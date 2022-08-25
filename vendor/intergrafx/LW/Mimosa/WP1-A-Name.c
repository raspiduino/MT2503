//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP1-A
// File        : WP1-A-Name.c
// Description : 含羞草桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-11-05
// Update      : 2011-02-15
//==============================================================================

#include "WP1-A-Name.h"

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif


struct _WP1_A_Name WP1_A_Name = {
	"WP1_A",
	"WP1-A",
	"WP1-A.igf",
	{ "WP1-A-Flowerpot.png", "WP1-A-flowerR.png", "WP1-A-flowerY.png", "WP1-A-jin.png", "WP1-A-Leaf.png", "WP1-A-Soil.png", "WP1-A-wellL.png", "WP1-A-bird.png", "WP1-A-b1.png", "WP1-A-b2.png", "WP1-A-b3.png"},
	{ 0, 255*256, 255*256, 0, 255*256, 0, 0, 255*256, 255*256, 255*256, 255*256},
	{ "WP1-A-back.png" },

#ifndef IGNORE_ARRAY
	{ png_WP1_A_Flowerpot, png_WP1_A_flowerR, png_WP1_A_flowerY, png_WP1_A_jin, png_WP1_A_Leaf, png_WP1_A_Soil, png_WP1_A_wellL, png_WP1_A_bird, png_WP1_A_b1, png_WP1_A_b2, png_WP1_A_b3},
	{ png_WP1_A_back },
#endif

	"main stem",
	{ "LeafA1", "LeafA2", "LeafA3", "LeafA4", "LeafB1", "LeafB2", "LeafB3", "LeafB4", "LeafC1", "LeafC2", "LeafC3", "LeafC4"},
	{ "stemFlowerA", "stemFlowerB", "stemFlowerC"},
	{"Birdgroup"},
	{"bird_route1"}
};

#ifdef __cplusplus
}
#endif
