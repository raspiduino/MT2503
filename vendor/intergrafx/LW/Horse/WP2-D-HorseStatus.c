//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP2-D
// File        : WP2-D-HorseStatus.c
// Description : も诀κ翤瓜ガ -- ン篈
// Author      : Ray
// Create      : 2010-11-02
// Update      : 2011-02-15
//==============================================================================

#include "V3Retained.h"
#include "IGMathUtil.h"
#include "WP2-D-GameApp.h"
#include "WP2-D-HorseStatus.h"
#include "CUtils.h"
#include "math.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

void WP2_D_HorseStatus_InitArrayPool(void)
{
	if(WP2_D.pStatusArrayPool == NULL) WP2_D.pStatusArrayPool = CNew(sizeof(CArrayPool));
	if(WP2_D.pStatusArray == NULL) WP2_D.pStatusArray = CNew(sizeof(NodeAniStatus) * MAX_ARRAY_POOL);
	CArrayPool_Init(WP2_D.pStatusArrayPool, (void *) WP2_D.pStatusArray, sizeof(NodeAniStatus) * MAX_ARRAY_POOL, sizeof(NodeAniStatus));
}

NodeAniStatus *WP2_D_HorseStatus_Alloc(void)
{

	if(WP2_D.pStatusArrayPool->m_Used > 800)
	{
			WP2_D_HorseStatus_InitArrayPool();
			WP2_D.m_OBJ[0] = WP2_D.horse01status;
			WP2_D.m_OBJ[1] = WP2_D.horse02status;
			WP2_D.m_OBJ[2] = WP2_D.horse03status;
			WP2_D.m_OBJ[3] = WP2_D.horse04status;
			WP2_D.m_OBJ[4] = WP2_D.horse05status;
			WP2_D.m_OBJ[5] = WP2_D.birdstatus;
			WP2_D.m_OBJ[6] = WP2_D.wavestatus;
	}
	//WP2_D_AddDebugMessage("%d\n",StatusArrayPool.m_Used,0L,0L,0L);
	return (NodeAniStatus *) CArrayPool_Alloc(WP2_D.pStatusArrayPool);
}

void WP2_D_HorseStatus_Free(NodeAniStatus *_this)
{
	CArrayPool_Free(WP2_D.pStatusArrayPool, (void *) _this);
}

WP2_D_HorseStatus *WP2_D_HorseStatus_New(IGNode *_pNode, const char *_Name, const char *_AniName)
{
	WP2_D_HorseStatus *self = NULL;

	if (WP2_D.pStatusArrayPool == NULL)
	{
		WP2_D_HorseStatus_InitArrayPool();
	}
	self = (WP2_D_HorseStatus *) CNew(sizeof(WP2_D_HorseStatus));
	CStrNCpy(self->m_Name, _Name, DEFAULT_NAME_SIZE);
	CStrNCpy(self->m_AniName, _AniName, DEFAULT_NAME_SIZE);
	self->m_Status = CQueue_New(DEFAULT_QUEUE_SIZE);
	self->m_Node = _pNode;
	WP2_D_HorseStatus_ClearPath(self);
	return self;
}

void WP2_D_HorseStatus_Del(WP2_D_HorseStatus *_this)
{
	if(_this != NULL)
	{
		CQueue_Del(_this->m_Status);
		_this->m_Status = 0;
		CDel(_this);
	}
}

NodeAniStatus *WP2_D_HorseStatus_CurrentStatus(WP2_D_HorseStatus *_this, IGU32 _Time)
{
	NodeAniStatus *pStatus = NULL;
	NodeAniStatus *pPop = NULL;
	while (1)
	{
		pStatus = NodeAniStatusQueue_Tail(_this->m_Status);
		if (pStatus != NULL)
		{
			//RAY::2010-12-17 硂娩璶耞琌ぃ琌タ Loop, 玥 Loop 穦砆奔, ㄤ┮Τガ硂娩常璶猔種
			if (pStatus->m_TimeEnd >= 0 && pStatus->m_TimeEnd < (long) _Time)
			{
				pPop = NodeAniStatusQueue_Pop(_this->m_Status);
				WP2_D_HorseStatus_Free(pPop);
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

int WP2_D_HorseStatus_IsLoop(WP2_D_HorseStatus *_this, IGU32 _Time)
{
	NodeAniStatus *pStatus = NULL;
	int IsLoop = 0;

	pStatus = WP2_D_HorseStatus_CurrentStatus(_this, _Time);
	if (pStatus != NULL)
	{
		IsLoop = pStatus->m_IsLoop;
	}
	return IsLoop;
}

void WP2_D_HorseStatus_ClearPath(WP2_D_HorseStatus *_this)
{
	_this->m_Path = -1;
	_this->m_PathNode = NULL;
	_this->m_PathAniName = NULL;
	_this->m_bPathPause = 0;
	_this->m_PathAniTime = 0;
	_this->m_PathDuration = 0;
}
void WP2_D_HorseStatus_SetBirdPath(WP2_D_HorseStatus *_this)
{
	AniInfo *ani_info;
	int iPath = -1;

	iPath = 8;
	_this->m_Path = iPath;
	_this->m_PathNode = WP2_D.m_Path[_this->m_Path];
	_this->m_PathAniName = "ANIMATE21";
	_this->m_bPathPause = 0;
	_this->m_PathAniTime = 0;
	CQueue_Clear(_this->m_Status);
	ani_info = CNamedObjArray_Get(WP2_D.m_AniInfo, 20);
	
	_this->m_PathDuration = (ani_info->m_Duration );
}

void WP2_D_HorseStatus_SetPath(WP2_D_HorseStatus *_this)
{
	AniInfo *ani_info;
	int iPath = -1;
	int iHit = 0;
	int cn;

	do
	{
		iHit = 0;
		
		iPath = RandomEvent_Random(4, 7);
		
		if(	WP2_D.m_getrun > 0)
		{
			iPath = RandomEvent_Random(0,7);
			WP2_D.m_getrun = 0 ;
		}

		for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
		{
			if (WP2_D.m_OBJ[cn] != _this)
			{
				if (WP2_D.m_OBJ[cn]->m_Path == iPath)
				{
					iHit = 1;
					break;
				}
			}
		}
	} while(iHit == 1);

	_this->m_Path = iPath;
	_this->m_PathNode = WP2_D.m_Path[_this->m_Path];
	_this->m_PathAniName = WP2_D_GetPathAniName(_this->m_Path);
	_this->m_bPathPause = 0;
	_this->m_PathAniTime = 0;
	CQueue_Clear(_this->m_Status);
	ani_info = CNamedObjArray_Get(WP2_D.m_AniInfo, WP2_D_GetPathAniNumber(_this->m_Path));
	
	_this->m_PathDuration = (ani_info->m_Duration);
}

//繷

void WP2_D_HorseStatus_EventEat(WP2_D_HorseStatus *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;
	NodeAniStatus *kStatus = NULL;
	NodeAniStatus *mStatus = NULL;
	int iEatAni, iEatTimes;

	//т程篈

   	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	
	if (pStatus != NULL)
	{
		NodeAniStatus_CutLoop(pStatus, _GameTime);
	}
	kStatus = NodeAniStatusQueue_Head(WP2_D.m_OBJ[4]->m_Status);
	if (kStatus != NULL)
	{
		NodeAniStatus_CutLoop(kStatus, _GameTime);
	}
	mStatus = NodeAniStatusQueue_Head(WP2_D.m_OBJ[6]->m_Status);
	if (mStatus != NULL)
	{
		NodeAniStatus_CutLoop(mStatus, _GameTime);
	}

	iEatAni = RandomEvent_Random(1, 2) * 2;
	iEatTimes = RandomEvent_Random(1, 5);
	WP2_D_HorseStatus_Ani(_this, _GameTime, 1);
	WP2_D_HorseStatus_Ani(WP2_D.m_OBJ[4], _GameTime, 1);
	WP2_D_HorseStatus_Ani(WP2_D.m_OBJ[6], _GameTime, 1);
	WP2_D_HorseStatus_Eat(_this, _GameTime, iEatAni, iEatTimes);
	WP2_D_HorseStatus_Eat(WP2_D.m_OBJ[4], _GameTime, iEatAni, iEatTimes);
	WP2_D_HorseStatus_Eat(WP2_D.m_OBJ[6], _GameTime, iEatAni, iEatTimes);
	WP2_D_HorseStatus_Ani(_this, _GameTime, 3);
	WP2_D_HorseStatus_Ani(WP2_D.m_OBJ[4], _GameTime, 3);
	WP2_D_HorseStatus_Ani(WP2_D.m_OBJ[6], _GameTime, 3);
	iEatTimes = RandomEvent_Random(1, 3);
	WP2_D_HorseStatus_Eat(_this, _GameTime, 0, iEatTimes);
	WP2_D_HorseStatus_Eat(WP2_D.m_OBJ[4], _GameTime, 0, iEatTimes);
	WP2_D_HorseStatus_Eat(WP2_D.m_OBJ[6], _GameTime, 0, iEatTimes);
	WP2_D_HorseStatus_Loop(_this, _GameTime, 0);
	WP2_D_HorseStatus_Loop(WP2_D.m_OBJ[4], _GameTime, 0);
	WP2_D_HorseStatus_Loop(WP2_D.m_OBJ[6], _GameTime, 0);
	V3Retained_GetPathPosition_i(_this->m_Node, "ANIMATE0", 0, _this->m_Position);
	V3Retained_GetPathPosition_i(WP2_D.m_OBJ[4]->m_Node, "ANIMATE0", 0, WP2_D.m_OBJ[4]->m_Position);
	V3Retained_GetPathPosition_i(WP2_D.m_OBJ[6]->m_Node, "ANIMATE0", 0, WP2_D.m_OBJ[6]->m_Position);
	_this->m_px = _this->m_Position[0] / (float) IG_ONE;
	_this->m_py = _this->m_Position[1] / (float) IG_ONE;
	_this->m_pz = _this->m_Position[2] / (float) IG_ONE;
	WP2_D.m_OBJ[4]->m_px = WP2_D.m_OBJ[4]->m_Position[0] / (float) IG_ONE;
	WP2_D.m_OBJ[4]->m_py = WP2_D.m_OBJ[4]->m_Position[1] / (float) IG_ONE;
	WP2_D.m_OBJ[4]->m_pz = WP2_D.m_OBJ[4]->m_Position[2] / (float) IG_ONE;
	WP2_D.m_OBJ[6]->m_px = WP2_D.m_OBJ[6]->m_Position[0] / (float) IG_ONE;
	WP2_D.m_OBJ[6]->m_py = WP2_D.m_OBJ[6]->m_Position[1] / (float) IG_ONE;
	WP2_D.m_OBJ[6]->m_pz = WP2_D.m_OBJ[6]->m_Position[2] / (float) IG_ONE;
}

void WP2_D_HorseStatus_BirdEventLoop(WP2_D_HorseStatus *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;

	//т程篈
   	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}
	WP2_D_HorseStatus_Loop(_this, _GameTime, 0);
}

void WP2_D_HorseStatus_EventLoop(WP2_D_HorseStatus *_this, IGU32 _GameTime, int _iAni)
{
	NodeAniStatus *pStatus = NULL;

	//т程篈
   	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}
	WP2_D_HorseStatus_Loop(_this, _GameTime, _iAni);
}

void WP2_D_HorseStatus_EventTouchStay(WP2_D_HorseStatus *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;
	NodeAniStatus *kStatus = NULL;
	NodeAniStatus *mStatus = NULL;
	//т程篈
   	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}
	CQueue_Clear(_this->m_Status);
	WP2_D_HorseStatus_Ani(_this, _GameTime, 10);
	WP2_D_HorseStatus_Loop(_this, _GameTime, 0);

   	kStatus = NodeAniStatusQueue_Head(WP2_D.m_OBJ[4]->m_Status);
	if (kStatus != NULL)
	{
		NodeAniStatus_TrimLoop(kStatus, _GameTime);
	}

	CQueue_Clear(WP2_D.m_OBJ[4]->m_Status);
	WP2_D_HorseStatus_Ani(WP2_D.m_OBJ[4], _GameTime, 10);
	WP2_D_HorseStatus_Loop(WP2_D.m_OBJ[4], _GameTime, 0);
   	mStatus = NodeAniStatusQueue_Head(WP2_D.m_OBJ[6]->m_Status);
	if (mStatus != NULL)
	{
		NodeAniStatus_TrimLoop(mStatus, _GameTime);
	}

	CQueue_Clear(WP2_D.m_OBJ[6]->m_Status);
	WP2_D_HorseStatus_Ani(WP2_D.m_OBJ[6], _GameTime, 10);
	WP2_D_HorseStatus_Loop(WP2_D.m_OBJ[6], _GameTime, 0);
}

void WP2_D_HorseStatus_EventTouchWalk(WP2_D_HorseStatus *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;

	//т程篈
   	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}
	CQueue_Clear(_this->m_Status);
	WP2_D_HorseStatus_Ani(_this, _GameTime, 10);
	WP2_D_HorseStatus_Loop(_this, _GameTime, WP2_D_GetHorseAniByPath(_this->m_Path));
}

void WP2_D_HorseStatus_Loop(WP2_D_HorseStatus *_this, IGU32 _GameTime, int _iAni)
{
	NodeAniStatus *pStatus = NULL;

	long TimeBegin = _GameTime;
	AniInfo *ani_info = CNamedObjArray_Get(WP2_D.m_AniInfo, _iAni);

	//pStatus = WPHorseStatus_CurrentStatus(_this, _GameTime);
	//莱赣璶т程 Status, τぃт Current Status

	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WP2_D_HorseStatus_Alloc();
	if(pStatus == NULL)
	{
		return;
	}
	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_ANIM_01;
	pStatus->m_IsLoop = 1;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = (ani_info->m_Duration / WP2_D.anispeed);
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = CNamedObjArray_GetName(WP2_D.m_AniInfo, _iAni);

	pStatus->m_TimeEnd = -1;

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP2_D_HorseStatus_Eat(WP2_D_HorseStatus *_this, IGU32 _GameTime, int _iAni, int _iTimes)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = _GameTime;
	AniInfo *ani_info = CNamedObjArray_Get(WP2_D.m_AniInfo, _iAni);

	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WP2_D_HorseStatus_Alloc();
	if(pStatus == NULL)return;

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_ANIM_01;
	pStatus->m_IsLoop = 0;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = (ani_info->m_Duration / WP2_D.anispeed);
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = CNamedObjArray_GetName(WP2_D.m_AniInfo, _iAni);

	pStatus->m_TimeEnd = pStatus->m_TimeBegin + (long) ((pStatus->m_AniEnd - pStatus->m_AniBegin) * (pStatus->m_AniRatio * WP2_D.anispeed ));

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP2_D_HorseStatus_Ani(WP2_D_HorseStatus *_this, IGU32 _GameTime, int _iAni)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = _GameTime;
	AniInfo *ani_info = CNamedObjArray_Get(WP2_D.m_AniInfo, _iAni);

	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WP2_D_HorseStatus_Alloc();
	if(pStatus == NULL)return;

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_ANIM_01;
	pStatus->m_IsLoop = 0;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = (ani_info->m_Duration / WP2_D.anispeed);
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = CNamedObjArray_GetName(WP2_D.m_AniInfo, _iAni);

	pStatus->m_TimeEnd = pStatus->m_TimeBegin + (long) ((pStatus->m_AniEnd - pStatus->m_AniBegin) * (pStatus->m_AniRatio * WP2_D.anispeed));

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}


void WP2_D_HorseStatus_Update(WP2_D_HorseStatus *_this, IGU32 _Time)
{
	IGErr err = IGERR_NONE;
	NodeAniStatus *pStatus = NULL;
	long iAniBias, iAniTime;
	int iTimes = 0;
	//static int debug_time = 0;
	igreal Position[3];
	
	if(_this == NULL)return;

	// Update the animation.

	pStatus = WP2_D_HorseStatus_CurrentStatus(_this, _Time);
	if(pStatus == NULL)return;
	if (pStatus == NULL)
	{
		IGNode_getPosition(V3Retained_GetMem(), _this->m_Node, Position, &err);
		Position[0] = (igreal) (IG_ONE * 0.9);
		Position[1] = 0;
		Position[2] = 0;
		IGNode_setPosition(V3Retained_GetMem(), _this->m_Node, Position, &err);
		return;
	}

	if (CStrCmp(pStatus->m_AniName, "ANIMATE10") == 0)
		{
			if(CStrCmp(_this->m_Node->m_name, WP2_D.m_OBJ[6]->m_Name) == 0)
			{	
				if(WP2_D.wave == 0)
				{
				Position[0] = 0;
				Position[1] = 0;
				Position[2] = -(igreal) (IG_ONE * 1);
				IGNode_setPosition(V3Retained_GetMem(), _this->m_Node, Position, &err);
				return;
				}
			}
		}

	if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[0]) == 0)
		iTimes = iTimes;
	if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[1]) == 0)
		iTimes = iTimes;
	if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[2]) == 0)
		iTimes = iTimes;
	if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[3]) == 0)
		iTimes = iTimes;
	if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[4]) == 0)
		iTimes = iTimes;
	if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[5]) == 0)
		iTimes = iTimes;
	if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[6]) == 0)
		iTimes = iTimes;


	if (pStatus != NULL)
	{
		if (pStatus->m_IsLoop)
		{
			iAniBias = (long) (((_Time - pStatus->m_TimeBegin) % (int) ((pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio)) / pStatus->m_AniRatio);

			iAniTime = pStatus->m_AniBegin + (iAniBias * WP2_D.anispeed);

			//if (abs(iAniTime - debug_time) > 100)
			//	iTimes = iTimes;
		}
		else
		{
			iAniTime = (long) ((_Time - pStatus->m_TimeBegin) / (pStatus->m_AniRatio / WP2_D.anispeed));
			if (pStatus->m_TimeBegin > pStatus->m_TimeEnd)
				iAniTime = pStatus->m_AniEnd - iAniTime;
			else
				iAniTime = pStatus->m_AniBegin + iAniTime;
		}

		V3Retained_UpdateNode(_this->m_Node, pStatus->m_AniName, iAniTime);
		pStatus->m_AniCurrent = iAniTime;



		if (CStrCmp(pStatus->m_AniName, "ANIMATE10") == 0)
			_this->m_bPathPause = 1;
		else
			_this->m_bPathPause = 0;

		if (_this->m_bPathPause == 1)
		{
			IGNode_setPosition(V3Retained_GetMem(), _this->m_Node, _this->m_Position, &err);
		}

		if (_this->m_Path == -1)
		{
			IGNode_setPosition(V3Retained_GetMem(), _this->m_Node, _this->m_Position, &err);
		}

		if (_this->m_Path >= 0 && _this->m_bPathPause == 0)
		{
			_this->m_PathAniTime = _this->m_PathAniTime + WP2_D.m_ElapsedTime / WP2_D.m_TimeFactor * WP2_D.anispeed;
			V3Retained_GetPathPosition_i(_this->m_PathNode, _this->m_PathAniName, _this->m_PathAniTime, _this->m_Position);
			IGNode_setPosition(V3Retained_GetMem(), _this->m_Node, _this->m_Position, &err);

			if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[0]) == 0)
				iTimes = iTimes;
		}

		IGNode_getPosition(V3Retained_GetMem(), _this->m_Node, Position, &err);
		{
		if(strcmp(_this->m_Name,WP_NameStruct.node_name_Obj[0]) == 0)
			WP2_D.horse01status = _this;
		if(strcmp(_this->m_Name,WP_NameStruct.node_name_Obj[1]) == 0)
			WP2_D.horse02status = _this;
		if(strcmp(_this->m_Name,WP_NameStruct.node_name_Obj[2]) == 0)
			WP2_D.horse03status = _this;
		if(strcmp(_this->m_Name,WP_NameStruct.node_name_Obj[3]) == 0)
			WP2_D.horse04status = _this;
		if(strcmp(_this->m_Name,WP_NameStruct.node_name_Obj[4]) == 0)
			WP2_D.horse05status = _this;
		if(strcmp(_this->m_Name,WP_NameStruct.node_name_Obj[5]) == 0)
			WP2_D.birdstatus = _this;
		if(strcmp(_this->m_Name,WP_NameStruct.node_name_Obj[6]) == 0)
			WP2_D.wavestatus = _this;		
		}
		_this->m_px = Position[0] / (float) IG_ONE;
		_this->m_py = Position[1] / (float) IG_ONE;
		_this->m_pz = Position[2] / (float) IG_ONE;

		if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[0]) == 0)
			iTimes = iTimes;
		if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[1]) == 0)
			iTimes = iTimes;
		if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[2]) == 0)
			iTimes = iTimes;
		if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[3]) == 0)
			iTimes = iTimes;
		if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[4]) == 0)
			iTimes = iTimes;

		//debug_time = iAniTime;
	}
}

#ifdef __cplusplus
}
#endif // __cplusplus