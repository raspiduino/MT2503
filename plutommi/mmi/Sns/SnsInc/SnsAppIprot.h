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
 * SnsAppIprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file implements application functions for SNS feature.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SNS_APP_IPROT_H__
#define __SNS_APP_IPROT_H__

#include "mmi_features.h"
#ifdef __SOCIAL_NETWORK_SUPPORT__

#include "MMIDataType.h"
#include "gui_typedef.h"
#include "wgui_categories_sns.h"
#include "mmi_frm_events_gprot.h"
#include "MenucuiGprot.h"
#include "gdi_include.h"
#include "wgui_categories_text_viewer.h"
#include "gui_effect_oem.h"

#include "SnsSrvDefs.h"

#include "SnsAppGprot.h"
#include "SnsCuiGprot.h"


/**************************************************************
 * MARCO                                                      *
 **************************************************************/

//#define __SNS_APP_SLA__

#define SNS_CATEGORY_DEFAULT_ITEM_OFFSET    0

#define SNS_PERSONAL_INFORMATION_MAX_LENGTH     500

#define MMI_SNS_VIEWER_BUF_SIZE (WGUI_CAT_TEXT_VIEWER_IMAGE_MAX_WIDTH * \
                                WGUI_CAT_TEXT_VIEWER_IMAGE_MAX_HEIGHT * \
                                GUI_EFFECT_LAYER_BYTE_PER_PIXEL)


/**************************************************************
 * Structure Declaration                                      *
 **************************************************************/
typedef enum
{
    MMI_SNS_TAB_NONE,
    MMI_SNS_TAB_ACTIVITIES = MMI_SNS_TAB_NONE,
    MMI_SNS_TAB_MY_PROFILE,
    MMI_SNS_TAB_DIRECT_MSG,
    MMI_SNS_TAB_NOTIFICATIONS,

    MMI_SNS_TAB_TOTAL
} mmi_sns_center_tab_enum;


typedef enum
{
    MMI_SNS_PROFILE_ACTIVITY,
    MMI_SNS_PROFILE_ALBUMS,
    MMI_SNS_PROFILE_PERSONAL_INFO,

    MMI_SNS_PROFILE_TOTAL
} mmi_sns_profile_enum;


typedef enum
{
//    SNS_NOTIFICATIONS_AT_ME,
    SNS_NOTIFICATIONS_COMMENTS,
    SNS_NOTIFICATIONS_FRIENDS_REQ,

    SNS_NOTIFICATIONS_TOTAL
} mmi_sns_notifications_enum;


typedef enum
{
    SNS_FILTER_PLAIN,
    SNS_FILTER_MULTIBEL,
    SNS_FILTER_RADIO,

    SNS_FILTER_END
} mmi_sns_filter_enum;


typedef enum
{
    MMI_SNS_LIST_TYPE_NONE,
    MMI_SNS_LIST_TYPE_NEWSFEED,
    MMI_SNS_LIST_TYPE_FRIEND_NEWSFEED,
    MMI_SNS_LIST_TYPE_ACTIVITY_COMMENTS,
    MMI_SNS_LIST_TYPE_TO_ME,
    MMI_SNS_LIST_TYPE_ALBUMS,
    MMI_SNS_LIST_TYPE_PIC,
    MMI_SNS_LIST_TYPE_DM_THREAD,
    MMI_SNS_LIST_TYPE_DM_MSG,
    MMI_SNS_LIST_TYPE_AT_ME,
    MMI_SNS_LIST_TYPE_COMMENTS,
    MMI_SNS_LIST_TYPE_FRIENDS_REQ,
    MMI_SNS_LIST_TYPE_ACCOUNTS,
    MMI_SNS_LIST_TYPE_GROUP,
    MMI_SNS_LIST_TYPE_FRIENDS,
    MMI_SNS_LIST_TYPE_PERSONAL_INFO,
    MMI_SNS_LIST_TYPE_NOTIF_ACTIVITY,

    MMI_SNS_LIST_TYPE_TOTAL
} mmi_sns_list_type_enum;


typedef enum
{
    MMI_SNS_LIST_STATUS_INIT,           /* 0 is no more, 1 is more */
    MMI_SNS_LIST_STATUS_MORE,           /* 0 is no more, 1 is more */
    MMI_SNS_LIST_STATUS_DOWN,           /* 0 is downing, 1 is done */
    MMI_SNS_LIST_STATUS_DOWN_MORE,      /* 1 is down by more */
    MMI_SNS_LIST_STATUS_REFRESH,        /* 1 is prevous operation is refresh */
    MMI_SNS_LIST_STATUS_FREEZE,         /* 1 is prevous operation will freeze list */

} mmi_sns_list_status_enum;


typedef enum
{
    MMI_SNS_ACCOUNT_TWITTER_NONE,
    MMI_SNS_ACCOUNT_TWITTER_ONLY,
    MMI_SNS_ACCOUNT_TWITTER_HAVE
} mmi_sns_twitter_account_enum;


/* activity list toolbar */
#ifdef __MMI_ICON_BAR_SUPPORT__
typedef enum
{
    MMI_SNS_ACT_LIST_TOOLBAR_REFRESH,
    MMI_SNS_ACT_LIST_TOOLBAR_ADD,
    MMI_SNS_ACT_LIST_TOOLBAR_REPLY,
    MMI_SNS_ACT_LIST_TOOLBAR_NEUTRAL,

    MMI_SNS_ACT_LIST_TOOLBAR_TOTAL
} mmi_sns_act_list_toolbar_enum;
#endif


typedef struct
{
    mmi_sns_list_type_enum list_type;
    MMI_BOOL available;
    U8  status; /* check mmi_sns_list_status_enum */
    S32 list_id;
    U16 total;
    U16 count;
    S16 start_index;
    S16 end_index;
    srv_sns_result result;
} mmi_sns_list_info_struct;


typedef void (*FuncPtrS32)(S32);

typedef struct
{
    CatGetAsyncItemFuncPtr get_item_func;
//    wgui_cat1006_get_image_path get_item_img;
} mmi_sns_cat_item_func_struct;


typedef struct
{
    FuncPtrS32 hilite_hdlr;
    FuncPtr lsk_hdlr;
    FuncPtr csk_hdlr;
    FuncPtr rsk_hdlr;
} mmi_sns_cat_op_hdlr_struct;


typedef struct
{
    mmi_sns_list_type_enum list_type;
    void *user_data;
    CatGetAsyncItemFuncPtr cat_refresh;
} mmi_sns_list_ud_struct;


typedef struct
{
    MMI_ID gid;
    mmi_sns_profile_enum profile_id;
    mmi_sns_list_info_struct account_list_info;
    srv_sns_account_struct *account;
    mmi_sns_list_info_struct *list;
} mmi_sns_profile_group_struct;


typedef struct
{
    MMI_ID gid;
    mmi_sns_list_info_struct personal_list;
    WCHAR *buffer;
} mmi_sns_personal_info_struct;


typedef struct
{
    MMI_ID gid;
    MMI_ID scrn_id;
    MMI_BOOL like_req;
    S16 index;
    mmi_sns_list_info_struct *list_info;
} mmi_sns_like_func_param_struct;


typedef struct
{
    MMI_ID gid;
    MMI_ID scrn_id;
    S16 index;
    mmi_sns_list_info_struct *list_info;
} mmi_sns_retweet_func_param_struct;


typedef struct
{
    MMI_ID gid;
    srv_sns_notif_struct *notif;
} mmi_sns_notif_struct;


typedef struct
{
    MMI_ID gid;
    mmi_sns_list_info_struct *list_info;
} mmi_sns_refresh_list_struct;


typedef void (*SnsDownPhotoFuncPtr)(MMI_BOOL, void *);

typedef struct
{
    MMI_ID gid;
    U16 string_id;
    S32 process_id;
    S32 list_id;
    S16 index;
    MMI_BOOL is_error_tip;
    void *user_data;
    SnsDownPhotoFuncPtr handler;
} mmi_sns_down_big_photo_struct;


/**************************************************************
 * Function Defination                                        *
 **************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_sns_launch_int
 * DESCRIPTION
 *  This function is used to launch SNS center.
 * PARAMETERS
 *  tab_id          [in] mmi_sns_center_tab_enum
 * RETURNS
 *  viod
 *****************************************************************************/
extern void mmi_sns_launch_int(mmi_sns_center_tab_enum tab_id);


/* Utility */
#define MMI_SNS_UTIL_GET_CURR_GROUP_UD()     mmi_frm_group_get_user_data(mmi_frm_group_get_active_id())

extern void *mmi_sns_util_get_curr_scrn_ud(void);
extern MMI_ID mmi_sns_util_get_parent_group_id(MMI_ID gid);

extern void mmi_sns_show_loading_screen(mmi_scrn_essential_struct *scrn_info);
extern void mmi_sns_util_show_plz_wait_scrn(MMI_ID gid, MMI_ID sid, U16 string_id, MMI_BOOL is_rsk);
extern void mmi_sns_util_change_plz_wait_scrn(MMI_ID gid, MMI_ID sid, U16 string_id, MMI_BOOL is_rsk);
extern void mmi_sns_show_dummy_screen(void);
extern void mmi_sns_timestamp_2_string(U32 time_stamp, WCHAR *data_time);
extern void mmi_sns_timestamp_2_stringY(U32 time_stamp, WCHAR *data_time);
extern MMI_ID mmi_sns_option_list_generic(MMI_ID parent_id, mmi_menu_id root_menu_id, U16 title_id);

extern MMI_BOOL mmi_sns_is_scrn_active(const MMI_ID group_id, const MMI_ID scrn_id);

extern mmi_sns_list_ud_struct *mmi_sns_init_list_user_data(
                                    mmi_sns_list_type_enum list_type,
                                    void *user_data,
                                    CatGetAsyncItemFuncPtr cat_refresh);

extern void mmi_sns_util_set_list_info(mmi_sns_list_type_enum list_type, mmi_sns_list_info_struct *list_info, srv_sns_evt_list_updated_struct *list_param);
extern MMI_BOOL mmi_sns_util_check_image_available(WCHAR *path);

extern void mmi_sns_util_freeze_list(mmi_sns_list_info_struct *list_info);
extern void mmi_sns_util_unfreeze_list(mmi_sns_list_info_struct *list_info);
extern MMI_BOOL mmi_sns_util_is_list_alive(mmi_sns_list_info_struct *list_info);
extern MMI_BOOL mmi_sns_util_is_net_avaiable(void);
extern MMI_BOOL mmi_sns_util_is_phone_online(void);


/* notifications */
extern void mmi_sns_notifications_pre_entry(mmi_sns_notifications_enum noti_id, mmi_sns_list_info_struct *list_info);
extern void mmi_sns_notifications_update_list(void);

extern mmi_sns_notif_struct *mmi_sns_notifications_get_notif_ud(void);
extern mmi_ret mmi_sns_notifications_clear_notif_callback(mmi_event_struct *param);


#ifdef __MMI_SNS_ALBUM__
/* Albums */
extern void mmi_sns_albums_create(MMI_ID gid, srv_sns_user_struct *user);
extern void mmi_sns_albums_launch(MMI_ID gid, mmi_sns_profile_group_struct *profile_gud);
extern void mmi_sns_photo_comments_launch(MMI_ID gid, srv_sns_photo_struct *photo);

#endif


/* My profile */
extern S32 mmi_sns_my_profile_get_account_info(mmi_sns_profile_enum profile_id, U16 *total, U32 *providers, CHAR users_id[][SRV_SNS_MAX_LEN_ID]);
extern void mmi_sns_my_profile_launch(MMI_ID parent_gid, mmi_sns_profile_enum profile_id);
extern void mmi_sns_personal_info_pre_entry(MMI_ID parent_gid, mmi_sns_personal_info_struct *personal_info_sud);


/* Activity details */
extern void mmi_sns_act_details_scrn_pre_entry(MMI_ID parent_id, S16 act_index, mmi_sns_list_info_struct *act_list);


/* Direct message */
extern void mmi_sns_direct_msg_scrn_pre_entry(MMI_ID parent_id, S32 thread_id, mmi_sns_list_info_struct *thread_list);


/* Micellaneous */
extern void mmi_sns_activities_common_option_process(MMI_ID parent_gid, cui_menu_event_struct *evt, srv_sns_activity_struct *activity);
extern void mmi_sns_direct_msg_option_process(MMI_ID parent_gid, cui_menu_event_struct *evt, srv_sns_thread_struct *thread);
extern void mmi_sns_init_list(S32 list_id, mmi_sns_list_info_struct *list_info);
extern S32 mmi_sns_load_list(S32 list_id, S16 index, mmi_proc_func done_cb, void *user_data);

extern void mmi_sns_get_accounts_info(srv_sns_login_enum is_login, srv_sns_feature_category category, U8 features, mmi_sns_list_info_struct *list_info);
extern void mmi_sns_misc_refresh_status_icon(MMI_BOOL is_set);

extern mmi_ret mmi_sns_activity_like_callback(mmi_event_struct *param);

extern void mmi_sns_lsk_status_update(S32 index, mmi_sns_list_info_struct *list_info);

extern void mmi_sns_misc_sending_screen(MMI_ID parent_gid, S32 process_id, cui_sns_event_enum evt_id);

extern void mmi_sns_misc_big_photo_loading(mmi_sns_down_big_photo_struct *big_photo_struct);

extern void mmi_sns_check_list_invalid(MMI_ID gid, mmi_sns_list_info_struct *list_info);
extern void mmi_sns_misc_account_logout_scrn_lsk_hdlr(void);
extern void mmi_sns_misc_list_refresh(MMI_ID gid, mmi_sns_list_info_struct *list_info);

extern void mmi_sns_misc_add_like_comment(srv_sns_activity_struct *activity, cat_iconlist_menu_item *item);

extern mmi_ret mmi_sns_app_not_ready_proc(mmi_event_struct *evt);
extern MMI_BOOL mmi_sns_misc_check_load_list_result(srv_sns_result result, MMI_BOOL is_meun_lable, S32 total);

extern MMI_BOOL mmi_sns_misc_check_only_twitter(void);
extern mmi_sns_twitter_account_enum mmi_sns_misc_check_have_twitter(void);

extern MMI_RET mmi_sns_misc_oom_close_group_proc(mmi_event_struct *evt);

extern gdi_image_cache_bmp_struct mmi_sns_misc_get_provider_img_callback(S32 item_index, U32 provider);
extern void mmi_sns_misc_provider_img_buffer_free(void);

extern void *mmi_sns_misc_viewer_buf_allocate(void);
extern void mmi_sns_misc_viewer_buf_free(void);

#ifdef __MMI_ICON_BAR_SUPPORT__
#define TOOLBAR_COUNT(Array)                        sizeof(Array)/sizeof(Array[0])
#define MMI_SNS_TOOLBAR_SETUP(Array, Callback)      mmi_sns_set_toolbar(TOOLBAR_COUNT(Array), (PU16)Array, Callback)

extern void mmi_sns_set_toolbar(S32 count, PU16 ids, GUIIconbarItemCallback callback);
extern void mmi_sns_set_act_list_toolbar(GUIIconbarItemCallback callback);
extern void mmi_sns_set_act_list_toolbar_twitter(GUIIconbarItemCallback callback);
extern void mmi_sns_set_toolbar_single_button(U16 icon_id, U16 disable_icon_id, U16 string_id, GUIIconbarItemCallback callback);

extern void mmi_sns_toolbar_status_update(S32 index, mmi_sns_list_info_struct *list_info, S32 min_total, S32 max_total, MMI_BOOL immediate);

#endif /* __MMI_ICON_BAR_SUPPORT__ */

extern MMI_BOOL mmi_sns_personal_info_string(srv_sns_info_struct *personal_info, WCHAR *buffer);
extern void mmi_sns_my_info_error_string(srv_sns_result result, WCHAR *buffer);
extern void mmi_sns_personal_info_set_midd_color(WCHAR *buffer);


/* news */
extern MMI_BOOL mmi_sns_news_need_2_update(mmi_sns_list_type_enum list_type, MMI_BOOL to_clean);
extern U32 mmi_sns_news_get_badge(void);


#endif /* __SOCIAL_NETWORK_SUPPORT__ */
#endif /* __SNS_APP_IPROT_H__ */
