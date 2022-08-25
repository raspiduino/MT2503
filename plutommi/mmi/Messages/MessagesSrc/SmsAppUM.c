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
 *  SmsAppMainUI.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Application main UI screen and menu, 
 *  inlcude the SMS folder List, Editor, Viewer and their options
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
 *****************************************************************************/

#include "MMI_features.h"

/**************************************************************
 * Header Files Include
 **************************************************************/
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "GlobalConstants.h"
#include "GlobalResDef.h"
#include "app_datetime.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "kal_public_api.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "customer_email_num.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "SmsSrvGprot.h"
#include "UmSrvDefs.h"
#include "UmSrvStruct.h"
#include "UMDefs.h"
#ifdef __UM_SUPPORT__
#include "mmi_rp_app_unifiedmessage_def.h"
#endif
#include "mmi_rp_app_sms_def.h"
#include "MMI_trc_Int.h"

#include "SmsAppGprot.h"
#include "SmsAppType.h"
#include "SmsAppProt.h"
#include "SmsAppUtil.h"
#include "SmsAppMsg.h"
#include "SmsCuiGprot.h"
#include "SmsPsHandler.h"
#include "UMGProt.h"
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
#include "UcResDef.h"
#include "UcAppGprot.h"
#include "UcCuiGprot.h"
#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */ 
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif /* __USB_IN_NORMAL_MODE__ */
#include "SimCtrlSrvGprot.h"


/**************************************************************
* MARCO
**************************************************************/

/**************************************************************
* Structure Declaration
**************************************************************/

/**************************************************************
 * Global Variables Declaration
 **************************************************************/


/**************************************************************
 * Global Function Declaration
 **************************************************************/


/**************************************************************
 * Static Variables Defination
 **************************************************************/


/**************************************************************
 * Static Function Declaration
 **************************************************************/
#ifdef __MMI_FTE_SUPPORT__
#ifndef __MMI_UNIFIED_COMPOSER__
static void mmi_sms_um_activate_reply_read_callback(mmi_sms_result_enum result, void *data);
#endif
#endif
#ifdef __MMI_ICON_BAR_SUPPORT__
#ifndef __MMI_UNIFIED_COMPOSER__
static void mmi_sms_um_activate_forward_read_callback(mmi_sms_result_enum result, void *data);
static void mmi_sms_um_activate_edit_read_callback(mmi_sms_result_enum result, void *data);
#endif /*__MMI_UNIFIED_COMPOSER__ */
static void mmi_sms_um_activate_send_read_callback(mmi_sms_result_enum result, void *data);
static void mmi_sms_um_activate_resend_read_callback(mmi_sms_result_enum result, void *data);
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
static void mmi_sms_um_activate_copy_callback(mmi_sms_result_enum result, void *data);
static void mmi_sms_um_activate_move_callback(mmi_sms_result_enum result, void *data);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
static void mmi_sms_um_activate_delete_callback(mmi_sms_result_enum result, void *data);
static void mmi_sms_um_activate_delete_confirm(void);
#endif /* __MMI_ICON_BAR_SUPPORT__ */



#ifndef __MMI_TELEPHONY_SUPPORT__
U16 srv_sms_get_msg_list_index(srv_sms_box_enum* msg_box_type, U16 msg_id)
{
    *msg_box_type = SRV_SMS_BOX_NONE;
    return SRV_SMS_INVALID_LIST_INDEX;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_entry_msg
 * DESCRIPTION
 *  entry sms msg
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 
#ifdef __UM_SUPPORT__
MMI_ID mmi_sms_um_entry_msg(mmi_um_entry_msg_struct *entry_msg_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cur_gid = GRP_ID_INVALID;
    srv_sms_box_enum msg_box_type = SRV_SMS_BOX_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    srv_sms_get_msg_list_index(&msg_box_type, entry_msg_param->msg_id);
    #endif
    #ifdef __MMI_SMS_SLIM__
    if (msg_box_type != SRV_SMS_BOX_NONE)
    #else
    if (msg_box_type != SRV_SMS_BOX_UNSENT)
    #endif
    {
        U16 key_code = entry_msg_param->key_code;

        if ((key_code == MMI_UM_UI_ENTRY_INTUITIVE_CMD)
            || (key_code == MMI_UM_UI_ENTRY_KEY_CSK)
            )
        {
            g_sms_cntx.is_from_hs = MMI_FALSE;
            mmi_sms_um_set_sms_context(entry_msg_param->msg_id);
        #ifdef __MMI_UM_ITERATOR_VIEWER__
            g_sms_cntx.user_data = entry_msg_param->user_data;
        #endif /* __MMI_UM_ITERATOR_VIEWER__ */

            mmi_sms_group_entry(entry_msg_param->parent_grp_id);
            mmi_sms_view_curr_msg();
            cur_gid = g_sms_gid;
        }
    }

    return cur_gid;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_set_sms_context
 * DESCRIPTION
 *  Get inbox message header
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_um_set_sms_context(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_box_enum msg_box_type = SRV_SMS_BOX_NONE;
    mmi_sms_list_enum list_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_get_msg_list_index(&msg_box_type, (U16) msg_id);

	switch (msg_box_type)
    {
        case SRV_SMS_BOX_INBOX:
            list_type = MMI_SMS_LIST_INBOX;
            break;

        case SRV_SMS_BOX_UNSENT:
            list_type = MMI_SMS_LIST_UNSENT;
            break;

        case SRV_SMS_BOX_OUTBOX:
            list_type = MMI_SMS_LIST_OUTBOX;
            break;

        case SRV_SMS_BOX_DRAFTS:
            list_type = MMI_SMS_LIST_DRAFTS;
            break;

    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__        
        case SRV_SMS_BOX_ARCHIVE:
            list_type = MMI_SMS_LIST_ARCHIVE;
            break;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case SRV_SMS_BOX_SIM:
            list_type = MMI_SMS_LIST_SIMBOX;
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

    #ifdef __MMI_UM_REPORT_BOX__
        case SRV_SMS_BOX_REPORT:
            list_type = MMI_SMS_LIST_REPORT;
            break; 
    #endif /* __MMI_UM_REPORT_BOX__ */

        default:
            list_type = MMI_SMS_LIST_NONE;
            break;
    }

    g_sms_cntx.curr_msg_id = (U16)msg_id;
    g_sms_cntx.curr_box_type = msg_box_type;
    g_sms_cntx.curr_list_type = list_type;
}

#ifdef __MMI_FTE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_reply
 * DESCRIPTION
 *  For um toolbar to launch the reply icon functon. 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_um_activate_reply(MMI_ID parent_grp_id, srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    srv_sms_box_enum msg_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_type == SRV_UM_MSG_SMS);

    srv_sms_get_msg_list_index(&msg_box_type, (U16)msg_id);

    mmi_sms_um_set_sms_context(msg_id);

    if (msg_box_type == SRV_SMS_BOX_ARCHIVE)
    {
    #ifdef __MMI_UNIFIED_COMPOSER__
        cui_uc_entry_msg_operation_launch(parent_grp_id, msg_id, (U16)MMI_UC_INFO_TYPE_SMS, MMI_UC_OPERATION_REPLY);
    #else /* __MMI_UNIFIED_COMPOSER__ */
        mmi_sms_group_entry(parent_grp_id);
        mmi_sms_read_msg(
            g_sms_cntx.curr_msg_id,
            MMI_FALSE,
            mmi_sms_um_activate_reply_read_callback);
    #endif /* __MMI_UNIFIED_COMPOSER__ */
    }
    else
    {
    #ifdef __MMI_UNIFIED_COMPOSER__
        cui_uc_entry_msg_operation_launch(parent_grp_id, msg_id, (U16)MMI_UC_INFO_TYPE_SMS, MMI_UC_OPERATION_REPLY);
    #else /* __MMI_UNIFIED_COMPOSER__ */
        mmi_sms_group_entry(parent_grp_id);
        mmi_sms_read_msg(
            g_sms_cntx.curr_msg_id,
            MMI_FALSE,
            mmi_sms_um_activate_reply_read_callback);
    #endif /* __MMI_UNIFIED_COMPOSER__ */
    }
    #endif /*__MMI_TELEPHONY_SUPPORT__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_common_read_callback
 * DESCRIPTION
 *  Read current highlight msg callback when press FTE toolbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_activate_common_read_callback(mmi_sms_result_enum result, void *data, mmi_sms_send_case_enum send_case)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id curr_gid = g_sms_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
        mmi_sms_msg_status_enum msg_status = *(mmi_sms_msg_status_enum*)data;

        g_sms_cntx.curr_msg_status = msg_status;
        
        if (SCR_ID_SMS_PROCESSING == GetActiveScreenId())
        {
            mmi_sms_entry_write_msg(send_case);
        }
    }

    mmi_frm_scrn_close(curr_gid, SCR_ID_SMS_PROCESSING);
}


#ifndef __MMI_UNIFIED_COMPOSER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_reply_read_callback
 * DESCRIPTION
 *  Read current highlight msg callback when press FTE toolbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_activate_reply_read_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sms_cntx.curr_box_type == SRV_SMS_BOX_ARCHIVE)
    {
        mmi_sms_um_activate_common_read_callback(result, data, SMS_SEND_CASE_ARCHIVE_REPLY);
    }
    else
    {
        mmi_sms_um_activate_common_read_callback(result, data, SMS_SEND_CASE_REPLY);
    }
}
#endif /* __MMI_UNIFIED_COMPOSER__*/

#endif /* __MMI_FTE_SUPPORT__*/
#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_check_reply
 * DESCRIPTION
 *  For um toolbar to check whether reply icon dim or not 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_um_check_reply(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    srv_sms_status_enum sms_status;
#endif
    srv_sms_box_enum msg_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_type == SRV_UM_MSG_SMS);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    sms_status = srv_sms_get_msg_status((U16)msg_id);
#endif
    srv_sms_get_msg_list_index(&msg_box_type, (U16)msg_id);

    if ((SRV_SMS_BOX_UNSENT == msg_box_type)
        || (SRV_SMS_BOX_DRAFTS == msg_box_type)
        || (SRV_SMS_BOX_OUTBOX == msg_box_type)
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        || ((msg_box_type == SRV_SMS_BOX_ARCHIVE) && (sms_status & SRV_SMS_STATUS_SENT))
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        || (!mmi_sms_check_is_valid_oa_addr((U16)msg_id))
        )
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_check_forward
 * DESCRIPTION
 *  For um toolbar to check whether forward icon dim or not 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_um_check_forward(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum sms_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_type == SRV_UM_MSG_SMS);

    sms_status = srv_sms_get_msg_status((U16)msg_id);

    if ((sms_status & SRV_SMS_STATUS_UNSUPPORTED)
        || (sms_status & SRV_SMS_STATUS_UNSENT)
        || (sms_status & SRV_SMS_STATUS_DRAFT)
        )
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_check_send
 * DESCRIPTION
 *  For um toolbar to check whether send icon dim or not 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_um_check_send(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum sms_status;
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    srv_sms_box_enum msg_box_type;
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_type == SRV_UM_MSG_SMS);
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    srv_sms_get_msg_list_index(&msg_box_type, (U16)msg_id);
    if (msg_box_type == SRV_SMS_BOX_DRAFTS)
    {
        return MMI_FALSE;
    }
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */


    sms_status = srv_sms_get_msg_status((U16)msg_id);

    if ((mmi_sms_is_send_enable() == MMI_FALSE) ||
        (sms_status & SRV_SMS_STATUS_UNSUPPORTED))
    {
        return MMI_FALSE;
    }
    else
    {
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
         srv_sms_send_status_enum backgrond_send_status = SRV_SMS_SEND_INVALID;
         backgrond_send_status = srv_sms_get_unsent_msg_status(msg_id);
         if ((SRV_SMS_SEND_WAITING == backgrond_send_status ) ||
             (SRV_SMS_SEND_SENDING== backgrond_send_status ))
         {
              return MMI_FALSE;
         }
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_check_edit
 * DESCRIPTION
 *  For um toolbar to check whether edit icon dim or not 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_um_check_edit(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (defined( __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) || defined (__MMI_MSG_EDITOR_WITH_RECIPIENT__))
    srv_sms_box_enum msg_box_type;
#endif /* (defined( __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) || defined (__MMI_MSG_EDITOR_WITH_RECIPIENT__)) */
    srv_sms_status_enum sms_status;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_type == SRV_UM_MSG_SMS);

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    srv_sms_get_msg_list_index(&msg_box_type, (U16)msg_id);

    if (msg_box_type == SRV_SMS_BOX_UNSENT)
    {
        srv_sms_send_status_enum send_status;

        send_status = srv_sms_get_unsent_msg_status((U16)msg_id);

        if (send_status != SRV_SMS_SEND_FAIL)
        {
           return MMI_FALSE;
        }
    }
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

#if (!defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__))
     srv_sms_get_msg_list_index(&msg_box_type, (U16)msg_id);
    if (msg_box_type == SRV_SMS_BOX_UNSENT)
    {
        return MMI_FALSE;
    }
#endif /* (!defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__)) */

    sms_status = srv_sms_get_msg_status((U16)msg_id);

    if (sms_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_check_resend
 * DESCRIPTION
 *  For um toolbar to check whether resend icon dim or not 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_um_check_resend(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum sms_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_type == SRV_UM_MSG_SMS);

    sms_status = srv_sms_get_msg_status((U16)msg_id);

    if ((mmi_sms_is_send_enable() == MMI_FALSE) ||
        (sms_status & SRV_SMS_STATUS_UNSUPPORTED))
    {
        return MMI_FALSE;
    }
    else
    {
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
         srv_sms_send_status_enum backgrond_send_status = SRV_SMS_SEND_INVALID;
         backgrond_send_status = srv_sms_get_unsent_msg_status(msg_id);
         if ((SRV_SMS_SEND_WAITING == backgrond_send_status ) ||
             (SRV_SMS_SEND_SENDING== backgrond_send_status ))
         {
              return MMI_FALSE;
         }
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_check_copy
 * DESCRIPTION
 *  For um toolbar to check whether copy icon dim or not 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_um_check_copy(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_type == SRV_UM_MSG_SMS);

#ifdef __MMI_MESSAGES_COPY__
    return (MMI_BOOL)(0 != srv_sim_ctrl_get_one_available_sim());
#else /* __MMI_MESSAGES_COPY__ */
    return MMI_FALSE;
#endif /* __MMI_MESSAGES_COPY__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_check_move
 * DESCRIPTION
 *  For um toolbar to check whether move icon dim or not 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_um_check_move(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_type == SRV_UM_MSG_SMS);

#ifdef __MMI_MESSAGES_COPY__
    return MMI_TRUE;
#else /* __MMI_MESSAGES_COPY__ */
    return MMI_FALSE;
#endif /* __MMI_MESSAGES_COPY__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_check_delete
 * DESCRIPTION
 *  For um toolbar to check whether delete icon dim or not 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_um_check_delete(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    srv_sms_box_enum msg_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_type == SRV_UM_MSG_SMS);

    srv_sms_get_msg_list_index(&msg_box_type, (U16)msg_id);

    if (msg_box_type == SRV_SMS_BOX_UNSENT)
    {
        srv_sms_send_status_enum send_status;

        send_status = srv_sms_get_unsent_msg_status((U16)msg_id);

        if (send_status != SRV_SMS_SEND_FAIL)
        {
           return MMI_FALSE;
        }
    }
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_forward
 * DESCRIPTION
 *  For um toolbar to launch the forward icon functon.  
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_um_activate_forward(MMI_ID parent_grp_id, srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_type == SRV_UM_MSG_SMS);

    mmi_sms_um_set_sms_context(msg_id);

#ifdef __MMI_UNIFIED_COMPOSER__
    cui_uc_entry_msg_operation_launch(parent_grp_id, msg_id, (U16)MMI_UC_INFO_TYPE_SMS, MMI_UC_OPERATION_FORWARD);
#else /* __MMI_UNIFIED_COMPOSER__ */
    mmi_sms_group_entry(parent_grp_id);
    mmi_sms_read_msg(
        g_sms_cntx.curr_msg_id,
        MMI_FALSE,
        mmi_sms_um_activate_forward_read_callback);
#endif /* __MMI_UNIFIED_COMPOSER__ */        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_send
 * DESCRIPTION
 *  For um toolbar to launch the send icon functon.  
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_um_activate_send(MMI_ID parent_grp_id, srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_type == SRV_UM_MSG_SMS);

    mmi_sms_um_set_sms_context(msg_id);

    mmi_sms_group_entry(parent_grp_id);

    mmi_sms_read_msg(
        g_sms_cntx.curr_msg_id,
        MMI_FALSE,
        mmi_sms_um_activate_send_read_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_edit
 * DESCRIPTION
 *  For um toolbar to launch the edit icon functon.  
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_um_activate_edit(MMI_ID parent_grp_id, srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_type == SRV_UM_MSG_SMS);

    mmi_sms_um_set_sms_context(msg_id);

#ifdef __MMI_UNIFIED_COMPOSER__
    cui_uc_entry_msg_operation_launch(parent_grp_id, msg_id, (U16)MMI_UC_INFO_TYPE_SMS, MMI_UC_OPERATION_EDIT_EXISTED_MSG);
#else /* __MMI_UNIFIED_COMPOSER__ */
    mmi_sms_group_entry(parent_grp_id);
    mmi_sms_read_msg(
        g_sms_cntx.curr_msg_id,
        MMI_FALSE,
        mmi_sms_um_activate_edit_read_callback);
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_resend
 * DESCRIPTION
 *  For um toolbar to launch the resend icon functon.  
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_um_activate_resend(MMI_ID parent_grp_id, srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_type == SRV_UM_MSG_SMS);

    mmi_sms_um_set_sms_context(msg_id);

    mmi_sms_group_entry(parent_grp_id);
#ifndef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    mmi_sms_read_msg(
        g_sms_cntx.curr_msg_id,
        MMI_FALSE,
        mmi_sms_um_activate_resend_read_callback);
#else
    mmi_sms_list_opt_bg_send();
#endif
    
}


#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_copy
 * DESCRIPTION
 *  For um toolbar to launch the copy icon functon.  
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_um_activate_copy(MMI_ID parent_grp_id, srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_type == SRV_UM_MSG_SMS);

    mmi_sms_um_set_sms_context(msg_id);

    mmi_sms_group_entry(parent_grp_id);

    mmi_sms_copy_msg(
        g_sms_cntx.curr_msg_id,
        SRV_SMS_STORAGE_ME,
        mmi_sms_um_activate_copy_callback); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_move
 * DESCRIPTION
 *  For um toolbar to launch the move icon functon.  
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_um_activate_move(MMI_ID parent_grp_id, srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_type == SRV_UM_MSG_SMS);

    mmi_sms_um_set_sms_context(msg_id);

    mmi_sms_group_entry(parent_grp_id);

    mmi_sms_move_msg(
        g_sms_cntx.curr_msg_id,
        SRV_SMS_STORAGE_ME,
        mmi_sms_um_activate_move_callback);
}
#endif /*__UNIFIED_MESSAGE_SIMBOX_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_delete
 * DESCRIPTION
 *  For um toolbar to launch the delete icon functon.  
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_um_activate_delete(MMI_ID parent_grp_id, srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__))
    srv_sms_box_enum msg_box_type;
#endif /* (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)) */    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__))
    srv_sms_get_msg_list_index(&msg_box_type, (U16)msg_id);

    if ((msg_box_type == SRV_SMS_BOX_ARCHIVE) && (srv_usb_is_in_mass_storage_mode()))
    {
        mmi_usb_app_unavailable_popup(0);
    }
    else
#endif /* (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)) */
    {
        mmi_sms_um_set_sms_context(msg_id);

        mmi_sms_group_entry(parent_grp_id);

        mmi_sms_entry_confirm_sg(
            g_sms_gid,
            STR_GLOBAL_DELETE_ASK,
            mmi_sms_um_activate_delete_confirm,
            mmi_frm_scrn_close_active_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_delete_confirm
 * DESCRIPTION
 *  For um toolbar to launch the delete confirm.  
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_activate_delete_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_delete_msg(g_sms_cntx.curr_msg_id, mmi_sms_um_activate_delete_callback);  
}


#ifndef __MMI_UNIFIED_COMPOSER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_forward_read_callback
 * DESCRIPTION
 *  Read current highlight msg callback when press FTE toolbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_activate_forward_read_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_um_activate_common_read_callback(result, data, SMS_SEND_CASE_FORWARD);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_edit_read_callback
 * DESCRIPTION
 *  Read current highlight msg callback when press FTE toolbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_activate_edit_read_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id curr_gid = g_sms_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
        mmi_sms_msg_status_enum msg_status = *(mmi_sms_msg_status_enum*)data;

        g_sms_cntx.curr_msg_status = msg_status;

        if (SCR_ID_SMS_PROCESSING == GetActiveScreenId())
        {
            if (g_sms_cntx.curr_msg_status == SMS_STATUS_DRAFTS)
            {
                mmi_sms_entry_write_msg(SMS_SEND_CASE_EDIT_DRAFT);
            }
            else
            {
                mmi_sms_entry_write_msg(SMS_SEND_CASE_EDIT_UNSENT);
            }
        }
    }

    mmi_frm_scrn_close(curr_gid, SCR_ID_SMS_PROCESSING);
}

#endif /* __MMI_UNIFIED_COMPOSER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_send_read_callback
 * DESCRIPTION
 *  Read current highlight msg callback when press FTE toolbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_activate_send_read_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_um_activate_common_read_callback(result, data, SMS_SEND_CASE_SEND_DRAFT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_resend_read_callback
 * DESCRIPTION
 *  Read current highlight msg callback when press FTE toolbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_activate_resend_read_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_um_activate_common_read_callback(result, data, SMS_SEND_CASE_RESEND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_delete_callback
 * DESCRIPTION
 *  Delete callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_activate_delete_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
        g_sms_cntx.curr_msg_id = SRV_SMS_INVALID_MSG_ID;
    }
}


#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_move_callback
 * DESCRIPTION
 *  Move message callback function when press move FTE toolbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_activate_move_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
        g_sms_cntx.curr_msg_id = SRV_SMS_INVALID_MSG_ID;
    }
#if (defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__))
    mmi_msg_update_unsent_icon();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_copy_callback
 * DESCRIPTION
 *  Move message callback function when press move FTE toolbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_activate_copy_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
        g_sms_cntx.curr_msg_id = SRV_SMS_INVALID_MSG_ID;
    }
#if (defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__))
    mmi_msg_update_unsent_icon();
#endif
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#endif  /* __MMI_ICON_BAR_SUPPORT__ */


#ifdef __MMI_UM_ITERATOR_VIEWER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_iter_viewer_query_indexing_callback
 * DESCRIPTION
 *  If um return fail when sms query indexing, this is the callback
 * PARAMETERS
 *  user_data     [IN]:   sms user data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_iter_viewer_query_indexing_callback(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (mmi_sms_iter_viewer_query_indexing() == MMI_TRUE)
    {
        mmi_sms_iter_viewer_entry_viewer_scrn();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_iter_viewer_query_indexing_callback
 * DESCRIPTION
 *  If um return fail when sms query indexing, this is the callback
 * PARAMETERS
 *  user_data     [IN]:   sms user data
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sms_iter_viewer_query_indexing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL query_ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sms_is_msg_exist(g_sms_cntx.curr_msg_id))
    {
        mmi_frm_group_close(g_sms_gid);
    }
    else
    {
        mmi_um_iter_viewer_info_struct info;
        info.msg_id     = g_sms_cntx.curr_msg_id;
        info.msg_type   = SRV_UM_MSG_SMS;
        info.func_cb    = mmi_sms_iter_viewer_query_indexing_callback;
        if (g_sms_cntx.iter_viewer_result == NULL)
        {
            g_sms_cntx.iter_viewer_result = (mmi_um_iter_viewer_result_struct *)OslMalloc(sizeof(mmi_um_iter_viewer_result_struct));
            memset(g_sms_cntx.iter_viewer_result, 0, sizeof(mmi_um_iter_viewer_result_struct));
        }

        query_ret = mmi_um_query_indexing(&info, g_sms_cntx.iter_viewer_result, g_sms_cntx.user_data);
    }
    return query_ret;
}

#endif /* __MMI_UM_ITERATOR_VIEWER__ */

#ifndef __MMI_SMS_SLIM__

#ifdef __UM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_list_opt_cb_hdlr
 * DESCRIPTION
 *  Response to UM list options menu cui event
 * PARAMETERS
 *  evt       :     [IN]        mmi_evt_struct
 *  msg_id    :     [IN]        message ID
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_um_list_opt_cb_hdlr(mmi_event_struct *evt, mmi_um_opt_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    return mmi_sms_box_list_opt_cb_hdlr(para->parent_grp_id, evt, (U16)para->msg_id);
}
#endif

#endif
