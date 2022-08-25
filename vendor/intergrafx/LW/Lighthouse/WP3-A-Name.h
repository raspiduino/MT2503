//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3-A
// File        : WP3-A-Name.h
// Description : 手機燈塔桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-11-16
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP3_A_NAME_H__
#define __WP3_A_NAME_H__

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

extern unsigned char const png_WP3_A_back[];

extern unsigned char igf_WP3_A[];
extern unsigned char png_WP3_A_bird[];
extern unsigned char png_WP3_A_ray[];
extern unsigned char png_WP3_A_whale[];
extern unsigned char png_WP3_A_island[];
extern unsigned char png_WP3_A_mountain[];
extern unsigned char png_WP3_A_sea1[];
extern unsigned char png_WP3_A_sea2[];
extern unsigned char png_WP3_A_sea3[];
extern unsigned char png_WP3_A_sea4[];
extern unsigned char png_WP3_A_sea5[];
extern unsigned char png_WP3_A_sea6[];
extern unsigned char png_WP3_A_sea7[];
extern unsigned char png_WP3_A_sea8[];
extern unsigned char png_WP3_A_sky[];
extern unsigned char png_WP3_A_tower[];
extern unsigned char png_WP3_A_trees[];

#define COUNT_BACK	1
#define COUNT_BMP	16
#define COUNT_OBJ	3
#define COUNT_PATH	3
#define COUNT_WHALE_POSITION	10

struct _WP3_A_Name
{
	char *WP_Name;
	char *file_folder;
	char *file_igf;
	char *file_bmp[COUNT_BMP];
	int keycolor[COUNT_BMP];
	char *file_back[COUNT_BACK];
#ifndef IGNORE_ARRAY
	const unsigned char *bmp_array[COUNT_BMP];
	const unsigned char *back_array[COUNT_BACK];
#endif
	const char *node_name_Obj_root;
	const char *node_name_Obj[COUNT_OBJ];
	const char *path_name_Obj[COUNT_PATH];
	const char *node_name_WhalePosition[COUNT_WHALE_POSITION];
};

extern struct _WP3_A_Name WP3_A_Name;

#define WP_NameStruct WP3_A_Name


#ifdef __cplusplus
}
#endif

#endif