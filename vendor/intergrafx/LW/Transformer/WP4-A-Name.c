//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP4-A
// File        : WP4-A-Name.c
// Description : 手機寵物狗桌布 -- 檔名節點定義
// Author      : Ray
// Create      : 2010-12-01
// Update      : 2011-02-15
//==============================================================================

#include "WP4-A-Name.h"

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif


struct _WP4_A_Name WP4_A_Name = {
	"WP4_A",
	"WP4-A",
	"WP4-A.igf",
	{ "body1.png", "body2.png", "glass.png", "interior.png", "road1.png", "road2.png", "robot.png"},
	{			0,		0x00FF00,			0,				0,				0,			0,				0},
	{"background.png"},

#ifndef IGNORE_ARRAY
	{png_WP4_A_body1, png_WP4_A_body2, png_WP4_A_glass, png_WP4_A_interior, png_WP4_A_road1, png_WP4_A_road2, png_WP4_A_robot},
	{png_WP4_A_back},
#endif

	"Scene Root",
	{ "car", "Glass"},
	{"ANIMATE0", "ANIMATE1", "ANIMATE2", "ANIMATE3", "ANIMATE4", "ANIMATE5", "ANIMATE6", "ANIMATE7", "ANIMATE8", "ANIMATE9", "ANIMATE10", "ANIMATE11"}
};


#ifdef __cplusplus
}
#endif
