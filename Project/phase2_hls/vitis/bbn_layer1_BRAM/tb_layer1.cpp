#include <iostream>
#include "bnn_layer1.h"
#include "c:/GitRepos/EECE4632/Project/phase1_software/fpga_weights/layer1_weights.h"

using namespace std;

int main() {
    cout << "=== BNN LAYER 1 - BRAM WEIGHT LOADING TEST ===" << endl;

    // ===== Pack weights into ap_uint<784> format =====
    weight_row_t packed_weights[LAYER1_NEURONS];
    for (int n = 0; n < LAYER1_NEURONS; n++) {
        packed_weights[n] = 0;
        for (int i = 0; i < INPUT_SIZE; i++) {
            if (LAYER1_WEIGHTS[n][i] < 0) {
                packed_weights[n][i] = 1;
            }
        }
    }

    // ===== STEP 1: Load weights into BRAM =====
    output_t dummy_output[LAYER1_NEURONS];
    input_t dummy_input = 0;

    cout << "\nLoading weights into BRAM..." << endl;
    bnn_layer1_xnor(dummy_input, dummy_output, packed_weights, 1);
    cout << "Weights loaded." << endl;

    // ===== STEP 2: Run inference (all-zero input = all +1 bipolar) =====
    output_t test_output[LAYER1_NEURONS];
    input_t test_input = 0;

    cout << "\nRunning inference..." << endl;
    bnn_layer1_xnor(test_input, test_output, packed_weights, 0);

    // ===== STEP 3: Compute expected result for neuron 0 =====
    int expected_count = 0;
    for (int i = 0; i < INPUT_SIZE; i++) {
        // input bit = 0 means bipolar +1, weight +1 maps to bit 0
        // XNOR(0, 0) = 1 for +1 weights, XNOR(0, 1) = 0 for -1 weights
        if (LAYER1_WEIGHTS[0][i] > 0) {
            expected_count++;  // XNOR match
        }
    }
    int expected_val = 2 * expected_count - INPUT_SIZE;

    cout << "\nNeuron 0 output:   " << test_output[0] << endl;
    cout << "Expected:          " << expected_val << endl;

    // ===== STEP 4: Validate all neurons =====
    int pass_count = 0;
    int fail_count = 0;

    for (int n = 0; n < LAYER1_NEURONS; n++) {
        int exp_count = 0;
        for (int i = 0; i < INPUT_SIZE; i++) {
            if (LAYER1_WEIGHTS[n][i] > 0) {
                exp_count++;
            }
        }
        int exp_val = 2 * exp_count - INPUT_SIZE;

        if (test_output[n] == exp_val) {
            pass_count++;
        } else {
            fail_count++;
            if (fail_count <= 5) {
                cout << "FAIL neuron " << n
                     << ": got " << test_output[n]
                     << ", expected " << exp_val << endl;
            }
        }
    }

    cout << "\n=== RESULTS ===" << endl;
    cout << "Passed: " << pass_count << " / " << LAYER1_NEURONS << endl;
    cout << "Failed: " << fail_count << " / " << LAYER1_NEURONS << endl;

    if (fail_count == 0) {
        cout << "\nTEST PASSED" << endl;
        return 0;
    } else {
        cout << "\nTEST FAILED" << endl;
        return 1;
    }
}