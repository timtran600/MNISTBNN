// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xbnn_layer3_xnor.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XBnn_layer3_xnor_CfgInitialize(XBnn_layer3_xnor *InstancePtr, XBnn_layer3_xnor_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XBnn_layer3_xnor_Start(XBnn_layer3_xnor *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_AP_CTRL) & 0x80;
    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XBnn_layer3_xnor_IsDone(XBnn_layer3_xnor *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XBnn_layer3_xnor_IsIdle(XBnn_layer3_xnor *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XBnn_layer3_xnor_IsReady(XBnn_layer3_xnor *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XBnn_layer3_xnor_EnableAutoRestart(XBnn_layer3_xnor *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XBnn_layer3_xnor_DisableAutoRestart(XBnn_layer3_xnor *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_AP_CTRL, 0);
}

void XBnn_layer3_xnor_Set_input_r(XBnn_layer3_xnor *InstancePtr, XBnn_layer3_xnor_Input_r Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_INPUT_R_DATA + 0, Data.word_0);
    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_INPUT_R_DATA + 4, Data.word_1);
    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_INPUT_R_DATA + 8, Data.word_2);
    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_INPUT_R_DATA + 12, Data.word_3);
    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_INPUT_R_DATA + 16, Data.word_4);
    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_INPUT_R_DATA + 20, Data.word_5);
    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_INPUT_R_DATA + 24, Data.word_6);
    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_INPUT_R_DATA + 28, Data.word_7);
}

XBnn_layer3_xnor_Input_r XBnn_layer3_xnor_Get_input_r(XBnn_layer3_xnor *InstancePtr) {
    XBnn_layer3_xnor_Input_r Data;

    Data.word_0 = XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_INPUT_R_DATA + 0);
    Data.word_1 = XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_INPUT_R_DATA + 4);
    Data.word_2 = XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_INPUT_R_DATA + 8);
    Data.word_3 = XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_INPUT_R_DATA + 12);
    Data.word_4 = XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_INPUT_R_DATA + 16);
    Data.word_5 = XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_INPUT_R_DATA + 20);
    Data.word_6 = XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_INPUT_R_DATA + 24);
    Data.word_7 = XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_INPUT_R_DATA + 28);
    return Data;
}

void XBnn_layer3_xnor_Set_output_r(XBnn_layer3_xnor *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_OUTPUT_R_DATA, (u32)(Data));
    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_OUTPUT_R_DATA + 4, (u32)(Data >> 32));
}

u64 XBnn_layer3_xnor_Get_output_r(XBnn_layer3_xnor *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_OUTPUT_R_DATA);
    Data += (u64)XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_OUTPUT_R_DATA + 4) << 32;
    return Data;
}

void XBnn_layer3_xnor_Set_weights(XBnn_layer3_xnor *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_WEIGHTS_DATA, (u32)(Data));
    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_WEIGHTS_DATA + 4, (u32)(Data >> 32));
}

u64 XBnn_layer3_xnor_Get_weights(XBnn_layer3_xnor *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_WEIGHTS_DATA);
    Data += (u64)XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_WEIGHTS_DATA + 4) << 32;
    return Data;
}

void XBnn_layer3_xnor_Set_load_weights(XBnn_layer3_xnor *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_LOAD_WEIGHTS_DATA, Data);
}

u32 XBnn_layer3_xnor_Get_load_weights(XBnn_layer3_xnor *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_LOAD_WEIGHTS_DATA);
    return Data;
}

void XBnn_layer3_xnor_InterruptGlobalEnable(XBnn_layer3_xnor *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_GIE, 1);
}

void XBnn_layer3_xnor_InterruptGlobalDisable(XBnn_layer3_xnor *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_GIE, 0);
}

void XBnn_layer3_xnor_InterruptEnable(XBnn_layer3_xnor *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_IER);
    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_IER, Register | Mask);
}

void XBnn_layer3_xnor_InterruptDisable(XBnn_layer3_xnor *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_IER);
    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_IER, Register & (~Mask));
}

void XBnn_layer3_xnor_InterruptClear(XBnn_layer3_xnor *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBnn_layer3_xnor_WriteReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_ISR, Mask);
}

u32 XBnn_layer3_xnor_InterruptGetEnabled(XBnn_layer3_xnor *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_IER);
}

u32 XBnn_layer3_xnor_InterruptGetStatus(XBnn_layer3_xnor *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBnn_layer3_xnor_ReadReg(InstancePtr->Control_BaseAddress, XBNN_LAYER3_XNOR_CONTROL_ADDR_ISR);
}

