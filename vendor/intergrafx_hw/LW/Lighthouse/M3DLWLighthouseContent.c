//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWLighthouse
// File        : M3DLWLighthouseContent.c
// Description : IGV5 LW Lighthouse
// Author      : Ray
// Create      : 2011-08-30
// Update      : 2012-01-17
//============================================================================== 

#include "M3DGameDef.h"
#include "M3DLWLighthouse.h"
#include "M3DTextureManager.h"

#if defined(__MMI_MAINLCD_240X320__)
#include "pvr_lighthouse_240x320.h"
#elif defined(__MMI_MAINLCD_240X400__)
#include "pvr_lighthouse_240x400.h"
#elif defined(__MMI_MAINLCD_320X480__)
#include "pvr_lighthouse_320x480.h"
#elif defined(__MMI_MAINLCD_480X800__)
#include "pvr_lighthouse_480x800.h"
#else
#include "pvr_lighthouse_320x480.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern M3DLWLighthouseApp M3DLWLighthouse;

extern unsigned char const pod_lighthouse01[];
extern unsigned char const pod_lighthouse02[];
extern unsigned char const pod_lighthouse03[];
extern unsigned char const pod_lighthouse04[];
extern unsigned char const pod_lighthouse05[];
extern unsigned char const pod_lighthouse06[];
extern unsigned char const pod_lighthouse07[];
extern long pod_lighthouse01_length;
extern long pod_lighthouse02_length;
extern long pod_lighthouse03_length;
extern long pod_lighthouse04_length;
extern long pod_lighthouse05_length;
extern long pod_lighthouse06_length;
extern long pod_lighthouse07_length;

extern unsigned char const pvr_lighthouse01[];
extern unsigned char const pvr_lighthouse01a[];
extern unsigned char const pvr_lighthouse02[];
extern unsigned char const pvr_lighthouse03[];
extern unsigned char const pvr_lighthouse04[];
extern unsigned char const pvr_lighthouse04a[];
extern unsigned char const pvr_lighthouse05[];
extern unsigned char const pvr_lighthouse06[];
extern unsigned char const pvr_lighthouse06a[];
extern unsigned char const pvr_lighthouse07[];
extern unsigned char const pvr_lighthouse07a[];
extern unsigned char const pvr_lighthouse08[];
extern unsigned char const pvr_lighthouse09[];
extern unsigned char const pvr_lighthouse10[];
extern unsigned char const pvr_lighthouse10a[];
extern unsigned char const pvr_lighthouse11[];
extern unsigned char const pvr_lighthouse11a[];
extern unsigned char const pvr_lighthouse12[];
extern unsigned char const pvr_lighthouse12a[];
extern unsigned char const pvr_lighthouse13[];
extern unsigned char const pvr_lighthouse14[];
extern unsigned char const pvr_lighthouse15[];
extern unsigned char const pvr_lighthouse15a[];

extern unsigned char const pvr_lighthouse_background2d[];

void M3DLWLighthouse_LoadBackground2D(void)
{
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "bg2d.pvr", pvr_lighthouse_background2d);
}

void M3DLWLighthouse_RemoveBackground2D(void)
{
	M3DTextureCollection_Remove(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "bg2d.pvr");
}

int M3DLWLighthouse_LoadContent(void)
{
	M3DLWLighthouse.m_SceneTextureNames = M3DSplitString_New("WP3-A-mountain.pvr,WP3-A-mountain_2.pvr,WP3-A-island.pvr,WP3-A-tower.pvr,WP3-A-trees.pvr,WP3-A-sea01.pvr,WP3-A-sea02.pvr;");
	M3DLWLighthouse.m_RayTextureNames   = M3DSplitString_New("WP3-A-ray.pvr;");
	M3DLWLighthouse.m_BirdsTextureNames = M3DSplitString_New("WP3-A-bird.pvr;");
	M3DLWLighthouse.m_WhaleTextureNames = M3DSplitString_New("WP3-A-whale.pvr,wave.pvr;");
	M3DLWLighthouse.m_Ray2TextureNames  = M3DSplitString_New("WP3-A-ray-2.pvr;");
	
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-sea01.pvr",  pvr_lighthouse02);
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-sea02.pvr",  pvr_lighthouse03);
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-bird.pvr",        pvr_lighthouse04);
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-bird_a.pvr",      pvr_lighthouse04a);
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-island.pvr",      pvr_lighthouse05);
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-mountain.pvr",    pvr_lighthouse06);
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-ray.pvr",         pvr_lighthouse07);
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-ray_a.pvr",       pvr_lighthouse07a);
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-tower.pvr",       pvr_lighthouse09);
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-trees.pvr",       pvr_lighthouse10);
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-trees_a.pvr",     pvr_lighthouse10a);
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-whale.pvr",       pvr_lighthouse11);
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-whale_a.pvr",     pvr_lighthouse11a);
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-ray-2.pvr",       pvr_lighthouse12);
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-ray-2_a.pvr",     pvr_lighthouse12a);
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-mountain_2.pvr",  pvr_lighthouse14);
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "wave.pvr",       pvr_lighthouse15);
	M3DTextureCollection_AddFromMem(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "wave_a.pvr",     pvr_lighthouse15a);
	
	M3DTextureCollection_Map(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-bird.pvr",     NULL,                       "WP3-A-bird_a.pvr");
	M3DTextureCollection_Map(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-ray.pvr",      NULL,                       "WP3-A-ray_a.pvr");
	M3DTextureCollection_Map(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-trees.pvr",    NULL,                       "WP3-A-trees_a.pvr");
	M3DTextureCollection_Map(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-whale.pvr",    NULL,                       "WP3-A-whale_a.pvr");
	M3DTextureCollection_Map(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "WP3-A-ray-2.pvr",    NULL,                       "WP3-A-ray-2_a.pvr");
	M3DTextureCollection_Map(&M3DLWLighthouse.m_Renderer.m_TextureCollection, "wave.pvr",    NULL,                       "wave_a.pvr");

	M3DModel_Load(M3DLWLighthouse.m_Scene, pod_lighthouse01, pod_lighthouse01_length, M3DLWLighthouse.m_SceneTextureNames);

	M3DModel_SetShaderProgram(M3DLWLighthouse.m_Scene, M3D_TEXTURE_SHADER, M3D_NULL_SHADER);

	M3DRenderer_LoadSkyboxTexture(&M3DLWLighthouse.m_Renderer, "Water.pvr", pvr_lighthouse13, "Sky_box.pvr", pvr_lighthouse08);

	M3DModel_Load(M3DLWLighthouse.m_Ray  , pod_lighthouse02, pod_lighthouse02_length, M3DLWLighthouse.m_RayTextureNames);
	M3DModel_Load(M3DLWLighthouse.m_Birds, pod_lighthouse03, pod_lighthouse03_length, M3DLWLighthouse.m_BirdsTextureNames);
	M3DModel_Load(M3DLWLighthouse.m_Whale, pod_lighthouse04, pod_lighthouse04_length, M3DLWLighthouse.m_WhaleTextureNames);
	M3DModel_Load(M3DLWLighthouse.m_Ray2 , pod_lighthouse07, pod_lighthouse07_length, M3DLWLighthouse.m_Ray2TextureNames);

	M3DModel_SetShaderProgram(M3DLWLighthouse.m_Birds, M3D_NULL_SHADER, M3D_SKINNING_TEXTURE_SHADER);
	M3DModel_SetShaderProgram(M3DLWLighthouse.m_Whale, M3D_NULL_SHADER, M3D_SKINNING_TEXTURE_SHADER);
	
	M3DDummyGroup_Load(M3DLWLighthouse.m_BirdsPath, pod_lighthouse05, pod_lighthouse05_length, "bird_route1,bird_route2,bird_route3;");
	M3DDummyGroup_Load(M3DLWLighthouse.m_WhalePath, pod_lighthouse06, pod_lighthouse06_length, "whale_dummy01,whale_dummy02,whale_dummy03,whale_dummy04,whale_dummy05,whale_dummy06,whale_dummy07,whale_dummy08,whale_dummy09,whale_dummy10;");
	M3DDummyGroup_AddObject(M3DLWLighthouse.m_WhalePath, M3DLWLighthouse.m_Whale, "whale_A");
	M3DDummyGroup_AddObject(M3DLWLighthouse.m_BirdsPath, M3DLWLighthouse.m_Birds, "Bird_All");
	M3DDummyGroup_Attach(M3DLWLighthouse.m_BirdsPath, 0, 0);
	M3DDummyGroup_Attach(M3DLWLighthouse.m_WhalePath, 0, 0);

	return 1;
}

#ifdef __cplusplus
}
#endif

/* end of M3DLWLighthouse.c */

