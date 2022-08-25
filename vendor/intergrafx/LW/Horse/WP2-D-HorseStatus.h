//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WPSample2
// File        : CWPStatus.h
// Description : C »y¨¥ 3D ª«¥óª¬ºA
// Author      : Ray
// Create      : 2010-11-02
// Update      : 2011-02-15
//==============================================================================

#ifndef __C_WP_STATUS_H__
#define __C_WP_STATUS_H__

#include "IGScene.h"
#include "CNodeStatus.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

struct _WP2_D_HorseStatus
{
	char	m_Name[DEFAULT_NAME_SIZE];
	char	m_AniName[DEFAULT_NAME_SIZE];
	float	m_px, m_py, m_pz, m_speed;
	IGNode	*m_Node;
	int		m_Path;
	IGNode	*m_PathNode;
	const char *m_PathAniName;
	int		m_bPathPause;
	IGU32	m_PathDuration;
	IGU32	m_PathAniTime;
	igreal	m_Position[3];
	CQueue	*m_Status;
};

typedef struct _WP2_D_HorseStatus WP2_D_HorseStatus;


typedef enum {
	WP_LOOP_0,
	WP_LOOP_1,
	WP_LOOP_DEFAULT,
	WP_ANIM_01,
	WP_ANIM_02,
	WP_ANIM_03,
	WP_ANIM_04,
} WPEvent;

extern void WP2_D_HorseStatus_InitArrayPool(void);
extern WP2_D_HorseStatus *WP2_D_HorseStatus_New(IGNode *_pNode, const char *_Name, const char *_AniName);
extern void WP2_D_HorseStatus_Del(WP2_D_HorseStatus *_this);
extern void WP2_D_HorseStatus_Event(WP2_D_HorseStatus *_this, IGU32 _Time, WPEvent _event);
extern void WP2_D_HorseStatus_Update(WP2_D_HorseStatus *_this, IGU32 _Time);
extern NodeAniStatus *WP2_D_HorseStatus_CurrentStatus(WP2_D_HorseStatus *_this, IGU32 _Time);
extern int WP2_D_HorseStatus_IsLoop(WP2_D_HorseStatus *_this, IGU32 _Time);
extern void WP2_D_HorseStatus_ClearPath(WP2_D_HorseStatus *_this);
extern void WP2_D_HorseStatus_SetPath(WP2_D_HorseStatus *_this);
extern void WP2_D_HorseStatus_EventEat(WP2_D_HorseStatus *_this, IGU32 _GameTime);
extern void WP2_D_HorseStatus_EventLoop(WP2_D_HorseStatus *_this, IGU32 _GameTime, int _iAni);
extern void WP2_D_HorseStatus_EventTouchWalk(WP2_D_HorseStatus *_this, IGU32 _GameTime);
extern void WP2_D_HorseStatus_EventTouchStay(WP2_D_HorseStatus *_this, IGU32 _GameTime);
extern void WP2_D_HorseStatus_EventAni(WP2_D_HorseStatus *_this, IGU32 _GameTime, int iAni);
extern void WP2_D_HorseStatus_Loop(WP2_D_HorseStatus *_this, IGU32 _GameTime, int _iAni);
extern void WP2_D_HorseStatus_Stay(WP2_D_HorseStatus *_this, IGU32 _GameTime, IGU32 _Duration, float _px, float _py, float _pz);
extern void WP2_D_HorseStatus_Eat(WP2_D_HorseStatus *_this, IGU32 _GameTime, int _iAni, int _iTimes);
extern void WP2_D_HorseStatus_Ani(WP2_D_HorseStatus *_this, IGU32 _GameTime, int iAni);
extern void	WP2_D_HorseStatus_BirdEventLoop(WP2_D_HorseStatus *_this,IGU32 _GameTime);
extern void WP2_D_HorseStatus_SetBirdPath(WP2_D_HorseStatus *_this);
extern void WP2_D_HorseStatus_LoopDefault(WP2_D_HorseStatus *_this, IGU32 _GameTime);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__C_WP_STATUS_H__

