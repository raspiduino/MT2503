//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWHorse
// File        : M3DLWHorseContent.c
// Description : IGV5 LW Horse
// Author      : Ray
// Create      : 2011-09-20
// Update      : 2011-12-23
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWHorse.h"
#include "M3DTextureManager.h"

#if defined(__MMI_MAINLCD_240X320__)
#include "pvr_horse_240x320.h"
#elif defined(__MMI_MAINLCD_240X400__)
#include "pvr_horse_240x400.h"
#elif defined(__MMI_MAINLCD_320X480__)
#include "pvr_horse_320x480.h"
#elif defined(__MMI_MAINLCD_480X800__)
#include "pvr_horse_480x800.h"
#else
#include "pvr_horse_320x480.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern M3DLWHorseApp M3DLWHorse;

extern unsigned char const pod_horse01[];
extern unsigned char const pod_horse02[];
extern unsigned char const pod_horse03[];
extern unsigned char const pod_horse03b[];
extern unsigned char const pod_horse04[];
extern unsigned char const pod_horse05[];
extern unsigned char const pod_horse06[];
extern unsigned char const pod_horse07[];
extern unsigned char const pod_horse08[];
extern unsigned char const pod_horse09[];
extern unsigned char const pod_horse10[];
extern long pod_horse01_length;
extern long pod_horse02_length;
extern long pod_horse03_length;
extern long pod_horse03b_length;
extern long pod_horse04_length;
extern long pod_horse05_length;
extern long pod_horse06_length;
extern long pod_horse07_length;
extern long pod_horse08_length;
extern long pod_horse09_length;
extern long pod_horse10_length;

extern unsigned char const pvr_horse01[];
extern unsigned char const pvr_horse01a[];
extern unsigned char const pvr_horse03[];
extern unsigned char const pvr_horse03a[];
extern unsigned char const pvr_horse04[];
extern unsigned char const pvr_horse04a[];
extern unsigned char const pvr_horse05[];
extern unsigned char const pvr_horse05a[];
extern unsigned char const pvr_horse06[];
extern unsigned char const pvr_horse06a[];
extern unsigned char const pvr_horse07[];
extern unsigned char const pvr_horse07a[];
extern unsigned char const pvr_horse08[];
extern unsigned char const pvr_horse08a[];
extern unsigned char const pvr_horse09[];
extern unsigned char const pvr_horse09a[];
extern unsigned char const pvr_horse10[];
extern unsigned char const pvr_horse10a[];
extern unsigned char const pvr_horse11[];
extern unsigned char const pvr_horse11a[];
extern unsigned char const pvr_horse12[];
extern unsigned char const pvr_horse12a[];
extern unsigned char const pvr_horse13[];
extern unsigned char const pvr_horse13a[];
extern unsigned char const pvr_horse14[];
extern unsigned char const pvr_horse14a[];
extern unsigned char const pvr_horse15[];
extern unsigned char const pvr_horse16[];
extern unsigned char const pvr_horse16a[];

extern unsigned char const pvr_horse_background2d[];

void M3DLWHorse_LoadBackground2D(void)
{
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "bg2d.pvr",          pvr_horse_background2d);
}

void M3DLWHorse_RemoveBackground2D(void)
{
	M3DTextureCollection_Remove(&M3DLWHorse.m_Renderer.m_TextureCollection, "bg2d.pvr");
}

int M3DLWHorse_LoadContent(void)
{
	M3DLWHorse.m_SceneTextureNames     = M3DSplitString_New("main.pvr;");
	M3DLWHorse.m_ButterflyTextureNames = M3DSplitString_New("Animal.pvr;");
	M3DLWHorse.m_TreeTextureNames      = M3DSplitString_New("tree_01.pvr,light.pvr,tree_02.pvr;");
	M3DLWHorse.m_OthersTextureNames    = M3DSplitString_New("CLOUD_s.pvr,main.pvr,front.pvr;");
	M3DLWHorse.m_LeafTextureNames      = M3DSplitString_New("leaf02.pvr;");
	M3DLWHorse.m_FogTextureNames       = M3DSplitString_New("wave2.pvr;");
	M3DLWHorse.m_HorseTextureNames[0]  = M3DSplitString_New("horse3.pvr,Shadow.pvr;");
	M3DLWHorse.m_HorseTextureNames[1]  = M3DSplitString_New("horse3.pvr,Shadow.pvr;");
	M3DLWHorse.m_HorseTextureNames[2]  = M3DSplitString_New("horse2.pvr,Shadow.pvr;");
	M3DLWHorse.m_HorseTextureNames[3]  = M3DSplitString_New("horse4.pvr,Shadow.pvr;");

	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "Animal.pvr",             pvr_horse01);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "Animal_a.pvr",           pvr_horse01a);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "bird.pvr",               pvr_horse03);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "bird_a.pvr",             pvr_horse03a);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "CLOUD_s.pvr",            pvr_horse04);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "CLOUD_s_a.pvr",          pvr_horse04a);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "front.pvr",              pvr_horse05);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "front_a.pvr",            pvr_horse05a);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "leaf.pvr",               pvr_horse09);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "leaf_a.pvr",             pvr_horse09a);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "leaf02.pvr",             pvr_horse10);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "leaf02_a.pvr",           pvr_horse10a);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "light.pvr",              pvr_horse11);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "light_a.pvr",            pvr_horse11a);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "main.pvr",               pvr_horse12);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "main_a.pvr",             pvr_horse12a);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "tree_01.pvr",            pvr_horse13);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "tree_01_a.pvr",          pvr_horse13a);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "tree_02.pvr",            pvr_horse14);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "tree_02_a.pvr",          pvr_horse14a);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "wave2.pvr",              pvr_horse15);

	M3DTextureCollection_Map(&M3DLWHorse.m_Renderer.m_TextureCollection, "Animal.pvr",        NULL,        "Animal_a.pvr");
	M3DTextureCollection_Map(&M3DLWHorse.m_Renderer.m_TextureCollection, "bird.pvr",          NULL,        "bird_a.pvr");
	M3DTextureCollection_Map(&M3DLWHorse.m_Renderer.m_TextureCollection, "CLOUD_s.pvr",       NULL,        "CLOUD_s_a.pvr");
	M3DTextureCollection_Map(&M3DLWHorse.m_Renderer.m_TextureCollection, "front.pvr",         NULL,        "front_a.pvr");
	M3DTextureCollection_Map(&M3DLWHorse.m_Renderer.m_TextureCollection, "leaf.pvr",          NULL,        "leaf_a.pvr");
	M3DTextureCollection_Map(&M3DLWHorse.m_Renderer.m_TextureCollection, "leaf02.pvr",        NULL,        "leaf02_a.pvr");
	M3DTextureCollection_Map(&M3DLWHorse.m_Renderer.m_TextureCollection, "light.pvr",         NULL,        "light_a.pvr");
	M3DTextureCollection_Map(&M3DLWHorse.m_Renderer.m_TextureCollection, "main.pvr",          NULL,        "main_a.pvr");
	M3DTextureCollection_Map(&M3DLWHorse.m_Renderer.m_TextureCollection, "tree_01.pvr",       NULL,        "tree_01_a.pvr");
	M3DTextureCollection_Map(&M3DLWHorse.m_Renderer.m_TextureCollection, "tree_02.pvr",       NULL,        "tree_02_a.pvr");

	M3DModel_Load(M3DLWHorse.m_Scene,     pod_horse01, pod_horse01_length, M3DLWHorse.m_SceneTextureNames);
	M3DModel_Load(M3DLWHorse.m_Butterfly, pod_horse02, pod_horse02_length, M3DLWHorse.m_ButterflyTextureNames);
	M3DModel_Load(M3DLWHorse.m_Tree,      pod_horse03, pod_horse03_length, M3DLWHorse.m_TreeTextureNames);
	M3DModel_Load(M3DLWHorse.m_Others,    pod_horse03b, pod_horse03b_length, M3DLWHorse.m_OthersTextureNames);
	M3DModel_Load(M3DLWHorse.m_Leaf,      pod_horse04, pod_horse04_length, M3DLWHorse.m_LeafTextureNames);
	M3DModel_Load(M3DLWHorse.m_Fog,       pod_horse10, pod_horse10_length, M3DLWHorse.m_FogTextureNames);

	M3DModel_SetShaderProgram(M3DLWHorse.m_Scene, M3D_TEXTURE_SHADER, M3D_NULL_SHADER);  //CY

	M3DTextureCollection_AddUVAnim(&M3DLWHorse.m_Renderer.m_TextureCollection, "wave2.pvr");
	M3DTextureCollection_AddUVAnim(&M3DLWHorse.m_Renderer.m_TextureCollection, "CLOUD_s.pvr");
	M3DTextureCollection_SetUVAnimTimeFactor(&M3DLWHorse.m_Renderer.m_TextureCollection, 0.0f, 0.25f);

	M3DModel_SetShaderProgramByNodeName(M3DLWHorse.m_Fog, "River_01", M3D_UV_DISPLACEMENT_SHADER);
	M3DModel_SetShaderProgramByNodeName(M3DLWHorse.m_Fog, "River_02", M3D_UV_DISPLACEMENT_SHADER);
	M3DModel_SetShaderProgramByNodeName(M3DLWHorse.m_Others, "Fog_front", M3D_UV_DISPLACEMENT_SHADER);
	M3DModel_SetShaderProgramByNodeName(M3DLWHorse.m_Others, "Fog_back",  M3D_UV_DISPLACEMENT_SHADER);

	M3DModel_AddAnimationByFrame(M3DLWHorse.m_Tree, "ANIMATE0",   0,  50, 1.0f);
	M3DLWHorse.m_Leaf->m_TimeFactor = 0.3f;
	M3DLWHorse.m_Renderer.m_LoadState = 1;

	return 1;
}

void M3DLWHorse_LoadContent2(void)
{
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "horse2.pvr",             pvr_horse06);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "horse2_a.pvr",           pvr_horse06a);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "horse3.pvr",             pvr_horse07);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "horse3_a.pvr",           pvr_horse07a);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "horse4.pvr",             pvr_horse08);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "horse4_a.pvr",           pvr_horse08a);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "Shadow.pvr",             pvr_horse16);
	M3DTextureCollection_AddFromMem(&M3DLWHorse.m_Renderer.m_TextureCollection, "Shadow_a.pvr",           pvr_horse16a);

	M3DTextureCollection_Map(&M3DLWHorse.m_Renderer.m_TextureCollection, "horse2.pvr",       NULL,        "horse2_a.pvr");
	M3DTextureCollection_Map(&M3DLWHorse.m_Renderer.m_TextureCollection, "horse3.pvr",       NULL,        "horse3_a.pvr");
	M3DTextureCollection_Map(&M3DLWHorse.m_Renderer.m_TextureCollection, "horse4.pvr",       NULL,        "horse4_a.pvr");
	M3DTextureCollection_Map(&M3DLWHorse.m_Renderer.m_TextureCollection, "Shadow.pvr",       NULL,        "Shadow_a.pvr");

	M3DModel_Load(M3DLWHorse.m_Horse[0], pod_horse05, pod_horse05_length, M3DLWHorse.m_HorseTextureNames[0]);
	M3DModel_Load(M3DLWHorse.m_Horse[1], pod_horse06, pod_horse06_length, M3DLWHorse.m_HorseTextureNames[1]);
	M3DModel_Load(M3DLWHorse.m_Horse[2], pod_horse07, pod_horse07_length, M3DLWHorse.m_HorseTextureNames[2]);
	M3DModel_Load(M3DLWHorse.m_Horse[3], pod_horse08, pod_horse08_length, M3DLWHorse.m_HorseTextureNames[3]);
	M3DModel_Load(M3DLWHorse.m_Horse[4], pod_horse09, pod_horse09_length, M3DLWHorse.m_HorseTextureNames[3]);

	M3DModel_SetShaderProgram(M3DLWHorse.m_Horse[0], M3D_NULL_SHADER, M3D_SKINNING_TEXTURE_SHADER);
	M3DModel_SetShaderProgram(M3DLWHorse.m_Horse[1], M3D_NULL_SHADER, M3D_SKINNING_TEXTURE_SHADER);
	M3DModel_SetShaderProgram(M3DLWHorse.m_Horse[2], M3D_NULL_SHADER, M3D_SKINNING_TEXTURE_SHADER);  //CY20120109	
	M3DModel_SetShaderProgram(M3DLWHorse.m_Horse[3], M3D_NULL_SHADER, M3D_SKINNING_TEXTURE_SHADER);
	M3DModel_SetShaderProgram(M3DLWHorse.m_Horse[4], M3D_NULL_SHADER, M3D_SKINNING_TEXTURE_SHADER);

	M3DLWHorse.m_Horse[1]->m_TimeFactor = 0.7f;
	M3DLWHorse.m_Horse[3]->m_TimeFactor = 0.6f;
	M3DLWHorse.m_Horse[4]->m_TimeFactor = 0.7f;
	M3DModel_AddAnimationByFrame(M3DLWHorse.m_Horse[0], "ANIMATE0",   0,  30, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWHorse.m_Horse[0], "ANIMATE1",  50,  80, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWHorse.m_Horse[0], "ANIMATE2",  80, 230, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWHorse.m_Horse[0], "ANIMATE3", 249, 289, 1.0f);
	M3DModel_SetDefaultAnimation(M3DLWHorse.m_Horse[0], 0, 1.0f);
	M3DModel_SetAnimation(M3DLWHorse.m_Horse[0], 3);

	/*M3DModel_AddAnimationByFrame(M3DLWHorse.m_Horse[2], "ANIMATE0", 150, 152, 0.5f);
	M3DModel_AddAnimationByFrame(M3DLWHorse.m_Horse[2], "ANIMATE1", 110, 130, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWHorse.m_Horse[2], "ANIMATE2", 130, 150, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWHorse.m_Horse[2], "ANIMATE3", 150, 170, 1.0f);*/
	
	M3DModel_AddAnimationByFrame(M3DLWHorse.m_Horse[2], "ANIMATE0", 90, 94, 1.0f);  //抬頭
  M3DModel_AddAnimationByFrame(M3DLWHorse.m_Horse[2], "ANIMATE1", 45, 85, 1.0f);  //drink
	M3DModel_AddAnimationByFrame(M3DLWHorse.m_Horse[2], "ANIMATE2", 0, 30, 1.0f);  // 抬起來
	M3DModel_AddAnimationByFrame(M3DLWHorse.m_Horse[2], "ANIMATE3", 31, 45, 1.0f);	// 低下去
	
	M3DModel_SetDefaultAnimation(M3DLWHorse.m_Horse[2], 0, 1.0f);
	M3DModel_SetAnimation(M3DLWHorse.m_Horse[2], 2);

	/*
	M3DModel_AddAnimationByFrame(M3DLWHorse.m_Horse[2], "ANIMATE0", 110, 130, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWHorse.m_Horse[2], "ANIMATE1", 130, 170, 1.0f);
	M3DModel_SetDefaultAnimation(M3DLWHorse.m_Horse[2], 0, 1.0f);
	M3DModel_SetAnimation(M3DLWHorse.m_Horse[2], 1);
	*/
	M3DLWHorse.m_Renderer.m_LoadState = 2;
}

#ifdef __cplusplus
}
#endif

/* end of M3DLWHorse.c */

