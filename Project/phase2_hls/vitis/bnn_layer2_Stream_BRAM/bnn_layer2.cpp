#include "bnn_layer2.h"

void bnn_layer2_xnor(
    hls::stream<out_stream_t> &output_stream,
    input_t input,
    weight_row_t weights[LAYER2_NEURONS],
    ap_uint<1> load_weights
)
{
    #pragma HLS INTERFACE s_axilite port=return
    #pragma HLS INTERFACE s_axilite port=input
    #pragma HLS INTERFACE s_axilite port=load_weights
    #pragma HLS INTERFACE axis port=output_stream
    #pragma HLS INTERFACE m_axi depth=256 port=weights bundle=gmem0

    // On-chip BRAM storage — persists across kernel calls
    static weight_row_t local_weights[LAYER2_NEURONS];
    #pragma HLS BIND_STORAGE variable=local_weights type=ram_2p impl=bram

    // ========== PHASE 1: Load weights from DDR into BRAM ==========
    if (load_weights) {
        LOAD_LOOP: for (int n = 0; n < LAYER2_NEURONS; n++) {
            #pragma HLS PIPELINE II=1
            local_weights[n] = weights[n];
        }
    }

    // ========== PHASE 2: Inference — stream out results ==========
    if (!load_weights) {
        NEURON_LOOP: for (int n = 0; n < LAYER2_NEURONS; n++) {
            #pragma HLS PIPELINE II=1

            // XNOR: matching bits become 1
            ap_uint<INPUT_SIZE> xnor_result = ~(input ^ local_weights[n]);

            // Popcount
            int count = 0;
            POPCOUNT_LOOP: for (int i = 0; i < INPUT_SIZE; i++) {
                count += xnor_result[i];
            }

            // Build AXI-Stream word with TLAST on final neuron
            out_stream_t out_word;
            out_word.data = 2 * count - INPUT_SIZE;
            out_word.keep = -1;  // all bytes valid
            out_word.strb = -1;
            out_word.last = (n == LAYER2_NEURONS - 1) ? 1 : 0;
            output_stream.write(out_word);
        }
    }
}