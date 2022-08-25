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
 *  DTVPlayerEnum.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files
*****************************************************************************/
#ifndef _MMI_DTV_PLAYER_ENUM_H_
#define _MMI_DTV_PLAYER_ENUM_H_

typedef enum
{
    MMI_DTV_KERNEL,
    MMI_DTV_PLAYER,
    MMI_DTV_RECORDER,

    MMI_DTV_MODULE_TOTAL_COUNT
}mmi_dtv_player_module_enum;


typedef enum
{
    DTV_KERNEL_CLOSED,      /* 0 */
    DTV_KERNEL_CLOSING,     /* 1 */
    DTV_KERNEL_SAVE_CONFIRM,/* 2 */
    DTV_KERNEL_SAVING,      /* 3 */
    DTV_KERNEL_DELETING,    /* 4 */
    DTV_KERNEL_SCANNING,    /* 5 */
    DTV_KERNEL_ESG_DOWNLOAD,/* 6 */
    DTV_KERNEL_OPENED,      /* 7 */
    DTV_KERNEL_INIT,        /* 8 */
    DTV_KERNEL_READY,       /* 9 */
    DTV_KERNEL_PROCESS,     /* 10 */
    DTV_KERNEL_SUB_UPDATING,/* 11 */
    DTV_KERNEL_NULL,        /* 12 */
    DTV_KERNEL_TOTAL_COUNT
}mmi_dtv_player_kernel_state_enum;

typedef enum
{
    DTV_PLAYER_STOPPED = 0,
    DTV_PLAYER_BT_CONNECT = 1,
    DTV_PLAYER_PLAY = 2,
    DTV_PLAYER_PAUSE = 3,
    DTV_PLAYER_NULL = 4,
    DTV_PLAYER_TOTAL_COUNT
}mmi_dtv_player_player_state_enum;

typedef enum
{
    DTV_RECORDER_STOPPED,       /* 0 */
    DTV_RECORDER_RECORD,        /* 1 */
    DTV_RECORDER_SAVE_CONFIRM,  /* 2 */
    DTV_RECORDER_SAVING,        /* 3 */
    DTV_RECORDER_DELETING,      /* 4 */
    DTV_RECORDER_NULL,          /* 5 */
    DTV_RECORDER_STATE_TOTAL_COUNT
}mmi_dtv_player_recorder_state_enum;

typedef enum
{
    DTV_APP_NORMAL = 0,

    DTV_APP_TOTAL_COUNT
}mmi_dtv_player_app_state_enum;

typedef enum
{
    MMI_DTV_CA_STATE_CMMB,
    MMI_DTV_CA_STATE_MBBMS,
    MMI_DTV_CA_STATE_MBBMS_INIT,
    MMI_DTV_CA_STATE_MBBMS_FAIL,
    MMI_DTV_CA_STATE_MBBMS_READY
} dtv_ca_state_enum;

typedef enum
{
	DTV_PLAYER_IS_NORMAL_INIT       = 0,
    DTV_PLAYER_BAD_RECEPTION        = 1,
    DTV_PLAYER_IS_STORAGE_CHECK     = (1<<1),
    DTV_PLAYER_IS_LIVE_SCANNING     = (1<<2),
    DTV_PLAYER_IS_SERVICE_ABORTED   = (1<<3),
    DTV_PLAYER_IS_SERVICE_REMOVED   = (1<<4),
    DTV_PLAYER_DELAY_DISPLAY_RECORD_ERROR = (1<<5),
    DTV_PLAYER_DELAY_UPDATE_EB_MSG = (1<<6),
    DTV_PLAYER_SERVICE_UNAVAILABLE = (1<<7),
    DTV_PLAYER_UNAVAILABLE_IN_CALL = (1<<8),
    DTV_PLAYER_ACCESS_DENIED = (1<<9),
    DTV_PLAYER_IS_SUBSCRIBE_CONFIRM_REJECTED = (1<<10),
    DTV_PLAYER_NEW_ESG_AVAILABLE = (1<<11),
    DTV_PLAYER_SG_RET_LOCATION_DETECT_FAIL = (1<<12),
    DTV_PLAYER_DISPLAY_CMMB_MODE_CONFIRM   = (1<<13),
    DTV_PLAYER_PLAYER_STARTED      = (1<<14),
    DTV_PLAYER_DISPLAY_EB_WARNING_STRING  = (1<<15),
    DTV_PLAYER_DISBLE_AUTO_PLAY  = (1<<16)
}dtv_player_bool_status_enum;



/* Service event */
typedef enum
{
    MDI_DTV_SERVICE_STARTED,            /* A service is started to connect */
    MDI_DTV_SERVICE_READY,              /* The service is connected successfully */
    MDI_DTV_SERVICE_STOPPED,            /* The service is stopped */
    MDI_DTV_SERVICE_ABORTED,            /* The service is aborted because some error occurs */
    MDI_DTV_SERVICE_ADDED,              /* A new service is available */
    MDI_DTV_SERVICE_REMOVED,            /* An existing service is removed */
    MDI_DTV_SERVICE_UPDATED,            /* The information of an existing service is updated */
    MDI_DTV_SERVICE_ACCESS_GRANTED,     /* The access permission of a service is granted */
    MDI_DTV_SERVICE_ACCESS_DENIED,      /* The access permission of a service is denied */
    MDI_DTV_SERVICE_BAD_RECEPTION,      /* The signal reception is bad */
    MDI_DTV_SERVICE_GOOD_RECEPTION,     /* The signal reception is good */
    MDI_DTV_SERVICE_FATAL_ERROR,        /* A severe problem happens  */
    MDI_DTV_SERVICE_DATE_TIME,          /* Current date and time is received */
    MDI_DTV_SERVICE_PROGRAM_INFO,       /* Current program info is received */
    MDI_DTV_SERVICE_EMERGENCY_MSG,      /* An emergency message is received */
    MDI_DTV_SERVICE_ESG_NEW_AVAILABLE,  /* A new ESG is available */
    MDI_DTV_SERVICE_ESG_DOWNLOADED,     /* A new ESG is downloaded, but is not ready for query */
    MDI_DTV_SERVICE_ESG_UPDATED,        /* ESG is updated */
    MDI_DTV_SERVICE_UPGRADE_RET,        /* Upgrade */
    MDI_DTV_SERVICE_AREA_RETRIEVE_RET,  /* Area retrieve  */
    MDI_DTV_SERVICE_INTERACTIVITY_RETRIEVE_RET,  /* Area retrieve  */
    MDI_DTV_SERVICE_SG_UPDATE_RET,    /* ESG fails to update */
    MDI_DTV_SERVICE_SUBSCRIPTION_RET,  /* Subscription table fails to update */
    MDI_DTV_SERVICE_ACCOUNT_INQUIRY_DONE, /* Account inquiry done */
    MDI_DTV_SERVICE_GBA_RET,           /* GBA process ret */
    MDI_DTV_SERVICE_SUBSCRIBE_DONE,     /* Subscribe done */
    MDI_DTV_SERVICE_UNSUBSCRIBE_DONE,   /* Unsubscribe done */
    MDI_DTV_SERVICE_MSK_RETRIEVE_DONE,    /* msk retrieve done */
    MDI_DTV_SERVICE_IMD_READY            /* IMD ready  */
} dtv_player_service_event_enum;

#ifdef __MBBMS_V30_OPERA__
typedef enum  
{
	OPERA_EVENT_NONE,
	OPERA_EVENT_STARTED,
	OPERA_EVENT_STOPPED,
	OPERA_EVENT_SCREEN_INVALID,
    OPERA_EVENT_LINK_CLICKED,
	OPERA_EVENT_IME_START,
	OPERA_EVENT_IME_END,
	OPERA_EVENT_PAGE_LOAD_START,
	OPERA_EVENT_PAGE_LOAD_PROGRESS,
	OPERA_EVENT_PAGE_LOAD_FINISHED,
	OPERA_EVENT_JSEX_CREATED,
	OPERA_EVENT_JSEX_SET_VALUE,
	OPERA_EVENT_JSEX_GET_VALUE,
	OPERA_EVENT_SCHEME_FOUND,
	OPERA_DIALOG_TYPE_CERT_CONFIRM,
	OPERA_USER_ACTIVE,
	OPERA_SET_RENDER_RECT_DONE
}dtv_player_opera_event_enum;
#endif /* __MBBMS_V30_OPERA__ */

#endif /* _MMI_DTV_PLAYER_ENUM_H_ */

