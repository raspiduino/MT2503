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
 *  ImpsAppProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines local contant, structure, enum, and function prototypes forIMPS application.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef IMPS_APP_PROT_H
#define IMPS_APP_PROT_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "mmi_frm_utility_gprot.h"
#include "DataAccountGProt.h"
#include "ProfilesSrvGprot.h"
#include "FileMgrSrvGProt.h"
#include "menucuigprot.h"
#include "inlinecuigprot.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "wgui_categories_list.h"
#include "DtcntSrvGprot.h"
#include "gui_inputs.h"
#include "custom_mmi_default_value.h"

#include "mmi2imps_struct.h"
#ifdef __MMI_OP11_IMPS__
/* under construction !*/
#endif
#include "ImpsSrvGprot.h"

/***************************************************************************** 
* Define
*****************************************************************************/

//#define __MMI_OP11_IMPS_TEST_VER__

/* trace */
#define MMI_IMPS_LOG(x)                     MMI_TRACE(MMI_INET_TRC_G8_IMPS, x)
#define MMI_IMPS_LOG1(x, x1)                MMI_TRACE(MMI_INET_TRC_G8_IMPS, x, x1)
#define MMI_IMPS_LOG2(x, x1, x2)            MMI_TRACE(MMI_INET_TRC_G8_IMPS, x, x1, x2)

/* general */
#define IMPS_MAX_SEARCH_RESULT              (30)     /* maximum number of search result */

#define MMI_IMPS_MAX_USERID_LEN             (64 + 1)
#define MMI_IMPS_MAX_PSWD_LEN               (30 + 1)
#define MMI_IMPS_MAX_SERVER_ADDRESS_LEN     (64 + 1)
#define MMI_IMPS_PROF_PORT_LEN              (6)      /* number of digits for port + NULL terminate */

#define IMPS_RECONN_COUNT                   (3)
#define IMPS_UPDATE_PA_COUNT                (2)

/* presence attribute value */
#define IMPS_PA_ATTR_VALUE             IMPS_PA_ONLINE_STATUS|IMPS_PA_USER_AVAILABILITY|IMPS_PA_STATUS_TEXT|IMPS_PA_ALIAS|IMPS_PA_STATUS_CONTENT|IMPS_PA_CLIENT_INFO
#define IMPS_PA_ATTR_VALUE_NO_PIC      IMPS_PA_ONLINE_STATUS|IMPS_PA_USER_AVAILABILITY|IMPS_PA_STATUS_TEXT|IMPS_PA_ALIAS|IMPS_PA_CLIENT_INFO
#define IMPS_PA_DEFAULT_ATTR_VALUE     IMPS_PA_ONLINE_STATUS|IMPS_PA_USER_AVAILABILITY|IMPS_PA_STATUS_TEXT|IMPS_PA_ALIAS|IMPS_PA_STATUS_CONTENT|IMPS_PA_CLIENT_INFO
#define IMPS_SUBS_GENERAL_NOTIFY       IMPS_NOTIFICATION_TYPE_ATCL|IMPS_NOTIFICATION_TYPE_BLC|IMPS_NOTIFICATION_TYPE_UIC	                         
#define IMPS_PA_ABOUT_ME_ATTR_VALUE    IMPS_PA_ONLINE_STATUS|IMPS_PA_USER_AVAILABILITY|IMPS_PA_STATUS_TEXT|IMPS_PA_ALIAS

#define IMPS_NUM_TEMPLATE                   (14)

/* chat/chat room */
#define IMPS_MAX_CHAT_INPUT_LEN             (260)   /* maximum length of input buffer */
#define IMPS_MAX_CHAT_BUFF                  (600)   /* maximum length of display buffer */

#define IMPS_MAX_PEND_FILE_MSG_COUNT        (20)    /* maximum number of pending file message */
#define IMPS_MAX_NOTIFY_MSG_INFO_LEN        (500)   /* size of notify messag information buffer */

#define MMI_IMPS_TAB_TEXT_LEN               (21)    /* tab text length for chat room */

/* about me related */
#define IMPS_MAX_PIC_PATH_LEN               (60)        /* maximum buffer length to store my picture */
#define IMPS_MAX_PIC_SIZE                   (50*1024)   /* maximum length of my picture */

/* invitation related */
#define IMPS_MAX_INVITATION_NOTE            (1024)   /* size of invitation note buffer */

#define IMPS_MAX_PROXY_ID_LEN               CCA_HASH_VALUE_MAX_BYTES     /* length of proxy id */  
#define IMPS_DATA_ACCOUNT_TYPE              (DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI)

/* imps folder */
#define IMPS_SETTING_FILE                   L"setting.dat"
#define IMPS_APP_FOLDER                     "app\\"
#define IMPS_APP_MESSAGE_FILE               L"message.dat"

#define IMPS_PUBLIC_PROFILE_DISP_BUFF       (700)

/* inline editor item number */
#define MMI_IMPS_CONNECT_ITEM               (5)
#define MMI_IMPS_NOTIFY_ITEM                (4)
#define MMI_IMPS_COUNTRY_CODE_ITEM          (STR_ID_IMPS_CC_END - STR_ID_IMPS_CC_BEGIN)

/* click to call */
#define MMI_IMPS_MAX_NO_HILITE_STR          (120)
#define MMI_IMPS_MAX_NO_HILITE_STR_NODE     (3)

/* imps status */
#define IMPS_CURR_ACTION_IDLE                   (mmi_imps_curr_action_idle())
#define IMPS_EVENT_IS_CURR_HANDLE(event_id)     (srv_imps_is_event_exist(imps_p->gen_info.imps_hd, event_id))

#define IMPS_STATUS_LOGGING_IN                  (srv_imps_get_status() == SRV_IMPS_STATUS_LOGING_IN)
#define IMPS_STATUS_ABORTING_LOGIN              (srv_imps_get_status() == SRV_IMPS_STATUS_ABORTING_LOGIN)
#define IMPS_STATUS_LOGIN                       (mmi_imps_is_login())
#define IMPS_STATUS_LOGGING_OUT                 (srv_imps_get_status() == SRV_IMPS_STATUS_LOGING_OUT)

#define IMPS_CURR_ROOM                          (&imps_p->room_info.room_list[imps_p->room_info.curr_room])

/* use for generate inline cui caption item */
#define MMI_IMPS_INLINE_CAP_NAME(name)  \
	static const cui_inline_item_caption_struct g_mmi_imps_##name = \
    {\
        name,\
    };

#define MMI_IMPS_INLINE_CAP_ITEM(num, name)   \
    {MMI_IMPS_INLINE_CAPTION_##num, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L##num, (void*)&g_mmi_imps_##name}

/* inline cui item id */
#define MMI_IMPS_INLINE_CAPTION_1                 (CUI_INLINE_ITEM_ID_BASE+0)
#define MMI_IMPS_INLINE_CAPTION_2                 (CUI_INLINE_ITEM_ID_BASE+1)
#define MMI_IMPS_INLINE_CAPTION_3                 (CUI_INLINE_ITEM_ID_BASE+2)
#define MMI_IMPS_INLINE_CAPTION_4                 (CUI_INLINE_ITEM_ID_BASE+3)
#define MMI_IMPS_INLINE_CAPTION_5                 (CUI_INLINE_ITEM_ID_BASE+4)
#define MMI_IMPS_INLINE_CAPTION_6                 (CUI_INLINE_ITEM_ID_BASE+5)
#define MMI_IMPS_INLINE_CAPTION_7                 (CUI_INLINE_ITEM_ID_BASE+6)
#define MMI_IMPS_INLINE_CAPTION_8                 (CUI_INLINE_ITEM_ID_BASE+7)
#define MMI_IMPS_INLINE_TEXT_EDIT_1               (CUI_INLINE_ITEM_ID_BASE+8)
#define MMI_IMPS_INLINE_TEXT_EDIT_2               (CUI_INLINE_ITEM_ID_BASE+9)
#define MMI_IMPS_INLINE_TEXT_EDIT_3               (CUI_INLINE_ITEM_ID_BASE+10)
#define MMI_IMPS_INLINE_TEXT_EDIT_4               (CUI_INLINE_ITEM_ID_BASE+11)
#define MMI_IMPS_INLINE_IP                        (CUI_INLINE_ITEM_ID_BASE+12)
#define MMI_IMPS_INLINE_SELECT_1                  (CUI_INLINE_ITEM_ID_BASE+13)
#define MMI_IMPS_INLINE_SELECT_2                  (CUI_INLINE_ITEM_ID_BASE+14)
#define MMI_IMPS_INLINE_SELECT_3                  (CUI_INLINE_ITEM_ID_BASE+15)
#define MMI_IMPS_INLINE_SELECT_4                  (CUI_INLINE_ITEM_ID_BASE+16)
#define MMI_IMPS_INLINE_DISP_ONLY_1               (CUI_INLINE_ITEM_ID_BASE+17)
#define MMI_IMPS_INLINE_DATE                      (CUI_INLINE_ITEM_ID_BASE+18)


/* imps tone */
#define MMI_IMPS_TONE_ID_OFFSET                        (1)
#define MMI_IMPS_DEFAULT_TONE_ID_CONT_ONLINE           (101)
#define MMI_IMPS_DEFAULT_TONE_ID_NEW_MSG               (102)
#define MMI_IMPS_DEFAULT_TONE_ID_INVITE                (103)
#define MMI_IMPS_DEFAULT_TONE_ID_GROUP_CHANGE          (104)


#ifdef __MMI_OP11_IMPS__
/* under construction !*/
#else /* __MMI_OP11_IMPS__ */
#define imps_act_prof (&imps_p->nvram_info.prof[imps_p->nvram_info.act_prof_indx - 1])
#endif /* #ifdef __MMI_OP11_IMPS__ */


/* 
 * common version defines 
 */
#ifndef __MMI_OP11_IMPS__

#define IMPS_PROF_COUNT 3       /* number of supported profiles */
#define IMPS_PROF_NAME_LEN 17   /* 16 word count + 1 word NULL terminate */
#endif
#define MMI_IMPS_OTA_HASH_LEN CCA_HASH_VALUE_MAX_BYTES


/*****************************************************************************
* Typedef 
*****************************************************************************/

/* type of add contact */
typedef enum
{
    MMI_IMPS_ADD_CONT_PA_AUTH = 0,
    MMI_IMPS_ADD_CONT_SEARCH,
    MMI_IMPS_ADD_CONT_DIRECT,
    MMI_IMPS_ADD_CONT_END
}mmi_imps_add_cont_type_enum;

/* multimedia message type */
typedef enum
{
    IMPS_MSG_TEXT = 1,
    IMPS_MM_MSG_AUDIO,
    IMPS_MM_MSG_IMAGE,
    IMPS_MM_MSG_VIDEO, 
    IMPS_MM_MSG_TYPE_TOTAL
} mmi_imps_mm_msg_type_enum;

typedef enum
{
    IMPS_ROOM_MEMBER_LEFT,
    IMPS_ROOM_MEMBER_JOINED,
    IMPS_ROOM_GROUP_CHANGE_TOTAL
} mmi_imps_room_change_enum;

/* OTA node symbols */
typedef enum 
{
    MMI_IMPS_NS_OMA_BOOTSTRAP,   /* L1 node */
    MMI_IMPS_NS_OMA_PROXY,       /* L1 node */
    MMI_IMPS_NS_OMA_APP,         /* L1 node */
    MMI_IMPS_NS_OMA_PXAUTHINFO,  /* child node of MMI_IMPS_NS_OMA_PROXY */
    MMI_IMPS_NS_OMA_PORT,        /* child node of MMI_IMPS_NS_OMA_PROXY */
    MMI_IMPS_NS_OMA_APPAUTH,     /* child node of MMI_IMPS_NS_OMA_APP */
    MMI_IMPS_NS_OMA_APPADDR,     /* child node of MMI_IMPS_NS_OMA_APP */
    MMI_IMPS_NS_OMA_TOTAL
} mmi_imps_ns_oma_enum;

typedef enum
{
    MMI_IMPS_MSG_TONE =  SRV_PROF_TONE_IMPS_NEW_MESSAGE,                     /* new message tone */
    MMI_IMPS_INVITATION_TONE = SRV_PROF_TONE_IMPS_CONTACT_INVITATION,        /* new invitation */
    MMI_IMPS_CONTACT_ONLINE_TONE = SRV_PROF_TONE_IMPS_CONTACT_ONLINE,        /* contact online */
    MMI_IMPS_GROUP_CHANGE_TONE = SRV_PROF_TONE_IMPS_CHATROOM_NOTIFICATION,   /* group change */
    MMI_IMPS_ERR_TONE   = SRV_PROF_TONE_ERROR,                               /* error tone */  
    MMI_IMPE_TONE_ENUM_TOTAL
} mmi_imps_tone_type_enum;

typedef enum
{
    MMI_IMPS_TREE_ITEM_CONT_LIST = 0,
    MMI_IMPS_TREE_ITEM_CONT_LIST_MSG,
    MMI_IMPS_TREE_ITEM_CONTACT
} mmi_imps_tree_item_level_enum;

typedef enum
{
    MMI_IMPS_TREE_ITEM_SHOW = 0,
    MMI_IMPS_TREE_ITEM_HIDE,
    MMI_IMPS_TREE_PARENT_STATE_SHOW,
    MMI_IMPS_TREE_PARENT_STATE_HIDE
} mmi_imps_tree_item_state_enum;

/* authorize type */
typedef enum
{
    MMI_IMPS_AUTHORIZE_TYPE_REACTIVE = 0,
    MMI_IMPS_AUTHORIZE_TYPE_PROACTIVE
} mmi_imps_authorize_type_enum;

typedef enum
{
    MMI_IMPS_AUDIO_ONLY = 0,
    MMI_IMPS_VIBRATION_ONLY,
    MMI_IMPS_AUDIO_VIBRATION,
    MMI_IMPS_AUDIO_NONE
} mmi_imps_audio_enum;

typedef enum
{
    MMI_IMPS_AUTO_SET_TYPE_LOGIN = 1,
    MMI_IMPS_AUTO_SET_TYPE_START
} mmi_imps_auto_set_type_enum;

typedef enum
{
    MMI_IMPS_SEARCH_TYPE_NUMB = 0,
    MMI_IMPS_SEARCH_TYPE_EMAIL
} mmi_imps_search_type;

typedef enum
{
    MMI_IMPS_FILE_SIZE_OK,
    MMI_IMPS_FILE_SIZE_ERR,
    MMI_IMPS_FILE_RESIZE_SUCC	
} mmi_imps_file_size_enum;

typedef enum
{
    MMI_IMPS_HILITE_STR_TYPE_PHONENUMBER,
    MMI_IMPS_HILITE_STR_TYPE_URL   
}mmi_imps_hilite_str_type;

/* disconnection cause */
typedef enum
{
    MMI_IMPS_DISCONNECT,
    MMI_IMPS_FAIL_TO_CONNECT   
}mmi_imps_disconnect_cause_enum;

typedef enum
{
    MMI_IMPS_VIEW_LOG_STATE_IDLE = 0,
    MMI_IMPS_VIEW_LOG_STATE_CALCULATING,
    MMI_IMPS_VIEW_LOG_STATE_COMPLETED,
    MMI_IMPS_VIEW_LOG_STATE_TOTAL
}mmi_imps_view_log_state;

/* information update */
typedef enum
{
    MMI_IMPS_BASIC_INFO_UPDATE = 0,
    MMI_IMPS_UNREAD_MSG_UPDATE,
    MMI_IMPS_AVAILABILITY_UPDATE,
    MMI_IMPS_CONTACT_STATUS_UPDATE,
    MMI_IMPS_CONVERSATION_UPDATE,
    MMI_IMPS_MYSELF_STATUS_UPDATE,
    MMI_IMPS_INFO_UPDATE_TYPE_END
} mmi_imps_info_update_type_enum;

/* notification setting type */
typedef enum
{
    MMI_IMPS_NOTIFICATION_TYPE_MESSAGE = 0,
    MMI_IMPS_NOTIFICATION_TYPE_PRESENCE
}mmi_imps_notification_type_enum;


#ifndef __MMI_OP11_IMPS__
/* profile type */
typedef enum 
{
    MMI_IMPS_PROF_TYPE_USER_EDIT = 0,  /* user edit profile, it is default */
    MMI_IMPS_PROF_TYPE_OTA,            /* OTA profile */
    MMI_IMPS_PROF_TYPE_FACTORY,        /* factory pre-defined profile */    
    MMI_IMPS_PROF_TYPE_TOTAL
} mmi_imps_prof_type_enum;
#endif /* #ifndef __MMI_OP11_IMPS__ */

/* structure of event(message or presence) notification setting */
typedef struct
{
    U8 audio_notify;        /* audio */
    U8 no_visual_notify;    /* visual */
} mmi_imps_event_notify_struct;

/* inline editor structure of event notification setting */
typedef struct  
{
    S32 audio_notify;
    S32 visual_notify;
} mmi_imps_event_notify_edit_struct;

typedef struct  
{
    S32 authorize;
} mmi_imps_authorize_edit_struct;

typedef struct  
{
    S32 link_prof;
} mmi_imps_link_prof_edit_struct;

typedef struct
{
    CHAR username[MMI_IMPS_MAX_USERID_LEN];
    CHAR password[MMI_IMPS_MAX_PSWD_LEN];
} mmi_imps_connect_struct;

typedef struct  
{
    mmi_id menu_id;
    FuncPtr select_func;
} mmi_imps_menu_select_struct;

/* general info of whole IMPS app */
typedef struct
{
    S32 imps_hd;                    /* imps app handler used to send event to imps service */
    U8  imps_version;               /* version used through  this session */
    U8  cbm_app_id;
    MMI_BOOL not_agreed_all;        /* 
                                     * not agreed all content type, 
                                     * it means there is a list indicate the accepted content types by server 
                                     */
    imps_not_agreed_services_struct not_agreed_serv;    /* not agreed service by server */
    U16 str_help;                   /* used for reuse help screen of chat, contact and contact list */
    mmi_imps_menu_select_struct *menu_tbl;              /* used for menu cui */
    cui_menu_type_enum menu_type;
#ifndef __MMI_OP11_IMPS__
    mmi_id main_menu_id;
#endif
} mmi_imps_general_info_struct;

/* info about IMPS app state */
typedef struct
{
    MMI_BOOL is_reentry;        /* re_entry IMPS application when progressing */
    MMI_BOOL auto_update_done;  /* if update finished */
    MMI_BOOL logout_background;
    MMI_BOOL proc_pending_msg;  /* 
                                 * if during the period of processing pending message .
                                 * pending message includes: received files, pa auth, invite, notify message.   
                                 */
    MMI_BOOL is_exit;           /* is exit or logout imps */

#ifdef __MMI_OP11_IMPS_TEST_VER__
/* under construction !*/
#endif
    MMI_BOOL only_update_presence;
} mmi_imps_state_info_struct;

/* info about auto start and auto login */
typedef struct
{
    U8       auto_set_type;         /* auto login or auto start */
    MMI_BOOL is_auto_login;
    MMI_BOOL check_auto_start;      /* has checked auto start in idle */
    MMI_BOOL auto_start_called;
    MMI_BOOL auto_login_called;
    MMI_BOOL auto_start_timeout;
} mmi_imps_auto_login_info_struct;

/* info about presence state */
typedef struct
{
    MMI_BOOL update_pa_background;      /* updating presence backgrounp */
    MMI_BOOL need_fname_alias;
} mmi_imps_presence_info_struct;

/* disconnect info */
typedef struct
{
    MMI_BOOL is_reconn;
    MMI_BOOL is_disconn;
    MMI_BOOL need_reconn;
    U8       reconn_count;      /* counter for login automatically when receive disconnect indication */
    S32      reason;
    CHAR     *detail;
} mmi_imps_disconnect_info_struct;

/* tab bar info */
typedef struct
{
    U8 no_tab;                          /* total number of tab */
    U8 curr_tab;                        /* index of current highlighting tab */
    S8 tab_bar_first_item_index;
    MMI_BOOL tab_bar_use_pen_switch;
} mmi_imps_tab_info_struct;

typedef struct
{
    FuncPtr lskFuncPtr;
    FuncPtr rskFuncPtr;
} mmi_imps_confirm_scr_struct;

/* structure of progressing screen */
typedef struct
{
    CHAR *strBody1;
    CHAR *strBody2;
    FuncPtr lskFuncPtr;
    FuncPtr rskFuncPtr;
    FuncPtr endFuncPtr;
    U16 strCaption;
    U16 imgCaption;
    U16 strLsk;
    U16 imgLsk;
    U16 strRsk;
    U16 imgRsk;
    U16 imgBody;
    U8  login_progress;      /* indicate login stage,  */
} mmi_imps_progress_scr_struct;

typedef struct
{
    mmi_imps_confirm_scr_struct confirm_scr;
    mmi_imps_progress_scr_struct progress_scr;
}mmi_imps_screen_info_struct;

/* mapping between errro code and string index */
typedef struct
{
    S32 err_cause;
    U16 str_id;
} mmi_imps_err_mapping_struct;

/* profile */
#ifdef __MMI_OP11_IMPS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
typedef struct
{
    U8  provurl[MMI_IMPS_OTA_HASH_LEN];                     /* for ota */
    U32 prov_flag;                                          /* for ota */  
    U8  proxy_id[MMI_IMPS_OTA_HASH_LEN];                    /* for ota */    
    WCHAR prof_name[IMPS_PROF_NAME_LEN];                    /* name of profile */
    CHAR server[IMPS_MAX_SERVER_ADDRESS_LEN];                 /* address of server */
    CHAR username[IMPS_MAX_USERID_LEN];                       /* user name */
    CHAR passwd[IMPS_MAX_PASSWORD_LEN];                       /* password */  
    U8 status;                                              /* status of user */
  
    U32   curr_dt_acct[MMI_SIM_TOTAL];                     /* data account */
    U32   active_dt_acct;

    U8 login_mode;                                          /* normal or security */
    U8 proxy_ip[4];                                         /* address of proxy server */    
    U16 proxy_port;                                         /* port number */
} mmi_imps_prof_struct;
#endif /* __MMI_OP11_IMPS__ */

/* about me nvram structure */
typedef struct
{
    WCHAR   pic_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];    /* file name of the picture */
    U8      is_pic;
} mmi_imps_presence_nvram_struct;

/* inline editor structure for when editing about me */
typedef struct
{
    S32      status;                               /* for inline editor */
    S32      is_pic;                               /* for inline editor */ 
    U8       *file_sel_list[2];                    /* for inline editor */    
    WCHAR    alias[IMPS_MAX_NAME_LEN];             /* alias */
    WCHAR    my_pic[IMPS_MAX_PIC_PATH_LEN];        /* original picture */
    WCHAR    file_buff[SRV_FMGR_PATH_MAX_LEN + 1]; /* path from FMGR */
    WCHAR    pic_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];    /* new selected picture */
    MMI_BOOL is_pic_changed;
} mmi_imps_presence_edit_struct;

/* inline editor structure for editing public profile info */
typedef struct
{
    srv_imps_public_profile_struct public_profile;
    U16 country_select;               /* current select country */
    MMI_BOOL edit_cc;                 /* edit country code */
} mmi_imps_public_profile_inline_struct;

/* auto login and auto start setting, stored in nvram */
typedef struct
{
    MMI_BOOL auto_login;
    MMI_BOOL auto_start;
} mmi_imps_setting_struct;

typedef struct  
{
    S32 auto_login;
    S32 auto_start;
} mmi_imps_setting_edit_struct;

typedef struct  
{
    U16 contact_online_tone;
    U16 new_message_tone;
    U16 new_invitation_tone;
    U16 room_notification_tone;
} mmi_imps_tone_setting_struct;

/* nvram struct */
typedef struct
{
    mmi_imps_presence_nvram_struct about_me;        /* about me */
#ifdef __MMI_OP11_IMPS__    
/* under construction !*/
#else
    mmi_imps_prof_struct prof[IMPS_PROF_COUNT];     /* list of profile */
    U8 act_prof_indx;                               /* index of active profile */
#endif
    mmi_imps_setting_struct        setting;         /* imps setting */
    mmi_imps_event_notify_struct   ms_notify;       /* message notification */    
    mmi_imps_event_notify_struct   pr_notify;       /* presence notification */
    mmi_imps_tone_setting_struct   tone_setting;    /* tone setting */
    U8 not_link_prof;                               /* link with profile or not */
    U8 authorize;                                   /* reactive or proactive authorization */
} mmi_imps_nvram_struct;


/* structure used when to store temporary data when editing a profile. */
#ifdef __MMI_OP11_IMPS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP11_IMPS_TEST_VER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_OP11_IMPS_TEST_VER__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP11_IMPS__ */
typedef struct
{
    U8  status;
    S32 login_mode;                             /* normal and security */
    WCHAR prof_name[IMPS_PROF_NAME_LEN];        /* profile name */
    WCHAR server[IMPS_MAX_SERVER_ADDRESS_LEN];  /* server address */
    WCHAR username[IMPS_MAX_USERID_LEN];        /* username */
    WCHAR passwd[IMPS_MAX_PASSWORD_LEN];        /* password */
  
    U32   curr_dt_acct[MMI_SIM_TOTAL];                     /* data account */

    WCHAR   dt_acct_name[2 * (MAX_DATA_ACCOUNT_NAME_LEN + 1)];
    MMI_BOOL is_changed;
} mmi_imps_prof_edit_struct;
#endif /* #ifdef __MMI_OP11_IMPS__ */


/* all misc application when modifying profile settings. */
typedef struct
{
    mmi_imps_presence_edit_struct       *my_prof;
#ifdef __MMI_OP11_IMPS__
/* under construction !*/
#else
    mmi_imps_prof_edit_struct           *edit_prof;   /* for edit setting->prof */
    WCHAR prof_name_list[IMPS_PROF_COUNT][IMPS_PROF_NAME_LEN];      /* List of profile names */
    U8 act_prof_indx;     /* Index of current active profile */
    U8 hilte_prof;        /* Index of current highlighted profile */
    U8 setting_type;
#endif
    U8                                  notify_type;  /* for edit notification */
    U8                                  tone_type;    /* for edit tone setting */ 
    mmi_imps_event_notify_edit_struct   *ms_notify;   /* for edit message notification */
    mmi_imps_event_notify_edit_struct   *pr_notify;   /* for edit presence notification */
    mmi_imps_setting_edit_struct        *setting;     /* for edit auto login */
    mmi_imps_link_prof_edit_struct      *link_prof;
    mmi_imps_authorize_edit_struct      *authorize;
} mmi_imps_prof_misc_struct;

#ifdef __MMI_OP11_IMPS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP11_IMPS__ */
/* structure used to store each OTA profile infomation */
typedef struct
{
    mmi_imps_prof_struct prof_info;      /* ota profile */
    U8  is_proxy;                        /* whether use proxy or not */
    U8  is_valid;                        /* whether this profile is valid, app addr and app auth are ok */
    U8  is_used;                         /* whether this profile is used */
    U8  is_app_addr;                     /* whether exist valid app address */
    U8  is_app_auth;                     /* whether exist valid app authorization information */    
    U8  update_index;                    /* the index of nvram prof to update when prof match,
                                            if no match prof, its value is 0xFF */
} mmi_imps_ota_prof_struct;
#endif /* #ifdef __MMI_OP11_IMPS__ */

/* structure used to store all info of OTA */
typedef struct
{

#ifdef __MMI_OP11_IMPS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP11_IMPS__ */
    mmi_imps_ota_prof_struct *info[IMPS_PROF_COUNT * 2];                  /* ota profile */
    /* 
     * list profiles name when all profiles configured for user to select which one to replace 
     */
    UI_character_type prof_name[IMPS_PROF_COUNT][IMPS_PROF_NAME_LEN]; 
    /* 
     * profile index to record app information because one app may include mulitple proxy 
     */
    MMI_BOOL app_prof_index[IMPS_PROF_COUNT * 2]; 
    MMI_BOOL is_curr_store; /* whether current profile can be store*/
    U8 is_act;              /* whether have activated profile */
    U8 total;               /* total number of ota profiles this time */
    U8 valid_no;            /* valid profile num */
    U8 curr_index;          /* current handling ota profile index */
    MMI_BOOL is_install;    /* whether install profiles */        
    MMI_BOOL is_update;     /* whether update match profile */
    MMI_BOOL is_skip;        /* whether skip some profile */
    U8 hilite_prof;         /* index of highlighting profile */
    U16 sim_id;             /* sim_id indicate which sim card from*/
    U16 config_id;          /* id of configure application */
    S32 hConfig;            /* handler of ota */    
    U32 prov_flag;          /* for factory profile, updatable */
    U8 provurl[MMI_IMPS_OTA_HASH_LEN];      
#endif /* #ifdef __MMI_OP11_IMPS__ */
} mmi_imps_ota_info_struct;

/* search contact criteria structure for inline editor screen */
typedef struct
{
    S32   domain;
    WCHAR user_emailaddr[IMPS_MAX_USER_EMAIL_ADDRESS_LEN];      /* User email address */
    WCHAR user_mobile_number[IMPS_MAX_USER_MOBILE_PHONE_LEN];   /* User mobile number */
    WCHAR *domain_list[10];
    U8    search_type;
} mmi_imps_search_cont_struct;

/* 
 * orange has no search group feature 
 */

/* structure to store result of search */   
typedef struct
{
    imps_entity_struct entity;                  /* entity of search result */
    U8 count;                                   /* number of items in search result */
    U8 curr_item;                               /* index of current selected item in search result screen */
} mmi_imps_search_result_struct;

/* data structure of a contact */
typedef struct
{
    U32 srv_index;            /* contact index, which is generated by imps service */
    U8  availability;         /* availability */
    MMI_BOOL unread_msg;      /* is this contact has unread new message */
} mmi_imps_cont_struct;

/* general information of all contacts */
typedef struct
{
    mmi_imps_cont_struct cont[SRV_IMPS_MAX_CONT_COUNT];  /* array of contacts */
    U8 no_cont;                      /* number of contact */
    U8 add_type;                     /* add contact directly or add by search */
    MMI_BOOL move_cont;
    WCHAR *pp_buff;
} mmi_imps_cont_info_struct;

typedef struct
{
    U32 srv_index;          /* contact list index generated by imps service */
    MMI_BOOL is_open; 
} mmi_imps_cont_list_struct;

typedef struct
{
    WCHAR* cont_list_name;                                                  /* inline editor structure */
    mmi_imps_cont_list_struct cont_list[SRV_IMPS_MAX_CONTACT_LIST_COUNT];   /* contact list array */
    U8 no;                                                                  /* contact list number */
    U8 curr_item;                                                           /* current selected item */
    U8 is_created;      /*
                         * auxiliary variable to indicate 
                         * the group is editing or creating 
                         * when in inline editor screen 
                         */
} mmi_imps_cont_list_info_struct;

/* structure to store chatting information */
typedef struct
{
    WCHAR input_buff[IMPS_MAX_CHAT_INPUT_LEN + 1];  /* buffer of current input message */        
    U8    sel_sym;      /* current selected symbol */
    U8    sel_template; /* current selected template */ 
} mmi_imps_chat_info_struct;

/* overall information of notify message */
typedef struct
{
    imps_message_info_struct *curr_msg;
    void *info;                           /* used to show information of notify message */        
    MMI_BOOL need_notify;                 /* need to notify user when get message fail */
    MMI_BOOL tone_played;                 /* to avoid re-entry to play tone again after end-key */
} mmi_imps_notify_msg_struct;

typedef struct
{    
    CHAR  content_type[IMPS_MAX_CONTENT_TYPE_LEN];
    WCHAR message_content[IMPS_MAX_CONTENT_LEN];
} mmi_imps_message_struct;

typedef struct
{
    mmi_imps_message_struct *info;    
    U8  curr_msg;
    WCHAR *tmp_input_buff;    
    MMI_BOOL is_used[IMPS_MAX_PEND_FILE_MSG_COUNT];
} mmi_imps_message_info_struct;

/* 
 * structure of hilite string information.
 * hilite string contains phone numbers and URLs.  
 * this structure used for the feature of click to call.
 */
typedef struct
{
    HILITE_STR hilite_list[MMI_IMPS_MAX_NO_HILITE_STR]; /* hilite string list */
    U8 hilite_type[MMI_IMPS_MAX_NO_HILITE_STR];         /* hilite string type */
    U8 hilite_no;                                       /* number of hilite strings */
    U8 curr_hilite;                                     /* index of current hilite string */
    MMI_BOOL is_visible;                                /* Is current highlight string in visible area of chat screen */
} mmi_imps_hilite_str_info_struct;

/* structure of a chat room */
typedef struct
{
    U32      srv_index;                            /* room index generated by imps service */
    WCHAR    chat_buff[IMPS_MAX_CHAT_BUFF + 1];    /* buffer of chat history */
    WCHAR    tab_text[MMI_IMPS_TAB_TEXT_LEN];      /* tab string */
    U8       tab_index;                            /* tab index that the chat room belongs to */
    MMI_BOOL clear_gui_buff;                       /* if clear GUI buffer is needed */
    MMI_BOOL unread_msg;                           /* if there is any unread message for in the chat room */
    MMI_BOOL edit_mode;                            /* it's in EDIT mode or not */
    MMI_BOOL is_closed;                            /* chat room is closed by remote group creator */
    MMI_BOOL  not_send_msg;                         /* char room if have message that not sended when close input mode*/ 
    U8       curr_hilite;                          /* index of current hilite string(phone number or URL)*/
    MYTIME   lastest_msg_time;
    U32      lastest_msg_len;
    MMI_BOOL tab_blink;                            /* room tab is blink or not */
} mmi_imps_room_struct;

/* structure of inline editor screen when join/create a chat room */
typedef struct
{
    WCHAR room_name[IMPS_MAX_NAME_LEN]; /* name of chat room */
    WCHAR sname[IMPS_MAX_NAME_LEN];     /* user's screen name in the chat room */
} mmi_imps_room_inline_struct;

/* overall information of chat rooms */
typedef struct
{
    mmi_imps_room_struct room_list[SRV_IMPS_MAX_ROOM_COUNT];    /* list of chat rooms */
    WCHAR room_name[IMPS_MAX_NAME_LEN];             /* name of the current chat room */
    U8 no_rooms;                                    /* number of chat rooms */
    U8 curr_item;                                   /* current selected room in room list screen */
    U8 curr_room;                                   /* current selected chat room array index */
    U8 curr_sel_user;                               /* Index of current selected user */  
    U8 mm_msg_type;                                 /* current multimedia message type */
    MMI_BOOL withdraw_cont;                         /* list joined user to eject contact */
    MMI_BOOL audio_play_back;                       /* back from audio player */
    MMI_BOOL video_play_back;                       /* back from video player */
    mmi_imps_hilite_str_info_struct hilite_info;    /* hilite string information */
    mmi_imps_room_inline_struct *inline_open_room;  /* inline editor for creating a chat room */
    WCHAR *join_sname;                              /* screen name of the user for join a group */
} mmi_imps_room_info_struct;

typedef struct
{
    U32 entity_num;
    U32 myself_index;    
    U32 curr_sel_user;
} mmi_imps_group_info;

/* overall information of invitation */
typedef struct
{
    WCHAR *invite_note;                                 /* buffer for invitation string */
    U32    invite_cand_list[SRV_IMPS_MAX_CONT_COUNT];   /* 
                                                         * temporary list of contact that can be invite 
                                                         * store contact index generated by imps service    
                                                         */
    U8     curr_sel_cont;                               /* index of current selected contact to invite */
    mmi_imps_invite_ind_struct *node;
} mmi_imps_invite_info_struct;

/* data structure used in View Friend's Detail screen */
typedef struct
{
    U32   index;                                /* contact index, generated by imps service */
    WCHAR *profile_text;                        /* pointer of profile text: profile text = profile text + public profile */
    WCHAR file_name[IMPS_MAX_FILE_NAME_LEN];    /* image file name */
    WCHAR *id_buf;
    srv_imps_public_profile_struct *pp_buf;
} mmi_imps_about_friend_struct;

/* data structure used in processing system message */
typedef struct
{
    imps_system_message_option_struct option[IMPS_MAX_SM_OPTION_NUM];
    WCHAR verification_key[IMPS_MAX_URL_LEN];               /* verification key */
    WCHAR verification[IMPS_MAX_URL_LEN];                   /* verification */
    CHAR  curr_sm_id[IMPS_MAX_SM_ID_LEN];                   /* current system message id */
    U8    sel_option;                                       /* user selected option */
    U8    option_count;                                     /* option count */
    U8    verification_type;                                /* verification type */
    BOOL  need_rsp;                                         /* need response or not */
    BOOL  is_give_up;                                       /* give up or not */
    CHAR  *sm_text;                                         /* text of system message information */
} mmi_imps_system_message_struct;


/* data structure used in processing presence authentication indication */
typedef struct
{
    imps_entity_struct auth_user;         /* current processing user */
    U32 attr_list;                        /* attribute list */
} mmi_imps_presence_auth_struct;

typedef struct
{
    WCHAR username[IMPS_MAX_NAME_LEN];
    WCHAR password[IMPS_MAX_AUTH_PWD_LEN];    
} mmi_imps_http_auth_struct;

typedef struct
{
    U32 srv_index;               /* contact or contact list array index */
    U8 level;
    U8 open_close;
} mmi_imps_tree_item_struct;

/* structure of contact list tree highlight item */
typedef struct
{
    U8  tree_index;             /* index of tree info array */
    U8  level;                  /* item level, contact list or contact */
    U32 srv_index;              /* contact or contact list index of imps service */
} mmi_imps_hilite_tree_item_struct;

/* contact list display tree info */
typedef struct
{
    mmi_imps_tree_item_struct item[SRV_IMPS_MAX_CONTACT_LIST_COUNT + SRV_IMPS_MAX_CONT_COUNT];
    U8 total;
    mmi_imps_hilite_tree_item_struct hilite_item;   /* current highlight tree item */
    MMI_BOOL cont_fold_unwrap;
    MMI_BOOL clear_gui_buff;                        /* 
                                                     * flag to indicate if the GUI buffer of contact list screen 
                                                     * shall be cleared or not 
                                                     */
    MMI_BOOL update_tree;
} mmi_imps_tree_info_struct;

typedef struct  
{
    WCHAR user_name[IMPS_MAX_NAME_LEN];
    WCHAR nick_name[IMPS_MAX_NAME_LEN];
    S32   domain;
    WCHAR *domain_list[10];
} mmi_imps_add_cont_struct;

typedef struct
{
    void *pa_visual_info;
    void *image_info;
} mmi_imps_pa_visual_struct;

typedef struct
{
    U32   cur_page_index;                         /* the index of current displayed page */
    U32   total_page;                             /* total pages of log file  */
    U32   cur_page_size;                          /* the size of current displayed page */
    WCHAR *title_text; 
    U8    state;                                  /* state of calcatlate, refer to mmi_imps_view_log_state */
    WCHAR jump_page[9];                           /* the page user want to jump to */
    WCHAR path_buff[(SRV_FMGR_PATH_MAX_LEN + 1)]; /* buffer to store file path */
}mmi_imps_log_page_info_struct;

typedef struct
{
    MMI_ID inline_cui_gid;                      /* for inline cui */
    MMI_ID editor_cui_gid;                      /* for editor cui */
} mmi_imps_cui_info_struct;

typedef struct
{
    mmi_imps_general_info_struct        gen_info;           /* general information of IMPS application */

    mmi_imps_state_info_struct          state_info;
        
    mmi_imps_auto_login_info_struct     auto_login_info;
    
    mmi_imps_presence_info_struct       presence_info;
    
    mmi_imps_disconnect_info_struct     disc_info;
    
    mmi_imps_tab_info_struct            tab_info;

    mmi_imps_nvram_struct               nvram_info;          /* NVRAM infomation */

    mmi_imps_prof_misc_struct           prof_misc;           /* misc data for editing profile */

    mmi_imps_prof_edit_struct           *login_info;

    mmi_imps_ota_info_struct            *ota_prof;           /* misc data for editing profile */    

    mmi_imps_cont_info_struct           cont_info;           /* contact informaion */

    mmi_imps_cont_list_info_struct      cont_list_info;      /* contact list informaion */

    mmi_imps_search_cont_struct         *search_cont;        /* search criteria */    

    mmi_imps_search_result_struct       search_result;       /* result of searching */ 

    mmi_imps_public_profile_inline_struct *pp_info;          /* inline buffer for editing public profile */

    mmi_imps_chat_info_struct           chat_info;           /* chatting related information */

    mmi_imps_notify_msg_struct          notify_msg;          /* pending notify message and list messge */

    mmi_imps_message_info_struct        new_msg;             /* pending new message */

    mmi_imps_room_info_struct           room_info;           /* chat room information */

    mmi_imps_group_info                 group_info;          /* group information */

    mmi_imps_invite_info_struct         invite_info;         /* invitation related information */
    
    mmi_imps_about_friend_struct        friend_info;         /* information of a friend when view his detail */

    mmi_imps_screen_info_struct         screen_info;         /* general screen info */

    mmi_imps_system_message_struct      *system_message;     /* system message info */

    mmi_imps_presence_auth_struct       *pa_auth;            /* presence authentication */

    mmi_imps_http_auth_struct           *http_auth;

    WCHAR path_buff[SRV_FMGR_PATH_MAX_LEN + 1];              /* common buffer to store file path */

    WCHAR file_buff[SRV_FMGR_PATH_MAX_FILE_NAME_LEN];        /* common buffer to store file name */

    WCHAR disp_name[IMPS_MAX_NAME_LEN];                      /* for myself, it is alias, for friend, it is nickname */

    void *history_buffer;
    
    mmi_imps_tree_info_struct           tree_info;

    mmi_imps_pa_visual_struct           visaul_info;

    mmi_imps_add_cont_struct            new_cont;

	mmi_imps_log_page_info_struct       log_page_info;

    mmi_imps_cui_info_struct            cui_info;
} mmi_imps_context_struct;


/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern mmi_imps_context_struct *imps_p;
extern const WCHAR *mmi_imps_domain[];

extern U16 g_imps_curr_sel_menu_item;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

#define EVENT_IMPS
extern void mmi_imps_app_event_hdlr(srv_imps_event_enum event_id, void *msg);

/* login, logout */
extern S32 mmi_imps_event_login_req(void);
extern S32 mmi_imps_event_logout_req(MMI_BOOL force);
extern S32 mmi_imps_event_abort_login_req(MMI_BOOL force);

/* contact, contact list */
extern S32 mmi_imps_event_add_contact_list_req(void);
extern S32 mmi_imps_event_edit_contact_list_req(void);
extern S32 mmi_imps_event_del_contact_list_req(void);
extern S32 mmi_imps_event_add_cont_req(U32 cont_list_srv_index, CHAR *cont_id, WCHAR *nick_name);
extern S32 mmi_imps_event_edit_cont_req(U32 cont_srv_index, WCHAR *nick_name);
extern S32 mmi_imps_event_del_cont_req(void);
extern S32 mmi_imps_event_move_cont_req(U32 cont_srv_index, U32 to_cont_list_index);

/* pa */
extern S32 mmi_imps_event_create_default_attribute_list_req(void);
extern S32 mmi_imps_event_update_alias_req(WCHAR *user_alias);
extern S32 mmi_imps_event_update_user_status_req(U8 status);
extern S32 mmi_imps_event_get_single_pa_req(U32 cont_srv_index);
extern S32 mmi_imps_event_get_about_me_pa_req(void);
extern S32 mmi_imps_event_abort_get_pa_req(void);
extern S32 mmi_imps_event_update_pa_req(void);
extern S32 mmi_imps_event_subs_all_pa_req(void);
extern S32 mmi_imps_event_get_block_list_req(void);
extern S32 mmi_imps_event_block_entity_req(MMI_BOOL is_block_cont);
extern S32 mmi_imps_event_get_pp_req(void);
extern S32 mmi_imps_event_abort_get_pp_req(void);
extern S32 mmi_imps_event_update_pp_req(void);
extern S32 mmi_imps_event_subs_notify_req(void);
extern S32 mmi_imps_event_unsubs_notify_req(void);
extern S32 mmi_imps_event_get_all_pa_req(void);

/* group */
extern S32 mmi_imps_event_create_group_req(void);
extern S32 mmi_imps_event_del_group_req(U32 room_srv_ndex);
extern S32 mmi_imps_event_join_group_req(CHAR *id);
extern S32 mmi_imps_event_leave_group_req(U32 room_srv_ndex);
extern S32 mmi_imps_event_get_joined_user_req(void);
extern S32 mmi_imps_event_abort_get_joined_user_req(void);
extern S32 mmi_imps_event_get_rejected_user_req(void);
extern S32 mmi_imps_event_abort_get_rejected_user_req(void);
extern S32 mmi_imps_event_reject_group_user_req(void);
extern S32 mmi_imps_event_del_reject_group_user_req(void);

/* message */
extern S32 mmi_imps_event_send_msg_req(
               U32 room_srv_ndex, 
               WCHAR *msg, 
               WCHAR *orig_path, 
               WCHAR *screen_name, 
               S32 send_msg_type);
extern S32 mmi_imps_event_system_message_user_req(void);
extern S32 mmi_imps_event_get_msg_req(CHAR *msg_id);
extern S32 mmi_imps_event_reject_msg_req(CHAR *msg_id);

extern S32 mmi_imps_event_dl_large_file_req(void);
extern S32 mmi_imps_event_get_about_me_pp_req(void);
extern void mmi_imps_event_invite(srv_imps_event_enum event_id, void *msg);
extern S32 mmi_imps_event_invite_group_req(U32 cont_srv_index, U32 room_srv_index);
extern S32 mmi_imps_event_ext_conv_req(U32 cont_srv_index, U32 room_srv_index);
extern S32 mmi_imps_event_search_cont_req(void);
extern S32 mmi_imps_event_abort_search_req(void);


#define INIT_IMPS
/* init function */
extern void mmi_imps_init_read_nvram(void);
extern void mmi_imps_init_acct(void);
extern void mmi_imps_init_chat(void);
extern void mmi_imps_init_app_id(void);
extern void mmi_imps_init_list(void);
extern void mmi_imps_reset_cntx(void);


#define COMMON_IMPS
/* main menu */
extern MMI_BOOL mmi_imps_is_allow_entry(void);
extern void mmi_imps_entry_main(void);
extern void mmi_imps_pre_entry_cont(void);

extern MMI_BOOL mmi_imps_curr_action_idle(void);
extern void mmi_imps_unsubs_notify_finished(S32 result);

/* disconnect */
extern void mmi_imps_retry_backgroud(void);
extern void mmi_imps_retry_connect_backgroud(void);
extern void mmi_imps_entry_disconn(MMI_BOOL force);
extern void mmi_imps_auto_reconn(U8 is_in_imps);
extern void mmi_imps_disconnect(U32 cause);


#define UI_CORE
extern void mmi_imps_display_progressing(void);
extern void mmi_imps_entry_abort(void);

extern void mmi_imps_pre_entry_progressing(
                U16 strCaption,
                U16 imgCaption,
                U16 strLsk,
                U16 imgLsk,
                U16 strRsk,
                U16 imgRsk,
                CHAR *strBody1,
                CHAR *strBody2,
                U16 imgBody,
                FuncPtr lskFuncPtr,
                FuncPtr rskFuncPtr,
                FuncPtr endFuncPtr);

extern void mmi_imps_entry_confirm(U16 msg, FuncPtr lskFuncPtr, FuncPtr rskFuncPtr);

extern void mmi_imps_entry_confirm_str(
                WCHAR* lsk_str,  
                PS8 lsk_img,
                WCHAR* rsk_str,  
                PS8 rsk_img,
                WCHAR* msg,
                FuncPtr lskFuncPtr, 
                FuncPtr rskFuncPtr);

extern void mmi_imps_entry_confirm_screen(
                U16 scr_id,
                FuncPtr newEntryHandler,
                U16 msg,
                FuncPtr lskFuncPtr,
                FuncPtr rskFuncPtr);

extern void mmi_imps_entry_help(void);

/* menu list */
extern MMI_ID mmi_imps_entry_menu(
                mmi_id group_id,
                cui_menu_type_enum type, 
                mmi_id menu_id, 
                mmi_imps_menu_select_struct *tbl);

extern MMI_BOOL mmi_imps_exec_menu_func(mmi_id menu_gid, mmi_id menu_item_id, mmi_imps_menu_select_struct *table);

extern void mmi_imps_menu_list_hilite_hdlr(S32 hilite_index);
extern void mmi_imps_exec_menu_item_sel_function(mmi_imps_menu_select_struct *menu_table, U16 menu_id);
extern void mmi_imps_cont_menu_sel_hdlr(void);

extern mmi_ret mmi_imps_cui_phb_event_proc(mmi_event_struct *evt);


#define LOGIN_LOGOUT_IMPS
extern void mmi_imps_entry_login_opt_help(void);
extern void mmi_imps_login_opt_exit(void);
extern void mmi_imps_login_opt_exist_acct(void);
extern void mmi_imps_entry_login_opt_acct(void);
extern U16  mmi_imps_login_progress_str(U8 status);
extern void mmi_imps_login_progress_ind(U8 status);
extern void mmi_imps_auto_login(void);
extern void mmi_imps_login_abort_finish(void);
extern void mmi_imps_entry_show_login_pwd(void);
extern void mmi_imps_pre_entry_logo(void);
extern void mmi_imps_save_login_info(void);
extern void mmi_imps_re_entry_app(void);
extern void mmi_imps_logout_confirm(void);
extern void mmi_imps_logout_complete(void);
extern void mmi_imps_logout_hdlr(void);
extern void mmi_imps_cut_domain(WCHAR *user_id);

#define PROFILE_IMPS
extern void mmi_imps_entry_setting(void);
extern U32 mmi_imps_get_data_acct_id(void);
extern void mmi_imps_set_srv_data_acct(void);
extern void mmi_imps_my_prof_free_mem(void);
extern void mmi_imps_free_nickname(void);

extern void mmi_imps_pre_entry_setting_my_prof(void);
extern void mmi_imps_setting_opt_auto_login(void);
extern void mmi_imps_setting_opt_auto_start(void);
extern void mmi_imps_pre_entry_setting_link_prof(void);
extern void mmi_imps_entryt_tone_setting(void);


#define CONTACT_IMPS
/* contact util */
extern S32 mmi_imps_get_cont_index(U32 cont_list_srv_index);
extern S32 mmi_imps_get_cont_list_index(U32 cont_list_srv_index);
extern U32 mmi_imps_get_curr_cont_srv_index(void);
extern U32 mmi_imps_get_curr_cont_list_srv_index(void);
extern S32 mmi_imps_get_curr_cont_index(void);
extern S32 mmi_imps_get_curr_cont_list_index(void);
extern void mmi_imps_update_cont_list_info(void);
extern void mmi_imps_update_cont_info(void);
extern void mmi_imps_sync_cont_list(void);
extern MMI_BOOL mmi_imps_is_contact_available(void);

extern void mmi_imps_entry_cont_opt(void);
extern void mmi_imps_cont_redraw_list(void);
extern void mmi_imps_cont_update_when_msg_come(S32 cont_index);
extern void mmi_imps_cont_reset_msg_icon(void);
extern void mmi_imps_entry_del_cont_confirm(void);
extern void mmi_imps_del_cont_finished(CHAR *desc, S32 result);
extern void mmi_imps_move_cont_finished(CHAR *desc, S32 result);
extern void mmi_imps_entry_cont_input_name(void);
extern void mmi_imps_cont_list_edit_finished(CHAR *desc, S32 result);
extern void mmi_imps_cont_list_del_finished(CHAR *desc, S32 result);
extern void mmi_imps_entry_manage_cont(void);

extern void mmi_imps_update_local_cache(mmi_imps_nvram_struct *nvram_buff);
extern void mmi_imps_status_visual_notify(const mmi_imps_cont_struct *cont);

/* add contact */
extern void mmi_imps_entry_add_cont_from_phb(void);
extern MMI_BOOL mmi_imps_is_add_cont_from_phb(void);
extern void mmi_imps_add_cont_finished(CHAR *desc, S32 result);
extern void mmi_imps_pre_entry_sel_cont_list(void);


#define SEARCH_IMPS
extern void mmi_imps_select_search_by_email(void);
extern void mmi_imps_select_search_by_phone_number(void);
extern void mmi_imps_select_search_direct_input_number(void);
extern void mmi_imps_select_search_load_number(void);
extern void mmi_imps_search_start(void);
extern void mmi_imps_search_quit(void);
extern void mmi_imps_entry_search_result(void);
extern void mmi_imps_entryt_search_opt(void);
extern void mmi_imps_entry_add_stranger_opt(void);
extern void mmi_imps_abort_search_finish(void);
extern void mmi_imps_search_phb_callback(U16 store_index);

extern void mmi_imps_notify_phb_add_cont_success(S16 result, WCHAR *user_id);
extern void mmi_imps_notify_phb_add_cont_fail(S32 result, CHAR *detail);
extern void mmi_imps_notify_phb_add_cont_cancel(void);

extern void mmi_imps_notify_phb_disc(void);

#define PRESENCE_IMPS
/* about me */
extern void mmi_imps_select_about_me(void);
extern void mmi_imps_check_pp_mandatory(void);
extern void mmi_imps_check_alias(void);
extern void mmi_imps_input_alias_confirm(void);
extern void mmi_imps_update_alias_finish(CHAR *desc, S32 result);
extern MMI_BOOL mmi_imps_alias_is_valid(WCHAR *alias);

/* about friend */
extern void mmi_imps_select_about_friend(void);
extern void mmi_imps_select_about_friend_edit(void);
extern void mmi_imps_about_friend_edit_done(void);
extern void mmi_imps_about_friend_edit_finish(CHAR *desc, S32 result);
extern void mmi_imps_select_about_friend_refersh(void);
extern void mmi_imps_about_friend_refresh_finish(void);
extern void mmi_imps_presence_save_finish(CHAR *desc, S32 result);
extern void mmi_imps_public_profile_save_done(CHAR *desc, S32 result);
extern void mmi_imps_entry_edit_friendly_name_confirm(void);
extern void mmi_imps_contact_pp_string(WCHAR *buffer, srv_imps_public_profile_struct *pp_info);

extern void mmi_imps_update_cont_pa(void);
extern void mmi_imps_save_user_status(U8 user_status);

/* block, grant */
extern void mmi_imps_block_grant_finished(CHAR *desc, S32 result);


#define SYSTEM_MESSAGE_IMPS
extern void mmi_imps_entry_system_message(void);
extern MMI_BOOL mmi_imps_exist_system_message(void);
extern void mmi_imps_check_system_message(void);


#define HTTP_AUTH_IMPS
extern void mmi_imps_entry_http_auth(void);
extern void mmi_imps_http_auth_no_hdlr(void);
extern void mmi_imps_http_auth_yes_hdlr(void);
extern void mmi_imps_event_send_http_auth_res(void);


#define CHAT_IMPS
extern U32 mmi_imps_get_curr_room_srv_index(void);
extern S32 mmi_imps_get_room_index(U32 room_srv_index);
extern void mmi_imps_pre_entry_chat(void);
extern void mmi_imps_entry_chat(void);
extern void mmi_imps_refresh_chat_screen(void);
extern void mmi_imps_refresh_curr_chat_screen(void);
extern void mmi_imps_select_chat_save(void);
extern void mmi_imps_chat_room_close_finished(CHAR *detail, S32 result);
extern void mmi_imps_reset_chat_room_data(void);
extern void mmi_imps_chat_recv_msg(srv_imps_newmessage_ind_struct *ind, U32 room_index);
extern void mmi_imps_chat_disp_user_change_msg(U32 room_index, imps_entity_struct *joined_user, S32 type);
extern void mmi_imps_chat_display_send_failed(U32 room_index, WCHAR *msg);
extern void mmi_imps_chat_flush_msg(WCHAR *data, U32 room_index);
extern void mmi_imps_chat_hide_input_screen(BOOL redraw);

#define MSG_IMPS
extern void mmi_imps_check_pending_msg(void);
extern MMI_BOOL mmi_imps_check_pending_invite(void);
extern MMI_BOOL mmi_imps_check_pending_pa_auth(void);
extern MMI_BOOL mmi_imps_write_message_to_file(srv_imps_newmessage_ind_struct *ind);
extern void mmi_imps_delete_message_file(void);

#define GROUP_IMPS
extern void mmi_imps_entry_room(void);
extern void mmi_imps_free_room_mem(void);
extern void mmi_imps_room_jump_to(void);
extern void mmi_imps_get_joined_user_finished(CHAR *desc, S32 result);
extern void mmi_imps_pre_entry_join(void);
extern void mmi_imps_join_room_finished(void *msg);
extern void mmi_imps_join_room_fill(srv_imps_join_group_rsp_struct *rsp);
extern void mmi_imps_get_rejected_user_finished(CHAR *desc, S32 result);
extern void mmi_imps_add_reject_user_done(CHAR *desc, S32 result);
extern void mmi_imps_delete_reject_user_done(CHAR *desc, S32 result);
extern void mmi_imps_select_list_joined(void);
extern void mmi_imps_entry_chat_withdraw_cont(void);
extern void mmi_imps_select_room_create(void);

extern void mmi_imps_select_room_close(void);
extern void mmi_imps_pre_entry_chat_list_rejected(void);

#define INVITE_IMPS
extern void mmi_imps_select_chat_invite(void);
extern void mmi_imps_invite_accept(void);
extern void mmi_imps_add_stranger_opt_sel_add(void);
extern void mmi_imps_add_stranger_opt_sel_get_pp(void);
extern void mmi_imps_get_stranger_pp_rsp(void *msg);
extern void mmi_imps_pa_auth_reject_comfirm(void);

#define ROOM_IMPS
extern MMI_BOOL mmi_imps_get_curr_room_detail(srv_imps_room_prop_struct *room);
extern MMI_BOOL mmi_imps_create_new_chat_room(S32 room_index, S32 cont_srv_index, CHAR *cont_id);
extern void mmi_imps_room_create_finish(CHAR *detail, S32 result, U32 room_srv_index);
extern void mmi_imps_add_chat_room_header(mmi_imps_room_struct *room);
extern void mmi_imps_close_curr_chat_room(void);
extern void mmi_imps_chat_room_close_done(mmi_imps_room_struct *room);


#define UTIL_TAB_IMPS
extern void mmi_imps_tab_init(void);
extern void mmi_imps_tab_del(U8 tab_index, U8 hilite);
extern void mmi_imps_tab_prev(void);
extern void mmi_imps_tab_next(void);
extern void mmi_imps_tab_jump(int index);
extern void mmi_imps_tab_redraw(U16 scr_id);
extern void mmi_imps_tab_update_event(U32 room_index);
extern void mmi_imps_tab_stop_timer(void);
extern void mmi_imps_tab_set_key_handler(void);


#define UTIL_COMMON_IMPS
extern U16 mmi_imps_util_get_err_str(S32 err);
extern U16 mmi_imps_util_get_srv_err_str(S32 err);
extern void mmi_imps_util_get_app_work_path(WCHAR *dest);
extern MMI_BOOL mmi_imps_util_is_imps_scr(U16 curr_scr);
extern MMI_BOOL mmi_imps_util_is_in_imps(void);
extern MMI_BOOL mmi_imps_util_is_imps_screen_group_active(void);
extern MMI_BOOL mmi_imps_util_is_in_imps_app(void);
extern void mmi_imps_util_del_scr_after_progress(U16 result_scr);
extern void mmi_imps_util_read_nvram(void *buff);
extern void mmi_imps_util_write_nvram(void *buff);
extern U8 mmi_imps_util_check_file_size(void *filePath);
extern WCHAR* mmi_imps_util_gen_temp_file(void);
extern void mmi_imps_util_reset_presence(mmi_imps_nvram_struct *nvram_data);
extern S32 mmi_imps_util_get_empty_room_index(void);
extern CHAR *mmi_imps_get_mine_type(CHAR *file_ext);
extern void mmi_imps_util_generate_name_hint(WCHAR *source, S32 hint_id, S32 max_len);
extern void mmi_imps_util_blink_tab(void);
extern void mmi_imps_util_update_status_icon(void);
extern void mmi_imps_util_update_login_icon(void);
extern void mmi_imps_util_change_login_icon(MMI_BOOL is_auto_login);
extern MMI_ID mmi_imps_get_app_menu_id(void);
extern MMI_ID mmi_imps_get_root_title_icon(void);
extern void mmi_imps_util_disp_info_popup(U16 str_id);
extern void mmi_imps_util_disp_info_popup_str(WCHAR *str);
extern void mmi_imps_util_disp_err_popup(U16 str_id);
extern void mmi_imps_util_disp_err_popup_str(WCHAR *str);
extern void mmi_imps_util_disp_fail_popup(U16 str_id);
extern void mmi_imps_util_disp_fail_popup_str(WCHAR *str);
extern void mmi_imps_util_disp_srv_fail_str(S32 result);
extern void mmi_imps_util_disp_fail_str(CHAR *detail, S32 result);
extern void mmi_imps_util_disp_progress_popup(U16 str_id);
extern void mmi_imps_util_disp_empty_popup(void);
extern void mmi_imps_util_disp_popup_done(void);
extern void mmi_imps_util_disp_popup(U16 str_id);
extern void mmi_imps_util_disp_warning_popup(U16 str_id);
extern void mmi_imps_util_play_tone(U8 tone_type);
extern U16 mmi_imps_get_tone_id(U32 tone_type);
extern S32 mmi_imps_util_find_room(U32 room_srv_ndex);
extern MMI_BOOL mmi_imps_util_is_call_interrupt_forbid(void);
extern MMI_BOOL mmi_imps_check_white_spaces(CHAR *string);
extern U8 mmi_imps_util_is_on_idle(void);
extern MMI_BOOL mmi_imps_check_ip(U8 *ip, CHAR *data, S32 len);
extern S32 mmi_imps_util_get_domain(WCHAR *user_id);
extern void mmi_imps_check_not_agreed_service(void);
extern MMI_BOOL mmi_imps_util_check_room_msg(U32 cont_srv_index);
extern S32 mmi_imps_get_country_code_str(CHAR *country_code);

#ifdef __MMI_IMPS_OTA__
extern void mmi_imps_handle_ota(U16 config_id, S32 hConfig);
extern void mmi_imps_ota_init(mmi_cca_app_configure_ind_struct *newConfigDoc);
#endif

extern U8 mmi_imps_hs_get_im_count(void);
extern void mmi_imps_notify_info_update(U16 type);
extern void mmi_imps_util_wps_terminate_ind(void);

/* click to call */
extern U32 mmi_imps_util_get_phnnum_url_count(CHAR *buff, U32 length);
extern void mmi_imps_util_get_phnnum_url_from_buff(CHAR *buff);
extern void mmi_imps_util_get_phnnum_url_from_newmsg(CHAR *buff_tail, CHAR *buff);
extern void mmi_imps_util_truncate_hilite_list(CHAR *cursor, CHAR *end);
extern void mmi_imps_hilite_str_callback(S32 idx);
extern void mmi_imps_hilite_str_click_callback(S32 idx);
extern MMI_BOOL mmi_imps_util_is_curr_hilite_str_visible(void);

#define CHAT_HISTORY
extern void mmi_imps_del_all_temp_conversation_file(void);
extern void mmi_imps_del_curr_chat_temp_conversation_file(mmi_imps_room_struct *room);
extern MMI_BOOL mmi_imps_write_conversation_to_temp_file(mmi_imps_room_struct *room, WCHAR *data);
extern void mmi_imps_save_disp_input_msg_to_tmp_file(void);
extern void mmi_imps_save_recv_msg_to_tmp_file(mmi_imps_room_struct *room, WCHAR *name, srv_imps_newmessage_ind_struct *ind);
extern void mmi_imps_save_send_failed_to_tmp_file(mmi_imps_room_struct *room, WCHAR *msg);
extern void mmi_imps_pre_entry_view_conversation(void);
extern void mmi_imps_select_cont_view_conversation(void);
extern void mmi_imps_pre_view_conversation_jump(void);
extern void mmi_imps_cont_view_conversation_next_page(void);
extern void mmi_imps_cont_view_conversation_pre_page(void);
extern void mmi_imps_pre_entry_del_conversation(void);
extern void mmi_imps_select_cont_del_conversation(void);

#define SCREEN_GROUP
extern MMI_ID mmi_imps_get_screen_group_id(void);
extern U8* mmi_imps_scrn_get_gui_buffer(MMI_ID scrn_id);  
extern MMI_BOOL mmi_imps_scrn_is_present(mmi_id scrn_id);
extern mmi_ret mmi_imps_scrn_close(mmi_id scrn_id);
extern mmi_ret mmi_imps_enter_main_group(MMI_ID parent_gid);
extern mmi_ret mmi_imps_re_enter_main_group(void);
extern mmi_ret mmi_imps_close_main_group(void);
extern mmi_ret mmi_imps_sg_insert_scrn(U16 scr_id, FuncPtr entry_func);
extern mmi_ret mmi_imps_screen_replace(U16 out_scrn_id, U16 in_scrn_id, FuncPtr in_src_func);
extern MMI_ID mmi_imps_enter_temp_screen_group(MMI_ID parent_id, mmi_proc_func proc, void *user_data);

extern void mmi_imps_entry_first_screen(void);

#ifndef __MMI_OP11_IMPS__
void mmi_imps_pre_entry_login(void);
#endif


MMI_BOOL mmi_imps_save_not_send_msg(mmi_imps_room_struct *room, MMI_BOOL first);
void mmi_imps_read_not_send_msg(mmi_imps_room_struct *room);

#if defined(__MMI_ICON_BAR_SUPPORT__) && defined(__MMI_OP11_IMPS__)
/* under construction !*/
/* under construction !*/
#endif  /*__MMI_ICON_BAR_SUPPORT__*/


#endif /* IMPS_APP_PROT_H */
