/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  IdleNotificationManagerConfig.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used by other applications to register their callbacks for the
 *  idle screen notification manager (NMGR).
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef IDLE_NOTIFICATION_MANAGER_CONFIG_H
#define IDLE_NOTIFICATION_MANAGER_CONFIG_H

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
#include "MMI_features.h"
#include "Messagesmiscell.h"
#include "CbsAppGProt.h"
#include "Voicemail.h"
#include "UMGProt.h"
#include "CallLogGprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "IdleNotificationManagerGprot.h"

#if defined(__WAP_PUSH_SUPPORT__) && !defined(__WAP_PUSH_SERVICE_ONLY_SUPPORT__)
#include "WAPPushGprots.h"
#endif

#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
#include "ProvBoxAPPGProt.h"
#elif defined(__MMI_CCA_SUPPORT__)
#include "CentralConfigAgentGProt.h"
#endif

#ifdef __MMI_MMS_2__
#include "MMSSrvGprot.h"
#endif

#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
#include "vObjects.h"
#endif

#ifdef OBIGO_Q03C_MMS_V01
extern void mmi_nmgr_widget_mms_query(void);
extern void mmi_nmgr_widget_mms_cancel(void);
extern MMI_BOOL mmi_widget_mms_new_event_query(void);
#endif

#ifdef __MMI_MMS_2__
extern void srv_mms_nmgr_get_unread_msg_callback(void);
extern void srv_mms_nmgr_cancel_unread_msg(void);
#endif

#ifdef __MMI_UM_REPORT_BOX__
extern void mmi_sms_nmgr_query_report_notify(void);
extern void mmi_sms_nmgr_cancel_report_notify(void);
#endif /* __MMI_UM_REPORT_BOX__ */


/**********************************************************************
 * APP query and cancel functions registration:
 *
 * PS. the order can be different to the order of APP ID registration.
 **********************************************************************/

/*
 * Macro Definition
 */
#undef MMI_NMGR_INTGR_CTRL_TABLE
#undef MMI_NMGR_INTGR_ADD_ENTRY
#undef MMI_NMGR_INTGR_LAST_ENTRY
#undef MMI_NMGR_INTGR_APP_NUM

#if defined(MMI_NMGR_CONFIG_INTERNAL_USE)

#define MMI_NMGR_INTGR_CTRL_TABLE                                       \
    const mmi_nmgr_intgr_ctrl_tbl_struct mmi_nmgr_intgr_ctrl_tbl[] =

#define MMI_NMGR_INTGR_ADD_ENTRY(_intgr_app, _query_func)               \
    {                                                                   \
        _intgr_app,                                                     \
        _query_func                                                     \
    }

#define MMI_NMGR_INTGR_LAST_ENTRY

#define MMI_NMGR_INTGR_APP_NUM                                          \
    (sizeof(mmi_nmgr_intgr_ctrl_tbl) / sizeof(mmi_nmgr_intgr_ctrl_tbl_struct))

#else /* defined(MMI_NMGR_CONFIG_INTERNAL_USE) */

#define MMI_NMGR_INTGR_CTRL_TABLE enum

#define MMI_NMGR_INTGR_ADD_ENTRY(_intgr_app, _query_func)               \
    MMI_NMGR_INTGR_TBL_ENTRY_##_intgr_app

#define MMI_NMGR_INTGR_LAST_ENTRY MMI_NMGR_INTGR_APP_NUM

#endif /* defined(MMI_NMGR_CONFIG_INTERNAL_USE) */


/*
 * Registration
 */
MMI_NMGR_INTGR_CTRL_TABLE
{
    MMI_NMGR_INTGR_ADD_ENTRY(
        MMI_NMGR_INTGR_APP_UM,
        mmi_um_nmgr_query_data)

#ifdef __MMI_UM_REPORT_BOX__
    ,
    MMI_NMGR_INTGR_ADD_ENTRY(
        MMI_NMGR_INTGR_APP_MSG_REPORT,
        mmi_um_nmgr_query_report_message)
#endif /* __MMI_UM_REPORT_BOX__ */

    ,
    MMI_NMGR_INTGR_LAST_ENTRY
};


/**********************************************************************
 * APP query and cancel functions registration:
 *
 * PS. the order can be different to the order of APP ID registration.
 **********************************************************************/

/*
 * Macro definition
 */
#undef MMI_NMGR_CTRL_TABLE
#undef MMI_NMGR_ADD_ENTRY
#undef MMI_NMGR_LAST_ENTRY
#undef MMI_NMGR_APP_NUM
#undef ADAPTOR_QUERY_NEW_EVENT
#undef INSTANTIATE_ADAPTOR_QUERY_NEW_EVENT

#if defined(MMI_NMGR_CONFIG_INTERNAL_USE)

#define MMI_NMGR_CTRL_TABLE                                                 \
    const mmi_nmgr_ctrl_tbl_struct mmi_nmgr_ctrl_tbl[] =

#define MMI_NMGR_ADD_ENTRY(_type, _check_func, _query_func, _cancel_func)   \
    {                                                                       \
        _type,                                                              \
        _check_func,                                                        \
        _query_func,                                                        \
        _cancel_func                                                        \
    }

#define MMI_NMGR_LAST_ENTRY

#define MMI_NMGR_APP_NUM                                                    \
    (sizeof(mmi_nmgr_ctrl_tbl) / sizeof(mmi_nmgr_ctrl_tbl_struct))

/*
 * Some old API returns U8, rather than MMI_BOOL when we ask if there is new
 * event. Use this adaptor to convert them conveniently.
 */
#define ADAPTOR_QUERY_NEW_EVENT(idle_callback) mmi_nmgr_adp_##idle_callback

#define INSTANTIATE_ADAPTOR_QUERY_NEW_EVENT(idle_callback)          \
    static MMI_BOOL ADAPTOR_QUERY_NEW_EVENT(idle_callback)(void)    \
    {                                                               \
        return idle_callback() != 0 ? MMI_TRUE : MMI_FALSE;         \
    }

#else /* defined(MMI_NMGR_CONFIG_INTERNAL_USE) */

#define MMI_NMGR_CTRL_TABLE enum

#define MMI_NMGR_ADD_ENTRY(_type, _check_func, _query_func, _cancel_func)   \
    MMI_NMGR_TBL_ENTRY_##_type

#define MMI_NMGR_LAST_ENTRY MMI_NMGR_APP_NUM

/*
 * Some old API returns U8, rather than MMI_BOOL when we ask if there is new
 * event. Use this adaptor to convert them conveniently.
 */
#define ADAPTOR_QUERY_NEW_EVENT(idle_callback) mmi_nmgr_adp_##idle_callback

#define INSTANTIATE_ADAPTOR_QUERY_NEW_EVENT(idle_callback)

#endif /* defined(MMI_NMGR_CONFIG_INTERNAL_USE) */


/*
 * Instantiation
 */
extern U8 mmi_msg_need_new_msg_ind(void);
INSTANTIATE_ADAPTOR_QUERY_NEW_EVENT(mmi_msg_need_new_msg_ind)

#ifdef __MMI_EMAIL__
extern U8 mmi_email_check_vf_list(void);
INSTANTIATE_ADAPTOR_QUERY_NEW_EVENT(mmi_email_check_vf_list)
#endif

#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
extern U8 mmi_cbs_nmgr_need_ind(void);
INSTANTIATE_ADAPTOR_QUERY_NEW_EVENT(mmi_cbs_nmgr_need_ind)
#endif

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
extern U8 mmi_msg_need_new_sim_msg_ind(void);
INSTANTIATE_ADAPTOR_QUERY_NEW_EVENT(mmi_msg_need_new_sim_msg_ind)
#endif

extern U8 mmi_msg_need_waiting_ind(void);
INSTANTIATE_ADAPTOR_QUERY_NEW_EVENT(mmi_msg_need_waiting_ind)

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
INSTANTIATE_ADAPTOR_QUERY_NEW_EVENT(mmi_provbox_idle_new_msg_check)
#endif

#ifdef __MMI_UM_REPORT_BOX__
INSTANTIATE_ADAPTOR_QUERY_NEW_EVENT(mmi_sms_nmgr_need_report_ind)
#endif

#undef INSTANTIATE_ADAPTOR_QUERY_NEW_EVENT


/*
 * Registration
 */
MMI_NMGR_CTRL_TABLE
{
#if defined(__MMI_TELEPHONY_SUPPORT__) || defined(__MMI_BT_PBAP_CLIENT__)
    MMI_NMGR_ADD_ENTRY(
        MMI_NMGR_APP_MISSED_CALL,
        mmi_clog_nmgr_check,
        mmi_clog_nmgr_query,
        mmi_clog_clear_all_new_events)
    ,
#endif /* __MMI_TELEPHONY_SUPPORT__ || __MMI_BT_PBAP_CLIENT__ */

    MMI_NMGR_ADD_ENTRY(
        MMI_NMGR_APP_SMS,
        ADAPTOR_QUERY_NEW_EVENT(mmi_msg_need_new_msg_ind),
        mmi_msg_nmgr_query_sms_notify,
        mmi_msg_nmgr_cancel_sms_notify)

#ifdef __MMI_UM_REPORT_BOX__
    ,
    MMI_NMGR_ADD_ENTRY(
        MMI_NMGR_APP_SMS_REPORT,
        ADAPTOR_QUERY_NEW_EVENT(mmi_sms_nmgr_need_report_ind),
        mmi_sms_nmgr_query_report_notify,
        mmi_sms_nmgr_cancel_report_notify)
#endif /* __MMI_UM_REPORT_BOX__ */

#ifdef __MMI_MMS_2__
    ,
    MMI_NMGR_ADD_ENTRY(
        MMI_NMGR_APP_MMS,
        srv_mms_nmgr_if_new_msg_event,
        srv_mms_nmgr_get_unread_msg_callback,
        srv_mms_nmgr_cancel_unread_msg)
#ifdef  __MMI_MMS_REPORT_BOX_SUPPORT__
    ,
    MMI_NMGR_ADD_ENTRY(
        MMI_NMGR_APP_MMS_REPORT,
        srv_mms_nmgr_if_new_report_event,
        srv_mms_query_unread_report_data,
        srv_mms_nmgr_cancel_unread_report)
#endif
#elif defined(OBIGO_Q03C_MMS_V01)
    ,
    MMI_NMGR_ADD_ENTRY(
        MMI_NMGR_APP_MMS,
        mmi_widget_mms_new_event_query,
        mmi_nmgr_widget_mms_query,
        mmi_nmgr_widget_mms_cancel)
#endif /* __MMI_MMS_2__ */

#ifdef __MMI_EMAIL__
    ,
    MMI_NMGR_ADD_ENTRY(
        MMI_NMGR_APP_EMAIL,
        ADAPTOR_QUERY_NEW_EVENT(mmi_email_check_vf_list),
        mmi_email_nmgr_query,
        mmi_email_nmgr_cancel)
#endif /* __MMI_EMAIL__ */

#if defined(__WAP_PUSH_SUPPORT__) && !defined(__WAP_PUSH_SERVICE_ONLY_SUPPORT__)
    ,
    MMI_NMGR_ADD_ENTRY(
        MMI_NMGR_APP_WAP_PUSH,
        srv_push_nmgr_if_new_msg_event,
        mmi_wap_push_nmgr_get_unread_msg,
        mmi_wap_push_nmgr_cancel_unread_msg)
#endif /* WAP_SUPPORT */

#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
    ,
    MMI_NMGR_ADD_ENTRY(
        MMI_NMGR_APP_CELL_BROADCAST,
        ADAPTOR_QUERY_NEW_EVENT(mmi_cbs_nmgr_need_ind),
        mmi_cbs_nmgr_query_ind_notify,
        mmi_cbs_nmgr_cancel_ind_notify)
#endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    ,
    MMI_NMGR_ADD_ENTRY(
        MMI_NMGR_APP_SIM_SMS,
        ADAPTOR_QUERY_NEW_EVENT(mmi_msg_need_new_sim_msg_ind),
        mmi_msg_nmgr_query_sim_sms_notify,
        mmi_msg_nmgr_cancel_sim_sms_notify)
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

    ,
    MMI_NMGR_ADD_ENTRY(
        MMI_NMGR_APP_MESSAGE_WAITING,
        ADAPTOR_QUERY_NEW_EVENT(mmi_msg_need_waiting_ind),
        mmi_sms_vm_nmgr_query_message_waiting,
        mmi_sms_vm_nmgr_cancel_message_waiting)

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    ,
    MMI_NMGR_ADD_ENTRY(
        MMI_NMGR_APP_PROVISIOING,
        ADAPTOR_QUERY_NEW_EVENT(mmi_provbox_idle_new_msg_check),
        mmi_provbox_nmgr_query,
        mmi_provbox_nmgr_cancel)
#elif defined(__MMI_CCA_SUPPORT__)
    ,
    MMI_NMGR_ADD_ENTRY(
        MMI_NMGR_APP_CCA,
        mmi_cca_nmgr_check,
        mmi_cca_nmgr_query,
        mmi_cca_nmgr_cancel)
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */

#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
    ,
    MMI_NMGR_ADD_ENTRY(
        MMI_NMGR_APP_VOBJ,
        mmi_vobj_is_pending_object,
        mmi_vobj_nmgr_query_pending_notify,
        mmi_vobj_nmgr_cancel)
#endif /* defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__) */

    ,
    MMI_NMGR_LAST_ENTRY
};


/*****************************************************************************
 * External Interface
 *****************************************************************************/

extern const mmi_nmgr_intgr_ctrl_tbl_struct *mmi_nmgr_get_intgr_ctrl_tbl(void);

extern const mmi_nmgr_ctrl_tbl_struct *mmi_nmgr_get_ctrl_tbl(void);

#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

#endif /* IDLE_NOTIFICATION_MANAGER_CONFIG_H */

