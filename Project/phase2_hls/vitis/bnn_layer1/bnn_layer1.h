#ifndef BNN_LAYER1_H
#define BNN_LAYER1_H

#include "ap_int.h"

#define INPUT_SIZE 784 
#define LAYER1_NEURONS 256

typedef ap_uint<INPUT_SIZE> input_t; // bits of input binary data
typedef ap_uint<INPUT_SIZE> weight_row_t; // bits of trained weights
typedef ap_int<16> output_t; // bits of ouput

void bnn_layer1_xnor(
    input_t input,
    output_t output[LAYER1_NEURONS],
    weight_row_t weights[LAYER1_NEURONS]
);

#endif