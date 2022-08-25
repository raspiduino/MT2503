//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWFish
// File        : M3DLWFish.c
// Description : IGV5 LW Fish
// Author      : Ray
// Create      : 2011-08-24
// Update      : 2012-01-01
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWFish.h"
#include "M3DTextureManager.h"
#include "M3DEventQueue.h"

#ifdef __cplusplus
extern "C" {
#endif

M3DLWFishApp M3DLWFish = {0};

//================== Interface Begin =========================
int M3DLWFish_OnStartup(void *_pc)
{
	M3DConfig *PC = (M3DConfig *)_pc;
	int ret = 1;

	m3d_adaption_init(&M3DLWFish.m_adaption, _pc);
	PC->m_pMemBuffer = m3d_alloc_engine_memory(&M3DLWFish.m_adaption, PC->m_MemSize);

	ret = M3DRenderer_Init(&M3DLWFish.m_Renderer, PC);
	M3DModel_InitStock();

	M3DLWFish_Init();
	m3d_time_resume(&M3DLWFish.m_adaption);

	return ret;
}

void M3DLWFish_OnShutdown(void)
{
	M3DLWFish_Release();
	M3DRenderer_Del(&M3DLWFish.m_Renderer);
	m3d_free_engine_memory(&M3DLWFish.m_adaption);
}

void M3DLWFish_OnResume(void)
{
	m3d_time_resume(&M3DLWFish.m_adaption);
}

void M3DLWFish_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2)
{
	unsigned long Time = _Time;

	if (M3DLWFish.m_GameTime < IGLW_FISH_DELAY_TIME)
		return;

	if (Time == 0L)
		Time = (long) M3DLWFish.m_GameTime;
	M3DEventQueue_PostEvent(M3DLWFish.m_EventMemPool, M3DLWFish.m_Event, _Id, Time, _Data1, _Data2);
}

static M3DEvent *pSE = NULL;

void M3DLWFish_OnUpdate(int isSuspend)
{
	static int MouseY = 0;

	if (M3DLWFish.m_Event == NULL)
		return;

	M3DLWFish.m_ElapsedTime = m3d_time_get_elapsed(&M3DLWFish.m_adaption);
	M3DLWFish.m_ElapsedTime = (float) (M3DLWFish.m_ElapsedTime * M3DLWFish.m_TimeFactor);

    if (isSuspend)
    {
        M3DLWFish.m_ElapsedTime = 0L;
    }
#if defined(M3D_DEBUG_FRAME)
	M3DLWFish.m_ElapsedTime = 10L;	//for debug
#endif

	M3DLWFish.m_GameTime = M3DLWFish.m_GameTime + M3DLWFish.m_ElapsedTime;

	while ((pSE = (M3DEvent *) M3DQueue_Pop(M3DLWFish.m_Event)) != NULL)
	{
		unsigned mem_used = M3DRenderer_GetUsedMemory(&M3DLWFish.m_Renderer);

		//remove all event
		if (M3DLWFish.m_GameTime < IGLW_FISH_DELAY_TIME)
		{
			M3DEventQueue_Free(M3DLWFish.m_EventMemPool, pSE);
			continue;
		}

		switch (pSE->m_uEventID)
		{
		case IGV5EID_BEGINTOUCH :
			M3DRotateCenter_SetTouch(&M3DLWFish.m_RotateCamera, 1);
			M3DRotateCenter_SetTouch(&M3DLWFish.m_VerticalCamera, 1);
			MouseY = pSE->m_uData2;
			break;
		case IGV5EID_TOUCH :
			M3DRotateCenter_MoveByPixel(&M3DLWFish.m_VerticalCamera, (signed)pSE->m_uData2 - MouseY, -1.0);
			MouseY = pSE->m_uData2;
			break;
		case IGV5EID_ENDTOUCH :
			{
				int bTouchMove = M3DRotateCenter_GetTouchMove(&M3DLWFish.m_VerticalCamera);
				if (bTouchMove == 1 || M3DLWFish.m_Page.m_Status == 1)
					M3DLWPage_SetStatus(&M3DLWFish.m_Page, 0);
				else
					M3DLWFish_ProcessTouch(pSE->m_uData1, pSE->m_uData2);
				M3DRotateCenter_SetTouch(&M3DLWFish.m_RotateCamera, 0);
				M3DRotateCenter_SetTouch(&M3DLWFish.m_VerticalCamera, 0);
			}
			MouseY = pSE->m_uData2;
 			break;
		case  IGV5EID_LWBOUNDSCHANGED :
			M3DLWPage_Changed(&M3DLWFish.m_Page, pSE->m_uData1);
			break;
		}

		M3DEventQueue_Free(M3DLWFish.m_EventMemPool, pSE);
	}

	if (M3DLWFish.m_GameTime > IGLW_2D_DELAY_TIME && M3DLWFish.m_Scene->m_bLoaded == 0)
		M3DLWFish_Init2();

	if (M3DLWFish.m_GameTime <= IGLW_2D_DELAY_TIME)
		M3DRenderer_Render2D(&M3DLWFish.m_Renderer, "bg2d.pvr");
	else
		M3DLWFish_Update();
}

//================== Interface End ===========================
int M3DLWFish_Init(void)
{
	M3DLWFish.m_Scene = M3DModel_New(&M3DLWFish.m_Renderer, "scene");
	M3DLWFish.m_Coral = M3DModel_New(&M3DLWFish.m_Renderer, "coral");
	M3DLWFish.m_Fish1 = M3DModel_New(&M3DLWFish.m_Renderer, "fish1");
	M3DLWFish.m_Fish2 = M3DModel_New(&M3DLWFish.m_Renderer, "fish2");
	M3DLWFish.m_Bubble   = M3DModel_New(&M3DLWFish.m_Renderer, "bubble");
	M3DLWFish.m_Bubble_b = M3DModel_New(&M3DLWFish.m_Renderer, "bubble_b");
	M3DLWFish.m_Bubble_c = M3DModel_New(&M3DLWFish.m_Renderer, "bubble_c");
	M3DLWFish.m_BubbleTouch   = M3DModel_New(&M3DLWFish.m_Renderer, "bubble2");
	M3DLWFish.m_BubbleTouch_b = M3DModel_New(&M3DLWFish.m_Renderer, "bubble2_b");
	M3DLWFish.m_BubbleTouch_c = M3DModel_New(&M3DLWFish.m_Renderer, "bubble2_c");

	M3DLWFish.m_SceneTextureNames  = NULL;
	M3DLWFish.m_CoralTextureNames  = NULL;
	M3DLWFish.m_Fish1TextureNames  = NULL;
	M3DLWFish.m_Fish2TextureNames  = NULL;
	M3DLWFish.m_BubbleTextureNames = NULL;

	M3DLWFish.m_BubbleDummy = NULL;

	M3DLWFish_LoadBackground2D();

	M3DLWFish.m_EventMemPool = M3DEventQueue_New(MAX_ARRAY_POOL);
	M3DLWFish.m_Event = M3DQueue_New(DEFAULT_QUEUE_SIZE);
	M3DLWFish.m_TimeFactor = 1.0f;
	M3DLWFish.m_GameTime = 0L;
	M3DLWFish.m_GameTime_DelayLoad = IGLW_FISH_DELAY_TIME;

	return 1;
}

int M3DLWFish_Init2(void)
{
	M3DLWFish_RemoveBackground2D();

	M3DLWFish.m_BubbleDummy = M3DDummyGroup_New(&M3DLWFish.m_Renderer);

	M3DLWFish_LoadContent();
	M3DRotateCenter_Init2(&M3DLWFish.m_VerticalCamera, -70.0f, 20.0f);
	M3DRotateCenter_InitPager(&M3DLWFish.m_RotateCamera, &M3DLWFish.m_Page, -180.0f, 180.0f);

	M3DModel_SetActiveCamera(M3DLWFish.m_Scene);
	M3DModel_SetActiveLight(M3DLWFish.m_Scene);

	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWFish.m_Renderer, M3D_TEXTURE_SHADER, 0.2f);
	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWFish.m_Renderer, M3D_GOURAUD_SHADOW_SHADER, 0.2f);
	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWFish.m_Renderer, M3D_SKINNING_GOURAUD_SHADER, 0.2f);
	M3DRenderer_SetAlphaTestCmpValue(&M3DLWFish.m_Renderer, 0.2f);

	//IGV5TextureShader_SetAlphaThreshold(M3DLWFish.textureShader, 0.2f);
	//IGV5GouraudShadowShader_SetAlphaThreshold(M3DLWFish.gouraudShadowShader, 0.2f);
	//IGV5SkinningGouraudShader_SetAlphaThreshold(M3DLWFish.skinningGouraudShader, 0.2f);
	
	M3DLWPage_Init(&M3DLWFish.m_Page, M3DLWFish.m_Renderer.m_EngineRC.m_sEGLInfo.m_uWidth, 5);

	return 1;
}

void M3DLWFish_Release(void)
{
	M3DEventQueue_ClearPendingEvents(M3DLWFish.m_EventMemPool, M3DLWFish.m_Event);
	M3DEventQueue_Del(M3DLWFish.m_EventMemPool);
	M3DLWFish.m_EventMemPool = NULL;
	M3DQueue_Del(M3DLWFish.m_Event);
	M3DLWFish.m_Event = NULL;
	M3DLWFish.m_GameTime = 0L;

	//IGV5TextureShader_Release(&M3DLWFish.textureShader);
	//IGV5GouraudShadowShader_Release(&M3DLWFish.gouraudShadowShader);
	//IGV5SkinningGouraudShader_Release(&M3DLWFish.skinningGouraudShader);

	M3DDummyGroup_Del(M3DLWFish.m_BubbleDummy);

	M3DSplitString_Del(M3DLWFish.m_BubbleTextureNames);
	M3DSplitString_Del(M3DLWFish.m_Fish2TextureNames);
	M3DSplitString_Del(M3DLWFish.m_Fish1TextureNames);
	M3DSplitString_Del(M3DLWFish.m_CoralTextureNames);
	M3DSplitString_Del(M3DLWFish.m_SceneTextureNames);

	M3DModel_Del(M3DLWFish.m_BubbleTouch_c);
	M3DModel_Del(M3DLWFish.m_BubbleTouch_b);
	M3DModel_Del(M3DLWFish.m_BubbleTouch);
	M3DModel_Del(M3DLWFish.m_Bubble_c);
	M3DModel_Del(M3DLWFish.m_Bubble_b);
	M3DModel_Del(M3DLWFish.m_Bubble);
	M3DModel_Del(M3DLWFish.m_Fish2);
	M3DModel_Del(M3DLWFish.m_Fish1);
	M3DModel_Del(M3DLWFish.m_Coral);
	M3DModel_Del(M3DLWFish.m_Scene);
}

void M3DLWFish_Update(void)
{
	if (M3DLWFish.m_Fish1->m_bLoaded == 0 && M3DLWFish.m_GameTime > M3DLWFish.m_GameTime_DelayLoad)
	{
		M3DLWFish_LoadContent2();
		M3DModel_SetShadow(M3DLWFish.m_Fish1);
		M3DModel_SetShadow(M3DLWFish.m_Fish2);
		M3DLWPage_Changed(&M3DLWFish.m_Page, m3d_adaption_get_pageX());
	}

	M3DModel_AnimateLoop(M3DLWFish.m_Scene, M3DLWFish.m_ElapsedTime, 0);
	M3DModel_AnimateLoop(M3DLWFish.m_Coral, M3DLWFish.m_ElapsedTime, 0);
	M3DModel_AnimateLoop(M3DLWFish.m_Fish1, M3DLWFish.m_ElapsedTime, 0);
	M3DModel_AnimateLoop(M3DLWFish.m_Fish2, M3DLWFish.m_ElapsedTime, 0);
	M3DModel_AnimateLoop(M3DLWFish.m_Bubble, M3DLWFish.m_ElapsedTime, 0);
	M3DModel_AnimateLoop(M3DLWFish.m_Bubble_b, M3DLWFish.m_ElapsedTime, 0);
	M3DModel_AnimateLoop(M3DLWFish.m_Bubble_c, M3DLWFish.m_ElapsedTime, 0);
	M3DModel_AnimateOnce(M3DLWFish.m_BubbleTouch,   M3DLWFish.m_ElapsedTime);
	M3DModel_AnimateOnce(M3DLWFish.m_BubbleTouch_b, M3DLWFish.m_ElapsedTime);
	M3DModel_AnimateOnce(M3DLWFish.m_BubbleTouch_c, M3DLWFish.m_ElapsedTime);

	M3DModel_FaceToCameraByXZ(M3DLWFish.m_Bubble,   "Bubble_dummy01");
	M3DModel_FaceToCameraByXZ(M3DLWFish.m_Bubble_b, "Bubble_dummy01");
	M3DModel_FaceToCameraByXZ(M3DLWFish.m_Bubble_c, "Bubble_dummy01");
	M3DModel_FaceToCameraByXZ(M3DLWFish.m_BubbleTouch,   "Bubble_dummy01");
	M3DModel_FaceToCameraByXZ(M3DLWFish.m_BubbleTouch_b, "Bubble_dummy01");
	M3DModel_FaceToCameraByXZ(M3DLWFish.m_BubbleTouch_c, "Bubble_dummy01");
	M3DDummyGroup_Animate(M3DLWFish.m_BubbleDummy, M3DLWFish.m_ElapsedTime);
	if (M3DLWFish.m_Bubble->m_Time < 500.0f)
	{
		M3DModel_SetTime(M3DLWFish.m_Bubble_b, 0.0f);
		M3DModel_SetNodeBeside(M3DLWFish.m_Bubble_b, "Bubble_dummy01", M3DLWFish.m_Bubble, "Bubble_dummy01", -5);
	}
	if (M3DLWFish.m_Bubble->m_Time < 500.0f)
	{
		M3DModel_SetTime(M3DLWFish.m_Bubble_c, 0.0f);
		M3DModel_SetNodeBeside(M3DLWFish.m_Bubble_c, "Bubble_dummy01", M3DLWFish.m_Bubble, "Bubble_dummy01", -10);
	}

	M3DRenderer_SetCameraRotation(&M3DLWFish.m_Renderer, M3DRotateCenter_Update(&M3DLWFish.m_VerticalCamera, M3DLWFish.m_ElapsedTime));
	M3DRenderer_UpdateVerticalCameraRotation(&M3DLWFish.m_Renderer);
	M3DRenderer_SetCameraRotation(&M3DLWFish.m_Renderer, M3DRotateCenter_UpdatePageX(&M3DLWFish.m_RotateCamera, M3DLWFish.m_ElapsedTime));
	M3DRenderer_UpdateCameraRotation(&M3DLWFish.m_Renderer);

	M3DRenderer_PrepareRender(&M3DLWFish.m_Renderer);
	M3DRenderer_PrepareShadow(&M3DLWFish.m_Renderer);
	
	M3DModel_Render(M3DLWFish.m_Bubble); //CY begin
	M3DModel_Render(M3DLWFish.m_Bubble_b);
	M3DModel_Render(M3DLWFish.m_Bubble_c);
	M3DModel_Render(M3DLWFish.m_BubbleTouch);
	M3DModel_RenderWithShadow(M3DLWFish.m_Scene);  //CY end
	M3DModel_RenderWithShadow(M3DLWFish.m_Coral);
	M3DModel_Render(M3DLWFish.m_Fish1);
	M3DModel_Render(M3DLWFish.m_Fish2);	

	M3DRenderer_Render(&M3DLWFish.m_Renderer);
	M3DRenderer_ReleaseShadow(&M3DLWFish.m_Renderer);

	/* calculate FPS */
	m3d_time_update_FPS(&M3DLWFish.m_adaption, &M3DLWFish.m_Renderer.m_EngineRC.m_sPerformanceInfo);
}

void M3DLWFish_ProcessTouch(int _mouseX, int _mouseY)
{
	int	idx = 0;
	idx = m3d_adaption_rand() % M3DLWFish.m_BubbleDummy->m_iTotalDummy;
	M3DModel_SetNodePosition(M3DLWFish.m_BubbleTouch, "Bubble_dummy01", &M3DLWFish.m_BubbleDummy->m_DummyMeshPosition[idx]);
	M3DModel_AnimateStart(M3DLWFish.m_BubbleTouch);
	M3DModel_SetTime(M3DLWFish.m_BubbleTouch, 1000L);

	idx = m3d_adaption_rand() % M3DLWFish.m_BubbleDummy->m_iTotalDummy;
	M3DModel_SetNodePosition(M3DLWFish.m_BubbleTouch_b, "Bubble_dummy01", &M3DLWFish.m_BubbleDummy->m_DummyMeshPosition[idx]);
	M3DModel_AnimateStart(M3DLWFish.m_BubbleTouch_b);
	M3DModel_SetTime(M3DLWFish.m_BubbleTouch_b, 1300L);

	idx = m3d_adaption_rand() % M3DLWFish.m_BubbleDummy->m_iTotalDummy;
	M3DModel_SetNodePosition(M3DLWFish.m_BubbleTouch_c, "Bubble_dummy01", &M3DLWFish.m_BubbleDummy->m_DummyMeshPosition[idx]);
	M3DModel_AnimateStart(M3DLWFish.m_BubbleTouch_c);
	M3DModel_SetTime(M3DLWFish.m_BubbleTouch_c, 1500L);
}

#ifdef __cplusplus
}
#endif

/* end of M3DLWFish.c */

