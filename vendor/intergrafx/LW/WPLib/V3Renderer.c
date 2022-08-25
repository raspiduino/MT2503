//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : IGV3Retained
// File        : V3Renderer.c
// Description : V3 Renderer
// Author      : Ray
// Create      : 2010-12-17
// Update      : 2011-02-15
//==============================================================================

#include "V3DataDef.h"
#include "V3Renderer.h"

#include "IGComDef.h" 
#include "IGMemoryPool.h"
#include "IGMathUtil.h"

#include "IGBackground.h"
#include "IGScene.h"
#include "IGRenderer.h"
#include "IGNode.h"
#include "IGGroup.h"
#include "IGCamera.h"
#include "IGTexture.h"
#include "IGObjCache.h"

#include "CNodeStatus.h"
#include "CMemory.h"

#define mMem		RendererInstance.m_Mem

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

V3Renderer	RendererInstance;
IGMemoryPool	m_Mem;

V3Renderer *V3Renderer_GetInstance(void)
{
	RendererInstance.m_Mem = &m_Mem;
	return &RendererInstance;
}

V3Renderer *V3Renderer_ResetInstance(void)
{
	IGErr err;

	IGMemoryPool_i_memset(&RendererInstance, sizeof(V3Renderer), 0, &err);
	RendererInstance.m_Mem = &m_Mem;

	return &RendererInstance;
}

IGMemoryPool *V3Renderer_GetMem(void)
{
	return &m_Mem;
}

void V3Renderer_LoadTextures(CArray *_textures)
{
	IGErr err;
	IGTexture *pTexture = NULL;
	V3Texture *tex = NULL;
	int cn;

	for (cn = 0; cn < _textures->m_Count; cn = cn + 1)
	{
		tex = (V3Texture *) CArray_Get(_textures, cn);

		pTexture = IGTexture_newFromByteArray(mMem, tex->m_pBuf, tex->m_pName, (igcolor) tex->m_Mask[0], (igcolor) tex->m_Mask[1], (igcolor) tex->m_Mask[2],	&err);

		if (tex->m_Keycolor > 0)
		{
			IGTexture_setKeyColorEnabled(mMem, pTexture, IGBOOL_TRUE, &err);
			IGTexture_setKeyColor(mMem, pTexture, IGTexture_getDeviceColor(mMem, pTexture, tex->m_Keycolor, &err), &err);  
		}
		tex->m_Texture = pTexture;
	}
}

/*
IGScene *V3Renderer_LoadScene(char *_buf, CArray *_textures)
{
	IGErr err;
	IGObjCache *cache;
	IGScene     *pScene;
	int cn;
	V3Texture *tex = NULL;

	cache = IGObjCache_new(mMem, _textures->m_Count, &err);

	for (cn = 0; cn < _textures->m_Count; cn = cn + 1)
	{
		tex = (V3Texture *) CArray_Get(_textures, cn);
		if (tex->m_Texture != NULL)
			IGObjCache_add(mMem, cache, tex->m_Texture, &err);
	}

	pScene = IGScene_fromByteArray(mMem, _buf,  cache, &err);
	IGObjCache_destroy(mMem, cache, &err);

	return pScene;
}
*/
/*
IGScene *V3Renderer_LoadWorld(V3World *_world)
{
	IGErr err;
	IGObjCache *cache;
	IGTexture   *pTexture = NULL;
	IGScene     *pScene;
	int cn;
	V3Texture *tex = NULL;
	IGGroup *pRoot = NULL;
	IGCamera *pCamera = NULL;
	igreal ratio;

	// Create a new object cache.
	cache = IGObjCache_new(mMem, _world->m_pTextures->m_Count, &err);

	for (cn = 0; cn < _world->m_pTextures->m_Count; cn = cn + 1)
	{
		tex = (V3Texture *) CArray_Get(_world->m_pTextures, cn);

		pTexture = IGTexture_newFromByteArray(mMem, tex->m_pBuf, tex->m_pName, (igcolor) tex->m_Mask[0], (igcolor) tex->m_Mask[1], (igcolor) tex->m_Mask[2],	&err);
		if (cn < V3RETAINED_TEXTURE_BUFFER)
		{
			RendererInstance.m_Textures[cn] = pTexture;
		}

		if (tex->m_Keycolor > 0)
		{
			IGTexture_setKeyColorEnabled(mMem, pTexture, IGBOOL_TRUE, &err);
			IGTexture_setKeyColor(mMem, pTexture, IGTexture_getDeviceColor(mMem, pTexture, tex->m_Keycolor, &err), &err);  
		}
		IGObjCache_add(mMem, cache, pTexture, &err);
	}

	if (_world->m_pTexturesSwitch != NULL)
	{
		for (cn = 0; cn < _world->m_pTexturesSwitch->m_Count; cn = cn + 1)
		{
			tex = (V3Texture *) CArray_Get(_world->m_pTexturesSwitch, cn);

			pTexture = IGTexture_newFromByteArray(mMem, tex->m_pBuf, tex->m_pName, (igcolor) tex->m_Mask[0], (igcolor) tex->m_Mask[1], (igcolor) tex->m_Mask[2],	&err);
			if (cn < V3RETAINED_TEXTURE_BUFFER)
			{
				RendererInstance.m_TexturesSwitch[cn] = pTexture;
			}

			if (tex->m_Keycolor > 0)
			{
				IGTexture_setKeyColorEnabled(mMem, pTexture, IGBOOL_TRUE, &err);
				IGTexture_setKeyColor(mMem, pTexture, IGTexture_getDeviceColor(mMem, pTexture, tex->m_Keycolor, &err), &err);  
			}
		}
	}

	pScene = IGScene_fromByteArray(mMem, _world->m_pBuf,  cache, &err);
	RendererInstance.m_Scene = pScene;
	RendererInstance.m_SceneNode = (IGNode *) V3Retained_GetGroup(_world->m_pName_SceneRoot);
	IGObjCache_destroy(mMem, cache, &err);

	for (cn = 0; cn < _world->m_pBackground->m_Count && cn < 2; cn = cn + 1)
	{
		tex = (V3Texture *) CArray_Get(_world->m_pBackground, cn);
		if (tex == NULL)
			continue;

		pTexture = IGTexture_newFromByteArray(mMem, tex->m_pBuf, tex->m_pName, (igcolor) tex->m_Mask[0], (igcolor) tex->m_Mask[1], (igcolor) tex->m_Mask[2],	&err);
		if (tex->m_Keycolor > 0)
		{
			IGTexture_setKeyColorEnabled(mMem, pTexture, IGBOOL_TRUE, &err);
			IGTexture_setKeyColor(mMem, pTexture, IGTexture_getDeviceColor(mMem, pTexture, tex->m_Keycolor, &err), &err);  
		}
		RendererInstance.m_Background[cn] = IGBackground_newFromTexture(mMem, pTexture, &err);
	}
	IGScene_setActiveBackground(mMem, pScene, RendererInstance.m_Background[0], &err);

	// Set the active camera.
	RendererInstance.m_Camera = IGScene_getActiveCamera(mMem, pScene, &err);
	RendererInstance.m_CameraControl = V3Retained_GetGroup(_world->m_pName_Camera);
	//IGScene_setActiveCamera(mMem, pScene, _world->m_pName_Camera, &err);
	//pCamera = IGScene_getActiveCamera(mMem, pScene, &err);
	ratio = IGCamera_getAspectRatio(mMem, RendererInstance.m_Camera, &err);
	ratio = IG_ONE * RendererInstance.PC.m_uScrWidth / RendererInstance.PC.m_uScrHeight;
	IGCamera_setAspectRatio(mMem, RendererInstance.m_Camera, ratio, &err);
  
	// Get the scene's root node.
	pRoot = (IGGroup *)IGScene_get(mMem, pScene, _world->m_pName_SceneRoot, IGNODE_GROUP, &err);
	RendererInstance.m_Root = pRoot;
    
	// Start the animation.
	RendererInstance.m_pName_Animation = _world->m_pName_Animation;
	IGNode_startAction(mMem, (IGNode *) pRoot, _world->m_pName_Animation, 0L, IGBOOL_TRUE, &err);  // you can change to ANIMATE0
	V3Retained_AC_Play();
	V3Retained_AC_SetStep(40L);

	RendererInstance.m_Scene = pScene;

	return pScene;
}
*/

#ifdef __cplusplus
}
#endif // __cplusplus
