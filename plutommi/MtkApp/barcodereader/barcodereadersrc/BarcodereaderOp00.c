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
 *  BarcodeReader.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  QR Code Reader Applications v0.1
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "mmi_features.h"

#ifdef __MMI_BARCODEREADER__
#include "MMI_features_barcodereader.h"

#ifdef __MMI_OP00_BARCODEREADER__

#ifndef __MMI_CAMERA__
#error "Please turn on __MMI_CAMERA__"
#endif 
#include "mmi_include.h"

#include "CommonScreens.h"
#include "wgui_softkeys.h"
#include "gui_font_size.h"

#include "SettingProfile.h"
#include "USBDeviceGProt.h"
#include "gpioInc.h"
#include "app_datetime.h"
#include "datetimetype.h"
#include "Barcodereadergprot.h"
#include "drm_def.h"
#include "FileMgr.h"
#include "FileManagerResDef.h"
#include "FileManagerGProt.h"
#include "FileMgrStruct.h"
#include "Conversions.h"
#include "wapadp.h"

#include "WguiCategoryGprot.h" 
#include "PhoneBookGprot.h"
#include "PhbSrvGprot.h"
#include "PhbCUIGprot.h"

#include "vObjects.h"
#include "vCard.h"

#include "l4c_common_enum.h"
#include "resource_camera_skins.h"
#include "CameraGprot.h"
#include "mdi_camera.h"


/************************************************************************
* Supported functions related header file
************************************************************************/
//#include "CallManagementGprot.h"        /* for call management related functions */

/* SMS2.0 */    
#include "SmsCuiGprot.h"
//#include "SMSApi.h"     /* for SMS related functions */
#include "SmsAppGprot.h"
#include "SmsSrvGprot.h"

#include "wap_ps_struct.h"      /* for wap related functions */


#ifdef __MMI_TVOUT__
#include "mdi_tv.h"
#endif 

#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#include "EmailAppProt.h"
#endif /* __MMI_EMAIL__ */ 

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
#include "NetworkSetupDefs.h"
#include "VoIPGProt.h"
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */ 

#ifdef __MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__
#endif /* __MMI_BARCODEREADER_FEATURE_TOUCH_SCREEN__ */

#include "BarcodeReaderGprot.h"
#include "mmi_features_barcodereader.h"
#include "resource_barcodereader_skins.h"       /* UI custom config */
#include "BarcodeReaderOp00.h"  /* camera app data */
#include "barcodereaderOp00ResDef.h"    /* resource ID def */
#include "BarcodereaderCameraSetting.h"
#include "BarcodereaderCameraSettingProt.h"
#include "BarcodereaderLcd.h"

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#include "UcmSrvGProt.h"
#endif /*__MMI_UCM__*/

#include "mmsadp.h"

#include "FileMgrGProt.h"

/****************************************************************************
* Global Variable - Extern                                                                 
*****************************************************************************/
extern BOOL r2lMMIFlag;
/* FMGR_Revise */
//extern fmgr_context_struct *fmgr_p;
static S8 mmi_barcode_urlHttp[10] = {0x68, 0x74, 0x74, 0x70, 0x3a, 0x1b, 0x5c, 0x1b, 0x5c, 0x00};
static S8 mmi_barcode_urlHttps[11] = {0x68, 0x74, 0x74, 0x70, 0x73, 0x3a, 0x1b, 0x5c, 0x1b, 0x5c, 0x00};
static const PS8 mmi_barcode_urlPattern[MMI_BARCODEREADER_MAX_NUM_URL_PATTERN] = { "http", "www.", "wap." };
static const U16 mmi_barcode_urlPattern_length[MMI_BARCODEREADER_MAX_NUM_URL_PATTERN] = {4, 4, 4};
static const PS8 mmi_barcode_urlValidHttpPrefix[MMI_BARCODEREADER_MAX_NUM_VALID_HTTP_PREFIX] =
    { "http://", "http:\\\\", mmi_barcode_urlHttp, "https://", "https:\\\\", mmi_barcode_urlHttps};

/* for MAUI_01348442 */
static S32 fmgr_path_get = 0;

/***************************************************************************** 
* Define
*****************************************************************************/
#define DUMMY_COMMAND      (0)

#define MMI_BARCODEREADER_AF_LARGE_WIDTH               (25)
#define MMI_BARCODEREADER_AF_NORMAL_WIDTH           (25)
#define MMI_BARCODEREADER_AF_SMALL_WIDTH               (25)

#define MMI_BARCODEREADER_TRANSLATE_COORDINATE_TO_270(X,Y,TMP)\
            TMP=X;                                            \
            X=Y;                                              \
            Y=(LCD_WIDTH-1)-TMP;

#define  MMI_BARCODEREADER_IS_NUM(c)  (((c)>='0') && ((c)<='9'))

/***************************************************************************** 
* Enum
*****************************************************************************/
typedef enum
{
    MMI_BARCODEREADER_STATE_EXIT = 0,
    MMI_BARCODEREADER_STATE_PREVIEW,
    MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE,
    MMI_BARCODEREADER_STATE_OPTION_MENU,
    MMI_BARCODEREADER_STATE_ALL
} barcodereader_state_enum;

/***************************************************************************** 
* External functions
*****************************************************************************/
extern U8 PhnsetGetDefEncodingType(void);

/***************************************************************************** 
* Local variable
*****************************************************************************/

static barcodereader_context_struct g_barcodereader_cntx;

/***************************************************************************** 
* Functions declaration
*****************************************************************************/
#define MMI_BARCODEREADER_CHECK_STATE(_STATE_)            MMI_ASSERT(g_barcodereader_cntx.app_state == _STATE_);

/***************************************************************************** 
* Functions declaration
*****************************************************************************/
/* screen entry function start */
       void mmi_barcodereader_highlight_app(void);
static void mmi_barcodereader_entry_editor_screen(void);
static void mmi_barcodereader_exit_editor_screen(void);

/* preview screen , both UI scheme has preview screen */
static void mmi_barcodereader_enter_preview_screen(void);
static void mmi_barcodereader_exit_preview_screen(void);

/* init/config framework's environment */
static void mmi_barcodereader_init_camera(void);

/* screen entry function end */
static void mmi_barcodereader_enter_preview_state(void);
static void mmi_barcodereader_exit_preview_state(void);

#if !defined(__MMI_BARCODEREADER_AF_SUPPORT__)
static void mmi_barcodereader_start_capture_and_decode(void);
#endif 
static void mmi_barcodereader_enter_capture_and_decode_state(void);
static void mmi_barcodereader_exit_capture_and_decode_state(void);

static void mmi_barcodereader_preview_start(void);
static void mmi_barcodereader_preview_stop(void);
       void mmi_barcodereader_highlight_to_qrv_editor(void);
static void mmi_barcodereader_enter_qrv_editor_screen(void);
static void mmi_barcodereader_exit_qrv_editor_screen(void);

/* MISC utility functions */
static void mmi_barcodereader_preview_set_key_hdlr(void);
#ifdef __MMI_BACKGROUND_CALL__
static void mmi_barcodereader_preview_set_backgroundcall_key_hdlr(void);
#endif
static void mmi_barcodereader_capture_and_decode_set_key_hdlr(void);
static void mmi_barcodereader_exit_current_state(void);
static void mmi_barcodereader_enter_state(barcodereader_state_enum state);
static void mmi_barcodereader_preview_clear_background(void);
static BOOL mmi_barcodereader_get_storage_file_path(PS8 filepath);
static BOOL mmi_barcodereader_get_storage_disk_path(PU16 drive, PS8 drv_buf);
static void mmi_barcodereader_preview_set_blt_layer(BOOL is_previewing);
//static mmi_chset_enum mmi_barcodereader_get_encoding_type(const S8 *str);

/* resource related functions */
static void mmi_barcodereader_create_preview_resource(void);
static void mmi_barcodereader_free_preview_resource(void);

static void mmi_barcoderader_malloc_memory_and_create_adm_resource(void);
static void mmi_barcoderader_free_memory_and_destory_adm_resource(void);

static BOOL mmi_barcodereader_create_resource(void);
static void mmi_barcodereader_free_resource(void);

/* key mapping functions */
static void mmi_barcodereader_capture_button_press(void);
static void mmi_barcodereader_capture_button_release(void);

#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
static void mmi_barcodereader_af_and_capture(void);
static void mmi_barcodereader_focus_button_press(void);

#if 0
/* under construction !*/
#endif /* 0 */ 
static void mmi_barcodereader_af_mode_hotkey_press(void);
#endif /* __MMI_BARCODEREADER_AF_SUPPORT__ */ 
static void mmi_barcodereader_storage_hotkey_press(void);
static void mmi_barcodereader_storage_change(BOOL is_next);
#ifdef __MMI_BARCODEREADER_FLASH__
static void mmi_barcodereader_flash_hotkey_press(void);
#endif 

       void mmi_barcodereader_dummy_func(void);
static void mmi_barcodereader_ev_inc_key_press(void);
static void mmi_barcodereader_ev_inc_key_release(void);
static void mmi_barcodereader_ev_dec_key_press(void);
static void mmi_barcodereader_ev_dec_key_release(void);

#ifdef __MMI_BARCODEREADER_MF_SUPPORT__
static void mmi_barcodereader_mf_status_change(mmi_barcodereader_mf_status_enum status_change);
static void mmi_barcodereader_mf_status_revert(mmi_barcodereader_mf_status_enum status_change);
#endif /* __MMI_BARCODEREADER_MF_SUPPORT__ */ 
static void mmi_barcodereader_lsk_press(void);
static void mmi_barcodereader_lsk_release(void);
static void mmi_barcodereader_rsk_press(void);
static void mmi_barcodereader_rsk_release(void);
#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
#if MDI_CAMERA_MT6238_SERIES
static void mmi_barcodereader_autofocus_callback(mdi_camera_af_result_struct result);
#else
static void mmi_barcodereader_autofocus_callback(mdi_result result);
#endif
#endif

/* UI related functions */
static void mmi_barcodereader_draw_osd(void);
static void mmi_barcodereader_draw_osd_timer(void);
static void mmi_barcodereader_draw_hint(void);
static void mmi_barcodereader_draw_softkey(void);
static void mmi_barcodereader_draw_icon(void);
static void mmi_barcodereader_draw_title(void);

#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
static void mmi_barcodereader_draw_focus_process(void);
#endif 
static void mmi_barcodereader_hide_hint(void);
static void mmi_barcodereader_set_hint(PS8 hint_str1, PS8 hint_str2, U16 fade_time);
static U8 mmi_barcodereader_is_symbol_valid(int c, U8 inBracket, U8 numIndex);
static S16 mmi_barcodereader_to_lower_case(PS8 ptr);
static U8 mmi_barcodereader_check_gsm_char(PU16 ch);

/* touch screen support */
#if defined(__MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__)
static void mmi_barcodereader_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos);
static void mmi_barcodereader_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos);
static void mmi_barcodereader_touch_scr_pen_move_hdlr(mmi_pen_point_struct pos);
static BOOL mmi_barcodereader_touch_scr_hit_test(S32 pos_x, S32 pos_y, barcodereader_ui_touch_struct *touch_obj);
#endif /* defined(__MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__) */ 

#ifdef __MMI_SUBLCD__
/* sub screen */
static void mmi_barcodereader_sublcd_draw_icon(void);
#endif /* __MMI_SUBLCD__ */ 

#ifdef __MMI_HORIZONTAL_BARCODEREADER__
static void mmi_barcodereader_check_sensor_orientation(void);
static void mmi_barcodereader_check_osd_orientation(void);
#endif /* __MMI_HORIZONTAL_BARCODEREADER__ */ 

#if defined(__MMI_BARCODEREADER_FOCUS_MODE_MANUAL__)
static void mmi_barcodereader_mf_forward(void);
static void mmi_barcodereader_mf_backward(void);
static void mmi_barcodereader_mf_stop(void);
static void mmi_barcodereader_mf_forward_continue(void);
static void mmi_barcodereader_mf_backward_continue(void);
#endif /* defined(__MMI_BARCODEREADER_FOCUS_MODE_MANUAL__) */ 

static MMI_BOOL mmi_barcodereader_parse_text(void);
static void mmi_barcodereader_parser_general(void);
static void mmi_barcodereader_forward_to_apps(void);
static void mmi_barcodereader_callback(S32 selected_idx);

static void mmi_barcodereader_exit_forward_to_apps(void);

static void mmi_barcodereader_copy_from_unicode_to_unicode(U16 which, U8 *dest, S32 length);
static void mmi_barcodereader_decode_listen_timer(void);

/*******************************************************
* URL
*******************************************************/
static void mmi_barcodereader_func_save(void);
static void mmi_barcodereader_get_next_filename(PS8 file_buf_p);
static void mmi_barcodereader_save_done(void);
static void mmi_barcodereader_save_done_timeout(void);
static void mmi_barcodereader_func_exit(void);

/*******************************************************
* URL
*******************************************************/
static void mmi_barcodereader_func_save_url(void);
static void mmi_barcodereader_func_open_url(void);

/*******************************************************
* Call Management
*******************************************************/
static void mmi_barcodereader_func_make_call(void);


#if defined(__MMI_BACKGROUND_CALL__)
mmi_ret mmi_barcodereader_ucm_call_back(mmi_event_struct* ucm_data);
static U8 mmi_barcodereader_app_preview_del_scr_callback(void *ptr);
#endif 

/*******************************************************
* SMS
*******************************************************/
//static void mmi_barcodereader_send_sms_callback(void *dummy, module_type mod, U16 flag);
static void mmi_barcodereader_save_sms_callback(void *dummy, module_type mod, U16 flag);
static void mmi_barcodereader_func_save_sms(void);
static void mmi_barcodereader_func_edit_by_sms(void);
static void mmi_barcodereader_func_send_by_sms(void);

/********************************************************
* Phonebook
********************************************************/
static void mmi_barcodereader_func_save_to_phonebook(void);

/********************************************************
* MMS
********************************************************/
static void mmi_barcodereader_func_edit_by_mms(void);

/********************************************************
* ORDER
********************************************************/
static void mmi_barcodereader_func_order(void);

/******************************************************
* Highlight Handlers
*******************************************************/
       void mmi_barcodereader_hilight_save(void);
       void mmi_barcodereader_hilight_open_url(void);
       void mmi_barcodereader_hilight_make_call(void);
       void mmi_barcodereader_hilight_edit_by_sms(void);
       void mmi_barcodereader_hilight_send_by_sms(void);
       void mmi_barcodereader_hilight_exit(void);
       void mmi_barcodereader_hilight_save_url(void);
       void mmi_barcodereader_hilight_save_sms(void);
       void mmi_barcodereader_hilight_save_to_phonebook(void);
       void mmi_barcodereader_hilight_edit_by_mms(void);
       void mmi_barcodereader_hilight_order(void);

/******************************************************
* App memory related functions
*******************************************************/
static void mmi_barcodereader_app_mem_stop_callback(void);
static void mmi_barcodereader_app_mem_success_callback(void);
static void mmi_barcodereader_app_mem_success_callback_from_qrv(void);
static void mmi_barcodereader_free_adm_resource(void);
static void mmi_barcodereader_create_adm_resource(void);

static U8 mmi_barcodereader_del_scr_callback(void *ptr);
static void mmi_barcodereader_decode_result_hdlr(
                mdi_result ret,
                U8 encoding,
                U8 nsymbol,
                U8 symbolid,
                U8 paritydata,
                mdi_camera_barcode_type_enum type);
static void mmi_barcodereader_enter_tip_screen(void);
static void mmi_barcodereader_exit_tip_screen(void);

/******************************************************
* misc functions
*******************************************************/
static S16 mmi_barcodereader_get_ucs2char(S8 *buf);
static void mmi_barcodereader_store_setting(void);
static void mmi_barcodereader_load_setting(void);

/******************************************************
* watchdog functions
*******************************************************/
#ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
static void mmi_barcodereader_reset_watchdog_time_out_handler(void);
static void mmi_barcodereader_watchdog_time_out_handler(void);
#endif 

mmi_ret mmi_barcodereader_cui_event_proc(mmi_event_struct *evt);


/******************************************************
* extern functions
*******************************************************/

/***************************************************************************** 
* Functions Implementation
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_order
 * DESCRIPTION
 *  high light handler of function save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_hilight_order(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_order, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_order, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_save
 * DESCRIPTION
 *  high light handler of function save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_hilight_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_save, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_edit_by_mms
 * DESCRIPTION
 *  high light handler of function edit by mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_hilight_edit_by_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_edit_by_mms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_edit_by_mms, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_save_to_phonebook
 * DESCRIPTION
 *  high light handler of function edit by sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_hilight_save_to_phonebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_save_to_phonebook, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_save_to_phonebook, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_edit_by_sms
 * DESCRIPTION
 *  high light handler of function edit by sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_hilight_edit_by_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_edit_by_sms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_edit_by_sms, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_send_by_sms
 * DESCRIPTION
 *  high light handler of function sent by sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_hilight_send_by_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_send_by_sms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_send_by_sms, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_exit
 * DESCRIPTION
 *  high light handler of function exit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_hilight_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_exit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_exit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_save_url
 * DESCRIPTION
 *  high light handler of function make call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_hilight_save_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_save_url, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_save_url, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_save_sms
 * DESCRIPTION
 *  high light handler of function save sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_hilight_save_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_save_sms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_save_sms, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_open_url
 * DESCRIPTION
 *  high light handler of function open url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_hilight_open_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_barcodereader_func_open_url, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_open_url, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hilight_make_call
 * DESCRIPTION
 *  high light handler of function make call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_hilight_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

            SetKeyHandler(mmi_barcodereader_func_make_call, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_barcodereader_func_make_call, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_order
 * DESCRIPTION
 *  functions to send sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_order(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 buffer;
    S32 bufferSize;
    U32 length;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BARCODEREADER_ORDER_CONFIRM, NULL, mmi_barcodereader_func_order, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_ORDER_CONFIRM);

    buffer = GetString(STR_ID_BARCODEREADER_ORDER_CONFIRM);

    mmi_ucs2cpy(g_barcodereader_cntx.input_string_tmp, buffer);
    mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp, (PS8) L"\n");

    mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp, (PS8) GetString(STR_ID_BARCODEREADER_NOTIFY_SEND_TO));

    if (g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SID].str_addr != NULL)
    {
        length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_SID].length;
        mmi_barcodereader_copy_from_unicode_to_unicode(
            MMI_BARCODEREADER_ATTRIBUTE_SID,
            (U8*) g_barcodereader_cntx.working_buffer,
            length);
        mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp, (PS8) g_barcodereader_cntx.working_buffer);
        mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp, (PS8) L".");
        mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp, (PS8) L"\n");
    }

    mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp, (PS8) GetString(STR_ID_BARCODEREADER_NOTIFY_CONTENT));
    if (g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_DG].str_addr != NULL)
    {
        length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_DG].length;
        mmi_barcodereader_copy_from_unicode_to_unicode(
            MMI_BARCODEREADER_ATTRIBUTE_DG,
            (U8*) g_barcodereader_cntx.working_buffer,
            length);
        mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp, (PS8) g_barcodereader_cntx.working_buffer);
        mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp, (PS8) L".");
        mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp, (PS8) L"\n");
    }

    bufferSize = mmi_ucs2strlen(g_barcodereader_cntx.input_string_tmp);

    ShowCategory74Screen(
        STR_ID_BARCODEREADER_ORDER_ATTENTION,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) g_barcodereader_cntx.input_string_tmp,
        bufferSize,
        NULL);
    SetKeyHandler(mmi_barcodereader_func_send_by_sms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_func_send_by_sms, KEY_EVENT_UP);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_edit_by_mms
 * DESCRIPTION
 *  functions to save to phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_edit_by_mms(void)
{
#ifdef MMS_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *src;
    U16 *dest;
    S32 length = 0;
    U16 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);
    src = (U16*) & g_barcodereader_cntx.formatted_text_buf[0];
    dest = (U16*) & g_barcodereader_cntx.input_string[0];
    for (idx = 0; idx < length; idx++)
    {
        *dest++ = *src++;
    }
    *dest = 0;

    mmi_ucs2_to_asc((PS8) g_barcodereader_cntx.input_string_tmp, (PS8) g_barcodereader_cntx.input_string);
    mms_text_insert_hdlr("", 0, (char*)g_barcodereader_cntx.input_string, (unsigned int)length);
#endif /* MMS_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_save_to_phonebook
 * DESCRIPTION
 *  functions to save to phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_save_to_phonebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *src;
    U16 *dest;
    S32 length;
    U16 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.selected_app_type != MMI_BARCODEREADER_APP_VCARD)
    {
        /* only phone number information */
        length = g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].length;
        src = (U16*) g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].str_addr;
        dest = (U16*) g_barcodereader_cntx.input_string;

        for (idx = 0; idx < length * ENCODING_LENGTH; idx += ENCODING_LENGTH)
        {
            if (((U16) '0' <= *src && *src <= (U16) '9') || *src == (U16) 'p' || *src == (U16) 'w' || *src == (U16) '+' ||
                *src == (U16) '*' || *src == (U16) '#')
            {
                *dest++ = *src;
            }

            src++;
        }

        *dest = 0;
        mmi_ucs2_to_asc((PS8) g_barcodereader_cntx.input_string_tmp, (PS8) g_barcodereader_cntx.input_string);
    
  /** 
    * If caller app not support Screen Group(SG), it has to entry new SG for using CUI, 
    * but no any screen based on it.
    * 
    * 1. Caller can use app id as SG id, or define SG id in app resource file
    * 2. The fourth params is user_data, caller can keep some data in it
    */

    if(mmi_frm_group_is_present(APP_BARCODEREADER))
    {
        mmi_frm_group_close(APP_BARCODEREADER);
    }

    mmi_frm_group_create(GRP_ID_ROOT, APP_BARCODEREADER, mmi_barcodereader_cui_event_proc, NULL);
    mmi_frm_group_enter(APP_BARCODEREADER, MMI_FRM_NODE_SMART_CLOSE_FLAG);

//  mmi_frm_group_entry_ex(GRP_ID_ROOT, APP_BARCODEREADER, mmi_barcodereader_cui_event_proc, NULL, NULL);

/** 
  * Caller should keep the CUI group id, because all operation about CUI depends on it
  */
      g_barcodereader_cntx.save_number_cui_id = cui_phb_save_contact_create(APP_BARCODEREADER);

      if(g_barcodereader_cntx.save_number_cui_id != GRP_ID_INVALID)
      {
          cui_phb_save_contact_set_number(g_barcodereader_cntx.save_number_cui_id, (U16*)g_barcodereader_cntx.input_string);

          cui_phb_save_contact_set_need_popup(g_barcodereader_cntx.save_number_cui_id, MMI_TRUE);

          cui_phb_save_contact_run(g_barcodereader_cntx.save_number_cui_id);
      }
      else
      {
            mmi_frm_group_close(APP_BARCODEREADER);
      }
        
    }
    else
    {
        g_barcodereader_cntx.last_error.error_result = MMI_BARCODEREADER_ERROR_COMMON;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;
        g_barcodereader_cntx.last_error.tone_id = ERROR_TONE;
        mmi_barcodereader_display_error_popup(
            g_barcodereader_cntx.last_error.error_result,
            g_barcodereader_cntx.last_error.error_type,
            g_barcodereader_cntx.last_error.tone_id);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_save_sms
 * DESCRIPTION
 *  functions to save sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_save_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    mmi_frm_sms_send_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));
    S32 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));

    length = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);

//    if (length > MMI_BARCODEREADER_MAX_SMS_CONTENT)
//        length = MMI_BARCODEREADER_MAX_SMS_CONTENT;

    if(mmi_frm_group_is_present(APP_BARCODEREADER))
    {
        mmi_frm_group_close(APP_BARCODEREADER);
    }

    mmi_frm_group_create(GRP_ID_ROOT, APP_BARCODEREADER, mmi_barcodereader_cui_event_proc, NULL);
    mmi_frm_group_enter(APP_BARCODEREADER, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_barcodereader_cntx.sms_cui_id = cui_sms_save_create(APP_BARCODEREADER);

    if(g_barcodereader_cntx.sms_cui_id != GRP_ID_INVALID)
    {

        cui_sms_set_save_content_text(g_barcodereader_cntx.sms_cui_id, (U16*)g_barcodereader_cntx.formatted_text_buf, length*2);

        cui_sms_save_run(g_barcodereader_cntx.sms_cui_id);

    }
    else
    {
        mmi_frm_group_close(APP_BARCODEREADER);
    }
//    mmi_frm_sms_save_sms_for_other_app(mmi_barcodereader_save_sms_callback, MOD_MMI, sendData);
//    OslMfree(sendData);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_edit_by_sms
 * DESCRIPTION
 *  functions to edit sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_edit_by_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_write_msg_para_struct *sendData;
    S32 length;
    U16 *src;

// #define MMI_BARCDEREADER_SMS_SM_LENGTH 20       /* current sms only supoort 20 character count number */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_api_entry_write_struct));

    sendData = mmi_malloc(sizeof(mmi_sms_write_msg_para_struct));
    memset((S8*) sendData, 0, sizeof(mmi_sms_write_msg_para_struct));


    length = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);

    if (length > MMI_BARCODEREADER_MAX_SMS_CONTENT)
        length = MMI_BARCODEREADER_MAX_SMS_CONTENT;

    src = (U16*) & g_barcodereader_cntx.formatted_text_buf[0];

    sendData->string = mmi_malloc((length + 1) * ENCODING_LENGTH);
    memset(sendData->string, 0, ((length + 1) * ENCODING_LENGTH));

    sendData->dcs = SRV_SMS_DCS_UCS2;
    mmi_ucs2ncpy((PS8) sendData->string, (PS8) src, length);
    sendData->stringlength = length;
    
    mmi_sms_write_msg_lanch(0, sendData);

    if (sendData)
    {
        if (sendData->string)
        {
            mmi_mfree(sendData->string);
        }
        mmi_mfree(sendData);
    }
//    mmi_frm_sms_api_entry_write_msg(sendData);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_send_by_sms
 * DESCRIPTION
 *  functions to send sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_send_by_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 length = 0;
    U16 *src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.total_receiver = 1;

    length = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);

//    if (length > MMI_BARCODEREADER_MAX_SMS_CONTENT)
//        length = MMI_BARCODEREADER_MAX_SMS_CONTENT;

//    mmi_ucs2ncpy((PS8)sms_content, (PS8) src, length);
    
    if(mmi_frm_group_is_present(APP_BARCODEREADER))
    {
        mmi_frm_group_close(APP_BARCODEREADER);
    }

    mmi_frm_group_create(GRP_ID_ROOT, APP_BARCODEREADER, mmi_barcodereader_cui_event_proc, NULL);
    mmi_frm_group_enter(APP_BARCODEREADER, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_barcodereader_cntx.sms_cui_id = cui_sms_send_create(APP_BARCODEREADER);

    if(g_barcodereader_cntx.sms_cui_id != GRP_ID_INVALID)
    {

        cui_sms_set_send_content_text(g_barcodereader_cntx.sms_cui_id, (U16*)g_barcodereader_cntx.formatted_text_buf, length*2);

        cui_sms_send_run(g_barcodereader_cntx.sms_cui_id);

    }
    else
    {
        mmi_frm_group_close(APP_BARCODEREADER);
    }
    /* mmi_frm_sms_api_entry_write_msg(&sendData); */
//    mmi_frm_sms_send_sms_for_other_app(mmi_barcodereader_send_sms_callback, MOD_MMI, sendData);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_make_call
 * DESCRIPTION
 *  functions to ooxx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *src, *dest;
    S32 length;
    U16 idx = 0;
    mmi_ucm_make_call_para_struct make_call_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].length;
    src = g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].str_addr;
    dest = g_barcodereader_cntx.input_string;
    
    for (idx = 0; idx < length * ENCODING_LENGTH; idx += ENCODING_LENGTH)
    {
        if (((U16) '0' <= *src && *src <= (U16) '9') || *src == (U16) 'p' || *src == (U16) 'w' || (*src == (U16) '+' && idx == 0) ||
            *src == (U16) '*' || *src == (U16) '#')
        {
            *dest = *src;
            dest += 2;
        }

        src += 2;
    }
    *dest = 0;
    *(dest+1) = 0;

#ifdef __MMI_UCM__
    mmi_ucm_init_call_para(&make_call_para);  
    make_call_para.adv_para.after_make_call_callback = NULL;
    make_call_para.ucs2_num_uri = (U16*)g_barcodereader_cntx.input_string;
    mmi_ucm_call_launch(0, &make_call_para);

#else
    MakeCall((PS8) g_barcodereader_cntx.input_string);
#endif
}




/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_save_url
 * DESCRIPTION
 *  send save url request to wap task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_save_url(void)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length;
    S16 url_addr[(MMI_BARCODEREADER_MAX_URL_LEN + 1) * 2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.selected_app_type == MMI_BARCODEREADER_APP_BUSINESS)
    {
        length = g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_URL].length;
        if (length > MMI_BARCODEREADER_MAX_URL_LEN)
        {
            length = MMI_BARCODEREADER_MAX_URL_LEN;
        }
        mmi_ucs2ncpy(
            (PS8) url_addr,
            g_barcodereader_cntx.app_content.ct_element[MMI_BARCODEREADER_ATTRIBUTE_URL].str_addr,
            length);
    }
    else
    {
        length = g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].length;
        if (length > MMI_BARCODEREADER_MAX_URL_LEN)
            length = MMI_BARCODEREADER_MAX_URL_LEN;

        mmi_ucs2ncpy(
            (PS8) url_addr,
            g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].str_addr,
            length);
    }

    wap_start_browser(WAP_BROWSER_ADD_BOOKMARK, (PU8) url_addr);
#endif /* WAP_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_open_url
 * DESCRIPTION
 *  send open url request to wap task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_open_url(void)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 src;
    PU8 dest;
    U16 idx = 0;
    S32 length;
    S16 url_addr[(MMI_BARCODEREADER_MAX_URL_LEN + 1) * 2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length =
        g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].length * ENCODING_LENGTH;
    if (length >= MMI_BARCODEREADER_MAX_URL_LEN * ENCODING_LENGTH)
        length = (MMI_BARCODEREADER_MAX_URL_LEN - 1) * ENCODING_LENGTH;

    src = (PU8) g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.selected_hilight_idx].str_addr;
    dest = (PU8) & url_addr[0];
    for (idx = 0; idx < length; idx++)
    {
        *dest++ = *src++;
    }
    *dest = 0;
    *(dest + 1) = 0;
    wap_start_browser(WAP_BROWSER_GOTO_URL, (PU8) url_addr);
#endif /* WAP_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_save_done
 * DESCRIPTION
 *  functions to ooxx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_save_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear all keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    mmi_display_popupcallback(
        (UI_string_type) GetString(STR_GLOBAL_SAVED), 
        (mmi_event_notify_enum) MMI_EVENT_SUCCESS,
        mmi_barcodereader_save_done_timeout);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_save_done_timeout
 * DESCRIPTION
 *  functions to ooxx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_save_done_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* DeleteNHistory(1); */
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_save
 * DESCRIPTION
 *  functions to ooxx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    U32 written;
    FS_HANDLE file_handle;
    S32 create_result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* blt base only */
    gdi_layer_set_blt_layer(g_barcodereader_cntx.base_layer_handle, 0, 0, 0);

    //gdi_layer_lock_frame_buffer();

    /* show popup category */
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    force_no_small_screen();
#endif 

    EntryNewScreen(SCR_ID_BARCODEREADER_SAVE, NULL, NULL, NULL);
    ShowCategory65Screen((PU8) GetString(STR_GLOBAL_SAVING), mmi_get_event_based_image(MMI_EVENT_PROGRESS), NULL);
    g_barcodereader_cntx.is_cat65_show = TRUE;

    //gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);

    mmi_barcodereader_get_storage_file_path((PS8) buf_filename);
    create_result = mmi_barcodereader_create_file_dir((PS8) buf_filename);
    
    if (create_result < FS_NO_ERROR)
    {
        g_barcodereader_cntx.last_error.error_result = create_result;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;
        g_barcodereader_cntx.last_error.tone_id = ERROR_TONE;
        
        if (g_barcodereader_cntx.is_cat65_show)
        {
            g_barcodereader_cntx.is_cat65_show = FALSE;
            //ExitCategoryFunction();
        }

        mmi_barcodereader_display_error_popup(
            g_barcodereader_cntx.last_error.error_result,
            g_barcodereader_cntx.last_error.error_type,
            g_barcodereader_cntx.last_error.tone_id);
        
        return;
    }

    mmi_barcodereader_get_next_filename(buf_filename);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_SAVE_FILE_PATH, buf_filename);

    file_handle = FS_Open((U16*) buf_filename, FS_CREATE | FS_READ_WRITE);

    if (file_handle >= FS_NO_ERROR)
    {
        S32 string_buffer_size = mmi_ucs2strlen(g_barcodereader_cntx.text_buf) * ENCODING_LENGTH;
        U8 file_header[2] = {0xFE, 0xff};
        FS_Write(file_handle, (void*)file_header, 2, (U32*) & written);
        FS_Write(file_handle, (void*)g_barcodereader_cntx.text_buf, string_buffer_size, (U32*) & written);
        FS_Close(file_handle);
        /* should fmgr support to search hidden file */
        /* FS_SetAttributes((WCHAR*)buf_filename,FS_ATTR_HIDDEN); */

        /* cant write in whole file, must be disk full */
        if (string_buffer_size != written)
        {
            /* delete the file that is not save complete */
            FS_Delete((U16*) buf_filename);

            g_barcodereader_cntx.last_error.error_result = FS_DISK_FULL;
            g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;
            g_barcodereader_cntx.last_error.tone_id = ERROR_TONE;
            if (g_barcodereader_cntx.is_cat65_show)
            {
                g_barcodereader_cntx.is_cat65_show = FALSE;
                //ExitCategoryFunction();
            }

            /* will display a popup, go out application and re-enter */
            mmi_barcodereader_display_error_popup(
                g_barcodereader_cntx.last_error.error_result,
                g_barcodereader_cntx.last_error.error_type,
                g_barcodereader_cntx.last_error.tone_id);
            return;
        }
    }
    else
    {
        g_barcodereader_cntx.last_error.error_result = file_handle;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_FS;
        g_barcodereader_cntx.last_error.tone_id = ERROR_TONE;

        if (g_barcodereader_cntx.is_cat65_show)
        {
            g_barcodereader_cntx.is_cat65_show = FALSE;
            //ExitCategoryFunction();
        }

        /* will display a popup, go out application and re-enter */
        mmi_barcodereader_display_error_popup(
            g_barcodereader_cntx.last_error.error_result,
            g_barcodereader_cntx.last_error.error_type,
            g_barcodereader_cntx.last_error.tone_id);
        return;
    }

    if (g_barcodereader_cntx.is_cat65_show)
    {
        g_barcodereader_cntx.is_cat65_show = FALSE;
        //ExitCategoryFunction();
    }
    mmi_barcodereader_save_done();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_get_next_filename
 * DESCRIPTION
 *  get next file name for QRcode decoded text
 * PARAMETERS
 *  file_buf_p      [IN]        
 *  a(?)            [OUT]       Next filename(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_get_next_filename(PS8 file_buf_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buffer[14];
    U16 path[50];
    S8  temp_path[60];
    MYTIME currentDateTime, inc_time, result_time;
    FS_HANDLE handle = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get/store sequentail number */
    switch (g_barcodereader_cntx.selected_app_type)
    {
        case MMI_BARCODEREADER_APP_VCARD:
            sprintf((PS8) buffer, "%s", MMI_BARCODEREADER_FILE_NAME_VCARD);
            break;

        case MMI_BARCODEREADER_APP_BUSINESS:
            sprintf((PS8) buffer, "%s", MMI_BARCODEREADER_FILE_NAME_BUSINESS);

        case MMI_BARCODEREADER_APP_EMAIL:
            sprintf((PS8) buffer, "%s", MMI_BARCODEREADER_FILE_NAME_EMAIL);
            break;

        case MMI_BARCODEREADER_APP_SMS:
            sprintf((PS8) buffer, "%s", MMI_BARCODEREADER_FILE_NAME_SMS);
            break;

        case MMI_BARCODEREADER_APP_DTXT:
            sprintf((PS8) buffer, "%s", MMI_BARCODEREADER_FILE_NAME_DTXT);
            break;

        default:
            sprintf((PS8) buffer, "%s", "");
            break;
    }

    mmi_asc_to_ucs2((PS8) temp_path, (PS8) buffer);

    GetDateTime(&currentDateTime);

    kal_wsprintf(
        path,
        "%02d%02d%02d_%02d%02d%02d",
        currentDateTime.nYear,
        currentDateTime.nMonth,
        currentDateTime.nDay,
        currentDateTime.nHour,
        currentDateTime.nMin,
        currentDateTime.nSec);
    mmi_ucs2cat((PS8) temp_path, (PS8) path);
    mmi_ucs2cat((PS8) temp_path, (PS8) MMI_BARCODEREADER_FILE_EXT_NAME);
    mmi_barcodereader_get_storage_file_path((PS8) path);

    mmi_ucs2cat((PS8) path, (PS8) temp_path);
    handle = FS_Open(path, FS_READ_ONLY);
    memset(&inc_time, 0, sizeof(MYTIME));
    inc_time.nSec = 1;
    while (handle >= FS_NO_ERROR)
    {
        FS_Close(handle);
        IncrementTime(currentDateTime, inc_time, &result_time);
        memcpy(&currentDateTime,&result_time,sizeof(MYTIME));
        mmi_asc_to_ucs2((PS8) temp_path, (PS8) buffer);
        kal_wsprintf(
            path,
            "%02d%02d%02d_%02d%02d%02d",
            result_time.nYear,
            result_time.nMonth,
            result_time.nDay,
            result_time.nHour,
            result_time.nMin,
            result_time.nSec);
        mmi_ucs2cat((PS8) temp_path, (PS8) path);
        mmi_ucs2cat((PS8) temp_path, (PS8) MMI_BARCODEREADER_FILE_EXT_NAME);
        mmi_barcodereader_get_storage_file_path((PS8) path);
        mmi_ucs2cat((PS8) path, (PS8) temp_path);
        handle = FS_Open(path, FS_READ_ONLY);
    }
    if (handle >= FS_NO_ERROR)
    {
        FS_Close(handle);
    }

    mmi_ucs2cpy(file_buf_p, (S8*) path);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
 *  mmi_barcodereader_exit_forward_to_apps
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_exit_forward_to_apps(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free buffer */
    gui_free(g_barcodereader_cntx.storage_filepath);
    g_barcodereader_cntx.storage_filepath = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_forward_to_apps
 * DESCRIPTION
 *  forward selected content to applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_forward_to_apps(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;
    U16 menu_id = 0;
    U16 title_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.app_list_idx_count == 0)
        g_barcodereader_cntx.selected_app_type = MMI_BARCODEREADER_NONE;
    else
        g_barcodereader_cntx.selected_app_type =
            g_barcodereader_cntx.app_type_list[g_barcodereader_cntx.selected_hilight_idx];
    switch (g_barcodereader_cntx.selected_app_type)
    {
        case MMI_BARCODEREADER_APP_VCARD:
        case MMI_BARCODEREADER_APP_BUSINESS:
        case MMI_BARCODEREADER_APP_SMS:
        case MMI_BARCODEREADER_APP_EMAIL:
        case MMI_BARCODEREADER_APP_DTXT:
            break;

        case MMI_BARCODEREADER_APP_PHONENUMBER:
            menu_id = MENU_ID_BARCODEREADER_APP_TO_GENERAL;
            title_id = STR_ID_BARCODEREADER_TO_GENERAL;
            mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_URL);
            mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_OPEN_URL);
            mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK);
            if (mmi_barcodereader_is_network_permit(MMI_TRUE))
            {

                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_MAKE_CALL);
                if (mmi_barcodereader_is_network_permit(MMI_FALSE))
                {
                    mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                    mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                    mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
                #ifdef MMS_SUPPORT
                    if (mms_is_ready())
                    {
                        mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
                    }
                    else
                    {
                        mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
                    }
                #else 
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
                #endif 
                }
                else
                {
                #ifndef __MMI_VOIP__
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_MAKE_CALL);
                #endif
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
                }
            }
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_MAKE_CALL);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
            }
            break;

        case MMI_BARCODEREADER_APP_URL:
            menu_id = MENU_ID_BARCODEREADER_APP_TO_GENERAL;
            title_id = STR_ID_BARCODEREADER_TO_GENERAL;
            if (mmi_barcodereader_is_network_permit(MMI_TRUE))
            {
            #ifdef WAP_SUPPORT
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_URL);
            #else 
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_URL);
            #endif 
            #ifdef WAP_SUPPORT
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_OPEN_URL);
            #else 
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_OPEN_URL);
            #endif 
                if (mmi_barcodereader_is_network_permit(MMI_FALSE))
                {
                    mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                    mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                    mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
                #ifdef MMS_SUPPORT
                    if (mms_is_ready())
                    {
                        mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
                    }
                    else
                    {
                        mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
                    }
                #else 
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
                #endif 
                }
                else
                {
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
                }
            }
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_URL);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_OPEN_URL);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
            }
            mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK);
            mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_MAKE_CALL);
            break;
            
        case MMI_BARCODEREADER_APP_EMAILADDRESS:
        case MMI_BARCODEREADER_NONE:
            menu_id = MENU_ID_BARCODEREADER_APP_TO_GENERAL;
            title_id = STR_ID_BARCODEREADER_TO_GENERAL;
            if (mmi_barcodereader_is_network_permit(MMI_FALSE))
            {
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
            #ifdef MMS_SUPPORT
                if (mms_is_ready())
                {
                    mmi_frm_unhide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
                }
                else
                {
                    mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
                }
            #else 
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
            #endif 
            }
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SEND_BY_SMS);
                mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_EDIT_BY_MMS);
            }
            mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_URL);
            mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_OPEN_URL);
            mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK);
            mmi_frm_hide_menu_item(MENU_ID_BARCODEREADER_FUNC_MAKE_CALL);
            break;
        default:
            ASSERT(0);
            break;
    }

    EntryNewScreen(
        SCR_ID_BARCODEREADER_APP_PREVIEW_OPTION,
        mmi_barcodereader_exit_forward_to_apps,
        mmi_barcodereader_forward_to_apps,
        NULL);

    /* allocate storage path buffer */
    g_barcodereader_cntx.storage_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
    memset(g_barcodereader_cntx.storage_filepath, 0, FMGR_PATH_BUFFER_SIZE);

    mmi_barcodereader_get_storage_file_path((PS8) g_barcodereader_cntx.storage_filepath);

    /* ENTRY CATEGORY SCREEN */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_APP_PREVIEW_OPTION);
    nItems = GetNumOfChild_Ext(menu_id);
    GetSequenceStringIds_Ext(menu_id, ItemList);
    GetSequenceImageIds_Ext(menu_id, ItemIcons);
    SetParentHandler(menu_id);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
    }

    ConstructHintsList(menu_id, PopUpList);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (PU16) gIndexIconsImageList,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_is_symbol_valid
 * DESCRIPTION
 *  Check if symbol is valid to insert use number
 * PARAMETERS
 *  c               [IN]        Current use number record length
 *  inBracket       [IN]        
 *  numIndex        [IN]        
 *  a(?)            [IN]        Input character(?)(?)
 *  b(?)            [IN]        Bracket waiting flag(?)(?)
 * RETURNS
 *  1: symbol is valid, 0: symbol is not valid
 *****************************************************************************/
static U8 mmi_barcodereader_is_symbol_valid(int c, U8 inBracket, U8 numIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 status = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_BARCODEREADER_IS_NUM(c))
    {
        return 1;
    }

    switch (c)
    {
        case '+':
            if (numIndex == 1)
            {
                status = 1;
            }
            break;
        case '(':
            status = 1;
            break;
        case ')':
            if (inBracket)
            {
                status = 1;
            }
            break;
        case 'p':
        case 'w':
        case '-':
            if (numIndex >= MMI_BARCODEREADER_USE_NUM_MIN_LENGTH)
            {
                status = 1;
            }
            break;
        default:
            status = 0;
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_to_lower_case
 * DESCRIPTION
 *  Convert ascii upper case character to unicode lower case
 * PARAMETERS
 *  ptr     [IN]        
 *  a(?)        [IN]        Ptr   a pointer points to an ascii character(?)(?)
 * RETURNS
 *  a pointer points to an unicode character
 *****************************************************************************/
static S16 mmi_barcodereader_to_lower_case(PS8 ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 two_byte_A = 0x0041;
    S16 two_byte_Z = 0x005A;
    S16 unicode_lower;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*((S16*) ptr) >= two_byte_A && *((S16*) ptr) <= two_byte_Z)
    {
        unicode_lower = (S16) ('a' + (*ptr) - 'A');
    }
    else
    {
        unicode_lower = *((S16*) (ptr));
    }
    return unicode_lower;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_check_gsm_char
 * DESCRIPTION
 *  Check if it is a gsm character
 * PARAMETERS
 *  ch      [IN]        
 *  a(?)        [IN]        Char(?)(?)
 * RETURNS
 *  TRUE if it is a gsm character; FALSE otherwise
 *****************************************************************************/
static U8 mmi_barcodereader_check_gsm_char(PU16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ascii_min = 0x0000;
    U16 ascii_max = 0x007f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*ch >= ascii_min && *ch <= ascii_max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_parse_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_barcodereader_parse_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.app_list_idx = 0;
    g_barcodereader_cntx.app_list_idx_count = 0;
    g_barcodereader_cntx.selected_app_type = MMI_BARCODEREADER_NONE;
    result = MMI_FALSE;

    mmi_barcodereader_parser_general();

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_unicode_to_ascii
 * DESCRIPTION
 *  Converts Unicode encode string to Ascii
 *  
 *  Caller has to ensure that pOutBuffer
 *  should be  large enough
 * PARAMETERS
 *  pOutBuffer      [?]     [?]     [?]
 *  pInBuffer       [?]     [?]     [?]
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_barcodereader_unicode_to_ascii(S8 *pOutBuffer, S8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!((*pInBuffer == 0) && (*(pInBuffer + 1) == 0)))
    {

        *pOutBuffer = *(pInBuffer);

        /* check if 0x003b or not */
        if ((*pOutBuffer) == ';' && (*(pInBuffer + 1) != 0))
            *pOutBuffer = (char)0xee;

        pInBuffer += 2;
        pOutBuffer++;
        count++;
    }

    *pOutBuffer = 0;
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_parser_general
 * DESCRIPTION
 *  app menu item hilight hdlr
 * PARAMETERS
 *  void
 *  PS8(?)      [OUT]       P_out_text(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_parser_general(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    S8 Pattern[MMI_BARCODEREADER_MAX_LEN_URL_PATTERN * ENCODING_LENGTH];
    kal_bool valid_http_prefix = KAL_TRUE;
    U16 idx, start_idx, current_idx, seek_idx;
    BOOL is_url = TRUE;
    BOOL is_number = FALSE;
    int digit_c, digit_c_first;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1. translate to UCS2 String */
    /* mmi_asc_to_ucs2(g_barcodereader_cntx.formatted_text_buf, g_barcodereader_cntx.text_buf); */
    mmi_ucs2cpy(g_barcodereader_cntx.formatted_text_buf, g_barcodereader_cntx.text_buf);
    g_barcodereader_cntx.formatted_text_buf_length = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);

    /* 2. if Not, check if contain URL or Number or email */
    idx = 0;
    start_idx = idx;
    current_idx = idx;
    seek_idx = idx;

    while (mmi_ucs2cmp((S8*) & g_barcodereader_cntx.formatted_text_buf[idx], "\0"))
    {
        is_url = FALSE;
        for (i = 0; i < MMI_BARCODEREADER_MAX_NUM_URL_PATTERN && is_url == FALSE; i++)
        {
            mmi_asc_to_ucs2(Pattern, mmi_barcode_urlPattern[i]);
            /* search the pattern in the MsgTxt */

            if (mmi_ucs2ncmp
                ((S8*) & g_barcodereader_cntx.formatted_text_buf[idx], Pattern, mmi_barcode_urlPattern_length[i]) == 0)
            {
                is_url = TRUE;
            }
            /* select the minimum one, i.e. http://www.mtk.com "http://" will be selected instead of "www." */
            if (is_url == TRUE)
            {

                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_PARSER_1_URL_PATTERN_MATCH, mmi_barcode_urlPattern[i]);
                /* Determine if the http prefix is valid. For example, "http:##" is not valid. */
                if ((strncmp(mmi_barcode_urlPattern[i], "http", 4)) == 0)
                {
                    int j = 0;
                    S16 http_prefix[MMI_BARCODEREADER_MAX_LEN_URL_PATTERN];
                    S16 http_prefix_in_msg[MMI_BARCODEREADER_MAX_LEN_URL_PATTERN];
                    S16 tmp_c;
                    int k = 0;

                    for (; j < MMI_BARCODEREADER_MAX_NUM_VALID_HTTP_PREFIX; j++)
                    {
                        int http_prefix_len = strlen((S8*) mmi_barcode_urlValidHttpPrefix[j]);

                        mmi_asc_n_to_ucs2((S8*) http_prefix, mmi_barcode_urlValidHttpPrefix[j], http_prefix_len);
                        mmi_ucs2ncpy(
                            (S8*) http_prefix_in_msg,
                            (S8*) & g_barcodereader_cntx.formatted_text_buf[idx],
                            http_prefix_len);
                        http_prefix_in_msg[http_prefix_len] = 0;

                        for (; k < http_prefix_len; k++)
                        {
                            tmp_c = mmi_barcodereader_to_lower_case((PS8) & http_prefix_in_msg[k]);
                            http_prefix_in_msg[k] = tmp_c;
                        }
                        if (mmi_ucs2ncmp((S8*) http_prefix_in_msg, (S8*) http_prefix, http_prefix_len) == 0)
                        {
                            break;
                        }
                    }

                    if (j == MMI_BARCODEREADER_MAX_NUM_VALID_HTTP_PREFIX)
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_PARSER_1_URL_PATTERN_INVALID);
                        valid_http_prefix = KAL_FALSE;
                    }
                    else
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_PARSER_1_URL_PATTERN_VALID);
                    }
                }
                else
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_PARSER_1_URL_PATTERN_VALID);
                    valid_http_prefix = KAL_TRUE;
                }
                start_idx = current_idx = idx;

                if (valid_http_prefix)
                {
                /* get one url until 0x20, 0x0d, 0x0a, 0x00 */
                while (mmi_ucs2ncmp((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx], " ", 1) &&
                       mmi_ucs2ncmp((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx], "\r", 1) &&
                       mmi_ucs2ncmp((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx], "\n", 1) &&
                       mmi_ucs2ncmp((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx], "\0", 1) &&
                       mmi_ucs2ncmp((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx], ",", 1) &&
                       mmi_ucs2ncmp((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx], "(", 1) &&
                       mmi_ucs2ncmp((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx], ")", 1) &&
                       mmi_ucs2ncmp((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx], (S8*)L"..", 2) &&
                       mmi_ucs2ncmp((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx], ";", 1))
                {
                    /* must reserve two bytes for null terminator */
                    if (mmi_barcodereader_check_gsm_char((PU16) & g_barcodereader_cntx.formatted_text_buf[current_idx]))
                    {
                        /* skip extension character 0x1b */
                        current_idx += ENCODING_LENGTH;
                    }
                    else
                    {
                        break;
                    }
                }
                }
                else
                {
                    current_idx += ENCODING_LENGTH;
                }

                if (valid_http_prefix && g_barcodereader_cntx.app_list_idx < MMI_BARCODEREADER_APPLIACTION_LIST_NUM)
                {
                    g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.app_list_idx].length =
                        (current_idx - start_idx) / ENCODING_LENGTH;
                    g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.app_list_idx].str_addr =
                        (PS8) & g_barcodereader_cntx.formatted_text_buf[start_idx];
                    g_barcodereader_cntx.app_type_list[g_barcodereader_cntx.app_list_idx] = MMI_BARCODEREADER_APP_URL;
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_PARSER_1_SOURCE_DATA,
                                         g_barcodereader_cntx.app_list_idx,
                                         g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.app_list_idx].
                                         length,
                                         (int)(g_barcodereader_cntx.app_content.
                                               ct_element[g_barcodereader_cntx.app_list_idx].str_addr));
                    g_barcodereader_cntx.app_list_idx++;
                }

                idx = current_idx;
            }

        }   /* end of checking pattern "http" "www." "wap." */

        valid_http_prefix = KAL_TRUE;

      /*********************************************************************
      * Check Number
      *********************************************************************/
        if (is_url == FALSE)
        {
            int pickNow = 0;
            U8 inBracket = 0;
            U8 non_digit_count = 0;
            U16 digit_count = 1;

            start_idx = idx;
            current_idx = idx;
            digit_c_first = mmi_barcodereader_get_ucs2char((S8*) & g_barcodereader_cntx.formatted_text_buf[start_idx]);

            do
            {
                digit_c = mmi_barcodereader_get_ucs2char((S8*) & g_barcodereader_cntx.formatted_text_buf[current_idx]);

                if (mmi_barcodereader_is_symbol_valid(digit_c, inBracket, (U8) digit_count) &&
                    (((digit_c_first == '+') && (digit_count - 1 < MMI_BARCODEREADER_MAX_DIGITS + 1)) || 
                     (digit_c_first != '+') && (digit_count - 1 < MMI_BARCODEREADER_MAX_DIGITS)))
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_PARSER_2_VALID_SYMBOL, digit_c);
                    if ((digit_c != '-') && (digit_c != '(') && (digit_c != ')'))
                    {
                        non_digit_count++;
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_PARSER_2_DIGIT_COUNT, digit_count);
                        digit_count++;
                    }

                    if (digit_c == '(')
                    {
                        inBracket++;
                    }
                    else if ((digit_c == ')') && inBracket)
                    {
                        inBracket--;
                    }
                }
                else
                {
                    /* Nth digit_c is an invalid symbol */
                    if (digit_count > 1 && ((current_idx / 2) < g_barcodereader_cntx.formatted_text_buf_length))
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_PARSER_2_INVALID_SYMBOL_PICK, digit_c);
                        current_idx -= ENCODING_LENGTH;
                        pickNow = 1;
                    }
                    else
                    {
                        if (non_digit_count > 0)
                        {
                            current_idx -= ENCODING_LENGTH;
                        }
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_PARSER_2_INVALID_SYMBOL_NOT_PIC, digit_c);
                        is_number = FALSE;
                        break;
                    }
                }

                if ((current_idx / 2) + 1 >= g_barcodereader_cntx.formatted_text_buf_length)
                {
                    pickNow = 1;
                }

                if (pickNow)
                {

                    pickNow = 0;
                    if ((g_barcodereader_cntx.formatted_text_buf[current_idx] == 'w') ||
                        (g_barcodereader_cntx.formatted_text_buf[current_idx] == 'p'))
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_PARSER_2_LAST_SYMBOL);
                        current_idx -= ENCODING_LENGTH;
                    }
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_PARSER_2_DIGIT_COUNT_WHEN_PICK,digit_count);
                    if (digit_count >= 4 && g_barcodereader_cntx.app_list_idx < MMI_BARCODEREADER_APPLIACTION_LIST_NUM)
                    {
                        g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.app_list_idx].length = (current_idx - start_idx + ENCODING_LENGTH) / 2;        /* + ENCODING_LENGTH; */
                        g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.app_list_idx].str_addr =
                            (PS8) & g_barcodereader_cntx.formatted_text_buf[start_idx];
                        g_barcodereader_cntx.app_type_list[g_barcodereader_cntx.app_list_idx] =
                            MMI_BARCODEREADER_APP_PHONENUMBER;
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_PARSER_2_SOURCE_DATA,
                                             g_barcodereader_cntx.app_list_idx,
                                             g_barcodereader_cntx.app_content.ct_element[g_barcodereader_cntx.
                                                                                         app_list_idx].length,
                                             (int)(g_barcodereader_cntx.app_content.
                                                   ct_element[g_barcodereader_cntx.app_list_idx].str_addr));
                        g_barcodereader_cntx.app_list_idx++;
                        is_number = TRUE;
                        break;
                    }
                    else
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_PARSER_2_NOT_NUMBER);
                        is_number = FALSE;
                        break;
                    }
                }
                else
                {
                    current_idx += ENCODING_LENGTH;
                }

            } while (1);

            idx = current_idx;

        }

      /*********************************************************************
      * Email address
      *********************************************************************/
        if (is_url == FALSE && is_number == FALSE)
        {

        }
        /* check next character */
        idx += ENCODING_LENGTH;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_highlight_app
 * DESCRIPTION
 *  app menu item hilight hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_barcodereader_enter_preview_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_barcodereader_enter_preview_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_highlight_to_qrv_editor
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_highlight_to_qrv_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_barcodereader_enter_qrv_editor_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_barcodereader_enter_qrv_editor_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_qrv_editor_screen
 * DESCRIPTION
 *  exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_exit_qrv_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free buffer */

    /* for MAUI_01348442 */
//    gui_free(g_barcodereader_cntx.storage_filepath);
//    g_barcodereader_cntx.storage_filepath = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_enter_qrv_editor_screen
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_enter_qrv_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*S32 index;*/
    S32 bufferSize;
    U8 *guiBuffer;
    /* FMGR_Revise */
//    S8 fmgr_filepath[FMGR_PATH_BUFFER_SIZE];
    FMGR_FILE_INFO_STRUCT file_info;
    FS_HANDLE file_handle;
    U32 read_size;

    /* for MAUI_01348442 */
    static S8 j_filepath[FMGR_PATH_BUFFER_SIZE];
    static U32 j_filesize;
    S8* fmgr_ptr;
   
//    mmi_chset_enum file_encoding_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*do not allow reentry*/
    if(IsScreenPresent(SCR_ID_BARCODEREADER_EDITOR) && (!CheckIsBackHistory()))
    {
        DeleteScreenIfPresent(SCR_ID_BARCODEREADER_EDITOR);
        DeleteScreenIfPresent(SCR_ID_BARCODEREADER_APP_PREVIEW_OPTION);
        //GoBackHistory();
    }

    /* for MAUI_01348442 */
    if(fmgr_path_get == 0 && !CheckIsBackHistory())
    {
        /* the very first time entry, and must get filepath, and filesize first */
        fmgr_ptr = mmi_fmgr_get_current_fileinfo(&file_info, NULL);
        ASSERT(fmgr_ptr);

        j_filesize = file_info.file_size;
        mmi_ucs2cpy((PS8)j_filepath, fmgr_ptr);
    }



    /* allocate memory from App-Based ASM */
    if (g_barcodereader_cntx.app_mem_pool == NULL)
    {
        g_barcodereader_cntx.app_mem_pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_BARCODEREADER, BR_APP_TOTAL_SIZE);

        if (g_barcodereader_cntx.app_mem_pool == NULL)
        {
            g_barcodereader_cntx.entry_app_callback = mmi_barcodereader_enter_qrv_editor_screen;

            /* for MAUI_01348442 */
            /* file path already got */

            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_BARCODEREADER,
                IMG_ID_BARCODEREADER_APP_ICON,
                BR_APP_TOTAL_SIZE,
                mmi_barcodereader_app_mem_success_callback_from_qrv);
            return;
        }
    }

    /* create adm related resource */
    mmi_barcodereader_create_adm_resource();

    EntryNewScreen(
        SCR_ID_BARCODEREADER_EDITOR,
        mmi_barcodereader_exit_qrv_editor_screen,
        mmi_barcodereader_enter_qrv_editor_screen,
        NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_EDITOR);

#ifdef __MMI_BACKGROUND_CALL__
//    srv_ucm_register_app_exit_callback(MMI_UCM_APP_EXIT_CHECK_CB_BARCODEREADER, mmi_barcodereader_ucm_call_back);
    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_APP_EXIT_QUERY, mmi_barcodereader_ucm_call_back, NULL);

#endif

    SetDelScrnIDCallbackHandler(SCR_ID_BARCODEREADER_EDITOR, mmi_barcodereader_del_scr_callback);

    /* for MAUI_01348442 */
    fmgr_path_get = 0;

    if (guiBuffer != NULL)
    {
    /* from history */
        /* FMGR_Revise */
        /* Smallp comment, this should be problem of re-entry 
         *  when path is not matched, it means previous FMGR is deleted
         *  In new design, there is no need to check
         */
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
    }
    else
    {
    /* first time entry screen, filepath already got, and all buffer already malloced */
        
        g_barcodereader_cntx.selected_hilight_idx = 0;

        /* allocate string buffer */
        /* FMGR_Revise */
#if 0        
    #ifdef __MMI_DOWNLOAD_AGENT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_DOWNLOAD_AGENT__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    file_handle = FS_Open((U16*)j_filepath, FS_READ_ONLY);
    if(file_handle < FS_NO_ERROR)
    {
        mmi_barcodereader_display_error_popup((S32)file_handle, (S32)MMI_BARCODEREADER_ERROR_TYPE_FROM_FS, 0);
        DeleteScreenIfPresent(SCR_ID_BARCODEREADER_EDITOR);
        return;        
    }

    if (j_filesize == 0)
    {
        FS_Close(file_handle);
        #if defined(__MMI_HORIZONTAL_BARCODEREADER__)

            mmi_display_popup_rotated(
                (UI_string_type) GetString(STR_GLOBAL_UNSUPPORTED_FORMAT), 
                (mmi_event_notify_enum) MMI_EVENT_FAILURE,
                (mmi_frm_screen_rotate_enum) g_barcodereader_cntx.osd_rotate);

        #else /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 

            mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_UNSUPPORTED_FORMAT), MMI_EVENT_FAILURE);

        #endif /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 
        DeleteScreenIfPresent(SCR_ID_BARCODEREADER_EDITOR);
        return;        

    }

    memset(g_barcodereader_cntx.text_buf, 0, BR_TEXT_BUFFER_SIZE);
    FS_Read(file_handle, (void*)g_barcodereader_cntx.text_buf, 2, (U32*) & read_size);

    if((g_barcodereader_cntx.text_buf[0] == (S8)0xFE) && (g_barcodereader_cntx.text_buf[1] == (S8)0xFF))
    {
        if(j_filesize > BR_TEXT_BUFFER_SIZE)
        {
        FS_Close(file_handle);
        #if defined(__MMI_HORIZONTAL_BARCODEREADER__)

            mmi_display_popup_rotated(
                (UI_string_type) GetString(FMGR_FS_FILE_TOO_LARGE_TEXT), 
                (mmi_event_notify_enum) MMI_EVENT_FAILURE,
                (mmi_frm_screen_rotate_enum) g_barcodereader_cntx.osd_rotate);

        #else /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 

            mmi_display_popup((UI_string_type) GetString(FMGR_FS_FILE_TOO_LARGE_TEXT), MMI_EVENT_FAILURE);

        #endif /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 
            DeleteScreenIfPresent(SCR_ID_BARCODEREADER_EDITOR);
            return;            

        }

        memset(g_barcodereader_cntx.text_buf, 0, BR_TEXT_BUFFER_SIZE);
        FS_Read(file_handle, (void*)g_barcodereader_cntx.text_buf, j_filesize-2, (U32*) & read_size);
        FS_Close(file_handle);

    }
    else
    {
        FS_Close(file_handle);
        #if defined(__MMI_HORIZONTAL_BARCODEREADER__)

            mmi_display_popup_rotated(
                (UI_string_type) GetString(STR_GLOBAL_UNSUPPORTED_FORMAT), 
                (mmi_event_notify_enum) MMI_EVENT_FAILURE,
                (mmi_frm_screen_rotate_enum) g_barcodereader_cntx.osd_rotate);

        #else /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 

            mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_UNSUPPORTED_FORMAT), MMI_EVENT_FAILURE);

        #endif /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 
            DeleteScreenIfPresent(SCR_ID_BARCODEREADER_EDITOR);
            return;            

    }
        
    memset(g_barcodereader_cntx.formatted_text_buf, 0, BR_TEXT_BUFFER_SIZE);
    mmi_barcodereader_parse_text();
    }

    bufferSize = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);

    g_barcodereader_cntx.app_list_idx_count = g_barcodereader_cntx.app_list_idx;
    MMI_multiline_inputbox.current_hilite_idx = 0;

    ShowCategory228Screen(
        STR_ID_BARCODEREADER_APP_NAME,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) g_barcodereader_cntx.formatted_text_buf,
        bufferSize,
        g_barcodereader_cntx.app_content.ct_element,
        (U16) g_barcodereader_cntx.app_list_idx,
        mmi_barcodereader_callback,
        guiBuffer);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_HILIGHT_COUNT, g_barcodereader_cntx.app_list_idx);

    SetLeftSoftkeyFunction(mmi_barcodereader_forward_to_apps, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_app_mem_success_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_app_mem_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.app_mem_pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_BARCODEREADER, BR_APP_TOTAL_SIZE);
    ASSERT(g_barcodereader_cntx.app_mem_pool != NULL);  /* It should provide enough memory */

    ASSERT(g_barcodereader_cntx.entry_app_callback != NULL);
    g_barcodereader_cntx.entry_app_callback();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_app_mem_success_callback_from_qrv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_app_mem_success_callback_from_qrv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_path_get = 1;
    mmi_barcodereader_app_mem_success_callback();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_app_mem_stop_callback
 * DESCRIPTION
 *  callback function used by applib to free APP-Based Memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_app_mem_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* De-initialize Application */

    /* Free Memory */
    mmi_barcoderader_free_memory_and_destory_adm_resource();

    /* Notify MMI that this application is already stopped */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_BARCODEREADER, KAL_TRUE);

    DeleteScreenIfPresent(SCR_ID_BARCODEREADER_APP_PREVIEW_OPTION);
    DeleteScreenIfPresent(SCR_ID_BARCODEREADER_APP_PREVIEW);
    DeleteScreenIfPresent(SCR_ID_BARCODEREADER_PREVIEW);
    DeleteScreenIfPresent(SCR_ID_BARCODEREADER_EDITOR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_create_adm_resource
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_create_adm_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // #ifdef  __MTK_TARGET__
    /* Create MemoryPool */
    if (g_barcodereader_cntx.adm_pool_id == NULL)
    {
        g_barcodereader_cntx.adm_pool_id = kal_adm_create((void*)g_barcodereader_cntx.app_mem_pool, BR_APP_TOTAL_SIZE, NULL, KAL_FALSE);

        ASSERT(g_barcodereader_cntx.adm_pool_id != NULL);

        /* allocate memory from adm for each resource */

        g_barcodereader_cntx.text_buf = (S8*) kal_adm_alloc(g_barcodereader_cntx.adm_pool_id, BR_TEXT_BUFFER_SIZE);
        ASSERT(g_barcodereader_cntx.text_buf != NULL);

        g_barcodereader_cntx.formatted_text_buf =
            (S8*) kal_adm_alloc(g_barcodereader_cntx.adm_pool_id, BR_TEXT_BUFFER_SIZE);
        ASSERT(g_barcodereader_cntx.formatted_text_buf != NULL);

        g_barcodereader_cntx.working_buffer =
            (S8*) kal_adm_alloc(g_barcodereader_cntx.adm_pool_id, BR_TEXT_BUFFER_SIZE);
        ASSERT(g_barcodereader_cntx.working_buffer != NULL);

        g_barcodereader_cntx.input_string = (S8*) kal_adm_alloc(g_barcodereader_cntx.adm_pool_id, BR_TEXT_BUFFER_SIZE);
        ASSERT(g_barcodereader_cntx.input_string != NULL);

        g_barcodereader_cntx.input_string_tmp =
            (S8*) kal_adm_alloc(g_barcodereader_cntx.adm_pool_id, BR_TEXT_BUFFER_SIZE);
        ASSERT(g_barcodereader_cntx.input_string_tmp != NULL);

        g_barcodereader_cntx.decode_text =
            (S8*) kal_adm_alloc(g_barcodereader_cntx.adm_pool_id, BR_VERSION_ONE_SLOT_BUFFER_SIZE);
        ASSERT(g_barcodereader_cntx.decode_text != NULL);

        for (i = 0; i < BR_VERSION_NODE_COUNT; i++)
        {
            g_barcodereader_cntx.text_slot[i] =
                (S8*) kal_adm_alloc(g_barcodereader_cntx.adm_pool_id, BR_VERSION_ONE_SLOT_BUFFER_SIZE);
            ASSERT(g_barcodereader_cntx.text_slot[i] != NULL);
        }

    g_barcodereader_cntx.hint1_buf = (S8*) kal_adm_alloc(g_barcodereader_cntx.adm_pool_id, BR_HINT_BUFFER_SIZE);
    ASSERT(g_barcodereader_cntx.hint1_buf != NULL);
    g_barcodereader_cntx.hint2_buf = (S8*) kal_adm_alloc(g_barcodereader_cntx.adm_pool_id, BR_HINT_BUFFER_SIZE);
    ASSERT(g_barcodereader_cntx.hint2_buf != NULL);

    memset(g_barcodereader_cntx.hint1_buf, 0, BR_HINT_BUFFER_SIZE);
    memset(g_barcodereader_cntx.hint2_buf, 0, BR_HINT_BUFFER_SIZE);

    }
    // #endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_free_adm_resource
 * DESCRIPTION
 *  callback function used by applib to free APP-Based Memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_free_adm_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    kal_status ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    if (g_barcodereader_cntx.adm_pool_id)
    {
        for (; i < 16; i++)
        {
            kal_adm_free(g_barcodereader_cntx.adm_pool_id, (void*)g_barcodereader_cntx.text_slot[i]);
            g_barcodereader_cntx.text_slot[i] = NULL;
        }

        kal_adm_free(g_barcodereader_cntx.adm_pool_id, (void*)g_barcodereader_cntx.text_buf);
        g_barcodereader_cntx.text_buf = NULL;

        kal_adm_free(g_barcodereader_cntx.adm_pool_id, (void*)g_barcodereader_cntx.formatted_text_buf);
        g_barcodereader_cntx.formatted_text_buf = NULL;

        kal_adm_free(g_barcodereader_cntx.adm_pool_id, (void*)g_barcodereader_cntx.working_buffer);
        g_barcodereader_cntx.working_buffer = NULL;

        kal_adm_free(g_barcodereader_cntx.adm_pool_id, (void*)g_barcodereader_cntx.input_string);
        g_barcodereader_cntx.input_string = NULL;

        kal_adm_free(g_barcodereader_cntx.adm_pool_id, (void*)g_barcodereader_cntx.input_string_tmp);
        g_barcodereader_cntx.input_string_tmp = NULL;

        kal_adm_free(g_barcodereader_cntx.adm_pool_id, (void*)g_barcodereader_cntx.decode_text);
        g_barcodereader_cntx.decode_text = NULL;

    if (g_barcodereader_cntx.hint1_buf != NULL)
    {
        kal_adm_free(g_barcodereader_cntx.adm_pool_id, (void*)g_barcodereader_cntx.hint1_buf);
         g_barcodereader_cntx.hint1_buf = NULL;
    }

    if (g_barcodereader_cntx.hint2_buf != NULL)
    {
        kal_adm_free(g_barcodereader_cntx.adm_pool_id, (void*)g_barcodereader_cntx.hint2_buf);
        g_barcodereader_cntx.hint2_buf = NULL;
    }

        ret = kal_adm_delete(g_barcodereader_cntx.adm_pool_id);

        ASSERT(ret == KAL_SUCCESS);
        g_barcodereader_cntx.adm_pool_id = NULL;
    }
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_del_scr_callback
 * DESCRIPTION
 *  delete screen id callback handler of BARCODEREADER applications
 * PARAMETERS
 *  ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_barcodereader_del_scr_callback(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_BACKGROUND_CALL__
//    srv_ucm_unregister_app_exit_callback(MMI_UCM_APP_EXIT_CHECK_CB_BARCODEREADER);
    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_APP_EXIT_QUERY, mmi_barcodereader_ucm_call_back, NULL);

#endif

    /* free kal adm memory pool */
    mmi_barcodereader_free_adm_resource();

    /* free app-based memory */
    if (g_barcodereader_cntx.app_mem_pool != NULL)
    {
        applib_mem_ap_free((void*)g_barcodereader_cntx.app_mem_pool);
        g_barcodereader_cntx.app_mem_pool = NULL;
    }

    /* check if it is in incall state, if yes, we need to reserve some incall screen */
//    if (isInCall() == TRUE)
    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        return MMI_FALSE;
    }

    /* if end_screen or marker_screen == 0, delete all barcodereader screen */
    for(i = SCR_ID_BARCODEREADER_MAIN; i< SCR_ID_BARCODEREADER_ALL; i++)
    {
        if(i != SCR_ID_BARCODEREADER_PREVIEW && i != SCR_ID_BARCODEREADER_EDITOR)
        {
            DeleteScreenIfPresent(i);
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_init_op00_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_init_op00_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize application memory pool */
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_BARCODEREADER,
        STR_ID_BARCODEREADER_APP_NAME,
        IMG_ID_BARCODEREADER_APP_ICON,
        mmi_barcodereader_app_mem_stop_callback);
    g_barcodereader_cntx.adm_pool_id = NULL;
    g_barcodereader_cntx.app_mem_pool = NULL;

    /* initialize Append Structure QR Code */
    g_barcodereader_cntx.is_append_qrcode = FALSE;
    g_barcodereader_cntx.nsymbol = 0;
    g_barcodereader_cntx.symbol_count = 0;
    g_barcodereader_cntx.paritydata = 0;
    g_barcodereader_cntx.encoding = 0;
    g_barcodereader_cntx.symbol_masks = 0;

    g_barcodereader_cntx.app_state = MMI_BARCODEREADER_STATE_EXIT;
    g_barcodereader_cntx.app_prev_state = MMI_BARCODEREADER_STATE_EXIT;
    g_barcodereader_cntx.app_next_state = MMI_BARCODEREADER_STATE_EXIT;

    g_barcodereader_cntx.is_storage_path_changed = FALSE;
    g_barcodereader_cntx.is_setting_loaded = FALSE;
    g_barcodereader_cntx.is_mainlcd_resource = FALSE;
    g_barcodereader_cntx.is_sublcd_display = FALSE;
    g_barcodereader_cntx.is_cat65_show = FALSE;
    g_barcodereader_cntx.is_manual_autofocus = FALSE;
    g_barcodereader_cntx.is_storage_ready = TRUE;

    g_barcodereader_cntx.base_layer_handle = GDI_LAYER_EMPTY_HANDLE;

    g_barcodereader_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_barcodereader_cntx.sublcd_base_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_barcodereader_cntx.preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;

#if defined(__MMI_HORIZONTAL_BARCODEREADER__)
    g_barcodereader_cntx.osd_rotate = MMI_BARCODEREADER_OSD_ROTATE_0;
    g_barcodereader_cntx.base_UI_device_width = LCD_HEIGHT;
    g_barcodereader_cntx.base_UI_device_height = LCD_WIDTH;
#else /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 
    g_barcodereader_cntx.osd_rotate = MMI_BARCODEREADER_OSD_ROTATE_0;
    g_barcodereader_cntx.base_UI_device_width = LCD_WIDTH;
    g_barcodereader_cntx.base_UI_device_height = LCD_HEIGHT;
#endif /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 

    g_barcodereader_cntx.active_barcodereader_osd_ptr = &g_barcodereader_osd_cntx;

    g_barcodereader_cntx.osd_UI_device_width = LCD_WIDTH;
    g_barcodereader_cntx.osd_UI_device_height = LCD_HEIGHT;

    /*init camera setting title id*/
    mmi_barcodereader_camera_set_title(STR_GLOBAL_SETTINGS);

#define INIT_OSD_TOUCH_ICON(a,A)                                                                                       \
   do {                                                                                                                \
      if(g_barcodereader_cntx.active_barcodereader_osd_ptr->##a##.is_show)                                             \
      {                                                                                                                \
         gdi_image_get_dimension_id((U16)(IMG_ID_BARCODEREADER_OSD_##A##_START+1),                                     \
                                    &g_barcodereader_cntx.touch_##a##.width,                                           \
                                    &g_barcodereader_cntx.touch_##a##.height);                                         \
         g_barcodereader_cntx.touch_##a##.offset_x = g_barcodereader_cntx.active_barcodereader_osd_ptr->##a##.offset_x;\
         g_barcodereader_cntx.touch_##a##.offset_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->##a##.offset_y;\
         g_barcodereader_cntx.touch_##a##.is_press = FALSE;                                                            \
      }                                                                                                                \
   } while(0);

    /* draw icon */
    INIT_OSD_TOUCH_ICON(flash, FLASH);
    INIT_OSD_TOUCH_ICON(af_mode, FOCUS_MODE);
    INIT_OSD_TOUCH_ICON(storage, STORAGE);

    /* ev inc */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_BARCODEREADER_OSD_EV_INC),
        &g_barcodereader_cntx.touch_ev_inc.width,
        &g_barcodereader_cntx.touch_ev_inc.height);

    g_barcodereader_cntx.touch_ev_inc.offset_x = g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_inc.offset_x;
    g_barcodereader_cntx.touch_ev_inc.offset_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_inc.offset_y;
    g_barcodereader_cntx.touch_ev_inc.is_press = FALSE;

    /* ev dec */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_BARCODEREADER_OSD_EV_DEC),
        &g_barcodereader_cntx.touch_ev_dec.width,
        &g_barcodereader_cntx.touch_ev_dec.height);

    g_barcodereader_cntx.touch_ev_dec.offset_x = g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_dec.offset_x;
    g_barcodereader_cntx.touch_ev_dec.offset_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_dec.offset_y;
    g_barcodereader_cntx.touch_ev_dec.is_press = FALSE;

    /* mf inc */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_BARCODEREADER_OSD_MF_INC),
        &g_barcodereader_cntx.touch_mf_inc.width,
        &g_barcodereader_cntx.touch_mf_inc.height);

    g_barcodereader_cntx.touch_mf_inc.offset_x = g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_inc.offset_x;
    g_barcodereader_cntx.touch_mf_inc.offset_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_inc.offset_y;
    g_barcodereader_cntx.touch_mf_inc.is_press = FALSE;

    /* mf dec */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_BARCODEREADER_OSD_MF_DEC),
        &g_barcodereader_cntx.touch_mf_dec.width,
        &g_barcodereader_cntx.touch_mf_dec.height);

    g_barcodereader_cntx.touch_mf_dec.offset_x = g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_dec.offset_x;
    g_barcodereader_cntx.touch_mf_dec.offset_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_dec.offset_y;
    g_barcodereader_cntx.touch_mf_dec.is_press = FALSE;

    /* capture */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_BARCODEREADER_OSD_CAPTURE),
        &g_barcodereader_cntx.touch_capture.width,
        &g_barcodereader_cntx.touch_capture.height);

    g_barcodereader_cntx.touch_capture.offset_x = g_barcodereader_cntx.active_barcodereader_osd_ptr->capture.offset_x;
    g_barcodereader_cntx.touch_capture.offset_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->capture.offset_y;
    g_barcodereader_cntx.touch_capture.is_press = FALSE;

    /*get storage value*/
    mmi_barcodereader_load_setting();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_append_qrcode_continue
 * DESCRIPTION
 *  exit help screen, and still in append_barcode mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_append_qrcode_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_append_qrcode_reset
 * DESCRIPTION
 *  exit help screen, and reset append_barcode mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_append_qrcode_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.is_append_qrcode = FALSE;
    g_barcodereader_cntx.symbol_masks = 0;
    g_barcodereader_cntx.symbol_count = 1;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_enter_tip_screen
 * DESCRIPTION
 *  this screen is for user to decoded continue to decode append
 *  barcode or to reset application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_enter_tip_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 buffer;
    S32 bufferSize;
    U8 *guiBuffer;
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_BARCODEREADER_TIP,
        mmi_barcodereader_exit_tip_screen,
        mmi_barcodereader_enter_tip_screen,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_TIP);

    switch (g_barcodereader_cntx.help_str_enum)
    {
        case MMI_BARCODEREADER_HELP_DECODE_NEXT:
            str_id = STR_ID_BARCODEREADER_HELP_APPEND_BARCODE;
            break;
        case MMI_BARCODEREADER_HELP_WRONG_SERIES:
            str_id = STR_ID_BARCODEREADER_HELP_WRONG_SERIES;
            break;
        case MMI_BARCODEREADER_HELP_DUPLICATED_CODE:
            str_id = STR_ID_BARCODEREADER_HELP_DUPLICATED_CODE;
            break;
        default:
            str_id = STR_ID_BARCODEREADER_HELP_APPEND_BARCODE;
            break;
    }
    buffer = GetString(str_id);
    mmi_ucs2cpy(g_barcodereader_cntx.input_string_tmp, buffer);

    if (g_barcodereader_cntx.help_str_enum != MMI_BARCODEREADER_HELP_WRONG_SERIES)
    {
        sprintf((PS8) g_barcodereader_cntx.working_buffer, "#%d, ", g_barcodereader_cntx.symbolid);
        mmi_asc_to_ucs2(g_barcodereader_cntx.input_string, g_barcodereader_cntx.working_buffer);
        mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp, g_barcodereader_cntx.input_string);
    }

    buffer = GetString(STR_ID_BARCODEREADER_HELP_DECODE_NEXT);
    mmi_ucs2cat(g_barcodereader_cntx.input_string_tmp, buffer);

    bufferSize = mmi_ucs2strlen(g_barcodereader_cntx.input_string_tmp);

    ShowCategory74Screen(
        STR_ID_BARCODEREADER_ORDER_ATTENTION,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_GLOBAL_CONTINUE,
        IMG_GLOBAL_OK,
        STR_GLOBAL_RESET,
        IMG_GLOBAL_BACK,
        (PU8) g_barcodereader_cntx.input_string_tmp,
        bufferSize,
        NULL);

    SetKeyHandler(mmi_barcodereader_append_qrcode_reset, KEY_RSK, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_barcodereader_append_qrcode_reset, KEY_EVENT_UP);

    SetKeyHandler(mmi_barcodereader_append_qrcode_continue, KEY_LSK, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_barcodereader_append_qrcode_continue, KEY_EVENT_UP);

    g_barcodereader_cntx.help_str_enum = MMI_BARCODEREADER_HELP_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_tip_screen
 * DESCRIPTION
 *  exit screen function of mmi_barcodereader_enter_tip_screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_exit_tip_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyEvents();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_decode_result_hdlr
 * DESCRIPTION
 *  no block burst shot capture result handler, symbolid start from 1, nsymbol means how many symbol
 * PARAMETERS
 *  ret                 [IN]        Decode result ( Succeed or Fail )
 *  encoding            [IN]        
 *  nsymbol             [IN]        
 *  symbolid            [IN]        
 *  paritydata          [IN]        
 *  barcode_type        [IN]        
 *  decode_times(?)     [IN]        How many time have we decoded.(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_decode_result_hdlr(
                mdi_result ret,
                U8 encoding,
                U8 nsymbol,
                U8 symbolid,
                U8 paritydata,
                mdi_camera_barcode_type_enum barcode_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *working_src;
    U8 *working_dest;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* decode successfully */
    if (g_barcodereader_cntx.b_stop_decode == MMI_TRUE) /*add this to avoid two popup from decode listen and mdi*/
    {
        gui_cancel_timer(mmi_barcodereader_decode_listen_timer);
        return;
    }

    if (ret == 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_STRING_LENGTH, mmi_ucs2strlen(g_barcodereader_cntx.decode_text));
        if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE)
        {
            /* if application is in APPEND_BARCODE state currently  */
            if (TRUE == g_barcodereader_cntx.is_append_qrcode)  /* node struct */
            {
                g_barcodereader_cntx.symbolid = symbolid;

                /* if the new decoded text is correct and undecoded before */
                if ((paritydata == g_barcodereader_cntx.paritydata)
                    && (nsymbol == g_barcodereader_cntx.nsymbol)
                    && (0 == ((1 << (symbolid - 1)) & g_barcodereader_cntx.symbol_masks)))
                {
                    g_barcodereader_cntx.symbol_count++;
                    g_barcodereader_cntx.symbol_masks |= (1 << (symbolid - 1));

                    /* copy decode string to text slot */
                    working_src = (U8*) g_barcodereader_cntx.decode_text;
                    memset(g_barcodereader_cntx.text_slot[symbolid - 1], 0xff, BR_VERSION_ONE_SLOT_BUFFER_SIZE);
                    working_dest = (U8*) g_barcodereader_cntx.text_slot[symbolid - 1];
                    while (*working_src != 0)
                    {
                        *working_dest++ = *working_src;
                        working_src++;
                    }
                    *working_dest = 0;

                    if (encoding < g_barcodereader_cntx.encoding)
                    {
                        g_barcodereader_cntx.encoding = encoding;
                    }

                    /* if all append barcodes are decoded */
                    if (g_barcodereader_cntx.symbol_count == nsymbol)
                    {
                        U8 count;

                        working_dest = (U8*) g_barcodereader_cntx.formatted_text_buf;
                        memset(g_barcodereader_cntx.formatted_text_buf, 0xff, BR_TEXT_BUFFER_SIZE);
                        /* conbime slot to text_buffer */
                        for (count = 0; count < nsymbol; count++)
                        {
                            working_src = (U8*) g_barcodereader_cntx.text_slot[count];
                            while (*working_src != 0)
                            {
                                *working_dest++ = *working_src;
                                working_src++;
                            }
                        }
                        *working_dest = 0;

                        if (0x01 == (encoding & 0x01))
                        {
                            mmi_chset_convert(
                                MMI_CHSET_GB2312,
                                MMI_CHSET_UCS2,
                                (char*)g_barcodereader_cntx.formatted_text_buf,
                                (char*)g_barcodereader_cntx.text_buf,
                                BR_TEXT_BUFFER_SIZE);
                        }
                        else if (0x04 == (encoding & 0x04) || 0x02 == (encoding & 0x02))
                        {
                            mmi_chset_convert(
                                MMI_CHSET_UTF8,
                                MMI_CHSET_UCS2,
                                (char*)g_barcodereader_cntx.formatted_text_buf,
                                (char*)g_barcodereader_cntx.text_buf,
                                BR_TEXT_BUFFER_SIZE);
                        }
                        else
                        {
                            mmi_chset_convert(
                                MMI_CHSET_GB2312,
                                MMI_CHSET_UCS2,
                                (char*)g_barcodereader_cntx.formatted_text_buf,
                                (char*)g_barcodereader_cntx.text_buf,
                                BR_TEXT_BUFFER_SIZE);
                        }

                        memset(g_barcodereader_cntx.formatted_text_buf, 0xff, BR_TEXT_BUFFER_SIZE);
                        g_barcodereader_cntx.is_append_qrcode = FALSE;
                        g_barcodereader_cntx.symbol_masks = 0;
                        g_barcodereader_cntx.symbol_count = 1;
                        mmi_barcodereader_parse_text();

                        mmi_barcodereader_entry_editor_screen();
                    }
                    else
                    {
                        /* shows 3: please decode the next one barcode */
                        g_barcodereader_cntx.help_str_enum = MMI_BARCODEREADER_HELP_DECODE_NEXT;
                        mmi_barcodereader_enter_tip_screen();
                    }
                }
                else if ((paritydata != g_barcodereader_cntx.paritydata)        /* node struct */
                         || (nsymbol != g_barcodereader_cntx.nsymbol))
                {
                    /* if the decoded barcode is not correct */
                    /* shows 1: this barcode is not the same series */
                    g_barcodereader_cntx.help_str_enum = MMI_BARCODEREADER_HELP_WRONG_SERIES;
                    mmi_barcodereader_enter_tip_screen();
                }
                else if (0 != ((1 << (symbolid - 1)) & g_barcodereader_cntx.symbol_masks))
                {
                    /* if the decoded barcode was decoded before */
                    /* shows 2: this barcode was decoded before */
                    g_barcodereader_cntx.help_str_enum = MMI_BARCODEREADER_HELP_DUPLICATED_CODE;
                    mmi_barcodereader_enter_tip_screen();
                }
            }
            else if (FALSE == g_barcodereader_cntx.is_append_qrcode)
            {

                if (nsymbol == 1)
                {
                    if (0x01 == (encoding  & 0x01))
                    {
                        mmi_chset_convert(
                            MMI_CHSET_GB2312,
                            MMI_CHSET_UCS2,
                            (char*)g_barcodereader_cntx.decode_text,
                            (char*)g_barcodereader_cntx.formatted_text_buf,
                            BR_VERSION_ONE_SLOT_BUFFER_SIZE);
                    }
                    else if (0x04 == (encoding & 0x04)||0x02 == (encoding & 0x02))
                    {
                        mmi_chset_convert(
                            MMI_CHSET_UTF8,
                            MMI_CHSET_UCS2,
                            (char*)g_barcodereader_cntx.decode_text,
                            (char*)g_barcodereader_cntx.formatted_text_buf,
                            BR_VERSION_ONE_SLOT_BUFFER_SIZE);
                    }
                    else    /* default encoding type is gb2312 */
                    {
                        mmi_chset_convert(
                            MMI_CHSET_GB2312,
                            MMI_CHSET_UCS2,
                            (char*)g_barcodereader_cntx.decode_text,
                            (char*)g_barcodereader_cntx.formatted_text_buf,
                            BR_VERSION_ONE_SLOT_BUFFER_SIZE);
                    }

                    mmi_ucs2cpy(g_barcodereader_cntx.text_buf, g_barcodereader_cntx.formatted_text_buf);
                    memset(g_barcodereader_cntx.formatted_text_buf, 0xff, BR_TEXT_BUFFER_SIZE);

                    mmi_barcodereader_parse_text();
                    mmi_barcodereader_entry_editor_screen();
                }
                else if (nsymbol > 1)
                {
                    g_barcodereader_cntx.is_append_qrcode = TRUE;
                    g_barcodereader_cntx.paritydata = paritydata;
                    g_barcodereader_cntx.nsymbol = nsymbol;
                    g_barcodereader_cntx.symbolid = symbolid;
                    g_barcodereader_cntx.symbol_masks = 0;
                    g_barcodereader_cntx.symbol_count = 1;
                    g_barcodereader_cntx.symbol_masks |= (1 << (symbolid - 1));
                    g_barcodereader_cntx.encoding = encoding;

                    /* copy decode string to text slot */
                    working_src = (U8*) g_barcodereader_cntx.decode_text;
                    memset(g_barcodereader_cntx.text_slot[symbolid - 1], 0xff, BR_VERSION_ONE_SLOT_BUFFER_SIZE);
                    working_dest = (U8*) g_barcodereader_cntx.text_slot[symbolid - 1];
                    while (*working_src != 0)
                    {
                        *working_dest++ = *working_src;
                        working_src++;
                    }
                    *working_dest = 0;

                    /* shows 3: please decode the next one barcode */
                    g_barcodereader_cntx.help_str_enum = MMI_BARCODEREADER_HELP_DECODE_NEXT;
                    mmi_barcodereader_enter_tip_screen();
                }
                else
                    ASSERT(0);
            }

        }
        else if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW)
        {
            mmi_barcodereader_preview_start();
        }
    }
    else
    {
        g_barcodereader_cntx.last_error.error_result = ret;
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;
        g_barcodereader_cntx.last_error.tone_id = ERROR_TONE;
        /* currently, it should not go here */
        mmi_barcodereader_display_error_popup(
            g_barcodereader_cntx.last_error.error_result,
            g_barcodereader_cntx.last_error.error_type,
            g_barcodereader_cntx.last_error.tone_id);
    }
}

#ifdef __MMI_BARCODEREADER_FOCUS_MODE__


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_focus_process
 * DESCRIPTION
 *  draw focus related OSD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_draw_focus_process()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U16 image_id = 0; */
    U16 af_x = 0;
    U16 af_y = 0;
    U16 af_width = 0;
    gdi_color af_color = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_barcodereader_cntx.af_state)
    {
        case MMI_BARCODEREADER_AF_CALCULATE:

            if (g_barcodereader_cntx.is_manual_autofocus == FALSE)
            {
                if (g_barcodereader_cntx.af_animation_process == MMI_BARCODEREADER_AF_ANIMATION_ALL)
                {
                    g_barcodereader_cntx.af_animation_process = MMI_BARCODEREADER_AF_ANIMATION_STEP1;
                }

                switch (g_barcodereader_cntx.af_animation_process)
                {
                    case MMI_BARCODEREADER_AF_ANIMATION_STEP1:
                        af_width = MMI_BARCODEREADER_AF_LARGE_WIDTH;
                        af_color = GDI_COLOR_WHITE;
                        break;
                    case MMI_BARCODEREADER_AF_ANIMATION_STEP2:
                        af_color = GDI_COLOR_GRAY;
                        af_width = MMI_BARCODEREADER_AF_NORMAL_WIDTH;
                        break;
                    case MMI_BARCODEREADER_AF_ANIMATION_STEP3:
                        af_color = GDI_COLOR_BLACK;
                        af_width = MMI_BARCODEREADER_AF_SMALL_WIDTH;
                        break;
                }

                af_x = MMI_BARCODEREADER_AF_POSITION_1_X - af_width / 2;
                af_y = MMI_BARCODEREADER_AF_POSITION_1_Y - af_width / 2;
                mmi_barcodereader_draw_bolder_rect(
                    af_x,
                    af_y,
                    af_x + af_width - 1,
                    af_y + af_width - 1,
                    1,
                    GDI_COLOR_WHITE);

                g_barcodereader_cntx.af_animation_process++;
            }

            break;
        case MMI_BARCODEREADER_AF_SUCCEED:
            af_width = MMI_BARCODEREADER_AF_SMALL_WIDTH;

            af_x = MMI_BARCODEREADER_AF_POSITION_1_X - af_width / 2;
            af_y = MMI_BARCODEREADER_AF_POSITION_1_Y - af_width / 2;
            mmi_barcodereader_draw_bolder_rect(
                af_x,
                af_y,
                af_x + af_width - 1,
                af_y + af_width - 1,
                1,
                GDI_COLOR_GREEN);

            break;
        case MMI_BARCODEREADER_AF_FAIL:
            af_width = MMI_BARCODEREADER_AF_SMALL_WIDTH;

            af_x = MMI_BARCODEREADER_AF_POSITION_1_X - af_width / 2;
            af_y = MMI_BARCODEREADER_AF_POSITION_1_Y - af_width / 2;
            mmi_barcodereader_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, GDI_COLOR_RED);

            break;
        case MMI_BARCODEREADER_AF_IDLE:
        case MMI_BARCODEREADER_AF_ONFOCUS:
            break;

    }
}
#endif /* __MMI_BARCODEREADER_FOCUS_MODE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_enter_sublcd_screen
 * DESCRIPTION
 *  entry sublcd screen, if still remain on standard MMI sublcd screen, time update will
 *  redraw sublcd while mainlcd is previewing, will cause driver assert.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_barcodereader_enter_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory331Screen();
    SetSubLCDExitHandler(mmi_barcodereader_exit_sublcd_screen);

    g_barcodereader_cntx.is_sublcd_display = TRUE;
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_sublcd_screen
 * DESCRIPTION
 *  exit sublcd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_barcodereader_exit_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode sub_history;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.is_sublcd_display = FALSE;

    sub_history.entryFuncPtr = mmi_barcodereader_enter_sublcd_screen;
    AddSubLCDHistory(&sub_history);
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_sublcd_draw_icon
 * DESCRIPTION
 *  draw a sublcd icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_barcodereader_sublcd_draw_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 lcd_width;
    S32 lcd_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_lcd_get_dimension(&lcd_width, &lcd_height);

    gdi_layer_reset_clip();

    gdi_layer_clear_background(GDI_COLOR_WHITE);
    gdi_image_get_dimension_id(IMG_ID_BARCODEREADER_PREVIEW_SUBLCD_ICON, &image_width, &image_height);
    gdi_image_draw_id(
        (lcd_width - image_width) >> 1,
        (lcd_height - image_height) >> 1,
        IMG_ID_BARCODEREADER_PREVIEW_SUBLCD_ICON);
    gdi_layer_blt_base_layer(0, 0, lcd_width - 1, lcd_height - 1);

    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_preview_stop
 * DESCRIPTION
 *  stop previewing of main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_preview_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop previewing */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODERD_CALL_MDI_STOP_PREVIEW);

    mdi_camera_barcodereader_preview_stop();

    /* restore black background */
#ifdef CAMERA_MODULE_WITH_LCD
    mmi_barcodereader_preview_clear_background();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_preview_screen
 * DESCRIPTION
 *  exit barcode reader application screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_exit_preview_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* exit camera state */
    MMI_BARCODEREADER_ENTER_STATE(MMI_BARCODEREADER_STATE_EXIT);

    /* stop capture and stop dummy bg midi for multi-channel sound */

    /* reset af related var */
#if defined(__CAMERA_AUTOFOCUS__)
    if (g_barcodereader_cntx.af_state != MMI_BARCODEREADER_AF_IDLE)
    {
        mdi_camera_stop_autofocus_process();
    }

    g_barcodereader_cntx.af_state = MMI_BARCODEREADER_AF_IDLE;
#endif /* defined(__CAMERA_AUTOFOCUS__) */ 

#if defined(__MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__) && !defined(__MMI_BARCODEREADER_AF_SUPPORT__)
    gui_cancel_timer(mmi_barcodereader_capture_button_press);
#endif 

#if !defined(__MMI_BARCODEREADER_AF_SUPPORT__)
    gui_cancel_timer(mmi_barcodereader_start_capture_and_decode);
#endif 

    /* stop hide hint timer */
    gui_cancel_timer(mmi_barcodereader_hide_hint);
    gui_cancel_timer(mmi_barcodereader_draw_osd_timer);

#ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
    mmi_barcodereader_reset_watchdog_time_out_handler();
#endif 

    /* shut down camera */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODERD_EXIT_CALL_MDI_STOP_PREVIEW);
    mdi_camera_barcodereader_preview_stop();

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODERD_CALL_MDI_CAMERA_POWEROFF);
    mdi_camera_power_off();

    mmi_barcodereader_uninit_frameword();

    /* free buffer */
    gui_free(g_barcodereader_cntx.storage_filepath);
    g_barcodereader_cntx.storage_filepath = NULL;

    /* turn off led */
#ifdef __MMI_BARCODEREADER_FLASH__
    if (mmi_barcodereader_get_flash_value() == MMI_BARCODEREADER_SETTING_FLASH_ON)
    {
        mdi_camera_flash_setting(FALSE);
    }
#endif /* __MMI_BARCODEREADER_FLASH__ */ 

#ifdef __MMI_SUBLCD__
    gdi_layer_push_and_set_active(g_barcodereader_cntx.sublcd_base_layer_handle);
    gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_0);
    gdi_layer_pop_and_restore_active();

    /* exit sublcd */
    if (g_barcodereader_cntx.is_sublcd_display)
    {
        GoBackSubLCDHistory();
        g_barcodereader_cntx.is_sublcd_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 

#if defined(__MMI_HORIZONTAL_BARCODEREADER__)
    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
    gdi_layer_push_and_set_active(g_barcodereader_cntx.base_layer_handle);
    gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_rotate_by_layer(FALSE);
#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
    }
#endif /* __MMI_TVOUT__ */ 
#else /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 
    gdi_layer_push_and_set_active(g_barcodereader_cntx.base_layer_handle);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
#endif /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 

    /* free preview resource */
    mmi_barcodereader_free_resource();

    /* store camera setting back to NVRAM */
    mmi_barcodereader_store_setting();

    /* this will force title status to redraw */
    entry_full_screen();

    /*for draw title bar*/
    wgui_reset_wallpaper_on_bottom();
        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_dummy_func
 * DESCRIPTION
 *  dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_dummy_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* empty function */
}


#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_autofocus_callback
 * DESCRIPTION
 *  callback while AF is succeed/fail
 * PARAMETERS
 *  result      [IN]        
 *  void(?)     [OUT]       PMsg(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
#if MDI_CAMERA_MT6238_SERIES
static void mmi_barcodereader_autofocus_callback(mdi_camera_af_result_struct result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* parse pMsg to get result */
    /* and response to osd layer */
    if (g_barcodereader_cntx.af_state == MMI_BARCODEREADER_AF_IDLE)
    {
        return;
    }

    g_barcodereader_cntx.af_result = (U8) result.af_result;


    if (g_barcodereader_cntx.app_state != MMI_BARCODEREADER_STATE_EXIT)
    {
        if (g_barcodereader_cntx.af_result == 0xFF)
        {
            g_barcodereader_cntx.af_state = MMI_BARCODEREADER_AF_FAIL;
            /* send cancel command to driver to stop cal focus */
            gui_cancel_timer(mmi_barcodereader_draw_osd_timer);
            mmi_barcodereader_set_hint(
                (PS8) GetString(STR_ID_BARCODEREADER_NOTIFY_CAPTURE_AND_DECODE),
                NULL,
                HINT_POPUP_FADE_TIME);

            mmi_barcodereader_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);

            if (g_barcodereader_cntx.is_af_capture == TRUE)
            {
                g_barcodereader_cntx.is_af_capture = FALSE;
                mmi_barcodereader_capture_button_press();
            }
        }
        else
        {
            g_barcodereader_cntx.af_state = MMI_BARCODEREADER_AF_SUCCEED;

            /* send cancel command to driver to stop cal focus */
            gui_cancel_timer(mmi_barcodereader_draw_osd_timer);
            mmi_barcodereader_set_hint(
                (PS8) GetString(STR_ID_BARCODEREADER_NOTIFY_CAPTURE_AND_DECODE),
                NULL,
                HINT_POPUP_FADE_TIME);
            mmi_barcodereader_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);

            if (g_barcodereader_cntx.is_af_capture == TRUE)
            {
                g_barcodereader_cntx.is_af_capture = FALSE;
                mmi_barcodereader_capture_button_press();
            }
        }
        g_barcodereader_cntx.is_draw_timer_on = FALSE;
        g_barcodereader_cntx.af_state = MMI_BARCODEREADER_AF_ONFOCUS;
        gui_start_timer(100, mmi_barcodereader_draw_osd_timer);
    }
}


#else


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_autofocus_callback
 * DESCRIPTION
 *  callback while AF is succeed/fail
 * PARAMETERS
 *  result      [IN]        
 *  void(?)     [OUT]       PMsg(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_autofocus_callback(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* parse pMsg to get result */
    /* and response to osd layer */
    if (g_barcodereader_cntx.af_state == MMI_BARCODEREADER_AF_IDLE)
    {
        return;
    }

    g_barcodereader_cntx.af_result = (U8) result;

    if (g_barcodereader_cntx.app_state != MMI_BARCODEREADER_STATE_EXIT)
    {
        if (g_barcodereader_cntx.af_result == 0xFF)
        {
            g_barcodereader_cntx.af_state = MMI_BARCODEREADER_AF_FAIL;
            /* send cancel command to driver to stop cal focus */
            gui_cancel_timer(mmi_barcodereader_draw_osd_timer);
            mmi_barcodereader_set_hint(
                (PS8) GetString(STR_ID_BARCODEREADER_NOTIFY_CAPTURE_AND_DECODE),
                NULL,
                HINT_POPUP_FADE_TIME);

            mmi_barcodereader_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);

            if (g_barcodereader_cntx.is_af_capture == TRUE)
            {
                g_barcodereader_cntx.is_af_capture = FALSE;
                mmi_barcodereader_capture_button_press();
            }
        }
        else
        {
            g_barcodereader_cntx.af_state = MMI_BARCODEREADER_AF_SUCCEED;

            /* send cancel command to driver to stop cal focus */
            gui_cancel_timer(mmi_barcodereader_draw_osd_timer);
            mmi_barcodereader_set_hint(
                (PS8) GetString(STR_ID_BARCODEREADER_NOTIFY_CAPTURE_AND_DECODE),
                NULL,
                HINT_POPUP_FADE_TIME);
            mmi_barcodereader_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);

            if (g_barcodereader_cntx.is_af_capture == TRUE)
            {
                g_barcodereader_cntx.is_af_capture = FALSE;
                mmi_barcodereader_capture_button_press();
            }
        }
        g_barcodereader_cntx.is_draw_timer_on = FALSE;
        g_barcodereader_cntx.af_state = MMI_BARCODEREADER_AF_ONFOCUS;
        gui_start_timer(100, mmi_barcodereader_draw_osd_timer);
    }
}
#endif
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_osd_timer
 * DESCRIPTION
 *  redraw osd timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_draw_osd_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);
    if (g_barcodereader_cntx.is_draw_timer_on)
    {
        gui_start_timer(100, mmi_barcodereader_draw_osd_timer);
    }
}

#ifdef __MMI_BARCODEREADER_AF_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_focus_button_press
 * DESCRIPTION
 *  press AF button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_focus_button_press()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__

#ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
    mmi_barcodereader_reset_watchdog_time_out_handler();
#endif

#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        //mmi_ucm_app_entry_error_message();
        return;
    }
#endif

    if (mdi_camera_is_ready_to_capture() == TRUE)
    {
        /* g_barcodereader_cntx.is_autofocus_pressed = TRUE; */
        g_barcodereader_cntx.af_state = MMI_BARCODEREADER_AF_CALCULATE;
        g_barcodereader_cntx.af_animation_process = MMI_BARCODEREADER_AF_ANIMATION_STEP1;

        /* send command to driver to start cal focus */
    #if MDI_CAMERA_MT6238_SERIES
        mdi_camera_start_autofocus_process((mdi_camera_af_ind_callback) mmi_barcodereader_autofocus_callback);
    #else
        mdi_camera_start_autofocus_process((mdi_callback) mmi_barcodereader_autofocus_callback);
    #endif

        /* clear key handler */
        ClearInputEventHandler(MMI_DEVICE_KEY);

        SetKeyHandler(mmi_barcodereader_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_barcodereader_lsk_release, KEY_LSK, KEY_EVENT_UP);

        SetKeyHandler(mmi_barcodereader_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_barcodereader_rsk_release, KEY_RSK, KEY_EVENT_UP);

        /* register capture and control keys */
        if (MMI_BARCODEREADER_CAPTURE_KEY != -1)
        {
            SetKeyHandler(mmi_barcodereader_capture_button_press, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_barcodereader_capture_button_release, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_UP);
        }

        if (MMI_BARCODEREADER_CAPTURE_EXTRA_KEY != -1)
        {
            SetKeyHandler(mmi_barcodereader_capture_button_press, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_barcodereader_capture_button_release, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_UP);
        }

        /* draw animation for focus process */
        g_barcodereader_cntx.is_draw_timer_on = TRUE;
        gui_start_timer(100, mmi_barcodereader_draw_osd_timer);

        mmi_barcodereader_draw_osd();
        gdi_layer_blt_previous(
            0,
            0,
            g_barcodereader_cntx.base_UI_device_width - 1,
            g_barcodereader_cntx.base_UI_device_height - 1);
    }
#endif
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
#endif /* 0 */ 
#endif /* __MMI_BARCODEREADER_AF_SUPPORT__ */ 

#ifdef __MMI_BARCODEREADER_AF_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_af_and_capture
 * DESCRIPTION
 *  capture button presse
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_af_and_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__

    #if defined(__MMI_BARCODEREADER_AF_SUPPORT__)
    /* if (g_barcodereader_cntx.setting.af_mode != MMI_BARCODEREADER_SETTING_FOCUS_MODE_MANUAL) */
        mmi_barcodereader_focus_button_press();
    #endif /* defined(__MMI_BARCODEREADER_AF_SUPPORT__) */ 

        mmi_barcodereader_capture_button_press();

#endif /* __MTK_TARGET__ */
}


#endif /* __MMI_BARCODEREADER_AF_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_capture_button_press
 * DESCRIPTION
 *  capture button presse
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_capture_button_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    /* capture only works if camera is ready, otherwise will ignore this action */
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif

    switch (g_barcodereader_cntx.app_state)
    {
        case MMI_BARCODEREADER_STATE_PREVIEW:
            if (mdi_camera_is_ready_to_capture() == TRUE)
            {
                if (g_barcodereader_cntx.is_capturing == FALSE)
                {
                    /* entry capture and decode state */
                #if defined(__MMI_BARCODEREADER_FOCUS_MODE__)
                    if (g_barcodereader_cntx.af_state == MMI_BARCODEREADER_AF_CALCULATE)
                    {
                        g_barcodereader_cntx.is_af_capture = TRUE;
                        mmi_barcodereader_draw_osd();
                        gdi_layer_blt_previous(
                            0,
                            0,
                            g_barcodereader_cntx.base_UI_device_width - 1,
                            g_barcodereader_cntx.base_UI_device_height - 1);

#ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
    mmi_barcodereader_reset_watchdog_time_out_handler();
    mmi_barcodereader_watchdog_time_out_handler();
#endif 
                 
                        return;
                    }
                #endif /* defined(__MMI_BARCODEREADER_FOCUS_MODE__) */ 
                    /* if not self timer, capture the image */

#ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
    mmi_barcodereader_reset_watchdog_time_out_handler();
#endif                 
                    MMI_BARCODEREADER_ENTER_STATE(MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE);
                }
                else
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_READY_TO_CAPTURE);
                    ASSERT(0);
                }
            }
            break;

        case MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE:
            if (g_barcodereader_cntx.is_capturing == TRUE)
            {
                if (g_barcodereader_cntx.af_state == MMI_BARCODEREADER_AF_ONFOCUS)
                {
                    mdi_camera_stop_autofocus_process();
                }
                /* entry preview state */
                mmi_barcodereader_hide_hint();
                MMI_BARCODEREADER_ENTER_STATE(MMI_BARCODEREADER_STATE_PREVIEW);
            }
            else
            {
            #if !defined(__MMI_BARCODEREADER_AF_SUPPORT__)
                gui_cancel_timer(mmi_barcodereader_start_capture_and_decode);
                mmi_barcodereader_hide_hint();
                MMI_BARCODEREADER_ENTER_STATE(MMI_BARCODEREADER_STATE_PREVIEW);
            #else /* !defined(__MMI_BARCODEREADER_AF_SUPPORT__) */ 
                ASSERT(0);
            #endif /* !defined(__MMI_BARCODEREADER_AF_SUPPORT__) */ 
            }

#ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
    mmi_barcodereader_reset_watchdog_time_out_handler();
    mmi_barcodereader_watchdog_time_out_handler();
#endif 
            
            break;
    }
    /* flush key event */
   // ClearKeyEvents();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_capture_button_release
 * DESCRIPTION
 *  capture button release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_capture_button_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* flush all key event */
    ClearKeyEvents();
}

#ifdef __MMI_BARCODEREADER_MF_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_mf_status_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status_change       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_mf_status_change(mmi_barcodereader_mf_status_enum status_change)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_BARCODEREADER_MF_STATUS_FORWARD)
    {
        if (!g_barcodereader_cntx.is_up_arrow_pressed)
        {
        #if defined(__MMI_BARCODEREADER_FOCUS_MODE_MANUAL__)
            mmi_barcodereader_mf_forward();
        #endif 
        }
        g_barcodereader_cntx.is_up_arrow_pressed = TRUE;
    }
    else
    {
        if (!g_barcodereader_cntx.is_down_arrow_pressed)
        {
        #if defined(__MMI_BARCODEREADER_FOCUS_MODE_MANUAL__)
            mmi_barcodereader_mf_backward();
        #endif 
        }
        g_barcodereader_cntx.is_down_arrow_pressed = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_mf_status_revert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status_change       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_mf_status_revert(mmi_barcodereader_mf_status_enum status_change)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_BARCODEREADER_MF_STATUS_FORWARD)
    {
        g_barcodereader_cntx.is_up_arrow_pressed = FALSE;

        g_barcodereader_cntx.touch_mf_inc.is_press = FALSE;

    #ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
        if (g_barcodereader_cntx.is_mf_continue == TRUE)
        {
            g_barcodereader_cntx.is_draw_timer_on = FALSE;
            mmi_barcodereader_mf_stop();
            gui_cancel_timer(mmi_barcodereader_draw_osd_timer);
        }
        else
        {
            mmi_barcodereader_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);
            gui_cancel_timer(mmi_barcodereader_mf_forward_continue);
        }
    #endif /* __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__ */ 
    }
    else
    {
        g_barcodereader_cntx.is_down_arrow_pressed = FALSE;

        g_barcodereader_cntx.touch_mf_dec.is_press = FALSE;

    #ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
        if (g_barcodereader_cntx.is_mf_continue == TRUE)
        {
            g_barcodereader_cntx.is_draw_timer_on = FALSE;
            mmi_barcodereader_mf_stop();
            gui_cancel_timer(mmi_barcodereader_draw_osd_timer);
        }
        else
        {
            mmi_barcodereader_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);
            gui_cancel_timer(mmi_barcodereader_mf_backward_continue);
        }
    #endif /* __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__ */ 
    }
}

#endif /* __MMI_BARCODEREADER_MF_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_storage_hotkey_press
 * DESCRIPTION
 *  delay_timer hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_storage_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
    mmi_barcodereader_reset_watchdog_time_out_handler();
    mmi_barcodereader_watchdog_time_out_handler();
#endif 

    mmi_barcodereader_storage_change(TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_storage_change
 * DESCRIPTION
 *  storage change
 * PARAMETERS
 *  is_next     [IN]        Change storage to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_storage_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    U16 cur_storage = g_barcodereader_cntx.setting.storage;
    U8 current_storage_index = 0;
    U8 total_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.is_storage_path_changed = FALSE;

    mmi_fmgr_get_exist_storage_inline_list(
        (S8) g_barcodereader_cntx.setting.storage,
        &total_num,
        &(g_barcodereader_cntx.drv_inline_list_p),
        (PU8) & current_storage_index);

    /* current_storage_index must <= total_num */
    ASSERT(current_storage_index <= total_num);

    if (is_next)
    {
        if (current_storage_index < total_num - 1)
        {
            current_storage_index++;
        }
        else
        {
            current_storage_index = 0;
        }
    }
    else
    {
        if (current_storage_index >= 1)
        {
            current_storage_index--;
        }
        else
        {
            current_storage_index = total_num - 1;
        }
    }

    mmi_fmgr_get_drive_letter_by_inline_index(current_storage_index, (S8*) & g_barcodereader_cntx.setting.storage);

    if (g_barcodereader_cntx.setting.storage != cur_storage)
    {
        g_barcodereader_cntx.is_storage_path_changed = TRUE;
    }

    if (g_barcodereader_cntx.is_storage_path_changed)
    {
        mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
        mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_GLOBAL_STORAGE));
        mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

        mmi_barcodereader_set_hint(
            (PS8) str_buf,
            (PS8) (((U8 **) (g_barcodereader_cntx.drv_inline_list_p))[current_storage_index]),
            HINT_POPUP_FADE_TIME);
    }

    mmi_barcodereader_store_setting();

        mmi_barcodereader_draw_osd();
        gdi_layer_blt_previous(
            0,
            0,
            g_barcodereader_cntx.base_UI_device_width - 1,
            g_barcodereader_cntx.base_UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_get_storage_file_path
 * DESCRIPTION
 *  get current active storage file path.
 * PARAMETERS
 *  filepath        [IN]        
 *  a(?)            [OUT]       Fill storage full path(?)(?)
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_barcodereader_get_storage_file_path(PS8 filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drv_buf[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_barcodereader_get_storage_disk_path(&g_barcodereader_cntx.setting.storage, drv_buf))
    {
        mmi_ucs2cpy((PS8) filepath, (PS8) drv_buf);
        mmi_ucs2cat((PS8) filepath, (PS8) MMI_BARCODEREADER_STORAGE_FILEPATH_PHONE);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_get_storage_disk_path
 * DESCRIPTION
 *  get current active storage disk path.
 * PARAMETERS
 *  drive       [IN]        
 *  drv_buf     [IN]        
 *  a(?)        [OUT]       Fill disk's name string.(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_barcodereader_get_storage_disk_path(PU16 drive, PS8 drv_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[64];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(buf, "%c:\\", (U8) (*drive));
    mmi_asc_to_ucs2(drv_buf, buf);
    
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_flash_hotkey_press
 * DESCRIPTION
 *  flash hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_BARCODEREADER_FLASH__)
static void mmi_barcodereader_flash_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_barcodereader_flash_change(MMI_TRUE);
    mmi_barcodereader_get_camera_setting_string(
        MMI_BARCODEREADER_CAMERA_SETTING_FLASH,
        g_barcodereader_cntx.hint1_buf,
        g_barcodereader_cntx.hint2_buf);
    g_barcodereader_cntx.fade_time = 100;

#ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
    mmi_barcodereader_reset_watchdog_time_out_handler();
    mmi_barcodereader_watchdog_time_out_handler();
#endif 

    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);
}
#endif /* defined(__MMI_BARCODEREADER_FLASH__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_af_mode_hotkey_press
 * DESCRIPTION
 *  focus mode hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
static void mmi_barcodereader_af_mode_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_barcodereader_focus_mode_change(MMI_TRUE);
    mmi_barcodereader_get_camera_setting_string(
        MMI_BARCODEREADER_CAMERA_SETTING_FOCUS_MODE,
        g_barcodereader_cntx.hint1_buf,
        g_barcodereader_cntx.hint2_buf);
    g_barcodereader_cntx.fade_time = 100;

#ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
    mmi_barcodereader_reset_watchdog_time_out_handler();
    mmi_barcodereader_watchdog_time_out_handler();
#endif 

    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);
}
#endif /* __MMI_BARCODEREADER_AF_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_ev_dec_key_press
 * DESCRIPTION
 *  preview left arrow pressed, adjust EV
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_ev_dec_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW)
    {
        if(!mmi_barcodereader_ev_is_reach_min())
        {
            g_barcodereader_cntx.touch_ev_dec.is_press = TRUE;
            mmi_barcodereader_ev_status_change(MMI_FALSE);
            mmi_barcodereader_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);
            
            if (g_barcodereader_cntx.is_ev_dec_pressed)
            {
                gui_start_timer(100, mmi_barcodereader_ev_dec_key_press);
            }
            else
            {
                /* first time press up arrow, use longer time */
                gui_start_timer(300, mmi_barcodereader_ev_dec_key_press);
                g_barcodereader_cntx.is_ev_dec_pressed = TRUE;
            }

        }

    #ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
        mmi_barcodereader_reset_watchdog_time_out_handler();
    #endif
        
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_ev_dec_key_release
 * DESCRIPTION
 *  preview left arrow release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_ev_dec_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_barcodereader_ev_dec_key_press);

    if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW)
    {
        g_barcodereader_cntx.is_ev_dec_pressed = FALSE;
        g_barcodereader_cntx.touch_ev_dec.is_press = FALSE;
        mmi_barcodereader_draw_osd();
        gdi_layer_blt_previous(
            0,
            0,
            g_barcodereader_cntx.base_UI_device_width - 1,
            g_barcodereader_cntx.base_UI_device_height - 1);

    #ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
        mmi_barcodereader_reset_watchdog_time_out_handler();
        mmi_barcodereader_watchdog_time_out_handler();
    #endif 

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_ev_inc_key_release
 * DESCRIPTION
 *  preview right arrow release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_ev_inc_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_barcodereader_ev_inc_key_press);

    if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW)
    {
        g_barcodereader_cntx.is_ev_inc_pressed = FALSE;
        g_barcodereader_cntx.touch_ev_inc.is_press = FALSE;
        mmi_barcodereader_draw_osd();
        gdi_layer_blt_previous(
            0,
            0,
            g_barcodereader_cntx.base_UI_device_width - 1,
            g_barcodereader_cntx.base_UI_device_height - 1);

    #ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
        mmi_barcodereader_reset_watchdog_time_out_handler();
        mmi_barcodereader_watchdog_time_out_handler();
    #endif 

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_ev_inc_key_press
 * DESCRIPTION
 *  preview right arrow pressed, adjust EV
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_ev_inc_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW)
    {
        if(!mmi_barcodereader_ev_is_reach_max())
        {
            g_barcodereader_cntx.touch_ev_inc.is_press = TRUE;
            mmi_barcodereader_ev_status_change(MMI_TRUE);
            mmi_barcodereader_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);
            
            if (g_barcodereader_cntx.is_ev_inc_pressed)
            {
                gui_start_timer(100, mmi_barcodereader_ev_inc_key_press);
            }
            else
            {
                /* first time press up arrow, use longer time */
                gui_start_timer(300, mmi_barcodereader_ev_inc_key_press);
                g_barcodereader_cntx.is_ev_inc_pressed = TRUE;
            }

        }

    #ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
        mmi_barcodereader_reset_watchdog_time_out_handler();
    #endif
        
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_rsk_press
 * DESCRIPTION
 *  previwe rsk pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.is_rsk_pressed = TRUE;

#ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
    mmi_barcodereader_reset_watchdog_time_out_handler();
#endif

    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_rsk_release
 * DESCRIPTION
 *  previwe rsk released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.is_rsk_pressed = FALSE;

    mmi_barcodereader_draw_osd();

    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);

    /* camera with only 23key, will use RSK to capture */
#ifdef __MMI_CAMERA_23KEY__
    mmi_barcodereader_capture_button_press();
#else 
    GoBackHistory();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_lsk_press
 * DESCRIPTION
 *  previwe lsk pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.is_lsk_pressed = TRUE;

#ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
    mmi_barcodereader_reset_watchdog_time_out_handler();
#endif

    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_lsk_release
 * DESCRIPTION
 *  previwe lsk released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.is_lsk_pressed = FALSE;

    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);

    /* Enter barcode reader camera menu screen */
    mmi_barcodereader_enter_camera_setting_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_preview_start
 * DESCRIPTION
 *  start previewing of main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_preview_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 preview_layer_flag = 0;
    U32 blt_layer_flag = 0;
    S32 preview_wnd_offset_x = 0;
    S32 preview_wnd_offset_y = 0;
    U16 preview_wnd_width = 0;
    U16 preview_wnd_height = 0;
    GDI_HANDLE preview_layer_handle = 0;
    mdi_camera_setting_struct camera_setting_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        return;
    }
#endif

    mmi_barcodereder_init_camera_befor_preview(&camera_setting_data);
    /* mmi_barcodereader_check_flash_status(); */

#ifdef __MMI_BARCODEREADER_FLASH__
        /* check flash status */
        mmi_barcodereader_check_flash_status(); /* turn on/off the flash */
#endif

    preview_layer_handle = g_barcodereader_cntx.preview_layer_handle;

    /* use preview wnd's position */
    preview_wnd_offset_x = g_barcodereader_cntx.active_barcodereader_osd_ptr->preview_wnd.offset_x;
    preview_wnd_offset_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->preview_wnd.offset_y;
    preview_wnd_width = g_barcodereader_cntx.preview_width;
    preview_wnd_height = g_barcodereader_cntx.preview_height;

    /* preview (hw), OSD */
    blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
    preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;

    /* it is just use for 6219 serial
    blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
    preview_layer_flag = GDI_LAYER_ENABLE_LAYER_1;
    */


    g_barcodereader_cntx.last_error.error_result = MDI_RES_CAMERA_SUCCEED;
    g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_CAMERA;
    g_barcodereader_cntx.last_error.tone_id = WARNING_TONE;
    g_barcodereader_cntx.last_error.error_result
        = mdi_camera_barcodereader_preview_start(
            preview_layer_handle,
            preview_wnd_offset_x,
            preview_wnd_offset_y,
            preview_wnd_width,
            preview_wnd_height,
            blt_layer_flag,
            preview_layer_flag,
            GDI_COLOR_TRANSPARENT,
            TRUE,
            &camera_setting_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_hide_hint
 * DESCRIPTION
 *  hide hint
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_hide_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_barcodereader_set_hint(NULL, NULL, 255);
    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_softkey
 * DESCRIPTION
 *  draw preview softkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_draw_softkey(void)
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
    PS8 str_ptr;
    U16 lsk_id;
    U16 rsk_id;
    S32 lsk_truncated_width;
    S32 rsk_truncated_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lsk_id = STR_GLOBAL_SETTINGS;

    /* if only have 23key, use rsk to capture */
#ifdef __MMI_CAMERA_23KEY__
    rsk_id = STR_ID_BARCODEREADER_RSK_CAPTURE;
#else 
    rsk_id = STR_GLOBAL_BACK;
#endif 

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_BUTTON));

    /* lsk */
    str_ptr = (PS8) GetString(lsk_id);

    gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
    wgui_softkey_get_offset(
        (UI_string_type) str_ptr,
        &lsk_offset_x, 
        &lsk_offset_y, 
        &lsk_truncated_width,
        MMI_LEFT_SOFTKEY,
        mmi_frm_get_screen_rotate());

    if (r2lMMIFlag)
    {
        lsk_offset_x -= str_width;
    }

    if (g_barcodereader_cntx.is_lsk_pressed)
    {
        lsk_offset_x++;
        lsk_offset_y++;
    }

    mmi_barcodereader_draw_style_text(
        str_ptr,
        lsk_offset_x,
        lsk_offset_y,
        lsk_truncated_width,
        &g_barcodereader_cntx.active_barcodereader_osd_ptr->softkey.lsk);

    g_barcodereader_cntx.touch_lsk.offset_x = lsk_offset_x;
    g_barcodereader_cntx.touch_lsk.offset_y = lsk_offset_y;
    if(str_width > (MMI_SOFTKEY_WIDTH - MMI_UI_SOFTKEY_GAP))
    {
        g_barcodereader_cntx.touch_lsk.width = (MMI_SOFTKEY_WIDTH - MMI_UI_SOFTKEY_GAP);
    }
    else
    {
        g_barcodereader_cntx.touch_lsk.width = str_width;
    }
    g_barcodereader_cntx.touch_lsk.height = str_height;

    /* rsk */
    str_ptr = (PS8) GetString(rsk_id);

    gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
    wgui_softkey_get_offset(
        (UI_string_type) str_ptr, 
        &rsk_offset_x, 
        &rsk_offset_y, 
        &rsk_truncated_width, 
        MMI_RIGHT_SOFTKEY,
        mmi_frm_get_screen_rotate());

    if (r2lMMIFlag)
    {
        rsk_offset_x -= str_width;
    }

    if (g_barcodereader_cntx.is_rsk_pressed)
    {
        rsk_offset_x++;
        rsk_offset_y++;
    }

    mmi_barcodereader_draw_style_text(
        str_ptr,
        rsk_offset_x,
        rsk_offset_y,
        rsk_truncated_width,
        &g_barcodereader_cntx.active_barcodereader_osd_ptr->softkey.rsk);

    g_barcodereader_cntx.touch_rsk.offset_x = rsk_offset_x;
    g_barcodereader_cntx.touch_rsk.offset_y = rsk_offset_y;
    if(str_width > (MMI_SOFTKEY_WIDTH - MMI_UI_SOFTKEY_GAP))
    {
        g_barcodereader_cntx.touch_rsk.width = (MMI_SOFTKEY_WIDTH - MMI_UI_SOFTKEY_GAP);
    }
    else
    {
        g_barcodereader_cntx.touch_rsk.width = str_width;
    }
    g_barcodereader_cntx.touch_rsk.height = str_height;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_title
 * DESCRIPTION
 *  draw preview title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_draw_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if not fullscreen and need title */
    if (g_barcodereader_cntx.active_barcodereader_osd_ptr->title.is_draw_mmi_title_bar &&
        g_barcodereader_cntx.active_barcodereader_osd_ptr->title.is_draw_mmi_caption)
    {
        gdi_layer_lock_frame_buffer();

        show_title_status_icon();
        wgui_title_change(
            GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
            0,
            (U8*) GetString(STR_ID_BARCODEREADER_APP_NAME),
            WGUI_TITLE_CHANGE_ICON | WGUI_TITLE_CHANGE_TEXT);
        wgui_title_set_style(GUI_TITLE_STYLE_DISABLEBG);
        draw_title();
        wgui_title_unset_style(GUI_TITLE_STYLE_DISABLEBG);
        gdi_layer_unlock_frame_buffer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_hint
 * DESCRIPTION
 *  draw preview OSD panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_draw_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str1_width;
    S32 str1_height;
    S32 str2_width;
    S32 str2_height;
    S32 str1_offset_x;
    S32 str1_offset_y;
    S32 str2_offset_x;
    S32 str2_offset_y;
    S32 spacing;
    PS8 hint_str1;
    PS8 hint_str2;

    S32 offset_x = 0;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear hint background region */

    gui_set_font(&MMI_medium_font);

    /* draw hint */
    if (g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.is_show)
    {
        hint_str1 = g_barcodereader_cntx.hint1_buf;
        hint_str2 = g_barcodereader_cntx.hint2_buf;

        /* be removed : clear hint backgounrd */

        gui_set_text_clip(
            g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.offset_x,
            g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.offset_y,
            g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.offset_x + g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.width - 1,
            g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.offset_y + g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.height - 1);

        gui_measure_string((UI_string_type) hint_str1, &str1_width, &str1_height);
        gui_measure_string((UI_string_type) hint_str2, &str2_width, &str2_height);

        str1_offset_x = (g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.width - str1_width) >> 1;

        spacing = g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.height - str1_height - str2_height;
        spacing = (spacing > 0) ? (spacing / 3 + 1) : 0;

        str1_offset_y = spacing;
        str2_offset_y = str1_offset_y + spacing + str1_height;
        str2_offset_x = (g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.width - str2_width) >> 1;

        gdi_layer_reset_clip();
        gui_reset_text_clip();

        mmi_barcodereader_draw_style_text(
            hint_str1,
            g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.offset_x + str1_offset_x - offset_x,
            g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.offset_y + str1_offset_y - offset_y,
            0,
            &g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.style_text);

        mmi_barcodereader_draw_style_text(
            hint_str2,
            g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.offset_x + str2_offset_x - offset_x,
            g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.offset_y + str2_offset_y - offset_y,
            0,
            &g_barcodereader_cntx.active_barcodereader_osd_ptr->hint_box.style_text);

        if (g_barcodereader_cntx.fade_time != 0 && g_barcodereader_cntx.fade_time != 255)
        {
            gui_start_timer(HINT_POPUP_FADE_TIME, mmi_barcodereader_hide_hint);
            g_barcodereader_cntx.fade_time = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_icon
 * DESCRIPTION
 *  draw preview OSD panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_draw_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x = 0;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /*****************************************************
   *  define MACRO
   *****************************************************/
    g_barcodereader_cntx.setting.af_mode = mmi_barcodereader_get_focus_mode_value();
    g_barcodereader_cntx.setting.ev = mmi_barcodereader_get_ev_value();
    g_barcodereader_cntx.setting.flash = mmi_barcodereader_get_flash_value();
    g_barcodereader_cntx.setting.banding = mmi_barcodereader_get_banding_value();

#define DRAW_OSD_ICON(a,A)                                                                                   \
   do {                                                                                                      \
      if(g_barcodereader_cntx.active_barcodereader_osd_ptr->##a##.is_show)                                   \
      {                                                                                                      \
         gdi_image_draw_id(g_barcodereader_cntx.active_barcodereader_osd_ptr->##a##.offset_x,                \
                           g_barcodereader_cntx.active_barcodereader_osd_ptr->##a##.offset_y,                \
                           (U16)(IMG_ID_BARCODEREADER_OSD_##A##_START+g_barcodereader_cntx.setting.##a##+1));\
      }                                                                                                      \
   } while(0);

    if (!g_barcodereader_cntx.is_hide_osd)
    {
        /* draw icon */
    #ifdef __MMI_BARCODEREADER_FLASH__
        DRAW_OSD_ICON(flash, FLASH);
    #endif 

    #ifdef __MMI_BARCODEREADER_FOCUS_MODE__
        DRAW_OSD_ICON(af_mode, FOCUS_MODE);
    #endif 

    #ifdef __MMI_BARCODEREADER_STORAGE__
        if (g_barcodereader_cntx.active_barcodereader_osd_ptr->storage.is_show)
        {
            U8 drive_enum;
            U16 image_id;

            mmi_fmgr_get_drive_enum_by_letter((S8)g_barcodereader_cntx.setting.storage, (PS8)&drive_enum);
            switch (drive_enum)
            {
            case FMGR_NAND_STORAGE:
            case FMGR_NOR_STORAGE:
                image_id = IMG_ID_BARCODEREADER_OSD_STORAGE_PHONE;
                break;

            case FMGR_REMOVABLE_STORAGE:
                image_id = IMG_ID_BARCODEREADER_OSD_STORAGE_MEMORY_CARD;
                break;

#ifdef __OTG_ENABLE__
            case FMGR_OTG_1_STORAGE:
            case FMGR_OTG_2_STORAGE:
            case FMGR_OTG_3_STORAGE:
            case FMGR_OTG_4_STORAGE:
            case FMGR_OTG_5_STORAGE:
            case FMGR_OTG_6_STORAGE:
            case FMGR_OTG_7_STORAGE:
            case FMGR_OTG_8_STORAGE:                
                image_id = drive_enum - FMGR_OTG_1_STORAGE + IMG_ID_BARCODEREADER_OSD_STORAGE_OTG_1;
                break;
#endif

            default:
                image_id = IMG_ID_BARCODEREADER_OSD_STORAGE_MEMORY_CARD;
            }

            gdi_image_draw_id(
                g_barcodereader_cntx.active_barcodereader_osd_ptr->storage.offset_x - offset_x,
                g_barcodereader_cntx.active_barcodereader_osd_ptr->storage.offset_y - offset_y,
                (U16) (image_id));       
        }
    #endif /* __MMI_BARCODEREADER_STORAGE__ */ 

        /* ev */
        DRAW_OSD_ICON(ev, EV);

        if (g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_inc.is_show)
        {
            if (mmi_barcodereader_ev_is_reach_max())
            {
                gdi_image_draw_id(
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_inc.offset_x - offset_x,
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_inc.offset_y - offset_y,
                    (U16) (IMG_ID_BARCODEREADER_OSD_EV_MAX));
            }
            else
            {
            if (g_barcodereader_cntx.touch_ev_inc.is_press)
            {
                gdi_image_draw_id(
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_inc.offset_x - offset_x,
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_inc.offset_y - offset_y,
                    (U16) (IMG_ID_BARCODEREADER_OSD_EV_INC_SEL));
            }
            else
            {
                gdi_image_draw_id(
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_inc.offset_x - offset_x,
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_inc.offset_y - offset_y,
                    (U16) (IMG_ID_BARCODEREADER_OSD_EV_INC));
            }
        }
        }

        if (g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_dec.is_show)
        {
            if (mmi_barcodereader_ev_is_reach_min())
            {
                gdi_image_draw_id(
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_dec.offset_x - offset_x,
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_dec.offset_y - offset_y,
                    (U16) (IMG_ID_BARCODEREADER_OSD_EV_MIN));
            }
            else
            {
            if (g_barcodereader_cntx.touch_ev_dec.is_press)
            {
                gdi_image_draw_id(
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_dec.offset_x - offset_x,
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_dec.offset_y - offset_y,
                    (U16) (IMG_ID_BARCODEREADER_OSD_EV_DEC_SEL));
            }
            else
            {
                gdi_image_draw_id(
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_dec.offset_x - offset_x,
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->ev_dec.offset_y - offset_y,
                    (U16) (IMG_ID_BARCODEREADER_OSD_EV_DEC));
            }
        }
        }

    #ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
        if (g_barcodereader_cntx.setting.af_mode == MMI_BARCODEREADER_SETTING_FOCUS_MODE_MANUAL)
        {
            S32 bar_width, bar_height, slider_x, slider_y, slider_width, slider_height;
            U8 total_idx, current_idx;

            gdi_image_draw_id(
                g_barcodereader_cntx.active_barcodereader_osd_ptr->mf.offset_x - offset_x,
                g_barcodereader_cntx.active_barcodereader_osd_ptr->mf.offset_y - offset_y,
                IMG_ID_BARCODEREADER_OSD_MF_BAR);

            /* CALCULATE THE SLIDER LOACTION AND DRAW */
            if (g_barcodereader_cntx.is_mf_continue == TRUE)
            {
                mdi_camera_get_focus_steps(&(g_barcodereader_cntx.mf_level_cnt), &(g_barcodereader_cntx.mf_level_idx));
            }

            total_idx = (U8) g_barcodereader_cntx.mf_level_cnt;
            current_idx = (U8) g_barcodereader_cntx.mf_level_idx;

            gdi_image_get_dimension_id(IMG_ID_BARCODEREADER_OSD_MF_BAR, &bar_width, &bar_height);
            gdi_image_get_dimension_id(IMG_ID_BARCODEREADER_OSD_MF_SLIDER, &slider_width, &slider_height);

            slider_x =
                g_barcodereader_cntx.active_barcodereader_osd_ptr->mf.offset_x - (S32) (slider_width - bar_width) / 2;

            if (current_idx == total_idx)
            {
                slider_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->mf.offset_y;
            }
            else if (current_idx == 0)
            {
                slider_y = g_barcodereader_cntx.active_barcodereader_osd_ptr->mf.offset_y + bar_height - slider_height;
            }
            else
            {
                slider_y =
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->mf.offset_y + (total_idx -
                                                                                      current_idx) * (bar_height -
                                                                                                      slider_height) /
                    total_idx;

            }

            gdi_image_draw_id(slider_x - offset_x, slider_y - offset_y, IMG_ID_BARCODEREADER_OSD_MF_SLIDER);

            if (g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_inc.is_show)
            {
                if (g_barcodereader_cntx.touch_mf_inc.is_press)
                {
                    gdi_image_draw_id(
                        g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_inc.offset_x - offset_x,
                        g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_inc.offset_y - offset_y,
                        (U16) (IMG_ID_BARCODEREADER_OSD_MF_INC_SEL));
                }
                else
                {
                    gdi_image_draw_id(
                        g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_inc.offset_x - offset_x,
                        g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_inc.offset_y - offset_y,
                        (U16) (IMG_ID_BARCODEREADER_OSD_MF_INC));
                }
            }

            if (g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_dec.is_show)
            {

                if (g_barcodereader_cntx.touch_mf_dec.is_press)
                {
                    gdi_image_draw_id(
                        g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_dec.offset_x - offset_x,
                        g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_dec.offset_y - offset_y,
                        (U16) (IMG_ID_BARCODEREADER_OSD_MF_DEC_SEL));
                }
                else
                {
                    gdi_image_draw_id(
                        g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_dec.offset_x - offset_x,
                        g_barcodereader_cntx.active_barcodereader_osd_ptr->mf_dec.offset_y - offset_y,
                        (U16) (IMG_ID_BARCODEREADER_OSD_MF_DEC));
                }
            }
        }
    #endif /* __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__ */ 
    }

    /* capture icon */
    if (g_barcodereader_cntx.active_barcodereader_osd_ptr->capture.is_show)
    {
        if (g_barcodereader_cntx.is_capturing || g_barcodereader_cntx.is_af_capture)
        {
            gdi_image_draw_id(
                g_barcodereader_cntx.active_barcodereader_osd_ptr->capture.offset_x - offset_x,
                g_barcodereader_cntx.active_barcodereader_osd_ptr->capture.offset_y - offset_y,
                (U16) (IMG_ID_BARCODEREADER_OSD_CAPTURE_SEL));
        }
        else
        {
            gdi_image_draw_id(
                g_barcodereader_cntx.active_barcodereader_osd_ptr->capture.offset_x - offset_x,
                g_barcodereader_cntx.active_barcodereader_osd_ptr->capture.offset_y - offset_y,
                (U16) (IMG_ID_BARCODEREADER_OSD_CAPTURE));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_osd
 * DESCRIPTION
 *  draw preview osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_draw_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_FALSE);
#endif

    gdi_layer_push_and_set_active(g_barcodereader_cntx.osd_layer_handle);
    /* toggle double buffer */
    gdi_layer_toggle_double();
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    /* draw background */
    gdi_image_draw_id(0, 0, IMG_ID_BARCODEREADER_PREVIEW_BACKGROUND);

#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
    /* if(g_barcodereader_cntx.is_autofocus_pressed == TRUE) */
    mmi_barcodereader_draw_focus_process();
#endif /* __MMI_BARCODEREADER_FOCUS_MODE__ */ 
    mmi_barcodereader_draw_softkey();
    mmi_barcodereader_draw_title();

    if (g_barcodereader_cntx.fade_time != 255)
    {
        mmi_barcodereader_draw_hint();
        g_barcodereader_cntx.fade_time = 0;
    }

    mmi_barcodereader_draw_icon();

    gdi_layer_pop_and_restore_active();

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_TRUE);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_preview_clear_background
 * DESCRIPTION
 *  clear backgroud of preview screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_preview_clear_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color bg_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_barcodereader_cntx.base_layer_handle);

    if (g_barcodereader_cntx.active_barcodereader_osd_ptr->bg.is_draw_bg_color)
    {
        bg_color = GDI_RGB_TO_BUFFER_FORMAT(
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->bg.r,
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->bg.g,
                    g_barcodereader_cntx.active_barcodereader_osd_ptr->bg.b);

        gdi_layer_clear(bg_color);
    }

    if (g_barcodereader_cntx.active_barcodereader_osd_ptr->bg.is_draw_bg_image)
    {
        gdi_image_draw_id(0, 0, IMG_ID_BARCODEREADER_PREVIEW_BACKGROUND);
    }

    if (!g_barcodereader_cntx.active_barcodereader_osd_ptr->bg.is_draw_bg_color &&
        !g_barcodereader_cntx.active_barcodereader_osd_ptr->bg.is_draw_bg_image)
    {
        gdi_layer_clear(GDI_COLOR_BLACK);
    }

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_set_hint
 * DESCRIPTION
 *  set hint string
 * PARAMETERS
 *  hint_str1       [IN]        String 1
 *  hint_str2       [IN]        String 2
 *  fade_time       [IN]        Hint fade out time
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_set_hint(PS8 hint_str1, PS8 hint_str2, U16 fade_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear buffer */
    memset(g_barcodereader_cntx.hint1_buf, 0, BR_HINT_BUFFER_SIZE);
    memset(g_barcodereader_cntx.hint2_buf, 0, BR_HINT_BUFFER_SIZE);

    if (hint_str1 != NULL)
    {
        mmi_ucs2ncpy((PS8) g_barcodereader_cntx.hint1_buf, (PS8) hint_str1, (BR_HINT_BUFFER_SIZE / ENCODING_LENGTH) - 1);
    }

    if (hint_str2 != NULL)
    {
        mmi_ucs2ncpy((PS8) g_barcodereader_cntx.hint2_buf, (PS8) hint_str2, (BR_HINT_BUFFER_SIZE / ENCODING_LENGTH) - 1);
    }

    g_barcodereader_cntx.fade_time = fade_time;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_free_resource
 * DESCRIPTION
 *  free main lcd's preview layer resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_free_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


   /****** free osd layer ******/
    if (g_barcodereader_cntx.osd_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        wgui_status_icon_bar_set_target_layer(WGUI_STATUS_ICON_BAR_H_BAR, GDI_ERROR_HANDLE);
        gdi_layer_free(g_barcodereader_cntx.osd_layer_handle);
        g_barcodereader_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;

        mmi_frm_scrmem_free((void*)g_barcodereader_cntx.osd_layer_buf_ptr);
        g_barcodereader_cntx.osd_layer_buf_ptr = NULL;
    }

   /****** preview layer ******/
    mmi_barcodereader_free_preview_resource();
    g_barcodereader_cntx.is_mainlcd_resource = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_current_state
 * DESCRIPTION
 *  exit function handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_exit_current_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_barcodereader_cntx.app_state)
    {
        case MMI_BARCODEREADER_STATE_EXIT:
            /* do nothing */
            break;

        case MMI_BARCODEREADER_STATE_PREVIEW:
            mmi_barcodereader_exit_preview_state();
            break;

        case MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE:
            mmi_barcodereader_exit_capture_and_decode_state();
            break;

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_enter_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_enter_state(barcodereader_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.app_prev_state = g_barcodereader_cntx.app_state;
    g_barcodereader_cntx.app_state = state;

    switch (state)
    {
        case MMI_BARCODEREADER_STATE_EXIT:
            /* do nothing */
            break;

        case MMI_BARCODEREADER_STATE_PREVIEW:
            mmi_barcodereader_enter_preview_state();
            break;

        case MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE:
            mmi_barcodereader_enter_capture_and_decode_state();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_free_preview_resource
 * DESCRIPTION
 *  create preview resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_free_preview_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.preview_layer_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        return;
    }
    gdi_layer_free(g_barcodereader_cntx.preview_layer_handle);
    g_barcodereader_cntx.preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_create_preview_resource
 * DESCRIPTION
 *  create preview resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_create_preview_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 buf_ptr;
    S32 buf_size;

    S32 offset_x = 0;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /************ preview layer ************/
#ifdef __MMI_HORIZONTAL_BARCODEREADER__
    offset_x = MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y;
    offset_y = MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X;
#else /* __MMI_HORIZONTAL_BARCODEREADER__ */ 
    /* offset_y = (LCD_HEIGHT - g_barcodereader_cntx.preview_height)>>1; */
    offset_x = MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X;
    offset_y = MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y;
#endif /* __MMI_HORIZONTAL_BARCODEREADER__ */ 

    ASSERT(g_barcodereader_cntx.preview_width * g_barcodereader_cntx.preview_height <= LCD_WIDTH * LCD_HEIGHT);

    gdi_layer_push_and_set_active(g_barcodereader_cntx.base_layer_handle);
    gdi_layer_get_buffer_ptr(&buf_ptr);

    buf_size =
        ((g_barcodereader_cntx.preview_width * g_barcodereader_cntx.preview_height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3);
    gdi_layer_create_using_outside_memory(
        0,
        0,
        g_barcodereader_cntx.preview_width,
        g_barcodereader_cntx.preview_height,
        &g_barcodereader_cntx.preview_layer_handle,
        (PU8) buf_ptr,
        buf_size);

    gdi_layer_set_active(g_barcodereader_cntx.preview_layer_handle);
#ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_BLACK);
#endif 
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_set_position(offset_x, offset_y);
    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcoderader_malloc_memory_and_create_adm_resource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcoderader_malloc_memory_and_create_adm_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.app_mem_pool == NULL)
    {
        g_barcodereader_cntx.app_mem_pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_BARCODEREADER, BR_APP_TOTAL_SIZE);

        if (g_barcodereader_cntx.app_mem_pool == NULL)
        {
            g_barcodereader_cntx.entry_app_callback = mmi_barcodereader_enter_preview_screen;
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_BARCODEREADER,
                IMG_ID_BARCODEREADER_APP_ICON,
                BR_APP_TOTAL_SIZE,
                mmi_barcodereader_app_mem_success_callback);
            return;
        }

    }

    /* create adm related resource */
    mmi_barcodereader_create_adm_resource();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcoderader_free_memory_and_destory_adm_resource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcoderader_free_memory_and_destory_adm_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_barcodereader_free_adm_resource();

    ASSERT(g_barcodereader_cntx.app_mem_pool != NULL);

    /* free app-based memory */
    applib_mem_ap_free((void*)g_barcodereader_cntx.app_mem_pool);
    g_barcodereader_cntx.app_mem_pool = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_enter_preview_state
 * DESCRIPTION
 *  entry of preview state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_enter_preview_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize preview data */

    switch (g_barcodereader_cntx.app_prev_state)
    {
        case MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE:
            /* register keys */
            mmi_barcodereader_preview_set_key_hdlr();

            /* register touch */
        #if defined(__MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__)
            wgui_register_pen_down_handler(mmi_barcodereader_touch_scr_pen_down_hdlr);
            wgui_register_pen_up_handler(mmi_barcodereader_touch_scr_pen_up_hdlr);
            wgui_register_pen_move_handler(mmi_barcodereader_touch_scr_pen_move_hdlr);
        #endif /* defined(__MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__) */ 

            /* draw panel and softkey */
            mmi_barcodereader_draw_osd();

            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);
            break;

            /* if enter from EXIT */
        case MMI_BARCODEREADER_STATE_EXIT:
        	  if (mmi_is_redrawing_bk_screens())
            {
            	  return;
            }
        	 
            g_barcodereader_cntx.is_lsk_pressed = FALSE;
            g_barcodereader_cntx.is_rsk_pressed = FALSE;
            g_barcodereader_cntx.is_up_arrow_pressed = FALSE;
            g_barcodereader_cntx.is_down_arrow_pressed = FALSE;

            g_barcodereader_cntx.is_capturing = FALSE;
            g_barcodereader_cntx.is_draw_timer_on = FALSE;
    #ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
            g_barcodereader_cntx.is_mf_continue = FALSE;
    #endif 
            g_barcodereader_cntx.touch_flash.is_press = FALSE;
            g_barcodereader_cntx.touch_ev_inc.is_press = FALSE;
            g_barcodereader_cntx.touch_ev_dec.is_press = FALSE;
            g_barcodereader_cntx.touch_mf_inc.is_press = FALSE;
            g_barcodereader_cntx.touch_mf_dec.is_press = FALSE;
            g_barcodereader_cntx.touch_capture.is_press = FALSE;
            g_barcodereader_cntx.touch_af_mode.is_press = FALSE;

            /* load mdi_camera default data */
    #ifdef CAMERA_MODULE_WITH_LCD
            gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
    #endif 

    #ifdef __MMI_SUBLCD__
            /* draw sublcd icon */
            mmi_barcodereader_sublcd_draw_icon();
    #endif /* __MMI_SUBLCD__ */ 

            /* init title bar */
            if (g_barcodereader_cntx.active_barcodereader_osd_ptr->title.is_draw_mmi_title_bar)
            {
            #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
                reset_title_status_icon();
                wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
            #endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 

                /* hide short cut */
                wgui_title_set_menu_shortcut_number(-1);

                if (g_barcodereader_cntx.active_barcodereader_osd_ptr->title.is_draw_mmi_caption)
                {
                    ChangeTitle(
                        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
                        (PU8) GetString(STR_ID_BARCODEREADER_APP_NAME));
                }
                else
                {
                    ChangeTitle(0, (PU8) GetString(STR_ID_BARCODEREADER_APP_NAME));
                }
            }
            else
            {
            #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
                wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);
            #endif 
            }


            /* clear base layer bg */
            mmi_barcodereader_preview_clear_background();

            /* draw panel and softkey */
#if defined(__MMI_BACKGROUND_CALL__)
        if (srv_ucm_is_background_call())
        {
            mmi_barcodereader_set_hint((PS8) GetString(STR_GLOBAL_NOT_AVAILABLE), NULL, 0);   
            mmi_barcodereader_draw_osd();

            /* register keys */
            mmi_barcodereader_preview_set_backgroundcall_key_hdlr();

            /* set blt layer for non-previwing, and blt first skin */
            mmi_barcodereader_preview_set_blt_layer(FALSE);
            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);

            return;
        }
        
#endif 
            mmi_barcodereader_set_hint(NULL, NULL, 0);
            mmi_barcodereader_draw_osd();

            /* register keys */
            mmi_barcodereader_preview_set_key_hdlr();

            /* register touch */
        #if defined(__MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__)
            wgui_register_pen_down_handler(mmi_barcodereader_touch_scr_pen_down_hdlr);
            wgui_register_pen_up_handler(mmi_barcodereader_touch_scr_pen_up_hdlr);
            wgui_register_pen_move_handler(mmi_barcodereader_touch_scr_pen_move_hdlr);
        #endif /* defined(__MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__) */ 
        
            /* set blt layer for non-previwing, and blt first skin */
            mmi_barcodereader_preview_set_blt_layer(FALSE);
            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);

            /* check if any error occurs in mmi_barcodereader_enter_preview_screen function */
            if (g_barcodereader_cntx.last_error.error_result != MDI_RES_CAMERA_SUCCEED)
            {
                mmi_barcodereader_display_error_popup(
                    g_barcodereader_cntx.last_error.error_result,
                    g_barcodereader_cntx.last_error.error_type,
                    g_barcodereader_cntx.last_error.tone_id);
                return;
            }
            else
            {
                /* if no error occurs, start preview */
                mmi_barcodereader_preview_set_blt_layer(TRUE);
                mmi_barcodereader_preview_start();
            #ifdef __MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__
            #ifdef __MMI_BARCODEREADER_AF_SUPPORT__
                mmi_barcodereader_af_and_capture();
            #else 
                gui_start_timer(200, mmi_barcodereader_capture_button_press);
            #endif 
            #endif /* __MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__ */ 
            }

            /* check if preview success */
            if (g_barcodereader_cntx.last_error.error_result != MDI_RES_CAMERA_SUCCEED)
            {
                mmi_barcodereader_display_error_popup(
                    g_barcodereader_cntx.last_error.error_result,
                    g_barcodereader_cntx.last_error.error_type,
                    g_barcodereader_cntx.last_error.tone_id);
                DeleteScreenIfPresent(SCR_ID_BARCODEREADER_PREVIEW);                
            }
            break;
    }

#ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
    mmi_barcodereader_reset_watchdog_time_out_handler();
    mmi_barcodereader_watchdog_time_out_handler();
#endif 
    
}


#ifdef __MMI_BACKGROUND_CALL__
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_preview_set_backgroundcall_key_hdlr
 * DESCRIPTION
 *  set key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_preview_set_backgroundcall_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_KEY);
    ClearKeyEvents();
    /* register soft keys */
    SetKeyHandler(mmi_barcodereader_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_barcodereader_lsk_release, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_barcodereader_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_barcodereader_rsk_release, KEY_RSK, KEY_EVENT_UP);

    /* register capture and control keys */
    if (MMI_BARCODEREADER_CAPTURE_KEY != -1)
    {

    #ifdef __MMI_BARCODEREADER_AF_SUPPORT__
        SetKeyHandler(mmi_barcodereader_af_and_capture, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_DOWN);
    #else 
        SetKeyHandler(mmi_barcodereader_capture_button_press, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_DOWN);
    #endif 
        SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_barcodereader_capture_button_release, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_UP);
    }

    if (MMI_BARCODEREADER_CAPTURE_EXTRA_KEY != -1)
    {

    #ifdef __MMI_BARCODEREADER_AF_SUPPORT__
        SetKeyHandler(mmi_barcodereader_af_and_capture, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_DOWN);
    #else 
        SetKeyHandler(mmi_barcodereader_capture_button_press, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_DOWN);
    #endif 
        SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_barcodereader_capture_button_release, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_UP);
    }


}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_preview_set_key_hdlr
 * DESCRIPTION
 *  set key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_preview_set_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_KEY);
    ClearKeyEvents();
    /* register soft keys */
    SetKeyHandler(mmi_barcodereader_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_barcodereader_lsk_release, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_barcodereader_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_barcodereader_rsk_release, KEY_RSK, KEY_EVENT_UP);

    /* register capture and control keys */
    if (MMI_BARCODEREADER_CAPTURE_KEY != -1)
    {

    #ifdef __MMI_BARCODEREADER_AF_SUPPORT__
        SetKeyHandler(mmi_barcodereader_af_and_capture, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_DOWN);
    #else 
        SetKeyHandler(mmi_barcodereader_capture_button_press, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_DOWN);
    #endif 
        SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_barcodereader_capture_button_release, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_UP);
    }

    if (MMI_BARCODEREADER_CAPTURE_EXTRA_KEY != -1)
    {

    #ifdef __MMI_BARCODEREADER_AF_SUPPORT__
        SetKeyHandler(mmi_barcodereader_af_and_capture, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_DOWN);
    #else 
        SetKeyHandler(mmi_barcodereader_capture_button_press, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_DOWN);
    #endif 
        SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_barcodereader_capture_button_release, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_UP);
    }

    /* ev */
    if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_90 ||
        g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
    {
        SetKeyHandler(mmi_barcodereader_ev_inc_key_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_barcodereader_ev_inc_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);

        SetKeyHandler(mmi_barcodereader_ev_dec_key_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_barcodereader_ev_dec_key_release, KEY_UP_ARROW, KEY_EVENT_UP);

        SetKeyHandler(mmi_barcodereader_dummy_func, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_barcodereader_dummy_func, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    }
    else
    {
        SetKeyHandler(mmi_barcodereader_ev_inc_key_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_barcodereader_ev_inc_key_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);

        SetKeyHandler(mmi_barcodereader_ev_dec_key_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_barcodereader_ev_dec_key_release, KEY_LEFT_ARROW, KEY_EVENT_UP);

        SetKeyHandler(mmi_barcodereader_dummy_func, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_barcodereader_dummy_func, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);        
    }

#ifdef __MMI_BARCODEREADER_FLASH__
    if (MMI_BARCODEREADER_FLASH_KEY != -1)
    {
        SetKeyHandler(mmi_barcodereader_flash_hotkey_press, (U16) MMI_BARCODEREADER_FLASH_KEY, KEY_EVENT_DOWN);
    }
#endif /* __MMI_BARCODEREADER_FLASH__ */ 

#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
    if (MMI_BARCODEREADER_FOCUS_MODE_KEY != -1)
    {
        SetKeyHandler(mmi_barcodereader_af_mode_hotkey_press, (U16) MMI_BARCODEREADER_FOCUS_MODE_KEY, KEY_EVENT_DOWN);
    }
#endif /* __MMI_BARCODEREADER_FOCUS_MODE__ */ 

#ifdef __MMI_BARCODEREADER_STORAGE__
    if (MMI_BARCODEREADER_STORAGE_KEY != -1)
    {
        SetKeyHandler(mmi_barcodereader_storage_hotkey_press, (U16) MMI_BARCODEREADER_STORAGE_KEY, KEY_EVENT_DOWN);
    }
#endif /* __MMI_BARCODEREADER_STORAGE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_preview_set_blt_layer
 * DESCRIPTION
 *  set blt layer based on current status (ex: is previwing, has add frame, etc )
 * PARAMETERS
 *  is_previewing       [IN]        Is preview flag
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_preview_set_blt_layer(BOOL is_previewing)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (is_previewing)
    {
        /* (1) previwing */
        gdi_layer_set_blt_layer(g_barcodereader_cntx.preview_layer_handle, g_barcodereader_cntx.osd_layer_handle, 0, 0);
    }
    else
    {
        gdi_layer_set_blt_layer(g_barcodereader_cntx.base_layer_handle, g_barcodereader_cntx.osd_layer_handle, 0, 0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_preview_state
 * DESCRIPTION
 *  exit of preview state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_exit_preview_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free preview resource */
    switch (g_barcodereader_cntx.app_next_state)
    {
        case MMI_BARCODEREADER_STATE_EXIT:
            mmi_barcodereader_preview_stop();
            break;
    }
}

#if defined(__MMI_BARCODEREADER_AF_SUPPORT__) && defined(__MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__)


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_re_focus_press
 * DESCRIPTION
 *  do focus process again
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_re_focus_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_barcodereader_capture_button_press();
    mmi_barcodereader_af_and_capture();
}
#endif /* defined(__MMI_BARCODEREADER_AF_SUPPORT__) && defined(__MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__) */ 

#if !defined(__MMI_BARCODEREADER_AF_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_start_capture_and_decode
 * DESCRIPTION
 *  entry of capture_and_decode state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_start_capture_and_decode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.b_stop_decode = MMI_FALSE;
    gui_start_timer(MMI_BARCODEREADER_DECODE_TIME, mmi_barcodereader_decode_listen_timer);
    mdi_camera_capture_and_decode_barcode(
        g_barcodereader_cntx.decode_text,
        BR_VERSION_ONE_SLOT_BUFFER_SIZE - ENCODING_LENGTH,
        mmi_barcodereader_decode_result_hdlr,
        MDI_CAMERA_BARCODE_TYPE_QR);

    mmi_barcodereader_capture_and_decode_set_key_hdlr();
    g_barcodereader_cntx.is_capturing = TRUE;
    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);
}
#endif /* !defined(__MMI_BARCODEREADER_AF_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_capture_and_decode_set_key_hdlr
 * DESCRIPTION
 *  set key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_capture_and_decode_set_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_KEY);
    ClearKeyEvents();
    /* register soft keys */
    SetKeyHandler(mmi_barcodereader_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_barcodereader_lsk_release, KEY_LSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_barcodereader_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_barcodereader_rsk_release, KEY_RSK, KEY_EVENT_UP);

#ifdef __MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__
#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
    /* register capture and control keys */
    if (MMI_BARCODEREADER_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_barcodereader_re_focus_press, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_barcodereader_capture_button_release, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_UP);
    }

    if (BARCODEREADER_CAPTURE_EXTRA_KEY != -1)
    {
        SetKeyHandler(mmi_barcodereader_re_focus_press, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_barcodereader_capture_button_release, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_UP);
    }
#else /* __MMI_BARCODEREADER_AF_SUPPORT__ */ 
    if (MMI_BARCODEREADER_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_UP);
    }

    if (MMI_BARCODEREADER_CAPTURE_EXTRA_KEY != -1)
    {
        SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_UP);
    }
#endif /* __MMI_BARCODEREADER_AF_SUPPORT__ */ 
#else /* __MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__ */ 
    /* register capture and control keys */
    if (MMI_BARCODEREADER_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_barcodereader_capture_button_press, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_barcodereader_capture_button_release, MMI_BARCODEREADER_CAPTURE_KEY, KEY_EVENT_UP);
    }

    if (MMI_BARCODEREADER_CAPTURE_EXTRA_KEY != -1)
    {
        SetKeyHandler(mmi_barcodereader_capture_button_press, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_barcodereader_dummy_func, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_barcodereader_capture_button_release, MMI_BARCODEREADER_CAPTURE_EXTRA_KEY, KEY_EVENT_UP);
    }

#endif /* __MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_enter_capture_and_decode_state
 * DESCRIPTION
 *  entry of capture_and_decode state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_enter_capture_and_decode_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_barcodereader_cntx.app_prev_state)
    {
        case MMI_BARCODEREADER_STATE_EXIT:
            ASSERT(g_barcodereader_cntx.app_prev_state != MMI_BARCODEREADER_STATE_EXIT);
            break;

        case MMI_BARCODEREADER_STATE_PREVIEW:
            memset(g_barcodereader_cntx.decode_text, 0, BR_VERSION_ONE_SLOT_BUFFER_SIZE);

    #if !defined(__MMI_BARCODEREADER_AF_SUPPORT__)
            mmi_barcodereader_set_hint(
                (PS8) GetString(STR_ID_BARCODEREADER_NOTIFY_CAPTURE_AND_DECODE),
                NULL,
                HINT_POPUP_FADE_TIME);
            mmi_barcodereader_start_capture_and_decode();  
            mmi_barcodereader_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_barcodereader_cntx.base_UI_device_width - 1,
                g_barcodereader_cntx.base_UI_device_height - 1);
            return;
    #else /* !defined(__MMI_BARCODEREADER_AF_SUPPORT__) */ 
            g_barcodereader_cntx.b_stop_decode = MMI_FALSE;
            gui_start_timer(MMI_BARCODEREADER_DECODE_TIME, mmi_barcodereader_decode_listen_timer);
            mdi_camera_capture_and_decode_barcode(
                g_barcodereader_cntx.decode_text,
                BR_VERSION_ONE_SLOT_BUFFER_SIZE - ENCODING_LENGTH,
                mmi_barcodereader_decode_result_hdlr,
                MDI_CAMERA_BARCODE_TYPE_QR);
            g_barcodereader_cntx.is_capturing = TRUE;
    #endif /* !defined(__MMI_BARCODEREADER_AF_SUPPORT__) */ 

            /* due to manual AF */
    #if defined(__MMI_BARCODEREADER_FOCUS_MODE__) && defined(__MMI_BARCODEREADER_FOCUS_MODE_MANUAL__)
            if (g_barcodereader_cntx.setting.af_mode == MMI_BARCODEREADER_SETTING_FOCUS_MODE_MANUAL)
            {
                mmi_barcodereader_draw_osd();
                gdi_layer_blt_previous(
                    0,
                    0,
                    g_barcodereader_cntx.base_UI_device_width - 1,
                    g_barcodereader_cntx.base_UI_device_height - 1);
            }
    #endif /* defined(__MMI_BARCODEREADER_FOCUS_MODE__) && defined(__MMI_BARCODEREADER_FOCUS_MODE_MANUAL__) */ 
            mmi_barcodereader_capture_and_decode_set_key_hdlr();
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_capture_and_decode_state
 * DESCRIPTION
 *  exit of capture_and_decode state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_exit_capture_and_decode_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_barcodereader_decode_listen_timer);
    switch (g_barcodereader_cntx.app_next_state)
    {
        case MMI_BARCODEREADER_STATE_EXIT:
            g_barcodereader_cntx.is_capturing = FALSE;
            mmi_barcodereader_preview_stop();

            gdi_layer_flatten_to_base(
                g_barcodereader_cntx.preview_layer_handle,
                g_barcodereader_cntx.osd_layer_handle,
                0,
                0);
            /* it is just use for 6219
            gdi_layer_flatten_to_base(
                g_barcodereader_cntx.base_layer_handle,
                g_barcodereader_cntx.preview_layer_handle,
                g_barcodereader_cntx.osd_layer_handle,
                0);
            */
            break;
        case MMI_BARCODEREADER_STATE_PREVIEW:
            mdi_camera_stop_capture_and_decode_barcode();
            g_barcodereader_cntx.is_capturing = FALSE;
            break;
    }
}

#ifdef __MMI_HORIZONTAL_BARCODEREADER__


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_check_sensor_orientation
 * DESCRIPTION
 *  check sensor orientation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_check_sensor_orientation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* rotate base layer */
    gdi_lcd_set_rotate(GDI_LCD_LAYER_ROTATE_270);
    gdi_layer_push_and_set_active(g_barcodereader_cntx.base_layer_handle);
    gdi_layer_resize(LCD_HEIGHT, LCD_WIDTH);
    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_check_osd_orientation
 * DESCRIPTION
 *  check sensor orientation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_check_osd_orientation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.previous_osd_rotate != g_barcodereader_cntx.osd_rotate)
    {
        switch (g_barcodereader_cntx.osd_rotate)
        {
            case MMI_BARCODEREADER_OSD_ROTATE_0:
                g_barcodereader_cntx.active_barcodereader_osd_ptr = &g_barcodereader_osd_cntx;
                g_barcodereader_cntx.osd_UI_device_height = LCD_HEIGHT;
                g_barcodereader_cntx.osd_UI_device_width = LCD_WIDTH;
                gdi_layer_push_and_set_active(g_barcodereader_cntx.osd_layer_handle);
                gdi_layer_toggle_double();
                gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_270);
                gdi_layer_resize(g_barcodereader_cntx.osd_UI_device_width, g_barcodereader_cntx.osd_UI_device_height);
                gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
                gdi_layer_pop_and_restore_active();
                break;

            case MMI_BARCODEREADER_OSD_ROTATE_270:
                g_barcodereader_cntx.active_barcodereader_osd_ptr = &g_barcodereader_osd_cntx_270;
                g_barcodereader_cntx.osd_UI_device_height = LCD_WIDTH;
                g_barcodereader_cntx.osd_UI_device_width = LCD_HEIGHT;
                gdi_layer_push_and_set_active(g_barcodereader_cntx.osd_layer_handle);
                gdi_layer_toggle_double();
                gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_0);
                gdi_layer_resize(g_barcodereader_cntx.osd_UI_device_width, g_barcodereader_cntx.osd_UI_device_height);
                gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
                gdi_layer_pop_and_restore_active();
                break;

            default:
                ASSERT(0);
                break;
        }

        g_barcodereader_cntx.previous_osd_rotate = g_barcodereader_cntx.osd_rotate;

    }

}
#endif /* __MMI_HORIZONTAL_BARCODEREADER__ */ 

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
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_enter_preview_screen
 * DESCRIPTION
 *  entry barcodereader application screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_enter_preview_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /***************************************************
     * Do not remove this section <START>
     ***************************************************/

    /*when in background call, do not allow to enter*/
#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call() && !CheckIsBackHistory())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif

    /* if usb is plugged in , then forbid to entry the barcode reader */
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */

        if (mmi_usb_check_path_exported((PS8) MMI_BARCODEREADER_STORAGE_FILEPATH_PHONE))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* allocate memory from App-Based ASM , and create adm related resource */
    mmi_barcoderader_malloc_memory_and_create_adm_resource();
    if (g_barcodereader_cntx.app_mem_pool == NULL)
    {   
        return;
    }

    /***************************************************
     * Do not remove this section <END>
     ***************************************************/

    MMI_BARCODEREADER_CHECK_STATE(MMI_BARCODEREADER_STATE_EXIT);

    /* entry new screen */
    EntryNewScreen(
        SCR_ID_BARCODEREADER_PREVIEW,
        mmi_barcodereader_exit_preview_screen,
        mmi_barcodereader_enter_preview_screen,
        MMI_FULL_SCREEN);
    SetDelScrnIDCallbackHandler(SCR_ID_BARCODEREADER_PREVIEW, mmi_barcodereader_del_scr_callback);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_PREVIEW);

    /************ init/config framework's environment  ************/
    /* entry full screen app */
    entry_full_screen();

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();
    gdi_layer_clear(GDI_COLOR_BLACK);
    /*********** init layer var ************/
    /* get mainlcd based layer handle */
    gdi_layer_get_base_handle(&g_barcodereader_cntx.base_layer_handle);

    /* get sublcd base layer handle */

    /*for draw title bar*/
    wgui_set_wallpaper_on_bottom(MMI_TRUE);
    
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_get_base_handle(&g_barcodereader_cntx.sublcd_base_layer_handle);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* __MMI_SUBLCD__ */ 

    /************ draw sublcd and hook msg hdlr ************/
#ifdef __MMI_SUBLCD__
    /* entry sublcd */
    if (!g_barcodereader_cntx.is_sublcd_display)
    {
        ForceSubLCDScreen(mmi_barcodereader_enter_sublcd_screen);
    }
#endif /* __MMI_SUBLCD__ */ 

    mmi_barcodereader_init_framework();

    /************ init camera app environment *********************/
    mmi_barcodereader_init_camera();

    /* load Setting */
    /* allocate storage path buffer */
    g_barcodereader_cntx.storage_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
    g_barcodereader_cntx.storage_filepath[0] = 0;

    /* each time newly enter camera, do anything ... ? */
    if (guiBuffer == NULL)
    {
        g_barcodereader_cntx.zoom_idx = MMI_BARCODEREADER_DEFAULT_SETTING_ZOOM_IDX;
        g_barcodereader_cntx.is_append_qrcode = FALSE;
        g_barcodereader_cntx.symbol_masks = 0;
        g_barcodereader_cntx.symbol_count = 1;
    }

    /* power on and init hardware module */
    if (g_barcodereader_cntx.last_error.error_result == MDI_RES_CAMERA_SUCCEED)
    {
        g_barcodereader_cntx.last_error.error_result = mdi_camera_power_on();
        g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_CAMERA;
        g_barcodereader_cntx.last_error.tone_id = ERROR_TONE;
    }

    /* create preview resource */
    mmi_barcodereader_create_resource();

    /* we always use LCD rotate */
    gdi_lcd_set_rotate_by_layer(TRUE);

#if defined(__MMI_HORIZONTAL_BARCODEREADER__)
    g_barcodereader_cntx.previous_osd_rotate = MMI_BARCODEREADER_OSD_ROTATE_RESET;
    mmi_barcodereader_check_sensor_orientation();   /* turn the base layer */
    mmi_barcodereader_check_osd_orientation();      /* turn the osd layer */

#if defined(__MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__)
    /* mmi_camera_update_osd_touch_icon(); */
#endif 
#endif /* defined(__MMI_HORIZONTAL_BARCODEREADER__) */ 

    /* check if there is small screen above camera */
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    //if (is_redrawing_old_screens() == TRUE)
    //{
        //return;
    //}
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 



#ifdef __MMI_TVOUT__
    /* since someone change lcd/lcm rotate mechanism (gdi_lcd_set_rotate_by_layer()), 
       we must call this function to change driver's mode */
    if (mdi_tvout_is_enable())
    {
        mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);  /* the same with lcd */
    }
#endif /* __MMI_TVOUT__ */ 

    /************ enter preview state ************/
    /* no error, if has error, will enter main then show error popup */
    if (g_barcodereader_cntx.last_error.error_result == MDI_RES_CAMERA_SUCCEED)
    {
        MMI_BARCODEREADER_ENTER_STATE(MMI_BARCODEREADER_STATE_PREVIEW);

    }
    else
    {
        mmi_barcodereader_display_error_popup(
            g_barcodereader_cntx.last_error.error_result,
            g_barcodereader_cntx.last_error.error_type,
            g_barcodereader_cntx.last_error.tone_id);
        #ifndef __MMI_BARCODEREADER_STORAGE__
            DeleteScreenIfPresent(SCR_ID_BARCODEREADER_PREVIEW);
        #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_init_camera
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_init_camera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init some flags */
    g_barcodereader_cntx.last_error.error_result = MDI_RES_CAMERA_SUCCEED;
    g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_CAMERA;
    g_barcodereader_cntx.last_error.tone_id = WARNING_TONE;
    g_barcodereader_cntx.lcm_rotate = MMI_BARCODEREADER_LCM_MAINLCD_ROTATE;

#ifdef __MMI_HORIZONTAL_BARCODEREADER__
    g_barcodereader_cntx.preview_height = MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH;
    g_barcodereader_cntx.preview_width = MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT;
#else /* __MMI_HORIZONTAL_BARCODEREADER__ */ 
    g_barcodereader_cntx.preview_height = MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT;
    g_barcodereader_cntx.preview_width = MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH;
#endif /* __MMI_HORIZONTAL_BARCODEREADER__ */ 

#ifdef __MMI_HORIZONTAL_BARCODEREADER__ /* preview area */
    g_barcodereader_cntx.image_width = MMI_BARCODEREADER_IMAGE_HEIGHT;
    g_barcodereader_cntx.image_height = MMI_BARCODEREADER_IMAGE_WIDTH;
#else /* __MMI_HORIZONTAL_BARCODEREADER__ */ 
    g_barcodereader_cntx.image_width = MMI_BARCODEREADER_IMAGE_WIDTH;
    g_barcodereader_cntx.image_height = MMI_BARCODEREADER_IMAGE_HEIGHT;
#endif /* __MMI_HORIZONTAL_BARCODEREADER__ */ 

#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
    g_barcodereader_cntx.af_state = MMI_BARCODEREADER_AF_IDLE;
    g_barcodereader_cntx.is_af_capture = FALSE;
#endif /* __MMI_BARCODEREADER_FOCUS_MODE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_create_resource
 * DESCRIPTION
 *  create layer resource
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static BOOL mmi_barcodereader_create_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_barcodereader_cntx.is_mainlcd_resource == FALSE);
    /* if main lcd resoruce is not created */


   /************ base layer ************/
    /* get both MainLCD and SubLCD base handle */
    gdi_layer_get_base_handle(&g_barcodereader_cntx.base_layer_handle);

    /* clear fullscreen */
    gdi_layer_clear(GDI_COLOR_BLACK);

#ifdef CAMERA_MODULE_WITH_LCD
    gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
#endif 

   /************ osd layer ************/
    g_barcodereader_cntx.osd_layer_buf_ptr = (PU8) mmi_frm_scrmem_alloc_framebuffer(BR_SCR_OSD_SIZE);
    ASSERT(g_barcodereader_cntx.osd_layer_buf_ptr != NULL);

    gdi_layer_create_double_using_outside_memory(
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &g_barcodereader_cntx.osd_layer_handle,
        (PU8) g_barcodereader_cntx.osd_layer_buf_ptr,
        (S32) (BR_SCR_OSD_SIZE));

    wgui_status_icon_bar_set_target_layer(WGUI_STATUS_ICON_BAR_H_BAR, g_barcodereader_cntx.osd_layer_handle);
    gdi_layer_push_and_set_active(g_barcodereader_cntx.osd_layer_handle);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

   /************ preview layer ***********/
    mmi_barcodereader_create_preview_resource();

    g_barcodereader_cntx.is_mainlcd_resource = TRUE;
    return g_barcodereader_cntx.is_mainlcd_resource;
}


/*****************************************************************************
 *
* touch screen support 
*
*****************************************************************************/
#if defined(__MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_touch_scr_pen_down_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen down
 * PARAMETERS
 *  pos     [IN]        Pen down position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }

    /* other screen use generic touch screen handler */
    if (!g_barcodereader_cntx.active_barcodereader_osd_ptr->softkey.is_draw_mmi_softkey)
    {
        /* LSK */
        if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_lsk) == MMI_TRUE)
        {
            switch (g_barcodereader_cntx.app_state)
            {
                    /* main lcd */
                case MMI_BARCODEREADER_STATE_PREVIEW:
                case MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE:
                    mmi_barcodereader_lsk_press();
                    break;
            }
            g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_LSK;
            return;
        }

        /* RSK */
        if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_rsk) == MMI_TRUE)
        {
            switch (g_barcodereader_cntx.app_state)
            {
                    /* main lcd */
                case MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE:
                case MMI_BARCODEREADER_STATE_PREVIEW:
                    mmi_barcodereader_rsk_press();
                    break;
            }
            g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_RSK;
            return;
        }

    }
    else
    {
        if (wgui_test_lsk_position(pos) == MMI_TRUE)
        {
            /* draw clicked lsk */
            mmi_barcodereader_lsk_press();
            g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_LSK;
            return;
        }
        if (wgui_test_rsk_position(pos) == MMI_TRUE)
        {
            /* draw clicked rsk */
            mmi_barcodereader_rsk_press();
            g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_RSK;
            return;
        }
    }
    /* while af is calculating, disable touch panel */
#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
    if (g_barcodereader_cntx.af_state == MMI_BARCODEREADER_AF_CALCULATE)        /* || g_barcodereader_cntx.is_autofocus_pressed ==TRUE) */
    {
        g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_NONE;
        return;
    }
#endif /* __MMI_BARCODEREADER_FOCUS_MODE__ */ 

    if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW && g_barcodereader_cntx.is_capturing == FALSE)
    {
        /* osd test */
#define MMI_BARCODEREADER_OSD_ICON_TOUCH_TEST(a,A)                                                                   \
      do {                                                                                                           \
         if(g_barcodereader_cntx.active_barcodereader_osd_ptr->##a##.is_show)                                        \
         {                                                                                                           \
            if(mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_##a##) == MMI_TRUE)    \
            {                                                                                                        \
               mmi_barcodereader_##a##_hotkey_press();                                                               \
               g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_##A;                                      \
               return;                                                                                               \
            }                                                                                                        \
         }                                                                                                           \
      } while(0);

        if (!g_barcodereader_cntx.is_hide_osd)
        {
        #ifdef __MMI_BARCODEREADER_FLASH__
            MMI_BARCODEREADER_OSD_ICON_TOUCH_TEST(flash, FLASH);
        #endif 

        #ifdef __MMI_BARCODEREADER_FOCUS_MODE__
            MMI_BARCODEREADER_OSD_ICON_TOUCH_TEST(af_mode, FOCUS_MODE);
        #endif 

        #ifdef __MMI_BARCODEREADER_STORAGE__
            MMI_BARCODEREADER_OSD_ICON_TOUCH_TEST(storage, STORAGE);
        #endif 
            /* ev inc test */
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_ev_inc) == MMI_TRUE)
            {
                mmi_barcodereader_ev_inc_key_press();
                g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_EV_INC;
                return;
            }

            /* ev dec test */
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_ev_dec) == MMI_TRUE)
            {
                mmi_barcodereader_ev_dec_key_press();
                g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_EV_DEC;
                return;
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
        #endif /* 0 */ 
        }

    }

#ifdef __MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__
    /* capture */
#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
    if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_capture) == MMI_TRUE)
    {
        /* mmi_barcodereader_capture_button_press(); */
        /* capture */
        /* mmi_barcodereader_af_and_capture(); */
        mmi_barcodereader_re_focus_press();
        g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_CAPTURE;
        return;
    }
#endif /* __MMI_BARCODEREADER_AF_SUPPORT__ */ 
#else /* __MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__ */ 
    /* capture */
    if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_capture) == MMI_TRUE)
    {
        if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW)
        {
            /* capture */
        #ifdef __MMI_BARCODEREADER_AF_SUPPORT__
            mmi_barcodereader_af_and_capture();
        #else 
            mmi_barcodereader_capture_button_press();
        #endif 
        }
        else if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE)
        {
            mmi_barcodereader_capture_button_press();
        }

        g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_CAPTURE;
        return;
    }
#endif /* __MMI_BARCODEREADER_AF_AND_CAPTURE_DIRECTLY__ */ 

    g_barcodereader_cntx.touch_object = MMI_BARCODEREADER_TOUCH_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_touch_scr_pen_up_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen up
 * PARAMETERS
 *  pos     [IN]        Pen up position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }

    switch (g_barcodereader_cntx.touch_object)
    {
        case MMI_BARCODEREADER_TOUCH_LSK:
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_lsk) == MMI_TRUE)
            {
                switch (g_barcodereader_cntx.app_state)
                {
                        /* main lcd */
                    case MMI_BARCODEREADER_STATE_PREVIEW:
                    case MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE:
                        mmi_barcodereader_lsk_release();
                        break;

                }
            }
#ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
            else
            {
                mmi_barcodereader_reset_watchdog_time_out_handler();
                mmi_barcodereader_watchdog_time_out_handler();
            }
#endif
            break;

        case MMI_BARCODEREADER_TOUCH_RSK:
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_rsk) == MMI_TRUE)
            {
                switch (g_barcodereader_cntx.app_state)
                {
                        /* main lcd */
                    case MMI_BARCODEREADER_STATE_PREVIEW:
                    case MMI_BARCODEREADER_STATE_CAPTURE_AND_DECODE:
                        mmi_barcodereader_rsk_release();
                        break;
                }
            }
#ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
            else
            {
                mmi_barcodereader_reset_watchdog_time_out_handler();
                mmi_barcodereader_watchdog_time_out_handler();
            }
#endif
            break;

        case MMI_BARCODEREADER_TOUCH_EV_INC:
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_ev_inc) == MMI_TRUE)
            {
                mmi_barcodereader_ev_inc_key_release();
            }
            break;

        case MMI_BARCODEREADER_TOUCH_EV_DEC:
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_ev_dec) == MMI_TRUE)
            {
                mmi_barcodereader_ev_dec_key_release();
            }
            break;
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
        #endif /* 0 */ 
        case MMI_BARCODEREADER_TOUCH_CAPTURE:
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_capture) == MMI_TRUE)
            {
                mmi_barcodereader_capture_button_release();
            }
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_touch_scr_pen_move_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen move
 * PARAMETERS
 *  pos     [IN]        Pen move position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_touch_scr_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL softkey_pressed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    softkey_pressed = FALSE;
    if (g_barcodereader_cntx.osd_rotate == MMI_BARCODEREADER_OSD_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }

    switch (g_barcodereader_cntx.touch_object)
    {
        case MMI_BARCODEREADER_TOUCH_LSK:
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_lsk))
            {
                softkey_pressed = TRUE;
            }
            else
            {
                softkey_pressed = FALSE;
            }

            if (softkey_pressed != g_barcodereader_cntx.is_lsk_pressed)
            {
                g_barcodereader_cntx.is_lsk_pressed = softkey_pressed;
                mmi_barcodereader_draw_osd();
                gdi_layer_blt_previous(
                    0,
                    0,
                    g_barcodereader_cntx.base_UI_device_width - 1,
                    g_barcodereader_cntx.base_UI_device_height - 1);
            }
            break;

        case MMI_BARCODEREADER_TOUCH_RSK:
            if (mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_rsk))
            {
                softkey_pressed = TRUE;
            }
            else
            {
                softkey_pressed = FALSE;
            }

            if (softkey_pressed != g_barcodereader_cntx.is_rsk_pressed)
            {
                g_barcodereader_cntx.is_rsk_pressed = softkey_pressed;
                mmi_barcodereader_draw_osd();
                gdi_layer_blt_previous(
                    0,
                    0,
                    g_barcodereader_cntx.base_UI_device_width - 1,
                    g_barcodereader_cntx.base_UI_device_height - 1);
            }
            break;

        case MMI_BARCODEREADER_TOUCH_EV_INC:
            if (!mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_ev_inc))
            {
                /* move out, treat as key release */
                mmi_barcodereader_ev_inc_key_release();
                /* mmi_barcodereader_ev_inc_key_release(); */
            }
            break;

        case MMI_BARCODEREADER_TOUCH_EV_DEC:
            if (!mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_ev_dec))
            {
                /* move out, treat as key release */
                mmi_barcodereader_ev_dec_key_release();
            }
            break;
        #ifdef __MMI_BARCODEREADER_MF_SUPPORT__
        case MMI_BARCODEREADER_TOUCH_MF_INC:
            if (!mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_mf_inc))
            {
                /* move out, treat as key release */
                mmi_barcodereader_up_arrow_release();
            }
            break;

        case MMI_BARCODEREADER_TOUCH_MF_DEC:
            if (!mmi_barcodereader_touch_scr_hit_test(pos.x, pos.y, &g_barcodereader_cntx.touch_mf_dec))
            {
                /* move out, treat as key release */
                mmi_barcodereader_down_arrow_release();
            }
        #endif /* __MMI_BARCODEREADER_MF_SUPPORT__ */ 
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_touch_scr_hit_test
 * DESCRIPTION
 *  test if is within touch region
 * PARAMETERS
 *  pos_x           [IN]        Position x
 *  pos_y           [IN]        Position y
 *  touch_obj       [?]         [?]         [?]
 *  touch(?)        [IN]        Touch object structure(?)(?)
 * RETURNS
 * BOOL
 *****************************************************************************/
static BOOL mmi_barcodereader_touch_scr_hit_test(S32 pos_x, S32 pos_y, barcodereader_ui_touch_struct *touch_obj)
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
#endif /* defined(__MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__) */ 

#if defined(__MMI_BARCODEREADER_FOCUS_MODE_MANUAL__)


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_mf_forward
 * DESCRIPTION
 *  mf forward once
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_mf_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW)
        && (g_barcodereader_cntx.mf_level_idx < g_barcodereader_cntx.mf_level_cnt))
    {
        g_barcodereader_cntx.mf_level_idx++;
        g_barcodereader_cntx.touch_mf_inc.is_press = TRUE;

        mdi_camera_mf_forward();
        mmi_barcodereader_set_hint(NULL, NULL, 0);
        mmi_barcodereader_draw_osd();
        gdi_layer_blt_previous(
            0,
            0,
            g_barcodereader_cntx.base_UI_device_width - 1,
            g_barcodereader_cntx.base_UI_device_height - 1);

        if (!g_barcodereader_cntx.is_up_arrow_pressed)
        {
            gui_start_timer(200, mmi_barcodereader_mf_forward_continue);
        }
    }
    else if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW)
    {
        g_barcodereader_cntx.touch_mf_inc.is_press = FALSE;
        mmi_barcodereader_draw_osd();
        gdi_layer_blt_previous(
            0,
            0,
            g_barcodereader_cntx.base_UI_device_width - 1,
            g_barcodereader_cntx.base_UI_device_height - 1);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_mf_backward
 * DESCRIPTION
 *  mf backward once
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_mf_backward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW) && (g_barcodereader_cntx.mf_level_idx > 0))
    {
        g_barcodereader_cntx.mf_level_idx--;
        g_barcodereader_cntx.touch_mf_dec.is_press = TRUE;
        mdi_camera_mf_backward();
        mmi_barcodereader_set_hint(NULL, NULL, 0);
        mmi_barcodereader_draw_osd();
        gdi_layer_blt_previous(
            0,
            0,
            g_barcodereader_cntx.base_UI_device_width - 1,
            g_barcodereader_cntx.base_UI_device_height - 1);

        if (!g_barcodereader_cntx.is_down_arrow_pressed)
        {
            gui_start_timer(200, mmi_barcodereader_mf_backward_continue);
        }
    }
    else if (g_barcodereader_cntx.app_state == MMI_BARCODEREADER_STATE_PREVIEW)
    {
        g_barcodereader_cntx.touch_mf_dec.is_press = FALSE;
        mmi_barcodereader_draw_osd();
        gdi_layer_blt_previous(
            0,
            0,
            g_barcodereader_cntx.base_UI_device_width - 1,
            g_barcodereader_cntx.base_UI_device_height - 1);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_mf_stop
 * DESCRIPTION
 *  stop mf action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_mf_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_stop_mf_continue();
    mmi_barcodereader_draw_osd();
    gdi_layer_blt_previous(
        0,
        0,
        g_barcodereader_cntx.base_UI_device_width - 1,
        g_barcodereader_cntx.base_UI_device_height - 1);
    g_barcodereader_cntx.is_mf_continue = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_mf_forward_continue
 * DESCRIPTION
 *  start mf forward continue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_mf_forward_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.is_mf_continue = TRUE;
    mdi_camera_start_mf_continue(TRUE);
    g_barcodereader_cntx.is_draw_timer_on = TRUE;
    gui_start_timer(100, mmi_barcodereader_draw_osd_timer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_mf_backward_continue
 * DESCRIPTION
 *  start mf backward continue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_mf_backward_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.is_mf_continue = TRUE;
    mdi_camera_start_mf_continue(FALSE);
    g_barcodereader_cntx.is_draw_timer_on = TRUE;
    gui_start_timer(100, mmi_barcodereader_draw_osd_timer);
}

#endif /* defined(__MMI_BARCODEREADER_FOCUS_MODE_MANUAL__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_copy_from_unicode_to_unicode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  which       [IN]        
 *  dest        [?]         [?]
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_copy_from_unicode_to_unicode(U16 which, U8 *dest, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 current_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.app_content.ct_element[which].str_addr != NULL)
    {
        current_len = g_barcodereader_cntx.app_content.ct_element[which].length;
        if (current_len > length)
        {
            current_len = length;
        }
        mmi_ucs2ncpy((S8*) dest, g_barcodereader_cntx.app_content.ct_element[which].str_addr, current_len);
        memset(dest + current_len * ENCODING_LENGTH, 0, 2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_callback
 * DESCRIPTION
 *  callback function which will be called from categoryscreen
 * PARAMETERS
 *  selected_idx        [IN]        The index of the selected highlight item
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_callback(S32 selected_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_cntx.selected_hilight_idx = selected_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_entry_editor_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_entry_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bufferSize;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_BARCODEREADER_EDITOR,
        mmi_barcodereader_exit_editor_screen,
        mmi_barcodereader_entry_editor_screen,
        NULL);

    /* allocate storage path buffer */
    g_barcodereader_cntx.storage_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
    memset(g_barcodereader_cntx.storage_filepath, 0, FMGR_PATH_BUFFER_SIZE);

    mmi_barcodereader_get_storage_file_path((PS8) g_barcodereader_cntx.storage_filepath);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_EDITOR);
    bufferSize = mmi_ucs2strlen(g_barcodereader_cntx.formatted_text_buf);

    if (guiBuffer == NULL)
    {
        g_barcodereader_cntx.selected_hilight_idx = 0;
    }

    g_barcodereader_cntx.app_list_idx_count = g_barcodereader_cntx.app_list_idx;

#ifdef __MMI_BACKGROUND_CALL__
//    srv_ucm_register_app_exit_callback(MMI_UCM_APP_EXIT_CHECK_CB_BARCODEREADER, mmi_barcodereader_ucm_call_back);
    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_APP_EXIT_QUERY, mmi_barcodereader_ucm_call_back, NULL);

    SetDelScrnIDCallbackHandler(SCR_ID_BARCODEREADER_APP_PREVIEW, mmi_barcodereader_app_preview_del_scr_callback);
#endif

    ShowCategory228Screen(
        STR_ID_BARCODEREADER_APP_NAME,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) g_barcodereader_cntx.formatted_text_buf,
        bufferSize,
        g_barcodereader_cntx.app_content.ct_element,
        (U16) g_barcodereader_cntx.app_list_idx,
        mmi_barcodereader_callback,
        guiBuffer);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BARCODEREADER_OP00_TOTAL_HILIGHT_COUNT_IN_EDITOR_SCREEN, g_barcodereader_cntx.app_list_idx);

    SetLeftSoftkeyFunction(mmi_barcodereader_forward_to_apps, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_exit_editor_screen
 * DESCRIPTION
 *  exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_exit_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free buffer */
    gui_free(g_barcodereader_cntx.storage_filepath);
    g_barcodereader_cntx.storage_filepath = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_func_exit
 * DESCRIPTION
 *  functions to ooxx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_func_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteNHistory(1);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_get_ucs2char
 * DESCRIPTION
 *  Get Ascii or UCS2 character
 * PARAMETERS
 *  buf     [?]     [?]     [?]
 *  a(?)        [IN]        Address of string(?)(?)
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
static S16 mmi_barcodereader_get_ucs2char(S8 *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (*buf + ((*(buf + 1)) << 8));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_store_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_store_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_BARCODEREADER_SETTING_LID,
        1,
        (void*)&g_barcodereader_cntx.setting,
        NVRAM_EF_BARCODEREADER_SETTING_SIZE,
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_load_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_load_setting(void)
{
    S16 error;
    
    if (!g_barcodereader_cntx.is_setting_loaded)
    {
        ReadRecord(
            NVRAM_EF_BARCODEREADER_SETTING_LID,
            1,
            (void*)&g_barcodereader_cntx.setting,
            NVRAM_EF_BARCODEREADER_SETTING_SIZE,
            &error);
        
        /* first time init */
        if (g_barcodereader_cntx.setting.storage == 0xffff)
        {
            g_barcodereader_cntx.setting.storage = (U16) MMI_PUBLIC_DRV;
            mmi_barcodereader_store_setting();
        }
        
        g_barcodereader_cntx.is_setting_loaded = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_decode_listen_timer
 * DESCRIPTION
 *  draw focus related OSD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_decode_listen_timer(void)
{
    g_barcodereader_cntx.b_stop_decode = MMI_TRUE;

    g_barcodereader_cntx.last_error.error_result = MDI_RES_BARCODEREADER_DECODE_TIMEOUT;
    g_barcodereader_cntx.last_error.error_type = MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER;
    g_barcodereader_cntx.last_error.tone_id = ERROR_TONE;

    mmi_barcodereader_display_error_popup(
        g_barcodereader_cntx.last_error.error_result,
        g_barcodereader_cntx.last_error.error_type,
        g_barcodereader_cntx.last_error.tone_id);
}


#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
BOOL mmi_barcodereader_notify_hdlr(U32 notify_flag, void* para)
{
    switch(notify_flag)
    {
    case MMI_FMGR_NOTIFY_SET_STORAGE_PRE_CHK:
        break;

    case MMI_FMGR_NOTIFY_SET_STORAGE:
        if (g_barcodereader_cntx.setting.storage != *((S8*)para))
        {
            g_barcodereader_cntx.setting.storage = *((S8*)para);
            mmi_barcodereader_store_setting();
        }
        /* update setting */
        break;
    }
    return MMI_TRUE;
}
#endif

#if defined(__MMI_BACKGROUND_CALL__)
mmi_ret mmi_barcodereader_ucm_call_back(mmi_event_struct* ucm_data)
{
    return SRV_UCM_APP_EXIT_QUERY_RESULT_NO;
}


static U8 mmi_barcodereader_app_preview_del_scr_callback(void *ptr)
{
//    srv_ucm_unregister_app_exit_callback(MMI_UCM_APP_EXIT_CHECK_CB_BARCODEREADER);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_APP_EXIT_QUERY, mmi_barcodereader_ucm_call_back, NULL);

    return MMI_HIST_ALLOW_DELETING;
}
#endif /* __MMI_BACKGROUND_CALL__ */


#ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_reset_watchdog_time_out_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_reset_watchdog_time_out_handler(void)
{
    gui_cancel_timer(mmi_barcodereader_watchdog_time_out_handler);
    g_barcodereader_cntx.preview_watchdog_duration = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_watchdog_time_out_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_watchdog_time_out_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_cntx.preview_watchdog_duration < MMI_BARCODEREADER_WATCHDOG_TIMEOUT_DUR_MAX / MMI_BARCODEREADER_WATCHDOG_TIMEOUT_DUR_INTERVAL)
    {
        g_barcodereader_cntx.preview_watchdog_duration ++;
        gui_start_timer(MMI_BARCODEREADER_WATCHDOG_TIMEOUT_DUR_INTERVAL, mmi_barcodereader_watchdog_time_out_handler);
    }
    else
    {
        GoBackHistory();
    }
}
#endif /* __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_cui_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_barcodereader_cui_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    cui_phb_save_contact_result_struct* phb_event;
    cui_evt_sms_send_struct *sms_event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
/* PHB2.0 CUI */    
       case EVT_ID_PHB_SAVE_CONTACT:
            phb_event = (cui_phb_save_contact_result_struct*)evt;
            // Do something self here
            // Caller should call CUI close function to release CUI resource
             cui_phb_save_contact_close(g_barcodereader_cntx.save_number_cui_id);
            break;
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
             // Do something self here
            // Caller should call CUI close function to release CUI resource
            cui_phb_save_contact_close(g_barcodereader_cntx.save_number_cui_id);
            break;

/* SMS2.0 CUI */    

        case EVT_ID_CUI_SMS_SEND:
            sms_event = (cui_evt_sms_send_struct*)evt;
            if (sms_event->is_send_finish)
            {
                 cui_sms_send_close(g_barcodereader_cntx.sms_cui_id);
             }
            break;
        case EVT_ID_CUI_SMS_SAVE:
        case EVT_ID_CUI_SMS_SAVE_CANCEL:
         // Do something self here
         // Caller should call CUI close function to release CUI resource
//            sms_event = (cui_evt_sms_send_struct*)evt;

            cui_sms_send_close(g_barcodereader_cntx.sms_cui_id);
            break;


        default:
            break;
    }
    
    return MMI_RET_OK;
}


#endif /* __MMI_OP00_BARCODEREADER__ */ 
#endif /* __MMI_BARCODEREADER__ */ 

