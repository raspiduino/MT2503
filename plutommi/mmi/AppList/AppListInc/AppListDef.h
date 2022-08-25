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
 *  AppListDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  AppList OSD
 *
 * Author:
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef _MMI_APPLIST_DEF_H_
#define _MMI_APPLIST_DEF_H_

#include "mmi_features.h"
#include "MMIDataType.h"
#include "lcd_sw_inc.h"
#ifdef __MMI_LAUNCHER_APP_LIST__

#ifndef G2D_SUPPORT
/* when in edit mode, show background image instead of shaking */
#define __MMI_APPLIST_EDIT_WITH_BG__
#endif

/* [without-QC]key navigation can loop */
//#define __MMI_APPLIST_KEY_LOOP__
//key loop depend on key support
#if !defined(__MMI_APPLIST_KEY_SUPPORT__) && defined(__MMI_APPLIST_KEY_LOOP__)
#undef __MMI_APPLIST_KEY_LOOP__
#endif

/* [without-QC]scale all types of icons unless that is not enough memory */
//#define __MMI_APPLIST_SMART_ICON_SCALE__
//smart icon scale depend on G2D_SUPPORT
#if !defined(G2D_SUPPORT) && defined(__MMI_APPLIST_SMART_ICON_SCALE__)
#undef __MMI_APPLIST_SMART_ICON_SCALE__
#endif

/* [without-QC]auto adjust asm to concurrent with java, cell will not be cached when there is not enough asm */
//#define __MMI_APPLIST_SMART_ASM__

/* [without-QC]shortcut icon auto reposition when cell number change */
//#define __MMI_APPLIST_SHORTCUT_AUTO_REPOSITION__

#if ((LCD_WIDTH == 320) && (LCD_HEIGHT == 480))
/* cache path app icon to improve performance */
#define __MMI_APPLIST_CACHE_PATH_APP_ICON__
/* cache app name to improve performance */
#define __MMI_APPLIST_CACHE_APP_NAME__
#endif

#if ((LCD_WIDTH == 240) && (LCD_HEIGHT == 320)) /* QVGA */

#ifdef __MMI_APPLIST_ONLY_ICON_SUPPORT__ 

#define MMI_APPLIST_CELL_ROW_COUNT (3)
#define MMI_APPLIST_CELL_COLUMN_COUNT (4)
#define MMI_APPLIST_INDICATOR_BAR_HEIGHT (17) 
#define MMI_APPLIST_SHORTCUT_BAR_HEIGHT (61)
#define MMI_APPLIST_TITLE_BAR_HEIGHT MMI_title_height

#define MMI_APPLIST_CELL_STRING_X (1)
#define MMI_APPLIST_INTER_PAGE_MARGIN (15)

#define MMI_APPLIST_APP_ICON_WIDTH_MAX (45)
#define MMI_APPLIST_APP_ICON_HEIGHT_MAX (45)
#define MMI_APPLIST_APP_ICON_WIDTH_MIN (38)
#define MMI_APPLIST_APP_ICON_HEIGHT_MIN (38)

#else /* __MMI_APPLIST_ONLY_ICON_SUPPORT__ */

#define MMI_APPLIST_CELL_ROW_COUNT (3)
#define MMI_APPLIST_CELL_COLUMN_COUNT (4)
#define MMI_APPLIST_INDICATOR_BAR_HEIGHT (16) 
#define MMI_APPLIST_SHORTCUT_BAR_HEIGHT (71)
#define MMI_APPLIST_TITLE_BAR_HEIGHT (0)

#define MMI_APPLIST_CELL_STRING_X (1)
#define MMI_APPLIST_CELL_STRING_Y (55) /* 5 + 45 + 5 */
#define MMI_APPLIST_INTER_PAGE_MARGIN (15)

#define MMI_APPLIST_APP_ICON_WIDTH_MAX (45)
#define MMI_APPLIST_APP_ICON_HEIGHT_MAX (45)
#define MMI_APPLIST_APP_ICON_WIDTH_MIN (38)
#define MMI_APPLIST_APP_ICON_HEIGHT_MIN (38)

#define MMI_APPLIST_APP_NAME_FONT_SIZE (10)
#endif  /* __MMI_APPLIST_ONLY_ICON_SUPPORT__ */

#define MMI_APPLIST_APP_DOWNLOAD_ICON_X (14)
#define MMI_APPLIST_APP_DOWNLOAD_ICON_Y (8)

#ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
#define MMI_APPLIST_APP_UNINSTALL_ICON_WIDTH (26)
#define MMI_APPLIST_APP_UNINSTALL_ICON_HEIGHT (28) 
#endif

#elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 240)) /* LQVGA */

#define MMI_APPLIST_CELL_ROW_COUNT (2)
#define MMI_APPLIST_CELL_COLUMN_COUNT (5)
#define MMI_APPLIST_INDICATOR_BAR_HEIGHT (15) 
#define MMI_APPLIST_SHORTCUT_BAR_HEIGHT (69)
#define MMI_APPLIST_TITLE_BAR_HEIGHT (0)

#define MMI_APPLIST_CELL_STRING_X (1)
#define MMI_APPLIST_CELL_STRING_Y (54) /* 4 + 45 + 5 */
#define MMI_APPLIST_INTER_PAGE_MARGIN (15)

#define MMI_APPLIST_APP_ICON_WIDTH_MAX (45)
#define MMI_APPLIST_APP_ICON_HEIGHT_MAX (45)
#define MMI_APPLIST_APP_ICON_WIDTH_MIN (38)
#define MMI_APPLIST_APP_ICON_HEIGHT_MIN (38)

#define MMI_APPLIST_APP_DOWNLOAD_ICON_X (14)
#define MMI_APPLIST_APP_DOWNLOAD_ICON_Y (8)

#ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
#define MMI_APPLIST_APP_UNINSTALL_ICON_WIDTH (26)
#define MMI_APPLIST_APP_UNINSTALL_ICON_HEIGHT (28) 
#endif

#define MMI_APPLIST_APP_NAME_FONT_SIZE (10)


#elif ((LCD_WIDTH == 240) && (LCD_HEIGHT == 400)) /* WQVGA */

#define MMI_APPLIST_CELL_ROW_COUNT (4)
#define MMI_APPLIST_CELL_COLUMN_COUNT (4)
#define MMI_APPLIST_INDICATOR_BAR_HEIGHT (30) 
#define MMI_APPLIST_SHORTCUT_BAR_HEIGHT (70)
#define MMI_APPLIST_TITLE_BAR_HEIGHT (0)

#define MMI_APPLIST_CELL_STRING_X (1)
#define MMI_APPLIST_CELL_STRING_Y (55) /* 5 + 45 + 5 */
#define MMI_APPLIST_INTER_PAGE_MARGIN (15)

#define MMI_APPLIST_APP_ICON_WIDTH_MAX (45)
#define MMI_APPLIST_APP_ICON_HEIGHT_MAX (45)
#define MMI_APPLIST_APP_ICON_WIDTH_MIN (38)
#define MMI_APPLIST_APP_ICON_HEIGHT_MIN (38)

#define MMI_APPLIST_APP_DOWNLOAD_ICON_X (14)
#define MMI_APPLIST_APP_DOWNLOAD_ICON_Y (8)

#ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
#define MMI_APPLIST_APP_UNINSTALL_ICON_WIDTH (26)
#define MMI_APPLIST_APP_UNINSTALL_ICON_HEIGHT (28) 
#endif

#define MMI_APPLIST_APP_NAME_FONT_SIZE (10)


#elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 480))  /* HVGA */

#define MMI_APPLIST_CELL_ROW_COUNT (4)
#define MMI_APPLIST_CELL_COLUMN_COUNT (4)
#define MMI_APPLIST_INDICATOR_BAR_HEIGHT (30) 
#define MMI_APPLIST_SHORTCUT_BAR_HEIGHT (86)
#define MMI_APPLIST_TITLE_BAR_HEIGHT (0)

#define MMI_APPLIST_CELL_STRING_X (1)
#define MMI_APPLIST_CELL_STRING_Y (68) /* 5 + 57 + 6*/
#define MMI_APPLIST_INTER_PAGE_MARGIN (20)

#define MMI_APPLIST_APP_ICON_WIDTH_MAX (57)
#define MMI_APPLIST_APP_ICON_HEIGHT_MAX (57)
#define MMI_APPLIST_APP_ICON_WIDTH_MIN (48)
#define MMI_APPLIST_APP_ICON_HEIGHT_MIN (48)

#define MMI_APPLIST_APP_DOWNLOAD_ICON_X (14)
#define MMI_APPLIST_APP_DOWNLOAD_ICON_Y (8)

#ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
#define MMI_APPLIST_APP_UNINSTALL_ICON_WIDTH (33)
#define MMI_APPLIST_APP_UNINSTALL_ICON_HEIGHT (35) 
#endif

#define MMI_APPLIST_APP_NAME_FONT_SIZE (13)


#else /* other LCD size */
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */

//TODO: modify as const value
#define MMI_APPLIST_APP_COUNT_PER_PAGE (MMI_APPLIST_CELL_ROW_COUNT * MMI_APPLIST_CELL_COLUMN_COUNT)
#define MMI_APPLIST_CELL_WIDTH (LCD_WIDTH / MMI_APPLIST_CELL_COLUMN_COUNT)
#define MMI_APPLIST_CELL_HEIGHT (MMI_APPLIST_SHORTCUT_BAR_HEIGHT)
#define MMI_APPLIST_SLIDE_AREA_HEIGHT (MMI_APPLIST_CELL_HEIGHT * MMI_APPLIST_CELL_ROW_COUNT)
#define MMI_APPLIST_SLIDE_AREA_Y (MMI_STATUS_BAR_HEIGHT + MMI_APPLIST_TITLE_BAR_HEIGHT)
#define MMI_APPLIST_INDICATOR_BAR_Y (MMI_STATUS_BAR_HEIGHT + MMI_APPLIST_TITLE_BAR_HEIGHT+ MMI_APPLIST_SLIDE_AREA_HEIGHT)
#define MMI_APPLIST_SHORTCUT_BAR_Y (MMI_STATUS_BAR_HEIGHT + MMI_APPLIST_TITLE_BAR_HEIGHT + MMI_APPLIST_SLIDE_AREA_HEIGHT + MMI_APPLIST_INDICATOR_BAR_HEIGHT)
#define MMI_APPLIST_PAGE_WIDTH_INC_MARGIN (LCD_WIDTH + MMI_APPLIST_INTER_PAGE_MARGIN)
#define MMI_APPLIST_MAX_PAGE_NUM ((MMI_APPLIST_PANEL_APP_NUM + MMI_APPLIST_APP_COUNT_PER_PAGE - 1) / MMI_APPLIST_APP_COUNT_PER_PAGE)
           
#define MMI_APPLIST_INDICATOR_SIDE (7)

#ifndef __MMI_APPLIST_ONLY_ICON_SUPPORT__
#define MMI_APPLIST_STRING_REGION MMI_APPLIST_CELL_WIDTH - (MMI_APPLIST_CELL_STRING_X<<1)
#define MMI_APPLIST_STRING_SCROLL_SPACE_LEN 6
#endif

#define MMI_APPLIST_KEY_LONG_PRESS_DELAY_FIRST_TIME (800)
#define MMI_APPLIST_KEY_LONG_PRESS_DELAY (500)

#ifdef __MMI_APPLIST_KEY_SUPPORT__
#define MMI_APPLIST_CELL_STRING_SCROLL_DELAY (400)
#define MMI_APPLIST_CELL_STRING_SCROLL_SPEED (2)
#else
#define MMI_APPLIST_CELL_TOUCHED_OPACITY (100)
#define MMI_APPLIST_CELL_NORMAL_OPACITY (255)
#endif

#ifdef G2D_SUPPORT
#define MMI_APPLIST_CELL_SHAKE_ROTATE_ANGLE (3)
#define MMI_APPLIST_CELL_SHAKE_DURATION (300)
#endif

#define MMI_APPLIST_CELL_SELECTED_RESIZE (1.2f)
#define MMI_APPLIST_CELL_NORMAL_RESIZE (1.0f)

#define MMI_APPLIST_ENTER_EDIT_MODE_DELAY (300)
#define MMI_APPLIST_ENTER_SELECTED_DELAY_IN_EDIT (200)
#define MMI_APPLIST_ENTER_ORGANIZE_CELL_DELAY (80)


#ifdef __MMI_TOUCH_SCREEN__
#define MMI_APPLIST_HIGHLIGHT_CHANGE_DELAY (200)

#define MMI_APPLIST_SLIDE_MARGIN (LCD_WIDTH/3)

#define MMI_APPLIST_CANCEL_EDIT_THRESHOLD_X (5)
#define MMI_APPLIST_CANCEL_EDIT_THRESHOLD_Y (40)

#define MMI_APPLIST_PAGE_SWIPE_TIME_THRESHOLD (600)
#define MMI_APPLIST_PAGE_SWIPE_DIST_THRESHOLD (10)
#endif


#define MMI_APPLIST_PAGE_AUTO_SLIDE_THRESHOLD (MMI_APPLIST_APP_ICON_WIDTH_MIN/2)
#define MMI_APPLIST_PAGE_AUTO_SLIDE_DELAY (1200)
#define MMI_APPLIST_PAGE_SLIDE_DURATION (300)
#define MMI_APPLIST_PAGE_SLIDE_BY_KEY_DURATION (400)
#define MMI_APPLIST_MOVE_POSITION_DURATION (200)

#define MMI_APPLIST_AUTO_ANIMA_DURATION (250)

#define MMI_APPLIST_UPDATE_ANIMA_QUEUE_DELAY (0)//(30)

/* the first enter we will just cache one page, and start this timer to cache more */
#define MMI_APPLIST_QUIET_CACHE_DELAY (800)

#define MMI_APPLIST_WALLPAPER_DELAY_TIME (500)

#if (MMI_APPLIST_PANEL_APP_NUM % MMI_APPLIST_APP_COUNT_PER_PAGE != 0)
#error "applist setting NVRAM length is wrong"
#endif

#define MMI_APPLIST_IVLW_MEM_SIZE   (0)

//IVLW will use anonymous to alloc memory, if ASM pool is not large enough, it will alloc fail, you can define this to enlarge ASM pool
//#define MMI_APPLIST_ENLARGE_ASM_POOL

#if defined(MMI_APPLIST_ENLARGE_ASM_POOL) && defined(__MMI_APPLIST_ONLY_ICON_SUPPORT__) && !defined(__MMI_FTE_SUPPORT__)
#if defined(__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__)
    #undef MMI_APPLIST_IVLW_MEM_SIZE
    #define MMI_APPLIST_IVLW_MEM_SIZE   (819200)  //(800*1024)
#elif defined(__MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__)
    #undef MMI_APPLIST_IVLW_MEM_SIZE
    #define MMI_APPLIST_IVLW_MEM_SIZE   (409600)  //(400*1024)
#endif
#endif  //defined(MMI_APPLIST_ENLARGE_ASM_POOL) && defined(__MMI_APPLIST_ONLY_ICON_SUPPORT__) && !defined(__MMI_FTE_SUPPORT__)  


#endif /* __MMI_LAUNCHER_APP_LIST__ */

#endif /* _MMI_APPLIST_DEF_H_ */
