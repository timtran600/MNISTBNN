// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XBNN_TOP_H
#define XBNN_TOP_H

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
#include "xbnn_top_hw.h"

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
} XBnn_top_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XBnn_top;

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
    u32 word_8;
    u32 word_9;
    u32 word_10;
    u32 word_11;
    u32 word_12;
    u32 word_13;
    u32 word_14;
    u32 word_15;
    u32 word_16;
    u32 word_17;
    u32 word_18;
    u32 word_19;
    u32 word_20;
    u32 word_21;
    u32 word_22;
    u32 word_23;
    u32 word_24;
} XBnn_top_Input_r;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XBnn_top_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XBnn_top_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XBnn_top_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XBnn_top_ReadReg(BaseAddress, RegOffset) \
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
int XBnn_top_Initialize(XBnn_top *InstancePtr, UINTPTR BaseAddress);
XBnn_top_Config* XBnn_top_LookupConfig(UINTPTR BaseAddress);
#else
int XBnn_top_Initialize(XBnn_top *InstancePtr, u16 DeviceId);
XBnn_top_Config* XBnn_top_LookupConfig(u16 DeviceId);
#endif
int XBnn_top_CfgInitialize(XBnn_top *InstancePtr, XBnn_top_Config *ConfigPtr);
#else
int XBnn_top_Initialize(XBnn_top *InstancePtr, const char* InstanceName);
int XBnn_top_Release(XBnn_top *InstancePtr);
#endif

void XBnn_top_Start(XBnn_top *InstancePtr);
u32 XBnn_top_IsDone(XBnn_top *InstancePtr);
u32 XBnn_top_IsIdle(XBnn_top *InstancePtr);
u32 XBnn_top_IsReady(XBnn_top *InstancePtr);
void XBnn_top_EnableAutoRestart(XBnn_top *InstancePtr);
void XBnn_top_DisableAutoRestart(XBnn_top *InstancePtr);

void XBnn_top_Set_input_r(XBnn_top *InstancePtr, XBnn_top_Input_r Data);
XBnn_top_Input_r XBnn_top_Get_input_r(XBnn_top *InstancePtr);
void XBnn_top_Set_l1_weights(XBnn_top *InstancePtr, u64 Data);
u64 XBnn_top_Get_l1_weights(XBnn_top *InstancePtr);
void XBnn_top_Set_l2_weights(XBnn_top *InstancePtr, u64 Data);
u64 XBnn_top_Get_l2_weights(XBnn_top *InstancePtr);
void XBnn_top_Set_l3_weights(XBnn_top *InstancePtr, u64 Data);
u64 XBnn_top_Get_l3_weights(XBnn_top *InstancePtr);
void XBnn_top_Set_load_weights(XBnn_top *InstancePtr, u32 Data);
u32 XBnn_top_Get_load_weights(XBnn_top *InstancePtr);

void XBnn_top_InterruptGlobalEnable(XBnn_top *InstancePtr);
void XBnn_top_InterruptGlobalDisable(XBnn_top *InstancePtr);
void XBnn_top_InterruptEnable(XBnn_top *InstancePtr, u32 Mask);
void XBnn_top_InterruptDisable(XBnn_top *InstancePtr, u32 Mask);
void XBnn_top_InterruptClear(XBnn_top *InstancePtr, u32 Mask);
u32 XBnn_top_InterruptGetEnabled(XBnn_top *InstancePtr);
u32 XBnn_top_InterruptGetStatus(XBnn_top *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
