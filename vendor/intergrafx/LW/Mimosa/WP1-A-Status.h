//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP1-A
// File        : WP1_A_Status.h
// Description : C »y¨¥ 3D ª«¥óª¬ºA
// Author      : Ray
// Create      : 2010-11-02
// Update      : 2011-02-15
//==============================================================================

#ifndef __C_WP1_A_STATUS_H__
#define __C_WP1_A_STATUS_H__

#include "IGScene.h"
#include "CNodeStatus.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

struct _WP1_A_Status
{
	char	m_Name[DEFAULT_NAME_SIZE];
	char	m_AniName[DEFAULT_NAME_SIZE];
	IGNode	*m_Node;
	CQueue	*m_Status;
};

typedef struct _WP1_A_Status WP1_A_Status;

typedef enum {
	MIMOSA_NONE,
	MIMOSA_LOOP_WIND1,
	MIMOSA_LOOP_WIND2,
	MIMOSA_LOOP_WIND3,
	MIMOSA_PICK_LEAF,
	MIMOSA_PICK_LEAF1,
	MIMOSA_PICK_LEAF2,
	MIMOSA_PICK_LEAF3,
	MIMOSA_PICK_LEAF4
} MimosaEvent;

typedef enum {
	WP_LOOP_0,
	WP_LOOP_1,
	WP_LOOP_DEFAULT,
	WP_ANIM_01,
	WP_ANIM_02,
	WP_ANIM_03,
	WP_ANIM_04,
} WPEvent;

extern WP1_A_Status *WP1_A_Status_New(IGNode *_pNode, const char *_Name, const char *_AniName);
extern void WP1_A_Status_Del(WP1_A_Status *_this);
extern void WP1_A_Status_Event(WP1_A_Status *_this, IGU32 _Time, WPEvent _event);
extern void WP1_A_Status_Update(WP1_A_Status *_this, IGU32 _Time);
extern void WP1_A_Status_AddEvent(WP1_A_Status *_this, IGU32 _TimeBegin, WPEvent _event);
extern NodeAniStatus *WP1_A_Status_CurrentStatus(WP1_A_Status *_this, IGU32 _Time);

extern void WP1_A_Status_EventHTouchMove(WP1_A_Status *_this, int _pixel);
extern void WP1_A_Status_EventVTouchMove(WP1_A_Status *_this, int _pixel);

extern void WP1_A_Status_EventFlower(WP1_A_Status *_this, IGU32 _GameTime);
extern void WP1_A_Status_Wind1(WP1_A_Status *_this, IGU32 _GameTime);
extern void WP1_A_Status_Wind2(WP1_A_Status *_this, IGU32 _GameTime, IGU8 _Times);
extern void WP1_A_Status_Wind3(WP1_A_Status *_this, IGU32 _GameTime, IGU8 _Times);

extern void WP1_A_Status_Leaf_Wind1(WP1_A_Status *_this, IGU32 _GameTime, IGU8 _Times);
extern void WP1_A_Status_Leaf_Wind2(WP1_A_Status *_this, IGU32 _GameTime, IGU8 _Times);
extern void WP1_A_Status_Leaf_Wind3(WP1_A_Status *_this, IGU32 _GameTime, IGU8 _Times);

extern void WP1_A_Status_EventLoop_Leaf(WP1_A_Status *_this, IGU32 _GameTime);
extern void WP1_A_Status_EventLoop0(WP1_A_Status *_this, IGU32 _GameTime);
extern void WP1_A_Status_EventLoop1(WP1_A_Status *_this, IGU32 _GameTime);
extern void WP1_A_Status_EventTouchLeaf(WP1_A_Status *_this, IGU32 _GameTime);
extern void WP1_A_Status_EventAni2(WP1_A_Status *_this, IGU32 _GameTime);
extern void WP1_A_Status_EventAni(WP1_A_Status *_this, IGU32 _GameTime, int iAni);

extern void WP1_A_Status_Loop0_Leaf(WP1_A_Status *_this, IGU32 _GameTime);
extern void WP1_A_Status_Loop0B(WP1_A_Status *_this, IGU32 _GameTime, int _iAmplitude);
extern void WP1_A_Status_Loop1B(WP1_A_Status *_this, IGU32 _GameTime);
extern void WP1_A_Status_Loop1(WP1_A_Status *_this, IGU32 _GameTime, int _iAmplitude);

extern void WP1_A_Status_Ani0A(WP1_A_Status *_this, IGU32 _GameTime, int _iAmplitude);
extern void WP1_A_Status_Ani0B(WP1_A_Status *_this, IGU32 _GameTime, int _iAmplitude, int _iTimes);
extern void WP1_A_Status_Ani0C(WP1_A_Status *_this, IGU32 _GameTime, int _iAmplitude);
extern void WP1_A_Status_Ani1A(WP1_A_Status *_this, IGU32 _GameTime);
extern void WP1_A_Status_Ani1C(WP1_A_Status *_this, IGU32 _GameTime);
extern void WP1_A_Status_Ani1(WP1_A_Status *_this, IGU32 _GameTime);
extern void WP1_A_Status_Ani1A(WP1_A_Status *_this, IGU32 _GameTime);
extern void WP1_A_Status_Ani1B(WP1_A_Status *_this, IGU32 _GameTime);
extern void WP1_A_Status_Ani2(WP1_A_Status *_this, IGU32 _GameTime);
extern void WP1_A_Status_Ani(WP1_A_Status *_this, IGU32 _GameTime, int iAni);

extern void WP1_A_Status_LoopDefault(WP1_A_Status *_this, IGU32 _GameTime);
extern void WP1_A_Status_LoopDefault_Append(WP1_A_Status *_this);
extern void WP1_A_Status_Anim01(WP1_A_Status *_this, IGU32 _GameTime, IGU8 _Times);
extern void WP1_A_Status_Anim02(WP1_A_Status *_this, IGU32 _GameTime, IGU8 _Times);
extern void WP1_A_Status_Anim03(WP1_A_Status *_this, IGU32 _GameTime, IGU8 _Times);
extern void WP1_A_Status_Anim04(WP1_A_Status *_this, IGU32 _GameTime, IGU8 _Times);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__C_WP_STATUS_H__

