// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.1
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xconvhw.h"

extern XConvhw_Config XConvhw_ConfigTable[];

XConvhw_Config *XConvhw_LookupConfig(u16 DeviceId) {
	XConvhw_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XCONVHW_NUM_INSTANCES; Index++) {
		if (XConvhw_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XConvhw_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XConvhw_Initialize(XConvhw *InstancePtr, u16 DeviceId) {
	XConvhw_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XConvhw_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XConvhw_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

