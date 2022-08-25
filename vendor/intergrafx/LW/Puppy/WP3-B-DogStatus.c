//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3-B
// File        : WP3-B-DogStatus.c
// Description : C 語言 3D 物件狀態
// Author      : Ray
// Create      : 2010-12-01
// Update      : 2011-02-15
//==============================================================================

#include "V3Retained.h"
#include "IGMathUtil.h"
#include "WP3-B-GameApp.h"
#include "WP3-B-DogStatus.h"
#include "CUtils.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

void WP3_B_DogStatus_InitArrayPool(void)
{
	if(WP3_B.pStatusArrayPool == NULL) WP3_B.pStatusArrayPool = CNew(sizeof(CArrayPool));
	if(WP3_B.pStatusArray == NULL) WP3_B.pStatusArray = CNew(sizeof(NodeAniStatus) * MAX_ARRAY_POOL);
	CArrayPool_Init(WP3_B.pStatusArrayPool, (void *) WP3_B.pStatusArray, sizeof(NodeAniStatus) * MAX_ARRAY_POOL, sizeof(NodeAniStatus));
}

NodeAniStatus *WP3_B_DogStatus_Alloc(void)
{
	return (NodeAniStatus *) CArrayPool_Alloc(WP3_B.pStatusArrayPool);
}

void WP3_B_DogStatus_Free(NodeAniStatus *_this)
{
	CArrayPool_Free(WP3_B.pStatusArrayPool, (void *) _this);
}

WP3_B_DogStatus *WP3_B_DogStatus_New(IGNode *_pNode, const char *_Name, const char *_AniName)
{
	WP3_B_DogStatus *self = NULL;
	
	if (WP3_B.pStatusArrayPool == NULL)
	{
		WP3_B_DogStatus_InitArrayPool();
	}

	self = (WP3_B_DogStatus *) CNew(sizeof(WP3_B_DogStatus));
	CStrNCpy(self->m_Name, _Name, DEFAULT_NAME_SIZE);
	CStrNCpy(self->m_AniName, _AniName, DEFAULT_NAME_SIZE);
	self->m_Status = CQueue_New(DEFAULT_QUEUE_SIZE);
	self->m_Node = _pNode;

	return self;
}

void WP3_B_DogStatus_Del(WP3_B_DogStatus *_this)
{
	if(_this != NULL)
	{
		CQueue_Del(_this->m_Status);
		_this->m_Status = 0;
		CDel(_this);
	}
}

NodeAniStatus *WP3_B_DogStatus_CurrentStatus(WP3_B_DogStatus *_this, IGU32 _Time)
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
				WP3_B_DogStatus_Free(pPop);
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

void WP3_B_DogStatus_EventLoop0(WP3_B_DogStatus *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;

	if (WP3_B.m_CurrentLoop == 0)
		return;

	//找到最後一個狀態
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}

	WP3_B_DogStatus_Loop0(_this, _GameTime);
	WP3_B.m_CurrentLoop = 0;
}

void WP3_B_DogStatus_EventAni(WP3_B_DogStatus *_this, IGU32 _GameTime, int _iAni)
{
	NodeAniStatus *pStatus = NULL;

	//找到最後一個狀態
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}

	WP3_B_DogStatus_Ani(_this, _GameTime, _iAni);

	WP3_B_DogStatus_Loop0(_this, _GameTime);
	WP3_B.m_CurrentAni = _iAni;
}

void WP3_B_DogStatus_Loop0(WP3_B_DogStatus *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = 0L;
	int iAni = 10;
	AniInfo *ani_info = (AniInfo *) CNamedObjArray_Get(WP3_B.m_AniInfo, iAni);

	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus == NULL)
	{
		TimeBegin = _GameTime;
	}
	else
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WP3_B_DogStatus_Alloc();

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_LOOP_0;
	pStatus->m_IsLoop = 1;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = ani_info->m_Duration / 100;
	pStatus->m_TimeEnd = -1;
	pStatus->m_AniRatio = 10;
	pStatus->m_AniName = CNamedObjArray_GetName(WP3_B.m_AniInfo, iAni);
	pStatus->m_IsBackward = 1;

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}


void WP3_B_DogStatus_Ani(WP3_B_DogStatus *_this, IGU32 _GameTime, int _iAni)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = _GameTime;
	AniInfo *ani_info = (AniInfo *) CNamedObjArray_Get(WP3_B.m_AniInfo, _iAni);

	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WP3_B_DogStatus_Alloc();
	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_ANIM_02;
	pStatus->m_IsLoop = 0;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = ani_info->m_Duration;
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = CNamedObjArray_GetName(WP3_B.m_AniInfo, _iAni);

	pStatus->m_TimeEnd = pStatus->m_TimeBegin + (long) ((pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio);

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP3_B_DogStatus_Update(WP3_B_DogStatus *_this, IGU32 _Time)
{
	NodeAniStatus *pStatus = NULL;
	long iAniBias, iAniTime, iAniTime2;
	int cn;
	int iTimes = 0;

	if(_this == NULL)return;
	pStatus = WP3_B_DogStatus_CurrentStatus(_this, _Time);
	if(pStatus == NULL)return;
	if (pStatus != NULL)
	{
		if (pStatus->m_IsLoop)
		{
			iAniBias = (long) (((_Time - pStatus->m_TimeBegin) % (int) ((pStatus->m_AniEnd - pStatus->m_AniBegin) * 10)) / 10);

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
			if (pStatus->m_TimeBegin > pStatus->m_TimeEnd)
				iAniTime = pStatus->m_AniEnd - iAniTime;
			else
				iAniTime = pStatus->m_AniBegin + iAniTime;
		}

		V3Retained_UpdateNode(_this->m_Node, pStatus->m_AniName, iAniTime);
		

		//debug_time = iAniTime;
	}
	for(cn = 0 ; cn <= 15 ; cn = cn + 1 )
	{
		if(strcmp(pStatus->m_AniName,CNamedObjArray_GetName(WP3_B.m_AniInfo, cn)) == 0)
		{
			WP3_B.m_nowani = cn;
		}
	}
}

#ifdef __cplusplus
}
#endif // __cplusplus

