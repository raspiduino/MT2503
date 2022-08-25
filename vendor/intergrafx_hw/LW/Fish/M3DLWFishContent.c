//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWFish
// File        : M3DLWFishContent.c
// Description : IGV5 LW Fish
// Author      : Ray
// Create      : 2011-08-30
// Update      : 2011-12-23
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWFish.h"
#include "M3DTextureManager.h"

#if defined(__MMI_MAINLCD_240X320__)
#include "pvr_fish_240x320.h"
#elif defined(__MMI_MAINLCD_240X400__)
#include "pvr_fish_240x400.h"
#elif defined(__MMI_MAINLCD_320X480__)
#include "pvr_fish_320x480.h"
#elif defined(__MMI_MAINLCD_480X800__)
#include "pvr_fish_480x800.h"
#else
#include "pvr_fish_320x480.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern M3DLWFishApp M3DLWFish;

extern unsigned char const pod_fish01[];
extern unsigned char const pod_fish02[];
extern unsigned char const pod_fish03[];
extern unsigned char const pod_fish04[];
extern unsigned char const pod_fish05[];
extern unsigned char const pod_fish05_b[];
extern unsigned char const pod_fish05_c[];
extern unsigned char const pod_fish06[];
extern long pod_fish01_length;
extern long pod_fish02_length;
extern long pod_fish03_length;
extern long pod_fish04_length;
extern long pod_fish05_length;
extern long pod_fish06_length;

extern unsigned char const pvr_fish01[];
extern unsigned char const pvr_fish02[];
extern unsigned char const pvr_fish02a[];
extern unsigned char const pvr_fish04[];
extern unsigned char const pvr_fish04a[];
extern unsigned char const pvr_fish07[];
extern unsigned char const pvr_fish07a[];
extern unsigned char const pvr_fish09[];
extern unsigned char const pvr_fish09a[];
extern unsigned char const pvr_fish10[];
extern unsigned char const pvr_fish10a[];
extern unsigned char const pvr_fish11[];
extern unsigned char const pvr_fish11a[];
extern unsigned char const pvr_fish12[];
extern unsigned char const pvr_fish12a[];
extern unsigned char const pvr_fish13[];
extern unsigned char const pvr_fish14[];
extern unsigned char const pvr_fish15[];
extern unsigned char const pvr_fish15a[];

extern unsigned char const pvr_fish_background2d[];

void M3DLWFish_LoadBackground2D(void)
{
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "bg2d.pvr",          pvr_fish_background2d);
}

void M3DLWFish_RemoveBackground2D(void)
{
	M3DTextureCollection_Remove(&M3DLWFish.m_Renderer.m_TextureCollection, "bg2d.pvr");
}

int M3DLWFish_LoadContent(void)
{
	M3DLWFish.m_SceneTextureNames  = M3DSplitString_New("Stone.pvr,Nomove_02.pvr,Nomove_03.pvr,Bg.pvr,Sand.pvr;");
	M3DLWFish.m_CoralTextureNames  = M3DSplitString_New("Coral02.pvr,coral08.pvr;");
	M3DLWFish.m_Fish1TextureNames  = M3DSplitString_New("fish001.pvr,WP3-D-fish1.pvr,Fish03.pvr;");
	M3DLWFish.m_Fish2TextureNames  = M3DSplitString_New("fish001.pvr,Fish03.pvr,WP3-D-fish1.pvr;");
	M3DLWFish.m_BubbleTextureNames = M3DSplitString_New("Bubble.pvr;");

	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "Bg.pvr",                 pvr_fish01);
	//M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "Bubble.pvr",             pvr_fish02);
	//M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "Bubble_a.pvr",           pvr_fish02a);
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "Coral02.pvr",            pvr_fish04);
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "Coral02_a.pvr",          pvr_fish04a);
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "coral08.pvr",            pvr_fish07);
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "coral08_a.pvr",          pvr_fish07a);
	//M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "fish001.pvr",            pvr_fish09);
	//M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "fish001_a.pvr",          pvr_fish09a);
	//M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "Fish03.pvr",             pvr_fish10);
	//M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "Fish03_a.pvr",           pvr_fish10a);
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "Nomove_02.pvr",          pvr_fish11);
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "Nomove_02_a.pvr",        pvr_fish11a);
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "Nomove_03.pvr",          pvr_fish12);
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "Nomove_03_a.pvr",        pvr_fish12a);
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "Sand.pvr",               pvr_fish13);
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "Stone.pvr",              pvr_fish14);
	//M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "WP3-D-fish1.pvr",        pvr_fish15);
	//M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "WP3-D-fish1_a.pvr",      pvr_fish15a);

	//M3DTextureCollection_MapAlpha(&M3DLWFish.m_Renderer.m_TextureCollection, "Bubble.pvr",           "Bubble_a.pvr");
	M3DTextureCollection_MapAlpha(&M3DLWFish.m_Renderer.m_TextureCollection, "Coral02.pvr",          "Coral02_a.pvr");
	M3DTextureCollection_MapAlpha(&M3DLWFish.m_Renderer.m_TextureCollection, "coral08.pvr",          "coral08_a.pvr");
	M3DTextureCollection_MapAlpha(&M3DLWFish.m_Renderer.m_TextureCollection, "Nomove_02.pvr",        "Nomove_02_a.pvr");
	M3DTextureCollection_MapAlpha(&M3DLWFish.m_Renderer.m_TextureCollection, "Nomove_03.pvr",        "Nomove_03_a.pvr");

	M3DModel_Load(M3DLWFish.m_Scene, pod_fish01, pod_fish01_length, M3DLWFish.m_SceneTextureNames);
	M3DModel_Load(M3DLWFish.m_Coral, pod_fish04, pod_fish04_length, M3DLWFish.m_CoralTextureNames);

	M3DModel_SetShaderProgram(M3DLWFish.m_Scene, M3D_GOURAUD_SHADOW_SHADER, M3D_NULL_SHADER);
	M3DModel_SetShaderProgramByNodeName(M3DLWFish.m_Scene, "Bg", M3D_TEXTURE_SHADER);  //CY
	M3DModel_SetShaderProgram(M3DLWFish.m_Coral, M3D_GOURAUD_SHADOW_SHADER, M3D_NULL_SHADER);
	
	//IGV5Model_SetShaderProgramForAllNode(&M3DLWFish.m_Scene->m_Node, (ShaderProgram*)M3DLWFish.gouraudShadowShader, NULL);
	//IGV5Model_SetShaderProgram(&M3DLWFish.m_Scene->m_Node, IGV5Model_FindNodeIdxByName(&M3DLWFish.m_Scene->m_Node, "Backbround"), (ShaderProgram*)M3DLWFish.textureShader);
	//IGV5Model_SetShaderProgramForAllNode(&M3DLWFish.m_Coral->m_Node, (ShaderProgram*)M3DLWFish.gouraudShadowShader, NULL);

	return 1;
}

void M3DLWFish_LoadContent2(void)
{
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "Bubble.pvr",             pvr_fish02);
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "Bubble_a.pvr",           pvr_fish02a);
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "fish001.pvr",            pvr_fish09);
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "fish001_a.pvr",          pvr_fish09a);
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "Fish03.pvr",             pvr_fish10);
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "Fish03_a.pvr",           pvr_fish10a);
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "WP3-D-fish1.pvr",        pvr_fish15);
	M3DTextureCollection_AddFromMem(&M3DLWFish.m_Renderer.m_TextureCollection, "WP3-D-fish1_a.pvr",      pvr_fish15a);

	M3DTextureCollection_MapAlpha(&M3DLWFish.m_Renderer.m_TextureCollection, "Bubble.pvr",           "Bubble_a.pvr");
	M3DTextureCollection_MapAlpha(&M3DLWFish.m_Renderer.m_TextureCollection, "fish001.pvr",          "fish001_a.pvr");
	M3DTextureCollection_MapAlpha(&M3DLWFish.m_Renderer.m_TextureCollection, "Fish03.pvr",           "Fish03_a.pvr");
	M3DTextureCollection_MapAlpha(&M3DLWFish.m_Renderer.m_TextureCollection, "WP3-D-fish1.pvr",      "WP3-D-fish1_a.pvr");

	M3DModel_Load(M3DLWFish.m_Fish1, pod_fish02, pod_fish02_length, M3DLWFish.m_Fish1TextureNames);
	M3DModel_Load(M3DLWFish.m_Fish2, pod_fish03, pod_fish03_length, M3DLWFish.m_Fish2TextureNames);
	M3DModel_Load(M3DLWFish.m_Bubble, pod_fish05, pod_fish05_length, M3DLWFish.m_BubbleTextureNames);
	M3DModel_Load(M3DLWFish.m_Bubble_b, pod_fish05_b, pod_fish05_length, M3DLWFish.m_BubbleTextureNames);
	M3DModel_Load(M3DLWFish.m_Bubble_c, pod_fish05_c, pod_fish05_length, M3DLWFish.m_BubbleTextureNames);
	M3DModel_Load(M3DLWFish.m_BubbleTouch, pod_fish06, pod_fish06_length, M3DLWFish.m_BubbleTextureNames);

	M3DModel_SetShaderProgram(M3DLWFish.m_Fish1, M3D_SKINNING_GOURAUD_SHADER, M3D_NULL_SHADER);
	M3DModel_SetShaderProgram(M3DLWFish.m_Fish2, M3D_SKINNING_GOURAUD_SHADER, M3D_NULL_SHADER);
	
	M3DModel_SetTime(M3DLWFish.m_Fish1, 180*1000/30);
	//M3DLWFish.m_Fish1->m_TimeFactor = 0.5f;
	//M3DLWFish.m_Fish2->m_TimeFactor = 0.5f;

	M3DDummyGroup_AddStaticDummies(M3DLWFish.m_BubbleDummy, M3DLWFish.m_Scene, "Bubble_point");
	M3DDummyGroup_AddObject(M3DLWFish.m_BubbleDummy, M3DLWFish.m_Bubble, "Bubble_dummy01");
	M3DDummyGroup_Attach(M3DLWFish.m_BubbleDummy, 0, 0);
}

#ifdef __cplusplus
}
#endif

/* end of M3DLWFish.c */

