// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
// control
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read/COR)
//        bit 7  - auto_restart (Read/Write)
//        bit 9  - interrupt (Read)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0 - enable ap_done interrupt (Read/Write)
//        bit 1 - enable ap_ready interrupt (Read/Write)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0 - ap_done (Read/TOW)
//        bit 1 - ap_ready (Read/TOW)
//        others - reserved
// 0x10 : Data signal of input_r
//        bit 31~0 - input_r[31:0] (Read/Write)
// 0x14 : Data signal of input_r
//        bit 31~0 - input_r[63:32] (Read/Write)
// 0x18 : Data signal of input_r
//        bit 31~0 - input_r[95:64] (Read/Write)
// 0x1c : Data signal of input_r
//        bit 31~0 - input_r[127:96] (Read/Write)
// 0x20 : Data signal of input_r
//        bit 31~0 - input_r[159:128] (Read/Write)
// 0x24 : Data signal of input_r
//        bit 31~0 - input_r[191:160] (Read/Write)
// 0x28 : Data signal of input_r
//        bit 31~0 - input_r[223:192] (Read/Write)
// 0x2c : Data signal of input_r
//        bit 31~0 - input_r[255:224] (Read/Write)
// 0x30 : reserved
// 0x34 : Data signal of weights
//        bit 31~0 - weights[31:0] (Read/Write)
// 0x38 : Data signal of weights
//        bit 31~0 - weights[63:32] (Read/Write)
// 0x3c : reserved
// 0x40 : Data signal of load_weights
//        bit 0  - load_weights[0] (Read/Write)
//        others - reserved
// 0x44 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XBNN_LAYER2_XNOR_CONTROL_ADDR_AP_CTRL           0x00
#define XBNN_LAYER2_XNOR_CONTROL_ADDR_GIE               0x04
#define XBNN_LAYER2_XNOR_CONTROL_ADDR_IER               0x08
#define XBNN_LAYER2_XNOR_CONTROL_ADDR_ISR               0x0c
#define XBNN_LAYER2_XNOR_CONTROL_ADDR_INPUT_R_DATA      0x10
#define XBNN_LAYER2_XNOR_CONTROL_BITS_INPUT_R_DATA      256
#define XBNN_LAYER2_XNOR_CONTROL_ADDR_WEIGHTS_DATA      0x34
#define XBNN_LAYER2_XNOR_CONTROL_BITS_WEIGHTS_DATA      64
#define XBNN_LAYER2_XNOR_CONTROL_ADDR_LOAD_WEIGHTS_DATA 0x40
#define XBNN_LAYER2_XNOR_CONTROL_BITS_LOAD_WEIGHTS_DATA 1

