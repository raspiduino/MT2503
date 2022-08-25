//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : IGV3Retained
// File        : V3Retained.c
// Description : V3 Renderer
// Author      : Ray
// Create      : 2010-09-01
// Update      : 2011-04-09
//==============================================================================

#include "V3DataDef.h"
#include "V3Retained.h"
#include "V3TextureManager.h"

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
#include "IGSprite.h"

#include "CNodeStatus.h"
#include "CMemory.h"

#if (!defined(USE_INTERNAL_ENGINE_BUFFER))
#include "mmi_frm_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "med_utility.h"
#endif

#define mMem		RetainedInstance.m_Mem

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

V3Retained	RetainedInstance;
IGV3Config	*v3config = NULL;

void *g_lw_memPool = NULL;                /*memory for IG Wallpaper*/

#if (defined(USE_INTERNAL_ENGINE_BUFFER))
//static unsigned char s_engineMemBuf[INTERNAL_ENGINE_BUFFER_SIZE];
unsigned char s_engineMemBuf[INTERNAL_ENGINE_BUFFER_SIZE];
#else
void ig_lw_memory_allocate(int iWidth, int iHeight)
{
    if (!g_lw_memPool)
    {
#if defined(__COSMOS_MMI__)
        //g_lw_memPool = mmi_frm_asm_alloc_anonymous(INTERNAL_ENGINE_BUFFER_SIZE);
		if(iWidth == 480 && iHeight == 800)//WVGA check
		{
			g_lw_memPool = mmi_frm_asm_alloc_r(APP_VENUS_WALLPAPER_INTERGRAFX, INTERNAL_ENGINE_BUFFER_SIZE_6MB);
		}
		else
		{
			g_lw_memPool = mmi_frm_asm_alloc_r(APP_VENUS_WALLPAPER_INTERGRAFX, INTERNAL_ENGINE_BUFFER_SIZE_4MB);
		}
#else
        //g_lw_memPool = med_alloc_asm_mem(0, INTERNAL_ENGINE_BUFFER_SIZE); -- 本來就槓掉的
        //g_lw_memPool = med_alloc_asm_mem_cacheable(0, INTERNAL_ENGINE_BUFFER_SIZE);
		if(iWidth == 480 && iHeight == 800)//WVGA check
		{
			g_lw_memPool = med_alloc_asm_mem_cacheable(0, INTERNAL_ENGINE_BUFFER_SIZE_6MB);
		}
		else
		{
			g_lw_memPool = med_alloc_asm_mem_cacheable(0, INTERNAL_ENGINE_BUFFER_SIZE_4MB);
		}
#endif
        //assert(g_lw_memPool != NULL);
    }
}
 
 
void ig_lw_memory_free(int appId)
{
    if (g_lw_memPool)
    {
#if defined(__COSMOS_MMI__)
        if (appId)
        {
            mmi_frm_asm_free_r(appId, g_lw_memPool);
        }
		else
		{
            mmi_frm_asm_free_r(APP_VENUS_WALLPAPER_INTERGRAFX, g_lw_memPool);
		}
#else
        med_free_asm_mem(0, &g_lw_memPool);
#endif
        g_lw_memPool = NULL;
    }
}
#endif

void V3Retained2D_BrushBuffer(void *_pFrameBuffer, int _width, int _height)
{
	V3Retained2D_BrushBackground(_pFrameBuffer, _width, _height);
}

void V3Retained2D_BrushBackground(void *_pFrameBuffer, int _width, int _height)
{
	igcolor *pFrameBuffer = (igcolor *) _pFrameBuffer;
	igcolor *pSrc = NULL;
	int cn, cn2;

	//RAY::2011-04-09 有時候 RetainedInstance.m_Background[0] == NULL, 所以 pSrc == NULL, 此時要用 RetainedInstance.m_BackgroundTexture
	if (RetainedInstance.m_Background[0] != NULL && RetainedInstance.m_Background[0]->m_bgndImage != NULL && RetainedInstance.m_Background[0]->m_bgndImage->m_texels != NULL)
		pSrc = RetainedInstance.m_Background[0]->m_bgndImage->m_texels;
	else
	{
		if (RetainedInstance.m_BackgroundTexture != NULL && RetainedInstance.m_BackgroundTexture->m_texels != NULL)
			pSrc = RetainedInstance.m_BackgroundTexture->m_texels;
	}

	if (pSrc == NULL)
		return;

	for (cn = 0; cn < _height; cn = cn + 1)
	{
		for (cn2 = 0; cn2 < _width; cn2 = cn2 + 1)
		{
			pFrameBuffer[cn*_width + cn2] = pSrc[(_height-cn-1)*_width + cn2];
		}
	}
}

V3Retained *V3Retained_GetInstance(void)
{
	RetainedInstance.m_Mem = V3Renderer_GetMem();
	return &RetainedInstance;
}

V3Retained *V3Retained_ResetInstance(void)
{
	IGErr err;

	IGMemoryPool_i_memset(&RetainedInstance, sizeof(V3Retained), 0, &err);
	IGMemoryPool_i_memcpy(&RetainedInstance.PC, v3config, sizeof(IGV3Config), &err);
	RetainedInstance.m_MemBuf = RetainedInstance.PC.m_pMemBuffer;
	RetainedInstance.m_Mem = V3Renderer_GetMem();

	return &RetainedInstance;
}

IGMemoryPool *V3Retained_GetMem(void)
{
	V3Retained *Inst = V3Retained_GetInstance();
	return Inst->m_Mem;
}

IGRenderer *V3Retained_GetRenderer(void)
{
	V3Retained *Inst = V3Retained_GetInstance();
	return Inst->m_Renderer;
}

void *V3Retained_Alloc(unsigned long _iSize)
{
	IGErr err;
	void *mem = NULL;

	mem = IGMemoryPool_allocate (mMem, _iSize, &err);
	IGMemoryPool_i_memset(mem, _iSize, 0, &err);

	return mem;
}

void V3Retained_Free(void *_mem)
{
	IGErr err;

	IGMemoryPool_free(mMem, _mem, &err);
}

int V3Retained_InitEngine(void *_config)
{
	IGErr err;
	v3config = (IGV3Config *) _config;

	// One-time initialization of the Engine's internal memory pool.

	if (v3config->m_pMemBuffer != NULL)
	{
		IGMemoryPool_initialize(V3Renderer_GetMem(), v3config->m_pMemBuffer, v3config->m_MemSize, &err);
	}
	else
	{
#if (defined(USE_INTERNAL_ENGINE_BUFFER))
		IGMemoryPool_initialize(V3Renderer_GetMem(), s_engineMemBuf, INTERNAL_ENGINE_BUFFER_SIZE, &err);
#else
		ig_lw_memory_allocate(v3config->m_uScrWidth, v3config->m_uScrHeight);
		if (g_lw_memPool != NULL)
		{
			//IGMemoryPool_initialize(V3Renderer_GetMem(), g_lw_memPool, INTERNAL_ENGINE_BUFFER_SIZE, &err);
			if(v3config->m_uScrWidth == 480 && v3config->m_uScrHeight == 800)//WVGA check
			{
				IGMemoryPool_initialize(V3Renderer_GetMem(), g_lw_memPool, INTERNAL_ENGINE_BUFFER_SIZE_6MB, &err);
			}
			else
			{
				IGMemoryPool_initialize(V3Renderer_GetMem(), g_lw_memPool, INTERNAL_ENGINE_BUFFER_SIZE_4MB, &err);
			}
		}
		else
		{
			return 0;
		}
#endif
	}
	V3Retained_ResetInstance();

	// Allocate a new renderer.
	RetainedInstance.m_Renderer = IGRenderer_new(mMem, &err);

	// Designate the framebuffer as the destination the renderer draws to. 
	if (RetainedInstance.PC.m_pFrameBuffer != NULL)
	{
		IGRenderer_setTarget(mMem, RetainedInstance.m_Renderer, (igcolor *) RetainedInstance.PC.m_pFrameBuffer, RetainedInstance.PC.m_uScrWidth, RetainedInstance.PC.m_uScrHeight, (igbool)RetainedInstance.PC.m_IsTopDown, IGBOOL_TRUE, IGBOOL_FALSE, RetainedInstance.PC.m_MaskR, RetainedInstance.PC.m_MaskG, RetainedInstance.PC.m_MaskB, &err);
	}
	V3TextureCollection_Init();
	return 0;
}

void V3Retained_Bind(IGU8 *_pFrameBuffer)
{
	IGErr err;

	if (_pFrameBuffer == NULL)
		return;

	if (RetainedInstance.PC.m_pFrameBuffer == NULL)
	{
		RetainedInstance.PC.m_pFrameBuffer = _pFrameBuffer;
		IGRenderer_setTarget(mMem, RetainedInstance.m_Renderer, (igcolor *) RetainedInstance.PC.m_pFrameBuffer, RetainedInstance.PC.m_uScrWidth, RetainedInstance.PC.m_uScrHeight, (igbool)RetainedInstance.PC.m_IsTopDown, IGBOOL_TRUE, IGBOOL_FALSE, RetainedInstance.PC.m_MaskR, RetainedInstance.PC.m_MaskG, RetainedInstance.PC.m_MaskB, &err);
	}
	else
	{
		RetainedInstance.PC.m_pFrameBuffer = _pFrameBuffer;
		IGRenderer_changeTarget(mMem, RetainedInstance.m_Renderer, (igcolor *) RetainedInstance.PC.m_pFrameBuffer, &err);
	}
}

void V3Retained_End(int appId)
{
	IGErr err;

	IGScene_ResetGameObjects(mMem, &err);
	V3TextureCollection_Release();

	// Free all the 3D data that was a part of the scene (all the data referenced by the
	// IGScene object created in the call to IGScene_fromByteArray).
	IGScene_destroyAll(mMem, RetainedInstance.m_Scene,  &err);

	// Release renderer memory.
	IGRenderer_destroy(mMem, RetainedInstance.m_Renderer, &err);

	// Release the memory the application allocated for the memory pool.
	IGMemoryPool_finalize(mMem, &err);

#if (!defined(USE_INTERNAL_ENGINE_BUFFER))
	if (g_lw_memPool != NULL)
		ig_lw_memory_free(appId);
#endif
}

void V3Retained_LoadWorldBegin(V3World *_world)
{
	IGErr err;
	RetainedInstance.m_TexturesCache = IGObjCache_new(mMem, _world->m_pTextures->m_Count, &err);
	RetainedInstance.m_iLoadingStatus = V3RETAINED_LOADING_BEGIN;
}

void V3Retained_LoadOneTexture(V3World *_world)
{
	IGErr		err;
	IGTexture	*pTexture = NULL;
	V3Texture	*tex = NULL;
	int			cn;

	for (cn = 0; cn < _world->m_pTextures->m_Count; cn = cn + 1)
	{
		tex = (V3Texture *) CArray_Get(_world->m_pTextures, cn);
		if (tex->m_Texture != NULL)
			continue;

		pTexture = IGTexture_newFromByteArray(mMem, tex->m_pBuf, tex->m_pName, RetainedInstance.PC.m_MaskR, RetainedInstance.PC.m_MaskG, RetainedInstance.PC.m_MaskB, &err);
		if (cn < V3RETAINED_TEXTURE_BUFFER)
		{
			RetainedInstance.m_Textures[cn] = pTexture;
		}

		if (tex->m_Keycolor > 0)
		{
			IGTexture_setKeyColorEnabled(mMem, pTexture, IGBOOL_TRUE, &err);
			IGTexture_setKeyColor(mMem, pTexture, IGTexture_getDeviceColor(mMem, pTexture, tex->m_Keycolor, &err), &err);  
		}
		tex->m_Texture = pTexture;
		IGObjCache_add(mMem, RetainedInstance.m_TexturesCache, pTexture, &err);
		RetainedInstance.m_iLoadingStatus = V3RETAINED_LOADING_TEXTURE;
		break;
	}

	if (cn == _world->m_pTextures->m_Count && RetainedInstance.m_iLoadingStatus == V3RETAINED_LOADING_TEXTURE)
	{
		RetainedInstance.m_iLoadingStatus = V3RETAINED_LOADING_TEXTURE_COMPLETE;
	}
}

void V3Retained_LoadWorldIGF(V3World *_world)
{
	IGErr err;
	IGScene     *pScene;

	pScene = IGScene_fromByteArray(mMem, _world->m_pBuf, RetainedInstance.m_TexturesCache, &err);
	RetainedInstance.m_Scene = pScene;
	RetainedInstance.m_SceneNode = (IGNode *) V3Retained_GetGroup(_world->m_pName_SceneRoot);
	RetainedInstance.m_iLoadingStatus = V3RETAINED_LOADING_IGF_COMPLETE;
}

void V3Retained_LoadWorldBackground(V3World *_world)
{
	IGErr err;
	IGTexture	*pTexture = NULL;
	V3Texture	*tex = NULL;
	int			cn;

	for (cn = 0; cn < _world->m_pBackground->m_Count && cn < 2; cn = cn + 1)
	{
		tex = (V3Texture *) CArray_Get(_world->m_pBackground, cn);
		if (tex == NULL)
			continue;

		pTexture = IGTexture_newFromByteArray(mMem, tex->m_pBuf, tex->m_pName, RetainedInstance.PC.m_MaskR, RetainedInstance.PC.m_MaskG, RetainedInstance.PC.m_MaskB, &err);
		if (tex->m_Keycolor > 0)
		{
			IGTexture_setKeyColorEnabled(mMem, pTexture, IGBOOL_TRUE, &err);
			IGTexture_setKeyColor(mMem, pTexture, IGTexture_getDeviceColor(mMem, pTexture, tex->m_Keycolor, &err), &err);  
		}
		RetainedInstance.m_Background[cn] = IGBackground_newFromTexture(mMem, pTexture, &err);
	}
	IGScene_setActiveBackground(mMem, RetainedInstance.m_Scene, RetainedInstance.m_Background[0], &err);
	RetainedInstance.m_iLoadingStatus = V3RETAINED_LOADING_BACKGROUND_COMPLETE;
}

void V3Retained_LoadWorldInit(V3World *_world)
{
	IGErr err;
	igreal ratio;

	// Set the active camera.
	RetainedInstance.m_Camera = IGScene_getActiveCamera(mMem, RetainedInstance.m_Scene, &err);
	RetainedInstance.m_CameraControl = V3Retained_GetGroup(_world->m_pName_Camera);
	ratio = IG_ONE * RetainedInstance.PC.m_uScrWidth / RetainedInstance.PC.m_uScrHeight;
	IGCamera_setAspectRatio(mMem, RetainedInstance.m_Camera, ratio, &err);
  
	// Get the scene's root node.
	RetainedInstance.m_Root = (IGGroup *)IGScene_get(mMem, RetainedInstance.m_Scene, _world->m_pName_SceneRoot, IGNODE_GROUP, &err);

	RetainedInstance.m_pName_Animation = _world->m_pName_Animation;
	IGNode_startAction(mMem, (IGNode *) RetainedInstance.m_Root, _world->m_pName_Animation, 0L, IGBOOL_TRUE, &err);  // you can change to ANIMATE0
	V3Retained_AC_Play();
	V3Retained_AC_SetStep(40L);

	RetainedInstance.m_iLoadingStatus = V3RETAINED_LOADING_INIT_VALUE;
}

void V3Retained_LoadWorldEnd(void)
{
	IGErr err;

	IGObjCache_destroy(mMem, RetainedInstance.m_TexturesCache, &err);
	RetainedInstance.m_iLoadingStatus = V3RETAINED_LOADING_COMPLETE;
}

void V3Retained_LoadWorldContinue(V3World *_world)
{
	switch (RetainedInstance.m_iLoadingStatus)
	{
	case V3RETAINED_LOADING_BEGIN :
	case V3RETAINED_LOADING_TEXTURE :
		V3Retained_LoadOneTexture(_world);
		break;
	case V3RETAINED_LOADING_TEXTURE_COMPLETE :
		V3Retained_LoadWorldIGF(_world);
		break;
	case V3RETAINED_LOADING_IGF_COMPLETE :
		V3Retained_LoadWorldBackground(_world);
		break;
	case V3RETAINED_LOADING_BACKGROUND_COMPLETE :
		V3Retained_LoadWorldInit(_world);
		break;
	}
}

int V3Retained_IsLoadingComplete(void)
{
	if (RetainedInstance.m_iLoadingStatus == V3RETAINED_LOADING_COMPLETE)
		return 1;
	else
		return 0;
}

int V3Retained_IsLoadingInitValue(void)
{
	if (RetainedInstance.m_iLoadingStatus == V3RETAINED_LOADING_INIT_VALUE)
		return 1;
	else
		return 0;
}

void V3Retained_LoadBackgroundTexture(const unsigned char *_buf)
{
	IGErr err;

	RetainedInstance.m_BackgroundTexture = IGTexture_newFromByteArray(mMem, _buf, "back", RetainedInstance.PC.m_MaskR, RetainedInstance.PC.m_MaskG, RetainedInstance.PC.m_MaskB, &err);
}

void V3Retained_ActiveBackgroundTexture(void)
{
	IGErr err;

	if (RetainedInstance.m_BackgroundTexture != NULL && RetainedInstance.m_Background[0] == NULL)
	{
		RetainedInstance.m_Background[0] = IGBackground_newFromTexture(mMem, RetainedInstance.m_BackgroundTexture, &err);
		IGScene_setActiveBackground(mMem, RetainedInstance.m_Scene, RetainedInstance.m_Background[0], &err);
	}
}

//CY: 呼叫這個函數時就會切換到指定的10K堆疊
static void V3Retained_LoadWorld_Internal(V3World *_world, IGScene **ppScene)
{
	IGErr err;
	IGObjCache *cache;
	IGTexture   *pTexture = NULL;
	IGScene     *pScene;
	int cn;
	V3Texture *tex = NULL;
	IGGroup *pRoot = NULL;
	igreal ratio;

	// Create a new object cache.
	cache = IGObjCache_new(mMem, _world->m_pTextures->m_Count, &err);

	for (cn = 0; cn < _world->m_pTextures->m_Count; cn = cn + 1)
	{
		tex = (V3Texture *) CArray_Get(_world->m_pTextures, cn);

		pTexture = IGTexture_newFromByteArray(mMem, tex->m_pBuf, tex->m_pName, (igcolor) tex->m_Mask[0], (igcolor) tex->m_Mask[1], (igcolor) tex->m_Mask[2],	&err);
		if (cn < V3RETAINED_TEXTURE_BUFFER)
		{
			RetainedInstance.m_Textures[cn] = pTexture;
		}

		if (tex->m_Keycolor > 0)
		{
			IGTexture_setKeyColorEnabled(mMem, pTexture, IGBOOL_TRUE, &err);
			IGTexture_setKeyColor(mMem, pTexture, IGTexture_getDeviceColor(mMem, pTexture, tex->m_Keycolor, &err), &err);  
		}
		tex->m_Texture = pTexture;
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
				RetainedInstance.m_TexturesSwitch[cn] = pTexture;
			}

			if (tex->m_Keycolor > 0)
			{
				IGTexture_setKeyColorEnabled(mMem, pTexture, IGBOOL_TRUE, &err);
				IGTexture_setKeyColor(mMem, pTexture, IGTexture_getDeviceColor(mMem, pTexture, tex->m_Keycolor, &err), &err);  
			}
			tex->m_Texture = pTexture;
		}
	}

	pScene = IGScene_fromByteArray(mMem, _world->m_pBuf,  cache, &err);
	RetainedInstance.m_Scene = pScene;
	RetainedInstance.m_SceneNode = (IGNode *) V3Retained_GetGroup(_world->m_pName_SceneRoot);
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
		RetainedInstance.m_Background[cn] = IGBackground_newFromTexture(mMem, pTexture, &err);
	}
	IGScene_setActiveBackground(mMem, pScene, RetainedInstance.m_Background[0], &err);

	// Set the active camera.
	RetainedInstance.m_Camera = IGScene_getActiveCamera(mMem, pScene, &err);
	RetainedInstance.m_CameraControl = V3Retained_GetGroup(_world->m_pName_Camera);
	//IGScene_setActiveCamera(mMem, pScene, _world->m_pName_Camera, &err);
	//pCamera = IGScene_getActiveCamera(mMem, pScene, &err);
	ratio = IGCamera_getAspectRatio(mMem, RetainedInstance.m_Camera, &err);
	ratio = IG_ONE * RetainedInstance.PC.m_uScrWidth / RetainedInstance.PC.m_uScrHeight;
	IGCamera_setAspectRatio(mMem, RetainedInstance.m_Camera, ratio, &err);
  
	// Get the scene's root node.
	pRoot = (IGGroup *)IGScene_get(mMem, pScene, _world->m_pName_SceneRoot, IGNODE_GROUP, &err);
	RetainedInstance.m_Root = pRoot;
    
	// Start the animation.
	RetainedInstance.m_pName_Animation = _world->m_pName_Animation;
	IGNode_startAction(mMem, (IGNode *) pRoot, _world->m_pName_Animation, 0L, IGBOOL_TRUE, &err);  // you can change to ANIMATE0
	V3Retained_AC_Play();
	V3Retained_AC_SetStep(40L);

	RetainedInstance.m_Scene = pScene;
	RetainedInstance.m_iLoadingStatus = V3RETAINED_LOADING_COMPLETE;

	*ppScene = pScene;	
}

#ifdef __MTK_TARGET__
extern kal_uint32 INT_SwitchStackToRun(
                    void *stack_start,
                    kal_uint32 stack_size,
                    kal_func_ptr func,
                    kal_uint32 argc,
                    ...);
extern void kal_check_stack(void);
#endif /* __MTK_TARGET__ */ 

IGScene *V3Retained_LoadWorld(V3World *_world)
{
	IGScene *pScene;
	
	void *pNewStack = NULL;
	
	 #if defined(__MTK_TARGET__)
	  
	//如果是手機上走這裡	
	pNewStack = CNew(1024 * 10);
	  
        INT_SwitchStackToRun(
            pNewStack,
            1024 * 10,
            (kal_func_ptr)V3Retained_LoadWorld_Internal,
            2,
            (void *)_world,
            (void *) &pScene);
            
        CDel(pNewStack);    
            
    #else /* defined(__MTK_TARGET__) */ 
        V3Retained_LoadWorld_Internal(_world, &pScene);
    #endif 
	
	  return pScene;
}

void V3Retained_ChangeBackground(int _iActive)
{
	IGErr err;

	if (_iActive >= 0 && _iActive < 2 && RetainedInstance.m_Background[_iActive] != NULL)
		IGScene_setActiveBackground(mMem, RetainedInstance.m_Scene, RetainedInstance.m_Background[_iActive], &err);
}

void V3Retained_ChangeTexture(int _iActive)
{
	IGErr err;
	int cn = 0;

	if (_iActive < 0 && _iActive >= 2)
		return;

	for (cn = 0; cn < V3RETAINED_TEXTURE_BUFFER; cn = cn + 1)
	{
		if (_iActive == 0 && RetainedInstance.m_Textures[cn] != NULL && RetainedInstance.m_TexturesSwitch[cn] != NULL)
			IGScene_switchTextures(mMem, RetainedInstance.m_Scene, RetainedInstance.m_Textures[cn], RetainedInstance.m_TexturesSwitch[cn], &err);
		if (_iActive == 1 && RetainedInstance.m_Textures[cn] != NULL && RetainedInstance.m_TexturesSwitch[cn] != NULL)
			IGScene_switchTextures(mMem, RetainedInstance.m_Scene, RetainedInstance.m_TexturesSwitch[cn], RetainedInstance.m_Textures[cn], &err);
	}
}

CArray *V3Retained_GenerateAniInfo(void)
{
	CArray *self = NULL;
	int cn = 0, len, dig1, dig2;
	int iCount = V3Retained_AC_GetCount();
	char temp[DEFAULT_NAME_SIZE];
	int iDuration = 0;
	AniInfo *item = NULL;


	self = CNamedObjArray_New(NULL, NULL);

	for (cn = 0; cn < iCount; cn = cn + 1)
	{
		CMemset(temp, DEFAULT_NAME_SIZE, 0);
		CStrNCpy(temp, "ANIMATE", DEFAULT_NAME_SIZE);
		len = CStrLen(temp);
		if (cn < 10)
		{
			temp[len] = '0' + cn;
		}
		else
		{
			dig1 = cn / 10;
			dig2 = cn % 10;
			temp[len] = '0' + dig1;
			temp[len+1] = '0' + dig2;
		}
		iDuration = V3Retained_AC_GetDurationByIndex(cn);
		item = (AniInfo *) CNew(sizeof(AniInfo));
		item->m_Duration = iDuration;
		CNamedObjArray_Add(self, temp, (void *)item);
	}

	return self;
}

void V3Retained_GetPathPosition_i(IGNode *_pNode, const char *_AniName, IGU32 _uTime, igreal *_Pos)
{
	IGErr err = IGERR_NONE;
	IGU32 uPos = (_uTime * 16 * 3) / 10;	//每 16 分之一秒播放 300

	IGNode_stopAndReset(mMem, _pNode, &err);
	IGNode_startAction(mMem, _pNode, _AniName, 0L, IGBOOL_FALSE, &err);
	IGNode_update(mMem, _pNode, uPos, &err);

	IGNode_getPosition(mMem, _pNode, _Pos, &err);
}

void V3Retained_GetPathPosition(IGNode *_pNode, const char *_AniName, IGU32 _uTime, float *_Pos)
{
	IGErr err = IGERR_NONE;
	IGU32 uPos = (_uTime * 16 * 3) / 10;	//每 16 分之一秒播放 300
	igreal Pos[3];

	IGNode_stopAndReset(mMem, _pNode, &err);
	IGNode_startAction(mMem, _pNode, _AniName, 0L, IGBOOL_FALSE, &err);
	IGNode_update(mMem, _pNode, uPos, &err);

	IGNode_getPosition(mMem, _pNode, Pos, &err);

	_Pos[0] = Pos[0] / (float) IG_ONE;
	_Pos[1] = Pos[1] / (float) IG_ONE;
	_Pos[2] = Pos[2] / (float) IG_ONE;
}

void V3Retained_SetPath(IGNode *_pNode, const char *_AniName, IGU32 _uTime)
{
	IGErr err = IGERR_NONE;
	IGU32 uPos = (_uTime * 16 * 3) / 10;	//每 16 分之一秒播放 300

	IGNode_stopAndReset(mMem, _pNode, &err);
	IGNode_startAction(mMem, _pNode, _AniName, 0L, IGBOOL_FALSE, &err);
	IGNode_update(mMem, _pNode, uPos, &err);
}

void V3Retained_RotateCamera(float _iRotateH, float _iRotateV)
{
	IGErr err = IGERR_NONE;
	IGNode_rotateZ(mMem, (IGNode *) RetainedInstance.m_CameraControl, (igreal) (IG_PI * _iRotateH / 180.0f), &err);
	IGNode_rotateY(mMem, (IGNode *) RetainedInstance.m_CameraControl, (igreal) (IG_PI * _iRotateV / 180.0f), &err);
}

/*
void V3Retained_SetLookAt(igreal *_pos, igreal *_look_v, igreal *_up_v)
{
	IGCamera *pCamera = RetainedInstance.m_Camera;
}
*/

igbool V3Retained_Update(IGU32 _uDelta)
{
	IGErr err = IGERR_NONE;
	igbool bRet;
	IGU32 uDelta = (_uDelta * 16 * 3) / 10;	//每 16 分之一秒播放 300

	if (RetainedInstance.m_AC_Play)
		RetainedInstance.m_Time += uDelta;  //Note: this need to be real timer value, e.g. value from timeGetTime()

	// Update the animation.
	bRet = IGScene_update(mMem, RetainedInstance.m_Scene, RetainedInstance.m_Time, &err);

	return bRet;
}

igbool V3Retained_UpdateScene(const char *_AniName, IGU32 _uTime)
{
	IGErr err = IGERR_NONE;
	igbool bRet;
	IGU32 uPos = (_uTime * 16 * 3) / 10;	//每 16 分之一秒播放 300

	IGNode_stopAndReset(mMem, (IGNode *) RetainedInstance.m_Root, &err);
	IGNode_startAction(mMem, (IGNode *) RetainedInstance.m_Root, _AniName, 0L, IGBOOL_FALSE, &err);
	bRet = IGNode_update(mMem, (IGNode *) RetainedInstance.m_Root, uPos, &err);

	return bRet;
}

igbool V3Retained_UpdateNode(IGNode *_pNode, const char *_AniName, IGU32 _uTime)
{
	IGErr err = IGERR_NONE;
	igbool bRet;
	IGU32 uPos = (_uTime * 16 * 3) / 10;	//每 16 分之一秒播放 300

	IGNode_stopAndReset(mMem, _pNode, &err);
	IGNode_startAction(mMem, _pNode, _AniName, 0L, IGBOOL_FALSE, &err);
	bRet = IGNode_update(mMem, _pNode, uPos, &err);

	return bRet;
}

extern unsigned g_uIGTotalMemUsed;
extern unsigned g_IGNumSceneTriangles;
extern unsigned g_IGNumTriRasterized;
extern unsigned g_IGNumScnenMeshes;

extern unsigned g_IGRender2DTime;
extern unsigned g_IGRender3DTime;
extern unsigned g_IGRasterizeTime;
extern unsigned g_IGRenderUITime;

extern void V3UI_DrawNumber(int _x, int _y, int _number, float _alpha);
extern void V3UI_DrawNumber0(int _x, int _y, int _length, int _number, float _alpha);
extern void V3UI_DrawNumber0_Corner(int _corner, int _x, int _y, int _length, int _number, float _alpha);

igbool V3Retained_Render(void)
{
	IGErr err = IGERR_NONE;
	// Render the scene (move the scene data the framebuffer).

	// reset UI rendering time
	g_IGRenderUITime = 0;

	IGScene_render(RetainedInstance.m_Mem, RetainedInstance.m_Scene, RetainedInstance.m_Renderer, &err);

	/*
		V3UI_DrawNumber(120, 10, g_IGNumSceneTriangles, 1.0f);
		V3UI_DrawNumber( 60, 10, g_IGNumTriRasterized, 1.0f);

		V3UI_DrawNumber0( 10, 30, 1, g_IGRender2DTime, 1.0f);
		V3UI_DrawNumber( 60, 30, g_IGRender3DTime, 1.0f);
		V3UI_DrawNumber(120, 30, g_IGRasterizeTime, 1.0f);
		V3UI_DrawNumber(170, 30, g_IGRenderUITime, 1.0f);
	*/

	return IGBOOL_TRUE;
}

IGNode *V3Retained_GetNode(const char *_name)
{
	IGNode *node = NULL;
	IGErr err;
	node = IGScene_get(mMem, RetainedInstance.m_Scene, _name, IGNODE_GROUP, &err);
	return node;
}

IGGroup *V3Retained_GetGroup(const char *_name)
{
	IGGroup *group = NULL;
	IGErr err;
	group = (IGGroup *)IGScene_get(mMem, RetainedInstance.m_Scene, _name, IGNODE_GROUP, &err);
	return group;
}

IGMesh *V3Retained_GetMesh(const char *_name)
{
	IGMesh *pNode = NULL;
	IGErr err;
	pNode = (IGMesh *)IGScene_get(mMem, RetainedInstance.m_Scene, _name, IGNODE_MESH, &err);
	return pNode;
}

long V3Retained_GetTime(void)
{
	return RetainedInstance.m_Time;
}

void V3Retained_AC_SetStep(long _iStep)
{
	if (_iStep >= 1)
		RetainedInstance.m_AC_Step = _iStep;
}

long V3Retained_AC_GetStep(void)
{
	return RetainedInstance.m_AC_Step;
}

void V3Retained_AC_Play(void)
{
	RetainedInstance.m_AC_Play = 1;
}

void V3Retained_AC_Stop(void)
{
	RetainedInstance.m_AC_Play = 0;
}

void V3Retained_AC_Reset(void)
{
	IGErr err;

	IGNode_stopAndReset(V3Retained_GetMem(), (IGNode*) RetainedInstance.m_Root,&err);
	IGNode_startAction(mMem, (IGNode *) RetainedInstance.m_Root, RetainedInstance.m_pName_Animation, 0L, IGBOOL_TRUE, &err);

	//iTotalDuration = V3Retained_AC_GetDuration();

	RetainedInstance.m_Time = 1;
	V3Retained_Update(0L);
	RetainedInstance.m_AC_Play = 0;
}

int  V3Retained_AC_GetCount(void)
{
	IGErr err = IGERR_NONE;
	IGNode		*pNode = NULL;
    IGNode		*pNodeItr = NULL;
	int iPath = 0;

	pNode = (IGNode *) RetainedInstance.m_Root;
	if (pNode->m_type == IGNODE_GROUP)
	{
		for (pNodeItr = IGGroup_getFirstChild ((IGGroup*)pNode); pNodeItr != NULL; pNodeItr = IGGroup_getNextChild (pNodeItr))
        {
			iPath = IGObjTable_i_getSize(mMem, &pNodeItr->m_paths, &err);
			if (iPath > 0)
			{
				break;
			}
        }
	}

	return iPath;
}

int V3Retained_AC_GetDurationByIndex(int _index)
{
	IGErr err = IGERR_NONE;
	IGNode		*pNode = NULL;
    IGNode		*pNodeItr = NULL;
	IGKeyPath	*pPath = NULL;
	int iPath = 0;
	int iDuration = 0;

	pNode = (IGNode *) RetainedInstance.m_Root;
	if (pNode->m_type == IGNODE_GROUP)
	{
		for (pNodeItr = IGGroup_getFirstChild ((IGGroup*)pNode); pNodeItr != NULL; pNodeItr = IGGroup_getNextChild (pNodeItr))
        {
			iPath = IGObjTable_i_getSize(mMem, &pNodeItr->m_paths, &err);
			if (iPath > 0)
			{
				if (_index < 0 || _index >= iPath)
					return 0;

				pPath = (IGKeyPath *) IGObjTable_i_getByIndex(mMem, &pNodeItr->m_paths, _index, &err);
				iDuration = IGKeyPath_i_getDuration(mMem, pPath, &err);
				break;
			}
        }
	}

	iDuration = (iDuration * 10) / 48;
	return iDuration;
}

int V3Retained_AC_GetDuration(void)
{
	IGErr err;
	IGNode		*pNode = NULL;
    IGNode		*pNodeItr = NULL;
	IGKeyPath	*pPath = NULL;
	int iPath = 0;
	int cn = 0;
	int iDuration = 0, iTotalDuration = 0;

	pNode = (IGNode *) RetainedInstance.m_Root;
	if (pNode->m_type == IGNODE_GROUP)
	{
		for (pNodeItr = IGGroup_getFirstChild ((IGGroup*)pNode); pNodeItr != NULL; pNodeItr = IGGroup_getNextChild (pNodeItr))
        {
			iPath = IGObjTable_i_getSize(mMem, &pNodeItr->m_paths, &err);
			if (iPath > 0)
			{
				iTotalDuration = 0;
				for (cn = 0; cn < iPath; cn = cn + 1)
				{
					pPath = (IGKeyPath *) IGObjTable_i_getByIndex(mMem, &pNodeItr->m_paths, cn, &err);
					iDuration = IGKeyPath_i_getDuration(mMem, pPath, &err);
					iTotalDuration = iTotalDuration + iDuration;
				}
			}
        }
	}

	return iTotalDuration;
}

IGTexture *V3Retained_LoadImage2D(const unsigned char * _bmp_array, const char *_bmp_name, int _keycolor)
{
	IGErr err;
	IGTexture *pTexture = NULL;

	pTexture = IGTexture_newFromByteArray(RetainedInstance.m_Mem, _bmp_array, _bmp_name, RetainedInstance.PC.m_MaskR, RetainedInstance.PC.m_MaskG, RetainedInstance.PC.m_MaskB, &err);
	if (pTexture != NULL && _keycolor != 0)
	{
		IGTexture_setKeyColorEnabled(RetainedInstance.m_Mem, pTexture, IGBOOL_TRUE, &err);
		IGTexture_setKeyColor(RetainedInstance.m_Mem, pTexture, IGTexture_getDeviceColor(RetainedInstance.m_Mem, pTexture, _keycolor, &err), &err);  
	}
	return pTexture;
}

#ifdef __cplusplus
}
#endif // __cplusplus
