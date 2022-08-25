//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3-D
// File        : WP3-D-GameApp.c
// Description : 手機魚缸桌布 -- 遊戲主架構
// Author      : Ray
// Create      : 2010-11-16
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

#include "WP3-D-GameApp.h"
#include "V3DataDef.h"
#include "V3Retained.h"
#include "CUtils.h"
#include "CNodeStatus.h"
#include "WP3-D-Name.h"
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
		WP3_D_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	PC.m_uScrHeight = pPC->m_uScrHeight;
	PC.m_uScrWidth = pPC->m_uScrWidth;

	PC.m_pFrameBuffer = pPC->m_pFrameBuffer;
	PC.m_pMemBuffer = NULL;
	PC.m_MemSize = 0;

	WP3_D_PrepareConfig(&PC);
	WP3_D_OnStartup();

	return 0;
}

int IGGame_OnUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE)
{
	{
		SYSTEMTIME sys_time;
		GetLocalTime(&sys_time);
		WP3_D_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	while (uNumSysEvents--) {
		WP3_D_PostEvent(pSE->m_uEventID, pSE->m_uTime, pSE->m_uData1, pSE->m_uData2);
	}

	//The resolution of the GetTickCount function is limited to the resolution of the system timer, which is typically in the range of 10 milliseconds to 16 milliseconds
	//這樣才不會造成時間差 = 0
	if (uFrameInterval > 0)
	{
		V3Retained *rr = V3Retained_GetInstance();
		WP3_D_OnUpdate(rr->PC.m_pFrameBuffer, uFrameInterval * 4800 / 32768);
	}

	return 0;
}

void IGGame_OnShutdown(void)
{
	WP3_D_OnShutdown();
}

#endif

//////////////////////////////////////////////////////// IGGame Framework Callback //////////////////////////////////////////

struct _WP3_D WP3_D;

#define ENGINE_BUFFER_SIZE 4*1024*1024
//static unsigned char s_engineMemBuf[ENGINE_BUFFER_SIZE];

int WP3_D_PrepareConfig(IGV3Config *pPC)
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

void WP3_D_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	char WP3_D_g_DebugMessage[128] = {0};
	sprintf(WP3_D_g_DebugMessage, _TEXT("[%010d] "), WP3_D.m_GameTime);
	sprintf(&WP3_D_g_DebugMessage[13], pFmt, _p1, _p2, _p3, _p4);
	OutputDebugString(WP3_D_g_DebugMessage);
#endif
}

CArrayPool *pWP3_D_StatusArrayPool = NULL;
IGSysEvent *pWP3_D_StatusArray = NULL;

void WP3_D_InitArrayPool(void)
{
	if(pWP3_D_StatusArrayPool == NULL)pWP3_D_StatusArrayPool = CNew(sizeof(CArrayPool));
	if(pWP3_D_StatusArray == NULL)pWP3_D_StatusArray = CNew(sizeof(IGSysEvent) * MAX_ARRAY_POOL);
	CArrayPool_Init(pWP3_D_StatusArrayPool, (void *) pWP3_D_StatusArray, sizeof(IGSysEvent) * MAX_ARRAY_POOL, sizeof(IGSysEvent));
}

IGSysEvent *WP3_D_Alloc(void)
{
	return (IGSysEvent *) CArrayPool_Alloc(pWP3_D_StatusArrayPool);
}

void WP3_D_Free(IGSysEvent *_this)
{
	CArrayPool_Free(pWP3_D_StatusArrayPool, (void *) _this);
}

void WP3_D_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2)
{
	IGSysEvent *pGE = WP3_D_Alloc();

	if(pGE == NULL)
	{
		WP3_D_InitArrayPool();
		pGE = WP3_D_Alloc();
	}

	pGE->m_uEventID = _Id;
	if (_Time == 0L)
		pGE->m_uTime = WP3_D.m_GameTime;
	else
		pGE->m_uTime = _Time;
	pGE->m_uData1 = _Data1;
	pGE->m_uData2 = _Data2;

	CQueue_Push(WP3_D.m_Event, (void *) pGE);
}

void WP3_D_ClearPendingEvents(void)
{
	CQueue_Clear(WP3_D.m_Event);
}

IGSysEvent *WP3_D_GetEvent(void)
{
	IGSysEvent *pR;

	pR = (IGSysEvent *) CQueue_Pop(WP3_D.m_Event);

	return pR;
}

V3Retained *WP3_D_rr = NULL;

int WP3_D_OnStartup(void)
{
	WP3_D_InitArrayPool();
	CMemset(&WP3_D, sizeof(WP3_D), 0);
	V3Retained_LoadBackgroundTexture(png_WP3_D_back);
	WP3_D.iObj = 1;
	WP3_D.m_bLoadWorld = 0;
	return 0;
}

int WP3_D_LoadWorld(void)
{
	V3Texture *tex = NULL;
	CArray *texs;
	V3World *world;

	
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

	world = V3World_New(igf_WP3_D, texs, tex, "Scene Root", "Camera_control", "ANIMATE0");


	V3Retained_LoadWorld(world);

	V3World_Del(world);

	WP3_D_rr = V3Retained_GetInstance();

	//IGCamera_setViewMode(rr->m_Mem, rr->m_Camera, IGVIEW_PARALLEL, &err);
	//IGCamera_setParallelFieldOfView(rr->m_Mem, rr->m_Camera, IG_ONE / 5, &err);
	//IGCamera_setPerspectiveFieldOfView(rr->m_Mem, rr->m_Camera, IG_ONE / 10, &err);

	WP3_D.m_Grass[0] = V3Retained_GetNode("plants2");
	WP3_D.m_Grass[1] = V3Retained_GetNode("plants3");
	WP3_D.m_Bubble[0] = V3Retained_GetNode("bub_Dummy");
	WP3_D.m_Bubble[1] = V3Retained_GetNode("bub_Dummy1");
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup("bubbleall");
		WP3_D.m_allbubble = WPFishStatus_New(pNode, "bubbleall","ANIMATE0");
		WP3_D.m_allbubble->m_speed = 0.001f;
	}

	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.node_name_Obj[cn]);
		WP3_D.m_OBJ[cn] = WPFishStatus_New(pNode, WP_NameStruct.node_name_Obj[cn], "ANIMATE0");
		WP3_D.m_OBJ[cn]->m_speed = 0.001f;  //unit / ms

		WP3_D.m_GameObj[cn] = IGNewAGameObject(WP3_D_rr->m_Mem, &WP3_D.err);
		IGAttachRootNodeToGameObject(WP3_D_rr->m_Mem, WP3_D.m_GameObj[cn], (IGNode *) WP3_D_rr->m_Root, pNode, &WP3_D.err);
		IGScene_AddToGameObjectList(WP3_D_rr->m_Mem, WP3_D.m_GameObj[cn], &WP3_D.err);
	}

	for (cn = 0; cn < COUNT_PATH; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.path_name_Obj[cn]);
		WP3_D.m_Path[cn] = pNode;

		WP3_D.m_GamePath[cn] = IGNewAGameObject(WP3_D_rr->m_Mem, &WP3_D.err);
		IGAttachRootNodeToGameObject(WP3_D_rr->m_Mem, WP3_D.m_GamePath[cn], (IGNode *) WP3_D_rr->m_Root, pNode, &WP3_D.err);
		IGScene_AddToGameObjectList(WP3_D_rr->m_Mem, WP3_D.m_GamePath[cn], &WP3_D.err);
	}

	{
		IGNode *pNode = NULL;
		pNode = (IGNode *) V3Retained_GetGroup("food_Dummy1");
		WP3_D.m_Food[0] = WPFishStatus_New(pNode, "food_Dummy1", "ANIMATE2");
		pNode = (IGNode *) V3Retained_GetGroup("food_Dummy2");
		WP3_D.m_Food[1] = WPFishStatus_New(pNode, "food_Dummy2", "ANIMATE2");
		pNode = (IGNode *) V3Retained_GetGroup("food_Dummy3");
		WP3_D.m_Food[2] = WPFishStatus_New(pNode, "food_Dummy3", "ANIMATE2");
		pNode = (IGNode *) V3Retained_GetGroup("food_Dummy4");
		WP3_D.m_Food[3] = WPFishStatus_New(pNode, "food_Dummy4", "ANIMATE2");
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

	WP3_D.m_Event = CQueue_New(DEFAULT_QUEUE_SIZE);
	WP3_D.anispeed = 1;
	WP3_D.m_WP = WPFishStatus_New((IGNode *) WP3_D_rr->m_Root, "root", "ANIMATE0");
	WPFishStatus_LoopDefault(WP3_D.m_WP, WP3_D.m_GameTime);
	WP3_D.m_CurrentLoop = -1;

	WP3_D.m_thisfood[0] = RandomEvent_Random(1,4);

	cn = RandomEvent_Random(1,4);
	if(cn == WP3_D.m_thisfood[0])
	{
		cn = cn + 1;
		if(cn == 5)
		{	
			cn = 1;
		}
	}

 	WP3_D.m_thisfood[1] = cn;


	WP3_D.m_AniInfo = V3Retained_GenerateAniInfo();


 	WP3_D.m_DegreeInc = 10;
	WP3_D.m_TimeFactor = 1;

	CRect_Set(&WP3_D.m_RectFeed, 0, 0, 160, 96);
	CRect_Set(&WP3_D.m_RectLight, 160, 0, 160, 96);

	RandomEvent_Init(&WP3_D.m_CheckObj, 1, 5, FISH_MIN, FISH_MAX);

	V3Retained_ActiveBackgroundTexture();
	WP3_D.m_bLoadWorld = 3;
	
	return 0;
}

IGU32 WP3_D_GetElapsedTime(IGU32 _tick)
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

void WP3_D_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second)
{
	WP3_D.m_Hour = _hour;
}

int WP3_D_GetHour(void)
{
	return WP3_D.m_Hour;
}

int WP3_D_Random(int _min, int _max)
{
	int rnd_value = 0;

	rnd_value = rand() % (_max - _min + 1) + _min;
	//rnd_value = (double) rand() / (RAND_MAX + 1) * (_max - _min) + _min;
	return rnd_value;
}

IGGameObject *WP3_D_GetGameObj(IGNode *_pNode)
{
	IGGameObject *pObj = NULL;
	int cn = 0;

	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		if (WP3_D.m_OBJ[cn]->m_Node == _pNode)
		{
			pObj = WP3_D.m_GameObj[cn];
		}
	}
	return pObj;
}

IGGameObject *WP3_D_GetGamePath(IGNode *_pNode)
{
	IGGameObject *pObj = NULL;
	int cn = 0;

	for (cn = 0; cn < COUNT_PATH; cn = cn + 1)
	{
		if (WP3_D.m_Path[cn] == _pNode)
		{
			pObj = WP3_D.m_GamePath[cn];
		}
	}
	return pObj;
}

void Event_Feed1(void)
{
	int cn = 0, iSendObjCount = 0, iSended = 0, iPath = 0, kn = 0;

	NodeAniStatus *pStatus = NULL;

	iSendObjCount = 2;
	iPath = COUNT_PATH - 4;

	//潛水艇不能過去吃
	for(cn = 0 ; cn < 2 ; cn = cn + 1 )
	{
	kn = WP3_D.m_thisfood[cn];
	pStatus = WPFishStatus_CurrentStatus(WP3_D.m_OBJ[kn], WP3_D.m_GameTime);
		if (pStatus == NULL)
		{
			/*WPFishStatus_FeedFood(WP3_D.m_Food[cn], WP3_D.m_GameTime);*/
			
			WPFishStatus_EventPathEat(WP3_D.m_OBJ[kn], WP3_D.m_GameTime, WP3_D.m_Path[iPath]);
			iSended = iSended + 1;
			iPath = iPath + 1;
			if (iSended >= iSendObjCount)
				break;
		}
	}
}
void Event_Food1(void)
{
	int cn = 0;

	//潛水艇不能過去吃
	for(cn = 0 ; cn < 2 ; cn = cn + 1 )
	{
		WPFishStatus_FeedFood(WP3_D.m_Food[cn], WP3_D.m_GameTime);
	}
}
void Event_Food2(void)
{
	//潛水艇不能過去吃

		WPFishStatus_FeedFood(WP3_D.m_Food[2], WP3_D.m_GameTime);
}
void Event_Food3(void)
{
	//潛水艇不能過去吃

		WPFishStatus_FeedFood(WP3_D.m_Food[3], WP3_D.m_GameTime);
}
void Event_Feed2(void)
{
	int cn = 0, iSendObjCount = 0, iSended = 0, iPath = 0, kn = 0;

	NodeAniStatus *pStatus = NULL;

	iSendObjCount = 1;
	iPath = COUNT_PATH - 2;

	//潛水艇不能過去吃
	for(cn = 0 ; cn < 1 ; cn = cn + 1 )
	{
	kn = WP3_D.m_thisfood[0];
	pStatus = WPFishStatus_CurrentStatus(WP3_D.m_OBJ[kn], WP3_D.m_GameTime);
		if (pStatus == NULL)
		{
			//WPFishStatus_FeedFood(WP3_D.m_Food[2], WP3_D.m_GameTime);
			
			WPFishStatus_EventPathEat(WP3_D.m_OBJ[kn], WP3_D.m_GameTime, WP3_D.m_Path[iPath]);
			iSended = iSended + 1;
			iPath = iPath + 1;
			if (iSended >= iSendObjCount)
				break;
		}
	}
}

void Event_Feed3(void)
{
	int cn = 0, iSendObjCount = 0, iSended = 0, iPath = 0, kn = 0;

	NodeAniStatus *pStatus = NULL;

	iSendObjCount = 1;
	iPath = COUNT_PATH - 1;

	//潛水艇不能過去吃
	for(cn = 0 ; cn < 1 ; cn = cn + 1 )
	{
	kn = WP3_D.m_thisfood[1];
	pStatus = WPFishStatus_CurrentStatus(WP3_D.m_OBJ[kn], WP3_D.m_GameTime);
		if (pStatus == NULL)
		{
			//WPFishStatus_FeedFood(WP3_D.m_Food[3], WP3_D.m_GameTime);
			
			WPFishStatus_EventPathEat(WP3_D.m_OBJ[kn], WP3_D.m_GameTime, WP3_D.m_Path[iPath]);
			iSended = iSended + 1;
			iPath = iPath + 1;
			if (iSended >= iSendObjCount)
				break;
		}
	}


}

void WP3_D_CheckObj(void)
{
	int iEvent = -1;
	int cn = 0, cn2, iHit, iCurrentObjCount = 0, iSendObjCount = 0, iSended = 0, iPath = 0;

	NodeAniStatus *pStatus = NULL;

	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		pStatus = WPFishStatus_CurrentStatus(WP3_D.m_OBJ[cn], WP3_D.m_GameTime);
		if (pStatus != NULL)
			iCurrentObjCount = iCurrentObjCount + 1;
	}

	iEvent = RandomEvent_Get(&WP3_D.m_CheckObj, WP3_D.m_GameTime);
	if (WP3_D.m_CheckObj.m_Event == 0 || iEvent > 0)
	{
		if (iEvent > 0)
			WP3_D.m_CheckObj.m_Event = iEvent;
		else
			WP3_D.m_CheckObj.m_Event = RandomEvent_Random(1, 5);

		if (WP3_D.m_CheckObj.m_Event > iCurrentObjCount)
			iSendObjCount = WP3_D.m_CheckObj.m_Event - iCurrentObjCount;

		for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
		{
			pStatus = WPFishStatus_CurrentStatus(WP3_D.m_OBJ[cn], WP3_D.m_GameTime);
			if (pStatus == NULL)
				WP3_D.m_OBJ[cn]->m_Path = -1;
		}

		for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
		{
			if(WP3_D.m_thisfood[0] != cn && WP3_D.m_thisfood[1] != cn)
			{
			pStatus = WPFishStatus_CurrentStatus(WP3_D.m_OBJ[cn], WP3_D.m_GameTime);
			if (pStatus == NULL)
			{
					WP3_D.m_OBJ[cn]->m_Path = -1;
					iHit = 1;

					do
					{
						iHit = 0;
						//扣掉潛水艇以及兩條餵食路徑
						iPath = RandomEvent_Random(1, COUNT_PATH-5);
						for (cn2 = 0; cn2 < COUNT_OBJ; cn2 = cn2 + 1)
						{
							if (WP3_D.m_OBJ[cn2] != WP3_D.m_OBJ[cn])
							{
								if (WP3_D.m_OBJ[cn2]->m_Path == iPath)
								{
									iHit = 1;
									break;
								}
							}
						}
					}while(iHit == 1);
					if(WP3_D.m_thisfood[0] == cn)
					{
						iHit = 0;
						iPath = -1;
					}
				WP3_D.m_OBJ[cn]->m_Path = iPath;
				WPFishStatus_EventPathSwim(WP3_D.m_OBJ[cn], WP3_D.m_GameTime, WP3_D.m_Path[iPath]);
				iSended = iSended + 1;
				if (iSended >= iSendObjCount)
					break;
			}
			} 
		}
		return;
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

void WP3_D_Update2D(unsigned char *_pFrameBuffer)
{
	V3Retained_Bind(_pFrameBuffer);
	V3UI_DrawImage2DCenter(WP3_D_rr->m_BackgroundTexture, 1.0f);
}

int WP3_D_Update3D(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	IGSysEvent *pSE = NULL;

	AniInfo *ani_info = CNamedObjArray_Get(WP3_D.m_AniInfo, 0);
	//AniInfo *ani_info2 = CNamedObjArray_Get(WP3_D.m_AniInfo, 2);
	int cn = 0, kn = 0, fish1 = 0,fish2 = 0;
	NodeAniStatus *pStatus = NULL;
	V3Retained_Bind(_pFrameBuffer);
	WP3_D.m_ElapsedTime = uFrameInterval;
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	//WP3_D.m_ElapsedTime = DebugInterval();
#endif
	WP3_D.m_GameTime = WP3_D.m_GameTime + WP3_D.m_ElapsedTime / WP3_D.m_TimeFactor;
	WP3_D_CheckObj();

	for(cn = 0 ; cn < 2 ; cn = cn + 1 )
	{
	kn = WP3_D.m_thisfood[cn];
	pStatus = WPFishStatus_CurrentStatus(WP3_D.m_OBJ[kn], WP3_D.m_GameTime);
		if (pStatus == NULL)
		{
			if(cn == 0)
				fish1 = 1;
			if(cn == 1)
				fish2 = 1;
		}
	}
	
	while ((pSE = (IGSysEvent *) CQueue_Pop(WP3_D.m_Event)) != NULL)
	{
		switch (pSE->m_uEventID)
		{
			case IGFK_TOUCH1_MOVE :
				{
					WP3_D.Ymouse = abs(pSE->m_uData1 - WP3_D.iMouseX);
					WP3_D.mouseL = WP3_D_rr->m_Renderer->m_buffs.m_width/4;
					
						if(WP3_D.pickonce == 0)
						{
							WPFishStatus_Bubble(WP3_D.m_allbubble, WP3_D.m_GameTime);
							WP3_D.pickonce = 1;
						}
					
				}
				break;
		case IGFK_TOUCH1_DOWN :
			{
				/*
				if(pSE->m_uData1> ((WP3_D.m_screenw/3)*2) &&	pSE->m_uData2 < (WP3_D.m_screenh/4))
				{
					WP3_D.anispeed = WP3_D.anispeed + 1;
					if(WP3_D.anispeed == 6)
					{
						WP3_D.anispeed = 1;
					}
					if(WP3_D.m_thisfood[0] != cn && WP3_D.m_thisfood[1] != cn)
					{

					}
				}
				*/

				WP3_D.pickonce = 0;
				WP3_D.iMouseX = pSE->m_uData1;
				if(WP3_D.iMouseX > (int) (WP3_D_rr->m_Renderer->m_buffs.m_width/3) && WP3_D.iMouseX < (int) ((WP3_D_rr->m_Renderer->m_buffs.m_width/3)*2))
				{
					IGNode *pNode = NULL;
					WPFishStatus_Del(WP3_D.m_Food[0]);
					pNode = (IGNode *) V3Retained_GetGroup("food_Dummy1");
					WP3_D.m_Food[0] = WPFishStatus_New(pNode, "food_Dummy1", "ANIMATE2");
					WPFishStatus_Del(WP3_D.m_Food[1]);
					pNode = (IGNode *) V3Retained_GetGroup("food_Dummy2");
					WP3_D.m_Food[1] = WPFishStatus_New(pNode, "food_Dummy2", "ANIMATE2");
					Event_Food1();
				}
				if(WP3_D.iMouseX <= (int) (WP3_D_rr->m_Renderer->m_buffs.m_width/3) )
				{
					IGNode *pNode = NULL;
					WPFishStatus_Del(WP3_D.m_Food[2]);
					pNode = (IGNode *) V3Retained_GetGroup("food_Dummy3");
					WP3_D.m_Food[2] = WPFishStatus_New(pNode, "food_Dummy3", "ANIMATE2");
					Event_Food2();
				}
				if(WP3_D.iMouseX >= (int) ((WP3_D_rr->m_Renderer->m_buffs.m_width/3)*2))
				{
					IGNode *pNode = NULL;
					WPFishStatus_Del(WP3_D.m_Food[3]);
					pNode = (IGNode *) V3Retained_GetGroup("food_Dummy4");
					WP3_D.m_Food[3] = WPFishStatus_New(pNode, "food_Dummy4", "ANIMATE2");
					Event_Food3();
				}
				if(fish1 + fish2 == 2)
				{
				if(WP3_D.iMouseX > (int) (WP3_D_rr->m_Renderer->m_buffs.m_width/3) && WP3_D.iMouseX < (int) ((WP3_D_rr->m_Renderer->m_buffs.m_width/3)*2))
				{
					Event_Feed1();
					fish1 = 0;
					fish2 = 0;
				}
				if(WP3_D.iMouseX <= (int) (WP3_D_rr->m_Renderer->m_buffs.m_width/3) )
				{
					Event_Feed2();
					fish1 = 0;
					fish2 = 0;
				}
				if(WP3_D.iMouseX >= (int) ((WP3_D_rr->m_Renderer->m_buffs.m_width/3)*2))
				{
					Event_Feed3();
					fish1 = 0;
					fish2 = 0;
				}
				}
			}
			break;

		case IGGAME_RESET :
			{

			}
			break;
		}

		WP3_D_Free(pSE);
	}

	{
		int iDuration = 460;
		int iAniTime = (WP3_D.m_GameTime/3);
		int iTimes = iAniTime / iDuration;
		iTimes = iTimes % 2;
		iAniTime = iAniTime % iDuration;
		if (iTimes == 1)
		{
			iAniTime = iDuration - iAniTime;
		}
		V3Retained_UpdateNode(WP3_D.m_Grass[0], "ANIMATE0", iAniTime);
		V3Retained_UpdateNode(WP3_D.m_Grass[1], "ANIMATE0", iAniTime);
	}
	if(WP3_D.pStatusArrayPool->m_Used > 900)
		WP3_D.memover = 1;

	V3Retained_UpdateNode(WP3_D.m_Bubble[0], "ANIMATE0", (WP3_D.m_GameTime/3) % ani_info->m_Duration);
	V3Retained_UpdateNode(WP3_D.m_Bubble[1], "ANIMATE0", (WP3_D.m_GameTime/3) % ani_info->m_Duration);

	//WP3_D_AddDebugMessage("%d\n",WP3_D.pStatusArrayPool->m_Used,0L,0L,0L);
	WPFishStatus_Update(WP3_D.m_OBJ[0], WP3_D.m_GameTime);
	WP3_D.substatus = WP3_D.m_OBJ[0];
	WPFishStatus_Update(WP3_D.m_OBJ[1], WP3_D.m_GameTime);
	WP3_D.fishstatus[0] = WP3_D.m_OBJ[1];
	WPFishStatus_Update(WP3_D.m_OBJ[2], WP3_D.m_GameTime);
	WP3_D.fishstatus[1] = WP3_D.m_OBJ[2];
	WPFishStatus_Update(WP3_D.m_OBJ[3], WP3_D.m_GameTime);
	WP3_D.fishstatus[2] = WP3_D.m_OBJ[3];
	WPFishStatus_Update(WP3_D.m_OBJ[4], WP3_D.m_GameTime);
	WP3_D.fishstatus[3] = WP3_D.m_OBJ[4];
	WPFishStatus_Update(WP3_D.m_allbubble, WP3_D.m_GameTime);
	WP3_D.bubbleall = WP3_D.m_allbubble;

	WPFishStatus_Update(WP3_D.m_Food[0], WP3_D.m_GameTime);
	WP3_D.food[0] = WP3_D.m_Food[0];
	WPFishStatus_Update(WP3_D.m_Food[1], WP3_D.m_GameTime);
	WP3_D.food[1] = WP3_D.m_Food[1];
	WPFishStatus_Update(WP3_D.m_Food[2], WP3_D.m_GameTime);
	WP3_D.food[2] = WP3_D.m_Food[2];
	WPFishStatus_Update(WP3_D.m_Food[3], WP3_D.m_GameTime);
	WP3_D.food[3] = WP3_D.m_Food[3];

	V3Retained_Render();

	return 0;
}

int WP3_D_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	WP3_D_rr = V3Retained_GetInstance();

	switch (WP3_D.m_bLoadWorld)
	{
	case 0 :
		WP3_D_Update2D(_pFrameBuffer);
		WP3_D.m_bLoadWorld = 1;
		break;
	case 1:
		WP3_D.m_bLoadWorld = 2;
		WP3_D_LoadWorld();
		WP3_D_Update2D(_pFrameBuffer);
		break;
	case 2:
		WP3_D_Update2D(_pFrameBuffer);
		break;
	case 3:
		WP3_D_Update3D(_pFrameBuffer, uFrameInterval);
		break;
	}
	return 0;
}

void WP3_D_OnShutdown(int appId)
{
	int cn = 0;
	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		if(WP3_D.m_OBJ[cn] != NULL)
		{
			WPFishStatus_Del(WP3_D.m_OBJ[cn]);
			WP3_D.m_OBJ[cn] = NULL;
		}
	}
	
	if(WP3_D.m_Event != NULL)
	{
		CQueue_Del(WP3_D.m_Event);
		WP3_D.m_Event = NULL;
	}
	
	if(WP3_D.m_WP != NULL)
	{
		WPFishStatus_Del(WP3_D.m_WP);
		WP3_D.m_WP = NULL;
	}
	
	if(WP3_D.m_AniInfo != NULL)
	{
		CArray_Del(WP3_D.m_AniInfo);
		WP3_D.m_AniInfo = NULL;
	}

	if(WP3_D.pStatusArrayPool != NULL)
	{
		CDel(WP3_D.pStatusArrayPool);
		WP3_D.pStatusArrayPool = NULL;
	}

	if(WP3_D.pStatusArray != NULL)
	{
		CDel(WP3_D.pStatusArray);
		WP3_D.pStatusArray = NULL;
	}
	
	if(pWP3_D_StatusArrayPool != NULL)
	{
		CDel(pWP3_D_StatusArrayPool);
		pWP3_D_StatusArrayPool = NULL;
	}
	
	if(pWP3_D_StatusArray != NULL)
	{
		CDel(pWP3_D_StatusArray);
		pWP3_D_StatusArray = NULL;
	}

	V3Retained_End(appId);
}



#ifdef __cplusplus
}
#endif
