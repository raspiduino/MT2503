/*!****************************************************************************

 @File         IGV5RenderTarget.h

 @Title        IGV5RenderTarget

 @Version      

 @brief			header file for device render target

******************************************************************************/

#ifndef __IGV5RENDERTARGET_H
#define __IGV5RENDERTARGET_H

#include "IGV5Texture.h"
#include "IGV5Renderer.h"


#ifdef __cplusplus
extern "C" {
#endif

#define IGV5RT_ZBUFFER 0x000000001
#define IGV5RT_STENCIL 0x000000002

typedef struct {

	unsigned m_uFlag;

	unsigned m_uFBO;

	IGV5Texture *m_pRT;

	IGV5Rect m_VP;

} IGV5RenderTarget;


/*!***************************************************************************
 @fn			IGV5RenderTarget_CreateFromTexture
 @brief			pRT					Initialized IGV5RenderTarget object
 @param				pTex				pointer to texture created for RT
 @brief		Read a vector
*****************************************************************************/
IGV5Err IGV5RenderTarget_Create(IGV5RenderTarget *pRT, unsigned uWidth, unsigned uHeight, unsigned uFormat, unsigned uFlag);

/*!***************************************************************************
 @fn			IGV5RenderTarget_CreateFromTexture
 @brief			pRT					Initialized IGV5RenderTarget object
 @param				pTex				Pointer to texture 
 @param				uFlag				special flag indicate if this RT has 
										Z-buffer or Stencil buffer
 @brief		Read a vector
*****************************************************************************/
IGV5Err IGV5RenderTarget_CreateFromTexture(IGV5RenderTarget *pRT, IGV5Texture *pTex,  unsigned uFlag);

/*!***************************************************************************
 @fn			IGV5RenderTarget_BeginScene
 @param				pRT					Poinrer of IGV5RenderTarget
 @brief		Make specified rendertarget ready
*****************************************************************************/
IGV5Err IGV5RenderTarget_BeginScene(IGV5RenderTarget *pRT);

/*!***************************************************************************
 @fn			IGV5RenderTarget_EndScene
 @param				pRT					Poinrer of IGV5RenderTarget
 @brief		Flush all pending rendering actions of RT
*****************************************************************************/
void IGV5RenderTarget_EndScene(IGV5RenderTarget *pRT);

/*!***************************************************************************
 @fn			IGV5RenderTarget_Release
 @brief			pRT					Released RT structure
 @brief		Release resources of RT
*****************************************************************************/
void IGV5RenderTarget_Release(IGV5RenderTarget *pRT);

/*!***************************************************************************
 @fn			IGV5RenderTarget_Set
 @param				pThisRC				Pointer to IGV5RC
 @param				pRT					Pointer to RT structure
 @brief		Set specified render target as current render target
*****************************************************************************/
IGV5Err IGV5RenderTarget_Set(IGV5RC *pThisRC, IGV5RenderTarget *pRT);

#ifdef __cplusplus
}
#endif

#endif

