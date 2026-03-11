#ifndef BNN_LAYER3_H
#define BNN_LAYER3_H

#include "ap_int.h"

#define INPUT_SIZE 256
#define LAYER3_NEURONS 10

typedef ap_uint<INPUT_SIZE> input_t;      // 256-bit packed binary input
typedef ap_uint<INPUT_SIZE> weight_row_t; // 256-bit packed binary weight row
typedef ap_int<16> output_t;              // Signed output (popcount result)

void bnn_layer3_xnor(
    input_t input,
    output_t output[LAYER3_NEURONS],
    weight_row_t weights[LAYER3_NEURONS],
    ap_uint<1> load_weights  // 1 = load weights into BRAM, 0 = run inference
);

#endif