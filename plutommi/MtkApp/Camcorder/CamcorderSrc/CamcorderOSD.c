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
 *  CamcorderOSD.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Camcorder OSD relative function
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef MMI_CAMCOOSD_C
#define MMI_CAMCOOSD_C

#include "MMI_include.h"
#ifdef __MMI_CAMCORDER__

#include "lcd_if.h"
#include "mdi_datatype.h"
#include "mdi_camera.h"
#include "mmi_features_camcorder.h"

#ifndef __MMI_CAMCO_FTE__

#include "CamcorderResDef.h"
#include "CamcorderSetting.h"
#ifndef __MMI_CAMCO_FTE__
#include "CamcorderOSD.h"
#endif 
#include "resource_camcorder_skins.h"
#include "CamcorderApp.h"
#include "app_datetime.h"
#ifdef GDI_USING_2D_ENGINE_V3
#include "gdi_2d_engine.h"
#endif 

#include "MMI_features.h"
#include "gdi_features.h"
#include "MMIDataType.h"
#include "mmi_frm_input_gprot.h"
#include "kal_general_types.h"
#include "lcd_sw_inc.h"
#include "gdi_datatype.h"
#include "g2d_enum.h"
#include "gdi_include.h"
#include "gui_windows.h"
#include "wgui_inputs.h"
#include "gdi_const.h"
#include "CustDataRes.h"
#include "mmi_rp_app_camco_def.h"
#include "gui_themes.h"
#include "gui.h"
#include "gui_data_types.h"
#include "string.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "lcd_sw_rnd.h"
#include "FileMgrSrvGProt.h"
#include "med_api.h"
#include "kal_trace.h"
#include "MMI_media_app_trc.h"
#include "mmi_media_app_trc.h"
#include "GlobalConstants.h"
#include "wgui_include.h"
#include "gui_typedef.h"
#include "ScreenRotationGprot.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "Unicodexdcl.h"
#include "gui_inputs.h"
#include "wgui_categories_inputs.h"
#include "gdi_lcd_config.h"
#include "CamcorderGprot.h"
#include "mmi_frm_mem_gprot.h"
#include "wgui_touch_screen.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS    (4)
#define MMI_CAMCO_OSD_RECORD_TIME_TIMER_SHIFT   (4)
#define MMI_CAMCO_OSD_ADD_FRAME_ARROW_SHIFT     (50)
#define MMI_CAMCO_OSD_ADD_FRAME_FILE_INDEX_SHIFT    (20)
#define MMI_CAMCO_OSD_ADD_FRAME_ARROW_OFFSET_Y      (2)
#define MMI_CAMCO_OSD_TOUCH_DUMMY_VAL   (-1)
#define MMI_CAMCO_OSD_FOCUSE_EDGE_RATIO  (20)
#define MMI_CAMCO_OSD_FACE_EDGE_RATIO  (20)

#ifdef __MMI_CAMCORDER_SLIM__
#if defined(__MMI_MAINLCD_320X480__) 
    #define __MENULIST_TITLE_WIDTH__  293
    #define __MENULIST_TITLE_HEIGHT__  43
    #define __MENULIST_HL_WIDTH__ 278
    #define __MENULIST_HL_HEIGHT__  40
    #define __MENULIST_HL_MISC_WIDTH__ 278
    #define __MENULIST_HL_MISC_HEIGHT__ 40
    #define __MENUITEM_BG_WIDTH__ 278
    #define __MENUITEM_BG_HEIGHT__ 40
#elif (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)||defined(__MMI_MAINLCD_320X240__))  
    #define __MENULIST_TITLE_WIDTH__  232
    #define __MENULIST_TITLE_HEIGHT__  30
    #define __MENULIST_HL_WIDTH__   217
    #define __MENULIST_HL_HEIGHT__  30
    #define __MENULIST_HL_MISC_WIDTH__  217
    #define __MENULIST_HL_MISC_HEIGHT__  30
    #define __MENUITEM_BG_WIDTH__  217
    #define __MENUITEM_BG_HEIGHT__ 30
#endif
#endif
/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
#if defined(__MTK_TARGET__)
#pragma arm section zidata = "NONCACHEDZI", rwdata = "NONCACHEDRW"
#endif 
mmi_camco_osd_cntx_struct g_mmi_camco_osd_cntx;
mmi_camco_osd_cntx_struct *const mmi_camco_osd_p = &g_mmi_camco_osd_cntx;
mmi_camco_skin_struct *mmi_camco_osd_skin_p = &mmi_camco_main_skin_cntx;

#if defined(__MTK_TARGET__)
#pragma arm section zidata, rwdata
#endif 
/***************************************************************************** 
 * Local Function Prototype
 *****************************************************************************/
#ifndef __MMI_ZOOM_SLIDER_BAR__
static void mmi_camco_osd_camera_zoom_in(void);
static void mmi_camco_osd_camera_zoom_in_press(void);
static void mmi_camco_osd_camera_zoom_in_release(void);
static void mmi_camco_osd_camera_zoom_out(void);
static void mmi_camco_osd_camera_zoom_out_press(void);
static void mmi_camco_osd_camera_zoom_out_release(void);
static void mmi_camco_osd_video_zoom_in(void);
static void mmi_camco_osd_video_zoom_in_press(void);
static void mmi_camco_osd_video_zoom_in_release(void);
static void mmi_camco_osd_video_zoom_out(void);
static void mmi_camco_osd_video_zoom_out_press(void);
static void mmi_camco_osd_video_zoom_out_release(void);
#else
MMI_BOOL mmi_camco_osd_is_horz_UI(void);
static void mmi_slider_draw(void);
#endif
#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
static void mmi_camco_osd_draw_reduced_progress(U16 ratio);
#endif 
static void mmi_camco_osd_draw_progress(U16 ratio);

static void mmi_camco_osd_iconlist_prev_cyclic(void);
static void mmi_camco_osd_iconlist_next_cyclic(void);
static void mmi_camco_osd_menulist_prev_cyclic(void);
static void mmi_camco_osd_menulist_next_cyclic(void);

#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
static void mmi_camco_osd_add_frame_prev_cyclic(void);
static void mmi_camco_osd_add_frame_next_cyclic(void);
#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
#ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
static void mmi_camco_osd_imgselect_prev_cyclic(void);
static void mmi_camco_osd_imgselect_next_cyclic(void);
#endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

#ifdef __MMI_TOUCH_SCREEN__
static void mmi_camco_osd_touch_pen_down_hdlr(mmi_pen_point_struct pos);
static void mmi_camco_osd_touch_pen_up_hdlr(mmi_pen_point_struct pos);
static void mmi_camco_osd_touch_pen_move_hdlr(mmi_pen_point_struct pos);
static MMI_BOOL mmi_camco_osd_touch_hit_test(S32 pos_x, S32 pos_y, mmi_camco_osd_touch_obj_struct *touch_obj);
static void mmi_camco_osd_touch_iconlist_prev_cyclic(void);
static void mmi_camco_osd_touch_iconlist_next_cyclic(void);
static void mmi_camco_osd_touch_menulist_prev_cyclic(void);
static void mmi_camco_osd_touch_menulist_next_cyclic(void);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
void mmi_camco_sublcd_osd_set_center_processing_hint_str(CHAR *str_ptr);
void mmi_camco_sublcd_osd_draw_hint_process_cyclic(void);
void mmi_camco_sublcd_osd_draw_hint(void);
static void mmi_camco_osd_sublcd_blt(void);
#endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 

static void mmi_camco_osd_draw_focus_hint_process_cyclic(void);

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
static void mmi_camco_osd_recording_setup_environment(void);
static void mmi_camco_osd_recording_reset_environment(void);


#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
static void mmi_camco_osd_sublcd_stop_hint_set_environment(void);
static void mmi_camco_osd_sublcd_stop_hint_reset_environment(void);
#endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
#ifdef __MMI_INTERACTIVE_PROFILNG__
extern MMI_BOOL mmi_frm_profiling_interactive_is_enabled(void);
#endif 
static void mmi_camco_osd_autorama_shot_setup_offset(void);
#ifdef __MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__
void mmi_camco_osd_draw_mav(void);
void mmi_camco_osd_draw_preview_center(void);
#endif

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_rotate_270_coordinate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_x     [OUT]       
 *  p_y     [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_rotate_270_coordinate(S16 *p_x, S16 *p_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 org_x = *p_x;
    S16 org_y = *p_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *p_y = LCD_WIDTH - org_x - 1;
    *p_x = org_y;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_rotate_90
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pDst            [OUT]       
 *  pSrc            [OUT]       
 *  src_width       [IN]        
 *  src_height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_rotate_90(U8 *pDst, U8 *pSrc, U32 const src_width, U32 const src_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < src_height; i++)
    {
        for (j = 0; j < src_width; j++)
        {
            *(pDst + (j * src_height * 2) + ((src_height - i - 1) * 2)) = *(pSrc++);
            *(pDst + (j * src_height * 2) + ((src_height - i - 1) * 2 + 1)) = *(pSrc++);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_rotate_for_hw_rotate
 * DESCRIPTION
 *  Rotate OSD if we have HW rotator in IDP or LCD
 *  (only supported when src/dst are same size )
 * PARAMETERS
 *  src_handle      [IN]        Srource layer handle
 *  dst_handle      [IN]        Destination layer handle
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_rotate_for_hw_rotate(gdi_handle src_handle, gdi_handle dst_handle,U8 rotate_angle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *src_ptr, *dst_ptr;
    S32 src_width, src_height;
    S32 dst_width, dst_height;
  
    gdi_color_format src_color_format = 0, dst_color_format = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(src_handle);
    gdi_layer_get_dimension(&src_width, &src_height);
    gdi_layer_get_buffer_ptr(&src_ptr);
    gdi_layer_get_color_format(&src_color_format);
    gdi_layer_pop_and_restore_active();

    gdi_layer_push_and_set_active(dst_handle);
    gdi_layer_get_dimension(&dst_width, &dst_height);
    gdi_layer_get_buffer_ptr(&dst_ptr);
    gdi_layer_get_color_format(&dst_color_format);
    gdi_layer_pop_and_restore_active();
    
    gdi_util_rotator(
        GDI_ROTATOR_DEFAULT, 
        rotate_angle, 
        src_ptr, 
        src_color_format,
        src_width,
        src_height,
        0,
        0,
        src_width,
        src_height,
        dst_ptr,
        dst_color_format,
        dst_width,
        dst_height,
        0,
        0,
        dst_width,
        dst_height);


}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_rotate_for_hw_rotate
 * DESCRIPTION
 *  Rotate OSD if we have HW rotator in IDP or LCD
 *  (only supported when src/dst are same size but only 90 degree rotated)
 * PARAMETERS
 *  src_handle      [IN]        Srource layer handle
 *  dst_handle      [IN]        Destination layer handle
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_rotate_for_hw_rotate(gdi_handle src_handle, gdi_handle dst_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef GDI_USING_2D_ENGINE_V3
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_2d_begin();
    gdi_2d_set_layer_as_dest_buffer(dst_handle);
    gdi_2d_set_layer_as_src_bitblt_buffer(src_handle);
    gdi_2d_rotate(GDI_TRANSFORM_ROTATE_90);
    gdi_2d_end();

#elif defined(MMI_CAMCO_FEATURE_ROTATE_ON)
    mdi_util_rotate_osd_for_hw_rotator(src_handle, dst_handle);
#else 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;
    S32 src_width, src_height;
    U8 *dst_p, *src_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(src_handle);
    gdi_layer_get_dimension(&src_width, &src_height);
    gdi_layer_get_buffer_ptr(&src_p);
    gdi_layer_pop_and_restore_active();

    gdi_layer_push_and_set_active(dst_handle);
    gdi_layer_get_buffer_ptr(&dst_p);
    gdi_layer_pop_and_restore_active();

    for (i = 0; i < src_height; i++)
    {
        for (j = 0; j < src_width; j++)
        {
            *(dst_p + (j * src_height * 2) + ((src_height - i - 1) * 2)) = *(src_p++);
            *(dst_p + (j * src_height * 2) + ((src_height - i - 1) * 2 + 1)) = *(src_p++);
        }
    }

#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_dummy_func
 * DESCRIPTION
 *  dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_dummy_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* empty function */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_set_mainlist_type(MMI_CAMCO_SETTING_MAINLIST_PRIMARY);
    mmi_camco_osd_p->iconlist.highlighted_idx = 0;
    mmi_camco_osd_p->add_frame.is_picked = MMI_FALSE;
#ifdef DUAL_CAMERA_SUPPORT
    if (mmi_camco_is_switching_maincamera())
    {
        mmi_camco_osd_p->add_frame.subcam_highlighted_idx = mmi_camco_osd_p->add_frame.highlighted_idx;
        mmi_camco_osd_p->add_frame.highlighted_idx = mmi_camco_osd_p->add_frame.maincam_highlighted_idx;
    }
    else if (mmi_camco_is_switching_subcamera())
    {
        mmi_camco_osd_p->add_frame.maincam_highlighted_idx = mmi_camco_osd_p->add_frame.highlighted_idx;
        mmi_camco_osd_p->add_frame.highlighted_idx = mmi_camco_osd_p->add_frame.subcam_highlighted_idx;
    }
    else
#endif /* DUAL_CAMERA_SUPPORT */ 
    {
        mmi_camco_osd_p->add_frame.highlighted_idx = 0;
        mmi_camco_osd_p->add_frame.maincam_highlighted_idx = 0;
        mmi_camco_osd_p->add_frame.subcam_highlighted_idx = 0;
    }

    //mmi_camco_setting_set_default();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_blt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_blt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF

    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {
           if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_RECORDING)
           {
               gdi_layer_blt(
                   mmi_camco_osd_p->base_layer_h,
                   mmi_camco_osd_p->video_recoding_osd.osd_layer_ev_zoom_area_h,
                   mmi_camco_osd_p->video_recoding_osd.osd_layer_rec_time_area_h,
                   mmi_camco_osd_p->video_recoding_osd.osd_layer_softkey_area_h,
                   0,
                   0,
                   LCD_WIDTH - 1,
                   LCD_HEIGHT - 1);

		   }
           else if(mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_AUTORAMA_SHOT)
           {

		       gdi_layer_blt(
                   mmi_camco_osd_p->base_layer_h,
                   mmi_camco_osd_p->autorama_cache_layer_h,
                   mmi_camco_osd_p->osd_layer_h,
	               0,
	               0,
	               0,
	               LCD_WIDTH - 1,
	               LCD_HEIGHT - 1);
		   }
	       else if(mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_HINT)
	       {
	           gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);
	           gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

	       }
	       else
	       {
	           gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
        }
    }
#ifdef DUAL_CAMERA_SUPPORT
    else
    {
        gdi_layer_blt_previous(0, 0, mmi_camco_osd_p->osd_width - 1, mmi_camco_osd_p->osd_height - 1);
    }
#endif /* DUAL_CAMERA_SUPPORT */ 
#else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
    gdi_layer_blt_previous(0, 0, mmi_camco_osd_p->osd_width - 1, mmi_camco_osd_p->osd_height - 1);
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_hint_set_mode
 * DESCRIPTION
 *  This function set hint mode (dummy in non FTE projectmmi_camco_osd_hint_set_mode).
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_hint_set_mode(mmi_cameco_osd_stop_hint_mode_enum mode)
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
 *  mmi_camco_osd_scrolling_text_stop
 * DESCRIPTION
 *  This function handles scrolling text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_scrolling_text_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->setting_menulist.is_scrolling)
    {
        gui_scrolling_text_stop(&mmi_camco_osd_p->setting_menulist.scrolling_item);
        mmi_camco_osd_p->setting_menulist.is_scrolling = MMI_FALSE;
    }

    if (mmi_camco_osd_p->option_menulist.is_scrolling)
    {
        gui_scrolling_text_stop(&mmi_camco_osd_p->option_menulist.scrolling_item);
        mmi_camco_osd_p->option_menulist.is_scrolling = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_scrolling_text_handle
 * DESCRIPTION
 *  This function handles scrolling text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_scrolling_text_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);

    gui_handle_scrolling_text(&menulist_p->scrolling_item);

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_scrolling_text_redraw_bg
 * DESCRIPTION
 *  This function clear the rect. of the scrolling text .
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_scrolling_text_redraw_bg(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;
    S32 offset_x;
    S32 offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    offset_x = menulist_p->menulist_offset_x;
    offset_y = menulist_p->menulist_offset_y;

    offset_y += menulist_p->title_height;
    offset_y += menulist_p->item_height * menulist_p->highlighted_idx;

    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);

    if (r2lMMIFlag)
    {
        gdi_image_draw_resized_id(offset_x - menulist_p->item_width + 1, menulist_p->item_width, menulist_p->item_height, offset_y, menulist_p->hilite_img_id);
    }
    else
    {
        gdi_image_draw_resized_id(offset_x, offset_y, menulist_p->item_width, menulist_p->item_height, menulist_p->hilite_img_id);
    }
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_setting_menulist_interrupt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_interrupt        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_setting_menulist_interrupt(MMI_BOOL is_interrupt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_menulist_struct *menulist_p = &mmi_camco_osd_p->setting_menulist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menulist_p->is_interrupt = is_interrupt;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_setting_menulist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_setting_menulist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width;
    S32 height;

    mmi_camco_osd_menulist_struct *menulist_p = &mmi_camco_osd_p->setting_menulist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gdi_image_get_dimension_id(IMG_ID_CAMCO_RADIO_EMPTY, &menulist_p->radio_width, &menulist_p->radio_height);
    #ifdef __MMI_CAMCORDER_SLIM__//9-slice
    menulist_p->item_width = __MENUITEM_BG_WIDTH__;
    menulist_p->item_height = __MENUITEM_BG_HEIGHT__;
    menulist_p->title_width = __MENULIST_TITLE_WIDTH__;
    menulist_p->title_height = __MENUITEM_BG_HEIGHT__;
    #else
    gdi_image_get_dimension_id(IMG_ID_CAMCO_MENUITEM_BG_1, &menulist_p->item_width, &menulist_p->item_height);
    gdi_image_get_dimension_id(IMG_ID_CAMCO_MENULIST_TITLE, &menulist_p->title_width, &menulist_p->title_height);
    #endif

    menulist_p->max_disp_item_count = mmi_camco_osd_skin_p->setting.menu_count;

    if (r2lMMIFlag)
    {
        if (menulist_p->max_disp_item_count > 3)
        {
            menulist_p->max_disp_item_count = 3;
        }
    }
    menulist_p->radio_shift_y = (menulist_p->item_height - menulist_p->radio_height) >> 1;
    menulist_p->radio_shift_x = menulist_p->radio_shift_y;

    /* icon position */
    gdi_image_get_dimension_id(IMG_ID_CAMCO_REF_STATUS_ICON_SIZE, &width, &height);
    menulist_p->item_img_shift_y = (menulist_p->item_height - height) >> 1;
    menulist_p->item_img_shift_x = menulist_p->item_width - menulist_p->item_img_shift_y - width;

    menulist_p->touch_down_highlighted_idx = 0;
    menulist_p->touch_up_highlighted_idx = 0;
    menulist_p->is_scrolling = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_gen_setting_menulist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_gen_setting_menulist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 remained;
    S32 str_width;
    S32 str_height;
    U16 i;
    mmi_camco_osd_menulist_struct *menulist_p;
    U16 prev_item_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_medium_font);

    mmi_camco_osd_p->act_menulist_p = &mmi_camco_osd_p->setting_menulist;
    menulist_p = mmi_camco_osd_p->act_menulist_p;

    /* shall gen setting item list first, otherwise will have no data */

    if (menulist_p->is_interrupt)
    {
        prev_item_count = menulist_p->item_count;
    }

    menulist_p->item_count = mmi_camco_setting_get_itemlist_count();
    menulist_p->state = MMI_CAMCO_OSD_MENULIST_STATE_EXIT;
    #ifndef __MMI_FTE_SUPPORT__
    if (mmi_camco_setting_get_mainlist_type() == MMI_CAMCO_SETTING_MAINLIST_PRIMARY)
    {
        menulist_p->hilite_img_id = IMG_ID_CAMCO_MENUITEM_HL_MAIN;
    }
    else
    #endif
    {
        menulist_p->hilite_img_id = IMG_ID_CAMCO_MENUITEM_HL_MISC;
    }

    /* get title str */
    mmi_camco_setting_get_cur_main_title(&menulist_p->title_str_id);
    gui_measure_string((UI_string_type) GetString(menulist_p->title_str_id), &str_width, &str_height);
    menulist_p->title_str_shift_x = (menulist_p->title_width - str_width) >> 1;
    menulist_p->title_str_shift_y = (menulist_p->title_height - str_height) >> 1;

    menulist_p->active_idx = mmi_camco_setting_get_itemlist_idx();

    if (!menulist_p->is_interrupt)
    {
        menulist_p->highlighted_idx = mmi_camco_setting_get_itemlist_idx();
        if (menulist_p->max_disp_item_count >= menulist_p->item_count)
        {
            /* menu item count did not excced display limit */
            menulist_p->disp_item_count = menulist_p->item_count;
            menulist_p->first_disp_idx = 0;
        }
        else
        {
            menulist_p->disp_item_count = menulist_p->max_disp_item_count;

            remained = menulist_p->item_count - menulist_p->highlighted_idx;

            if (remained < menulist_p->disp_item_count)
            {
                menulist_p->first_disp_idx = menulist_p->item_count - menulist_p->disp_item_count;

                if (menulist_p->first_disp_idx < 0)
                {
                    menulist_p->first_disp_idx = 0;
                }
            }
            else
            {
                menulist_p->first_disp_idx = menulist_p->highlighted_idx;
            }
        }

    }
    else
    {
        menulist_p->is_interrupt = MMI_FALSE;

        if (menulist_p->item_count != prev_item_count)
        {
            if (prev_item_count > menulist_p->item_count)
            {
                if (menulist_p->highlighted_idx > menulist_p->item_count - 1)
                {
                    menulist_p->highlighted_idx = mmi_camco_setting_get_itemlist_idx();
                }
            }

            if (menulist_p->max_disp_item_count >= menulist_p->item_count)
            {
                /* menu item count did not excced display limit */
                menulist_p->disp_item_count = menulist_p->item_count;
                menulist_p->first_disp_idx = 0;
            }
            else
            {
                menulist_p->disp_item_count = menulist_p->max_disp_item_count;

                remained = menulist_p->item_count - menulist_p->highlighted_idx;

                if (remained < menulist_p->disp_item_count)
                {
                    menulist_p->first_disp_idx = menulist_p->item_count - menulist_p->disp_item_count;

                    if (menulist_p->first_disp_idx < 0)
                    {
                        menulist_p->first_disp_idx = 0;
                    }
                }
                else
                {
                    menulist_p->first_disp_idx = menulist_p->highlighted_idx;
                }
            }
        }

        mmi_camco_setting_set_cur_item_idx(menulist_p->highlighted_idx);
        if (mmi_camco_is_preview() && (mmi_camco_setting_get_mainlist_setting() != MMI_CAMCO_SETTING_SHUTTERSOUND))
        {
            mmi_camco_setting_item_hilite_hdlr();
        }
    }
    /* get all item data (img, str) */
    for (i = 0; i < menulist_p->item_count; i++)
    {
        mmi_camco_setting_get_item_resource(
            mmi_camco_setting_get_itemlist_value(i),
            &menulist_p->item_list[i].str_id,
            &menulist_p->item_list[i].status_img_id);

        if (mmi_camco_setting_is_main_show_radio())
        {
            if (i == menulist_p->active_idx)
            {
                menulist_p->item_list[i].radio_img_id = IMG_ID_CAMCO_RADIO_FULL;
            }
            else
            {
                menulist_p->item_list[i].radio_img_id = IMG_ID_CAMCO_RADIO_EMPTY;
            }
        }
        else
        {
            menulist_p->item_list[i].radio_img_id = 0;
        }

    }

    /* calc string position */
    if (menulist_p->item_list[0].str_id != 0)
    {
        gui_measure_string((UI_string_type) GetString(menulist_p->item_list[0].str_id), &str_width, &str_height);
        menulist_p->item_str_shift_y = (menulist_p->item_height - str_height) >> 1;

        if (mmi_camco_setting_is_main_show_radio())
        {
            menulist_p->item_str_shift_x =
                menulist_p->radio_width + menulist_p->radio_shift_x + menulist_p->item_str_shift_y;
        }
        else
        {
            menulist_p->item_str_shift_x = menulist_p->item_str_shift_y;
        }
    }

    /* cal left top position */
    /* the position in mmi_camco_osd_skin_p->setting is bottom left corner */
    menulist_p->menulist_offset_x = mmi_camco_osd_skin_p->setting.menulist.offset_x;
    menulist_p->menulist_offset_y = mmi_camco_osd_skin_p->setting.menulist.offset_y;
    menulist_p->menulist_offset_y -= menulist_p->disp_item_count * menulist_p->item_height;
    menulist_p->menulist_offset_y -= menulist_p->title_height;

    if (r2lMMIFlag)
    {
        menulist_p->menulist_offset_x = mmi_camco_osd_p->osd_width - menulist_p->menulist_offset_x - 1;
    }

    /* touch */
    if (r2lMMIFlag)
    {
        menulist_p->list_touch.offset_x = menulist_p->menulist_offset_x - menulist_p->item_width + 1;
    }
    else
    {
        menulist_p->list_touch.offset_x = menulist_p->menulist_offset_x;
    }
    menulist_p->list_touch.offset_y = menulist_p->menulist_offset_y + menulist_p->title_height;
    menulist_p->list_touch.width = menulist_p->item_width;
    menulist_p->list_touch.height = menulist_p->item_height * menulist_p->disp_item_count;

    menulist_p->list_up_touch.offset_x = menulist_p->list_touch.offset_x;
    menulist_p->list_up_touch.offset_y = 0;
    menulist_p->list_up_touch.width = menulist_p->list_touch.width;
    menulist_p->list_up_touch.height = menulist_p->menulist_offset_y + menulist_p->title_height;

    menulist_p->list_down_touch.offset_x = menulist_p->list_touch.offset_x;
    menulist_p->list_down_touch.offset_y = mmi_camco_osd_skin_p->setting.menulist.offset_y;
    menulist_p->list_down_touch.width = menulist_p->list_touch.width;
    menulist_p->list_down_touch.height = mmi_camco_osd_p->osd_height - mmi_camco_osd_skin_p->setting.menulist.offset_y;

    /* gen scrollbar */
    mmi_camco_osd_gen_scrollbar();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_menulist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_draw_menulist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 i;
    S32 bg_idx;
    S32 str_width;
    S32 str_height;

    mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_medium_font);

    mmi_camco_osd_scrolling_text_stop();
    gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);

    /* draw title bg */
    offset_x = menulist_p->menulist_offset_x;
    offset_y = menulist_p->menulist_offset_y;

    if (r2lMMIFlag)
    {
        gdi_image_draw_resized_id(offset_x - menulist_p->title_width + 1,offset_y,menulist_p->title_width,menulist_p->title_height,  IMG_ID_CAMCO_MENULIST_TITLE);
    }
    else
    {
        gdi_image_draw_resized_id(offset_x, offset_y,menulist_p->title_width,menulist_p->title_height, IMG_ID_CAMCO_MENULIST_TITLE);
    }

    /* draw title str */
    gui_set_text_color(gui_color(255, 255, 255));
    gui_set_text_border_color(gui_color(0, 0, 0));
    gui_measure_string((UI_string_type) GetString(menulist_p->title_str_id), &str_width, &str_height);
    
    if (str_width > menulist_p->title_width - 3)
    {
        if (r2lMMIFlag)
        {
            gui_print_truncated_text(
                offset_x - menulist_p->title_str_shift_x,
                offset_y + menulist_p->title_str_shift_y,
                menulist_p->title_width - 3,
                (UI_string_type) GetString(menulist_p->title_str_id));
        }
        else
        {
            gui_print_truncated_text(
                offset_x + menulist_p->title_str_shift_x,
                offset_y + menulist_p->title_str_shift_y,
                menulist_p->title_width - 3,
                (UI_string_type) GetString(menulist_p->title_str_id));
        }
    }
    else
    {
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(offset_x - menulist_p->title_str_shift_x, offset_y + menulist_p->title_str_shift_y);
        }
        else
        {
            gui_move_text_cursor(offset_x + menulist_p->title_str_shift_x, offset_y + menulist_p->title_str_shift_y);
        }
        gui_print_text((UI_string_type) GetString(menulist_p->title_str_id));
    }
    
    offset_y += menulist_p->title_height;
    bg_idx = 0;

    /* draw item */
    for (i = menulist_p->first_disp_idx; i < menulist_p->first_disp_idx + menulist_p->disp_item_count; i++)
    {
        if (r2lMMIFlag)
        {
            gdi_image_draw_resized_id(
                offset_x - menulist_p->item_width + 1,
                offset_y,menulist_p->item_width,menulist_p->item_height,
                (MMI_ID_TYPE) (IMG_ID_CAMCO_MENUITEM_BG_1));
        }
        else
        {
            gdi_image_draw_resized_id(offset_x, offset_y, menulist_p->item_width ,menulist_p->item_height,(MMI_ID_TYPE) (IMG_ID_CAMCO_MENUITEM_BG_1));
        }
        bg_idx++;

        /* draw highlight bar */
        if (i == menulist_p->highlighted_idx)
        {
            if (r2lMMIFlag)
            {
                gdi_image_draw_resized_id(offset_x - menulist_p->item_width + 1,offset_y, menulist_p->item_width,menulist_p->item_height, menulist_p->hilite_img_id);
            }
            else
            {
                gdi_image_draw_resized_id(offset_x, offset_y,menulist_p->item_width,menulist_p->item_height, menulist_p->hilite_img_id);
            }
        }

        if (menulist_p->item_list[i].radio_img_id != 0)
        {
            if (r2lMMIFlag)
            {
                gdi_image_draw_id(
                    offset_x - menulist_p->radio_shift_x - menulist_p->radio_width + 1,
                    offset_y + menulist_p->radio_shift_y,
                    menulist_p->item_list[i].radio_img_id);

            }
            else
            {
                gdi_image_draw_id(
                    offset_x + menulist_p->radio_shift_x,
                    offset_y + menulist_p->radio_shift_y,
                    menulist_p->item_list[i].radio_img_id);
            }
        }

        /* draw string */
        gui_measure_string((UI_string_type) GetString(menulist_p->item_list[i].str_id), &str_width, &str_height);
        menulist_p->item_str_shift_y = (menulist_p->item_height - str_height) >> 1;

        if (i == menulist_p->highlighted_idx &&
            str_width > (menulist_p->item_width - menulist_p->item_str_shift_x) + 10 &&
            mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_OPTION_MENU)
        {
            S32 r2l_offset_x;

            r2l_offset_x = menulist_p->menulist_offset_x - menulist_p->item_width;

            if (r2lMMIFlag)
            {
                gui_create_scrolling_text(
                    &menulist_p->scrolling_item,
                    r2l_offset_x + menulist_p->item_str_shift_x,
                    offset_y + menulist_p->item_str_shift_y,
                    menulist_p->item_width - menulist_p->item_str_shift_x - 1,
                    menulist_p->item_height,
                    (UI_string_type) GetString(menulist_p->item_list[i].str_id),
                    mmi_camco_osd_scrolling_text_handle,
                    mmi_camco_osd_scrolling_text_redraw_bg,
                    gui_color(234, 251, 255),
                    gui_color(56, 80, 112));
            }
            else
            {
                gui_create_scrolling_text(
                    &menulist_p->scrolling_item,
                    offset_x + menulist_p->item_str_shift_x,
                    offset_y + menulist_p->item_str_shift_y,
                    menulist_p->item_width - menulist_p->item_str_shift_x - 1,
                    menulist_p->item_height,
                    (UI_string_type) GetString(menulist_p->item_list[i].str_id),
                    mmi_camco_osd_scrolling_text_handle,
                    mmi_camco_osd_scrolling_text_redraw_bg,
                    gui_color(234, 251, 255),
                    gui_color(56, 80, 112));
            }
            mmi_camco_osd_p->act_menulist_p->is_scrolling = MMI_TRUE;
            gui_show_scrolling_text(&menulist_p->scrolling_item);
        }
        else if (str_width > (menulist_p->item_width - menulist_p->item_str_shift_x))
        {
            if (r2lMMIFlag)
            {
                gui_print_truncated_text(
                    offset_x - menulist_p->item_str_shift_x,
                    offset_y + menulist_p->item_str_shift_y,
                    menulist_p->item_width - menulist_p->item_str_shift_x - 1,
                    (UI_string_type) GetString(menulist_p->item_list[i].str_id));
            }
            else
            {
                gui_print_truncated_text(
                    offset_x + menulist_p->item_str_shift_x,
                    offset_y + menulist_p->item_str_shift_y,
                    menulist_p->item_width - menulist_p->item_str_shift_x - 1,
                    (UI_string_type) GetString(menulist_p->item_list[i].str_id));
            }
        }
        else
        {
            if (r2lMMIFlag)
            {
                gui_move_text_cursor(offset_x - menulist_p->item_str_shift_x, offset_y + menulist_p->item_str_shift_y);
            }
            else
            {
                gui_move_text_cursor(offset_x + menulist_p->item_str_shift_x, offset_y + menulist_p->item_str_shift_y);
            }

            gui_set_text_color(gui_color(234, 251, 255));
			gui_set_text_border_color(gui_color(56,80,112));
            gui_print_bordered_text((UI_string_type) GetString(menulist_p->item_list[i].str_id));
        }
        /* draw icon */
        if (menulist_p->item_list[i].status_img_id != 0)
        {
            if (r2lMMIFlag)
            {
                S32 width = 0;
                S32 height = 0;

                gdi_image_get_dimension_id(IMG_ID_CAMCO_REF_STATUS_ICON_SIZE, &width, &height);
                gdi_image_draw_id(
                    offset_x - menulist_p->item_img_shift_x - width + 1,
                    offset_y + menulist_p->item_img_shift_y,
                    menulist_p->item_list[i].status_img_id);

            }
            else
            {
                gdi_image_draw_id(
                    offset_x + menulist_p->item_img_shift_x,
                    offset_y + menulist_p->item_img_shift_y,
                    menulist_p->item_list[i].status_img_id);
            }
        }

        offset_y += menulist_p->item_height;
    }

	gdi_pop_and_restore_alpha_blending_source_layer();
    /* draw scrollbar */
    mmi_camco_osd_draw_scrollbar();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_menulist_move_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_menulist_move_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menulist_p->highlighted_idx < menulist_p->item_count - 1)
    {
        menulist_p->highlighted_idx++;

        if (menulist_p->highlighted_idx < menulist_p->first_disp_idx + menulist_p->disp_item_count)
        {
            /* within same page, do nothing */
        }
        else
        {
            menulist_p->first_disp_idx++;

            /* update scrollbar */
            mmi_camco_osd_update_scrollbar();
        }

        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_OPTION_MENU
            || mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION
            || mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION)
        {
            mmi_camco_set_option_menulist_highlight_idx(menulist_p->highlighted_idx);
        }
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_menulist_move_prev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_menulist_move_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menulist_p->highlighted_idx > 0)
    {
        menulist_p->highlighted_idx--;

        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_OPTION_MENU
            || mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION
            || mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION)
        {
            mmi_camco_set_option_menulist_highlight_idx(menulist_p->highlighted_idx);
        }

        if (menulist_p->highlighted_idx >= menulist_p->first_disp_idx)
        {
            /* within same page, do nothing */
        }
        else
        {
            menulist_p->first_disp_idx--;

            /* update scrollbar */
            mmi_camco_osd_update_scrollbar();
        }

        return MMI_TRUE;

    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_menulist_idx_from_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos_y       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_camco_osd_get_menulist_idx_from_pos(S32 pos_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;
    S32 offset_y;
    S32 height;
    S32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get menulist start pos */
    offset_y = menulist_p->menulist_offset_y + menulist_p->title_height;

    height = pos_y - offset_y;
    idx = height / menulist_p->item_height;
    idx += menulist_p->first_disp_idx;

    if (idx > menulist_p->item_count - 1)
    {
        idx = menulist_p->item_count - 1;
    }

    return (U16) idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_iconlist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_init_iconlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    iconlist_p->iconlist_offset_x = mmi_camco_osd_skin_p->setting.iconlist.offset_x;
    iconlist_p->iconlist_offset_y = mmi_camco_osd_skin_p->setting.iconlist.offset_y;
    iconlist_p->disp_icon_count = mmi_camco_osd_skin_p->setting.icon_count;

    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        gdi_image_get_dimension_id(IMG_ID_CAMCO_ICONLIST_LA, &iconlist_p->la_touch.width, &iconlist_p->la_touch.height);
        gdi_image_get_dimension_id(IMG_ID_CAMCO_ICONLIST_RA, &iconlist_p->ra_touch.width, &iconlist_p->ra_touch.height);
    }
#ifdef DUAL_CAMERA_SUPPORT
    else
    {
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_SUBCAM_ICONLIST_LA,
            &iconlist_p->la_touch.width,
            &iconlist_p->la_touch.height);
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_SUBCAM_ICONLIST_RA,
            &iconlist_p->ra_touch.width,
            &iconlist_p->ra_touch.height);
    }
#endif /* DUAL_CAMERA_SUPPORT */ 
    gdi_image_get_dimension_id(IMG_ID_CAMCO_REF_MAIN_ICON_SIZE, &iconlist_p->icon_width, &iconlist_p->icon_height);

    iconlist_p->la_touch.offset_x = iconlist_p->iconlist_offset_x;
    iconlist_p->la_touch.offset_y = iconlist_p->iconlist_offset_y;
    iconlist_p->la_touch.is_press = MMI_FALSE;

    iconlist_p->ra_touch.offset_x =
        iconlist_p->la_touch.offset_x +
        iconlist_p->la_touch.width + (iconlist_p->disp_icon_count * iconlist_p->icon_width);

    iconlist_p->ra_touch.offset_y = iconlist_p->iconlist_offset_y;
    iconlist_p->ra_touch.is_press = MMI_FALSE;

    iconlist_p->list_touch.offset_x = iconlist_p->la_touch.offset_x + iconlist_p->la_touch.width;
    iconlist_p->list_touch.offset_y = iconlist_p->la_touch.offset_y;
    iconlist_p->list_touch.height = iconlist_p->icon_height;
    iconlist_p->list_touch.width = iconlist_p->icon_width * iconlist_p->disp_icon_count;
    iconlist_p->list_touch.is_press = MMI_FALSE;

    iconlist_p->touch_down_highlighted_idx = 0;
    iconlist_p->touch_up_highlighted_idx = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_gen_iconlist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_gen_iconlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 remained;
    U16 i;

    mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* shall gen setting item list first, otherwise will have no data */

    iconlist_p->icon_count = mmi_camco_setting_get_mainlist_count();
    iconlist_p->state = MMI_CAMCO_OSD_ICONLIST_STATE_EXIT;
    iconlist_p->highlighted_idx = mmi_camco_setting_get_mainlist_idx();
    iconlist_p->list_touch.width = iconlist_p->icon_width * iconlist_p->disp_icon_count;

    remained = iconlist_p->icon_count - iconlist_p->highlighted_idx;

    if (remained < iconlist_p->disp_icon_count)
    {
        iconlist_p->first_disp_idx = iconlist_p->icon_count - iconlist_p->disp_icon_count;

        if (iconlist_p->first_disp_idx < 0)
        {
            iconlist_p->first_disp_idx = 0;
            iconlist_p->list_touch.width = iconlist_p->icon_width * iconlist_p->icon_count;
        }
    }
    else
    {
        iconlist_p->first_disp_idx = iconlist_p->highlighted_idx;
    }

    /* get all item data (img, str) */
    for (i = 0; i < iconlist_p->icon_count; i++)
    {
        mmi_camco_setting_get_main_resource(
            i,
            &iconlist_p->icon_list[i].str_id,
            &iconlist_p->icon_list[i].img_id,
            NULL,
            NULL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_iconlist_highlight_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_iconlist_highlight_idx(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->iconlist.highlighted_idx = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_iconlist_highlight_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  index               [OUT]
 *****************************************************************************/
extern U16 mmi_camco_osd_get_iconlist_highlight_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->iconlist.highlighted_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_iconlist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_draw_iconlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    U16 i;
    #ifdef __MMI_CAMCORDER_SLIM__
    S32 offset_x_icon;
    S32 offset_y_icon;
    S32 width_bg = 0;
    S32 height_bg = 0;
    S32 width_icon = 0;
    S32 height_icon = 0;
    #endif
    mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;
    U32 la_empty = IMG_ID_CAMCO_ICONLIST_LA_EMPTY;
    U32 la_sel = IMG_ID_CAMCO_ICONLIST_LA_SEL;
    U32 la = IMG_ID_CAMCO_ICONLIST_LA;
    U32 ra_empty = IMG_ID_CAMCO_ICONLIST_RA_EMPTY;
    U32 ra_sel = IMG_ID_CAMCO_ICONLIST_RA_SEL;
    U32 ra = IMG_ID_CAMCO_ICONLIST_RA;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    offset_x = iconlist_p->iconlist_offset_x;
    offset_y = iconlist_p->iconlist_offset_y;

    gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        la_empty = IMG_ID_CAMCO_ICONLIST_LA_EMPTY;
        la_sel = IMG_ID_CAMCO_ICONLIST_LA_SEL;
        la = IMG_ID_CAMCO_ICONLIST_LA;
        ra_empty = IMG_ID_CAMCO_ICONLIST_RA_EMPTY;
        ra_sel = IMG_ID_CAMCO_ICONLIST_RA_SEL;
        ra = IMG_ID_CAMCO_ICONLIST_RA;
    }
#ifdef DUAL_CAMERA_SUPPORT
    else
    {
        la_empty = IMG_ID_CAMCO_SUBCAM_ICONLIST_LA_EMPTY;
        la_sel = IMG_ID_CAMCO_SUBCAM_ICONLIST_LA_SEL;
        la = IMG_ID_CAMCO_SUBCAM_ICONLIST_LA;
        ra_empty = IMG_ID_CAMCO_SUBCAM_ICONLIST_RA_EMPTY;
        ra_sel = IMG_ID_CAMCO_SUBCAM_ICONLIST_RA_SEL;
        ra = IMG_ID_CAMCO_SUBCAM_ICONLIST_RA;
    }
#endif /* DUAL_CAMERA_SUPPORT */ 
    /* draw left arrow */
    if (iconlist_p->highlighted_idx == 0)
    {
        /* select on first icon, no need draw la */
        gdi_image_draw_id(offset_x, offset_y, la_empty);

    }
    else
    {
        if (mmi_camco_osd_p->iconlist.la_touch.is_press)
        {
            gdi_image_draw_id(offset_x, offset_y, la_sel);
        }
        else
        {
            gdi_image_draw_id(offset_x, offset_y, la);
        }
    }

    offset_x += iconlist_p->la_touch.width;

    /* draw icon */
        for (i = iconlist_p->first_disp_idx; i < iconlist_p->first_disp_idx + iconlist_p->disp_icon_count; i++)
        {   
            #ifdef __MMI_CAMCORDER_SLIM__
                gdi_image_get_dimension_id(IMG_ID_CAMCO_HIGHLIGHT_BG,&width_bg,&height_bg);
                gdi_image_get_dimension_id((MMI_ID_TYPE) (iconlist_p->icon_list[i].img_id),&width_icon,&height_icon);
                offset_x_icon = (width_bg - width_icon)/2; 
                offset_y_icon = (height_bg - height_icon)/2;
            #endif
            if (i == iconlist_p->highlighted_idx)
            {
                #ifdef __MMI_CAMCORDER_SLIM__
                /* selected */
                gdi_image_draw_id(offset_x,offset_y,IMG_ID_CAMCO_HIGHLIGHT_BG);
                gdi_image_draw_id(offset_x + offset_x_icon , offset_y + offset_y_icon, (MMI_ID_TYPE) (iconlist_p->icon_list[i].img_id));
                #else
                gdi_image_draw_id(offset_x , offset_y , (MMI_ID_TYPE) (iconlist_p->icon_list[i].img_id+1));            
                #endif
            
            }
            else
            {
                if (i > iconlist_p->icon_count - 1)
                {
                    #ifndef __MMI_CAMCORDER_SLIM__
                        gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMCO_EMPTY_MAIN_ICON);
                    #else
                        gdi_image_draw_id(offset_x,offset_y,IMG_ID_CAMCO_NORMAL_BG);
                    #endif
                }
                else
                {   
                    #ifdef __MMI_CAMCORDER_SLIM__
                        gdi_image_draw_id(offset_x,offset_y,IMG_ID_CAMCO_NORMAL_BG);
                        gdi_image_draw_id(offset_x + offset_x_icon, offset_y + offset_y_icon, (MMI_ID_TYPE) (iconlist_p->icon_list[i].img_id));
                    #else
                        gdi_image_draw_id(offset_x , offset_y , (MMI_ID_TYPE) (iconlist_p->icon_list[i].img_id));
                    #endif



                }
            }
    
            offset_x += iconlist_p->icon_width;
        }
    
        /* draw left arrow */
        if (iconlist_p->highlighted_idx == iconlist_p->icon_count - 1)
        {
            /* select on last icon, no need draw ra */
            gdi_image_draw_id(offset_x, offset_y, ra_empty);
    
        }
        else
        {
            if (mmi_camco_osd_p->iconlist.ra_touch.is_press)
            {
                gdi_image_draw_id(offset_x, offset_y, ra_sel);
            }
            else
            {
                gdi_image_draw_id(offset_x, offset_y, ra);
            }
        }
        gdi_pop_and_restore_alpha_blending_source_layer();
    
    }


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_iconlist_move_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_iconlist_move_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (iconlist_p->highlighted_idx < iconlist_p->icon_count - 1)
    {
        iconlist_p->highlighted_idx++;

        if (iconlist_p->highlighted_idx < iconlist_p->first_disp_idx + iconlist_p->disp_icon_count)
        {
            /* within same page, do nothing */
        }
        else
        {
            iconlist_p->first_disp_idx++;
        }

        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_iconlist_move_prev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_iconlist_move_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (iconlist_p->highlighted_idx > 0)
    {
        iconlist_p->highlighted_idx--;

        if (iconlist_p->highlighted_idx >= iconlist_p->first_disp_idx)
        {
            /* within same page, do nothing */
        }
        else
        {
            iconlist_p->first_disp_idx--;
        }

        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_imgselect_move_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_imgselect_move_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imgselect_cache_p->highlighted_idx < imgselect_cache_p->img_count - 1)
    {
        imgselect_cache_p->highlighted_idx++;

        if (imgselect_cache_p->highlighted_idx <
            imgselect_cache_p->first_disp_idx + imgselect_cache_p->disp_cache_count)
        {
            /* within same page, do nothing */
        }
        else
        {
            imgselect_cache_p->first_disp_idx++;
        }

        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_imgselect_move_prev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_imgselect_move_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imgselect_cache_p->highlighted_idx > 0)
    {
        imgselect_cache_p->highlighted_idx--;

        if (imgselect_cache_p->highlighted_idx >= imgselect_cache_p->first_disp_idx)
        {
            /* within same page, do nothing */
        }
        else
        {
            imgselect_cache_p->first_disp_idx--;
        }

        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_add_frame_move_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_add_frame_move_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (add_frame_p->highlighted_idx < add_frame_p->frame_count - 1)
    {
        add_frame_p->highlighted_idx++;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_add_frame_move_prev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_add_frame_move_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (add_frame_p->highlighted_idx > 0)
    {
        add_frame_p->highlighted_idx--;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_iconlist_idx_from_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos_x       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_camco_osd_get_iconlist_idx_from_pos(S32 pos_x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;
    S32 offset_x;
    S32 width;
    S32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get iconlist start pos */
    offset_x = iconlist_p->iconlist_offset_x + iconlist_p->la_touch.width;

    width = pos_x - offset_x;
    idx = width / iconlist_p->icon_width;
    idx += iconlist_p->first_disp_idx;

    return (U16) idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_gen_camera_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_gen_camera_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    MMI_ID_TYPE img_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mmi_camco_osd_p->status_icon, 0, sizeof(mmi_camco_osd_p->status_icon));

    /* get setting values */
#define CAMCO_OSD_GEN_CAMERA_STATUS_ICON(__X__,__x__)                                                         \
    img_id = mmi_camco_setting_get_setting_icon(MMI_CAMCO_SETTING_##__X__##);                                 \
    if (img_id != 0)                                                                                          \
    {                                                                                                         \
        mmi_camco_osd_p->status_icon[idx].img_id = img_id;                                                    \
        mmi_camco_osd_p->status_icon[idx].offset_x                                                            \
            = mmi_camco_osd_skin_p->camera_preview.##__x__##.offset_x;                                        \
        mmi_camco_osd_p->status_icon[idx].offset_y                                                            \
            = mmi_camco_osd_skin_p->camera_preview.##__x__##.offset_y;                                        \
        idx++;                                                                                                \
    }

#define CAMCO_OSD_GEN_CAMERA_STATUS_ICON_WITH_CAP(__X__,__x__)                                                 \
    img_id = 0;                                                                                                \
    if (mmi_camco_setting_get_setting_capability(MMI_CAMCO_SETTING_##__X__##) == MMI_CAMCO_SETTING_CAP_ENABLED)\
    {                                                                                                          \
        img_id = mmi_camco_setting_get_setting_icon(MMI_CAMCO_SETTING_##__X__##);                              \
    }                                                                                                          \
    if (img_id != 0)                                                                                           \
    {                                                                                                          \
        mmi_camco_osd_p->status_icon[idx].img_id = img_id;                                                     \
        mmi_camco_osd_p->status_icon[idx].offset_x                                                             \
            = mmi_camco_osd_skin_p->camera_preview.##__x__##.offset_x;                                         \
        mmi_camco_osd_p->status_icon[idx].offset_y                                                             \
            = mmi_camco_osd_skin_p->camera_preview.##__x__##.offset_y;                                         \
        idx++;                                                                                                 \
    }

    CAMCO_OSD_GEN_CAMERA_STATUS_ICON_WITH_CAP(CAPMODE, capmode);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(CAMSCENEMODE, camscenemode);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(CAPSIZE, capsize);

    if (mmi_camco_get_flash_type() == MMI_CAMCO_FLASH_TYPE_LED &&
        mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) != MMI_CAMCO_CAPMODE_EV_BRACKET_SEL &&
        mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) != MMI_CAMCO_CAPMODE_SMILE_SHOT&&        
        mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) != MMI_CAMCO_CAPMODE_HDR_SHOT &&          
        mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) != MMI_CAMCO_CAPMODE_AUTORAMA)
    {
        CAMCO_OSD_GEN_CAMERA_STATUS_ICON(FLASH, flash);
    }
    else if (mmi_camco_get_flash_type() == MMI_CAMCO_FLASH_TYPE_XENON &&
             (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_NORMAL ||
#ifdef __SMILE_SHUTTER_SUPPORT__
              mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_SMILE_SHOT ||
#endif 
              mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_ADD_FRAME))
    {
        CAMCO_OSD_GEN_CAMERA_STATUS_ICON(FLASH, flash);
    }

    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(AFRANGE, afrange);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(ISO, iso);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(WB, wb);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(STORAGE, storage);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON_WITH_CAP(CAPQTY, capqty);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(AEMETER, aemeter);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON_WITH_CAP(TIMESTAMP, timestamp);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON_WITH_CAP(SELFTIMER, selftimer);
    if(mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_ASD_SHOT)
    {
        CAMCO_OSD_GEN_CAMERA_STATUS_ICON_WITH_CAP(FACEDETECT, facedetect);
    }
    else
    {
        CAMCO_OSD_GEN_CAMERA_STATUS_ICON(FACEDETECT, facedetect);
    }
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(HIGHLIGHT, highlight);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_gen_video_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_gen_video_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    MMI_ID_TYPE img_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mmi_camco_osd_p->status_icon, 0, sizeof(mmi_camco_osd_p->status_icon));

    /* get setting values */
#define CAMCO_OSD_GEN_VIDEO_STATUS_ICON(__X__,__x__)                                                          \
    img_id = mmi_camco_setting_get_setting_icon(MMI_CAMCO_SETTING_##__X__##);                                 \
    if (img_id != 0)                                                                                          \
    {                                                                                                         \
        mmi_camco_osd_p->status_icon[idx].img_id = img_id;                                                    \
        mmi_camco_osd_p->status_icon[idx].offset_x                                                            \
            = mmi_camco_osd_skin_p->video_preview.##__x__##.offset_x;                                         \
        mmi_camco_osd_p->status_icon[idx].offset_y                                                            \
            = mmi_camco_osd_skin_p->video_preview.##__x__##.offset_y;                                         \
        idx++;                                                                                                \
    }

#define CAMCO_OSD_GEN_VIDEO_STATUS_ICON_WITH_CAP(__X__,__x__)                                                  \
    img_id = 0;                                                                                                \
    if (mmi_camco_setting_get_setting_capability(MMI_CAMCO_SETTING_##__X__##) == MMI_CAMCO_SETTING_CAP_ENABLED)\
    {                                                                                                          \
        img_id = mmi_camco_setting_get_setting_icon(MMI_CAMCO_SETTING_##__X__##);                              \
    }                                                                                                          \
    if (img_id != 0)                                                                                           \
    {                                                                                                          \
        mmi_camco_osd_p->status_icon[idx].img_id = img_id;                                                     \
        mmi_camco_osd_p->status_icon[idx].offset_x                                                             \
            = mmi_camco_osd_skin_p->video_preview.##__x__##.offset_x;                                          \
        mmi_camco_osd_p->status_icon[idx].offset_y                                                             \
            = mmi_camco_osd_skin_p->video_preview.##__x__##.offset_y;                                          \
        idx++;                                                                                                 \
    }

    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(VDOSCENEMODE, vdoscenemode);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(RECSIZE, recsize);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON_WITH_CAP(AFRANGE, afrange);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(WB, wb);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(LIMIT, limit);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(STORAGE, storage);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(VISQTY, visqty);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(AFMODE, afmode);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(RECAUD, recaud);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(HIGHLIGHT, highlight);
	CAMCO_OSD_GEN_VIDEO_STATUS_ICON(TIMELAPS, timelaps);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_draw_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CAMCO_OSD_MAX_STATUS_ICON_COUNT; i++)
    {
        if (mmi_camco_osd_p->status_icon[i].img_id != 0)
        {
            gdi_image_draw_id(
                mmi_camco_osd_p->status_icon[i].offset_x,
                mmi_camco_osd_p->status_icon[i].offset_y,
                mmi_camco_osd_p->status_icon[i].img_id);
        }
    }
}

#ifndef __MMI_ZOOM_SLIDER_BAR__
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_video_zoom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_zoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_width;
    S32 img_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_get_dimension_id(IMG_ID_CAMCO_ZOOM_IN, &img_width, &img_height);
    mmi_camco_osd_p->zoom_in_touch.offset_x = mmi_camco_osd_skin_p->zoom_in.offset_x;
    mmi_camco_osd_p->zoom_in_touch.offset_y = mmi_camco_osd_skin_p->zoom_in.offset_y;
    mmi_camco_osd_p->zoom_in_touch.width = img_width;
    mmi_camco_osd_p->zoom_in_touch.height = img_height;
    mmi_camco_osd_p->zoom_in_touch.is_press = MMI_FALSE;

    gdi_image_get_dimension_id(IMG_ID_CAMCO_ZOOM_OUT, &img_width, &img_height);
    mmi_camco_osd_p->zoom_out_touch.offset_x = mmi_camco_osd_skin_p->zoom_out.offset_x;
    mmi_camco_osd_p->zoom_out_touch.offset_y = mmi_camco_osd_skin_p->zoom_out.offset_y;
    mmi_camco_osd_p->zoom_out_touch.width = img_width;
    mmi_camco_osd_p->zoom_out_touch.height = img_height;
    mmi_camco_osd_p->zoom_out_touch.is_press = MMI_FALSE;

    gdi_image_get_dimension_id(IMG_ID_CAMCO_ZOOM_HEAD, &img_width, &img_height);
    mmi_camco_osd_p->zoom_ui.head_width = img_width;

    gdi_image_get_dimension_id(IMG_ID_CAMCO_NUM_0, &img_width, &img_height);
    mmi_camco_osd_p->zoom_ui.num_width = img_width;

    gdi_image_get_dimension_id(IMG_ID_CAMCO_NUM_DOT, &img_width, &img_height);
    mmi_camco_osd_p->zoom_ui.dot_width = img_width;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_video_zoom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_zoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_value;
    U16 remained;
    U16 value;
    MMI_ID_TYPE img_id;
    MMI_BOOL can_zoom;
    S32 offset_x = mmi_camco_osd_skin_p->zoom.offset_x;
    S32 offset_y = mmi_camco_osd_skin_p->zoom.offset_y;
    #ifdef __MMI_CAMCORDER_SLIM__
    S32 width;
    S32 height;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_camco_setting_get_active_app() == MMI_CAMCO_SETTING_APP_CAMERA)
    {
		zoom_value = mmi_camco_setting_get_camzoom_value();

    }
    else
    {
        zoom_value = mmi_camco_setting_get_vdozoom_value();

    }
    #ifdef __MMI_CAMCORDER_SLIM__
    gdi_image_get_dimension_id(IMG_ID_CAMCO_ZOOM_TAIL, &width, &height);
    
    #ifdef __MMI_MAINLCD_320X480__
        width = 141;
    #else
        width = 108;
    #endif 
        gdi_image_draw_resized_id(offset_x, offset_y, width, height, IMG_ID_CAMCO_ZOOM_TAIL);
    #endif
    gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
    /* draw head */
    gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMCO_ZOOM_HEAD);

    /* draw 10 digit */
    offset_x += mmi_camco_osd_p->zoom_ui.head_width;

    value = zoom_value / 100;

    gdi_image_draw_id(offset_x, offset_y, (MMI_ID_TYPE) (IMG_ID_CAMCO_NUM_0 + value));

    /* draw dot */
    offset_x += mmi_camco_osd_p->zoom_ui.num_width;

    gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMCO_NUM_DOT);

    /* draw digit */
    offset_x += mmi_camco_osd_p->zoom_ui.dot_width;

    remained = (zoom_value / 10) % 10;

    gdi_image_draw_id(offset_x, offset_y, (MMI_ID_TYPE) (IMG_ID_CAMCO_NUM_0 + remained));

    offset_x += mmi_camco_osd_p->zoom_ui.num_width;

    remained = (zoom_value) % 10;

    gdi_image_draw_id(offset_x, offset_y, (MMI_ID_TYPE) (IMG_ID_CAMCO_NUM_0 + remained));

    /* draw tail */
    offset_x += mmi_camco_osd_p->zoom_ui.num_width;

    gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMCO_ZOOM_TAIL);

    /* draw control */
    if(mmi_camco_setting_get_active_app() == MMI_CAMCO_SETTING_APP_CAMERA)
    {

        can_zoom = mmi_camco_setting_camzoom_can_zoom_out();
    }
    else
    {

        can_zoom = mmi_camco_setting_vdozoom_can_zoom_out();

    }

    if (can_zoom == MMI_TRUE )
    {
        if (mmi_camco_osd_p->zoom_out_touch.is_press)
        {
            img_id = IMG_ID_CAMCO_ZOOM_OUT_SEL;
        }
        else
        {
            img_id = IMG_ID_CAMCO_ZOOM_OUT;
        }
    }
    else
    {
        img_id = IMG_ID_CAMCO_ZOOM_OUT_DIS;
    }

    gdi_image_draw_id(
        mmi_camco_osd_skin_p->zoom_out.offset_x ,
        mmi_camco_osd_skin_p->zoom_out.offset_y,
        img_id);

    if(mmi_camco_setting_get_active_app() == MMI_CAMCO_SETTING_APP_CAMERA)
    {

        can_zoom = mmi_camco_setting_camzoom_can_zoom_in();
    }
    else
    {

        can_zoom = mmi_camco_setting_vdozoom_can_zoom_in();

    }

    if (can_zoom == MMI_TRUE )
    {
        if (mmi_camco_osd_p->zoom_in_touch.is_press)
        {
            img_id = IMG_ID_CAMCO_ZOOM_IN_SEL;
        }
        else
        {
            img_id = IMG_ID_CAMCO_ZOOM_IN;
        }
    }
    else
    {
        img_id = IMG_ID_CAMCO_ZOOM_IN_DIS;
    }
    gdi_image_draw_id(
        mmi_camco_osd_skin_p->zoom_in.offset_x,
        mmi_camco_osd_skin_p->zoom_in.offset_y,
        img_id);
    gdi_pop_and_restore_alpha_blending_source_layer();

}

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_reduced_video_zoom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_reduced_video_zoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_value;
    U16 remained;
    U16 value;
    MMI_ID_TYPE img_id;
#ifdef __MMI_CAMCORDER_SLIM__
    S32 width;
    S32 height;
#endif

    gdi_rect_struct *rotate_ev_zoom_area_p = &mmi_camco_osd_p->video_recoding_osd.rotate_ev_zoom_area;
    S32 offset_x = mmi_camco_osd_skin_p->zoom.offset_x - rotate_ev_zoom_area_p->x1;
    S32 offset_y = mmi_camco_osd_skin_p->zoom.offset_y - rotate_ev_zoom_area_p->y1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    zoom_value = mmi_camco_setting_get_vdozoom_value();

#ifdef __MMI_CAMCORDER_SLIM__
 gdi_image_get_dimension_id(IMG_ID_CAMCO_ZOOM_TAIL, &width, &height);        
#ifdef __MMI_MAINLCD_320X480__
                width = 141;
#else
                width = 108;
#endif 

        gdi_image_draw_resized_id(offset_x, offset_y, width, height, IMG_ID_CAMCO_ZOOM_TAIL);
#endif
    gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);

    /* draw head */
    gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMCO_ZOOM_HEAD);

    /* draw 10 digit */
    offset_x += mmi_camco_osd_p->zoom_ui.head_width;

    value = zoom_value / 100;

    gdi_image_draw_id(offset_x, offset_y, (MMI_ID_TYPE) (IMG_ID_CAMCO_NUM_0 + value));

    /* draw dot */
    offset_x += mmi_camco_osd_p->zoom_ui.num_width;

    gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMCO_NUM_DOT);

    /* draw digit */
    offset_x += mmi_camco_osd_p->zoom_ui.dot_width;

    remained = (zoom_value / 10) % 10;

    gdi_image_draw_id(offset_x, offset_y, (MMI_ID_TYPE) (IMG_ID_CAMCO_NUM_0 + remained));

    offset_x += mmi_camco_osd_p->zoom_ui.num_width;

    remained = (zoom_value) % 10;

    gdi_image_draw_id(offset_x, offset_y, (MMI_ID_TYPE) (IMG_ID_CAMCO_NUM_0 + remained));

    /* draw tail */
    offset_x += mmi_camco_osd_p->zoom_ui.num_width;

    gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMCO_ZOOM_TAIL);

    /* draw control */
    
    if (mmi_camco_setting_vdozoom_can_zoom_out())
    {
        if (mmi_camco_osd_p->zoom_out_touch.is_press)
        {
            img_id = IMG_ID_CAMCO_ZOOM_OUT_SEL;
        }
        else
        {
            img_id = IMG_ID_CAMCO_ZOOM_OUT;
        }
    }
    else
    {
        img_id = IMG_ID_CAMCO_ZOOM_OUT_DIS;
    }    

    gdi_image_draw_id(
        mmi_camco_osd_skin_p->zoom_out.offset_x  - rotate_ev_zoom_area_p->x1,
        mmi_camco_osd_skin_p->zoom_out.offset_y - rotate_ev_zoom_area_p->y1,
        img_id);

    if (mmi_camco_setting_vdozoom_can_zoom_in())
    {
        if (mmi_camco_osd_p->zoom_in_touch.is_press)
        {
            img_id = IMG_ID_CAMCO_ZOOM_IN_SEL;
        }
        else
        {
            img_id = IMG_ID_CAMCO_ZOOM_IN;
        }
    }
    else
    {
        img_id = IMG_ID_CAMCO_ZOOM_IN_DIS;
    }

    gdi_image_draw_id(
        mmi_camco_osd_skin_p->zoom_in.offset_x - rotate_ev_zoom_area_p->x1,
        mmi_camco_osd_skin_p->zoom_in.offset_y - rotate_ev_zoom_area_p->y1,
        img_id);

    gdi_pop_and_restore_alpha_blending_source_layer();

}
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_camera_zoom_in
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_camera_zoom_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_value = 100;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_EXIT);

    if (mmi_camco_setting_camzoom_can_zoom_in())
    {
        /* call core to get value */

        zoom_value = mmi_camco_update_zoom_factor();

        /* set value to setting */
        mmi_camco_setting_set_camzoom_value(zoom_value);

        mmi_camco_setting_set_camzoom_step(mmi_camco_update_zoom_step());

        /* update ui */
        mmi_camco_osd_draw_osd();

        gui_start_timer(MMI_CAMCO_OSD_CAM_SETTING_DUR, mmi_camco_osd_camera_zoom_in);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_camera_zoom_in_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_camera_zoom_in_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->zoom_in_touch.is_press)
    {
        /* already pressed */
        return;
    }

    if (!mmi_camco_setting_camzoom_can_zoom_in())
    {
        /* cant zoom in anymore */
        return;
    }

    if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_FACEDETECT) == MMI_CAMCO_FACEDETECT_ON)
    {
        mmi_camco_cam_face_detect_stop();
    }
    if(mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_ASD_SHOT)
    {
        mmi_camco_cam_scene_detect_stop();
    }

    mmi_camco_osd_p->zoom_in_touch.is_press = MMI_TRUE;
    mmi_camco_osd_draw_osd();

    /* first time ev, will wait longer to zoom again */
    gui_start_timer(MMI_CAMCO_OSD_CAM_SETTING_LONG_DUR, mmi_camco_osd_camera_zoom_in);

    /* call core to zoom in */
    mmi_camco_start_zoom_in_one_step();
    gui_start_timer(MMI_CAMCO_OSD_CAM_SETTING_DUR, mmi_camco_start_fast_zoom_in);

    mmi_camco_osd_draw_osd();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_camera_zoom_in_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_camera_zoom_in_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_value = 10;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_camco_osd_p->zoom_in_touch.is_press)
    {
        /* not pressed */
        return;
    }
    gui_cancel_timer(mmi_camco_start_fast_zoom_in);
    gui_cancel_timer(mmi_camco_osd_camera_zoom_in);

    mmi_camco_osd_p->zoom_in_touch.is_press = MMI_FALSE;

    /* get value and update ui again */
    /* call core to get value */
    mmi_camco_stop_fast_zoom();

    zoom_value = mmi_camco_update_zoom_factor();

    /* set value to setting */
    mmi_camco_setting_set_camzoom_value(zoom_value);

    mmi_camco_setting_set_camzoom_step(mmi_camco_update_zoom_step());

    mmi_camco_osd_draw_osd();

    if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_FACEDETECT) == MMI_CAMCO_FACEDETECT_ON)
    {
        mmi_camco_cam_face_detect_start();
    }
     if(mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_ASD_SHOT)
    {
        mmi_camco_cam_scene_detect_start();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_camera_zoom_out
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_camera_zoom_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_value = 10;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_EXIT);

    if (mmi_camco_setting_camzoom_can_zoom_out())
    {
        /* call core to get value */

        zoom_value = mmi_camco_update_zoom_factor();

        /* set value to setting */
        mmi_camco_setting_set_camzoom_value(zoom_value);

        mmi_camco_setting_set_camzoom_step(mmi_camco_update_zoom_step());

        /* update ui */
        mmi_camco_osd_draw_osd();

        gui_start_timer(MMI_CAMCO_OSD_CAM_SETTING_DUR, mmi_camco_osd_camera_zoom_out);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_camera_zoom_out_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_camera_zoom_out_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->zoom_out_touch.is_press)
    {
        /* already pressed */
        return;
    }

    if (!mmi_camco_setting_camzoom_can_zoom_out())
    {
        /* cant zoom in anymore */
        return;
    }

    if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_FACEDETECT) == MMI_CAMCO_FACEDETECT_ON)
    {
        mmi_camco_cam_face_detect_stop();
    }
    if(mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_ASD_SHOT)
    {
        mmi_camco_cam_scene_detect_stop();
    }

    mmi_camco_osd_p->zoom_out_touch.is_press = MMI_TRUE;
    mmi_camco_osd_draw_osd();

    /* first time ev, will wait longer to zoom again */
    gui_start_timer(MMI_CAMCO_OSD_CAM_SETTING_LONG_DUR, mmi_camco_osd_camera_zoom_out);

    /* call core to zoom in */
    mmi_camco_start_zoom_out_one_step();
    gui_start_timer(MMI_CAMCO_OSD_CAM_SETTING_DUR, mmi_camco_start_fast_zoom_out);

    mmi_camco_osd_draw_osd();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_camera_zoom_out_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_camera_zoom_out_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_value = 10;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_camco_osd_p->zoom_out_touch.is_press)
    {
        /* not pressed */
        return;
    }
    gui_cancel_timer(mmi_camco_start_fast_zoom_out);
    gui_cancel_timer(mmi_camco_osd_camera_zoom_out);

    mmi_camco_osd_p->zoom_out_touch.is_press = MMI_FALSE;

    /* get value and update ui again */
    /* call core to get value */
    mmi_camco_stop_fast_zoom();

    zoom_value = mmi_camco_update_zoom_factor();

    mmi_camco_setting_set_camzoom_step(mmi_camco_update_zoom_step());

    /* set value to setting */
    mmi_camco_setting_set_camzoom_value(zoom_value);

    mmi_camco_osd_draw_osd();

    if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_FACEDETECT) == MMI_CAMCO_FACEDETECT_ON)
    {
        mmi_camco_cam_face_detect_start();
    }
     if(mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_ASD_SHOT)
    {
        mmi_camco_cam_scene_detect_start();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_video_zoom_in
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_video_zoom_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_value = 100;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_EXIT);

    if (mmi_camco_setting_vdozoom_can_zoom_in())
    {
        /* call core to get value */

        zoom_value = mmi_camco_update_zoom_factor();

        /* set value to setting */
        mmi_camco_setting_set_vdozoom_value(zoom_value);

        mmi_camco_setting_set_vdozoom_step(mmi_camco_update_zoom_step());

        /* update ui */
        mmi_camco_osd_draw_osd();

        gui_start_timer(MMI_CAMCO_OSD_CAM_SETTING_DUR, mmi_camco_osd_video_zoom_in);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_video_zoom_in_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_video_zoom_in_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->zoom_in_touch.is_press)
    {
        /* already pressed */
        return;
    }

    if (!mmi_camco_setting_vdozoom_can_zoom_in())
    {
        /* cant zoom in anymore */
        return;
    }

    /* first time ev, will wait longer to zoom again */
    gui_start_timer(MMI_CAMCO_OSD_CAM_SETTING_LONG_DUR, mmi_camco_osd_video_zoom_in);

    /* call core to zoom in */
    mmi_camco_start_zoom_in_one_step();
    gui_start_timer(MMI_CAMCO_OSD_CAM_SETTING_DUR, mmi_camco_start_fast_zoom_in);

    mmi_camco_osd_p->zoom_in_touch.is_press = MMI_TRUE;
    mmi_camco_osd_draw_osd();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_video_zoom_in_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_video_zoom_in_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_value = 10;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_camco_osd_p->zoom_in_touch.is_press)
    {
        /* not pressed */
        return;
    }
    gui_cancel_timer(mmi_camco_start_fast_zoom_in);
    gui_cancel_timer(mmi_camco_osd_video_zoom_in);

    mmi_camco_osd_p->zoom_in_touch.is_press = MMI_FALSE;

    /* get value and update ui again */
    /* call core to get value */
    mmi_camco_stop_fast_zoom();

    zoom_value = mmi_camco_update_zoom_factor();

    /* set value to setting */
    mmi_camco_setting_set_vdozoom_value(zoom_value);

    mmi_camco_setting_set_vdozoom_step(mmi_camco_update_zoom_step());

    mmi_camco_osd_draw_osd();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_video_zoom_out
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_video_zoom_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_value = 10;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_EXIT);

    if (mmi_camco_setting_vdozoom_can_zoom_out())
    {
        /* call core to get value */

        zoom_value = mmi_camco_update_zoom_factor();

        /* set value to setting */
        mmi_camco_setting_set_vdozoom_value(zoom_value);

        mmi_camco_setting_set_vdozoom_step(mmi_camco_update_zoom_step());

        /* update ui */
        mmi_camco_osd_draw_osd();

        gui_start_timer(MMI_CAMCO_OSD_CAM_SETTING_DUR, mmi_camco_osd_video_zoom_out);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_video_zoom_out_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_video_zoom_out_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->zoom_out_touch.is_press)
    {
        /* already pressed */
        return;
    }

    if (!mmi_camco_setting_vdozoom_can_zoom_out())
    {
        /* cant zoom in anymore */
        return;
    }

    /* first time ev, will wait longer to zoom again */
    gui_start_timer(MMI_CAMCO_OSD_CAM_SETTING_LONG_DUR, mmi_camco_osd_video_zoom_out);

    /* call core to zoom in */
    mmi_camco_start_zoom_out_one_step();
    gui_start_timer(MMI_CAMCO_OSD_CAM_SETTING_DUR, mmi_camco_start_fast_zoom_out);

    mmi_camco_osd_p->zoom_out_touch.is_press = MMI_TRUE;
    mmi_camco_osd_draw_osd();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_video_zoom_out_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_video_zoom_out_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_value = 10;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_camco_osd_p->zoom_out_touch.is_press)
    {
        /* not pressed */
        return;
    }
    gui_cancel_timer(mmi_camco_start_fast_zoom_out);
    gui_cancel_timer(mmi_camco_osd_video_zoom_out);

    mmi_camco_osd_p->zoom_out_touch.is_press = MMI_FALSE;

    /* get value and update ui again */
    /* call core to get value */
    mmi_camco_stop_fast_zoom();

    zoom_value = mmi_camco_update_zoom_factor();

    /* set value to setting */
    mmi_camco_setting_set_vdozoom_value(zoom_value);

    mmi_camco_setting_set_vdozoom_step(mmi_camco_update_zoom_step());

    mmi_camco_osd_draw_osd();
}

#else
#define img_press_shift(x) ((x?1:0))
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_round
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_camco_round(double input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 dig;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dig = (U16)input;

    if ((input - (double)dig) >= 0.5)
        dig += 1;
    return dig;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_slider_init
 * DESCRIPTION
 *  init slider obj
 * PARAMETERS
 *  gbf
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slider_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slider_struct *slider;
    MMI_ID_TYPE ZOOM_TOP;
    MMI_ID_TYPE ZOOM_SLIDER_BAR;
    MMI_ID_TYPE ZOOM_BOTTOM;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    slider = &mmi_camco_osd_p->slider;
    slider->slider_state = MMI_CAMCO_OSD_SLIDER_RELEASE;

    if (mmi_camco_osd_is_horz_UI())
    {
        ZOOM_TOP = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_INC_ICON;
        ZOOM_SLIDER_BAR = IMG_ID_CAMCO_DIR_SETTING_SLIDER_BAR_ICON;
        ZOOM_BOTTOM = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_DEC_ICON;
    }
    else
    {
        ZOOM_TOP = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_DEC_V_ICON;
        ZOOM_SLIDER_BAR = IMG_ID_CAMCO_DIR_SETTING_SLIDER_BAR_V_ICON;
        ZOOM_BOTTOM = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_INC_V_ICON;
    }

    
    slider->slider_zoom_top.offset_x = mmi_camco_osd_skin_p->zoom_slider_top.offset_x;
    slider->slider_zoom_top.offset_y = mmi_camco_osd_skin_p->zoom_slider_top.offset_y;
    gdi_image_get_dimension_id(
        ZOOM_TOP,
        &slider->slider_zoom_top.width,
        &slider->slider_zoom_top.height);
    
    slider->slider_bar.offset_x = mmi_camco_osd_skin_p->zoom_slider_bar.offset_x;
    slider->slider_bar.offset_y = mmi_camco_osd_skin_p->zoom_slider_bar.offset_y;
    gdi_image_get_dimension_id(
        ZOOM_SLIDER_BAR,
        &slider->slider_bar.width,
        &slider->slider_bar.height);
    
    slider->slider_zoom_botton.offset_x = mmi_camco_osd_skin_p->zoom_slider_botton.offset_x;
    slider->slider_zoom_botton.offset_y = mmi_camco_osd_skin_p->zoom_slider_botton.offset_y;

    gdi_image_get_dimension_id(
        ZOOM_BOTTOM,
        &slider->slider_zoom_botton.width,
        &slider->slider_zoom_botton.height);
    
    slider->slider_location.offset_x = mmi_camco_osd_skin_p->zoom_slider_location.offset_x;
    slider->slider_location.offset_y = mmi_camco_osd_skin_p->zoom_slider_location.offset_y;

    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_DIR_SETTING_SLIDER_IND_ICON,
        &slider->slider_location.width,
        &slider->slider_location.height);

    slider->slider_location.is_press = MMI_FALSE;
    slider->slider_location.is_usable = MMI_TRUE;
    
    if (mmi_camco_osd_is_horz_UI())
    {
        slider->slider_region.offset_x = slider->slider_bar.offset_x + ((slider->slider_bar.width -slider->slider_location.width)>> 1);
        slider->slider_region.offset_y = slider->slider_bar.offset_y + ((slider->slider_location.height)>> 1); /* + (setting_p.slider_location.height >>1); */
        slider->slider_region.width = slider->slider_location.width;
        slider->slider_region.height = slider->slider_bar.height - slider->slider_location.height;

    }
    else
    {
        slider->slider_region.offset_x = slider->slider_bar.offset_x + ((slider->slider_location.width)>> 1);
        slider->slider_region.offset_y = slider->slider_bar.offset_y + ((slider->slider_bar.height - slider->slider_location.height) >> 1); /* + (setting_p.slider_location.height >>1); */
        slider->slider_region.width = slider->slider_bar.width - slider->slider_location.width;
        slider->slider_region.height = slider->slider_location.height;

    }
    slider->slider_region.is_press = MMI_FALSE;
    slider->slider_region.is_usable = MMI_TRUE;

    slider->zoom_region.offset_x = slider->slider_zoom_top.offset_x;
    slider->zoom_region.offset_y = slider->slider_zoom_top.offset_y;
    slider->zoom_region.width = slider->slider_zoom_botton.offset_x + slider->slider_zoom_botton.width - slider->slider_zoom_top.offset_x;
    slider->zoom_region.height = slider->slider_zoom_botton.offset_y + slider->slider_zoom_botton.height - slider->slider_zoom_top.offset_y;
    slider->zoom_region.is_press = MMI_FALSE;
    slider->zoom_region.is_usable = MMI_TRUE;

    slider->slider_location_region.offset_x = slider->slider_location.offset_x - 10;
    slider->slider_location_region.offset_y = slider->slider_location.offset_y - 5;
    slider->slider_location_region.width = slider->slider_location.width + 20;
    slider->slider_location_region.height = slider->slider_location.height + 10;

    slider->slider_location_region.is_press = MMI_FALSE;
    slider->slider_location_region.is_usable = MMI_TRUE;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_zoom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_zoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //mmi_camco_osd_p->is_show_zoom_slider = MMI_FALSE;

    //mmi_camco_osd_init_zoom_bt();

    mmi_slider_init();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_zoom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_zoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mmi_camco_osd_p->is_show_zoom_slider == MMI_TRUE ||
        mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_RECORDING||
        mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_PAUSE)
    {  
        mmi_slider_draw();
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_is_horz_UI
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  MMI_BOOL 
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_is_horz_UI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        return MMI_TRUE;
    }
#ifdef DUAL_CAMERA_SUPPORT
    else
    {
        return MMI_FALSE;
    }
#endif /* DUAL_CAMERA_SUPPORT */ 
#else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
    return MMI_FALSE;
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

}

/*****************************************************************************
 * FUNCTION
 *  mmi_slider_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slider_update(mmi_pen_point_struct pos)
{
    double ratio = (((1.0) * (pos.y - mmi_camco_osd_p->slider.slider_region.offset_y)) / mmi_camco_osd_p->slider.slider_region.height);
    double rel_pos_y;                    
    U16 zoom_value;
    U16 curr_value = mmi_camco_setting_get_camzoom_step();

    if (mmi_camco_osd_is_horz_UI())
    {  
        ratio = (((1.0) * (pos.y - mmi_camco_osd_p->slider.slider_region.offset_y)) / mmi_camco_osd_p->slider.slider_region.height);                
    }
    else
    {
        ratio = (((1.0) * (pos.x - mmi_camco_osd_p->slider.slider_region.offset_x)) / mmi_camco_osd_p->slider.slider_region.width);                
    }
                
    if(ratio > 1)
        ratio = 1;

    if (mmi_camco_osd_is_horz_UI())
    {                  
        rel_pos_y = (1 - ratio) * (mmi_camco_osd_p->slider.step_count - 1) + (mmi_camco_osd_p->slider.min_value);
    }
    else
    {                  
        rel_pos_y = (ratio) * (mmi_camco_osd_p->slider.step_count - 1) + (mmi_camco_osd_p->slider.min_value);
    }                    
    zoom_value = mmi_camco_round(rel_pos_y);

    if (curr_value - zoom_value > 50 || zoom_value - curr_value > 50)
        return;
    if(mmi_camco_setting_get_active_app() == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        if (zoom_value > mmi_camco_setting_get_camzoom_maxstep())
            zoom_value = mmi_camco_setting_get_camzoom_maxstep();

        if (zoom_value < mmi_camco_setting_get_camzoom_minstep())
            zoom_value = mmi_camco_setting_get_camzoom_minstep();

        mmi_camco_setting_set_camzoom_step(zoom_value);
        mdi_camera_update_para_zoom(zoom_value);

        mmi_camco_setting_set_camzoom_value(mmi_camco_update_zoom_factor());
     }
     else
     {
         if (zoom_value > mmi_camco_setting_get_vdozoom_maxstep())
             zoom_value = mmi_camco_setting_get_vdozoom_maxstep();

         if (zoom_value < mmi_camco_setting_get_vdozoom_minstep())
             zoom_value = mmi_camco_setting_get_vdozoom_minstep();

         mmi_camco_setting_set_vdozoom_step(zoom_value);
         mdi_video_rec_update_para_zoom(zoom_value);
         mmi_camco_setting_set_vdozoom_value(mmi_camco_update_zoom_factor());

     }

                    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_slider_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slider_draw()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	U16 curr_value;
	U16 ind_center_pos_y, ind_center_pos_x;
    mmi_slider_struct slider;
    MMI_ID_TYPE ZOOM_TOP;
    MMI_ID_TYPE ZOOM_SLIDER_BAR;
    MMI_ID_TYPE ZOOM_BOTTOM;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	slider = mmi_camco_osd_p->slider;
    gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
    if(mmi_camco_setting_get_active_app() == MMI_CAMCO_SETTING_APP_CAMERA)
    {
		curr_value = mmi_camco_setting_get_camzoom_step();

    }
    else
    {
        curr_value = mmi_camco_setting_get_vdozoom_step();

    }
    
    if (mmi_camco_osd_is_horz_UI())
    {
        ZOOM_TOP = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_INC_ICON;
        ZOOM_SLIDER_BAR = IMG_ID_CAMCO_DIR_SETTING_SLIDER_BAR_ICON;
        ZOOM_BOTTOM = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_DEC_ICON;
    }
    else
    {
        ZOOM_TOP = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_DEC_V_ICON;
        ZOOM_SLIDER_BAR = IMG_ID_CAMCO_DIR_SETTING_SLIDER_BAR_V_ICON;
        ZOOM_BOTTOM = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_INC_V_ICON;
    }
    
    gdi_image_draw_id(
		slider.slider_zoom_top.offset_x,
		slider.slider_zoom_top.offset_y,
		ZOOM_TOP);
    
	gdi_image_draw_id(
		slider.slider_bar.offset_x ,
		slider.slider_bar.offset_y,
		ZOOM_SLIDER_BAR);
    
	gdi_image_draw_id(
		slider.slider_zoom_botton.offset_x ,
		slider.slider_zoom_botton.offset_y,
		ZOOM_BOTTOM);
    
	if (mmi_camco_osd_is_horz_UI() == MMI_TRUE)
	{  
		ind_center_pos_y =
			(1.0 - (((curr_value - slider.min_value) * (1.0)) / (slider.step_count - 1))) *
			slider.slider_region.height;
	
		slider.slider_location.offset_y = (ind_center_pos_y - (slider.slider_location.height >> 1) + slider.slider_region.offset_y);
		 mmi_camco_osd_p->slider.slider_location_region.offset_y = slider.slider_location.offset_y - 5;
	
		gdi_layer_set_clip(
			slider.slider_bar.offset_x,
			slider.slider_location.offset_y + (slider.slider_location.height >> 1),
			slider.slider_bar.offset_x + slider.slider_bar.width,
			slider.slider_bar.offset_y + slider.slider_bar.height);
	}
	else
    {   				
		ind_center_pos_x =
			((((curr_value - slider.min_value) * (1.0)) / (slider.step_count - 1))) *
				slider.slider_region.width;
	
		slider.slider_location.offset_x = (ind_center_pos_x - (slider.slider_location.width>> 1) + slider.slider_region.offset_x);
		 mmi_camco_osd_p->slider.slider_location_region.offset_x = slider.slider_location.offset_x - 10;
	
		gdi_layer_set_clip(
			slider.slider_bar.offset_x,
			slider.slider_bar.offset_y,
			slider.slider_location.offset_x + (slider.slider_location.width>> 1),						 
			slider.slider_bar.offset_y + slider.slider_bar.height);
	}
    
	gdi_image_draw_id(
		slider.slider_bar.offset_x ,
		slider.slider_bar.offset_y,
		ZOOM_SLIDER_BAR + 1);//img_press_shift(slider.slider_location.is_press));
    
    gdi_layer_reset_clip();
    
	gdi_image_draw_id(
		slider.slider_location.offset_x,
		slider.slider_location.offset_y,
		IMG_ID_CAMCO_DIR_SETTING_SLIDER_IND_ICON + img_press_shift(slider.slider_location.is_press));	
    gdi_pop_and_restore_alpha_blending_source_layer();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_zoom_bt_press_hdlr
 * DESCRIPTION
 *  zoom bt press hdlr
 * PARAMETERS
 *  void             
 *        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_zoom_bt_press_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_ZOOM;
    mmi_camco_osd_draw_osd();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_zoom_bt_release_hdlr
 * DESCRIPTION
 *  zoom bt release hdlr
 * PARAMETERS
 *  void             
 *        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_zoom_bt_release_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_camco_setting_get_active_app() == MMI_CAMCO_SETTING_APP_CAMERA)
    {
	    if(mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPSIZE)!= MMI_CAMCO_CAPSIZE_5MP)
        {   
        
		    if((mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) != MMI_CAMCO_CAPMODE_MAV)&&
				(mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) != MMI_CAMCO_CAPMODE_3D_IMAGE)&&
				(mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) != MMI_CAMCO_CAPMODE_AUTORAMA))
		    {
      
				mmi_camco_osd_p->is_show_zoom_slider = MMI_TRUE;
			    mmi_camco_osd_p->slider.slider_location_region.is_usable = MMI_TRUE;
			    mmi_camco_osd_p->slider.slider_region.is_usable = MMI_TRUE;
			    mmi_camco_osd_p->slider.zoom_region.is_usable = MMI_TRUE; 
				mmi_camco_osd_draw_osd();
      
	    	}
       
	    
	    }
    }else
    {
		mmi_camco_osd_p->is_show_zoom_slider = MMI_TRUE;
		mmi_camco_osd_p->slider.slider_location_region.is_usable = MMI_TRUE;
		mmi_camco_osd_p->slider.slider_region.is_usable = MMI_TRUE;
		mmi_camco_osd_p->slider.zoom_region.is_usable = MMI_TRUE; 
		mmi_camco_osd_draw_osd();

	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_setting_menu_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_enter        [IN]        
 *  idx             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_touch_slider_normalize(S16 *y, S32 s, S32 e, S32 range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((*y) < s && (*y) > s - range)
    {
        (*y) = s + 1;
    }
    else if((*y) > e && (*y) < e + range)
    {
        (*y) = e - 1;
    }
    return MMI_TRUE;
}
#endif /*__MMI_ZOOM_SLIDER_BAR__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_right_arrow_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_right_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* Do nothing */
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
        #ifdef __SMILE_SHUTTER_SUPPORT__
            if(mmi_camco_osd_p->smiledetect.is_zoom_ev_enable)
            {
        #endif    
        #ifndef __MMI_ZOOM_SLIDER_BAR__
            mmi_camco_osd_camera_zoom_in_press();  
        #endif
        #ifdef __SMILE_SHUTTER_SUPPORT__
            }
        #endif    

            break;
        }

        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
        #ifndef __MMI_ZOOM_SLIDER_BAR__
            mmi_camco_osd_video_zoom_in_press(); 
        #endif
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

            iconlist_p->ra_touch.is_press = MMI_TRUE;
            mmi_camco_osd_iconlist_next_cyclic();
            break;
        }
    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

            add_frame_p->ra_touch.is_press = MMI_TRUE;
            mmi_camco_osd_add_frame_next_cyclic();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

            imgselect_cache_p->ra_touch.is_press = MMI_TRUE;
            mmi_camco_osd_imgselect_next_cyclic();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_right_arrow_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_right_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* Do nothing */
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
        #ifdef __SMILE_SHUTTER_SUPPORT__
            if(mmi_camco_osd_p->smiledetect.is_zoom_ev_enable)
            {
        #endif 
        #ifndef __MMI_ZOOM_SLIDER_BAR__
            mmi_camco_osd_camera_zoom_in_release();    
        #endif
        #ifdef __SMILE_SHUTTER_SUPPORT__
            }
        #endif    

            break;
        }

        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
        #ifndef __MMI_ZOOM_SLIDER_BAR__
            mmi_camco_osd_video_zoom_in_release();
        #endif
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING: 
        {
            mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

            if (!iconlist_p->ra_touch.is_press)
            {
                /* not pressed, return */
                return;
            }

            gui_cancel_timer(mmi_camco_osd_iconlist_next_cyclic);
            iconlist_p->ra_touch.is_press = MMI_FALSE;

            mmi_camco_osd_draw_osd();
            break;
        }
    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {

            mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

            if (!add_frame_p->ra_touch.is_press)
            {
                /* not pressed, return */
                return;
            }

            gui_cancel_timer(mmi_camco_osd_add_frame_next_cyclic);
            add_frame_p->ra_touch.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

            if (!imgselect_cache_p->ra_touch.is_press)
            {
                /* not pressed, return */
                return;
            }

            gui_cancel_timer(mmi_camco_osd_imgselect_next_cyclic);
            imgselect_cache_p->ra_touch.is_press = MMI_FALSE;
            mmi_camco_updata_key_handler();
            mmi_camco_osd_draw_osd();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_left_arrow_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_left_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* Do nothing */
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
        #ifdef __SMILE_SHUTTER_SUPPORT__
            if(mmi_camco_osd_p->smiledetect.is_zoom_ev_enable)
            {
        #endif
            #ifndef __MMI_ZOOM_SLIDER_BAR__
                mmi_camco_osd_camera_zoom_out_press(); 
            #endif
        #ifdef __SMILE_SHUTTER_SUPPORT__
            }
        #endif    

            break;
        }

        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            
        #ifndef __MMI_ZOOM_SLIDER_BAR__
            mmi_camco_osd_video_zoom_out_press();    
        #endif
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:  
        {
            mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

            iconlist_p->la_touch.is_press = MMI_TRUE;
            mmi_camco_osd_iconlist_prev_cyclic();
            break;
        }
    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

            add_frame_p->la_touch.is_press = MMI_TRUE;
            mmi_camco_osd_add_frame_prev_cyclic();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

            imgselect_cache_p->la_touch.is_press = MMI_TRUE;
            mmi_camco_osd_imgselect_prev_cyclic();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            break;
        }
        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_left_arrow_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_left_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* Do nothing */
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
        #ifdef __SMILE_SHUTTER_SUPPORT__
            if(mmi_camco_osd_p->smiledetect.is_zoom_ev_enable)
            {
        #endif
        
        #ifndef __MMI_ZOOM_SLIDER_BAR__
            mmi_camco_osd_camera_zoom_out_release(); 
        #endif
        #ifdef __SMILE_SHUTTER_SUPPORT__
            }
        #endif
            break;
        }

        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            
        #ifndef __MMI_ZOOM_SLIDER_BAR__
            mmi_camco_osd_video_zoom_out_release();  
        #endif
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:  
        {
            mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

            if (!iconlist_p->la_touch.is_press)
            {
                /* not pressed, return */
                return;
            }

            gui_cancel_timer(mmi_camco_osd_iconlist_prev_cyclic);
            iconlist_p->la_touch.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            break;
        }
    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

            if (!add_frame_p->la_touch.is_press)
            {
                /* not pressed, return */
                return;
            }

            gui_cancel_timer(mmi_camco_osd_add_frame_prev_cyclic);
            add_frame_p->la_touch.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();

            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

            if (!imgselect_cache_p->la_touch.is_press)
            {
                /* not pressed, return */
                return;
            }

            gui_cancel_timer(mmi_camco_osd_imgselect_prev_cyclic);
            imgselect_cache_p->la_touch.is_press = MMI_FALSE;
            mmi_camco_updata_key_handler();
            mmi_camco_osd_draw_osd();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_option_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title_str_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_option_title(MMI_ID_TYPE title_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;

    mmi_camco_osd_menulist_struct *menulist_p = &mmi_camco_osd_p->option_menulist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menulist_p->item_count = 0;
    menulist_p->state = MMI_CAMCO_OSD_MENULIST_STATE_EXIT;

    /* get title str */
    menulist_p->title_str_id = title_str_id;

    gui_measure_string((UI_string_type) GetString(menulist_p->title_str_id), &str_width, &str_height);

    menulist_p->title_str_shift_x = (menulist_p->title_width - str_width) >> 1;
    menulist_p->title_str_shift_y = (menulist_p->title_height - str_height) >> 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_insert_option_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_id         [IN]        
 *  item_str_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_insert_option_item(U32 item_id, MMI_ID_TYPE item_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_camco_osd_menulist_struct *menulist_p = &mmi_camco_osd_p->option_menulist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menulist_p->item_list[menulist_p->item_count].item_id = item_id;
    menulist_p->item_list[menulist_p->item_count].str_id = item_str_id;
    menulist_p->item_list[menulist_p->item_count].radio_img_id = 0;
    menulist_p->item_list[menulist_p->item_count].status_img_id = 0;
    menulist_p->item_count++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_insert_option_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_insert_option_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;

    mmi_camco_osd_menulist_struct *menulist_p = &mmi_camco_osd_p->option_menulist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(menulist_p->item_list[0].str_id != 0);

    gui_measure_string((UI_string_type) GetString(menulist_p->item_list[0].str_id), &str_width, &str_height);
    menulist_p->item_str_shift_y = (menulist_p->item_height - str_height) >> 1;
    menulist_p->item_str_shift_x = menulist_p->item_str_shift_y;
    if (menulist_p->item_count > menulist_p->max_disp_item_count)
    {
        menulist_p->disp_item_count = menulist_p->max_disp_item_count;
    }
    else
    {
        menulist_p->disp_item_count = menulist_p->item_count;
    }

    /* start position (left top) */
    menulist_p->menulist_offset_x = mmi_camco_osd_skin_p->option.menulist.offset_x;
    menulist_p->menulist_offset_y = mmi_camco_osd_skin_p->option.menulist.offset_y;
    if (r2lMMIFlag)
    {
        menulist_p->menulist_offset_x = mmi_camco_osd_p->osd_width - menulist_p->menulist_offset_x - 1;
    #ifdef HORIZONTAL_CAMERA
        if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
        {
#define MMI_CAMCO_OSD_OFFSET_Y (30)
            menulist_p->menulist_offset_y += MMI_CAMCO_OSD_OFFSET_Y;
            menulist_p->max_disp_item_count = 4;
        }
    #endif /* HORIZONTAL_CAMERA */ 
    }

    /* touch */
    if (r2lMMIFlag)
    {
        menulist_p->list_touch.offset_x = menulist_p->menulist_offset_x - menulist_p->item_width + 1;
    }
    else
    {
        menulist_p->list_touch.offset_x = menulist_p->menulist_offset_x;
    }
    menulist_p->list_touch.offset_y = menulist_p->menulist_offset_y + menulist_p->title_height;
    menulist_p->list_touch.width = menulist_p->item_width;
    menulist_p->list_touch.height = menulist_p->item_height * menulist_p->disp_item_count;

    menulist_p->list_up_touch.offset_x = menulist_p->list_touch.offset_x;
    menulist_p->list_up_touch.offset_y = 0;
    menulist_p->list_up_touch.width = menulist_p->list_touch.width;
    menulist_p->list_up_touch.height = menulist_p->menulist_offset_y + menulist_p->title_height;

    menulist_p->list_down_touch.offset_x = menulist_p->list_touch.offset_x;
    menulist_p->list_down_touch.offset_y = mmi_camco_osd_skin_p->setting.menulist.offset_y;
    menulist_p->list_down_touch.width = menulist_p->list_touch.width;
    menulist_p->list_down_touch.height = mmi_camco_osd_p->osd_height - mmi_camco_osd_skin_p->setting.menulist.offset_y;

    /* gen scrollbar */
    mmi_camco_osd_gen_scrollbar();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_option_hilite_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
extern U16 mmi_camco_osd_get_option_hilite_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->option_menulist.highlighted_idx;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_option_item_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  highlight_idx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
extern U32 mmi_camco_osd_get_option_item_id(S32 highlight_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->option_menulist.item_list[highlight_idx].item_id;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_imgselect_hilite_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
extern U16 mmi_camco_osd_get_imgselect_hilite_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->imgselect_cache.highlighted_idx;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_option_hilite_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_option_hilite_idx(U16 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 remained;
    mmi_camco_osd_menulist_struct *menulist_p = &mmi_camco_osd_p->option_menulist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menulist_p->highlighted_idx = idx;

    remained = menulist_p->item_count - menulist_p->highlighted_idx;

    if (remained < menulist_p->disp_item_count)
    {
        if (menulist_p->disp_item_count > menulist_p->item_count)
        {
            menulist_p->first_disp_idx = 0;
        }
        else
        {
            menulist_p->first_disp_idx = menulist_p->item_count - menulist_p->disp_item_count;
        }
    }
    else
    {
        menulist_p->first_disp_idx = menulist_p->highlighted_idx;
    }

    mmi_camco_osd_gen_scrollbar();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_option_menulist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_option_menulist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_camco_osd_menulist_struct *menulist_p = &mmi_camco_osd_p->option_menulist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_CAMCORDER_SLIM__
        menulist_p->item_width = __MENUITEM_BG_WIDTH__;
        menulist_p->item_height = __MENUITEM_BG_HEIGHT__;
        menulist_p->title_width = __MENULIST_TITLE_WIDTH__;
        menulist_p->title_height = __MENUITEM_BG_HEIGHT__;

    #else
        gdi_image_get_dimension_id(IMG_ID_CAMCO_MENUITEM_BG_1, &menulist_p->item_width, &menulist_p->item_height);
        gdi_image_get_dimension_id(IMG_ID_CAMCO_MENULIST_TITLE, &menulist_p->title_width, &menulist_p->title_height);
    #endif
    gdi_image_get_dimension_id(IMG_ID_CAMCO_RADIO_EMPTY, &menulist_p->radio_width, &menulist_p->radio_height);

    menulist_p->max_disp_item_count = mmi_camco_osd_skin_p->option.menu_count;

    menulist_p->radio_shift_y = 0;      /* not used */
    menulist_p->radio_shift_x = 0;      /* not used */
    menulist_p->item_img_shift_y = 0;   /* not used */
    menulist_p->item_img_shift_x = 0;   /* not used */

    menulist_p->highlighted_idx = 0;

    menulist_p->touch_down_highlighted_idx = 0;
    menulist_p->touch_up_highlighted_idx = 0;
    menulist_p->is_scrolling = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_gen_option_menulist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_gen_option_menulist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_menulist_struct *menulist_p = &mmi_camco_osd_p->option_menulist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->act_menulist_p = &mmi_camco_osd_p->option_menulist;
    menulist_p = mmi_camco_osd_p->act_menulist_p;

    memset(menulist_p->item_list, 0, sizeof(menulist_p->item_list));

    menulist_p->item_count = 0;
    menulist_p->state = MMI_CAMCO_OSD_MENULIST_STATE_EXIT;
    menulist_p->hilite_img_id = IMG_ID_CAMCO_MENUITEM_HL_MISC;
    menulist_p->active_idx = 0;
    menulist_p->item_count = 0;
    menulist_p->first_disp_idx = 0;
    menulist_p->disp_item_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_video_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_video_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_camco_osd_video_progress_struct *progress_p = &mmi_camco_osd_p->video_progress;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_get_dimension_id(IMG_ID_CAMCO_OSD_TIMER_0, &progress_p->num_img_width, &progress_p->num_img_height);
    gdi_image_get_dimension_id(IMG_ID_CAMCO_OSD_TIMER_COLON, &progress_p->col_img_width, &progress_p->col_img_height);

    progress_p->dot_offset_x = mmi_camco_osd_skin_p->video_record.record_dot.offset_x;
    progress_p->dot_offset_y = mmi_camco_osd_skin_p->video_record.record_dot.offset_y;

    progress_p->time_offset_x = progress_p->dot_offset_x + 2 * MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS +   /* 2 means one diameter is two radius */
        MMI_CAMCO_OSD_RECORD_TIME_TIMER_SHIFT;

    progress_p->time_offset_y = progress_p->dot_offset_y;

    progress_p->progress_offset_x = progress_p->time_offset_x + 2 * MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS + 6 * progress_p->num_img_width +      /* 6 means there are six numbers */
        2 * progress_p->col_img_width + /* 2 means there are two colon   */
        MMI_CAMCO_OSD_RECORD_TIME_TIMER_SHIFT;

    progress_p->progress_offset_y = progress_p->time_offset_y;

}

#ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_imageselect_set_cache_img_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  offset_x            [IN]        
 *  offset_y            [IN]        
 *  resized_width       [IN]        
 *  resized_height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_imageselect_set_cache_img_info(S32 offset_x, S32 offset_y, S32 resized_width, S32 resized_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->imgselect_cache.cache_resized_offset_x = offset_x;
    mmi_camco_osd_p->imgselect_cache.cache_resized_offset_y = offset_y;
    mmi_camco_osd_p->imgselect_cache.cache_resized_width = resized_width;
    mmi_camco_osd_p->imgselect_cache.cache_resized_height = resized_height;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_imageselect_set_cache_layer_buf_p
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_imageselect_set_cache_layer_buf_p(void *buf_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->imageselect_cache_layer_buf_p = (U8*) buf_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_imageselect_setup_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_imageselect_setup_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 buf_size = 0;
    S32 cache_osd_width;
    S32 cache_osd_height;
    S32 offset_y = 0;

    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_skin_p->multiselect_cache.is_horizontal_display)
    {
        cache_osd_width = mmi_camco_osd_p->osd_width;
        cache_osd_height = MMI_CAMCO_OSD_IMGSEL_CACHE_LAYER_HOR_HEIGHT;
        offset_y = mmi_camco_osd_skin_p->multiselect_cache.border.offset_y -
            MMI_CAMCO_OSD_IMGSEL_CACHE_LAYER_EXTEND_LENGTH;
    }
    else
    {
        cache_osd_width =
            MMI_CAMCO_OSD_IMGSEL_CACHE_LAYER_VER_WIDTH + mmi_camco_osd_skin_p->multiselect_cache.border.offset_x;
        cache_osd_height = mmi_camco_osd_p->osd_height;
    }

    buf_size = ((cache_osd_width * cache_osd_height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3);

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        mmi_camco_osd_p->imgselect_cache.cache_layer_width = cache_osd_height;
        mmi_camco_osd_p->imgselect_cache.cache_layer_height = cache_osd_width;
    }            
#ifdef DUAL_CAMERA_SUPPORT
    else
    {           
        mmi_camco_osd_p->imgselect_cache.cache_layer_width = cache_osd_width;
        mmi_camco_osd_p->imgselect_cache.cache_layer_height = cache_osd_height;
    }        
#endif /* DUAL_CAMERA_SUPPORT */ 
#else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */    
    mmi_camco_osd_p->imgselect_cache.cache_layer_width = cache_osd_width;
    mmi_camco_osd_p->imgselect_cache.cache_layer_height = cache_osd_height;
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */   

    MMI_ASSERT(mmi_camco_osd_p->imageselect_cache_layer_buf_p != NULL);

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {

        gdi_layer_create_using_outside_memory(
            0,
            0,
            cache_osd_height,
            cache_osd_width,
            &mmi_camco_osd_p->imageselect_cache_layer_h,
            (U8*) mmi_camco_osd_p->imageselect_cache_layer_buf_p,
            buf_size);
    }            
#ifdef DUAL_CAMERA_SUPPORT
    else
    {           
        gdi_layer_create_using_outside_memory(
            0,
            0,
            cache_osd_width,
            cache_osd_height,
            &mmi_camco_osd_p->imageselect_cache_layer_h,
            (U8*) mmi_camco_osd_p->imageselect_cache_layer_buf_p,
            buf_size);
    }        
#endif /* DUAL_CAMERA_SUPPORT */ 
#else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */    
    gdi_layer_create_using_outside_memory(
        0,
        0,
        cache_osd_width,
        cache_osd_height,
        &mmi_camco_osd_p->imageselect_cache_layer_h,
        (U8*) mmi_camco_osd_p->imageselect_cache_layer_buf_p,
        buf_size);
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */   


    gdi_layer_push_and_set_active(mmi_camco_osd_p->imageselect_cache_layer_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    if (mmi_camco_osd_skin_p->multiselect_cache.is_horizontal_display)
    {
    #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
        if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
        {
            gdi_layer_set_position(mmi_camco_osd_p->osd_height - cache_osd_height - offset_y, 0);    
        }            
    #ifdef DUAL_CAMERA_SUPPORT
        else
        {           
            gdi_layer_set_position(0, offset_y);
        }        
    #endif /* DUAL_CAMERA_SUPPORT */ 
    #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */    
        gdi_layer_set_position(0, offset_y);
    #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */      
    }
    else
    {
        gdi_layer_set_position(0, 0);
    }

    gdi_layer_pop_and_restore_active();

    if (mmi_camco_osd_skin_p->multiselect_cache.is_horizontal_display)
    {
        imgselect_cache_p->la_touch.is_usable = MMI_TRUE;
        imgselect_cache_p->ra_touch.is_usable = MMI_TRUE;
    }
    else
    {
        imgselect_cache_p->ua_touch.is_usable = MMI_TRUE;
        imgselect_cache_p->da_touch.is_usable = MMI_TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_imageselect_reset_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_imageselect_reset_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imgselect_cache_p->la_touch.is_usable = MMI_FALSE;
    imgselect_cache_p->ra_touch.is_usable = MMI_FALSE;
    imgselect_cache_p->ua_touch.is_usable = MMI_FALSE;
    imgselect_cache_p->da_touch.is_usable = MMI_FALSE;

    imgselect_cache_p->la_touch.is_press = MMI_FALSE;
    imgselect_cache_p->ra_touch.is_press = MMI_FALSE;
    imgselect_cache_p->ua_touch.is_press = MMI_FALSE;
    imgselect_cache_p->da_touch.is_press = MMI_FALSE;

    if (mmi_camco_osd_p->imageselect_cache_layer_h == GDI_NULL_HANDLE)
    {
        return;
    }

    if (mmi_camco_osd_p->imageselect_cache_layer_h)
    {
        gdi_layer_free(mmi_camco_osd_p->imageselect_cache_layer_h);
        mmi_camco_osd_p->imageselect_cache_layer_h = GDI_NULL_HANDLE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_imgselect_highlight_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_imgselect_highlight_idx(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_IMAGE_SELECTION)
    {
        imgselect_cache_p->highlighted_idx = index;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_imgselect_shown_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_p               [OUT]       
 *  buf_filename_pp     [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_get_imgselect_shown_size(U16 *w, U16 *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (*w) = MMI_CAMCO_CAM_CACHE_IMAGE_WIDTH;
    (*h) = MMI_CAMCO_CAM_CACHE_IMAGE_HEIGHT;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_imgselect_cur_img_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_p               [OUT]       
 *  buf_filename_pp     [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_get_imgselect_cur_img_info(U16 *idx_p, CHAR**buf_filename_pp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *idx_p = imgselect_cache_p->highlighted_idx;
    *buf_filename_pp = imgselect_cache_p->buf_filename[imgselect_cache_p->highlighted_idx];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_imgselect_filepath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  buf_filename_p      [OUT]
 *****************************************************************************/
extern CHAR* mmi_camco_osd_get_imgselect_filepath(U16 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return imgselect_cache_p->buf_filename[idx];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_image_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_init_image_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imgselect_cache_p->cache_img_width = MMI_CAMCO_CAM_CACHE_IMAGE_WIDTH;
    imgselect_cache_p->cache_img_height = MMI_CAMCO_CAM_CACHE_IMAGE_HEIGHT;

    imgselect_cache_p->is_horizontal_display = (MMI_BOOL) mmi_camco_osd_skin_p->multiselect_cache.is_horizontal_display;
    imgselect_cache_p->interval = mmi_camco_osd_skin_p->multiselect_cache.interval;
    imgselect_cache_p->max_display_count = mmi_camco_osd_skin_p->multiselect_cache.display_count;
    imgselect_cache_p->disp_cache_count = 0;

    imgselect_cache_p->highlight_color = gdi_act_color_from_rgb(255, 240, 228, 15);
    imgselect_cache_p->highlight_border_color = GDI_COLOR_WHITE;

    imgselect_cache_p->cache_img_osd_touch = NULL;
    imgselect_cache_p->is_cache_img_osd_redraw = MMI_TRUE;
    mmi_camco_osd_p->imgselect_cache.is_cache_highlight_osd_redraw = MMI_TRUE;
    mmi_camco_osd_p->imageselect_cache_layer_h = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_image_select_filename_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buff_address        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_init_image_select_filename_buffer(CHAR* buff_address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CAMCO_CAM_CACHE_IMAGE_COUNT; i++)
    {
        imgselect_cache_p->buf_filename[i] = buff_address;
        memset(imgselect_cache_p->buf_filename[i], 0, SRV_FMGR_PATH_BUFFER_SIZE);
        buff_address += SRV_FMGR_PATH_BUFFER_SIZE;
    }

    imgselect_cache_p->first_disp_idx = 0;
    imgselect_cache_p->highlighted_idx = imgselect_cache_p->first_disp_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_deinit_image_select_filename_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_deinit_image_select_filename_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->imgselect_cache.buf_filename[0] != NULL)
    {
        U8 i;

        for (i = 0; i < MMI_CAMCO_CAM_CACHE_IMAGE_COUNT; i++)
        {
            mmi_camco_osd_p->imgselect_cache.buf_filename[i] = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_gen_image_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_gen_image_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;
    S32 image_width = 0;
    S32 image_height = 0;
    const U8 MMI_CMACO_ARROW_OFFSET = mmi_camco_osd_skin_p->multiselect_cache.arrow_interval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_get_multiselect_img_info(
        &imgselect_cache_p->img_count,
        &imgselect_cache_p->img_p,
        &imgselect_cache_p->cache_imgdata_pp,
        &imgselect_cache_p->save_flag_p);

    if (imgselect_cache_p->img_count >= imgselect_cache_p->max_display_count)
    {
        imgselect_cache_p->disp_cache_count = imgselect_cache_p->max_display_count;
        imgselect_cache_p->centralize_shift = 0;
    }
    else
    {
        imgselect_cache_p->disp_cache_count = imgselect_cache_p->img_count;
        if (imgselect_cache_p->is_horizontal_display == MMI_TRUE)
        {
            imgselect_cache_p->centralize_shift =
                (mmi_camco_osd_p->osd_width - mmi_camco_osd_p->lsk.touch.width -
                 imgselect_cache_p->disp_cache_count * imgselect_cache_p->cache_img_width -
                 (imgselect_cache_p->disp_cache_count - 1) * imgselect_cache_p->interval) >> 1;
        }
        else
        {
            imgselect_cache_p->centralize_shift =
                (mmi_camco_osd_p->osd_height - mmi_camco_osd_p->lsk.touch.height-
                 imgselect_cache_p->disp_cache_count * imgselect_cache_p->cache_img_height -
                 (imgselect_cache_p->disp_cache_count - 1) * imgselect_cache_p->interval) >> 1;
        }
    }

    imgselect_cache_p->cache_img_osd_touch = gui_malloc(imgselect_cache_p->disp_cache_count * sizeof(mmi_camco_osd_touch_obj_struct));
    MMI_ASSERT(imgselect_cache_p->cache_img_osd_touch != NULL);

    imgselect_cache_p->cache_img_osd_touch[0].width = imgselect_cache_p->cache_img_width;
    imgselect_cache_p->cache_img_osd_touch[0].height = imgselect_cache_p->cache_img_height;

    if (imgselect_cache_p->centralize_shift > 0)
    {
        if (imgselect_cache_p->is_horizontal_display == MMI_TRUE)
        {
            imgselect_cache_p->cache_img_osd_touch[0].offset_x = imgselect_cache_p->centralize_shift;
            imgselect_cache_p->cache_img_osd_touch[0].offset_y =
                mmi_camco_osd_skin_p->multiselect_cache.border.offset_y;
        }
        else
        {
            imgselect_cache_p->cache_img_osd_touch[0].offset_y = imgselect_cache_p->centralize_shift;
            imgselect_cache_p->cache_img_osd_touch[0].offset_x =
                mmi_camco_osd_skin_p->multiselect_cache.border.offset_x;
        }
    }
    else
    {
        imgselect_cache_p->cache_img_osd_touch[0].offset_x = mmi_camco_osd_skin_p->multiselect_cache.border.offset_x;
        imgselect_cache_p->cache_img_osd_touch[0].offset_y = mmi_camco_osd_skin_p->multiselect_cache.border.offset_y;
    }

    for (i = 1; i < imgselect_cache_p->disp_cache_count; i++)
    {
        if (imgselect_cache_p->is_horizontal_display == MMI_TRUE)
        {
            imgselect_cache_p->cache_img_osd_touch[i].offset_y = imgselect_cache_p->cache_img_osd_touch[0].offset_y;
            imgselect_cache_p->cache_img_osd_touch[i].offset_x =
                imgselect_cache_p->cache_img_osd_touch[i - 1].offset_x
                + imgselect_cache_p->cache_img_osd_touch[i - 1].width + imgselect_cache_p->interval;
        }
        else
        {
            imgselect_cache_p->cache_img_osd_touch[i].offset_x = imgselect_cache_p->cache_img_osd_touch[0].offset_x;
            imgselect_cache_p->cache_img_osd_touch[i].offset_y =
                imgselect_cache_p->cache_img_osd_touch[i - 1].offset_y
                + imgselect_cache_p->cache_img_osd_touch[i - 1].height + imgselect_cache_p->interval;

        }
        imgselect_cache_p->cache_img_osd_touch[i].width = imgselect_cache_p->cache_img_osd_touch[0].width;
        imgselect_cache_p->cache_img_osd_touch[i].height = imgselect_cache_p->cache_img_osd_touch[0].height;
    }

    for (i = 0; i < MMI_CAMCO_CAM_CACHE_IMAGE_COUNT; i++)
    {
        imgselect_cache_p->cache_is_mem_blt[i] = MMI_FALSE;
    }
    imgselect_cache_p->prev_highlighted_idx = MMI_CAMCO_CAM_CACHE_IMAGE_COUNT;

    if (imgselect_cache_p->is_horizontal_display)
    {
        /* Left arrow key */
        gdi_image_get_dimension_id(IMG_ID_CAMCO_MULTISHOT_ARROW_LEFT, &image_width, &image_height);
        imgselect_cache_p->la_touch.offset_x =
            imgselect_cache_p->cache_img_osd_touch[0].offset_x - image_width - MMI_CMACO_ARROW_OFFSET;

        imgselect_cache_p->la_touch.offset_y =
            imgselect_cache_p->cache_img_osd_touch[0].offset_y +
            (imgselect_cache_p->cache_img_height - image_height) / 2;

        imgselect_cache_p->la_touch.width = image_width;
        imgselect_cache_p->la_touch.height = image_height;

        /* Right arrow key */
        gdi_image_get_dimension_id(IMG_ID_CAMCO_MULTISHOT_ARROW_RIGHT, &image_width, &image_height);
        imgselect_cache_p->ra_touch.offset_x =
            imgselect_cache_p->cache_img_osd_touch[imgselect_cache_p->img_count - 1].offset_x +
            imgselect_cache_p->cache_img_width + MMI_CMACO_ARROW_OFFSET;

        imgselect_cache_p->ra_touch.offset_y =
            imgselect_cache_p->cache_img_osd_touch[imgselect_cache_p->img_count - 1].offset_y +
            (imgselect_cache_p->cache_img_height - image_height) / 2;

        imgselect_cache_p->ra_touch.width = image_width;
        imgselect_cache_p->ra_touch.height = image_height;
    }
    else
    {
        /* Up arrow key */
        gdi_image_get_dimension_id(IMG_ID_CAMCO_MULTISHOT_ARROW_UP, &image_width, &image_height);
        imgselect_cache_p->ua_touch.offset_x =
            imgselect_cache_p->cache_img_osd_touch[0].offset_x + (imgselect_cache_p->cache_img_width - image_width) / 2;

        imgselect_cache_p->ua_touch.offset_y =
            imgselect_cache_p->cache_img_osd_touch[0].offset_y - image_height - MMI_CMACO_ARROW_OFFSET;
        imgselect_cache_p->ua_touch.width = image_width;
        imgselect_cache_p->ua_touch.height = image_height;

        /* Down arrow key */
        gdi_image_get_dimension_id(IMG_ID_CAMCO_MULTISHOT_ARROW_DOWN, &image_width, &image_height);
        imgselect_cache_p->da_touch.offset_x =
            imgselect_cache_p->cache_img_osd_touch[imgselect_cache_p->img_count - 1].offset_x +
            (imgselect_cache_p->cache_img_width - image_width) / 2;

        imgselect_cache_p->da_touch.offset_y =
            imgselect_cache_p->cache_img_osd_touch[imgselect_cache_p->img_count - 1].offset_y +
            imgselect_cache_p->cache_img_height + MMI_CMACO_ARROW_OFFSET;
        imgselect_cache_p->da_touch.width = image_width;
        imgselect_cache_p->da_touch.height = image_height;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_image_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_draw_image_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 start_idx, end_idx;
    U8 cache_highlighted_idx = 0;
    gdi_rect_struct clip;
    S32 image_region_offset_x;
    S32 image_region_offset_y;
    S32 image_region_width;
    S32 image_region_height;
    S32 resized_offset_x = 0;
    S32 resized_offset_y = 0;
    S32 resized_width = 0;
    S32 resized_height = 0;
    S32 image_width = 0;
    S32 image_height = 0;
    S32 pick_offset_x = 0;
    S32 pick_offset_y = 0;
    S32 offset_x;
    S32 offset_y;
    PU8 image_buf_ptr;
    U32 image_buf_size;
    BOOL is_draw_highlighted_image = TRUE;

    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

#ifdef __MMI_INTERACTIVE_PROFILNG__
    U32 tempticks_start = 0;
    U32 tempticks_end = 0;
#endif /* __MMI_INTERACTIVE_PROFILNG__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    end_idx = imgselect_cache_p->first_disp_idx + imgselect_cache_p->disp_cache_count;

    /* draw cache image */
    gdi_layer_push_and_set_active(mmi_camco_osd_p->imageselect_cache_layer_h);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    if (imgselect_cache_p->is_cache_img_osd_redraw)
    {

        for (start_idx = imgselect_cache_p->first_disp_idx; start_idx < end_idx; start_idx++)
        {

            if (start_idx < imgselect_cache_p->draw_cache_image_count &&
                !imgselect_cache_p->cache_is_mem_blt[start_idx])
            {

                if (imgselect_cache_p->is_horizontal_display)
                {
                    clip.x1 = imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x;
                    clip.y1 = MMI_CAMCO_OSD_IMGSEL_CACHE_LAYER_EXTEND_LENGTH;
                    clip.x2 =
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x +
                        imgselect_cache_p->cache_img_osd_touch[start_idx].width - 1;
                    clip.y2 = clip.y1 + imgselect_cache_p->cache_img_osd_touch[start_idx].height - 1;
                }
                else
                {
                    clip.x1 = imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x;
                    clip.y1 = imgselect_cache_p->cache_img_osd_touch[start_idx].offset_y;
                    clip.x2 =
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x +
                        imgselect_cache_p->cache_img_osd_touch[start_idx].width - 1;
                    clip.y2 =
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_y +
                        imgselect_cache_p->cache_img_osd_touch[start_idx].height - 1;
                }

                gdi_2d_memory_blt_without_transpant_check(
                    imgselect_cache_p->cache_imgdata_pp[start_idx],
                    imgselect_cache_p->cache_img_width,
                    0,
                    0,
                    imgselect_cache_p->cache_img_width,
                    imgselect_cache_p->cache_img_height,
                    (U8*) mmi_camco_osd_p->imageselect_cache_layer_buf_p,
                    imgselect_cache_p->cache_layer_width,
                    clip.x1,
                    clip.y1,
                    clip,
                    GDI_MAINLCD_BIT_PER_PIXEL);

                imgselect_cache_p->cache_is_mem_blt[start_idx] = MMI_TRUE;



                if (imgselect_cache_p->is_horizontal_display)
                {
                    gdi_draw_rect(
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x - 1,
                        clip.y1 - 1,
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x + imgselect_cache_p->cache_img_osd_touch[start_idx].width,
                        clip.y1 + imgselect_cache_p->cache_img_osd_touch[start_idx].height,
                        GDI_COLOR_BLACK);
                }
                else
                {
                    gdi_draw_rect(
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x - 1,
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_y - 1,
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x + imgselect_cache_p->cache_img_osd_touch[start_idx].width,
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_y + imgselect_cache_p->cache_img_osd_touch[start_idx].height,
                        GDI_COLOR_BLACK);
                }
			    imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x += imgselect_cache_p->cache_resized_offset_x;
                imgselect_cache_p->cache_img_osd_touch[start_idx].offset_y += imgselect_cache_p->cache_resized_offset_y;
                imgselect_cache_p->cache_img_osd_touch[start_idx].width = imgselect_cache_p->cache_resized_width;
                imgselect_cache_p->cache_img_osd_touch[start_idx].height = imgselect_cache_p->cache_resized_height;

            }

        }

    }

    gdi_layer_pop_and_restore_active();

    /* draw highlight image */
    gdi_layer_push_and_set_active(mmi_camco_osd_p->base_layer_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    if (imgselect_cache_p->is_horizontal_display)
    {
        is_draw_highlighted_image = !(imgselect_cache_p->la_touch.is_press | imgselect_cache_p->ra_touch.is_press);
    }
    else
    {
        is_draw_highlighted_image = !(imgselect_cache_p->ua_touch.is_press | imgselect_cache_p->da_touch.is_press);
    }

    if (is_draw_highlighted_image == TRUE &&
        imgselect_cache_p->highlighted_idx != imgselect_cache_p->prev_highlighted_idx)
    {
        mmi_camco_get_preview_region(
            &image_region_offset_x,
            &image_region_offset_y,
            &image_region_width,
            &image_region_height);

        gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

    #ifdef __MMI_INTERACTIVE_PROFILNG__
        if (mmi_frm_profiling_interactive_is_enabled())
        {
            kal_get_time(&tempticks_start);
        }
    #endif /* __MMI_INTERACTIVE_PROFILNG__ */ 

        MMI_CAMCO_START_LOGGING("DEC");

        image_buf_ptr = (PU8) imgselect_cache_p->img_p->file_address[imgselect_cache_p->highlighted_idx];
        image_buf_size = imgselect_cache_p->img_p->file_size[imgselect_cache_p->highlighted_idx];
        gdi_image_jpeg_get_dimension_no_rotate(image_buf_ptr, image_buf_size, &image_width, &image_height);

        if ((image_region_width >= image_width) && (image_region_height >= image_height))
        {
            /* align preview window at the center of screen */
            offset_x = ((image_region_width - image_width) >> 1);
            offset_y = ((image_region_height - image_height) >> 1);

            gdi_image_jpeg_draw_no_rotate(offset_x, offset_y, image_buf_ptr, image_buf_size);
        }
        else
        {
           /* gdi_image_util_fit_bbox(
                image_region_width,
                image_region_height,
                image_width,
                image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);*/

            gdi_image_jpeg_draw_resized_no_rotate(
                0,
                0,
                image_region_width,
                image_region_height,
                image_buf_ptr,
                image_buf_size);
        }
        imgselect_cache_p->prev_highlighted_idx = imgselect_cache_p->highlighted_idx;

    #ifdef __MMI_INTERACTIVE_PROFILNG__
        if (mmi_frm_profiling_interactive_is_enabled())
        {
            kal_get_time(&tempticks_end);
            MMI_TRACE(
                MMI_MEDIA_TRC_G2_APP,
                MMI_TRC_CAMCO_CAM_DEC_DUR,
                (U32) ((tempticks_end - tempticks_start) * 4.615));
        }
    #endif /* __MMI_INTERACTIVE_PROFILNG__ */ /* __MMI_INTERACTIVE_PROFILNG_ */

        MMI_CAMCO_STOP_LOGGING("DEC");
    }

    gdi_layer_pop_and_restore_active();

    if (!imgselect_cache_p->is_cache_highlight_osd_redraw)
    {
        return;
    }
    /* draw highlight rectangle on osd layer */
    if (imgselect_cache_p->is_horizontal_display)
    {
        offset_x = imgselect_cache_p->la_touch.offset_x;
        offset_y = imgselect_cache_p->la_touch.offset_y;
        if (imgselect_cache_p->la_touch.is_press)
        {
            #ifdef __MMI_FTE_SUPPORT__
                gdi_image_draw_id(offset_x + 1, offset_y + 1, IMG_ID_CAMCO_MULTISHOT_ARROW_LEFT_SEL);
            #else
                gdi_image_draw_id(offset_x + 1, offset_y + 1, IMG_ID_CAMCO_MULTISHOT_ARROW_LEFT);
            #endif
        }
        else
        {
            gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMCO_MULTISHOT_ARROW_LEFT);
        }

        offset_x = imgselect_cache_p->ra_touch.offset_x;
        offset_y = imgselect_cache_p->ra_touch.offset_y;
        if (imgselect_cache_p->ra_touch.is_press)
        {
            #ifdef __MMI_FTE_SUPPORT__
                gdi_image_draw_id(offset_x + 1, offset_y + 1, IMG_ID_CAMCO_MULTISHOT_ARROW_RIGHT_SEL);
            #else        
                gdi_image_draw_id(offset_x + 1, offset_y + 1, IMG_ID_CAMCO_MULTISHOT_ARROW_RIGHT);
            #endif
        }
        else
        {
            gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMCO_MULTISHOT_ARROW_RIGHT);
        }

    }
    else
    {
        offset_x = imgselect_cache_p->ua_touch.offset_x;
        offset_y = imgselect_cache_p->ua_touch.offset_y;
		#ifndef __MMI_FTE_SUPPORT__ 
        if (imgselect_cache_p->ua_touch.is_press)
        {   
            gdi_image_draw_id(offset_x + 1, offset_y + 1, IMG_ID_CAMCO_MULTISHOT_ARROW_UP);
        }
        else
        {
            gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMCO_MULTISHOT_ARROW_UP);
        }
        #endif
        offset_x = imgselect_cache_p->da_touch.offset_x;
        offset_y = imgselect_cache_p->da_touch.offset_y;
       #ifndef __MMI_FTE_SUPPORT__ 
        if (imgselect_cache_p->da_touch.is_press)
        {
            gdi_image_draw_id(offset_x + 1, offset_y + 1, IMG_ID_CAMCO_MULTISHOT_ARROW_DOWN);
       
        }
        else
        {
            gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMCO_MULTISHOT_ARROW_DOWN);
        }
		#endif
    }

    cache_highlighted_idx = imgselect_cache_p->highlighted_idx - imgselect_cache_p->first_disp_idx;
    gdi_draw_rect(
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_x,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_y,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_x + imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].width,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_y + imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].height,
        imgselect_cache_p->highlight_border_color);

    gdi_draw_rect(
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_x - 1,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_y - 1,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_x + imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].width + 1,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_y + imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].height + 1,
        imgselect_cache_p->highlight_color);

    gdi_draw_rect(
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_x - 2,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_y - 2,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_x + imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].width + 2,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_y + imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].height + 2,
        imgselect_cache_p->highlight_color);

    gdi_draw_rect(
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_x - 3,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_y - 3,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_x + imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].width + 3,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_y + imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].height + 3,
        imgselect_cache_p->highlight_border_color);

    /* draw saved flag on osd layer */
    for (start_idx = imgselect_cache_p->first_disp_idx; start_idx < end_idx; start_idx++)
    {
        if (imgselect_cache_p->save_flag_p[start_idx] == TRUE)
        {
            /* Put the save flag on 75% of width and height */
            if (imgselect_cache_p->is_horizontal_display)
            {
                pick_offset_x = imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x +
                    (imgselect_cache_p->cache_img_osd_touch[start_idx].width * 2) / 3;
            }
            else
            {
                pick_offset_x = imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x +
                    (imgselect_cache_p->cache_img_osd_touch[start_idx].width * 3) / 4;
            }
            pick_offset_y = imgselect_cache_p->cache_img_osd_touch[start_idx].offset_y +
                (imgselect_cache_p->cache_img_osd_touch[start_idx].height * 3) / 4;

            gdi_image_draw_id(pick_offset_x, pick_offset_y, IMG_ID_CAMCO_PICK);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_image_select_osd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_image_select_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 start_idx, end_idx;
    U8 cache_highlighted_idx = 0;
    S32 pick_offset_x = 0;
    S32 pick_offset_y = 0;
    S32 offset_x;
    S32 offset_y;

    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    end_idx = imgselect_cache_p->first_disp_idx + imgselect_cache_p->disp_cache_count;

    if (!imgselect_cache_p->is_cache_highlight_osd_redraw)
    {
        return;
    }
    /* draw highlight rectangle on osd layer */
    if (imgselect_cache_p->is_horizontal_display)
    {
        offset_x = imgselect_cache_p->la_touch.offset_x;
        offset_y = imgselect_cache_p->la_touch.offset_y;
		#ifndef __MMI_FTE_SUPPORT__ 
		if (imgselect_cache_p->la_touch.is_press)
        {
            gdi_image_draw_id(offset_x + 1, offset_y + 1, IMG_ID_CAMCO_MULTISHOT_ARROW_LEFT);           

        }
        else
        {
            gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMCO_MULTISHOT_ARROW_LEFT);
        }
		#endif
        offset_x = imgselect_cache_p->ra_touch.offset_x;
        offset_y = imgselect_cache_p->ra_touch.offset_y;
		#ifndef __MMI_FTE_SUPPORT__ 
        if (imgselect_cache_p->ra_touch.is_press)
        {
            
            gdi_image_draw_id(offset_x + 1, offset_y + 1, IMG_ID_CAMCO_MULTISHOT_ARROW_RIGHT);
        }
        else
        {
            gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMCO_MULTISHOT_ARROW_RIGHT);
        }
		#endif

    }
    else
    {
        offset_x = imgselect_cache_p->ua_touch.offset_x;
        offset_y = imgselect_cache_p->ua_touch.offset_y;
		#ifndef __MMI_FTE_SUPPORT__ 
        if (imgselect_cache_p->ua_touch.is_press)
        {
            gdi_image_draw_id(offset_x + 1, offset_y + 1, IMG_ID_CAMCO_MULTISHOT_ARROW_UP);
        }
        else
        {
            gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMCO_MULTISHOT_ARROW_UP);
        }
		#endif

        offset_x = imgselect_cache_p->da_touch.offset_x;
        offset_y = imgselect_cache_p->da_touch.offset_y;
		#ifndef __MMI_FTE_SUPPORT__ 
		if (imgselect_cache_p->da_touch.is_press)
        {
            gdi_image_draw_id(offset_x + 1, offset_y + 1, IMG_ID_CAMCO_MULTISHOT_ARROW_DOWN);
        }
        else
        {
            gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMCO_MULTISHOT_ARROW_DOWN);
        }
		#endif
    }

    cache_highlighted_idx = imgselect_cache_p->highlighted_idx - imgselect_cache_p->first_disp_idx;
    gdi_draw_rect(
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_x,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_y,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_x + imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].width,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_y + imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].height,
        imgselect_cache_p->highlight_border_color);

    gdi_draw_rect(
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_x - 1,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_y - 1,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_x + imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].width + 1,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_y + imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].height + 1,
        imgselect_cache_p->highlight_color);

    gdi_draw_rect(
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_x - 2,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_y - 2,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_x + imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].width + 2,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_y + imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].height + 2,
        imgselect_cache_p->highlight_color);

    gdi_draw_rect(
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_x - 3,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_y - 3,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_x + imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].width + 3,
        imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].offset_y + imgselect_cache_p->cache_img_osd_touch[cache_highlighted_idx].height + 3,
        imgselect_cache_p->highlight_border_color);

    /* draw saved flag on osd layer */
    for (start_idx = imgselect_cache_p->first_disp_idx; start_idx < end_idx; start_idx++)
    {
        if (imgselect_cache_p->save_flag_p[start_idx] == TRUE)
        {
            /* Put the save flag on 75% of width and height */
            if (imgselect_cache_p->is_horizontal_display)
            {
                pick_offset_x = imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x +
                    (imgselect_cache_p->cache_img_osd_touch[start_idx].width * 2) / 3;
            }
            else
            {
                pick_offset_x = imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x +
                    (imgselect_cache_p->cache_img_osd_touch[start_idx].width * 3) / 4;
            }
            pick_offset_y = imgselect_cache_p->cache_img_osd_touch[start_idx].offset_y +
                (imgselect_cache_p->cache_img_osd_touch[start_idx].height * 3) / 4;

            gdi_image_draw_id(pick_offset_x, pick_offset_y, IMG_ID_CAMCO_PICK);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_image_select_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b_ptr       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_image_select_cache(U8 *b_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 start_idx, end_idx;
    gdi_rect_struct clip;

    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    end_idx = imgselect_cache_p->first_disp_idx + imgselect_cache_p->disp_cache_count;

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    {

        for (start_idx = imgselect_cache_p->first_disp_idx; start_idx < end_idx; start_idx++)
        {

            {

                if (imgselect_cache_p->is_horizontal_display)
                {
                    clip.x1 = imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x;
                    clip.y1 = MMI_CAMCO_OSD_IMGSEL_CACHE_LAYER_EXTEND_LENGTH;
                    clip.x2 =
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x +
                        imgselect_cache_p->cache_img_osd_touch[start_idx].width - 1;
                    clip.y2 = clip.y1 + imgselect_cache_p->cache_img_osd_touch[start_idx].height - 1;
                }
                else
                {
                    clip.x1 = imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x;
                    clip.y1 = imgselect_cache_p->cache_img_osd_touch[start_idx].offset_y;
                    clip.x2 =
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x +
                        imgselect_cache_p->cache_img_osd_touch[start_idx].width - 1;
                    clip.y2 =
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_y +
                        imgselect_cache_p->cache_img_osd_touch[start_idx].height - 1;
                }

                gdi_2d_memory_blt_without_transpant_check(
                    imgselect_cache_p->cache_imgdata_pp[start_idx],
                    imgselect_cache_p->cache_img_width,
                    0,
                    0,
                    imgselect_cache_p->cache_img_width,
                    imgselect_cache_p->cache_img_height,
                    (U8*) b_ptr,
                    imgselect_cache_p->cache_layer_height,
                    clip.x1,
                    clip.y1,
                    clip,
                    GDI_MAINLCD_BIT_PER_PIXEL);

                imgselect_cache_p->cache_is_mem_blt[start_idx] = MMI_TRUE;
                
                if (imgselect_cache_p->is_horizontal_display)
                {
                    gdi_draw_rect(
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x - 1,
                        clip.y1 - 1,
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x + imgselect_cache_p->cache_img_osd_touch[start_idx].width,
                        clip.y1 + imgselect_cache_p->cache_img_osd_touch[start_idx].height,
                        GDI_COLOR_BLACK);
                }
                else
                {
                    gdi_draw_rect(
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x - 1,
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_y - 1,
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_x + imgselect_cache_p->cache_img_osd_touch[start_idx].width,
                        imgselect_cache_p->cache_img_osd_touch[start_idx].offset_y + imgselect_cache_p->cache_img_osd_touch[start_idx].height,
                        GDI_COLOR_BLACK);
                }

            }

        }

    }

}

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_image_select_hilite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_image_select_hilite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_region_offset_x;
    S32 image_region_offset_y;
    S32 image_region_width;
    S32 image_region_height;
    S32 resized_offset_x = 0;
    S32 resized_offset_y = 0;
    S32 resized_width = 0;
    S32 resized_height = 0;
    S32 image_width = 0;
    S32 image_height = 0;
    S32 offset_x;
    S32 offset_y;
    PU8 image_buf_ptr;
    U32 image_buf_size;
    BOOL is_draw_highlighted_image = TRUE;

    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

#ifdef __MMI_INTERACTIVE_PROFILNG__
    U32 tempticks_start = 0;
    U32 tempticks_end = 0;
#endif /* __MMI_INTERACTIVE_PROFILNG__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* draw highlight image */
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    if (imgselect_cache_p->is_horizontal_display)
    {
        is_draw_highlighted_image = !(imgselect_cache_p->la_touch.is_press | imgselect_cache_p->ra_touch.is_press);
    }
    else
    {
        is_draw_highlighted_image = !(imgselect_cache_p->ua_touch.is_press | imgselect_cache_p->da_touch.is_press);
    }

    if (is_draw_highlighted_image == TRUE &&
        imgselect_cache_p->highlighted_idx != imgselect_cache_p->prev_highlighted_idx)
    {
        mmi_camco_get_preview_region(
            &image_region_offset_x,
            &image_region_offset_y,
            &image_region_width,
            &image_region_height);

        gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

    #ifdef __MMI_INTERACTIVE_PROFILNG__
        if (mmi_frm_profiling_interactive_is_enabled())
        {
            kal_get_time(&tempticks_start);
        }
    #endif /* __MMI_INTERACTIVE_PROFILNG__ */ 

        MMI_CAMCO_START_LOGGING("DEC");

        image_buf_ptr = (PU8) imgselect_cache_p->img_p->file_address[imgselect_cache_p->highlighted_idx];
        image_buf_size = imgselect_cache_p->img_p->file_size[imgselect_cache_p->highlighted_idx];
        gdi_image_jpeg_get_dimension_no_rotate(image_buf_ptr, image_buf_size, &image_width, &image_height);
        gdi_layer_resize(image_region_width,image_region_height);
        if ((image_region_width >= image_width) && (image_region_height >= image_height))
        {
            /* align preview window at the center of screen */
            offset_x = ((image_region_width - image_width) >> 1);
            offset_y = ((image_region_height - image_height) >> 1);

            gdi_image_jpeg_draw_no_rotate(offset_x, offset_y, image_buf_ptr, image_buf_size);
        }
        else
        {
            /*gdi_image_util_fit_bbox(
                image_region_width,
                image_region_height,
                image_width,
                image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);*/

            gdi_image_jpeg_draw_resized_no_rotate(
                0,
                0,
                image_region_width,
                image_region_height,
                image_buf_ptr,
                image_buf_size);
        }
        imgselect_cache_p->prev_highlighted_idx = imgselect_cache_p->highlighted_idx;

	mmi_camco_osd_rotate_for_hw_rotate(
		mmi_camco_osd_p->osd_layer_draw_h,
		mmi_camco_osd_p->base_layer_h);

    #ifdef __MMI_INTERACTIVE_PROFILNG__
        if (mmi_frm_profiling_interactive_is_enabled())
        {
            kal_get_time(&tempticks_end);
            MMI_TRACE(
                MMI_MEDIA_TRC_G2_APP,
                MMI_TRC_CAMCO_CAM_DEC_DUR,
                (U32) ((tempticks_end - tempticks_start) * 4.615));
        }
    #endif /* __MMI_INTERACTIVE_PROFILNG__ */ /* __MMI_INTERACTIVE_PROFILNG_ */

        MMI_CAMCO_STOP_LOGGING("DEC");
    }


}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_redraw_image_select_highlight_osd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_redraw       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_redraw_image_select_highlight_osd(MMI_BOOL is_redraw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->imgselect_cache.is_cache_highlight_osd_redraw = is_redraw;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_redraw_image_select_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_redraw       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_redraw_image_select_cache(MMI_BOOL is_redraw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->imgselect_cache.is_cache_img_osd_redraw = is_redraw;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_draw_image_select_cache_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  draw_count      [IN]        Display cache count
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_draw_image_select_cache_count(U16 draw_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->imgselect_cache.draw_cache_image_count = draw_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_imgselect_prev_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_imgselect_prev_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_imgselect_move_prev())
    {
        mmi_camco_updata_key_handler();
        mmi_camco_osd_draw_osd();

        gui_start_timer(MMI_CAMCO_OSD_TOUCH_IMGSELECT_MOVE_DUR, mmi_camco_osd_imgselect_prev_cyclic);

    }
    else
    {
        imgselect_cache_p->highlighted_idx = imgselect_cache_p->img_count - 1;

        mmi_camco_updata_key_handler();
        mmi_camco_osd_draw_osd();

        gui_start_timer(MMI_CAMCO_OSD_TOUCH_IMGSELECT_MOVE_DUR, mmi_camco_osd_imgselect_prev_cyclic);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_imgselect_next_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_imgselect_next_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_imgselect_move_next())
    {
        mmi_camco_updata_key_handler();
        mmi_camco_osd_draw_osd();

        gui_start_timer(MMI_CAMCO_OSD_TOUCH_IMGSELECT_MOVE_DUR, mmi_camco_osd_imgselect_next_cyclic);

    }
    else
    {
        imgselect_cache_p->highlighted_idx = 0;

        mmi_camco_updata_key_handler();
        mmi_camco_osd_draw_osd();

        gui_start_timer(MMI_CAMCO_OSD_TOUCH_IMGSELECT_MOVE_DUR, mmi_camco_osd_imgselect_next_cyclic);
    }
}
#endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 


#ifdef __MMI_CAMCO_FEATURE_OSD_AUTORAMA__

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_autorama_shot_osd_info
 * DESCRIPTION
 *  set autorama info for osd draw
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_autorama_shot_osd_info(S32 mov_x,S32 mov_y,S32 overlap_ratio,mmi_camco_autorama_direction_enum dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_camco_osd_cntx.autorama.overlap_ratio = overlap_ratio;
    g_mmi_camco_osd_cntx.autorama.regist_mov_offset_x = mov_x;
    g_mmi_camco_osd_cntx.autorama.regist_mov_offset_y = mov_y;
    g_mmi_camco_osd_cntx.autorama.autorama_direct = dir;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_autorama_cache_image
 * DESCRIPTION
 *  set autorama quick view image data for osd display
 * PARAMETERS
 *  cache_imgdata_pp    [IN]   point to quick view data point
 *  img_count                [IN]   Image count 
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_autorama_cache_image(U8* cache_imgdata_pp,S32 img_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    g_mmi_camco_osd_cntx.autorama.cache_imgdata_pp = cache_imgdata_pp;
    g_mmi_camco_osd_cntx.autorama.img_count = img_count;
    g_mmi_camco_osd_cntx.autorama.regist_mov_offset_x = 0;//ybyang why reset offset for image 
    g_mmi_camco_osd_cntx.autorama.regist_mov_offset_y = 0;
        


}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_autorama_selection
 * DESCRIPTION
 *  Draw autorama direction selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_autorama_direction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* draw up icon */
   
    gdi_image_draw_id( 
        mmi_camco_osd_skin_p->autorama.ua.offset_x,
        mmi_camco_osd_skin_p->autorama.ua.offset_y,
        IMG_ID_CAMCO_CAPMODE_AUTORAMA_DIR_UP);
  
    /* draw down icon */   
    
    gdi_image_draw_id(
        mmi_camco_osd_skin_p->autorama.da.offset_x,
        mmi_camco_osd_skin_p->autorama.da.offset_y,
        IMG_ID_CAMCO_CAPMODE_AUTORAMA_DIR_DOWN);

    /* draw left icon */
    
    gdi_image_draw_id(
        mmi_camco_osd_skin_p->autorama.la.offset_x,
        mmi_camco_osd_skin_p->autorama.la.offset_y,
        IMG_ID_CAMCO_CAPMODE_AUTORAMA_DIR_LEFT);

    /* draw right icon */
    
    gdi_image_draw_id(
        mmi_camco_osd_skin_p->autorama.ra.offset_x,
        mmi_camco_osd_skin_p->autorama.ra.offset_y,
        IMG_ID_CAMCO_CAPMODE_AUTORAMA_DIR_RIGHT);
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_setting_get_autorama_direction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  direction     [OUT]    direction
 *****************************************************************************/
mmi_camco_autorama_direction_enum mmi_camco_osd_get_autorama_direction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_camco_osd_cntx.autorama.autorama_direct;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_autorama_shot_dir
 * DESCRIPTION
 *  Draw select autorama shot dir in autorama shot state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_autorama_shot_dir(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_autorama_direction_enum autorama_direct;
    MMI_ID_TYPE autorama_icon = NULL;
    S32 offset_x = 0;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    autorama_direct = mmi_camco_osd_get_autorama_direction();
    switch(autorama_direct)
    {
        case MMI_CAMCO_AUTORAMA_DIRECTION_UP: 
	    {
			offset_x = mmi_camco_osd_skin_p->autorama.shot_up.offset_x;
            offset_y = mmi_camco_osd_skin_p->autorama.shot_up.offset_y;  
            autorama_icon = IMG_ID_CAMCO_CAPMODE_AUTORAMA_DIR_UP ;
			break;
        }
			
	    case MMI_CAMCO_AUTORAMA_DIRECTION_DOWN:
		{
			offset_x = mmi_camco_osd_skin_p->autorama.shot_da.offset_x;
            offset_y = mmi_camco_osd_skin_p->autorama.shot_da.offset_y; 
            autorama_icon = IMG_ID_CAMCO_CAPMODE_AUTORAMA_DIR_DOWN;
			break;	
	    }
		
		case MMI_CAMCO_AUTORAMA_DIRECTION_LEFT:
	    {
			offset_x = mmi_camco_osd_skin_p->autorama.shot_la.offset_x;
            offset_y = mmi_camco_osd_skin_p->autorama.shot_la.offset_y; 
            autorama_icon = IMG_ID_CAMCO_CAPMODE_AUTORAMA_DIR_LEFT;
			break;
		}
			
		case MMI_CAMCO_AUTORAMA_DIRECTION_RIGHT:
		{
			offset_x = mmi_camco_osd_skin_p->autorama.shot_ra.offset_x;
            offset_y = mmi_camco_osd_skin_p->autorama.shot_ra.offset_y; 
            autorama_icon = IMG_ID_CAMCO_CAPMODE_AUTORAMA_DIR_RIGHT;
			break;
        }

		default:
					//MMI_ASSERT(0);
            break;
    }
    
    gdi_image_draw_id(offset_x, offset_y, autorama_icon);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_autorama_rigistration_rect
 * DESCRIPTION
 *  Draw autorama shot mov rigist rect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_camco_osd_draw_autorama_rigistration_rect(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x = 0;
    S32 offset_y = 0;
    S32 mv_x = 0;
    S32 mv_y = 0;
    S32 preview_width;
    S32 preview_height;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_camco_cam_get_preview_size(&preview_width,&preview_height);

        mv_x = g_mmi_camco_osd_cntx.autorama.regist_mov_offset_x * g_mmi_camco_osd_cntx.autorama.cache_width/preview_width;
        mv_y = g_mmi_camco_osd_cntx.autorama.regist_mov_offset_y * g_mmi_camco_osd_cntx.autorama.cache_height/preview_height;

    offset_x = g_mmi_camco_osd_cntx.autorama.regist_offset_x + mv_x;
    offset_y = g_mmi_camco_osd_cntx.autorama.regist_offset_y + mv_y;

    gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMCO_CAPMODE_AUTORAMA_DETECT_REC);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_autorama_shot
 * DESCRIPTION
 *  Draw autorama shot
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_camco_osd_draw_autorama_rigistration_cache(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x1 = 0;
    S32 offset_y1 = 0;
    S32 offset_x2 = 0;
    S32 offset_y2 = 0;
    S32 img_count = 0;
    S32 layer_width = 0;
    S32 layer_height = 0;
	S32 layer_off_x = 0;
	S32 layer_off_y = 0;
	S32 mov_x;
	S32 mov_y;
    gdi_color rect_color;
    U8* b_ptr;
    gdi_rect_struct clip;
    mmi_camco_osd_autorama_struct autorama_cache;
	U8 bits_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    autorama_cache = g_mmi_camco_osd_cntx.autorama;
    //the rect of cache image
    rect_color = gdi_act_color_from_rgb(255,255,75,0);
    img_count = autorama_cache.img_count;
	offset_x1 = g_mmi_camco_osd_cntx.autorama.cache_offset_x;
    offset_y1 =g_mmi_camco_osd_cntx.autorama.cache_offset_y;
	mov_x = g_mmi_camco_osd_cntx.autorama.cache_mov_x;
	mov_y = g_mmi_camco_osd_cntx.autorama.cache_mov_y;
	gdi_layer_get_dimension(&layer_width,&layer_height);
    gdi_layer_get_buffer_ptr(&b_ptr);
    bits_num = gdi_layer_get_bit_per_pixel();
	offset_x2 = offset_x1 + autorama_cache.cache_width; 
	offset_y2 = offset_y1 + autorama_cache.cache_height;
				  
	clip.x1 = offset_x1 + 1;
	clip.x2 = offset_x2 - 1;
	clip.y1 = offset_y1 + 1;
	clip.y2 = offset_y2 - 1;
	gdi_2d_memory_blt_without_transpant_check(
	    autorama_cache.cache_imgdata_pp,
	    autorama_cache.cache_width,
		0,
		0,
		autorama_cache.cache_width,
		autorama_cache.cache_height,
		b_ptr,
		layer_width,
		offset_x1,
		offset_y1,
		clip,
		bits_num);
					
	gdi_draw_rect(offset_x1, offset_y1, offset_x2 - 1, offset_y2 - 1, autorama_cache.fore_ground_color); 

	offset_x1 = offset_x1 + mov_x;
	offset_y1 = offset_y1 + mov_y;
        
	g_mmi_camco_osd_cntx.autorama.cache_offset_x = offset_x1;
	
	g_mmi_camco_osd_cntx.autorama.cache_offset_y = offset_y1;

        /*set mov rigister rec origin position*/
    gdi_layer_get_position(&layer_off_x,&layer_off_y);
    g_mmi_camco_osd_cntx.autorama.regist_offset_x  = offset_x1 + layer_off_x - mov_x;
    g_mmi_camco_osd_cntx.autorama.regist_offset_y  = offset_y1 + layer_off_y - mov_y;

	offset_x2 = offset_x1 + autorama_cache.cache_width;
	offset_y2 = offset_y1 + autorama_cache.cache_height;
    /*draw regist rect */
	gdi_draw_solid_rect(
		offset_x1 ,
        offset_y1 ,//+ autorama_cache.cache_height * autorama_cache.overlap_ratio/64+1,
        offset_x2-1,
        offset_y2-1,
        autorama_cache.fore_ground_color);
    gdi_draw_rect(offset_x1, offset_y1, offset_x2 - 1, offset_y2 - 1, rect_color); 
    gdi_draw_rect(offset_x1 + 1, offset_y1 + 1, offset_x2 - 2, offset_y2 - 2, rect_color);
       
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_autorama
 * DESCRIPTION
 *  init autorama osd Variables
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_init_autorama(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_camco_osd_p->autorama.regist_img_id = IMG_ID_CAMCO_CAPMODE_AUTORAMA_DETECT_REC;
    mmi_camco_osd_p->autorama.cache_width = MMI_CAMCO_CAM_AUTORAMA_CACHE_IMAGE_WIDTH;
    mmi_camco_osd_p->autorama.cache_height =MMI_CAMCO_CAM_AUTORAMA_CACHE_IMAGE_HEIGHT;
    mmi_camco_osd_p->autorama.overlap_ratio = 32;
    mmi_camco_osd_p->autorama.back_ground_color = gdi_act_color_from_rgb(255,150,150,150);
        
    mmi_camco_osd_p->autorama.fore_ground_color= gdi_act_color_from_rgb(255,200,200,200);
     
}
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_autorama_shot_setup_environment
 * DESCRIPTION
 *  create cache layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_autorama_shot_setup_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 buf_size = 0;
    U8* align_osd_layer_p;
    S32 cache_layer_offset_x;
    S32 cache_layer_offset_y;
    U32 bits_per_pix;
    mmi_camco_autorama_direction_enum autorama_direct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->autorama.is_init)
    {
        return;
    }
	
    MMI_ASSERT(mmi_camco_osd_p->autorama_cache_layer_buf_p != NULL);
    autorama_direct = mmi_camco_osd_get_autorama_direction();

        if(autorama_direct == MMI_CAMCO_AUTORAMA_DIRECTION_LEFT || autorama_direct == MMI_CAMCO_AUTORAMA_DIRECTION_RIGHT )
        {
            mmi_camco_osd_p->autorama.cache_layer_width = MMI_CAMCO_CAM_AUTORAMA_CACHE_IMAGE_HEIGHT;
            mmi_camco_osd_p->autorama.cache_layer_height = (MMI_CAMCO_CAM_AUTORAMA_CACHE_IMAGE_WIDTH * mmi_camco_osd_p->autorama.overlap_ratio/64) * 7 + MMI_CAMCO_CAM_AUTORAMA_CACHE_IMAGE_WIDTH;
            cache_layer_offset_x = 4;
            cache_layer_offset_y = (mmi_camco_osd_p->osd_width - mmi_camco_osd_p->autorama.cache_layer_height)/2;      
        }
        else
        {
        
            mmi_camco_osd_p->autorama.cache_layer_width = (MMI_CAMCO_CAM_AUTORAMA_CACHE_IMAGE_HEIGHT * mmi_camco_osd_p->autorama.overlap_ratio/64) * 7 + MMI_CAMCO_CAM_AUTORAMA_CACHE_IMAGE_HEIGHT;
            mmi_camco_osd_p->autorama.cache_layer_height= MMI_CAMCO_CAM_AUTORAMA_CACHE_IMAGE_WIDTH;
            cache_layer_offset_x = (mmi_camco_osd_p->osd_height - mmi_camco_osd_p->autorama.cache_layer_width)/2;
            cache_layer_offset_y = 4;
        }

    bits_per_pix = 16;
    buf_size = ((mmi_camco_osd_p->autorama.cache_layer_width * mmi_camco_osd_p->autorama.cache_layer_height * bits_per_pix) >> 3);
    align_osd_layer_p = (U8*)(((((U32)mmi_camco_osd_p->autorama_cache_layer_buf_p) >>5) +1) <<5);
    mmi_camco_osd_p->autorama.cache_layer_offset_x = cache_layer_offset_x;
    mmi_camco_osd_p->autorama.cache_layer_offset_y = cache_layer_offset_y;
	
    gdi_layer_create_double_using_outside_memory(
        cache_layer_offset_x,
        cache_layer_offset_y,
        mmi_camco_osd_p->autorama.cache_layer_width,
        mmi_camco_osd_p->autorama.cache_layer_height,
        &mmi_camco_osd_p->autorama_cache_layer_h,
        (U8*) align_osd_layer_p,
        buf_size*2);

    gdi_layer_push_and_set_active(mmi_camco_osd_p->autorama_cache_layer_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
        align_osd_layer_p = (U8*)(((((U32)align_osd_layer_p + buf_size*2) >>5) +1) <<5);
        gdi_layer_create_using_outside_memory(
            cache_layer_offset_y,
            cache_layer_offset_x,
            mmi_camco_osd_p->autorama.cache_layer_height,
            mmi_camco_osd_p->autorama.cache_layer_width,
            &mmi_camco_osd_p->autorama.cache_draw_layer,
            (U8*) align_osd_layer_p,
            buf_size);
		    /* draw back ground */
	    gdi_layer_push_and_set_active(mmi_camco_osd_p->autorama.cache_draw_layer);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_BLUE);
        gdi_layer_clear(mmi_camco_osd_p->autorama.back_ground_color);
		mmi_camco_osd_autorama_shot_setup_offset();
		gdi_layer_pop_and_restore_active();

    mmi_camco_osd_p->autorama.is_init = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_autorama_shot_setup_offset
 * DESCRIPTION
 *  free autorama cache layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_autorama_shot_setup_offset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 offset_x1 = 0;
    S32 offset_y1 = 0;
	S32 mov_x;
	S32 mov_y;
	S32 abs_movx;
	S32 abs_movy;
	S32 layer_width = 0;
	S32 layer_height = 0;
	mmi_camco_autorama_direction_enum autorama_direct;
	mmi_camco_osd_autorama_struct autorama_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	offset_x1 = 0;
    offset_y1 = 0;
	mov_x = 0;
	mov_y = 0;
	autorama_direct = mmi_camco_osd_get_autorama_direction();
    autorama_cache = g_mmi_camco_osd_cntx.autorama;
	gdi_layer_get_dimension(&layer_width,&layer_height);
    if (autorama_direct == MMI_CAMCO_AUTORAMA_DIRECTION_DOWN )
    {
        mov_y =  autorama_cache.cache_height* autorama_cache.overlap_ratio/64;
		abs_movx = autorama_cache.cache_width;
		abs_movy = mov_y;
    }
	else if(autorama_direct == MMI_CAMCO_AUTORAMA_DIRECTION_RIGHT)
	{
		mov_x =  autorama_cache.cache_width* autorama_cache.overlap_ratio/64;
		abs_movx = mov_x;
		abs_movy = autorama_cache.cache_height;
	}
    else if(autorama_direct == MMI_CAMCO_AUTORAMA_DIRECTION_UP)
    {
		mov_y = - autorama_cache.cache_height* autorama_cache.overlap_ratio/64;		
		offset_y1 =  layer_height  - autorama_cache.cache_height;
		abs_movx = autorama_cache.cache_width;
		abs_movy = -mov_y;
    }
    else if(autorama_direct == MMI_CAMCO_AUTORAMA_DIRECTION_LEFT)
    {    
        mov_x = -  autorama_cache.cache_width* autorama_cache.overlap_ratio/64;	
        offset_x1 = layer_width  - autorama_cache.cache_width;
		abs_movx = - mov_x;
		abs_movy = autorama_cache.cache_height;
    }
    g_mmi_camco_osd_cntx.autorama.cache_offset_x = offset_x1;
    g_mmi_camco_osd_cntx.autorama.cache_offset_y = offset_y1;
    g_mmi_camco_osd_cntx.autorama.cache_mov_x = mov_x;
    g_mmi_camco_osd_cntx.autorama.cache_mov_y = mov_y;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_autorama_shot_reset_environment
 * DESCRIPTION
 *  free autorama cache layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_autorama_shot_reset_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_camco_osd_p->autorama.is_init)
    {
        return;
    }
    else if (mmi_camco_osd_p->autorama.is_init && mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_AUTORAMA_SHOT)
    {
        return;
    }

    if (mmi_camco_osd_p->autorama_cache_layer_h != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(mmi_camco_osd_p->autorama_cache_layer_h);
        mmi_camco_osd_p->autorama_cache_layer_h = GDI_LAYER_EMPTY_HANDLE;
    }
	if (mmi_camco_osd_p->autorama.cache_draw_layer!= GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(mmi_camco_osd_p->autorama.cache_draw_layer);
        mmi_camco_osd_p->autorama.cache_draw_layer = GDI_LAYER_EMPTY_HANDLE;
    }
    mmi_camco_osd_p->autorama.is_init = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_autorama_set_cache_layer_buf_p
 * DESCRIPTION
 *  set  buffer pointer to  autorama cache layer 
 * PARAMETERS
 *  buf_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_autorama_set_cache_layer_buf_p(void *buf_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->autorama_cache_layer_buf_p = (U8*) buf_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_autorama_is_enable
 * DESCRIPTION
 *  Get whether to draw autorama cache image flag
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_autorama_cache_draw_is_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/*only when autorama shot a new image cache layer will be redrawed*/ 
    return mmi_camco_osd_p->autorama.is_picked;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_autorama_set_enable
 * DESCRIPTION
 *  Set whether to draw autorama cache image flag
 * PARAMETERS
 *  is_enable       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_autorama_cache_draw_enable(MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->autorama.is_picked = is_enable;
}
#endif /* __MMI_CAMCO_FEATURE_OSD_AUTORAMA__ */ 


#ifdef __MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_set_captured_count
 * DESCRIPTION
 *  set captured image count for osd display
 * PARAMETERS
 *  [In]captured_count
 *       total_count
 *  [out]Void
 * RETURNS
 *  void  [OUT]
 *****************************************************************************/
void mmi_camco_set_captured_count(U8 captured_count,U8 total_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_camco_osd_p->mav.captured_count = captured_count;
	mmi_camco_osd_p->mav.total_count = total_count;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_mav
 * DESCRIPTION
 *  draw mav progress
 * PARAMETERS
 *  void
 * RETURNS
 *  result  [OUT]
 *****************************************************************************/
void mmi_camco_osd_draw_preview_center(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 offset_x;
	S32 offset_y;
	S32 image_region_width;
	S32 image_region_height;
	S32 image_width;
	S32 image_height;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_get_preview_region(
        &offset_x,
        &offset_y,
        &image_region_width,
        &image_region_height);
	gdi_image_get_dimension_id(IMG_ID_CAMCO_CAPMODE_MAV_PREVIEW_CENTER1,&image_width,&image_height);
    offset_x += (image_region_width>>2);
	offset_y += (image_region_height>>2);
	gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
	gdi_image_draw_id(offset_x,offset_y,IMG_ID_CAMCO_CAPMODE_MAV_PREVIEW_CENTER1);
	gdi_image_draw_id((offset_x + (image_region_width>>1) - image_width),offset_y,IMG_ID_CAMCO_CAPMODE_MAV_PREVIEW_CENTER2);
	gdi_image_draw_id(offset_x,offset_y + (image_region_height>>1) - image_height,IMG_ID_CAMCO_CAPMODE_MAV_PREVIEW_CENTER4);
	gdi_image_draw_id(offset_x + (image_region_width>>1) - image_width,offset_y + (image_region_height>>1) - image_height,IMG_ID_CAMCO_CAPMODE_MAV_PREVIEW_CENTER3);
	gdi_pop_and_restore_alpha_blending_source_layer();

}
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_mav
 * DESCRIPTION
 *  draw mav progress
 * PARAMETERS
 *  void
 * RETURNS
 *  result  [OUT]
 *****************************************************************************/
void mmi_camco_osd_draw_mav(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
	S32 offset_x;
	S32 offset_y;
	S32 image_width;
	S32 image_height;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	offset_x = mmi_camco_osd_skin_p->mav_shot.lattice.offset_x;
	offset_y = mmi_camco_osd_skin_p->mav_shot.lattice.offset_y;
	
	gdi_image_get_dimension_id(IMG_ID_CAMCO_CAPMODE_MAV_LATTICE_E,&image_width,&image_height);
	gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
    for(i = 0 ; i< mmi_camco_osd_p->mav.total_count;i++)
    {
        if(i < mmi_camco_osd_p->mav.captured_count)
        {
	        gdi_image_draw_id(offset_x,offset_y,IMG_ID_CAMCO_CAPMODE_MAV_LATTICE_F);
       	}
		else
		{
			gdi_image_draw_id(offset_x,offset_y,IMG_ID_CAMCO_CAPMODE_MAV_LATTICE_E);

		}
		offset_x += mmi_camco_osd_skin_p->mav_shot.interval + image_width;;
	}
	
	gdi_image_draw_id(
		offset_x,
		offset_y,
		IMG_ID_CAMCO_CAPMODE_MAV_ARROW);
	gdi_pop_and_restore_alpha_blending_source_layer();

}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_is_zooming
 * DESCRIPTION
 *  qeury if zooming
 * PARAMETERS
 *  void
 * RETURNS
 *  result  [OUT]
 *****************************************************************************/
extern MMI_BOOL mmi_camco_osd_is_zooming(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_ZOOM_SLIDER_BAR__
    return (MMI_BOOL)(mmi_camco_osd_p->zoom_in_touch.is_press | mmi_camco_osd_p->zoom_out_touch.is_press);
#else
    return MMI_TRUE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_stop_zoom
 * DESCRIPTION
 *  dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_stop_zoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_ZOOM_SLIDER_BAR__
    if (mmi_camco_osd_p->zoom_in_touch.is_press)
    {
        gui_cancel_timer(mmi_camco_start_fast_zoom_in);
        mmi_camco_stop_fast_zoom();
        mmi_camco_osd_p->zoom_in_touch.is_press = MMI_FALSE;
    }

    if (mmi_camco_osd_p->zoom_out_touch.is_press)
    {
        gui_cancel_timer(mmi_camco_start_fast_zoom_out);
        mmi_camco_stop_fast_zoom();
        mmi_camco_osd_p->zoom_out_touch.is_press = MMI_FALSE;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_up_arrow_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_up_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* Do nothing */
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
            break;
        }

        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
            break;            
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            mmi_camco_osd_menulist_prev_cyclic();
            break;
        }

        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:           	
        {
            mmi_camco_osd_menulist_prev_cyclic();
            break;
        }

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            /* Do nothing */
            break;
        }
    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

            imgselect_cache_p->ua_touch.is_press = MMI_TRUE;
            mmi_camco_osd_imgselect_prev_cyclic();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 
    
        default:
            MMI_ASSERT(0);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_up_arrow_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_up_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* Do nothing */
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
            break;
        }

        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
            if (mmi_camco_osd_p->lsk.event_callback == NULL)
            {
                return;
            }
                           
            mmi_camco_switch_app();
            
            /* callback */            
            mmi_camco_osd_p->lsk.event_callback(KEY_EVENT_UP);
            break;            
        }            
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            gui_cancel_timer(mmi_camco_osd_menulist_prev_cyclic);
            break;
        }

    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

            if (!imgselect_cache_p->ua_touch.is_press)
            {
                /* not pressed, return */
                return;
            }

            gui_cancel_timer(mmi_camco_osd_imgselect_prev_cyclic);
            imgselect_cache_p->ua_touch.is_press = MMI_FALSE;
            mmi_camco_updata_key_handler();
            mmi_camco_osd_draw_osd();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            /* Do nothing */
            break;
        }

        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:           	
        {
            gui_cancel_timer(mmi_camco_osd_menulist_prev_cyclic);
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_down_arrow_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_down_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* Do nothing */
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
            break;
        }

        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
            break;            
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING: 
        {
            mmi_camco_osd_menulist_next_cyclic();
            break;
        }

        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:          	
        {
            mmi_camco_osd_menulist_next_cyclic();
            break;
        }

    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

            imgselect_cache_p->da_touch.is_press = MMI_TRUE;
            mmi_camco_osd_imgselect_next_cyclic();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_down_arrow_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_down_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* Do nothing */
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
            if (mmi_camco_osd_p->lsk.event_callback == NULL)
            {
                return;
            }
                           
            mmi_camco_switch_app();
            
            /* callback */            
            mmi_camco_osd_p->lsk.event_callback(KEY_EVENT_UP);

            break;
        }

        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
            break;    

        }
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING: 
        {
            gui_cancel_timer(mmi_camco_osd_menulist_next_cyclic);
            break;
        }

    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

            if (!imgselect_cache_p->da_touch.is_press)
            {
                /* not pressed, return */
                return;
            }

            gui_cancel_timer(mmi_camco_osd_imgselect_next_cyclic);
            imgselect_cache_p->da_touch.is_press = MMI_FALSE;
            mmi_camco_updata_key_handler();
            mmi_camco_osd_draw_osd();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            /* Do nothing */
            break;
        }

        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:          	
        {
            gui_cancel_timer(mmi_camco_osd_menulist_next_cyclic);
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_scroll_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_scroll_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_width;
    S32 img_height;
    mmi_camco_osd_scrollbar_struct *scrollbar_p = &mmi_camco_osd_p->scrollbar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_get_dimension_id(IMG_ID_CAMCO_SCROLLBAR_HEAD, &img_width, &img_height);
    scrollbar_p->scrollbar_width = img_width;
    scrollbar_p->scrollbar_border_height = img_height;

    gdi_image_get_dimension_id(IMG_ID_CAMCO_SCROLLBAR_BODY, &img_width, &img_height);
    scrollbar_p->scrollbar_body_img_height = img_height;

    gdi_image_get_dimension_id(IMG_ID_CAMCO_SLIDER_HEAD, &img_width, &img_height);
    scrollbar_p->slider_touch.width = img_width;
    scrollbar_p->scrollbar_border_width = (scrollbar_p->scrollbar_width - scrollbar_p->slider_touch.width) >> 1;
    scrollbar_p->slider_border_height = img_height;

    gdi_image_get_dimension_id(IMG_ID_CAMCO_SLIDER_BODY, &img_width, &img_height);
    scrollbar_p->slider_body_img_height = img_height;

    scrollbar_p->slider_touch.is_usable = MMI_TRUE;
    scrollbar_p->slider_up_touch.is_usable = MMI_TRUE;
    scrollbar_p->slider_down_touch.is_usable = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_gen_scrollbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_gen_scrollbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_scrollbar_struct *scrollbar_p = &mmi_camco_osd_p->scrollbar;
    mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;
    S32 scroll_region_end_y;
    S32 slider_end_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrollbar_p->item_count = menulist_p->item_count;

    if (scrollbar_p->item_count > 0)
    {
        if (r2lMMIFlag)
        {
            scrollbar_p->scrollbar_offset_x = menulist_p->menulist_offset_x - menulist_p->item_width;
        }
        else
        {
            scrollbar_p->scrollbar_offset_x = menulist_p->item_width + menulist_p->menulist_offset_x;
        }

        scrollbar_p->scrollbar_offset_y = menulist_p->menulist_offset_y + menulist_p->title_height;
        scrollbar_p->scrollbar_height = menulist_p->item_height * menulist_p->disp_item_count;

        if (r2lMMIFlag)
        {
            scrollbar_p->scroll_region_offset_x = scrollbar_p->scrollbar_offset_x - scrollbar_p->scrollbar_border_width;
        }
        else
        {
            scrollbar_p->scroll_region_offset_x = scrollbar_p->scrollbar_offset_x + scrollbar_p->scrollbar_border_width;
        }
        scrollbar_p->scroll_region_offset_y = scrollbar_p->scrollbar_offset_y + scrollbar_p->scrollbar_border_height;
        scrollbar_p->scroll_region_width = scrollbar_p->scrollbar_width - scrollbar_p->scrollbar_border_width * 2;
        scrollbar_p->scroll_region_height = scrollbar_p->scrollbar_height - scrollbar_p->scrollbar_border_height * 2;

        scrollbar_p->slider_touch.width = scrollbar_p->scroll_region_width;

        if (scrollbar_p->item_count > menulist_p->disp_item_count)
        {
            scrollbar_p->slider_touch.height =
                menulist_p->disp_item_count * scrollbar_p->scroll_region_height / scrollbar_p->item_count;
        }
        else
        {
            scrollbar_p->slider_touch.height = scrollbar_p->scroll_region_height;
        }

        scrollbar_p->slider_body_height = scrollbar_p->slider_touch.height - scrollbar_p->slider_border_height * 2;

        if (menulist_p->item_count > menulist_p->disp_item_count)
        {
            scrollbar_p->page_count = scrollbar_p->item_count - menulist_p->disp_item_count + 1;

            scrollbar_p->height_per_page = scrollbar_p->scroll_region_height / scrollbar_p->page_count;
        }
        else
        {
            scrollbar_p->page_count = 1;
            scrollbar_p->height_per_page = scrollbar_p->scroll_region_height;
        }

        /* move to slide position */
        if (r2lMMIFlag)
        {
            scrollbar_p->slider_touch.offset_x =
                scrollbar_p->scroll_region_offset_x - scrollbar_p->scroll_region_width + 1;
        }
        else
        {
            scrollbar_p->slider_touch.offset_x = scrollbar_p->scroll_region_offset_x;
        }
        scrollbar_p->slider_touch.offset_y =
            menulist_p->first_disp_idx * scrollbar_p->scroll_region_height / scrollbar_p->item_count +
            scrollbar_p->scroll_region_offset_y;

        slider_end_y = scrollbar_p->slider_touch.offset_y + scrollbar_p->slider_touch.height;
        scroll_region_end_y = scrollbar_p->scroll_region_offset_y + scrollbar_p->scroll_region_height;

        if (scroll_region_end_y - slider_end_y == 1)
        {
            /* round error, last page's slider will 1 pixel lower */
            scrollbar_p->slider_touch.offset_y++;
        }

        if (r2lMMIFlag)
        {
            scrollbar_p->slider_up_touch.offset_x =
                scrollbar_p->scrollbar_offset_x - scrollbar_p->slider_touch.width + 1;
        }
        else
        {
            scrollbar_p->slider_up_touch.offset_x = scrollbar_p->scrollbar_offset_x;
        }
        scrollbar_p->slider_up_touch.offset_y = scrollbar_p->scrollbar_offset_y + scrollbar_p->scrollbar_border_height;
        scrollbar_p->slider_up_touch.width = scrollbar_p->slider_touch.width;
        scrollbar_p->slider_up_touch.height = scrollbar_p->slider_touch.offset_y - scrollbar_p->scrollbar_offset_y;
        if (scrollbar_p->slider_up_touch.height < 0)
        {
            scrollbar_p->slider_up_touch.height = 0;
        }

        if (r2lMMIFlag)
        {
            scrollbar_p->slider_down_touch.offset_x =
                scrollbar_p->scrollbar_offset_x - scrollbar_p->slider_touch.width + 1;
        }
        else
        {
            scrollbar_p->slider_down_touch.offset_x = scrollbar_p->scrollbar_offset_x;
        }
        scrollbar_p->slider_down_touch.offset_y = scrollbar_p->slider_touch.offset_y + scrollbar_p->slider_touch.height;
        scrollbar_p->slider_down_touch.width = scrollbar_p->slider_touch.width;
        scrollbar_p->slider_down_touch.height = scroll_region_end_y - scrollbar_p->slider_down_touch.offset_y;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_update_scrollbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_update_scrollbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_scrollbar_struct *scrollbar_p = &mmi_camco_osd_p->scrollbar;
    mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;
    S32 scroll_region_end_y;
    S32 slider_end_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrollbar_p->item_count > 0)
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
    #endif /* 0 */ 
        /* move to slide position */
        scrollbar_p->slider_touch.offset_y =
            menulist_p->first_disp_idx * scrollbar_p->scroll_region_height / scrollbar_p->item_count +
            scrollbar_p->scroll_region_offset_y;

        slider_end_y = scrollbar_p->slider_touch.offset_y + scrollbar_p->slider_touch.height;
        scroll_region_end_y = scrollbar_p->scroll_region_offset_y + scrollbar_p->scroll_region_height;

        if (scroll_region_end_y - slider_end_y == 1)
        {
            /* round error, last page's slider will 1 pixel lower */
            scrollbar_p->slider_touch.offset_y++;
        }

        if (r2lMMIFlag)
        {
            scrollbar_p->slider_up_touch.offset_x =
                scrollbar_p->scrollbar_offset_x - scrollbar_p->slider_touch.width + 1;
        }
        else
        {
            scrollbar_p->slider_up_touch.offset_x = scrollbar_p->scrollbar_offset_x;
        }
        scrollbar_p->slider_up_touch.offset_y = scrollbar_p->scrollbar_offset_y + scrollbar_p->scrollbar_border_height;
        scrollbar_p->slider_up_touch.width = scrollbar_p->slider_touch.width;
        scrollbar_p->slider_up_touch.height = scrollbar_p->slider_touch.offset_y - scrollbar_p->scrollbar_offset_y;
        if (scrollbar_p->slider_up_touch.height < 0)
        {
            scrollbar_p->slider_up_touch.height = 0;
        }

        if (r2lMMIFlag)
        {
            scrollbar_p->slider_down_touch.offset_x =
                scrollbar_p->scrollbar_offset_x - scrollbar_p->slider_touch.width + 1;
        }
        else
        {
            scrollbar_p->slider_down_touch.offset_x = scrollbar_p->scrollbar_offset_x;
        }
        scrollbar_p->slider_down_touch.offset_y = scrollbar_p->slider_touch.offset_y + scrollbar_p->slider_touch.height;
        scrollbar_p->slider_down_touch.width = scrollbar_p->slider_touch.width;
        scrollbar_p->slider_down_touch.height = scroll_region_end_y - scrollbar_p->slider_down_touch.offset_y;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_scrollbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_draw_scrollbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 remained_height;
    S32 offset_y;
    mmi_camco_osd_scrollbar_struct *scrollbar_p = &mmi_camco_osd_p->scrollbar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrollbar_p->item_count)
    {
        /* scrollbar head */
        offset_y = scrollbar_p->scrollbar_offset_y;
        if (r2lMMIFlag)
        {
            gdi_image_draw_id(
                scrollbar_p->scrollbar_offset_x - scrollbar_p->scrollbar_width + 1,
                scrollbar_p->scrollbar_offset_y,
                IMG_ID_CAMCO_SCROLLBAR_HEAD);
        }
        else
        {
            gdi_image_draw_id(
                scrollbar_p->scrollbar_offset_x,
                scrollbar_p->scrollbar_offset_y,
                IMG_ID_CAMCO_SCROLLBAR_HEAD);
        }
        offset_y += scrollbar_p->scrollbar_border_height;

        /* scrollbar body */
        remained_height = scrollbar_p->scroll_region_height;

        if (r2lMMIFlag)
        {
            gdi_layer_set_clip(
                scrollbar_p->scrollbar_offset_x - scrollbar_p->scrollbar_width + 1,
                scrollbar_p->scrollbar_offset_y,
                scrollbar_p->scrollbar_offset_x,
                scrollbar_p->scrollbar_offset_y + scrollbar_p->scrollbar_height - 1);
        }
        else
        {
            gdi_layer_set_clip(
                scrollbar_p->scrollbar_offset_x,
                scrollbar_p->scrollbar_offset_y,
                scrollbar_p->scrollbar_offset_x + scrollbar_p->scrollbar_width - 1,
                scrollbar_p->scrollbar_offset_y + scrollbar_p->scrollbar_height - 1);
        }

        while (remained_height > 0)
        {
            if (r2lMMIFlag)
            {
                gdi_image_draw_id(
                    scrollbar_p->scrollbar_offset_x - scrollbar_p->scrollbar_width + 1,
                    offset_y,
                    IMG_ID_CAMCO_SCROLLBAR_BODY);
            }
            else
            {
                gdi_image_draw_id(scrollbar_p->scrollbar_offset_x, offset_y, IMG_ID_CAMCO_SCROLLBAR_BODY);
            }

            if (remained_height > scrollbar_p->scrollbar_body_img_height)
            {

                offset_y += scrollbar_p->scrollbar_body_img_height;
            }
            else
            {
                offset_y += remained_height;
            }

            remained_height -= scrollbar_p->scrollbar_body_img_height;
        }

        gdi_layer_reset_clip();

        /* scrollbar tail */
        if (r2lMMIFlag)
        {
            gdi_image_draw_id(
                scrollbar_p->scrollbar_offset_x - scrollbar_p->scrollbar_width + 1,
                offset_y,
                IMG_ID_CAMCO_SCROLLBAR_TAIL);
        }
        else
        {
            gdi_image_draw_id(scrollbar_p->scrollbar_offset_x, offset_y, IMG_ID_CAMCO_SCROLLBAR_TAIL);
        }

        /* slider head */
        offset_y = scrollbar_p->slider_touch.offset_y;
        gdi_image_draw_id(
            scrollbar_p->slider_touch.offset_x,
            scrollbar_p->slider_touch.offset_y,
            IMG_ID_CAMCO_SLIDER_HEAD);
        offset_y += scrollbar_p->slider_border_height;

        /* slider body */
        remained_height = scrollbar_p->slider_body_height;

        gdi_layer_set_clip(
            scrollbar_p->slider_touch.offset_x,
            scrollbar_p->slider_touch.offset_y,
            scrollbar_p->slider_touch.offset_x + scrollbar_p->slider_touch.width - 1,
            scrollbar_p->slider_touch.offset_y + scrollbar_p->slider_touch.height - 1);

        while (remained_height > 0)
        {
            gdi_image_draw_id(scrollbar_p->slider_touch.offset_x, offset_y, IMG_ID_CAMCO_SLIDER_BODY);

            if (remained_height > scrollbar_p->slider_body_img_height)
            {

                offset_y += scrollbar_p->slider_body_img_height;
            }
            else
            {
                offset_y += remained_height;
            }

            remained_height -= scrollbar_p->slider_body_img_height;
        }

        gdi_layer_reset_clip();

        /* slider tail */
        gdi_image_draw_id(scrollbar_p->slider_touch.offset_x, offset_y, IMG_ID_CAMCO_SLIDER_TAIL);

    }

}

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_reduced_record_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time_msec       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_reduced_record_frame(U64 frame)
{
#ifdef __CAMCO_TIME_LAPS_VIDEO_RECORDER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 frame1;
    S32 offset_x;
	  S32 offset_y;
	  int i;
    mmi_camco_osd_video_progress_struct *progress_p = &mmi_camco_osd_p->video_progress;
    gdi_rect_struct *rotate_rec_time_area_p = &mmi_camco_osd_p->video_recoding_osd.rotate_rec_time_area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	
    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_RECORDING)
    {
        gdi_draw_solid_circle(
            progress_p->dot_offset_x + MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS - rotate_rec_time_area_p->x1,
            progress_p->dot_offset_y + progress_p->num_img_height / 2 - rotate_rec_time_area_p->y1,
            MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            GDI_COLOR_RED);
    }
    else
    {
        gdi_draw_solid_circle(
            progress_p->dot_offset_x + MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS - rotate_rec_time_area_p->x1,
            progress_p->dot_offset_y + progress_p->num_img_height / 2 - rotate_rec_time_area_p->y1,
            MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            GDI_COLOR_GREEN);
    }

    offset_x = progress_p->time_offset_x - rotate_rec_time_area_p->x1;
    offset_y = progress_p->time_offset_y - rotate_rec_time_area_p->y1,
    offset_x += (progress_p->num_img_width + 1)*8 ;
    for(i=0;;i++)
    {
        frame1 = frame%10;
     	frame = frame/10;
     	gdi_image_draw_id(
            offset_x,
            offset_y,
            (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) frame1));
      
        offset_x -= (progress_p->num_img_width + 1) ;
     	if(frame == 0)
     		break;
   }
   offset_x = progress_p->time_offset_x - rotate_rec_time_area_p->x1;
   offset_x += (progress_p->num_img_width + 1)*8 ;
if(	mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) != MMI_CAMCO_LIMIT_NO_LIMIT)
{
	offset_x += progress_p->num_img_width + 1;

	gui_print_truncated_text(offset_x,progress_p->time_offset_y - rotate_rec_time_area_p->y1,progress_p->num_img_width,(UI_string_type)"/");

    if(	mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) == MMI_CAMCO_LIMIT_TIME_5MIN)
    {
        frame = 5 * 60 *RECORDER_TIME_LAPSE_SAMPLE_PERIOD;
	}
    else if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) == MMI_CAMCO_LIMIT_TIME_10MIN)
    {
	    frame = 10 * 60 *RECORDER_TIME_LAPSE_SAMPLE_PERIOD;
    }
	offset_x += (progress_p->num_img_width + 1)*3;
	 for(i=0;;i++)
	 {
		 frame1 = frame%10;
		 frame = frame/10;
		 gdi_image_draw_id(
			 offset_x,
			 offset_y,
			 (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) frame1));
	   
		 offset_x -= (progress_p->num_img_width + 1) ;
		 if(frame == 0)
			 break;
	}


}
#endif
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_reduced_record_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time_msec       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_reduced_record_time(U64 time_msec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hour;
    S32 hour_remain;
    S32 min;
    S32 sec;
    S32 offset_x;
    U64 time_sec = time_msec / 1000;
#ifdef __MMI_OP02_LEMEI__    
    U64 predict_time_sec = mmi_camco_get_predict_record_time();       
#endif
    mmi_camco_osd_video_progress_struct *progress_p = &mmi_camco_osd_p->video_progress;
    gdi_rect_struct *rotate_rec_time_area_p = &mmi_camco_osd_p->video_recoding_osd.rotate_rec_time_area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hour = time_sec / 3600;
    hour_remain = time_sec % 3600;
    min = hour_remain / 60;
    sec = hour_remain % 60;

    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_RECORDING)
    {
        gdi_draw_solid_circle(
            progress_p->dot_offset_x + MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS - rotate_rec_time_area_p->x1,
            progress_p->dot_offset_y + progress_p->num_img_height / 2 - rotate_rec_time_area_p->y1,
            MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            GDI_COLOR_RED);
    }
    else
    {
        gdi_draw_solid_circle(
            progress_p->dot_offset_x + MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS - rotate_rec_time_area_p->x1,
            progress_p->dot_offset_y + progress_p->num_img_height / 2 - rotate_rec_time_area_p->y1,
            MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            GDI_COLOR_GREEN);
    }

    /* hr */
    gdi_image_draw_id(
        progress_p->time_offset_x - rotate_rec_time_area_p->x1,
        progress_p->time_offset_y - rotate_rec_time_area_p->y1,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) hour / 10));

    offset_x = progress_p->time_offset_x + progress_p->num_img_width + 1 - rotate_rec_time_area_p->x1;
    gdi_image_draw_id(
        offset_x,
        progress_p->time_offset_y - rotate_rec_time_area_p->y1,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) hour % 10));

    offset_x += progress_p->num_img_width + 1;
    gdi_image_draw_id(
        offset_x,
        progress_p->time_offset_y - rotate_rec_time_area_p->y1,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_COLON));

    /* min */
    offset_x += progress_p->col_img_width + 1;
    gdi_image_draw_id(
        offset_x,
        progress_p->time_offset_y - rotate_rec_time_area_p->y1,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) min / 10));

    offset_x += progress_p->num_img_width + 1;
    gdi_image_draw_id(
        offset_x,
        progress_p->time_offset_y - rotate_rec_time_area_p->y1,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) min % 10));

    offset_x += progress_p->num_img_width + 1;
    gdi_image_draw_id(
        offset_x,
        progress_p->time_offset_y - rotate_rec_time_area_p->y1,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_COLON));

    /* sec */
    offset_x += progress_p->col_img_width + 1;
    gdi_image_draw_id(
        offset_x,
        progress_p->time_offset_y - rotate_rec_time_area_p->y1,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) sec / 10));

    offset_x += progress_p->num_img_width + 1;
    gdi_image_draw_id(
        offset_x,
        progress_p->time_offset_y - rotate_rec_time_area_p->y1,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) sec % 10));
    
#ifdef __MMI_OP02_LEMEI__   
    if (!mmi_camco_setting_app_switch_is_enable())
    {
        hour = predict_time_sec / 3600;
        hour_remain = predict_time_sec % 3600;
        min = hour_remain / 60;
        sec = hour_remain % 60;

        /* / */   
        offset_x += progress_p->num_img_width + 1;
        gui_move_text_cursor(offset_x, progress_p->time_offset_y);
        gui_print_bordered_text((UI_string_type) L"/");    

        /* hr */    
        offset_x += progress_p->num_img_width + 1;    
        gdi_image_draw_id(offset_x, progress_p->time_offset_y - rotate_rec_time_area_p->y1, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) hour / 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y - rotate_rec_time_area_p->y1, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) hour % 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y - rotate_rec_time_area_p->y1, (U16) (IMG_ID_CAMCO_OSD_TIMER_COLON));

        /* min */
        offset_x += progress_p->col_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y - rotate_rec_time_area_p->y1, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) min / 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y - rotate_rec_time_area_p->y1, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) min % 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y - rotate_rec_time_area_p->y1, (U16) (IMG_ID_CAMCO_OSD_TIMER_COLON));

        /* sec */
        offset_x += progress_p->col_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y - rotate_rec_time_area_p->y1, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) sec / 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y - rotate_rec_time_area_p->y1, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) sec % 10));    
    }
#endif
}
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_record_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time_msec       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_record_time(U64 time_msec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hour;
    S32 hour_remain;
    S32 min;
    S32 sec;
    S32 offset_x;     
    U64 time_sec = time_msec / 1000;
#ifdef __MMI_OP02_LEMEI__  
    U64 predict_time_sec = mmi_camco_get_predict_record_time();       
#endif
    mmi_camco_osd_video_progress_struct *progress_p = &mmi_camco_osd_p->video_progress;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hour = time_sec / 3600;
    hour_remain = time_sec % 3600;
    min = hour_remain / 60;
    sec = hour_remain % 60;

    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_RECORDING)
    {
        gdi_draw_solid_circle(
            progress_p->dot_offset_x + MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            progress_p->dot_offset_y + progress_p->num_img_height / 2,
            MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            GDI_COLOR_RED);
    }
    else
    {
        gdi_draw_solid_circle(
            progress_p->dot_offset_x + MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            progress_p->dot_offset_y + progress_p->num_img_height / 2,
            MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            GDI_COLOR_GREEN);
    }

    /* hr */
    gdi_image_draw_id(
        progress_p->time_offset_x,
        progress_p->time_offset_y,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) hour / 10));

    offset_x = progress_p->time_offset_x + progress_p->num_img_width + 1;
    gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) hour % 10));

    offset_x += progress_p->num_img_width + 1;
    gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_COLON));

    /* min */
    offset_x += progress_p->col_img_width + 1;
    gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) min / 10));

    offset_x += progress_p->num_img_width + 1;
    gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) min % 10));

    offset_x += progress_p->num_img_width + 1;
    gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_COLON));

    /* sec */
    offset_x += progress_p->col_img_width + 1;
    gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) sec / 10));

    offset_x += progress_p->num_img_width + 1;
    gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) sec % 10));

#ifdef __MMI_OP02_LEMEI__   
    if (!mmi_camco_setting_app_switch_is_enable())
    {
        hour = predict_time_sec / 3600;
        hour_remain = predict_time_sec % 3600;
        min = hour_remain / 60;
        sec = hour_remain % 60;

        /* / */   
        offset_x += progress_p->num_img_width + 1;
        gui_move_text_cursor(offset_x, progress_p->time_offset_y);
        gui_print_bordered_text((UI_string_type) L"/");    

        /* hr */    
        offset_x += progress_p->num_img_width + 5;    
        gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) hour / 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) hour % 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_COLON));

        /* min */
        offset_x += progress_p->col_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) min / 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) min % 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_COLON));

        /* sec */
        offset_x += progress_p->col_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) sec / 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) sec % 10));
    }
#endif
}



/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_reduced_record_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time_msec       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_record_frame(U64 frame)
{
#ifdef __CAMCO_TIME_LAPS_VIDEO_RECORDER__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 frame1;
    S32 offset_x;
	S32 offset_y;
	int i;
    mmi_camco_osd_video_progress_struct *progress_p = &mmi_camco_osd_p->video_progress;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_RECORDING)
    {
        gdi_draw_solid_circle(
            progress_p->dot_offset_x + MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            progress_p->dot_offset_y + progress_p->num_img_height / 2,
            MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            GDI_COLOR_RED);
    }
    else
    {
        gdi_draw_solid_circle(
            progress_p->dot_offset_x + MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            progress_p->dot_offset_y + progress_p->num_img_height / 2,
            MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            GDI_COLOR_GREEN);
    }

	offset_x = progress_p->time_offset_x ;
    offset_y = progress_p->time_offset_y ,
    offset_x += (progress_p->num_img_width + 1)*8 ;
    for(i=0;;i++)
    {
        frame1 = frame%10;
        frame = frame/10;
     	gdi_image_draw_id(
            offset_x,
            offset_y,
            (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) frame1));
      
        offset_x -= (progress_p->num_img_width + 1) ;
     	if(frame == 0)
     		break;
     }
	
   offset_x = progress_p->time_offset_x ;
   offset_x += (progress_p->num_img_width + 1)*8 ;
if(	mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) != MMI_CAMCO_LIMIT_NO_LIMIT)
{
	offset_x += progress_p->num_img_width + 1;

	gui_print_truncated_text(offset_x, progress_p->time_offset_y,progress_p->num_img_width,(UI_string_type)"/");

    if(	mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) == MMI_CAMCO_LIMIT_TIME_5MIN)
    {
        frame = 5 * 60 * RECORDER_TIME_LAPSE_SAMPLE_PERIOD ;
	}
    else if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) == MMI_CAMCO_LIMIT_TIME_10MIN)
    {
	    frame = 10 * 60 * RECORDER_TIME_LAPSE_SAMPLE_PERIOD;
    }
	
	offset_x += (progress_p->num_img_width + 1)*3;
	 for(i=0;;i++)
	 {
		 frame1 = frame%10;
		 frame = frame/10;
		 gdi_image_draw_id(
			 offset_x,
			 offset_y,
			 (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) frame1));
	   
		 offset_x -= (progress_p->num_img_width + 1) ;
		 if(frame == 0)
			 break;
	}


}
#endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_xenon_flash
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_init_xenon_flash(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->xenon_flash_state = MMI_CAMCO_OSD_XENON_FLASH_STATE_EXIT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_xenon_flash_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  xenon_flash_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_xenon_flash_state(mmi_camco_osd_xenon_flash_state_enum xenon_flash_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->xenon_flash_state = xenon_flash_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_xenon_flash
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_xenon_flash(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x = mmi_camco_osd_skin_p->xenon_status.offset_x;
    S32 offset_y = mmi_camco_osd_skin_p->xenon_status.offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_CAMCO_CAM_XENON_FLASH_DRAW, mmi_camco_osd_p->xenon_flash_state);

    switch (mmi_camco_osd_p->xenon_flash_state)
    {
        case MMI_CAMCO_OSD_XENON_FLASH_STATE_SUCCESS:
            gdi_image_draw_id(offset_x, offset_y, (U16) (IMG_ID_CAMCO_XENON_SUCCESS));
            break;

        case MMI_CAMCO_OSD_XENON_FLASH_STATE_CHARGING:
            gdi_image_draw_id(offset_x, offset_y, (U16) (IMG_ID_CAMCO_XENON_CHARGING));
            break;

        case MMI_CAMCO_OSD_XENON_FLASH_STATE_TIMEOUT:
            gdi_image_draw_id(offset_x, offset_y, (U16) (IMG_ID_CAMCO_XENON_TIMEOUT));
            break;

        case MMI_CAMCO_OSD_XENON_FLASH_STATE_LOW_BATTERY:
            gdi_image_draw_id(offset_x, offset_y, (U16) (IMG_ID_CAMCO_XENON_LOW_BATTERY));
            break;

        case MMI_CAMCO_OSD_XENON_FLASH_STATE_EXIT:
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_reduced_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ratio       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_reduced_progress(U16 ratio)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_video_progress_struct *progress_p = &mmi_camco_osd_p->video_progress;
    U32 progress_width;
    //GDI_RESULT ret;
    gdi_rect_struct *rotate_rec_time_area_p = &mmi_camco_osd_p->video_recoding_osd.rotate_rec_time_area;
    gdi_rect_struct clip;
    S32 num_width;
    S32 num_height;
    S32 img_width;
    S32 img_height;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_get_dimension_id(IMG_ID_CAMCO_OSD_TIMER_0, &num_width, &num_height);
    gdi_image_get_dimension_id(IMG_ID_CAMCO_VIDEO_PROGRESS_BG, &img_width, &img_height);
    if (num_height > img_height)
    {
        offset_y = (num_height - img_height) >> 1;
    }

    clip.x1 = progress_p->progress_offset_x - rotate_rec_time_area_p->x1;
    clip.y1 = progress_p->progress_offset_y - rotate_rec_time_area_p->y1;

    /* draw progress bg */
    gdi_layer_set_clip(
        clip.x1,
        clip.y1 + offset_y,
        clip.x1 + mmi_camco_osd_skin_p->video_record.progress_width,
        clip.y1 + mmi_camco_osd_skin_p->video_record.progress_height + offset_y);

    gdi_image_draw_id(clip.x1, clip.y1 + offset_y, IMG_ID_CAMCO_VIDEO_PROGRESS_BG);
    gdi_layer_reset_clip();

    /* draw progress fg according to the ratio */
    progress_width = (U32) ((mmi_camco_osd_skin_p->video_record.progress_width * ratio) / 100);

    gdi_layer_set_clip(
        clip.x1,
        clip.y1 + offset_y,
        clip.x1 + progress_width,
        clip.y1 + mmi_camco_osd_skin_p->video_record.progress_height + offset_y);

    gdi_image_draw_id(clip.x1, clip.y1 + offset_y, IMG_ID_CAMCO_VIDEO_PROGRESS_FG);
    gdi_layer_reset_clip();

}
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ratio       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_progress(U16 ratio)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_video_progress_struct *progress_p = &mmi_camco_osd_p->video_progress;
    U32 progress_width;
    S32 num_width;
    S32 num_height;
    S32 img_width;
    S32 img_height;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_get_dimension_id(IMG_ID_CAMCO_OSD_TIMER_0, &num_width, &num_height);
    gdi_image_get_dimension_id(IMG_ID_CAMCO_VIDEO_PROGRESS_BG, &img_width, &img_height);
    if (num_height > img_height)
    {
        offset_y = (num_height - img_height) >> 1;
    }

    /* draw progress bg */
    gdi_layer_set_clip(
        progress_p->progress_offset_x,
        progress_p->progress_offset_y + offset_y,
        progress_p->progress_offset_x + mmi_camco_osd_skin_p->video_record.progress_width,
        progress_p->progress_offset_y + mmi_camco_osd_skin_p->video_record.progress_height + offset_y);

    gdi_image_draw_id(
            progress_p->progress_offset_x,
            progress_p->progress_offset_y + offset_y,
            IMG_ID_CAMCO_VIDEO_PROGRESS_BG);
    gdi_layer_reset_clip();

    /* draw progress fg according to the ratio */
    progress_width = (U32) ((mmi_camco_osd_skin_p->video_record.progress_width * ratio) / 100);

    gdi_layer_set_clip(
        progress_p->progress_offset_x,
        progress_p->progress_offset_y + offset_y,
        progress_p->progress_offset_x + progress_width,
        progress_p->progress_offset_y + mmi_camco_osd_skin_p->video_record.progress_height + offset_y);

   gdi_image_draw_id(
            progress_p->progress_offset_x,
            progress_p->progress_offset_y + offset_y,
            IMG_ID_CAMCO_VIDEO_PROGRESS_FG);
    gdi_layer_reset_clip();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_bg_black
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_bg_black(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(mmi_camco_osd_p->base_layer_h);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_clear_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_clear_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

}

#ifndef MMI_CAMCO_OSD_ICON_SWKEY

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_lsk_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_id              [IN]        
 *  event_callback      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_lsk_str(MMI_ID_TYPE str_id, void (*event_callback) (mmi_key_types_enum event))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_softkey_struct *lsk_p = &mmi_camco_osd_p->lsk;
    S32 offset_x;
    S32 offset_y;
    S32 str_width;
    S32 str_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lsk_p->str_id = str_id;
    lsk_p->event_callback = event_callback;

    /* reset touch region */
    memset((void*)&lsk_p->touch, 0, sizeof(mmi_camco_osd_touch_obj_struct));

    if (str_id != 0)
    {
    #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
        if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
        {
            lsk_p->is_truncated = wgui_softkey_get_offset(
                                    (UI_string_type) GetString(lsk_p->str_id),
                                    &offset_x,
                                    &offset_y,
                                    &lsk_p->truncated_width,
                                    MMI_LEFT_SOFTKEY,
                                    MMI_FRM_SCREEN_ROTATE_270);
        }
    #ifdef DUAL_CAMERA_SUPPORT
        else
        {
            lsk_p->is_truncated = wgui_softkey_get_offset(
                                    (UI_string_type) GetString(lsk_p->str_id),
                                    &offset_x,
                                    &offset_y,
                                    &lsk_p->truncated_width,
                                    MMI_LEFT_SOFTKEY,
                                    MMI_FRM_SCREEN_ROTATE_0);
        }
    #endif /* DUAL_CAMERA_SUPPORT */ 
    #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
        lsk_p->is_truncated = wgui_softkey_get_offset(
                                (UI_string_type) GetString(lsk_p->str_id),
                                &offset_x,
                                &offset_y,
                                &lsk_p->truncated_width,
                                MMI_LEFT_SOFTKEY,
                                MMI_FRM_SCREEN_ROTATE_0);
    #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

        gui_measure_string((UI_string_type) GetString(lsk_p->str_id), &str_width, &str_height);

        lsk_p->offset_x = offset_x;
        lsk_p->offset_y = offset_y;

        lsk_p->touch.offset_x = offset_x;
        lsk_p->touch.offset_y = offset_y;
        lsk_p->touch.width = str_width;
        lsk_p->touch.height = str_height;
        lsk_p->touch.is_press = MMI_FALSE;
        lsk_p->touch.is_usable = MMI_TRUE;
    }
    else
    {
        /* invalid ID */
        MMI_ASSERT(0);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_rsk_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_id              [IN]        
 *  event_callback      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_rsk_str(MMI_ID_TYPE str_id, void (*event_callback) (mmi_key_types_enum event))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_softkey_struct *rsk_p = &mmi_camco_osd_p->rsk;
    S32 offset_x;
    S32 offset_y;
    S32 str_width;
    S32 str_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsk_p->str_id = str_id;
    rsk_p->event_callback = event_callback;

    memset((void*)&rsk_p->touch, 0, sizeof(mmi_camco_osd_touch_obj_struct));

    if (str_id != 0)
    {
    #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
        if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
        {
            rsk_p->is_truncated = wgui_softkey_get_offset(
                                    (UI_string_type) GetString(rsk_p->str_id),
                                    &offset_x,
                                    &offset_y,
                                    &rsk_p->truncated_width,
                                    MMI_RIGHT_SOFTKEY,
                                    MMI_FRM_SCREEN_ROTATE_270);
        }
    #ifdef DUAL_CAMERA_SUPPORT
        else
        {
            rsk_p->is_truncated = wgui_softkey_get_offset(
                                    (UI_string_type) GetString(rsk_p->str_id),
                                    &offset_x,
                                    &offset_y,
                                    &rsk_p->truncated_width,
                                    MMI_RIGHT_SOFTKEY,
                                    MMI_FRM_SCREEN_ROTATE_0);
        }
    #endif /* DUAL_CAMERA_SUPPORT */ 
    #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
        rsk_p->is_truncated = wgui_softkey_get_offset(
                                (UI_string_type) GetString(rsk_p->str_id),
                                &offset_x,
                                &offset_y,
                                &rsk_p->truncated_width,
                                MMI_RIGHT_SOFTKEY,
                                MMI_FRM_SCREEN_ROTATE_0);
    #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

        gui_measure_string((UI_string_type) GetString(rsk_p->str_id), &str_width, &str_height);

        rsk_p->offset_x = offset_x;
        rsk_p->offset_y = offset_y;

        rsk_p->touch.offset_x = offset_x;
        rsk_p->touch.offset_y = offset_y;
        rsk_p->touch.width = str_width;
        rsk_p->touch.height = str_height;
        rsk_p->touch.is_press = MMI_FALSE;
        rsk_p->touch.is_usable = MMI_TRUE;
    }
    else
    {
        /* invalid ID */
        MMI_ASSERT(0);
    }

}
#else
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_lsk_img
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_id              [IN]        
 *  img_press_id        [IN]        
 *  event_callback      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_lsk_img(
        MMI_ID_TYPE img_id,
        MMI_ID_TYPE img_press_id,
        void (*event_callback) (mmi_key_types_enum event))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_softkey_struct *lsk_p = &mmi_camco_osd_p->lsk;
    S32 offset_x;
    S32 offset_y;
    S32 img_width;
    S32 img_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lsk_p->img_id = img_id;
    lsk_p->img_press_id = img_press_id;
    lsk_p->event_callback = event_callback;

    memset((void*)&lsk_p->touch, 0, sizeof(mmi_camco_osd_touch_obj_struct));

    if (lsk_p->img_id != 0)
    {
        if (lsk_p->img_press_id == 0)
        {
            lsk_p->img_press_id = lsk_p->img_id;
        }

        gdi_image_get_dimension_id(lsk_p->img_id, &img_width, &img_height);
    #ifdef __MMI_CAMCORDER_SLIM__
        offset_x = mmi_camco_osd_skin_p->softkey.left_softkey.offset_x;
        offset_y = mmi_camco_osd_skin_p->softkey.left_softkey.offset_y;
    #else
        #ifdef HORIZONTAL_CAMERA
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                /* horizontal */
                offset_x = (mmi_camco_osd_p->osd_width - 1) - img_width - MMI_CAMCO_OSD_SOFTKEY_IMG_MARGINE;
                offset_y = (mmi_camco_osd_p->osd_height - 1) - img_height - MMI_CAMCO_OSD_SOFTKEY_IMG_MARGINE;

            }
            #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                /* portrait */
                offset_x = MMI_CAMCO_OSD_SOFTKEY_IMG_MARGINE;
                offset_y = (mmi_camco_osd_p->osd_height - 1) - img_height - MMI_CAMCO_OSD_SOFTKEY_IMG_MARGINE;

            }
            #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* HORIZONTAL_CAMERA */ 
        /* portrait */
            offset_x = MMI_CAMCO_OSD_SOFTKEY_IMG_MARGINE;
            offset_y = (mmi_camco_osd_p->osd_height - 1) - img_height - MMI_CAMCO_OSD_SOFTKEY_IMG_MARGINE;
        #endif /* HORIZONTAL_CAMERA */ 
    #endif
    
    lsk_p->offset_x = offset_x;
    lsk_p->offset_y = offset_y;

    lsk_p->touch.offset_x = offset_x - 5;
    lsk_p->touch.offset_y = offset_y - 5;
    lsk_p->touch.width = img_width + 10;
    lsk_p->touch.height = img_height + 10;
    lsk_p->touch.is_press = MMI_FALSE;
    lsk_p->touch.is_usable = MMI_TRUE;
    
    #ifndef  __MMI_FTE_SUPPORT__
        if(mmi_camco_osd_p->use_lsk_function_and_csk_icon)
            mmi_camco_osd_set_csk_img(IMG_GLOBAL_COMMON_CSK, IMG_GLOBAL_COMMON_CSK, event_callback, KEY_EVENT_UP);
    #else
	    if(mmi_camco_osd_p->use_lsk_function_and_csk_icon)
            mmi_camco_osd_set_csk_img(NULL, NULL, event_callback, KEY_EVENT_UP);
	#endif
    
    }
    else
    {
        /* invalid ID */
        MMI_ASSERT(0);
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_rsk_img
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_id              [IN]        
 *  img_press_id        [IN]        
 *  event_callback      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_rsk_img(
        MMI_ID_TYPE img_id,
        MMI_ID_TYPE img_press_id,
        void (*event_callback) (mmi_key_types_enum event))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_softkey_struct *rsk_p = &mmi_camco_osd_p->rsk;
    S32 offset_x;
    S32 offset_y;
    S32 img_width;
    S32 img_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsk_p->img_id = img_id;
    rsk_p->img_press_id = img_press_id;
    rsk_p->event_callback = event_callback;

    memset((void*)&rsk_p->touch, 0, sizeof(mmi_camco_osd_touch_obj_struct));

    if (rsk_p->img_id != 0)
    {
        if (rsk_p->img_press_id == 0)
        {
            rsk_p->img_press_id = rsk_p->img_id;
        }

        gdi_image_get_dimension_id(rsk_p->img_id, &img_width, &img_height);
    #ifdef __MMI_CAMCORDER_SLIM__
        offset_x = mmi_camco_osd_skin_p->softkey.right_softkey.offset_x;
        offset_y = mmi_camco_osd_skin_p->softkey.right_softkey.offset_y;
    #else
        #ifdef HORIZONTAL_CAMERA
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                /* horizontal */
                offset_x = (mmi_camco_osd_p->osd_width - 1) - img_width - MMI_CAMCO_OSD_SOFTKEY_IMG_MARGINE;
                offset_y = MMI_CAMCO_OSD_SOFTKEY_IMG_MARGINE;
        }
    #ifdef DUAL_CAMERA_SUPPORT
        else
        {
            /* portrait */
            offset_x = (mmi_camco_osd_p->osd_width - 1) - img_width - MMI_CAMCO_OSD_SOFTKEY_IMG_MARGINE;
            offset_y = (mmi_camco_osd_p->osd_height - 1) - img_height - MMI_CAMCO_OSD_SOFTKEY_IMG_MARGINE;

            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* HORIZONTAL_CAMERA */ 
            /* portrait */
            offset_x = (mmi_camco_osd_p->osd_width - 1) - img_width - MMI_CAMCO_OSD_SOFTKEY_IMG_MARGINE;
            offset_y = (mmi_camco_osd_p->osd_height - 1) - img_height - MMI_CAMCO_OSD_SOFTKEY_IMG_MARGINE;
        #endif /* HORIZONTAL_CAMERA */ 
    #endif

        rsk_p->offset_x = offset_x;
        rsk_p->offset_y = offset_y;
        rsk_p->touch.offset_x = offset_x -5;
        rsk_p->touch.offset_y = offset_y - 5;
        rsk_p->touch.width = img_width + 10;
        rsk_p->touch.height = img_height + 10;
        rsk_p->touch.is_press = MMI_FALSE;
        rsk_p->touch.is_usable = MMI_TRUE;
    }
    else
    {
        /* invalid ID */
        MMI_ASSERT(0);
    }

}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_csk_img
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_id              [IN]        
 *  img_press_id        [IN]        
 *  event_callback      [IN]        
 *  event_type          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_csk_img(
        MMI_ID_TYPE img_id,
        MMI_ID_TYPE img_press_id,
        void (*event_callback) (mmi_key_types_enum event),
        mmi_key_types_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_center_softkey_struct *csk_p = &mmi_camco_osd_p->csk;
    S32 offset_x = 0;
    S32 offset_y = 0;
    S32 img_width;
    S32 img_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    csk_p->img_id = img_id;
    csk_p->img_press_id = img_press_id;
    if (KEY_EVENT_DOWN == event_type)
    {
        csk_p->down_event_callback = event_callback;
    }
    else if (KEY_EVENT_UP == event_type)
    {
        csk_p->up_event_callback = event_callback;
    }

    memset((void*)&csk_p->touch, 0, sizeof(mmi_camco_osd_touch_obj_struct));

    if (csk_p->img_id != 0)
    {
        if (csk_p->img_press_id == 0)
        {
            csk_p->img_press_id = csk_p->img_id;
        }

        gdi_image_get_dimension_id(csk_p->img_id, &img_width, &img_height);
    #ifdef __MMI_CAMCORDER_SLIM__
        offset_x = mmi_camco_osd_skin_p->softkey.center_softkey.offset_x;
        offset_y = mmi_camco_osd_skin_p->softkey.center_softkey.offset_y;
    #else
    #ifdef HORIZONTAL_CAMERA
        if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
        {
            offset_x = (mmi_camco_osd_p->osd_width - 1) - img_width - MMI_CAMCO_OSD_SOFTKEY_IMG_MARGINE;
            offset_y = (mmi_camco_osd_p->osd_height - img_height) >> 1;
        }
    #ifdef DUAL_CAMERA_SUPPORT
        else
        {
            offset_x = (mmi_camco_osd_p->osd_width - img_width) >> 1;
            offset_y = (mmi_camco_osd_p->osd_height - 1) - img_height - MMI_CAMCO_OSD_SOFTKEY_IMG_MARGINE;
        }
    #endif /* DUAL_CAMERA_SUPPORT */ 
    #else /* HORIZONTAL_CAMERA */ 
        offset_x = (mmi_camco_osd_p->osd_width - img_width) >> 1;
        offset_y = (mmi_camco_osd_p->osd_height - 1) - img_height - MMI_CAMCO_OSD_SOFTKEY_IMG_MARGINE;
    #endif /* HORIZONTAL_CAMERA */ 
    #endif
        csk_p->offset_x = offset_x;
        csk_p->offset_y = offset_y;

        csk_p->touch.offset_x = offset_x - 5;
        csk_p->touch.offset_y = offset_y - 5;
        csk_p->touch.width = img_width + 10;
        csk_p->touch.height = img_height + 10;
        csk_p->touch.is_press = MMI_FALSE;
        csk_p->touch.is_usable = MMI_TRUE;
    }
    else
    {
        /* invalid ID */
        //MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_set_csk_action_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  use_lsk_function_and_csk_icon        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_set_csk_action_mode(MMI_BOOL use_lsk_function_and_csk_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__
    mmi_camco_osd_p->use_lsk_function_and_csk_icon = use_lsk_function_and_csk_icon;
#else
	mmi_camco_osd_p->use_lsk_function_and_csk_icon = TRUE;
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_softkey_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sk_p        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_softkey_internal(mmi_camco_osd_softkey_struct *sk_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw lsk */
    if (sk_p->str_id)
    {
        gui_set_font(&MMI_medium_font);

        if (sk_p->touch.is_press)
        {
            gui_move_text_cursor(sk_p->offset_x + 1, sk_p->offset_y + 1);
        }
        else
        {
            gui_move_text_cursor(sk_p->offset_x, sk_p->offset_y);
        }

        gui_set_text_color(mmi_camco_osd_p->text_color);
        gui_set_text_border_color(mmi_camco_osd_p->text_border_color);
        if (sk_p->is_truncated)
        {
            if (sk_p->touch.is_press)
            {
                gui_print_truncated_borderd_text(
                    sk_p->offset_x + 1,
                    sk_p->offset_y + 1,
                    sk_p->truncated_width,
                    (UI_string_type) GetString(sk_p->str_id));
            }
            else
            {
                gui_print_truncated_borderd_text(
                    sk_p->offset_x,
                    sk_p->offset_y,
                    sk_p->truncated_width,
                    (UI_string_type) GetString(sk_p->str_id));
            }
        }
        else
        {
            gui_print_bordered_text((UI_string_type) GetString(sk_p->str_id));
        }
    }

    if (sk_p->img_id)
    {
        if (sk_p->touch.is_press)
        {
            gdi_image_draw_id(sk_p->offset_x + 1, sk_p->offset_y + 1, sk_p->img_press_id);
        }
        else
        {
            gdi_image_draw_id(sk_p->offset_x, sk_p->offset_y, sk_p->img_id);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_center_softkey_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_center_softkey_internal()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_center_softkey_struct *sk_p = &mmi_camco_osd_p->csk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw lsk */
    if (sk_p->str_id)
    {
        gui_set_font(&MMI_medium_font);

        if (sk_p->touch.is_press)
        {
            gui_move_text_cursor(sk_p->offset_x + 1, sk_p->offset_y + 1);
        }
        else
        {
            gui_move_text_cursor(sk_p->offset_x, sk_p->offset_y);
        }

        gui_set_text_color(mmi_camco_osd_p->text_color);
        gui_set_text_border_color(mmi_camco_osd_p->text_border_color);
        if (sk_p->is_truncated)
        {
            if (sk_p->touch.is_press)
            {
                gui_print_truncated_borderd_text(
                    sk_p->offset_x + 1,
                    sk_p->offset_y + 1,
                    sk_p->truncated_width,
                    (UI_string_type) GetString(sk_p->str_id));
            }
            else
            {
                gui_print_truncated_borderd_text(
                    sk_p->offset_x,
                    sk_p->offset_y,
                    sk_p->truncated_width,
                    (UI_string_type) GetString(sk_p->str_id));
            }
        }
        else
        {
            gui_print_bordered_text((UI_string_type) GetString(sk_p->str_id));
        }
    }

    if (sk_p->img_id)
    {
        if (sk_p->touch.is_press)
        {
            gdi_image_draw_id(sk_p->offset_x + 1, sk_p->offset_y + 1, sk_p->img_press_id);
        }
        else
        {
            gdi_image_draw_id(sk_p->offset_x, sk_p->offset_y, sk_p->img_id);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_softkey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_draw_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
    mmi_camco_osd_draw_softkey_internal(&mmi_camco_osd_p->lsk);
    mmi_camco_osd_draw_softkey_internal(&mmi_camco_osd_p->rsk);
    mmi_camco_osd_draw_center_softkey_internal();
    gdi_pop_and_restore_alpha_blending_source_layer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_storage_selection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_storage_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 drv_num;
    U8 idx = 0;
    SRV_FMGR_DRVLIST_HANDLE drvlist;
    U8 drv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
    drv_num = srv_fmgr_drivelist_count(drvlist);
            
    mmi_camco_osd_set_option_title(STR_GLOBAL_OPTIONS);

    for (idx = 0; idx < drv_num; idx++)
    {
        drv = srv_fmgr_drivelist_get_drv_letter(drvlist, idx);
        mmi_camco_osd_p->storage_sel_list_enum[idx] = srv_fmgr_drv_get_type(drv); 
        mmi_camco_osd_p->storage_sel_list[idx] = (U8*)get_string(srv_fmgr_drv_get_string(drv));
        mmi_camco_osd_insert_option_item(idx, srv_fmgr_drv_get_string(drv));        
    }     

    mmi_camco_osd_insert_option_done();

    mmi_camco_osd_draw_menulist();
    
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_selected_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void      
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 mmi_camco_osd_get_selected_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 current_idx = mmi_camco_osd_get_option_hilite_idx();
    //U32 current_item = mmi_camco_osd_get_option_item_id(current_idx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_camco_osd_p->storage_sel_list_enum[current_idx];

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_reduced_recoding_softkey_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sk_p        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
void mmi_camco_osd_draw_reduced_recoding_softkey_internal(mmi_camco_osd_softkey_struct *sk_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_rect_struct *rotate_softkey_area_p = &mmi_camco_osd_p->video_recoding_osd.rotate_softkey_area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw lsk */
    if (sk_p->str_id)
    {
        gui_set_font(&MMI_medium_font);

        if (sk_p->touch.is_press)
        {
            gui_move_text_cursor(
                sk_p->offset_x + 1 - rotate_softkey_area_p->x1,
                sk_p->offset_y + 1 - rotate_softkey_area_p->y1);
        }
        else
        {
            gui_move_text_cursor(
                sk_p->offset_x - rotate_softkey_area_p->x1,
                sk_p->offset_y - rotate_softkey_area_p->y1);
        }

        gui_set_text_color(mmi_camco_osd_p->text_color);
        gui_set_text_border_color(mmi_camco_osd_p->text_border_color);
        gui_print_bordered_text((UI_string_type) GetString(sk_p->str_id));
    }

    if (sk_p->img_id)
    {
        if (sk_p->touch.is_press)
        {
            gdi_image_draw_id(
                sk_p->offset_x + 1 - rotate_softkey_area_p->x1,
                sk_p->offset_y + 1 - rotate_softkey_area_p->y1,
                sk_p->img_press_id);
        }
        else
        {
            gdi_image_draw_id(
                sk_p->offset_x - rotate_softkey_area_p->x1,
                sk_p->offset_y - rotate_softkey_area_p->y1,
                sk_p->img_id);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_reduced_recoding_center_softkey_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_reduced_recoding_center_softkey_internal()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_rect_struct *rotate_softkey_area_p = &mmi_camco_osd_p->video_recoding_osd.rotate_softkey_area;
    mmi_camco_osd_center_softkey_struct *sk_p = &mmi_camco_osd_p->csk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw lsk */
    if (sk_p->str_id)
    {
        gui_set_font(&MMI_medium_font);

        if (sk_p->touch.is_press)
        {
            gui_move_text_cursor(
                sk_p->offset_x + 1 - rotate_softkey_area_p->x1,
                sk_p->offset_y + 1 - rotate_softkey_area_p->y1);
        }
        else
        {
            gui_move_text_cursor(
                sk_p->offset_x - rotate_softkey_area_p->x1,
                sk_p->offset_y - rotate_softkey_area_p->y1);
        }

        gui_set_text_color(mmi_camco_osd_p->text_color);
        gui_set_text_border_color(mmi_camco_osd_p->text_border_color);
        gui_print_bordered_text((UI_string_type) GetString(sk_p->str_id));
    }

    if (sk_p->img_id)
    {
        if (sk_p->touch.is_press)
        {
            gdi_image_draw_id(
                sk_p->offset_x + 1 - rotate_softkey_area_p->x1,
                sk_p->offset_y + 1 - rotate_softkey_area_p->y1,
                sk_p->img_press_id);
        }
        else
        {
            gdi_image_draw_id(
                sk_p->offset_x - rotate_softkey_area_p->x1,
                sk_p->offset_y - rotate_softkey_area_p->y1,
                sk_p->img_id);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_reduced_recoding_softkey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_reduced_recoding_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_draw_reduced_recoding_softkey_internal(&mmi_camco_osd_p->lsk);
    mmi_camco_osd_draw_reduced_recoding_softkey_internal(&mmi_camco_osd_p->rsk);
    mmi_camco_osd_draw_reduced_recoding_center_softkey_internal();

}
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_rsk_press_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_rsk_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_softkey_struct *rsk_p = &mmi_camco_osd_p->rsk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* rsk not registered */
    if (rsk_p->event_callback == NULL)
    {
        return;
    }

    /* rsk is already pressed */
    if (rsk_p->touch.is_press)
    {
        return;
    }

    rsk_p->touch.is_press = MMI_TRUE;

    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* shall not have key event who osd hide */
            MMI_ASSERT(0);
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        case MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_PREVIEW:
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        case MMI_CAMCO_OSD_STATE_AUTORAMA_DIRECTION:
        case MMI_CAMCO_OSD_STATE_AUTORAMA_SHOT:
        case MMI_CAMCO_OSD_STATE_MAV_SHOT:
        case MMI_CAMCO_OSD_STATE_FOCUSE_HINT:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:            
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:                    
        {
            /* draw osd */
            mmi_camco_osd_draw_osd();
            break;
        }

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SAVING:
        {
            MMI_ASSERT(0);
            break;
        }

        default:
            MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_rsk_release_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_rsk_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_softkey_struct *rsk_p = &mmi_camco_osd_p->rsk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* rsk not registered */
    if (rsk_p->event_callback == NULL)
    {
        return;
    }

    /* rsk no pressed */
    if (!rsk_p->touch.is_press)
    {
        return;
    }

    rsk_p->touch.is_press = MMI_FALSE;

    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SAVING:
        {
            /* shall not have key event who osd hide */
            MMI_ASSERT(0);
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
		    {
			
            rsk_p->event_callback(KEY_EVENT_UP);
            break;

		    }
        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        case MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_PREVIEW:
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        case MMI_CAMCO_OSD_STATE_AUTORAMA_SHOT:
		case MMI_CAMCO_OSD_STATE_AUTORAMA_DIRECTION:
		case MMI_CAMCO_OSD_STATE_MAV_SHOT:
        case MMI_CAMCO_OSD_STATE_FOCUSE_HINT:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:            
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:                    
        {
            /* draw osd */
            mmi_camco_osd_draw_osd();

            rsk_p->event_callback(KEY_EVENT_UP);
            break;
        }

        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            mmi_camco_setting_set_current_setting_value(MMI_CAMCO_SETTING_CAPMODE, mmi_camco_get_last_capmode());
            /* draw osd */
            mmi_camco_osd_draw_osd();

            rsk_p->event_callback(KEY_EVENT_UP);
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            U16 count;

            /* draw osd */
            mmi_camco_osd_draw_osd();

            if (MMI_CAMCO_SETTING_MAINLIST_SECONDARY == mmi_camco_setting_get_mainlist_type())
            {
                /* retore previous hilited modify setting */
                mmi_camco_setting_restore_hilite_mod();
                gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

                mmi_camco_setting_gen_mainlist(MMI_CAMCO_SETTING_MAINLIST_PRIMARY);
                count = mmi_camco_setting_get_mainlist_count();
                MMI_ASSERT(count != 0);

                /* move to last */
                mmi_camco_setting_set_mainlist_idx((U16) (count - 1));

                mmi_camco_osd_gen_iconlist();
                mmi_camco_osd_gen_setting_menulist();

                mmi_camco_osd_draw_osd();
            }
            else if (MMI_CAMCO_SETTING_MAINLIST_PRIMARY == mmi_camco_setting_get_mainlist_type())
            {
                mmi_camco_setting_restore_hilite_mod();
                rsk_p->event_callback(KEY_EVENT_UP);
            }
            else
            {
                MMI_ASSERT(0);
            }
            break;
        }

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            /* Do nothing */
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_lsk_press_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_lsk_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_softkey_struct *lsk_p = &mmi_camco_osd_p->lsk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* lsk not registered */
    if (lsk_p->event_callback == NULL)
    {
        return;
    }

    /* lsk already pressed */
    if (lsk_p->touch.is_press)
    {
        return;
    }

    lsk_p->touch.is_press = MMI_TRUE;

    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SAVING:
        {
            /* shall not have key event who osd hide */
            MMI_ASSERT(0);
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        case MMI_CAMCO_OSD_STATE_AUTORAMA_DIRECTION:
        case MMI_CAMCO_OSD_STATE_AUTORAMA_SHOT:
		case MMI_CAMCO_OSD_STATE_MAV_SHOT:
        case MMI_CAMCO_OSD_STATE_FOCUSE_HINT:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:            
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:                        
        {
            mmi_camco_osd_draw_osd();
            break;
        }

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            /* Do nothing */
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_lsk_release_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_lsk_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_softkey_struct *lsk_p = &mmi_camco_osd_p->lsk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* lsk not pressed */
    if (!lsk_p->touch.is_press)
    {
        return;
    }

    lsk_p->touch.is_press = MMI_FALSE;

    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SAVING:
        {
            /* shall not have key event who osd hide */
            MMI_ASSERT(0);
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        case MMI_CAMCO_OSD_STATE_FOCUSE_HINT:
		case MMI_CAMCO_OSD_STATE_AUTORAMA_DIRECTION:
        case MMI_CAMCO_OSD_STATE_AUTORAMA_SHOT:
		case MMI_CAMCO_OSD_STATE_MAV_SHOT:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:            
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:              
        {
            /* lsk not registered */
            if (lsk_p->event_callback == NULL)
            {
                return;
            }

            /* draw osd */
            mmi_camco_osd_draw_osd();

            /* callback */
            lsk_p->event_callback(KEY_EVENT_UP);
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            U16 idx;
            U16 count;
            mmi_camco_setting_mainlist_type_enum type;

            /* draw osd */
            mmi_camco_osd_draw_osd();

            idx = mmi_camco_setting_get_mainlist_idx();
            count = mmi_camco_setting_get_mainlist_count();
            type = mmi_camco_setting_get_mainlist_type();

            /* call item select handler - do action */
            /* this function will modify type and index, call after getting those value */
            mmi_camco_setting_item_selected_hdlr();
        
            if (!((type == MMI_CAMCO_SETTING_MAINLIST_PRIMARY) && (idx == count - 1)))
            {
                /* if it is not misc item, call lsk handler */
                lsk_p->event_callback(KEY_EVENT_UP);
            }
            break;
        }

        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            mmi_camco_osd_p->add_frame.is_picked = MMI_TRUE;
            if (lsk_p->event_callback == NULL)
            {
                return;
            }

            /* draw osd */
            mmi_camco_osd_draw_osd();

            /* callback */
            lsk_p->event_callback(KEY_EVENT_UP);
            break;
        }

        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            /* lsk not registered */
            if (lsk_p->event_callback == NULL)
            {
                return;
            }

            /* draw osd */
            mmi_camco_osd_draw_osd();

            /* callback */
            lsk_p->event_callback(KEY_EVENT_UP);
            break;
        }

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            /* Do nothing */
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_csk_press_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_csk_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_center_softkey_struct *csk_p = &mmi_camco_osd_p->csk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* lsk not registered */
    if (csk_p->down_event_callback == NULL && csk_p->up_event_callback == NULL)
    {
        return;
    }

    /* lsk already pressed */
    if (csk_p->touch.is_press)
    {
        return;
    }

    csk_p->touch.is_press = MMI_TRUE;

    if (csk_p->up_event_callback == mmi_camco_osd_p->lsk.event_callback)
    {
        //mmi_camco_osd_p->lsk.touch.is_press = MMI_TRUE;
    }

    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* shall not have key event who osd hide */
            MMI_ASSERT(0);
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        case MMI_CAMCO_OSD_STATE_FOCUSE_HINT:
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:

        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:            
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:              
        {
            mmi_camco_osd_draw_osd();
            if (csk_p->down_event_callback != NULL)
            {
                csk_p->down_event_callback(KEY_EVENT_DOWN);
            }
            break;
        }

        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SAVING:
        case MMI_CAMCO_OSD_STATE_FOCUSE:
        case MMI_CAMCO_OSD_STATE_AUTORAMA_DIRECTION:
        case MMI_CAMCO_OSD_STATE_AUTORAMA_SHOT:
        {
            /* Do nothing */
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_csk_release_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_csk_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_center_softkey_struct *csk_p = &mmi_camco_osd_p->csk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* lsk not registered */
    if (csk_p->up_event_callback == NULL)
    {
        return;
    }

    /* lsk not pressed */
    if (!csk_p->touch.is_press)
    {
        return;
    }

    csk_p->touch.is_press = MMI_FALSE;

    if (csk_p->up_event_callback == mmi_camco_osd_p->lsk.event_callback)
    {
        //mmi_camco_osd_p->lsk.touch.is_press = MMI_FALSE;
    }

    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SAVING:
        {
            /* shall not have key event who osd hide */
            MMI_ASSERT(0);
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        case MMI_CAMCO_OSD_STATE_FOCUSE_HINT:
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        //case MMI_CAMCO_OSD_STATE_AUTORAMA_SHOT:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:            
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:              
        {
            /* draw osd */
            mmi_camco_osd_draw_osd();

            csk_p->up_event_callback(KEY_EVENT_UP);
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            /* same action as lsk */
            U16 idx;
            U16 count;
            mmi_camco_setting_mainlist_type_enum type;

            /* draw osd */
            mmi_camco_osd_draw_osd();

            idx = mmi_camco_setting_get_mainlist_idx();
            count = mmi_camco_setting_get_mainlist_count();
            type = mmi_camco_setting_get_mainlist_type();

            /* call item select handler - do action */
                mmi_camco_setting_item_selected_hdlr();

            if (!((type == MMI_CAMCO_SETTING_MAINLIST_PRIMARY) && (idx == count - 1)))
            {
                /* if it is not misc item, call lsk handler */
                csk_p->up_event_callback(KEY_EVENT_UP);
            }

            break;
        }

        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            mmi_camco_osd_p->add_frame.is_picked = MMI_TRUE;
            if (csk_p->up_event_callback == NULL)
            {
                return;
            }

            /* draw osd */
            mmi_camco_osd_draw_osd();

            /* callback */
            csk_p->up_event_callback(KEY_EVENT_UP);
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
            csk_p->up_event_callback(KEY_EVENT_UP);        	
            break;
                        
        case MMI_CAMCO_OSD_STATE_AUTORAMA_DIRECTION:
        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            /* Do nothing */
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_csk_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_csk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_center_softkey_struct *csk_p = &mmi_camco_osd_p->csk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    csk_p->touch.is_press = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_csk_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_csk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_center_softkey_struct *csk_p = &mmi_camco_osd_p->csk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    csk_p->touch.is_press = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_center_hint_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_center_hint_str(CHAR *str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;
    S32 img_width;
    S32 img_height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->center_hint.str_ptr = str_ptr;
    gui_measure_string((UI_string_type) mmi_camco_osd_p->center_hint.str_ptr, &str_width, &str_height);

           
    gdi_image_get_dimension_id(IMG_GLOBAL_COMMON_CSK, &img_width, &img_height);     
#ifndef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    img_width = 0;
#endif
    if (mmi_camco_setting_get_active_cam() != MMI_CAMCO_SETTING_CAM_MAIN)
        img_width = 0;
        
    mmi_camco_osd_p->center_hint.offset_x = (mmi_camco_osd_p->osd_width - img_width - MMI_CAMCO_OSD_SOFTKEY_IMG_MARGINE - str_width) >> 1;
    if (r2lMMIFlag)
    {
        mmi_camco_osd_p->center_hint.offset_x = mmi_camco_osd_p->osd_width - img_width - MMI_CAMCO_OSD_SOFTKEY_IMG_MARGINE - mmi_camco_osd_p->center_hint.offset_x;
    }

    mmi_camco_osd_p->center_hint.offset_y = (mmi_camco_osd_p->osd_height - str_height) >> 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_center_processing_hint_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_center_processing_hint_str(CHAR *str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->center_hint.is_processing = MMI_TRUE;
    mmi_camco_osd_set_center_hint_str(str_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_corner_hint_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_corner_hint_str(CHAR *str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->corner_hint.str_ptr = str_ptr;
    gui_measure_string((UI_string_type) mmi_camco_osd_p->corner_hint.str_ptr, &str_width, &str_height);

    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_HINT)
    {
        mmi_camco_osd_p->corner_hint.offset_x = mmi_camco_osd_skin_p->camera_preview.corner_hint.offset_x;
        mmi_camco_osd_p->corner_hint.offset_y = mmi_camco_osd_skin_p->camera_preview.corner_hint.offset_x;
    }
    else if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_HINT)
    {
        mmi_camco_osd_p->corner_hint.offset_x = mmi_camco_osd_skin_p->video_preview.corner_hint.offset_x;
        mmi_camco_osd_p->corner_hint.offset_y = mmi_camco_osd_skin_p->video_preview.corner_hint.offset_x;
    }
    else
    {
        MMI_ASSERT(0);
    }

    if (r2lMMIFlag)
    {
        mmi_camco_osd_p->corner_hint.offset_x += str_width;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_multiline_center_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_multiline_center_hint(CHAR* str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define MULTILINE_AREA_OFFSET_WIDTH  (mmi_camco_osd_p->osd_width)
#define MULTILINE_AREA_OFFSET_HEIGHT (60)
#define MULTILINE_AREA_OFFSET_X      (0)
#define MULTILINE_AREA_OFFSET_Y      (mmi_camco_osd_p->osd_height/2 - MULTILINE_AREA_OFFSET_HEIGHT/2)

    S32 str_width = 0;
    S32 str_height = 0;
    S32 str_len = 0;
    S32 line_height;
    S32 layer_offset_x = 0;
    S32 layer_offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_medium_font);
    gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);

    gdi_draw_solid_rect(
        MULTILINE_AREA_OFFSET_X,
        MULTILINE_AREA_OFFSET_Y,
        MULTILINE_AREA_OFFSET_X + MULTILINE_AREA_OFFSET_WIDTH - 1,
        MULTILINE_AREA_OFFSET_Y + MULTILINE_AREA_OFFSET_HEIGHT - 1,
        GDI_COLOR_TRANSPARENT);

    str_len = mmi_ucs2strlen((CHAR*) str_ptr);

    create_multiline_inputbox_set_buffer((UI_string_type) str_ptr, str_len, str_len, 0);
    MMI_multiline_inputbox.normal_text_color = mmi_camco_osd_p->text_color;
    MMI_multiline_inputbox.border_color = mmi_camco_osd_p->text_border_color;
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_USE_BORDER_FONT;
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
        UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
        UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND |
        UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;

    MMI_multiline_inputbox.text_font = &MMI_medium_font;

    resize_multiline_inputbox(MULTILINE_AREA_OFFSET_WIDTH, MULTILINE_AREA_OFFSET_HEIGHT);
    move_multiline_inputbox(MULTILINE_AREA_OFFSET_X + layer_offset_x, MULTILINE_AREA_OFFSET_Y + layer_offset_y);

    /* vertical center alignment */
    show_multiline_inputbox_no_draw();
    line_height = get_multiline_inputbox_line_height();
    resize_multiline_inputbox(
        MULTILINE_AREA_OFFSET_WIDTH,
        (MMI_multiline_inputbox.n_lines * line_height) + MULTILINE_INPUTBOX_HEIGHT_PAD + MMI_multiline_inputbox.text_y);
    move_multiline_inputbox(
        0,
        MULTILINE_AREA_OFFSET_Y + ((MULTILINE_AREA_OFFSET_HEIGHT - MMI_multiline_inputbox.height) >> 1));

    show_multiline_inputbox();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_hint_process_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_hint_process_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->center_hint.dot_count++;

    if (mmi_camco_osd_p->center_hint.dot_count > MMI_CAMCO_OSD_MAX_HINT_DOT_COUNT)
    {
        mmi_camco_osd_p->center_hint.dot_count = 0;
    }

    mmi_camco_osd_draw_osd();

    gui_start_timer(MMI_CAMCO_OSD_HINT_PROCESS_DUR, mmi_camco_osd_draw_hint_process_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define MMI_CAMCO_OSD_TMP_BUF_LEN (100)
#define MMI_CAMCO_OSD_CENTER_HINT_BORDER (5)

    S32 i;
    CHAR str_buf[MMI_CAMCO_OSD_TMP_BUF_LEN];
    S32 str_width = 0;
    S32 str_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_medium_font);

    if (mmi_camco_osd_p->center_hint.str_ptr != NULL)
    {
        gui_set_text_color(mmi_camco_osd_p->text_color);
        gui_set_text_border_color(mmi_camco_osd_p->text_border_color);

        memset(str_buf, 0, MMI_CAMCO_OSD_TMP_BUF_LEN);

        if (r2lMMIFlag)
        {
            for (i = 0; i < mmi_camco_osd_p->center_hint.dot_count; i++)
            {
                mmi_ucs2cat(str_buf, (CHAR*) (L"."));
            }

            mmi_ucs2ncat(
                str_buf,
                (CHAR*) mmi_camco_osd_p->center_hint.str_ptr,
                MMI_CAMCO_OSD_TMP_BUF_LEN - 1 - mmi_camco_osd_p->center_hint.dot_count);

        }
        else
        {
            mmi_ucs2ncpy(
                str_buf,
                (CHAR*) mmi_camco_osd_p->center_hint.str_ptr,
                MMI_CAMCO_OSD_TMP_BUF_LEN - 1 - mmi_camco_osd_p->center_hint.dot_count);

            for (i = 0; i < mmi_camco_osd_p->center_hint.dot_count; i++)
            {
                mmi_ucs2cat(str_buf, (CHAR*) (L"."));
            }
        }

        gui_measure_string((UI_string_type) str_buf, &str_width, &str_height);

        if (str_width < mmi_camco_osd_p->osd_width - 2 * MMI_CAMCO_OSD_CENTER_HINT_BORDER)
        {
            gui_move_text_cursor(mmi_camco_osd_p->center_hint.offset_x, mmi_camco_osd_p->center_hint.offset_y);

            gui_print_bordered_text((UI_string_type) str_buf);

        }
        else
        {
            mmi_camco_osd_draw_multiline_center_hint(str_buf);
        }

        if (mmi_camco_osd_p->center_hint.is_processing)
        {
            gui_start_timer(MMI_CAMCO_OSD_HINT_PROCESS_DUR, mmi_camco_osd_draw_hint_process_cyclic);
        }

    }

    if (mmi_camco_osd_p->corner_hint.str_ptr != NULL)
    {
        gui_set_text_color(mmi_camco_osd_p->text_color);
        gui_set_text_border_color(mmi_camco_osd_p->text_border_color);

        gui_move_text_cursor(mmi_camco_osd_p->corner_hint.offset_x, mmi_camco_osd_p->corner_hint.offset_y);

        gui_print_bordered_text((UI_string_type) mmi_camco_osd_p->corner_hint.str_ptr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_focus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  focus_region        [IN]        
 *  type                [IN]        
 *  center_x            [IN]        
 *  center_y            [IN]        
 *  width               [IN]        
 *  height              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_focus(
        mmi_camco_osd_focus_region_enum focus_region,
        mmi_camco_osd_focus_type_enum type,
        S32 center_x,
        S32 center_y,
        S32 width,
        S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(focus_region < MMI_CAMCO_OSD_FOCUS_REGION_END);

    mmi_camco_osd_p->focus_region[focus_region].type = type;
    mmi_camco_osd_p->focus_region[focus_region].x1 = center_x - (width >> 1);
    mmi_camco_osd_p->focus_region[focus_region].x2 = center_x + (width >> 1);
    mmi_camco_osd_p->focus_region[focus_region].y1 = center_y - (height >> 1);
    mmi_camco_osd_p->focus_region[focus_region].y2 = center_y + (height >> 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_focus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_focus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* focused green */
    mmi_camco_osd_p->focused_color = gdi_act_color_from_rgb(255, 0, 255, 0);
    mmi_camco_osd_p->focused_border_color = gdi_act_color_from_rgb(255, 0, 0, 0);

    /* focusing white */
    mmi_camco_osd_p->focusing_color = gdi_act_color_from_rgb(255, 255, 255, 255);
    mmi_camco_osd_p->focusing_border_color = gdi_act_color_from_rgb(255, 0, 0, 0);

    /* focusing fail red */
    mmi_camco_osd_p->focusing_fail_color = gdi_act_color_from_rgb(255, 255, 0, 0);
    mmi_camco_osd_p->focusing_fail_border_color = gdi_act_color_from_rgb(255, 0, 0, 0);

    /* 255 = no opacity, 0 = full opacity */
    mmi_camco_osd_p->focus_opacity = 200;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_focus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_focus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    gdi_color rect_color = gdi_act_color_from_rgb(255, 255, 255, 255);
    gdi_color border_color = gdi_act_color_from_rgb(255, 255, 255, 255);
    S32 region_height = 0;
    S32 edge_pixel = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CAMCO_OSD_FOCUS_REGION_END; i++)
    {
        if (mmi_camco_osd_p->focus_region[i].type != MMI_CAMCO_OSD_FOCUS_TYPE_NULL)
        {
            if (mmi_camco_osd_p->focus_region[i].type == MMI_CAMCO_OSD_FOCUS_TYPE_FOCUSED)
            {
                rect_color = mmi_camco_osd_p->focused_color;
                border_color = mmi_camco_osd_p->focused_border_color;
            }
            else if (mmi_camco_osd_p->focus_region[i].type == MMI_CAMCO_OSD_FOCUS_TYPE_FOCUSING)
            {
                rect_color = mmi_camco_osd_p->focusing_color;
                border_color = mmi_camco_osd_p->focusing_border_color;

            }
            else if (mmi_camco_osd_p->focus_region[i].type == MMI_CAMCO_OSD_FOCUS_TYPE_FOCUSING_FAIL)
            {
                rect_color = mmi_camco_osd_p->focusing_fail_color;
                border_color = mmi_camco_osd_p->focusing_fail_border_color;
            }
            else
            {
                MMI_ASSERT(0);
            }
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
        #endif /* 0 */ 
            region_height = mmi_camco_osd_p->focus_region[i].y2 - mmi_camco_osd_p->focus_region[i].y1;
            edge_pixel = (MMI_CAMCO_OSD_FOCUSE_EDGE_RATIO * region_height) / 100;

            /* top-left */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 - 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1,
                mmi_camco_osd_p->focus_region[i].x1 - 1 + edge_pixel + 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1,
                mmi_camco_osd_p->focus_region[i].y1,
                mmi_camco_osd_p->focus_region[i].x1 + edge_pixel,
                mmi_camco_osd_p->focus_region[i].y1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + 1,
                mmi_camco_osd_p->focus_region[i].y1 + 1,
                mmi_camco_osd_p->focus_region[i].x1 + 1 + edge_pixel - 1,
                mmi_camco_osd_p->focus_region[i].y1 + 1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + 2,
                mmi_camco_osd_p->focus_region[i].y1 + 2,
                mmi_camco_osd_p->focus_region[i].x1 + 2 + edge_pixel - 2,
                mmi_camco_osd_p->focus_region[i].y1 + 2,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + edge_pixel + 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1,
                mmi_camco_osd_p->focus_region[i].x1 + edge_pixel + 1,
                mmi_camco_osd_p->focus_region[i].y1 + 2,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 - 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1,
                mmi_camco_osd_p->focus_region[i].x1 - 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1 + edge_pixel + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1,
                mmi_camco_osd_p->focus_region[i].y1,
                mmi_camco_osd_p->focus_region[i].x1,
                mmi_camco_osd_p->focus_region[i].y1 + edge_pixel,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + 1,
                mmi_camco_osd_p->focus_region[i].y1 + 1,
                mmi_camco_osd_p->focus_region[i].x1 + 1,
                mmi_camco_osd_p->focus_region[i].y1 + 1 + edge_pixel - 1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + 2,
                mmi_camco_osd_p->focus_region[i].y1 + 2,
                mmi_camco_osd_p->focus_region[i].x1 + 2,
                mmi_camco_osd_p->focus_region[i].y1 + 2 + edge_pixel - 2,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 - 1,
                mmi_camco_osd_p->focus_region[i].y1 + edge_pixel + 1,
                mmi_camco_osd_p->focus_region[i].x1 + 2,
                mmi_camco_osd_p->focus_region[i].y1 + edge_pixel + 1,
                border_color);

            /* top-right */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->focus_region[i].y1 - 1,
                mmi_camco_osd_p->focus_region[i].x2 + 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - edge_pixel,
                mmi_camco_osd_p->focus_region[i].y1,
                mmi_camco_osd_p->focus_region[i].x2,
                mmi_camco_osd_p->focus_region[i].y1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->focus_region[i].y1 + 1,
                mmi_camco_osd_p->focus_region[i].x2 - 1,
                mmi_camco_osd_p->focus_region[i].y1 + 1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 2 - (edge_pixel - 2),
                mmi_camco_osd_p->focus_region[i].y1 + 2,
                mmi_camco_osd_p->focus_region[i].x2 - 2,
                mmi_camco_osd_p->focus_region[i].y1 + 2,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - edge_pixel - 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1,
                mmi_camco_osd_p->focus_region[i].x2 - edge_pixel - 1,
                mmi_camco_osd_p->focus_region[i].y1 + 2,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 + 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1,
                mmi_camco_osd_p->focus_region[i].x2 + 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1 + (edge_pixel + 1),
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2,
                mmi_camco_osd_p->focus_region[i].y1,
                mmi_camco_osd_p->focus_region[i].x2,
                mmi_camco_osd_p->focus_region[i].y1 + edge_pixel,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 1,
                mmi_camco_osd_p->focus_region[i].y1 + 1,
                mmi_camco_osd_p->focus_region[i].x2 - 1,
                mmi_camco_osd_p->focus_region[i].y1 + 1 + (edge_pixel - 1),
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 2,
                mmi_camco_osd_p->focus_region[i].y1 + 2,
                mmi_camco_osd_p->focus_region[i].x2 - 2,
                mmi_camco_osd_p->focus_region[i].y1 + 2 + (edge_pixel - 2),
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 2,
                mmi_camco_osd_p->focus_region[i].y1 + edge_pixel + 1,
                mmi_camco_osd_p->focus_region[i].x2 + 1,
                mmi_camco_osd_p->focus_region[i].y1 + edge_pixel + 1,
                border_color);

            /* bottom-left */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 - 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1,
                mmi_camco_osd_p->focus_region[i].x1 - 1 + edge_pixel + 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1,
                mmi_camco_osd_p->focus_region[i].y2,
                mmi_camco_osd_p->focus_region[i].x1 + edge_pixel,
                mmi_camco_osd_p->focus_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + 1,
                mmi_camco_osd_p->focus_region[i].y2 - 1,
                mmi_camco_osd_p->focus_region[i].x1 + 1 + edge_pixel - 1,
                mmi_camco_osd_p->focus_region[i].y2 - 1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + 2,
                mmi_camco_osd_p->focus_region[i].y2 - 2,
                mmi_camco_osd_p->focus_region[i].x1 + 2 + edge_pixel - 2,
                mmi_camco_osd_p->focus_region[i].y2 - 2,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + edge_pixel + 1,
                mmi_camco_osd_p->focus_region[i].y2 - 2,
                mmi_camco_osd_p->focus_region[i].x1 + edge_pixel + 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 - 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->focus_region[i].x1 - 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1,
                mmi_camco_osd_p->focus_region[i].y2 - edge_pixel,
                mmi_camco_osd_p->focus_region[i].x1,
                mmi_camco_osd_p->focus_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + 1,
                mmi_camco_osd_p->focus_region[i].y2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->focus_region[i].x1 + 1,
                mmi_camco_osd_p->focus_region[i].y2 - 1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + 2,
                mmi_camco_osd_p->focus_region[i].y2 - 2 - (edge_pixel - 2),
                mmi_camco_osd_p->focus_region[i].x1 + 2,
                mmi_camco_osd_p->focus_region[i].y2 - 2,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 - 1,
                mmi_camco_osd_p->focus_region[i].y2 - edge_pixel - 1,
                mmi_camco_osd_p->focus_region[i].x1 + 2,
                mmi_camco_osd_p->focus_region[i].y2 - edge_pixel - 1,
                border_color);

            /* bottom-right */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->focus_region[i].y2 + 1,
                mmi_camco_osd_p->focus_region[i].x2 + 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - edge_pixel,
                mmi_camco_osd_p->focus_region[i].y2,
                mmi_camco_osd_p->focus_region[i].x2,
                mmi_camco_osd_p->focus_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->focus_region[i].y2 - 1,
                mmi_camco_osd_p->focus_region[i].x2 - 1,
                mmi_camco_osd_p->focus_region[i].y2 - 1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 2 - (edge_pixel - 2),
                mmi_camco_osd_p->focus_region[i].y2 - 2,
                mmi_camco_osd_p->focus_region[i].x2 - 2,
                mmi_camco_osd_p->focus_region[i].y2 - 2,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - edge_pixel - 1,
                mmi_camco_osd_p->focus_region[i].y2 - 2,
                mmi_camco_osd_p->focus_region[i].x2 - edge_pixel - 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 + 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->focus_region[i].x2 + 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2,
                mmi_camco_osd_p->focus_region[i].y2 - edge_pixel,
                mmi_camco_osd_p->focus_region[i].x2,
                mmi_camco_osd_p->focus_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 1,
                mmi_camco_osd_p->focus_region[i].y2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->focus_region[i].x2 - 1,
                mmi_camco_osd_p->focus_region[i].y2 - 1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 2,
                mmi_camco_osd_p->focus_region[i].y2 - 2 - (edge_pixel - 2),
                mmi_camco_osd_p->focus_region[i].x2 - 2,
                mmi_camco_osd_p->focus_region[i].y2 - 2,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 2,
                mmi_camco_osd_p->focus_region[i].y2 - edge_pixel - 1,
                mmi_camco_osd_p->focus_region[i].x2 + 1,
                mmi_camco_osd_p->focus_region[i].y2 - edge_pixel - 1,
                border_color);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_focus_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_init_focus_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->focus_hint.img_id = 0;
    mmi_camco_osd_p->focus_hint.is_hint_show = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_center_focus_process_hint_img
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_center_focus_process_hint_img(MMI_ID_TYPE img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_width;
    S32 img_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->focus_hint.is_processing = MMI_TRUE;
    gdi_image_get_dimension_id((U16) img_id, &img_width, &img_height);
    mmi_camco_osd_p->focus_hint.img_id = img_id;

    mmi_camco_osd_p->focus_hint.offset_x = (mmi_camco_osd_p->osd_width - img_width) >> 1;
    mmi_camco_osd_p->focus_hint.offset_y = (mmi_camco_osd_p->osd_height - img_height) >> 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_focus_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_focus_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_camco_osd_p->focus_hint.is_hint_show && mmi_camco_osd_p->focus_hint.img_id)
    {
        gdi_image_draw_id(
            mmi_camco_osd_p->focus_hint.offset_x,
            mmi_camco_osd_p->focus_hint.offset_y,
            (U16) (mmi_camco_osd_p->focus_hint.img_id));

        mmi_camco_osd_p->focus_hint.is_hint_show = MMI_TRUE;

    }
    else
    {
        mmi_camco_osd_clear_bg();
        mmi_camco_osd_p->focus_hint.is_hint_show = MMI_FALSE;

    }

    if (mmi_camco_osd_p->focus_hint.is_processing)
    {
        gui_start_timer(MMI_CAMCO_OSD_FOCUS_HINT_PROCESS_DUR, mmi_camco_osd_draw_focus_hint_process_cyclic);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_focus_hint_process_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_focus_hint_process_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_draw_osd();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_add_frame_highlighted_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
extern void mmi_camco_osd_set_add_frame_highlighted_idx(U16 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->add_frame.highlighted_idx = idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_add_frame_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
extern U16 mmi_camco_osd_get_add_frame_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->add_frame.highlighted_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_overlay_frame_buf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
extern U8 *mmi_camco_osd_get_overlay_frame_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->add_frame.overlay_frame_layer_buf_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_overlay_frame_cap_buf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
extern U8 *mmi_camco_osd_get_overlay_frame_cap_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->add_frame.overlay_frame_layer_cap_buf_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_add_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_init_add_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;
    S32 image_width;
    S32 image_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    add_frame_p->frame_count = IMG_ID_CAMCO_ADD_FRAME_COLOR_IDX_COUNT - IMG_ID_CAMCO_ADD_FRAME_COLOR_IDX_BASE - 1;

    gdi_image_get_dimension_id(IMG_ID_CAMCO_ARROW_LEFT, &image_width, &image_height);

    /* left arrow top-right corner */
    add_frame_p->la_touch.offset_x = mmi_camco_osd_skin_p->add_frame.left_arrow.offset_x + 5;
    add_frame_p->la_touch.offset_y = mmi_camco_osd_skin_p->add_frame.left_arrow.offset_y ;
    /* right arrow top-left corner */
    add_frame_p->ra_touch.offset_x = mmi_camco_osd_skin_p->add_frame.right_arrow.offset_x - 5;
    add_frame_p->ra_touch.offset_y = mmi_camco_osd_skin_p->add_frame.right_arrow.offset_y;
    /*enlarge touch region*/
	image_width += 10;
	image_height += 5;

    add_frame_p->la_touch.width = image_width;
    add_frame_p->la_touch.height = image_height;
    add_frame_p->la_touch.offset_x -= image_width;

    add_frame_p->ra_touch.width = image_width;
    add_frame_p->ra_touch.height = image_height;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_add_frame_color_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_add_frame_color_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_region_offset_x;
    S32 image_region_offset_y;
    S32 image_region_width;
    S32 image_region_height;
    S32 image_width;
    S32 image_height;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;
    U16 image_idx;
    GDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

    mmi_camco_get_preview_region(
        &image_region_offset_x,
        &image_region_offset_y,
        &image_region_width,
        &image_region_height);

    image_idx = (U16) (IMG_ID_CAMCO_ADD_FRAME_COLOR_IDX_BASE + mmi_camco_osd_p->add_frame.highlighted_idx + 1);

    result = gdi_image_get_dimension_id(image_idx, &image_width, &image_height);

    if (result >= 0)
    {
        if ((image_region_width >= image_width) && (image_region_height >= image_height))
        {
            gdi_image_draw_id(image_region_offset_x, image_region_offset_y, (U16) (image_idx));
        }
        else
        {
            gdi_image_util_fit_bbox(
                image_region_width,
                image_region_height,
                image_width,
                image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            gdi_image_draw_resized_id(
                resized_offset_x + image_region_offset_x,
                resized_offset_y + image_region_offset_y,
                resized_width,
                resized_height,
                image_idx);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_add_frame_color_idx_on_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  palette_size        [OUT]       
 *  palette_address     [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_draw_add_frame_color_idx_on_layer(U8 *palette_size, U32 **palette_address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color *p_gdi_palette;
    U16 i;
    U32 Y, U, V;
    U32 R, G, B;
    U32 *p_overlay_palette;
    U16 image_idx;
    mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;
    S32 image_region_offset_x;
    S32 image_region_offset_y;
    S32 image_region_width;
    S32 image_region_height;
    GDI_RESULT result;
    S32 image_width;
    S32 image_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    image_idx = (U16) (IMG_ID_CAMCO_ADD_FRAME_COLOR_IDX_BASE + mmi_camco_osd_p->add_frame.highlighted_idx + 1);
    gdi_layer_push_and_set_active(add_frame_p->overlay_frame_layer_h);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

    mmi_camco_get_preview_region(
        &image_region_offset_x,
        &image_region_offset_y,
        &image_region_width,
        &image_region_height);

    gdi_layer_resize(image_region_width, image_region_height);

    result = gdi_image_get_dimension_id(image_idx, &image_width, &image_height);

    if (result < 0)
    {
        return;
    }

    if ((image_region_width >= image_width) && (image_region_height >= image_height))
    {
        gdi_image_draw_id_with_transparent_color(0, 0, (U16) (image_idx));
    }
    else
    {
        gdi_image_draw_resized_id_with_transparent_color(
            0,
            0,
            image_region_width,
            image_region_height,
            (U16) (image_idx));
    }

    p_gdi_palette = gdi_layer_get_palette();

    add_frame_p->overlay_frame_palette_size = gdi_image_gif_get_palette_size();
    /*************** RGB to YUV format **************************************************
    *
    *     [MSDN RGB888 to YUV444 (16bits)]
    *
    *     Y = ( (  66 * R + 129 * G +  25 * B + 128) >> 8) +  16
    *     U = ( ( -38 * R -  74 * G + 112 * B + 128) >> 8) + 128
    *     V = ( ( 112 * R -  94 * G -  18 * B + 128) >> 8) + 128
    *     
    *     These formulas produce 8-bit results using coefficients 
    *     that require no more than 8 bits of (unsigned) precision. 
    *     Intermediate results require up to 16 bits of precision.
    *
    ***************************************************************************************/
    p_overlay_palette = &add_frame_p->overlay_palette[0];
    for (i = 0; i < 256; i++)
    {
        R = (U32) ((U8) (*p_gdi_palette >> 16));
        G = (U32) ((U8) (*p_gdi_palette >> 8));
        B = (U32) ((U8) (*p_gdi_palette));

        Y = (U32) ((U8) (((66 * R + 129 * G + 25 * B + 128) >> 8) + 16));
        U = (U32) ((U8) (((-38 * R - 74 * G + 112 * B + 128) >> 8) + 128));
        V = (U32) ((U8) (((112 * R - 94 * G - 18 * B + 128) >> 8) + 128));

        (*p_overlay_palette) = (V) | (U << 8) | (Y << 16);
        p_overlay_palette++;
        p_gdi_palette++;
    }

    *palette_size = add_frame_p->overlay_frame_palette_size;
    *palette_address = &add_frame_p->overlay_palette[0];

    gdi_layer_pop_and_restore_active();

}

void mmi_camco_osd_get_add_frame_size(S32 * width, S32 * height)
{
  gdi_layer_push_and_set_active(mmi_camco_osd_p->add_frame.overlay_frame_cap_layer_h);
  gdi_layer_get_dimension(width,height);
  gdi_layer_pop_and_restore_active();

}
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_add_frame_color_idx_cap_on_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  palette_size        [OUT]       
 *  palette_address     [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_draw_add_frame_color_idx_cap_on_layer(U8 *palette_size, U32 **palette_address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color *p_gdi_palette;
    U16 i;
    U32 Y, U, V;
    U32 R, G, B;
    U32 *p_overlay_palette;
    U16 image_idx;
    mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;
    GDI_RESULT result;
    S32 image_width;
    S32 image_height;
#ifdef __CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__
    GDI_HANDLE handle;
    U8* buf_ptr;
    S32 layer_width;
	S32 layer_height;
	S32 temp;
	U8 rotate = GDI_LAYER_ROTATE_0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    image_idx = (U16) (IMG_ID_CAMCO_ADD_FRAME_COLOR_IDX_BASE + mmi_camco_osd_p->add_frame.highlighted_idx + 1);
    gdi_layer_push_and_set_active(add_frame_p->overlay_frame_cap_layer_h);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

    gdi_layer_resize(MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH, MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT);

    result = gdi_image_get_dimension_id(image_idx, &image_width, &image_height);

    if (result < 0)
    {
        return;
    }
#ifdef __CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__
   	    gdi_layer_get_dimension(&layer_width,&layer_height);
		gdi_layer_create_cf(GDI_COLOR_FORMAT_8,0,0,layer_width,layer_height,&handle);
	#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
		if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
		{
			if(mmi_camco_get_capture_rotate_value()==MDI_CAMERA_UI_ROTATE_180 )
			{
			    gdi_layer_resize(layer_height,layer_width);
	            rotate = GDI_LAYER_ROTATE_270;
			}
			else if(mmi_camco_get_capture_rotate_value()==MDI_CAMERA_UI_ROTATE_0)
			{
				gdi_layer_resize(layer_height,layer_width);
				rotate =GDI_LAYER_ROTATE_90;
			}else if(mmi_camco_get_capture_rotate_value()==MDI_CAMERA_UI_ROTATE_270)
			{
				rotate = GDI_LAYER_ROTATE_180;
			}
		}
		else
		{
			if(mmi_camco_get_capture_rotate_value()==MDI_CAMERA_UI_ROTATE_180 )
			{
	            rotate = GDI_LAYER_ROTATE_180;
			}
			else if(mmi_camco_get_capture_rotate_value()==MDI_CAMERA_UI_ROTATE_90)
			{
				gdi_layer_resize(layer_height,layer_width);
				rotate = GDI_LAYER_ROTATE_270;
			}else if(mmi_camco_get_capture_rotate_value()==MDI_CAMERA_UI_ROTATE_270)
			{
				rotate = GDI_LAYER_ROTATE_90;
				gdi_layer_resize(layer_height,layer_width);
			}

		}
	#else
		if(mmi_camco_get_capture_rotate_value()==MDI_CAMERA_UI_ROTATE_180 )
		{
			rotate = GDI_LAYER_ROTATE_180;
		}
		else if(mmi_camco_get_capture_rotate_value()==MDI_CAMERA_UI_ROTATE_90)
		{
			gdi_layer_resize(layer_height,layer_width);
			rotate = GDI_LAYER_ROTATE_270;
		}else if(mmi_camco_get_capture_rotate_value()==MDI_CAMERA_UI_ROTATE_270)
		{
			rotate = GDI_LAYER_ROTATE_90;
			gdi_layer_resize(layer_height,layer_width);
		}

	#endif
	gdi_layer_push_and_set_active(handle);
    if ((MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH >= image_width) &&
        (MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT >= image_height))
    {
        gdi_image_draw_id_with_transparent_color(0, 0, (U16) (image_idx));
    }
    else
    {
        gdi_image_draw_resized_id_with_transparent_color(
            0,
            0,
            MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH,
            MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT,
            (U16) (image_idx));
    }
    gdi_layer_pop_and_restore_active();
	mdi_util_rotate_layer_partial_region(handle,0,0,MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH,MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT,add_frame_p->overlay_frame_cap_layer_h,rotate);
	gdi_layer_free(handle);

#else
if ((MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH >= image_width) &&
	(MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT >= image_height))
{
	gdi_image_draw_id_with_transparent_color(0, 0, (U16) (image_idx));
}
else
{
	gdi_image_draw_resized_id_with_transparent_color(
		0,
		0,
		MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH,
		MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT,
		(U16) (image_idx));
}

#endif

    p_gdi_palette = gdi_layer_get_palette();

    add_frame_p->overlay_frame_palette_size = gdi_image_gif_get_palette_size();
    /*************** RGB to YUV format **************************************************
    *
    *     [MSDN RGB888 to YUV444 (16bits)]
    *
    *     Y = ( (  66 * R + 129 * G +  25 * B + 128) >> 8) +  16
    *     U = ( ( -38 * R -  74 * G + 112 * B + 128) >> 8) + 128
    *     V = ( ( 112 * R -  94 * G -  18 * B + 128) >> 8) + 128
    *     
    *     These formulas produce 8-bit results using coefficients 
    *     that require no more than 8 bits of (unsigned) precision. 
    *     Intermediate results require up to 16 bits of precision.
    *
    ***************************************************************************************/
    p_overlay_palette = &add_frame_p->overlay_palette[0];
    for (i = 0; i < 256; i++)
    {
        R = (U32) ((U8) (*p_gdi_palette >> 16));
        G = (U32) ((U8) (*p_gdi_palette >> 8));
        B = (U32) ((U8) (*p_gdi_palette));

        Y = (U32) ((U8) (((66 * R + 129 * G + 25 * B + 128) >> 8) + 16));
        U = (U32) ((U8) (((-38 * R - 74 * G + 112 * B + 128) >> 8) + 128));
        V = (U32) ((U8) (((112 * R - 94 * G - 18 * B + 128) >> 8) + 128));

        (*p_overlay_palette) = (V) | (U << 8) | (Y << 16);
        p_overlay_palette++;
        p_gdi_palette++;
    }

    *palette_size = add_frame_p->overlay_frame_palette_size;
    *palette_address = &add_frame_p->overlay_palette[0];

    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_add_frame_file_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_add_frame_file_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 la_offset_x;
    S32 ra_offset_x;
    S32 file_idx_offset_x;
    S32 file_idx_offset_y;
    S32 offset_y;
    S32 image_width;
    S32 image_height;
    S32 slash_img_width;
    S32 tens_place = 0;
    S32 units_place = 0;
    mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define MMI_CAMCO_OSD_FILE_NUM_INTERVAL (1)
#define MMI_CAMCO_OSD_FILE_SLASH_INTERVAL (3)

    gdi_image_get_dimension_id(IMG_ID_CAMCO_ARROW_LEFT, &image_width, &image_height);

	la_offset_x = mmi_camco_osd_skin_p->add_frame.left_arrow.offset_x - image_width; 
    ra_offset_x = mmi_camco_osd_skin_p->add_frame.right_arrow.offset_x ;

    file_idx_offset_x = mmi_camco_osd_skin_p->add_frame.file_index.offset_x;
    file_idx_offset_y = mmi_camco_osd_skin_p->add_frame.file_index.offset_y;

    offset_y = mmi_camco_osd_skin_p->add_frame.left_arrow.offset_y;

    /* draw lefe arrow */
    if (add_frame_p->la_touch.is_press == MMI_TRUE)
    {
        #ifdef __MMI_FTE_SUPPORT__
            gdi_image_draw_id(la_offset_x + 1, offset_y + 1, (U16) IMG_ID_CAMCO_ARROW_LEFT_SEL);
        #else
            gdi_image_draw_id(la_offset_x + 1, offset_y + 1, (U16) IMG_ID_CAMCO_ARROW_LEFT);
        #endif
    }
    else
    {
        gdi_image_draw_id(la_offset_x, offset_y, (U16) IMG_ID_CAMCO_ARROW_LEFT);
    }

    /* draw right arrow */
    if (add_frame_p->ra_touch.is_press == MMI_TRUE)
    {
        #ifdef __MMI_FTE_SUPPORT__
            gdi_image_draw_id(ra_offset_x + 1, offset_y + 1, (U16) IMG_ID_CAMCO_ARROW_RIGHT_SEL);
        #else
            gdi_image_draw_id(ra_offset_x + 1, offset_y + 1, (U16) IMG_ID_CAMCO_ARROW_RIGHT);        
        #endif

    }
    else
    {
        gdi_image_draw_id(ra_offset_x, offset_y, (U16) IMG_ID_CAMCO_ARROW_RIGHT);
    }

    /* draw "file index / file count" */
    gdi_image_get_dimension_id(IMG_ID_CAMCO_OSD_TIMER_0, &image_width, &image_height);

    tens_place = (mmi_camco_osd_p->add_frame.highlighted_idx + 1) / 10;
    units_place = (mmi_camco_osd_p->add_frame.highlighted_idx + 1) % 10;

    gdi_image_draw_id(file_idx_offset_x, file_idx_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + tens_place));
    file_idx_offset_x += image_width + MMI_CAMCO_OSD_FILE_NUM_INTERVAL;
    gdi_image_draw_id(file_idx_offset_x, file_idx_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + units_place));

    file_idx_offset_x += image_width + MMI_CAMCO_OSD_FILE_SLASH_INTERVAL;
    gdi_image_draw_id(file_idx_offset_x, file_idx_offset_y, (U16) IMG_ID_CAMCO_SLASH);

    gdi_image_get_dimension_id(IMG_ID_CAMCO_SLASH, &slash_img_width, &image_height);

    tens_place = mmi_camco_osd_p->add_frame.frame_count / 10;
    units_place = mmi_camco_osd_p->add_frame.frame_count % 10;

    file_idx_offset_x += slash_img_width + MMI_CAMCO_OSD_FILE_SLASH_INTERVAL;
    gdi_image_draw_id(file_idx_offset_x, file_idx_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + tens_place));
    file_idx_offset_x += image_width + MMI_CAMCO_OSD_FILE_NUM_INTERVAL;
    gdi_image_draw_id(file_idx_offset_x, file_idx_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + units_place));

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_is_add_frame_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
extern MMI_BOOL mmi_camco_osd_is_add_frame_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->add_frame.is_picked;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_add_frame_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_enable       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_add_frame_enable(MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->add_frame.is_picked = is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_add_frame_prev_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_add_frame_prev_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_camco_osd_add_frame_move_prev())
    {
        mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

        add_frame_p->highlighted_idx = add_frame_p->frame_count - 1;
    }

    mmi_camco_osd_draw_osd();
    gui_start_timer(MMI_CAMCO_OSD_TOUCH_ADD_FRAME_MOVE_DUR, mmi_camco_osd_add_frame_prev_cyclic);

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_add_frame_next_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_add_frame_next_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_camco_osd_add_frame_move_next())
    {
        mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

        add_frame_p->highlighted_idx = 0;
    }

    mmi_camco_osd_draw_osd();
    gui_start_timer(MMI_CAMCO_OSD_TOUCH_ADD_FRAME_MOVE_DUR, mmi_camco_osd_add_frame_next_cyclic);

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_is_time_stamp_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
 extern MMI_BOOL mmi_camco_osd_is_time_stamp_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->time_stamp.is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_time_stamp_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_enable       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_time_stamp_enable(MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->time_stamp.is_enable = is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_time_stamp_color_idx_on_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  palette_size        [OUT]       
 *  palette_address     [OUT]       
 *  overlay_width       [OUT]       
 *  overlay_height      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_draw_time_stamp_color_idx_on_layer(
        U8 *palette_size,
        U32 **palette_address,
        S32 *overlay_width,
        S32 *overlay_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color *p_gdi_palette;
    U16 i;
    U32 Y, U, V;
    U32 R, G, B;
    U32 *p_overlay_palette;
    U16 image_idx = 0;
    U16 colon_image_idx = 0;
    mmi_camco_osd_time_stamp_struct *time_stamp_p = &mmi_camco_osd_p->time_stamp;
    mmi_camco_capsize_enum capsize;
    S32 layer_width = 0;
    S32 layer_height = 0;
    applib_time_struct time;
    S32 offset_x;
    S32 offset_y;
    S32 num_img_width;
    S32 num_img_height;
    S32 colon_img_width;
    S32 colon_img_height;
    gdi_color source_key = 0;
    U8 offset_x_from_right = 0;
    U8 offset_y_from_bottom = 0;

#ifdef __CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__
S32 temp = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_date_time(&time);

    capsize = mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPSIZE);

    if (capsize == MMI_CAMCO_CAPSIZE_WALLPAPER)
    {
        image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_320X240_0;
        colon_image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_320X240_COLON;
        layer_width = LCD_WIDTH;
        layer_height = LCD_HEIGHT;
        offset_x_from_right = mmi_camco_osd_skin_p->time_stamp.wallpaper.offset_x_from_right;
        offset_y_from_bottom = mmi_camco_osd_skin_p->time_stamp.wallpaper.offset_y_from_bottom;
    }
#if defined(HORIZONTAL_CAMERA)
    else if (capsize == MMI_CAMCO_CAPSIZE_HLCD)
    {
        image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_320X240_0;
        colon_image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_320X240_COLON;
        layer_width = MMI_CAMCO_TIME_STAMP_COLOR_IDX_5_WIDTH;
        layer_height = MMI_CAMCO_TIME_STAMP_COLOR_IDX_5_HEIGHT;
        offset_x_from_right = mmi_camco_osd_skin_p->time_stamp.HLCD.offset_x_from_right;
        offset_y_from_bottom = mmi_camco_osd_skin_p->time_stamp.HLCD.offset_y_from_bottom;
    }
#endif /* defined(HORIZONTAL_CAMERA) */ 
    else if (capsize == MMI_CAMCO_CAPSIZE_VGA || capsize == MMI_CAMCO_CAPSIZE_1MP || capsize == MMI_CAMCO_CAPSIZE_2MP)
    {
        image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_320X240_0;
        colon_image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_320X240_COLON;
        layer_width = MMI_CAMCO_TIME_STAMP_COLOR_IDX_3_WIDTH;
        layer_height = MMI_CAMCO_TIME_STAMP_COLOR_IDX_3_HEIGHT;
        offset_x_from_right = mmi_camco_osd_skin_p->time_stamp.VGA_to_2M.offset_x_from_right;
        offset_y_from_bottom = mmi_camco_osd_skin_p->time_stamp.VGA_to_2M.offset_y_from_bottom;
    }
    else if (capsize == MMI_CAMCO_CAPSIZE_3MP)
    {
        image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_256X192_0; 
        colon_image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_256X192_COLON;
        layer_width = MMI_CAMCO_TIME_STAMP_COLOR_IDX_1_WIDTH;
        layer_height = MMI_CAMCO_TIME_STAMP_COLOR_IDX_1_HEIGHT;
        offset_x_from_right = mmi_camco_osd_skin_p->time_stamp.Three_M.offset_x_from_right;
        offset_y_from_bottom = mmi_camco_osd_skin_p->time_stamp.Three_M.offset_y_from_bottom;
    }
#ifdef __MMI_CAMCO_FEATURE_CAM_IMGSZIE_SUPPORT_4M__    
    else if (capsize == MMI_CAMCO_CAPSIZE_4MP)
    {
        image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_288X216_0; 
        colon_image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_288X216_COLON;
        layer_width = MMI_CAMCO_TIME_STAMP_COLOR_IDX_2_WIDTH;
        layer_height = MMI_CAMCO_TIME_STAMP_COLOR_IDX_2_HEIGHT;
        offset_x_from_right = mmi_camco_osd_skin_p->time_stamp.Four_M.offset_x_from_right;
        offset_y_from_bottom = mmi_camco_osd_skin_p->time_stamp.Four_M.offset_y_from_bottom;
    }
#endif  
#ifdef __MMI_CAMCO_FEATURE_CAM_IMGSZIE_SUPPORT_5M__ 
    else if (capsize == MMI_CAMCO_CAPSIZE_5MP)
    {
        image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_324X243_0;
        colon_image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_324X243_COLON;
        layer_width = MMI_CAMCO_TIME_STAMP_COLOR_IDX_4_WIDTH;
        layer_height = MMI_CAMCO_TIME_STAMP_COLOR_IDX_4_HEIGHT;
        offset_x_from_right = mmi_camco_osd_skin_p->time_stamp.Five_M.offset_x_from_right;
        offset_y_from_bottom = mmi_camco_osd_skin_p->time_stamp.Five_M.offset_y_from_bottom;
    }
#endif

#ifdef __CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__
	#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
	if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
	{

	    if(mmi_camco_get_capture_rotate_value()==MDI_CAMERA_UI_ROTATE_180 ||mmi_camco_get_capture_rotate_value()==MDI_CAMERA_UI_ROTATE_0)
		{
			temp = layer_width;
			layer_width = layer_height;
			layer_height = temp;
		}
	}
	else
	{
	    if(mmi_camco_get_capture_rotate_value()==MDI_CAMERA_UI_ROTATE_270 ||mmi_camco_get_capture_rotate_value()==MDI_CAMERA_UI_ROTATE_90)
		{
			temp = layer_width;
			layer_width = layer_height;
			layer_height = temp;
		}
	}
	#else
	if(mmi_camco_get_capture_rotate_value()==MDI_CAMERA_UI_ROTATE_270 ||mmi_camco_get_capture_rotate_value()==MDI_CAMERA_UI_ROTATE_90)
	{
		temp = layer_width;
		layer_width = layer_height;
		layer_height = temp;
	}	
	#endif
#endif
    gdi_image_get_dimension_id(image_idx, &num_img_width, &num_img_height);
    gdi_image_get_dimension_id(colon_image_idx, &colon_img_width, &colon_img_height);

    offset_x = layer_width -
        (offset_x_from_right +
         12 * num_img_width +
         2 * mmi_camco_osd_skin_p->time_stamp.date_interval + mmi_camco_osd_skin_p->time_stamp.offset_to_time);

    offset_y = layer_height - offset_y_from_bottom;

    gdi_layer_push_and_set_active(time_stamp_p->overlay_frame_layer_h);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_resize(layer_width, layer_height);

    /* Get the source key of timestamp and fill the color to all layer */
    gdi_image_draw_id_with_transparent_color(0, 0, (U16) image_idx);
    source_key = gdi_image_bmp_get_transparent_index();
    memset(time_stamp_p->overlay_frame_layer_buf_p, source_key, (S32) (MMI_CAMCO_OVERLAY_COLOR_IDX_BUFFER_SIZE) - 4);

    /* year */
    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nYear / 1000) % 10));
    offset_x += num_img_width;

    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nYear / 100) % 10));
    offset_x += num_img_width;

    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nYear / 10) % 10));
    offset_x += num_img_width;

    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nYear) % 10));
    offset_x += num_img_width;

    offset_x += mmi_camco_osd_skin_p->time_stamp.date_interval;

    /* month */
    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nMonth / 10) % 10));
    offset_x += num_img_width;

    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nMonth) % 10));
    offset_x += num_img_width;

    offset_x += mmi_camco_osd_skin_p->time_stamp.date_interval;

    /* day */
    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nDay / 10) % 10));
    offset_x += num_img_width;

    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nDay) % 10));
    offset_x += num_img_width;

    offset_x += mmi_camco_osd_skin_p->time_stamp.offset_to_time;

    /* hour */
    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nHour / 10) % 10));
    offset_x += num_img_width;

    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nHour) % 10));
    offset_x += num_img_width;

    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) colon_image_idx);
    offset_x += colon_img_width;

    /* Min */
    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nMin / 10) % 10));
    offset_x += num_img_width;

    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nMin) % 10));

    p_gdi_palette = gdi_layer_get_palette();

    time_stamp_p->overlay_frame_palette_size = gdi_image_bmp_get_palette_size();
    /*************** RGB to YUV format **************************************************
    *
    *     [MSDN RGB888 to YUV444 (16bits)]
    *
    *     Y = ( (  66 * R + 129 * G +  25 * B + 128) >> 8) +  16
    *     U = ( ( -38 * R -  74 * G + 112 * B + 128) >> 8) + 128
    *     V = ( ( 112 * R -  94 * G -  18 * B + 128) >> 8) + 128
    *     
    *     These formulas produce 8-bit results using coefficients 
    *     that require no more than 8 bits of (unsigned) precision. 
    *     Intermediate results require up to 16 bits of precision.
    *
    ***************************************************************************************/
    p_overlay_palette = &time_stamp_p->overlay_palette[0];
    for (i = 0; i < 256; i++)
    {
        R = (U32) ((U8) (*p_gdi_palette >> 16));
        G = (U32) ((U8) (*p_gdi_palette >> 8));
        B = (U32) ((U8) (*p_gdi_palette));

        Y = (U32) ((U8) (((66 * R + 129 * G + 25 * B + 128) >> 8) + 16));
        U = (U32) ((U8) (((-38 * R - 74 * G + 112 * B + 128) >> 8) + 128));
        V = (U32) ((U8) (((112 * R - 94 * G - 18 * B + 128) >> 8) + 128));

        (*p_overlay_palette) = (V) | (U << 8) | (Y << 16);
        p_overlay_palette++;
        p_gdi_palette++;
    }

    *palette_size = time_stamp_p->overlay_frame_palette_size;
    *palette_address = &time_stamp_p->overlay_palette[0];
    *overlay_width = layer_width;
    *overlay_height = layer_height;

    gdi_layer_pop_and_restore_active();

}
#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_facedetect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_init_facedetect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->facedetect.is_tracking = MMI_FALSE;
    /* focused green */
    mmi_camco_osd_p->facedetect.focused_color = gdi_act_color_from_rgb(255, 0, 255, 0);
    mmi_camco_osd_p->facedetect.focused_border_color = gdi_act_color_from_rgb(255, 0, 0, 0);

    /* tracking white */
    mmi_camco_osd_p->facedetect.tracking_color = gdi_act_color_from_rgb(255, 240, 228, 15);
    mmi_camco_osd_p->facedetect.tracking_border_color = gdi_act_color_from_rgb(255, 240, 228, 15);

    /* 255 = no opacity, 0 = full opacity */
    mmi_camco_osd_p->facedetect.opacity = 200;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_clear_facedetect_region
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_clear_facedetect_region(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mmi_camco_osd_p->facedetect.tracking_region, 0, sizeof(mmi_camco_osd_p->facedetect.tracking_region));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_facedetect_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_enable       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_facedetect_enable(MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->facedetect.is_tracking = is_enable;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_facedetect_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     
 * RETURNS
 *  BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_camco_osd_get_facedetect_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->facedetect.is_tracking;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_facedetect_region
 * DESCRIPTION
 *  
 * PARAMETERS
 *  facedetect_region       [IN]        
 *  type                    [IN]        
 *  center_x                [IN]        
 *  center_y                [IN]        
 *  width                   [IN]        
 *  height                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_facedetect_region(
        U16 facedetect_region,
        mmi_camco_osd_facedetect_type_enum type,
        S32 center_x,
        S32 center_y,
        S32 width,
        S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(facedetect_region < MMI_CAMCO_SUPPORT_FACE_NUM);

    mmi_camco_osd_p->facedetect.tracking_region[facedetect_region].type = type;
    mmi_camco_osd_p->facedetect.tracking_region[facedetect_region].x1 = center_x - (width >> 1);
    mmi_camco_osd_p->facedetect.tracking_region[facedetect_region].x2 = center_x + (width >> 1);
    mmi_camco_osd_p->facedetect.tracking_region[facedetect_region].y1 = center_y - (height >> 1);
    mmi_camco_osd_p->facedetect.tracking_region[facedetect_region].y2 = center_y + (height >> 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_facedetect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_facedetect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    gdi_color rect_color = gdi_act_color_from_rgb(255, 255, 255, 255);
    gdi_color border_color = gdi_act_color_from_rgb(255, 255, 255, 255);
    S32 region_width = 0;
    S32 edge_pixel = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CAMCO_SUPPORT_FACE_NUM; i++)
    {
        if (mmi_camco_osd_p->facedetect.tracking_region[i].type != MMI_CAMCO_OSD_FACEDETECT_TYPE_NULL)
        {
            if (mmi_camco_osd_p->facedetect.tracking_region[i].type == MMI_CAMCO_OSD_FACEDETECT_TYPE_FOCUSED)
            {
                rect_color = mmi_camco_osd_p->facedetect.focused_color;
                border_color = mmi_camco_osd_p->facedetect.focused_border_color;
            }
            else if (mmi_camco_osd_p->facedetect.tracking_region[i].type == MMI_CAMCO_OSD_FACEDETECT_TYPE_TRACKING)
            {
                rect_color = mmi_camco_osd_p->facedetect.tracking_color;
                border_color = mmi_camco_osd_p->facedetect.tracking_border_color;

            }
            else
            {
                MMI_ASSERT(0);
            }
        #ifdef __SMILE_SHUTTER_SUPPORT__
            if (!mmi_camco_osd_p->smiledetect.is_zoom_ev_enable)
            {
                if (i == 0)
                {
                    rect_color = mmi_camco_osd_p->facedetect.focused_color;
                    border_color = mmi_camco_osd_p->facedetect.focused_color;
                }
            }
        #endif /* __SMILE_SHUTTER_SUPPORT__ */ 

            region_width =
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - mmi_camco_osd_p->facedetect.tracking_region[i].x1;
            edge_pixel = (MMI_CAMCO_OSD_FACE_EDGE_RATIO * region_width) / 100;

            /* top-left */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 - 1 + edge_pixel + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 - 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + edge_pixel,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + 1 + edge_pixel - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 - 1 + edge_pixel + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + edge_pixel,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + 1 + edge_pixel - 1,
                border_color);

            /* top-right */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 - 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - edge_pixel,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 - 1 + (edge_pixel + 1),
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + edge_pixel,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + 1 + (edge_pixel - 1),
                border_color);

            /* bottom-left */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 - 1 + edge_pixel + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + edge_pixel,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + 1 + edge_pixel - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - edge_pixel,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - 1,
                border_color);

            /* bottom-right */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - edge_pixel,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - edge_pixel,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - 1,
                border_color);
        }
    }

}

#ifdef __SMILE_SHUTTER_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_smiledetect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_init_smiledetect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->smiledetect.is_tracking = MMI_FALSE;
    /* focused green */
    mmi_camco_osd_p->smiledetect.focused_color = gdi_act_color_from_rgb(255, 255, 128, 0);
    mmi_camco_osd_p->smiledetect.focused_border_color = gdi_act_color_from_rgb(255, 0, 0, 0);

    /* tracking white */
    mmi_camco_osd_p->smiledetect.tracking_color = gdi_act_color_from_rgb(255, 255, 128, 15);
    mmi_camco_osd_p->smiledetect.tracking_border_color = gdi_act_color_from_rgb(255, 240, 128, 15);

    /* 255 = no opacity, 0 = full opacity */
    mmi_camco_osd_p->smiledetect.opacity = 200;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_smileshot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_smileshot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;
    S32 image_region_offset_x;
    S32 image_region_offset_y;
    S32 image_region_width;
    S32 image_region_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_get_preview_region(
        &image_region_offset_x,
        &image_region_offset_y,
        &image_region_width,
        &image_region_height);

    gdi_image_get_dimension_id(IMG_ID_CAMCO_CAPMODE_SMILE_SHOT_DET, &width, &height);
    gdi_image_draw_id(
        image_region_offset_x + (mmi_camco_osd_p->osd_width -image_region_offset_x - width) >> 1,
        image_region_offset_y,
        IMG_ID_CAMCO_CAPMODE_SMILE_SHOT_DET);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_smiledetect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_smiledetect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    gdi_color rect_color = gdi_act_color_from_rgb(255, 255, 255, 255);
    gdi_color border_color = gdi_act_color_from_rgb(255, 255, 255, 255);
    S32 region_width = 0;
    S32 edge_pixel = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CAMCO_SUPPORT_FACE_NUM; i++)
    {
        if (mmi_camco_osd_p->smiledetect.tracking_region[i].type != MMI_CAMCO_OSD_FACEDETECT_TYPE_NULL)
        {
            if (mmi_camco_osd_p->smiledetect.tracking_region[i].type == MMI_CAMCO_OSD_FACEDETECT_TYPE_FOCUSED)
            {
                rect_color = mmi_camco_osd_p->smiledetect.focused_color;
                border_color = mmi_camco_osd_p->smiledetect.focused_border_color;
            }
            else if (mmi_camco_osd_p->smiledetect.tracking_region[i].type == MMI_CAMCO_OSD_FACEDETECT_TYPE_TRACKING)
            {
                rect_color = mmi_camco_osd_p->smiledetect.tracking_color;
                border_color = mmi_camco_osd_p->smiledetect.tracking_border_color;

            }
            else
            {
                MMI_ASSERT(0);
            }

            region_width =
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - mmi_camco_osd_p->smiledetect.tracking_region[i].x1;
            edge_pixel = (MMI_CAMCO_OSD_FACE_EDGE_RATIO * region_width) / 100;

            /* top-left */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 - 1 + edge_pixel + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 - 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + edge_pixel,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + 1 + edge_pixel - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 - 1 + edge_pixel + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + edge_pixel,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + 1 + edge_pixel - 1,
                border_color);

            /* top-right */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 - 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - edge_pixel,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 - 1 + (edge_pixel + 1),
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + edge_pixel,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + 1 + (edge_pixel - 1),
                border_color);

            /* bottom-left */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 - 1 + edge_pixel + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + edge_pixel,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + 1 + edge_pixel - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - edge_pixel,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - 1,
                border_color);

            /* bottom-right */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - edge_pixel,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - edge_pixel,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - 1,
                border_color);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_clear_smiledetect_region
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_clear_smiledetect_region(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mmi_camco_osd_p->smiledetect.tracking_region, 0, sizeof(mmi_camco_osd_p->smiledetect.tracking_region));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_smiledetect_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_enable       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_smiledetect_enable(MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->smiledetect.is_tracking = is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_zoom_ev_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_enable       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_zoom_ev_enable(MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->smiledetect.is_zoom_ev_enable = is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_smiledetect_region
 * DESCRIPTION
 *  
 * PARAMETERS
 *  smiledetect_region      [IN]        
 *  type                    [IN]        
 *  center_x                [IN]        
 *  center_y                [IN]        
 *  width                   [IN]        
 *  height                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_smiledetect_region(
        U16 smiledetect_region,
        mmi_camco_osd_facedetect_type_enum type,
        S32 center_x,
        S32 center_y,
        S32 width,
        S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(smiledetect_region < MMI_CAMCO_SUPPORT_FACE_NUM);

    mmi_camco_osd_p->smiledetect.tracking_region[smiledetect_region].type = type;
    mmi_camco_osd_p->smiledetect.tracking_region[smiledetect_region].x1 = center_x - (width >> 1);
    mmi_camco_osd_p->smiledetect.tracking_region[smiledetect_region].x2 = center_x + (width >> 1);
    mmi_camco_osd_p->smiledetect.tracking_region[smiledetect_region].y1 = center_y - (height >> 1);
    mmi_camco_osd_p->smiledetect.tracking_region[smiledetect_region].y2 = center_y + (height >> 1);

}

#endif /* __SMILE_SHUTTER_SUPPORT__ */ 

void mmi_camco_osd_set_qvi_color_format(U8 cf)
{

	mmi_camco_osd_p->qvi_color_format = cf;


}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_blt_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_blt_layer(mmi_camco_osd_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (state)
    {
        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        case MMI_CAMCO_OSD_STATE_FOCUSE:
        case MMI_CAMCO_OSD_STATE_FOCUSE_HINT:
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
		case MMI_CAMCO_OSD_STATE_MAV_SHOT:
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);
            break;

        case MMI_CAMCO_OSD_STATE_HIDE:
            gdi_layer_set_blt_layer(0, mmi_camco_osd_p->osd_layer_h, 0, 0);
            break;

        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            /* register key event */
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (state == MMI_CAMCO_OSD_STATE_VIDEO_PAUSE)
            {
                gdi_layer_set_blt_layer(
                    mmi_camco_osd_p->base_layer_h,
                    mmi_camco_osd_p->video_recoding_osd.osd_layer_ev_zoom_area_h,
                    mmi_camco_osd_p->video_recoding_osd.osd_layer_rec_time_area_h,
                    mmi_camco_osd_p->video_recoding_osd.osd_layer_softkey_area_h);
            }
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            break;
        }

    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            gdi_layer_set_blt_layer(
                mmi_camco_osd_p->base_layer_h,
                mmi_camco_osd_p->imageselect_cache_layer_h,
                mmi_camco_osd_p->osd_layer_h,
                0);
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_AUTORAMA__
        case MMI_CAMCO_OSD_STATE_AUTORAMA_DIRECTION:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);
            break;
        }

        case MMI_CAMCO_OSD_STATE_AUTORAMA_SHOT:
        {
            gdi_layer_set_blt_layer(
                mmi_camco_osd_p->base_layer_h,
                mmi_camco_osd_p->autorama_cache_layer_h,
                mmi_camco_osd_p->osd_layer_h,
                0);
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_AUTORAMA__ */ 

    #ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
        case MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_PREVIEW:
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
            gdi_layer_set_blt_layer(mmi_camco_osd_p->sublcd_base_layer_h, 0, 0, 0);
            break;

        case MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_STOP_HINT:
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
            gdi_layer_set_blt_layer(mmi_camco_osd_p->sublcd_base_layer_h, mmi_camco_osd_p->sublcd_osd_layer_h, 0, 0);

            break;
    #endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 

        case MMI_CAMCO_OSD_STATE_EXIT:
        {
            /* exit state */
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, 0, 0, 0);
            break;
        }

        default:
            MMI_ASSERT(0);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_enter_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_enter_state(mmi_camco_osd_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->osd_state = state;

    /* reset all variables */
    mmi_camco_osd_p->center_hint.str_ptr = NULL;
    mmi_camco_osd_p->center_hint.is_processing = MMI_FALSE;
    mmi_camco_osd_p->center_hint.dot_count = 0;

    mmi_camco_osd_p->corner_hint.str_ptr = NULL;

    mmi_camco_osd_p->lsk.str_id = 0;
    mmi_camco_osd_p->lsk.img_press_id = 0;
    mmi_camco_osd_p->lsk.img_id = 0;
    mmi_camco_osd_p->lsk.event_callback = NULL;

    mmi_camco_osd_p->rsk.str_id = 0;
    mmi_camco_osd_p->rsk.img_press_id = 0;
    mmi_camco_osd_p->rsk.img_id = 0;
    mmi_camco_osd_p->rsk.event_callback = NULL;

    mmi_camco_osd_p->csk.str_id = 0;
    mmi_camco_osd_p->csk.img_press_id = 0;
    mmi_camco_osd_p->csk.img_id = 0;
    mmi_camco_osd_p->csk.up_event_callback = NULL;
    mmi_camco_osd_p->csk.down_event_callback = NULL;

    mmi_camco_osd_p->focus_hint.img_id = 0;
    mmi_camco_osd_p->focus_hint.is_hint_show = MMI_FALSE;
    mmi_camco_osd_p->use_lsk_function_and_csk_icon = MMI_TRUE;

    /* reset key handlers */
    ClearKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RSK, KEY_EVENT_UP);
    ClearKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
    ClearKeyHandler(KEY_CSK, KEY_EVENT_DOWN);    
    ClearKeyHandler(KEY_CSK, KEY_EVENT_UP);        
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_camco_dummy_func, KEY_CSK, KEY_EVENT_REPEAT);

    /* State transition, stop zoom */
    mmi_camco_osd_stop_zoom();

    /* clear all touch usable flag */
    mmi_camco_osd_p->lsk.touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->rsk.touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->csk.touch.is_usable = MMI_FALSE;
#ifndef __MMI_ZOOM_SLIDER_BAR__
    mmi_camco_osd_p->zoom_in_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->zoom_out_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->zoom_in_touch.is_press = MMI_FALSE;
    mmi_camco_osd_p->zoom_out_touch.is_press = MMI_FALSE;
#else
    mmi_camco_osd_p->slider.slider_bar.is_usable = MMI_TRUE;
    mmi_camco_osd_p->slider.slider_location.is_usable = MMI_TRUE;
    mmi_camco_osd_p->slider.slider_location_region.is_usable = MMI_TRUE;
    mmi_camco_osd_p->slider.slider_region.is_usable = MMI_TRUE;
    mmi_camco_osd_p->slider.zoom_region.is_usable = MMI_TRUE;
    mmi_camco_osd_p->is_show_zoom_slider = MMI_FALSE;
#endif
    mmi_camco_osd_p->iconlist.la_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->iconlist.ra_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->iconlist.list_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->setting_menulist.list_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->setting_menulist.list_up_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->setting_menulist.list_down_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->option_menulist.list_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->option_menulist.list_up_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->option_menulist.list_down_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->add_frame.la_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->add_frame.ra_touch.is_usable = MMI_FALSE;

    mmi_camco_osd_p->scrollbar.slider_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->scrollbar.slider_up_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->scrollbar.slider_down_touch.is_usable = MMI_FALSE;

    if (mmi_camco_osd_p->imgselect_cache.cache_img_osd_touch != NULL)
    {
        U8 idx;
        mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

        for (idx = 0; idx < imgselect_cache_p->disp_cache_count; idx++)
        {
            imgselect_cache_p->cache_img_osd_touch[idx].is_usable = MMI_TRUE;
        }
    }
    mmi_camco_osd_p->imgselect_cache.is_cache_img_osd_redraw = MMI_TRUE;
    mmi_camco_osd_p->imgselect_cache.is_cache_highlight_osd_redraw = MMI_TRUE;
#ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
    mmi_camco_osd_imageselect_reset_environment();
#endif 
#ifdef __MMI_CAMCO_FEATURE_OSD_AUTORAMA__
    mmi_camco_osd_autorama_shot_reset_environment();
#endif 

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        mmi_camco_osd_recording_reset_environment();

    }
#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
    mmi_camco_osd_sublcd_stop_hint_reset_environment();
#endif 
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif 
    /* stop timer */
    gui_cancel_timer(mmi_camco_osd_draw_hint_process_cyclic);
    gui_cancel_timer(mmi_camco_osd_draw_focus_hint_process_cyclic);
    gui_cancel_timer(mmi_camco_osd_iconlist_prev_cyclic);
    gui_cancel_timer(mmi_camco_osd_iconlist_next_cyclic);
    gui_cancel_timer(mmi_camco_osd_menulist_prev_cyclic);
    gui_cancel_timer(mmi_camco_osd_menulist_next_cyclic);
    gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);
#ifndef __MMI_ZOOM_SLIDER_BAR__
    gui_cancel_timer(mmi_camco_osd_camera_zoom_in);
    gui_cancel_timer(mmi_camco_osd_camera_zoom_out);
    gui_cancel_timer(mmi_camco_osd_video_zoom_in);
    gui_cancel_timer(mmi_camco_osd_video_zoom_out);
    gui_cancel_timer(mmi_camco_start_fast_zoom_in);
    gui_cancel_timer(mmi_camco_start_fast_zoom_out);
#endif
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    gui_cancel_timer(mmi_camco_osd_add_frame_prev_cyclic);
    gui_cancel_timer(mmi_camco_osd_add_frame_next_cyclic);
#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
#ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
    gui_cancel_timer(mmi_camco_osd_imgselect_prev_cyclic);
    gui_cancel_timer(mmi_camco_osd_imgselect_next_cyclic);
#endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 
#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
    gui_cancel_timer(mmi_camco_sublcd_osd_draw_hint_process_cyclic);
#endif 
#ifdef __MMI_TOUCH_SCREEN__
    gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
    gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);
    gui_cancel_timer(mmi_camco_osd_touch_menulist_prev_cyclic);
    gui_cancel_timer(mmi_camco_osd_touch_menulist_next_cyclic);
#endif /* __MMI_TOUCH_SCREEN__ */ 
#ifdef __MMI_TOUCH_SCREEN__
    if(mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_HINT )
        mmi_pen_reset();
#endif        
    mmi_camco_osd_scrolling_text_stop();

    if (mmi_camco_osd_p->imgselect_cache.cache_img_osd_touch != NULL)
    {
        gui_free(mmi_camco_osd_p->imgselect_cache.cache_img_osd_touch);
        mmi_camco_osd_p->imgselect_cache.cache_img_osd_touch = NULL;
    }

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        
    #ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_STOP_HINT)
        {
            gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            gdi_layer_resize(SUBLCD_HEIGHT, SUBLCD_WIDTH);
            gdi_layer_pop_and_restore_active();
            mmi_camco_osd_p->is_horizontal = MMI_FALSE;
        }
        else
    #endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */             
        {
            if (mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_VIDEO_RECORDING &&
                mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_VIDEO_PAUSE)
            {
                if (mmi_camco_osd_p->is_horizontal)
                {
                    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                    gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
                    gdi_layer_pop_and_restore_active();
                    mmi_camco_osd_p->is_horizontal = MMI_FALSE;
                }
            }
        }
    }
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

    /* reset opacity */
    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
    gdi_layer_set_opacity(MMI_FALSE, 0);
    gdi_layer_pop_and_restore_active();

    switch (state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, 0, 0, 0);
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_csk_press_hdlr, KEY_CSK, KEY_EVENT_DOWN);    
            SetKeyHandler(mmi_camco_osd_csk_release_hdlr, KEY_CSK, KEY_EVENT_UP);   

            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            if (MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW == state)
            {
                mmi_camco_osd_gen_camera_status_icon();
            }
            else if (MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW == state)
            {
                mmi_camco_osd_gen_video_status_icon();
            }
            #ifdef __MMI_ZOOM_SLIDER_BAR__
                if (mmi_camco_setting_app_switch_is_enable())
                {
                   #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
                    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
                    {
                        SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                        SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                        SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                        SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                    }
                    #ifdef DUAL_CAMERA_SUPPORT
                    else
                    {
                        SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                        SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                        SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                        SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
                    }
                    #endif /* DUAL_CAMERA_SUPPORT */ 
                #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
              
                    SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                    SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);                
                #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
                 }
                 SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
                 SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
                 SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
                 SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
                 SetKeyHandler(mmi_camco_osd_csk_press_hdlr, KEY_CSK, KEY_EVENT_DOWN);    
                 SetKeyHandler(mmi_camco_osd_csk_release_hdlr, KEY_CSK, KEY_EVENT_UP);
            #else
        #ifdef __SMILE_SHUTTER_SUPPORT__
            if (mmi_camco_osd_p->smiledetect.is_zoom_ev_enable)
            {
        #endif /* __SMILE_SHUTTER_SUPPORT__ */ 

                /* register key event */
            #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
                if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
                {
                    SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                    SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
		            if (mmi_camco_setting_app_switch_is_enable())
		            {            	                    
                        SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                        SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                        SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                        SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                    }
                }
            #ifdef DUAL_CAMERA_SUPPORT
                else
                {
                    SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                    SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
		                if (mmi_camco_setting_app_switch_is_enable())
		                {                     
                        SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                        SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                        SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                        SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
                    }
                }
            #endif /* DUAL_CAMERA_SUPPORT */ 
            #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
                SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
		            if (mmi_camco_setting_app_switch_is_enable())
		            {                 
                    SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                    SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
                }                    
            #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            #ifdef __SMILE_SHUTTER_SUPPORT__
            }
            #endif 
            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_csk_press_hdlr, KEY_CSK, KEY_EVENT_DOWN);    
            SetKeyHandler(mmi_camco_osd_csk_release_hdlr, KEY_CSK, KEY_EVENT_UP);      
            #endif
        #ifdef __SMILE_SHUTTER_SUPPORT__
            if (!mmi_camco_osd_p->smiledetect.is_tracking)
            {
        #endif /* __SMILE_SHUTTER_SUPPORT__ */ 
            #ifndef __MMI_ZOOM_SLIDER_BAR__
                mmi_camco_osd_p->zoom_in_touch.is_usable = MMI_TRUE;
                mmi_camco_osd_p->zoom_out_touch.is_usable = MMI_TRUE;
            #else
            if (MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW == state)
            {            
                mmi_camco_setting_get_camzoom_info(
                    &mmi_camco_osd_p->slider.max_value,
                    &mmi_camco_osd_p->slider.min_value,
                    &mmi_camco_osd_p->slider.one_step_value,
                    &mmi_camco_osd_p->slider.step_count);
            }
            else if(MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW == state)
            {
                mmi_camco_setting_get_vdozoom_info(
                    &mmi_camco_osd_p->slider.max_value,
                    &mmi_camco_osd_p->slider.min_value,
                    &mmi_camco_osd_p->slider.one_step_value,
                    &mmi_camco_osd_p->slider.step_count);
            }
            #endif

            #ifdef __SMILE_SHUTTER_SUPPORT__
            }
            #endif 
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            mmi_camco_osd_p->option_menulist.list_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->option_menulist.list_up_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->option_menulist.list_down_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->scrollbar.slider_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->scrollbar.slider_up_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->scrollbar.slider_down_touch.is_usable = MMI_TRUE;
            
            if (MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW == state)
            {
                mmi_camco_osd_p->is_camera_storage_selection = MMI_TRUE;
            }
            else if (MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW == state)
            {
                mmi_camco_osd_p->is_camera_storage_selection = MMI_FALSE;
            }
            mmi_camco_osd_gen_option_menulist();


            /* register key event */
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_csk_press_hdlr, KEY_CSK, KEY_EVENT_DOWN);    
            SetKeyHandler(mmi_camco_osd_csk_release_hdlr, KEY_CSK, KEY_EVENT_UP);      

            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            if (MMI_CAMCO_OSD_STATE_CAMERA_SETTING == state)
            {
                mmi_camco_osd_gen_camera_status_icon();
            }
            else if (MMI_CAMCO_OSD_STATE_VIDEO_SETTING == state)
            {
                mmi_camco_osd_gen_video_status_icon();
            }

            /* setting */
            mmi_camco_setting_gen_mainlist(mmi_camco_setting_get_mainlist_type());
            
            if(mmi_camco_osd_p->iconlist.highlighted_idx > mmi_camco_setting_get_mainlist_count() - 1 )
                mmi_camco_osd_p->iconlist.highlighted_idx = 0;

            mmi_camco_setting_set_mainlist_idx(mmi_camco_osd_p->iconlist.highlighted_idx);

                if(mmi_camco_setting_get_mainlist_idx() == 0 && mmi_camco_setting_get_mainlist_type() == MMI_CAMCO_SETTING_MAINLIST_PRIMARY)
                {
                    mmi_camco_osd_p->is_ev_setting = MMI_TRUE;
                }
                else
                {
                    mmi_camco_osd_p->is_ev_setting = MMI_FALSE;
                }

            /* gen ui */
            mmi_camco_osd_gen_iconlist();
            mmi_camco_osd_gen_setting_menulist();

            mmi_camco_osd_p->iconlist.ra_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->iconlist.la_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->iconlist.list_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->setting_menulist.list_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->setting_menulist.list_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->setting_menulist.list_up_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->setting_menulist.list_down_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->scrollbar.slider_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->scrollbar.slider_up_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->scrollbar.slider_down_touch.is_usable = MMI_TRUE;
            /* register key event */
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);

                SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);

                SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);

            SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_csk_press_hdlr, KEY_CSK, KEY_EVENT_DOWN);    
            SetKeyHandler(mmi_camco_osd_csk_release_hdlr, KEY_CSK, KEY_EVENT_UP);               
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);
            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_csk_press_hdlr, KEY_CSK, KEY_EVENT_DOWN);    
            SetKeyHandler(mmi_camco_osd_csk_release_hdlr, KEY_CSK, KEY_EVENT_UP);   

            break;
        }

        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            /* register key event */
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                mmi_camco_osd_recording_setup_environment();

                if (state == MMI_CAMCO_OSD_STATE_VIDEO_PAUSE)
                {
                    gdi_layer_set_blt_layer(
                        mmi_camco_osd_p->base_layer_h,
                        mmi_camco_osd_p->video_recoding_osd.osd_layer_ev_zoom_area_h,
                        mmi_camco_osd_p->video_recoding_osd.osd_layer_rec_time_area_h,
                        mmi_camco_osd_p->video_recoding_osd.osd_layer_softkey_area_h);
                }

                SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

                SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            }
        #endif /* DUAL_CAMERA_SUPPORT */ /* #ifdef DUAL_CAMERA_SUPPORT */
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_csk_press_hdlr, KEY_CSK, KEY_EVENT_DOWN);    
            SetKeyHandler(mmi_camco_osd_csk_release_hdlr, KEY_CSK, KEY_EVENT_UP);      
        #ifndef __MMI_ZOOM_SLIDER_BAR__
            mmi_camco_osd_p->zoom_in_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->zoom_out_touch.is_usable = MMI_TRUE;
        #else
        if((mmi_camco_osd_p->slider.max_value - mmi_camco_osd_p->slider.min_value) > 1)
        {
            mmi_camco_osd_p->is_show_zoom_slider = MMI_TRUE;
        }
        #endif
            break;
        }

    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_csk_press_hdlr, KEY_CSK, KEY_EVENT_DOWN);    
            SetKeyHandler(mmi_camco_osd_csk_release_hdlr, KEY_CSK, KEY_EVENT_UP);

            mmi_camco_osd_p->add_frame.la_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->add_frame.ra_touch.is_usable = MMI_TRUE;
            break;
        }

        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SAVING:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            break;

        }
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            mmi_camco_osd_imageselect_setup_environment();

            gdi_layer_set_blt_layer(
                mmi_camco_osd_p->base_layer_h,
                mmi_camco_osd_p->imageselect_cache_layer_h,
                mmi_camco_osd_p->osd_layer_h,
                0);

            /* register key event */
            if (mmi_camco_osd_p->imgselect_cache.is_horizontal_display == MMI_TRUE)
            {
            #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
                if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
                {
                    SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                    SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
                }
            #ifdef DUAL_CAMERA_SUPPORT
                else
                {
                    SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                    SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                }
            #endif /* DUAL_CAMERA_SUPPORT */ 
            #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
                SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            }
            else
            {
            #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
                if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
                {
                    SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                    SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                }
            #ifdef DUAL_CAMERA_SUPPORT
                else
                {
                    SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                    SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
                }
            #endif /* DUAL_CAMERA_SUPPORT */ 
            #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
                SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            }

            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_csk_press_hdlr, KEY_CSK, KEY_EVENT_DOWN);    
            SetKeyHandler(mmi_camco_osd_csk_release_hdlr, KEY_CSK, KEY_EVENT_UP);

            mmi_camco_osd_gen_image_select();

            if (mmi_camco_osd_p->imgselect_cache.cache_img_osd_touch != NULL)
            {
                U8 idx;
                mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

                for (idx = 0; idx < imgselect_cache_p->disp_cache_count; idx++)
                {
                    imgselect_cache_p->cache_img_osd_touch[idx].is_usable = MMI_TRUE;
                }
            }
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_AUTORAMA__
        case MMI_CAMCO_OSD_STATE_AUTORAMA_DIRECTION:
        {
            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);
            break;
        }

        case MMI_CAMCO_OSD_STATE_AUTORAMA_SHOT:
        {
            mmi_camco_osd_autorama_shot_setup_environment();
			// enter from MMI_CAMCO_OSD_STATE_AUTORAMA_DIRECTION to MMI_CAMCO_OSD_STATE_AUTORAMA_SHOT
			//when preview is on going ,if set blt , ROI region will only be video layer,and the region outside video layer will not be blt until cal gdi_blt,
			// So blt and set blt at the same time
            /*gdi_layer_set_blt_layer(
                mmi_camco_osd_p->base_layer_h,
                mmi_camco_osd_p->autorama_cache_layer_h,
                mmi_camco_osd_p->osd_layer_h,
                0);*/

            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_AUTORAMA__ */ 

	#ifdef __MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__
		case MMI_CAMCO_OSD_STATE_MAV_SHOT:
		{
            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
			gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);
            break;
		}

	#endif
        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            /* clear focus data */
            memset(mmi_camco_osd_p->focus_region, 0, sizeof(mmi_camco_osd_p->focus_region));

            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            /* set opacity */
            gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            gdi_layer_set_opacity(TRUE, mmi_camco_osd_p->focus_opacity);
            gdi_layer_pop_and_restore_active();

            break;
        }
        case MMI_CAMCO_OSD_STATE_FOCUSE_HINT:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_csk_press_hdlr, KEY_CSK, KEY_EVENT_DOWN);    
            SetKeyHandler(mmi_camco_osd_csk_release_hdlr, KEY_CSK, KEY_EVENT_UP);  
            break;
        }
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            mmi_camco_osd_gen_option_menulist();

            mmi_camco_osd_p->option_menulist.list_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->option_menulist.list_up_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->option_menulist.list_down_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->scrollbar.slider_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->scrollbar.slider_up_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->scrollbar.slider_down_touch.is_usable = MMI_TRUE;
            /* register key event */
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_csk_press_hdlr, KEY_CSK, KEY_EVENT_DOWN);    
            SetKeyHandler(mmi_camco_osd_csk_release_hdlr, KEY_CSK, KEY_EVENT_UP);              
            break;



    #ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
        case MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_PREVIEW:
            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);

            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
            gdi_layer_set_blt_layer(mmi_camco_osd_p->sublcd_base_layer_h, 0, 0, 0);
            break;

        case MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_STOP_HINT:
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF    
            mmi_camco_osd_sublcd_stop_hint_set_environment();
        #endif
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
            gdi_layer_set_blt_layer(mmi_camco_osd_p->sublcd_base_layer_h, mmi_camco_osd_p->sublcd_osd_layer_h, 0, 0);

            break;
    #endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 
        case MMI_CAMCO_OSD_STATE_EXIT:
        {
            /* exit state */
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, 0, 0, 0);
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_osd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_draw_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    S32 width = 0;
    S32 height = 0;
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__			
            gdi_layer_toggle_double();
            #endif
            mmi_camco_osd_blt();
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        {
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_softkey();
                mmi_camco_osd_draw_hint();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	                
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                /* Subcamera - Portrait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	                                
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();

                mmi_camco_osd_draw_softkey();
                mmi_camco_osd_draw_hint();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	         
            gdi_layer_toggle_double();
            #endif
            gdi_layer_lock_frame_buffer();

            mmi_camco_osd_clear_bg();

            mmi_camco_osd_draw_softkey();
            mmi_camco_osd_draw_hint();

            gdi_layer_unlock_frame_buffer();
            gdi_layer_pop_and_restore_active();

            mmi_camco_osd_blt();
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            break;
        }

        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        {
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_softkey();
                mmi_camco_osd_draw_hint();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	                  
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                /* Subcamera - Portrait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	                  
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_softkey();
                mmi_camco_osd_draw_hint();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
            gdi_layer_toggle_double();
            #endif
            gdi_layer_lock_frame_buffer();

            mmi_camco_osd_clear_bg();
            mmi_camco_osd_draw_softkey();
            mmi_camco_osd_draw_hint();

            gdi_layer_unlock_frame_buffer();
            gdi_layer_pop_and_restore_active();

            mmi_camco_osd_blt();
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();

                if (mmi_camco_osd_p->facedetect.is_tracking)
                {
                    mmi_camco_osd_draw_facedetect();
                }

            #ifdef __SMILE_SHUTTER_SUPPORT__
                if (mmi_camco_osd_p->smiledetect.is_tracking)
                {
                    mmi_camco_osd_draw_smiledetect();
                }
                if (!mmi_camco_osd_p->smiledetect.is_zoom_ev_enable)
                {
                    mmi_camco_osd_draw_smileshot();
                }
            #endif /* __SMILE_SHUTTER_SUPPORT__ */ 

            #ifdef __SMILE_SHUTTER_SUPPORT__
                if (mmi_camco_osd_p->smiledetect.is_zoom_ev_enable)
                {
            #endif /* __SMILE_SHUTTER_SUPPORT__ */ 
                    mmi_camco_osd_draw_status_icon();


					mmi_camco_osd_draw_zoom();

            #ifdef __SMILE_SHUTTER_SUPPORT__
                }
            #endif 
                if (mmi_camco_setting_get_setting_capability(MMI_CAMCO_SETTING_FLASH) == MMI_CAMCO_SETTING_CAP_ENABLED
                    && mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_FLASH) != MMI_CAMCO_FLASH_OFF &&
                    mmi_camco_get_flash_type() == MMI_CAMCO_FLASH_TYPE_XENON)
                {
                    mmi_camco_osd_draw_xenon_flash();
                }
                #ifdef __MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__
				if((mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_MAV)||
					(mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_3D_IMAGE))
				{
				    mmi_camco_osd_draw_preview_center();
				}
				#endif
                mmi_camco_osd_draw_softkey();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                /* Subcamera - Portrait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();

                if (mmi_camco_osd_p->facedetect.is_tracking)
                {
                    mmi_camco_osd_draw_facedetect();
                }
            #ifdef __SMILE_SHUTTER_SUPPORT__
                if (mmi_camco_osd_p->smiledetect.is_tracking)
                {
                    mmi_camco_osd_draw_smiledetect();
                }
                if (!mmi_camco_osd_p->smiledetect.is_zoom_ev_enable)
                {
                    mmi_camco_osd_draw_smileshot();
                }
            #endif /* __SMILE_SHUTTER_SUPPORT__ */ 

            #ifdef __SMILE_SHUTTER_SUPPORT__
                if (mmi_camco_osd_p->smiledetect.is_zoom_ev_enable)
                {
            #endif /* __SMILE_SHUTTER_SUPPORT__ */ 
                    mmi_camco_osd_draw_status_icon();

					mmi_camco_osd_draw_zoom();

                #ifdef __SMILE_SHUTTER_SUPPORT__
                }
                #endif 

                if (mmi_camco_setting_get_setting_capability(MMI_CAMCO_SETTING_FLASH) == MMI_CAMCO_SETTING_CAP_ENABLED
                    && mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_FLASH) != MMI_CAMCO_FLASH_OFF &&
                    mmi_camco_get_flash_type() == MMI_CAMCO_FLASH_TYPE_XENON)
                {
                    mmi_camco_osd_draw_xenon_flash();
                }
	    #ifdef __MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__
				if((mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_MAV)||
					(mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_3D_IMAGE))
				{
				    mmi_camco_osd_draw_preview_center();
				}
	    #endif

                mmi_camco_osd_draw_softkey();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
            gdi_layer_toggle_double();
            #endif
            gdi_layer_lock_frame_buffer();

            mmi_camco_osd_clear_bg();

            if (mmi_camco_osd_p->facedetect.is_tracking)
            {
                mmi_camco_osd_draw_facedetect();
            }
        #ifdef __SMILE_SHUTTER_SUPPORT__
            if (mmi_camco_osd_p->smiledetect.is_tracking)
            {
                mmi_camco_osd_draw_smiledetect();
            }
            if (!mmi_camco_osd_p->smiledetect.is_zoom_ev_enable)
            {
                mmi_camco_osd_draw_smileshot();
            }
        #endif /* __SMILE_SHUTTER_SUPPORT__ */ 

        #ifdef __SMILE_SHUTTER_SUPPORT__
            if (mmi_camco_osd_p->smiledetect.is_zoom_ev_enable)
            {
        #endif /* __SMILE_SHUTTER_SUPPORT__ */ 
                mmi_camco_osd_draw_status_icon();

				mmi_camco_osd_draw_zoom();

            #ifdef __SMILE_SHUTTER_SUPPORT__
            }
            #endif 

            if (mmi_camco_setting_get_setting_capability(MMI_CAMCO_SETTING_FLASH) == MMI_CAMCO_SETTING_CAP_ENABLED &&
                mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_FLASH) != MMI_CAMCO_FLASH_OFF &&
                mmi_camco_get_flash_type() == MMI_CAMCO_FLASH_TYPE_XENON)
            {
                mmi_camco_osd_draw_xenon_flash();
            }

	    #ifdef __MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__
			if((mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_MAV)||
					(mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_3D_IMAGE))
			{
				mmi_camco_osd_draw_preview_center();
			}
	    #endif

            mmi_camco_osd_draw_softkey();

            gdi_layer_unlock_frame_buffer();
            gdi_layer_pop_and_restore_active();

            mmi_camco_osd_blt();
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            break;
        }

        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_status_icon();

				mmi_camco_osd_draw_zoom();

                mmi_camco_osd_draw_softkey();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                /* Subcamera - Portait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_status_icon();
				mmi_camco_osd_draw_zoom();

                mmi_camco_osd_draw_softkey();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
            gdi_layer_toggle_double();
            #endif
            gdi_layer_lock_frame_buffer();

            mmi_camco_osd_clear_bg();
            mmi_camco_osd_draw_status_icon();

			mmi_camco_osd_draw_zoom();

            mmi_camco_osd_draw_softkey();

            gdi_layer_unlock_frame_buffer();
            gdi_layer_pop_and_restore_active();

            mmi_camco_osd_blt();
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:
        {
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_storage_selection();                
                mmi_camco_osd_draw_softkey();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__     
                gdi_layer_toggle_double();
            #endif 
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                /* Subcamera - Portait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__     
                gdi_layer_toggle_double();
            #endif 
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_storage_selection();   
                mmi_camco_osd_draw_softkey();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
        #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__     
            gdi_layer_toggle_double();
        #endif 
            gdi_layer_lock_frame_buffer();

            mmi_camco_osd_clear_bg();
            mmi_camco_osd_draw_storage_selection();   
            mmi_camco_osd_draw_softkey();

            gdi_layer_unlock_frame_buffer();
            gdi_layer_pop_and_restore_active();

            mmi_camco_osd_blt();
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            break;            
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                /* Horizontal */
                mmi_camco_osd_vdo_recording_osd_struct *video_recoding_osd_p = &mmi_camco_osd_p->video_recoding_osd;

                /* EV and Zoom */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
                width = video_recoding_osd_p->rotate_ev_zoom_area.x2 - video_recoding_osd_p->rotate_ev_zoom_area.x1 + 1;
                height =
                    video_recoding_osd_p->rotate_ev_zoom_area.y2 - video_recoding_osd_p->rotate_ev_zoom_area.y1 + 1;

                gdi_layer_resize(width, height);
                mmi_camco_osd_clear_bg();
                #ifdef __MMI_ZOOM_SLIDER_BAR__
                mmi_camco_osd_draw_zoom();
				#else
                mmi_camco_osd_draw_reduced_video_zoom();
                #endif
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(video_recoding_osd_p->osd_layer_ev_zoom_area_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(
                    mmi_camco_osd_p->osd_layer_draw_h,
                    video_recoding_osd_p->osd_layer_ev_zoom_area_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                /* Softkey */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
                mmi_camco_osd_clear_bg();
                width = video_recoding_osd_p->rotate_softkey_area.x2 - video_recoding_osd_p->rotate_softkey_area.x1 + 1;
                height =
                    video_recoding_osd_p->rotate_softkey_area.y2 - video_recoding_osd_p->rotate_softkey_area.y1 + 1;

                gdi_layer_resize(width, height);
                mmi_camco_osd_draw_reduced_recoding_softkey();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(video_recoding_osd_p->osd_layer_softkey_area_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(
                    mmi_camco_osd_p->osd_layer_draw_h,
                    video_recoding_osd_p->osd_layer_softkey_area_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                /* Record time */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
                width =
                    video_recoding_osd_p->rotate_rec_time_area.x2 - video_recoding_osd_p->rotate_rec_time_area.x1 + 1;
                height =
                    video_recoding_osd_p->rotate_rec_time_area.y2 - video_recoding_osd_p->rotate_rec_time_area.y1 + 1;

                gdi_layer_resize(width, height);
                mmi_camco_osd_clear_bg();
              if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_TIMELAPS) == MMI_CAMCO_TIMELAPS_ON)
              {
				  mmi_camco_osd_draw_reduced_record_frame(mmi_camco_get_record_frame());

			  }
			  else	
              {
			    mmi_camco_osd_draw_reduced_record_time(mmi_camco_get_record_time());

            #ifdef __MMI_OP02_LEMEI__    
                if (mmi_camco_setting_app_switch_is_enable())
                {
                    if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) > MMI_CAMCO_LIMIT_NO_LIMIT)
                    {
                        mmi_camco_osd_draw_reduced_progress(mmi_camco_get_record_progress_ratio());
                    }            
                }
            #else
                if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) > MMI_CAMCO_LIMIT_NO_LIMIT)
                {
                    mmi_camco_osd_draw_reduced_progress(mmi_camco_get_record_progress_ratio());
                }
            #endif
              	}
            
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(video_recoding_osd_p->osd_layer_rec_time_area_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(
                    mmi_camco_osd_p->osd_layer_draw_h,
                    video_recoding_osd_p->osd_layer_rec_time_area_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                if (mmi_camco_osd_p->is_blt)
                {
                    mmi_camco_osd_blt();
                }
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                /* Subcamera - Portait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();

				mmi_camco_osd_draw_zoom();

                mmi_camco_osd_draw_softkey();

			 if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_TIMELAPS) == MMI_CAMCO_TIMELAPS_ON)
              {
				  mmi_camco_osd_draw_record_frame(mmi_camco_get_record_frame());

			  }
			  else	
              {
                mmi_camco_osd_draw_record_time(mmi_camco_get_record_time());

            #ifdef __MMI_OP02_LEMEI__    
                if (mmi_camco_setting_app_switch_is_enable())
                {
                    if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) > MMI_CAMCO_LIMIT_NO_LIMIT)
                    {
                        mmi_camco_osd_draw_progress(mmi_camco_get_record_progress_ratio());
                    }            
                }
            #else
                if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) > MMI_CAMCO_LIMIT_NO_LIMIT)
                {
                    mmi_camco_osd_draw_progress(mmi_camco_get_record_progress_ratio());
                }
            #endif
			  	}

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
            gdi_layer_toggle_double();
            #endif
            gdi_layer_lock_frame_buffer();

            mmi_camco_osd_clear_bg();
			mmi_camco_osd_draw_zoom();

            mmi_camco_osd_draw_softkey();
		    if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_TIMELAPS) == MMI_CAMCO_TIMELAPS_ON)
             {
				  mmi_camco_osd_draw_record_frame(mmi_camco_get_record_frame());

			 }
		    else	
            {
               mmi_camco_osd_draw_record_time(mmi_camco_get_record_time());

        #ifdef __MMI_OP02_LEMEI__    
            if (mmi_camco_setting_app_switch_is_enable())
            {
                if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) > MMI_CAMCO_LIMIT_NO_LIMIT)
                {
                    mmi_camco_osd_draw_progress(mmi_camco_get_record_progress_ratio());
                }            
            }
        #else
            if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) > MMI_CAMCO_LIMIT_NO_LIMIT)
            {
                mmi_camco_osd_draw_progress(mmi_camco_get_record_progress_ratio());
            }
        #endif
		    }
            gdi_layer_unlock_frame_buffer();
            gdi_layer_pop_and_restore_active();

            mmi_camco_osd_blt();
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
				/*setting bar overlay on the status icon, it will cover the icon*/
                //mmi_camco_osd_draw_status_icon();
                mmi_camco_osd_draw_menulist();
                mmi_camco_osd_draw_iconlist();
                mmi_camco_osd_draw_softkey();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                /* Subcamera - Portrait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
				/*setting bar overlay on the status icon, it will cover the icon*/
                //mmi_camco_osd_draw_status_icon();
                mmi_camco_osd_draw_menulist();
                mmi_camco_osd_draw_iconlist();
                mmi_camco_osd_draw_softkey();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
            gdi_layer_toggle_double();
            #endif
            gdi_layer_lock_frame_buffer();

            mmi_camco_osd_clear_bg();
			/*setting bar overlay on the status icon, it will cover the icon*/
            //mmi_camco_osd_draw_status_icon();
            mmi_camco_osd_draw_menulist();
            mmi_camco_osd_draw_iconlist();
            mmi_camco_osd_draw_softkey();

            gdi_layer_unlock_frame_buffer();
            gdi_layer_pop_and_restore_active();

            mmi_camco_osd_blt();
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            break;
        }

    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_add_frame_color_idx();
                mmi_camco_osd_draw_add_frame_file_index();
                mmi_camco_osd_draw_softkey();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                /* Subcamera - Portrait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_add_frame_color_idx();
                mmi_camco_osd_draw_add_frame_file_index();
                mmi_camco_osd_draw_softkey();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
            gdi_layer_toggle_double();
            #endif
            gdi_layer_lock_frame_buffer();

            mmi_camco_osd_clear_bg();
            mmi_camco_osd_draw_add_frame_color_idx();
            mmi_camco_osd_draw_add_frame_file_index();
            mmi_camco_osd_draw_softkey();

            gdi_layer_unlock_frame_buffer();
            gdi_layer_pop_and_restore_active();

            mmi_camco_osd_blt();
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            break;
        }

        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SAVING:
        {
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                if (mmi_camco_osd_p->add_frame.is_picked)
                {
                    mmi_camco_osd_draw_add_frame_color_idx();
                }
                mmi_camco_osd_draw_softkey();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                /* Portrait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
                if (mmi_camco_osd_p->add_frame.is_picked)
                {
                    mmi_camco_osd_draw_add_frame_color_idx();
                }
                mmi_camco_osd_draw_softkey();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
            gdi_layer_toggle_double();
            #endif
            gdi_layer_lock_frame_buffer();

            mmi_camco_osd_clear_bg();
            if (mmi_camco_osd_p->add_frame.is_picked)
            {
                mmi_camco_osd_draw_add_frame_color_idx();
            }
            mmi_camco_osd_draw_softkey();

            gdi_layer_unlock_frame_buffer();
            gdi_layer_pop_and_restore_active();

            mmi_camco_osd_blt();
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                S32 width, height;

                /*===============================================================*/
                /* draw osd */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_softkey();
                mmi_camco_osd_draw_image_select_osd();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);

                gdi_layer_toggle_double();
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                /* draw cache layer */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
                gdi_layer_get_dimension(&width, &height);
                gdi_layer_resize(
                    mmi_camco_osd_p->imgselect_cache.cache_layer_height,
                    mmi_camco_osd_p->imgselect_cache.cache_layer_width);
                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_image_select_cache(mmi_camco_osd_p->osd_layer_draw_buf_p);
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->imageselect_cache_layer_h);
                gdi_layer_lock_frame_buffer();
                mmi_camco_osd_rotate_for_hw_rotate(
                    mmi_camco_osd_p->osd_layer_draw_h,
                    mmi_camco_osd_p->imageselect_cache_layer_h);
                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
				mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_image_select_hilite();

                gdi_layer_resize(width, height);
                gdi_layer_pop_and_restore_active();
                mmi_camco_osd_blt();
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
    
                mmi_camco_osd_draw_image_select();
                mmi_camco_osd_draw_softkey();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
            gdi_layer_toggle_double();
            #endif
            gdi_layer_lock_frame_buffer();

            mmi_camco_osd_clear_bg();

            mmi_camco_osd_draw_image_select();
            mmi_camco_osd_draw_softkey();

            gdi_layer_unlock_frame_buffer();
            gdi_layer_pop_and_restore_active();

            mmi_camco_osd_blt();
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_AUTORAMA__
        case MMI_CAMCO_OSD_STATE_AUTORAMA_DIRECTION:
        	{
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_autorama_direction();
				mmi_camco_osd_draw_softkey();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();
                mmi_camco_osd_clear_bg();
                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
                break;
        	}
        case MMI_CAMCO_OSD_STATE_AUTORAMA_SHOT:
        {
   
                /*draw cache layer */
                if(mmi_camco_osd_autorama_cache_draw_is_enable()==MMI_TRUE)
                {
					gdi_layer_push_and_set_active(mmi_camco_osd_p->autorama.cache_draw_layer);
					
                    gdi_layer_set_position(mmi_camco_osd_p->autorama.cache_layer_offset_y,(mmi_camco_osd_p->osd_height-mmi_camco_osd_p->autorama.cache_layer_offset_x-mmi_camco_osd_p->autorama.cache_layer_width));
					mmi_camco_osd_draw_autorama_rigistration_cache();
					
                    gdi_layer_pop_and_restore_active();
            
                    gdi_layer_push_and_set_active(mmi_camco_osd_p->autorama_cache_layer_h);
                    #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
					gdi_layer_toggle_double();
                    #endif
                    gdi_layer_lock_frame_buffer();
                    mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->autorama.cache_draw_layer, mmi_camco_osd_p->autorama_cache_layer_h);
                    
					gdi_layer_unlock_frame_buffer();
                    gdi_layer_pop_and_restore_active();
                    mmi_camco_osd_autorama_cache_draw_enable(MMI_FALSE);
                }
                /*draw osd layer */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_autorama_shot_dir();
                mmi_camco_osd_draw_softkey();
                mmi_camco_osd_draw_autorama_rigistration_rect();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();         
                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);
                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();
                /*blt*/
                mmi_camco_osd_blt();
				break;
        }
#endif
#ifdef __MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__
	    case MMI_CAMCO_OSD_STATE_MAV_SHOT:
		{
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
	        if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
	        {
		        /* Horizontal */
		        gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
   
		        mmi_camco_osd_clear_bg();
		        mmi_camco_osd_draw_mav();
				mmi_camco_osd_draw_preview_center();
				mmi_camco_osd_draw_softkey();
		        gdi_layer_pop_and_restore_active();
   
		        gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
		        #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ 
		        gdi_layer_toggle_double();
			    #endif
			    gdi_layer_lock_frame_buffer();
   
			    mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);
   
			    gdi_layer_unlock_frame_buffer();
			    gdi_layer_pop_and_restore_active();
   
			    mmi_camco_osd_blt();
		   }
        #ifdef DUAL_CAMERA_SUPPORT
	       else
	       {
			   /* Subcamera - Portrait */
			   gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
			#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ 
			   gdi_layer_toggle_double();
			#endif
			
			   gdi_layer_lock_frame_buffer();
   
			   mmi_camco_osd_clear_bg();
			   mmi_camco_osd_draw_mav();
			   mmi_camco_osd_draw_preview_center();
			   mmi_camco_osd_draw_softkey();
   
			   gdi_layer_unlock_frame_buffer();
			   gdi_layer_pop_and_restore_active();
   
			   mmi_camco_osd_blt();
		   }
	    #endif /* DUAL_CAMERA_SUPPORT */ 
    #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
	       gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
		#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ 
		   gdi_layer_toggle_double();
		#endif
		   gdi_layer_lock_frame_buffer();
   
		   mmi_camco_osd_clear_bg();
		   mmi_camco_osd_draw_mav();
		   mmi_camco_osd_draw_preview_center();
		   mmi_camco_osd_draw_softkey();
		   gdi_layer_unlock_frame_buffer();
		   gdi_layer_pop_and_restore_active();
   
		   mmi_camco_osd_blt();
    #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
	break;

    }
#endif
        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_focus();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                /* Subcamera - Portrait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_focus();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
            gdi_layer_toggle_double();
            #endif
            gdi_layer_lock_frame_buffer();

            mmi_camco_osd_clear_bg();
            mmi_camco_osd_draw_focus();

            gdi_layer_unlock_frame_buffer();
            gdi_layer_pop_and_restore_active();

            mmi_camco_osd_blt();
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            break;
        }

        case MMI_CAMCO_OSD_STATE_FOCUSE_HINT:
        {
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_focus_hint();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                /* Subcamera - Portrait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_focus_hint();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__	
            gdi_layer_toggle_double();
            #endif
            gdi_layer_lock_frame_buffer();

            mmi_camco_osd_clear_bg();
            mmi_camco_osd_draw_focus_hint();

            gdi_layer_unlock_frame_buffer();
            gdi_layer_pop_and_restore_active();

            mmi_camco_osd_blt();
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            break;
        }

        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        {
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);               
                
                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_menulist();
                mmi_camco_osd_draw_softkey();

                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();
                
                mmi_camco_osd_blt();                
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ 
                gdi_layer_toggle_double();       
            #endif
                gdi_layer_lock_frame_buffer();
                
                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_menulist();
                mmi_camco_osd_draw_softkey();
                
                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();
                
                mmi_camco_osd_blt();


            }
        #endif /* DUAL_CAMERA_SUPPORT */ 
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
        
            gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
        #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ 
            gdi_layer_toggle_double();
        #endif
            gdi_layer_lock_frame_buffer();
            
            mmi_camco_osd_clear_bg();
            mmi_camco_osd_draw_menulist();
            mmi_camco_osd_draw_softkey();
            
            gdi_layer_unlock_frame_buffer();
            gdi_layer_pop_and_restore_active();
            
            mmi_camco_osd_blt();
            
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
        

            break;
        }

    #ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
        case MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_PREVIEW:
            break;

        case MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_STOP_HINT:
        {
            gdi_layer_push_and_set_active(mmi_camco_osd_p->sublcd_osd_layer_h);
            mmi_camco_osd_clear_bg();
            mmi_camco_sublcd_osd_draw_hint();
            gdi_layer_pop_and_restore_active();

            mmi_camco_osd_sublcd_blt();
            break;
        }
    #endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 

        default:
            MMI_ASSERT(0);
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_base_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layer_h     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_base_layer(gdi_handle layer_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->base_layer_h = layer_h;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DUAL_CAMERA_SUPPORT
    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        mmi_camco_osd_skin_p = &mmi_camco_main_skin_cntx;
    }
    else
    {
        mmi_camco_osd_skin_p = &mmi_camco_sub_skin_cntx;
    }
#endif /* DUAL_CAMERA_SUPPORT */ 

#ifdef HORIZONTAL_CAMERA
    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        mmi_camco_osd_p->osd_width = UI_device_height;
        mmi_camco_osd_p->osd_height = UI_device_width;
    }
#ifdef DUAL_CAMERA_SUPPORT
    else
    {
        mmi_camco_osd_p->osd_width = UI_device_width;
        mmi_camco_osd_p->osd_height = UI_device_height;
    }
#endif /* DUAL_CAMERA_SUPPORT */ 
#else /* HORIZONTAL_CAMERA */ 
    mmi_camco_osd_p->osd_width = UI_device_width;
    mmi_camco_osd_p->osd_height = UI_device_height;
#endif /* HORIZONTAL_CAMERA */ 

#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
#ifdef HORIZONTAL_CAMERA
    mmi_camco_osd_p->sublcd_osd_width = SUBLCD_HEIGHT;
    mmi_camco_osd_p->sublcd_osd_height = SUBLCD_WIDTH;
#else /* HORIZONTAL_CAMERA */ 
    mmi_camco_osd_p->sublcd_osd_width = SUBLCD_WIDTH;
    mmi_camco_osd_p->sublcd_osd_height = SUBLCD_HEIGHT;
#endif /* HORIZONTAL_CAMERA */ 
#endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 

    mmi_camco_osd_p->text_color = gui_color(255, 255, 255);
    mmi_camco_osd_p->text_border_color = gui_color(0, 0, 0);

    mmi_camco_osd_p->is_horizontal = MMI_FALSE;
#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    mmi_camco_osd_p->is_blt = MMI_TRUE;
#endif 
    mmi_camco_osd_init_iconlist();
    mmi_camco_osd_init_setting_menulist();
    mmi_camco_osd_init_option_menulist();
    mmi_camco_osd_init_scroll_bar();
    mmi_camco_osd_init_zoom();
    mmi_camco_osd_init_video_progress();

#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    mmi_camco_osd_init_add_frame();
#endif 

#ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
    mmi_camco_osd_init_image_select();
#endif 

    mmi_camco_osd_init_focus();
    mmi_camco_osd_init_focus_hint();

    mmi_camco_osd_init_xenon_flash();

    mmi_camco_osd_init_facedetect();

#ifdef __SMILE_SHUTTER_SUPPORT__
    mmi_camco_osd_init_smiledetect();
#endif 
#ifdef __MMI_CAMCO_FEATURE_OSD_AUTORAMA__
    mmi_camco_osd_init_autorama();
#endif 

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_is_init_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern void mmi_camco_osd_set_init_mem(void* ptr)
{
    mmi_camco_osd_p->osd_layer_draw_buf_ori_p = (U8*)ptr;   		
}

extern U8* mmi_camco_osd_get_init_mem(void)
{
    return mmi_camco_osd_p->osd_layer_draw_buf_ori_p;   		
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_setup_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  osd_layer_buf_p     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_setup_environment(void *osd_layer_buf_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* allocate resource */
    /* shall move to camcoder memory */
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;
    mmi_camco_osd_time_stamp_struct *time_stamp_p = &mmi_camco_osd_p->time_stamp;
#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
    S32 blt_osd_width = 0;
    S32 blt_osd_height = 0;
    U8 *align_osd_layer_p;
#ifdef __MMI_CAMCO_LOW_COST__
    U8* outside_memory1;
    U8* outside_memory2;
    GDI_HANDLE temp_handle;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(osd_layer_buf_p != NULL);
    mmi_camco_osd_p->osd_layer_buf_p = (U8*) osd_layer_buf_p;

#if defined(HORIZONTAL_CAMERA) && !defined(MMI_CAMCO_OSD_ROTATE_LCD_270_SELF)
    blt_osd_width = mmi_camco_osd_p->osd_width;
    blt_osd_height = mmi_camco_osd_p->osd_height;
#else /* defined(HORIZONTAL_CAMERA) && !defined(MMI_CAMCO_OSD_ROTATE_LCD_270_SELF) */ 
    blt_osd_width = LCD_WIDTH;
    blt_osd_height = LCD_HEIGHT;
#endif /* defined(HORIZONTAL_CAMERA) && !defined(MMI_CAMCO_OSD_ROTATE_LCD_270_SELF) */ 
#ifdef __MMI_CAMCO_LOW_COST__

	/*get gdi memory*/
	gdi_layer_create(0,0,blt_osd_width,blt_osd_height,&temp_handle);
	gdi_layer_push_and_set_active(temp_handle);
	gdi_layer_get_buffer_ptr(&outside_memory1);
	gdi_layer_pop_and_restore_active();
	gdi_layer_free(temp_handle);
	gdi_layer_get_base_handle(&temp_handle);
	gdi_layer_push_and_set_active(temp_handle);
	gdi_layer_get_buffer_ptr(&outside_memory2);
	gdi_layer_pop_and_restore_active();
	/*end*/
	
    gdi_layer_create_cf_double_using_outside_memory(
        2,
        0,
        0,
        blt_osd_width,
        blt_osd_height,
        &mmi_camco_osd_p->osd_layer_h,
        outside_memory1,
        MMI_CAMCO_OSD_LAYER_DB_BUF_SIZE/2,
        outside_memory2,
        MMI_CAMCO_OSD_LAYER_DB_BUF_SIZE/2);

		gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
		gdi_layer_clear(GDI_COLOR_TRANSPARENT);
	    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
	     gdi_layer_set_background(GDI_COLOR_BLACK); 
	    gdi_layer_toggle_double();
	    gdi_layer_copy_double();
	    gdi_layer_pop_and_restore_active();

#else
#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    align_osd_layer_p = (U8*)(((((U32)mmi_camco_osd_p->osd_layer_buf_p) >>5) +1) <<5);
    gdi_layer_create_double_using_outside_memory(
        0, 
        0, 
        blt_osd_width, 
        blt_osd_height,
        &mmi_camco_osd_p->osd_layer_h, 
        (U8*)align_osd_layer_p, 
        MMI_CAMCO_OSD_LAYER_DB_BUF_SIZE);

    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_set_background(GDI_COLOR_BLACK); 
    gdi_layer_toggle_double();
    gdi_layer_copy_double();
    gdi_layer_pop_and_restore_active();
#else
    align_osd_layer_p = (U8*)(((((U32)mmi_camco_osd_p->osd_layer_buf_p) >>5) +1) <<5);
    gdi_layer_create_using_outside_memory(
        0, 
        0, 
        blt_osd_width, 
        blt_osd_height,
        &mmi_camco_osd_p->osd_layer_h, 
        (U8*)align_osd_layer_p, 
        MMI_CAMCO_OSD_LAYER_DB_BUF_SIZE / 2);

    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
     gdi_layer_set_background(GDI_COLOR_BLACK); 
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
#endif
#endif
#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
	if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
	{
            align_osd_layer_p = (U8*)(((((U32)mmi_camco_osd_p->osd_layer_draw_buf_ori_p) >>5) + 1) <<5);    

            gdi_layer_create_using_outside_memory(
                0,
	            0,
	            mmi_camco_osd_p->osd_width, 
	            mmi_camco_osd_p->osd_height, 
	            &mmi_camco_osd_p->osd_layer_draw_h,
	            (U8*) align_osd_layer_p,
	            (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * MMI_CAMCO_OSD_BYTE_PER_PIXEL));       
		
	    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
        gdi_layer_get_buffer_ptr(&mmi_camco_osd_p->osd_layer_draw_buf_p);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
         gdi_layer_set_background(GDI_COLOR_BLACK); 
        gdi_layer_pop_and_restore_active(); 

	}
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
    mmi_camco_osd_p->sublcd_osd_layer_buf_p = mmi_camco_osd_p->osd_layer_buf_p + MMI_CAMCO_OSD_LAYER_DB_BUF_SIZE + 64;
#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__

    gdi_layer_create_double_using_outside_memory(
        0,
        0,
        mmi_camco_osd_p->sublcd_osd_width,
        mmi_camco_osd_p->sublcd_osd_height,
        &mmi_camco_osd_p->sublcd_osd_layer_h,
        (U8*) mmi_camco_osd_p->sublcd_osd_layer_buf_p,
        MMI_CAMCO_SUBLCD_OSD_LAYER_DB_BUF_SIZE);

    gdi_layer_push_and_set_active(mmi_camco_osd_p->sublcd_osd_layer_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_set_background(GDI_COLOR_BLACK); 
    gdi_layer_pop_and_restore_active();
    
#else

    gdi_layer_create_using_outside_memory(
        0, 
        0, 
        mmi_camco_osd_p->sublcd_osd_width, 
        mmi_camco_osd_p->sublcd_osd_height, 
        &mmi_camco_osd_p->sublcd_osd_layer_h, 
        (U8*)mmi_camco_osd_p->sublcd_osd_layer_buf_p, 
        MMI_CAMCO_SUBLCD_OSD_LAYER_DB_BUF_SIZE / 2);

    gdi_layer_push_and_set_active(mmi_camco_osd_p->sublcd_osd_layer_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_set_background(GDI_COLOR_BLACK); 
    gdi_layer_pop_and_restore_active();    

#endif
#endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 


#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    add_frame_p->overlay_frame_layer_buf_p = mmi_frm_scrmem_alloc_framebuffer(CAMCO_OVERLAY_FRAME_BUFFER_SIZE);
    ASSERT(add_frame_p->overlay_frame_layer_buf_p != NULL);

    /*
     * avoid hw issue :It is a hardware issue. 
     * * When the overlay frame buffer address is 16bytes alignment and the enlarge times is 2.
     * * It will cause the result. Please Vincent help to avoid such case. 
     */
    if ((((kal_uint32) add_frame_p->overlay_frame_layer_buf_p) & 0x0f) == 0)
    {
        add_frame_p->overlay_frame_layer_buf_p += 4;
        add_frame_p->is_buf_p_shift = MMI_TRUE;
    }
    else
    {
        add_frame_p->is_buf_p_shift = MMI_FALSE;
    }
    /* end of avoid hw issue */
    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_8,
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &add_frame_p->overlay_frame_layer_h,
        (PU8) add_frame_p->overlay_frame_layer_buf_p,
        (S32) (MMI_CAMCO_OVERLAY_COLOR_IDX_BUFFER_SIZE) - 4);

    gdi_layer_push_and_set_active(add_frame_p->overlay_frame_layer_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_background(GDI_COLOR_BLACK); 
    gdi_layer_pop_and_restore_active();

    time_stamp_p->overlay_frame_layer_buf_p = add_frame_p->overlay_frame_layer_buf_p;
    time_stamp_p->overlay_frame_layer_h = add_frame_p->overlay_frame_layer_h;

        add_frame_p->overlay_frame_layer_cap_buf_p =
            add_frame_p->overlay_frame_layer_buf_p + MMI_CAMCO_ADD_FRAME_BUFFER_SIZE;
        if ((((kal_uint32) add_frame_p->overlay_frame_layer_cap_buf_p) & 0x0f) == 0)
        {
            add_frame_p->overlay_frame_layer_cap_buf_p += 4;
        }
        gdi_layer_create_cf_using_outside_memory(
            GDI_COLOR_FORMAT_8,
            0,
            0,
            MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH,
            MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT,
            &add_frame_p->overlay_frame_cap_layer_h,
            (PU8) add_frame_p->overlay_frame_layer_cap_buf_p,
            (S32) (MMI_CAMCO_OVERLAY_COLOR_IDX_BUFFER_SIZE - MMI_CAMCO_ADD_FRAME_BUFFER_SIZE) - 4);

        gdi_layer_push_and_set_active(add_frame_p->overlay_frame_cap_layer_h);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_set_background(GDI_COLOR_BLACK); 
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();

#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

#if defined(__MMI_TOUCH_SCREEN__)
    /* register pen event */
    wgui_register_pen_down_handler(mmi_camco_osd_touch_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_camco_osd_touch_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_camco_osd_touch_pen_move_hdlr);
#endif /* defined(__MMI_TOUCH_SCREEN__) */ /* __MMI_TOUCH_SCREEN_ */

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    mmi_camco_osd_p->video_recoding_osd.is_init = MMI_FALSE;
#endif 
    mmi_camco_osd_p->autorama.is_init = MMI_FALSE;

    gui_set_font(&MMI_medium_font);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_reset_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_reset_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;
    mmi_camco_osd_time_stamp_struct *time_stamp_p = &mmi_camco_osd_p->time_stamp;
#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free resource */
    MMI_ASSERT(mmi_camco_osd_p->osd_layer_h != GDI_NULL_HANDLE);

    gdi_layer_free(mmi_camco_osd_p->osd_layer_h);
    mmi_camco_osd_p->osd_layer_h = GDI_NULL_HANDLE;

    mmi_camco_osd_p->osd_layer_buf_p = NULL;

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        gdi_layer_free(mmi_camco_osd_p->osd_layer_draw_h);
        mmi_camco_osd_p->osd_layer_draw_h = GDI_NULL_HANDLE;
    }
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
    gdi_layer_free(mmi_camco_osd_p->sublcd_osd_layer_h);
    mmi_camco_osd_p->sublcd_osd_layer_h = GDI_NULL_HANDLE;
#endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 

#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    if (add_frame_p->overlay_frame_layer_buf_p != NULL)
    {
        if (add_frame_p->is_buf_p_shift)
        {
            add_frame_p->overlay_frame_layer_buf_p -= 4;
        }
        mmi_frm_scrmem_free((void*)add_frame_p->overlay_frame_layer_buf_p);
        add_frame_p->overlay_frame_layer_buf_p = NULL;
        time_stamp_p->overlay_frame_layer_buf_p = NULL;
    }

    gdi_layer_free(add_frame_p->overlay_frame_layer_h);
    add_frame_p->overlay_frame_layer_h = GDI_NULL_HANDLE;
    time_stamp_p->overlay_frame_layer_h = add_frame_p->overlay_frame_layer_h;

        gdi_layer_free(add_frame_p->overlay_frame_cap_layer_h);
        add_frame_p->overlay_frame_cap_layer_h = GDI_NULL_HANDLE;
#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_recording_setup_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
static void mmi_camco_osd_recording_setup_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_rect_struct *ev_zoom_area_p = &mmi_camco_osd_p->video_recoding_osd.ev_zoom_area;
    gdi_rect_struct *rec_time_area_p = &mmi_camco_osd_p->video_recoding_osd.rec_time_area;
    gdi_rect_struct *softkey_area_p = &mmi_camco_osd_p->video_recoding_osd.softkey_area;
    gdi_rect_struct *rotate_ev_zoom_area_p = &mmi_camco_osd_p->video_recoding_osd.rotate_ev_zoom_area;
    gdi_rect_struct *rotate_rec_time_area_p = &mmi_camco_osd_p->video_recoding_osd.rotate_rec_time_area;
    gdi_rect_struct *rotate_softkey_area_p = &mmi_camco_osd_p->video_recoding_osd.rotate_softkey_area;
    mmi_camco_osd_video_progress_struct *progress_p = &mmi_camco_osd_p->video_progress;
    mmi_camco_osd_vdo_recording_osd_struct *video_recoding_osd_p = &mmi_camco_osd_p->video_recoding_osd;
    S32 osd_width = 0;
    S32 osd_height = 0;
    PU8 active_ptr = NULL;
    U8* align_osd_layer_p;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define MMI_CAMCO_OSD_REDUCE_AREA_EXTEND (4)
    if (video_recoding_osd_p->is_init)
    {
        return;
    }
    /*
     * Because one of the double buffer is updated by driver. Therefore, we need using another
     * to divide to three layer. Otherwise, the preview image will have noise during the period 
     * of dividing OSD layer. Because at the same time, driver keep updating.
     */
    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__    
    gdi_layer_toggle_double();
#endif
    gdi_layer_lock_frame_buffer();
        
    mmi_camco_osd_clear_bg();
    gdi_layer_get_buffer_ptr(&active_ptr);
        
    gdi_layer_unlock_frame_buffer();
    gdi_layer_pop_and_restore_active();
        
    gdi_layer_free(mmi_camco_osd_p->osd_layer_h);

    rotate_ev_zoom_area_p->x1 = 0;
    rotate_ev_zoom_area_p->y1 = 0;
    rotate_ev_zoom_area_p->x2 = MMI_CAMCO_OSD_RECORDING_EV_ZOOM_AREA_WIDTH - 1;
    rotate_ev_zoom_area_p->y2 = MMI_CAMCO_OSD_RECORDING_EV_ZOOM_AREA_HEIGHT - 1;

    ev_zoom_area_p->x1 = LCD_WIDTH - rotate_ev_zoom_area_p->y2 - 1;
    ev_zoom_area_p->y1 = rotate_ev_zoom_area_p->x1;
    ev_zoom_area_p->x2 = LCD_WIDTH - rotate_ev_zoom_area_p->y1 - 1;
    ev_zoom_area_p->y2 = rotate_ev_zoom_area_p->x2;

    rotate_rec_time_area_p->x1 = 0;
    rotate_rec_time_area_p->y1 = progress_p->time_offset_y - MMI_CAMCO_OSD_REDUCE_AREA_EXTEND;
    rotate_rec_time_area_p->x2 = rotate_rec_time_area_p->x1 + MMI_CAMCO_OSD_RECORDING_REC_TIME_AREA_WIDTH - 1;
    rotate_rec_time_area_p->y2 = rotate_rec_time_area_p->y1 + MMI_CAMCO_OSD_RECORDING_REC_TIME_AREA_HEIGHT - 1;

    rec_time_area_p->x1 = LCD_WIDTH - rotate_rec_time_area_p->y2 - 1;
    rec_time_area_p->y1 = rotate_rec_time_area_p->x1;
    rec_time_area_p->x2 = LCD_WIDTH - rotate_rec_time_area_p->y1 - 1;
    rec_time_area_p->y2 = rotate_rec_time_area_p->x2;

    rotate_softkey_area_p->x1 = LCD_HEIGHT - MMI_CAMCO_OSD_RECORDING_SWKEY_AREA_WIDTH;
    rotate_softkey_area_p->y1 = 0;
    rotate_softkey_area_p->x2 = LCD_HEIGHT - 1;
    rotate_softkey_area_p->y2 = LCD_WIDTH - 1;

    softkey_area_p->x1 = LCD_WIDTH - rotate_softkey_area_p->y2 - 1;
    softkey_area_p->y1 = rotate_softkey_area_p->x1;
    softkey_area_p->x2 = LCD_WIDTH - rotate_softkey_area_p->y1 - 1;
    softkey_area_p->y2 = rotate_softkey_area_p->x2;

    video_recoding_osd_p->osd_layer_ev_zoom_area_buf_p = (U8*) active_ptr;

    video_recoding_osd_p->osd_layer_rec_time_area_buf_p =
        video_recoding_osd_p->osd_layer_ev_zoom_area_buf_p + MMI_CAMCO_OSD_LAYER_EV_ZOOM_AREA_DB_BUF_SIZE + 64;

    video_recoding_osd_p->osd_layer_softkey_area_buf_p =
        video_recoding_osd_p->osd_layer_rec_time_area_buf_p + MMI_CAMCO_OSD_LAYER_REC_TIME_AREA_DB_BUF_SIZE + 64;

    osd_width = ev_zoom_area_p->x2 - ev_zoom_area_p->x1 + 1;
    osd_height = ev_zoom_area_p->y2 - ev_zoom_area_p->y1 + 1;
#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__    
    align_osd_layer_p = (U8*)(((((U32)video_recoding_osd_p->osd_layer_ev_zoom_area_buf_p) >>5) +1) <<5);

    gdi_layer_create_double_using_outside_memory(
        ev_zoom_area_p->x1,
        ev_zoom_area_p->y1,
        osd_width,
        osd_height,
        &video_recoding_osd_p->osd_layer_ev_zoom_area_h,
        (U8*) align_osd_layer_p,
        MMI_CAMCO_OSD_LAYER_EV_ZOOM_AREA_DB_BUF_SIZE);
#else
    align_osd_layer_p = (U8*)(((((U32)video_recoding_osd_p->osd_layer_ev_zoom_area_buf_p) >>5) +1) <<5);

    gdi_layer_create_using_outside_memory(
        ev_zoom_area_p->x1, 
        ev_zoom_area_p->y1, 
        osd_width, 
        osd_height,
        &video_recoding_osd_p->osd_layer_ev_zoom_area_h, 
        (U8*) align_osd_layer_p,
        MMI_CAMCO_OSD_LAYER_EV_ZOOM_AREA_DB_BUF_SIZE);
#endif
    gdi_layer_push_and_set_active(video_recoding_osd_p->osd_layer_ev_zoom_area_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    osd_width = rec_time_area_p->x2 - rec_time_area_p->x1 + 1;
    osd_height = rec_time_area_p->y2 - rec_time_area_p->y1 + 1;
#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__    
    align_osd_layer_p = (U8*)(((((U32)video_recoding_osd_p->osd_layer_rec_time_area_buf_p) >>5) +1) <<5);

    gdi_layer_create_double_using_outside_memory(
        rec_time_area_p->x1,
        rec_time_area_p->y1,
        osd_width,
        osd_height,
        &video_recoding_osd_p->osd_layer_rec_time_area_h,
        (U8*) align_osd_layer_p,
        MMI_CAMCO_OSD_LAYER_REC_TIME_AREA_DB_BUF_SIZE);  
#else
    align_osd_layer_p = (U8*)(((((U32)video_recoding_osd_p->osd_layer_rec_time_area_buf_p) >>5) +1) <<5);

    gdi_layer_create_using_outside_memory(
        rec_time_area_p->x1, 
        rec_time_area_p->y1, 
        osd_width, 
        osd_height,
        &video_recoding_osd_p->osd_layer_rec_time_area_h, 
        (U8*) align_osd_layer_p,
        MMI_CAMCO_OSD_LAYER_REC_TIME_AREA_DB_BUF_SIZE);  
#endif
    gdi_layer_push_and_set_active(video_recoding_osd_p->osd_layer_rec_time_area_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    osd_width = softkey_area_p->x2 - softkey_area_p->x1 + 1;
    osd_height = softkey_area_p->y2 - softkey_area_p->y1 + 1;
#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__      
    align_osd_layer_p = (U8*)(((((U32)video_recoding_osd_p->osd_layer_softkey_area_buf_p) >>5) +1) <<5);

    gdi_layer_create_double_using_outside_memory(
        softkey_area_p->x1,
        softkey_area_p->y1,
        osd_width,
        osd_height,
        &video_recoding_osd_p->osd_layer_softkey_area_h,
        (U8*) align_osd_layer_p,
        MMI_CAMCO_OSD_LAYER_SWKEY_AREA_AREA_DB_BUF_SIZE);     
#else
    align_osd_layer_p = (U8*)(((((U32)video_recoding_osd_p->osd_layer_softkey_area_buf_p) >>5) +1) <<5);

    gdi_layer_create_using_outside_memory(
        softkey_area_p->x1, 
        softkey_area_p->y1, 
        osd_width, 
        osd_height,
        &video_recoding_osd_p->osd_layer_softkey_area_h, 
        (U8*) align_osd_layer_p,
        MMI_CAMCO_OSD_LAYER_SWKEY_AREA_AREA_DB_BUF_SIZE);    
#endif
    gdi_layer_push_and_set_active(video_recoding_osd_p->osd_layer_softkey_area_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    video_recoding_osd_p->is_init = MMI_TRUE;

    /*
     * Because entering OSD recoding state, OSD has to be reduced from FULL LCD to three small OSD
     * for improving performance. However, before set blt layer osd content need to be drawed
     * in advance. Otherwise, the part of the preview layer overlaying the three layer will
     * became empty suddenly. Because at that time, three layer all are transparent.
     */
    mmi_camco_osd_p->is_blt = MMI_FALSE;
    mmi_camco_osd_draw_osd();
    mmi_camco_osd_p->is_blt = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_recording_reset_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_recording_reset_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_vdo_recording_osd_struct *video_recoding_osd_p = &mmi_camco_osd_p->video_recoding_osd;
    S32 blt_osd_width = 0;
    S32 blt_osd_height = 0;
    U8 *align_osd_layer_p;
#ifdef __MMI_CAMCO_LOW_COST__
    U8* outside_memory1;
    U8* outside_memory2;
    GDI_HANDLE temp_handle;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!video_recoding_osd_p->is_init)
    {
        return;
    }
    else if (video_recoding_osd_p->is_init &&
             (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_RECORDING ||
              mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_PAUSE ||
              mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_EXIT))
    {
        return;
    }

    gdi_layer_free(video_recoding_osd_p->osd_layer_ev_zoom_area_h);
    gdi_layer_free(video_recoding_osd_p->osd_layer_rec_time_area_h);
    gdi_layer_free(video_recoding_osd_p->osd_layer_softkey_area_h);

    blt_osd_width = LCD_WIDTH;
    blt_osd_height = LCD_HEIGHT;
#ifdef __MMI_CAMCO_LOW_COST__

	/*get gdi memory*/
	gdi_layer_create(0,0,blt_osd_width,blt_osd_height,&temp_handle);
	gdi_layer_push_and_set_active(temp_handle);
	gdi_layer_get_buffer_ptr(&outside_memory1);
	gdi_layer_pop_and_restore_active();
	gdi_layer_free(temp_handle);
	gdi_layer_get_base_handle(&temp_handle);
	gdi_layer_push_and_set_active(temp_handle);
	gdi_layer_get_buffer_ptr(&outside_memory2);
	gdi_layer_pop_and_restore_active();
	/*end*/
	
    gdi_layer_create_cf_double_using_outside_memory(
        2,
        0,
        0,
        blt_osd_width,
        blt_osd_height,
        &mmi_camco_osd_p->osd_layer_h,
        outside_memory1,
        MMI_CAMCO_OSD_LAYER_DB_BUF_SIZE/2,
        outside_memory2,
        MMI_CAMCO_OSD_LAYER_DB_BUF_SIZE/2);

#else  
    #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__       
    align_osd_layer_p = (U8*)(((((U32)mmi_camco_osd_p->osd_layer_buf_p) >>5) +1) <<5);
    gdi_layer_create_double_using_outside_memory(
        0,
        0,
        blt_osd_width,
        blt_osd_height,
        &mmi_camco_osd_p->osd_layer_h,
        (U8*)    align_osd_layer_p, 
        MMI_CAMCO_OSD_LAYER_DB_BUF_SIZE);
    #else
    align_osd_layer_p = (U8*)(((((U32)mmi_camco_osd_p->osd_layer_buf_p) >>5) +1) <<5);
    gdi_layer_create_using_outside_memory(
        0, 
        0, 
        blt_osd_width, 
        blt_osd_height,
        &mmi_camco_osd_p->osd_layer_h, 
        (U8*)    align_osd_layer_p, 
        MMI_CAMCO_OSD_LAYER_DB_BUF_SIZE/2);
    #endif
#endif
    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_toggle_double();
    gdi_layer_copy_double();
    gdi_layer_pop_and_restore_active();

    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
    gdi_layer_resize(mmi_camco_osd_p->osd_width, mmi_camco_osd_p->osd_height);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    video_recoding_osd_p->is_init = MMI_FALSE;
}


#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_sublcd_stop_hint_set_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_sublcd_stop_hint_set_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* rotate lcd */
#ifdef HORIZONTAL_CAMERA
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_push_and_set_active(mmi_camco_osd_p->sublcd_osd_layer_h);
    gdi_lcd_set_rotate_by_layer(TRUE);
    gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* HORIZONTAL_CAMERA */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_sublcd_stop_hint_reset_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_sublcd_stop_hint_reset_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* rotate lcd */
#ifdef HORIZONTAL_CAMERA
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_push_and_set_active(mmi_camco_osd_p->sublcd_osd_layer_h);
    gdi_lcd_set_rotate_by_layer(FALSE);
    gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* HORIZONTAL_CAMERA */ 
}
#endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_menulist_prev_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_menulist_prev_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_menulist_move_prev())
    {
        mmi_camco_osd_draw_osd();

        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
            mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
        {
            mmi_camco_setting_itemlist_move_prev();
            gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);

            duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;
        }
        else
        {
            /* option menu sensitivity should be lower */
            duration = MMI_CAMCO_OSD_TOUCH_OPTION_MENU_MOVE_DUR;
        }
        gui_start_timer(duration, mmi_camco_osd_menulist_prev_cyclic);
    }
    else
    {
        mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;

        menulist_p->highlighted_idx = menulist_p->item_count - 1;
        menulist_p->first_disp_idx = menulist_p->highlighted_idx - (menulist_p->disp_item_count - 1);

        mmi_camco_osd_update_scrollbar();
        mmi_camco_osd_draw_osd();

        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
            mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
        {
            mmi_camco_setting_itemlist_move_prev();
            gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);

            duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;
        }
        else if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_OPTION_MENU
        	       || mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION
                 || mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION)
        {
            mmi_camco_set_option_menulist_highlight_idx(menulist_p->highlighted_idx);

            /* option menu sensitivity should be lower */
            duration = MMI_CAMCO_OSD_TOUCH_OPTION_MENU_MOVE_DUR;
        }

        gui_start_timer(duration, mmi_camco_osd_menulist_prev_cyclic);
    }

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
        mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
    {
        mmi_camco_reset_preview_terminate_timer();
    }
#endif /* __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_menulist_next_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_menulist_next_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_menulist_move_next())
    {
        mmi_camco_osd_draw_osd();

        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
            mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
        {
            mmi_camco_setting_itemlist_move_next();
            gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);

            duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;
        }
        else
        {
            duration = MMI_CAMCO_OSD_TOUCH_OPTION_MENU_MOVE_DUR;
        }

        gui_start_timer(duration, mmi_camco_osd_menulist_next_cyclic);
    }
    else
    {
        mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;

        menulist_p->highlighted_idx = 0;
        menulist_p->first_disp_idx = 0;

        mmi_camco_osd_update_scrollbar();
        mmi_camco_osd_draw_osd();

        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
            mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
        {
            mmi_camco_setting_itemlist_move_next();
            gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);

            duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;
        }
        else if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_OPTION_MENU
        	       || mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION
                 || mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION)
        {
            mmi_camco_set_option_menulist_highlight_idx(menulist_p->highlighted_idx);

            duration = MMI_CAMCO_OSD_TOUCH_OPTION_MENU_MOVE_DUR;
        }

        gui_start_timer(duration, mmi_camco_osd_menulist_next_cyclic);
    }

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
        mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
    {
        mmi_camco_reset_preview_terminate_timer();
    }
#endif /* __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_iconlist_prev_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_iconlist_prev_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_iconlist_move_prev())
    {
        mmi_camco_setting_mainlist_move_prev();
    }
    else
    {
        mmi_camco_setting_set_mainlist_idx(iconlist_p->icon_count - 1);
        mmi_camco_osd_gen_iconlist();
    }
    if(mmi_camco_setting_get_mainlist_idx() == 0 && mmi_camco_setting_get_mainlist_type() == MMI_CAMCO_SETTING_MAINLIST_PRIMARY)
    {
        mmi_camco_osd_p->is_ev_setting = MMI_TRUE;
    }
    else
    {
        mmi_camco_osd_p->is_ev_setting = MMI_FALSE;
    }

    mmi_camco_osd_gen_setting_menulist();
    mmi_camco_osd_draw_osd();

    mmi_camco_setting_restore_hilite_mod();
    gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

    gui_start_timer(MMI_CAMCO_OSD_TOUCH_ICONLIST_MOVE_DUR, mmi_camco_osd_iconlist_prev_cyclic);

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_iconlist_next_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_iconlist_next_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_iconlist_move_next())
    {
        mmi_camco_setting_mainlist_move_next();
    }
    else
    {
        mmi_camco_setting_set_mainlist_idx(0);
        mmi_camco_osd_gen_iconlist();
    }
    if(mmi_camco_setting_get_mainlist_idx() == 0 && mmi_camco_setting_get_mainlist_type() == MMI_CAMCO_SETTING_MAINLIST_PRIMARY)
    {
        mmi_camco_osd_p->is_ev_setting = MMI_TRUE;
    }
    else
    {
        mmi_camco_osd_p->is_ev_setting = MMI_FALSE;
    }

    mmi_camco_osd_gen_setting_menulist();
    mmi_camco_osd_draw_osd();

    mmi_camco_setting_restore_hilite_mod();
    gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

    gui_start_timer(MMI_CAMCO_OSD_TOUCH_ICONLIST_MOVE_DUR, mmi_camco_osd_iconlist_next_cyclic);

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_slider_touch_menulist_move_prev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
MMI_BOOL mmi_camco_osd_slider_touch_menulist_move_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menulist_p->first_disp_idx > 0)
    {
        menulist_p->first_disp_idx--;
        if (menulist_p->highlighted_idx > menulist_p->first_disp_idx + menulist_p->disp_item_count - 1)
        {
            menulist_p->highlighted_idx = menulist_p->first_disp_idx + menulist_p->disp_item_count - 1;
        }
        mmi_camco_osd_update_scrollbar();

        mmi_camco_osd_draw_osd();

        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
            mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
        {
            mmi_camco_setting_set_itemlist_idx(menulist_p->highlighted_idx);
            gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);
        }
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_slider_touch_menulist_move_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_slider_touch_menulist_move_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menulist_p->first_disp_idx < menulist_p->item_count - menulist_p->disp_item_count)
    {
        menulist_p->first_disp_idx++;
        if (menulist_p->highlighted_idx < menulist_p->first_disp_idx)
        {
            menulist_p->highlighted_idx = menulist_p->first_disp_idx;
        }
        mmi_camco_osd_update_scrollbar();

        mmi_camco_osd_draw_osd();

        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
            mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
        {
            mmi_camco_setting_set_itemlist_idx(menulist_p->highlighted_idx);
            gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);
        }
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_menulist_prev_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_touch_menulist_prev_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_menulist_move_prev())
    {
        mmi_camco_osd_draw_osd();

        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
            mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
        {
            mmi_camco_setting_itemlist_move_prev();
            gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);

            duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;
        }
        else
        {
            duration = MMI_CAMCO_OSD_TOUCH_OPTION_MENU_MOVE_DUR;
        }

        gui_start_timer(duration, mmi_camco_osd_touch_menulist_prev_cyclic);
    }

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_menulist_next_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_touch_menulist_next_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_menulist_move_next())
    {
        mmi_camco_osd_draw_osd();

        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
            mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
        {
            mmi_camco_setting_itemlist_move_next();
            gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);

            duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;
        }
        else
        {
            duration = MMI_CAMCO_OSD_TOUCH_OPTION_MENU_MOVE_DUR;
        }

        gui_start_timer(duration, mmi_camco_osd_touch_menulist_next_cyclic);
    }

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_iconlist_prev_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_touch_iconlist_prev_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_iconlist_move_prev())
    {
        mmi_camco_setting_mainlist_move_prev();
        mmi_camco_osd_gen_setting_menulist();
        mmi_camco_osd_draw_osd();

        mmi_camco_setting_restore_hilite_mod();
        gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

        gui_start_timer(MMI_CAMCO_OSD_TOUCH_ICONLIST_MOVE_DUR, mmi_camco_osd_touch_iconlist_prev_cyclic);
    }

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_iconlist_next_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_touch_iconlist_next_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_iconlist_move_next())
    {
        mmi_camco_setting_mainlist_move_next();
        mmi_camco_osd_gen_setting_menulist();
        mmi_camco_osd_draw_osd();

        mmi_camco_setting_restore_hilite_mod();
        gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

        gui_start_timer(MMI_CAMCO_OSD_TOUCH_ICONLIST_MOVE_DUR, mmi_camco_osd_touch_iconlist_next_cyclic);
    }

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_touch_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_app_enum act_app = mmi_camco_setting_get_active_app();
    #ifdef __MMI_ZOOM_SLIDER_BAR__
    mmi_camco_osd_touch_obj_struct *region =  &mmi_camco_osd_p->slider.slider_region;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_EXIT);

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        mmi_camco_osd_rotate_270_coordinate(&pos.x, &pos.y);
    }
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
    if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->lsk.touch))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_LSK;
        mmi_camco_osd_lsk_press_hdlr();
    }
    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->rsk.touch))
    {
        mmi_camco_osd_rsk_press_hdlr();
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_RSK;
    }
    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->csk.touch))
    {
        if (mmi_camco_osd_p->csk.str_id != 0 || mmi_camco_osd_p->csk.img_id != 0)
        {
            mmi_camco_osd_csk_press_hdlr();
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CSK;
        }
    }
    #ifdef __MMI_ZOOM_SLIDER_BAR__
    else if ((mmi_camco_osd_p->is_show_zoom_slider == MMI_FALSE) &&(
        mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_RECORDING||
        mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_PAUSE ||
        mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW ||
        mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW))
    {
        mmi_camco_osd_zoom_bt_press_hdlr();

    }
    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->slider.slider_location_region))
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER;
            mmi_camco_osd_p->slider.slider_state = MMI_CAMCO_OSD_SLIDER_PRESS;
            mmi_camco_osd_p->slider.slider_location.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
        }
        else if (mmi_camco_osd_p->is_show_zoom_slider == MMI_TRUE&&mmi_camco_osd_touch_slider_normalize(&pos.y ,region->offset_y , region->offset_y + region->height, (mmi_camco_osd_p->slider.slider_location.height))  &&
                   mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->slider.slider_region))
        {
            mmi_slider_update(pos);
            /* let user can move ind after touch some place to change zomm value */
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER;
            mmi_camco_osd_p->slider.slider_state = MMI_CAMCO_OSD_SLIDER_PRESS;
            if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_FACEDETECT) == MMI_CAMCO_FACEDETECT_ON)
            {
                mmi_camco_cam_face_detect_stop();
            }
            if(mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_ASD_SHOT)
            {
                 mmi_camco_cam_scene_detect_stop();
            }
            mmi_camco_osd_p->slider.slider_location.is_press = MMI_TRUE;            
            mmi_camco_osd_draw_osd();

        }
        else if(mmi_camco_osd_p->is_show_zoom_slider == MMI_TRUE && !mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->slider.zoom_region))
        {
            if(mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_VIDEO_RECORDING&&
            mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_VIDEO_PAUSE )
            {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ZOOM_BACK;        

			}
        }
    #else
    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->zoom_in_touch))
    {
        if (act_app == MMI_CAMCO_SETTING_APP_CAMERA)
        {
            mmi_camco_osd_camera_zoom_in_press();
        }
        else if (act_app == MMI_CAMCO_SETTING_APP_VIDEO)
        {
            mmi_camco_osd_video_zoom_in_press();
        }
        else
        {
            MMI_ASSERT(0);
        }

        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_ZOOM_IN;
    }
    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->zoom_out_touch))
    {
        if (act_app == MMI_CAMCO_SETTING_APP_CAMERA)
        {
            mmi_camco_osd_camera_zoom_out_press();
        }
        else if (act_app == MMI_CAMCO_SETTING_APP_VIDEO)
        {
            mmi_camco_osd_video_zoom_out_press();
        }
        else
        {
            MMI_ASSERT(0);
        }

        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_ZOOM_OUT;
    }
    #endif
    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->iconlist.ra_touch))
    {
        mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

        gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);

        iconlist_p->ra_touch.is_press = MMI_TRUE;

        mmi_camco_osd_touch_iconlist_next_cyclic();

        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_ICONLIST_RA;
    }
    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->iconlist.la_touch))
    {
        mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

        gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);

        iconlist_p->la_touch.is_press = MMI_TRUE;

        mmi_camco_osd_touch_iconlist_prev_cyclic();

        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_ICONLIST_LA;
    }
    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->iconlist.list_touch))
    {
        U16 idx;

        idx = mmi_camco_osd_get_iconlist_idx_from_pos(pos.x);

        if (idx != mmi_camco_osd_p->iconlist.highlighted_idx)
        {
            mmi_camco_setting_restore_hilite_mod();
            gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

            mmi_camco_setting_set_mainlist_idx(idx);

            /* gen menulist again */
            mmi_camco_osd_gen_setting_menulist();

            mmi_camco_osd_p->iconlist.highlighted_idx = idx;
            mmi_camco_osd_draw_osd();
        }

        mmi_camco_osd_p->iconlist.touch_down_highlighted_idx = idx;
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_ICONLIST;
    }
    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->setting_menulist.list_touch))
    {
        U16 idx;

        idx = mmi_camco_osd_get_menulist_idx_from_pos(pos.y);
        #ifdef __MMI_FTE_SUPPORT__
        mmi_camco_osd_p->setting_menulist.is_idx_change = MMI_FALSE;
        #endif
        if (idx != mmi_camco_osd_p->setting_menulist.highlighted_idx)
        {
            mmi_camco_setting_set_itemlist_idx(idx);
            mmi_camco_osd_p->setting_menulist.highlighted_idx = idx;
            mmi_camco_setting_item_hilite_hdlr();
            mmi_camco_osd_draw_osd();
        }

        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_MENULIST;
    }
    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->option_menulist.list_touch))
    {
        U16 idx;

        idx = mmi_camco_osd_get_menulist_idx_from_pos(pos.y);

        if (idx != mmi_camco_osd_p->option_menulist.highlighted_idx)
        {
            mmi_camco_osd_p->option_menulist.highlighted_idx = idx;

            if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_OPTION_MENU
                || mmi_camco_osd_p->osd_state ==  MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION
                || mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION)            	
            {
                mmi_camco_set_option_menulist_highlight_idx(idx);
            }

            mmi_camco_osd_draw_osd();
        }
        mmi_camco_osd_p->option_menulist.touch_down_highlighted_idx = idx;

        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_MENULIST;
    }

    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->scrollbar.slider_touch))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_SLIDER;
    }
    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->scrollbar.slider_up_touch))
    {
        mmi_camco_osd_slider_touch_menulist_move_prev();
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_SLIDER_UP;
    }
    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->scrollbar.slider_down_touch))
    {
        mmi_camco_osd_slider_touch_menulist_move_next();
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_SLIDER_DOWN;
    }

#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->add_frame.la_touch))
    {
        gui_cancel_timer(mmi_camco_osd_add_frame_next_cyclic);

        mmi_camco_osd_left_arrow_press();

        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_ADD_FRAME_LA;
    }

    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->add_frame.ra_touch))
    {
        gui_cancel_timer(mmi_camco_osd_add_frame_prev_cyclic);

        mmi_camco_osd_right_arrow_press();

        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_ADD_FRAME_RA;
    }
#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
#ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
#ifndef __MMI_FTE_SUPPORT__
    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->imgselect_cache.la_touch))
    {
        mmi_camco_osd_left_arrow_press();
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_IMAGESELECT_LA;
    }
    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->imgselect_cache.ra_touch))
    {
        mmi_camco_osd_right_arrow_press();
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_IMAGESELECT_RA;
    }
    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->imgselect_cache.ua_touch))
    {
        mmi_camco_osd_up_arrow_press();
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_IMAGESELECT_UA;
    }
    else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->imgselect_cache.da_touch))
    {
        mmi_camco_osd_down_arrow_press();
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_IMAGESELECT_DA;
    }
    else if (mmi_camco_osd_p->imgselect_cache.cache_img_osd_touch != NULL)
    {
        S16 idx = 0;
        MMI_BOOL is_found = MMI_FALSE;

        while (idx < mmi_camco_osd_p->imgselect_cache.disp_cache_count)
        {
            if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->imgselect_cache.cache_img_osd_touch[idx]))
            {
                is_found = MMI_TRUE;
                break;
            }
            idx++;
        }

        if (is_found == MMI_TRUE)
        {
            if (mmi_camco_osd_p->imgselect_cache.highlighted_idx != idx)
            {
                mmi_camco_osd_p->imgselect_cache.highlighted_idx = idx;
                mmi_camco_updata_key_handler();
                mmi_camco_osd_draw_osd();
            }
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_IMAGESELECT;
        }
    }
#else
	else if (mmi_camco_osd_p->imgselect_cache.cache_img_osd_touch != NULL)
    {
        S16 idx = 0;
        MMI_BOOL is_found = MMI_FALSE;

        while (idx < mmi_camco_osd_p->imgselect_cache.disp_cache_count)
        {
            if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->imgselect_cache.cache_img_osd_touch[idx]))
            {
                is_found = MMI_TRUE;
                break;
            }
            idx++;
        }

        if (is_found == MMI_TRUE)
        {   
            mmi_camco_osd_p->imgselect_cache.highlighted_idx = idx;
            mmi_camco_updata_key_handler();
			mmi_camco_osd_p->lsk.touch.is_press = MMI_TRUE;
			mmi_camco_osd_lsk_release_hdlr();
            mmi_camco_osd_draw_osd();
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_IMAGESELECT;
        }
    }
#endif
#endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_touch_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_app_enum act_app = mmi_camco_setting_get_active_app();
    mmi_camco_osd_touch_obj_enum prev_touch_obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_EXIT);

    /* check if is still within */
#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        mmi_camco_osd_rotate_270_coordinate(&pos.x, &pos.y);
    }
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

    switch (mmi_camco_osd_p->touch_obj)
    {
        case MMI_CAMCO_OSD_TOUCH_LSK:
            {
                mmi_camco_osd_lsk_release_hdlr();
            }
            break;

        case MMI_CAMCO_OSD_TOUCH_RSK:
            {
                mmi_camco_osd_rsk_release_hdlr();
            }
            break;

        case MMI_CAMCO_OSD_TOUCH_CSK:
            {
                mmi_camco_osd_csk_release_hdlr();
            }
            break;
        #ifdef __MMI_ZOOM_SLIDER_BAR__
        case MMI_CAMCO_OSD_TOUCH_ZOOM:
            mmi_camco_osd_zoom_bt_release_hdlr();
            break;
            
        case MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER:
            {
                if(mmi_camco_osd_p->slider.slider_location.is_press == MMI_TRUE)
                    mmi_camco_osd_p->slider.slider_location.is_press = MMI_FALSE;

                if (mmi_camco_osd_p->slider.slider_region.is_usable)                
                    mmi_slider_update(pos);
                
                mmi_camco_osd_p->slider.slider_state = MMI_CAMCO_OSD_SLIDER_RELEASE;
                mmi_camco_osd_draw_osd();
                if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_FACEDETECT) == MMI_CAMCO_FACEDETECT_ON)
                {
                    mmi_camco_cam_face_detect_start();
                }

                if(mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_ASD_SHOT)
                {
                     mmi_camco_cam_scene_detect_start();
                }
                break;
            }
       case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ZOOM_BACK:
            {
                mmi_camco_osd_p->is_show_zoom_slider = MMI_FALSE; 
                mmi_camco_osd_p->slider.slider_location_region.is_usable = MMI_FALSE;
                mmi_camco_osd_p->slider.slider_region.is_usable = MMI_FALSE;
                mmi_camco_osd_p->slider.zoom_region.is_usable = MMI_FALSE;                            
                mmi_camco_osd_draw_osd();                
                break;
            }
        #else
        case MMI_CAMCO_OSD_TOUCH_ZOOM_IN:
            if (act_app == MMI_CAMCO_SETTING_APP_CAMERA)
            {
                mmi_camco_osd_camera_zoom_in_release();
            }
            else if (act_app == MMI_CAMCO_SETTING_APP_VIDEO)
            {
                mmi_camco_osd_video_zoom_in_release();
            }
            break;

        case MMI_CAMCO_OSD_TOUCH_ZOOM_OUT:
            if (act_app == MMI_CAMCO_SETTING_APP_CAMERA)
            {
                mmi_camco_osd_camera_zoom_out_release();
            }
            else if (act_app == MMI_CAMCO_SETTING_APP_VIDEO)
            {
                mmi_camco_osd_video_zoom_out_release();
            }
            break;
        #endif
        case MMI_CAMCO_OSD_TOUCH_ICONLIST_RA:
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);
            mmi_camco_osd_right_arrow_release();
            break;

        case MMI_CAMCO_OSD_TOUCH_ICONLIST_LA:
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
            mmi_camco_osd_left_arrow_release();
            break;

        case MMI_CAMCO_OSD_TOUCH_ICONLIST:
        case MMI_CAMCO_OSD_TOUCH_ICONLIST_LEFT:
        case MMI_CAMCO_OSD_TOUCH_ICONLIST_RIGHT:
            if ((mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
                 mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING) &&
                mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_ICONLIST)
            {
                mmi_camco_osd_p->iconlist.touch_up_highlighted_idx = mmi_camco_osd_p->iconlist.highlighted_idx;
            }
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);
            mmi_camco_osd_p->iconlist.la_touch.is_press = MMI_FALSE;
            mmi_camco_osd_p->iconlist.ra_touch.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            break;

        case MMI_CAMCO_OSD_TOUCH_MENULIST:
        case MMI_CAMCO_OSD_TOUCH_MENULIST_UP:
        case MMI_CAMCO_OSD_TOUCH_MENULIST_DOWN:
            {
            if ((mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_OPTION_MENU || mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION
                 || mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION)&&
                mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_MENULIST)
            {
                mmi_camco_osd_p->option_menulist.touch_up_highlighted_idx =
                    mmi_camco_osd_p->option_menulist.highlighted_idx;
            }
            #ifdef __MMI_FTE_SUPPORT__
            if(mmi_camco_osd_p->setting_menulist.is_idx_change == MMI_FALSE&&(
                mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING||
                mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING
                ))
            {
               mmi_camco_osd_p->lsk.touch.is_press = MMI_TRUE;
               mmi_camco_osd_lsk_release_hdlr();
            }
            #endif
            gui_cancel_timer(mmi_camco_osd_touch_menulist_prev_cyclic);
            gui_cancel_timer(mmi_camco_osd_touch_menulist_next_cyclic);
            break;
            }

        case MMI_CAMCO_OSD_TOUCH_SLIDER:
            mmi_camco_osd_p->scrollbar.slider_touch.is_press = MMI_FALSE;
            break;

        case MMI_CAMCO_OSD_TOUCH_SLIDER_UP:
            mmi_camco_osd_p->scrollbar.slider_up_touch.is_press = MMI_FALSE;
            break;

        case MMI_CAMCO_OSD_TOUCH_SLIDER_DOWN:
            mmi_camco_osd_p->scrollbar.slider_down_touch.is_press = MMI_FALSE;
            break;

        #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_TOUCH_ADD_FRAME_RA:
            gui_cancel_timer(mmi_camco_osd_add_frame_next_cyclic);
            mmi_camco_osd_right_arrow_release();
            break;

        case MMI_CAMCO_OSD_TOUCH_ADD_FRAME_LA:
            gui_cancel_timer(mmi_camco_osd_add_frame_prev_cyclic);
            mmi_camco_osd_left_arrow_release();
            break;
        #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

        case MMI_CAMCO_OSD_TOUCH_IMAGESELECT:
        {
            mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

            imgselect_cache_p->la_touch.is_press = MMI_FALSE;
            imgselect_cache_p->ra_touch.is_press = MMI_FALSE;
            imgselect_cache_p->ua_touch.is_press = MMI_FALSE;
            imgselect_cache_p->da_touch.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            break;
        }

        case MMI_CAMCO_OSD_TOUCH_IMAGESELECT_LA:
            mmi_camco_osd_left_arrow_release();
            mmi_camco_osd_draw_osd();
            break;

        case MMI_CAMCO_OSD_TOUCH_IMAGESELECT_RA:
            mmi_camco_osd_right_arrow_release();
            mmi_camco_osd_draw_osd();
            break;

        case MMI_CAMCO_OSD_TOUCH_IMAGESELECT_UA:
            mmi_camco_osd_up_arrow_release();
            mmi_camco_osd_draw_osd();
            break;

        case MMI_CAMCO_OSD_TOUCH_IMAGESELECT_DA:
            mmi_camco_osd_down_arrow_release();
            mmi_camco_osd_draw_osd();
            break; 
    }

    prev_touch_obj = mmi_camco_osd_p->touch_obj;
    mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;

    if ((mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_OPTION_MENU
    	   || mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION
         || mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION) 
        && prev_touch_obj == MMI_CAMCO_OSD_TOUCH_MENULIST)
    {
        if (mmi_camco_osd_p->option_menulist.touch_down_highlighted_idx ==
            mmi_camco_osd_p->option_menulist.touch_up_highlighted_idx)
        {
            mmi_camco_osd_p->lsk.touch.is_press = MMI_TRUE;
            mmi_camco_osd_lsk_release_hdlr();
        }
    }
    else if ((mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
              mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING) &&
             prev_touch_obj == MMI_CAMCO_OSD_TOUCH_ICONLIST)
    {
        if (mmi_camco_osd_p->iconlist.touch_down_highlighted_idx == mmi_camco_osd_p->iconlist.touch_up_highlighted_idx)
        {
            if (mmi_camco_osd_p->iconlist.touch_up_highlighted_idx == mmi_camco_setting_get_mainlist_count() - 1)
            {
                mmi_camco_osd_p->lsk.touch.is_press = MMI_TRUE;
                mmi_camco_osd_lsk_release_hdlr();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_touch_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_app_enum act_app = mmi_camco_setting_get_active_app();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_EXIT);

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        mmi_camco_osd_rotate_270_coordinate(&pos.x, &pos.y);
    }
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

    switch (mmi_camco_osd_p->touch_obj)
    {
        case MMI_CAMCO_OSD_TOUCH_LSK:
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->lsk.touch))
            {
                mmi_camco_osd_p->lsk.touch.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();

                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;

        case MMI_CAMCO_OSD_TOUCH_RSK:
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->rsk.touch))
            {
                mmi_camco_osd_p->rsk.touch.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();

                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;

        case MMI_CAMCO_OSD_TOUCH_CSK:
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->csk.touch))
            {
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;

                mmi_camco_osd_p->csk.touch.is_press = MMI_FALSE;
                if (mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_HIDE && mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT)
                {	
                    mmi_camco_osd_draw_osd();
                }    

                if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT)
                {
                    mmi_camco_osd_p->csk.touch.is_press = MMI_TRUE;
                    mmi_camco_osd_csk_release_hdlr();
                }
            }
            break;
        #ifndef __MMI_ZOOM_SLIDER_BAR__
        case MMI_CAMCO_OSD_TOUCH_ZOOM_IN:
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->zoom_in_touch))
            {
                if (act_app == MMI_CAMCO_SETTING_APP_CAMERA)
                {
                    mmi_camco_osd_camera_zoom_in_release();
                }
                else if (act_app == MMI_CAMCO_SETTING_APP_VIDEO)
                {
                    mmi_camco_osd_video_zoom_in_release();
                }

                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;

        case MMI_CAMCO_OSD_TOUCH_ZOOM_OUT:
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->zoom_out_touch))
            {
                if (act_app == MMI_CAMCO_SETTING_APP_CAMERA)
                {
                    mmi_camco_osd_camera_zoom_out_release();
                }
                else if (act_app == MMI_CAMCO_SETTING_APP_VIDEO)
                {
                    mmi_camco_osd_video_zoom_out_release();
                }

                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        #else
        case MMI_CAMCO_OSD_TOUCH_ZOOM:           
             mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
             break;

        case MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER:
        {
                if (mmi_camco_osd_p->slider.slider_region.is_usable)
                {
                    mmi_slider_update(pos);
                
                    mmi_camco_osd_draw_osd();
                }       
            break;
        }
        
        #endif

        case MMI_CAMCO_OSD_TOUCH_ICONLIST_RA:
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->iconlist.ra_touch))
            {
                gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);

                mmi_camco_osd_p->iconlist.ra_touch.is_press = MMI_FALSE;

                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;

        case MMI_CAMCO_OSD_TOUCH_ICONLIST_LA:
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->iconlist.la_touch))
            {
                gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);

                mmi_camco_osd_p->iconlist.la_touch.is_press = MMI_FALSE;

                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;

        case MMI_CAMCO_OSD_TOUCH_ICONLIST:
        case MMI_CAMCO_OSD_TOUCH_ICONLIST_LEFT:
        case MMI_CAMCO_OSD_TOUCH_ICONLIST_RIGHT:
        {
            mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

            if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->iconlist.list_touch))
            {
                U16 idx;

                gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
                gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);

                idx = mmi_camco_osd_get_iconlist_idx_from_pos(pos.x);

                if (idx != iconlist_p->highlighted_idx)
                {
                    mmi_camco_setting_restore_hilite_mod();
                    gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

                    mmi_camco_setting_set_mainlist_idx(idx);

                    /* gen menulist again */
                    mmi_camco_osd_gen_setting_menulist();

                    iconlist_p->highlighted_idx = idx;
                    mmi_camco_osd_draw_osd();
                #ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
                    mmi_camco_reset_preview_terminate_timer();
                #endif 
                }

                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_ICONLIST;

                mmi_camco_osd_p->iconlist.la_touch.is_press = MMI_FALSE;
                mmi_camco_osd_p->iconlist.ra_touch.is_press = MMI_FALSE;

                if (mmi_camco_osd_p->iconlist.touch_down_highlighted_idx != idx)
                {
                    mmi_camco_osd_p->iconlist.touch_down_highlighted_idx = MMI_CAMCO_OSD_TOUCH_DUMMY_VAL;
                }
            }
            else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->iconlist.la_touch))
            {
                if (mmi_camco_osd_p->touch_obj != MMI_CAMCO_OSD_TOUCH_ICONLIST_LEFT)
                {
                    gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);

                    mmi_camco_osd_p->iconlist.la_touch.is_press = MMI_TRUE;
                    mmi_camco_osd_touch_iconlist_prev_cyclic();
                    mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_ICONLIST_LEFT;
                }
            }
            else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->iconlist.ra_touch))
            {
                if (mmi_camco_osd_p->touch_obj != MMI_CAMCO_OSD_TOUCH_ICONLIST_RIGHT)
                {
                    gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);

                    mmi_camco_osd_p->iconlist.ra_touch.is_press = MMI_TRUE;
                    mmi_camco_osd_touch_iconlist_next_cyclic();
                    mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_ICONLIST_RIGHT;
                }
            }
            else
            {
                /* moved out */
                mmi_camco_osd_p->iconlist.la_touch.is_press = MMI_FALSE;
                mmi_camco_osd_p->iconlist.ra_touch.is_press = MMI_FALSE;
                gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
                gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
                mmi_camco_osd_draw_osd();
            }
            break;
        }

        case MMI_CAMCO_OSD_TOUCH_MENULIST:
        case MMI_CAMCO_OSD_TOUCH_MENULIST_UP:
        case MMI_CAMCO_OSD_TOUCH_MENULIST_DOWN:
        {
            MMI_BOOL update_setting = MMI_FALSE;
            mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;

            if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
                mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
            {
                update_setting = MMI_TRUE;
            }

            if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &menulist_p->list_touch))
            {
                U16 idx;

                gui_cancel_timer(mmi_camco_osd_touch_menulist_prev_cyclic);
                gui_cancel_timer(mmi_camco_osd_touch_menulist_next_cyclic);

                idx = mmi_camco_osd_get_menulist_idx_from_pos(pos.y);

                if (idx != menulist_p->highlighted_idx)
                {
                    if (update_setting)
                    {
                        mmi_camco_setting_set_itemlist_idx(idx);
                        mmi_camco_setting_item_hilite_hdlr();
                    }

                    menulist_p->highlighted_idx = idx;
                    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_OPTION_MENU
                    	  || mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION
                        || mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION)
                    {
                        mmi_camco_set_option_menulist_highlight_idx(idx);
                    }

                    mmi_camco_osd_draw_osd();
                #ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
                    mmi_camco_reset_preview_terminate_timer();
                #endif 
                #ifdef __MMI_FTE_SUPPORT__
                    mmi_camco_osd_p->setting_menulist.is_idx_change = MMI_TRUE;
                #endif
                }
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_MENULIST;

                if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_OPTION_MENU &&
                    mmi_camco_osd_p->option_menulist.touch_down_highlighted_idx != idx)
                {
                    mmi_camco_osd_p->option_menulist.touch_down_highlighted_idx = MMI_CAMCO_OSD_TOUCH_DUMMY_VAL;
                }
            }
            else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &menulist_p->list_up_touch))
            {
                if (mmi_camco_osd_p->touch_obj != MMI_CAMCO_OSD_TOUCH_MENULIST_UP)
                {
                    gui_cancel_timer(mmi_camco_osd_touch_menulist_next_cyclic);

                    mmi_camco_osd_touch_menulist_prev_cyclic();
                    mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_MENULIST_UP;
                }
            }
            else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &menulist_p->list_down_touch))
            {
                if (mmi_camco_osd_p->touch_obj != MMI_CAMCO_OSD_TOUCH_MENULIST_DOWN)
                {
                    gui_cancel_timer(mmi_camco_osd_touch_menulist_prev_cyclic);

                    mmi_camco_osd_touch_menulist_next_cyclic();
                    mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_MENULIST_DOWN;
                }
            }
            else
            {
                /* moved out */
                gui_cancel_timer(mmi_camco_osd_touch_menulist_prev_cyclic);
                gui_cancel_timer(mmi_camco_osd_touch_menulist_next_cyclic);
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }

        case MMI_CAMCO_OSD_TOUCH_SLIDER:
        {
            mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;
            mmi_camco_osd_scrollbar_struct *scrollbar_p = &mmi_camco_osd_p->scrollbar;
            S16 page_idx;
            S32 offset_y;
            MMI_BOOL update_setting = MMI_FALSE;

            if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
                mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
            {
                update_setting = MMI_TRUE;
            }

            offset_y = pos.y - scrollbar_p->scroll_region_offset_y;
            page_idx = offset_y / scrollbar_p->height_per_page;

            if (page_idx < 0)
            {
                page_idx = 0;
            }

            if (page_idx >= scrollbar_p->page_count)
            {
                page_idx = scrollbar_p->page_count - 1;
            }

            if (page_idx != menulist_p->first_disp_idx)
            {
                if (page_idx > menulist_p->first_disp_idx && page_idx < scrollbar_p->page_count)
                {
                    menulist_p->first_disp_idx = page_idx;

                    if (menulist_p->highlighted_idx < menulist_p->first_disp_idx)
                    {
                        /* highlight changed */
                        menulist_p->highlighted_idx = menulist_p->first_disp_idx;

                        mmi_camco_osd_update_scrollbar();
                        mmi_camco_osd_draw_osd();

                        if (update_setting)
                        {
                            mmi_camco_setting_set_itemlist_idx(menulist_p->highlighted_idx);
                            gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);
                        }
                    }
                    else
                    {
                        mmi_camco_osd_update_scrollbar();
                        mmi_camco_osd_draw_osd();
                    }
                }
                else if (page_idx < menulist_p->first_disp_idx && page_idx >= 0)
                {
                    /* move prev */
                    menulist_p->first_disp_idx = page_idx;

                    if (menulist_p->highlighted_idx >= menulist_p->first_disp_idx + menulist_p->disp_item_count)
                    {
                        /* highlight changed */
                        menulist_p->highlighted_idx = menulist_p->first_disp_idx + menulist_p->disp_item_count - 1;

                        mmi_camco_osd_update_scrollbar();
                        mmi_camco_osd_draw_osd();

                        if (update_setting)
                        {
                            mmi_camco_setting_set_itemlist_idx(menulist_p->highlighted_idx);
                            gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);
                        }
                    }
                    else
                    {
                        mmi_camco_osd_update_scrollbar();
                        mmi_camco_osd_draw_osd();
                    }

                }
            }
            break;
        }

        case MMI_CAMCO_OSD_TOUCH_SLIDER_UP:
        {
            mmi_camco_osd_scrollbar_struct *scrollbar_p = &mmi_camco_osd_p->scrollbar;

            if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &scrollbar_p->slider_up_touch))
            {
                mmi_camco_osd_slider_touch_menulist_move_prev();
            }
            else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &scrollbar_p->slider_touch))
            {
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_SLIDER;
                mmi_camco_osd_slider_touch_menulist_move_prev();

                scrollbar_p->slider_up_touch.is_press = MMI_FALSE;
                scrollbar_p->slider_touch.is_press = MMI_TRUE;
            }
            else
            {
                scrollbar_p->slider_up_touch.is_press = MMI_FALSE;

                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }

        case MMI_CAMCO_OSD_TOUCH_SLIDER_DOWN:
        {
            if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->scrollbar.slider_down_touch))
            {
                mmi_camco_osd_slider_touch_menulist_move_next();
            }
            else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->scrollbar.slider_touch))
            {
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_SLIDER;
                mmi_camco_osd_slider_touch_menulist_move_next();

                mmi_camco_osd_p->scrollbar.slider_down_touch.is_press = MMI_FALSE;
                mmi_camco_osd_p->scrollbar.slider_touch.is_press = MMI_TRUE;
            }
            else
            {
                mmi_camco_osd_p->scrollbar.slider_down_touch.is_press = MMI_FALSE;

                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }

    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_TOUCH_ADD_FRAME_LA:
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->add_frame.la_touch))
            {
                gui_cancel_timer(mmi_camco_osd_add_frame_prev_cyclic);
                mmi_camco_osd_p->add_frame.la_touch.is_press = MMI_FALSE;

                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;

        case MMI_CAMCO_OSD_TOUCH_ADD_FRAME_RA:
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->add_frame.ra_touch))
            {
                gui_cancel_timer(mmi_camco_osd_add_frame_next_cyclic);
                mmi_camco_osd_p->add_frame.ra_touch.is_press = MMI_FALSE;

                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

        #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_TOUCH_IMAGESELECT:
        {
            S16 start_idx = 0;
            S16 end_idx = 0;
            S16 idx = 0;
            MMI_BOOL is_movenext = MMI_FALSE;
            MMI_BOOL is_moveprev = MMI_FALSE;
            MMI_BOOL is_found = MMI_FALSE;
            mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

            if (imgselect_cache_p->is_horizontal_display)
            {
                if (pos.x >
                    imgselect_cache_p->cache_img_osd_touch[imgselect_cache_p->highlighted_idx].offset_x +
                    imgselect_cache_p->cache_img_width)
                {
                    is_movenext = MMI_TRUE;
                    imgselect_cache_p->ra_touch.is_press = MMI_TRUE;
                    imgselect_cache_p->la_touch.is_press = MMI_FALSE;
                }
                else if (pos.x < imgselect_cache_p->cache_img_osd_touch[imgselect_cache_p->highlighted_idx].offset_x)
                {
                    is_moveprev = MMI_TRUE;
                    imgselect_cache_p->la_touch.is_press = MMI_TRUE;
                    imgselect_cache_p->ra_touch.is_press = MMI_FALSE;
                }
            }
            else
            {
                if (pos.y >
                    imgselect_cache_p->cache_img_osd_touch[imgselect_cache_p->highlighted_idx].offset_y +
                    imgselect_cache_p->cache_img_height)
                {
                    is_movenext = MMI_TRUE;
                    imgselect_cache_p->da_touch.is_press = MMI_TRUE;
                    imgselect_cache_p->ua_touch.is_press = MMI_FALSE;
                }
                else if (pos.y < imgselect_cache_p->cache_img_osd_touch[imgselect_cache_p->highlighted_idx].offset_y)
                {
                    is_moveprev = MMI_TRUE;
                    imgselect_cache_p->ua_touch.is_press = MMI_TRUE;
                    imgselect_cache_p->da_touch.is_press = MMI_FALSE;
                }
            }

            if (is_movenext == MMI_TRUE &&
                (imgselect_cache_p->highlighted_idx != imgselect_cache_p->disp_cache_count - 1))
            {
                start_idx = imgselect_cache_p->highlighted_idx;
                end_idx = imgselect_cache_p->disp_cache_count;

                for (idx = start_idx; idx < end_idx; idx++)
                {
                    if (mmi_camco_osd_touch_hit_test
                        (pos.x, pos.y, &mmi_camco_osd_p->imgselect_cache.cache_img_osd_touch[idx]))
                    {
                        is_found = MMI_TRUE;
                        break;
                    }
                }
            }
            else if (is_moveprev == MMI_TRUE && (imgselect_cache_p->highlighted_idx != 0))
            {
                start_idx = imgselect_cache_p->highlighted_idx - 1;
                end_idx = 0;

                for (idx = start_idx; idx >= end_idx; idx--)
                {
                    if (mmi_camco_osd_touch_hit_test
                        (pos.x, pos.y, &mmi_camco_osd_p->imgselect_cache.cache_img_osd_touch[idx]))
                    {
                        is_found = MMI_TRUE;
                        break;
                    }
                }
            }

            if ((is_moveprev == MMI_TRUE || is_movenext == MMI_TRUE) && is_found == MMI_TRUE)
            {
                if (idx >= 0 && idx < imgselect_cache_p->disp_cache_count)
                {
                    imgselect_cache_p->highlighted_idx = idx;
                    mmi_camco_updata_key_handler();
                    mmi_camco_osd_draw_osd();
                }
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_IMAGESELECT_LA:
        {
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->imgselect_cache.la_touch))
            {
                gui_cancel_timer(mmi_camco_osd_imgselect_prev_cyclic);
                mmi_camco_osd_p->imgselect_cache.la_touch.is_press = MMI_FALSE;

                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_IMAGESELECT_RA:
        {
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->imgselect_cache.ra_touch))
            {
                gui_cancel_timer(mmi_camco_osd_imgselect_next_cyclic);
                mmi_camco_osd_p->imgselect_cache.ra_touch.is_press = MMI_FALSE;

                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_IMAGESELECT_UA:
        {
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->imgselect_cache.ua_touch))
            {
                gui_cancel_timer(mmi_camco_osd_imgselect_prev_cyclic);
                mmi_camco_osd_p->imgselect_cache.ua_touch.is_press = MMI_FALSE;

                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_IMAGESELECT_DA:
        {
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->imgselect_cache.da_touch))
            {
                gui_cancel_timer(mmi_camco_osd_imgselect_next_cyclic);
                mmi_camco_osd_p->imgselect_cache.da_touch.is_press = MMI_FALSE;

                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */  
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_hit_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos_x           [IN]        
 *  pos_y           [IN]        
 *  touch_obj       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_camco_osd_touch_hit_test(S32 pos_x, S32 pos_y, mmi_camco_osd_touch_obj_struct *touch_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!touch_obj->is_usable)
    {
        return MMI_FALSE;
    }

    if (touch_obj->width <= 0 || touch_obj->height <= 0)
    {
        return MMI_FALSE;
    }

    if ((pos_x >= touch_obj->offset_x) &&
        (pos_x < touch_obj->offset_x + touch_obj->width) &&
        (pos_y >= touch_obj->offset_y) && (pos_y < touch_obj->offset_y + touch_obj->height))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_sublcd_blt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_sublcd_blt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_blt_previous(0, 0, mmi_camco_osd_p->sublcd_osd_width - 1, mmi_camco_osd_p->sublcd_osd_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_sublcd_bg_black
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_sublcd_bg_black(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(mmi_camco_osd_p->sublcd_base_layer_h);
    gdi_layer_resize(SUBLCD_WIDTH, SUBLCD_HEIGHT);
    gdi_layer_set_position(0, 0);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_sublcd_base_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layer_h     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_sublcd_base_layer(gdi_handle layer_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->sublcd_base_layer_h = layer_h;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_sublcd_osd_set_center_hint_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_sublcd_osd_set_center_hint_str(CHAR *str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->sublcd_center_hint.str_ptr = str_ptr;
    gui_measure_string((UI_string_type) mmi_camco_osd_p->sublcd_center_hint.str_ptr, &str_width, &str_height);

    mmi_camco_osd_p->sublcd_center_hint.offset_x = (mmi_camco_osd_p->sublcd_osd_width - str_width) >> 1;
    mmi_camco_osd_p->sublcd_center_hint.offset_y = (mmi_camco_osd_p->sublcd_osd_height - str_height) >> 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_sublcd_osd_set_center_processing_hint_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_sublcd_osd_set_center_processing_hint_str(CHAR *str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->sublcd_center_hint.is_processing = MMI_TRUE;
    mmi_camco_sublcd_osd_set_center_hint_str(str_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_sublcd_osd_draw_hint_process_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_sublcd_osd_draw_hint_process_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->sublcd_center_hint.dot_count++;

    if (mmi_camco_osd_p->sublcd_center_hint.dot_count > MMI_CAMCO_OSD_MAX_HINT_DOT_COUNT)
    {
        mmi_camco_osd_p->sublcd_center_hint.dot_count = 0;
    }

    mmi_camco_osd_draw_osd();

    gui_start_timer(MMI_CAMCO_OSD_HINT_PROCESS_DUR, mmi_camco_sublcd_osd_draw_hint_process_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_sublcd_osd_draw_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_sublcd_osd_draw_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define MMI_CAMCO_SUBLCD_OSD_TMP_BUF_LEN (80)

    S32 i;
    CHAR str_buf[MMI_CAMCO_SUBLCD_OSD_TMP_BUF_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_medium_font);

    if (mmi_camco_osd_p->sublcd_center_hint.str_ptr != NULL)
    {
        gui_set_text_color(mmi_camco_osd_p->text_color);
        gui_set_text_border_color(mmi_camco_osd_p->text_border_color);

        memset(str_buf, 0, MMI_CAMCO_SUBLCD_OSD_TMP_BUF_LEN);

        mmi_ucs2cpy(str_buf, (CHAR*) mmi_camco_osd_p->sublcd_center_hint.str_ptr);

        for (i = 0; i < mmi_camco_osd_p->sublcd_center_hint.dot_count; i++)
        {
            mmi_ucs2cat(str_buf, (CHAR*) (L"."));
        }

        gui_move_text_cursor(
            mmi_camco_osd_p->sublcd_center_hint.offset_x,
            mmi_camco_osd_p->sublcd_center_hint.offset_y);

        gui_print_bordered_text((UI_string_type) str_buf);

        if (mmi_camco_osd_p->sublcd_center_hint.is_processing)
        {
            gui_start_timer(MMI_CAMCO_OSD_HINT_PROCESS_DUR, mmi_camco_sublcd_osd_draw_hint_process_cyclic);
        }

    }

}
#endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 

#endif /* __MMI_CAMCORDER__ */ 

#endif /* MMI_CAMCOOSD_C */ 
#endif /* __MMI_CAMCO_FTE__ */ 

