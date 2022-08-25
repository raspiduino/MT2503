//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WPSample2
// File        : CWP1_A_Status.h
// Description : C 語言 3D 物件狀態
// Author      : Ray
// Create      : 2010-11-02
// Update      : 2011-02-15
//==============================================================================

#include "V3Retained.h"
#include "IGMathUtil.h"
#include "WP1-A-GameApp.h"
#include "WP1-A-Status.h"
#include "CUtils.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

//V3Retained *rr = NULL;

void WP1_A_Status_InitArrayPool(void)
{
	if(WP1_A.pStatusArrayPool == NULL) WP1_A.pStatusArrayPool = CNew(sizeof(CArrayPool));
	if(WP1_A.pStatusArray == NULL) WP1_A.pStatusArray = CNew(sizeof(NodeAniStatus) * MAX_ARRAY_POOL);
	CArrayPool_Init(WP1_A.pStatusArrayPool, (void *) WP1_A.pStatusArray, sizeof(NodeAniStatus) * MAX_ARRAY_POOL, sizeof(NodeAniStatus));
}

NodeAniStatus *WP1_A_Status_Alloc(void)
{
	if(WP1_A.pStatusArrayPool->m_Used > 400)WP1_A_Status_InitArrayPool();//避免Status的pool滿出來造成當機, edit by Odin
	return (NodeAniStatus *) CArrayPool_Alloc(WP1_A.pStatusArrayPool);
}

void WP1_A_Status_Free(NodeAniStatus *_this)
{
	CArrayPool_Free(WP1_A.pStatusArrayPool, (void *) _this);
}

WP1_A_Status *WP1_A_Status_New(IGNode *_pNode, const char *_Name, const char *_AniName)
{
	WP1_A_Status *self = NULL;

	if (WP1_A.pStatusArrayPool == NULL)
	{
		WP1_A_Status_InitArrayPool();
	}

	self = (WP1_A_Status *) CNew(sizeof(WP1_A_Status));
	CStrNCpy(self->m_Name, _Name, DEFAULT_NAME_SIZE);
	CStrNCpy(self->m_AniName, _AniName, DEFAULT_NAME_SIZE);
	self->m_Status = CQueue_New(DEFAULT_QUEUE_SIZE);
	self->m_Node = _pNode;

	return self;
}

void WP1_A_Status_Del(WP1_A_Status *_this)
{
	if(_this != NULL)
	{
		CQueue_Del(_this->m_Status);
		_this->m_Status = 0;
		CDel(_this);
	}
}

NodeAniStatus *WP1_A_Status_CurrentStatus(WP1_A_Status *_this, IGU32 _Time)
{
	NodeAniStatus *pStatus = NULL;
	NodeAniStatus *pPop = NULL;

	while (1)
	{
		pStatus = NodeAniStatusQueue_Tail(_this->m_Status);
		if (pStatus != NULL)
		{
			//RAY::2010-12-17 這邊要判斷是不是正在 Loop, 否則 Loop 會被砍掉, 其他所有的桌布這邊都要注意
			if (pStatus->m_TimeEnd >= 0 && pStatus->m_TimeEnd < (long) _Time)
			{
				pPop = NodeAniStatusQueue_Pop(_this->m_Status);
				WP1_A_Status_Free(pPop);
				pPop = NULL;
				continue;
			}
			break;
		}
		else
			break;
	}

	return pStatus;
}

void WP1_A_Status_EventHTouchMove(WP1_A_Status *_this, int _pixel)
{
	V3Retained *rr = V3Retained_GetInstance();
	int iMax = WP1_A.iMaxDeg2, iMin = WP1_A.iMinDeg2;

	//檢查是否正在進行自動校正, 如果正在進行自動校正, 使用者是無法調整鏡頭的
	if(WP1_A.isRecovering == 1)
	{
		WP1_A.m_HDegree = WP1_A.m_HDegree + _pixel;
		//這段是避免鏡頭轉過頭而讓畫面出現破綻
		if (WP1_A.m_HDegree > iMax)WP1_A.m_HDegree = (float)iMax;
		if (WP1_A.m_HDegree < iMin)WP1_A.m_HDegree = (float)iMin;

		if(WP1_A.m_HDegree == WP1_A.iMaxDeg1 || WP1_A.m_HDegree == WP1_A.iMinDeg1)WP1_A.isRecovering = 0;//結束自動補正
	}
	else
	{
		WP1_A.m_HDegree = WP1_A.m_HDegree + _pixel * WP1_A.m_DegreeInc;
		//這段是避免鏡頭轉過頭而讓畫面出現破綻
		if (WP1_A.m_HDegree > iMax)WP1_A.m_HDegree = (float)iMax;
		if (WP1_A.m_HDegree < iMin)WP1_A.m_HDegree = (float)iMin;
	}
}

void WP1_A_Status_EventFlower(WP1_A_Status *_this, IGU32 _GameTime)
{
	WP1_A_Status_Ani2(_this, _GameTime);
}

void WP1_A_Status_Wind1(WP1_A_Status *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;

	//找到最後一個狀態
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}

	if (WP1_A.m_Wind.m_EventPrev != MIMOSA_NONE)
		WP1_A_Status_Ani0C(_this, _GameTime, 20);

	WP1_A_Status_Ani0A(_this, _GameTime, 20);
	WP1_A_Status_Loop0B(_this, _GameTime, 20);
}

void WP1_A_Status_Wind3(WP1_A_Status *_this, IGU32 _GameTime, IGU8 _Times)
{
	NodeAniStatus *pStatus = NULL;

	//找到最後一個狀態
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}

	if (WP1_A.m_Wind.m_EventPrev != MIMOSA_NONE)
		WP1_A_Status_Ani0C(_this, _GameTime, 20);

	WP1_A_Status_Ani0A(_this, _GameTime, 100);
	WP1_A_Status_Ani0B(_this, _GameTime, 100, _Times);
	WP1_A_Status_Ani0C(_this, _GameTime, 100);
	WP1_A_Status_Ani0A(_this, _GameTime, 20);
	WP1_A_Status_Loop0B(_this, _GameTime, 20);
}

void WP1_A_Status_Wind2(WP1_A_Status *_this, IGU32 _GameTime, IGU8 _Times)
{
	NodeAniStatus *pStatus = NULL;

	//找到最後一個狀態
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}

	if (WP1_A.m_Wind.m_EventPrev != MIMOSA_NONE)
		WP1_A_Status_Ani0C(_this, _GameTime, 20);

	WP1_A_Status_Ani0A(_this, _GameTime, 50);
	WP1_A_Status_Ani0B(_this, _GameTime, 50, _Times);
	WP1_A_Status_Ani0C(_this, _GameTime, 50);
	WP1_A_Status_Ani0A(_this, _GameTime, 20);
	WP1_A_Status_Loop0B(_this, _GameTime, 20);
}

//Leaf
int  WP1_A_Status_Leaf_Position(void)
{
	int iHour = WP1_A_GetHour();
	int iPos = 0;

	/*
	if (iHour >= 0 && iHour < 6)
		iPos = 600;
	else if (iHour >= 6 && iHour < 8)
		iPos = 300;
	else if (iHour >= 8 && iHour < 15)
		iPos = 0;
	else if (iHour >= 15 && iHour < 19)
		iPos = 300;
	else if (iHour >= 19 && iHour < 24)
		iPos = 600;
	*/

	return iPos;
}

void WP1_A_Status_Leaf_Wind1(WP1_A_Status *_this, IGU32 _GameTime, IGU8 _Times)
{
	NodeAniStatus *pStatus = NULL;

	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}

	WP1_A_Status_Loop1(_this, _GameTime, 20);
}

void WP1_A_Status_Leaf_Wind2(WP1_A_Status *_this, IGU32 _GameTime, IGU8 _Times)
{
	NodeAniStatus *pStatus = NULL;

	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}

	WP1_A_Status_Loop1(_this, _GameTime, 50);
}

void WP1_A_Status_Leaf_Wind3(WP1_A_Status *_this, IGU32 _GameTime, IGU8 _Times)
{
	NodeAniStatus *pStatus = NULL;

	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}

	WP1_A_Status_Loop1(_this, _GameTime, 100);
}

void WP1_A_Status_EventLoop_Leaf(WP1_A_Status *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;

	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}

	WP1_A_Status_Loop1(_this, _GameTime, 100);

	WP1_A.m_CurrentLoop = 0;
}

void WP1_A_Status_EventTouchLeaf(WP1_A_Status *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;

	//找到最後一個狀態
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}

	//RAY::2010-01-21 本來要等 Loop 結束, 但是 Loop 太慢, 所以直接清除 Queue, 因為動作幅度比較小, 所以還 OK
	CQueue_Clear(_this->m_Status);
	WP1_A_Status_Ani1A(_this, _GameTime);
	WP1_A_Status_Ani1B(_this, _GameTime);
	//WP1_A_Status_Loop0_Leaf(_this, _GameTime);
	WP1_A_Status_Loop1(_this, _GameTime, 100);
}

void WP1_A_Status_Loop0_Leaf(WP1_A_Status *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = 0L;
	AniInfo *ani_info = CNamedObjArray_Get(WP1_A.m_AniInfo, 0);

	//找到最後一個狀態
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus == NULL)
		TimeBegin = _GameTime;
	else
		TimeBegin = pStatus->m_TimeEnd;

	pStatus = WP1_A_Status_Alloc();

	if(pStatus == NULL)return;

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_LOOP_0;
	pStatus->m_IsLoop = 1;
	pStatus->m_AniBegin = (unsigned int) (ani_info->m_Duration * 0.47f);
	pStatus->m_AniEnd = (unsigned int) (ani_info->m_Duration * 0.53f);
	pStatus->m_TimeEnd = -1;
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = "ANIMATE0";
	pStatus->m_IsBackward = 1;

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP1_A_Status_Loop0B(WP1_A_Status *_this, IGU32 _GameTime, int _iAmplitude)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = 0L;
	AniInfo *ani_info = CNamedObjArray_Get(WP1_A.m_AniInfo, 0);

	//找到最後一個狀態
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus == NULL)
		return;

	TimeBegin = pStatus->m_TimeEnd;

	pStatus = WP1_A_Status_Alloc();

	if(pStatus == NULL)return;

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_LOOP_0;
	pStatus->m_IsLoop = 1;
	pStatus->m_AniBegin = ani_info->m_Duration / 2 - (ani_info->m_Duration / 2 * _iAmplitude / 100);
	pStatus->m_AniEnd = ani_info->m_Duration / 2 + (ani_info->m_Duration / 2 * _iAmplitude / 100);
	pStatus->m_TimeEnd = -1;
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = "ANIMATE0";
	pStatus->m_IsBackward = 1;

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP1_A_Status_Ani0A(WP1_A_Status *_this, IGU32 _GameTime, int _iAmplitude)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = _GameTime;
	AniInfo *ani_info = CNamedObjArray_Get(WP1_A.m_AniInfo, 0);

	//pStatus = WP1_A_Status_CurrentStatus(_this, _GameTime);
	//應該要找最後一個 Status, 而不能找 Current Status
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WP1_A_Status_Alloc();

	if(pStatus == NULL) return;

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_ANIM_01;
	pStatus->m_IsLoop = 0;
	pStatus->m_AniBegin = ani_info->m_Duration / 2;
	pStatus->m_AniEnd = ani_info->m_Duration / 2 - (ani_info->m_Duration / 2 * _iAmplitude / 100);
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = "ANIMATE0";

	pStatus->m_TimeEnd = pStatus->m_TimeBegin + (long) (abs(pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio);

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP1_A_Status_Ani0B(WP1_A_Status *_this, IGU32 _GameTime, int _iAmplitude, int _iTimes)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = 0L;
	AniInfo *ani_info = CNamedObjArray_Get(WP1_A.m_AniInfo, 0);

	//找到最後一個狀態
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus == NULL)
		return;

	TimeBegin = pStatus->m_TimeEnd;

	pStatus = WP1_A_Status_Alloc();

	if(pStatus == NULL)return;

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_LOOP_0;
	pStatus->m_IsLoop = 1;
	pStatus->m_AniBegin = ani_info->m_Duration / 2 - (ani_info->m_Duration / 2 * _iAmplitude / 100);
	pStatus->m_AniEnd = ani_info->m_Duration / 2 + (ani_info->m_Duration / 2 * _iAmplitude / 100);
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = "ANIMATE0";
	pStatus->m_IsBackward = 1;

	//要來回所以要 * 2
	pStatus->m_TimeEnd = pStatus->m_TimeBegin + (long) (abs(pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio * 2 * _iTimes);

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP1_A_Status_Ani0C(WP1_A_Status *_this, IGU32 _GameTime, int _iAmplitude)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = _GameTime;
	AniInfo *ani_info = CNamedObjArray_Get(WP1_A.m_AniInfo, 0);

	//pStatus = WP1_A_Status_CurrentStatus(_this, _GameTime);
	//應該要找最後一個 Status, 而不能找 Current Status
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WP1_A_Status_Alloc();

	if(pStatus == NULL)return;

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_ANIM_01;
	pStatus->m_IsLoop = 0;
	pStatus->m_AniBegin = ani_info->m_Duration / 2 - (ani_info->m_Duration / 2 * _iAmplitude / 100);
	pStatus->m_AniEnd = ani_info->m_Duration / 2;
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = "ANIMATE0";

	pStatus->m_TimeEnd = pStatus->m_TimeBegin + (long) ((pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio);

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP1_A_Status_Loop1(WP1_A_Status *_this, IGU32 _GameTime, int _iAmplitude)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = _GameTime;
	AniInfo *ani_info = CNamedObjArray_Get(WP1_A.m_AniInfo, 2);

	//pStatus = WP1_A_Status_CurrentStatus(_this, _GameTime);
	//應該要找最後一個 Status, 而不能找 Current Status
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WP1_A_Status_Alloc();

	if(pStatus == NULL)return;

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_TimeEnd   = -1;
	pStatus->m_EventType = WP_ANIM_02;
	pStatus->m_IsLoop = 1;
	//pStatus->m_AniBegin = 0;
	pStatus->m_AniBegin = WP1_A_Status_Leaf_Position();
	pStatus->m_AniEnd = pStatus->m_AniBegin + ani_info->m_Duration / 50 * _iAmplitude / 100;
	pStatus->m_AniRatio = (float) (5 * 100 / _iAmplitude);
	pStatus->m_AniName = "ANIMATE1";
	pStatus->m_IsBackward = 1;

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP1_A_Status_Ani1(WP1_A_Status *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = _GameTime;
	AniInfo *ani_info = CNamedObjArray_Get(WP1_A.m_AniInfo, 2);

	//pStatus = WP1_A_Status_CurrentStatus(_this, _GameTime);
	//應該要找最後一個 Status, 而不能找 Current Status
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WP1_A_Status_Alloc();

	if(pStatus == NULL)return;

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_ANIM_01;
	pStatus->m_IsLoop = 0;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = ani_info->m_Duration;
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = "ANIMATE1";

	pStatus->m_TimeEnd = pStatus->m_TimeBegin + (long) ((pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio);

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP1_A_Status_Ani1A(WP1_A_Status *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = _GameTime;
	AniInfo *ani_info = CNamedObjArray_Get(WP1_A.m_AniInfo, 2);

	//pStatus = WP1_A_Status_CurrentStatus(_this, _GameTime);
	//應該要找最後一個 Status, 而不能找 Current Status
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WP1_A_Status_Alloc();

	if(pStatus == NULL) return;

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_ANIM_01;
	pStatus->m_IsLoop = 0;
	pStatus->m_AniBegin = WP1_A_Status_Leaf_Position();
	pStatus->m_AniEnd = ani_info->m_Duration;
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = "ANIMATE1";

	pStatus->m_TimeEnd = pStatus->m_TimeBegin + (long) ((pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio);

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP1_A_Status_Ani1B(WP1_A_Status *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = _GameTime;
	AniInfo *ani_info = CNamedObjArray_Get(WP1_A.m_AniInfo, 2);

	//pStatus = WP1_A_Status_CurrentStatus(_this, _GameTime);
	//應該要找最後一個 Status, 而不能找 Current Status
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WP1_A_Status_Alloc();

	if(pStatus == NULL) return;

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_ANIM_01;
	pStatus->m_IsLoop = 0;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = WP1_A_Status_Leaf_Position();
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = "ANIMATE1";

	pStatus->m_TimeEnd = pStatus->m_TimeBegin + (long) ((pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio);

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP1_A_Status_Ani2(WP1_A_Status *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = _GameTime;
	AniInfo *ani_info = CNamedObjArray_Get(WP1_A.m_AniInfo, 2);

	//pStatus = WP1_A_Status_CurrentStatus(_this, _GameTime);
	//應該要找最後一個 Status, 而不能找 Current Status
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WP1_A_Status_Alloc();

	if(pStatus == NULL)return;

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_ANIM_02;
	pStatus->m_IsLoop = 0;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = ani_info->m_Duration;
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = "ANIMATE2";

	pStatus->m_TimeEnd = pStatus->m_TimeBegin + (long) ((pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio);

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP1_A_Status_Update(WP1_A_Status *_this, IGU32 _Time)
{
	NodeAniStatus *pStatus = NULL;
	long iAniBias, iAniTime, iAniTime2;
	int iTimes = 0;
	//static int debug_time = 0;
	if(_this == NULL || _Time == NULL) return;

	pStatus = WP1_A_Status_CurrentStatus(_this, _Time);
	if(pStatus == NULL) return;

	if (strcmp(_this->m_Name, "stemFlowerA") == 0)
		iTimes = iTimes;

	if (strcmp(_this->m_Name, "LeafA1") == 0)
		iTimes = iTimes;

	if (strcmp(_this->m_Name, "root") == 0)
		iTimes = iTimes;

	if (pStatus != NULL)
	{
		if (pStatus->m_IsLoop)
		{
			iAniBias = (long) (((_Time - pStatus->m_TimeBegin) % (int) ((pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio)) / pStatus->m_AniRatio);

			iAniTime = pStatus->m_AniBegin + iAniBias;

			if (pStatus->m_IsBackward)
			{
				iTimes = (int) ((_Time - pStatus->m_TimeBegin) / ((pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio));
				iTimes = iTimes % 2;
				if (iTimes == 1)
				{
					iAniTime2 = pStatus->m_AniEnd - iAniBias;
					//if (abs(iAniTime2 - debug_time) > 100)
					//	iTimes = iTimes;
					iAniTime = iAniTime2;
				}
			}

			//if (abs(iAniTime - debug_time) > 100)
			//	iTimes = iTimes;
		}
		else
		{
			iAniTime = (long) ((_Time - pStatus->m_TimeBegin) / pStatus->m_AniRatio);
			if (pStatus->m_AniBegin < pStatus->m_AniEnd)
				iAniTime = pStatus->m_AniBegin + iAniTime;
			else
				iAniTime = pStatus->m_AniBegin - iAniTime;
		}

		V3Retained_UpdateNode(_this->m_Node, pStatus->m_AniName, iAniTime);
		pStatus->m_AniCurrent = iAniTime;

		if (strcmp(_this->m_Name, "root") == 0)
			iTimes = iTimes;

		if (strcmp(_this->m_Name, "LeafA1") == 0)
			iTimes = iTimes;

		if (strcmp(_this->m_Name, "stemFlowerA") == 0)
			iTimes = iTimes;
	}
}

#ifdef __cplusplus
}
#endif // __cplusplus

