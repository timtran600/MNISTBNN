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
// 0x30 : Data signal of input_r
//        bit 31~0 - input_r[287:256] (Read/Write)
// 0x34 : Data signal of input_r
//        bit 31~0 - input_r[319:288] (Read/Write)
// 0x38 : Data signal of input_r
//        bit 31~0 - input_r[351:320] (Read/Write)
// 0x3c : Data signal of input_r
//        bit 31~0 - input_r[383:352] (Read/Write)
// 0x40 : Data signal of input_r
//        bit 31~0 - input_r[415:384] (Read/Write)
// 0x44 : Data signal of input_r
//        bit 31~0 - input_r[447:416] (Read/Write)
// 0x48 : Data signal of input_r
//        bit 31~0 - input_r[479:448] (Read/Write)
// 0x4c : Data signal of input_r
//        bit 31~0 - input_r[511:480] (Read/Write)
// 0x50 : Data signal of input_r
//        bit 31~0 - input_r[543:512] (Read/Write)
// 0x54 : Data signal of input_r
//        bit 31~0 - input_r[575:544] (Read/Write)
// 0x58 : Data signal of input_r
//        bit 31~0 - input_r[607:576] (Read/Write)
// 0x5c : Data signal of input_r
//        bit 31~0 - input_r[639:608] (Read/Write)
// 0x60 : Data signal of input_r
//        bit 31~0 - input_r[671:640] (Read/Write)
// 0x64 : Data signal of input_r
//        bit 31~0 - input_r[703:672] (Read/Write)
// 0x68 : Data signal of input_r
//        bit 31~0 - input_r[735:704] (Read/Write)
// 0x6c : Data signal of input_r
//        bit 31~0 - input_r[767:736] (Read/Write)
// 0x70 : Data signal of input_r
//        bit 15~0 - input_r[783:768] (Read/Write)
//        others   - reserved
// 0x74 : reserved
// 0x78 : Data signal of l1_weights
//        bit 31~0 - l1_weights[31:0] (Read/Write)
// 0x7c : Data signal of l1_weights
//        bit 31~0 - l1_weights[63:32] (Read/Write)
// 0x80 : reserved
// 0x84 : Data signal of l2_weights
//        bit 31~0 - l2_weights[31:0] (Read/Write)
// 0x88 : Data signal of l2_weights
//        bit 31~0 - l2_weights[63:32] (Read/Write)
// 0x8c : reserved
// 0x90 : Data signal of l3_weights
//        bit 31~0 - l3_weights[31:0] (Read/Write)
// 0x94 : Data signal of l3_weights
//        bit 31~0 - l3_weights[63:32] (Read/Write)
// 0x98 : reserved
// 0x9c : Data signal of load_weights
//        bit 0  - load_weights[0] (Read/Write)
//        others - reserved
// 0xa0 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XBNN_TOP_CONTROL_ADDR_AP_CTRL           0x00
#define XBNN_TOP_CONTROL_ADDR_GIE               0x04
#define XBNN_TOP_CONTROL_ADDR_IER               0x08
#define XBNN_TOP_CONTROL_ADDR_ISR               0x0c
#define XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA      0x10
#define XBNN_TOP_CONTROL_BITS_INPUT_R_DATA      784
#define XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA_     0x38
#define XBNN_TOP_CONTROL_BITS_INPUT_R_DATA      784
#define XBNN_TOP_CONTROL_ADDR_L1_WEIGHTS_DATA   0x78
#define XBNN_TOP_CONTROL_BITS_L1_WEIGHTS_DATA   64
#define XBNN_TOP_CONTROL_ADDR_L2_WEIGHTS_DATA   0x84
#define XBNN_TOP_CONTROL_BITS_L2_WEIGHTS_DATA   64
#define XBNN_TOP_CONTROL_ADDR_L3_WEIGHTS_DATA   0x90
#define XBNN_TOP_CONTROL_BITS_L3_WEIGHTS_DATA   64
#define XBNN_TOP_CONTROL_ADDR_LOAD_WEIGHTS_DATA 0x9c
#define XBNN_TOP_CONTROL_BITS_LOAD_WEIGHTS_DATA 1

