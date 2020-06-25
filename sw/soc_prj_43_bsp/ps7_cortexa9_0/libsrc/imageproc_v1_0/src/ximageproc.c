// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.4
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

/***************************** Include Files *********************************/
#include "ximageproc.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XImageproc_CfgInitialize(XImageproc *InstancePtr, XImageproc_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Ctrl_BaseAddress = ConfigPtr->Ctrl_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XImageproc_Start(XImageproc *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XImageproc_ReadReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_AP_CTRL) & 0x80;
    XImageproc_WriteReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XImageproc_IsDone(XImageproc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XImageproc_ReadReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XImageproc_IsIdle(XImageproc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XImageproc_ReadReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XImageproc_IsReady(XImageproc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XImageproc_ReadReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XImageproc_EnableAutoRestart(XImageproc *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImageproc_WriteReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_AP_CTRL, 0x80);
}

void XImageproc_DisableAutoRestart(XImageproc *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImageproc_WriteReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_AP_CTRL, 0);
}

void XImageproc_Set_image_in(XImageproc *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImageproc_WriteReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_IMAGE_IN_DATA, Data);
}

u32 XImageproc_Get_image_in(XImageproc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XImageproc_ReadReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_IMAGE_IN_DATA);
    return Data;
}

void XImageproc_Set_image_out(XImageproc *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImageproc_WriteReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_IMAGE_OUT_DATA, Data);
}

u32 XImageproc_Get_image_out(XImageproc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XImageproc_ReadReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_IMAGE_OUT_DATA);
    return Data;
}

void XImageproc_InterruptGlobalEnable(XImageproc *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImageproc_WriteReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_GIE, 1);
}

void XImageproc_InterruptGlobalDisable(XImageproc *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImageproc_WriteReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_GIE, 0);
}

void XImageproc_InterruptEnable(XImageproc *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XImageproc_ReadReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_IER);
    XImageproc_WriteReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_IER, Register | Mask);
}

void XImageproc_InterruptDisable(XImageproc *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XImageproc_ReadReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_IER);
    XImageproc_WriteReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_IER, Register & (~Mask));
}

void XImageproc_InterruptClear(XImageproc *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImageproc_WriteReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_ISR, Mask);
}

u32 XImageproc_InterruptGetEnabled(XImageproc *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XImageproc_ReadReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_IER);
}

u32 XImageproc_InterruptGetStatus(XImageproc *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XImageproc_ReadReg(InstancePtr->Ctrl_BaseAddress, XIMAGEPROC_CTRL_ADDR_ISR);
}

