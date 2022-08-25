//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : IGV3GameFramework
// File        : CMemory.h
// Description : 記憶體管理公用結構與函式
// Author      : Ray
// Create      : 2010-11-19
// Update      : 2011-02-15
//==============================================================================

#include "CMemory.h"
#include "V3Retained.h"
#include "IGMemoryPool.h"
#include "IGComDef.h" 
#include "IGMathUtil.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

static int iMem = 0;

void *CNew(unsigned long _Size)
{
	void *_Memory = NULL;
	IGErr err;

	_Memory = IGMemoryPool_allocate(V3Retained_GetMem(), _Size, &err);
	IGMemoryPool_i_memset(_Memory, _Size, 0, &err);
	iMem = iMem + 1;

	return _Memory;
}

void CDel(void *_Memory)
{
	IGErr err;

	if (_Memory != NULL)
	{
		IGMemoryPool_free(V3Retained_GetMem(), _Memory, &err);
		iMem = iMem - 1;
		_Memory = NULL;
	}
}

void CMemcpy(void *_dest, void *_src, long _size)
{
	IGErr err;

	if (_dest != NULL && _src != NULL)
	{
		IGMemoryPool_i_memcpy(_dest, _src, _size, &err);
	}
}

void CMemset(void *_Memory, long _count, int _value)
{
	IGErr err;

	if (_Memory != NULL)
	{
		IGMemoryPool_i_memset(_Memory, _count, _value, &err);
	}
}

float CDistance(float _x, float _y, float _z)
{
	float distance = 0.0f;
	igreal x, y, z, value;

	x = (igreal) (_x * IG_ONE);
	y = (igreal) (_y * IG_ONE);
	z = (igreal) (_z * IG_ONE);

	value = IG_MUL(x, x) + IG_MUL(y, y) + IG_MUL(z, z);
	distance = (float) IG_SQRT(value) / IG_ONE;

	return distance;
}

igreal CDistance_i(igreal _x, igreal _y, igreal _z)
{
	igreal distance = 0;
	igreal x, y, z, value;

	x = (igreal) (_x);
	y = (igreal) (_y);
	z = (igreal) (_z);

	value = IG_MUL(x, x) + IG_MUL(y, y) + IG_MUL(z, z);
	distance = IG_SQRT(value);

	return distance;
}

#ifdef __cplusplus
}
#endif // __cplusplus
