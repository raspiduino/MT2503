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
 * UcAppInterface.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements .......... Unified Composer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_TELEPHONY_SUPPORT__

#ifndef _UNIFIED_COMPOSER_ENGINE_SRV_C
#define _UNIFIED_COMPOSER_ENGINE_SRV_C

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

//#include "Commonscreens.h"
#include "Custom_events_notify.h"
#include "SmsAppGprot.h"
#include "PhoneBookGprot.h"
#include "wapadp.h"
//#include "UmGprot.h"
#ifdef __MMI_MMS_2__
#include "MmsSrvGprot.h"
#endif
#include "UcSrvGprot.h"
#include "UcSrvIprot.h"
#include "UcAppGprot.h"
#include "FileMgrGProt.h"
#include "kal_public_api.h"
#include "UcAppProt.h"
#include "UcResDef.h"
//#include "custom_events_notify.h"
#ifdef J2ME_SHARE_MED_EXT_MEM
#include "med_api.h"
#include "med_mem.h"
#endif
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif
//suggested add
    #include "MMI_features.h"
    #include "MMIDataType.h"
    #include "wgui_categories_UCE.h"
   // #include "kal_general_types.h"
  //  #include "MMI_common_app_trc.h"
    #include "DebugInitDef_Int.h"
    //#include "kal_trace.h"
   // #include "mmi_common_app_trc.h"
    //#include "kal_public_api.h"
    #include "CustDataRes.h"
    #include "mmi_frm_events_gprot.h"
    #include "GlobalResDef.h"
    #include "gui_data_types.h"
    #include "AlertScreen.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "mma_api.h"
    #include "fs_type.h"
    #include "fs_func.h"
    #include "TimerEvents.h"
    #include "FileMgrSrvGProt.h"
    #include "UmSrvDefs.h"
    #include "mmi_frm_mem_gprot.h"
    #include "string.h"
    #include "Unicodexdcl.h"
    #include "gui_config.h"
    #include "app_mem.h"
    #include "SmsSrvGprot.h"
    #include "fs_errcode.h"
    #include "mms_api.h"
    #include "UmSrvGprot.h"
    //#include "mmi_rp_app_unifiedcomposer_def.h"
	#include "MessagesMiscell.h"

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_init
 * DESCRIPTION
 *  Initialize Unified Composer application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_init_context();
    //mmi_uc_set_protocol_event_handler();
#ifdef __MMI_UC_USE_ASM__
    mmi_uc_asm_register_app();
#else
    mmi_uc_create_adm_mem();
#endif /* __MMI_UC_USE_ASM__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_write_msg_with_content
 * DESCRIPTION
 *  Entry unified composer with content
 * PARAMETERS
 *  type        [IN]        
 *  data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_write_msg_with_content(mmi_uc_done_type_enum type, mmi_uc_entry_write_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 addr_num = 0;
    srv_uc_addr_struct *addr = data->addr;
    mma_mms_object_struct *object;
    wgui_uce_text_info_struct text_info;
    U8 *mmi_uc_text_path = NULL;
    S32 result;
    #ifndef __MMI_MMS_STANDALONE_COMPOSER__
    U16 msg_id = 0;
    #endif
    mmi_id group_id = 0;
    kal_uint32 current_tick_count ;
    kal_uint32 tick_count_at_start;
    kal_uint32 time_gap;
	U16 error_string = STR_GLOBAL_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_ENTRY_WRITE_MSG_WITH_CONTENT_P2, type, data->info_type);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_START_ENTRY_WRITE_MSG_WITH_CONTENT);
    kal_get_time(&tick_count_at_start);

#if defined(__MMI_MMS_STANDALONE_COMPOSER__)
    if (data->info_type == MMI_UC_INFO_TYPE_SMS)
    {
        MMI_ASSERT(0);
        return;
    }
#endif /* defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 

    if (!mmi_uc_is_uc_ready())
    {
        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE)), MMI_EVENT_FAILURE, NULL);
        mmi_uc_handle_progress_entry_composer_write_msg_on_fail();
        if (data->callback != NULL)
        {
            data->callback((void*)data->callback_para);
        }
		//if (!mmi_uc_is_uc_reenter())
		{
			mmi_frm_group_close (g_uc_p->main.uc_cui_gid);
			g_uc_p->main.uc_cui_gid = GRP_ID_INVALID;
		}
        return;
    }

    if (mmi_uc_is_uc_reenter())
    {
        //mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)), MMI_EVENT_FAILURE, NULL);

        mmi_uc_write_msg_delete_history_hdlr(NULL);
        //return;
    }

    if (g_uc_p->srv_send_info->action == SRV_UC_ACTION_SAVE_IN_BACKGROUND)
    {
        //g_uc_p->main.callback_id = parent_cui_gid;

        g_uc_p->main.operation_reentry = (uc_confirm_func_ptr)mmi_uc_entry_write_msg_with_content;

        mmi_uc_copy_reentry_struct(type, data);

        if (g_uc_p->main.reentry_struct != NULL)

        {

        mmi_uc_show_progress_in_reentry(0);

       StartTimer(
                                UC_CREATE_RSP_REENTRY_RETRY_TIMER_ID,
                                MMI_UC_CREATE_RSP_REENTRY_RETRY_TIME,
                                mmi_uc_create_msg_rsp_timeout_callback);
        }
       
       return;
    }

    

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode() && mma_is_storage_exported_to_pc())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*) SRV_UC_FOLDER_DRV))
        {
            /* MMI public drive is exported, cannot use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            mmi_uc_handle_progress_entry_composer_write_msg_on_fail();
            if (data->callback != NULL)
            {
                data->callback((void*)data->callback_para);
            }
			mmi_frm_group_close (g_uc_p->main.uc_cui_gid);
			g_uc_p->main.uc_cui_gid = GRP_ID_INVALID;
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

#ifdef __MMI_MMS_POSTCARD__
    if (data->info_type == MMI_UC_INFO_TYPE_POSTCARD_MMS)
    {
        g_uc_p->srv_msg_type->MMS_edit_mode = MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS;
    }
    else
    {
        g_uc_p->srv_msg_type->MMS_edit_mode = MMI_UC_MMS_EDIT_MODE_NORMAL_MMS;
    }
#endif /* __MMI_MMS_POSTCARD__ */ 
#ifdef __MMI_OP02_LEMEI__
    if (data->info_type == MMI_UC_INFO_TYPE_LEMEI_MMS)
     {
      g_uc_p->srv_msg_type->MMS_edit_mode = MMI_UC_MMS_EDIT_MODE_LEMEI_MMS;    
     }
#endif
    /* if caller only give one phone number, and the number exceed its max digit limitaton, popup here */
    /* if there are many addresses, will continue, but the number which exceed number digit limitation will not be added */
    if (data->get_address_callback)
    {
        // Skip here do operation later */
        /* Addr should be NULL if there is callback register for getting input. */
        MMI_ASSERT(data->addr == NULL);
    }
    else
    {
        if (data->addr_num == 1)
        {
            U16 string_id = mmi_uc_entry_validation_checks_for_recipient(data->addr);

            if (string_id != STR_GLOBAL_OK)
            {
                mmi_popup_display((WCHAR*)((UI_string_type) GetString(string_id)), MMI_EVENT_ERROR, NULL);
                mmi_uc_handle_progress_entry_composer_write_msg_on_fail();
                #ifdef __MMI_FTE_SUPPORT__
                    //DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                mmi_frm_scrn_close (g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
                #endif
                if (data->callback != NULL)
                {
                    data->callback((void*)data->callback_para);
                }
				mmi_frm_group_close (g_uc_p->main.uc_cui_gid);
				g_uc_p->main.uc_cui_gid = GRP_ID_INVALID;
                return;
            }
        }
    }
    if (type != MMI_UC_STATE_WRITE_NEW_MSG)
    {
    #ifndef __MMI_MMS_STANDALONE_COMPOSER__
        if (data->info_type == MMI_UC_INFO_TYPE_SMS)
        {
            msg_id = *((U16*)data->info);
        }
    #endif
    }
    if (mmi_frm_group_get_active_id() == g_uc_p->main.uc_cui_gid &&  g_uc_p->main.uc_cui_gid == GRP_ID_UNIFIED_COMPOSER)
    {
        group_id = g_uc_p->main.uc_cui_gid;
        g_uc_p->main.uc_cui_gid = GRP_ID_INVALID;
    }
	else 
	{
		mmi_frm_group_close (g_uc_p->main.uc_cui_gid);
		g_uc_p->main.uc_cui_gid = GRP_ID_INVALID;
	}
#ifdef __MMI_UC_USE_ASM__
    if (!(g_uc_p->main.entry_struct && g_uc_p->main.entry_struct->file_path))
#endif /* __MMI_UC_USE_ASM__ */
    {
        mmi_uc_reset_msg();
    }

    result = srv_uc_check_uc_folder(g_uc_p->main.instance);

    if (result < 0)
    {
        mmi_popup_display((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(result))), MMI_EVENT_FAILURE, NULL);
        mmi_uc_handle_progress_entry_composer_write_msg_on_fail();
        if (data->callback != NULL)
        {
            data->callback((void*)data->callback_para);
        }
		mmi_frm_group_close (g_uc_p->main.uc_cui_gid);
		mmi_frm_group_close (group_id);
		group_id = GRP_ID_INVALID;
		g_uc_p->main.uc_cui_gid = GRP_ID_INVALID;
        return;
    }
#ifdef __MMI_UC_USE_ASM__
    if(!mmi_uc_alloc_asm_pool_with_content(type, data))
    {
        //mmi_uc_copy_entry_struct(type, data);
        return;
    }
#endif /* __MMI_UC_USE_ASM__ */

    g_uc_p->srv_main->state = type;
    g_uc_p->send_info.highlight_sim_id = srv_uc_convert_sim_id(data->sim_id);

    if (type != MMI_UC_STATE_WRITE_NEW_MSG)
    {
    #ifndef __MMI_MMS_STANDALONE_COMPOSER__
        if (data->info_type == MMI_UC_INFO_TYPE_SMS)
        {

            if (g_uc_p->srv_main->state == MMI_UC_STATE_FORWARD)
            {
                g_uc_p->srv_main->state = MMI_UC_STATE_EDIT_EXISTED_MSG;
            }
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            /* Treat edit archive box SMS msg as write new msg. */
            if ((g_uc_p->srv_main->state == MMI_UC_STATE_EDIT_EXISTED_MSG) &&
                (SRV_UM_MSG_BOX_ARCHIVE == mmi_msg_get_um_type_by_msgid((U32)msg_id)))
            {
                g_uc_p->srv_main->state = MMI_UC_STATE_WRITE_NEW_MSG;
            }
            else
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
            {
                g_uc_p->srv_send_info->existed_msg_type = MMI_UC_MSG_TYPE_SMS_PREFER;
                g_uc_p->srv_send_info->existed_msg_id = msg_id;
            }
        }
        else
        {
            MMI_ASSERT(0);
        }
    #else /* __MMI_MMS_STANDALONE_COMPOSER__ */ 
        MMI_ASSERT(0);
    #endif /* __MMI_MMS_STANDALONE_COMPOSER__ */ 
    }

    for (; addr_num < data->addr_num; addr_num++)
    {
        srv_uc_addr_struct *addr_node = NULL;

        if (data->get_address_callback)
        {
            kal_int8 *temp_address_string = NULL;
            S32 str_length = 0;
            U16 address_type = 0;

            MMI_ASSERT(addr == NULL);
            addr_node = OslMalloc(sizeof(srv_uc_addr_struct));
            memset(addr_node, 0, sizeof(srv_uc_addr_struct));
            temp_address_string = data->get_address_callback((kal_uint16) addr_num, &address_type);
            str_length = mmi_ucs2strlen((S8*) temp_address_string);
            addr_node->addr = OslMalloc((str_length + 1) * ENCODING_LENGTH);
            memset(addr_node->addr, 0, (str_length + 1) * ENCODING_LENGTH);
            memcpy(addr_node->addr, temp_address_string, (str_length + 1) * ENCODING_LENGTH);
            addr_node->type =
                (address_type ==
                 MMI_PHB_ADDRESS_TYPE_NUMBER) ? MMI_UC_ADDRESS_TYPE_PHONE_NUMBER : MMI_UC_ADDRESS_TYPE_EMAIL;
            addr_node->group = MMI_UC_ADDRESS_GROUP_TYPE_TO;
            addr = addr_node;
        }

        MMI_ASSERT(addr);
        /* because pbh has valid number +(40 digit), but current UC only handle 40 digits or +(39 digits)
           so if the total digit > 40, will not allow user to add, because intercept number is meaningless */
        if (data->addr_num == 1)
        {
            U16 local_flag = mmi_uc_entry_validation_checks_for_recipient(addr);

            if (local_flag != STR_GLOBAL_OK)
            {
                mmi_popup_display((WCHAR*)((UI_string_type) GetString(local_flag)), MMI_EVENT_ERROR, NULL);
                if (addr_node)
                {
                    OslMfree(addr_node->addr);
                    OslMfree(addr_node);
                    addr_node = NULL;
                }
                if (data->callback != NULL)
                {
                    data->callback((void*)data->callback_para);
                }
				mmi_frm_group_close (g_uc_p->main.uc_cui_gid);
				mmi_frm_group_close (group_id);
				group_id = GRP_ID_INVALID;
				g_uc_p->main.uc_cui_gid = GRP_ID_INVALID;
                return;
            }
        }
        if (mmi_uc_entry_validation_checks_for_recipient(addr) != STR_GLOBAL_OK)
        {
            /* will not added without showing popup */
			error_string = STR_ID_UC_INVALID_RECIPIENTS_REMOVED;
        }
        else
        {
            srv_uc_add_address(g_uc_p->main.instance, addr->addr, addr->type, addr->group);
        }
        if ((g_uc_p->srv_msg->to_num) >= SRV_UC_MAX_ADDRESS_NUM)
        {
            /* the recipient limitation is SRV_UC_MAX_ADDRESS_NUM */
            break;
        }
        addr = addr->next;
        if (addr_node)
        {
            OslMfree(addr_node->addr);
            OslMfree(addr_node);
            addr_node = NULL;
        }
    }

	if (g_uc_p->srv_msg->to_num == 0 && error_string != STR_GLOBAL_OK)
	{
		error_string = STR_GLOBAL_INVALID_RECIPIENTS;
	}

    g_uc_p->srv_msg->msg_body.curr_slide= srv_uc_insert_slide(g_uc_p->main.instance, NULL);
    g_uc_p->srv_msg->current_slide_num = g_uc_p->srv_msg->msg_body.curr_slide->slide_num;

    memset(g_uc_p->srv_msg->subject, 0, sizeof(g_uc_p->srv_msg->subject));
    if (mmi_ucs2strlen((S8*) data->subject))
    {
        mmi_ucs2ncpy((S8*) g_uc_p->srv_msg->subject, (S8*) data->subject, MMI_UC_MAX_SUBJECT_LEN);
    }

    /* text file */
    if (data->text_num)
    {
#ifdef __MMI_UC_USE_ASM__
        if (g_uc_p->main.entry_struct && g_uc_p->main.entry_struct->file_path)
        {
            srv_uc_read_file_to_text_buffer(g_uc_p->main.instance, g_uc_p->main.entry_struct->file_path, MMA_CHARSET_UTF8);
        }
        else
#endif /* __MMI_UC_USE_ASM__ */
        {
            U32 buffer_size = 0;
            U8 *buffer = NULL;
            U32 buffer_len = 0;

            /* Discard the exceeding part */
            if (data->text_num > SRV_UC_MAX_CHAR_NUM_IN_ONE_SLIDE)
            {
                data->text_num = SRV_UC_MAX_CHAR_NUM_IN_ONE_SLIDE;
            }
            if (data->msg_type == MMI_UC_MSG_TYPE_SMS_ONLY && data->text_num > MMI_UC_MAX_SMS_CONTENT)
            {
                data->text_num = MMI_UC_MAX_SMS_CONTENT;
            }

            buffer_size = (data->text_num + 1) * ENCODING_LENGTH;
            buffer = applib_mem_screen_alloc(buffer_size);

            MMI_ASSERT(buffer_size <= MMI_UC_UTF8_TEXT_BUFFER_SIZE);

            memset(buffer, 0, buffer_size);
            srv_sms_remove_escape_char(
                (S8*) buffer,
                (S8*) data->text_buffer,
                (U16) data->text_num);
            buffer_len = mmi_ucs2strlen((S8*) buffer);

            srv_uc_reset_text_buffer(g_uc_p->main.instance);
            if (buffer_len <= (SRV_UC_TEXT_BUFFER_SIZE / ENCODING_LENGTH) - 1)
            {
                mmi_ucs2ncpy((S8*) g_uc_p->srv_main->text_buffer, (S8*) buffer, buffer_len);
            }
            else
            {
                mmi_ucs2ncpy(
                    (S8*) g_uc_p->srv_main->text_buffer,
                    (S8*) buffer,
                    (SRV_UC_TEXT_BUFFER_SIZE / ENCODING_LENGTH) - 1);
            }

            applib_mem_screen_free(buffer);
        }

        mmi_uc_text_path = OslMalloc(SRV_UC_MAX_TEMP_FILE_LEN);
        memset(mmi_uc_text_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);
        SRV_UC_MAKE_TEXT_FILE_PATH(mmi_uc_text_path, g_uc_p->srv_msg->msg_body.curr_slide->slide_num, g_uc_p->main.instance);

        mmi_uc_editor_initialize();
    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        mmi_uc_recipient_initialize();
    #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
        memset(&text_info, 0, sizeof(wgui_uce_text_info_struct));
        wgui_uce_get_text_info_for_buffer(&text_info, g_uc_p->srv_main->text_buffer);

        result = srv_uc_save_buffer_to_file(
                    g_uc_p->main.instance,
                    mmi_uc_text_path,
                    g_uc_p->srv_main->text_buffer,
                    text_info.char_count);

        if (result == FS_NO_ERROR)
        {
            mmi_uc_set_text_info_to_slide(g_uc_p->srv_msg->msg_body.curr_slide, &text_info);

            object = srv_uc_insert_object(g_uc_p->main.instance, (S8*) mmi_uc_text_path, SRV_UC_OBJECT_TYPE_TEXT);
            srv_uc_insert_object_to_slide(
                g_uc_p->main.instance,
                object,
                g_uc_p->srv_msg->msg_body.curr_slide,
                SRV_UC_OBJECT_TYPE_TEXT);
            g_uc_p->srv_msg->msg_body.curr_slide->txt.object->encoding = MMA_CHARSET_UTF8;   /* because the text's encode already UTF8 when mmi_uc_save_buffer_to_file to file */
        }
        else
        {
            mmi_uc_display_popup(SRV_UC_STORAGE_FULL);

            if (data->callback != NULL)
            {
                data->callback((void*)data->callback_para);
            }
            OslMfree(mmi_uc_text_path);
            mmi_uc_text_path = NULL;
			mmi_frm_group_close(g_uc_p->main.uc_cui_gid);
			mmi_frm_group_close(group_id);
			g_uc_p->main.uc_cui_gid = GRP_ID_INVALID;
            return;
        }
        OslMfree(mmi_uc_text_path);
        mmi_uc_text_path = NULL;
    }

    srv_uc_update_msg_size(g_uc_p->main.instance);

    if (data->info_type == MMI_UC_INFO_TYPE_SMS)
    {
        MMI_ASSERT(data->file_path == NULL);
    }

    if (data->file_path)
    {
        U32 flie_path_len = mmi_ucs2strlen((S8*) data->file_path);

        if (g_uc_p->srv_main->file_path)
        {
            kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->srv_main->file_path);
        }

        g_uc_p->srv_main->file_path = kal_adm_alloc(g_uc_p->main.mem_pool_id, (flie_path_len + 1) * ENCODING_LENGTH);

        MMI_ASSERT(g_uc_p->srv_main->file_path);

        mmi_ucs2ncpy((S8*) g_uc_p->srv_main->file_path, (S8*) data->file_path, flie_path_len);
    }
	/*For DCD Added*/
	if(data->get_img_callback)
	{
			g_uc_p->srv_msg->get_media_callback = data->get_img_callback ;
			g_uc_p->srv_msg->media_count = data->media_num ;
	}

    if (data->callback != NULL)
    {
        g_uc_p->main.callback = data->callback;
        g_uc_p->main.callback_para = data->callback_para;
    }

    g_uc_p->srv_msg_type->setting_msg_type = srv_uc_get_setting_msg_type();
    g_uc_p->srv_msg_type->curr_msg_type = g_uc_p->srv_msg_type->setting_msg_type;

    if (data->msg_type == MMI_UC_MSG_TYPE_SMS_ONLY)
    {
        g_uc_p->srv_msg_type->curr_msg_type = MMI_UC_MSG_TYPE_SMS_PREFER;
    }
    else if (data->msg_type == MMI_UC_MSG_TYPE_MMS_ONLY)
    {
        g_uc_p->srv_msg_type->curr_msg_type = MMI_UC_MSG_TYPE_MMS_PREFER;
    }

    g_uc_p->srv_msg_type->caller_specific_msg_type = data->msg_type;
#ifdef __MMI_MMS_STANDALONE_COMPOSER__
    g_uc_p->srv_msg_type->caller_specific_msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;

#endif /* __MMI_MMS_STANDALONE_COMPOSER__ */ 
    g_uc_p->srv_msg_type->backup_msg_type = MMI_UC_MSG_TYPE_DEFAULT;
    if (group_id == 0)
    {
        g_uc_p->main.uc_cui_gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_UNIFIED_COMPOSER, mmi_uc_editor_proc, NULL);
        mmi_frm_group_enter(g_uc_p->main.uc_cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    else
    {
        g_uc_p->main.uc_cui_gid = group_id;
    }
    mmi_uc_process_entry_write_msg();

	kal_get_time(&current_tick_count);
	time_gap = (current_tick_count)-(tick_count_at_start);
	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_EXIT_ENTRY_WRITE_MSG_WITH_CONTENT,time_gap);

	if (error_string != STR_GLOBAL_OK)
	{
		mmi_popup_display((WCHAR*)((UI_string_type) GetString(error_string)), MMI_EVENT_ERROR, NULL);
	}

    if(g_uc_p->main.reentry_struct)
    {
        mmi_uc_free_reentry_struct();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_mms_from_previewer
 * DESCRIPTION
 *  when user select send item in previewer screen
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void mmi_uc_send_mms_from_previewer(mmi_uc_sim_id sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->srv_send_info->send_sim_id = srv_uc_convert_sim_id(sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_edit_mms_content_from_previewer
 * DESCRIPTION
 *  when user select edit item in previewer screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void mmi_uc_edit_mms_content_from_previewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__

    g_uc_p->srv_send_info->action = SRV_UC_ACTION_IDLE;
    g_uc_p->send_info.abort = MMI_UC_ABORT_NONE;
	mmi_frm_group_close(g_uc_p->main.mms_cui_gid);
	mmi_frm_group_close(APPLIB_MEM_AP_ID_UNIFIED_COMPOSER);
	if (g_uc_p->srv_send_info->new_msg_id)
	{
		mmi_uc_delete_mms_req(g_uc_p->srv_send_info->new_msg_id, g_uc_p->send_info.new_msg_storage);
		g_uc_p->srv_send_info->new_msg_id = 0;
	}

#else
    /* reset */
    g_uc_p->srv_send_info->action = SRV_UC_ACTION_IDLE;
    g_uc_p->send_info.abort = MMI_UC_ABORT_NONE;
    mmi_uc_entry_add_recipient();
	mmi_frm_group_close(g_uc_p->main.mms_cui_gid);
	mmi_frm_group_close(APPLIB_MEM_AP_ID_UNIFIED_COMPOSER);
	if (g_uc_p->srv_send_info->new_msg_id)
	{
		mmi_uc_delete_mms_req(g_uc_p->srv_send_info->new_msg_id, g_uc_p->send_info.new_msg_storage);
		g_uc_p->srv_send_info->new_msg_id = 0;
	}
#endif /* #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_send_message_menu_hidden
 * DESCRIPTION
 *  This API will be for other App use to show
 *  direct launch UC option or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_uc_is_send_message_menu_hidden(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0
#ifdef __MMI_MMS__
        || mms_hide_send_mms_menu() == KAL_TRUE
#endif 
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
        || srv_sms_is_hide_send_sms_menu_item() == TRUE
#endif 
        )
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_pending_action
 * DESCRIPTION
 *  Check if uc has pending action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern kal_bool mmi_uc_is_pending_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_uc_is_pending_action(g_uc_p->main.instance);
}

#ifdef __MMI_MMS__


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_mms_ready_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_uc_mms_ready_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_mms_ready;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_mms_ready = (MMI_BOOL)mms_is_ready();
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_IS_MMS_READY_P1, is_mms_ready);
    return is_mms_ready;
}
#endif /* __MMI_MMS__ */ 

#ifndef __MMI_MMS_STANDALONE_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_sms_ready_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_uc_sms_ready_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_sms_ready;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_sms_ready = mmi_sms_is_sms_ready();
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_IS_SMS_READY_P1, is_sms_ready);
    return is_sms_ready;
}
#endif /* __MMI_MMS_STANDALONE_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_uc_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_uc_is_uc_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_IS_UC_READY);
    if (srv_um_check_ready()
#ifdef __MMI_MMS__
        && mmi_uc_mms_ready_check()
#endif 
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
        && mmi_uc_sms_ready_check()
#endif 
        )
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_IS_UC_READY_P1, 1);
        return MMI_TRUE;
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_IS_UC_READY_P1, 0);
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_mms_reenter_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_uc_is_mms_reenter_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_mms_reenter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_mms_reenter = (MMI_BOOL)(!mms_is_reentrant());
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_IS_MMS_REENTER_P1, is_mms_reenter);
    return is_mms_reenter;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_uc_reenter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_uc_is_uc_reenter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 is_reentry = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_IS_UC_REENTER);
    if (mmi_uc_is_uc_screen_in_history() || mmi_uc_is_pending_action() || mmi_uc_is_mms_reenter_check()
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
    #ifndef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        || srv_sms_is_send_action_busy()
    #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
#endif 
        )
    {
        is_reentry = MMI_TRUE;
    }

    if (is_reentry)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_IS_UC_REENTER_P1, 1);
        return MMI_TRUE;
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_IS_UC_REENTER_P1, 0);
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_launch
 * DESCRIPTION
 *  API to start UC
 * PARAMETERS
 *  msg_req     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_uc_launch(mmi_uc_start_struct *msg_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id group_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_uc_is_uc_screen_alraedy_present())
    {
        return MMA_RESULT_FAIL_BUSY;
    }
    else
    {
        if (g_uc_p->main.uc_cui_gid == GRP_ID_UNIFIED_COMPOSER)
        {
            group_id = g_uc_p->main.uc_cui_gid;
            mmi_frm_group_enter(group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
            g_uc_p->main.uc_cui_gid = GRP_ID_INVALID;
        }
        else
        {
            group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_UNIFIED_COMPOSER, mmi_uc_editor_proc, NULL);
            mmi_frm_group_enter(group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        }

        mmi_uc_reset_msg();
        g_uc_p->main.uc_cui_gid = group_id;
        g_uc_p->srv_main->state = (srv_uc_state_enum)srv_uc_convert_mms_app_mode_to_uc_state(msg_req->mode);
        if (g_uc_p->srv_main->state == MMI_UC_STATE_FORWARD)
        {
            g_uc_p->srv_main->mode = SRV_UC_FORWARD_WITHOUT_EDIT_MODE;
            g_uc_p->srv_main->state = MMI_UC_STATE_EDIT_EXISTED_MSG;
        }
        else if (g_uc_p->srv_main->state == MMI_UC_STATE_SEND)
        {
            g_uc_p->send_info.curr_folder = (U16) mma_get_box(msg_req->msg_id);
    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
            g_uc_p->srv_main->mode = SRV_UC_SEND_WITHOUT_EDIT_MODE;
            g_uc_p->srv_main->state = MMI_UC_STATE_EDIT_EXISTED_MSG;
    #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
        }
        g_uc_p->srv_send_info->existed_msg_id = msg_req->msg_id;
        g_uc_p->send_info.existed_msg_storage = (mma_msg_storage_type_enum) msg_req->curr_storage;
        g_uc_p->srv_send_info->existed_msg_type = MMI_UC_MSG_TYPE_MMS_PREFER;
        g_uc_p->send_info.highlight_sim_id = srv_uc_convert_sim_id((srv_uc_sim_id)(msg_req->sim_id));

        g_uc_p->srv_msg_type->setting_msg_type = srv_uc_get_setting_msg_type();
        g_uc_p->srv_msg_type->curr_msg_type = g_uc_p->srv_msg_type->setting_msg_type;
    #ifdef __MMI_MMS_STANDALONE_COMPOSER__
        g_uc_p->srv_msg_type->caller_specific_msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
    #else 
        g_uc_p->srv_msg_type->caller_specific_msg_type = MMI_UC_MSG_TYPE_DEFAULT;
    #endif 
        g_uc_p->srv_msg_type->backup_msg_type = MMI_UC_MSG_TYPE_DEFAULT;

    #ifdef __MMI_MMS_POSTCARD__
        g_uc_p->srv_msg_type->MMS_edit_mode = msg_req->edit_mode;
        if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
        {
            g_uc_p->srv_msg_type->caller_specific_msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
        }
    #endif /* __MMI_MMS_POSTCARD__ */ 
    #ifdef __MMI_OP01_202_MMS_REPLY_BY_SMS_MMS_SUPPORT__
        /* To make sure Reply by MMS. */
        if (g_uc_p->srv_main->state == MMI_UC_STATE_REPLY || g_uc_p->srv_main->state == MMI_UC_STATE_REPLY_ALL)
        {
            g_uc_p->srv_msg_type->curr_msg_type = MMI_UC_MSG_TYPE_MMS_PREFER;
            g_uc_p->srv_msg_type->caller_specific_msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
        }
    #endif /* __MMI_OP01_202_MMS_REPLY_BY_SMS_MMS_SUPPORT__ */ 
        mmi_uc_process_entry_write_msg();
        return MMA_RESULT_OK;
    }

    //return MMA_RESULT_FAIL_BUSY;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_allow_postcard_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_uc_is_allow_postcard_process(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(mmi_uc_is_uc_ready()) || mmi_uc_is_uc_reenter())
    {
        return MMI_FALSE;
    }

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode() && mma_is_storage_exported_to_pc())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*) SRV_UC_FOLDER_DRV))
        {
            /* MMI public drive is exported, cannot use this app */
            return MMI_FALSE;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_mms_in_use
 * DESCRIPTION
 *  Check if the msg_id is in used (highlight on it, this will aslo can cover UC,
 *  because before enter UC, need to select one msg)
 *  Why UC need provide this only for Q05A, it's because different mms slution has
 *  different architecture.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mmi_uc_is_mms_in_use(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_uc_is_mms_in_use(msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_sms_in_use
 * DESCRIPTION
 *  Check if the msg_id is in used (Other application need to check for this before use a msg.
 *  Because same message can not be used by two applications simultaneously)
 *  msg_id : [IN] Msg id.
 * RETURNS
 *  KAL_FALSE  : Not in use.
 *  KAL_TRUE  : In use.
 *****************************************************************************/
kal_bool mmi_uc_is_sms_in_use(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_uc_is_sms_in_use(g_uc_p->main.instance, msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_no_recepient
 * DESCRIPTION
 *  return T if there is no recepient
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_uc_is_no_recepient(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_uc_is_no_recepient(g_uc_p->main.instance);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_msg_operation_launch
 * DESCRIPTION
 *  Api to launch the operation via UC over a SMS, MMS or Postcard
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE:   Success
 *  MMI_FALSE:  Failure
 *****************************************************************************/
MMI_BOOL mmi_uc_entry_msg_operation_launch( U32 msg_id, U16 msg_type, mmi_uc_msg_operation_enum operation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MMS_STANDALONE_COMPOSER__)       
    if (msg_type == MMI_UC_INFO_TYPE_SMS)
    {
        MMI_ASSERT(0);
        return MMI_FALSE;
    }
#endif    

    if (!(mmi_uc_is_uc_ready())|| mmi_uc_is_uc_reenter())
    {
        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE)), MMI_EVENT_FAILURE, NULL);
        return MMI_FALSE;
    }

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode()
         && mma_is_storage_exported_to_pc())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*) SRV_UC_FOLDER_DRV))
        {
            /* MMI public drive is exported, cannot use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return MMI_FALSE;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */
    if (g_uc_p->main.uc_cui_gid != GRP_ID_UNIFIED_COMPOSER)
    {
        g_uc_p->main.uc_cui_gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_UNIFIED_COMPOSER, mmi_uc_editor_proc, NULL);
        mmi_frm_group_enter(g_uc_p->main.uc_cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    else
    {
        mmi_frm_group_enter(g_uc_p->main.uc_cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    mmi_uc_show_progress_entry_composer_write_msg();
    switch(msg_type)
    {
        extern MMI_BOOL mmi_uc_sms_msg_operation_trigger(U32 msg_id, mmi_uc_msg_operation_enum operation);
     #ifndef __MMI_MMS_STANDALONE_COMPOSER__       
        case MMI_UC_INFO_TYPE_SMS:
            result = mmi_uc_sms_msg_operation_trigger(msg_id, operation);
            break;
    #endif
        case MMI_UC_INFO_TYPE_MMS:
    #ifdef __MMI_MMS_POSTCARD__
        case MMI_UC_INFO_TYPE_POSTCARD_MMS:
    #endif
          //  result = mmi_umms_msg_operation_trigger(msg_id, operation);
            break;
        default:
            ASSERT(0);
            break;
    }
    if(result == MMI_FALSE)
    {
        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE)), MMI_EVENT_FAILURE, NULL);
        mmi_frm_scrn_close (g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
    }
    return result;
}

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
mmi_ret mmi_uc_sd_card_plug_in_hdlr_cb(mmi_event_struct *param)
{
	U8 i = 0;
	U8 drive_counter = 0;
	srv_fmgr_notification_dev_plug_event_struct *plug_in_info;
	switch(param->evt_id)
	{
		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
			
			plug_in_info = (srv_fmgr_notification_dev_plug_event_struct*)param;

			for (i = 0; i < plug_in_info->count; i++)
			{
				if (plug_in_info->drv_letters[i] == SRV_FMGR_CARD_DRV)
				{
					drive_counter++;
				}
			}
			if(drive_counter)
			{
				mmi_uc_sd_plug_in_hdlr();
			}
			
			break;
	}
	return MMI_RET_OK;
	
}
#endif

mmi_ret mmi_uc_sd_card_plug_out_hdlr_cb (mmi_event_struct *param)
{
	U8 i = 0;
	U8 drive_counter = 0;
	srv_fmgr_notification_dev_plug_event_struct *plug_in_info;
	switch(param->evt_id)
	{
		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
			
			plug_in_info = (srv_fmgr_notification_dev_plug_event_struct*)param;

			for (i = 0; i < plug_in_info->count; i++)
			{
				if (plug_in_info->drv_letters[i] == SRV_FMGR_CARD_DRV)
				{
					drive_counter++;
				}
			}
			if(drive_counter)
			{
				mmi_uc_sd_plug_out_hdlr();
			}
			
			break;
	}
	return MMI_RET_OK;
}

#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */ 
#endif /* _UNIFIED_COMPOSER_ENGINE_SRV_C */ /* _MMI_UNIFIED_COMPOSER_MAIN_C */

#endif /* __MMI_TELEPHONY_SUPPORT__ */
