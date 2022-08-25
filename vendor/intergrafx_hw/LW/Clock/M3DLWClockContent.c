//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWClock
// File        : M3DLWClockContent.c
// Description : IGV5 LW Clock
// Author      : Ray
// Create      : 2011-08-25
// Update      : 2012-01-16
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWClock.h"
#include "M3DTextureManager.h"

#if defined(__MMI_MAINLCD_240X320__)
#include "pvr_clock_240x320.h"
#elif defined(__MMI_MAINLCD_240X400__)
#include "pvr_clock_240x400.h"
#elif defined(__MMI_MAINLCD_320X480__)
#include "pvr_clock_320x480.h"
#elif defined(__MMI_MAINLCD_480X800__)
#include "pvr_clock_480x800.h"
#else
#include "pvr_clock_320x480.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern M3DLWClockApp M3DLWClock;

extern unsigned char const pod_clock01[];
//extern unsigned char const pod_clock02[];
extern unsigned char const pod_clock03[];
extern unsigned char const pod_clock04[];
extern unsigned char const pod_clock05[];
extern unsigned char const pod_clock06[];
extern long pod_clock01_length;
//extern long pod_clock02_length;
extern long pod_clock03_length;
extern long pod_clock04_length;
extern long pod_clock05_length;
extern long pod_clock06_length;

extern unsigned char const pvr_clock01[];
extern unsigned char const pvr_clock02[];
extern unsigned char const pvr_clock03[];
extern unsigned char const pvr_clock04[];
extern unsigned char const pvr_clock05[];
extern unsigned char const pvr_clock05a[];
extern unsigned char const pvr_clock06[];
extern unsigned char const pvr_clock06a[];
extern unsigned char const pvr_clock07[];
extern unsigned char const pvr_clock08[];
extern unsigned char const pvr_clock08a[];
extern unsigned char const pvr_clock09[];
extern unsigned char const pvr_clock10[];
extern unsigned char const pvr_clock10a[];

extern long pvr_clock01_length;
extern long pvr_clock02_length;
extern long pvr_clock03_length;
extern long pvr_clock04_length;
extern long pvr_clock05_length;
extern long pvr_clock05a_length;
extern long pvr_clock06_length;
extern long pvr_clock06a_length;
extern long pvr_clock07_length;
extern long pvr_clock08_length;
extern long pvr_clock08a_length;
extern long pvr_clock09_length;
extern long pvr_clock10_length;
extern long pvr_clock10a_length;

extern unsigned char const pvr_clock_background2d[];

void M3DLWClock_LoadBackground2D(void)
{
	M3DTextureCollection_AddFromMem(&M3DLWClock.m_Renderer.m_TextureCollection, "bg2d.pvr",          pvr_clock_background2d);
}

void M3DLWClock_RemoveBackground2D(void)
{
	M3DTextureCollection_Remove(&M3DLWClock.m_Renderer.m_TextureCollection, "bg2d.pvr");
}

int M3DLWClock_LoadContent(void)
{
	M3DLWClock.m_SceneTextureNames = M3DSplitString_New("bg01.pvr,no.pvr,metal.pvr,goldwheel02.pvr,buttom.pvr;");
	M3DLWClock.m_FaceTextureNames  = M3DSplitString_New("face01.pvr,scene.pvr,metal.pvr;");
	M3DLWClock.m_GearTextureNames  = M3DSplitString_New("WP2_3_01.pvr,WP2_2_01.pvr;");
	M3DLWClock.m_Gear2TextureNames = M3DSplitString_New("WP2_2_01.pvr;");
	M3DLWClock.m_HandTextureNames  = M3DSplitString_New("P2-06_01.pvr;");

	M3DTextureCollection_AddFromMem(&M3DLWClock.m_Renderer.m_TextureCollection, "bg01.pvr",           pvr_clock01);
	M3DTextureCollection_AddFromMem(&M3DLWClock.m_Renderer.m_TextureCollection, "buttom.pvr",         pvr_clock02);
	M3DTextureCollection_AddFromMem(&M3DLWClock.m_Renderer.m_TextureCollection, "face01.pvr",         pvr_clock03);
	M3DTextureCollection_AddFromMem(&M3DLWClock.m_Renderer.m_TextureCollection, "goldwheel02.pvr",    pvr_clock04);
	M3DTextureCollection_AddFromMem(&M3DLWClock.m_Renderer.m_TextureCollection, "metal.pvr",          pvr_clock05);
	M3DTextureCollection_AddFromMem(&M3DLWClock.m_Renderer.m_TextureCollection, "metal_a.pvr",        pvr_clock05a);
	M3DTextureCollection_AddFromMem(&M3DLWClock.m_Renderer.m_TextureCollection, "no.pvr",             pvr_clock06);
	M3DTextureCollection_AddFromMem(&M3DLWClock.m_Renderer.m_TextureCollection, "no_a.pvr",           pvr_clock06a);
	M3DTextureCollection_AddFromMem(&M3DLWClock.m_Renderer.m_TextureCollection, "P2-06_01.pvr",       pvr_clock07);
	M3DTextureCollection_AddFromMem(&M3DLWClock.m_Renderer.m_TextureCollection, "scene.pvr",          pvr_clock08);
	M3DTextureCollection_AddFromMem(&M3DLWClock.m_Renderer.m_TextureCollection, "scene_a.pvr",        pvr_clock08a);
	M3DTextureCollection_AddFromMem(&M3DLWClock.m_Renderer.m_TextureCollection, "WP2_2_01.pvr",       pvr_clock09);
	M3DTextureCollection_AddFromMem(&M3DLWClock.m_Renderer.m_TextureCollection, "WP2_3_01.pvr",       pvr_clock10);
	M3DTextureCollection_AddFromMem(&M3DLWClock.m_Renderer.m_TextureCollection, "WP2_3_01_a.pvr",     pvr_clock10a);

	M3DTextureCollection_Map(&M3DLWClock.m_Renderer.m_TextureCollection, "metal.pvr",   NULL,        "metal_a.pvr");
	M3DTextureCollection_Map(&M3DLWClock.m_Renderer.m_TextureCollection, "no.pvr",      NULL,        "no_a.pvr");
	M3DTextureCollection_Map(&M3DLWClock.m_Renderer.m_TextureCollection, "scene.pvr",   NULL,        "scene_a.pvr");
	M3DTextureCollection_Map(&M3DLWClock.m_Renderer.m_TextureCollection, "WP2_3_01.pvr", NULL,       "WP2_3_01_a.pvr");

	//if (M3DLWClock.m_Renderer.m_EngineRC.m_sEGLInfo.m_uHeight == 800)
		M3DModel_Load(M3DLWClock.m_Scene, pod_clock01, pod_clock01_length, M3DLWClock.m_SceneTextureNames);
	//else
	//	M3DModel_Load(M3DLWClock.m_Scene, pod_clock02, pod_clock02_length, M3DLWClock.m_SceneTextureNames);
	M3DModel_Load(M3DLWClock.m_Face,  pod_clock03, pod_clock03_length, M3DLWClock.m_FaceTextureNames);
	M3DModel_Load(M3DLWClock.m_Gear,  pod_clock04, pod_clock04_length, M3DLWClock.m_GearTextureNames);
	M3DModel_Load(M3DLWClock.m_Hand,  pod_clock06, pod_clock06_length, M3DLWClock.m_HandTextureNames);

	M3DModel_SetShaderProgram(M3DLWClock.m_Scene, M3D_TEXTURE_SHADER, M3D_NULL_SHADER);
	M3DModel_SetShaderProgramByNodeName(M3DLWClock.m_Scene, "Surface", M3D_GOURAUD_SPECULAR_SHADER);  //CY
	M3DModel_SetShaderProgram(M3DLWClock.m_Face, M3D_TEXTURE_SHADER, M3D_NULL_SHADER);  //CY
	M3DModel_SetShaderProgram(M3DLWClock.m_Gear, M3D_GOURAUD_SHADER, M3D_NULL_SHADER);  //CY
	M3DModel_SetShaderProgram(M3DLWClock.m_Hand, M3D_TEXTURE_SHADER, M3D_NULL_SHADER);  //CY

	M3DModel_AddAnimationByFrame(M3DLWClock.m_Face, "ANIMATE0",   0, 100, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWClock.m_Face, "ANIMATE1",   0, 100, 1.0f);
	//M3DModel_AddAnimationByFrame(M3DLWClock.m_Face, "ANIMATE2", 130, 190, 1.0f);
        M3DModel_AddAnimationByFrame(M3DLWClock.m_Face, "ANIMATE2", 130, 181, 1.0f);
	M3DModel_SetAnimationStart(M3DLWClock.m_Face, 0);
	M3DModel_AnimateStop(M3DLWClock.m_Face);
	return 1;
}

void M3DLWClock_LoadContent2(void)
{
	M3DModel_Load(M3DLWClock.m_Gear2, pod_clock05, pod_clock05_length, M3DLWClock.m_Gear2TextureNames);
	M3DModel_SetShaderProgram(M3DLWClock.m_Gear2, M3D_GOURAUD_SHADER, M3D_NULL_SHADER); //CY
}

#ifdef __cplusplus
}
#endif

/* end of M3DLWClock.c */

