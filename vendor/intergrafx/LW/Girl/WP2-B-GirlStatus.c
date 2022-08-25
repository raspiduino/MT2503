//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP2-B-GirlStatus
// File        : WP2-B-GirlStatus.h
// Description : C 語言 3D 物件狀態
// Author      : Ray
// Create      : 2010-10-25
// Update      : 2011-02-15
//==============================================================================

#include "V3Retained.h"
#include "IGMathUtil.h"
#include "WP2-B-GameApp.h"
#include "WP2-B-GirlStatus.h"
#include "CUtils.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

void WP2_B_GirlStatus_InitArrayPool(void)
{
	if(WP2_B.pStatusArrayPool == NULL) WP2_B.pStatusArrayPool = CNew(sizeof(CArrayPool));
	if(WP2_B.pStatusArray == NULL) WP2_B.pStatusArray = CNew(sizeof(NodeAniStatus) * MAX_ARRAY_POOL);
	CArrayPool_Init(WP2_B.pStatusArrayPool, (void *) WP2_B.pStatusArray, sizeof(NodeAniStatus) * MAX_ARRAY_POOL, sizeof(NodeAniStatus));
}

NodeAniStatus *WP2_B_GirlStatus_Alloc(void)
{
	if(WP2_B.pStatusArrayPool->m_Used > 1000)WP2_B_GirlStatus_InitArrayPool();//避免Status的pool滿出來造成當機, edit by Odin
	return (NodeAniStatus *) CArrayPool_Alloc(WP2_B.pStatusArrayPool);
}

void WP2_B_GirlStatus_Free(NodeAniStatus *_this)
{
	CArrayPool_Free(WP2_B.pStatusArrayPool, (void *) _this);
}

WP2_B_GirlStatus *WP2_B_GirlStatus_New(IGNode *_pNode, const char *_Name, const char *_AniName)
{
	WP2_B_GirlStatus *self = NULL;

	if (WP2_B.pStatusArrayPool == NULL)
	{
		WP2_B_GirlStatus_InitArrayPool();
	}

	self = (WP2_B_GirlStatus *) CNew(sizeof(WP2_B_GirlStatus));
	CStrNCpy(self->m_Name, _Name, DEFAULT_NAME_SIZE);
	CStrNCpy(self->m_AniName, _AniName, DEFAULT_NAME_SIZE);
	self->m_Status = CQueue_New(DEFAULT_QUEUE_SIZE);
	self->m_Node = _pNode;

	return self;


}

void WP2_B_GirlStatus_EventHTouchMove(WP2_B_GirlStatus *_this, int _pixel)
{
	int maxDeg = WP2_B.iMaxDeg2, minDeg = WP2_B.iMinDeg2;
	
	if(WP2_B.isRecovering == 1 && (WP2_B.m_HDegree == WP2_B.iMaxDeg1 || WP2_B.m_HDegree == WP2_B.iMinDeg1)) WP2_B.isRecovering = 0;//結束自動補正
	WP2_B.m_HDegree = WP2_B.m_HDegree + (_pixel * WP2_B.m_DegreeInc);
	if (WP2_B.m_HDegree > maxDeg)WP2_B.m_HDegree = maxDeg;
	if (WP2_B.m_HDegree < minDeg)WP2_B.m_HDegree = minDeg;	
}


void WP2_B_GirlStatus_Del(WP2_B_GirlStatus *_this)
{
	if(_this != NULL)
	{
		CQueue_Del(_this->m_Status);
		_this->m_Status = 0;
		CDel(_this);
	}
}

NodeAniStatus *WP2_B_GirlStatus_CurrentStatus(WP2_B_GirlStatus *_this, IGU32 _Time)
{
	NodeAniStatus *pStatus = NULL;
	NodeAniStatus *pPop = NULL;

	while (1)
	{
		pStatus = NodeAniStatusQueue_Tail(_this->m_Status);
		if (pStatus != NULL)
		{
			if (pStatus->m_TimeEnd >= 0 && pStatus->m_TimeEnd < (long) _Time)
			{
				pPop = NodeAniStatusQueue_Pop(_this->m_Status);
				WP2_B_GirlStatus_Free(pPop);
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

void WP2_B_GirlStatus_EventLoop(WP2_B_GirlStatus *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;

	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_CutLoop(pStatus, _GameTime);
	}

	WP2_B_GirlStatus_Loop(_this, _GameTime);
}

void WP2_B_GirlStatus_EventAni(WP2_B_GirlStatus *_this, IGU32 _GameTime, int _iAni)
{
	NodeAniStatus *pStatus = NULL;

	pStatus = WP2_B_GirlStatus_CurrentStatus(_this, _GameTime);
	if (pStatus != NULL && pStatus->m_IsLoop != 1)
		return;

	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		CQueue_Clear(_this->m_Status);
	}

	WP2_B_GirlStatus_Ani(_this, _GameTime, _iAni);
	WP2_B_GirlStatus_Loop(_this, _GameTime);
	WP2_B.m_CurrentAni = _iAni;
}
void WP2_B_GirlStatus_Loop(WP2_B_GirlStatus *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = 0L;
	int iAni = 0 ;
	AniInfo *ani_info = (AniInfo *) CNamedObjArray_Get(WP2_B.m_AniInfo, iAni);

	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus == NULL)
	{
		TimeBegin = _GameTime;
	}
	else
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WP2_B_GirlStatus_Alloc();

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_LOOP_0;
	pStatus->m_IsLoop = 1;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = (ani_info->m_Duration / WP2_B.anispeed);
	pStatus->m_TimeEnd = -1;
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = CNamedObjArray_GetName(WP2_B.m_AniInfo, iAni);
	pStatus->m_IsBackward = 1;

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP2_B_GirlStatus_Ani(WP2_B_GirlStatus *_this, IGU32 _GameTime, int _iAni)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = _GameTime;
	AniInfo *ani_info = (AniInfo *) CNamedObjArray_Get(WP2_B.m_AniInfo, _iAni);


	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WP2_B_GirlStatus_Alloc();
	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_ANIM_02;
	pStatus->m_IsLoop = 0;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = (ani_info->m_Duration/WP2_B.anispeed);
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = CNamedObjArray_GetName(WP2_B.m_AniInfo, _iAni);

	pStatus->m_TimeEnd = pStatus->m_TimeBegin + (long) ((pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio);

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP2_B_GirlStatus_LoopDefault(WP2_B_GirlStatus *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = 0L;

	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus == NULL)
		TimeBegin = _GameTime;
	else
		TimeBegin = pStatus->m_TimeEnd;

	pStatus = WP2_B_GirlStatus_Alloc();

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_LOOP_DEFAULT;
	pStatus->m_IsLoop = 1;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = (3333 / WP2_B.anispeed);
	pStatus->m_TimeEnd = -1;
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = "ANIMATE0";
	pStatus->m_IsBackward = 0;

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP2_B_GirlStatus_Update(WP2_B_GirlStatus *_this, IGU32 _Time)
{
	IGErr err = IGERR_NONE;
	NodeAniStatus *pStatus = NULL;
	long iAniBias, iAniTime;
	int iTimes = 0;
	//static int debug_time = 0;

	if(_this == NULL)return;

	// Update the animation.
	if (CStrCmp(_this->m_Name, "root") == 0)
		iTimes = iTimes;

	pStatus = WP2_B_GirlStatus_CurrentStatus(_this, _Time);
	if(pStatus == NULL)return;

	if (pStatus != NULL)
	{
		if (pStatus->m_IsLoop)
		{
			iAniBias = (long) (((_Time - pStatus->m_TimeBegin) % (int) ((pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio)) / pStatus->m_AniRatio);

			iAniTime = pStatus->m_AniBegin + (iAniBias * WP2_B.anispeed);

			//if (abs(iAniTime - debug_time) > 100)
			//	iTimes = iTimes;

		}
		else
		{
			iAniTime = (long) ((_Time - pStatus->m_TimeBegin) / (pStatus->m_AniRatio / WP2_B.anispeed));
			if (pStatus->m_TimeBegin > pStatus->m_TimeEnd)
				iAniTime = pStatus->m_AniEnd - iAniTime;
			else
				iAniTime = pStatus->m_AniBegin + iAniTime;
		}
		WP2_B.rr = V3Retained_GetInstance();

		//檢查是否需要進行鏡頭自動校正, 且分辨是左校正或者右校正
		if(WP2_B.m_HDegree >= WP2_B.iMiddleDeg && WP2_B.m_HDegree >= WP2_B.iMaxDeg1 && WP2_B.isRecovering == 1)
			WP2_B_GirlStatus_EventHTouchMove(WP2_B.m_WP, -1);//左校正
		else if(WP2_B.m_HDegree <= WP2_B.iMiddleDeg && WP2_B.m_HDegree <= WP2_B.iMinDeg1 && WP2_B.isRecovering == 1)
			WP2_B_GirlStatus_EventHTouchMove(WP2_B.m_WP, 1);//右校正

		V3Retained_UpdateNode(_this->m_Node, pStatus->m_AniName, iAniTime);
		V3Retained_UpdateNode((IGNode*)WP2_B.rr->m_CameraControl, "ANIMATE0", 0);
		IGNode_rotateZ(V3Retained_GetMem(), (IGNode *) WP2_B.rr->m_CameraControl, WP2_B.m_HDegree, &err);
		IGNode_rotateX(V3Retained_GetMem(), (IGNode *) WP2_B.rr->m_CameraControl, WP2_B.m_VDegree, &err);

		//debug_time = iAniTime;
	}
}

#ifdef __cplusplus
}
#endif // __cplusplus

