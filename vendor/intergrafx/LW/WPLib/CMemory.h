//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : IGV3GameFramework
// File        : CMemory.h
// Description : 記憶體管理公用結構與函式
// Author      : Ray
// Create      : 2010-11-19
// Update      : 2011-02-15
//==============================================================================

#include "IGMemoryPool.h"

#ifndef __C_MEMORY__
#define __C_MEMORY__

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus


extern void *CNew(unsigned long _Size);
extern void CDel(void *_Memory);
extern void CMemcpy(void *_dest, void *_src, long _size);
extern void CMemset(void *_Memory, long _count, int _value);
extern float CDistance(float _x, float _y, float _z);
extern igreal CDistance_i(igreal _x, igreal _y, igreal _z);

#define CStrNCpy IGMemoryPool_i_strncpy
#define CStrCmp  IGMemoryPool_i_strcmp
#define CStrLen  IGMemoryPool_i_strlen

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__C_MEMORY__
