#ifndef BNN_TOP_H
#define BNN_TOP_H

#include "ap_int.h"
#include "ap_axi_sdata.h"
#include "hls_stream.h"

// Layer dimensions
#define L1_INPUT_SIZE  784
#define L1_NEURONS     256
#define L2_INPUT_SIZE  256
#define L2_NEURONS     256
#define L3_INPUT_SIZE  256
#define L3_NEURONS     10

// Number of 32-bit words to transfer the 784-bit input
#define INPUT_STREAM_WORDS 25  // ceil(784 / 32)

// Unroll factors
#define L1_UNROLL 4
#define L2_UNROLL 4
#define L3_UNROLL 1

// Row weight types (packed binary vectors)
typedef ap_uint<L1_INPUT_SIZE> l1_input_t;
typedef ap_uint<L1_INPUT_SIZE> l1_weight_row_t;
typedef ap_uint<L2_INPUT_SIZE> l2_weight_row_t;
typedef ap_uint<L3_INPUT_SIZE> l3_weight_row_t;
typedef ap_int<16> score_t;

// AXI-Stream types
typedef ap_axiu<32, 0, 0, 0> in_stream_t;   // 32-bit input stream
typedef ap_axiu<16, 0, 0, 0> out_stream_t;   // 16-bit output stream

// Top-level function
void bnn_top(
    hls::stream<in_stream_t>  &input_stream,
    hls::stream<out_stream_t> &output_stream,
    l1_weight_row_t l1_weights[L1_NEURONS],
    l2_weight_row_t l2_weights[L2_NEURONS],
    l3_weight_row_t l3_weights[L3_NEURONS],
    ap_uint<1> load_weights
);


#endif