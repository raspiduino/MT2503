//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP2-C
// File        : WP2-C-Name.h
// Description : 手機機械鐘桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-12-08
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP2_C_NAME_H__
#define __WP2_C_NAME_H__

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

extern unsigned char igf_WP2_C[];
extern unsigned char png_bg2[];
extern unsigned char png_WP2_C_P2_01[];
extern unsigned char png_WP2_C_P2_01_1[];
extern unsigned char png_WP2_C_P2_02_1[];
extern unsigned char png_WP2_C_P2_02_2[];
extern unsigned char png_WP2_C_P2_03[];
extern unsigned char png_WP2_C_P2_04[];
extern unsigned char png_WP2_C_P2_05[];
extern unsigned char png_WP2_C_P2_06[];
extern unsigned char png_WP2_C_P2_07[];
extern unsigned char png_WP2_C_P2_08[];
extern unsigned char png_WP2_C_P2_09_1[];
extern unsigned char png_WP2_C_P2_09_2[];
extern unsigned char png_WP2_C_P2_09_3[];
extern unsigned char png_WP2_C_P2_09_4[];



#define COUNT_BACK	1
#define COUNT_BMP	14
#define COUNT_OBJ	5
#define COUNT_PATH	0

struct _WP2_C_Name
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

extern struct _WP2_C_Name WP2_C_Name;

#define WP_NameStruct WP2_C_Name


#ifdef __cplusplus
}
#endif

#endif
