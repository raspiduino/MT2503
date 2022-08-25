//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP4-A
// File        : WP4-A-GameApp.h
// Description : 手機變形金剛桌布 -- 遊戲主架構
// Author      : Ray
// Create      : 2010-12-14
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP4_A_GAME_APP_H__
#define __WP4_A_GAME_APP_H__

#include "GameDef.h"
#include "V3DataDef.h"
#include "IGScene.h"
#include "WP4-A-Name.h"
#include "CUtils.h"
#include "CNodeStatus.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TIME_MIN	10000
#define TIME_MAX	12000

struct _WP4_A
{
	IGErr err;
	IGU8	m_bGameActive;
	IGU32	m_GameTime;	//從進入程式開始算, GameFlow & GameFlowDisplay 的 fGameTime 是從一場遊戲開始算
	IGU32	m_ElapsedTime;
	IGU8	m_TimeFactor;
	IGU8	m_Hour;
	IGU8	m_TimeMode; //葉片位置是否要隨時間改變
	IGU32	m_AniTime[5];
	CQueue	*m_Event;
	EventStatus		m_TimeEvent;
	int					m_bLoadWorld;
	IGNode			*m_pObj[COUNT_OBJ];					//全部模型節點指標, 也就一個模型可供控制...-.,-
	CArray			*m_AniInfo;							//紀錄所有動畫資訊
	signed int				m_CurrentAni;						//紀錄目前正播放哪個動畫
	signed int		m_PausedAni;						//紀錄目前已經被暫停的動畫編號, -1表示空值, 其他號碼代表要解除暫停時還原用的動畫編號
	signed int		m_CurrentAniTimePassed;				//目前正播放的動畫, 時間進度, -1表示沒動畫, 可能是靜止, 可能是正在播LOOP
	//int				m_isCarState;						//紀錄目前模型的狀態, 0:機器人 1:車
	signed int		m_LoopDirection;					//紀錄目前Loop是順著播放還是倒著播放, 1:順播, -1:倒播
	int				m_isTouchMove;						//紀錄目前使用者是否正嚐試進行touch move, 0:未進行, 1:正在進行, 由touch up事件 進行重置
	int				m_isPauseAni;						//紀錄目前是否暫停動畫, 0:暫停, 1:不暫停
	int				m_isTransformationable;				//紀錄目前是否可以插入變形動畫, 0:不可 1:可
	int				m_isLoop;							//紀錄目前是否正在閒置狀態, 0:不是, 1=是
	int		iMaxDeg1;//邊緣角度極限值(左)
	int		iMaxDeg2;//邊緣角度緩衝值(左)
	int		iMinDeg1;//邊緣角度極限值(右)
	int		iMinDeg2;//邊緣角度緩衝值(右)
	int		iMiddleDeg;//鏡頭角度(中心值)
	int		isRecovering;//是否正進行視角補正, 1:正在進行, 0:未進行

	unsigned int	m_PauseTime;						//紀錄使用者按下暫停時的[遊戲時間], 用以讓動畫的播放持續延後
	unsigned int	m_PauseAniTime;						//紀錄使用者按下暫停時的動畫播放到哪裡, 用以讓動畫停格 & 解除暫停後繼續播放
	int				m_isGlassShow;						//紀錄是否顯示玻璃破碎的畫面, 0:顯示, 1:顯示
	IGU32			m_RandomPlayAniTime;				//紀錄遊戲開始閒置的起始時間, 0:表示目前不在閒置狀態
	int				m_HDegree, m_VDegree, m_DegreeInc;	//旋轉功能, 目前水平旋轉幾度, 目前垂直旋轉幾度, 旋轉角度增量
	int				m_posZ, m_posInc;					//紀錄camera_control, Z軸座標, 座標增量
	int				m_ScaleInc;							//縮放的增量, 給camera_control用
	igreal			m_Scale[ 3 ];						//XYZ軸的縮放量, 給camera_control用
	IGPoint			m_logMouse;							//滑鼠座標資訊, 資訊暫存, 非真正的滑鼠座標
	IGPoint			m_downMouse;						//滑鼠座標資訊, 資訊暫存, 非真正的滑鼠座標, 用來記錄touch down的座標
	int				m_isAutoRotate;						//紀錄目前是否進行自動旋轉, 0:不轉, 1:轉
	signed int		m_iDir;								//紀錄自動旋轉模式轉動的方向, 正值向左, 負值向右
	int				m_isAutoScale;						//紀錄目前是否進行自動縮放鏡頭至合適的情況, 0:不動, 1:自動
	
};

extern struct _WP4_A WP4_A;

//extern int WP4_A_PrepareConfig(IGPlatformConfig *pPC);
extern int WP4_A_PrepareConfig(IGV3Config *pPC);
extern void WP4_A_InitArrayPool(void);
extern void WP4_A_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4);
extern void WP4_A_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2);
extern void WP4_A_ClearPendingEvents(void);
extern void WP4_A_Free(IGSysEvent *_this);
extern IGSysEvent *WP4_A_GetEvent(void);

//===
extern void WP4_A_initialValues(void);
extern void WP4_A_RandomAni(void);
extern void WP4_A_Transformation(void);
extern void WP4_A_HTouchMove(signed int _pixel);		//touch move, horizontal, Rotate
extern void WP4_A_VTouchMove(signed int _pixel);		//touch move, vertical, Scale
extern void WP4_A_translateZ(signed int iNum);
extern void WP4_A_ScaleXYZ(signed int iNum);
extern void WP4_A_TouchUp(void);
extern void WP4_A_ShowPic(IGTexture *pTex, int locX, int locY, int viewX, int viewY, int viewWidth, int viewHeight);
extern void WP4_A_SwitchAni(int iNum);
extern void WP4_A_PlayAni(void);
extern void WP4_A_PlayLoop(void);
extern void WP4_A_PauseAni(void);
extern void WP4_A_StopAni(void);
extern void WP4_A_EventAniEnd(int iNum);
extern void WP4_A_InputEvent(IGSysEvent *pSE);

/**
* Called when platform startup the application
* * @param pPC
*   Pointer to the IGPlatformConfig provided by IGGame Framework
* @return
*   0 means application successfully initialize the application, otherwize returns application dependent error code
* @see IGGame_OnShutdown
*/
extern int WP4_A_OnStartup(void);

extern IGU32 WP4_A_GetElapsedTime(IGU32 _tick);
extern void WP4_A_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second);
extern int WP4_A_GetHour(void);

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
extern int WP4_A_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval);



/**
* Called when platform wants application to ternimate
* @see IGGame_OnShutdown
*/
extern void WP4_A_OnShutdown(int appId);


#ifdef __cplusplus
}
#endif


#endif //__GAME_APP_H__
