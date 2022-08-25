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

struct _WPFishStatus
{
	char	m_Name[DEFAULT_NAME_SIZE];
	char	m_AniName[DEFAULT_NAME_SIZE];
	float	m_px, m_py, m_pz, m_speed;
	IGNode	*m_Node;
	int		m_Path;
	CQueue	*m_Status;
};

typedef struct _WPFishStatus WPFishStatus;


typedef enum {
	WP_LOOP_0,
	WP_LOOP_1,
	WP_LOOP_DEFAULT,
	WP_ANIM_01,
	WP_ANIM_02,
	WP_ANIM_03,
	WP_ANIM_04,
} WPEvent;

extern WPFishStatus *WPFishStatus_New(IGNode *_pNode, const char *_Name, const char *_AniName);
extern void WPFishStatus_Del(WPFishStatus *_this);
extern void WPFishStatus_Event(WPFishStatus *_this, IGU32 _Time, WPEvent _event);
extern void WPFishStatus_Update(WPFishStatus *_this, IGU32 _Time);
extern NodeAniStatus *WPFishStatus_CurrentStatus(WPFishStatus *_this, IGU32 _Time);
extern void WPFishStatus_Bubble(WPFishStatus *_this, IGU32 _GameTime);
extern void WPFishStatus_ClearPath(WPFishStatus *_this);
extern void WPFishStatus_EventPathSwim(WPFishStatus *_this, IGU32 _GameTime, IGNode *_path);
extern void WPFishStatus_EventPathEat(WPFishStatus *_this, IGU32 _GameTime, IGNode *_path);
extern void WPFishStatus_PathSwim(WPFishStatus *_this, IGU32 _GameTime, IGNode *_path);
extern void WPFishStatus_PathEat(WPFishStatus *_this, IGU32 _GameTime, IGNode *_path);
extern void WPFishStatus_FeedFood(WPFishStatus *_this, IGU32 _GameTime);
extern void WPFishStatus_LoopDefault(WPFishStatus *_this, IGU32 _GameTime);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__C_WP_STATUS_H__

