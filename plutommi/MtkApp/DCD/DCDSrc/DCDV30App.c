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
 * DCDV30App.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_OP01_DCD_V30__

#include "dcdagentdefine.h"
#include "mmi_frm_gprot.h"
#include "DateTimeType.h"
#include "worldclock.h"
#include "PhoneSetupGprots.h"
#include "CommonScreens.h"
#include "MMIDataType.h"
#include "MenuCuiGprot.h"
#include "nvram_user_defs.h"
#include "Nvram_enums.h"
#include "Nvram_interface.h"
#include "mmi_rp_app_dcd_def.h"
#include "custom_dcd.h"
#include "DCDV30Prot.h"
#include "DCDV30GProt.h"

#include "mmi_rp_srv_filemanager_def.h"
#include "FileMgrSrvGProt.h"
#include "filemgrcuigprot.h"
#include "Conversions.h"
#include "browser_api.h"
#include "SmsAppGprot.h"
#include "EmailAppGProt.h"
#include "ui_dcd_porting.h"
#include "fseditorcuigprot.h"
#include "app_str.h"
#include "Plx_dcd_wrapper.h"
#include "NwInfoSrvGprot.h"
#include "Wgui_fixed_menus.h"
#include "wgui_categories_popup_op.h"
#include "FilemgrResDef.h"
#include "fs_gprot.h"
#include "USBSrvGprot.h"
//#include "OP01HomeScreen\vadp_p2v_op01_hs.h"
#include "Wgui_categories_util.h"
#include "CommonScreensResDef.h"
#include "Custom_events_notify.h"
#include "FileMgrType.h"
#include "Mms_api.h"
#include "IdleAppResDef.h"


/*****************************************************************************
 * Define
 *****************************************************************************/
#define MMI_DCD_MAX_CTXT_ID_LEN     (20)
#define MMI_DCD_SAVED_TEXT_FLODER "DCD"
#define MMI_DCD_SAVED_TEXT_FORMAT ".txt"
#define MMI_DCD_MAX_URL_LEN       256

/*****************************************************************************
 * Enum
 *****************************************************************************/
typedef enum
{
    DCD_ENTRY_NEXT_ITEM,
    DCD_ENTRY_PRE_ITEM,
    DCD_ENTRY_ITEM_MOVE_ALL
} mmi_dcd_item_move_enum;

typedef enum
{
    DCD_ENTRY_NEXT_PAGE,
    DCD_ENTRY_PRE_PAGE,
    DCD_ENTRY_PAGE_MOVE_ALL
} mmi_dcd_page_move_enum;

typedef enum 
{
	MMI_DCD_AGENT_SHOW_END,
	MMI_DCD_AGENT_SHOW_SHOWING,
	MMI_DCD_AGENT_SHOW_PAUSE,
	MMI_DCD_AGENT_SHOW_TOTAL
}mmi_dcd_agent_show_state;

/*****************************************************************************
 * Struct
 *****************************************************************************/
/* application context strcut */
typedef struct
{
    HDCD_Channel    channel_handle;
    S32             channel_index;
    BRCHAR          channel_id[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    BRCHAR          block_id[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    S32             block_index;
    S32             entry_index;
    BRCHAR          entry_id[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    BRINT           PageOrder;
    U8              update_flag;
    EDCD_VIEW_MODE  view_mode;
} mmi_dcd_app_cntx_struct;

typedef struct
{
    S8 **title_list_pp;
    S8 **time_list_pp;
    S32 story_index;
    S32 story_number;
    S32 pageorder;
    CHAR entry_id[MMI_DCD_MAX_CTXT_ID_LEN + 1];
} mmi_dcd_saved_story_list_struct;

typedef struct
{
    MMI_BOOL        normal_entry;
    MMI_BOOL        normal_exit;
    MMI_BOOL        is_back_from_viewer;
    S32             curr_object;
    S32             object_count;
    S32             objects_index[MAX_DCD_OBJECT_COUNT];
    U16             file_name[SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN + 1];
    S8              src_file_path[(SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) *ENCODING_LENGTH];
    S8              drive_index;
} dcd_viewer_context_struct;

typedef struct
{
    U8  info_str[UPDATE_STR_SIZE * ENCODING_LENGTH];
    U16 scr_id;
} mmi_dcd_refresh_cnxt;

typedef struct
{
    CHAR        entry_id[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    CHAR        block_id[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    S32         PageOrder;
} mmi_dcd_item_move;

typedef struct
{
    WCHAR*      multi_img_path[10];
    S32         img_count;
} mmi_dcd_multi_img_struct;

/*****************************************************************************
 * Declarations
 *****************************************************************************/
static mmi_dcd_app_cntx_struct g_dcd_app_cntx;
static MMI_ID setting_inline_id = GRP_ID_INVALID;
static mmi_dcd_saved_story_list_struct g_saved_story_list_cntx;
static S8   **g_dcd_title_list_pp = NULL;
static S8   **g_dcd_time_list_pp = NULL;             
static S8                *g_help_text_p = NULL;
static U8                g_mmi_dcd_url_type = MMI_DCD_URL_ADD_CHAN;
static dcd_viewer_context_struct  g_dcd_app_viewer;
static mmi_dcd_refresh_cnxt  g_dcd_manual_update;
mmi_dcd_refresh_cnxt  * g_dcd_manual_update_p = &g_dcd_manual_update;  
static MMI_ID filename_editor_cui_id;
static S8* city_name_p[MMI_DCD_MAX_CITY_COUNT];
static U8 g_city_block_count = 0;
static U8 g_default_city_index = 0;
static S32 g_cur_idle_chan_index = 0;
static MMI_BOOL          g_isSyncStopped;
static U8                g_city_list_page_index = 0;
static U8                g_background_list_page_index = 0;
static WCHAR*               g_weather_image_path = NULL;
static WCHAR*               g_news_image_path = NULL;
static WCHAR*               g_preset_content = NULL;
static MMI_BOOL          g_isEntryFromIdle = MMI_FALSE;
static MMI_BOOL          g_CityCntChanged = MMI_FALSE;
static MMI_BOOL          g_DefaultCityChanged = MMI_FALSE;
static MMI_BOOL          g_isCityDeleted = MMI_FALSE;
static MMI_BOOL          g_DefaultCityDeleted = MMI_FALSE;
static S8 *              g_searchCityImgpath = NULL;
static U8 *              g_cityWeatherSummary = NULL;
static U8 *              g_selectCityCode = NULL;
static MMI_BOOL          g_onlyPkgSync = MMI_FALSE;
static MMI_BOOL          g_contentNeedUpdate = MMI_FALSE;
static MMI_BOOL          g_gettingNextPage = MMI_FALSE;
static MMI_BOOL          g_GettingCityList = MMI_FALSE;
static MMI_BOOL          g_GettingStoryContent = MMI_FALSE;
static CHAR*             g_pre_channel_id;
static MMI_ID            g_screen_id = GRP_ID_INVALID;
static mmi_dcd_item_move * g_item_move_req_data_ptr;
static mmi_dcd_multi_img_struct    g_multi_img_ctx;
/* inline cui data strcuture for Setting */
static U16 connection_mode_list[] = 
{
    STR_ID_DCD_CONN_ALWAYS,
    STR_ID_DCD_V30_CONN_HOME_ONLY,
    STR_ID_DCD_CONN_MANUAL
};
static U16 scroll_speed_list[] = 
{
    STR_GLOBAL_MEDIUM,
    STR_GLOBAL_SLOW,
    STR_GLOBAL_FAST

};
static U16 update_mode_list[] = 
{
    STR_ID_UPDATE_MODE_TITLE_ONLY,
    STR_ID_UPDATE_MODE_TITLE_AND_HOMPAGE
};
static U16 no_city_item[] = 
{
    STR_ID_DCD_SETTING_NO_CITY
};
static const cui_inline_item_caption_struct connection_mode_caption = 
{
    STR_ID_DCD_CONN_MODE
};
static const cui_inline_item_select_struct connection_mode_select =
{
    3, 
    0, 
    connection_mode_list
};
static const cui_inline_item_caption_struct scroll_speed_caption = 
{
    STR_ID_DCD_SCROLL_SPEED
};
static const cui_inline_item_select_struct scroll_speed_select =
{
    3, 
    0, 
    scroll_speed_list
};
static const cui_inline_item_caption_struct update_mode_caption = 
{
    STR_ID_DCD_AUTO_UPDATE_OPERATION
};
static const cui_inline_item_select_struct update_mode_select =
{
    2, 
    0, 
    update_mode_list
};
static const cui_inline_item_caption_struct default_city_caption = 
{
    STR_ID_DCD_SETTING_DEFAULT_CITY
};
static const cui_inline_item_select_struct no_city_select =
{
    1, 
    0, 
    no_city_item
};
static const cui_inline_item_softkey_struct mmi_dcd_inline_softkeys =
{
    {
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0}
    }
};
static const cui_inline_set_item_struct g_dcd_settings_inline[] = 
{
    {DCD_SETTING_CONNECTION_MODE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)(&connection_mode_caption)},
    {DCD_SETTING_CONNECTION_MODE, CUI_INLINE_ITEM_TYPE_SELECT , 0, (void*)(&connection_mode_select)},
    {DCD_SETTING_SCROLL_SPEED_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)(&scroll_speed_caption)},
    {DCD_SETTING_SCROLL_SPEED, CUI_INLINE_ITEM_TYPE_SELECT , 0, (void*)(&scroll_speed_select)},
    {DCD_SETTING_UPDATE_MODE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)(&update_mode_caption)},
    {DCD_SETTING_UPDATE_MODE, CUI_INLINE_ITEM_TYPE_SELECT , 0, (void*)(&update_mode_select)},
    {DCD_SETTING_DEFAULT_CITY_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)(&default_city_caption)},
    {DCD_SETTING_DEFAULT_CITY, CUI_INLINE_ITEM_TYPE_SELECT , 0, (void*)(&no_city_select)},
};
static const cui_inline_struct dcd_settings_initial_data = 
{
    DCD_SETTING_INLINE_TOTAL - CUI_INLINE_ITEM_ID_BASE,
    STR_ID_DCD_SYSTEM_SETTING,
    0,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
    &mmi_dcd_inline_softkeys,
    g_dcd_settings_inline
};


static cui_inline_struct network_info_inline_struct = {0};
static cui_inline_set_item_struct network_info_inline_item[8] = {0};
static const cui_inline_item_caption_struct last_update_result_caption = {STR_ID_DCD_LAST_UPDATE_RESULT};
static const cui_inline_item_caption_struct pre_update_time_caption = {STR_ID_DCD_LAST_UPDATE_TIME};
static const cui_inline_item_caption_struct next_update_time_caption = {STR_ID_DCD_NEXT_UPDATE_TIME};
static const cui_inline_item_caption_struct update_error_reason_caption = {STR_ID_DCD_UPDATE_ERROR_REASON};
static cui_inline_item_display_only_struct pre_update_result_display_only = {0};
static cui_inline_item_display_only_struct pre_update_time_display_only = {0};
static cui_inline_item_display_only_struct next_update_time_display_only = {0};
static cui_inline_item_multiline_rdonly_struct error_reason_multi_rdonly_struct = {0};

static cui_inline_item_softkey_struct network_info_softkey_struct = {{
                                        {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE},
                                        {STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
                                        {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE}}};

static void mmi_dcd_entry_channel_list(void);
static void mmi_dcd_create_screen_group(void);
static void mmi_dcd_app_callback(mmi_dcd_event_enum evt, mmi_dcd_sync_req_type_enum sync_type);
static mmi_ret mmi_dcd_proc(mmi_event_struct *evt);
static void mmi_dcd_entry_channel_list_int(void);
static S32 mmi_dcd_get_channel_title_and_time_list(HDCD_Agent agent);
static void mmi_dcd_entry_channel_list_option(void);
static void mmi_dcd_channel_item_highlight_hdlr(S32 item_index);
static void mmi_dcd_entry_manual_update(void);
static void mmi_dcd_channel_list_select_item(mmi_tap_type_enum tap_type,S32 index);
static void mmi_dcd_pre_entry_channel_detail(void);
static void mmi_dcd_pre_entry_background_list(void);
static void mmi_dcd_entry_background_list_page_move(S32 page_index);
static void mmi_dcd_entry_channel_detail(void);
static void mmi_dcd_entry_story_page_move(mmi_dcd_page_move_enum page_move);
static void mmi_dcd_entry_story_item_move(mmi_dcd_item_move_enum item_move);
static void mmi_dcd_channel_detail_rsk_handler(void);
static void mmi_dcd_exit_channel_detail(void);
static void mmi_dcd_pre_entry_story_viewer(void);
static void mmi_dcd_entry_story_viewer(void);
static void mmi_dcd_entry_backgound_list_option(void);
static void mmi_dcd_entry_story_viewer_option(void);
static void mmi_dcd_entry_saved_story_viewer_option(void);
static void mmi_dcd_entry_city_weather_viewer_option(void);
static void mmi_dcd_entry_channel_detail_option(void);
static void mmi_dcd_story_viewer_rsk_handler(void);
static void mmi_dcd_pre_entry_channel_list_from_channel_detail(void);
static void mmi_dcd_entry_channel_list_from_channel_detail(void);
static void mmi_dcd_cui_filename_editor_proc(cui_filename_editor_result_event_struct *result_event);
static void mmi_dcd_save_object_done(void);
static mmi_ret mmi_dcd_file_copy_proc(mmi_event_struct *event);
static void mmi_dcd_pre_entry_object_list(void);
static void mmi_dcd_entry_image_list(void);
static void mmi_dcd_object_list_get_item_index(S32 index);
static pBOOL mmi_dcd_get_object_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static void mmi_dcd_entry_select_storage(void);
static void mmi_dcd_cui_storage_selector_proc(cui_storage_selector_result_event_struct *result_event);
static void mmi_dcd_get_images_folder_path(S8 *path);
static void mmi_dcd_entry_file_name_editor(void);
static void mmi_dcd_save_object(void);
static void mmi_dcd_set_manual_updte_scr_id(U16 update_scr_id);
static void mmi_dcd_entry_background_list(void);
static void mmi_dcd_pre_entry_city_list(S32 page_index);
static void mmi_dcd_entry_city_list(void);
static void mmi_dcd_entry_delete_city_query(void);
static void mmi_dcd_set_default_city(void);
static void mmi_dcd_pre_entry_weather_city(void);
static void mmi_dcd_entry_weather_city(void);
static mmi_ret mmi_dcd_delete_city_confirm_callback(mmi_event_struct *evt);
static void mmi_dcd_delete_city_done(void);
static void mmi_dcd_entry_story_open_link(S8* url);
static void mmi_dcd_pre_entry_my_favorite(void);
static void mmi_dcd_viewer_save_to_my_favorite(void);
static mmi_ret mmi_dcd_save_to_my_favorite_confirm_callback(mmi_event_struct *evt);
static void mmi_dcd_my_favorite_save_done(void);
static MMI_BOOL mmi_dcd_my_favorite_get_icon_path(S32 index, S8 *buf, S32 buflen);
static void mmi_dcd_entry_my_favorite(void);
static void mmi_dcd_get_my_favorite_title_and_time_list(HDCD_Agent agent);
static MMI_BOOL mmi_dcd_time_string_fomat(char *issued_time, char *format_time, kal_int32 dest_size);
static void mmi_dcd_pre_entry_saved_story_viewer(mmi_tap_type_enum tap_type, S32 index);
static void mmi_dcd_entry_saved_story_viewer(void);
static void mmi_dcd_my_favorite_delete_confirm(void);
static mmi_ret mmi_dcd_my_favorite_delete_confirm_callback(mmi_event_struct *evt);
static void mmi_dcd_entry_my_favorite_option(void);
static void mmi_dcd_my_favorite_delete_done(void);
static void mmi_dcd_my_favorite_delete_callback(void);
static void mmi_dcd_entry_setting_screen(void);
static mmi_ret mmi_dcd_entry_setting_screen_inline_cui_proc(mmi_event_struct* evt);
static void mmi_dcd_setting_inline_set_city_list(void);
static void mmi_dcd_entry_setting_option(void);
static mmi_ret mmi_dcd_setting_option_proc(mmi_event_struct *evt);
static void mmi_dcd_setting_save(void);
static void mmi_dcd_setting_save_done(MMI_BOOL success);
static MMI_BOOL mmi_dcd_setting_set_default_city(void);
static void mmi_dcd_entry_forward_sms(void);
static void mmi_dcd_entry_forward_mms(void);
static void mmi_dcd_entry_forward_email(void);
static void mmi_dcd_entry_help_info(void);
static void mmi_dcd_exit_help_info(void);
static void mmi_dcd_enter_help_info_page(void);
static void mmi_dcd_help_info_callback(S32 selected_idx);
static void mmi_dcd_entry_network_info(void);
static mmi_ret mmi_dcd_entry_network_info_inline_cui_proc(mmi_event_struct* evt);
static void mmi_dcd_entry_switch_off_prompt(void);
static mmi_ret mmi_dcd_switch_off_confirm_callback(mmi_event_struct *evt);
static void mmi_dcd_entry_switch_off_prompt_ext(void);
static mmi_ret mmi_dcd_switch_on_confirm_callback(mmi_event_struct *evt);
static void mmi_dcd_switch_off_done(void);
static void mmi_dcd_wakeup_prompt(void);
static void mmi_dcd_switch(MMI_BOOL on);
static void mmi_dcd_entry_channal_list_external_done(void);
static S32 mmi_dcd_get_channel_entry_count(HDCD_Channel channel_handle);
static MMI_BOOL mmi_dcd_channel_list_get_icon(S32 item_index, S8* path);
static MMI_BOOL mmi_dcd_channel_get_icon_path(HDCD_Agent agent, S32 index, S8 * buf, S32 buflen);
static void mmi_dcd_launch_wap_browser(void);
static void mmi_dcd_set_url_type(U8 url_type);
static void mmi_dcd_settings_reset_confirm(void);
static mmi_ret mmi_dcd_setting_reset_confirm_callback(mmi_event_struct *evt);
static void mmi_dcd_settings_reset(void);
static HDCD_Entry mmi_dcd_get_current_entry(HDCD_Agent agent_handle);
static HDCD_Story mmi_dcd_get_current_story(HDCD_Entry entry_handle);
static void mmi_dcd_entry_city_search_edit_done(MMI_ID gid);
static void mmi_dcd_entry_search_city(CHAR *city);
static MMI_BOOL mmi_dcd_url_encode(CHAR *src, CHAR *dest, U32 src_len);
static void mmi_dcd_entry_connect_sync(void);
static void mmi_dcd_get_entry_content_complete(MMI_BOOL pkg_complete);
static mmi_ret mmi_dcd_content_sync_screen_leave_proc (mmi_event_struct *evt);
static void mmi_dcd_abort_content_sync(void);
static void mmi_dcd_get_entry_content_refresh(void);
static void mmi_dcd_get_background_list_complete(void);
static void mmi_dcd_get_city_list_complete(void);
static void mmi_dcd_search_city_complete(void);
static void mmi_dcd_add_search_city_to_list(void);
static void mmi_dcd_add_city_complete(void);
static void mmi_dcd_delete_city_complete(void);
static void mmi_dcd_entry_add_city_confirm(void);
static void mmi_dcd_main_update_complete(MMI_BOOL pkg_complete);
static void mmi_dcd_manual_update_complete(MMI_BOOL pkg_complete);
static void mmi_dcd_sync_fail(mmi_dcd_sync_req_type_enum sync_type, mmi_dcd_event_enum error_evt);
static HDCD_Entry mmi_dcd_get_newest_unread_entry(HDCD_Channel channel_handle);
static void mmi_dcd_pre_entry_manual_update(void);
static void mmi_dcd_entry_roaming_maunul_mode_prompt(void);
static void mmi_dcd_entry_manual_update_prompt(void);
static void mmi_dcd_entry_manual_update_roaming_prompt(void);
static void mmi_dcd_abort_manual_update(void);
static void mmi_dcd_refresh_channel_detail(void);
static void mmi_dcd_refresh_weather_city(void);
static void mmi_dcd_exit_add_city_confirm(void);
static void mmi_dcd_entry_add_city_selected_query(CHAR * city_code);
static mmi_ret mmi_dcd_add_city_selected_confirm_callback(mmi_event_struct *evt);
static void mmi_dcd_add_city_selected_to_list(void);
static void mmi_dcd_pre_entry_preset_channel_detail(void);
static void mmi_dcd_entry_preset_channel_detail(void);
static void mmi_dcd_add_channel_handler(void);
static void mmi_dcd_story_content_request(void);
static void mmi_dcd_entry_get_next_story_page(void);
static void mmi_dcd_manual_update_storage_full(void);
static void mmi_dcd_get_city_block_focus(void);
static CHAR* mmi_dcd_get_default_city_id(HDCD_Agent agent_handle);
mmi_ret mmi_dcd_manual_update_retry_confirm_callback(mmi_event_struct *evt);
static WCHAR * mmi_dcd_get_sync_code_info_str(EDCD_SYNC_ERROR_STATUS error_code);
static void mmi_dcd_sync_insufficient_memory(void);
static void mmi_dcd_channel_list_from_channel_detail_rsk_hdlr(void);
static mmi_ret mmi_dcd_insufficient_memory_popup_exit(mmi_event_struct *evt);
static void mmi_dcd_city_weather_viewer_rsk_handler(void);
extern void vadp_p2v_hs_update_dcd_news_img(void);
extern void vadp_p2v_hs_update_dcd_news_content(void);
extern void vadp_p2v_hs_update_dcd_whether_area(void);
static void mmi_dcd_entry_saved_text(void);
static S32 mmi_dcd_init_saved_text_folder(void);
static void mmi_dcd_init_saved_text_file(void);
static void mmi_dcd_get_multi_img_callback(U16 index, WCHAR* file_path, MMI_BOOL need_continue);
/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_initialize
 * DESCRIPTION
 *  initialize for dcd v30
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_dcd_initialize(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_INITALITZE);
    ret = mmi_dcd_srv_initialize(mmi_dcd_app_callback);
    if (!ret)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_INITALITZE_FAIL);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_app_callback
 * DESCRIPTION
 *  callback function for srv
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_dcd_app_callback(mmi_dcd_event_enum evt, mmi_dcd_sync_req_type_enum sync_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_CALLBACK, evt);
    switch (evt)
    {

        case DCD_EVT_MAIN_SYNCPKG_SYNC_COMPLETE:
            mmi_dcd_main_update_complete(MMI_TRUE);
            break;
    
        case DCD_EVT_MAIN_SYNC_COMPLETE:
            // main sync complete, app may need to update the screen, eg. channel list screen
            mmi_dcd_main_update_complete(MMI_FALSE);
            break;

        case DCD_EVT_USER_SYNCPKG_SYNC_COMPLETE:
            mmi_dcd_manual_update_complete(MMI_TRUE);
            break;
            
        case DCD_EVT_USER_SYNC_COMPLETE:
            // user manual update complete, app should close the waiting screen, and pop up "success"
            mmi_dcd_manual_update_complete(MMI_FALSE);
            break;

        case DCD_EVT_GETENTRYCONTENT_SYNC_COMPLETE:
            mmi_dcd_get_entry_content_complete(MMI_TRUE);
            break;

        case DCD_EVT_GETDATA2_SYNC_COMPLETE:
            // get entry content complete, app should close the waiting screen, and pop up "success"
            mmi_dcd_get_entry_content_complete(MMI_FALSE);
            break;

        case DCD_EVT_GETBACKGROUNDLIST_SYNC_COMPLETE:
            // get backgroundlist complete, app should close the waiting screen, and pop up "success"
            mmi_dcd_get_background_list_complete();
            break;

        case DCD_EVT_SEARCHCITY_SYNC_COMPLETE:
            // search citylist complete, app should close the waiting screen, and pop up "success"
            mmi_dcd_search_city_complete();
            break;

        case DCD_EVT_GETCITYLIST_SYNC_COMPLETE:
            // get citylist complete, app should close the waiting screen, and pop up "success"
            mmi_dcd_get_city_list_complete();
            break;

        case DCD_EVT_ADDWEATHERCITY_SYNC_COMPLETE:
            // addweather city complete, app should close the waiting screen, and pop up "success"
            mmi_dcd_add_city_complete();
            break;

        case DCD_EVT_DELETEWEATHERCITY_SYNC_COMPLETE:
            // delete weather city complete, app should close the waiting screen, and pop up "success"
            mmi_dcd_delete_city_complete();
            break;
        case DCD_EVT_ERR_STORAGE_FULL:
            mmi_dcd_manual_update_storage_full();
            break;
            
        case DCD_EVT_ERR_INSUFFICIENT_MEMORY:
            mmi_dcd_sync_insufficient_memory();
            break;

        case DCD_EVT_ERR_NOT_FOUND_RESOURCE:
        case DCD_EVT_ERR_SYNTEX:
        case DCD_EVT_ERR_OTHER_CERTIFY:  
        case DCD_EVT_ERR_INTERNAL_SYSTEM:
        case DCD_EVT_ERR_TRAFFIC_CONTROL:
        case DCD_EVT_ERR_NOT_SUPPORT_TERMINAL:
        case DCD_EVT_ERR_NOT_REGISTER_USER:
        case DCD_EVT_ERR_VERSION_NUMBER:
        case DCD_EVT_ERR_VERSION_EXPIRED:
        case DCD_EVT_ERR_LATEST_VERSION:
        case DCD_EVT_ERR_SYNCPKG_PARSING:
        case DCD_EVT_ERR_NO_SYNCPKG:
        case DCD_EVT_ERR_CONTENT_PARSING:
        case DCD_EVT_ERR_NO_CONTENT:
        case DCD_EVT_ERR_NETWORK_DISABLE:
        case DCD_EVT_ERR_NETWORK_BUSY:
        case DCD_EVT_ERR_CONNECT_TIME_OUT:
        case DCD_EVT_ERR_FAIL_REMOVE_CITY:
        case DCD_EVT_ERR_BEFORE_BUY_CITY:
        case DCD_EVT_ERR_NOT_EXIST_CITY:
        case DCD_EVT_ERR_FULL_BUY_CITY_COUNT:
        case DCD_EVT_ERR_DOWNLOAD_SYNCPKG:
        case DCD_EVT_ERR_DOWNLOAD_CONTENT:
        case DCD_EVT_ERR_DOWNLOAD_APPPKG:
        case DCD_EVT_ERR_SYNC_FAIL:
            // sync fail, app should popup to user for retry or cancel the sync process
            mmi_dcd_sync_fail(sync_type, evt);
            break;

        case DCD_EVT_WAKE_UP:
            // server wap push, dcd should be waked up if it is off
            mmi_dcd_wakeup_prompt();
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_create_screen_group
 * DESCRIPTION
 *  create dcd 3.0 screen group
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_create_screen_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_DCD))
    {
        mmi_frm_group_close(GRP_ID_DCD);
    }
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_DCD, mmi_dcd_proc, NULL);
    mmi_frm_group_enter(GRP_ID_DCD, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_dcd_app_cntx.view_mode = eDCD_VIEW_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_proc
 * DESCRIPTION
 *  event proc of dcd group
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_dcd_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_event;
    menu_event = (cui_menu_event_struct*)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_PROC, evt->evt_id);
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch (menu_event->highlighted_menu_id)
            {
                case MENU_ID_DCD_ADD_CITY:
                    mmi_dcd_pre_entry_city_list(0);
                    break;
                    
                case MENU_ID_DCD_DELETE_CITY:
                    mmi_dcd_entry_delete_city_query();
                    break;
                    
                case MENU_ID_DCD_SET_AS_DEFAULT_CITY:
                    mmi_dcd_set_default_city();
                    break;    
                    
                case MENU_ID_DCD_CHANNEL_MANAGEMENT:
                    break;
                    
                case MENU_ID_DCD_ADD_CHANNEL:
                    mmi_dcd_add_channel_handler();
                    break;
                    
                case MENU_ID_DCD_DELETE_CHANNEL:
                    mmi_dcd_set_url_type(MMI_DCD_URL_DEL_CHAN);
                    mmi_dcd_launch_wap_browser();
                    break;
                    
                case MENU_ID_DCD_MANUAL_UPDATE:
                    mmi_dcd_pre_entry_manual_update();
                    break;
                    
                case MENU_ID_DCD_MY_FAVORITE:
                    mmi_dcd_pre_entry_my_favorite();
                    break;
                    
                case MENU_ID_DCD_SAVE_TO_MY_FAVORITE:
                    mmi_dcd_viewer_save_to_my_favorite();
                    break;
                    
                case MENU_ID_DCD_SYSTEM_SETTING:
                    mmi_dcd_setting_inline_set_city_list();
                    mmi_dcd_entry_setting_screen();
                    break;
                    
                case MENU_ID_DCD_HELP:
                    mmi_dcd_entry_help_info();
                    break;
                    
                case MENU_ID_DCD_NETWORK_INFO:
                    mmi_dcd_entry_network_info();
                    break;
                    
                case MENU_ID_DCD_CLOSE_DCD:
                    mmi_dcd_entry_switch_off_prompt();
                    break;
                    
                case MENU_ID_DCD_DELETE_FROM_MY_FAVORITE:
                    mmi_dcd_my_favorite_delete_confirm();
                    break;

                case MENU_ID_DCD_CHANNEL_LIST:
                    mmi_dcd_pre_entry_channel_list_from_channel_detail();
                    break;
                    
                case MENU_ID_DCD_SAVE_PICTURE:
                    mmi_dcd_pre_entry_object_list();
                    break;

                case MENU_ID_DCD_SAVE_TEXT:
                    mmi_dcd_entry_saved_text();
                    break;
                    
                case MENU_ID_DCD_FORWARD_AS_SMS:
                    mmi_dcd_entry_forward_sms();
                    break;

                case MENU_ID_DCD_FORWARD_AS_MMS:
                    mmi_dcd_entry_forward_mms();
                    break;

                case MENU_ID_DCD_FORWARD_AS_EMAIL:
                    mmi_dcd_entry_forward_email();
                    break;
            }
            break;
            
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            menu_event = (cui_menu_event_struct*)evt;
            cui_menu_close(menu_event->sender_id);
            break;

        case EVT_ID_CUI_STORAGE_SELECTOR_RESULT:
        {
            mmi_dcd_cui_storage_selector_proc((cui_storage_selector_result_event_struct *)evt);
            break;
        }  

        case EVT_ID_CUI_FILENAME_EDITOR_RESULT:
        {
            mmi_dcd_cui_filename_editor_proc((cui_filename_editor_result_event_struct *)evt);
            break;
        }

        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        {
            cui_fseditor_evt_struct *fsedit_evt = (cui_fseditor_evt_struct*)evt;
            mmi_dcd_entry_city_search_edit_done(fsedit_evt->sender_id);
            break;
        }

        case EVT_ID_CUI_FSEDITOR_ABORT:
        {
            cui_fseditor_evt_struct *fsedit_evt = (cui_fseditor_evt_struct*)evt;
            cui_fseditor_close(fsedit_evt->sender_id);
            break;
        }

        case EVT_ID_GROUP_DEINIT:
            g_dcd_app_viewer.normal_exit = MMI_TRUE;
            g_dcd_app_cntx.view_mode = eDCD_VIEW_IDLE;
            if (g_item_move_req_data_ptr)
            {
                OslMfree(g_item_move_req_data_ptr);
                g_item_move_req_data_ptr = NULL;
            }
            g_DefaultCityDeleted = MMI_FALSE;
            break;
            
        default:
            break;
    }

    return MMI_RET_OK; 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_cui_filename_editor_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_cui_filename_editor_proc(cui_filename_editor_result_event_struct *result_event)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (result_event->result > 0)
    {
        mmi_dcd_save_object_done();
    }
    else
    {
        cui_filename_editor_close(result_event->sender_id);
        mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_IMAGE_LIST);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_save_object_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_save_object_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Entry entry_handle = NULL;
    HDCD_Story story_handle = NULL;
    HDCD_Content content_handle = NULL;
    EDCD_AGENT_RESULT result = eDCD_ERR_UNKNOWN;
    BRSTR object_type = NULL;
    U16 *dest_file_path = NULL;
    U16 *temp = NULL;
    S8 *postfix = NULL;
    S32 content_len = 0;
    MMI_BOOL content_valid = MMI_TRUE;
    S32 ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check entry handle */
    agent_handle = mmi_dcd_get_agent_handle();
    entry_handle = mmi_dcd_get_current_entry(agent_handle);
    if (!entry_handle)
    {
        content_valid = MMI_FALSE;
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__); 
    }
    else
    {
        dest_file_path = (U16*)OslMalloc((SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * sizeof(U16));
        temp = OslMalloc(SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1);
        memset(temp, 0, SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1);
        memset(g_dcd_app_viewer.src_file_path, 0, (SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);

        story_handle = mmi_dcd_get_current_story(entry_handle);
        if (story_handle)
        {
            content_handle = emDCDAgent_GetStoryContentAt(story_handle, g_dcd_app_viewer.objects_index[g_dcd_app_viewer.curr_object]);
            if (content_handle)
            {
                content_len = emDCDAgent_GetContentLength(content_handle);
                if (content_len)
                {
                    result = emDCDAgent_GetContentFullPath(
                        content_handle, 
                        (BRSTR)temp, 
                        SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
            
                    if (result == eDCD_SUCCESS)
                    {
                        mmi_chset_utf8_to_ucs2_string(
                            (kal_uint8*)g_dcd_app_viewer.src_file_path,
                            (SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            (kal_uint8*)temp);

                        /* name of the dest image */
                        mmi_dcd_get_images_folder_path((S8*)temp);
                        mmi_wcscpy(dest_file_path, temp);
                        mmi_wcscat(dest_file_path, g_dcd_app_viewer.file_name);
                        mmi_asc_to_wcs(temp, ".");
                        mmi_wcscat(dest_file_path, temp);
                        object_type = emDCDAgent_GetContentType(content_handle);
                        postfix = strchr(object_type, '/');
                        postfix++;
                        mmi_asc_to_wcs(temp, postfix);
                        mmi_wcscat(dest_file_path, temp);

                        /* copy the image */
                        ret = srv_fmgr_async_copy(
                                (WCHAR*)g_dcd_app_viewer.src_file_path,
                                (WCHAR*)dest_file_path,
                                0,
                                mmi_dcd_file_copy_proc,
                                NULL);
                        kal_wap_trace(MOD_MMI_CONN_APP, TRACE_INFO, "[DCD][APP] srv_fmgr_async_copy ret is %d", ret);
                    }
                    else
                    {
                        content_valid = MMI_FALSE;
                        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
                    }
                }
                else
                {
                    content_valid = MMI_FALSE;
                    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
                }
            }
            else
            {
                content_valid = MMI_FALSE;
                MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
            }
        }
        else
        {
            content_valid = MMI_FALSE;
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
        }
        
        OslMfree(dest_file_path);
        OslMfree(temp);
    }

    if (!content_valid)
    {
        /* invalid handle, just popup and return */
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
        cui_filename_editor_close(filename_editor_cui_id);
        mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_IMAGE_LIST);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_file_copy_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  event     [IN]        Variable stores the result of copy
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_file_copy_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(event->evt_id)
    {
		case EVT_ID_SRV_FMGR_ASYNC_DONE:
		{		
			srv_fmgr_async_done_event_struct *async_evt = (srv_fmgr_async_done_event_struct *)event;

            kal_wap_trace(MOD_MMI_CONN_APP, TRACE_INFO, "[DCD][APP] mmi_dcd_file_copy_proc result is %d", async_evt->result);
            
            if (async_evt->result >= 0)
            {
                mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, NULL);
                cui_filename_editor_close(filename_editor_cui_id);
                mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_IMAGE_LIST);
            }
            else
            {
                mmi_popup_display(
                    (WCHAR*)GetString((U16) srv_fmgr_fs_error_get_string(async_evt->result)), 
                    (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(async_evt->result), 
                    NULL);
                if (async_evt->result != FS_PATH_OVER_LEN_ERROR &&
                    async_evt->result != FS_FILE_EXISTS &&
                    async_evt->result != FS_INVALID_FILENAME)
                {
                    cui_filename_editor_close(filename_editor_cui_id);
                    mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_IMAGE_LIST);
                }
            }
			break;
		}

        default:
            break;
    }
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_channel_list
 * DESCRIPTION
 *  entry channel list screen from external
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_channel_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dcd_create_screen_group();
    mmi_dcd_entry_channel_list_int();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_channel_title_and_time_list
 * DESCRIPTION
 *  get dcd channel title
 * PARAMETERS
 *  agent               [IN] dcd agent handle  
 *  index               [IN] channel index
 *  buf                 [IN] channel title buffer
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_dcd_get_channel_title_and_time_list(HDCD_Agent agent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32             entry_cnt, channel_cnt;
    S8  *           title;
    HDCD_Channel    hChannel;
    S8              asc_buf[5];
    S8              ucs_buf[16];
    S32             char_num, chan_index;
    MMI_BOOL        is_truncated = MMI_FALSE;
    S32             buflen, offset;
    S8  *           buf;
    S32             save_entry_cnt = 0;
    S8 *            subject = NULL;
    char            *issued_time;
    MMI_BOOL        only_pre_channel = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    channel_cnt = emDCDAgent_GetChannelCount(agent);
    if (channel_cnt <= 0)
    {
        only_pre_channel = MMI_TRUE;
        channel_cnt = emDCDAgent_GetPreChannelCount(agent);
    }
    else if (channel_cnt > MMI_DCD_MAX_CHANNEL_COUNT)
    {
        channel_cnt = MMI_DCD_MAX_CHANNEL_COUNT;
    }

    /* alloc memory for title */
    buflen = (sizeof(S8*) + MMI_DCD_CHANNEL_TITLE_LEN) * (channel_cnt + 1);
    g_dcd_title_list_pp = (S8**)applib_mem_screen_alloc(buflen);
    memset(g_dcd_title_list_pp, 0, buflen);

    /* alloc memory for time */
    buflen = (sizeof(S8*) + (19 + 1) * ENCODING_LENGTH) * (channel_cnt + 1);
    g_dcd_time_list_pp = (S8**)applib_mem_screen_alloc(buflen);
    memset(g_dcd_time_list_pp, 0, buflen);

    for (chan_index = 0; chan_index < channel_cnt; chan_index++)
    {

        buflen = MMI_DCD_CHANNEL_TITLE_LEN;
        if (only_pre_channel)
        {
            hChannel = emDCDAgent_GetPreChannelAt(agent, chan_index);
        }
        else
        {
            hChannel = emDCDAgent_GetChannelAt(agent, chan_index);
            entry_cnt = mmi_dcd_get_channel_entry_count(hChannel);
    	    sprintf(asc_buf, "(%d)", entry_cnt);
            buflen -= strlen(asc_buf) * 2;
        }


        offset = sizeof(S8*) * (channel_cnt + 1) + MMI_DCD_CHANNEL_TITLE_LEN * chan_index;
        buf = g_dcd_title_list_pp[chan_index] = (S8*)g_dcd_title_list_pp + offset;
        
	    title = emDCDAgent_GetChannelTitle(hChannel);
        /* title = emDCDAgent_GetChannelSummary(hChannel); */
        char_num = mmi_chset_utf8_strlen((kal_uint8*)title);
        is_truncated = MMI_FALSE;
        if ( char_num >= buflen / 2)
        {
            is_truncated = MMI_TRUE;
            buflen -= 4;
        }
	    /* include null terminal */
        mmi_chset_utf8_to_ucs2_string((kal_uint8 *)buf, buflen, (kal_uint8 *)title );
        if (is_truncated)
        {
            app_ucs2_strcat((kal_int8 *)buf, (kal_int8 *)L"..");
        }
        if (!only_pre_channel)
        {
            app_asc_str_to_ucs2_str((kal_int8 *)ucs_buf, (kal_int8 *)asc_buf);
            app_ucs2_strcat((kal_int8 *)buf, (kal_int8 *)ucs_buf);

        }

        /* get time, milliseconds string */
        issued_time = (char*)emDCDAgent_GetChannelIssuedTime(hChannel);
        offset = sizeof(S8*) * (channel_cnt + 1) + (19 + 1) * ENCODING_LENGTH * chan_index;
        buf = g_dcd_time_list_pp[chan_index] = (S8*)g_dcd_time_list_pp + offset;
        buflen = (19 + 1) * ENCODING_LENGTH;
        if (issued_time && strlen(issued_time) > 0)
        {
            mmi_dcd_time_string_fomat(issued_time, (char*)buf, (kal_int32)buflen);
        }
        else
        {
            /* for preset channel, should not display the time */
            app_ucs2_strcat((kal_int8*)buf, (kal_int8*)L" ");
        }
    }

    /* title for my favorite */
    offset = sizeof(S8*) * (channel_cnt + 1) + MMI_DCD_CHANNEL_TITLE_LEN * channel_cnt;
    buf = (g_dcd_title_list_pp[channel_cnt]) = (S8*)g_dcd_title_list_pp + offset;
    subject = GetString(STR_ID_DCD_MY_FAVORITE);
    mmi_ucs2cpy((CHAR*)buf, (CHAR*)subject);
    save_entry_cnt = emDCDAgent_GetPermanenceEntryCount	(agent);
    sprintf(asc_buf, "(%d)", save_entry_cnt);
    app_asc_str_to_ucs2_str((kal_int8 *)ucs_buf, (kal_int8 *)asc_buf);
    app_ucs2_strcat((kal_int8 *)buf, (kal_int8 *)ucs_buf);

    /* time for my favorite */
    offset = sizeof(S8*) * (channel_cnt + 1) + (19 + 1) * ENCODING_LENGTH * chan_index;
    buf = g_dcd_time_list_pp[channel_cnt] = (S8*)g_dcd_time_list_pp + offset;
    buf[0] = buf[1] = 0;
    app_ucs2_strcat((kal_int8*)buf, (kal_int8*)L" ");
    return channel_cnt;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_channel_list_get_icon
 * DESCRIPTION
 *  get icon of specific channel
 * PARAMETERS
 *  item_index  [in]    item index
 *  path        [out]   icon path
 * RETURNS
 * TRUE/FALSE
 *****************************************************************************/
MMI_BOOL mmi_dcd_channel_list_get_icon(S32 item_index, S8* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    result = MMI_FALSE;
    S32         buflen = SRV_FMGR_PATH_MAX_LEN;
    HDCD_Agent agent_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    agent_handle = mmi_dcd_get_agent_handle();
    if (agent_handle)
    {
        result = mmi_dcd_channel_get_icon_path(agent_handle, item_index, path, buflen);
    }
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_channel_get_icon_path
 * DESCRIPTION
 *  get dcd channel icon
 * PARAMETERS
 *  agent       [IN]        dcd agent handle
 *  index       [IN]        channel index
 *  buf         [IN]        channel title buffer
 *  buflen      [IN]        buffer len
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dcd_channel_get_icon_path(HDCD_Agent agent, S32 index, S8 * buf, S32 buflen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL        is_image_exist = MMI_FALSE;
    HDCD_Channel    hChannel;
    EDCD_AGENT_RESULT result;
    S32             nChannelCnt;
    S32             i, nContentCnt;
    HDCD_Content    pContent;
    CHAR            *content_type;
    S8 *            path_buf = NULL;
    MMI_BOOL        preset_only = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nChannelCnt = emDCDAgent_GetChannelCount(agent);
    if (nChannelCnt <= 0)
    {
        nChannelCnt = emDCDAgent_GetPreChannelCount(agent);
        preset_only = MMI_TRUE;
    }
    
    if (index >= nChannelCnt)
    {
        return MMI_FALSE;
    }
    if (preset_only)
    {
        hChannel = emDCDAgent_GetPreChannelAt(agent, index);
    }
    else
    {
        hChannel = emDCDAgent_GetChannelAt(agent, index);
    }
    nContentCnt = emDCDAgent_GetChannelContentCount(hChannel);
    path_buf = OslMalloc(SRV_FMGR_PATH_MAX_LEN + 1);
    memset(path_buf, 0, SRV_FMGR_PATH_MAX_LEN + 1);
    for( i = 0; i < nContentCnt; i++)
    {
        pContent = emDCDAgent_GetChannelContentAt(hChannel, i);
        content_type = emDCDAgent_GetContentType(pContent);
        if (app_strnicmp((kal_char*)content_type, "image/", 6) == 0)
        {
			result = emDCDAgent_GetContentFullPath(pContent, path_buf, SRV_FMGR_PATH_MAX_LEN);
            if (result == eDCD_SUCCESS)
            {
                is_image_exist = MMI_TRUE;
                break; 
            }
        }
    }
 
	if (!is_image_exist)
    {
        memset(buf, 0, sizeof(buf));
	}
    else
    {
        mmi_chset_utf8_to_ucs2_string((kal_uint8 *)buf, buflen, (kal_uint8 *)path_buf);
    }

    if (path_buf)
    {
        OslMfree(path_buf);
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_exit_channel_list_screen
 * DESCRIPTION
 *  exit channel list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_exit_channel_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dcd_title_list_pp)
    {
        applib_mem_screen_free(g_dcd_title_list_pp);
        g_dcd_title_list_pp = NULL;
    }

    if (g_dcd_time_list_pp)
    {
        applib_mem_screen_free(g_dcd_time_list_pp);
        g_dcd_time_list_pp = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_channel_list_int
 * DESCRIPTION
 *  entry channel list screen
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_channel_list_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    HDCD_Agent agent_handle = NULL;
    S32 channel_cnt = 0;
    U8  read_state_list[MMI_DCD_MAX_CHANNEL_COUNT] = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ENTRY_CHANNEL_LIST_INT); 
    
    if (!mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_CHANNEL_LIST,
        mmi_dcd_exit_channel_list_screen, mmi_dcd_entry_channel_list_int, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    g_dcd_app_cntx.view_mode = eDCD_VIEW_IDLE;
    
    agent_handle = mmi_dcd_get_agent_handle();
    channel_cnt = mmi_dcd_get_channel_title_and_time_list(agent_handle);
    RegisterHighlightHandler(mmi_dcd_channel_item_highlight_hdlr);
    
	wgui_cat9005_op01_show(
        (UI_string_type)GetString(STR_ID_DCD),
        NULL,
        (UI_string_type)GetString(STR_GLOBAL_OPTIONS),
        (PU8)GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type)GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        channel_cnt + 1,
        (U8**)g_dcd_title_list_pp,
        (U8**)g_dcd_time_list_pp,
        mmi_dcd_channel_list_get_icon,
        read_state_list,
        0,
        gui_buffer,
        MMI_FALSE);

    wgui_register_tap_callback(mmi_dcd_channel_list_select_item);
    SetLeftSoftkeyFunction(mmi_dcd_entry_channel_list_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_channel_item_highlight_hdlr
 * DESCRIPTION
 *  channel item highlight handler
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_channel_item_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    S32 channel_cnt = 0;
    MMI_BOOL preset_only = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    agent_handle = mmi_dcd_get_agent_handle();
    channel_cnt = emDCDAgent_GetChannelCount(agent_handle);
    if (channel_cnt <= 0)
    {
        channel_cnt = emDCDAgent_GetPreChannelCount(agent_handle);
        preset_only = MMI_TRUE;
    }
    
    if (item_index < channel_cnt)
    {
        g_dcd_app_cntx.channel_index = item_index;
        if (preset_only)
        {
            g_dcd_app_cntx.channel_handle = emDCDAgent_GetPreChannelAt(agent_handle, g_dcd_app_cntx.channel_index);
        }
        else
        {
            g_dcd_app_cntx.channel_handle = emDCDAgent_GetChannelAt(agent_handle, g_dcd_app_cntx.channel_index);
        }
       strcpy(g_dcd_app_cntx.channel_id, emDCDAgent_GetChannelID(g_dcd_app_cntx.channel_handle));
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_channel_list_option
 * DESCRIPTION
 *  entry channel list option screen
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_channel_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_id = cui_menu_create(
                    GRP_ID_DCD,
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_FROM_RESOURCE,
                    MENU_ID_DCD_CHANNEL_LIST_OPTION,
                    MMI_TRUE,
                    NULL);
    cui_menu_run(menu_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_channel_entry_count
 * DESCRIPTION
 *  get entry count for each channel including weather
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_dcd_get_channel_entry_count(HDCD_Channel channel_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 block_cnt = 0;
    S32 block_index = 0;
    HDCD_Block hBlock = NULL;
    S32 entry_cnt = 0;
    EDCD_CHANNEL_TYPE channel_type;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    channel_type = emDCDAgent_GetChannelType(channel_handle);
    block_cnt = emDCDAgent_GetChannelBlockCount(channel_handle);
    if (channel_type == eDCD_CHANNEL_WEATHER)
    {
        return block_cnt;
    }
    else
    {
        for (block_index = 0; block_index < block_cnt; block_index++)
        {
            hBlock = emDCDAgent_GetChannelBlockAt(channel_handle, block_index);
            if (!hBlock)
            {
                break;
            }
            entry_cnt += emDCDAgent_GetBlockEntryCount(hBlock);
        }
        return entry_cnt;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_pre_entry_city_list
 * DESCRIPTION
 *  mmi_dcd_pre_entry_city_list
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_pre_entry_city_list(S32 page_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR url[MMI_DCD_MAX_URL_LEN];
    MMI_BOOL result = MMI_FALSE;
    MMI_BOOL is_syncing = MMI_FALSE;
    U32 start = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_PRE_ENTRY_CITY_LIST, page_index);
    g_city_list_page_index = page_index;
    {
        memset(url, 0, sizeof(url));
        start = MAX_DCD_CITY_ITEM_NUM_PER_PAGE * page_index + 1;
        sprintf(url, "start=%d&count=%d", start, MAX_DCD_CITY_ITEM_NUM_PER_PAGE);    

        result = mmi_dcd_user_to_sync(DCD_SYNC_REQ_TYPE_GETCITYLIST, url, &is_syncing);
        if (!result)
        {
            mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
        }
        else if (is_syncing == MMI_TRUE)
        {
            mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_V30_BACKGROUND_SYNC_PROGRESS), MMI_EVENT_FAILURE, NULL);
        }
        else
        {
            g_GettingCityList = MMI_TRUE;
            mmi_dcd_entry_connect_sync();
            g_isSyncStopped = MMI_FALSE;
            g_CityCntChanged = MMI_FALSE;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_city_list
 * DESCRIPTION
 *  mmi_dcd_entry_city_list
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_city_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    U8 *gui_buffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ENTRY_CITY_LIST);
    if (mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_ADD_CITY, mmi_dcd_exit_channel_detail, mmi_dcd_entry_city_list, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
    {
        return;
    }
    
    agent_handle = mmi_dcd_get_agent_handle();
    g_dcd_app_cntx.view_mode = eDCD_VIEW_CITY_LIST;

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    if ((g_dcd_app_viewer.normal_entry) || (g_CityCntChanged) || (g_contentNeedUpdate))
    {
        mmi_dcd_show_end(agent_handle);
        g_CityCntChanged = MMI_FALSE;
        g_contentNeedUpdate = MMI_FALSE;
    }
    else
    {
        mmi_dcd_show_pause(agent_handle);
    }

    emDCDAgent_SetStoryViewerID(agent_handle, NULL, NULL, NULL, g_city_list_page_index);
    mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_CITY_LIST);

    if (g_dcd_app_viewer.normal_entry)
    {
        g_dcd_app_viewer.normal_entry = MMI_FALSE;
    }
    g_dcd_app_viewer.normal_exit = MMI_FALSE;
    
    wgui_cat9003_op01_show(
        NULL,
        NULL,
        (UI_string_type) GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
#if defined(__MMI_TOUCH_SCREEN__)
        ui_dcd_pen_handler,
#else 
        NULL,
#endif 
        (void*)agent_handle, gui_buffer);

    SetRightSoftkeyFunction(mmi_dcd_channel_detail_rsk_handler, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_delete_city_query
 * DESCRIPTION
 *  mmi_dcd_entry_delete_city_query
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_delete_city_query()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    HDCD_Agent agent_handle = NULL;
    WCHAR     delete_city_title[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    S32        channel_index = 0;
    HDCD_Channel  channel_handle = NULL;
    S32           block_index = 0;
    HDCD_Block    block_handle = NULL;
    CHAR *        block_title = NULL;
    WCHAR *        delete_ask_str = NULL;
    S32           len = 0;
    S32           city_count = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((!g_dcd_app_cntx.block_id) || (strlen(g_dcd_app_cntx.block_id) == 0))
    {
        mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_NO_CITY_SELECTED), MMI_EVENT_FAILURE, NULL);
        return;
    }
    
    agent_handle = mmi_dcd_get_agent_handle();
    channel_index = emDCDAgent_GetChannelIndex(agent_handle, g_dcd_app_cntx.channel_id);
    channel_handle = emDCDAgent_GetChannelAt(agent_handle, channel_index);

    city_count = emDCDAgent_GetChannelBlockCount(channel_handle);

    if (city_count <= 1)
    {
        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DCD_LAST_CITY_CAN_NOT_BE_DELETED), MMI_EVENT_FAILURE, NULL);
        return;
    }
    else
    {    
        block_index = emDCDAgent_GetChannelBlockIndex(channel_handle, g_dcd_app_cntx.block_id);
        block_handle = emDCDAgent_GetChannelBlockAt(channel_handle, block_index);
        block_title = emDCDAgent_GetBlockTitle(block_handle);

        memset(delete_city_title, 0, (MMI_DCD_MAX_CTXT_ID_LEN + 1) * ENCODING_LENGTH);

        len = kal_wstrlen(get_string(STR_ID_DCD_DELETE_CITY_ASK));
        delete_ask_str = (WCHAR*)OslMalloc(len + (MMI_DCD_MAX_CTXT_ID_LEN + 1) * ENCODING_LENGTH + 2);
        memset(delete_ask_str, 0, len + (MMI_DCD_MAX_CTXT_ID_LEN + 1) * ENCODING_LENGTH + 2);
        
            mmi_chset_utf8_to_ucs2_string(
                (kal_uint8*)delete_city_title,
                (MMI_DCD_MAX_CTXT_ID_LEN + 1) * ENCODING_LENGTH,
                (kal_uint8*)block_title);

        kal_wsprintf(delete_ask_str, "%w%w%w", get_string(STR_ID_DCD_DELETE_CITY_ASK), delete_city_title, get_string(STR_ID_DCD_QUESTION_MARK));
        
        mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
        arg.callback = (mmi_proc_func)mmi_dcd_delete_city_confirm_callback;
        arg.user_tag = delete_ask_str;
        //mmi_confirm_display((WCHAR *)get_string(STR_ID_DCD_DELETE_CITY_ASK), MMI_EVENT_QUERY, &arg);
        mmi_confirm_display(delete_ask_str, MMI_EVENT_QUERY, &arg);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_switch_off_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_delete_city_confirm_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {        
        mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
        
        switch (alert->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_dcd_delete_city_done();
                if(alert->user_tag)
                {
                    OslMfree(alert->user_tag);
                    alert->user_tag = NULL; 
                }
                break;

            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                if(alert->user_tag)
                {
                    OslMfree(alert->user_tag);
                    alert->user_tag = NULL; 
                }
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_delete_city_done
 * DESCRIPTION
 *  mmi_dcd_delete_city_done
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_delete_city_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    MMI_BOOL is_syncing = MMI_FALSE;
    CHAR url[MMI_DCD_MAX_URL_LEN];
    CHAR * default_city_id = NULL;
    HDCD_Agent agent_handle = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(url, 0, sizeof(url));

    /*assume that the city block id is same to the city code*/
    sprintf(url, "citycode=%s", g_dcd_app_cntx.block_id);    

    result = mmi_dcd_user_to_sync(DCD_SYNC_REQ_TYPE_DELETEWEATHERCITY, url, &is_syncing);
    if (!result)
    {
        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
    }
    else if (is_syncing == MMI_TRUE)
    {
        mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_V30_BACKGROUND_SYNC_PROGRESS), MMI_EVENT_FAILURE, NULL);
    }
    else
    {
        agent_handle = mmi_dcd_get_agent_handle();
        default_city_id = emDCDAgent_GetConfigDefaultUserCity(agent_handle);
        if (!strcmp(default_city_id, g_dcd_app_cntx.block_id))
        {
            g_DefaultCityDeleted = MMI_TRUE;
        }
        mmi_dcd_entry_connect_sync();
        g_isSyncStopped = MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_set_default_city
 * DESCRIPTION
 *  mmi_dcd_set_default_city
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_set_default_city()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    CHAR *defalut_city_block_id = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((!g_dcd_app_cntx.block_id) || (strlen(g_dcd_app_cntx.block_id) == 0))
    {
        mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_NO_CITY_SELECTED), MMI_EVENT_FAILURE, NULL);
        return;
    }

    agent_handle = mmi_dcd_get_agent_handle();
    defalut_city_block_id = emDCDAgent_GetConfigDefaultUserCity(agent_handle);
    if (strcmp(defalut_city_block_id, g_dcd_app_cntx.block_id))
    {
        emDCDAgent_SetConfigDefaultUserCity(agent_handle,g_dcd_app_cntx.block_id);
        g_DefaultCityChanged = MMI_TRUE;
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
    }
    else
    {
        mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_THE_CITY_IS_DEFAULT_ALREADY), MMI_EVENT_FAILURE, NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_connect_sync
 * DESCRIPTION
 *  mmi_dcd_entry_connect_sync
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_connect_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* str_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ENTRY_CONNECT_SYNC);
    if (mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS, NULL, mmi_dcd_entry_connect_sync, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    mmi_frm_scrn_set_leave_proc(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS, mmi_dcd_content_sync_screen_leave_proc);

    if (g_GettingCityList)
    {
        str_ptr = (U8*)GetString(STR_ID_DCD_IN_GETTING_CITY_LIST);
    }
    else
    {
        str_ptr = (U8*)GetString(STR_ID_DCD_IN_GETTING_CONTENT);
    }
    ShowCategory66Screen(
        NULL,
        NULL,
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        str_ptr,
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    SetRightSoftkeyFunction(mmi_dcd_abort_content_sync, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_abort_content_sync
 * DESCRIPTION
 *  mmi_dcd_abort_content_sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_abort_content_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ABORT_CONTENT_SYNC, g_onlyPkgSync);
    if (g_item_move_req_data_ptr)
    {
        OslMfree(g_item_move_req_data_ptr);
        g_item_move_req_data_ptr = NULL;
    }
    mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_MANUAL_UPDATE_ROAMING_PROMPT);
    mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_MANUAL_UPDATE_PROMPT);
    mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_manual_update_screen_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_dcd_content_sync_screen_leave_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            break;
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
            break;
        case EVT_ID_SCRN_DEINIT:
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_CONTENT_SYNC_SCREEN_LEAVE, g_isSyncStopped, g_onlyPkgSync);          
            if ((g_isSyncStopped == MMI_FALSE) && (g_onlyPkgSync == MMI_FALSE))
            {
                mmi_dcd_stop_sync();
            }
            g_GettingCityList = MMI_FALSE;
            g_DefaultCityDeleted = MMI_FALSE;
            break;
        }

        default:
            return MMI_RET_ERR;
    }

    return MMI_RET_ALLOW_CLOSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_my_favorite_highlight_hdlr
 * DESCRIPTION
 *  story list highlight handler
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_my_favorite_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_saved_story_list_cntx.story_index = index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_exit_saved_story_list_screen
 * DESCRIPTION
 *  exit story list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_exit_saved_story_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_saved_story_list_cntx.title_list_pp != NULL)
    {
        for (index = 0; index < g_saved_story_list_cntx.story_number; index++)
        {
            if (g_saved_story_list_cntx.title_list_pp[index] != NULL)
                applib_mem_screen_free(g_saved_story_list_cntx.title_list_pp[index]);
        }
        applib_mem_screen_free(g_saved_story_list_cntx.title_list_pp);
        g_saved_story_list_cntx.title_list_pp = NULL;
    }
    
    if (g_saved_story_list_cntx.time_list_pp != NULL)
    {
        for (index = 0; index < g_saved_story_list_cntx.story_number; index++)
        {
            if (g_saved_story_list_cntx.time_list_pp[index] != NULL)
                applib_mem_screen_free(g_saved_story_list_cntx.time_list_pp[index]);
        }
        applib_mem_screen_free(g_saved_story_list_cntx.time_list_pp);
        g_saved_story_list_cntx.time_list_pp = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_pre_entry_my_favorite
 * DESCRIPTION
 *  mmi_dcd_pre_entry_my_favorite
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_pre_entry_my_favorite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    HDCD_Agent agent_handle = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    agent_handle = mmi_dcd_get_agent_handle();
    g_saved_story_list_cntx.story_number = emDCDAgent_GetPermanenceEntryCount(agent_handle);
    if (g_saved_story_list_cntx.story_number == 0)
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, NULL);
        return;
    }
    else if (g_saved_story_list_cntx.story_number > MMI_DCD_MAX_SAVED_STORY_COUNT)
    {
        g_saved_story_list_cntx.story_number = MMI_DCD_MAX_SAVED_STORY_COUNT;
    }       
    
    mmi_dcd_entry_my_favorite();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_my_favorite_title_and_time_list
 * DESCRIPTION
 *  get dcd channel title
 * PARAMETERS
 *  agent       [IN]        Dcd channel handle
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_get_my_favorite_title_and_time_list(HDCD_Agent agent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *title;
    HDCD_Entry hEntry;
    S32 char_num, index;
    MMI_BOOL is_truncated = MMI_FALSE;
    S32 buflen = 0;
    S8 *buf;
    char *issued_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_saved_story_list_cntx.title_list_pp = (S8 **)applib_mem_screen_alloc(sizeof(S8*) * g_saved_story_list_cntx.story_number);
    g_saved_story_list_cntx.time_list_pp = (S8 **)applib_mem_screen_alloc(sizeof(S8*) *g_saved_story_list_cntx.story_number);

    for (index = 0; index < g_saved_story_list_cntx.story_number; index++)
    {
        hEntry = emDCDAgent_GetPermanenceEntryAt(agent, index);
        title = emDCDAgent_GetEntryTitle(hEntry);
        buflen = MMI_DCD_MAX_STORY_TITLE_LEN;
        buf = g_saved_story_list_cntx.title_list_pp[index] = (S8*) applib_mem_screen_alloc(buflen);

        is_truncated = MMI_FALSE;
        if (title != NULL)
        {
            char_num = mmi_chset_utf8_strlen((kal_uint8*) title);
            if (char_num > buflen / 2)
            {
                is_truncated = MMI_TRUE;
                buflen -= 4;
            }

            mmi_chset_utf8_to_ucs2_string((kal_uint8*)buf, buflen, (kal_uint8*)title);
            if (is_truncated)
            {
                app_ucs2_strcat((kal_int8*) buf, (kal_int8*) L"..");
            }
        }
        else
        {
            buf[0] = 0;
            buf[1] = 0;
            app_ucs2_strcat((kal_int8*) buf, (kal_int8*) L" ");
        }

        /* get time, milliseconds string */
        issued_time = (char*)emDCDAgent_GetEntryIssuedTime(hEntry);
        buflen = (19 + 1) * ENCODING_LENGTH;
        buf = g_saved_story_list_cntx.time_list_pp[index] = (S8*)applib_mem_screen_alloc(buflen);
        mmi_dcd_time_string_fomat(issued_time, (char*)buf, (kal_int32)buflen);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_time_string_fomat
 * DESCRIPTION
 *  convert time string (milliseconds) to formated string, e.g. 2011/02/22 04:08 pm
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_dcd_time_string_fomat(char *issued_time, char *format_time, kal_int32 dest_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct mytime;
    char mytime_str[19 + 1], secs_str[10 + 1];
    U32 secs;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!format_time || dest_size <= 0)
    {
        return MMI_FALSE;
    }
    
    if (issued_time && strlen(issued_time) > 3)
    {
        /* remove milliseconds */
        strncpy(secs_str, issued_time, strlen(issued_time) - 3);
        secs = atoi(secs_str);
    }
    else
    {
        secs = 0;
    }
    
    /* add the time zone */
    secs += (U32)(GetTimeZone(PhnsetGetHomeCity()) * 3600);
    
    /* convert to datatime */
    applib_dt_utc_sec_2_mytime(secs, &mytime, KAL_FALSE);
    sprintf(
        mytime_str, 
        "%04d/%02d/%02d %02d:%02d %s", 
        mytime.nYear, 
        mytime.nMonth, 
        mytime.nDay, 
        (mytime.nHour > 12) ? (mytime.nHour - 12) : mytime.nHour, 
        mytime.nMin,
        (mytime.nHour >= 12) ? "pm" : "am");
    mmi_chset_utf8_to_ucs2_string((kal_uint8*)format_time, dest_size, (kal_uint8*)mytime_str);
    
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_my_favorite_get_icon
 * DESCRIPTION
 *  get dcd story icon
 * PARAMETERS
 *  item_index      [IN]        [in]    item index
 *  path            [?]         [?]         [out]   icon path
 * RETURNS
 *  TRUE/FALSE
 *****************************************************************************/
static MMI_BOOL mmi_dcd_my_favorite_get_icon(S32 item_index, S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    S32 buflen = SRV_FMGR_PATH_MAX_LEN;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_dcd_my_favorite_get_icon_path(item_index, path, buflen);
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_saved_story_get_icon_path
 * DESCRIPTION
 *  get dcd story icon
 * PARAMETERS
 *  agent       [IN]        Dcd agent handle
 *  index       [IN]        Channel index
 *  buf         [IN]        Channel title buffer
 *  buflen      [IN]        Buffer len
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dcd_my_favorite_get_icon_path(S32 index, S8 *buf, S32 buflen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    MMI_BOOL is_image_exist = MMI_FALSE;
    HDCD_Entry hEntry;
    S32 i, nContentCnt;
    HDCD_Content pContent;
    CHAR *content_type;
    S8 *path_buf = NULL;
    EDCD_AGENT_RESULT result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    agent_handle = mmi_dcd_get_agent_handle();
    hEntry = emDCDAgent_GetPermanenceEntryAt(agent_handle, index);
    nContentCnt = emDCDAgent_GetEntryContentCount(hEntry);
    path_buf = OslMalloc(SRV_FMGR_PATH_MAX_LEN + 1);
    memset(path_buf, 0, SRV_FMGR_PATH_MAX_LEN);
    
    for (i = 0; i < nContentCnt; i++)
    {
        pContent = emDCDAgent_GetEntryContentAt(hEntry, i);
        content_type = emDCDAgent_GetContentType(pContent);
        if (app_strnicmp((kal_char*)content_type, "image/", 6) == 0)
        {
            result = emDCDAgent_GetContentFullPath(pContent, path_buf, SRV_FMGR_PATH_MAX_LEN);
            if (result == eDCD_SUCCESS)
            {
                is_image_exist = MMI_TRUE;
                break; 
            }
        }
    }
    
    if (!is_image_exist)
    {
        memset(buf, 0, sizeof(buf));
    }

    mmi_chset_utf8_to_ucs2_string((kal_uint8 *)buf, buflen, (kal_uint8 *)path_buf);   

    if (path_buf)
    {
        OslMfree(path_buf);
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_my_favorite
 * DESCRIPTION
 *  mmi_dcd_entry_my_favorite
 * PARAMETERS
 *  agent       [IN]        Dcd agent handle
 *  index       [IN]        Channel index
 *  buf         [IN]        Channel title buffer
 *  buflen      [IN]        Buffer len
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_my_favorite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    HDCD_Agent agent_handle = NULL;
    U8  *gui_buffer = NULL; 
   	U16 pre_story_total;
    U8  read_state_list[MMI_DCD_MAX_SAVED_STORY_COUNT] = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ENTRY_MY_FAVORITE);
    
    agent_handle = mmi_dcd_get_agent_handle();
    pre_story_total =  g_saved_story_list_cntx.story_number;
    g_saved_story_list_cntx.story_number = emDCDAgent_GetPermanenceEntryCount(agent_handle); 
    
    if (g_saved_story_list_cntx.story_number == 0)
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, NULL);
        return;
    }
    else if (g_saved_story_list_cntx.story_number > MMI_DCD_MAX_SAVED_STORY_COUNT)
    {
        g_saved_story_list_cntx.story_number = MMI_DCD_MAX_SAVED_STORY_COUNT;
    }

    if (mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_MY_FAVORITE, mmi_dcd_exit_saved_story_list_screen, mmi_dcd_entry_my_favorite, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    if ((g_saved_story_list_cntx.story_number < pre_story_total) && (gui_buffer != NULL))
    {
		gui_buffer = NULL;
    }

    RegisterHighlightHandler(mmi_dcd_my_favorite_highlight_hdlr);
    mmi_dcd_get_my_favorite_title_and_time_list(agent_handle);    

    wgui_cat9005_op01_show(
        (UI_string_type)GetString(STR_ID_DCD_FAVORITE_TITLE),
        NULL,
        (UI_string_type)GetString(STR_GLOBAL_OPTIONS),
        (PU8)GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type)GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        g_saved_story_list_cntx.story_number,
        (U8 **) g_saved_story_list_cntx.title_list_pp,
        (U8 **) g_saved_story_list_cntx.time_list_pp,
        mmi_dcd_my_favorite_get_icon,
        read_state_list,
        0,
        gui_buffer,
        MMI_TRUE);

    wgui_register_tap_callback(mmi_dcd_pre_entry_saved_story_viewer);
    
    SetLeftSoftkeyFunction(mmi_dcd_entry_my_favorite_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_viewer_save_to_my_favorite
 * DESCRIPTION
 *  mmi_dcd_viewer_save_to_my_favorite
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_viewer_save_to_my_favorite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_dcd_save_to_my_favorite_confirm_callback;
    mmi_confirm_display((WCHAR *)GetString(STR_GLOBAL_SAVE_ASK), MMI_EVENT_QUERY, &arg);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_save_story_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_save_to_my_favorite_confirm_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {        
        mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
        
        switch (alert->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_dcd_my_favorite_save_done();
                break;

            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_story_save_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_my_favorite_save_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT result;
    HDCD_Agent agent_handle = NULL;
    HDCD_Entry entry_handle = NULL;
    EDCD_AGENT_RESULT check_result  = eDCD_ERR_UNKNOWN;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    agent_handle = mmi_dcd_get_agent_handle();
    entry_handle = mmi_dcd_get_current_entry(agent_handle);
    
    check_result = emDCDAgent_IsValidHandle(entry_handle);
    if (eDCD_SUCCESS != check_result)
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE, NULL);
        return;
    }
    
    result = emDCDAgent_SavePermanenceEntry(agent_handle, entry_handle);
    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_INFO, "[DCD][APP] save favorite result is %d", result);
    switch (result)
    {
        case eDCD_SUCCESS:
            mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, NULL); 
            break;

        case eDCD_ERR_MAX_PERMANENT_ENTRY_REACHED:
            mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_MEMORY_FULL), MMI_EVENT_FAILURE, NULL);
            break;

        case eDCD_ERR_WRITE_FILE:
        case eDCD_ERR_STORAGE_FULL:
            mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_QUOTA_EXCEEDED), MMI_EVENT_FAILURE, NULL);
            break;

        case eDCD_ERR_PERM_ENTRY_DUPLICATION:
            mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_FILE_ALREADY_EXISTS), MMI_EVENT_FAILURE, NULL);
            break;

        case eDCD_FAIL:
            mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_FAILED_TO_SAVE), MMI_EVENT_FAILURE, NULL);     
            break;
            
        default:
            break;
    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_my_favorite_delete_confirm
 * DESCRIPTION
 *  pop up delete story confirm window
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_my_favorite_delete_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do {
    mmi_confirm_property_struct arg;
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_dcd_my_favorite_delete_confirm_callback;
    mmi_confirm_display((WCHAR *)get_string(STR_ID_DCD_DELETE_NEWS_ENTRY_ASK), MMI_EVENT_QUERY, &arg);
    } while(0);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_my_favorite_delete_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_my_favorite_delete_confirm_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {        
        mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
        
        switch (alert->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_dcd_my_favorite_delete_done();
                break;

            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_my_favorite_delete_done
 * DESCRIPTION
 *  delete current saved story
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_my_favorite_delete_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Entry entry_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    agent_handle = mmi_dcd_get_agent_handle();
    entry_handle = emDCDAgent_GetPermanenceEntryAt(agent_handle, g_saved_story_list_cntx.story_index);
    emDCDAgent_DeletePermanenceEntry(agent_handle, entry_handle);

    do {
	mmi_popup_property_struct arg;
	mmi_popup_property_init(&arg);
	arg.callback = mmi_alert_normal_exit_helper;
	arg.user_tag = (void *)(mmi_dcd_my_favorite_delete_callback);
	mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS, &arg);
	} while(0);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_my_favorite_delete_callback
 * DESCRIPTION
 *  delete saved story popup callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_my_favorite_delete_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 total = 0;
    HDCD_Agent agent_handle = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    agent_handle = mmi_dcd_get_agent_handle();
    total = emDCDAgent_GetPermanenceEntryCount(agent_handle);
    if (total == 0)
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, NULL);
        mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_MY_FAVORITE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_my_favorite_option
 * DESCRIPTION
 *  entry story list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_my_favorite_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid = GRP_ID_INVALID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_gid = cui_menu_create(
                            GRP_ID_DCD,
                            CUI_MENU_SRC_TYPE_RESOURCE,
                            CUI_MENU_TYPE_FROM_RESOURCE,
                            MENU_ID_DCD_MY_FAVORITE_OPTION,
                            MMI_TRUE,
                            NULL);

    if (menu_gid != GRP_ID_INVALID)
    {
        cui_menu_run(menu_gid);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_setting_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     select_index = 0;
    mmi_dcd_setting_struct* dcd_setting_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_group_create(
	    GRP_ID_DCD,
		GRP_ID_DCD_SYSTEM_SETTING,
		mmi_dcd_entry_setting_screen_inline_cui_proc,
		NULL);
	mmi_frm_group_enter(GRP_ID_DCD_SYSTEM_SETTING, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
	setting_inline_id  = cui_inline_create(GRP_ID_DCD_SYSTEM_SETTING, &dcd_settings_initial_data);
    dcd_setting_p = mmi_dcd_get_setting_data();
    
	if (setting_inline_id != GRP_ID_INVALID)
	{
        if (dcd_setting_p->dcd_conn_mode >= DCD_CONN_MODE_ALL)
	    {
            select_index = 0;
	    }
	    else 
	    {
		    select_index = dcd_setting_p->dcd_conn_mode;
	    }
        cui_inline_set_value(setting_inline_id, DCD_SETTING_CONNECTION_MODE, (void*)select_index);
        
        if (dcd_setting_p->dcd_scroll_speed >= DCD_SCROLL_SPEED_TOTAL)
	    {
            select_index = 0;
	    }
	    else 
	    {
		    select_index = dcd_setting_p->dcd_scroll_speed;
	    }
        cui_inline_set_value(setting_inline_id, DCD_SETTING_SCROLL_SPEED, (void*)select_index);


        if (dcd_setting_p->dcd_update_mode >= DCD_UPDATE_MODE_ALL)
        {
            select_index = 0;
	    }
	    else 
	    {
		    select_index = dcd_setting_p->dcd_update_mode;
        }
        cui_inline_set_value(setting_inline_id, DCD_SETTING_UPDATE_MODE, (void*)select_index);

        if (g_city_block_count > 0)
        {
            cui_inline_set_item_select(
                setting_inline_id,
                DCD_SETTING_DEFAULT_CITY,
                g_city_block_count,
                (PU8*)city_name_p,
                g_default_city_index);
        }
	    cui_inline_run(setting_inline_id);
	}
	else
	{
		mmi_frm_group_close(GRP_ID_DCD_SYSTEM_SETTING);
	}

}

void mmi_dcd_setting_inline_set_city_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Block city_block_handle = NULL;
    U8         channel_count = 0;
    U8    channel_index = 0;
    HDCD_Channel channel_handle = NULL;
    EDCD_CHANNEL_TYPE channel_type = eDCD_CHANNEL_NONE;
    S8 * city_title = NULL;
    CHAR *      city_block_id = NULL;
    U8 city_block_count = 0;
    U8 city_block_index = 0;
    CHAR city_code_p[MMI_DCD_MAX_CITY_COUNT][MMI_DCD_MAX_CTXT_ID_LEN + 1];
    CHAR *default_city_code = NULL;
    U8 default_city_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    agent_handle = mmi_dcd_get_agent_handle();
    channel_count = emDCDAgent_GetChannelCount(agent_handle);
    for (channel_index = 0; channel_index < channel_count; channel_index++)
    {
        channel_handle = emDCDAgent_GetChannelAt(agent_handle, channel_index);
        channel_type = emDCDAgent_GetChannelType(channel_handle);
        if (eDCD_CHANNEL_WEATHER == channel_type)
        {
            city_block_count = emDCDAgent_GetChannelBlockCount(channel_handle);
            break;
        }
    }
    memset(city_code_p, 0, sizeof(city_code_p));
    for (city_block_index = 0; city_block_index < city_block_count; city_block_index++)
    {
        city_block_handle = emDCDAgent_GetChannelBlockAt(channel_handle, city_block_index);

        city_block_id = emDCDAgent_GetCityListBlockID(city_block_handle);
        city_title = emDCDAgent_GetBlockTitle(city_block_handle);
        city_name_p[city_block_index] = (S8*)applib_mem_screen_alloc((MMI_DCD_MAX_CTXT_ID_LEN + 1) * ENCODING_LENGTH);
        memset(city_name_p[city_block_index], 0, (MMI_DCD_MAX_CTXT_ID_LEN + 1) * ENCODING_LENGTH);
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*)city_name_p[city_block_index],
            (MMI_DCD_MAX_CTXT_ID_LEN + 1) * ENCODING_LENGTH,
            (kal_uint8*)city_title);

        strcpy(city_code_p[city_block_index], city_block_id);
    }
    default_city_code = emDCDAgent_GetConfigDefaultUserCity(agent_handle);
    for (default_city_index = 0; default_city_index < city_block_count; default_city_index++)
    {
        if (!strcmp(city_code_p[default_city_index], default_city_code))
        {
            break;
        }
    }
    g_default_city_index = default_city_index;
    g_city_block_count = city_block_count;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_setting_screen_inline_cui_proc
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_dcd_entry_setting_screen_inline_cui_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_event;
    menu_event = (cui_menu_event_struct*)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        break;
        
        
     case EVT_ID_CUI_MENU_LIST_ENTRY:  
        break;
        
    case EVT_ID_CUI_MENU_LIST_EXIT:
        break;
        
    case EVT_ID_CUI_MENU_ITEM_HILITE:
        break;
        
    case EVT_ID_CUI_MENU_ITEM_SELECT:
        switch (menu_event->highlighted_menu_id)
        {
            case MENU_ID_DCD_RESTORE_FACTORY_SETTING:
                mmi_dcd_settings_reset_confirm();
                break;
            case MENU_ID_DCD_SAVE_SETTING:
            {
                S32 select_index;
                mmi_dcd_setting_struct* dcd_setting_p = NULL;
                dcd_setting_p = mmi_dcd_get_setting_data();
                cui_menu_close(menu_event->sender_id);
                cui_inline_get_value(menu_event->sender_id, DCD_SETTING_CONNECTION_MODE, &select_index);
                dcd_setting_p->dcd_conn_mode = (U8)select_index;

                mmi_dcd_setting_save();
                cui_inline_close(menu_event->sender_id);
                break;
            }                   
                
            default:
                break;
        }
        break;
    case EVT_ID_CUI_MENU_ITEM_TAP:
    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:      
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_event->sender_id);
        }
        break; 

    case EVT_ID_CUI_INLINE_SUBMIT:
        {
            S32 select_index;
            mmi_dcd_setting_struct* dcd_setting_p = NULL;
            cui_event_inline_submit_struct * inline_submit_p = (cui_event_inline_submit_struct *)evt;
            dcd_setting_p = mmi_dcd_get_setting_data();
            cui_inline_get_value(inline_submit_p->sender_id, DCD_SETTING_CONNECTION_MODE, &select_index);
            dcd_setting_p->dcd_conn_mode = (U8)select_index;

            mmi_dcd_setting_save();

            cui_inline_close(inline_submit_p->sender_id);
        }    
        break;

    case EVT_ID_CUI_INLINE_NOTIFY:
        break;
    
    case EVT_ID_CUI_INLINE_SET_KEY:
    {
        cui_event_inline_set_key_struct *inline_evt = NULL;
        inline_evt = (cui_event_inline_set_key_struct *)evt;
        cui_inline_set_softkey_text(inline_evt->sender_id, inline_evt->item_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_dcd_entry_setting_option, KEY_EVENT_UP);
        break;
    }

    case EVT_ID_CUI_INLINE_ABORT:
    {
        cui_event_inline_abort_struct *inline_evt;
        S8 index = 0;
        inline_evt = (cui_event_inline_abort_struct *)evt;

        for(index = 0; index < MMI_DCD_MAX_CITY_COUNT; index++)
        {
            if (city_name_p[index])
            {
                applib_mem_screen_free(city_name_p[index]);
                city_name_p[index] = NULL; 
            }
            else
            {
                break;
            }
        }
        cui_inline_close(inline_evt->sender_id);
        break;
    }

    case EVT_ID_CUI_INLINE_MAIN_SCREEN_INACTIVE:
    {
        S8 index = 0;
        for(index = 0; index < MMI_DCD_MAX_CITY_COUNT; index++)
        {
            if (city_name_p[index])
            {
                applib_mem_screen_free(city_name_p[index]);
                city_name_p[index] = NULL; 
            }
            else
            {
                break;
            }
        }
        break;
    }

    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
    {
        if (!city_name_p[0])
        {
            mmi_dcd_setting_inline_set_city_list();
        }
        break;
    }
           
    case EVT_ID_CUI_INLINE_GROUP_DEINIT:
        break; 
        
    default:
        break;
    }
	
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_setting_option_proc
 * DESCRIPTION
 *  mmi_dcd_setting_option_proc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_setting_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_event;
    menu_event = (cui_menu_event_struct*)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch (menu_event->highlighted_menu_id)
            {
                case MENU_ID_DCD_RESTORE_FACTORY_SETTING:
                    mmi_dcd_settings_reset_confirm();
                    break;
                    
                case MENU_ID_DCD_SAVE_SETTING:
                {
                    S32 select_index;
                    mmi_dcd_setting_struct* dcd_setting_p = NULL;
                    dcd_setting_p = mmi_dcd_get_setting_data();

                    /* connect mode */
                    cui_inline_get_value(setting_inline_id, DCD_SETTING_CONNECTION_MODE, &select_index);
                    dcd_setting_p->dcd_conn_mode = (U8)select_index;

                    /* scroll speed */
                    cui_inline_get_value(setting_inline_id, DCD_SETTING_SCROLL_SPEED, &select_index);
                    dcd_setting_p->dcd_scroll_speed = (U8)select_index;

                    /* update mode */
                    cui_inline_get_value(setting_inline_id, DCD_SETTING_UPDATE_MODE, &select_index);
                    dcd_setting_p->dcd_update_mode = (U8)select_index;

                    /* default city */
                    cui_inline_get_value(setting_inline_id, DCD_SETTING_DEFAULT_CITY, &select_index);
                    g_default_city_index = (U8)select_index;
                    
                    mmi_dcd_setting_save();
                    mmi_frm_group_close(GRP_ID_DCD_SYSTEM_SETTING);
                    break;
                }
                    
                default:
                    break;
            }
            break;
            
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_event->sender_id);
            break;
            
        default:
            break;
    }

    return MMI_RET_OK; 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_settings_save
 * DESCRIPTION
 *  Function to Fill valuses in inine edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_setting_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL success;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	success = mmi_dcd_save_setting_data();
    mmi_dcd_setting_save_done(success);
    if (success)
    {
    	mmi_dcd_set_update_mode();
    	mmi_dcd_setting_set_default_city();
        mmi_dcd_conn_to_sync();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_settings_save_done
 * DESCRIPTION
 *  Function to Fill valuses in inine edit screen
 * PARAMETERS
 *  success     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_setting_save_done(MMI_BOOL success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ( success )
    {
        string = (UI_string_type)GetString(STR_GLOBAL_DONE);
        mmi_popup_display((WCHAR*)string, MMI_EVENT_SUCCESS, NULL);
    }
    else 
    {
        string = (UI_string_type)GetString(STR_GLOBAL_ERROR);
        mmi_popup_display((WCHAR*)string, MMI_EVENT_FAILURE, NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_scroll_speed_ext
 * DESCRIPTION
 *  mmi_dcd_get_scroll_speed_ext
 * PARAMETERS
 *  success     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
dcd_idle_scroll_speed_enum mmi_dcd_get_scroll_speed_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dcd_setting_struct* dcd_setting_p = NULL;
    dcd_idle_scroll_speed_enum speed = DCD_IDLE_SCROLL_MEDIUM_SPEED;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dcd_setting_p = mmi_dcd_get_setting_data();
	switch (dcd_setting_p->dcd_scroll_speed)
	{
	    case DCD_SCROLL_SPEED_FAST:
		    speed = DCD_IDLE_SCROLL_FAST_SPEED;
		    break;
		
	    case DCD_SCROLL_SPEED_MEDIUM:
		    speed = DCD_IDLE_SCROLL_MEDIUM_SPEED;
		    break;

	    case DCD_SCROLL_SPEED_SLOW:
		    speed = DCD_IDLE_SCROLL_SLOW_SPEED;
		    break;

	    default:
		    speed = DCD_IDLE_SCROLL_MEDIUM_SPEED;
		    break;
	}
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_SPEED_IS_SET, speed);
    return speed;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_channel_list_select_item
 * DESCRIPTION
 *  mmi_dcd_channel_list_select_item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_channel_list_select_item(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    S32 channel_cnt = 0;
    MMI_BOOL   only_preset = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    agent_handle = mmi_dcd_get_agent_handle();
    channel_cnt = emDCDAgent_GetChannelCount(agent_handle);
    if (channel_cnt <= 0)
    {
        channel_cnt = emDCDAgent_GetPreChannelCount(agent_handle);
        only_preset = MMI_TRUE;
    }
    
    if (index < channel_cnt)
    {
        mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_CHANNEL_DETAIL);
        if (only_preset)
        {
            mmi_dcd_pre_entry_preset_channel_detail();
        }
        else
        {
            mmi_dcd_pre_entry_channel_detail();
        }
    }
    else
    {
        mmi_dcd_pre_entry_my_favorite();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_setting_set_default_city
 * DESCRIPTION
 *  set default city to DCD engine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dcd_setting_set_default_city(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Channel channel_handle = NULL;
    EDCD_CHANNEL_TYPE channel_type = eDCD_CHANNEL_NONE;
    HDCD_Block block_handle = NULL;
    S32 channel_count, channel_index, block_count;
    CHAR *city_code = NULL;
    CHAR * pre_default_city = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if there is no city, should not save to engine */
    if (g_city_block_count > 0)
    {
        agent_handle = mmi_dcd_get_agent_handle();
        channel_count = emDCDAgent_GetChannelCount(agent_handle);
        for (channel_index = 0; channel_index < channel_count; channel_index++)
        {
            channel_handle = emDCDAgent_GetChannelAt(agent_handle, channel_index);
            channel_type = emDCDAgent_GetChannelType(channel_handle);
            if (channel_type == eDCD_CHANNEL_WEATHER)
            {
                block_count = emDCDAgent_GetChannelBlockCount(channel_handle);
                if (g_default_city_index < block_count)
                {
                    block_handle = emDCDAgent_GetChannelBlockAt(channel_handle, g_default_city_index);
                    city_code = emDCDAgent_GetBlockID(block_handle);
                    if (city_code)
                    {
                        pre_default_city = emDCDAgent_GetConfigDefaultUserCity(agent_handle);
                        if (strcmp(pre_default_city, city_code))
                        {
                            g_DefaultCityChanged = MMI_TRUE;
                        }
                        emDCDAgent_SetConfigDefaultUserCity(agent_handle, city_code);
                    }
                    else
                    {
                        return MMI_FALSE;
                    }
                }
                break;
            }
        }  
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_pre_entry_channel_detail
 * DESCRIPTION
 *  mmi_dcd_pre_entry_channel_detail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_pre_entry_channel_detail()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    CHAR a_szChannelID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    CHAR a_szBlockID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    CHAR a_szEntryID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    BRINT  a_nPageOrder = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_PRE_ENTRY_CHANNEL_DETAIL);
    
    agent_handle = mmi_dcd_get_agent_handle();

    g_dcd_app_viewer.normal_entry = MMI_TRUE;
    g_dcd_app_viewer.normal_exit = MMI_FALSE;
    g_CityCntChanged = MMI_FALSE;
    g_DefaultCityChanged = MMI_FALSE;
    g_DefaultCityDeleted = MMI_FALSE;
    memset(g_dcd_app_cntx.block_id, 0, sizeof(g_dcd_app_cntx.block_id));
    memset(g_dcd_app_cntx.entry_id, 0, sizeof(g_dcd_app_cntx.entry_id));
    
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_VIEW_MODE, g_dcd_app_cntx.view_mode);
    
    if (g_dcd_app_cntx.view_mode == eDCD_VIEW_CHANNEL_DETAIL)
    {
        memset(a_szChannelID, 0, sizeof(a_szChannelID));
        memset(a_szBlockID, 0, sizeof(a_szBlockID));
        memset(a_szEntryID, 0, sizeof(a_szEntryID));

        emDCDAgent_GetStoryViewerID(agent_handle, a_szChannelID, a_szBlockID, a_szEntryID, &a_nPageOrder);
        strcpy(g_dcd_app_cntx.channel_id, a_szChannelID);
        //strcpy(g_dcd_app_cntx.block_id, a_szBlockID);
        //strcpy(g_dcd_app_cntx.entry_id, a_szEntryID);

        g_dcd_app_cntx.channel_handle = emDCDAgent_GetChannelAt(agent_handle, g_dcd_app_cntx.channel_index);
        strcpy(g_dcd_app_cntx.channel_id, emDCDAgent_GetChannelID(g_dcd_app_cntx.channel_handle));
        mmi_dcd_show_end(agent_handle);
        emDCDAgent_SetStoryViewerID(agent_handle, g_dcd_app_cntx.channel_id, NULL, NULL, 0);
        mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_CHANNEL_DETAIL);
        mmi_dcd_show_start(agent_handle, eERM_RETURN_FROM_NORMAL, NULL);
    }
    else
    {
        g_dcd_app_cntx.channel_handle = emDCDAgent_GetChannelHandle(agent_handle, g_dcd_app_cntx.channel_id);

        if (g_dcd_app_cntx.channel_handle == NULL)
        {
            mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, NULL);
            return;
        }
        g_isEntryFromIdle = MMI_FALSE;
        mmi_dcd_entry_channel_detail();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_channel_detail
 * DESCRIPTION
 *  mmi_dcd_entry_channel_detail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_channel_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    U8 *gui_buffer;
    S32 channel_index = -1;
    HDCD_Channel channel_handle = NULL;
    EDCD_CHANNEL_TYPE channel_type = eDCD_CHANNEL_NONE;
    EDCD_AGENT_RESULT check_result  = eDCD_ERR_UNKNOWN;
    EDCD_VIEW_MODE  pre_view_mode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ENTRY_CHANNEL_DETAIL);

    if (mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_CHANNEL_DETAIL, mmi_dcd_exit_channel_detail, mmi_dcd_entry_channel_detail, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
    {
        return;
    }
    
    agent_handle = mmi_dcd_get_agent_handle();

    pre_view_mode = g_dcd_app_cntx.view_mode;
    
    g_dcd_app_cntx.view_mode = eDCD_VIEW_CHANNEL_DETAIL;

    channel_index = emDCDAgent_GetChannelIndex(agent_handle, g_dcd_app_cntx.channel_id);
    channel_handle = emDCDAgent_GetChannelAt(agent_handle, channel_index);
    check_result = emDCDAgent_IsValidHandle(channel_handle);

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    
    if ((g_dcd_app_viewer.normal_entry) || (g_CityCntChanged) || (g_DefaultCityChanged))
    {
        mmi_dcd_show_end(agent_handle);

        if (eDCD_SUCCESS != check_result)
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
            mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DCD_CONTENT_DELETED), MMI_EVENT_FAILURE, NULL);
            g_dcd_app_viewer.normal_exit = MMI_TRUE;
            mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_CHANNEL_DETAIL);
            return;
        }
        
        channel_type = emDCDAgent_GetChannelType(channel_handle);
        if (channel_type == eDCD_CHANNEL_WEATHER)
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_CLEAR_CITY_BLOCK);
            memset(g_dcd_app_cntx.block_id, 0, sizeof(g_dcd_app_cntx.block_id));
            memset(g_dcd_app_cntx.entry_id, 0, sizeof(g_dcd_app_cntx.entry_id));
        }
        g_CityCntChanged = MMI_FALSE;
        g_DefaultCityChanged = MMI_FALSE;
        g_DefaultCityDeleted = MMI_FALSE;
    }
    else
    {
        mmi_dcd_show_pause(agent_handle);
        if ((eDCD_SUCCESS != check_result) && (pre_view_mode != g_dcd_app_cntx.view_mode))
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
            mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DCD_CONTENT_DELETED), MMI_EVENT_FAILURE, NULL);
            g_dcd_app_viewer.normal_exit = MMI_TRUE;
            mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_CHANNEL_DETAIL);
            return;
        }
    }

    emDCDAgent_SetStoryViewerID(agent_handle, g_dcd_app_cntx.channel_id, NULL, NULL, 0);
    mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_CHANNEL_DETAIL);

    if (g_dcd_app_viewer.normal_entry)
    {
        g_dcd_app_viewer.normal_entry = MMI_FALSE;
    }
    g_dcd_app_viewer.normal_exit = MMI_FALSE;
    
    wgui_cat9003_op01_show(
        (UI_string_type) GetString(STR_GLOBAL_OPTIONS),
        (PU8) GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type) GetString(STR_GLOBAL_BACK), (PU8) GetImage(IMG_GLOBAL_BACK),
#if defined(__MMI_TOUCH_SCREEN__)
        ui_dcd_pen_handler,
#else 
        NULL,
#endif 
        (void*)agent_handle, gui_buffer);

    SetLeftSoftkeyFunction(mmi_dcd_entry_channel_detail_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dcd_channel_detail_rsk_handler, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_pre_entry_preset_channel_detail
 * DESCRIPTION
 *  mmi_dcd_pre_entry_preset_channel_detail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_pre_entry_preset_channel_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_app_viewer.normal_entry = MMI_TRUE;
    g_dcd_app_viewer.normal_exit = MMI_FALSE;
    g_CityCntChanged = MMI_FALSE;
    g_DefaultCityChanged = MMI_FALSE;
    g_isEntryFromIdle = MMI_FALSE;
    mmi_dcd_entry_preset_channel_detail();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_preset_channel_detail
 * DESCRIPTION
 *  mmi_dcd_entry_preset_channel_detail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_preset_channel_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    U8 *gui_buffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ENTRY_PRESET_CHANNEL_DETAIL);

    if (mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_CHANNEL_DETAIL, mmi_dcd_exit_channel_detail, mmi_dcd_entry_preset_channel_detail, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
    {
        return;
    }
    
    agent_handle = mmi_dcd_get_agent_handle();
    g_dcd_app_cntx.view_mode = eDCD_VIEW_DEFAULT_STORY;

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    
    if ((g_dcd_app_viewer.normal_entry))
    {
        mmi_dcd_show_end(agent_handle);
    }
    else
    {
        mmi_dcd_show_pause(agent_handle);
    }

    emDCDAgent_SetStoryViewerID(agent_handle, g_dcd_app_cntx.channel_id, NULL, NULL, 0);
    mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_DEFAULT_STORY);

    if (g_dcd_app_viewer.normal_entry)
    {
        g_dcd_app_viewer.normal_entry = MMI_FALSE;
    }
    g_dcd_app_viewer.normal_exit = MMI_FALSE;
    
    wgui_cat9003_op01_show(
        (UI_string_type) GetString(STR_GLOBAL_OPTIONS),
        (PU8) GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type) GetString(STR_GLOBAL_BACK), (PU8) GetImage(IMG_GLOBAL_BACK),
#if defined(__MMI_TOUCH_SCREEN__)
        ui_dcd_pen_handler,
#else 
        NULL,
#endif 
        (void*)agent_handle, gui_buffer);

    SetLeftSoftkeyFunction(mmi_dcd_entry_channel_detail_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dcd_channel_detail_rsk_handler, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_channel_detail_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_channel_detail_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_app_viewer.normal_exit = MMI_TRUE;

    if (g_dcd_app_cntx.view_mode == eDCD_VIEW_CHANNEL_DETAIL)
    {
        g_dcd_app_cntx.view_mode = eDCD_VIEW_IDLE;
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        mmi_frm_scrn_close_active_id();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_pre_entry_channel_list_from_channel_detail
 * DESCRIPTION
 *  entry channel list screen from channel detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_pre_entry_channel_list_from_channel_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_PRE_ENTRY_CHANNEL_LIST_FROM_DETAIL, g_isEntryFromIdle);
    if (!g_isEntryFromIdle)
    {
        if ((g_dcd_app_cntx.view_mode == eDCD_VIEW_CHANNEL_DETAIL) || (g_dcd_app_cntx.view_mode == eDCD_VIEW_DEFAULT_STORY))
        {
            mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_CHANNEL_DETAIL);
            mmi_frm_scrn_close_active_id();
            g_dcd_app_cntx.view_mode = eDCD_VIEW_IDLE;
            return;
        }
    }
    if (!g_pre_channel_id)
    {
        g_pre_channel_id = (CHAR*)OslMalloc(MMI_DCD_MAX_CTXT_ID_LEN + 1);
    }
    strcpy(g_pre_channel_id, g_dcd_app_cntx.channel_id);
    mmi_dcd_entry_channel_list_from_channel_detail();
}

static mmi_ret mmi_dcd_channel_list_from_channel_detail_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            break;
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
            break;
        case EVT_ID_SCRN_DEINIT:
        {
            if (g_pre_channel_id)
            {
                OslMfree(g_pre_channel_id);
                g_pre_channel_id = NULL;

            }
            break;
        }

        default:
            return MMI_RET_ERR;
    }

    return MMI_RET_ALLOW_CLOSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_channel_list_from_channel_detail
 * DESCRIPTION
 *  entry channel list screen from channel detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_channel_list_from_channel_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* gui_buffer = NULL;
    S32 channel_cnt, highlighted_item = 0;
    U8  read_state_list[MMI_DCD_MAX_CHANNEL_COUNT] = {0};
    HDCD_Agent agent_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ENTRY_CHANNEL_LIST_FROM_DETAIL);
    
	if (mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_CHANNEL_LIST, mmi_dcd_exit_channel_list_screen, mmi_dcd_entry_channel_list_from_channel_detail, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

    mmi_frm_scrn_set_leave_proc(GRP_ID_DCD, SCR_ID_DCD_CHANNEL_LIST, mmi_dcd_channel_list_from_channel_detail_leave_proc);
    agent_handle = mmi_dcd_get_agent_handle();

    if (agent_handle == NULL)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    
    g_dcd_app_cntx.view_mode = eDCD_VIEW_IDLE;
    
    if (gui_buffer == NULL)
    {
        if (g_dcd_app_cntx.update_flag & MMI_DCD_CHANNEL_LIST_UPDATE_MASK)
        {
            highlighted_item = 0;
        }
        else
        {
            highlighted_item = emDCDAgent_GetChannelIndex(agent_handle, g_dcd_app_cntx.channel_id);
        }
        g_dcd_app_cntx.update_flag = g_dcd_app_cntx.update_flag & (~MMI_DCD_CHANNEL_LIST_UPDATE_MASK);
    }
    else
    {
        if (g_dcd_app_cntx.update_flag & MMI_DCD_CHANNEL_LIST_UPDATE_MASK)
        {
            gui_buffer = NULL;
            g_dcd_app_cntx.update_flag = g_dcd_app_cntx.update_flag & (~MMI_DCD_CHANNEL_LIST_UPDATE_MASK);
            highlighted_item = 0;
        }
    }

    mmi_dcd_set_manual_updte_scr_id(SCR_ID_DCD_CHANNEL_LIST);
    channel_cnt = mmi_dcd_get_channel_title_and_time_list(agent_handle);

    RegisterHighlightHandler(mmi_dcd_channel_item_highlight_hdlr);
    
	wgui_cat9005_op01_show(
        (UI_string_type)GetString(STR_ID_DCD),
        NULL,
        (UI_string_type)GetString(STR_GLOBAL_OPTIONS),
        (PU8)GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type)GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        channel_cnt + 1,
        (U8**)g_dcd_title_list_pp,
        (U8**)g_dcd_time_list_pp,
        mmi_dcd_channel_list_get_icon,
        read_state_list,
        highlighted_item,
        gui_buffer,
        MMI_FALSE);

    wgui_register_tap_callback(mmi_dcd_channel_list_select_item);
    
    SetLeftSoftkeyFunction(mmi_dcd_entry_channel_list_option, KEY_EVENT_UP);    
    SetRightSoftkeyFunction(mmi_dcd_channel_list_from_channel_detail_rsk_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_channel_list_from_channel_detail
 * DESCRIPTION
 *  entry channel list screen from channel detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_channel_list_from_channel_detail_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(GRP_ID_DCD, SCR_ID_DCD_CHANNEL_DETAIL, MMI_FRM_NODE_ALL_FLAG))
    {
        if (g_pre_channel_id)
        {
            strcpy(g_dcd_app_cntx.channel_id, g_pre_channel_id);
        }
    }
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_set_manual_updte_scr_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_set_manual_updte_scr_id(U16 update_scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_manual_update_p->scr_id = update_scr_id;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_channel_detail_option
 * DESCRIPTION
 *  entry story list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_channel_detail_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Channel channel_handle = NULL;
    EDCD_CHANNEL_TYPE channel_type = eDCD_CHANNEL_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ID menu_gid = cui_menu_create(
                        GRP_ID_DCD,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_FROM_RESOURCE,
                        MENU_ID_DCD_CHANNEL_DETAIL_OPTION,
                        MMI_TRUE,
                        NULL);

    agent_handle = mmi_dcd_get_agent_handle();
    channel_handle = emDCDAgent_GetChannelHandle(agent_handle,g_dcd_app_cntx.channel_id);

    channel_type = emDCDAgent_GetChannelType(channel_handle);

    if (eDCD_CHANNEL_WEATHER != channel_type)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_ADD_CITY, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_DELETE_CITY, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_SET_AS_DEFAULT_CITY, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_ADD_CITY, MMI_FALSE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_DELETE_CITY, MMI_FALSE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_SET_AS_DEFAULT_CITY, MMI_FALSE);
    }

    if (menu_gid != GRP_ID_INVALID)
    {
        cui_menu_run(menu_gid);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_story_viewer_option
 * DESCRIPTION
 *  mmi_dcd_entry_story_viewer_option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_story_viewer_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid = cui_menu_create(
                        GRP_ID_DCD,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_FROM_RESOURCE,
                        MENU_ID_DCD_STORY_VIEWER_OPTION,
                        MMI_TRUE,
                        NULL);

    if (menu_gid != GRP_ID_INVALID)
    {
        cui_menu_run(menu_gid);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_saved_story_viewer_option
 * DESCRIPTION
 *  mmi_dcd_entry_saved_story_viewer_option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_saved_story_viewer_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid = cui_menu_create(
                        GRP_ID_DCD,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_FROM_RESOURCE,
                        MENU_ID_DCD_SAVED_STORY_VIEWER_OPTION,
                        MMI_TRUE,
                        NULL);

    if (menu_gid != GRP_ID_INVALID)
    {
        cui_menu_run(menu_gid);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_backgound_list_option
 * DESCRIPTION
 *  mmi_dcd_entry_backgound_list_option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_backgound_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid = cui_menu_create(
                        GRP_ID_DCD,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_FROM_RESOURCE,
                        MENU_ID_DCD_BACKGOUND_LIST_OPTION,
                        MMI_TRUE,
                        NULL);

    if (menu_gid != GRP_ID_INVALID)
    {
        cui_menu_run(menu_gid);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_city_weather_viewer_option
 * DESCRIPTION
 *  mmi_dcd_entry_city_weather_viewer_option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_city_weather_viewer_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid = cui_menu_create(
                        GRP_ID_DCD,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_FROM_RESOURCE,
                        MENU_ID_DCD_CITY_WEATHER_DETAIL_OPTION,
                        MMI_TRUE,
                        NULL);

    if (menu_gid != GRP_ID_INVALID)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_SET_AS_DEFAULT_CITY, MMI_FALSE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_DELETE_CITY, MMI_FALSE);
        cui_menu_run(menu_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_exit_channel_detail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_exit_channel_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dcd_app_viewer.normal_exit)
    {
        ui_dcd_set_screen_exit_normal(MMI_TRUE);
    }
    else
    {
        ui_dcd_set_screen_exit_normal(MMI_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_app_message_proc
 * DESCRIPTION
 *  process the event from engine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
SDK_RESULT mmi_dcd_app_message_proc(EDCD_MSG_CODE a_eMsgCode, BRVOID *a_pUserData, BRLONG a_nParam1, BRLONG a_nParam2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    STDCD_ITEM_INFO * SelectItemInfo;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_MESSAGE_PROC, a_eMsgCode);
    //agent_handle = mmi_dcd_get_agent_handle();
    switch (a_eMsgCode)
    {
        case eDCD_MSG_DETAIL_VIEW_OPEN_CHANNEL:
        {
            g_dcd_app_cntx.channel_index = (S32)a_nParam1;
            mmi_dcd_pre_entry_channel_detail();
            break;
        }
            
        case eDCD_MSG_DETAIL_VIEW_OPEN_ENTRY:
        {
            SelectItemInfo = (STDCD_ITEM_INFO*)a_nParam1;
            strcpy(g_dcd_app_cntx.channel_id, SelectItemInfo->szChannelID);
            strcpy(g_dcd_app_cntx.block_id, SelectItemInfo->szBlockID);
            strcpy(g_dcd_app_cntx.entry_id, SelectItemInfo->szEntryID);

            g_dcd_app_cntx.PageOrder = SelectItemInfo->nPageOrder;
            mmi_dcd_pre_entry_story_viewer();
            break;
        }
            
        case eDCD_MSG_DETAIL_VIEW_OPEN_BACKGROUNDLIST_BLOCK:
        {
            g_dcd_app_cntx.block_index = (S32)a_nParam1;
            mmi_dcd_pre_entry_background_list();
            break;
        }
        
        case eDCD_MSG_DETAIL_VIEW_OPEN_BACKGROUNDLIST_PAGE:
        {
            S32 page_index = (S32)a_nParam1;
            mmi_dcd_entry_background_list_page_move(page_index);
            break;
        }
        
        case eDCD_MSG_DETAIL_VIEW_OPEN_WEATHER_BLOCK:
        {
            g_dcd_app_cntx.block_index = (S32)a_nParam1;

            mmi_dcd_pre_entry_weather_city();
            break;
        }

        case eDCD_MSG_DETAIL_VIEW_OPEN_ADDCITY_PAGE:
        {
            S32 page_index = (S32)a_nParam1;
            mmi_dcd_pre_entry_city_list(page_index);
            break;
        }
        
        case eDCD_MSG_DETAIL_VIEW_FIND_CITY:
        {
            mmi_dcd_entry_search_city((CHAR*)a_nParam1);
            break;
        }
        
        case eDCD_MSG_STORY_VIEW_NEXT_PAGE:
        {
            mmi_dcd_entry_story_page_move(DCD_ENTRY_NEXT_PAGE);
            break;
        }
        
        case eDCD_MSG_STORY_VIEW_PREV_PAGE:
        {
            mmi_dcd_entry_story_page_move(DCD_ENTRY_PRE_PAGE);
            break;
        }

        case eDCD_MSG_STORY_VIEW_PREV_ITEM:
        {
            mmi_dcd_entry_story_item_move(DCD_ENTRY_PRE_ITEM);
            break;
        }

        case eDCD_MSG_STORY_VIEW_NEXT_ITEM:
        {
            mmi_dcd_entry_story_item_move(DCD_ENTRY_NEXT_ITEM);
            break;
        }

        case eDCD_MSG_DETAIL_VIEW_BACKGROUNDLIST_ITEM:
        case eDCD_MSG_STORY_VIEW_OPEN_LINK:
        {
            mmi_dcd_entry_story_open_link((S8*)a_nParam1);
            break;
        }
        case eDCD_MSG_DETAIL_VIEW_ADDCITY:
        {
            mmi_dcd_entry_add_city_selected_query((CHAR*)a_nParam1);
            break;
        }
        
        case eDCD_MSG_DETAIL_VIEW_OPEN_WEATHER_BLOCK_FOCUS:
        {
            g_dcd_app_cntx.block_index = (S32)a_nParam1;
            mmi_dcd_get_city_block_focus();
            break;
        }
        case eDCD_MSG_DETAIL_VIEW_OPEN_WEATHER_BLOCK_DEFOCUS:
        {
            memset(g_dcd_app_cntx.block_id, 0, sizeof(g_dcd_app_cntx.block_id));
            break;
        }
        default:
            break;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_pre_entry_story_viewer
 * DESCRIPTION
 *  mmi_dcd_pre_entry_story_viewer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_pre_entry_story_viewer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Entry entry_handle = NULL;
    HDCD_Story story_handle = NULL;
    MMI_BOOL  is_syncing = MMI_FALSE;
    MMI_BOOL  result = MMI_FALSE;
    CHAR url[MMI_DCD_MAX_URL_LEN];
    U8 hasHot = 0;
    EDCD_AGENT_RESULT check_result  = eDCD_ERR_UNKNOWN;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_PRE_ENTRY_STORY_VIEWER);
    agent_handle = mmi_dcd_get_agent_handle();
    entry_handle = mmi_dcd_get_current_entry(agent_handle);

    check_result = emDCDAgent_IsValidHandle(entry_handle);
    if (eDCD_SUCCESS != check_result)
    {
        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DCD_CONTENT_DELETED), MMI_EVENT_FAILURE, NULL);
        return;
    }
    
    story_handle = emDCDAgent_GetEntryStoryPageOrder(entry_handle, g_dcd_app_cntx.PageOrder + 1);
    if (!story_handle)
    {
        if (g_dcd_app_cntx.PageOrder == 0)
        {
            hasHot = 1;
        }
        memset(url, 0, sizeof(url));
        sprintf(url, "entryId=%s&pageOrder=%d&hasHot=%d", g_dcd_app_cntx.entry_id, (g_dcd_app_cntx.PageOrder + 1), hasHot);    
        result = mmi_dcd_user_to_sync(DCD_SYNC_REQ_TYPE_GETENTRYCONTENT, url, &is_syncing);
        if (!result)
        {
            mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
        }
        else if (is_syncing == MMI_TRUE)
        {
            mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_V30_BACKGROUND_SYNC_PROGRESS), MMI_EVENT_FAILURE, NULL);
        }
        else
        {
            mmi_dcd_entry_connect_sync();
            g_isSyncStopped = MMI_FALSE;
            g_GettingStoryContent = MMI_FALSE;
        }
    }
    else
    {
        g_dcd_app_viewer.normal_entry = MMI_TRUE;
        g_dcd_app_viewer.normal_exit = MMI_FALSE;
        mmi_dcd_story_content_request();
        mmi_dcd_entry_story_viewer();
        if (!g_GettingStoryContent)
        {
            mmi_dcd_entry_get_next_story_page();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_story_content_request
 * DESCRIPTION
 *  mmi_dcd_story_content_request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_story_content_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Entry entry_handle = NULL;
    HDCD_Story story_handle = NULL;
    MMI_BOOL  is_syncing = MMI_FALSE;
    MMI_BOOL  result = MMI_FALSE;
    CHAR url[MMI_DCD_MAX_URL_LEN];
    S32 content_cnt = 0;
    S32 content_index = 0;
    CHAR * content_id[10] = {NULL};   
    HDCD_Content content_handle = NULL;
    S32    content_length = -1;
    S32    content_id_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_STORY_CONTENT_REQUEST);
    agent_handle = mmi_dcd_get_agent_handle();
    entry_handle = mmi_dcd_get_current_entry(agent_handle);
    story_handle = emDCDAgent_GetEntryStoryPageOrder(entry_handle, g_dcd_app_cntx.PageOrder + 1);

    if (!story_handle)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
        return;
    }

    content_cnt = emDCDAgent_GetStoryContentCount(story_handle);

    if (content_cnt <= 0)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
        return;
    }
    else
    {
        for (content_index = 0; content_index < content_cnt; content_index++)
        {
            content_handle = emDCDAgent_GetStoryContentAt(story_handle, content_index);
            if (!content_handle)
            {
                MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
                continue;
            }
            else
            {
                content_length = emDCDAgent_GetContentLength(content_handle);
                if (content_length <= 0)
                {
                    content_id[content_id_index] = emDCDAgent_GetContentID(content_handle);
                    content_id_index++;
                }
                else
                {
                    continue;
                }
            }
        }
        if ((content_id[0] == NULL) || (strlen(content_id[0]) == 0))
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
            return;
        }
        else
        {
            memset(url, 0, sizeof(url));
            sprintf(url, "%s", content_id[0]);
            for (content_index = 1; content_index < content_id_index; content_index++)
            {
                strcat(url, ",");
                strcat(url, content_id[content_index]);
            }
            result = mmi_dcd_user_to_sync(DCD_SYNC_REQ_TYPE_GETDATA2, url, &is_syncing);
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_RESULT, result);
            if (result && (!is_syncing))
            {
                g_GettingStoryContent = MMI_TRUE;
                MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_get_next_story_page
 * DESCRIPTION
 *  mmi_dcd_entry_get_next_story_page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_get_next_story_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Entry entry_handle = NULL;
    HDCD_Story story_handle = NULL;
    MMI_BOOL  is_syncing = MMI_FALSE;
    MMI_BOOL  result = MMI_FALSE;
    CHAR url[MMI_DCD_MAX_URL_LEN];
    S32 story_total_count = 0;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_GET_NEXT_STORY_PAGE);
    agent_handle = mmi_dcd_get_agent_handle();
    entry_handle = mmi_dcd_get_current_entry(agent_handle);

    story_total_count = emDCDAgent_GetEntryStoryTotalPageCount(entry_handle);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_NEXT_STORY_PAGE_INFO, story_total_count, g_dcd_app_cntx.PageOrder + 1); 
    
    if ((g_dcd_app_cntx.PageOrder + 1) >= story_total_count)
    {
        /*already the last page*/
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
        return;
    }
    story_handle = emDCDAgent_GetEntryStoryPageOrder(entry_handle, g_dcd_app_cntx.PageOrder + 2);
    if (!story_handle)
    {
        memset(url, 0, sizeof(url));
        sprintf(url, "entryId=%s&pageOrder=%d&hasHot=0", g_dcd_app_cntx.entry_id, (g_dcd_app_cntx.PageOrder + 2));    

        result = mmi_dcd_user_to_sync(DCD_SYNC_REQ_TYPE_GETENTRYCONTENT, url, &is_syncing);
        if (!result)
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
        }
        else if (is_syncing == MMI_TRUE)
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
        }
        else
        {
            g_isSyncStopped = MMI_FALSE;
            g_gettingNextPage = MMI_TRUE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_story_viewer
 * DESCRIPTION
 *  mmi_dcd_entry_story_viewer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_story_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Entry entry_handle =NULL;
    U8 *gui_buffer;
    EDCD_AGENT_RESULT check_result  = eDCD_ERR_UNKNOWN;
    EDCD_VIEW_MODE  pre_view_mode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ENTRY_STORY_VIEWER); 
    if (mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_STORY_VIEWER, mmi_dcd_exit_channel_detail, mmi_dcd_entry_story_viewer, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
    {
        return;
    }
    
    agent_handle = mmi_dcd_get_agent_handle();

    pre_view_mode = g_dcd_app_cntx.view_mode;
    
    g_dcd_app_cntx.view_mode = eDCD_VIEW_STORY;
    entry_handle = mmi_dcd_get_current_entry(agent_handle);
    
    check_result = emDCDAgent_IsValidHandle(entry_handle);
    
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    if ((g_dcd_app_viewer.normal_entry) || (g_contentNeedUpdate))
    {
        mmi_dcd_show_end(agent_handle);
        g_contentNeedUpdate = MMI_FALSE;

        if (eDCD_SUCCESS != check_result)
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
            mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DCD_CONTENT_DELETED), MMI_EVENT_FAILURE, NULL);
            g_dcd_app_viewer.normal_exit = MMI_TRUE;
            mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_STORY_VIEWER);
            return;
        }
    }
    else
    {
        mmi_dcd_show_pause(agent_handle);
        if ((eDCD_SUCCESS != check_result) && (pre_view_mode != g_dcd_app_cntx.view_mode))
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
            mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DCD_CONTENT_DELETED), MMI_EVENT_FAILURE, NULL);
            g_dcd_app_viewer.normal_exit = MMI_TRUE;
            mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_STORY_VIEWER);
            return;
        }
    }

    emDCDAgent_SetStoryViewerID(agent_handle, g_dcd_app_cntx.channel_id, g_dcd_app_cntx.block_id, g_dcd_app_cntx.entry_id, g_dcd_app_cntx.PageOrder);
    mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_STORY);
    
    if (g_dcd_app_viewer.normal_entry)
    {
        g_dcd_app_viewer.normal_entry = MMI_FALSE;
    }
    g_dcd_app_viewer.normal_exit = MMI_FALSE;

    wgui_cat9003_op01_show(
        (UI_string_type) GetString(STR_GLOBAL_OPTIONS),
        (PU8) GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type) GetString(STR_GLOBAL_BACK), (PU8) GetImage(IMG_GLOBAL_BACK),
#if defined(__MMI_TOUCH_SCREEN__)
        ui_dcd_pen_handler,
#else 
        NULL,
#endif 
        (void*)agent_handle, gui_buffer);

    SetLeftSoftkeyFunction(mmi_dcd_entry_story_viewer_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dcd_story_viewer_rsk_handler, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_pre_entry_saved_story_viewer
 * DESCRIPTION
 *  mmi_dcd_pre_entry_saved_story_viewer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_pre_entry_saved_story_viewer(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_app_viewer.normal_entry = MMI_TRUE;
    g_dcd_app_viewer.normal_exit = MMI_FALSE;
    g_saved_story_list_cntx.pageorder = 0;
    mmi_dcd_entry_saved_story_viewer();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_saved_story_viewer
 * DESCRIPTION
 *  mmi_dcd_entry_saved_story_viewer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_saved_story_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    U8 *gui_buffer;
    HDCD_Entry entry_handle = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ENTRY_SAVED_STORY_VIEWER); 
    
    if (mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_SAVE_STORY_VIEWER, mmi_dcd_exit_channel_detail, mmi_dcd_entry_saved_story_viewer, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
    {
        return;
    }
    
    agent_handle = mmi_dcd_get_agent_handle();

    entry_handle = emDCDAgent_GetPermanenceEntryAt(agent_handle, g_saved_story_list_cntx.story_index);
    strcpy(g_saved_story_list_cntx.entry_id, emDCDAgent_GetEntryID(entry_handle));

    g_dcd_app_cntx.view_mode = eDCD_VIEW_SAVEDSTORY;

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    if (g_dcd_app_viewer.normal_entry)
    {
        mmi_dcd_show_end(agent_handle);
    }
    else
    {
        mmi_dcd_show_pause(agent_handle);
    }
    emDCDAgent_SetStoryViewerID(agent_handle, NULL, NULL, g_saved_story_list_cntx.entry_id, g_saved_story_list_cntx.pageorder);
    mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_SAVEDSTORY);

    if (g_dcd_app_viewer.normal_entry)
    {
        g_dcd_app_viewer.normal_entry = MMI_FALSE;
    }
    g_dcd_app_viewer.normal_exit = MMI_FALSE;
    
    wgui_cat9003_op01_show(
        (UI_string_type) GetString(STR_GLOBAL_OPTIONS),
        (PU8) GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type) GetString(STR_GLOBAL_BACK), (PU8) GetImage(IMG_GLOBAL_BACK),
#if defined(__MMI_TOUCH_SCREEN__)
        ui_dcd_pen_handler,
#else 
        NULL,
#endif 
        (void*)agent_handle, gui_buffer);

    SetLeftSoftkeyFunction(mmi_dcd_entry_saved_story_viewer_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dcd_story_viewer_rsk_handler, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_pre_entry_object_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_pre_entry_object_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Entry entry_handle = NULL;
    HDCD_Story story_handle = NULL;
    HDCD_Content content_handle = NULL;
    S32 content_count = 0, index = 0, content_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check entry handle */
    agent_handle = mmi_dcd_get_agent_handle();
    entry_handle = mmi_dcd_get_current_entry(agent_handle);
    if (!entry_handle)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
        
        /* invalid handle, just popup and return */
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE, NULL);
        return;
    }

    /* init object context */
    g_dcd_app_viewer.object_count = 0;
    g_dcd_app_viewer.curr_object = 0;
    memset(g_dcd_app_viewer.objects_index, 0, sizeof(S32) * MAX_DCD_OBJECT_COUNT);

    /* story */
    story_handle = mmi_dcd_get_current_story(entry_handle);
    if (story_handle)
    {
        content_count = emDCDAgent_GetStoryContentCount(story_handle);
        for (index = 0; index < content_count; index++)
        {
            content_handle = emDCDAgent_GetStoryContentAt(story_handle, index);
            if (content_handle)
            {
                content_len = emDCDAgent_GetContentLength(content_handle);
                if (content_len > 0)
                {
                    g_dcd_app_viewer.objects_index[g_dcd_app_viewer.object_count] = index;
                    g_dcd_app_viewer.object_count++;
                }
            }
        }
        if (g_dcd_app_viewer.object_count > 0)
        {
            mmi_dcd_entry_image_list();
        }
        else
        {    
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ENTRY_NO_CONTENT);
            
            /* there is no image, trace and popup no image */
            mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_NO_IMAGE), MMI_EVENT_FAILURE, NULL);
        }
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
        
        /* entry handle is invalid, popup error */
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_image_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_image_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_IMAGE_LIST, NULL, mmi_dcd_entry_image_list, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    
    SetParentHandler(SCR_ID_DCD_IMAGE_LIST);
    RegisterHighlightHandler(mmi_dcd_object_list_get_item_index);    
    ShowCategory184Screen(
        STR_GLOBAL_PICTURE,
        NULL,
        STR_GLOBAL_SAVE,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_dcd_app_viewer.object_count,
        mmi_dcd_get_object_item,
        NULL,
        g_dcd_app_viewer.curr_object,
        gui_buffer);

    g_dcd_app_viewer.drive_index = 0; /* insure highlight item is the first one in storage select screen */
    
    SetLeftSoftkeyFunction(mmi_dcd_entry_select_storage, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_select_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_select_storage(void)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_gid = cui_storage_selector_create(
                GRP_ID_DCD,
                g_dcd_app_viewer.drive_index,
                0);
    cui_storage_selector_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_cui_storage_selector_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_cui_storage_selector_proc(cui_storage_selector_result_event_struct *result_event)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (result_event->result > 0)
    {
        g_dcd_app_viewer.drive_index = (S8)result_event->result;
        mmi_dcd_save_object();
    }
    cui_storage_selector_close(result_event->sender_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_images_folder_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_get_images_folder_path(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drv[4];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(drv, "%c:\\", (S8)g_dcd_app_viewer.drive_index);
    mmi_asc_to_ucs2((S8*) path, drv);
    mmi_ucs2cat((S8*) path, (const S8*)FMGR_DEFAULT_FOLDER_IMAGES);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_save_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_save_object_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Agent entry_handle = NULL;
    HDCD_Story story_handle = NULL;
    HDCD_Content content_handle = NULL;
    BRSTR content_id = NULL;
    MMI_BOOL content_valid = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check entry handle */
    agent_handle = mmi_dcd_get_agent_handle();
    entry_handle = mmi_dcd_get_current_entry(agent_handle);
    if (!entry_handle)
    {
        content_valid = MMI_FALSE;
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
    }
    else
    {
        memset(g_dcd_app_viewer.file_name, 0, sizeof(g_dcd_app_viewer.file_name));
        story_handle = mmi_dcd_get_current_story(entry_handle);
        if (story_handle)
        {
            content_handle = emDCDAgent_GetStoryContentAt(story_handle, g_dcd_app_viewer.objects_index[g_dcd_app_viewer.curr_object]);
            if (content_handle)
            {
                content_id = emDCDAgent_GetContentID(content_handle);
                mmi_asc_to_ucs2((CHAR*)g_dcd_app_viewer.file_name, (CHAR*)content_id);
                mmi_dcd_entry_file_name_editor();
            }
            else
            {
                content_valid = MMI_FALSE;
                MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
            }
        }
        else
        {
            content_valid = MMI_FALSE;
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
        }
    }

    if (!content_valid)
    {
        /* invalid handle, just popup and return */
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
        mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_IMAGE_LIST);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_file_name_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
static void mmi_dcd_entry_file_name_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filename_editor_cui_id = cui_filename_editor_create(
                                GRP_ID_DCD, 
                                (WCHAR *)g_dcd_app_viewer.file_name, 
                                ((SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN + 1) * ENCODING_LENGTH),
                                MAX_DCD_SAVED_IMAGE_NAME_LEN,//SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN
                                NULL,
                                NULL);
    cui_filename_editor_set_title(filename_editor_cui_id, STR_GLOBAL_FILENAME, NULL);
    cui_filename_editor_run(filename_editor_cui_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_save_object
 * DESCRIPTION
 *  
 * PARAMETERS
 * void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_save_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;
    U16 path[(SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN) * ENCODING_LENGTH];
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dcd_get_images_folder_path((S8*)path);
    
    if (FS_GetDevStatus(path[0], FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
    {
        mmi_popup_display((WCHAR*)GetString(FMGR_FS_DEVICE_BUSY_TEXT), MMI_EVENT_FAILURE, NULL);
        return;
    }

    file_handle = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle < 0)
    {
        fs_ret = FS_CreateDir(path);
        
        kal_wap_trace(MOD_MMI_CONN_APP, TRACE_INFO, "[DCD][APP] save object fs_ret is %d", fs_ret);
        
        if (fs_ret == FS_NO_ERROR)
        {
             mmi_dcd_save_object_ext();
        }
        else
        {
            //mmi_popup_display((WCHAR*)GetString(FMGR_FS_ROOT_DIR_FULL_TEXT), MMI_EVENT_FAILURE, NULL);
            mmi_popup_display(
                (WCHAR*)GetString((U16) srv_fmgr_fs_error_get_string(fs_ret)), 
                MMI_EVENT_FAILURE, 
                NULL);
        }
    }
    else
    {
        FS_Close(file_handle);
        mmi_dcd_save_object_ext();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_object_list_get_item_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_object_list_get_item_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_app_viewer.curr_object = index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_object_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         [?]         [?]
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static pBOOL mmi_dcd_get_object_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Entry entry_handle = NULL;
    HDCD_Story story_handle = NULL;
    HDCD_Content content_handle = NULL;
    BRSTR content_id = NULL;
    S8 ucs2_id[MAX_DCD_OBJECT_ITEM_LEN * ENCODING_LENGTH] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    agent_handle = mmi_dcd_get_agent_handle();
    entry_handle = mmi_dcd_get_current_entry(agent_handle);
    story_handle = mmi_dcd_get_current_story(entry_handle);
    if (story_handle && item_index < g_dcd_app_viewer.object_count)
    {
        memset(ucs2_id, 0, (MAX_DCD_OBJECT_ITEM_LEN * ENCODING_LENGTH));
        content_handle = emDCDAgent_GetStoryContentAt(story_handle, g_dcd_app_viewer.objects_index[item_index]);
        if (content_handle)
        {
            content_id = emDCDAgent_GetContentID(content_handle);
            mmi_asc_to_ucs2((CHAR*)ucs2_id, (CHAR*)content_id);
            mmi_ucs2cpy((S8*)str_buff, (S8*)ucs2_id);
            *img_buff_p = get_image((MMI_ID_TYPE)(IMG_GLOBAL_L1 + item_index));
        }
    }
    return MMI_TRUE;
}

static void mmi_dcd_entry_saved_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fs_error_enum FS_state = FS_NO_ERROR;
    U64 disk_free_space = 0;
    U64 disk_total_space = 0;
    S32 ret = FS_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if(srv_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return;
    }
#endif
        
    FS_state = FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_FEATURE_STATE_ENUM);
    
    if (FS_state == FS_DEVICE_BUSY)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
        mmi_popup_display((WCHAR*)GetString(FMGR_FS_DEVICE_BUSY_TEXT), MMI_EVENT_FAILURE, NULL);
        return;
    }
    srv_fmgr_drv_get_size(SRV_FMGR_PUBLIC_DRV, &disk_total_space, &disk_free_space);
    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_INFO, "[DCD][APP] free space is %d", disk_free_space);
    if (disk_free_space < MAX_DCD_SAVED_TEXT_SIZE)
    {
        mmi_popup_display((WCHAR*)GetString(FMGR_FS_DISK_FULL_TEXT), MMI_EVENT_FAILURE, NULL);
        return;
    }

    ret = mmi_dcd_init_saved_text_folder();
    if (ret < FS_NO_ERROR)
    {
        return;
    }
    mmi_dcd_init_saved_text_file();
}

static S32 mmi_dcd_init_saved_text_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1];
    FS_HANDLE handle = NULL;
    S32 ret = FS_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(path,"%c:\\%s", SRV_FMGR_PUBLIC_DRV, MMI_DCD_SAVED_TEXT_FLODER);
    handle = FS_Open(path, FS_READ_ONLY| FS_OPEN_DIR);
    if (handle < 0)
    {
        ret = FS_CreateDir(path);
        if (ret < FS_NO_ERROR)
        {
            /* Do not care error. */
            if (ret == FS_ROOT_DIR_FULL)
            {
                mmi_popup_display((WCHAR*)GetString(FMGR_FS_ROOT_DIR_FULL_TEXT), MMI_EVENT_FAILURE, NULL);
            }
        }
        else
        {
            FS_SetAttributes(path, FS_ATTR_DIR /*| FS_ATTR_HIDDEN*/);    
        }
        return ret;
    }
    
    FS_Close(handle);
    return ret;
}

static void mmi_dcd_init_saved_text_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Entry entry_handle = NULL;
    HDCD_Story story_handle = NULL;
    WCHAR path[(SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN)];
    BRSTR pagecontent = NULL;
    S32 buff_size = 0;
    S32 content_len = 0;
    S32 max_sms_len = 0;
    CHAR* content_buffer = NULL;
    UINT file_length = 0;
    S32 ret = -1;
    FS_HANDLE handle = NULL;
    BRSTR title = NULL;
    CHAR* text_content = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    agent_handle = mmi_dcd_get_agent_handle();
    entry_handle = mmi_dcd_get_current_entry(agent_handle);
    if (!entry_handle)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
        
        /* invalid handle, just popup and return */
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE, NULL);
        return;
    }

    if (g_dcd_app_cntx.view_mode == eDCD_VIEW_STORY)
    {
        kal_wsprintf(path,"%c:\\%s\\%s(%d)%s", SRV_FMGR_PUBLIC_DRV, MMI_DCD_SAVED_TEXT_FLODER, g_dcd_app_cntx.entry_id, g_dcd_app_cntx.PageOrder + 1, MMI_DCD_SAVED_TEXT_FORMAT);
    }
    else if (g_dcd_app_cntx.view_mode == eDCD_VIEW_SAVEDSTORY)
    {
        kal_wsprintf(path,"%c:\\%s\\%s(%d)%s", SRV_FMGR_PUBLIC_DRV, MMI_DCD_SAVED_TEXT_FLODER, g_saved_story_list_cntx.entry_id, g_saved_story_list_cntx.pageorder + 1, MMI_DCD_SAVED_TEXT_FORMAT);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
    }


    handle = FS_Open(path, FS_READ_ONLY);
    
    if (handle < 0)
    {
        handle = FS_Open(path, FS_CREATE | FS_READ_WRITE);
        text_content = (CHAR*)OslMalloc(MAX_DCD_SAVED_TEXT_SIZE);
        memset(text_content, 0, MAX_DCD_SAVED_TEXT_SIZE);
        /* title */
        title = emDCDAgent_GetEntryTitle(entry_handle);
        if (title)
        {
            strcpy(text_content, title);
        }
        
        story_handle = mmi_dcd_get_current_story(entry_handle);

        if (story_handle)
        {
            /* page content */
            pagecontent = emDCDAgent_GetStoryPageContent(story_handle);
            if (pagecontent)
            {
                /* max 2K */
                buff_size = MAX_DCD_STORY_TEXT_LEN;
                content_buffer = (BRSTR)OslMalloc(buff_size);
                memset(content_buffer, 0, buff_size);
                content_len = emDCDAgent_GetTextFromHTML(pagecontent, (char*)content_buffer, buff_size - 1);
                if (content_len > 0)
                {
                    if (strlen(text_content) > 0)  /*if have title*/
                    {
                        strcat(text_content, " ");
                    }

                    strcat(text_content, content_buffer);
                    ret = FS_Write(handle, text_content, buff_size, &file_length);

                    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_INFO, "[DCD][APP] save result is %d", ret);
                        
                    if (ret == FS_DISK_FULL)
                    {
                        FS_Delete((U16*) path);
                        mmi_popup_display((WCHAR*)(UI_string_type)GetString(FMGR_FS_DISK_FULL_TEXT), MMI_EVENT_FAILURE, NULL);
                    }
                    else
                    {
                        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, NULL);
                    }

                }
                else
                {
                    if (strlen(text_content) > 0)
                    {
                        ret = FS_Write(handle, text_content, strlen(text_content), &file_length);
                        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, NULL);
                    }
                    else
                    {
                        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DCD_NO_TEXT_CONTENT), MMI_EVENT_FAILURE, NULL);
                        FS_Delete((U16*) path);
                        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
                    }
                }
                OslMfree(content_buffer);
            }
            else
            {
                if (strlen(text_content) > 0)
                {
                    ret = FS_Write(handle, text_content, strlen(text_content), &file_length);
                    mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, NULL);
                }
                else
                {
                    mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DCD_NO_TEXT_CONTENT), MMI_EVENT_FAILURE, NULL);
                    FS_Delete((U16*) path);
                    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);                    
                }
            }
        }

        OslMfree(text_content);
        
        FS_Close(handle);
    }
    else
    {
        //popup
        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_FILE_ALREADY_EXISTS), MMI_EVENT_FAILURE, NULL);
        FS_Close(handle);
    }

    return;

}



/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_story_viewer_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_story_viewer_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_app_viewer.normal_exit = MMI_TRUE;

    if (g_dcd_app_cntx.view_mode == eDCD_VIEW_STORY)
    {
        //g_dcd_app_cntx.view_mode = eDCD_VIEW_CHANNEL_DETAIL;
        mmi_frm_scrn_close_active_id();
        if (g_GettingStoryContent || g_gettingNextPage)
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_STOP_ENTRY_CONTENT_SYNC);
            mmi_dcd_stop_sync();
            g_GettingStoryContent = MMI_FALSE;
            g_gettingNextPage = MMI_FALSE;
        }
    }

    else if (g_dcd_app_cntx.view_mode == eDCD_VIEW_BACKGROUND_LIST)
    {
        mmi_frm_scrn_close_active_id();
    }
    else if (g_dcd_app_cntx.view_mode == eDCD_VIEW_WEATHER)
    {
        //g_dcd_app_cntx.view_mode = eDCD_VIEW_CHANNEL_DETAIL;
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        mmi_frm_scrn_close_active_id();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_story_viewer_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_city_weather_viewer_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_app_viewer.normal_exit = MMI_TRUE;
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_CLEAR_CITY_BLOCK);
    memset(g_dcd_app_cntx.block_id, 0, sizeof (g_dcd_app_cntx.block_id));
    memset(g_dcd_app_cntx.entry_id, 0, sizeof (g_dcd_app_cntx.entry_id));
    mmi_frm_scrn_close_active_id();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_story_viewer_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_pre_entry_background_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle =NULL;
    HDCD_Block block_handle = NULL;
    BRSTR new_block_id;
    CHAR a_szChannelID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    CHAR a_szBlockID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    CHAR a_szEntryID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    BRINT  a_nPageOrder = 0;
    CHAR url[MMI_DCD_MAX_URL_LEN];
    MMI_BOOL result = MMI_FALSE;
    MMI_BOOL is_syncing = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_PRE_ENTRY_BACKGROUND_LIST);
    agent_handle = mmi_dcd_get_agent_handle();
    memset(a_szChannelID, 0, sizeof(a_szChannelID));
    memset(a_szBlockID, 0, sizeof(a_szBlockID));
    memset(a_szEntryID, 0, sizeof(a_szEntryID));
    
    emDCDAgent_GetStoryViewerID(agent_handle, a_szChannelID, a_szBlockID, a_szEntryID, &a_nPageOrder);
    strcpy(g_dcd_app_cntx.channel_id, a_szChannelID);
    strcpy(g_dcd_app_cntx.block_id, a_szBlockID);
    strcpy(g_dcd_app_cntx.entry_id, a_szEntryID);

    g_dcd_app_cntx.channel_index = emDCDAgent_GetChannelIndex(agent_handle, g_dcd_app_cntx.channel_id);
    g_dcd_app_cntx.channel_handle = emDCDAgent_GetChannelAt(agent_handle, g_dcd_app_cntx.channel_index);
    block_handle = emDCDAgent_GetChannelBlockAt(g_dcd_app_cntx.channel_handle, g_dcd_app_cntx.block_index);
    new_block_id = emDCDAgent_GetBlockID(block_handle);
    strcpy(g_dcd_app_cntx.block_id, new_block_id);

    g_background_list_page_index = 0;
    
    memset(url, 0, sizeof(url));
    sprintf(url, "blockid=%s&start=1&count=%d", g_dcd_app_cntx.block_id, MAX_DCD_BACKGROUND_ITEM_NUM_PER_PAGE);    

    result = mmi_dcd_user_to_sync(DCD_SYNC_REQ_TYPE_GETBACKGROUNDLIST, url, &is_syncing);
    if (!result)
    {
        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
    }
    else if (is_syncing == MMI_TRUE)
    {
        mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_V30_BACKGROUND_SYNC_PROGRESS), MMI_EVENT_FAILURE, NULL);
    }
    else
    {
        mmi_dcd_entry_connect_sync();
        g_isSyncStopped = MMI_FALSE;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_background_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_background_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Channel channel_handle = NULL;
    S32 channel_index = -1;
    HDCD_Block block_handle = NULL;
    BRSTR new_block_id;
    U8 *gui_buffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ENTRY_BACKGROUND_LIST);
    if (mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_BACKGROUND_LIST, mmi_dcd_exit_channel_detail, mmi_dcd_entry_background_list, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
    {
        return;
    }
    
    agent_handle = mmi_dcd_get_agent_handle();

    g_dcd_app_cntx.view_mode = eDCD_VIEW_BACKGROUND_LIST;

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    channel_index = emDCDAgent_GetChannelIndex(agent_handle, g_dcd_app_cntx.channel_id);
    channel_handle = emDCDAgent_GetChannelAt(agent_handle, channel_index);
    block_handle = emDCDAgent_GetChannelBlockAt(channel_handle, g_dcd_app_cntx.block_index);
    new_block_id = emDCDAgent_GetBlockID(block_handle);
    strcpy(g_dcd_app_cntx.block_id, new_block_id);

    if ((g_dcd_app_viewer.normal_entry) || (g_contentNeedUpdate == MMI_TRUE))
    {
        mmi_dcd_show_end(agent_handle);
        g_contentNeedUpdate = MMI_FALSE;
    }
    else
    {
        mmi_dcd_show_pause(agent_handle);
    }
    
    emDCDAgent_SetStoryViewerID(agent_handle, g_dcd_app_cntx.channel_id, g_dcd_app_cntx.block_id, NULL, g_background_list_page_index);
    mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_BACKGROUND_LIST);

    if (g_dcd_app_viewer.normal_entry)
    {
        g_dcd_app_viewer.normal_entry = MMI_FALSE;
    }
    g_dcd_app_viewer.normal_exit = MMI_FALSE;
    wgui_cat9003_op01_show(
        (UI_string_type) GetString(STR_GLOBAL_OPTIONS),
        (PU8) GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type) GetString(STR_GLOBAL_BACK), (PU8) GetImage(IMG_GLOBAL_BACK),
#if defined(__MMI_TOUCH_SCREEN__)
        ui_dcd_pen_handler,
#else 
        NULL,
#endif 
        (void*)agent_handle, gui_buffer);

    SetLeftSoftkeyFunction(mmi_dcd_entry_backgound_list_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dcd_story_viewer_rsk_handler, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_background_list_page_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_background_list_page_move(S32 page_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle =NULL;
    CHAR a_szChannelID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    CHAR a_szBlockID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    CHAR a_szEntryID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    BRINT  a_nPageOrder = 0;
    CHAR url[MMI_DCD_MAX_URL_LEN];
    MMI_BOOL result = MMI_FALSE;
    MMI_BOOL is_syncing = MMI_FALSE;
    U32 start = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_BACKGROUND_LIST_MOVE, page_index);
    agent_handle = mmi_dcd_get_agent_handle();
    memset(a_szChannelID, 0, sizeof(a_szChannelID));
    memset(a_szBlockID, 0, sizeof(a_szBlockID));
    memset(a_szEntryID, 0, sizeof(a_szEntryID));
    
    emDCDAgent_GetStoryViewerID(agent_handle, a_szChannelID, a_szBlockID, a_szEntryID, &a_nPageOrder);
    strcpy(g_dcd_app_cntx.channel_id, a_szChannelID);
    strcpy(g_dcd_app_cntx.block_id, a_szBlockID);
    strcpy(g_dcd_app_cntx.entry_id, a_szEntryID);
    
    g_background_list_page_index = page_index;
    start = MAX_DCD_BACKGROUND_ITEM_NUM_PER_PAGE * page_index + 1;
    memset(url, 0, sizeof(url));
    sprintf(url, "blockid=%s&start=%d&count=%d", g_dcd_app_cntx.block_id, start, MAX_DCD_BACKGROUND_ITEM_NUM_PER_PAGE);

    result = mmi_dcd_user_to_sync(DCD_SYNC_REQ_TYPE_GETBACKGROUNDLIST, url, &is_syncing);
    if (!result)
    {
        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
    }
    else if (is_syncing == MMI_TRUE)
    {
        mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_V30_BACKGROUND_SYNC_PROGRESS), MMI_EVENT_FAILURE, NULL);
    }
    else
    {
        mmi_dcd_entry_connect_sync();
        g_isSyncStopped = MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_pre_entry_weather_city
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_pre_entry_weather_city()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Block block_handle =NULL;
    CHAR a_szChannelID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    CHAR a_szBlockID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    CHAR a_szEntryID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    BRINT  a_nPageOrder = 0;
    BRSTR new_block_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_PRE_ENTRY_WEATHER_CITY);
    agent_handle = mmi_dcd_get_agent_handle();
    memset(a_szChannelID, 0, sizeof(a_szChannelID));
    memset(a_szBlockID, 0, sizeof(a_szBlockID));
    memset(a_szEntryID, 0, sizeof(a_szEntryID));
    
    emDCDAgent_GetStoryViewerID(agent_handle, a_szChannelID, a_szBlockID, a_szEntryID, &a_nPageOrder);
    strcpy(g_dcd_app_cntx.channel_id, a_szChannelID);
    strcpy(g_dcd_app_cntx.block_id, a_szBlockID);
    strcpy(g_dcd_app_cntx.entry_id, a_szEntryID);
    
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_VIEW_MODE, g_dcd_app_cntx.view_mode);

    if (g_dcd_app_cntx.view_mode == eDCD_VIEW_WEATHER)
    {
        g_dcd_app_cntx.channel_index = emDCDAgent_GetChannelIndex(agent_handle, g_dcd_app_cntx.channel_id);
        g_dcd_app_cntx.channel_handle = emDCDAgent_GetChannelAt(agent_handle, g_dcd_app_cntx.channel_index);
        block_handle = emDCDAgent_GetChannelBlockAt(g_dcd_app_cntx.channel_handle, g_dcd_app_cntx.block_index);
        new_block_id = emDCDAgent_GetBlockID(block_handle);
        strcpy(g_dcd_app_cntx.block_id, new_block_id);

        mmi_dcd_show_end(agent_handle);
        emDCDAgent_SetStoryViewerID(agent_handle, g_dcd_app_cntx.channel_id, g_dcd_app_cntx.block_id, NULL, 0);
        mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_WEATHER);
        mmi_dcd_show_start(agent_handle, eERM_RETURN_FROM_NORMAL, NULL);
    }
    else
    {
        g_dcd_app_viewer.normal_entry = MMI_TRUE;
        g_dcd_app_viewer.normal_exit = MMI_FALSE;
        g_isCityDeleted = MMI_FALSE;
        mmi_dcd_entry_weather_city();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_weather_city
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_weather_city(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Channel channel_handle = NULL;
    S32 channel_index = -1;
    HDCD_Block block_handle = NULL;
    BRSTR new_block_id;
    U8 *gui_buffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ENTRY_WEATHER_CITY);
    if (g_isCityDeleted)
    {
        mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_CITY_WEATHER_DETAIL);
        return;
    }

    if (mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_CITY_WEATHER_DETAIL, mmi_dcd_exit_channel_detail, mmi_dcd_entry_weather_city, MMI_FRM_SCRN_GROUP) == MMI_FALSE)
    {
        return;
    }
    
    agent_handle = mmi_dcd_get_agent_handle();
    g_dcd_app_cntx.view_mode = eDCD_VIEW_WEATHER;

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    channel_index = emDCDAgent_GetChannelIndex(agent_handle, g_dcd_app_cntx.channel_id);
    channel_handle = emDCDAgent_GetChannelAt(agent_handle, channel_index);
    block_handle = emDCDAgent_GetChannelBlockAt(channel_handle, g_dcd_app_cntx.block_index);
    new_block_id = emDCDAgent_GetBlockID(block_handle);
    strcpy(g_dcd_app_cntx.block_id, new_block_id);

    if (g_dcd_app_viewer.normal_entry)
    {
        mmi_dcd_show_end(agent_handle);
    }
    else
    {
        mmi_dcd_show_pause(agent_handle);
    }

    emDCDAgent_SetStoryViewerID(agent_handle, g_dcd_app_cntx.channel_id, g_dcd_app_cntx.block_id, NULL, 0);
    mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_WEATHER);

    if (g_dcd_app_viewer.normal_entry)
    {
        g_dcd_app_viewer.normal_entry = MMI_FALSE;
    }
    g_dcd_app_viewer.normal_exit = MMI_FALSE;
    wgui_cat9003_op01_show(
        (UI_string_type) GetString(STR_GLOBAL_OPTIONS),
        (PU8) GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type) GetString(STR_GLOBAL_BACK), (PU8) GetImage(IMG_GLOBAL_BACK),
#if defined(__MMI_TOUCH_SCREEN__)
        ui_dcd_pen_handler,
#else 
        NULL,
#endif 
        (void*)agent_handle, gui_buffer);

    SetLeftSoftkeyFunction(mmi_dcd_entry_city_weather_viewer_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dcd_city_weather_viewer_rsk_handler, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_story_page_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_story_page_move(mmi_dcd_page_move_enum page_move)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle =NULL;
    CHAR a_szChannelID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    CHAR a_szBlockID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    CHAR a_szEntryID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    BRINT  a_nPageOrder = 0;
    HDCD_Story story_handle = NULL;
    CHAR url[MMI_DCD_MAX_URL_LEN];
    MMI_BOOL result = MMI_FALSE;
    MMI_BOOL is_syncing = MMI_FALSE;
    HDCD_Entry  entry_handle = NULL;
    U8 hashot = 0;
    S32  story_count = 0;
    S32  story_total_count = 0;
    S32  story_content_cnt;
    S32  content_index = 0;
    HDCD_Content content_handle = NULL;
    CHAR * content_id[10] = {NULL};
    S32    content_id_index = 0;
    S32    content_length = -1;
    EDCD_AGENT_RESULT check_result  = eDCD_ERR_UNKNOWN;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ENTRY_STORY_PAGE_MOVE);
    agent_handle = mmi_dcd_get_agent_handle();

    memset(a_szChannelID, 0, sizeof(a_szChannelID));
    memset(a_szBlockID, 0, sizeof(a_szBlockID));
    memset(a_szEntryID, 0, sizeof(a_szEntryID));
    emDCDAgent_GetStoryViewerID(agent_handle, a_szChannelID, a_szBlockID, a_szEntryID, &a_nPageOrder);

    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_VIEW_MODE, g_dcd_app_cntx.view_mode);
    if (g_dcd_app_cntx.view_mode == eDCD_VIEW_SAVEDSTORY)
    {
        strcpy(g_saved_story_list_cntx.entry_id, a_szEntryID);
        g_saved_story_list_cntx.pageorder = a_nPageOrder;

        entry_handle = emDCDAgent_GetPermanenceEntryAt(agent_handle, g_saved_story_list_cntx.story_index);
        story_count = emDCDAgent_GetEntryStoryCount(entry_handle);
        story_total_count = story_count;

        if (page_move == DCD_ENTRY_NEXT_PAGE)
        {
            if (g_saved_story_list_cntx.pageorder < story_total_count - 1)
            {
                g_saved_story_list_cntx.pageorder++;
            }
            else
            {
                return;
            }
        }
        if (page_move == DCD_ENTRY_PRE_PAGE)
        {
            if (g_saved_story_list_cntx.pageorder > 0)
            {
                g_saved_story_list_cntx.pageorder--;
            }
            else
            {
                return;
            }
        }
        mmi_dcd_show_end(agent_handle);
        emDCDAgent_SetStoryViewerID(agent_handle, NULL, NULL, g_saved_story_list_cntx.entry_id, g_saved_story_list_cntx.pageorder);
        mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_SAVEDSTORY);
        mmi_dcd_show_start(agent_handle, eERM_RETURN_FROM_NORMAL, NULL);
    }
    else
    {
        strcpy(g_dcd_app_cntx.channel_id, a_szChannelID);
        strcpy(g_dcd_app_cntx.block_id, a_szBlockID);
        strcpy(g_dcd_app_cntx.entry_id, a_szEntryID);
        g_dcd_app_cntx.PageOrder = a_nPageOrder;

        kal_wap_trace(MOD_MMI_CONN_APP, TRACE_INFO, "[DCD][APP] new added a_nPageOrder is %d", a_nPageOrder);

        entry_handle = mmi_dcd_get_current_entry(agent_handle);
        check_result = emDCDAgent_IsValidHandle(entry_handle);
        kal_wap_trace(MOD_MMI_CONN_APP, TRACE_INFO, "[DCD][APP] entry check result is %d", check_result);
        
        if ((!entry_handle) || (check_result != eDCD_SUCCESS))
        {
            mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DCD_CONTENT_DELETED), MMI_EVENT_FAILURE, NULL);
            return;
        }
        story_count = emDCDAgent_GetEntryStoryCount(entry_handle);
        story_total_count = emDCDAgent_GetEntryStoryTotalPageCount(entry_handle);
        
        if (page_move == DCD_ENTRY_NEXT_PAGE)
        {
            if (g_dcd_app_cntx.PageOrder < story_total_count - 1)
            {
                g_dcd_app_cntx.PageOrder++;
            }
            else
            {
                return;
            }
        }
        if (page_move == DCD_ENTRY_PRE_PAGE)
        {
            if (g_dcd_app_cntx.PageOrder > 0)
            {
                g_dcd_app_cntx.PageOrder--;
            }
            else
            {
                return;
            }
        }

        story_handle = emDCDAgent_GetEntryStoryPageOrder(entry_handle, g_dcd_app_cntx.PageOrder + 1);
        
        if (story_handle)
        {
            mmi_dcd_show_end(agent_handle);
            emDCDAgent_SetStoryViewerID(agent_handle, g_dcd_app_cntx.channel_id, g_dcd_app_cntx.block_id, g_dcd_app_cntx.entry_id, g_dcd_app_cntx.PageOrder);
            mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_STORY);
            mmi_dcd_show_start(agent_handle, eERM_RETURN_FROM_NORMAL, NULL);
            
            story_content_cnt = emDCDAgent_GetStoryContentCount(story_handle);
            if (story_content_cnt <= 0)
            {
                MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
                if (page_move == DCD_ENTRY_NEXT_PAGE)
                {
                    mmi_dcd_entry_get_next_story_page();
                }
            }
            else
            {
                for (content_index = 0; content_index < story_content_cnt; content_index++)
                {
                    content_handle = emDCDAgent_GetStoryContentAt(story_handle, content_index);
                    if (!content_handle)
                    {
                        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
                        break;
                    }
                    else
                    {
                        content_length = emDCDAgent_GetContentLength(content_handle);
                        if (content_length <= 0)
                        {
                            content_id[content_id_index] = emDCDAgent_GetContentID(content_handle);
                            content_id_index++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                if (content_id[0] == NULL)
                {
                    if (page_move == DCD_ENTRY_NEXT_PAGE)
                    {
                        mmi_dcd_entry_get_next_story_page();
                    }
                }
                else
                {
                    memset(url, 0, sizeof(url));
                    sprintf(url, "%s", content_id[0]);
                    for (content_id_index = 1; content_id[content_id_index] != NULL; content_id_index++)
                    {
                        strcat(url, ",");
                        strcat(url, content_id[content_id_index]);
                    }
                    result = mmi_dcd_user_to_sync(DCD_SYNC_REQ_TYPE_GETDATA2, url, &is_syncing);
                }
            }
        }
        else
        {
            if (g_dcd_app_cntx.PageOrder == 0)
            {
                hashot = 1;
            }
            memset(url, 0, sizeof(url));
            sprintf(url, "entryId=%s&pageOrder=%d&hasHot=%d", g_dcd_app_cntx.entry_id, g_dcd_app_cntx.PageOrder + 1, hashot);    

            result = mmi_dcd_user_to_sync(DCD_SYNC_REQ_TYPE_GETENTRYCONTENT, url, &is_syncing);
            if (!result)
            {
                mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
                if (page_move == DCD_ENTRY_NEXT_PAGE)
                {
                    g_dcd_app_cntx.PageOrder--;
                }
                if (page_move == DCD_ENTRY_PRE_PAGE)
                {
                    g_dcd_app_cntx.PageOrder++;
                }
            }
            else if (is_syncing == MMI_TRUE)
            {
                mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_V30_BACKGROUND_SYNC_PROGRESS), MMI_EVENT_FAILURE, NULL);
                if (page_move == DCD_ENTRY_NEXT_PAGE)
                {
                    g_dcd_app_cntx.PageOrder--;
                }
                if (page_move == DCD_ENTRY_PRE_PAGE)
                {
                    g_dcd_app_cntx.PageOrder++;
                }
            }
            else
            {
                mmi_dcd_entry_connect_sync();
                g_isSyncStopped = MMI_FALSE;
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_story_item_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_story_item_move(mmi_dcd_item_move_enum item_move)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle =NULL;
    CHAR a_szChannelID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    CHAR a_szBlockID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    CHAR a_szEntryID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    BRINT  a_nPageOrder = 0;
    HDCD_Channel channel_handle = NULL;
    HDCD_Block block_handle = NULL;
    S32 block_index = -1;
    S32 entry_index = -1;
    S32 channel_index = -1;
    S32 entry_total_count = -1;
    HDCD_Story story_handle = NULL;
    CHAR url[MMI_DCD_MAX_URL_LEN];
    MMI_BOOL result = MMI_FALSE;
    MMI_BOOL is_syncing = MMI_FALSE;
    S32      block_count = -1;
    EDCD_AGENT_RESULT check_result = eDCD_ERR_UNKNOWN;
    HDCD_Entry entry_handle = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ENTRY_STORY_ITEM_MOVE, item_move);
    agent_handle = mmi_dcd_get_agent_handle();
    
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_VIEW_MODE, g_dcd_app_cntx.view_mode);
    
    if (g_dcd_app_cntx.view_mode == eDCD_VIEW_SAVEDSTORY)
    {
        if (item_move == DCD_ENTRY_NEXT_ITEM)
        {
            if (g_saved_story_list_cntx.story_index < g_saved_story_list_cntx.story_number - 1)
            {
                g_saved_story_list_cntx.story_index++;
            }
            else
            {
                return;
            }
        }
        if (item_move == DCD_ENTRY_PRE_ITEM)
        {
            if (g_saved_story_list_cntx.story_index > 0)
            {
                g_saved_story_list_cntx.story_index--;
            }
            else
            {
                return;
            }
        }
        entry_handle = emDCDAgent_GetPermanenceEntryAt(agent_handle, g_saved_story_list_cntx.story_index);
        strcpy(g_saved_story_list_cntx.entry_id, emDCDAgent_GetEntryID(entry_handle));
        g_saved_story_list_cntx.pageorder = 0;

        mmi_dcd_show_end(agent_handle);    
        emDCDAgent_SetStoryViewerID(agent_handle, NULL, NULL, g_saved_story_list_cntx.entry_id, 0);
        mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_SAVEDSTORY);
        mmi_dcd_show_start(agent_handle, eERM_RETURN_FROM_NORMAL, NULL);
    }
    else
    {
        memset(a_szChannelID, 0, sizeof(a_szChannelID));
        memset(a_szBlockID, 0, sizeof(a_szBlockID));
        memset(a_szEntryID, 0, sizeof(a_szEntryID));
        
        emDCDAgent_GetStoryViewerID(agent_handle, a_szChannelID, a_szBlockID, a_szEntryID, &a_nPageOrder);
        strcpy(g_dcd_app_cntx.channel_id, a_szChannelID);
        strcpy(g_dcd_app_cntx.block_id, a_szBlockID);
        strcpy(g_dcd_app_cntx.entry_id, a_szEntryID);
        g_dcd_app_cntx.PageOrder = a_nPageOrder;

        channel_index = emDCDAgent_GetChannelIndex(agent_handle, g_dcd_app_cntx.channel_id);
        channel_handle = emDCDAgent_GetChannelAt(agent_handle, channel_index);
        block_index = emDCDAgent_GetChannelBlockIndex(channel_handle, g_dcd_app_cntx.block_id);
        block_handle = emDCDAgent_GetChannelBlockAt(channel_handle, block_index);
        entry_total_count = emDCDAgent_GetBlockEntryCount(block_handle);
        entry_index = emDCDAgent_GetBlockEntryIndex(block_handle, g_dcd_app_cntx.entry_id);

        check_result = emDCDAgent_IsValidHandle(channel_handle);
        kal_wap_trace(MOD_MMI_CONN_APP, TRACE_INFO, "[DCD][APP] channel handle check result is %d", check_result);
        
        if (check_result != eDCD_SUCCESS)
        {
            mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DCD_CONTENT_DELETED), MMI_EVENT_FAILURE, NULL);
            return;
        }
        if (!g_item_move_req_data_ptr)
        {
            g_item_move_req_data_ptr = (mmi_dcd_item_move*)OslMalloc(sizeof(mmi_dcd_item_move));
        }
        strcpy(g_item_move_req_data_ptr->block_id, g_dcd_app_cntx.block_id);
        
        if (item_move == DCD_ENTRY_NEXT_ITEM)
        {
            if (entry_index < (entry_total_count - 1))
            {
                entry_index++;
            }
            else
            {
                block_count = emDCDAgent_GetChannelBlockCount(channel_handle);
                if(block_index < block_count - 1)
                {
                    block_index++;
                    block_handle = emDCDAgent_GetChannelBlockAt(channel_handle, block_index);
                    //strcpy(g_dcd_app_cntx.block_id, emDCDAgent_GetBlockID(block_handle));
                    strcpy(g_item_move_req_data_ptr->block_id, emDCDAgent_GetBlockID(block_handle));                    
                    entry_index = 0;
                }
                else
                {
                    if (g_item_move_req_data_ptr)
                    {
                        OslMfree(g_item_move_req_data_ptr);
                        g_item_move_req_data_ptr = NULL;
                    }
                    return;
                }
            }
        }
        if (item_move == DCD_ENTRY_PRE_ITEM)
        {
            if (entry_index > 0)
            {
                entry_index--;
            }
            else
            {
                if(block_index > 0)
                {
                    block_index--;
                    block_handle = emDCDAgent_GetChannelBlockAt(channel_handle, block_index);
                    //strcpy(g_dcd_app_cntx.block_id, emDCDAgent_GetBlockID(block_handle));
                    strcpy(g_item_move_req_data_ptr->block_id, emDCDAgent_GetBlockID(block_handle));
                    entry_total_count = emDCDAgent_GetBlockEntryCount(block_handle);
                    entry_index = entry_total_count - 1;
                }
                else
                {
                    if (g_item_move_req_data_ptr)
                    {
                        OslMfree(g_item_move_req_data_ptr);
                        g_item_move_req_data_ptr = NULL;
                    }
                    return;
                }
            
            }
        }

        entry_handle = emDCDAgent_GetBlockEntryAt(block_handle, entry_index);
        //strcpy(g_dcd_app_cntx.entry_id, emDCDAgent_GetEntryID(entry_handle));
        //g_dcd_app_cntx.PageOrder = 0;

        strcpy(g_item_move_req_data_ptr->entry_id, emDCDAgent_GetEntryID(entry_handle));
        g_item_move_req_data_ptr->PageOrder = 0;
        
        //story_handle = emDCDAgent_GetEntryStoryPageOrder(entry_handle, g_dcd_app_cntx.PageOrder + 1);
        story_handle = emDCDAgent_GetEntryStoryPageOrder(entry_handle, g_item_move_req_data_ptr->PageOrder + 1);
        if (!story_handle)
        {
            memset(url, 0, sizeof(url));
            //sprintf(url, "entryId=%s&pageOrder=%d&hasHot=1", g_dcd_app_cntx.entry_id, g_dcd_app_cntx.PageOrder + 1);    
            sprintf(url, "entryId=%s&pageOrder=%d&hasHot=1", g_item_move_req_data_ptr->entry_id, g_item_move_req_data_ptr->PageOrder + 1);
            
            result = mmi_dcd_user_to_sync(DCD_SYNC_REQ_TYPE_GETENTRYCONTENT, url, &is_syncing);
            if (!result)
            {
                if (g_item_move_req_data_ptr)
                {
                    OslMfree(g_item_move_req_data_ptr);
                    g_item_move_req_data_ptr = NULL;
                }
                mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
            }
            else if (is_syncing == MMI_TRUE)
            {
                if (g_item_move_req_data_ptr)
                {
                    OslMfree(g_item_move_req_data_ptr);
                    g_item_move_req_data_ptr = NULL;
                }
                mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_V30_BACKGROUND_SYNC_PROGRESS), MMI_EVENT_FAILURE, NULL);
            }
            else
            {
                mmi_dcd_entry_connect_sync();
                g_isSyncStopped = MMI_FALSE;
            }
        }
        else
        {
            strcpy(g_dcd_app_cntx.block_id, g_item_move_req_data_ptr->block_id);
            strcpy(g_dcd_app_cntx.entry_id, g_item_move_req_data_ptr->entry_id);
            g_dcd_app_cntx.PageOrder = g_item_move_req_data_ptr->PageOrder;

            if (g_item_move_req_data_ptr)
            {
                OslMfree(g_item_move_req_data_ptr);
                g_item_move_req_data_ptr = NULL;
            }
            mmi_dcd_story_content_request();
            mmi_dcd_show_end(agent_handle);    
            emDCDAgent_SetStoryViewerID(agent_handle, g_dcd_app_cntx.channel_id, g_dcd_app_cntx.block_id, g_dcd_app_cntx.entry_id, g_dcd_app_cntx.PageOrder);
            mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_STORY);
            mmi_dcd_show_start(agent_handle, eERM_RETURN_FROM_NORMAL, NULL);
            if (!g_GettingStoryContent)
            {
                mmi_dcd_entry_get_next_story_page();
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_story_open_link
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_story_open_link(S8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ucs_url = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!url)
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_INVALID_URL), MMI_EVENT_FAILURE, NULL);
        return;
    }
    ucs_url = OslMalloc((strlen((CHAR*)url) + 1) * ENCODING_LENGTH);
    mmi_asc_to_ucs2((CHAR*)ucs_url, (CHAR*)url);
    wap_start_browser(WAP_BROWSER_GOTO_URL, ucs_url);
    OslMfree(ucs_url);
}
HDCD_Entry mmi_dcd_get_current_entry(HDCD_Agent agent_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Channel channel_handle = NULL;
    HDCD_Block block_handle = NULL;
    S32 block_index = -1;
    S32 entry_index = -1;
    S32 channel_index = -1;
    HDCD_Entry entry_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dcd_app_cntx.view_mode == eDCD_VIEW_SAVEDSTORY)
    {
        entry_handle = emDCDAgent_GetPermanenceEntryAt(agent_handle, g_saved_story_list_cntx.story_index);
    }
    else
    {
        channel_index = emDCDAgent_GetChannelIndex(agent_handle, g_dcd_app_cntx.channel_id);
        channel_handle = emDCDAgent_GetChannelAt(agent_handle, channel_index);
        block_index = emDCDAgent_GetChannelBlockIndex(channel_handle, g_dcd_app_cntx.block_id);
        block_handle = emDCDAgent_GetChannelBlockAt(channel_handle, block_index);
        entry_index = emDCDAgent_GetBlockEntryIndex(block_handle, g_dcd_app_cntx.entry_id);
        entry_handle = emDCDAgent_GetBlockEntryAt(block_handle, entry_index);
    }

    return entry_handle;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_current_story
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static HDCD_Story mmi_dcd_get_current_story(HDCD_Entry entry_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Story story_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dcd_app_cntx.view_mode == eDCD_VIEW_SAVEDSTORY)
    {
        story_handle = emDCDAgent_GetEntryStoryPageOrder(entry_handle, g_saved_story_list_cntx.pageorder + 1);
    }
    else
    {
        story_handle = emDCDAgent_GetEntryStoryPageOrder(entry_handle, g_dcd_app_cntx.PageOrder + 1);
    }
    
    return story_handle;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_setting_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_setting_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_DCD_SYSTEM_SETTING, GRP_ID_DCD_SYSTEM_SETTING_OPTION, mmi_dcd_setting_option_proc, (void*)NULL);
    mmi_frm_group_enter(GRP_ID_DCD_SYSTEM_SETTING_OPTION, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    menu_cui_id = cui_menu_create(
                    GRP_ID_DCD_SYSTEM_SETTING_OPTION,
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_FROM_RESOURCE,
                    MENU_ID_DCD_SYSTEM_SETTING_OPTION,
                    MMI_TRUE,
                    NULL);
    
    cui_menu_run(menu_cui_id);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_help_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_help_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  *guiBuffer;
    S8  *str_buf;
    S32 text_size = 0, ucs2_text_len = 0;
    S8  *find_text_p = NULL;
    static HILITE_STR hilite_item[1];

    /*-----------------------------------------------------------  -----*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_HELP, mmi_dcd_exit_help_info, mmi_dcd_entry_help_info, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    text_size = mmi_ucs2strlen(GetString(STR_ID_DCD_V30_HELP_INFO1));
    text_size += mmi_ucs2strlen(GetString(STR_ID_DCD_V30_HELP_INFO2));
    text_size += mmi_ucs2strlen(GetString(STR_ID_DCD_V30_HELP_INFO3));
    text_size += mmi_ucs2strlen(GetString(STR_ID_DCD_V30_HELP_INFO4));
    text_size += mmi_ucs2strlen(GetString(STR_ID_DCD_V30_HELP_INFO5));
    text_size += mmi_ucs2strlen(GetString(STR_ID_DCD_V30_HELP_INFO6));
    text_size += mmi_ucs2strlen(GetString(STR_ID_DCD_V30_HELP_INFO7));
    ucs2_text_len = (text_size + 1)* 2;
    
    g_help_text_p = (S8 *) applib_mem_screen_alloc(ucs2_text_len);
    
    mmi_ucs2cpy(g_help_text_p, (S8 *)GetString(STR_ID_DCD_V30_HELP_INFO1));
    mmi_ucs2cat(g_help_text_p, (S8 *)GetString(STR_ID_DCD_V30_HELP_INFO2));
    mmi_ucs2cat(g_help_text_p, (S8 *)GetString(STR_ID_DCD_V30_HELP_INFO3));
    mmi_ucs2cat(g_help_text_p, (S8 *)GetString(STR_ID_DCD_V30_HELP_INFO4));
    mmi_ucs2cat(g_help_text_p, (S8 *)GetString(STR_ID_DCD_V30_HELP_INFO5));
    mmi_ucs2cat(g_help_text_p, (S8 *)GetString(STR_ID_DCD_V30_HELP_INFO6));
    mmi_ucs2cat(g_help_text_p, (S8 *)GetString(STR_ID_DCD_V30_HELP_INFO7));

    str_buf = GetString(STR_ID_DCD_MORE);
    find_text_p =  g_help_text_p + ucs2_text_len - (mmi_ucs2strlen(str_buf) + 1) * 2;

    hilite_item[0].str_addr = (S8*) find_text_p;
    hilite_item[0].length = mmi_ucs2strlen(str_buf);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory228Screen(
        STR_GLOBAL_HELP,
        NULL,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) g_help_text_p,
        text_size,
        hilite_item,
        1,
        mmi_dcd_help_info_callback,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_dcd_enter_help_info_page, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_exit_help_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_exit_help_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_help_text_p)
    {
        applib_mem_screen_free(g_help_text_p);
    }
    g_help_text_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_enter_help_info_page
 * DESCRIPTION
 *  dcd launch wap browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_enter_help_info_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dcd_set_url_type(MMI_DCD_URL_HELP);
    mmi_dcd_launch_wap_browser();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_help_info_callback
 * DESCRIPTION
 *  store the highlighted string item index
 * PARAMETERS
 *  selected_idx        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_help_info_callback(S32 selected_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_pen_down;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    is_pen_down = wgui_multi_line_get_pen_down_flag();
    if (!is_pen_down)
    {
        return;
    }
    wgui_multi_line_clear_pen_down_flag();

    mmi_dcd_set_url_type(MMI_DCD_URL_HELP);
    mmi_dcd_launch_wap_browser();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_network_info_init_inline_item
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_network_info_init_inline_item(
                cui_inline_set_item_struct *p_inline_item,
                U16 item_id,
                U32 item_flag,
                U16 image_id,
                void *item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_inline_item->item_id = item_id;
    p_inline_item->item_flag = item_flag;
    p_inline_item->image_id = image_id;
    p_inline_item->item_data = item_data;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_network_info
 * DESCRIPTION
 *  story list highlight handler
 * PARAMETERS
 *  void
 *  index(?)        [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_network_info()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 inline_item_index = 0;
    MMI_ID inline_cui_id = GRP_ID_INVALID;
    HDCD_Agent agent_handle = NULL;
    BRBOOL LastSyncRes;

    WCHAR  *last_update_result_str;
    CHAR last_update_time_str[20];
    CHAR next_update_time_str[20];
    CHAR update_error_reason_str[20];
    applib_time_struct last_update_time = {0};
    applib_time_struct next_update_time = {0};
    BRULONG local_sec = 0, ttl_sec = 0;
    EDCD_SYNC_ERROR_STATUS error_code = eDCD_SYNC_SUCCESS;
    static WCHAR lut_ucs2[25];
    static WCHAR nut_ucs2[25];
    static WCHAR uer_ucs2[40];
    WCHAR * sync_code_str = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_group_create(GRP_ID_DCD,
							GRP_ID_DCD_NETWORK_INFO,
							mmi_dcd_entry_network_info_inline_cui_proc,
							NULL);
	mmi_frm_group_enter(GRP_ID_DCD_NETWORK_INFO, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_dcd_network_info_init_inline_item(
        &network_info_inline_item[inline_item_index++],
        DCD_NETWORK_INFO_LAST_UPDATE_RESULT_CAPTAIN,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        0,
        (void*)&last_update_result_caption);


    mmi_dcd_network_info_init_inline_item(
        &network_info_inline_item[inline_item_index++],
        DCD_NETWORK_INFO_LAST_UPDATE_RESULT,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,
        0,
        &pre_update_result_display_only);
    
    mmi_dcd_network_info_init_inline_item(
        &network_info_inline_item[inline_item_index++],
        DCD_NETWORK_INFO_LAST_UPDATE_TIME_CAPTAIN,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        0,
        (void*)&pre_update_time_caption);

    mmi_dcd_network_info_init_inline_item(
        &network_info_inline_item[inline_item_index++],
        DCD_NETWORK_INFO_LAST_UPDATE_TIME,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,
        0,
        &pre_update_time_display_only);
    
    mmi_dcd_network_info_init_inline_item(
        &network_info_inline_item[inline_item_index++],
        DCD_NETWORK_INFO_NEXT_UPDATE_TIME_CAPTAIN,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        0,
        (void*)&next_update_time_caption);

    mmi_dcd_network_info_init_inline_item(
        &network_info_inline_item[inline_item_index++],
        DCD_NETWORK_INFO_NEXT_UPDATE_TIME,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,
        0,
        &next_update_time_display_only);

    mmi_dcd_network_info_init_inline_item(
        &network_info_inline_item[inline_item_index++],
        DCD_NETWORK_INFO_UPDATE_ERROR_REASON_CAPTAIN,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        0,
        (void*)&update_error_reason_caption);

    error_reason_multi_rdonly_struct.height_of_item = 2;
    mmi_dcd_network_info_init_inline_item(
        &network_info_inline_item[inline_item_index++],
        DCD_NETWORK_INFO_UPDATE_ERROR_REASON,
        CUI_INLINE_ITEM_TYPE_MULTILINE_RD_ONLY,
        0,
        &error_reason_multi_rdonly_struct);
    
    network_info_inline_struct.items_count = inline_item_index;
    network_info_inline_struct.title = STR_ID_DCD_NETWORK_INFO;
    network_info_inline_struct.title_icon = NULL;
    network_info_inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE;
    network_info_inline_struct.softkey = &network_info_softkey_struct;
    network_info_inline_struct.items = network_info_inline_item;

    inline_cui_id = cui_inline_create(GRP_ID_DCD_NETWORK_INFO, &network_info_inline_struct);
    if (inline_cui_id != GRP_ID_INVALID)
    {
        agent_handle = mmi_dcd_get_agent_handle();
        LastSyncRes = emDCDAgent_GetLastSyncPkgResult(agent_handle);
        if (LastSyncRes == BRTRUE)
        {
            last_update_result_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_SUCCESS);
        }
        else
        {
            last_update_result_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_FAILURE);
        }
        cui_inline_set_value(
            inline_cui_id,
            DCD_NETWORK_INFO_LAST_UPDATE_RESULT,
            (void*)last_update_result_str);

        memset(lut_ucs2, 0, sizeof(lut_ucs2));
        memset(last_update_time_str, 0, sizeof(last_update_time_str));
        local_sec = emDCDAgent_GetLastSyncPkgTime(agent_handle);
        applib_dt_utc_sec_2_mytime(local_sec, &last_update_time, MMI_FALSE);
        sprintf(
            last_update_time_str, 
            "%04d/%02d/%02d %02d:%02d %s", 
            last_update_time.nYear, 
            last_update_time.nMonth, 
            last_update_time.nDay, 
            (last_update_time.nHour > 12) ? (last_update_time.nHour - 12) : last_update_time.nHour, 
            last_update_time.nMin,
            (last_update_time.nHour >= 12) ? "pm" : "am");
        app_asc_str_to_ucs2_str((kal_int8 *)lut_ucs2, (kal_int8 *) last_update_time_str);
        
        cui_inline_set_value(
            inline_cui_id,
            DCD_NETWORK_INFO_LAST_UPDATE_TIME,
            (void*)lut_ucs2);

        memset(nut_ucs2, 0, sizeof(nut_ucs2));
        memset(next_update_time_str, 0, sizeof(next_update_time_str));
        if (LastSyncRes != BRTRUE)
        {
            mmi_wcscpy(nut_ucs2, (WCHAR *)get_string(STR_ID_DCD_UNKNOWN));
        }
        else
        {
            ttl_sec = emDCDAgent_GetSyncPkgTTL(agent_handle) / 1000;
            local_sec += ttl_sec;
            applib_dt_utc_sec_2_mytime(local_sec, &next_update_time, MMI_FALSE);
            sprintf(
                next_update_time_str, 
                "%04d/%02d/%02d %02d:%02d %s", 
                next_update_time.nYear, 
                next_update_time.nMonth, 
                next_update_time.nDay, 
                (next_update_time.nHour > 12) ? (next_update_time.nHour - 12) : next_update_time.nHour, 
                next_update_time.nMin,
                (next_update_time.nHour >= 12) ? "pm" : "am");
            app_asc_str_to_ucs2_str((kal_int8 *)nut_ucs2, (kal_int8 *) next_update_time_str);
                
        }
        cui_inline_set_value(
            inline_cui_id,
            DCD_NETWORK_INFO_NEXT_UPDATE_TIME,
            (void*)nut_ucs2);

        memset(uer_ucs2, 0, sizeof(uer_ucs2));
        memset(update_error_reason_str, 0, sizeof(update_error_reason_str));
        error_code = emDCDAgent_GetLastSyncPkgErrorCode(agent_handle);
        sprintf(update_error_reason_str, "%d", error_code);
        app_asc_str_to_ucs2_str((kal_int8 *)uer_ucs2, (kal_int8 *) update_error_reason_str);
        mmi_wcscat(uer_ucs2, L"\n");
        sync_code_str = mmi_dcd_get_sync_code_info_str(error_code);
        mmi_wcscat(uer_ucs2, sync_code_str);
        cui_inline_set_value(
            inline_cui_id,
            DCD_NETWORK_INFO_UPDATE_ERROR_REASON,
            (void*)uer_ucs2);
        
        cui_inline_run(inline_cui_id);
    }
    else
    {
        mmi_frm_group_close(GRP_ID_DCD_NETWORK_INFO);
    }
}

static WCHAR * mmi_dcd_get_sync_code_info_str(EDCD_SYNC_ERROR_STATUS error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR * sync_code_str = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (error_code)
    {
        case eDCD_SYNC_SUCCESS:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_SUCCESS);
            break;
            
        case eDCD_SYNC_ERR_SYNTEX:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_SYNTEX);
            break;

        case eDCD_SYNC_ERR_OTHER_CERTIFY:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_OTHER_CERTIFY);
            break;

        case eDCD_SYNC_ERR_NOT_FOUND_RESOURCE:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_NOT_FOUND_RESOURCE);
            break;

        case eDCD_SYNC_ERR_INTERNAL_SYSTEM:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_INTERNAL_SYSTEM);
            break;

        case eDCD_SYNC_ERR_TRAFFIC_CONTROL:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_TRAFFIC_CONTROL);
            break;

        case eDCD_SYNC_ERR_NOT_SUPPORT_TERMINAL:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_NOT_SUPPORT_TERMINAL);
            break;

        case eDCD_SYNC_ERR_NOT_REGISTER_USER:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_NOT_REGISTER_USER);
            break;

        case eDCD_SYNC_ERR_VERSION_NUMBER:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_VERSION_NUMBER);
            break;

        case eDCD_SYNC_ERR_BEFORE_BUY_CITY:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_BEFORE_BUY_CITY);
            break;

        case eDCD_SYNC_ERR_NOT_EXIST_CITY:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_NOT_EXIST_CITY);
            break;

        case eDCD_SYNC_ERR_VERSION_EXPIRED:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_VERSION_EXPIRED);
            break;

        case eDCD_SYNC_ERR_FULL_BUY_CITY_COUNT:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_FULL_BUY_CITY_COUNT);
            break;
            
        case eDCD_SYNC_ERR_LATEST_VERSION:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_LATEST_VERSION);
            break;

        case eDCD_SYNC_ERR_FAIL_REMOVE_CITY:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_FAIL_REMOVE_CITY);
            break;
            
        case eDCD_SYNC_ERR_SYNCPKG_PARSING:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_FAIL_SYNCPKG_PARSING);
            break;

        case eDCD_SYNC_ERR_NO_SYNCPKG:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_FAIL_NO_SYNCPKG);
            break;

        case eDCD_SYNC_ERR_CONTENT_PARSING:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_FAIL_CONTENT_PARSING);
            break;

        case eDCD_SYNC_ERR_NO_CONTENT:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_FAIL_NO_CONTENT);
            break;

        case eDCD_SYNC_ERR_STORAGE_FULL:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_FAIL_STORAGE_FULL);
            break;

        case eDCD_SYNC_ERR_NETWORK_DISABLE:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_FAIL_NETWORK_DISABLE);
            break;

        case eDCD_SYNC_ERR_NETWORK_BUSY:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_FAIL_NETWORK_BUSY);
            break;

        case eDCD_SYNC_ERR_SERVER_TIME_OUT:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_ERR_FAIL_SERVER_TIME_OUT);
            break;
            
        default:
            sync_code_str = (WCHAR *)get_string(STR_ID_DCD_SYNC_CODE_SUCCESS);
            break;
        
    }

    return sync_code_str;
}

static mmi_ret mmi_dcd_entry_network_info_inline_cui_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        mmi_frm_group_close(GRP_ID_DCD_NETWORK_INFO);
        break;
            
    case EVT_ID_CUI_INLINE_SET_KEY:
        break;

    case EVT_ID_CUI_INLINE_ABORT:
            mmi_frm_group_close(GRP_ID_DCD_NETWORK_INFO);
        break;
            
    case EVT_ID_CUI_INLINE_GROUP_DEINIT:
        break; 
        
    default:
        break;
    }
	
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_switch_off_prompt
 * DESCRIPTION
 *  mmi_dcd_entry_switch_off_prompt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_switch_off_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_dcd_switch_off_confirm_callback;
    mmi_confirm_display((WCHAR *)get_string(STR_ID_DCD_SWITCH_OFF_ASK), MMI_EVENT_QUERY, &arg);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_switch_off_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_dcd_switch_off_confirm_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {        
        mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
        
        switch (alert->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_dcd_entry_switch_off_prompt_ext();
                break;

            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_switch_off_prompt_ext
 * DESCRIPTION
 *  mmi_dcd_entry_switch_off_prompt_ext
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_switch_off_prompt_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_SWITCH_OFF_PROMPT, NULL, mmi_dcd_entry_switch_off_prompt_ext, MMI_FRM_FULL_SCRN))
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    
    ShowCategory21Screen(
        STR_GLOBAL_SETTINGS,
        NULL,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        STR_ID_DCD_PURCHASE_EXIST,
        gui_buffer);
   
    SetLeftSoftkeyFunction(mmi_dcd_switch_off_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_switch_off_done
 * DESCRIPTION
 *  mmi_dcd_switch_off_done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_switch_off_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dcd_setting_struct * dcd_setting_p = NULL;
    MMI_BOOL pre_switch, curr_switch;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dcd_setting_p = mmi_dcd_get_setting_data();
    pre_switch = mmi_dcd_is_switch_on();
    dcd_setting_p->dcd_switch = MMI_FALSE;
    mmi_dcd_save_setting_data();
    curr_switch = mmi_dcd_is_switch_on();
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);

    if ((mmi_frm_group_is_present(GRP_ID_DCD))||(mmi_frm_group_is_present(GRP_ID_DCD_SYSTEM_SETTING)))
    {
        mmi_frm_group_close(GRP_ID_DCD);
    }
    if (pre_switch != curr_switch)
    {
        mmi_dcd_switch(MMI_FALSE);
    }
    mmi_dcd_set_current_idle_channel_index(0);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_wakeup_prompt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_wakeup_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_SWITCH_ON_PROMPT), MMI_EVENT_INFO, NULL);
}


void mmi_dcd_entry_channal_list_external(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dcd_setting_struct *dcd_setting_p = NULL;
    MMI_BOOL   dcd_available = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dcd_available = mmi_dcd_is_service_available();
    if (!dcd_available)
    {
        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), MMI_EVENT_FAILURE, NULL);
        return;
    }
    dcd_setting_p = mmi_dcd_get_setting_data();
    if (!dcd_setting_p->dcd_switch)
    {
        mmi_confirm_property_struct arg;
        mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
        arg.callback = (mmi_proc_func)mmi_dcd_switch_on_confirm_callback;
        mmi_confirm_display((WCHAR *)get_string(STR_ID_DCD_SWITCH_ON), MMI_EVENT_QUERY, &arg);        
    }
    else
    {
        mmi_dcd_entry_channel_list();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_switch_on_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_switch_on_confirm_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {        
        mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
        
        switch (alert->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_dcd_entry_channal_list_external_done();
                break;

            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_channal_list_external_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_channal_list_external_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dcd_setting_struct * dcd_setting_p = NULL;
    MMI_BOOL pre_switch, curr_switch;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dcd_setting_p = mmi_dcd_get_setting_data();
    pre_switch = mmi_dcd_is_switch_on();
    dcd_setting_p->dcd_switch = DCD_ENABLE_ON;
    mmi_dcd_save_setting_data();
    curr_switch = mmi_dcd_is_switch_on();
    if (pre_switch != curr_switch)
    {
        mmi_dcd_switch(MMI_TRUE);
    }
    do {
	mmi_popup_property_struct arg;
	mmi_popup_property_init(&arg);
	arg.callback = mmi_alert_normal_exit_helper;
	arg.user_tag = (void *)(mmi_dcd_entry_channel_list);
	mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, &arg);
	} while(0);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_switch
 * DESCRIPTION
 *  switch on or off in phone setup
 * PARAMETERS
 *  on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_switch(MMI_BOOL on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_DCD_SWITCH, on);
    {
        mmi_dcd_switch_to_sync(on);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_forward_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_forward_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Entry entry_handle = NULL;
    HDCD_Story story_handle = NULL;
    BRSTR title = NULL;
    BRSTR pagecontent = NULL;
    BRSTR content_buffer = NULL;
    WCHAR *ucs2_title = NULL;
    WCHAR *ucs2_sms = NULL;
    WCHAR *ucs2_pagecontent_p = NULL;
    S32 buff_size = 0, content_len = 0, max_sms_len = 0;
    S32 ucs2_title_len = 0, ucs2_content_len = 0;
    mmi_sms_write_msg_para_struct sms_write_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_FORWORD_SMS);
    
    /* check entry handle */
    agent_handle = mmi_dcd_get_agent_handle();
    entry_handle = mmi_dcd_get_current_entry(agent_handle);
    if (!entry_handle)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
        
        /* invalid handle, just popup and return */
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE, NULL);
        return;
    }
    
    /* init sms_write_struct */
    memset(&sms_write_struct, 0, sizeof(mmi_sms_write_msg_para_struct));

    /* init sms content buffer */
    max_sms_len = 2 * 67 * MMI_SMS_MAX_MSG_SEG + ENCODING_LENGTH;
    max_sms_len = (max_sms_len < 2 * 1024) ? max_sms_len : 2 * 1024;
    ucs2_sms = (WCHAR*)OslMalloc(max_sms_len);
    memset(ucs2_sms, 0, max_sms_len);

    /* title */
    title = emDCDAgent_GetEntryTitle(entry_handle);
    if (title)
    {
        ucs2_title = (WCHAR*)OslMalloc(MAX_DCD_STORY_TITLE_LEN * ENCODING_LENGTH);
        memset(ucs2_title, 0, MAX_DCD_STORY_TITLE_LEN * ENCODING_LENGTH);
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*)ucs2_title,
            (MAX_DCD_STORY_TITLE_LEN * ENCODING_LENGTH),
            (kal_uint8*)title);
        mmi_wcscat((WCHAR*)ucs2_sms, (WCHAR*)ucs2_title);
        mmi_wcscat((WCHAR*)ucs2_sms, L" ");
        OslMfree(ucs2_title);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
    }

    /* story */
    story_handle = mmi_dcd_get_current_story(entry_handle);
    if (story_handle)
    {
        /* page content */
        pagecontent = emDCDAgent_GetStoryPageContent(story_handle);
        if (pagecontent)
        {
            /* max 2K */
            buff_size = 2 * 1024;
            content_buffer = (BRSTR)OslMalloc(buff_size);
            memset(content_buffer, 0, buff_size);
            content_len = emDCDAgent_GetTextFromHTML(pagecontent, (char*)content_buffer, buff_size - 1);
            if (content_len > 0)
            {
                ucs2_pagecontent_p = (WCHAR*)OslMalloc(buff_size);
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*)ucs2_pagecontent_p,
                    (kal_int32)buff_size,
                    (kal_uint8*)content_buffer);
                ucs2_title_len = mmi_wcslen(ucs2_sms);
                ucs2_content_len = mmi_wcslen(ucs2_pagecontent_p);
                if (ucs2_title_len + ucs2_content_len > max_sms_len / ENCODING_LENGTH)
                {
                    mmi_wcsncat(
                        ucs2_sms, 
                        ucs2_pagecontent_p,
                        max_sms_len / ENCODING_LENGTH - ucs2_title_len - 4);
                    mmi_wcscat(ucs2_sms, L"...");
                }
                else
                {
                    mmi_wcscat(ucs2_sms, ucs2_pagecontent_p);
                }
                OslMfree(ucs2_pagecontent_p);
            }
            else
            {
                MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
            }
            OslMfree(content_buffer);
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
        }
    }

    sms_write_struct.srcport = 0;
    sms_write_struct.desport = 0;
    sms_write_struct.flag = MMI_SMS_ENTRY_WRITE_REPLY;
    sms_write_struct.stringlength = mmi_wcslen(ucs2_sms);
    sms_write_struct.string = (S8*)ucs2_sms;
    sms_write_struct.filename = NULL;
    sms_write_struct.dcs = SMSAL_UCS2_DCS;
    sms_write_struct.dcs_class = 0;
    sms_write_struct.ascii_addr = NULL;
    mmi_sms_write_msg_lanch(0, &sms_write_struct);
    
    OslMfree(ucs2_sms);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_forward_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_forward_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Entry entry_handle = NULL;
    HDCD_Story story_handle = NULL;
    EDCD_AGENT_RESULT result = eDCD_ERR_UNKNOWN;
    BRSTR title = NULL;
    BRSTR pagecontent = NULL;
    BRSTR content_buffer = NULL;
    HDCD_Content content_handle = NULL;
    WCHAR *ucs2_title = NULL;
    WCHAR *ucs2_pagecontent_p = NULL;
    U8 utf8_path[SRV_FMGR_PATH_MAX_LEN + 1] = {0};
    S32 buff_size = 0, content_len = 0, content_count = 0;
    mmi_uc_entry_write_struct uc_data;
    S32 content_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_FORWORD_MMS);
    
    /* check entry handle */
    agent_handle = mmi_dcd_get_agent_handle();
    entry_handle = mmi_dcd_get_current_entry(agent_handle);
    if (!entry_handle)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
        
        /* invalid handle, just popup and return */
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE, NULL);
        return;
    }
    
    /* init mms_data */
    memset(&uc_data, 0x00, sizeof(mmi_uc_entry_write_struct));
    
    /* title */
    title = emDCDAgent_GetEntryTitle(entry_handle);
    if (title)
    {    
        ucs2_title = (WCHAR*)OslMalloc(MAX_DCD_STORY_TITLE_LEN * ENCODING_LENGTH);
        memset(ucs2_title, 0, MAX_DCD_STORY_TITLE_LEN * ENCODING_LENGTH);
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*)ucs2_title,
            (MAX_DCD_STORY_TITLE_LEN * ENCODING_LENGTH),
            (kal_uint8*)title);
        uc_data.subject = (char*)ucs2_title;
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
    }

    /* story */
    story_handle = mmi_dcd_get_current_story(entry_handle);
    if (story_handle)
    {
        /* page content */
        pagecontent = emDCDAgent_GetStoryPageContent(story_handle);
        if (pagecontent)
        {
            /* max 2K */
            buff_size = 2 * 1024;
            content_buffer = (BRSTR)OslMalloc(buff_size);
            memset(content_buffer, 0, buff_size);
            content_len = emDCDAgent_GetTextFromHTML(pagecontent, (char*)content_buffer, buff_size - 1);
            if (content_len > 0)
            {
                ucs2_pagecontent_p = (WCHAR*)OslMalloc(buff_size);
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*)ucs2_pagecontent_p,
                    (kal_int32)buff_size,
                    (kal_uint8*)content_buffer);
                uc_data.text_buffer = (S8*)ucs2_pagecontent_p;
            }
            else
            {
                MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
            }
            OslMfree(content_buffer);
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
        }

        /* picture, only support 1 picture */
        content_count = emDCDAgent_GetStoryContentCount(story_handle);
        memset(&g_multi_img_ctx, 0, sizeof(g_multi_img_ctx));
        //g_multi_img_ctx.img_count = content_count;
        for (content_index = 0; content_index < content_count; content_index++)
        {
            content_handle = emDCDAgent_GetStoryContentAt(story_handle, content_index);
            if (content_handle)
            {
                result = emDCDAgent_GetContentFullPath(content_handle, (BRSTR)utf8_path, SRV_FMGR_PATH_MAX_LEN);
                if (result == eDCD_SUCCESS)
                {
                    g_multi_img_ctx.multi_img_path[content_index] = (WCHAR*)OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);
                    memset(g_multi_img_ctx.multi_img_path[content_index], 0, (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);
                    mmi_chset_utf8_to_ucs2_string(
                        (kal_uint8*)g_multi_img_ctx.multi_img_path[content_index],
                        (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH,
                        (kal_uint8*)utf8_path);
                    g_multi_img_ctx.img_count++;
                }
                else
                {
                    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
                }
            }
            else
            {
                MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
            }
        }
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
    }


        uc_data.callback = NULL;
        uc_data.callback_para = NULL;
        uc_data.get_img_callback = mmi_dcd_get_multi_img_callback;
        uc_data.media_num = g_multi_img_ctx.img_count;
        uc_data.text_num = mmi_ucs2strlen(uc_data.text_buffer);
		uc_data.msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
        uc_data.info_type = MMI_UC_INFO_TYPE_MMS;

        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &uc_data);

    /* free ctrl buffer if needed */
    if (ucs2_title)
    {
        OslMfree(ucs2_title);
    }
    if (ucs2_pagecontent_p)
    {
        OslMfree(ucs2_pagecontent_p);
    }
}

void mmi_dcd_get_multi_img_callback(U16 index, WCHAR* file_path, MMI_BOOL need_continue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(need_continue && (index < g_multi_img_ctx.img_count))
    {
        if (g_multi_img_ctx.multi_img_path[index])
        {
            mmi_ucs2cpy((CHAR*)file_path, (CHAR*)g_multi_img_ctx.multi_img_path[index]);
            OslMfree(g_multi_img_ctx.multi_img_path[index]);
            g_multi_img_ctx.multi_img_path[index] = NULL;
        }
    }
    else
    {
        for (idx = 0; idx < g_multi_img_ctx.img_count; idx++)
        {
            if (g_multi_img_ctx.multi_img_path[idx])
            {
                OslMfree(g_multi_img_ctx.multi_img_path[idx]);
                g_multi_img_ctx.multi_img_path[idx] = NULL;
            }

        }
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_forward_email
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_EMAIL__
void mmi_dcd_entry_forward_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Entry entry_handle = NULL;
    HDCD_Story story_handle = NULL;
    EDCD_AGENT_RESULT result = eDCD_ERR_UNKNOWN;
    BRSTR title = NULL;
    BRSTR pagecontent = NULL;
    BRSTR content_buffer = NULL;
    HDCD_Content content_handle = NULL;
    WCHAR *ucs2_title = NULL;
    WCHAR *ucs2_pagecontent_p = NULL;
    WCHAR *ucs2_path_p = NULL;
    U8 utf8_path[SRV_FMGR_PATH_MAX_LEN + 1] = {0};
    S32 buff_size = 0, content_len = 0, content_count = 0;
    email_app_send_param_fill_enum  flag = EMAIL_NONE_FILL_FLAG;
    mmi_email_app_send_param_struct *email_param = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_FORWORD_EMAIL);
    
    /* check entry handle */
    agent_handle = mmi_dcd_get_agent_handle();
    entry_handle = mmi_dcd_get_current_entry(agent_handle);
    if (!entry_handle)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
        
        /* invalid handle, just popup and return */
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE, NULL);
        return;
    }
    
    /* init email_param */
    email_param = (mmi_email_app_send_param_struct*)OslMalloc(sizeof(mmi_email_app_send_param_struct));
    mmi_email_app_send_init_param_to_null(email_param);
    
    /* title*/
    title = emDCDAgent_GetEntryTitle(entry_handle);
    if (title)
    {
        ucs2_title = (WCHAR*)OslMalloc(MAX_DCD_STORY_TITLE_LEN * ENCODING_LENGTH);
        memset(ucs2_title, 0, MAX_DCD_STORY_TITLE_LEN * ENCODING_LENGTH);
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*)ucs2_title,
            (MAX_DCD_STORY_TITLE_LEN * ENCODING_LENGTH),
            (kal_uint8*)title);
        email_param->subj = (S8*)ucs2_title;
        flag |= EMAIL_SUBJ_FILL_FLAG;
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
    }
    
    /* story */
    story_handle = mmi_dcd_get_current_story(entry_handle);
    if (story_handle)
    {
        /* page content */
        pagecontent = emDCDAgent_GetStoryPageContent(story_handle);
        if (pagecontent)
        {
            /* max 2K */
            buff_size = 2 * 1024;
            content_buffer = (BRSTR)OslMalloc(buff_size);
            memset(content_buffer, 0, buff_size);
            content_len = emDCDAgent_GetTextFromHTML(pagecontent, (char*)content_buffer, buff_size - 1);
            if (content_len > 0)
            {
                ucs2_pagecontent_p = (WCHAR*)OslMalloc(buff_size);
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*)ucs2_pagecontent_p,
                    (kal_int32)buff_size,
                    (kal_uint8*)content_buffer);
                email_param->cont = (S8*)ucs2_pagecontent_p;
                flag |= EMAIL_CONT_FILL_FLAG;
            }
            else
            {
                MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
            }
            OslMfree(content_buffer);
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
        }

        /* picture, only support 1 picture */
        content_count = emDCDAgent_GetStoryContentCount(story_handle);
        if (content_count > 0)
        {
            content_handle = emDCDAgent_GetStoryContentAt(story_handle, 0);
            if (content_handle)
            {
                result = emDCDAgent_GetContentFullPath(content_handle, (BRSTR)utf8_path, SRV_FMGR_PATH_MAX_LEN);
                if (result == eDCD_SUCCESS)
                {
                    ucs2_path_p = (WCHAR*)OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);
                    mmi_chset_utf8_to_ucs2_string(
                        (kal_uint8*)ucs2_path_p,
                        (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH,
                        (kal_uint8*)utf8_path);
                    email_param->attch_file_path = (S8*)ucs2_path_p;
                    flag |= EMAIL_ATTCH_FILL_FLAG;
                }
                else
                {
                    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
                }
            }
            else
            {
                MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
            }
        }
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__);
    }

    /* send email */
    mmi_email_app_send(email_param, flag);
    
    /* free ctrl buffer if needed */
    if (ucs2_title)
    {
        OslMfree(ucs2_title);
    }
    if (ucs2_pagecontent_p)
    {
        OslMfree(ucs2_pagecontent_p);
    }
    if (ucs2_path_p)
    {
        OslMfree(ucs2_path_p);
    }
    if (email_param)
    {
        OslMfree(email_param);
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_settings_reset_confirm
 * DESCRIPTION
 * PARAMETERS  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_settings_reset_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do {
    mmi_confirm_property_struct arg;
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_dcd_setting_reset_confirm_callback;
    mmi_confirm_display((WCHAR *)get_string(STR_ID_DCD_RESTORE_FACTORY_ASK), MMI_EVENT_QUERY, &arg);
    } while(0);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_setting_reset_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_setting_reset_confirm_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {        
        mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
        
        switch (alert->result)
        {
            case MMI_ALERT_CNFM_YES:
                ShowCategory66Screen(
                    NULL,
                    NULL,
                    0,
                    0,
                    0,
                    0,
                    (U8*)GetString(STR_ID_DCD_RESETTING),
                    mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                    NULL);
                    
                mmi_dcd_settings_reset();
                break;

            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_settings_reset
 * DESCRIPTION
 * PARAMETERS  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_settings_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dcd_setting_struct* dcd_setting_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dcd_setting_p = mmi_dcd_get_setting_data();
    dcd_setting_p->dcd_conn_mode         = 0x01;
    dcd_setting_p->dcd_scroll_speed      = 0x00;
    dcd_setting_p->dcd_switch            = 0x01;
    dcd_setting_p->dcd_update_mode       = 0x00;
    
    mmi_dcd_save_setting_data();
    mmi_dcd_reset_to_sync();
    
    memset(&g_dcd_app_cntx, 0, sizeof(g_dcd_app_cntx));
    mmi_dcd_city_weather_image_free_ext();
    mmi_dcd_news_image_free_ext();
    
    mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_RESTORE_FACTORY_DONE), MMI_EVENT_SUCCESS, NULL);

    if (mmi_frm_group_is_present(GRP_ID_DCD))
    {
        mmi_frm_group_close(GRP_ID_DCD);
    }
    DeleteUptoScrID(IDLE_SCREEN_ID);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_set_url_type
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_set_url_type(U8 url_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (url_type)
    {
        case MMI_DCD_URL_ADD_CHAN:
            g_mmi_dcd_url_type = MMI_DCD_URL_ADD_CHAN;
            break;

        case MMI_DCD_URL_DEL_CHAN:
            g_mmi_dcd_url_type = MMI_DCD_URL_DEL_CHAN;
            break;

        case MMI_DCD_URL_HELP:
            g_mmi_dcd_url_type = MMI_DCD_URL_HELP;
            break;

        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_launch_wap_browser
 * DESCRIPTION
 *  dcd launch wap browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_launch_wap_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 * url = NULL;
    U8         url_ucs2[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_dcd_url_type == MMI_DCD_URL_ADD_CHAN)
    {
        url = (kal_int8 *)dcd_custom_get_url_add_channel();
    } 
    else if (g_mmi_dcd_url_type == MMI_DCD_URL_DEL_CHAN)
    {
        url = (kal_int8 *)dcd_custom_get_url_del_channel();
    }
    else if (g_mmi_dcd_url_type == MMI_DCD_URL_HELP)
    {
        url = (kal_int8 *)dcd_custom_get_url_help();
    }

    app_asc_str_to_ucs2_str((kal_int8 *)url_ucs2, url);
    wap_start_browser(WAP_BROWSER_GOTO_URL, url_ucs2);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_cug_name_edit
 * DESCRIPTION
 *  entry function for cug name edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_city_search_edit(CHAR * string, CHAR* label)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
    WCHAR city_name[MMI_DCD_MAX_CITY_NAME_LEN + 1] = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gid = cui_fseditor_create(GRP_ID_DCD);
    if (string)
    {
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) city_name,
            (MMI_DCD_MAX_CITY_NAME_LEN + 1) * ENCODING_LENGTH,
            (kal_uint8*) string);
        if (mmi_wcscmp(city_name, (WCHAR*)GetString(STR_ID_DCD_SEARCH_PROMPT)) == 0)
        {
            memset(city_name, 0, (MMI_DCD_MAX_CITY_NAME_LEN + 1) * ENCODING_LENGTH);
        }
    }
    cui_fseditor_set_text(gid, city_name, sizeof(city_name), MMI_DCD_MAX_CITY_NAME_LEN);
    cui_fseditor_set_title(gid, STR_GLOBAL_SEARCH, NULL);
    cui_fseditor_set_input_method(gid, IMM_INPUT_TYPE_SENTENCE, NULL, 0);
    cui_fseditor_run(gid);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_city_search_edit_done
 * DESCRIPTION
 *  mmi_dcd_entry_city_search_edit_done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_city_search_edit_done(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle;
    S32 ucs2_len = 0;
    CHAR *city_name_utf8 = NULL;
    WCHAR city_name[MMI_DCD_MAX_CITY_NAME_LEN + 1] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    agent_handle = mmi_dcd_get_agent_handle();
    ucs2_len = cui_fseditor_get_text(gid, city_name, (MMI_DCD_MAX_CITY_NAME_LEN + 1) * ENCODING_LENGTH);
    city_name_utf8 = (CHAR*)OslMalloc(ucs2_len * 3 + 1);
    mmi_chset_ucs2_to_utf8_string((kal_uint8*)city_name_utf8, ucs2_len * 3 + 1, (kal_uint8*)city_name);
    cui_fseditor_close(gid);
    mmi_dcd_show_pause(agent_handle);
    mmi_dcd_show_start(agent_handle, eERM_RETURN_FROM_OEM_EDIT, city_name_utf8);
    OslMfree(city_name_utf8);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_search_city
 * DESCRIPTION
 *  search the weather of the city
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_search_city(CHAR *city)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_syncing = MMI_FALSE;
    MMI_BOOL result = MMI_FALSE;
    CHAR *url_data = NULL;
    WCHAR ucs2_city[MMI_DCD_MAX_CITY_NAME_LEN + 1] = {0};
    MMI_BOOL city_valid = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ENTRY_SEARCH_CITY);

    /* check city valid or not */
    if (!city || strlen(city) == 0)
    {
        city_valid = MMI_FALSE;
    }
    else
    {
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*)ucs2_city,
            (MMI_DCD_MAX_CITY_NAME_LEN + 1) * ENCODING_LENGTH,
            (kal_uint8*)city);
        if (mmi_wcscmp(ucs2_city, (WCHAR*)GetString(STR_ID_DCD_SEARCH_PROMPT)) == 0)
        {
            city_valid = MMI_FALSE;
        }
    }

    /* if city invalid, popup and return */
    if (!city_valid)
    {
        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DCD_SEARCH_CITY_PROMPT), MMI_EVENT_FAILURE, NULL);
        return;
    }
    
    url_data = (CHAR*)OslMalloc(strlen(city) * 3 + 5 + 1);
    strcpy(url_data, "city=");
    mmi_dcd_url_encode(city, url_data + 5, strlen(city));

    result = mmi_dcd_user_to_sync(DCD_SYNC_REQ_TYPE_SEARCHCITY, url_data, &is_syncing);
    OslMfree(url_data);

    if (!result)
    {
        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
    }
    else if (is_syncing == MMI_TRUE)
    {
        mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_V30_BACKGROUND_SYNC_PROGRESS), MMI_EVENT_FAILURE, NULL);
    }
    else
    {
        mmi_dcd_entry_connect_sync();
        g_isSyncStopped = MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_url_encode
 * DESCRIPTION
 *  encode url
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_dcd_url_encode(CHAR *src, CHAR *dest, U32 src_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    CHAR *hexchars = "0123456789ABCDEF";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dest should be allocted */
    if (!src || !dest)
    {
        return MMI_FALSE;
    }
    
    for (i = 0; i < src_len; i++)
    {
        if (src[i] == '.' ||
            src[i] == '-' ||
            src[i] == '_' ||
            (src[i] >= '0' && src[i] <= '9') ||
            (src[i] >= 'a' && src[i] <= 'z') ||
            (src[i] >= 'A' && src[i] <= 'Z'))
         {
            *dest++ = src[i];
            continue;
         }
        else
        {
            *dest++ = '%';
            *dest++ = hexchars[(src[i] & 0xF0) >> 4];
            *dest++ = hexchars[src[i] & 0x0F];
        }
    }
    *dest = '\0';
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_agent_handle_ext
 * DESCRIPTION
 *  mmi_dcd_get_agent_handle_ext
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_dcd_get_agent_handle_ext()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent      agent_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    agent_handle = mmi_dcd_get_agent_handle();
    return (void*)agent_handle;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_channel_count_ext
 * DESCRIPTION
 *  mmi_dcd_get_channel_count_ext
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dcd_get_channel_count_ext(void* agent_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32             channel_cnt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    channel_cnt = emDCDAgent_GetChannelCount((HDCD_Agent)agent_handle);
    return channel_cnt;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_channel_count_ext
 * DESCRIPTION
 *  mmi_dcd_get_channel_count_ext
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_dcd_get_current_channel_handle_ext(void* agent_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Channel    channel_handle;
    S32 cur_idle_chan_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_idle_chan_index = mmi_dcd_get_current_idle_channel_index();
    channel_handle = emDCDAgent_GetChannelAt((HDCD_Agent)agent_handle, cur_idle_chan_index);
    return (void*)channel_handle;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_channel_block_count_ext
 * DESCRIPTION
 *  mmi_dcd_get_channel_block_count_ext
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dcd_get_channel_block_count_ext(void* channel_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    S32             block_cnt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    block_cnt = emDCDAgent_GetChannelBlockCount((HDCD_Channel)channel_handle);
    return block_cnt;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_channel_block_handle_ext
 * DESCRIPTION
 *  mmi_dcd_get_channel_block_handle_ext
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void * mmi_dcd_get_channel_block_handle_ext(void * channel_handle, S32 block_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Block      block_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    block_handle = emDCDAgent_GetChannelBlockAt((HDCD_Channel)channel_handle, block_index);
    return (void*)block_handle;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_block_entry_count_ext
 * DESCRIPTION
 *  mmi_dcd_get_block_entry_count_ext
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dcd_get_block_entry_count_ext(void* block_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32             entry_cnt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_cnt = emDCDAgent_GetBlockEntryCount((HDCD_Block)block_handle);
    return entry_cnt;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_block_entry_handle_ext
 * DESCRIPTION
 *  mmi_dcd_get_block_entry_handle_ext
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void * mmi_dcd_get_block_entry_handle_ext(void* block_handle, S32 entry_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Entry      entry_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_handle = emDCDAgent_GetBlockEntryAt((HDCD_Block) block_handle, entry_index);
    return (void*)entry_handle;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_channel_title_ext
 * DESCRIPTION
 *  get dcd channel title
 * PARAMETERS
 *  agent               [IN] dcd agent handle  
 *  index               [IN] channel index
 *  buf                 [IN] channel title buffer
 * RETURNS
 *  void
 *****************************************************************************/
WCHAR* mmi_dcd_get_channel_title_ext(void* channel_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8  *           title;
    static WCHAR    ucs_title[16];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    title = emDCDAgent_GetChannelTitle((HDCD_Channel)channel_handle);
    memset(ucs_title, 0, sizeof(ucs_title));
    mmi_chset_utf8_to_ucs2_string((kal_uint8 *)ucs_title, sizeof(ucs_title), (kal_uint8 *)title );
    return ucs_title;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_channel_title_list
 * DESCRIPTION
 *  get dcd channel title
 * PARAMETERS
 *  agent               [IN] dcd agent handle  
 *  index               [IN] channel index
 *  buf                 [IN] channel title buffer
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dcd_is_weather_channel(void* channel_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_CHANNEL_TYPE channel_type = eDCD_CHANNEL_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    channel_type = emDCDAgent_GetChannelType((HDCD_Channel)channel_handle);
    if (channel_type == eDCD_CHANNEL_WEATHER)
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
 *  mmi_dcd_get_channel_title_list
 * DESCRIPTION
 *  get dcd channel title
 * PARAMETERS
 *  agent               [IN] dcd agent handle  
 *  index               [IN] channel index
 *  buf                 [IN] channel title buffer
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_dcd_get_weather_channel_ext(void* agent_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Channel    channel_handle = NULL;
    S32             channel_cnt;
    S32             channel_index = 0;
    EDCD_CHANNEL_TYPE channel_type = eDCD_CHANNEL_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    channel_cnt = emDCDAgent_GetChannelCount((HDCD_Agent)agent_handle);

    for (channel_index = 0; channel_index < channel_cnt; channel_index++)
    {
        channel_handle = emDCDAgent_GetChannelAt((HDCD_Agent)agent_handle, channel_index);
        channel_type = emDCDAgent_GetChannelType(channel_handle);
        if (eDCD_CHANNEL_WEATHER == channel_type)
        {
            break;
        }
        else
        {
            channel_handle = NULL;
        }
    }

    return (void*)channel_handle;
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_default_city_ext
 * DESCRIPTION
 *  mmi_dcd_get_default_city_ext
 * PARAMETERS
 *  agent               [IN] dcd agent handle  
 *  index               [IN] channel index
 *  buf                 [IN] channel title buffer
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_dcd_get_default_city_ext(void* agent_handle, void* weather_channel_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *defalut_city_block_id = NULL;
    U8 default_city_index = 0;
    HDCD_Block default_city_handle = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    defalut_city_block_id = emDCDAgent_GetConfigDefaultUserCity(agent_handle);
    if (!defalut_city_block_id)
    {
        return NULL;
    }
    if (strlen(defalut_city_block_id))
    {
        default_city_index = emDCDAgent_GetChannelBlockIndex((HDCD_Channel)weather_channel_handle, defalut_city_block_id);
        default_city_handle = emDCDAgent_GetChannelBlockAt((HDCD_Channel)weather_channel_handle, default_city_index);
    }
    return (void*)default_city_handle;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_default_city_name_ext
 * DESCRIPTION
 *  mmi_dcd_get_default_city_name_ext
 * PARAMETERS
 *  agent               [IN] dcd agent handle  
 *  index               [IN] channel index
 *  buf                 [IN] channel title buffer
 * RETURNS
 *  void
 *****************************************************************************/
WCHAR *mmi_dcd_get_city_name_ext(void* city_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S8               city_name[(MMI_DCD_MAX_CTXT_ID_LEN + 1) * ENCODING_LENGTH];
    CHAR *           city_title = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    city_title = emDCDAgent_GetBlockTitle((HDCD_Block)city_handle);

    memset(city_name, 0, sizeof(city_name));
    mmi_chset_utf8_to_ucs2_string((kal_uint8*)city_name,
                                  sizeof(city_name),
                                 (kal_uint8*) city_title);
    return (WCHAR*)city_name;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_city_temperature_ext
 * DESCRIPTION
 *  mmi_dcd_get_city_temperature_ext
 * PARAMETERS
 *  agent               [IN] dcd agent handle  
 *  index               [IN] channel index
 *  buf                 [IN] channel title buffer
 * RETURNS
 *  void
 *****************************************************************************/
WCHAR *mmi_dcd_get_city_temperature_ext(void* city_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S8               city_temperature[(8 + 1) * ENCODING_LENGTH];
    CHAR *           temperature = NULL;
    HDCD_Entry       entry_handle = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_handle = emDCDAgent_GetBlockEntryAt((HDCD_Block)city_handle, 0);
    temperature = emDCDAgent_GetEntryTemperature(entry_handle);

    memset(city_temperature, 0, sizeof(city_temperature));
    mmi_chset_utf8_to_ucs2_string((kal_uint8*)city_temperature,
                                  sizeof(city_temperature),
                                 (kal_uint8*) temperature);
    return (WCHAR*)city_temperature;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_city_weather_image_ext
 * DESCRIPTION
 *  mmi_dcd_get_city_weather_image_ext
 * PARAMETERS
 *  agent               [IN] dcd agent handle  
 *  index               [IN] channel index
 *  buf                 [IN] channel title buffer
 * RETURNS
 *  void
 *****************************************************************************/
WCHAR* mmi_dcd_get_city_weather_image_ext(void* city_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Entry       entry_handle = NULL;
    HDCD_Content     content_handle = NULL;
    S8*              temp = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_handle = emDCDAgent_GetBlockEntryAt((HDCD_Block)city_handle, 0);    
    content_handle = emDCDAgent_GetEntryContentAt(entry_handle, 0);
    if (!g_weather_image_path)
    {
        g_weather_image_path = (WCHAR*)OslMalloc(sizeof(WCHAR)*(DCD_MAX_IMAGE_PATH_LEN + 1));
    }
    memset(g_weather_image_path, 0, sizeof(WCHAR)*(DCD_MAX_IMAGE_PATH_LEN + 1));
    
    temp = OslMalloc(SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1);
    memset(temp, 0, SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1);
    
    emDCDAgent_GetContentFullPath(content_handle, (BRSTR)temp, SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
    
    mmi_chset_utf8_to_ucs2_string(
        (kal_uint8*)g_weather_image_path,
        sizeof(WCHAR)*(DCD_MAX_IMAGE_PATH_LEN + 1),
        (kal_uint8*) temp);
        
    if (temp)
    {
        OslMfree(temp);
        temp = NULL;
    }
    return g_weather_image_path;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_city_weather_image_free_ext
 * DESCRIPTION
 *  mmi_dcd_city_weather_image_free_ext
 * PARAMETERS
 *  agent               [IN] dcd agent handle  
 *  index               [IN] channel index
 *  buf                 [IN] channel title buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_city_weather_image_free_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_weather_image_path)
    {
        OslMfree(g_weather_image_path);
        g_weather_image_path = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_news_image_ext
 * DESCRIPTION
 *  mmi_dcd_get_news_image_ext
 * PARAMETERS
 *  agent               [IN] dcd agent handle  
 *  index               [IN] channel index
 *  buf                 [IN] channel title buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_set_news_image_ext(void* channel_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Entry       new_unread_entry = NULL;
    HDCD_Content     content_handle = NULL;
    S8*              temp = NULL;
    EDCD_CHANNEL_TYPE channel_type = eDCD_CHANNEL_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    channel_type = emDCDAgent_GetChannelType((HDCD_Channel)channel_handle);
    if(channel_type == eDCD_CHANNEL_WEATHER)
    {
        if (g_news_image_path)
        {
            OslMfree(g_news_image_path);
            g_news_image_path = NULL;
        }
        return;
    }
    
    new_unread_entry = mmi_dcd_get_newest_unread_entry((HDCD_Channel)channel_handle);
    if (new_unread_entry)
    {
        content_handle = emDCDAgent_GetEntryContentAt(new_unread_entry, 0);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_NO_NEW_UNREAD_ENTRY);
        content_handle = emDCDAgent_GetChannelContentAt((HDCD_Channel)channel_handle, 0);
    }

    if (!content_handle)
    {
        return;
    }

    if(!g_news_image_path)
    {
        g_news_image_path = (WCHAR*)OslMalloc(sizeof(WCHAR)*(DCD_MAX_IMAGE_PATH_LEN + 1));
    }
    ASSERT(g_news_image_path);
    memset(g_news_image_path, 0, sizeof(WCHAR)*(DCD_MAX_IMAGE_PATH_LEN + 1));
    
    temp = OslMalloc(SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1);
    ASSERT(temp);
    memset(temp, 0, SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
    
    emDCDAgent_GetContentFullPath(content_handle, (BRSTR)temp, SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
    mmi_chset_utf8_to_ucs2_string(
        (kal_uint8*)g_news_image_path,
        sizeof(WCHAR)*(DCD_MAX_IMAGE_PATH_LEN + 1),
        (kal_uint8*) temp);
    
    if (temp)
    {
        OslMfree(temp);
        temp = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_news_image_ext
 * DESCRIPTION
 *  mmi_dcd_get_news_image_ext
 * PARAMETERS
 *  agent               [IN] dcd agent handle  
 *  index               [IN] channel index
 *  buf                 [IN] channel title buffer
 * RETURNS
 *  void
 *****************************************************************************/
WCHAR* mmi_dcd_get_news_image_ext()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_news_image_path;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_news_image_free_ext
 * DESCRIPTION
 *  mmi_dcd_news_image_free_ext
 * PARAMETERS
 *  agent               [IN] dcd agent handle  
 *  index               [IN] channel index
 *  buf                 [IN] channel title buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_news_image_free_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_news_image_path)
    {
        OslMfree(g_news_image_path);
        g_news_image_path = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_news_image_ext
 * DESCRIPTION
 *  mmi_dcd_get_news_image_ext
 * PARAMETERS
 *  agent               [IN] dcd agent handle  
 *  index               [IN] channel index
 *  buf                 [IN] channel title buffer
 * RETURNS
 *  void
 *****************************************************************************/
HDCD_Entry mmi_dcd_get_newest_unread_entry(HDCD_Channel channel_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Entry       entry_handle = NULL;
    U8               block_count = 0;    
    U8               block_index = 0;
    HDCD_Block       block_handle = NULL;
    U8               block_entry_cnt = 0;
    U8               entry_index = 0;
    MMI_BOOL         is_readed = MMI_FALSE;
    MMI_BOOL         is_new = MMI_FALSE;
    CHAR*            entry_issue_time = NULL;
    CHAR*            newest_issue_time = NULL;
    HDCD_Entry       newest_entry_handle = NULL;
    CHAR*            block_type = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newest_issue_time = (CHAR*)OslMalloc(sizeof(CHAR) * (DCD_MAX_ISSUE_TIME_LEN + 1));
    memset(newest_issue_time, 0, sizeof(CHAR) * (DCD_MAX_ISSUE_TIME_LEN + 1));
    block_count = emDCDAgent_GetChannelBlockCount(channel_handle);
    for(block_index = 0; block_index < block_count; block_index++)
    {
        block_handle = emDCDAgent_GetChannelBlockAt(channel_handle, block_index);
        block_type = emDCDAgent_GetBlockType(block_handle);
        if (!strcmp(block_type, "1"))
        {
            continue;
        }
        block_entry_cnt = emDCDAgent_GetBlockEntryCount(block_handle);
        for(entry_index = 0; entry_index < block_entry_cnt; entry_index++)
        {
            entry_handle = emDCDAgent_GetBlockEntryAt(block_handle, entry_index);
            emDCDAgent_IsReadedEntry(entry_handle, (BRBOOL *)&is_readed);
            
            if (!is_readed)
            {
                emDCDAgent_IsNewEntry(entry_handle,(BRBOOL *)&is_new);                
                if (is_new)
                {
                    entry_issue_time = emDCDAgent_GetEntryIssuedTime(entry_handle);
                    if (strlen(entry_issue_time) > strlen(newest_issue_time))
                    {                        
                        strcpy(newest_issue_time, entry_issue_time);
                        newest_entry_handle = entry_handle;
                        continue;
                    }
                    if (strlen(entry_issue_time) < strlen(newest_issue_time))
                    {
                        continue;
                    }
                    if (strlen(entry_issue_time) == strlen(newest_issue_time))
                    {
                        if (strcmp(entry_issue_time, newest_issue_time) > 0)
                        {
                            strcpy(newest_issue_time, entry_issue_time);
                            newest_entry_handle = entry_handle;
                        }
                    }
                }
            }
        }
    }
    if (newest_issue_time)
    {
        OslMfree(newest_issue_time);
        newest_issue_time = NULL;
    }
    return (void*)newest_entry_handle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_channel_title_list
 * DESCRIPTION
 *  get dcd channel title
 * PARAMETERS
 *  entry_handle               [IN] entry handle  
 * RETURNS
 *  void
 *****************************************************************************/
WCHAR* mmi_dcd_get_entry_title(void* entry_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8  *           title;
    static WCHAR    ucs_title[16];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    title = emDCDAgent_GetEntryTitle((HDCD_Entry) entry_handle);
    memset(ucs_title, 0, sizeof(ucs_title));
    mmi_chset_utf8_to_ucs2_string((kal_uint8 *)ucs_title, sizeof(ucs_title), (kal_uint8 *)title );
    return ucs_title;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_current_idle_channel_index
 * DESCRIPTION
 *  mmi_dcd_get_current_idle_channel_index
 * PARAMETERS

 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dcd_get_current_idle_channel_index()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_GET_CURRENT_IDLE_CHANNEL_INDEX, g_cur_idle_chan_index);
    return g_cur_idle_chan_index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_set_current_idle_channel_index
 * DESCRIPTION
 *  mmi_dcd_set_current_idle_channel_index
 * PARAMETERS

 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_set_current_idle_channel_index(S32 current_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cur_idle_chan_index = current_index;
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_SET_CURRENT_IDLE_CHANNEL_INDEX, g_cur_idle_chan_index);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_channel_detail_from_idle
 * DESCRIPTION
 *  mmi_dcd_entry_channel_detail_from_idle
 * PARAMETERS

 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_channel_detail_from_idle()
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Channel cur_chan_handle = NULL;
    S32          channel_cnt;
    MMI_BOOL    preset_only = MMI_FALSE;
    EDCD_CHANNEL_TYPE channel_type = eDCD_CHANNEL_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    agent_handle = mmi_dcd_get_agent_handle();

    mmi_dcd_create_screen_group();

    g_dcd_app_viewer.normal_entry = MMI_TRUE;
    g_dcd_app_viewer.normal_exit = MMI_FALSE;

    channel_cnt = emDCDAgent_GetChannelCount(agent_handle);
    if (channel_cnt <= 0)
    {
        channel_cnt = emDCDAgent_GetPreChannelCount(agent_handle);
        cur_chan_handle = emDCDAgent_GetPreChannelAt(agent_handle, 0);
        preset_only = MMI_TRUE;
    }
    else
    {
        cur_chan_handle = (HDCD_Channel)mmi_dcd_get_current_channel_handle_ext((void*)agent_handle);
    }

    if (cur_chan_handle == NULL)
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, NULL);
        return;
    }
    g_dcd_app_cntx.channel_handle = cur_chan_handle;
    strcpy(g_dcd_app_cntx.channel_id, emDCDAgent_GetChannelID(g_dcd_app_cntx.channel_handle));
    g_isEntryFromIdle = MMI_TRUE;
    if (preset_only)
    {
        mmi_dcd_entry_preset_channel_detail();
    }
    else if (1 == channel_cnt)
    {
        channel_type = emDCDAgent_GetChannelType(cur_chan_handle);
        if (eDCD_CHANNEL_WEATHER == channel_type)
        {
            cur_chan_handle = emDCDAgent_GetPreChannelAt(agent_handle, 0);
            g_dcd_app_cntx.channel_handle = cur_chan_handle;
            strcpy(g_dcd_app_cntx.channel_id, emDCDAgent_GetChannelID(g_dcd_app_cntx.channel_handle));
            mmi_dcd_entry_preset_channel_detail();
        }
        else
        {
            mmi_dcd_entry_channel_detail();
        }
    }
    else
    {
        mmi_dcd_entry_channel_detail();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_weather_channel_from_idle
 * DESCRIPTION
 *  mmi_dcd_entry_weather_channel_from_idle
 * PARAMETERS

 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_weather_channel_from_idle()
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent     agent_handle = NULL;
    HDCD_Channel   channel_handle = NULL;
    S32            channel_index = 0;
    S32            channel_count = 0;
    EDCD_CHANNEL_TYPE channel_type = eDCD_CHANNEL_NONE;
    MMI_BOOL       preset_only = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    agent_handle = mmi_dcd_get_agent_handle();
    
    channel_count = emDCDAgent_GetChannelCount(agent_handle);

    if (channel_count <= 0)
    {
        channel_count = emDCDAgent_GetPreChannelCount(agent_handle);
        channel_handle = emDCDAgent_GetPreChannelAt(agent_handle, 0);
        preset_only = MMI_TRUE;
    }
    else
    {
        for (channel_index = 0; channel_index < channel_count; channel_index++)
        {
            channel_handle = emDCDAgent_GetChannelAt(agent_handle, channel_index);
            channel_type = emDCDAgent_GetChannelType(channel_handle);
            if (eDCD_CHANNEL_WEATHER == channel_type)
            {
                break;
            }
            else
            {
                channel_handle = NULL;
            }
        }
    }
    if (channel_handle)
    {

        mmi_dcd_create_screen_group();

        g_dcd_app_viewer.normal_entry = MMI_TRUE;
        g_dcd_app_viewer.normal_exit = MMI_FALSE;

        g_dcd_app_cntx.channel_handle = channel_handle;
        strcpy(g_dcd_app_cntx.channel_id, emDCDAgent_GetChannelID(g_dcd_app_cntx.channel_handle));

        g_isEntryFromIdle = MMI_TRUE;

        if (preset_only)
        {
            mmi_dcd_entry_preset_channel_detail();
        }
        else
        {
            mmi_dcd_entry_channel_detail();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_pre_entry_manual_update
 * DESCRIPTION
 *  mmi_dcd_pre_entry_manual_update
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_pre_entry_manual_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dcd_setting_struct* dcd_setting_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dcd_setting_p = mmi_dcd_get_setting_data();

    if (dcd_setting_p->dcd_conn_mode == DCD_CONN_MODE_MANUAL)
    {
        if (srv_nw_info_is_roaming(MMI_SIM1))
        {
            mmi_dcd_entry_roaming_maunul_mode_prompt();
        }
        else
        {
            mmi_dcd_entry_manual_update_prompt();
        }
    }
    else if ((dcd_setting_p->dcd_conn_mode == DCD_CONN_MODE_HOME) && (srv_nw_info_is_roaming(MMI_SIM1)))
    {
        mmi_dcd_entry_manual_update_roaming_prompt();
    }
    else
    {
        mmi_dcd_entry_manual_update();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_manual_update_prompt
 * DESCRIPTION
 *  mmi_dcd_entry_manual_update_prompt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_manual_update_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_MANUAL_UPDATE_PROMPT, NULL, mmi_dcd_entry_manual_update_prompt, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory21Screen(
        STR_ID_DCD_REFRESH,
        NULL,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        STR_ID_DCD_MANUAL_UPDATE_PROMPT,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_dcd_entry_manual_update, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dcd_abort_manual_update, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_manual_update_roaming_prompt
 * DESCRIPTION
 *  mmi_dcd_entry_manual_update_roaming_prompt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_manual_update_roaming_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_MANUAL_UPDATE_ROAMING_PROMPT, NULL, mmi_dcd_entry_manual_update_roaming_prompt, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    ShowCategory21Screen(
        STR_ID_DCD_REFRESH,
        NULL,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        STR_ID_DCD_MAN_UPDATE_WHEN_ROAMING_PROMPT,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_dcd_entry_manual_update, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_manual_update_roaming_prompt
 * DESCRIPTION
 *  mmi_dcd_entry_manual_update_roaming_prompt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_roaming_maunul_mode_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_MANUAL_UPDATE_ROAMING_PROMPT, NULL, mmi_dcd_entry_manual_update_roaming_prompt, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    ShowCategory21Screen(
        STR_ID_DCD_REFRESH,
        NULL,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        STR_ID_DCD_MAN_UPDATE_WHEN_ROAMING_PROMPT,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_dcd_entry_manual_update_prompt, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_abort_manual_update
 * DESCRIPTION
 *  mmi_dcd_abort_manual_update
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_abort_manual_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_MANUAL_UPDATE_ROAMING_PROMPT);
    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_manual_update
 * DESCRIPTION
 *  mmi_dcd_entry_manual_update
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_manual_update()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    MMI_BOOL is_syncing = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result = mmi_dcd_user_to_sync(DCD_SYNC_REQ_TYPE_MAN, NULL, &is_syncing);
    if (!result)
    {
        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
    }
    else if (is_syncing == MMI_TRUE)
    {
        mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_V30_BACKGROUND_SYNC_PROGRESS), MMI_EVENT_FAILURE, NULL);
    }
    else
    {
        mmi_dcd_entry_connect_sync();
        g_isSyncStopped = MMI_FALSE;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_pre_entry_manual_update
 * DESCRIPTION
 *  mmi_dcd_pre_entry_manual_update
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_get_entry_content_complete(MMI_BOOL pkg_complete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_GET_ENTRY_CONTENT_COMPLETE, pkg_complete);
    if (pkg_complete)
    {
        if (!g_gettingNextPage)
        {
            g_onlyPkgSync = MMI_TRUE;
            mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS);
            g_isSyncStopped = MMI_FALSE;

            if (g_item_move_req_data_ptr)
            {
                strcpy(g_dcd_app_cntx.block_id, g_item_move_req_data_ptr->block_id);
                strcpy(g_dcd_app_cntx.entry_id, g_item_move_req_data_ptr->entry_id);
                g_dcd_app_cntx.PageOrder = g_item_move_req_data_ptr->PageOrder;
                OslMfree(g_item_move_req_data_ptr);
                g_item_move_req_data_ptr = NULL;
            }
            if (g_dcd_app_cntx.view_mode == eDCD_VIEW_STORY)
            {
                mmi_dcd_get_entry_content_refresh();
            }
            else
            {
                g_dcd_app_viewer.normal_entry = MMI_TRUE;
                g_dcd_app_viewer.normal_exit = MMI_FALSE;
                mmi_dcd_entry_story_viewer();
            }
            mmi_dcd_story_content_request();
            if (!g_GettingStoryContent)
            {
                mmi_dcd_entry_get_next_story_page();
            }
        }
        else
        {
            g_gettingNextPage = MMI_FALSE;
            if (g_isSyncStopped == MMI_FALSE) 
            {
                //mmi_dcd_stop_sync();
                g_isSyncStopped = MMI_TRUE;
            }
        }
    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_DCD_STORY_VIEWER)
        {
            if (g_dcd_app_cntx.view_mode == eDCD_VIEW_STORY)
            {
                mmi_dcd_get_entry_content_refresh();
            }
        }
        else
        {
            g_contentNeedUpdate = MMI_TRUE;
        }
        g_isSyncStopped = MMI_TRUE;
        g_onlyPkgSync = MMI_FALSE;
        g_GettingStoryContent = MMI_FALSE;
        mmi_dcd_entry_get_next_story_page();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_entry_content_refresh
 * DESCRIPTION
 *  mmi_dcd_get_entry_content_refresh
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_get_entry_content_refresh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Handle  agent_handle = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_GET_ENTRY_REFRESH);
    agent_handle = mmi_dcd_get_agent_handle();
    mmi_dcd_show_end(agent_handle);    
    emDCDAgent_SetStoryViewerID(agent_handle, g_dcd_app_cntx.channel_id, g_dcd_app_cntx.block_id, g_dcd_app_cntx.entry_id, g_dcd_app_cntx.PageOrder);
    mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_STORY);
    mmi_dcd_show_start(agent_handle, eERM_RETURN_FROM_NORMAL, NULL);
    g_contentNeedUpdate = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_background_list_complete
 * DESCRIPTION
 *  mmi_dcd_get_background_list_complete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_get_background_list_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_GET_BACKGROUND_LIST_COMPLETE);

    g_isSyncStopped = MMI_TRUE;
    if ((mmi_frm_scrn_get_active_id() == SCR_ID_DCD_UPDATE_PROGRESS) || mmi_frm_scrn_is_present(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS);
    }

    if (g_dcd_app_cntx.view_mode == eDCD_VIEW_BACKGROUND_LIST)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_DCD_BACKGROUND_LIST)
        {
            agent_handle = mmi_dcd_get_agent_handle();
            mmi_dcd_show_end(agent_handle);
            emDCDAgent_SetStoryViewerID(agent_handle, g_dcd_app_cntx.channel_id, g_dcd_app_cntx.block_id, NULL, g_background_list_page_index);
            mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_BACKGROUND_LIST);
            mmi_dcd_show_start(agent_handle, eERM_RETURN_FROM_NORMAL, NULL);
        }
        else
        {
            g_contentNeedUpdate = MMI_TRUE;
        }
    }
    else
    {
        g_dcd_app_viewer.normal_entry = MMI_TRUE;
        g_dcd_app_viewer.normal_exit = MMI_FALSE;
        mmi_dcd_entry_background_list();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_city_list_complete
 * DESCRIPTION
 *  mmi_dcd_get_city_list_complete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_get_city_list_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_GET_CITY_LIST_COMPLETE, g_city_list_page_index);

    if ((mmi_frm_scrn_get_active_id() == SCR_ID_DCD_UPDATE_PROGRESS) || mmi_frm_scrn_is_present(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS);
    }

    g_isSyncStopped = MMI_TRUE;

    if (g_dcd_app_cntx.view_mode == eDCD_VIEW_CITY_LIST)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_DCD_ADD_CITY)
        {
            agent_handle = mmi_dcd_get_agent_handle();
            mmi_dcd_show_end(agent_handle);
            emDCDAgent_SetStoryViewerID(agent_handle, NULL, NULL, NULL, g_city_list_page_index);
            mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_CITY_LIST);
            mmi_dcd_show_start(agent_handle, eERM_RETURN_FROM_NORMAL, NULL);
        }
        else
        {
            g_contentNeedUpdate = MMI_TRUE;
        }
    }
    else
    {
        g_dcd_app_viewer.normal_entry = MMI_TRUE;
        g_dcd_app_viewer.normal_exit = MMI_FALSE;
        mmi_dcd_entry_city_list();
    }  
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_search_city_complete
 * DESCRIPTION
 *  mmi_dcd_search_city_complete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_search_city_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_SEARCH_CITY_COMPLETE);
    g_isSyncStopped = MMI_TRUE;
    if ((mmi_frm_scrn_get_active_id() == SCR_ID_DCD_UPDATE_PROGRESS) || mmi_frm_scrn_is_present(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS);
    }

    mmi_dcd_entry_add_city_confirm();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_add_city_confirm
 * DESCRIPTION
 *  mmi_dcd_entry_add_city_confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_add_city_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    HDCD_Content content_handle = NULL;
    //CHAR * content_id = NULL;
    S8* temp;
    U8 *gui_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(GRP_ID_DCD, SCR_ID_DCD_ADD_CITY_CONFIRM,
        mmi_dcd_exit_add_city_confirm, mmi_dcd_entry_add_city_confirm, MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    
    agent_handle = mmi_dcd_get_agent_handle();
    content_handle = emDCDAgent_GetSearchContent(agent_handle);

    temp = OslMalloc(SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1);
    memset(temp, 0, (SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1));
    if(!g_searchCityImgpath)
    {
        g_searchCityImgpath = OslMalloc((SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
    }
    memset(g_searchCityImgpath, 0, (SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
    emDCDAgent_GetContentFullPath(content_handle, (BRSTR)temp, SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
    mmi_chset_utf8_to_ucs2_string(
        (kal_uint8*)g_searchCityImgpath,
        (SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
        (kal_uint8*) temp);
    
    if (temp)
    {
        OslMfree(temp);
        temp = NULL;
    }

    g_cityWeatherSummary = OslMalloc((MAX_DCD_WEATHER_SUMMARY_LEN + 1) * ENCODING_LENGTH);
    memset(g_cityWeatherSummary, 0, (MAX_DCD_WEATHER_SUMMARY_LEN + 1) * ENCODING_LENGTH);
    temp = (S8*)emDCDAgent_GetSearchSummary(agent_handle);
    if (temp)
    {
        mmi_chset_utf8_to_ucs2_string(
        (kal_uint8*)g_cityWeatherSummary,
        (MAX_DCD_WEATHER_SUMMARY_LEN + 1) * ENCODING_LENGTH,
        (kal_uint8*) temp);
    }

    wgui_cat9004_op01_show(
        get_string(STR_ID_DCD_ADD_TO_CITY_LIST),
        0,
        get_string(STR_GLOBAL_CANCEL),
        0,
        g_cityWeatherSummary,
        g_searchCityImgpath,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_dcd_add_search_city_to_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

static void mmi_dcd_exit_add_city_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_searchCityImgpath)
    {
        OslMfree(g_searchCityImgpath);
        g_searchCityImgpath = NULL;
    }

    if (g_cityWeatherSummary)
    {
        OslMfree(g_cityWeatherSummary);
        g_cityWeatherSummary = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_add_city_to_list
 * DESCRIPTION
 *  mmi_dcd_add_city_to_list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_add_search_city_to_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    MMI_BOOL  is_syncing = MMI_FALSE;
    MMI_BOOL  result = MMI_FALSE;
    CHAR url[MMI_DCD_MAX_URL_LEN];
    CHAR city_code[MMI_DCD_MAX_CITY_CODE_LEN + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_ADD_CITY_CONFIRM);
    
    {
        agent_handle = mmi_dcd_get_agent_handle();
        strcpy(city_code, emDCDAgent_GetSearchCityCode(agent_handle));
        memset(url, 0, sizeof(url));
        sprintf(url, "citycode=%s", city_code);    
        
        result = mmi_dcd_user_to_sync(DCD_SYNC_REQ_TYPE_ADDWEATHERCITY, url, &is_syncing);
        if (!result)
        {
            mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
        }
        else if (is_syncing == MMI_TRUE)
        {
            mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_V30_BACKGROUND_SYNC_PROGRESS), MMI_EVENT_FAILURE, NULL);
        }
        else
        {
            mmi_dcd_entry_connect_sync();
            g_isSyncStopped = MMI_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_add_city_complete
 * DESCRIPTION
 *  mmi_dcd_add_city_complete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_add_city_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ADD_CITY_COMPLETE);
    g_isSyncStopped = MMI_TRUE;
    if ((mmi_frm_scrn_get_active_id() == SCR_ID_DCD_UPDATE_PROGRESS) || mmi_frm_scrn_is_present(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS);
    }
	mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
    g_CityCntChanged = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_refresh_channel_detail
 * DESCRIPTION
 *  mmi_dcd_refresh_channel_detail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_refresh_channel_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    HDCD_Agent agent_handle = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_REFRESH_CHANNEL_DETAIL);
    if (g_dcd_app_cntx.view_mode == eDCD_VIEW_CHANNEL_DETAIL)
    {
        agent_handle = mmi_dcd_get_agent_handle();
        mmi_dcd_show_end(agent_handle);
        emDCDAgent_SetStoryViewerID(agent_handle, g_dcd_app_cntx.channel_id, NULL, NULL, 0);
        mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_CHANNEL_DETAIL);
        mmi_dcd_show_start(agent_handle, eERM_RETURN_FROM_NORMAL, NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_refresh_channel_detail
 * DESCRIPTION
 *  mmi_dcd_refresh_channel_detail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_refresh_weather_city(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    HDCD_Agent agent_handle = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_REFRESH_WEATHER_CITY);
    if (g_dcd_app_cntx.view_mode == eDCD_VIEW_WEATHER)
    {
        agent_handle = mmi_dcd_get_agent_handle();
        mmi_dcd_show_end(agent_handle);
        emDCDAgent_SetStoryViewerID(agent_handle, g_dcd_app_cntx.channel_id, g_dcd_app_cntx.block_id, NULL, 0);
        mmi_dcd_set_view_mode(agent_handle, eDCD_VIEW_WEATHER);
        mmi_dcd_show_start(agent_handle, eERM_RETURN_FROM_NORMAL, NULL);
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_delete_city_complete
 * DESCRIPTION
 *  mmi_dcd_delete_city_complete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_delete_city_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    HDCD_Agent agent_handle = NULL;
    S32 channel_index = -1;
    HDCD_Channel channel_handle = NULL;
    HDCD_Block new_default_city_handle = NULL;
    CHAR*  defalut_city_id = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_DELETE_CITY_COMPLETE);
    g_isSyncStopped = MMI_TRUE;
    g_isCityDeleted = MMI_TRUE;
    g_CityCntChanged = MMI_TRUE;

    if (g_DefaultCityDeleted)
    {
        agent_handle = mmi_dcd_get_agent_handle();
        channel_index = emDCDAgent_GetChannelIndex(agent_handle, g_dcd_app_cntx.channel_id);
        channel_handle = emDCDAgent_GetChannelAt(agent_handle, channel_index);
        if (0 < emDCDAgent_GetChannelBlockCount(channel_handle))
        {
            kal_wap_trace(MOD_MMI_CONN_APP, TRACE_INFO, "[DCD][APP] set first city as default city");
            new_default_city_handle = emDCDAgent_GetChannelBlockAt(channel_handle, 0);
            defalut_city_id = emDCDAgent_GetBlockID(new_default_city_handle);
            emDCDAgent_SetConfigDefaultUserCity(agent_handle, defalut_city_id);
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__); 
        }
        g_DefaultCityDeleted = MMI_FALSE;
    }
    
    if ((mmi_frm_scrn_get_active_id() == SCR_ID_DCD_UPDATE_PROGRESS) || mmi_frm_scrn_is_present(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS);
    }
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_manual_update_complete
 * DESCRIPTION
 *  mmi_dcd_manual_update_complete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_manual_update_complete(MMI_BOOL pkg_complete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    HDCD_Agent agent_handle = NULL;
    HDCD_Channel channel_handle = NULL;
    S32          block_count = -1;
    HDCD_Block   block_handle = NULL;
    CHAR*        city_id = NULL;
    S32          block_index = 0;
    CHAR *       default_city_id = NULL;
    MMI_BOOL     default_city_exist = MMI_FALSE;
    HDCD_Block   default_city_handle = NULL;
    EDCD_AGENT_RESULT check_result  = eDCD_ERR_UNKNOWN;
    HDCD_Entry   entry_handle = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_MANUAL_UPDATE_COMPLETE, pkg_complete);
    
    if (pkg_complete)
    {
        agent_handle = mmi_dcd_get_agent_handle();
        mmi_dcd_show_end(agent_handle);
        emDCDAgent_DestroyAllHandle();

        if (g_dcd_app_cntx.view_mode == eDCD_VIEW_STORY)
        {
            entry_handle = mmi_dcd_get_current_entry(agent_handle);
            check_result = emDCDAgent_IsValidHandle(entry_handle);
            if (check_result != eDCD_SUCCESS)
            {
                g_contentNeedUpdate = MMI_TRUE;
            }
        }

        g_onlyPkgSync = MMI_TRUE;
        if ((mmi_frm_scrn_get_active_id() == SCR_ID_DCD_UPDATE_PROGRESS) || mmi_frm_scrn_is_present(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS, MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS);
        }

        //emDCDAgent_DestroyAllHandle();

        agent_handle = mmi_dcd_get_agent_handle();
        
        g_isSyncStopped = MMI_FALSE;
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);   

        mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_MANUAL_UPDATE_PROMPT);
        mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_MANUAL_UPDATE_ROAMING_PROMPT);
        
        mmi_dcd_set_current_idle_channel_index(0);

        default_city_id = mmi_dcd_get_default_city_id(agent_handle);
        channel_handle = (HDCD_Channel)mmi_dcd_get_weather_channel_ext((void*)agent_handle);
        if (channel_handle)
        {
            block_count = emDCDAgent_GetChannelBlockCount(channel_handle);
        }
        if (block_count > 0)
        {
            if (!default_city_id)
            {
                default_city_handle = emDCDAgent_GetChannelBlockAt(channel_handle, 0);
                default_city_id = emDCDAgent_GetBlockID(default_city_handle);
                emDCDAgent_SetConfigDefaultUserCity(agent_handle, default_city_id);
                //g_DefaultCityChanged = MMI_TRUE;
            }
            else
            {
                for (block_index = 0; block_index < block_count; block_index++)
                {
                    block_handle = emDCDAgent_GetChannelBlockAt(channel_handle, block_index);
                    city_id = emDCDAgent_GetBlockID(block_handle);
                    if (!strcmp(default_city_id, city_id))
                    {
                        default_city_exist = MMI_TRUE;
                        break;
                    }
                }
                if (!default_city_exist)
                {
                    default_city_handle = emDCDAgent_GetChannelBlockAt(channel_handle, 0);
                    default_city_id = emDCDAgent_GetBlockID(default_city_handle);
                    emDCDAgent_SetConfigDefaultUserCity(agent_handle, default_city_id);
                }
                //g_DefaultCityChanged = MMI_TRUE;
            }
        }
    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_DCD_CHANNEL_LIST)
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_REDRAW_FIXED_LIST);
            redraw_fixed_list();
        }
        g_onlyPkgSync = MMI_FALSE;
        g_isSyncStopped = MMI_TRUE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_manual_update_complete
 * DESCRIPTION
 *  mmi_dcd_manual_update_complete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_main_update_complete(MMI_BOOL pkg_complete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    HDCD_Agent agent_handle = NULL;
    HDCD_Channel channel_handle = NULL;
    S32          block_count = -1;
    HDCD_Block   block_handle = NULL;
    CHAR*        city_id = NULL;
    HDCD_Channel curr_idle_chan = NULL;
    MMI_ID       active_screen = GRP_ID_INVALID;
    S32          block_index = 0;
    CHAR *       default_city_id = NULL;
    MMI_BOOL     default_city_exist = MMI_FALSE;
    HDCD_Block   default_city_handle = NULL;
    HDCD_Entry   entry_handle = NULL;
    EDCD_AGENT_RESULT  result = eDCD_SUCCESS;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_MAIN_UPDATE_COMPLETE, pkg_complete);

    //emDCDAgent_DestroyAllHandle();
    
    active_screen = mmi_frm_scrn_get_active_id();
    agent_handle = mmi_dcd_get_agent_handle();
    if (pkg_complete)
    {
        if ((g_dcd_app_cntx.view_mode != eDCD_VIEW_STORY) && (g_dcd_app_cntx.view_mode != eDCD_VIEW_SAVEDSTORY))
        {
            mmi_dcd_show_end(agent_handle);
        }
        emDCDAgent_DestroyAllHandle();
        
        g_onlyPkgSync = MMI_TRUE;
        
        if ((active_screen == SCR_ID_DCD_UPDATE_PROGRESS) || mmi_frm_scrn_is_present(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS, MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS);
        }
        g_isSyncStopped = MMI_FALSE;
        if ((active_screen == SCR_ID_DCD_CHANNEL_LIST) ||
            (active_screen == SCR_ID_DCD_CHANNEL_DETAIL) ||
            (active_screen == SCR_ID_DCD_BACKGROUND_LIST) ||
            (active_screen == SCR_ID_DCD_ADD_CITY))
        {
            mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_UPDATE), MMI_EVENT_SUCCESS, NULL);   
        }

        if (g_dcd_app_cntx.view_mode == eDCD_VIEW_STORY)
        {
            entry_handle = mmi_dcd_get_current_entry(agent_handle);
            result = emDCDAgent_IsValidHandle(entry_handle);
            kal_wap_trace(MOD_MMI_CONN_APP, TRACE_INFO, "[DCD][APP] entry handle check is %d", result);
        }

        mmi_dcd_set_current_idle_channel_index(0);

        default_city_id = mmi_dcd_get_default_city_id(agent_handle);
        channel_handle = (HDCD_Channel)mmi_dcd_get_weather_channel_ext((void*)agent_handle);
        if (channel_handle)
        {
            block_count = emDCDAgent_GetChannelBlockCount(channel_handle);
        }
        if (block_count > 0)
        {
            if (!default_city_id)
            {
                default_city_handle = emDCDAgent_GetChannelBlockAt(channel_handle, 0);
                default_city_id = emDCDAgent_GetBlockID(default_city_handle);
                emDCDAgent_SetConfigDefaultUserCity(agent_handle, default_city_id);
                //g_DefaultCityChanged = MMI_TRUE;
            }
            else
            {
                for (block_index = 0; block_index < block_count; block_index++)
                {
                    block_handle = emDCDAgent_GetChannelBlockAt(channel_handle, block_index);
                    city_id = emDCDAgent_GetBlockID(block_handle);
                    if (!strcmp(default_city_id, city_id))
                    {
                        default_city_exist = MMI_TRUE;
                        break;
                    }
                }
                if (!default_city_exist)
                {
                    default_city_handle = emDCDAgent_GetChannelBlockAt(channel_handle, 0);
                    default_city_id = emDCDAgent_GetBlockID(default_city_handle);
                    emDCDAgent_SetConfigDefaultUserCity(agent_handle, default_city_id);
                }
                //g_DefaultCityChanged = MMI_TRUE;
            }
        }
        vadp_p2v_hs_update_dcd_news_content();
        vadp_p2v_hs_update_dcd_whether_area();
    }
    else
    {
        if (active_screen == SCR_ID_DCD_CHANNEL_LIST)
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_REDRAW_FIXED_LIST);
            redraw_fixed_list();
        }
        else if (active_screen == SCR_ID_DCD_CHANNEL_DETAIL)
        {
            mmi_dcd_refresh_channel_detail();
        }
        else if (active_screen == SCR_ID_DCD_CITY_WEATHER_DETAIL)
        {
            mmi_dcd_refresh_weather_city();
        }
        g_isSyncStopped = MMI_TRUE;
        g_onlyPkgSync = MMI_FALSE;
        curr_idle_chan = (HDCD_Channel)mmi_dcd_get_current_channel_handle_ext((void*)agent_handle);
        mmi_dcd_set_news_image_ext((void *)curr_idle_chan);
        vadp_p2v_hs_update_dcd_news_img();
        vadp_p2v_hs_update_dcd_whether_area();
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_sync_fail
 * DESCRIPTION
 *  mmi_dcd_sync_fail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_sync_fail(mmi_dcd_sync_req_type_enum sync_type, mmi_dcd_event_enum error_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    mmi_confirm_property_struct arg;
    WCHAR * error_str = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_SYNC_FAIL);
    g_isSyncStopped = MMI_TRUE;
    g_onlyPkgSync = MMI_FALSE;
    g_gettingNextPage = MMI_FALSE;
    g_GettingStoryContent = MMI_FALSE;
    g_DefaultCityDeleted = MMI_FALSE;
    if ((mmi_frm_scrn_get_active_id() == SCR_ID_DCD_UPDATE_PROGRESS) || mmi_frm_scrn_is_present(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS);
    }
    if(sync_type == DCD_SYNC_REQ_TYPE_MAN)
    {
        mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
        arg.callback = (mmi_proc_func)mmi_dcd_manual_update_retry_confirm_callback;
        mmi_confirm_display((WCHAR *)get_string(STR_ID_DCD_MANUAL_UPDATE_FAIL_RETRY_ASK), MMI_EVENT_QUERY, &arg);
    }
    else
    {
        switch (error_evt)
        {
            case DCD_EVT_ERR_NOT_FOUND_RESOURCE:
                error_str = (WCHAR*)GetString(STR_ID_DCD_RESOURCE_NOT_FOUND);
                break;

            case DCD_EVT_ERR_SYNTEX:
                error_str = (WCHAR*)GetString(STR_ID_DCD_SYNC_CODE_ERR_SYNTEX);
                break;
                
            case DCD_EVT_ERR_OTHER_CERTIFY:
                error_str = (WCHAR*)GetString(STR_ID_DCD_SYNC_CODE_ERR_OTHER_CERTIFY);
                break;
                
            case DCD_EVT_ERR_INTERNAL_SYSTEM:
                error_str = (WCHAR*)GetString(STR_ID_DCD_SYNC_CODE_ERR_INTERNAL_SYSTEM);
                break;
                
            case DCD_EVT_ERR_TRAFFIC_CONTROL:
                error_str = (WCHAR*)GetString(STR_ID_DCD_SYNC_CODE_ERR_TRAFFIC_CONTROL);
                break;
                
            case DCD_EVT_ERR_NOT_SUPPORT_TERMINAL:
                error_str = (WCHAR*)GetString(STR_ID_DCD_SYNC_CODE_ERR_NOT_SUPPORT_TERMINAL);
                break;
            case DCD_EVT_ERR_NOT_REGISTER_USER:
                error_str = (WCHAR*)GetString(STR_ID_DCD_SYNC_CODE_ERR_NOT_REGISTER_USER);
                break;
            case DCD_EVT_ERR_VERSION_NUMBER:
                error_str = (WCHAR*)GetString(STR_ID_DCD_SYNC_CODE_ERR_VERSION_NUMBER);
                break;
            case DCD_EVT_ERR_VERSION_EXPIRED:
                error_str = (WCHAR*)GetString(STR_ID_DCD_SYNC_CODE_ERR_VERSION_EXPIRED);
                break;
            case DCD_EVT_ERR_LATEST_VERSION:
                error_str = (WCHAR*)GetString(STR_ID_DCD_SYNC_CODE_ERR_LATEST_VERSION);
                break;
                
            case DCD_EVT_ERR_SYNCPKG_PARSING:
                error_str = (WCHAR*)GetString(STR_ID_DCD_SYNC_CODE_ERR_FAIL_SYNCPKG_PARSING);
                break;
            case DCD_EVT_ERR_NO_SYNCPKG:
                error_str = (WCHAR*)GetString(STR_ID_DCD_SYNC_CODE_ERR_FAIL_NO_SYNCPKG);
                break;
            case DCD_EVT_ERR_CONTENT_PARSING:
                error_str = (WCHAR*)GetString(STR_ID_DCD_SYNC_CODE_ERR_FAIL_CONTENT_PARSING);
                break;
            case DCD_EVT_ERR_NO_CONTENT:
                error_str = (WCHAR*)GetString(STR_ID_DCD_SYNC_CODE_ERR_FAIL_NO_CONTENT);
                break;
            case DCD_EVT_ERR_NETWORK_DISABLE:
                error_str = (WCHAR*)GetString(STR_ID_DCD_SYNC_CODE_ERR_FAIL_NETWORK_DISABLE);
                break;
            case DCD_EVT_ERR_NETWORK_BUSY:
                error_str = (WCHAR*)GetString(STR_ID_DCD_SYNC_CODE_ERR_FAIL_NETWORK_BUSY);
                break;
            case DCD_EVT_ERR_CONNECT_TIME_OUT:
                error_str = (WCHAR*)GetString(STR_ID_DCD_SYNC_CODE_ERR_FAIL_SERVER_TIME_OUT);                
                break;
            case DCD_EVT_ERR_FAIL_REMOVE_CITY:
                error_str = (WCHAR*)GetString(STR_ID_DCD_SYNC_CODE_ERR_FAIL_REMOVE_CITY);                
                break;
            case DCD_EVT_ERR_BEFORE_BUY_CITY:
                error_str = (WCHAR*)GetString(STR_ID_DCD_CITY_ALREADY_BUY);
                break;
            case DCD_EVT_ERR_NOT_EXIST_CITY:
                error_str = (WCHAR*)GetString(STR_ID_DCD_CITY_NOT_EXIT);
                break;

            case DCD_EVT_ERR_FULL_BUY_CITY_COUNT:
                error_str = (WCHAR*)GetString(STR_ID_DCD_CITY_COUNT_FULL);
                break;

            case DCD_EVT_ERR_DOWNLOAD_SYNCPKG:
            case DCD_EVT_ERR_DOWNLOAD_CONTENT:
            case DCD_EVT_ERR_DOWNLOAD_APPPKG:
            case DCD_EVT_ERR_SYNC_FAIL:
            default:
                error_str = (WCHAR*)GetString(STR_GLOBAL_ERROR);
                break;
                
        }
        mmi_popup_display(error_str, MMI_EVENT_FAILURE, NULL);       
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_add_city_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_manual_update_retry_confirm_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {        
        mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
        
        switch (alert->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_dcd_entry_manual_update();
                break;

            case MMI_ALERT_CNFM_CANCEL:
            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_MANUAL_UPDATE_PROMPT);
                mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_MANUAL_UPDATE_ROAMING_PROMPT);
                mmi_frm_scrn_close_active_id();

                /* if user cancel retry, srv need to update ttl sync */
                mmi_dcd_user_sync_fail_abort();
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_add_city_selected_query
 * DESCRIPTION
 *  mmi_dcd_entry_add_city_selected_query
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_add_city_selected_query(CHAR * city_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!g_selectCityCode)
    {
        g_selectCityCode = (U8 *)OslMalloc((MMI_DCD_MAX_CTXT_ID_LEN + 1));
    }
    memset(g_selectCityCode, 0, (MMI_DCD_MAX_CTXT_ID_LEN + 1));

    strcpy((CHAR*)g_selectCityCode, city_code);    
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ADD_CITY_SELECTED_QUERY, g_selectCityCode);

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_dcd_add_city_selected_confirm_callback;
    mmi_confirm_display((WCHAR *)get_string(STR_ID_DCD_ADD_THE_CITY_ASK), MMI_EVENT_QUERY, &arg);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_add_city_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_add_city_selected_confirm_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {        
        mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
        
        switch (alert->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_dcd_add_city_selected_to_list();
                break;

            case MMI_ALERT_CNFM_NO:
                if (g_selectCityCode)
                {
                    OslMfree(g_selectCityCode);
                    g_selectCityCode = NULL;
                }
                mmi_frm_scrn_close_active_id();
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_add_city_selected_to_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_add_city_selected_to_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  is_syncing = MMI_FALSE;
    MMI_BOOL  result = MMI_FALSE;
    CHAR url[MMI_DCD_MAX_URL_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_ADD_CITY_SELECTED_TO_LIST);
    memset(url, 0, sizeof(url));
    sprintf(url, "citycode=%s", g_selectCityCode);
    
    result = mmi_dcd_user_to_sync(DCD_SYNC_REQ_TYPE_ADDWEATHERCITY, url, &is_syncing);

    if (g_selectCityCode)
    {
        OslMfree(g_selectCityCode);
        g_selectCityCode = NULL;
    }
    
    if (!result)
    {
        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
    }
    else if (is_syncing == MMI_TRUE)
    {
        mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_V30_BACKGROUND_SYNC_PROGRESS), MMI_EVENT_FAILURE, NULL);
    }
    else
    {
        mmi_dcd_entry_connect_sync();
        g_isSyncStopped = MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_add_channel_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_add_channel_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    S32 channel_cnt = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    agent_handle = mmi_dcd_get_agent_handle();
    channel_cnt = emDCDAgent_GetChannelCount(agent_handle);
    if (channel_cnt >= MMI_DCD_MAX_CHANNEL_COUNT)
    {
        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DCD_CHANNEL_COUNT_FULL), MMI_EVENT_FAILURE, NULL);
    }
    else
    {
        mmi_dcd_set_url_type(MMI_DCD_URL_ADD_CHAN);
        mmi_dcd_launch_wap_browser();
    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_manual_update_storage_full
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_manual_update_storage_full(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS);
    g_onlyPkgSync = MMI_FALSE;
    mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DCD_STORAGE_FULL), MMI_EVENT_FAILURE, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_sync_insufficient_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_sync_insufficient_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    EDCD_AGENT_RESULT ret = eDCD_ERR_UNKNOWN;
	mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(GRP_ID_DCD, SCR_ID_DCD_UPDATE_PROGRESS);
    g_onlyPkgSync = MMI_FALSE;
    g_isSyncStopped = MMI_TRUE;
    g_gettingNextPage = MMI_FALSE;
    g_GettingStoryContent = MMI_FALSE;
    
    agent_handle = mmi_dcd_get_agent_handle();
    
    ret = emDCDAgent_Pause(agent_handle, BRFALSE);
    if (ret == eDCD_SUCCESS)
    {
        g_screen_id = mmi_frm_scrn_get_active_id();
        mmi_dcd_set_agent_show_state(MMI_DCD_AGENT_SHOW_PAUSE);
    	mmi_popup_property_init(&arg);
    	arg.callback = mmi_dcd_insufficient_memory_popup_exit;
        mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_INSUFFICIENT_MEMORY), MMI_EVENT_FAILURE, &arg);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_COMMON_FAIL, __LINE__); 
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_insufficient_memory_popup_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_dcd_insufficient_memory_popup_exit(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {        
        mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
        
        switch (alert->result)
        {
            case MMI_POPUP_NORMAL_EXIT:

                    if ((SCR_ID_DCD_CHANNEL_DETAIL == g_screen_id) ||
                        (SCR_ID_DCD_BACKGROUND_LIST == g_screen_id) ||
                        (SCR_ID_DCD_STORY_VIEWER == g_screen_id) ||
                        (SCR_ID_DCD_CITY_WEATHER_DETAIL == g_screen_id) ||
                        (SCR_ID_DCD_ADD_CITY == g_screen_id) ||
                        (SCR_ID_DCD_SAVE_STORY_VIEWER == g_screen_id))
                    {
                        agent_handle = mmi_dcd_get_agent_handle();
                        mmi_dcd_show_end(agent_handle);
                        mmi_frm_scrn_close(GRP_ID_DCD, g_screen_id);
                    }
                    g_screen_id = GRP_ID_INVALID;
                //mmi_frm_scrn_close_active_id();
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_channel_list_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_get_channel_list_status(S32 * channel_count, MMI_BOOL *preset_only)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    S32        channel_cnt = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    agent_handle = mmi_dcd_get_agent_handle();
    channel_cnt = emDCDAgent_GetChannelCount(agent_handle);
    if (channel_cnt <= 0)
    {
        *preset_only = MMI_TRUE;
    }
    else
    {
        *preset_only = MMI_FALSE;
    }
    *channel_count = channel_cnt; 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_is_switch_on_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dcd_is_switch_on_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL dcd_on = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dcd_on = mmi_dcd_is_switch_on();
    return dcd_on;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_city_block_focus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_get_city_block_focus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Agent agent_handle = NULL;
    CHAR a_szChannelID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    CHAR a_szBlockID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    CHAR a_szEntryID[MMI_DCD_MAX_CTXT_ID_LEN + 1];
    BRINT  a_nPageOrder = 0;
    S32 channel_index = -1;
    HDCD_Channel channel_handle = NULL;
    HDCD_Block   block_handle = NULL;
    CHAR *       block_id_focus = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_V30_APP_GET_FOCUS_CITY);
    
    agent_handle = mmi_dcd_get_agent_handle();
    memset(a_szChannelID, 0, sizeof(a_szChannelID));
    memset(a_szBlockID, 0, sizeof(a_szBlockID));
    
    emDCDAgent_GetStoryViewerID(agent_handle, a_szChannelID, a_szBlockID, a_szEntryID, &a_nPageOrder);
    strcpy(g_dcd_app_cntx.channel_id, a_szChannelID);
    strcpy(g_dcd_app_cntx.block_id, a_szBlockID);

    channel_index = emDCDAgent_GetChannelIndex(agent_handle, g_dcd_app_cntx.channel_id);
    channel_handle = emDCDAgent_GetChannelAt(agent_handle, channel_index);
    block_handle = emDCDAgent_GetChannelBlockAt(channel_handle, g_dcd_app_cntx.block_index);
    block_id_focus = emDCDAgent_GetBlockID(block_handle);
    strcpy(g_dcd_app_cntx.block_id, block_id_focus);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_default_city_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static CHAR* mmi_dcd_get_default_city_id(HDCD_Agent agent_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *     default_city_id = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    default_city_id = emDCDAgent_GetConfigDefaultUserCity(agent_handle);
    if ((default_city_id) && strlen(default_city_id))
    {
        return default_city_id;
    }
    else
    {
        return NULL;
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_default_city_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
WCHAR* mmi_dcd_get_preset_summary_ext(void* agent_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Channel  preset_chan = NULL;
    CHAR*      summary = NULL;
    CHAR*      title = NULL;
    WCHAR*     summary_ucs = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    preset_chan = emDCDAgent_GetPreChannelAt(agent_handle, 0);

    if (preset_chan)
    {
        title = emDCDAgent_GetChannelTitle(preset_chan);
        summary = emDCDAgent_GetChannelSummary(preset_chan);
        if (!g_preset_content)
        {
            g_preset_content = (WCHAR *)OslMalloc(DCD_PRESET_CHANNEL_SUMMARY_LEN * ENCODING_LENGTH);
        }
        memset(g_preset_content, 0, sizeof(g_preset_content));
        mmi_chset_utf8_to_ucs2_string(
        (kal_uint8*) g_preset_content,
        DCD_PRESET_CHANNEL_SUMMARY_LEN * ENCODING_LENGTH,
        (kal_uint8*) title);

        summary_ucs = (WCHAR *)OslMalloc(DCD_PRESET_CHANNEL_SUMMARY_LEN * ENCODING_LENGTH);
        memset(summary_ucs, 0, sizeof(summary_ucs));
        mmi_chset_utf8_to_ucs2_string(
        (kal_uint8*) summary_ucs,
        DCD_PRESET_CHANNEL_SUMMARY_LEN * ENCODING_LENGTH,
        (kal_uint8*) summary);

        mmi_wcscat(g_preset_content, L"\n");
        mmi_wcscat(g_preset_content, summary_ucs);
        if (summary_ucs)
        {
            OslMfree(summary_ucs);
        }
    }
    
    return g_preset_content;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_preset_summary_free_ext
 * DESCRIPTION
 *  mmi_dcd_preset_summary_free_ext
 * PARAMETERS
 *  agent               [IN] dcd agent handle  
 *  index               [IN] channel index
 *  buf                 [IN] channel title buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_preset_summary_free_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_preset_content)
    {
        OslMfree(g_preset_content);
        g_preset_content = NULL;
    }
}

#endif /* __MMI_OP01_DCD_V30__ */

