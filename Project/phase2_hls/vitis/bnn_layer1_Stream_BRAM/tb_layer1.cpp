#include <iostream>
#include "bnn_layer1.h"
#include "c:/GitRepos/EECE4632/Project/phase1_software/fpga_weights/layer1_weights.h"

using namespace std;

int main() {
    cout << "BNN LAYER 1 - AXI-STREAM TEST" << endl;

    // Pack weights into ap_uint<784> format
    weight_row_t packed_weights[LAYER1_NEURONS];
    for (int n = 0; n < LAYER1_NEURONS; n++) {
        packed_weights[n] = 0;
        for (int i = 0; i < INPUT_SIZE; i++) {
            if (LAYER1_WEIGHTS[n][i] < 0) {
                packed_weights[n][i] = 1;
            }
        }
    }

    // Load weights into BRAM
    hls::stream<out_stream_t> dummy_stream;
    input_t dummy_input = 0;

    cout << "\nLoading weights into BRAM..." << endl;
    bnn_layer1_xnor(dummy_stream, dummy_input, packed_weights, 1);
    cout << "Weights loaded." << endl;

    // STEP 2: Run inference
    hls::stream<out_stream_t> output_stream;
    input_t test_input = 0;  // All bits 0 = all bipolar +1

    cout << "\nRunning inference..." << endl;
    bnn_layer1_xnor(output_stream, test_input, packed_weights, 0);

    // Read stream and validate
    int pass_count = 0;
    int fail_count = 0;
    int last_seen = 0;

    for (int n = 0; n < LAYER1_NEURONS; n++) {
        out_stream_t out_word = output_stream.read();
        ap_int<16> result = out_word.data;

        // Compute expected
        int exp_count = 0;
        for (int i = 0; i < INPUT_SIZE; i++) {
            if (LAYER1_WEIGHTS[n][i] > 0) {
                exp_count++;
            }
        }
        int exp_val = 2 * exp_count - INPUT_SIZE;

        if (result == exp_val) {
            pass_count++;
        } else {
            fail_count++;
            if (fail_count <= 5) {
                cout << "FAIL neuron " << n
                     << ": got " << result
                     << ", expected " << exp_val << endl;
            }
        }

        // Check TLAST
        if (out_word.last) {
            last_seen = n;
        }
    }

    // Verify TLAST position
    cout << "\n=== RESULTS ===" << endl;
    cout << "Passed: " << pass_count << " / " << LAYER1_NEURONS << endl;
    cout << "Failed: " << fail_count << " / " << LAYER1_NEURONS << endl;
    cout << "TLAST seen at neuron: " << last_seen
         << " (expected: " << LAYER1_NEURONS - 1 << ")" << endl;

    if (fail_count == 0 && last_seen == LAYER1_NEURONS - 1) {
        cout << "\nTEST PASSED" << endl;
        return 0;
    } else {
        cout << "\nTEST FAILED" << endl;
        return 1;
    }
}