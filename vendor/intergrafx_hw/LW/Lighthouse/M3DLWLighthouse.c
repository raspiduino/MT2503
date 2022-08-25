//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWLighthouse
// File        : M3DLWLighthouse.c
// Description : IGV5 LW Lighthouse
// Author      : Ray
// Create      : 2011-08-12
// Update      : 2011-08-30
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWLighthouse.h"
#include "M3DTextureManager.h"
#include "M3DEventQueue.h"

#ifdef __cplusplus
extern "C" {
#endif

M3DLWLighthouseApp M3DLWLighthouse;
static M3DRenderer *rr = NULL;

static int M3DLWLighthouse_DrawReflectionModels(struct IGV5SkyBoxType *pSkyBox,IGV5Matrix *pView, IGV5Matrix *pProjection);

//================== Interface Begin =========================
int M3DLWLighthouse_OnStartup(void *_pc)
{
	M3DConfig *PC = (M3DConfig *)_pc;
	int ret = 1;

	rr = &M3DLWLighthouse.m_Renderer;

	m3d_adaption_init(&M3DLWLighthouse.m_adaption, _pc);
	PC->m_pMemBuffer = m3d_alloc_engine_memory(&M3DLWLighthouse.m_adaption, PC->m_MemSize);

	M3DRenderer_Init(&M3DLWLighthouse.m_Renderer, PC);

	M3DLWLighthouse_Init();

	return ret;
}

void M3DLWLighthouse_OnShutdown(void)
{
	M3DLWLighthouse_Release();
	M3DRenderer_Del(rr);
	m3d_free_engine_memory(&M3DLWLighthouse.m_adaption);
}

void M3DLWLighthouse_OnResume(void)
{
	m3d_time_resume(&M3DLWLighthouse.m_adaption);
}

void M3DLWLighthouse_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2)
{
	unsigned long Time = _Time;

	if (M3DLWLighthouse.m_GameTime < IGLW_LIGHTHOUSE_DELAY_TIME)
		return;

	if (Time == 0L)
		Time = (long) M3DLWLighthouse.m_GameTime;
	M3DEventQueue_PostEvent(M3DLWLighthouse.m_EventMemPool, M3DLWLighthouse.m_Event, _Id, Time, _Data1, _Data2);
}

static M3DEvent *pSE = NULL;

void M3DLWLighthouse_OnUpdate(int suspend)
{
	static int MouseY = 0;	
	M3DLWLighthouse.m_ElapsedTime = m3d_time_get_elapsed(&M3DLWLighthouse.m_adaption);
	M3DLWLighthouse.m_ElapsedTime = (float) (M3DLWLighthouse.m_ElapsedTime * M3DLWLighthouse.m_TimeFactor);

#if defined(M3D_DEBUG_FRAME)
	M3DLWLighthouse.m_ElapsedTime = 10L;	//for debug
#endif 

    if (suspend)
    {
        M3DLWLighthouse.m_ElapsedTime = 0L; //real suspend animation and stop IG reference time
    }

	M3DLWLighthouse.m_GameTime = M3DLWLighthouse.m_GameTime + M3DLWLighthouse.m_ElapsedTime;

	while ((pSE = (M3DEvent *) M3DQueue_Pop(M3DLWLighthouse.m_Event)) != NULL)
	{
		switch (pSE->m_uEventID)
		{
		case IGV5EID_BEGINTOUCH :
			M3DRotateCenter_SetTouch(&M3DLWLighthouse.m_RotateCamera, 1);
			M3DRotateCenter_SetTouch(&M3DLWLighthouse.m_VerticalCamera, 1);
			MouseY = pSE->m_uData2;
			break;
		case IGV5EID_TOUCH :	
			M3DRotateCenter_MoveByPixel(&M3DLWLighthouse.m_VerticalCamera, (signed)pSE->m_uData2 - MouseY, 0.5f);
			MouseY = pSE->m_uData2;
			break;
		case IGV5EID_ENDTOUCH :
			{
				int bTouchMove = M3DRotateCenter_GetTouchMove(&M3DLWLighthouse.m_VerticalCamera);
				if (bTouchMove == 1 || M3DLWLighthouse.m_Page.m_Status == 1)
					M3DLWPage_SetStatus(&M3DLWLighthouse.m_Page, 0);
				else
					M3DLWLighthouse_ProcessTouch(pSE->m_uData1, pSE->m_uData2);
				M3DRotateCenter_SetTouch(&M3DLWLighthouse.m_RotateCamera, 0);
				M3DRotateCenter_SetTouch(&M3DLWLighthouse.m_VerticalCamera, 0);
			}
			MouseY = pSE->m_uData2;
			break;
		case  IGV5EID_LWBOUNDSCHANGED :
			M3DLWPage_Changed(&M3DLWLighthouse.m_Page, pSE->m_uData1);
			break;
		}

		M3DEventQueue_Free(M3DLWLighthouse.m_EventMemPool, pSE);
	}
	
	if (M3DLWLighthouse.m_GameTime > IGLW_2D_DELAY_TIME && M3DLWLighthouse.m_Scene->m_bLoaded == 0)
		M3DLWLighthouse_Init2();

	if (M3DLWLighthouse.m_GameTime <= IGLW_2D_DELAY_TIME)
		M3DRenderer_Render2D(&M3DLWLighthouse.m_Renderer, "bg2d.pvr");
	else
		M3DLWLighthouse_Update();
}

//================== Interface End ===========================

int M3DLWLighthouse_Init(void)
{
	M3DLWLighthouse.m_Scene = M3DModel_New(&M3DLWLighthouse.m_Renderer, "scene");
	M3DLWLighthouse.m_Ray   = M3DModel_New(&M3DLWLighthouse.m_Renderer, "ray");
	M3DLWLighthouse.m_Birds = M3DModel_New(&M3DLWLighthouse.m_Renderer, "birds");
	M3DLWLighthouse.m_Whale = M3DModel_New(&M3DLWLighthouse.m_Renderer, "whale");
	M3DLWLighthouse.m_Ray2   = M3DModel_New(&M3DLWLighthouse.m_Renderer, "ray2");

	M3DLWLighthouse.m_BirdsPath = M3DDummyGroup_New(rr);
	M3DLWLighthouse.m_WhalePath = M3DDummyGroup_New(rr);

	M3DLWLighthouse.m_SceneTextureNames = NULL;
	M3DLWLighthouse.m_RayTextureNames   = NULL;
	M3DLWLighthouse.m_BirdsTextureNames = NULL;
	M3DLWLighthouse.m_WhaleTextureNames = NULL;
	M3DLWLighthouse.m_Ray2TextureNames  = NULL;

	M3DLWLighthouse_LoadBackground2D();

	M3DLWLighthouse.m_EventMemPool = M3DEventQueue_New(MAX_ARRAY_POOL);
	M3DLWLighthouse.m_Event = M3DQueue_New(DEFAULT_QUEUE_SIZE);
	M3DLWLighthouse.m_TimeFactor = 1.0f;
	M3DLWLighthouse.m_GameTime = 0L;

	return 1;
}

int M3DLWLighthouse_Init2(void)
{
	M3DLWLighthouse_RemoveBackground2D();

	M3DLWLighthouse_LoadContent();
	
	M3DRotateCenter_Init2(&M3DLWLighthouse.m_VerticalCamera, 0.0f, 130.0f);
	M3DRotateCenter_InitPager(&M3DLWLighthouse.m_RotateCamera, &M3DLWLighthouse.m_Page, -180.0f, 180.0f);

	M3DModel_SetActiveCamera(M3DLWLighthouse.m_Scene);
	M3DModel_SetActiveLight(M3DLWLighthouse.m_Scene);

	M3DRenderer_SetCameraRotation(rr, 0.0f);
	M3DRenderer_SetAlphaTestCmpValue(&M3DLWLighthouse.m_Renderer, 0.1f);

	M3DRenderer_SetCameraNearFar(&M3DLWLighthouse.m_Renderer, 20.0f, 5000.0f);
	M3DLWPage_Init(&M3DLWLighthouse.m_Page, M3DLWLighthouse.m_Renderer.m_EngineRC.m_sEGLInfo.m_uWidth, 5);
	M3DRotateSimple_InitRandom(&M3DLWLighthouse.m_RotateRay, 0.3f);

	CLinear_Init(&M3DLWLighthouse.m_CameraEnterLookAt, M3DLWLighthouse.m_Renderer.m_CameraInfo.m_To.x + 50.0f, M3DLWLighthouse.m_Renderer.m_CameraInfo.m_To.y + 5.0f, M3DLWLighthouse.m_Renderer.m_CameraInfo.m_To.z, M3DLWLighthouse.m_Renderer.m_CameraInfo.m_To.x, M3DLWLighthouse.m_Renderer.m_CameraInfo.m_To.y, M3DLWLighthouse.m_Renderer.m_CameraInfo.m_To.z, 0L, IGLW_LIGHTHOUSE_DELAY_TIME);

	M3DRenderer_InitSkybox(&M3DLWLighthouse.m_Renderer, "Water.pvr", "Sky_box.pvr", M3DLWLighthouse_DrawReflectionModels);
	
	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWLighthouse.m_Renderer, M3D_TEXTURE_SHADER, 0.2f);
	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWLighthouse.m_Renderer, M3D_SKINNING_TEXTURE_SHADER, 0.2f);	

	return 1;
}

void M3DLWLighthouse_Release(void)
{
	M3DEventQueue_ClearPendingEvents(M3DLWLighthouse.m_EventMemPool, M3DLWLighthouse.m_Event);
	M3DEventQueue_Del(M3DLWLighthouse.m_EventMemPool);
	M3DLWLighthouse.m_EventMemPool = NULL;
	M3DQueue_Del(M3DLWLighthouse.m_Event);
	M3DLWLighthouse.m_Event = NULL;
	M3DLWLighthouse.m_GameTime = 0L;

	M3DSplitString_Del(M3DLWLighthouse.m_WhaleTextureNames);
	M3DSplitString_Del(M3DLWLighthouse.m_BirdsTextureNames);
	M3DSplitString_Del(M3DLWLighthouse.m_RayTextureNames);
	M3DSplitString_Del(M3DLWLighthouse.m_SceneTextureNames);
	M3DSplitString_Del(M3DLWLighthouse.m_Ray2TextureNames);

	M3DModel_Del(M3DLWLighthouse.m_Scene);
	M3DModel_Del(M3DLWLighthouse.m_Ray);
	M3DModel_Del(M3DLWLighthouse.m_Birds);
	M3DModel_Del(M3DLWLighthouse.m_Whale);
	M3DModel_Del(M3DLWLighthouse.m_Ray2);

	M3DDummyGroup_Del(M3DLWLighthouse.m_BirdsPath);
	M3DDummyGroup_Del(M3DLWLighthouse.m_WhalePath);
	M3DRenderer_ReleaseSkybox(&M3DLWLighthouse.m_Renderer);
}

void M3DLWLighthouse_Update(void)
{
	M3DModel_AnimateLoop(M3DLWLighthouse.m_Scene, M3DLWLighthouse.m_ElapsedTime, 0);
	M3DModel_AnimateLoop(M3DLWLighthouse.m_Birds, M3DLWLighthouse.m_ElapsedTime, 0);
	M3DModel_AnimateLoop(M3DLWLighthouse.m_Whale, M3DLWLighthouse.m_ElapsedTime, 0);
	M3DDummyGroup_Animate(M3DLWLighthouse.m_WhalePath, M3DLWLighthouse.m_ElapsedTime);
	M3DDummyGroup_Animate2(M3DLWLighthouse.m_BirdsPath, M3DLWLighthouse.m_ElapsedTime);

	M3DModel_SetNodeYRotation(M3DLWLighthouse.m_Ray, "Box01", M3DRotateSimple_Update(&M3DLWLighthouse.m_RotateRay, M3DLWLighthouse.m_ElapsedTime * 0.1f));
	M3DModel_FaceToCamera(M3DLWLighthouse.m_Ray2, "ray_2");

	M3DRenderer_SetCameraRotation(&M3DLWLighthouse.m_Renderer, M3DRotateCenter_Update(&M3DLWLighthouse.m_VerticalCamera, M3DLWLighthouse.m_ElapsedTime));
	M3DRenderer_UpdateVerticalCameraRotation(&M3DLWLighthouse.m_Renderer);
	M3DRenderer_SetCameraRotation(&M3DLWLighthouse.m_Renderer, M3DRotateCenter_UpdatePageX(&M3DLWLighthouse.m_RotateCamera, M3DLWLighthouse.m_ElapsedTime));
	M3DRenderer_UpdateCameraRotation(&M3DLWLighthouse.m_Renderer);

	IGV5Model_GetLight(&M3DLWLighthouse.m_Scene->m_Node, &M3DLWLighthouse.m_Renderer.m_Light);

	M3DRenderer_PrepareRender(&M3DLWLighthouse.m_Renderer);

	IGV5Renderer_SetAlphaBlendMode(IGV5RS_ALPHA_COMPLEMENT);
	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWLighthouse.m_Renderer, M3D_TEXTURE_SHADER, 0.01f);

	M3DRenderer_SetAlphaTestCmpValue(&M3DLWLighthouse.m_Renderer, 0.01f); 

	M3DRenderer_UpdateSkybox(&M3DLWLighthouse.m_Renderer, M3DLWLighthouse.m_ElapsedTime);
	
	M3DModel_Render(M3DLWLighthouse.m_Scene);
	M3DModel_Render(M3DLWLighthouse.m_Birds);
	M3DModel_Render(M3DLWLighthouse.m_Whale);
	
	IGV5Renderer_SetAlphaBlendMode(IGV5RS_ALPHA_ADD);
	M3DModel_Render(M3DLWLighthouse.m_Ray);

	IGV5Renderer_SetAlphaBlendMode(IGV5RS_ALPHA_COMPLEMENT);
	IGV5Renderer_SetZTestFunc(IGV5RS_ZTEST_ALWAYS);
	M3DModel_Render(M3DLWLighthouse.m_Ray2);
	IGV5Renderer_SetZTestFunc(IGV5RS_ZTEST_LEQUAL);
	
	M3DRenderer_Render(&M3DLWLighthouse.m_Renderer);

	m3d_time_update_FPS(&M3DLWLighthouse.m_adaption, &M3DLWLighthouse.m_Renderer.m_EngineRC.m_sPerformanceInfo);
}

void M3DLWLighthouse_ProcessTouch(int _mouseX, int _mouseY)
{
	//if (M3DModel_IsDefaultAnimation(M3DLWLighthouse.m_Obj[0]) == 1)
		//M3DModel_SetAnimation(M3DLWLighthouse.m_Obj[0], m3d_adaption_rand() % 5);
}

static int M3DLWLighthouse_DrawReflectionModels(struct IGV5SkyBoxType *pSkyBox,IGV5Matrix *pView, IGV5Matrix *pProjection)
{
	return 0;
}

#ifdef __cplusplus
}
#endif

/* end of M3DLWLighthouse.c */

