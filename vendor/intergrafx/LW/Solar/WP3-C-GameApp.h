//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3_C
// File        : WP3_C_GameApp.h
// Description : 手機太陽系桌布 -- 遊戲主架構
// Author      : Ray
// Create      : 2010-11-16
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP3_C_GAME_APP_H__
#define __WP3_C_GAME_APP_H__

#include "GameDef.h"
#include "V3DataDef.h"
#include "IGScene.h"
#include "WP3-C-Name.h"
#include "CUtils.h"
#include "CNodeStatus.h"

#ifdef __cplusplus
extern "C" {
#endif

#define FISH_MIN	500
#define FISH_MAX	3000

struct _WP3_C
{
	float fDegree;
	int lastmouse,timelast,countspeed;
	float rospeed;
	int iMouseX, iMouseY;
	long iStoneTime;

	IGU8	m_bGameActive;

	IGU32	m_GameTime;	//從進入程式開始算, GameFlow & GameFlowDisplay 的 fGameTime 是從一場遊戲開始算
	IGU32	m_ElapsedTime;
	IGU8	m_TimeFactor;

	IGU8	m_Hour;
	IGU8	m_TimeMode; //葉片位置是否要隨時間改變
	CTime	m_Time;

	CQueue	*m_Event;
	int			m_bLoadWorld;
	IGNode	*m_Obj[COUNT_OBJ];
	IGNode	*m_ObjBody[COUNT_OBJ];
	IGGameObject	*m_GameObj[COUNT_OBJ];
	IGNode	*m_Stone[COUNT_STONE];

	int		m_NodePicked;

	CArray	*m_AniInfo;
	int		m_Direction;

	int		m_HDegree, m_VDegree, m_DegreeInc;
};

extern struct _WP3_C WP3_C;

extern int  WP3_C_PrepareConfig(IGV3Config *pPC);
extern void WP3_C_InitArrayPool(void);
extern void WP3_C_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4);
extern void WP3_C_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2);
extern void WP3_C_ClearPendingEvents(void);
extern IGSysEvent *WP3_C_GetEvent(void);

/**
* Called when platform startup the application
* * @param pPC
*   Pointer to the IGPlatformConfig provided by IGGame Framework
* @return
*   0 means application successfully initialize the application, otherwize returns application dependent error code
* @see IGGame_OnShutdown
*/
extern int WP3_C_OnStartup(void);

extern IGU32 WP3_C_GetElapsedTime(IGU32 _tick);
extern void WP3_C_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second);
extern int WP3_C_GetHour(void);

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
extern int WP3_C_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval);
 

/**
* Called when platform wants application to ternimate
* @see IGGame_OnShutdown
*/
extern void WP3_C_OnShutdown(int appId);


#ifdef __cplusplus
}
#endif


#endif //__GAME_APP_H__
