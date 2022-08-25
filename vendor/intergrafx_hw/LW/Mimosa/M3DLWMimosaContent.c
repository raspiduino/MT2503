//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWMimosa
// File        : M3DLWMimosaContent.c
// Description : IGV5 LW Mimosa
// Author      : Ray
// Create      : 2011-09-18
// Update      : 2012-01-16
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWMimosa.h"
#include "M3DTextureManager.h"

#if defined(__MMI_MAINLCD_240X320__)
#include "pvr_mimosa_240x320.h"
#elif defined(__MMI_MAINLCD_240X400__)
#include "pvr_mimosa_240x400.h"
#elif defined(__MMI_MAINLCD_320X480__)
#include "pvr_mimosa_320x480.h"
#elif defined(__MMI_MAINLCD_480X800__)
#include "pvr_mimosa_480x800.h"
#else
#include "pvr_mimosa_320x480.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern M3DLWMimosaApp M3DLWMimosa;

extern unsigned char const pod_mimosa01[];
extern unsigned char const pod_mimosa02[];
extern unsigned char const pod_mimosa03[];
extern unsigned char const pod_mimosa04[];
extern unsigned char const pod_mimosa05[];
extern unsigned char const pod_mimosa06[];
extern long pod_mimosa01_length;
extern long pod_mimosa02_length;
extern long pod_mimosa03_length;
extern long pod_mimosa04_length;
extern long pod_mimosa05_length;
extern long pod_mimosa06_length;

extern unsigned char const pvr_mimosa01[];
extern unsigned char const pvr_mimosa02[];
extern unsigned char const pvr_mimosa03[];
extern unsigned char const pvr_mimosa03a[];
extern unsigned char const pvr_mimosa04[];
extern unsigned char const pvr_mimosa04a[];
extern unsigned char const pvr_mimosa05[];
extern unsigned char const pvr_mimosa05a[];
extern unsigned char const pvr_mimosa06[];
extern unsigned char const pvr_mimosa07[];
extern unsigned char const pvr_mimosa07a[];
extern unsigned char const pvr_mimosa08[];
extern unsigned char const pvr_mimosa09[];
extern unsigned char const pvr_mimosa10[];
extern unsigned char const pvr_mimosa11[];
extern unsigned char const pvr_mimosa12[];
extern unsigned char const pvr_mimosa13[];
extern unsigned char const pvr_mimosa13a[];
extern unsigned char const pvr_mimosa14[];
extern unsigned char const pvr_mimosa15[];
extern unsigned char const pvr_mimosa15a[];
extern unsigned char const pvr_mimosa16[];
extern unsigned char const pvr_mimosa16a[];
extern unsigned char const pvr_mimosa17[];
extern unsigned char const pvr_mimosa17a[];
extern unsigned char const pvr_mimosa18[];
extern unsigned char const pvr_mimosa18a[];

extern unsigned char const pvr_mimosa_background2d[];

void M3DLWMimosa_LoadBackground2D(void)
{
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "bg2d.pvr",          pvr_mimosa_background2d);
}

void M3DLWMimosa_RemoveBackground2D(void)
{
	M3DTextureCollection_Remove(&M3DLWMimosa.m_Renderer.m_TextureCollection, "bg2d.pvr");
}

int M3DLWMimosa_LoadContent(void)
{
	M3DLWMimosa.m_SceneTextureNames     = M3DSplitString_New("Sky.pvr,Mountain.pvr,Grass.pvr,Farm.pvr,water.pvr,Wood.pvr,Wall.pvr,Floor.pvr;");
	M3DLWMimosa.m_FlowerpotTextureNames = M3DSplitString_New("Flowerpot.pvr,Soil.pvr;");
	M3DLWMimosa.m_WindowTextureNames    = M3DSplitString_New("Glass.pvr,Window.pvr;");
	M3DLWMimosa.m_ButterflyTextureNames = M3DSplitString_New("Fly01.pvr,Fly02.pvr;");
	M3DLWMimosa.m_PlantTextureNames     = M3DSplitString_New("Stem.pvr,WP1-A-flowerR.pvr,WP1-A-flowerY.pvr,Leaf.pvr;");

	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Floor.pvr",            pvr_mimosa01);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Flowerpot.pvr",        pvr_mimosa02);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Fly01.pvr",            pvr_mimosa03);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Fly01_a.pvr",          pvr_mimosa03a);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Fly02.pvr",            pvr_mimosa04);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Fly02_a.pvr",          pvr_mimosa04a);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Glass.pvr",            pvr_mimosa05);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Glass_a.pvr",          pvr_mimosa05a);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Grass.pvr",            pvr_mimosa06);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Mountain.pvr",         pvr_mimosa07);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Mountain_a.pvr",       pvr_mimosa07a);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Sky.pvr",              pvr_mimosa08);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Soil.pvr",             pvr_mimosa09);
	//M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Stem.pvr",             pvr_mimosa10);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Wall.pvr",             pvr_mimosa11);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "water.pvr",            pvr_mimosa12);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Window.pvr",           pvr_mimosa13);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Wood.pvr",             pvr_mimosa14);
	//M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "WP1-A-flowerR.pvr",    pvr_mimosa15);
	//M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "WP1-A-flowerR_a.pvr",  pvr_mimosa15a);
	//M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "WP1-A-flowerY.pvr",    pvr_mimosa16);
	//M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "WP1-A-flowerY_a.pvr",  pvr_mimosa16a);
	//M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "WP1-A-Leaf.pvr",       pvr_mimosa17);
	//M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "WP1-A-Leaf_a.pvr",     pvr_mimosa17a);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Farm.pvr",             pvr_mimosa18);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Farm_a.pvr"     ,      pvr_mimosa18a);

	M3DTextureCollection_Map(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Fly01.pvr",          NULL,                     "Fly01_a.pvr");
	M3DTextureCollection_Map(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Fly02.pvr",          NULL,                     "Fly02_a.pvr");
	M3DTextureCollection_Map(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Glass.pvr",          NULL,                     "Glass_a.pvr");
	M3DTextureCollection_Map(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Mountain.pvr",       NULL,                     "Mountain_a.pvr");
	//M3DTextureCollection_Map(&M3DLWMimosa.m_Renderer.m_TextureCollection, "WP1-A-flowerR.pvr",  NULL,                     "WP1-A-flowerR_a.pvr");
	//M3DTextureCollection_Map(&M3DLWMimosa.m_Renderer.m_TextureCollection, "WP1-A-flowerY.pvr",  NULL,                     "WP1-A-flowerY_a.pvr");
	//M3DTextureCollection_Map(&M3DLWMimosa.m_Renderer.m_TextureCollection, "WP1-A-Leaf.pvr",     NULL,                     "WP1-A-Leaf_a.pvr");
	M3DTextureCollection_Map(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Farm.pvr",           NULL,                     "Farm_a.pvr");

	M3DModel_Load(M3DLWMimosa.m_Scene,     pod_mimosa01, pod_mimosa01_length, M3DLWMimosa.m_SceneTextureNames);
	M3DModel_Load(M3DLWMimosa.m_CameraPod, pod_mimosa02, pod_mimosa02_length, NULL);
	M3DModel_Load(M3DLWMimosa.m_Flowerpot, pod_mimosa03, pod_mimosa03_length, M3DLWMimosa.m_FlowerpotTextureNames);
	M3DModel_Load(M3DLWMimosa.m_Butterfly, pod_mimosa04, pod_mimosa04_length, M3DLWMimosa.m_ButterflyTextureNames);
	M3DModel_Load(M3DLWMimosa.m_Window,    pod_mimosa06, pod_mimosa06_length, M3DLWMimosa.m_WindowTextureNames);

	M3DModel_SetShaderProgramByNodeName(M3DLWMimosa.m_Scene, "Lawn", M3D_TEXTURE_SHADER);  //CY change shader to less exapnsive one
	M3DModel_SetShaderProgramByNodeName(M3DLWMimosa.m_Scene, "Pier", M3D_TEXTURE_SHADER);
	M3DModel_SetShaderProgramByNodeName(M3DLWMimosa.m_Scene, "Wall_02", M3D_TEXTURE_SHADER);
	M3DModel_SetShaderProgramByNodeName(M3DLWMimosa.m_Scene, "Floor", M3D_TEXTURE_SHADER);
	M3DModel_SetShaderProgram(M3DLWMimosa.m_Flowerpot, M3D_GOURAUD_SHADER, M3D_NULL_SHADER);
	M3DModel_SetShaderProgram(M3DLWMimosa.m_Butterfly, M3D_TEXTURE_SHADER, M3D_NULL_SHADER);
	M3DModel_SetShaderProgram(M3DLWMimosa.m_Window, M3D_TEXTURE_SHADER, M3D_NULL_SHADER);

	/*
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE0",    0,  139, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE1",  139,  199, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE2",  199,  210, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE3",  210,  221, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE4",  221,  229, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE5",  229,  240, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE6",  240,  250, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE7",  250,  261, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE8",  261,  270, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE9",  270,  279, 1.0f);
	*/

	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE0",    0,  140, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE1",  140,  200, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE2",  220,  225, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE3",  225,  230, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE4",  230,  235, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE5",  235,  240, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE6",  200,  205, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE7",  205,  210, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE8",  210,  215, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_CameraPod, "ANIMATE9",  215,  220, 1.0f);

	M3DModel_SetAnimationStart(M3DLWMimosa.m_CameraPod, 0);

	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_Butterfly, "ANIMATE0",    0,  139, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_Butterfly, "ANIMATE1",  139,  199, 1.0f);
	M3DModel_SetDefaultAnimation(M3DLWMimosa.m_Butterfly, 1, 1.0f);
	M3DModel_SetAnimation(M3DLWMimosa.m_Butterfly, 0);
	return 1;
}

void M3DLWMimosa_LoadContent2(void)
{
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Stem.pvr",             pvr_mimosa10);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "WP1-A-flowerR.pvr",    pvr_mimosa15);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "WP1-A-flowerR_a.pvr",  pvr_mimosa15a);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "WP1-A-flowerY.pvr",    pvr_mimosa16);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "WP1-A-flowerY_a.pvr",  pvr_mimosa16a);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Leaf.pvr",             pvr_mimosa17);
	M3DTextureCollection_AddFromMem(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Leaf_a.pvr",           pvr_mimosa17a);

	M3DTextureCollection_Map(&M3DLWMimosa.m_Renderer.m_TextureCollection, "WP1-A-flowerR.pvr",  NULL,                     "WP1-A-flowerR_a.pvr");
	M3DTextureCollection_Map(&M3DLWMimosa.m_Renderer.m_TextureCollection, "WP1-A-flowerY.pvr",  NULL,                     "WP1-A-flowerY_a.pvr");
	M3DTextureCollection_Map(&M3DLWMimosa.m_Renderer.m_TextureCollection, "Leaf.pvr",           NULL,                     "Leaf_a.pvr");

	M3DModel_Load(M3DLWMimosa.m_Plant, pod_mimosa05, pod_mimosa05_length, M3DLWMimosa.m_PlantTextureNames);
	M3DModel_SetShaderProgram(M3DLWMimosa.m_Plant, M3D_TEXTURE_SHADER, M3D_SKINNING_TEXTURE_SHADER);

	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_Plant, "ANIMATE0",   30,   49, 0.3f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_Plant, "ANIMATE1",   15,   49, 0.5f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_Plant, "ANIMATE2",    0,   49, 0.5f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_Plant, "ANIMATE3",   49,   75, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_Plant, "ANIMATE4",   75,  100, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_Plant, "ANIMATE5",  101,  124, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWMimosa.m_Plant, "ANIMATE6",  125,  150, 1.0f);
	M3DModel_SetDefaultAnimation(M3DLWMimosa.m_Plant, 0, 0.3f);
}
#ifdef __cplusplus
}
#endif

/* end of M3DLWMimosa.c */

