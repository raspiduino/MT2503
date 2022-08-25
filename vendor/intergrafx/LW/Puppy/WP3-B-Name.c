//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3-B
// File        : WP3-B-Name.c
// Description : 手機寵物狗桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-12-01
// Update      : 2011-02-15
//==============================================================================

#include "WP3-B-Name.h"

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif


struct _WP3_B_Name WP3_B_Name = {
	"WP3_B",
	"WP3-B-Dog",
	"WP3-B.igf",
	{ "WP3-B-dog.png", "WP3-B-prop.png","shadow.png", "smile.png" },
	{ 0, 0 , 0,0},
	{ "WP3-B-bg.png" },

#ifndef IGNORE_ARRAY
	{ png_WP3_B_dog, png_WP3_B_prop, png_WP3_B_shadow,png_WP3_B_smile},
	{ png_WP3_B_bg },
#endif

	"Scene Root",
	{ "Dog_global_ctrl","dog"}
};


#ifdef __cplusplus
}
#endif
