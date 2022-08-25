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
 * DCDV30Prot.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _DCD_V30_PROT_H
#define _DCD_V30_PROT_H

#include "MMI_features.h"
#ifdef __MMI_OP01_DCD_V30__

#include "dcdagentdefine.h"
#include "InlineCuiGprot.h"
#include "MMIDatatype.h"
#include "kal_non_specific_general_types.h"
#include "app_datetime.h"

/*****************************************************************************
 * Define
 *****************************************************************************/
#define MMI_DCD_MAX_CHANNEL_COUNT        10 	/* channel count */
#define MMI_DCD_CHANNEL_TITLE_LEN        ((64+7+1)*2) /* channel tilte length, 7 for number, 1 for null terminal */
#define MMI_DCD_CHANNEL_LIST_BUF_SIZE    ((MMI_DCD_MAX_CHANNEL_COUNT)*((MMI_DCD_CHANNEL_TITLE_LEN)+sizeof(void*)))
#define MMI_DCD_MAX_CHANNEL_TITLE_LEN    ((64 + 1)*ENCODING_LENGTH)
//#define MMI_DCD_MAX_STORY_COUNT          10
#define MMI_DCD_MAX_STORY_TITLE_LEN      ((64 + 1)*ENCODING_LENGTH)/* story tilte length, 1 for null terminal */
//#define MMI_DCD_STORY_LIST_BUF_SIZE      (MMI_DCD_MAX_STORY_COUNT*(MMI_DCD_MAX_STORY_TITLE_LEN + sizeof(void*)))
#define MMI_DCD_MAX_SAVED_STORY_COUNT       10
#define MMI_DCD_MAX_CITY_COUNT            10
#define MMI_DCD_MAX_CITY_NAME_LEN         40
#define MMI_DCD_MAX_CITY_CODE_LEN         20
#define MAX_DCD_OBJECT_COUNT        (10)
#define MAX_DCD_OBJECT_ITEM_LEN     (20 + 1)
#define UPDATE_STR_SIZE             20  
#define MAX_DCD_STORY_TITLE_LEN             (32 + 1)
#define MAX_DCD_WEATHER_SUMMARY_LEN   (255 + 1)
#define DCD_MAX_IMAGE_PATH_LEN             (100)
#define DCD_MAX_ISSUE_TIME_LEN             (15)
#define DCD_PRESET_CHANNEL_SUMMARY_LEN      (200)
#define MMI_DCD_CHANNEL_LIST_UPDATE_MASK    0x01
#define MMI_DCD_STORY_LIST_UPDATE_MASK      0x02
#define DCD_OBJECT_TYPE_IMAGE       "image/"
#define MAX_DCD_STORY_TEXT_LEN             (2*1024 + 1)
#define MAX_DCD_SAVED_TEXT_SIZE            (MAX_DCD_STORY_TEXT_LEN + MAX_DCD_STORY_TITLE_LEN)
#define MAX_DCD_SAVED_IMAGE_NAME_LEN       (100)
/*****************************************************************************
 * Enum
 *****************************************************************************/
/* sync type */
typedef enum
{
    DCD_SYNC_REQ_TYPE_MAN,
    DCD_SYNC_REQ_TYPE_START,
    DCD_SYNC_REQ_TYPE_SVR,
    DCD_SYNC_REQ_TYPE_TTL,
    DCD_SYNC_REQ_TYPE_RETRY,
    DCD_SYNC_REQ_TYPE_GETENTRYCONTENT,
    DCD_SYNC_REQ_TYPE_GETDATA2,
    DCD_SYNC_REQ_TYPE_GETBACKGROUNDLIST,
    DCD_SYNC_REQ_TYPE_SEARCHCITY,
    DCD_SYNC_REQ_TYPE_GETCITYLIST,
    DCD_SYNC_REQ_TYPE_ADDWEATHERCITY,
    DCD_SYNC_REQ_TYPE_DELETEWEATHERCITY,
    DCD_SYNC_REQ_TYPE_ALL
} mmi_dcd_sync_req_type_enum;

/* srv callback event type */
typedef enum
{
    DCD_EVT_MAIN_SYNCPKG_SYNC_COMPLETE,
    DCD_EVT_MAIN_SYNC_COMPLETE,
    DCD_EVT_USER_SYNCPKG_SYNC_COMPLETE,
    DCD_EVT_USER_SYNC_COMPLETE,
    DCD_EVT_GETENTRYCONTENT_SYNC_COMPLETE,
    DCD_EVT_GETDATA2_SYNC_COMPLETE,
    DCD_EVT_GETBACKGROUNDLIST_SYNC_COMPLETE,
    DCD_EVT_SEARCHCITY_SYNC_COMPLETE,
    DCD_EVT_GETCITYLIST_SYNC_COMPLETE,
    DCD_EVT_ADDWEATHERCITY_SYNC_COMPLETE,
    DCD_EVT_DELETEWEATHERCITY_SYNC_COMPLETE,
    DCD_EVT_ERR_SYNTEX,                         /* eDCD_MSG_ERR_SYNTEX, 400 */
    DCD_EVT_ERR_OTHER_CERTIFY,                  /* eDCD_MSG_ERR_OTHER_CERTIFY, 403 */
    DCD_EVT_ERR_NOT_FOUND_RESOURCE,             /* eDCD_MSG_ERR_NOT_FOUND_RESOURCE, 404 */
    DCD_EVT_ERR_INTERNAL_SYSTEM,                /* eDCD_MSG_ERR_INTERNAL_SYSTEM, 500 */
    DCD_EVT_ERR_TRAFFIC_CONTROL,                /* eDCD_MSG_ERR_TRAFFIC_CONTROL, 503 */
    DCD_EVT_ERR_NOT_SUPPORT_TERMINAL,           /* eDCD_MSG_ERR_NOT_SUPPORT_TERMINAL, 601 */
    DCD_EVT_ERR_NOT_REGISTER_USER,              /* eDCD_MSG_ERR_NOT_REGISTER_USER, 604 */
    DCD_EVT_ERR_VERSION_NUMBER,                 /* eDCD_MSG_ERR_VERSION_NUMBER, 692 */
    DCD_EVT_ERR_BEFORE_BUY_CITY,                /* eDCD_MSG_ERR_BEFORE_BUY_CITY, 693 */
    DCD_EVT_ERR_NOT_EXIST_CITY,                 /* eDCD_MSG_ERR_NOT_EXIST_CITY, 694 */
    DCD_EVT_ERR_VERSION_EXPIRED,                /* eDCD_MSG_ERR_VERSION_EXPIRED, 695 */
    DCD_EVT_ERR_FULL_BUY_CITY_COUNT,            /* eDCD_MSG_ERR_FULL_BUY_CITY_COUNT, 696 */
    DCD_EVT_ERR_LATEST_VERSION,                 /* eDCD_MSG_ERR_FULL_BUY_CITY_COUNT, 697 */
    DCD_EVT_ERR_FAIL_REMOVE_CITY,               /* eDCD_MSG_ERR_FAIL_REMOVE_CITY, 698 */
    DCD_EVT_ERR_SYNCPKG_PARSING,                /* eDCD_MSG_ERR_SYNCPKG_PARSING,  701 */
    DCD_EVT_ERR_NO_SYNCPKG,                     /* eDCD_MSG_ERR_NO_SYNCPKG, 702 */
    DCD_EVT_ERR_CONTENT_PARSING,                /* eDCD_MSG_ERR_CONTENT_PARSING, 703 */
    DCD_EVT_ERR_NO_CONTENT,                     /* eDCD_MSG_ERR_NO_CONTENT, 704 */
    DCD_EVT_ERR_STORAGE_FULL,                   /* eDCD_MSG_ERR_STORAGE_FULL, 705 */
    DCD_EVT_ERR_NETWORK_DISABLE,                /* eDCD_MSG_ERR_NETWORK_DISABLE, 706 */
    DCD_EVT_ERR_NETWORK_BUSY,                   /* eDCD_MSG_ERR_NETWORK_BUSY, 707 */
    DCD_EVT_ERR_CONNECT_TIME_OUT,               /* eDCD_MSG_ERR_CONNECT_TIME_OUT, 708 */
    DCD_EVT_ERR_DOWNLOAD_SYNCPKG,               /* eDCD_MSG_ERR_DOWNLOAD_SYNCPKG */
    DCD_EVT_ERR_DOWNLOAD_CONTENT,               /* eDCD_MSG_ERR_DOWNLOAD_CONTENT */
    DCD_EVT_ERR_DOWNLOAD_APPPKG,                /* eDCD_MSG_ERR_DOWNLOAD_APPPKG */
    DCD_EVT_ERR_INSUFFICIENT_MEMORY,            /* eDCD_MSG_ERR_INSUFFICIENT_MEMORY */
    DCD_EVT_ERR_SYNC_FAIL,                      /* sync common fail */
    DCD_EVT_WAKE_UP,
    DCD_EVT_ALL
} mmi_dcd_event_enum;

/* connect mode enum */
typedef enum
{
    DCD_CONN_MODE_ALWAYS,
    DCD_CONN_MODE_HOME,
    DCD_CONN_MODE_MANUAL,
    DCD_CONN_MODE_ALL
} mmi_dcd_conn_mode_enum;

/* update mode enum */
typedef enum
{
    DCD_UPDATE_MODE_ONLY_TITLE,
    DCD_UPDATE_MODE_TITLE_AND_HOMEPAGE,
    DCD_UPDATE_MODE_ALL
} mmi_dcd_update_mode_enum;

typedef enum {
    MMI_DCD_URL_ADD_CHAN,
    MMI_DCD_URL_DEL_CHAN,
    MMI_DCD_URL_HELP,
    MMI_DCD_URL_TYPE_END
} mmi_dcd_url_type_eunm;

typedef enum
{
    DCD_SETTING_CONNECTION_MODE_CAPTION = CUI_INLINE_ITEM_ID_BASE,
    DCD_SETTING_CONNECTION_MODE,
    DCD_SETTING_SCROLL_SPEED_CAPTION,
    DCD_SETTING_SCROLL_SPEED,
    DCD_SETTING_UPDATE_MODE_CAPTION,
    DCD_SETTING_UPDATE_MODE,
    DCD_SETTING_DEFAULT_CITY_CAPTION,
    DCD_SETTING_DEFAULT_CITY,
    DCD_SETTING_INLINE_TOTAL
} mmi_dcd_setting_inline_items_enum;

typedef enum
{
    DCD_NETWORK_INFO_LAST_UPDATE_RESULT_CAPTAIN = CUI_INLINE_ITEM_ID_BASE,
    DCD_NETWORK_INFO_LAST_UPDATE_RESULT,
    DCD_NETWORK_INFO_LAST_UPDATE_TIME_CAPTAIN,
    DCD_NETWORK_INFO_LAST_UPDATE_TIME,
    DCD_NETWORK_INFO_NEXT_UPDATE_TIME_CAPTAIN,
    DCD_NETWORK_INFO_NEXT_UPDATE_TIME,
    DCD_NETWORK_INFO_UPDATE_ERROR_REASON_CAPTAIN,
    DCD_NETWORK_INFO_UPDATE_ERROR_REASON,
    DCD_NETWORK_INFO_INLINE_TOTAL
} mmi_dcd_network_info_inline_items_enum;

typedef enum
{
    DCD_SCROLL_SPEED_MEDIUM,
    DCD_SCROLL_SPEED_SLOW,
    DCD_SCROLL_SPEED_FAST,
    DCD_SCROLL_SPEED_TOTAL
} dcd_scroll_speed_enum;

typedef enum
{
	DCD_ENABLE_OFF,
	DCD_ENABLE_ON,
	DCD_ENABLE_TOTAL
} mmi_dcd_enable_enum;

/*****************************************************************************
 * Struct
 *****************************************************************************/
/* setting struct */
typedef struct 
{
    kal_uint8   dcd_conn_mode;
    kal_uint8   dcd_scroll_speed;
    kal_uint8   dcd_switch;
    kal_uint8   dcd_update_mode;
    kal_uint8   dcd_restore;
} mmi_dcd_setting_struct;

typedef void (*srv_func_ptr)(mmi_dcd_event_enum evt, mmi_dcd_sync_req_type_enum sync_type);


/*****************************************************************************
 * Extern functions
 *****************************************************************************/
extern MMI_BOOL mmi_dcd_srv_initialize(srv_func_ptr callback_func);
extern MMI_BOOL mmi_dcd_is_service_available(void);
extern MMI_BOOL mmi_dcd_save_setting_data(void);
extern mmi_dcd_setting_struct* mmi_dcd_get_setting_data(void);
extern MMI_BOOL mmi_dcd_set_update_mode(void);
extern MMI_BOOL mmi_dcd_user_to_sync(mmi_dcd_sync_req_type_enum req_type, char *url_data, MMI_BOOL *is_syncing);
extern void mmi_dcd_reset_to_sync(void);
extern void mmi_dcd_switch_to_sync(MMI_BOOL switch_on);
extern void mmi_dcd_conn_to_sync(void);
extern void mmi_dcd_user_sync_fail_abort(void);
extern void mmi_dcd_stop_sync(void);
extern MMI_BOOL mmi_dcd_is_roaming(void);

#endif /* __MMI_OP01_DCD_V30__ */
#endif /* _DCD_V30_PROT_H */

