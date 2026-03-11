#include "bnn_layer3.h"

void bnn_layer3_xnor(
    input_t input,
    output_t output[LAYER3_NEURONS],
    weight_row_t weights[LAYER3_NEURONS],
    ap_uint<1> load_weights
)
{
    #pragma HLS INTERFACE s_axilite port=return
    #pragma HLS INTERFACE s_axilite port=load_weights
    #pragma HLS INTERFACE s_axilite port=input
    #pragma HLS INTERFACE m_axi depth=256 port=output  bundle=gmem0
    #pragma HLS INTERFACE m_axi depth=256 port=weights bundle=gmem1

    // On-chip BRAM storage for weights - persists across kernel calls
    static weight_row_t local_weights[LAYER3_NEURONS];
    #pragma HLS BIND_STORAGE variable=local_weights type=ram_2p impl=bram

    // ========== PHASE 1: Load weights from DDR into BRAM ==========
    if (load_weights) {
        LOAD_LOOP: for (int n = 0; n < LAYER3_NEURONS; n++) {
            #pragma HLS PIPELINE II=1
            local_weights[n] = weights[n];
        }
    }

    // ========== PHASE 2: Inference using BRAM weights ==========
    if (!load_weights) {
        NEURON_LOOP: for (int n = 0; n < LAYER3_NEURONS; n++) {
            #pragma HLS PIPELINE II=1

            // XNOR: matching bits become 1
            ap_uint<INPUT_SIZE> xnor_result = ~(input ^ local_weights[n]);

            // Popcount: count matching bits
            int count = 0;
            POPCOUNT_LOOP: for (int i = 0; i < INPUT_SIZE; i++) {
                count += xnor_result[i];
            }

            // Convert to signed bipolar output: 2*popcount - N
            output[n] = 2 * count - INPUT_SIZE;
        }
    }
}