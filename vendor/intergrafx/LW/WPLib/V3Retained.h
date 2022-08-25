//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : IGV3Retained
// File        : V3Retained.h
// Description : V3 Renderer
// Author      : Ray
// Create      : 2010-09-01
// Update      : 2011-04-08
//==============================================================================

#ifndef __WP_LIB_H__
#define __WP_LIB_H__

#include "GameDef.h"
#include "V3DataDef.h"
#include "IGScene.h"
#include "CUtils.h"
#include "V3Renderer.h"
#include "CNodeStatus.h"

#define V3RETAINED_TEXTURE_BUFFER	16
#define INTERNAL_ENGINE_BUFFER_SIZE 6*1024*1024
#define INTERNAL_ENGINE_BUFFER_SIZE_4MB 4*1024*1024
#define INTERNAL_ENGINE_BUFFER_SIZE_6MB 6*1024*1024
//#define USE_INTERNAL_ENGINE_BUFFER	1

#define V3RETAINED_LOADING_BEGIN				0
#define V3RETAINED_LOADING_TEXTURE				1
#define V3RETAINED_LOADING_TEXTURE_COMPLETE		2
#define V3RETAINED_LOADING_IGF_COMPLETE			3
#define V3RETAINED_LOADING_BACKGROUND_COMPLETE	4
#define V3RETAINED_LOADING_INIT_VALUE			5
#define V3RETAINED_LOADING_COMPLETE				6


#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

extern void *g_lw_memPool;

struct _V3Retained
{
	//這個 PC 參數只有在 V3Retained_InitEngine 會用到
	IGV3Config PC;

	IGMemoryPool	*m_Mem;
	IGU8			*m_MemBuf;
	IGScene			*m_Scene;
	IGNode 			*m_SceneNode;
	IGRenderer		*m_Renderer;
	IGGroup			*m_Root;
	IGCamera		*m_Camera;
	IGGroup			*m_CameraControl;
	IGTexture		*m_BackgroundTexture;
	IGBackground	*m_Background[2];
	IGTexture		*m_Textures[V3RETAINED_TEXTURE_BUFFER];
	IGTexture		*m_TexturesSwitch[V3RETAINED_TEXTURE_BUFFER];
	IGObjCache		*m_TexturesCache;
	int				m_iLoadingStatus;

	const char		*m_pName_Animation;

	long			m_Time;
	int				m_AC_Step;
	int				m_AC_Play;
	int				m_AC_Repeat;
};

typedef struct _V3Retained V3Retained;

extern void V3Retained2D_BrushBuffer(void *_pFrameBuffer, int _width, int _height);
extern void V3Retained2D_BrushBackground(void *_pFrameBuffer, int _width, int _height);
extern void V3Retained2D_BrushColor(void *_pFrameBuffer, int _width, int _height, int _r, int _g, int _b);

extern V3Retained *V3Retained_GetInstance(void);
extern IGMemoryPool *V3Retained_GetMem(void);
extern IGRenderer *V3Retained_GetRenderer(void);
void *V3Retained_Alloc(unsigned long _iSize);
void V3Retained_Free(void *_mem);

extern int V3Retained_InitEngine(void *_config);
extern void V3Retained_Bind(IGU8 *_pFrameBuffer);
extern void V3Retained_End(int appId);

extern void V3Retained_LoadWorldBegin(V3World *_world);
extern void V3Retained_LoadWorldContinue(V3World *_world);
extern void V3Retained_LoadWorldEnd(void);
extern int  V3Retained_IsLoadingComplete(void);
extern int  V3Retained_IsLoadingInitValue(void);

extern void V3Retained_LoadBackgroundTexture(const unsigned char *_buf);
extern void V3Retained_ActiveBackgroundTexture(void);

extern IGScene *V3Retained_LoadWorld(V3World *_world);
extern void V3Retained_ChangeBackground(int _iActive);
extern void V3Retained_ChangeTexture(int iActivce);
extern void V3Retained_RotateCamera(float _iRotateH, float _iRotateV);
extern igbool V3Retained_Update(IGU32 _uDelta);
extern igbool V3Retained_UpdateScene(const char *_AniName, IGU32 _uTime);
extern igbool V3Retained_UpdateNode(IGNode *_pNode, const char *_AniName, IGU32 _uTime);
extern igbool V3Retained_Render(void);
extern long V3Retained_GetTime(void);

extern IGNode  *V3Retained_GetNode(const char *_name);
extern IGGroup *V3Retained_GetGroup(const char *_name);
extern IGMesh  *V3Retained_GetMesh(const char *_name);

extern CArray *V3Retained_GenerateAniInfo(void);
extern void V3Retained_GetPathPosition_i(IGNode *_pNode, const char *_AniName, IGU32 _uTime, igreal *_Pos);
extern void V3Retained_GetPathPosition(IGNode *_pNode, const char *_AniName, IGU32 _uTime, float *_Pos);
extern void V3Retained_SetPath(IGNode *_pNode, const char *_AniName, IGU32 _uTime);

extern void V3Retained_AC_SetStep(long _iStep);
extern long V3Retained_AC_GetStep(void);
extern void V3Retained_AC_Play(void);
extern void V3Retained_AC_Stop(void);
extern void V3Retained_AC_Reset(void);
extern int  V3Retained_AC_GetDurationByIndex(int _index);
extern int  V3Retained_AC_GetDuration(void);
extern int  V3Retained_AC_GetCount(void);

extern IGTexture *V3Retained_LoadImage2D(const unsigned char * _bmp_array, const char *_bmp_name, int _keycolor);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif