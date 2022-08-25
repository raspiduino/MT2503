//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3-B
// File        : WP3-B-GameApp.c
// Description : 手機寵物狗桌布 -- 遊戲主架構
// Author      : Ray
// Create      : 2010-12-01
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

#include "WP3-B-GameApp.h"
#include "V3DataDef.h"
#include "V3Retained.h"
#include "CUtils.h"
#include "CNodeStatus.h"
#include "WP3-B-Name.h"
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
		WP3_B_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	PC.m_uScrHeight = pPC->m_uScrHeight;
	PC.m_uScrWidth = pPC->m_uScrWidth;
	PC.m_pFrameBuffer = pPC->m_pFrameBuffer;
	PC.m_pMemBuffer = NULL;
	PC.m_MemSize = 0;

	WP3_B_PrepareConfig(&PC);
	WP3_B_OnStartup();

	return 0;
}

int IGGame_OnUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE)
{
	{
		SYSTEMTIME sys_time;
		GetLocalTime(&sys_time);
		WP3_B_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	while (uNumSysEvents--) {
		WP3_B_PostEvent(pSE->m_uEventID, pSE->m_uTime, pSE->m_uData1, pSE->m_uData2);
	}

	if (uFrameInterval > 0)
	{
		V3Retained *rr = V3Retained_GetInstance();
		WP3_B_OnUpdate(rr->PC.m_pFrameBuffer, uFrameInterval * 4800 / 32768);
	}

	return 0;
}

void IGGame_OnShutdown(void)
{
	WP3_B_OnShutdown();
}

#endif

//////////////////////////////////////////////////////// IGGame Framework Callback //////////////////////////////////////////
struct _WP3_B WP3_B;

#define ENGINE_BUFFER_SIZE 4*1024*1024

int WP3_B_PrepareConfig(IGV3Config *pPC)
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

void WP3_B_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	char WP3_B_g_DebugMessage[128] = {0};
	sprintf(WP3_B_g_DebugMessage, _TEXT("[%010d] "), WP3_B.m_GameTime);
	sprintf(&WP3_B_g_DebugMessage[13], pFmt, _p1, _p2, _p3, _p4);
	OutputDebugString(WP3_B_g_DebugMessage);
#endif
}

CArrayPool *pWP3_B_StatusArrayPool = NULL;
IGSysEvent *pWP3_B_StatusArray = NULL;

void WP3_B_InitArrayPool(void)
{
	if(pWP3_B_StatusArrayPool == NULL)pWP3_B_StatusArrayPool = CNew(sizeof(CArrayPool));
	if(pWP3_B_StatusArray == NULL)pWP3_B_StatusArray = CNew(sizeof(IGSysEvent) * MAX_ARRAY_POOL);
	CArrayPool_Init(pWP3_B_StatusArrayPool, (void *) pWP3_B_StatusArray, sizeof(IGSysEvent) * MAX_ARRAY_POOL, sizeof(IGSysEvent));
}

IGSysEvent *WP3_B_Alloc(void)
{
	return (IGSysEvent *) CArrayPool_Alloc(pWP3_B_StatusArrayPool);
}

void WP3_B_Free(IGSysEvent *_this)
{
	CArrayPool_Free(pWP3_B_StatusArrayPool, (void *) _this);
}

void WP3_B_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2)
{
	IGSysEvent *pGE = WP3_B_Alloc();

	if(pGE == NULL)
	{
		WP3_B_InitArrayPool();
		pGE = WP3_B_Alloc();
	}

	pGE->m_uEventID = _Id;
	if (_Time == 0L)
		pGE->m_uTime = WP3_B.m_GameTime;
	else
		pGE->m_uTime = _Time;
	pGE->m_uData1 = _Data1;
	pGE->m_uData2 = _Data2;

	CQueue_Push(WP3_B.m_Event, (void *) pGE);
}

void WP3_B_ClearPendingEvents(void)
{
	CQueue_Clear(WP3_B.m_Event);
}

IGSysEvent *WP3_B_GetEvent(void)
{
	IGSysEvent *pR;

	pR = (IGSysEvent *) CQueue_Pop(WP3_B.m_Event);

	return pR;
}

V3Retained *WP3_B_rr = NULL;

int WP3_B_OnStartup(void)
{
	WP3_B_InitArrayPool();
	CMemset(&WP3_B, sizeof(WP3_B), 0);
	V3Retained_LoadBackgroundTexture(png_WP3_B_bg);

	return 0;
}

int WP3_B_LoadWorld(void)
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
//#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
//	tex = V3Texture_New(png_WP3_B_bg, "WP3-B-bg.png", MASK_555_RED, MASK_555_GREEN, MASK_555_BLUE, 0);
//#else
//	tex = V3Texture_New(png_WP3_B_bg, WP_NameStruct.file_back[0], MASK_565_RED, MASK_565_GREEN, MASK_565_BLUE, 0);
//#endif
	world = V3World_New(igf_WP3_B, texs, tex, "Scene Root", "Camera_control", "ANIMATE0");

	V3Retained_LoadWorld(world);

	V3World_Del(world);
	WP3_B_rr = V3Retained_GetInstance();

	WP3_B.Smile = (IGNode *) V3Retained_GetGroup("smile");
	WP3_B.active = 0;

	Obj_root = (IGNode *) V3Retained_GetGroup(WP_NameStruct.node_name_Obj_root);
	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.node_name_Obj[cn]);
		WP3_B.m_OBJ[cn] = WP3_B_DogStatus_New(pNode, WP_NameStruct.node_name_Obj[cn], "ANIMATE0");
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

	WP3_B.m_AniInfo = V3Retained_GenerateAniInfo();


	WP3_B.m_Event = CQueue_New(DEFAULT_QUEUE_SIZE);
	WP3_B.m_WP = WP3_B_DogStatus_New(Obj_root, "root", "ANIMATE0");

	WP3_B.m_CurrentLoop = -1;
	WP3_B_DogStatus_EventLoop0(WP3_B.m_WP, WP3_B.m_GameTime);

	WP3_B.m_TimeFactor = 1;

	RandomEvent_Init(&WP3_B.m_TimeEvent, 9, 8, TIME_MIN, TIME_MAX);


	return 0;
}

IGU32 WP3_B_GetElapsedTime(IGU32 _tick)
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

void WP3_B_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second)
{
	WP3_B.m_Hour = _hour;
}

int WP3_B_GetHour(void)
{
	return WP3_B.m_Hour;
}

void WP3_B_RandomAni(void)
{
	int iEvent = -1;
	NodeAniStatus *pStatus = NULL;

	pStatus = WP3_B_DogStatus_CurrentStatus(WP3_B.m_WP, WP3_B.m_GameTime);


	if (pStatus != NULL && pStatus->m_IsLoop == 0)
		return;

	iEvent = RandomEvent_Get(&WP3_B.m_TimeEvent, WP3_B.m_GameTime);
	if(iEvent == 16)
		iEvent = 15;
	if (WP3_B.m_TimeEvent.m_Event == 0 || iEvent > 0)
	{
		if (iEvent > 0)
			WP3_B.m_TimeEvent.m_Event = iEvent;
		else
		{
			WP3_B.m_TimeEvent.m_Event = RandomEvent_Random(9, 15);
		}

		WP3_B_DogStatus_EventAni(WP3_B.m_WP, WP3_B.m_GameTime, WP3_B.m_TimeEvent.m_Event);
		
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

void WP3_B_Update2D(unsigned char *_pFrameBuffer)
{
	V3Retained_Bind(_pFrameBuffer);
	V3UI_DrawImage2DCenter(WP3_B_rr->m_BackgroundTexture, 1.0f);
}

int WP3_B_Update3D(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	IGErr err = IGERR_NONE;

	igreal Position[3];
	igreal iPosition[3];
	IGSysEvent *pSE = NULL;


	V3Retained_Bind(_pFrameBuffer);
	WP3_B.m_ElapsedTime = uFrameInterval;
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	//WP3_B.m_ElapsedTime = DebugInterval();
#endif
	WP3_B.m_GameTime = WP3_B.m_GameTime + WP3_B.m_ElapsedTime / WP3_B.m_TimeFactor;

	WP3_B_RandomAni();

	while ((pSE = CQueue_Pop(WP3_B.m_Event)) != NULL)
	{
		switch (pSE->m_uEventID)
		{
		case IGFK_TOUCH1_DOWN :
			{	
				if(WP3_B.active == 0)
				{
					WP3_B.active = 1;
					WP3_B_DogStatus_EventAni(WP3_B.m_WP, WP3_B.m_GameTime, WP3_B.iAni);
					WP3_B.iAni = WP3_B.iAni + 1;
					if (WP3_B.iAni == 8)
						WP3_B.iAni = 0;
				}
			}
			break;
		}

		WP3_B_Free(pSE);
	}

	WP3_B.fDegree = WP3_B.fDegree + 4;
	if(WP3_B.fDegree >= 360)
		WP3_B.fDegree = 0;

	WP3_B_DogStatus_Update(WP3_B.m_WP, WP3_B.m_GameTime);

	
		if(WP3_B.m_nowani <= 7 )
		{
			WP3_B.active = 2;
		}
		else
		{
			if(WP3_B.active == 2)
			{
				WP3_B.active = 0;
			}
		}
	IGNode_rotateZ (V3Retained_GetMem(),WP3_B.Smile, (igreal) (IG_PI * WP3_B.fDegree / 180),&err);
	if(WP3_B.active == 0)
	{
		Position[0] = 0;
		Position[1] = 0;
		Position[2] = (igreal) (IG_ONE * -0.9);
		IGNode_setPosition(V3Retained_GetMem(), WP3_B.Smile, Position, &err);
	}
	else
	{
		IGNode_getPosition(V3Retained_GetMem(), WP3_B.m_OBJ[0]->m_Node, iPosition, &err);
		iPosition[2] = iPosition[2]+6000L;
		IGNode_setPosition(V3Retained_GetMem(), WP3_B.Smile, iPosition, &err);
	}
	
	V3Retained_Render();

	return 0;
}

int WP3_B_SafeCheck(void)
{
	int iOK = 1;
	int iFAIL = 0;
	int iRESULT = iFAIL;
	int cn = 0;

	for(cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		if(WP3_B.m_OBJ[cn] == NULL)
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

int WP3_B_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	WP3_B_rr = V3Retained_GetInstance();

	switch (WP3_B.m_bLoadWorld)
	{
	case 0 :
		WP3_B_Update2D(_pFrameBuffer);
		WP3_B.m_bLoadWorld = 1;
		break;
	case 1:
		WP3_B_LoadWorld();
		V3Retained_ActiveBackgroundTexture();
		WP3_B_Update2D(_pFrameBuffer);
		WP3_B.m_bLoadWorld = 2;
		break;
	case 2:
		if(WP3_B_SafeCheck() == 1)//讀取完畢, 放行
		{
			V3Retained_ActiveBackgroundTexture();
			WP3_B_Update3D(_pFrameBuffer, uFrameInterval);
			WP3_B.m_bLoadWorld = 3;
		}
		else//還在讀取 繼續等等
		{
			WP3_B_Update2D(_pFrameBuffer);
		}
		break;
	case 3:
		WP3_B_Update3D(_pFrameBuffer, uFrameInterval);
		break;
	}

	return 0;
}
void WP3_B_OnShutdown(int appId)
{
	int cn = 0;

	if(WP3_B.m_AniInfo != NULL)
	{
		CArray_Del(WP3_B.m_AniInfo);
		WP3_B.m_AniInfo = NULL;
	}

	if(WP3_B.m_Event != NULL)
	{
		CQueue_Del(WP3_B.m_Event);
		WP3_B.m_Event = NULL;
	}
	
	if(WP3_B.m_WP != NULL)
	{
		WP3_B_DogStatus_Del(WP3_B.m_WP);
		WP3_B.m_WP = NULL;
	}

	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		if(WP3_B.m_OBJ[cn] != NULL)
		{
			WP3_B_DogStatus_Del(WP3_B.m_OBJ[cn]);
			WP3_B.m_OBJ[cn] = NULL;
		}
	}
	
	if(WP3_B.pStatusArray != NULL)
	{
		CDel(WP3_B.pStatusArray);
		WP3_B.pStatusArray = NULL;
	}

	if(WP3_B.pStatusArrayPool != NULL)
	{
		CDel(WP3_B.pStatusArrayPool);
		WP3_B.pStatusArrayPool = NULL;
	}
	
	if(pWP3_B_StatusArrayPool != NULL)
	{
		CDel(pWP3_B_StatusArrayPool);
		pWP3_B_StatusArrayPool = NULL;
	}
	
	if(pWP3_B_StatusArray != NULL)
	{
		CDel(pWP3_B_StatusArray);
		pWP3_B_StatusArray = NULL;
	}

	V3Retained_End(appId);
}



#ifdef __cplusplus
}
#endif
