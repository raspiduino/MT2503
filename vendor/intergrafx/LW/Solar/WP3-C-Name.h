//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3-C
// File        : WP3-C-Name.h
// Description : 手機太陽系桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-11-16
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP3_C_NAME_H__
#define __WP3_C_NAME_H__

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

extern unsigned char igf_WP3_C[];
extern unsigned char png_WP3_C_bg[];
extern unsigned char png_WP3_C_mars[];
extern unsigned char png_WP3_C_Mer[];
extern unsigned char png_WP3_C_Neptune[];
extern unsigned char png_WP3_C_Neptunemer[];
extern unsigned char png_WP3_C_stoneA[];
extern unsigned char png_WP3_C_sun1[];
extern unsigned char png_WP3_C_venusmoon[];
extern unsigned char png_WP3_C_Earth1[];
extern unsigned char png_WP3_C_Earth2[];
extern unsigned char png_WP3_C_Jupiter1[];
extern unsigned char png_WP3_C_line[];
extern unsigned char png_WP3_C_Saturn[];
extern unsigned char png_WP3_C_Uranus[];

#define COUNT_BACK	1
#define COUNT_BMP	13
#define COUNT_OBJ	8
#define COUNT_PATH	0
#define COUNT_STONE 1

struct _WP3_C_Name
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
	const char *node_name_Stone[COUNT_STONE];
};

extern struct _WP3_C_Name WP3_C_Name;

#define WP_NameStruct WP3_C_Name


#ifdef __cplusplus
}
#endif

#endif