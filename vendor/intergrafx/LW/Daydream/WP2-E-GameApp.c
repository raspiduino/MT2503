//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP2-E
// File        : WP2_E_GameApp.c
// Description : 手機白日夢桌布 -- 遊戲主架構
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

#include "WP2-E-GameApp.h"
#include "V3DataDef.h"
#include "V3Retained.h"
#include "CUtils.h"
#include "CNodeStatus.h"
#include "WP2-E-Name.h"
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
		WP2_E_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	PC.m_uScrHeight = pPC->m_uScrHeight;
	PC.m_uScrWidth = pPC->m_uScrWidth;
	PC.m_pFrameBuffer = pPC->m_pFrameBuffer;
	PC.m_pMemBuffer = NULL;
	PC.m_MemSize = 0;

	WP2_E_PrepareConfig(&PC);
	WP2_E_OnStartup();

	return 0;
}

int IGGame_OnUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE)
{
	{
		SYSTEMTIME sys_time;
		GetLocalTime(&sys_time);
		WP2_E_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	while (uNumSysEvents--) {
		WP2_E_PostEvent(pSE->m_uEventID, pSE->m_uTime, pSE->m_uData1, pSE->m_uData2);
	}

	//The resolution of the GetTickCount function is limited to the resolution of the system timer, which is typically in the range of 10 milliseconds to 16 milliseconds
	//這樣才不會造成時間差 = 0
	if (uFrameInterval > 0)
	{
		V3Retained *rr = V3Retained_GetInstance();
		WP2_E_OnUpdate(rr->PC.m_pFrameBuffer, uFrameInterval * 4800 / 32768);
	}

	return 0;
}

void IGGame_OnShutdown(void)
{
	WP2_E_OnShutdown();
}

#endif

//////////////////////////////////////////////////////// IGGame Framework Callback //////////////////////////////////////////

struct _WP2_E WP2_E;

#define ENGINE_BUFFER_SIZE 8*1024*1024
//static unsigned char s_engineMemBuf[ENGINE_BUFFER_SIZE];

int WP2_E_PrepareConfig(IGV3Config *pPC)
{
	int err;
	IGV3Config PC;

	PC.m_uScrHeight = pPC->m_uScrHeight;
	PC.m_uScrWidth = pPC->m_uScrWidth;
	PC.m_pFrameBuffer = pPC->m_pFrameBuffer;
	PC.m_MemSize = ENGINE_BUFFER_SIZE;

	if (pPC->m_pMemBuffer != NULL)
	{
		PC.m_pMemBuffer = pPC->m_pMemBuffer;
		PC.m_MemSize = pPC->m_MemSize;
	}
	else
	{
		//PC.m_pMemBuffer = s_engineMemBuf;
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

void WP2_E_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	char WP2_E_g_DebugMessage[128] = {0};
	sprintf(WP2_E_g_DebugMessage, _TEXT("[%010d] "), WP2_E.m_GameTime);
	sprintf(&WP2_E_g_DebugMessage[13], pFmt, _p1, _p2, _p3, _p4);
	OutputDebugString(WP2_E_g_DebugMessage);
#endif
}

CArrayPool *pWP2_E_StatusArrayPool = NULL;
IGSysEvent *pWP2_E_StatusArray = NULL;

void WP2_E_InitArrayPool(void)
{
	if(pWP2_E_StatusArrayPool == NULL) pWP2_E_StatusArrayPool = CNew(sizeof(CArrayPool));
	if(pWP2_E_StatusArray == NULL) pWP2_E_StatusArray = CNew(sizeof(IGSysEvent) * MAX_ARRAY_POOL);
	CArrayPool_Init(pWP2_E_StatusArrayPool, (void *) pWP2_E_StatusArray, sizeof(IGSysEvent) * MAX_ARRAY_POOL, sizeof(IGSysEvent));
}

IGSysEvent *WP2_E_Alloc(void)
{
	return (IGSysEvent *) CArrayPool_Alloc(pWP2_E_StatusArrayPool);
}

void WP2_E_Free(IGSysEvent *_this)
{
	CArrayPool_Free(pWP2_E_StatusArrayPool, (void *) _this);
}

void WP2_E_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2)
{
	IGSysEvent *pGE = WP2_E_Alloc();

	if(pGE == NULL)
	{
		WP2_E_InitArrayPool();
		pGE = WP2_E_Alloc();
	}

	pGE->m_uEventID = _Id;
	if (_Time == 0L)
		pGE->m_uTime = WP2_E.m_GameTime;
	else
		pGE->m_uTime = _Time;
	pGE->m_uData1 = _Data1;
	pGE->m_uData2 = _Data2;

	CQueue_Push(WP2_E.m_Event, (void *) pGE);
}

void WP2_E_ClearPendingEvents(void)
{
	CQueue_Clear(WP2_E.m_Event);
}

IGSysEvent *WP2_E_GetEvent(void)
{
	IGSysEvent *pR;

	pR = (IGSysEvent *) CQueue_Pop(WP2_E.m_Event);

	return pR;
}

V3Retained *WP2_E_rr = NULL;

int WP2_E_OnStartup00(void)
{
	V3Texture *tex = NULL;
	CArray *texs;
	int cn;

	WP2_E_InitArrayPool();
	CMemset(&WP2_E, sizeof(WP2_E), 0);

	texs = V3Textures_New(NULL);

	for (cn = 0; cn < COUNT_BMP; cn = cn + 1)
	{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
		CArray_Add(texs, (void *) V3Texture_New(WP_NameStruct.bmp_array[cn], WP_NameStruct.file_bmp[cn], MASK_555_RED, MASK_555_GREEN, MASK_555_BLUE, WP_NameStruct.keycolor[cn]));
#else
		CArray_Add(texs, (void *) V3Texture_New(WP_NameStruct.bmp_array[cn], WP_NameStruct.file_bmp[cn], MASK_565_RED, MASK_565_GREEN, MASK_565_BLUE, WP_NameStruct.keycolor[cn]));
#endif
	}

#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	tex = V3Texture_New(png_WP2_E_back, "bg.png", MASK_555_RED, MASK_555_GREEN, MASK_555_BLUE, 0);
#else
	tex = V3Texture_New(png_WP2_E_back, "bg.png", MASK_565_RED, MASK_565_GREEN, MASK_565_BLUE, 0);
#endif
	WP2_E.m_World = V3World_New(igf_WP2_E, texs, tex, "Scene Root", "Camera_control", "ANIMATE0");

	V3Retained_LoadWorldBegin(WP2_E.m_World);

	return 0;
}

int WP2_E_OnStartupInitValue(void)
{
	int cn;

	WP2_E_rr = V3Retained_GetInstance();

	//IGCamera_setViewMode(rr->m_Mem, rr->m_Camera, IGVIEW_PARALLEL, &err);
	//WP2_E.m_CameraFov = IG_ONE / 5;
	//IGCamera_setParallelFieldOfView(rr->m_Mem, rr->m_Camera, WP2_E.m_CameraFov, &err);
	//IGCamera_setPerspectiveFieldOfView(rr->m_Mem, rr->m_Camera, IG_ONE * 1.7, &err);

	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup("plane-track01");
		WP2_E.m_Plane = WP2_E_CashStatus_New(pNode, "plane-track01", "ANIMATE1");
	}

	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.node_name_Obj[cn]);
		WP2_E.m_Obj[cn] = pNode;

		WP2_E.m_OBJ[cn] = WP2_E_CashStatus_New(pNode, WP_NameStruct.node_name_Obj[cn], "ANIMATE0");
		WP2_E.m_OBJ[cn]->m_speed = 0.001f;  //unit / ms

		//pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.pick_name_Obj[cn]);
		WP2_E.m_GameObj[cn] = IGNewAGameObject(WP2_E_rr->m_Mem, &WP2_E.err);
		IGAttachRootNodeToGameObject(WP2_E_rr->m_Mem, WP2_E.m_GameObj[cn], (IGNode *) WP2_E_rr->m_SceneNode, pNode, &WP2_E.err);
		IGScene_AddToGameObjectList(WP2_E_rr->m_Mem, WP2_E.m_GameObj[cn], &WP2_E.err);
	}

	for (cn = 0; cn < COUNT_PATH; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.path_name_Obj[cn]);
		WP2_E.m_Path[cn] = pNode;
	}

	for(cn = 0; cn < COUNT_CLOUD; cn = cn + 1)//讀取雲模型, 四方板
	{
		WP2_E.m_CloudObj[cn] = (IGNode *) V3Retained_GetGroup(WP_NameStruct.cloud_name_Obj[cn]);
	}

	for(cn = 0; cn < COUNT_CLOUDPATH; cn = cn + 1)//讀取雲路徑
	{
		WP2_E.m_CloudPath[cn] = (IGNode *) V3Retained_GetGroup(WP_NameStruct.cloudpath_name_Obj[cn]);
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

	WP2_E.m_Event = CQueue_New(DEFAULT_QUEUE_SIZE);

	WP2_E.m_AniInfo = V3Retained_GenerateAniInfo();
	IGNode_getPosition(WP2_E_rr->m_Mem, (IGNode *)WP2_E_rr->m_CameraControl, WP2_E.m_CameraPosition, &WP2_E.err);

	/*
		WP2_E_CashStatus_EventAni(WP2_E.m_Plane, WP2_E.m_GameTime, 1);
		for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
		{
			WP2_E_CashStatus_EventPathFall(WP2_E.m_OBJ[cn], WP2_E.m_GameTime, WP2_E.m_Path[cn]);
		}
*/
	WP2_E.m_DegreeInc = 1;
	WP2_E.m_TimeFactor = 1;
	WP2_E.m_CurrentCashTexture = 0;
	WP2_E.m_TouchTimeStart = 0;
	WP2_E.m_bNoCash = 0;

	return 0;
}

int WP2_E_OnStartup(void)
{
	WP2_E_InitArrayPool();
	CMemset(&WP2_E, sizeof(WP2_E), 0);
	WP2_E.fDegree = 0;
	V3Retained_LoadBackgroundTexture(png_WP2_E_back);
	WP2_E.m_bLoadWorld = 0;

	return 0;
}

int WP2_E_LoadWorld(void)
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
	WP2_E.m_World = V3World_New(igf_WP2_E, texs, tex, "Scene Root", "Camera_control", "ANIMATE0");

	V3Retained_LoadWorld(WP2_E.m_World);

	WP2_E_rr = V3Retained_GetInstance();

	//IGCamera_setViewMode(rr->m_Mem, rr->m_Camera, IGVIEW_PARALLEL, &err);
	//WP2_E.m_CameraFov = IG_ONE / 5;
	//IGCamera_setParallelFieldOfView(rr->m_Mem, rr->m_Camera, WP2_E.m_CameraFov, &err);
	//IGCamera_setPerspectiveFieldOfView(rr->m_Mem, rr->m_Camera, IG_ONE * 1.7, &err);

	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup("plane-track01");
		WP2_E.m_Plane = WP2_E_CashStatus_New(pNode, "plane-track01", "ANIMATE1");
	}

	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.node_name_Obj[cn]);
		WP2_E.m_Obj[cn] = pNode;

		WP2_E.m_OBJ[cn] = WP2_E_CashStatus_New(pNode, WP_NameStruct.node_name_Obj[cn], "ANIMATE0");
		WP2_E.m_OBJ[cn]->m_speed = 0.001f;  //unit / ms

		//pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.pick_name_Obj[cn]);
		WP2_E.m_GameObj[cn] = IGNewAGameObject(WP2_E_rr->m_Mem, &WP2_E.err);
		IGAttachRootNodeToGameObject(WP2_E_rr->m_Mem, WP2_E.m_GameObj[cn], (IGNode *) WP2_E_rr->m_SceneNode, pNode, &WP2_E.err);
		IGScene_AddToGameObjectList(WP2_E_rr->m_Mem, WP2_E.m_GameObj[cn], &WP2_E.err);
	}

	for (cn = 0; cn < COUNT_PATH; cn = cn + 1)
	{
		IGNode *pNode = (IGNode *) V3Retained_GetGroup(WP_NameStruct.path_name_Obj[cn]);
		WP2_E.m_Path[cn] = pNode;
	}

	for(cn = 0; cn < COUNT_CLOUD; cn = cn + 1)//讀取雲模型, 四方板
	{
		WP2_E.m_CloudObj[cn] = (IGNode *) V3Retained_GetGroup(WP_NameStruct.cloud_name_Obj[cn]);
	}

	for(cn = 0; cn < COUNT_CLOUDPATH; cn = cn + 1)//讀取雲路徑
	{
		WP2_E.m_CloudPath[cn] = (IGNode *) V3Retained_GetGroup(WP_NameStruct.cloudpath_name_Obj[cn]);
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
	WP2_E.m_Event = CQueue_New(DEFAULT_QUEUE_SIZE);

	WP2_E.m_AniInfo = V3Retained_GenerateAniInfo();
	IGNode_getPosition(WP2_E_rr->m_Mem, (IGNode *)WP2_E_rr->m_CameraControl, WP2_E.m_CameraPosition, &WP2_E.err);

	WP2_E.m_DegreeInc = 1;
	WP2_E.m_TimeFactor = 1;
	WP2_E.m_CurrentCashTexture = 0;
	WP2_E.m_TouchTimeStart = 0;
	WP2_E.m_bNoCash = 0;

	return 0;
}

IGU32 WP2_E_GetElapsedTime(IGU32 _tick)
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

void WP2_E_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second)
{
	WP2_E.m_Hour = _hour;
	CTime_Set(&WP2_E.m_Time, _hour, _minute, _second);
}

int WP2_E_GetHour(void)
{
	return WP2_E.m_Hour;
}

IGGameObject *WP2_E_GetGameObj(IGNode *_pNode)
{
	IGGameObject *pObj = NULL;
	int cn = 0;

	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		if (WP2_E.m_OBJ[cn]->m_Node == _pNode)
		{
			pObj = WP2_E.m_GameObj[cn];
		}
	}
	return pObj;
}

void WP2_E_EventHTouchMove(int _pixel)
{
	int iPrev = WP2_E.m_HDegree;

	WP2_E.m_HDegree = WP2_E.m_HDegree + _pixel * WP2_E.m_DegreeInc;

	V3Retained_RotateCamera((float) (WP2_E.m_HDegree - iPrev), 0);
}

void WP2_E_Check(void)
{
	NodeAniStatus *pStatus = NULL;
	int cn, iAni, bStart = 1, iDelayTime;
	int iCashTexture = 0;

	pStatus = NodeAniStatusQueue_Head(WP2_E.m_Plane->m_Status);
	if (pStatus != NULL)
	{
		return;
	}

	if (WP2_E.m_bNoCash == 1)
	{
		iAni = RandomEvent_Random(1, 4);
		WP2_E_CashStatus_EventAni(WP2_E.m_Plane, WP2_E.m_GameTime, iAni);
		WP2_E.m_bNoCash = 0;
		return;
	}


	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		pStatus = NodeAniStatusQueue_Head(WP2_E.m_OBJ[cn]->m_Status);
		if (pStatus != NULL)
			bStart = 0;
	}

	if (bStart == 1)
	{
		iAni = RandomEvent_Random(1, 4);
		switch (iAni)
		{
		case 1:
			iDelayTime = 5000;
			break;
		default :
			iDelayTime = 10000;
			break;
		}
		iDelayTime = 3000;
		WP2_E_CashStatus_EventAni(WP2_E.m_Plane, WP2_E.m_GameTime, iAni);

		if (WP2_E.m_bNoCash == 1)
		{
			//按住 5 秒, 鈔票不落下
			WP2_E.m_bNoCash = 0;
		}
		else
		{
			for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
			{
				WP2_E_CashStatus_EventPathFall(WP2_E.m_OBJ[cn], WP2_E.m_GameTime + iDelayTime, WP2_E.m_Path[cn]);
			}

			iCashTexture = RandomEvent_Random(0, 2);
			if (iCashTexture != WP2_E.m_CurrentCashTexture)
			{
				V3Texture *tex = NULL;
				IGTexture *pCashOld = NULL, *pCashNew;

				tex = (V3Texture *) CArray_Get(WP2_E.m_World->m_pTextures, WP2_E.m_CurrentCashTexture);
				pCashOld = tex->m_Texture;
				tex = (V3Texture *) CArray_Get(WP2_E.m_World->m_pTextures, iCashTexture);
				pCashNew = tex->m_Texture;
		
				IGScene_switchTextures(V3Retained_GetMem(), WP2_E_rr->m_Scene, pCashOld, pCashNew, &WP2_E.err);
			}
		}
	}
}

void WP2_E_ProcessPick(int _pick_x, int _pick_y)
{
	IGErr err;
	IGPoint point;
	IGObjCache *pPickedObjs;
	IGPickedObject *picked;
	int cn, cn2, bPickOne;

	point.x = _pick_x;
	point.y = _pick_y;
	pPickedObjs = IGScene_PickSceneObjects(V3Retained_GetMem(), &point, &err);

	bPickOne = 0;
	for (cn = 0; cn < pPickedObjs->m_pointers.m_count; cn = cn + 1)
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
				if (picked->m_pObject->mRootNode == WP2_E.m_OBJ[cn2]->m_Node)
				{
					NodeAniStatus *pStatus = NULL;
					pStatus = NodeAniStatusQueue_Head(WP2_E.m_OBJ[cn2]->m_Status);
					if (pStatus != NULL)
						NodeAniStatus_Cut(pStatus, WP2_E.m_GameTime);
					bPickOne = 1;
					break;
				}
			}
			if (bPickOne == 1)
				break;
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

void WP2_E_ShowPic(IGTexture *pTex, int locX, int locY, int viewX, int viewY, int viewWidth, int viewHeight)
{
	IGPoint Loc;
	IGRect ViewRect;
	IGErr err;

	Loc.x = locX;
	Loc.y = locY;

	ViewRect.x1 = viewX;
	ViewRect.x2 = viewX + viewWidth;
	ViewRect.y1 = viewY;
	ViewRect.y2 = viewY + viewHeight;

	IGSprite_drawTrans(WP2_E_rr->m_Mem, WP2_E_rr->m_Renderer, &Loc, pTex, &ViewRect, IG_ONE, &err);
}

void WP2_E_ShowBack(IGTexture *pTex, int locX, int locY, int viewX, int viewY)
{
	IGPoint Loc;
	IGRect ViewRect;
	IGErr err = IGERR_NONE;
	
	Loc.x = locX;
	Loc.y = locY;
	ViewRect.x1 = viewX;
	ViewRect.x2 = pTex->m_width;
	ViewRect.y1 = viewY;
	ViewRect.y2 = pTex->m_height;
	
	IGSprite_drawTrans(WP2_E_rr->m_Mem, WP2_E_rr->m_Renderer, &Loc, pTex, &ViewRect, (igreal) (IG_ONE * 0.1f), &err);
}

void WP2_E_SetCloud_Position(void)
{
	AniInfo *ani_info = CNamedObjArray_Get(WP2_E.m_AniInfo, 6);
	float Pos[3];
	igreal Position[3];
	IGErr err = IGERR_NONE;
	int cn = 0;

	for(cn = 0; cn < 4; cn = cn + 1)
	{
		IGNode *pPathNode = WP2_E.m_CloudPath[cn];
		V3Retained_GetPathPosition(pPathNode, "ANIMATE6", WP2_E.m_GameTime % ani_info->m_Duration, Pos);
		//for (inCount = 0; inCount < 12; inCount = inCount++)WP2_E.m_CloudObj[cn]->m_oriMat[inCount] = pPathNode->m_oriMat[inCount];
		Position[0] = (igreal) (Pos[0] * IG_ONE);
		Position[1] = (igreal) (Pos[1] * IG_ONE);
		Position[2] = (igreal) (Pos[2] * IG_ONE);
		IGNode_setPosition(V3Retained_GetMem(), WP2_E.m_CloudObj[cn], Position, &err);
	}
}

void WP2_E_Update2D(unsigned char *_pFrameBuffer)
{
	V3Retained_Bind(_pFrameBuffer);
	V3UI_DrawImage2DCenter(WP2_E_rr->m_BackgroundTexture, 1.0f);
}

int WP2_E_Update3D(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	IGErr err = IGERR_NONE;

	IGSysEvent *pSE = NULL;
	AniInfo *ani_info = CNamedObjArray_Get(WP2_E.m_AniInfo, 1);
	int cn;
	V3Retained_Bind(_pFrameBuffer);

	/*
	if (!V3Retained_IsLoadingComplete())
	{
		V3Retained_LoadWorldContinue(WP2_E.m_World);
		if (V3Retained_IsLoadingInitValue())
		{
			WP2_E_OnStartupInitValue();
			V3Retained_LoadWorldEnd();
		}
		V3UI_SetTargetColor(_pFrameBuffer, 0xFFF0);
		return 0;
	}
	*/

	WP2_E.m_ElapsedTime = uFrameInterval;
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	//WP2_E.m_ElapsedTime = DebugInterval();
#endif
	WP2_E.m_GameTime = WP2_E.m_GameTime + WP2_E.m_ElapsedTime / WP2_E.m_TimeFactor;

	WP2_E_Check();
	// process platform events, only test touch down event (mouse left button down)
	while ((pSE = (IGSysEvent *) CQueue_Pop(WP2_E.m_Event)) != NULL)
	{
		switch (pSE->m_uEventID)
		{
		case IGFK_0 :
			{
				WP2_E.m_CameraFov = WP2_E.m_CameraFov - 100;
				IGCamera_setParallelFieldOfView(WP2_E_rr->m_Mem, WP2_E_rr->m_Camera, WP2_E.m_CameraFov, &err);
			}
			break;
		case IGFK_1 :
			{
				WP2_E.m_CameraFov = WP2_E.m_CameraFov + 100;
				IGCamera_setParallelFieldOfView(WP2_E_rr->m_Mem, WP2_E_rr->m_Camera, WP2_E.m_CameraFov, &err);
			}
			break;
		case IGFK_TOUCH1_DOWN :
			{
				WP2_E.iMouseX = pSE->m_uData1;
				WP2_E.iMouseY = pSE->m_uData2; 
				WP2_E_ProcessPick(pSE->m_uData1, pSE->m_uData2);
				WP2_E.m_TouchTimeStart = WP2_E.m_GameTime;
			}
			break;
		case IGFK_TOUCH1_UP :
			WP2_E.iMouseX = pSE->m_uData1;
			WP2_E.iMouseY = pSE->m_uData2;

			if ((WP2_E.m_GameTime - WP2_E.m_TouchTimeStart) > 3000)
			{
				WP2_E.m_bNoCash = 1;
			}
			WP2_E.m_TouchTimeStart = 0;
			break;

		case IGFK_TOUCH1_MOVE :
			WP2_E_EventHTouchMove(pSE->m_uData1 - WP2_E.iMouseX);
			WP2_E.iMouseX = pSE->m_uData1;
			WP2_E.iMouseY = pSE->m_uData2; 
			break;
		case IGFK_LEFT_ARROW:
			{
			}
			break;

		case IGFK_RIGHT_ARROW:
			{
			}
			break;
		case IGFK_UP_ARROW:
			{
			}
			break;
		case IGFK_DOWN_ARROW:
			{
			}
			break;
		}

		WP2_E_Free(pSE);
	}
 
	//V3Retained_UpdateScene("ANIMATE1", (WP2_E.m_GameTime/3) % ani_info->m_Duration);
	/*
	IGNode_setPosition(rr->m_Mem, (IGNode *) rr->m_Camera, WP2_E.m_CameraPosition, &err);
	{
		float deg_hh, deg_mm, deg_ss;

		deg_hh = (WP2_E.m_Time.m_Hour % 12) * 2.0f / 12.0f;
		deg_mm = WP2_E.m_Time.m_Min * 2.0f / 60.0f;
		deg_ss = WP2_E.m_Time.m_Sec * 2.0f / 60.0f;
		IGNode_rotateY(V3Retained_GetMem(), (IGNode *) WP2_E.m_Obj[0], (igreal) (IG_PI * deg_hh), &err);
		IGNode_rotateY(V3Retained_GetMem(), (IGNode *) WP2_E.m_Obj[1], (igreal) (IG_PI * deg_mm), &err);
		IGNode_rotateY(V3Retained_GetMem(), (IGNode *) WP2_E.m_Obj[2], (igreal) (IG_PI * deg_ss), &err);
	}
	*/

	WP2_E_CashStatus_Update(WP2_E.m_Plane, WP2_E.m_GameTime);
	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		WP2_E_CashStatus_Update(WP2_E.m_OBJ[cn], WP2_E.m_GameTime);
	}
	
	//IGNode_setPosition(rr->m_Mem, (IGNode *) rr->m_CameraControl, WP2_E.m_CameraPosition, &err);
	
	V3Retained_Render();

	//設定雲面板的相關資訊
	WP2_E_SetCloud_Position();

	return 0;
}

int WP2_E_SafeCheck(void)
{
	int iOK = 1;
	int iFAIL = 0;
	int iRESULT = iFAIL;
	int cn = 0;

	for(cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		if(WP2_E.m_OBJ[cn] == NULL)
		{
			iRESULT = iFAIL;
			return iRESULT;
		}
		else
		{
			iRESULT = iOK;
		}
	}


	if(WP2_E.m_Plane != NULL)
	{
		iRESULT = iOK;
	}
	else
	{
		iRESULT = iFAIL;
		return iRESULT;
	}

	return iRESULT;
}

int WP2_E_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	WP2_E_rr = V3Retained_GetInstance();

	switch (WP2_E.m_bLoadWorld)
	{
	case 0 :
		WP2_E_Update2D(_pFrameBuffer);
		WP2_E.m_bLoadWorld = 1;
		break;
	case 1:
		WP2_E_LoadWorld();
		WP2_E_Update2D(_pFrameBuffer);
		WP2_E.m_bLoadWorld = 2;
		break;
	case 2:
		if(WP2_E_SafeCheck() == 1)//讀取完畢, 放行
		{
			WP2_E_SetCloud_Position();//Odin, 加這行, 是因為雲模型的預設位置在鏡頭前面, 會造成殘影, 所以要移開
			V3Retained_ActiveBackgroundTexture();
			WP2_E_Update3D(_pFrameBuffer, uFrameInterval);
			WP2_E.m_bLoadWorld = 3;
		}
		else//還在讀取 繼續等等
		{
			WP2_E_Update2D(_pFrameBuffer);
		}
		break;
	case 3:
		WP2_E_Update3D(_pFrameBuffer, uFrameInterval);
		break;
	}

	return 0;
}

void WP2_E_OnShutdown(int appId)
{
	int cn = 0;
	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		if(WP2_E.m_OBJ[cn] != NULL)
		{
			WP2_E_CashStatus_Del(WP2_E.m_OBJ[cn]);
			WP2_E.m_OBJ[cn] = NULL;
		}
	}
	
	if(WP2_E.m_Plane != NULL)
	{
		WP2_E_CashStatus_Del(WP2_E.m_Plane);
		WP2_E.m_Plane = NULL;
	}
	//WP2_E_CashStatus_InitArrayPool();marked by Odin, 不知道為什麼呼叫, 感覺沒必要, 避免意外, 先mark處理, 日後刪除
	if(WP2_E.m_Event != NULL)
	{
		CQueue_Del(WP2_E.m_Event);
		WP2_E.m_Event = NULL;
	}

	if(WP2_E.m_World != NULL)
	{
		V3World_Del(WP2_E.m_World);
		WP2_E.m_World = NULL;
	}
	
	if(WP2_E.m_AniInfo != NULL)
	{
		CArray_Del(WP2_E.m_AniInfo);
		WP2_E.m_AniInfo = NULL;
	}
	
	if(WP2_E.pStatusArray != NULL)
	{
		CDel(WP2_E.pStatusArray);
		WP2_E.pStatusArray = NULL;
	}

	if(WP2_E.pStatusArrayPool != NULL)
	{
		CDel(WP2_E.pStatusArrayPool);
		WP2_E.pStatusArrayPool = NULL;
	}
	
	if(pWP2_E_StatusArrayPool != NULL)
	{
		CDel(pWP2_E_StatusArrayPool);
		pWP2_E_StatusArrayPool = NULL;
	}
	
	if(pWP2_E_StatusArray != NULL)
	{
		CDel(pWP2_E_StatusArray);
		pWP2_E_StatusArray = NULL;
	}

	V3Retained_End(appId);
}



#ifdef __cplusplus
}
#endif
