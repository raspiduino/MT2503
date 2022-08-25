//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3-D
// File        : WP3-D-Name.h
// Description : 手機魚缸桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-11-16
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP3_D_NAME_H__
#define __WP3_D_NAME_H__

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif


extern unsigned char const png_WP3_D_back[];



extern unsigned char igf_WP3_D[];
extern unsigned char png_WP3_D_fish1[];
extern unsigned char png_WP3_D_sub[];
extern unsigned char png_WP3_D_bub[];
extern unsigned char png_WP3_D_fish2[];
extern unsigned char png_WP3_D_fish3[];
extern unsigned char png_WP3_D_plants[];
extern unsigned char png_WP3_D_fish4[];


#define COUNT_BACK	1
#define COUNT_BMP	7
#define COUNT_OBJ		5
#define COUNT_PATH	13


struct _WP3_D_Name
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
	const char *node_name_ObjBody[COUNT_OBJ];
	const char *path_name_Obj[COUNT_PATH];
};

extern struct _WP3_D_Name WP3_D_Name;

#define WP_NameStruct WP3_D_Name

#ifdef __cplusplus
}
#endif

#endif