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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifndef _UNIFIED_COMPOSER_ENGINE_SRV_C
#define _UNIFIED_COMPOSER_ENGINE_SRV_C

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))


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
//void mmi_uc_entry_write_msg_with_content(mmi_uc_done_type_enum type, mmi_uc_entry_write_struct *data)
void mmi_uc_entry_write_msg_with_content(U32 type, void *data)
{
    return;
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
//void mmi_uc_send_mms_from_previewer(mmi_uc_sim_id sim_id)
void mmi_uc_send_mms_from_previewer(U32 sim_id)
{
    return;
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
    return;
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
    return MMI_TRUE;
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
kal_bool mmi_uc_is_pending_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
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
    return MMI_TRUE;
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
    return MMI_TRUE;
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
    return MMI_TRUE;
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
    return MMI_TRUE;
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
    return MMI_TRUE;
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
//U32 mmi_uc_launch(mmi_uc_start_struct *msg_req)
U32 mmi_uc_launch(void *msg_req)
{
    return 0;
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
kal_bool mmi_uc_is_mms_in_use(U32 msg_id)
{
    return KAL_FALSE;
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
kal_bool mmi_uc_is_sms_in_use(U32 msg_id)
{
    return KAL_FALSE;
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
    return TRUE;
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
//MMI_BOOL mmi_uc_entry_msg_operation_launch( U32 msg_id, U16 msg_type, mmi_uc_msg_operation_enum operation)
MMI_BOOL mmi_uc_entry_msg_operation_launch(U32 msg_id, U16 msg_type, U32 operation)
{
    return MMI_TRUE;
}


#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
mmi_ret mmi_uc_sd_card_plug_in_hdlr_cb(mmi_event_struct *param)
{
	return MMI_RET_OK;	
}
#endif

mmi_ret mmi_uc_sd_card_plug_out_hdlr_cb (mmi_event_struct *param)
{
	return MMI_RET_OK;
}

void cui_uc_write_msg_launch(mmi_id parent_grp_id)
{
    return;
}

void cui_uc_write_msg_close(mmi_id cui_gid)
{
    return;
}

mmi_ret cui_uc_group_proc(mmi_event_struct *evt)
{
	return MMI_RET_OK;
}

mmi_id cui_uc_write_msg_create(mmi_id parent_gid)
{
    return (U16)0;
}

void cui_uc_write_msg_with_content_launch(U16 parent_cui_gid, U32 type, void *data)
{
    return;
}

U32 cui_uc_write_msg_from_mms_launch(U16 parent_cui_gid, void *msg_req)
{
   return MMI_FALSE;
}

MMI_BOOL cui_uc_entry_msg_operation_launch( U16 parent_cui_gid, U32 msg_id, U16 msg_type, U32 operation)
{
   return MMI_FALSE;
}

mmi_ret mmi_uc_handle_sms_msg_del_event(mmi_event_struct *event_data)
{
	return MMI_RET_OK;
}

mmi_ret mmi_uc_force_close(mmi_event_struct *evt)
{
	return MMI_RET_OK;
}

mmi_ret mmi_uc_usb_ms_plug_in_hdlr(mmi_event_struct *evt)
{
	return MMI_RET_OK;
}

void mmi_uc_highlight_send(void)
{
    return;
}

void mmi_uc_highlight_opt_send_to(void)
{
    return;
}

void mmi_uc_highlight_opt_text_options(void)
{
    return;
}

void mmi_uc_highlight_slide_opt_text_timing(void)
{
    return;
}

void mmi_uc_highlight_opt_picture_options(void)
{
    return;
}

void mmi_uc_highlight_opt_edit_image(void)
{
    return;
}

void mmi_uc_highlight_slide_opt_image_timing(void)
{
    return;
}

void mmi_uc_highlight_remove_image(void)
{
    return;
}

void mmi_uc_highlight_replace_image(void)
{
    return;
}

void mmi_uc_highlight_opt_sound_options(void)
{
    return;
}

void mmi_uc_highlight_slide_opt_audio_timing(void)
{
    return;
}

void mmi_uc_highlight_remove_audio(void)
{
    return;
}

void mmi_uc_highlight_replace_audio(void)
{
    return;
}

void mmi_uc_highlight_opt_video_options(void)
{
    return;
}

void mmi_uc_highlight_slide_opt_video_timing(void)
{
    return;
}

void mmi_uc_highlight_opt_attachment_options(void)
{
    return;
}

void mmi_uc_highlight_remove_attachment(void)
{
    return;
}

void mmi_uc_highlight_replace_attachment(void)
{
    return;
}

void mmi_uc_highlight_opt_add_picture(void)
{
    return;
}

void mmi_uc_highlight_insert_image(void)
{
    return;
}

void mmi_uc_highlight_insert_new_image(void)
{
    return;
}

void mmi_uc_highlight_opt_add_sound(void)
{
    return;
}

void mmi_uc_highlight_insert_audio(void)
{
    return;
}

void mmi_uc_highlight_insert_new_audio(void)
{
    return;
}

void mmi_uc_highlight_opt_add_video(void)
{
    return;
}

void mmi_uc_highlight_insert_video(void)
{
    return;
}

void mmi_uc_highlight_insert_new_video(void)
{
    return;
}

void mmi_uc_highlight_opt_add_subject(void)
{
    return;
}

void mmi_uc_highlight_opt_preview(void)
{
    return;
}

void mmi_uc_highlight_opt_slide_opt(void)
{
    return;
}

void mmi_uc_highlight_slide_opt_insert(void)
{
    return;
}

void mmi_uc_highlight_slide_opt_insert_before(void)
{
    return;
}

void mmi_uc_highlight_slide_opt_timing(void)
{
    return;
}

void mmi_uc_highlight_slide_opt_delete(void)
{
    return;
}

void mmi_uc_highlight_slide_opt_next(void)
{
    return;
}

void mmi_uc_highlight_slide_opt_previous(void)
{
    return;
}

void mmi_uc_highlight_opt_change_msg_type_to_sms(void)
{
    return;
}

void mmi_uc_highlight_opt_change_msg_type_to_mms(void)
{
    return;
}

void mmi_uc_highlight_opt_advance_options(void)
{
    return;
}

void mmi_uc_highlight_insert_text_template(void)
{
    return;
}

void mmi_uc_highlight_insert_attachment(void)
{
    return;
}

void mmi_uc_highlight_insert_phb_number(void)
{
    return;
}

void mmi_uc_highlight_insert_phb_name(void)
{
    return;
}

void mmi_uc_highlight_insert_bookmark(void)
{
    return;
}

void mmi_uc_highlight_insert_signature(void)
{
    return;
}

void mmi_uc_highlight_save_as_template(void)
{
    return;
}

void mmi_uc_highlight_opt_msg_detail(void)
{
    return;
}

void mmi_uc_highlight_edit_recipient(void)
{
    return;
}

void mmi_uc_highlight_remove_recipient(void)
{
    return;
}

void mmi_uc_highlight_remove_all_recipients(void)
{
    return;
}

void mmi_uc_highlight_change_to_to(void)
{
    return;
}

void mmi_uc_highlight_change_to_cc(void)
{
    return;
}

void mmi_uc_highlight_change_to_bcc(void)
{
    return;
}

void mmi_uc_highlight_save_to_draft(void)
{
    return;
}

void mmi_uc_highlight_opt_remove(void)
{
    return;
}

void mmi_uc_highlight_remove_video(void)
{
    return;
}

void mmi_uc_highlight_done_opt_send(void)
{
    return;
}

void mmi_uc_highlight_opt_replace(void)
{
    return;
}

void mmi_uc_highlight_replace_video(void)
{
    return;
}

void mmi_uc_highlight_exit_opt_save(void)
{
    return;
}

void mmi_uc_highlight_exit_opt_exit(void)
{
    return;
}

void mmi_uc_collect_object_ind_data(
        void *peer_buffer_p,
        U32 num_of_object,
        kal_bool more,
        void **uc_data)
{
    return;
}

void mmi_uc_free_collected_object_ind_data(void)
{
    return;
}

kal_bool mmi_uc_is_multi_object_req_is_in_process(void)
{
    return KAL_TRUE;
}

kal_bool mmi_uc_multi_object_insert_req(void)
{
    return KAL_TRUE;
}

void mmi_uc_pre_entry_write_msg(void)
{
    return;
}

void mmi_uc_battery_low_callback(void)
{
    return;
}

mmi_ret mmi_uc_sim_status_info_hdlr(mmi_event_struct *info)
{
	return MMI_RET_OK;
}

#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */ 
#endif /* _UNIFIED_COMPOSER_ENGINE_SRV_C */ /* _MMI_UNIFIED_COMPOSER_MAIN_C */
