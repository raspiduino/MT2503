//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : M3DGameFramework
// File        : M3DEventQueue.c
// Description : C 語言公用結構與函式
// Author      : Ray
// Create      : 2011-06-02
// Update      : 2011-06-03
//==============================================================================

#include "M3DGameDef.h"
#include "M3DUtils.h"
#include "M3DEventQueue.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

M3DArrayPool *M3DEventQueue_New(int _count)
{
	M3DArrayPool *_this = M3DMemory_New(sizeof(M3DArrayPool));
	M3DEvent *events = NULL;

	if(_this != NULL)
	{
		events = M3DMemory_New(sizeof(M3DEvent) * _count);
		M3DArrayPool_Init(_this, (void *) events, sizeof(M3DEvent) * _count, sizeof(M3DEvent));
	}

	return _this;
}

void M3DEventQueue_Del(M3DArrayPool *_this)
{
	M3DMemory_Del(_this->m_Mem);
	_this->m_Mem = NULL;
	M3DMemory_Del(_this);
}

M3DEvent *M3DEventQueue_Alloc(M3DArrayPool *_this)
{
	return (M3DEvent *) M3DArrayPool_Alloc(_this);
}

void M3DEventQueue_Free(M3DArrayPool *_this, M3DEvent *_event)
{
	M3DArrayPool_Free(_this, (void *) _event);
}

void M3DEventQueue_PostEvent(M3DArrayPool *_this, M3DQueue *_queue, unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2)
{
	M3DEvent *pGE = M3DEventQueue_Alloc(_this);

	pGE->m_uEventID = _Id;
	pGE->m_uTime = _Time;
	pGE->m_uData1 = _Data1;
	pGE->m_uData2 = _Data2;

	M3DQueue_Push(_queue, (void *) pGE);
}

void M3DEventQueue_ClearPendingEvents(M3DArrayPool *_this, M3DQueue *_queue)
{
	M3DQueue_Clear(_queue);
}

M3DEvent *M3DEventQueue_GetEvent(M3DArrayPool *_this, M3DQueue *_queue)
{
	M3DEvent *pR;

	pR = (M3DEvent *) M3DQueue_Pop(_queue);

	return pR;
}

#ifdef __cplusplus
}
#endif // __cplusplus
