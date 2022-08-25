//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP2-C
// File        : WP2-C-GameApp.h
// Description : 手機機械鐘桌布 -- 遊戲主架構
// Author      : Ray
// Create      : 2010-11-16
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP2_C_GAME_APP_H__
#define __WP2_C_GAME_APP_H__

#include "GameDef.h"
#include "V3DataDef.h"
#include "IGScene.h"
#include "WP2-C-Name.h"
#include "CUtils.h"
#include "CNodeStatus.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _WP2_C
{
	igreal iAngle;
	igreal add;
	int countback;
	long iGearTime;
	int iMouseX;
	int iMouseY;

	IGU8	m_bGameActive;

	IGU32	m_GameTime;	//從進入程式開始算, GameFlow & GameFlowDisplay 的 fGameTime 是從一場遊戲開始算
	IGU32	m_ElapsedTime;
	IGU8	m_TimeFactor;

	IGU8	m_Hour;
	IGU8	m_TimeMode; //葉片位置是否要隨時間改變
	CTime	m_Time;

	int		m_bTouchMove;
	IGU32	m_TouchTimeStart, m_GearTimeStart, m_ZoomTimeStart, m_MoveBackTimeStart;
	int		m_bLoadWorld;
	CQueue	*m_Event;
	IGNode	*m_Obj[COUNT_OBJ];
	igreal	m_CameraPosition[3];
	igreal	m_CameraOriPosition[3];
	igreal	m_CameraMinPosition[3];
	igreal	m_CameraFov;
	CArray	*m_AniInfo;
	int		m_HDegree, m_VDegree, m_DegreeInc;
	
};


extern struct _WP2_C WP2_C;
extern int  WP2_C_PrepareConfig(IGV3Config *pPC);
extern void WP2_C_InitArrayPool(void);
extern void WP2_C_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4);
extern void WP2_C_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2);
extern void WP2_C_ClearPendingEvents(void);
extern IGSysEvent *WP2_C_GetEvent(void);

/**
* Called when platform startup the application
* * @param pPC
*   Pointer to the IGPlatformConfig provided by IGGame Framework
* @return
*   0 means application successfully initialize the application, otherwize returns application dependent error code
* @see IGGame_OnShutdown
*/
extern int WP2_C_OnStartup(void);

extern IGU32 WP2_C_GetElapsedTime(IGU32 _tick);
extern void WP2_C_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second);
extern int WP2_C_GetHour(void);

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
extern int WP2_C_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval);
 

/**
* Called when platform wants application to ternimate
* @see IGGame_OnShutdown
*/
extern void WP2_C_OnShutdown(int appId);


#ifdef __cplusplus
}
#endif


#endif //__GAME_APP_H__
