//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3-A
// File        : WP3-A-GameApp.c
// Description : 手機燈塔桌布 -- 遊戲主架構
// Author      : Ray
// Create      : 2010-11-29
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

#include "WP3-A-GameApp.h"
#include "V3DataDef.h"
#include "V3Retained.h"
#include "CUtils.h"
#include "CNodeStatus.h"
#include "WP3-A-Name.h"
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
		WP3_A_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	PC.m_uScrHeight = pPC->m_uScrHeight;
	PC.m_uScrWidth = pPC->m_uScrWidth;
	PC.m_pFrameBuffer = pPC->m_pFrameBuffer;
	PC.m_pMemBuffer = NULL;
	PC.m_MemSize = 0;

	WP3_A_PrepareConfig(&PC);
	WP3_A_OnStartup();

	return 0;
}

int IGGame_OnUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE)
{
#ifdef WIN32
	{
		SYSTEMTIME sys_time;
		GetLocalTime(&sys_time);
		WP3_A_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}
#endif

	while (uNumSysEvents--) {
		if(WP3_A.m_bLoadWorld == 2)WP3_A_PostEvent(pSE->m_uEventID, pSE->m_uTime, pSE->m_uData1, pSE->m_uData2);
	}

	//The resolution of the GetTickCount function is limited to the resolution of the system timer, which is typically in the range of 10 milliseconds to 16 milliseconds
	//這樣才不會造成時間差 = 0
	if (uFrameInterval > 0)
	{
		V3Retained *rr = V3Retained_GetInstance();
		WP3_A_OnUpdate(rr->PC.m_pFrameBuffer, uFrameInterval * 4800 / 32768);
	}

	return 0;
}

void IGGame_OnShutdown(void)
{
	WP3_A_OnShutdown();
}

#endif

//////////////////////////////////////////////////////// IGGame Framework Callback //////////////////////////////////////////

struct _WP3_A WP3_A;

#define ENGINE_BUFFER_SIZE 8*1024*1024
//static unsigned char s_engineMemBuf[ENGINE_BUFFER_SIZE];

int WP3_A_PrepareConfig(IGV3Config *pPC)
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

void WP3_A_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	char WP3_A_g_DebugMessage[128] = {0};
	sprintf(WP3_A_g_DebugMessage, _TEXT("[%010d] "), WP3_A.m_GameTime);
	sprintf(&WP3_A_g_DebugMessage[13], pFmt, _p1, _p2, _p3, _p4);
	OutputDebugString(WP3_A_g_DebugMessage);
#endif
}

CArrayPool *pWP3_A_StatusArrayPool = NULL;
IGSysEvent *pWP3_A_StatusArray = NULL;

void WP3_A_InitArrayPool(void)
{
	if(pWP3_A_StatusArrayPool == NULL)pWP3_A_StatusArrayPool = CNew(sizeof(CArrayPool));
	if(pWP3_A_StatusArray == NULL)pWP3_A_StatusArray = CNew(sizeof(IGSysEvent) * MAX_ARRAY_POOL);
	CArrayPool_Init(pWP3_A_StatusArrayPool, (void *) pWP3_A_StatusArray, sizeof(IGSysEvent) * MAX_ARRAY_POOL, sizeof(IGSysEvent));
}

IGSysEvent *WP3_A_Alloc(void)
{
	return (IGSysEvent *) CArrayPool_Alloc(pWP3_A_StatusArrayPool);
}

void WP3_A_Free(IGSysEvent *_this)
{
	CArrayPool_Free(pWP3_A_StatusArrayPool, (void *) _this);
}

void WP3_A_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2)
{
	IGSysEvent *pGE = WP3_A_Alloc();
	
	if(pGE == NULL)
	{
		WP3_A_InitArrayPool();
		pGE = WP3_A_Alloc();
	}

	pGE->m_uEventID = _Id;
	if (_Time == 0L)
		pGE->m_uTime = WP3_A.m_GameTime;
	else
		pGE->m_uTime = _Time;
	pGE->m_uData1 = _Data1;
	pGE->m_uData2 = _Data2;

	CQueue_Push(WP3_A.m_Event, (void *) pGE);
}

void WP3_A_ClearPendingEvents(void)
{
	CQueue_Clear(WP3_A.m_Event);
}

IGSysEvent *WP3_A_GetEvent(void)
{
	IGSysEvent *pR;

	pR = (IGSysEvent *) CQueue_Pop(WP3_A.m_Event);

	return pR;
}

V3Retained *WP3_A_rr = NULL;

//=====================
//On Startup
//=====================
int WP3_A_OnStartup(void)
{
	WP3_A_InitArrayPool();
	CMemset(&WP3_A, sizeof(WP3_A), 0);
	WP3_A.iRayTime = 0L;
	V3Retained_LoadBackgroundTexture(png_WP3_A_back);
	return 0;
}

int WP3_A_LoadWorld(void)
{
	V3Texture *tex = NULL;
	CArray *texs;
	V3World *world;
	int cn = 0;
	int scaleValue = 0;

	texs = V3Textures_New(NULL);

	for (cn = 0; cn < COUNT_BMP; cn = cn + 1)
	{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
		CArray_Add(texs, (void *) V3Texture_New(WP_NameStruct.bmp_array[cn], WP_NameStruct.file_bmp[cn], MASK_555_RED, MASK_555_GREEN, MASK_555_BLUE, WP_NameStruct.keycolor[cn]));
#else
		CArray_Add(texs, (void *) V3Texture_New(WP_NameStruct.bmp_array[cn], WP_NameStruct.file_bmp[cn], MASK_565_RED, MASK_565_GREEN, MASK_565_BLUE, WP_NameStruct.keycolor[cn]));
#endif
	}
	world = V3World_New(igf_WP3_A, texs, tex, "Scene Root", "Camera_dummy", "ANIMATE0");

	V3Retained_LoadWorld(world);

	V3World_Del(world);

	WP3_A_rr = V3Retained_GetInstance();
	IGCamera_setPerspectiveFieldOfView(WP3_A_rr->m_Mem, WP3_A_rr->m_Camera, (igreal) (IG_ONE / 0.8f), &WP3_A.err);

	WP3_A.m_Ray = (IGNode *) V3Retained_GetGroup("ray_dummy");
	WP3_A.m_Whale = (IGNode *) V3Retained_GetGroup("whale_A");
	WP3_A.m_Bird = (IGNode *) V3Retained_GetGroup("Bird_All");
	WP3_A.m_Bird01 = (IGNode *) V3Retained_GetGroup("Bird_All01");
	WP3_A.m_worldrotate = (IGNode *)V3Retained_GetGroup("worldrotate");

	for (cn = 0; cn < COUNT_PATH; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.path_name_Obj[cn]);
		WP3_A.m_Path[cn] = pNode;
	}

	for (cn = 0; cn < COUNT_WHALE_POSITION; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.node_name_WhalePosition[cn]);
		WP3_A.m_WhalePosition[cn] = pNode;
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
	WP3_A.m_Event = CQueue_New(DEFAULT_QUEUE_SIZE);

	WP3_A.m_AniInfo = V3Retained_GenerateAniInfo();

	WP3_A.m_DegreeInc = 1;
	WP3_A.m_TimeFactor = 1;
	WP3_A.m_bLoadWorld = 0;
	WP3_A.m_CurrentWhalePosition = 0;
	WP3_A.m_CurrentBirdPath = 0;

	WP3_A.m_Scale[0] = scaleValue;
	WP3_A.m_Scale[1] = scaleValue;
	WP3_A.m_Scale[2] = scaleValue;

	WP3_A_ScaleXYZ(0.06f);

	V3Retained_ActiveBackgroundTexture();

	return 0;
}

IGU32 WP3_A_GetElapsedTime(IGU32 _tick)
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

void WP3_A_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second)
{
	WP3_A.m_Hour = _hour;
}

int WP3_A_GetHour(void)
{
	return WP3_A.m_Hour;
}

int WP3_A_Random(int _min, int _max)
{
	int rnd_value = 0;

	rnd_value = rand() % (_max - _min + 1) + _min;
	return rnd_value;
}

void WP3_A_EventHTouchMove(int _pixel)
{
	IGErr err = IGERR_NONE;
	int iPrev = WP3_A.m_HDegree;

	WP3_A.m_HDegree = WP3_A.m_HDegree + _pixel * WP3_A.m_DegreeInc;
	//horizontal
	IGNode_rotateZ(WP3_A_rr->m_Mem, (IGNode *) WP3_A_rr->m_CameraControl, (igreal) (IG_PI * (WP3_A.m_HDegree - iPrev) / 180.0f), &err);
}

void WP3_A_VTouchMove(int _pixel)
{
	IGErr err = IGERR_NONE;
	int iPrev = WP3_A.m_VDegree;
	
	WP3_A.m_VDegree = WP3_A.m_VDegree + _pixel;
	IGNode_rotateX(WP3_A_rr->m_Mem, (IGNode *) WP3_A_rr->m_CameraControl, (igreal) (IG_PI * (WP3_A.m_VDegree - iPrev) / 180.0f), &err);
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

void WP3_A_ScaleXYZ(float fNum)
{
	WP3_A.m_Scale[0] = (igreal) (fNum * IG_ONE);
	WP3_A.m_Scale[1] = (igreal) (fNum * IG_ONE);
	WP3_A.m_Scale[2] = (igreal) (fNum * IG_ONE);
}


void WP3_A_Update2D(unsigned char *_pFrameBuffer)
{
	V3Retained_Bind(_pFrameBuffer);
	V3UI_DrawImage2DCenter(WP3_A_rr->m_BackgroundTexture, 1.0f);
}


int WP3_A_Update3D(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	IGErr err = IGERR_NONE;

	int cn;
	IGSysEvent *pSE = NULL;
	AniInfo *ani_info0 = CNamedObjArray_Get(WP3_A.m_AniInfo, 0);
	AniInfo *ani_info1 = CNamedObjArray_Get(WP3_A.m_AniInfo, 1);
	igreal Position[3], Position01[3];

	V3Retained_Bind(_pFrameBuffer);
	WP3_A.m_ElapsedTime = uFrameInterval;
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	//WP3_A.m_ElapsedTime = DebugInterval();
#endif
	WP3_A.m_GameTime = WP3_A.m_GameTime + WP3_A.m_ElapsedTime / WP3_A.m_TimeFactor;

	// process platform events, only test touch down event (mouse left button down)
	while ((pSE = CQueue_Pop(WP3_A.m_Event)) != NULL)
	{
		switch (pSE->m_uEventID)
		{
		case IGFK_TOUCH1_DOWN :
			WP3_A.iMouseX = pSE->m_uData1;
			WP3_A.iMouseY = pSE->m_uData2; 
			break;
		case IGFK_TOUCH1_MOVE :
			WP3_A_EventHTouchMove(pSE->m_uData1 - WP3_A.iMouseX);
			WP3_A.iMouseX = pSE->m_uData1;
			WP3_A.iMouseY = pSE->m_uData2; 
			break;
		}

		WP3_A_Free(pSE);
	}

	//更新光線動畫資訊
	WP3_A.iRayTime = WP3_A.iRayTime + WP3_A.m_ElapsedTime / WP3_A.m_TimeFactor;
	WP3_A.iRayTime = WP3_A.iRayTime % ani_info0->m_Duration;

	//更新各模型動畫資料
	V3Retained_UpdateNode((IGNode *) WP3_A.m_Ray,   "ANIMATE0", WP3_A.iRayTime);
	V3Retained_UpdateNode((IGNode *) WP3_A.m_worldrotate, "ANIMATE0", WP3_A.iRayTime);//借用光線的時間-.,-y
	V3Retained_UpdateNode((IGNode *) WP3_A.m_Whale, "ANIMATE1", WP3_A.m_GameTime % ani_info1->m_Duration);
	V3Retained_UpdateNode((IGNode *) WP3_A.m_Bird,  "ANIMATE1", WP3_A.m_GameTime % ani_info1->m_Duration);
	V3Retained_UpdateNode((IGNode *) WP3_A.m_Bird01,  "ANIMATE1", WP3_A.m_GameTime % ani_info1->m_Duration);

	//變換鯨魚位置
	if (WP3_A.m_GameTime % ani_info1->m_Duration < 10)
		WP3_A.m_CurrentWhalePosition = RandomEvent_Random(0, 9);
	
	IGNode_getPosition(V3Retained_GetMem(), WP3_A.m_WhalePosition[WP3_A.m_CurrentWhalePosition], Position, &err);
	Position[2] -= 200;//微調鯨魚的垂直座標, 讓鯨魚沉到水面下
	IGNode_setPosition(V3Retained_GetMem(), WP3_A.m_Whale, Position, &err);

	//變換鳥群路徑
	if (WP3_A.m_GameTime % ani_info0->m_Duration < 10)
	{
		WP3_A.m_CurrentBirdPath = RandomEvent_Random(0, 2);
		WP3_A.m_CurrentBirdPath01 = RandomEvent_Random(0, 2);
		//用來避免挑選到相同路徑
		if(WP3_A.m_CurrentBirdPath == WP3_A.m_CurrentBirdPath01)
		{
			if(WP3_A.m_CurrentBirdPath01 == 2)
				WP3_A.m_CurrentBirdPath01 = 0;
			else
			{
				//WP3_A.m_CurrentBirdPath01++; edit by Odin
				WP3_A.m_CurrentBirdPath01 = WP3_A.m_CurrentBirdPath01 + 1;
			}
				
		}
	}

	//WP3_A_ScaleXYZ(0.05);
	IGNode_setScale(WP3_A_rr->m_Mem, WP3_A.m_Bird, WP3_A.m_Scale, &err);
	IGNode_setScale(WP3_A_rr->m_Mem, WP3_A.m_Bird01, WP3_A.m_Scale, &err);
	
	//設定鳥(bird)的路徑
	{
		//static float a = 0, b = 0, c = 0;
		float Pos[3];
		IGNode *pPathNode = WP3_A.m_Path[WP3_A.m_CurrentBirdPath];
		V3Retained_GetPathPosition(pPathNode, "ANIMATE0", WP3_A.m_GameTime % ani_info0->m_Duration, Pos);
		if (WP3_A.m_Bird)
			for (cn = 0; cn < 12; cn = cn + 1)
				WP3_A.m_Bird->m_oriMat[cn] = pPathNode->m_oriMat[cn];

		Position[0] = (igreal) (Pos[0] * IG_ONE);
		Position[1] = (igreal) (Pos[1] * IG_ONE);
		Position[2] = (igreal) (Pos[2] * IG_ONE);

		IGNode_setPosition(V3Retained_GetMem(), WP3_A.m_Bird, Position, &err);
	}
	
	//設定鳥(bird01)的路徑
	{
		float Pos01[3];
		IGNode *pPathNode01 = WP3_A.m_Path[WP3_A.m_CurrentBirdPath01];
		V3Retained_GetPathPosition(pPathNode01, "ANIMATE0", WP3_A.m_GameTime % ani_info0->m_Duration, Pos01);
		if (WP3_A.m_Bird01)
			for (cn = 0; cn < 12; cn = cn + 1)
				WP3_A.m_Bird01->m_oriMat[cn] = pPathNode01->m_oriMat[cn];

		Position01[0] = (igreal) (Pos01[0] * IG_ONE);
		Position01[1] = (igreal) (Pos01[1] * IG_ONE);
		Position01[2] = (igreal) (Pos01[2] * IG_ONE);
		IGNode_setPosition(V3Retained_GetMem(), WP3_A.m_Bird01, Position01, &err);
	}

	V3Retained_Render();

	return 0;
}
int WP3_A_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	WP3_A_rr = V3Retained_GetInstance();

	switch (WP3_A.m_bLoadWorld)
	{
	case 0 :
		WP3_A_Update2D(_pFrameBuffer);
		WP3_A.m_bLoadWorld = 1;
		break;
	case 1:
		WP3_A_LoadWorld();
		WP3_A_Update3D(_pFrameBuffer, uFrameInterval);
		WP3_A.m_bLoadWorld = 2;
		break;
	case 2:
		WP3_A_Update3D(_pFrameBuffer, uFrameInterval);
		break;
	}
		return 0;
}
void WP3_A_OnShutdown(int appId)
{
	if(WP3_A.m_AniInfo != NULL)
	{
		CArray_Del(WP3_A.m_AniInfo);
		WP3_A.m_AniInfo = NULL;
	}

	if(pWP3_A_StatusArrayPool != NULL)
	{
		CDel(pWP3_A_StatusArrayPool);
		pWP3_A_StatusArrayPool = NULL;
	}

	if(pWP3_A_StatusArray != NULL)
	{
		CDel(pWP3_A_StatusArray);
		pWP3_A_StatusArray = NULL;
	}

	V3Retained_End(appId);
}




#ifdef __cplusplus
}
#endif
