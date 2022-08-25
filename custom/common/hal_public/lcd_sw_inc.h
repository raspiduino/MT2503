/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 * 
 * Filename:
 * ---------
 *    lcd_sw_inc.h
 *
 * Project:
 * --------
 *    Maui_Software
 *
 * Description:
 * ------------
 *    This file is abstract LCD driver functions and defination for MMI.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * $Log$
 *
 * 01 06 2014 edwardyc.lin
 * removed!
 *
 * 01 23 2013 joey.pan
 * removed!
 * Merge main lcd bw modification.
 *
 * 11 10 2011 ct.fang
 * removed!
 * .
 *
 * 11 03 2011 ct.fang
 * removed!
 * .
 *
 * 11 03 2011 chaoyuan.huang
 * removed!
 * add 128*64 LCD SIZE
 *
 * 10 27 2011 ct.fang
 * removed!
 * .
 * 
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _LCD_SW_INC_H
#define _LCD_SW_INC_H

/****************************************************************************
 * Include Directives
 ****************************************************************************/
#include "lcd_hw.h" // For LCM driver project-dependent definitions
#ifdef FPGA
#include "lcd_feature.h"
#endif

/****************************************************************************
 * Macro Definitions
 ****************************************************************************/
#ifndef LCM_DPI
#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif
#endif

/**
 *  \def MULTIMEDIA_DISPLAY_COLOR_FMT_BPP
 *  Defines the BPP of display frame buffer, this is usually defined by driver and middleware but not by customers.
 *  \remark Project-dependent [TBD].
 *  \remark Do not use this macro definition in future if BPP is not 16...This is not customiziable for now.
 */
#define MULTIMEDIA_DISPLAY_COLOR_FMT_BPP (16) // (16)

/**
 *  \def LCD_WIDTH
 *  MMI width.
 *  \remark Chip/project independent, you don't need to modify this macro unless a new MMI resolution is supported.
 *
 *  \def LCD_HEIGHT
 *  MMI height.
 *  \remark Chip/project independent, you don't need to modify this macro unless a new MMI resolution is supported.
 */
#if defined(__MMI_MAINLCD_96X64__) 
    #define LCD_WIDTH           (96)
    #define LCD_HEIGHT            (64) 
#elif defined(__MMI_MAINLCD_128X128__)
    #define LCD_WIDTH           (128)
    #define LCD_HEIGHT            (128)
#elif defined(__MMI_MAINLCD_128X64__)
    #define LCD_WIDTH           (128)
    #define LCD_HEIGHT            (64)

#elif defined(__MMI_MAINLCD_128X160__)
    #define LCD_WIDTH           (128)
    #define LCD_HEIGHT            (160)
#elif defined(__MMI_MAINLCD_160X128__)
    #define LCD_WIDTH           (160)
    #define LCD_HEIGHT            (128)
#elif defined(__MMI_MAINLCD_176X220__)
    #define LCD_WIDTH           (176)
    #define LCD_HEIGHT            (220)
#elif defined(__MMI_MAINLCD_220X176__)
    #define LCD_WIDTH           (220)
    #define LCD_HEIGHT            (176)
#elif defined(__MMI_MAINLCD_240X320__)
    #define LCD_WIDTH           (240)
    #define LCD_HEIGHT            (320)
#elif defined(__MMI_MAINLCD_320X240__)
    #define LCD_WIDTH           (320)
    #define LCD_HEIGHT            (240)
#elif defined(__MMI_MAINLCD_240X240__)
    #define LCD_WIDTH           (240)
    #define LCD_HEIGHT            (240)	
#elif defined(__MMI_MAINLCD_240X400__)
    #define LCD_WIDTH           (240)
    #define LCD_HEIGHT            (400)
#elif defined(__MMI_MAINLCD_400X240__)
    #define LCD_WIDTH           (400)
    #define LCD_HEIGHT            (240)
#elif defined(__MMI_MAINLCD_240X432__)
    #define LCD_WIDTH           (240)
    #define LCD_HEIGHT            (432)
#elif defined(__MMI_MAINLCD_432X240__)
    #define LCD_WIDTH           (432)
    #define LCD_HEIGHT            (240)
#elif defined(__MMI_MAINLCD_320X480__)
    #define LCD_WIDTH           (320)
    #define LCD_HEIGHT            (480)
#elif defined(__MMI_MAINLCD_480X320__)
    #define LCD_WIDTH           (480)
    #define LCD_HEIGHT            (320)
#elif defined(__MMI_MAINLCD_360X640__)
    #define LCD_WIDTH           (360)
    #define LCD_HEIGHT            (640)
#elif defined(__MMI_MAINLCD_640X360__)
    #define LCD_WIDTH           (640)
    #define LCD_HEIGHT            (360)
#elif defined(__MMI_MAINLCD_480X800__)
    #define LCD_WIDTH           (480)
    #define LCD_HEIGHT            (800)
#elif defined(__MMI_MAINLCD_800X480__)
    #define LCD_WIDTH           (800)
    #define LCD_HEIGHT            (480)
#else
    #error  "No proper Main LCD size found in lcd_sw_inc.h !!"
#endif

/**
 *  \def SUBLCD_WIDTH
 *  Defines SUB LCD width.
 *  \remark Chip/project-independent.
 *  \todo Check makefile...this should also be decided like LCD_WIDTH.
 *  
 *  \def SUBLCD_HEIGHT
 *  Defines SUB LCD height.
 *  \remark Chip/project-independent.
 *  \todo Check makefile...this should also be decided like LCD_HEIGHT.
 */
#ifdef DUAL_LCD
    #define SUBLCD_WIDTH            (128)
    #define SUBLCD_HEIGHT           (128)
#endif

/**
 *  \def UI_DEVICE_WIDTH
 *  Defines MMI width.
 *  \remark Chip/project-independent.
 *  
 *  \def UI_DEVICE_HEIGHT
 *  Defines MMI height.
 *  \remark Chip/project independent.
 */
#define UI_DEVICE_WIDTH             LCD_WIDTH
#define UI_DEVICE_HEIGHT            LCD_HEIGHT

#endif  // _LCD_SW_INC_H

