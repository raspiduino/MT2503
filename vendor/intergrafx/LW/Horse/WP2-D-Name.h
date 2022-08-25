//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP2-D
// File        : WP2-D-Name.h
// Description : 手機百駿圖桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-12-06
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP2_D_NAME_H__
#define __WP2_D_NAME_H__

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif


extern unsigned char igf_WP2_D[];
extern unsigned char png_WP2_D_back2[];
extern unsigned char png_WP2_D_bird[];
extern unsigned char png_WP2_D_hair1[];
extern unsigned char png_WP2_D_hair2[];
extern unsigned char png_WP2_D_horse2[];
extern unsigned char png_WP2_D_horse3[];
extern unsigned char png_WP2_D_horse4[];
extern unsigned char png_WP2_D_tree2[];
extern unsigned char png_WP2_D_wave[];


#define COUNT_BACK	1
#define COUNT_BMP	8
#define COUNT_OBJ	7
#define COUNT_PATH	9

struct _WP2_D_Name
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
	int map_ani[COUNT_PATH];
};

extern struct _WP2_D_Name WP2_D_Name;

#define WP_NameStruct WP2_D_Name

#ifdef __cplusplus
}
#endif

#endif