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

/*******************************************************************************
 * Filename:
 * ---------
 * BrowserTypes.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains all the data structures used for browser secondary MMI implementation.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "MMI_features.h"
#ifndef BROWSERAPPTYPES_H
#define BROWSERAPPTYPES_H

#ifdef __MMI_BROWSER_2__

/**********************************************HEADERS START***********************************/
#include "UriAgentSrvGprot.h"      /* for the URI Agent enums and callback function pointers */
#include "BrowserSrvProts.h"    /* for various Browser service enums variable etc */
#include "InlineCuiGprot.h"     /* for Inline cui related stuct */
#include "FileMgrSrvGProt.h"    /* for the FMGR enums macros and others */
#include "MMIDataType.h"
#include "wgui_touch_screen.h"
#include "BrowserSrvConfig.h"
#include "kal_general_types.h"
#include "BrowserSrvBookmarks.h"
#include "App_ltlcom.h"
#include "bam_struct.h"
#include "common_nvram_editor_data_item.h"
#include "WAPProfileSrvType.h"
#include "wps_struct.h"
#ifdef OBIGO_Q05A
#include "bam_lib.h"
#endif
#include "wap_adp.h"

/**********************************************HEADERS END***********************************/


/**********************************************MACROS START***********************************/
typedef void (*hide_hdlr_func_ptr) (void*);
typedef S32 (*highlighter_func_ptr) (void);
typedef void (*show_toolbar_func_ptr) (void);
typedef S32 (*inline_fill_func)(void);
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
typedef void (*tap_cllback_func)(mmi_tap_type_enum tap_type,S32 index);
#endif /* __MMI_FTE_SUPPORT__ */
typedef mmi_ret (*browser_cui_proc)(mmi_event_struct *evt);
typedef void (*FuncPtr) (void);

#ifdef __MMI_OP12_BRW_EMBEDDED_LINKS__
#define BRW_MAX_EMBEDDED_LINKS_ALLOWED 30
#endif 

/* Browser preferences */
#define BRW_TIME_OUT_LEN                    3
#define BRW_ZOOM_VAL_LEN                    4

#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
#define BRW_SPLASH_SCREEN_TIMER_VALUE       3000
#endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */

#define BRW_ADDRESS_LIST_TITLE_LENGTH       SRV_BRW_ADDRESS_LIST_TITLE_LENGTH
#define BRW_ADDRESS_LIST_URL_LENGTH         SRV_BRW_ADDRESS_LIST_URL_LENGTH

/* Object Properties */
#define BRW_OBJECT_PROPERTIES_NAME_LEN      SRV_BRW_MAX_TITLE_LENGTH
#define BRW_OBJECT_PROPERTIES_ADDRESS_LEN   SRV_BRW_MAX_URL_LENGTH
#define BRW_OBJECT_PROPERTIES_SIZE_LEN      50
#define BRW_OBJECT_PROPERTIES_DATE_LEN      20
#define BRW_CURRENT_CERT_STR_LEN            3000
#define BRW_SESSION_INFO_STR_LEN            1000

#define BRW_UPLOAD_PROGRESS_TIMER_VALUE     2000

#define BRW_UTF8_ENCODING_LENGTH	    3
#define BRW_BKM_ADD_BOOKMARK_ITEM_COUNT     4
#define BRW_BKM_EDIT_BOOKMARK_ITEM_COUNT    4
#define BRW_BKM_VIEW_BOOKMARK_ITEM_COUNT    4
#ifdef __MMI_URI_AGENT__
#define BRW_HTTP_URI_SCHEME                 "http"
#define BRW_HTTPS_URI_SCHEME			    "https"
#define BRW_FILE_URI_SCHEME                 "file"
#endif /* __MMI_URI_AGENT__ */

#define BRW_TEMP_VBKM_FILE_DRIVE            SRV_FMGR_SYSTEM_DRV
#define BRW_TEMP_VBKM_FILE_PATH             L"\\@vbookmarks\\vbookmark.url"

#define BRW_DEFAULT_ENTER_ADDR_STR          "http://"
#define BRW_MAX_VISIBLE_URL_LENGTH          38
#define BRW_MENU_ITEM_TRUNC_STR             L"..."
#define BRW_CONFIRM_DLG_MSG_LEN             500
#define BRW_MEMORY_STATUS_MSG_LEN			200

#define BRW_DO_ELEMENT_EVENT_TYPE_PREVIOUS  "prev"
#define BRW_OPERATOR_DEFAULT_PROF_INDEX     0

#ifdef __MMI_BRW_PAGE_FETCHING_STATUS__
#define BRW_PAGE_CONNECTING_LIMIT           10
#define BRW_PAGE_PROCESSING_LIMIT           65
#define BRW_PAGE_LOADING_LIMIT              100
#define BRW_PAGE_INCREMENTATION             5
#endif /* __MMI_BRW_PAGE_FETCHING_STATUS__ */ 

#define BRW_UTF8_ENCODING_LENGTH            3       /* as some of the chinese chars may take 3 bytes */

/* Time out limits */
#define BRW_TIME_OUT_MIN_VAL                15
#define BRW_TIME_OUT_MAX_VAL                300


/* stored pages */
#define BRW_STORED_PAGE_PROPERTIES_COUNT  4
#define BRW_STORED_PAGE_PROPERTIES_DATE_LEN  10
#define BRW_STORED_PAGE_PROPERTIES_SIZE_LEN  20
/* stored pages */

#define BRW_PREFERENCES_INLINE_SHOW_IMAGES_OPTION_COUNT        2
#define BRW_PREFERENCES_INLINE_SHOW_VIDEOS_OPTION_COUNT        2
#define BRW_PREFERENCES_INLINE_PLAY_SOUNDS_OPTION_COUNT        2
#define BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_OPTION_COUNT 2
#define BRW_PREFERENCES_INLINE_CSS_OPTION_COUNT             2
#define BRW_PREFERENCES_INLINE_SCRIPT_OPTION_COUNT          2
#define BRW_PREFERENCES_INLINE_CACHE_OPTION_COUNT           2
#define BRW_PREFERENCES_INLINE_COOKIE_OPTION_COUNT          2
#define BRW_PREFERENCES_INLINE_SHORTCUTS_OPTION_COUNT       2
#ifdef BRW_SECURITY_WARNINGS_SUPPORT
#define BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_OPTION_COUNT  2
#endif /* BRW_SECURITY_WARNINGS_SUPPORT */
#ifdef BRW_SEND_DEVICE_ID_SUPPORT
#define BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_OPTION_COUNT     2
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */ 
#ifdef __MMI_BRW_POST_SESSION_INFO__
#define BRW_PREFERENCES_INLINE_POST_SESSION_INFO_OPTION_COUNT     2
#endif 

#define BRW_SELECT_MODE_IMAGE_PROP_COUNT    2
#define BRW_PAGE_OBJECT_PROPERTIES_COUNT    2
#define BRW_THIS_PAGE_PROPERTIES_COUNT      3
#define BRW_THIS_PAGE_PROPERTIES_SIZE_LEN   20

#ifdef __MMI_BRW_POST_SESSION_INFO__
#define BRW_POST_SESSION_INFO_STR_LEN       2000
#endif 

#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
#define BRW_MAX_UPLOAD_STRING_LENGTH 30
#endif

#define BRW_VIEW_BOOKMARK_STR_LEN       700

/**********************************************MACROS END***********************************/

/************************************************ENUM START************************************/
#ifdef __MMI_OP12_BRW_EMBEDDED_LINKS__
typedef enum
{
    BRW_EMBEDDED_LINK_START = 0,
    BRW_EMBEDDED_LINK1,
    BRW_EMBEDDED_LINK2,
    BRW_EMBEDDED_LINK3,
    BRW_EMBEDDED_LINK4,
    BRW_EMBEDDED_LINK5,
    BRW_EMBEDDED_LINK6,
    BRW_EMBEDDED_LINK7,
    BRW_EMBEDDED_LINK8,
    BRW_EMBEDDED_LINK9,
    BRW_EMBEDDED_LINK10,
    BRW_EMBEDDED_LINK11,
    BRW_EMBEDDED_LINK12,
    BRW_EMBEDDED_LINK13,
    BRW_EMBEDDED_LINK14,
    BRW_EMBEDDED_LINK15,
    BRW_EMBEDDED_LINK16,
    BRW_EMBEDDED_LINK17,
    BRW_EMBEDDED_LINK18,
    BRW_EMBEDDED_LINK19,
    BRW_EMBEDDED_LINK20,
    BRW_EMBEDDED_LINK_TOTAL
} brw_embedded_link_enum;
#endif 

#ifdef OBIGO_Q05A
typedef enum
{
    BRW_ENCODING_START = 0,
    BRW_ENCODING_1,
    BRW_ENCODING_2,
    BRW_ENCODING_3,
    BRW_ENCODING_4,
    BRW_ENCODING_5,
    BRW_ENCODING_6,
    BRW_ENCODING_7,
    BRW_ENCODING_8,
    BRW_ENCODING_9,
    BRW_ENCODING_10,
    BRW_ENCODING_11,
    BRW_ENCODING_12,
    BRW_ENCODING_13,
    BRW_ENCODING_14,
    BRW_ENCODING_15,
    BRW_ENCODING_16,
    BRW_ENCODING_17,
    BRW_ENCODING_18,
    BRW_ENCODING_19,
    BRW_ENCODING_20,
    BRW_ENCODING_TOTAL
} brw_encoding_enum;
#endif 


typedef enum
{
    BRW_VIEW_NONE = 0,
    BRW_VIEW_TRUSTED_CERTIFICATE,
    BRW_VIEW_CURRENT_CERTIFICATE,
    BRW_VIEW_CURRENT_SESSION_INFO,
    BRW_VIEW_TOTAL
} brw_view_enum;


#ifdef OBIGO_Q05A
typedef enum
{
    BRW_PAGE_OBJECT_TYPE_IMAGE = 0,
    BRW_PAGE_OBJECT_TYPE_BG_IMAGE,
    BRW_PAGE_OBJECT_TYPE_SOUNDS,
    BRW_PAGE_OBJECT_TYPE_OTHERS,
    BRW_PAGE_OBJECT_TYPES_COUNT
} brw_page_object_types_enum;
#endif /* OBIGO_Q05A */


#ifdef __MMI_BRW_PAGE_FETCHING_STATUS__
typedef enum
{
    BRW_FETCHING_STATUS_CONNECTING = 0,
    BRW_FETCHING_STATUS_PROCESSING,
    BRW_FETCHING_STATUS_LOADING,

    BRW_TOTAL_FETCHING_STATUS
} brw_fetching_status_enum;
#endif /* __MMI_BRW_PAGE_FETCHING_STATUS__ */ 

typedef enum
{
	MMI_BRW_FALSE,
	MMI_BRW_TRUE,
	MMI_BRW_ASYNC_WAIT,
    MMI_BRW_NO_URL_IN_ADDR_LIST,
    MMI_BRW_END
}mmi_brw_app_result_enum;

typedef enum
{
    BRW_PREF_NEVER_INDEX = 0,
    BRW_PREF_ALWAYS_INDEX,
    BRW_PREF_ALWAYS_NEVER_TOTAL
} brw_never_always_string_array_enum;

typedef enum
{
    BRW_PREF_DISABLE_INDEX = 0,
    BRW_PREF_ENABLE_INDEX,
    BRW_PREF_ENABLE_DISABLE_TOTAL
} brw_disable_enable_string_array_enum;

#ifdef OBIGO_Q05A
typedef enum
{
    BRW_APP_AUTH_DLG_SAVE_NONE_INDEX = 0,
    BRW_APP_AUTH_DLG_SAVE_BOTH_INDEX,
    BRW_APP_AUTH_DLG_SAVE_USERNAME_INDEX,
    BRW_APP_AUTH_DLG_SAVE_OPTION_TOTAL
} brw_app_auth_dialog_save_option_string_array_enum;

#endif /* #ifdef OBIGO_Q05A */

typedef enum
{
    BRW_AUTH_DLG_INLINE_USERNAME_CAPTION  = CUI_INLINE_ITEM_ID_BASE + 0,
    BRW_AUTH_DLG_INLINE_USERNAME,
    BRW_AUTH_DLG_INLINE_PASSWORD_CAPTION,
    BRW_AUTH_DLG_INLINE_PASSWORD,
#ifdef OBIGO_Q05A
    BRW_AUTH_DLG_INLINE_SAVE_OPTION_CAPTION,
    BRW_AUTH_DLG_INLINE_SAVE_OPTION,
#endif /* OBIGO_Q05A */
    BRW_AUTH_DLG_INLINE_TOTAL
} brw_auth_inline_item_display;

typedef enum
{
    BRW_LPD_NONE = 0,
    BRW_LPD_MAIN_MENU,
    BRW_LPD_EXTERNAL_LOAD_URL_REQ,
    BRW_LPD_EXTERNAL_LOAD_DATA_REQ,
    BRW_LPD_SETTINGS_PREF,
    BRW_LPD_ASM_TERMINATE,
    BRW_LPD_ACTIVE_PROFILE_CHANGED,
#ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
    BRW_LPD_RESTORE_BRW_SETTINGS,
#endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */
#ifdef __SAT__
    BRW_LPD_SAT_LAUNCH_REQ,
#endif 
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif 
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    BRW_LPD_HOME_SCR_ENTER_ADDRESS,
    BRW_LPD_HOME_SCR_USER_DEFINED_BKM,
    BRW_LPD_HOME_SCR_DUMMY,
#endif 
    BRW_LPD_NEED_BEARER_RELEASE,
#if (MMI_MAX_SIM_NUM >= 2)
    BRW_LPD_TEMP_PROFILE_CHANGED,
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#ifdef __MMI_RMGR_SEAMLESS_UNLOCK__
    BRW_LPD_SESSION_CLOSED,
#endif /* __MMI_RMGR_SEAMLESS_UNLOCK__ */ 
    BRW_LPD_WIFI_PREFER_LAUNCH,
    BRW_LPD_WIFI_PREFER_RELAUNCH,
    BRW_LPD_END
} brw_launching_pad_enum;


#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
typedef enum
{
    BRW_UPLOAD_STATUS_UPLOADING,
    BRW_UPLOAD_STATUS_COMPLETE,
    BRW_UPLOAD_STATUS_FINISHED
} mmi_brw_upload_status_enum;

#endif /* __MMI_BRW_FILE_UPLOAD_SUPPORT__ */

typedef enum
{
    BRW_PREFERENCES_INLINE_TIMEOUT_CAPTION = CUI_INLINE_ITEM_ID_BASE + 0,
    BRW_PREFERENCES_INLINE_TIMEOUT_EDIT,
    BRW_PREFERENCES_INLINE_SHOW_IMAGES_CAPTION,
    BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT,
#ifdef OBIGO_Q05A
    BRW_PREFERENCES_INLINE_SHOW_VIDEOS_CAPTION,
    BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT,
    BRW_PREFERENCES_INLINE_PLAY_SOUNDS_CAPTION,
    BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT,
    BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_CAPTION,
    BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT,
    BRW_PREFERENCES_INLINE_CSS_CAPTION,
    BRW_PREFERENCES_INLINE_CSS_SELECT,
    BRW_PREFERENCES_INLINE_SCRIPT_CAPTION,
    BRW_PREFERENCES_INLINE_SCRIPT_SELECT,
#endif /* OBIGO_Q05A */
#ifndef SLIM_WAP_MMS
    BRW_PREFERENCES_INLINE_CACHE_CAPTION,
    BRW_PREFERENCES_INLINE_CACHE_SELECT,
#endif
    BRW_PREFERENCES_INLINE_COOKIE_CAPTION,
    BRW_PREFERENCES_INLINE_COOKIE_SELECT
#ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
        , BRW_PREFERENCES_INLINE_SHORTCUTS_CAPTION, BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT
#endif 
#ifdef BRW_SECURITY_WARNINGS_SUPPORT
        , BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_CAPTION, BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT
#endif 
#ifdef BRW_SEND_DEVICE_ID_SUPPORT
        , BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_CAPTION, BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT
#endif 
#ifdef __MMI_BRW_POST_SESSION_INFO__
        , BRW_PREFERENCES_INLINE_POST_SESSION_INFO_CAPTION, BRW_PREFERENCES_INLINE_POST_SESSION_INFO_SELECT
#endif 
    , BROWSER_PREFERENCES_ITEM_COUNT
} brw_preferences_inline_item_display;



#ifdef __MMI_VECTOR_FONT_SUPPORT__
typedef enum
{
    BRW_FONT_SIZE_SMALL = 80,
    BRW_FONT_SIZE_MEDIUM = 100,
    BRW_FONT_SIZE_LARGE = 120
} brw_font_size_enum;
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */

#ifdef __MMI_FTE_SUPPORT__
typedef enum
{
    BRW_LAUNCH_FROM_BOOKMARK,
    BRW_LAUNCH_FROM_ADDRESS,
    BRW_LAUNCH_FROM_RECENT_PAGE_ADD_BKM,
    BRW_LAUNCH_FROM_RECENT_PAGE_INPUT_ADDR,
    BRW_LAUNCH_FROM_RECENT_PAGE_DELETE,
    BRW_LAUNCH_FROM_RECENT_PAGE_GOTO,
    BRW_LAUNCH_FROM_STORED_PAGE_ADD_BKM,
    BRW_LAUNCH_FROM_STORED_PAGE_INPUT_ADDR,
    BRW_LAUNCH_FROM_STORED_PAGE_DELETE,
    BRW_LAUNCH_FROM_STORED_PAGE_GOTO,
    BRW_LAUNCH_FROM_RENDER_PAGE,
    BRW_LAUNCH_FROM_BKM_BROWSE_PATH,
    BRW_LAUNCH_FROM_MENU
} brw_toolbar_enum;
#endif  /* __MMI_FTE_SUPPORT__ */

/* Typedefs */
typedef enum
{
    BRW_APP_INLINE_TITLE_CAPTION  = CUI_INLINE_ITEM_ID_BASE + 0,
    BRW_APP_INLINE_TITLE,
    BRW_APP_INLINE_ADDRESS_CAPTION,
    BRW_APP_INLINE_URL
} brw_app_inline_item_display;

typedef enum
{
    BRW_OBJECT_PROP_NAME = 0,
    BRW_OBJECT_PROP_ADDRESS,
    BRW_OBJECT_PROP_SIZE,
    BRW_OBJECT_PROP_DATE,
    BRW_OBJECT_PROP_MAX_COUNT
} brw_obj_prop_enum;


#ifdef __MMI_VBOOKMARK__
typedef enum
{
    BRW_BKM_FOLDER_NONE = 0,
    BRW_BKM_FOLDER_CREATE,
    BRW_BKM_FOLDER_RENAME,
    BRW_BKM_FOLDER_END
} brw_bkm_folder_opeartion_enum;

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
typedef enum
{
    BRW_BKM_VBOOKMARKS_MENU_ITEM_INDEX = 0,
#ifdef __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__
    BRW_BKM_EXTERNAL_MEMORY_MENU_ITEM_INDEX = 1,
#endif /* __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__ */ 

    BRW_BKM_TRANSFER_BOOKMARKS_TOTAL_MENU_ITEMS
} brw_bkm_transfer_bookmarks_menu_enum;
#endif

typedef enum
{
    BRW_BKM_BROWSE_PATH_NONE = 0,
    BRW_BKM_BROWSE_PATH_COPY_TO,
    BRW_BKM_BROWSE_PATH_MOVE_TO
} brw_bkm_browse_path_enum;

typedef enum
{
    BRW_BKM_ADD_BOOKMARK = 0,
    BRW_BKM_ADD_TO_BOOKMARK
} brw_bkm_add_bookmark_enum;

#endif /* __MMI_VBOOKMARK__ */

typedef enum
{
    BRW_INLINE_NAME_CAPTION  = CUI_INLINE_ITEM_ID_BASE + 0,
    BRW_INLINE_NAME,
    BRW_INLINE_URL_CAPTION,
    BRW_INLINE_ADDRESS,
    BRW_INLINE_SIZE_CAPTION,
    BRW_INLINE_SIZE,
    BRW_INLINE_DATE_CAPTION,
    BRW_INLINE_DATE
} brw_obj_properties_inline_item_display;


/* Typedefs */
typedef enum
{
    BRW_INLINE_TITLE_CAPTION  = CUI_INLINE_ITEM_ID_BASE + 0,
    BRW_INLINE_TITLE,
    BRW_INLINE_ADDRESS_CAPTION,
    BRW_INLINE_URL
} brw_inline_item_display;

typedef enum
{
    BRW_LAUNCH_TYPE_URL = 0,
    BRW_LAUNCH_TYPE_RECENT_PAGE,
    BRW_LAUNCH_TYPE_STORED_PAGE,
    BRW_LAUNCH_TYPE_OUTSIDE_URL,
    BRW_LAUNCH_TYPE_OPEN_FILE,
    BRW_LAUNCH_TYPE_OUTSIDE_FILE,
    BRW_LAUNCH_TYPE_END
} brw_launch_type_enum;

/************************************************ENUM END************************************/

/************************************************STRUCT START************************************/
typedef struct
{
    U8 file_path[(SRV_FMGR_PATH_MAX_LEN+1) *ENCODING_LENGTH];
    S32 is_short;
} brw_file_detail_struct;

/* Structure for both the current certificate and trusted certificate */
typedef struct
{
    kal_uint8 issuer[256];
    kal_uint32 not_after;
    kal_uint32 not_before;
    kal_uint8 serial_num[128];
    kal_uint16 serial_num_len;
    kal_uint8 sig_alg_name[128];
    kal_uint8 subject[256];
    kal_uint8 type;
    kal_uint8 version;
} mmi_brw_certificate_content_struct;


typedef struct
{
    kal_uint16 key_exchange_alg;
    kal_uint8 blk_encrypt_alg;
    kal_uint8 hash_alg;
    kal_uint8 sec_conn_type;
} mmi_brw_get_session_info_rsp_struct;

#ifdef __MMI_URI_AGENT__
typedef struct
{
    srv_uriagent_appid_enum ura_appid;
    U8 url[SRV_BRW_MAX_URL_LEN + 1];
    srv_uriagent_uri_request_hdlr_cb uri_agent_cb;
} brw_uha_handler_struct;
#endif /* __MMI_URI_AGENT__ */


//TODO wrap this structure in Q05A
typedef struct
{
    U8 obj_name[(BRW_OBJECT_PROPERTIES_NAME_LEN + 1) *ENCODING_LENGTH];
    U8 obj_address[(BRW_OBJECT_PROPERTIES_ADDRESS_LEN + 1) *ENCODING_LENGTH];
    U8 obj_size[BRW_OBJECT_PROPERTIES_SIZE_LEN *ENCODING_LENGTH];
    U8 obj_date[BRW_OBJECT_PROPERTIES_DATE_LEN *ENCODING_LENGTH];
    U8 prop_status[BRW_OBJECT_PROP_MAX_COUNT];
    U8 prop_count;
} brw_object_properties_struct;



typedef struct
{
    MMI_BOOL isBrowserFetching;//app
    MMI_BOOL isBrowserWaiting;//app
    MMI_BOOL mainMenuEntryFlag; //app
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
    MMI_BOOL address_list_flag; // app
#endif /* __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */
    MMI_BOOL reset_hiliter_flag; //app
    MMI_BOOL view_cert_flag;//app
#ifdef OBIGO_Q05A
    MMI_BOOL encoding_type_new_flag;//app
#endif /* OBIGO_Q05A */
    MMI_BOOL select_mode_flag;//app
#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
    MMI_BOOL brw_first_page_flag;//app
#endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
    MMI_BOOL list_refresh_flag;//app
    MMI_BOOL is_wait_user_action;//app
#ifdef __MMI_FTE_SUPPORT__
    MMI_BOOL is_navigation_req_send; //app
#endif /* __MMI_FTE_SUPPORT__ */
    MMI_BOOL is_bearer_active;//app
#ifdef OBIGO_Q03C_BROWSER
    MMI_BOOL reload_req_processing;
    MMI_BOOL load_req_processing;
#endif
    /* settings fields status */
#ifdef __MMI_BRW_PAGE_FETCHING_STATUS__
    brw_fetching_status_enum page_fetching_status;//app
    U8 page_fetching_progress;//app
#endif /* __MMI_BRW_PAGE_FETCHING_STATUS__ */ 
#ifdef __MMI_OP12_BRW_EMBEDDED_LINKS__
    U16 fixed_menu_items;//app
#endif
    U16 wap_highlighted_menu;
    /* settings fields status */
    S32 index_highlighted_item; //app 
#ifdef __MMI_BRW_PAGE_SIZE_CHECKING__
    MMI_BOOL is_page_size_checked;//app
#endif 
#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
    /* File Upload Feature */
    mmi_brw_upload_status_enum upload_status;//app
    /* File Upload Feature */
#endif /* __MMI_BRW_FILE_UPLOAD_SUPPORT__ */
    brw_view_enum view_type;
#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
    U8 *user_input_url; //app
#endif /* #if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)*/
#ifdef OBIGO_Q05A
    brw_object_properties_struct brw_obj_properties;//app
#endif /* OBIGO_Q05A */
    U8 *requested_url_p; //app
    S8 *BrwAlwaysNeverStringArray[BRW_PREF_ALWAYS_NEVER_TOTAL];//app
    S8 *BrwEnableDisableStringArray[BRW_PREF_ENABLE_DISABLE_TOTAL];//app

    U8 BrwTimeoutValue[(BRW_TIME_OUT_LEN + 1) * ENCODING_LENGTH];//app
    U8 brw_hist_selected_url[(BRW_ADDRESS_LIST_URL_LENGTH) * ENCODING_LENGTH]; // app
    S32 brw_preferences[(BROWSER_PREFERENCES_ITEM_COUNT - CUI_INLINE_ITEM_ID_BASE)];//app
#ifdef OBIGO_Q05A
    mmi_brw_certificate_content_struct *current_cert_p;
    mmi_brw_get_session_info_rsp_struct *session_info_p;
#endif /* OBIGO_Q05A */
    mmi_brw_certificate_content_struct *trusted_cert_p; 
    brw_launch_type_enum launch_type;
    MMI_BOOL is_using_wifi;
#ifdef SLIM_WAP_MMS
    MMI_BOOL is_images_popup_shown;
#endif
} brw_app_dynamic_context_struct;



typedef struct
{
/* related to CUI */    
    MMI_ID brw_inline_cui_gid;
    MMI_ID brw_inline_cid;
    MMI_ID brw_scr_group_id;
    MMI_ID brw_menu_cui_gid;
    MMI_ID brw_menu_cid;	
    MMI_ID sel_bkm_cid;
    MMI_ID add_bkm_cid;	
    MMI_ID file_naming_rule_cid;	
    MMI_ID fseditor_cid;	
    MMI_ID file_selector_cui_gid;
    MMI_ID file_selector_cid;
/*end of CUI variable */
    U16 editor_scr_id; //app
    U16 top_scr_id; //app
    U32 file_mgr_instance; //app 
    brw_launching_pad_enum brw_launching_pad; //app
    brw_app_dynamic_context_struct *brw_dynamic_cntx_p; 
    srv_wap_prof_response_funcptr_type actv_prof_changed_cb; //srv
#ifdef __MMI_URI_AGENT__
    brw_uha_handler_struct *uha_info_p; //app
#endif 
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    mmi_id send_msg_cui_id; //app
#endif
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    brw_launching_pad_enum brw_launching_pad_for_OHS; //app
#endif
#ifdef __MMI_FTE_SUPPORT__
    brw_toolbar_enum brw_toolbar_launch_point; //app
#endif
#ifdef WAP_SEC_SUPPORT
    wps_show_confirm_dialog_ind_struct *sec_confirm_dlg_info_p; //app
#endif
#ifdef OBIGO_Q05A
    bam_charset_name_id_t *charset_list_p; //app
#endif /* OBIGO_Q05A */
    MMI_BOOL common_gateway_flag; //app
    MMI_BOOL is_resend_profile_required; //app
#ifdef __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__
    MMI_BOOL nine_way_mode;
#endif /* __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__ */
#if defined(__MMI_OP11_HOMESCREEN__)  || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    MMI_BOOL isBookmarkLaunched; //app
#endif
    MMI_BOOL sat_profile_update;
    MMI_BOOL allow_group_deleted;  //record if can close wap screen group
    MMI_ID close_evt;      // record the reason why wap screen group is closed
} brw_app_context_struct;


#ifdef __MMI_VBOOKMARK__
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
typedef struct
{
    U8 sel_folder_name[SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1];
    S32 sel_folder_index;
    U32 total_folder_count;
    S32 selected_file_index;
    MMI_BOOL is_first_level;
    srv_brw_bkm_bookmark_list_struct bookmark_list[SRV_BRW_BKM_MAX_COUNT];
    brw_bkm_folder_opeartion_enum folder_op_type;
} brw_bkm_dynamic_context_struct;
#endif

typedef struct
{
    U8 *sel_folder_name;
    S32 sel_file_index;
    U32 total_file_count;
    srv_brw_bkm_bookmark_list_struct bookmark_list[SRV_BRW_BKM_MAX_COUNT];
} brw_bkm_sel_bkm_cntx_struct;

typedef struct
{
    U8 sel_file_name[(SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) *ENCODING_LENGTH];
    U8 sel_file_url[(SRV_BRW_MAX_URL_LEN + 1) *ENCODING_LENGTH];
    U8 sel_folder_name[SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1];
    S32 sel_file_index;
    U32 total_file_count;
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    brw_bkm_dynamic_context_struct *bkm_dynamic_cntx;
#endif
    srv_brw_bkm_bookmark_list_struct bookmark_list[SRV_BRW_BKM_MAX_COUNT];
} brw_bkm_context_struct;


typedef struct
{
    U8 bookmark_name[(SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) *ENCODING_LENGTH];
    U8 bookmark_url[(SRV_BRW_MAX_URL_LEN + 1) *ENCODING_LENGTH];
    U8* selected_file_path;
    MMI_BOOL is_asm_taken;
} brw_ext_bkm_context_struct;
#endif /* __MMI_VBOOKMARK__ */

/************************************************STRUCT END************************************/


extern brw_app_context_struct g_brw_app_cntx;
extern void *g_brw_app_memory_pool;
extern U8 *g_brw_display_info_str;
extern U8 g_brw_current_url[(WAP_MAX_SEARCH_URL_LENGTH + 1) * ENCODING_LENGTH];
extern U8 g_brw_current_title[(SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH];
extern brw_file_detail_struct g_brw_open_file_cntx;

extern brw_ext_bkm_context_struct *g_brw_ext_bkm_cntx_p;
/* Inline CUI Structs */
extern const cui_inline_struct g_brw_bkm_initial_data_view_bookmark ;
extern const cui_inline_struct g_brw_bkm_initial_data_add_bookmark ;
extern const cui_inline_struct g_brw_bkm_initial_data_edit_bookmark ;
extern const cui_inline_struct g_brw_initial_data_obj_properties ;
extern const cui_inline_struct g_brw_ren_initial_data_auth ;
extern const cui_inline_struct g_brw_settings_pref ;
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
extern const cui_inline_struct g_brw_initial_data_edit_shortcut;
#endif
/* End of  Inline CUI Structs */

#ifdef OBIGO_Q05A
extern U8 g_brw_auth_dlg_save_option;
extern S8 *gBrwAuthDlgSaveOptionStringArray[BRW_APP_AUTH_DLG_SAVE_OPTION_TOTAL];
#endif /* OBIGO_Q05A */

#ifdef __MMI_VBOOKMARK__
extern brw_bkm_context_struct g_brw_bkm_cntx;
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
extern brw_bkm_sel_bkm_cntx_struct g_brw_bkm_sel_bkm_cntx;
extern MMI_BOOL g_brw_bkm_sel_bkm_pool;
#endif
extern U16 g_brw_bkm_scr_id;
extern brw_bkm_add_bookmark_enum g_brw_bkm_add_type;
extern brw_bkm_browse_path_enum g_brw_bkm_browse_path_event;
#endif /* __MMI_VBOOKMARK__ */

extern void *g_brw_memory_pool;

extern U8 g_brw_auth_username[(WAP_BAM_MAX_USER_PASSWD_LENGTH + 1) * ENCODING_LENGTH];
extern U8 g_brw_auth_password[(WAP_BAM_MAX_USER_PASSWD_LENGTH + 1) * ENCODING_LENGTH];

#endif /* __MMI_BROWSER_2__ */ 
#endif /* BROWSERAPPTYPES_H */ 

