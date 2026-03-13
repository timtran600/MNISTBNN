#include <iostream>
#include "bnn_top.h"
#include "c:/GitRepos/EECE4632/Project/phase1_software/fpga_weights/layer1_weights.h"
#include "c:/GitRepos/EECE4632/Project/phase1_software/fpga_weights/layer2_weights.h"
#include "c:/GitRepos/EECE4632/Project/phase1_software/fpga_weights/layer3_weights.h"

using namespace std;

int main() {
    cout << "BNN TOP-LEVEL (3-LAYER) TEST" << endl;

    // Pack all weights

    // Layer 1: 256 x 784
    l1_weight_row_t packed_l1[L1_NEURONS];
    for (int n = 0; n < L1_NEURONS; n++) {
        packed_l1[n] = 0;
        for (int i = 0; i < L1_INPUT_SIZE; i++) {
            if (LAYER1_WEIGHTS[n][i] < 0) packed_l1[n][i] = 1;
        }
    }

    // Layer 2: 256 x 256
    l2_weight_row_t packed_l2[L2_NEURONS];
    for (int n = 0; n < L2_NEURONS; n++) {
        packed_l2[n] = 0;
        for (int i = 0; i < L2_INPUT_SIZE; i++) {
            if (LAYER2_WEIGHTS[n][i] < 0) packed_l2[n][i] = 1;
        }
    }

    // Layer 3: 10 x 256
    l3_weight_row_t packed_l3[L3_NEURONS];
    for (int n = 0; n < L3_NEURONS; n++) {
        packed_l3[n] = 0;
        for (int i = 0; i < L3_INPUT_SIZE; i++) {
            if (LAYER3_WEIGHTS[n][i] < 0) packed_l3[n][i] = 1;
        }
    }

    // Load weights
    hls::stream<out_stream_t> dummy_stream;
    l1_input_t dummy_input = 0;
    cout << "\nLoading weights into BRAM..." << endl;
    bnn_top(dummy_stream, dummy_input, packed_l1, packed_l2, packed_l3, 1);
    cout << "All weights loaded." << endl;

    // Run inference 
    hls::stream<out_stream_t> output_stream;
    l1_input_t test_input = 0;  // All bits 0 = all bipolar +1

    cout << "\nRunning 3-layer inference..." << endl;
    bnn_top(output_stream, test_input, packed_l1, packed_l2, packed_l3, 0);

    // Compute expected (golden reference)

    // Layer 1
    int l1_out[L1_NEURONS];
    for (int n = 0; n < L1_NEURONS; n++) {
        int count = 0;
        for (int i = 0; i < L1_INPUT_SIZE; i++) {
            // input bit 0 = bipolar +1, weight +1 = bit 0 -> XNOR = 1
            if (LAYER1_WEIGHTS[n][i] > 0) count++;
        }
        l1_out[n] = 2 * count - L1_INPUT_SIZE;
    }

    // Binarize L1 output -> L2 input (pack into bits)
    // bit = 1 if negative, 0 if positive (matching kernel convention)
    ap_uint<L2_INPUT_SIZE> l2_in_packed = 0;
    for (int i = 0; i < L1_NEURONS; i++) {
        if (l1_out[i] < 0) l2_in_packed[i] = 1;
    }

    // Layer 2
    int l2_out[L2_NEURONS];
    for (int n = 0; n < L2_NEURONS; n++) {
        // Pack layer 2 weight row
        ap_uint<L2_INPUT_SIZE> w2 = 0;
        for (int i = 0; i < L2_INPUT_SIZE; i++) {
            if (LAYER2_WEIGHTS[n][i] < 0) w2[i] = 1;
        }
        ap_uint<L2_INPUT_SIZE> xnor2 = ~(l2_in_packed ^ w2);
        int count = 0;
        for (int i = 0; i < L2_INPUT_SIZE; i++) {
            count += xnor2[i];
        }
        l2_out[n] = 2 * count - L2_INPUT_SIZE;
    }

    // Binarize L2 output -> L3 input
    ap_uint<L3_INPUT_SIZE> l3_in_packed = 0;
    for (int i = 0; i < L2_NEURONS; i++) {
        if (l2_out[i] < 0) l3_in_packed[i] = 1;
    }

    // Layer 3
    int expected_scores[L3_NEURONS];
    for (int n = 0; n < L3_NEURONS; n++) {
        ap_uint<L3_INPUT_SIZE> w3 = 0;
        for (int i = 0; i < L3_INPUT_SIZE; i++) {
            if (LAYER3_WEIGHTS[n][i] < 0) w3[i] = 1;
        }
        ap_uint<L3_INPUT_SIZE> xnor3 = ~(l3_in_packed ^ w3);
        int count = 0;
        for (int i = 0; i < L3_INPUT_SIZE; i++) {
            count += xnor3[i];
        }
        expected_scores[n] = 2 * count - L3_INPUT_SIZE;
    }

    // Read stream and validate
    int pass_count = 0;
    int fail_count = 0;
    int last_seen = -1;
    int predicted_class = 0;
    int max_score = -9999;

    cout << "\n=== Output Scores ===" << endl;
    for (int n = 0; n < L3_NEURONS; n++) {
        out_stream_t out_word = output_stream.read();
        ap_int<16> result = out_word.data;

        cout << "Class " << n << ": kernel=" << result
             << "  expected=" << expected_scores[n];

        if (result == expected_scores[n]) {
            pass_count++;
            cout << "  OK" << endl;
        } else {
            fail_count++;
            cout << "  FAIL" << endl;
        }

        if (result > max_score) {
            max_score = result;
            predicted_class = n;
        }

        if (out_word.last) last_seen = n;
    }

    // ===== STEP 5: Summary =====
    cout << "\n=== RESULTS ===" << endl;
    cout << "Passed: " << pass_count << " / " << L3_NEURONS << endl;
    cout << "Failed: " << fail_count << " / " << L3_NEURONS << endl;
    cout << "TLAST at index: " << last_seen
         << " (expected: " << L3_NEURONS - 1 << ")" << endl;
    cout << "Predicted class: " << predicted_class
         << " (score: " << max_score << ")" << endl;

    if (fail_count == 0 && last_seen == L3_NEURONS - 1) {
        cout << "\nTEST PASSED" << endl;
        return 0;
    } else {
        cout << "\nTEST FAILED" << endl;
        return 1;
    }
}