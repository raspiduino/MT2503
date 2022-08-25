//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3-B
// File        : WP3-B-DogStatus.h
// Description : C »y¨¥ 3D ª«¥óª¬ºA
// Author      : Ray
// Create      : 2010-12-01
// Update      : 2011-02-15
//==============================================================================

#ifndef __C_WP3_B_STATUS_H__
#define __C_WP3_B_STATUS_H__

#include "IGScene.h"
#include "CNodeStatus.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

struct _WP2_E_CashStatus
{
	char	m_Name[DEFAULT_NAME_SIZE];
	char	m_AniName[DEFAULT_NAME_SIZE];
	float	m_px, m_py, m_pz, m_speed;
	IGNode	*m_Node;
	int		m_Path;
	CQueue	*m_Status;
};

typedef struct _WP2_E_CashStatus WP2_E_CashStatus;

typedef enum {
	WP_LOOP_0,
	WP_LOOP_1,
	WP_LOOP_DEFAULT,
	WP_ANIM_01,
	WP_ANIM_02,
	WP_ANIM_03,
	WP_ANIM_04,
} WPEvent;

extern WP2_E_CashStatus *WP2_E_CashStatus_New(IGNode *_pNode, const char *_Name, const char *_AniName);
extern void WP2_E_CashStatus_Del(WP2_E_CashStatus *_this);
extern void WP2_E_CashStatus_Event(WP2_E_CashStatus *_this, IGU32 _Time, WPEvent _event);
extern void WP2_E_CashStatus_Update(WP2_E_CashStatus *_this, IGU32 _Time);
extern void WP2_E_CashStatus_AddEvent(WP2_E_CashStatus *_this, IGU32 _TimeBegin, WPEvent _event);
extern NodeAniStatus *WP2_E_CashStatus_CurrentStatus(WP2_E_CashStatus *_this, IGU32 _Time);

extern void WP2_E_CashStatus_EventPathFall(WP2_E_CashStatus *_this, IGU32 _GameTime, IGNode *_path);
extern void WP2_E_CashStatus_PathFall(WP2_E_CashStatus *_this, IGU32 _GameTime, IGNode *_path);

extern void WP2_E_CashStatus_EventLoop0(WP2_E_CashStatus *_this, IGU32 _GameTime);
extern void WP2_E_CashStatus_EventLoop1(WP2_E_CashStatus *_this, IGU32 _GameTime);
extern void WP2_E_CashStatus_EventAni(WP2_E_CashStatus *_this, IGU32 _GameTime, int _iAni);

extern void WP2_E_CashStatus_Loop0(WP2_E_CashStatus *_this, IGU32 _GameTime);
extern void WP2_E_CashStatus_Loop1(WP2_E_CashStatus *_this, IGU32 _GameTime);

extern void WP2_E_CashStatus_Ani(WP2_E_CashStatus *_this, IGU32 _GameTime, int _iAni);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__C_WP_STATUS_H__

