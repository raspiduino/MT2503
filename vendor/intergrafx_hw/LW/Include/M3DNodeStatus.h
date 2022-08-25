//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : 
// File        : M3DNodeStatus.h
// Description : C »y¨¥ 3D ª«¥óª¬ºA
// Author      : Ray
// Create      : 2010-09-20
// Update      : 2011-02-15
//==============================================================================

#ifndef __M3D_NODE_STATUS_H__
#define __M3D_NODE_STATUS_H__

#include "M3DUtils.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

struct _M3DNodeAniStatus {
	const char		*m_AniName;
	unsigned char	m_IsBackward;
	float			m_TimeBegin;
	float			m_TimeEnd;
	unsigned int	m_AniBegin;
	unsigned int	m_AniEnd;
	unsigned int	m_AniCurrent;
	float			m_AniRatio;		// (1 / speed)
	unsigned char	m_IsLoop;
	int				m_EventType;

	void			*m_PathNode;
	const char		*m_PathAniName;
	unsigned int	m_PathAniBegin;
	unsigned int	m_PathAniEnd;
	float			m_Position[3];
	float			m_Rotation;
	float			m_PositionV[3];
	float			m_RotationV;
};

typedef struct _M3DNodeAniStatus M3DNodeAniStatus;

extern void M3DNodeAniStatus_TrimLoop(M3DNodeAniStatus *_this, float _Time);
extern void M3DNodeAniStatus_CutLoop(M3DNodeAniStatus *_this, float _Time);
extern void M3DNodeAniStatus_Cut(M3DNodeAniStatus *_this, float _Time);

extern void M3DNodeAniStatusQueue_Push(M3DQueue *_this, M3DNodeAniStatus *_item);
extern M3DNodeAniStatus *M3DNodeAniStatusQueue_Pop(M3DQueue *_this);
extern M3DNodeAniStatus *M3DNodeAniStatusQueue_Head(M3DQueue *_this);
extern M3DNodeAniStatus *M3DNodeAniStatusQueue_Tail(M3DQueue *_this);


struct _M3DEventStatus {
	unsigned char	m_Event;
	unsigned char	m_EventPrev;
	unsigned char	m_EventStart;
	unsigned char	m_EventCount;
	float	m_Time;
	float	m_TimeNext;
	unsigned long	m_IntervalMin;
	unsigned long	m_IntervalMax;
};

typedef struct _M3DEventStatus M3DEventStatus;

extern int  M3DRandomEvent_Random(int _min, int _max);
extern void M3DRandomEvent_Init(M3DEventStatus *_this, unsigned char _Start, unsigned char _Count, unsigned long _Min, unsigned long _Max);
extern int  M3DRandomEvent_Get(M3DEventStatus *_this, float _Time);
extern void M3DRandomEvent_Set(M3DEventStatus *_this, unsigned char _Event, float _Time);
extern int  M3DRandomEvent_Hit(M3DEventStatus *_this, float _GameTime);

typedef struct _M3DTimeStatus
{
	M3DTime	m_Time;
	unsigned char m_MinInc;
} M3DTimeStatus;

extern void M3DTimeEvent_Set(M3DTimeStatus *_this, unsigned char _Hour, unsigned char _Min, unsigned char _Sec, unsigned char _MinInc);
extern void M3DTimeEvent_SetHour(M3DTimeStatus *_this, M3DTime *_TimeCurrent);
extern void M3DTimeEvent_SetQuadHour(M3DTimeStatus *_this, M3DTime *_TimeCurrent);
extern int  M3DTimeEvent_Get(M3DTimeStatus *_this, M3DTime *_TimeCurrent);

//extern int  TimeEvent

typedef struct _M3DTimer
{
	int		m_Enabled;
	float	m_Interval;
	float	m_TimeSet;
} M3DTimer;

extern void M3DTimer_Set(M3DTimer *_this, float _GameTime, float _Interval);
extern int  M3DTimer_Check(M3DTimer *_this, float _GameTime);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__M3D_NODE_STATUS_H__
