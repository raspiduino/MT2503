//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : M3DGameFramework
// File        : M3DEventQueue.h
// Description : C 語言公用結構與函式
// Author      : Ray
// Create      : 2011-06-02
// Update      : 2011-06-03
//==============================================================================

#include "M3DGameDef.h"
#include "M3DUtils.h"

#ifndef __M3D_EVENT_QUEUE__
#define __M3D_EVENT_QUEUE__


#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

extern M3DArrayPool *M3DEventQueue_New(int _count);
extern void M3DEventQueue_Del(M3DArrayPool *_this);
extern M3DEvent *M3DEventQueue_Alloc(M3DArrayPool *_this);
extern void M3DEventQueue_Free(M3DArrayPool *_this, M3DEvent *_event);
extern void M3DEventQueue_PostEvent(M3DArrayPool *_this, M3DQueue *_queue, unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2);
extern void M3DEventQueue_ClearPendingEvents(M3DArrayPool *_this, M3DQueue *_queue);
extern M3DEvent *M3DEventQueue_GetEvent(M3DArrayPool *_this, M3DQueue *_queue);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__M3D_EVENT_QUEUE__
