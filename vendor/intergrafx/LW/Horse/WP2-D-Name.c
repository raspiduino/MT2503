//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP2-D
// File        : WP2-D-Name.c
// Description : 手機百駿圖桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-12-06
// Update      : 2011-02-15
//==============================================================================

#include "WP2-D-Name.h"

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

struct _WP2_D_Name WP2_D_Name = {
	"WP2_D",
	"WP2-D",
	"WP2-D.igf",
	{ "hair1.png", "hair2.png", "horse2.png", "horse3.png", "horse4.png", "tree2.png", "wave.png", "bird.png" },
	{ 255*256, 255*256, 255*256, 255*256, 255*256, 255*256, 255*256, 255*256},
	{ "back2.png" },

#ifndef IGNORE_ARRAY
	{ png_WP2_D_hair1, png_WP2_D_hair2, png_WP2_D_horse2, png_WP2_D_horse3, png_WP2_D_horse4, png_WP2_D_tree2, png_WP2_D_wave, png_WP2_D_bird },
	{ png_WP2_D_back2 },
#endif

	"Scene Root",
	{ "horse01", "horse02", "horse03", "horse04", "horse05" , "bird","wave"},
	{ "track02", "track03", "track04", "track05", "track06", "track07", "track08", "track09", "birdpath" },
	{ 9, 9, 9, 8, 5, 5, 6, 7, 0}
//const char *path_name_Obj[COUNT_PATH] = { "route_1", "route_2", "route_3", "route_4", "route_5", "route_6", "route_7", "route_8" };
};

#ifdef __cplusplus
}
#endif
