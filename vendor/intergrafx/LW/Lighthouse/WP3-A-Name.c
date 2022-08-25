//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3-A
// File        : WP3-A-Name.c
// Description : 手機燈塔桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-11-29
// Update      : 2011-02-15
//==============================================================================

#include "WP3-A-Name.h"

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

struct _WP3_A_Name WP3_A_Name = {
	"WP3_A",
	"WP3-A-LightTower",
	"WP3-A.igf",
	{ "WP3-A-island.png", "WP3-A-mountain.png", "WP3-A-sky.png", "WP3-A-tower.png", "WP3-A-trees.png", "WP3-A-sea1.png", "WP3-A-sea2.png", "WP3-A-sea3.png", "WP3-A-sea4.png", "WP3-A-sea5.png", "WP3-A-sea6.png", "WP3-A-sea8.png", "WP3-A-sea7.png", "WP3-A-bird.png", "WP3-A-ray.png", "WP3-A-whale.png" },
	{					0,						0,				0,						0,			255*256,					0,					0,					0,					0,				0,					0,					0,					0,			255*256,					0,					255*256 },//128*256(ray)
	{ "" },

#ifndef IGNORE_ARRAY
	{ png_WP3_A_island, png_WP3_A_mountain, png_WP3_A_sky, png_WP3_A_tower, png_WP3_A_trees, png_WP3_A_sea1, png_WP3_A_sea2, png_WP3_A_sea3, png_WP3_A_sea4, png_WP3_A_sea5, png_WP3_A_sea6, png_WP3_A_sea8, png_WP3_A_sea7, png_WP3_A_bird, png_WP3_A_ray, png_WP3_A_whale },
	{ png_WP3_A_back },
#endif

	"Scene Root",
	{ "ray_dummy", "whale_A", "Bird_All" },
	{ "bird_route1", "bird_route2", "bird_route3"},
	{ "whale_dummy01", "whale_dummy02", "whale_dummy03", "whale_dummy04", "whale_dummy05", "whale_dummy06", "whale_dummy07", "whale_dummy08", "whale_dummy09", "whale_dummy10" }
};


#ifdef __cplusplus
}
#endif
