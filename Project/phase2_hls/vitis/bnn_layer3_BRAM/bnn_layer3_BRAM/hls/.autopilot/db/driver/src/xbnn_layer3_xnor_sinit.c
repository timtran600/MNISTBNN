// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#ifdef SDT
#include "xparameters.h"
#endif
#include "xbnn_layer3_xnor.h"

extern XBnn_layer3_xnor_Config XBnn_layer3_xnor_ConfigTable[];

#ifdef SDT
XBnn_layer3_xnor_Config *XBnn_layer3_xnor_LookupConfig(UINTPTR BaseAddress) {
	XBnn_layer3_xnor_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XBnn_layer3_xnor_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XBnn_layer3_xnor_ConfigTable[Index].Control_BaseAddress == BaseAddress) {
			ConfigPtr = &XBnn_layer3_xnor_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XBnn_layer3_xnor_Initialize(XBnn_layer3_xnor *InstancePtr, UINTPTR BaseAddress) {
	XBnn_layer3_xnor_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XBnn_layer3_xnor_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XBnn_layer3_xnor_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XBnn_layer3_xnor_Config *XBnn_layer3_xnor_LookupConfig(u16 DeviceId) {
	XBnn_layer3_xnor_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XBNN_LAYER3_XNOR_NUM_INSTANCES; Index++) {
		if (XBnn_layer3_xnor_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XBnn_layer3_xnor_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XBnn_layer3_xnor_Initialize(XBnn_layer3_xnor *InstancePtr, u16 DeviceId) {
	XBnn_layer3_xnor_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XBnn_layer3_xnor_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XBnn_layer3_xnor_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

