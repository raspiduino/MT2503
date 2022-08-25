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
 *  ImgAdv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Viewer ADV.
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
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_IMAGE_VIEWER_ADV__)

#include "GlobalConstants.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "gdi_const.h"
#include "gdi_features.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "Gdi_util.h"
#include "gui_typedef.h"
#include "gui_data_types.h"
#include "gui.h"
#include "gui_windows.h"
#include "wgui_include.h"
#include "wgui_categories_util.h"
#include "wgui_touch_screen.h"
#include "MMIDataType.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_gestures_gprot.h"
#include "MMI_media_app_trc.h"
#include "GlobalResDef.h"

#include "FileMgrSrvGProt.h"
#include "lcd_sw_inc.h"
#include "ImageViewCuiGprot.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "drm_def.h"
#include "CustDataRes.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "FileMgrType.h"
#include "FileMgrGProt.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "FileMgrServiceResDef.h"
#include "mmi_rp_app_filemanager_def.h"
#include "GlobalMenuItems.h"
#include "AlertScreen.h"
#include "mmi_rp_file_type_def.h"
#include "drm_errcode.h"
#include "string.h"

#include "lcd_sw_rnd.h" /* for LCD size */

#if defined(SVG12_SUPPORT)
#include "svg.h"
#endif

#include "ImageViewerGprot.h"
#include "mmi_rp_app_imageviewer_def.h"
#include "ImageViewerAdv.h"
#include "ImageViewerAdvGprot.h"
#include "Drm_gprot.h"  /* DRM support */
#include "conversions.h"

#if defined(__MMI_SCREEN_ROTATE__)
#include "ScreenRotationGprot.h"
#endif 


#if defined(__MMI_TVOUT__)
#include "mdi_datatype.h"
#include "mdi_tv.h"
#endif /* __MMI_TVOUT__ */
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)  
#include "mmi_frm_gestures.h"
#endif
#include "gui_touch_feedback.h"

#include "Gui_font_size.h"

/* For imgview CUI */
#include "ImageViewCui.h"
#include "FileMgrCUIGProt.h"
#include "MenuCuiGprot.h"

/***************************************************************************** 
* Local Variable
*****************************************************************************/
imgadv_context_struct g_imgadv_cntx;
#if ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
    imgadv_osd_layout_struct g_imgadv_osd_cntx =
    {
        {25,23,0,0,TRUE,FALSE},     /* left arrow */
        {130,23,0,0,TRUE,FALSE},    /* right arrow */
        {0,25,176, 20,TRUE},        /* num_count */
        {104,176,0,0,TRUE,FALSE},   /* rotate  */
        {52,176,0,0,TRUE,FALSE},    /* zoom in */
        {78,176,0,0,TRUE,FALSE},    /* zoom out */
        {20, 2, (MAIN_LCD_DEVICE_WIDTH - 40), 16,TRUE},     /* title */
    };

    imgadv_osd_layout_struct g_imgadv_osd_cntx_270 =
    {
        {16, 24,0,0,TRUE,FALSE},    /* left arrow */
        {144, 24,0,0,TRUE,FALSE},   /* right arrow */
        {48, 24, ((MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_SOFTKEY_WIDTH-90)), 20,TRUE},    /* num_count */
        {107,152,0,0,TRUE,FALSE},   /* rotate  */
        {52,152,0,0,TRUE,FALSE},    /* zoom in */
        {80,152,0,0,TRUE,FALSE},    /* zoom out */
        {11, 5, (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_SOFTKEY_WIDTH - 14), 16,TRUE},     /* title */
    };

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
    imgadv_osd_layout_struct g_imgadv_osd_cntx =
    {
        {25, 25,0,0,TRUE,FALSE},    /* left arrow */
        {195,25,0,0,TRUE,FALSE},    /* right arrow */
        {0, 2, 240, 20,TRUE},       /* num_count */
        {152,255,0,0,TRUE,FALSE},   /* rotate  */
        {56,255,0,0,TRUE,FALSE},    /* zoom in */
        {104,255,0,0,TRUE,FALSE},   /* zoom out */
        {50, 23, 140, 24,TRUE},     /* title */
    };

    imgadv_osd_layout_struct g_imgadv_osd_cntx_270 =
    {
        {37, 35,0,0,TRUE,FALSE},    /* left arrow */
        {212, 35,0,0,TRUE,FALSE},   /* right arrow */
        {66, 2, 140, 24,TRUE},      /* num_count */
        {172,192,0,0,TRUE,FALSE},   /* rotate  */
        {54,192,0,0,TRUE,FALSE},    /* zoom in */
        {113,192,0,0,TRUE,FALSE},   /* zoom out */
        {66, 32, 140, 24,TRUE},     /* title */
    };
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
    imgadv_osd_layout_struct g_imgadv_osd_cntx =
    {
        {52, 9,0,0,TRUE,FALSE},     /* left arrow */
        {249,9,0,0,TRUE,FALSE},     /* right arrow */
        {0, 37, 320, 28,TRUE},      /* num_count */
        {184,209,0,0,TRUE,FALSE},   /* rotate  */
        {109,209,0,0,TRUE,FALSE},   /* zoom in */
        {146,209,0,0,TRUE,FALSE},   /* zoom out */
        {73, 8, 174, 25,TRUE},      /* title */
    };

    imgadv_osd_layout_struct g_imgadv_osd_cntx_270 =
    {
        {25, 30,0,0,TRUE,FALSE},    /* left arrow */
        {195,30,0,0,TRUE,FALSE},    /* right arrow */
        {2, 2, 180, 20,TRUE},       /* num_count */
        {152,255,0,0,TRUE,FALSE},   /* rotate  */
        {56,255,0,0,TRUE,FALSE},    /* zoom in */
        {104,255,0,0,TRUE,FALSE},   /* zoom out */
        {50, 28, 140, 24,TRUE},     /* title */
    };
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 400) )
    imgadv_osd_layout_struct g_imgadv_osd_cntx =
    {
        {14, 21,0,0,TRUE,FALSE},    /* left arrow */
        {198,21,0,0,TRUE,FALSE},    /* right arrow */
        {0, 3, 240, 17,TRUE},       /* num_count */
        {153,329,0,0,TRUE,FALSE},   /* rotate  */
        {48,329,0,0,TRUE,FALSE},    /* zoom in */
        {101,329,0,0,TRUE,FALSE},   /* zoom out */
        {48, 24, 144, 26,TRUE},     /* title */
    };

    imgadv_osd_layout_struct g_imgadv_osd_cntx_270 =
    {
        {67, 30,0,0,TRUE,FALSE},    /* left arrow */
        {251,30,0,0,TRUE,FALSE},    /* right arrow */
        {46, 7, 254, 20,TRUE},      /* num_count */
        {206,187,0,0,TRUE,FALSE},   /* rotate  */
        {101,187,0,0,TRUE,FALSE},   /* zoom in */
        {154,187,0,0,TRUE,FALSE},   /* zoom out */
        {104, 33, 140, 26,TRUE},    /* title */
    };
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480) )
    imgadv_osd_layout_struct g_imgadv_osd_cntx =
    {
        {23, 33,0,0,TRUE,FALSE},    /* left arrow */
        {261,33,0,0,TRUE,FALSE},    /* right arrow */
        {0, 5, 320, 19,TRUE},       /* num_count */
        {200,400,0,0,TRUE,FALSE},   /* rotate  */
        {84,400,0,0,TRUE,FALSE},    /* zoom in */
        {142,400,0,0,TRUE,FALSE},   /* zoom out */
        {69, 38, 180, 28,TRUE},     /* title */
    };

    imgadv_osd_layout_struct g_imgadv_osd_cntx_270 =
    {
        {58, 28,0,0,TRUE,FALSE},    /* left arrow */
        {296,28,0,0,TRUE,FALSE},    /* right arrow */
        {58, 5, 275, 22,TRUE},      /* num_count */
        {235,269,0,0,TRUE,FALSE},   /* rotate  */
        {119,269,0,0,TRUE,FALSE},   /* zoom in */
        {177,269,0,0,TRUE,FALSE},   /* zoom out */
        {105, 33, 180, 28,TRUE},    /* title */
    };  
#elif ( (LCD_WIDTH == 480) && (LCD_HEIGHT == 800) )
    imgadv_osd_layout_struct g_imgadv_osd_cntx =
    {
        {23, 33,0,0,TRUE,FALSE},    /* left arrow */
        {261,33,0,0,TRUE,FALSE},    /* right arrow */
        {0, 5, 320, 19,TRUE},       /* num_count */
        {200,400,0,0,TRUE,FALSE},   /* rotate  */
        {84,400,0,0,TRUE,FALSE},    /* zoom in */
        {142,400,0,0,TRUE,FALSE},   /* zoom out */
        {69, 38, 180, 28,TRUE},     /* title */
    };

    imgadv_osd_layout_struct g_imgadv_osd_cntx_270 =
    {
        {58, 28,0,0,TRUE,FALSE},    /* left arrow */
        {296,28,0,0,TRUE,FALSE},    /* right arrow */
        {58, 5, 275, 22,TRUE},      /* num_count */
        {235,269,0,0,TRUE,FALSE},   /* rotate  */
        {119,269,0,0,TRUE,FALSE},   /* zoom in */
        {177,269,0,0,TRUE,FALSE},   /* zoom out */
        {105, 33, 180, 28,TRUE},    /* title */
    };      
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern BOOL r2lMMIFlag;

/* CUI related variables */
mmi_id g_imgadv_cui_gid;
extern cui_imgview_context_struct *g_imgview_cui_ptr;
/***************************************************************************** 
* Local Function
*****************************************************************************/
static void mmi_imgadv_osd_fade_cyclic(void);
#ifdef __MMI_TOUCH_SCREEN__
static void mmi_imgadv_pen_down_hdlr_osd_showup(mmi_pen_point_struct pos);
#endif
static void mmi_imgadv_entry_external_app_screen(void);
static void mmi_imgadv_init_external_key_handler(void);

#define MMI_IMGADV_OSD_FADE_OUT_VALUE   (32)     /* fade 32/256 */
#define MMI_IMGADV_OSD_FADEOUT_FACTOR   (255)
#define MMI_IMGADV_OSD_FADE_OUT_TIME    (2*1000)    /* 2 sec */

/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_is_direct_exit_state
 * DESCRIPTION
 *  fade imgadv osd
 * PARAMETERS
 *  sleep       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_imgadv_is_direct_exit_state(imgadv_direct_exit_enum org_type, imgadv_direct_exit_enum new_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (org_type & new_type)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_set_exit_state
 * DESCRIPTION
 *  fade imgadv osd
 * PARAMETERS
 *  sleep       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_add_direct_exit_state(imgadv_direct_exit_enum *org_type, imgadv_direct_exit_enum new_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *org_type |= new_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_reset_exit_state
 * DESCRIPTION
 *  fade imgadv osd
 * PARAMETERS
 *  sleep       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_remove_direct_exit_state(imgadv_direct_exit_enum *org_type, imgadv_direct_exit_enum new_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *org_type &= ~new_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_check_exit_request
 * DESCRIPTION
 *  fade imgadv osd
 * PARAMETERS
 *  sleep       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_check_exit_request(FS_HANDLE filehandle, MMI_BOOL single)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (single)
    {
        switch (filehandle)
        {
            case FS_MEDIA_CHANGED:
            case FS_DRIVE_NOT_FOUND:
            case FS_DRIVE_NOT_READY:
            case FS_FILE_NOT_FOUND:
                mmi_imgadv_add_direct_exit_state(&g_imgadv_cntx.direct_exit, IMGADV_DIRECT_EXIT_VIEWSCRN_EXT_REQUIRE);
                return;
        }
    }
    else
    {
        switch (filehandle)
        {
            case FS_MEDIA_CHANGED:
            case FS_DRIVE_NOT_FOUND:
            case FS_DRIVE_NOT_READY:
                mmi_imgadv_add_direct_exit_state(&g_imgadv_cntx.direct_exit, IMGADV_DIRECT_EXIT_VIEWSCRN_REQUIRE);
                return;
        }
    }
    mmi_imgadv_remove_direct_exit_state(&g_imgadv_cntx.direct_exit, IMGADV_DIRECT_EXIT_VIEWSCRN_REQUIRE);
    mmi_imgadv_remove_direct_exit_state(&g_imgadv_cntx.direct_exit, IMGADV_DIRECT_EXIT_VIEWSCRN_EXT_REQUIRE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_lsk_is_enable
 * DESCRIPTION
 *  fade imgadv osd
 * PARAMETERS
 *  sleep       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_imgadv_lsk_is_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_enable = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* CUI control part, user can reset it */
    if (g_imgview_cui_ptr->cap_enable[CUI_IMGVIEW_CAP_OPTION] == MMI_FALSE &&
        g_imgview_cui_ptr->lsk_setting.is_customized == MMI_FALSE)
    {
        return is_enable = MMI_FALSE;
    }

    if (g_imgview_cui_ptr->lsk_setting.is_customized)
    {
        if (g_imgview_cui_ptr->lsk_setting.is_force_enable)
        {
            is_enable = MMI_TRUE;
        }
        else if (g_imgadv_cntx.result >= MMI_IMGADV_OK &&
                 g_imgview_cui_ptr->lsk_setting.is_force_enable == MMI_FALSE)
        {
            is_enable = MMI_TRUE;
        }
        else
        {
            is_enable = MMI_FALSE;
        }
    }
    else
    {
        #ifdef __DRM_SUPPORT__
        if ((g_imgadv_cntx.is_printable == TRUE ) && 
            (IMGADV_DRM_PRINT_VALID & g_imgadv_cntx.drm_valid)!=0 )
        #else
        if (g_imgadv_cntx.is_printable == TRUE )
        #endif
        {
            is_enable = MMI_TRUE;
        }
        else
        {
            is_enable = MMI_FALSE;
        }
    }
    return is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_temp_dummy_screen
 * DESCRIPTION
 *  fade imgadv osd
 * PARAMETERS
 *  sleep       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_temp_dummy_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_reset_osd_fade
 * DESCRIPTION
 *  fade imgadv osd
 * PARAMETERS
 *  sleep       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_reset_osd_fade(MMI_BOOL sleep)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_imgadv_osd_fade_cyclic);
    
    if (g_imgadv_cntx.osd_opacity != MMI_IMGADV_OSD_FADEOUT_FACTOR)
    {
        g_imgadv_cntx.osd_opacity = MMI_IMGADV_OSD_FADEOUT_FACTOR;

        gdi_layer_push_and_set_active(g_imgadv_cntx.base_layer_handle);
        gdi_layer_set_opacity(TRUE, (U8) g_imgadv_cntx.osd_opacity);
        gdi_layer_pop_and_restore_active();
    }

    if (sleep)
    {
        /* start fade out timer */
        gui_start_timer(MMI_IMGADV_OSD_FADE_OUT_TIME, mmi_imgadv_osd_fade_cyclic);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_osd_show_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_osd_show_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imgadv_init_key_handler();
    mmi_imgadv_init_default_touch_and_key_handler();
    mmi_imgadv_reset_osd_fade(MMI_TRUE);
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    if (!g_imgadv_cntx.is_decoding)
#endif
    {
        if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_0)
        {
            gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
        }
        else
        {
            gdi_layer_blt_previous(0, 0, LCD_HEIGHT - 1, LCD_WIDTH - 1);
        }
    }
    ClearKeyEvents();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_osd_fade_cyclic
 * DESCRIPTION
 *  fade slidshow osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_osd_fade_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgadv_cntx.cache_layer_handle == GDI_NULL_HANDLE)
    {
        gui_cancel_timer(mmi_imgadv_osd_fade_cyclic);
        return;
    }

    /* reset osd fade out timer */
    if (g_imgadv_cntx.osd_opacity > MMI_IMGADV_OSD_FADE_OUT_VALUE)
    {        
        g_imgadv_cntx.osd_opacity -= MMI_IMGADV_OSD_FADE_OUT_VALUE;
        gui_start_timer(200, mmi_imgadv_osd_fade_cyclic);
        
        if (g_imgadv_cntx.map.is_zoomin_able)
        {
            SetKeyHandler(mmi_imgadv_zoomin_press, KEY_1, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_zoomin_release, KEY_1, KEY_EVENT_UP);
        }
        else
        {
            SetKeyHandler(mmi_imgadv_osd_show_up, KEY_1, KEY_EVENT_UP);
        }

        if (g_imgadv_cntx.map.is_zoomout_able)
        {
            SetKeyHandler(mmi_imgadv_zoomout_press, KEY_2, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_zoomout_release, KEY_2, KEY_EVENT_UP);
        }
        else
        {
            SetKeyHandler(mmi_imgadv_osd_show_up, KEY_2, KEY_EVENT_UP);
        }

        SetKeyHandler(mmi_imgadv_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_imgadv_lsk_release, KEY_LSK, KEY_EVENT_UP);
        
        SetKeyHandler(mmi_imgadv_rsk_press, KEY_RSK, KEY_EVENT_DOWN); 
        SetKeyHandler(mmi_imgadv_rsk_release, KEY_RSK, KEY_EVENT_UP);

        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_4, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_5, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_6, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_7, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_8, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_9, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_0, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_POUND, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_STAR, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_ENTER, KEY_EVENT_UP);        
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_CLEAR, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_CAMERA, KEY_EVENT_UP);

        if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
        {
            if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
            {
                SetKeyHandler(mmi_imgadv_osd_show_up, KEY_LEFT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_imgadv_osd_show_up, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                if (g_imgadv_cntx.is_external_req)
                {
                    SetKeyHandler(mmi_imgadv_osd_show_up, KEY_UP_ARROW, KEY_EVENT_UP);
                    SetKeyHandler(mmi_imgadv_osd_show_up, KEY_DOWN_ARROW, KEY_EVENT_UP);
                }
            }
        }
        else
        {
            if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
            {
                SetKeyHandler(mmi_imgadv_osd_show_up, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_imgadv_osd_show_up, KEY_DOWN_ARROW, KEY_EVENT_UP);
                if (g_imgadv_cntx.is_external_req)
                {
                    SetKeyHandler(mmi_imgadv_osd_show_up, KEY_LEFT_ARROW, KEY_EVENT_UP);
                    SetKeyHandler(mmi_imgadv_osd_show_up, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                }
            }           
        }
    }
    else
    {
        g_imgadv_cntx.osd_opacity = 0;

        ClearInputEventHandler(MMI_DEVICE_ALL);
    
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_1, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_2, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_3, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_4, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_5, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_6, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_7, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_8, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_9, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_0, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_POUND, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_STAR, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_LSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_RSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_ENTER, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_LEFT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_UP_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_DOWN_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_CLEAR, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_CAMERA, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_VOL_UP, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_osd_show_up, KEY_VOL_DOWN, KEY_EVENT_UP);

    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_pen_down_handler(mmi_imgadv_pen_down_hdlr_osd_showup);
    #endif
    }

    gdi_layer_push_and_set_active(g_imgadv_cntx.base_layer_handle);
    gdi_layer_set_opacity(TRUE, (U8) g_imgadv_cntx.osd_opacity);
    gdi_layer_pop_and_restore_active();
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_0)
    {
        gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
    else
    {
        gdi_layer_blt_previous(0, 0, LCD_HEIGHT - 1, LCD_WIDTH - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_init_app
 * DESCRIPTION
 *  init function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cntx.is_real_decode = MMI_FALSE;
    g_imgadv_cntx.is_err_displayed = FALSE;

    #ifdef __DRM_SUPPORT__
        g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_EXIT;
        g_imgadv_cntx.drm_id = 0;
        g_imgadv_cntx.drm_handle = NULL;
    #endif

    g_imgadv_cntx.is_external_req = MMI_FALSE;
    g_imgadv_cntx.direct_exit = IMGADV_DIRECT_EXIT_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_get_rotate
 * DESCRIPTION
 *  get rotate function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_imgadv_get_rotate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_imgadv_cntx.imgview_rotate;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_unlock_filelist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_unlock_filelist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgview_state = MMI_IMGVIEW_STATE_EXIT;    
    mmi_mediaview_free_filelist();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_draw_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_draw_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width, str_height;
    S32 define_offset_x, define_offset_y, define_offset_w, define_offset_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgview_cui_ptr->cap_enable[CUI_IMGVIEW_CAP_FILENAME] == MMI_FALSE &&
        g_imgview_cui_ptr->cap_enable[CUI_IMGVIEW_CAP_TITLE] == MMI_FALSE)
    {
        /* no title */
        return;
    }
    define_offset_x = g_imgadv_cntx.active_osd_layout_ptr->title.offset_x;
    define_offset_y = g_imgadv_cntx.active_osd_layout_ptr->title.offset_y;
    define_offset_w = g_imgadv_cntx.active_osd_layout_ptr->title.width;
    define_offset_h = g_imgadv_cntx.active_osd_layout_ptr->title.height;

    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_TITLE));
    gui_measure_string((UI_string_type) g_imgadv_cntx.buf_filename_no_ext, &str_width, &str_height);

    if ( str_width > define_offset_w)
    {
    #if !defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
        gui_create_scrolling_text(
            &g_imgadv_cntx.scrolling_title,
            define_offset_x,
            define_offset_y + 1,
            define_offset_w,
            define_offset_h,
            (UI_string_type) g_imgadv_cntx.buf_filename_no_ext,
            mmi_imgadv_scrolling_text_handle,
            mmi_imgadv_strolling_text_redraw_bg,
            gui_color(255, 255, 255),
            gui_color(0, 0, 0));

        g_imgadv_cntx.scrolling_title.flags |=UI_SCROLLING_TEXT_BORDERED_TEXT;
        gui_show_scrolling_text(&g_imgadv_cntx.scrolling_title);
        g_imgadv_cntx.is_scrolling_title = TRUE;
    #else /* !defined(__MMI_IMGADV_NONBLOCKING_DECODE__) */
        gdi_draw_solid_rect(define_offset_x,
                            define_offset_y,
                            define_offset_x+define_offset_w,
                            define_offset_y+define_offset_h,
                            GDI_COLOR_TRANSPARENT);


        mmi_imgadv_draw_truncated_style_text(
            g_imgadv_cntx.buf_filename_no_ext,
            define_offset_x,
            define_offset_y + 1,
            define_offset_w );
    #endif /* !defined(__MMI_IMGADV_NONBLOCKING_DECODE__) */

    }
    else
    {
        S32 offset_x ;
        gdi_draw_solid_rect(define_offset_x,
                            define_offset_y,
                            define_offset_x+define_offset_w,
                            define_offset_y+define_offset_h,
                            GDI_COLOR_TRANSPARENT);

        offset_x = (define_offset_w - str_width)>>1;

        mmi_imgadv_draw_style_text(
            IMGADV_NON_KEY,
            g_imgadv_cntx.buf_filename_no_ext,
            define_offset_x+offset_x,
            define_offset_y + 1);
                
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_construct_osd_strings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_construct_osd_strings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR                          buffer[30];  /* for xxxx/xxxx */
    WCHAR* name_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_imgadv_cntx.is_external_req)
    {
        /* prepare xxxx/xxxx string */
        sprintf(buffer, "%d/%d", (U16) g_imgview_fl_idx + 1, (U16) g_imgadv_cntx.total_count);
        mmi_asc_to_ucs2((CHAR*) g_imgadv_cntx.count_str, (CHAR*) buffer);
       /* end of prepare xxxx/xxxx string */   
    }
    if (g_imgview_cui_ptr->cap_enable[CUI_IMGVIEW_CAP_FILENAME])
    {
        name_ptr = srv_fmgr_path_get_filename_ptr((WCHAR*)g_imgadv_cntx.filepath);
        mmi_ucs2cpy((CHAR*) g_imgadv_cntx.buf_filename_no_ext, (CHAR*)name_ptr);
        srv_fmgr_path_hide_extension((WCHAR*)(g_imgadv_cntx.buf_filename_no_ext));
    }
    else if (g_imgview_cui_ptr->cap_enable[CUI_IMGVIEW_CAP_TITLE] && g_imgview_cui_ptr->title_confing.is_customized)
    {
        mmi_ucs2cpy((CHAR*) g_imgadv_cntx.buf_filename_no_ext, (CHAR*)g_imgview_cui_ptr->title_confing.title_string);
    }
    else
    {
        /* Draw nothing */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_recheck_file
 * DESCRIPTION
 *  recheck image again.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_recheck_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__DRM_SUPPORT__)
    FS_HANDLE                   fs_handle;
#else    
    MMI_BOOL               validate;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__
    if (g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_EXIT)
    {
        if ((g_imgadv_cntx.drm_valid & IMGADV_DRM_DRM_FILE)!=0)
        {
            validate = DRM_validate_permission(NULL, (kal_wchar *)g_imgadv_cntx.filepath, DRM_PERMISSION_DISPLAY);
        }
        else
        {
            validate = MMI_TRUE;
        }
    }
    else
    {
        /* This is for rotate */
        validate = MMI_TRUE;
    }
    if (validate == MMI_FALSE)
    {
        g_imgadv_cntx.result = MMI_IMGADV_DRM_INVALID; 
        g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_DRM_PROHIBITED);
        g_imgadv_cntx.error_event = MMI_EVENT_FAILURE;
    }
#else
    fs_handle = DRM_open_file((U16*)g_imgadv_cntx.filepath, FS_READ_ONLY, DRM_PERMISSION_NONE);
    if (fs_handle < 0)
    {
        g_imgadv_cntx.result = MMI_IMGADV_ERROR;
        g_imgadv_cntx.err_str_ptr = GetString((U16)srv_fmgr_fs_error_get_string(fs_handle));
        g_imgadv_cntx.error_event = srv_fmgr_fs_error_get_popup_type(fs_handle);
    }
    else
    {
        DRM_close_file(fs_handle);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivex_view_screen_leave_proc
 * DESCRIPTION
 *  Ext view screen leave proc.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_imgadv_view_screen_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_SCRN_GOBACK:
        break;
    case EVT_ID_SCRN_DELETE_REQ:
        break;
    case EVT_ID_SCRN_DEINIT:
        mmi_imgadv_del_scr_callback(NULL);
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_entry_app_screen_internal
 * DESCRIPTION
 *  Entry function of imgadv viewer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_entry_app_screen_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8                          *guiBuffer;
    srv_fmgr_fileinfo_struct     file_info;
    CHAR*                         error_str_ptr;
    MMI_BOOL entry_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* exit previous screen */
    if (!mmi_frm_is_in_backward_scenario() && !mmi_frm_group_is_present(g_imgadv_cui_gid))
    {
        mmi_frm_group_enter(g_imgadv_cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    entry_ret = mmi_frm_scrn_enter(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW, mmi_imgadv_exit_app_screen, mmi_imgadv_entry_app_screen, MMI_FRM_FULL_SCRN);
    if (!entry_ret)
    {
        return;
    }

    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);

    mmi_imgadv_remove_direct_exit_state(&g_imgadv_cntx.direct_exit, IMGADV_DIRECT_EXIT_VIEWSCRN);
    g_imgadv_cntx.is_refreshing = MMI_FALSE;
    mmi_frm_scrn_close(g_imgadv_cui_gid, SCR_ID_GLOBAL_DUMMY);
    mmi_frm_scrn_set_leave_proc(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW, mmi_imgadv_view_screen_leave_proc);

    /* force all playing keypad tone off */
    //AudioStopReq(GetCurKeypadTone());

    /* entry full screen app */
    entry_full_screen();

    /* clear key events for key release event from last screen */
    ClearKeyEvents();

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_ENTRY_SCREEN);
    /* check if it is return from interrupt */
    guiBuffer = mmi_frm_scrn_get_gui_buf(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW);
    if (guiBuffer != NULL && g_imgadv_cntx.is_real_decode == MMI_TRUE)
    {
        g_imgadv_cntx.is_resume = TRUE;
    }
    else
    {
        g_imgadv_cntx.is_resume = FALSE;
        g_imgadv_cntx.map.zoom_factor_cnt = 0;
        g_imgadv_cntx.map.max_zoom_factor_cnt = 255;
        g_imgadv_cntx.result = MMI_IMGADV_OK;
        mmi_imgadv_init_map_box();
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_CHECK_RESUME, g_imgadv_cntx.is_resume);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_RESULT, g_imgadv_cntx.result);

    /* allocate string buffer */
    g_imgadv_cntx.filepath = mmi_frm_scrmem_alloc_framebuffer(SRV_FMGR_PATH_BUFFER_SIZE);
    g_imgadv_cntx.buf_filename_no_ext = mmi_frm_scrmem_alloc_framebuffer(SRV_FMGR_PATH_BUFFER_SIZE);
    g_imgadv_cntx.count_str = mmi_frm_scrmem_alloc_framebuffer(60);

    /* get file_info */
    if (g_imgview_cui_ptr->view_mode.viewmode == CUI_IMGVIEW_VIEWMODE_PREFETCH)
    {
        srv_fmgr_fs_path_get_fileinfo((WCHAR*)g_imgview_cui_ptr->view_mode.buff_ptr, &file_info);
        mmi_ucs2cpy(g_imgadv_cntx.filepath, g_imgview_cui_ptr->view_mode.buff_ptr);
    }
    else
    {
        srv_fmgr_filelist_get_fileinfo(g_imgview_fl_hdl, g_imgview_fl_idx, &file_info);
        srv_fmgr_filelist_get_filepath(g_imgview_fl_hdl, g_imgview_fl_idx, (WCHAR*)g_imgadv_cntx.filepath, SRV_FMGR_PATH_BUFFER_SIZE);
    }
    /* Get file list path */
    g_imgadv_cntx.is_short = FALSE;
    /*
     * 1. DRM permission check with filepath 
     ****/
    if ( mmi_imgadv_validate_drm_right() == FALSE)
    {
        return;
    }

    /*
     * 2. Check print functions 
     ****/
    if (mmi_imgview_print_enabler(&file_info) > 0
#if defined(__DRM_SUPPORT__)
    && (IMGADV_DRM_PRINT_VALID & g_imgadv_cntx.drm_valid)!=0
#endif
    )
    {
        g_imgadv_cntx.is_printable = TRUE;
    }
    else
    {
        g_imgadv_cntx.is_printable = FALSE;
    }

    mmi_imgadv_recheck_file();

    /*
     * 3. check file dimension and type 
     ****/
    if (g_imgadv_cntx.result >= MMI_IMGADV_OK && !mmi_fmgr_util_file_limit_check(FMGR_LIMIT_IMAGE_VIEWER, (CHAR*) g_imgadv_cntx.filepath, &error_str_ptr))
    {
        g_imgadv_cntx.err_str_ptr = error_str_ptr;
        g_imgadv_cntx.result = MMI_IMGADV_ERROR;
    }

    if (g_imgadv_cntx.result >= MMI_IMGADV_OK)
    {
        g_imgadv_cntx.image_type = gdi_image_get_type_from_file(g_imgadv_cntx.filepath);

        g_imgadv_cntx.result = gdi_image_get_dimension_file(
                                        (CHAR*) g_imgadv_cntx.filepath,
                                        &(g_imgadv_cntx.image_width),
                                        &(g_imgadv_cntx.image_height));
        if (((g_imgadv_cntx.image_width <= 0) || (g_imgadv_cntx.image_height <= 0)) ||
            g_imgadv_cntx.result < 0)
        {        
            g_imgadv_cntx.result = MMI_IMGADV_INVALID_FORMAT;
            g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_INVALID_FORMAT);
        }

        /* add image size limit for svg file type */
        if (g_imgadv_cntx.image_type==GDI_IMAGE_TYPE_SVG || g_imgadv_cntx.image_type==GDI_IMAGE_TYPE_SVG_FILE)
        {
            g_imgadv_cntx.image_width *= 3;
            g_imgadv_cntx.image_height *= 3;
        }
    }

    /************ base layer ************/
    gdi_layer_get_base_handle(&g_imgadv_cntx.base_layer_handle);
    
    g_imgadv_cntx.osd_opacity = MMI_IMGADV_OSD_FADEOUT_FACTOR;
    gdi_layer_push_and_set_active(g_imgadv_cntx.base_layer_handle);
    gdi_layer_set_opacity(TRUE, (U8) g_imgadv_cntx.osd_opacity);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
      
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_0)
    {
        gdi_layer_resize(LCD_WIDTH,LCD_HEIGHT);
        gdi_lcd_set_rotate(GDI_LCD_LAYER_ROTATE_0);
    }
    else if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        gdi_layer_resize(LCD_HEIGHT,LCD_WIDTH);
        gdi_lcd_set_rotate(GDI_LCD_LAYER_ROTATE_270);
        gdi_lcd_set_rotate_by_layer(TRUE);
    }
    
    /* create resource for imageviewer */
    mmi_imgadv_create_resource(); 

#if !defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_get_alpha_blending_source_layer(&g_imgadv_cntx.ivadv_org_bld_layer);
    gdi_set_alpha_blending_source_layer(g_imgadv_cntx.cache_layer_handle);
#endif

    gdi_layer_set_blt_layer(g_imgadv_cntx.cache_layer_handle,g_imgadv_cntx.base_layer_handle,0,0);

    /* init count_str and buf_filename_no_ext */
    mmi_imgadv_construct_osd_strings();

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        /* if is fullscreen, we shall set to owner APP Owner draw, to avoid GDI's update */
        mdi_tvout_set_owner(MDI_TV_OWNER_APP);
    }
#endif /* __MMI_TVOUT__ */ 

    /* initialize osd icon */
    mmi_imgadv_init_osd_icon_position();

    /* get active osd cntx */
    mmi_imgadv_get_active_osd_cntx();

    /* show ooxx/ooxx */
    mmi_imgadv_draw_num_count();

    /* tmp test */
    if (g_imgadv_cntx.is_resume == FALSE)
    {
        mmi_imgadv_init_image_info();
    }
    else
    {
        if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG ||
            g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG_FILE )
        /*gdi_anim_stop_all_by_layer(g_imgadv_cntx.cache_layer_handle);*/
        {
        #ifdef __MMI_TVOUT__
            if (mdi_tvout_is_enable())
            {
                /* it will calculate roi */
                mmi_imgadv_init_image_info();
            }
        #endif /* __MMI_TVOUT__ */ 
            if (!(g_imgadv_cntx.is_err_displayed == TRUE &&
                g_imgadv_cntx.map.zoom_factor_cnt == 0 &&
                g_imgadv_cntx.map.max_zoom_factor_cnt == 255))
            {
                gdi_anim_stop_all_by_layer(g_imgadv_cntx.cache_layer_handle);
                gdi_layer_push_and_set_active(g_imgadv_cntx.thumbnail_layer_handle);
                gdi_layer_resize(g_imgadv_cntx.thumbnail_layer_width ,g_imgadv_cntx.thumbnail_layer_height);
                gdi_image_draw_resized_file(
                    0,
                    0,
                    g_imgadv_cntx.thumbnail_layer_width,
                    g_imgadv_cntx.thumbnail_layer_height,
                    g_imgadv_cntx.filepath);
                gdi_layer_pop_and_restore_active();
            }
        }
    }

    mmi_imgadv_draw_map();

        /* draw osd */
    mmi_imgadv_draw_osd();

    /* for MAUI_02734333, to avoid scolling text blt a small area to LCD before image viewer blt its layers */
    gdi_layer_lock_frame_buffer();

    /* show file name */
    mmi_imgadv_draw_title();
    
    gdi_layer_unlock_frame_buffer();

    /* blt to lcd */
    gdi_lcd_repaint_all();

    /* clear ori key handler */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    mmi_imgadv_init_default_touch_and_key_handler();

    if (g_imgadv_cntx.is_err_displayed == TRUE) 
    {
        mmi_imgadv_reset_osd_fade(MMI_TRUE);
        if (g_imgadv_cntx.result == MMI_IMGADV_OK && g_imgadv_cntx.map.max_zoom_factor_cnt != 255)
            g_imgadv_cntx.result = MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR;

        switch (g_imgadv_cntx.result)
        {
            case MMI_IMGADV_OK:
            case MMI_IMGADV_ERROR:
            case MMI_IMGADV_INVALID_FORMAT:
            case MMI_IMGADV_DRM_INVALID:
            case MMI_IMGADV_FIRST_TIME_DECODE_ERR:
                g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
                g_imgadv_cntx.map.is_zoomout_able = MMI_FALSE;
                g_imgadv_cntx.map.zoom_factor_cnt = 0;
                mmi_imgadv_draw_map();
                mmi_imgadv_draw_osd();
                gdi_lcd_repaint_all();
                mmi_imgadv_init_key_handler();
                break;
            case MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR:
                mmi_imgadv_draw_map();
                mmi_imgadv_draw_osd();
            #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
                g_imgadv_cntx.is_initialized = FALSE;
            #else
                mmi_imgadv_init_key_handler();
                mmi_imgadv_init_default_touch_and_key_handler();
            #endif           
                mmi_imgadv_extract_image_to_cache_layer();

                if (g_imgadv_cntx.result >= MMI_IMGADV_OK)
                {
                    if (g_imgadv_cntx.map.zoom_factor_cnt == g_imgadv_cntx.map.max_zoom_factor_cnt)
                    {
                        g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
                    }
                    else
                    {
                        g_imgadv_cntx.map.is_zoomin_able = MMI_TRUE;
                    }

                    if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
                    {
                        g_imgadv_cntx.map.is_zoomout_able = MMI_TRUE;
                    }
                    else
                    {
                        g_imgadv_cntx.map.is_zoomout_able = MMI_FALSE;
                    }
                        
                    mmi_imgadv_extract_image_to_thumbnail_layer();
                }
                else
                {
                    gdi_lcd_repaint_all();
                }
            #ifdef __MMI_TVOUT__
                mmi_imgadv_tvout_clear_bg();
                mmi_imgadv_tvout_decode();
                /* if tvout is not enable, stop lcd sleep */
                if (mdi_tvout_is_enable())
                {
                    /* tv out is on, do not let tv to sleep in when lcd sleep in */
                    mmi_phnset_tvout_disable_tv_sleep_in();
                    mmi_phnset_disable_partial_ss();
                }
            #endif
                return;
        }
    }
    else if (g_imgadv_cntx.result < MMI_IMGADV_OK)
    {
        g_imgadv_cntx.error_event = MMI_EVENT_FAILURE;
        mmi_imgadv_display_error_sg(g_imgadv_cui_gid, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
        return;
    }
    else
    {
        if (g_imgadv_cntx.is_resume == FALSE)
        {
            /* it will calculate roi */
            mmi_imgadv_init_image_info();
        }

        g_imgadv_cntx.is_initialized = FALSE;
        /* start timer to decode */
        gui_start_timer(10, mmi_imgadv_start_decode);
        gdi_lcd_repaint_all();
    }
#ifdef __MMI_TVOUT__
    mmi_imgadv_tvout_clear_bg();
#endif /* __MMI_TVOUT__ */ 

}


/* Imageviwer call imgview CUI using start */
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_run_imgview_cui
 * DESCRIPTION
 *  Run image view CUI
 * PARAMETERS
 *  parent_gid           :  [IN]  Image view's parent group id.
 *  filelist             :  [IN]  File list.
 *  start_index          :  [IN]  Start view index.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_run_imgview_cui(mmi_id parent_gid, SRV_FMGR_FILELIST_HANDLE filelist, U32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id imgview_gid;
    U16 ui_direct;
    cui_imgview_ui_direction_enum cui_view_direct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ui_direct = mmi_imgview_get_rotate();
    if (ui_direct == 0)
    {
        cui_view_direct = CUI_IMGVIEW_UI_DIRECTION_VERTICAL;
    }
    else
    {
        cui_view_direct = CUI_IMGVIEW_UI_DIRECTION_HORIZONTAL;
    }
    
    if ((imgview_gid = cui_imgview_create(parent_gid)) != GRP_ID_INVALID)
    {
        cui_imgview_set_mode_filelist(imgview_gid, filelist,start_index);
        cui_imgview_set_app_id(imgview_gid, mmi_mediaview_get_curr_app_id());
        cui_imgview_set_ui_direction(imgview_gid, cui_view_direct);
        cui_imgview_set_display_cap(imgview_gid, CUI_IMGVIEW_CAP_ALL, MMI_TRUE);   
        cui_imgview_set_display_cap(imgview_gid, CUI_IMGVIEW_CAP_UI_ROTATE, MMI_FALSE);   
        cui_imgview_set_display_cap(imgview_gid, CUI_IMGVIEW_CAP_SLIDESHOW, MMI_FALSE);   
        cui_imgview_set_display_cap(imgview_gid, CUI_IMGVIEW_CAP_TITLE, MMI_FALSE);   
        cui_imgview_set_display_cap(imgview_gid, CUI_IMGVIEW_CAP_DB, MMI_FALSE);   
        cui_imgview_run(imgview_gid);
    }
    else
    {
        /*TODO: add trace, enter fail*/
    }
}
/* Imgview CUI using end */


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_check_filelist
 * DESCRIPTION
 *  check filelist.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_imgadv_check_filelist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32                         total_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_count = srv_fmgr_filelist_count(g_imgview_fl_hdl);
    g_imgadv_cntx.total_count = total_count;
    
    if (total_count == 0)
    {
        mmi_imgview_display_popup_sg(g_imgadv_cui_gid, (UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
        mmi_imgadv_unlock_filelist();
    #ifdef __DRM_SUPPORT__
        if (g_imgadv_cntx.is_rotate_action == MMI_TRUE)
        {
            /* rotate should not consume */
            g_imgadv_cntx.is_rotate_action = MMI_FALSE;
            mmi_imgadv_pause_drm_consume_if_need();
        }
    #endif
        return MMI_FALSE;
    }
    else if (total_count < 0)
    {
        SRV_FMGR_DRVLIST_HANDLE drvlist;
        S32 total_drv_num = 0;
        CHAR* error_string_ptr;
        drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ALL);
        total_drv_num = srv_fmgr_drivelist_count(drvlist);
        srv_fmgr_drivelist_destroy(drvlist);
        #ifdef __FS_CARD_SUPPORT__
        /* for 64+32 */
        if (total_drv_num == 0)
        {
            error_string_ptr = GetString(STR_GLOBAL_INSERT_MEMORY_CARD);
        }
        else
        {
            error_string_ptr = GetString(FMGR_FS_MEDIA_CHANGED_TEXT);
        }
        #else
        error_string_ptr = GetString(FMGR_FS_MEDIA_CHANGED_TEXT);
        #endif
        mmi_imgview_display_popup_sg(g_imgadv_cui_gid, (UI_string_type)error_string_ptr, MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
        mmi_imgadv_unlock_filelist();
    #ifdef __DRM_SUPPORT__
        if (g_imgadv_cntx.is_rotate_action == MMI_TRUE)
        {
            /* rotate should not consume */
            g_imgadv_cntx.is_rotate_action = MMI_FALSE;
            mmi_imgadv_pause_drm_consume_if_need();
        }
    #endif
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_entry_app_screen
 * DESCRIPTION
 *  Entry function of imgadv viewer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_entry_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  filelist_is_ok;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imgadv_add_direct_exit_state(&g_imgadv_cntx.direct_exit, IMGADV_DIRECT_EXIT_VIEWSCRN);
    /* check if there is small screen above IMAGEVIEWER */
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        /* currently we clear layer as black as background of small screen. */
        gdi_layer_get_base_handle(&g_imgadv_cntx.cache_layer_handle);
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);      
        gdi_layer_pop_and_restore_active();   
        return;
    }

    /* check filelist valid or not , if total_count < 0, it means folder changed; we need to resort filelist again. */
    g_imgadv_cntx.is_change_image = MMI_FALSE;
    /* prefetch mode has not filelist */
    if (g_imgview_cui_ptr->view_mode.viewmode != CUI_IMGVIEW_VIEWMODE_PREFETCH &&
        g_imgview_cui_ptr->view_mode.viewmode != CUI_IMGVIEW_VIEWMODE_FILENAME)
    {
        filelist_is_ok = mmi_imgadv_check_filelist();
    }
    else
    {
        filelist_is_ok = MMI_TRUE;
    }
    
    if (!filelist_is_ok)
    {
        mmi_imgadv_unlock_filelist();
        return;
    }
    g_imgadv_cntx.is_rotate_action = MMI_FALSE;
    mmi_imgadv_entry_app_screen_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_preentry_view_screen
 * DESCRIPTION
 *  Preentry function of imgadv viewer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_preentry_view_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  filelist_is_ok;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filelist_is_ok = mmi_imgadv_check_filelist();
    if (!filelist_is_ok)
    {
        return;
    }
    mmi_imgadv_run_imgview_cui(g_mediaview_cui_gid,g_imgview_fl_hdl, g_imgview_fl_idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_start_decode_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_start_decode_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer(10, mmi_imgadv_extract_image_to_cache_layer);
    g_imgadv_cntx.is_decode_timer_on = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_cancel_decode_timer
 * DESCRIPTION
 *  imgview delete screen callback handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_cancel_decode_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_imgadv_extract_image_to_cache_layer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_resume_decode_timer_if_need
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_resume_decode_timer_if_need(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_imgadv_cntx.is_decode_timer_on == TRUE)
    {
        gui_start_timer(10, mmi_imgadv_extract_image_to_cache_layer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_del_scr_callback
 * DESCRIPTION
 *  imgview delete screen callback handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_imgadv_del_scr_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_DEL_SCR_CB);
    gui_cancel_timer(mmi_imgadv_osd_fade_cyclic);
    g_imgadv_cntx.is_real_decode = MMI_FALSE;
    
#ifdef __DRM_SUPPORT__
    if (g_imgadv_cntx.is_rotate_action == MMI_FALSE)
    {
        /* rotate should not consume */
        mmi_imgadv_pause_drm_consume_if_need();
    }
#endif

    if (g_imgadv_cntx.is_change_image == MMI_FALSE)
    {
        mmi_imgadv_unlock_filelist();
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_exit_app_screen
 * DESCRIPTION
 *  imgadv exit screen handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_exit_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_direct_exit;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_EXIT_SCREEN);
    is_direct_exit = mmi_imgadv_is_direct_exit_state(g_imgadv_cntx.direct_exit, IMGADV_DIRECT_EXIT_VIEWSCRN);
    if (is_direct_exit)
    {
        return;
    }
    
    gdi_lcd_set_rotate_by_layer(FALSE);
    
#if defined(__MMI_GESTURES_FRAMEWORK__) && defined( __MMI_TOUCH_SCREEN__)
    mmi_frm_gesture_stop_listen_event();
#endif

#ifdef __MMI_TVOUT__
    gdi_image_stop_animation(g_imgadv_cntx.animation_on_tv);
    if (mdi_tvout_is_enable())
    {
        /* restore back to GDI */
        mdi_tvout_set_owner(MDI_TV_OWNER_GDI);

        /* restore back to start mode1 */
        mdi_tvout_set_mode(
            MDI_TV_MODE_LCD_SCR,
            0,  /* layer_width */
            0); /* layer_height */
        
        /* enable it */
        mmi_phnset_tvout_enable_tv_sleep_in();
        mmi_phnset_enable_partial_ss();
    }
#endif /* __MMI_TVOUT__ */ 
    
#ifdef __DRM_SUPPORT__
    /* based on DEL SCR will be called before exit screen hdlr */
    if (g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_CONSUME)
    {
        DRM_pause_consume(g_imgadv_cntx.drm_id);
        g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_PAUSE;
    }
    else if (g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_DECODING)
    {
        DRM_close_file(g_imgadv_cntx.drm_handle);
        g_imgadv_cntx.drm_handle = NULL;
        g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_EXIT;
    }
#endif

    gdi_anim_stop_all_by_layer(g_imgadv_cntx.cache_layer_handle);

    #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
        gdi_image_nb_stop_all();
    #endif

    /* cancel timer */
    gui_cancel_timer(mmi_imgadv_osd_fade_cyclic);
    gui_cancel_timer(mmi_imgadv_start_decode);
    mmi_imgadv_cancel_decode_timer();
    
    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

#if !defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_set_alpha_blending_source_layer(g_imgadv_cntx.ivadv_org_bld_layer);
#endif

    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        gdi_lcd_set_rotate(GDI_LCD_LAYER_ROTATE_0);
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_flatten(
            g_imgadv_cntx.cache_layer_handle,
            g_imgadv_cntx.base_layer_handle,
            GDI_NULL_HANDLE,
            GDI_NULL_HANDLE);
        gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_90);
        gdi_layer_pop_and_restore_active();
        gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
        gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_0);
        gdi_layer_flatten_to_base(g_imgadv_cntx.cache_layer_handle, 0, 0, 0);
    }
    else
    {
        gdi_layer_flatten_to_base(
            g_imgadv_cntx.cache_layer_handle,
            g_imgadv_cntx.base_layer_handle,
            GDI_NULL_HANDLE,
            GDI_NULL_HANDLE);
    }

    if (g_imgadv_cntx.is_scrolling_title == TRUE)
        gui_scrolling_text_stop(&g_imgadv_cntx.scrolling_title);

    /* free buffer resource */
    mmi_imgadv_free_resource();

    /* free string resource */
    mmi_frm_scrmem_free((void*)g_imgadv_cntx.filepath);
    mmi_frm_scrmem_free((void*)g_imgadv_cntx.buf_filename_no_ext);
    mmi_frm_scrmem_free((void*)g_imgadv_cntx.count_str);
    g_imgadv_cntx.filepath = NULL;
    g_imgadv_cntx.count_str = NULL;
    g_imgadv_cntx.buf_filename_no_ext = NULL;

    /* reset imageviewer rotation, if left normally */
    if (g_imgadv_cntx.is_reset_application == TRUE)
    {
        mmi_imgadv_reset_app();
    }    

    /* restore only base layer active */
    gdi_layer_set_blt_layer(g_imgadv_cntx.base_layer_handle, 0, 0, 0);

    /* this will force title status to redraw */
    entry_full_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_reset_app
 * DESCRIPTION
 *  This function reset flags used by imgadv.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_reset_app()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_RESET);
    g_imgadv_cntx.is_err_displayed = FALSE;
    g_imgadv_cntx.imgview_rotate = 0;
    g_imgadv_cntx.is_rotate_action = MMI_FALSE;
    g_imgadv_cntx.is_reset_application = FALSE;
    g_imgadv_cntx.rotate_able = MMI_TRUE;
}



#ifndef OSD
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_strolling_text_redraw_bg
 * DESCRIPTION
 *  This function clear the rect. of the scrolling text .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_strolling_text_redraw_bg(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_scrolling_text_handle
 * DESCRIPTION
 *  This function handles scrolling text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_scrolling_text_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&g_imgadv_cntx.scrolling_title);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_init_map_box
 * DESCRIPTION
 *  This function is called to initialize the map which is used by imgadv.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_init_map_box(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgadv_cntx.image_width > g_imgadv_cntx.image_height)
    {
        g_imgadv_cntx.map.ratio_map_to_image = (float) MMI_IMGADV_MAP_WIDTH/g_imgadv_cntx.image_width;
        g_imgadv_cntx.map.width = MMI_IMGADV_MAP_WIDTH;
        g_imgadv_cntx.map.map_offset_x = 0;
        g_imgadv_cntx.map.height = (g_imgadv_cntx.image_height * g_imgadv_cntx.map.ratio_map_to_image + 0.99);
        g_imgadv_cntx.map.map_offset_y = (MMI_IMGADV_MAP_HEIGHT - g_imgadv_cntx.map.height)>>1; 
    }
    else
    {
        g_imgadv_cntx.map.ratio_map_to_image = (float) MMI_IMGADV_MAP_HEIGHT/g_imgadv_cntx.image_height;
        g_imgadv_cntx.map.height = MMI_IMGADV_MAP_HEIGHT;
        g_imgadv_cntx.map.map_offset_y = 0;
        g_imgadv_cntx.map.width = (g_imgadv_cntx.image_width * g_imgadv_cntx.map.ratio_map_to_image + 0.99);
        g_imgadv_cntx.map.map_offset_x = (MMI_IMGADV_MAP_WIDTH - g_imgadv_cntx.map.width)>>1;
    }

    g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
    g_imgadv_cntx.map.is_zoomout_able = MMI_FALSE;
    g_imgadv_cntx.map.wnd_height = g_imgadv_cntx.map.height;
    g_imgadv_cntx.map.wnd_width = g_imgadv_cntx.map.width;
    g_imgadv_cntx.map.wnd_offset_x = 0;
    g_imgadv_cntx.map.wnd_offset_y = 0;
    g_imgadv_cntx.map.zoom_factor = 1.25;
    g_imgadv_cntx.map.zoom_factor_cnt = 0;
    g_imgadv_cntx.map.ratio_map_to_thumbnail = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_draw_map
 * DESCRIPTION
 *  This function is called to draw the small map on the screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_draw_map(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x=0, offset_y=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_imgadv_cntx.base_layer_handle);
    
    if (GDI_LCD_LAYER_ROTATE_0 == g_imgadv_cntx.imgview_rotate)
    {
        offset_x = MMI_IMGADV_MAP_POSITION_X + g_imgadv_cntx.map.map_offset_x ;
        offset_y = MMI_IMGADV_MAP_POSITION_Y + g_imgadv_cntx.map.map_offset_y ;
    }
    else if (GDI_LCD_LAYER_ROTATE_270 == g_imgadv_cntx.imgview_rotate)
    {
        offset_x = MMI_IMGADV_ROTATED_MAP_POSITION_X + g_imgadv_cntx.map.map_offset_x ;
        offset_y = MMI_IMGADV_ROTATED_MAP_POSITION_Y + g_imgadv_cntx.map.map_offset_y ;
    }

    gdi_draw_solid_rect(offset_x - 2,
                        offset_y - 2,
                        offset_x + g_imgadv_cntx.map.width + 2,
                        offset_y + g_imgadv_cntx.map.height + 2,
                        GDI_COLOR_TRANSPARENT);

    if(g_imgadv_cntx.map.zoom_factor_cnt > 0)
    {
        gdi_draw_solid_rect(offset_x - 1,
                      offset_y - 1,
                      offset_x + g_imgadv_cntx.map.width + 1,
                      offset_y + g_imgadv_cntx.map.height + 1,
                      GDI_COLOR_GRAY);

        gdi_draw_rect(offset_x - 2,
                      offset_y - 2,
                      offset_x + g_imgadv_cntx.map.width + 2,
                      offset_y + g_imgadv_cntx.map.height + 2,
                      GDI_COLOR_WHITE);

        gdi_draw_solid_rect(offset_x + g_imgadv_cntx.map.wnd_offset_x,
                            offset_y + g_imgadv_cntx.map.wnd_offset_y,
                            offset_x + g_imgadv_cntx.map.wnd_offset_x + g_imgadv_cntx.map.wnd_width,
                            offset_y + g_imgadv_cntx.map.wnd_offset_y + g_imgadv_cntx.map.wnd_height,
                            GDI_COLOR_WHITE);
    }
    gdi_layer_pop_and_restore_active();

}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_draw_num_count
 * DESCRIPTION
 *  This function is called to draw the oo/xx on the screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_draw_num_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;
    S32 offset_x = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_imgview_cui_ptr->cap_enable[CUI_IMGVIEW_CAP_COUNTER])
    {
        return;
    }

    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_TITLE));

    gui_measure_string((UI_string_type) g_imgadv_cntx.count_str, &str_width, &str_height);

    gdi_draw_solid_rect(g_imgadv_cntx.active_osd_layout_ptr->num_count.offset_x,
                        g_imgadv_cntx.active_osd_layout_ptr->num_count.offset_y,
                        g_imgadv_cntx.active_osd_layout_ptr->num_count.offset_x+g_imgadv_cntx.active_osd_layout_ptr->num_count.width,
                        g_imgadv_cntx.active_osd_layout_ptr->num_count.offset_y+g_imgadv_cntx.active_osd_layout_ptr->num_count.height,
                        GDI_COLOR_TRANSPARENT);
    if (!(LCD_WIDTH == 320 && LCD_HEIGHT == 240))
    {
        if(g_imgadv_cntx.active_osd_layout_ptr->num_count.width > str_width)
        {
            offset_x = (g_imgadv_cntx.active_osd_layout_ptr->num_count.width - str_width)>>1;
        }
    }
    else
    {
        if (GDI_LCD_LAYER_ROTATE_0 == g_imgadv_cntx.imgview_rotate)
        {
            if(g_imgadv_cntx.active_osd_layout_ptr->num_count.width > str_width)
            {
                offset_x = (g_imgadv_cntx.active_osd_layout_ptr->num_count.width - str_width)>>1;
            }
        }
    }
    mmi_imgadv_draw_style_text(
        IMGADV_NON_KEY,
        g_imgadv_cntx.count_str,
        g_imgadv_cntx.active_osd_layout_ptr->num_count.offset_x+offset_x,
        g_imgadv_cntx.active_osd_layout_ptr->num_count.offset_y);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_draw_softkey
 * DESCRIPTION
 *  draw preview softkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_draw_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lsk_offset_x = 0;
    S32 lsk_offset_y = 0;
    S32 rsk_offset_x = 0;
    S32 rsk_offset_y = 0;
    S32 str_width;
    S32 str_height;
    CHAR* str_ptr;
    U16 lsk_id;
    U16 rsk_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgview_cui_ptr->lsk_setting.is_customized)
    {
        lsk_id = g_imgview_cui_ptr->lsk_setting.stringid;
    }
    else
    {
        lsk_id = STR_GLOBAL_PRINT;
    }
    rsk_id = STR_GLOBAL_BACK;

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /* if is fullscreen display, or normal display but without mmi_softkey */
    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_BUTTON));

    if (mmi_imgadv_lsk_is_enable())
    {
        str_ptr = (CHAR*) GetString(lsk_id);
        g_imgadv_cntx.is_truncated = MMI_FALSE;
        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);

        if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
        {
            if (LCD_WIDTH < LCD_HEIGHT)
            {
                g_imgadv_cntx.is_truncated = wgui_softkey_get_offset((UI_string_type) str_ptr, &lsk_offset_x, &lsk_offset_y, &g_imgadv_cntx.truncated_width, MMI_LEFT_SOFTKEY, MMI_FRM_SCREEN_ROTATE_270);
            }
            else
            {
                /* for landscape, the API wgui_softkey_get_offset give wrong offset value, so App self modify it */
                lsk_offset_x = LCD_HEIGHT - str_width - 2;
                lsk_offset_y = LCD_WIDTH - str_height - 2;
                g_imgadv_cntx.is_truncated = MMI_FALSE;
            }
        }
        else
        {
            g_imgadv_cntx.is_truncated = wgui_softkey_get_offset(
                                             (UI_string_type) str_ptr, 
                                             &lsk_offset_x, 
                                             &lsk_offset_y, 
                                             &g_imgadv_cntx.truncated_width, 
                                             MMI_LEFT_SOFTKEY,
                                             mmi_frm_get_screen_rotate());        
        }

        /* check r2lMMIFlag flag to correct offset_x of string, due to we will do the change in 
         * mmi_camera_draw_style_text() */
        if (r2lMMIFlag)
        {
            lsk_offset_x -= gui_get_string_width((UI_string_type) str_ptr);
        }

        if (g_imgadv_cntx.lsk.is_press)
        {
            lsk_offset_x++;
            lsk_offset_y++;
        }

        gdi_draw_solid_rect(lsk_offset_x-2,lsk_offset_y-2,lsk_offset_x+str_width+2,lsk_offset_y+str_height+2,GDI_COLOR_TRANSPARENT);
        mmi_imgadv_draw_style_text(
            IMGADV_LSK,
            str_ptr,
            lsk_offset_x ,
            lsk_offset_y );

        g_imgadv_cntx.lsk.offset_x = lsk_offset_x;
        g_imgadv_cntx.lsk.offset_y = lsk_offset_y;
        g_imgadv_cntx.lsk.width = str_width;
        g_imgadv_cntx.lsk.height = str_height;
    }

    /* rsk */
    str_ptr = (CHAR*) GetString(rsk_id);
    g_imgadv_cntx.is_truncated = MMI_FALSE;
    gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        if (LCD_WIDTH < LCD_HEIGHT)
        {
            g_imgadv_cntx.is_truncated = wgui_softkey_get_offset((UI_string_type) str_ptr, &rsk_offset_x, &rsk_offset_y, &g_imgadv_cntx.truncated_width, MMI_RIGHT_SOFTKEY, MMI_FRM_SCREEN_ROTATE_270);
        }
        else
        {
            /* for landscape, the API wgui_softkey_get_offset give wrong offset value, so App self modify it */
            rsk_offset_x = LCD_HEIGHT - str_width - 2;
            rsk_offset_y = 2;
            if (str_width > LCD_HEIGHT - rsk_offset_x - 2)
            {
                g_imgadv_cntx.truncated_width = LCD_HEIGHT - rsk_offset_x - 2;
                g_imgadv_cntx.is_truncated = MMI_TRUE;
            }
            else
            {
                g_imgadv_cntx.is_truncated = MMI_FALSE;
            }
        }
    }
    else
    {
        g_imgadv_cntx.is_truncated = wgui_softkey_get_offset(
                                         (UI_string_type) str_ptr, 
                                         &rsk_offset_x, 
                                         &rsk_offset_y, 
                                         &g_imgadv_cntx.truncated_width, 
                                         MMI_RIGHT_SOFTKEY,
                                        mmi_frm_get_screen_rotate());
    }

    if (r2lMMIFlag)
    {
        rsk_offset_x -= gui_get_string_width((UI_string_type) str_ptr);
    }

    if (g_imgadv_cntx.rsk.is_press)
    {
        rsk_offset_x++;
        rsk_offset_y++;
    }

    gdi_draw_solid_rect(rsk_offset_x-2,rsk_offset_y-2,rsk_offset_x+str_width+2,rsk_offset_y+str_height+2,GDI_COLOR_TRANSPARENT);
    mmi_imgadv_draw_style_text(
        IMGADV_RSK,
        str_ptr,
        rsk_offset_x,
        rsk_offset_y);

    g_imgadv_cntx.rsk.offset_x = rsk_offset_x;
    g_imgadv_cntx.rsk.offset_y = rsk_offset_y;
    g_imgadv_cntx.rsk.width = str_width;
    g_imgadv_cntx.rsk.height = str_height;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_draw_style_text
 * DESCRIPTION
 *  This function is called to draw style text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_draw_style_text(imgadv_key_enum key_object, CHAR* str, S32 offset_x, S32 offset_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (r2lMMIFlag)
    {
        offset_x += gui_get_string_width((UI_string_type) str);
    }
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_push_and_set_alpha_blending_source_layer(g_imgadv_cntx.cache_layer_handle);
#endif
    gui_move_text_cursor(offset_x, offset_y);
    gui_set_text_color(gui_color(255, 255, 255));
    gui_set_text_border_color(gui_color(0, 0, 0));
    if (key_object == IMGADV_NON_KEY)
    {
        gui_print_bordered_text((UI_string_type) str);
    }
    else
    {
        if (g_imgadv_cntx.is_truncated == MMI_TRUE)
        {
            gui_print_truncated_borderd_text(offset_x, offset_y, g_imgadv_cntx.truncated_width, (UI_string_type) str);
        }
        else
        {
            gui_print_bordered_text((UI_string_type) str);
        }
    }
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_pop_and_restore_alpha_blending_source_layer();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_init_osd_icon_position
 * DESCRIPTION
 *  This function is called to initilize osd icon positions.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_init_osd_icon_position(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    imgadv_osd_layout_struct *active_imgadv_osd_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    #define INIT_OSD_TOUCH_ICON(__a__,__A__)                                    \
    do {                                                                        \
      if(active_imgadv_osd_ptr->##__a__##.is_show)                              \
      {                                                                         \
         gdi_image_get_dimension_id((U16)(IMG_ID_IMAGEVIEWER_##__A__##), \
                                    &(active_imgadv_osd_ptr->##__a__##.width),  \
                                    &(active_imgadv_osd_ptr->##__a__##.height)); \
         active_imgadv_osd_ptr->##__a__##.is_press = FALSE;                        \
      }                                                                         \
    } while(0);

    active_imgadv_osd_ptr = &g_imgadv_osd_cntx;

    active_imgadv_osd_ptr->larrow.is_show = TRUE;
    active_imgadv_osd_ptr->rarrow.is_show = TRUE;        


    INIT_OSD_TOUCH_ICON(larrow,LEFT_ARROW_UP);
    INIT_OSD_TOUCH_ICON(rarrow,RIGHT_ARROW_UP);
    INIT_OSD_TOUCH_ICON(zoomin,ZOOMIN_UP);
    INIT_OSD_TOUCH_ICON(zoomout,ZOOMOUT_UP);
    INIT_OSD_TOUCH_ICON(rotate,ROTATE_UP);
    
    active_imgadv_osd_ptr = &g_imgadv_osd_cntx_270;

    active_imgadv_osd_ptr->larrow.is_show = TRUE;
    active_imgadv_osd_ptr->rarrow.is_show = TRUE;        

    INIT_OSD_TOUCH_ICON(larrow,LEFT_ARROW_UP);
    INIT_OSD_TOUCH_ICON(rarrow,RIGHT_ARROW_UP);
    INIT_OSD_TOUCH_ICON(zoomin,ZOOMIN_UP);
    INIT_OSD_TOUCH_ICON(zoomout,ZOOMOUT_UP);
    INIT_OSD_TOUCH_ICON(rotate,ROTATE_UP);
    
    #ifdef INIT_OSD_TOUCH_ICON 
    #undef INIT_OSD_TOUCH_ICON
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_draw_osd_item
 * DESCRIPTION
 *  This function is called to draw osd.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_draw_osd_item(imgadv_osd_icon_struct item,
                                                MMI_BOOL is_enable,
                                                U16 down_icon,
                                                U16 up_icon,
                                                U16 disable_icon)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(item.offset_x, item.offset_y, item.offset_x + item.width, item.offset_y + item.height, GDI_COLOR_TRANSPARENT);
    if (!is_enable)
    {
        gdi_image_draw_id(item.offset_x, item.offset_y, disable_icon);
    }
    else
    {
        if (item.is_press == FALSE)
        {
            gdi_image_draw_id(item.offset_x, item.offset_y, up_icon);
        }
        else
        {
            gdi_image_draw_id(item.offset_x, item.offset_y, down_icon);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_draw_zoom_rotate
 * DESCRIPTION
 *  This function is called to draw osd.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_draw_zoom_rotate(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imgadv_draw_osd_item(
        g_imgadv_cntx.active_osd_layout_ptr->zoomin,
        g_imgadv_cntx.map.is_zoomin_able,
        IMG_ID_IMAGEVIEWER_ZOOMIN_DOWN,
        IMG_ID_IMAGEVIEWER_ZOOMIN_UP,
        IMG_ID_IMAGEVIEWER_ZOOMIN_DISABLE);
    mmi_imgadv_draw_osd_item(
        g_imgadv_cntx.active_osd_layout_ptr->zoomout,
        g_imgadv_cntx.map.is_zoomout_able,
        IMG_ID_IMAGEVIEWER_ZOOMOUT_DOWN,
        IMG_ID_IMAGEVIEWER_ZOOMOUT_UP,
        IMG_ID_IMAGEVIEWER_ZOOMOUT_DISABLE);
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_0)
    {
        mmi_imgadv_draw_osd_item(
            g_imgadv_cntx.active_osd_layout_ptr->rotate,
            g_imgadv_cntx.rotate_able,
            IMG_ID_IMAGEVIEWER_ROTATE_DOWN,
            IMG_ID_IMAGEVIEWER_ROTATE_UP,
            IMG_ID_IMAGEVIEWER_ZOOMIN_DISABLE);
    }
    else if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        mmi_imgadv_draw_osd_item(
            g_imgadv_cntx.active_osd_layout_ptr->rotate,
            g_imgadv_cntx.rotate_able,
            IMG_ID_IMAGEVIEWER_ROTATE_CCW_DOWN,
            IMG_ID_IMAGEVIEWER_ROTATE_CCW_UP,
            IMG_ID_IMAGEVIEWER_ZOOMOUT_DISABLE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_draw_external_osd
 * DESCRIPTION
 *  This function is called to draw osd.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_draw_external_osd(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    if (g_imgadv_cntx.is_decoding)
    {
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
#endif

    gdi_layer_push_and_set_active(g_imgadv_cntx.base_layer_handle);
    mmi_imgadv_draw_zoom_rotate();
    mmi_imgadv_draw_softkey();
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_draw_osd
 * DESCRIPTION
 *  This function is called to draw osd.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_draw_osd(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgadv_cntx.is_external_req)
    {
        mmi_imgadv_draw_external_osd();
        return;
    }
    
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    if (g_imgadv_cntx.is_decoding)
    {
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
#endif

    gdi_layer_push_and_set_active(g_imgadv_cntx.base_layer_handle);
    mmi_imgadv_draw_osd_item(
        g_imgadv_cntx.active_osd_layout_ptr->larrow,
        MMI_TRUE,
        IMG_ID_IMAGEVIEWER_LEFT_ARROW_DOWN,
        IMG_ID_IMAGEVIEWER_LEFT_ARROW_UP,
        NULL);
    mmi_imgadv_draw_osd_item(
        g_imgadv_cntx.active_osd_layout_ptr->rarrow,
        MMI_TRUE,
        IMG_ID_IMAGEVIEWER_RIGHT_ARROW_DOWN,
        IMG_ID_IMAGEVIEWER_RIGHT_ARROW_UP,
        NULL);
    mmi_imgadv_draw_zoom_rotate();
    mmi_imgadv_draw_softkey();
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_imgadv_draw_num_count();
    if (g_imgadv_cntx.active_osd_layout_ptr->rarrow.is_press == FALSE
        && g_imgadv_cntx.active_osd_layout_ptr->larrow.is_press == FALSE
        && g_imgadv_cntx.active_osd_layout_ptr->rotate.is_press == FALSE
        && g_imgadv_cntx.active_osd_layout_ptr->zoomin.is_press == FALSE
        && g_imgadv_cntx.active_osd_layout_ptr->zoomout.is_press == FALSE
        && g_imgadv_cntx.lsk.is_press == FALSE
        && g_imgadv_cntx.rsk.is_press == FALSE)
    {
        gdi_lcd_repaint_all();
        mmi_imgadv_draw_title();
    }
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */    

    gdi_layer_pop_and_restore_active();
}

#endif

#ifndef KEY_PEN_EVENT
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_init_key_handler
 * DESCRIPTION
 *  init key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_init_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgadv_cntx.is_external_req)
    {
        mmi_imgadv_init_external_key_handler();
        return;
    }
    
    ClearInputEventHandler(MMI_DEVICE_KEY);    

    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
        {
            SetKeyHandler(mmi_imgadv_move_down_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_left_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_up_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_right_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

            SetKeyHandler(mmi_imgadv_move_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        }
        else
        {
            SetKeyHandler(mmi_imgadv_previous_image_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_next_image_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_previous_image_release, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_next_image_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
        }
        SetKeyHandler(mmi_imgadv_rsk_press, KEY_RSK, KEY_EVENT_DOWN); 
        SetKeyHandler(mmi_imgadv_rsk_release, KEY_RSK, KEY_EVENT_UP);
    }
    else
    {
        if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
        {
            SetKeyHandler(mmi_imgadv_move_down_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_left_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_up_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_right_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

            SetKeyHandler(mmi_imgadv_move_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        }
        else
        {
            SetKeyHandler(mmi_imgadv_previous_image_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_next_image_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_previous_image_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_next_image_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);        
        }
        SetKeyHandler(mmi_imgadv_rsk_press, KEY_RSK, KEY_EVENT_DOWN); 
        SetKeyHandler(mmi_imgadv_rsk_release, KEY_RSK, KEY_EVENT_UP);
    }

    if (g_imgadv_cntx.map.is_zoomin_able)
    {
        SetKeyHandler(mmi_imgadv_zoomin_press, KEY_1, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_imgadv_zoomin_release, KEY_1, KEY_EVENT_UP);
    }

    if (g_imgadv_cntx.map.is_zoomout_able)
    {
        SetKeyHandler(mmi_imgadv_zoomout_press, KEY_2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_imgadv_zoomout_release, KEY_2, KEY_EVENT_UP);
    }
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    SetKeyHandler(mmi_imgadv_dummy, KEY_1, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(mmi_imgadv_dummy, KEY_1, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_imgadv_dummy, KEY_2, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(mmi_imgadv_dummy, KEY_2, KEY_EVENT_REPEAT);
#endif
    
    SetKeyHandler(mmi_imgadv_rotate_press, KEY_3, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgadv_rotate_release, KEY_3, KEY_EVENT_UP);

#if 0        
/* under construction !*/
/* under construction !*/
#endif
    {
        SetKeyHandler(mmi_imgadv_next_image_press, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_imgadv_previous_image_press, KEY_VOL_UP, KEY_EVENT_DOWN);

        SetKeyHandler(mmi_imgadv_next_image_release, KEY_VOL_DOWN, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_previous_image_release, KEY_VOL_UP, KEY_EVENT_UP);
    }

    SetKeyHandler(mmi_imgadv_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgadv_lsk_release, KEY_LSK, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_move_right_press
 * DESCRIPTION
 *  This function handles the right arrow key pressed event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_move_right_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    if (g_imgadv_cntx.is_decoding)
    {
        gdi_image_nb_stop_all();
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
#endif
    mmi_imgadv_reset_osd_fade(MMI_FALSE);
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_0)
    {
        gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
    else
    {
        gdi_layer_blt_previous(0, 0, LCD_HEIGHT - 1, LCD_WIDTH - 1);
    }
    
    mmi_imgadv_cancel_decode_timer();
    mmi_imgadv_translate(3,0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_move_up_press
 * DESCRIPTION
 *  This function handles the up arrow key pressed event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_move_up_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    if (g_imgadv_cntx.is_decoding)
    {
        gdi_image_nb_stop_all();
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
#endif
    mmi_imgadv_reset_osd_fade(MMI_FALSE);
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_0)
    {
        gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
    else
    {
        gdi_layer_blt_previous(0, 0, LCD_HEIGHT - 1, LCD_WIDTH - 1);
    }
    mmi_imgadv_cancel_decode_timer();
    mmi_imgadv_translate(0,-3);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_move_down_press
 * DESCRIPTION
 *  This function handles the down key pressed event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_move_down_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    if (g_imgadv_cntx.is_decoding)
    {
        gdi_image_nb_stop_all();
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
#endif
    mmi_imgadv_reset_osd_fade(MMI_FALSE);
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_0)
    {
        gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
    else
    {
        gdi_layer_blt_previous(0, 0, LCD_HEIGHT - 1, LCD_WIDTH - 1);
    }
    mmi_imgadv_cancel_decode_timer();
    mmi_imgadv_translate(0,3);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_move_left_press
 * DESCRIPTION
 *  This function handles the left key pressed event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_move_left_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    if (g_imgadv_cntx.is_decoding)
    {
        gdi_image_nb_stop_all();
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
#endif
    mmi_imgadv_reset_osd_fade(MMI_FALSE);
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_0)
    {
        gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
    else
    {
        gdi_layer_blt_previous(0, 0, LCD_HEIGHT - 1, LCD_WIDTH - 1);
    }
    mmi_imgadv_cancel_decode_timer();
    mmi_imgadv_translate(-3,0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_move_key_release
 * DESCRIPTION
 *  This function handles the up/right/left/down key release event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_move_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
    {
        return;
    }
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    if (g_imgadv_cntx.is_decoding)
    {
        gdi_image_nb_stop_all();
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
#endif

    mmi_imgadv_start_decode_timer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_zoomin_press
 * DESCRIPTION
 *  This function handles zoomin key pressed event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_zoomin_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgadv_cntx.map.is_zoomin_able)
    {
        mmi_imgadv_cancel_decode_timer();
        g_imgadv_cntx.active_osd_layout_ptr->zoomin.is_press = TRUE;
        mmi_imgadv_reset_osd_fade(MMI_FALSE);
        mmi_imgadv_draw_osd();
        gdi_lcd_repaint_all();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_zoomin_release
 * DESCRIPTION
 *  This function handles zoomin key released event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_zoomin_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cntx.active_osd_layout_ptr->zoomin.is_press = FALSE;
    //mmi_imgadv_reset_osd_fade(MMI_TRUE);
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
    mmi_imgadv_zoomin();

    /* for issue: while 1) extract_to_cache is in timer but be canceled due to zoom in key press and 2) this image is not able to zoomin in this situation. */
    mmi_imgadv_resume_decode_timer_if_need();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_zoomout_press
 * DESCRIPTION
 *  This function handle zoomout key pressed event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_zoomout_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgadv_cntx.map.is_zoomout_able)
    {
        mmi_imgadv_cancel_decode_timer();
        g_imgadv_cntx.active_osd_layout_ptr->zoomout.is_press = TRUE;
        mmi_imgadv_reset_osd_fade(MMI_FALSE);
        mmi_imgadv_draw_osd();
        gdi_lcd_repaint_all();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_zoomout_release
 * DESCRIPTION
 *  This function handles zoomout key released event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_zoomout_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cntx.active_osd_layout_ptr->zoomout.is_press = FALSE;
    //mmi_imgadv_reset_osd_fade(MMI_TRUE);
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
    mmi_imgadv_zoomout();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_rotate_press
 * DESCRIPTION
 *  This function handles the rotate key pressed event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_rotate_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_imgadv_cntx.rotate_able)
    {
        return;
    }
    mmi_imgadv_cancel_decode_timer();
    g_imgadv_cntx.active_osd_layout_ptr->rotate.is_press = TRUE;
    mmi_imgadv_reset_osd_fade(MMI_FALSE);
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_rotate_release
 * DESCRIPTION
 *  This function handles the rotate key released event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_rotate_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_imgadv_cntx.rotate_able)
    {
        return;
    }
    g_imgadv_cntx.active_osd_layout_ptr->rotate.is_press = FALSE;
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();

#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    if (g_imgadv_cntx.is_decoding)
    {
        gdi_image_nb_stop_all();
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
#endif
    /* Set flag for not reset imageviewer  */
    g_imgadv_cntx.is_reset_application = FALSE;
    g_imgadv_cntx.is_err_displayed = FALSE;
    g_imgadv_cntx.is_change_image = MMI_TRUE;
    g_imgadv_cntx.imgview_rotate = (g_imgadv_cntx.imgview_rotate==GDI_LCD_LAYER_ROTATE_0)?GDI_LCD_LAYER_ROTATE_270 : GDI_LCD_LAYER_ROTATE_0;
    g_imgadv_cntx.is_rotate_action = MMI_TRUE;
    if (g_imgadv_cntx.is_external_req)
    {
        mmi_frm_scrn_enter(g_imgadv_cui_gid, SCR_ID_GLOBAL_DUMMY, NULL, mmi_imgadv_temp_dummy_screen, MMI_FRM_FULL_SCRN);
        mmi_frm_scrn_close(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW_EXT);
        g_imgadv_cntx.is_external_req = MMI_TRUE;
        
        mmi_imgadv_entry_external_app_screen();
    }
    else
    {
        gdi_layer_resize(LCD_WIDTH,LCD_HEIGHT);
        gdi_lcd_set_rotate(GDI_LCD_LAYER_ROTATE_0);
        /* Due to imageviewer maybe interuupt popup by audio player in background in horizontal mode, we need to clear bg for this scenario.
         * clear bg to white color */
        g_imgadv_cntx.osd_opacity = MMI_IMGADV_OSD_FADEOUT_FACTOR;
        gdi_layer_push_and_set_active(g_imgadv_cntx.base_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_set_opacity(TRUE, (U8) g_imgadv_cntx.osd_opacity);
        gdi_layer_pop_and_restore_active();

        gdi_layer_flatten_to_base(g_imgadv_cntx.base_layer_handle, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
        mmi_frm_scrn_enter(g_imgadv_cui_gid, SCR_ID_GLOBAL_DUMMY, NULL, mmi_imgadv_temp_dummy_screen, MMI_FRM_FULL_SCRN);
        mmi_frm_scrn_close(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW);
        mmi_imgadv_entry_app_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_lsk_press
 * DESCRIPTION
 *  This function handles the lsk pressed event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_imgadv_lsk_is_enable())
    {
        return;
    }
    
    mmi_imgadv_cancel_decode_timer();
    g_imgadv_cntx.lsk.is_press = TRUE;
    mmi_imgadv_reset_osd_fade(MMI_FALSE);
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_lsk_release
 * DESCRIPTION
 *  This function handles the lsk released event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_imgadv_lsk_is_enable())
    {
        mmi_imgadv_osd_show_up();
        return;
    }

    g_imgadv_cntx.lsk.is_press = FALSE;
    mmi_imgadv_reset_osd_fade(MMI_TRUE);
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
    /* When can print, do cont. */
    if (g_imgview_cui_ptr->lsk_setting.is_customized)
    {
        mmi_imgadv_lsk_custmize_confirmed();
    }
    else
    {
        /* print */
    #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
        if (g_imgadv_cntx.is_decoding)
        {
            gdi_image_nb_stop_all();
            gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();
        }
    #endif
        mmi_imgadv_print_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_rsk_press
 * DESCRIPTION
 *  This function handles the rsk pressed event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imgadv_cancel_decode_timer();
    g_imgadv_cntx.rsk.is_press = TRUE;
    mmi_imgadv_reset_osd_fade(MMI_FALSE);
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_rsk_release
 * DESCRIPTION
 *  This function handles the rsk released event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cntx.rsk.is_press = FALSE;
    mmi_imgadv_reset_osd_fade(MMI_TRUE);
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    if (g_imgadv_cntx.is_decoding)
    {
        gdi_image_nb_stop_all();
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
#endif
    if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
    {
        mmi_imgadv_reenter();
    }
    else
    {
        g_imgadv_cntx.is_reset_application = TRUE;
    #ifdef __DRM_SUPPORT__
        mmi_imgadv_pause_drm_consume_if_need();
    #endif
        mmi_imgadv_unlock_filelist();
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_image_change
 * DESCRIPTION
 *  This function is called to show image.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_image_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(g_imgadv_cui_gid, SCR_ID_GLOBAL_DUMMY, NULL, mmi_imgadv_temp_dummy_screen, MMI_FRM_FULL_SCRN);
    g_imgadv_cntx.is_change_image = MMI_TRUE;
    mmi_frm_scrn_close(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW);
    g_imgadv_cntx.is_err_displayed = FALSE;
    mmi_imgadv_entry_app_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_filelist_load_proc
 * DESCRIPTION
 *  This function create a list.
 * PARAMETERS
 *  image_viewer_id      :  [IN]  Image view group id.
 * RETURNS
 *  S32.
 *****************************************************************************/
mmi_ret mmi_imgadv_filelist_load_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_refresh_result_event_struct *evt = (srv_fmgr_filelist_refresh_result_event_struct*) param;
    S32 file_count;
    mmi_ret ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() != SCR_ID_IMGVIEW_VIEW)
    {
        return ret;
    }
    switch(param->evt_id) 
    {
        case EVT_ID_SRV_FMGR_FILELIST_LOAD_RESULT:
        {
            if (evt->result >= 0)
            {
                g_imgadv_cntx.is_refreshing = MMI_FALSE;
                file_count = srv_fmgr_filelist_count(evt->handle);
                if (file_count > 0)
                {
                    if (evt->user_data == (void*)0)
                    {
                        g_imgadv_cntx.active_osd_layout_ptr->larrow.is_press = TRUE;
                        mmi_imgadv_previous_image_release();
                    }
                    if (evt->user_data == (void*)1)
                    {
                        g_imgadv_cntx.active_osd_layout_ptr->rarrow.is_press = TRUE;
                        mmi_imgadv_next_image_release();
                    }
                }
                else if (file_count < 0)
                {
                    mmi_imgview_display_popup_sg(g_imgadv_cui_gid, (UI_string_type)GetString(FMGR_FS_MEDIA_CHANGED_TEXT), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
                    mmi_frm_scrn_close(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW);
                    g_imgview_state = MMI_IMGVIEW_STATE_EXIT;
                    return ret;
                }
                else if (file_count == 0)
                {
                    mmi_imgview_display_popup_sg(g_imgadv_cui_gid, (UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
                    mmi_frm_scrn_close(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW);
                    return ret;
                }
            }
            else
            {
                MMI_ID_TYPE error_str_id;
                error_str_id = srv_fmgr_fs_error_get_string(evt->result);
                mmi_imgview_display_popup_sg(g_imgadv_cui_gid, (UI_string_type)GetString(error_str_id), 
                    (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(evt->result), 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
                mmi_frm_scrn_close(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW);
            }
        }
        break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_next_image_press
 * DESCRIPTION
 *  This function is called to show next image.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_next_image_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgadv_cntx.is_refreshing)
    {
        return;
    }
    mmi_imgadv_cancel_decode_timer();
    g_imgadv_cntx.active_osd_layout_ptr->rarrow.is_press = TRUE;
    mmi_imgadv_reset_osd_fade(MMI_FALSE);
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_previous_image_press
 * DESCRIPTION
 *  This function is called to show previous image.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_previous_image_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgadv_cntx.is_refreshing)
    {
        return;
    }
    mmi_imgadv_cancel_decode_timer();
    g_imgadv_cntx.active_osd_layout_ptr->larrow.is_press = TRUE;
    mmi_imgadv_reset_osd_fade(MMI_FALSE);
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_next_image
 * DESCRIPTION
 *  press down in view detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_next_image_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct file_info;
    S32 counter;
    S32 file_count;
    S32 ret;
    S32 older_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_imgadv_cntx.active_osd_layout_ptr->rarrow.is_press)
    {
        return;
    }
    g_imgadv_cntx.active_osd_layout_ptr->rarrow.is_press = FALSE;
    mmi_imgadv_reset_osd_fade(MMI_TRUE);
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();

    #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    if (g_imgadv_cntx.is_decoding)
    {
        gdi_image_nb_stop_all();    
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
    #endif

    #ifdef __DRM_SUPPORT__
        mmi_imgadv_pause_drm_consume_if_need();
    #endif

    /* prefetch mode has not filelist */
    if (g_imgview_cui_ptr->view_mode.viewmode == CUI_IMGVIEW_VIEWMODE_PREFETCH)
    {
        mmi_imgadv_prefetch_image(MMI_TRUE);
        mmi_imgadv_image_change();
        return;
    }

    /* FMGR_Revise */
    file_count = srv_fmgr_filelist_count(g_imgview_fl_hdl);
    counter = 0;

    if (file_count > 1)
    {
        do
        {
            older_index = g_imgview_fl_idx;
            /* FMGR_Revise */
            g_imgview_fl_idx ++;
            if(g_imgview_fl_idx == file_count)
                g_imgview_fl_idx = 0;
            cui_folder_browser_set_highlight_index(mmi_mediaview_get_browse_gid(), g_imgview_fl_idx);
            ret = srv_fmgr_filelist_get_fileinfo(g_imgview_fl_hdl, g_imgview_fl_idx, &file_info);
            if (ret == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
            {
                g_imgadv_cntx.is_refreshing = MMI_TRUE;
                ret = srv_fmgr_filelist_load_file(g_imgview_fl_hdl, g_imgview_fl_idx, mmi_imgadv_filelist_load_proc, (void*)1);
                if (ret == SRV_FMGR_FILELIST_ERROR_FILE_READY)
                {
                    /* Do nothing */
                }
                else if (ret == 0)
                {
                    g_imgview_fl_idx = older_index;
                    return;
                }
                else if (ret < 0)
                {
                    MMI_ID_TYPE error_str_id;
                    error_str_id = srv_fmgr_fs_error_get_string(ret);
                    mmi_imgview_display_popup_sg(g_imgadv_cui_gid, (UI_string_type)GetString(error_str_id), 
                        (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(ret), 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
                    mmi_frm_scrn_close(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW);
                    return;
                }
            }
            counter++;
            if (!(file_info.attribute & FS_ATTR_DIR))
            {
                mmi_imgadv_image_change();
                return;
            }

            if (counter >= (file_count - 1))
            {
                return;
            }

        } while (1);
    }
    else if (file_count < 0)
    {
        mmi_imgview_display_popup_sg(g_imgadv_cui_gid, (UI_string_type)GetString(FMGR_FS_MEDIA_CHANGED_TEXT), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
        mmi_frm_scrn_close(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW);
        g_imgview_state = MMI_IMGVIEW_STATE_EXIT;
        return;
    }
    else if (file_count == 0)
    {
        mmi_imgview_display_popup_sg(g_imgadv_cui_gid, (UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
        mmi_frm_scrn_close(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_previous_image
 * DESCRIPTION
 *  press up in view detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_previous_image_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct file_info;
    S32 counter;
    S32 file_count;
    S32 ret;
    S32 older_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_imgadv_cntx.active_osd_layout_ptr->larrow.is_press)
    {
        return;
    }
    g_imgadv_cntx.active_osd_layout_ptr->larrow.is_press = FALSE;
    mmi_imgadv_reset_osd_fade(MMI_TRUE);
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();

    #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
        if (g_imgadv_cntx.is_decoding)
        {
            gdi_image_nb_stop_all();
            gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();
        }
    #endif

    #ifdef __DRM_SUPPORT__
        mmi_imgadv_pause_drm_consume_if_need();
    #endif

    /* prefetch mode has not filelist */
    if (g_imgview_cui_ptr->view_mode.viewmode == CUI_IMGVIEW_VIEWMODE_PREFETCH)
    {
        mmi_imgadv_prefetch_image(MMI_FALSE);
        mmi_imgadv_image_change();
        return;
    }
    /* FMGR_Revise */
    file_count = srv_fmgr_filelist_count(g_imgview_fl_hdl);
    counter = 0;

    if (file_count > 1)
    {
        do
        {
            older_index = g_imgview_fl_idx;
            /* FMGR_Revise */
            if(g_imgview_fl_idx>0)
                g_imgview_fl_idx --;
            else
                g_imgview_fl_idx = file_count-1;

            cui_folder_browser_set_highlight_index(mmi_mediaview_get_browse_gid(), g_imgview_fl_idx);
            ret = srv_fmgr_filelist_get_fileinfo(g_imgview_fl_hdl, g_imgview_fl_idx, &file_info);
            if (ret == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
            {
                g_imgadv_cntx.is_refreshing = MMI_TRUE;
                ret = srv_fmgr_filelist_load_file(g_imgview_fl_hdl, g_imgview_fl_idx, mmi_imgadv_filelist_load_proc, (void*)0);
                if (ret == SRV_FMGR_FILELIST_ERROR_FILE_READY)
                {
                    /* Do nothing */
                }
                else if (ret == 0)
                {
                    g_imgview_fl_idx = older_index;
                    return;
                }
                else if (ret < 0)
                {
                    MMI_ID_TYPE error_str_id;
                    error_str_id = srv_fmgr_fs_error_get_string(ret);
                    mmi_imgview_display_popup_sg(g_imgadv_cui_gid, (UI_string_type)GetString(error_str_id), 
                        (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(ret), 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
                    mmi_frm_scrn_close(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW);
                    return;
                }
            }
            
            counter++;

            if (!(file_info.attribute & FS_ATTR_DIR))
            {
                mmi_imgadv_image_change();
                return;
            }

            if (counter >= (file_count - 1))
            {
                return;
            }

        } while (1);
    }
    else if (file_count < 0)
    {
        mmi_imgview_display_popup_sg(g_imgadv_cui_gid, (UI_string_type)GetString(FMGR_FS_MEDIA_CHANGED_TEXT), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
        mmi_frm_scrn_close(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW);
        g_imgview_state = MMI_IMGVIEW_STATE_EXIT;
        return;
    }
    else if (file_count == 0)
    {
        mmi_imgview_display_popup_sg(g_imgadv_cui_gid, (UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
        mmi_frm_scrn_close(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW);
        g_imgview_state = MMI_IMGVIEW_STATE_EXIT;
        return;
    }
}


#if defined(__MMI_GESTURES_FRAMEWORK__) && defined( __MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_view_next_image_gesture_hdlr
 * DESCRIPTION
 *  This function handles "->" gesture event
 * PARAMETERS
 *  mmi_frm_gesture_event_enum
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_view_next_image_gesture_hdlr (mmi_frm_gesture_event_enum gesture_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        if (gesture_event != MMI_FRM_GESTURE_UP)
            return;
    }
    else if(g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_0)
    {
        if (gesture_event != MMI_FRM_GESTURE_LEFT)
            return;
    }
    else
    {
        return;
    }
    if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
    {
        return;
    }
    mmi_imgadv_cancel_decode_timer();
    g_imgadv_cntx.active_osd_layout_ptr->rarrow.is_press = TRUE;
    mmi_imgadv_next_image_release();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_view_previous_image_gesture_hdlr
 * DESCRIPTION
 *  This function handles "<-" gesture event
 * PARAMETERS
 *  mmi_frm_gesture_event_enum
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_view_previous_image_gesture_hdlr (mmi_frm_gesture_event_enum gesture_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        if (gesture_event != MMI_FRM_GESTURE_DOWN)
            return;
    }
    else if(g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_0)
    {
        if (gesture_event != MMI_FRM_GESTURE_RIGHT)
            return;
    }
    else
    {
        return;
    }
    if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
    {
        return;
    }
    mmi_imgadv_cancel_decode_timer();
    g_imgadv_cntx.active_osd_layout_ptr->larrow.is_press = TRUE;
    mmi_imgadv_previous_image_release();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_cwr_image_gesture_hdlr
 * DESCRIPTION
 *  This function handles "clockwise" gesture event
 * PARAMETERS
 *  mmi_frm_gesture_event_enum
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_cwr_image_gesture_hdlr (mmi_frm_gesture_event_enum gesture_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gesture_event != MMI_FRM_GESTURE_CLOCKWISE)
    {
        return;
    }
    if (g_imgadv_cntx.imgview_rotate != GDI_LCD_LAYER_ROTATE_0)
    {
        return;
    }
    if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
    {
        return;
    }
    mmi_imgadv_cancel_decode_timer();
    mmi_imgadv_rotate_release();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_ccwr_image_gesture_hdlr
 * DESCRIPTION
 *  This function handles "counter-clockwise" gesture event
 * PARAMETERS
 *  mmi_frm_gesture_event_enum
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_ccwr_image_gesture_hdlr (mmi_frm_gesture_event_enum gesture_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gesture_event != MMI_FRM_GESTURE_ANTICLOCKWISE)
    {
        return;
    }
    if (g_imgadv_cntx.imgview_rotate != GDI_LCD_LAYER_ROTATE_270)
    {
        return;
    }
    if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
    {
        return;
    }
    mmi_imgadv_cancel_decode_timer();
    mmi_imgadv_rotate_release();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_init_default_touch_and_key_handler
 * DESCRIPTION
 *  init key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_init_default_touch_and_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_TOUCH_SCREEN__
    /* register pen down/up/move event */
    wgui_register_pen_down_handler(mmi_imgadv_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_imgadv_pen_up_hdlr);
    #ifdef __MTK_TARGET__
    wgui_register_pen_abort_handler(mmi_imgadv_pen_abort_hdlr);
    #endif
    wgui_register_pen_move_handler(mmi_imgadv_pen_move_hdlr);
#if defined(__MMI_GESTURES_FRAMEWORK__)
    if (!g_imgadv_cntx.is_external_req)
    {
        if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
        {
            mmi_frm_gesture_listen_event(MMI_FRM_GESTURE_DOWN, mmi_imgadv_view_previous_image_gesture_hdlr);
            mmi_frm_gesture_listen_event(MMI_FRM_GESTURE_UP, mmi_imgadv_view_next_image_gesture_hdlr);
        }
        else
        {
            mmi_frm_gesture_listen_event(MMI_FRM_GESTURE_RIGHT, mmi_imgadv_view_previous_image_gesture_hdlr);
            mmi_frm_gesture_listen_event(MMI_FRM_GESTURE_LEFT, mmi_imgadv_view_next_image_gesture_hdlr);
        }
    }
    mmi_frm_gesture_listen_event(MMI_FRM_GESTURE_CLOCKWISE, mmi_imgadv_cwr_image_gesture_hdlr);
    mmi_frm_gesture_listen_event(MMI_FRM_GESTURE_ANTICLOCKWISE, mmi_imgadv_ccwr_image_gesture_hdlr);
#endif
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* if less or equal to 1 image, no need to switch to next image */
    if (!g_imgadv_cntx.is_external_req)
    {
        SetKeyHandler(mmi_imgadv_next_image_press, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_imgadv_previous_image_press, KEY_VOL_UP, KEY_EVENT_DOWN);

        SetKeyHandler(mmi_imgadv_next_image_release, KEY_VOL_DOWN, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_previous_image_release, KEY_VOL_UP, KEY_EVENT_UP);
    }
    SetKeyHandler(mmi_imgadv_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgadv_lsk_release, KEY_LSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_imgadv_rsk_press, KEY_RSK, KEY_EVENT_DOWN); 
    SetKeyHandler(mmi_imgadv_rsk_release, KEY_RSK, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_init_external_key_handler
 * DESCRIPTION
 *  init key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_init_external_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_KEY);    

    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
        {
            SetKeyHandler(mmi_imgadv_move_down_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_left_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_up_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_right_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

            SetKeyHandler(mmi_imgadv_move_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        }
        SetKeyHandler(mmi_imgadv_rsk_press, KEY_RSK, KEY_EVENT_DOWN); 
        SetKeyHandler(mmi_imgadv_rsk_release, KEY_RSK, KEY_EVENT_UP);
    }
    else
    {
        if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
        {
            SetKeyHandler(mmi_imgadv_move_down_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_left_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_up_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_right_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

            SetKeyHandler(mmi_imgadv_move_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        }
        SetKeyHandler(mmi_imgadv_rsk_press, KEY_RSK, KEY_EVENT_DOWN); 
        SetKeyHandler(mmi_imgadv_rsk_release, KEY_RSK, KEY_EVENT_UP);
    }

    SetKeyHandler(mmi_imgadv_zoomin_press, KEY_1, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgadv_zoomout_press, KEY_2, KEY_EVENT_DOWN);
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    SetKeyHandler(mmi_imgadv_dummy, KEY_1, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(mmi_imgadv_dummy, KEY_1, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_imgadv_dummy, KEY_2, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(mmi_imgadv_dummy, KEY_2, KEY_EVENT_REPEAT);
#endif
    
    SetKeyHandler(mmi_imgadv_zoomin_release, KEY_1, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgadv_zoomout_release, KEY_2, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgadv_rotate_press, KEY_3, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgadv_rotate_release, KEY_3, KEY_EVENT_UP);

    SetKeyHandler(mmi_imgadv_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgadv_lsk_release, KEY_LSK, KEY_EVENT_UP);
}
#endif /* KEY_PEN_EVENT */


#ifndef OPERATION
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_start_decode
 * DESCRIPTION
 *  This function start decode the current image.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_start_decode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cntx.is_real_decode = MMI_TRUE;
   
    mmi_imgadv_extract_image_to_cache_layer();

    if (g_imgadv_cntx.result >= MMI_IMGADV_OK)
    {
        mmi_imgadv_extract_image_to_thumbnail_layer();
#if !defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
        mmi_imgadv_init_key_handler();
        g_imgadv_cntx.is_initialized = TRUE;
#endif        

    }
    else
    {
        /* after popup display, so gobackhistory */
        return;
    }

#ifdef __MMI_TVOUT__
    mmi_imgadv_tvout_decode();
    /* if tvout is not enable, stop lcd sleep */
    if (mdi_tvout_is_enable())
    {
        /* tv out is on, do not let tv to sleep in when lcd sleep in */
        mmi_phnset_tvout_disable_tv_sleep_in();
        mmi_phnset_disable_partial_ss();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_translate
 * DESCRIPTION
 *  This function is called when user move the left-up point of the view port to offset x and y
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_translate(S32 x, S32 y)
{
    S32 movement_x, movement_y;
    movement_x = x;
    movement_y = y;

    //mmi_imgadv_reset_osd_fade(MMI_TRUE);
    
    g_imgadv_cntx.map.wnd_offset_x += movement_x;
    g_imgadv_cntx.map.wnd_offset_y += movement_y;

    if (g_imgadv_cntx.map.wnd_offset_x < 0)
        g_imgadv_cntx.map.wnd_offset_x = 0;
    else if (g_imgadv_cntx.map.wnd_offset_x + g_imgadv_cntx.map.wnd_width > g_imgadv_cntx.map.width)
        g_imgadv_cntx.map.wnd_offset_x = g_imgadv_cntx.map.width - g_imgadv_cntx.map.wnd_width ;

    if (g_imgadv_cntx.map.wnd_offset_y < 0)
        g_imgadv_cntx.map.wnd_offset_y = 0;
    else if (g_imgadv_cntx.map.wnd_offset_y + g_imgadv_cntx.map.wnd_height > g_imgadv_cntx.map.height)
        g_imgadv_cntx.map.wnd_offset_y = g_imgadv_cntx.map.height - g_imgadv_cntx.map.wnd_height ;

    if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG ||
         g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG_FILE )
        gdi_anim_stop_all_by_layer(g_imgadv_cntx.cache_layer_handle);

    {
        S32 src_x, src_y, src_width, src_height;
        S32 dest_x = 0, dest_y = 0, dest_width, dest_height;
        
        src_x = g_imgadv_cntx.map.wnd_offset_x * g_imgadv_cntx.map.ratio_map_to_thumbnail;
        src_y = g_imgadv_cntx.map.wnd_offset_y * g_imgadv_cntx.map.ratio_map_to_thumbnail;
        src_width = g_imgadv_cntx.map.wnd_width * g_imgadv_cntx.map.ratio_map_to_thumbnail;
        src_height = g_imgadv_cntx.map.wnd_height * g_imgadv_cntx.map.ratio_map_to_thumbnail;

        /**********************************************************************************
         * check if src_width2/src_height2 > original size.
         **********************************************************************************/
        if (src_width > g_imgadv_cntx.thumbnail_layer_width)
            src_width = g_imgadv_cntx.thumbnail_layer_width;

        if (src_height > g_imgadv_cntx.thumbnail_layer_height)
            src_height = g_imgadv_cntx.thumbnail_layer_height;

        if (src_x + src_width > g_imgadv_cntx.thumbnail_layer_width)
            src_x = g_imgadv_cntx.thumbnail_layer_width - src_width;

        if (src_y + src_height > g_imgadv_cntx.thumbnail_layer_height)
            src_y = g_imgadv_cntx.thumbnail_layer_height - src_height;

        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_get_dimension(&dest_width, &dest_height);

        gdi_bitblt_resized(
            g_imgadv_cntx.thumbnail_layer_handle,
            src_x,
            src_y,
            src_x + src_width - 1,
            src_y + src_height - 1,
            dest_x,
            dest_y,
            dest_x + dest_width - 1,
            dest_y + dest_height - 1);
        
        gdi_layer_pop_and_restore_active();
    }    
    mmi_imgadv_draw_map();
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();    
}


static BOOL mmi_imgadv_validate_drm_right(void)
{
#if defined(__DRM_SUPPORT__)
    if(g_imgadv_cntx.result != MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR
       && g_imgadv_cntx.is_err_displayed == FALSE)
    {
        g_imgadv_cntx.result = MMI_IMGADV_DRM_INVALID;

        if (g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_EXIT)
        {
            g_imgadv_cntx.drm_valid = mmi_imgadv_process_drm_hdlr();

            /* ERROR HAPPENED */
            if ((g_imgadv_cntx.drm_valid & IMGADV_DRM_DRM_FILE)==0)
            {
                g_imgadv_cntx.result = MMI_IMGADV_OK;
                g_imgadv_cntx.drm_valid |= IMGADV_DRM_PRINT_VALID;
            }
            else if (((IMGADV_DRM_MULTI_PART & g_imgadv_cntx.drm_valid)!=0))
            {
                /* MULTI-PART */
                g_imgadv_cntx.result = MMI_IMGADV_DRM_INVALID; 
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_IMGVIEW_NOTIFY_MULTIPART_NOT_SUPPORT);
            }
            else if ((IMGADV_DRM_DISPLAY_VALID & g_imgadv_cntx.drm_valid)==0)
            {
                /* DISPLAY PERMISSIONT DENINED */
                g_imgadv_cntx.result = MMI_IMGADV_DRM_INVALID; 
                g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_DRM_PROHIBITED);
            }
            else 
                g_imgadv_cntx.result = MMI_IMGADV_OK;
        }
        else if (g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_PAUSE)
        {

            /* check print right again */
            if (DRM_get_object_method(NULL,(PU16) g_imgadv_cntx.filepath) != DRM_METHOD_NONE)
            {
                if (!DRM_validate_permission(NULL, (PU16)g_imgadv_cntx.filepath, DRM_PERMISSION_PRINT))
                {
                    g_imgadv_cntx.drm_valid&= ~(IMGADV_DRM_PRINT_VALID);
                }
            }            

            /* if DRM State in PAUSE, Consume DRM Right */
            DRM_resume_consume(g_imgadv_cntx.drm_id);
            g_imgadv_cntx.result = MMI_IMGADV_OK;
            g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_CONSUME;

            DRM_close_file(g_imgadv_cntx.drm_handle);
            g_imgadv_cntx.drm_handle = NULL;
        }
        else
        {
            /* should not go into this section */
            ASSERT(0);
        }

    }
#else /* __DRM_SUPPORT__ */ 
    g_imgadv_cntx.result = MMI_IMGADV_OK;
#endif /* __DRM_SUPPORT__ */ 

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_anim_finished_callback
 * DESCRIPTION
 *  animation finished decode done callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_anim_finished_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < GDI_SUCCEED)
    {
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
        gdi_lcd_repaint_all();

        if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
        {
            if (result == GDI_JPEG_ERR_IMAGE_TOO_LARGE)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE);
            }
            else if (result == GDI_JPEG_ERR_FILE_FORMAT_WRONG)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_INVALID_FORMAT);
            }
            else if (result == GDI_JPEG_ERR_DECODE_TIME_OUT)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE);
            }
            else if (result == GDI_IMAGE_ERR_INVALID_IMG_TYPE)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_INVALID_FORMAT);
            }
            /*else if (result == GDI_IMAGE_ERR_UNSUPPORTED_FORMAT)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_UNSUPPORTED_FORMAT);
            }*/
            else
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_INVALID_FORMAT);
            }
        }
        else
        {
            if (result == GDI_JPEG_ERR_IMAGE_TOO_LARGE)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE);
            }
            else if (result == GDI_JPEG_ERR_FILE_FORMAT_WRONG)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_INVALID_FORMAT);
            }
            else
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE);
        }


        if (g_imgadv_cntx.map.zoom_factor_cnt+1 <= 1)
        {
            g_imgadv_cntx.map.zoom_factor_cnt = 0;
            g_imgadv_cntx.result = MMI_IMGADV_FIRST_TIME_DECODE_ERR;
            g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
            g_imgadv_cntx.map.is_zoomout_able = MMI_FALSE;
        }
        else
        {
            g_imgadv_cntx.result = MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR;  
            g_imgadv_cntx.map.zoom_factor_cnt--;
            g_imgadv_cntx.map.max_zoom_factor_cnt = g_imgadv_cntx.map.zoom_factor_cnt;
            g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;

            if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
            {
                g_imgadv_cntx.map.is_zoomout_able = MMI_TRUE;
            }
            else
            {
                g_imgadv_cntx.map.is_zoomout_able = MMI_FALSE;
            }
        }
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_RESULT, g_imgadv_cntx.result);
        g_imgadv_cntx.error_event = MMI_EVENT_FAILURE;
        {
            FS_HANDLE  fs_handler;
            fs_handler = FS_Open((PU16) g_imgadv_cntx.filepath, FS_READ_ONLY);
            if (fs_handler < FS_NO_ERROR)
            {
                g_imgadv_cntx.result = MMI_IMGADV_ERROR;
                g_imgadv_cntx.err_str_ptr = GetString((U16)srv_fmgr_fs_error_get_string(fs_handler));
                g_imgadv_cntx.error_event = srv_fmgr_fs_error_get_popup_type(fs_handler);
            }
            else
            {
                FS_Close(fs_handler);
            }
        }
        mmi_imgadv_display_error_sg(g_imgadv_cui_gid, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_extract_image_to_cache_layer
 * DESCRIPTION
 *  This function extract image to cache layer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_extract_image_to_cache_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    GDI_RESULT gdi_handle_result = GDI_SUCCEED;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_DECODE);
    gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);

    /* reset decode_timer */
    if(g_imgadv_cntx.is_decode_timer_on == TRUE)
    {
        g_imgadv_cntx.is_decode_timer_on = FALSE;
        gui_cancel_timer(mmi_imgadv_extract_image_to_cache_layer);
    }

    /* clear gdi working buffer */
    gdi_image_clear_work_buffer();

#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_nb_set_done_callback(mmi_imgadv_decode_done_callback);
    gdi_nb_set_blt(MMI_FALSE,MMI_FALSE);
#endif

    if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
    {
        S32 offset_x = 0;
        S32 offset_y = 0;

        if (g_imgadv_cntx.cache_layer_width> g_imgadv_cntx.resized_img_width)
        {
            offset_x = (g_imgadv_cntx.cache_layer_width - g_imgadv_cntx.resized_img_width) >> 1;
        }

        if (g_imgadv_cntx.cache_layer_height > g_imgadv_cntx.resized_img_height)
        {
            offset_y = (g_imgadv_cntx.cache_layer_height - g_imgadv_cntx.resized_img_height) >> 1;
        }

        switch (g_imgadv_cntx.image_type)
        {
            case GDI_IMAGE_TYPE_GIF:
            case GDI_IMAGE_TYPE_GIF_FILE:
            case GDI_IMAGE_TYPE_SVG:
            case GDI_IMAGE_TYPE_SVG_FILE:
            case GDI_IMAGE_TYPE_M3D:
            case GDI_IMAGE_TYPE_M3D_FILE:
                if (g_imgadv_cntx.image_type != GDI_IMAGE_TYPE_SVG && 
                    g_imgadv_cntx.image_type != GDI_IMAGE_TYPE_SVG_FILE)
                {
                    g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
                    g_imgadv_cntx.map.is_zoomout_able = MMI_FALSE;
                }
                
                #ifdef __MMI_TVOUT__
                if (mdi_tvout_is_enable())
                {
                    if ( g_imgadv_cntx.is_initialized == FALSE )
                    {
                        S32 tvout_width = (g_imgadv_cntx.resized_img_width > 1) ? g_imgadv_cntx.resized_img_width : 2;
                        S32 tvout_height = (g_imgadv_cntx.resized_img_height > 1) ? g_imgadv_cntx.resized_img_height : 2;

                        /* set mode to owner draw */
                        /*
                        *  check if tvout_resized_width % 2 == 0 
                        *  for all chips, tvout_buffer_width must be 2x.
                        */
                        if (tvout_width % 2 != 0)
                            tvout_width+=1;

                        mdi_tvout_set_mode(
                            MDI_TV_MODE_OWNER_DRAW,
                            tvout_width,
                            tvout_height);
                        
                        g_imgadv_cntx.tvout_width = tvout_width;
                        gdi_anim_set_draw_after_callback(mmi_imgadv_anim_callback);
                    }  
                }
                #endif
                gdi_layer_clear(GDI_COLOR_BLACK);
                #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
                    g_imgadv_cntx.is_decoding = MMI_TRUE;
                    gdi_nb_set_anim_last_frame_callback(mmi_imgadv_anim_finished_callback);
                    g_imgadv_cntx.nb_handle = gdi_anim_nb_draw_resized_file(
                                                offset_x,
                                                offset_y,
                                                g_imgadv_cntx.resized_img_width,
                                                g_imgadv_cntx.resized_img_height,
                                                g_imgadv_cntx.filepath);                    
                #else
                    {
                    gdi_anim_set_last_frame_callback(mmi_imgadv_anim_finished_callback);
                    gdi_handle_result = gdi_anim_draw_file_resized(
                                    offset_x,
                                    offset_y,
                                    g_imgadv_cntx.resized_img_width,
                                    g_imgadv_cntx.resized_img_height,
                                    g_imgadv_cntx.filepath,
                                    NULL);
                    }
                #endif
            break;
            case GDI_IMAGE_TYPE_PNG:
            case GDI_IMAGE_TYPE_PNG_FILE:
                gdi_push_and_set_alpha_blending_source_layer(g_imgadv_cntx.cache_layer_handle);

                gdi_layer_clear(GDI_COLOR_BLACK);
                #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
                    g_imgadv_cntx.is_decoding = MMI_TRUE;
                    g_imgadv_cntx.nb_handle = gdi_image_nb_draw_resized_file(
                                                offset_x,
                                                offset_y,
                                                g_imgadv_cntx.resized_img_width,
                                                g_imgadv_cntx.resized_img_height,
                                                g_imgadv_cntx.filepath);                    
                #else
                    gdi_handle_result = gdi_image_draw_resized_file(
                                    offset_x,
                                    offset_y,
                                    g_imgadv_cntx.resized_img_width,
                                    g_imgadv_cntx.resized_img_height,
                                    g_imgadv_cntx.filepath);
                    
                #endif

                gdi_pop_and_restore_alpha_blending_source_layer();

                break;
            default:
                gdi_layer_clear(GDI_COLOR_BLACK);
                #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
                    g_imgadv_cntx.is_decoding = MMI_TRUE;
                    g_imgadv_cntx.nb_handle = gdi_image_nb_draw_resized_file(
                                                offset_x,
                                                offset_y,
                                                g_imgadv_cntx.resized_img_width,
                                                g_imgadv_cntx.resized_img_height,
                                                g_imgadv_cntx.filepath);                    
                #else
                    gdi_handle_result = gdi_image_draw_resized_file(
                                    offset_x,
                                    offset_y,
                                    g_imgadv_cntx.resized_img_width,
                                    g_imgadv_cntx.resized_img_height,
                                    g_imgadv_cntx.filepath);
                    
                #endif
            break;                                
        }
    }
    else
    {
        S32 offset_x = g_imgadv_cntx.map.wnd_offset_x * g_imgadv_cntx.map.ratio_map_to_resized_image;
        S32 offset_y = g_imgadv_cntx.map.wnd_offset_y * g_imgadv_cntx.map.ratio_map_to_resized_image;
        S32 wnd_width = g_imgadv_cntx.map.wnd_width * g_imgadv_cntx.map.ratio_map_to_resized_image;
        S32 wnd_height = g_imgadv_cntx.map.wnd_height * g_imgadv_cntx.map.ratio_map_to_resized_image; 

        if ( offset_x + wnd_width > g_imgadv_cntx.resized_img_width )
            offset_x = g_imgadv_cntx.resized_img_width - wnd_width;

        if ( offset_y + wnd_height > g_imgadv_cntx.resized_img_height )
            offset_y = g_imgadv_cntx.resized_img_height - wnd_height;

        if (GDI_LCD_LAYER_ROTATE_0 == g_imgadv_cntx.imgview_rotate)
        {
            if (g_imgadv_cntx.map.wnd_offset_x != 0)
            {
                offset_x += (wnd_width-LCD_WIDTH);
            }
            if (g_imgadv_cntx.map.wnd_offset_y != 0)
            {
                offset_y += (wnd_height-LCD_HEIGHT);
            }
            wnd_width = LCD_WIDTH;
            wnd_height = LCD_HEIGHT;
        }
        else if (GDI_LCD_LAYER_ROTATE_270 == g_imgadv_cntx.imgview_rotate)
        {
            if (g_imgadv_cntx.map.wnd_offset_x != 0)
            {
                offset_x += (wnd_width-LCD_HEIGHT);
            }
            if (g_imgadv_cntx.map.wnd_offset_y != 0)
            {
                offset_y += (wnd_height-LCD_WIDTH);
            }
            wnd_width = LCD_HEIGHT;
            wnd_height = LCD_WIDTH;
        }

        /* check for some special case */
        if (g_imgadv_cntx.map.wnd_offset_y + g_imgadv_cntx.map.wnd_height == g_imgadv_cntx.map.height)
            offset_y = g_imgadv_cntx.resized_img_height - wnd_height;
        if (g_imgadv_cntx.map.wnd_offset_x + g_imgadv_cntx.map.wnd_width == g_imgadv_cntx.map.width)
            offset_x = g_imgadv_cntx.resized_img_width - wnd_width;           


        /******************************************************
         * check to prevent offset_x, offset_y to be invalid
         ******************************************************/
        if (offset_y < 0)
            offset_y = 0;

        if (offset_x < 0)
            offset_x = 0;

        switch (g_imgadv_cntx.image_type)
        {
            case GDI_IMAGE_TYPE_SVG:
            case GDI_IMAGE_TYPE_SVG_FILE:
                gdi_anim_stop_all_by_layer(g_imgadv_cntx.cache_layer_handle);
                #ifdef __MMI_TVOUT__
                if (mdi_tvout_is_enable())
                {
                    S32 tvout_width = (g_imgadv_cntx.cache_layer_width> 1) ? g_imgadv_cntx.cache_layer_width: 2;
                    S32 tvout_height = (g_imgadv_cntx.cache_layer_height> 1) ? g_imgadv_cntx.cache_layer_height: 2;

                    /* set mode to owner draw */
                    /*
                    *  check if tvout_resized_width % 2 == 0 
                    *  for all chips, tvout_buffer_width must be 2x.
                    */
                    if (tvout_width % 2 != 0)
                        tvout_width+=1;

                    mdi_tvout_set_mode(
                        MDI_TV_MODE_OWNER_DRAW,
                        tvout_width,
                        tvout_height);

                    g_imgadv_cntx.tvout_width = tvout_width;
                }
                #endif

                gdi_layer_clear(GDI_COLOR_BLACK);

                #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
                    g_imgadv_cntx.is_decoding = MMI_TRUE;                
                    g_imgadv_cntx.nb_handle = gdi_anim_nb_draw_resized_file(
                                                -offset_x,
                                                -offset_y,
                                                g_imgadv_cntx.resized_img_width,
                                                g_imgadv_cntx.resized_img_height,
                                                g_imgadv_cntx.filepath);                    
                #else
                    gdi_handle_result = gdi_anim_draw_file_resized(
                                            -offset_x,
                                            -offset_y,
                                            g_imgadv_cntx.resized_img_width,
                                            g_imgadv_cntx.resized_img_height,
                                            g_imgadv_cntx.filepath,
                                            NULL);
                #endif
                break;
            case GDI_IMAGE_TYPE_PNG:
            case GDI_IMAGE_TYPE_PNG_FILE:
                gdi_push_and_set_alpha_blending_source_layer(g_imgadv_cntx.cache_layer_handle);

                gdi_layer_clear(GDI_COLOR_BLACK);					 	

                #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
                    g_imgadv_cntx.is_decoding = MMI_TRUE;
                    g_imgadv_cntx.nb_handle = gdi_image_nb_draw_resized_file(
                                                -offset_x,
                                                -offset_y,
                                                g_imgadv_cntx.resized_img_width,
                                                g_imgadv_cntx.resized_img_height,
                                                g_imgadv_cntx.filepath);                    
                #else
                    gdi_handle_result = gdi_image_draw_resized_file(
                                    -offset_x,
                                    -offset_y,
                                    g_imgadv_cntx.resized_img_width,
                                    g_imgadv_cntx.resized_img_height,
                                    g_imgadv_cntx.filepath);
                #endif

                gdi_pop_and_restore_alpha_blending_source_layer();

                break;

            case GDI_IMAGE_TYPE_JPG:
            case GDI_IMAGE_TYPE_JPG_FILE:
            default:
                gdi_layer_clear(GDI_COLOR_BLACK);					 	

                #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
                    g_imgadv_cntx.is_decoding = MMI_TRUE;
                    g_imgadv_cntx.nb_handle = gdi_image_nb_draw_resized_file(
                                                -offset_x,
                                                -offset_y,
                                                g_imgadv_cntx.resized_img_width,
                                                g_imgadv_cntx.resized_img_height,
                                                g_imgadv_cntx.filepath);                    
                #else
                    gdi_handle_result = gdi_image_draw_resized_file(
                                    -offset_x,
                                    -offset_y,
                                    g_imgadv_cntx.resized_img_width,
                                    g_imgadv_cntx.resized_img_height,
                                    g_imgadv_cntx.filepath);
                #endif
                break;
        }

    }

    gdi_layer_pop_and_restore_active();
    g_imgadv_cntx.result = MMI_IMGADV_OK;

#if !defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_GDI_HANDLE_RESULT, gdi_handle_result);
#endif
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_RESULT, g_imgadv_cntx.result);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_IS_ERR_DISP, g_imgadv_cntx.is_err_displayed);
#if !defined(__MMI_IMGADV_NONBLOCKING_DECODE__)

    #ifdef __DRM_SUPPORT__
    if (gdi_handle_result == GDI_SUCCEED && g_imgadv_cntx.is_resume != TRUE && g_imgadv_cntx.drm_handle != NULL)
    {
        g_imgadv_cntx.drm_id = 
            DRM_consume_rights(g_imgadv_cntx.drm_handle, DRM_PERMISSION_DISPLAY, mmi_imgadv_drm_callback_hdlr);
        g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_CONSUME;

        DRM_close_file(g_imgadv_cntx.drm_handle);
        g_imgadv_cntx.drm_handle = NULL;
    }
    #endif

    if (gdi_handle_result != GDI_SUCCEED && 
        (( g_imgadv_cntx.is_err_displayed == TRUE) && 
           g_imgadv_cntx.result != MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR))
    {
        g_imgadv_cntx.result = MMI_IMGADV_ERROR;
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
        mmi_imgadv_reset_osd_fade(MMI_TRUE);
        return;
    }
    else if (gdi_handle_result != GDI_SUCCEED)
    {
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
        gdi_lcd_repaint_all();

        if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
        {
            if (gdi_handle_result == GDI_JPEG_ERR_IMAGE_TOO_LARGE)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE);
            }
            else if (gdi_handle_result == GDI_JPEG_ERR_FILE_FORMAT_WRONG)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_INVALID_FORMAT);
            }
            else if (gdi_handle_result == GDI_JPEG_ERR_DECODE_TIME_OUT)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE);
            }
            else if (gdi_handle_result == GDI_IMAGE_ERR_INVALID_IMG_TYPE)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_INVALID_FORMAT);
            }
            else if (gdi_handle_result == GDI_IMAGE_ERR_UNSUPPORTED_FORMAT)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_UNSUPPORTED_FORMAT);
            }
            else
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_INVALID_FORMAT);
            }
        }
        else
        {
            if (gdi_handle_result == GDI_JPEG_ERR_IMAGE_TOO_LARGE)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE);
            }
            else if (gdi_handle_result == GDI_JPEG_ERR_FILE_FORMAT_WRONG)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_INVALID_FORMAT);
            }
            else
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE);
        }


        if (g_imgadv_cntx.map.zoom_factor_cnt+1 <= 1)
        {
            g_imgadv_cntx.map.zoom_factor_cnt = 0;
            g_imgadv_cntx.result = MMI_IMGADV_FIRST_TIME_DECODE_ERR;
            g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
            g_imgadv_cntx.map.is_zoomout_able = MMI_FALSE;
        }
        else
        {
            g_imgadv_cntx.result = MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR;  
            g_imgadv_cntx.map.zoom_factor_cnt--;
            g_imgadv_cntx.map.max_zoom_factor_cnt = g_imgadv_cntx.map.zoom_factor_cnt;
            g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;

            if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
            {
                g_imgadv_cntx.map.is_zoomout_able = MMI_TRUE;
            }
            else
            {
                g_imgadv_cntx.map.is_zoomout_able = MMI_FALSE;
            }
        }
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_RESULT, g_imgadv_cntx.result);
        g_imgadv_cntx.error_event = MMI_EVENT_FAILURE;
        mmi_imgadv_display_error_sg(g_imgadv_cui_gid, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
        return;
    }
    else
    {
        if (g_imgadv_cntx.image_type != GDI_IMAGE_TYPE_GIF && 
            g_imgadv_cntx.image_type != GDI_IMAGE_TYPE_GIF_FILE &&
            g_imgadv_cntx.image_type != GDI_IMAGE_TYPE_M3D &&
            g_imgadv_cntx.image_type != GDI_IMAGE_TYPE_M3D_FILE)
        {
			if (g_imgadv_cntx.map.zoom_factor_cnt != 0)
			{
				g_imgadv_cntx.map.zoom_factor = 1.25;
			}

            if (g_imgadv_cntx.map.zoom_factor_cnt >= g_imgadv_cntx.map.max_zoom_factor_cnt ||
                g_imgadv_cntx.image_height < g_imgadv_cntx.cache_layer_height || 
                g_imgadv_cntx.image_width < g_imgadv_cntx.cache_layer_width ||
                g_imgadv_cntx.map.ratio_map_to_image <= 0 ||
                g_imgadv_cntx.map.width <= 0 || 
                g_imgadv_cntx.map.height <= 0)
            {
                g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
            }
            else if ( (g_imgadv_cntx.resized_img_width * g_imgadv_cntx.map.zoom_factor > g_imgadv_cntx.image_width) ||
                 (g_imgadv_cntx.resized_img_height * g_imgadv_cntx.map.zoom_factor > g_imgadv_cntx.image_height))
            {
                g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
                g_imgadv_cntx.map.max_zoom_factor_cnt = g_imgadv_cntx.map.zoom_factor_cnt;
            }
            else
            {
                if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
                {
                    float tmp_ratio;
                
                    tmp_ratio = (float)g_imgadv_cntx.cache_layer_height/ g_imgadv_cntx.resized_img_height;
                    if (g_imgadv_cntx.map.zoom_factor  < tmp_ratio)
                    {
                        g_imgadv_cntx.map.zoom_factor  = tmp_ratio;
                    }

                    tmp_ratio = (float)g_imgadv_cntx.cache_layer_width / g_imgadv_cntx.resized_img_width;
                    if (g_imgadv_cntx.map.zoom_factor  < tmp_ratio)
                    {
                        g_imgadv_cntx.map.zoom_factor  = tmp_ratio;
                    }
                }
                
                if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_JPG||
                    g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_JPG_FILE)
                {
                    if (g_imgadv_cntx.resized_img_width * g_imgadv_cntx.map.zoom_factor < 4095 &&
                        g_imgadv_cntx.resized_img_height * g_imgadv_cntx.map.zoom_factor < 4095)
                    {
                        g_imgadv_cntx.map.is_zoomin_able = MMI_TRUE;
                    }
                    else
                    {
                        g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
                    }
                }
                else if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_PNG||
                    g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_PNG_FILE)
                 {
                    if (g_imgadv_cntx.resized_img_width * g_imgadv_cntx.map.zoom_factor < 2047 &&
                        g_imgadv_cntx.resized_img_height * g_imgadv_cntx.map.zoom_factor < 4096)
                    {
                        g_imgadv_cntx.map.is_zoomin_able = MMI_TRUE;
                    }
                    else
                    {
                        g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
                    }
                }
                else
                {
                    g_imgadv_cntx.map.is_zoomin_able = MMI_TRUE;
                }
                g_imgadv_cntx.map.zoom_factor = 1.25;
            }
        #ifdef __MMI_TVOUT__
            if (mdi_tvout_is_enable() && 
                (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG ||
                 g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG_FILE))
            {
                g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
                g_imgadv_cntx.map.zoom_factor_cnt = 0;            
            }
        #endif      
        }
        else
        {
            g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
            g_imgadv_cntx.map.zoom_factor_cnt = 0;
            
        }
        /* CUI control part, user can reset it */
        if (g_imgview_cui_ptr->cap_enable[CUI_IMGVIEW_CAP_ZOOM] == MMI_FALSE)
        {
            g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
        }
        
        if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
        {
            g_imgadv_cntx.map.is_zoomout_able = MMI_TRUE;
        }
        else
        {
            g_imgadv_cntx.map.is_zoomout_able = MMI_FALSE;
        }
        if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_JPG ||
            g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_JPG_FILE)
        {
            if (mmi_imgadv_check_jpg_resizer_limitation())
            {
                g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
            }
        }
        mmi_imgadv_init_key_handler();
        mmi_imgadv_init_default_touch_and_key_handler();
        mmi_imgadv_draw_osd();
        gdi_lcd_repaint_all();
    }
    if (g_imgadv_cntx.active_osd_layout_ptr->rarrow.is_press == FALSE
        && g_imgadv_cntx.active_osd_layout_ptr->larrow.is_press == FALSE
        && g_imgadv_cntx.active_osd_layout_ptr->rotate.is_press == FALSE
        && g_imgadv_cntx.active_osd_layout_ptr->zoomin.is_press == FALSE
        && g_imgadv_cntx.active_osd_layout_ptr->zoomout.is_press == FALSE
        && g_imgadv_cntx.lsk.is_press == FALSE
        && g_imgadv_cntx.rsk.is_press == FALSE)
    {
        mmi_imgadv_osd_fade_cyclic();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_extract_image_to_thumbnail_layer
 * DESCRIPTION
 *  This function extract image to thumbnail layer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_extract_image_to_thumbnail_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_EXTRACT_THUM);
    
    if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_M3D ||
        g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_M3D_FILE ||
        g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_GIF ||
        g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_GIF_FILE)
        return;

    if (g_imgadv_cntx.is_resume == TRUE)
    {
        if (g_imgadv_cntx.image_type != GDI_IMAGE_TYPE_SVG &&
            g_imgadv_cntx.image_type != GDI_IMAGE_TYPE_SVG_FILE )
        {
            gdi_layer_push_and_set_active(g_imgadv_cntx.thumbnail_layer_handle);
            gdi_push_and_set_alpha_blending_source_layer(g_imgadv_cntx.thumbnail_layer_handle);
            gdi_layer_resize(g_imgadv_cntx.thumbnail_layer_width ,g_imgadv_cntx.thumbnail_layer_height);
            gdi_image_draw_resized_file(
                0,
                0,
                g_imgadv_cntx.thumbnail_layer_width,
                g_imgadv_cntx.thumbnail_layer_height,
                g_imgadv_cntx.filepath);
            gdi_pop_and_restore_alpha_blending_source_layer();
            gdi_layer_pop_and_restore_active();
        }
    }
    else if (g_imgadv_cntx.is_resume == FALSE && 
             g_imgadv_cntx.map.zoom_factor_cnt == 0 )
    {
        PU8 src;
        PU8 dest;
        U16 src_width, src_height, src_pitch;
        S32 src_offset_x=0, src_offset_y=0;
        S32 dest_pitch, dest_offset_x, dest_offset_y;
        gdi_rect_struct dest_clip;

        if (g_imgadv_cntx.cache_layer_width> g_imgadv_cntx.resized_img_width)
        {
            src_offset_x = (g_imgadv_cntx.cache_layer_width - g_imgadv_cntx.resized_img_width) >> 1;
        }

        if (g_imgadv_cntx.cache_layer_height > g_imgadv_cntx.resized_img_height)
        {
            src_offset_y = (g_imgadv_cntx.cache_layer_height - g_imgadv_cntx.resized_img_height) >> 1;
        }

        g_imgadv_cntx.thumbnail_layer_width = g_imgadv_cntx.resized_img_width;
        g_imgadv_cntx.thumbnail_layer_height = g_imgadv_cntx.resized_img_height;

        gdi_layer_push_and_set_active(g_imgadv_cntx.thumbnail_layer_handle);
        gdi_layer_resize(g_imgadv_cntx.thumbnail_layer_width ,g_imgadv_cntx.thumbnail_layer_height);
        gdi_layer_pop_and_restore_active();

        dest = g_imgadv_cntx.thumbnail_buf_ptr;
        src = g_imgadv_cntx.cache_buf_ptr;
        src_pitch = g_imgadv_cntx.cache_layer_width;
        dest_pitch = g_imgadv_cntx.thumbnail_layer_width;
        dest_clip.x1 = 0;
        dest_clip.y1 = 0;
        dest_clip.x2 = g_imgadv_cntx.thumbnail_layer_width- 1;
        dest_clip.y2 = g_imgadv_cntx.thumbnail_layer_height - 1;
        src_width = g_imgadv_cntx.resized_img_width;
        src_height = g_imgadv_cntx.resized_img_height;
        dest_offset_x = 0;
        dest_offset_y = 0;

        /* use 2D copy from cache layer to thumbnail layer */
        gdi_2d_memory_blt_without_transpant_check(
            src,
            src_pitch,
            src_offset_x,
            src_offset_y,
            src_width,
            src_height,
            dest,
            dest_pitch,
            dest_offset_x,
            dest_offset_y,
            dest_clip,
            GDI_MAINLCD_BIT_PER_PIXEL);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_init_image_info
 * DESCRIPTION
 *  This function init image info.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_init_image_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set cache layer's width/height */
    if (GDI_LCD_LAYER_ROTATE_0 == g_imgadv_cntx.imgview_rotate)
    {
        g_imgadv_cntx.cache_layer_height = LCD_HEIGHT;
        g_imgadv_cntx.cache_layer_width = LCD_WIDTH;
        g_imgadv_cntx.map.ratio_width_to_height = (float)LCD_WIDTH/LCD_HEIGHT;
    }
    else if (GDI_LCD_LAYER_ROTATE_270 == g_imgadv_cntx.imgview_rotate)
    {
        g_imgadv_cntx.cache_layer_height = LCD_WIDTH;
        g_imgadv_cntx.cache_layer_width = LCD_HEIGHT;
        g_imgadv_cntx.map.ratio_width_to_height = (float)LCD_HEIGHT/LCD_WIDTH;
    }

    /* initialize the map */
    mmi_imgadv_init_map_box();

    /* initialize resized_img_width/resized_img_height */
    if ((g_imgadv_cntx.image_width < g_imgadv_cntx.cache_layer_width) &&
        (g_imgadv_cntx.image_height < g_imgadv_cntx.cache_layer_height))
    {
        g_imgadv_cntx.resized_img_width = g_imgadv_cntx.image_width;
        g_imgadv_cntx.resized_img_height = g_imgadv_cntx.image_height;
    }
    else
    {
        float tmp_width = (float)g_imgadv_cntx.image_width / g_imgadv_cntx.cache_layer_width;
        float tmp_height = (float)g_imgadv_cntx.image_height / g_imgadv_cntx.cache_layer_height;

        if (tmp_width == tmp_height)
        {
            g_imgadv_cntx.is_width_dominate = TRUE;
            g_imgadv_cntx.resized_img_width = g_imgadv_cntx.cache_layer_width;
            g_imgadv_cntx.resized_img_height = g_imgadv_cntx.cache_layer_height;
            g_imgadv_cntx.map.ratio_map_to_resized_image = 
            g_imgadv_cntx.map.ratio_map_to_thumbnail = 
                (float)g_imgadv_cntx.resized_img_height/ g_imgadv_cntx.map.height;            
        }
        else if (tmp_width > tmp_height)
        {
            g_imgadv_cntx.is_width_dominate = TRUE;
            g_imgadv_cntx.resized_img_height = g_imgadv_cntx.image_height / tmp_width + 0.5;
            g_imgadv_cntx.resized_img_width = g_imgadv_cntx.cache_layer_width;
            g_imgadv_cntx.map.ratio_map_to_resized_image = 
            g_imgadv_cntx.map.ratio_map_to_thumbnail = 
            (float)g_imgadv_cntx.resized_img_width/g_imgadv_cntx.map.width;            
        }
        else
        {
            g_imgadv_cntx.is_width_dominate = FALSE;
            g_imgadv_cntx.resized_img_width = g_imgadv_cntx.image_width / tmp_height + 0.5;
            g_imgadv_cntx.resized_img_height = g_imgadv_cntx.cache_layer_height;
            g_imgadv_cntx.map.ratio_map_to_resized_image = 
            g_imgadv_cntx.map.ratio_map_to_thumbnail = 
                (float)g_imgadv_cntx.resized_img_height/g_imgadv_cntx.map.height;
        }
    }

    /* check if resized_img_width/resized_img_height <= 0 */
    if (g_imgadv_cntx.resized_img_width <= 0)
    {
        g_imgadv_cntx.resized_img_width = 1;
    }

    if (g_imgadv_cntx.resized_img_height <= 0)
    {
        g_imgadv_cntx.resized_img_height = 1;
    }

    g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
    g_imgadv_cntx.map.is_zoomout_able = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_zoomin
 * DESCRIPTION
 *  zoom in function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_imgadv_zoomin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_wnd_width;
    S32 old_wnd_height;
    S32 old_wnd_offset_x;
    S32 old_wnd_offset_y;
    S32 old_resized_width;
    S32 old_resized_height;
    float old_ratio;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


#ifdef __MMI_TVOUT__
    /******************************************************************************
    * if TVOUT is enable and image_type is SVG, disable zoomin function
    ******************************************************************************/
    if (mdi_tvout_is_enable() && (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG ||
             g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG_FILE ))
            return FALSE; 
#endif /* __MMI_TVOUT__ */ 


    /******************************************************************************
    * if not initialized, also disable zoomin function
    ******************************************************************************/
    if (g_imgadv_cntx.is_initialized == FALSE || 
        g_imgadv_cntx.map.is_zoomin_able == MMI_FALSE || 
        g_imgadv_cntx.map.max_zoom_factor_cnt <= g_imgadv_cntx.map.zoom_factor_cnt)
    {
        return FALSE;
    }

    /* while it is first-time zoomin, if the image display on screen currently is small than lcd size,
       zoom to fit screen size, else zoom factor = 1.414 */
    if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
    {
        float tmp_ratio;
    
        tmp_ratio = (float)g_imgadv_cntx.cache_layer_height/ g_imgadv_cntx.resized_img_height;
        if (g_imgadv_cntx.map.zoom_factor  < tmp_ratio)
        {
            g_imgadv_cntx.map.zoom_factor  = tmp_ratio;
            g_imgadv_cntx.is_width_dominate = TRUE;
        }

        tmp_ratio = (float)g_imgadv_cntx.cache_layer_width / g_imgadv_cntx.resized_img_width;
        if (g_imgadv_cntx.map.zoom_factor  < tmp_ratio)
        {
            g_imgadv_cntx.map.zoom_factor  = tmp_ratio;
            g_imgadv_cntx.is_width_dominate = FALSE;
        }
    }
    else
    {
        if (GDI_LCD_LAYER_ROTATE_0 == g_imgadv_cntx.imgview_rotate)
        {
            g_imgadv_cntx.is_width_dominate = FALSE;
        }
        else
        {
            g_imgadv_cntx.is_width_dominate = TRUE;
        }
    }
    
    /* must put after check is_zoomin_able */
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    if (g_imgadv_cntx.is_decoding)
    {
        gdi_image_nb_stop_all();
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
#endif

    
    old_wnd_width = g_imgadv_cntx.map.wnd_width;
    old_wnd_height = g_imgadv_cntx.map.wnd_height;
    old_wnd_offset_x = g_imgadv_cntx.map.wnd_offset_x;
    old_wnd_offset_y = g_imgadv_cntx.map.wnd_offset_y;    
    old_resized_width = g_imgadv_cntx.resized_img_width;
    old_resized_height = g_imgadv_cntx.resized_img_height; 
    old_ratio = g_imgadv_cntx.map.ratio_map_to_resized_image;
    
    if (g_imgadv_cntx.is_width_dominate == TRUE)
    {
        g_imgadv_cntx.map.wnd_width = (g_imgadv_cntx.map.wnd_width / g_imgadv_cntx.map.zoom_factor + 0.5);
        g_imgadv_cntx.map.wnd_height = (g_imgadv_cntx.map.wnd_width / g_imgadv_cntx.map.ratio_width_to_height + 0.5);
    }
    else
    {
        g_imgadv_cntx.map.wnd_height = (g_imgadv_cntx.map.wnd_height / g_imgadv_cntx.map.zoom_factor + 0.5);
        g_imgadv_cntx.map.wnd_width = (g_imgadv_cntx.map.wnd_height * g_imgadv_cntx.map.ratio_width_to_height + 0.5);
    }

    /************************************************
     *  check if new wnd_width/wnd_height > old ones
     *  prevent calculate clip error 
     ************************************************/
    if (old_wnd_width < g_imgadv_cntx.map.wnd_width)
        g_imgadv_cntx.map.wnd_width = old_wnd_width;

    if (old_wnd_height < g_imgadv_cntx.map.wnd_height)
        g_imgadv_cntx.map.wnd_height = old_wnd_height;
    
    g_imgadv_cntx.map.wnd_offset_x = g_imgadv_cntx.map.wnd_offset_x + ((old_wnd_width - g_imgadv_cntx.map.wnd_width)>>1);
    g_imgadv_cntx.map.wnd_offset_y = g_imgadv_cntx.map.wnd_offset_y + ((old_wnd_height - g_imgadv_cntx.map.wnd_height)>>1);

    g_imgadv_cntx.map.zoom_factor_cnt++; 

    g_imgadv_cntx.resized_img_width = g_imgadv_cntx.resized_img_width * g_imgadv_cntx.map.zoom_factor;  //((float)(g_imgadv_cntx.map.width * g_imgadv_cntx.cache_layer_width / g_imgadv_cntx.map.wnd_width))+0.5;
    g_imgadv_cntx.resized_img_height = g_imgadv_cntx.resized_img_height * g_imgadv_cntx.map.zoom_factor;//((float)(g_imgadv_cntx.map.height * g_imgadv_cntx.cache_layer_height / g_imgadv_cntx.map.wnd_height))+0.5;

    /* In order to keep the same proportion with the image, re-calculate the resize image dimension */
    if (g_imgadv_cntx.is_width_dominate == TRUE)
    {
        g_imgadv_cntx.resized_img_height = (g_imgadv_cntx.resized_img_width * g_imgadv_cntx.image_height) / g_imgadv_cntx.image_width;

        if (g_imgadv_cntx.resized_img_height < g_imgadv_cntx.cache_layer_height)
        {
            g_imgadv_cntx.resized_img_height = g_imgadv_cntx.cache_layer_height;
            g_imgadv_cntx.resized_img_width = (g_imgadv_cntx.resized_img_height * g_imgadv_cntx.image_width) / g_imgadv_cntx.image_height;
        }
    }
    else
    {
        g_imgadv_cntx.resized_img_width = (g_imgadv_cntx.resized_img_height * g_imgadv_cntx.image_width) / g_imgadv_cntx.image_height;

        if (g_imgadv_cntx.resized_img_width < g_imgadv_cntx.cache_layer_width)
        {
            g_imgadv_cntx.resized_img_width = g_imgadv_cntx.cache_layer_width;
            g_imgadv_cntx.resized_img_height = (g_imgadv_cntx.resized_img_width * g_imgadv_cntx.image_height) / g_imgadv_cntx.image_width;
        }
    }

    g_imgadv_cntx.map.ratio_map_to_resized_image = 
                (float)g_imgadv_cntx.resized_img_width/g_imgadv_cntx.map.width;            


    if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG ||
         g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG_FILE )
        gdi_anim_stop_all_by_layer(g_imgadv_cntx.cache_layer_handle);

    mmi_imgadv_extract_image_to_cache_layer();
    if ( (g_imgadv_cntx.resized_img_width * g_imgadv_cntx.map.zoom_factor > g_imgadv_cntx.image_width) ||
       (g_imgadv_cntx.resized_img_height * g_imgadv_cntx.map.zoom_factor > g_imgadv_cntx.image_height))
    {
        g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
        g_imgadv_cntx.map.max_zoom_factor_cnt = g_imgadv_cntx.map.zoom_factor_cnt;
    }
    g_imgadv_cntx.map.zoom_factor  = 1.25;

    if (g_imgadv_cntx.result >= MMI_IMGADV_OK)
    {
        mmi_imgadv_draw_map();
        mmi_imgadv_draw_osd();
        gdi_lcd_repaint_all();
        mmi_imgadv_init_key_handler();    
    }
    else
    {
        g_imgadv_cntx.map.wnd_width = old_wnd_width;
        g_imgadv_cntx.map.wnd_height = old_wnd_height;
        g_imgadv_cntx.map.wnd_offset_x = old_wnd_offset_x;
        g_imgadv_cntx.map.wnd_offset_y = old_wnd_offset_y;
        g_imgadv_cntx.resized_img_width = old_resized_width;
        g_imgadv_cntx.resized_img_height = old_resized_height; 
        g_imgadv_cntx.map.ratio_map_to_resized_image = old_ratio;       
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_reenter
 * DESCRIPTION
 *  This function is called to draw the best fit image on the screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_reenter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cntx.map.zoom_factor_cnt = 1;
    mmi_imgadv_zoomout();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_zoomout
 * DESCRIPTION
 *  zoom out function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_imgadv_zoomout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_wnd_width;
    S32 old_wnd_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (g_imgadv_cntx.map.zoom_factor_cnt == 0 || g_imgadv_cntx.is_initialized == FALSE)
    {
        return FALSE;
    }
    else
    {
        g_imgadv_cntx.map.is_zoomin_able = MMI_TRUE;
    }
    
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    if (g_imgadv_cntx.is_decoding)
    {
        gdi_image_nb_stop_all();
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
#endif

    old_wnd_width = g_imgadv_cntx.map.wnd_width;
    old_wnd_height = g_imgadv_cntx.map.wnd_height;

    if (g_imgadv_cntx.map.zoom_factor_cnt == 1)
    {
        mmi_imgadv_init_map_box();

        /* due to init map will reset it to FALSE */
        g_imgadv_cntx.map.is_zoomin_able = MMI_TRUE;
        g_imgadv_cntx.map.is_zoomout_able = MMI_FALSE;

        mmi_imgadv_init_key_handler();

        mmi_imgadv_draw_osd();
        
        /* initialize resized_img_width/resized_img_height */
        {
            float tmp_width = (float)g_imgadv_cntx.image_width / g_imgadv_cntx.cache_layer_width;
            float tmp_height = (float)g_imgadv_cntx.image_height / g_imgadv_cntx.cache_layer_height;

            if (tmp_width == tmp_height)
            {
                g_imgadv_cntx.is_width_dominate = TRUE;
                g_imgadv_cntx.resized_img_width = g_imgadv_cntx.cache_layer_width;
                g_imgadv_cntx.resized_img_height = g_imgadv_cntx.cache_layer_height;
                g_imgadv_cntx.map.ratio_map_to_resized_image = 
                g_imgadv_cntx.map.ratio_map_to_thumbnail = 
                    (float)g_imgadv_cntx.resized_img_height/ g_imgadv_cntx.map.height;            
            }
            else if (tmp_width > tmp_height)
            {
                g_imgadv_cntx.is_width_dominate = TRUE;
                g_imgadv_cntx.resized_img_height = g_imgadv_cntx.image_height / tmp_width + 0.5;
                g_imgadv_cntx.resized_img_width = g_imgadv_cntx.cache_layer_width;
                g_imgadv_cntx.map.ratio_map_to_resized_image = 
                g_imgadv_cntx.map.ratio_map_to_thumbnail = 
                    (float)g_imgadv_cntx.resized_img_width/g_imgadv_cntx.map.width;            
            }
            else
            {
                g_imgadv_cntx.is_width_dominate = FALSE;
                g_imgadv_cntx.resized_img_width = g_imgadv_cntx.image_width / tmp_height + 0.5;
                g_imgadv_cntx.resized_img_height = g_imgadv_cntx.cache_layer_height;
                g_imgadv_cntx.map.ratio_map_to_resized_image = 
                g_imgadv_cntx.map.ratio_map_to_thumbnail = 
                    (float)g_imgadv_cntx.resized_img_height/g_imgadv_cntx.map.height;
            }
        }
    }
    else
    {
        if (g_imgadv_cntx.is_width_dominate == TRUE)
        {
            g_imgadv_cntx.map.wnd_width = (g_imgadv_cntx.map.wnd_width * g_imgadv_cntx.map.zoom_factor + 0.5);
            g_imgadv_cntx.map.wnd_height = (g_imgadv_cntx.map.wnd_width / g_imgadv_cntx.map.ratio_width_to_height + 0.5);
        }
        else
        {
            g_imgadv_cntx.map.wnd_height = (g_imgadv_cntx.map.wnd_height * g_imgadv_cntx.map.zoom_factor + 0.5);
            g_imgadv_cntx.map.wnd_width = (g_imgadv_cntx.map.wnd_height * g_imgadv_cntx.map.ratio_width_to_height + 0.5);
        }

        /***************************************************
         *  check if new wnd_width/wnd_height > default one.
         *  prevent calculate clip error 
         ***************************************************/
        if (g_imgadv_cntx.map.width < g_imgadv_cntx.map.wnd_width)
            g_imgadv_cntx.map.wnd_width = g_imgadv_cntx.map.width;

        if (g_imgadv_cntx.map.height < g_imgadv_cntx.map.wnd_height)
            g_imgadv_cntx.map.wnd_height = g_imgadv_cntx.map.height;

        
        g_imgadv_cntx.map.wnd_offset_x = g_imgadv_cntx.map.wnd_offset_x - ((g_imgadv_cntx.map.wnd_width - old_wnd_width)>>1);
        g_imgadv_cntx.map.wnd_offset_y = g_imgadv_cntx.map.wnd_offset_y - ((g_imgadv_cntx.map.wnd_height - old_wnd_height)>>1);

        if (g_imgadv_cntx.map.wnd_offset_x < 0)
            g_imgadv_cntx.map.wnd_offset_x = 0;
        else if (g_imgadv_cntx.map.wnd_offset_x + g_imgadv_cntx.map.wnd_width > g_imgadv_cntx.map.width)
            g_imgadv_cntx.map.wnd_offset_x = g_imgadv_cntx.map.width - g_imgadv_cntx.map.wnd_width ;

        if (g_imgadv_cntx.map.wnd_offset_y < 0)
            g_imgadv_cntx.map.wnd_offset_y = 0;
        else if (g_imgadv_cntx.map.wnd_offset_y + g_imgadv_cntx.map.wnd_height > g_imgadv_cntx.map.height)
            g_imgadv_cntx.map.wnd_offset_y = g_imgadv_cntx.map.height - g_imgadv_cntx.map.wnd_height ;

        g_imgadv_cntx.resized_img_width = ((float)(g_imgadv_cntx.map.width * g_imgadv_cntx.cache_layer_width / g_imgadv_cntx.map.wnd_width))+0.5;
        g_imgadv_cntx.resized_img_height = ((float)(g_imgadv_cntx.map.height * g_imgadv_cntx.cache_layer_height / g_imgadv_cntx.map.wnd_height))+0.5;

        /* In order to keep the same proportion with the image, re-calculate the resize image dimension */
        if (g_imgadv_cntx.is_width_dominate == TRUE)
        {
            g_imgadv_cntx.resized_img_height = (g_imgadv_cntx.resized_img_width * g_imgadv_cntx.image_height) / g_imgadv_cntx.image_width;
            
            if (g_imgadv_cntx.resized_img_height < g_imgadv_cntx.cache_layer_height)
            {
                g_imgadv_cntx.resized_img_height = g_imgadv_cntx.cache_layer_height;
                g_imgadv_cntx.resized_img_width = (g_imgadv_cntx.resized_img_height * g_imgadv_cntx.image_width) / g_imgadv_cntx.image_height;
            }
        }
        else
        {
            g_imgadv_cntx.resized_img_width = (g_imgadv_cntx.resized_img_height * g_imgadv_cntx.image_width) / g_imgadv_cntx.image_height;
            
            if (g_imgadv_cntx.resized_img_width < g_imgadv_cntx.cache_layer_width)
            {
                g_imgadv_cntx.resized_img_width = g_imgadv_cntx.cache_layer_width;
                g_imgadv_cntx.resized_img_height = (g_imgadv_cntx.resized_img_width * g_imgadv_cntx.image_height) / g_imgadv_cntx.image_width;
            }
        }
    
        g_imgadv_cntx.map.ratio_map_to_resized_image = 
                (float)g_imgadv_cntx.resized_img_width/g_imgadv_cntx.map.width;            

        g_imgadv_cntx.map.zoom_factor_cnt--;
        g_imgadv_cntx.map.is_zoomin_able = MMI_TRUE;
    }    

    if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG ||
         g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG_FILE)
    {
        gdi_anim_stop_all_by_layer(g_imgadv_cntx.cache_layer_handle);
    }
    mmi_imgadv_draw_map();
    gdi_lcd_repaint_all();
    mmi_imgadv_extract_image_to_cache_layer();

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_check_jpg_resizer_limitation
 * DESCRIPTION
 *  handle HW resize jpg limitation, if can not be resized, so not to
 *  allow to be zoomable. or will be not moved smoothly
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_imgadv_check_jpg_resizer_limitation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp_wnd_width,temp_wnd_height;
    S32 src_width,src_height;
    S32 resized_width,resized_height;
    S32 temp_thum_width,temp_thum_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_imgadv_cntx.image_width < g_imgadv_cntx.cache_layer_width)
        && (g_imgadv_cntx.image_height < g_imgadv_cntx.cache_layer_height))
    {
        return MMI_FALSE;
    }
    
    if (g_imgadv_cntx.map.zoom_factor_cnt != 0)
    {
        if (GDI_LCD_LAYER_ROTATE_0 == g_imgadv_cntx.imgview_rotate)
        {
            g_imgadv_cntx.is_width_dominate = FALSE;
        }
        else
        {
            g_imgadv_cntx.is_width_dominate = TRUE;
        }
        g_imgadv_cntx.map.zoom_factor = 1.25;
        temp_thum_height = g_imgadv_cntx.thumbnail_layer_height;
        temp_thum_width = g_imgadv_cntx.thumbnail_layer_width;
    }
    else
    {
        temp_thum_height = g_imgadv_cntx.resized_img_height;
        temp_thum_width = g_imgadv_cntx.resized_img_width;
    }


    if (g_imgadv_cntx.is_width_dominate == TRUE)
    {
        temp_wnd_width = (g_imgadv_cntx.map.wnd_width / g_imgadv_cntx.map.zoom_factor + 0.5);
        temp_wnd_height = (temp_wnd_width / g_imgadv_cntx.map.ratio_width_to_height + 0.5);
    }
    else
    {
        temp_wnd_height = (g_imgadv_cntx.map.wnd_height / g_imgadv_cntx.map.zoom_factor + 0.5);
        temp_wnd_width = (temp_wnd_height * g_imgadv_cntx.map.ratio_width_to_height + 0.5);
    }
    if (temp_wnd_height < 1)
    {
        temp_wnd_height = 1;
    }
    if (temp_wnd_width < 1)
    {
        temp_wnd_width = 1;
    }
    if (temp_wnd_height > g_imgadv_cntx.map.wnd_height)
    {
        temp_wnd_height = g_imgadv_cntx.map.wnd_height;
    }
    if (temp_wnd_width > g_imgadv_cntx.map.wnd_width)
    {
        temp_wnd_width = g_imgadv_cntx.map.wnd_width;
    }

    src_width = temp_wnd_width * g_imgadv_cntx.map.ratio_map_to_thumbnail;
    src_height = temp_wnd_height * g_imgadv_cntx.map.ratio_map_to_thumbnail;
	if (src_width < 1)
	{
		src_width = 1;
	}
	if (src_height < 1)
	{
		src_height = 1;
	}
    resized_width = temp_thum_width * g_imgadv_cntx.cache_layer_width / src_width;
    resized_height = temp_thum_height * g_imgadv_cntx.cache_layer_height / src_height;
    if (resized_width > g_imgadv_cntx.image_width ||
        resized_height > g_imgadv_cntx.image_height ||
        resized_width > 4095 ||
        resized_height > 4095)
    {
        /* if resized dimension is large than original or limited value, will not allow to zoomin,
        or it will cause resizer failure and can not be moved smoothly */
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_print_req
 * DESCRIPTION
 *  handle print request 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_print_req(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id option_menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_menu_gid = cui_menu_create(
                                    g_imgadv_cui_gid,
                                    CUI_MENU_SRC_TYPE_RESOURCE,
                                    CUI_MENU_TYPE_OPTION,
                                    MENU_ID_FMGR_IMG_OPTION_PRINT,
                                    MMI_TRUE,
                                    NULL);
    cui_menu_set_default_title(option_menu_gid, get_string(STR_GLOBAL_OPTIONS), get_image(GetRootTitleIcon(MENU_ID_IMGVIEW_APP)));
    cui_menu_set_currlist_flags(option_menu_gid, CUI_MENU_LIST_WITH_TEXT_NUMBERED_ITEMS);

    cui_menu_run(option_menu_gid);
}
#endif


#if defined(__MMI_BPP_SUPPORT__) || defined(__MMI_PICT_BRIDGE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_option_print_execute_forward
 * DESCRIPTION
 *   handle lsk event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_option_print_execute_forward(U16 highlight_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    WCHAR filepath[SRV_FMGR_PATH_BUFFER_SIZE / ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get file_info */
    if (g_imgview_cui_ptr->view_mode.viewmode == CUI_IMGVIEW_VIEWMODE_FILENAME)
    {
        mmi_ucs2cpy((CHAR*)filepath, g_imgadv_cntx.ext_filepath);
    }
    else if (g_imgview_cui_ptr->view_mode.viewmode == CUI_IMGVIEW_VIEWMODE_PREFETCH)
    {
        mmi_ucs2cpy((CHAR*)filepath, g_imgview_cui_ptr->view_mode.buff_ptr);
    }
    else
    {
        srv_fmgr_filelist_get_filepath(g_imgview_fl_hdl, g_imgview_fl_idx, filepath, SRV_FMGR_PATH_BUFFER_SIZE);
    }

    ret = srv_fmgr_types_launch_option(filepath, highlight_item);
    if (ret <= 0)
    {
        g_imgadv_cntx.err_str_ptr = GetString(srv_fmgr_fs_error_get_string(ret));
        g_imgadv_cntx.error_event = srv_fmgr_fs_error_get_popup_type(ret);
        mmi_imgadv_display_error_sg(g_imgadv_cui_gid, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
    }
}
#endif


#ifndef MISC
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_get_active_osd_cntx
 * DESCRIPTION
 *  This function is called to set imgadv active osd cntx.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_get_active_osd_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_LCD_LAYER_ROTATE_270 == g_imgadv_cntx.imgview_rotate)
    {
        g_imgadv_cntx.active_osd_layout_ptr = &g_imgadv_osd_cntx_270;
        g_imgadv_cntx.lsk.is_press = FALSE;
        g_imgadv_cntx.rsk.is_press = FALSE;
    }
    else if (GDI_LCD_LAYER_ROTATE_0 == g_imgadv_cntx.imgview_rotate)
    {
        g_imgadv_cntx.active_osd_layout_ptr = &g_imgadv_osd_cntx;
        g_imgadv_cntx.lsk.is_press = FALSE;
        g_imgadv_cntx.rsk.is_press = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_create_resource
 * DESCRIPTION
 *  This function is called to create resource used by imgadv.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_create_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cntx.cache_buf_ptr = mmi_frm_scrmem_alloc_framebuffer(MMI_IMGADV_LAYER_SIZE);

    /* create thumbnail layer resource */
#if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24)
    gdi_layer_create_cf(
        GDI_COLOR_FORMAT_24,
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &g_imgadv_cntx.thumbnail_layer_handle);
#else
        gdi_layer_create(
            0,
            0,
            LCD_WIDTH,
            LCD_HEIGHT,
            &g_imgadv_cntx.thumbnail_layer_handle);
#endif
    layer_ptr = (gdi_layer_struct*)g_imgadv_cntx.thumbnail_layer_handle;
    g_imgadv_cntx.thumbnail_buf_ptr = layer_ptr->buf_ptr;

    gdi_layer_push_and_set_active(g_imgadv_cntx.thumbnail_layer_handle);
    gdi_layer_clear(GDI_COLOR_BLACK);
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        gdi_layer_resize(LCD_HEIGHT,LCD_WIDTH);
    }
    gdi_layer_pop_and_restore_active();

    /* create cache layer resource */
    #if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24)
        gdi_layer_create_cf_using_outside_memory(
            GDI_COLOR_FORMAT_24,
            0,
            0,
            LCD_WIDTH,
            LCD_HEIGHT,
            &g_imgadv_cntx.cache_layer_handle,
            (PU8) g_imgadv_cntx.cache_buf_ptr,
            (S32) MMI_IMGADV_LAYER_SIZE);
    #else
    gdi_layer_create_using_outside_memory(
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &g_imgadv_cntx.cache_layer_handle,
        (PU8) g_imgadv_cntx.cache_buf_ptr,
        (S32) MMI_IMGADV_LAYER_SIZE);
    #endif

    gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
    gdi_layer_clear(GDI_COLOR_BLACK);
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        gdi_layer_resize(LCD_HEIGHT,LCD_WIDTH);
    }
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_free_resource
 * DESCRIPTION
 *  This function is called to free resource used by imgadv
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_free_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /**************************************************************
    * free thumbnail layer handle
    **************************************************************/
    if (g_imgadv_cntx.thumbnail_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_imgadv_cntx.thumbnail_layer_handle);
        g_imgadv_cntx.thumbnail_layer_handle = GDI_LAYER_EMPTY_HANDLE;
        g_imgadv_cntx.thumbnail_buf_ptr = NULL;
    }

    /**************************************************************
    * free cache buffer ptr
    **************************************************************/
    if (g_imgadv_cntx.cache_buf_ptr != NULL)
    {
        mmi_frm_scrmem_free((void*)g_imgadv_cntx.cache_buf_ptr);
        g_imgadv_cntx.cache_buf_ptr = NULL;
    }

    /**************************************************************
    * free cache layer hendle
    **************************************************************/
    if (g_imgadv_cntx.cache_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_imgadv_cntx.cache_layer_handle);
        g_imgadv_cntx.cache_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_display_error_sg
 * DESCRIPTION
 *  This function shows display popup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_display_error_sg(mmi_id parent_gid, mmi_imgview_popup_result_process_enum process)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&arg);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_DISP_POPUP);
    g_imgadv_cntx.is_err_displayed = TRUE;

    if (parent_gid == GRP_ID_INVALID)
    {
        arg.parent_id = GRP_ID_ROOT;
    }
    else
    {
        arg.parent_id = parent_gid;
        arg.user_tag = (void*)process;
    }
    #if defined(__MMI_SCREEN_ROTATE__)
    arg.rotation = (mmi_frm_screen_rotate_enum)g_imgadv_cntx.imgview_rotate;
    #else 
    arg.rotation = MMI_FRM_SCREEN_ROTATE_0;
    #endif
    mmi_popup_display((WCHAR*)g_imgadv_cntx.err_str_ptr, (mmi_event_notify_enum)g_imgadv_cntx.error_event, &arg);
}
#endif


#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_touch_scr_hit_test
 * DESCRIPTION
 *  This function check if icon is pressed on touch screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_imgadv_touch_scr_hit_test(S32 pos_x, S32 pos_y, imgadv_osd_icon_struct  *touch_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pos_x >= touch_obj->offset_x) &&
        (pos_x < touch_obj->offset_x + touch_obj->width) &&
        (pos_y >= touch_obj->offset_y) && (pos_y < touch_obj->offset_y + touch_obj->height))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_pen_down_hdlr
 * DESCRIPTION
 *  pen down event handler.
 * PARAMETERS
 *  pos IN position of the touched pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }
    g_imgadv_cntx.pen_down_x = pos.x;
    g_imgadv_cntx.pen_down_y = pos.y; 

    g_imgadv_cntx.is_pen_down = TRUE;
    mmi_imgadv_osd_show_up();
    if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
    {
        gui_cancel_timer(mmi_imgadv_osd_fade_cyclic);
    }
    
    /* LSK */
    if (mmi_imgadv_touch_scr_hit_test(pos.x, pos.y, &g_imgadv_cntx.lsk) == MMI_TRUE)
    {
        g_imgadv_cntx.touch_object = IMGADV_TOUCH_LSK;
        if (mmi_imgadv_lsk_is_enable())
        {
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            g_imgadv_cntx.on_icon_pen_down = MMI_TRUE;
        }
        mmi_imgadv_lsk_press();
        return;
    }

    /* RSK */
    if (mmi_imgadv_touch_scr_hit_test(pos.x, pos.y, &g_imgadv_cntx.rsk) == MMI_TRUE)
    {
        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        g_imgadv_cntx.touch_object = IMGADV_TOUCH_RSK;
        g_imgadv_cntx.on_icon_pen_down = MMI_TRUE;
        mmi_imgadv_rsk_press();
        return;
    }

    /* osd test */
    #define IMGADV_OSD_ICON_TOUCH_TEST(a,A)\
    do {\
        if(g_imgadv_cntx.active_osd_layout_ptr->##a##.is_show)\
        {\
            if(mmi_imgadv_touch_scr_hit_test(pos.x, pos.y, &(g_imgadv_cntx.active_osd_layout_ptr->##a##)) == MMI_TRUE)\
            {\
                mmi_imgadv_##a##_press();\
                g_imgadv_cntx.touch_object = IMGADV_TOUCH_##A;\
                if (g_imgadv_cntx.map.is_##a##_able)\
                {\
                    gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);\
                    g_imgadv_cntx.on_icon_pen_down = MMI_TRUE;\
                }\
                return;\
            }\
        }\
    } while(0)
    /* when arrow icon can also grey, should also judge for g_imgadv_cntx.on_icon_pen_down = MMI_TRUE;*/
    if(g_imgadv_cntx.active_osd_layout_ptr->larrow.is_show && !g_imgadv_cntx.is_external_req)
    {
        if(mmi_imgadv_touch_scr_hit_test(pos.x, pos.y, &(g_imgadv_cntx.active_osd_layout_ptr->larrow)) == MMI_TRUE)
        {
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            mmi_imgadv_previous_image_press();
            g_imgadv_cntx.touch_object = IMGADV_TOUCH_LEFT_ARROW;
            g_imgadv_cntx.on_icon_pen_down = MMI_TRUE;
            return;
        }
    }

    if(g_imgadv_cntx.active_osd_layout_ptr->rarrow.is_show && !g_imgadv_cntx.is_external_req)
    {
        if(mmi_imgadv_touch_scr_hit_test(pos.x, pos.y, &(g_imgadv_cntx.active_osd_layout_ptr->rarrow)) == MMI_TRUE)
        {
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            mmi_imgadv_next_image_press(); 
            g_imgadv_cntx.touch_object = IMGADV_TOUCH_RIGHT_ARROW;
            g_imgadv_cntx.on_icon_pen_down = MMI_TRUE;
            return;
        }
    }

    IMGADV_OSD_ICON_TOUCH_TEST(zoomin, ZOOMIN);
    IMGADV_OSD_ICON_TOUCH_TEST(zoomout, ZOOMOUT);
    //IMGADV_OSD_ICON_TOUCH_TEST(rotate, ROTATE);
    if(g_imgadv_cntx.active_osd_layout_ptr->rotate.is_show)
    {
        if(mmi_imgadv_touch_scr_hit_test(pos.x, pos.y, &(g_imgadv_cntx.active_osd_layout_ptr->rotate)) == MMI_TRUE)
        {
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            mmi_imgadv_rotate_press();
            g_imgadv_cntx.touch_object = IMGADV_TOUCH_ROTATE;
            g_imgadv_cntx.on_icon_pen_down = MMI_TRUE;
            return;
        }
    }
    g_imgadv_cntx.touch_object = IMGADV_TOUCH_NONE;
    
    /* if not touching icon , do translate image */
    if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
    {
        mmi_imgadv_cancel_decode_timer();
    }
    #if defined(SVG12_SUPPORT)
    svg_pen_event_handler(MMI_PEN_EVENT_DOWN, pos.x, pos.y);
    #endif
    
    #ifdef IMGADV_OSD_ICON_TOUCH_TEST
    #undef IMGADV_OSD_ICON_TOUCH_TEST
    #endif

}


#ifdef __MTK_TARGET__
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_pen_abort_hdlr
 * DESCRIPTION
 *  pen abort event handler
 * PARAMETERS
 *  pos IN position of the touched pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_pen_abort_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_abort_type_enum abort_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_imgadv_cntx.is_pen_down)
    {
        return;
    }

    /* get pen abort type, will do pen up action if pen up lost because queue full, or do nothing */
    abort_type = mmi_pen_get_pen_abort_type();
    if (abort_type == MMI_PEN_ABORT_TYPE_DRVQ_FULL)
    {
        mmi_imgadv_pen_up_hdlr(pos);
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_pen_up_hdlr
 * DESCRIPTION
 *  pen up event handler
 * PARAMETERS
 *  pos IN position of the touched pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_imgadv_cntx.is_pen_down)
    {
        return;
    }
    
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }
    if (g_imgadv_cntx.on_icon_pen_down == MMI_TRUE)
    {
        mmi_imgadv_reset_osd_fade(MMI_TRUE);
        g_imgadv_cntx.on_icon_pen_down = MMI_FALSE;
    }
    
    if (g_imgadv_cntx.touch_object == IMGADV_TOUCH_NONE && 
        g_imgadv_cntx.map.zoom_factor_cnt > 0 &&
        g_imgadv_cntx.is_pen_down == TRUE)
    {
        S32 movement_x, movement_y;
        movement_x = (g_imgadv_cntx.pen_down_x - pos.x) / 5;
        movement_y = (g_imgadv_cntx.pen_down_y - pos.y) / 5;

        g_imgadv_cntx.map.wnd_offset_x += movement_x;
        g_imgadv_cntx.map.wnd_offset_y += movement_y;

        if (g_imgadv_cntx.map.wnd_offset_x < 0)
            g_imgadv_cntx.map.wnd_offset_x = 0;
        else if (g_imgadv_cntx.map.wnd_offset_x + g_imgadv_cntx.map.wnd_width > g_imgadv_cntx.map.width)
            g_imgadv_cntx.map.wnd_offset_x = g_imgadv_cntx.map.width - g_imgadv_cntx.map.wnd_width ;

        if (g_imgadv_cntx.map.wnd_offset_y < 0)
            g_imgadv_cntx.map.wnd_offset_y = 0;
        else if (g_imgadv_cntx.map.wnd_offset_y + g_imgadv_cntx.map.wnd_height > g_imgadv_cntx.map.height)
            g_imgadv_cntx.map.wnd_offset_y = g_imgadv_cntx.map.height - g_imgadv_cntx.map.wnd_height ;

        mmi_imgadv_draw_map();
        mmi_imgadv_start_decode_timer();
    }
    else
    {
        switch (g_imgadv_cntx.touch_object)
        {
            case IMGADV_TOUCH_LSK:
                mmi_imgadv_lsk_release();
                break;
            case IMGADV_TOUCH_RSK:
                mmi_imgadv_rsk_release();
                break;
            case IMGADV_TOUCH_LEFT_ARROW:
                mmi_imgadv_previous_image_release();            
                break;
            case IMGADV_TOUCH_RIGHT_ARROW:
                mmi_imgadv_next_image_release();            
                break;
            case IMGADV_TOUCH_ZOOMIN:
                mmi_imgadv_zoomin_release();
                break;
            case IMGADV_TOUCH_ZOOMOUT:
                mmi_imgadv_zoomout_release();
                break;
            case IMGADV_TOUCH_ROTATE:
                mmi_imgadv_rotate_release();
                break;
        }
    }
    #if defined(SVG12_SUPPORT)
    svg_pen_event_handler(MMI_PEN_EVENT_UP, pos.x, pos.y);
    #endif

    g_imgadv_cntx.is_pen_down = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_pen_move_hdlr
 * DESCRIPTION
 *  pen move event handler.
 * PARAMETERS
 *  pos IN current position of the moved pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL softkey_pressed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #define IMGADV_SWITCH_CASE(a,A)\
        case IMGADV_TOUCH_##A:\
            if (!mmi_imgadv_touch_scr_hit_test(pos.x, pos.y, &g_imgadv_cntx.active_osd_layout_ptr->##a##))\
            {\
                g_imgadv_cntx.active_osd_layout_ptr->##a##.is_press = FALSE;\
                mmi_imgadv_draw_osd();\
                gdi_lcd_repaint_all();\
                g_imgadv_cntx.touch_object = IMGADV_TOUCH_NONE;\
            }\
            break;\

    softkey_pressed = FALSE;
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }

    if (g_imgadv_cntx.touch_object == IMGADV_TOUCH_NONE && 
        g_imgadv_cntx.map.zoom_factor_cnt > 0 &&
        g_imgadv_cntx.is_pen_down == TRUE)
    {
        S32 movement_x, movement_y;
        movement_x = (g_imgadv_cntx.pen_down_x - pos.x) / 5;
        movement_y = (g_imgadv_cntx.pen_down_y - pos.y) / 5;

        mmi_imgadv_reset_osd_fade(MMI_FALSE);
        g_imgadv_cntx.map.wnd_offset_x += movement_x;
        g_imgadv_cntx.map.wnd_offset_y += movement_y;

        if (g_imgadv_cntx.map.wnd_offset_x < 0)
            g_imgadv_cntx.map.wnd_offset_x = 0;
        else if (g_imgadv_cntx.map.wnd_offset_x + g_imgadv_cntx.map.wnd_width > g_imgadv_cntx.map.width)
            g_imgadv_cntx.map.wnd_offset_x = g_imgadv_cntx.map.width - g_imgadv_cntx.map.wnd_width ;

        if (g_imgadv_cntx.map.wnd_offset_y < 0)
            g_imgadv_cntx.map.wnd_offset_y = 0;
        else if (g_imgadv_cntx.map.wnd_offset_y + g_imgadv_cntx.map.wnd_height > g_imgadv_cntx.map.height)
            g_imgadv_cntx.map.wnd_offset_y = g_imgadv_cntx.map.height - g_imgadv_cntx.map.wnd_height ;

        g_imgadv_cntx.pen_down_x = pos.x;
        g_imgadv_cntx.pen_down_y = pos.y;        

        if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG ||
             g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG_FILE )
            gdi_anim_stop_all_by_layer(g_imgadv_cntx.cache_layer_handle);

        {
            S32 src_x, src_y, src_width, src_height;
            S32 dest_x = 0, dest_y = 0, dest_width, dest_height;

            #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
                if (g_imgadv_cntx.is_decoding)
                {
                    gdi_image_nb_stop_all();
                    gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
                    gdi_layer_clear(GDI_COLOR_BLACK);
                    gdi_layer_pop_and_restore_active();
                }
            #endif


            src_x = g_imgadv_cntx.map.wnd_offset_x * g_imgadv_cntx.map.ratio_map_to_thumbnail;
            src_y = g_imgadv_cntx.map.wnd_offset_y * g_imgadv_cntx.map.ratio_map_to_thumbnail;
            src_width = g_imgadv_cntx.map.wnd_width * g_imgadv_cntx.map.ratio_map_to_thumbnail;
            src_height = g_imgadv_cntx.map.wnd_height * g_imgadv_cntx.map.ratio_map_to_thumbnail;

            /************************************************
             *
             *  check if src_width/src_height > layer's
             *  prevent calculate clip error 
             *
             ************************************************/
            if (src_height > g_imgadv_cntx.thumbnail_layer_height)
                src_height = g_imgadv_cntx.thumbnail_layer_height;

            if (src_width > g_imgadv_cntx.thumbnail_layer_width)
                src_width = g_imgadv_cntx.thumbnail_layer_width;

            if (src_x + src_width > g_imgadv_cntx.thumbnail_layer_width)
                src_x = g_imgadv_cntx.thumbnail_layer_width - src_width;

            if (dest_y + src_height > g_imgadv_cntx.thumbnail_layer_height)
                dest_y = g_imgadv_cntx.thumbnail_layer_height - src_height;

            gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
            gdi_layer_get_dimension(&dest_width, &dest_height);

            gdi_bitblt_resized(
                g_imgadv_cntx.thumbnail_layer_handle,
                src_x,
                src_y,
                src_x + src_width - 1,
                src_y + src_height - 1,
                dest_x,
                dest_y,
                dest_x + dest_width - 1,
                dest_y + dest_height - 1);
            
            gdi_layer_pop_and_restore_active();
        }    
        mmi_imgadv_draw_map();
        mmi_imgadv_draw_osd();
    #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
        if (!g_imgadv_cntx.is_decoding)
    #endif
        {
            gdi_lcd_repaint_all();   
        } 
    }
    else
    {
        switch (g_imgadv_cntx.touch_object)
        {
            case IMGADV_TOUCH_LSK:
                if (mmi_imgadv_touch_scr_hit_test(pos.x, pos.y, &g_imgadv_cntx.lsk))
                {
                    softkey_pressed = TRUE;
                    g_imgadv_cntx.touch_object=IMGADV_TOUCH_LSK;
                }
                else
                {
                    softkey_pressed = FALSE;
                    g_imgadv_cntx.touch_object=IMGADV_TOUCH_NONE;
                }

                if (softkey_pressed != g_imgadv_cntx.lsk.is_press )
                {
                    g_imgadv_cntx.lsk.is_press = softkey_pressed;
                    mmi_imgadv_draw_osd();
                    gdi_lcd_repaint_all();
                }
                break;

            case IMGADV_TOUCH_RSK:
                if (mmi_imgadv_touch_scr_hit_test(pos.x, pos.y, &g_imgadv_cntx.rsk))
                {
                    softkey_pressed = TRUE;
                    g_imgadv_cntx.touch_object=IMGADV_TOUCH_RSK;                    
                }
                else
                {
                    softkey_pressed = FALSE;
                    g_imgadv_cntx.touch_object=IMGADV_TOUCH_NONE;
                }

                if (softkey_pressed != g_imgadv_cntx.rsk.is_press )
                {
                    g_imgadv_cntx.rsk.is_press = softkey_pressed;
                    mmi_imgadv_draw_osd();
                    gdi_lcd_repaint_all();
                }
                break;
            IMGADV_SWITCH_CASE(zoomin,ZOOMIN);
            IMGADV_SWITCH_CASE(zoomout,ZOOMOUT);
            IMGADV_SWITCH_CASE(rotate,ROTATE);
            IMGADV_SWITCH_CASE(rarrow,RIGHT_ARROW);
            IMGADV_SWITCH_CASE(larrow,LEFT_ARROW);
        }
    }
    #if defined(SVG12_SUPPORT)
    /* We only apply pen move event when zoom_factor == 0 */
    if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
    {
        svg_pen_event_handler(MMI_PEN_EVENT_MOVE, pos.x, pos.y);
    }
    #endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_pen_down_hdlr_osd_showup
 * DESCRIPTION
 *  pen down event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_pen_down_hdlr_osd_showup(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*    
    g_imgadv_cntx.is_pen_down = FALSE;
*/
    g_imgadv_cntx.touch_object = IMGADV_TOUCH_NONE;
    mmi_imgadv_osd_show_up();
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


#if defined(__MMI_TVOUT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_anim_callback
 * DESCRIPTION
 *  animation callback function for gdi animate.
 * PARAMETERS
 *  gdi_result IN return code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_anim_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE tvout_layer;
    PU8 p_src,p_dest;
    gdi_rect_struct clip;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (result < GDI_SUCCEED)
    {
        return;
    }

    if (mdi_tvout_is_enable())
    {
        /* buffer should only need to be get once. */
        p_src = g_imgadv_cntx.cache_buf_ptr;
       
        tvout_layer = mdi_tvout_get_active_layer();
        gdi_layer_push_and_set_active(tvout_layer);
        gdi_layer_get_buffer_ptr(&p_dest);

        if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
        {
            clip.x1 = clip.y1 = 0;
            clip.x2 = g_imgadv_cntx.resized_img_width-1;
            clip.y2 = g_imgadv_cntx.resized_img_height-1;
            gdi_2d_memory_blt(
                p_src,
                g_imgadv_cntx.cache_layer_width,
                (g_imgadv_cntx.cache_layer_width - g_imgadv_cntx.resized_img_width) >>1,
                (g_imgadv_cntx.cache_layer_height - g_imgadv_cntx.resized_img_height) >>1,
                g_imgadv_cntx.resized_img_width,
                g_imgadv_cntx.resized_img_height,
                p_dest,
                g_imgadv_cntx.tvout_width ,
                0,                       /* the offset on the dest buffer */
                0,
                clip,
                GDI_MAINLCD_BIT_PER_PIXEL);
        }
        else if (g_imgadv_cntx.map.zoom_factor_cnt > 0) 
        {
            clip.x1 = clip.y1 = 0;
            clip.x2 = g_imgadv_cntx.cache_layer_width-1;
            clip.y2 = g_imgadv_cntx.cache_layer_height-1;
            gdi_2d_memory_blt(
                p_src,
                g_imgadv_cntx.cache_layer_width,
                0,
                0,
                g_imgadv_cntx.cache_layer_width,
                g_imgadv_cntx.cache_layer_height,
                p_dest,
                g_imgadv_cntx.tvout_width,
                0,                       /* the offset on the dest buffer */
                0,
                clip,
                GDI_MAINLCD_BIT_PER_PIXEL);            
        }
        gdi_layer_pop_and_restore_active();        
        mdi_tvout_blt();        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_tvout_clear_bg
 * DESCRIPTION
 *  This function clear tvout buffer bg..
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_tvout_clear_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 tvout_buf_width;
    S32 tvout_buf_height;
    GDI_HANDLE tvout_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_tvout_is_enable())
    {
        if (g_imgadv_cntx.result >= 0)
        {
            /* get best fit size for PAL/NTSC */
            mdi_tvout_get_owner_draw_best_size(&tvout_buf_width, &tvout_buf_height);

            /* set mode to owner draw */
            mdi_tvout_set_mode(
                MDI_TV_MODE_OWNER_DRAW,
                tvout_buf_width,    /* layer_width */
                tvout_buf_height);  /* layer_height */

            tvout_layer = mdi_tvout_get_active_layer();

            gdi_layer_push_and_set_active(tvout_layer);
            gdi_layer_reset_clip();
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();

            /* blt to TV */
            mdi_tvout_blt();
        }
        else
        {
            /* has error, draw a black screen, use 10, 10 size to save memroy bandwidth */
            tvout_buf_width = 16;
            tvout_buf_height = 16;

            /* set mode to owner draw */
            mdi_tvout_set_mode(
                MDI_TV_MODE_OWNER_DRAW,
                tvout_buf_width,    /* layer_width */
                tvout_buf_height);  /* layer_height */

            tvout_layer = mdi_tvout_get_active_layer();

            gdi_layer_push_and_set_active(tvout_layer);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();

            /* blt to TV */
            mdi_tvout_blt();

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_tvout_decode
 * DESCRIPTION
 *  This function will decode the current file to tv buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_tvout_decode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 tvout_buf_width;
    S32 tvout_buf_height;
    S32 tvout_resized_offset_x;
    S32 tvout_resized_offset_y;
    S32 tvout_resized_width;
    S32 tvout_resized_height;
    S32 tvout_draw_resized_width;
    S32 tvout_draw_resized_height;

    GDI_HANDLE tvout_layer;
    S32 offset_x = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_tvout_is_enable())
    {
        if (g_imgadv_cntx.result >= 0 && (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG_FILE 
            || g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_M3D_FILE || g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_GIF_FILE))
        {
            // do nothing
        }
        else if (g_imgadv_cntx.result >= 0)
        {
            /* get best fit size for PAL/NTSC */
            mdi_tvout_get_owner_draw_best_size(&tvout_buf_width, &tvout_buf_height);

            mdi_tvout_force_disable_vertical_filter();

            if ((g_imgadv_cntx.image_width > tvout_buf_width) ||
                (g_imgadv_cntx.image_height > tvout_buf_height))
            {
                gdi_image_util_fit_bbox(
                    tvout_buf_width,
                    tvout_buf_height,
                    g_imgadv_cntx.image_width,
                    g_imgadv_cntx.image_height,
                    &tvout_resized_offset_x,
                    &tvout_resized_offset_y,
                    &tvout_resized_width,
                    &tvout_resized_height);
            }
            else
            {
                tvout_resized_width = g_imgadv_cntx.image_width;
                tvout_resized_height = g_imgadv_cntx.image_height;
                tvout_resized_offset_x = (tvout_buf_width - g_imgadv_cntx.image_width) >> 1;
                tvout_resized_offset_y = (tvout_buf_height - g_imgadv_cntx.image_height) >> 1;
            }

		tvout_draw_resized_width = tvout_resized_width;
		tvout_draw_resized_height = tvout_resized_height;
		if (tvout_resized_width <= 1) 
		{
			tvout_resized_width = 2;
			tvout_draw_resized_width = 1;
		}
		if (tvout_resized_height <= 1) 
		{
			tvout_resized_height = 2;
			tvout_draw_resized_height = 1;
		}

        /* set mode to owner draw */
        /*
        *  check if tvout_resized_width % 2 == 0 
        *  for all chips, tvout_buffer_width must be 2x.
        */
        if (tvout_resized_width % 2 == 0)
            mdi_tvout_set_mode(
                MDI_TV_MODE_OWNER_DRAW,
                tvout_resized_width,    /* layer_width */
                tvout_resized_height);  /* layer_height */
        else
            mdi_tvout_set_mode(
                MDI_TV_MODE_OWNER_DRAW,
                tvout_resized_width+1,    /* layer_width */
                tvout_resized_height);  /* layer_height */

            tvout_layer = mdi_tvout_get_active_layer();

            /* need to set to tv lcd, gdi anim will keep this info */
            gdi_layer_push_and_set_active(tvout_layer);
            gdi_layer_reset_clip();
            gdi_layer_clear(GDI_COLOR_BLACK);

            gdi_push_and_set_alpha_blending_source_layer(tvout_layer);

			g_imgadv_cntx.animation_on_tv = GDI_NULL_HANDLE;

            gdi_image_draw_animation_resized_file(
                offset_x,
                0,
                tvout_draw_resized_width,
                tvout_draw_resized_height,
                (CHAR*) g_imgadv_cntx.filepath,
                &g_imgadv_cntx.animation_on_tv);
            gdi_pop_and_restore_alpha_blending_source_layer();

            gdi_layer_pop_and_restore_active();
            
            /* blt to TV */
            mdi_tvout_blt();
        }
        else
        {
            /* has error, draw a black screen, use 10, 10 size to save memroy bandwidth */
            tvout_buf_width = 16;
            tvout_buf_height = 16;

            /* set mode to owner draw */
            mdi_tvout_set_mode(
                MDI_TV_MODE_OWNER_DRAW,
                tvout_buf_width,    /* layer_width */
                tvout_buf_height);  /* layer_height */

            tvout_layer = mdi_tvout_get_active_layer();

            gdi_layer_push_and_set_active(tvout_layer);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();

            /* blt to TV */
            mdi_tvout_blt();

        }
    }
}
#endif /* defined(__MMI_TVOUT__) */


#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
static void mmi_imgadv_dummy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_decode_done_callback
 * DESCRIPTION
 *  decode done callback function called by gdi
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_decode_done_callback(GDI_RESULT result, gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID scrnid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgadv_cntx.is_external_req)
    {
        scrnid = SCR_ID_IMGVIEW_VIEW_EXT;
    }
    else
    {
        scrnid = SCR_ID_IMGVIEW_VIEW;
    }
    if (mmi_frm_scrn_get_active_id()!=scrnid)
    return;

    g_imgadv_cntx.is_decoding = MMI_FALSE;
    
    if (g_imgadv_cntx.is_initialized == FALSE)
    {
        mmi_imgadv_init_key_handler();
        mmi_imgadv_init_default_touch_and_key_handler();
        g_imgadv_cntx.is_initialized = TRUE;
    }
    
    #ifdef __DRM_SUPPORT__
    if (result == GDI_SUCCEED && g_imgadv_cntx.is_resume != TRUE && g_imgadv_cntx.drm_handle != NULL)
    {
        g_imgadv_cntx.drm_id = 
            DRM_consume_rights(g_imgadv_cntx.drm_handle, DRM_PERMISSION_DISPLAY, mmi_imgadv_drm_callback_hdlr);
        g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_CONSUME;

        DRM_close_file(g_imgadv_cntx.drm_handle);
        g_imgadv_cntx.drm_handle = NULL;
    }
    #endif

    if (result != GDI_SUCCEED && (( g_imgadv_cntx.is_err_displayed == TRUE) && g_imgadv_cntx.result != MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR))
    {
        g_imgadv_cntx.result = MMI_IMGADV_ERROR;
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
        mmi_imgadv_reset_osd_fade(MMI_TRUE);
        return;
    }
    else if (result != GDI_SUCCEED)
    {
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
        gdi_lcd_repaint_all();

        if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
        {
            if (result == GDI_JPEG_ERR_IMAGE_TOO_LARGE)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE);
            }
            else if (result== GDI_JPEG_ERR_FILE_FORMAT_WRONG)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_INVALID_FORMAT);
            }
            else if (result== GDI_JPEG_ERR_DECODE_TIME_OUT)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE);
            }
            else if (result== GDI_IMAGE_ERR_INVALID_IMG_TYPE)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_INVALID_FORMAT);
            }
            else if (result == GDI_IMAGE_ERR_UNSUPPORTED_FORMAT)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_UNSUPPORTED_FORMAT);
            }
            else
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_INVALID_FORMAT);
            }
        }
        else
        {
            if (result== GDI_JPEG_ERR_IMAGE_TOO_LARGE)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE);
            }
            else if (result== GDI_JPEG_ERR_FILE_FORMAT_WRONG)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_INVALID_FORMAT);
            }
            else
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE);
        }

        if (g_imgadv_cntx.map.zoom_factor_cnt+1 <= 1)
        {
            g_imgadv_cntx.map.zoom_factor_cnt = 0;
            g_imgadv_cntx.result = MMI_IMGADV_FIRST_TIME_DECODE_ERR;    
            g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
            g_imgadv_cntx.map.is_zoomout_able = MMI_FALSE;
        }
        else
        {
            g_imgadv_cntx.result = MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR;  
            g_imgadv_cntx.map.zoom_factor_cnt--;
            g_imgadv_cntx.map.max_zoom_factor_cnt = g_imgadv_cntx.map.zoom_factor_cnt;

            g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
            if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
            {
                g_imgadv_cntx.map.is_zoomout_able = MMI_TRUE;
            }
            else
            {
                g_imgadv_cntx.map.is_zoomout_able = MMI_FALSE;
            }
        }
        g_imgadv_cntx.error_event = MMI_EVENT_FAILURE;
        mmi_imgadv_display_error_sg(g_imgadv_cui_gid, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
        return;
    }
    else
    {
        if (g_imgadv_cntx.image_type != GDI_IMAGE_TYPE_GIF && 
            g_imgadv_cntx.image_type != GDI_IMAGE_TYPE_GIF_FILE &&
            g_imgadv_cntx.image_type != GDI_IMAGE_TYPE_M3D &&
            g_imgadv_cntx.image_type != GDI_IMAGE_TYPE_M3D_FILE)
        {
            if (g_imgadv_cntx.map.zoom_factor_cnt >= g_imgadv_cntx.map.max_zoom_factor_cnt ||
                g_imgadv_cntx.image_height < g_imgadv_cntx.cache_layer_height || 
                g_imgadv_cntx.image_width < g_imgadv_cntx.cache_layer_width ||
                g_imgadv_cntx.map.ratio_map_to_image <= 0 ||
                g_imgadv_cntx.map.width <= 0 || 
                g_imgadv_cntx.map.height <= 0)
            {
                g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
            }
            else if ( (g_imgadv_cntx.resized_img_width * g_imgadv_cntx.map.zoom_factor > g_imgadv_cntx.image_width) ||
                 (g_imgadv_cntx.resized_img_height * g_imgadv_cntx.map.zoom_factor > g_imgadv_cntx.image_height))
            {
                g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
                g_imgadv_cntx.map.max_zoom_factor_cnt = g_imgadv_cntx.map.zoom_factor_cnt;
            }
            else
            {
                if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
                {
                    float tmp_ratio;
                
                    tmp_ratio = (float)g_imgadv_cntx.cache_layer_height/ g_imgadv_cntx.resized_img_height;
                    if (g_imgadv_cntx.map.zoom_factor  < tmp_ratio)
                    {
                        g_imgadv_cntx.map.zoom_factor  = tmp_ratio;
                    }

                    tmp_ratio = (float)g_imgadv_cntx.cache_layer_width / g_imgadv_cntx.resized_img_width;
                    if (g_imgadv_cntx.map.zoom_factor  < tmp_ratio)
                    {
                        g_imgadv_cntx.map.zoom_factor  = tmp_ratio;
                    }
                }
                
                if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_JPG||
                    g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_JPG_FILE)
                {
                    if (g_imgadv_cntx.resized_img_width * g_imgadv_cntx.map.zoom_factor < 4095 &&
                        g_imgadv_cntx.resized_img_height * g_imgadv_cntx.map.zoom_factor < 4095)
                    {
                        g_imgadv_cntx.map.is_zoomin_able = MMI_TRUE;
                    }
                    else
                    {
                        g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
                    }
                }
                else if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_PNG||
                    g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_PNG_FILE)
                {
                    if (g_imgadv_cntx.resized_img_width * g_imgadv_cntx.map.zoom_factor < 2047 &&
                        g_imgadv_cntx.resized_img_height * g_imgadv_cntx.map.zoom_factor < 4096)
                    {
                        g_imgadv_cntx.map.is_zoomin_able = MMI_TRUE;
                    }
                    else
                    {
                        g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
                    }
                }
                else
                {
                    g_imgadv_cntx.map.is_zoomin_able = MMI_TRUE;
                }
                g_imgadv_cntx.map.zoom_factor = 1.25;
                        
            }
        #ifdef __MMI_TVOUT__
            if (mdi_tvout_is_enable() && 
                (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG ||
                 g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG_FILE))
            {
                g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
                g_imgadv_cntx.map.zoom_factor_cnt = 0;            
            }
        #endif      
        }
        else
        {
            g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
            g_imgadv_cntx.map.zoom_factor_cnt = 0;
            
        }
        
        /* CUI control part, user can reset it */
        if (g_imgview_cui_ptr->cap_enable[CUI_IMGVIEW_CAP_ZOOM] == MMI_FALSE)
        {
            g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
        }
        
        if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
        {
            g_imgadv_cntx.map.is_zoomout_able = MMI_TRUE;
        }
        else
        {
            g_imgadv_cntx.map.is_zoomout_able = MMI_FALSE;
        }
        mmi_imgadv_init_key_handler();
        mmi_imgadv_init_default_touch_and_key_handler();
        mmi_imgadv_draw_osd();
        gdi_lcd_repaint_all();
    }
    if (g_imgadv_cntx.active_osd_layout_ptr->rarrow.is_press == FALSE
        && g_imgadv_cntx.active_osd_layout_ptr->larrow.is_press == FALSE
        && g_imgadv_cntx.active_osd_layout_ptr->rotate.is_press == FALSE
        && g_imgadv_cntx.active_osd_layout_ptr->zoomin.is_press == FALSE
        && g_imgadv_cntx.active_osd_layout_ptr->zoomout.is_press == FALSE
        && g_imgadv_cntx.lsk.is_press == FALSE
        && g_imgadv_cntx.rsk.is_press == FALSE)
    {
        mmi_imgadv_osd_fade_cyclic();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_draw_truncated_style_text
 * DESCRIPTION
 *  This function is called to draw style text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_draw_truncated_style_text(CHAR* str, S32 offset_x, S32 offset_y, S32 width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (r2lMMIFlag)
    {
        offset_x += g_imgadv_cntx.active_osd_layout_ptr->title.width;
    }
    
    gdi_push_and_set_alpha_blending_source_layer(g_imgadv_cntx.cache_layer_handle);
    gui_move_text_cursor(offset_x, offset_y);
    gui_set_text_color(gui_color(255, 255, 255));
    gui_set_text_border_color(gui_color(0, 0, 0));
    gui_print_truncated_borderd_text(offset_x, offset_y, width, (UI_string_type) str);
    gdi_pop_and_restore_alpha_blending_source_layer();
}
#endif /* defined(__MMI_IMGADV_NONBLOCKING_DECODE__) */


#if defined(__DRM_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_pause_drm_consume_if_need
 * DESCRIPTION
 *  consume DRM right if the it is in correct drm state 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_pause_drm_consume_if_need(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_IMGADV_CONSUME_DRM_IF_NEED,g_imgadv_cntx.drm_state,g_imgadv_cntx.drm_id);
    if ((g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_CONSUME)||(g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_PAUSE))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_IMGADV_CONSUME_DRM,g_imgadv_cntx.drm_state,g_imgadv_cntx.drm_id);

        DRM_stop_consume(g_imgadv_cntx.drm_id);
        g_imgadv_cntx.drm_id = 0;
        g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_EXIT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_drm_callback_hdlr
 * DESCRIPTION
 *  DRM Timeout hdlr
 * PARAMETERS
 *  S32 result
 *  S32 id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_drm_callback_hdlr(kal_int32 result, kal_int32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*****************************************************************
     * TIME OUT
     * ---------------------------------------------------------------
     * show popup and draw black bg on panel 
     *****************************************************************/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_DRM_CALLBACK_HDLR,g_imgadv_cntx.drm_state,g_imgadv_cntx.drm_id);
    if (mmi_frm_scrn_get_active_id() == SCR_ID_IMGVIEW_VIEW)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_DRM_CALLBACK_IN_APP);
        if (g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_CONSUME || g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_PAUSE)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_CONSUME_DRM,g_imgadv_cntx.drm_state,g_imgadv_cntx.drm_id);
            DRM_stop_consume(g_imgadv_cntx.drm_id);
            g_imgadv_cntx.drm_id = 0;
            g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_EXIT;
        }
        
        g_imgadv_cntx.result = MMI_IMGADV_DRM_INVALID; 
        g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_DRM_PROHIBITED);
        g_imgadv_cntx.error_event = MMI_EVENT_FAILURE;
        mmi_imgadv_display_error_sg(g_imgadv_cui_gid, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
    }
    else if (mmi_frm_scrn_is_present(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_IMGADV_DRM_CALLBACK_IN_HISTORY);
        if (g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_CONSUME || g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_PAUSE)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_CONSUME_DRM,g_imgadv_cntx.drm_state,g_imgadv_cntx.drm_id);
            DRM_stop_consume(g_imgadv_cntx.drm_id);
            g_imgadv_cntx.drm_id = 0;
            g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_EXIT;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_process_drm_hdlr
 * DESCRIPTION
 *  This function check DRM right of the file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static imgadv_drm_ret_enum mmi_imgadv_process_drm_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    imgadv_drm_ret_enum         ret = IMGADV_DRM_NOT_DRM_FILE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check multipart or single part first */

#ifdef __DRM_V02__    
    if (srv_fmgr_types_find_type_by_filepath((WCHAR*)g_imgadv_cntx.filepath) == FMGR_TYPE_ODF)
    {
        ret = IMGADV_DRM_DRM_FILE;
        ret |= IMGADV_DRM_MULTI_PART;       
    }
    else
#endif
    {
        if ((g_imgadv_cntx.drm_handle = DRM_open_file((PU16) g_imgadv_cntx.filepath, FS_READ_ONLY, DRM_PERMISSION_DISPLAY)) >= FS_NO_ERROR)
        {

            if (DRM_get_object_method(g_imgadv_cntx.drm_handle, NULL) == DRM_METHOD_NONE)
            {
                ret = IMGADV_DRM_NOT_DRM_FILE;
                DRM_close_file(g_imgadv_cntx.drm_handle);
                g_imgadv_cntx.drm_handle = NULL;
                return ret;
            }

            ret = IMGADV_DRM_DRM_FILE;

            if (DRM_validate_permission(NULL, (kal_wchar *)g_imgadv_cntx.filepath, DRM_PERMISSION_PRINT))
                ret |= IMGADV_DRM_PRINT_VALID;

            if (DRM_validate_permission(NULL, (kal_wchar *)g_imgadv_cntx.filepath, DRM_PERMISSION_DISPLAY))
            {
                ret |= IMGADV_DRM_DISPLAY_VALID;
                g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_DECODING;
            }
            else
            {
               DRM_close_file(g_imgadv_cntx.drm_handle);
               g_imgadv_cntx.drm_handle = NULL;
            }
        }
        else if (g_imgadv_cntx.drm_handle  == DRM_RESULT_NO_PERMISSION)  /* file open error but not DRM related problem */
        {
            /* NOT DRM FILE */
            //ret = IMGADV_DRM_NOT_DRM_FILE;
            g_imgadv_cntx.drm_handle = NULL;
        }
        else if (g_imgadv_cntx.drm_handle  <= -1)  /* file open error but not DRM related problem */
        {
            /* NOT DRM FILE */
            ret = IMGADV_DRM_NOT_DRM_FILE;
            g_imgadv_cntx.drm_handle = NULL;
        }
    }
    return ret;    
}
#endif /* __DRM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_external_del_scr_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_imgadv_external_del_scr_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cntx.is_real_decode = MMI_FALSE;
#ifdef __DRM_SUPPORT__
    if (g_imgadv_cntx.is_rotate_action == MMI_FALSE)
    {
        mmi_imgadv_pause_drm_consume_if_need();
    }
#endif
    if (!g_imgadv_cntx.is_change_image)
    {
        g_imgadv_cntx.is_external_req = MMI_FALSE;
        if (g_imgadv_cntx.ext_filepath != NULL)
        {
            gui_free(g_imgadv_cntx.ext_filepath);
            g_imgadv_cntx.ext_filepath = NULL;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_exit_view_image_external_request
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_exit_external_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_direct_exit;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_EXIT_SCREEN);
    is_direct_exit = mmi_imgadv_is_direct_exit_state(g_imgadv_cntx.direct_exit, IMGADV_DIRECT_EXIT_VIEWSCRN_EXT);
    if (is_direct_exit)
    {
        return;
    }
    
    gdi_lcd_set_rotate_by_layer(FALSE);

#if defined(__MMI_GESTURES_FRAMEWORK__) && defined( __MMI_TOUCH_SCREEN__)
    mmi_frm_gesture_stop_listen_event();
#endif

#ifdef __MMI_TVOUT__
    gdi_image_stop_animation(g_imgadv_cntx.animation_on_tv);
    if (mdi_tvout_is_enable())
    {
        /* restore back to GDI */
        mdi_tvout_set_owner(MDI_TV_OWNER_GDI);

        /* restore back to start mode1 */
        mdi_tvout_set_mode(
            MDI_TV_MODE_LCD_SCR,
            0,  /* layer_width */
            0); /* layer_height */

    }
#endif /* __MMI_TVOUT__ */ 
    
#ifdef __DRM_SUPPORT__
    /* based on DEL SCR will be called before exit screen hdlr */
    if (g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_CONSUME)
    {
        DRM_pause_consume(g_imgadv_cntx.drm_id);
        g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_PAUSE;
    }
    else if (g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_DECODING)
    {
        DRM_close_file(g_imgadv_cntx.drm_handle);
        g_imgadv_cntx.drm_handle = NULL;
        g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_EXIT;
    }
#endif

    gdi_anim_stop_all_by_layer(g_imgadv_cntx.cache_layer_handle);

    #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
        gdi_image_nb_stop_all();
    #endif

    /* cancel timer */
    gui_cancel_timer(mmi_imgadv_start_decode);
    mmi_imgadv_cancel_decode_timer();
    
    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

#if !defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_set_alpha_blending_source_layer(g_imgadv_cntx.ivadv_org_bld_layer);
#endif

    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        gdi_lcd_set_rotate(GDI_LCD_LAYER_ROTATE_0);
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_flatten(
            g_imgadv_cntx.cache_layer_handle,
            g_imgadv_cntx.base_layer_handle,
            GDI_NULL_HANDLE,
            GDI_NULL_HANDLE);
        gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_90);
        gdi_layer_pop_and_restore_active();
        gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
        gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_0);
        gdi_layer_flatten_to_base(g_imgadv_cntx.cache_layer_handle, 0, 0, 0);
    }
    else
    {
        gdi_layer_flatten_to_base(
            g_imgadv_cntx.cache_layer_handle,
            g_imgadv_cntx.base_layer_handle,
            GDI_NULL_HANDLE,
            GDI_NULL_HANDLE);
    }

    if (g_imgadv_cntx.is_scrolling_title == TRUE)
        gui_scrolling_text_stop(&g_imgadv_cntx.scrolling_title);

    /* free buffer resource */
    mmi_imgadv_free_resource();

    /* free string resource */
    mmi_frm_scrmem_free((void*)g_imgadv_cntx.filepath);
    if (g_imgadv_cntx.is_show_filename)
    {
        mmi_frm_scrmem_free((void*)g_imgadv_cntx.buf_filename_no_ext);
    }
    g_imgadv_cntx.filepath = NULL;
    g_imgadv_cntx.buf_filename_no_ext = NULL;

    /* reset imageviewer rotation, if left normally */
    if (g_imgadv_cntx.is_reset_application == TRUE)
    {
        mmi_imgadv_reset_app();
    }    

    /* restore only base layer active */
    gdi_layer_set_blt_layer(g_imgadv_cntx.base_layer_handle, 0, 0, 0);

    /* this will force title status to redraw */
    entry_full_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_external_screen_leave_proc
 * DESCRIPTION
 *  Image view screen leave proc.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static mmi_ret mmi_imgadv_external_screen_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_SCRN_GOBACK:
        break;
    case EVT_ID_SCRN_DELETE_REQ:
        break;
    case EVT_ID_SCRN_DEINIT:
        mmi_imgadv_external_del_scr_callback(NULL);
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_view_image_external_request_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_entry_external_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8                          *guiBuffer;
    srv_fmgr_fileinfo_struct    file_info;
    CHAR*                         error_str_ptr;
    FS_HANDLE file_handle;
    MMI_BOOL entry_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imgadv_add_direct_exit_state(&g_imgadv_cntx.direct_exit, IMGADV_DIRECT_EXIT_VIEWSCRN_EXT);
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        /* currently we clear layer as black as background of small screen. */
        gdi_layer_get_base_handle(&g_imgadv_cntx.cache_layer_handle);
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);      
        gdi_layer_pop_and_restore_active();
        return;
    }

    if (!mmi_frm_is_in_backward_scenario() && !mmi_frm_group_is_present(g_imgadv_cui_gid))
    {
        mmi_frm_group_enter(g_imgadv_cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    entry_ret = mmi_frm_scrn_enter(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW_EXT, mmi_imgadv_exit_external_app_screen, mmi_imgadv_entry_external_app_screen, MMI_FRM_FULL_SCRN);
    if (!entry_ret)
    {
        return;
    }

    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);

    mmi_imgadv_remove_direct_exit_state(&g_imgadv_cntx.direct_exit, IMGADV_DIRECT_EXIT_VIEWSCRN_EXT);
    mmi_frm_scrn_close(g_imgadv_cui_gid, SCR_ID_GLOBAL_DUMMY);
    mmi_frm_scrn_set_leave_proc(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW_EXT, mmi_imgadv_external_screen_leave_proc);

    /* force all playing keypad tone off */
    //AudioStopReq(GetCurKeypadTone());

    /* entry full screen app */
    entry_full_screen();

    /* clear key events for key release event from last screen */
    ClearKeyEvents();

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    guiBuffer = mmi_frm_scrn_get_gui_buf(g_imgadv_cui_gid, SCR_ID_IMGVIEW_VIEW_EXT);

    if (guiBuffer != NULL && g_imgadv_cntx.is_real_decode == MMI_TRUE)
    {
        g_imgadv_cntx.is_resume = TRUE;
    }
    else
    {
        g_imgadv_cntx.is_resume = FALSE;
        g_imgadv_cntx.map.zoom_factor_cnt = 0;
        g_imgadv_cntx.map.max_zoom_factor_cnt= 255;
        g_imgadv_cntx.result = MMI_IMGADV_OK;
        mmi_imgadv_init_map_box();
    }

    g_imgadv_cntx.is_change_image = MMI_FALSE;
    
    g_imgadv_cntx.filepath = mmi_frm_scrmem_alloc_framebuffer(SRV_FMGR_PATH_BUFFER_SIZE);
    memset(g_imgadv_cntx.filepath, 0, SRV_FMGR_PATH_BUFFER_SIZE);
    
    mmi_ucs2cpy(g_imgadv_cntx.filepath, g_imgadv_cntx.ext_filepath);

    if (g_imgadv_cntx.is_show_filename)
    {
        g_imgadv_cntx.buf_filename_no_ext = mmi_frm_scrmem_alloc_framebuffer(SRV_FMGR_PATH_BUFFER_SIZE);
        mmi_imgadv_construct_osd_strings();
    }

    /*
     * 1. DRM permission check with filepath 
     */
    if ( mmi_imgadv_validate_drm_right() == FALSE)
    {
        return;
    }

    /*
     * 2. Check print functions 
     */
    srv_fmgr_fs_path_get_fileinfo((WCHAR*)g_imgadv_cntx.filepath, &file_info);
    if (mmi_imgview_print_enabler(&file_info) > 0
#if defined(__DRM_SUPPORT__)
    && (IMGADV_DRM_PRINT_VALID & g_imgadv_cntx.drm_valid)!=0
#endif
    )
    {
        g_imgadv_cntx.is_printable = TRUE;
    }
    else
    {
        g_imgadv_cntx.is_printable = FALSE;
    }
    
    if (g_imgadv_cntx.filepath != NULL)
    {
        file_handle = FS_Open((PU16)g_imgadv_cntx.filepath, FS_READ_ONLY);
        if (file_handle < FS_NO_ERROR)
        {
            g_imgadv_cntx.result = MMI_IMGADV_ERROR;
            g_imgadv_cntx.err_str_ptr = GetString((U16)srv_fmgr_fs_error_get_string(file_handle));
            g_imgadv_cntx.error_event = srv_fmgr_fs_error_get_popup_type(file_handle);
            mmi_imgadv_check_exit_request(file_handle, MMI_TRUE);
        }
        else
        {
            FS_Close(file_handle);
        }
    }
    /*
     * 3. Check file dimension and type 
     */
    if (g_imgadv_cntx.result >= MMI_IMGADV_OK && !mmi_fmgr_util_file_limit_check(FMGR_LIMIT_IMAGE_VIEWER, (CHAR*) g_imgadv_cntx.filepath, &error_str_ptr))
    {
        g_imgadv_cntx.err_str_ptr = error_str_ptr;
        g_imgadv_cntx.result = MMI_IMGADV_ERROR;
    }

    if (g_imgadv_cntx.result >= MMI_IMGADV_OK)
    {
        g_imgadv_cntx.image_type = gdi_image_get_type_from_file(g_imgadv_cntx.filepath);

        g_imgadv_cntx.result = gdi_image_get_dimension_file(
                                        (CHAR*) g_imgadv_cntx.filepath,
                                        &(g_imgadv_cntx.image_width),
                                        &(g_imgadv_cntx.image_height));
        if (((g_imgadv_cntx.image_width <= 0) || (g_imgadv_cntx.image_height <= 0)) ||
            g_imgadv_cntx.result < 0)
        {        
            g_imgadv_cntx.result = MMI_IMGADV_INVALID_FORMAT;
            g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_INVALID_FORMAT);
        }

        /* add image size limit for svg file type */
        if (g_imgadv_cntx.image_type==GDI_IMAGE_TYPE_SVG || g_imgadv_cntx.image_type==GDI_IMAGE_TYPE_SVG_FILE)
        {
            g_imgadv_cntx.image_width *= 3;
            g_imgadv_cntx.image_height *= 3;
        }
    }    

    /************ base layer ************/
    gdi_layer_get_base_handle(&g_imgadv_cntx.base_layer_handle);

    g_imgadv_cntx.osd_opacity = MMI_IMGADV_OSD_FADEOUT_FACTOR;
    gdi_layer_push_and_set_active(g_imgadv_cntx.base_layer_handle);
    gdi_layer_set_opacity(TRUE, (U8) g_imgadv_cntx.osd_opacity);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
      
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_0)
    {
        gdi_layer_resize(LCD_WIDTH,LCD_HEIGHT);
        gdi_lcd_set_rotate(GDI_LCD_LAYER_ROTATE_0);
    }
    else if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        gdi_layer_resize(LCD_HEIGHT,LCD_WIDTH);
        gdi_lcd_set_rotate(GDI_LCD_LAYER_ROTATE_270);
        gdi_lcd_set_rotate_by_layer(TRUE);
    }
    
    /* create resource for imageviewer */
    mmi_imgadv_create_resource(); 

#if !defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_get_alpha_blending_source_layer(&g_imgadv_cntx.ivadv_org_bld_layer);
    gdi_set_alpha_blending_source_layer(g_imgadv_cntx.cache_layer_handle);
#endif

    gdi_layer_set_blt_layer(g_imgadv_cntx.cache_layer_handle,g_imgadv_cntx.base_layer_handle,0,0);

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        /* if is fullscreen, we shall set to owner APP Owner draw, to avoid GDI's update */
        mdi_tvout_set_owner(MDI_TV_OWNER_APP);
    }
#endif /* __MMI_TVOUT__ */ 

    /* initialize osd icon */
    mmi_imgadv_init_osd_icon_position();

    /* get active osd cntx */
    mmi_imgadv_get_active_osd_cntx();

    if (g_imgadv_cntx.is_resume == FALSE)
    {
        mmi_imgadv_init_image_info();
    }
    mmi_imgadv_draw_map();

    /* for MAUI_02734333, to avoid scolling text blt a small area to LCD before image viewer blt its layers */
    gdi_layer_lock_frame_buffer();

    /* show file name */
    if (g_imgadv_cntx.is_show_filename)
    {
        mmi_imgadv_draw_title();
    }
        /* draw osd */
    mmi_imgadv_draw_external_osd();

    gdi_layer_unlock_frame_buffer();

    /* blt to lcd */
    gdi_lcd_repaint_all();

    /* clear ori key handler */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    mmi_imgadv_init_default_touch_and_key_handler();

    if (g_imgadv_cntx.is_err_displayed == TRUE) 
    {
        if (g_imgadv_cntx.result == MMI_IMGADV_OK && g_imgadv_cntx.map.max_zoom_factor_cnt != 255)
            g_imgadv_cntx.result = MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR;

        switch (g_imgadv_cntx.result)
        {
            case MMI_IMGADV_OK:
            case MMI_IMGADV_ERROR:
            case MMI_IMGADV_INVALID_FORMAT:
            case MMI_IMGADV_DRM_INVALID:
            case MMI_IMGADV_FIRST_TIME_DECODE_ERR:
                g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
                g_imgadv_cntx.map.is_zoomout_able = MMI_FALSE;
                g_imgadv_cntx.map.zoom_factor_cnt = 0;
                g_imgadv_cntx.is_external_req = MMI_TRUE;
                mmi_imgadv_draw_map();
                mmi_imgadv_draw_external_osd();
                gdi_lcd_repaint_all();
                mmi_imgadv_init_external_key_handler();
                break;
            case MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR:
                g_imgadv_cntx.is_err_displayed = MMI_FALSE;
                mmi_imgadv_draw_map();
                mmi_imgadv_draw_external_osd();
            #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
                g_imgadv_cntx.is_initialized = FALSE;
            #else
                mmi_imgadv_init_key_handler();
                mmi_imgadv_init_default_touch_and_key_handler();
            #endif           
                mmi_imgadv_extract_image_to_cache_layer();

                if (g_imgadv_cntx.result >= MMI_IMGADV_OK)
                {
                    if (g_imgadv_cntx.map.zoom_factor_cnt == g_imgadv_cntx.map.max_zoom_factor_cnt)
                    {
                        g_imgadv_cntx.map.is_zoomin_able = MMI_FALSE;
                    }
                    else
                    {
                        g_imgadv_cntx.map.is_zoomin_able = MMI_TRUE;
                    }

                    if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
                    {
                        g_imgadv_cntx.map.is_zoomout_able = MMI_TRUE;
                    }
                    else
                    {
                        g_imgadv_cntx.map.is_zoomout_able = MMI_FALSE;
                    }
                        
                    mmi_imgadv_extract_image_to_thumbnail_layer();
                }
                else
                {
                    gdi_lcd_repaint_all();
                }
            #ifdef __MMI_TVOUT__
                mmi_imgadv_tvout_clear_bg();
                mmi_imgadv_tvout_decode();
            #endif
                return;
        }
    }
    else if (g_imgadv_cntx.result < MMI_IMGADV_OK)
    {
        g_imgadv_cntx.error_event = MMI_EVENT_FAILURE;
        if (mmi_imgadv_is_direct_exit_state(g_imgadv_cntx.direct_exit, IMGADV_DIRECT_EXIT_VIEWSCRN_EXT_REQUIRE))
        {
            mmi_imgadv_display_error_sg(g_imgadv_cui_gid, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
        }
        else
        {
            mmi_imgadv_display_error_sg(g_imgadv_cui_gid, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
        }
        mmi_imgadv_remove_direct_exit_state(&g_imgadv_cntx.direct_exit, IMGADV_DIRECT_EXIT_VIEWSCRN_EXT_REQUIRE);
        return;
    }
    else
    {
        if (g_imgadv_cntx.is_resume == FALSE)
        {
            /* it will calculate roi */
            mmi_imgadv_init_image_info();
        }

        g_imgadv_cntx.is_initialized = FALSE;
        /* start timer to decode */
        gui_start_timer(10, mmi_imgadv_start_decode);
        gdi_lcd_repaint_all();
    }    

#ifdef __MMI_TVOUT__
    mmi_imgadv_tvout_clear_bg();
#endif /* __MMI_TVOUT__ */ 
}


#define MMI_IMGVIEW_CUI_APP
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_lsk_custmize_confirmed
 * DESCRIPTION
 *  Left softkey pressed to confirm the operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_lsk_custmize_confirmed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VIEW_ADV_CUI_LSK_CONFIRM, g_imgadv_cui_gid;
    evt.evt_id = EVT_ID_IMGVIEW_FILE_SELECT;
    evt.sender_id = g_imgadv_cui_gid;
    evt.size = sizeof(mmi_group_event_struct);
    mmi_frm_group_post_to_parent(g_imgadv_cui_gid, &evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_view_image_external_request
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_view_image_external_request(mmi_imgadv_external_request request)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_imgadv_cntx.ext_filepath == NULL);
    /* make sure is not error happened when enter form camco avoid the true error display from exit imageview (in imageview, no_first error will not clear if press end key exit) */
    g_imgadv_cntx.is_err_displayed = MMI_FALSE;
    g_imgadv_cntx.ext_filepath = gui_malloc(SRV_FMGR_PATH_BUFFER_SIZE);
    memset(g_imgadv_cntx.ext_filepath, 0, SRV_FMGR_PATH_BUFFER_SIZE);
    
    mmi_ucs2cpy((CHAR*) g_imgadv_cntx.ext_filepath , (CHAR*) request.filepath);
    g_imgadv_cntx.imgview_rotate = request.rotation;
    g_imgadv_cntx.is_show_filename = request.is_show_filename;
    g_imgadv_cntx.is_short = request.is_short;
    g_imgadv_cntx.is_external_req = MMI_TRUE;
    g_imgadv_cntx.is_real_decode = MMI_FALSE;

    mmi_imgadv_entry_external_app_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_set_fl_and_start_idx
 * DESCRIPTION
 *  Set filelist and start index for APP runing
 * PARAMETERS
 *  filelist           :   [IN] caller filelist.
 *  start_index        :   [IN] start index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_set_fl_and_start_idx(SRV_FMGR_FILELIST_HANDLE filelist, U32 start_index, U32 total_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VIEW_FL_IDX,g_imgview_fl_hdl,g_imgview_fl_idx,filelist,start_index);
    g_imgview_fl_hdl = filelist;
    g_imgview_fl_idx = start_index;
    g_imgadv_cntx.total_count = total_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_fetch_file_name
 * DESCRIPTION
 *  For prefetch mode to fetch file name
 * PARAMETERS
 *  filelist           :   [IN] caller filelist.
 *  start_index        :   [IN] start index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_fetch_file_name(WCHAR *path_buffer, U32 bufer_size, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_imgview_get_filename_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VIEW_FETCH,g_imgview_fl_hdl,g_imgview_fl_idx,filelist,start_index);
    evt.index = index;
    evt.path_buffer = path_buffer;
    evt.path_buffer_size = bufer_size;
    evt.evt_id = EVT_ID_IMGVIEW_GET_FILENAME;
    evt.sender_id = g_imgadv_cui_gid;
    evt.size = sizeof(cui_imgview_get_filename_event_struct);
    mmi_frm_group_send_to_parent(g_imgadv_cui_gid, (mmi_group_event_struct*)&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_prefetch_image
 * DESCRIPTION
 *  This function switch image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_prefetch_image(MMI_BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgview_cui_ptr->view_mode.total_count == 1)
    {
        return;
    }
    else
    {
        if (is_next)
        {
            g_imgview_cui_ptr->view_mode.start_index++;
            if (g_imgview_cui_ptr->view_mode.start_index >= g_imgview_cui_ptr->view_mode.total_count)
            {
                g_imgview_cui_ptr->view_mode.start_index = 0;
            }
        }
        else
        {
            if (g_imgview_cui_ptr->view_mode.start_index == 0)
            {
                g_imgview_cui_ptr->view_mode.start_index = g_imgview_cui_ptr->view_mode.total_count - 1;
            }
            else
            {
                g_imgview_cui_ptr->view_mode.start_index--;
            }
        }
    }
    mmi_imgadv_fetch_file_name((WCHAR*)g_imgview_cui_ptr->view_mode.buff_ptr, SRV_FMGR_PATH_BUFFER_SIZE, g_imgview_cui_ptr->view_mode.start_index);
}


#define MMI_IMGVIEW_CUI
extern void cui_imgview_set_filelist_config_fun(mmi_id image_viewer_id, void(*filelist_config)(SRV_FMGR_FILELIST_HANDLE filelist, U32 start_index, U32 total_count));
extern void cui_imgview_set_enter_view_fun(mmi_id image_viewer_id, void(*enter_view_screen)(void));
extern void cui_imgview_enter_before_play(mmi_id image_viewer_id);
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_app_reset
 * DESCRIPTION
 *  Reset app variable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_app_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cui_gid = GRP_ID_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_set_ui_direct
 * DESCRIPTION
 *  Set UI direction of viewing image
 * PARAMETERS
 *  image_viewer_id  :   [IN]  Image view group id.
 *  rotation               :   [IN] UI direction
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_set_ui_direct(mmi_id image_viewer_id, cui_imgview_ui_direction_enum direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (direction == CUI_IMGVIEW_UI_DIRECTION_HORIZONTAL)
    {
        g_imgadv_cntx.imgview_rotate = GDI_LCD_LAYER_ROTATE_270;
    }
    else
    {
        g_imgadv_cntx.imgview_rotate = GDI_LCD_LAYER_ROTATE_0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_enter_view_from_cui
 * DESCRIPTION
 *  View entrance for cui
 * PARAMETERS
 *  image_viewer_id  :   [IN]  Image view group id.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_enter_view_from_cui(mmi_id image_viewer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imgadv_external_request request;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cui_gid = image_viewer_id;
    /* For multi-instance, it will get itself data */
    g_imgview_cui_ptr = (cui_imgview_context_struct*)mmi_frm_group_get_user_data(g_imgadv_cui_gid);
    
    if (g_imgadv_cui_gid != g_imgview_cui_ptr->imgview_cui_gid)
    {
        MMI_ASSERT(0);
    }

    if (g_imgview_cui_ptr->cap_enable[CUI_IMGVIEW_CAP_IMG_ROTATE] ||
        g_imgview_cui_ptr->cap_enable[CUI_IMGVIEW_CAP_UI_ROTATE])
    {
        g_imgadv_cntx.rotate_able = MMI_TRUE;
    }
    else
    {
        g_imgadv_cntx.rotate_able = MMI_FALSE;
    }
    
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VIEW_FROM_CUI,g_imgadv_cui_gid,g_imgview_cui_ptr->view_mode.viewmode);
    switch (g_imgview_cui_ptr->view_mode.viewmode)
    {
        case CUI_IMGVIEW_VIEWMODE_FILENAME:
            request.filepath = g_imgview_cui_ptr->view_mode.buff_ptr;
            request.is_short = MMI_FALSE;
            request.rotation = g_imgadv_cntx.imgview_rotate;
            if (g_imgview_cui_ptr->cap_enable[CUI_IMGVIEW_CAP_FILENAME] ||
                g_imgview_cui_ptr->cap_enable[CUI_IMGVIEW_CAP_COUNTER] ||
                g_imgview_cui_ptr->cap_enable[CUI_IMGVIEW_CAP_TITLE])
            {
                request.is_show_filename = MMI_TRUE;
            }
            else
            {
                request.is_show_filename = MMI_FALSE;
            }
            mmi_imgadv_view_image_external_request(request);
            break;
        case CUI_IMGVIEW_VIEWMODE_PREFETCH:
            mmi_imgadv_fetch_file_name((WCHAR*)g_imgview_cui_ptr->view_mode.buff_ptr, SRV_FMGR_PATH_BUFFER_SIZE, g_imgview_cui_ptr->view_mode.start_index);
            mmi_imgadv_entry_app_screen();
            break;
        case CUI_IMGVIEW_VIEWMODE_FILELIST:
            g_imgadv_cntx.total_count = srv_fmgr_filelist_count(g_imgview_cui_ptr->view_mode.filelist);
            mmi_imgadv_set_fl_and_start_idx(g_imgview_cui_ptr->view_mode.filelist, g_imgview_cui_ptr->view_mode.start_index, g_imgadv_cntx.total_count);
            mmi_imgadv_entry_app_screen();
            break;
        case CUI_IMGVIEW_VIEWMODE_FILENAME_ARRAY:
            break;
        case CUI_IMGVIEW_VIEWMODE_IMAGEID_ARRAY:
            break;
        case CUI_IMGVIEW_VIEWMODE_FOLDER:
            mmi_imgadv_reset_app();
            cui_imgview_set_filelist_config_fun(g_imgadv_cui_gid, mmi_imgadv_set_fl_and_start_idx);
            cui_imgview_set_enter_view_fun(g_imgadv_cui_gid, mmi_imgadv_entry_app_screen);
            cui_imgview_enter_before_play(g_imgadv_cui_gid);
            break;
        default:
            MMI_ASSERT(0);
            break;
    }
}

#endif /* __MMI_IMAGE_VIEWER_ADV__ */

