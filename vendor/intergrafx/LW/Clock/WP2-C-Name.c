//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP2-C
// File        : WP2-C-Name.c
// Description : 手機機械鐘桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-12-08
// Update      : 2011-02-15
//==============================================================================

#include "WP2-C-Name.h"

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

struct _WP2_C_Name WP2_C_Name = {
	"WP2_C",			//WP_Name
	"WP2-C",			//file_folder
	"WP2-C.igf",		//file_igf
	{ "P2-01.png", "P2-01-1.png", "P2-02-1.png", "P2-02-2.png", "P2-03.png", "P2-04.png", "P2-05.png", "P2-06.png", "P2-07.png", "P2-08.png", "P2-09-1.png", "P2-09-2.png", "P2-09-3.png", "P2-09-4.png"},								//file_bmp[]
	{ 255*256, 255*256, 255*256, 255*256, 255*256, 255*256, 255*256, 255*256, 255*256, 255*256, 255*256, 255*256,255*256 },																				//keycolor[]
	{ "bg2.png" },		//file_back[]

#ifndef IGNORE_ARRAY
	{ png_WP2_C_P2_01, png_WP2_C_P2_01_1, png_WP2_C_P2_02_1, png_WP2_C_P2_02_2, png_WP2_C_P2_03, png_WP2_C_P2_04, png_WP2_C_P2_05, png_WP2_C_P2_06, png_WP2_C_P2_07, png_WP2_C_P2_08, png_WP2_C_P2_09_1, png_WP2_C_P2_09_2, png_WP2_C_P2_09_3, png_WP2_C_P2_09_4 },	//bmp_array[COUNT_BMP]
	{ png_bg2 },	//back_array[COUNT_BACK]
#endif

	"Scene root",		//node_name_Obj_root
	{ "P2-0601", "P2-0600", "P2-0602", "Gear","P2-07" }	//node_name_Obj
};

#ifdef __cplusplus
}
#endif
