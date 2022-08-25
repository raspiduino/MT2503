//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP2-E
// File        : WP2-E-Name.c
// Description : 手機白日夢桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-12-08
// Update      : 2011-02-15
//==============================================================================

#include "WP2-E-Name.h"

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

struct _WP2_E_Name WP2_E_Name = {
	"WP2_E",			//WP_Name
	"WP2-E",			//file_folder
	"WP2-E.igf",		//file_igf
	{ "cash_01.png", "cash_02.png", "cash_03.png", "Cloud1.png", "Cloud2.png", "Cloud3.png", "Cloud4.png", "plane.png" },								//file_bmp[]
	{				0,				0,				0,				0,				0,			0,				0,				0x00FF00 },																				//keycolor[]
	{ "WP2-E-back.png" },		//file_back[]

#ifndef IGNORE_ARRAY
	{ png_WP2_E_cash_01, png_WP2_E_cash_02, png_WP2_E_cash_03, png_WP2_E_Cloud1, png_WP2_E_Cloud2, png_WP2_E_Cloud3, png_WP2_E_Cloud4, png_WP2_E_plane },	//bmp_array[COUNT_BMP]
	{ png_WP2_E_back },	//back_array[COUNT_BACK]
#endif

	"Scene root",		//node_name_Obj_root
	{ "cash01", "cash04", "cash07", "cash11", "cash14", "cash16", "cash19", "cash22", "cash25", "cash28", "cash31", "cash34", "cash37", "cash40", "cash43", "cash46", "cash49", "cash52", "cash55", "cash58"},	//node_name_Obj
	{ "track01", "track02", "track03", "track04", "track05", "track06", "track07", "track08", "track09", "track10", "track11", "track12", "track13", "track14", "track15", "track16", "track17", "track18", "track19", "track20" },	//node_name_Obj
//	{ "money01", "money02", "money03", "money04", "money05", "money06", "money07", "money08", "money09", "money10", "money11", "money12", "money13", "money14", "money15", "money16", "money17", "money18", "money19", "money20" }	//node_name_Obj
	{"cloud01", "cloud02", "cloud03", "cloud04"},
	{"cmove01", "cmove02", "cmove03", "cmove04"}
};

#ifdef __cplusplus
}
#endif
