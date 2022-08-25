//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP2-D
// File        : WP2-D-GameApp.c
// Description : 手機百駿圖桌布 -- 遊戲主架構
// Author      : Ray
// Create      : 2010-12-06
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

#include "WP2-D-GameApp.h"
#include "V3DataDef.h"
#include "V3Retained.h"
#include "CUtils.h"
#include "CNodeStatus.h"
#include "WP2-D-Name.h"
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
		WP2_D_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	PC.m_uScrHeight = pPC->m_uScrHeight;
	PC.m_uScrWidth = pPC->m_uScrWidth;
	PC.m_pFrameBuffer = pPC->m_pFrameBuffer;
	PC.m_pMemBuffer = NULL;
	PC.m_MemSize = 0;

	WP2_D_PrepareConfig(&PC);
	WP2_D_OnStartup();

	return 0;
}

int IGGame_OnUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE)
{
	{
		SYSTEMTIME sys_time;
		GetLocalTime(&sys_time);
		WP2_D_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	while (uNumSysEvents--) {
		WP2_D_PostEvent(pSE->m_uEventID, pSE->m_uTime, pSE->m_uData1, pSE->m_uData2);
	}

	//The resolution of the GetTickCount function is limited to the resolution of the system timer, which is typically in the range of 10 milliseconds to 16 milliseconds
	//這樣才不會造成時間差 = 0
	if (uFrameInterval > 0)
	{
		V3Retained *rr = V3Retained_GetInstance();
		WP2_D_OnUpdate(rr->PC.m_pFrameBuffer, uFrameInterval * 4800 / 32768);
	}

	return 0;
}

void IGGame_OnShutdown(void)
{
	WP2_D_OnShutdown();
}

#endif

//////////////////////////////////////////////////////// IGGame Framework Callback //////////////////////////////////////////

struct _WP2_D WP2_D;

#define ENGINE_BUFFER_SIZE 8*1024*1024
//static unsigned char s_engineMemBuf[ENGINE_BUFFER_SIZE];

int WP2_D_PrepareConfig(IGV3Config *pPC)
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

void WP2_D_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	char WP2_D_g_DebugMessage[128] = {0};
	sprintf(WP2_D_g_DebugMessage, _TEXT("[%010d] "), WP2_D.m_GameTime);
	sprintf(&WP2_D_g_DebugMessage[13], pFmt, _p1, _p2, _p3, _p4);
	OutputDebugString(WP2_D_g_DebugMessage);
#endif
}

CArrayPool *pWP2_D_StatusArrayPool = NULL;
IGSysEvent *pWP2_D_StatusArray = NULL;

void WP2_D_InitArrayPool(void)
{
	if(pWP2_D_StatusArrayPool == NULL) pWP2_D_StatusArrayPool = CNew(sizeof(CArrayPool));
	if(pWP2_D_StatusArray == NULL) pWP2_D_StatusArray = CNew(sizeof(IGSysEvent) * MAX_ARRAY_POOL);	
	CArrayPool_Init(pWP2_D_StatusArrayPool, (void *) pWP2_D_StatusArray, sizeof(IGSysEvent) * MAX_ARRAY_POOL, sizeof(IGSysEvent));
}

IGSysEvent *WP2_D_Alloc(void)
{
	return (IGSysEvent *) CArrayPool_Alloc(pWP2_D_StatusArrayPool);
}

void WP2_D_Free(IGSysEvent *_this)
{
	CArrayPool_Free(pWP2_D_StatusArrayPool, (void *) _this);
}

void WP2_D_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2)
{
	IGSysEvent *pGE = WP2_D_Alloc();

	if(pGE == NULL)
	{
		WP2_D_InitArrayPool();
		pGE = WP2_D_Alloc();
	}

	pGE->m_uEventID = _Id;
	if (_Time == 0L)
		pGE->m_uTime = WP2_D.m_GameTime;
	else
		pGE->m_uTime = _Time;
	pGE->m_uData1 = _Data1;
	pGE->m_uData2 = _Data2;

	CQueue_Push(WP2_D.m_Event, (void *) pGE);
}

void WP2_D_ClearPendingEvents(void)
{
	CQueue_Clear(WP2_D.m_Event);
}

IGSysEvent *WP2_D_GetEvent(void)
{
	IGSysEvent *pR;

	pR = (IGSysEvent *) CQueue_Pop(WP2_D.m_Event);

	return pR;
}

V3Retained *WP2_D_rr = NULL;

int WP2_D_OnStartup(void)
{
	WP2_D_InitArrayPool();
	CMemset(&WP2_D, sizeof(WP2_D), 0);
	WP2_D.pickonce = 0;
	V3Retained_LoadBackgroundTexture(png_WP2_D_back2);
	WP2_D.m_bLoadWorld = 0;

	return 0;
}

int WP2_D_LoadWorld(void)
{
	V3Texture *tex = NULL;
	CArray *texs;
	
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

	WP2_D.m_World = V3World_New(igf_WP2_D, texs, tex, "Scene Root", "Camera_control", "ANIMATE0");

	V3Retained_LoadWorld(WP2_D.m_World);

	WP2_D_rr = V3Retained_GetInstance();

	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.node_name_Obj[cn]);
		WP2_D.m_OBJ[cn] = WP2_D_HorseStatus_New(pNode, WP_NameStruct.node_name_Obj[cn], "ANIMATE6");
		WP2_D.m_OBJ[cn]->m_speed = 0.001f;  //unit / ms

		WP2_D.m_GameObj[cn] = IGNewAGameObject(WP2_D_rr->m_Mem, &WP2_D.err);
		IGAttachRootNodeToGameObject(WP2_D_rr->m_Mem, WP2_D.m_GameObj[cn], (IGNode *) WP2_D_rr->m_SceneNode, pNode, &WP2_D.err);
		IGScene_AddToGameObjectList(WP2_D_rr->m_Mem, WP2_D.m_GameObj[cn], &WP2_D.err);

		WP2_D.m_OBJ[cn]->m_Path = -1;
	}

	for (cn = 0; cn < COUNT_PATH; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.path_name_Obj[cn]);
		WP2_D.m_Path[cn] = pNode;
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

	WP2_D.m_AniInfo = V3Retained_GenerateAniInfo();
	WP2_D.anispeed = 1;
	WP2_D.m_Event = CQueue_New(DEFAULT_QUEUE_SIZE);
	WP2_D.m_WP = WP2_D_HorseStatus_New((IGNode *)WP2_D_rr->m_Root, "root", "ANIMATE20");
	WP2_D_HorseStatus_EventEat(WP2_D.m_OBJ[1], WP2_D.m_GameTime);

	WP2_D_HorseStatus_BirdEventLoop(WP2_D.m_OBJ[5],WP2_D.m_GameTime);

	WP2_D_HorseStatus_EventLoop(WP2_D.m_OBJ[0], WP2_D.m_GameTime, 6);
	WP2_D_HorseStatus_EventLoop(WP2_D.m_OBJ[2], WP2_D.m_GameTime, 6);
	WP2_D_HorseStatus_EventLoop(WP2_D.m_OBJ[3], WP2_D.m_GameTime, 6);
	WP2_D.m_CurrentLoop = -1;
	WP2_D.fivesecall = WP2_D.m_GameTime;
	WP2_D.fivesecone = WP2_D.m_GameTime;
	WP2_D.fivesecthis = -1;
 	WP2_D.m_DegreeInc = 10;
	WP2_D.m_TimeFactor = 1;

	RandomEvent_Init(&WP2_D.m_CheckObj, 1, 5, FISH_MIN, FISH_MAX);
	
	return 0;
}

IGU32 WP2_D_GetElapsedTime(IGU32 _tick)
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

void WP2_D_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second)
{
	WP2_D.m_Hour = _hour;
}

int WP2_D_GetHour(void)
{
	return WP2_D.m_Hour;
}



int WP2_D_GetHorseAniByPath(int _iPath)
{
	int iAni = -1;

	iAni = WP_NameStruct.map_ani[_iPath];
	return iAni;
}

int WP2_D_GetPathAniNumber(int _iPath)
{
	return _iPath + 11;
}

const char *WP2_D_GetPathAniName(int _iPath)
{
	int iAni = 0;
	const char *name;
	if(_iPath <= 3)
		iAni = _iPath + 11;
	if(_iPath >= 4)
		iAni = _iPath + 12;
	name =  CNamedObjArray_GetName(WP2_D.m_AniInfo, iAni);
	return name;
}

void CheckObj(void)
{
	int cn,see;

	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		//第二跟五隻馬沒有路徑, 在原地吃草
		if (cn == 1)
			continue;
		if (cn == 4)
			continue;
		if (cn == 5)
			continue;
		if (cn == 6)
			continue;

		see = WP2_D.m_GameTime % 20000L;

		if(see >= 1000&& see <= 1010)
		{
			WP2_D.m_getrun = WP2_D.m_getrun + 1 ;
			if(WP2_D.m_getrun == 2)
				WP2_D.m_getrun = 1;
		 }
		if (WP2_D.m_OBJ[cn]->m_Path == -1)
		{
			WP2_D_HorseStatus_SetPath(WP2_D.m_OBJ[cn]);
			WP2_D_HorseStatus_EventLoop(WP2_D.m_OBJ[cn], WP2_D.m_GameTime, WP2_D_GetHorseAniByPath(WP2_D.m_OBJ[cn]->m_Path));
		}
		else
		{
			//RAY::2011-02-08 這邊要 cast long 型態, 否則變成 unsigned - unsigned 這樣結果不會是負的, 判斷就會錯誤
			if (WP2_D.m_OBJ[cn]->m_bPathPause == 0 && ((long) WP2_D.m_OBJ[cn]->m_PathDuration - (long) WP2_D.m_OBJ[cn]->m_PathAniTime) < 10)
			{
				WP2_D_HorseStatus_SetPath(WP2_D.m_OBJ[cn]);
				WP2_D_HorseStatus_EventLoop(WP2_D.m_OBJ[cn], WP2_D.m_GameTime, WP2_D_GetHorseAniByPath(WP2_D.m_OBJ[cn]->m_Path));
			}
		}
	}
	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		if (cn == 5)
		{
			if (WP2_D.m_OBJ[5]->m_Path == -1)
			{
				WP2_D_HorseStatus_SetBirdPath(WP2_D.m_OBJ[5]);
				WP2_D_HorseStatus_EventLoop(WP2_D.m_OBJ[5], WP2_D.m_GameTime, WP2_D_GetHorseAniByPath(WP2_D.m_OBJ[5]->m_Path));
			}
			else
				{
				//RAY::2011-02-08 這邊要 cast long 型態, 否則變成 unsigned - unsigned 這樣結果不會是負的, 判斷就會錯誤
				if (WP2_D.m_OBJ[5]->m_bPathPause == 0 && ((long) WP2_D.m_OBJ[5]->m_PathDuration - (long) WP2_D.m_OBJ[5]->m_PathAniTime) < 10)
				{
					WP2_D_HorseStatus_SetBirdPath(WP2_D.m_OBJ[5]);
					WP2_D_HorseStatus_EventLoop(WP2_D.m_OBJ[5], WP2_D.m_GameTime, WP2_D_GetHorseAniByPath(WP2_D.m_OBJ[5]->m_Path));
				}
		}
		}

	}
		
}

void WP2_D_PickAll(void)
{
	//點了一次就全部的馬動一次，拉動的距離要超過3分之1
	int cn2;
	for (cn2 = 0; cn2 < 4; cn2 = cn2 + 1)
	{
			if (cn2 == 1)
			{
				WP2_D.wave = 0;
				WP2_D_HorseStatus_EventTouchStay(WP2_D.m_OBJ[1], WP2_D.m_GameTime);
			}
			else
			{
				WP2_D_HorseStatus_EventTouchWalk(WP2_D.m_OBJ[cn2], WP2_D.m_GameTime);
			}
	}
}
void WP2_D_ProcessPick(int _pick_x, int _pick_y)
{
	IGErr err;
	IGPoint point;
	IGObjCache *pPickedObjs;
	IGPickedObject *picked;
	
	int cn, cn2;

	point.x = _pick_x;
	point.y = _pick_y;
	pPickedObjs = IGScene_PickSceneObjects(V3Retained_GetMem(), &point, &err);

	//RAY::2011-01-04 要到過來才會先抓到前面的馬, 抓到一隻就回去 (break), 否則很多隻會一起叫
	//if(WP2_D.m_GameTime - WP2_D.fivesecone >= 1000)
	//{
	for (cn = pPickedObjs->m_pointers.m_count - 1; cn >= 0; cn = cn - 1)
	{
		picked = (IGPickedObject *)IGObjCache_getByIndex(V3Retained_GetMem(), pPickedObjs, cn, &err);
		if(picked != NULL)
		{
			for(cn2 = 0; cn2 < picked->m_PickedMeshNodes.m_pointers.m_count; cn2 = cn2 + 1)
			{
				//pMesh = (IGMesh *)IGObjCache_getByIndex(V3Retained_GetMem(), &picked->m_PickedMeshNodes, cn2, &err);
				//You can get picked mesh info here for lower level manipulations, 
				// such as play different sounds, aniamtions, and so on
				//...
			}
			for (cn2 = 0; cn2 < COUNT_OBJ; cn2 = cn2 + 1)
			{
				if (picked->m_pObject->mRootNode == WP2_D.m_OBJ[cn2]->m_Node)
				{
					if(picked->m_pObject->mRootNode != WP2_D.m_OBJ[4]->m_Node)
					{
						if(picked->m_pObject->mRootNode != WP2_D.m_OBJ[5]->m_Node)
						{
							WP2_D.fivesecone = WP2_D.m_GameTime;
							if (cn2 == 1)
							{
								WP2_D.wave = 0;
								WP2_D_HorseStatus_EventTouchStay(WP2_D.m_OBJ[1], WP2_D.m_GameTime);
							}
							else
							{
								WP2_D_HorseStatus_EventTouchWalk(WP2_D.m_OBJ[cn2], WP2_D.m_GameTime);
							}
						}
					}
				}
			}
			//RAY::2011-01-04 抓到一隻就回去
			break;
		}
	}
	//}
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

void WP2_D_Update2D(unsigned char *_pFrameBuffer)
{
	V3Retained_Bind(_pFrameBuffer);
	V3UI_DrawImage2DCenter(WP2_D_rr->m_BackgroundTexture, 1.0f);
}

int WP2_D_Update3D(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	IGErr err = IGERR_NONE;
	IGSysEvent *pSE = NULL;
	AniInfo *ani_info = CNamedObjArray_Get(WP2_D.m_AniInfo, 0);
	AniInfo *ani_info20 = CNamedObjArray_Get(WP2_D.m_AniInfo, 20);
	V3Retained_Bind(_pFrameBuffer);

	WP2_D.m_ElapsedTime = uFrameInterval;
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	//WP2_D.m_ElapsedTime = DebugInterval();
#endif
	WP2_D.m_GameTime = WP2_D.m_GameTime + WP2_D.m_ElapsedTime / WP2_D.m_TimeFactor;

	CheckObj();

	//if(WP2_D.m_ScrHeight == 320 && WP2_D.m_ScrWidth == 240)
	if(WP2_D_rr->m_Renderer->m_buffs.m_height == 320 && WP2_D_rr->m_Renderer->m_buffs.m_width == 240)
	{
		IGCamera_setPerspectiveFieldOfView(WP2_D_rr->m_Mem, WP2_D_rr->m_Camera, (igreal) (IG_ONE / 2.8f), &err);
	}
	else
	{
		IGCamera_setPerspectiveFieldOfView(WP2_D_rr->m_Mem, WP2_D_rr->m_Camera, (igreal) (IG_ONE / 2.55f), &err);
	}

	if (WP2_D_HorseStatus_IsLoop(WP2_D.m_OBJ[1], WP2_D.m_GameTime) == 1)
	{
		WP2_D_HorseStatus_EventEat(WP2_D.m_OBJ[1], WP2_D.m_GameTime);
	}

	// process platform events, only test touch down event (mouse left button down)

	while ((pSE = CQueue_Pop(WP2_D.m_Event)) != NULL)
	{
		switch (pSE->m_uEventID)
		{
		case IGFK_TOUCH1_UP :
			{
				//讓他不要重覆一直觸發馬，會造成消失
				WP2_D.pickonce = 0;
			}
			break;
		case IGFK_TOUCH1_DOWN :
			{
				WP2_D.Xmouse = pSE->m_uData1;
				WP2_D_ProcessPick(pSE->m_uData1, pSE->m_uData2);
				WP2_D.iMouseX = pSE->m_uData1;
				WP2_D.iMouseY = pSE->m_uData2;
				/*
				if(iMouseY < (WP2_D.m_ScrHeight / 4) && iMouseX > ((WP2_D.m_ScrWidth / 4) * 3))
				{
					WP2_D.anispeed = WP2_D.anispeed + 1;
					if(WP2_D.anispeed == 6)
					{
						WP2_D.anispeed = 1 ;
					}	
				}
				*/
			}
			break;
		case IGFK_TOUCH1_MOVE :
			{
				WP2_D.Ymouse = abs(pSE->m_uData1 - WP2_D.Xmouse);
				WP2_D.mouseL = WP2_D_rr->m_Renderer->m_buffs.m_width / 4;
				if(WP2_D.m_GameTime - WP2_D.fivesecall >= 2000)
				{
				if(WP2_D.Ymouse > WP2_D.mouseL)
				{
					if(WP2_D.pickonce == 0)
					{
						WP2_D_PickAll();
						WP2_D.pickonce = 1;
						WP2_D.fivesecall = WP2_D.m_GameTime;
					}
				}
				}
			}
			break;
		case IGFK_LEFT_ARROW:
			V3Retained_ChangeBackground(0);
			break;

		case IGFK_RIGHT_ARROW:
			V3Retained_ChangeBackground(1);
			break;

		}

		WP2_D_Free(pSE);
	}

	//V3Retained_UpdateScene("ANIMATE0", (WP2_D.m_GameTime/3) % ani_info->m_Duration);
	//RAY::2010-12-01 Update Grass -- 動作全長是 1000, 因為 470 ~ 500 的地方有問題, 所以用 460
	{
		int iDuration = 460;
		int iAniTime = (WP2_D.m_GameTime/3);
		int iTimes = iAniTime / iDuration;
		iTimes = iTimes % 2;
		iAniTime = iAniTime % iDuration;
		if (iTimes == 1)
		{
			iAniTime = iDuration - iAniTime;
		}
	}



	V3Retained_UpdateNode((IGNode *) WP2_D_rr->m_Root, "ANIMATE20", (WP2_D.m_GameTime) % ani_info20->m_Duration);
	
	WP2_D_HorseStatus_Update(WP2_D.m_OBJ[0], WP2_D.m_GameTime);
	WP2_D_HorseStatus_Update(WP2_D.m_OBJ[1], WP2_D.m_GameTime);
	WP2_D_HorseStatus_Update(WP2_D.m_OBJ[2], WP2_D.m_GameTime);
	WP2_D_HorseStatus_Update(WP2_D.m_OBJ[3], WP2_D.m_GameTime);
	WP2_D_HorseStatus_Update(WP2_D.m_OBJ[4], WP2_D.m_GameTime);
	WP2_D_HorseStatus_Update(WP2_D.m_OBJ[5], WP2_D.m_GameTime);
	WP2_D_HorseStatus_Update(WP2_D.m_OBJ[6], WP2_D.m_GameTime);

	V3Retained_Render();

	return 0;
}
int WP2_D_SafeCheck(void)
{
	int iOK = 1;
	int iFAIL = 0;
	int cn,ct,cr = 0;
	for(cn = 0; cn <= COUNT_OBJ;cn=cn+1)
	{
		if(WP2_D.m_OBJ[cn] == NULL)//如果通通都不是null
		{
			ct = 1;
		}
		else
		{
			ct = 0;
		}
		cr = cr + ct;
	}
	if(cr == 0)
	return iOK;
	else
	return iFAIL;
}

int WP2_D_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	WP2_D_rr = V3Retained_GetInstance();

	switch (WP2_D.m_bLoadWorld)
	{
	case 0 :
		WP2_D_Update2D(_pFrameBuffer);
		WP2_D.m_bLoadWorld = 1;
		break;
	case 1:
		WP2_D_LoadWorld();
		WP2_D_Update2D(_pFrameBuffer);
		WP2_D.m_bLoadWorld = 2;
		break;
	case 2:
		if(WP2_D_SafeCheck() == 1)
		{
			V3Retained_ActiveBackgroundTexture();
			WP2_D_Update3D(_pFrameBuffer, uFrameInterval);
			WP2_D.m_bLoadWorld = 3;
		}
		else
		{
			WP2_D_Update2D(_pFrameBuffer);
		}
		break;
	case 3:
			WP2_D_Update3D(_pFrameBuffer, uFrameInterval);
		break;
	}

	return 0;
}

void WP2_D_OnShutdown(int appId)
{
	int cn = 0;
	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		if(WP2_D.m_OBJ[cn] != NULL)
		{
			WP2_D_HorseStatus_Del(WP2_D.m_OBJ[cn]);
			WP2_D.m_OBJ[cn] = NULL;
		}
	}

	//WP2_D_HorseStatus_InitArrayPool();, marked by Odin, 這行不太清楚怎麼會出現在這裡, 理論上不需要, 避免意外, 先用mark的方式, 日後再刪除
	if(WP2_D.m_World != NULL)
	{
		V3World_Del(WP2_D.m_World);
		WP2_D.m_World = NULL;
	}
		
	//IGScene_ResetGameObjects(V3Retained_GetMem(), &err);
	
	if(WP2_D.m_Event != NULL)
	{
		CQueue_Del(WP2_D.m_Event);
		WP2_D.m_Event = NULL;
	}
	
	if(WP2_D.m_WP != NULL)
	{
		WP2_D_HorseStatus_Del(WP2_D.m_WP);
		WP2_D.m_WP = NULL;
	}

	if(WP2_D.m_AniInfo != NULL)
	{
		CArray_Del(WP2_D.m_AniInfo);
		WP2_D.m_AniInfo = NULL;
	}

	if(WP2_D.pStatusArray != NULL)
	{
		CDel(WP2_D.pStatusArray);
		WP2_D.pStatusArray = NULL;
	}

	if(WP2_D.pStatusArrayPool != NULL)
	{
		CDel(WP2_D.pStatusArrayPool);
		WP2_D.pStatusArrayPool = NULL;
	}
	
	if(pWP2_D_StatusArrayPool != NULL)
	{
		CDel(pWP2_D_StatusArrayPool);
		pWP2_D_StatusArrayPool = NULL;
	}

	if(pWP2_D_StatusArray != NULL)
	{
		CDel(pWP2_D_StatusArray);
		pWP2_D_StatusArray = NULL;
	}

	V3Retained_End(appId);
}



#ifdef __cplusplus
}
#endif
