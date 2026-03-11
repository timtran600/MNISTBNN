
#ifndef BNN_LAYER1_H
#define BNN_LAYER1_H

#include "ap_int.h"

#define INPUT_SIZE 784
#define LAYER1_NEURONS 256

typedef ap_uint<INPUT_SIZE> input_t;      // 784-bit packed binary input
typedef ap_uint<INPUT_SIZE> weight_row_t; // 784-bit packed binary weight row
typedef ap_int<16> output_t;              // Signed output (popcount result)

void bnn_layer1_xnor(
    input_t input,
    output_t output[LAYER1_NEURONS],
    weight_row_t weights[LAYER1_NEURONS],
    ap_uint<1> load_weights  // 1 = load weights into BRAM, 0 = run inference
);

#endif