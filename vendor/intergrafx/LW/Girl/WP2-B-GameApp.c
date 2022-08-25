//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP2-B
// File        : WP2-B-GameApp.c
// Description : 手機搔女孩桌布 -- 遊戲主架構
// Author      : Ray
// Create      : 2010-09-20
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

#include "WP2-B-GameApp.h"
#include "V3DataDef.h"
#include "V3Retained.h"
#include "CUtils.h"
#include "CNodeStatus.h"
#include "WP2-B-Name.h"
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
		WP2_B_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	PC.m_uScrHeight = pPC->m_uScrHeight;
	PC.m_uScrWidth = pPC->m_uScrWidth;
	PC.m_pFrameBuffer = pPC->m_pFrameBuffer;
	PC.m_pMemBuffer = NULL;
	PC.m_MemSize = 0;

	WP2_B_PrepareConfig(&PC);
	WP2_B_OnStartup();

	return 0;
}

int IGGame_OnUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE)
{
#ifdef WIN32
	{
		SYSTEMTIME sys_time;
		GetLocalTime(&sys_time);
		WP2_B_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}
#endif

	while (uNumSysEvents--) {
		WP2_B_PostEvent(pSE->m_uEventID, pSE->m_uTime, pSE->m_uData1, pSE->m_uData2);
	}

	//The resolution of the GetTickCount function is limited to the resolution of the system timer, which is typically in the range of 10 milliseconds to 16 milliseconds
	//這樣才不會造成時間差 = 0
	if (uFrameInterval > 0)
	{
		V3Retained *rr = V3Retained_GetInstance();
		WP2_B_OnUpdate(rr->PC.m_pFrameBuffer, uFrameInterval * 4800 / 32768);
	}

	return 0;
}

void IGGame_OnShutdown(void)
{
	WP2_B_OnShutdown();
}

#endif

//////////////////////////////////////////////////////// IGGame Framework Callback //////////////////////////////////////////

struct _WP2_B WP2_B;

#define ENGINE_BUFFER_SIZE 4*1024*1024

int WP2_B_PrepareConfig(IGV3Config *pPC)
{
	int err;
	IGV3Config PC;

	PC.m_uScrHeight = pPC->m_uScrHeight;
	PC.m_uScrWidth = pPC->m_uScrWidth;
	WP2_B.screenW = pPC->m_uScrWidth;
	WP2_B.screenH = pPC->m_uScrHeight;
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

void WP2_B_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	char WP2_B_g_DebugMessage[128] = {0};
	sprintf(WP2_B_g_DebugMessage, _TEXT("[%010d] "), WP2_B.m_GameTime);
	sprintf(&WP2_B_g_DebugMessage[13], pFmt, _p1, _p2, _p3, _p4);
	OutputDebugString(WP2_B_g_DebugMessage);
#endif
}

CArrayPool *pWP2_B_StatusArrayPool = NULL;
NodeAniStatus *pWP2_B_StatusArray = NULL;
void WP2_B_InitArrayPool(void)
{
	if(pWP2_B_StatusArrayPool == NULL) pWP2_B_StatusArrayPool = CNew(sizeof(CArrayPool));
	if(pWP2_B_StatusArray == NULL)pWP2_B_StatusArray = CNew(sizeof(NodeAniStatus) * MAX_ARRAY_POOL);
	CArrayPool_Init(pWP2_B_StatusArrayPool, (void *) pWP2_B_StatusArray, sizeof(IGSysEvent) * MAX_ARRAY_POOL, sizeof(IGSysEvent));
}

IGSysEvent *WP2_B_Alloc(void)
{
	return (IGSysEvent *) CArrayPool_Alloc(pWP2_B_StatusArrayPool);
}

void WP2_B_Free(IGSysEvent *_this)
{
	CArrayPool_Free(pWP2_B_StatusArrayPool, (void *) _this);
}

void WP2_B_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2)
{
	IGSysEvent *pGE = WP2_B_Alloc();
	
	if(pGE == NULL)
	{
		WP2_B_InitArrayPool();
		pGE = WP2_B_Alloc();
	}

	pGE->m_uEventID = _Id;
	if (_Time == 0L)
		pGE->m_uTime = WP2_B.m_GameTime;
	else
		pGE->m_uTime = _Time;
	pGE->m_uData1 = _Data1;
	pGE->m_uData2 = _Data2;

	CQueue_Push(WP2_B.m_Event, (void *) pGE);
}

void WP2_B_ClearPendingEvents(void)
{
	CQueue_Clear(WP2_B.m_Event);
}

IGSysEvent *WP2_B_GetEvent(void)
{
	IGSysEvent *pR;

	pR = (IGSysEvent *) CQueue_Pop(WP2_B.m_Event);

	return pR;
}

int WP2_B_OnStartup(void)
{
	WP2_B_InitArrayPool();
	CMemset(&WP2_B, sizeof(WP2_B), 0);
	V3Retained_LoadBackgroundTexture(png_WP2_B_back);

	return 0;
}

int WP2_B_LoadWorld(void)
{
	V3Texture *tex = NULL;
	CArray *texs;
	int cn = 0;
	int screenH,screenW;
	screenH = WP2_B.screenH;
	screenW = WP2_B.screenW;
	WP2_B_InitArrayPool();
	CMemset(&WP2_B, sizeof(WP2_B), 0);

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
//	tex = V3Texture_New(png_WP2_B_back, "back.png", MASK_555_RED, MASK_555_GREEN, MASK_555_BLUE, 0);
//#else
//	tex = V3Texture_New(png_WP2_B_back, "back.png", MASK_565_RED, MASK_565_GREEN, MASK_565_BLUE, 0);
//#endif
	WP2_B.m_World = V3World_New(igf_WP2_B, texs, tex, "Scene Root", "Camera_control", "ANIMATE0");

	V3Retained_LoadWorld(WP2_B.m_World);

	WP2_B.rr = V3Retained_GetInstance();

	for (cn = 0; cn < COUNT_BONE; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.node_name_Bone[cn]);
		WP2_B.m_Bone[cn] = pNode;
		WP2_B.m_GameObj[cn] = IGNewAGameObject(WP2_B.rr->m_Mem, &WP2_B.err);
		IGAttachRootNodeToGameObject(WP2_B.rr->m_Mem, WP2_B.m_GameObj[cn], (IGNode *) WP2_B.rr->m_SceneNode, pNode, &WP2_B.err);
		IGScene_AddToGameObjectList(WP2_B.rr->m_Mem, WP2_B.m_GameObj[cn], &WP2_B.err);
	}

	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetMesh(WP_NameStruct.node_name_Obj[cn]);
		WP2_B.m_Obj[cn] = pNode;
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

	WP2_B.m_Event = CQueue_New(DEFAULT_QUEUE_SIZE);


	WP2_B.m_WP = WP2_B_GirlStatus_New((IGNode *)WP2_B.rr->m_Root, "root", "ANIMATE0");

	WP2_B.m_CurrentLoop = -1;
	WP2_B.m_CurrentAni = -1;

	WP2_B.m_AniInfo = V3Retained_GenerateAniInfo();
	WP2_B.anispeed = 1;
	WP2_B_GirlStatus_EventLoop(WP2_B.m_WP, WP2_B.m_GameTime);

	WP2_B.m_DegreeInc = 1000;
	WP2_B.m_TimeFactor = 1;
	WP2_B.screenW = screenW;
	WP2_B.screenH = screenH;
	WP2_B.isRecovering = 0;//加這行是為了避免系統正在進行自動校正時, 被使用者重置了系統而導致狀態不一
	
	WP2_B.iMaxDeg1 = 20000;
	WP2_B.iMaxDeg2 = 30000;
	WP2_B.iMinDeg1 = -20000;
	WP2_B.iMinDeg2 = -30000;

	WP2_B.iMiddleDeg = (WP2_B.iMaxDeg2 + WP2_B.iMinDeg2)/2;
	WP2_B.m_HDegree = WP2_B.iMiddleDeg;

	return 0;
}

IGU32 WP2_B_GetElapsedTime(IGU32 _tick)
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

void WP2_B_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second)
{
	WP2_B.m_Hour = _hour;
}

int WP2_B_GetHour(void)
{
	return WP2_B.m_Hour;
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

void WP2_B_ProcessPick(int _pick_x, int _pick_y)
{
	IGErr err;								
	IGPoint point;							
	IGObjCache *pPickedObjs;				
	IGPickedObject *picked;					
	IGMesh *pMesh;							
	int cn, cn2, cn3;			

	point.x = _pick_x;
	point.y = _pick_y;
	pPickedObjs = IGScene_PickSceneObjects(WP2_B.rr->m_Mem, &point, &err);
	for (cn = pPickedObjs->m_pointers.m_count - 1; cn >= 0; cn = cn - 1)
	{
		picked = (IGPickedObject *)IGObjCache_getByIndex(V3Retained_GetMem(), pPickedObjs, cn, &err);
		if(picked != NULL)
		{
			for(cn2 = 0; cn2 < picked->m_PickedMeshNodes.m_pointers.m_count; cn2 = cn2 + 1)
			{
				pMesh = (IGMesh *)IGObjCache_getByIndex(V3Retained_GetMem(), &picked->m_PickedMeshNodes, cn2, &err);
				for (cn3 = 0; cn3 < COUNT_OBJ; cn3 = cn3 + 1)
				{
					if (pMesh == (IGMesh *) WP2_B.m_Obj[cn3])
					{
						if(WP_NameStruct.map_ani[cn3] != -1)
						{
							WP2_B_GirlStatus_EventAni(WP2_B.m_WP, WP2_B.m_GameTime, WP_NameStruct.map_ani[cn3]);
							//iHit = 1;
						}
						return;
					}
				}
			}
		}
	}
}

void WP2_B_IO_EventHandler(IGSysEvent *pSE)
{


	while ((pSE = CQueue_Pop(WP2_B.m_Event)) != NULL)
	{
		switch (pSE->m_uEventID)
		{
		case IGFK_TOUCH1_DOWN :
			WP2_B.iMouseX = pSE->m_uData1;
			WP2_B.iMouseY = pSE->m_uData2;
			WP2_B_ProcessPick(pSE->m_uData1, pSE->m_uData2);
			/*
			if(iMouseY < (WP2_B.screenH / 4) && iMouseX > ((WP2_B.screenW / 4) * 3))
			{
				WP2_B.anispeed = WP2_B.anispeed + 1;
				if(WP2_B.anispeed == 6)
				{
					WP2_B.anispeed = 1 ;
				}
				WP2_B_GirlStatus_EventLoop(WP2_B.m_WP, WP2_B.m_GameTime);

			}
			*/
			break;
		case IGFK_TOUCH1_UP :
			if(
				(WP2_B.m_HDegree >= WP2_B.iMiddleDeg && WP2_B.m_HDegree > WP2_B.iMaxDeg1) ||
				(WP2_B.m_HDegree <= WP2_B.iMiddleDeg && WP2_B.m_HDegree <= WP2_B.iMinDeg1)
				)
				WP2_B.isRecovering = 1;
			break;
		case IGFK_TOUCH1_MOVE :
			WP2_B_GirlStatus_EventHTouchMove(WP2_B.m_WP, WP2_B.iMouseX - pSE->m_uData1);
			WP2_B.iMouseX = pSE->m_uData1;
			WP2_B.iMouseY = pSE->m_uData2; 
			break;
	
		}

		WP2_B_Free(pSE);
	}
}

void WP2_B_Update2D(unsigned char *_pFrameBuffer)
{
	V3Retained_Bind(_pFrameBuffer);
	V3UI_DrawImage2DCenter(WP2_B.rr->m_BackgroundTexture, 1.0f);
}

int WP2_B_Update3D(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	IGSysEvent *pSE = NULL;
	AniInfo *ani_info = CNamedObjArray_Get(WP2_B.m_AniInfo, 0);

	V3Retained_Bind(_pFrameBuffer);
	WP2_B.m_ElapsedTime = uFrameInterval;
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	//WP2_B.m_ElapsedTime = DebugInterval();
#endif

	WP2_B.m_GameTime = WP2_B.m_GameTime + WP2_B.m_ElapsedTime / WP2_B.m_TimeFactor;

	WP2_B_IO_EventHandler(pSE);

	WP2_B_GirlStatus_Update(WP2_B.m_WP, WP2_B.m_GameTime);

	V3Retained_Render();

	//WP2_B_AddDebugMessage("H deg>> %d\n", WP2_B.m_HDegree,0,0,0);

	return 0;
}

int WP2_B_SafeCheck(void)
{
	int iOK = 1;
	int iFAIL = 0;
	int iRESULT = iFAIL;
	int cn = 0;

	for(cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		if(WP2_B.m_Obj[cn] == NULL)
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

int WP2_B_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	WP2_B.rr = V3Retained_GetInstance();

	switch (WP2_B.m_bLoadWorld)
	{
	case 0 :
		WP2_B_Update2D(_pFrameBuffer);
		WP2_B.m_bLoadWorld = 1;
		break;
	case 1:
		WP2_B_LoadWorld();
		V3Retained_ActiveBackgroundTexture();
		WP2_B_Update2D(_pFrameBuffer);
		WP2_B.m_bLoadWorld = 2;
		break;
	case 2:
		if(WP2_B_SafeCheck() == 1)//讀取完畢, 放行
		{
			V3Retained_ActiveBackgroundTexture();
			WP2_B_Update3D(_pFrameBuffer, uFrameInterval);
			WP2_B.m_bLoadWorld = 3;
		}
		else//還在讀取 繼續等等
		{
			WP2_B_Update2D(_pFrameBuffer);
		}
		break;
	case 3:
		WP2_B_Update3D(_pFrameBuffer, uFrameInterval);
		break;
	}

	return 0;
}
void WP2_B_OnShutdown(int appId)
{
	if(WP2_B.m_World != NULL)
	{
		V3World_Del(WP2_B.m_World);
		WP2_B.m_World = NULL;
	}

	if(WP2_B.m_Event != NULL)
	{
		CQueue_Del(WP2_B.m_Event);
		WP2_B.m_Event = NULL;
	}
	
	if(WP2_B.m_WP != NULL)
	{
		WP2_B_GirlStatus_Del(WP2_B.m_WP);
		WP2_B.m_WP = NULL;
	}

	if(pWP2_B_StatusArrayPool != NULL)
	{
		CDel(pWP2_B_StatusArrayPool);
		pWP2_B_StatusArrayPool = NULL;
	}

	if(pWP2_B_StatusArray != NULL)
	{
		CDel(pWP2_B_StatusArray);
		pWP2_B_StatusArray = NULL;
	}
	
	if(WP2_B.pStatusArrayPool != NULL)
	{
		CDel(WP2_B.pStatusArrayPool);
		WP2_B.pStatusArrayPool = NULL;
	}
	
	if(WP2_B.pStatusArrayPool != NULL)
	{
		CDel(WP2_B.pStatusArray);
		WP2_B.pStatusArrayPool = NULL;
	}

	V3Retained_End(appId);
}


#ifdef __cplusplus
}
#endif
