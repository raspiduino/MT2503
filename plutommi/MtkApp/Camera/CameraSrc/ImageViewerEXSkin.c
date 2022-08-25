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
 *  ImageViewerEXSkin.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Viewer EX.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_IMAGE_VIEWER_EX__

#include "lcd_sw_inc.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "wgui.h"
#include "ImageViewerEXSkin.h"
#include "ImageViewerEXAppGProt.h"
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
#include "ImageViewerEXSlidingBar.h"
#endif

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
#ifdef __MMI_FTE_SUPPORT__
#if ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
    #define IVEX_PANEL_H_0      40
    #define IVEX_ICON_W_0       60
    #define IVEX_SK_H_GAP       95
    #define IVEX_SK_Y_OFF_0     46
    #define IVEX_SK_X_OFF_0      9

    
    #define IVEX_PANEL_W_270      40
    #define IVEX_ICON_H_270       60
    #define IVEX_SK_V_GAP         95
    #define IVEX_SK_Y_OFF_270      6    
    #define IVEX_SK_X_OFF_270     44
    ivex_osd_layout_struct g_ivex_osd_cntx_0 =
    {
        {0, LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0},       /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                      /* title */
        
        { 0, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, 0, MMI_FALSE},      /* panel shadow */
        { 0, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, IVEX_PANEL_H_0, MMI_FALSE},     /* panel background */
        {0, IVEX_PANEL_H_0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0 - IVEX_PANEL_H_0, MMI_FALSE},     /* softkey background */
        
        {0, 0, 0, 0, MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0, MMI_FALSE},      /* right arrow */
        
        { 3*IVEX_ICON_W_0, 0, IVEX_ICON_W_0, IVEX_PANEL_H_0, MMI_FALSE},   /* zoom in */
        { 2*IVEX_ICON_W_0, 0, IVEX_ICON_W_0, IVEX_PANEL_H_0, MMI_FALSE},   /* zoom out */
        { 1*IVEX_ICON_W_0, 0, IVEX_ICON_W_0, IVEX_PANEL_H_0, MMI_FALSE},    /* clockwise rotate */
        { 0*IVEX_ICON_W_0, 0, IVEX_ICON_W_0, IVEX_PANEL_H_0, MMI_FALSE},    /* counterclockwise rotate */
        
        {  IVEX_SK_X_OFF_0+0*IVEX_SK_H_GAP, IVEX_SK_Y_OFF_0, 0, 0,  MMI_FALSE},    /* left softkey */
        {  IVEX_SK_X_OFF_0+2*IVEX_SK_H_GAP, IVEX_SK_Y_OFF_0, 0, 0, MMI_FALSE},   /* right softkey */
        {  IVEX_SK_X_OFF_0+1*IVEX_SK_H_GAP, IVEX_SK_Y_OFF_0, 0, 0, MMI_FALSE},    /* center key */
    
        {99, 118, 0, 0, MMI_FALSE},   /* drm hint */
        {98, 118, 0, 0, MMI_FALSE},   /* error hint */
        {105, 145, 0, 0, MMI_FALSE},  /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},    /* title */
    };

    ivex_osd_layout_struct g_ivex_osd_cntx_270 =
    {
        {LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_270},  /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                    /* title */
        
        {0, 0, 11, 240, MMI_FALSE},      /* panel shadow */
        {0, 0, IVEX_PANEL_W_270, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_270, MMI_FALSE},     /* panel background */
        {IVEX_PANEL_W_270, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270-IVEX_PANEL_W_270, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_270, MMI_FALSE},     /* softkey background */
        
        {0, 0, 0, 0, MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0, MMI_FALSE},      /* right arrow */
        
        {0, 0*IVEX_ICON_H_270, IVEX_PANEL_W_270, IVEX_ICON_H_270, MMI_FALSE},    /* zoom in */
        {0, 1*IVEX_ICON_H_270, IVEX_PANEL_W_270, IVEX_ICON_H_270, MMI_FALSE},    /* zoom out */
        {0, 2*IVEX_ICON_H_270, IVEX_PANEL_W_270, IVEX_ICON_H_270, MMI_FALSE},   /* clockwise rotate */
        {0, 3*IVEX_ICON_H_270, IVEX_PANEL_W_270, IVEX_ICON_H_270, MMI_FALSE},   /* counterclockwise rotate */
        
        {IVEX_SK_X_OFF_270, IVEX_SK_Y_OFF_270+2*IVEX_SK_V_GAP, 0, 0, MMI_FALSE},   /* left softkey */
        {IVEX_SK_X_OFF_270, IVEX_SK_Y_OFF_270+0*IVEX_SK_V_GAP, 0, 0,   MMI_FALSE},   /* right softkey */
        {IVEX_SK_X_OFF_270, IVEX_SK_Y_OFF_270+1*IVEX_SK_V_GAP, 0, 0, MMI_FALSE},    /* center key */
        
        {139, 79, 0, 0, MMI_FALSE},   /* drm hint */
        {139, 79, 0, 0, MMI_FALSE},   /* error hint */
        {145, 105, 0, 0, MMI_FALSE},  /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},  /* title */
    };

#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    const SlidingBarLayout g_sliding_bar_layout_skin_0 = {
        {22, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 196, 25},
        {22, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 196, 25},
        {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 25, 25},
        {0/*dummy*/, 0/*dummy*/, 25, 25},
        48, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0 - 48,
        {(LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0) / 2,
         LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - MMI_SOFTKEY_HEIGHT,
         MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0,
         MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0}
    };
    
    const SlidingBarLayout g_sliding_bar_layout_skin_270 = {
        {22, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 196, 25},
        {22, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 196, 25},
        {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 25, 25},
        {0/*dummy*/, 0/*dummy*/, 25, 25},
        48, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0 - 48,
        {(LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270) / 2,
         LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 3,
         MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270,
         MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270}
    };
#endif
    
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
    #define IVEX_PANEL_H_0      38
    #define IVEX_ICON_W_0       80
    #define IVEX_SK_H_GAP      136
    #define IVEX_SK_Y_OFF_0     44
    #define IVEX_SK_X_OFF_0      8

    
    #define IVEX_PANEL_W_270      38
    #define IVEX_ICON_H_270       80
    #define IVEX_SK_V_GAP        136
    #define IVEX_SK_Y_OFF_270      8    
    #define IVEX_SK_X_OFF_270     44
    ivex_osd_layout_struct g_ivex_osd_cntx_0 =
    {
        {0, LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0},       /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                      /* title */
        
        { 0, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, 0, MMI_FALSE},      /* panel shadow */
        { 0, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, IVEX_PANEL_H_0, MMI_FALSE},     /* panel background */
        {0, IVEX_PANEL_H_0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0 - IVEX_PANEL_H_0, MMI_FALSE},     /* softkey background */
        
        {0, 0, 0, 0, MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0, MMI_FALSE},      /* right arrow */
        
        { 3*IVEX_ICON_W_0, 0, IVEX_ICON_W_0, IVEX_PANEL_H_0, MMI_FALSE},   /* zoom in */
        { 2*IVEX_ICON_W_0, 0, IVEX_ICON_W_0, IVEX_PANEL_H_0, MMI_FALSE},   /* zoom out */
        { 1*IVEX_ICON_W_0, 0, IVEX_ICON_W_0, IVEX_PANEL_H_0, MMI_FALSE},    /* clockwise rotate */
        { 0*IVEX_ICON_W_0, 0, IVEX_ICON_W_0, IVEX_PANEL_H_0, MMI_FALSE},    /* counterclockwise rotate */
        
        {  IVEX_SK_X_OFF_0+0*IVEX_SK_H_GAP, IVEX_SK_Y_OFF_0, 0, 0,  MMI_FALSE},    /* left softkey */
        {  IVEX_SK_X_OFF_0+2*IVEX_SK_H_GAP, IVEX_SK_Y_OFF_0, 0, 0, MMI_FALSE},   /* right softkey */
        {  IVEX_SK_X_OFF_0+1*IVEX_SK_H_GAP, IVEX_SK_Y_OFF_0, 0, 0, MMI_FALSE},    /* center key */
        
        {140, 76, 0, 0, MMI_FALSE},   /* drm hint */
        {139, 76, 0, 0, MMI_FALSE},   /* error hint */
        {145, 85, 0, 0, MMI_FALSE},   /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},    /* title */
    };

    ivex_osd_layout_struct g_ivex_osd_cntx_270 = /* not support rotate, should remove */
    {
        {LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_270},  /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                    /* title */
        
        { 0, 0, 11, 240, MMI_FALSE},      /* panel shadow */
        {0, 0, IVEX_PANEL_W_270, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_270, MMI_FALSE},     /* panel background */
        {IVEX_PANEL_W_270, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270-IVEX_PANEL_W_270, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_270, MMI_FALSE},     /* softkey background */
        
        {0, 0, 0, 0,  MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0,  MMI_FALSE},      /* right arrow */
        
        {0, 0*IVEX_ICON_H_270, IVEX_PANEL_W_270, IVEX_ICON_H_270, MMI_FALSE},    /* zoom in */
        {0, 1*IVEX_ICON_H_270, IVEX_PANEL_W_270, IVEX_ICON_H_270, MMI_FALSE},    /* zoom out */
        {0, 2*IVEX_ICON_H_270, IVEX_PANEL_W_270, IVEX_ICON_H_270, MMI_FALSE},   /* clockwise rotate */
        {0, 3*IVEX_ICON_H_270, IVEX_PANEL_W_270, IVEX_ICON_H_270, MMI_FALSE},   /* counterclockwise rotate */
        
        {IVEX_SK_X_OFF_270, IVEX_SK_Y_OFF_270+2*IVEX_SK_V_GAP, 0, 0, MMI_FALSE},   /* left softkey */
        {IVEX_SK_X_OFF_270, IVEX_SK_Y_OFF_270+0*IVEX_SK_V_GAP, 0, 0,   MMI_FALSE},   /* right softkey */
        {IVEX_SK_X_OFF_270, IVEX_SK_Y_OFF_270+1*IVEX_SK_V_GAP, 0, 0, MMI_FALSE},    /* center key */
        
        {0, 0, 0, 0,  MMI_FALSE},      /* drm hint */
        {0, 0, 0, 0,  MMI_FALSE},      /* error hint */
        {0, 0, 0, 0,  MMI_FALSE},      /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},  /* title */
    };

#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    const SlidingBarLayout g_sliding_bar_layout_skin_0 = {
        {26, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 39, 268, 32},
        {26, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 39, 268, 32},
        {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 39, 32, 32},
        {0/*dummy*/, 0/*dummy*/, 32, 32},
        62, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0 - 62,
        {(LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0) / 2,
         LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - MMI_SOFTKEY_HEIGHT,
         MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0,
         MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0}
    };
    
    const SlidingBarLayout g_sliding_bar_layout_skin_270 = {
        /* TODO */
        {26, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 39, 268, 32},
        {26, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 39, 268, 32},
        {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 39, 32, 32},
        {0/*dummy*/, 0/*dummy*/, 32, 32},
        62, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270 - 62,
        {(LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270) / 2,
         LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 3,
         MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270,
         MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270}
    };
#endif

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 400) )
    #define IVEX_PANEL_H_0      40
    #define IVEX_ICON_W_0       60
    #define IVEX_SK_H_GAP       95
    #define IVEX_SK_Y_OFF_0     51
    #define IVEX_SK_X_OFF_0      9

    
    #define IVEX_PANEL_W_270      40
    #define IVEX_ICON_H_270       60
    #define IVEX_SK_V_GAP         95
    #define IVEX_SK_Y_OFF_270      6
    #define IVEX_SK_X_OFF_270     44
    ivex_osd_layout_struct g_ivex_osd_cntx_0 =
    {
        {0, LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0},       /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                      /* title */
        
        { 0, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, 0, MMI_FALSE},      /* panel shadow */
        { 0, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, IVEX_PANEL_H_0, MMI_FALSE},     /* panel background */
        {0, IVEX_PANEL_H_0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0 - IVEX_PANEL_H_0, MMI_FALSE},     /* softkey background */
        
        {0, 0, 0, 0, MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0, MMI_FALSE},      /* right arrow */
        
        { 3*IVEX_ICON_W_0, 0, IVEX_ICON_W_0, IVEX_PANEL_H_0, MMI_FALSE},   /* zoom in */
        { 2*IVEX_ICON_W_0, 0, IVEX_ICON_W_0, IVEX_PANEL_H_0, MMI_FALSE},   /* zoom out */
        { 1*IVEX_ICON_W_0, 0, IVEX_ICON_W_0, IVEX_PANEL_H_0, MMI_FALSE},    /* clockwise rotate */
        { 0*IVEX_ICON_W_0, 0, IVEX_ICON_W_0, IVEX_PANEL_H_0, MMI_FALSE},    /* counterclockwise rotate */
        
        {  IVEX_SK_X_OFF_0+0*IVEX_SK_H_GAP, IVEX_SK_Y_OFF_0, 0, 0,  MMI_FALSE},    /* left softkey */
        {  IVEX_SK_X_OFF_0+2*IVEX_SK_H_GAP, IVEX_SK_Y_OFF_0, 0, 0, MMI_FALSE},   /* right softkey */
        {  IVEX_SK_X_OFF_0+1*IVEX_SK_H_GAP, IVEX_SK_Y_OFF_0, 0, 0, MMI_FALSE},    /* center key */
        
        {99, 158, 0, 0, MMI_FALSE},   /* drm hint */
        {98, 158, 0, 0, MMI_FALSE},   /* error hint */
        {105, 185, 0, 0, MMI_FALSE},  /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},    /* title */
    };

    ivex_osd_layout_struct g_ivex_osd_cntx_270 =
    {
        {LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_270},  /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                    /* title */
        
        { 0, 0, 11, 240, MMI_FALSE},      /* panel shadow */
        {0, 0, IVEX_PANEL_W_270, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_270, MMI_FALSE},     /* panel background */
        {IVEX_PANEL_W_270, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270-IVEX_PANEL_W_270, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_270, MMI_FALSE},     /* softkey background */
        
        {0, 0, 0, 0, MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0, MMI_FALSE},      /* right arrow */
        
        {0, 0*IVEX_ICON_H_270, IVEX_PANEL_W_270, IVEX_ICON_H_270, MMI_FALSE},    /* zoom in */
        {0, 1*IVEX_ICON_H_270, IVEX_PANEL_W_270, IVEX_ICON_H_270, MMI_FALSE},    /* zoom out */
        {0, 2*IVEX_ICON_H_270, IVEX_PANEL_W_270, IVEX_ICON_H_270, MMI_FALSE},   /* clockwise rotate */
        {0, 3*IVEX_ICON_H_270, IVEX_PANEL_W_270, IVEX_ICON_H_270, MMI_FALSE},   /* counterclockwise rotate */
        
        {IVEX_SK_X_OFF_270, IVEX_SK_Y_OFF_270+2*IVEX_SK_V_GAP, 0, 0, MMI_FALSE},   /* left softkey */
        {IVEX_SK_X_OFF_270, IVEX_SK_Y_OFF_270+0*IVEX_SK_V_GAP, 0, 0,   MMI_FALSE},   /* right softkey */
        {IVEX_SK_X_OFF_270, IVEX_SK_Y_OFF_270+1*IVEX_SK_V_GAP, 0, 0, MMI_FALSE},    /* center key */
        
        {179, 79, 0, 0, MMI_FALSE},   /* drm hint */
        {179, 79, 0, 0, MMI_FALSE},   /* error hint */
        {185, 105, 0, 0, MMI_FALSE},  /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},  /* title */
    };

#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    const SlidingBarLayout g_sliding_bar_layout_skin_0 = {
        {22, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 196, 25},
        {22, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 196, 25},
        {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 25, 25},
        {0/*dummy*/, 0/*dummy*/, 25, 25},
        48, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0 - 48,
        {(LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0) / 2,
         LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - MMI_SOFTKEY_HEIGHT,
         MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0,
         MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0}
    };
    
    const SlidingBarLayout g_sliding_bar_layout_skin_270 = {
        {22, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 196, 25},
        {22, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 196, 25},
        {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 25, 25},
        {0/*dummy*/, 0/*dummy*/, 25, 25},
        48, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0 - 48,
        {(LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270) / 2,
         LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 3,
         MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270,
         MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270}
    };
#endif

#elif (( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480) ) || ( (LCD_WIDTH == 360) && (LCD_HEIGHT == 640) )  || ( (LCD_WIDTH == 480) && (LCD_HEIGHT == 800) ))
    ivex_osd_layout_struct g_ivex_osd_cntx_0 =
    {
        {0, LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0},       /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                      /* title */
        
        {0, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, 16, MMI_FALSE},      /* panel shadow */
        {0, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, 48, MMI_FALSE},     /* panel background */
        {0, 48, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, 51, MMI_FALSE},     /* softkey background */
        
        {0, 0, 0, 0, MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0, MMI_FALSE},      /* right arrow */
        
        {240, 0, 80, 48, MMI_FALSE},   /* zoom in */
        {160, 0, 80, 48, MMI_FALSE},   /* zoom out */
        { 80, 0, 80, 48, MMI_FALSE},    /* clockwise rotate */
        {  0, 0, 80, 48, MMI_FALSE},    /* counterclockwise rotate */
        
        { 11, 55, 0, 0,  MMI_FALSE},     /* left softkey */
        {267, 55, 0, 0, MMI_FALSE},   /* right softkey */
        {139, 55, 0, 0, MMI_FALSE},   /* center key */
        
        {135, 193, 0, 0, MMI_FALSE},  /* drm hint */
        {135, 193, 0, 0, MMI_FALSE},  /* error hint */
        {142, 222, 0, 0, MMI_FALSE},  /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},    /* title */
    };

    ivex_osd_layout_struct g_ivex_osd_cntx_270 =
    {
        {LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_270},  /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                    /* title */

        { 0, 0, 16, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, MMI_FALSE},      /* panel shadow */
        {0, 0, 48, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, MMI_FALSE},     /* panel background */
        {48, 0, 51, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, MMI_FALSE},     /* softkey background */
        
        {0, 0, 0, 0, MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0, MMI_FALSE},      /* right arrow */
        
        {0,   0, 48, 80, MMI_FALSE},    /* zoom in */
        {0,  80, 48, 80, MMI_FALSE},    /* zoom out */
        {0, 160, 48, 80, MMI_FALSE},   /* clockwise rotate */
        {0, 240, 48, 80, MMI_FALSE},   /* counterclockwise rotate */
        
        {55, 266, 0, 0, MMI_FALSE},   /* left softkey */
        {55,  10, 0, 0,   MMI_FALSE},     /* right softkey */
        {55, 138, 0, 0, MMI_FALSE},   /* center key */
        
        {215, 113, 0, 0, MMI_FALSE},  /* drm hint */
        {215, 113, 0, 0, MMI_FALSE},  /* error hint */
        {222, 142, 0, 0, MMI_FALSE},  /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},  /* title */
    };

#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    const SlidingBarLayout g_sliding_bar_layout_skin_0 = {
        {26, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 39, 268, 32},
        {26, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 39, 268, 32},
        {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 39, 32, 32},
        {0/*dummy*/, 0/*dummy*/, 32, 32},
        62, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0 - 62,
        {(LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0) / 2,
         LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - MMI_SOFTKEY_HEIGHT,
         MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0,
         MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0}
    };
    
    const SlidingBarLayout g_sliding_bar_layout_skin_270 = {
        /* TODO */
        {26, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 39, 268, 32},
        {26, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 39, 268, 32},
        {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 39, 32, 32},
        {0/*dummy*/, 0/*dummy*/, 32, 32},
        62, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270 - 62,
        {(LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270) / 2,
         LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 3,
         MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270,
         MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270}
    };
#endif
    
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
#else  /* __MMI_FTE_SUPPORT__ */
#if ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
    ivex_osd_layout_struct g_ivex_osd_cntx_0 =
    {
        {0, LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0},       /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                      /* title */

        {0, 0, 0, 0, MMI_FALSE},      /* panel shadow */
        {0, 9, 0, 0, MMI_FALSE},      /* panel background */
        {0, 35, 0, 0, MMI_FALSE},     /* softkey background */
        
        {0, 0, 0, 0, MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0, MMI_FALSE},      /* right arrow */
        
        {136, 12, 0, 0, MMI_FALSE},   /* zoom in */
        {98, 12, 0, 0, MMI_FALSE},    /* zoom out */
        {48, 12, 0, 0, MMI_FALSE},    /* clockwise rotate */
        {10, 12, 0, 0, MMI_FALSE},    /* counterclockwise rotate */
        
        {6, 35, 0, 0,  MMI_FALSE},     /* left softkey */
        {150, 35, 0, 0, MMI_FALSE},   /* right softkey */
        {78, 35, 0, 0, MMI_FALSE},    /* center key */
        
        {73, 75, 0, 0, MMI_FALSE},    /* drm hint */
        {73, 75, 0, 0, MMI_FALSE},    /* error hint */
        {75, 97, 0, 0, MMI_FALSE},    /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},    /* title */
    };

    ivex_osd_layout_struct g_ivex_osd_cntx_270 =
    {
        {LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_270},  /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                    /* title */

        {0, 0, 0, 0, MMI_FALSE},      /* panel shadow */
        {9, 0, 0, 0, MMI_FALSE},      /* panel background */
        {35, 0, 0, 0, MMI_FALSE},     /* softkey background */
        
        {0, 0, 0, 0, MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0, MMI_FALSE},      /* right arrow */
        
        {12, 10, 0, 0, MMI_FALSE},    /* zoom in */
        {12, 48, 0, 0, MMI_FALSE},    /* zoom out */
        {12, 98, 0, 0, MMI_FALSE},    /* clockwise rotate */
        {12, 136, 0, 0, MMI_FALSE},   /* counterclockwise rotate */
        
        {35, 150, 0, 0, MMI_FALSE},   /* left softkey */
        {35, 6, 0, 0, MMI_FALSE},     /* right softkey */
        {35, 78, 0, 0, MMI_FALSE},    /* center key */
        
        {95, 54, 0, 0, MMI_FALSE},    /* drm hint */
        {95, 54, 0, 0, MMI_FALSE},    /* error hint */
        {97, 75, 0, 0, MMI_FALSE},    /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},  /* title */
    };
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
        const SlidingBarLayout g_sliding_bar_layout_skin_0 = {
            {6, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 26, 164, 21},
            {6, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 26, 164, 21},
            {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 26, 20, 21},
            {0/*dummy*/, 0/*dummy*/, 20, 21},
            30, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0 - 30,
            {(LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0) / 2,
             LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - MMI_SOFTKEY_HEIGHT,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0}
        };
        
        const SlidingBarLayout g_sliding_bar_layout_skin_270 = {
            {6, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 26, 164, 21},
            {6, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 26, 164, 21},
            {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 26, 20, 21},
            {0/*dummy*/, 0/*dummy*/, 20, 21},
            30, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0 - 30,
            {(LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270) / 2,
             LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 5,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270}
        };
#endif
    
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
    ivex_osd_layout_struct g_ivex_osd_cntx_0 =
    {
        {0, LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0},       /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                      /* title */
        
        {0, 0, 0, 0, MMI_FALSE},      /* panel shadow */
        {0, 11, 0, 0, MMI_FALSE},     /* panel background */
        {0, 52, 0, 0, MMI_FALSE},     /* softkey background */
        
        {0, 0, 0, 0, MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0, MMI_FALSE},      /* right arrow */
        
        {184, 17, 0, 0, MMI_FALSE},   /* zoom in */
        {130, 17, 0, 0, MMI_FALSE},   /* zoom out */
        {64, 17, 0, 0, MMI_FALSE},    /* clockwise rotate */
        {10, 17, 0, 0, MMI_FALSE},    /* counterclockwise rotate */
        
        {6, 54, 0, 0,  MMI_FALSE},     /* left softkey */
        {203, 54, 0, 0, MMI_FALSE},   /* right softkey */
        {103, 54, 0, 0, MMI_FALSE},   /* center key */
        
        {99, 118, 0, 0, MMI_FALSE},   /* drm hint */
        {98, 118, 0, 0, MMI_FALSE},   /* error hint */
        {105, 145, 0, 0, MMI_FALSE},  /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},    /* title */
    };

    ivex_osd_layout_struct g_ivex_osd_cntx_270 =
    {
        {LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_270},  /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                    /* title */
        
        {0, 0, 0, 0, MMI_FALSE},      /* panel shadow */
        {11, 0, 0, 0, MMI_FALSE},     /* panel background */
        {52, 0, 0, 0, MMI_FALSE},     /* softkey background */
        
        {0, 0, 0, 0, MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0, MMI_FALSE},      /* right arrow */
        
        {17, 10, 0, 0, MMI_FALSE},    /* zoom in */
        {17, 64, 0, 0, MMI_FALSE},    /* zoom out */
        {17, 130, 0, 0, MMI_FALSE},   /* clockwise rotate */
        {17, 184, 0, 0, MMI_FALSE},   /* counterclockwise rotate */
        
        {54, 205, 0, 0, MMI_FALSE},   /* left softkey */
        {54, 8, 0, 0,  MMI_FALSE},     /* right softkey */
        {54, 100, 0, 0, MMI_FALSE},   /* center key */
        
        {139, 79, 0, 0, MMI_FALSE},   /* drm hint */
        {139, 79, 0, 0, MMI_FALSE},   /* error hint */
        {145, 105, 0, 0, MMI_FALSE},  /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},  /* title */
    };
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
        const SlidingBarLayout g_sliding_bar_layout_skin_0 = {
            {22, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 196, 25},
            {22, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 196, 25},
            {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 25, 25},
            {0/*dummy*/, 0/*dummy*/, 25, 25},
            37, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0 - 37,
            {(LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0) / 2,
             LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - MMI_SOFTKEY_HEIGHT,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0}
        };
        
        const SlidingBarLayout g_sliding_bar_layout_skin_270 = {
            {22, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 196, 25},
            {22, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 196, 25},
            {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 25, 25},
            {0/*dummy*/, 0/*dummy*/, 25, 25},
            37, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0 - 37,
            {(LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270) / 2,
             LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 3,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270}
        };
#endif
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
    ivex_osd_layout_struct g_ivex_osd_cntx_0 =
    {
        {0, LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0},       /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                      /* title */
        
        {0, 0, 0, 0, MMI_FALSE},      /* panel shadow */
        {0, 11, 0, 0, MMI_FALSE},     /* panel background */
        {0, 45, 0, 0, MMI_FALSE},     /* softkey background */
        
        {0, 0, 0, 0, MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0, MMI_FALSE},      /* right arrow */
        
        {245, 15, 0, 0, MMI_FALSE},   /* zoom in */
        {180, 15, 0, 0, MMI_FALSE},   /* zoom out */
        {87, 15, 0, 0, MMI_FALSE},    /* clockwise rotate */
        {22, 15, 0, 0, MMI_FALSE},    /* counterclockwise rotate */
        
        {8, 47, 0, 0,  MMI_FALSE},     /* left softkey */
        {281, 47, 0, 0, MMI_FALSE},   /* right softkey */
        {143, 47, 0, 0, MMI_FALSE},   /* center key */
        
        {140, 76, 0, 0, MMI_FALSE},   /* drm hint */
        {139, 76, 0, 0, MMI_FALSE},   /* error hint */
        {145, 85, 0, 0, MMI_FALSE},   /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},    /* title */
    };

    ivex_osd_layout_struct g_ivex_osd_cntx_270 = /* not support rotate, should remove */
    {
        {LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_270},  /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                    /* title */
        
        {0, 0, 0, 0,  MMI_FALSE},      /* panel shadow */
        {0, 0, 0, 0,  MMI_FALSE},      /* panel background */
        {0, 0, 0, 0,  MMI_FALSE},      /* softkey background */
        
        {0, 0, 0, 0,  MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0,  MMI_FALSE},      /* right arrow */
        
        {0, 0, 0, 0,  MMI_FALSE},      /* zoom in */
        {0, 0, 0, 0,  MMI_FALSE},      /* zoom out */
        {0, 0, 0, 0,  MMI_FALSE},      /* clockwise rotate */
        {0, 0, 0, 0,  MMI_FALSE},      /* counterclockwise rotate */
        
        {0, 0, 0, 0,  MMI_FALSE},      /* left softkey */
        {0, 0, 0, 0,  MMI_FALSE},      /* right softkey */
        {0, 0, 0, 0,  MMI_FALSE},      /* center key */
        
        {0, 0, 0, 0,  MMI_FALSE},      /* drm hint */
        {0, 0, 0, 0,  MMI_FALSE},      /* error hint */
        {0, 0, 0, 0,  MMI_FALSE},      /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},  /* title */
    };
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
        const SlidingBarLayout g_sliding_bar_layout_skin_0 = {
            {26, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 39, 268, 32},
            {26, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 39, 268, 32},
            {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 39, 32, 32},
            {0/*dummy*/, 0/*dummy*/, 32, 32},
            62, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0 - 62,
            {(LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0) / 2,
             LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - MMI_SOFTKEY_HEIGHT,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0}
        };
        
        const SlidingBarLayout g_sliding_bar_layout_skin_270 = {
            /* TODO */
            {26, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 39, 268, 32},
            {26, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 39, 268, 32},
            {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 39, 32, 32},
            {0/*dummy*/, 0/*dummy*/, 32, 32},
            62, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270 - 62,
            {(LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270) / 2,
             LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 3,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270}
        };
#endif
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 400) )
    ivex_osd_layout_struct g_ivex_osd_cntx_0 =
    {
        {0, LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0},       /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                      /* title */
        
        {0, 0, 0, 0, MMI_FALSE},      /* panel shadow */
        {0, 11, 0, 0, MMI_FALSE},     /* panel background */
        {0, 52, 0, 0, MMI_FALSE},     /* softkey background */
        
        {0, 0, 0, 0, MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0, MMI_FALSE},      /* right arrow */
        
        {184, 17, 0, 0, MMI_FALSE},   /* zoom in */
        {130, 17, 0, 0, MMI_FALSE},   /* zoom out */
        {64, 17, 0, 0, MMI_FALSE},    /* clockwise rotate */
        {10, 17, 0, 0, MMI_FALSE},    /* counterclockwise rotate */
        
        {6, 54, 0, 0,  MMI_FALSE},     /* left softkey */
        {203, 54, 0, 0, MMI_FALSE},   /* right softkey */
        {103, 54, 0, 0, MMI_FALSE},   /* center key */
        
        {99, 158, 0, 0, MMI_FALSE},   /* drm hint */
        {98, 158, 0, 0, MMI_FALSE},   /* error hint */
        {105, 185, 0, 0, MMI_FALSE},  /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},    /* title */
    };

    ivex_osd_layout_struct g_ivex_osd_cntx_270 =
    {
        {LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_270},  /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                    /* title */

        {0, 0, 0, 0, MMI_FALSE},      /* panel shadow */
        {11, 0, 0, 0, MMI_FALSE},     /* panel background */
        {52, 0, 0, 0, MMI_FALSE},     /* softkey background */
        
        {0, 0, 0, 0, MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0, MMI_FALSE},      /* right arrow */
        
        {17, 10, 0, 0, MMI_FALSE},    /* zoom in */
        {17, 64, 0, 0, MMI_FALSE},    /* zoom out */
        {17, 130, 0, 0, MMI_FALSE},   /* clockwise rotate */
        {17, 184, 0, 0, MMI_FALSE},   /* counterclockwise rotate */
        
        {54, 205, 0, 0, MMI_FALSE},   /* left softkey */
        {54, 8, 0, 0,  MMI_FALSE},     /* right softkey */
        {54, 100, 0, 0, MMI_FALSE},   /* center key */
        
        {179, 79, 0, 0, MMI_FALSE},   /* drm hint */
        {179, 79, 0, 0, MMI_FALSE},   /* error hint */
        {185, 105, 0, 0, MMI_FALSE},  /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},  /* title */
    };
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
        const SlidingBarLayout g_sliding_bar_layout_skin_0 = {
            {22, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 196, 25},
            {22, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 196, 25},
            {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 25, 25},
            {0/*dummy*/, 0/*dummy*/, 25, 25},
            37, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0 - 37,
            {(LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0) / 2,
             LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - MMI_SOFTKEY_HEIGHT,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0}
        };
        
        const SlidingBarLayout g_sliding_bar_layout_skin_270 = {
            {22, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 196, 25},
            {22, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 196, 25},
            {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 32, 25, 25},
            {0/*dummy*/, 0/*dummy*/, 25, 25},
            37, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0 - 37,
            {(LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270) / 2,
             LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 3,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270}
        };
#endif
#elif (( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480) ) || ( (LCD_WIDTH == 360) && (LCD_HEIGHT == 640) )  || ( (LCD_WIDTH == 480) && (LCD_HEIGHT == 800) ))
    ivex_osd_layout_struct g_ivex_osd_cntx_0 =
    {
        {0, LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_0, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_0},       /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                      /* title */

        {0, 0, 0, 0, MMI_FALSE},      /* panel shadow */
        {0, 16, 0, 0, MMI_FALSE},     /* panel background */
        {0, 64, 0, 0, MMI_FALSE},     /* softkey background */
        
        {0, 0, 0, 0, MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0, MMI_FALSE},      /* right arrow */
        
        {245, 23, 0, 0, MMI_FALSE},   /* zoom in */
        {179, 23, 0, 0, MMI_FALSE},   /* zoom out */
        {86, 23, 0, 0, MMI_FALSE},    /* clockwise rotate */
        {19, 23, 0, 0, MMI_FALSE},    /* counterclockwise rotate */
        
        {6, 66, 0, 0,   MMI_FALSE},     /* left softkey */
        {275, 66, 0, 0, MMI_FALSE},   /* right softkey */
        {143, 66, 0, 0, MMI_FALSE},   /* center key */
        
        {135, 193, 0, 0, MMI_FALSE},  /* drm hint */
        {135, 193, 0, 0, MMI_FALSE},  /* error hint */
        {142, 222, 0, 0, MMI_FALSE},  /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_0 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},    /* title */
    };

    ivex_osd_layout_struct g_ivex_osd_cntx_270 =
    {
        {LCD_HEIGHT - MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, 0, MMI_IVEX_OSD_PENAL_LYAER_WIDTH_270, MMI_IVEX_OSD_PENAL_LYAER_HEIGHT_270},  /* panel */
        {0, 0, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT},                                                    /* title */

        {0, 0, 0, 0,   MMI_FALSE},      /* panel shadow */
        {16, 0, 0, 0,   MMI_FALSE},     /* panel background */
        {64, 0, 0, 0,   MMI_FALSE},     /* softkey background */
                       
        {0, 0, 0, 0,   MMI_FALSE},      /* left arrow */
        {0, 0, 0, 0,   MMI_FALSE},      /* right arrow */
        
        {22, 20, 0, 0, MMI_FALSE},    /* zoom in */
        {22, 86, 0, 0, MMI_FALSE},    /* zoom out */
        {22, 178, 0, 0, MMI_FALSE},   /* clockwise rotate */
        {22, 244, 0, 0, MMI_FALSE},   /* counterclockwise rotate */
        
        {66, 280, 0, 0, MMI_FALSE},   /* left softkey */
        {66, 7, 0, 0,   MMI_FALSE},     /* right softkey */
        {66, 142, 0, 0,  MMI_FALSE},   /* center key */
        
        {215, 113, 0, 0, MMI_FALSE},  /* drm hint */
        {215, 113, 0, 0, MMI_FALSE},  /* error hint */
        {222, 142, 0, 0, MMI_FALSE},  /* loading hint */
        {4, 6, MMI_IVEX_OSD_TITLE_LAYER_WIDTH_270 - 8, MMI_IVEX_OSD_TITLE_LAYER_HEIGHT - 10, MMI_FALSE},  /* title */
    };
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
        const SlidingBarLayout g_sliding_bar_layout_skin_0 = {
            {26, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 39, 268, 32},
            {26, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 39, 268, 32},
            {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - 39, 32, 32},
            {0/*dummy*/, 0/*dummy*/, 32, 32},
            62, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0 - 62,
            {(LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0) / 2,
             LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0 - MMI_SOFTKEY_HEIGHT,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0}
        };
        
        const SlidingBarLayout g_sliding_bar_layout_skin_270 = {
            /* TODO */
            {26, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 39, 268, 32},
            {26, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 39, 268, 32},
            {0/*dummy*/, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 39, 32, 32},
            {0/*dummy*/, 0/*dummy*/, 32, 32},
            62, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270 - 62,
            {(LCD_HEIGHT - MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270) / 2,
             LCD_WIDTH - MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270 - 3,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270,
             MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270}
        };
#endif
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
#endif  /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_IMAGE_VIEWER_EX__ */

