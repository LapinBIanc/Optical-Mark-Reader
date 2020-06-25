// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.4
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef XIMAGEPROC_H
#define XIMAGEPROC_H

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
#include "ximageproc_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Ctrl_BaseAddress;
} XImageproc_Config;
#endif

typedef struct {
    u32 Ctrl_BaseAddress;
    u32 IsReady;
} XImageproc;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XImageproc_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XImageproc_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XImageproc_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XImageproc_ReadReg(BaseAddress, RegOffset) \
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
int XImageproc_Initialize(XImageproc *InstancePtr, u16 DeviceId);
XImageproc_Config* XImageproc_LookupConfig(u16 DeviceId);
int XImageproc_CfgInitialize(XImageproc *InstancePtr, XImageproc_Config *ConfigPtr);
#else
int XImageproc_Initialize(XImageproc *InstancePtr, const char* InstanceName);
int XImageproc_Release(XImageproc *InstancePtr);
#endif

void XImageproc_Start(XImageproc *InstancePtr);
u32 XImageproc_IsDone(XImageproc *InstancePtr);
u32 XImageproc_IsIdle(XImageproc *InstancePtr);
u32 XImageproc_IsReady(XImageproc *InstancePtr);
void XImageproc_EnableAutoRestart(XImageproc *InstancePtr);
void XImageproc_DisableAutoRestart(XImageproc *InstancePtr);

void XImageproc_Set_image_in(XImageproc *InstancePtr, u32 Data);
u32 XImageproc_Get_image_in(XImageproc *InstancePtr);
void XImageproc_Set_image_out(XImageproc *InstancePtr, u32 Data);
u32 XImageproc_Get_image_out(XImageproc *InstancePtr);

void XImageproc_InterruptGlobalEnable(XImageproc *InstancePtr);
void XImageproc_InterruptGlobalDisable(XImageproc *InstancePtr);
void XImageproc_InterruptEnable(XImageproc *InstancePtr, u32 Mask);
void XImageproc_InterruptDisable(XImageproc *InstancePtr, u32 Mask);
void XImageproc_InterruptClear(XImageproc *InstancePtr, u32 Mask);
u32 XImageproc_InterruptGetEnabled(XImageproc *InstancePtr);
u32 XImageproc_InterruptGetStatus(XImageproc *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
