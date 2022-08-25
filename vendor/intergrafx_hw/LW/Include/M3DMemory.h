//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : IGV4GameFramework
// File        : M3DMemory.h
// Description : 記憶體管理公用結構與函式
// Author      : Ray
// Create      : 2010-11-19
// Update      : 2011-06-03
//==============================================================================

#include "IGV5Memory.h"

#ifndef __M3D_MEMORY__
#define __M3D_MEMORY__

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus


extern void  M3DMemory_SetMemory(void);
extern void *M3DMemory_New(unsigned long _Size);
extern void  M3DMemory_Del(void *_Memory);
extern void  M3DMemory_Copy(void *_dest, void *_src, long _size);
extern void  M3DMemory_Set(void *_Memory, long _count, int _value);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__C_MEMORY__
