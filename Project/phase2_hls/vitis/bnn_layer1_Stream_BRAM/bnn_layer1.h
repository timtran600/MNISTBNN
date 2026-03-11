#ifndef BNN_LAYER1_H
#define BNN_LAYER1_H

#include "ap_int.h"
#include "ap_axi_sdata.h"
#include "hls_stream.h"

#define INPUT_SIZE 784
#define LAYER1_NEURONS 256

// Packed binary types
typedef ap_uint<INPUT_SIZE> input_t;      // 784-bit packed binary input
typedef ap_uint<INPUT_SIZE> weight_row_t; // 784-bit packed binary weight row
typedef ap_int<16> output_t;              // Signed output (popcount result)

// AXI-Stream side-channel struct: data + TLAST
typedef ap_axiu<16, 0, 0, 0> out_stream_t;  // 16-bit output stream word

void bnn_layer1_xnor(
    hls::stream<out_stream_t> &output_stream,
    input_t input,
    weight_row_t weights[LAYER1_NEURONS],
    ap_uint<1> load_weights
);

#endif