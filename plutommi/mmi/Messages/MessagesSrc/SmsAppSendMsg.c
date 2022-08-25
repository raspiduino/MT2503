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
 *  SmsAppSendMsg.c
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

//#ifdef __MMI_TELEPHONY_SUPPORT__



/**************************************************************
* MARCO
**************************************************************/
#define INVALID_RECIPIENT_INDEX             0xFFFF

#define MMI_SMS_MAX_SENDING_CAPTION_LEN     120
#define MMI_SMS_MAX_COMFIRM_LEN             120
#define MMI_SMS_INVALID_INDEX   0xffff


/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    U16 total_num;
    S8 recipient[CUI_SMS_MAX_RECIPIENTS_NUM][CUI_SMS_MAX_ADDR_LEN + 1];
    U16 invalid_num;
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    mmi_sms_address_type_enum addr_type;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    MMI_BOOL is_modify;
    MMI_BOOL is_hide_save_menu;
    U16 pre_total_num;
#if !defined(__MMI_UNIFIED_COMPOSER__) && defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__)
    U16 curr_index;
    WCHAR recipient_name[CUI_SMS_MAX_RECIPIENTS_NUM][(CUI_SMS_MAX_ADDR_LEN + 2)];
    MMI_BOOL is_recipient_map[CUI_SMS_MAX_RECIPIENTS_NUM];
#endif /* !defined(__MMI_UNIFIED_COMPOSER__) && defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__) */
}mmi_sms_add_recipient_struct;


typedef struct
{
    MMI_BOOL is_sent;    /* To Control the abort action */
    MMI_BOOL is_aborting;   /* To Control the Send action */
    U16 msg_index;
    mmi_sms_send_case_enum send_case;
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    mmi_sms_msg_type_enum send_type;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
}mmi_sms_send_info_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif
extern EMSData *GetEMSDataForEdit(EMSData **p, U8 force);
extern EMSData *GetEMSDataForView(EMSData **p, U8 force);
extern EMSTATUS EMSSetMsgClass(EMSData *emsData, kal_uint8 msg_class);


/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static mmi_sms_add_recipient_struct recipient_data; 
static mmi_sms_send_info_struct send_info_data;
static mmi_id mmi_sms_editor_send_parent_gid = GRP_ID_INVALID;
static mmi_id mmi_sms_editor_send_child_gid = GRP_ID_INVALID;
static mmi_id mmi_sms_api_send_parent_gid = GRP_ID_INVALID;
static mmi_id mmi_sms_api_send_child_gid = GRP_ID_INVALID;
static MMI_BOOL is_hidden_add_recipient_scrn = MMI_TRUE;


/**************************************************************
* Static Function Declaration
**************************************************************/
#ifdef __MMI_UNIFIED_COMPOSER__
static void mmi_sms_entry_add_recipient(void);
#endif

static void mmi_sms_entry_recipient_exceeded_confirm(U16 count, MMI_BOOL is_send);
static void mmi_sms_recipient_exceeded_handle(void);
static void mmi_sms_recipient_exceeded_confirm_go_back(void);

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

static mmi_ret mmi_sms_send_msg_proc(mmi_event_struct *evt);
/*FM_SG*/
void mmi_sms_get_recipient_from_send_cui(cui_evt_sms_send_struct *event);
static mmi_ret mmi_sms_api_send_msg_proc(mmi_event_struct *evt);

#ifndef __MMI_UNIFIED_COMPOSER__    
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_pre_entry_add_recipient
 * DESCRIPTION
 *  Pre-Entry Add Recipient Screen Function
 * PARAMETERS
 *  is_external     [IN] Is from other application (TRUE) or SMS application (FALSE)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_pre_entry_add_recipient(MMI_BOOL is_hide_save_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_PRE_ENTRY_ADD_RECIPIENT, is_hide_save_menu);

    recipient_data.is_hide_save_menu = is_hide_save_menu;

#ifdef __EMS_DYNAMIC_SEG_NUM__
    if (!mmi_frm_scrn_is_present(g_sms_gid ,SCR_ID_SMS_EDITOR, MMI_FRM_NODE_ALL_FLAG))
    {
        if (srv_sms_set_cur_segment(g_sms_cntx.edit_ems_data, SRV_SMS_SIM_1) != EMS_OK)
        {
            mmi_sms_display_popup_ext(
                STR_SMS_FAILURE_DATA_EXCEED,
                MMI_EVENT_FAILURE);
            return;
        }
    }
#endif /* __EMS_DYNAMIC_SEG_NUM__ */ 

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    if (recipient_data.addr_type == SMS_ADDR_TYPE_EMAIL_ADDR)
    {
        U16 remaining_len;
        MMI_BOOL is_enough_space = MMI_TRUE;

        remaining_len = cui_sms_get_ems_remaining_length(g_sms_cntx.edit_ems_data);

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
            mmi_sms_display_popup_ext(
                STR_SMS_EMAIL_NO_SPACE,
                MMI_EVENT_FAILURE);
            return;
        }
    }
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    is_hidden_add_recipient_scrn = MMI_FALSE;
#endif
    mmi_sms_send_sms();
}
#endif /* __MMI_UNIFIED_COMPOSER__ */


#ifdef __MMI_UNIFIED_COMPOSER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_add_recipient
 * DESCRIPTION
 *  Entry Add Recipient Screen Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_entry_add_recipient(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_hidden_add_recipient_scrn = MMI_FALSE;
    mmi_sms_send_sms();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_recipien_exceeded_confirm
 * DESCRIPTION
 *  Entry "Add Recipient" Options Screen Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_entry_recipient_exceeded_confirm(U16 count, MMI_BOOL is_send)
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
    confirm_str_buff = OslMalloc(MMI_SMS_MAX_COMFIRM_LEN * ENCODING_LENGTH);

    if (is_send == MMI_TRUE)
    {
        front_str_id = STR_ID_SMS_CAN_ONLY_SEND_TO_FIRST;
    }
    else
    {
        front_str_id = STR_ID_SMS_CAN_ONLY_ADD_FIRST;
    }

    mmi_ucs2cpy(confirm_str_buff, (S8*)GetString(front_str_id));

    sprintf(asc_str, "%d", count);
    mmi_asc_to_ucs2(ucs2_str, asc_str);

    mmi_ucs2cat(confirm_str_buff, ucs2_str);

    if (count == 1)
    {
        last_str_id = STR_ID_SMS_CONTACT_CONTINUE_QUERY;
    }
    else
    {
        last_str_id = STR_ID_SMS_CONTACTS_CONTINUE_QUERY;
    }

    mmi_ucs2cat(confirm_str_buff, (S8*)GetString(last_str_id));

    mmi_sms_entry_confirm_sg_ext(
        g_sms_gid,
        (WCHAR*) confirm_str_buff,
        mmi_sms_recipient_exceeded_handle,
        mmi_sms_recipient_exceeded_confirm_go_back);

    OslMfree(confirm_str_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_recipien_exceeded_confirm
 * DESCRIPTION
 *  Entry "Add Recipient" Options Screen Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_recipient_exceeded_handle(void)
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
        mmi_sms_pre_entry_editor();
    }
    else
#endif /* __MMI_UNIFIED_COMPOSER__ */
    if ((send_info_data.send_case == SMS_SEND_CASE_SEND_FROM_OTHER_APP) ||
        (send_info_data.send_case == SMS_SEND_CASE_SEND_DATA_MSG))
    {
    #ifdef __MMI_UNIFIED_COMPOSER__
        mmi_sms_entry_add_recipient();
    #else /* __MMI_UNIFIED_COMPOSER__ */
        mmi_sms_pre_entry_add_recipient(MMI_TRUE);
    #endif /* __MMI_UNIFIED_COMPOSER__ */
    }

    if (recipient_data.invalid_num > 0)
    {
        mmi_sms_display_popup_ext(
            STR_ID_SMS_INVLAID_NUMBERS_REMOVED,
            MMI_EVENT_INFO);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_recipien_exceeded_confirm
 * DESCRIPTION
 *  Entry "Add Recipient" Options Screen Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_recipient_exceeded_confirm_go_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 rollback_num = recipient_data.total_num - recipient_data.pre_total_num;
    U16 start_index = recipient_data.pre_total_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rollback_num > 0 && start_index < CUI_SMS_MAX_RECIPIENTS_NUM)
    {
        if (rollback_num > (CUI_SMS_MAX_RECIPIENTS_NUM - start_index))
        {
            rollback_num = CUI_SMS_MAX_RECIPIENTS_NUM - start_index;
        }

        memset(
            recipient_data.recipient[start_index],
            0,
            (MMI_SMS_MAX_ADDR_LEN + 1) * rollback_num);
        recipient_data.total_num = recipient_data.pre_total_num;
    }

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_append_recipient
 * DESCRIPTION
 *  Append Recipient to the Recipient List
 * PARAMETERS
 *  ucs2_addr       [IN]    UCS2 Address
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_append_recipient(S8 *ucs2_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (recipient_data.total_num < MMI_SMS_MAX_RECIPIENTS_NUM)
    {
        if (mmi_ucs2strlen(ucs2_addr) > 0)
        {
            S8 *ascii_addr = recipient_data.recipient[recipient_data.total_num];
            U16 addr_len;

            addr_len = mmi_ucs2_n_to_asc(ascii_addr, ucs2_addr, MMI_SMS_MAX_ADDR_LEN * ENCODING_LENGTH);
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
 *  mmi_sms_reset_recipient_data
 * DESCRIPTION
 *  Reset the Add Recipient Data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_reset_recipient_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&recipient_data, 0, sizeof(mmi_sms_add_recipient_struct));
#if !defined(__MMI_UNIFIED_COMPOSER__) && defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__)
    mmi_sms_init_recipient_buffer();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_add_addr_list_to_recipient
 * DESCRIPTION
 *  Add the address list to the recipient list,
 *  and return the count of invalid address
 * PARAMETERS
 *  ucs2_addr_list  [IN]    Address List (UCS2 Format)
 *  addr_count      [IN]    The input address total number
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_sms_add_addr_list_to_recipient(S8 **ucs2_addr_list, U16 addr_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 invalid_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MMI_TELEPHONY_SUPPORT__) || defined(__MMI_BT_MAP_CLIENT__)
    if ((ucs2_addr_list != NULL) && (addr_count > 0))
    {
        for (i = 0; i < addr_count; i++)
        {
            S8 *ucs2_addr = ucs2_addr_list[i];

            if (
                #ifdef __MMI_TELEPHONY_SUPPORT__
                srv_sms_check_ucs2_number((S8*)ucs2_addr) == MMI_FALSE
                #elif defined(__MMI_BT_MAP_CLIENT__)
                srv_sms_btmapc_check_ucs2_number((S8*)ucs2_addr) == MMI_FALSE
                #endif/*__MMI_TELEPHONY_SUPPORT__*/
                )
            {
                invalid_num++;
            }
            else
            {
                if (mmi_sms_append_recipient((S8*)ucs2_addr) == MMI_FALSE)
                {
                    break;
                }
            }
        }
    }
    #endif
    return invalid_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_max_recipient_num
 * DESCRIPTION
 *  Get The SMS Max Recipient Number
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_sms_get_max_recipient_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_SMS_MAX_RECIPIENTS_NUM;
}


#if !defined(__MMI_UNIFIED_COMPOSER__) && defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_recipient_name_buffer
 * DESCRIPTION
 *  Get The SMS recipient name buffer
 * PARAMETERS
 *  index  [IN]    index
 * RETURNS
 *  U16
 *****************************************************************************/
S8* mmi_sms_get_recipient_name_buffer(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < MMI_SMS_MAX_RECIPIENTS_NUM)
    {
        return (S8 *) recipient_data.recipient_name[index];
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_recipient_number
 * DESCRIPTION
 *  Reset the Add Recipient Data
 * PARAMETERS
 *  index  [IN]    The number need to be check
 * RETURNS
 *  U16     The number of valid recipient
 *****************************************************************************/
U16 mmi_sms_check_recipient_number(U16 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num > MMI_SMS_MAX_RECIPIENTS_NUM)
    {
        num = MMI_SMS_MAX_RECIPIENTS_NUM;
    }
    for (i = 0; i < num; i++)
    {
        if (recipient_data.is_recipient_map[i] == MMI_FALSE)
        {
            U16 number[MMI_SMS_MAX_NUM_LEN + 2];
            U16 addr_len;

            addr_len = mmi_ucs2strlen((S8 *)recipient_data.recipient_name[i]);
            mmi_ucs2cpy((S8 *)number, (S8 *)recipient_data.recipient_name[i]);
            if (addr_len && number[addr_len - 1] == L';')
            {
                number[addr_len - 1] = L'\0';
                addr_len--;
            }
            
            if (srv_sms_check_ucs2_number((S8*)number) == MMI_TRUE)
            {
                /* add new unmber*/
                recipient_data.total_num++;
                addr_len = mmi_ucs2_n_to_asc(recipient_data.recipient[i], (CHAR *)number, MMI_SMS_MAX_ADDR_LEN * ENCODING_LENGTH);
                recipient_data.recipient[i][addr_len] = '\0';
                recipient_data.is_recipient_map[i] = MMI_TRUE;
            }
            else
            {
                break;
            }
        }        
    }
    
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_update_recipient_name_number
 * DESCRIPTION
 *  Reset the Add Recipient Data
 * PARAMETERS
 *  index  [IN]    The index need to be updated
 * RETURNS
 *  MMI_BOOL     MMI_TRUE: success; MMI_FALSE: failed
 *****************************************************************************/
MMI_BOOL mmi_sms_update_recipient_name_number(U16 index, S8 *ucs2_addr, U16 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = index + offset;
    U16 j = MMI_SMS_MAX_RECIPIENTS_NUM - 1;
    U16 len = mmi_ucs2strlen(ucs2_addr) << 1;
    MMI_BOOL ret = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (i >= MMI_SMS_MAX_RECIPIENTS_NUM || (offset && recipient_data.total_num >= MMI_SMS_MAX_RECIPIENTS_NUM))
    {
         return MMI_FALSE;
    }
    if (offset > 0)
    {
        wgui_cat28_insert_new_recipient(i, (UI_buffer_type)&recipient_data.recipient_name[index], WGUI_CAT28_WRAPPING_DELETE_RECIPIENT, MMI_FALSE);
    }
    mmi_sms_set_recipient_validy(i, MMI_TRUE);
    ret = mmi_sms_add_recipient_number(i, ucs2_addr);
    if (ret)
    {
        mmi_sms_set_recipient_edit_flag(i, WGUI_CAT28_WRAPPING_DELETE_RECIPIENT, MMI_TRUE);
    }
    else
    {
        mmi_sms_set_recipient_edit_flag(i, WGUI_CAT28_HIGHLIGHT_RECIPIENT, MMI_TRUE);
    }
    
   return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_add_recipient_number
 * DESCRIPTION
 *  Reset the Add Recipient Data
 * PARAMETERS
 *  index  [IN]    The index need to be updated
 * RETURNS
 *  MMI_BOOL     MMI_TRUE: success; MMI_FALSE: failed
 *****************************************************************************/
MMI_BOOL mmi_sms_add_recipient_number(U16 index, S8 *ucs2_addr)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 len = 0;
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= MMI_SMS_MAX_RECIPIENTS_NUM)
    {
        return MMI_FALSE;
    }
    
    if (ucs2_addr)
    {
        if (srv_sms_check_ucs2_number(ucs2_addr) == MMI_TRUE)
        {
            
            if ( recipient_data.is_recipient_map[index] == MMI_TRUE)
            {
                mmi_sms_adjust_recipient_number(index);
            }
            len = mmi_ucs2_n_to_asc(recipient_data.recipient[index], ucs2_addr, (mmi_ucs2strlen(ucs2_addr) << 1));
            recipient_data.recipient[index][len] = '\0';
            recipient_data.is_recipient_map[index] = MMI_TRUE;
            recipient_data.total_num++;
        }
        else
        {
            recipient_data.is_recipient_map[index] = MMI_FALSE;
            
            return MMI_FALSE;
        }
        return MMI_TRUE;
    }   
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_adjust_recipient_number
 * DESCRIPTION
 *  Reset the Add Recipient Data
 * PARAMETERS
 *  index  [IN]    The index need to be updated
 * RETURNS
 *  MMI_BOOL     MMI_TRUE: success; MMI_FALSE: failed
 *****************************************************************************/
MMI_BOOL mmi_sms_adjust_recipient_number(U16 index)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (recipient_data.total_num > 0 && recipient_data.total_num < MMI_SMS_MAX_RECIPIENTS_NUM && index < recipient_data.total_num)
    { 
        U16 i;
        U16 total_num = mmi_sms_get_recipient_num();

        if (total_num >= MMI_SMS_MAX_RECIPIENTS_NUM)
        {
            return MMI_FALSE;
        }

        for (i = total_num; i > index ; i--)
        {
            strcpy((S8 *)recipient_data.recipient[i], (S8 *)recipient_data.recipient[i - 1]);
            recipient_data.is_recipient_map[i] =  recipient_data.is_recipient_map[i - 1];
        }
        recipient_data.is_recipient_map[index] = MMI_FALSE;

        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_delete_recipient_number
 * DESCRIPTION
 *  Delete one Recipient number
 * PARAMETERS
 *  index  [IN]    The index need to be updated
 * RETURNS
 *  MMI_BOOL     MMI_TRUE: success; MMI_FALSE: failed
 *****************************************************************************/
MMI_BOOL mmi_sms_delete_recipient_number(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < MMI_SMS_MAX_RECIPIENTS_NUM && recipient_data.total_num)
    {
        U16 i;
        U16 total_num = wgui_cat28_get_recipients_num();


         /* reset the last recipient as empty */
        recipient_data.recipient[index][0] = '\0';
        if (recipient_data.is_recipient_map[index])
        {
            recipient_data.is_recipient_map[index] = MMI_FALSE;
            recipient_data.total_num--;
        }
        for (i = index + 1; i <= total_num; i++)
        {
            strcpy((S8 *)recipient_data.recipient[i - 1], (S8 *)recipient_data.recipient[i]);
            recipient_data.is_recipient_map[i - 1] = recipient_data.is_recipient_map[i];        
        }
        recipient_data.recipient[total_num][0] = '\0';
        recipient_data.is_recipient_map[total_num] = MMI_FALSE;
        
        return MMI_TRUE;      
    }
 
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_add_recipient
 * DESCRIPTION
 *  Add Recipient to the Recipient List
 * PARAMETERS
 *  ucs2_addr       [IN]    UCS2 Address
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_add_recipient(S8 *ucs2_name, S8 *ucs2_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num = mmi_sms_get_recipient_num();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (num < MMI_SMS_MAX_RECIPIENTS_NUM)
    {
        U16 len;
        U16 num_len = mmi_ucs2strlen(ucs2_addr);

        if (ucs2_name == NULL || mmi_ucs2strlen(ucs2_name) == 0)
        {
            if (num_len != 0)
            {
                srv_phb_get_name_by_number((U16 *)ucs2_addr, (U16 *)&recipient_data.recipient_name[num], CUI_SMS_MAX_ADDR_LEN);
                if (mmi_ucs2strlen((S8*)&recipient_data.recipient_name[num]) == 0)
                {
                   if (srv_sms_check_ucs2_number(ucs2_addr))
                   {
                        mmi_ucs2cpy((CHAR *) &recipient_data.recipient_name[num], (CHAR *) ucs2_addr);
                        mmi_sms_set_recipient_edit_flag(num, WGUI_CAT28_DEFAULT_FLAGS, MMI_FALSE);
                   }
                   else
                   {
                       return MMI_FALSE;
                   }
                }
                else
                {
                    mmi_sms_set_recipient_edit_flag(num, WGUI_CAT28_WRAPPING_DELETE_RECIPIENT, MMI_FALSE);
                }
            }
            else
            {
                return MMI_FALSE;
            }
        }
        else
        {
            len = mmi_ucs2strlen(ucs2_name);
            
            if (len > CUI_SMS_MAX_ADDR_LEN)
            {
                len = CUI_SMS_MAX_ADDR_LEN;
            }
            mmi_ucs2cpy((CHAR *) &recipient_data.recipient_name[num], (CHAR *) ucs2_name);
            mmi_sms_set_recipient_edit_flag(num, WGUI_CAT28_WRAPPING_DELETE_RECIPIENT, MMI_FALSE);
        } 
        mmi_sms_set_recipient_validy(num, MMI_TRUE);
        mmi_ucs2cat((S8 *) &recipient_data.recipient_name[num], (S8 *)L";");

        if (num_len)
        {
             return mmi_sms_add_recipient_number(num, ucs2_addr);
        }
    }
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_recipient_number_flag
 * DESCRIPTION
 *  Reset the Add Recipient Data
 * PARAMETERS
 *  index  [IN]    The number need to be modify
 * RETURNS
 *  U16     The number of valid recipient
 *****************************************************************************/
void mmi_sms_set_recipient_number_flag(U16 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (recipient_data.is_recipient_map[num])
    {
        recipient_data.is_recipient_map[num] = MMI_FALSE;
        recipient_data.recipient[num][0] = '\0';
        recipient_data.total_num--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_add_many_addr_to_recipient
 * DESCRIPTION
 *  Add the address list to the recipient list,
 *  and return the count of invalid address
 * PARAMETERS
 *  ucs2_addr_list  [IN]    Address List (UCS2 Format)
 *  addr_count      [IN]    The input address total number
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_sms_add_many_addr_to_recipient(S8 **ucs2_addr_list, U16 addr_count)
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

            if (srv_sms_check_ucs2_number((S8*)ucs2_addr) == MMI_FALSE)
            {
                invalid_num++;
            }
            else
            {
                if (mmi_sms_add_recipient(NULL, (S8*)ucs2_addr) == MMI_FALSE)
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
 *  mmi_sms_get_recipient_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_sms_get_recipient_name(U16 index, U16* name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < MMI_SMS_MAX_RECIPIENTS_NUM)
    {
        mmi_ucs2cpy((S8 *)name, (S8 *)recipient_data.recipient_name[index]);
        len = mmi_ucs2strlen((S8 *)recipient_data.recipient_name[index]);
        if (len > 0 && (name[len - 1] == L';' || name[len - 1] == 0xff1b ))
        {
            name[len - 1] = L'\0';
        }
    }

    return len;
}
#endif /* !defined(__MMI_UNIFIED_COMPOSER__) && defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__) */


#ifdef __MMI_MESSAGES_SMS_EMAIL__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_preferred_msg_type
 * DESCRIPTION
 *  Get Preferred msg type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_sms_msg_type_enum mmi_sms_get_preferred_msg_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_msg_type_enum preferred_type;

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
 *  mmi_sms_set_send_type
 * DESCRIPTION
 *  Set the send msg type
 * PARAMETERS
 *  send_type           [IN] the send msg type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_set_send_type(mmi_sms_msg_type_enum send_type)
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
 *  mmi_sms_get_send_type
 * DESCRIPTION
 *  Get the send msg type
 * PARAMETERS
 *  send_type           [IN] the send msg type
 * RETURNS
 *  void
 *****************************************************************************/
mmi_sms_msg_type_enum mmi_sms_get_send_type(void)
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
 *  mmi_sms_set_send_msg_case
 * DESCRIPTION
 *  set send message case state
 * PARAMETERS
 *  send_msg_case        [IN]  	send msg case      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_set_send_msg_case(mmi_sms_send_case_enum send_msg_case)
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
mmi_sms_send_case_enum mmi_sms_get_send_msg_case(void)
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
 *  mmi_sms_get_is_sent
 * DESCRIPTION
 *  Check whether it is sending msg
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
*****************************************************************************/
MMI_BOOL mmi_sms_get_is_sent(void)
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
 *  mmi_sms_set_is_sent_false
 * DESCRIPTION
 *  Check whether it is sending msg
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
*****************************************************************************/
void mmi_sms_set_is_sent_false(void)
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
 *  mmi_sms_set_is_sent_false
 * DESCRIPTION
 *  Check whether it is sending msg
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
*****************************************************************************/
void mmi_sms_set_is_sent_true(void)
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
 *  mmi_sms_is_re_entry_send
 * DESCRIPTION
 *  Check Whether it is re-entry to Edit or Send Message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sms_is_re_entry_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_EDITOR, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG) ||
        (mmi_sms_editor_send_child_gid != GRP_ID_INVALID))
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_IS_RE_ENTRY_SEND, send_info_data.is_sent, result);

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_write_text_msg
 * DESCRIPTION
 *  Entry SMS Editor For Write a Text message
 * PARAMETERS
 *  ucs2_addr_list  [IN]    Address List (UCS2 Format)
 *  addr_count      [IN]    The input address total number
 *  ucs2_content    [IN]    The default UCS2 content will be input to the Editor 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_entry_write_text_msg(S8 **ucs2_addr_list, U16 addr_count, S8 *ucs2_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* will remove define W1021*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_write_sms
 * DESCRIPTION
 *  Entry SMS Editor For Write a Text message
 * PARAMETERS
 *  ucs2_addr_list  [IN]    Address List (UCS2 Format)
 *  addr_count      [IN]    The input address total number
 *  ucs2_content    [IN]    The default UCS2 content will be input to the Editor 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_entry_write_sms(MMI_ID parent_gid, S8 **ucs2_addr_list, U16 addr_count, S8 *ucs2_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    mmi_sms_uc_data_struct uc_data;
#endif /* __MMI_UNIFIED_COMPOSER__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ENTRY_WRITE_TEXT_MSG_UC, ucs2_addr_list, addr_count, ucs2_content);

    uc_data.msg_index = SRV_SMS_INVALID_MSG_ID;
    uc_data.text_buff = (U8*)ucs2_content;
    uc_data.text_char_num = mmi_ucs2strlen(ucs2_content);
    uc_data.ucs2_addr_list = ucs2_addr_list;
    uc_data.addr_count = (U8)addr_count;
    uc_data.state_type = MMI_UC_STATE_WRITE_NEW_MSG;
    uc_data.msg_type = MMI_UC_MSG_TYPE_SMS_ONLY;
    uc_data.info_type = MMI_UC_INFO_TYPE_SMS;
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

    if (parent_gid == GRP_ID_ROOT)
    {
        parent_gid = g_sms_parent_gid;
        g_sms_parent_gid = GRP_ID_ROOT;
    }

    mmi_sms_entry_uc(&uc_data);

    if (parent_gid == GRP_ID_ROOT)
    {
        g_sms_parent_gid = parent_gid;
    }

#else /* __MMI_UNIFIED_COMPOSER__ */
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ENTRY_WRITE_TEXT_MSG, ucs2_addr_list, addr_count, ucs2_content);

    if (mmi_sms_is_allow_send_sms() == MMI_FALSE)
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);
    }
    else
    {
    #ifdef __MMI_TELEPHONY_SUPPORT__
        EMSData *edit_ems_data;
        EMSTATUS result;

        GetEMSDataForEdit(&edit_ems_data, 1);

        result = mmi_sms_add_text_to_ems_data(edit_ems_data, ucs2_content);

        if (result != EMS_OK)
        {
            mmi_sms_display_popup_ext(
                STR_SMS_FAILURE_DATA_EXCEED,
                MMI_EVENT_FAILURE);
        }
        else
        {
    #endif
            U16 invalid_num;
            U16 pre_add_count;

            mmi_sms_reset_recipient_data();

            mmi_sms_set_send_msg_case(SMS_SEND_CASE_WRITE_FROM_OTHER_APP);
        #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
        #endif /* __MMI_DUAL_SIM_MASTER__ */

            if (addr_count > MMI_SMS_MAX_RECIPIENTS_NUM)
            {
                pre_add_count = MMI_SMS_MAX_RECIPIENTS_NUM;
            }
            else
            {
                pre_add_count = addr_count;
            }
        #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
            invalid_num = mmi_sms_add_many_addr_to_recipient(ucs2_addr_list, pre_add_count);
        #else
            invalid_num = mmi_sms_add_addr_list_to_recipient(ucs2_addr_list, pre_add_count);
        #endif

            if (addr_count > MMI_SMS_MAX_RECIPIENTS_NUM)
            {
                recipient_data.pre_total_num = 0;
                recipient_data.invalid_num = invalid_num;

                if ((g_sms_gid == GRP_ID_INVALID) || (parent_gid != g_sms_gid)
                    || mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_EDITOR, MMI_FRM_NODE_ALL_FLAG))
                {
                    mmi_sms_group_entry(parent_gid);
                }

                mmi_sms_entry_recipient_exceeded_confirm(MMI_SMS_MAX_RECIPIENTS_NUM, MMI_FALSE);
            }
            else
            {
                if (invalid_num > 0)
                {
                    if (addr_count == 1)
                    {
                        mmi_sms_display_popup_ext(
                            STR_GLOBAL_INVALID_NUMBER,
                            MMI_EVENT_FAILURE);
                    }
                    else
                    {
                        if ((g_sms_gid == GRP_ID_INVALID) || (parent_gid != g_sms_gid)
                            || mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_EDITOR, MMI_FRM_NODE_ALL_FLAG))
                        {
                            mmi_sms_group_entry(parent_gid);
                        }

                        mmi_sms_pre_entry_editor();

                        mmi_sms_display_popup_ext(
                            STR_ID_SMS_INVLAID_NUMBERS_REMOVED,
                            MMI_EVENT_INFO);
                    }
                }
                else
                {
                    if ((g_sms_gid == GRP_ID_INVALID) || (parent_gid != g_sms_gid)
                        || mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_EDITOR, MMI_FRM_NODE_ALL_FLAG))
                    {
                        mmi_sms_group_entry(parent_gid);
                    }

                    mmi_sms_pre_entry_editor();
                }
            }
    #ifdef __MMI_TELEPHONY_SUPPORT__
        }
    #endif/*__MMI_TELEPHONY_SUPPORT__*/
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */
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
 *  mmi_sms_send_text_msg
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
void mmi_sms_send_text_msg(S8 **ucs2_addr_list, U16 addr_count, S8 *ucs2_content)
{
    /* will remove define W1021*/
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_send_data_msg
 * DESCRIPTION
 *  Send Data SMS
 * PARAMETERS
 *  src_port        [IN]    Source port number
 *  dest_port       [IN]    Destination port number
 *  ucs2_addr_list  [IN]    UCS2 Address List
 *  addr_count      [IN]    The input address total number
 *  file_path       [IN]    File path of the content 
 *  content_buff    [IN]    The buffer ot content
 *  buff_size       [IN]    The buffer size of content_buff
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_send_data_msg(
            U16 src_port,
            U16 dest_port,
            S8 **ucs2_addr_list,
            U16 addr_count,
            S8 *file_path,
            S8 *content_buff,
            U32 buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_SEND_DATA_MSG, src_port, dest_port, ucs2_addr_list, addr_count);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_SEND_DATA_MSG_1, file_path, content_buff, buff_size);

    if (
        #ifdef __MMI_TELEPHONY_SUPPORT__
        (mmi_sms_is_send_enable() == MMI_FALSE) ||
        #endif/*__MMI_TELEPHONY_SUPPORT__*/
        (mmi_sms_is_re_entry_send() == MMI_TRUE))
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);
    }
    #ifdef __MMI_TELEPHONY_SUPPORT__
    else if (mmi_sms_is_sms_ready() == MMI_FALSE)
    {
        mmi_sms_display_popup_ext(
            STR_SMS_MSG_NOT_READY_YET,
            MMI_EVENT_FAILURE);
    }
    #endif/*__MMI_TELEPHONY_SUPPORT__*/
    else
    {
    #ifdef __MMI_TELEPHONY_SUPPORT__
        EMSData *edit_ems_data;
        EMSTATUS result;

        GetEMSDataForEdit(&edit_ems_data, 1);

        result = mmi_sms_add_data_to_ems_data(
                                    edit_ems_data,
                                    src_port,
                                    dest_port,
                                    file_path,
                                    content_buff,
                                    buff_size);

        if (result == EMS_OK)
        {
    #endif/*__MMI_TELEPHONY_SUPPORT__*/
            U16 invalid_num;
            U16 pre_add_count;

            mmi_sms_reset_recipient_data();

            mmi_sms_set_send_msg_case(SMS_SEND_CASE_SEND_DATA_MSG);
        #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_MESSAGES_SMS_EMAIL__
            mmi_sms_set_send_type(SMS_MSG_TYPE_TEXT);
        #endif /* __MMI_MESSAGES_SMS_EMAIL__ */

            if (addr_count > MMI_SMS_MAX_RECIPIENTS_NUM)
            {
                pre_add_count = MMI_SMS_MAX_RECIPIENTS_NUM;
            }
            else
            {
                pre_add_count = addr_count;
            }

            invalid_num = mmi_sms_add_addr_list_to_recipient(ucs2_addr_list, pre_add_count);

            if (addr_count > MMI_SMS_MAX_RECIPIENTS_NUM)
            {
                recipient_data.pre_total_num = 0;
                recipient_data.invalid_num = invalid_num;
                mmi_sms_entry_recipient_exceeded_confirm(MMI_SMS_MAX_RECIPIENTS_NUM, MMI_TRUE);
            }
            else
            {
                if (invalid_num > 0)
                {
                    if (addr_count == 1)
                    {
                        mmi_sms_display_popup_ext(
                            STR_GLOBAL_INVALID_NUMBER,
                            MMI_EVENT_FAILURE);
                    }
                    else
                    {
                    #ifdef __MMI_UNIFIED_COMPOSER__
                        mmi_sms_entry_add_recipient();
                    #else /* __MMI_UNIFIED_COMPOSER__ */
                        mmi_sms_pre_entry_add_recipient(MMI_TRUE);
                    #endif /* __MMI_UNIFIED_COMPOSER__ */

                        mmi_sms_display_popup_ext(
                            STR_ID_SMS_INVLAID_NUMBERS_REMOVED,
                            MMI_EVENT_INFO);
                    }
                }
                else
                {
                    if (recipient_data.total_num > 0)
                    {
                    #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
                    #else /* __MMI_DUAL_SIM_MASTER__ */
                        mmi_sms_send_sms();
                    #endif /* __MMI_DUAL_SIM_MASTER__ */
                    }
                    else
                    {
                    #ifdef __MMI_UNIFIED_COMPOSER__
                        mmi_sms_entry_add_recipient();
                    #else /* __MMI_UNIFIED_COMPOSER__ */
                        mmi_sms_pre_entry_add_recipient(MMI_TRUE);
                    #endif /* __MMI_UNIFIED_COMPOSER__ */
                    }
                }
            }
        #ifdef __MMI_TELEPHONY_SUPPORT__
        }
        else
        {
            switch (result)
            {
                case EMS_EMS_DATA_EXCEEDED:
                    mmi_sms_display_popup_ext(
                        STR_SMS_FAILURE_DATA_EXCEED,
                        MMI_EVENT_FAILURE);
                    break;

                case EMS_INVALID_EMS_DATA:
                default:
                    mmi_sms_display_popup_ext(
                        STR_SMS_FAILURE_DATA_INVALID,
                        MMI_EVENT_FAILURE);
                    break;
            }
        }
        #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_write_msg_from_phb
 * DESCRIPTION
 *  Entrt the SMS editor to write SMS from Phonebook
 * PARAMETERS
 *  addr_count          [IN]    address total number
 *  get_phb_num_func    [IN]    The function to get number from phonebook
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_entry_write_msg_from_phb(U16 addr_count, void *get_phb_num_func)
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
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ENTRY_WRITE_MSG_FROM_PHB_UC, addr_count, get_phb_num_func);

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
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ENTRY_WRITE_MSG_FROM_PHB, addr_count, get_phb_num_func);

    if (mmi_sms_is_re_entry_send() == MMI_TRUE)
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);
    }
    #ifdef __MMI_TELEPHONY_SUPPORT__
    else if (mmi_sms_is_sms_ready() == MMI_FALSE)
    {
        mmi_sms_display_popup_ext(
            STR_SMS_MSG_NOT_READY_YET,
            MMI_EVENT_FAILURE);
    }
    #endif/*__MMI_TELEPHONY_SUPPORT__*/
    else
    {
        U16 i;
        MMI_BOOL is_exist_invalid = MMI_FALSE;
        mmi_phb_send_address_to_others_callback_type get_num_cb_func;

        get_num_cb_func = (mmi_phb_send_address_to_others_callback_type)get_phb_num_func;
    //#ifdef __MMI_TELEPHONY_SUPPORT__
        ReleaseEMSEditBuffer();
   // #endif
        mmi_sms_reset_recipient_data();

        for (i = 0; i < addr_count; i++)
        {
            S8* phb_addr;
            U16 type;

            phb_addr = get_num_cb_func(i, &type);
            #if defined(__MMI_TELEPHONY_SUPPORT__) || defined(__MMI_BT_MAP_CLIENT__)
            if (
                #ifdef __MMI_TELEPHONY_SUPPORT__
                srv_sms_check_ucs2_number(phb_addr) == MMI_FALSE
                #elif defined(__MMI_BT_MAP_CLIENT__)
                srv_sms_btmapc_check_ucs2_number(phb_addr) == MMI_FALSE
                #endif
                )
            {
                if (is_exist_invalid == MMI_FALSE)
                {
                    is_exist_invalid = MMI_TRUE;
                }
            }
            else
            #endif
            {
            #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
                if (mmi_sms_add_recipient(NULL, phb_addr) == MMI_FALSE)                
            #else
                if (mmi_sms_append_recipient(phb_addr) == MMI_FALSE)
            #endif
                {
                    break;
                }
            }
        }

        mmi_sms_set_send_msg_case(SMS_SEND_CASE_WRITE_FROM_OTHER_APP);
    #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        mmi_sms_set_send_type(SMS_MSG_TYPE_TEXT);
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */

        mmi_sms_group_entry(GRP_ID_ROOT);
        mmi_sms_pre_entry_editor();

        if (is_exist_invalid == MMI_TRUE)
        {
            mmi_sms_display_popup_ext(
                STR_ID_SMS_INVLAID_NUMBERS_REMOVED,
                MMI_EVENT_INFO);
        }
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_write_msg
 * DESCRIPTION
 *  Entry Write or Send Message screen
 * PARAMETERS
 *  send_case       [IN]    Send Msg Case
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_entry_write_msg(mmi_sms_send_case_enum send_case)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ENTRY_WRITE_MSG_1, send_case);

    mmi_sms_set_send_msg_case(send_case);

#ifdef __MMI_UNIFIED_COMPOSER__
    switch (send_case)
    {
        case SMS_SEND_CASE_EDIT_DRAFT:
        case SMS_SEND_CASE_EDIT_UNSENT:
        case SMS_SEND_CASE_RESEND:
        case SMS_SEND_CASE_SEND_DRAFT:
        case SMS_SEND_CASE_FORWARD:
        {
            EMSData *pEMS = GetEMSDataForView(NULL, 0);

            MMI_ASSERT(pEMS != NULL);
#ifndef __ULC_SLIM_EMS__
            if ((pEMS->listHead != NULL) && 
                ((send_case == SMS_SEND_CASE_EDIT_DRAFT) ||
                 (send_case == SMS_SEND_CASE_EDIT_UNSENT) ||
                 (send_case == SMS_SEND_CASE_FORWARD)))
            {
                mmi_sms_entry_confirm_generic(
                    STR_SMS_REMOVE_EMS_OBJECT_QUERY_ID,
                    mmi_sms_write_msg_by_uc,
                    mmi_frm_scrn_close_active_id);
            }
            else
#endif /* ndef __ULC_SLIM_EMS__ */                
            {
                mmi_sms_write_msg_by_uc();
            }
            break;
        }

        case SMS_SEND_CASE_WRITE_NEW_MSG:
        case SMS_SEND_CASE_REPLY:
        default:
        {
            mmi_sms_write_msg_by_uc();
            break;
        }
    }

#else /* __MMI_UNIFIED_COMPOSER__ */
    if ((mmi_sms_is_re_entry_send() == MMI_TRUE))
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);
    }
    #ifdef __MMI_TELEPHONY_SUPPORT__
    else if (mmi_sms_is_sms_ready() == MMI_FALSE)
    {
        mmi_sms_display_popup_ext(
            STR_SMS_MSG_NOT_READY_YET,
            MMI_EVENT_FAILURE);
    }
    #endif/*__MMI_TELEPHONY_SUPPORT__*/
    else
    {
        U16 msg_index = SRV_SMS_INVALID_MSG_ID;
        MMI_BOOL is_add_num = MMI_FALSE;
        MMI_BOOL is_entry_editor = MMI_TRUE;
        MMI_BOOL is_entry_recipient = MMI_TRUE;
        MMI_BOOL is_reset_edit_data = MMI_TRUE;
        MMI_BOOL is_reset_recipient_data = MMI_TRUE;
#ifdef __MMI_MESSAGES_SMS_EMAIL__
        mmi_sms_msg_type_enum send_msg_type = SMS_MSG_TYPE_TEXT;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

        switch (send_case)
        {
            case SMS_SEND_CASE_EDIT_DRAFT:
            case SMS_SEND_CASE_EDIT_UNSENT:
            case SMS_SEND_CASE_RESEND:
            case SMS_SEND_CASE_SEND_DRAFT:
            case SMS_SEND_CASE_FORWARD:
            {
                U8 result;

                result = CopyEMSViewToEditBuffer();
                is_reset_edit_data = MMI_FALSE;

                /* copy view content to edit buffer maybe fail due to EMS LIB virtual pack fail */
                if (result != EMS_OK)
                {
                    mmi_sms_display_popup_ext(
                        STR_SMS_FAILURE_MSG_LEN_EXCEEDED,
                        MMI_EVENT_FAILURE);
                    return;
                }
                else
                {
                    switch (send_case)
                    {
                        case SMS_SEND_CASE_EDIT_DRAFT:
                        case SMS_SEND_CASE_EDIT_UNSENT:
                        {
                        #ifndef __SMS_R8_NATION_LANGUAGE__
                            EMSData *pEMS;

                            GetEMSDataForEdit(&pEMS, 0);
                        #ifndef __UNIFIED_COMPOSER_SUPPORT__
                        #ifndef __ULC_SLIM_EMS__
                            mmi_msg_handle_edit_ems_data(pEMS);
                        #endif /* __ULC_SLIM_EMS__ */
                        #endif
                        #endif /* __SMS_R8_NATION_LANGUAGE__ */

                            msg_index = g_sms_cntx.curr_msg_id;
                            is_add_num = MMI_TRUE;
                            break;
                        }

                        case SMS_SEND_CASE_RESEND:
                            msg_index = g_sms_cntx.curr_msg_id;
                            is_add_num = MMI_TRUE;
                        #ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
                            is_entry_editor = MMI_FALSE;
                        #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
                            break;

                        case SMS_SEND_CASE_SEND_DRAFT:
                            msg_index = g_sms_cntx.curr_msg_id;
                            is_add_num = MMI_TRUE;
                        #ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__                            
                            is_entry_editor = MMI_FALSE;
                        #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
                            break;

                        case SMS_SEND_CASE_FORWARD:
                            break;

                        default:
                            MMI_ASSERT(0);
                            break;
                    }
                }
                break;
            }

            case SMS_SEND_CASE_REPLY:
            case SMS_SEND_CASE_ARCHIVE_REPLY:
            {
                msg_index = g_sms_cntx.curr_msg_id;
                is_add_num = MMI_TRUE;
                break;
            }

            case SMS_SEND_CASE_WRITE_NEW_MSG:
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
            ReleaseEMSEditBuffer();
        }

        if (is_reset_recipient_data == MMI_TRUE)
        {
            mmi_sms_reset_recipient_data();
        }

        if ((is_add_num == MMI_TRUE) && (msg_index != SRV_SMS_INVALID_MSG_ID))
        {

        #ifdef __MMI_MESSAGES_SMS_EMAIL__
            if (mmi_sms_is_sms_email(msg_index) == MMI_TRUE)
            {
                send_msg_type = SMS_MSG_TYPE_EMAIL;

                if (mmi_ucs2strlen(g_sms_cntx.sms_email_addr) > 0)
                {
                    mmi_sms_append_recipient(g_sms_cntx.sms_email_addr);

                    if (send_case == SMS_SEND_CASE_RESEND)
                    {
                        is_entry_recipient = MMI_FALSE;
                    }
                }
            }
            else
        #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
            {
                S8 ucs2_addr[(MMI_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
				#ifndef __MMI_SMS_SLIM__
                srv_sms_get_msg_address(msg_index, ucs2_addr);
                #else
                mmi_sms_get_hilite_msg_addr(ucs2_addr);
                #endif

                if ((ucs2_addr[0] != '\0') || (ucs2_addr[1] != '\0'))
                {
                #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
                    if (srv_sms_check_ucs2_number(ucs2_addr) == MMI_FALSE)
                    {
                        mmi_sms_display_popup_ext(
                            STR_ID_SMS_INVLAID_NUMBERS_REMOVED,
                            MMI_EVENT_INFO); 
                    }
                    else
                    {
                        mmi_sms_add_recipient(NULL, (S8 *)ucs2_addr);
                    }
                #else
                    mmi_sms_append_recipient(ucs2_addr);
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
        mmi_sms_set_send_type(send_msg_type);
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */

        if (is_entry_editor == MMI_TRUE)
        {
            mmi_sms_pre_entry_editor();
        }
        else if (is_entry_recipient == MMI_TRUE)
        {
            mmi_sms_pre_entry_add_recipient(MMI_TRUE);
        }
        else
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
        #else /* __MMI_DUAL_SIM_MASTER__ */
            mmi_sms_send_sms();
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        }
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */
}


#ifdef __MMI_UNIFIED_COMPOSER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_write_msg_by_uc
 * DESCRIPTION
 *  Write or Send Msg In the UC version
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_write_msg_by_uc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_send_case_enum send_case = mmi_sms_get_send_msg_case();
    MMI_BOOL is_add_num = MMI_TRUE;
    MMI_BOOL is_add_content = MMI_TRUE;
    S8 *ucs2_addr = NULL;
    U8 addr_count = 0;
    mmi_sms_uc_data_struct uc_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uc_data.msg_index = g_sms_cntx.curr_msg_id;

    uc_data.msg_type = MMI_UC_MSG_TYPE_DEFAULT;
    uc_data.info_type = MMI_UC_INFO_TYPE_SMS;
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

    switch (send_case)
    {
        case SMS_SEND_CASE_REPLY:
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
        #endif /* __MMI_DUAL_SIM_MASTER__ */

            is_add_content = MMI_FALSE;

            uc_data.state_type = MMI_UC_STATE_REPLY;

        #if (MMI_MAX_SIM_NUM >= 2)
            sms_sim_id = srv_sms_get_msg_sim_id(g_sms_cntx.curr_msg_id);

            uc_data.sim_id = mmi_sms_sim_id_to_uc_sim(sms_sim_id);
        #endif /* (MMI_MAX_SIM_NUM >= 2) */
            break;
        }

        case SMS_SEND_CASE_ARCHIVE_REPLY:
        {
            is_add_content = MMI_FALSE;
            uc_data.msg_index = SRV_SMS_INVALID_MSG_ID;
            uc_data.state_type = MMI_UC_STATE_WRITE_NEW_MSG;
            break;
        }

        case SMS_SEND_CASE_FORWARD:
        {
            is_add_num = MMI_FALSE;
            uc_data.state_type = MMI_UC_STATE_FORWARD;
            break;
        }
    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        case SMS_SEND_CASE_RESEND:
        case SMS_SEND_CASE_SEND_DRAFT:
    #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
        case SMS_SEND_CASE_EDIT_DRAFT:
        case SMS_SEND_CASE_EDIT_UNSENT:
        {
            uc_data.state_type = MMI_UC_STATE_EDIT_EXISTED_MSG;
            break;
        }

    #ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        case SMS_SEND_CASE_RESEND:
        case SMS_SEND_CASE_SEND_DRAFT:
        {
            MMI_BOOL is_entry_recipient = MMI_TRUE;
            S8 temp_ucs2_addr[(MMI_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];

            CopyEMSViewToEditBuffer();
			#ifndef __MMI_SMS_SLIM__
            srv_sms_get_msg_address(g_sms_cntx.curr_msg_id, temp_ucs2_addr);
			#else
			mmi_sms_get_hilite_msg_addr(temp_ucs2_addr);
			#endif

            mmi_sms_reset_recipient_data();

            send_info_data.msg_index = g_sms_cntx.curr_msg_id;

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

            if ((temp_ucs2_addr[0] != '\0') || (temp_ucs2_addr[1] != '\0'))
            {
                mmi_sms_append_recipient(temp_ucs2_addr);

                if (send_case == SMS_SEND_CASE_RESEND)
                {
                    is_entry_recipient = MMI_FALSE;
                }
            }

            if (is_entry_recipient == MMI_TRUE)
            {
                mmi_sms_entry_add_recipient();
            }
            else
            {
            #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
            #else /* __MMI_DUAL_SIM_MASTER__ */
                mmi_sms_send_sms();
            #endif /* __MMI_DUAL_SIM_MASTER__ */
            }

            return;
        }
    #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
    
        case SMS_SEND_CASE_WRITE_NEW_MSG:
        default:
        {
            is_add_num = MMI_FALSE;
            is_add_content = MMI_FALSE;
            uc_data.state_type = MMI_UC_STATE_WRITE_NEW_MSG;
            break;
        }
    }

    if (is_add_content == MMI_TRUE)
    {
        EMSData *pEMS;

        GetEMSDataForView(&pEMS, 0);

        uc_data.text_buff = pEMS->textBuffer;
        uc_data.text_char_num = pEMS->textLength / ENCODING_LENGTH;
    }
    else
    {
        uc_data.text_buff = NULL;
        uc_data.text_char_num = 0;
    }

    if (is_add_num == MMI_TRUE)
    {
        S8 *asc_addr;

        asc_addr = (S8*)mmi_sms_get_msg_address(g_sms_cntx.curr_msg_id);

        if (strlen(asc_addr) > 0)
        {
            ucs2_addr = OslMalloc((MMI_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);

            mmi_asc_to_ucs2(ucs2_addr, asc_addr);
            addr_count++;
        }
    }

    uc_data.ucs2_addr_list = &ucs2_addr;
    uc_data.addr_count = addr_count;

    mmi_sms_entry_uc(&uc_data);

    if (ucs2_addr != NULL)
    {
        OslMfree(ucs2_addr);
    }
}
#endif /* __MMI_UNIFIED_COMPOSER__ */

#if defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_uc
 * DESCRIPTION
 *  Entry unified composer editor
 * PARAMETERS
 *  uc_data      [IN]    mmi_sms_uc_data_struct
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_entry_uc(mmi_sms_uc_data_struct *uc_data)  
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_entry_write_struct* data = OslMalloc(sizeof(mmi_uc_entry_write_struct));
    U8 i;
    mmi_uc_addr_struct *temp_addr_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (uc_data == NULL)
    {
        return;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ENTRY_UC, uc_data->ucs2_addr_list, uc_data->addr_count, uc_data->msg_index);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ENTRY_UC_1, uc_data->state_type, uc_data->msg_type, uc_data->info_type);
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

    memset (data, 0 , sizeof(mmi_uc_entry_write_struct));

    for (i = 0; i < uc_data->addr_count; i++)
    {
        mmi_uc_addr_struct *addr_node;

        addr_node = OslMalloc(sizeof(mmi_uc_addr_struct));

        addr_node->addr = (U8*)uc_data->ucs2_addr_list[i];
        addr_node->type = MMI_UC_ADDRESS_TYPE_PHONE_NUMBER;
        addr_node->group = MMI_UC_ADDRESS_GROUP_TYPE_TO;
        addr_node->next = NULL;

        if (data->addr == NULL)
        {
            data->addr = addr_node;
        }
        else if (temp_addr_node != NULL)
        {
            temp_addr_node->next = addr_node;
        }

        temp_addr_node = addr_node;
    }

    data->addr_num = uc_data->addr_count;

    data->msg_type = uc_data->msg_type;
    data->file_path = NULL;

    if ((uc_data->text_buff != NULL) && (uc_data->text_char_num > 0))
    {
        data->text_buffer = uc_data->text_buff;
        data->text_num = uc_data->text_char_num;
    }
    else
    {
        data->text_buffer = NULL;
        data->text_num = 0;
    }

    data->subject = NULL;

    data->info_type = uc_data->info_type;

    if (data->info_type == MMI_UC_INFO_TYPE_SMS)
    {
        data->info = &uc_data->msg_index;
    }
    else
    {
        data->info = NULL;
    }

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

    cui_uc_write_msg_with_content_launch(g_sms_parent_gid, uc_data->state_type, data);

    temp_addr_node = data->addr;

    while (temp_addr_node != NULL)
    {
        mmi_uc_addr_struct *del_addr_node;

        del_addr_node = temp_addr_node;

        temp_addr_node = temp_addr_node->next;
   
        OslMfree(del_addr_node);
    }

    OslMfree(data);
}
#endif /* defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__) */


#if defined(__MMI_MMS_STANDALONE_COMPOSER__) || defined(__MMI_UNIFIED_COMPOSER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_send_mms
 * DESCRIPTION
 *  send one mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_send_one_mms(
                S8 *ucs2_addr
            #if (MMI_MAX_SIM_NUM >= 2)
                , srv_sms_sim_enum sim_id
            #endif /* (MMI_MAX_SIM_NUM >= 2) */
            #ifdef __MMI_MESSAGES_SMS_EMAIL__
                , mmi_sms_address_type_enum addr_type
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
    data->sim_id = mmi_sms_sim_id_to_uc_sim(sim_id);
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
 *  mmi_sms_is_allow_send_sms
 * DESCRIPTION
 *  Check Whether allow to send SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_is_allow_send_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_sms_is_sms_ready() == MMI_FALSE) ||
        (mmi_sms_is_re_entry_send() == MMI_TRUE))
    {
        result = MMI_FALSE;
    }
    else
    {
        result = MMI_TRUE;
    }

    return result;
}


srv_sms_sim_enum mmi_sms_convert_mmi_sim_to_srv_sim(mmi_sms_sim_enum sms_sim_id)
{
    srv_sms_sim_enum srv_sim_id = SRV_SMS_SIM_1;
     switch(sms_sim_id)
     {
     case  SMS_SIM_1:
     srv_sim_id = SRV_SMS_SIM_1;
     break;
     
     case  SMS_SIM_2:
      srv_sim_id = SRV_SMS_SIM_2;
       break;
       
     case SMS_SIM_3:
      srv_sim_id = SRV_SMS_SIM_3;
       break;
       
     case SMS_SIM_4:
      srv_sim_id = SRV_SMS_SIM_4;
       break;
       
     case SMS_SIM_TOTAL:
     case SMS_SIM_UNSPECIFIC:
      srv_sim_id = SRV_SMS_SIM_TOTAL;
      break;
      
      default:
      srv_sim_id = SRV_SMS_SIM_TOTAL;
      break;
     }
    return  srv_sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_send_sms
 * DESCRIPTION
 *  Check Whether allow to send SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_sms_send_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_editor_send_parent_gid = mmi_frm_group_create_ex(
        g_sms_gid,
        GRP_ID_AUTO_GEN,
        mmi_sms_send_msg_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_sms_editor_send_child_gid = cui_sms_send_create(mmi_sms_editor_send_parent_gid);

    if (mmi_sms_editor_send_child_gid != GRP_ID_INVALID)
    {
        if(recipient_data.is_hide_save_menu == MMI_FALSE)
        {
            cui_sms_set_send_unhide_save_menu(mmi_sms_editor_send_child_gid);
        }

    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        if (recipient_data.addr_type == SMS_ADDR_TYPE_EMAIL_ADDR)
        {
            cui_sms_set_send_pid(mmi_sms_editor_send_child_gid, SRV_SMS_PID_EMAIL);
        }
    #endif

        if (recipient_data.total_num > 0)
        {
            U16 ucs2_addr[CUI_SMS_MAX_ADDR_LEN + 1];
            U16 addr_len;
            U16 i;

            if (recipient_data.total_num > MMI_SMS_MAX_RECIPIENTS_NUM)
            {
                recipient_data.total_num = MMI_SMS_MAX_RECIPIENTS_NUM;
            }

            for (i = 0; i < recipient_data.total_num; i++)
            {
                addr_len = mmi_asc_n_to_ucs2((S8*)ucs2_addr, recipient_data.recipient[i], CUI_SMS_MAX_ADDR_LEN);

                if (addr_len > CUI_SMS_MAX_ADDR_LEN *ENCODING_LENGTH)
                {
                    addr_len = CUI_SMS_MAX_ADDR_LEN *ENCODING_LENGTH;
                }

                ucs2_addr[addr_len/ENCODING_LENGTH] = 0;
                cui_sms_set_send_each_address(mmi_sms_editor_send_child_gid, ucs2_addr);
            }

            if (is_hidden_add_recipient_scrn == MMI_FALSE)
            {
                cui_sms_set_send_unhide_add_recipient_scrn(mmi_sms_editor_send_child_gid);
                is_hidden_add_recipient_scrn = MMI_TRUE;
            }
        }
        else if (is_hidden_add_recipient_scrn == MMI_FALSE)
        {
            is_hidden_add_recipient_scrn = MMI_TRUE;
        }
        
    #ifndef __ULC_SLIM_EMS__
        cui_sms_set_send_content_ems(
            mmi_sms_editor_send_child_gid,
            (void*) g_sms_cntx.edit_ems_data);
    #else /* __ULC_SLIM_EMS__ */
        #ifdef __MMI_TELEPHONY_SUPPORT__
        cui_sms_set_send_content_text(
            mmi_sms_editor_send_child_gid, 
            (U16*)g_sms_cntx.edit_ems_data->textBuffer, 
            g_sms_cntx.edit_ems_data->textBufferSize + ENCODING_LENGTH);
        #else
        cui_sms_set_send_content_text(
            mmi_sms_editor_send_child_gid, 
            (U16*)g_sms_cntx.edit_ems_data->textBuffer, 
            g_sms_cntx.edit_ems_data->textBufferSize);
        #endif
    #endif /* __ULC_SLIM_EMS__ */
    
   #if (MMI_MAX_SIM_NUM >= 2)
        if(send_info_data.prefer_sim_id != SMS_SIM_UNSPECIFIC)
        {
            cui_sms_set_send_sim_id(mmi_sms_editor_send_child_gid, mmi_sms_convert_mmi_sim_to_srv_sim(send_info_data.prefer_sim_id));
        }    
        #endif

        if (send_info_data.msg_index != SRV_SMS_INVALID_MSG_ID)
        {
            cui_sms_set_send_msg_id(mmi_sms_editor_send_child_gid, send_info_data.msg_index);
        }

        cui_sms_set_send_msg_case(mmi_sms_editor_send_child_gid, (cui_sms_send_case_enum)send_info_data.send_case);

        if (send_info_data.send_case == SMS_SEND_CASE_REPLY &&
            recipient_data.is_modify == ((MMI_BOOL)MMI_FALSE))
        {
            cui_sms_set_send_reply_msg_id(mmi_sms_editor_send_child_gid, send_info_data.msg_index);
#if (defined(__OP01__) && (MMI_MAX_SIM_NUM >= 2))
            cui_sms_set_send_sim_id(mmi_sms_editor_send_child_gid, srv_sms_get_msg_sim_id(send_info_data.msg_index));
#endif
        }

    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        if ((send_info_data.send_case == SMS_SEND_CASE_SEND_FROM_OTHER_APP)
            ||(send_info_data.send_case == SMS_SEND_CASE_SEND_DATA_MSG))
        {
            cui_sms_set_send_type(mmi_sms_editor_send_child_gid, SRV_SMS_FG_SEND);
        }
        else
        {
            cui_sms_set_send_type(mmi_sms_editor_send_child_gid, SRV_SMS_BG_SAVE_SEND);
        }
    #else
        cui_sms_set_send_type(mmi_sms_editor_send_child_gid, SRV_SMS_FG_SEND);
    #endif

        cui_sms_send_run(mmi_sms_editor_send_child_gid);
    }
    else
    {
        mmi_frm_group_close(mmi_sms_editor_send_parent_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_send_msg_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static mmi_ret mmi_sms_send_msg_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            /* need addd code to release buffer */
            mmi_sms_editor_send_child_gid = GRP_ID_INVALID;
            mmi_sms_editor_send_parent_gid = GRP_ID_INVALID;
            break;

        case EVT_ID_CUI_SMS_SEND:
            {
                cui_evt_sms_send_struct *event = (cui_evt_sms_send_struct*)evt;
                if (event->is_send_finish)
                {
                    if (event->cur_send_result == CUI_SMS_RESULT_GROUP_GOBACK)
                    {
                        mmi_sms_get_recipient_from_send_cui(event);
                    }
                    else
                    {
                        if (event->cur_send_result != CUI_SMS_RESULT_CANCEL)
                        {	
                            mmi_sms_set_is_sent_true();
                            mmi_frm_group_close(g_sms_gid);

                            ReleaseEMSEditBuffer();
                            mmi_sms_reset_recipient_data();
                        }
                    }

                    cui_sms_send_close(event->send_gid);
                    mmi_frm_group_close(event->parent_gid);
                }
            }
            break;
        case EVT_ID_CUI_SMS_SEND_START_SAVING:
            {
                mmi_sms_set_is_sent_true();
                break;
            }

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_send_msg_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_sms_get_recipient_from_send_cui(cui_evt_sms_send_struct *event)/*FM_SG*/
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
    cui_sms_get_send_address(mmi_sms_editor_send_child_gid, (U16**)addr_list, &addr_count);

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
 *  mmi_sms_set_is_recipient_modify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_sms_set_is_recipient_modify(MMI_BOOL set)
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
 *  mmi_sms_is_reenter_message
 * DESCRIPTION
 *  When send sms, before enter editor screen, check if SMS application is reentered
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE: MSG application is reentered,will show popup;FALSE: MSG application is not reentered
 *****************************************************************************/
MMI_BOOL mmi_sms_is_reenter_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    MMI_STR_ID title = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifndef __MMI_UNIFIED_COMPOSER__
    if (mmi_sms_is_sms_ready() == MMI_FALSE)
    {
        
        title = STR_SMS_MSG_NOT_READY_YET;
        result = MMI_TRUE;
    }
    else
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
#ifdef __MMI_TELEPHONY_SUPPORT__
    if (IsMessagesReEntering())
    {
        title = STR_GLOBAL_NOT_AVAILABLE;
        result = MMI_TRUE;
    }
#endif
    if (result)
    {
        mmi_sms_display_popup_ext(
            title,
            MMI_EVENT_FAILURE);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_write_msg_lanch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_sms_write_msg_lanch(mmi_id parent_gid, mmi_sms_write_msg_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_write_msg_para_struct *data = para;
    S8 *text_buff = NULL;
    S8 *text_buff_ucs2 = NULL;
    U32 text_len = 0;
#ifdef __MMI_UNIFIED_COMPOSER__
    mmi_sms_uc_data_struct uc_data;
    U8 addr_count = 0;
    S8 *ucs2_addr = NULL;
#else /* __MMI_UNIFIED_COMPOSER__ */
    EMSData *pEMS;
    U16 result = 0;
#ifndef __ULC_SLIM_EMS__
    history temphistory;
#endif
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_FRM_SMS_ENTRY_WRITE_MSG_REQ); */


    if (data->filename != NULL)
    {
        S32 errorCode = 0;
        FS_HANDLE emsObjectFilePtr;
        U32 read_size = 0;

        emsObjectFilePtr = FS_Open((U16*) data->filename, FS_READ_ONLY);
        /* the file exists without error */
        if (emsObjectFilePtr > 0)
        {
            FS_GetFileSize(emsObjectFilePtr, &text_len);

            /* the file size is 0 */
            if (text_len == 0)
            {
                FS_Close(emsObjectFilePtr);
                mmi_sms_display_popup_ext(
                    STR_SMS_FAILURE_DATA_EMPTY,
                    MMI_EVENT_FAILURE);
                return;
            }

            if (data->dcs == SMSAL_8BIT_DCS)
            {
                /* the file is too large. */
                if (text_len > (160 * MMI_SMS_MAX_MSG_SEG / ENCODING_LENGTH) ||
                    text_len > ((MMI_SMS_MAX_BUFF_SIZE / ENCODING_LENGTH) - 1))
                {
                    FS_Close(emsObjectFilePtr);
                    mmi_sms_display_popup_ext(
                        STR_SMS_FAILURE_DATA_EXCEED,
                        MMI_EVENT_FAILURE);
                    return;
                }
                /* the file size is allowed */
                text_buff = OslMalloc(text_len + 1);
                errorCode = FS_Read(emsObjectFilePtr, text_buff, text_len, &read_size);
                FS_Close(emsObjectFilePtr);
                /* the file content is corrupted */
                if (errorCode < 0)
                {
                    mmi_sms_display_popup_ext(
                        STR_SMS_FAILURE_DATA_INVALID,
                        MMI_EVENT_FAILURE);
                    OslMfree(text_buff);
                    return;
                }
                /* the file content is allowed */
                text_buff_ucs2 = OslMalloc((text_len + 1) * ENCODING_LENGTH);
                mmi_asc_n_to_ucs2(text_buff_ucs2, text_buff, text_len);
                memset(text_buff_ucs2 + text_len * ENCODING_LENGTH, 0, ENCODING_LENGTH);
                OslMfree(text_buff);
            }
            /* UCS2 and  DEFAULT DCS */
            else
            {
                /* the file is too large. */
                if (text_len > (160 * MMI_SMS_MAX_MSG_SEG) ||
                    text_len > (MMI_SMS_MAX_BUFF_SIZE - ENCODING_LENGTH))
                {
                    FS_Close(emsObjectFilePtr);
                    mmi_sms_display_popup_ext(
                        STR_SMS_FAILURE_DATA_EXCEED,
                        MMI_EVENT_FAILURE);
                    return;
                }
                /* the file size is allowed */
                text_buff = OslMalloc(text_len + ENCODING_LENGTH);
                errorCode = FS_Read(emsObjectFilePtr, text_buff, text_len, &read_size);
                FS_Close(emsObjectFilePtr);
                /* the file content is corrupted */
                if (errorCode < 0)
                {
                    mmi_sms_display_popup_ext(
                        STR_SMS_FAILURE_DATA_INVALID,
                        MMI_EVENT_FAILURE);
                    OslMfree(text_buff);
                    return;
                }
                /* the file content is allowed */
                text_buff_ucs2 = OslMalloc((text_len + ENCODING_LENGTH));
                memset(text_buff_ucs2, 0, (text_len + ENCODING_LENGTH));
                memcpy(text_buff_ucs2, text_buff, text_len);
                OslMfree(text_buff);
            }
        }
        else
        {
            mmi_sms_display_popup_ext(
                STR_SMS_FAILURE_DATA_INVALID,
                MMI_EVENT_FAILURE);
            return;
        }
    }
    else if (data->string != NULL && data->stringlength > 0)
    {
        #ifndef __MMI_BT_MAP_CLIENT__
        if (data->stringlength > (160 * MMI_SMS_MAX_MSG_SEG / ENCODING_LENGTH) ||
            data->stringlength > ((MMI_SMS_MAX_BUFF_SIZE / ENCODING_LENGTH) - 1))
        {
            mmi_sms_display_popup_ext(
                STR_SMS_FAILURE_DATA_EXCEED,
                MMI_EVENT_FAILURE);
            return;
        }
        #endif
        text_buff_ucs2 = OslMalloc((data->stringlength + 1) * ENCODING_LENGTH);
        memset((S8*) text_buff_ucs2, 0, ((data->stringlength + 1) * ENCODING_LENGTH));
        memcpy(text_buff_ucs2, data->string, ((data->stringlength) * ENCODING_LENGTH));
    }
#ifndef __MMI_UNIFIED_COMPOSER__
    else
    {
        ReleaseEMSEditBuffer();
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */

#ifndef __MMI_UNIFIED_COMPOSER__
    if (text_buff_ucs2)
    {
        EMSTATUS EMSSetPortResult = EMS_OK;
        EMSTATUS EMSSetClassResult = EMS_OK;

        ReleaseEMSEditBuffer();
        pEMS = GetEMSDataForEdit(0, 1);
        if ((data->flag & MMI_SMS_ENTRY_WRITE_PORT) == MMI_SMS_ENTRY_WRITE_PORT)
        {
            EMSSetPortResult = EMSSetPortNum(pEMS, data->srcport, data->desport);
        }
        if ((data->flag & MMI_SMS_ENTRY_WRITE_CLASS) == MMI_SMS_ENTRY_WRITE_CLASS)
        {
            EMSSetClassResult = EMSSetMsgClass(pEMS, data->dcs_class);
        }

        if ((EMSSetPortResult != EMS_OK) || (EMSSetClassResult != EMS_OK))
        {
            mmi_sms_display_popup_ext(
                STR_SMS_FAILURE_DATA_INVALID,
                MMI_EVENT_FAILURE);
            OslMfree(text_buff_ucs2);
            return;
        }

        if (data->filename != NULL)
        {
            #ifdef __ULC_SLIM_EMS__
            result = mmi_sms_append_string_to_ems_buffer( pEMS, 
                                                (S8*) text_buff_ucs2, 
                                                gui_strlen((UI_string_type) text_buff_ucs2));
            pEMS->dcs = data->dcs;
            #else /* __ULC_SLIM_EMS__ */
            result = AppendEMSString(
                        IMM_INPUT_TYPE_SENTENCE,
                        pEMS,
                        (U8*) text_buff_ucs2,
                        data->dcs,
                        temphistory.guiBuffer);
            
            #endif /* __ULC_SLIM_EMS__ */
        }
        else if (data->string != NULL)
        {
            EMSSetDCS(pEMS, data->dcs);
        #ifdef __ULC_SLIM_EMS__
            result = mmi_sms_append_string_to_ems_buffer(pEMS, (CHAR*) text_buff_ucs2, data->stringlength);
        #else /* __ULC_SLIM_EMS__ */
            result = AddString(pEMS, (CHAR*) text_buff_ucs2, data->stringlength, NULL);
        #endif /* __ULC_SLIM_EMS__ */
        }
        OslMfree(text_buff_ucs2);

        if ((data->filename != NULL && result == 0) || (data->string != NULL && result != EMS_OK))
        {
            mmi_sms_display_popup_ext(
                STR_SMS_FAILURE_DATA_EXCEED,
                MMI_EVENT_FAILURE);
            return;
        }
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */

#ifdef __MMI_UNIFIED_COMPOSER__
    uc_data.msg_index = SRV_SMS_INVALID_MSG_ID;
    uc_data.text_buff = (U8*)text_buff_ucs2;
    uc_data.text_char_num = mmi_ucs2strlen(text_buff_ucs2);

    if (data->ascii_addr != NULL)
    {
        U32 addr_len;

        addr_len = strlen((S8*)data->ascii_addr);
        ucs2_addr = OslMalloc((addr_len + 1) * ENCODING_LENGTH);

        mmi_asc_to_ucs2(ucs2_addr, (S8*)data->ascii_addr);
        addr_count++;
    }

    uc_data.ucs2_addr_list = &ucs2_addr;
    uc_data.addr_count = addr_count;

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */ 

    uc_data.state_type = MMI_UC_STATE_WRITE_NEW_MSG;
    uc_data.msg_type = MMI_UC_MSG_TYPE_SMS_ONLY;
    uc_data.info_type = MMI_UC_INFO_TYPE_SMS;

    parent_gid = g_sms_parent_gid;
    g_sms_parent_gid = GRP_ID_ROOT;
    mmi_sms_entry_uc(&uc_data);
    g_sms_parent_gid = parent_gid;

    if (text_buff_ucs2 != NULL)
    {
        OslMfree(text_buff_ucs2);
    }

    if (ucs2_addr != NULL)
    {
        OslMfree(ucs2_addr);
    }
#else /* __MMI_UNIFIED_COMPOSER__ */ 
    if ((mmi_sms_is_re_entry_send() == MMI_TRUE))
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);
    }
    else if (mmi_sms_is_sms_ready() == MMI_FALSE)
    {
        mmi_sms_display_popup_ext(
            STR_SMS_MSG_NOT_READY_YET,
            MMI_EVENT_FAILURE);
    }
    else
    {
        U16 invalid_num = 0;

        mmi_sms_reset_recipient_data();
    
        if (data->ascii_addr != NULL)
        {
            U32 addr_len;
            S8* ucs2_addr;

            addr_len = strlen((S8*)data->ascii_addr);
			if (0 == addr_len)
			{
				mmi_sms_display_popup_ext(
	                STR_GLOBAL_NO_NUMBER,
	                MMI_EVENT_FAILURE);
				return;
			}
            ucs2_addr = OslMalloc((addr_len + 1) * ENCODING_LENGTH);

            mmi_asc_to_ucs2(ucs2_addr, (S8*)data->ascii_addr);
        #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
            if (mmi_sms_add_recipient(NULL, ucs2_addr) == MMI_FALSE)
            {
                invalid_num = 1;
            }
        #else /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
            invalid_num = mmi_sms_add_addr_list_to_recipient(&ucs2_addr, 1);
        #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

            OslMfree(ucs2_addr);
        }

        if (invalid_num > 0)
        {
            mmi_sms_display_popup_ext(
                STR_GLOBAL_INVALID_NUMBER,
                MMI_EVENT_FAILURE);
        }
        else
        {
    #if (defined(__MMI_BT_MAP_CLIENT__) && !defined(__MMI_TELEPHONY_SUPPORT__))
        if(mmi_sms_get_send_msg_case() != SMS_SEND_CASE_EDIT_DRAFT)
    #endif
            mmi_sms_set_send_msg_case(SMS_SEND_CASE_WRITE_FROM_OTHER_APP);
        #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
        #endif /* __MMI_DUAL_SIM_MASTER__ */

            mmi_sms_group_entry(GRP_ID_ROOT);
            mmi_sms_pre_entry_editor();
        }
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
}


mmi_ret mmi_sms_api_send_msg_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_sms_is_sms_ready() == MMI_FALSE)
        #ifdef __MMI_TELEPHONY_SUPPORT__
        || (srv_sms_is_send_action_busy() == MMI_TRUE)
        #endif
        || (mmi_sms_api_send_parent_gid != GRP_ID_INVALID))
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);
    }
    else
    {
        srv_sms_event_api_send_msg_struct send_data;
        S8 ucs2_addr[(MMI_SMS_MAX_ADDR_LEN + 1) *ENCODING_LENGTH];
        U16 addr_len;
        S8 *content_buff;
        U16 content_buff_size;

        #ifdef __MMI_TELEPHONY_SUPPORT__
        S8 *sc_number;
        srv_sms_setting_struct default_setting;

        memcpy((S8*)&send_data, (S8*)event_data->event_info, sizeof(srv_sms_event_api_send_msg_struct));

        memcpy(&default_setting, srv_sms_get_default_setting(send_data.sim_id), sizeof(srv_sms_setting_struct));
        sc_number = default_setting.sc_addr;
        if (strlen((S8*)sc_number) == 0)
        {
            mmi_sms_display_popup_ext(
                STR_SMS_FAILURE_SC_NUM_EMPTY,
                MMI_EVENT_FAILURE);
            return MMI_RET_OK;
        }
        #endif/*__MMI_TELEPHONY_SUPPORT__*/
        content_buff_size = send_data.content_buff_size;
        if (content_buff_size > MMI_SMS_MAX_BUFF_SIZE)
        {
            content_buff_size = MMI_SMS_MAX_BUFF_SIZE;
        }
        content_buff = OslMalloc(content_buff_size);

        mmi_sms_api_send_parent_gid = mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_AUTO_GEN,
            mmi_sms_api_send_msg_proc,
            content_buff,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

        if (GRP_ID_INVALID == mmi_sms_api_send_parent_gid)
        {
            OslMfree(content_buff);
            return MMI_RET_OK;
        }

        mmi_sms_api_send_child_gid = cui_sms_send_create(mmi_sms_api_send_parent_gid);

        if (mmi_sms_api_send_child_gid != GRP_ID_INVALID)
        {
             addr_len = mmi_asc_n_to_ucs2(ucs2_addr, send_data.number, CUI_SMS_MAX_ADDR_LEN);
             if (addr_len > CUI_SMS_MAX_ADDR_LEN *ENCODING_LENGTH)
             {
                addr_len = CUI_SMS_MAX_ADDR_LEN *ENCODING_LENGTH;
             }
             ucs2_addr[addr_len] = '\0';
             ucs2_addr[addr_len + 1] = '\0';

            cui_sms_set_send_address(mmi_sms_api_send_child_gid, (U16**) &ucs2_addr, 1);

            memcpy(content_buff, (S8*)send_data.content_buff, content_buff_size);
            cui_sms_set_send_content_text(mmi_sms_api_send_child_gid, (U16*) content_buff, content_buff_size);

        #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
        #endif

            cui_sms_set_send_msg_case(mmi_sms_api_send_child_gid, CUI_SMS_SEND_CASE_SEND_FROM_OTHER_APP);

            cui_sms_set_send_type(mmi_sms_api_send_child_gid, SRV_SMS_FG_SEND);

            cui_sms_send_run(mmi_sms_api_send_child_gid);
        }
        else
        {
            mmi_frm_group_close(mmi_sms_api_send_parent_gid);
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_api_send_msg_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static mmi_ret mmi_sms_api_send_msg_proc(mmi_event_struct *evt)
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
            mmi_sms_api_send_child_gid = GRP_ID_INVALID;
            mmi_sms_api_send_parent_gid = GRP_ID_INVALID;
            break;

        case EVT_ID_CUI_SMS_SEND:
            {
                cui_evt_sms_send_struct *event = (cui_evt_sms_send_struct*)evt;
                if (event->is_send_finish)
                {
                    cui_sms_send_close(mmi_sms_api_send_child_gid);
                    mmi_frm_group_close(mmi_sms_api_send_parent_gid);
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
 *  mmi_sms_api_send_result_handler
 * DESCRIPTION
 *  Handler for applications to process post SMS request actions, such as
 *  display result popup, delete SMS framework screens, and enable SPOF
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_api_send_result_handler(mmi_sms_api_result_handler_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID title;
    mmi_event_notify_enum event_id = MMI_EVENT_FAILURE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_COMMON_TRC_G6_MSG,
        TRC_MMI_SMS_FRM_SMS_API_RESULT_HANDLER,
        result->display_popup,
        result->request_type,
        result->result,
        result->delete_sms_screen);

    if (result->display_popup)
    {
        switch (result->result)
        {
            case SRV_SMS_CAUSE_NO_ERROR:
                if (result->request_type == MMI_SMS_REQ_SEND)
                {
                    title = STR_GLOBAL_SENT;
                    event_id = MMI_EVENT_MESSAGE_SENT;
                }
                else if (result->request_type == MMI_SMS_REQ_SAVE)
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
                ReleaseEMSEditBuffer();
                title = STR_GLOBAL_MEMORY_FULL;
                break;

            case SRV_SMS_CAUSE_MEM_INSUFFICIENT:
                title = STR_GLOBAL_NOT_ENOUGH_MEMORY;
                break;
            case SRV_SMS_CAUSE_ERROR_FDN_ENABLED:
                title = STR_ID_SMS_FDN_FAIL;
                break;
            default:
                if (result->request_type == MMI_SMS_REQ_SAVE)
                {
                    title = STR_GLOBAL_FAILED_TO_SAVE;             
                }
                else
                {
                    title = STR_GLOBAL_FAILED_TO_SEND; 
                }
                break;
        }

        mmi_sms_display_popup_ext(
            title,
            event_id);     
    }
}
//#else
///TODO:
//void mmi_sms_write_msg_lanch(mmi_id parent_gid, mmi_sms_write_msg_para_struct *para)
//{}

//#endif /* __MMI_TELEPHONY_SUPPORT__ */

