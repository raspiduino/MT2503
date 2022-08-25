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

#if defined(__MMI_MAINLCD_240X320__)
#include "pvr_puppy_240x320.h"
#elif defined(__MMI_MAINLCD_240X400__)
#include "pvr_puppy_240x400.h"
#elif defined(__MMI_MAINLCD_320X480__)
#include "pvr_puppy_320x480.h"
#elif defined(__MMI_MAINLCD_480X800__)
#include "pvr_puppy_480x800.h"
#else
#include "pvr_puppy_320x480.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern M3DLWPuppyApp M3DLWPuppy;

extern unsigned char const pod_puppy01[];
extern unsigned char const pod_puppy02[];
extern unsigned char const pod_puppy03[];
extern unsigned char const pod_puppy04[];
extern long pod_puppy01_length;
extern long pod_puppy02_length;
extern long pod_puppy03_length;
extern long pod_puppy04_length;

extern unsigned char const pvr_puppy01[];
extern unsigned char const pvr_puppy01a[];
extern unsigned char const pvr_puppy02[];
extern unsigned char const pvr_puppy03[];
extern unsigned char const pvr_puppy04[];
extern unsigned char const pvr_puppy04a[];
extern unsigned char const pvr_puppy05[];
extern unsigned char const pvr_puppy06[];
extern unsigned char const pvr_puppy06a[];
extern unsigned char const pvr_puppy07[];
extern unsigned char const pvr_puppy08[];

extern unsigned char const pvr_puppy_background2d[];

void M3DLWPuppy_LoadBackground2D(void)
{
	M3DTextureCollection_AddFromMem(&M3DLWPuppy.m_Renderer.m_TextureCollection, "bg2d.pvr",          pvr_puppy_background2d);
}

void M3DLWPuppy_RemoveBackground2D(void)
{
	M3DTextureCollection_Remove(&M3DLWPuppy.m_Renderer.m_TextureCollection, "bg2d.pvr");
}

int M3DLWPuppy_LoadContent(void)
{
	M3DLWPuppy.m_SceneTextureNames  = M3DSplitString_New("WP3-B-prop.pvr,WP3_B_Floor.pvr,WP3-B-Background.pvr,WP3_Background4.pvr;");
	M3DLWPuppy.m_CloudTextureNames  = M3DSplitString_New("WP3_Background3.pvr;");
	M3DLWPuppy.m_WindowTextureNames = M3DSplitString_New("Curtain.pvr;");
	M3DLWPuppy.m_DogTextureNames    = M3DSplitString_New("WP3-B-dog.pvr,WP3-B-prop.pvr,Symbol.pvr;");

	M3DTextureCollection_AddFromMem(&M3DLWPuppy.m_Renderer.m_TextureCollection, "Curtain.pvr",            pvr_puppy01);
	M3DTextureCollection_AddFromMem(&M3DLWPuppy.m_Renderer.m_TextureCollection, "Curtain_a.pvr",          pvr_puppy01a);
	//M3DTextureCollection_AddFromMem(&M3DLWPuppy.m_Renderer.m_TextureCollection, "Symbol.pvr",              pvr_puppy02);
	M3DTextureCollection_AddFromMem(&M3DLWPuppy.m_Renderer.m_TextureCollection, "WP3_B_Floor.pvr",        pvr_puppy03);
	M3DTextureCollection_AddFromMem(&M3DLWPuppy.m_Renderer.m_TextureCollection, "WP3_Background3.pvr",    pvr_puppy04);
	M3DTextureCollection_AddFromMem(&M3DLWPuppy.m_Renderer.m_TextureCollection, "WP3_Background3_a.pvr",  pvr_puppy04a);
	M3DTextureCollection_AddFromMem(&M3DLWPuppy.m_Renderer.m_TextureCollection, "WP3_Background4.pvr",    pvr_puppy05);
	M3DTextureCollection_AddFromMem(&M3DLWPuppy.m_Renderer.m_TextureCollection, "WP3-B-Background.pvr",   pvr_puppy06);
	M3DTextureCollection_AddFromMem(&M3DLWPuppy.m_Renderer.m_TextureCollection, "WP3-B-Background_a.pvr", pvr_puppy06a);
	//M3DTextureCollection_AddFromMem(&M3DLWPuppy.m_Renderer.m_TextureCollection, "WP3-B-dog.pvr",          pvr_puppy07);
	M3DTextureCollection_AddFromMem(&M3DLWPuppy.m_Renderer.m_TextureCollection, "WP3-B-prop.pvr",         pvr_puppy08);

	M3DTextureCollection_Map(&M3DLWPuppy.m_Renderer.m_TextureCollection, "Curtain.pvr",          NULL,                   "Curtain_a.pvr");
	M3DTextureCollection_Map(&M3DLWPuppy.m_Renderer.m_TextureCollection, "WP3_Background3.pvr",  NULL,                   "WP3_Background3_a.pvr");
	M3DTextureCollection_Map(&M3DLWPuppy.m_Renderer.m_TextureCollection, "WP3-B-Background.pvr", NULL,                   "WP3-B-Background_a.pvr");

	M3DTextureCollection_AddUVAnim(&M3DLWPuppy.m_Renderer.m_TextureCollection, "WP3_Background3.pvr");
	M3DTextureCollection_SetUVAnimTimeFactor(&M3DLWPuppy.m_Renderer.m_TextureCollection, 0.1f, 0.0f);

	M3DModel_Load(M3DLWPuppy.m_Scene,  pod_puppy01, pod_puppy01_length, M3DLWPuppy.m_SceneTextureNames);
	M3DModel_Load(M3DLWPuppy.m_Cloud,  pod_puppy02, pod_puppy02_length, M3DLWPuppy.m_CloudTextureNames);
	M3DModel_Load(M3DLWPuppy.m_Window, pod_puppy03, pod_puppy03_length, M3DLWPuppy.m_WindowTextureNames);

	M3DModel_SetShaderProgram(M3DLWPuppy.m_Cloud, M3D_UV_DISPLACEMENT_SHADER, M3D_NULL_SHADER);
	return 1;
}

void M3DLWPuppy_LoadContent2(void)
{
	M3DTextureCollection_AddFromMem(&M3DLWPuppy.m_Renderer.m_TextureCollection, "Symbol.pvr",             pvr_puppy02);
	M3DTextureCollection_AddFromMem(&M3DLWPuppy.m_Renderer.m_TextureCollection, "WP3-B-dog.pvr",          pvr_puppy07);

	M3DModel_Load(M3DLWPuppy.m_Dog,    pod_puppy04, pod_puppy04_length, M3DLWPuppy.m_DogTextureNames);

	M3DModel_SetShaderProgramByNodeName(M3DLWPuppy.m_Dog, "dog", M3D_SKINNING_GOURAUD_SHADER);
	M3DModel_SetShaderProgramByNodeName(M3DLWPuppy.m_Dog, "bone", M3D_GOURAUD_SHADER);
	M3DModel_SetShaderProgramByNodeName(M3DLWPuppy.m_Dog, "frog", M3D_GOURAUD_SHADER);

	/*
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE0",   420,  430, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE1",     0,   90, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE2",   120,  210, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE3",   240,  390, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE4",   420,  510, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE5",   540,  630, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE6",   690,  780, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE7",   810,  870, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE8",   900, 1050, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE9",  1080, 1200, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE10", 1240, 1300, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE11", 1530, 1670, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE12", 1720, 1810, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE13", 1860, 2070, 1.0f);
	*/

	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE0",   420, 430, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE1",     0,  30, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE2",    40,  70, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE3",    80, 128, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE4",   140, 170, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE5",   180, 210, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE6",   230, 260, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE7",   270, 290, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE8",   300, 350, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE9",   360, 400, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE10",  413, 433, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE11",  510, 557, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE12",  573, 603, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWPuppy.m_Dog, "ANIMATE13",  620, 690, 1.0f);

	//M3DModel_InitAnimationEven(M3DLWPuppy.m_Dog, "30,0,970,333,1000,333,1667,333,1000,333,1000,10667,1000,333,667,333,1667,333,1333,444,667,2556,1555,556,1000,557,2333;");
	M3DAniInfo_Add(&M3DLWPuppy.m_Dog->m_AniInfo, "init", 6333, 7000);
	M3DModel_SetDefaultAnimation(M3DLWPuppy.m_Dog, 10, 1.0f);
	M3DModel_SetAnimationByName(M3DLWPuppy.m_Dog, "init");
}

#ifdef __cplusplus
}
#endif

/* end of M3DLWPuppy.c */

