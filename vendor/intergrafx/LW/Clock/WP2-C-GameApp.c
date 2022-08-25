//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP2-C
// File        : WP2-C-GameApp.c
// Description : 手機機械鐘桌布 -- 遊戲主架構
// Author      : Ray
// Create      : 2010-11-30
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

#include "IGGame.h"

#include "WP2-C-GameApp.h"
#include "V3DataDef.h"
#include "V3Retained.h"
#include "CUtils.h"
#include "CNodeStatus.h"
#include "WP2-C-Name.h"
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

////////////////////////////////////////////////// IGGame Framework Callback for Win32 //////////////////////////////////////////

#if defined(WIN32) && !defined(_MODIS_ON_VC9_)

int IGGame_OnStartup(IGPlatformConfig *pPC)
{
	IGV3Config PC;

	{
		SYSTEMTIME sys_time;
		GetLocalTime(&sys_time);
		WP2_C_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	PC.m_uScrHeight = pPC->m_uScrHeight;
	PC.m_uScrWidth = pPC->m_uScrWidth;
	PC.m_pFrameBuffer = pPC->m_pFrameBuffer;
	PC.m_pMemBuffer = NULL;
	PC.m_MemSize = 0;

	WP2_C_PrepareConfig(&PC);
	WP2_C_OnStartup();

	return 0;
}

int IGGame_OnUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE)
{
	{
		SYSTEMTIME sys_time;
		GetLocalTime(&sys_time);
		WP2_C_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	while (uNumSysEvents--) {
		if(WP2_C.m_bLoadWorld == 2)WP2_C_PostEvent(pSE->m_uEventID, pSE->m_uTime, pSE->m_uData1, pSE->m_uData2);
	}

	//The resolution of the GetTickCount function is limited to the resolution of the system timer, which is typically in the range of 10 milliseconds to 16 milliseconds
	//這樣才不會造成時間差 = 0
	if (uFrameInterval > 0)
	{
		V3Retained *rr = V3Retained_GetInstance();
		WP2_C_OnUpdate(rr->PC.m_pFrameBuffer, uFrameInterval * 4800 / 32768);
	}

	return 0;
}

void IGGame_OnShutdown(void)
{
	V3Retained_End();
}

#endif


//////////////////////////////////////////////////////// IGGame Framework Callback //////////////////////////////////////////

struct _WP2_C WP2_C;

#define ENGINE_BUFFER_SIZE 8*1024*1024
//static unsigned char s_engineMemBuf[ENGINE_BUFFER_SIZE];

int WP2_C_PrepareConfig(IGV3Config *pPC)
{
	int err;
	IGV3Config PC;

	PC.m_uScrHeight = pPC->m_uScrHeight;
	PC.m_uScrWidth = pPC->m_uScrWidth;
	PC.m_pFrameBuffer = pPC->m_pFrameBuffer;

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

void WP2_C_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	char WP2_C_g_DebugMessage[128] = {0};
	sprintf(WP2_C_g_DebugMessage, _TEXT("[%010d] "), WP2_C.m_GameTime);
	sprintf(&WP2_C_g_DebugMessage[13], pFmt, _p1, _p2, _p3, _p4);
	OutputDebugString(WP2_C_g_DebugMessage);
#endif
}

CArrayPool *pWP2_C_StatusArrayPool = NULL;
NodeAniStatus *pWP2_C_StatusArray = NULL;

void WP2_C_InitArrayPool(void)
{
	if(pWP2_C_StatusArrayPool == NULL) pWP2_C_StatusArrayPool = CNew(sizeof(CArrayPool));
	if(pWP2_C_StatusArray == NULL) pWP2_C_StatusArray = CNew(sizeof(NodeAniStatus) * MAX_ARRAY_POOL);
	CArrayPool_Init(pWP2_C_StatusArrayPool, (void *) pWP2_C_StatusArray, sizeof(IGSysEvent) * MAX_ARRAY_POOL, sizeof(IGSysEvent));
}

IGSysEvent *WP2_C_Alloc(void)
{
	return (IGSysEvent *) CArrayPool_Alloc(pWP2_C_StatusArrayPool);
}

void WP2_C_Free(IGSysEvent *_this)
{
	CArrayPool_Free(pWP2_C_StatusArrayPool, (void *) _this);
}

void WP2_C_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2)
{
	IGSysEvent *pGE = WP2_C_Alloc();

	if(pGE == NULL)
	{
		WP2_C_InitArrayPool();
		pGE = WP2_C_Alloc();
	}

	pGE->m_uEventID = _Id;
	if (_Time == 0L)
		pGE->m_uTime = WP2_C.m_GameTime;
	else
		pGE->m_uTime = _Time;
	pGE->m_uData1 = _Data1;
	pGE->m_uData2 = _Data2;

	CQueue_Push(WP2_C.m_Event, (void *) pGE);
}

void WP2_C_ClearPendingEvents(void)
{
	CQueue_Clear(WP2_C.m_Event);
}

IGSysEvent *WP2_C_GetEvent(void)
{
	IGSysEvent *pR;

	pR = (IGSysEvent *) CQueue_Pop(WP2_C.m_Event);

	return pR;
}

V3Retained *WP2_C_rr = NULL;

int WP2_C_OnStartup(void)
{
	WP2_C_InitArrayPool();
	CMemset(&WP2_C, sizeof(WP2_C), 0);
	WP2_C.add = 0;
	WP2_C.countback = 0;
	WP2_C.iGearTime = 0L;
	V3Retained_LoadBackgroundTexture(png_bg2);
	WP2_C.m_bLoadWorld = 0;
	return 0;
}
int WP2_C_LoadWorld(void)
{
	//IGErr err;
	V3Texture *tex = NULL;
	CArray *texs;
	V3World *world;


	int cn = 0;
	texs = V3Textures_New(NULL);

	for (cn = 0; cn < COUNT_BMP; cn = cn + 1)
	{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
		CArray_Add(texs, (void *) V3Texture_New(WP2_C_Name.bmp_array[cn], WP2_C_Name.file_bmp[cn], MASK_555_RED, MASK_555_GREEN, MASK_555_BLUE, WP2_C_Name.keycolor[cn]));
#else
		CArray_Add(texs, (void *) V3Texture_New(WP2_C_Name.bmp_array[cn], WP2_C_Name.file_bmp[cn], MASK_565_RED, MASK_565_GREEN, MASK_565_BLUE, WP2_C_Name.keycolor[cn]));
#endif
	}

	
	world = V3World_New(igf_WP2_C, texs, tex, "Scene Root", "Camera_control", "ANIMATE0");

	V3Retained_LoadWorld(world);

	V3World_Del(world);

	WP2_C_rr = V3Retained_GetInstance();

	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP2_C_Name.node_name_Obj[cn]);
		WP2_C.m_Obj[cn] = pNode;
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
	WP2_C.m_Event = CQueue_New(DEFAULT_QUEUE_SIZE);

	WP2_C.m_AniInfo = V3Retained_GenerateAniInfo();

	WP2_C.m_DegreeInc = 1;
	WP2_C.m_TimeFactor = 1;
	WP2_C.m_bTouchMove = 0;
	WP2_C.m_TouchTimeStart = 0;
	WP2_C.m_GearTimeStart = 0;
	WP2_C.m_ZoomTimeStart = 0;
	WP2_C.m_MoveBackTimeStart = 0;


	return 0;
}

IGU32 WP2_C_GetElapsedTime(IGU32 _tick)
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

void WP2_C_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second)
{
	WP2_C.m_Hour = _hour;
	CTime_Set(&WP2_C.m_Time, _hour, _minute, _second);
}

int WP2_C_GetHour(void)
{
	return WP2_C.m_Hour;
}

void Process_EventHTouchMove(int _pixel)
{
	int iPrev = WP2_C.m_HDegree;

	WP2_C.m_HDegree = WP2_C.m_HDegree + _pixel * WP2_C.m_DegreeInc;

	V3Retained_RotateCamera((float) (WP2_C.m_HDegree - iPrev), 0);
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


void WP2_C_Update2D(unsigned char *_pFrameBuffer)
{
	V3Retained_Bind(_pFrameBuffer);
	V3UI_DrawImage2DCenter(WP2_C_rr->m_BackgroundTexture, 1.0f);
}

int WP2_C_Update3D(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	IGErr err = IGERR_NONE;
	IGSysEvent *pSE = NULL;
	AniInfo *ani_info0 = CNamedObjArray_Get(WP2_C.m_AniInfo, 0);
	AniInfo *ani_info1 = CNamedObjArray_Get(WP2_C.m_AniInfo, 1);


	V3Retained_Bind(_pFrameBuffer);
	WP2_C.m_ElapsedTime = uFrameInterval;
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	//WP2_C.m_ElapsedTime = DebugInterval();
#endif
	WP2_C.m_GameTime = WP2_C.m_GameTime + WP2_C.m_ElapsedTime / WP2_C.m_TimeFactor;

	// process platform events, only test touch down event (mouse left button down)
	while ((pSE = (IGSysEvent *) CQueue_Pop(WP2_C.m_Event)) != NULL)
	{
		switch (pSE->m_uEventID)
		{
		
		case IGFK_TOUCH1_DOWN :
			WP2_C.m_TouchTimeStart = WP2_C.m_GameTime;
			break;

		case IGFK_TOUCH1_UP :
			WP2_C.iMouseX = pSE->m_uData1;
			WP2_C.iMouseY = pSE->m_uData2;
			WP2_C.m_TouchTimeStart = 0;
			if (WP2_C.m_GearTimeStart == 0 && WP2_C.m_bTouchMove == 0)
				WP2_C.m_ZoomTimeStart = WP2_C.m_GameTime;
			if (WP2_C.m_bTouchMove == 1)
			{
				WP2_C.m_bTouchMove = 0;
				WP2_C.m_MoveBackTimeStart = WP2_C.m_GameTime;
			}

			WP2_C.countback = 1;
	
			break;

		case IGFK_TOUCH1_MOVE :
			if(-16000 < WP2_C.add)
			{
				if(WP2_C.iMouseX < (int)pSE->m_uData1)
				{
					WP2_C.add = WP2_C.add + WP2_C.iAngle;
					WP2_C.iAngle = -3000;
					IGNode_rotateZ(WP2_C_rr->m_Mem, (IGNode *) WP2_C_rr->m_CameraControl, WP2_C.iAngle, &err);
					WP2_C.iMouseX = pSE->m_uData1;
				}

			}
			if(WP2_C.add < 16000)
			{
				if(WP2_C.iMouseX > (int)pSE->m_uData1)
				{
					WP2_C.add = WP2_C.add + WP2_C.iAngle;
					WP2_C.iAngle = 3000;
					IGNode_rotateZ(WP2_C_rr->m_Mem, (IGNode *) WP2_C_rr->m_CameraControl, WP2_C.iAngle, &err);
					WP2_C.iMouseX = pSE->m_uData1;
					WP2_C.iMouseY = pSE->m_uData2; 
				}
			}
			break;

		}

		WP2_C_Free(pSE);
	}

	//整分齒輪加速十秒 or 快轉事件觸發
	if ((WP2_C.m_TouchTimeStart != 0) && (WP2_C.m_GameTime - WP2_C.m_TouchTimeStart) > 2000)
	{
		WP2_C.m_TouchTimeStart = 0;
		WP2_C.m_GearTimeStart = WP2_C.m_GameTime;
	}
	if ((WP2_C.m_GearTimeStart != 0) && (WP2_C.m_GameTime - WP2_C.m_GearTimeStart) > 5000)
		WP2_C.m_GearTimeStart = 0;

		WP2_C.iGearTime = WP2_C.iGearTime + WP2_C.m_ElapsedTime;
		WP2_C.iGearTime = WP2_C.iGearTime % ani_info0->m_Duration;




	if(WP2_C.countback == 1)
	{
		if(WP2_C.add > 0)
		{
			if(WP2_C.add != 0)
			{
			WP2_C.add = WP2_C.add + WP2_C.iAngle;
			WP2_C.iAngle = -1000;
			IGNode_rotateZ(WP2_C_rr->m_Mem, (IGNode *) WP2_C_rr->m_CameraControl, WP2_C.iAngle, &err);
			}

		}
		if(WP2_C.add <= 0)
		{
			if(WP2_C.add != 0)
			{
				WP2_C.add = WP2_C.add + WP2_C.iAngle;
				WP2_C.iAngle = 1000;
				IGNode_rotateZ(WP2_C_rr->m_Mem, (IGNode *) WP2_C_rr->m_CameraControl, WP2_C.iAngle, &err);
			}
			else
			{
				WP2_C.countback = 0;
				V3Retained_UpdateNode((IGNode *)WP2_C_rr->m_CameraControl, "ANIMATE0", 0);
			}
		}
	}

	V3Retained_UpdateNode((IGNode *) WP2_C.m_Obj[0], "ANIMATE0", (WP2_C.m_GameTime) % ani_info0->m_Duration);
	V3Retained_UpdateNode((IGNode *) WP2_C.m_Obj[1], "ANIMATE0", (WP2_C.m_GameTime) % ani_info0->m_Duration);
	V3Retained_UpdateNode((IGNode *) WP2_C.m_Obj[2], "ANIMATE0", (WP2_C.m_GameTime) % ani_info0->m_Duration);
	V3Retained_UpdateNode((IGNode *) WP2_C.m_Obj[3], "ANIMATE0", WP2_C.iGearTime);
	V3Retained_UpdateNode((IGNode *) WP2_C.m_Obj[4], "ANIMATE1", (WP2_C.m_GameTime) % ani_info1->m_Duration);


	{
		float deg_hh, deg_mm, deg_ss;
		//igreal value_cos, value_sin;

		deg_hh = (WP2_C.m_Time.m_Hour % 12 + WP2_C.m_Time.m_Min / 60.0f) * 2.0f / 12.0f;
		deg_mm = (WP2_C.m_Time.m_Min + WP2_C.m_Time.m_Sec / 60.0f) * 2.0f / 60.0f;
		deg_ss = WP2_C.m_Time.m_Sec * 2.0f / 60.0f;
		IGNode_rotateY(V3Retained_GetMem(), (IGNode *) WP2_C.m_Obj[0], (igreal) (IG_PI * deg_hh), &err);
		IGNode_rotateY(V3Retained_GetMem(), (IGNode *) WP2_C.m_Obj[1], (igreal) (IG_PI * deg_mm), &err);
		IGNode_rotateY(V3Retained_GetMem(), (IGNode *) WP2_C.m_Obj[2], (igreal) (IG_PI * deg_ss), &err);

	}

	V3Retained_Render();
	return 0;
}
int WP2_C_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	IGErr err = IGERR_NONE;
	WP2_C_rr = V3Retained_GetInstance();

	switch (WP2_C.m_bLoadWorld)
	{
	case 0 :
		WP2_C_Update2D(_pFrameBuffer);
		WP2_C.m_bLoadWorld = 1;

		break;
	case 1:
		WP2_C_LoadWorld();
		V3Retained_ActiveBackgroundTexture();
		IGCamera_setPerspectiveFieldOfView(WP2_C_rr->m_Mem, WP2_C_rr->m_Camera, (igreal)(IG_ONE * 0.8), &err);
		WP2_C_Update3D(_pFrameBuffer, uFrameInterval);
		WP2_C.m_bLoadWorld = 2;

		break;
	case 2:
		WP2_C_Update3D(_pFrameBuffer, uFrameInterval);
		break;

	}
		return 0;
}
void WP2_C_OnShutdown(int appId)
{	
	if(WP2_C.m_AniInfo != NULL)
	{
		CArray_Del(WP2_C.m_AniInfo);
		WP2_C.m_AniInfo = NULL;
	}

	if(pWP2_C_StatusArrayPool != NULL)
	{
		CDel(pWP2_C_StatusArrayPool);
		pWP2_C_StatusArrayPool = NULL;
	}
	
	if(pWP2_C_StatusArray != NULL)
	{
		CDel(pWP2_C_StatusArray);
		pWP2_C_StatusArray = NULL;
	}

	V3Retained_End(appId);
}



#ifdef __cplusplus
}
#endif
