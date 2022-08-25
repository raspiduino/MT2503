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
 *  SmsAppMsg.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Application Primitive Handler with the SMS framework or L4
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_TELEPHONY_SUPPORT__

/**************************************************************
* Header Files Include
**************************************************************/
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "kal_general_types.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "kal_public_api.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "smsal_l4c_enum.h"
#include "Unicodexdcl.h"
#include "stdio.h"
#include "mmi_rp_app_sms_def.h"
#include "mmi_trc_int.h"

#include "SmsSrvGprot.h"

#include "Ems.h"

#include "SmsAppType.h"
#include "SmsAppProt.h"
#include "SmsAppMsg.h"
#include "SmsAppUtil.h"
#include "SmsGuiInterfaceProt.h"

#include "SmsPsHandler.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif /* __USB_IN_NORMAL_MODE__ */
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
#include "FileMgrSrvGProt.h"
#endif

/**************************************************************
* Global Variables Defination
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
static void mmi_sms_read_msg_rsp(srv_sms_callback_struct* callback_data);
static void mmi_sms_delete_msg_rsp(srv_sms_callback_struct* callback_data);
#ifdef __MMI_MESSAGES_COPY__
static void mmi_sms_copy_msg_rsp(srv_sms_callback_struct* callback_data);
static void mmi_sms_copy_msg_all_rsp(srv_sms_callback_struct* callback_data);
static void mmi_msg_move_msg_rsp(srv_sms_callback_struct* callback_data);
static void mmi_sms_move_msg_all_rsp(srv_sms_callback_struct* callback_data);
#endif
static void mmi_sms_change_sms_read_unread_rsp(srv_sms_callback_struct* callback_data);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
static void mmi_sms_move_msg_to_archive_rsp(srv_sms_callback_struct* callback_data);
#endif

/**************************************************************
* Function Defination
**************************************************************/

#ifndef __ULC_SLIM_EMS__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_read_msg
 * DESCRIPTION
 *  Read Message
 * PARAMETERS
 *  msg_index           [IN]    Msg Index
 *  callback_func   [IN]    Callback Function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_read_msg(U16 msg_id, MMI_BOOL change_status, SmsCBFuncPtr callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__))
    srv_sms_box_enum curr_box_type;
#endif /* (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__))
    srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);

    if ((curr_box_type == SRV_SMS_BOX_ARCHIVE) &&
        (srv_usb_is_in_mass_storage_mode()))
    {
        mmi_usb_app_unavailable_popup(0);
    }
    else
#endif /* (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)) */
	if (srv_sms_is_sms_ready() == MMI_FALSE)
    {
        mmi_sms_display_popup_ext(
            STR_SMS_MSG_NOT_READY_YET,
            MMI_EVENT_FAILURE);

        if (callback_func != NULL)
        {
            callback_func(SMS_RESULT_ERROR, NULL);
        }
    }
    else
    {
        srv_sms_msg_data_struct *msg_data;

        msg_data = (srv_sms_msg_data_struct*)OslMalloc(sizeof(srv_sms_msg_data_struct));

        mmi_sms_set_and_entry_processing_sg(g_sms_gid, STR_GLOBAL_PLEASE_WAIT, 0);

        msg_data->para_flag = SRV_SMS_PARA_CONTENT_EMS;

        msg_data->content_ems = (EMSData*)GetEMSDataForView(NULL, 1);

    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        msg_data->para_flag |= SRV_SMS_PARA_PID;
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */

        srv_sms_read_msg(
            msg_id,
            change_status,
            msg_data,
            mmi_sms_read_msg_rsp,
            (void*)callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_read_msg_rsp
 * DESCRIPTION
 *  Entry send screen
 * PARAMETERS
 *  data        [IN]    Dummy
 *  mod         [IN]    Module Type
 *  result      [IN]    SMS Framework Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_read_msg_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_read_msg_cb_struct *read_msg_cb_data;
    srv_sms_msg_data_struct *msg_data;
    SmsCBFuncPtr callback_func;
    mmi_sms_result_enum action_result;
    mmi_sms_msg_status_enum msg_status = SMS_STATUS_UNSUPPORT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_msg_cb_data = (srv_sms_read_msg_cb_struct*)callback_data->action_data;
    callback_func = (SmsCBFuncPtr)callback_data->user_data;

    msg_data = read_msg_cb_data->msg_data;

	if (callback_data->result == MMI_FALSE)
	{
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        if (callback_data->cause == SRV_SMS_CAUSE_ARCH_FILE_NOT_EXIST)
        {
            mmi_sms_entry_confirm(
                g_sms_gid,
                STR_ID_SMS_DEL_CORRUPT_MSG_QUERY,
                mmi_sms_delete_curr_archive_msg,
                mmi_frm_scrn_close_active_id,
                MMI_TRUE);
        }
        else
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        {
            mmi_sms_display_popup_ext(
                STR_GLOBAL_UNFINISHED,
                MMI_EVENT_FAILURE);
        }

        action_result = SMS_RESULT_ERROR;
	}
    else
    {
        if (msg_data->mti == SRV_SMS_MTI_STATUS_REPORT)
        {
            if (msg_data->tp_st == ST_COMP_MSG_RECV_BY_SME)
            {
                msg_status = SMS_STATUS_DELIVERY_REPORT;
            }
            else
            {
                msg_status = SMS_STATUS_PENDING_REPORT;
            }
        }
        else
        {
            srv_sms_status_enum srv_status = msg_data->status;

            if (srv_status & SRV_SMS_STATUS_UNSUPPORTED)
            {
                msg_status = SMS_STATUS_UNSUPPORT;
            }
            else
            {
                switch (srv_status)
                {
                    case SRV_SMS_STATUS_UNREAD:
                        msg_status = SMS_STATUS_UNREAD;
                        break;

                    case SRV_SMS_STATUS_READ:
                        msg_status = SMS_STATUS_INBOX;
                        break;

                    case SRV_SMS_STATUS_SENT:
                        msg_status = SMS_STATUS_SENT;
                        break;

                    case SRV_SMS_STATUS_UNSENT:
                        msg_status = SMS_STATUS_UNSENT;
                        break;

                    case SRV_SMS_STATUS_DRAFT:
                        msg_status = SMS_STATUS_DRAFTS;
                        break;

                    default:
                        MMI_ASSERT(0);
                        break;
                }

            #ifdef __MMI_MESSAGES_SMS_EMAIL__
            	if (msg_data->pid == SRV_SMS_PID_EMAIL)
            	{
                    EMSData *ems_data = msg_data->content_ems;
                    U16 addr_length = 0;
                    g_sms_cntx.is_sms_email = MMI_TRUE;

            	    memset(g_sms_cntx.sms_email_addr, 0, sizeof(g_sms_cntx.sms_email_addr));

            		mmi_msg_get_email_and_subject_from_msgtxt(
                        (S8 *)ems_data->textBuffer,
                        ems_data->textLength,
            			g_sms_cntx.sms_email_addr,
            			(MMI_SMS_MAX_EMAIL_ADDR_LEN * ENCODING_LENGTH),
            			NULL,
            			0,
            			&addr_length, 
            			NULL);

                    mmi_msg_remove_email_address_from_msgtxt(ems_data, addr_length);
            	}
            	else
            	{
                    g_sms_cntx.is_sms_email = MMI_FALSE;
            	}
            #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
            }
        }

        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
    #if (MMI_MAX_SIM_NUM == 2)
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);
    #endif

        action_result = SMS_RESULT_OK;
    }

    OslMfree(msg_data);

    if (callback_func != NULL)
    {
        callback_func(action_result, &msg_status);
    }
}
#else /* __ULC_SLIM_EMS__ */
/*****************************************************************************
* FUNCTION
*  mmi_sms_read_msg_pre_check
* DESCRIPTION
*  Read Message
* PARAMETERS
*  msg_id           [IN]    Msg id
* RETURNS
*  MMI_TRUE  if msg are ready for read operation
*  MMI_FALSE Msg are not ready and related popup screen is shown.
*****************************************************************************/
MMI_BOOL mmi_sms_read_msg_pre_check(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__))
    srv_sms_box_enum curr_box_type;
#endif /* (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)) */
    MMI_BOOL is_ready_to_read = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__))
    srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);

    if ((curr_box_type == SRV_SMS_BOX_ARCHIVE) &&
        (mmi_usb_is_in_mass_storage_mode()))
    {
        mmi_usb_app_unavailable_popup(0);
        is_ready_to_read = MMI_FALSE;
    }
    else
#endif /* (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)) */
    if (srv_sms_is_sms_ready() == MMI_FALSE)
    {
        mmi_sms_display_popup(
            (UI_string_type) GetString(STR_SMS_MSG_NOT_READY_YET),
            MMI_EVENT_FAILURE);
        is_ready_to_read = MMI_FALSE;
    }
    return is_ready_to_read;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_read_msg_text_only
 * DESCRIPTION
 *  Read Message
 * PARAMETERS
 *  msg_index           [IN]    Msg Index
 *  callback_func   [IN]    Callback Function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_read_msg(U16 msg_id, MMI_BOOL change_status, SmsCBFuncPtr callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData* content_ems = GetEMSDataForView(NULL, 1);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sms_read_msg_pre_check(msg_id))
    {
        srv_sms_msg_data_struct *msg_data;

        msg_data = (srv_sms_msg_data_struct*)OslMalloc(sizeof(srv_sms_msg_data_struct));

        mmi_sms_set_and_entry_processing_sg(g_sms_gid, STR_GLOBAL_PLEASE_WAIT, 0);

        msg_data->para_flag = SRV_SMS_PARA_CONTENT_BUFF;

        msg_data->content_buff = (S8*)content_ems->textBuffer;
        msg_data->content_buff_size= content_ems->textBufferSize + ENCODING_LENGTH;
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        msg_data->para_flag |= SRV_SMS_PARA_PID;
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */

        srv_sms_read_msg(
            msg_id,
            change_status,
            msg_data,
            mmi_sms_read_msg_rsp,
            (void*)callback_func);
    }
    else
    {
        if (callback_func != NULL)
        {
            callback_func(SMS_RESULT_ERROR, NULL);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_read_msg_text_only_rsp
 * DESCRIPTION
 *  Entry send screen
 * PARAMETERS
 *  data        [IN]    Dummy
 *  mod         [IN]    Module Type
 *  result      [IN]    SMS Framework Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_read_msg_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_read_msg_cb_struct *read_msg_cb_data;
    srv_sms_msg_data_struct *msg_data;
    SmsCBFuncPtr callback_func;
    mmi_sms_result_enum action_result;
    mmi_sms_msg_status_enum msg_status = SMS_STATUS_UNSUPPORT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_msg_cb_data = (srv_sms_read_msg_cb_struct*)callback_data->action_data;
    callback_func = (SmsCBFuncPtr)callback_data->user_data;

    msg_data = read_msg_cb_data->msg_data;

	if (callback_data->result == MMI_FALSE)
	{
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        if (callback_data->cause == SRV_SMS_CAUSE_ARCH_FILE_NOT_EXIST)
        {
            mmi_sms_entry_confirm(
                g_sms_gid,
                STR_ID_SMS_DEL_CORRUPT_MSG_QUERY,
                mmi_sms_delete_curr_archive_msg,
                mmi_frm_scrn_close_active_id,
                MMI_TRUE);
        }
        else
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        {
            mmi_sms_display_popup(
                (UI_string_type) GetString(STR_GLOBAL_UNFINISHED),
                MMI_EVENT_FAILURE);
        }

        action_result = SMS_RESULT_ERROR;
	}
    else
    {
        if (msg_data->mti == SRV_SMS_MTI_STATUS_REPORT)
        {
            if (msg_data->tp_st == ST_COMP_MSG_RECV_BY_SME)
            {
                msg_status = SMS_STATUS_DELIVERY_REPORT;
            }
            else
            {
                msg_status = SMS_STATUS_PENDING_REPORT;
            }
        }
        else
        {
            srv_sms_status_enum srv_status = msg_data->status;

            if (srv_status & SRV_SMS_STATUS_UNSUPPORTED)
            {
                msg_status = SMS_STATUS_UNSUPPORT;
            }
            else
            {
                switch (srv_status)
                {
                    case SRV_SMS_STATUS_UNREAD:
                        msg_status = SMS_STATUS_UNREAD;
                        break;

                    case SRV_SMS_STATUS_READ:
                        msg_status = SMS_STATUS_INBOX;
                        break;

                    case SRV_SMS_STATUS_SENT:
                        msg_status = SMS_STATUS_SENT;
                        break;

                    case SRV_SMS_STATUS_UNSENT:
                        msg_status = SMS_STATUS_UNSENT;
                        break;

                    case SRV_SMS_STATUS_DRAFT:
                        msg_status = SMS_STATUS_DRAFTS;
                        break;

                    default:
                        MMI_ASSERT(0);
                        break;
                }

            #ifdef __MMI_MESSAGES_SMS_EMAIL__
            	if (msg_data->pid == SRV_SMS_PID_EMAIL)
            	{
                    U16 addr_length = 0;
                    g_sms_cntx.is_sms_email = MMI_TRUE;

            	    memset(g_sms_cntx.sms_email_addr, 0, sizeof(g_sms_cntx.sms_email_addr));

            		mmi_msg_get_email_and_subject_from_msgtxt(
                        msg_data->content_bufff,
                        mmi_ucs2strlen((CHAR*)msg_data->content_bufff),
            			g_sms_cntx.sms_email_addr,
            			(MMI_SMS_MAX_EMAIL_ADDR_LEN * ENCODING_LENGTH),
            			NULL,
            			0,
            			&addr_length,
            			NULL);

                    mmi_msg_remove_email_address_from_text_only_msgtxt(msg_data->content_bufff, addr_length);
            	}
            	else
            	{
                    g_sms_cntx.is_sms_email = MMI_FALSE;
            	}
            #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
            }
        }

        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
    #if (MMI_MAX_SIM_NUM == 2)
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);
    #endif

        action_result = SMS_RESULT_OK;
    }

    OslMfree(msg_data);

    if (callback_func != NULL)
    {
        callback_func(action_result, &msg_status);
    }
}

#endif /* __ULC_SLIM_EMS__ */


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_delete_curr_archive_msg
 * DESCRIPTION
 *  Delete Msg
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_delete_curr_archive_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_delete_msg(g_sms_cntx.curr_msg_id, NULL);
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_delete_msg
 * DESCRIPTION
 *  Delete Msg
 * PARAMETERS
 *  index           [IN]    Msg Index
 *  callback_func   [IN]    Callback Function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_delete_msg(U16 msg_id, SmsCBFuncPtr callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__))
    srv_sms_box_enum curr_box_type;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__))
    srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);

    if ((curr_box_type == SRV_SMS_BOX_ARCHIVE) &&
        (srv_usb_is_in_mass_storage_mode()))
    {
        mmi_usb_app_unavailable_popup(0);
        if (!mmi_frm_scrn_get_count(g_sms_gid))
        {
            mmi_frm_group_close(g_sms_gid);
        }
    }
    else
#endif /* (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)) */
    {
        mmi_sms_set_and_entry_processing_sg(g_sms_gid, STR_GLOBAL_DELETING, 0);

        srv_sms_delete_msg(
            msg_id,
            mmi_sms_delete_msg_rsp,
            (void*)callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_delete_msg_rsp
 * DESCRIPTION
 *  Delete Msg Response
 * PARAMETERS
 *  data        [IN]    Dummy
 *  mod         [IN]    Module Type
 *  result      [IN]    SMS Framework Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_delete_msg_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_result_enum action_result = SMS_RESULT_OK;
    SmsCBFuncPtr callback_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callback_func = (SmsCBFuncPtr)callback_data->user_data;

    if (callback_data->result == MMI_FALSE)
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_UNFINISHED,
            MMI_EVENT_FAILURE);

        action_result = SMS_RESULT_ERROR;
    }

    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
#if (MMI_MAX_SIM_NUM == 2)
    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);
#endif

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    mmi_msg_update_unsent_icon();
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

    mmi_msg_handle_new_sms_flag();

    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);

    if (callback_func != NULL)
    {
        callback_func(action_result, NULL);
    }
}


#ifdef __MMI_MESSAGES_COPY__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_copy_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_copy_msg_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_result_enum action_result = SMS_RESULT_OK;
    SmsCBFuncPtr callback_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callback_func = (SmsCBFuncPtr)callback_data->user_data;

    if (callback_data->result == MMI_FALSE)
    {
        U16 str_id;

        if ((callback_data->cause == SRV_SMS_CAUSE_MEM_FULL) ||
            (callback_data->cause == SRV_SMS_CAUSE_MEM_INSUFFICIENT))
        {
            str_id = STR_GLOBAL_MEMORY_FULL;

            action_result = SMS_RESULT_MEM_FULL;
        }
        else
        {
            str_id = STR_GLOBAL_UNFINISHED;

            action_result = SMS_RESULT_ERROR;
        }

        mmi_sms_display_popup_ext(
            str_id,
            MMI_EVENT_FAILURE);
    }

    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);

    if (callback_func != NULL)
    {
        callback_func(action_result, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_move_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_move_msg_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_copy_msg_rsp(callback_data);
}




/*****************************************************************************
 * FUNCTION
 *  mmi_sms_copy_move_msg_all_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_copy_move_msg_all_rsp(srv_sms_callback_struct* callback_data, U16 done_msg_num, MMI_BOOL copy_op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_result_enum action_result;
    SmsCBFuncPtr callback_func;
    WCHAR causeString[100];
    U16 str_id;
    U16 mulstr_id;
    U16 nostr_id;
    U16 temp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callback_func = (SmsCBFuncPtr)callback_data->user_data;

    if (copy_op)
    {
        str_id = STR_ID_SMS_MESSAGE_COPIED;
        mulstr_id = STR_ID_SMS_MESSAGES_COPIED;
        nostr_id = STR_ID_SMS_NO_MESSAGE_COPIED;
    }
    else
    {
        str_id = STR_ID_SMS_MESSAGE_MOVED;
        mulstr_id = STR_ID_SMS_MESSAGES_MOVED;
        nostr_id = STR_ID_SMS_NO_MESSAGE_MOVED;
    }

    if (done_msg_num <= 1)
    {
        temp_id = str_id;
    }
    else
    {
        temp_id = mulstr_id;
    }

    if (callback_data->result == MMI_TRUE)
    {
        action_result = SMS_RESULT_OK;

        if(done_msg_num == 0)
        {
            mmi_ucs2cpy((S8*)causeString, (S8*)GetString(nostr_id));
            mmi_sms_display_popup((UI_string_type) causeString, MMI_EVENT_INFO);
        }
    }
    else
    {
        if ((callback_data->cause == SRV_SMS_CAUSE_MEM_FULL)
            ||(callback_data->cause == SRV_SMS_CAUSE_MEM_INSUFFICIENT)
            )
        {
            action_result = SMS_RESULT_MEM_FULL;
        }
        else
        {
            action_result = SMS_RESULT_ERROR;
        }

        kal_wsprintf(causeString, 
            "%w\n  %d  %w", 
            GetString(STR_GLOBAL_DONE),
            done_msg_num, 
            GetString(temp_id));

        mmi_sms_display_popup((UI_string_type) causeString, MMI_EVENT_FAILURE);
    }

    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);

    if (callback_func != NULL)
    {
        callback_func(action_result, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_copy_msg_all_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_copy_msg_all_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_copy_msg_list_cb_struct *copy_cb_data;
    U16 copied_msg_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_cb_data = (srv_sms_copy_msg_list_cb_struct*)callback_data->action_data;

    copied_msg_num = copy_cb_data->copied_msg_num;

    mmi_sms_copy_move_msg_all_rsp(callback_data, copied_msg_num, MMI_TRUE);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_move_msg_all_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_move_msg_all_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_move_msg_list_cb_struct *move_cb_data;
    U16 moved_msg_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    move_cb_data = (srv_sms_move_msg_list_cb_struct*)callback_data->action_data;

    moved_msg_num = move_cb_data->moved_msg_num;

    mmi_sms_copy_move_msg_all_rsp(callback_data, moved_msg_num, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_copy_msg
 * DESCRIPTION
 *  Entry send screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_copy_msg(U16 msg_id, srv_sms_storage_enum dest_storage, SmsCBFuncPtr callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_set_and_entry_processing_sg(g_sms_gid, STR_GLOBAL_COPYING, 0);

    srv_sms_copy_msg(
        msg_id,
        dest_storage,
        mmi_sms_copy_msg_rsp,
        (void*)callback_func);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_move_msg
 * DESCRIPTION
 *  Entry send screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_move_msg(U16 msg_id, srv_sms_storage_enum dest_storage, SmsCBFuncPtr callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_set_and_entry_processing_sg(g_sms_gid, STR_GLOBAL_MOVING, 0);

    srv_sms_move_msg(
        msg_id,
        dest_storage,
        mmi_msg_move_msg_rsp,
        (void*)callback_func);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_copy_msg
 * DESCRIPTION
 *  Entry send screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_copy_msg_ext(U16 msg_id, srv_sms_storage_enum dest_storage, srv_sms_sim_enum sim_id, SmsCBFuncPtr callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_set_and_entry_processing_sg(g_sms_gid, STR_GLOBAL_COPYING, 0);

    srv_sms_copy_msg_ext(
        msg_id,
        dest_storage,
        sim_id,
        mmi_sms_copy_msg_rsp,
        (void*)callback_func);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_move_msg_ext
 * DESCRIPTION
 *  Entry send screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_move_msg_ext(U16 msg_id, srv_sms_storage_enum dest_storage, srv_sms_sim_enum sim_id, SmsCBFuncPtr callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_set_and_entry_processing_sg(g_sms_gid, STR_GLOBAL_MOVING, 0);

    srv_sms_move_msg_ext(
        msg_id,
        dest_storage,
        sim_id,
        mmi_sms_copy_msg_rsp,
        (void*)callback_func);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_copy_all_sms
 * DESCRIPTION
 *  Entry send screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_copy_all_sms(
        srv_sms_box_enum msg_box_type,
        srv_sms_storage_enum dest_storage,
        srv_sms_sim_enum sim_id,
        SmsCBFuncPtr callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_set_and_entry_processing_sg(g_sms_gid, STR_GLOBAL_COPYING, 0);

    srv_sms_copy_msg_list(
        msg_box_type,
        dest_storage,
        sim_id,
        mmi_sms_copy_msg_all_rsp,
        (void*)callback_func);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_move_all_sms
 * DESCRIPTION
 *  Entry send screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_move_all_sms(
        srv_sms_box_enum msg_box_type,
        srv_sms_storage_enum dest_storage,
        srv_sms_sim_enum sim_id,
        SmsCBFuncPtr callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_set_and_entry_processing_sg(g_sms_gid, STR_GLOBAL_MOVING, 0);

    srv_sms_move_msg_list(
        msg_box_type,
        dest_storage,
        sim_id,
        mmi_sms_move_msg_all_rsp,
        (void*)callback_func);
}

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_copy_all_sms_tcard
 * DESCRIPTION
 *  mmi_sms_copy_all_sms_tcard
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_copy_all_sms_tcard(
                srv_sms_box_enum msg_box_type,
                srv_sms_storage_enum src_storage,
                srv_sms_storage_enum dest_storage,
                srv_sms_sim_enum sim_id,
                SmsCBFuncPtr callback_func)
{
 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_copy_move_tcard_struct copy_move;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_move.msg_box_type   = msg_box_type;
    copy_move.src_storage  =src_storage;
    copy_move.dest_storage = dest_storage;
    copy_move.sim_id = sim_id;
     mmi_sms_set_and_entry_processing_sg(g_sms_gid, STR_GLOBAL_COPYING, 0);
     srv_sms_copy_msg_list_tcard(&copy_move,mmi_sms_copy_msg_all_rsp,(void*)callback_func);
 }


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_copy_all_sms_tcard
 * DESCRIPTION
 *  mmi_sms_copy_all_sms_tcard
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_move_all_sms_tcard(
                srv_sms_box_enum msg_box_type,
                srv_sms_storage_enum src_storage,
                srv_sms_storage_enum dest_storage,
                srv_sms_sim_enum sim_id,
                SmsCBFuncPtr callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_copy_move_tcard_struct copy_move;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_move.msg_box_type   = msg_box_type;
    copy_move.src_storage  =src_storage;
    copy_move.dest_storage = dest_storage;
    copy_move.sim_id = sim_id;
     mmi_sms_set_and_entry_processing_sg(g_sms_gid, STR_GLOBAL_MOVING, 0);
     srv_sms_move_msg_list_tcard(&copy_move,mmi_sms_move_msg_all_rsp,(void*)callback_func);
 }
#endif /*__MMI_SMS_TCARD_STORAGE_SUPPORT__*/
#endif /* __MMI_MESSAGES_COPY__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_change_sms_read_unread_rsp
 * DESCRIPTION
 *  Change Inbox SMS status response
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_change_sms_read_unread_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_result_enum action_result = SMS_RESULT_OK;
    SmsCBFuncPtr callback_func;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callback_func = (SmsCBFuncPtr)callback_data->user_data;

    if (callback_data->result == MMI_FALSE)
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_UNFINISHED,
            MMI_EVENT_FAILURE);
        action_result = SMS_RESULT_ERROR;
    }

    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);

    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
#if (MMI_MAX_SIM_NUM == 2)
    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);
#endif

    if (callback_func != NULL)
    {
        callback_func(action_result, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_change_sms_status
 * DESCRIPTION
 *  Change Inbox SMS status request
 * PARAMETERS
 *  status      [IN]    the status of the SMS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_change_sms_status(U16 msg_id, srv_sms_status_enum status, SmsCBFuncPtr callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/   
    mmi_sms_set_and_entry_processing_sg(g_sms_gid, STR_GLOBAL_PLEASE_WAIT, 0);

    srv_sms_change_msg_status(
        msg_id,
        status,
        mmi_sms_change_sms_read_unread_rsp,
        (void*)callback_func);
}


#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_unsent_status_callback
 * DESCRIPTION
 *  set unsent sms status callback function
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_change_unsent_sending_status_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback_data->result == MMI_FALSE)
	{
        mmi_sms_nmgr_display_popup(
            (UI_string_type) GetString(STR_GLOBAL_UNFINISHED),
            MMI_EVENT_FAILURE);
	}

    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);
    mmi_msg_update_unsent_icon();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_change_unsent_sending_status
 * DESCRIPTION
 *  Change Inbox SMS status request
 * PARAMETERS
 *  status      [IN]    the status of the SMS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_change_unsent_sending_status(U16 msg_id, srv_sms_send_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_set_and_entry_processing_sg(g_sms_gid, STR_GLOBAL_PLEASE_WAIT, 0);

    srv_sms_set_unsent_msg_status_ext(msg_id, status, mmi_sms_change_unsent_sending_status_callback, NULL);
}
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_move_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_move_msg_to_archive_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_result_enum action_result = SMS_RESULT_OK;
    SmsCBFuncPtr callback_func;
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callback_func = (SmsCBFuncPtr)callback_data->user_data;

    if (callback_data->result == MMI_FALSE)
    {
        if (callback_data->cause == SRV_SMS_CAUSE_MEM_FULL)
        {
            str_id = STR_SMS_ARCHIVE_MEMORY_EXCEEDED;
        }
        else if (callback_data->cause == SRV_SMS_CAUSE_FS_ERROR)
        {
            srv_sms_move_msg_to_archive_cb_struct *move_cb_data;
            S32 fs_error;

            move_cb_data = (srv_sms_move_msg_to_archive_cb_struct*)callback_data->action_data;

            fs_error = move_cb_data->fs_error;

            str_id = srv_fmgr_fs_error_get_string(fs_error);
        }
        else
        {
            str_id = STR_GLOBAL_UNFINISHED;

        }

        mmi_sms_display_popup_ext(
            str_id,
            MMI_EVENT_FAILURE);

        action_result = SMS_RESULT_ERROR;
    }

    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);

    if (callback_func != NULL)
    {
        callback_func(action_result, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_move_msg_to_archive
 * DESCRIPTION
 *  Move one message to archive
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_move_msg_to_archive(U16 msg_id, SmsCBFuncPtr callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__))
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
    }
    else
#endif /* (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)) */
    {
        mmi_sms_set_and_entry_processing_sg(g_sms_gid, STR_GLOBAL_MOVING, 0);

        srv_sms_move_msg_to_archive(
            msg_id,
            mmi_sms_move_msg_to_archive_rsp,
            (void*)callback_func);
    }
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#endif /*__MMI_TELEPHONY_SUPPORT__*/

