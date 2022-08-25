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
 *  SmsBtAppSendMsg.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Application Send SMS Flow handler
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_BT_MAP_CLIENT__

#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
#undef __MMI_MSG_EDITOR_WITH_RECIPIENT__
#endif
#ifdef __MMI_UNIFIED_COMPOSER__
#undef __MMI_UNIFIED_COMPOSER__
#endif

/**************************************************************
* Header Files Include
**************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"

#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "stdio.h"
#include "gui_data_types.h"
#include "string.h"
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_public_api.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "wgui_categories_util.h"
#include "fs_type.h"
#include "fs_func.h"
#include "ps_public_enum.h"
#include "MessagesMiscell.h"
#include "mmi_rp_app_sms_def.h"
#include "SmsAppType.h"
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
#include "mmi_rp_app_unifiedcomposer_def.h"
#endif
#include "UcSrvGprot.h"
#include "ImeGprot.h"
#include "MMI_trc_Int.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_history_gprot.h"
#include "SmsAppGProt.h"
#include "SmsAppProt.h"
#include "SmsAppUtil.h"
#include "PhonebookGprot.h"
#include "SmsCuiGprot.h"
#include "SmsSrvGprot.h"
#include "Ems.h"
#include "Wgui_ems.h"
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
#include "UcAppGprot.h"
#include "UcCuiGprot.h"
#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */
#include "SimCtrlSrvGProt.h"




/**************************************************
******* BT headers ********************************
**************************************************/

#include "SmsUmBtMapProt.h"
#include "SmsBtAppProt.h"
#include "SmsUmBtMapGProt.h"
#include "fseditorcuigprot.h"
#include "mmi_rp_app_smsbtunifiedmessage_def.h"  /*added for resources*/
#include "SmsBtMapCSrvGProt.h"
#include "SmsBtMapCSrvGProt.h"
#include "PhoneBookBtDailerGprot.h" 	/*Search phonebook*/
#include "PhoneBookBtDailer.h"			/*Search phonebook*/
#include "PhbCuiGprot.h"
/**************************************************************
* MARCO
**************************************************************/
#define INVALID_RECIPIENT_INDEX             0xFFFF

#define mmi_sms_bt_MAX_SENDING_CAPTION_LEN     120
#define mmi_sms_bt_MAX_COMFIRM_LEN             120
#define mmi_sms_bt_INVALID_INDEX   0xffff
extern MMI_ID  g_sms_bt_parent_gid;
extern SMS_HANDLE g_srv_sms_bt_send_handle;


/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    U16 total_num;
    S8 recipient[MMI_SMS_BT_MAX_RECIPIENTS_NUM][MMI_SMS_BT_MAX_ADDR_LEN + 1];
    U16 invalid_num;
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    mmi_sms_bt_address_type_enum addr_type;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    MMI_BOOL is_modify;
    MMI_BOOL is_hide_save_menu;
    U16 pre_total_num;
#if !defined(__MMI_UNIFIED_COMPOSER__) && defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__)
    U16 curr_index;
    WCHAR recipient_name[MMI_SMS_BT_MAX_RECIPIENTS_NUM][(MMI_SMS_BT_MAX_ADDR_LEN + 2)];
    MMI_BOOL is_recipient_map[MMI_SMS_BT_MAX_RECIPIENTS_NUM];
#endif /* !defined(__MMI_UNIFIED_COMPOSER__) && defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__) */
}mmi_sms_bt_add_recipient_struct;


typedef struct
{
    MMI_BOOL is_sent;    /* To Control the abort action */
    MMI_BOOL is_aborting;   /* To Control the Send action */
    U16 msg_index;
    mmi_sms_bt_send_case_enum send_case;
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    mmi_sms_bt_msg_type_enum send_type;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
}mmi_sms_bt_send_info_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/

extern MMI_ID editor_gid;
extern srv_sms_msg_data_struct* send_data;

U8 sms_bt_add_buff[((MMI_SMS_BT_MAX_ADDR_LEN + ENCODING_LENGTH) * ENCODING_LENGTH)];    ///TODO: Change to global pointer
MMI_ID phb_cui_id = NULL;


#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif
extern EMSTATUS EMSSetMsgClass(EMSData *emsData, kal_uint8 msg_class);
extern MMI_BOOL mmi_sms_bt_get_text_for_forward();

/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static mmi_sms_bt_add_recipient_struct recipient_data; 
static mmi_sms_bt_send_info_struct send_info_data;
mmi_id mmi_sms_bt_editor_send_parent_gid = GRP_ID_INVALID;
static mmi_id mmi_sms_bt_editor_send_child_gid = GRP_ID_INVALID;
static mmi_id mmi_sms_bt_api_send_parent_gid = GRP_ID_INVALID;
static mmi_id mmi_sms_bt_api_send_child_gid = GRP_ID_INVALID;
static MMI_BOOL is_hidden_add_recipient_scrn = MMI_TRUE;
static S8 *textBuffer ;

/**************************************************************
* Static Function Declaration
**************************************************************/
#ifdef __MMI_UNIFIED_COMPOSER__
static void mmi_sms_bt_entry_add_recipient(void);
#endif

static void mmi_sms_bt_entry_recipient_exceeded_confirm(U16 count, MMI_BOOL is_send);
static void mmi_sms_bt_recipient_exceeded_handle(void);
static void mmi_sms_bt_recipient_exceeded_confirm_go_back(void);
static void mmi_sms_bt_send_rsp_handler(srv_sms_callback_struct* data);
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

static mmi_ret mmi_sms_bt_send_msg_proc(mmi_event_struct *evt);
/*FM_SG*/
void mmi_sms_bt_get_recipient_from_send_cui(cui_evt_sms_send_struct *event);
static mmi_ret mmi_sms_bt_api_send_msg_proc(mmi_event_struct *evt);

#ifndef __MMI_UNIFIED_COMPOSER__    
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_pre_entry_add_recipient
 * DESCRIPTION
 *  Pre-Entry Add Recipient Screen Function
 * PARAMETERS
 *  is_external     [IN] Is from other application (TRUE) or SMS application (FALSE)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_pre_entry_add_recipient(MMI_BOOL is_hide_save_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_PRE_ENTRY_ADD_RECIPIENT, is_hide_save_menu);

    recipient_data.is_hide_save_menu = is_hide_save_menu;

#ifdef __EMS_DYNAMIC_SEG_NUM__
    if (!mmi_frm_scrn_is_present(g_sms_bt_gid ,SCR_ID_SMS_BT_EDITOR, MMI_FRM_NODE_ALL_FLAG))
    {
        if (srv_sms_set_cur_segment(g_sms_bt_cntx.edit_ems_data, SRV_SMS_BT_SIM_1) != EMS_OK)
        {
            mmi_popup_display_ext(
                STR_SMS_FAILURE_DATA_EXCEED,
                MMI_EVENT_FAILURE, NULL);
            return;
        }
    }
#endif /* __EMS_DYNAMIC_SEG_NUM__ */ 

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    if (recipient_data.addr_type == SMS_ADDR_TYPE_EMAIL_ADDR)
    {
        U16 remaining_len;
        MMI_BOOL is_enough_space = MMI_TRUE;

        remaining_len = cui_sms_get_ems_remaining_length(g_sms_bt_cntx.edit_ems_data);

        if (remaining_len <= 3)
        {
            is_enough_space = MMI_FALSE;
        }
        else
        {
            U16 i;

            for (i = 0; i < recipient_data.total_num; i++)
            {
                if ((U16)strlen(recipient_data.recipient[i]) > (remaining_len - 1))
                {
                    is_enough_space = MMI_FALSE;
                }
            }
        }

        if (is_enough_space == MMI_FALSE)
        {
            mmi_popup_display_ext(
                STR_SMS_EMAIL_NO_SPACE,
                MMI_EVENT_FAILURE, NULL);
            return;
        }
    }
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    is_hidden_add_recipient_scrn = MMI_FALSE;
#endif
    mmi_sms_bt_send_sms_dummy();
}
#endif /* __MMI_UNIFIED_COMPOSER__ */


#ifdef __MMI_UNIFIED_COMPOSER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_entry_add_recipient
 * DESCRIPTION
 *  Entry Add Recipient Screen Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_entry_add_recipient(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_hidden_add_recipient_scrn = MMI_FALSE;
    mmi_sms_bt_send_sms_dummy();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_entry_recipien_exceeded_confirm
 * DESCRIPTION
 *  Entry "Add Recipient" Options Screen Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_entry_recipient_exceeded_confirm(U16 count, MMI_BOOL is_send)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *confirm_str_buff;
    S8 asc_str[10];
    S8 ucs2_str[10 * ENCODING_LENGTH];
    U16 front_str_id;
    U16 last_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_entry_recipien_exceeded_confirm
 * DESCRIPTION
 *  Entry "Add Recipient" Options Screen Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_recipient_exceeded_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UNIFIED_COMPOSER__
    if (send_info_data.send_case == SMS_SEND_CASE_WRITE_FROM_OTHER_APP)
    {
        mmi_sms_bt_entry_editor();
    }
    else
#endif /* __MMI_UNIFIED_COMPOSER__ */
    if ((send_info_data.send_case == SMS_SEND_CASE_SEND_FROM_OTHER_APP) ||
        (send_info_data.send_case == SMS_SEND_CASE_SEND_DATA_MSG))
    {
    #ifdef __MMI_UNIFIED_COMPOSER__
        mmi_sms_bt_entry_add_recipient();
    #else /* __MMI_UNIFIED_COMPOSER__ */
        mmi_sms_bt_pre_entry_add_recipient(MMI_TRUE);
    #endif /* __MMI_UNIFIED_COMPOSER__ */
    }

    if (recipient_data.invalid_num > 0)
    {
        mmi_popup_display_ext(
            STR_ID_SMS_INVLAID_NUMBERS_REMOVED,
            MMI_EVENT_INFO, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_entry_recipien_exceeded_confirm
 * DESCRIPTION
 *  Entry "Add Recipient" Options Screen Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_recipient_exceeded_confirm_go_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 rollback_num = recipient_data.total_num - recipient_data.pre_total_num;
    U16 start_index = recipient_data.pre_total_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rollback_num > 0 && start_index < MMI_SMS_BT_MAX_RECIPIENTS_NUM)
    {
        if (rollback_num > (MMI_SMS_BT_MAX_RECIPIENTS_NUM - start_index))
        {
            rollback_num = MMI_SMS_BT_MAX_RECIPIENTS_NUM - start_index;
        }

        memset(
            recipient_data.recipient[start_index],
            0,
            (MMI_SMS_BT_MAX_ADDR_LEN + 1) * rollback_num);
        recipient_data.total_num = recipient_data.pre_total_num;
    }

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_append_recipient
 * DESCRIPTION
 *  Append Recipient to the Recipient List
 * PARAMETERS
 *  ucs2_addr       [IN]    UCS2 Address
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_bt_append_recipient(S8 *ucs2_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (recipient_data.total_num < MMI_SMS_BT_MAX_RECIPIENTS_NUM)
    {
        if (mmi_ucs2strlen(ucs2_addr) > 0)
        {
            S8 *ascii_addr = recipient_data.recipient[recipient_data.total_num];
            U16 addr_len;

            addr_len = mmi_ucs2_n_to_asc(ascii_addr, ucs2_addr, MMI_SMS_BT_MAX_ADDR_LEN * ENCODING_LENGTH);
            ascii_addr[addr_len] = '\0';

            recipient_data.total_num++;
            recipient_data.is_modify = MMI_TRUE;
        }

        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_reset_recipient_data
 * DESCRIPTION
 *  Reset the Add Recipient Data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_reset_recipient_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&recipient_data, 0, sizeof(mmi_sms_bt_add_recipient_struct));
#if !defined(__MMI_UNIFIED_COMPOSER__) && defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__)
    mmi_sms_bt_init_recipient_buffer();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_add_addr_list_to_recipient
 * DESCRIPTION
 *  Add the address list to the recipient list,
 *  and return the count of invalid address
 * PARAMETERS
 *  ucs2_addr_list  [IN]    Address List (UCS2 Format)
 *  addr_count      [IN]    The input address total number
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_sms_bt_add_addr_list_to_recipient(S8 **ucs2_addr_list, U16 addr_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 invalid_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ucs2_addr_list != NULL) && (addr_count > 0))
    {
        for (i = 0; i < addr_count; i++)
        {
            S8 *ucs2_addr = ucs2_addr_list[i];

            if (srv_sms_btmapc_check_ucs2_number((S8*)ucs2_addr) == MMI_FALSE)
            {
                invalid_num++;
            }
            else
            {
                if (mmi_sms_bt_append_recipient((S8*)ucs2_addr) == MMI_FALSE)
                {
                    break;
                }
            }
        }
    }

    return invalid_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_get_max_recipient_num
 * DESCRIPTION
 *  Get The SMS Max Recipient Number
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_sms_bt_get_max_recipient_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_SMS_BT_MAX_RECIPIENTS_NUM;
}



#ifdef __MMI_MESSAGES_SMS_EMAIL__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_get_preferred_msg_type
 * DESCRIPTION
 *  Get Preferred msg type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_sms_bt_msg_type_enum mmi_sms_bt_get_preferred_msg_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_bt_msg_type_enum preferred_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (recipient_data.total_num == 0)
    {
        preferred_type = SMS_MSG_TYPE_UNLIMITED;
    }
    else
    {
        if (recipient_data.addr_type == SMS_ADDR_TYPE_NUMBER)
        {
            preferred_type = SMS_MSG_TYPE_TEXT;
        }
        else
        {
            preferred_type = SMS_MSG_TYPE_EMAIL;
        }
    }

    return preferred_type;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_set_send_type
 * DESCRIPTION
 *  Set the send msg type
 * PARAMETERS
 *  send_type           [IN] the send msg type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_set_send_type(mmi_sms_bt_msg_type_enum send_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (send_type)
    {
        case SMS_MSG_TYPE_EMAIL:
            recipient_data.addr_type = SMS_ADDR_TYPE_EMAIL_ADDR;
            send_info_data.send_type = SMS_MSG_TYPE_EMAIL;
        break;

        case SMS_MSG_TYPE_UNLIMITED:
        case SMS_MSG_TYPE_TEXT:
        default:
            recipient_data.addr_type = SMS_ADDR_TYPE_NUMBER;
            send_info_data.send_type = SMS_MSG_TYPE_TEXT;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_get_send_type
 * DESCRIPTION
 *  Get the send msg type
 * PARAMETERS
 *  send_type           [IN] the send msg type
 * RETURNS
 *  void
 *****************************************************************************/
mmi_sms_bt_msg_type_enum mmi_sms_bt_get_send_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return send_info_data.send_type;
}
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_set_send_msg_case
 * DESCRIPTION
 *  set send message case state
 * PARAMETERS
 *  send_msg_case        [IN]  	send msg case      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_set_send_msg_case(mmi_sms_bt_send_case_enum send_msg_case)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	send_info_data.send_case = send_msg_case;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_send_msg_case
 * DESCRIPTION
 *  get send message case state
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_msg_send_case_enum
 *****************************************************************************/
mmi_sms_bt_send_case_enum mmi_sms_bt_get_send_msg_case(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return send_info_data.send_case;
}


/*
 *  Send Msg Begin
 */
#ifdef __MMI_DUAL_SIM_MASTER__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_get_is_sent
 * DESCRIPTION
 *  Check whether it is sending msg
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
*****************************************************************************/
MMI_BOOL mmi_sms_bt_get_is_sent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return send_info_data.is_sent;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_set_is_sent_false
 * DESCRIPTION
 *  Check whether it is sending msg
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
*****************************************************************************/
void mmi_sms_bt_set_is_sent_false(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_info_data.is_sent = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_set_is_sent_false
 * DESCRIPTION
 *  Check whether it is sending msg
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
*****************************************************************************/
void mmi_sms_bt_set_is_sent_true(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_info_data.is_sent = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_is_re_entry_send
 * DESCRIPTION
 *  Check Whether it is re-entry to Edit or Send Message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sms_bt_is_re_entry_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(g_sms_bt_gid, SCR_ID_SMS_BT_EDITOR, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG) ||
        (mmi_sms_bt_editor_send_child_gid != GRP_ID_INVALID))
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    // MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_IS_RE_ENTRY_SEND, send_info_data.is_sent, result);

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_entry_write_text_msg
 * DESCRIPTION
 *  Entry SMS Editor For Write a Text message
 * PARAMETERS
 *  ucs2_addr_list  [IN]    Address List (UCS2 Format)
 *  addr_count      [IN]    The input address total number
 *  ucs2_content    [IN]    The default UCS2 content will be input to the Editor 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_entry_write_text_msg(S8 **ucs2_addr_list, U16 addr_count, S8 *ucs2_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* will remove define W1021*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


#ifdef __MMI_DUAL_SIM_MASTER__
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
#else
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_send_text_msg
 * DESCRIPTION
 *  Send Text Message in the foreground;
 *  In this API, it will do error handling, and popup corresponding notification screen.
 * PARAMETERS
 *  ucs2_addr_list  :   [IN]    Address List, UCS2 Format
 *  addr_count      :   [IN]    The input address total number
 *  ucs2_content    :   [IN]    The default UCS2 content will be input to the Editor 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_send_text_msg(S8 **ucs2_addr_list, U16 addr_count, S8 *ucs2_content)
{
    /* will remove define W1021*/
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_entry_write_msg_from_phb
 * DESCRIPTION
 *  Entrt the SMS editor to write SMS from Phonebook
 * PARAMETERS
 *  addr_count          [IN]    address total number
 *  get_phb_num_func    [IN]    The function to get number from phonebook
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_entry_write_msg_from_phb(U16 addr_count, void *get_phb_num_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    mmi_uc_entry_write_struct* data = OslMalloc(sizeof(mmi_uc_entry_write_struct));
    U16 msg_index = SRV_SMS_INVALID_MSG_ID;
#endif /* __MMI_UNIFIED_COMPOSER__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    // MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_ENTRY_WRITE_MSG_FROM_PHB_UC, addr_count, get_phb_num_func);

    data = OslMalloc(sizeof(mmi_uc_entry_write_struct));

    data->addr_num = (U8)addr_count;
    data->addr = NULL;
    data->msg_type = MMI_UC_MSG_TYPE_SMS_ONLY;
    data->file_path = NULL;
    data->text_buffer = NULL;
    data->text_num = 0;
    data->subject = NULL;
    data->info_type = MMI_UC_INFO_TYPE_SMS;
    data->info = &msg_index;
    data->callback = NULL;
    data->callback_para = NULL;
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
    data->get_address_callback = (uc_func_ptr_general_insert_get_addr_fn)get_phb_num_func;

    cui_uc_write_msg_with_content_launch(GRP_ID_ROOT, MMI_UC_STATE_WRITE_NEW_MSG, data);

    OslMfree(data);
#else /* __MMI_UNIFIED_COMPOSER__ */
    // MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_ENTRY_WRITE_MSG_FROM_PHB, addr_count, get_phb_num_func);

    if (mmi_sms_bt_is_re_entry_send() == MMI_TRUE)
    {
        mmi_popup_display_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE, NULL);
    }
    else
    {
        U16 i;
        MMI_BOOL is_exist_invalid = MMI_FALSE;
        mmi_phb_send_address_to_others_callback_type get_num_cb_func;

        get_num_cb_func = (mmi_phb_send_address_to_others_callback_type)get_phb_num_func;

        mmi_sms_bt_reset_recipient_data();

        for (i = 0; i < addr_count; i++)
        {
            S8* phb_addr;
            U16 type;

            phb_addr = get_num_cb_func(i, &type);

            if (srv_sms_btmapc_check_ucs2_number(phb_addr) == MMI_FALSE)
            {
                if (is_exist_invalid == MMI_FALSE)
                {
                    is_exist_invalid = MMI_TRUE;
                }
            }
            else
            {
            #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
                if (mmi_sms_bt_add_recipient(NULL, phb_addr) == MMI_FALSE)                
            #else
                if (mmi_sms_bt_append_recipient(phb_addr) == MMI_FALSE)
            #endif
                {
                    break;
                }
            }
        }

        mmi_sms_bt_set_send_msg_case(SMS_SEND_CASE_WRITE_FROM_OTHER_APP);
    #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        mmi_sms_bt_set_send_type(SMS_MSG_TYPE_TEXT);
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */

        mmi_sms_bt_group_entry(GRP_ID_ROOT);
        mmi_sms_bt_entry_editor();

        if (is_exist_invalid == MMI_TRUE)
        {
            mmi_popup_display_ext(
                STR_ID_SMS_INVLAID_NUMBERS_REMOVED,
                MMI_EVENT_INFO, NULL);
        }
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_entry_write_msg
 * DESCRIPTION
 *  Entry Write or Send Message screen
 * PARAMETERS
 *  send_case       [IN]    Send Msg Case
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_entry_write_msg(mmi_sms_bt_send_case_enum send_case)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_ENTRY_WRITE_MSG_1, send_case);

    mmi_sms_bt_set_send_msg_case(send_case);


    if ((mmi_sms_bt_is_re_entry_send() == MMI_TRUE))
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE, NULL);
    }
    else
    {
        U16 msg_index = SRV_SMS_INVALID_MSG_ID;
        MMI_BOOL is_add_num = MMI_FALSE;
        MMI_BOOL is_entry_editor = MMI_TRUE;
        MMI_BOOL is_entry_recipient = MMI_TRUE;
        MMI_BOOL is_reset_edit_data = MMI_TRUE;
        MMI_BOOL is_reset_recipient_data = MMI_TRUE;
#ifdef __MMI_MESSAGES_SMS_EMAIL__
        mmi_sms_bt_msg_type_enum send_msg_type = SMS_MSG_TYPE_TEXT;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

        switch (send_case)
        {
            case SMS_BT_SEND_CASE_EDIT_DRAFT:
            case SMS_BT_SEND_CASE_EDIT_UNSENT:
            case SMS_BT_SEND_CASE_RESEND:
            case SMS_BT_SEND_CASE_SEND_DRAFT:
            case SMS_BT_SEND_CASE_FORWARD:
            {
                U8 result;
               // textBuffer = srv_sms_btmapc_get_msg_content(g_sms_bt_cntx.curr_msg_id);
				srv_sms_msg_data_struct *msg_data_forward = mmi_sms_bt_get_msg_data_for_forward();
				is_reset_edit_data = MMI_FALSE;

                /* copy view content to edit buffer maybe fail due to EMS LIB virtual pack fail */
                if (msg_data_forward == NULL)
                {
                    mmi_popup_display_ext(
                        STR_SMS_FAILURE_MSG_LEN_EXCEEDED,
                        MMI_EVENT_FAILURE, NULL);
                    return;
                }
                else
                {
                    switch (send_case)
                    {
                       
                        case SMS_BT_SEND_CASE_RESEND:
                            msg_index = g_sms_cntx.curr_msg_id;
                            is_add_num = MMI_TRUE;
                        #ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
                            is_entry_editor = MMI_FALSE;
                        #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
                            break;

                        case SMS_BT_SEND_CASE_SEND_DRAFT:
                            msg_index = g_sms_cntx.curr_msg_id;
                            is_add_num = MMI_TRUE;
                        #ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__                            
                            is_entry_editor = MMI_FALSE;
                        #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
                            break;

                        case SMS_BT_SEND_CASE_FORWARD:
                            break;

                        default:
                            MMI_ASSERT(0);
                            break;
                    }
                }
                break;
            }

            case SMS_BT_SEND_CASE_REPLY:
            {
                msg_index = g_sms_bt_cntx.curr_msg_id;
                is_add_num = MMI_TRUE;
                break;
            }

            case SMS_BT_SEND_CASE_WRITE_NEW_MSG:
            {
                break;
            }

            default:
            {
                is_reset_edit_data = MMI_FALSE;
                is_reset_recipient_data = MMI_FALSE;
                break;
            }
        }

        send_info_data.msg_index = msg_index;

        if (is_reset_edit_data == MMI_TRUE)
        {
         
        }

        if (is_reset_recipient_data == MMI_TRUE)
        {
            mmi_sms_bt_reset_recipient_data();
        }

        if ((is_add_num == MMI_TRUE) && (msg_index != SRV_SMS_INVALID_MSG_ID))
        {

            {
                S8 ucs2_addr[(MMI_SMS_BT_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];

                srv_sms_btmapc_get_msg_address(msg_index, ucs2_addr);

                if ((ucs2_addr[0] != '\0') || (ucs2_addr[1] != '\0'))
                {
                #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
                    if (srv_sms_btmapc_check_ucs2_number(ucs2_addr) == MMI_FALSE)
                    {
                        mmi_popup_display_ext(
                            STR_ID_SMS_INVLAID_NUMBERS_REMOVED,
                            MMI_EVENT_INFO, NULL); 
                    }
                    else
                    {
                        mmi_sms_bt_add_recipient(NULL, (S8 *)ucs2_addr);
                    }
                #else
                    mmi_sms_bt_append_recipient(ucs2_addr);
                #endif

                    if (send_case == SMS_SEND_CASE_RESEND)
                    {
                        is_entry_recipient = MMI_FALSE;
                    }
                }
            }
        }
    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        else
        {
            is_entry_editor = TRUE;
        }
    #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

    #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        mmi_sms_bt_set_send_type(send_msg_type);
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */

        if (is_entry_editor == MMI_TRUE)
        {
            mmi_sms_bt_entry_editor();
        }
        else if (is_entry_recipient == MMI_TRUE)
        {
            mmi_sms_bt_pre_entry_add_recipient(MMI_TRUE);
        }
        else
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
        #else /* __MMI_DUAL_SIM_MASTER__ */
            mmi_sms_bt_send_sms_dummy();
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        }
    }

}


#if defined(__MMI_MMS_STANDALONE_COMPOSER__) || defined(__MMI_UNIFIED_COMPOSER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_send_mms
 * DESCRIPTION
 *  send one mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_send_one_mms(
                S8 *ucs2_addr
            #if (MMI_MAX_SIM_NUM >= 2)
                , srv_sms_sim_enum sim_id
            #endif /* (MMI_MAX_SIM_NUM >= 2) */
            #ifdef __MMI_MESSAGES_SMS_EMAIL__
                , mmi_sms_bt_address_type_enum addr_type
            #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
                )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_entry_write_struct* data = OslMalloc(sizeof(mmi_uc_entry_write_struct));
    mmi_uc_addr_struct *addr_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset (data, 0 , sizeof(mmi_uc_entry_write_struct));

    if (mmi_ucs2strlen(ucs2_addr) > 0)
    {
        addr_node = OslMalloc(sizeof(mmi_uc_addr_struct));
        addr_node->addr = (U8*)ucs2_addr;
    
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        if (addr_type == SMS_ADDR_TYPE_EMAIL_ADDR)
        {
            addr_node->type = MMI_UC_ADDRESS_TYPE_EMAIL;
        }
        else
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
        {
            addr_node->type = MMI_UC_ADDRESS_TYPE_PHONE_NUMBER;
        }

        addr_node->group = MMI_UC_ADDRESS_GROUP_TYPE_TO;
        addr_node->next = NULL;
        data->addr = addr_node;
        data->addr_num = 1;
    }
    else
    {
        data->addr = NULL;
        data->addr_num = 0;
    }

    data->msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
    data->file_path = NULL;
    data->text_buffer = NULL;
    data->text_num = 0;
    data->subject = NULL;
    data->info_type = MMI_UC_INFO_TYPE_MMS;
    data->info = NULL;
#if (MMI_MAX_SIM_NUM >= 2)
   // data->sim_id = mmi_sms_bt_sim_id_to_uc_sim(sim_id);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    cui_uc_write_msg_with_content_launch(g_sms_parent_gid, MMI_UC_STATE_WRITE_NEW_MSG, data);

    if (addr_node != NULL)
    {
        OslMfree(addr_node);
    }

    OslMfree(data);
}
#endif /* defined(__MMI_MMS_STANDALONE_COMPOSER__) && !defined(__MMI_UNIFIED_COMPOSER__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_is_allow_send_sms
 * DESCRIPTION
 *  Check Whether allow to send SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_bt_is_allow_send_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_sms_bt_is_re_entry_send() == MMI_TRUE))
    {
        result = MMI_FALSE;
    }
    else
    {
        result = MMI_TRUE;
    }

    return result;
}


srv_sms_sim_enum mmi_sms_bt_convert_mmi_sim_to_srv_sim(mmi_sms_bt_sim_enum sms_sim_id)
{
    srv_sms_sim_enum srv_sim_id = SRV_SMS_SIM_1;
     switch(sms_sim_id)
     {
     case  SMS_BT_SIM_1:
     srv_sim_id = SRV_SMS_SIM_1;
     break;
     
     case  SMS_BT_SIM_2:
      srv_sim_id = SRV_SMS_SIM_2;
       break;
       
     case SMS_BT_SIM_3:
      srv_sim_id = SRV_SMS_SIM_3;
       break;
       
     case SMS_BT_SIM_4:
      srv_sim_id = SRV_SMS_SIM_4;
       break;
       
     case SMS_BT_SIM_TOTAL:
     case SMS_BT_SIM_UNSPECIFIC:
      srv_sim_id = SRV_SMS_SIM_TOTAL;
      break;
      
      default:
      srv_sim_id = SRV_SMS_SIM_TOTAL;
      break;
     }
    return  srv_sim_id;
}

void mmi_sms_bt_send_sms_dummy()
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_bt_editor_send_parent_gid = mmi_frm_group_create_ex(
        g_sms_bt_gid,   /********** using  bt global *****************/
        GRP_ID_AUTO_GEN,
        mmi_sms_bt_send_msg_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
	
	kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_editor_send_parent_gid = %d", mmi_sms_bt_editor_send_parent_gid);

   // mmi_sms_bt_editor_send_child_gid = cui_sms_send_create(mmi_sms_bt_editor_send_parent_gid);
   if (recipient_data.total_num > 0)
   {
	   U16 ucs2_addr[MMI_SMS_BT_MAX_ADDR_LEN + 1] = {0,};
	   U16 addr_len;
	   U16 i;
	   SMS_HANDLE srv_sms_bt_send_handle ;
	   EMSData *ems_data;
	 
	   if (recipient_data.total_num > MMI_SMS_BT_MAX_RECIPIENTS_NUM)
	   {
		   recipient_data.total_num = MMI_SMS_BT_MAX_RECIPIENTS_NUM;
	   }
   
	   for (i = 0; i < recipient_data.total_num; i++)
	   {
		 
		 			mmi_asc_n_to_ucs2((S8*)ucs2_addr, recipient_data.recipient[i], CUI_SMS_MAX_ADDR_LEN);
           }

	  		cui_sms_bt_send_edit_phone_number(mmi_sms_bt_editor_send_parent_gid, ucs2_addr);
	   
   }
   else
   	{
   		cui_sms_bt_send_edit_phone_number(mmi_sms_bt_editor_send_parent_gid, NULL);
   	}

}
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_send_sms
 * DESCRIPTION
 *  Check Whether allow to send SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
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
    #ifndef __ULC_SLIM_EMS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else /* __ULC_SLIM_EMS__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __ULC_SLIM_EMS__ */
/* under construction !*/
   #if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
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
#if (defined(__OP01__) && (MMI_MAX_SIM_NUM >= 2))
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
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
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


static void mmi_sms_bt_send_rsp_handler(srv_sms_callback_struct* data)
{
   
	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_MSG_SEND_GET_SEND_RSP, data->result);
	if(data->result == MMI_TRUE)
		mmi_display_popup(GetString(STR_GLOBAL_SENT), MMI_EVENT_SUCCESS);
	else if(data->result == MMI_FALSE)
		mmi_display_popup(GetString(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE);
	else
		MMI_ASSERT(0);

    if(g_srv_sms_bt_send_handle != NULL)
    {
        srv_sms_btmapc_free_send_handle(g_srv_sms_bt_send_handle);
        g_srv_sms_bt_send_handle = NULL;
    }
	mmi_frm_group_close(g_sms_bt_gid);
	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_MSG_SEND_CLOSE_PROGRESS_SCREEN);
	g_sms_bt_gid = GRP_ID_INVALID;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/

static void mmi_sms_bt_set_box_rsp_handler(srv_sms_callback_struct* data)
{
	SMS_HANDLE srv_sms_bt_send_handle ;
	EMSData *ems_data;
    
	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_MSG_SEND_GET_LIST_RSP, data->result);
	if(data->result == MMI_TRUE)
		{	 g_srv_sms_bt_send_handle = srv_sms_btmapc_get_send_handle();
			 srv_sms_btmapc_set_address(g_srv_sms_bt_send_handle, sms_bt_add_buff);
		     kal_prompt_trace(MOD_MMI, "Akhil, srv_sms_btmapc_set_address = %s",sms_bt_add_buff);
			 kal_prompt_trace(MOD_MMI, "Akhil, srv_sms_bt_send_handle = %s", g_srv_sms_bt_send_handle);
			 srv_sms_btmapc_set_send_type(g_srv_sms_bt_send_handle, SRV_SMS_FG_SEND);
             
			 srv_sms_btmapc_set_content(g_srv_sms_bt_send_handle, send_data->content_buff, send_data->content_buff_size);
			 srv_sms_btmapc_send_msg(g_srv_sms_bt_send_handle,mmi_sms_bt_send_rsp_handler,NULL);
		}
	else
	{
		mmi_display_popup(GetString(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE);
		mmi_frm_group_close(g_sms_bt_gid);
		g_sms_bt_gid = GRP_ID_INVALID;
		return;
	}
}
//3 Phonebook search
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_search_phonebook
 * DESCRIPTION
 *  Entry Phonebook List to Search Address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_search_phonebook(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 filter_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_prompt_trace(MOD_MMI, "[Ashish], mmi_sms_bt_search_phonebook():");
	kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_editor_send_parent_gid = %d", mmi_sms_bt_editor_send_parent_gid);

    MMI_ASSERT(sms_bt_add_buff != NULL);
#ifdef __MMI_BT_PBAP_CLIENT__
    kal_prompt_trace(MOD_MMI, "[Ashish], mmi_sms_bt_search_phonebook()_2:");
    phb_cui_id = cui_phb_pbapc_select_contact_create(parent_gid);

    if (phb_cui_id != GRP_ID_INVALID)
    {
        cui_phb_pbapc_select_contact_run(phb_cui_id);
    }
	else		
		kal_prompt_trace(MOD_MMI, "[Ashish], mmi_sms_bt_search_phonebook(): Phonebook Cui not created !!!");
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_get_sc_addr_from_phb
 * DESCRIPTION
 *  Get Phonebook Number Callback function
 * PARAMETERS
 *  name        [IN]        Name
 *  number      [IN]        Number in Ucs2
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_get_sc_addr_from_phb(mmi_id parent_gid, S8* name, S8* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8* number_ascii[(MMI_SMS_BT_MAX_ADDR_LEN + ENCODING_LENGTH) * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_prompt_trace(MOD_MMI, "[Ashish], mmi_sms_bt_get_sc_addr_from_phb():");
	kal_prompt_trace(MOD_MMI, "[Ashish], parent_gid:%d, name:%s, unicoded number:%s ", parent_gid, name, number);

    MMI_ASSERT(sms_bt_add_buff != NULL);

    /*if (cui_sms_is_valid_address(number, edit_num_info->phone_number_addr_type) == MMI_FALSE)
    {
        U16 string_id;

        switch (edit_num_info->phone_number_addr_type)
        {
            case CUI_SMS_ADDR_TYPE_NUMBER:
            default:
                string_id = STR_GLOBAL_INVALID_NUMBER;
                break;
        }
        mmi_popup_display_simple_ext(
            string_id,
            MMI_EVENT_FAILURE,
            sms_send_gid,
            NULL);
    }
    else*/
    {
        U32 max_char_num;
        mmi_ucs2cpy((S8*)sms_bt_add_buff, (S8*)number);
		
		mmi_ucs2_n_to_asc((CHAR *) number_ascii, (CHAR *) sms_bt_add_buff, MMI_SMS_BT_MAX_ADDR_LEN * ENCODING_LENGTH);
		kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_get_sc_addr_from_phb ASCII no no:%s", number_ascii);

		max_char_num = MMI_SMS_BT_MAX_ADDR_LEN;//edit_num_info->phone_number_max_addr_len;
        cui_fseditor_set_text(editor_gid, (WCHAR*)sms_bt_add_buff, max_char_num * ENCODING_LENGTH, max_char_num);
    }
}

extern mmi_sms_bt_cntx_struct *g_sms_bt_ui_p;
extern srv_sms_btmapc_bt_enum	g_sms_active_dev_index;	   /* Bt index ID */
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_send_msg_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static mmi_ret mmi_sms_bt_send_msg_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cui_evt_sms_send_struct *event = (cui_evt_sms_send_struct*)evt;
    
#ifdef __MMI_BT_PBAP_CLIENT__
	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "[SMS]mmi_sms_bt_send_msg_proc  evt->evt_id=%d\n",evt->evt_id); 
#endif	
    switch (evt->evt_id)
    {
    	case EVT_ID_CUI_FSEDITOR_SUBMIT:
			 kal_prompt_trace(MOD_MMI, "[Akhil], into fseditor submit");
			 kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_editor_send_parent_gid = %d", mmi_sms_bt_editor_send_parent_gid);
			 cui_fseditor_get_text(editor_gid, (WCHAR*)sms_bt_add_buff, (MMI_SMS_BT_MAX_ADDR_LEN * ENCODING_LENGTH));
			 kal_prompt_trace(MOD_MMI, "[Akhil],sender number buffer = %s",sms_bt_add_buff );
			if(mmi_ucs2strlen((const S8*)sms_bt_add_buff) > 0)
			{
				 mmi_sms_bt_set_and_entry_processing_sg(g_sms_bt_gid, STR_GLOBAL_SENDING, 0);
                                 srv_sms_btmapc_get_msg_list_by_tab(g_sms_active_dev_index, MMI_TRUE, SRV_SMS_BTMAPC_BOX_UNSENT,mmi_sms_bt_set_box_rsp_handler, NULL);                           
				 MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_MSG_SEND_GET_LIST_REQ);
			}
			else //Search phonebook
			{
				mmi_sms_bt_search_phonebook(mmi_sms_bt_editor_send_parent_gid);
			}
			break;
#ifdef __MMI_BT_PBAP_CLIENT__            
	    case EVT_ID_PHB_PBAPC_SEL_CONTACT:
        {
            S8* number_ucs[(MMI_SMS_BT_MAX_ADDR_LEN + ENCODING_LENGTH) * ENCODING_LENGTH];
		    cui_phb_pbapc_select_contact_rsp_struct *select_result = (cui_phb_pbapc_select_contact_rsp_struct *) evt;
            if (MMI_PHB_PBAPC_SEL_REQ_CLOSE == select_result->rsp_type)
            {
                cui_phb_pbapc_select_contact_close(phb_cui_id);
            }
            else
            {
                cui_phb_pbapc_select_contact_ret_struct *select_ret_result = (cui_phb_pbapc_select_contact_ret_struct*)select_result->rsp;
                if (MMI_PHB_PBAPC_SEL_RET_OK == select_ret_result->ret)
                {
                    mmi_sms_bt_get_sc_addr_from_phb(
				        mmi_sms_bt_editor_send_parent_gid,
				        (S8*)select_ret_result->name,
				        (S8*)select_ret_result->number);
                }
            }
            cui_phb_pbapc_select_contact_close(phb_cui_id);
            break;
        }
#endif		   
		//FS editor events
		case EVT_ID_CUI_FSEDITOR_ABORT:
			cui_fseditor_close(editor_gid);
			break;

		case EVT_ID_CUI_FSEDITOR_NOT_EMPTY:
			cui_fseditor_set_softkey_text(editor_gid, MMI_LEFT_SOFTKEY, STR_GLOBAL_SEND);
			break;

		case EVT_ID_CUI_FSEDITOR_EMPTY:
			cui_fseditor_set_softkey_text(editor_gid, MMI_LEFT_SOFTKEY, STR_GLOBAL_SEARCH);
			break;
			 
        case EVT_ID_GROUP_DEINIT:
            /* need addd code to release buffer */
            mmi_sms_bt_editor_send_child_gid = GRP_ID_INVALID;
            mmi_sms_bt_editor_send_parent_gid = GRP_ID_INVALID;
		
            break;

        case EVT_ID_CUI_SMS_SEND:
            {
              
                if (event->is_send_finish)
                {
                    if (event->cur_send_result == CUI_SMS_RESULT_GROUP_GOBACK)
                    {
                        mmi_sms_bt_get_recipient_from_send_cui(event);
                    }
                    else
                    {
                        if (event->cur_send_result != CUI_SMS_RESULT_CANCEL)
                        {	
                            mmi_sms_bt_set_is_sent_true();
                            mmi_frm_group_close(g_sms_bt_gid);

                            
                            mmi_sms_bt_reset_recipient_data();
                        }
                    }

                    cui_sms_send_close(event->send_gid);
                    mmi_frm_group_close(event->parent_gid);
                }
            }
            break;
        case EVT_ID_CUI_SMS_SEND_START_SAVING:
            {
                mmi_sms_bt_set_is_sent_true();
                break;
            }

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_send_msg_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_sms_bt_get_recipient_from_send_cui(cui_evt_sms_send_struct *event)/*FM_SG*/
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 addr_count = 0;
    U16 addr_list[CUI_SMS_MAX_RECIPIENTS_NUM][CUI_SMS_MAX_ADDR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_sms_get_send_address(mmi_sms_bt_editor_send_child_gid, (U16**)addr_list, &addr_count);

    recipient_data.total_num = addr_count;

    for (i = 0; i < addr_count; i++)
    {
        U16 addr_len;
        addr_len = mmi_ucs2_n_to_asc(recipient_data.recipient[i], (S8*)addr_list[i],(CUI_SMS_MAX_ADDR_LEN *ENCODING_LENGTH));

        if (addr_len > CUI_SMS_MAX_ADDR_LEN)
        {
            addr_len = CUI_SMS_MAX_ADDR_LEN;
        }

        recipient_data.recipient[i][addr_len] = '\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_set_is_recipient_modify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_sms_bt_set_is_recipient_modify(MMI_BOOL set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    recipient_data.is_modify = set;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_write_msg_lanch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_sms_bt_write_msg_lanch(mmi_id parent_gid, mmi_sms_bt_write_msg_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  		 mmi_sms_bt_write_msg_para_struct *data = para;
		 strcpy((CHAR *) &recipient_data.recipient[0], (CHAR*)data->ascii_addr);
	         recipient_data.total_num++;
                 mmi_sms_bt_group_entry(GRP_ID_ROOT);
                 mmi_sms_bt_entry_editor();


}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_api_send_msg_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static mmi_ret mmi_sms_bt_api_send_msg_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
        case EVT_ID_GROUP_INACTIVE:
            break;

        case EVT_ID_GROUP_DEINIT:
            /* need addd code to release buffer */
            if ((S8*)evt->user_data != NULL)
            {
                OslMfree((S8*)evt->user_data);
            }
            mmi_sms_bt_api_send_child_gid = GRP_ID_INVALID;
            mmi_sms_bt_api_send_parent_gid = GRP_ID_INVALID;
            break;

        case EVT_ID_CUI_SMS_SEND:
            {
                cui_evt_sms_send_struct *event = (cui_evt_sms_send_struct*)evt;
                if (event->is_send_finish)
                {
                    cui_sms_send_close(mmi_sms_bt_api_send_child_gid);
                    mmi_frm_group_close(mmi_sms_bt_api_send_parent_gid);
                }
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_api_send_result_handler
 * DESCRIPTION
 *  Handler for applications to process post SMS request actions, such as
 *  display result popup, delete SMS framework screens, and enable SPOF
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_api_send_result_handler(mmi_sms_bt_api_result_handler_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID title;
    mmi_event_notify_enum event_id = MMI_EVENT_FAILURE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* MMI_TRACE(
        MMI_COMMON_TRC_G6_MSG,
        TRC_FRM_SMS_API_RESULT_HANDLER,
        result->display_popup,
        result->request_type,
        result->result,
        result->delete_sms_screen);
*/
    if (result->display_popup)
    {
        switch (result->result)
        {
            case SRV_SMS_CAUSE_NO_ERROR:
                if (result->request_type == MMI_SMS_BT_REQ_SEND)
                {
                    title = STR_GLOBAL_SENT;
                    event_id = MMI_EVENT_MESSAGE_SENT;
                }
                else if (result->request_type == MMI_SMS_BT_REQ_SAVE)
                {
                    title = STR_GLOBAL_SAVED;
                    event_id = MMI_EVENT_EXPLICITLY_SAVED;
                }
                else
                {
                    title = STR_GLOBAL_DONE;
                    event_id = MMI_EVENT_SUCCESS;
                }
                break;

            case SRV_SMS_CAUSE_SEND_ABORT:
                title = STR_ID_SMS_CANCELLED;
                event_id = MMI_EVENT_SUCCESS;
                break;
  
            case SRV_SMS_CAUSE_NOT_READY:
                title = STR_SMS_MSG_NOT_READY_YET;
                break;

            case SRV_SMS_CAUSE_NUMBER_INVALID:
                title = STR_GLOBAL_INVALID_NUMBER;
                break;

            case SRV_SMS_CAUSE_DATA_INVALID:
                title = STR_SMS_FAILURE_DATA_INVALID;
                break;

            case SRV_SMS_CAUSE_DATA_EXCEED:
                title = STR_SMS_FAILURE_DATA_EXCEED;
                break;

            case SRV_SMS_CAUSE_SC_EMPTY:
                title = STR_SMS_FAILURE_SC_NUM_EMPTY;
                break;


            case SRV_SMS_CAUSE_MEM_FULL:
                title = STR_GLOBAL_MEMORY_FULL;
                break;

            case SRV_SMS_CAUSE_MEM_INSUFFICIENT:
                title = STR_GLOBAL_NOT_ENOUGH_MEMORY;
                break;
            case SRV_SMS_CAUSE_ERROR_FDN_ENABLED:
                title = STR_ID_SMS_FDN_FAIL;
                break;
            default:
                if (result->request_type == MMI_SMS_BT_REQ_SEND)
                {
                    title = STR_GLOBAL_FAILED_TO_SAVE;             
                }
                else
                {
                    title = STR_GLOBAL_FAILED_TO_SEND; 
                }
                break;
        }

        mmi_popup_display_ext(
            title,
            event_id, NULL);     
    }
}

MMI_BOOL mmi_sms_bt_get_text_for_forward()
{
	if(textBuffer == NULL)
		return MMI_FALSE;
	else
	{
		textBuffer = NULL;
		return MMI_TRUE;
	}
}

#endif


