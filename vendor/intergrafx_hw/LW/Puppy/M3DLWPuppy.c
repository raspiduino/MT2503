//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWPuppy
// File        : M3DLWPuppy.c
// Description : IGV5 LW Puppy
// Author      : Ray
// Create      : 2011-08-23
// Update      : 2011-12-23
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWPuppy.h"
#include "M3DTextureManager.h"
#include "M3DEventQueue.h"

#ifdef __cplusplus
extern "C" {
#endif

M3DLWPuppyApp M3DLWPuppy = {0};
static M3DRenderer *rr = NULL;

//================== Interface Begin =========================
int M3DLWPuppy_OnStartup(void *_pc)
{
	M3DConfig *PC = (M3DConfig *)_pc;
	int ret = 1;

	rr = &M3DLWPuppy.m_Renderer;

	m3d_adaption_init(&M3DLWPuppy.m_adaption, _pc);
	PC->m_pMemBuffer = m3d_alloc_engine_memory(&M3DLWPuppy.m_adaption, PC->m_MemSize);

	ret = M3DRenderer_Init(&M3DLWPuppy.m_Renderer, PC);
	M3DModel_InitStock();

	M3DLWPuppy_Init();
	m3d_time_resume(&M3DLWPuppy.m_adaption);

	return ret;
}

void M3DLWPuppy_OnShutdown(void)
{
	M3DLWPuppy_Release();
	M3DRenderer_Del(rr);
	m3d_free_engine_memory(&M3DLWPuppy.m_adaption);
}

void M3DLWPuppy_OnResume(void)
{
	m3d_time_resume(&M3DLWPuppy.m_adaption);
}

void M3DLWPuppy_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2)
{
	unsigned long Time = _Time;

	if (M3DLWPuppy.m_GameTime < IGLW_PUPPY_DELAY_TIME)
		return;

	if (Time == 0L)
		Time = (long) M3DLWPuppy.m_GameTime;
	M3DEventQueue_PostEvent(M3DLWPuppy.m_EventMemPool, M3DLWPuppy.m_Event, _Id, Time, _Data1, _Data2);
}

static M3DEvent *pSE = NULL;

void M3DLWPuppy_OnUpdate(int suspend)
{
	if (M3DLWPuppy.m_Event == NULL)
		return;

	M3DLWPuppy.m_ElapsedTime = m3d_time_get_elapsed(&M3DLWPuppy.m_adaption);
	M3DLWPuppy.m_ElapsedTime = (float) (M3DLWPuppy.m_ElapsedTime * M3DLWPuppy.m_TimeFactor);

#if defined(M3D_DEBUG_FRAME)
	//M3DLWPuppy.m_ElapsedTime = 10L;	//for debug
#endif

    if (suspend)
    {
        M3DLWPuppy.m_ElapsedTime = 0L; //real suspend animation and stop IG reference time
    }

	M3DLWPuppy.m_GameTime = M3DLWPuppy.m_GameTime + M3DLWPuppy.m_ElapsedTime;
	M3DLWPuppy.m_Renderer.m_GameTime = M3DLWPuppy.m_GameTime;

	while ((pSE = (M3DEvent *) M3DQueue_Pop(M3DLWPuppy.m_Event)) != NULL)
	{
		unsigned mem_used = M3DRenderer_GetUsedMemory(&M3DLWPuppy.m_Renderer);

		//remove all event
		if (M3DLWPuppy.m_GameTime < IGLW_PUPPY_DELAY_TIME)
		{
			M3DEventQueue_Free(M3DLWPuppy.m_EventMemPool, pSE);
			continue;
		}

		switch (pSE->m_uEventID)
		{
		case IGV5EID_BEGINTOUCH :
			M3DRotateCenter_SetTouch(&M3DLWPuppy.m_RotateCamera, 1);
			break;
		case IGV5EID_TOUCH :	
			//if (M3DLWPage_IsLastPage(&M3DLWPuppy.m_Page) == 1 && ((signed)pSE->m_uData1 - MouseX) < 0)
			//	M3DRotateCenter_Move(&M3DLWPuppy.m_RotateCamera, 10.0f);
			//if (M3DLWPage_IsFirstPage(&M3DLWPuppy.m_Page) == 1 && ((signed)pSE->m_uData1 - MouseX) > 0)
			//	M3DRotateCenter_Move(&M3DLWPuppy.m_RotateCamera, -10.0f);
			break;
		case IGV5EID_ENDTOUCH :
			M3DRotateCenter_SetTouch(&M3DLWPuppy.m_RotateCamera, 0);
			M3DLWPuppy_ProcessTouch(pSE->m_uData1, pSE->m_uData2);
			break;
		case  IGV5EID_LWBOUNDSCHANGED :
			M3DLWPage_Changed(&M3DLWPuppy.m_Page, pSE->m_uData1);
			break;
		}

		M3DEventQueue_Free(M3DLWPuppy.m_EventMemPool, pSE);
	}

	if (M3DLWPuppy.m_GameTime > IGLW_2D_DELAY_TIME && M3DLWPuppy.m_Scene->m_bLoaded == 0)
		M3DLWPuppy_Init2();

	if (M3DLWPuppy.m_GameTime <= IGLW_2D_DELAY_TIME)
		M3DRenderer_Render2D(&M3DLWPuppy.m_Renderer, "bg2d.pvr");
	else
		M3DLWPuppy_Update();
}

//================== Interface End ===========================
int M3DLWPuppy_Init(void)
{
	M3DLWPuppy.m_Scene  = M3DModel_New(&M3DLWPuppy.m_Renderer, "scene");
	M3DLWPuppy.m_Cloud  = M3DModel_New(&M3DLWPuppy.m_Renderer, "cloud");
	M3DLWPuppy.m_Window = M3DModel_New(&M3DLWPuppy.m_Renderer, "window");
	M3DLWPuppy.m_Dog    = M3DModel_New(&M3DLWPuppy.m_Renderer, "dog");
	M3DLWPuppy.m_SceneTextureNames  = NULL;
	M3DLWPuppy.m_CloudTextureNames  = NULL;
	M3DLWPuppy.m_WindowTextureNames = NULL;
	M3DLWPuppy.m_DogTextureNames    = NULL;

	M3DLWPuppy_LoadBackground2D();

	M3DLWPuppy.m_EventMemPool = M3DEventQueue_New(MAX_ARRAY_POOL);
	M3DLWPuppy.m_Event = M3DQueue_New(DEFAULT_QUEUE_SIZE);
	M3DLWPuppy.m_TimeFactor = 0.3333f;
	M3DLWPuppy.m_GameTime = 0.0f;
	M3DLWPuppy.m_IdleStartTime = -1;

	return 1;
}

int M3DLWPuppy_Init2(void)
{
	M3DLWPuppy_RemoveBackground2D();

	M3DLWPuppy_LoadContent();

	M3DModel_SetActiveCamera(M3DLWPuppy.m_Scene);
	M3DModel_SetActiveLight(M3DLWPuppy.m_Scene);

	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWPuppy.m_Renderer, M3D_UV_DISPLACEMENT_SHADER, 0.01f);
	//M3DRenderer_Shader_SetAlphaThreshold(&M3DLWPuppy.m_Renderer, M3D_GOURAUD_SHADOW_SHADER, 0.2f);
	//M3DRenderer_Shader_SetAlphaThreshold(&M3DLWPuppy.m_Renderer, M3D_SKINNING_GOURAUD_SHADER, 0.2f);
	M3DRenderer_SetAlphaTestCmpValue(&M3DLWPuppy.m_Renderer, 0.01f);

	//M3DRebond_Init(&M3DLWPuppy.m_RebondCamera, -90.0f, 90.0f);
	M3DModel_SetDefaultAnimation(M3DLWPuppy.m_Dog, 0, 1.0f);
	M3DModel_SetAnimationByName(M3DLWPuppy.m_Dog, "init");
	M3DModel_SetReflection(M3DLWPuppy.m_Scene);
	M3DModel_InitReflector(M3DLWPuppy.m_Scene, "Floor01", 0.8f);

	M3DLWPage_Init(&M3DLWPuppy.m_Page, M3DLWPuppy.m_Renderer.m_EngineRC.m_sEGLInfo.m_uWidth, 5);
	M3DRotateCenter_InitPager(&M3DLWPuppy.m_RotateCamera, &M3DLWPuppy.m_Page, -15.0f, 15.0f);
	M3DRenderer_SetAlphaTestCmpValue(&M3DLWPuppy.m_Renderer, 0.01f);

	return 1;
}

void M3DLWPuppy_Release(void)
{
	M3DEventQueue_ClearPendingEvents(M3DLWPuppy.m_EventMemPool, M3DLWPuppy.m_Event);
	M3DEventQueue_Del(M3DLWPuppy.m_EventMemPool);
	M3DLWPuppy.m_EventMemPool = NULL;
	M3DQueue_Del(M3DLWPuppy.m_Event);
	M3DLWPuppy.m_Event = NULL;
	M3DLWPuppy.m_GameTime = 0.0f;

	M3DRenderer_ReleaseReflection(&M3DLWPuppy.m_Renderer);

	M3DSplitString_Del(M3DLWPuppy.m_DogTextureNames);
	M3DSplitString_Del(M3DLWPuppy.m_WindowTextureNames);
	M3DSplitString_Del(M3DLWPuppy.m_CloudTextureNames);
	M3DSplitString_Del(M3DLWPuppy.m_SceneTextureNames);

	M3DModel_Del(M3DLWPuppy.m_Dog);
	M3DModel_Del(M3DLWPuppy.m_Window);
	M3DModel_Del(M3DLWPuppy.m_Cloud);
	M3DModel_Del(M3DLWPuppy.m_Scene);
}

void M3DLWPuppy_Update(void)
{
	if (M3DLWPuppy.m_Dog->m_bLoaded == 0 && M3DLWPuppy.m_GameTime > IGLW_PUPPY_DELAY_TIME)
	{
		M3DLWPuppy_LoadContent2();
		M3DRenderer_ReleaseReflection(&M3DLWPuppy.m_Renderer);
		M3DModel_SetReflection(M3DLWPuppy.m_Dog);
		M3DModel_InitReflector(M3DLWPuppy.m_Scene, "Floor01", 0.8f);
		M3DLWPage_Changed(&M3DLWPuppy.m_Page, m3d_adaption_get_pageX());

		M3DModel_EnableNode(M3DLWPuppy.m_Dog, "Symbol01", 0);
		M3DModel_EnableNode(M3DLWPuppy.m_Dog, "Symbol02", 0);
	}

	if (M3DModel_IsDefaultAnimation(M3DLWPuppy.m_Dog) == 1)
	{
		if (M3DLWPuppy.m_IdleStartTime == -1)
			M3DLWPuppy.m_IdleStartTime = M3DLWPuppy.m_GameTime;

		if (M3DLWPuppy.m_GameTime - M3DLWPuppy.m_IdleStartTime > 5000)
		{
			int iAni = m3d_adaption_rand() % 8 + 5 + 1;
			M3DModel_SetAnimation(M3DLWPuppy.m_Dog, iAni);
			M3DLWPuppy.m_IdleStartTime = -1;
		}
	}

	M3DModel_AnimateLoop(M3DLWPuppy.m_Scene, M3DLWPuppy.m_ElapsedTime, 0);
	M3DModel_AnimateLoop(M3DLWPuppy.m_Cloud, M3DLWPuppy.m_ElapsedTime, 0);
	M3DModel_AnimateLoop(M3DLWPuppy.m_Window, M3DLWPuppy.m_ElapsedTime, 0);

	if (M3DLWPuppy.m_Dog->m_iCurrentAnimation == 0)
		M3DModel_AnimateCurrentLoop(M3DLWPuppy.m_Dog, M3DLWPuppy.m_ElapsedTime, 1);
	else
		M3DModel_AnimateCurrent(M3DLWPuppy.m_Dog, M3DLWPuppy.m_ElapsedTime);

	//M3DRenderer_SetCameraPanX(rr, M3DRotateCenter_UpdatePage(&M3DLWPuppy.m_RotateCamera, M3DLWPuppy.m_ElapsedTime));
	//M3DRenderer_UpdateCameraPan(rr);
	M3DRenderer_SetCameraRotation(rr, M3DRotateCenter_UpdatePageX(&M3DLWPuppy.m_RotateCamera, M3DLWPuppy.m_ElapsedTime));
	M3DRenderer_UpdateCameraRotation(rr);

	M3DRenderer_PrepareRender(&M3DLWPuppy.m_Renderer);
	M3DRenderer_PrepareReflection(&M3DLWPuppy.m_Renderer);


	M3DModel_Render(M3DLWPuppy.m_Dog);  //CY

	M3DModel_Render(M3DLWPuppy.m_Scene);  //CY

	M3DModel_Render(M3DLWPuppy.m_Window);		
	M3DModel_Render(M3DLWPuppy.m_Cloud);	

	M3DRenderer_Render(&M3DLWPuppy.m_Renderer);

	/* calculate FPS */
	m3d_time_update_FPS(&M3DLWPuppy.m_adaption, &M3DLWPuppy.m_Renderer.m_EngineRC.m_sPerformanceInfo);
}

void M3DLWPuppy_ProcessTouch(int _mouseX, int _mouseY)
{
	if (M3DModel_IsDefaultAnimation(M3DLWPuppy.m_Dog) == 1)
	{
		int rnd = m3d_adaption_rand() % 3;
		if (M3DLWPuppy.m_Page.m_CurrentPage == 2 && rnd == 0)
		{
			//­w¦b¿Ã¹õ«e
			M3DModel_SetAnimation(M3DLWPuppy.m_Dog, 2);
		}
		else
		{
			rnd = (m3d_adaption_rand() % 5) + 1;
			if (rnd == 2)
				rnd = 3;
			M3DModel_SetAnimation(M3DLWPuppy.m_Dog, rnd);
		}
		M3DLWPuppy.m_IdleStartTime = -1;
	}
}

#ifdef __cplusplus
}
#endif

/* end of M3DLWPuppy.c */

