//==============================================================================
// Copyright (c)2005 InterGrafx, Inc. All rights reserved.
// Project     : M3D_LW_Lib
// File        : M3DDummyGroup.h
// Description : M3D 桌布公用程式
// Author      : Ray
// Create      : 2011-05-31
// Update      : 2010-07-14
//==============================================================================
#ifndef __M3D_DUMMY_GROUP_H__
#define __M3D_DUMMY_GROUP_H__

#include "M3DRenderer.h"
#include "M3DModel.h"
#include "M3DPhysics.h"
#include "M3DUtils.h"

#ifdef __cplusplus
extern "C" {
#endif

#define M3D_DEFAULT_DUMMY_GROUP_OBJECT_SLOT	16
#define M3D_DEFAULT_DUMMY_GROUP_SLOT			16

#define M3D_DUMMY_GROUP_TYPE_RANDOM_BY_OBJECT		0
#define M3D_DUMMY_GROUP_TYPE_RANDOM_BY_DUMMY		1

typedef struct _M3DDummyGroup
{
	M3DRenderer *m_rr;
	char		m_Name[M3D_DEFAULT_NAME_LENGTH];
	int			m_type;
	M3DModel	*m_Model;
	M3DSplitString	m_DummyNames;
	M3DNode		m_Object[M3D_DEFAULT_DUMMY_GROUP_OBJECT_SLOT];
	int			m_ObjectDummy[M3D_DEFAULT_DUMMY_GROUP_OBJECT_SLOT];
	float		m_ObjectTime[M3D_DEFAULT_DUMMY_GROUP_OBJECT_SLOT];
	CVector3f	m_DummyMeshPosition[M3D_DEFAULT_DUMMY_GROUP_SLOT];
	int			m_iTotalObject;
	int			m_iTotalDummy;
	M3DAniInfo	m_AniInfo;
	float		m_AnimationLength;
	float		m_TimeFactor;
} M3DDummyGroup;

extern M3DDummyGroup *M3DDummyGroup_New(M3DRenderer *_rr);
extern void M3DDummyGroup_Load(M3DDummyGroup *_this, unsigned char const *_data, long _data_length, char *_node_names);
extern void M3DDummyGroup_Release(M3DDummyGroup *_this);
extern void M3DDummyGroup_ReplaceTexture(M3DDummyGroup *_this, unsigned char *_data, long _data_length);

extern void M3DDummyGroup_Del(M3DDummyGroup *_this);
extern void M3DDummyGroup_SetType(M3DDummyGroup *_this, int _type);

extern void M3DDummyGroup_AddStaticDummies(M3DDummyGroup *_this, M3DModel *_model, char *_node_name_prefix);
extern void M3DDummyGroup_AddObject(M3DDummyGroup *_this, M3DModel *_model, char *_node_name);
extern void M3DDummyGroup_Attach(M3DDummyGroup *_this, int _dummy_idx, int _object_idx);
extern void M3DDummyGroup_AttachNext(M3DDummyGroup *_this, int _object_idx);
extern void M3DDummyGroup_AnimateStart(M3DDummyGroup *_this, int _object_idx);
extern void M3DDummyGroup_AnimateOnce(M3DDummyGroup *_this, int _object_idx, float _ElapsedTime);
extern void M3DDummyGroup_AnimateNormal(M3DDummyGroup *_this, float _GameTime);
extern void M3DDummyGroup_Animate(M3DDummyGroup *_this, float _ElapsedTime);
extern void M3DDummyGroup_Animate2(M3DDummyGroup *_this, float _ElapsedTime);

#ifdef __cplusplus
}
#endif

#endif

