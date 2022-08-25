//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP2-D
// File        : GameApp.h
// Description : 手機百駿圖桌布 -- 遊戲主架構
// Author      : Ray
// Create      : 2010-12-06
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP2_D_GAME_APP_H__
#define __WP2_D_GAME_APP_H__

#include "GameDef.h"
#include "V3DataDef.h"
#include "IGScene.h"
#include "WP2-D-HorseStatus.h"
#include "WP2-D-Name.h"
#include "CUtils.h"

#ifdef __cplusplus
extern "C" {
#endif

#define FISH_MIN	500
#define FISH_MAX	3000

struct _WP2_D
{
	CArrayPool *pStatusArrayPool;
	NodeAniStatus *pStatusArray;

	int pickonce;
	int iMouseX, iMouseY,Xmouse,Ymouse,mouseL;
	IGErr err;

	IGU8	m_bGameActive;

	IGU32	m_GameTime;	//從進入程式開始算, GameFlow & GameFlowDisplay 的 fGameTime 是從一場遊戲開始算
	IGU32	m_ElapsedTime;
	IGU8	m_TimeFactor;
	IGU8	m_Hour;
	IGU8	m_TimeMode; //葉片位置是否要隨時間改變
	CTime	m_Time;
	CQueue	*m_Event;
	WP2_D_HorseStatus	*m_WP;
	WP2_D_HorseStatus	*m_OBJ[COUNT_OBJ];
	IGGameObject		*m_GameObj[COUNT_OBJ];
	IGNode			*m_Path[COUNT_PATH];
	WP2_D_HorseStatus	*horse01status;
	WP2_D_HorseStatus	*horse02status;
	WP2_D_HorseStatus	*horse03status;
	WP2_D_HorseStatus	*horse04status;
	WP2_D_HorseStatus	*horse05status;
	WP2_D_HorseStatus	*birdstatus;
	WP2_D_HorseStatus	*wavestatus;
	
	int		anispeed;
	long	fivesecall;
	long	fivesecone;
	int		fivesecthis;
	int		wave;
	int		m_getrun;
	igreal	m_position[3];
	int		m_CurrentLoop;
	EventStatus	m_CheckObj;
	CArray	*m_AniInfo;

	int		m_bLoadWorld;

	int		m_HDegree, m_VDegree, m_DegreeInc;
	V3World *m_World;
};

extern struct _WP2_D WP2_D;

extern int WP2_D_PrepareConfig(IGV3Config *pPC);
extern void WP2_D_InitArrayPool(void);
extern void WP2_D_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4);
extern void WP2_D_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2);
extern void WP2_D_ClearPendingEvents(void);
extern IGSysEvent *WP2_D_GetEvent(void);

extern int WP2_D_GetHorseAniByPath(int _iPath);
extern int WP2_D_GetPathAniNumber(int _iPath);
extern const char *WP2_D_GetPathAniName(int _iPath);

/**
* Called when platform startup the application
* * @param pPC
*   Pointer to the IGPlatformConfig provided by IGGame Framework
* @return
*   0 means application successfully initialize the application, otherwize returns application dependent error code
* @see IGGame_OnShutdown
*/
extern int WP2_D_OnStartup(void);

extern IGU32 WP2_D_GetElapsedTime(IGU32 _tick);
extern void WP2_D_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second);
extern int WP2_D_GetHour(void);

extern IGGameObject *WP2_D_GetGameObj(IGNode *_pNode);
extern int WP2_D_GetPathAniNumber(int _iPath);

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
extern int WP2_D_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval);
 

/**
* Called when platform wants application to ternimate
* @see IGGame_OnShutdown
*/
extern void WP2_D_OnShutdown(int appId);


#ifdef __cplusplus
}
#endif


#endif //__GAME_APP_H__
