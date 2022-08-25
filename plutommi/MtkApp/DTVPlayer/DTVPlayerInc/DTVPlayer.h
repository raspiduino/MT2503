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
 *  DTVPlayer.h
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files
*****************************************************************************/
#ifndef _MMI_DTV_PLAYER_H_
#define _MMI_DTV_PLAYER_H_

#include "mmi_features.h"

#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__

#include "mmi_rp_app_dtv_player_def.h"
#include "DTVPlayerEnum.h"
#include "DTVPlayerOSD.h"
#include "DTVPlayerGprot.h"
#include "FileMgrSrvGProt.h"
#include "BrowserSrvGprot.h"
#include "DLAgentSrvDef.h"

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
#include "mdi_datatype.h"
#include "mdi_mtv.h"
#include "gui_windows.h"
#include "gui_typedef.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "BtcmSrvGprot.h"
#include "gdi_const.h"
#include "gdi_features.h"
#include "common_nvram_editor_data_item.h"
#ifdef __MBBMS_V30_OPERA__
#include "opera_webview_api.h"
#endif

#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
#include "cmmb_2gppadp.h"
#endif

#define __MMI_DTV_AUDIO_CHANNEL_SUPPORT__

#define STR_ID_DTV_PLAYER_NULL 0
#define IMG_ID_DTV_PLAYER_NULL 0

#define MMI_DTV_NAME_STR_LENGTH 64
#define MMI_DTV_CITY_STR_LEN (20)
#define MMI_DTV_TIME_STR_LENGTH 14
#define MMI_DTV_DATE_TIME_STR_LENGTH 20
#define MMI_DTV_DATE_TYPE_STR_LENGTH 32
#define MMI_DTV_DESC_STR_LENGTH 32
#define MMI_DTV_DATE_PRICE_STR_LENGTH 32
#define MMI_DTV_INFO_STR_LENGTH 200
#define MMI_DTV_TEXT_STR_LENGTH 128

#define MMI_DTV_JUMP_TO_CHANNEL_DELAY 2000

#define MMI_DTV_PROG_LIST_DAY_NUM (8)
#define MMI_DTV_PROG_LIST_DAY_LEN (11) /* xx-xx or xxxx-xx-xx */
#define MMI_DTV_STORAGE_TOTAL_COUNT (2)


#define MMI_DTV_MAX_PORT_LEN                  (6)        /* 0 - 65535 */
#define MMI_DTV_MAX_IP_LEN                    (3)        /* xxx */
#define MMI_DTV_MAX_KEYWORD_LEN               (20)
#define MMI_DTV_MAX_PREVIEW_TEXT_LEN          (20)
#define MMI_DTV_MAX_SEARCH_DATE               (4)
#define MMI_DTV_MAX_FREQUENCY_LEN             (12)
/***************************************
* Hint Box
***************************************/
#define MMI_DTV_PLAYER_HINT_POPUP_FADE_TIME          (1200)
#define MMI_DTV_PLAYER_HINT_POPUP_NO_FADE            (999)
#define MMI_DTV_PLAYER_OSD_FADE_OUT_TIME       (3*1000) /* 3 sec */
#define MMI_DTV_PLAYER_OSD_FADE_OUT_VALUE      (32)     /* fade 32/256 */

#define MMI_DTV_PLAYER_UPDATE_SIGNAL_DURATION (2000)
#define MMI_DTV_PLAYER_MINIMAL_MAX_DELAY_TO_START_TS (2000)
#define MMI_DTV_PLAYER_TS_ENABLE_DURATION (5000) /* msec */
#define MMI_DTV_PLAYER_TS_DELAY_DURATION (16000) /* msec */
#define MMI_DTV_PLAYER_TS_BAR_DELAY_DURATION (2000) /* msec */
#define MMI_DTV_PLAYER_OSD_FADEOUT_FACTOR (255)
#define MMI_DTV_PLAYER_SERVICE_TIMEOUT_DURATION (90000) /* msec */
#define MMI_DTV_PLAYER_DISPLAY_ACCESS_DENIED_DURATION (15000) /* msec */
#define MMI_DTV_PLAYER_VOL_ICON_DURATION (5000) /* msec */
/****************************************
* inter description display
****************************************/
#define MMI_DTV_PLAYER_INTER_DESC_SCROLL_TIMES (2)
#define MMI_DTV_PLAYER_INTER_DESC_DELAY_SECONDS (5000) /*msec*/

#if defined(__MMI_FTE_SUPPORT__)
extern void mmi_dtv_player_vol_idx_icon_press(void);
extern void mmi_dtv_player_vol_idx_icon_release(void);
extern void mmi_dtv_player_vol_bg_icon_press(void);
extern void mmi_dtv_player_vol_bg_icon_release(void);
extern void mmi_dtv_player_hide_fte_vol_icon(void);
extern void mmi_dtv_player_update_vol_level(S32 pos_x);
extern void mmi_dtv_player_draw_fte_vol_icon(void);
#endif /* __MMI_FTE_SUPPORT__ */

#define MMI_DTV_PLAYER_ESG_TIMEOUT_DURATION (60000) /* msec */

/***************************************
* Mobile TV Setting Structure
***************************************/
#define MMI_DTV_PLAYER_BRIGHTNESS_ADJ_LEVEL_COUNT (11)       /* -5, -4, ...0 , +4, +5 */
#define MMI_DTV_PLAYER_CONTRAST_ADJ_LEVEL_COUNT   (11)       /* -5, -4, ...0 , +4, +5 */
#define MMI_DTV_PLAYER_SIMCARD_COUNT (2) /* Simcard1 , Simcard2 */

/***************************************
* Mobile TV Emergency Broadcast Type
***************************************/
#define DTV_PLAYER_EB_TYPE_SYSTEM_TEST_1 0
#define DTV_PLAYER_EB_TYPE_SYSTEM_TEST_2 32
#define DTV_PLAYER_EB_TYPE_SYSTEM_TEST_3 64
#define DTV_PLAYER_EB_TYPE_SYSTEM_TEST_4 96
#define DTV_PLAYER_EB_TYPE_NATURAL_DISASTER_START 1
#define DTV_PLAYER_EB_TYPE_NATURAL_DISASTER_END 7
#define DTV_PLAYER_EB_TYPE_ACCIDENT_DISASTER_START 33
#define DTV_PLAYER_EB_TYPE_ACCIDENT_DISASTER_END 36
#define DTV_PLAYER_EB_TYPE_PUBLIC_HEALTH_DISASTER_START 65
#define DTV_PLAYER_EB_TYPE_PUBLIC_HEALTH_DISASTER_END 68
#define DTV_PLAYER_EB_TYPE_PUBLIC_SOCIAL_SECURITY_START 97
#define DTV_PLAYER_EB_TYPE_PUBLIC_SOCIAL_SECURITY_END 100


#define KERNEL_STATE_IN(_STATE_) (dtv_player_p->kernel_state==_STATE_)
#define KERNEL_ENTER_STATE(_STATE_) \
    do{\
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_KERNEL_STATE, dtv_player_p->kernel_state, _STATE_);\
        dtv_player_p->kernel_prev_state=dtv_player_p->kernel_state;\
        dtv_player_p->kernel_state=_STATE_;\
    }while(0)

#define PLAYER_STATE_IN(_STATE_) (dtv_player_p->player_state==_STATE_)
#define PLAYER_ENTER_STATE(_STATE_) \
    do{\
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_PLAYER_STATE, dtv_player_p->player_state, _STATE_);\
        dtv_player_p->player_prev_state=dtv_player_p->player_state;\
        dtv_player_p->player_state=_STATE_;\
    }while(0)

#define RECORDER_STATE_IN(_STATE_) (dtv_player_p->recorder_state==_STATE_)
#define RECORDER_ENTER_STATE(_STATE_) \
    do{\
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_RECORDER_STATE, dtv_player_p->recorder_state, _STATE_);\
        dtv_player_p->recorder_prev_state=dtv_player_p->recorder_state;\
        dtv_player_p->recorder_state=_STATE_;\
    }while(0)

#define DTV_FULL_DLS_ICON_SPACE 6
#define DTV_FULL_DLS_INTER_NUM_STR_SPACE 30

/* Menu icon */
#ifdef __COSMOS_MMI_PACKAGE__
    #define DTV_PLAYER_MENU_ICON (IMG_ID_DTV_PLAYER_APP_MENU_ICON)
#else
    #define DTV_PLAYER_MENU_ICON (GetRootTitleIcon(MENU_ID_DTV_PLAYER_APP))
#endif

typedef enum
{
    DTV_PLAYER_UPDATE_AUTO,
    DTV_PLAYER_UPDATE_SPECIFY_CITY,
    DTV_PLAYER_UPDATE_APPROACH_NUM
} dtv_player_update_approach_enum;

typedef struct
{

    CHAR *update_approach_str[DTV_PLAYER_UPDATE_APPROACH_NUM];
    CHAR *service_name_str[MMI_DTV_MAX_SERVICES + 1];
    CHAR *search_date_str[MMI_DTV_MAX_SEARCH_DATE];

}dtv_player_menu_context_struct;

typedef enum
{
    DTV_PLAYER_PLAY_SPEED_10X = 0,
    DTV_PLAYER_PLAY_SPEED_20X,
    DTV_PLAYER_PLAY_SPEED_5X,

    DTV_PLAYER_PLAY_SPEED_TOTAL_COUNT
} dtv_player_setting_play_speed_enum;

/***************************************
* Mobile TV Setting Structure
***************************************/
#define MMI_DTV_PLAYER_STORAGE_FILEPATH            FMGR_DEFAULT_FOLDER_VIDEO
#ifdef __COSMOS_MMI_PACKAGE__
#define MMI_DTV_PLAYER_STORAGE_FILEPATH_PHOTOS     L"Shootings\\"
#else
#define MMI_DTV_PLAYER_STORAGE_FILEPATH_PHOTOS     FMGR_DEFAULT_FOLDER_PHOTOS
#endif
#define MMI_DTV_PLAYER_APN_LENGTH (20)
#define MMI_DTV_PLAYER_RADIO_NUM (2)

typedef enum
{
    DTV_PLAYER_STORAGE_PATH_VIDEO = 0,
    DTV_PLAYER_STORAGE_PATH_PHOTO,

    DTV_PLAYER_STORAGE_PATH_COUNT
} dtv_player_storage_path_enum;


typedef enum
{
    DTV_PLAYER_SETTING_BRIGHTNESS = 0,
    DTV_PLAYER_SETTING_CONTRAST,
    DTV_PLAYER_SETTING_SATURATION,
    DTV_PLAYER_SETTING_AUDIO_MODE,
    DTV_PLAYER_SETTING_RECORD_SIZE,
    DTV_PLAYER_SETTING_ITEM_COUNT
} dtv_player_setting_count_enum;

typedef enum
{
    DTV_PLAYER_STORAGE_OK = 0,
    DTV_PLAYER_STORAGE_NOT_READY, /* Folder is not yet created */
    DTV_PLAYER_STORAGE_RESET, /* Drive is not yet mounted */
    DTV_PLAYER_STORAGE_TOTAL_COUNT
}dtv_player_storage_status_enum;

typedef enum
{
    DTV_PLAYER_DYNAMIC_LABEL_OFF = 0,
    DTV_PLAYER_DYNAMIC_LABEL_ON,
    DTV_PLAYER_DYNAMIC_LABEL_SCROLLING
}dtv_player_dynamic_label_state_enum;


/***************************************
* Icon Structure
***************************************/
typedef enum
{
    DTV_PLAYER_VOL_MUTE, /* 0 */
    DTV_PLAYER_VOL_1,
    DTV_PLAYER_VOL_2,
    DTV_PLAYER_VOL_3,
    DTV_PLAYER_VOL_4,
    DTV_PLAYER_VOL_5,
    DTV_PLAYER_VOL_6,
    DTV_PLAYER_VOL_7,
    DTV_PLAYER_VOL_8,
    DTV_PLAYER_VOL_9,
    DTV_PLAYER_VOL_10,
    DTV_PLAYER_VOL_11,
    DTV_PLAYER_VOL_12,
    DTV_PLAYER_VOL_13,
    DTV_PLAYER_VOL_14,
    DTV_PLAYER_VOL_15,
    DTV_PLAYER_VOL_16
} dtv_player_aud_vol_enum;

typedef enum
{
    DTV_PLAYER_TOUCH_NONE = 0,
    DTV_PLAYER_TOUCH_PLAY,
    DTV_PLAYER_TOUCH_RECORD,
    DTV_PLAYER_TOUCH_CYCLE,
    DTV_PLAYER_TOUCH_FULLSCREEN,
    DTV_PLAYER_TOUCH_FORWARD,
    DTV_PLAYER_TOUCH_REWIND,
    DTV_PLAYER_TOUCH_VOL_INC,
    DTV_PLAYER_TOUCH_VOL_DEC,
    DTV_PLAYER_TOUCH_CHANNEL_NEXT,
    DTV_PLAYER_TOUCH_CHANNEL_PREV,
    DTV_PLAYER_TOUCH_CHANGE,
    DTV_PLAYER_TOUCH_TS_BAR,

    DTV_PLAYER_TOUCH_LSK,
    DTV_PLAYER_TOUCH_RSK,
    DTV_PLAYER_TOUCH_VOL_BG,
    DTV_PLAYER_TOUCH_VOL_IDX,
    DTV_PLAYER_TOUCH_VOL_STATUS,
    DTV_PLAYER_TOUCH_VIEW
} dtv_player_touch_icon_enum;


typedef enum
{
    DTV_PLAYER_TOTAL_LIST,
    DTV_PLAYER_FAVORITE_LIST,
#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
	DTV_PLAYER_ACCOUNT_MANAGE_TEXT,
	DTV_PLAYER_SERVICE_LIST_TYPE_NUM,
	DTV_PLAYER_PROG_REMINDER_LIST
#else
    DTV_PLAYER_PROG_REMINDER_LIST,    
    DTV_PLAYER_SERVICE_LIST_TYPE_NUM
#endif
} dtv_player_service_list_type_enum;


typedef enum
{
    DTV_PLAYER_SUBSCRIBED_ORDER_LIST,
    DTV_PLAYER_UNSUBSCRIBED_ORDER_LIST,
    DTV_PLAYER_MO_LIST_TYPE_NUM
} dtv_player_mo_list_type_enum;

typedef enum
{
    DTV_PLAYER_CITY_LIST_RECOMMEND,
    DTV_PLAYER_CITY_LIST_LEVEL_1,
    DTV_PLAYER_CITY_LIST_LEVEL_2,
    DTV_PLAYER_CITY_LIST_LEVEL_3,
    DTV_PLAYER_CITY_LIST_NUM
} dtv_player_city_list_type_enum;

typedef enum
{
    MMI_DTV_SGDD_WELCOME_INFO,
    MMI_DTV_SGDD_AREA_NAME
} dtv_player_sgdd_info_enum;

typedef enum
{
    MMI_DTV_OSD_MODE_CHANNEL,
    MMI_DTV_OSD_MODE_TIME_SHIFT
} mtv_osd_mode_enum;


typedef enum
{
    DTV_PLAYER_HINT_STATE_HIDE,
    DTV_PLAYER_HINT_STATE_SHOW_TRUNCATED,
    DTV_PLAYER_HINT_STATE_FADING_TRUNCATED,
    DTV_PLAYER_HINT_STATE_SHOW_MULTILINE,
    DTV_PLAYER_HINT_STATE_FADING_MULTILINE
} dtv_player_hint_state_enum;

#ifdef __MBBMS_DUAL_SIM_SUPPORT__
typedef enum
{
	DTV_PLAYER_SIM1,
	DTV_PLAYER_SIM2,
	DTV_PLAYER_SIMCARD_NUM
}dtv_player_simcard_count_enum;

#define DTV_PLAYER_OTHER_SIM(x) ((MMI_SIM1 == x) ? (MMI_SIM2):(MMI_SIM1))
#endif
typedef enum
{
    MMI_DTV_TEST_MODE_SET_CAPTION = CUI_INLINE_ITEM_ID_BASE+1,
	MMI_DTV_TEST_MODE_SET_EDIT		
}dtv_player_test_mode_setting_enum;


typedef enum
{
    MMI_DTV_BRIGHTNESS_CAPTION = CUI_INLINE_ITEM_ID_BASE+1,
    MMI_DTV_BRIGHTNESS_SELECTOR,
    MMI_DTV_CONTRAST_CAPTION,
    MMI_DTV_CONTRAST_SELECTOR,
#ifdef __MBBMS_DUAL_SIM_SUPPORT__
	MMI_DTV_SIMCARD_CAPTION,
	MMI_DTV_SIMCARD_SELECTOR,
#endif
    MMI_DTV_RECORD_SIZE_CAPTION,
    MMI_DTV_RECORD_SIZE_SELECTOR,

    /* MBBMS: Channel list settings */
    MMI_DTV_PROGRAM_REMIND_TIME_CAPTION,
    MMI_DTV_PROGRAM_REMIND_TIME_SELECTOR,
    MMI_DTV_INTER_ARRIVE_CAPTION,
    MMI_DTV_INTER_ARRIVE_CHECK_BOX,
    MMI_DTV_USER_LOC_INFO_CAPTION,
    MMI_DTV_USER_LOC_INFO_RADIO_LIST,
    MMI_DTV_CLIENT_UPGRADE_CAPTION = MMI_DTV_USER_LOC_INFO_RADIO_LIST + MMI_DTV_PLAYER_RADIO_NUM,
    MMI_DTV_DETECT_NEW_DISPLAY_ONLY,
    MMI_DTV_DATA_ACCOUNT_CAPTION,
    MMI_DTV_DATA_ACCOUNT_SELECTOR,
    MMI_DTV_USE_PROXY_CAPTION,
    MMI_DTV_USE_PROXY_SELECTOR,
    MMI_DTV_PROXY_SERVER_CAPTION,
    MMI_DTV_PROXY_SERVER_IP4,
    MMI_DTV_PROXY_PORT_CAPTION,
    MMI_DTV_PROXY_PORT_TEXT_EDIT,
    MMI_DTV_SG_SERVER_CAPTION,
    MMI_DTV_SG_SERVER_TEXT_EDIT,
    MMI_DTV_SG_SERVER_PORT_CAPTION,
    MMI_DTV_SG_SERVER_PORT_TEXT_EDIT,

    /* MBBMS: Search program */
    MMI_DTV_KEYWORD_CAPTION,
    MMI_DTV_KEYWORD_TEXT_EDIT,
    MMI_DTV_CHANNEL_CAPTION,
    MMI_DTV_CHANNEL_SELECTOR,
    MMI_DTV_DATE_CAPTION,
    MMI_DTV_DATE_SELECTOR
}dtv_player_setting_enum;


typedef enum
{
    DTV_PLAYER_EB_LEVEL_1 = 1,
    DTV_PLAYER_EB_LEVEL_2,
    DTV_PLAYER_EB_LEVEL_3,
    DTV_PLAYER_EB_LEVEL_4,
    DTV_PLAYER_EB_LEVEL_NUM
} dtv_player_eb_msg_level_enum;

typedef enum
{
    DTV_PLAYER_PROG_REMIND_0,
    DTV_PLAYER_PROG_REMIND_2,
    DTV_PLAYER_PROG_REMIND_5,
    DTV_PLAYER_PROG_REMIND_10
} dtv_player_prog_reminder_time_enum;

typedef enum
{
    DTV_PLAYER_PROCESS_TYPE_GBA,  /* MTS */
    DTV_PLAYER_PROCESS_TYPE_SUBSCRIPTION_UPDATE,   /* MTS */
    DTV_PLAYER_PROCESS_TYPE_MSK_RETRIEVE,  /* MTS */
    DTV_PLAYER_PROCESS_TYPE_SUBSCRIBE,
    DTV_PLAYER_PROCESS_TYPE_UNSUBSCRIBE,
    DTV_PLAYER_PROCESS_TYPE_ACCOUNT_INQUIRY,
    DTV_PLAYER_PROCESS_TYPE_UPGRADE_QUERY,
    DTV_PLAYER_PROCESS_TYPE_AREA_SET_RETRIEVE,
    DTV_PLAYER_PROCESS_TYPE_INTERACTIVITY_RETRIEVE,
    DTV_PLAYER_PROCESS_TYPE_NUM
} dtv_player_process_type_enum;

typedef enum
{
    DTV_PLAYER_DL_STATE_CLOSED,
    DTV_PLAYER_DL_STATE_OPENED,
    DTV_PLAYER_DL_STATE_DOWNLOADING
} dtv_player_dl_state_enum;

typedef enum
{
    DTV_PLAYER_PREVIEW_STATE_NONE,
    DTV_PLAYER_PREVIEW_STATE_WAIT_DECODE,
    DTV_PLAYER_PREVIEW_STATE_DECODED
} dtv_player_preview_img_state_enum;

typedef enum
{
    DTV_PLAYER_RADIO_LIST_AUTO,
    DTV_PLAYER_RADIO_LIST_MANUAL,
    DTV_PLAYER_RADIO_NUM
} dtv_player_radio_list_enum;

typedef enum
{
	DTV_PLAYER_INTER_DETAIL_PRE,
	DTV_PLAYER_INTER_DETAIL_NEXT,
	DTV_PLAYER_INTER_DETAIL_TOTAL
}dtv_player_inter_detail_enum;

typedef enum
{
    DTV_PLAYER_INT_STATE_OFF,
    DTV_PLAYER_INT_STATE_ONE_LINE,
    DTV_PLAYER_INT_STATE_HALF_SCREEN
} dtv_player_int_state_enum;

#ifdef __MBBMS_V30_OPERA__
typedef enum
{
    DTV_PLAYER_OPERA_INIT = 0,
    DTV_PLAYER_OPERA_START = 1,
    DTV_PLAYER_OPERA_SHOW_PAGE = 1 << 1,
    DTV_PLAYER_OPERA_IME = 1 << 2,
}dtv_player_opera_state_enum;
#endif /* __MBBMS_V30_OPERA__ */

typedef enum
{
	DTV_CMMB_TEST_MODE_OFF,
	DTV_CMMB_TEST_MODE_FACTORY,
	DTV_CMMB_TEST_MODE_ON_SITE,
	DTV_CMMB_TEST_MODE_NUM
}dtv_player_test_mode_enum;

extern kal_bool g_mtv_mts_command;


typedef struct
{
    U8       remind_time;
    U8       use_proxy;
    U8       cbm_app_id;
    U8       *mem_buff;
    MMI_ID   inline_gid;
    U32      hilite;
    U32      sg_proxy_port;
    U32      proxy_port;
    U32      data_account_id;
    U32      data_account_idx;
    MMI_BOOL manual_set_loc;
    MMI_BOOL inter_auto_popup;
    CHAR     data_account_name[(MAX_DATA_ACCOUNT_NAME_WITH_SUFFIX_LEN + 1)*ENCODING_LENGTH];
    CHAR     proxy_server[MMI_DTV_PLAYER_PROXY_IP_COUNT];
    WCHAR    sg_proxy_server[MMI_DTV_MAX_SG_ADDR_LEN];
}dtv_player_cl_setting_struct;

/* Remember to enlarge MMI_DTV_MAX_SERVICE_INFO_STRUCTURE_SIZE */
typedef struct dtv_player_service_info_struct_t
{
    U32 service_id;
    U32 service_number;
    mdi_mtv_service_type_enum service_type;
    S32 service_flags;
    WCHAR service_name[MMI_DTV_NAME_STR_LENGTH + 1];
    MMI_BOOL is_favorite;
    MMI_BOOL has_preview_data;
    struct dtv_player_service_info_struct_t *next; /* Next favorite service */
    struct dtv_player_service_info_struct_t *prev; /* Prev favorite service */
#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
	U32 frequency;    /*  IBIO need this data to collect statitics */
#endif

    WCHAR program_name[MMI_DTV_NAME_STR_LENGTH + 1];
    WCHAR program_time[MMI_DTV_TIME_STR_LENGTH + 1]; /* HH:MM - HH:MM */
} dtv_player_service_info_struct;



/* Remember to enlarge MMI_DTV_MAX_SCHEDULE_INFO_STRUCTURE_SIZE */
typedef struct
{
    WCHAR date[MMI_DTV_TIME_STR_LENGTH + 1]; /* yyyy-mm-dd */
    WCHAR time[MMI_DTV_TIME_STR_LENGTH + 1]; /* hh:mm-hh:mm */
    WCHAR name[MMI_DTV_NAME_STR_LENGTH + 1];
    U16 content_id;
    kal_char cid[MBBMS_SG_ID_LEN + 1];
    U32 service_id;
    MMI_BOOL if_reminder;
    MMI_BOOL has_inter_data;
} dtv_player_schedule_info_struct;

/* Remember to enlarge MMI_DTV_MAX_SCHEDULE_INFO_STRUCTURE_SIZE */
typedef struct
{
    kal_char cid[MBBMS_SG_ID_LEN + 1];
    U32 service_id;
    kal_wchar date[MMI_DTV_TIME_STR_LENGTH + 1]; /* 2010-10-28*/
    kal_wchar time[MMI_DTV_TIME_STR_LENGTH + 1]; /* 01:02-03:04*/

    /* Only for PD screen */
    WCHAR name[MMI_DTV_NAME_STR_LENGTH + 1];
} dtv_player_content_struct;

typedef struct
{
    kal_char id[MBBMS_SG_ID_LEN + 1];
    kal_char gid[MBBMS_SG_ID_LEN + 1];
    WCHAR name[MMI_DTV_NAME_STR_LENGTH + 1];
    U8 type;
    U8 period;
    float price;
    MMI_BOOL subscribed;
    MMI_BOOL local;
} dtv_player_order_struct;

typedef struct
{
    kal_char id[MBBMS_SG_ID_LEN + 1];
    kal_char gid[MBBMS_SG_ID_LEN + 1];
    WCHAR name[MMI_DTV_NAME_STR_LENGTH + 1];
    WCHAR desc[MMI_DTV_DESC_STR_LENGTH + 1];
    U8 type;
    U8 period;
    float price;
} dtv_player_account_struct;

typedef struct
{
    WCHAR name[MMI_DTV_CITY_STR_LEN + 1];
} dtv_player_city_struct;

typedef struct
{
    U32 id;
    WCHAR name[MMI_DTV_CITY_STR_LEN + 1];
} dtv_player_display_city_struct;

/* Remember to enlarge MMI_DTV_MAX_INTER_LIST_STRUCTURE_SIZE */
typedef struct
{
    MMI_BOOL read;
    WCHAR desc[MMI_DTV_TEXT_STR_LENGTH + 1];
} dtv_player_inter_list_struct;

/* Remember to enlarge MMI_DTV_MAX_EB_MESSAGE_STRUCTURE_SIZE */
typedef struct
{
    U32 id;

    U8 msg_level;
    MMI_BOOL is_new;
    WCHAR receive_time[MMI_DTV_DATE_TIME_STR_LENGTH + 1];
    WCHAR text[MMI_DTV_TEXT_STR_LENGTH + 1];
} dtv_player_eb_msg_struct;

typedef struct
{
    MMI_BOOL target;

    S32 service_id;
    kal_char cid[MBBMS_SG_ID_LEN + 1];
    WCHAR name[MMI_DTV_NAME_STR_LENGTH + 1]; /* Program name */
    applib_time_struct remind_time;
} dtv_player_prog_reminder_struct;

typedef struct
{
    MMI_ID option_menu_gid;
    MMI_ID cl_option_menu_gid; /* Channel list option   */
    MMI_ID pl_option_menu_gid; /* Program list optoin   */
    MMI_ID mo_option_menu_gid; /* Manage order option   */
    MMI_ID eb_option_menu_gid; /* EB list option        */
    MMI_ID pd_option_menu_gid; /* Program detail option */
    MMI_ID sc_option_menu_gid; /* Specify city option   */
    MMI_ID sr_option_menu_gid; /* Search result option  */
    MMI_ID ps_inline_gid;      /* Player setting inline */
    MMI_ID setting_inline_gid; /* setting inline        */
    MMI_ID sp_inline_gid;      /* search program inline */
#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
	MMI_ID help_2gpp_select_item;
	MMI_BOOL rescan_notify;
#endif

    dtv_player_storage_status_enum storage_status;
    dtv_player_storage_status_enum prev_storage_status;
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
    /* osd layer */
    gdi_handle osd_layer_handle;
    PU8 osd_layer_buf_ptr;
    PU8 osd_layer_buf_ptr_2;

    /* dls layer */
    gdi_handle dls_layer_handle;
    PU8 dls_layer_buf_ptr;

    /* status_bar_layer_handle */
    gdi_handle status_bar_layer_handle;
    PU8 status_bar_buf_ptr;

    U32 blt_layer_flag;
    
    WCHAR hint1_buf[MMI_DTV_NAME_STR_LENGTH + 1];
    WCHAR hint2_buf[MMI_DTV_NAME_STR_LENGTH + 1];
    U16 fade_time;
    dtv_player_hint_state_enum hint_state;

    mmi_dtv_player_app_state_enum app_prev_state;
    mmi_dtv_player_app_state_enum app_state;
    mmi_dtv_player_app_state_enum app_next_state;

    mmi_dtv_player_kernel_state_enum kernel_prev_state;
    mmi_dtv_player_kernel_state_enum kernel_state;
    mmi_dtv_player_kernel_state_enum kernel_next_state;

    mmi_dtv_player_player_state_enum player_prev_state;
    mmi_dtv_player_player_state_enum player_state;
    mmi_dtv_player_player_state_enum player_next_state;

    mmi_dtv_player_recorder_state_enum recorder_prev_state;
    mmi_dtv_player_recorder_state_enum recorder_state;
    mmi_dtv_player_recorder_state_enum recorder_next_state;

    dtv_player_service_info_struct * services; /* [MMI_DTV_MAX_SERVICES] */
    U16 num_services;
    U8 scan_progress;
    U8 highlighted_order;
    U8 temporal_channel;
    dtv_player_service_list_type_enum service_list_type;
    dtv_player_dl_state_enum dl_state;
    dtv_player_process_type_enum process_type;
    MMI_BOOL auto_launch;
    mtv_osd_mode_enum osd_mode;
    dtv_player_service_info_struct *head_of_favorite_service;
    U16 num_favorite_services;
    MMI_BOOL has_esg_info;
    dtv_ca_state_enum ca_state;	
    MMI_BOOL display_mts_menu;
    MMI_BOOL is_favorite_list_org;	
    dtv_player_schedule_info_struct *schedules; /* MMI_DTV_MAX_SCHEDULES */
    S16 sche_start_idx;
    S16 sche_end_idx;
    U16 num_schedules;	
    U8 *cat1023_his_buf;
    dtv_player_eb_msg_struct *eb_msg; /* [MMI_DTV_MAX_EB_MSG] */
    U16 num_eb_msg;
    dtv_player_order_struct *orders; /* MMI_DTV_MAX_ORDERS */
    dtv_player_account_struct *account; /* [MMI_DTV_MAX_ACCOUNT] */
    U16 num_orders;
    U16 num_subscribed_orders;
    U16 num_accounts;
    dtv_player_order_struct selected_order;
    U32 selected_eb_id;
    U32 num_unread_ebs;
    U16 num_order_msg;
    U8 order_index;
    dtv_player_schedule_info_struct selected_content;
    S32 language_type;
    CHAR *detail_buf;
    applib_time_struct entry_prog_list_time;
    U32 prog_list_hilight_idx;
    dtv_player_preview_img_state_enum preview_state;
    WCHAR keyword[MMI_DTV_MAX_KEYWORD_LEN];
    WCHAR preview_text[MMI_DTV_MAX_PREVIEW_TEXT_LEN + 1];
    U8 search_channel_idx;
    U8 search_date_idx;
    applib_time_struct search_time;
    WCHAR pl_date[MMI_DTV_PROG_LIST_DAY_NUM][MMI_DTV_PROG_LIST_DAY_LEN]; /* xx-xx or xxxx-xx-xx */
    WCHAR *pl_date_ptr[MMI_DTV_PROG_LIST_DAY_NUM];
    mdi_mtv_program_info_struct prog_info;
    dtv_player_mo_list_type_enum mo_list_type;
    S32 update_approach;
    HILITE_STR hilite_str;
    applib_time_struct remind_time;
	applib_time_struct play_status_time;	
    WCHAR snapshot_filename[(SRV_FMGR_PATH_BUFFER_SIZE + 1) >> 1];
    WCHAR city[MMI_DTV_CITY_STR_LEN + 1];
    WCHAR info_str_buffer[MMI_DTV_INFO_STR_LENGTH + 1];
    S32 selected_storage;
    CHAR *storage_str[MMI_DTV_STORAGE_TOTAL_COUNT]; 
    srv_fmgr_drv_type_enum storage_type[MMI_DTV_STORAGE_TOTAL_COUNT];
    
    S32 prev_selected_service;
    MDI_RESULT last_error;
    MMI_ID_TYPE err_str_id;
    MDI_RESULT delayed_record_error;

    dtv_player_layout_struct *active_osd_cntx_p;
    dtv_player_touch_icon_enum touch_object;
    nvram_dtv_player_setting_struct setting;
    dtv_player_cl_setting_struct cl_setting;
    /* scrolling label */
    scrolling_text scrolling_label;
    dtv_player_dynamic_label_state_enum dynamic_label_state;
    WCHAR label_str[MMI_DTV_TEXT_STR_LENGTH + 1];

    U32 delay_step;
    U32 play_delay;
    U32 max_delay;
    U32 max_timeshift_delay;
    MMI_BOOL is_timeshift_enable;

    U32 signal_strength;
    U16 fullscr_osd_opacity ;
    dtv_player_bool_status_enum bool_state;
    MMI_BOOL is_tvout_fullscreen;
    U8 te_ctrl_handle;

    MMI_BOOL is_key_pressed;
    MMI_BOOL is_ts_bar_enable;
    MMI_BOOL is_setting_loaded;
    MMI_BOOL is_bt_connecting;
    MMI_BOOL is_recorder_error;
    MMI_BOOL is_ready_to_ts;
    MMI_BOOL is_capture;

    MMI_BOOL is_before_cat265;
    MMI_BOOL is_channel_changed;
    MMI_BOOL is_changing_channel_by_key;
    U16   change_to_channel;

    gdi_handle anim_handle;
    gdi_handle bt_connect_amin_handle;
	gdi_handle eb_amin_handle;
    gdi_handle radio_amin_handle;

#ifdef __MMI_TOUCH_SCREEN__
    S32 pen_down_x;
    S32 pen_down_y;
    MMI_BOOL is_pen_down;
    S32 movement_x;
    S32 movement_y;
#endif

    gdi_handle cl_preview_layer_handle;
    U32 cl_blt_layer_flag;
    U32 cl_preview_layer_flag;
    S32 cl_preview_layer_offset_x;
    S32 cl_preview_layer_offset_y;
    S32 cl_preview_layer_width;
    S32 cl_preview_layer_height;

#if defined(__MMI_DTV_A2DP_SUPPORT__)
    U32 aud_sample_rate;
    U32 aud_channel_num;
#endif

/* __MBBMS_DUAL_SIM_SUPPORT__ */
    mmi_sim_enum cur_sim;
/* #endif */
    /* support app screen process when exit for back key */
    MMI_BOOL frequency_setting;
#ifdef __MBBMS_CITY_LIST__
dtv_player_display_city_struct selected_city[DTV_PLAYER_CITY_LIST_NUM];
dtv_player_city_struct *recommend_city; 
dtv_player_display_city_struct *display_city; 
U16 num_recommend_city;
U16 num_display_citys;
dtv_player_city_list_type_enum city_list_type;
S32 if_rememeber_location;
#endif /* __MBBMS_CITY_LIST__ */

#ifdef __MBBMS_UPGRADE__
U16 upgrade_type;
MMI_ID upgrade_confirm_id;
#endif /* __MBBMS_UPGRADE__ */

#ifdef __MBBMS_INTER__
dtv_player_inter_list_struct *inter_list; 
dtv_player_int_state_enum int_state;
U32 num_imd;
U32 num_unread_imd;
U32 imd_display_desc;
U32 selected_imd;
scrolling_text scrolling_inter_des;
U8			   scroll_inter_times;
dtv_player_dynamic_label_state_enum dynamic_inter_state;
#endif /* __MBBMS_INTER__ */

#ifdef __MBBMS_V30_OPERA__
    opera_webview_rect opera_page_rect;
    U16 opera_engine_state;
    opera_webview_ctx opera_engine_context;
    gdi_handle restore_layer;
    MMI_BOOL opera_engine_blt_flag;
    gdi_handle opera_layer_handle;
    PU8 opera_layer_buf_ptr;
	U32 opera_display_imd_index;
	MMI_BOOL need_open_url;
    CHAR folder_path[(SRV_FMGR_PATH_MAX_LEN+1) *ENCODING_LENGTH];
#endif /* __MBBMS_V30_OPERA__ */
}mmi_dtv_player_context_struct;

/* Global variables declaration */
extern mmi_dtv_player_context_struct *dtv_player_p;
extern dtv_player_menu_context_struct *dtv_player_setting_p;
extern U8 g_cmmb_test_mode;
/****************************************************************************
* MACRO
*****************************************************************************/

/****************************************************************************
* Define
*****************************************************************************/
extern MDI_RESULT mmi_dtv_player_enter_next_state(mmi_dtv_player_module_enum module);
extern void mmi_dtv_player_pre_highlight_handler(S32 index, MMI_BOOL force_player_stop);
extern void mmi_dtv_player_post_highlight_handler(gdi_handle preview_handle, U32 blt_layer_flag, U32 preview_layer_flag, S32 x, S32 y, S32 width, S32 height);
extern S32 mmi_dtv_player_cat265_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item);
extern void mmi_dtv_player_reset_all_state(void);
extern void mmi_dtv_player_entry_option_menu_screen(void);
extern void mmi_dtv_player_highlight_channel_hdlr(S32 index);
extern void mmi_dtv_player_entry_cl_option_screen(void);
extern void mmi_dtv_player_entry_channel_list_screen(void);
extern MMI_BOOL mmi_dtv_player_check_and_restore_valid_drv(MMI_BOOL restore, U16 storage);
extern void mmi_dtv_player_highlight_storage_hdlr(S32 idx);
extern void mmi_dtv_player_entry_storage_screen(void);
extern void mmi_dtv_player_update_channel_list(void);
extern void mmi_dtv_player_remove_service(dtv_player_service_info_struct *info_ptr);
extern void mmi_dtv_player_service_timeout_hdlr(void);
extern void mmi_dtv_player_handle_service_aborted(void);
extern void mmi_dtv_player_handle_service_removed(void);
extern void mmi_dtv_player_reset_key_handler(void(*func_ptr)(void));
extern void mmi_dtv_player_delay_post_highlight_handler(void);
extern void mmi_dtv_player_check_and_jump_to_channel(void);

extern void mmi_dtv_player_highlight_app(void);
extern dtv_player_service_info_struct *mmi_dtv_player_get_active_channel_ptr(void);

extern S32 mmi_dtv_player_favo_to_total_idx(S32 idx);
extern S32 mmi_dtv_player_total_to_favo_idx(S32 idx);
extern void mmi_dtv_player_reset_to_channel_list_screen(void);
extern void mmi_dtv_player_display_confirm(U16 str_id);
extern mmi_ret mmi_dtv_player_deleting_popup_proc(mmi_event_struct *evt);
extern void mmi_dtv_player_esg_timeout_hdlr(void);
extern void mmi_dtv_player_vol_status_icon_press(void);
extern void mmi_dtv_player_player_prepare_player_setting(mdi_mtv_player_setting_struct *video_setting);
extern void mmi_dtv_player_reinit_switch_screen(void);
extern void mmi_dtv_player_stop_download_preview_data(void);
extern MMI_BOOL mmi_dtv_player_draw_preview_image(S32 region_x, S32 region_y, S32 region_width, S32 region_height);
extern void mmi_dtv_player_set_eb_dls_string(void);
extern void mmi_dtv_player_assign_if_have_preview_data(void);
extern void mmi_dtv_player_enter_process_screen(void);
extern void mmi_dtv_player_finalize_mbbms_init(S32 param);
extern void mmi_dtv_player_set_radio_list_string(MMI_ID inline_id);
extern void mmi_dtv_player_query_sgdd_info(
            dtv_player_sgdd_info_enum sgdd_info, 
            WCHAR *str_buffer,
            S32 str_len);
extern U32 mmi_dtv_player_query_display_city_num(void);

extern void mmi_dtv_player_draw_eb_animation(void);
extern void mmi_dtv_player_display_eb_notification(void);

extern MMI_BOOL mmi_dtv_player_query_preview_data(void);
extern MMI_BOOL mmi_dtv_player_check_eb_list(void);

extern void mmi_dtv_player_service_access_denied_hdlr(void);
extern void mmi_dtv_player_assign_service_number(void);
extern void mmi_dtv_player_dtcnt_ready_calback(void);
extern MMI_BOOL mmi_dtv_player_query_access_list(void);
extern void mmi_dtv_player_get_order_name_string(dtv_player_order_struct *order_p, WCHAR *name_str);
extern void mmi_dtv_player_get_order_type_string(dtv_player_order_struct *order_p, WCHAR *type_str);
extern void mmi_dtv_player_get_order_price_string(dtv_player_order_struct *order_p, WCHAR *price_str);
extern U8 mmi_dtv_player_construct_eb_msg(void);
extern void mmi_dtv_player_query_eb_msg_list(void);
extern void mmi_dtv_player_gen_scan_progress(void);
extern void mmi_dtv_player_upgrade_result_hdlr(S32 param);

extern MMI_BOOL mmi_dtv_player_change_channel(U8 target_channel);
#ifdef __MMI_TOUCH_SCREEN__
static void mmi_dtv_player_content_tap_callback(mmi_tap_type_enum tap_type,S32 index);
#endif
extern void mmi_dtv_player_account_inquiry_hdlr(mdi_mtv_account_inquiry_struct *account, void *user_data);
extern void mmi_dtv_player_enter_mbbms_mode_timeout(void);
extern void mmi_dtv_player_enter_mbbms_mode_confirm(void);
extern mmi_ret mmi_dtv_player_dummy_proc(mmi_event_struct *evt);
extern void mmi_dtv_player_entry_manage_order_screen(void);
extern void mmi_dtv_player_refresh_channel_list(void);
extern mmi_ret mmi_dtv_player_cl_setting_proc(mmi_event_struct *evt);
extern void mmi_dtv_player_gen_separate_string(WCHAR *str, WCHAR *insert_str, WCHAR *insert_str2);
extern void mmi_dtv_player_set_search_value(MMI_ID sender_id);
extern void mmi_dtv_player_content_highlight_hdlr(S32 index);
extern S32 mmi_dtv_player_get_content_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item);
extern void mmi_dtv_player_cancel_select_channel(void);
extern void mmi_dtv_player_sort_services(void);
extern void mmi_dtv_player_query_mbbms_content_details(void);
extern void mmi_dtv_player_query_cmmb_content_details(void);
extern void mmi_dtv_player_query_mbbms_service_details(void);
extern void mmi_dtv_player_query_cmmb_service_details(void);
extern void mmi_dtv_player_delete_eb(void);
extern void mmi_dtv_player_alloc_detail_screen_memory(void);
extern void mmi_dtv_player_exit_detail_screen_memory(void);
extern void mmi_dtv_player_play_selected_content(void);
extern void mmi_dtv_player_query_order_list(void);
extern void mmi_dtv_player_entry_tab_subscribed_order_screen(void);
extern void mmi_dtv_player_entry_tab_unsubscribed_order_screen(void);
extern void mmi_dtv_player_entry_tab_program_reminder_screen(void);
extern void mmi_dtv_player_entry_tab_all_channel_screen(void);
extern void mmi_dtv_player_entry_tab_favorite_channel_screen(void);
extern void mmi_dtv_player_exit_channel_list_screen(void);
extern void mmi_dtv_player_entry_channel_detail_screen(void);
extern void mmi_dtv_player_exit_channel_detail_screen(void);
extern void mmi_dtv_player_entry_channel_guide_screen(void);
extern void mmi_dtv_player_enter_cmmb_mode_confirm(void);
extern void mmi_dtv_player_entry_eb_msg_list_screen(void);
extern void mmi_dtv_player_update_program_info(void);
extern void mmi_dtv_player_config_cl_option_menu(MMI_ID send_id);
extern void mmi_dtv_player_get_current_system_time(applib_time_struct *current_time);
extern void mmi_dtv_player_update_esg(void);
extern void mmi_dtv_player_entry_card_info_screen(void);
extern void mmi_dtv_player_new_esg_available_hdlr(void);
extern void mmi_dtv_player_update_eb_msg(void);
extern void mmi_dtv_player_config_pl_option_menu(MMI_ID send_id);
extern void mmi_dtv_player_config_pd_option_menu(MMI_ID send_id);
extern void mmi_dtv_player_config_sr_option_menu(MMI_ID send_id);
extern void mmi_dtv_player_entry_order_detail_screen(void);
extern void mmi_dtv_player_entry_search_program_screen(void);

extern void mmi_dtv_player_cl_setting_screen_entry(void);
extern S32 mmi_dtv_player_cl_setting_deinit(void);
extern S32 mmi_dtv_player_cl_setting_init(MMI_BOOL sim_valid);
extern S32 mmi_dtv_player_get_favorite_service_index(dtv_player_service_info_struct *info_ptr);
extern MMI_BOOL mmi_dtv_player_assign_service_info(void);
extern MMI_BOOL mmi_dtv_player_assign_favorite_service_info(void);
extern MMI_BOOL mmi_dtv_player_assign_program_info(void);
extern void mmi_dtv_player_query_favorite_service(void);
extern void mmi_dtv_player_query_schedule_details(void);
extern void mmi_dtv_player_query_service_details(void);
extern void mmi_dtv_player_add_favorite(S32 idx);
extern void mmi_dtv_player_delete_favorite(S32 idx);
extern void mmi_dtv_player_entry_program_detail_screen(void);
extern void mmi_dtv_player_exit_program_detail_screen(void);
extern mmi_ret mmi_dtv_player_app_screen_leave_proc(mmi_event_struct *para);
extern MMI_BOOL mmi_dtv_cas_get_sim_struct(mdi_mtv_cas_sim_struct *cas);
extern void mmi_dtv_player_get_language_type(void);

extern void mmi_dtv_player_draw_program_time(void);
extern void mmi_dtv_player_entry_eb_msg_screen(void);
extern MMI_BOOL mmi_dtv_player_check_and_copy_program_info(mdi_mtv_program_info_struct* prog_info);
extern void mmi_dtv_player_display_access_denied(void);
extern void mmi_dtv_player_service_access_granted_hdlr(void);

extern void mmi_dtv_player_compute_mjd_to_apptime(
                kal_uint32 mjd,
                kal_uint32 bcd,
                applib_time_struct *p);
extern void mmi_dtv_player_compute_seconds_to_apptime(U32 seconds, applib_time_struct *p);
extern void mmi_dtv_player_entry_channel_guide_tab_screen(S32 tab_index);
extern void mmi_dtv_player_exit_channel_guide_tab_screen(void);
extern void mmi_dtv_player_entry_channel_guide_tab_0(void);
extern void mmi_dtv_player_entry_channel_guide_tab_1(void);
extern void mmi_dtv_player_entry_channel_guide_tab_2(void);
extern void mmi_dtv_player_entry_channel_guide_tab_3(void);
extern void mmi_dtv_player_entry_channel_guide_tab_4(void);
extern void mmi_dtv_player_entry_channel_guide_tab_5(void);
extern void mmi_dtv_player_entry_channel_guide_tab_6(void);
extern void mmi_dtv_player_entry_channel_guide_tab_7(void);
extern void mmi_dtv_player_entry_channel_guide_tab_8(void);
extern void mmi_dtv_player_entry_channel_guide_tab_9(void);
extern void mmi_dtv_player_entry_channel_guide_tab_10(void);

extern void mmi_dtv_player_enter_esg_download(void);
extern void mmi_dtv_player_stop_esg_download(void);
extern void mmi_dtv_player_exit_esg_download(void);
extern MDI_RESULT mmi_dtv_player_kernel_exit_esg_download_state(void);
extern MDI_RESULT mmi_dtv_player_kernel_entry_esg_download_state(void);
extern S32 mmi_dtv_player_check_time_status(applib_time_struct *target_time, WCHAR *date, WCHAR *time);
extern S32 mmi_dtv_player_check_time_to_alarm_status(applib_time_struct *target_time, WCHAR *date, WCHAR *time);
extern void mmi_dtv_player_entry_help_screen(void);
extern void mmi_dtv_player_exit_help_screen(void);
extern void mmi_dtv_player_entry_program_list_screen(void);
extern void mmi_dtv_player_alarm_expiry(BOOL power_on);
extern void mmi_dtv_player_reinit_alarm(void);
extern void mmi_dtv_player_update_alarm(void);
extern void mmi_dtv_player_get_service_flag(void);

extern void mmi_dtv_player_set_storage(WCHAR drv_letter);
extern mmi_ret mmi_dtv_player_app_screen_leave_proc(mmi_event_struct *para);
extern void mmi_dtv_player_dummy(void);
extern void mmi_dtv_player_register_key_hdlr(void);
extern void mmi_dtv_player_set_band_value(void);
extern void mmi_dtv_player_highlight_band_hdlr(S32 idx);
extern void mmi_dtv_player_entry_band_screen(void);
extern void mmi_dtv_player_entry_app_screen(void);
extern void mmi_dtv_player_exit_app_screen(void);
extern void mmi_dtv_player_display_popup(U16 string_id, mmi_event_notify_enum event_id);
extern void mmi_dtv_player_display_failure_popup(MDI_RESULT ret);
extern MMI_BOOL mmi_dtv_player_get_storage_file_path(U16 storage, CHAR *filepath, dtv_player_storage_path_enum path);
extern S32 mmi_dtv_player_create_file_dir(CHAR *filepath);
extern MDI_RESULT mmi_dtv_player_kernel_enter_state(mmi_dtv_player_kernel_state_enum next_state);
extern void mmi_dtv_player_update_scan_progress(S32 value);
extern void mmi_dtv_player_rsk_icon_press(void);
extern void mmi_dtv_player_rsk_icon_release(void);
extern void mmi_dtv_player_lsk_icon_press(void);
extern void mmi_dtv_player_lsk_icon_release(void);
extern void mmi_dtv_player_play_icon_press(void);
extern void mmi_dtv_player_play_icon_release(void);
extern void mmi_dtv_player_change_icon_press(void);
extern void mmi_dtv_player_change_icon_release(void);
extern void mmi_dtv_player_record_icon_press(void);
extern void mmi_dtv_player_record_icon_release(void);
extern void mmi_dtv_player_play_speed_icon_press(void);
extern void mmi_dtv_player_play_speed_icon_release(void);
extern void mmi_dtv_player_fullscreen_icon_press(void);
extern void mmi_dtv_player_fullscreen_icon_release(void);
extern void mmi_dtv_player_forward_icon_press(void);
extern void mmi_dtv_player_forward_icon_release(void);
extern void mmi_dtv_player_rewind_icon_press(void);
extern void mmi_dtv_player_rewind_icon_release(void);
extern void mmi_dtv_player_vol_inc_icon_press(void);
extern void mmi_dtv_player_vol_inc_icon_release(void);
extern void mmi_dtv_player_vol_dec_icon_press(void);
extern void mmi_dtv_player_vol_dec_icon_release(void);
extern void mmi_dtv_player_channel_next_icon_press(void);
extern void mmi_dtv_player_channel_next_icon_release(void);
extern void mmi_dtv_player_channel_prev_icon_press(void);
extern void mmi_dtv_player_channel_prev_icon_release(void);
extern void mmi_dtv_player_key_1_press(void);
extern void mmi_dtv_player_key_2_press(void);
extern void mmi_dtv_player_key_3_press(void);
extern void mmi_dtv_player_key_4_press(void);
extern void mmi_dtv_player_key_5_press(void);
extern void mmi_dtv_player_key_6_press(void);
extern void mmi_dtv_player_key_7_press(void);
extern void mmi_dtv_player_key_8_press(void);
extern void mmi_dtv_player_key_9_press(void);
extern void mmi_dtv_player_key_0_press(void);
extern void mmi_dtv_player_jump_to_channel(void);
extern void mmi_dtv_player_fade_in(void);
extern void mmi_dtv_player_fade_out(void);
extern void mmi_dtv_player_vol_status_icon_release(void);
extern void mmi_dtv_player_cycle_icon_press(void);
extern void mmi_dtv_player_cycle_icon_release(void);

extern void mmi_dtv_player_enter_info_confirm_screen(void);
extern void mmi_dtv_player_init_icon_info(void);
#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_dtv_player_switch_ts_bar(void);
extern void mmi_dtv_player_ts_bar_icon_press(S32 x, S32 y);
extern void mmi_dtv_player_ts_bar_icon_release(void);
extern MMI_BOOL mmi_dtv_player_touch_scr_hit_test(S32 pos_x, S32 pos_y, dtv_player_osd_icon_struct *touch_obj);
extern void mmi_dtv_player_pen_down_hdlr_fullscreen(mmi_pen_point_struct pos);
extern void mmi_dtv_player_pen_down_hdlr(mmi_pen_point_struct pos);
extern void mmi_dtv_player_pen_up_hdlr(mmi_pen_point_struct pos);
extern void mmi_dtv_player_pen_move_hdlr(mmi_pen_point_struct pos);
#endif
#ifdef __MBBMS_DUAL_SIM_SUPPORT__
extern void mmi_dtv_player_switch_to_mbbms_mode(void);
extern MMI_BOOL mmi_dtv_player_sim_support_mbbms(U32 simcard);
#endif

extern void mmi_dtv_player_draw_style_text(CHAR *str, S32 offset_x, S32 offset_y);
extern void mmi_dtv_player_draw_osd_softkey(void);
extern void mmi_dtv_player_draw_osd(void);

extern void mmi_dtv_player_fullscr_osd_show_up(void);
extern void mmi_dtv_player_fullscr_osd_fade_cyclic(void);
extern void mmi_dtv_player_fullscr_reset_osd_fade(BOOL sleep);
extern void mmi_dtv_player_entry_play(void);
extern void mmi_dtv_player_draw_osd_and_blt(void);

extern void mmi_dtv_player_app_mem_success_callback(void);
extern void mmi_dtv_player_stop_app_mem_callback(void);

extern void mmi_dtv_player_create_adm(void);
extern void mmi_dtv_player_delete_adm(void);
extern void mmi_dtv_player_alloc_adm_layer(void);
extern void mmi_dtv_player_free_adm_layer(void);
extern void mmi_dtv_player_alloc_resource(void);
extern void mmi_dtv_player_free_resource(void);
extern void mmi_dtv_player_alloc_base_layer(void);
extern void mmi_dtv_player_free_base_layer(void);
extern void mmi_dtv_player_free_adm_structure(void);
extern void mmi_dtv_player_alloc_adm_structure(void);
extern U8 mmi_dtv_player_app_screen_delete_hdlr(void* ptr);
extern void mmi_dtv_player_store_setting(void);
extern void mmi_dtv_player_load_setting(void);
extern void mmi_dtv_player_restore_setting(void);
extern void mmi_dtv_player_set_hint(CHAR *hint_str1, CHAR *hint_str2, U16 fade_time, MMI_BOOL multiline);
extern void mmi_dtv_player_draw_hint(void);
extern void mmi_dtv_player_hide_hint(void);

extern void mmi_dtv_player_config_layers(void);
extern void mmi_dtv_player_config_display_layer(void);
extern void mmi_dtv_player_set_blt_layer(void);

extern void mmi_dtv_player_service_found_hdlr(mdi_mtv_service_info_struct *service_info, void *user_data);
extern void mmi_dtv_player_search_progress_hdlr(S32 value, void *user_data);
extern void mmi_dtv_player_complete_recovering_hdlr(S32 value, void *user_data);
extern void mmi_dtv_player_system_event_hdlr(U32 event_id, S32 param, void *user_data);
extern void mmi_dtv_player_service_event_hdlr(U32 event_id, S32 param, void *user_data);
extern void mmi_dtv_player_player_event_hdlr(U32 event_id, S32 param, void *user_data);
extern void mmi_dtv_player_recorder_event_hdlr(U32 event_id, S32 param, void *user_data);

extern MDI_RESULT mmi_dtv_player_open_engine(void);

extern MDI_RESULT mmi_dtv_player_exit_current_state(mmi_dtv_player_module_enum module);
/*kernel state management*/
extern MDI_RESULT mmi_dtv_player_kernel_entry_closing_state(void);
extern MDI_RESULT mmi_dtv_player_kernel_exit_closing_state(void);
extern MDI_RESULT mmi_dtv_player_kernel_entry_scanning_state(void);
extern MDI_RESULT mmi_dtv_player_kernel_exit_scanning_state(void);
extern MDI_RESULT mmi_dtv_player_kernel_entry_saving_state(void);
extern MDI_RESULT mmi_dtv_player_kernel_exit_saving_state(void);
extern MDI_RESULT mmi_dtv_player_kernel_entry_opened_state(void);
extern MDI_RESULT mmi_dtv_player_kernel_exit_opened_state(void);
extern MDI_RESULT mmi_dtv_player_kernel_entry_init_state(void);
extern MDI_RESULT mmi_dtv_player_kernel_exit_init_state(void);
extern MDI_RESULT mmi_dtv_player_kernel_entry_ready_state(void);
extern MDI_RESULT mmi_dtv_player_kernel_exit_ready_state(void);
extern MDI_RESULT mmi_dtv_player_kernel_entry_deleting_state(void);
extern MDI_RESULT mmi_dtv_player_kernel_exit_deleting_state(void);


/*player state management*/
extern MDI_RESULT mmi_dtv_player_player_entry_stopped_state(void);
extern MDI_RESULT mmi_dtv_player_player_exit_stopped_state(void);
extern MDI_RESULT mmi_dtv_player_player_entry_bt_connect_state(void);
extern MDI_RESULT mmi_dtv_player_player_exit_bt_connect_state(void);
extern MDI_RESULT mmi_dtv_player_player_entry_play_state(void);
extern MDI_RESULT mmi_dtv_player_player_exit_play_state(void);
extern MDI_RESULT mmi_dtv_player_player_entry_pause_state(void);
extern MDI_RESULT mmi_dtv_player_player_exit_pause_state(void);
/*recorder state management*/
extern MDI_RESULT mmi_dtv_player_recorder_entry_stopped_state(void);
extern MDI_RESULT mmi_dtv_player_recorder_exit_stopped_state(void);
extern MDI_RESULT mmi_dtv_player_recorder_entry_record_state(void);
extern MDI_RESULT mmi_dtv_player_recorder_exit_record_state(void);
extern MDI_RESULT mmi_dtv_player_recorder_entry_save_confirm_state(void);
extern MDI_RESULT mmi_dtv_player_recorder_exit_save_confirm_state(void);
extern MDI_RESULT mmi_dtv_player_recorder_entry_saving_state(void);
extern MDI_RESULT mmi_dtv_player_recorder_exit_saving_state(void);
extern MDI_RESULT mmi_dtv_player_recorder_entry_deleting_state(void);
extern MDI_RESULT mmi_dtv_player_recorder_exit_deleting_state(void);
extern MDI_RESULT mmi_dtv_player_recorder_entry_pause_state(void);
extern MDI_RESULT mmi_dtv_player_recorder_exit_pause_state(void);

extern void mmi_dtv_player_enter_saving_screen(void);
extern void mmi_dtv_player_player_update_cyclic(void);
extern void mmi_dtv_player_enter_deleting_screen(void);

extern void mmi_dtv_player_scrolling_text_draw_hdlr(void);
extern void mmi_dtv_player_scrolling_text_draw_background_hdlr(S32 x1, S32 y1, S32 x2, S32 y2);
extern void mmi_dtv_player_clear_dynamic_label(void);
extern void mmi_dtv_player_draw_dynamic_label(void);
extern void mmi_dtv_player_draw_signal_icon(void);
extern void mmi_dtv_player_enable_ts_function(void);

/* bluetooth */
#if defined(__MMI_DTV_A2DP_SUPPORT__)
#if !defined(__MMI_A2DP_HIDE_BT_SETTINGS__)
void mmi_dtv_player_highlight_bluetooth_setting(void);
#endif
extern void mmi_dtv_player_bt_anim_timeout_hdlr(void);
extern MMI_BOOL mmi_dtv_player_is_output_to_bt(void);
extern void mmi_dtv_player_stop_bt_connecting_anim(void);
extern srv_bt_cm_bt_addr *mmi_dtv_player_get_bt_headset(void);
extern void mmi_dtv_player_bt_open_callback(S32 result);
extern void mmi_dtv_player_disconnect_bt(void);
extern void mmi_dtv_player_bt_close_codec(void);
#endif /* __MMI_DTV_A2DP_SUPPORT__ */

extern void mmi_dtv_player_draw_radio_animation(void);
extern void mmi_dtv_player_stop_radio_animation(void);

#ifdef __MMI_DTV_AVRCP_SUPPORT__
extern U8 mmi_dtv_player_bt_avrcp_cmd_hdlr(U8 command, mmi_avrcp_key_events event);
#endif

extern void mmi_dtv_player_enable_timeshift_function(void);
extern void mmi_dtv_player_disable_timeshift_function(void);
extern void mmi_dtv_player_enable_lsk_function(void);
extern void mmi_dtv_player_disable_lsk_function(void);

extern void mmi_dtv_player_enable_switch_channel_function(void);
extern void mmi_dtv_player_disable_switch_channel_function(void);
extern void mmi_dtv_player_enable_play_function(void);
extern void mmi_dtv_player_disable_play_function(void);

extern MMI_BOOL mmi_dtv_player_is_play_speed_function_enable(void);
extern void mmi_dtv_player_enable_record_function(void);
extern void mmi_dtv_player_disable_record_function(void);
extern void mmi_dtv_player_enable_fullscreen_function(void);
extern void mmi_dtv_player_reset_jump_to_channel(void);
extern void mmi_dtv_player_disable_fullscreen_function(void);
extern void mmi_dtv_player_check_and_display_delayed_record_error(void);
extern void mmi_dtv_player_enter_scan_channel(void);
extern void mmi_dtv_player_config_functions_by_state(void);
extern MMI_BOOL mmi_dtv_player_enable_play_speed_function(void);
extern void mmi_dtv_player_disable_play_speed_function(void);
extern void mmi_dtv_player_clear_preview_layer(void);
extern void mmi_dtv_player_get_player_status(U32 mtv_handle, mdi_mtv_player_state_enum *state, U32* play_delay, U32* max_delay, U32* buf_duration, S32* play_rate);
extern void mmi_dtv_player_record_start_record(void);
extern MMI_BOOL mmi_dtv_player_snapshot(void);
extern void mmi_dtv_player_draw_preview_icon(dtv_player_preview_icon_enum type);
extern mmi_event_notify_enum mmi_dtv_player_check_storage(MMI_BOOL restore, U16 storage);
extern void mmi_dtv_player_get_and_update_signal(void);
extern void mmi_dtv_player_enter_save_confirm(void);
extern void mmi_dtv_player_select_channel_to_play(void);
extern void mmi_dtv_player_prepare_channel_name_hint(CHAR *str_buf, CHAR *str_buf2);
extern void mmi_dtv_player_get_next_filename(CHAR * file_buf_p, CHAR *file_path_p);
extern void mmi_dtv_player_set_flag(dtv_player_bool_status_enum selected_flag);
extern void mmi_dtv_player_unset_flag(dtv_player_bool_status_enum selected_flag) ;
extern MMI_BOOL mmi_dtv_player_is_flag_set(dtv_player_bool_status_enum selected_flag) ;
extern void mmi_dtv_player_animation_draw_after_hdlr(GDI_RESULT result);
extern void mmi_dtv_player_handle_record_discarded(void);
extern void mmi_dtv_player_entry_play_info_screen(void);
extern void mmi_dtv_player_free_detail_screen_memory(void);
extern void mmi_dtv_player_blt_previous(S32 x1, S32 y1, S32 x2, S32 y2);
extern void mmi_dtv_player_display_popup_str(WCHAR *string, mmi_event_notify_enum event_id);
extern MMI_BOOL mmi_dtv_player_init_service_in_app_screen(MMI_BOOL avoid_infinite_pop);
extern MDI_RESULT mmi_dtv_player_player_enter_state(mmi_dtv_player_player_state_enum next_state);
extern void mmi_dtv_player_set_selected_service(S32 service_idx);
extern void mmi_dtv_player_stop_hint_animation(void);
extern MMI_BOOL mmi_dtv_player_if_mts_file_exist(void);
extern void mmi_dtv_player_update_service_preview_data(S32 idx);
extern void mmi_dtv_player_config_mo_option_menu(MMI_ID send_id);
extern void mmi_dtv_player_entry_update_approach_screen(void);
extern void mmi_dtv_player_cancel_reminder(void);
extern void mmi_dtv_player_add_reminder(void);
extern S32 mmi_dtv_player_service_id_to_idx(S32 service_id);
extern void mmi_dtv_player_delete_eb_confirm(void);
extern void mmi_dtv_player_update_with_city_name(void); 
extern void mmi_dtv_player_disable_view_function(void); 
extern void mmi_dtv_player_enable_view_function(void);
extern void mmi_dtv_player_free_city_mem(void);
extern void mmi_dtv_player_unset_flag(dtv_player_bool_status_enum selected_flag);
extern void mmi_dtv_player_stop_eb_animation(void);
extern void mmi_dtv_player_handle_play_fail(void);
extern void mmi_dtv_player_view_icon_release(void);
extern void mmi_dtv_player_view_icon_press(void);
extern void mmi_dtv_player_copy_eb_region(void);
extern void mmi_dtv_player_update_imd_count(void);
extern void mmi_dtv_player_sg_update_result_hdlr(S32 param);
extern void mmi_dtv_player_mbbms_update_hdlr(U32 event_id, S32 param);
extern void mmi_dtv_player_area_retrieve_result_hdlr(S32 param);
extern void mmi_dtv_player_imd_ready_hdlr(S32 param);
extern void mmi_dtv_player_subscriptoin_update_result_hdlr(S32 param);
extern void mmi_dtv_player_purchase_done_hdlr(U32 event_id, S32 param);
extern void mmi_dtv_player_account_inquiry_done_hdlr(S32 param);
extern MDI_RESULT mmi_dtv_player_kernel_entry_sub_updating_state(void);
extern MDI_RESULT mmi_dtv_player_kernel_entry_process_state(void);
extern MDI_RESULT mmi_dtv_player_kernel_exit_process_state(void);
extern MDI_RESULT mmi_dtv_player_kernel_exit_sub_updating_state(void);
extern MMI_BOOL mmi_dtv_player_is_city_screen_presented(void);
extern MMI_BOOL mmi_dtv_cas_update_net_info(void);

#ifdef __MBBMS_CITY_LIST__
extern void mmi_dtv_player_allocate_city_mem(void);
extern void mmi_dtv_player_city_found_hdlr(mdi_mtv_city_info_struct *city, void *user_data);
extern void mmi_dtv_player_entry_city_list_recommend_screen(void);
extern void mmi_dtv_player_entry_city_list_level_1_screen(void);
extern void mmi_dtv_player_entry_city_list_level_2_screen(void);
extern void mmi_dtv_player_entry_city_list_level_3_screen(void);
extern void mmi_dtv_player_display_city_list(void);
#endif /* __MBBMS_CITY_LIST__ */

#ifdef __MBBMS_UPGRADE__
extern void mmi_dtv_player_upgrade(void);
extern void mmi_dtv_player_upgrade_result_hdlr(S32 param);
extern void mmi_dtv_player_display_upgrade_query(void);
#endif /* __MBBMS_UPGRADE__ */

#ifdef __MBBMS_INTER__
extern void mmi_dtv_player_draw_inter_description(void);
extern void mmi_dtv_player_clear_description(void);
extern void mmi_dtv_player_clear_dynamic_inter_desc(void);
extern void mmi_dtv_player_display_next_inter_desc(void);
extern S32 cui_inline_set_item_checkbox_string(mmi_id gid, U16 item_id, PU8 text_p);
extern void mmi_dtv_player_interactivity_retrieve(void);
extern void mmi_dtv_player_config_inter_layer(void);
extern void mmi_dtv_player_draw_service_inter_icon(void);
extern void mmi_dtv_player_entry_content_inter_screen(void);
extern void mmi_dtv_player_entry_service_inter_list_screen(void);
extern void mmi_dtv_player_entry_service_inter_screen(void);
extern void mmi_dtv_player_inter_retrieve_result_hdlr(S32 param);
extern void mmi_dtv_player_half_inter_app_screen(void);

#endif /* __MBBMS_INTER__ */

#ifdef __MBBMS_V30_OPERA__
extern MMI_BOOL mmi_dtv_player_opera_engine_start(void);
extern void mmi_dtv_player_opera_engine_stop(void);
extern void mmi_dtv_player_opera_engine_restart(GDI_HANDLE opera_layer);
extern void mmi_dtv_player_opera_engine_pause(void);
extern MMI_BOOL mmi_dtv_player_opera_engine_pen_event(mmi_pen_point_struct pos, enum opera_webview_pen_evt event);
extern void mmi_dtv_player_opera_engine_key_event(void);
extern void mmi_dtv_player_alloc_opera_layer_memory(void);
extern void mmi_dtv_player_free_opera_layer_memory(void);
extern void mmi_dtv_player_opera_engine_init_boot_up(void);
extern void mmi_dtv_player_inter_fullscreen_pen_down_hdlr(mmi_pen_point_struct pos);
extern void mmi_dtv_player_inter_fullscreen_pen_up_hdlr(mmi_pen_point_struct pos);
extern void mmi_dtv_player_inter_fullscreen_pen_move_hdlr(mmi_pen_point_struct pos);
extern void mmi_dtv_player_opera_engine_display_imd(void);
extern MMI_BOOL mmi_dtv_player_opera_engine_is_set_flag(dtv_player_opera_state_enum flag);
extern void mmi_dtv_player_opera_register_key_hdlr(void);
extern void mmi_dtv_player_entry_inter_file_download_screen(void);
#endif /* __MBBMS_V30_OPERA__ */

#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
extern void mmi_dtv_player_entry_tab_account_manage_screen(void);
extern void mmi_dtv_player_exit_confirm(void);
extern void mmi_dtv_player_display_2gpp_help_items(void);
extern void mmi_dtv_player_2gpp_call_cbc_service_hotline(void);
extern void mmi_dtv_player_cmmb_2gpp_display_hint(void);
extern void mmi_dtv_player_2gpp_display_athenticate_state(int status);
#endif

#ifndef GDI_USING_2D_ENGINE_V3
extern void mmi_dtv_player_sw_rotate(U8* pDst, U8* pSrc, U32 const src_width, U32 const src_height);
#endif
void mmi_dtv_player_counter_clockwise_rotate(U8* pDst, U8* pSrc, U32 const dst_width,
                                             U32 const dst_height, gdi_rect_struct *dest_rect);

#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */
#endif /* _MMI_DTV_PLAYER_H_ */

