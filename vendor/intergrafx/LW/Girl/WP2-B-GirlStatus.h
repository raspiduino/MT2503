//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WPSample
// File        : CWPGirlStatus.h
// Description : C »y¨¥ 3D ª«¥óª¬ºA
// Author      : Ray
// Create      : 2010-10-25
// Update      : 2011-02-15
//==============================================================================

#ifndef __C_WP2_B_GIRL_STATUS_H__
#define __C_WP2_B_GIRL_STATUS_H__

#include "IGScene.h"
#include "CNodeStatus.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

struct _WP2_B_GirlStatus
{
	char	m_Name[DEFAULT_NAME_SIZE];
	char	m_AniName[DEFAULT_NAME_SIZE];
	IGNode	*m_Node;
	CQueue	*m_Status;
};

typedef struct _WP2_B_GirlStatus WP2_B_GirlStatus;

typedef enum {
	WP_LOOP_0,
	WP_LOOP_1,
	WP_LOOP_DEFAULT,
	WP_ANIM_01,
	WP_ANIM_02,
	WP_ANIM_03,
	WP_ANIM_04,
} WPEvent;

extern WP2_B_GirlStatus *WP2_B_GirlStatus_New(IGNode *_pNode, const char *_Name, const char *_AniName);
extern void WP2_B_GirlStatus_Del(WP2_B_GirlStatus *_this);
extern void WP2_B_GirlStatus_Event(WP2_B_GirlStatus *_this, IGU32 _Time, WPEvent _event);
extern void WP2_B_GirlStatus_Update(WP2_B_GirlStatus *_this, IGU32 _Time);
extern NodeAniStatus *WP2_B_GirlStatus_CurrentStatus(WP2_B_GirlStatus *_this, IGU32 _Time);
extern void WP2_B_GirlStatus_EventHTouchMove(WP2_B_GirlStatus *_this, int _pixel);
extern void WP2_B_GirlStatus_EventLoop(WP2_B_GirlStatus *_this, IGU32 _GameTime);
extern void WP2_B_GirlStatus_EventAni(WP2_B_GirlStatus *_this, IGU32 _GameTime, int _iAni);
extern void WP2_B_GirlStatus_Loop(WP2_B_GirlStatus *_this, IGU32 _GameTime);
extern void WP2_B_GirlStatus_Ani(WP2_B_GirlStatus *_this, IGU32 _GameTime, int _iAni);
extern void WP2_B_GirlStatus_EventAni(WP2_B_GirlStatus *_this, IGU32 _GameTime, int iAni);
extern void WP2_B_GirlStatus_Ani(WP2_B_GirlStatus *_this, IGU32 _GameTime, int iAni);
extern void WP2_B_GirlStatus_LoopDefault(WP2_B_GirlStatus *_this, IGU32 _GameTime);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__C_WP_STATUS_H__

