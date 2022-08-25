//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3-C
// File        : WP3_C_GameApp.c
// Description : 手機太陽系桌布 -- 遊戲主架構
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
#include "IGRay.h"
#include "IGSprite.h"

#include "IGGame.h"

#include "WP3-C-GameApp.h"
#include "V3DataDef.h"
#include "V3Retained.h"
#include "CUtils.h"
#include "CNodeStatus.h"
#include "WP3-C-Name.h"
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
		WP3_C_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	PC.m_uScrHeight = pPC->m_uScrHeight;
	PC.m_uScrWidth = pPC->m_uScrWidth;
	PC.m_pFrameBuffer = pPC->m_pFrameBuffer;
	PC.m_pMemBuffer = NULL;
	PC.m_MemSize = 0;

	WP3_C_PrepareConfig(&PC);
	WP3_C_OnStartup();

	return 0;
}

int IGGame_OnUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE)
{
	{
		SYSTEMTIME sys_time;
		GetLocalTime(&sys_time);
		WP3_C_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	while (uNumSysEvents--) {
		if(WP3_C.m_bLoadWorld == 2)WP3_C_PostEvent(pSE->m_uEventID, pSE->m_uTime, pSE->m_uData1, pSE->m_uData2);
	}

	//The resolution of the GetTickCount function is limited to the resolution of the system timer, which is typically in the range of 10 milliseconds to 16 milliseconds
	//這樣才不會造成時間差 = 0
	if (uFrameInterval > 0)
	{
		V3Retained *rr = V3Retained_GetInstance();
		WP3_C_OnUpdate(rr->PC.m_pFrameBuffer, uFrameInterval * 4800 / 32768);
	}

	return 0;
}

void IGGame_OnShutdown(void)
{
	WP3_C_OnShutdown();
}

#endif

//////////////////////////////////////////////////////// IGGame Framework Callback //////////////////////////////////////////

struct _WP3_C WP3_C;

#define ENGINE_BUFFER_SIZE 8*1024*1024

int WP3_C_PrepareConfig(IGV3Config *pPC)
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

void WP3_C_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	char WP3_C_g_DebugMessage[128] = {0};
	sprintf(WP3_C_g_DebugMessage, _TEXT("[%010d] "), WP3_C.m_GameTime);
	sprintf(&WP3_C_g_DebugMessage[13], pFmt, _p1, _p2, _p3, _p4);
	OutputDebugString(WP3_C_g_DebugMessage);
#endif
}

CArrayPool *pWP3_C_StatusArrayPool = NULL;
IGSysEvent *pWP3_C_StatusArray = NULL;

void WP3_C_InitArrayPool(void)
{
	if(pWP3_C_StatusArrayPool == NULL)pWP3_C_StatusArrayPool = CNew(sizeof(CArrayPool));
	if(pWP3_C_StatusArray == NULL)pWP3_C_StatusArray = CNew(sizeof(IGSysEvent) * MAX_ARRAY_POOL);
	CArrayPool_Init(pWP3_C_StatusArrayPool, (void *) pWP3_C_StatusArray, sizeof(IGSysEvent) * MAX_ARRAY_POOL, sizeof(IGSysEvent));
}

IGSysEvent *WP3_C_Alloc(void)
{
	return (IGSysEvent *) CArrayPool_Alloc(pWP3_C_StatusArrayPool);
}

void WP3_C_Free(IGSysEvent *_this)
{
	CArrayPool_Free(pWP3_C_StatusArrayPool, (void *) _this);
}

void WP3_C_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2)
{
	IGSysEvent *pGE = WP3_C_Alloc();

	if(pGE == NULL)
	{
		WP3_C_InitArrayPool();
		pGE = WP3_C_Alloc();
	}

	pGE->m_uEventID = _Id;
	if (_Time == 0L)
		pGE->m_uTime = WP3_C.m_GameTime;
	else
		pGE->m_uTime = _Time;
	pGE->m_uData1 = _Data1;
	pGE->m_uData2 = _Data2;

	CQueue_Push(WP3_C.m_Event, (void *) pGE);
}

void WP3_C_ClearPendingEvents(void)
{
	CQueue_Clear(WP3_C.m_Event);
}

IGSysEvent *WP3_C_GetEvent(void)
{
	IGSysEvent *pR;

	pR = (IGSysEvent *) CQueue_Pop(WP3_C.m_Event);

	return pR;
}

V3Retained *WP3_C_rr = NULL;

int WP3_C_OnStartup(void)
{
	WP3_C_InitArrayPool();
	CMemset(&WP3_C, sizeof(WP3_C), 0);
	WP3_C.countspeed = 1;
	WP3_C.rospeed = 0.1f;

	V3Retained_LoadBackgroundTexture(png_WP3_C_bg);
	return 0;
}
int WP3_C_LoadWorld(void)
{
	IGErr err;
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

	world = V3World_New(igf_WP3_C, texs, tex, "Scene Root", "Camera_control", "ANIMATE0");

	V3Retained_LoadWorld(world);

	V3World_Del(world);

	WP3_C_rr = V3Retained_GetInstance();

	IGCamera_setPerspectiveFieldOfView(WP3_C_rr->m_Mem, WP3_C_rr->m_Camera, (igreal)(IG_ONE * 1.5), &err);

	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.node_name_Obj[cn]);
		WP3_C.m_Obj[cn] = pNode;

		if (pNode != NULL)
		{
			WP3_C.m_GameObj[cn] = IGNewAGameObject(WP3_C_rr->m_Mem, &err);
			IGAttachRootNodeToGameObject(WP3_C_rr->m_Mem, WP3_C.m_GameObj[cn], (IGNode *) WP3_C_rr->m_Root, pNode, &err);
		}
	}

	for (cn = 0; cn < COUNT_STONE; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.node_name_Stone[cn]);
		WP3_C.m_Stone[cn] = pNode;
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
	WP3_C.m_Event = CQueue_New(DEFAULT_QUEUE_SIZE);

	WP3_C.m_AniInfo = V3Retained_GenerateAniInfo();
	
	WP3_C.m_bLoadWorld = 0;
	WP3_C.m_GameTime = 0;
	WP3_C.m_DegreeInc = 1;
	WP3_C.m_TimeFactor = 1;
	WP3_C.m_Direction = -1;
	WP3_C.iStoneTime = 0L;
	return 0;
}

IGU32 WP3_C_GetElapsedTime(IGU32 _tick)
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

void WP3_C_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second)
{
	WP3_C.m_Hour = _hour;
}

int WP3_C_GetHour(void)
{
	return WP3_C.m_Hour;
}

void WP3_C_RandomStone(void)
{
	int cn;
	AniInfo *ani_info1 = CNamedObjArray_Get(WP3_C.m_AniInfo, 0);
	
		if(WP3_C.iStoneTime < (long) ani_info1->m_Duration)
		{
			WP3_C.iStoneTime = WP3_C.iStoneTime + (long) WP3_C.m_ElapsedTime + 100L;
		}


		for(cn = 0; cn < COUNT_STONE; cn = cn + 1)
		{
			V3Retained_UpdateNode((IGNode *) WP3_C.m_Stone[cn], "ANIMATE0", WP3_C.iStoneTime);
		}
}

void WP3_C_RotateSun(void)
{

	IGErr err = IGERR_NONE;
	IGNode *kNode = NULL;

	igreal angle[4];

	angle[0] = 0L;
	angle[1] = 100L;
	angle[2] = 0L;
	angle[3] = 500L;
	kNode = (IGNode *) V3Retained_GetGroup("sun1www");
	IGNode_rotateXYZ ( V3Retained_GetMem(), kNode, angle, &err);
}

void WP3_C_Update2D(unsigned char *_pFrameBuffer)
{
	V3Retained_Bind(_pFrameBuffer);
	V3UI_DrawImage2DCenter(WP3_C_rr->m_BackgroundTexture, 1.0f);
}

int WP3_C_Update3D(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	IGErr err = IGERR_NONE;
	
	int cn;
	IGSysEvent *pSE = NULL;
	AniInfo *ani_info0 = CNamedObjArray_Get(WP3_C.m_AniInfo, 0);
	AniInfo *ani_info1 = CNamedObjArray_Get(WP3_C.m_AniInfo, 1);

	V3Retained_Bind(_pFrameBuffer);
	WP3_C.m_ElapsedTime = uFrameInterval;
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	//WP3_C.m_ElapsedTime = DebugInterval();
#endif
	WP3_C.m_GameTime = WP3_C.m_GameTime + WP3_C.m_ElapsedTime / WP3_C.m_TimeFactor;
	
	
	WP3_C_RandomStone();
	WP3_C_RotateSun();

	IGCamera_setPerspectiveFieldOfView(WP3_C_rr->m_Mem, WP3_C_rr->m_Camera, (igreal) (IG_ONE * 1.1f), &err);
	//WP3_C_AddDebugMessage("%d   %d\n",countspeed, WP3_C.m_GameTime, 0L, 0L);
	while ((pSE = CQueue_Pop(WP3_C.m_Event)) != NULL)
	{
		switch (pSE->m_uEventID)
		{

		case IGFK_TOUCH1_DOWN :
			WP3_C.iMouseX = pSE->m_uData1;
			WP3_C.iMouseY = pSE->m_uData2; 
			WP3_C.lastmouse = WP3_C.iMouseX;
			WP3_C.timelast =	WP3_C.m_GameTime;
			if(WP3_C.countspeed < 0)
			{
				WP3_C.countspeed =WP3_C.countspeed - 1;
				if(WP3_C.countspeed == -4)
					WP3_C.countspeed = -3;
			}
			if(WP3_C.countspeed > 0)
			{
				WP3_C.countspeed =WP3_C.countspeed + 1;
				if(WP3_C.countspeed == 4)
					WP3_C.countspeed = 3;
			}
			if(WP3_C.iStoneTime >= (long) ani_info1->m_Duration)
			{
					WP3_C.iStoneTime = 0L;
			}
		break;

		case IGFK_TOUCH1_MOVE:

			WP3_C.iMouseX = pSE->m_uData1;
			WP3_C.iMouseY = pSE->m_uData2; 
			
			if(WP3_C.iMouseX > WP3_C.lastmouse)
				{
					WP3_C.m_Direction = 0;

				}	
	
				if(WP3_C.iMouseX < WP3_C.lastmouse)
				{
					WP3_C.m_Direction = 1;
				}
	
			break;

		}

		WP3_C_Free(pSE);
	}
	
	for(cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		V3Retained_UpdateNode((IGNode *) WP3_C.m_Obj[cn], "ANIMATE0", (WP3_C.m_GameTime/10) % ani_info0->m_Duration);
	}

	if(WP3_C.m_Direction == 0)
	{
	if(WP3_C.rospeed < -0.05f)
	{
		WP3_C.rospeed = 0.1f;
		WP3_C.countspeed = 1;
	}
		if(WP3_C.countspeed == 2)
			WP3_C.rospeed = 0.5f;
	if(WP3_C.countspeed == 3)
		WP3_C.rospeed = 2.0f;
	}
	if(WP3_C.m_Direction == 1)
	{
		if(WP3_C.rospeed > 0.05f)
		{
		WP3_C.rospeed = -0.1f;
		WP3_C.countspeed = -1;
		}
	if(WP3_C.countspeed == -2)
		WP3_C.rospeed = -0.5f;
	if(WP3_C.countspeed == -3)
		WP3_C.rospeed = -2.0f;
	}

	//for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	//{
	//	if (WP3_C.m_Obj[cn] != NULL)
	//		IGNode_rotateZ(V3Retained_GetMem(), (IGNode *) WP3_C.m_Obj[cn], (igreal) (IG_PI * fDegree / 180), &err);
	//}
	if (WP3_C.m_Obj[0] != NULL)
		IGNode_rotateZ(V3Retained_GetMem(), (IGNode *) WP3_C.m_Obj[0], (igreal) (IG_PI * WP3_C.fDegree * 10 / 180), &err);
	if (WP3_C.m_Obj[1] != NULL)
		IGNode_rotateZ(V3Retained_GetMem(), (IGNode *) WP3_C.m_Obj[1], (igreal) (IG_PI * WP3_C.fDegree *8/ 180), &err);
	if (WP3_C.m_Obj[2] != NULL)
		IGNode_rotateZ(V3Retained_GetMem(), (IGNode *) WP3_C.m_Obj[2], (igreal) (IG_PI * WP3_C.fDegree *6/ 180), &err);
	if (WP3_C.m_Obj[3] != NULL)
		IGNode_rotateZ(V3Retained_GetMem(), (IGNode *) WP3_C.m_Obj[3], (igreal) (IG_PI * WP3_C.fDegree *4/ 180), &err);
	if (WP3_C.m_Obj[4] != NULL)
		IGNode_rotateZ(V3Retained_GetMem(), (IGNode *) WP3_C.m_Obj[4], (igreal) (IG_PI * WP3_C.fDegree *2/ 180), &err);
	if (WP3_C.m_Obj[5] != NULL)
		IGNode_rotateZ(V3Retained_GetMem(), (IGNode *) WP3_C.m_Obj[5], (igreal) (IG_PI * WP3_C.fDegree / 180), &err);
	if (WP3_C.m_Obj[6] != NULL)
		IGNode_rotateZ(V3Retained_GetMem(), (IGNode *) WP3_C.m_Obj[6], (igreal) (IG_PI * WP3_C.fDegree / 180), &err);
	if (WP3_C.m_Obj[7] != NULL)
		IGNode_rotateZ(V3Retained_GetMem(), (IGNode *) WP3_C.m_Obj[7], (igreal) (IG_PI * WP3_C.fDegree / 180), &err);

	WP3_C.fDegree = WP3_C.fDegree + WP3_C.rospeed;


	V3Retained_Render();

	return 0;
}

int WP3_C_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	WP3_C_rr = V3Retained_GetInstance();

	switch (WP3_C.m_bLoadWorld)
	{
	case 0 :
		WP3_C_Update2D(_pFrameBuffer);
		WP3_C.m_bLoadWorld = 1;
		break;
	case 1:
		WP3_C_LoadWorld();
		V3Retained_ActiveBackgroundTexture();
		WP3_C_Update3D(_pFrameBuffer, uFrameInterval);
		WP3_C.m_bLoadWorld = 2;
		break;
	case 2:
		WP3_C_Update3D(_pFrameBuffer, uFrameInterval);
		break;
	}
		return 0;
}
void WP3_C_OnShutdown(int appId)
{
	if(WP3_C.m_AniInfo != NULL)
	{
		CArray_Del(WP3_C.m_AniInfo);
		WP3_C.m_AniInfo = NULL;
	}

	if(pWP3_C_StatusArrayPool != NULL)
	{
		CDel(pWP3_C_StatusArrayPool);
		pWP3_C_StatusArrayPool = NULL;
	}
	
	if(pWP3_C_StatusArray != NULL)
	{
		CDel(pWP3_C_StatusArray);
		pWP3_C_StatusArray = NULL;
	}

	V3Retained_End(appId);
}




#ifdef __cplusplus
}
#endif
