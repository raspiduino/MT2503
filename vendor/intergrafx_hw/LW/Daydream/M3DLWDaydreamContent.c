//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWDaydream
// File        : M3DLWDaydreamContent.c
// Description : IGV5 LW Daydream
// Author      : Ray
// Create      : 2011-09-18
// Update      : 2011-12-22
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWDaydream.h"
#include "M3DTextureManager.h"

#if defined(__MMI_MAINLCD_240X320__)
#include "pvr_daydream_240x320.h"
#elif defined(__MMI_MAINLCD_240X400__)
#include "pvr_daydream_240x400.h"
#elif defined(__MMI_MAINLCD_320X480__)
#include "pvr_daydream_320x480.h"
#elif defined(__MMI_MAINLCD_480X800__)
#include "pvr_daydream_480x800.h"
#else
#include "pvr_daydream_320x480.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern M3DLWDaydreamApp M3DLWDaydream;

extern unsigned char const pod_daydream01[];
extern unsigned char const pod_daydream02[];
extern unsigned char const pod_daydream03[];
extern unsigned char const pod_daydream04[];
extern long pod_daydream01_length;
extern long pod_daydream02_length;
extern long pod_daydream03_length;
extern long pod_daydream04_length;

extern unsigned char const pvr_daydream01[];
extern unsigned char const pvr_daydream02[];
extern unsigned char const pvr_daydream03[];
extern unsigned char const pvr_daydream03a[];
extern unsigned char const pvr_daydream04[];
extern unsigned char const pvr_daydream04a[];
extern unsigned char const pvr_daydream05[];
extern unsigned char const pvr_daydream05a[];
extern unsigned char const pvr_daydream06[];
extern unsigned char const pvr_daydream07[];

extern unsigned char const pvr_daydream_background2d[];

void M3DLWDaydream_LoadBackground2D(void)
{
	M3DTextureCollection_AddFromMem(&M3DLWDaydream.m_Renderer.m_TextureCollection, "bg2d.pvr",          pvr_daydream_background2d);
}

void M3DLWDaydream_RemoveBackground2D(void)
{
	M3DTextureCollection_Remove(&M3DLWDaydream.m_Renderer.m_TextureCollection, "bg2d.pvr");
}

int M3DLWDaydream_LoadContent(void)
{
	M3DLWDaydream.m_SceneTextureNames = M3DSplitString_New("Sky.pvr,100.pvr;");
	M3DLWDaydream.m_CloudTextureNames = M3DSplitString_New("Cloud1.pvr;");
	M3DLWDaydream.m_PlaneTextureNames = M3DSplitString_New("Plain02.pvr,Logo.pvr;");
	M3DLWDaydream.m_CashTextureNames  = M3DSplitString_New("Cash_01.pvr;");

	//M3DTextureCollection_AddFromMem(&M3DLWDaydream.m_Renderer.m_TextureCollection, "Cash_01.pvr",        pvr_daydream01);
	//M3DTextureCollection_AddFromMem(&M3DLWDaydream.m_Renderer.m_TextureCollection, "Cash_02.pvr",        pvr_daydream02);
	M3DTextureCollection_AddFromMem(&M3DLWDaydream.m_Renderer.m_TextureCollection, "100.pvr",            pvr_daydream03);
	M3DTextureCollection_AddFromMem(&M3DLWDaydream.m_Renderer.m_TextureCollection, "100_a.pvr",          pvr_daydream03a);
	M3DTextureCollection_AddFromMem(&M3DLWDaydream.m_Renderer.m_TextureCollection, "Cloud1.pvr",         pvr_daydream04);
	M3DTextureCollection_AddFromMem(&M3DLWDaydream.m_Renderer.m_TextureCollection, "Cloud1_a.pvr",       pvr_daydream04a);
	//M3DTextureCollection_AddFromMem(&M3DLWDaydream.m_Renderer.m_TextureCollection, "Logo.pvr",           pvr_daydream05);
	//M3DTextureCollection_AddFromMem(&M3DLWDaydream.m_Renderer.m_TextureCollection, "Logo_a.pvr",         pvr_daydream05a);
	//M3DTextureCollection_AddFromMem(&M3DLWDaydream.m_Renderer.m_TextureCollection, "Plain02.pvr",        pvr_daydream06);
	M3DTextureCollection_AddFromMem(&M3DLWDaydream.m_Renderer.m_TextureCollection, "Sky.pvr",            pvr_daydream07);

	M3DTextureCollection_Map(&M3DLWDaydream.m_Renderer.m_TextureCollection, "100.pvr",      NULL,        "100_a.pvr");
	M3DTextureCollection_Map(&M3DLWDaydream.m_Renderer.m_TextureCollection, "Cloud1.pvr",   NULL,        "Cloud1_a.pvr");
	//M3DTextureCollection_Map(&M3DLWDaydream.m_Renderer.m_TextureCollection, "Logo.pvr",     NULL,        "Logo_a.pvr");

	M3DTextureCollection_AddUVAnim(&M3DLWDaydream.m_Renderer.m_TextureCollection, "Cloud1.pvr");
	M3DTextureCollection_SetUVAnimTimeFactor(&M3DLWDaydream.m_Renderer.m_TextureCollection, 0.5f, 0.0f);

	M3DModel_Load(M3DLWDaydream.m_Scene, pod_daydream01, pod_daydream01_length, M3DLWDaydream.m_SceneTextureNames);
	M3DModel_Load(M3DLWDaydream.m_Cloud, pod_daydream02, pod_daydream02_length, M3DLWDaydream.m_CloudTextureNames);

	M3DModel_SetShaderProgram(M3DLWDaydream.m_Cloud, M3D_UV_DISPLACEMENT_SHADER, M3D_NULL_SHADER);

	return 1;
}

void M3DLWDaydream_LoadContent2(void)
{
	M3DTextureCollection_AddFromMem(&M3DLWDaydream.m_Renderer.m_TextureCollection, "Cash_01.pvr",        pvr_daydream01);

#if defined(IGLW_DAYDREAM_CHANGE_TEXTURE)
	M3DTextureCollection_AddFromMem(&M3DLWDaydream.m_Renderer.m_TextureCollection, "Cash_02.pvr",        pvr_daydream02);
#endif

	M3DTextureCollection_AddFromMem(&M3DLWDaydream.m_Renderer.m_TextureCollection, "Logo.pvr",           pvr_daydream05);
	M3DTextureCollection_AddFromMem(&M3DLWDaydream.m_Renderer.m_TextureCollection, "Logo_a.pvr",         pvr_daydream05a);
	M3DTextureCollection_AddFromMem(&M3DLWDaydream.m_Renderer.m_TextureCollection, "Plain02.pvr",        pvr_daydream06);

	M3DTextureCollection_Map(&M3DLWDaydream.m_Renderer.m_TextureCollection, "Logo.pvr",     NULL,        "Logo_a.pvr");

	M3DModel_Load(M3DLWDaydream.m_Plane, pod_daydream03, pod_daydream03_length, M3DLWDaydream.m_PlaneTextureNames);
	M3DModel_Load(M3DLWDaydream.m_Cash, pod_daydream04, pod_daydream04_length, M3DLWDaydream.m_CashTextureNames);

	M3DModel_SetShaderProgram(M3DLWDaydream.m_Plane, M3D_TEXTURE_SHADER, M3D_SKINNING_TEXTURE_SHADER); //CY
	M3DModel_SetShaderProgram(M3DLWDaydream.m_Cash, M3D_GOURAUD_SHADER, M3D_SKINNING_GOURAUD_SHADER);

	M3DModel_AddAnimationByFrame(M3DLWDaydream.m_Plane, "ANIMATE0",   0, 140, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWDaydream.m_Plane, "ANIMATE1", 160, 280, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWDaydream.m_Plane, "ANIMATE2", 290, 430, 1.0f);
	//M3DModel_InitAnimationEven(M3DLWDaydream.m_Plane, "9000,1000,9000,1000,9000;");
	//M3DAniInfo_Add(&M3DLWDaydream.m_Cash->m_AniInfo, "init", 6500, 8000);

	//M3DModel_SetDefaultAnimation(M3DLWDaydream.m_Cash, 0, 0.1f);
	//M3DModel_SetAnimationByName(M3DLWDaydream.m_Cash, "init");
}
#ifdef __cplusplus
}
#endif

/* end of M3DLWDaydream.c */

