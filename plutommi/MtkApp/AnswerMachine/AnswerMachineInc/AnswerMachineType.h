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
 * AnswerMachineType.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for auto answer machine.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_AUTOAM_TTPE_H
#define MMI_AUTOAM_TTPE_H

#include "MMI_features.h"

#ifdef __MMI_AUTO_ANSWER_MACHINE__
#include "FileMgrSrvGProt.h"
#include "GlobalConstants.h"
#include "MMIDataType.h"
#include "fs_type.h"
#include "custom_mmi_default_value.h"
#if defined (__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
#include "NetsetAppGprot.h"
#endif
/***************************************************************************** 
 * Define 
 *****************************************************************************/
/* string length */
#define MMI_AUTOAM_CALL_NUMBER_LEN          65  /* 42 */
#define MMI_AUTOAM_CALL_NAME_LEN            61
#define MMI_AUTOAM_REMOTE_PASSWD_LEN        4
#define MMI_AUTOAM_SHOW_DURATION_LEN        20
#define MMI_AUTOAM_MAX_FILE_NAME_LEN        80
#define MMI_AUTOAM_MAX_DISPLAY_FILE_NAME_LEN  MAX_SUBMENU_CHARACTERS
#define MMI_AUTOAM_MAX_SIM_NAME_LEN  MAX_SUBMENU_CHARACTERS



#define MMI_AUTOAM_MAX_PATH_LEN             50  /* The path is fixed. i.e "c:\answer machine\message" */
#define MMI_AUTOAM_MAX_FULL_NAME_LEN        (MMI_AUTOAM_MAX_PATH_LEN+ SRV_FMGR_PATH_MAX_LEN) + 1       /* (MAX_FM_PATH_LEN+MAX_FM_FILE_NAME_LEN) */
/* path define */
#define MMI_AUTOAM_DEFAULT_FOLDER_ANSWER_MACHINE        L"Answer machine\\"
#define MMI_AUTOAM_DEFAULT_FOLDER_GREETING              L"Greeting\\"
#define MMI_AUTOAM_DEFAULT_FOLDER_MESSAGE               L"Message\\"
#define MMI_AUTOAM_SYSTEM_FOLDER                        L"Z:\\@AutoAM\\"
#define MMI_AUTOAM_DEFAULT_RECORD_LIST_NAME             L"AnswerMachineList.txt"

/* others */
#define MMI_AUTOAM_MAX_REOCRD_NUM           100
#define MMI_AUTOAM_DEFAULT_REMOTE_HOTKEY    '#'

/* Audio resource */
#define MMI_AUTOAM_AUD_GREETING_DEFAULT(x)      ((x)+1)
#define MMI_AUTOAM_AUD_HINT_TIME_1MIN(x)        ((x)+2)
#define MMI_AUTOAM_AUD_HINT_TIME_3MIN(x)        ((x)+3)
#define MMI_AUTOAM_AUD_HINT_TIME_5MIN(x)        ((x)+4)
#define MMI_AUTOAM_AUD_HINT_TIME_30SCD(x)       ((x)+5)
#define MMI_AUTOAM_AUD_TIMEOUT(x)               ((x)+6)
#define MMI_AUTOAM_AUD_DISCFULL(x)              ((x)+7)
#define MMI_AUTOAM_AUD_GOODBYE(x)               ((x)+8)
#define MMI_AUTOAM_AUD_LOGIN_GREETING(x)        ((x)+9)
#define MMI_AUTOAM_AUD_LOGIN_PASSWD_ERROR(x)    ((x)+10)
#define MMI_AUTOAM_AUD_REMOTE_GREETING(x)       ((x)+11)
#define MMI_AUTOAM_AUD_REMOTE_NO_NEW(x)         ((x)+12)
#define MMI_AUTOAM_AUD_REMOTE_PLAY_UNREAD(x)    ((x)+13)
#define MMI_AUTOAM_AUD_REMOTE_REPLAY_UNREAD(x)  ((x)+14)
#define MMI_AUTOAM_AUD_REMOTE_REPLAY_ONE(x)     ((x)+15)
#define MMI_AUTOAM_AUD_REMOTE_REPLAY_ALL(x)     ((x)+16)
#define MMI_AUTOAM_AUD_REMOTE_PLAY_END(x)       ((x)+17)
/* flag define */
#define MMI_AUTOAM_MSG_READ_FLAG        0x01
#define MMI_AUTOAM_MSG_PROTECT_FLAG     0x02
#define MMI_AUTOAM_MSG_VALID_FLAG      0x04
#define MMI_AUTOAM_FILE_END_TAG         '#'
/* define file structure */
#define MMI_AUTOAM_FILE_HEADER_LEN          MMI_AUTOAM_MAX_REOCRD_NUM + 1       /* end tag 0xEE */
#define MMI_AUTOAM_FILE_FLAG_OFFSET         0                                /* 0 */  
#define MMI_AUTOAM_FILE_SIM_OFFSET          MMI_AUTOAM_FILE_FLAG_OFFSET  + 1 /* 1 */
#define MMI_AUTOAM_FILE_DRIVE_OFFSET        MMI_AUTOAM_FILE_SIM_OFFSET  + 1  /* 2 */  
#define MMI_AUTOAM_FILE_NAME_OFFSET         MMI_AUTOAM_FILE_DRIVE_OFFSET + 1 /* 3 */   
#define MMI_AUTOAM_FILE_DURATION_OFFSET     MMI_AUTOAM_FILE_NAME_OFFSET  + (MMI_AUTOAM_MAX_DISPLAY_FILE_NAME_LEN * ENCODING_LENGTH)        /* 85 */
#define MMI_AUTOAM_FILE_DATE_OFFSET         MMI_AUTOAM_FILE_DURATION_OFFSET + 2 /* 86 */
#define MMI_AUTOAM_FILE_CALLER_NAME_OFFSET  MMI_AUTOAM_FILE_DATE_OFFSET + 12    /* 99 */
#define MMI_AUTOAM_FILE_NUMBER_OFFSET       MMI_AUTOAM_FILE_CALLER_NAME_OFFSET + (MMI_AUTOAM_MAX_DISPLAY_FILE_NAME_LEN * ENCODING_LENGTH)  /* 181 */
#if !defined (__MMI_DYNAMIC_SIM_DYNAMIC_UI__)

#define MMI_AUTOAM_FILE_END_TAG_OFFSET      MMI_AUTOAM_FILE_NUMBER_OFFSET + MMI_AUTOAM_CALL_NUMBER_LEN  /* 246 */
#define MMI_AUTOAM_FILE_ONE_MSG_LEN         247

#else

#define MMI_AUTOAM_FILE_SIM_NAME_OFFSET    MMI_AUTOAM_FILE_NUMBER_OFFSET + MMI_AUTOAM_CALL_NUMBER_LEN  /* 246 */
#define MMI_AUTOAM_FILE_END_TAG_OFFSET     MMI_AUTOAM_FILE_SIM_NAME_OFFSET + (MMI_NETSET_SIM_NAME_MAX_LEN * ENCODING_LENGTH) /* 268 */
#define MMI_AUTOAM_FILE_ONE_MSG_LEN        269

#endif


/* Define detail screen string size */


#if defined (__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
#define MMI_AUTOAM_DETAIL_STR_SIZE  ((512*4 + MMI_AUTOAM_REMOTE_PASSWD_LEN + MMI_AUTOAM_CALL_NAME_LEN + MMI_AUTOAM_MAX_SIM_NAME_LEN + MMI_NETSET_SIM_NAME_MAX_LEN + 40)*2)
#else
#define MMI_AUTOAM_DETAIL_STR_SIZE  ((512*4 + MMI_AUTOAM_REMOTE_PASSWD_LEN + MMI_AUTOAM_CALL_NAME_LEN + MMI_AUTOAM_MAX_SIM_NAME_LEN+ 40)*2)
#endif


#define MMI_AUTOAM_SINGLE_STR_LEN   512

 /***************************************************************************** 
 * enum
 *****************************************************************************/
typedef enum
{
    MMI_AUTOAM_STATE_IDLE,              /* ---0 */
    MMI_AUTOAM_STATE_GREETING,
    MMI_AUTOAM_STATE_HINT_TIME,
    MMI_AUTOAM_STATE_RECORD,
    MMI_AUTOAM_STATE_RECORD_TIMEOUT,
    MMI_AUTOAM_STATE_RECORD_DISCFULL,   /* ---5 */
    MMI_AUTOAM_STATE_GOODBYE,
    MMI_AUTOAM_STATE_RECORD_QUIT,
    MMI_AUTOAM_STATE_REMOTE_STOP,       /* UCM notify the call is end */
    MMI_AUTOAM_STATE_STOP_BY_ANSWER,    /* user select answer */

    MMI_AUTOAM_STATE_LOGIN_GREETING,    /* 10 */
    MMI_AUTOAM_STATE_LOGIN_DETECT_BEGIN,
    MMI_AUTOAM_STATE_LOGIN_PASSWD_RECV,
    MMI_AUTOAM_STATE_LOGIN_PASSWD_CHECK,
    MMI_AUTOAM_STATE_LOGIN_PASSWD_ERROR,

    MMI_AUTOAM_STATE_REMOTE_GREETING,       /* 15 */
    MMI_AUTOAM_STATE_REMOTE_ENTRY,
    MMI_AUTOAM_STATE_REMOTE_NO_NEW,
    MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_UNREAD,
    MMI_AUTOAM_STATE_REMOTE_PRE_REPLAY_UNREAD,
    MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_ALL,   /* 20 */
    MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_ONE,
    MMI_AUTOAM_STATE_REMOTE_PLAY_UNREAD,
    MMI_AUTOAM_STATE_REMOTE_PLAY_ALL,
    MMI_AUTOAM_STATE_REMOTE_PLAY_ONE,
    MMI_AUTOAM_STATE_REMOTE_PLAY_END,       /* 25 */

    MMI_AUTOAM_NO_OF_STATE
} mmi_autoam_state_enum;

typedef enum
{
    MMI_AUTOAM_OFF,
    MMI_AUTOAM_ON,
    MMI_AUTOAM_NO_OF_SWITCH
} mmi_autoam_switch_enum;

typedef enum
{
    MMI_AUTOAM_PICKUP_THREE_SEC,
    MMI_AUTOAM_PICKUP_FIVE_SEC,
    MMI_AUTOAM_PICKUP_TEN_SEC,
    MMI_AUTOAM_PICKUP_THIRTY_SEC,
    /* MMI_AUTOAM_PICKUP_ONE_MINUTE, */
    MMI_AUTOAM_NO_OF_PICKUP
} mmi_autoam_pickup_enum;

typedef enum
{
    MMI_AUTOAM_DURATION_THIRTY_SEC,
    MMI_AUTOAM_DURATION_ONE_MINUTE,
    MMI_AUTOAM_DURATION_THREE_MINUTE,
    MMI_AUTOAM_DURATION_FIVE_MINUTE,
    MMI_AUTOAM_DURATION_UNLIMIT,
    MMI_AUTOAM_NO_OF_DURATION
} mmi_autoam_duration_enum;

typedef enum
{
    MMI_AUTOAM_SETTING_STATE_CAP,
    MMI_AUTOAM_SETTING_STATE,
#if defined(__MMI_FMGR_APP_STORAGE__)
    MMI_AUTOAM_SETTING_STORAGE_CAP,
    MMI_AUTOAM_SETTING_STORAGE,
#endif /* defined(__MMI_FMGR_APP_STORAGE__) */ 
    MMI_AUTOAM_SETTING_PICKUP_TIME_CAP,
    MMI_AUTOAM_SETTING_PICKUP_TIME,
    MMI_AUTOAM_SETTING_DURATION_CAP,
    MMI_AUTOAM_SETTING_DURATION,
    MMI_AUTOAM_SETTING_GREETING_CAP,
    MMI_AUTOAM_SETTING_GREETING,
    MMI_AUTOAM_SETTING_REMOTE_ACCESS,
    MMI_AUTOAM_NO_OF_SETTING
} mmi_autoam_setting_enum;

typedef enum
{
    MMI_AUTOAM_REMOTE_SETTING_STATE_CAP,
    MMI_AUTOAM_REMOTE_SETTING_STATE,
    MMI_AUTOAM_REMOTE_SETTING_KEY_CAP,
    MMI_AUTOAM_REMOTE_SETTING_KEY,
    MMI_AUTOAM_REMOTE_SETTING_PASSWORD_CAP,
    MMI_AUTOAM_REMOTE_SETTING_PASSWORD,
    MMI_AUTOAM_NO_OF_REMOTE_SETTING
} mmi_autoam_remote_setting_enum;

typedef enum
{
    MMI_AUTOAM_GREETING_DEFAULT,
    MMI_AUTOAM_GREETING_NORMAL,
    MMI_AUTOAM_GREETING_SHORT,

    MMI_AUTOAM_GREETING_TOTAL
} mmi_autoam_greeting_enum;

#ifdef __MMI_FTE_SUPPORT__
typedef enum
{
    MMI_AUTOAM_ICON_CALL,
    MMI_AUTOAM_ICON_PHB,
    MMI_AUTOAM_ICON_DEL,

    MMI_AUTOAM_ICON_TOTAL
} mmi_autoam_icon_bar_enum;
#endif /* __MMI_FTE_SUPPORT__ */ 

/***************************************************************************** 
 * structure 
 *****************************************************************************/
typedef struct
{
    U8 turn_on;         /* auto answer machine enable or disable, disable default. */
    U8 remote_allow;    /* allow remote access, disable default. */
    U8 drv_letter;      /* leaving message default storage. */
    U8 rec_storage;     /* greeting file browse storage */
    /* U8 message_drv;     //message file browse storage */
    U8 greeting_default;
    U8 hot_key;
    U8 pickup;
    U8 pwlength;
    U8 password[MMI_AUTOAM_REMOTE_PASSWD_LEN];
    U16 duration;
    U16 greeting_filename[MMI_AUTOAM_MAX_FULL_NAME_LEN];
} mmi_autoam_setting_struct;

typedef struct
{
    /* for remote access */
    U8 repeat_count;
    U8 passwd_count;
    U8 remote_key;
    U8 passwd_buf[MMI_AUTOAM_REMOTE_PASSWD_LEN + 1];    /* the last byte is '#' */
    /* for remote play message */
    U8 reset_flag;
    U8 total_play_num;
    U8 curr_play_num;
    U8 curr_play_index;
    U8 message_num_unread;
    /* for all */
    U8 state;
    U8 volume;
    U8 message_num_all;
    U8 isMute;
    U16 name[MMI_AUTOAM_CALL_NAME_LEN];
    U16 number[MMI_AUTOAM_CALL_NUMBER_LEN];
    FS_HANDLE fd;
    S32 lan_index;
    MYTIME begin_time;
} mmi_autoam_speech_struct;

typedef struct
{
    U8 flag;                                /* No.1 */
    U8 sim_no;                              /* No.2 */
    U8 drv_letter;                          /* No.3 */
    U8 number[MMI_AUTOAM_CALL_NUMBER_LEN];  /* No.4 */
    U8 date[12];                            /* No.5 --year+mon+day+hour+min */
    U16 rec_len;                            /* No.6 */
    U16 filename[MMI_AUTOAM_MAX_DISPLAY_FILE_NAME_LEN];        /* No.7 */
    U16 callername[MMI_AUTOAM_MAX_DISPLAY_FILE_NAME_LEN];      /* No.8 */
    #if defined (__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    WCHAR sim_name[MMI_NETSET_SIM_NAME_MAX_LEN + 1]; /* No.9 */ // Operator Name
    #endif
} mmi_autoam_message_struct;

#endif /* __MMI_AUTO_ANSWER_MACHINE__ */ 

#endif /* MMI_AUTOAM_TTPE_H */ 

