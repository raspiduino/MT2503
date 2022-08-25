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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  ImgViewerConfig.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Configuration of Imageviewer App.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 ****************************************************************************/

#ifndef _IMG_VIEWER_CONFIG_H_
#define _IMG_VIEWER_CONFIG_H_

#include "MMI_features.h"
#include "wgui.h"

#ifdef __MMI_IMAGE_VIEWER__

#ifdef __MMI_IMAGE_VIEWER_EX__  /* Ex use the old code */

#include "ImageViewerEXAppGprot.h"

#define IV_TOTAL_SCREEN_MEMORY_SIZE (MMI_IVEX_TOTAL_SCREEN_BASED_MEMORY_SIZE)

#else /* __MMI_IMAGE_VIEWER_EX__ */ /* Slim & Adv use the new code */

#include "MMIDataType.h"
#include "MediaAppPanel.h"
#include "MediaAppFrame.h"
#ifndef __RESOURCE_GEN_
#include "flash_opt.h"
#endif


#ifndef __GDI_MEMORY_PROFILE_2__
#define IV_CACHE_MEMORY_SIZE (LCD_WIDTH * LCD_HEIGHT * GDI_COLOR_FORMAT_16)
#endif

 /* User Config */
#if defined(__MMI_IMAGE_VIEWER_BASIC__)
#ifndef __MMI_WEARABLE_DEVICE__
#undef __MMI_IVF_SLIDE__       /* slide show */
#undef  __MMI_IVF_OSD__         /* will have title, softkey bar(text or image style), panel(depends on __MMI_IVF_PANEL__) */
#undef __MMI_IVF_OSD_SK_TEXT__ /* softkey style: with text in place of icon */
#else
#define __MMI_IVF_SLIDE__       /* slide show */
#define __MMI_IVF_OSD__         /* will have title, softkey bar(text or image style), panel(depends on __MMI_IVF_PANEL__) */
#define __MMI_IVF_OSD_SK_TEXT__ /* softkey style: with text in place of icon */
#endif
#define  __MMI_IVF_OPTION__      /* options */
#undef  __MMI_IVF_ZOOM__        /* Zoom & Pan */
#undef  __MMI_IVF_OSD_PANEL__   /* If with panel */
#undef __MMI_IVF_OSD_FADE__
#undef  __MMI_IVF_SWITCH_EFFECT__
#undef  __MMI_IV_NEW_MEM__      /* if use new memory mechanism */
#define __MMI_IVF_ROTATE__   /* Rotate UI feature */
#elif defined(__MMI_IMAGE_VIEWER_STD__)

#define __MMI_IVF_OPTION__      /* options */
#define __MMI_IVF_SLIDE__       /* slide show */
#define __MMI_IVF_ZOOM__        /* Zoom & Pan */
#define __MMI_IVF_OSD__         /* will have title, softkey bar(text or image style), panel(depends on __MMI_IVF_PANEL__) */
#define __MMI_IVF_OSD_PANEL__   /* If with panel, depends __MMI_TOUCH_SCREEN__, __MMI_IVF_ZOOM__ &  __MMI_IVF_OSD__ */
#undef __MMI_IVF_OSD_FADE__
#define __MMI_IVF_OSD_SK_TEXT__ /* softkey style: with text in place of icon */
#define __MMI_IVF_SWITCH_EFFECT__
#undef  __MMI_IV_NEW_MEM__      /* if use new memory mechanism */

#if defined(__MMI_IMGVIEW_CACHE__)
#define __MMI_IVF_CACHE__
#define __MMI_IVF_CACHE_L1__
#define __MMI_IVF_CACHE_DB__
#elif defined(__MMI_IVF_SWITCH_EFFECT__)
#undef __MMI_IVF_SWITCH_EFFECT__    /* switch effect dependents on cache */
#endif

#endif 

#if !defined(__MMI_IVF_CACHE__)
#ifdef __MMI_IVF_CACHE_L1__
#undef __MMI_IVF_CACHE_L1__
#endif 
#ifdef __MMI_IVF_CACHE_DB__
#undef __MMI_IVF_CACHE_DB__
#endif 
#endif /* !defined(__MMI_IVF_CACHE__) */ 

#if defined(__MMI_IVF_SWITCH_EFFECT__)
#if !defined(__MMI_IVF_CACHE_L1__)
#error Please turn on __MMI_IVF_CACHE_L1__ when __MMI_IVF_SWITCH_EFFECT__ is on
#endif 
#endif /* defined(__MMI_IVF_SWITCH_EFFECT__) */ 

/* Storage selector, depends on filemgr */
#if !defined (__MMI_ULTRA_SLIM_FILE_MANAGER__) || defined (__PUBLIC_DRIVE_AVAILABLE__)
#define __MMI_IVF_STORAGE__
#endif

/* Motion */
#ifdef MOTION_SENSOR_SUPPORT
#define __MMI_IVF_MOTION__
#endif /* MOTION_SENSOR_SUPPORT */

/* touch screen */
#ifdef __MMI_TOUCH_SCREEN__
#define __MMI_IVF_TOUCH_SCREEN__
#endif

/* Pen drag out another image and switch */
#if defined(__MMI_IVF_SWITCH_EFFECT__) && defined(__MMI_IVF_TOUCH_SCREEN__)
#define __MMI_IVF_DRAG_SWITCH__
#endif

/* Gif decode */
#ifdef GIF_DECODE
#define __MMI_IVF_ANIM_SUPPORT__
#endif

/*******************************************
 * Check depends
 *******************************************/
#if (!defined(__MMI_IVF_TOUCH_SCREEN__) || !defined(__MMI_IVF_ZOOM__) || !defined(__MMI_IVF_OSD__))
#undef __MMI_IVF_OSD_PANEL__
#endif

#if (!defined(__MMI_IVF_OSD__))
#undef __MMI_IVF_OSD_SK_TEXT__
#endif

/*******************************************
 * Constants Definition
 *******************************************/
#define IV_MAX_IMG_SIZE                 46340   /* square root of (2^31-1), for avoid S32 overflow */

#ifdef __MMI_IVF_SLIDE__
#define MMI_IV_SLIDE_PLAY_INTERVAL    2000
#define MMI_IV_SLIDE_RELOAD_INTERVAL  30
#endif /* __MMI_IVF_SLIDE__ */

#ifdef __MMI_IVF_ZOOM__ /* Zoom &¡¡Pan */
#define MMI_IVF_ZOOM_CACHE_W    (2*LCD_WIDTH)
#define MMI_IVF_ZOOM_CACHE_H    (2*LCD_HEIGHT)

#define MMI_IV_ZOOM_INTERVAL    (60)
#define MMI_IV_ZOOM_STEP        (2)     /* val / 10 */

#define MMI_IV_PAN_INTERVAL    (100)
#define MMI_IV_PAN_STEP        (30)     /* for key pan */
#endif /* __MMI_IVF_ZOOM__ */

#ifdef __MMI_IVF_OSD__  /* OSD feature */
#define MMI_IV_OSD_ANIM_INTERVAL      40
#define MMI_IV_OSD_SHOW_INTERVAL      3000
#endif /* __MMI_IVF_OSD__ */

#define IV_LAYER_CF               GDI_COLOR_FORMAT_16
#define IV_LAYER_BIT_PER_PIXEL    16

#define IV_OSD_LAYER_CF         GDI_COLOR_FORMAT_16
#define IV_OSD_BIT_PER_PIXEL    16

#define IV_OSD_PANEL_ICON_BAR_BG_COLOR  (GDI_COLOR_TRANSPARENT) /* gdi_act_color_from_rgb(255, 248, 248, 248)) */
#define IV_OSD_PANEL_SK_BAR_BG_COLOR    (GDI_COLOR_TRANSPARENT)

#define IV_ALIGN_4(size)        (((size)+3) & (~0x3))

/************************************************
 *  size of panel and title
 ************************************************/
#ifdef __MMI_FTE_SUPPORT__

#if ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
#define IV_PANEL_SK_BAR_H   (35)    /* DUMMY VALUE, NOT READY */
#define IV_PANEL_ICON_BAR_H (31)
#define IV_PANEL_ICON_BAR_BOTTOM_MARGIN (6)
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 400) )
#define IV_PANEL_SK_BAR_H   (35)    /* DUMMY VALUE, NOT READY */
#define IV_PANEL_ICON_BAR_H (31)
#define IV_PANEL_ICON_BAR_BOTTOM_MARGIN (4)
#elif (( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480) ) || ( (LCD_WIDTH == 360) && (LCD_HEIGHT == 640) )  || ( (LCD_WIDTH == 480) && (LCD_HEIGHT == 800) ))
#define IV_PANEL_SK_BAR_H   (57)    /* DUMMY VALUE, NOT READY */
#define IV_PANEL_ICON_BAR_H (47)
#define IV_PANEL_ICON_BAR_BOTTOM_MARGIN (7)
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 240) )
#define IV_PANEL_SK_BAR_H   (35)    /* DUMMY VALUE, NOT READY */
#define IV_PANEL_ICON_BAR_H (31)
#define IV_PANEL_ICON_BAR_BOTTOM_MARGIN (6)
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
#define IV_PANEL_SK_BAR_H   (57)    /* DUMMY VALUE, NOT READY */
#define IV_PANEL_ICON_BAR_H (47)
#define IV_PANEL_ICON_BAR_BOTTOM_MARGIN (7)
#else
#error "[Image viewer]Please add new IV_PANEL_TOT_H configuration according to new LCD resolution"
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */

#else /* __MMI_FTE_SUPPORT__ */

#if ( (LCD_WIDTH == 128) && (LCD_HEIGHT == 128) || (LCD_WIDTH == 128) && (LCD_HEIGHT == 160) )
#define IV_PANEL_SK_BAR_H   (20)
#define IV_PANEL_ICON_BAR_H (25)
#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
#define IV_PANEL_SK_BAR_H   (28)
#define IV_PANEL_ICON_BAR_H (28)
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
#define IV_PANEL_SK_BAR_H   (35)    /* DUMMY VALUE, NOT READY */
#define IV_PANEL_ICON_BAR_H (35)
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 240) )
#define IV_PANEL_SK_BAR_H   (35)    /* DUMMY VALUE, NOT READY */
#define IV_PANEL_ICON_BAR_H (35)
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
#define IV_PANEL_SK_BAR_H   (35)    /* DUMMY VALUE, NOT READY */
#define IV_PANEL_ICON_BAR_H (35)
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 400) )
#define IV_PANEL_SK_BAR_H   (35)    /* DUMMY VALUE, NOT READY */
#define IV_PANEL_ICON_BAR_H (35)
#elif (( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480) ) || ( (LCD_WIDTH == 360) && (LCD_HEIGHT == 640) )  || ( (LCD_WIDTH == 480) && (LCD_HEIGHT == 800) ))
#define IV_PANEL_SK_BAR_H   (35)    /* DUMMY VALUE, NOT READY */
#define IV_PANEL_ICON_BAR_H (35)
#else
#define IV_PANEL_SK_BAR_H   (20)    /* DUMMY VALUE, NOT READY */
#define IV_PANEL_ICON_BAR_H (25)
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */

#endif /* __MMI_FTE_SUPPORT__ */

#ifndef IV_PANEL_ICON_BAR_BOTTOM_MARGIN
#define IV_PANEL_ICON_BAR_BOTTOM_MARGIN (0)
#endif

#ifdef __MMI_IVF_OSD_PANEL__
#define IV_PANEL_H  (MMI_SOFTKEY_HEIGHT + IV_PANEL_ICON_BAR_H)
#else 
#define IV_PANEL_H  (MMI_SOFTKEY_HEIGHT)
#endif 

#define IV_PANEL_X         (0)
#define IV_PANEL_Y         (LCD_HEIGHT - IV_PANEL_H)
#define IV_PANEL_W         (LCD_WIDTH)

#define IV_MAX_TITLE_LINE      1
#define IV_TITLE_LINE_H        50
#define IV_TITLE_X   (0)
#define IV_TITLE_Y   (0)
#if (LCD_WIDTH > LCD_HEIGHT)
#define IV_TITLE_W         (LCD_WIDTH)
#else
#define IV_TITLE_W         (LCD_HEIGHT)
#endif

#define IV_TITLE_H         (IV_MAX_TITLE_LINE * IV_TITLE_LINE_H)
#define IV_TITLE_MIN_MARGIN   (4)

/************************************************
 *  Cache memory config
 ************************************************/
#define IV_CACHE_SIZE_UNIT          ((LCD_WIDTH * LCD_HEIGHT * IV_LAYER_BIT_PER_PIXEL) >> 3)

#if defined(__MMI_IVF_CACHE_L1__)
#define IV_CACHE_COUNT_IN_MED       2
#else /* defined(__MMI_IVF_CACHE_L1__) */ 
#define IV_CACHE_COUNT_IN_MED       0
#endif /* defined(__MMI_IVF_CACHE_L1__) */ 
#define IV_CACHE_COUNT_IN_SCR       1

/************************************************
 *  screen based memory
 ************************************************/
#ifdef __MMI_IVF_OSD__
#define IV_OSD_TITLE_SIZE   IV_ALIGN_4((IV_TITLE_W*IV_TITLE_H*IV_OSD_BIT_PER_PIXEL>>3))
#define IV_OSD_PANEL_SIZE   IV_ALIGN_4((IV_PANEL_W*IV_PANEL_H*IV_OSD_BIT_PER_PIXEL>>3))

#ifdef __MMI_IVF_OSD_PANEL__
#define IV_ICON_COUNT     6
#else
#define IV_ICON_COUNT     2
#endif

#define IV_APP_SCREEN_MEMORY_SIZE   (IV_OSD_TITLE_SIZE + IV_OSD_PANEL_SIZE \
                                                    + MEDIA_APP_FRAME_SIZE(2, IV_ICON_COUNT))

#else /* __MMI_IVF_OSD__ */
#define IV_APP_SCREEN_MEMORY_SIZE   (0)
#endif /* __MMI_IVF_OSD__ */

#ifdef __MMI_IVF_CACHE__
#define IV_CACHE_SCREEN_MEMORY_SIZE (MMI_IVC_RUN_BUF_SIZE + (IV_CACHE_COUNT_IN_SCR * IV_CACHE_SIZE_UNIT))
#else 
#define IV_CACHE_SCREEN_MEMORY_SIZE (0)
#endif 

#define IV_TOTAL_SCREEN_MEMORY_SIZE (IV_APP_SCREEN_MEMORY_SIZE + IV_CACHE_SCREEN_MEMORY_SIZE)

/************************************************
 *  med memory
 ************************************************/
#ifdef __MMI_IVF_ZOOM__
#define IV_LARGE_CACHE_SIZE         IV_ALIGN_4((MMI_IVF_ZOOM_CACHE_W * MMI_IVF_ZOOM_CACHE_H*IV_LAYER_BIT_PER_PIXEL)>>3)
#else 
#define IV_LARGE_CACHE_SIZE         (0)
#endif 

#define IV_TOTAL_MED_MEMORY_SIZE    (IV_LARGE_CACHE_SIZE + (IV_CACHE_COUNT_IN_MED) * IV_CACHE_SIZE_UNIT)

//#define __MMI_IVC_DB_DEBUG__
//#define __MMI_IVC_MEASURE_PERFORMANCE__
//#define __MMI_IVC_LAYER_DEBUG__
#if !defined(WIN32)
#undef __MMI_IVC_LAYER_DEBUG__
#endif 

#include "ImgViewerCacheGProt.h"        /* Must include this for MMI_IVC_RUN_BUF_SIZE */

#endif /* __MMI_IMAGE_VIEWER_EX__ */
#endif /* __MMI_IMAGE_VIEWER__ */

#endif /* _IMG_VIEWER_CONFIG_H_ */

