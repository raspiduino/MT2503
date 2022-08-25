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
 *    lcd_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for LCD driver.
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

 
#ifndef _LCD_HW_H
#define _LCD_HW_H
 
// If you like to add any data type definitions in this header, please include KAL headers
// For example
#include "kal_general_types.h"

 /****************************************************************************
  *  Macro Definitions
  ****************************************************************************/
 /**
  *  \def LCM_DPI
  *  Defines LCM DPI value.
  *  \remark project-dependent
  *  \warning! The macro is exported, you cannot rename or remove it.
  */
#define LCM_DPI (162)
 
 /**
  *  \def WHITE_BACKLIGHT
  *  Backlight is white color
  *  \remark one of the three macros must be defined WHITE_BACKLIGHT, BLACK_BACKLIGHT, BLUE_BACKLIGHT
  *  \remark project-dependent
  *  \warning! The macro is exported, you cannot rename or remove it.
  */
#define WHITE_BACKLIGHT
 //#define BLACK_BACKLIGHT
 //#define BLUE_BACKLIGHT
 
 /**
  *  \def DRV_MAINLCD_BIT_PER_PIXEL
  *  Main LCD BPP, 16 for RGB565, 24 for RGB888, 32 for ARGB8888, 1 for mono B/W, ...
  *  \warning! The macro is exported, you cannot rename or remove it. You can only modify the value.
  */
#if defined(__MMI_DISPLAY_TYPE_COLOR__)
  #define DRV_MAINLCD_BIT_PER_PIXEL (16)
#else
  #define DRV_MAINLCD_BIT_PER_PIXEL (1)
#endif
 
#ifdef DUAL_LCD
  #ifdef COLOR_SUBLCD
    #define DRV_SUBLCD_BIT_PER_PIXEL  (16)
  #else
    #define DRV_SUBLCD_BIT_PER_PIXEL  (1)
  #endif
#endif  // #ifdef DUAL_LCD

typedef struct {
	kal_uint8 addr;
	kal_uint8 data;
} lcd_init_setting;
    // TBD

#endif   /*_LCD_HW_H*/
