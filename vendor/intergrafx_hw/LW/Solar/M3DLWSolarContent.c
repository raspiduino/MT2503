//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWSolar
// File        : M3DLWSolar.c
// Description : IGV5 LW Solar
// Author      : Ray
// Create      : 2011-08-25
// Update      : 2011-12-23
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWSolar.h"
#include "M3DTextureManager.h"

#if defined(__MMI_MAINLCD_240X320__)
#include "pvr_solar_240x320.h"
#elif defined(__MMI_MAINLCD_240X400__)
#include "pvr_solar_240x400.h"
#elif defined(__MMI_MAINLCD_320X480__)
#include "pvr_solar_320x480.h"
#elif defined(__MMI_MAINLCD_480X800__)
#include "pvr_solar_480x800.h"
#else
#include "pvr_solar_320x480.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern M3DLWSolarApp M3DLWSolar;

extern unsigned char const pod_solar01[];
extern unsigned char const pod_solar02[];
extern unsigned char const pod_solar03[];
extern unsigned char const pod_solar04[];
extern unsigned char const pod_solar05[];
extern long pod_solar01_length;
extern long pod_solar02_length;
extern long pod_solar03_length;
extern long pod_solar04_length;
extern long pod_solar05_length;

extern unsigned char const pvr_solar01[];
extern unsigned char const pvr_solar02[];
extern unsigned char const pvr_solar02a[];
extern unsigned char const pvr_solar03[];
extern unsigned char const pvr_solar04[];
extern unsigned char const pvr_solar05[];
extern unsigned char const pvr_solar05a[];
extern unsigned char const pvr_solar06[];
extern unsigned char const pvr_solar06a[];
extern unsigned char const pvr_solar07[];
extern unsigned char const pvr_solar07a[];
extern unsigned char const pvr_solar08[];
extern unsigned char const pvr_solar08n[];
extern unsigned char const pvr_solar09[];
extern unsigned char const pvr_solar10[];
extern unsigned char const pvr_solar11[];
extern unsigned char const pvr_solar12[];
extern unsigned char const pvr_solar13[];
extern unsigned char const pvr_solar14[];
extern unsigned char const pvr_solar14a[];
extern unsigned char const pvr_solar15[];
extern unsigned char const pvr_solar16[];
extern unsigned char const pvr_solar16a[];
extern unsigned char const pvr_solar17[];
extern unsigned char const pvr_solar18[];
extern unsigned char const pvr_solar20[];
extern unsigned char const pvr_solar20a[];

extern unsigned char const pvr_solar_background2d[];

void M3DLWSolar_LoadBackground2D(void)
{
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "bg2d.pvr",          pvr_solar_background2d);
}

void M3DLWSolar_RemoveBackground2D(void)
{
	M3DTextureCollection_Remove(&M3DLWSolar.m_Renderer.m_TextureCollection, "bg2d.pvr");
}

int M3DLWSolar_LoadContent(void)
{
	M3DLWSolar.m_SceneTextureNames  = M3DSplitString_New("Galaxy_BG.pvr,Galaxy01_02.pvr,Galaxy03.pvr;");
	M3DLWSolar.m_PlanetTextureNames = M3DSplitString_New("Mercury.pvr,Venus.pvr,Earth.pvr,Earth_Cloud.pvr,Moon.pvr,mars.pvr,Jupiter.pvr,Saturn.pvr,Saturn_1.pvr,Uranus.pvr,Neptune.pvr,sun.pvr,Sunfire.pvr,Glow.pvr,Tube_Glow.pvr;");
	M3DLWSolar.m_TubeTextureNames   = M3DSplitString_New("Tube_Glow.pvr;");

	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Earth.pvr",              pvr_solar01);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Earth_Cloud.pvr",        pvr_solar02);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Earth_Cloud_a.pvr",      pvr_solar02a);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Galaxy_BG.pvr",          pvr_solar03);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Galaxy_BG2.pvr",         pvr_solar04);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Galaxy01_02.pvr",           pvr_solar05);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Galaxy01_02_a.pvr",         pvr_solar05a);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Galaxy03.pvr",           pvr_solar06);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Galaxy03_a.pvr",         pvr_solar06a);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Glow.pvr",               pvr_solar07);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Glow_a.pvr",             pvr_solar07a);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Jupiter.pvr",            pvr_solar08);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "mars.pvr",               pvr_solar09);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Mercury.pvr",            pvr_solar10);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Moon.pvr",               pvr_solar11);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Neptune.pvr",            pvr_solar12);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Saturn.pvr",             pvr_solar13);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Saturn_1.pvr",           pvr_solar14);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Saturn_1_a.pvr",         pvr_solar14a);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "sun.pvr",                pvr_solar15);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Sunfire.pvr",            pvr_solar16);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Sunfire_a.pvr",          pvr_solar16a);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Uranus.pvr",             pvr_solar17);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Venus.pvr",              pvr_solar18);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Tube_Glow.pvr",          pvr_solar20);
	M3DTextureCollection_AddFromMem(&M3DLWSolar.m_Renderer.m_TextureCollection, "Tube_Glow_a.pvr",        pvr_solar20a);

	M3DTextureCollection_MapAlpha(&M3DLWSolar.m_Renderer.m_TextureCollection, "Earth_Cloud.pvr",      "Earth_Cloud_a.pvr");
	M3DTextureCollection_MapAlpha(&M3DLWSolar.m_Renderer.m_TextureCollection, "Galaxy01_02.pvr",      "Galaxy01_02_a.pvr");
	M3DTextureCollection_MapAlpha(&M3DLWSolar.m_Renderer.m_TextureCollection, "Galaxy03.pvr",         "Galaxy03_a.pvr");
	M3DTextureCollection_MapAlpha(&M3DLWSolar.m_Renderer.m_TextureCollection, "Glow.pvr",             "Glow_a.pvr");
	//M3DTextureCollection_MapAlpha(&M3DLWSolar.m_Renderer.m_TextureCollection, "Saturn_1.pvr",         "Saturn_1_a.pvr");
	M3DTextureCollection_MapAlpha(&M3DLWSolar.m_Renderer.m_TextureCollection, "Sunfire.pvr",          "Sunfire_a.pvr");
	M3DTextureCollection_MapAlpha(&M3DLWSolar.m_Renderer.m_TextureCollection, "Tube_Glow.pvr",        "Tube_Glow_a.pvr");

	M3DTextureCollection_AddUVAnim(&M3DLWSolar.m_Renderer.m_TextureCollection, "Sunfire.pvr");
	M3DTextureCollection_AddUVAnim(&M3DLWSolar.m_Renderer.m_TextureCollection, "Glow.pvr");
	M3DTextureCollection_AddUVAnim(&M3DLWSolar.m_Renderer.m_TextureCollection, "sun.pvr");

	M3DModel_Load(M3DLWSolar.m_Scene,  pod_solar01, pod_solar01_length, M3DLWSolar.m_SceneTextureNames);
	M3DModel_Load(M3DLWSolar.m_Planet, pod_solar02, pod_solar02_length, M3DLWSolar.m_PlanetTextureNames);
	M3DModel_Load(M3DLWSolar.m_Tube,   pod_solar03, pod_solar03_length, M3DLWSolar.m_TubeTextureNames);

	M3DModel_SetShaderProgram(M3DLWSolar.m_Planet, M3D_GOURAUD_SHADER, M3D_NULL_SHADER);
	M3DModel_SetShaderProgram(M3DLWSolar.m_Tube, M3D_GOURAUD_SHADER, M3D_NULL_SHADER);
	M3DModel_SetShaderProgramByNodeName(M3DLWSolar.m_Planet, "Sunfire01", M3D_UV_DISPLACEMENT_SHADER);
	M3DModel_SetShaderProgramByNodeName(M3DLWSolar.m_Planet, "Sunfire02", M3D_UV_DISPLACEMENT_SHADER);
	M3DModel_SetShaderProgramByNodeName(M3DLWSolar.m_Planet, "Sun", M3D_UV_DISPLACEMENT_SHADER);
	M3DTextureCollection_SetUVAnimTimeFactor(&M3DLWSolar.m_Renderer.m_TextureCollection, 0.2f, 0.0f);

	return 1;
}

#ifdef __cplusplus
}
#endif

/* end of M3DLWSolar.c */

