//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP2-B
// File        : WP2-B-Name.h
// Description : 手機搔女孩桌布 -- 檔名節點定義
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

//extern unsigned char const bmp_back[];

extern unsigned char igf_WP2_B[];
extern unsigned char png_WP2_B_body[];
extern unsigned char png_WP2_B_body01[];
extern unsigned char png_WP2_B_head[];
extern unsigned char png_WP2_B_back[];

#define COUNT_BMP_SLOT	20

#define COUNT_BACK	1
#define COUNT_BMP	3
#define COUNT_BONE	20
#define COUNT_OBJ	9

struct _WP2_B_Name
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
	const char *node_name_Bone[COUNT_BONE];
	int map_ani[COUNT_OBJ];
};

extern struct _WP2_B_Name WP2_B_Name;

#define WP_NameStruct WP2_B_Name


#ifdef __cplusplus
}
#endif

#endif