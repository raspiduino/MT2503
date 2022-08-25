/**
@file IGSprite.h  
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
#ifndef IG_SPRITE_H
#define IG_SPRITE_H

#include "IGMemoryPool.h"
#include "IGRenderer.h"
#include "IGTexture.h"

#ifdef __cplusplus
extern "C"
{
#endif


/*--------------------------------------------------------------------*\
|   IGSprite public interface
\*--------------------------------------------------------------------*/
void        IGSprite_draw       ( IGMemoryPool*     pMemPool, 
                                  const IGRenderer* pRender, 
                                  const IGPoint*    pDestPos,
                                  IGTexture*        pSrcTexture, 
                                  const IGRect*     pSrcRect, 
                                  IGErr*            pErr );

void		IGSprite_drawbackground(   IGMemoryPool*       pMemPool, 
								const IGRenderer*   pRender, 
								const IGPoint*      pDestPos,
								IGTexture*          pSrcTexture, 
								const IGRect*       pSrcRect, 
								IGErr*              pErr );

void        IGSprite_drawTrans  ( IGMemoryPool*     pMemPool,
                                  const IGRenderer* pRender, 
                                  const IGPoint*    pDestPos,
                                  IGTexture*        pSrcTexture, 
                                  const IGRect*     pSrcRect,
                                  igreal            iAlpha, 
                                  IGErr*            pErr );

void        IGSprite_drawCore       ( IGMemoryPool*     pMemPool, 
                                  const IGRenderer* pRender, 
                                  const IGPoint*    pDestPos,
                                  IGTexture*        pSrcTexture, 
                                  const IGRect*     pSrcRect, 
                                  IGErr*            pErr );

void		IGSprite_drawbackgroundCore(   IGMemoryPool*       pMemPool, 
								const IGRenderer*   pRender, 
								const IGPoint*      pDestPos,
								IGTexture*          pSrcTexture, 
								const IGRect*       pSrcRect, 
								IGErr*              pErr );

void        IGSprite_drawTransCore  ( IGMemoryPool*     pMemPool,
                                  const IGRenderer* pRender, 
                                  const IGPoint*    pDestPos,
                                  IGTexture*        pSrcTexture, 
                                  const IGRect*     pSrcRect,
                                  igreal            iAlpha, 
                                  IGErr*            pErr );

void IGSprite_drawTransCoreTex
(   IGMemoryPool*       pMemPool, 
    const IGTexture*    pDstTexture, 
    const IGPoint*      pDestPos, 
    IGTexture*          pSrcTexture, 
    const IGRect*       pSrcRect, 
    igreal              iAlpha,
    IGErr*              pErr );


#ifdef __cplusplus
}
#endif

#endif//IG_SPRITE_H

