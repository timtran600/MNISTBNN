#include "bnn_top.h"

void bnn_top(
    hls::stream<out_stream_t> &output_stream,
    l1_input_t input,
    l1_weight_row_t l1_weights[L1_NEURONS],
    l2_weight_row_t l2_weights[L2_NEURONS],
    l3_weight_row_t l3_weights[L3_NEURONS],
    ap_uint<1> load_weights
)
{
    #pragma HLS INTERFACE s_axilite port=return
    #pragma HLS INTERFACE s_axilite port=input
    #pragma HLS INTERFACE s_axilite port=load_weights
    #pragma HLS INTERFACE axis port=output_stream
    #pragma HLS INTERFACE m_axi depth=256 port=l1_weights bundle=gmem0
    #pragma HLS INTERFACE m_axi depth=256 port=l2_weights bundle=gmem1
    #pragma HLS INTERFACE m_axi depth=10  port=l3_weights bundle=gmem2

    // On-chip BRAM weight storage
    static l1_weight_row_t local_l1_weights[L1_NEURONS];
    #pragma HLS ARRAY_PARTITION variable=local_l1_weights cyclic factor=L1_UNROLL dim=1

    static l2_weight_row_t local_l2_weights[L2_NEURONS];
    #pragma HLS ARRAY_PARTITION variable=local_l2_weights cyclic factor=L2_UNROLL dim=1Array partitioning was also used to allow for successful unrolling

    static l3_weight_row_t local_l3_weights[L3_NEURONS];
    #pragma HLS BIND_STORAGE variable=local_l3_weights type=ram_1p impl=lutram

    // Load weights
    if (load_weights)
    {
        L1_LOAD: for (int n = 0; n < L1_NEURONS; n++)
        {
            #pragma HLS PIPELINE II=1
            local_l1_weights[n] = l1_weights[n];
        }
        L2_LOAD: for (int n = 0; n < L2_NEURONS; n++)
        {
            #pragma HLS PIPELINE II=1
            local_l2_weights[n] = l2_weights[n];
        }
        L3_LOAD: for (int n = 0; n < L3_NEURONS; n++)
        {
            #pragma HLS PIPELINE II=1
            local_l3_weights[n] = l3_weights[n];
        }
    }

    // Layer Inference
    if (!load_weights)
    {

        // LAYER 1: 784 -> 256
        score_t l1_output[L1_NEURONS];

        L1_NEURON: for (int n = 0; n < L1_NEURONS; n += L1_UNROLL)
        {
            #pragma HLS PIPELINE II=1
            for (int u = 0; u < L1_UNROLL; u++)
            {
                #pragma HLS UNROLL
                ap_uint<L1_INPUT_SIZE> xnor_result = ~(input ^ local_l1_weights[n + u]);
                int count = 0;
                for (int i = 0; i < L1_INPUT_SIZE; i++)
                {
                    #pragma HLS UNROLL
                    count += xnor_result[i];
                }
                l1_output[n + u] = 2 * count - L1_INPUT_SIZE;
            }
        }

        // BINARIZE L1 -> L2
        ap_uint<L2_INPUT_SIZE> l2_input = 0;
        BINARIZE_L1: for (int i = 0; i < L1_NEURONS; i++)
        {
            #pragma HLS UNROLL
            l2_input[i] = (l1_output[i] < 0) ? 1 : 0;
        }

        // LAYER 2: 256 -> 256
        score_t l2_output[L2_NEURONS];

        L2_NEURON: for (int n = 0; n < L2_NEURONS; n += L2_UNROLL)
        {
            #pragma HLS PIPELINE II=1
            for (int u = 0; u < L2_UNROLL; u++)
            {
                #pragma HLS UNROLL
                ap_uint<L2_INPUT_SIZE> xnor_result = ~(l2_input ^ local_l2_weights[n + u]);
                int count = 0;
                for (int i = 0; i < L2_INPUT_SIZE; i++)
                {
                    #pragma HLS UNROLL
                    count += xnor_result[i];
                }
                l2_output[n + u] = 2 * count - L2_INPUT_SIZE;
            }
        }

        // BINARIZE L2 -> L3
        ap_uint<L3_INPUT_SIZE> l3_input = 0;
        BINARIZE_L2: for (int i = 0; i < L2_NEURONS; i++)
        {
            #pragma HLS UNROLL
            l3_input[i] = (l2_output[i] < 0) ? 1 : 0;
        }

        // LAYER 3: 256 -> 10
        L3_NEURON: for (int n = 0; n < L3_NEURONS; n += L3_UNROLL)
        {
            #pragma HLS PIPELINE II=1
            for (int u = 0; u < L3_UNROLL; u++)
            {
                #pragma HLS UNROLL
                int idx = n + u;
                ap_uint<L3_INPUT_SIZE> xnor_result = ~(l3_input ^ local_l3_weights[idx]);
                int count = 0;
                for (int i = 0; i < L3_INPUT_SIZE; i++)
                {
                    #pragma HLS UNROLL
                    count += xnor_result[i];
                }

                out_stream_t out_word;
                out_word.data = 2 * count - L3_INPUT_SIZE;
                out_word.keep = -1;
                out_word.strb = -1;
                out_word.last = (idx == L3_NEURONS - 1) ? 1 : 0;
                output_stream.write(out_word);
            }
        }
    }
}