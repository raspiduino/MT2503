//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3-C
// File        : WP3-C-Name.c
// Description : 手機太陽系桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-11-30
// Update      : 2011-02-15
//==============================================================================

#include "WP3-C-Name.h"

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

struct _WP3_C_Name WP3_C_Name = {
	"WP3_C",
	"WP3-C-SolarSystem",
	"WP3-C.igf",
	{ "mars.png","Mer.png","Neptune.png","Neptunemer.png","stoneA.png", "sun1.png","venusmoon.png","WP3-C-Earth1.png","WP3-C-Earth2.png", "WP3-C-Jupiter1.png","WP3-C-line.png","WP3-C-Saturn.png","WP3-C-Uranus.png" },
	{ 0, 0, 0, 0, 0, 0, 255, 0, 0, 0, 255, 0, 0 },
	{ "WP3-C-bg.png" },

#ifndef IGNORE_ARRAY
	{ png_WP3_C_mars, png_WP3_C_Mer, png_WP3_C_Neptune, png_WP3_C_Neptunemer, png_WP3_C_stoneA, png_WP3_C_sun1, png_WP3_C_venusmoon, png_WP3_C_Earth1, png_WP3_C_Earth2, png_WP3_C_Jupiter1, png_WP3_C_line, png_WP3_C_Saturn, png_WP3_C_Uranus },
	{ png_WP3_C_bg },
#endif

	"Scene Root",
	{"mercury_g", "venus_g", "earth_g", "mars_g", "jupiter_g", "saturn_g", "uranus_g", "neptune_g"},
	{"Stone_all"}
};

#ifdef __cplusplus
}
#endif
