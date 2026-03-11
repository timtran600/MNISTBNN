#ifndef BNN_LAYER1_H
#define BNN_LAYER1_H

#include "ap_int.h"
#include "hls_stream.h" 

#define INPUT_SIZE 784
#define LAYER1_NEURONS 256

typedef ap_uint<INPUT_SIZE> input_t;
typedef ap_uint<INPUT_SIZE> weight_row_t;
typedef ap_int<16> output_t;

// CHANGE function signature:
void bnn_layer1_xnor(
    hls::stream<input_t> &input_stream,
    output_t output[LAYER1_NEURONS],
    weight_row_t weights[LAYER1_NEURONS]
);

#endif