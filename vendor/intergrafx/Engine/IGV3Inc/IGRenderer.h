/**
@file IGRenderer.h 
@brief 

@par Last updated:


@par Copyright (c) 2005 InterGrafx, Inc. All rights reserved.
InterGrafx CONFIDENTIAL AND PROPRIETARY
@par
This source is the sole property of InterGrafx Inc. Reproduction or
Utilization of this source in whole or in part is forbidden without
The written consent of InterGrafx Inc.

@par History:


@par Description:
more description here.
*/
#ifndef IG_RENDERER_H
#define IG_RENDERER_H

#include "IGMemoryPool.h"
#include "IGDataCache.h"
#include "IGMesh.h"
#include "IGRasterizer.h"
#include "IGRenderBuffers.h"
#include "IGCamera.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct _IGProjector
{
    IGCamera*      m_cam;
	IGTexture*     m_tex;
	igbool         m_prjOn;

}   IGProjector;

typedef struct _IGRendererRec
{
    IGCamera*       m_renderCam;
    IGObjCache      m_lights;
    IGObjCache      m_meshes;
    IGDataCache     m_trisToDraw;

    IGRect          m_lastValidRect;
    IGRect          m_validRect;
    int             m_inval;

    IGRasterizer    m_raster;
    IGRenderBuffers m_buffs;

	IGProjector       m_proj;

	int               m_eff;

}  IGRenderer;

/*--------------------------------------------------------------------*\
|   IGRenderer public interface
\*--------------------------------------------------------------------*/
/**
* IGRenderer constructor.
* Allocates a new IGRenderer.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pErr
*   Stores error code raised by this function
* @return
*   Handle to the newly created IGRenderer; NULL if creation failed
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   IGRenderer* hRender = IGRenderer_new(pMemPool, pErr);
* @endcode
* @see IGRenderer_destroy
*/
IGRenderer*     IGRenderer_new          ( IGMemoryPool* pMemPool, 
                                          IGErr*        pErr );
/**
* IGRenderer destructor.
* Deallocates an IGRenderer.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pRender
*   Handle to the IGRenderer
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hRender references a previously allocated IGRenderer.
*   // Dispose of the IGRenderer object
*   if (hRender) {
*     IGRenderer_destroy(pMemPool, hRender, pErr);
*   }
* @endcode
* @see IGRenderer_new
*/
void            IGRenderer_destroy      ( IGMemoryPool* pMemPool, 
                                          IGRenderer*   pRender, 
                                          IGErr*        pErr );

igbool          IGRenderer_getRenderRect( IGMemoryPool* pMemPool, 
                                          IGRenderer*   pRender, 
                                          IGRect*       pRect, 
                                          IGErr*        pErr );

void            IGRenderer_setRenderRect( IGMemoryPool* pMemPool, 
                                          IGRenderer*   pRender, 
                                          IGRect*       pRect, 
                                          igbool        iUpdated, 
                                          IGErr*        pErr );
  

/**
* Tells an IGRenderer where to draw its results to.
* The caller supplies a pointer to a target pixel buffer. Also indicates
* whether the renderer should support per-pixel z-buffering and translucency.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pRender
*   Handle to the IGRenderer
* @param pixelBuffer
*   Destination rendering buffer; the first @a width * @a height elements of
*   this buffer will hold rendering results in a platform-specific color
*   format; a caller will usually specify hardware video memory as the
*   destination buffer
* @param iWidth
*   Width of the destination buffer in pixels
* @param iHeight
*   Height of the destination buffer in pixels
* @param iIsTopDown
*   IGBOOL_TRUE if the destination buffer's scanlines ordered from top to bottom;
*   IGBOOL_FALSE if scanlines are ordered from bottom to top
* @param iIsZBuffered
*   Set to @a IGBOOL_TRUE to enable per-pixel z-buffering; otherwise the engine uses
*   another depth algorithm that is less accurate but doesn't have the
*   overhead of allocating a z-buffer
* @param iRMask
*   Color with all red bits set and all other bits cleared.
* @param iGMask
*   Color with all green bits set and all other bits cleared.
* @param iBMask
*   Color with all blue bits set and all other bits cleared.
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hRender references a previously allocated IGRenderer.
*   // g_pFrameBuff is a previously set up global pixel array (igcolor*).
*   // Create a relationship between pixel buffer g_pFrameBuff and renderer hRender.
*   IGRenderer_setTarget(pMemPool, hRender, g_pFrameBuff, 400L, 400L, IGBOOL_FALSE,
*                        IGBOOL_FALSE, 0xF00, 0xF0, 0xF, pErr);
* @endcode
* @see IGScene_render
* @see IGBOOL_FALSE
* @see IGBOOL_TRUE
*/
void            IGRenderer_setTarget    ( IGMemoryPool* pMemPool, 
                                          IGRenderer*   pRender, 
                                          igcolor*      pixelBuffer,
                                          unsigned long iWidth, 
                                          unsigned long iHeight, 
                                          igbool        iIsTopDown, 
                                          igbool        iIsZBuffered,
										  igbool        iIsShadowEnable,
                                          igcolor       iRMask, 
                                   igcolor       iGMask, 
                                          igcolor       iBMask, 
                                          IGErr*        pErr );


void IGRenderer_changeTarget
(   IGMemoryPool*   pMemPool, 
    IGRenderer*     pRender,
    igcolor*        iPixelBuffer, 
    IGErr*          pErr );


void			IGRenderer_setCamera	( IGMemoryPool* pMemPool,
										  IGRenderer*	pRender,
										  IGCamera*		pCam,
										  IGErr*		pErr );


igbool          IGRenderer_getViewport( IGMemoryPool* pMemPool, 
                                          IGRenderer*   pRender, 
                                          IGRect**       pRect, 
                                          IGErr*        pErr );

void            IGRenderer_setViewport( IGMemoryPool* pMemPool, 
                                          IGRenderer*   pRender, 
                                          IGRect*       pRect, 
										  igint32       x,
										  igint32       y,
										  IGErr*        pErr );

void IGRenderer_clear(IGMemoryPool* pMemPool, IGRenderer* pRender, igcolor wColor, IGErr *pErr);

//Utility functions to get pointer of framebuffers, etc.

/**
* IGRenderer_getFrameBuffer
* Direct access to current framebuffer
* @param pRender
*   Handle to the IGRenderer
* @return
*   pointer to array of igcolor (size = framebuffer width * height * sizeof(igcolor)
*/
igcolor* IGRenderer_getFrameBuffer(IGRenderer* pRender);

/**
* IGRenderer_getFrameBuffer
* Direct access to current framebuffer
* @param pRender
*   Handle to the IGRenderer
* @return
*   pointer to array of igreal (size = framebuffer width * height * sizeof(igcolor)
*/
igreal* IGRenderer_getZBuffer(IGRenderer* pRender);

#ifdef __cplusplus
}
#endif

#endif//IG_RENDERER_H

