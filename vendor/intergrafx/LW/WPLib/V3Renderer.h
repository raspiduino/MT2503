//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : IGV3Retained
// File        : V3Renderer.h
// Description : V3 Renderer
// Author      : Ray
// Create      : 2010-12-17
// Update      : 2011-02-15
//==============================================================================

#include "GameDef.h"
#include "IGScene.h"
#include "CUtils.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

struct _V3Renderer
{
	IGMemoryPool	*m_Mem;
	IGU8			*m_MemBuf;
	IGRenderer		*m_Renderer;
};

typedef struct _V3Renderer V3Renderer;

extern V3Renderer *V3Renderer_GetInstance(void);
extern V3Renderer *V3Renderer_ResetInstance(void);
extern IGMemoryPool *V3Renderer_GetMem(void);
extern void V3Renderer_LoadTextures(CArray *_textures);
extern IGScene *V3Renderer_LoadScene(char *_buf, CArray *_textures);

#ifdef __cplusplus
}
#endif // __cplusplus
