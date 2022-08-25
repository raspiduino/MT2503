//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WPSample2
// File        : CWPStatus.h
// Description : C 語言 3D 物件狀態
// Author      : Ray
// Create      : 2010-11-02
// Update      : 2011-02-15
//==============================================================================

#include "V3Retained.h"
#include "IGMathUtil.h"
#include "WP3-D-GameApp.h"
#include "WP3-D-FishStatus.h"
#include "CUtils.h"
#include "math.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus



void WPFishStatus_InitArrayPool(void)
{
	if(WP3_D.pStatusArrayPool == NULL)WP3_D.pStatusArrayPool = CNew(sizeof(CArrayPool));
	if(WP3_D.pStatusArray == NULL)WP3_D.pStatusArray = CNew(sizeof(NodeAniStatus) * MAX_ARRAY_POOL);
	CArrayPool_Init(WP3_D.pStatusArrayPool, (void *) WP3_D.pStatusArray, sizeof(NodeAniStatus) * MAX_ARRAY_POOL, sizeof(NodeAniStatus));
}

NodeAniStatus *WPFishStatus_Alloc(void)
{

	if(WP3_D.memover == 1)
	{
						 int cn;
			 WPFishStatus_InitArrayPool();

			 for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
			 {
			 WPFishStatus_Del(WP3_D.m_OBJ[cn]);
			 { 
			 IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.node_name_Obj[cn]);
			WP3_D.m_OBJ[cn] = WPFishStatus_New(pNode, WP_NameStruct.node_name_Obj[cn], "ANIMATE0");
			 }
			 }
			 //WP3_D.m_OBJ[1] = WP3_D.fishstatus[0];
			 //WP3_D.m_OBJ[2] = WP3_D.fishstatus[1];
			 //WP3_D.m_OBJ[3] = WP3_D.fishstatus[2];
			 //WP3_D.m_OBJ[4] = WP3_D.fishstatus[3];
			 //WP3_D.m_Food[0] = WP3_D.food[0];
			 //WP3_D.m_Food[1] = WP3_D.food[1];
			 //WP3_D.m_Food[2] = WP3_D.food[2];
			 //WP3_D.m_Food[3] = WP3_D.food[3];
			 //WP3_D.m_allbubble = WP3_D.bubbleall;
			WP3_D.memover = 0;
	}
	return (NodeAniStatus *) CArrayPool_Alloc(WP3_D.pStatusArrayPool);
}

void WPFishStatus_Free(NodeAniStatus *_this)
{
	CArrayPool_Free(WP3_D.pStatusArrayPool, (void *) _this);
}

WPFishStatus *WPFishStatus_New(IGNode *_pNode, const char *_Name, const char *_AniName)
{
	WPFishStatus *self = NULL;

	if (WP3_D.pStatusArrayPool == NULL)
	{
		WPFishStatus_InitArrayPool();
	}

	self = (WPFishStatus *) CNew(sizeof(WPFishStatus));
	CStrNCpy(self->m_Name, _Name, DEFAULT_NAME_SIZE);
	CStrNCpy(self->m_AniName, _AniName, DEFAULT_NAME_SIZE);
	self->m_Status = CQueue_New(DEFAULT_QUEUE_SIZE);
	self->m_Node = _pNode;

	return self;
}

void WPFishStatus_Del(WPFishStatus *_this)
{
	if(_this != NULL)
	{
		CQueue_Del(_this->m_Status);
		_this->m_Status = 0;
		CDel(_this);
	}
}

NodeAniStatus *WPFishStatus_CurrentStatus(WPFishStatus *_this, IGU32 _Time)
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
				WPFishStatus_Free(pPop);
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

void WPFishStatus_EventPathSwim(WPFishStatus *_this, IGU32 _GameTime, IGNode *_path)
{
	NodeAniStatus *pStatus = NULL;

	//找到最後一個狀態
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}

	WPFishStatus_PathSwim(_this, _GameTime, _path);
}

void WPFishStatus_EventPathEat(WPFishStatus *_this, IGU32 _GameTime, IGNode *_path)
{
	NodeAniStatus *pStatus = NULL;

	//找到最後一個狀態
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);
	if (pStatus != NULL)
	{
		NodeAniStatus_TrimLoop(pStatus, _GameTime);
	}

	WPFishStatus_PathEat(_this, _GameTime, _path);
}

void WPFishStatus_PathSwim(WPFishStatus *_this, IGU32 _GameTime, IGNode *_path)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = _GameTime;
	AniInfo *ani_info = CNamedObjArray_Get(WP3_D.m_AniInfo, 0);
	AniInfo *path_ani_info = CNamedObjArray_Get(WP3_D.m_AniInfo, 1);

	//pStatus = WPFishStatus_CurrentStatus(_this, _GameTime);
	//應該要找最後一個 Status, 而不能找 Current Status
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WPFishStatus_Alloc();

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_ANIM_01;
	pStatus->m_IsLoop = 1;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = (ani_info->m_Duration / WP3_D.anispeed);
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = "ANIMATE0";

	pStatus->m_TimeEnd = TimeBegin + (path_ani_info->m_Duration/ WP3_D.anispeed);

	pStatus->m_PathNode = _path;
	pStatus->m_PathAniName = "ANIMATE1";
	pStatus->m_PathAniBegin = 0;
	pStatus->m_PathAniEnd = (path_ani_info->m_Duration / WP3_D.anispeed);

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}
void WPFishStatus_Bubble(WPFishStatus *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = _GameTime;
	AniInfo *ani_info = CNamedObjArray_Get(WP3_D.m_AniInfo, 0);
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = pStatus->m_TimeEnd;
	}
	pStatus = WPFishStatus_Alloc();

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_ANIM_01;
	pStatus->m_IsLoop = 0;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = (ani_info->m_Duration/ WP3_D.anispeed);
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = "ANIMATE0";

	pStatus->m_TimeEnd = TimeBegin + (ani_info->m_Duration/ WP3_D.anispeed);
	
	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}
void WPFishStatus_PathEat(WPFishStatus *_this, IGU32 _GameTime, IGNode *_path)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = _GameTime;
	AniInfo *ani_info = CNamedObjArray_Get(WP3_D.m_AniInfo, 0);
	AniInfo *path_ani_info = CNamedObjArray_Get(WP3_D.m_AniInfo, 2);

	//pStatus = WPFishStatus_CurrentStatus(_this, _GameTime);
	//應該要找最後一個 Status, 而不能找 Current Status
	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = pStatus->m_TimeEnd;
	}

	pStatus = WPFishStatus_Alloc();

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_ANIM_01;
	pStatus->m_IsLoop = 1;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = (ani_info->m_Duration/ WP3_D.anispeed);
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = "ANIMATE0";

	pStatus->m_TimeEnd = TimeBegin + (path_ani_info->m_Duration/ WP3_D.anispeed);

	pStatus->m_PathNode = _path;
	pStatus->m_PathAniName = "ANIMATE2";
	pStatus->m_PathAniBegin = 0;
	pStatus->m_PathAniEnd = (path_ani_info->m_Duration / WP3_D.anispeed);

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}


void WPFishStatus_FeedFood(WPFishStatus *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = _GameTime;
	AniInfo *ani_info = CNamedObjArray_Get(WP3_D.m_AniInfo, 2);

	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus != NULL)
	{
		TimeBegin = _GameTime;
	}

	pStatus = WPFishStatus_Alloc();

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_ANIM_01;
	pStatus->m_IsLoop = 0;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = (ani_info->m_Duration/ WP3_D.anispeed);
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = "ANIMATE2";
	pStatus->m_PathNode = NULL;

	pStatus->m_TimeEnd = pStatus->m_TimeBegin + (long) ((pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio)/ WP3_D.anispeed;

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}


void WPFishStatus_LoopDefault(WPFishStatus *_this, IGU32 _GameTime)
{
	NodeAniStatus *pStatus = NULL;
	long TimeBegin = 0L;

	pStatus = NodeAniStatusQueue_Head(_this->m_Status);

	if (pStatus == NULL)
		TimeBegin = _GameTime;
	else
		TimeBegin = pStatus->m_TimeEnd;

	pStatus = WPFishStatus_Alloc();

	pStatus->m_TimeBegin = TimeBegin;
	pStatus->m_EventType = WP_LOOP_DEFAULT;
	pStatus->m_IsLoop = 1;
	pStatus->m_AniBegin = 0;
	pStatus->m_AniEnd = ( 3333 / WP3_D.anispeed);
	pStatus->m_TimeEnd = -1;
	pStatus->m_AniRatio = 1;
	pStatus->m_AniName = "ANIMATE0";
	pStatus->m_IsBackward = 0;

	NodeAniStatusQueue_Push(_this->m_Status, pStatus);
}
int debug_time = 0;
int degree = 0, degree_inc = 10;
igreal pos[3], pos2[3], angle[4];

void WPFishStatus_Update(WPFishStatus *_this, IGU32 _Time)
{
	IGErr err = IGERR_NONE;
	NodeAniStatus *pStatus = NULL;
	long iAniBias, iAniTime, iAniTime2;
	int iTimes = 0;

	igreal Position[3];
	IGGameObject *pGameObj = NULL, *pGamePath = NULL;
	int cn;

	if(_this == NULL)return;

	pStatus = WPFishStatus_CurrentStatus(_this, _Time);
	
	if (pStatus == NULL)
	{
		//沒有在動的魚要先移到外面
		IGNode_getPosition(V3Retained_GetMem(), _this->m_Node, Position, &err);
		Position[0] = (igreal) (IG_ONE * 0.9);
		Position[1] = 0;
		Position[2] = 0;
		IGNode_setPosition(V3Retained_GetMem(), _this->m_Node, Position, &err);
		return;
	}
	if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[0]) == 0)
	{
		iTimes = iTimes;
			if(pStatus->m_IsLoop == 0)
	{
		pStatus->m_TimeBegin =  pStatus->m_TimeEnd;
	}
	}
	if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[1]) == 0)
	{
		iTimes = iTimes;
			if(pStatus->m_IsLoop == 0)
	{
		pStatus->m_TimeBegin =  pStatus->m_TimeEnd;
	}
	}
	if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[2]) == 0)
	{
		iTimes = iTimes;
			if(pStatus->m_IsLoop == 0)
	{
		pStatus->m_TimeBegin =  pStatus->m_TimeEnd;
	}
	}
	if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[3]) == 0)
	{
		iTimes = iTimes;
			if(pStatus->m_IsLoop == 0)
	{
		pStatus->m_TimeBegin =  pStatus->m_TimeEnd;
	}
	}
	if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[4]) == 0)
	{
		iTimes = iTimes;
			if(pStatus->m_IsLoop == 0)
	{
		iAniTime = pStatus->m_PathAniEnd;
	}

	}

	if (strcmp(_this->m_Name, "food_Dummy1") == 0)
		iTimes = iTimes;
	if (strcmp(_this->m_Name, "food_Dummy2") == 0)
		iTimes = iTimes;
	if (strcmp(_this->m_Name, "food_Dummy3") == 0)
		iTimes = iTimes;
	if (strcmp(_this->m_Name, "food_Dummy4") == 0)
		iTimes = iTimes;



	if (pStatus != NULL)
	{
		if (pStatus->m_IsLoop)
		{
			iAniBias = ( (long) (((_Time - pStatus->m_TimeBegin) % (int) ((pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio)) / pStatus->m_AniRatio))* WP3_D.anispeed;

			iAniTime = pStatus->m_AniBegin + (iAniBias* WP3_D.anispeed);

			if (pStatus->m_IsBackward)
			{
				iTimes = (int) ((_Time - pStatus->m_TimeBegin) / ((pStatus->m_AniEnd - pStatus->m_AniBegin) * pStatus->m_AniRatio));
				iTimes = iTimes % 2;
				if (iTimes == 1)
				{
					iAniTime2 = pStatus->m_AniEnd - (iAniBias);
					if (abs(iAniTime2 - debug_time) > 100)
						iTimes = iTimes;
					iAniTime = iAniTime2;
				}
			}

			if (abs(iAniTime - debug_time) > 100)
				iTimes = iTimes;
		}
		else
		{
			iAniTime = (long) ((_Time - pStatus->m_TimeBegin) / (pStatus->m_AniRatio / WP3_D.anispeed));
			if (pStatus->m_TimeBegin > pStatus->m_TimeEnd)
				iAniTime = pStatus->m_AniEnd - iAniTime;
			else
				iAniTime = pStatus->m_AniBegin + iAniTime;
		}

		V3Retained_UpdateNode(_this->m_Node, pStatus->m_AniName, iAniTime);
		iAniBias = (_Time - pStatus->m_TimeBegin) * WP3_D.anispeed;
		iAniTime = pStatus->m_PathAniBegin +  iAniBias ;
		if (pStatus->m_PathNode != NULL)
		{
			float Pos[3], Pos2[3];
			V3Retained_GetPathPosition(pStatus->m_PathNode, pStatus->m_PathAniName, iAniTime, Pos);

			pGameObj = WP3_D_GetGameObj(_this->m_Node);
			pGamePath = WP3_D_GetGamePath(pStatus->m_PathNode);
			IGUpdateGameObject(V3Retained_GetMem(), pGamePath, &err);

			if (pGameObj != NULL && pGamePath != NULL)
			{
				for (cn = 0; cn < 12; cn = cn + 1)
				{
					IGNode *pPathNode = pStatus->m_PathNode;
					_this->m_Node->m_oriMat[cn] = pPathNode->m_oriMat[cn];
				}
			}
			else
			{
				V3Retained_GetPathPosition(pStatus->m_PathNode, pStatus->m_PathAniName, iAniTime + 50, Pos2);
				if (Pos2[0] > Pos[0])
					IGNode_rotateZ(V3Retained_GetMem(), _this->m_Node, IG_PI, &err);
			}

			Position[0] = (igreal) (Pos[0] * IG_ONE);
			Position[1] = (igreal) (Pos[1] * IG_ONE);
			Position[2] = (igreal) (Pos[2] * IG_ONE);
			IGNode_setPosition(V3Retained_GetMem(), _this->m_Node, Position, &err);
		}
		else
		{
			
			Position[0] = (igreal) ((pStatus->m_Position[0] + pStatus->m_PositionV[0] * iAniBias) * IG_ONE);
			Position[1] = (igreal) ((pStatus->m_Position[1] + pStatus->m_PositionV[1] * iAniBias) * IG_ONE);
			Position[2] = (igreal) ((pStatus->m_Position[2] + pStatus->m_PositionV[2] * iAniBias) * IG_ONE);

			if (!(pStatus->m_PositionV[0] == 0 && pStatus->m_PositionV[1] == 0 && pStatus->m_PositionV[2] == 0))
				IGNode_setPosition(V3Retained_GetMem(), _this->m_Node, Position, &err);

			if (pStatus->m_PositionV[0] > 0)
				IGNode_rotateZ(V3Retained_GetMem(), _this->m_Node, IG_PI, &err);
		}
		
		IGNode_getPosition(V3Retained_GetMem(), _this->m_Node, Position, &err);
		_this->m_px = Position[0] / (float) IG_ONE;
		_this->m_py = Position[1] / (float) IG_ONE;
		_this->m_pz = Position[2] / (float) IG_ONE;



		if (strcmp(_this->m_Name, "food_Dummy1") == 0)
		{
			iTimes = iTimes;
		}
		if (strcmp(_this->m_Name, "food_Dummy2") == 0)
		{
			iTimes = iTimes;
		}
		if (strcmp(_this->m_Name, "food_Dummy3") == 0)
		{
			iTimes = iTimes;
		}
		if (strcmp(_this->m_Name, "food_Dummy4") == 0)
		{

			iTimes = iTimes;
		}
		if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[0]) == 0)
		{

			iTimes = iTimes;
		}
		if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[1]) == 0)
		{

			iTimes = iTimes;
		}
		if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[2]) == 0)
		{

			iTimes = iTimes;
		}
		if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[3]) == 0)
		{
			iTimes = iTimes;
		}
		if (strcmp(_this->m_Name, WP_NameStruct.node_name_Obj[4]) == 0)
		{
			iTimes = iTimes;
		}

		debug_time = iAniTime;
	}
}

#ifdef __cplusplus
}
#endif // __cplusplus

