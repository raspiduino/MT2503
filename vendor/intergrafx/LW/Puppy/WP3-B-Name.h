//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3-B
// File        : WP3-B-Name.h
// Description : 手機寵物狗桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-12-01
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP3_B_NAME_H__
#define __WP3_B_NAME_H__

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

extern unsigned char const png_WP3_B_bg[];
extern unsigned char const png_WP3_B_bg2[];

extern unsigned char igf_WP3_B[];
extern unsigned char png_WP3_B_dog[];
extern unsigned char png_WP3_B_prop[];
extern unsigned char png_WP3_B_shadow[];
extern unsigned char png_WP3_B_smile[];

#define COUNT_BACK	1
#define COUNT_BMP	4
#define COUNT_OBJ	2
#define COUNT_PATH	8

struct _WP3_B_Name
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
};

extern struct _WP3_B_Name WP3_B_Name;

#define WP_NameStruct WP3_B_Name

#ifdef __cplusplus
}
#endif

#endif
