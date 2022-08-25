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
 *   VTCallScr.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   Video Telephony Call Screen
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_VIDEO_TELEPHONY__

#include "lcd_sw_rnd.h"
#include "MMI_features_video.h" /* features */
#include "gui.h"                /* Gui functions */
#include "GpioSrvGprot.h"            /* LED */
#include "SettingDefs.h"        /* popup sound */
#include "CommonScreens.h"      /* Popup */
#include "MainMenuDef.h"        /* Multi-media icon */
#include "Conversions.h"        /* char set conversion */
#include "PhoneSetupGprots.h"   /* PhnsetGetDefEncodingType() */
//#include "CallManagementGProt.h"/* CM */


#include "med_api.h"            /* media task */
#include "med_main.h"           /* media task */

#include "lcd_sw_rnd.h"
#include "lcd_if.h"

#include "mdi_datatype.h"
#include "mdi_audio.h"          /* audio lib */
#include "mdi_video.h"          /* video lib */
#include "mdi_camera.h"         /* camera lib */
#include "CameraApp.h"

/* tmp include */
#include "VdoPlyResDef.h"

#include "SettingProfile.h"     /* warning tone */
#include "FileManagerGProt.h"   /* file path / file error  */
#include "FileManagerDef.h"     /* error string id */
#include "FileMgr.h"
#include "Mmi_rp_srv_filemanager_def.h"
#include "FileMgrResDef.h"

#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif

#include "DataAccountGprot.h"
#include "DateTimeGprot.h"      /* time related */

#include "vt_mmi_struct.h"      /* User input indication */
#include "BtcmSrvGprot.h" 

#ifdef __MMI_TOUCH_SCREEN__ 
#define __MMI_UCM_VT_FEATURE_TOUCH__
#endif

#ifdef __MMI_UCM_VT_FEATURE_TOUCH__
#include "wgui_touch_screen.h"
#endif 

#include "UcmVtCallScrGprot.h"
#include "UcmVtCallScrProt.h"
#include "resource_vt_skins.h"

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"             /* mdi tvout */
#endif /* __MMI_TVOUT__ */ 

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"          /* DRM support */
#endif /* __DRM_SUPPORT__ */ 

#include "ImageViewerGprot.h"
#include "MediaAppGProt.h"

#include "UCMGProt.h"
#include "UCMProt.h"
#include "UcmSrvGprot.h"
#include "UcmResDef.h" /* Modified by Tony */

//#include "CallmanagementIdDef.h"

#include "GpioSrvGprot.h"
#include "wgui_categories_util.h"
#include "gui_font_size.h"

#include "mdi_include.h"

// for backloght control
#include "device.h"
#include "gpiosrvgprot.h"

// get isp banding
#include "mmi_features_camcorder.h"
#include "gdi_include.h"
#include "CamcorderGprot.h"

#define MMI_VTCS_DTMF_RECEIVE

#ifdef MMI_VTCS_DTMF_RECEIVE
#include "mmi_frm_events_gprot.h"
#include "Vt_mmi_struct.h"
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_VTCS_UPDATE_TIME_DUR                (300) /* 300 ms update once */
#define MMI_VTCS_TOGGLE_TIME_PANEL_DISP_DUR     (5000) /* 5 sec update once */

#define MMI_VTCS_UT_DEBUG
//#define __MMI_UCM_VT_FEATURE_TOUCH__
#if (GDI_LCD_WIDTH == 320) && (GDI_LCD_HEIGHT == 240) 
#define MMI_VTCS_LANDSCAPE_MODE
#endif

/***************************************************************************** 
 * Extern interface
 *****************************************************************************/
extern void gui_screen_switch_effect_block(MMI_BOOL enable);
extern void gui_touch_feedback_play(gui_touch_feedback_enum event_enum);

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

#ifdef MMI_VTCS_DTMF_RECEIVE
typedef void (*mmi_vtcs_dtmf_received_callback)(U16 key_code);

mmi_vtcs_dtmf_received_callback mmi_vtcs_dtmf_received_cb = NULL;

#endif

/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
mmi_vtcs_cntx_struct g_mmi_vtcs_cntx;


/***************************************************************************** 
 * Local Function
 *****************************************************************************/
static void mmi_vtcs_allocate_resource(void); 
static void mmi_vtcs_free_resource(void);
static void mmi_vtcs_config_display_mode(mmi_vtcs_display_mode_enum mode);
static void mmi_vtcs_update_call_status_cyclic(void);
static void mmi_vtcs_init_state(MMI_BOOL is_newly_enter);
static void mmi_vtcs_register_key_event(void);
static void mmi_vtcs_snapshot_key_press(void);
static void mmi_vtcs_snapshot_key_release(void);
static void mmi_vtcs_camera_key_press(void);
static void mmi_vtcs_camera_key_release(void);
static void mmi_vtcs_mic_key_press(void);
static void mmi_vtcs_mic_key_release(void);
static void mmi_vtcs_speaker_key_press(void);
static void mmi_vtcs_speaker_key_release(void);
static void mmi_vtcs_aud_rec_key_press(void);
static void mmi_vtcs_aud_rec_key_release(void);
static void mmi_vtcs_ev_key_press(void);
static void mmi_vtcs_ev_key_release(void);
static void mmi_vtcs_ev_init_cap(void);
static void mmi_vtcs_ev_inc_cyclic(void);
static void mmi_vtcs_ev_dec_cyclic(void);
static void mmi_vtcs_ev_inc_key_press(void);
static void mmi_vtcs_ev_inc_key_release(void);
static void mmi_vtcs_ev_dec_key_press(void);
static void mmi_vtcs_ev_dec_key_release(void);
static void mmi_vtcs_zoom_init_cap(MMI_BOOL enable_update);
static void mmi_vtcs_zoom_in_cyclic(void);
static void mmi_vtcs_zoom_out_cyclic(void);
static void mmi_vtcs_zoom_in_key_press(void);
static void mmi_vtcs_zoom_in_key_release(void);
static void mmi_vtcs_zoom_out_key_press(void);
static void mmi_vtcs_zoom_out_key_release(void);
static void mmi_vtcs_vol_up_cyclic(void);
static void mmi_vtcs_vol_down_cyclic(void);
static void mmi_vtcs_vol_up_key_press(void);
static void mmi_vtcs_vol_up_key_release(void);
static void mmi_vtcs_vol_down_key_press(void);
static void mmi_vtcs_vol_down_key_release(void);
static void mmi_vtcs_lsk_press(void);
static void mmi_vtcs_lsk_release(void);
static void mmi_vtcs_rsk_press(void);
static void mmi_vtcs_rsk_release(void);
static void mmi_vtcs_panel_restore_hdlr(void);
static void mmi_vtcs_config_scroll(
    mmi_vtcs_panel_state_enum state,
    U16 inc_img, 
    U16 dec_img,
    S32 cur_value, 
    S32 total_value);
static void mmi_vtcs_update_scroll_cur_value(S32 cur_value);
static void mmi_vtcs_scroll_inc_press(void);
static void mmi_vtcs_scroll_inc_release(void);
static void mmi_vtcs_scroll_dec_press(void);
static void mmi_vtcs_scroll_dec_release(void);
static U32  mmi_vtcs_get_ev_factor(void);
static U32  mmi_vtcs_get_cam_rotate_factor(void);
static U32 mmi_vtcs_get_cam_rotate_factor_for_IDP(void);
static U32  mmi_vtcs_get_local_enc_qty_factor(void);
static U32  mmi_vtcs_get_peer_enc_qty_factor(void);
static U32  mmi_vtcs_get_enc_size_factor(void);
static void mmi_vtcs_clear_status_bg(void);
static void mmi_vtcs_draw_status(void);
static void mmi_vtcs_draw_title(void);
static void mmi_vtcs_draw_body(void);
static void mmi_vtcs_draw_panel(void);
static void mmi_vtcs_draw_time_cost(void);
static void mmi_vtcs_draw_camera_icon(void);
static void mmi_vtcs_draw_mic_icon(void);
static void mmi_vtcs_draw_speaker_icon(void);
static void mmi_vtcs_draw_aud_rec_icon(void);

#ifdef __MMI_VTCS_OP01__
static void mmi_vtcs_draw_brightness_up_icon(void);
static void mmi_vtcs_draw_brightness_down_icon(void);
static void mmi_vtcs_draw_contrast_icon(void);
static void mmi_vtcs_draw_fullscreen_icon(void);
#endif

static void mmi_vtcs_draw_snapshot_icon(void);
static void mmi_vtcs_draw_ev_icon(void);
static void mmi_vtcs_draw_zoom_icon(void);
static void mmi_vtcs_draw_vk_icon(void);
static void mmi_vtcs_draw_softkey(void);
static void mmi_vtcs_set_softkey(U16 lsk_id, U16 rsk_id);
static void mmi_vtcs_draw_main_wnd(void);
static void mmi_vtcs_draw_sub_wnd(void);
static void mmi_vtcs_open_main_wnd_hole(void);
static void mmi_vtcs_open_sub_wnd_hole(void);
static void mmi_vtcs_draw_skin(void);
static void mmi_vtcs_draw_encode_layer(void);
static void mmi_vtcs_start_event_callback_hdlr(mdi_video_tel_codec_event_enum tel_event, S32 para, void* user_data);
static void mmi_vtcs_stop_display(void);
static S32  mmi_vtcs_start_display(MMI_BOOL enable_3a);
static void mmi_vtcs_pause_display(void);
static S32  mmi_vtcs_resume_display(MMI_BOOL enable_3a);
static void mmi_vtcs_pause_background_display(void);
static void mmi_vtcs_resume_background_display(MMI_BOOL enable_3a);
static void mmi_vtcs_stop_background_display(void);
static void mmi_vtcs_config_layer_seq(void);
static void mmi_vtcs_blt(void);
static U8   mmi_vtcs_convert_key_code_to_ascii(U16 key_code);
static void mmi_vtcs_dtmf_key_up(void);
static void mmi_vtcs_dtmf_key_down(void);
static void mmi_vtcs_add_to_input_box(U16 key_code);
static void mmi_vtcs_entry_call_scr_internal(mmi_scrn_essential_struct* scr_info);
static void mmi_vtcs_exit_call_scr(void);
static void mmi_vtcs_destroy_call_scr_history(void *ptr);
static MMI_BOOL mmi_vtcs_screen_delete_callback(void);
#if defined(__MMI_SUBLCD__)
static void mmi_vtcs_entry_sublcd_scr(void);
static void mmi_vtcs_exit_sublcd_scr(void);
#endif /* defined(__MMI_SUBLCD__) */

#if defined(__MMI_TOUCH_SCREEN__)
static void mmi_vtcs_touch_pen_down_hdlr(mmi_pen_point_struct pos);
static void mmi_vtcs_touch_pen_up_hdlr(mmi_pen_point_struct pos);
static void mmi_vtcs_touch_pen_move_hdlr(mmi_pen_point_struct pos);
#endif /* defined(__MMI_TOUCH_SCREEN__) */

#ifdef MMI_VTCS_UT_DEBUG
static void mmi_vtcs_ut_9_press(void);
static void mmi_vtcs_ut_8_press(void);
static void mmi_vtcs_ut_pound_press(void);
static void mmi_vtcs_ut_toggle_mode(void);
static void mmi_vtcs_ut_enter_mode(mmi_vtcs_display_mode_enum mode);
static void mmi_vtcs_ut_exit_mode(void);
#endif /* MMI_VTCS_UT_DEBUG */

mmi_ret mmi_vtcs_scrn_group_proc(mmi_event_struct *evt);
static void mmi_vtcs_entry_call_scr_normal();

   
/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_display_popup
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_display_popup(U16 str_id, mmi_event_notify_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
                
    mmi_popup_property_init(&arg);
    arg.parent_id = g_mmi_vtcs_cntx.parent_sg_id;
    arg.callback = mmi_vtcs_scrn_group_proc;

    mmi_popup_display((WCHAR *) GetString(str_id), event_type, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_set_call_timer
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_set_call_timer(U32 start_time, U32 cur_time, U32 dur)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    g_mmi_vtcs_cntx.call_start_time = start_time;
    g_mmi_vtcs_cntx.call_cur_time = cur_time;
    g_mmi_vtcs_cntx.call_dur = dur;  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_allocate_resource
 * DESCRIPTION
 *  Allocate resource for UI display 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_allocate_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 offset_x;
    S32 offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * Layer Configuration: 
     *
     * ========== [Up] ============
     * (2) Skin Layer (dobule buffer)   => from screen memory
     * (1) Sub Wnd Layer                => from GDI memory pool
     * (0) Main Wnd Layer               => from GDI memory pool
     * ========= [Down] ============
     *
     * Others
     * (*) Snapshot Layer               => from GDI memory pool
     */

    /* Skin Layer, double buffer */
    g_mmi_vtcs_cntx.skin_layer_buf_ptr = mmi_frm_scrmem_alloc_framebuffer(MMI_VTCS_SKIN_BUF_SIZE);
    MMI_ASSERT(g_mmi_vtcs_cntx.skin_layer_buf_ptr != NULL);
    
    gdi_layer_create_double_using_outside_memory(
        0, 
        0,         
        UI_device_width,
        UI_device_height,
        &g_mmi_vtcs_cntx.skin_layer_handle,
        g_mmi_vtcs_cntx.skin_layer_buf_ptr,
        MMI_VTCS_SKIN_BUF_SIZE);

    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_set_background(GDI_COLOR_BLACK);    
    gdi_layer_pop_and_restore_active();

#ifndef MMI_VTCS_LANDSCAPE_MODE
    /* init status bar */
    g_mmi_vtcs_cntx.prev_status_layer_handle = 
        wgui_status_icon_bar_get_target_layer(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_set_target_layer(
        WGUI_STATUS_ICON_BAR_H_BAR,
        g_mmi_vtcs_cntx.skin_layer_handle);
    wgui_status_icon_bar_set_double_buffer(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_set_alpha_blend_layer(
        WGUI_STATUS_ICON_BAR_H_BAR,
        g_mmi_vtcs_cntx.skin_layer_handle);
    wgui_status_icon_bar_register_hide_callback(
        WGUI_STATUS_ICON_BAR_H_BAR, 
        mmi_vtcs_clear_status_bg);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
#endif /* MMI_VTCS_LANDSCAPE_MODE */

    /* Sub Window */
    gdi_layer_create(
        g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_x,
        g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_y,    
        g_mmi_vtcs_skin_cntx.sub_wnd_rect.width,    
        g_mmi_vtcs_skin_cntx.sub_wnd_rect.height,          
        &g_mmi_vtcs_cntx.sub_wnd_layer_handle);

    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.sub_wnd_layer_handle);
    gdi_layer_set_background(GDI_COLOR_BLACK);    
    gdi_layer_pop_and_restore_active();
    
    /* Main Window */
    //gdi_layer_create(
        //g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_x,
        //g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_y,    
        //g_mmi_vtcs_skin_cntx.main_wnd_rect.width,    
        //g_mmi_vtcs_skin_cntx.main_wnd_rect.height,          
        //&g_mmi_vtcs_cntx.main_wnd_layer_handle);
    gdi_layer_create(
        g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_x,
        g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_y,    
        MMI_VTCS_MAX_WIDTH,    
        MMI_VTCS_MAX_HEIGHT,          
        &g_mmi_vtcs_cntx.main_wnd_layer_handle);

    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.main_wnd_layer_handle);
	gdi_layer_resize(g_mmi_vtcs_skin_cntx.main_wnd_rect.width, g_mmi_vtcs_skin_cntx.main_wnd_rect.height);
    gdi_layer_set_background(GDI_COLOR_BLACK);    
    gdi_layer_pop_and_restore_active();
    
    /* Encode Layer */
    g_mmi_vtcs_cntx.encode_layer_buf_ptr = mmi_frm_scrmem_alloc_framebuffer(MMI_VTCS_ENCODE_BUF_SIZE);
    MMI_ASSERT(g_mmi_vtcs_cntx.encode_layer_buf_ptr != NULL);  

    gdi_layer_create_using_outside_memory(
        0, 
        0,         
        MMI_VTCS_ENCODE_BUF_WIDTH,
        MMI_VTCS_ENCODE_BUF_HEIGHT,
        &g_mmi_vtcs_cntx.encode_layer_handle,
        g_mmi_vtcs_cntx.encode_layer_buf_ptr,
        MMI_VTCS_ENCODE_BUF_SIZE);

    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.encode_layer_handle);
	gdi_layer_resize(g_mmi_vtcs_skin_cntx.main_wnd_rect.width, g_mmi_vtcs_skin_cntx.main_wnd_rect.height);
    gdi_layer_set_background(GDI_COLOR_BLACK);    
    gdi_layer_pop_and_restore_active();


    /* Snapshot Layer */
    gdi_image_get_dimension_id(IMG_ID_UCM_VT_SNAPSHOTING, &image_width, &image_height);
    offset_x = g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_x;
    offset_x += ((g_mmi_vtcs_skin_cntx.main_wnd_rect.width - image_width) >> 1);

    offset_y = g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_y;
    offset_y += ((g_mmi_vtcs_skin_cntx.main_wnd_rect.height - image_height) >> 1);

    gdi_layer_create(
        offset_x,
        offset_y,    
        image_width,    
        image_height,          
        &g_mmi_vtcs_cntx.snapshot_layer_handle);
    
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.snapshot_layer_handle);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_BLUE);
    gdi_layer_clear(GDI_COLOR_BLUE);
    gdi_image_draw_id(0, 0, IMG_ID_UCM_VT_SNAPSHOTING);
    gdi_layer_pop_and_restore_active();    
/*
    gdi_layer_create(
        0,
        (UI_device_height - 50)>>1,    
        UI_device_width,    
        50,          
        &g_mmi_vtcs_cntx.info_layer_handle);
    
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.info_layer_handle);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
*/
    mmi_vtcs_config_layer_seq();
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_free_resource
 * DESCRIPTION
 *  Free resource 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_free_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * Layer Configuration: 
     *
     * ========== [Up] ============
     * (2) Skin Layer (dobule buffer)   => from screen memory
     * (1) Sub Wnd Layer                => from GDI memory pool
     * (0) Main Wnd Layer               => from GDI memory pool
     * ========= [Down] ============
     */
     
    /* Skin Layer, double buffer */
    gdi_layer_free(g_mmi_vtcs_cntx.skin_layer_handle);
    g_mmi_vtcs_cntx.skin_layer_handle = GDI_NULL_HANDLE;
        
    mmi_frm_scrmem_free(g_mmi_vtcs_cntx.skin_layer_buf_ptr);
    g_mmi_vtcs_cntx.skin_layer_buf_ptr = NULL;  

#ifndef MMI_VTCS_LANDSCAPE_MODE
    wgui_status_icon_bar_set_target_layer(WGUI_STATUS_ICON_BAR_H_BAR, g_mmi_vtcs_cntx.prev_status_layer_handle);
    wgui_status_icon_bar_reset_double_buffer(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_reset_alpha_blend_layer(WGUI_STATUS_ICON_BAR_H_BAR);
#endif

    /* Main Window Layer */
    gdi_layer_free(g_mmi_vtcs_cntx.main_wnd_layer_handle);
    g_mmi_vtcs_cntx.main_wnd_layer_handle = GDI_NULL_HANDLE;

    /* Sub Window Layer */
    gdi_layer_free(g_mmi_vtcs_cntx.sub_wnd_layer_handle);
    g_mmi_vtcs_cntx.sub_wnd_layer_handle = GDI_NULL_HANDLE;

    /* Encode Layer */
    gdi_layer_free(g_mmi_vtcs_cntx.encode_layer_handle);
    g_mmi_vtcs_cntx.encode_layer_handle = GDI_NULL_HANDLE;
        
    mmi_frm_scrmem_free(g_mmi_vtcs_cntx.encode_layer_buf_ptr);
    g_mmi_vtcs_cntx.encode_layer_buf_ptr = NULL;  

    /* Snapshot Layer */
    gdi_layer_free(g_mmi_vtcs_cntx.snapshot_layer_handle);
    g_mmi_vtcs_cntx.snapshot_layer_handle = GDI_NULL_HANDLE;
  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_config_mode
 * DESCRIPTION
 *  Config mode 
 * PARAMETERS
 *  mode        [IN]        display mode
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_config_display_mode(mmi_vtcs_display_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    /*         
     *             Main Window      Sub Window      Note
     * ----------------------------------------------------------------------------
     * MODE 1      Peer Video       Local Video     Encode video to peer
     * MODE 2      Local Video      Peer Video      Encode video to peer
     * MODE 3      Peer Video       Local Image     Encode image to peer
     * MODE 4      Local Image      Peer Video      Encode image to peer 
     * MODE 5      Peer Video       Local Hide      Encode black image to peer, no open sub hole 
     * MODE 6      Peer Image       Local Video     Preview only
     * MODE 7      Local Video      Peer Image      Preview only
     * MODE 8      Peer Image       Local Hide      Will not call driver
     * MODE 9      Local Image      Peer Image      Will not call driver
     *
     */    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_CONFIG_DISPLAY_MODE, mode);     
    g_mmi_vtcs_cntx.mode = mode;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_call_status_callback
 * DESCRIPTION
 *  Update call status
 * PARAMETERS
 *  start_timer   [IN]   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vtcs_call_status_callback(MMI_BOOL start_timer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(start_timer)
    {
        applib_time_struct vt_time_ptr;
        applib_time_struct start_time;
        applib_time_struct cur_time;    
        
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_TIMER_STATE,100);     
                
        if (mmi_ucm_vt_get_call_start_time(&vt_time_ptr))
        {   
            /* call have time */
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_TIMER_STATE,101);                 
            memcpy((void*)&start_time, (void*)&vt_time_ptr, sizeof(applib_time_struct));
            applib_dt_get_rtc_time(&cur_time);
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            mmi_vtcs_set_call_timer(
                applib_dt_mytime_2_utc_sec(&start_time, KAL_FALSE),
                applib_dt_mytime_2_utc_sec(&cur_time, KAL_FALSE),
                g_mmi_vtcs_cntx.call_cur_time - g_mmi_vtcs_cntx.call_start_time);
            
            gui_start_timer(MMI_VTCS_UPDATE_TIME_DUR, mmi_vtcs_update_call_status_cyclic);                
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_TIMER_STATE,g_mmi_vtcs_cntx.call_start_time );              
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_TIMER_STATE,g_mmi_vtcs_cntx.call_dur );                          
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_TIMER_STATE,102);              
            /* call do not have time */
            mmi_vtcs_set_call_timer(0, 0, 0);  
        }    
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_TIMER_STATE,-100);        
        mmi_vtcs_set_call_timer(0, 0, 0);     
        gui_cancel_timer(mmi_vtcs_update_call_status_cyclic);        
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_update_call_status_cyclic
 * DESCRIPTION
 *  Update call time handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_update_call_status_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 prev_call_dur;
    S32 unit_len;
	S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    CHAR* unit_p;
    CHAR* cost_p;
    MMI_BOOL need_update = MMI_FALSE;
    
    applib_time_struct cur_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_UPDATE_CALL_STATUS_CYCLIC); 
     
    if(g_mmi_vtcs_cntx.state != MMI_VTCS_STATE_FOREGROUND)
        return;
        
    /* update time */
    prev_call_dur = g_mmi_vtcs_cntx.call_dur;
    applib_dt_get_rtc_time(&cur_time);

    g_mmi_vtcs_cntx.call_cur_time = applib_dt_mytime_2_utc_sec(&cur_time, KAL_FALSE);
    g_mmi_vtcs_cntx.call_dur = g_mmi_vtcs_cntx.call_cur_time - g_mmi_vtcs_cntx.call_start_time;

    if (prev_call_dur != g_mmi_vtcs_cntx.call_dur)
    {
        need_update = MMI_TRUE;
    }

    /* update cost */
    if (mmi_ucm_vt_get_call_cost_status(&unit_p, &cost_p))
    {
        memset(g_mmi_vtcs_cntx.call_cost_str, 0, MMI_VTCS_COST_BUF_SIZE);
        unit_len = mmi_ucs2strlen(unit_p);
        MMI_ASSERT(unit_len < MMI_VTCS_COST_LEN-1);
        
        mmi_ucs2cpy(g_mmi_vtcs_cntx.call_cost_str, unit_p);
        mmi_ucs2ncat(g_mmi_vtcs_cntx.call_cost_str, cost_p, MMI_VTCS_COST_LEN - unit_len - 1);

        g_mmi_vtcs_cntx.is_display_cost = MMI_TRUE;
        need_update = MMI_TRUE;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_UPDATE_CALL_STATUS_CYCLIC_NEED_UPDATE,need_update);
    if (need_update)
    {
    	if(!g_mmi_vtcs_cntx.is_fullscreen_state)
    	{
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_UPDATE_CALL_STATUS_CYCLIC_UPDATE,g_mmi_vtcs_cntx.call_dur,unit_p,cost_p);    
        mmi_vtcs_draw_panel();
		mmi_vtcs_draw_softkey();
    #ifdef __MMI_VTCS_FTE__        
        if(g_mmi_vtcs_cntx.panel_state != MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
    #endif            
        mmi_vtcs_open_sub_wnd_hole();    
        mmi_vtcs_blt();      
        }
		else
		{
		#ifdef __MMI_VTCS_OP01__
			gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
			gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
			gdi_layer_set_clip(
				g_mmi_vtcs_skin_cntx.fullscr_time_pos.offset_x - 1,
				g_mmi_vtcs_skin_cntx.fullscr_time_pos.offset_y - 1,
				g_mmi_vtcs_skin_cntx.fullscr_time_pos.offset_x + 100,
				g_mmi_vtcs_skin_cntx.fullscr_time_pos.offset_y + 30);
			offset_x = g_mmi_vtcs_skin_cntx.fullscr_skin_bg_pos.offset_x- layer_offset_x;
    		offset_y = g_mmi_vtcs_skin_cntx.fullscr_skin_bg_pos.offset_y - layer_offset_y;   
   
   			gdi_image_draw_id(
        		offset_x, 
        		offset_y, 
        		IMG_ID_UCM_VT_FULLSCREEN_BG);
			mmi_vtcs_draw_time_cost();
			gdi_layer_pop_and_restore_active();
		#endif
		    mmi_vtcs_blt();  
		}
    }
	if(g_mmi_vtcs_cntx.panel_state != MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
	{
    gui_start_timer(MMI_VTCS_UPDATE_TIME_DUR, mmi_vtcs_update_call_status_cyclic);    
}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_config_icon_touch
 * DESCRIPTION
 *   
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_config_icon_touch(mmi_vtcs_touch_struct *touch_obj, mmi_vtcs_pos_struct *icon_pos, U16 img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_width = 0, img_height = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_image_get_dimension_id(img_id , &img_width, &img_height);
    touch_obj->offset_x = icon_pos->offset_x;
    touch_obj->offset_y = icon_pos->offset_y;
    touch_obj->width    = img_width;
    touch_obj->height   = img_height;
    touch_obj->is_press = MMI_FALSE;
    touch_obj->is_usable= MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_init_state
 * DESCRIPTION
 *  Init state 
 * PARAMETERS
 *  is_newly_enter      [IN]    is newly enter this screen
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_init_state(MMI_BOOL is_newly_enter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_mode_init = MMI_FALSE;
    MMI_BOOL is_bg_call = MMI_FALSE;
    mmi_vt_camera_enum prev_camera_state;

    applib_time_struct vt_time_ptr;
    applib_time_struct start_time;
    applib_time_struct cur_time;   
    mmi_ucm_vt_incall_pic_status_enum incall_pic_type;
    CHAR* incall_pic_name_ptr;
    U16 incall_pic_id;
    S32 img_width, img_height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_STATE);    

#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        is_bg_call = MMI_TRUE;
    }
#endif /* __MMI_BACKGROUND_CALL__ */
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
#endif
#define VT_CONFIG_ICON(__obj__, __pos__, __IMG_ID__)    \
    mmi_vtcs_config_icon_touch(&g_mmi_vtcs_cntx.touch_##__obj__##, &g_mmi_vtcs_skin_cntx.icon_##__pos__##_pos, ##__IMG_ID__##);

#define VT_CONFIG_VK(__x__, __X__)  \
    mmi_vtcs_config_icon_touch(&g_mmi_vtcs_cntx.touch_vk_##__x__##, &g_mmi_vtcs_skin_cntx.vk_##__x__##_pos, IMG_ID_UCM_VT_VK_##__X__##);

#ifdef __MMI_UCM_VT_FEATURE_TOUCH__
    /* Touch position configuration */

    /* 
     * Touch screen panel icons 
     *   [EV]   [ZOOM]  [CAMERA] [MIC] [SPEAKER] [SNAP] [VK] 
     *     1      2        3       4       5      6      7    
     */

    /* icon */
#ifdef __MMI_VTCS_FTE__
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    VT_CONFIG_ICON(zoom, 1, IMG_ID_UCM_VT_ZOOM);
    VT_CONFIG_ICON(ev, 2, IMG_ID_UCM_VT_EV);
    VT_CONFIG_ICON(camera, 3, IMG_ID_UCM_VT_CAMERA_ON);
    VT_CONFIG_ICON(speaker, 4, IMG_ID_UCM_VT_SPEAKER_ON);
    VT_CONFIG_ICON(vk, 5, IMG_ID_UCM_VT_VK);
#ifdef __MMI_VTCS_OP01__
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
	VT_CONFIG_ICON(brightness_up, 8, IMG_ID_UCM_VT_BRIGHTNESS_UP);   
    VT_CONFIG_ICON(brightness_down, 9, IMG_ID_UCM_VT_BRIGHTNESS_DOWN);   
    VT_CONFIG_ICON(fullscreen, 10, IMG_ID_UCM_VT_FULLSCR_ICON); 
	VT_CONFIG_ICON(contrast, 11, IMG_ID_UCM_VT_CONTRAST_NORMAL); 
#endif

    /* put snapshot icon on CSK on FTE layout */
    gdi_image_get_dimension_id(IMG_ID_UCM_VT_SNAPSHOT , &img_width, &img_height);                           
    g_mmi_vtcs_cntx.touch_snapshot.offset_x = (GDI_LCD_WIDTH - img_width)>>1; 
    g_mmi_vtcs_cntx.touch_snapshot.offset_y = g_mmi_vtcs_skin_cntx.icon_6_pos.offset_y; 
    g_mmi_vtcs_cntx.touch_snapshot.width = img_width;                                            
    g_mmi_vtcs_cntx.touch_snapshot.height = img_height;                                          
    g_mmi_vtcs_cntx.touch_snapshot.is_press = MMI_FALSE;                                         
    g_mmi_vtcs_cntx.touch_snapshot.is_usable = MMI_FALSE;
    
#else
#if defined(__MMI_VTCS_OP01__)&& (defined(__MMI_MAINLCD_240X400__)||defined(__MMI_MAINLCD_240X320__)) 
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    VT_CONFIG_ICON(ev, 1, IMG_ID_UCM_VT_EV);
    VT_CONFIG_ICON(zoom, 2, IMG_ID_UCM_VT_ZOOM);
    VT_CONFIG_ICON(camera, 3, IMG_ID_UCM_VT_CAMERA_ON);
	VT_CONFIG_ICON(speaker, 4, IMG_ID_UCM_VT_SPEAKER_ON);    
    VT_CONFIG_ICON(brightness_up, 5, IMG_ID_UCM_VT_BRIGHTNESS_UP);
    VT_CONFIG_ICON(brightness_down, 6, IMG_ID_UCM_VT_BRIGHTNESS_DOWN);    
	VT_CONFIG_ICON(fullscreen, 7, IMG_ID_UCM_VT_FULLSCR_ICON);   
    VT_CONFIG_ICON(contrast, 8, IMG_ID_UCM_VT_CONTRAST_NORMAL);
#else
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    VT_CONFIG_ICON(vk, 1, IMG_ID_UCM_VT_VK);         
    VT_CONFIG_ICON(ev, 2, IMG_ID_UCM_VT_EV);
    VT_CONFIG_ICON(zoom, 3, IMG_ID_UCM_VT_ZOOM);
    VT_CONFIG_ICON(camera, 4, IMG_ID_UCM_VT_CAMERA_ON);
    VT_CONFIG_ICON(mic, 5, IMG_ID_UCM_VT_MIC_ON);
    VT_CONFIG_ICON(speaker, 6, IMG_ID_UCM_VT_SPEAKER_ON);    
    VT_CONFIG_ICON(snapshot, 7, IMG_ID_UCM_VT_SNAPSHOT);
#endif
#endif
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

    VT_CONFIG_VK(0, 0);
    VT_CONFIG_VK(1, 1);
    VT_CONFIG_VK(2, 2);
    VT_CONFIG_VK(3, 3);
    VT_CONFIG_VK(4, 4);
    VT_CONFIG_VK(5, 5);
    VT_CONFIG_VK(6, 6);
    VT_CONFIG_VK(7, 7);
    VT_CONFIG_VK(8, 8);
    VT_CONFIG_VK(9, 9);
    VT_CONFIG_VK(star,STAR);        
    VT_CONFIG_VK(pound,POUND); 
    
    g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;     
#else /* __MMI_UCM_VT_FEATURE_TOUCH__ */
    /* 
     * Non-Touch sreen panel icons 
     * [CAMERA] [MIC] [SPEAKER] [SNAP] 
     *    4       5      6       7
     */
    #ifndef __MMI_VTCS_FTE__
    #if 0
/* under construction !*/
/* under construction !*/
    #endif
    VT_CONFIG_ICON(camera, 4, IMG_ID_UCM_VT_CAMERA_ON);
	VT_CONFIG_ICON(snapshot, 7, IMG_ID_UCM_VT_SNAPSHOT);
	#endif
	#if 0
/* under construction !*/
/* under construction !*/
    #endif
    VT_CONFIG_ICON(mic, 5, IMG_ID_UCM_VT_MIC_ON);
    VT_CONFIG_ICON(speaker, 6, IMG_ID_UCM_VT_SPEAKER_ON); 

#endif /* __MMI_UCM_VT_FEATURE_TOUCH__ */

    g_mmi_vtcs_cntx.touch_inc.offset_x = g_mmi_vtcs_skin_cntx.inc_icon_pos.offset_x;
    g_mmi_vtcs_cntx.touch_inc.offset_y = g_mmi_vtcs_skin_cntx.inc_icon_pos.offset_y;
    gdi_image_get_dimension_id(IMG_ID_UCM_VT_VOL_UP, &img_width, &img_height);
    g_mmi_vtcs_cntx.touch_inc.width = img_width;
    g_mmi_vtcs_cntx.touch_inc.height = img_height;    

    g_mmi_vtcs_cntx.touch_dec.offset_x = g_mmi_vtcs_skin_cntx.dec_icon_pos.offset_x;
    g_mmi_vtcs_cntx.touch_dec.offset_y = g_mmi_vtcs_skin_cntx.dec_icon_pos.offset_y;
    gdi_image_get_dimension_id(IMG_ID_UCM_VT_VOL_DOWN, &img_width, &img_height);
    g_mmi_vtcs_cntx.touch_dec.width = img_width;
    g_mmi_vtcs_cntx.touch_dec.height = img_height;    


    /* note: lsk, rsk touch region will be assigned while drawing the text */

    /* init when in ut state */
    if (g_mmi_vtcs_cntx.is_ut)
    {
    #ifdef __MMI_UCM_VT_DUAL_CAMERA__        
        g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_FRONT;    
    #else
        g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_ON;
    #endif 
    
        g_mmi_vtcs_cntx.mic_state = MMI_VT_MIC_ON;
        g_mmi_vtcs_cntx.speaker_state = MMI_VT_SPEAKER_ON;  
        g_mmi_vtcs_cntx.aud_rec_state = MMI_VT_AUD_REC_OFF;
        g_mmi_vtcs_cntx.ev_value = MMI_VT_EV_0;
        g_mmi_vtcs_cntx.local_enc_qty_state = MMI_VT_VIDEO_QUALITY_NORMAL;
        g_mmi_vtcs_cntx.peer_enc_qty_state = MMI_VT_VIDEO_QUALITY_NORMAL;        
        g_mmi_vtcs_cntx.enc_size_state = MMI_VT_ENC_SIZE_QCIF;    
        g_mmi_vtcs_cntx.vol_value = MMI_VT_VOL_3;
        g_mmi_vtcs_cntx.panel_state = MMI_VTCS_PANEL_STATE_TIME_ICON;

        memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
        mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"Hello", MMI_VTCS_TITLE_LEN);
        mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_1);
        g_mmi_vtcs_cntx.call_dur = 500;
        g_mmi_vtcs_cntx.local_img_state = MMI_VTCS_LOCAL_IMG_DEFAULT_ID;   
        //return;
    }
    
    /* camera */
    prev_camera_state = g_mmi_vtcs_cntx.camera_state;
    if (mmi_ucm_vt_get_camera_status())
    {
    #ifdef __MMI_UCM_VT_DUAL_CAMERA__
        if (mmi_ucm_vt_get_main_camera_status())
        {
            g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_BACK;
        }
        else
        {
            g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_FRONT;            
        }
    #else /* __MMI_UCM_VT_DUAL_CAMERA__ */
        g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_ON;
    #endif /* __MMI_UCM_VT_DUAL_CAMERA__ */
    }
    else
    {
        g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_OFF;        
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_STATE_CAMERA,g_mmi_vtcs_cntx.camera_state); 

    /* get capability from driver after knowing using which camera */
    if (is_newly_enter || prev_camera_state != g_mmi_vtcs_cntx.camera_state)
    {
        /* first time enter or camera changed in option screen */
        mmi_vtcs_zoom_init_cap(MMI_TRUE);    
        mmi_vtcs_ev_init_cap();
        g_mmi_vtcs_cntx.contrast_state = MMI_VT_CONTRAST_NORMAL;
    }
    /* reset the inc/dec icon staus if the up event is not received in the previous exit */
    g_mmi_vtcs_cntx.touch_inc.is_press = MMI_FALSE;  
    g_mmi_vtcs_cntx.touch_dec.is_press = MMI_FALSE; 

    g_mmi_vtcs_cntx.touch_lsk.is_press = MMI_FALSE;  
    g_mmi_vtcs_cntx.touch_rsk.is_press = MMI_FALSE; 


    /* camera mirror */
    /* no need to get from vt, it always turn off when rear camera and turn on it when front camera */
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
#endif

    /* mic */
    if (mmi_ucm_vt_get_mic_status())
    {
        g_mmi_vtcs_cntx.mic_state = MMI_VT_MIC_ON;
    }
    else
    {
        g_mmi_vtcs_cntx.mic_state = MMI_VT_MIC_OFF;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_STATE_MIC,g_mmi_vtcs_cntx.mic_state); 
    
    /* speaker */
    if (mmi_ucm_vt_get_speaker_status())
    {
        g_mmi_vtcs_cntx.speaker_state = MMI_VT_SPEAKER_ON;  
    }
    else
    {
        g_mmi_vtcs_cntx.speaker_state = MMI_VT_SPEAKER_OFF;  
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_STATE_SPEAKER,g_mmi_vtcs_cntx.speaker_state); 
    
    /* aud record */
    /* TODO: need interface to get status */
    g_mmi_vtcs_cntx.aud_rec_state = MMI_VT_AUD_REC_OFF;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_STATE_AUDREC,g_mmi_vtcs_cntx.speaker_state); 

    /* ev */
    g_mmi_vtcs_cntx.ev_value = mmi_ucm_vt_get_ev_status();

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_STATE_EV,g_mmi_vtcs_cntx.ev_value); 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_STATE_ZOOM,g_mmi_vtcs_cntx.zoom_step); 
    
    /* enc quality */
    /* enc quality for peer */
    g_mmi_vtcs_cntx.peer_enc_qty_state = mmi_ucm_vt_get_video_quality_status();

    /* enc quality for local */
    if (is_newly_enter)
    {
        g_mmi_vtcs_cntx.local_enc_qty_state = MMI_VT_VIDEO_QUALITY_NORMAL;
    }

    if(mmi_ucm_vt_get_night_mode_status() == MMI_VT_NIGHT_MODE_ON)
    {
        g_mmi_vtcs_cntx.night_mode_state = MMI_VT_NIGHT_ON;
    }        
    else
    {    
        g_mmi_vtcs_cntx.night_mode_state = MMI_VT_NIGHT_OFF;
    }
    

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_STATE_ENC_QUAT,g_mmi_vtcs_cntx.local_enc_qty_state); 
    
    /* video size - default QCIF */
    g_mmi_vtcs_cntx.enc_size_state = MMI_VT_ENC_SIZE_QCIF;    

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_STATE_ENC_STATE,g_mmi_vtcs_cntx.enc_size_state);     

    /* volume */
    g_mmi_vtcs_cntx.vol_value = mmi_ucm_vt_get_volume_status();
    //mmi_ucm_vt_set_volume_status(g_mmi_vtcs_cntx.vol_value);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_STATE_VOL,g_mmi_vtcs_cntx.vol_value);     
    
    if(g_mmi_vtcs_cntx.speaker_state == MMI_VT_SPEAKER_OFF)
    {    
        mmi_ucm_vt_set_speaker_status(MMI_FALSE);        
    }
    else 
    {        
        mmi_ucm_vt_set_speaker_status(MMI_TRUE);                
    }
    
    if (is_newly_enter)
    {
        g_mmi_vtcs_cntx.original_brightness_state = (mmi_vt_brightness_enum)srv_backlight_get_level(SRV_BACKLIGHT_TYPE_MAINLCD); 

    #ifdef __MMI_VTCS_OP01__
        if(g_mmi_vtcs_cntx.original_brightness_state == MMI_VT_BRIGHTNESS_LEVEL0)
        {
            g_mmi_vtcs_cntx.original_brightness_state = MMI_VT_BRIGHTNESS_LEVEL1;    
            srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD, MMI_VT_BRIGHTNESS_LEVEL1);             
        }
    #endif        
        g_mmi_vtcs_cntx.brightness_state = g_mmi_vtcs_cntx.original_brightness_state;
    }    

    /* ctrl panel */
    g_mmi_vtcs_cntx.panel_state = MMI_VTCS_PANEL_STATE_TIME_ICON;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_STATE_PANNEL,g_mmi_vtcs_cntx.panel_state);     

    /* title */
    memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
    
    mmi_ucm_vt_get_remote_display_name((U16*) g_mmi_vtcs_cntx.title_buf, ((MMI_VTCS_TITLE_LEN - 1) / 2));
    
    /* out-going image */
    incall_pic_type = mmi_ucm_vt_get_incall_pic(&incall_pic_id, &incall_pic_name_ptr, MMI_UCM_VT_INCALL_PIC_TYPE_LOCAL_USER);

    if (incall_pic_type == MMI_UCM_VT_INCALL_PIC_STATUS_BUILT_IN)
    {
        g_mmi_vtcs_cntx.local_img_state = MMI_VTCS_LOCAL_IMG_DEFAULT_ID;   
		g_mmi_vtcs_cntx.is_local_image_off = MMI_FALSE;
    }
    else if(incall_pic_type == MMI_UCM_VT_INCALL_PIC_STATUS_FILE)
    {
        g_mmi_vtcs_cntx.local_img_state = MMI_VTCS_LOCAL_IMG_USER_FILE;   
		g_mmi_vtcs_cntx.is_local_image_off = MMI_FALSE;
        memset(g_mmi_vtcs_cntx.user_img_file_path, 0, SRV_FMGR_PATH_BUFFER_SIZE);
        mmi_ucs2ncpy(g_mmi_vtcs_cntx.user_img_file_path, incall_pic_name_ptr, SRV_FMGR_PATH_MAX_LEN);
    }
	else if(incall_pic_type == MMI_UCM_VT_INCALL_PIC_STATUS_OFF)
	{
	    g_mmi_vtcs_cntx.local_img_state = MMI_VTCS_LOCAL_IMG_DEFAULT_ID;  
		g_mmi_vtcs_cntx.is_local_image_off = MMI_TRUE;
    }
    else
    {
        MMI_ASSERT(0);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_STATE_IMAGE,g_mmi_vtcs_cntx.local_img_state); 

    incall_pic_type = mmi_ucm_vt_get_incall_pic(&incall_pic_id, &incall_pic_name_ptr, MMI_UCM_VT_INCALL_PIC_TYPE_REMOTE_USER);

    if (incall_pic_type == MMI_UCM_VT_INCALL_PIC_STATUS_BUILT_IN)
    {
        g_mmi_vtcs_cntx.peer_img_state = MMI_VTCS_LOCAL_IMG_DEFAULT_ID;   
    }
    else if(incall_pic_type == MMI_UCM_VT_INCALL_PIC_STATUS_FILE)
    {
        g_mmi_vtcs_cntx.peer_img_state = MMI_VTCS_LOCAL_IMG_USER_FILE;   
        memset(g_mmi_vtcs_cntx.default_peer_img_file_path, 0, SRV_FMGR_PATH_BUFFER_SIZE);
        mmi_ucs2ncpy(g_mmi_vtcs_cntx.default_peer_img_file_path, incall_pic_name_ptr, SRV_FMGR_PATH_MAX_LEN);
    }
    else
    {
        MMI_ASSERT(0);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_STATE_IMAGE,g_mmi_vtcs_cntx.peer_img_state); 
    
    /* clear user input buffer */
    memset(g_mmi_vtcs_cntx.input_box_buf, 0, MMI_VTCS_INPUT_BOX_BUF_SIZE);

    g_mmi_vtcs_cntx.is_enc_path_built = MMI_FALSE;

    /* init mode */
    g_mmi_vtcs_cntx.is_hide_sub = mmi_ucm_vt_get_hide_small_pic_status();

    switch (mmi_ucm_vt_get_incall_screen_mode())
    {
        case MMI_UCM_VT_INCALL_SCREEN_MODE_INCALL:
            /* Mode 1 */
            /* Main: Peer Video */
            /* Sub : Local Video */
            if (mmi_ucm_vt_get_camera_status() == MMI_TRUE &&           /* camera on */
                mmi_ucm_vt_get_pic_switch_status() == MMI_FALSE)        /* peer on main */
            {

                mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_1);
                is_mode_init = MMI_TRUE;
            }

            /* Mode 2 */
            /* Main: Local Video */
            /* Sub : Peer Video */
            if (mmi_ucm_vt_get_camera_status() == MMI_TRUE &&           /* camera on */
                mmi_ucm_vt_get_pic_switch_status() == MMI_TRUE)         /* peer on sub */
            {
                mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_2);
                is_mode_init = MMI_TRUE;
            }

            /* Mode 3 */
            /* Main: Peer Video */
            /* Sub : Local Image */            
            if (mmi_ucm_vt_get_camera_status() == MMI_FALSE &&          /* camera off */
                mmi_ucm_vt_get_pic_switch_status() == MMI_FALSE)        /* peer on main */
            {
                mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_3);
                is_mode_init = MMI_TRUE;
            }

            /* Mode 4 */
            /* Main: Local Image */
            /* Sub : Peer Video */              
            if (mmi_ucm_vt_get_camera_status() == MMI_FALSE &&          /* camera off */
                mmi_ucm_vt_get_pic_switch_status() == MMI_TRUE)         /* Peer on sub */
            {
                mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_4);
                is_mode_init = MMI_TRUE;
            }      

            if (mmi_ucm_vt_get_hand_free_status())
            {
                g_mmi_vtcs_cntx.hand_state = MMI_VT_HAND_FREE;
            }
            else
            {
                g_mmi_vtcs_cntx.hand_state = MMI_VT_HAND_HELD;
            }
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_STATE_HAND,g_mmi_vtcs_cntx.hand_state); 

            /* call dur */
            /* start until VT notify me */
            if(!mmi_ucm_get_no_counter_status()) /* it mean shoud start timer */
            {                            
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_TIMER_STATE,1);     
                                                
                if (mmi_ucm_vt_get_call_start_time(&vt_time_ptr))
                {   
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_TIMER_STATE,2);
                    /* call have time */
                    memcpy((void*)&start_time, (void*)&vt_time_ptr, sizeof(applib_time_struct));
                    applib_dt_get_rtc_time(&cur_time);
                    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
                    #endif
                    mmi_vtcs_set_call_timer(
                        applib_dt_mytime_2_utc_sec(&start_time, KAL_FALSE),
                        applib_dt_mytime_2_utc_sec(&cur_time, KAL_FALSE),
                        g_mmi_vtcs_cntx.call_cur_time - g_mmi_vtcs_cntx.call_start_time);
                
                    gui_start_timer(MMI_VTCS_UPDATE_TIME_DUR, mmi_vtcs_update_call_status_cyclic);                
                     
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_TIMER_STATE,g_mmi_vtcs_cntx.call_start_time); 
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_TIMER_STATE,g_mmi_vtcs_cntx.call_dur);                          
                }
                else
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_TIMER_STATE,3);
                    /* call do not have time */
                    mmi_vtcs_set_call_timer(0, 0, 0);  
                }
            }
            else            
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_TIMER_STATE,0);                
                
                if(is_newly_enter)
                {                    
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_INIT_TIMER_STATE,-1);
                    
                    mmi_vtcs_set_call_timer(0, 0, 0);
                }
            }
        #ifdef __MMI_BT_SUPPORT__
            if (!srv_bt_cm_is_incall_aud_swap2bt())
            {
                if (mmi_ucm_vt_get_hand_free_status())
                {
                    mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_ID_UCM_VT_RSK_HANDS_HELD);                
                }
                else
                {
                    mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_ID_UCM_VT_RSK_HANDS_FREE);
                }
            }
            else
            {
               mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, 0);
            }
        #else /* __MMI_BT_HP_SUPPORT__ */
        
            if (mmi_ucm_vt_get_hand_free_status())
            {
                mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_ID_UCM_VT_RSK_HANDS_HELD);                
            }
            else
            {
                mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_ID_UCM_VT_RSK_HANDS_FREE);
            }
        #endif /* __MMI_BT_HP_SUPPORT__ */
        
            /* not within any mode */
            MMI_ASSERT(is_mode_init);
            break;

        case MMI_UCM_VT_INCALL_SCREEN_MODE_NONE:
        case MMI_UCM_VT_INCALL_SCREEN_MODE_PREVIEW_ONLY:

            /* Mode 5 */
            /* Main: Peer Image */
            /* Sub : Local Video */             
            if (mmi_ucm_vt_get_camera_status() == MMI_TRUE &&           /* camera on */
                mmi_ucm_vt_get_pic_switch_status() == MMI_FALSE)        /* peer on main */
            {
                if (is_bg_call)
                {
                    mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_7);
                }
                else
                {
                    mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_5);
                }
                is_mode_init = MMI_TRUE;
            }   

            /* Mode 6 */
            /* Main: Local Video */
            /* Sub : Peer Image */              
            if (mmi_ucm_vt_get_camera_status() == MMI_TRUE &&           /* camera on */
                mmi_ucm_vt_get_pic_switch_status() == MMI_TRUE)         /* peer on sub */
            {
                if (is_bg_call)
                {
                    mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_8);
                }
                else
                {            
                    mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_6);
                }
                is_mode_init = MMI_TRUE;
            }   

            /* Mode 7 */
            /* Main: Peer Image */
            /* Sub : Local Image */              
            if (mmi_ucm_vt_get_camera_status() == MMI_FALSE &&          /* camera off */
                mmi_ucm_vt_get_pic_switch_status() == MMI_FALSE)        /* peer on main */
            {
                mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_7);
                is_mode_init = MMI_TRUE;
            } 

            /* Mode 8 */
            /* Main: Peer Image */
            /* Sub : Local Image */                 
            if (mmi_ucm_vt_get_camera_status() == MMI_FALSE &&          /* camera off */
                mmi_ucm_vt_get_pic_switch_status() == MMI_TRUE)         /* peer on sub */
            {
                mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_8);
                is_mode_init = MMI_TRUE;
            } 

            mmi_vtcs_set_call_timer(0, 0, 0);

            mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_GLOBAL_BACK);
            
            /* not within any mode */
            MMI_ASSERT(is_mode_init);
            break;

        default:
            /* shall not enter here */
            MMI_ASSERT(0);
    }


}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_register_key_event
 * DESCRIPTION
 *  Register key event  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_register_key_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear all key handlers */
    ClearAllKeyHandler();
	if(g_mmi_vtcs_cntx.is_fullscreen_state)
	{
	    //kal_print_string_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Video call]: fullstate: %d, line:%d", g_mmi_vtcs_cntx.is_fullscreen_state, __LINE__);
		SetKeyHandler(mmi_vtcs_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_rsk_release, KEY_RSK, KEY_EVENT_UP);
		return;
	}

#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        /* if is background call, only enable lsk (option) and rsk (back) */
        SetKeyHandler(mmi_vtcs_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_rsk_release, KEY_RSK, KEY_EVENT_UP);            

        /* depend on BGcall request, it still need work */
        /* call will be blocked after press lsk */
        g_mmi_vtcs_cntx.touch_vk.is_usable = MMI_TRUE; 
        mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF);
        SetGroupKeyHandler(mmi_ucm_vt_pre_entry_new_call, (U16*)PresentAllDialerKeys, TOTAL_DIALER_KEYS, KEY_EVENT_DOWN);
        
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */

#ifdef MMI_VTCS_UT_DEBUG
    if (g_mmi_vtcs_cntx.is_ut)
    {
        //return;
    }
#endif

    /* basic icons */
#ifdef __MMI_VTCS_OP01__
    g_mmi_vtcs_cntx.touch_brightness_up.is_usable = MMI_TRUE;    
    g_mmi_vtcs_cntx.touch_brightness_down.is_usable = MMI_TRUE;    
    g_mmi_vtcs_cntx.touch_fullscreen.is_usable = MMI_TRUE;   
#endif
    SetKeyHandler(mmi_vtcs_camera_key_press, MMI_VTCS_CAMERA_KEY, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vtcs_camera_key_release, MMI_VTCS_CAMERA_KEY, KEY_EVENT_UP);
    g_mmi_vtcs_cntx.touch_camera.is_usable = MMI_TRUE;    

    if (mmi_ucm_vt_get_incall_screen_mode() == MMI_UCM_VT_INCALL_SCREEN_MODE_INCALL)
    {
        /* mic and speaker can only adjust when in call */
        SetKeyHandler(mmi_vtcs_mic_key_press, MMI_VTCS_MIC_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_mic_key_release, MMI_VTCS_MIC_KEY, KEY_EVENT_UP);
        g_mmi_vtcs_cntx.touch_mic.is_usable = MMI_TRUE;    

        SetKeyHandler(mmi_vtcs_speaker_key_press, MMI_VTCS_SPEAKER_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_speaker_key_release, MMI_VTCS_SPEAKER_KEY, KEY_EVENT_UP);
        g_mmi_vtcs_cntx.touch_speaker.is_usable = MMI_TRUE;    
    }

    SetKeyHandler(mmi_vtcs_aud_rec_key_press, MMI_VTCS_AUD_REC_KEY, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vtcs_aud_rec_key_release, MMI_VTCS_AUD_REC_KEY, KEY_EVENT_UP);
    g_mmi_vtcs_cntx.touch_aud_rec.is_usable = MMI_TRUE;   

    /* snapshot */
    if(mmi_ucm_vt_get_incall_screen_mode() == MMI_UCM_VT_INCALL_SCREEN_MODE_INCALL)    
    {
    #if defined(__USB_IN_NORMAL_MODE__)
        if (!srv_usb_is_in_mass_storage_mode())
        {
            SetKeyHandler(mmi_vtcs_snapshot_key_press, KEY_CAMERA, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vtcs_snapshot_key_release, KEY_CAMERA, KEY_EVENT_UP);          
            g_mmi_vtcs_cntx.touch_snapshot.is_usable = MMI_TRUE;   
        }
    #endif /* defined(__USB_IN_NORMAL_MODE__) */     
	if(!g_mmi_vtcs_cntx.is_fullscreen_state && 
		g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_TIME_ICON)
	{
		if(wgui_softkey_is_csk_enabled())
		{
			SetKeyHandler(mmi_vtcs_snapshot_key_press, KEY_CSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vtcs_snapshot_key_release, KEY_CSK, KEY_EVENT_UP);          
            g_mmi_vtcs_cntx.touch_snapshot.is_usable = MMI_TRUE; 
		}
	}
    }

    
    /* EV, Zoom, Vol */
    /* disable inc/dec/scroll touch */
    g_mmi_vtcs_cntx.touch_inc.is_usable = MMI_FALSE;
    g_mmi_vtcs_cntx.touch_dec.is_usable = MMI_FALSE;     
    g_mmi_vtcs_cntx.touch_slider.is_usable = MMI_FALSE;       

#ifdef __MMI_UCM_VT_FEATURE_TOUCH__
    /* if has touch screen, show ev, zoom icon, for user to click to active scroll bar */

    if (g_mmi_vtcs_cntx.camera_state != MMI_VT_CAMERA_OFF)
    {
        /* camera on */
        g_mmi_vtcs_cntx.touch_ev.is_usable = MMI_TRUE;         
        g_mmi_vtcs_cntx.touch_zoom.is_usable = MMI_TRUE;
    #ifdef __MMI_VTCS_OP01__
        g_mmi_vtcs_cntx.touch_contrast.is_usable = MMI_TRUE;        
    #endif
    }
    else
    {
        /* camera off */
        g_mmi_vtcs_cntx.touch_ev.is_usable = MMI_FALSE;         
        g_mmi_vtcs_cntx.touch_zoom.is_usable = MMI_FALSE;
    #ifdef __MMI_VTCS_OP01__
        g_mmi_vtcs_cntx.touch_contrast.is_usable = MMI_FALSE;          
    #endif
    }
    
    g_mmi_vtcs_cntx.touch_vk.is_usable = MMI_TRUE;   

    g_mmi_vtcs_cntx.touch_vk_0.is_usable = MMI_TRUE;   
    g_mmi_vtcs_cntx.touch_vk_1.is_usable = MMI_TRUE;    
    g_mmi_vtcs_cntx.touch_vk_2.is_usable = MMI_TRUE;
    g_mmi_vtcs_cntx.touch_vk_3.is_usable = MMI_TRUE;
    g_mmi_vtcs_cntx.touch_vk_4.is_usable = MMI_TRUE;
    g_mmi_vtcs_cntx.touch_vk_5.is_usable = MMI_TRUE;
    g_mmi_vtcs_cntx.touch_vk_6.is_usable = MMI_TRUE;
    g_mmi_vtcs_cntx.touch_vk_7.is_usable = MMI_TRUE;    
    g_mmi_vtcs_cntx.touch_vk_8.is_usable = MMI_TRUE;    
    g_mmi_vtcs_cntx.touch_vk_9.is_usable = MMI_TRUE;        
    g_mmi_vtcs_cntx.touch_vk_star.is_usable = MMI_TRUE;            
    g_mmi_vtcs_cntx.touch_vk_pound.is_usable = MMI_TRUE;                
    
#else /* __MMI_UCM_VT_FEATURE_TOUCH__ */
    g_mmi_vtcs_cntx.touch_ev.is_usable = MMI_FALSE;         
    g_mmi_vtcs_cntx.touch_zoom.is_usable = MMI_FALSE; 
    g_mmi_vtcs_cntx.touch_vk.is_usable = MMI_FALSE;    

    g_mmi_vtcs_cntx.touch_vk_0.is_usable = MMI_FALSE;   
    g_mmi_vtcs_cntx.touch_vk_1.is_usable = MMI_FALSE;    
    g_mmi_vtcs_cntx.touch_vk_2.is_usable = MMI_FALSE;
    g_mmi_vtcs_cntx.touch_vk_3.is_usable = MMI_FALSE;
    g_mmi_vtcs_cntx.touch_vk_4.is_usable = MMI_FALSE;
    g_mmi_vtcs_cntx.touch_vk_5.is_usable = MMI_FALSE;
    g_mmi_vtcs_cntx.touch_vk_6.is_usable = MMI_FALSE;
    g_mmi_vtcs_cntx.touch_vk_7.is_usable = MMI_FALSE;    
    g_mmi_vtcs_cntx.touch_vk_8.is_usable = MMI_FALSE;    
    g_mmi_vtcs_cntx.touch_vk_9.is_usable = MMI_FALSE;        
    g_mmi_vtcs_cntx.touch_vk_star.is_usable = MMI_FALSE;            
    g_mmi_vtcs_cntx.touch_vk_pound.is_usable = MMI_FALSE;  
    
#endif /* __MMI_UCM_VT_FEATURE_TOUCH__ */

    if (g_mmi_vtcs_cntx.camera_state != MMI_VT_CAMERA_OFF)
    {
        SetKeyHandler(mmi_vtcs_ev_inc_key_press, MMI_VTCS_EV_INC_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_ev_inc_key_release, MMI_VTCS_EV_INC_KEY, KEY_EVENT_UP);
        SetKeyHandler(mmi_vtcs_ev_dec_key_press, MMI_VTCS_EV_DEC_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_ev_dec_key_release, MMI_VTCS_EV_DEC_KEY, KEY_EVENT_UP);    
        
        SetKeyHandler(mmi_vtcs_zoom_in_key_press, MMI_VTCS_ZOOM_IN_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_zoom_in_key_release, MMI_VTCS_ZOOM_IN_KEY, KEY_EVENT_UP);
        SetKeyHandler(mmi_vtcs_zoom_out_key_press, MMI_VTCS_ZOOM_OUT_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_zoom_out_key_release, MMI_VTCS_ZOOM_OUT_KEY, KEY_EVENT_UP);    
    }

    if (mmi_ucm_vt_get_incall_screen_mode() == MMI_UCM_VT_INCALL_SCREEN_MODE_INCALL)
    {
        /* only incall can adjust volume */
        SetKeyDownHandler(mmi_vtcs_vol_up_key_press, MMI_VTCS_VOL_UP_KEY);
        SetKeyUpHandler(mmi_vtcs_vol_up_key_release, MMI_VTCS_VOL_UP_KEY);
        SetKeyDownHandler(mmi_vtcs_vol_down_key_press, MMI_VTCS_VOL_DOWN_KEY);
        SetKeyUpHandler(mmi_vtcs_vol_down_key_release, MMI_VTCS_VOL_DOWN_KEY);
        SetKeyLongpressHandler(NULL, MMI_VTCS_VOL_DOWN_KEY);
        SetKeyLongpressHandler(NULL, MMI_VTCS_VOL_UP_KEY);
        SetKeyRepeatHandler(NULL, MMI_VTCS_VOL_DOWN_KEY);
        SetKeyRepeatHandler(NULL, MMI_VTCS_VOL_UP_KEY);
    }
   
    /* softkeys */
    SetKeyHandler(mmi_vtcs_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vtcs_lsk_release, KEY_LSK, KEY_EVENT_UP);    
    
#ifdef __MMI_BT_HP_SUPPORT__
    if (!srv_bt_cm_is_incall_aud_swap2bt())
    {
        /* if do not use bt, rsk will toggle hand-held / hand-free */
        SetKeyHandler(mmi_vtcs_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_rsk_release, KEY_RSK, KEY_EVENT_UP);    
    }
#else
    SetKeyHandler(mmi_vtcs_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vtcs_rsk_release, KEY_RSK, KEY_EVENT_UP);  
#endif


    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) > 0)
    {
        mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF);
        SetGroupKeyHandler(mmi_vtcs_dtmf_key_down, (U16*)PresentAllDialerKeys, TOTAL_DIALER_KEYS, KEY_EVENT_DOWN);
        SetGroupKeyHandler(mmi_vtcs_dtmf_key_up, (U16*)PresentAllDialerKeys, TOTAL_DIALER_KEYS, KEY_EVENT_UP);
        g_mmi_vtcs_cntx.touch_vk.is_usable = MMI_TRUE;           
    }
    else
    {
        mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF);
        SetGroupKeyHandler(mmi_ucm_vt_pre_entry_new_call, (U16*)PresentAllDialerKeys, TOTAL_DIALER_KEYS, KEY_EVENT_DOWN);
    }

    if(mmi_ucm_vt_get_incall_screen_mode() == MMI_UCM_VT_INCALL_SCREEN_MODE_INCALL)
    {
        SetKeyHandler(mmi_ucm_in_call_endkey, KEY_END, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_snapshot_key_press
 * DESCRIPTION
 *  Snapshot key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_snapshot_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_SNAPSHOT_KEY_PRESS,0); 
    
    if (g_mmi_vtcs_cntx.touch_snapshot.is_press)
    {
        /* already pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_SNAPSHOT_KEY_PRESS,1); 
        return;
    }
    
    /* key camera may be pressed in VK panel and it should not be shown */    
    if(g_mmi_vtcs_cntx.panel_state != MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
    {
    g_mmi_vtcs_cntx.touch_snapshot.is_press = KAL_TRUE;
    mmi_vtcs_draw_snapshot_icon();
    mmi_vtcs_blt();
    }        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_snapshot_key_release
 * DESCRIPTION
 *  Snapshot key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_snapshot_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR buf_pathname[SRV_FMGR_PATH_BUFFER_SIZE];
    CHAR buf_filename[SRV_FMGR_PATH_BUFFER_SIZE];
    S32 create_result;
    MDI_RESULT snap_ret;
    gdi_handle real_sub_handle;
    gdi_handle real_main_handle;        
    S32 image_width, image_height;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_SNAPSHOT_KEY_RELEASE,0); 
    if (!g_mmi_vtcs_cntx.touch_snapshot.is_press)
    {
        /* not pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_SNAPSHOT_KEY_RELEASE,1); 
        return;
    }
    
    /* key camera may be pressed in VK panel and it should not be shown */
    if(g_mmi_vtcs_cntx.panel_state != MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
    {
        g_mmi_vtcs_cntx.touch_snapshot.is_press = KAL_FALSE;
        mmi_vtcs_draw_snapshot_icon();
        mmi_vtcs_blt();
    }
    
    memset(buf_pathname, 0, SRV_FMGR_PATH_BUFFER_SIZE);

    /* mmi_imgview_get_storage_file_path(buf_pathname);
    create_result = mmi_imgview_create_file_dir(buf_pathname); */
    #ifdef __MMI_IMAGE_VIEWER__
    	create_result = mmi_imgview_get_storage_file_path((WCHAR*)buf_pathname);
	#else
	    create_result = -1;
	#endif

    /* create directory failed */
    if (create_result < 0)
    {
        mmi_vtcs_display_popup(srv_fmgr_fs_error_get_string(create_result), MMI_EVENT_FAILURE);
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        return;
    }
   
    /* get file name snapshot */
    #ifdef __MMI_VIDEO_PLY_SNAPSHOT_SUPPORT__
        mmi_media_app_get_next_snapshot_filename(buf_filename, buf_pathname);
    #else
    {
        g_mmi_vtcs_cntx.mode = MMI_VTCS_DISPLAY_MODE_NONE;  
        mmi_vtcs_display_popup(FMGR_FS_ROOT_DIR_FULL_TEXT, MMI_EVENT_FAILURE);
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        return;    
    }
    #endif

    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.snapshot_layer_handle);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_BLUE);
    gdi_layer_clear(GDI_COLOR_BLUE);
    gdi_image_draw_id(0, 0, IMG_ID_UCM_VT_SNAPSHOTING);
    gdi_layer_pop_and_restore_active();    
    
    g_mmi_vtcs_cntx.is_snapshot = MMI_TRUE;


    g_mmi_vtcs_cntx.is_snapshot = MMI_FALSE;    

    if(g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
       g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||
       g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4 ||
       g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5 )
    {
        real_sub_handle = g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle;
    }
    else
    {
        real_sub_handle = g_mmi_vtcs_cntx.sub_wnd_layer_handle;    
    }
    if(g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
       g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||
       g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 ||
       g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_6 )
    {
        real_main_handle = g_mmi_vtcs_cntx.main_wnd_hw_layer_handle;
    }
    else
    {
        real_main_handle = g_mmi_vtcs_cntx.main_wnd_layer_handle;    
    }

    if (g_mmi_vtcs_cntx.is_hide_sub)
    {
        /* hide sub, move sub window to lowest */
        gdi_layer_set_blt_layer(
            real_sub_handle,                        /* 0 */
            real_main_handle,                       /* 1 */
            g_mmi_vtcs_cntx.skin_layer_handle,      /* 2 */
            g_mmi_vtcs_cntx.snapshot_layer_handle); /* 3 */
    }
    else
    {
        /* do not hide sub, move sub window in front of main window */
        gdi_layer_set_blt_layer(
            real_main_handle,                       /* 0 */
            real_sub_handle,                        /* 1 */
            g_mmi_vtcs_cntx.skin_layer_handle,      /* 2 */
            g_mmi_vtcs_cntx.snapshot_layer_handle); /* 3 */
    }

    if(g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 || g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3)
    {
        gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.snapshot_layer_handle);        
        gdi_image_get_dimension_id(IMG_ID_UCM_VT_SNAPSHOTING, &image_width, &image_height);
        gdi_layer_set_position(
            g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_x + ((g_mmi_vtcs_skin_cntx.main_wnd_rect.width - image_width) >> 1),
            g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_y + ((g_mmi_vtcs_skin_cntx.main_wnd_rect.height - image_height) >> 1)
        );
        gdi_layer_pop_and_restore_active();          
    }
    else if(g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 || g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4)
    {
        gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.snapshot_layer_handle);        
        gdi_image_get_dimension_id(IMG_ID_UCM_VT_SNAPSHOTING, &image_width, &image_height);
        gdi_layer_set_position(
            g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_x + ((g_mmi_vtcs_skin_cntx.sub_wnd_rect.width - image_width) >> 1),
            g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_y + ((g_mmi_vtcs_skin_cntx.sub_wnd_rect.height - image_height) >> 1)
        );
        gdi_layer_pop_and_restore_active();                  
    }

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    /* snapshot - save to file */   

    /* Snapshot Content Layer */    
    if(g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 || g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3)
    {
        gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.main_wnd_layer_handle);
        gdi_layer_get_buffer_ptr((U8**)&g_mmi_vtcs_cntx.bg_mem_ptr);         
        gdi_layer_pop_and_restore_active();    
        
        gdi_layer_create_using_outside_memory(
            g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_x,
            g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_y,    
            g_mmi_vtcs_skin_cntx.main_wnd_rect.width,    
            g_mmi_vtcs_skin_cntx.main_wnd_rect.height,       
            &g_mmi_vtcs_cntx.bg_main_wnd_layer_handle,   
            (PU8)g_mmi_vtcs_cntx.bg_mem_ptr,
            (S32)g_mmi_vtcs_skin_cntx.main_wnd_rect.width * g_mmi_vtcs_skin_cntx.main_wnd_rect.height * 2);   

        mdi_video_tel_get_peer_content((U8 *)g_mmi_vtcs_cntx.bg_mem_ptr, g_mmi_vtcs_skin_cntx.main_wnd_rect.width * g_mmi_vtcs_skin_cntx.main_wnd_rect.height * 2);          

        gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.snapshot_layer_handle);        
        gdi_image_get_dimension_id(IMG_ID_UCM_VT_SNAPSHOTING, &image_width, &image_height);
        gdi_layer_set_position(
            g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_x + ((g_mmi_vtcs_skin_cntx.main_wnd_rect.width - image_width) >> 1),
            g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_y + ((g_mmi_vtcs_skin_cntx.main_wnd_rect.height - image_height) >> 1)
        );
        gdi_layer_pop_and_restore_active();          
    }
    else if(g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 || g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4)
    {
        gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.sub_wnd_layer_handle);
        gdi_layer_get_buffer_ptr((U8**)&g_mmi_vtcs_cntx.bg_mem_ptr);         
        gdi_layer_pop_and_restore_active();    
        
        gdi_layer_create_using_outside_memory(
            g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_x,
            g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_y,    
            g_mmi_vtcs_skin_cntx.sub_wnd_rect.width,    
            g_mmi_vtcs_skin_cntx.sub_wnd_rect.height,       
            &g_mmi_vtcs_cntx.bg_main_wnd_layer_handle,   
            (PU8)g_mmi_vtcs_cntx.bg_mem_ptr,
            (S32)g_mmi_vtcs_skin_cntx.sub_wnd_rect.width * g_mmi_vtcs_skin_cntx.sub_wnd_rect.height * 2);          
        
        mdi_video_tel_get_peer_content((U8 *)g_mmi_vtcs_cntx.bg_mem_ptr, g_mmi_vtcs_skin_cntx.sub_wnd_rect.width * g_mmi_vtcs_skin_cntx.sub_wnd_rect.height * 2);                     

        gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.snapshot_layer_handle);        
        gdi_image_get_dimension_id(IMG_ID_UCM_VT_SNAPSHOTING, &image_width, &image_height);
        gdi_layer_set_position(
            g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_x + ((g_mmi_vtcs_skin_cntx.sub_wnd_rect.width - image_width) >> 1),
            g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_y + ((g_mmi_vtcs_skin_cntx.sub_wnd_rect.height - image_height) >> 1)
        );
        gdi_layer_pop_and_restore_active();                  
    }
    else
    {
        // no snapshot if not in call
        ASSERT(0);
    }           
    snap_ret = mdi_video_ply_snapshot(g_mmi_vtcs_cntx.bg_main_wnd_layer_handle, buf_filename);

    gdi_layer_free(g_mmi_vtcs_cntx.bg_main_wnd_layer_handle);    
    g_mmi_vtcs_cntx.bg_main_wnd_layer_handle = GDI_LAYER_EMPTY_HANDLE;

    if(snap_ret != 0)
    {
        gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.snapshot_layer_handle);
        gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_BLUE);
        gdi_layer_clear(GDI_COLOR_BLUE);
        gdi_image_draw_id(0, 0, IMG_ID_UCM_VT_SNAPSHOTING_FAIL);
        gdi_layer_pop_and_restore_active();        
    }
    else
    {
        gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.snapshot_layer_handle);
        gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_BLUE);
        gdi_layer_clear(GDI_COLOR_BLUE);
        gdi_image_draw_id(0, 0, IMG_ID_UCM_VT_SNAPSHOTING);
        gdi_layer_pop_and_restore_active();    
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
    /* let snapshot icon show 200 ms */
    kal_sleep_task(50);

    /* start play again */
    mmi_vtcs_config_layer_seq();
    mmi_vtcs_blt();

    /* avoid input to many key event */
    ClearKeyEvents();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_camera_key_press
 * DESCRIPTION
 *  Camera key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_camera_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_CAMERA_KEY_PRESS,0); 
    if (g_mmi_vtcs_cntx.touch_camera.is_press)
    {
        /* already pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_CAMERA_KEY_PRESS,1); 
        return;
    }
    
    g_mmi_vtcs_cntx.touch_camera.is_press = KAL_TRUE;
    mmi_vtcs_draw_camera_icon();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_camera_key_release
 * DESCRIPTION
 *  Camera key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_camera_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_turn_on = MMI_FALSE;
    MMI_BOOL is_turn_off = MMI_FALSE;
	#ifdef __OP01__
	#if defined(__MMI_FTE_VT_ENHANCE__)
	S32 offset_x; 
	S32 offset_y;
	#endif
	#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_CAMERA_KEY_RELEASE,0); 
    if (!g_mmi_vtcs_cntx.touch_camera.is_press)
    {
        /* not pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_CAMERA_KEY_RELEASE,1);
        return;
    }
    
    is_turn_on = MMI_FALSE;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_CAMERA_KEY_RELEASE_MODE,g_mmi_vtcs_cntx.camera_state);
    
#ifdef __MMI_UCM_VT_DUAL_CAMERA__

    /* Dule Camera */
    if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_FRONT)
    {
        g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_BACK;
        is_turn_off = MMI_FALSE;
        is_turn_on = MMI_FALSE;    

        g_mmi_vtcs_cntx.contrast_state = MMI_VT_CONTRAST_NORMAL;        

        /* TODO: Discuss with Tony to modify API naiming */
        mmi_ucm_vt_set_main_camera_status(MMI_TRUE);
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_BACK)
    {
        g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_OFF;
        is_turn_off = MMI_TRUE;
        is_turn_on = MMI_FALSE;

        g_mmi_vtcs_cntx.contrast_state = MMI_VT_CONTRAST_NORMAL;
        /* turn off */
        mmi_ucm_vt_set_camera_status(MMI_FALSE);
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_OFF)
    {
        g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_FRONT;
        is_turn_off = MMI_FALSE;
        is_turn_on = MMI_TRUE;        
        
        g_mmi_vtcs_cntx.contrast_state = MMI_VT_CONTRAST_NORMAL;        

        /* turn on */
        mmi_ucm_vt_set_camera_status(MMI_TRUE);
        mmi_ucm_vt_set_main_camera_status(MMI_FALSE);
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }

#else /* __MMI_UCM_VT_DUAL_CAMERA__ */

    /* Single Camera */
    if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_ON)
    {
        g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_OFF;
        is_turn_off = MMI_TRUE;
        is_turn_on = MMI_FALSE;      
        
        /* turn off */
        mmi_ucm_vt_set_camera_status(MMI_FALSE);        
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_OFF)
    {
        g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_ON;
        is_turn_off = MMI_FALSE;
        is_turn_on = MMI_TRUE;  

        /* turn on */
        mmi_ucm_vt_set_camera_status(MMI_TRUE);        
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }
#endif /* __MMI_UCM_VT_DUAL_CAMERA__ */

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_CAMERA_KEY_RELEASE_MODE,g_mmi_vtcs_cntx.camera_state);

    g_mmi_vtcs_cntx.touch_camera.is_press = KAL_FALSE;
    mmi_vtcs_draw_camera_icon();
    mmi_vtcs_blt();


    /* Mode Transition */
    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_6 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5)
    {
        if(is_turn_off && ! is_turn_on)
        {
            mmi_vtcs_stop_display();        
        }  
        else
        {                  
            mmi_vtcs_pause_display();
        }

    }   
    else
    {   
        mmi_vtcs_pause_display();
    }        
    mmi_vtcs_config_layer_seq();
    
    if(g_mmi_vtcs_cntx.camera_state != MMI_VT_CAMERA_OFF)
    {    
        /* camera changed, init cap again */        
        if(g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_BACK)
            mmi_vtcs_zoom_init_cap(MMI_FALSE);    
        else    
            mmi_vtcs_zoom_init_cap(MMI_TRUE);            
        mmi_vtcs_ev_init_cap();        
    }
            
    if (is_turn_on && !is_turn_off)
    {
        /* turn on */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_CAMERA_KEY_RELEASE_TURN_ON);
        
        if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3)
        {
            /* sub image -> sub preview */
            mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_1);            
        }
        else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4)
        {
            /* main image -> main preview */
            mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_2);      
        }
        else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_7)
        {
            /* sub image -> sub preview */
            mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_5);               
        }
        else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_8)
        {
            /* main image -> main preview */
            mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_6);   
        }        

        /* enable ev/zoom  */
    #ifdef __MMI_UCM_VT_FEATURE_TOUCH__        
        g_mmi_vtcs_cntx.touch_ev.is_usable = MMI_TRUE;         
        g_mmi_vtcs_cntx.touch_zoom.is_usable = MMI_TRUE;
    #ifdef __MMI_VTCS_OP01__
        g_mmi_vtcs_cntx.touch_contrast.is_usable = MMI_TRUE;          
    #endif
    #else
        g_mmi_vtcs_cntx.touch_ev.is_usable = MMI_FALSE;         
        g_mmi_vtcs_cntx.touch_zoom.is_usable = MMI_FALSE;
    #ifdef __MMI_VTCS_OP01__
        g_mmi_vtcs_cntx.touch_contrast.is_usable = MMI_FALSE;          
    #endif
    #endif 
    
        SetKeyHandler(mmi_vtcs_ev_inc_key_press, MMI_VTCS_EV_INC_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_ev_inc_key_release, MMI_VTCS_EV_INC_KEY, KEY_EVENT_UP);
        SetKeyHandler(mmi_vtcs_ev_dec_key_press, MMI_VTCS_EV_DEC_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_ev_dec_key_release, MMI_VTCS_EV_DEC_KEY, KEY_EVENT_UP);    
    
        SetKeyHandler(mmi_vtcs_zoom_in_key_press, MMI_VTCS_ZOOM_IN_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_zoom_in_key_release, MMI_VTCS_ZOOM_IN_KEY, KEY_EVENT_UP);
        SetKeyHandler(mmi_vtcs_zoom_out_key_press, MMI_VTCS_ZOOM_OUT_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_zoom_out_key_release, MMI_VTCS_ZOOM_OUT_KEY, KEY_EVENT_UP);   
        
    }
    else if (is_turn_off && ! is_turn_on)
    {
        /* trun off */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_CAMERA_KEY_RELEASE_TURN_OFF);
        
        if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1)
        {
            /* sub preview -> sub image */
            mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_3);               
            mmi_vtcs_draw_sub_wnd();  
        }
        else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2)
        {
            /* main preview -> main image */
            mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_4);               
            mmi_vtcs_draw_main_wnd();
        }
        else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5)
        {
            /* sub preview -> sub image */ 
            mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_7);   
            mmi_vtcs_draw_sub_wnd();    
        }
        else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_6)
        {
            /* main preview -> main image */
            mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_8);               
            mmi_vtcs_draw_main_wnd();            
        }
        mmi_vtcs_draw_encode_layer();        
        
        /* disable ev/zoom  */
        g_mmi_vtcs_cntx.touch_ev.is_usable = MMI_FALSE;         
        g_mmi_vtcs_cntx.touch_zoom.is_usable = MMI_FALSE;
    #ifdef __MMI_VTCS_OP01__
        g_mmi_vtcs_cntx.touch_contrast.is_usable = MMI_FALSE;  
    #endif
    
        ClearKeyHandler(MMI_VTCS_EV_INC_KEY, KEY_EVENT_DOWN);
        ClearKeyHandler(MMI_VTCS_EV_INC_KEY, KEY_EVENT_UP);
        ClearKeyHandler(MMI_VTCS_EV_DEC_KEY, KEY_EVENT_DOWN);
        ClearKeyHandler(MMI_VTCS_EV_DEC_KEY, KEY_EVENT_UP);    
    
        ClearKeyHandler(MMI_VTCS_ZOOM_IN_KEY, KEY_EVENT_DOWN);
        ClearKeyHandler(MMI_VTCS_ZOOM_IN_KEY, KEY_EVENT_UP);
        ClearKeyHandler(MMI_VTCS_ZOOM_OUT_KEY, KEY_EVENT_DOWN);
        ClearKeyHandler(MMI_VTCS_ZOOM_OUT_KEY, KEY_EVENT_UP);    
        g_mmi_vtcs_cntx.panel_state = MMI_VTCS_PANEL_STATE_TIME_ICON;

    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_CAMERA_KEY_RELEASE_SWITCH);    
        /* do not change */
    }

    mmi_vtcs_config_layer_seq();
#ifdef __OP01__
	#if defined(__MMI_FTE_VT_ENHANCE__)
	mmi_vtcs_draw_body();
	mmi_vtcs_open_main_wnd_hole();
    mmi_vtcs_draw_brightness_down_icon();
    mmi_vtcs_draw_brightness_up_icon();
    mmi_vtcs_draw_contrast_icon();
    #endif
#endif
    mmi_vtcs_draw_panel();
#ifdef __MMI_VTCS_FTE__
    mmi_vtcs_open_sub_wnd_hole();   
#endif
/*
#ifdef __OP01__
	#if defined(__MMI_FTE_VT_ENHANCE__)
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
	
	gdi_layer_get_position(&offset_x, &offset_y);

    offset_x = g_mmi_vtcs_skin_cntx.contrast_bg.offset_x - offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.contrast_bg.offset_y - offset_y;    
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_CONTRAST_BG);
    
    gdi_layer_pop_and_restore_active();
    mmi_vtcs_draw_brightness_down_icon();
    mmi_vtcs_draw_brightness_up_icon();
    mmi_vtcs_draw_contrast_icon();
    #endif
#endif
*/ 
    mmi_vtcs_blt();          
    mmi_vtcs_draw_main_wnd();
	mmi_vtcs_draw_sub_wnd();

    if(g_mmi_vtcs_cntx.has_open_MED)
    {
        /* start preview with 3a */
        if (mmi_vtcs_resume_display(MMI_TRUE) != MDI_RES_VDOTEL_SUCCEED)
        {
            /* camera error */
            mmi_vtcs_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            return;
        }
    }
    else
    {
        /* start preview with 3a */
        if (mmi_vtcs_start_display(MMI_TRUE) != MDI_RES_VDOTEL_SUCCEED)
        {
            /* camera error */
            mmi_vtcs_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            return;
        }
    }  
 }


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_mic_key_press
 * DESCRIPTION
 *  MIC key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_mic_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_MIC_KEY_PRESS,0);  
    if (g_mmi_vtcs_cntx.touch_mic.is_press)
    {
        /* already pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_MIC_KEY_PRESS,1);  
        return;
    }
    
    g_mmi_vtcs_cntx.touch_mic.is_press = KAL_TRUE;
    mmi_vtcs_draw_mic_icon();
    mmi_vtcs_blt();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_mic_key_release
 * DESCRIPTION
 *  MIC key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_mic_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_MIC_KEY_RELEASE,0);  
    if (!g_mmi_vtcs_cntx.touch_mic.is_press)
    {
        /* not pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_MIC_KEY_RELEASE,1);  
        return;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_MIC_KEY_RELEASE_MIC_STATE,g_mmi_vtcs_cntx.mic_state); 
    if (g_mmi_vtcs_cntx.mic_state == MMI_VT_MIC_ON)
    {
        g_mmi_vtcs_cntx.mic_state = MMI_VT_MIC_OFF;
        mmi_ucm_vt_set_mic_status(MMI_FALSE);
    }
    else if (g_mmi_vtcs_cntx.mic_state == MMI_VT_MIC_OFF)
    {
        g_mmi_vtcs_cntx.mic_state = MMI_VT_MIC_ON;
        mmi_ucm_vt_set_mic_status(MMI_TRUE);        
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }

    
    g_mmi_vtcs_cntx.touch_mic.is_press = KAL_FALSE;
    mmi_vtcs_draw_mic_icon();
    mmi_vtcs_blt();


}

#ifdef __MMI_VTCS_OP01__
/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_brightness_up_key_press
 * DESCRIPTION
 *  Speaker key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_brightness_up_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mmi_vtcs_cntx.touch_brightness_up.is_press)
    {
        /* already pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_brightness_up.is_press = KAL_TRUE;
    mmi_vtcs_draw_brightness_up_icon();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_brightness_up_key_release
 * DESCRIPTION
 *  Speaker key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_brightness_up_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_vtcs_cntx.touch_brightness_up.is_press)
    {
        /* not pressed */
        return;
    }
    
    if(g_mmi_vtcs_cntx.brightness_state < MMI_VT_BRIGHTNESS_LEVEL5)
        g_mmi_vtcs_cntx.brightness_state++;
    srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD, g_mmi_vtcs_cntx.brightness_state); 

    
    g_mmi_vtcs_cntx.touch_brightness_up.is_press = KAL_FALSE;
    mmi_vtcs_draw_brightness_up_icon();
    mmi_vtcs_blt();


}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_brightness_down_key_press
 * DESCRIPTION
 *  Speaker key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_brightness_down_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mmi_vtcs_cntx.touch_brightness_down.is_press)
    {
        /* already pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_brightness_down.is_press = KAL_TRUE;
    mmi_vtcs_draw_brightness_down_icon();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_brightness_down_key_release
 * DESCRIPTION
 *  Speaker key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_brightness_down_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_vtcs_cntx.touch_brightness_down.is_press)
    {
        /* not pressed */
        return;
    }
    

    if(g_mmi_vtcs_cntx.brightness_state > MMI_VT_BRIGHTNESS_LEVEL1)
        g_mmi_vtcs_cntx.brightness_state--;
    
    srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD, g_mmi_vtcs_cntx.brightness_state); 
    
    g_mmi_vtcs_cntx.touch_brightness_down.is_press = KAL_FALSE;
    mmi_vtcs_draw_brightness_down_icon();
    mmi_vtcs_blt();


}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_contrast_key_press
 * DESCRIPTION
 *  Speaker key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_contrast_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mmi_vtcs_cntx.touch_contrast.is_press)
    {
        /* already pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_contrast.is_press = KAL_TRUE;
    mmi_vtcs_draw_contrast_icon();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_contrast_key_release
 * DESCRIPTION
 *  Speaker key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_contrast_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	#if defined(__MMI_FTE_VT_ENHANCE__)
	S32 offset_x; 
    S32 offset_y; 
	#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_vtcs_cntx.touch_contrast.is_press)
    {
        /* not pressed */
        return;
    }

    if (g_mmi_vtcs_cntx.contrast_state == MMI_VT_CONTRAST_NORMAL)
    {
        g_mmi_vtcs_cntx.contrast_state = MMI_VT_CONTRAST_REDUCE;
        
        if(g_mmi_vtcs_cntx.is_enc_path_built)        
            mdi_video_tel_update_para_contrast(MDI_CAMERA_IE_LEVEL_LOW);   

    }
    else if (g_mmi_vtcs_cntx.contrast_state == MMI_VT_CONTRAST_REDUCE)
    {
        g_mmi_vtcs_cntx.contrast_state = MMI_VT_CONTRAST_ENHANCE;
        if(g_mmi_vtcs_cntx.is_enc_path_built)        
            mdi_video_tel_update_para_contrast(MDI_CAMERA_IE_LEVEL_HIGH);  

    }
    else if (g_mmi_vtcs_cntx.contrast_state == MMI_VT_CONTRAST_ENHANCE)
    {
        g_mmi_vtcs_cntx.contrast_state = MMI_VT_CONTRAST_NORMAL;
        if(g_mmi_vtcs_cntx.is_enc_path_built)        
            mdi_video_tel_update_para_contrast(MDI_CAMERA_IE_LEVEL_MEDIUM);  

    }    
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }
    
    g_mmi_vtcs_cntx.touch_contrast.is_press = KAL_FALSE;
	/*
	#if defined(__MMI_FTE_VT_ENHANCE__)
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
	
	gdi_layer_get_position(&offset_x, &offset_y);

    offset_x = g_mmi_vtcs_skin_cntx.contrast_bg.offset_x - offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.contrast_bg.offset_y - offset_y;    
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_CONTRAST_BG);
    
    gdi_layer_pop_and_restore_active();
	#endif
    mmi_vtcs_draw_brightness_down_icon();
    mmi_vtcs_draw_brightness_up_icon();
    */
    mmi_vtcs_draw_contrast_icon();
    mmi_vtcs_blt();


}
/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_fullscreen_key_press
 * DESCRIPTION
 *  fullscreen key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_fullscreen_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mmi_vtcs_cntx.touch_fullscreen.is_press)
    {
        /* already pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_fullscreen.is_press = KAL_TRUE;
    mmi_vtcs_draw_fullscreen_icon();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_fullscreen_key_release
 * DESCRIPTION
 *  fullscreen key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_fullscreen_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
	S32 layer_width;
	S32 layer_height;
	U16 image_id;
	U16 ret;
	gdi_handle main_layer_temp_handle = 0;
	gdi_handle sub_layer_temp_handle = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_vtcs_cntx.touch_fullscreen.is_press)
    {
        /* not pressed */
        return;
    }  
	g_mmi_vtcs_cntx.is_fullscreen_state = MMI_TRUE;
	mmi_vtcs_register_key_event();
	mmi_vtcs_pause_display();
    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_6)
	{
		main_layer_temp_handle = g_mmi_vtcs_cntx.main_wnd_hw_layer_handle;
	}
	else
	{
		main_layer_temp_handle = g_mmi_vtcs_cntx.main_wnd_layer_handle;
	}
	if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5)
	{
		sub_layer_temp_handle = g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle;
	}
	else
	{
		sub_layer_temp_handle = g_mmi_vtcs_cntx.sub_wnd_layer_handle;
	}
    g_mmi_vtcs_cntx.touch_fullscreen.is_press = KAL_FALSE;
	
	gdi_layer_push_and_set_active(main_layer_temp_handle);
	gdi_layer_resize(MMI_VTCS_MAX_WIDTH,MMI_VTCS_MAX_HEIGHT);
	//gdi_layer_clear(GDI_COLOR_BLACK);
	gdi_layer_get_dimension(&layer_width, &layer_height);
	gdi_layer_set_position(g_mmi_vtcs_skin_cntx.fullscr_main_wnd_pos.offset_x, g_mmi_vtcs_skin_cntx.fullscr_main_wnd_pos.offset_y);
	gdi_layer_pop_and_restore_active();
	gdi_layer_push_and_set_active(sub_layer_temp_handle);
	//gdi_layer_clear(GDI_COLOR_BLACK);
	gdi_layer_set_position(g_mmi_vtcs_skin_cntx.fullscr_sub_wnd_pos.offset_x, g_mmi_vtcs_skin_cntx.fullscr_sub_wnd_pos.offset_y);
	gdi_layer_pop_and_restore_active();
	mmi_vtcs_config_layer_seq();
	
	gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
	gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_skin_cntx.fullscr_skin_bg_pos.offset_x- layer_offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.fullscr_skin_bg_pos.offset_y - layer_offset_y;   

    image_id = IMG_ID_UCM_VT_FULLSCREEN_BG;
    
   gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);

    offset_x = g_mmi_vtcs_skin_cntx.fullscr_main_wnd_pos.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.fullscr_main_wnd_pos.offset_y - layer_offset_y;    

    gdi_draw_solid_rect(
        offset_x,
        offset_y,
        offset_x + MMI_VTCS_MAX_WIDTH - 1,
        offset_y + MMI_VTCS_MAX_HEIGHT - 1, 
        GDI_COLOR_TRANSPARENT);

    gdi_layer_pop_and_restore_active(); 
	mmi_vtcs_draw_status();
    mmi_vtcs_draw_title();
	gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
	mmi_vtcs_draw_time_cost();
	gdi_layer_pop_and_restore_active();
	mmi_vtcs_set_softkey(0, STR_GLOBAL_BACK);
	mmi_vtcs_draw_softkey();
	mmi_vtcs_draw_main_wnd();
	mmi_vtcs_draw_sub_wnd();
	mmi_vtcs_blt();
	if(g_mmi_vtcs_cntx.has_open_MED)
    {
        /* start preview with 3a */
		ret = mmi_vtcs_resume_display(MMI_TRUE);
	    //is_fullscreen_state = MMI_FALSE;
        if (ret != MDI_RES_VDOTEL_SUCCEED)
        {
            /* camera error */
            mmi_vtcs_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            return;
        }
    }
    else
    {
        /* start preview with 3a */
		ret = mmi_vtcs_start_display(MMI_TRUE);
	    //is_fullscreen_state = MMI_FALSE;
        if (ret != MDI_RES_VDOTEL_SUCCEED)
        {
            /* camera error */
            mmi_vtcs_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            return;
        }
    } 


}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_speaker_key_press
 * DESCRIPTION
 *  Speaker key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_speaker_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_SPEAKER_KEY_PRESS,0); 
    if (g_mmi_vtcs_cntx.touch_speaker.is_press)
    {
        /* already pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_SPEAKER_KEY_PRESS,1); 
        return;
    }
    
    g_mmi_vtcs_cntx.touch_speaker.is_press = KAL_TRUE;
    mmi_vtcs_draw_speaker_icon();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_speaker_key_release
 * DESCRIPTION
 *  Speaker key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_speaker_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_SPEAKER_KEY_RELEASE,0); 
    if (!g_mmi_vtcs_cntx.touch_speaker.is_press)
    {
        /* not pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_SPEAKER_KEY_RELEASE,1); 
        return;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_SPEAKER_KEY_RELEASE_SPEAKER_STATE,g_mmi_vtcs_cntx.speaker_state); 
    if (g_mmi_vtcs_cntx.speaker_state == MMI_VT_SPEAKER_ON)
    {
        g_mmi_vtcs_cntx.speaker_state = MMI_VT_SPEAKER_OFF;
        mmi_ucm_vt_set_speaker_status(MMI_FALSE);        
    }
    else if (g_mmi_vtcs_cntx.speaker_state == MMI_VT_SPEAKER_OFF)
    {
        g_mmi_vtcs_cntx.speaker_state = MMI_VT_SPEAKER_ON;
        mmi_ucm_vt_set_speaker_status(MMI_TRUE);                
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }
    
    g_mmi_vtcs_cntx.touch_speaker.is_press = KAL_FALSE;
    mmi_vtcs_draw_speaker_icon();
    mmi_vtcs_blt();


}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_aud_rec_key_press
 * DESCRIPTION
 *  Aud rec key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_aud_rec_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_AUD_REC_KEY_PRESS,0); 
    if (g_mmi_vtcs_cntx.touch_aud_rec.is_press)
    {
        /* already pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_AUD_REC_KEY_PRESS,1); 
        return;
    }
    
    g_mmi_vtcs_cntx.touch_aud_rec.is_press = KAL_TRUE;
    mmi_vtcs_draw_aud_rec_icon();
    mmi_vtcs_blt();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_aud_rec_key_release
 * DESCRIPTION
 *  Aud rec key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_aud_rec_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_AUD_REC_KEY_RELEASE,0);     
    if (!g_mmi_vtcs_cntx.touch_aud_rec.is_press)
    {
        /* not pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_AUD_REC_KEY_RELEASE,1); 
        return;
    }
    
    g_mmi_vtcs_cntx.touch_aud_rec.is_press = KAL_TRUE;
    mmi_vtcs_draw_aud_rec_icon();
    mmi_vtcs_blt();

    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_AUD_REC_KEY_RELEASE_AUDREC_STATE,g_mmi_vtcs_cntx.aud_rec_state); 
    if (g_mmi_vtcs_cntx.aud_rec_state == MMI_VT_AUD_REC_ON)
    {
        g_mmi_vtcs_cntx.aud_rec_state = MMI_VT_AUD_REC_OFF;
    }
    else if (g_mmi_vtcs_cntx.aud_rec_state == MMI_VT_AUD_REC_OFF)
    {
        g_mmi_vtcs_cntx.aud_rec_state = MMI_VT_AUD_REC_ON;
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ev_key_press
 * DESCRIPTION
 *  EV key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ev_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_KEY_PRESS,0); 
    if (g_mmi_vtcs_cntx.touch_ev.is_press)
    {
        /* already pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_KEY_PRESS,1); 
        return;
    }
    
    g_mmi_vtcs_cntx.touch_ev.is_press = KAL_TRUE;
    mmi_vtcs_draw_ev_icon();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ev_key_release
 * DESCRIPTION
 *  EV key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ev_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	gdi_handle t_lyr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_KEY_RELEASE,0); 
    if (!g_mmi_vtcs_cntx.touch_ev.is_press)
    {
        /* not pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_KEY_RELEASE,1); 
        return;
    }
    
    g_mmi_vtcs_cntx.touch_ev.is_press = KAL_FALSE;
    mmi_vtcs_draw_ev_icon();
    mmi_vtcs_blt();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_KEY_RELEASE_PANEL_STATE,g_mmi_vtcs_cntx.panel_state);
    if (g_mmi_vtcs_cntx.panel_state != MMI_VTCS_PANEL_STATE_SCROLL_EV)
    {

        mmi_vtcs_config_scroll(
            MMI_VTCS_PANEL_STATE_SCROLL_EV,
            IMG_ID_UCM_VT_EV_INC, 
            IMG_ID_UCM_VT_EV_DEC,        
            g_mmi_vtcs_cntx.ev_value,  
            MMI_VT_EV_TOTAL); 

        mmi_vtcs_draw_panel();
	gdi_get_alpha_blending_source_layer(&t_lyr);
	gdi_set_alpha_blending_source_layer(g_mmi_vtcs_cntx.skin_layer_handle);
    #ifdef __MMI_VTCS_FTE__
        mmi_vtcs_draw_softkey();    
    #endif
	gdi_set_alpha_blending_source_layer(t_lyr);
        mmi_vtcs_open_sub_wnd_hole();    
        mmi_vtcs_blt();     

        gui_start_timer(MMI_VTCS_CTRL_PANEL_RESTORE_DUR, mmi_vtcs_panel_restore_hdlr);         
   }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_key_press
 * DESCRIPTION
 *  Zoom key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_zoom_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_KEY_PRESS,0);
    if (g_mmi_vtcs_cntx.touch_zoom.is_press)
    {
        /* already pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_KEY_PRESS,1);        
        return;
    }
    
    g_mmi_vtcs_cntx.touch_zoom.is_press = KAL_TRUE;
    mmi_vtcs_draw_zoom_icon();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_key_release
 * DESCRIPTION
 *  EV key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_zoom_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	gdi_handle t_lyr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_KEY_RELEASE,0);
    if (!g_mmi_vtcs_cntx.touch_zoom.is_press)
    {
        /* not pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_KEY_RELEASE,1);        
        return;
    }
    
    g_mmi_vtcs_cntx.touch_zoom.is_press = KAL_FALSE;
    mmi_vtcs_draw_zoom_icon();
    mmi_vtcs_blt();

    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_KEY_RELEASE_PANEL_STATE,g_mmi_vtcs_cntx.panel_state);  
    if (g_mmi_vtcs_cntx.panel_state != MMI_VTCS_PANEL_STATE_SCROLL_ZOOM)
    {
        mmi_vtcs_config_scroll(
            MMI_VTCS_PANEL_STATE_SCROLL_ZOOM,
            IMG_ID_UCM_VT_ZOOM_IN, 
            IMG_ID_UCM_VT_ZOOM_OUT,        
            g_mmi_vtcs_cntx.zoom_step,  
            g_mmi_vtcs_cntx.zoom_max_step); 

        mmi_vtcs_draw_panel();
		gdi_get_alpha_blending_source_layer(&t_lyr);
		gdi_set_alpha_blending_source_layer(g_mmi_vtcs_cntx.skin_layer_handle);
    #ifdef __MMI_VTCS_FTE__
        mmi_vtcs_draw_softkey();    
    #endif   
		gdi_set_alpha_blending_source_layer(t_lyr);
        mmi_vtcs_open_sub_wnd_hole();    
        mmi_vtcs_blt();     
        
        gui_start_timer(MMI_VTCS_CTRL_PANEL_RESTORE_DUR, mmi_vtcs_panel_restore_hdlr);                 
   }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_vk_key_press
 * DESCRIPTION
 *  VK key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_vk_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VK_KEY_PRESS,0);
    if (g_mmi_vtcs_cntx.touch_vk.is_press)
    {
        /* already pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VK_KEY_PRESS,1);
        return;
    }
    
    g_mmi_vtcs_cntx.touch_vk.is_press = KAL_TRUE;
    mmi_vtcs_draw_vk_icon();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_dial_mailbox_address
 * DESCRIPTION
 *  make a call with user input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vtcs_dial_mailbox_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     mmi_ucm_make_call_para_struct sendkey_makecall_para; 
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
     mmi_ucm_init_call_para_for_sendkey(&sendkey_makecall_para);  /*will decide the dial type based on send key rules*/
     sendkey_makecall_para.ucs2_num_uri = (U16*)g_mmi_vtcs_cntx.input_box_buf;   
     mmi_ucm_call_launch(0, &sendkey_makecall_para);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_key_release
 * DESCRIPTION
 *  EV key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_vk_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VK_KEY_RELEASE,0);
    if (!g_mmi_vtcs_cntx.touch_vk.is_press)
    {
        /* not pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VK_KEY_RELEASE,1);
        return;
    }
    
    g_mmi_vtcs_cntx.touch_vk.is_press = KAL_FALSE;
    mmi_vtcs_draw_vk_icon();
    mmi_vtcs_blt();

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) == 0)
    {
        /* lanch dialing screen */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VK_KEY_RELEASE_NO_CALL);
        mmi_ucm_vt_pre_entry_new_call_without_input();   
        return;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VK_KEY_RELEASE_PANEL_STATE,g_mmi_vtcs_cntx.panel_state);
    if (g_mmi_vtcs_cntx.panel_state != MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
    {

        mmi_ucm_handle_sendkeys_for_call(mmi_vtcs_dial_mailbox_address,KEY_EVENT_UP);            
        
        memset(g_mmi_vtcs_cntx.input_box_buf, 0, MMI_VTCS_INPUT_BOX_BUF_SIZE);
        
    #ifndef __MMI_VTCS_FTE__
        /* start restore time */
        gui_start_timer((MMI_VTCS_CTRL_PANEL_RESTORE_DUR + 3000), mmi_vtcs_panel_restore_hdlr);      
    #endif
        g_mmi_vtcs_cntx.panel_state = MMI_VTCS_PANEL_STATE_USER_INPUT_VK;
    #ifdef __MMI_VTCS_FTE__    
        mmi_vtcs_set_softkey(NULL, STR_GLOBAL_BACK);
        g_mmi_vtcs_cntx.two_setp_ad_panel_mode = MMI_TRUE;    
    #endif
    
        mmi_vtcs_draw_panel();
#ifndef __MMI_VTCS_FTE__  
        mmi_vtcs_open_sub_wnd_hole();
        mmi_vtcs_draw_softkey(); 
#else
        mmi_vtcs_draw_softkey();   
#endif
        mmi_vtcs_blt();        
   }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ev_init_cap
 * DESCRIPTION
 *  Init ev capability 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ev_init_cap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx;
    mdi_camera_fun_info ev_cap;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_INIT_CAP,g_mmi_vtcs_cntx.camera_state);
#ifdef __MMI_UCM_VT_DUAL_CAMERA__
    if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_BACK)
    {
        mdi_video_tel_set_camera_id(MDI_VIDEO_MAIN_SENSOR);
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_FRONT)
    {
        mdi_video_tel_set_camera_id(MDI_VIDEO_SUB_SENSOR);
    }
    else
    {
        /* do nothing */
    }
#endif /* __MMI_UCM_VT_DUAL_CAMERA__ */

    
    mdi_video_tel_query_support_info(MDI_CAMERA_SETTING_EV, &ev_cap);

    if (!ev_cap.is_support)
    {
        /* shall support ev */
        MMI_ASSERT(0);
    }

    g_mmi_vtcs_cntx.ev_max_value = MMI_VT_EV_0;
    g_mmi_vtcs_cntx.ev_min_value = MMI_VT_EV_0;

    for(idx = 0; idx < ev_cap.item_count; idx++)
    {
        /* this method has some assumption that if have N4 alwasy have P4 */
        if (ev_cap.support_item[idx] == MDI_CAMERA_EV_N4)
        {
            g_mmi_vtcs_cntx.ev_max_value = MMI_VT_EV_P4;
            g_mmi_vtcs_cntx.ev_min_value = MMI_VT_EV_N4;
            g_mmi_vtcs_cntx.ev_valid_value_count = 9;
            break;
        }
        else if (ev_cap.support_item[idx] == MDI_CAMERA_EV_N3)
        {
            g_mmi_vtcs_cntx.ev_max_value = MMI_VT_EV_P3;
            g_mmi_vtcs_cntx.ev_min_value = MMI_VT_EV_N3;
            g_mmi_vtcs_cntx.ev_valid_value_count = 7;            
            break;
        }
        else if (ev_cap.support_item[idx] == MDI_CAMERA_EV_N2)
        {
            g_mmi_vtcs_cntx.ev_max_value = MMI_VT_EV_P2;
            g_mmi_vtcs_cntx.ev_min_value = MMI_VT_EV_N2;
            g_mmi_vtcs_cntx.ev_valid_value_count = 5;                        
            break;
        }            
        else if (ev_cap.support_item[idx] == MDI_CAMERA_EV_N2)
        {
            g_mmi_vtcs_cntx.ev_max_value = MMI_VT_EV_P1;
            g_mmi_vtcs_cntx.ev_min_value = MMI_VT_EV_N1;
            g_mmi_vtcs_cntx.ev_valid_value_count = 3;                                    
            break;
        }   
        else
        {
            /* check if driver's EV cap have problem */
            MMI_ASSERT(0);            
        }
    }
    g_mmi_vtcs_cntx.ev_value = MMI_VT_EV_0;
    mmi_ucm_vt_set_ev_status(g_mmi_vtcs_cntx.ev_value);  
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_INIT_CAP_PARA,g_mmi_vtcs_cntx.ev_max_value,g_mmi_vtcs_cntx.ev_min_value,g_mmi_vtcs_cntx.ev_valid_value_count);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ev_inc_cyclic
 * DESCRIPTION
 *  EV increase cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ev_inc_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_INC_CYCLIC,g_mmi_vtcs_cntx.ev_value);
    if (g_mmi_vtcs_cntx.ev_value < g_mmi_vtcs_cntx.ev_max_value)
    {
        g_mmi_vtcs_cntx.ev_value++;
        
        if(g_mmi_vtcs_cntx.is_enc_path_built)        
            mdi_video_tel_update_para_ev(mmi_vtcs_get_ev_factor());   
        
        g_mmi_vtcs_cntx.touch_inc.is_press = MMI_TRUE;
        
        mmi_vtcs_update_scroll_cur_value(g_mmi_vtcs_cntx.ev_value);  
        mmi_ucm_vt_set_ev_status(g_mmi_vtcs_cntx.ev_value);        
        mmi_vtcs_scroll_inc_press();
        mmi_vtcs_draw_panel();        
        mmi_vtcs_open_sub_wnd_hole();      
        mmi_vtcs_blt();
    }    

    gui_start_timer(200, mmi_vtcs_ev_inc_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ev_dec_cyclic
 * DESCRIPTION
 *  EV decrease cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ev_dec_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_DEC_CYCLIC,g_mmi_vtcs_cntx.ev_value);
    if (g_mmi_vtcs_cntx.ev_value > g_mmi_vtcs_cntx.ev_min_value)
    {
        g_mmi_vtcs_cntx.ev_value--;
        
        if(g_mmi_vtcs_cntx.is_enc_path_built)        
            mdi_video_tel_update_para_ev(mmi_vtcs_get_ev_factor());   
        
        g_mmi_vtcs_cntx.touch_dec.is_press = MMI_TRUE;
        
        mmi_vtcs_update_scroll_cur_value(g_mmi_vtcs_cntx.ev_value);
        mmi_ucm_vt_set_ev_status(g_mmi_vtcs_cntx.ev_value);
        mmi_vtcs_scroll_dec_press();
        mmi_vtcs_draw_panel();        
        mmi_vtcs_open_sub_wnd_hole();           
        mmi_vtcs_blt();   
    }

    gui_start_timer(200, mmi_vtcs_ev_dec_cyclic);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ev_inc_key_press
 * DESCRIPTION
 *  EV increase key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ev_inc_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_INC_KEY_PRESS,0);
    
    /* FTE VK Panel will full all screen, cannot adjust zoom/EV/Vol */
#ifdef __MMI_VTCS_FTE__
    if(g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
        return;
#endif        

    gui_cancel_timer(mmi_vtcs_panel_restore_hdlr);   

    if (g_mmi_vtcs_cntx.touch_inc.is_press)
    {
        /* already pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_INC_KEY_PRESS,1);
        return;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_INC_KEY_PRESS_PANEL_STATE,0);
    if (g_mmi_vtcs_cntx.panel_state != MMI_VTCS_PANEL_STATE_SCROLL_EV)
    {
        mmi_vtcs_config_scroll(
            MMI_VTCS_PANEL_STATE_SCROLL_EV,
            IMG_ID_UCM_VT_EV_INC, 
            IMG_ID_UCM_VT_EV_DEC,        
            g_mmi_vtcs_cntx.ev_value,  
            g_mmi_vtcs_cntx.ev_valid_value_count); 

        mmi_vtcs_draw_panel();        
#ifdef __MMI_VTCS_FTE__
        mmi_vtcs_open_sub_wnd_hole();   
        mmi_vtcs_draw_softkey();    
#endif        
        mmi_vtcs_blt();        
    }
    else
    {
        mmi_vtcs_ev_inc_cyclic();
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ev_inc_key_release
 * DESCRIPTION
 *  EV increase key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ev_inc_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_INC_KEY_RELEASE,0,g_mmi_vtcs_cntx.ev_value);

    /* FTE VK Panel will full all screen, cannot adjust zoom/EV/Vol */
#ifdef __MMI_VTCS_FTE__
    if(g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
        return;
#endif    

    gui_start_timer(MMI_VTCS_CTRL_PANEL_RESTORE_DUR, mmi_vtcs_panel_restore_hdlr);  
    gui_cancel_timer(mmi_vtcs_ev_inc_cyclic);

    if (!g_mmi_vtcs_cntx.touch_inc.is_press)
    {
        /* not pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_INC_KEY_RELEASE,1,-1);
        return;
    }
    
    mmi_ucm_vt_set_ev_status(g_mmi_vtcs_cntx.ev_value);
     
    mmi_vtcs_scroll_inc_release();
    mmi_vtcs_draw_panel();        
#ifdef __MMI_VTCS_FTE__
    mmi_vtcs_open_sub_wnd_hole();   
#endif    
    mmi_vtcs_blt();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ev_dec_key_press
 * DESCRIPTION
 *  EV decrease key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ev_dec_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_DEC_KEY_PRESS,0);

    /* FTE VK Panel will full all screen, cannot adjust zoom/EV/Vol */
#ifdef __MMI_VTCS_FTE__
    if(g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
        return;
#endif    

    gui_cancel_timer(mmi_vtcs_panel_restore_hdlr);   

    if (g_mmi_vtcs_cntx.touch_dec.is_press)
    {
        /* already pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_DEC_KEY_PRESS,1);
        return;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_DEC_KEY_PRESS_PANEL_STATE,g_mmi_vtcs_cntx.panel_state);
    if (g_mmi_vtcs_cntx.panel_state != MMI_VTCS_PANEL_STATE_SCROLL_EV)
    {
        mmi_vtcs_config_scroll(
            MMI_VTCS_PANEL_STATE_SCROLL_EV,
            IMG_ID_UCM_VT_EV_INC, 
            IMG_ID_UCM_VT_EV_DEC,        
            g_mmi_vtcs_cntx.ev_value,  
            g_mmi_vtcs_cntx.ev_valid_value_count); 

        mmi_vtcs_draw_panel();        
#ifdef __MMI_VTCS_FTE__
        mmi_vtcs_open_sub_wnd_hole();   
        mmi_vtcs_draw_softkey();    
#endif
        mmi_vtcs_blt();        
    }
    else
    {
        mmi_vtcs_ev_dec_cyclic();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ev_dec_key_release
 * DESCRIPTION
 *  EV decrease key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ev_dec_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_DEC_KEY_RELEASE,0,g_mmi_vtcs_cntx.ev_value);

    /* FTE VK Panel will full all screen, cannot adjust zoom/EV/Vol */
#ifdef __MMI_VTCS_FTE__
    if(g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
        return;
#endif    

    gui_start_timer(MMI_VTCS_CTRL_PANEL_RESTORE_DUR, mmi_vtcs_panel_restore_hdlr);  
    gui_cancel_timer(mmi_vtcs_ev_dec_cyclic);
    
    if (!g_mmi_vtcs_cntx.touch_dec.is_press)
    {
        /* not pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EV_DEC_KEY_RELEASE,1,-1);
        return;
    }

    mmi_ucm_vt_set_ev_status(g_mmi_vtcs_cntx.ev_value);
    
    mmi_vtcs_scroll_dec_release();
    mmi_vtcs_draw_panel();        
#ifdef __MMI_VTCS_FTE__
    mmi_vtcs_open_sub_wnd_hole();   
#endif    
    mmi_vtcs_blt();

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_init_cap
 * DESCRIPTION
 *  Init zoom capability 
 * PARAMETERS
 *  MMI_BOOL  enable_update
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_zoom_init_cap(MMI_BOOL enable_update)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_camera_zoom_info zoom_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_INIT_CAP,g_mmi_vtcs_cntx.camera_state);
#ifdef __MMI_UCM_VT_DUAL_CAMERA__
    if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_BACK)
    {
        mdi_video_tel_set_camera_id(MDI_VIDEO_MAIN_SENSOR);
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_FRONT)
    {
        mdi_video_tel_set_camera_id(MDI_VIDEO_SUB_SENSOR);
    }
    else
    {
        /* do nothing */
    }
#endif /* __MMI_UCM_VT_DUAL_CAMERA__ */
   
    mdi_video_tel_query_zoom_info(&zoom_info);   

    g_mmi_vtcs_cntx.zoom_max_step = zoom_info.zoom_steps;
    g_mmi_vtcs_cntx.zoom_step = 0;
    
    /* In the case when camera switch, we don't want to apply on the previous cameara preview */
    /* So we don't call MDI and new setting will be upstate in tel_resume/tel_start           */
    if(enable_update)
    {        
        mdi_video_tel_update_para_zoom(g_mmi_vtcs_cntx.zoom_step);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_INIT_CAP_PARA,g_mmi_vtcs_cntx.zoom_max_step,g_mmi_vtcs_cntx.zoom_step);

}




/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_in_cyclic
 * DESCRIPTION
 *  Zoom in cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_zoom_in_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_IN_CYCLIC,g_mmi_vtcs_cntx.zoom_step);
    if (g_mmi_vtcs_cntx.zoom_step < g_mmi_vtcs_cntx.zoom_max_step - 1)
    {
        g_mmi_vtcs_cntx.zoom_step++;
        g_mmi_vtcs_cntx.touch_inc.is_press = MMI_TRUE;

        if(g_mmi_vtcs_cntx.is_enc_path_built)
            mdi_video_tel_update_para_zoom(g_mmi_vtcs_cntx.zoom_step);
        
        mmi_vtcs_update_scroll_cur_value(g_mmi_vtcs_cntx.zoom_step);
        mmi_vtcs_scroll_inc_press();
        mmi_vtcs_draw_panel();        
#ifdef __MMI_VTCS_FTE__
        mmi_vtcs_open_sub_wnd_hole();   
#endif          
        mmi_vtcs_blt();            
    }   

    gui_start_timer(200, mmi_vtcs_zoom_in_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_out_cyclic
 * DESCRIPTION
 *  Zoom out cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_zoom_out_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_OUT_CYCLIC,g_mmi_vtcs_cntx.zoom_step);
    if (g_mmi_vtcs_cntx.zoom_step > 0)
    {
        g_mmi_vtcs_cntx.zoom_step--;
        g_mmi_vtcs_cntx.touch_dec.is_press = MMI_TRUE;   

        if(g_mmi_vtcs_cntx.is_enc_path_built)        
            mdi_video_tel_update_para_zoom(g_mmi_vtcs_cntx.zoom_step);  
        
        mmi_vtcs_update_scroll_cur_value(g_mmi_vtcs_cntx.zoom_step); 
        mmi_vtcs_scroll_dec_press();
        mmi_vtcs_draw_panel();        
#ifdef __MMI_VTCS_FTE__
        mmi_vtcs_open_sub_wnd_hole();   
#endif          
        mmi_vtcs_blt();
    }   

    gui_start_timer(200, mmi_vtcs_zoom_out_cyclic);    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_in_key_press
 * DESCRIPTION
 *  Zoom in key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_zoom_in_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_IN_KEY_PRESS,0);
    
    /* FTE VK Panel will full all screen, cannot adjust zoom/EV/Vol */
#ifdef __MMI_VTCS_FTE__
    if(g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
        return;
#endif    

    gui_cancel_timer(mmi_vtcs_panel_restore_hdlr);   

    if (g_mmi_vtcs_cntx.touch_inc.is_press)
    {
        /* already pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_IN_KEY_PRESS,1);
        return;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_IN_KEY_PRESS_PANNEL_STATE,g_mmi_vtcs_cntx.panel_state);
    if (g_mmi_vtcs_cntx.panel_state != MMI_VTCS_PANEL_STATE_SCROLL_ZOOM)
    {
        mmi_vtcs_config_scroll(
            MMI_VTCS_PANEL_STATE_SCROLL_ZOOM,
            IMG_ID_UCM_VT_ZOOM_IN, 
            IMG_ID_UCM_VT_ZOOM_OUT,        
            g_mmi_vtcs_cntx.zoom_step,  
            g_mmi_vtcs_cntx.zoom_max_step); 

        mmi_vtcs_draw_panel();        
#ifdef __MMI_VTCS_FTE__
        mmi_vtcs_open_sub_wnd_hole();   
        mmi_vtcs_draw_softkey();    
#endif        
        mmi_vtcs_blt();        
    }
    else
    {
        mmi_vtcs_zoom_in_cyclic();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_in_key_release
 * DESCRIPTION
 *  Zoom in key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_zoom_in_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_IN_KEY_RELEASE,0,g_mmi_vtcs_cntx.zoom_step);

    /* FTE VK Panel will full all screen, cannot adjust zoom/EV/Vol */
#ifdef __MMI_VTCS_FTE__
    if(g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
        return;
#endif    

    gui_start_timer(MMI_VTCS_CTRL_PANEL_RESTORE_DUR, mmi_vtcs_panel_restore_hdlr);  
    gui_cancel_timer(mmi_vtcs_zoom_in_cyclic);
    
    if (!g_mmi_vtcs_cntx.touch_inc.is_press)
    {
        /* not pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_IN_KEY_RELEASE,1,-1);
        return;
    }
    
    mmi_ucm_vt_set_zoom_step(g_mmi_vtcs_cntx.zoom_step);
    
    mmi_vtcs_scroll_inc_release();
    mmi_vtcs_draw_panel();        
#ifdef __MMI_VTCS_FTE__
    mmi_vtcs_open_sub_wnd_hole();   
#endif    
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_out_key_press
 * DESCRIPTION
 *  Zoom out key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_zoom_out_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_OUT_KEY_PRESS,0);
    
    /* FTE VK Panel will full all screen, cannot adjust zoom/EV/Vol */
#ifdef __MMI_VTCS_FTE__
    if(g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
        return;
#endif        
    gui_cancel_timer(mmi_vtcs_panel_restore_hdlr);   

    if (g_mmi_vtcs_cntx.touch_dec.is_press)
    {
        /* already pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_OUT_KEY_PRESS,1);
        return;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_OUT_KEY_PRESS_PANEL_STATE,g_mmi_vtcs_cntx.panel_state);
    if (g_mmi_vtcs_cntx.panel_state != MMI_VTCS_PANEL_STATE_SCROLL_ZOOM)
    {
        mmi_vtcs_config_scroll(
            MMI_VTCS_PANEL_STATE_SCROLL_ZOOM,
            IMG_ID_UCM_VT_ZOOM_IN, 
            IMG_ID_UCM_VT_ZOOM_OUT,        
            g_mmi_vtcs_cntx.zoom_step,  
            g_mmi_vtcs_cntx.zoom_max_step); 

        mmi_vtcs_draw_panel();        
#ifdef __MMI_VTCS_FTE__
        mmi_vtcs_open_sub_wnd_hole();   
        mmi_vtcs_draw_softkey();    
#endif        
        mmi_vtcs_blt();        
    }
    else
    {
        mmi_vtcs_zoom_out_cyclic();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_out_key_release
 * DESCRIPTION
 *  Zoom out key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_zoom_out_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_OUT_KEY_RELEASE,0,g_mmi_vtcs_cntx.zoom_step);

    /* FTE VK Panel will full all screen, cannot adjust zoom/EV/Vol */
#ifdef __MMI_VTCS_FTE__
    if(g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
        return;
#endif    

    gui_start_timer(MMI_VTCS_CTRL_PANEL_RESTORE_DUR, mmi_vtcs_panel_restore_hdlr);      
    gui_cancel_timer(mmi_vtcs_zoom_out_cyclic);
    
    if (!g_mmi_vtcs_cntx.touch_dec.is_press)
    {
        /* not pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ZOOM_OUT_KEY_RELEASE,1,-1);
        return;
    }

    mmi_ucm_vt_set_zoom_step(g_mmi_vtcs_cntx.zoom_step);
    
    mmi_vtcs_scroll_dec_release();
    mmi_vtcs_draw_panel();        
#ifdef __MMI_VTCS_FTE__
    mmi_vtcs_open_sub_wnd_hole();   
#endif    
    mmi_vtcs_blt();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_vol_up_cyclic
 * DESCRIPTION
 *  Vol up cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_vol_up_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VOL_UP_CYCLIC,g_mmi_vtcs_cntx.vol_value );
    if (g_mmi_vtcs_cntx.vol_value < MMI_VT_VOL_6)
    {
        g_mmi_vtcs_cntx.vol_value++;
        mmi_ucm_vt_set_volume_status(g_mmi_vtcs_cntx.vol_value);        
        
        g_mmi_vtcs_cntx.touch_inc.is_press = MMI_TRUE;               

        mmi_vtcs_update_scroll_cur_value(g_mmi_vtcs_cntx.vol_value);            
        mmi_vtcs_scroll_inc_press();
        mmi_vtcs_draw_panel();        
    #ifdef __MMI_VTCS_FTE__
        mmi_vtcs_open_sub_wnd_hole();   
    #endif          
        mmi_vtcs_blt();            
    }        
    
    gui_start_timer(200, mmi_vtcs_vol_up_cyclic);
    
    if(g_mmi_vtcs_cntx.vol_value == MMI_VT_VOL_6)
    {
        g_mmi_vtcs_cntx.touch_inc.is_press = MMI_TRUE;  
        gui_cancel_timer(mmi_vtcs_vol_up_cyclic);
        kal_sleep_task(50);
        mmi_vtcs_panel_restore_hdlr();        
    }     
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_vol_down_cyclic
 * DESCRIPTION
 *  Vol down cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_vol_down_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VOL_DOWN_CYCLIC,g_mmi_vtcs_cntx.vol_value );
    if (g_mmi_vtcs_cntx.vol_value > MMI_VT_VOL_0)
    {
        g_mmi_vtcs_cntx.vol_value--;
        mmi_ucm_vt_set_volume_status(g_mmi_vtcs_cntx.vol_value);        
        
        g_mmi_vtcs_cntx.touch_dec.is_press = MMI_TRUE;   
        
        mmi_vtcs_update_scroll_cur_value(g_mmi_vtcs_cntx.vol_value);        
        mmi_vtcs_scroll_dec_press();
        mmi_vtcs_draw_panel();        
    #ifdef __MMI_VTCS_FTE__
        mmi_vtcs_open_sub_wnd_hole();   
    #endif          
        mmi_vtcs_blt();            
    }   

    gui_start_timer(200, mmi_vtcs_vol_down_cyclic);    

    if(g_mmi_vtcs_cntx.vol_value == MMI_VT_VOL_0)
    {          
        g_mmi_vtcs_cntx.touch_dec.is_press = MMI_TRUE; 
        gui_cancel_timer(mmi_vtcs_vol_down_cyclic);
        kal_sleep_task(50);
        mmi_vtcs_panel_restore_hdlr();
    }        
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_vol_up_key_press
 * DESCRIPTION
 *  Vol up key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_vol_up_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VOL_UP_KEY_PRESS,0,g_mmi_vtcs_cntx.speaker_state);
    
    /* FTE VK Panel will full all screen, cannot adjust zoom/EV/Vol */
#ifdef __MMI_VTCS_FTE__
    if(g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
        return;
#endif        
    if(g_mmi_vtcs_cntx.speaker_state != MMI_VT_SPEAKER_ON)
    {
        g_mmi_vtcs_cntx.speaker_state = MMI_VT_SPEAKER_ON;
        mmi_ucm_vt_set_volume_status(g_mmi_vtcs_cntx.vol_value); 
    }
    gui_cancel_timer(mmi_vtcs_panel_restore_hdlr);   

    if (g_mmi_vtcs_cntx.touch_inc.is_press)
    {
        /* already pressed */
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VOL_UP_KEY_PRESS,1,-1);
        return;
    }
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VOL_UP_KEY_PRESS_PANEL_STATE,g_mmi_vtcs_cntx.panel_state);
    if (g_mmi_vtcs_cntx.panel_state != MMI_VTCS_PANEL_STATE_SCROLL_VOL)
    {
        mmi_vtcs_config_scroll(
            MMI_VTCS_PANEL_STATE_SCROLL_VOL,
            IMG_ID_UCM_VT_VOL_UP, 
            IMG_ID_UCM_VT_VOL_DOWN,        
            g_mmi_vtcs_cntx.vol_value,  
            MMI_VT_VOL_TOTAL); 
            
        mmi_vtcs_draw_panel();        
#ifdef __MMI_VTCS_FTE__
        mmi_vtcs_open_sub_wnd_hole();   
        mmi_vtcs_draw_softkey();    
#endif        
        mmi_vtcs_blt();        
    }
    else
    {
        mmi_vtcs_vol_up_cyclic();
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_vol_up_key_release
 * DESCRIPTION
 *  Vol up key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_vol_up_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VOL_UP_KEY_RELEASE,0,g_mmi_vtcs_cntx.speaker_state,g_mmi_vtcs_cntx.vol_value);

    /* FTE VK Panel will full all screen, cannot adjust zoom/EV/Vol */
#ifdef __MMI_VTCS_FTE__
    if(g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
        return;
#endif    

    if(g_mmi_vtcs_cntx.speaker_state != MMI_VT_SPEAKER_ON)
    {
        g_mmi_vtcs_cntx.speaker_state = MMI_VT_SPEAKER_ON;
        mmi_ucm_vt_set_volume_status(g_mmi_vtcs_cntx.vol_value);         
    }  
    gui_start_timer(MMI_VTCS_CTRL_PANEL_RESTORE_DUR, mmi_vtcs_panel_restore_hdlr);      
    gui_cancel_timer(mmi_vtcs_vol_up_cyclic);
        
    if (!g_mmi_vtcs_cntx.touch_inc.is_press)
    {
        /* not pressed */
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VOL_UP_KEY_RELEASE,1,-1,-1);
        return;
    }
        
    mmi_vtcs_scroll_inc_release();
    mmi_vtcs_draw_panel();        
#ifdef __MMI_VTCS_FTE__
    mmi_vtcs_open_sub_wnd_hole();   
#endif    
    mmi_vtcs_blt();
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_vol_down_key_press
 * DESCRIPTION
 *  Vol down key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_vol_down_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VOL_DOWN_KEY_PRESS,0,g_mmi_vtcs_cntx.speaker_state);    

    /* FTE VK Panel will full all screen, cannot adjust zoom/EV/Vol */
#ifdef __MMI_VTCS_FTE__
    if(g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
        return;
#endif    

    if(g_mmi_vtcs_cntx.speaker_state != MMI_VT_SPEAKER_ON)
    {
        g_mmi_vtcs_cntx.speaker_state = MMI_VT_SPEAKER_ON;
        mmi_ucm_vt_set_volume_status(g_mmi_vtcs_cntx.vol_value); 
    }        
    gui_cancel_timer(mmi_vtcs_panel_restore_hdlr);   
        
    if (g_mmi_vtcs_cntx.touch_dec.is_press)
    {
        /* already pressed */
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VOL_DOWN_KEY_PRESS,1,-1);     
        return;
    }
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VOL_DOWN_KEY_PRESS_PANEL_STATE,g_mmi_vtcs_cntx.speaker_state);  
    if (g_mmi_vtcs_cntx.panel_state != MMI_VTCS_PANEL_STATE_SCROLL_VOL)
    {
        mmi_vtcs_config_scroll(
            MMI_VTCS_PANEL_STATE_SCROLL_VOL,
            IMG_ID_UCM_VT_VOL_UP, 
            IMG_ID_UCM_VT_VOL_DOWN,        
            g_mmi_vtcs_cntx.vol_value,  
            MMI_VT_VOL_TOTAL); 
            
        mmi_vtcs_draw_panel();        
#ifdef __MMI_VTCS_FTE__
        mmi_vtcs_open_sub_wnd_hole();   
        mmi_vtcs_draw_softkey();    
#endif        
        mmi_vtcs_blt();              
    }
    else
    {
        mmi_vtcs_vol_down_cyclic();
    }
                
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_vol_down_key_release
 * DESCRIPTION
 *  Vol down key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_vol_down_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VOL_DOWN_KEY_RELEASE,0,g_mmi_vtcs_cntx.speaker_state,g_mmi_vtcs_cntx.vol_value);

    /* FTE VK Panel will full all screen, cannot adjust zoom/EV/Vol */
#ifdef __MMI_VTCS_FTE__
    if(g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
        return;
#endif    

    if(g_mmi_vtcs_cntx.speaker_state != MMI_VT_SPEAKER_ON)
    {
        g_mmi_vtcs_cntx.speaker_state = MMI_VT_SPEAKER_ON;
    } 
    gui_start_timer(MMI_VTCS_CTRL_PANEL_RESTORE_DUR, mmi_vtcs_panel_restore_hdlr);      
    gui_cancel_timer(mmi_vtcs_vol_down_cyclic); 
        
    if (!g_mmi_vtcs_cntx.touch_dec.is_press)
    {
        /* not pressed */
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VOL_DOWN_KEY_RELEASE,1,-1,-1);
        return;
    }

    mmi_vtcs_scroll_dec_release();
    mmi_vtcs_draw_panel();        
#ifdef __MMI_VTCS_FTE__
    mmi_vtcs_open_sub_wnd_hole();   
#endif    
    mmi_vtcs_blt();
  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_lsk_press
 * DESCRIPTION
 *  lsk hdlr when press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_LSK_PRESS,0);
    if (g_mmi_vtcs_cntx.touch_lsk.is_press)
    {
        /* already pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_LSK_PRESS,1);
        return;
    }
    
    g_mmi_vtcs_cntx.touch_lsk.is_press = MMI_TRUE;
    mmi_vtcs_draw_softkey();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_lsk_release
 * DESCRIPTION
 *  lsk hdlr when release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_LSK_RELEASE,0);
    if (!g_mmi_vtcs_cntx.touch_lsk.is_press)
    {
        /* not pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_LSK_RELEASE,1);    
        return;
    }
    
    g_mmi_vtcs_cntx.touch_lsk.is_press = MMI_FALSE;
    mmi_vtcs_draw_softkey();
    mmi_vtcs_blt();

    mmi_ucm_vt_entry_incall_option();
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_rsk_press
 * DESCRIPTION
 *  rsk hdlr when press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_RSK_PRESS,0);
    if (g_mmi_vtcs_cntx.touch_rsk.is_press)
    {
        /* already pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_RSK_PRESS,1);
        return;
    }
    
    g_mmi_vtcs_cntx.touch_rsk.is_press = MMI_TRUE;
    mmi_vtcs_draw_softkey();
    mmi_vtcs_blt();    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_rsk_release
 * DESCRIPTION
 *  rsk hdlr when release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_RSK_RELEASE,0);  
    if (!g_mmi_vtcs_cntx.touch_rsk.is_press)
    {
        /* not pressed */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_RSK_RELEASE,1);  
        return;
    }
    
    g_mmi_vtcs_cntx.touch_rsk.is_press = MMI_FALSE;
    mmi_vtcs_draw_softkey();
    mmi_vtcs_blt();       
	if(g_mmi_vtcs_cntx.is_fullscreen_state)
	{
	    g_mmi_vtcs_cntx.is_fullscreen_state = FALSE;
		mmi_vtcs_entry_call_scr_normal();
		return;
	}

#ifdef __MMI_VTCS_FTE__

    if(g_mmi_vtcs_cntx.two_setp_ad_panel_mode)
    {           
        g_mmi_vtcs_cntx.panel_state = MMI_VTCS_PANEL_STATE_TIME_ICON;         
        mmi_ucm_handle_sendkeys_for_call(NULL,KEY_EVENT_UP);    
        g_mmi_vtcs_cntx.two_setp_ad_panel_mode = MMI_FALSE;
		gui_start_timer(MMI_VTCS_UPDATE_TIME_DUR, mmi_vtcs_update_call_status_cyclic);

        #ifdef __MMI_BT_SUPPORT__
            if (!srv_bt_cm_is_incall_aud_swap2bt())
            {
                if (mmi_ucm_vt_get_hand_free_status())
                {
                    mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_ID_UCM_VT_RSK_HANDS_HELD);                
                }
                else
                {
                    mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_ID_UCM_VT_RSK_HANDS_FREE);
                }
            }
            else
            {
               mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, 0);
            }
        #else /* __MMI_BT_HP_SUPPORT__ */
        
            if (mmi_ucm_vt_get_hand_free_status())
            {
                mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_ID_UCM_VT_RSK_HANDS_HELD);                
            }
            else
            {
                mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_ID_UCM_VT_RSK_HANDS_FREE);
            }
        #endif /* __MMI_BT_HP_SUPPORT__ */
        mmi_vtcs_draw_status();
        mmi_vtcs_draw_title();
        mmi_vtcs_draw_body();        
        mmi_vtcs_draw_panel();
        mmi_vtcs_open_sub_wnd_hole();
        mmi_vtcs_open_main_wnd_hole(); 
        mmi_vtcs_draw_softkey();        
        mmi_vtcs_blt();          
    
        return;
    }    
#endif

    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4)
    {
        /* mode 1, 2, 3, 4, 5 are VTing state */
        if (g_mmi_vtcs_cntx.hand_state == MMI_VT_HAND_HELD)
        {
            g_mmi_vtcs_cntx.hand_state = MMI_VT_HAND_FREE;
            mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_ID_UCM_VT_RSK_HANDS_HELD);
            
            mmi_ucm_vt_set_hand_free_status(MMI_TRUE);
            g_mmi_vtcs_cntx.vol_value = mmi_ucm_vt_get_volume_status();
            if(g_mmi_vtcs_cntx.speaker_state == MMI_VT_SPEAKER_OFF)
            {
                mmi_ucm_vt_set_speaker_status(MMI_FALSE);        
            }
            else 
            {                
                mmi_ucm_vt_set_speaker_status(MMI_TRUE);                
            }
            

        }
        else if (g_mmi_vtcs_cntx.hand_state == MMI_VT_HAND_FREE)
        {
            g_mmi_vtcs_cntx.hand_state = MMI_VT_HAND_HELD;
            mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_ID_UCM_VT_RSK_HANDS_FREE);            

            mmi_ucm_vt_set_hand_free_status(MMI_FALSE);
            g_mmi_vtcs_cntx.vol_value = mmi_ucm_vt_get_volume_status();            
            if(g_mmi_vtcs_cntx.speaker_state == MMI_VT_SPEAKER_OFF)
            {
                mmi_ucm_vt_set_speaker_status(MMI_FALSE);        
            }
            else 
            {                
                mmi_ucm_vt_set_speaker_status(MMI_TRUE);                
            }        
        }
        else
        {
            /* shall not enter here */
            MMI_ASSERT(0);
        }
        if(g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_VOL)
        {    
            mmi_vtcs_update_scroll_cur_value(g_mmi_vtcs_cntx.vol_value);   
        }    
        mmi_vtcs_draw_panel();  
    #ifdef __MMI_VTCS_FTE__
        mmi_vtcs_open_sub_wnd_hole();   
    #endif        
        mmi_vtcs_draw_softkey();
        mmi_vtcs_blt();       
        kal_sleep_task(100);         
        return;
    }
    else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_6 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_8 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_7)
    {
        mmi_frm_group_close(GRP_ID_UCM_VT);
        return;        
    }
    else
    {
        /* unhandle mode */
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_panel_restore_hdlr
 * DESCRIPTION
 *  Restore control panel to timer state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_panel_restore_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle t_lyr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_PANEL_RESTORE_HDLR, g_mmi_vtcs_cntx.panel_state, g_mmi_vtcs_cntx.touch_obj); 
    #ifdef __MMI_VTCS_FTE__        
    if(g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
        return;
    #endif    
    if(g_mmi_vtcs_cntx.touch_obj != MMI_VTCS_TOUCH_NONE)
    {
        if(g_mmi_vtcs_cntx.touch_obj == MMI_VTCS_TOUCH_INC)
        {
            if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_EV)
            {
                mmi_vtcs_ev_inc_key_release();
            }
            else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_ZOOM)
            {
                mmi_vtcs_zoom_in_key_release();
            }
            else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_VOL)
            {
                mmi_vtcs_vol_up_key_release();
            }        
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;
        }
        else if(g_mmi_vtcs_cntx.touch_obj == MMI_VTCS_TOUCH_DEC)
        {                        
            if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_EV)
            {
                mmi_vtcs_ev_dec_key_release();
            }
            else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_ZOOM)
            {
                mmi_vtcs_zoom_out_key_release();
            }
            else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_VOL)
            {
                mmi_vtcs_vol_down_key_release();
            }   
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;
        }
        else if(g_mmi_vtcs_cntx.touch_obj == MMI_VTCS_TOUCH_SLIDER)
        {
            gui_start_timer(MMI_VTCS_CTRL_PANEL_RESTORE_DUR, mmi_vtcs_panel_restore_hdlr);  
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;
        } 
        //g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;     
    }        
    
    g_mmi_vtcs_cntx.panel_state = MMI_VTCS_PANEL_STATE_TIME_ICON; 

#ifdef __MMI_VTCS_FTE__
    switch (mmi_ucm_vt_get_incall_screen_mode())
    {
        case MMI_UCM_VT_INCALL_SCREEN_MODE_INCALL:
            
        #ifdef __MMI_BT_SUPPORT__
            if (!srv_bt_cm_is_incall_aud_swap2bt())
            {
                if (mmi_ucm_vt_get_hand_free_status())
                {
                    mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_ID_UCM_VT_RSK_HANDS_HELD);             
                }
                else
                {
                    mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_ID_UCM_VT_RSK_HANDS_FREE);
                }
            }
            else
            {
               mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, 0);
            }
        #else /* __MMI_BT_HP_SUPPORT__ */
        
            if (mmi_ucm_vt_get_hand_free_status())
            {
                mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_ID_UCM_VT_RSK_HANDS_HELD);             
            }
            else
            {
                mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_ID_UCM_VT_RSK_HANDS_FREE);
            }
        #endif /* __MMI_BT_HP_SUPPORT__ */
            break;

        case MMI_UCM_VT_INCALL_SCREEN_MODE_NONE:
        case MMI_UCM_VT_INCALL_SCREEN_MODE_PREVIEW_ONLY:

            mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_GLOBAL_BACK);
            break;            
    }
#endif

    mmi_ucm_handle_sendkeys_for_call(NULL,KEY_EVENT_UP);

    gdi_get_alpha_blending_source_layer(&t_lyr);
    gdi_set_alpha_blending_source_layer(g_mmi_vtcs_cntx.skin_layer_handle);
#ifdef MMI_VTCS_LANDSCAPE_MODE
    /* landscape need draw body since control bar overlap body */
    mmi_vtcs_draw_body();    
    mmi_vtcs_draw_panel(); 
    mmi_vtcs_open_sub_wnd_hole();    
    mmi_vtcs_open_main_wnd_hole();  
#else /* MMI_VTCS_LANDSCAPE_MODE */
#if  ( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )
    mmi_vtcs_draw_body();    
#endif
    mmi_vtcs_draw_panel();
    mmi_vtcs_open_sub_wnd_hole();
    mmi_vtcs_open_main_wnd_hole(); 
#endif /* MMI_VTCS_LANDSCAPE_MODE */
#ifdef __MMI_VTCS_FTE__
    mmi_vtcs_draw_softkey();    
#endif /* MMI_VTCS_LANDSCAPE_MODE */
	//gdi_set_alpha_blending_source_layer(t_lyr);

    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_config_scroll
 * DESCRIPTION
 *  Set control panel's scroll's inc, dec icon images
 * PARAMETERS
 *  state           [IN]        ctrl panel state 
 *  inc_img         [IN]        inc image id
 *  dec_img         [IN]        dec image id 
 *  cur_value       [IN]        cur_value
 *  total_value     [IN]        total_value
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_config_scroll(
    mmi_vtcs_panel_state_enum state,
    U16 inc_img, 
    U16 dec_img,
    S32 cur_value, 
    S32 total_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_CONFIG_SCROLL, g_mmi_vtcs_cntx.panel_state, g_mmi_vtcs_cntx.scroll_cur_value); 
    g_mmi_vtcs_cntx.touch_dec.is_usable = MMI_TRUE;
    g_mmi_vtcs_cntx.touch_inc.is_usable = MMI_TRUE;    
    g_mmi_vtcs_cntx.touch_slider.is_usable = MMI_TRUE;        
    g_mmi_vtcs_cntx.panel_state = state;
    g_mmi_vtcs_cntx.scroll_inc_img_id = inc_img;
    g_mmi_vtcs_cntx.scroll_dec_img_id = dec_img;   
    g_mmi_vtcs_cntx.scroll_cur_value = cur_value;
    g_mmi_vtcs_cntx.scroll_total_value = total_value;     

#ifdef __MMI_VTCS_FTE__
    mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, NULL);
#endif    
    mmi_ucm_handle_sendkeys_for_call(NULL,KEY_EVENT_UP);

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_update_scroll_cur_value
 * DESCRIPTION
 *  Update control panel scroll's cur value
 * PARAMETERS
 *  cur_value           [IN]        cur_value
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_update_scroll_cur_value(S32 cur_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_UPDATE_SCROLL_CUR_VALUE, cur_value); 
    g_mmi_vtcs_cntx.scroll_cur_value = cur_value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_scroll_inc_press
 * DESCRIPTION
 *  Scroll inc press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_scroll_inc_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_SCROLL_INC_PRESS); 
    g_mmi_vtcs_cntx.touch_inc.is_press = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_scroll_inc_release
 * DESCRIPTION
 *  Scroll inc release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_scroll_inc_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_SCROLL_INC_RELEASE);     
    g_mmi_vtcs_cntx.touch_inc.is_press = MMI_FALSE;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_scroll_dec_press
 * DESCRIPTION
 *  Slider dec press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_scroll_dec_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_SCROLL_DEC_PRESS);      
    g_mmi_vtcs_cntx.touch_dec.is_press = MMI_TRUE;    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_scroll_dec_release
 * DESCRIPTION
 *  Scroll dec release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_scroll_dec_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_SCROLL_DEC_RELEASE);        
    g_mmi_vtcs_cntx.touch_dec.is_press = MMI_FALSE;     
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_get_ev_factor
 * DESCRIPTION
 *  get ev factor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_vtcs_get_ev_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 ev_value = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(g_mmi_vtcs_cntx.ev_value)
    {
        case MMI_VT_EV_N4:
            ev_value = MDI_VIDEO_EV_N4;
            break;
        case MMI_VT_EV_N3:
            ev_value = MDI_VIDEO_EV_N3;
            break;
        case MMI_VT_EV_N2:
            ev_value = MDI_VIDEO_EV_N2;
            break;
        case MMI_VT_EV_N1:
            ev_value = MDI_VIDEO_EV_N1;
            break;  
        case MMI_VT_EV_0:
            ev_value = MDI_VIDEO_EV_0;
            break;    
        case MMI_VT_EV_P1:
            ev_value = MDI_VIDEO_EV_P1;
            break;    
        case MMI_VT_EV_P2:
            ev_value = MDI_VIDEO_EV_P2;
            break;    
        case MMI_VT_EV_P3:
            ev_value = MDI_VIDEO_EV_P3;
            break;                
        case MMI_VT_EV_P4:
            ev_value = MDI_VIDEO_EV_P4;
            break; 
        default:
            /* wrong value */
            MMI_ASSERT(0);
            ev_value = 0;
			break;
    }
	return ev_value;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_get_cam_rotate_factor
 * DESCRIPTION
 *  get camera rotate factor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_vtcs_get_cam_rotate_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 cam_rotate_state = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   


    if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_BACK)
    {
#ifdef HORIZONTAL_CAMERA     
        switch (g_mmi_vtcs_cntx.cam_rotate_state)
        {    
            case MMI_VT_CAM_ROTATE_0:
                
            #if defined(SUB_SENSOR_ROTATE_0)
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_90;
            #elif defined(SUB_SENSOR_ROTATE_90)        
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_180;        
            #elif defined(SUB_SENSOR_ROTATE_180)
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_270;
            #else 
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_0;        
            #endif
				break;

            case MMI_VT_CAM_ROTATE_0_MIRROR:
                
            #if defined(SUB_SENSOR_ROTATE_0)
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_90_MIRROR;
            #elif defined(SUB_SENSOR_ROTATE_90)        
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_180_MIRROR;        
            #elif defined(SUB_SENSOR_ROTATE_180)
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_270_MIRROR;
            #else 
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_0_MIRROR;        
            #endif
                break;
            
            default:
                /* wrong value */
                MMI_ASSERT(0);
                cam_rotate_state = 0;
				break;
        } 
#else        
        
        /* camera at the rear, same side as battery cover */
        switch (g_mmi_vtcs_cntx.cam_rotate_state)
        {
            case MMI_VT_CAM_ROTATE_0:

            #if defined(SENSOR_ROTATE_0)
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_0;
            #elif defined(SENSOR_ROTATE_90)        
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_90;        
            #elif defined(SENSOR_ROTATE_180)
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_180;
            #else 
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_270;        
            #endif
                break;

            case MMI_VT_CAM_ROTATE_0_MIRROR:
                
            #if defined(SENSOR_ROTATE_0)
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_0_MIRROR;
            #elif defined(SENSOR_ROTATE_90)        
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_90_MIRROR;        
            #elif defined(SENSOR_ROTATE_180)
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_180_MIRROR;
            #else 
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_270_MIRROR;        
            #endif
                break;
            
            default:
                /* wrong value */
                MMI_ASSERT(0);
                cam_rotate_state = 0;
				break;
        }        
#endif        
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_FRONT)
    {
        /* camera at front, same side as LCD panel */
    #ifdef __MMI_UCM_VT_DUAL_CAMERA__
        switch (g_mmi_vtcs_cntx.cam_rotate_state)
        {    
            case MMI_VT_CAM_ROTATE_0:
                
            #if defined(SUB_SENSOR_ROTATE_0)
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_0;
            #elif defined(SUB_SENSOR_ROTATE_90)        
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_90;        
            #elif defined(SUB_SENSOR_ROTATE_180)
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_180;
            #else 
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_270;        
            #endif
				break;

            case MMI_VT_CAM_ROTATE_0_MIRROR:
                
            #if defined(SUB_SENSOR_ROTATE_0)
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_0_MIRROR;
            #elif defined(SUB_SENSOR_ROTATE_90)        
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_90_MIRROR;        
            #elif defined(SUB_SENSOR_ROTATE_180)
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_180_MIRROR;
            #else 
                cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_270_MIRROR;        
            #endif
                break;
            
            default:
                /* wrong value */
                MMI_ASSERT(0);
                cam_rotate_state = 0;
				break;
        }
    #endif /* __MMI_UCM_VT_DUAL_CAMERA__ */    
    }
    else
    {
       cam_rotate_state = MDI_VIDEO_PREVIEW_ROTATE_0;
    }
	return cam_rotate_state;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_get_cam_rotate_factor
 * DESCRIPTION
 *  get camera rotate factor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_vtcs_get_cam_rotate_factor_for_IDP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   

#ifdef __MMI_UCM_VT_DUAL_CAMERA__

    if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_BACK)
    {
        
#ifdef HORIZONTAL_CAMERA                
            #if defined(SENSOR_ROTATE_0)
                return MDI_VIDEO_PREVIEW_ROTATE_90;
            #elif defined(SENSOR_ROTATE_90)        
                return MDI_VIDEO_PREVIEW_ROTATE_180;        
            #elif defined(SENSOR_ROTATE_180)
                return MDI_VIDEO_PREVIEW_ROTATE_270;
            #else 
                return MDI_VIDEO_PREVIEW_ROTATE_0;        
            #endif
#else
            #if defined(SENSOR_ROTATE_0)
                return MDI_VIDEO_PREVIEW_ROTATE_0;
            #elif defined(SENSOR_ROTATE_90)        
                return MDI_VIDEO_PREVIEW_ROTATE_90;        
            #elif defined(SENSOR_ROTATE_180)
                return MDI_VIDEO_PREVIEW_ROTATE_180;
            #else 
                return MDI_VIDEO_PREVIEW_ROTATE_270;        
            #endif
#endif            
        
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_FRONT)
    {

                    return MDI_VIDEO_PREVIEW_ROTATE_0;
/*                
            #if defined(SUB_SENSOR_ROTATE_0)
                return MDI_VIDEO_PREVIEW_ROTATE_180;
            #elif defined(SUB_SENSOR_ROTATE_90)        
                return MDI_VIDEO_PREVIEW_ROTATE_90;        
            #elif defined(SUB_SENSOR_ROTATE_180)
                return MDI_VIDEO_PREVIEW_ROTATE_0;
            #else 
                return MDI_VIDEO_PREVIEW_ROTATE_270;        
            #endif
*/
    }
    else
    {
       return MDI_VIDEO_PREVIEW_ROTATE_0;
    }
    
#else
    if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_ON)
    {
#ifdef HORIZONTAL_CAMERA                
            #if defined(SENSOR_ROTATE_0)
                return MDI_VIDEO_PREVIEW_ROTATE_90;
            #elif defined(SENSOR_ROTATE_90)        
                return MDI_VIDEO_PREVIEW_ROTATE_180;        
            #elif defined(SENSOR_ROTATE_180)
                return MDI_VIDEO_PREVIEW_ROTATE_270;
            #else 
                return MDI_VIDEO_PREVIEW_ROTATE_0;        
            #endif
#else
            #if defined(SENSOR_ROTATE_0)
                return MDI_VIDEO_PREVIEW_ROTATE_0;
            #elif defined(SENSOR_ROTATE_90)        
                return MDI_VIDEO_PREVIEW_ROTATE_90;        
            #elif defined(SENSOR_ROTATE_180)
                return MDI_VIDEO_PREVIEW_ROTATE_180;
            #else 
                return MDI_VIDEO_PREVIEW_ROTATE_270;        
            #endif
#endif    
    }
    else
    {
        return MDI_VIDEO_PREVIEW_ROTATE_0;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_get_local_enc_qty_factor
 * DESCRIPTION
 *  Get encode quality for local encoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_vtcs_get_local_enc_qty_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 local_enc_qty = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    switch (g_mmi_vtcs_cntx.local_enc_qty_state)
    {
        case MMI_VT_VIDEO_QUALITY_SHARP:
            local_enc_qty = MDI_VIDEO_TEL_ENC_QTY_FINE;            
            break;

        case MMI_VT_VIDEO_QUALITY_NORMAL:
            local_enc_qty = MDI_VIDEO_TEL_ENC_QTY_NORMAL;
            break;

        case MMI_VT_VIDEO_QUALITY_SMOOTH:
            local_enc_qty = MDI_VIDEO_TEL_ENC_QTY_LOW;
            break;

        default:
            /* wrong value */
            MMI_ASSERT(0);
            local_enc_qty = 0;
			break;
    }
	return local_enc_qty;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_get_peer_enc_qty_factor
 * DESCRIPTION
 *  Get encode quality for perr encoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_vtcs_get_peer_enc_qty_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 peer_enc_qty = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    switch (g_mmi_vtcs_cntx.peer_enc_qty_state)
    {
        case MMI_VT_VIDEO_QUALITY_SHARP:
            peer_enc_qty = MDI_VIDEO_TEL_ENC_QTY_FINE;            
            break;

        case MMI_VT_VIDEO_QUALITY_NORMAL:
            peer_enc_qty = MDI_VIDEO_TEL_ENC_QTY_NORMAL;
            break;

        case MMI_VT_VIDEO_QUALITY_SMOOTH:
            peer_enc_qty = MDI_VIDEO_TEL_ENC_QTY_LOW;
            break;

        default:
            /* wrong value */
            MMI_ASSERT(0);
            peer_enc_qty = 0;
			break;
    }
	return peer_enc_qty;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_get_enc_size_factor
 * DESCRIPTION
 *  Get encode size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_vtcs_get_enc_size_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 enc_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    switch (g_mmi_vtcs_cntx.enc_size_state)
    {
        case MMI_VT_ENC_SIZE_QCIF:
            enc_size = MDI_VIDEO_VIDEO_SIZE_QCIF;
            break;

        case MMI_VT_ENC_SIZE_SQCIF:
            enc_size = MDI_VIDEO_VIDEO_SIZE_SQCIF;
            break;
            
        default:
            /* wrong value */
            MMI_ASSERT(0);
            enc_size = 0;
			break;
    }
	return enc_size;
}


#ifndef MMI_VTCS_LANDSCAPE_MODE
/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_clear_status_bg
 * DESCRIPTION
 *  Clear status background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_clear_status_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_CLEAR_STATUS_BG);  
    wgui_status_icon_bar_get_clip(WGUI_STATUS_ICON_BAR_H_BAR, &x1, &y1, &x2, &y2);
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_image_draw_id(
        g_mmi_vtcs_skin_cntx.status_rect.offset_x, 
        g_mmi_vtcs_skin_cntx.status_rect.offset_y,         
        IMG_ID_UCM_VT_BG_STATUS);
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_status
 * DESCRIPTION
 *  Draw statis
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_STATUS);          
#ifndef MMI_VTCS_LANDSCAPE_MODE
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);    
    wgui_status_icon_bar_update();
    gdi_layer_pop_and_restore_active();    
#endif /* MMI_VTCS_LANDSCAPE_MODE */
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_title
 * DESCRIPTION
 *  Draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 str_width;
    S32 str_height;
    S32 char_height;
    S32 str_len;
    S32 str_total_width;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_TITLE);       
#if ( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )
    return;
#endif 

    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    offset_x = g_mmi_vtcs_skin_cntx.title_rect.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.title_rect.offset_y - layer_offset_y;    
    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_TITLE));  
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_BG_TITLE);


    /* draw title string */
    str_len = mmi_ucs2strlen(g_mmi_vtcs_cntx.title_buf);

    if (str_len != 0)
    {
        gui_measure_string((UI_string_type)g_mmi_vtcs_cntx.title_buf, &str_width, &str_height);

        /* if string too long, change to xxxxxx.. */
        if (str_width > g_mmi_vtcs_skin_cntx.title_rect.width)
        {

            for (index = (str_len - 3); index > 0; index--)
            {
                mmi_ucs2cpy(&g_mmi_vtcs_cntx.title_buf[index * ENCODING_LENGTH], (CHAR *) L"...");
                
                gui_measure_string((UI_string_type)g_mmi_vtcs_cntx.title_buf, &str_total_width, &char_height);

                if (str_total_width < g_mmi_vtcs_skin_cntx.title_rect.width)
                {                 
                    break;
                }
            }

            str_width = str_total_width;
        }

        if (r2lMMIFlag)
        {
            offset_x = (g_mmi_vtcs_skin_cntx.title_rect.width - str_width) >> 1;
            offset_x = g_mmi_vtcs_skin_cntx.title_rect.offset_x + g_mmi_vtcs_skin_cntx.title_rect.width - offset_x;
            offset_x -= layer_offset_x;
        }
        else
        {
            offset_x = (g_mmi_vtcs_skin_cntx.title_rect.width - str_width) >> 1;
            offset_x += g_mmi_vtcs_skin_cntx.title_rect.offset_x;
            offset_x -= layer_offset_x;
        }
        
        offset_y = (g_mmi_vtcs_skin_cntx.title_rect.height - str_height) >> 1;
        offset_y += g_mmi_vtcs_skin_cntx.title_rect.offset_y;
        offset_y -= layer_offset_y;        


        gui_move_text_cursor(offset_x, offset_y);
        gui_set_text_color(MMI_VTCS_TEXT_COLOR);
        gui_set_text_border_color(MMI_VTCS_TEXT_BORDER_COLOR);
        gui_print_bordered_text((UI_string_type)g_mmi_vtcs_cntx.title_buf);
    }
    
    gui_set_font(&MMI_medium_font);
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_body
 * DESCRIPTION
 *  Draw body bg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_body(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_BODY);  
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);

    gdi_layer_get_position(&offset_x, &offset_y);

    offset_x = g_mmi_vtcs_skin_cntx.body_rect.offset_x - offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.body_rect.offset_y - offset_y;    
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_BG_BODY);
	/*
	#if defined(__OP01__) && defined(__MMI_FTE_SUPPORT__)
	gdi_layer_get_position(&offset_x, &offset_y);

    offset_x = g_mmi_vtcs_skin_cntx.contrast_bg.offset_x - offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.contrast_bg.offset_y - offset_y;    
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_CONTRAST_BG);
	#endif
	*/
	#if defined(__MMI_FTE_VT_SUBWND_BG__)
    if (!g_mmi_vtcs_cntx.is_hide_sub)
	{
		gdi_layer_get_position(&offset_x, &offset_y);
	offset_x = g_mmi_vtcs_skin_cntx.subwnd_bg.offset_x - offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.subwnd_bg.offset_y - offset_y;    
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_SUBWND_BG);
	}
	#endif
    
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_ctrl_panel
 * DESCRIPTION
 *  Draw time panel region
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_panel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 str_width;
    S32 str_height;  
    U32 img_id;
#ifdef __MMI_VTCS_FTE__    
    U32 img_id2;    
#endif
    S32 bar_width;
    S32 bar_height;
    S32 slider_width;
    S32 slider_height;
#ifdef __MMI_VTCS_FTE__    
    S32 img_width, img_height;  
    S32 b_img_width, b_img_height;  
#endif    
    gdi_handle t_lyr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_PANEL,g_mmi_vtcs_cntx.panel_state); 
    
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);

    if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_TIME_ICON)
    {
        /*
         * [Portrait] : Two panel always display
         * Panel 0 : Cost and time
         * Panel 1 : Icons
         * --------------------
         *  cost           time (Panel 0)
         * --------------------
         *           [][][][][] (Panel 1)
         * --------------------
         *
         *
         * [Landscape] 
         * Panel 0 : Hide
         * Panel 1 : Show time/cost and icons, time/cost will toggle
         * --------------------         
         *                Hide  (Panel 0)
         * --------------------
         * time/cost [][][][][] (Panel 1) 
         * --------------------
         */

        gdi_get_alpha_blending_source_layer(&t_lyr);
        gdi_set_alpha_blending_source_layer(g_mmi_vtcs_cntx.skin_layer_handle);

    #ifndef MMI_VTCS_LANDSCAPE_MODE        
    #if !( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )
        gdi_image_draw_id(
            g_mmi_vtcs_skin_cntx.panel_0_rect.offset_x, 
            g_mmi_vtcs_skin_cntx.panel_0_rect.offset_y, 
            IMG_ID_UCM_VT_BG_PANEL_0);
    #endif            
    #endif /* MMI_VTCS_LANDSCAPE_MODE */
    
        gdi_image_draw_id(
            g_mmi_vtcs_skin_cntx.panel_1_rect.offset_x, 
            g_mmi_vtcs_skin_cntx.panel_1_rect.offset_y, 
            IMG_ID_UCM_VT_BG_PANEL_1);

        /* draw time/cost */
        mmi_vtcs_draw_time_cost();

        /* draw icons */
        #ifdef __MMI_VTCS_FTE__
        mmi_vtcs_draw_camera_icon();
        mmi_vtcs_draw_speaker_icon();       
        mmi_vtcs_draw_ev_icon();
        mmi_vtcs_draw_zoom_icon();
        mmi_vtcs_draw_vk_icon();
        mmi_vtcs_draw_snapshot_icon();            
    #ifdef __MMI_VTCS_OP01__
        mmi_vtcs_draw_contrast_icon();    
        mmi_vtcs_draw_brightness_up_icon();    
        mmi_vtcs_draw_brightness_down_icon();                
		mmi_vtcs_draw_fullscreen_icon();
    #endif
        #else
        #if defined(__MMI_VTCS_OP01__)&& defined(__MMI_TOUCH_SCREEN__)&& (defined(__MMI_MAINLCD_240X400__)||defined(__MMI_MAINLCD_240X320__))
        mmi_vtcs_draw_camera_icon();       
        mmi_vtcs_draw_ev_icon();
        mmi_vtcs_draw_zoom_icon();
		mmi_vtcs_draw_speaker_icon();
        mmi_vtcs_draw_contrast_icon();    
        mmi_vtcs_draw_brightness_up_icon();    
        mmi_vtcs_draw_brightness_down_icon();  
		mmi_vtcs_draw_fullscreen_icon();
        #else
        mmi_vtcs_draw_camera_icon();
        mmi_vtcs_draw_mic_icon();    
        mmi_vtcs_draw_speaker_icon();
        mmi_vtcs_draw_aud_rec_icon();
        mmi_vtcs_draw_snapshot_icon();        
        mmi_vtcs_draw_ev_icon();
        mmi_vtcs_draw_zoom_icon();
        mmi_vtcs_draw_vk_icon();
        #endif
        #endif

        gdi_set_alpha_blending_source_layer(t_lyr);      
    }
    else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_EV ||
             g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_ZOOM ||
             g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_VOL)
    {

        /*
         * [Portrait] : Two panels always display
         * Panel 0 : Slide bar
         * Panel 1 : Icons
         * --------------------
         *  [] ------|------[]  (Panel 0)
         * --------------------
         *     [][][][][][][][] (Panel 1)
         * --------------------
         */

        /*
         * [Landscape]  : Two panels always display
         * Panel 0 : Slide bar
         * Panel 1 : Show time/cost and icons, time/cost will toggle
         * --------------------
         *  [] ------|------[]   (Panel 0)
         * --------------------
         * T/C  [][][][][][][][] (Panel 1)
         * --------------------
         */

        gdi_get_alpha_blending_source_layer(&t_lyr);
        gdi_set_alpha_blending_source_layer(g_mmi_vtcs_cntx.skin_layer_handle);

#if ( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )
        if(g_mmi_vtcs_cntx.is_hide_sub)
        {
            g_mmi_vtcs_skin_cntx.inc_icon_pos.offset_x = 149;
            g_mmi_vtcs_cntx.touch_inc.offset_x = g_mmi_vtcs_skin_cntx.inc_icon_pos.offset_x;            
#endif
            gdi_image_draw_id(
                g_mmi_vtcs_skin_cntx.panel_0_rect.offset_x, 
                g_mmi_vtcs_skin_cntx.panel_0_rect.offset_y, 
                IMG_ID_UCM_VT_BG_PANEL_0);
#if ( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )            
        }
        else
        {
            g_mmi_vtcs_skin_cntx.inc_icon_pos.offset_x = 86;
            g_mmi_vtcs_cntx.touch_inc.offset_x = g_mmi_vtcs_skin_cntx.inc_icon_pos.offset_x;            
            gdi_image_draw_id(
                g_mmi_vtcs_skin_cntx.panel_0_rect.offset_x, 
                g_mmi_vtcs_skin_cntx.panel_0_rect.offset_y, 
                IMG_ID_UCM_VT_BG_PANEL_0_SHORT);
        }
#endif    
        gdi_image_draw_id(
            g_mmi_vtcs_skin_cntx.panel_1_rect.offset_x, 
            g_mmi_vtcs_skin_cntx.panel_1_rect.offset_y, 
            IMG_ID_UCM_VT_BG_PANEL_1);
        
        /* inc icon */
        img_id = g_mmi_vtcs_cntx.scroll_inc_img_id;       
        
        if (g_mmi_vtcs_cntx.touch_inc.is_press)
        {
            img_id++;
        }

        gdi_image_draw_id(
            g_mmi_vtcs_skin_cntx.inc_icon_pos.offset_x, 
            g_mmi_vtcs_skin_cntx.inc_icon_pos.offset_y, 
            img_id);
            
		#if defined(__MMI_FTE_VT_ENHANCE__)
		gdi_image_draw_id(
			g_mmi_vtcs_line_cntx.scroll_line1.offset_x, 
			g_mmi_vtcs_line_cntx.scroll_line1.offset_y, 
			IMG_ID_UCM_VT_PANEL_LINE);
		#endif


        /* dec icon */
        img_id = g_mmi_vtcs_cntx.scroll_dec_img_id;       
        
        if (g_mmi_vtcs_cntx.touch_dec.is_press)
        {
            img_id++;
        }

        gdi_image_draw_id(
            g_mmi_vtcs_skin_cntx.dec_icon_pos.offset_x, 
            g_mmi_vtcs_skin_cntx.dec_icon_pos.offset_y, 
            img_id);
            
		#if defined(__MMI_FTE_VT_ENHANCE__)
		gdi_image_draw_id(
			g_mmi_vtcs_line_cntx.scroll_line2.offset_x, 
			g_mmi_vtcs_line_cntx.scroll_line2.offset_y, 
			IMG_ID_UCM_VT_PANEL_LINE);
		#endif

#if ( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )
        if(g_mmi_vtcs_cntx.is_hide_sub)
        {
            g_mmi_vtcs_skin_cntx.scroll_bar_pos.offset_x = 31;
#endif
            /* bar */
            gdi_image_draw_id(
                g_mmi_vtcs_skin_cntx.scroll_bar_pos.offset_x, 
                g_mmi_vtcs_skin_cntx.scroll_bar_pos.offset_y, 
                IMG_ID_UCM_VT_SCROLL_BAR);

            gdi_image_get_dimension_id(IMG_ID_UCM_VT_SCROLL_BAR, &bar_width, &bar_height);

#if ( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )
        }
        else
        {

            g_mmi_vtcs_skin_cntx.scroll_bar_pos.offset_x = 29;
            /* bar */
            gdi_image_draw_id(
                g_mmi_vtcs_skin_cntx.scroll_bar_pos.offset_x, 
                g_mmi_vtcs_skin_cntx.scroll_bar_pos.offset_y, 
                IMG_ID_UCM_VT_SCROLL_BAR_SHORT);
            
            gdi_image_get_dimension_id(IMG_ID_UCM_VT_SCROLL_BAR_SHORT, &bar_width, &bar_height);            
        }
#endif
        /* slider */
        //gdi_image_get_dimension_id(IMG_ID_UCM_VT_SCROLL_BAR, &bar_width, &bar_height);
        gdi_image_get_dimension_id(IMG_ID_UCM_VT_SCROLL_SLIDER, &slider_width, &slider_height);          

        /* shift from bar's position */
        offset_y =  
            g_mmi_vtcs_skin_cntx.scroll_bar_pos.offset_y - 
            ((slider_height - bar_height) >> 1);   
        
        offset_x = 
            g_mmi_vtcs_skin_cntx.scroll_bar_pos.offset_x +
            g_mmi_vtcs_cntx.scroll_cur_value * 
            (bar_width - slider_width) / 
            (g_mmi_vtcs_cntx.scroll_total_value-1);

        gdi_image_draw_id(
            offset_x, 
            offset_y, 
            IMG_ID_UCM_VT_SCROLL_SLIDER);
        
        g_mmi_vtcs_cntx.touch_slider.offset_x = offset_x;
        g_mmi_vtcs_cntx.touch_slider.offset_y = offset_y;        
        g_mmi_vtcs_cntx.touch_slider.width = slider_width;        
        g_mmi_vtcs_cntx.touch_slider.height = slider_height;     

        g_mmi_vtcs_cntx.bar_step_width_shift10 = (bar_width << 10) / g_mmi_vtcs_cntx.scroll_total_value;
        g_mmi_vtcs_cntx.bar_offset_x = g_mmi_vtcs_skin_cntx.scroll_bar_pos.offset_x;
        g_mmi_vtcs_cntx.bar_width = bar_width;

    #ifdef MMI_VTCS_LANDSCAPE_MODE    
        /* draw time/cost */
        mmi_vtcs_draw_time_cost();
    #endif /* MMI_VTCS_LANDSCAPE_MODE */
    
    #if ( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )
        mmi_vtcs_draw_time_cost();
    #endif
    
        /* draw icons */
        #ifdef __MMI_VTCS_FTE__
        mmi_vtcs_draw_time_cost();        
        mmi_vtcs_open_sub_wnd_hole();
        #else
		#if defined(__MMI_VTCS_OP01__)&& defined(__MMI_TOUCH_SCREEN__)&& (defined(__MMI_MAINLCD_240X400__)||defined(__MMI_MAINLCD_240X320__))
        mmi_vtcs_draw_camera_icon();       
        mmi_vtcs_draw_ev_icon();
        mmi_vtcs_draw_zoom_icon();
		mmi_vtcs_draw_speaker_icon();
        mmi_vtcs_draw_contrast_icon();    
        mmi_vtcs_draw_brightness_up_icon();    
        mmi_vtcs_draw_brightness_down_icon();  
	mmi_vtcs_draw_fullscreen_icon(); 
        #else
        mmi_vtcs_draw_camera_icon();
        mmi_vtcs_draw_mic_icon();    
        mmi_vtcs_draw_speaker_icon();
        mmi_vtcs_draw_aud_rec_icon();
        mmi_vtcs_draw_snapshot_icon();        
        mmi_vtcs_draw_ev_icon();
        mmi_vtcs_draw_zoom_icon();
        mmi_vtcs_draw_vk_icon();
        #endif       
        #endif       

        gdi_set_alpha_blending_source_layer(t_lyr);      
    }
    else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
    {
    
#ifdef __MMI_VTCS_FTE__

    gdi_get_alpha_blending_source_layer(&t_lyr);
	//gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_set_alpha_blending_source_layer(g_mmi_vtcs_cntx.skin_layer_handle);

    gdi_image_get_dimension_id(IMG_ID_UCM_VT_DIAL_BG , &img_width, &img_height);                                                                

    gdi_image_draw_resized_id(                                                  
        g_mmi_vtcs_skin_cntx.body_rect.offset_x,                          
        g_mmi_vtcs_skin_cntx.body_rect.offset_y,          
        g_mmi_vtcs_skin_cntx.body_rect.width,   
        img_height,
        IMG_ID_UCM_VT_DIAL_BG);     

    gdi_image_draw_resized_id(                                                  
        g_mmi_vtcs_skin_cntx.input_box_bg_pos.offset_x,                          
        g_mmi_vtcs_skin_cntx.input_box_bg_pos.offset_y,          
        g_mmi_vtcs_skin_cntx.input_box_rect.width,   
        g_mmi_vtcs_skin_cntx.input_box_rect.height,  
        IMG_ID_UCM_VT_DIAL_INPUT);      

    gdi_image_get_dimension_id(IMG_ID_UCM_VT_DIAL_BG , &img_width, &img_height);  
    gdi_image_get_dimension_id(IMG_ID_UCM_VT_VK_0, &b_img_width, &b_img_height);      

    #define VTCS_DRAW_VK(__x__, __X__) \
        img_id = IMG_ID_UCM_VT_VK_##__X__##;                                        \
        img_id2 = IMG_ID_UCM_VT_DIAL_BT;                                            \
        if (g_mmi_vtcs_cntx.touch_vk_##__x__##.is_press)                            \
        {                                                                           \
            img_id++;                                                               \
            img_id2++;                                                              \
        }                                                                           \
        gdi_image_draw_resized_id(                                                  \
            g_mmi_vtcs_skin_cntx.vk_##__x__##_pos.offset_x,                         \
            g_mmi_vtcs_skin_cntx.vk_##__x__##_pos.offset_y,                         \
            b_img_width,                                                            \
            b_img_height,                                                           \
            img_id2);                                                               \
        gdi_image_draw_id(                                                          \
            g_mmi_vtcs_skin_cntx.vk_##__x__##_pos.offset_x,                         \
            g_mmi_vtcs_skin_cntx.vk_##__x__##_pos.offset_y,                         \
            img_id);                                                                \
            
    #define buf_space 10        

        VTCS_DRAW_VK(0,0);
        VTCS_DRAW_VK(1,1);
        VTCS_DRAW_VK(2,2);        
        VTCS_DRAW_VK(3,3);
        VTCS_DRAW_VK(4,4);
        VTCS_DRAW_VK(5,5);
        VTCS_DRAW_VK(6,6);
        VTCS_DRAW_VK(7,7);
        VTCS_DRAW_VK(8,8);
        VTCS_DRAW_VK(9,9); 
        VTCS_DRAW_VK(star,STAR);
        VTCS_DRAW_VK(pound,POUND);  

        /* draw input number */
        gui_set_font(&MMI_large_font);
        offset_x = g_mmi_vtcs_skin_cntx.input_box_rect.offset_x;
        offset_y = g_mmi_vtcs_skin_cntx.input_box_rect.offset_y;
        {
            U32 str_len;
            U32 i;
            
            str_len = mmi_ucs2strlen(g_mmi_vtcs_cntx.input_box_buf);

            /* right alignment */
            for(i = 0; i < str_len; i++)
            {
                gui_measure_string(
                    (UI_string_type)(g_mmi_vtcs_cntx.input_box_buf + ((str_len - 1 - i) * ENCODING_LENGTH)), 
                    &str_width, 
                    &str_height);

                if (str_width > (g_mmi_vtcs_skin_cntx.input_box_rect.width - buf_space))
                {
                    break;
                }
            }

            gui_measure_string(
                (UI_string_type)(g_mmi_vtcs_cntx.input_box_buf + ((str_len - i) * ENCODING_LENGTH)), 
                &str_width, 
                &str_height);

            if (r2lMMIFlag)
            {
                offset_x += str_width;                
            }
            else
            {                
                offset_x += g_mmi_vtcs_skin_cntx.input_box_rect.width - buf_space - str_width;
            }
            
            gui_move_text_cursor(offset_x, offset_y);
            gui_set_text_color(MMI_VTCS_TEXT_BORDER_COLOR);
            gui_set_text_border_color(MMI_VTCS_TEXT_COLOR);
            gui_print_bordered_text((UI_string_type)(g_mmi_vtcs_cntx.input_box_buf + ((str_len - i) * ENCODING_LENGTH)));          
        }    
        gui_set_font(&MMI_medium_font);
        gdi_set_alpha_blending_source_layer(t_lyr);        
#else
        /*
         * [Portrait][Landscape]  : Two panels always display
         * Panel 0 : input box
         * Panel 1 : VK
         * --------------------
         *  [12345_           ] (Panel 0)
         * --------------------
         *  [][][][][][][]]][]  (Panel 1)
         * --------------------
         */
#if ( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )
        if(g_mmi_vtcs_cntx.is_hide_sub)
        {
#endif
            gdi_image_draw_id(
                g_mmi_vtcs_skin_cntx.panel_0_rect.offset_x, 
                g_mmi_vtcs_skin_cntx.panel_0_rect.offset_y, 
                IMG_ID_UCM_VT_BG_PANEL_0);


#if ( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )            
        }
        else
        {
            gdi_image_draw_id(
                g_mmi_vtcs_skin_cntx.panel_0_rect.offset_x, 
                g_mmi_vtcs_skin_cntx.panel_0_rect.offset_y, 
                IMG_ID_UCM_VT_BG_PANEL_0_SHORT);            
        }
#endif
        
        gdi_image_draw_id(
            g_mmi_vtcs_skin_cntx.panel_1_rect.offset_x, 
            g_mmi_vtcs_skin_cntx.panel_1_rect.offset_y, 
            IMG_ID_UCM_VT_BG_PANEL_1);
        
        /* draw VK */
    #define VTCS_DRAW_VK(__x__, __X__) \
        img_id = IMG_ID_UCM_VT_VK_##__X__##;                                            \
        if (g_mmi_vtcs_cntx.touch_vk_##__x__##.is_press)                            \
        {                                                                           \
            img_id++;                                                               \
        }                                                                           \
        gdi_image_draw_id(                                                          \
            g_mmi_vtcs_skin_cntx.vk_##__x__##_pos.offset_x,                         \
            g_mmi_vtcs_skin_cntx.vk_##__x__##_pos.offset_y,                         \
            img_id);                                                                \

        VTCS_DRAW_VK(0,0);
        VTCS_DRAW_VK(1,1);
        VTCS_DRAW_VK(2,2);        
        VTCS_DRAW_VK(3,3);
        VTCS_DRAW_VK(4,4);
        VTCS_DRAW_VK(5,5);
        VTCS_DRAW_VK(6,6);
        VTCS_DRAW_VK(7,7);
        VTCS_DRAW_VK(8,8);
        VTCS_DRAW_VK(9,9); 
        VTCS_DRAW_VK(star,STAR);
        VTCS_DRAW_VK(pound,POUND);    

        /* draw input box */
        offset_x = g_mmi_vtcs_skin_cntx.input_box_bg_pos.offset_x;
        offset_y = g_mmi_vtcs_skin_cntx.input_box_bg_pos.offset_y;
#if ( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )
        if(g_mmi_vtcs_cntx.is_hide_sub)
        {
#endif
            gdi_image_draw_id(offset_x, offset_y, IMG_ID_UCM_VT_INPUT_BOX); 

#if ( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )            
            g_mmi_vtcs_skin_cntx.input_box_rect.width = 160;
        }
        else
        {

            gdi_image_draw_id(offset_x, offset_y, IMG_ID_UCM_VT_INPUT_BOX_SHORT); 
            g_mmi_vtcs_skin_cntx.input_box_rect.width = 100;            

        }
#endif

        /* draw input number */
        offset_x = g_mmi_vtcs_skin_cntx.input_box_rect.offset_x;
        offset_y = g_mmi_vtcs_skin_cntx.input_box_rect.offset_y;
        {
            U32 str_len;
            S32 i;
            
            str_len = mmi_ucs2strlen(g_mmi_vtcs_cntx.input_box_buf);

            /* right alignment */
            for(i = 0; i < str_len; i++)
            {
                gui_measure_string(
                    (UI_string_type)(g_mmi_vtcs_cntx.input_box_buf + ((str_len - 1 - i) * ENCODING_LENGTH)), 
                    &str_width, 
                    &str_height);

                if (str_width > g_mmi_vtcs_skin_cntx.input_box_rect.width)
                {
                    break;
                }
            }

            gui_measure_string(
                (UI_string_type)(g_mmi_vtcs_cntx.input_box_buf + ((str_len - i) * ENCODING_LENGTH)), 
                &str_width, 
                &str_height);

            if (r2lMMIFlag)
            {
                offset_x += str_width;                
            }
            else
            {                
                offset_x += g_mmi_vtcs_skin_cntx.input_box_rect.width - str_width;
            }
            gui_move_text_cursor(offset_x, offset_y);
            gui_set_text_color(MMI_VTCS_TEXT_COLOR);
            gui_set_text_border_color(MMI_VTCS_TEXT_BORDER_COLOR);
            gui_print_bordered_text((UI_string_type)(g_mmi_vtcs_cntx.input_box_buf + ((str_len - i) * ENCODING_LENGTH)));          
        }
#endif
           
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }
   
    gdi_layer_pop_and_restore_active();
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_time_cost
 * DESCRIPTION
 *  Draw time cost
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_time_cost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U16 hr;
    U16 min;
    U16 sec;
    U32 remain;
    S32 offset_x;
    S32 str_width;
    S32 str_height;
    CHAR  tmp_buf[20];
    CHAR  tmp_buf_ucs2[20];    
    CHAR  time_buf_ucs2[50];  
	S32 temp_offset_x;
    S32 temp_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_TIME_COST,g_mmi_vtcs_cntx.call_dur, g_mmi_vtcs_cntx.is_display_cost);
    if (!mmi_ucm_vt_get_call_timer_display_setting())
    {
        /* do not draw call time */
        return;
    }

    if(g_mmi_vtcs_cntx.is_fullscreen_state)
    {
        temp_offset_x =g_mmi_vtcs_skin_cntx.fullscr_time_pos.offset_x;
		temp_offset_y =g_mmi_vtcs_skin_cntx.fullscr_time_pos.offset_y;
    }
	else
	{
		temp_offset_x = g_mmi_vtcs_skin_cntx.time_pos.offset_x;
	    temp_offset_y = g_mmi_vtcs_skin_cntx.time_pos.offset_y;
	}

    /* draw time */
    memset(time_buf_ucs2, 0, sizeof(time_buf_ucs2));
    
    /* hr */
    hr = g_mmi_vtcs_cntx.call_dur / (60 * 60);
    remain = g_mmi_vtcs_cntx.call_dur % (60 * 60);
    
    sprintf(tmp_buf, "%02d", hr);
    mmi_asc_to_ucs2(tmp_buf_ucs2, tmp_buf);
    mmi_ucs2cat(time_buf_ucs2, tmp_buf_ucs2);    
    mmi_ucs2cat(time_buf_ucs2, (CHAR *)L":");

    /* min */
    min = remain / 60 ;
    sec = remain % 60;
    
    sprintf(tmp_buf, "%02d", min);
    mmi_asc_to_ucs2(tmp_buf_ucs2, tmp_buf);     
    mmi_ucs2cat(time_buf_ucs2, tmp_buf_ucs2);         
    mmi_ucs2cat(time_buf_ucs2, (CHAR *)L":");   

    /* sec */
    sprintf(tmp_buf, "%02d", sec);
    mmi_asc_to_ucs2(tmp_buf_ucs2, tmp_buf); 
    mmi_ucs2cat(time_buf_ucs2, tmp_buf_ucs2);

#if ( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )
    gui_set_font(&MMI_small_font);
#elif defined(__MMI_FTE_SUPPORT__)&& defined(__MMI_MAINLCD_240X320__)
	gui_set_font(&MMI_small_font);
#else
    gui_set_font(&MMI_medium_font);    
#endif

    if (r2lMMIFlag)
    {
        gui_measure_string((UI_string_type)time_buf_ucs2, &str_width, &str_height);        
        offset_x = temp_offset_x + str_width;
    }
    else
    {
        offset_x = temp_offset_x;
    }
    
    gui_move_text_cursor(offset_x, temp_offset_y);
			//if(is_fullscreen_state)
      // {
			//gui_set_text_color(gui_color(0,0,255));
			//gui_set_text_border_color(gui_color(0,0,255));
      // }
	  // else
	  // {
		 // gui_set_text_color(MMI_VTCS_TEXT_COLOR);
	     // gui_set_text_border_color(MMI_VTCS_TEXT_BORDER_COLOR);
	   //}
    gui_set_text_color(MMI_VTCS_TEXT_COLOR);
    gui_set_text_border_color(MMI_VTCS_TEXT_BORDER_COLOR);
    gui_print_bordered_text((UI_string_type)time_buf_ucs2);  


#ifndef __MMI_VTCS_FTE__   
    /* draw cost */
    if (g_mmi_vtcs_cntx.is_display_cost)
    {
        if (r2lMMIFlag)
        {
            gui_measure_string((UI_string_type)g_mmi_vtcs_cntx.call_cost_str, &str_width, &str_height);        
            offset_x = temp_offset_x + str_width;
        }
        else
        {
            offset_x = temp_offset_x;
        }
        
        gui_move_text_cursor(offset_x, temp_offset_y);
		/*
		if(is_fullscreen_state)
       {
			gui_set_text_color(gui_color(0,0,255));
			gui_set_text_border_color(gui_color(0,0,255));
       }
	   else
	   {
		  gui_set_text_color(MMI_VTCS_TEXT_COLOR);
	      gui_set_text_border_color(MMI_VTCS_TEXT_BORDER_COLOR);
	   }
	   */
        gui_set_text_color(MMI_VTCS_TEXT_COLOR);
        gui_set_text_border_color(MMI_VTCS_TEXT_BORDER_COLOR);
        gui_print_bordered_text((UI_string_type)g_mmi_vtcs_cntx.call_cost_str);
    }
#endif
#if ( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )
    gui_set_font(&MMI_medium_font);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_panel_camera
 * DESCRIPTION
 *  Draw camera icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_camera_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id = IMG_ID_UCM_VT_CAMERA_OFF;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_CAMERA_ICON,g_mmi_vtcs_cntx.camera_state, g_mmi_vtcs_cntx.touch_camera.is_usable,g_mmi_vtcs_cntx.touch_camera.is_press);
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_camera.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_camera.offset_y - layer_offset_y;   

    if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_OFF)
    {
        image_id = IMG_ID_UCM_VT_CAMERA_OFF;
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_ON)
    {
        image_id = IMG_ID_UCM_VT_CAMERA_ON; 
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_FRONT)
    {
        image_id = IMG_ID_UCM_VT_CAMERA_FRONT; 
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_BACK)
    {
        image_id = IMG_ID_UCM_VT_CAMERA_BACK; 
    }
    else
    {
        MMI_ASSERT(0);
    }
   

    if (g_mmi_vtcs_cntx.touch_camera.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_camera.is_press)
        {
            /* _PRESS image */
            image_id += 1;
        }
    }
    else
    {
        /* _DISABLE image */
        image_id += 2;
    }
#if defined(__MMI_FTE_VT_ENHANCE__)
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_PANEL_BG_3);
#endif   
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);
	#ifdef  __MMI_UCM_VT_FEATURE_TOUCH__
	#if defined(__MMI_FTE_VT_ENHANCE__)
	offset_x = g_mmi_vtcs_line_cntx.line3.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_line_cntx.line3.offset_y - layer_offset_y;
	gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_PANEL_LINE);
	#endif
	#endif

    /* TODO: highlight box for key only */
//    gdi_image_draw_id(
//        offset_x, 
//        offset_y, 
//        IMG_ID_UCM_VT_ICON_HIGHLIGHT);

    gdi_layer_pop_and_restore_active();    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_panel_mic
 * DESCRIPTION
 *  Draw mic icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_mic_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id = IMG_ID_UCM_VT_MIC_OFF;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_MIC_ICON,g_mmi_vtcs_cntx.mic_state, g_mmi_vtcs_cntx.touch_mic.is_usable,g_mmi_vtcs_cntx.touch_mic.is_press);    
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_mic.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_mic.offset_y - layer_offset_y;   

    if (g_mmi_vtcs_cntx.mic_state == MMI_VT_MIC_OFF)
    {
        image_id = IMG_ID_UCM_VT_MIC_OFF;
    }
    else if (g_mmi_vtcs_cntx.mic_state == MMI_VT_MIC_ON)
    {
        image_id = IMG_ID_UCM_VT_MIC_ON; 
    }

    if (g_mmi_vtcs_cntx.touch_mic.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_mic.is_press)
        {
            /* _PRESS image */
            image_id += 1;
        }
    }
    else
    {
        /* _DISABLE image */
        image_id += 2;
    }    
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);

    gdi_layer_pop_and_restore_active();    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_speaker_icon
 * DESCRIPTION
 *  Draw speaker icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_speaker_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id = IMG_ID_UCM_VT_SPEAKER_OFF;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_SPEAKER_ICON,g_mmi_vtcs_cntx.speaker_state, g_mmi_vtcs_cntx.touch_speaker.is_usable,g_mmi_vtcs_cntx.touch_speaker.is_press);        
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_speaker.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_speaker.offset_y - layer_offset_y;   

    if (g_mmi_vtcs_cntx.speaker_state == MMI_VT_SPEAKER_OFF)
    {
        image_id = IMG_ID_UCM_VT_SPEAKER_OFF;
    }
    else if (g_mmi_vtcs_cntx.speaker_state == MMI_VT_SPEAKER_ON)
    {
        image_id = IMG_ID_UCM_VT_SPEAKER_ON; 
    }    
    
    if (g_mmi_vtcs_cntx.touch_speaker.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_speaker.is_press)
        {
            /* _PRESS image */
            image_id += 1;
        }
    }
    else
    {
        /* _DISABLE image */
        image_id += 2;
    }
#if defined(__MMI_FTE_VT_ENHANCE__)
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_PANEL_BG_4);
#endif
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);
    #ifdef  __MMI_UCM_VT_FEATURE_TOUCH__
	#if defined(__MMI_FTE_VT_ENHANCE__)
	offset_x = g_mmi_vtcs_line_cntx.line4.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_line_cntx.line4.offset_y - layer_offset_y;
	gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_PANEL_LINE);
	#endif
	#endif
	

    gdi_layer_pop_and_restore_active();    
    
}

#ifdef __MMI_VTCS_OP01__
/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_brightness_up_icon
 * DESCRIPTION
 *  Draw brightness icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_brightness_up_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_brightness_up.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_brightness_up.offset_y - layer_offset_y;   

	#if defined(__MMI_FTE_VT_ENHANCE__)
	gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_SINGLE_ICON_BG);
	#endif

    image_id = IMG_ID_UCM_VT_BRIGHTNESS_UP;
    
    if (g_mmi_vtcs_cntx.touch_brightness_up.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_brightness_up.is_press)
        {
            /* _PRESS image */
            image_id += 1;
        }
    }
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);

    gdi_layer_pop_and_restore_active();    
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_brightness_down_icon
 * DESCRIPTION
 *  Draw brightness icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_brightness_down_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_brightness_down.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_brightness_down.offset_y - layer_offset_y;   

	#if defined(__MMI_FTE_VT_ENHANCE__)
	gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_SINGLE_ICON_BG);
	#endif


    image_id = IMG_ID_UCM_VT_BRIGHTNESS_DOWN;
    
    if (g_mmi_vtcs_cntx.touch_brightness_down.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_brightness_down.is_press)
        {
            /* _PRESS image */
            image_id += 1;
        }
    }
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);

    gdi_layer_pop_and_restore_active();    
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_contrast_icon
 * DESCRIPTION
 *  Draw contrast icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_contrast_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id = IMG_ID_UCM_VT_CONTRAST_NORMAL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if(g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_OFF)
    {
        return;
    }
    
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_contrast.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_contrast.offset_y - layer_offset_y;   

    if (g_mmi_vtcs_cntx.contrast_state == MMI_VT_CONTRAST_NORMAL)
    {
        image_id = IMG_ID_UCM_VT_CONTRAST_NORMAL;
    }
    else if (g_mmi_vtcs_cntx.contrast_state == MMI_VT_CONTRAST_ENHANCE)
    {
        image_id = IMG_ID_UCM_VT_CONTRAST_ENHANCE; 
    }
    else if (g_mmi_vtcs_cntx.contrast_state == MMI_VT_CONTRAST_REDUCE)
    {
        image_id = IMG_ID_UCM_VT_CONTRAST_RESUCED; 
    }      
    #if defined(__MMI_FTE_VT_ENHANCE__)
	gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_SINGLE_ICON_BG);
	#endif
    
    if (g_mmi_vtcs_cntx.touch_contrast.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_contrast.is_press)
        {
            /* _PRESS image */
            image_id += 1;
        }
    }
    else
    {
        /* _DISABLE image */
        image_id += 2;
    }
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);

    gdi_layer_pop_and_restore_active();    
    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_fullscreen_icon
 * DESCRIPTION
 *  Draw fullscreen icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_fullscreen_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_fullscreen.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_fullscreen.offset_y - layer_offset_y;   

    image_id = IMG_ID_UCM_VT_FULLSCR_ICON;

	#if defined(__MMI_FTE_VT_ENHANCE__)
	gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_SINGLE_ICON_BG);
	#endif
    
    if (g_mmi_vtcs_cntx.touch_fullscreen.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_fullscreen.is_press)
        {
            /* _PRESS image */
            image_id += 1;
        }
    }
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);

    gdi_layer_pop_and_restore_active();    
    
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_aud_rec_icon
 * DESCRIPTION
 *  Draw aud_rec icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_aud_rec_icon(void)
{
#ifdef __MMI_UCM_VT_FEATURE_AUD_REC__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_AUD_REC_ICON,g_mmi_vtcs_cntx.aud_rec_state, g_mmi_vtcs_cntx.touch_aud_rec.is_usable,g_mmi_vtcs_cntx.touch_aud_rec.is_press);        
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_aud_rec.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_aud_rec.offset_y - layer_offset_y;   

    if (g_mmi_vtcs_cntx.aud_rec_state == MMI_VT_AUD_REC_OFF)
    {
        image_id = IMG_ID_UCM_VT_AUD_REC_OFF;
    }
    else if (g_mmi_vtcs_cntx.aud_rec_state == MMI_VT_AUD_REC_ON)
    {
        image_id = IMG_ID_UCM_VT_AUD_REC_ON; 
    }

    if (g_mmi_vtcs_cntx.touch_aud_rec.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_aud_rec.is_press)
        {
            /* _PRESS image */
            image_id += 1;
        }
    }
    else
    {
        /* _DISABLE image */
        image_id += 2;
    }
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);    

    gdi_layer_pop_and_restore_active();    
    
#endif /*  __MMI_UCM_VT_FEATURE_AUD_REC__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_snapshot_icon
 * DESCRIPTION
 *  Draw snapshot icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_snapshot_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_SNAPSHOT_ICON,g_mmi_vtcs_cntx.camera_state,g_mmi_vtcs_cntx.touch_snapshot.is_usable,g_mmi_vtcs_cntx.touch_snapshot.is_press);        
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_snapshot.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_snapshot.offset_y - layer_offset_y;   
    image_id = IMG_ID_UCM_VT_SNAPSHOT;
 
    if (g_mmi_vtcs_cntx.touch_snapshot.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_snapshot.is_press)
        {
            /* _PRESS image */
            image_id += 1;
        }
    }
    else
    {
        /* _DISABLE image */
        image_id += 2;
    }
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);    

    gdi_layer_pop_and_restore_active();    
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_ev_icon
 * DESCRIPTION
 *  Draw ev icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_ev_icon(void)
{
#ifdef __MMI_UCM_VT_FEATURE_TOUCH__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_EV_ICON,g_mmi_vtcs_cntx.ev_value, g_mmi_vtcs_cntx.touch_ev.is_usable,g_mmi_vtcs_cntx.touch_ev.is_press);        
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_ev.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_ev.offset_y - layer_offset_y;   

    if (g_mmi_vtcs_cntx.touch_ev.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_ev.is_press)
        {
            image_id = IMG_ID_UCM_VT_EV_PRESS;
        }
        else
        {
            image_id = IMG_ID_UCM_VT_EV;
        }
    }
    else
    {
        image_id = IMG_ID_UCM_VT_EV_DISABLE;
    }
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);

    gdi_layer_pop_and_restore_active();
	#ifdef  __MMI_UCM_VT_FEATURE_TOUCH__
	#if defined(__MMI_FTE_VT_ENHANCE__)
	offset_x = g_mmi_vtcs_line_cntx.line2.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_line_cntx.line2.offset_y - layer_offset_y;
	gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_PANEL_LINE);
	#endif
	#endif
#endif /* __MMI_UCM_VT_FEATURE_TOUCH__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_zoom_icon
 * DESCRIPTION
 *  Draw zoom icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_zoom_icon(void)
{
#ifdef __MMI_UCM_VT_FEATURE_TOUCH__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_ZOOM_ICON,g_mmi_vtcs_cntx.zoom_step, g_mmi_vtcs_cntx.touch_zoom.is_usable,g_mmi_vtcs_cntx.touch_zoom.is_press);        
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_zoom.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_zoom.offset_y - layer_offset_y;   
    
    if (g_mmi_vtcs_cntx.touch_zoom.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_zoom.is_press)
        {
            image_id = IMG_ID_UCM_VT_ZOOM_PRESS;
        }
        else
        {
            image_id = IMG_ID_UCM_VT_ZOOM;
        }
    }
    else
    {
        image_id = IMG_ID_UCM_VT_ZOOM_DISABLE;
    }

    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);
	#ifdef  __MMI_UCM_VT_FEATURE_TOUCH__
	#if defined(__MMI_FTE_VT_ENHANCE__)
	offset_x = g_mmi_vtcs_line_cntx.line1.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_line_cntx.line1.offset_y - layer_offset_y;
	gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_PANEL_LINE);
	#endif
	#endif
    gdi_layer_pop_and_restore_active();    
#endif /* __MMI_UCM_VT_FEATURE_TOUCH__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_vk_icon
 * DESCRIPTION
 *  Draw zoom icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_vk_icon(void)
{
#ifdef __MMI_UCM_VT_FEATURE_TOUCH__       
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_VK_ICON,0, g_mmi_vtcs_cntx.touch_vk.is_usable,g_mmi_vtcs_cntx.touch_vk.is_press);        
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_vk.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_vk.offset_y - layer_offset_y;   
    
    if (g_mmi_vtcs_cntx.touch_vk.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_vk.is_press)
        {
            image_id = IMG_ID_UCM_VT_VK_PRESS;
        }
        else
        {
            image_id = IMG_ID_UCM_VT_VK;
        }
    }
    else
    {
        image_id = IMG_ID_UCM_VT_VK_DISABLE;
    }

    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);

    gdi_layer_pop_and_restore_active();    
#endif /* __MMI_UCM_VT_FEATURE_TOUCH__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_set_softkey
 * DESCRIPTION
 *  Set softkey string id
 * PARAMETERS
 *  lsk_id      [IN]         lsk_string_id
 *  rsk_id      [IN]         rsk_string_id 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_set_softkey(U16 lsk_id, U16 rsk_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_SET_SOFTKEY,lsk_id ,rsk_id);        
    
    g_mmi_vtcs_cntx.lsk_str_id = lsk_id;
    g_mmi_vtcs_cntx.rsk_str_id = rsk_id;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_softkey
 * DESCRIPTION
 *  Draw softkey region
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;  
#ifndef __MMI_VTCS_FTE__      
    S32 str_width;
    S32 str_height;
    S32 lsk_offset_x;
    S32 lsk_offset_y;    
    S32 lsk_truncate_width;
    S32 rsk_offset_x;
    S32 rsk_offset_y;    
    S32 rsk_truncate_width;
#endif    
#ifdef __MMI_VTCS_FTE__
	U16 image_id = 0;
    S32 img_width, img_height;
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_SOFTKEY,g_mmi_vtcs_cntx.lsk_str_id,g_mmi_vtcs_cntx.rsk_str_id);
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_reset_clip();
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_BUTTON));  
    
    offset_x = g_mmi_vtcs_skin_cntx.softkey_rect.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.softkey_rect.offset_y - layer_offset_y;    
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_BG_SOFTKEY);

#ifdef __MMI_VTCS_FTE__        
    // because the snapshot icon is on softkey bar, redraw to avoid be covered by sk bar
    if(!g_mmi_vtcs_cntx.is_fullscreen_state && 
		g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_TIME_ICON)
    {
    mmi_vtcs_draw_snapshot_icon();
    }
#endif
    
    /* draw softkey string */
    /* LSK */
    if (g_mmi_vtcs_cntx.lsk_str_id != 0 
#if defined(__MMI_BACKGROUND_CALL__)        
        && !srv_ucm_is_background_call()
#endif        
        )
    {
#ifdef __MMI_VTCS_FTE__    
    if(g_mmi_vtcs_cntx.panel_state != MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
    {
        if (g_mmi_vtcs_cntx.touch_lsk.is_press)
        {
            image_id = IMG_ID_UCM_VT_OPTION_PRESS;
        }
        else
        {
            image_id = IMG_ID_UCM_VT_OPTION;
        }   

        gdi_image_get_dimension_id(image_id , &img_width, &img_height);  
        g_mmi_vtcs_cntx.touch_lsk.offset_x = g_mmi_vtcs_skin_cntx.icon_6_pos.offset_x;
        g_mmi_vtcs_cntx.touch_lsk.offset_y = g_mmi_vtcs_skin_cntx.icon_6_pos.offset_y;
        g_mmi_vtcs_cntx.touch_lsk.width = img_width;
        g_mmi_vtcs_cntx.touch_lsk.height = img_height;
        g_mmi_vtcs_cntx.touch_lsk.is_usable = MMI_TRUE;    
      
        gdi_image_draw_id(
            g_mmi_vtcs_cntx.touch_lsk.offset_x, 
            g_mmi_vtcs_cntx.touch_lsk.offset_y, 
            image_id);
        
    }
#else
        wgui_softkey_get_offset(
            get_string(g_mmi_vtcs_cntx.lsk_str_id),
            &lsk_offset_x,
            &lsk_offset_y,
            &lsk_truncate_width,
            MMI_LEFT_SOFTKEY,
            mmi_frm_get_screen_rotate());
        
        gui_measure_string(get_string(g_mmi_vtcs_cntx.lsk_str_id), &str_width, &str_height);

        if (g_mmi_vtcs_cntx.touch_lsk.is_press)
        {
            lsk_offset_x++;
            lsk_offset_y++;
        }

        lsk_offset_x -= layer_offset_x;
        lsk_offset_y -= layer_offset_y;  

        gui_move_text_cursor(lsk_offset_x, lsk_offset_y);
        gui_set_text_color(MMI_VTCS_TEXT_COLOR);
        gui_set_text_border_color(MMI_VTCS_TEXT_BORDER_COLOR);
        gui_print_bordered_text(get_string(g_mmi_vtcs_cntx.lsk_str_id));

        if (r2lMMIFlag)
        {
            g_mmi_vtcs_cntx.touch_lsk.offset_x = lsk_offset_x - str_width;
        }
        else
        {
            g_mmi_vtcs_cntx.touch_lsk.offset_x = lsk_offset_x;
        }

        g_mmi_vtcs_cntx.touch_lsk.offset_y = lsk_offset_y;
        g_mmi_vtcs_cntx.touch_lsk.width = str_width;
        g_mmi_vtcs_cntx.touch_lsk.height = str_height;
        g_mmi_vtcs_cntx.touch_lsk.is_usable = MMI_TRUE;

#endif
#ifdef __MMI_VTCS_FTE__    
    if(g_mmi_vtcs_cntx.panel_state != MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
    {
#endif
        SetKeyHandler(mmi_vtcs_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_lsk_release, KEY_LSK, KEY_EVENT_UP);           
#ifdef __MMI_VTCS_FTE__    
    }
#endif       
    }
    else
    {
        g_mmi_vtcs_cntx.touch_lsk.is_usable = MMI_FALSE;

        SetKeyHandler(NULL, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_LSK, KEY_EVENT_UP);           
    }        


    /* RSK */
    if (g_mmi_vtcs_cntx.rsk_str_id != 0)
    {
#ifdef __MMI_VTCS_FTE__    

    if(g_mmi_vtcs_cntx.rsk_str_id == STR_ID_UCM_VT_RSK_HANDS_HELD)
    {
        if (g_mmi_vtcs_cntx.touch_rsk.is_press)
        {
            image_id = IMG_ID_UCM_VT_H_HELD_PRESS;
        }
        else
        {
            image_id = IMG_ID_UCM_VT_H_HELD;
        }
    }
    else if(g_mmi_vtcs_cntx.rsk_str_id == STR_ID_UCM_VT_RSK_HANDS_FREE)
    {
        if (g_mmi_vtcs_cntx.touch_rsk.is_press)
        {
            image_id = IMG_ID_UCM_VT_H_FREE_PRESS;
        }
        else
        {
            image_id = IMG_ID_UCM_VT_H_FREE;
        }
    }
    else if(g_mmi_vtcs_cntx.rsk_str_id == STR_GLOBAL_BACK)
    {
        if (g_mmi_vtcs_cntx.touch_rsk.is_press)
        {
            image_id = IMG_ID_UCM_VT_BACK_PRESS;
        }
        else
        {
            image_id = IMG_ID_UCM_VT_BACK;
        }
    }
    else
    {
        ASSERT(0);
    }
    
    gdi_image_get_dimension_id(image_id , &img_width, &img_height);  
    g_mmi_vtcs_cntx.touch_rsk.offset_x = g_mmi_vtcs_skin_cntx.icon_7_pos.offset_x;
    g_mmi_vtcs_cntx.touch_rsk.offset_y = g_mmi_vtcs_skin_cntx.icon_7_pos.offset_y;
    g_mmi_vtcs_cntx.touch_rsk.width = img_width;
    g_mmi_vtcs_cntx.touch_rsk.height = img_height;
    g_mmi_vtcs_cntx.touch_rsk.is_usable = MMI_TRUE;    
  
    gdi_image_draw_id(
        g_mmi_vtcs_cntx.touch_rsk.offset_x, 
        g_mmi_vtcs_cntx.touch_rsk.offset_y, 
        image_id);
    
#else    
        wgui_softkey_get_offset(
            get_string(g_mmi_vtcs_cntx.rsk_str_id),
            &rsk_offset_x,
            &rsk_offset_y,
            &rsk_truncate_width,
            MMI_RIGHT_SOFTKEY,
            mmi_frm_get_screen_rotate());

        gui_measure_string(get_string(g_mmi_vtcs_cntx.rsk_str_id), &str_width, &str_height);

        if (g_mmi_vtcs_cntx.touch_rsk.is_press)
        {
            rsk_offset_x++;
            rsk_offset_y++;
        }

        rsk_offset_x -= layer_offset_x;
        rsk_offset_y -= layer_offset_y;        

        gui_move_text_cursor(rsk_offset_x, rsk_offset_y);
        gui_set_text_color(MMI_VTCS_TEXT_COLOR);
        gui_set_text_border_color(MMI_VTCS_TEXT_BORDER_COLOR);
        gui_print_bordered_text(get_string(g_mmi_vtcs_cntx.rsk_str_id));

        if (r2lMMIFlag)
        {
            g_mmi_vtcs_cntx.touch_rsk.offset_x = rsk_offset_x - str_width;
        }
        else
        {
            g_mmi_vtcs_cntx.touch_rsk.offset_x = rsk_offset_x;
        }

        g_mmi_vtcs_cntx.touch_rsk.offset_y = rsk_offset_y;
        g_mmi_vtcs_cntx.touch_rsk.width = str_width;
        g_mmi_vtcs_cntx.touch_rsk.height = str_height;
        g_mmi_vtcs_cntx.touch_rsk.is_usable = MMI_TRUE;  
#endif        
        SetKeyHandler(mmi_vtcs_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_rsk_release, KEY_RSK, KEY_EVENT_UP);           
        
    }
    else
    {
        g_mmi_vtcs_cntx.touch_rsk.is_usable = MMI_FALSE;
        SetKeyHandler(NULL, KEY_RSK, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_RSK, KEY_EVENT_UP);           
    }        
    
    gui_set_font(&MMI_medium_font);
    
    gdi_layer_pop_and_restore_active();

}


static void mmi_vtcs_draw_image_id(U16 image_id, S32 layer_width, S32 layer_height)
{
    GDI_RESULT ret;
    S32 image_width;
    S32 image_height;
    S32 resized_width;
    S32 resized_height;
    S32 resized_offset_x;
    S32 resized_offset_y;

    ret = gdi_image_get_dimension_id(image_id, &image_width, &image_height);

    if (ret == GDI_SUCCEED && image_width != 0 && image_height != 0)
    {
        if(image_width < layer_width && image_height < layer_height)
        {
            gdi_util_fit_box(                                           
    			GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,               
    			layer_width,                                            
    			layer_height,                                           
    			image_width,                                            
    			image_height,                                           
    			&resized_offset_x,                                      
    			&resized_offset_y,                                      
    			&resized_width,                                         
    			&resized_height);
        }
        else
        {
            gdi_image_util_fit_bbox(  
    		    layer_width,  
    			layer_height, 
    			image_width,  
    			image_height, 
    			&resized_offset_x,
    			&resized_offset_y, 
    			&resized_width, 
    			&resized_height);
        }
            
        gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR); 
		gdi_image_draw_resized_id(                                  
			resized_offset_x,                                       
			resized_offset_y,                                       
			resized_width,                                          
			resized_height,                                         
			image_id);
    }
}

static void mmi_vtcs_draw_image_file(S8 *file, S32 layer_width, S32 layer_height, gdi_handle alpha_blending_src_layer)
{
    GDI_RESULT ret;
    S32 image_width;
    S32 image_height;
    S32 resized_width;
    S32 resized_height;
    S32 resized_offset_x;
    S32 resized_offset_y;

    ret = gdi_image_get_dimension_file(file, &image_width, &image_height);

    if (ret == GDI_SUCCEED && image_width != 0 && image_height != 0)
    {
        if(image_width < layer_width && image_height < layer_height)
        {
            gdi_util_fit_box(                                           
    			GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,               
    			layer_width,                                            
    			layer_height,                                           
    			image_width,                                            
    			image_height,                                           
    			&resized_offset_x,                                      
    			&resized_offset_y,                                      
    			&resized_width,                                         
    			&resized_height);
        }
        else
        {
            gdi_image_util_fit_bbox(  
    		    layer_width,  
    			layer_height, 
    			image_width,  
    			image_height, 
    			&resized_offset_x,
    			&resized_offset_y, 
    			&resized_width, 
    			&resized_height);
        }
            
        gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR);     
		/* to prevent image to blending with wrong layer */
        gdi_push_and_set_alpha_blending_source_layer(alpha_blending_src_layer);
		
        ret = gdi_image_draw_resized_file(
                resized_offset_x, 
                resized_offset_y, 
                resized_width, 
                resized_height,
                file);

        gdi_pop_and_restore_alpha_blending_source_layer();  

        if(ret != GDI_SUCCEED)
        {
            gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR); 
			mmi_vtcs_draw_image_id(IMG_ID_UCM_VT_MAIN_WND_PEER, layer_width, layer_height);
        }
    }
    else
    {
        mmi_vtcs_draw_image_id(IMG_ID_UCM_VT_MAIN_WND_PEER, layer_width, layer_height);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_main_wnd
 * DESCRIPTION
 *  Draw main window layer based on display type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_main_wnd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;    
    S32 layer_width;
    S32 layer_height;
    S32 resized_width;
    S32 resized_height;
    S32 resized_offset_x;
    S32 resized_offset_y;    
	S32 layer_x;
    S32 layer_y; 
    GDI_RESULT ret;
	gdi_handle main_layer_temp_handle = 0;
	gdi_handle main_layer_temp_handle_bt = 0;
	MMI_BOOL is_hw_layer = MMI_FALSE;
	U8 *gdi_layer_buffer_ptr;
	MMI_BOOL is_cf_suc;
	gdi_color_format layer_color_format;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_MAIN_WND,g_mmi_vtcs_cntx.mode,g_mmi_vtcs_cntx.local_img_state);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	
	if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_6)
	{
		main_layer_temp_handle_bt = g_mmi_vtcs_cntx.main_wnd_hw_layer_handle;
		//mdi_util_hw_layer_switch_to_sw_layer(main_layer_temp_handle);
		is_hw_layer = MMI_TRUE;
	}
	else
	{
		main_layer_temp_handle_bt = g_mmi_vtcs_cntx.main_wnd_layer_handle;
	}
    gdi_layer_push_and_set_active(main_layer_temp_handle_bt);
	gdi_layer_get_buffer_ptr(&gdi_layer_buffer_ptr);
	gdi_layer_get_dimension(&layer_width, &layer_height);
	gdi_layer_get_position(&layer_x, &layer_y);
	gdi_layer_get_color_format(&layer_color_format);
	gdi_layer_pop_and_restore_active();

	gdi_layer_create_using_outside_memory(
        layer_x,
        layer_y,
        layer_width,
        layer_height,
        &main_layer_temp_handle,
        (PU8)gdi_layer_buffer_ptr,
        (layer_width*layer_height*2));
	
	gdi_layer_push_and_set_active(main_layer_temp_handle);
	gdi_layer_get_dimension(&layer_width, &layer_height);

	//if(is_hw_layer == MMI_TRUE)
	//{
	//	gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
	//}
 
    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_7)
    {
        /* PEER MAIN (Video, Image) */              
        if (g_mmi_vtcs_cntx.peer_img_state == MMI_VTCS_LOCAL_IMG_DEFAULT_ID)
        {
            //gdi_image_draw_id(0, 0, IMG_ID_UCM_VT_MAIN_WND_PEER); 
			            /* TODO: currently do not have user id, but we can keep the code for future extension */
            #if 0
/* under construction !*/
            #endif
			mmi_vtcs_draw_image_id(IMG_ID_UCM_VT_MAIN_WND_PEER, layer_width, layer_height);
        }
        else if (g_mmi_vtcs_cntx.peer_img_state == MMI_VTCS_LOCAL_IMG_USER_ID)
        {
            /* TODO: currently do not have user id, but we can keep the code for future extension */  
            mmi_vtcs_draw_image_id(g_mmi_vtcs_cntx.default_peer_img_id, layer_width, layer_height);

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
        }
        else if (g_mmi_vtcs_cntx.peer_img_state == MMI_VTCS_LOCAL_IMG_USER_FILE)
        {
            mmi_vtcs_draw_image_file(
                g_mmi_vtcs_cntx.default_peer_img_file_path, 
                layer_width, layer_height,
                main_layer_temp_handle);
                
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
        }
        else
        {
            MMI_ASSERT(0);
        }        
    }
    else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_6)
    {
        /* LCOAL MAIN (Video) */   
        //gdi_image_draw_id(0, 0, IMG_ID_UCM_VT_MAIN_WND_LOCAL); 
        mmi_vtcs_draw_image_id(IMG_ID_UCM_VT_MAIN_WND_LOCAL, layer_width, layer_height);
        #if 0
/* under construction !*/
        #endif
    }
    else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_8)
    {
        /* LCOAL MAIN (Image) */   
        if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_DEFAULT_ID)
        {
            //gdi_image_draw_id(0, 0, IMG_ID_UCM_VT_MAIN_WND_LOCAL); 
            mmi_vtcs_draw_image_id(IMG_ID_UCM_VT_MAIN_WND_LOCAL, layer_width, layer_height);
            #if 0
/* under construction !*/
            #endif
        }
        else if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_USER_ID)
        {
            /* TODO: currently do not have user id, but we can keep the code for future extension */ 
            mmi_vtcs_draw_image_id(g_mmi_vtcs_cntx.user_img_id, layer_width, layer_height);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
        }
        else if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_USER_FILE)
        {
            mmi_vtcs_draw_image_file(
                g_mmi_vtcs_cntx.user_img_file_path, 
                layer_width, layer_height,
                main_layer_temp_handle);

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
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        /* some mode not handled */
        MMI_ASSERT(0);
    }

	if(is_hw_layer == MMI_TRUE && layer_color_format ==GDI_COLOR_FORMAT_UYVY422)
	{
		is_cf_suc = mdi_util_convert_color_format(main_layer_temp_handle,GDI_COLOR_FORMAT_16,GDI_COLOR_FORMAT_UYVY422);
	}
   
    gdi_layer_pop_and_restore_active();
	
	if (main_layer_temp_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(main_layer_temp_handle);
    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_sub_wnd
 * DESCRIPTION
 *  Draw sub window layer based on display type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_sub_wnd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;    
    S32 layer_width;
    S32 layer_height;
    S32 resized_width;
    S32 resized_height;
    S32 resized_offset_x;
    S32 resized_offset_y;
	S32 layer_x;
    S32 layer_y; 
    GDI_RESULT ret;
	gdi_handle sub_layer_temp_handle;
	MMI_BOOL is_hw_layer = MMI_FALSE;
	gdi_handle sub_layer_temp_handle_bt = 0;
	U8 *gdi_layer_buffer_ptr;
	MMI_BOOL is_cf_suc;
	gdi_color_format layer_color_format;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_SUB_WND,g_mmi_vtcs_cntx.mode,g_mmi_vtcs_cntx.local_img_state);    
	if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5)
	{
		sub_layer_temp_handle_bt = g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle;
		//mdi_util_hw_layer_switch_to_sw_layer(sub_layer_temp_handle);
		is_hw_layer = MMI_TRUE;
	}
	else
	{
		sub_layer_temp_handle_bt = g_mmi_vtcs_cntx.sub_wnd_layer_handle;
	}
	gdi_layer_push_and_set_active(sub_layer_temp_handle_bt);
	gdi_layer_get_buffer_ptr(&gdi_layer_buffer_ptr);
	gdi_layer_get_dimension(&layer_width, &layer_height);
	gdi_layer_get_position(&layer_x, &layer_y);
	gdi_layer_get_color_format(&layer_color_format);
	gdi_layer_pop_and_restore_active();

	gdi_layer_create_using_outside_memory(
        layer_x,
        layer_y,
        layer_width,
        layer_height,
        &sub_layer_temp_handle,
        (PU8)gdi_layer_buffer_ptr,
        (layer_width*layer_height*2));
	
	gdi_layer_push_and_set_active(sub_layer_temp_handle);
    gdi_layer_get_dimension(&layer_width, &layer_height);
	//if(is_hw_layer == MMI_TRUE )
	//{
	//	gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
	//}

    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_6 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_8)
    {
        /* PEER SUB (Video) */                   
        if (g_mmi_vtcs_cntx.peer_img_state == MMI_VTCS_LOCAL_IMG_DEFAULT_ID)
        {
            gdi_image_draw_id(0, 0, IMG_ID_UCM_VT_SUB_WND_PEER);
        }
        else if (g_mmi_vtcs_cntx.peer_img_state == MMI_VTCS_LOCAL_IMG_USER_ID)
        {
            /* TODO: currently do not have user id, but we can keep the code for future extension */
            mmi_vtcs_draw_image_id(g_mmi_vtcs_cntx.default_peer_img_id, layer_width, layer_height);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
        }
        else if (g_mmi_vtcs_cntx.peer_img_state == MMI_VTCS_LOCAL_IMG_USER_FILE)
        {
            mmi_vtcs_draw_image_file(
                g_mmi_vtcs_cntx.default_peer_img_file_path, 
                layer_width, layer_height,
                sub_layer_temp_handle);

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
/* under construction !*/
            #endif
        }
        else
        {
            MMI_ASSERT(0);
        }        
    }
    else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5)
    {
        /* LOCAL SUB (Video) */    
        gdi_image_draw_id(0, 0, IMG_ID_UCM_VT_SUB_WND_LOCAL);        
    }
    else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_7)
    {
        /* LOCAL SUB (Image) */        
        if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_DEFAULT_ID)
        {
            gdi_image_draw_id(0, 0, IMG_ID_UCM_VT_SUB_WND_LOCAL);    
        }
        else if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_USER_ID)
        {
            /* TODO: currently do not have user id, but we can keep the code for future extension */
            mmi_vtcs_draw_image_id(g_mmi_vtcs_cntx.user_img_id, layer_width, layer_height);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
        }
        else if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_USER_FILE)
        {
            mmi_vtcs_draw_image_file(
                g_mmi_vtcs_cntx.user_img_file_path, 
                layer_width, layer_height,
                sub_layer_temp_handle);

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
/* under construction !*/
            #endif
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        /* some mode not handled */
        MMI_ASSERT(0);
    }

	if(is_hw_layer == MMI_TRUE && layer_color_format == GDI_COLOR_FORMAT_UYVY422)
	{
		is_cf_suc = mdi_util_convert_color_format(sub_layer_temp_handle,GDI_COLOR_FORMAT_16,GDI_COLOR_FORMAT_UYVY422);
	}

    gdi_layer_pop_and_restore_active();
	if (sub_layer_temp_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(sub_layer_temp_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_open_main_wnd_hole
 * DESCRIPTION
 *  Open holes on skin main window display, since these two windows 
 *  are under r the skin layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_open_main_wnd_hole(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_OPEN_MAIN_WND_HOLE);     
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);

    gdi_layer_get_position(&offset_x, &offset_y);

    offset_x = g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_x - offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_y - offset_y;    

    gdi_draw_solid_rect(
        offset_x,
        offset_y,
        offset_x + g_mmi_vtcs_skin_cntx.main_wnd_rect.width - 1,
        offset_y + g_mmi_vtcs_skin_cntx.main_wnd_rect.height - 1, 
        GDI_COLOR_TRANSPARENT);
    
    gdi_layer_pop_and_restore_active();  
   
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_open_sub_wnd_hole
 * DESCRIPTION
 *  Open holes on skin sub window display, since these two windows 
 *  are under r the skin layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_open_sub_wnd_hole(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_OPEN_SUB_WND_HOLE);     
    if (g_mmi_vtcs_cntx.is_hide_sub)
    {
        /* hide sub, do not open sub hole */
        return;
    }   
    
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);

    gdi_layer_get_position(&offset_x, &offset_y);

    offset_x = g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_x - offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_y - offset_y;    

    gdi_draw_solid_rect(
        offset_x,
        offset_y,
        offset_x + g_mmi_vtcs_skin_cntx.sub_wnd_rect.width - 1,
        offset_y + g_mmi_vtcs_skin_cntx.sub_wnd_rect.height - 1, 
        GDI_COLOR_TRANSPARENT);
    
    gdi_layer_pop_and_restore_active();  
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_skin
 * DESCRIPTION
 *  Draw skin to current active skin layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_skin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	gdi_handle t_lyr;
    S32 offset_x;
    S32 offset_y;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_SKIN);         
    /* prevent others blt the status bar first and show abnormal screen */
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);                
    gdi_layer_lock_frame_buffer();
    gdi_layer_pop_and_restore_active();    

	gdi_get_alpha_blending_source_layer(&t_lyr);
	gdi_set_alpha_blending_source_layer(g_mmi_vtcs_cntx.skin_layer_handle);

    mmi_vtcs_draw_status();
    mmi_vtcs_draw_title();
    mmi_vtcs_draw_body();    
    mmi_vtcs_draw_panel(); 
    mmi_vtcs_draw_softkey();   
    mmi_vtcs_draw_main_wnd();
    mmi_vtcs_draw_sub_wnd();    
    mmi_vtcs_open_main_wnd_hole();
    mmi_vtcs_open_sub_wnd_hole();
	#if defined(__MMI_FTE_VT_SUBWND_BG__)
    if (!g_mmi_vtcs_cntx.is_hide_sub)
	{
	gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);

    gdi_layer_get_position(&offset_x, &offset_y);	

	offset_x = g_mmi_vtcs_skin_cntx.subwnd_bg.offset_x - offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.subwnd_bg.offset_y - offset_y;    
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_UCM_VT_SUBWND_BG);
    
    gdi_layer_pop_and_restore_active();
	mmi_vtcs_blt();
	}
	#endif

	//gdi_set_alpha_blending_source_layer(t_lyr);

    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);                
    gdi_layer_unlock_frame_buffer();
    gdi_layer_pop_and_restore_active();    
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_encode_layer
 * DESCRIPTION
 *  Draw encode layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_encode_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 layer_width;
    S32 layer_height;
    S32 resized_width;
    S32 resized_height;
    S32 resized_offset_x;
    S32 resized_offset_y;
    GDI_RESULT ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DRAW_ENCODE_LAYER,g_mmi_vtcs_cntx.local_img_state);     
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.encode_layer_handle);        
	if(g_mmi_vtcs_cntx.is_fullscreen_state)
	{
		gdi_layer_resize(MMI_VTCS_MAX_WIDTH,MMI_VTCS_MAX_HEIGHT);
	}
	else
	{
	    gdi_layer_resize(176,144);
	}
    gdi_layer_get_dimension(&layer_width, &layer_height);

    gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR);
            
    if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_DEFAULT_ID)
    {
        gdi_image_get_dimension_id(IMG_ID_UCM_VT_MAIN_WND_LOCAL, &image_width, &image_height);

        gdi_image_util_fit_bbox(
            layer_width,
            layer_height,
            image_width,
            image_height,
            &resized_offset_x,
            &resized_offset_y,
            &resized_width,
            &resized_height);

        gdi_image_draw_resized_id(
            resized_offset_x, 
            resized_offset_y, 
            resized_width, 
            resized_height,
            IMG_ID_UCM_VT_MAIN_WND_LOCAL);     
    
    }
    else if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_USER_ID)
    {
        /* TODO: currently do not have user id, but we can keep the code for future extension */            
        ret = gdi_image_get_dimension_id(g_mmi_vtcs_cntx.user_img_id, &image_width, &image_height);

        if (ret == GDI_SUCCEED && image_width != 0 && image_height != 0)
        {  
            if(image_width < layer_width && image_height < layer_height)
            {
                gdi_util_fit_box(
                    GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
                    layer_width,
                    layer_height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);            
            }                    
            else
            {        
                gdi_image_util_fit_bbox(
                    layer_width,
                    layer_height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);
            }
            gdi_image_draw_resized_id(
                resized_offset_x, 
                resized_offset_y, 
                resized_width, 
                resized_height,
                g_mmi_vtcs_cntx.user_img_id);              
        }
    }
    else if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_USER_FILE)
    {
        ret = gdi_image_get_dimension_file(g_mmi_vtcs_cntx.user_img_file_path, &image_width, &image_height);

        if (ret == GDI_SUCCEED && image_width != 0 && image_height != 0)
        {
            if(image_width < layer_width && image_height < layer_height)
            {
                gdi_util_fit_box(
                    GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
                    layer_width,
                    layer_height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);            
            }                    
            else
            {         
                gdi_image_util_fit_bbox(
                    layer_width,
                    layer_height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);
            }
            gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR);     
            /* to prevent image to blending with wrong layer */
            gdi_push_and_set_alpha_blending_source_layer(g_mmi_vtcs_cntx.encode_layer_handle);
                
            ret= gdi_image_draw_resized_file(
                    resized_offset_x, 
                    resized_offset_y, 
                    resized_width, 
                    resized_height,
                    g_mmi_vtcs_cntx.user_img_file_path);         
                    
            gdi_pop_and_restore_alpha_blending_source_layer();                           
            
            if(ret != GDI_SUCCEED)
            {
                gdi_image_get_dimension_id(IMG_ID_UCM_VT_MAIN_WND_LOCAL, &image_width, &image_height);

                gdi_image_util_fit_bbox(
                    layer_width,
                    layer_height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);

                gdi_image_draw_resized_id(
                    resized_offset_x, 
                    resized_offset_y, 
                    resized_width, 
                    resized_height,
                    IMG_ID_UCM_VT_MAIN_WND_LOCAL);             
            }
        }
        else
        {
            gdi_image_get_dimension_id(IMG_ID_UCM_VT_MAIN_WND_LOCAL, &image_width, &image_height);

            gdi_image_util_fit_bbox(
                layer_width,
                layer_height,
                image_width,
                image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            gdi_image_draw_resized_id(
                resized_offset_x, 
                resized_offset_y, 
                resized_width, 
                resized_height,
                IMG_ID_UCM_VT_MAIN_WND_LOCAL);         
        }        
    }

    gdi_layer_pop_and_restore_active();        
        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_start_event_callback_hdlr
 * DESCRIPTION
 *  Start display event callback handler
 * PARAMETERS
 *  tel_event       [IN]        event type
 *  para            [IN]        parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_start_event_callback_hdlr(mdi_video_tel_codec_event_enum tel_event, S32 para, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 vt_para = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_START_EVENT_CALLBACK_HDLR,tel_event,para);  
    if(g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_NONE) 
        return ;
        
    switch(tel_event)
    {
        case MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_SIZE:
            /* in this case, para is MDI_VIDEO_VIDEO_SIZE_XXXX */

            if (para == MDI_VIDEO_VIDEO_SIZE_QCIF)
            {
                vt_para = MMI_VT_ENC_SIZE_QCIF;
            }
            else if (para == MDI_VIDEO_VIDEO_SIZE_SQCIF)
            {
                vt_para = MMI_VT_ENC_SIZE_SQCIF;
            }
            else
            {
                ASSERT(0);
            }
			mmi_vtcs_draw_main_wnd();
			mmi_vtcs_draw_sub_wnd();

            if (vt_para != g_mmi_vtcs_cntx.enc_size_state)
            {
                /* size changed, need restart */
                /* TODO: maybe need reconfig preview layer size */
                g_mmi_vtcs_cntx.enc_size_state = (mmi_vt_enc_size_enum)vt_para;

                if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_BG_1 ||
                    g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_BG_2)
                {
                    /* background */
                    mmi_vtcs_pause_background_display();
                    mmi_vtcs_resume_background_display(MMI_FALSE);                    
                }
                else
                {
                    /* foreground */
                    mmi_vtcs_pause_display();
                    if (mmi_vtcs_resume_display(MMI_FALSE) != MDI_RES_VDOTEL_SUCCEED)
                    {
                        /* camera error */
                        mmi_vtcs_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
                        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                        #endif
                        return;
                    }
                }
            }
            break;

        case MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_QUALITY:

            if(g_mmi_vtcs_cntx.night_mode_state == MMI_VT_NIGHT_MODE_ON)
            {
                break;            
            }
            if (para == MDI_VIDEO_TEL_ENC_QTY_FINE)
            {
                vt_para = MMI_VT_VIDEO_QUALITY_SHARP;
            }
            else if (para == MDI_VIDEO_TEL_ENC_QTY_NORMAL)
            {
                vt_para = MMI_VT_VIDEO_QUALITY_NORMAL;
            }
            else if (para == MDI_VIDEO_TEL_ENC_QTY_LOW)
            {
                vt_para = MMI_VT_VIDEO_QUALITY_SMOOTH;            
            }                       
            else
            {
                ASSERT(0);
            }
			mmi_vtcs_draw_main_wnd();
			mmi_vtcs_draw_sub_wnd();

            if (vt_para != g_mmi_vtcs_cntx.local_enc_qty_state)
            {
                /* size changed, need restart */
                g_mmi_vtcs_cntx.local_enc_qty_state = (mmi_vt_video_quality_enum)vt_para;
                
                if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_BG_1 ||
                    g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_BG_2)
                {
                    /* background */
                    mmi_vtcs_pause_background_display();
                    mmi_vtcs_resume_background_display(MMI_FALSE);                    
                }
                else
                {
                    /* foreground */
                    mmi_vtcs_pause_display();
                    
                    if (mmi_vtcs_resume_display(MMI_FALSE) != MDI_RES_VDOTEL_SUCCEED)
                    {
                        /* camera error */
                        mmi_vtcs_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
                        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                        #endif
                        return;
                    }
                    
                }
            }
            break;
            
        case MDI_VIDEO_TEL_EVENT_UPDATE_LCD:
            
              mmi_vtcs_blt();
            break;            
        case MDI_VIDEO_TEL_EVENT_ENC_PATH_BUILT:
            if(vt_para == 0)
                g_mmi_vtcs_cntx.is_enc_path_built = MMI_TRUE;
            else
                g_mmi_vtcs_cntx.is_enc_path_built = MMI_FALSE;
            break;                        
        case MDI_VIDEO_TEL_EVENT_DEC_CH_CHANGE:
            /*
            if(vt_para == 0)
            {
                S32 str_width, str_height;

                gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.info_layer_handle);        
                gui_measure_string((UI_string_type) GetString(STR_ID_UCM_VT_PEER_CAMERA_OFF), &str_width, &str_height); 
                if(r2lMMIFlag)
                    gui_move_text_cursor(UI_device_width - ((UI_device_width - str_width) >> 1), 0);                    
                else    
                    gui_move_text_cursor(((UI_device_width - str_width) >> 1), 0);
                gui_set_text_color(gui_color(255, 255, 255));
                gui_set_text_border_color(gui_color(0, 0, 0));   
                gui_print_text((UI_string_type) GetString(STR_ID_UCM_VT_PEER_CAMERA_OFF));
                gdi_layer_pop_and_restore_active();                 

                gdi_layer_set_blt_layer(
                    g_mmi_vtcs_cntx.sub_wnd_layer_handle,   
                    g_mmi_vtcs_cntx.main_wnd_layer_handle,  
                    g_mmi_vtcs_cntx.skin_layer_handle,      
                    g_mmi_vtcs_cntx.info_layer_handle);     
                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);                

                kal_sleep_task(200);

                mmi_vtcs_config_layer_seq();
                mmi_vtcs_blt();
            }                
            else
            {
                S32 str_width, str_height;

                gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.info_layer_handle);        
                gui_measure_string((UI_string_type) GetString(STR_ID_UCM_VT_PEER_CAMERA_ON), &str_width, &str_height); 
                if(r2lMMIFlag)
                    gui_move_text_cursor(UI_device_width - ((UI_device_width - str_width) >> 1), 0);                    
                else    
                    gui_move_text_cursor(((UI_device_width - str_width) >> 1), 0);
                gui_set_text_color(gui_color(255, 255, 255));
                gui_set_text_border_color(gui_color(0, 0, 0));   
                gui_print_text((UI_string_type) GetString(STR_ID_UCM_VT_PEER_CAMERA_ON));                
                gdi_layer_pop_and_restore_active();                 

                gdi_layer_set_blt_layer(
                    g_mmi_vtcs_cntx.sub_wnd_layer_handle,   
                    g_mmi_vtcs_cntx.main_wnd_layer_handle,  
                    g_mmi_vtcs_cntx.skin_layer_handle,      
                    g_mmi_vtcs_cntx.info_layer_handle);     
                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);                

                kal_sleep_task(200);

                mmi_vtcs_config_layer_seq();
                mmi_vtcs_blt();
            }  
            */
            break;                
        default:
            ASSERT(0);
    
    }
    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_stop_display
 * DESCRIPTION
 *  stop display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_stop_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_STOP_DISPLAY,g_mmi_vtcs_cntx.mode);     
    if (g_mmi_vtcs_cntx.mode != MMI_VTCS_DISPLAY_MODE_8 &&
        g_mmi_vtcs_cntx.mode != MMI_VTCS_DISPLAY_MODE_7)
    {
        /* stop previous playing */   
        g_mmi_vtcs_cntx.has_open_MED = MMI_FALSE;
        mdi_video_tel_stop();
    }
    
    // clear preview content prevent see again at the next stating     
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle); 
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();                   
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.main_wnd_hw_layer_handle); 
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();        
    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_pause_display
 * DESCRIPTION
 *  stop display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_pause_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_STOP_DISPLAY,g_mmi_vtcs_cntx.mode);     
    /*
    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_8 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_7)
    {
       
        mdi_video_tel_stop();
    }
    else
    {*/
    if (g_mmi_vtcs_cntx.mode != MMI_VTCS_DISPLAY_MODE_8 &&
        g_mmi_vtcs_cntx.mode != MMI_VTCS_DISPLAY_MODE_7)
    {    
        mdi_video_tel_pause();
    }   

    mdi_util_hw_layer_switch_to_sw_layer(g_mmi_vtcs_cntx.main_wnd_hw_layer_handle);
    mdi_util_hw_layer_switch_to_sw_layer(g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle);
    
    // clear preview content prevent see again at the next stating     
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle); 
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();                   
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.main_wnd_hw_layer_handle); 
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();  	 
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_start_display
 * DESCRIPTION
 *  Start VT display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_vtcs_start_display(MMI_BOOL enable_3a)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle peer_layer_handle = 0;
    gdi_handle local_layer_handle = 0;
    mdi_video_tel_disp_type_enum local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
    mdi_video_tel_disp_type_enum peer_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;    
    U32 blt_layer_flag = 0;
    U32 peer_layer_flag = 0;
    U32 local_layer_flag = 0;
    mdi_video_setting_struct video_setting;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Layer Configuration: 
     *
     * Hide Sub
     * ========== [Up] ============
     * (2) Skin Layer (dobule buffer)   
     * (1) Main Wnd Layer               
     * (0) Sub Wnd Layer                
     * ========= [Down] ============
     *
     * Not Hide Sub
     * ========== [Up] ============
     * (2) Skin Layer (dobule buffer)   
     * (1) Sub Wnd Layer               
     * (0) Main Wnd Layer               
     * ========= [Down] ============
     */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_START_DISPLAY,enable_3a,g_mmi_vtcs_cntx.mode);   
    
    if (!enable_3a)
    {
        mdi_video_tel_bypass_3a_stable();
    } 
    
    switch (g_mmi_vtcs_cntx.mode)
    {
        case MMI_VTCS_DISPLAY_MODE_1:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 1      Peer Video       Local Video     Encode video to peer            
             *
             */
            peer_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            peer_layer_handle = g_mmi_vtcs_cntx.main_wnd_hw_layer_handle;   

            local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            local_layer_handle = g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle;   

            if (g_mmi_vtcs_cntx.is_hide_sub)
            {
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_1;     /* main */
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_0;    /* sub */
            }
            else
            {
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_0;     /* main */
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_1;    /* sub */
            }
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2;
            break;

        case MMI_VTCS_DISPLAY_MODE_2:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 2      Local Video      Peer Video      Encode video to peer         
             *
             */            
            peer_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            peer_layer_handle = g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle;   

            local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            local_layer_handle = g_mmi_vtcs_cntx.main_wnd_hw_layer_handle;   

            if (g_mmi_vtcs_cntx.is_hide_sub)
            {
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_1;    /* main */
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_0;     /* sub */
                
            }
            else
            {
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_0;    /* main */
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_1;     /* sub */                
            }
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2;
            break;

       case MMI_VTCS_DISPLAY_MODE_3:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 3      Peer Video       Local Image     Encode image to peer     
             *
             */  
            peer_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            peer_layer_handle = g_mmi_vtcs_cntx.main_wnd_hw_layer_handle;   

            local_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
            local_layer_handle = g_mmi_vtcs_cntx.encode_layer_handle;  /* will encode this and send to pper */

            if (g_mmi_vtcs_cntx.is_hide_sub)
            {
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_1;     /* main */
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_0;    /* sub */
            }
            else
            {
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_0;     /* main */
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_1;    /* sub */
            }
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2;
            break;

        case MMI_VTCS_DISPLAY_MODE_4:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 4      Local Image      Peer Video      Encode image to peer   
             *
             */                
            peer_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            peer_layer_handle = g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle;   

            local_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
            local_layer_handle = g_mmi_vtcs_cntx.encode_layer_handle;  /* will encode this and send to pper */

            if (g_mmi_vtcs_cntx.is_hide_sub)
            {
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_1;    /* main */
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_0;     /* sub */
                
            }
            else
            {
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_0;    /* main */
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_1;     /* sub */                
            }
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2;
            break;
            
        case MMI_VTCS_DISPLAY_MODE_5:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 5      Peer Image       Local Video     Preview only
             *
             */        
            peer_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
            peer_layer_handle = g_mmi_vtcs_cntx.main_wnd_layer_handle;   

            local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            local_layer_handle = g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle;  

            if (g_mmi_vtcs_cntx.is_hide_sub)
            {
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_1;     /* main */
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_0;    /* sub */
            }
            else
            {
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_0;     /* main */
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_1;    /* sub */
            }
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2;
            break;

        case MMI_VTCS_DISPLAY_MODE_6:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 6      Local Video      Peer Image      Preview only
             *
             */              
            peer_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
            peer_layer_handle = g_mmi_vtcs_cntx.sub_wnd_layer_handle;   

            local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            local_layer_handle = g_mmi_vtcs_cntx.main_wnd_hw_layer_handle;  

            if (g_mmi_vtcs_cntx.is_hide_sub)
            {
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_1;    /* main */
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_0;     /* sub */
            }
            else
            {
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_0;    /* main */
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_1;     /* sub */                
            }
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2;
                     
            break;
  
        case MMI_VTCS_DISPLAY_MODE_7:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 7      Local Image      Peer Image      No preview
             *
             */  
             
            /* no need call driver, return */
            return MDI_RES_VDOTEL_SUCCEED;
            
        case MMI_VTCS_DISPLAY_MODE_8:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 8     Peer Image       Local Image      No preview
             *
             */                
             
            /* no need call driver, return */   
            return MDI_RES_VDOTEL_SUCCEED;            

        default:
            MMI_ASSERT(0);

    }


    /* get default video preview settings */
    mdi_video_tel_load_default_setting(&video_setting);
    
#ifdef __MMI_CAMCORDER__    
    video_setting.banding = mmi_camco_setting_get_banding();
#else    
    video_setting.banding = 0;
#endif  
    video_setting.zoom = g_mmi_vtcs_cntx.zoom_step;
    video_setting.ev = mmi_vtcs_get_ev_factor();
    video_setting.preview_rotate = mmi_vtcs_get_cam_rotate_factor();
    video_setting.video_qty = mmi_vtcs_get_local_enc_qty_factor();  /* local encoder */
    video_setting.video_size = mmi_vtcs_get_enc_size_factor();
    video_setting.peer_enc_qty = mmi_vtcs_get_peer_enc_qty_factor();
    video_setting.display_mirror = MMI_FALSE;
    video_setting.display_rotate = mmi_vtcs_get_cam_rotate_factor_for_IDP();
	video_setting.notify_peer_on_camera_off = g_mmi_vtcs_cntx.is_local_image_off;
    if(g_mmi_vtcs_cntx.night_mode_state == MMI_VT_NIGHT_MODE_ON)
    {
        video_setting.night = 1;
    }
    else
    {
        video_setting.night = 0;
    }
    
#ifdef __MMI_UCM_VT_DUAL_CAMERA__
    if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_BACK)
    {
        mdi_video_tel_set_camera_id(MDI_VIDEO_MAIN_SENSOR);
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_FRONT)
    {
        mdi_video_tel_set_camera_id(MDI_VIDEO_SUB_SENSOR);
        video_setting.display_mirror = MMI_TRUE;
    }
    else
    {
        /* do nothing */
    }
#endif /* __MMI_UCM_VT_DUAL_CAMERA__ */
    g_mmi_vtcs_cntx.has_open_MED = MMI_TRUE;
	ret = mdi_video_tel_set_memory_param(TRUE,MMI_VTCS_MAX_WIDTH,MMI_VTCS_MAX_HEIGHT,g_mmi_vtcs_skin_cntx.sub_wnd_rect.width,g_mmi_vtcs_skin_cntx.sub_wnd_rect.height);

    ret = mdi_video_tel_start(
                peer_layer_handle,         
                local_layer_handle,        
                peer_type,                 
                local_type,  
                blt_layer_flag,
                peer_layer_flag,
                local_layer_flag,
                &video_setting,
                g_mmi_vtcs_cntx.parent_sg_id,                
                mmi_vtcs_start_event_callback_hdlr,
                NULL);

    if (ret != MDI_RES_VDOTEL_SUCCEED)
    {
        if (g_mmi_vtcs_cntx.camera_state != MMI_VT_CAMERA_OFF)
        {
            /* turn off cameras */
            mmi_ucm_vt_set_camera_status(MMI_FALSE);
            
        #ifdef __MMI_UCM_VT_DUAL_CAMERA__
            mmi_ucm_vt_set_main_camera_status(MMI_FALSE);
        #endif
        }
        g_mmi_vtcs_cntx.has_open_MED = MMI_FALSE;
        /* set to display mode exit, so it will not stop driver since it start failed */
        g_mmi_vtcs_cntx.mode = MMI_VTCS_DISPLAY_MODE_NONE;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_resume_display
 * DESCRIPTION
 *  Start VT display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_vtcs_resume_display(MMI_BOOL enable_3a)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle peer_layer_handle = 0;
    gdi_handle local_layer_handle = 0;
    mdi_video_tel_disp_type_enum local_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
    mdi_video_tel_disp_type_enum peer_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;    
    U32 blt_layer_flag = 0;
    U32 peer_layer_flag = 0;
    U32 local_layer_flag = 0;
    mdi_video_setting_struct video_setting;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Layer Configuration: 
     *
     * Hide Sub
     * ========== [Up] ============
     * (2) Skin Layer (dobule buffer)   
     * (1) Main Wnd Layer               
     * (0) Sub Wnd Layer                
     * ========= [Down] ============
     *
     * Not Hide Sub
     * ========== [Up] ============
     * (2) Skin Layer (dobule buffer)   
     * (1) Sub Wnd Layer               
     * (0) Main Wnd Layer               
     * ========= [Down] ============
     */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_START_DISPLAY,enable_3a,g_mmi_vtcs_cntx.mode);   
    
    if (!enable_3a)
    {
        mdi_video_tel_bypass_3a_stable();
    }
    
    switch (g_mmi_vtcs_cntx.mode)
    {
        case MMI_VTCS_DISPLAY_MODE_1:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 1      Peer Video       Local Video     Encode video to peer            
             *
             */
            peer_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            peer_layer_handle = g_mmi_vtcs_cntx.main_wnd_hw_layer_handle;   

            local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            local_layer_handle = g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle;   

            if (g_mmi_vtcs_cntx.is_hide_sub)
            {
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_1;     /* main */
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_0;    /* sub */
            }
            else
            {
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_0;     /* main */
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_1;    /* sub */
            }
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2;
            break;

        case MMI_VTCS_DISPLAY_MODE_2:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 2      Local Video      Peer Video      Encode video to peer         
             *
             */            
            peer_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            peer_layer_handle = g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle;   

            local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            local_layer_handle = g_mmi_vtcs_cntx.main_wnd_hw_layer_handle;   

            if (g_mmi_vtcs_cntx.is_hide_sub)
            {
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_1;    /* main */
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_0;     /* sub */
                
            }
            else
            {
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_0;    /* main */
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_1;     /* sub */                
            }
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2;
            break;

       case MMI_VTCS_DISPLAY_MODE_3:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 3      Peer Video       Local Image     Encode image to peer     
             *
             */  
            peer_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            peer_layer_handle = g_mmi_vtcs_cntx.main_wnd_hw_layer_handle;   

            local_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
            local_layer_handle = g_mmi_vtcs_cntx.encode_layer_handle;  /* will encode this and send to pper */

            if (g_mmi_vtcs_cntx.is_hide_sub)
            {
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_1;     /* main */
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_0;    /* sub */
            }
            else
            {
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_0;     /* main */
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_1;    /* sub */
            }
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2;
            break;

        case MMI_VTCS_DISPLAY_MODE_4:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 4      Local Image      Peer Video      Encode image to peer   
             *
             */                
            peer_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            peer_layer_handle = g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle;   

            local_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
            local_layer_handle = g_mmi_vtcs_cntx.encode_layer_handle;  /* will encode this and send to pper */

            if (g_mmi_vtcs_cntx.is_hide_sub)
            {
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_1;    /* main */
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_0;     /* sub */
                
            }
            else
            {
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_0;    /* main */
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_1;     /* sub */                
            }
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2;
            break;
            
        case MMI_VTCS_DISPLAY_MODE_5:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 5      Peer Image       Local Video     Preview only
             *
             */        
            peer_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
            peer_layer_handle = g_mmi_vtcs_cntx.main_wnd_layer_handle;   

            local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            local_layer_handle = g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle;  

            if (g_mmi_vtcs_cntx.is_hide_sub)
            {
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_1;     /* main */
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_0;    /* sub */
            }
            else
            {
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_0;     /* main */
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_1;    /* sub */
            }
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2;
            break;

        case MMI_VTCS_DISPLAY_MODE_6:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 6      Local Video      Peer Image      Preview only
             *
             */              
            peer_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
            peer_layer_handle = g_mmi_vtcs_cntx.sub_wnd_layer_handle;   

            local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            local_layer_handle = g_mmi_vtcs_cntx.main_wnd_hw_layer_handle;  

            if (g_mmi_vtcs_cntx.is_hide_sub)
            {
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_1;    /* main */
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_0;     /* sub */
            }
            else
            {
                local_layer_flag = GDI_LAYER_ENABLE_LAYER_0;    /* main */
                peer_layer_flag = GDI_LAYER_ENABLE_LAYER_1;     /* sub */                
            }
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2;
                     
            break;
  
        case MMI_VTCS_DISPLAY_MODE_7:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 7      Local Image      Peer Image      No preview
             *
             */  
             
            /* no need call driver, return */
            return MDI_RES_VDOTEL_SUCCEED;
            
        case MMI_VTCS_DISPLAY_MODE_8:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 8     Peer Image       Local Image      No preview
             *
             */                
             
            /* no need call driver, return */   
            return MDI_RES_VDOTEL_SUCCEED;            

        default:
            MMI_ASSERT(0);

    }


    /* get default video preview settings */
    mdi_video_tel_load_default_setting(&video_setting);
    
#ifdef __MMI_CAMCORDER__    
    video_setting.banding = mmi_camco_setting_get_banding();
#else    
    video_setting.banding = 0;
#endif  
    video_setting.zoom = g_mmi_vtcs_cntx.zoom_step;
    video_setting.ev = mmi_vtcs_get_ev_factor();
    video_setting.preview_rotate = mmi_vtcs_get_cam_rotate_factor();
    video_setting.video_qty = mmi_vtcs_get_local_enc_qty_factor();  /* local encoder */
    video_setting.video_size = mmi_vtcs_get_enc_size_factor();
    video_setting.peer_enc_qty = mmi_vtcs_get_peer_enc_qty_factor();
    video_setting.display_mirror = MMI_FALSE;
    video_setting.display_rotate = mmi_vtcs_get_cam_rotate_factor_for_IDP();
	video_setting.notify_peer_on_camera_off = g_mmi_vtcs_cntx.is_local_image_off;
    if(g_mmi_vtcs_cntx.night_mode_state == MMI_VT_NIGHT_MODE_ON)
    {
        video_setting.night = 1;
    }
    else
    {
        video_setting.night = 0;
    }
        
#ifdef __MMI_UCM_VT_DUAL_CAMERA__
    if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_BACK)
    {
        mdi_video_tel_set_camera_id(MDI_VIDEO_MAIN_SENSOR);
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_FRONT)
    {
        mdi_video_tel_set_camera_id(MDI_VIDEO_SUB_SENSOR);
        video_setting.display_mirror = MMI_TRUE;        
    }
    else
    {
        /* do nothing */
    }
#endif /* __MMI_UCM_VT_DUAL_CAMERA__ */

    ret = mdi_video_tel_resume(
                peer_layer_handle,         
                local_layer_handle,        
                peer_type,                 
                local_type,  
                blt_layer_flag,
                peer_layer_flag,
                local_layer_flag,             
                &video_setting,
                mmi_vtcs_start_event_callback_hdlr,
                NULL);

    if (ret != MDI_RES_VDOTEL_SUCCEED)
    {
        if (g_mmi_vtcs_cntx.camera_state != MMI_VT_CAMERA_OFF)
        {
            /* turn off cameras */
            mmi_ucm_vt_set_camera_status(MMI_FALSE);
            
        #ifdef __MMI_UCM_VT_DUAL_CAMERA__
            mmi_ucm_vt_set_main_camera_status(MMI_FALSE);
        #endif
        }

        /* set to display mode exit, so it will not stop driver since it start failed */
        g_mmi_vtcs_cntx.mode = MMI_VTCS_DISPLAY_MODE_NONE;
    }

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_resume_background_display
 * DESCRIPTION
 *  Start VT display
 * PARAMETERS
 *  enable_3a   [IN] enable 3a or not
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_resume_background_display(MMI_BOOL enable_3a)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle peer_layer_handle = 0;
    gdi_handle local_layer_handle = 0;
    mdi_video_tel_disp_type_enum local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
    mdi_video_tel_disp_type_enum peer_type = MDI_VIDEO_TEL_DISPLAY_HIDE;    
    U32 blt_layer_flag = 0;
    U32 peer_layer_flag = 0;
    U32 local_layer_flag = 0;
    mdi_video_setting_struct video_setting;
    mmi_vtcs_display_mode_enum previous_mode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Layer Configuration: 
     *
     * ========== [Up] ============
     * (3) Status Layer                 => from GDI memory pool 
     * (2) Skin Layer (dobule buffer)   => from screen memory
     * (1) Sub Wnd Layer                => from GDI memory pool
     * (0) Main Wnd Layer               => from GDI memory pool
     * ========= [Down] ============
     */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_START_BACKGROUND_DISPLAY,enable_3a,g_mmi_vtcs_cntx.mode);  
    /* Main Window */
    if (!enable_3a)
    {
        mdi_video_tel_bypass_3a_stable();
    }   

    /* change mode from forground to back ground */
    previous_mode = g_mmi_vtcs_cntx.mode;
    switch (g_mmi_vtcs_cntx.mode)
    {
        case MMI_VTCS_DISPLAY_MODE_1:
        case MMI_VTCS_DISPLAY_MODE_2:            
            g_mmi_vtcs_cntx.mode = MMI_VTCS_DISPLAY_MODE_BG_1;
            break;

        case MMI_VTCS_DISPLAY_MODE_3:
        case MMI_VTCS_DISPLAY_MODE_4:            
            g_mmi_vtcs_cntx.mode = MMI_VTCS_DISPLAY_MODE_BG_2;
            break;
    }
 
    /* TODO: mode */
    switch (g_mmi_vtcs_cntx.mode)
    {
        case MMI_VTCS_DISPLAY_MODE_BG_1:
            /*         
             * BG MODE 1: Encode video to peer         
             */

            /* hide peer */
            peer_type = MDI_VIDEO_TEL_DISPLAY_HIDE;
            peer_layer_handle = GDI_LAYER_EMPTY_HANDLE;   
            peer_layer_flag = 0;            

            /* encode local video */
            local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            if(previous_mode == MMI_VTCS_DISPLAY_MODE_1)
            {
                local_layer_handle = g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle;   
            }                
            else if(previous_mode == MMI_VTCS_DISPLAY_MODE_2)
            {
                local_layer_handle = g_mmi_vtcs_cntx.main_wnd_hw_layer_handle;   
            }                
            local_layer_flag = 0;  
            
            blt_layer_flag = 0;
            break;

        case MMI_VTCS_DISPLAY_MODE_BG_2:
            /*         
             * BG MODE 2: Encode image layer to peer         
             */

            /* hide peer */
            peer_type = MDI_VIDEO_TEL_DISPLAY_HIDE;
            peer_layer_handle = GDI_LAYER_EMPTY_HANDLE;   
            peer_layer_flag = 0;            

            /* encode local video */
            local_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
            local_layer_handle = g_mmi_vtcs_cntx.encode_layer_handle;   
            local_layer_flag = 0;  
            
            blt_layer_flag = 0;
            break;
  
        default:
            MMI_ASSERT(0);

    }


    /* get default video preview settings */
    mdi_video_tel_load_default_setting(&video_setting);

    video_setting.zoom = g_mmi_vtcs_cntx.zoom_step;
    video_setting.ev = mmi_vtcs_get_ev_factor();
    video_setting.preview_rotate = mmi_vtcs_get_cam_rotate_factor();
    video_setting.video_qty = mmi_vtcs_get_local_enc_qty_factor();
    video_setting.video_size = mmi_vtcs_get_enc_size_factor();
    video_setting.peer_enc_qty = mmi_vtcs_get_peer_enc_qty_factor();
    video_setting.display_mirror = MMI_FALSE;    
    video_setting.display_rotate = mmi_vtcs_get_cam_rotate_factor_for_IDP();  
    if(g_mmi_vtcs_cntx.night_mode_state == MMI_VT_NIGHT_MODE_ON)
    {
        video_setting.night = 1;
    }
    else
    {
        video_setting.night = 0;
    }

#ifdef __MMI_UCM_VT_DUAL_CAMERA__
    if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_BACK)
    {
        mdi_video_tel_set_camera_id(MDI_VIDEO_MAIN_SENSOR);
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_FRONT)
    {
        mdi_video_tel_set_camera_id(MDI_VIDEO_SUB_SENSOR);
        video_setting.display_mirror = MMI_TRUE;        
    }
    else
    {
        /* do nothing */
    }
#endif /* __MMI_UCM_VT_DUAL_CAMERA__ */

    
    mdi_video_tel_resume(
        peer_layer_handle,         
        local_layer_handle,        
        peer_type,                 
        local_type,  
        blt_layer_flag,
        peer_layer_flag,
        local_layer_flag,    
        &video_setting,
        mmi_vtcs_start_event_callback_hdlr,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_pause_background_display
 * DESCRIPTION
 *  stop display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_pause_background_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_STOP_BACKGROUND_DISPLAY);  
    /* stop previous playing */        
    mdi_video_tel_pause();

    // clear preview content prevent see again at the next stating     
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle); 
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();                   
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.main_wnd_hw_layer_handle); 
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();       
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_stop_background_display
 * DESCRIPTION
 *  stop display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_stop_background_display(void)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_STOP_BACKGROUND_DISPLAY);  
    /* stop previous playing */     
    g_mmi_vtcs_cntx.has_open_MED = MMI_FALSE;    
    mdi_video_tel_stop();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_config_layer_seq
 * DESCRIPTION
 *  Config layer 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_config_layer_seq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle real_sub_handle;
    gdi_handle real_main_handle;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_CONFIG_LAYER_SEQ,g_mmi_vtcs_cntx.is_hide_sub);  

    if(g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
       g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||    
       g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4 ||
       g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5 )
    {
        real_sub_handle = g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle;
    }
    else
    {
        real_sub_handle = g_mmi_vtcs_cntx.sub_wnd_layer_handle;    
    }
    if(g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
       g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||
       g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 ||     
       g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_6 )
    {
        real_main_handle = g_mmi_vtcs_cntx.main_wnd_hw_layer_handle;
    }
    else
    {
        real_main_handle = g_mmi_vtcs_cntx.main_wnd_layer_handle;    
    }
    if (g_mmi_vtcs_cntx.is_hide_sub)
    {
        /* hide sub, move sub window to lowest */
        gdi_layer_set_blt_layer(
            real_sub_handle,                        /* 0 */
            real_main_handle,                       /* 1 */
            g_mmi_vtcs_cntx.skin_layer_handle,      /* 2 */
            0);                                     /* 3 */
    }
    else
    {
        /* do not hide sub, move sub window in front of main window */
        gdi_layer_set_blt_layer(
            real_main_handle,                       /* 0 */
            real_sub_handle,                        /* 1 */
            g_mmi_vtcs_cntx.skin_layer_handle,      /* 2 */
            0);                                     /* 3 */
    }
    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_blt
 * DESCRIPTION
 *  Blt to LCD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_blt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_BLT);  
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    /* clone skin */
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_toggle_double();
    gdi_layer_copy_double();
    gdi_layer_pop_and_restore_active();
}




/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_convert_key_code_to_ascii
 * DESCRIPTION
 *  Conver key code to ascii code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_vtcs_convert_key_code_to_ascii(U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ascii_code = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(key_code)
    {
        case KEY_0:
        {
            ascii_code = '0';     
        }
        break;
        
        case KEY_1:
        {
            ascii_code = '1';     
        }
        break;
        
        case KEY_2:
        {
            ascii_code = '2';     
        }
        break;

        case KEY_3:
        {
            ascii_code = '3';     
        }
        break;

        case KEY_4:
        {
            ascii_code = '4';     
        }
        break;

        case KEY_5:
        {
            ascii_code = '5';     
        }
        break;

        case KEY_6:
        {
            ascii_code = '6';     
        }
        break;

        case KEY_7:
        {
            ascii_code = '7';     
        }
        break;

        case KEY_8:
        {
            ascii_code = '8';     
        }
        break;

        case KEY_9:
        {
            ascii_code = '9';     
        }
        break;

        case KEY_STAR:
        {
            ascii_code = '*';     
        }
        break;

        case KEY_POUND:
        {
            ascii_code = '#';     
        }
        break;
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
        case KEY_W:
        {
            ascii_code = 'w';     
        }
        break;

        case KEY_P:
        {
            ascii_code = 'p';     
        }
        break;
#endif

        default:
        {
            ascii_code = 0;     
        }
        break;        
    }

    return ascii_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_dtmf_key_down
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_dtmf_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vt_uii_struct *msg_req;
    U16 key_code = 0, key_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_CS_DTMF_KEY_DOWN);

    GetkeyInfo(&key_code, &key_type);

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    if (!wgui_inputs_dialer_is_dialer_keys(key_code))
    {
        return;
    }
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */
    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_CS_SEND_UII, key_code);

    msg_req = (mmi_vt_uii_struct*) construct_local_para(sizeof(mmi_vt_uii_struct), TD_CTRL | TD_RESET);

    msg_req->uiiLength = 1;
    msg_req->uiiString[0] = mmi_vtcs_convert_key_code_to_ascii(key_code);
   
    mmi_frm_send_ilm(        
        MOD_VT,
        MSG_ID_MMI_VT_UII,
        (oslParaType*) msg_req,
        NULL);
                
    /* avid reapeat key event */
    SetGroupKeyHandler(MMI_dummy_function, (U16*)PresentAllDialerKeys, TOTAL_DIALER_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(MMI_dummy_function, (U16*)PresentAllDialerKeys, TOTAL_DIALER_KEYS, KEY_EVENT_LONG_PRESS);
    SetGroupKeyHandler(MMI_dummy_function, (U16*)PresentAllDialerKeys, TOTAL_DIALER_KEYS, KEY_EVENT_REPEAT);        
#ifndef __MMI_VTCS_FTE__
    gui_start_timer(MMI_VTCS_CTRL_PANEL_RESTORE_DUR + 3000, mmi_vtcs_panel_restore_hdlr);  
#endif
    if (g_mmi_vtcs_cntx.panel_state != MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
    {

        mmi_ucm_handle_sendkeys_for_call(mmi_vtcs_dial_mailbox_address,KEY_EVENT_UP);
        memset(g_mmi_vtcs_cntx.input_box_buf, 0, MMI_VTCS_INPUT_BOX_BUF_SIZE);
        g_mmi_vtcs_cntx.panel_state = MMI_VTCS_PANEL_STATE_USER_INPUT_VK;        
    #ifdef __MMI_VTCS_FTE__    
        g_mmi_vtcs_cntx.two_setp_ad_panel_mode = MMI_TRUE;    
        mmi_vtcs_set_softkey(NULL, STR_GLOBAL_BACK);
    #endif        
    }

    mmi_vtcs_add_to_input_box(key_code);
    mmi_vtcs_draw_panel();
#ifdef __MMI_VTCS_FTE__  
    mmi_vtcs_draw_softkey();   
#endif
    mmi_vtcs_blt();     
   
}


static void mmi_vtcs_add_to_input_box(U16 key_code)
{
    U32 str_len;

    str_len = mmi_ucs2strlen(g_mmi_vtcs_cntx.input_box_buf);
    if (str_len == MMI_VTCS_INPUT_BOX_LEN)
    {
        /* reach max, move 1 char foward */
        memcpy(g_mmi_vtcs_cntx.input_box_buf, g_mmi_vtcs_cntx.input_box_buf + ENCODING_LENGTH, MMI_VTCS_INPUT_BOX_BUF_SIZE);
        str_len--;
    }

    switch(key_code)
    {
        case KEY_0:
            mmi_ucs2cat((CHAR *)&g_mmi_vtcs_cntx.input_box_buf[str_len * ENCODING_LENGTH], (CHAR *)(L"0"));
            break;
        case KEY_1:
            mmi_ucs2cat((CHAR *)&g_mmi_vtcs_cntx.input_box_buf[str_len * ENCODING_LENGTH], (CHAR *)(L"1"));
            break;
        case KEY_2:
            mmi_ucs2cat((CHAR *)&g_mmi_vtcs_cntx.input_box_buf[str_len * ENCODING_LENGTH], (CHAR *)(L"2"));
            break;
        case KEY_3:
            mmi_ucs2cat((CHAR *)&g_mmi_vtcs_cntx.input_box_buf[str_len * ENCODING_LENGTH], (CHAR *)(L"3"));
            break;
        case KEY_4:
            mmi_ucs2cat((CHAR *)&g_mmi_vtcs_cntx.input_box_buf[str_len * ENCODING_LENGTH], (CHAR *)(L"4"));
            break;
        case KEY_5:
            mmi_ucs2cat((CHAR *)&g_mmi_vtcs_cntx.input_box_buf[str_len * ENCODING_LENGTH], (CHAR *)(L"5"));
            break;
        case KEY_6:
            mmi_ucs2cat((CHAR *)&g_mmi_vtcs_cntx.input_box_buf[str_len * ENCODING_LENGTH], (CHAR *)(L"6"));
            break;
        case KEY_7:
            mmi_ucs2cat((CHAR *)&g_mmi_vtcs_cntx.input_box_buf[str_len * ENCODING_LENGTH], (CHAR *)(L"7"));
            break;
        case KEY_8:
            mmi_ucs2cat((CHAR *)&g_mmi_vtcs_cntx.input_box_buf[str_len * ENCODING_LENGTH], (CHAR *)(L"8"));
            break;
        case KEY_9:
            mmi_ucs2cat((CHAR *)&g_mmi_vtcs_cntx.input_box_buf[str_len * ENCODING_LENGTH], (CHAR *)(L"9"));
            break;
        case KEY_STAR:
            mmi_ucs2cat((CHAR *)&g_mmi_vtcs_cntx.input_box_buf[str_len * ENCODING_LENGTH], (CHAR *)(L"*"));
            break;
        case KEY_POUND:
            mmi_ucs2cat((CHAR *)&g_mmi_vtcs_cntx.input_box_buf[str_len * ENCODING_LENGTH], (CHAR *)(L"#"));
            break;
    #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__            
        case KEY_W:
            mmi_ucs2cat((CHAR *)&g_mmi_vtcs_cntx.input_box_buf[str_len * ENCODING_LENGTH], (CHAR *)(L"w"));
            break;
        case KEY_P:
            mmi_ucs2cat((CHAR *)&g_mmi_vtcs_cntx.input_box_buf[str_len * ENCODING_LENGTH], (CHAR *)(L"p"));
            break;
    #endif            
        default:
            MMI_ASSERT(0);
            break;

    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_dtmf_key_up
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_dtmf_key_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_CS_DTMF_KEY_UP);

    mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF);
    SetGroupKeyHandler(mmi_vtcs_dtmf_key_down, (U16*)PresentAllDialerKeys, TOTAL_DIALER_KEYS, KEY_EVENT_DOWN);
}


/***********************************
 * 3G Video Call - DTMF key msg
 ***********************************/
#ifdef MMI_VTCS_DTMF_RECEIVE
/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_convert_ascii_to_key_code
 * DESCRIPTION
 *  Conver ascii code to key code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_vtcs_convert_ascii_to_key_code(U8 key_ascii)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_code = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(key_ascii)
    {
        case '*':
        {
            key_code = KEY_STAR;     
        }
        break;

        case '#':
        {
            key_code = KEY_POUND;     
        }
        break;
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
        case 'w':
        {
            key_code = KEY_W;     
        }
        break;

        case 'p':
        {
            key_code = KEY_P;     
        }
        break;
#endif

        default:
        {
            key_code = key_ascii - '0';     
        }
        break;        
    }

    return key_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_dtmf_detect_ind
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vtcs_dtmf_detect_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vt_ui_received_ind_struct *pMsg;
    U16 key_code;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (mmi_vtcs_dtmf_received_cb)
    {
        pMsg = (mmi_vt_ui_received_ind_struct*)msg;
        key_code = mmi_vtcs_convert_ascii_to_key_code(pMsg->uiiString[0]);
        mmi_vtcs_dtmf_received_cb(key_code);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_start_dtmf_detect
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vtcs_start_dtmf_detect(mmi_vtcs_dtmf_received_callback func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    mmi_vtcs_dtmf_received_cb = func;
    SetProtocolEventHandler(mmi_vtcs_dtmf_detect_ind, MSG_ID_MMI_VT_UI_RECEIVED_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_stop_dtmf_detect
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vtcs_stop_dtmf_detect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    mmi_vtcs_dtmf_received_cb = NULL;
    ClearProtocolEventHandler(MSG_ID_MMI_VT_UI_RECEIVED_IND);
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_entry_call_scr_internal
 * DESCRIPTION
 *  Enter call screen internal function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_entry_call_scr_internal(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 offset_x;
	S32 offset_y;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_VT_INCALL,
                    mmi_vtcs_exit_call_scr,
                    (FuncPtr)mmi_vtcs_entry_call_scr_internal,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }

    /* disable SSE */
    gui_screen_switch_effect_block(MMI_TRUE);
    
    /* set ther blt mode to make osd blt immediate */
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    
    g_mmi_vtcs_cntx.parent_sg_id = scr_info->group_id;

    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ENTRY_CALL_SCR_INTERNAL); 

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) == 0)
    {    
        mdi_audio_suspend_background_play();
    }

    /* back from history */
    if (g_mmi_vtcs_cntx.state == MMI_VTCS_STATE_BACKGROUND)
    {
        /* back from backgroudn play, stop it */
        mmi_vtcs_pause_background_display();

    }
    
    g_mmi_vtcs_cntx.state = MMI_VTCS_STATE_FOREGROUND;        
	g_mmi_vtcs_cntx.is_local_image_off = MMI_FALSE;
	g_mmi_vtcs_cntx.is_fullscreen_state = MMI_FALSE;

    /* hook destroy screen hdlr */
    /* this destroy call back will be called after exit function */
    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_VT, SCR_ID_UCM_VT_INCALL, (mmi_proc_func) mmi_vtcs_scrn_group_proc);

   /*************************************************************************
    * Init proper state for video applcation                                                                   
    *************************************************************************/

    /* stop LED patten */
    srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_STOP);

    /* stop lcd sleep in */
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);

    /* use medium font */
    gui_set_font(&MMI_medium_font);

#ifdef MMI_VTCS_LANDSCAPE_MODE
    /* landscape mode will force not to show status */
    entry_full_screen();
#endif
#if ( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )
    entry_full_screen();
#endif
#if defined(__MMI_TOUCH_SCREEN__)
    wgui_register_pen_down_handler(mmi_vtcs_touch_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_vtcs_touch_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_vtcs_touch_pen_move_hdlr);
#endif /* defined(__MMI_TOUCH_SCREEN__) */

    /******************************
     * Init                                                                 
     ******************************/
    /* init state */
    if(mmi_frm_scrn_get_active_gui_buf() != NULL)
    {
        /* back from history */
        mmi_vtcs_init_state(MMI_FALSE);
    }
    else
    {
        mdi_util_create_hw_layer_in_struct  layer_in;
        mdi_util_create_hw_layer_out_struct layer_out;       
        /* newly enter */
        mmi_vtcs_init_state(MMI_TRUE);
        layer_in.app_id = g_mmi_vtcs_cntx.parent_sg_id;
        layer_in.offset_x = g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_x;
        layer_in.offset_y = g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_y;
        layer_in.width = g_mmi_vtcs_skin_cntx.sub_wnd_rect.width;
        layer_in.height = g_mmi_vtcs_skin_cntx.sub_wnd_rect.height;
        g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle = mdi_util_hw_layer_create(&layer_in, &layer_out);

        gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle);
        gdi_layer_set_background(GDI_COLOR_BLACK);    
        gdi_layer_pop_and_restore_active();        
        
        layer_in.app_id = g_mmi_vtcs_cntx.parent_sg_id;
        layer_in.offset_x = g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_x;
        layer_in.offset_y = g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_y;
        //layer_in.width = g_mmi_vtcs_skin_cntx.main_wnd_rect.width;
        //layer_in.height = g_mmi_vtcs_skin_cntx.main_wnd_rect.height;
        layer_in.width = MMI_VTCS_MAX_WIDTH;
		layer_in.height = MMI_VTCS_MAX_HEIGHT;
        g_mmi_vtcs_cntx.main_wnd_hw_layer_handle = mdi_util_hw_layer_create(&layer_in, &layer_out);
        
        gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.main_wnd_hw_layer_handle);
		gdi_layer_resize(g_mmi_vtcs_skin_cntx.main_wnd_rect.width, g_mmi_vtcs_skin_cntx.main_wnd_rect.height);
        gdi_layer_set_background(GDI_COLOR_BLACK);    
        gdi_layer_pop_and_restore_active();          
    }


    /* get and init resource */
    mmi_vtcs_allocate_resource();

    /* init key event  */
    mmi_vtcs_register_key_event();

    /* draw image to encode layer */        
    mmi_vtcs_draw_encode_layer();    

    /******************************
     * draw skin                                                                 
     ******************************/
    mmi_vtcs_draw_skin();
    mmi_vtcs_blt();

    if(mmi_is_redrawing_bk_screens())
    {
        /* 
         * redraw small screen, shall return after the skin is drawn, 
         * no need to start codec
         */
        /* change to mode exit, so will not driver to stop since it is not started yet */
        g_mmi_vtcs_cntx.mode = MMI_VTCS_DISPLAY_MODE_NONE;
        return;
    }

#ifdef MMI_VTCS_UT_DEBUG
    if (g_mmi_vtcs_cntx.is_ut)
    {
        SetKeyHandler(mmi_vtcs_ut_9_press, KEY_9, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_ut_8_press, KEY_8, KEY_EVENT_DOWN);        
        SetKeyHandler(mmi_vtcs_ut_pound_press, KEY_POUND, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_ut_toggle_mode, KEY_STAR, KEY_EVENT_DOWN);        
        
        /* to change to in call mode */
        g_mmi_vtcs_cntx.mode -= 4;
        mmi_vtcs_ut_enter_mode(g_mmi_vtcs_cntx.mode);
        return;
    }
#endif

    /* start display */
    //if (screen_info.state == MMI_FRM_SCREEN_BACKWARD)
    if(g_mmi_vtcs_cntx.has_open_MED)
    {
        /* back from history */
        if (mmi_vtcs_resume_display(MMI_FALSE) != MDI_RES_VDOTEL_SUCCEED)
        {
            /* camera error */
            mmi_vtcs_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            return;
        }

    }
    else
    {
        if (mmi_vtcs_start_display(MMI_TRUE) != MDI_RES_VDOTEL_SUCCEED)
        {
            /* camera error */
            mmi_vtcs_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            return;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_exit_call_scr
 * DESCRIPTION
 *  Exit VT call screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vtcs_exit_call_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_enable_bg_play = MMI_TRUE; /* tmp close due to codec conflict */
	gdi_handle main_layer_temp_handle = 0;
	gdi_handle sub_layer_temp_handle = 0;
	//U16 temp_mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_EXIT_CALL_SCR,g_mmi_vtcs_cntx.mode); 
    if (g_mmi_vtcs_cntx.mode != MMI_VTCS_DISPLAY_MODE_NONE)
    {    
        /* get screen info, and determine what to do in thi s exit function */

        if(!mmi_frm_is_in_backward_scenario())
        {
            if(!mmi_is_redrawing_bk_screens())
            {
                /* screen foward, means enter option, shall enable background display */
                //mmi_vtcs_pause_display();
                
                if (is_enable_bg_play && 
                    (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
                     g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||
                     g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 ||
                     g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4))
                {
                    mmi_vtcs_pause_display();
                    g_mmi_vtcs_cntx.state = MMI_VTCS_STATE_BACKGROUND;
                    /* start bg display with 3a disable */
                    mmi_vtcs_resume_background_display(MMI_FALSE);
                }
                else
                {
                    mmi_vtcs_stop_display();
                    g_mmi_vtcs_cntx.has_open_MED = MMI_FALSE;
                    g_mmi_vtcs_cntx.state = MMI_VTCS_STATE_EXIT;
                }
            }                
            else
            {
                /* redraw small screen bg */
                /* since display not start yet, we do not need to stop it */
                g_mmi_vtcs_cntx.state = MMI_VTCS_STATE_EXIT;               
            }
        }
        else //if (screen_info & MMI_SCENARIO_STATE_BACKWARD)
        {
            /* screen backward, means exit app */
            mmi_vtcs_pause_display();                        
            g_mmi_vtcs_cntx.state = MMI_VTCS_STATE_EXIT;
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
        #endif
    }
	
	/* flatten layer to base */
    gdi_layer_flatten_previous_to_base();
		
    if(g_mmi_vtcs_cntx.is_fullscreen_state)
    {
    	gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.main_wnd_hw_layer_handle);
		gdi_layer_resize(g_mmi_vtcs_skin_cntx.main_wnd_rect.width,g_mmi_vtcs_skin_cntx.main_wnd_rect.height);
		gdi_layer_set_position(g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_x, g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_y);
		gdi_layer_pop_and_restore_active();

		gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.main_wnd_layer_handle);
		gdi_layer_resize(g_mmi_vtcs_skin_cntx.main_wnd_rect.width,g_mmi_vtcs_skin_cntx.main_wnd_rect.height);
		gdi_layer_set_position(g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_x, g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_y);
		gdi_layer_pop_and_restore_active();
	
		gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle);
		gdi_layer_set_position(g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_x, g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_y);
		gdi_layer_pop_and_restore_active();
		
		gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.sub_wnd_layer_handle);
		gdi_layer_set_position(g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_x, g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_y);
		gdi_layer_pop_and_restore_active();

		g_mmi_vtcs_cntx.is_fullscreen_state = MMI_FALSE;
    	
    }

    mdi_util_hw_layer_switch_to_sw_layer(g_mmi_vtcs_cntx.main_wnd_hw_layer_handle);
    mdi_util_hw_layer_switch_to_sw_layer(g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle);
    

    /* UT code */
    if (g_mmi_vtcs_cntx.is_ut)
    {
        mmi_vtcs_ut_exit_mode();
    }

	if(g_mmi_vtcs_cntx.original_brightness_state == MMI_VT_BRIGHTNESS_LEVEL0)
		g_mmi_vtcs_cntx.original_brightness_state = MMI_VT_BRIGHTNESS_LEVEL3;
		
    srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD,  g_mmi_vtcs_cntx.original_brightness_state); 
	/* srv_backlight_set_real_level not work if there is no operation,so must turn on */
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    mdi_audio_resume_background_play();
    /* stop timers */
    gui_cancel_timer(mmi_vtcs_panel_restore_hdlr);   
    gui_cancel_timer(mmi_vtcs_update_call_status_cyclic);       
    gui_cancel_timer(mmi_vtcs_vol_up_cyclic);
    gui_cancel_timer(mmi_vtcs_vol_down_cyclic);
    gui_cancel_timer(mmi_vtcs_ev_inc_cyclic);
    gui_cancel_timer(mmi_vtcs_ev_dec_cyclic);
    gui_cancel_timer(mmi_vtcs_zoom_in_cyclic);
    gui_cancel_timer(mmi_vtcs_zoom_out_cyclic);    

    /* resume alignment timer */
    UI_disable_alignment_timers();

    /* resume LCD patten */
    srv_gpio_play_pattern(SRV_GPIO_PATN_LED_PWRON, SRV_GPIO_PATN_PLAY_STOP);

    /* let MMI can sleep */
    srv_backlight_turn_off();

    /* free resource */
    mmi_vtcs_free_resource();

#ifndef MMI_VTCS_LANDSCAPE_MODE
    /* restore status display layer */
    wgui_status_icon_bar_reset_target_layer(WGUI_STATUS_ICON_BAR_H_BAR);
#endif 

#if ( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )
    /* restore status display layer */
    wgui_status_icon_bar_reset_target_layer(WGUI_STATUS_ICON_BAR_H_BAR);
#endif    

#ifdef __MMI_SUBLCD__
    /* exit sublcd */
    if (g_mmi_vtcs_cntx.is_sub_display)
    {
        g_mmi_vtcs_cntx.is_sub_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 

}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_screen_delete_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means it can't be deleted
 *  MMI_FALSE means it can be deleted
 *****************************************************************************/
static MMI_BOOL mmi_vtcs_screen_delete_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) == 0 &&
         srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) == 0) ||
        mmi_ucm_vt_get_incall_screen_mode() != MMI_UCM_VT_INCALL_SCREEN_MODE_INCALL)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_destroy_call_scr_history
 * DESCRIPTION
 *  Destroy call screen from history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_destroy_call_scr_history(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_DESTROY_CALL_SCR_HISTORY,g_mmi_vtcs_cntx.state); 
    /* destory from history */
    if (g_mmi_vtcs_cntx.state == MMI_VTCS_STATE_BACKGROUND)
    {
        /* backgroudn play, stop it */
        mmi_vtcs_stop_background_display();
    }
    else
    {
        if (g_mmi_vtcs_cntx.mode != MMI_VTCS_DISPLAY_MODE_8 &&
            g_mmi_vtcs_cntx.mode != MMI_VTCS_DISPLAY_MODE_7)    
        {
              if(g_mmi_vtcs_cntx.has_open_MED)
              {
                g_mmi_vtcs_cntx.has_open_MED = MMI_FALSE; 
                mdi_video_tel_stop();
            }
        }
    }

    g_mmi_vtcs_cntx.state = MMI_VTCS_STATE_EXIT;  
    mdi_util_hw_layer_free(g_mmi_vtcs_cntx.main_wnd_hw_layer_handle);
    g_mmi_vtcs_cntx.main_wnd_hw_layer_handle = GDI_NULL_HANDLE;
    mdi_util_hw_layer_free(g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle);
    g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle = GDI_NULL_HANDLE;    
    
    mmi_ucm_vt_set_incall_screen_mode(MMI_UCM_VT_INCALL_SCREEN_MODE_NONE);
}

mmi_ret mmi_vtcs_scrn_group_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:            
            if (MMI_TRUE == mmi_vtcs_screen_delete_callback())
            {
                return MMI_RET_ERR; 
            }
            break;      
        case EVT_ID_SCRN_DEINIT:
            mmi_vtcs_destroy_call_scr_history(NULL);            
            break;         
    }

    return MMI_RET_OK;

}


#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_touch_hit_test
 * DESCRIPTION
 *  Test if is within touch region
 * PARAMETERS
 *  pos_x                   [IN]        Position x
 *  pos_y                   [IN]        Position y
 *  touch_obj_ptr           [IN]        Touch object structure
 * RETURNS
 *  BOOL
 *****************************************************************************/
static BOOL mmi_vtcs_touch_hit_test(S32 pos_x, S32 pos_y, mmi_vtcs_touch_struct *touch_obj_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_HIT_TEST,touch_obj_ptr->is_usable,pos_x,pos_y); 
    if (!touch_obj_ptr->is_usable)
    {
        return FALSE;
    }
    
    if ((pos_x >= touch_obj_ptr->offset_x) &&
        (pos_x < touch_obj_ptr->offset_x + touch_obj_ptr->width) &&
        (pos_y >= touch_obj_ptr->offset_y) && (pos_y < touch_obj_ptr->offset_y + touch_obj_ptr->height))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_HIT_TEST_RESULT,1); 
        return TRUE;
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_HIT_TEST_RESULT,0);
        return FALSE;
    }
}


void mmi_vtcs_vk_number_key_press(mmi_vtcs_touch_obj_enum vk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vt_uii_struct *msg_req;
    U16 key_code = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VK_NUMBER_KEY_PRESS,vk); 
    /* get key_code */
    switch(vk)
    {
        case MMI_VTCS_TOUCH_VK_0:
            key_code = KEY_0;
            g_mmi_vtcs_cntx.touch_vk_0.is_press = MMI_TRUE;
            break;
            
        case MMI_VTCS_TOUCH_VK_1:
            key_code = KEY_1;
            g_mmi_vtcs_cntx.touch_vk_1.is_press = MMI_TRUE;
            break;

        case MMI_VTCS_TOUCH_VK_2:
            key_code = KEY_2;
            g_mmi_vtcs_cntx.touch_vk_2.is_press = MMI_TRUE;
            break;

        case MMI_VTCS_TOUCH_VK_3:
            key_code = KEY_3;
            g_mmi_vtcs_cntx.touch_vk_3.is_press = MMI_TRUE;
            break;

        case MMI_VTCS_TOUCH_VK_4:
            key_code = KEY_4;
            g_mmi_vtcs_cntx.touch_vk_4.is_press = MMI_TRUE;
            break;

        case MMI_VTCS_TOUCH_VK_5:
            key_code = KEY_5;
            g_mmi_vtcs_cntx.touch_vk_5.is_press = MMI_TRUE;
            break;

        case MMI_VTCS_TOUCH_VK_6:
            key_code = KEY_6;
            g_mmi_vtcs_cntx.touch_vk_6.is_press = MMI_TRUE;
            break;

        case MMI_VTCS_TOUCH_VK_7:
            g_mmi_vtcs_cntx.touch_vk_7.is_press = MMI_TRUE;  
            key_code = KEY_7;
            break;

        case MMI_VTCS_TOUCH_VK_8:
            g_mmi_vtcs_cntx.touch_vk_8.is_press = MMI_TRUE;            
            key_code = KEY_8;
            break;

        case MMI_VTCS_TOUCH_VK_9:
            g_mmi_vtcs_cntx.touch_vk_9.is_press = MMI_TRUE;            
            key_code = KEY_9;
            break;

        case MMI_VTCS_TOUCH_VK_STAR:
            g_mmi_vtcs_cntx.touch_vk_star.is_press = MMI_TRUE;                        
            key_code = KEY_STAR;
            break;

        case MMI_VTCS_TOUCH_VK_POUND:
            g_mmi_vtcs_cntx.touch_vk_pound.is_press = MMI_TRUE;                        
            key_code = KEY_POUND;
            break;

        default:
            MMI_ASSERT(0);

    }
    
        
    /* send meesage to VT */
    msg_req = (mmi_vt_uii_struct*) construct_local_para(sizeof(mmi_vt_uii_struct), TD_CTRL | TD_RESET);

    msg_req->uiiLength = 1;
    msg_req->uiiString[0] = mmi_vtcs_convert_key_code_to_ascii(key_code);
    
    mmi_frm_send_ilm(        
        MOD_VT,
        MSG_ID_MMI_VT_UII,
        (oslParaType*) msg_req,
        NULL);
            
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_CS_SEND_UII, key_code);

    mmi_vtcs_add_to_input_box(key_code);

#ifndef __MMI_VTCS_FTE__
    /* start restore time */
    gui_start_timer((MMI_VTCS_CTRL_PANEL_RESTORE_DUR + 3000), mmi_vtcs_panel_restore_hdlr);      
#endif

    mmi_vtcs_draw_panel();
    mmi_vtcs_draw_softkey();

#ifndef __MMI_VTCS_FTE__        
    mmi_vtcs_open_sub_wnd_hole();    
#endif    
    mmi_vtcs_blt();        

}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_vk_number_key_release
 * DESCRIPTION
 *  Pen down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vtcs_vk_number_key_release(mmi_vtcs_touch_obj_enum vk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_VK_NUMBER_KEY_RELEASE,vk); 
    switch(vk)
    {
        case MMI_VTCS_TOUCH_VK_0:
            g_mmi_vtcs_cntx.touch_vk_0.is_press = MMI_FALSE;
            break;
            
        case MMI_VTCS_TOUCH_VK_1:
            g_mmi_vtcs_cntx.touch_vk_1.is_press = MMI_FALSE;
            break;

        case MMI_VTCS_TOUCH_VK_2:
            g_mmi_vtcs_cntx.touch_vk_2.is_press = MMI_FALSE;
            break;

        case MMI_VTCS_TOUCH_VK_3:
            g_mmi_vtcs_cntx.touch_vk_3.is_press = MMI_FALSE;
            break;

        case MMI_VTCS_TOUCH_VK_4:
            g_mmi_vtcs_cntx.touch_vk_4.is_press = MMI_FALSE;
            break;

        case MMI_VTCS_TOUCH_VK_5:
            g_mmi_vtcs_cntx.touch_vk_5.is_press = MMI_FALSE;
            break;

        case MMI_VTCS_TOUCH_VK_6:
            g_mmi_vtcs_cntx.touch_vk_6.is_press = MMI_FALSE;
            break;

        case MMI_VTCS_TOUCH_VK_7:
            g_mmi_vtcs_cntx.touch_vk_7.is_press = MMI_FALSE;
            break;

        case MMI_VTCS_TOUCH_VK_8:
            g_mmi_vtcs_cntx.touch_vk_8.is_press = MMI_FALSE;
            break;

        case MMI_VTCS_TOUCH_VK_9:
            g_mmi_vtcs_cntx.touch_vk_9.is_press = MMI_FALSE;
            break;

        case MMI_VTCS_TOUCH_VK_STAR:
            g_mmi_vtcs_cntx.touch_vk_star.is_press = MMI_FALSE;
            break;

        case MMI_VTCS_TOUCH_VK_POUND:
            g_mmi_vtcs_cntx.touch_vk_pound.is_press = MMI_FALSE;
            break;

        default:
            MMI_ASSERT(0);

    }   

    mmi_vtcs_draw_panel();
	mmi_vtcs_draw_softkey();
    mmi_vtcs_blt();
    
}

static void mmi_vtcs_touch_pen_feedback_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VTCS_FTE__    
    if(g_mmi_vtcs_cntx.touch_obj != MMI_VTCS_TOUCH_NONE)
    {
        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_touch_pen_down_hdlr
 * DESCRIPTION
 *  Pen down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_touch_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_DOWN_HDLR,g_mmi_vtcs_cntx.touch_obj,pos.x, pos.y); 

	/* rsk */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_RSK); 
	if(g_mmi_vtcs_cntx.is_fullscreen_state)
	{
	    if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_rsk))
        {
       		 mmi_vtcs_rsk_press();
       		 g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_RSK;
        	 mmi_vtcs_touch_pen_feedback_hdlr();
        	 return;
        }
		return;
	}
	
    /* lsk */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_LSK); 
    if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_lsk))
    {
        mmi_vtcs_lsk_press();
        g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_LSK;
        mmi_vtcs_touch_pen_feedback_hdlr();
        return;
    }

    /* rsk */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_RSK); 
    if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_rsk))
    {
        mmi_vtcs_rsk_press();
        g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_RSK;
        mmi_vtcs_touch_pen_feedback_hdlr();
        return;
    }

    /* panel */
#ifdef __MMI_VTCS_FTE__
    if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_TIME_ICON)
#else
    if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_TIME_ICON || 
        g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_EV ||
        g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_ZOOM ||
        g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_VOL)
#endif        
    {
        /* camera */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_CAMERA); 
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_camera))
        {
            mmi_vtcs_camera_key_press();
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_CAMERA;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }
        
        /* mic */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_MIC); 
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_mic))
        {
            mmi_vtcs_mic_key_press();
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_MIC;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }

        /* speaker */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_SPEAKER); 
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_speaker))
        {
            mmi_vtcs_speaker_key_press();
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_SPEAKER;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }

        /* aud rec */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_AUD_REC); 
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_aud_rec))
        {
            mmi_vtcs_aud_rec_key_press();
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_AUD_REC;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }
    #ifdef __MMI_VTCS_OP01__
        
        /* briness up */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_BRIGHTNESS_UP); 
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_brightness_up))
        {
            mmi_vtcs_brightness_up_key_press();
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_BRIGHTNESS_UP;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }
        
        /* briness down */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_BRIGHTNESS_DOWN); 
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_brightness_down))
        {
            mmi_vtcs_brightness_down_key_press();
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_BRIGHTNESS_DOWN;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_CONTRAST); 
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_contrast))
        {
            mmi_vtcs_contrast_key_press();
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_CONTRAST;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }
		/*fullscreen */
        //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_FULLSCRENN); 
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_fullscreen))
        {
            mmi_vtcs_fullscreen_key_press();
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_FULLSCREEN;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }
    #endif

        /* ev */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_EV); 
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_ev))
        {
            mmi_vtcs_ev_key_press();
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_EV;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }

        /* zoom */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_ZOOM); 
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_zoom))
        {
            mmi_vtcs_zoom_key_press();
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_ZOOM;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }

        /* snapshot */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_SNAPSHOT); 
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_snapshot))
        {
            mmi_vtcs_snapshot_key_press();
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_SNAPSHOT;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }

        /* vk */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_VK); 
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk))
        {
            mmi_vtcs_vk_key_press();
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_VK;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }        
    }
    
    if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_EV ||
        g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_ZOOM ||
        g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_VOL)
    {
        /* inc */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_INC); 
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_inc))
        {        
            kal_uint8 slider_type_flag = 0;        
            if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_EV)
            {
                slider_type_flag = MMI_VTCS_PANEL_STATE_SCROLL_EV;
                mmi_vtcs_ev_inc_key_press();
            }
            else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_ZOOM)
            {
                slider_type_flag = MMI_VTCS_PANEL_STATE_SCROLL_ZOOM;
                mmi_vtcs_zoom_in_key_press();
            }
            else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_VOL)
            {
                slider_type_flag = MMI_VTCS_PANEL_STATE_SCROLL_VOL;
                mmi_vtcs_vol_up_key_press();
            }
            else
            {
                MMI_ASSERT(0);
            }
            /* bug fix : the panel store may happen between above and below */
            /*           no always set touch_obj or it will cause not match panel state when pen up */
            if(g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_EV ||
               g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_ZOOM ||
               g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_VOL)
            {
              
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_INC;
            } 
            /* set the key up if the restore happen between above and below */
            else
            {
                if (slider_type_flag == MMI_VTCS_PANEL_STATE_SCROLL_EV)
                {
                    mmi_vtcs_ev_inc_key_release();
                }
                else if (slider_type_flag == MMI_VTCS_PANEL_STATE_SCROLL_ZOOM)
                {
                    mmi_vtcs_zoom_in_key_release();
                }
                else if (slider_type_flag == MMI_VTCS_PANEL_STATE_SCROLL_VOL)
                {
                    mmi_vtcs_vol_up_key_release();
                }                  
            }                   
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
            
        }

        /* dec */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_DEC); 
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_dec))
        {        
            /* bug fix : the panel store may happen between above and below */
            /*           no always set touch_obj or it will cause not match panel state when pen up */               
            kal_uint8 slider_type_flag = 0;                 
            if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_EV)
            {
                slider_type_flag = MMI_VTCS_PANEL_STATE_SCROLL_EV;                
                mmi_vtcs_ev_dec_key_press();
            }
            else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_ZOOM)
            {
                slider_type_flag = MMI_VTCS_PANEL_STATE_SCROLL_ZOOM;                
                mmi_vtcs_zoom_out_key_press();
            }
            else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_VOL)
            {
                slider_type_flag = MMI_VTCS_PANEL_STATE_SCROLL_VOL;                
                mmi_vtcs_vol_down_key_press();
            }
            else
            {
                MMI_ASSERT(0);
            }
            
            if(g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_EV ||
               g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_ZOOM ||
               g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_VOL)
            {
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_DEC;
            }     
            /* set the key up if the restore happen between above and below */
            else
            {
                if (slider_type_flag == MMI_VTCS_PANEL_STATE_SCROLL_EV)
                {
                    mmi_vtcs_ev_dec_key_release();
                }
                else if (slider_type_flag == MMI_VTCS_PANEL_STATE_SCROLL_ZOOM)
                {
                    mmi_vtcs_zoom_out_key_release();
                }
                else if (slider_type_flag == MMI_VTCS_PANEL_STATE_SCROLL_VOL)
                {
                    mmi_vtcs_vol_down_key_release();
                }                  
            }                        
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }

        /* slider */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_TEST_OBJ,MMI_VTCS_TOUCH_SLIDER); 
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_slider))
        {    
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_SLIDER;
            gui_cancel_timer(mmi_vtcs_panel_restore_hdlr);
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }
    }
    
    if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_USER_INPUT_VK)
    {

        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_0))
        {
            mmi_vtcs_vk_number_key_press(MMI_VTCS_TOUCH_VK_0);
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_VK_0;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }        
        else if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_1))
        {
            mmi_vtcs_vk_number_key_press(MMI_VTCS_TOUCH_VK_1);
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_VK_1;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }
        else if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_2))
        {
            mmi_vtcs_vk_number_key_press(MMI_VTCS_TOUCH_VK_2);
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_VK_2;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }
        else if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_3))
        {
            mmi_vtcs_vk_number_key_press(MMI_VTCS_TOUCH_VK_3);
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_VK_3;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }
        else if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_4))
        {
            mmi_vtcs_vk_number_key_press(MMI_VTCS_TOUCH_VK_4);
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_VK_4;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }
        else if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_5))
        {
            mmi_vtcs_vk_number_key_press(MMI_VTCS_TOUCH_VK_5);
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_VK_5;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }
        else if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_6))
        {
            mmi_vtcs_vk_number_key_press(MMI_VTCS_TOUCH_VK_6);
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_VK_6;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }
        else if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_7))
        {
            mmi_vtcs_vk_number_key_press(MMI_VTCS_TOUCH_VK_7);
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_VK_7;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }
        else if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_8))
        {
            mmi_vtcs_vk_number_key_press(MMI_VTCS_TOUCH_VK_8);
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_VK_8;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }
        else if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_9))
        {
            mmi_vtcs_vk_number_key_press(MMI_VTCS_TOUCH_VK_9);
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_VK_9;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }
        else if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_star))
        {
            mmi_vtcs_vk_number_key_press(MMI_VTCS_TOUCH_VK_STAR);
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_VK_STAR;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }
        else if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_pound))
        {
            mmi_vtcs_vk_number_key_press(MMI_VTCS_TOUCH_VK_POUND);
            g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_VK_POUND;
            mmi_vtcs_touch_pen_feedback_hdlr();
            return;
        }
    }


}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_touch_pen_up_hdlr
 * DESCRIPTION
 *  Pen down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_touch_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_UP_HDLR,g_mmi_vtcs_cntx.touch_obj,pos.x, pos.y);     
    switch (g_mmi_vtcs_cntx.touch_obj)
    {
        case MMI_VTCS_TOUCH_NONE:
            /* do nothing */
            break;

        case MMI_VTCS_TOUCH_EV:
            mmi_vtcs_ev_key_release();
            break;

        case MMI_VTCS_TOUCH_ZOOM:
            mmi_vtcs_zoom_key_release();
            break;

        case MMI_VTCS_TOUCH_CAMERA:
            mmi_vtcs_camera_key_release();
            break;

        case MMI_VTCS_TOUCH_MIC:
            mmi_vtcs_mic_key_release();
            break;

        case MMI_VTCS_TOUCH_SPEAKER:
            mmi_vtcs_speaker_key_release();
            break;

        case MMI_VTCS_TOUCH_AUD_REC:
            mmi_vtcs_aud_rec_key_release();
            break;

    #ifdef __MMI_VTCS_OP01__
        case MMI_VTCS_TOUCH_BRIGHTNESS_UP:
            mmi_vtcs_brightness_up_key_release();
            break;

        case MMI_VTCS_TOUCH_BRIGHTNESS_DOWN:
            mmi_vtcs_brightness_down_key_release();
            break;

        case MMI_VTCS_TOUCH_CONTRAST:
            mmi_vtcs_contrast_key_release();
            break;            
		case MMI_VTCS_TOUCH_FULLSCREEN:
            mmi_vtcs_fullscreen_key_release();
            break;  
    #endif
            
       case MMI_VTCS_TOUCH_SNAPSHOT:
            mmi_vtcs_snapshot_key_release();
            break;

       case MMI_VTCS_TOUCH_VK:
            mmi_vtcs_vk_key_release();
            break;

       case MMI_VTCS_TOUCH_LSK:
            mmi_vtcs_lsk_release();
            break;

       case MMI_VTCS_TOUCH_RSK:
            mmi_vtcs_rsk_release();
            break;

       case MMI_VTCS_TOUCH_INC:
            if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_EV)
            {
                mmi_vtcs_ev_inc_key_release();
            }
            else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_ZOOM)
            {
                mmi_vtcs_zoom_in_key_release();
            }
            else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_VOL)
            {
                mmi_vtcs_vol_up_key_release();
            }
            else
            {
                /* shall not enter here */                
                MMI_ASSERT(0);
            }
            break;

       case MMI_VTCS_TOUCH_DEC:
            if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_EV)
            {
                mmi_vtcs_ev_dec_key_release();
            }
            else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_ZOOM)
            {
                mmi_vtcs_zoom_out_key_release();
            }
            else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_VOL)
            {
                mmi_vtcs_vol_down_key_release();
            }
            else
            {
                /* shall not enter here */                
                MMI_ASSERT(0);
            }   
            break;

       case MMI_VTCS_TOUCH_SLIDER:
            {
                gui_start_timer(MMI_VTCS_CTRL_PANEL_RESTORE_DUR, mmi_vtcs_panel_restore_hdlr);  
            }    
            break;

       case MMI_VTCS_TOUCH_VK_0:
       case MMI_VTCS_TOUCH_VK_1:
       case MMI_VTCS_TOUCH_VK_2:
       case MMI_VTCS_TOUCH_VK_3:
       case MMI_VTCS_TOUCH_VK_4:
       case MMI_VTCS_TOUCH_VK_5:
       case MMI_VTCS_TOUCH_VK_6:
       case MMI_VTCS_TOUCH_VK_7:
       case MMI_VTCS_TOUCH_VK_8:
       case MMI_VTCS_TOUCH_VK_9:
       case MMI_VTCS_TOUCH_VK_STAR:        
       case MMI_VTCS_TOUCH_VK_POUND:        
            mmi_vtcs_vk_number_key_release(g_mmi_vtcs_cntx.touch_obj);
            break;
        
        default:
            /* unhandled case */
            MMI_ASSERT(0);
            break;

    }

    g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_touch_pen_move_hdlr
 * DESCRIPTION
 *  Pen down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_touch_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_TOUCH_PEN_MOVE_HDLR,g_mmi_vtcs_cntx.touch_obj,pos.x, pos.y);  
    switch (g_mmi_vtcs_cntx.touch_obj)
    {
        case MMI_VTCS_TOUCH_NONE:
            /* do nothing */
            break;

        case MMI_VTCS_TOUCH_EV:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_ev))
            {
                g_mmi_vtcs_cntx.touch_ev.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;                
                mmi_vtcs_draw_ev_icon();
                mmi_vtcs_blt();
            }            
            break;

        case MMI_VTCS_TOUCH_ZOOM:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_zoom))
            {
                g_mmi_vtcs_cntx.touch_zoom.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;                
                mmi_vtcs_draw_zoom_icon();
                mmi_vtcs_blt();
            }     
            break;

        case MMI_VTCS_TOUCH_CAMERA:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_camera))
            {
                g_mmi_vtcs_cntx.touch_camera.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;                
                mmi_vtcs_draw_camera_icon();
                mmi_vtcs_blt();
            }                 
            break;

        case MMI_VTCS_TOUCH_MIC:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_mic))
            {
                g_mmi_vtcs_cntx.touch_mic.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;                
                mmi_vtcs_draw_mic_icon();
                mmi_vtcs_blt();
            }                 
            break;

        case MMI_VTCS_TOUCH_SPEAKER:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_speaker))
            {
                g_mmi_vtcs_cntx.touch_speaker.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;                
                mmi_vtcs_draw_speaker_icon();
                mmi_vtcs_blt();
            }      
            break;

        case MMI_VTCS_TOUCH_AUD_REC:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_aud_rec))
            {
                g_mmi_vtcs_cntx.touch_aud_rec.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;                
                mmi_vtcs_draw_aud_rec_icon();
                mmi_vtcs_blt();
            }      
            break;

    #ifdef __MMI_VTCS_OP01__
        case MMI_VTCS_TOUCH_BRIGHTNESS_UP:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_brightness_up))
            {
                g_mmi_vtcs_cntx.touch_brightness_up.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;                
                mmi_vtcs_draw_brightness_up_icon();
                mmi_vtcs_blt();
            }      
            break;

        case MMI_VTCS_TOUCH_BRIGHTNESS_DOWN:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_brightness_down))
            {
                g_mmi_vtcs_cntx.touch_brightness_down.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;                
                mmi_vtcs_draw_brightness_down_icon();
                mmi_vtcs_blt();
            }      
            break;

        case MMI_VTCS_TOUCH_CONTRAST:            
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_contrast))
            {
                g_mmi_vtcs_cntx.touch_contrast.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;                
                mmi_vtcs_draw_contrast_icon();
                mmi_vtcs_blt();
            }      
            break;
		case MMI_VTCS_TOUCH_FULLSCREEN:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_brightness_up))
            {
                g_mmi_vtcs_cntx.touch_fullscreen.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;                
                mmi_vtcs_draw_fullscreen_icon();
                mmi_vtcs_blt();
            }      
            break;
    #endif

       case MMI_VTCS_TOUCH_SNAPSHOT:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_snapshot))
            {
                g_mmi_vtcs_cntx.touch_snapshot.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;                
                mmi_vtcs_draw_snapshot_icon();
                mmi_vtcs_blt();
            }   
            break;

       case MMI_VTCS_TOUCH_VK:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk))
            {
                g_mmi_vtcs_cntx.touch_vk.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;                
                mmi_vtcs_draw_vk_icon();
                mmi_vtcs_blt();
            }   
            break;

       case MMI_VTCS_TOUCH_RSK:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_rsk))
            {
                g_mmi_vtcs_cntx.touch_rsk.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;                
                mmi_vtcs_draw_softkey();
                mmi_vtcs_blt();
            }   
            break;

       case MMI_VTCS_TOUCH_LSK:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_lsk))
            {
                g_mmi_vtcs_cntx.touch_lsk.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;                
                mmi_vtcs_draw_softkey();
                mmi_vtcs_blt();
            }  
            break;

       case MMI_VTCS_TOUCH_INC:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_inc))
            {
                if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_EV)
                {
                    gui_cancel_timer(mmi_vtcs_ev_inc_cyclic); 
                    mmi_vtcs_ev_inc_key_release();
                }
                else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_ZOOM)
                { 
                    gui_cancel_timer(mmi_vtcs_zoom_in_cyclic); 
                    mmi_vtcs_zoom_in_key_release();
                }
                else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_VOL)
                {   
                    gui_cancel_timer(mmi_vtcs_vol_up_cyclic);                     
                    mmi_vtcs_vol_up_key_release();                
                }
                else
                {
                    /* shall not enter here */                
                    MMI_ASSERT(0);
                }   
                
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;     
                mmi_vtcs_scroll_inc_release();
                mmi_vtcs_draw_panel();
				mmi_vtcs_draw_softkey();
                mmi_vtcs_blt();

            }
            break;

       case MMI_VTCS_TOUCH_DEC:
           if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_dec))
           {
                if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_EV)
                {
                    gui_cancel_timer(mmi_vtcs_ev_dec_cyclic); 
                    mmi_vtcs_ev_dec_key_release();
                }
                else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_ZOOM)
                { 
                    gui_cancel_timer(mmi_vtcs_zoom_out_cyclic); 
                    mmi_vtcs_zoom_out_key_release();
                }
                else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_VOL)
                {   
                    gui_cancel_timer(mmi_vtcs_vol_down_cyclic);                     
                    mmi_vtcs_vol_down_key_release();                 
                }
                else
                {
                    /* shall not enter here */                
                    MMI_ASSERT(0);
                }   
                
                g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;     
                mmi_vtcs_scroll_dec_release();
                mmi_vtcs_draw_panel();
				mmi_vtcs_draw_softkey();
                mmi_vtcs_blt();

            }
            break;

       case MMI_VTCS_TOUCH_SLIDER:
            {
                S32 cur_pos_on_bar;

                cur_pos_on_bar = pos.x - g_mmi_vtcs_cntx.bar_offset_x;
                if (cur_pos_on_bar < 0)
                {
                    g_mmi_vtcs_cntx.scroll_cur_value = 0;
                }
                else if (cur_pos_on_bar >= g_mmi_vtcs_cntx.bar_width)
                {
                    g_mmi_vtcs_cntx.scroll_cur_value = g_mmi_vtcs_cntx.scroll_total_value - 1;
                }
                else
                {
                    g_mmi_vtcs_cntx.scroll_cur_value = (cur_pos_on_bar << 10) / g_mmi_vtcs_cntx.bar_step_width_shift10;
                }


                if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_EV)
                {
                    g_mmi_vtcs_cntx.ev_value = (mmi_vt_ev_enum)g_mmi_vtcs_cntx.scroll_cur_value;
                    if(g_mmi_vtcs_cntx.is_enc_path_built)  
                        mdi_video_tel_update_para_ev(mmi_vtcs_get_ev_factor());                      
                    mmi_ucm_vt_set_ev_status(g_mmi_vtcs_cntx.ev_value);  
                }
                else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_ZOOM)
                { 
                    g_mmi_vtcs_cntx.zoom_step = g_mmi_vtcs_cntx.scroll_cur_value;
                    if(g_mmi_vtcs_cntx.is_enc_path_built)                      
                        mdi_video_tel_update_para_zoom(g_mmi_vtcs_cntx.zoom_step);                      
                }
                else if (g_mmi_vtcs_cntx.panel_state == MMI_VTCS_PANEL_STATE_SCROLL_VOL)
                {   
                    g_mmi_vtcs_cntx.vol_value = (mmi_vt_vol_enum)g_mmi_vtcs_cntx.scroll_cur_value;
                    mmi_ucm_vt_set_volume_status(g_mmi_vtcs_cntx.vol_value);
                }
                else
                {
                    /* shall not enter here */                
                    MMI_ASSERT(0);
                }  

                mmi_vtcs_draw_panel();
            #ifdef __MMI_VTCS_FTE__
                mmi_vtcs_open_sub_wnd_hole();   
            #endif 
				mmi_vtcs_draw_softkey();
                mmi_vtcs_blt();
            } 
            break;


       case MMI_VTCS_TOUCH_VK_0:
           if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_0))
           {
               g_mmi_vtcs_cntx.touch_vk_0.is_press = MMI_FALSE;
               g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE; 
               mmi_vtcs_draw_panel();
			   mmi_vtcs_draw_softkey();
               mmi_vtcs_blt();
           }
           break;

       case MMI_VTCS_TOUCH_VK_1:
           if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_1))
           {
               g_mmi_vtcs_cntx.touch_vk_1.is_press = MMI_FALSE;
               g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE; 
               mmi_vtcs_draw_panel();
			   mmi_vtcs_draw_softkey();
               mmi_vtcs_blt();
           }
           break;

       case MMI_VTCS_TOUCH_VK_2:
           if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_2))
           {
               g_mmi_vtcs_cntx.touch_vk_2.is_press = MMI_FALSE;            
               g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE; 
               mmi_vtcs_draw_panel();
			   mmi_vtcs_draw_softkey();
               mmi_vtcs_blt();
           }
           break;

       case MMI_VTCS_TOUCH_VK_3:
           if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_3))
           {
               g_mmi_vtcs_cntx.touch_vk_3.is_press = MMI_FALSE;            
               g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE; 
               mmi_vtcs_draw_panel();
			   mmi_vtcs_draw_softkey();
               mmi_vtcs_blt();
           }
           break;

       case MMI_VTCS_TOUCH_VK_4:
           if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_4))
           {
               g_mmi_vtcs_cntx.touch_vk_4.is_press = MMI_FALSE;                        
               g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE; 
               mmi_vtcs_draw_panel();
			   mmi_vtcs_draw_softkey();
               mmi_vtcs_blt();
           }
           break;

       case MMI_VTCS_TOUCH_VK_5:
           if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_5))
           {
               g_mmi_vtcs_cntx.touch_vk_5.is_press = MMI_FALSE;                                    
               g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE; 
               mmi_vtcs_draw_panel();
			   mmi_vtcs_draw_softkey();
               mmi_vtcs_blt();
           }
           break;

       case MMI_VTCS_TOUCH_VK_6:
           if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_6))
           {
               g_mmi_vtcs_cntx.touch_vk_6.is_press = MMI_FALSE;                                    
               g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE; 
               mmi_vtcs_draw_panel();
			   mmi_vtcs_draw_softkey();
               mmi_vtcs_blt();
           }
           break;

       case MMI_VTCS_TOUCH_VK_7:
           if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_7))
           {
               g_mmi_vtcs_cntx.touch_vk_7.is_press = MMI_FALSE;                                    
               g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE; 
               mmi_vtcs_draw_panel();
			   mmi_vtcs_draw_softkey();
               mmi_vtcs_blt();
           }
           break;

       case MMI_VTCS_TOUCH_VK_8:
           if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_8))
           {
               g_mmi_vtcs_cntx.touch_vk_8.is_press = MMI_FALSE;
               g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE; 
               mmi_vtcs_draw_panel();
			   mmi_vtcs_draw_softkey();
               mmi_vtcs_blt();
           }
           break;

       case MMI_VTCS_TOUCH_VK_9:
           if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_9))
           {
               g_mmi_vtcs_cntx.touch_vk_9.is_press = MMI_FALSE;            
               g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE; 
               mmi_vtcs_draw_panel();
			   mmi_vtcs_draw_softkey();
               mmi_vtcs_blt();
           }
           break;

       case MMI_VTCS_TOUCH_VK_STAR:
           if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_star))
           {
               g_mmi_vtcs_cntx.touch_vk_star.is_press = MMI_FALSE;            
               g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE; 
               mmi_vtcs_draw_panel();
			   mmi_vtcs_draw_softkey();
               mmi_vtcs_blt();
           }
           break;

       case MMI_VTCS_TOUCH_VK_POUND:
           if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_vk_pound))
           {
               g_mmi_vtcs_cntx.touch_vk_pound.is_press = MMI_FALSE;                
               g_mmi_vtcs_cntx.touch_obj = MMI_VTCS_TOUCH_NONE; 
               mmi_vtcs_draw_panel();
			   mmi_vtcs_draw_softkey();
               mmi_vtcs_blt();
           }
           break;

        default:
            /* unhandled case */
            MMI_ASSERT(0);
            break;

    }

//    case VDOPLY_TOUCH_VOLUME_INC:
//        if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_volume_inc))
//        {
//            g_vdoply_cntx.full_touch_volume_inc.is_press = FALSE;
//
//            mmi_vdoply_draw_fullscr_osd();
//            mmi_vdoply_blt_screen();
//            g_vdoply_cntx.touch_obj = MMI_VTCS_TOUCH_NONE;
//        }
//        break;
    
}
#endif /* defined(__MMI_TOUCH_SCREEN__) */


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_entry_call_scr
 * DESCRIPTION
 *  Enter call screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vtcs_entry_call_scr(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ENTRY_CALL_SCR);  
    g_mmi_vtcs_cntx.is_ut = MMI_FALSE;
    mmi_vtcs_entry_call_scr_internal(scr_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_entry_call_scr_for_ut
 * DESCRIPTION
 *  Enter call screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vtcs_entry_call_scr_for_ut(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_vtcs_cntx.is_ut = MMI_TRUE;
    mmi_vtcs_entry_call_scr_internal(scr_info);
}



#ifdef MMI_VTCS_UT_DEBUG
/* UT related code */
void vt_qty_test(kal_uint32 q);
static U16 vt_q = 0;
static void mmi_vtcs_ut_9_press(void)
{
//    vt_qty_test(vt_q);
    vt_q++;

    if (vt_q > 3)
    {
        vt_q = 0;
    }
}

void vt_size_test(kal_uint32 s);
static U16 vt_s = 0;
static void mmi_vtcs_ut_8_press(void)
{
//    vt_qty_test(vt_s);
    vt_s++;

    if (vt_s > 1)
    {
        vt_s = 0;
    }
}




static void mmi_vtcs_ut_pound_press(void)
{
    mmi_vtcs_display_popup(STR_GLOBAL_OK, MMI_EVENT_FAILURE);
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
}

static void mmi_vtcs_ut_toggle_mode(void)
{
    mmi_vtcs_display_mode_enum mode;

    mode = g_mmi_vtcs_cntx.mode;
    if (mode < MMI_VTCS_DISPLAY_MODE_TOTAL - 1)
    {
        mode++;
    }
    else
    {
        mode = MMI_VTCS_DISPLAY_MODE_1;
    }

    mmi_vtcs_ut_exit_mode();
    g_mmi_vtcs_cntx.mode = mode;
    mmi_vtcs_ut_enter_mode(g_mmi_vtcs_cntx.mode);
}


static void mmi_vtcs_ut_enter_mode(mmi_vtcs_display_mode_enum mode)
{
    switch (mode)
    {
        case MMI_VTCS_DISPLAY_MODE_1:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 1", MMI_VTCS_TITLE_LEN);
            mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_3G324M);
            mdi_audio_speech_codec_start();           
            mdi_video_tel_enable_vt_loopback(); 
            break;

        case MMI_VTCS_DISPLAY_MODE_2:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 2", MMI_VTCS_TITLE_LEN);
            mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_3G324M);
            mdi_audio_speech_codec_start();           
            mdi_video_tel_enable_vt_loopback(); 
            break;        

        case MMI_VTCS_DISPLAY_MODE_3:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 3", MMI_VTCS_TITLE_LEN);
            mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_3G324M);
            mdi_audio_speech_codec_start();           
            mdi_video_tel_enable_vt_loopback(); 
            break;        

        case MMI_VTCS_DISPLAY_MODE_4:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 4", MMI_VTCS_TITLE_LEN);
            mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_3G324M);
            mdi_audio_speech_codec_start();           
            mdi_video_tel_enable_vt_loopback(); 
            break;         

        case MMI_VTCS_DISPLAY_MODE_5:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 6", MMI_VTCS_TITLE_LEN);
            break;            

        case MMI_VTCS_DISPLAY_MODE_6:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 7", MMI_VTCS_TITLE_LEN);
            break;   

        case MMI_VTCS_DISPLAY_MODE_8:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 9", MMI_VTCS_TITLE_LEN);
            break;     

        case MMI_VTCS_DISPLAY_MODE_7:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 10", MMI_VTCS_TITLE_LEN);
            break;     
            
        default:
            MMI_ASSERT(0);
    }

    mmi_vtcs_config_display_mode(mode);        
    mmi_vtcs_draw_skin();

    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 || 
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4)
    {        
        /* draw image to encode layer */        
        mmi_vtcs_draw_encode_layer();    
    }

    mmi_vtcs_config_layer_seq();
    mmi_vtcs_blt();
    
    mmi_vtcs_start_display(MMI_TRUE);
    
}

static void mmi_vtcs_ut_exit_mode(void)
{
    mmi_vtcs_stop_display();

    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 || 
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 || 
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 || 
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4)
    {
        mdi_audio_speech_codec_stop(); 
        mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_3G324M);
        mdi_video_tel_disable_vt_loopback();         
    }
    else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5 || 
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_6 || 
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_8 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_8 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_7)
    {
        /* do nothing */
    }
    else
    {
        mdi_audio_speech_codec_stop(); 
        mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_3G324M);
        mdi_video_tel_disable_vt_loopback();            
        //MMI_ASSERT(0);
    }

}

#endif /* MMI_VTCS_UT_DEBUG */

static void mmi_vtcs_entry_call_scr_normal()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 offset_x;
	S32 offset_y;
	gdi_handle main_layer_temp_handle = 0;
	gdi_handle sub_layer_temp_handle = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VTCS_ENTRY_CALL_SCR_INTERNAL);           

    /* use medium font */
    gui_set_font(&MMI_medium_font);
	mmi_vtcs_pause_display();
    mmi_vtcs_init_state(MMI_FALSE);
#ifdef MMI_VTCS_UT_DEBUG
			if (g_mmi_vtcs_cntx.is_ut)
			{				
				/* to change to in call mode */
				g_mmi_vtcs_cntx.mode -= 4;
			}
#endif

    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_6)
	{
		main_layer_temp_handle = g_mmi_vtcs_cntx.main_wnd_hw_layer_handle;
	}
	else
	{
		main_layer_temp_handle = g_mmi_vtcs_cntx.main_wnd_layer_handle;
	}
	if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5)
	{
		sub_layer_temp_handle = g_mmi_vtcs_cntx.sub_wnd_hw_layer_handle;
	}
	else
	{
		sub_layer_temp_handle = g_mmi_vtcs_cntx.sub_wnd_layer_handle;
	}
	
	gdi_layer_push_and_set_active(main_layer_temp_handle);
	gdi_layer_resize(g_mmi_vtcs_skin_cntx.main_wnd_rect.width,g_mmi_vtcs_skin_cntx.main_wnd_rect.height);
	//gdi_layer_get_dimension(&layer_width, &layer_height);
	gdi_layer_set_position(g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_x, g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_y);
	gdi_layer_pop_and_restore_active();
	
	gdi_layer_push_and_set_active(sub_layer_temp_handle);
	gdi_layer_set_position(g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_x, g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_y);
	gdi_layer_pop_and_restore_active();
	
	mmi_vtcs_config_layer_seq();
	mmi_vtcs_register_key_event();
	    /* draw image to encode layer */        
    mmi_vtcs_draw_encode_layer();    

    mmi_vtcs_draw_skin();
    mmi_vtcs_blt();

    /* start display */
    //if (screen_info.state == MMI_FRM_SCREEN_BACKWARD)
    if(g_mmi_vtcs_cntx.has_open_MED)
    {
        /* back from history */
        if (mmi_vtcs_resume_display(MMI_TRUE) != MDI_RES_VDOTEL_SUCCEED)
        {
            /* camera error */
            mmi_vtcs_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            return;
        }

    }
    else
    {
        if (mmi_vtcs_start_display(MMI_TRUE) != MDI_RES_VDOTEL_SUCCEED)
        {
            /* camera error */
            mmi_vtcs_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            return;
        }
    }

}

#endif /* __MMI_VIDEO_TELEPHONY__ */ 

