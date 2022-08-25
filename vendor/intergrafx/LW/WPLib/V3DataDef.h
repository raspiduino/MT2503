//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : IGV3Retained
// File        : V3DataDef.h
// Description : V3 ¸ê®Æµ²ºc
// Author      : Ray
// Create      : 2010-09-01
// Update      : 2011-02-15
//==============================================================================

#include "IGExtDef.h"
#include "IGComDef.h" 
#include "IGMemoryPool.h"
#include "IGTexture.h"

#include "CUtils.h"

#ifndef __V3_DATA_DEF__
#define __V3_DATA_DEF__

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

struct _V3Texture
{
	unsigned char const *m_pBuf;
	const char *m_pName;
	int m_Mask[3];
	int m_Keycolor;
	IGTexture *m_Texture;
};

typedef struct _V3Texture V3Texture;

struct _V3World
{
	unsigned char const *m_pBuf;
	CArray	   *m_pTextures;
	CArray	   *m_pTexturesSwitch;
	CArray     *m_pBackground;
	const char *m_pName_SceneRoot;
	const char *m_pName_Camera;
	const char *m_pName_Animation;
};

typedef struct _V3World V3World;

extern V3Texture *V3Texture_New(unsigned char const *_buf, const char *_name, int _r, int _g, int _b, int _keycolor);
extern void V3Texture_Del(V3Texture *_this);

extern CArray *V3Textures_New(V3Texture *_item);
extern void V3Textures_Del(CArray *_this);

extern V3World *V3World_New(unsigned char const *_buf, CArray *_textures, V3Texture *_background, const char *_name_scene, const char *_name_camera, const char *_name_animation);
extern V3World *V3World_New2(unsigned char const *_buf, CArray *_textures, CArray *_textures_switch, V3Texture *_background, const char *_name_scene, const char *_name_camera, const char *_name_animation);
extern void V3World_AddBackground(V3World *_this, V3Texture *_background);
extern void V3World_Del(V3World *_this);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__V3_DATA_DEF
