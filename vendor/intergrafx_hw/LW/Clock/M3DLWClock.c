//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWClock
// File        : M3DLWClock.c
// Description : IGV5 LW Clock
// Author      : Ray
// Create      : 2011-06-20
// Update      : 2012-01-11
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWClock.h"
#include "M3DTextureManager.h"
#include "M3DEventQueue.h"

#ifdef __cplusplus
extern "C" {
#endif

M3DLWClockApp M3DLWClock = {0};
static M3DRenderer *rr = NULL;

//================== Interface Begin =========================
int M3DLWClock_OnStartup(void *_pc)
{
	M3DConfig *PC = (M3DConfig *)_pc;
	int ret = 1;

	rr = &M3DLWClock.m_Renderer;

	m3d_adaption_init(&M3DLWClock.m_adaption, _pc);
	PC->m_pMemBuffer = m3d_alloc_engine_memory(&M3DLWClock.m_adaption, PC->m_MemSize);

	ret = M3DRenderer_Init(&M3DLWClock.m_Renderer, PC);

	M3DLWClock_Init();

	return ret;
}

void M3DLWClock_OnShutdown(void)
{
	M3DLWClock_Release();
	M3DRenderer_Del(rr);
	m3d_free_engine_memory(&M3DLWClock.m_adaption);
}

void M3DLWClock_OnResume(void)
{
	m3d_time_resume(&M3DLWClock.m_adaption);
}

void M3DLWClock_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2)
{
	long Time = _Time;

	if (M3DLWClock.m_GameTime < IGLW_CLOCK_DELAY_TIME)
		return;

	if (Time == 0L)
		Time = (long) M3DLWClock.m_GameTime;
	M3DEventQueue_PostEvent(M3DLWClock.m_EventMemPool, M3DLWClock.m_Event, _Id, Time, _Data1, _Data2);
}

static M3DEvent *pSE = NULL;

void M3DLWClock_OnUpdate(int suspend)
{
	M3DLWClock.m_ElapsedTime = m3d_time_get_elapsed(&M3DLWClock.m_adaption);
	M3DLWClock.m_ElapsedTime = (float) (M3DLWClock.m_ElapsedTime * M3DLWClock.m_TimeFactor);

#if defined(M3D_DEBUG_FRAME)
	M3DLWClock.m_ElapsedTime = 10L;	//for debug
#endif

    if (suspend)
    {
        M3DLWClock.m_ElapsedTime = 0L; //real suspend animation and stop IG reference time
    }
	
	M3DLWClock.m_GameTime = M3DLWClock.m_GameTime + M3DLWClock.m_ElapsedTime;

	while ((pSE = (M3DEvent *) M3DQueue_Pop(M3DLWClock.m_Event)) != NULL)
	{
		unsigned mem_used = M3DRenderer_GetUsedMemory(&M3DLWClock.m_Renderer);

		//remove all event
		if (M3DLWClock.m_GameTime < IGLW_CLOCK_DELAY_TIME)
		{
			M3DEventQueue_Free(M3DLWClock.m_EventMemPool, pSE);
			continue;
		}

		switch (pSE->m_uEventID)
		{
		case IGV5EID_BEGINTOUCH :
			M3DRotateCenter_SetTouch(&M3DLWClock.m_RotateCamera, 1);
			break;
		case IGV5EID_TOUCH :	
			//if (M3DLWPage_IsLastPage(&M3DLWClock.m_Page) == 1 && ((signed)pSE->m_uData1 - MouseX) < 0)
			//	M3DRotateCenter_Move(&M3DLWClock.m_RotateCamera, 10.0f);
			//if (M3DLWPage_IsFirstPage(&M3DLWClock.m_Page) == 1 && ((signed)pSE->m_uData1 - MouseX) > 0)
			//	M3DRotateCenter_Move(&M3DLWClock.m_RotateCamera, -10.0f);
			break;
		case IGV5EID_ENDTOUCH :
			M3DRotateCenter_SetTouch(&M3DLWClock.m_RotateCamera, 0);
			if (M3DLWClock.m_Page.m_Status == 1)
				M3DLWPage_SetStatus(&M3DLWClock.m_Page, 0);
			else
				M3DLWClock_ProcessTouch(pSE->m_uData1, pSE->m_uData2);
			break;
		case  IGV5EID_LWBOUNDSCHANGED :
			M3DLWPage_Changed(&M3DLWClock.m_Page, pSE->m_uData1);
			break;
		}

		M3DEventQueue_Free(M3DLWClock.m_EventMemPool, pSE);
	}

	if (M3DLWClock.m_GameTime > IGLW_2D_DELAY_TIME && M3DLWClock.m_Scene->m_bLoaded == 0)
		M3DLWClock_Init2();

	if (M3DLWClock.m_GameTime <= IGLW_2D_DELAY_TIME)
		M3DRenderer_Render2D(&M3DLWClock.m_Renderer, "bg2d.pvr");
	else
		M3DLWClock_Update();
}

//================== Interface End ===========================

int M3DLWClock_Init(void)
{
	M3DLWClock.m_Scene = M3DModel_New(&M3DLWClock.m_Renderer, "scene");
	M3DLWClock.m_Face  = M3DModel_New(&M3DLWClock.m_Renderer, "face");
	M3DLWClock.m_Gear  = M3DModel_New(&M3DLWClock.m_Renderer, "gear");
	M3DLWClock.m_Gear2 = M3DModel_New(&M3DLWClock.m_Renderer, "gear2");
	M3DLWClock.m_Hand  = M3DModel_New(&M3DLWClock.m_Renderer, "hand");
	M3DLWClock.m_SceneTextureNames = NULL;
	M3DLWClock.m_FaceTextureNames  = NULL;
	M3DLWClock.m_GearTextureNames  = NULL;
	M3DLWClock.m_Gear2TextureNames = NULL;
	M3DLWClock.m_HandTextureNames  = NULL;

	M3DLWClock_LoadBackground2D();

	M3DLWClock.m_EventMemPool = M3DEventQueue_New(MAX_ARRAY_POOL);
	M3DLWClock.m_Event = M3DQueue_New(DEFAULT_QUEUE_SIZE);
	M3DLWClock.m_TimeFactor = 1.0f;
	M3DLWClock.m_GameTime = 0L;

	return 1;
}

int M3DLWClock_Init2(void)
{
	M3DLWClock_RemoveBackground2D();

	M3DLWClock_LoadContent();
	M3DRotateCenter_InitPager(&M3DLWClock.m_RotateCamera, &M3DLWClock.m_Page, -60.0f, 60.0f);

	M3DModel_SetActiveCamera(M3DLWClock.m_Scene);
	M3DModel_SetActiveLight(M3DLWClock.m_Scene);
	M3DRenderer_SetCameraNearFar(&M3DLWClock.m_Renderer, 1.0f, 10000.0f);

	M3DLWPage_Init(&M3DLWClock.m_Page, M3DLWClock.m_Renderer.m_EngineRC.m_sEGLInfo.m_uWidth, 5);
	M3DModel_AnimateStop(M3DLWClock.m_Face);
	M3DRenderer_EnableSpecular(&M3DLWClock.m_Renderer, 1);

	return 1;
}

void M3DLWClock_Release(void)
{
	M3DEventQueue_ClearPendingEvents(M3DLWClock.m_EventMemPool, M3DLWClock.m_Event);
	M3DEventQueue_Del(M3DLWClock.m_EventMemPool);
	M3DLWClock.m_EventMemPool = NULL;
	M3DQueue_Del(M3DLWClock.m_Event);
	M3DLWClock.m_Event = NULL;
	M3DLWClock.m_GameTime = 0L;

	M3DSplitString_Del(M3DLWClock.m_HandTextureNames);
	M3DSplitString_Del(M3DLWClock.m_Gear2TextureNames);
	M3DSplitString_Del(M3DLWClock.m_GearTextureNames);
	M3DSplitString_Del(M3DLWClock.m_FaceTextureNames);
	M3DSplitString_Del(M3DLWClock.m_SceneTextureNames);

	M3DModel_Del(M3DLWClock.m_Hand);
	M3DModel_Del(M3DLWClock.m_Gear2);
	M3DModel_Del(M3DLWClock.m_Gear);
	M3DModel_Del(M3DLWClock.m_Face);
	M3DModel_Del(M3DLWClock.m_Scene);
}

void M3DLWClock_MoveHand(void)
{
		float deg_hh, deg_mm, deg_ss;

		deg_hh = (LW_AdaptionClock.m_Hour % 12 + LW_AdaptionClock.m_Minute / 60.0f) * 2.0f / 12.0f;
		deg_mm = (LW_AdaptionClock.m_Minute + LW_AdaptionClock.m_Second / 60.0f) * 2.0f / 60.0f;
		deg_ss = LW_AdaptionClock.m_Second * 2.0f / 60.0f;

		M3DModel_SetNodeYRotation(M3DLWClock.m_Hand, "P2-0601", -deg_hh * 180.0f);
		M3DModel_SetNodeYRotation(M3DLWClock.m_Hand, "P2-0600", -deg_mm * 180.0f);
		M3DModel_SetNodeYRotation(M3DLWClock.m_Hand, "P2-0602", -deg_ss * 180.0f);
}

void M3DLWClock_Update(void)
{
	float face_time = 0;

	if (M3DLWClock.m_Gear2->m_bLoaded == 0 && M3DLWClock.m_GameTime > IGLW_CLOCK_DELAY_TIME)
	{
		M3DLWClock_LoadContent2();
		M3DLWPage_Changed(&M3DLWClock.m_Page, m3d_adaption_get_pageX());
	}

	M3DLWClock_MoveHand();

	M3DModel_AnimateLoop(M3DLWClock.m_Scene, M3DLWClock.m_ElapsedTime, 0);
	M3DModel_AnimateCurrentOnceAndPause(M3DLWClock.m_Face,  M3DLWClock.m_ElapsedTime);
	M3DModel_AnimateLoop(M3DLWClock.m_Gear,  M3DLWClock.m_ElapsedTime, 0);
	M3DModel_AnimateLoop(M3DLWClock.m_Gear2, M3DLWClock.m_ElapsedTime, 0);
	M3DModel_AnimateLoop(M3DLWClock.m_Hand,  M3DLWClock.m_ElapsedTime, 0);

	M3DModel_SetNodeYRotation(M3DLWClock.m_Scene, "camera", -M3DRotateCenter_UpdatePageX(&M3DLWClock.m_RotateCamera, M3DLWClock.m_ElapsedTime));
	M3DModel_SetActiveCamera(M3DLWClock.m_Scene);
	M3DModel_SetActiveLight(M3DLWClock.m_Scene);
	//M3DRenderer_SetCameraRotation(rr, M3DRotateCenter_UpdatePageX(&M3DLWClock.m_RotateCamera, M3DLWClock.m_ElapsedTime));
	//M3DRenderer_UpdateCameraRotation(rr);
	//M3DRenderer_SetCameraPanX(rr, M3DRotateCenter_UpdatePage(&M3DLWClock.m_RotateCamera, M3DLWClock.m_ElapsedTime));
	//M3DRenderer_UpdateCameraPan(rr);
	//M3DModel_FaceToCameraByXZ(M3DLWClock.m_Scene, "Plane03");

	face_time = M3DModel_GetCurrentFrame(M3DLWClock.m_Face);
	if (face_time >= 20 && face_time < 170)
	{
		M3DModel_EnableNode(M3DLWClock.m_Face, "Object01", 0);
		M3DModel_EnableNode(M3DLWClock.m_Face, "Object02", 0);
		M3DModel_EnableNode(M3DLWClock.m_Face, "Object03", 0);
		M3DModel_EnableNode(M3DLWClock.m_Face, "Object04", 0);
		M3DModel_EnableNode(M3DLWClock.m_Face, "Object05", 0);
		M3DModel_EnableNode(M3DLWClock.m_Face, "Object06", 0);
		M3DModel_EnableNode(M3DLWClock.m_Face, "Object07", 0);
		M3DModel_EnableNode(M3DLWClock.m_Face, "Cylinder01", 0);
	}
	else
	{
		M3DModel_EnableNode(M3DLWClock.m_Face, "Object01", 1);
		M3DModel_EnableNode(M3DLWClock.m_Face, "Object02", 1);
		M3DModel_EnableNode(M3DLWClock.m_Face, "Object03", 1);
		M3DModel_EnableNode(M3DLWClock.m_Face, "Object04", 1);
		M3DModel_EnableNode(M3DLWClock.m_Face, "Object05", 1);
		M3DModel_EnableNode(M3DLWClock.m_Face, "Object06", 1);
		M3DModel_EnableNode(M3DLWClock.m_Face, "Object07", 1);
		M3DModel_EnableNode(M3DLWClock.m_Face, "Cylinder01", 1);
	}

	M3DModel_EnableNode(M3DLWClock.m_Scene, "Cylinder02", 0);

	M3DRenderer_PrepareRender(&M3DLWClock.m_Renderer);
	M3DModel_Render(M3DLWClock.m_Hand);
	M3DModel_Render(M3DLWClock.m_Face);
	M3DModel_Render(M3DLWClock.m_Gear);
	M3DModel_Render(M3DLWClock.m_Gear2);
	M3DModel_Render(M3DLWClock.m_Scene);
	M3DRenderer_Render(&M3DLWClock.m_Renderer);

	/* calculate FPS */
	m3d_time_update_FPS(&M3DLWClock.m_adaption, &M3DLWClock.m_Renderer.m_EngineRC.m_sPerformanceInfo);
}

void M3DLWClock_ProcessTouch(int _mouseX, int _mouseY)
{
	if (M3DLWClock.m_Face->m_Stop == 1)
	{
		if (M3DLWClock.m_Face->m_iCurrentAnimation == 1)
		{
			M3DModel_SetAnimationStart(M3DLWClock.m_Face, 2);
		}
		else
		{
			M3DModel_SetAnimationStart(M3DLWClock.m_Face, 1);
		}
		//M3DModel_SetTime(M3DLWClock.m_Face, 2000);
	}
}

#ifdef __cplusplus
}
#endif

/* end of M3DLWClock.c */

