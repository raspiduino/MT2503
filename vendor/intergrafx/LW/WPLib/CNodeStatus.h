//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : 
// File        : CNodeStatus.h
// Description : C »y¨¥ 3D ª«¥óª¬ºA
// Author      : Ray
// Create      : 2010-09-20
// Update      : 2011-02-15
//==============================================================================

#ifndef __C_NODE_STATUS_H__
#define __C_NODE_STATUS_H__

#include "CUtils.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

typedef struct _AniInfo
{
	unsigned int	m_Duration;
} AniInfo;

struct _NodeAniStatus {
	const char		*m_AniName;
	unsigned char	m_IsBackward;
	long			m_TimeBegin;
	long			m_TimeEnd;
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

typedef struct _NodeAniStatus NodeAniStatus;

extern void NodeAniStatus_TrimLoop(NodeAniStatus *_this, long _Time);
extern void NodeAniStatus_CutLoop(NodeAniStatus *_this, long _Time);
extern void NodeAniStatus_Cut(NodeAniStatus *_this, long _Time);

extern void NodeAniStatusQueue_Push(CQueue *_this, NodeAniStatus *_item);
extern NodeAniStatus *NodeAniStatusQueue_Pop(CQueue *_this);
extern NodeAniStatus *NodeAniStatusQueue_Head(CQueue *_this);
extern NodeAniStatus *NodeAniStatusQueue_Tail(CQueue *_this);


struct _EventStatus {
	unsigned char	m_Event;
	unsigned char	m_EventPrev;
	unsigned char	m_EventStart;
	unsigned char	m_EventCount;
	unsigned long	m_Time;
	unsigned long	m_TimeNext;
	unsigned long	m_IntervalMin;
	unsigned long	m_IntervalMax;
};

typedef struct _EventStatus EventStatus;

extern int  RandomEvent_Random(int _min, int _max);
extern void RandomEvent_Init(EventStatus *_this, unsigned char _Start, unsigned char _Count, unsigned long _Min, unsigned long _Max);
extern int  RandomEvent_Get(EventStatus *_this, unsigned long _Time);
extern void RandomEvent_Set(EventStatus *_this, unsigned char _Event, unsigned long _Time);
extern int  RandomEvent_Hit(EventStatus *_this, unsigned long _GameTime);

typedef struct _TimeStatus
{
	CTime	m_Time;
	unsigned char m_MinInc;
} TimeStatus;

extern void TimeEvent_Set(TimeStatus *_this, unsigned char _Hour, unsigned char _Min, unsigned char _Sec, unsigned char _MinInc);
extern void TimeEvent_SetHour(TimeStatus *_this, CTime *_TimeCurrent);
extern void TimeEvent_SetQuadHour(TimeStatus *_this, CTime *_TimeCurrent);
extern int  TimeEvent_Get(TimeStatus *_this, CTime *_TimeCurrent);
//extern int  TimeEvent
#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__C_NODE_STATUS_H__
