//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWGirl
// File        : M3DLWGirlContent.c
// Description : IGV5 LW Girl
// Author      : Ray
// Create      : 2011-08-25
// Update      : 2011-12-22
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWGirl.h"
#include "M3DTextureManager.h"

#if defined(__MMI_MAINLCD_240X320__)
#include "pvr_girl_240x320.h"
#elif defined(__MMI_MAINLCD_240X400__)
#include "pvr_girl_240x400.h"
#elif defined(__MMI_MAINLCD_320X480__)
#include "pvr_girl_320x480.h"
#elif defined(__MMI_MAINLCD_480X800__)
#include "pvr_girl_480x800.h"
#else
#include "pvr_girl_320x480.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern M3DLWGirlApp M3DLWGirl;

extern unsigned char const pod_girl01[];
extern unsigned char const pod_girl02[];
extern unsigned char const pod_girl03[];
extern long pod_girl01_length;
extern long pod_girl02_length;
extern long pod_girl03_length;

extern unsigned char const pvr_girl01[];
extern unsigned char const pvr_girl02[];
extern unsigned char const pvr_girl03[];
extern unsigned char const pvr_girl04[];
extern unsigned char const pvr_girl05[];
extern unsigned char const pvr_girl06[];
extern unsigned char const pvr_girl07[];
extern unsigned char const pvr_girl07a[];
extern unsigned char const pvr_girl08[];
extern unsigned char const pvr_girl08a[];

extern unsigned char const pvr_girl_background2d[];

void M3DLWGirl_LoadBackground2D(void)
{
	M3DTextureCollection_AddFromMem(&M3DLWGirl.m_Renderer.m_TextureCollection, "bg2d.pvr",          pvr_girl_background2d);
}

void M3DLWGirl_RemoveBackground2D(void)
{
	M3DTextureCollection_Remove(&M3DLWGirl.m_Renderer.m_TextureCollection, "bg2d.pvr");
}

int M3DLWGirl_LoadContent(void)
{
	m3d_adaption_before_load1();
	M3DLWGirl.m_SceneTextureNames = M3DSplitString_New("Bg.pvr;");
	M3DLWGirl.m_GirlTextureNames  = M3DSplitString_New("Body.pvr,face.pvr,Flower.pvr,Hair_all.pvr;");

	m3d_adaption_before_pvr();
	M3DTextureCollection_AddFromMem(&M3DLWGirl.m_Renderer.m_TextureCollection, "Bg.pvr",          pvr_girl01);
	m3d_adaption_after_pvr();

	if (M3DLWGirl.m_Renderer.m_EngineRC.m_sEGLInfo.m_uHeight == 800)
		M3DModel_Load(M3DLWGirl.m_Scene, pod_girl01, pod_girl01_length, M3DLWGirl.m_SceneTextureNames);
	else
		M3DModel_Load(M3DLWGirl.m_Scene, pod_girl02, pod_girl02_length, M3DLWGirl.m_SceneTextureNames);

	M3DModel_SetShaderProgram(M3DLWGirl.m_Scene, M3D_GOURAUD_SHADOW_SHADER, M3D_NULL_SHADER);

	m3d_adaption_after_load1();
	M3DLWGirl.m_Renderer.m_LoadState = 1;

	return 1;
}

void M3DLWGirl_LoadContent2(void)
{
	m3d_adaption_before_load2();
	M3DTextureCollection_AddFromMem(&M3DLWGirl.m_Renderer.m_TextureCollection, "Body.pvr",           pvr_girl05);
	M3DTextureCollection_AddFromMem(&M3DLWGirl.m_Renderer.m_TextureCollection, "face.pvr",           pvr_girl06);
	M3DTextureCollection_AddFromMem(&M3DLWGirl.m_Renderer.m_TextureCollection, "Flower.pvr",         pvr_girl07);
	M3DTextureCollection_AddFromMem(&M3DLWGirl.m_Renderer.m_TextureCollection, "Flower_a.pvr",       pvr_girl07a);
	M3DTextureCollection_AddFromMem(&M3DLWGirl.m_Renderer.m_TextureCollection, "Hair_all.pvr",       pvr_girl08);
	M3DTextureCollection_AddFromMem(&M3DLWGirl.m_Renderer.m_TextureCollection, "Hair_all_a.pvr",     pvr_girl08a);

	M3DTextureCollection_Map(&M3DLWGirl.m_Renderer.m_TextureCollection, "Flower.pvr",    NULL,        "Flower_a.pvr");
	M3DTextureCollection_Map(&M3DLWGirl.m_Renderer.m_TextureCollection, "Hair_all.pvr",  NULL,        "Hair_all_a.pvr");

	M3DModel_Load(M3DLWGirl.m_Girl, pod_girl03, pod_girl03_length, M3DLWGirl.m_GirlTextureNames);
	M3DModel_EnableNode(M3DLWGirl.m_Girl, "Box01", 0);

	M3DModel_SetShaderProgram(M3DLWGirl.m_Girl, M3D_NULL_SHADER, M3D_SKINNING_GOURAUD_SHADER);

	M3DModel_AddAnimationByFrame(M3DLWGirl.m_Girl, "ANIMATE0",   3,  48, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWGirl.m_Girl, "ANIMATE1",  52, 141, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWGirl.m_Girl, "ANIMATE2", 243, 300, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWGirl.m_Girl, "ANIMATE3", 303, 340, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWGirl.m_Girl, "ANIMATE4", 345, 375, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWGirl.m_Girl, "ANIMATE5", 380, 432, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWGirl.m_Girl, "init",     146, 240, 1.0f);

	//M3DModel_InitAnimationEven(M3DLWGirl.m_Girl, "0,34,500,33,1000,34,1067,67,600,33,400,100,300,67,200,67,300;");
	//M3DAniInfo_Add(&M3DLWGirl.m_Girl->m_AniInfo, "init", 1600, 2667);

	//M3DModel_SetDefaultAnimation(M3DLWGirl.m_Girl, 1, 1.0f);
	M3DModel_SetAnimationByName(M3DLWGirl.m_Girl, "init");
	m3d_adaption_after_load2();

	M3DLWGirl.m_Renderer.m_LoadState = 2;
}
#ifdef __cplusplus
}
#endif

/* end of M3DLWGirl.c */

