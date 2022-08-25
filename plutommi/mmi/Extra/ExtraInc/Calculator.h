/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * Calculator.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines constant, enum value, structure, and function prototypes for calculator application.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      Calculator.h
   Author:        manju
   Date Created:  June-21-2003
   Contains:      Calculator
**********************************************************************************/
#ifndef _MMI_CALCULATOR_H
#define _MMI_CALCULATOR_H

//#if defined(__MMI_CALCULATOR__) && !defined(__COSMOS_MMI_PACKAGE__)
#if defined(__MMI_CALCULATOR__) 
#include "MMI_features.h"
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "GlobalResDef.h"
#include "mmi_frm_input_gprot.h"
#include "wgui.h"
#ifndef __RESOURCE_GEN_
#include "mmi_rp_app_calculator_def.h"
#endif

#if 0
#ifdef __MMI_MAINLCD_96X64__
/* under construction !*/
#endif
#endif

#if ((defined(__MMI_MAINLCD_240X320__)||defined(__MMI_MAINLCD_240X400__)||defined(__MMI_MAINLCD_320X240__)||defined(__MMI_MAINLCD_320X480__)) && defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
	#ifndef __CALC_FTE_SLIM_USE_SLICE_RES__
	#define __CALC_FTE_SLIM_USE_SLICE_RES__
	#endif
#endif
#if ((defined(__MMI_MAINLCD_128X160__)||defined(__MMI_MAINLCD_176X220__)||defined(__MMI_MAINLCD_240X320__)||defined(__MMI_MAINLCD_240X400__)||defined(__MMI_MAINLCD_320X240__)||defined(__MMI_MAINLCD_320X480__)) && !defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_TOUCH_SCREEN__))
#ifndef __CALC_SLIM_FOR_61__
#define __CALC_SLIM_FOR_61__
#endif
#endif
/* 
 * Define
 */
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_SLIM_IMG_RES__)
//#ifndef __CALC_96_64_SOLUTION_SLIM__
#ifndef __MMI_MAINLCD_96X64__
#define CALC_NAVI_HILIGHT     0
#define CALC_LSK_CLEAR        1
#else
#define CALC_NAVI_HILIGHT     1
#define CALC_LSK_CLEAR        0
#endif/*__MMI_MAINLCD_96X64__*/
#else
#define CALC_NAVI_HILIGHT     1
#define CALC_LSK_CLEAR        0
#endif

#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_FTE_SUPPORT__)
#define CALC_DRAW_BACKGROUND    1
#else
#define CALC_DRAW_BACKGROUND    0
#endif

//#if defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) || defined(__CALC_96_64_SOLUTION_SLIM__)
#if defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_MAINLCD_96X64__)
#define CALC_SHOW_STATUS_ICON   0
#else
#define CALC_SHOW_STATUS_ICON   1
#endif

#if defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_FTE_SUPPORT__)
#define CALC_DRAW_TITLE         0
#else
#define CALC_DRAW_TITLE         1
#endif

#if defined(__MMI_FTE_SUPPORT__) || (defined(__MMI_SLIM_IMG_RES__) && !defined(__MMI_TOUCH_SCREEN__))
#define CALC_MEM_SUPPORT        0
#else
#define CALC_MEM_SUPPORT        1
#endif

#if defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || \
    (defined(__MMI_MAINLCD_176X220__))    
#define CALC_FONT_SIZE          MEDIUM_FONT
#elif defined(__MMI_FTE_SUPPORT__)
#if defined(__MMI_MAINLCD_320X480__)
#define CALC_FONT_SIZE          (0x80 | 36)
#elif defined(__MMI_MAINLCD_320X240__)
#define CALC_FONT_SIZE          (0x80 | 21)
#else
#define CALC_FONT_SIZE          (0x80 | 27)
#endif
#else
#define CALC_FONT_SIZE          LARGE_FONT
#endif

#ifdef __MMI_FTE_SUPPORT__
#define CALC_FONT_COLOR         {255, 255, 255, 100}
#ifdef __CALC_FTE_SLIM_USE_SLICE_RES__
#define CALC_FONT_COLOR_INPUT   {0, 0, 0, 100}        //black 
#endif/*__CALC_FTE_SLIM_USE_SLICE_RES__*/
#else
//#ifndef __CALC_96_64_SOLUTION_SLIM__
#ifndef __MMI_MAINLCD_96X64__
#define CALC_FONT_COLOR         {0, 0, 0, 100}
#else
#define CALC_FONT_COLOR         {255, 255, 255, 100}  //white
#define CALC_HIGHLIGHT_TEXT_COLOR    {0, 0, 0, 100}    //black 
#endif/*__CALC_96_64_SOLUTION_SLIM__*/
#endif
//#ifndef __CALC_96_64_SOLUTION_SLIM__
#ifndef __MMI_MAINLCD_96X64__
#ifdef __CALC_FTE_SLIM_USE_SLICE_RES__
#define CALC_OUTPUT_BGCOLOR     255, 234, 182, 100
#define CALC_OUTPUT_BDCOLOR     255, 186, 64, 100
#else
//pluto slim;
//#define CALC_OUTPUT_BGCOLOR     255, 234, 182, 100
#define CALC_OUTPUT_BGCOLOR     255, 255, 255, 255  //white
//#define CALC_OUTPUT_BDCOLOR     255, 186, 64, 100     
#define CALC_OUTPUT_BDCOLOR      255, 56, 174, 95   //38ae5f     
#endif/*__CALC_FTE_SLIM_USE_SLICE_RES__*/
#else
#define CALC_OUTPUT_BGCOLOR     255, 0, 0, 0    //black
#define CALC_OUTPUT_BDCOLOR     255, 255, 255, 255  //white

#define CALC_HIGHLIGHT_BGCOLOR  255, 255, 255, 255  //white
#define CALC_INPUT_BGCOLOR     255, 0, 0, 0    //black
#endif
#ifdef __CALC_SLIM_FOR_61__
#define CALC_INPUT_SUB_COLOR     255, 126, 186, 0   //7eba00
#endif

typedef enum {
    CALC_NUM_BEGIN,
    CALC_0,
    CALC_1,
    CALC_2,
    CALC_3,
    CALC_4,
    CALC_5,
    CALC_6,
    CALC_7,
    CALC_8,
    CALC_9,
    CALC_00,
    CALC_DOT,
    CALC_NUM_END,
    CALC_OP_BEGIN,
    CALC_PLUS,
    CALC_MINUS,
    CALC_DIV,      //   /
    CALC_MULT,
    //CALC_DIV,
    CALC_EQUAL,
    CALC_OP_END,
 #ifndef __CALC_SLIM_FOR_61__
    CALC_MEM_BEGIN,
    CALC_MP,
    CALC_MM,
    CALC_MC,
    CALC_MR,
    CALC_MEM_END,
 #endif/*__CALC_SLIM_FOR_61__*/
    CALC_CLEAR,
    CALC_CLEAR_ALL,
    CALC_INPUT_END
} calc_input_enum;

typedef enum {
    CALC_STATE_OPERAND1,
    CALC_STATE_OPERAND2,
    CALC_STATE_EQUAL,
    CALC_STATE_EXCEPTION
} calc_state_enum;

typedef enum {
    CALC_RESULT_SUCC,
    CALC_RESULT_FAIL,
    CALC_RESULT_DIV0,
    CALC_RESULT_EXCEED
} calc_result_enum;

typedef struct 
{
    U16 input;
    WCHAR *text;
} calc_format_struct;

typedef struct
{
    S16 left;
    S16 top;
    S16 width;
    S16 height;
} calc_rect_struct;

typedef struct 
{
    calc_rect_struct region;
    MMI_ID image;
    U16 shortcut;
    calc_input_enum input;
} calc_button_struct;

static const calc_format_struct g_calc_input_tab[] = {
    {CALC_0,    L"0"},
    {CALC_1,    L"1"},
    {CALC_2,    L"2"},
    {CALC_3,    L"3"},
    {CALC_4,    L"4"},
    {CALC_5,    L"5"},
    {CALC_6,    L"6"},
    {CALC_7,    L"7"},
    {CALC_8,    L"8"},
    {CALC_9,    L"9"},
    {CALC_00,   L"00"},
    {CALC_DOT,  L"."},
    {CALC_PLUS, L"+"},
    {CALC_MINUS, L"-"},
    {CALC_MULT, L"x"},
    {CALC_DIV,  L"/"},
    {CALC_EQUAL, L"="}
};

#define CALC_BG_X                   0
#if CALC_DRAW_TITLE
#define CALC_BG_Y                   MMI_CONTENT_Y
#else
#define CALC_BG_Y                   MMI_TITLE_Y
#endif

//#ifdef __CALC_96_64_SOLUTION_SLIM__
#ifdef __MMI_MAINLCD_96X64__
#define CALC_BG_X_FOR_96_64                   0
#define CALC_BG_Y_FOR_96_64                   28
#endif
#if CALC_DRAW_BACKGROUND
//#ifndef __CALC_96_64_SOLUTION_SLIM__
#ifndef __MMI_MAINLCD_96X64__
#define CALC_BORDER_WIDTH           0
#else
#define CALC_BORDER_WIDTH           1
#endif/*__CALC_96_64_SOLUTION_SLIM__*/
#else
//#ifndef __CALC_96_64_SOLUTION_SLIM__
#ifndef __MMI_MAINLCD_96X64__
#ifdef __CALC_FTE_SLIM_USE_SLICE_RES__
#define CALC_BORDER_WIDTH           2
#else
//pluto slim;
//#define CALC_BORDER_WIDTH           2
#define CALC_BORDER_WIDTH           1
#endif/*__CALC_FTE_SLIM_USE_SLICE_RES__*/
#else
#define CALC_BORDER_WIDTH           1
#endif/*__CALC_96_64_SOLUTION_SLIM__*/
#endif

#if defined(__MMI_FTE_SUPPORT__)
    #define CALC_KEYPAD_X               0
    #define CALC_KEYPAD_Y               0
    #if defined     (__MMI_MAINLCD_240X320__)
        static const calc_rect_struct g_calc_output_layout = 
            {CALC_BG_X,CALC_BG_Y,UI_DEVICE_WIDTH,81};
        #ifdef __MMI_TOUCH_SCREEN__
	    #ifndef __CALC_FTE_SLIM_USE_SLICE_RES__
        static const calc_button_struct g_calc_input_layout[] = {
            {{8,107,42,39},     IMG_ID_CALC_KEY1,   KEY_1, CALC_1},
            {{54,107,42,39},    IMG_ID_CALC_KEY2,   KEY_2, CALC_2},
            {{99,107,42,39},   IMG_ID_CALC_KEY3,   KEY_3, CALC_3},
            {{8,149,42,39},     IMG_ID_CALC_KEY4,   KEY_4, CALC_4},
            {{54,149,42,39},    IMG_ID_CALC_KEY5,   KEY_5, CALC_5},
            {{99,149,42,39},   IMG_ID_CALC_KEY6,   KEY_6, CALC_6},
            {{8,192,42,39},     IMG_ID_CALC_KEY7,   KEY_7, CALC_7},
            {{54,192,42,39},    IMG_ID_CALC_KEY8,   KEY_8, CALC_8},
            {{99,192,42,39},   IMG_ID_CALC_KEY9,   KEY_9, CALC_9},
            {{8,235,42,39},     IMG_ID_CALC_KEY00,  KEY_STAR, CALC_00},
            {{54,235,42,39},    IMG_ID_CALC_KEY0,   KEY_0, CALC_0},
            {{99,235,42,39},   IMG_ID_CALC_DOT,    KEY_POUND, CALC_DOT},
            {{170,146,41,23},   IMG_ID_CALC_PLUS,   KEY_UP_ARROW, CALC_PLUS},
         #ifndef __CALC_SLIM_FOR_61__
            {{170,207,41,23},   IMG_ID_CALC_SUB,    KEY_DOWN_ARROW, CALC_MINUS},
         #else
		    {{170,207,41,23},   0,    KEY_DOWN_ARROW, CALC_MINUS},
		 #endif
            {{148,169,22,38},   IMG_ID_CALC_MULTI,  KEY_LEFT_ARROW, CALC_MULT},
            {{211,169,22,38},   IMG_ID_CALC_DIVIDE, KEY_RIGHT_ARROW, CALC_DIV},
            {{175,173,31,31},   IMG_ID_CALC_EQUAL,  KEY_CSK, CALC_EQUAL}
        };
		#else
		static const calc_button_struct g_calc_input_layout[] = {
            {{8,107,42,39},     IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_1, CALC_1},
            {{54,107,42,39},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_2, CALC_2},
            {{99,107,42,39},   IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_3, CALC_3},
            {{8,149,42,39},     IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_4, CALC_4},
            {{54,149,42,39},    IMG_ID_CALC_KEY_HILIGHT_SLICE,  KEY_5, CALC_5},
            {{99,149,42,39},   IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_6, CALC_6},
            {{8,192,42,39},     IMG_ID_CALC_KEY_HILIGHT_SLICE,  KEY_7, CALC_7},
            {{54,192,42,39},    IMG_ID_CALC_KEY_HILIGHT_SLICE,  KEY_8, CALC_8},
            {{99,192,42,39},   IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_9, CALC_9},
            {{8,235,42,39},     IMG_ID_CALC_KEY_HILIGHT_SLICE, KEY_STAR, CALC_00},
            {{54,235,42,39},    IMG_ID_CALC_KEY_HILIGHT_SLICE,  KEY_0, CALC_0},
            {{99,235,42,39},   IMG_ID_CALC_KEY_HILIGHT_SLICE,    KEY_POUND, CALC_DOT},
            {{170,146+7,41,23},   IMG_ID_CALC_PLUS_AND_SUB_SLICE,  KEY_UP_ARROW, CALC_PLUS},
            {{170,207+8,41,23},   IMG_ID_CALC_PLUS_AND_SUB_SLICE,   KEY_DOWN_ARROW, CALC_MINUS},
            {{148,169+8,22,38},   IMG_ID_CALC_MULTI_AND_DIVIDE_SLICE, KEY_LEFT_ARROW, CALC_MULT},
            {{211,169+8,22,38},   IMG_ID_CALC_MULTI_AND_DIVIDE_SLICE,KEY_RIGHT_ARROW, CALC_DIV},
            {{175,173+7,31,31},   IMG_ID_CALC_EQUAL, KEY_CSK, CALC_EQUAL}
        };

		//static const calc_button_struct g_calc_input_nonhilight_layout[] = {     必须是非const类型的坐标结构数组；
		static calc_button_struct g_calc_input_nonhilight_layout[] = {
            {{8,107,42,39},     IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_1, CALC_1},
            {{54,107,42,39},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_2, CALC_2},
            {{99,107,42,39},   IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_3, CALC_3},
            {{8,149,42,39},     IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_4, CALC_4},
            {{54,149,42,39},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,  KEY_5, CALC_5},
            {{99,149,42,39},   IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_6, CALC_6},
            {{8,192,42,39},     IMG_ID_CALC_KEY_NONHILIGHT_SLICE,  KEY_7, CALC_7},
            {{54,192,42,39},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,  KEY_8, CALC_8},
            {{99,192,42,39},   IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_9, CALC_9},
            {{8,235,42,39},     IMG_ID_CALC_KEY_NONHILIGHT_SLICE, KEY_STAR, CALC_00},
            {{54,235,42,39},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,  KEY_0, CALC_0},
            {{99,235,42,39},   IMG_ID_CALC_KEY_NONHILIGHT_SLICE,    KEY_POUND, CALC_DOT}
        };
		#endif/*__CALC_FTE_SLIM_USE_SLICE_RES__*/
        #else
        static const calc_button_struct g_calc_input_layout[] = {
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_1, CALC_1},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_2, CALC_2},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_3, CALC_3},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_4, CALC_4},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_5, CALC_5},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_6, CALC_6},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_7, CALC_7},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_8, CALC_8},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_9, CALC_9},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_STAR, CALC_00},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_0, CALC_0},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_POUND, CALC_DOT},
            {{101,124,37,37},   IMG_ID_CALC_PLUS,   KEY_UP_ARROW, CALC_PLUS},
          #ifndef __CALC_SLIM_FOR_61__
            {{101,226,37,37},   IMG_ID_CALC_SUB,    KEY_DOWN_ARROW, CALC_MINUS},
          #else
		    {{101,226,37,37},   0,    KEY_DOWN_ARROW, CALC_MINUS},
		  #endif
            {{49,175,37,37},    IMG_ID_CALC_MULTI,  KEY_LEFT_ARROW, CALC_MULT},
            {{153,175,37,37},   IMG_ID_CALC_DIVIDE, KEY_RIGHT_ARROW, CALC_DIV},
            {{91,165,57,57},   IMG_ID_CALC_EQUAL,  KEY_CSK, CALC_EQUAL}
        };
        #endif
    #elif defined   (__MMI_MAINLCD_240X400__)
        static const calc_rect_struct g_calc_output_layout = 
            {CALC_BG_X,CALC_BG_Y,UI_DEVICE_WIDTH,85};
        #ifdef __MMI_TOUCH_SCREEN__
		#ifndef __CALC_FTE_SLIM_USE_SLICE_RES__
        static const calc_button_struct g_calc_input_layout[] = {
            {{8,149,42,39},     IMG_ID_CALC_KEY1,   KEY_1, CALC_1},
            {{54,149,42,39},    IMG_ID_CALC_KEY2,   KEY_2, CALC_2},
            {{99,149,42,39},   IMG_ID_CALC_KEY3,   KEY_3, CALC_3},
            {{8,191,42,39},     IMG_ID_CALC_KEY4,   KEY_4, CALC_4},
            {{54,191,42,39},    IMG_ID_CALC_KEY5,   KEY_5, CALC_5},
            {{99,191,42,39},   IMG_ID_CALC_KEY6,   KEY_6, CALC_6},
            {{8,234,42,39},     IMG_ID_CALC_KEY7,   KEY_7, CALC_7},
            {{54,234,42,39},    IMG_ID_CALC_KEY8,   KEY_8, CALC_8},
            {{99,234,42,39},   IMG_ID_CALC_KEY9,   KEY_9, CALC_9},
            {{8,277,42,39},     IMG_ID_CALC_KEY00,  KEY_STAR, CALC_00},
            {{54,277,42,39},    IMG_ID_CALC_KEY0,   KEY_0, CALC_0},
            {{99,277,42,39},   IMG_ID_CALC_DOT,    KEY_POUND, CALC_DOT},
            {{170,188,41,23},   IMG_ID_CALC_PLUS,   KEY_UP_ARROW, CALC_PLUS},
          #ifndef __CALC_SLIM_FOR_61__
            {{170,249,41,23},   IMG_ID_CALC_SUB,    KEY_DOWN_ARROW, CALC_MINUS},
          #else
		    {{170,249,41,23},   0,    KEY_DOWN_ARROW, CALC_MINUS},
		  #endif
            {{148,212,22,38},   IMG_ID_CALC_MULTI,  KEY_LEFT_ARROW, CALC_MULT},
            {{211,212,22,38},   IMG_ID_CALC_DIVIDE, KEY_RIGHT_ARROW, CALC_DIV},
            {{175,215,31,31},   IMG_ID_CALC_EQUAL,  KEY_CSK, CALC_EQUAL}
        };
		#else
		static const calc_button_struct g_calc_input_layout[] = {
            {{8,149,42,39},     IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_1, CALC_1},
            {{54,149,42,39},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_2, CALC_2},
            {{99,149,42,39},   IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_3, CALC_3},
            {{8,191,42,39},     IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_4, CALC_4},
            {{54,191,42,39},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_5, CALC_5},
            {{99,191,42,39},   IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_6, CALC_6},
            {{8,234,42,39},     IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_7, CALC_7},
            {{54,234,42,39},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_8, CALC_8},
            {{99,234,42,39},   IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_9, CALC_9},
            {{8,277,42,39},     IMG_ID_CALC_KEY_HILIGHT_SLICE,  KEY_STAR, CALC_00},
            {{54,277,42,39},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_0, CALC_0},
            {{99,277,42,39},   IMG_ID_CALC_KEY_HILIGHT_SLICE,    KEY_POUND, CALC_DOT},
            {{170,188,41,23},   IMG_ID_CALC_PLUS_AND_SUB_SLICE,   KEY_UP_ARROW, CALC_PLUS},
            {{170,249+1,41,23},   IMG_ID_CALC_PLUS_AND_SUB_SLICE,    KEY_DOWN_ARROW, CALC_MINUS},
            {{148,212,22,38},   IMG_ID_CALC_MULTI_AND_DIVIDE_SLICE,  KEY_LEFT_ARROW, CALC_MULT},
            {{211,212,22,38},   IMG_ID_CALC_MULTI_AND_DIVIDE_SLICE, KEY_RIGHT_ARROW, CALC_DIV},
            {{175,215,31,31},   IMG_ID_CALC_EQUAL,  KEY_CSK, CALC_EQUAL}
        };
		static calc_button_struct g_calc_input_nonhilight_layout[] = {
			{{8,149,42,39},     IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_1, CALC_1},
            {{54,149,42,39},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_2, CALC_2},
            {{99,149,42,39},   IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_3, CALC_3},
            {{8,191,42,39},     IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_4, CALC_4},
            {{54,191,42,39},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_5, CALC_5},
            {{99,191,42,39},   IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_6, CALC_6},
            {{8,234,42,39},     IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_7, CALC_7},
            {{54,234,42,39},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_8, CALC_8},
            {{99,234,42,39},   IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_9, CALC_9},
            {{8,277,42,39},     IMG_ID_CALC_KEY_NONHILIGHT_SLICE,  KEY_STAR, CALC_00},
            {{54,277,42,39},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_0, CALC_0},
            {{99,277,42,39},   IMG_ID_CALC_KEY_NONHILIGHT_SLICE,    KEY_POUND, CALC_DOT}
		};
		#endif/*__CALC_FTE_SLIM_USE_SLICE_RES__*/
        #else
        static const calc_button_struct g_calc_input_layout[] = {
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_1, CALC_1},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_2, CALC_2},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_3, CALC_3},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_4, CALC_4},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_5, CALC_5},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_6, CALC_6},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_7, CALC_7},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_8, CALC_8},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_9, CALC_9},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_STAR, CALC_00},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_0, CALC_0},
            {{0,0,0,0},         IMG_GLOBAL_EMPTY,   KEY_POUND, CALC_DOT},
            {{101,165,37,37},   IMG_ID_CALC_PLUS,   KEY_UP_ARROW, CALC_PLUS},
          #ifndef __CALC_SLIM_FOR_61__
            {{101,268,37,37},   IMG_ID_CALC_SUB,    KEY_DOWN_ARROW, CALC_MINUS},
          #else
		    {{101,268,37,37},   0,    KEY_DOWN_ARROW, CALC_MINUS},
		  #endif
            {{49,216,37,37},    IMG_ID_CALC_MULTI,  KEY_LEFT_ARROW, CALC_MULT},
            {{153,216,37,37},   IMG_ID_CALC_DIVIDE, KEY_RIGHT_ARROW, CALC_DIV},
            {{91,206,57,57},   IMG_ID_CALC_EQUAL,  KEY_CSK, CALC_EQUAL}
        };
        #endif
    #elif defined   (__MMI_MAINLCD_320X240__)
        static const calc_rect_struct g_calc_output_layout = 
            {CALC_BG_X,CALC_BG_Y,UI_DEVICE_WIDTH,53};
        #ifdef __MMI_TOUCH_SCREEN__
		#ifndef __CALC_FTE_SLIM_USE_SLICE_RES__
        static const calc_button_struct g_calc_input_layout[] = {
            {{11,77,42,39},    IMG_ID_CALC_KEY1,   KEY_1, CALC_1},
            {{54,77,42,39},    IMG_ID_CALC_KEY2,   KEY_2, CALC_2},
            {{97,77,42,39},   IMG_ID_CALC_KEY3,   KEY_3, CALC_3},
            {{11,118,42,39},    IMG_ID_CALC_KEY4,   KEY_4, CALC_4},
            {{54,118,42,39},    IMG_ID_CALC_KEY5,   KEY_5, CALC_5},
            {{97,118,42,39},   IMG_ID_CALC_KEY6,   KEY_6, CALC_6},
            {{11,159,42,39},    IMG_ID_CALC_KEY7,   KEY_7, CALC_7},
            {{54,159,42,39},    IMG_ID_CALC_KEY8,   KEY_8, CALC_8},
            {{97,159,42,39},   IMG_ID_CALC_KEY9,   KEY_9, CALC_9},
            {{140,118,42,39},    IMG_ID_CALC_KEY0,   KEY_0, CALC_0},
            {{140,77,42,39},    IMG_ID_CALC_KEY00,  KEY_STAR, CALC_00},
            {{140,159,42,39},   IMG_ID_CALC_DOT,    KEY_POUND, CALC_DOT},
            {{233,98,41,23},   IMG_ID_CALC_PLUS,   KEY_UP_ARROW, CALC_PLUS},
          #ifndef __CALC_SLIM_FOR_61__
            {{233,160,41,23},   IMG_ID_CALC_SUB,    KEY_DOWN_ARROW, CALC_MINUS},
          #else
		    {{233,160,41,23},   0,    KEY_DOWN_ARROW, CALC_MINUS},
		  #endif
            {{211,122,22,38},   IMG_ID_CALC_MULTI,  KEY_LEFT_ARROW, CALC_MULT},
            {{274,123,22,38},   IMG_ID_CALC_DIVIDE, KEY_RIGHT_ARROW, CALC_DIV},
            {{238,125,31,31},   IMG_ID_CALC_EQUAL,  KEY_CSK, CALC_EQUAL}
        };
		#else
		static const calc_button_struct g_calc_input_layout[] = {
            {{11,77,42,39},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_1, CALC_1},
            {{54,77,42,39},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_2, CALC_2},
            {{97,77,42,39},   IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_3, CALC_3},
            {{11,118,42,39},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_4, CALC_4},
            {{54,118,42,39},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_5, CALC_5},
            {{97,118,42,39},   IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_6, CALC_6},
            {{11,159,42,39},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_7, CALC_7},
            {{54,159,42,39},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_8, CALC_8},
            {{97,159,42,39},   IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_9, CALC_9},
            {{140,118,42,39},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_0, CALC_0},
            {{140,77,42,39},    IMG_ID_CALC_KEY_HILIGHT_SLICE,  KEY_STAR, CALC_00},
            {{140,159,42,39},   IMG_ID_CALC_KEY_HILIGHT_SLICE,    KEY_POUND, CALC_DOT},
            {{233,98,41,23},   IMG_ID_CALC_PLUS_AND_SUB_SLICE,   KEY_UP_ARROW, CALC_PLUS},
            {{233,160,41,23},   IMG_ID_CALC_PLUS_AND_SUB_SLICE,    KEY_DOWN_ARROW, CALC_MINUS},
            {{211,122,22,38},   IMG_ID_CALC_MULTI_AND_DIVIDE_SLICE,  KEY_LEFT_ARROW, CALC_MULT},
            {{274,123,22,38},   IMG_ID_CALC_MULTI_AND_DIVIDE_SLICE, KEY_RIGHT_ARROW, CALC_DIV},
            {{238,125,31,31},   IMG_ID_CALC_EQUAL,  KEY_CSK, CALC_EQUAL}
        };
		static calc_button_struct g_calc_input_nonhilight_layout[] = {
			{{11,77,42,39},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_1, CALC_1},
            {{54,77,42,39},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_2, CALC_2},
            {{97,77,42,39},   IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_3, CALC_3},
            {{11,118,42,39},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_4, CALC_4},
            {{54,118,42,39},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_5, CALC_5},
            {{97,118,42,39},   IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_6, CALC_6},
            {{11,159,42,39},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_7, CALC_7},
            {{54,159,42,39},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_8, CALC_8},
            {{97,159,42,39},   IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_9, CALC_9},
            {{140,118,42,39},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_0, CALC_0},
            {{140,77,42,39},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,  KEY_STAR, CALC_00},
            {{140,159,42,39},   IMG_ID_CALC_KEY_NONHILIGHT_SLICE,    KEY_POUND, CALC_DOT},
		};
		#endif/*__CALC_FTE_SLIM_USE_SLICE_RES__*/
        #else
        static const calc_button_struct g_calc_input_layout[] = {
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_1, CALC_1},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_2, CALC_2},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_3, CALC_3},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_4, CALC_4},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_5, CALC_5},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_6, CALC_6},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_7, CALC_7},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_8, CALC_8},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_9, CALC_9},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_0, CALC_0},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_STAR, CALC_00},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_POUND, CALC_DOT},
            {{139,94,41,23}, IMG_ID_CALC_PLUS,     KEY_UP_ARROW, CALC_PLUS},
          #ifndef __CALC_SLIM_FOR_61__
            {{139,156,41,23}, IMG_ID_CALC_SUB,      KEY_DOWN_ARROW, CALC_MINUS},
          #else
		    {{139,156,41,23}, 0,      KEY_DOWN_ARROW, CALC_MINUS},
		  #endif
            {{117,118,22,38}, IMG_ID_CALC_MULTI,     KEY_LEFT_ARROW, CALC_MULT},
            {{180,119,22,38}, IMG_ID_CALC_DIVIDE,   KEY_RIGHT_ARROW, CALC_DIV},
            {{144,121,31,31}, IMG_ID_CALC_EQUAL,    KEY_CSK, CALC_EQUAL}
        };
        #endif
    #elif defined   (__MMI_MAINLCD_320X480__)
        static const calc_rect_struct g_calc_output_layout = 
            {CALC_BG_X,CALC_BG_Y,UI_DEVICE_WIDTH,114};
        #ifdef __MMI_TOUCH_SCREEN__
		#ifndef __CALC_FTE_SLIM_USE_SLICE_RES__
        static const calc_button_struct g_calc_input_layout[] = {
            {{10,172,57,53},    IMG_ID_CALC_KEY1,   KEY_1, CALC_1},
            {{71,172,57,53},    IMG_ID_CALC_KEY2,   KEY_2, CALC_2},
            {{132,172,57,53},   IMG_ID_CALC_KEY3,   KEY_3, CALC_3},
            {{10,229,57,53},    IMG_ID_CALC_KEY4,   KEY_4, CALC_4},
            {{71,229,57,53},    IMG_ID_CALC_KEY5,   KEY_5, CALC_5},
            {{132,229,57,53},   IMG_ID_CALC_KEY6,   KEY_6, CALC_6},
            {{10,286,57,53},    IMG_ID_CALC_KEY7,   KEY_7, CALC_7},
            {{71,286,57,53},    IMG_ID_CALC_KEY8,   KEY_8, CALC_8},
            {{132,286,57,53},   IMG_ID_CALC_KEY9,   KEY_9, CALC_9},
            {{71,343,57,53},    IMG_ID_CALC_KEY0,   KEY_0, CALC_0},
            {{10,343,57,53},    IMG_ID_CALC_KEY00,  KEY_STAR, CALC_00},
            {{132,343,57,53},   IMG_ID_CALC_DOT,    KEY_POUND, CALC_DOT},
            {{227,225,54,31},   IMG_ID_CALC_PLUS,   KEY_UP_ARROW, CALC_PLUS},
          #ifndef __CALC_SLIM_FOR_61__
            {{227,308,54,31},   IMG_ID_CALC_SUB,    KEY_DOWN_ARROW, CALC_MINUS},
          #else
		    {{227,308,54,31},   0,    KEY_DOWN_ARROW, CALC_MINUS},
		  #endif
            {{197,256,31,54},   IMG_ID_CALC_MULTI,  KEY_LEFT_ARROW, CALC_MULT},
            {{281,256,31,54},   IMG_ID_CALC_DIVIDE, KEY_RIGHT_ARROW, CALC_DIV},
            {{233,261,42,42},   IMG_ID_CALC_EQUAL,  KEY_CSK, CALC_EQUAL}
        };
		#else
		static const calc_button_struct g_calc_input_layout[] = {
            {{10,172,57,53},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_1, CALC_1},
            {{71,172,57,53},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_2, CALC_2},
            {{132,172,57,53},   IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_3, CALC_3},
            {{10,229,57,53},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_4, CALC_4},
            {{71,229,57,53},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_5, CALC_5},
            {{132,229,57,53},   IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_6, CALC_6},
            {{10,286,57,53},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_7, CALC_7},
            {{71,286,57,53},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_8, CALC_8},
            {{132,286,57,53},   IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_9, CALC_9},
            {{71,343,57,53},    IMG_ID_CALC_KEY_HILIGHT_SLICE,   KEY_0, CALC_0},
            {{10,343,57,53},    IMG_ID_CALC_KEY_HILIGHT_SLICE,  KEY_STAR, CALC_00},
            {{132,343,57,53},   IMG_ID_CALC_KEY_HILIGHT_SLICE,    KEY_POUND, CALC_DOT},
            /*{{227,225,54,31},   IMG_ID_CALC_PLUS_AND_SUB_SLICE,   KEY_UP_ARROW, CALC_PLUS},
            {{227,308,54,31},   IMG_ID_CALC_PLUS_AND_SUB_SLICE,    KEY_DOWN_ARROW, CALC_MINUS},
            {{197,256,31,54},   IMG_ID_CALC_MULTI_AND_DIVIDE_SLICE,  KEY_LEFT_ARROW, CALC_MULT},
            {{281,256,31,54},   IMG_ID_CALC_MULTI_AND_DIVIDE_SLICE, KEY_RIGHT_ARROW, CALC_DIV},*/
            {{227,225,51+1,28+2},   IMG_ID_CALC_PLUS_AND_SUB_SLICE,   KEY_UP_ARROW, CALC_PLUS},
            {{227,308,51+1,28+2},   IMG_ID_CALC_PLUS_AND_SUB_SLICE,    KEY_DOWN_ARROW, CALC_MINUS},
            {{197,256,28+1,51+1},   IMG_ID_CALC_MULTI_AND_DIVIDE_SLICE,  KEY_LEFT_ARROW, CALC_MULT},
            {{281,256,28+1,51+1},   IMG_ID_CALC_MULTI_AND_DIVIDE_SLICE, KEY_RIGHT_ARROW, CALC_DIV},
            {{233,261,42,42},   IMG_ID_CALC_EQUAL,  KEY_CSK, CALC_EQUAL}
        };
		static calc_button_struct g_calc_input_nonhilight_layout[] = {
			{{10,172,57,53},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_1, CALC_1},
            {{71,172,57,53},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_2, CALC_2},
            {{132,172,57,53},   IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_3, CALC_3},
            {{10,229,57,53},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_4, CALC_4},
            {{71,229,57,53},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_5, CALC_5},
            {{132,229,57,53},   IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_6, CALC_6},
            {{10,286,57,53},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_7, CALC_7},
            {{71,286,57,53},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_8, CALC_8},
            {{132,286,57,53},   IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_9, CALC_9},
            {{71,343,57,53},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,   KEY_0, CALC_0},
            {{10,343,57,53},    IMG_ID_CALC_KEY_NONHILIGHT_SLICE,  KEY_STAR, CALC_00},
            {{132,343,57,53},   IMG_ID_CALC_KEY_NONHILIGHT_SLICE,    KEY_POUND, CALC_DOT}
		};
		#endif/*__CALC_FTE_SLIM_USE_SLICE_RES__*/
        #else
        static const calc_button_struct g_calc_input_layout[] = {
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_1, CALC_1},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_2, CALC_2},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_3, CALC_3},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_4, CALC_4},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_5, CALC_5},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_6, CALC_6},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_7, CALC_7},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_8, CALC_8},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_9, CALC_9},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_0, CALC_0},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_STAR, CALC_00},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_POUND, CALC_DOT},
            {{135,177,49,49}, IMG_ID_CALC_PLUS,     KEY_UP_ARROW, CALC_PLUS},
         #ifndef __CALC_SLIM_FOR_61__
            {{135,315,49,49}, IMG_ID_CALC_SUB,      KEY_DOWN_ARROW, CALC_MINUS},
         #else
		    {{135,315,49,49}, 0,      KEY_DOWN_ARROW, CALC_MINUS},
		 #endif
            {{67,246,49,49}, IMG_ID_CALC_MULTI,     KEY_LEFT_ARROW, CALC_MULT},
            {{205,246,49,49}, IMG_ID_CALC_DIVIDE,   KEY_RIGHT_ARROW, CALC_DIV},
            {{122,232,75,75}, IMG_ID_CALC_EQUAL,    KEY_CSK, CALC_EQUAL}
        };
        #endif
    #else
        static const calc_rect_struct g_calc_output_layout = 
            {0, 0, 0, 0};
        static const calc_button_struct g_calc_input_layout[] = {
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_1, CALC_1}
        };
    #endif
#elif defined(__MMI_SLIM_IMG_RES__)
    #if defined     (__MMI_MAINLCD_128X128__)
        #define CALC_KEYPAD_X               22
        #define CALC_KEYPAD_Y               41
        static const calc_rect_struct g_calc_output_layout = 
            {CALC_BG_X, CALC_BG_Y, UI_DEVICE_WIDTH, 40};
        static const calc_button_struct g_calc_input_layout[] = {
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_1, CALC_1},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_2, CALC_2},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_3, CALC_3},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_4, CALC_4},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_5, CALC_5},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_6, CALC_6},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_7, CALC_7},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_8, CALC_8},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_9, CALC_9},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_0, CALC_0},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_STAR, CALC_00},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_POUND, CALC_DOT},
            {{CALC_KEYPAD_X+35,CALC_KEYPAD_Y+4,13,13}, IMG_ID_CALC_PLUS,     KEY_UP_ARROW, CALC_PLUS},
          #ifndef __CALC_SLIM_FOR_61__
            {{CALC_KEYPAD_X+35,CALC_KEYPAD_Y+47,13,13}, IMG_ID_CALC_SUB,      KEY_DOWN_ARROW, CALC_MINUS},
          #else
		    {{CALC_KEYPAD_X+35,CALC_KEYPAD_Y+47,13,13}, 0,      KEY_DOWN_ARROW, CALC_MINUS},
		  #endif
            {{CALC_KEYPAD_X+9,CALC_KEYPAD_Y+25,13,13}, IMG_ID_CALC_MULTI,     KEY_LEFT_ARROW, CALC_MULT},
            {{CALC_KEYPAD_X+62,CALC_KEYPAD_Y+25,13,17}, IMG_ID_CALC_DIVIDE,   KEY_RIGHT_ARROW, CALC_DIV},
            {{CALC_KEYPAD_X+35,CALC_KEYPAD_Y+25,13,13}, IMG_ID_CALC_EQUAL,    KEY_CSK, CALC_EQUAL}
        };
    #elif defined   (__MMI_MAINLCD_128X160__)
        #define CALC_KEYPAD_X               22
        #define CALC_KEYPAD_Y               51
        #ifdef __MMI_TOUCH_SCREEN__
        static const calc_rect_struct g_calc_output_layout = 
            {4, CALC_BG_Y+5, 120, 41};
        static const calc_button_struct g_calc_input_layout[] = {
            {{2,CALC_BG_Y+49,30,18},     IMG_ID_CALC_MP,     KEY_INVALID,  CALC_MP},
            {{33,CALC_BG_Y+49,30,18},    IMG_ID_CALC_MS,     KEY_INVALID,  CALC_MM},
            {{64,CALC_BG_Y+49,30,18},   IMG_ID_CALC_MR,     KEY_INVALID,  CALC_MR},
            {{95,CALC_BG_Y+49,30,18},   IMG_ID_CALC_MC,     KEY_INVALID,  CALC_MC},
            {{2,CALC_BG_Y+67,30,18},     IMG_ID_CALC_KEY7,   KEY_7,  CALC_7},
            {{33,CALC_BG_Y+67,30,18},    IMG_ID_CALC_KEY8,   KEY_8,  CALC_8},
            {{64,CALC_BG_Y+67,30,18},   IMG_ID_CALC_KEY9,   KEY_9,  CALC_9},
            {{95,CALC_BG_Y+67,30,18},   IMG_ID_CALC_DIVIDE, KEY_INVALID, CALC_DIV},
            {{2,CALC_BG_Y+85,30,18},     IMG_ID_CALC_KEY4,   KEY_4, CALC_4},
            {{33,CALC_BG_Y+85,30,18},    IMG_ID_CALC_KEY5,   KEY_5, CALC_5},
            {{64,CALC_BG_Y+85,30,18},   IMG_ID_CALC_KEY6,   KEY_6, CALC_6},
            {{95,CALC_BG_Y+85,30,18},   IMG_ID_CALC_MULTI,  KEY_INVALID, CALC_MULT},
            {{2,CALC_BG_Y+107,30,18},     IMG_ID_CALC_KEY1,   KEY_1, CALC_1},
            {{33,CALC_BG_Y+107,30,18},    IMG_ID_CALC_KEY2,   KEY_2, CALC_2},
            {{64,CALC_BG_Y+107,30,18},   IMG_ID_CALC_KEY3,   KEY_3, CALC_3},
         #ifndef __CALC_SLIM_FOR_61__
            {{95,CALC_BG_Y+107,30,18},   IMG_ID_CALC_SUB,    KEY_INVALID, CALC_MINUS},
         #else
		    {{95,CALC_BG_Y+107,30,18},   0,    KEY_INVALID, CALC_MINUS},
		 #endif
            {{2,CALC_BG_Y+129,30,18},     IMG_ID_CALC_KEY0,   KEY_0, CALC_0},
            {{33,CALC_BG_Y+129,30,18},    IMG_ID_CALC_DOT,    KEY_POUND, CALC_DOT},
            {{64,CALC_BG_Y+129,30,18},   IMG_ID_CALC_EQUAL,  KEY_CSK, CALC_EQUAL},
            {{95,CALC_BG_Y+129,30,18},   IMG_ID_CALC_PLUS,   KEY_INVALID, CALC_PLUS}
        };
        #else
        static const calc_rect_struct g_calc_output_layout = 
            {CALC_BG_X, CALC_BG_Y, UI_DEVICE_WIDTH, 46};
        static const calc_button_struct g_calc_input_layout[] = {
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_1, CALC_1},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_2, CALC_2},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_3, CALC_3},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_4, CALC_4},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_5, CALC_5},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_6, CALC_6},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_7, CALC_7},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_8, CALC_8},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_9, CALC_9},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_0, CALC_0},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_STAR, CALC_00},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_POUND, CALC_DOT},
            {{CALC_KEYPAD_X+35,CALC_KEYPAD_Y+4,13,13}, IMG_ID_CALC_PLUS,     KEY_UP_ARROW, CALC_PLUS},
         #ifndef __CALC_SLIM_FOR_61__
            {{CALC_KEYPAD_X+35,CALC_KEYPAD_Y+47,13,13}, IMG_ID_CALC_SUB,      KEY_DOWN_ARROW, CALC_MINUS},
         #else
		    {{CALC_KEYPAD_X+35,CALC_KEYPAD_Y+47,13,13}, 0,      KEY_DOWN_ARROW, CALC_MINUS},
		 #endif
            {{CALC_KEYPAD_X+9,CALC_KEYPAD_Y+25,13,13}, IMG_ID_CALC_MULTI,     KEY_LEFT_ARROW, CALC_MULT},
            {{CALC_KEYPAD_X+62,CALC_KEYPAD_Y+25,13,17}, IMG_ID_CALC_DIVIDE,   KEY_RIGHT_ARROW, CALC_DIV},
            {{CALC_KEYPAD_X+35,CALC_KEYPAD_Y+25,13,13}, IMG_ID_CALC_EQUAL,    KEY_CSK, CALC_EQUAL}
        };
        #endif
    #elif defined   (__MMI_MAINLCD_176X220__)
        #define CALC_KEYPAD_X               30
        #define CALC_KEYPAD_Y               102
        #ifdef __MMI_TOUCH_SCREEN__
        static const calc_rect_struct g_calc_output_layout = 
            {7, CALC_BG_Y+2, 161, 44};
        static const calc_button_struct g_calc_input_layout[] = {
		  #ifndef __CALC_SLIM_FOR_61__
            {{6,CALC_BG_Y+47,38,20},     IMG_ID_CALC_MP,     KEY_INVALID,  CALC_MP},
            {{47,CALC_BG_Y+47,38,20},    IMG_ID_CALC_MS,     KEY_INVALID,  CALC_MM},
            {{88,CALC_BG_Y+47,38,20},   IMG_ID_CALC_MR,     KEY_INVALID,  CALC_MR},
            {{129,CALC_BG_Y+47,38,20},   IMG_ID_CALC_MC,     KEY_INVALID,  CALC_MC},
          #endif/*__CALC_SLIM_FOR_61__*/
            {{6,CALC_BG_Y+69,38,20},     IMG_ID_CALC_KEY7,   KEY_7,  CALC_7},
            {{47,CALC_BG_Y+69,38,20},    IMG_ID_CALC_KEY8,   KEY_8,  CALC_8},
            {{88,CALC_BG_Y+69,38,20},   IMG_ID_CALC_KEY9,   KEY_9,  CALC_9},
            {{129,CALC_BG_Y+69,38,20},   IMG_ID_CALC_DIVIDE, KEY_INVALID, CALC_DIV},
            {{6,CALC_BG_Y+91,38,20},     IMG_ID_CALC_KEY4,   KEY_4, CALC_4},
            {{47,CALC_BG_Y+91,38,20},    IMG_ID_CALC_KEY5,   KEY_5, CALC_5},
            {{88,CALC_BG_Y+91,38,20},   IMG_ID_CALC_KEY6,   KEY_6, CALC_6},
            {{129,CALC_BG_Y+91,38,20},   IMG_ID_CALC_MULTI,  KEY_INVALID, CALC_MULT},
            {{6,CALC_BG_Y+113,38,20},     IMG_ID_CALC_KEY1,   KEY_1, CALC_1},
            {{47,CALC_BG_Y+113,38,20},    IMG_ID_CALC_KEY2,   KEY_2, CALC_2},
            {{88,CALC_BG_Y+113,38,20},   IMG_ID_CALC_KEY3,   KEY_3, CALC_3},
          #ifndef __CALC_SLIM_FOR_61__
            {{129,CALC_BG_Y+113,38,20},   IMG_ID_CALC_SUB,    KEY_INVALID, CALC_MINUS},
          #else
		    {{129,CALC_BG_Y+113,38,20},   0,    KEY_INVALID, CALC_MINUS},
		  #endif
            {{6,CALC_BG_Y+135,38,20},     IMG_ID_CALC_KEY0,   KEY_0, CALC_0},
            {{47,CALC_BG_Y+135,38,20},    IMG_ID_CALC_DOT,    KEY_POUND, CALC_DOT},
            {{88,CALC_BG_Y+135,38,20},   IMG_ID_CALC_EQUAL,  KEY_CSK, CALC_EQUAL},
            {{129,CALC_BG_Y+135,38,20},   IMG_ID_CALC_PLUS,   KEY_INVALID, CALC_PLUS}
        };
        #else
        static const calc_rect_struct g_calc_output_layout = 
          #ifdef __CALC_FTE_SLIM_USE_SLICE_RES__
		    {CALC_BG_X, CALC_BG_Y, UI_DEVICE_WIDTH, 52};
		  #else
            //{CALC_BG_X, CALC_BG_Y, UI_DEVICE_WIDTH, 52};
            {CALC_BG_X +2 ,CALC_BG_Y +5 ,UI_DEVICE_WIDTH - 4,52 - 5};
		  #endif
        static const calc_button_struct g_calc_input_layout[] = {
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_1, CALC_1},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_2, CALC_2},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_3, CALC_3},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_4, CALC_4},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_5, CALC_5},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_6, CALC_6},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_7, CALC_7},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_8, CALC_8},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_9, CALC_9},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_0, CALC_0},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_STAR, CALC_00},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_POUND, CALC_DOT},
            {{CALC_KEYPAD_X+49,CALC_KEYPAD_Y+6,17,17}, IMG_ID_CALC_PLUS,     KEY_UP_ARROW, CALC_PLUS},
         #ifndef __CALC_SLIM_FOR_61__
            {{CALC_KEYPAD_X+49,CALC_KEYPAD_Y+66,17,17}, IMG_ID_CALC_SUB,      KEY_DOWN_ARROW, CALC_MINUS},
         #else
		    {{CALC_KEYPAD_X+49,CALC_KEYPAD_Y+66,17,17}, 0 ,      KEY_DOWN_ARROW, CALC_MINUS},
		 #endif/*__CALC_SLIM_FOR_61__*/
            {{CALC_KEYPAD_X+13,CALC_KEYPAD_Y+36,17,17}, IMG_ID_CALC_MULTI,     KEY_LEFT_ARROW, CALC_MULT},
            {{CALC_KEYPAD_X+86,CALC_KEYPAD_Y+36,17,17}, IMG_ID_CALC_DIVIDE,   KEY_RIGHT_ARROW, CALC_DIV},
            {{CALC_KEYPAD_X+49,CALC_KEYPAD_Y+36,17,17}, IMG_ID_CALC_EQUAL,    KEY_CSK, CALC_EQUAL}
        };
        #endif
    #elif defined   (__MMI_MAINLCD_240X320__)
        #define CALC_KEYPAD_X               43
        #define CALC_KEYPAD_Y               136
        #ifdef __MMI_TOUCH_SCREEN__
        static const calc_rect_struct g_calc_output_layout = 
            {8, 58, 223, 72};
        static const calc_button_struct g_calc_input_layout[] = {
            {{8,135,52,29},     IMG_ID_CALC_MP,     KEY_INVALID,  CALC_MP},
            {{65,135,52,29},    IMG_ID_CALC_MS,     KEY_INVALID,  CALC_MM},
            {{122,135,52,29},   IMG_ID_CALC_MR,     KEY_INVALID,  CALC_MR},
            {{179,135,52,29},   IMG_ID_CALC_MC,     KEY_INVALID,  CALC_MC},
            {{8,167,52,29},     IMG_ID_CALC_KEY7,   KEY_7,  CALC_7},
            {{65,167,52,29},    IMG_ID_CALC_KEY8,   KEY_8,  CALC_8},
            {{122,167,52,29},   IMG_ID_CALC_KEY9,   KEY_9,  CALC_9},
            {{179,167,52,29},   IMG_ID_CALC_DIVIDE, KEY_INVALID, CALC_DIV},
            {{8,199,52,29},     IMG_ID_CALC_KEY4,   KEY_4, CALC_4},
            {{65,199,52,29},    IMG_ID_CALC_KEY5,   KEY_5, CALC_5},
            {{122,199,52,29},   IMG_ID_CALC_KEY6,   KEY_6, CALC_6},
            {{179,199,52,29},   IMG_ID_CALC_MULTI,  KEY_INVALID, CALC_MULT},
            {{8,231,52,29},     IMG_ID_CALC_KEY1,   KEY_1, CALC_1},
            {{65,231,52,29},    IMG_ID_CALC_KEY2,   KEY_2, CALC_2},
            {{122,231,52,29},   IMG_ID_CALC_KEY3,   KEY_3, CALC_3},
         #ifndef __CALC_SLIM_FOR_61__
            {{179,231,52,29},   IMG_ID_CALC_SUB,    KEY_INVALID, CALC_MINUS},
         #else
		    {{179,231,52,29},   0,    KEY_INVALID, CALC_MINUS},
		 #endif
            {{8,263,52,29},     IMG_ID_CALC_KEY0,   KEY_0, CALC_0},
            {{65,263,52,29},    IMG_ID_CALC_DOT,    KEY_POUND, CALC_DOT},
            {{122,263,52,29},   IMG_ID_CALC_EQUAL,  KEY_CSK, CALC_EQUAL},
            {{179,263,52,29},   IMG_ID_CALC_PLUS,   KEY_INVALID, CALC_PLUS}
        };
        #else
        static const calc_rect_struct g_calc_output_layout = 
            {CALC_BG_X, CALC_BG_Y, UI_DEVICE_WIDTH, 67};
        static const calc_button_struct g_calc_input_layout[] = {
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_1, CALC_1},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_2, CALC_2},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_3, CALC_3},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_4, CALC_4},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_5, CALC_5},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_6, CALC_6},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_7, CALC_7},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_8, CALC_8},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_9, CALC_9},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_0, CALC_0},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_STAR, CALC_00},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_POUND, CALC_DOT},
            {{109,145,21,21}, IMG_ID_CALC_PLUS,     KEY_UP_ARROW, CALC_PLUS},
         #ifndef __CALC_SLIM_FOR_61__
            {{109,223,21,21}, IMG_ID_CALC_SUB,      KEY_DOWN_ARROW, CALC_MINUS},
         #else
		    {{109,223,21,21}, 0,      KEY_DOWN_ARROW, CALC_MINUS},
		 #endif
            {{62,184,21,21}, IMG_ID_CALC_MULTI,     KEY_LEFT_ARROW, CALC_MULT},
            {{158,184,21,21}, IMG_ID_CALC_DIVIDE,   KEY_RIGHT_ARROW, CALC_DIV},
            {{109,184,21,21}, IMG_ID_CALC_EQUAL,    KEY_CSK, CALC_EQUAL}
        };
        #endif
   #elif defined   (__MMI_MAINLCD_96X64__)
		static const calc_rect_struct g_calc_output_layout = 
            {CALC_BG_X, CALC_BG_Y, UI_DEVICE_WIDTH, 40};
        static const calc_button_struct g_calc_input_layout[] = {
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_1, CALC_1},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_2, CALC_2},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_3, CALC_3},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_4, CALC_4},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_5, CALC_5},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_6, CALC_6},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_7, CALC_7},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_8, CALC_8},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_9, CALC_9},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_0, CALC_0},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_STAR, CALC_00},
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_POUND, CALC_DOT},
            {{18-2-2,28+4,14-2,14-1}, IMG_ID_CALC_PLUS,     KEY_UP_ARROW, CALC_PLUS},
         #ifndef __CALC_SLIM_FOR_61__
            {{36-2+1,28+4,14-2,14-1}, IMG_ID_CALC_SUB,      KEY_DOWN_ARROW, CALC_MINUS},
         #else
		    {{36-2+1,28+4,14-2,14-1}, 0,      KEY_DOWN_ARROW, CALC_MINUS},
		 #endif
            {{58-2,28+4,14-2,14-1}, IMG_ID_CALC_DIVIDE,   KEY_RIGHT_ARROW, CALC_DIV},    //14
            {{78-2,28+4,14-2,14-1}, IMG_ID_CALC_MULTI,     KEY_LEFT_ARROW, CALC_MULT},
            {{0,0,0,0}, IMG_ID_CALC_EQUAL,    KEY_CSK, CALC_EQUAL}
        };
    #else
        #define CALC_KEYPAD_X               0
        #define CALC_KEYPAD_Y               0
        static const calc_rect_struct g_calc_output_layout = 
            {0, 0, 0, 0};
        static const calc_button_struct g_calc_input_layout[] = {
            {{0,0,0,0},     IMG_GLOBAL_EMPTY,       KEY_INVALID, CALC_1}
        };
    #endif
#else
    #if defined     (__MMI_MAINLCD_128X128__)
        #define CALC_KEYPAD_X               20
        #define CALC_KEYPAD_Y               41
        static const calc_rect_struct g_calc_output_layout = 
            {CALC_BG_X, CALC_BG_Y, UI_DEVICE_WIDTH, 40};
        static const calc_button_struct g_calc_input_layout[] = {
            {{CALC_KEYPAD_X+1,CALC_KEYPAD_Y,59,18},   IMG_ID_CALC_MP,     KEY_INVALID,  CALC_MP},
            {{CALC_KEYPAD_X,CALC_KEYPAD_Y+48,58,19},  IMG_ID_CALC_MS,     KEY_INVALID,  CALC_MM},
            {{CALC_KEYPAD_X+70,CALC_KEYPAD_Y+1,23,45},   IMG_ID_CALC_MR,     KEY_INVALID,  CALC_MR},
            {{CALC_KEYPAD_X,CALC_KEYPAD_Y+1,23,45},    IMG_ID_CALC_MC,     KEY_INVALID,  CALC_MC},
            {{CALC_KEYPAD_X+17,CALC_KEYPAD_Y+16,37,14},   IMG_ID_CALC_PLUS,   KEY_INVALID,  CALC_PLUS},
         #ifndef __CALC_SLIM_FOR_61__
            {{CALC_KEYPAD_X+17,CALC_KEYPAD_Y+38,38,13},   IMG_ID_CALC_SUB,    KEY_INVALID,  CALC_MINUS},
         #else
		    {{CALC_KEYPAD_X+17,CALC_KEYPAD_Y+38,38,13},   0,    KEY_INVALID,  CALC_MINUS},
		 #endif
            {{CALC_KEYPAD_X+16,CALC_KEYPAD_Y+17,17,27},   IMG_ID_CALC_MULTI,  KEY_INVALID,  CALC_MULT},
            {{CALC_KEYPAD_X+60,CALC_KEYPAD_Y+17,38,13},   IMG_ID_CALC_DIVIDE, KEY_INVALID,  CALC_DIV}
        };
    #elif defined   (__MMI_MAINLCD_128X160__)
        #define CALC_KEYPAD_X               21
        #define CALC_KEYPAD_Y               40
        #ifdef __MMI_TOUCH_SCREEN__
        static const calc_rect_struct g_calc_output_layout = 
            {4, CALC_BG_Y+5, 120, 41};
        static const calc_button_struct g_calc_input_layout[] = {
            {{2,CALC_BG_Y+49,30,18},     IMG_ID_CALC_MP,     KEY_INVALID,  CALC_MP},
            {{33,CALC_BG_Y+49,30,18},    IMG_ID_CALC_MS,     KEY_INVALID,  CALC_MM},
            {{64,CALC_BG_Y+49,30,18},   IMG_ID_CALC_MR,     KEY_INVALID,  CALC_MR},
            {{95,CALC_BG_Y+49,30,18},   IMG_ID_CALC_MC,     KEY_INVALID,  CALC_MC},
            {{2,CALC_BG_Y+67,30,18},     IMG_ID_CALC_KEY7,   KEY_7,  CALC_7},
            {{33,CALC_BG_Y+67,30,18},    IMG_ID_CALC_KEY8,   KEY_8,  CALC_8},
            {{64,CALC_BG_Y+67,30,18},   IMG_ID_CALC_KEY9,   KEY_9,  CALC_9},
            {{95,CALC_BG_Y+67,30,18},   IMG_ID_CALC_DIVIDE, KEY_INVALID, CALC_DIV},
            {{2,CALC_BG_Y+85,30,18},     IMG_ID_CALC_KEY4,   KEY_4, CALC_4},
            {{33,CALC_BG_Y+85,30,18},    IMG_ID_CALC_KEY5,   KEY_5, CALC_5},
            {{64,CALC_BG_Y+85,30,18},   IMG_ID_CALC_KEY6,   KEY_6, CALC_6},
            {{95,CALC_BG_Y+85,30,18},   IMG_ID_CALC_MULTI,  KEY_INVALID, CALC_MULT},
            {{2,CALC_BG_Y+107,30,18},     IMG_ID_CALC_KEY1,   KEY_1, CALC_1},
            {{33,CALC_BG_Y+107,30,18},    IMG_ID_CALC_KEY2,   KEY_2, CALC_2},
            {{64,CALC_BG_Y+107,30,18},   IMG_ID_CALC_KEY3,   KEY_3, CALC_3},
         #ifndef __CALC_SLIM_FOR_61__
            {{95,CALC_BG_Y+107,30,18},   IMG_ID_CALC_SUB,    KEY_INVALID, CALC_MINUS},
         #else
		    {{95,CALC_BG_Y+107,30,18},   0,    KEY_INVALID, CALC_MINUS},
		 #endif
            {{2,CALC_BG_Y+129,30,18},     IMG_ID_CALC_KEY0,   KEY_0, CALC_0},
            {{33,CALC_BG_Y+129,30,18},    IMG_ID_CALC_DOT,    KEY_POUND, CALC_DOT},
            {{64,CALC_BG_Y+129,30,18},   IMG_ID_CALC_EQUAL,  KEY_CSK, CALC_EQUAL},
            {{95,CALC_BG_Y+129,30,18},   IMG_ID_CALC_PLUS,   KEY_INVALID, CALC_PLUS}
        };
        #else
        static const calc_rect_struct g_calc_output_layout = 
            {CALC_BG_X, CALC_BG_Y, UI_DEVICE_WIDTH, 46};
        static const calc_button_struct g_calc_input_layout[] = {
            {{CALC_KEYPAD_X+1,CALC_KEYPAD_Y,59,18},   IMG_ID_CALC_MP,     KEY_INVALID,  CALC_MP},
            {{CALC_KEYPAD_X,CALC_KEYPAD_Y+48,58,19},  IMG_ID_CALC_MS,     KEY_INVALID,  CALC_MM},
            {{CALC_KEYPAD_X+70,CALC_KEYPAD_Y+1,23,45},   IMG_ID_CALC_MR,     KEY_INVALID,  CALC_MR},
            {{CALC_KEYPAD_X,CALC_KEYPAD_Y+1,23,45},    IMG_ID_CALC_MC,     KEY_INVALID,  CALC_MC},
            {{CALC_KEYPAD_X+17,CALC_KEYPAD_Y+16,37,14},   IMG_ID_CALC_PLUS,   KEY_INVALID,  CALC_PLUS},
          #ifndef __CALC_SLIM_FOR_61__
            {{CALC_KEYPAD_X+17,CALC_KEYPAD_Y+38,38,13},   IMG_ID_CALC_SUB,    KEY_INVALID,  CALC_MINUS},
          #else
		    {{CALC_KEYPAD_X+17,CALC_KEYPAD_Y+38,38,13},   0,    KEY_INVALID,  CALC_MINUS},
		  #endif
            {{CALC_KEYPAD_X+16,CALC_KEYPAD_Y+17,17,27},   IMG_ID_CALC_MULTI,  KEY_INVALID,  CALC_MULT},
            {{CALC_KEYPAD_X+60,CALC_KEYPAD_Y+17,38,13},   IMG_ID_CALC_DIVIDE, KEY_INVALID,  CALC_DIV}
        };
        #endif
    #elif defined   (__MMI_MAINLCD_176X220__)
        #define CALC_KEYPAD_X               0
        #define CALC_KEYPAD_Y               101
        #ifdef __MMI_TOUCH_SCREEN__
        static const calc_rect_struct g_calc_output_layout = 
            {7, CALC_BG_Y+2, 161, 44};
        static const calc_button_struct g_calc_input_layout[] = {
            {{6,CALC_BG_Y+47,38,20},     IMG_ID_CALC_MP,     KEY_INVALID,  CALC_MP},
            {{47,CALC_BG_Y+47,38,20},    IMG_ID_CALC_MS,     KEY_INVALID,  CALC_MM},
            {{88,CALC_BG_Y+47,38,20},   IMG_ID_CALC_MR,     KEY_INVALID,  CALC_MR},
            {{129,CALC_BG_Y+47,38,20},   IMG_ID_CALC_MC,     KEY_INVALID,  CALC_MC},
            {{6,CALC_BG_Y+69,38,20},     IMG_ID_CALC_KEY7,   KEY_7,  CALC_7},
            {{47,CALC_BG_Y+69,38,20},    IMG_ID_CALC_KEY8,   KEY_8,  CALC_8},
            {{88,CALC_BG_Y+69,38,20},   IMG_ID_CALC_KEY9,   KEY_9,  CALC_9},
            {{129,CALC_BG_Y+69,38,20},   IMG_ID_CALC_DIVIDE, KEY_INVALID, CALC_DIV},
            {{6,CALC_BG_Y+91,38,20},     IMG_ID_CALC_KEY4,   KEY_4, CALC_4},
            {{47,CALC_BG_Y+91,38,20},    IMG_ID_CALC_KEY5,   KEY_5, CALC_5},
            {{88,CALC_BG_Y+91,38,20},   IMG_ID_CALC_KEY6,   KEY_6, CALC_6},
            {{129,CALC_BG_Y+91,38,20},   IMG_ID_CALC_MULTI,  KEY_INVALID, CALC_MULT},
            {{6,CALC_BG_Y+113,38,20},     IMG_ID_CALC_KEY1,   KEY_1, CALC_1},
            {{47,CALC_BG_Y+113,38,20},    IMG_ID_CALC_KEY2,   KEY_2, CALC_2},
            {{88,CALC_BG_Y+113,38,20},   IMG_ID_CALC_KEY3,   KEY_3, CALC_3},
          #ifndef __CALC_SLIM_FOR_61__
            {{129,CALC_BG_Y+113,38,20},   IMG_ID_CALC_SUB,    KEY_INVALID, CALC_MINUS},
          #else
		    {{129,CALC_BG_Y+113,38,20},   0,    KEY_INVALID, CALC_MINUS},
		  #endif
            {{6,CALC_BG_Y+135,38,20},     IMG_ID_CALC_KEY0,   KEY_0, CALC_0},
            {{47,CALC_BG_Y+135,38,20},    IMG_ID_CALC_DOT,    KEY_POUND, CALC_DOT},
            {{88,CALC_BG_Y+135,38,20},   IMG_ID_CALC_EQUAL,  KEY_CSK, CALC_EQUAL},
            {{129,CALC_BG_Y+135,38,20},   IMG_ID_CALC_PLUS,   KEY_INVALID, CALC_PLUS}
        };
        #else
        static const calc_rect_struct g_calc_output_layout = 
            {CALC_BG_X, CALC_BG_Y, UI_DEVICE_WIDTH, 52};
        static const calc_button_struct g_calc_input_layout[] = {
            {{31,CALC_KEYPAD_Y+2,117,17},   IMG_ID_CALC_MP,     KEY_INVALID,  CALC_MP},
            {{31,CALC_KEYPAD_Y+70,117,17},  IMG_ID_CALC_MS,     KEY_INVALID,  CALC_MM},
            {{126,CALC_KEYPAD_Y+3,23,83},   IMG_ID_CALC_MR,     KEY_INVALID,  CALC_MR},
            {{30,CALC_KEYPAD_Y+3,23,83},    IMG_ID_CALC_MC,     KEY_INVALID,  CALC_MC},
            {{53,CALC_KEYPAD_Y+19,73,26},   IMG_ID_CALC_PLUS,   KEY_INVALID,  CALC_PLUS},
         #ifndef __CALC_SLIM_FOR_61__
            {{53,CALC_KEYPAD_Y+44,73,26},   IMG_ID_CALC_SUB,    KEY_INVALID,  CALC_MINUS},
         #else
		    {{53,CALC_KEYPAD_Y+44,73,26},   0,    KEY_INVALID,  CALC_MINUS},
		 #endif
            {{53,CALC_KEYPAD_Y+19,37,51},   IMG_ID_CALC_MULTI,  KEY_INVALID,  CALC_MULT},
            {{89,CALC_KEYPAD_Y+19,37,51},   IMG_ID_CALC_DIVIDE, KEY_INVALID,  CALC_DIV}
        };
        #endif
    #elif defined   (__MMI_MAINLCD_240X320__)
        #define CALC_KEYPAD_X               0
        #define CALC_KEYPAD_Y               142
        #ifdef __MMI_TOUCH_SCREEN__
        static const calc_rect_struct g_calc_output_layout = 
            {8, 58, 223, 72};
        static const calc_button_struct g_calc_input_layout[] = {
            {{8,135,52,29},     IMG_ID_CALC_MP,     KEY_INVALID,  CALC_MP},
            {{65,135,52,29},    IMG_ID_CALC_MS,     KEY_INVALID,  CALC_MM},
            {{122,135,52,29},   IMG_ID_CALC_MR,     KEY_INVALID,  CALC_MR},
            {{179,135,52,29},   IMG_ID_CALC_MC,     KEY_INVALID,  CALC_MC},
            {{8,167,52,29},     IMG_ID_CALC_KEY7,   KEY_7,  CALC_7},
            {{65,167,52,29},    IMG_ID_CALC_KEY8,   KEY_8,  CALC_8},
            {{122,167,52,29},   IMG_ID_CALC_KEY9,   KEY_9,  CALC_9},
            {{179,167,52,29},   IMG_ID_CALC_DIVIDE, KEY_INVALID, CALC_DIV},
            {{8,199,52,29},     IMG_ID_CALC_KEY4,   KEY_4, CALC_4},
            {{65,199,52,29},    IMG_ID_CALC_KEY5,   KEY_5, CALC_5},
            {{122,199,52,29},   IMG_ID_CALC_KEY6,   KEY_6, CALC_6},
            {{179,199,52,29},   IMG_ID_CALC_MULTI,  KEY_INVALID, CALC_MULT},
            {{8,231,52,29},     IMG_ID_CALC_KEY1,   KEY_1, CALC_1},
            {{65,231,52,29},    IMG_ID_CALC_KEY2,   KEY_2, CALC_2},
            {{122,231,52,29},   IMG_ID_CALC_KEY3,   KEY_3, CALC_3},
         #ifndef __CALC_SLIM_FOR_61__
            {{179,231,52,29},   IMG_ID_CALC_SUB,    KEY_INVALID, CALC_MINUS},
         #else
		    {{179,231,52,29},   0,    KEY_INVALID, CALC_MINUS},
		 #endif
            {{8,263,52,29},     IMG_ID_CALC_KEY0,   KEY_0, CALC_0},
            {{65,263,52,29},    IMG_ID_CALC_DOT,    KEY_POUND, CALC_DOT},
            {{122,263,52,29},   IMG_ID_CALC_EQUAL,  KEY_CSK, CALC_EQUAL},
            {{179,263,52,29},   IMG_ID_CALC_PLUS,   KEY_INVALID, CALC_PLUS}
        };
        #else
        static const calc_rect_struct g_calc_output_layout =             
            {CALC_BG_X, CALC_BG_Y, UI_DEVICE_WIDTH, 67};

        static const calc_button_struct g_calc_input_layout[] = {
            {{30,CALC_KEYPAD_Y,180,33},   IMG_ID_CALC_MP,     KEY_INVALID,  CALC_MP},
            {{30,CALC_KEYPAD_Y+100,180,33},  IMG_ID_CALC_MS,     KEY_INVALID,  CALC_MM},
            {{167,CALC_KEYPAD_Y,43,133},   IMG_ID_CALC_MR,     KEY_INVALID,  CALC_MR},
            {{30,CALC_KEYPAD_Y,43,133},    IMG_ID_CALC_MC,     KEY_INVALID,  CALC_MC},
            {{73,CALC_KEYPAD_Y+33,94,34},   IMG_ID_CALC_PLUS,   KEY_INVALID,  CALC_PLUS},
          #ifndef __CALC_SLIM_FOR_61__
            {{73,CALC_KEYPAD_Y+66,94,33},   IMG_ID_CALC_SUB,    KEY_INVALID,  CALC_MINUS},
          #else
		    {{73,CALC_KEYPAD_Y+66,94,33},   0,    KEY_INVALID,  CALC_MINUS},
		  #endif
            {{73,CALC_KEYPAD_Y+33,46,67},   IMG_ID_CALC_MULTI,  KEY_INVALID,  CALC_MULT},
            {{119,CALC_KEYPAD_Y+33,48,67},   IMG_ID_CALC_DIVIDE, KEY_INVALID,  CALC_DIV}
        };
        #endif
    #elif defined   (__MMI_MAINLCD_240X400__)
        #define CALC_KEYPAD_X               0
        #define CALC_KEYPAD_Y               198
        #ifdef __MMI_TOUCH_SCREEN__
        static const calc_rect_struct g_calc_output_layout = 
            {13, CALC_BG_Y+10, 215, 80};
        static const calc_button_struct g_calc_input_layout[] = {
            {{12,CALC_BG_Y+97,50,37},   IMG_ID_CALC_MP,     KEY_INVALID,  CALC_MP},
            {{67,CALC_BG_Y+97,50,37},   IMG_ID_CALC_MS,     KEY_INVALID,  CALC_MM},
            {{122,CALC_BG_Y+97,50,37},  IMG_ID_CALC_MR,     KEY_INVALID,  CALC_MR},
            {{177,CALC_BG_Y+97,50,37},  IMG_ID_CALC_MC,     KEY_INVALID,  CALC_MC},
            {{12,CALC_BG_Y+138,50,37},  IMG_ID_CALC_KEY7,   KEY_7,  CALC_7},
            {{67,CALC_BG_Y+138,50,37},  IMG_ID_CALC_KEY8,   KEY_8,  CALC_8},
            {{122,CALC_BG_Y+138,50,37}, IMG_ID_CALC_KEY9,   KEY_9,  CALC_9},
            {{177,CALC_BG_Y+138,50,37}, IMG_ID_CALC_DIVIDE, KEY_INVALID, CALC_DIV},
            {{12,CALC_BG_Y+179,50,37},  IMG_ID_CALC_KEY4,   KEY_4, CALC_4},
            {{67,CALC_BG_Y+179,50,37},  IMG_ID_CALC_KEY5,   KEY_5, CALC_5},
            {{122,CALC_BG_Y+179,50,37}, IMG_ID_CALC_KEY6,   KEY_6, CALC_6},
            {{177,CALC_BG_Y+179,50,37}, IMG_ID_CALC_MULTI,  KEY_INVALID, CALC_MULT},
            {{12,CALC_BG_Y+220,50,37},  IMG_ID_CALC_KEY1,   KEY_1, CALC_1},
            {{67,CALC_BG_Y+220,50,37},  IMG_ID_CALC_KEY2,   KEY_2, CALC_2},
            {{122,CALC_BG_Y+220,50,37}, IMG_ID_CALC_KEY3,   KEY_3, CALC_3},
         #ifndef __CALC_SLIM_FOR_61__
            {{177,CALC_BG_Y+220,50,37}, IMG_ID_CALC_SUB,    KEY_INVALID, CALC_MINUS},
         #else
		    {{177,CALC_BG_Y+220,50,37}, 0,    KEY_INVALID, CALC_MINUS},
		 #endif
            {{12,CALC_BG_Y+261,50,37},  IMG_ID_CALC_KEY0,   KEY_0, CALC_0},
            {{67,CALC_BG_Y+261,50,37},  IMG_ID_CALC_DOT,    KEY_POUND, CALC_DOT},
            {{122,CALC_BG_Y+261,50,37}, IMG_ID_CALC_EQUAL,  KEY_CSK, CALC_EQUAL},
            {{177,CALC_BG_Y+261,50,37}, IMG_ID_CALC_PLUS,   KEY_INVALID, CALC_PLUS}
        };
        #else
        static const calc_rect_struct g_calc_output_layout = 
            {CALC_BG_X, CALC_BG_Y, UI_DEVICE_WIDTH, 70};
        static const calc_button_struct g_calc_input_layout[] = {
            {{30,CALC_KEYPAD_Y,180,33},   IMG_ID_CALC_MP,     KEY_INVALID,  CALC_MP},
            {{30,CALC_KEYPAD_Y+100,180,33},  IMG_ID_CALC_MS,     KEY_INVALID,  CALC_MM},
            {{167,CALC_KEYPAD_Y,43,133},   IMG_ID_CALC_MR,     KEY_INVALID,  CALC_MR},
            {{30,CALC_KEYPAD_Y,43,133},    IMG_ID_CALC_MC,     KEY_INVALID,  CALC_MC},
            {{73,CALC_KEYPAD_Y+33,94,34},   IMG_ID_CALC_PLUS,   KEY_INVALID,  CALC_PLUS},
          #ifndef __CALC_SLIM_FOR_61__
            {{73,CALC_KEYPAD_Y+66,94,33},   IMG_ID_CALC_SUB,    KEY_INVALID,  CALC_MINUS},
          #else
		    {{73,CALC_KEYPAD_Y+66,94,33},   0,    KEY_INVALID,  CALC_MINUS},
		  #endif
            {{73,CALC_KEYPAD_Y+33,46,67},   IMG_ID_CALC_MULTI,  KEY_INVALID,  CALC_MULT},
            {{119,CALC_KEYPAD_Y+33,48,67},   IMG_ID_CALC_DIVIDE, KEY_INVALID,  CALC_DIV}
        };
        #endif
    #elif defined   (__MMI_MAINLCD_320X240__)
        #define CALC_KEYPAD_X               40
        #define CALC_KEYPAD_Y               79
        #ifdef __MMI_TOUCH_SCREEN__
        static const calc_rect_struct g_calc_output_layout = 
            {28, CALC_BG_Y+4, 261, 61};
        static const calc_button_struct g_calc_input_layout[] = {
            {{28,CALC_BG_Y+69,62,25},   IMG_ID_CALC_MP,     KEY_INVALID,  CALC_MP},
            {{94,CALC_BG_Y+69,62,25},   IMG_ID_CALC_MS,     KEY_INVALID,  CALC_MM},
            {{160,CALC_BG_Y+69,62,25},  IMG_ID_CALC_MR,     KEY_INVALID,  CALC_MR},
            {{226,CALC_BG_Y+69,62,25},  IMG_ID_CALC_MC,     KEY_INVALID,  CALC_MC},
            {{28,CALC_BG_Y+97,62,25},  IMG_ID_CALC_KEY7,   KEY_7,  CALC_7},
            {{94,CALC_BG_Y+97,62,25},  IMG_ID_CALC_KEY8,   KEY_8,  CALC_8},
            {{160,CALC_BG_Y+97,62,25}, IMG_ID_CALC_KEY9,   KEY_9,  CALC_9},
            {{226,CALC_BG_Y+97,62,25}, IMG_ID_CALC_DIVIDE, KEY_INVALID, CALC_DIV},
            {{28,CALC_BG_Y+125,62,25},  IMG_ID_CALC_KEY4,   KEY_4, CALC_4},
            {{94,CALC_BG_Y+125,62,25},  IMG_ID_CALC_KEY5,   KEY_5, CALC_5},
            {{160,CALC_BG_Y+125,62,25}, IMG_ID_CALC_KEY6,   KEY_6, CALC_6},
            {{226,CALC_BG_Y+125,62,25}, IMG_ID_CALC_MULTI,  KEY_INVALID, CALC_MULT},
            {{28,CALC_BG_Y+153,62,25},  IMG_ID_CALC_KEY1,   KEY_1, CALC_1},
            {{94,CALC_BG_Y+153,62,25},  IMG_ID_CALC_KEY2,   KEY_2, CALC_2},
            {{160,CALC_BG_Y+153,62,25}, IMG_ID_CALC_KEY3,   KEY_3, CALC_3},
         #ifndef __CALC_SLIM_FOR_61__
            {{226,CALC_BG_Y+153,62,25}, IMG_ID_CALC_SUB,    KEY_INVALID, CALC_MINUS},
         #else
		    {{226,CALC_BG_Y+153,62,25}, 0,    KEY_INVALID, CALC_MINUS},
		 #endif
            {{28,CALC_BG_Y+181,62,25},  IMG_ID_CALC_KEY0,   KEY_0, CALC_0},
            {{94,CALC_BG_Y+181,62,25},  IMG_ID_CALC_DOT,    KEY_POUND, CALC_DOT},
            {{160,CALC_BG_Y+181,62,25}, IMG_ID_CALC_EQUAL,  KEY_CSK, CALC_EQUAL},
            {{226,CALC_BG_Y+181,62,25}, IMG_ID_CALC_PLUS,   KEY_INVALID, CALC_PLUS}
        };
        #else
        static const calc_rect_struct g_calc_output_layout = 
            {CALC_BG_X, CALC_BG_Y, UI_DEVICE_WIDTH, 67};
        static const calc_button_struct g_calc_input_layout[] = {
            {{30,CALC_KEYPAD_Y,180,33},   IMG_ID_CALC_MP,     KEY_INVALID,  CALC_MP},
            {{30,CALC_KEYPAD_Y+100,180,33},  IMG_ID_CALC_MS,     KEY_INVALID,  CALC_MM},
            {{167,CALC_KEYPAD_Y,43,133},   IMG_ID_CALC_MR,     KEY_INVALID,  CALC_MR},
            {{30,CALC_KEYPAD_Y,43,133},    IMG_ID_CALC_MC,     KEY_INVALID,  CALC_MC},
            {{73,CALC_KEYPAD_Y+33,94,34},   IMG_ID_CALC_PLUS,   KEY_INVALID,  CALC_PLUS},
         #ifndef __CALC_SLIM_FOR_61__
            {{73,CALC_KEYPAD_Y+66,94,33},   IMG_ID_CALC_SUB,    KEY_INVALID,  CALC_MINUS},
         #else
		    {{73,CALC_KEYPAD_Y+66,94,33},   0,    KEY_INVALID,  CALC_MINUS},
		 #endif
            {{73,CALC_KEYPAD_Y+33,46,67},   IMG_ID_CALC_MULTI,  KEY_INVALID,  CALC_MULT},
            {{119,CALC_KEYPAD_Y+33,48,67},   IMG_ID_CALC_DIVIDE, KEY_INVALID,  CALC_DIV}
        };
        #endif
    #elif defined   (__MMI_MAINLCD_360X640__)
        #define CALC_KEYPAD_X               0
        #define CALC_KEYPAD_Y               0

        #ifdef __MMI_TOUCH_SCREEN__
        static const calc_rect_struct g_calc_output_layout = 
            {0, 0, 0, 0};
        static const calc_button_struct g_calc_input_layout[] = {
            {{0, 0, 0, 0},   IMG_GLOBAL_EMPTY,     KEY_INVALID,  CALC_1}
        };
        #else
        static const calc_rect_struct g_calc_output_layout = 
            {0, 0, 0, 0};
        static const calc_button_struct g_calc_input_layout[] = {
            {{0, 0, 0, 0},   IMG_GLOBAL_EMPTY,     KEY_INVALID,  CALC_1}
        };
        #endif
    #else
        #define CALC_KEYPAD_X               0
        #define CALC_KEYPAD_Y               MMI_CONTENT_Y
        static const calc_rect_struct g_calc_output_layout = 
            {0, 0, 0, 0};
        static const calc_button_struct g_calc_input_layout[] = {
            {{0, 0, 0, 0},   IMG_GLOBAL_EMPTY,     KEY_INVALID,  CALC_1}
        };
    #endif
#endif

#if CALC_MEM_SUPPORT
#define CALC_OUTPUT_LINES       3
#else
#define CALC_OUTPUT_LINES       2
#endif


extern void HighlightCalcMenu(void);
static mmi_ret mmi_calc_main_scrn_proc(mmi_event_struct *evt);
static void CalcDeInit(void);
extern void CalcPreEntryApp(void);

static void calc_input_hdlr(U16 input);
#ifndef __CALC_SLIM_FOR_61__
static MMI_BOOL calc_mem_input_hdlr(U16 input);
static void calc_exception_hdlr(S32 result);
#endif /*__CALC_SLIM_FOR_61__*/
static MMI_BOOL calc_append_number(U16 input);
static MMI_BOOL calc_remove_number(void);
static MMI_BOOL calc_set_number(U16 input);
#ifndef __CALC_SLIM_FOR_61__
static void calc_reset_number(DOUBLE num);
static MMI_BOOL calc_number_inputed(void);
#endif/*__CALC_SLIM_FOR_61__*/
static S32 calc_compute_result(DOUBLE *result, DOUBLE op1, DOUBLE op2, U16 op);
static WCHAR *calc_string_format(U16 input);
#ifndef __CALC_SLIM_FOR_61__
static MMI_BOOL calc_check_boundary(DOUBLE result);
#endif/*__CALC_SLIM_FOR_61__*/
#if CALC_NAVI_HILIGHT
static U16 calc_navi_hilight(U8 key_code);
#endif
static mmi_ret calc_key_hdlr(mmi_event_struct *evt);
static void calc_lsk_hdlr(void);
static void calc_lsk_long_press_hdlr(void);
static void calc_csk_hdlr(void);
static void calc_rsk_up_hdlr(void);
static void calc_rsk_long_press_hdlr(void);
#ifdef __MMI_TOUCH_SCREEN__
static void calc_pen_down_hdlr(mmi_pen_point_struct pt);
static void calc_pen_move_hdlr(mmi_pen_point_struct pt);
static void calc_pen_long_tap_hdlr(mmi_pen_point_struct pt);
static void calc_pen_repeat_hdlr(mmi_pen_point_struct pt);
static void calc_pen_up_hdlr(mmi_pen_point_struct pt);
static calc_button_struct *calc_get_button_by_pt(mmi_pen_point_struct *pt);
#endif
static void calc_register_input_hdlr(void);
static void calc_hilight_btn(calc_button_struct *btn);
static void calc_lowlight_btn(calc_button_struct *btn);
static void calc_update_input(void);
static void calc_update_output(void);
static void calc_update_softkey(void);
static void calc_update(void);
#if CALC_NAVI_HILIGHT
static calc_button_struct *calc_get_button(U16 input);
#endif
static calc_button_struct *calc_get_button_by_shortcut(U8 shortcut);
#endif
#endif /* _MMI_CALCULATOR_H */ 

