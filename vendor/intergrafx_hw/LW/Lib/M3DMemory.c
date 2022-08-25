//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : M3DGameFramework
// File        : M3DMemory.h
// Description : 記憶體管理公用結構與函式, 這個會隨著引擎而不同
// Author      : Ray
// Create      : 2010-11-19
// Update      : 2011-06-03
//==============================================================================

#include "M3DMemory.h"
#include "IGV5Memory.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

static int iMem = 0;
//static IGMemory *pMem = NULL;

void M3DMemory_SetMemory(void)
{
	//pMem = _mMem;
}

void *M3DMemory_New(unsigned long _Size)
{
	void *_Memory = NULL;

	_Memory = IGV5Memory_Alloc(_Size);
	if (_Memory != NULL)
	{
		memset(_Memory, 0, _Size);
		iMem = iMem + 1;
	}

	return _Memory;
}

void M3DMemory_Del(void *_Memory)
{
	if (_Memory != NULL)
	{
		IGV5Memory_Free(_Memory);
		iMem = iMem - 1;
		_Memory = NULL;
	}
}

void M3DMemory_Copy(void *_dest, void *_src, long _size)
{
	if (_dest != NULL && _src != NULL)
	{
		memcpy(_dest, _src, _size);
	}
}

void M3DMemory_Set(void *_Memory, long _count, int _value)
{
	if (_Memory != NULL)
	{
		memset(_Memory, _value, _count);
	}
}
#ifdef __cplusplus
}
#endif // __cplusplus
