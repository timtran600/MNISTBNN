// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XBNN_LAYER3_XNOR_H
#define XBNN_LAYER3_XNOR_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xbnn_layer3_xnor_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
#ifdef SDT
    char *Name;
#else
    u16 DeviceId;
#endif
    u64 Control_BaseAddress;
} XBnn_layer3_xnor_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XBnn_layer3_xnor;

typedef u32 word_type;

typedef struct {
    u32 word_0;
    u32 word_1;
    u32 word_2;
    u32 word_3;
    u32 word_4;
    u32 word_5;
    u32 word_6;
    u32 word_7;
} XBnn_layer3_xnor_Input_r;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XBnn_layer3_xnor_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XBnn_layer3_xnor_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XBnn_layer3_xnor_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XBnn_layer3_xnor_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
#ifdef SDT
int XBnn_layer3_xnor_Initialize(XBnn_layer3_xnor *InstancePtr, UINTPTR BaseAddress);
XBnn_layer3_xnor_Config* XBnn_layer3_xnor_LookupConfig(UINTPTR BaseAddress);
#else
int XBnn_layer3_xnor_Initialize(XBnn_layer3_xnor *InstancePtr, u16 DeviceId);
XBnn_layer3_xnor_Config* XBnn_layer3_xnor_LookupConfig(u16 DeviceId);
#endif
int XBnn_layer3_xnor_CfgInitialize(XBnn_layer3_xnor *InstancePtr, XBnn_layer3_xnor_Config *ConfigPtr);
#else
int XBnn_layer3_xnor_Initialize(XBnn_layer3_xnor *InstancePtr, const char* InstanceName);
int XBnn_layer3_xnor_Release(XBnn_layer3_xnor *InstancePtr);
#endif

void XBnn_layer3_xnor_Start(XBnn_layer3_xnor *InstancePtr);
u32 XBnn_layer3_xnor_IsDone(XBnn_layer3_xnor *InstancePtr);
u32 XBnn_layer3_xnor_IsIdle(XBnn_layer3_xnor *InstancePtr);
u32 XBnn_layer3_xnor_IsReady(XBnn_layer3_xnor *InstancePtr);
void XBnn_layer3_xnor_EnableAutoRestart(XBnn_layer3_xnor *InstancePtr);
void XBnn_layer3_xnor_DisableAutoRestart(XBnn_layer3_xnor *InstancePtr);

void XBnn_layer3_xnor_Set_input_r(XBnn_layer3_xnor *InstancePtr, XBnn_layer3_xnor_Input_r Data);
XBnn_layer3_xnor_Input_r XBnn_layer3_xnor_Get_input_r(XBnn_layer3_xnor *InstancePtr);
void XBnn_layer3_xnor_Set_output_r(XBnn_layer3_xnor *InstancePtr, u64 Data);
u64 XBnn_layer3_xnor_Get_output_r(XBnn_layer3_xnor *InstancePtr);
void XBnn_layer3_xnor_Set_weights(XBnn_layer3_xnor *InstancePtr, u64 Data);
u64 XBnn_layer3_xnor_Get_weights(XBnn_layer3_xnor *InstancePtr);
void XBnn_layer3_xnor_Set_load_weights(XBnn_layer3_xnor *InstancePtr, u32 Data);
u32 XBnn_layer3_xnor_Get_load_weights(XBnn_layer3_xnor *InstancePtr);

void XBnn_layer3_xnor_InterruptGlobalEnable(XBnn_layer3_xnor *InstancePtr);
void XBnn_layer3_xnor_InterruptGlobalDisable(XBnn_layer3_xnor *InstancePtr);
void XBnn_layer3_xnor_InterruptEnable(XBnn_layer3_xnor *InstancePtr, u32 Mask);
void XBnn_layer3_xnor_InterruptDisable(XBnn_layer3_xnor *InstancePtr, u32 Mask);
void XBnn_layer3_xnor_InterruptClear(XBnn_layer3_xnor *InstancePtr, u32 Mask);
u32 XBnn_layer3_xnor_InterruptGetEnabled(XBnn_layer3_xnor *InstancePtr);
u32 XBnn_layer3_xnor_InterruptGetStatus(XBnn_layer3_xnor *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
