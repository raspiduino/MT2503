//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWSolar
// File        : M3DLWSolar.c
// Description : IGV5 LW Solar
// Author      : Ray
// Create      : 2011-08-25
// Update      : 2011-12-23
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWSolar.h"
#include "M3DTextureManager.h"
#include "M3DEventQueue.h"

#ifdef __cplusplus
extern "C" {
#endif

M3DLWSolarApp M3DLWSolar = {0};
static M3DRenderer *rr = NULL;

//================== Interface Begin =========================
int M3DLWSolar_OnStartup(void *_pc)
{
	M3DConfig *PC = (M3DConfig *)_pc;
	int ret = 1;

	rr = &M3DLWSolar.m_Renderer;

	m3d_adaption_init(&M3DLWSolar.m_adaption, _pc);
	PC->m_pMemBuffer = m3d_alloc_engine_memory(&M3DLWSolar.m_adaption, PC->m_MemSize);

	ret = M3DRenderer_Init(&M3DLWSolar.m_Renderer, PC);

	M3DLWSolar_Init();

	return ret;
}

void M3DLWSolar_OnShutdown(void)
{
	M3DLWSolar_Release();
	M3DRenderer_Del(rr);
	m3d_free_engine_memory(&M3DLWSolar.m_adaption);
}

void M3DLWSolar_OnResume(void)
{
	m3d_time_resume(&M3DLWSolar.m_adaption);
}

void M3DLWSolar_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2)
{
	unsigned long Time = _Time;

	if (M3DLWSolar.m_GameTime < IGLW_SOLAR_DELAY_TIME)
		return;

	if (Time == 0L)
		Time = (long) M3DLWSolar.m_GameTime;
	M3DEventQueue_PostEvent(M3DLWSolar.m_EventMemPool, M3DLWSolar.m_Event, _Id, Time, _Data1, _Data2);
}

static M3DEvent *pSE = NULL;

void M3DLWSolar_OnUpdate(int suspend)
{
	static int MouseY = 0;
	M3DLWSolar.m_ElapsedTime = m3d_time_get_elapsed(&M3DLWSolar.m_adaption);
	M3DLWSolar.m_ElapsedTime = (float) (M3DLWSolar.m_ElapsedTime * M3DLWSolar.m_TimeFactor);

#if defined(M3D_DEBUG_FRAME)
	M3DLWSolar.m_ElapsedTime = 10L;	//for debug
#endif

    if (suspend)
    {
        M3DLWSolar.m_ElapsedTime = 0L; //real suspend animation and stop IG reference time
    }

	M3DLWSolar.m_GameTime = M3DLWSolar.m_GameTime + M3DLWSolar.m_ElapsedTime;
	M3DLWSolar.m_Renderer.m_GameTime = M3DLWSolar.m_GameTime;

	while ((pSE = (M3DEvent *) M3DQueue_Pop(M3DLWSolar.m_Event)) != NULL)
	{
		switch (pSE->m_uEventID)
		{
		case IGV5EID_BEGINTOUCH :
			M3DRotateCenter_SetTouch(&M3DLWSolar.m_RotateCamera, 1);
			M3DRotateCenter_SetTouch(&M3DLWSolar.m_VerticalCamera, 1);
			MouseY = pSE->m_uData2;
			break;
		case IGV5EID_TOUCH :	
			M3DRotateCenter_MoveByPixel(&M3DLWSolar.m_VerticalCamera, (signed)pSE->m_uData2 - MouseY, 0.5f);
			/*
			if (MouseY != 0)
			{
				if (pSE->m_uData2 > MouseY)
					M3DRotateCenter_Move(&M3DLWSolar.m_VerticalCamera, -5.0f);
				else
					M3DRotateCenter_Move(&M3DLWSolar.m_VerticalCamera, 5.0f);
			}
			*/
			MouseY = pSE->m_uData2;
			break;
		case IGV5EID_ENDTOUCH :
			{
				int bTouchMove = M3DRotateCenter_GetTouchMove(&M3DLWSolar.m_VerticalCamera);
				if (bTouchMove == 1 || M3DLWSolar.m_Page.m_Status == 1)
					M3DLWPage_SetStatus(&M3DLWSolar.m_Page, 0);
				else
					M3DLWSolar_ProcessTouch(pSE->m_uData1, pSE->m_uData2);
				M3DRotateCenter_SetTouch(&M3DLWSolar.m_RotateCamera, 0);
				M3DRotateCenter_SetTouch(&M3DLWSolar.m_VerticalCamera, 0);
			}
			MouseY = pSE->m_uData2;
			break;
		case  IGV5EID_LWBOUNDSCHANGED :
			M3DLWPage_Changed(&M3DLWSolar.m_Page, pSE->m_uData1);
			break;
		}

		M3DEventQueue_Free(M3DLWSolar.m_EventMemPool, pSE);
	}

	if (M3DLWSolar.m_GameTime > IGLW_2D_DELAY_TIME && M3DLWSolar.m_Scene->m_bLoaded == 0)
		M3DLWSolar_Init2();

	if (M3DLWSolar.m_GameTime <= IGLW_2D_DELAY_TIME)
		M3DRenderer_Render2D(&M3DLWSolar.m_Renderer, "bg2d.pvr");
	else
		M3DLWSolar_Update();
}

//================== Interface End ===========================
int M3DLWSolar_Init(void)
{
	M3DLWSolar.m_Scene  = M3DModel_New(&M3DLWSolar.m_Renderer, "scene");
	M3DLWSolar.m_Planet = M3DModel_New(&M3DLWSolar.m_Renderer, "planet");
	M3DLWSolar.m_Tube   = M3DModel_New(&M3DLWSolar.m_Renderer, "tube");
	M3DLWSolar.m_SceneTextureNames  = NULL;
	M3DLWSolar.m_PlanetTextureNames = NULL;
	M3DLWSolar.m_TubeTextureNames   = NULL;

	M3DLWSolar_LoadBackground2D();

	M3DLWSolar.m_EventMemPool = M3DEventQueue_New(MAX_ARRAY_POOL);
	M3DLWSolar.m_Event = M3DQueue_New(DEFAULT_QUEUE_SIZE);
	M3DLWSolar.m_TimeFactor = 1.0f;
	M3DLWSolar.m_GameTime = 0L;
	M3DLWSolar.m_RotateDegree = 0.0f;

	return 1;
}

int M3DLWSolar_Init2(void)
{
	M3DLWSolar_RemoveBackground2D();

	M3DLWSolar_LoadContent();
	M3DModel_EnableNode(M3DLWSolar.m_Planet, "Tube01", 0);
	M3DModel_EnableNode(M3DLWSolar.m_Tube, "Tube01", 0);
	M3DRotateCenter_Init2(&M3DLWSolar.m_VerticalCamera, 0.0f, 130.0f);
	M3DRotateCenter_InitPager(&M3DLWSolar.m_RotateCamera, &M3DLWSolar.m_Page, -180.0f, 180.0f);
	M3DLWPage_Init(&M3DLWSolar.m_Page, M3DLWSolar.m_Renderer.m_EngineRC.m_sEGLInfo.m_uWidth, 5);

	//M3DModel_SetShadow(M3DLWSolar.m_Planet);

	M3DModel_SetActiveCamera(M3DLWSolar.m_Scene);
	M3DModel_SetActiveLight(M3DLWSolar.m_Planet);
	M3DRenderer_SetCameraNearFar(&M3DLWSolar.m_Renderer, 50.0f, 10000.0f);

	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWSolar.m_Renderer, M3D_GOURAUD_SHADER, 0.01f);
	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWSolar.m_Renderer, M3D_UV_DISPLACEMENT_SHADER, 0.01f);
	M3DRenderer_SetAlphaTestCmpValue(&M3DLWSolar.m_Renderer, 0.01f);

	M3DRotateSimple_InitRandom(&M3DLWSolar.m_Revolution[0], 0.015f);
	M3DRotateSimple_InitRandom(&M3DLWSolar.m_Revolution[1], 0.012f);
	M3DRotateSimple_InitRandom(&M3DLWSolar.m_Revolution[2], 0.010f);
	M3DRotateSimple_InitRandom(&M3DLWSolar.m_Revolution[3], 0.008f);
	M3DRotateSimple_InitRandom(&M3DLWSolar.m_Revolution[4], 0.005f);
	M3DRotateSimple_InitRandom(&M3DLWSolar.m_Revolution[5], 0.0025f);
	M3DRotateSimple_InitRandom(&M3DLWSolar.m_Revolution[6], 0.002f);
	M3DRotateSimple_InitRandom(&M3DLWSolar.m_Revolution[7], 0.0015f);
	//M3DRebond_Init(&M3DLWSolar.m_RebondCamera, -90.0f, 90.0f);

		//index = IGV5Model_FindNodeIdxByName(&M3DLWSolar.m_Planet->m_Node, "Mercury_1");
		//M3DModel_GetNodePosition(M3DLWSolar.m_Planet, "Mercury_1", &pos);
		//M3DRenderer_SetLookTo(rr, &pos);
	M3DLWPage_Changed(&M3DLWSolar.m_Page, m3d_adaption_get_pageX());
	M3DRenderer_SetCameraNearFar(&M3DLWSolar.m_Renderer, 5.0f, 10000.0f);
	M3DLWSolar.m_CameraStatus = 0;
	return 1;
}

void M3DLWSolar_Release(void)
{
	M3DEventQueue_ClearPendingEvents(M3DLWSolar.m_EventMemPool, M3DLWSolar.m_Event);
	M3DEventQueue_Del(M3DLWSolar.m_EventMemPool);
	M3DLWSolar.m_EventMemPool = NULL;
	M3DQueue_Del(M3DLWSolar.m_Event);
	M3DLWSolar.m_Event = NULL;
	M3DLWSolar.m_GameTime = 0L;

	M3DSplitString_Del(M3DLWSolar.m_TubeTextureNames);
	M3DSplitString_Del(M3DLWSolar.m_PlanetTextureNames);
	M3DSplitString_Del(M3DLWSolar.m_SceneTextureNames);

	M3DModel_Del(M3DLWSolar.m_Tube);
	M3DModel_Del(M3DLWSolar.m_Planet);
	M3DModel_Del(M3DLWSolar.m_Scene);
}

void M3DLWSolar_Update(void)
{
	//M3DModel_Update(M3DLWSolar.m_Scene, (float) M3DLWSolar.m_ElapsedTime / 1000.0f);
	//M3DModel_Update(M3DLWSolar.m_Solar, M3DLWSolar.m_GameTime);
	//M3DModel_AnimateOnce(M3DLWSolar.m_Scene, M3DLWSolar.m_ElapsedTime);
	M3DModel_AnimateLoop(M3DLWSolar.m_Planet, M3DLWSolar.m_ElapsedTime, 0);
	M3DModel_AnimateLoop(M3DLWSolar.m_Tube, M3DLWSolar.m_ElapsedTime, 0);

	M3DRenderer_SetCameraRotation(rr, M3DRotateCenter_Update(&M3DLWSolar.m_VerticalCamera, M3DLWSolar.m_ElapsedTime));
	M3DRenderer_UpdateVerticalCameraRotation(rr);
	M3DRenderer_SetCameraRotation(rr, M3DRotateCenter_UpdatePageX(&M3DLWSolar.m_RotateCamera, M3DLWSolar.m_ElapsedTime));
	//M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Tube02", -M3DLWSolar.m_RotateCamera.m_Degree);
	M3DRenderer_UpdateCameraRotation(rr);

	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Mercury_1", M3DLWSolar.m_RotateDegree);
	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Venus_1", M3DLWSolar.m_RotateDegree);
	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Earth_1", M3DLWSolar.m_RotateDegree);
	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Earth_2", -M3DLWSolar.m_RotateDegree);
	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Moon", M3DLWSolar.m_RotateDegree);
	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "mars_1", M3DLWSolar.m_RotateDegree);
	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Jupiter_2", M3DLWSolar.m_RotateDegree);
	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Saturn_1", M3DLWSolar.m_RotateDegree);
	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Saturn_2", M3DLWSolar.m_RotateDegree);
	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Uranus_1", M3DLWSolar.m_RotateDegree);
	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Neptune_1", M3DLWSolar.m_RotateDegree);
	M3DLWSolar.m_RotateDegree += 0.2f;

	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Mercury",         M3DRotateSimple_Update(&M3DLWSolar.m_Revolution[0], M3DLWSolar.m_ElapsedTime));
	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Venus",           M3DRotateSimple_Update(&M3DLWSolar.m_Revolution[1], M3DLWSolar.m_ElapsedTime));
	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Earth_All_Dummy", M3DRotateSimple_Update(&M3DLWSolar.m_Revolution[2], M3DLWSolar.m_ElapsedTime));
	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "mars",            M3DRotateSimple_Update(&M3DLWSolar.m_Revolution[3], M3DLWSolar.m_ElapsedTime));
	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Jupiter_1",       M3DRotateSimple_Update(&M3DLWSolar.m_Revolution[4], M3DLWSolar.m_ElapsedTime));
	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Saturn",          M3DRotateSimple_Update(&M3DLWSolar.m_Revolution[5], M3DLWSolar.m_ElapsedTime));
	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Uranus",          M3DRotateSimple_Update(&M3DLWSolar.m_Revolution[6], M3DLWSolar.m_ElapsedTime));
	M3DModel_SetNodeYRotation(M3DLWSolar.m_Planet, "Neptune",         M3DRotateSimple_Update(&M3DLWSolar.m_Revolution[7], M3DLWSolar.m_ElapsedTime));

	M3DModel_FaceToCamera(M3DLWSolar.m_Planet, "Sun_Glow");
	//M3DModel_FaceToCamera(M3DLWSolar.m_Planet, "Glow02");
	//M3DModel_FaceToCamera(M3DLWSolar.m_Planet, "Glow03");
	//M3DModel_FaceToCamera(M3DLWSolar.m_Planet, "Glow04");

	M3DRenderer_PrepareRender(&M3DLWSolar.m_Renderer);
	//M3DRenderer_PrepareShadow(&M3DLWSolar.m_Renderer);

	M3DModel_Render(M3DLWSolar.m_Scene);  //CY end
	M3DModel_Render(M3DLWSolar.m_Planet);  //CY begin
	IGV5Renderer_SetBackFaceCulling(IGV5RS_CULL_NONE);
	M3DModel_Render(M3DLWSolar.m_Tube);
	IGV5Renderer_SetBackFaceCulling(IGV5RS_CULL_BACK);
	
	M3DRenderer_Render(&M3DLWSolar.m_Renderer);
	//M3DRenderer_ReleaseShadow(&M3DLWSolar.m_Renderer);

	/* calculate FPS */
	m3d_time_update_FPS(&M3DLWSolar.m_adaption, &M3DLWSolar.m_Renderer.m_EngineRC.m_sPerformanceInfo);
}

void M3DLWSolar_ProcessTouch(int _mouseX, int _mouseY)
{
	int bIsMoving = M3DRotateCenter_IsMoving(&M3DLWSolar.m_RotateCamera);

	if (bIsMoving == 0)
	{
		if (M3DLWSolar.m_CameraStatus == 1)
		{
			M3DModel_SetActiveCamera(M3DLWSolar.m_Scene);
			M3DRenderer_SetCameraNearFar(&M3DLWSolar.m_Renderer, 5.0f, 10000.0f);
			M3DLWSolar.m_CameraStatus = 0;
			M3DModel_EnableNode(M3DLWSolar.m_Tube, "Tube01", 0);
		}
		else
		{
			M3DModel_SetActiveCamera(M3DLWSolar.m_Planet);
			M3DRenderer_SetCameraNearFar(&M3DLWSolar.m_Renderer, 5.0f, 10000.0f);
			M3DLWSolar.m_CameraStatus = 1;
			M3DModel_EnableNode(M3DLWSolar.m_Tube, "Tube01", 1);
		}
	}
}

#ifdef __cplusplus
}
#endif

/* end of M3DLWSolar.c */

