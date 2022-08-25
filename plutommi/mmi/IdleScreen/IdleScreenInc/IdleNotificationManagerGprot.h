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
 *  IdleNotificationManagerGprot.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file provides the exported interface for the applications that want to
 *  use the notification manager (NMBR) of the idle screen.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MMI_IDLE_NOTIFICATION_MANAGER_GPROT_H
#define _MMI_IDLE_NOTIFICATION_MANAGER_GPROT_H

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__

#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "kal_general_types.h"

#if 0
#ifdef __OP12__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

/**********************************************************************
 * Application ID registration (single): 
 **********************************************************************/

#define MMI_NMGR_APP_MISSED_CALL            0x00000001  /* Missed calls */
#define MMI_NMGR_APP_SMS                    0x00000002  /* SMS */
#define MMI_NMGR_APP_MMS                    0x00000004  /* MMS */
#define MMI_NMGR_APP_EMAIL                  0x00000008  /* Email */
#define MMI_NMGR_APP_WAP_PUSH               0x00000010  /* WAP push */
#define MMI_NMGR_APP_CELL_BROADCAST         0x00000020  /* Cell broadcast */
#define MMI_NMGR_APP_SIM_SMS                0x00000040  /* SIM SMS */
#define MMI_NMGR_APP_MESSAGE_WAITING        0x00000080  /* Message waiting */
#define MMI_NMGR_APP_PROVISIOING            0x00000100  /* Provisioning */
#define MMI_NMGR_APP_CCA                    0x00000200  /* CCA*/
#define MMI_NMGR_APP_VOBJ                   0x00000400  /* Vobject */
#define MMI_NMGR_APP_SMS_REPORT				0x00000800  /* SMS report*/
#define MMI_NMGR_APP_MMS_REPORT				0x00001000  /* MMS report*/
#define MMI_NMGR_APP_NULL                   0x00000000


/**********************************************************************
 * Application ID registration (integrated):
 **********************************************************************/

/* Integrated APP: unified message */
#ifdef __MMI_MMS_IN_UM__
#define _APP_MMS_IN_UM MMI_NMGR_APP_MMS
#else
#define _APP_MMS_IN_UM 0
#endif /* __MMI_MMS_IN_UM__ */

#ifdef __MMI_PUSH_IN_UM__
#define _APP_PUSH_IN_UM MMI_NMGR_APP_WAP_PUSH
#else
#define _APP_PUSH_IN_UM 0
#endif /* __MMI_PUSH_IN_UM__ */

#ifdef __MMI_PROV_IN_UM__
#define _APP_PROV_IN_UM MMI_NMGR_APP_PROVISIOING
#else
#define _APP_PROV_IN_UM 0
#endif /* __MMI_PROV_IN_UM__ */

#define MMI_NMGR_INTGR_APP_UM               (MMI_NMGR_APP_SMS | _APP_MMS_IN_UM | _APP_PUSH_IN_UM | _APP_PROV_IN_UM)

/* Intergrated APP: Vodafone toolbar */
#define MMI_NMGR_INTGR_APP_TOOLBAR          (MMI_NMGR_APP_MISSED_CALL | MMI_NMGR_INTGR_APP_UM | MMI_NMGR_APP_EMAIL | MMI_NMGR_APP_CELL_BROADCAST)

/* Integrated APP: Vodafone multi-event list */
#define MMI_NMGR_INTGR_APP_NORMAL_IDLE      (MMI_NMGR_APP_MISSED_CALL | MMI_NMGR_INTGR_APP_UM | MMI_NMGR_APP_MESSAGE_WAITING | MMI_NMGR_APP_EMAIL)

#if 0
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif
#endif

#define MMI_NMGR_INTGR_APP_MSG_REPORT       (MMI_NMGR_APP_SMS_REPORT | MMI_NMGR_APP_MMS_REPORT)

#if 0
#ifdef __OP01__
/* under construction !*/
#endif /* __OP01__ */
#endif

/**********************************************************************
 * Option flag for mmi_nmgr_notify:
 **********************************************************************/

/* NULL. The event will not be processed if the operator's notification rule 
   does not handle it. */
#define MMI_NMGR_OPTION_NULL                0x00000000

/* Use default behavior to notify the event even if the event is not processed
   by the operator's notification rule. */
#define MMI_NMGR_OPTION_USE_DEFAULT         0x00000001

/* On the idle notification screen, the LSK will be "Cancel". If the user
   selects LSK, the handset displays a confirm popup "Cancel?". The confirm
   popup has LSK as "Yes" and RSK as "No". "Yes" will close the notification
   screen; while "No" will go back to the notification screen.
   NOTE. This is only useable for the default idle notification. */
#define MMI_NMGR_OPTION_CONFIRM_CANCEL      0x00000002

/* This event is a lower priority event. Only need to insert it to the pending 
   event queue. */
#define MMI_NMGR_OPTION_LOWER_PRIORITY      0x00000004

/* APP will cancel the event by itself when it handles the event. */
#define MMI_NMGR_OPTION_SELF_CANCEL_ON_EXEC 0x00000008


/**********************************************************************
 * Default constants and values
 **********************************************************************/

/* Max. length of the string. */
#define MMI_NMGR_MAX_STR_LEN                31


/**********************************************************************
 * Type definitions
 **********************************************************************/

/* Function prototype for the query function to check whether new event is 
   present. */
typedef MMI_BOOL (*mmi_nmgr_query_new_event_func_t)(void);

/* Function prototype for the query function to get the information of the 
   events. */
typedef void (*mmi_nmgr_query_func_t)(void);

/* Function prototype for the cancel function to cancel the notification of 
   the new event. */
typedef void (*mmi_nmgr_cancel_func_t)(void);

/* Function prototype for the handler of the left softkey of the notification
   on the idle screen */
typedef void (*mmi_nmgr_hdlr_func_t)(void *user_data);


/**********************************************************************
 * Enum definitions
 **********************************************************************/

/* This enum defines the result of the query. */
typedef enum
{
    MMI_NMGR_RESULT_OK,         /* OK */
    MMI_NMGR_RESULT_NOT_READY,  /* APP is not ready and will update later */
    MMI_NMGR_RESULT_UPDATE      /* APP actively update its content */
} mmi_nmgr_result_enum;


/**********************************************************************
 * Structure definitions
 **********************************************************************/

/* This structure defines the information about a notification. */
typedef struct mmi_nmgr_info_struct_st
{
    /* Idle screen: */
    U16      image;         /* Image used in idle notification */
    U16      left_softkey;  /* Left softkey string ID */
    CHAR    *idle_text1;    /* Text (line 1) used in idle notification */
    CHAR    *idle_text2;    /* Text (line 2) used in idle notification */
    void    *user_data;     /* User data associated with this notificaiton */

    /* Misc. information about the event. */
    U16      icon;          /* Icon ID (only used in the multi-event list) */
    S32      total_num;     /* Total number of the unread messages or calls */
} mmi_nmgr_info_struct;


/* This structure defines the information about a notification. Note that this
   structure is for the integrated APP to return the answer. */
typedef struct mmi_nmgr_answer_struct_s
{
    CHAR                    idle_text1[(MMI_NMGR_MAX_STR_LEN + 1) * ENCODING_LENGTH];   /* Text (line 1) used in idle notification */
    CHAR                    idle_text2[(MMI_NMGR_MAX_STR_LEN + 1) * ENCODING_LENGTH];   /* Text (line 2) used in idle notification */
    U16                     image;                                                      /* Image used in idle notification */
    U16                     left_softkey;                                               /* Left softkey string ID */
    U16                     icon;                                                       /* Icon ID (only used in the multi-event list) */
    S32                     total_num;                                                  /* Total number of the unread messages or calls */
    void                   *user_data;                                                  /* User data associated with this notificaiton */
    mmi_nmgr_hdlr_func_t    hdlr;                                                       /* Handler for the left softkey on the idle screen */
} mmi_nmgr_answer_struct;


/* Notification manager control table entry (single): */
typedef struct
{
    /* The type of the APP */
    U32 type;

    /* Query function to check whether new event is present. */
    mmi_nmgr_query_new_event_func_t query_new_event;

    /* Query function to get the information of the events. */
    mmi_nmgr_query_func_t query_func;

    /* Cancel function to cancel the notification of the new event. */
    mmi_nmgr_cancel_func_t cancel_func;
} mmi_nmgr_ctrl_tbl_struct;


/* Notification manager control table entry (integrated): */
typedef struct
{
    /* The type of the APP (bit-wise OR of the APP ID) */
    U32 type;

    /* Query function to get the information of the events. */
    void (*query_func)(mmi_nmgr_answer_struct *answer);
} mmi_nmgr_intgr_ctrl_tbl_struct;


/**********************************************************************
 * Public APIs
 **********************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_answer
 * DESCRIPTION
 *  This function is called by APP to provide the notification information.
 * PARAMETERS
 *  type            [IN]            Application ID
 *  result          [IN]            Result of answer
 *  info            [IN]            Information about this notification
 *  hdlr            [IN]            Handler about this notification
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_nmgr_answer (
                U32 type,
                mmi_nmgr_result_enum result,
                mmi_nmgr_info_struct *info,
                mmi_nmgr_hdlr_func_t hdlr);


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_notify
 * DESCRIPTION
 *  This function is called by APP to notify the user.
 * PARAMETERS
 *  type            [IN]            Application ID
 *  flag            [IN]            Option flag
 * RETURNS
 *  If the notification is processed by the notification manager, return
 *  MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_nmgr_notify(U32 type, U32 flag);


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_refresh
 * DESCRIPTION
 *  This function refreshes the notification manager screen. This function only 
 *  refreshes the idle notification screen such that the unread message number
 *  can be updated. For non-idle notification screen, because it is only a 
 *  popup, not need to refresh it.
 * PARAMETERS
 *  type            [IN]            Application ID
 *  flag            [IN]            Option flag
 * RETURNS
 *  If the notification is processed by the notification manager, return
 *  MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_nmgr_refresh(U32 type, U32 flag);


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_is_active
 * DESCRIPTION
 *  This function checks whether the active screen is the notification screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_nmgr_is_active(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_is_active_on_idle
 * DESCRIPTION
 *  This function checks whether the active screen is the notification screen on
 *  the idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_nmgr_is_active_on_idle(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_get_app_info
 * DESCRIPTION
 *  This function gets the APP information.
 * PARAMETERS
 *  type            [IN]            Application ID
 *  info            [OUT]           Application information
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_nmgr_get_app_info(U32 type, mmi_nmgr_info_struct *info);


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_initialize
 * DESCRIPTION
 *  This function initializes the context of the NMGR.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_nmgr_initialize(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_get_current_process_event
 * DESCRIPTION
 *  This function get the current processed notification event id.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return event id.
 *****************************************************************************/
extern U32 mmi_nmgr_get_current_process_event(void);

#endif /* __MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

#endif /* _MMI_IDLE_NOTIFICATION_MANAGER_GPROT_H */

