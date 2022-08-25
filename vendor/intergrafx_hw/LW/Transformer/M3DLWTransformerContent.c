//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWTransformer
// File        : M3DLWTransformerContent.c
// Description : IGV5 LW Transformer
// Author      : Ray
// Create      : 2011-08-25
// Update      : 2011-12-23
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWTransformer.h"
#include "M3DTextureManager.h"

#if defined(__MMI_MAINLCD_240X320__)
#include "pvr_transformer_240x320.h"
#elif defined(__MMI_MAINLCD_240X400__)
#include "pvr_transformer_240x400.h"
#elif defined(__MMI_MAINLCD_320X480__)
#include "pvr_transformer_320x480.h"
#elif defined(__MMI_MAINLCD_480X800__)
#include "pvr_transformer_480x800.h"
#else
#include "pvr_transformer_320x480.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern M3DLWTransformerApp M3DLWTransformer;

extern unsigned char const pod_transformer01[];
extern unsigned char const pod_transformer02[];
extern long pod_transformer01_length;
extern long pod_transformer02_length;

extern unsigned char const pvr_transformer01[];
extern unsigned char const pvr_transformer02[];
extern unsigned char const pvr_transformer03[];
extern unsigned char const pvr_transformer03a[];
extern unsigned char const pvr_transformer04[];
extern unsigned char const pvr_transformer04a[];
extern unsigned char const pvr_transformer05[];
extern unsigned char const pvr_transformer05a[];
extern unsigned char const pvr_transformer06[];
extern unsigned char const pvr_transformer06a[];
extern unsigned char const pvr_transformer07[];


extern unsigned char const pvr_transformer_background2d[];

void M3DLWTransformer_LoadBackground2D(void)
{
	M3DTextureCollection_AddFromMem(&M3DLWTransformer.m_Renderer.m_TextureCollection, "bg2d.pvr",          pvr_transformer_background2d);
}

void M3DLWTransformer_RemoveBackground2D(void)
{
	M3DTextureCollection_Remove(&M3DLWTransformer.m_Renderer.m_TextureCollection, "bg2d.pvr");
}

int M3DLWTransformer_LoadContent(void)
{
	M3DLWTransformer.m_SceneTextureNames       = M3DSplitString_New("bg.pvr;");
	M3DLWTransformer.m_TransformerTextureNames = M3DSplitString_New("robot.pvr,Car02_ra.pvr,Car01_ra.pvr,ray.pvr,Gunfire.pvr;");

  M3DTextureCollection_SetMipLevelStart(1);
	M3DTextureCollection_AddFromMem(&M3DLWTransformer.m_Renderer.m_TextureCollection, "bg.pvr",             pvr_transformer01);
	//M3DTextureCollection_AddFromMem(&M3DLWTransformer.m_Renderer.m_TextureCollection, "bg2.pvr",            pvr_transformer07);
	M3DTextureCollection_SetMipLevelStart(0);
	
	M3DModel_Load(M3DLWTransformer.m_Scene, pod_transformer01, pod_transformer01_length, M3DLWTransformer.m_SceneTextureNames);
	//M3DModel_EnableNode(M3DLWTransformer.m_Scene,"wall", IGV5_FALSE);
	M3DModel_SetMaterialOpacity(M3DLWTransformer.m_Scene, 0.5f);

	return 1;
}

void M3DLWTransformer_LoadContent2(void)
{
	M3DTextureCollection_SetMipLevelStart(1);
	M3DTextureCollection_AddFromMem(&M3DLWTransformer.m_Renderer.m_TextureCollection, "Car01_ra.pvr",       pvr_transformer02);
	M3DTextureCollection_AddFromMem(&M3DLWTransformer.m_Renderer.m_TextureCollection, "Car02_ra.pvr",       pvr_transformer03);
	M3DTextureCollection_AddFromMem(&M3DLWTransformer.m_Renderer.m_TextureCollection, "Car02_ra_a.pvr",     pvr_transformer03a);
	M3DTextureCollection_AddFromMem(&M3DLWTransformer.m_Renderer.m_TextureCollection, "robot.pvr",          pvr_transformer04);
	M3DTextureCollection_AddFromMem(&M3DLWTransformer.m_Renderer.m_TextureCollection, "robot_a.pvr",        pvr_transformer04a);
	M3DTextureCollection_AddFromMem(&M3DLWTransformer.m_Renderer.m_TextureCollection, "ray.pvr",            pvr_transformer05);
	M3DTextureCollection_AddFromMem(&M3DLWTransformer.m_Renderer.m_TextureCollection, "ray_a.pvr",          pvr_transformer05a);
	M3DTextureCollection_AddFromMem(&M3DLWTransformer.m_Renderer.m_TextureCollection, "Gunfire.pvr",        pvr_transformer06);
	M3DTextureCollection_AddFromMem(&M3DLWTransformer.m_Renderer.m_TextureCollection, "Gunfire_a.pvr",      pvr_transformer06a);
	M3DTextureCollection_SetMipLevelStart(0);

	M3DTextureCollection_Map(&M3DLWTransformer.m_Renderer.m_TextureCollection, "Car02_ra.pvr", NULL,                    "Car02_ra_a.pvr");
	M3DTextureCollection_Map(&M3DLWTransformer.m_Renderer.m_TextureCollection, "robot.pvr",    NULL,                    "robot_a.pvr");
	M3DTextureCollection_Map(&M3DLWTransformer.m_Renderer.m_TextureCollection, "ray.pvr",      NULL,                    "ray_a.pvr");
	M3DTextureCollection_Map(&M3DLWTransformer.m_Renderer.m_TextureCollection, "Gunfire.pvr",  NULL,                    "Gunfire_a.pvr");

	M3DModel_Load(M3DLWTransformer.m_Transformer, pod_transformer02, pod_transformer02_length, M3DLWTransformer.m_TransformerTextureNames);

	M3DModel_SetShaderProgram(M3DLWTransformer.m_Transformer, M3D_GOURAUD_SHADER, M3D_NULL_SHADER);

	M3DModel_AddAnimationByFrame(M3DLWTransformer.m_Transformer, "ANIMATE0",    0,    1, 0.5f);
	M3DModel_AddAnimationByFrame(M3DLWTransformer.m_Transformer, "ANIMATE1",    2,   10, 1.0f);		//light on
	M3DModel_AddAnimationByFrame(M3DLWTransformer.m_Transformer, "ANIMATE2",    9,   11, 1.0f);
	M3DModel_AddAnimationByFrame(M3DLWTransformer.m_Transformer, "ANIMATE3",   10,   23, 1.0f);		//light off
	M3DModel_AddAnimationByFrame(M3DLWTransformer.m_Transformer, "ANIMATE4",   23,   45, 1.0f);		//open door
	M3DModel_AddAnimationByFrame(M3DLWTransformer.m_Transformer, "ANIMATE5",   46,  193, 1.0f);		//car -> robot
	M3DModel_AddAnimationByFrame(M3DLWTransformer.m_Transformer, "ANIMATE6",  193,  227, 1.0f);		//robot
	M3DModel_AddAnimationByFrame(M3DLWTransformer.m_Transformer, "ANIMATE7",  293,  487, 1.0f);		//Fire
	M3DModel_AddAnimationByFrame(M3DLWTransformer.m_Transformer, "ANIMATE8",  583,  658, 1.0f);		//robot -> car
	M3DModel_AddAnimationByFrame(M3DLWTransformer.m_Transformer, "ANIMATE9",  658,  691, 1.0f);		//fail
	M3DModel_AddAnimationByFrame(M3DLWTransformer.m_Transformer, "ANIMATE10",  704,  738, 1.0f);	//car enter
	M3DModel_AddAnimationByFrame(M3DLWTransformer.m_Transformer, "ANIMATE11",  513,  573, 1.0f);	//robot enter
	if (M3DLWTransformer.m_Status == 0)
	{
		M3DModel_SetDefaultAnimation(M3DLWTransformer.m_Transformer, 0, 1.0f);
		M3DModel_SetAnimation(M3DLWTransformer.m_Transformer, 10);
	}
	else
	{
		M3DModel_SetDefaultAnimation(M3DLWTransformer.m_Transformer, 6, 1.0f);
		M3DModel_SetAnimation(M3DLWTransformer.m_Transformer, 11);
	}
}

#ifdef __cplusplus
}
#endif

/* end of M3DLWTransformer.c */

