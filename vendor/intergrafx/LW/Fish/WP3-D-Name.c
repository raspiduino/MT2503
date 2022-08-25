//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3-D
// File        : WP3-D-Name.c
// Description : 手機魚缸桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-11-16
// Update      : 2011-02-15
//==============================================================================

#include "WP3-D-Name.h"

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif


struct _WP3_D_Name WP3_D_Name = {
	"WP3_D",
	"WP3-D",
	"WP3-D.igf",
	{ "WP3-D-fish1.png", "WP3-D-fish2.png", "WP3-D-fish3.png", "WP3-D-fish4.png", "WP3-D-plants.png", "WP3-D-bub.png", "WP3-D-sub.png"},
	{ 255*256, 255*256, 255*256,255*256,255*256, 255*256,255*256},
	{ ""},

#ifndef IGNORE_ARRAY
	{ png_WP3_D_fish1, png_WP3_D_fish2, png_WP3_D_fish3, png_WP3_D_fish4, png_WP3_D_plants, png_WP3_D_bub , png_WP3_D_sub},
	{ png_WP3_D_back},
#endif

	"Scene Root",
	{ "sub_dummy", "fish1_dummy", "fish2_dummy", "fish3_dummy", "fish4_dummy" },
	{ "sub", "fish1", "fish2", "fish3", "fish4" },
	{ "swim_dummy_sub", "swim_dummy1", "swim_dummy2", "swim_dummy3", "swim_dummy4", "swim_dummy5", "swim_dummy6", "swim_dummy7", "swim_dummy8", "swim_eat_dummy1", "swim_eat_dummy2" ,"swim_eat_dummy3", "swim_eat_dummy04"},
	//{ "route_1", "route_2", "route_3", "route_4", "route_5", "route_6", "route_7", "route_8" }
};


#ifdef __cplusplus
}
#endif
