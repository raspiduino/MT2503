//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3-D
// File        : 手機魚缸桌布 -- WP3-D-GameApp.h
// Description : 遊戲主架構
// Author      : Ray
// Create      : 2010-11-16
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP3_D_GAME_APP_H__
#define __WP3_D_GAME_APP_H__

#include "GameDef.h"
#include "V3DataDef.h"
#include "IGScene.h"
#include "IGGameObject.h"

#include "WP3-D-FishStatus.h"
#include "WP3-D-Name.h"
#include "CUtils.h"

#ifdef __cplusplus
extern "C" {
#endif

#define FISH_MIN	500
#define FISH_MAX	3000

struct _WP3_D
{
	int iObj;
	int iMouseX,Ymouse,mouseL,pickonce;

	CArrayPool *pStatusArrayPool;//請注意, 這個指標是給FishStatus裡頭操作
	NodeAniStatus *pStatusArray;//請注意, 這個指標是給FishStatus裡頭操作

	IGErr err;

	IGU8	m_bGameActive;

	IGU32	m_GameTime;	//從進入程式開始算, GameFlow & GameFlowDisplay 的 fGameTime 是從一場遊戲開始算
	IGU32	m_ElapsedTime;
	IGU8	m_TimeFactor;

	IGU8	m_Hour;
	IGU8	m_TimeMode; //葉片位置是否要隨時間改變
	CTime	m_Time;
	int			m_bLoadWorld;
	CQueue	*m_Event;
	int				m_thisfood[2];
	int				memover;
	int				anispeed;
	WPFishStatus	*m_WP;
	IGNode			*m_Grass[4];
	IGNode			*m_Bubble[2];
	WPFishStatus	*m_allbubble;
	WPFishStatus	*m_OBJ[COUNT_OBJ];
	WPFishStatus	*fishstatus[4];
	WPFishStatus	*substatus;
	WPFishStatus	*food[4];
	WPFishStatus	*bubbleall;
	IGGameObject	*m_GameObj[COUNT_OBJ];
	WPFishStatus	*m_Food[4];
	IGNode			*m_ObjBody[COUNT_OBJ];
	IGNode			*m_Path[COUNT_PATH];
	IGGameObject	*m_GamePath[COUNT_PATH];
	int		m_CurrentLoop;

	CRect	m_RectFeed, m_RectLight;

	EventStatus	m_CheckObj;

	CArray	*m_AniInfo;

	int		m_HDegree, m_VDegree, m_DegreeInc;
};

extern struct _WP3_D WP3_D;

extern int WP3_D_PrepareConfig(IGV3Config *pPC);
extern void WP3_D_InitArrayPool(void);
extern void WP3_D_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4);
extern void WP3_D_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2);
extern void WP3_D_ClearPendingEvents(void);
extern IGSysEvent *WP3_D_GetEvent(void);
extern int WP3_D_Random(int _min, int _max);

/**
* Called when platform startup the application
* * @param pPC
*   Pointer to the IGPlatformConfig provided by IGGame Framework
* @return
*   0 means application successfully initialize the application, otherwize returns application dependent error code
* @see IGGame_OnShutdown
*/
extern int WP3_D_OnStartup(void);
extern IGGameObject *WP3_D_GetGameObj(IGNode *_pNode);
extern IGGameObject *WP3_D_GetGamePath(IGNode *_pNode);

extern IGU32 WP3_D_GetElapsedTime(IGU32 _tick);
extern void WP3_D_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second);
extern int WP3_D_GetHour(void);

/**
* Called when platform wants application to render & update itself
* * @param uFrameInterval
*   Time interval (integer, millisecond) between previous frame and this frame. 
* * @param uNumSysEvents
*   Number of system fired events captured by IGGame Framework since previous frame.
* * @param pSE
*   Pointer to the IGSysEvent structure provided by IGGame Framework
* @return
*   0 means application successfully update and render irslef, otherwize returns application dependent error code, 
*   IGGame Framework will then call IGGame_OnShutdown to terminate the application
* @see IGGame_OnShutdown
*/
extern int WP3_D_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval);
 

/**
* Called when platform wants application to ternimate
* @see IGGame_OnShutdown
*/
extern void WP3_D_OnShutdown(int appId);


#ifdef __cplusplus
}
#endif


#endif //__GAME_APP_H__
