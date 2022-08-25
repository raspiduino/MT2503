//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP2-E
// File        : WP2-E-Name.h
// Description : 手機白日夢桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-12-08
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP2_E_NAME_H__
#define __WP2_E_NAME_H__

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

extern unsigned char const png_WP2_E_back[];

extern unsigned char igf_WP2_E[];
extern unsigned char png_WP2_E_cash_01[];
extern unsigned char png_WP2_E_cash_02[];
extern unsigned char png_WP2_E_cash_03[];
extern unsigned char png_WP2_E_Cloud1[];
extern unsigned char png_WP2_E_Cloud2[];
extern unsigned char png_WP2_E_Cloud3[];
extern unsigned char png_WP2_E_Cloud4[];
extern unsigned char png_WP2_E_plane[];

#define COUNT_BACK	1
#define COUNT_BMP	8
#define COUNT_OBJ	20
#define COUNT_PATH	20
#define COUNT_CLOUD 4
#define COUNT_CLOUDPATH	4

struct _WP2_E_Name
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
	const char *cloud_name_Obj[COUNT_CLOUD];
	const char *cloudpath_name_Obj[COUNT_CLOUDPATH];
};

extern struct _WP2_E_Name WP2_E_Name;

#define WP_NameStruct WP2_E_Name


#ifdef __cplusplus
}
#endif

#endif
