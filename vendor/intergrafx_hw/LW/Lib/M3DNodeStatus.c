//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : 
// File        : M3DNodeStatus.c
// Description : C 語言 3D 物件狀態
// Author      : Ray
// Create      : 2010-09-20
// Update      : 2011-02-15
//==============================================================================

#include "m3d_adaption.h"
#include "M3DNodeStatus.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus


void M3DNodeAniStatus_TrimLoop(M3DNodeAniStatus *_this, float _Time)
{
	float AniDuration = (float) ((_this->m_AniEnd - _this->m_AniBegin) * _this->m_AniRatio);
	float TimeEnd = _this->m_TimeBegin;
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
void M3DNodeAniStatus_EndLoop(M3DNodeAniStatus *_this, float _Time, float _Duration)
{
	float AniDuration = (float) ((_this->m_AniEnd - _this->m_AniBegin) * _this->m_AniRatio);
	float TimeEnd = _this->m_TimeBegin;
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

void M3DNodeAniStatus_CutLoop(M3DNodeAniStatus *_this, float _Time)
{
	if (_this->m_IsLoop == 0 || _this->m_TimeEnd > _Time)
		return;

	_this->m_TimeEnd = _Time;
}

void M3DNodeAniStatus_Cut(M3DNodeAniStatus *_this, float _Time)
{
	_this->m_TimeEnd = _Time;
}

void M3DNodeAniStatusQueue_Push(M3DQueue *_this, M3DNodeAniStatus *_item)
{
	M3DQueue_Push(_this, (void *) _item);
}

M3DNodeAniStatus *M3DNodeAniStatusQueue_Pop(M3DQueue *_this)
{
	return (M3DNodeAniStatus *) M3DQueue_Pop(_this);
}

M3DNodeAniStatus *M3DNodeAniStatusQueue_Head(M3DQueue *_this)
{
	return (M3DNodeAniStatus *) M3DQueue_Head(_this);
}

M3DNodeAniStatus *M3DNodeAniStatusQueue_Tail(M3DQueue *_this)
{
	return (M3DNodeAniStatus *) M3DQueue_Tail(_this);
}

int M3DRandomEvent_Random(int _min, int _max)
{
	int rnd_value = 0;

	rnd_value = m3d_adaption_rand() % (_max - _min + 1) + _min;
	//rnd_value = (double) rand() / (RAND_MAX + 1) * (_max - _min) + _min;
	return rnd_value;
}

static long M3DRandomEvent_RandomL(long _min, long _max)
{
	long rnd_value = 0;

	rnd_value = m3d_adaption_rand() % (_max - _min + 1) + _min;
	//rnd_value = (double) rand() / (RAND_MAX + 1) * (_max - _min) + _min;
	return rnd_value;
}

void M3DRandomEvent_Init(M3DEventStatus *_this, unsigned char _Start, unsigned char _Count, unsigned long _Min, unsigned long _Max)
{
	_this->m_EventStart = _Start;
	_this->m_EventPrev = 0;
	_this->m_EventCount = _Count;
	_this->m_IntervalMin = _Min;
	_this->m_IntervalMax = _Max;
	_this->m_Time = 0;
	_this->m_TimeNext = _this->m_Time + M3DRandomEvent_RandomL(_this->m_IntervalMin, _this->m_IntervalMax);
}

//判斷是否要進入下一個事件, 並且產生事件
int M3DRandomEvent_Get(M3DEventStatus *_this, float _Time)
{
	int iEvent = -1;
	if (_Time > _this->m_TimeNext)
	{
		iEvent = M3DRandomEvent_Random(_this->m_EventStart, _this->m_EventStart + _this->m_EventCount - 1);
		_this->m_Time = _this->m_TimeNext;
		_this->m_TimeNext = _this->m_Time + M3DRandomEvent_RandomL(_this->m_IntervalMin, _this->m_IntervalMax);
		_this->m_EventPrev = _this->m_Event;
		_this->m_Event = (unsigned char) iEvent;
	}

	return iEvent;
}

void M3DRandomEvent_Set(M3DEventStatus *_this, unsigned char _Event, float _Time)
{
	_this->m_EventPrev = _this->m_Event;
	_this->m_Event = _Event;
	_this->m_Time = _Time;
}

int M3DRandomEvent_Hit(M3DEventStatus *_this, float _GameTime)
{
	float tDiff;
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
			iRnd = M3DRandomEvent_Random(min, max);
			if (iRnd <= (int) ((tDiff - _this->m_IntervalMin) / 1000))
				hit = 1;
		}
	}

	if (hit == 1)
	{
		if (_this->m_EventCount > 1)
		{
			while ((iEvent = M3DRandomEvent_Random(0, _this->m_EventCount-1)) == _this->m_Event);
		}

		_this->m_Event = iEvent;
		_this->m_Time = _GameTime;
	}

	return hit;
}

void M3DTimeEvent_Set(M3DTimeStatus *_this, unsigned char _Hour, unsigned char _Min, unsigned char _Sec, unsigned char _MinInc)
{
	M3DTime_Set(&_this->m_Time, _Hour, _Min, _Sec);
	_this->m_MinInc = _MinInc;
}

void M3DTimeEvent_SetHour(M3DTimeStatus *_this, M3DTime *_TimeCurrent)
{
	unsigned hour = _TimeCurrent->m_Hour;
	if (_TimeCurrent->m_Min == 0)
	{
		hour = hour + 1;
		if (hour == 24)
			hour = 0;
	}
	M3DTime_Set(&_this->m_Time, hour, 0, 0);
	_this->m_MinInc = 60;
}

void M3DTimeEvent_SetQuadHour(M3DTimeStatus *_this, M3DTime *_TimeCurrent)
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
	M3DTime_Set(&_this->m_Time, hour, min, 0);
	_this->m_MinInc = 15;
}

int  M3DTimeEvent_Get(M3DTimeStatus *_this, M3DTime *_TimeCurrent)
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

void M3DTimer_Set(M3DTimer *_this, float _GameTime, float _Interval)
{
	_this->m_Enabled = 1;
	_this->m_Interval = _Interval;
	_this->m_TimeSet = _GameTime;
}

int  M3DTimer_Check(M3DTimer *_this, float _GameTime)
{
	int ret = 0;
	if ((_this->m_Enabled == 1) && (_GameTime > (_this->m_TimeSet + _this->m_Interval)))
	{
		ret = 1;
		_this->m_Enabled = 0;
	}
	return ret;
}

#ifdef __cplusplus
}
#endif // __cplusplus

