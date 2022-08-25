//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWGirl
// File        : M3DLWGirl.h
// Description : IGV5 LW Girl
// Author      : Ray
// Create      : 2011-06-20
// Update      : 2011-12-20
//==============================================================================

#ifndef __M3D_LW_GIRL_H__
#define __M3D_LW_GIRL_H__

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

#define IGLW_GIRL_DELAY_TIME	2000

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _M3DLWGirl
{
	float	m_GameTime;
	float	m_ElapsedTime;
	float	m_TimeFactor;
	float	m_GameTime_DelayLoad;

	M3D_Adaption	m_adaption;
	M3DRenderer		m_Renderer;
	M3DArrayPool	*m_EventMemPool;
	M3DQueue		*m_Event;

	M3DModel		*m_Scene;
	M3DModel		*m_Girl;
	M3DSplitString	*m_SceneTextureNames;
	M3DSplitString	*m_GirlTextureNames;

	M3DRotateCenter	m_RotateCamera;
	M3DLWPage		m_Page;

	//如果 Page 在最左邊, 模型會有問題, 所以 10000 之後, Page 才能變
	int				m_bMatchPage;
} M3DLWGirlApp;

extern M3DLWGirlApp M3DLWGirl;

extern int  M3DLWGirl_OnStartup(void *_pc);
extern void M3DLWGirl_OnShutdown(void);
extern void M3DLWGirl_OnResume(void);

extern void M3DLWGirl_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2);

extern void M3DLWGirl_OnUpdate(int suspend);

extern void M3DLWGirl_LoadBackground2D(void);
extern void M3DLWGirl_RemoveBackground2D(void);

extern int  M3DLWGirl_Init(void);
extern int  M3DLWGirl_Init2(void);
extern void M3DLWGirl_Release(void);
extern int  M3DLWGirl_LoadContent(void);
extern void M3DLWGirl_LoadContent2(void);
extern void M3DLWGirl_Update(void);
extern void M3DLWGirl_ProcessTouch(int _mouseX, int _mouseY);

#ifdef __cplusplus
}
#endif

#endif /* __IGV5_PLAYER_H__ */


