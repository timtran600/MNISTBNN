#include <iostream>
#include "bnn_layer1.h"

int main() {
    std::cout << "Testing Layer 1 with streaming interface..." << std::endl;
    
    // Create stream for input
    hls::stream<input_t> input_stream("input_stream");
    
    // Test data
    input_t test_input = -1;  // All ones
    input_stream.write(test_input);  // ← Write to stream instead of passing directly
    
    output_t test_output[LAYER1_NEURONS];
    weight_row_t test_weights[LAYER1_NEURONS];
    
    // Initialize weights
    for (int i = 0; i < LAYER1_NEURONS; i++) {
        test_weights[i] = -1;
    }
    
    // Call function (reads from stream)
    bnn_layer1_xnor(input_stream, test_output, test_weights);
    
    // Verify
    std::cout << "Output[0] = " << test_output[0] << " (expected: 784)" << std::endl;
    
    if (test_output[0] == 784) {
        std::cout << "✓ Test PASSED" << std::endl;
        return 0;
    } else {
        std::cout << "✗ Test FAILED" << std::endl;
        return 1;
    }
}