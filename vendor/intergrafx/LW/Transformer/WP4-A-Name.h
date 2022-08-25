//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP4-A
// File        : WP4-A-Name.h
// Description : 手機寵物狗桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-12-01
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP4_A_NAME_H__
#define __WP4_A_NAME_H__

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

//png_WP4_A_back1, png_WP4_A_bg, png_WP4_A_bg2, png_WP4_A_bg3, png_WP4_A_body1, png_WP4_A_body2, png_WP4_A_floor, png_WP4_A_glass, png_WP4_A_interior, png_WP4_A_robot, png_WP4_A_up
//png_WP4_A_background
extern unsigned char igf_WP4_A[];
extern unsigned char png_WP4_A_body1[];
extern unsigned char png_WP4_A_body2[];
extern unsigned char png_WP4_A_glass[];
extern unsigned char png_WP4_A_interior[];
extern unsigned char png_WP4_A_road1[];
extern unsigned char png_WP4_A_road2[];
extern unsigned char png_WP4_A_robot[];
extern unsigned char png_WP4_A_back[];



#define COUNT_BACK	1
#define COUNT_BMP	7
#define COUNT_OBJ	2
#define COUNT_PATH	1
#define COUNT_ANI	12

struct _WP4_A_Name
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
	const char *ani_name[COUNT_ANI];
};

extern struct _WP4_A_Name WP4_A_Name;

#define WP_NameStruct WP4_A_Name

#ifdef __cplusplus
}
#endif

#endif
