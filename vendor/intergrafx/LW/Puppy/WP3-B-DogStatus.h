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

struct _WP3_B_DogStatus
{
	char	m_Name[DEFAULT_NAME_SIZE];
	char	m_AniName[DEFAULT_NAME_SIZE];
	IGNode	*m_Node;
	CQueue	*m_Status;
};

typedef struct _WP3_B_DogStatus WP3_B_DogStatus;

typedef enum {
	WP_LOOP_0,
	WP_LOOP_1,
	WP_LOOP_DEFAULT,
	WP_ANIM_01,
	WP_ANIM_02,
	WP_ANIM_03,
	WP_ANIM_04,
} WPEvent;

extern WP3_B_DogStatus *WP3_B_DogStatus_New(IGNode *_pNode, const char *_Name, const char *_AniName);
extern void WP3_B_DogStatus_Del(WP3_B_DogStatus *_this);
extern void WP3_B_DogStatus_Event(WP3_B_DogStatus *_this, IGU32 _Time, WPEvent _event);
extern void WP3_B_DogStatus_Update(WP3_B_DogStatus *_this, IGU32 _Time);
extern NodeAniStatus *WP3_B_DogStatus_CurrentStatus(WP3_B_DogStatus *_this, IGU32 _Time);
extern void WP3_B_DogStatus_EventLoop0(WP3_B_DogStatus *_this, IGU32 _GameTime);
extern void WP3_B_DogStatus_EventAni(WP3_B_DogStatus *_this, IGU32 _GameTime, int _iAni);
extern void WP3_B_DogStatus_Loop0(WP3_B_DogStatus *_this, IGU32 _GameTime);
extern void WP3_B_DogStatus_Ani(WP3_B_DogStatus *_this, IGU32 _GameTime, int _iAni);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__C_WP_STATUS_H__

