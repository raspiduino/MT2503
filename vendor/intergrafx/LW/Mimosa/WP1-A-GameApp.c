//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP1-A
// File        : WP1-A-GameApp.c
// Description : 含羞草桌布 -- 遊戲主架構
// Author      : Ray
// Create      : 2010-11-02
// Update      : 2011-02-15
//==============================================================================

// --------------------------------------------------------------------------------------
// Headers
// --------------------------------------------------------------------------------------
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#endif

#include "IGComDef.h" 
#include "IGExtDef.h"
#include "IGMemoryPool.h"
#include "IGMathUtil.h"

#include "IGBackground.h"
#include "IGScene.h"
#include "IGRenderer.h"
#include "IGNode.h"
#include "IGGroup.h"
#include "IGCamera.h"
#include "IGTexture.h"
#include "IGObjCache.h"
#include "IGRay.h"

#include "IGGame.h"

#include "WP1-A-GameApp.h"
#include "V3DataDef.h"
#include "V3Retained.h"
#include "CUtils.h"
#include "CNodeStatus.h"
#include "WP1-A-Name.h"
#include "V3TextureManager.h"
#include "V3UI.h"

// --------------------------------------------------------------------------------------
// Global variables
// --------------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

//////////////////////////////////////////////////////// IGGame Framework Callback //////////////////////////////////////////

#if defined(WIN32) && !defined(_MODIS_ON_VC9_)

int IGGame_OnStartup(IGPlatformConfig *pPC)
{
	IGV3Config PC;

	{
		SYSTEMTIME sys_time;
		GetLocalTime(&sys_time);
		WP1_A_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	PC.m_uScrHeight = pPC->m_uScrHeight;
	PC.m_uScrWidth = pPC->m_uScrWidth;
	PC.m_pFrameBuffer = pPC->m_pFrameBuffer;
	PC.m_pMemBuffer = NULL;
	PC.m_MemSize = 0;

	WP1_A_PrepareConfig(&PC);
	WP1_A_OnStartup();
	//WP1_A_OnStartup00();

	return 0;
}

int IGGame_OnUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE)
{
	{
		SYSTEMTIME sys_time;
		GetLocalTime(&sys_time);
		WP1_A_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	while (uNumSysEvents--) {
		WP1_A_PostEvent(pSE->m_uEventID, pSE->m_uTime, pSE->m_uData1, pSE->m_uData2);
	}

	if (uFrameInterval > 0)
	{
		V3Retained *rr = V3Retained_GetInstance();
		WP1_A_OnUpdate(rr->PC.m_pFrameBuffer, uFrameInterval * 4800 / 32768);
	}

	return 0;
}

void IGGame_OnShutdown(void)
{
	WP1_A_OnShutdown();
}

#endif

//////////////////////////////////////////////////////// IGGame Framework Callback //////////////////////////////////////////

struct _WP1_A WP1_A;

#define ENGINE_BUFFER_SIZE 8*1024*1024
//static unsigned char s_engineMemBuf[ENGINE_BUFFER_SIZE];

int WP1_A_PrepareConfig(IGV3Config *pPC)
{
	int err;
	IGV3Config PC;

	PC.m_uScrHeight = pPC->m_uScrHeight;
	PC.m_uScrWidth = pPC->m_uScrWidth;
	PC.m_pFrameBuffer = pPC->m_pFrameBuffer;

	if (pPC->m_pMemBuffer != NULL)
	{
		PC.m_pMemBuffer = pPC->m_pMemBuffer;
		PC.m_MemSize = pPC->m_MemSize;
	}
	else
	{
		PC.m_pMemBuffer = NULL;
		PC.m_MemSize = ENGINE_BUFFER_SIZE;
	}

#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	PC.m_MaskR = MASK_555_RED;
	PC.m_MaskG = MASK_555_GREEN;
	PC.m_MaskB = MASK_555_BLUE;
	PC.m_IsTopDown = 0;
#else
	PC.m_MaskR = MASK_565_RED;
	PC.m_MaskG = MASK_565_GREEN;
	PC.m_MaskB = MASK_565_BLUE;
	PC.m_IsTopDown = 1;
#endif

	err = V3Retained_InitEngine(&PC);

	return err;
}

void WP1_A_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	char WP1_A_g_DebugMessage[128] = {0};
	sprintf(WP1_A_g_DebugMessage, _TEXT("[%010d] "), WP1_A.m_GameTime);
	sprintf(&WP1_A_g_DebugMessage[13], pFmt, _p1, _p2, _p3, _p4);
	OutputDebugString(WP1_A_g_DebugMessage);
#endif
}

CArrayPool *pWP1_A_StatusArrayPool = NULL;
IGSysEvent *pWP1_A_StatusArray = NULL;
void WP1_A_InitArrayPool(void)
{
	if(pWP1_A_StatusArrayPool == NULL)pWP1_A_StatusArrayPool = CNew(sizeof(CArrayPool));
	if(pWP1_A_StatusArray == NULL)pWP1_A_StatusArray = CNew(sizeof(IGSysEvent) * MAX_ARRAY_POOL);
	CArrayPool_Init(pWP1_A_StatusArrayPool, (void *) pWP1_A_StatusArray, sizeof(IGSysEvent) * MAX_ARRAY_POOL, sizeof(IGSysEvent));
}

IGSysEvent *WP1_A_Alloc(void)
{
	return (IGSysEvent *) CArrayPool_Alloc(pWP1_A_StatusArrayPool);
}

void WP1_A_Free(IGSysEvent *_this)
{
	CArrayPool_Free(pWP1_A_StatusArrayPool, (void *) _this);
}

void WP1_A_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2)
{
	IGSysEvent *pGE = WP1_A_Alloc();

	if(pGE == NULL)
	{
		WP1_A_InitArrayPool();
		pGE = WP1_A_Alloc();
	}

	pGE->m_uEventID = _Id;
	if (_Time == 0L)
		pGE->m_uTime = WP1_A.m_GameTime;
	else
		pGE->m_uTime = _Time;
	pGE->m_uData1 = _Data1;
	pGE->m_uData2 = _Data2;

	CQueue_Push(WP1_A.m_Event, (void *) pGE);
}

void WP1_A_ClearPendingEvents(void)
{
	CQueue_Clear(WP1_A.m_Event);
}

IGSysEvent *WP1_A_GetEvent(void)
{
	IGSysEvent *pR;

	pR = (IGSysEvent *) CQueue_Pop(WP1_A.m_Event);

	return pR;
}

V3Retained *WP1_A_rr = NULL;

//=============================================
//==================================OnStartup()
//=============================================
int WP1_A_OnStartup(void)
{
	WP1_A_InitArrayPool();
	WP1_A.iTime = 0L;
	CMemset(&WP1_A, sizeof(WP1_A), 0);
	
	WP1_A.iTime = 0L;
	V3Retained_LoadBackgroundTexture(png_WP1_A_back);

	return 0;
}

int WP1_A_LoadWorld(void)
{
	V3Texture *tex = NULL;
	CArray *texs;
	V3World *world;
	IGNode *Obj_root = NULL;
	int cn = 0;

	texs = V3Textures_New(NULL);
 
	for (cn = 0; cn < COUNT_BMP; cn = cn + 1)
	{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
		CArray_Add(texs, (void *) V3Texture_New(WP_NameStruct.bmp_array[cn], WP_NameStruct.file_bmp[cn], MASK_555_RED, MASK_555_GREEN, MASK_555_BLUE, WP_NameStruct.keycolor[cn]));
#else
		CArray_Add(texs, (void *) V3Texture_New(WP_NameStruct.bmp_array[cn], WP_NameStruct.file_bmp[cn], MASK_565_RED, MASK_565_GREEN, MASK_565_BLUE, WP_NameStruct.keycolor[cn]));
#endif
	}

	world = V3World_New(igf_WP1_A, texs, tex, "Scene Root", "Camera_control", "ANIMATE0");

	V3Retained_LoadWorld(world);

	V3World_Del(world);

	WP1_A_rr = V3Retained_GetInstance();

	IGCamera_setPerspectiveFieldOfView(WP1_A_rr->m_Mem, WP1_A_rr->m_Camera, (igreal) (IG_ONE * 0.55f), &WP1_A.err);

	Obj_root = (IGNode *) V3Retained_GetGroup(WP_NameStruct.node_name_Obj_root);
	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.node_name_Obj[cn]);
		
		WP1_A.m_OBJ[cn] = WP1_A_Status_New(pNode, WP_NameStruct.node_name_Obj[cn], "ANIMATE1");

		WP1_A.m_GameObj[cn] = IGNewAGameObject(WP1_A_rr->m_Mem, &WP1_A.err);
		IGAttachRootNodeToGameObject(WP1_A_rr->m_Mem, WP1_A.m_GameObj[cn], (IGNode *) WP1_A_rr->m_Root, pNode, &WP1_A.err);
		IGScene_AddToGameObjectList(WP1_A_rr->m_Mem, WP1_A.m_GameObj[cn], &WP1_A.err);
	}

	for (cn = 0; cn < COUNT_FLOWER; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.node_name_Flower[cn]);
		WP1_A.m_OBJFlower[cn] = WP1_A_Status_New(pNode, WP_NameStruct.node_name_Flower[cn], "ANIMATE1");
	}

	for(cn = 0; cn < COUNT_BIRD; cn = cn + 1)
	{
		WP1_A.m_Bird[cn] = (IGNode *) V3Retained_GetGroup(WP_NameStruct.node_name_Bird[cn]);
	}

	for(cn = 0; cn < COUNT_PATH; cn = cn + 1)
	{
		WP1_A.m_Path[cn] = (IGNode *) V3Retained_GetGroup(WP_NameStruct.node_name_Path[cn]);
	}

#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	srand( (unsigned)time( NULL ) );
#else
	{
	    kal_uint32 tick;
		kal_get_time(&tick);
		srand( (unsigned int)tick );
	}
#endif

	WP1_A.m_Event = CQueue_New(DEFAULT_QUEUE_SIZE);
	WP1_A.m_WP = WP1_A_Status_New(Obj_root, "root", "ANIMATE0");
	WP1_A.m_CurrentLoop = -1;

	WP1_A.m_AniInfo = V3Retained_GenerateAniInfo();

	WP1_A.m_GameTime = 0;
	WP1_A.m_DegreeInc = 0.1f;
	WP1_A.m_TimeFactor = 1;

	RandomEvent_Init(&WP1_A.m_Wind, MIMOSA_LOOP_WIND1, 3, WIND_MIN, WIND_MAX);
	TimeEvent_SetQuadHour(&WP1_A.m_FlowerY, &WP1_A.m_Time);
	TimeEvent_SetHour(&WP1_A.m_FlowerR, &WP1_A.m_Time);
	TimeEvent_SetQuadHour(&WP1_A.m_FlowerC, &WP1_A.m_Time);

	WP1_A_Status_EventHTouchMove(WP1_A.m_WP, 10);

	WP1_A.isRecovering = 0;//加這行是為了避免系統正在進行自動校正時, 被使用者重置了系統而導致狀態不一
	WP1_A.iMiddleDeg = 0;
	WP1_A.m_HDegree = (float)WP1_A.iMiddleDeg;
	
	WP1_A.iMaxDeg1 = 30;
	WP1_A.iMaxDeg2 = 45;
	WP1_A.iMinDeg1 = -10;
	WP1_A.iMinDeg2 = -25;

	return 0;
}

IGU32 WP1_A_GetElapsedTime(IGU32 _tick)
{
	static IGU32 last_tick = 0L;
	IGU32 diff = 0L;

	if (last_tick != 0)
	{
		diff = _tick - last_tick;
	}
	last_tick = _tick;
	return diff;
}

void WP1_A_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second)
{
	WP1_A.m_Hour = _hour;
	CTime_Set(&WP1_A.m_Time, _hour, _minute, _second);
}

int WP1_A_GetHour(void)
{
	return WP1_A.m_Hour;
}

void WP1_A_Flower(void)
{
	int iEvent = -1;

	iEvent = TimeEvent_Get(&WP1_A.m_FlowerY, &WP1_A.m_Time);
	if (iEvent == 1)
	{
		WP1_A_Status_EventFlower(WP1_A.m_OBJFlower[0], WP1_A.m_GameTime);
	}

	iEvent = TimeEvent_Get(&WP1_A.m_FlowerR, &WP1_A.m_Time);
	if (iEvent == 1)
	{
		WP1_A_Status_EventFlower(WP1_A.m_OBJFlower[1], WP1_A.m_GameTime);
	}

	iEvent = TimeEvent_Get(&WP1_A.m_FlowerC, &WP1_A.m_Time);
	if (iEvent == 1)
	{
		WP1_A_Status_EventFlower(WP1_A.m_OBJFlower[2], WP1_A.m_GameTime);
	}
}

void WP1_A_Wind(void)
{
	int iEvent = -1;
	int iTimes = 0;
	int cn = 0;

	if (WP1_A.m_Wind.m_Event == MIMOSA_NONE)
	{
		WP1_A.m_Wind.m_Event = (IGU8) MIMOSA_LOOP_WIND1;
		WP1_A_Status_Wind3(WP1_A.m_WP, 0L, 3);
		for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
		{
			WP1_A_Status_Leaf_Wind1(WP1_A.m_OBJ[cn], 0L, 0);
		}
		return;
	}
	
	iEvent = RandomEvent_Get(&WP1_A.m_Wind, WP1_A.m_GameTime);
	if (iEvent >= MIMOSA_LOOP_WIND1)
	{
		iTimes = RandomEvent_Random(1, 5);

		switch (iEvent)
		{
		case MIMOSA_LOOP_WIND1:
			WP1_A_Status_Wind1(WP1_A.m_WP, WP1_A.m_GameTime);
			for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
			{
				WP1_A_Status_Leaf_Wind1(WP1_A.m_OBJ[cn], WP1_A.m_GameTime, 0);
			}
			break;
		case MIMOSA_LOOP_WIND2:
			WP1_A_Status_Wind2(WP1_A.m_WP, WP1_A.m_GameTime, iTimes);
			for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
			{
				WP1_A_Status_Leaf_Wind2(WP1_A.m_OBJ[cn], WP1_A.m_GameTime, iTimes);
			}
			break;
		case MIMOSA_LOOP_WIND3:
			WP1_A_Status_Wind3(WP1_A.m_WP, WP1_A.m_GameTime, iTimes);
			for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
			{
				WP1_A_Status_Leaf_Wind3(WP1_A.m_OBJ[cn], WP1_A.m_GameTime, iTimes);
			}
			break;
		}
	}
}

void WP1_A_ProcessPick(int _pick_x, int _pick_y)
{
	IGErr err;
	IGPoint point;
	IGObjCache *pPickedObjs;
	IGPickedObject *picked;
	int cn, cn2;

	point.x = _pick_x;
	point.y = _pick_y;
	pPickedObjs = IGScene_PickSceneObjects(V3Retained_GetMem(), &point, &err);

	for (cn = 0; cn < pPickedObjs->m_pointers.m_count; cn = cn + 1)
	{
		picked = (IGPickedObject *)IGObjCache_getByIndex(V3Retained_GetMem(), pPickedObjs, cn, &err);
		if(picked != NULL)
		{
			for(cn2 = 0; cn2 < picked->m_PickedMeshNodes.m_pointers.m_count; cn2 = cn2 + 1)
			{
				//pMesh = (IGMesh *)IGObjCache_getByIndex(V3Retained_GetMem(), &picked->m_PickedMeshNodes, cn2, &err);
			}
			for (cn2 = 0; cn2 < COUNT_OBJ; cn2 = cn2 + 1)
			{
				if (picked->m_pObject->mRootNode == WP1_A.m_OBJ[cn2]->m_Node)
				{
					WP1_A_Status_EventTouchLeaf(WP1_A.m_OBJ[cn2], WP1_A.m_GameTime);
				}
			}
		}
	}
}

/*
static long DebugInterval()
{
	static int bFirst = 1;

	if (bFirst)
	{
		bFirst = 0;
		return 0L;
	}
	else
		return 10L;
}
*/

//是否為右邊, 1:目前是要恢復右邊, 0:目前要恢復左邊
void WP1_A_DegRecovery(int isRight)
{
	int iInc = 1;
	if(isRight != 1) iInc = iInc * -1;
	WP1_A.isRecovering = 1;
	WP1_A_Status_EventHTouchMove(WP1_A.m_WP, iInc);
}

void WP1_A_Update2D(unsigned char *_pFrameBuffer)
{
	V3Retained_Bind(_pFrameBuffer);
	V3UI_DrawImage2DCenter(WP1_A_rr->m_BackgroundTexture, 1.0f);
}

int WP1_A_Update3D(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	int cn;
	IGSysEvent *pSE = NULL;

	AniInfo *bird_ani_info = CNamedObjArray_Get(WP1_A.m_AniInfo, 4);
	AniInfo *path_ani_info = CNamedObjArray_Get(WP1_A.m_AniInfo, 3);

	igreal Position[3];
	V3Retained_Bind(_pFrameBuffer);

	WP1_A.err = IGERR_NONE;
	WP1_A.m_ElapsedTime = uFrameInterval;
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	//WP1_A.m_ElapsedTime = DebugInterval();
#endif
	WP1_A.m_GameTime = WP1_A.m_GameTime + WP1_A.m_ElapsedTime / WP1_A.m_TimeFactor;

	WP1_A_Wind();
	WP1_A_Flower();

	while ((pSE = (IGSysEvent *) CQueue_Pop(WP1_A.m_Event)) != NULL)
	{
		switch (pSE->m_uEventID)
		{
		case IGFK_TOUCH1_DOWN :			
				WP1_A.iMouseX = pSE->m_uData1;
				WP1_A.iMouseY = pSE->m_uData2;
				WP1_A_ProcessPick(pSE->m_uData1, pSE->m_uData2);
			break;
		case IGFK_TOUCH1_MOVE :	
			WP1_A_Status_EventHTouchMove(WP1_A.m_WP, WP1_A.iMouseX - pSE->m_uData1);
			WP1_A.iMouseX = pSE->m_uData1;
			WP1_A.iMouseY = pSE->m_uData2; 
			break;
		case IGFK_TOUCH1_UP :
			WP1_A.iMouseX = pSE->m_uData1;
			WP1_A.iMouseY = pSE->m_uData2;
			
			//檢查攝影機角度有沒有落在左右緩衝區間內, 有就啟動自動角度校正
			if(WP1_A.m_HDegree >= WP1_A.iMiddleDeg && WP1_A.m_HDegree > WP1_A.iMaxDeg1)
				WP1_A.isRecovering = 1;
			else if(WP1_A.m_HDegree <= WP1_A.iMiddleDeg && WP1_A.m_HDegree <= WP1_A.iMinDeg1)
				WP1_A.isRecovering = 1;
			break;
		}

		WP1_A_Free(pSE);
	}

	//檢查是否需要進行鏡頭自動校正, 且分辨是左校正或者右校正
	if(WP1_A.m_HDegree >= WP1_A.iMiddleDeg && WP1_A.m_HDegree >= WP1_A.iMaxDeg1 && WP1_A.isRecovering == 1)
		WP1_A_DegRecovery(0);//左校正
	else if(WP1_A.m_HDegree <= WP1_A.iMiddleDeg && WP1_A.m_HDegree <= WP1_A.iMinDeg1 && WP1_A.isRecovering == 1)
		WP1_A_DegRecovery(1);//右校正

	V3Retained_UpdateNode((IGNode*)WP1_A_rr->m_CameraControl, "ANIMATE0", 0);
	IGNode_rotateZ(WP1_A_rr->m_Mem, (IGNode *) WP1_A_rr->m_CameraControl, (igreal) (IG_PI * (WP1_A.m_HDegree ) / 180.0f), &WP1_A.err);
	
	WP1_A.iTime = WP1_A.iTime + WP1_A.m_ElapsedTime / WP1_A.m_TimeFactor;
	
	WP1_A.iTime = WP1_A.iTime % bird_ani_info->m_Duration;
	V3Retained_UpdateNode((IGNode *) WP1_A.m_Bird[0], "ANIMATE4", WP1_A.iTime);

	WP1_A_Status_Update(WP1_A.m_WP, WP1_A.m_GameTime);
	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{	
		WP1_A_Status_Update(WP1_A.m_OBJ[cn], WP1_A.m_GameTime);
	}

	for (cn = 0; cn < COUNT_FLOWER; cn = cn + 1)
	{
		WP1_A_Status_Update(WP1_A.m_OBJFlower[cn], WP1_A.m_GameTime);
	}

	//背景上的飛鳥
	{
		float Pos[3];
		IGNode *pPathNode = WP1_A.m_Path[0];
		float fSize = 2.0f;
		igreal iScale[3];

		iScale[0] = (igreal) (fSize * IG_ONE);
		iScale[1] = (igreal) (fSize * IG_ONE);
		iScale[2] = (igreal) (fSize * IG_ONE);

		V3Retained_GetPathPosition(pPathNode, "ANIMATE3", WP1_A.m_GameTime % path_ani_info->m_Duration, Pos);
		//V3Retained_GetPathPosition(pPathNode, "ANIMATE3", fakeTime % path_ani_info->m_Duration, Pos);

		if (WP1_A.m_Bird[0])
			for (cn = 0; cn < 12; cn = cn + 1)
				WP1_A.m_Bird[0]->m_oriMat[cn] = pPathNode->m_oriMat[cn];
		Position[0] = (igreal) (Pos[0] * IG_ONE);
		Position[1] = (igreal) (Pos[1] * IG_ONE);
		Position[2] = (igreal) (Pos[2] * IG_ONE);

		IGNode_setScale(WP1_A_rr->m_Mem, WP1_A.m_Bird[0], iScale, &WP1_A.err);
		IGNode_setPosition(V3Retained_GetMem(), WP1_A.m_Bird[0], Position, &WP1_A.err);
	}

	V3Retained_Render();

	return 0;
}
int WP1_A_SafeCheck(void)
{
	int iOK = 1;
	int iFAIL = 0;
	int iRESULT = iFAIL;
	int cn = 0;

	for(cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		if(WP1_A.m_OBJ[cn] == NULL)
		{
			iRESULT = iFAIL;
			return iRESULT;
		}
		else
		{
			iRESULT = iOK;
		}
	}


	return iRESULT;
}

int WP1_A_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	WP1_A_rr = V3Retained_GetInstance();

	switch (WP1_A.m_bLoadWorld)
	{
	case 0 :
		WP1_A_Update2D(_pFrameBuffer);
		WP1_A.m_bLoadWorld = 1;
		break;
	case 1:
		WP1_A_LoadWorld();
		V3Retained_ActiveBackgroundTexture();
		WP1_A_Update2D(_pFrameBuffer);
		WP1_A.m_bLoadWorld = 2;
		break;
	case 2:
		if(WP1_A_SafeCheck() == 1)//讀取完畢, 放行
		{
			V3Retained_ActiveBackgroundTexture();
			WP1_A_Update3D(_pFrameBuffer, uFrameInterval);
			WP1_A.m_bLoadWorld = 3;
		}
		else//還在讀取 繼續等等
		{
			WP1_A_Update2D(_pFrameBuffer);
		}
		break;
	case 3:
		WP1_A_Update3D(_pFrameBuffer, uFrameInterval);
		break;
	}

	return 0;
}
void WP1_A_OnShutdown(int appId)
{
	int cn = 0;
	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		if(WP1_A.m_OBJ[cn] != NULL)
		{
			WP1_A_Status_Del(WP1_A.m_OBJ[cn]);
			WP1_A.m_OBJ[cn] = NULL;
		}
	}

	if(WP1_A.m_Event != NULL)
	{
		CQueue_Del(WP1_A.m_Event);
		WP1_A.m_Event = NULL;
	}
	
	if(WP1_A.m_WP != NULL)
	{
		WP1_A_Status_Del(WP1_A.m_WP);
		WP1_A.m_WP = NULL;
	}
	
	if(WP1_A.m_AniInfo != NULL)
	{
		CArray_Del(WP1_A.m_AniInfo);
		WP1_A.m_AniInfo = NULL;
	}
	
	if(pWP1_A_StatusArrayPool != NULL)
	{
		CDel(pWP1_A_StatusArrayPool);
		pWP1_A_StatusArrayPool = NULL;
	}

	if(pWP1_A_StatusArray != NULL)
	{
		CDel(pWP1_A_StatusArray);
		pWP1_A_StatusArray = NULL;
	}
	
	if(WP1_A.pStatusArray != NULL)
	{
		CDel(WP1_A.pStatusArray);
		WP1_A.pStatusArray = NULL;
	}

	if(WP1_A.pStatusArrayPool != NULL)
	{
		CDel(WP1_A.pStatusArrayPool);
		WP1_A.pStatusArrayPool = NULL;
	}

	V3Retained_End(appId);
}



#ifdef __cplusplus
}
#endif
