#include "bnn_layer1.h"

void bnn_layer1_xnor(
    hls::stream<input_t> &input_stream,
    output_t output[LAYER1_NEURONS],
    weight_row_t weights[LAYER1_NEURONS]
) 
{
    #pragma HLS INTERFACE axis port=input_stream
    #pragma HLS INTERFACE s_axilite port=return
    #pragma HLS INTERFACE m_axi depth=256 port=output bundle=gmem0
    #pragma HLS INTERFACE m_axi depth=256 port=weights bundle=gmem1

    input_t input = input_stream.read();

    // For each neuron in layer 1 (256)
    
    NEURON_LOOP: for (int n = 0; n < LAYER1_NEURONS; n++)
    {

        #pragma HLS PIPELINE II=1
        
        // Compute XNOR operation with corresponding input and weight
        ap_uint<INPUT_SIZE> xnor_result = ~(input ^ weights[n]);
        
        // Popcount: count number of matching bits
        int count = 0;
        POPCOUNT_LOOP: for (int i = 0; i < INPUT_SIZE; i++)
        {
            
            count += xnor_result[i];
        }
        
        // Convert to signed bipolar
        output[n] = 2 * count - INPUT_SIZE;
    }
}