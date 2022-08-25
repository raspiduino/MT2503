//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP2-B
// File        : WP2-B-Name.c
// Description : 手機搔女孩桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-12-06
// Update      : 2011-02-15
//==============================================================================

#include "WP2-B-Name.h"

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

struct _WP2_B_Name WP2_B_Name = {
	"WP2_B",
	"WP2-B",
	"WP2-B.igf",
	{"body.png", "body01.png", "head.png"},
	{		0,				0,		0x00FF00},
	{"WP2-B-back.png"},

#ifndef IGNORE_ARRAY
	{ png_WP2_B_body, png_WP2_B_body01, png_WP2_B_head},
	{ png_WP2_B_back },
#endif
	"girl",
	{"g_face", "g_hair", "g_hands01", "g_hands02", "g_hand01", "g_hand02", "g_body01", "g_body02", "g_foot"},
	{"Bip01", "Bip01 Spine", "Bip01 Spine1", "Bip01 Head", "Bip01 Neck", "Bip01 L Clavicle", "Bip01 L UpperArm", "Bip01 L Forearm", "Bip01 L Hand", "Bip01 R Clavicle", "Bip01 R UpperArm", "Bip01 R Forearm", "Bip01 R Hand", "Bip01 L Pelvis", "Bip01 L Thigh", "Bip01 L Calf", "Bip01 L Foot", "Bip01 R Pelvis", "Bip01 R Thigh", "Bip01 R Calf"},
	{1, 1, 3, 2, 3, 2, 5, 4, -1}
};

#ifdef __cplusplus
}
#endif
