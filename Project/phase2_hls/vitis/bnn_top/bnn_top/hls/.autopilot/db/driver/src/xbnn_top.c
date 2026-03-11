// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xbnn_top.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XBnn_top_CfgInitialize(XBnn_top *InstancePtr, XBnn_top_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XBnn_top_Start(XBnn_top *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_AP_CTRL) & 0x80;
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XBnn_top_IsDone(XBnn_top *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XBnn_top_IsIdle(XBnn_top *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XBnn_top_IsReady(XBnn_top *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XBnn_top_EnableAutoRestart(XBnn_top *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XBnn_top_DisableAutoRestart(XBnn_top *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_AP_CTRL, 0);
}

void XBnn_top_Set_input_r(XBnn_top *InstancePtr, XBnn_top_Input_r Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 0, Data.word_0);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 4, Data.word_1);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 8, Data.word_2);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 12, Data.word_3);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 16, Data.word_4);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 20, Data.word_5);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 24, Data.word_6);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 28, Data.word_7);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 32, Data.word_8);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 36, Data.word_9);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 40, Data.word_10);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 44, Data.word_11);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 48, Data.word_12);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 52, Data.word_13);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 56, Data.word_14);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 60, Data.word_15);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 64, Data.word_16);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 68, Data.word_17);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 72, Data.word_18);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 76, Data.word_19);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 80, Data.word_20);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 84, Data.word_21);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 88, Data.word_22);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 92, Data.word_23);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 96, Data.word_24);
}

XBnn_top_Input_r XBnn_top_Get_input_r(XBnn_top *InstancePtr) {
    XBnn_top_Input_r Data;

    Data.word_0 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 0);
    Data.word_1 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 4);
    Data.word_2 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 8);
    Data.word_3 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 12);
    Data.word_4 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 16);
    Data.word_5 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 20);
    Data.word_6 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 24);
    Data.word_7 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 28);
    Data.word_8 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 32);
    Data.word_9 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 36);
    Data.word_10 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 40);
    Data.word_11 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 44);
    Data.word_12 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 48);
    Data.word_13 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 52);
    Data.word_14 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 56);
    Data.word_15 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 60);
    Data.word_16 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 64);
    Data.word_17 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 68);
    Data.word_18 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 72);
    Data.word_19 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 76);
    Data.word_20 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 80);
    Data.word_21 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 84);
    Data.word_22 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 88);
    Data.word_23 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 92);
    Data.word_24 = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_INPUT_R_DATA + 96);
    return Data;
}

void XBnn_top_Set_l1_weights(XBnn_top *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_L1_WEIGHTS_DATA, (u32)(Data));
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_L1_WEIGHTS_DATA + 4, (u32)(Data >> 32));
}

u64 XBnn_top_Get_l1_weights(XBnn_top *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_L1_WEIGHTS_DATA);
    Data += (u64)XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_L1_WEIGHTS_DATA + 4) << 32;
    return Data;
}

void XBnn_top_Set_l2_weights(XBnn_top *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_L2_WEIGHTS_DATA, (u32)(Data));
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_L2_WEIGHTS_DATA + 4, (u32)(Data >> 32));
}

u64 XBnn_top_Get_l2_weights(XBnn_top *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_L2_WEIGHTS_DATA);
    Data += (u64)XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_L2_WEIGHTS_DATA + 4) << 32;
    return Data;
}

void XBnn_top_Set_l3_weights(XBnn_top *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_L3_WEIGHTS_DATA, (u32)(Data));
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_L3_WEIGHTS_DATA + 4, (u32)(Data >> 32));
}

u64 XBnn_top_Get_l3_weights(XBnn_top *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_L3_WEIGHTS_DATA);
    Data += (u64)XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_L3_WEIGHTS_DATA + 4) << 32;
    return Data;
}

void XBnn_top_Set_load_weights(XBnn_top *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_LOAD_WEIGHTS_DATA, Data);
}

u32 XBnn_top_Get_load_weights(XBnn_top *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_LOAD_WEIGHTS_DATA);
    return Data;
}

void XBnn_top_InterruptGlobalEnable(XBnn_top *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_GIE, 1);
}

void XBnn_top_InterruptGlobalDisable(XBnn_top *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_GIE, 0);
}

void XBnn_top_InterruptEnable(XBnn_top *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_IER);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_IER, Register | Mask);
}

void XBnn_top_InterruptDisable(XBnn_top *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_IER);
    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_IER, Register & (~Mask));
}

void XBnn_top_InterruptClear(XBnn_top *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_top_WriteReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_ISR, Mask);
}

u32 XBnn_top_InterruptGetEnabled(XBnn_top *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_IER);
}

u32 XBnn_top_InterruptGetStatus(XBnn_top *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBnn_top_ReadReg(InstancePtr->Control_BaseAddress, XBNN_TOP_CONTROL_ADDR_ISR);
}

