//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : 
// File        : CNodeStatus.c
// Description : C 語言 3D 物件狀態
// Author      : Ray
// Create      : 2010-09-20
// Update      : 2011-02-15
//==============================================================================

#include "CNodeStatus.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

void NodeAniStatus_TrimLoop(NodeAniStatus *_this, long _Time)
{
	long AniDuration = (long) ((_this->m_AniEnd - _this->m_AniBegin) * _this->m_AniRatio);
	long TimeEnd = _this->m_TimeBegin;
	int iTimes = 0;

	if (_this->m_IsLoop == 0 || _this->m_TimeEnd > _Time)
		return;

	while (TimeEnd < _Time)
	{
		iTimes = iTimes + 1;
		if (_this->m_IsBackward == 1)
			TimeEnd = TimeEnd + AniDuration * 2;
		else
			TimeEnd = TimeEnd + AniDuration;
	}

	_this->m_TimeEnd = TimeEnd;
}

//設定幾秒之後 loop 要結束
void NodeAniStatus_EndLoop(NodeAniStatus *_this, long _Time, long _Duration)
{
	long AniDuration = (long) ((_this->m_AniEnd - _this->m_AniBegin) * _this->m_AniRatio);
	long TimeEnd = _this->m_TimeBegin;
	int iTimes = 0;

	if (_this->m_IsLoop == 0 || _this->m_TimeEnd > _Time)
		return;

	while (TimeEnd < _Time)
	{
		iTimes = iTimes + 1;
		if (_this->m_IsBackward == 1)
			TimeEnd = TimeEnd + AniDuration * 2;
		else
			TimeEnd = TimeEnd + AniDuration;
	}

	_this->m_TimeEnd = TimeEnd;
}

void NodeAniStatus_CutLoop(NodeAniStatus *_this, long _Time)
{
	if (_this->m_IsLoop == 0 || _this->m_TimeEnd > _Time)
		return;

	_this->m_TimeEnd = _Time;
}

void NodeAniStatus_Cut(NodeAniStatus *_this, long _Time)
{
	_this->m_TimeEnd = _Time;
}

void NodeAniStatusQueue_Push(CQueue *_this, NodeAniStatus *_item)
{
	CQueue_Push(_this, (void *) _item);
}

NodeAniStatus *NodeAniStatusQueue_Pop(CQueue *_this)
{
	return (NodeAniStatus *) CQueue_Pop(_this);
}

NodeAniStatus *NodeAniStatusQueue_Head(CQueue *_this)
{
	return (NodeAniStatus *) CQueue_Head(_this);
}

NodeAniStatus *NodeAniStatusQueue_Tail(CQueue *_this)
{
	return (NodeAniStatus *) CQueue_Tail(_this);
}

int RandomEvent_Random(int _min, int _max)
{
	int rnd_value = 0;

	rnd_value = rand() % (_max - _min + 1) + _min;
	//rnd_value = (double) rand() / (RAND_MAX + 1) * (_max - _min) + _min;
	return rnd_value;
}

static long RandomEvent_RandomL(long _min, long _max)
{
	long rnd_value = 0;

	rnd_value = rand() % (_max - _min + 1) + _min;
	//rnd_value = (double) rand() / (RAND_MAX + 1) * (_max - _min) + _min;
	return rnd_value;
}

void RandomEvent_Init(EventStatus *_this, unsigned char _Start, unsigned char _Count, unsigned long _Min, unsigned long _Max)
{
	_this->m_EventStart = _Start;
	_this->m_EventPrev = 0;
	_this->m_EventCount = _Count;
	_this->m_IntervalMin = _Min;
	_this->m_IntervalMax = _Max;
	_this->m_Time = 0;
	_this->m_TimeNext = _this->m_Time + RandomEvent_RandomL(_this->m_IntervalMin, _this->m_IntervalMax);
}

//判斷是否要進入下一個事件, 並且產生事件
int RandomEvent_Get(EventStatus *_this, unsigned long _Time)
{
	int iEvent = -1;
	if (_Time > _this->m_TimeNext)
	{
		iEvent = RandomEvent_Random(_this->m_EventStart, _this->m_EventStart + _this->m_EventCount - 1);
		_this->m_Time = _this->m_TimeNext;
		_this->m_TimeNext = _this->m_Time + RandomEvent_RandomL(_this->m_IntervalMin, _this->m_IntervalMax);
		_this->m_EventPrev = _this->m_Event;
		_this->m_Event = (unsigned char) iEvent;
	}

	return iEvent;
}

void RandomEvent_Set(EventStatus *_this, unsigned char _Event, unsigned long _Time)
{
	_this->m_EventPrev = _this->m_Event;
	_this->m_Event = _Event;
	_this->m_Time = _Time;
}

int RandomEvent_Hit(EventStatus *_this, unsigned long _GameTime)
{
	unsigned long tDiff;
	int	min, max, iRnd;
	int hit = 0;
	unsigned char iEvent = 0;

	tDiff = _GameTime - _this->m_Time;
	min = 0;
	max = (_this->m_IntervalMax - _this->m_IntervalMin) / 1000;

	if (tDiff > _this->m_IntervalMax)
	{
		hit = 1;
	}
	else
	{
		if (tDiff > _this->m_IntervalMin)
		{
			iRnd = RandomEvent_Random(min, max);
			if (iRnd <= (int) ((tDiff - _this->m_IntervalMin) / 1000))
				hit = 1;
		}
	}

	if (hit == 1)
	{
		if (_this->m_EventCount > 1)
		{
			while ((iEvent = RandomEvent_Random(0, _this->m_EventCount-1)) == _this->m_Event);
		}

		_this->m_Event = iEvent;
		_this->m_Time = _GameTime;
	}

	return hit;
}

void TimeEvent_Set(TimeStatus *_this, unsigned char _Hour, unsigned char _Min, unsigned char _Sec, unsigned char _MinInc)
{
	CTime_Set(&_this->m_Time, _Hour, _Min, _Sec);
	_this->m_MinInc = _MinInc;
}

void TimeEvent_SetHour(TimeStatus *_this, CTime *_TimeCurrent)
{
	unsigned hour = _TimeCurrent->m_Hour;
	if (_TimeCurrent->m_Min == 0)
	{
		hour = hour + 1;
		if (hour == 24)
			hour = 0;
	}
	CTime_Set(&_this->m_Time, hour, 0, 0);
	_this->m_MinInc = 60;
}

void TimeEvent_SetQuadHour(TimeStatus *_this, CTime *_TimeCurrent)
{
	unsigned char hour = _TimeCurrent->m_Hour;
	unsigned char min = _TimeCurrent->m_Min;

	min = (_TimeCurrent->m_Min%15 + 1) * 15;

	if (min == 60)
	{
		hour = hour + 1;
		if (hour == 24)
			hour = 0;
		min = 0;
	}
	CTime_Set(&_this->m_Time, hour, min, 0);
	_this->m_MinInc = 15;
}

int  TimeEvent_Get(TimeStatus *_this, CTime *_TimeCurrent)
{
	int iEvent = 0;
	unsigned char hour = _this->m_Time.m_Hour;
	unsigned char min = _this->m_Time.m_Min;

	//如果, 目前的小時 大於等於 狀態物件內紀錄的時間, 且, 目前的分 大於等於 狀態物件內的分
	if (_TimeCurrent->m_Hour >= _this->m_Time.m_Hour && _TimeCurrent->m_Min >= _this->m_Time.m_Min)
	{
		//觸發開花事件
		iEvent = 1;
		
		min = min + _this->m_MinInc;
		hour = hour + min / 60;
		min = min % 60;
		hour = hour % 24;
		_this->m_Time.m_Hour = hour;
		_this->m_Time.m_Min = min;
	}
	return iEvent;
}

#ifdef __cplusplus
}
#endif // __cplusplus

