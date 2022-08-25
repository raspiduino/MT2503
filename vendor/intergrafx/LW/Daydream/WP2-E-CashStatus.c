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
#include "WP2-E-GameApp.h"
#include "WP2-E-CashStatus.h"
#include "CUtils.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus


void WP2_E_CashStatus_InitArrayPool(void)
{
	if(WP2_E.pStatusArrayPool == NULL) WP2_E.pStatusArrayPool = CNew(sizeof(CArrayPool));
	if(WP2_E.pStatusArray == NULL) WP2_E.pStatusArray = CNew(sizeof(NodeAniStatus) * MAX_ARRAY_POOL);
	CArrayPool_Init(WP2_E.pStatusArrayPool, (void *) WP2_E.pStatusArray, sizeof(NodeAniStatus) * MAX_ARRAY_POOL, sizeof(NodeAniStatus));
}

NodeAniStatus *WP2_E_CashStatus_Alloc(void)
{
	return (NodeAniStatus *) CArrayPool_Alloc(WP2_E.pStatusArrayPool);
}

void WP2_E_CashStatus_Free(NodeAniStatus *_this)
{
	CArrayPool_Free(WP2_E.pStatusArrayPool, (void *) _this);
}

WP2_E_CashStatus *WP2_E_CashStatus_New(IGNode *_pNode, const char *_Name, const char *_AniName)
{
	WP2_E_CashStatus *self = NULL;
	
	if (WP2_E.pStatusArrayPool == NULL)
	{
		WP2_E_CashStatus_InitArrayPool();
	}

	self = (WP2_E_CashStatus *) CNew(sizeof(WP2_E_CashStatus));
	CStrNCpy(self->m_Name, _Name, DEFAULT_NAME_SIZE);
	CStrNCpy(self->m_AniName, _AniName, DEFAULT_NAME_SIZE);
	self->m_Status = CQueue_New(DEFAULT_QUEUE_SIZE);
	self->m_Node = _pNode;

	return self;
}

void WP2_E_CashStatus_Del(WP2_E_CashStatus *_this)
{
	if(_this != NULL)
	{
		CQueue_Del(_this->m_Status);
		_this->m_Status = 0;
		CDel(_this);
	}
}

NodeAniStatus *WP2_E_CashStatus_CurrentStatus(WP2_E_CashStatus *_this, IGU32 _Time)
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
				WP2_E_CashStatus_Free(pPop);
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

void WP2_E_CashStatus_EventPathFall(WP2_E_CashStatus *_this, IGU32 _GameTime, IGNode *_path)
{
	NodeAniStatus *pStatus = NULL;

	//找到最後一個狀態
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}

	WP2_E_CashStatus_PathFall(_this, _GameTime, _path);
}

void WP2_E_CashStatus_EventAni(WP2_E_CashStatus *_this, IGU32 _GameTime, int _iAni)
{
	NodeAniStatus *pStatus = NULL;

	//找到最後一個狀態
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}

	WP2_E_CashStatus_Ani(_this, _GameTime, _iAni);
	WP2_E.m_CurrentAni = _iAni;
}

void WP2_E_CashStatus_PathFall(WP2_E_CashStatus *_this, IGU32 _GameTime, IGNode *_path)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = _GameTime;
	AniInfo *ani_info = CNamedObjArray_Get(WP2_E.m_AniInfo, 5);
	AniInfo *path_ani_info = CNamedObjArray_Get(WP2_E.m_AniInfo, 0);

	//pStatus = WPFishStatus_CurrentStatus(_this, _GameTime);
	//應該要找最後一個 Status, 而不能找 Current Status
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WP2_E_CashStatus_Alloc();

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_ANIM_01;
	pStatus->m_IsLoop = 1;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = ani_info->m_Duration;
	pStatus->m_AniRatio = 5;
	pStatus->m_AniName = "ANIMATE5";

	pStatus->m_TimeEnd = TimeBegin + path_ani_info->m_Duration;

	pStatus->m_PathNode = _path;
	pStatus->m_PathAniName = "ANIMATE0";
	pStatus->m_PathAniBegin = 3000;
	pStatus->m_PathAniEnd = path_ani_info->m_Duration;

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP2_E_CashStatus_Ani(WP2_E_CashStatus *_this, IGU32 _GameTime, int _iAni)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = _GameTime;
	AniInfo *ani_info = (AniInfo *) CNamedObjArray_Get(WP2_E.m_AniInfo, _iAni);

	//pStatus = WP2_E_CashStatus_CurrentStatus(_this, _GameTime);
	//應該要找最後一個 Status, 而不能找 Current Status
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WP2_E_CashStatus_Alloc();
	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_ANIM_02;
	pStatus->m_IsLoop = 0;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = ani_info->m_Duration;
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = CNamedObjArray_GetName(WP2_E.m_AniInfo, _iAni);

	pStatus->m_TimeEnd = (long)(pStatus->m_TimeBegin + (pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio);

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}

void WP2_E_CashStatus_Update(WP2_E_CashStatus *_this, IGU32 _Time)
{
	IGErr err = IGERR_NONE;
	NodeAniStatus *pStatus = NULL;
	long iAniBias, iAniTime, iAniTime2;
	int iTimes = 0;
	//static int debug_time = 0;
	static igreal pos2[3];
	igreal Position[3];//, Rotation[4];
	int cn;

	// Update the animation.

	if(_this == NULL)return;
	pStatus = WP2_E_CashStatus_CurrentStatus(_this, _Time);
	//if(pStatus == NULL)return;
	if (pStatus == NULL || pStatus->m_TimeBegin > (long)_Time)
	{
		//沒有在動的物件或是時間還沒到的鈔票要先移到外面
		IGNode_getPosition(V3Retained_GetMem(), _this->m_Node, Position, &err);
		Position[0] = (igreal) (IG_ONE * 0.9);
		Position[1] = 0;
		Position[2] = 0;
		IGNode_setPosition(V3Retained_GetMem(), _this->m_Node, Position, &err);
		return;
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

	if (pStatus != NULL)
	{
		if (pStatus->m_IsLoop)
		{
			iAniBias = (long)(((_Time - pStatus->m_TimeBegin) % (int) ((pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio)) / pStatus->m_AniRatio);

			iAniTime = pStatus->m_AniBegin + iAniBias;

			if (pStatus->m_IsBackward)
			{
				iTimes = (int)((_Time - pStatus->m_TimeBegin) / ((pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio));
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
			iAniTime = (long)((_Time - pStatus->m_TimeBegin) / pStatus->m_AniRatio);
			if (pStatus->m_TimeBegin > pStatus->m_TimeEnd)
				iAniTime = pStatus->m_AniEnd - iAniTime;
			else
				iAniTime = pStatus->m_AniBegin + iAniTime;
		}

		V3Retained_UpdateNode(_this->m_Node, pStatus->m_AniName, iAniTime);
		
		iAniBias = _Time - pStatus->m_TimeBegin;
		iAniTime = pStatus->m_PathAniBegin + iAniBias;
		if (pStatus->m_PathNode != NULL)
		{
			float Pos[3];//, Pos2[3];
			V3Retained_GetPathPosition(pStatus->m_PathNode, pStatus->m_PathAniName, iAniTime, Pos);
			IGNode_getPosition(V3Retained_GetMem(), _this->m_Node, pos2, &err);
			for (cn = 0; cn < 12; cn = cn + 1)
			{
				IGNode *pPathNode = pStatus->m_PathNode;
				_this->m_Node->m_oriMat[cn] = pPathNode->m_oriMat[cn];
			}

			Position[0] = (igreal) (Pos[0] * IG_ONE);
			Position[1] = (igreal) (Pos[1] * IG_ONE);
			Position[2] = (igreal) (Pos[2] * IG_ONE);
			IGNode_setPosition(V3Retained_GetMem(), _this->m_Node, Position, &err);
			//IGNode_getPosition(V3Retained_GetMem(), WP2_E.m_OBJ[0]->m_Node, pos, &err);
			//IGNode_setPosition(V3Retained_GetMem(), _this->m_Node, pos, &err);
		}
		else
		{
			Position[0] = (igreal)((pStatus->m_Position[0] + pStatus->m_PositionV[0] * iAniBias) * IG_ONE);
			Position[1] = (igreal)((pStatus->m_Position[1] + pStatus->m_PositionV[1] * iAniBias) * IG_ONE);
			Position[2] = (igreal)((pStatus->m_Position[2] + pStatus->m_PositionV[2] * iAniBias) * IG_ONE);
			if (!(pStatus->m_PositionV[0] == 0 && pStatus->m_PositionV[1] == 0 && pStatus->m_PositionV[2] == 0))
				IGNode_setPosition(V3Retained_GetMem(), _this->m_Node, Position, &err);
		
			if (pStatus->m_PositionV[0] > 0)
				IGNode_rotateZ(V3Retained_GetMem(), _this->m_Node, IG_PI, &err);
		}

		IGNode_getPosition(V3Retained_GetMem(), _this->m_Node, Position, &err);
		_this->m_px = Position[0] / (float) IG_ONE;
		_this->m_py = Position[1] / (float) IG_ONE;
		_this->m_pz = Position[2] / (float) IG_ONE;
		//Position[0] = IG_ONE / 2;
		//IGNode_setPosition(V3Retained_GetMem(), _this->m_Node, Position, &err);

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

