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
 *  MobileTVPlayer.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Mobile TV Player Applications v0.1
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef _MMI_MOBILE_TV_PLAYER_H_
#define _MMI_MOBILE_TV_PLAYER_H_

#include "mmi_features.h"

#ifdef __MMI_ATV_SUPPORT__


#include "mmi_rp_app_mobile_tv_player_def.h"
#include "MobileTVPlayerEnum.h"
#include "MobileTVPlayerOSD.h"
#include "FileMgrSrvGProt.h"

/* IMSI*/
#include "SimCtrlSrvGprot.h" 
#include "InlineCUIGprot.h"


#include "DataAccountGProt.h"
#include "MMIDataType.h"
#include "FileMgrType.h"
#include "kal_general_types.h"
#include "mdi_enum.h"
#include "ScreenRotationGprot.h"
#include "kal_public_defs.h"
#include "gdi_datatype.h"
#include "app_datetime.h"
#include "mdi_mtv.h"
#include "mdi_datatype.h"
#include "gui_windows.h"
#include "gui_typedef.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "BtcmSrvGprot.h"
#include "gdi_const.h"
#include "gdi_features.h"
#include "mmi_features_mtv_player.h"


#define MMI_ATV_COUNTRY_TOTAL_COUNT     (STR_ID_ATV_COUNTRY_END - STR_ID_ATV_COUNTRY_START - 1)

#define MMI_MTV_NAME_STR_LENGTH 41
#define MMI_MTV_TIME_STR_LENGTH 14
#define MMI_MTV_DATE_TIME_STR_LENGTH 20
#define MMI_MTV_DATE_TYPE_STR_LENGTH 32
#define MMI_MTV_DATE_PRICE_STR_LENGTH 32
#define MMI_MTV_INFO_STR_LENGTH 128
#define MMI_MTV_TEXT_STR_LENGTH 128

#define MMI_MTV_JUMP_TO_CHANNEL_DELAY 2000

#define MMI_MTV_PROG_LIST_DAY_NUM (8)
#define MMI_MTV_PROG_LIST_DAY_LEN (11) /* xx-xx or xxxx-xx-xx */
#define MMI_MTV_CITY_LEN (10)

/***************************************
* Hint Box
***************************************/
#define MMI_MOBILE_TV_PLAYER_HINT_POPUP_FADE_TIME          (1200)
#define MMI_MOBILE_TV_PLAYER_HINT_POPUP_NO_FADE            (999)
#define MMI_MOBILE_TV_PLAYER_OSD_FADE_OUT_TIME       (3*1000) /* 3 sec */
#define MMI_MOBILE_TV_PLAYER_OSD_FADE_OUT_VALUE      (32)     /* fade 32/256 */

#define MMI_MOBILE_TV_PLAYER_UPDATE_SIGNAL_DURATION (2000)
#define MMI_MOBILE_TV_PLAYER_MINIMAL_MAX_DELAY_TO_START_TS (2000)
#define MMI_MOBILE_TV_PLAYER_TS_ENABLE_DURATION (5000) /* msec */
#define MMI_MOBILE_TV_PLAYER_TS_DELAY_DURATION (16000) /* msec */
#define MMI_MOBILE_TV_PLAYER_TS_BAR_DELAY_DURATION (2000) /* msec */
//#define MMI_MOBILE_TV_PLAYER_OSD_FADEOUT_FACTOR (255)
#if defined(__MMI_FTE_SUPPORT__) && (defined(__MMI_MAINLCD_320X480__)||defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__))
#define MMI_MOBILE_TV_PLAYER_OSD_FADEOUT_FACTOR (229)
#else 
#define MMI_MOBILE_TV_PLAYER_OSD_FADEOUT_FACTOR (255)
#endif
#define MMI_MOBILE_TV_PLAYER_SERVICE_TIMEOUT_DURATION (90000) /* msec */
#define MMI_MOBILE_TV_PLAYER_DISPLAY_ACCESS_DENIED_DURATION (15000) /* msec */
#define MMI_MOBILE_TV_PLAYER_VOL_ICON_DURATION (5000) /* msec */

#if defined(__MMI_FTE_SUPPORT__)
extern void mmi_mtv_player_vol_idx_icon_press(void);
extern void mmi_mtv_player_vol_idx_icon_release(void);
extern void mmi_mtv_player_vol_bg_icon_press(void);
extern void mmi_mtv_player_vol_bg_icon_release(void);
extern void mmi_mtv_player_hide_fte_vol_icon(void);
extern void mmi_mtv_player_update_vol_level(S32 pos_x);
extern void mmi_mtv_player_draw_fte_vol_icon(void);
#endif /* __MMI_FTE_SUPPORT__ */


/***************************************
* Mobile TV Setting Structure
***************************************/
#define MMI_MOBILE_TV_PLAYER_BRIGHTNESS_ADJ_LEVEL_COUNT (11)       /* -5, -4, ...0 , +4, +5 */
#define MMI_MOBILE_TV_PLAYER_CONTRAST_ADJ_LEVEL_COUNT   (11)       /* -5, -4, ...0 , +4, +5 */
#define MMI_MOBILE_TV_PLAYER_SATURATION_ADJ_LEVEL_COUNT (11)       /* -5, -4, ...0 , +4, +5 */
#define MMI_MOBILE_TV_PLAYER_AUD_MODE_ADJ_COUNT     (8)
#define MMI_MOBILE_TV_PLAYER_RECORD_SIZE_ADJ_COUNT  (3)

/***************************************
* Mobile TV Emergency Broadcast Type
***************************************/

#define KERNEL_STATE_IN(_STATE_) (mtv_player_p->kernel_state==_STATE_)
#define KERNEL_ENTER_STATE(_STATE_) \
    do{\
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_KERNEL_STATE, mtv_player_p->kernel_state, _STATE_);\
        mtv_player_p->kernel_prev_state=mtv_player_p->kernel_state;\
        mtv_player_p->kernel_state=_STATE_;\
    }while(0)

#define PLAYER_STATE_IN(_STATE_) (mtv_player_p->player_state==_STATE_)
#define PLAYER_ENTER_STATE(_STATE_) \
    do{\
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_PLAYER_STATE, mtv_player_p->player_state, _STATE_);\
        mtv_player_p->player_prev_state=mtv_player_p->player_state;\
        mtv_player_p->player_state=_STATE_;\
    }while(0)

#define RECORDER_STATE_IN(_STATE_) (mtv_player_p->recorder_state==_STATE_)
#define RECORDER_ENTER_STATE(_STATE_) \
    do{\
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_RECORDER_STATE, mtv_player_p->recorder_state, _STATE_);\
        mtv_player_p->recorder_prev_state=mtv_player_p->recorder_state;\
        mtv_player_p->recorder_state=_STATE_;\
    }while(0)
        
#define MTV_FULL_DLS_ICON_SPACE 6
typedef enum
{
    MTV_PLAYER_UPDATE_AUTO,
    MTV_PLAYER_UPDATE_SPECIFY_CITY,
    MTV_PLAYER_UPDATE_APPROACH_NUM
} mtv_player_update_approach_enum;

typedef struct
{
    CHAR *country_str[MMI_ATV_COUNTRY_TOTAL_COUNT + 1];   
    CHAR *aud_mode_str[MMI_MOBILE_TV_PLAYER_AUD_MODE_ADJ_COUNT];
    CHAR *record_size_str[MMI_MOBILE_TV_PLAYER_RECORD_SIZE_ADJ_COUNT];    
}mtv_player_menu_context_struct;


/***************************************
* Mobile TV Setting Structure
***************************************/
#define MMI_MTV_PLAYER_STORAGE_FILEPATH            FMGR_DEFAULT_FOLDER_VIDEO
#define MMI_MTV_PLAYER_STORAGE_FILEPATH_PHOTOS            FMGR_DEFAULT_FOLDER_PHOTOS

typedef enum
{
    MTV_PLAYER_STORAGE_PATH_VIDEO = 0,
    MTV_PLAYER_STORAGE_PATH_PHOTO,
    MTV_PLAYER_STORAGE_PATH_COUNT
} mtv_player_storage_path_enum;


typedef enum
{
    MTV_PLAYER_SETTING_BRIGHTNESS = 0,
    MTV_PLAYER_SETTING_CONTRAST,
    MTV_PLAYER_SETTING_SATURATION,
    MTV_PLAYER_SETTING_AUDIO_MODE,
    MTV_PLAYER_SETTING_RECORD_SIZE,
    MTV_PLAYER_SETTING_ITEM_COUNT
} mtv_player_setting_count_enum;

typedef enum
{
    MTV_PLAYER_STORAGE_OK = 0,
    MTV_PLAYER_STORAGE_NOT_READY, /* Folder is not yet created */
    MTV_PLAYER_STORAGE_RESET, /* Drive is not yet mounted */
    MTV_PLAYER_STORAGE_TOTAL_COUNT
}mtv_player_storage_status_enum;

/***************************************
* Icon Structure
***************************************/
typedef enum
{
    MTV_PLAYER_VOL_MUTE, /* 0 */
    MTV_PLAYER_VOL_1,
    MTV_PLAYER_VOL_2,
    MTV_PLAYER_VOL_3,
    MTV_PLAYER_VOL_4,
    MTV_PLAYER_VOL_5,
    MTV_PLAYER_VOL_6,
    MTV_PLAYER_VOL_7,
    MTV_PLAYER_VOL_8,
    MTV_PLAYER_VOL_9,
    MTV_PLAYER_VOL_10,
    MTV_PLAYER_VOL_11,
    MTV_PLAYER_VOL_12,
    MTV_PLAYER_VOL_13,    
    MTV_PLAYER_VOL_14,
    MTV_PLAYER_VOL_15,
    MTV_PLAYER_VOL_16    
} mtv_player_aud_vol_enum;

typedef enum
{
    MTV_PLAYER_TOUCH_NONE = 0,
    MTV_PLAYER_TOUCH_PLAY,
    MTV_PLAYER_TOUCH_RECORD,
    MTV_PLAYER_TOUCH_FULLSCREEN,
    MTV_PLAYER_TOUCH_VOL_INC,
    MTV_PLAYER_TOUCH_VOL_DEC,
    MTV_PLAYER_TOUCH_CHANNEL_NEXT,
    MTV_PLAYER_TOUCH_CHANNEL_PREV,
    MTV_PLAYER_TOUCH_LSK,
    MTV_PLAYER_TOUCH_RSK,
    MTV_PLAYER_TOUCH_VOL_BG,
    MTV_PLAYER_TOUCH_VOL_IDX,
    MTV_PLAYER_TOUCH_VOL_STATUS
} mtv_player_touch_icon_enum;

typedef enum
{    
    MTV_PLAYER_BOOL_START,
    MTV_PLAYER_IS_STORAGE_CHECK     = (1<<0),
    MTV_PLAYER_IS_LIVE_SCANNING     = (1<<1),         
    MTV_PLAYER_SERVICE_UNAVAILABLE  = (1<<2),
    MTV_PLAYER_UNAVAILABLE_IN_CALL  = (1<<3)    
}mtv_player_bool_status_enum;

typedef enum
{
    MTV_PLAYER_HINT_STATE_HIDE,
    MTV_PLAYER_HINT_STATE_SHOW_TRUNCATED, 
    MTV_PLAYER_HINT_STATE_FADING_TRUNCATED,
    MTV_PLAYER_HINT_STATE_SHOW_MULTILINE,
    MTV_PLAYER_HINT_STATE_FADING_MULTILINE    
} mtv_player_hint_state_enum;


typedef enum
{
    MMI_MTV_BRIGHTNESS_CAPTION = CUI_INLINE_ITEM_ID_BASE+1,
    MMI_MTV_BRIGHTNESS_SELECTOR,
    MMI_MTV_CONTRAST_CAPTION,
    MMI_MTV_CONTRAST_SELECTOR,   
    MMI_MTV_SATURATION_CAPTION,
    MMI_MTV_SATURATION_SELECTOR,
    MMI_MTV_AUDIO_MODE_CAPTION,
    MMI_MTV_AUDIO_MODE_SELECTOR,
    MMI_MTV_AUDIO_MODE_DISPLAY_ONLY,   
    MMI_MTV_RECORD_SIZE_CAPTION,
    MMI_MTV_RECORD_SIZE_SELECTOR,

    /* MBBMS: Channel list settings */
    MMI_MTV_PROGRAM_REMIND_TIME_CAPTION,
    MMI_MTV_PROGRAM_REMIND_TIME_SELECTOR,
    MMI_MTV_DATA_ACCOUNT_CAPTION,
//bql: apn
    MMI_MTV_DATA_ACCOUNT_SELECTOR,
    MMI_MTV_USE_PROXY_CAPTION,
    MMI_MTV_USE_PROXY_SELECTOR,
    MMI_MTV_PROXY_SERVER_CAPTION,
    MMI_MTV_PROXY_SERVER_IP4,
    MMI_MTV_PROXY_PORT_CAPTION,
    MMI_MTV_PROXY_PORT_TEXT_EDIT,
    MMI_MTV_SG_SERVER_CAPTION,
    MMI_MTV_SG_SERVER_TEXT_EDIT,
    MMI_MTV_SG_SERVER_PORT_CAPTION,
    MMI_MTV_SG_SERVER_PORT_TEXT_EDIT,
    
    /* MBBMS: Search program */
    MMI_MTV_KEYWORD_CAPTION,
    MMI_MTV_KEYWORD_TEXT_EDIT,
    MMI_MTV_CHANNEL_CAPTION,
    MMI_MTV_CHANNEL_SELECTOR,
    MMI_MTV_DATE_CAPTION,
    MMI_MTV_DATE_SELECTOR
}mtv_cui_inline_item_enum;

typedef struct
{       
    U8 brightness;
    U8 contrast;
    U8 saturation;
    U8 vol_level;
    U8 is_mute;
    U8 selected_channel;
    U8 record_size;
    U16 storage; 
    U16 filename_seq_no;
    S16 band;
    MMI_BOOL is_channel_list_init;  /* 17 */
} mtv_player_setting_struct;



/* Remember to enlarge MMI_MTV_MAX_SERVICE_INFO_STRUCTURE_SIZE */
typedef struct mtv_player_service_info_struct_t
{    
    U32 service_id;
    U32 service_number;
    mdi_mtv_service_type_enum service_type;
    S32 service_flags;
    WCHAR service_name[MMI_MTV_NAME_STR_LENGTH + 1];
    kal_uint32 audio_mode;              
    kal_uint32 supported_audio_mode;
} mtv_player_service_info_struct;

typedef struct
{   
    MMI_ID option_menu_gid;
    MMI_ID cl_option_menu_gid; /* Channel list option */
    MMI_ID ps_inline_gid; /* Player setting inline */
    mtv_player_storage_status_enum storage_status;
    mtv_player_storage_status_enum prev_storage_status;
    CHAR storage_filepath[SRV_FMGR_PATH_BUFFER_SIZE];    
    mmi_frm_screen_rotate_enum ui_rotate;

    U32 mtv_handle;
    
    void *app_mem_pool;
    KAL_ADM_ID adm_pool_id;
    kal_bool app_mem_force_release;
    
    /* preview layer */
    gdi_handle display_layer_handle;

    gdi_handle dls_drawing_layer_handle; /* for IDP rotate */
    gdi_handle osd_drawing_layer_handle; /* for IDP rotate */

    BOOL source_key_enable;
    gdi_color source_key_value;
    S32 base_layer_width;
    S32 base_layer_height;
    
    PU8 dls_drawing_layer_buf_ptr; /* for IDP rotate */
    PU8 osd_drawing_layer_buf_ptr; /* for IDP rotate */

    MMI_BOOL go_back_history;
    MMI_BOOL del_deleting_screen;
    MMI_BOOL del_main_screen;
    MMI_BOOL is_frist;
    /* osd layer */
    gdi_handle osd_layer_handle;
    PU8 osd_layer_buf_ptr;
    PU8 osd_layer_buf_ptr_2;

    /* dls layer */
    gdi_handle dls_layer_handle;
    PU8 dls_layer_buf_ptr;

    gdi_handle vol_layer_handle;
    PU8 vol_layer_buf_ptr;
    
    /* status_bar_layer_handle */
    gdi_handle status_bar_layer_handle;
    PU8 status_bar_buf_ptr;
    
    WCHAR hint1_buf[MMI_MTV_NAME_STR_LENGTH + 1];
    WCHAR hint2_buf[MMI_MTV_NAME_STR_LENGTH + 1];
    U16 fade_time;
    mtv_player_hint_state_enum hint_state;

    mmi_mtv_player_kernel_state_enum kernel_prev_state;
    mmi_mtv_player_kernel_state_enum kernel_state;
    mmi_mtv_player_kernel_state_enum kernel_next_state;

    mmi_mtv_player_player_state_enum player_prev_state;
    mmi_mtv_player_player_state_enum player_state;
    mmi_mtv_player_player_state_enum player_next_state;
    
    mmi_mtv_player_recorder_state_enum recorder_prev_state;
    mmi_mtv_player_recorder_state_enum recorder_state;
    mmi_mtv_player_recorder_state_enum recorder_next_state;

    mtv_player_service_info_struct *services; /* [MMI_MTV_MAX_SERVICES] */
    U16 num_services;
    
    U8 temporal_channel;
    WCHAR edit_service_name[MMI_MTV_NAME_STR_LENGTH + 11];    
    S32 record_size_num;

    S32 selected_band;
    S32 prev_selected_service;
    MDI_RESULT last_error;
    MMI_ID_TYPE err_str_id;
    MMI_BOOL is_setting_loaded;
    mtv_player_layout_struct *active_osd_cntx_p;
    mtv_player_touch_icon_enum touch_object;

    mtv_player_setting_struct setting;    
    U32 signal_strength;
    U16 fullscr_osd_opacity ;    
    mtv_player_bool_status_enum bool_state;
    U8 te_ctrl_handle;
    
    MMI_BOOL is_key_pressed;
    MMI_BOOL is_capture;

    MMI_BOOL is_suspend;
    
    MMI_BOOL is_before_cat265;
    MMI_BOOL is_channel_changed;
    MMI_BOOL is_changing_channel_by_key;
    U16   change_to_channel;

    gdi_handle bt_connect_amin_handle;

    gdi_handle cl_preview_layer_handle;
    U32 cl_blt_layer_flag;
    U32 cl_preview_layer_flag;
    S32 cl_preview_layer_offset_x;
    S32 cl_preview_layer_offset_y;
    S32 cl_preview_layer_width;
    S32 cl_preview_layer_height;

#if defined(__MMI_MTV_A2DP_SUPPORT__)
    U32 aud_sample_rate;
    U32 aud_channel_num;
#endif
}mmi_mtv_player_context_struct;

extern mmi_mtv_player_context_struct *mtv_player_p;
extern mtv_player_menu_context_struct *mtv_player_setting_p;

/****************************************************************************
* MACRO
*****************************************************************************/
extern MDI_RESULT mmi_mtv_player_enter_next_state(mmi_mtv_player_module_enum module);
/****************************************************************************
* Define
*****************************************************************************/
extern void mmi_mtv_player_pre_highlight_handler(S32 index, MMI_BOOL force_player_stop);
extern void mmi_mtv_player_post_highlight_handler(gdi_handle preview_handle, U32 blt_layer_flag, U32 preview_layer_flag, S32 x, S32 y, S32 width, S32 height);
extern S32 mmi_mtv_player_cat265_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item);
extern void mmi_mtv_player_reset_all_state(void);
extern void mmi_mtv_player_entry_option_menu_screen(void);
extern void mmi_mtv_player_highlight_channel_hdlr(S32 index);
extern void mmi_mtv_player_entry_cl_option_screen(void);
extern void mmi_mtv_player_entry_channel_list_screen(void);
extern MMI_BOOL mmi_mtv_player_check_and_restore_valid_drv(MMI_BOOL restore, U16 storage);
extern void mmi_mtv_player_highlight_storage_hdlr(S32 idx);
extern void mmi_mtv_player_entry_storage_screen(void);
extern void mmi_mtv_player_update_channel_list(void);
extern void mmi_mtv_player_remove_service(mtv_player_service_info_struct *info_ptr);
extern void mmi_mtv_player_reset_key_handler(void(*func_ptr)(void));
extern void mmi_mtv_player_delay_post_highlight_handler(void);
extern void mmi_mtv_player_check_and_jump_to_channel(void);

extern void mmi_mtv_player_highlight_app(void);
extern mtv_player_service_info_struct *mmi_mtv_player_get_active_channel_ptr(void);

extern void mmi_mtv_player_reset_to_channel_list_screen(void);
extern void mmi_mtv_player_display_confirm(U16 str_id);
extern void mmi_mtv_player_vol_status_icon_press(void);
extern void mmi_mtv_player_player_prepare_player_setting(mdi_mtv_player_setting_struct *video_setting);

extern void mmi_mtv_player_delete_channel(void);
extern void mmi_mtv_player_get_service_list(void);
extern void mmi_mtv_player_entry_rename_screen(void);

extern U8 mmi_mtv_player_select_band(void);
extern void mmi_mtv_player_prepare_audio_mode_list(U32 *num, U32 *highlighted_index);
extern MMI_BOOL mmi_mtv_player_rename_channel(void);
extern void mmi_mtv_player_prepare_record_size_list(void);
extern S32 mmi_mtv_player_get_audio_mode_index(S32 selected_index);
extern mdi_mtv_recorder_size_enum mmi_mtv_player_get_record_size(S32 idx);
extern S32 mmi_mtv_player_get_record_size_index(mdi_mtv_recorder_size_enum size);

extern void mmi_mtv_player_set_storage(WCHAR drv_letter);
extern mmi_ret mmi_mtv_player_app_screen_leave_proc(mmi_event_struct *para);
extern void mmi_mtv_player_dummy(void);
extern void mmi_mtv_player_register_key_hdlr(void); 
extern void mmi_mtv_player_set_band_value(void);
extern void mmi_mtv_player_highlight_band_hdlr(S32 idx);
extern void mmi_mtv_player_entry_band_screen(void);
extern void mmi_mtv_player_entry_app_screen(void);
extern void mmi_mtv_player_exit_app_screen(void);
extern void mmi_mtv_player_display_popup(U16 string_id, mmi_event_notify_enum event_id);
extern void mmi_mtv_player_display_failure_popup(MDI_RESULT ret);
extern MMI_BOOL mmi_mtv_player_get_storage_file_path(U16 storage, CHAR *filepath, mtv_player_storage_path_enum path);
extern S32 mmi_mtv_player_create_file_dir(CHAR *filepath);
extern MDI_RESULT mmi_mtv_player_kernel_enter_state(mmi_mtv_player_kernel_state_enum next_state);
extern void mmi_mtv_player_update_scan_progress(S32 value);

extern void mmi_mtv_player_rsk_icon_press(void);
extern void mmi_mtv_player_rsk_icon_release(void);
extern void mmi_mtv_player_lsk_icon_press(void);
extern void mmi_mtv_player_lsk_icon_release(void);
extern void mmi_mtv_player_play_icon_press(void);
extern void mmi_mtv_player_play_icon_release(void);
extern void mmi_mtv_player_record_icon_press(void);
extern void mmi_mtv_player_record_icon_release(void);
extern void mmi_mtv_player_fullscreen_icon_press(void);
extern void mmi_mtv_player_fullscreen_icon_release(void);
extern void mmi_mtv_player_vol_inc_icon_press(void);
extern void mmi_mtv_player_vol_inc_icon_release(void);
extern void mmi_mtv_player_vol_dec_icon_press(void);
extern void mmi_mtv_player_vol_dec_icon_release(void);
extern void mmi_mtv_player_channel_next_icon_press(void);
extern void mmi_mtv_player_channel_next_icon_release(void);
extern void mmi_mtv_player_channel_prev_icon_press(void);
extern void mmi_mtv_player_channel_prev_icon_release(void);
extern void mmi_mtv_player_key_1_press(void);
extern void mmi_mtv_player_key_2_press(void);
extern void mmi_mtv_player_key_3_press(void);
extern void mmi_mtv_player_key_4_press(void);
extern void mmi_mtv_player_key_5_press(void);
extern void mmi_mtv_player_key_6_press(void);
extern void mmi_mtv_player_key_7_press(void);
extern void mmi_mtv_player_key_8_press(void);
extern void mmi_mtv_player_key_9_press(void);
extern void mmi_mtv_player_key_0_press(void);
extern void mmi_mtv_player_jump_to_channel(void);
extern void mmi_mtv_player_fade_in(void);
extern void mmi_mtv_player_fade_out(void);
extern void mmi_mtv_player_vol_status_icon_release(void);

extern void mmi_mtv_player_init_icon_info(void);
#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL mmi_mtv_player_touch_scr_hit_test(S32 pos_x, S32 pos_y, mtv_player_osd_icon_struct *touch_obj);
extern void mmi_mtv_player_pen_down_hdlr_fullscreen(mmi_pen_point_struct pos);
extern void mmi_mtv_player_pen_down_hdlr(mmi_pen_point_struct pos);
extern void mmi_mtv_player_pen_up_hdlr(mmi_pen_point_struct pos);
extern void mmi_mtv_player_pen_move_hdlr(mmi_pen_point_struct pos);
#endif

extern void mmi_mtv_player_draw_style_text(CHAR *str, S32 offset_x, S32 offset_y);
extern void mmi_mtv_player_draw_osd_softkey(void);
extern void mmi_mtv_player_draw_osd(void);

extern void mmi_mtv_player_fullscr_osd_show_up(void);
extern void mmi_mtv_player_fullscr_osd_fade_cyclic(void);
extern void mmi_mtv_player_fullscr_reset_osd_fade(BOOL sleep);

extern void mmi_mtv_player_app_mem_success_callback(void);
extern void mmi_mtv_player_stop_app_mem_callback(void);

extern void mmi_mtv_player_create_adm(void);
extern void mmi_mtv_player_delete_adm(void);
extern void mmi_mtv_player_alloc_adm_layer(void);
extern void mmi_mtv_player_free_adm_layer(void);
extern void mmi_mtv_player_alloc_resource(void);
extern void mmi_mtv_player_free_resource(void);
extern void mmi_mtv_player_alloc_base_layer(void);
extern void mmi_mtv_player_free_base_layer(void);
extern void mmi_mtv_player_free_adm_structure(void);
extern void mmi_mtv_player_alloc_adm_structure(void);
extern U8 mmi_mtv_player_app_screen_delete_hdlr(void* ptr);
extern void mmi_mtv_player_store_setting(void);
extern void mmi_mtv_player_load_setting(void);
extern void mmi_mtv_player_restore_setting(void);
extern void mmi_mtv_player_set_hint(CHAR *hint_str1, CHAR *hint_str2, U16 fade_time, MMI_BOOL multiline);
extern void mmi_mtv_player_draw_hint(void);
extern void mmi_mtv_player_hide_hint(void);

extern void mmi_mtv_player_config_layers(void);
extern void mmi_mtv_player_config_display_layer(void);
extern void mmi_mtv_player_set_blt_layer(void);

extern void mmi_mtv_player_service_found_hdlr(mdi_mtv_service_info_struct *service_info, void *user_data);
extern void mmi_mtv_player_search_progress_hdlr(S32 value, void *user_data);
extern void mmi_mtv_player_complete_recovering_hdlr(S32 value, void *user_data);
extern void mmi_mtv_player_system_event_hdlr(U32 event_id, S32 param, void *user_data);
extern void mmi_mtv_player_service_event_hdlr(U32 event_id, S32 param, void *user_data);
extern void mmi_mtv_player_player_event_hdlr(U32 event_id, S32 param, void *user_data);
extern void mmi_mtv_player_recorder_event_hdlr(U32 event_id, S32 param, void *user_data);

extern MDI_RESULT mmi_mtv_player_open_engine(void);

extern MDI_RESULT mmi_mtv_player_exit_current_state(mmi_mtv_player_module_enum module);
/*kernel state management*/
extern MDI_RESULT mmi_mtv_player_kernel_entry_closing_state(void);
extern MDI_RESULT mmi_mtv_player_kernel_exit_closing_state(void);
extern MDI_RESULT mmi_mtv_player_kernel_entry_scanning_state(void);
extern MDI_RESULT mmi_mtv_player_kernel_exit_scanning_state(void);
extern MDI_RESULT mmi_mtv_player_kernel_entry_saving_state(void);
extern MDI_RESULT mmi_mtv_player_kernel_exit_saving_state(void);
extern MDI_RESULT mmi_mtv_player_kernel_entry_opened_state(void);
extern MDI_RESULT mmi_mtv_player_kernel_exit_opened_state(void);
extern MDI_RESULT mmi_mtv_player_kernel_entry_init_state(void);
extern MDI_RESULT mmi_mtv_player_kernel_exit_init_state(void);
extern MDI_RESULT mmi_mtv_player_kernel_entry_ready_state(void);
extern MDI_RESULT mmi_mtv_player_kernel_exit_ready_state(void);
extern MDI_RESULT mmi_mtv_player_kernel_entry_deleting_state(void);
extern MDI_RESULT mmi_mtv_player_kernel_exit_deleting_state(void);


/*player state management*/
extern MDI_RESULT mmi_mtv_player_player_entry_stopped_state(void);
extern MDI_RESULT mmi_mtv_player_player_exit_stopped_state(void);
extern MDI_RESULT mmi_mtv_player_player_entry_bt_connect_state(void);
extern MDI_RESULT mmi_mtv_player_player_exit_bt_connect_state(void);
extern MDI_RESULT mmi_mtv_player_player_entry_play_state(void);
extern MDI_RESULT mmi_mtv_player_player_exit_play_state(void);
/*recorder state management*/
extern MDI_RESULT mmi_mtv_player_recorder_entry_stopped_state(void);
extern MDI_RESULT mmi_mtv_player_recorder_exit_stopped_state(void);
extern MDI_RESULT mmi_mtv_player_recorder_entry_record_state(void);
extern MDI_RESULT mmi_mtv_player_recorder_exit_record_state(void);
extern MDI_RESULT mmi_mtv_player_recorder_entry_save_confirm_state(void);
extern MDI_RESULT mmi_mtv_player_recorder_exit_save_confirm_state(void);
extern MDI_RESULT mmi_mtv_player_recorder_entry_saving_state(void);
extern MDI_RESULT mmi_mtv_player_recorder_exit_saving_state(void);
extern MDI_RESULT mmi_mtv_player_recorder_entry_deleting_state(void);
extern MDI_RESULT mmi_mtv_player_recorder_exit_deleting_state(void);
extern MDI_RESULT mmi_mtv_player_recorder_entry_pause_state(void);
extern MDI_RESULT mmi_mtv_player_recorder_exit_pause_state(void);



extern void mmi_mtv_player_enter_saving_screen(void);
extern void mmi_mtv_player_player_update_cyclic(void);
extern void mmi_mtv_player_enter_deleting_screen(void);
extern void mmi_mtv_player_draw_signal_icon(void);

/* bluetooth */
#if defined(__MMI_MTV_A2DP_SUPPORT__)
#if !defined(__MMI_A2DP_HIDE_BT_SETTINGS__)
void mmi_mtv_player_highlight_bluetooth_setting(void);
#endif
extern void mmi_mtv_player_bt_anim_timeout_hdlr(void);
extern MMI_BOOL mmi_mtv_player_is_output_to_bt(void);
extern void mmi_mtv_player_stop_bt_connecting_anim(void);
extern srv_bt_cm_bt_addr *mmi_mtv_player_get_bt_headset(void);
extern void mmi_mtv_player_bt_open_callback(S32 result);
extern void mmi_mtv_player_disconnect_bt(void);
extern void mmi_mtv_player_bt_close_codec(void);
#endif /* __MMI_MTV_A2DP_SUPPORT__ */

#ifdef __MMI_MTV_AVRCP_SUPPORT__
extern U8 mmi_mtv_player_bt_avrcp_cmd_hdlr(U8 command, mmi_avrcp_key_events event);
#endif

extern void mmi_mtv_player_enable_lsk_function(void);
extern void mmi_mtv_player_disable_lsk_function(void);

extern void mmi_mtv_player_enable_switch_channel_function(void);
extern void mmi_mtv_player_disable_switch_channel_function(void);
extern void mmi_mtv_player_enable_play_function(void);
extern void mmi_mtv_player_disable_play_function(void);


extern void mmi_mtv_player_enable_record_function(void);
extern void mmi_mtv_player_disable_record_function(void);
extern void mmi_mtv_player_enable_fullscreen_function(void);
extern void mmi_mtv_player_reset_jump_to_channel(void);
extern void mmi_mtv_player_disable_fullscreen_function(void);
extern void mmi_mtv_player_enter_scan_channel(void);
extern void mmi_mtv_player_config_functions_by_state(void);
extern void mmi_mtv_player_clear_preview_layer(void);
extern void mmi_mtv_player_record_start_record(void);
extern MMI_BOOL mmi_mtv_player_snapshot(void);
extern void mmi_mtv_player_draw_preview_icon(mtv_player_preview_icon_enum type);
#ifndef __ATV_NO_PHONE_STORAGE__
extern mmi_event_notify_enum mmi_mtv_player_check_storage(BOOL restore, U16 storage);
#else
extern mmi_event_notify_enum mmi_mtv_player_check_storage(void);
#endif

extern void mmi_mtv_player_get_and_update_signal(void);
extern void mmi_mtv_player_enter_save_confirm(void);
extern void mmi_mtv_player_select_channel_to_play(void);
extern void mmi_mtv_player_get_next_filename(CHAR *file_buf_p, CHAR *file_path_p);
extern void mmi_mtv_player_set_flag(mtv_player_bool_status_enum selected_flag);
extern void mmi_mtv_player_unset_flag(mtv_player_bool_status_enum selected_flag) ;
extern MMI_BOOL mmi_mtv_player_is_flag_set(mtv_player_bool_status_enum selected_flag) ;
extern void mmi_mtv_player_animation_draw_after_hdlr(GDI_RESULT result);
extern void mmi_mtv_player_handle_record_discarded(void);

#ifndef GDI_USING_2D_ENGINE_V3 
extern void mmi_mtv_player_sw_rotate(
    U8* pDst,
    U8* pSrc,
    U32 const src_width,
    U32 const src_height);
#endif
void mmi_mtv_player_counter_clockwise_rotate(
    U8* pDst,
    U8* pSrc,
    U32 const dst_width,
    U32 const dst_height,
    gdi_rect_struct *dest_rect);

#endif /* __MMI_ATV_SUPPORT__ */ 
#endif /* _MMI_MOBILE_TV_PLAYER_H_ */ 

