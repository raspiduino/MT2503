//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : IGV3Retained
// File        : V3TextureManager.c
// Description : V3 Texture Manager
// Author      : Ray
// Create      : 2011-01-26
// Update      : 2011-02-15
//==============================================================================

#include "V3Retained.h"
#include "V3TextureManager.h"

#include "IGMemoryPool.h"
#include "IGTexture.h"
#include "IGSprite.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

struct _V3TextureCollection V3TextureCollection;

void V3TextureCollection_Init(void)
{
	V3TextureCollection.m_Textures = CNamedObjArray_New(NULL, NULL);
}

void V3TextureCollection_Add(const char *_name, unsigned char *_buf, int _keycolor)
{
	IGTexture *tex = V3Retained_LoadImage2D(_buf, _name, _keycolor);
	CNamedObjArray_Add(V3TextureCollection.m_Textures, _name, tex);
}

void V3TextureCollection_Release(void)
{
	int cn;
	IGErr err;
	IGTexture *tex = NULL;

	for (cn = 0; cn < V3TextureCollection.m_Textures->m_Count; cn = cn + 1)
	{
		tex = (IGTexture *) CNamedObjArray_Get(V3TextureCollection.m_Textures, cn);
		IGTexture_destroy(V3Retained_GetMem(), tex, &err);
	}
	CNamedObjArray_Del(V3TextureCollection.m_Textures);
}

IGTexture *V3TextureCollection_Get(const char *_name)
{
	IGTexture *tex = NULL;
	tex = (IGTexture *) CNamedObjArray_GetFirstByName(V3TextureCollection.m_Textures, _name);

	return tex;
}

#ifdef __cplusplus
}
#endif // __cplusplus
