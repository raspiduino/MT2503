//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP4-A
// File        : WP4-A-GameApp.c
// Description : 手機變形金剛桌布 -- 遊戲主架構
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

#include "IGSprite.h"
#include "IGGame.h"

#include "WP4-A-GameApp.h"
#include "V3DataDef.h"
#include "V3Retained.h"
#include "CUtils.h"
#include "CNodeStatus.h"
#include "WP4-A-Name.h"
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
		WP4_A_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	PC.m_uScrHeight = pPC->m_uScrHeight;
	PC.m_uScrWidth = pPC->m_uScrWidth;
	PC.m_pFrameBuffer = pPC->m_pFrameBuffer;
	PC.m_pMemBuffer = NULL;
	PC.m_MemSize = 0;

	WP4_A_PrepareConfig(&PC);
	WP4_A_OnStartup();

	return 0;
}

int IGGame_OnUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE)
{
	{
		SYSTEMTIME sys_time;
		GetLocalTime(&sys_time);
		WP4_A_SetLocalTime((IGU8)sys_time.wHour, (IGU8)sys_time.wMinute, (IGU8)sys_time.wSecond);
	}

	while (uNumSysEvents--) {
		WP4_A_PostEvent(pSE->m_uEventID, pSE->m_uTime, pSE->m_uData1, pSE->m_uData2);
	}

	//The resolution of the GetTickCount function is limited to the resolution of the system timer, which is typically in the range of 10 milliseconds to 16 milliseconds
	//這樣才不會造成時間差 = 0
	if (uFrameInterval > 0)
	{
		V3Retained *rr = V3Retained_GetInstance();
		WP4_A_OnUpdate(rr->PC.m_pFrameBuffer, uFrameInterval * 4800 / 32768);
	}

	return 0;
}

void IGGame_OnShutdown(void)
{
	WP4_A_OnShutdown();
}

#endif

//////////////////////////////////////////////////////// IGGame Framework Callback //////////////////////////////////////////

struct _WP4_A WP4_A;
static int	m_isCarState = 1;						//紀錄目前模型的狀態, 0:機器人 1:車

#define ENGINE_BUFFER_SIZE 8*1024*1024
//static unsigned char s_engineMemBuf[ENGINE_BUFFER_SIZE];

int WP4_A_PrepareConfig(IGV3Config *pPC)
{
	int err;
	IGV3Config PC;

	PC.m_uScrHeight = pPC->m_uScrHeight;
	PC.m_uScrWidth = pPC->m_uScrWidth;
	PC.m_pFrameBuffer = pPC->m_pFrameBuffer;
	if(pPC->m_pMemBuffer != NULL)
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

void WP4_A_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	char WP4_A_g_DebugMessage[128] = {0};
	sprintf(WP4_A_g_DebugMessage, _TEXT("[%010d] "), WP4_A.m_GameTime);
	sprintf(&WP4_A_g_DebugMessage[13], pFmt, _p1, _p2, _p3, _p4);
	OutputDebugString(WP4_A_g_DebugMessage);
#endif
}

CArrayPool *pWP4_A_StatusArrayPool = NULL;
IGSysEvent *pWP4_A_StatusArray = NULL;

void WP4_A_InitArrayPool(void)
{
	if(pWP4_A_StatusArrayPool == NULL)pWP4_A_StatusArrayPool = CNew(sizeof(CArrayPool));
	if(pWP4_A_StatusArray == NULL)pWP4_A_StatusArray = CNew(sizeof(IGSysEvent) * MAX_ARRAY_POOL);
	CArrayPool_Init(pWP4_A_StatusArrayPool, (void *) pWP4_A_StatusArray, sizeof(IGSysEvent) * MAX_ARRAY_POOL, sizeof(IGSysEvent));
}

IGSysEvent *WP4_A_Alloc(void)
{
	return (IGSysEvent *) CArrayPool_Alloc(pWP4_A_StatusArrayPool);
}

void WP4_A_Free(IGSysEvent *_this)
{
	CArrayPool_Free(pWP4_A_StatusArrayPool, (void *) _this);
}

void WP4_A_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2)
{
	IGSysEvent *pGE = WP4_A_Alloc();

	if(pGE == NULL)
	{
		WP4_A_InitArrayPool();
		pGE = WP4_A_Alloc();
	}

	pGE->m_uEventID = _Id;
	if (_Time == 0L)
		pGE->m_uTime = WP4_A.m_GameTime;
	else
		pGE->m_uTime = _Time;
	pGE->m_uData1 = _Data1;
	pGE->m_uData2 = _Data2;

	CQueue_Push(WP4_A.m_Event, (void *) pGE);
}

void WP4_A_ClearPendingEvents(void)
{
	CQueue_Clear(WP4_A.m_Event);
}

IGSysEvent *WP4_A_GetEvent(void)
{
	IGSysEvent *pR;

	pR = (IGSysEvent *) CQueue_Pop(WP4_A.m_Event);

	return pR;
}

//debug用的時間推進函式
/* 20110413 Odin, 消除所有靜態變數
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

IGU32 WP4_A_GetElapsedTime(IGU32 _tick)
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

void WP4_A_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second)
{
	WP4_A.m_Hour = _hour;
}

int WP4_A_GetHour(void)
{
	return WP4_A.m_Hour;
}

void WP4_A_initialValues(void)
{	
	int scaleValue = 0;
	WP4_A.m_GameTime = 0;//遊戲時間
	WP4_A.m_CurrentAni = -1;//目前正播放的動畫, -1表示沒有, 會切入Loop動畫
	WP4_A.m_CurrentAniTimePassed = -1;//目前正播放的動畫, 時間進度, -1表示沒動畫, 可能是靜止, 可能是正在播LOOP
	WP4_A.m_isLoop = 1;//預設為:靜置狀態, 也就是播放Loop動畫

	WP4_A.m_TimeFactor = 1;
	//m_isCarState = 1;
	WP4_A.m_isTransformationable = 1;
	WP4_A.m_isPauseAni = 1;
	WP4_A.m_PauseTime = 0;
	WP4_A.m_PauseAniTime = 0;
	WP4_A.m_RandomPlayAniTime = 0;
	WP4_A.m_isAutoRotate = 1;
	WP4_A.m_iDir = 1;
	WP4_A.m_isAutoScale = 1;
	WP4_A.m_isTouchMove = 0;
	
	WP4_A.m_Scale[0] = scaleValue;
	WP4_A.m_Scale[1] = scaleValue;
	WP4_A.m_Scale[2] = scaleValue;
	WP4_A.m_ScaleInc = 10;

	WP4_A.m_HDegree = 10000;
	WP4_A.m_VDegree = 0;
	WP4_A.m_DegreeInc = 500;

	WP4_A.m_posZ = 0;
	WP4_A.m_posInc = 10;

	WP4_A.m_isGlassShow = 0;

	WP4_A.iMaxDeg1 = 18000;
	WP4_A.iMaxDeg2 = 21000;
	WP4_A.iMiddleDeg = 10000;
	WP4_A.iMinDeg1 = 4000;
	WP4_A.iMinDeg2 = 1000;
}

V3Retained *WP4_A_rr = NULL;

int WP4_A_OnStartup(void)
{
	WP4_A_InitArrayPool();
	CMemset(&WP4_A, sizeof(WP4_A), 0);
	V3Retained_LoadBackgroundTexture(png_WP4_A_back);
	return 0;
}

int WP4_A_LoadWorld(void)
{
	V3Texture *tex = NULL;
	CArray *texs;
	V3World *world = NULL;
	int cn = 0;
	texs = V3Textures_New(NULL);
	//讀取貼圖材質
	for (cn = 0; cn < COUNT_BMP; cn = cn + 1)
	{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
		CArray_Add(texs, (void *) V3Texture_New(WP_NameStruct.bmp_array[cn], WP_NameStruct.file_bmp[cn], MASK_555_RED, MASK_555_GREEN, MASK_555_BLUE, WP_NameStruct.keycolor[cn]));
#else
		CArray_Add(texs, (void *) V3Texture_New(WP_NameStruct.bmp_array[cn], WP_NameStruct.file_bmp[cn], MASK_565_RED, MASK_565_GREEN, MASK_565_BLUE, WP_NameStruct.keycolor[cn]));
#endif
	}


	//建立世界資料物件
	world = V3World_New(igf_WP4_A, texs, tex, "Scene Root", "camera_control", "ANIMATE0");
	
	//根據世界資料物件創建渲染器實體
	V3Retained_LoadWorld(world);

	//取得渲染器物件實體
	WP4_A_rr = V3Retained_GetInstance();

	//設定透視視野FOV
	IGCamera_setPerspectiveFieldOfView(WP4_A_rr->m_Mem, WP4_A_rr->m_Camera, IG_ONE / (igreal)1.1, &WP4_A.err);//FOV = 1.1, 美術給的值
	
	//銷毀世界資料物件
	V3World_Del(world);

	//取得場景根節點
	//Obj_root = (IGNode *) V3Retained_GetGroup(WP_NameStruct.node_name_Obj_root);
	
	//建立時間亂數種子
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	srand( (unsigned)time( NULL ) );
#else
	{
	    kal_uint32 tick;
		kal_get_time(&tick);
		srand( (unsigned int)tick );
	}
#endif

	//讀取動畫資訊
	WP4_A.m_AniInfo = V3Retained_GenerateAniInfo();

	//讀取模型資料
	for(cn = 0; cn < COUNT_OBJ; cn = cn + 1)
		WP4_A.m_pObj[cn] = (IGNode*)V3Retained_GetNode(WP_NameStruct.node_name_Obj[cn]);

	//建立Event佇列
	WP4_A.m_Event = CQueue_New(DEFAULT_QUEUE_SIZE);
	WP4_A.m_bLoadWorld = 0;
	//初始化WP4_A內的變數
	WP4_A_initialValues();

	//糾正模型檔的玻璃貼圖
	IGNode_switchTextures(WP4_A_rr->m_Mem, WP4_A.m_pObj[1], WP4_A_rr->m_Textures[6], WP4_A_rr->m_Textures[2], &WP4_A.err);
	
	return 0;
}

//隨機動畫事件, 有自動區分目前模型是車 還是 機器人
void WP4_A_RandomAni(void)
{
	int iAni = 0;
	IGU32 checkMS = 5000;//靜置幾秒後播放隨機動畫

	//如果, 目前可以插入變形動畫, 也就是閒置中
	if(WP4_A.m_isTransformationable == 1 && WP4_A.m_isPauseAni == 1 && WP4_A.m_isLoop == 1)
	{
		if(WP4_A.m_RandomPlayAniTime == 0)		//如果, 目前處於閒置狀態, 紀錄一下當前的GameTime
		{
			WP4_A.m_RandomPlayAniTime = WP4_A.m_GameTime;
		}
		else
		{
			if(WP4_A.m_GameTime - WP4_A.m_RandomPlayAniTime >= checkMS)
			{
				WP4_A.m_isLoop = 0;							//紀錄進入非閒置狀態
				WP4_A.m_isTransformationable = 0;			//關閉變形權限
				WP4_A.m_isAutoRotate = 1;					//啟動自動旋轉
				if(m_isCarState == 0)		//機器人
				{
					iAni = RandomEvent_Random(5, 7);
					WP4_A_SwitchAni(iAni);
					//WP4_A_SwitchAni(6);
				}
				else							//汽車
				{
					iAni = RandomEvent_Random(9, 12);
					if(iAni == 12) iAni = 0;				//這是彌補車窗下上的動畫編號在0, 不方便加入random
					WP4_A_SwitchAni(iAni);
					//WP4_A_SwitchAni(11);
				}
				WP4_A.m_RandomPlayAniTime = 0;				//重置累積閒置時間
			}
		}
	}
}

//播放變形動畫&暫停動畫
void WP4_A_Transformation(void)
{
	if(WP4_A.m_isTransformationable == 1)
	{
		WP4_A.m_isTransformationable = 0;		//進入這個判斷區塊就是準備放變身動畫, 為了避免重複push, 所以一進來就關掉權限
		if(m_isCarState == 1)					//由車變機器人
		{
			m_isCarState = 0;
			WP4_A_SwitchAni(1);
		}
		else										//由機器人變車
		{
			m_isCarState = 1;
			WP4_A_SwitchAni(8);
		}
	}
	else if(WP4_A.m_CurrentAni == 1 || WP4_A.m_CurrentAni == 8 || WP4_A.m_CurrentAni == -1)							//如果現在不允許變身, 則執行暫停/解除暫停功能
	{
		//WP4_A_PauseAni();
	}
}

void WP4_A_HTouchMove(int _pixel)
{
	//int iMinDeg = -7300, iMaxDeg = 27000, iMiddle = (iMinDeg + iMaxDeg)/2 + 13000;
	int iMinDeg = WP4_A.iMinDeg2, iMaxDeg = WP4_A.iMaxDeg2, iGlassDeg = 20500;
	int rotateValue = WP4_A.m_HDegree + (_pixel * WP4_A.m_DegreeInc);

	//特殊情況檢查, 動畫6號無條件把鏡頭給挪到中央
	if(WP4_A.m_CurrentAni == 6)
	{
		rotateValue = iGlassDeg;
	}
	else if(rotateValue <= iMinDeg)
	{
		rotateValue = iMinDeg;
		WP4_A.m_iDir = WP4_A.m_iDir * (-1);
	}
	else if(rotateValue >= iMaxDeg)
	{
		rotateValue = iMaxDeg;
		WP4_A.m_iDir = WP4_A.m_iDir * (-1);
	}

	WP4_A.m_HDegree = rotateValue;
}

void WP4_A_ScaleXYZ(signed int iNum)
{
	//int iMin = 5000, iMax = 6000;
	int iMin = 6000, iMax = 6000;
	int scaleValue = WP4_A.m_Scale[0] + (iNum * WP4_A.m_ScaleInc);

	if(scaleValue < iMin)
		scaleValue = iMin;
	else if(scaleValue > iMax)
		scaleValue = iMax;

	WP4_A.m_Scale[0] = scaleValue;
	WP4_A.m_Scale[1] = scaleValue;
	WP4_A.m_Scale[2] = scaleValue;
}

void WP4_A_translateZ(signed int iNum)
{
	signed int iMinTranslateZ = -100, iMaxTranslateZ = 600;
	//int iMinTranslateZ = 800, iMaxTranslateZ = 900;
	int translateZValue = WP4_A.m_posZ + (iNum * WP4_A.m_posInc);

	if(translateZValue < iMinTranslateZ)
		translateZValue = iMinTranslateZ;
	else if(translateZValue > iMaxTranslateZ)
		translateZValue = iMaxTranslateZ;
	WP4_A.m_posZ = translateZValue;
}
void WP4_A_VTouchMove(signed int _pixel)
{
	WP4_A_ScaleXYZ(_pixel);
	WP4_A_translateZ(_pixel);
}

void WP4_A_TouchUp(void)
{
	if(WP4_A.m_isTouchMove == 0)
	{
		if(WP4_A.m_isLoop == 1 || WP4_A.m_isTransformationable == 0)//只要是閒置狀態就能觸發, 另一個條件是用來偵測變形中啟用暫停功能
		{
			WP4_A_Transformation();
			WP4_A.m_isLoop = 0;
		}
	}

	WP4_A.m_isTouchMove = 0;
}

void WP4_A_ShowPic(IGTexture *pTex, int locX, int locY, int viewX, int viewY, int viewWidth, int viewHeight)
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

	IGSprite_drawTrans(WP4_A_rr->m_Mem, WP4_A_rr->m_Renderer, &Loc, pTex, &ViewRect, IG_ONE, &err);
}

void WP4_A_SwitchAni(int iNum)
{
	WP4_A.m_CurrentAni = iNum;
	WP4_A.m_CurrentAniTimePassed = 0;
}

void WP4_A_PlayAni(void)
{
	AniInfo *ani_info = NULL;
	IGU32 iAniTime = 0;

	if(WP4_A.m_CurrentAni < 0)return;//安全機制, 避免播到-1的動畫
	
	//找出動畫資訊
	ani_info = (AniInfo *) CNamedObjArray_Get(WP4_A.m_AniInfo, WP4_A.m_CurrentAni);
	iAniTime = WP4_A.m_CurrentAniTimePassed + WP4_A.m_ElapsedTime;
	if(iAniTime > ani_info->m_Duration)
	{
		WP4_A_StopAni();
	}
	else
	{
		V3Retained_UpdateNode(WP4_A_rr->m_SceneNode, WP4_A_Name.ani_name[WP4_A.m_CurrentAni], iAniTime);
		WP4_A.m_CurrentAniTimePassed = iAniTime;
		if(WP4_A.m_CurrentAni == 6 && WP4_A.m_CurrentAniTimePassed > 1600) WP4_A.m_isGlassShow = 1;		//這個動作比較特殊, 所以多做個處理
	}
}

void WP4_A_PlayLoop(void)
{
	int iCarLoopNum = 9, iRobotLoopNum = 3;//利用哪段動畫的片段當Loop
	int iLoopStart = 10, iLoopEnd = 80;//loop的時間flag
	static int iAniTime = 0;

	//iAniTime += WP4_A.m_LoopDirection;
	iAniTime = iAniTime + WP4_A.m_LoopDirection;
	
	if(m_isCarState == 0)			//機器人
		V3Retained_UpdateNode(WP4_A_rr->m_SceneNode, WP4_A_Name.ani_name[iRobotLoopNum], iAniTime);
	else								//汽車
		V3Retained_UpdateNode(WP4_A_rr->m_SceneNode, WP4_A_Name.ani_name[iCarLoopNum], iAniTime);

	//切換Loop播放方向
	if(iAniTime >= iLoopEnd) WP4_A.m_LoopDirection = -1;
	if(iAniTime <= iLoopStart) WP4_A.m_LoopDirection = 1;
}

//暫停當前動畫 / 解除當前動畫暫停狀態
void WP4_A_PauseAni(void)
{
	return;//20110330, 會議決定, 取消暫停功能, Odin

	/*
	if (WP4_A.m_isPauseAni == 0)//目前暫停, 執行解除暫停
	{
		//play
		WP4_A.m_CurrentAni = WP4_A.m_PausedAni;
		WP4_A.m_PausedAni = -1;
		WP4_A.m_isPauseAni = 1;
	}
	else						//執行暫停
	{
		//pause
		WP4_A.m_PausedAni = WP4_A.m_CurrentAni;
		WP4_A.m_CurrentAni = -1;
		WP4_A.m_isPauseAni = 0;
	}
	*/
}

//終止當前動畫
void WP4_A_StopAni(void)
{
	WP4_A_EventAniEnd(WP4_A.m_CurrentAni);		//發出動畫結束的通知訊息
	WP4_A.m_CurrentAni = -1;					//重置播放動畫的數字
	WP4_A.m_CurrentAniTimePassed = -1;			//清空動畫播放進度記錄
}

void WP4_A_EventAniEnd(int iNum)
{
	//打開變形動畫權限
	WP4_A.m_isTransformationable = 1;
	//恢復為靜置狀態
	WP4_A.m_isLoop = 1;
	//關閉玻璃破碎的貼圖畫面
	WP4_A.m_isGlassShow = 0;
}

//是否為右邊, 1:目前是要恢復右邊, 0:目前要恢復左邊
void WP4_A_DegRecovery(signed int isRight)
{
	signed int iInc = 1;
	if(isRight != 1) iInc = iInc * -1;
	WP4_A.isRecovering = 1;
	WP4_A_HTouchMove(iInc);
}

//避免MTK沒提供ABS函式, 自己手工寫一個來用
int WP4_A_ABS(signed int iNum)
{
	int result = 0;
	
	if(iNum != 0)
	{
		if(iNum < 0) iNum = iNum * -1;

		result = iNum;
	}

	return result;
}

void WP4_A_InputEvent(IGSysEvent *pSE)
{
	int iRangeW = 0;//touch move touch up的事件轉換緩衝值, Width
	int iRangeH = 0;//touch move touch up的事件轉換緩衝值, Height

	iRangeW = WP4_A_rr->m_Renderer->m_buffs.m_width / 4;
	iRangeH = WP4_A_rr->m_Renderer->m_buffs.m_height / 5;

	if(pSE != NULL)
	{
		switch (pSE->m_uEventID)
		{
		case IGFK_TOUCH1_UP:
			{
				if(WP4_A.m_CurrentAni != 6 && WP4_A.m_CurrentAni != 11)
				{
					WP4_A_TouchUp();
				}
				//檢查攝影機角度有沒有落在左右緩衝區間內, 有就啟動自動角度校正
				WP4_A.isRecovering = 1;
			}
			break;
		case IGFK_TOUCH1_DOWN:
			{
				WP4_A.m_logMouse.x = pSE->m_uData1;
				WP4_A.m_logMouse.y = pSE->m_uData2;
				WP4_A.m_downMouse.x = pSE->m_uData1;
				WP4_A.m_downMouse.y = pSE->m_uData2;
				WP4_A.isRecovering = 0;
				
			}
			break;
		case IGFK_TOUCH1_MOVE:
			{
				if(WP4_A.m_CurrentAni != 6)
				{
					WP4_A_HTouchMove(pSE->m_uData1 - WP4_A.m_logMouse.x);
					WP4_A.m_logMouse.x = pSE->m_uData1;
					WP4_A.m_logMouse.y = pSE->m_uData2;

					//點擊緩衝值
					if(WP4_A_ABS(WP4_A.m_downMouse.x - pSE->m_uData1) > iRangeW || WP4_A_ABS(WP4_A.m_downMouse.y - pSE->m_uData2) > iRangeH)
					{
						WP4_A.m_isTouchMove = 1;
					}
				}
			}
			break;
		}
		WP4_A_Free(pSE);
	}
}

void WP4_A_Update2D(unsigned char *_pFrameBuffer)
{
	V3Retained_Bind(_pFrameBuffer);
	V3UI_DrawImage2DCenter(WP4_A_rr->m_BackgroundTexture, 1.0f);
}

int WP4_A_Update3D(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	IGErr err = IGERR_NONE;
	IGSysEvent *pSE = NULL;

	//綁定正確的rendering target, 這是因為手機上的rendering target有可能被MTK的其他程式給置換掉
	V3Retained_Bind(_pFrameBuffer);
	//時間流動間隔
	WP4_A.m_ElapsedTime = uFrameInterval;
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	//WP4_A.m_ElapsedTime = DebugInterval();//Debug時, 正確迫使時間流動
#endif
	//計算遊戲時間
	WP4_A.m_GameTime = WP4_A.m_GameTime + WP4_A.m_ElapsedTime / WP4_A.m_TimeFactor;

	//輸入事件處理
	while ((pSE = CQueue_Pop(WP4_A.m_Event)) != NULL)
		WP4_A_InputEvent(pSE);

	//檢查是否需要進行鏡頭自動校正, 且分辨是左校正或者右校正
	if(WP4_A.m_HDegree >= WP4_A.iMiddleDeg && WP4_A.m_HDegree >= WP4_A.iMaxDeg1 && WP4_A.isRecovering == 1)
		WP4_A_DegRecovery(0);//左校正
	else if(WP4_A.m_HDegree <= WP4_A.iMiddleDeg && WP4_A.m_HDegree <= WP4_A.iMinDeg1 && WP4_A.isRecovering == 1)
		WP4_A_DegRecovery(1);//右校正
	
	//靜置狀態隨機動畫
	WP4_A_RandomAni();
	
	//自動旋轉功能
	if(WP4_A.m_isAutoRotate == 1)WP4_A_HTouchMove(0);

	//自動縮放鏡頭功能
	if(WP4_A.m_isAutoScale == 1 && m_isCarState == 0 && WP4_A.m_isTouchMove == 0)WP4_A_VTouchMove(1);//機器人自動縮放鏡頭
	if(WP4_A.m_isAutoScale == 1 && m_isCarState == 1 && WP4_A.m_isTouchMove == 0)WP4_A_VTouchMove(-1);//車自動縮放鏡頭

	//播放動畫
	if(WP4_A.m_isLoop != 1)WP4_A_PlayAni(); else WP4_A_PlayLoop();
	
	//重置鏡頭狀態
	V3Retained_UpdateNode((IGNode*)WP4_A_rr->m_CameraControl, "ANIMATE0", 0);

	//鏡頭操控
	//Scale > Rotate > Translate
	//縮放, Scale
	IGNode_setScale(WP4_A_rr->m_Mem, (IGNode*)WP4_A_rr->m_CameraControl, WP4_A.m_Scale, &err);
	//旋轉, Rotate
	IGNode_rotateZ(WP4_A_rr->m_Mem, (IGNode*)WP4_A_rr->m_CameraControl, WP4_A.m_HDegree, &err);//水平旋轉
	//位移, Translate
	IGNode_translateZ(WP4_A_rr->m_Mem, (IGNode*)WP4_A_rr->m_CameraControl, WP4_A.m_posZ, &err);		

	//判斷是否顯示破玻璃
	if(WP4_A.m_isGlassShow != 1)//這裡做的是反向檢查, 這是因為玻璃模型預設顯示
	{
		igreal size[3];
		int iSize = 0;
		size[0] = iSize; size[1] = iSize; size[2] = iSize;
		IGNode_setScale(WP4_A_rr->m_Mem, WP4_A.m_pObj[1], size, &err);
	}

	//繪圖
	V3Retained_Render();
	
	return 0;
}

int WP4_A_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval)
{
	WP4_A_rr = V3Retained_GetInstance();

	switch (WP4_A.m_bLoadWorld)
	{
	case 0 :
		WP4_A_Update2D(_pFrameBuffer);
		WP4_A.m_bLoadWorld = 1;
		break;
	case 1:
		WP4_A_LoadWorld();
		V3Retained_ActiveBackgroundTexture();
        WP4_A_Update2D(_pFrameBuffer);  //add to fix MAUI_03170490
        //WP4_A_Update3D(_pFrameBuffer, uFrameInterval);  //mark to fix MAUI_03170490
		WP4_A.m_bLoadWorld = 2;
		break;
	case 2:
		WP4_A_Update3D(_pFrameBuffer, uFrameInterval);
		break;
	}
		return 0;
}

void WP4_A_OnShutdown(int appId)
{
	int cn = 0;

	
	if(WP4_A.m_AniInfo != NULL)
	{
		CArray_Del(WP4_A.m_AniInfo);
		WP4_A.m_AniInfo = NULL;
	}

	if(WP4_A.m_Event != NULL)
	{
		CQueue_Del(WP4_A.m_Event);
		WP4_A.m_Event = NULL;
	}

	for (cn = 0; cn < COUNT_OBJ; cn = cn + 1)
	{
		if(WP4_A.m_pObj[cn] != NULL)
		{
			CDel(WP4_A.m_pObj[cn]);
			WP4_A.m_pObj[cn] = NULL;
		}
	}
	
	if(pWP4_A_StatusArrayPool != NULL)
	{
		CDel(pWP4_A_StatusArrayPool);
		pWP4_A_StatusArrayPool = NULL;
	}
	
	if(pWP4_A_StatusArray != NULL)
	{
		CDel(pWP4_A_StatusArray);
		pWP4_A_StatusArray = NULL;
	}

	V3Retained_End(appId);
}

#ifdef __cplusplus
}
#endif
