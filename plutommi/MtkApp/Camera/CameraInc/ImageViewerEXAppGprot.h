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
 *  ImageViewerEXAppGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  ImageViewer's prototype header file
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_VIEWER_EX_GPROT_H_
#define _IMAGE_VIEWER_EX_GPROT_H_

#include "MMI_features.h"

#ifndef _GDI_INCLUDE_H_
#include "gdi_include.h"
#endif

#ifdef __MMI_IMAGE_VIEWER_EX__
#include "kal_general_types.h"
#include "app_mem.h"
#include "gdi_include.h"
#include "gdi_lcd_config.h"
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "MediaCacheSrvMem.h"


#include "ImageViewCuiGprot.h"

#ifndef __RESOURCE_GEN_
#include "FileMgrSrvGProt.h"
#include "FileMgrGProt.h"
#include "InlineCuiGprot.h"

#ifndef _FMGR_GPROT_H_
#include "FileMgrGprot.h"
#include "FileMgrSrvGProt.h"
#endif
#endif

#ifdef  __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
#define __IVEX_SUPPORT_IES__
#endif

#if defined(__MMI_IMAGE_VIEWER_EX_DB__) && defined(__SQLITE3_SUPPORT__)
#define __MMI_IMGVIEWEX_DB__
#endif

#ifdef __MMI_FTE_SUPPORT_SLIM__
#ifndef __IMAGE_VIEWER_EX_MEM_SLIM__
#define __IMAGE_VIEWER_EX_MEM_SLIM__
#endif
#endif

#ifdef __MMI_FTE_SUPPORT__
#if ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480) )
#define __FTE_HVGA__
#endif
#endif

#define MMI_IVEX_MAINLOCD_LAYER_SIZE (((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL)>>3))

#if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24)
#define MMI_IVEX_LAYER_SIZE (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * 3)
#else
#define MMI_IVEX_LAYER_SIZE (((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL)>>3))
#endif

#define MMI_IVEX_ALIGN_4(n)             ((((n) + 4 - 1) / 4) * 4)


#if defined(__MMI_FTE_SUPPORT__)
#ifdef __MMI_VECTOR_FONT_SUPPORT__
#define MMI_IVEX_OSD_TITLE_LAYER_CF     (GDI_COLOR_FORMAT_32)
#define MMI_IVEX_OSD_TITLE_BITS_PER_PIXEL   (32)
#else
#define MMI_IVEX_OSD_TITLE_LAYER_CF     (GDI_COLOR_FORMAT_16)
#define MMI_IVEX_OSD_TITLE_BITS_PER_PIXEL   (16)
#endif
#define MMI_IVEX_OSD_PENAL_LAYER_CF     (GDI_COLOR_FORMAT_16)
#define MMI_IVEX_OSD_PENAL_BITS_PER_PIXEL   (16)
/* TODO: check the impact of GDI_COLOR_FORMAT_16 */
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
#define MMI_IVEX_OSD_SLIDING_BAR_LAYER_CF     (GDI_COLOR_FORMAT_16)
#define MMI_IVEX_OSD_SLIDING_BAR_BITS_PER_PIXEL   (16)
#endif
#else /* __MMI_FTE_SUPPORT__ */
#define MMI_IVEX_OSD_TITLE_LAYER_CF     (GDI_COLOR_FORMAT_32)
#define MMI_IVEX_OSD_PENAL_LAYER_CF     (GDI_COLOR_FORMAT_32)
#define MMI_IVEX_OSD_TITLE_BITS_PER_PIXEL   (32)
#define MMI_IVEX_OSD_PENAL_BITS_PER_PIXEL   (32)
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
#define MMI_IVEX_OSD_SLIDING_BAR_LAYER_CF     (GDI_COLOR_FORMAT_32)
#define MMI_IVEX_OSD_SLIDING_BAR_BITS_PER_PIXEL   (32)
#endif
#endif /* __MMI_FTE_SUPPORT__ */


#ifdef __MMI_FTE_SUPPORT__
#if ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
#define MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0   (77)        /* penal shadow+penal bg+softkey bg */
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
#define MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0   (74)        /* penal shadow+penal bg+softkey bg */
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 400) )
#define MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0   (83)
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480) )
#define MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0   (99)
#elif ( ( (LCD_WIDTH == 360) && (LCD_HEIGHT == 640) )  || ( (LCD_WIDTH == 480) && (LCD_HEIGHT == 800) ) )
#define MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0   (115)
#endif
#else /* __MMI_FTE_SUPPORT__ */
#if ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
#define MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0   (55)        /* penal shadow+penal bg+softkey bg */
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
#define MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0   (83)
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
#define MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0   (75)
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 400) )
#define MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0   (83)
#elif ( ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480) ) || ( (LCD_WIDTH == 360) && (LCD_HEIGHT == 640) )  || ( (LCD_WIDTH == 480) && (LCD_HEIGHT == 800) ) )
#define MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0   (100)
#endif
#endif /* __MMI_FTE_SUPPORT__ */


#define MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0    (LCD_WIDTH)
#define MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270  (MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0)
#define MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_270 (MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0)
#define MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0    (LCD_WIDTH)
#define MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270  (LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270)
#define MMI_IVEX_OSD_TITLE_LAYER_HEIGHT     (50)

#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
#ifdef __MMI_FTE_SUPPORT__
// TODO: recheck the values with new FTE2.0 layout
// NOTE: sync the heights with height of panel(excluding softkey bar)
#if ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
#define MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 (41)
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
#define MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 (41)
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 400) )
#define MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 (41)
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480) )
#define MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 (48)
#elif ( ( (LCD_WIDTH == 360) && (LCD_HEIGHT == 640) )  || ( (LCD_WIDTH == 480) && (LCD_HEIGHT == 800) ) )
#define MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 (48)
#endif
#else /* __MMI_FTE_SUPPORT__ */
#if ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
#define MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 (25)
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
#define MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 (41)
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
#define MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 (41)
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 400) )
#define MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 (41)
#elif ( ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480) ) || ( (LCD_WIDTH == 360) && (LCD_HEIGHT == 640) )  || ( (LCD_WIDTH == 480) && (LCD_HEIGHT == 800) ) )
#define MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 (48)
#endif
#endif /* __MMI_FTE_SUPPORT__ */

#define MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0      (MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0)
#define MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270    (MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0)
#define MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270   (MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0)

#define MMI_IVEX_OSD_SLIDING_BAR_SIZE  MMI_IVEX_ALIGN_4(                                                               \
                                       (MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0 *                                       \
                                       MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 *                                       \
                                       MMI_IVEX_OSD_SLIDING_BAR_BITS_PER_PIXEL >> 3))

#endif /* __MULTIPLE_ANGLE_VIEW_SUPPORT__ */

#define MMI_IVEX_OSD_TITLE_SIZE     MMI_IVEX_ALIGN_4(                                                               \
                                    (((MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0 > MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270) ?     \
                                       MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0 : MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270) *     \
                                      MMI_IVEX_OSD_TITLE_LAYER_HEIGHT * MMI_IVEX_OSD_TITLE_BITS_PER_PIXEL >> 3))
#define MMI_IVEX_OSD_PANEL_SIZE     MMI_IVEX_ALIGN_4(                                                               \
                                    (MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0 *                                             \
                                     MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0 *                                            \
                                     MMI_IVEX_OSD_PENAL_BITS_PER_PIXEL >> 3))


#if defined(__IMAGE_VIEWER_EX_MEM_SLIM__)
#define MMI_IVEX_LARGE_CACHE_SIZE       (MMI_IVEX_LAYER_SIZE * 4)
#else
#define MMI_IVEX_LARGE_CACHE_SIZE       (MMI_IVEX_LAYER_SIZE * 9)
#endif
#define MMI_IVEX_SMALL_CACHE_SIZE       (MMI_IVEX_LAYER_SIZE / 4)
#define MMI_IVEX_LCD_CACHE_SIZE           (MMI_IVEX_LAYER_SIZE)
#define MMI_IVEX_APP_BASED_MEM_MGR   (APPLIB_MEM_GET_POOL_EXTRA_SIZE(10))


#if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24)
#define MMI_IVEX_SHOWN_IMAGE_LAYER_24BIT    (((LCD_WIDTH*LCD_HEIGHT*MAIN_MEDIA_LAYER_BITS_PER_PIXEL)>>3))
#else
#define MMI_IVEX_SHOWN_IMAGE_LAYER_24BIT    (0)
#endif
#define MMI_IVEX_LARGE_CACHE_COUNT              (1)
#if defined(__IMAGE_VIEWER_EX_MEM_SLIM__)
#define MMI_IVEX_SMALL_CACHE_PRE_COUNT      (0)
#else
#define MMI_IVEX_SMALL_CACHE_PRE_COUNT      (0)
#endif

#ifdef __MMI_IMGVIEWEX_DB__
    #define MMI_IVEX_SMALL_CACHE_NEXT_COUNT    (MMI_IVEX_SMALL_CACHE_PRE_COUNT)
    #if defined(__MMI_SRV_IES_META_DB__)
    #define MMI_IVEX_DB_BUFFER_SIZE      (SRV_MEDIACACHE_SQLITE_DB_L1_BUF_SIZE_BEST)
    #elif defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24)
    #define MMI_IVEX_DB_BUFFER_SIZE      (SRV_MEDIACACHE_SQLITE_DB_L1_BUF_SIZE_DEFAULT_24BIT)
    #else
    #define MMI_IVEX_DB_BUFFER_SIZE      (SRV_MEDIACACHE_SQLITE_DB_L1_BUF_SIZE_DEFAULT)
    #endif
#else
    #define MMI_IVEX_SMALL_CACHE_NEXT_COUNT    (MMI_IVEX_SMALL_CACHE_PRE_COUNT * 2)
    #define MMI_IVEX_DB_BUFFER_SIZE            (0)
#endif

#if defined(__IMAGE_VIEWER_EX_MEM_SLIM__)
#ifdef __IVEX_SUPPORT_IES__ /* add this for Mediacache need one cell for IES cache working cell, so need the count = original + 1 */
#define MMI_IVEX_LCD_CACHE_COUNT                   (2)
#else /*__IVEX_SUPPORT_IES__*/
#define MMI_IVEX_LCD_CACHE_COUNT                   (3)
#endif /*__IVEX_SUPPORT_IES__*/
#else
#ifdef __IVEX_SUPPORT_IES__ /* add this for Mediacache need one cell for IES cache working cell, so need the count = original + 1 */
#define MMI_IVEX_LCD_CACHE_COUNT                   (4)
#else /*__IVEX_SUPPORT_IES__*/
#define MMI_IVEX_LCD_CACHE_COUNT                   (3)
#endif /*__IVEX_SUPPORT_IES__*/
#endif

#ifdef __IVEX_SUPPORT_IES__
#define MMI_IVEX_LCD_CACHE_MAX_COUNT               (7)
#else
#define MMI_IVEX_LCD_CACHE_MAX_COUNT               (100)
#endif

#define MMI_IVEX_APP_DISPLAY_USE_COUNT       (2)   /* Current the osd use RGB565 */
#define MMI_IVEX_APP_FILE_PATH_USE_COUNT   (4)
#define MMI_IVEX_SMALL_CACHE_COUNT              (MMI_IVEX_SMALL_CACHE_PRE_COUNT + MMI_IVEX_SMALL_CACHE_NEXT_COUNT)

#define MMI_IVEX_TOTAL_SMALL_CACHE_SIZE      (MMI_IVEX_SMALL_CACHE_SIZE * MMI_IVEX_SMALL_CACHE_COUNT)
#define MMI_IVEX_TOTAL_LCD_CACHE_SIZE          (MMI_IVEX_LCD_CACHE_SIZE * MMI_IVEX_LCD_CACHE_COUNT)
#define MMI_IVEX_MAX_LCD_CACHE_SIZE          (MMI_IVEX_LCD_CACHE_SIZE * MMI_IVEX_LCD_CACHE_MAX_COUNT)
#define MMI_IVEX_TOTAL_LARGE_CACHE_SIZE      (MMI_IVEX_LARGE_CACHE_SIZE * MMI_IVEX_LARGE_CACHE_COUNT)

#define MMI_IVEX_TOTAL_APP_FILE_PATH_SIZE   (SRV_FMGR_PATH_BUFFER_SIZE * MMI_IVEX_APP_FILE_PATH_USE_COUNT)
#define MMI_IVEX_INFO_HELP_BUFFER_SIZE      (MAX_SUB_MENUS * MAX_SUB_MENU_SIZE)

#define MMI_IVEX_MEM_FOR_SRV_RUN_BUFFER         (SRV_MEDIACACHE_RUN_BUF_SIZE(MMI_IVEX_LCD_CACHE_MAX_COUNT))

#define MMI_IVEX_SMALL_CACHE_COUNT_SINGLE_VIEW              (0)
#ifdef __IVEX_SUPPORT_IES__
#define MMI_IVEX_LCD_CACHE_COUNT_SINGLE_VIEW              (2)
#else
#define MMI_IVEX_LCD_CACHE_COUNT_SINGLE_VIEW              (1)
#endif
#define MMI_IVEX_TOTAL_SMALL_CACHE_SIZE_SINGLE_VIEW      (MMI_IVEX_SMALL_CACHE_SIZE * MMI_IVEX_SMALL_CACHE_COUNT_SINGLE_VIEW)
#define MMI_IVEX_TOTAL_LCD_CACHE_SIZE_SINGLE_VIEW          (MMI_IVEX_LCD_CACHE_SIZE * MMI_IVEX_LCD_CACHE_COUNT_SINGLE_VIEW)

/* screen based memory */
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
#define MMI_IVEX_TOTAL_SCREEN_BASED_MEMORY_SIZE   ((MMI_IVEX_OSD_TITLE_SIZE + MMI_IVEX_OSD_PANEL_SIZE + MMI_IVEX_OSD_SLIDING_BAR_SIZE) > MMI_IVEX_INFO_HELP_BUFFER_SIZE ? \
                                                   (MMI_IVEX_OSD_TITLE_SIZE + MMI_IVEX_OSD_PANEL_SIZE + MMI_IVEX_OSD_SLIDING_BAR_SIZE) : MMI_IVEX_INFO_HELP_BUFFER_SIZE)
#else
#define MMI_IVEX_TOTAL_SCREEN_BASED_MEMORY_SIZE   ((MMI_IVEX_OSD_TITLE_SIZE + MMI_IVEX_OSD_PANEL_SIZE) > MMI_IVEX_INFO_HELP_BUFFER_SIZE ? \
                                                   (MMI_IVEX_OSD_TITLE_SIZE + MMI_IVEX_OSD_PANEL_SIZE) : MMI_IVEX_INFO_HELP_BUFFER_SIZE)
#endif
/* media pool memory */
#if (__MMI_IMAGE_VIEWER_EX_MEM_SRC__ == MMI_IMAGE_VIEWER_EX_MEM_SRC_ASM)

    #define MMI_IVEX_TOTAL_MED_MEM_POOL_SIZE          0
    #define MMI_IVEX_MEDAPP_DEF_SIZE                  (MMI_IVEX_DB_BUFFER_SIZE\
                                                        + MMI_IVEX_TOTAL_SMALL_CACHE_SIZE\
                                                        + MMI_IVEX_TOTAL_LARGE_CACHE_SIZE\
                                                        + MMI_IVEX_TOTAL_LCD_CACHE_SIZE)
    #define MMI_IVEX_MEDAPP_MAX_SIZE                  (MMI_IVEX_DB_BUFFER_SIZE\
                                                        + MMI_IVEX_TOTAL_SMALL_CACHE_SIZE\
                                                        + MMI_IVEX_TOTAL_LARGE_CACHE_SIZE\
                                                        + MMI_IVEX_MAX_LCD_CACHE_SIZE)
    #define MMI_IVEX_MEDAPP_SIG_SIZE                  (MMI_IVEX_TOTAL_SMALL_CACHE_SIZE_SINGLE_VIEW\
                                                        + MMI_IVEX_TOTAL_LARGE_CACHE_SIZE\
                                                        + MMI_IVEX_TOTAL_LCD_CACHE_SIZE_SINGLE_VIEW)


#elif (__MMI_IMAGE_VIEWER_EX_MEM_SRC__ == MMI_IMAGE_VIEWER_EX_MEM_SRC_MED)

    #define MMI_IVEX_TOTAL_MED_MEM_POOL_SIZE          (MMI_IVEX_DB_BUFFER_SIZE\
                                                        + MMI_IVEX_TOTAL_SMALL_CACHE_SIZE\
                                                        + MMI_IVEX_TOTAL_LARGE_CACHE_SIZE\
                                                        + MMI_IVEX_TOTAL_LCD_CACHE_SIZE)
    #define MMI_IVEX_MEDAPP_DEF_SIZE                   0
    #define MMI_IVEX_MEDAPP_MAX_SIZE                   0
    #define MMI_IVEX_MEDAPP_SIG_SIZE                   0

#else   //MMI_IVEX_MEM_SRC_DEF

    #define MMI_IVEX_TOTAL_MED_MEM_POOL_SIZE          MMI_IVEX_TOTAL_LARGE_CACHE_SIZE
    #define MMI_IVEX_MEDAPP_DEF_SIZE                  (MMI_IVEX_DB_BUFFER_SIZE\
                                                        + MMI_IVEX_TOTAL_SMALL_CACHE_SIZE + MMI_IVEX_TOTAL_LCD_CACHE_SIZE)
    #define MMI_IVEX_MEDAPP_MAX_SIZE                  (MMI_IVEX_DB_BUFFER_SIZE\
                                                        + MMI_IVEX_TOTAL_SMALL_CACHE_SIZE + MMI_IVEX_MAX_LCD_CACHE_SIZE)
    #define MMI_IVEX_MEDAPP_SIG_SIZE                  (MMI_IVEX_TOTAL_SMALL_CACHE_SIZE_SINGLE_VIEW + MMI_IVEX_TOTAL_LCD_CACHE_SIZE_SINGLE_VIEW)

#endif  //__MMI_IMAGE_VIEWER_EX_MEM_SRC__

/* App based memory which cannot exchange with MED mem */
/* when OPERA open the ASM is very large. So config IES working buffer of media cache as ASM */
#if defined(OPERA_BROWSER) && defined(__IVEX_SUPPORT_IES__)
#define MMI_IVEX_MEDCACHE_IES_WORKING_BUF_SIZE      (SRV_MEDIACACHE_IES_WORKING_BUF_SIZE)
#else
#define MMI_IVEX_MEDCACHE_IES_WORKING_BUF_SIZE      (0)
#endif

#define MMI_IVEX_APP_MEM_BASE_SIZE                (MMI_IVEX_TOTAL_APP_FILE_PATH_SIZE\
                                                  + MMI_IVEX_APP_BASED_MEM_MGR\
                                                  + MMI_IVEX_SHOWN_IMAGE_LAYER_24BIT\
                                                  + MMI_IVEX_MEM_FOR_SRV_RUN_BUFFER\
                                                  + MMI_IVEX_MEDCACHE_IES_WORKING_BUF_SIZE)

/* default App based memory size */                                                  
#define MMI_IVEX_TOTAL_APP_BASED_MEM_POOL_SIZE    (MMI_IVEX_APP_MEM_BASE_SIZE\
                                                  + MMI_IVEX_MEDAPP_DEF_SIZE)

#define MMI_IVEX_MAX_APP_BASED_MEM_POOL_SIZE     (MMI_IVEX_APP_MEM_BASE_SIZE\
                                                  + MMI_IVEX_MEDAPP_MAX_SIZE)


#define MMI_IVEX_FMGR_APP_BASED_MEM_POOL_SIZE    (MMI_IVEX_APP_MEM_BASE_SIZE\
                                                  + MMI_IVEX_MEDAPP_SIG_SIZE)

#define MMI_IVEX_APP_BASED_FRAMEBUF_OVERHEAD     (100)

typedef struct
{
    CHAR*  filepath;
    U8   rotation;
    MMI_BOOL is_show_filename;
    MMI_BOOL is_short;
}mmi_ivex_external_request;

typedef enum
{
    MMI_IVEX_SETTINGS_SPEED_CAP = CUI_INLINE_ITEM_ID_BASE + 0,
    MMI_IVEX_SETTINGS_SPEED,
}mmi_ivex_settings_items_index_enum;
extern void mmi_ivex_init_app(void);
extern void mmi_ivex_reset_app(void);
extern void mmi_ivex_preentry_view_screen(void);
/* The below APIs are for Imageview CUI */
#ifdef __MMI_RMGR__
extern void mmi_ivex_option_more_licence_execute_forward(U16 highlight_item) ;
#endif
#if defined(__MMI_BPP_SUPPORT__) || defined(__MMI_PICT_BRIDGE_SUPPORT__)
extern void mmi_ivex_option_print_execute_forward(U16 highlight_item);
#endif
extern void mmi_ivex_view_preentry_option_screen(void);
extern void mmi_ivex_view_option_entry_help_screen(void);
extern void mmi_ivex_view_option_entry_info_screen(void);
extern void mmi_ivex_option_use_init_list(void);
extern void mmi_ivex_option_use_execute_forward(U16 highlight_item) ;
extern void mmi_ivex_option_send_init_list(void);
extern void mmi_ivex_option_send_execute_forward(U16 highlight_item) ;
extern void mmi_ivex_settings_prepare_inline_data(void);
extern void mmi_ivex_view_option_settings_done(void);
extern void mmi_ivex_view_option_settings_save(void);
extern void mmi_ivex_close_settings_inline_cui(void);
extern void mmi_ivex_close_option_menu_cui(void);
extern void mmi_ivex_settings_speed_change_value(S32 value);
#if defined(__MMI_PHOTOEDITOR__)
extern void mmi_ivex_view_option_entry_photoeditor(void);
#endif
extern void mmi_ivex_print_req(void);
extern void mmi_ivex_view_option_entry_prepare_play(void);

extern void mmi_ivex_app_reset(void);
extern void mmi_ivex_set_ui_direct(mmi_id image_viewer_id, cui_imgview_ui_direction_enum direction);
extern void mmi_ivex_enter_view_from_cui(mmi_id image_viewer_id);
#else /* __MMI_IMAGE_VIEWER_EX__ */
#define MMI_IVEX_TOTAL_SCREEN_BASED_MEMORY_SIZE (0)
#define MMI_IVEX_TOTAL_APP_BASED_MEM_POOL_SIZE (0)
#define MMI_IVEX_MAX_APP_BASED_MEM_POOL_SIZE   (0)
#define MMI_IVEX_TOTAL_MED_MEM_POOL_SIZE (0)
#define MMI_IVEX_FMGR_APP_BASED_MEM_POOL_SIZE (0)
#endif /* __MMI_IMAGE_VIEWER_EX__ */

#endif /* _IMAGE_VIEWER_ADV_GPROT_H_ */

