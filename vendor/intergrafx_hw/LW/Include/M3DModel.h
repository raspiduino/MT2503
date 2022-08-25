//==============================================================================
// Project     : M3D_Lib
// File        : M3DModel.h
// Description : M3D ���ε{��
// Author      : Ray
// Create      : 2011-05-31
// Update      : 2010-11-11
//==============================================================================
#ifndef __M3D_MODEL_H__
#define __M3D_MODEL_H__

#include "M3DRenderer.h"
#include "M3DGameDef.h"
#include "M3DTextureManager.h"
#include "M3DUtils.h"

#include "IGV5Model.h"
#include "M3DPhysics.h"

#ifdef __cplusplus
extern "C" {
#endif

#define M3D_DEFAULT_ANIMATION_SLOT	32

typedef struct _M3DAnimation
{
	char	m_Name[M3D_DEFAULT_NAME_LENGTH];
	float	m_Start;
	float	m_End;
	float	m_Duration;
	float	m_TimeFactor;
} M3DAnimation;

typedef struct _M3DAniInfo
{
	M3DAnimation m_Animation[M3D_DEFAULT_ANIMATION_SLOT];
	float	m_TotalDuration;
	int		m_Count;
	int		m_Even;
} M3DAniInfo;

extern void M3DAniInfo_Init(M3DAniInfo *_this, char *_values);
extern void M3DAniInfo_InitEven(M3DAniInfo *_this, char *_values);
extern void M3DAniInfo_Append(M3DAniInfo *_this, float _duration);
extern void M3DAniInfo_Add(M3DAniInfo *_this, char *_name, float _iStart, float _iEnd);
extern void M3DAniInfo_AddByFrame(M3DAniInfo *_this, char *_name, int _iStart, int _iEnd, float _time_factor);
extern int  M3DAniInfo_GetIndex(M3DAniInfo *_this, char *_name);
extern M3DAnimation *M3DAniInfo_Get(M3DAniInfo *_this, int _index);
extern M3DAnimation *M3DAniInfo_GetByName(M3DAniInfo *_this, char *_name);

typedef struct _M3DModel
{
	char		m_Name[M3D_DEFAULT_NAME_LENGTH];
	M3DSplitString	*m_TextureName;

	M3DRenderer *m_rr;
	int			m_bLoaded;
	IGV5ModelNode	m_ModelNode;
	IGV5NameCache	m_TexCache;
	IGV5Model	m_Node;
	M3DAniInfo	m_AniInfo;
	int			m_iDefaultAnimation;
	int			m_iCurrentAnimation;
	char		*m_CurrentAnimationName;
	float		m_AnimationLength;
	int			m_iAnimateForward;
	float		m_Time;
	int			m_Stop;
	float		m_TimeFactor;
	float		m_DegreeZ;
} M3DModel;

extern void M3DModel_InitStock(void);
extern M3DModel *M3DModel_New(M3DRenderer *_rr, char *_name);
extern void M3DModel_Load(M3DModel *_this, unsigned char const *_data, long _data_length, M3DSplitString *_textures);
//extern void M3DModel_Load(M3DModel *_this, unsigned char *_data, long _data_length, char *_anim_info, int _anim_info_length);
extern void M3DModel_LoadFromFile(M3DModel *_this, char *_filename, M3DSplitString *_textures);
extern void M3DModel_InitAnimation(M3DModel *_this, char *_anim_info);
extern void M3DModel_InitAnimationEven(M3DModel *_this, char *_anim_info);
extern void M3DModel_AddAnimationByFrame(M3DModel *_this, char *_name, int _iStartFrame, int _iEndFrame, float _time_factor);
extern void M3DModel_SetAnimation(M3DModel *_this, int _iAnimation);
extern void M3DModel_SetDefaultAnimation(M3DModel *_this, int _iAnimation, float _time_factor);
extern int M3DModel_IsDefaultAnimation(M3DModel *_this);
extern void M3DModel_SetAnimationByName(M3DModel *_this, char *_name);

extern void M3DModel_SetActiveCamera(M3DModel *_this);
extern void M3DModel_SetActiveLight(M3DModel *_this);
extern void M3DModel_BindTexture(M3DModel *_this, int _i32NodeIndex);
extern void M3DModel_SetPosition(M3DModel *_this, float _x, float _y, float _z);
extern void M3DModel_SetNodeBeside(M3DModel *_this, char *_name, M3DModel *_beside, char *_beside_name, int _range);
extern void M3DModel_SetNodePosition(M3DModel *_this, char *_name, CVector3f *_position);
extern void M3DModel_GetNodePosition(M3DModel *_this, char *_name, CVector3f *_position);
extern void M3DModel_SetNodeScale(M3DModel *_this, char *_name, CVector3f *_scale);
extern void M3DModel_SetNodeZRotation(M3DModel *_this, char *_name, float _degree);
extern void M3DModel_SetNodeYRotation(M3DModel *_this, char *_name, float _degree);
extern void M3DModel_SetNodeXRotation(M3DModel *_this, char *_name, float _degree);
extern void M3DModel_FaceToCameraByXZ(M3DModel *_this, char *_node_name);
extern void M3DModel_FaceToCamera(M3DModel *_this, char *_node_name);

extern void M3DModel_Update(M3DModel *_this, float _fFrameTime);
extern void M3DModel_SetPassID(M3DModel *_this, char *_node_name, int _iPassId);
extern void M3DModel_EnableNode(M3DModel *_this, char *_node_name, int _bEnable);
extern void M3DModel_EnableNodeByIndex(M3DModel *_this, int _index, int _bEnable);
extern void M3DModel_EnableAllNode(M3DModel *_this, int _bEnable);

extern void M3DModel_SetMaterialOpacity(M3DModel *_this, float _fOpacity);
extern void M3DModel_Render(M3DModel *_this);
extern void M3DModel_RenderWithShadow(M3DModel *_this);
extern int  M3DModel_Pick(M3DModel *_this, int *_Picked, int _x, int _y);
extern char *M3DModel_PickNode(M3DModel *_this, int _x, int _y);
extern char *M3DModel_PickLastNode(M3DModel *_this, int _x, int _y);
extern char *M3DModel_PickNodeByNamePrefix(M3DModel *_this, int _x, int _y, char *_node_name_prefix);
extern int  M3DModel_PickNodeIndex(M3DModel *_this, int _x, int _y);

extern M3DAnimation *M3DModel_GetCurrentAnimation(M3DModel *_this);
extern void M3DModel_AnimateStart(M3DModel *_this);
extern void M3DModel_AnimateStop(M3DModel *_this);
extern void M3DModel_AnimateOnce(M3DModel *_this, float _ElapsedTime);
extern void M3DModel_SetTime(M3DModel *_this, float _Time);
extern float M3DModel_GetTimeFrame(M3DModel *_this);
extern float M3DModel_GetCurrentFrame(M3DModel *_this);
extern void M3DModel_AnimateLoop(M3DModel *_this, float _ElapsedTime, int _bRewind);
extern void M3DModel_AnimateCurrent(M3DModel *_this, float _ElapsedTime);
extern void M3DModel_AnimateCurrentLoop(M3DModel *_this, float _ElapsedTime, int _bRewind);
extern void M3DModel_SetAnimationStart(M3DModel *_this, int _iAnimation);
extern void M3DModel_AnimateCurrentOnce(M3DModel *_this, float _ElapsedTime);
extern void M3DModel_AnimateCurrentOnceAndPause(M3DModel *_this, float _ElapsedTime);
extern void M3DModel_SetAnimationPercent(M3DModel *_this, int _iAnimation, float _percent);


extern M3DModel *M3DModel_NewFromModel(M3DModel *_src, int _id, char *_anim_info, int _anim_info_length);
extern M3DModel *M3DModel_NewFromWorld(M3DRenderer *_rr, int _id, char *_anim_info, int _anim_info_length);
extern void M3DModel_Split(M3DModel *_this, M3DModel *_to, int _iNodeCount);
extern void M3DModel_ChangeSingleTexture(M3DModel *_this, char *_new_tex_name);
extern void M3DModel_ChangeTexture(M3DModel *_this, char *_old_tex_name, char *_new_tex_name);
extern void M3DModel_Release(M3DModel *_this);

extern void M3DModel_SetTimeFactor(M3DModel *_this, float _value);

extern void M3DModel_AnimateNormal(M3DModel *_this, float _GameTime);
extern void M3DModel_AnimateCurrentNormal(M3DModel *_this, float _GameTime);
extern void M3DModel_AnimateLoop(M3DModel *_this, float _ElapsedTime, int _bRewind);
extern void M3DModel_AnimateCurrent(M3DModel *_this, float _ElapsedTime);
extern void M3DModel_RotateZ(M3DModel *_this, float _degree);
extern void M3DModel_IncreaseZ(M3DModel *_this, float _degree);
extern void M3DModel_Rotate(M3DModel *_this);
extern void M3DModel_Del(M3DModel *_this);


typedef struct _M3DNode
{
	M3DModel	*m_Model;
	char		m_Name[M3D_DEFAULT_NAME_LENGTH];
	float		m_Time;
	int			m_Stop;
	int			m_iCurrentAnimation;
	int			m_ParentNodeIndex;
	int			m_ChildNodeIndex[10];
	int			m_iChildNode;
	int			m_IsBone;
} M3DNode;

extern M3DNode *M3DNode_New(M3DModel *_model, char *_node_name);
extern M3DNode *M3DNode_NewBone(M3DModel *_model, char *_node_name);
extern M3DNode *M3DNode_NewParent(M3DModel *_model, char *_node_name);
extern int  M3DNode_IsChild(M3DNode *_this, char *_child_node_name);
extern void M3DNode_Del(M3DNode *_this);
extern void M3DNode_Init(M3DNode *_this, M3DModel *_model, char *_node_name);
extern void M3DNode_InitParent(M3DNode *_this, M3DModel *_model, char *_parent_node_name);
extern void M3DNode_ResetTime(M3DNode *_this);
extern void M3DNode_SetTime(M3DNode *_this, float _Time);
extern void M3DNode_AnimateLoop(M3DNode *_this, float _ElapsedTime);
extern void M3DNode_AnimateStart(M3DNode *_this, float _Time);
extern void M3DNode_AnimateOnce(M3DNode *_this, float _ElapsedTime);
extern void M3DNode_AnimateChildsOnce(M3DNode *_this, float _ElapsedTime);
extern void M3DNode_SetAnimationStart(M3DNode *_this, int _iAnimation);
extern void M3DNode_AnimateCurrentOnce(M3DNode *_this, float _ElapsedTime);
extern void M3DNode_AnimateChildCurrentOnce(M3DNode *_this, float _ElapsedTime);

//Shadow and Reflection
extern void M3DModel_SetShaderProgram(M3DModel *_this, int _iModelShader, int _iSkinningShader);
extern void M3DModel_SetShaderProgramByNodeName(M3DModel *_this, char *pNodeName, int _iShader);
extern void M3DModel_SetShadow(M3DModel *_this);
extern void M3DModel_InitReflector(M3DModel *_this, char *_node_name, float reflectorOpacity);
extern void M3DModel_SetReflection(M3DModel *_this);

#ifdef __cplusplus
}
#endif

#endif

