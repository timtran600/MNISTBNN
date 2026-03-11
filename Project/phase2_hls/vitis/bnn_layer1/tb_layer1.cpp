// phase2_hls/testbench/tb_layer1.cpp
#include <iostream>
#include "bnn_layer1.h"

int main() {
    std::cout << "Starting Layer 1 testbench..." << std::endl;
    
    // Simple test: All-ones input, all-ones weights
    input_t test_input;
    test_input = -1;  // All bits set to 1
    
    output_t test_output[LAYER1_NEURONS];
    weight_row_t test_weights[LAYER1_NEURONS];
    
    // Initialize all weights to all-ones
    for (int i = 0; i < LAYER1_NEURONS; i++) {
        test_weights[i] = -1;  // All bits 1
    }
    
    // Call DUT (Design Under Test)
    bnn_layer1_xnor(test_input, test_output, test_weights);
    
    // Verify: XNOR(1,1) = 1, popcount(all 1s) = 784
    // Expected output: 2*784 - 784 = +784
    std::cout << "Output[0] = " << test_output[0] << " (expected: 784)" << std::endl;
    
    if (test_output[0] == 784) {
        std::cout << "✓ Test PASSED" << std::endl;
        return 0;
    } else {
        std::cout << "✗ Test FAILED" << std::endl;
        return 1;
    }
}