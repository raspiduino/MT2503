//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP1-A
// File        : WP1-A-Name.h
// Description : 含羞草桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-11-05
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP1_A_NAME_H__
#define __WP1_A_NAME_H__

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif
extern unsigned char png_WP1_A_back[];

extern unsigned char igf_WP1_A[];
extern unsigned char png_WP1_A_bird[];
extern unsigned char png_WP1_A_Flowerpot[];
extern unsigned char png_WP1_A_flowerR[];
extern unsigned char png_WP1_A_flowerY[];
extern unsigned char png_WP1_A_jin[];
extern unsigned char png_WP1_A_Leaf[];
extern unsigned char png_WP1_A_Soil[];
extern unsigned char png_WP1_A_wellL[];
extern unsigned char png_WP1_A_b1[];
extern unsigned char png_WP1_A_b2[];
extern unsigned char png_WP1_A_b3[];

#define COUNT_BACK	1
#define COUNT_BMP	11
#define COUNT_OBJ	12
#define COUNT_FLOWER 3
#define COUNT_BIRD	1
#define COUNT_PATH	1

struct _WP1_A_Name
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
	const char *node_name_Flower[COUNT_FLOWER];
	const char *node_name_Bird[COUNT_BIRD];
	const char *node_name_Path[COUNT_PATH];
};

extern struct _WP1_A_Name WP1_A_Name;

#define WP_NameStruct WP1_A_Name

#ifdef __cplusplus
}
#endif

#endif