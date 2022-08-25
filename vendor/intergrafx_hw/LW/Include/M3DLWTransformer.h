//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWTransformer
// File        : M3DLWTransformer.h
// Description : IGV5 Mali ´ú¸Õ±M®×
// Author      : Ray
// Create      : 2011-06-20
// Update      : 2011-12-23
//==============================================================================

#ifndef __M3D_LW_TRANSFORMER_H__
#define __M3D_LW_TRANSFORMER_H__

#include "IGV5RuntimeContext.h"
#include "IGV5Font.h"
#include "IGV5Camera.h"
#include "M3D_Adaption.h"
#include "M3DRenderer.h"
#include "M3DModel.h"
#include "M3DPhysics.h"

#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
#include "win32_runtime.h"
#else
#include "6256_runtime.h"
#endif

#define IGLW_TRANSFORMER_DELAY_TIME  2000
#define IGLW_TRANSFORMER_REFLECTION  1

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _M3DLWTransformer
{
	float	m_GameTime;
	float	m_ElapsedTime;
	float	m_TimeFactor;
	float	m_LightTime;
	int		m_Status;

	M3D_Adaption	m_adaption;
	M3DRenderer		m_Renderer;
	M3DArrayPool	*m_EventMemPool;
	M3DQueue		*m_Event;

	M3DModel		*m_Scene;
	M3DModel		*m_Transformer;
	M3DSplitString	*m_SceneTextureNames;
	M3DSplitString	*m_TransformerTextureNames;

  M3DRotateSimple m_RotScene;
	M3DRotateCenter	m_RotateCamera;
	M3DRotateCenter	m_VerticalCamera;
	M3DLWPage		m_Page;
} M3DLWTransformerApp;

extern M3DLWTransformerApp M3DLWTransformer;

extern int  M3DLWTransformer_OnStartup(void *_pc);
extern void M3DLWTransformer_OnShutdown(void);
extern void M3DLWTransformer_OnResume(void);

extern void M3DLWTransformer_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2);

extern void M3DLWTransformer_OnUpdate(int suspend);

extern void M3DLWTransformer_LoadBackground2D(void);
extern void M3DLWTransformer_RemoveBackground2D(void);

extern int  M3DLWTransformer_Init(void);
extern int  M3DLWTransformer_Init2(void);
extern void M3DLWTransformer_Release(void);
extern int  M3DLWTransformer_LoadContent(void);
extern void M3DLWTransformer_LoadContent2(void);
extern void M3DLWTransformer_EnableObjects(void);
extern void M3DLWTransformer_CheckLightTime(void);
extern void M3DLWTransformer_Update(void);
extern void M3DLWTransformer_ProcessTouch(int _mouseX, int _mouseY);

#ifdef __cplusplus
}
#endif

#endif /* __IGV5_PLAYER_H__ */


