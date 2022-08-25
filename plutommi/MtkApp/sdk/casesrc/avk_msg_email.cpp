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
 *   avk_msg_email.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   3rd Party Integration Development Environment
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_features.h"

#ifdef __MAUI_SDK_TEST__

#ifdef __cplusplus
extern "C" {
#endif

#include "MMIDataType.h"
#include "mmi_rp_app_sdk_test_def.h"
#include "gui_themes.h"


#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_release.h"
#include "DevAppDef.h"
#include "Conversions.h"
#include "EmailSrvGprot.h"
#include "mmi_rp_app_sdk_test_def.h"
#include "wgui_draw_manager.h"
#include "cbm_api.h"
#include "DtcntSrvGprot.h"
#include "wgui_categories_multimedia.h"
#include "wgui_categories_util.h"
#include "wgui_categories_popup.h"
#include "avk_msg_email.h"

#ifdef __cplusplus
}
#endif 

#ifdef __MMI_EMAIL__

typedef struct
{
    S32 index;
	EMAIL_SRV_HANDLE  srv_handle;
	EMAIL_ACCT_HANDLE acct_handle;
	EMAIL_MSG_HANDLE  msg_handle;
    EMAIL_FLDR_HANDLE fldr_handle;
    srv_email_fldr_create_info_struct folder_info;
	S32 msgNotifyId;
#ifdef __MMI_EMAIL_OTAP__
	EMAIL_OTAP_HANDLE otap_handle;
#endif
	srv_email_acct_info_struct curr_acct;
	EMAIL_REQ_ID req_id;
	EMAIL_MSG_ID msg_id;
	EMAIL_MSG_ID new_msg_id;
	EMAIL_ACCT_ID acct_id;
	EMAIL_FLDR_ID fldr_id;
    srv_email_msg_save_part_enum save_part;
	U32 remote_folder_num;
	U32 folder_num;
    U16 curr_opt;
}avk_msg_email_struct;


avk_msg_email_struct avk_msg_email_cntx;
static kal_uint8 avk_msg_email_app_id;

#ifndef __COSMOS_MMI_PACKAGE__
extern "C" MMI_BOOL mmi_email_store_acct_misc_info(EMAIL_ACCT_ID account_id);
#endif

void avk_msg_email_display_screen(dm_coordinates *coordinate);
void avk_msg_email_pass(void);
void avk_msg_email_fail(void);
void avk_msg_email_init_all(void);
void avk_msg_email_deinit_all(void);
void avk_msg_email_002_fldr_notify_callback(srv_email_om_notify_struct *notify_data, void *user_data);
static void avk_msg_email_002_fldr_send_all_proc_callback(srv_email_nwk_proc_struct *data);

void avk_msg_email_query_update_id_array(EMAIL_MSG_ID **id_array, U32 *num)
{

}	

void avk_msg_email_answer_update_id_array(EMAIL_MSG_ID *id_array, MMI_BOOL is_changed)
{

}

void *avk_msg_email_mem_malloc(U32 size)
{
	return OslMalloc(size);
}

void avk_msg_email_mem_free(void *ptr)
{
	OslMfree(ptr);
}

void avk_msg_email_005_emn_process(EMAIL_ACCT_ID acct_id)
{

}

void avk_msg_email_005_emn(void)
{
	avk_msg_email_cntx.index = 4;
	
#if defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__)

	mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_AVK_SCN_10, NULL, avk_msg_email_005_emn, MMI_FRM_FULL_SCRN);

    ShowCategory227Screen(0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, avk_msg_email_display_screen, NULL);

	AVK_LOG(srv_email_register_emn_notify(
							avk_msg_email_cntx.srv_handle, 
							avk_msg_email_005_emn_process, 
							NULL));
	AVK_LOG(srv_email_clear_emn_notify(avk_msg_email_cntx.srv_handle));

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);

#else
    AVK_LOG_FUN_UNSUPPORTED(srv_email_register_emn_notify);
    AVK_LOG_FUN_UNSUPPORTED(srv_email_clear_emn_notify);
    AVK_ASYN_DONE();
#endif

}



static void avk_msg_email_004_otap_async_add_profile_callback(
                srv_email_result_struct *p_result,
                EMAIL_ACCT_ID acct_id,
                EMAIL_REQ_ID req_id,
                void *user_data)
{

}


static void avk_msg_email_004_otap_async_replace_profile_callback(
                srv_email_result_struct *p_result,
                EMAIL_ACCT_ID acct_id,
                EMAIL_REQ_ID req_id,
                void *user_data)
{

}


void avk_msg_email_004_otap_process(U32 profile_num)
{

}


void avk_msg_email_004_otap(void)
{
	avk_msg_email_cntx.index = 3;
	//srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    srv_email_otap_option_struct otap_option;
	srv_email_otap_prof_info_struct current_profile_info;
	EMAIL_ACCT_ID replaced_account_id;
	U32 prof_num;

#ifdef __MMI_EMAIL_OTAP__

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_AVK_SCN_11, NULL, avk_msg_email_004_otap, MMI_FRM_FULL_SCRN);

    ShowCategory227Screen(0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, avk_msg_email_display_screen, NULL);


    AVK_LOG(srv_email_register_otap_notify(
                        avk_msg_email_cntx.srv_handle, 
                        avk_msg_email_004_otap_process, 
                        NULL));

	AVK_LOG(srv_email_otap_start_install(&avk_msg_email_cntx.otap_handle));
    AVK_LOG(srv_email_otap_set_option(avk_msg_email_cntx.otap_handle, &otap_option));

	AVK_LOG(srv_email_otap_get_prof_num(avk_msg_email_cntx.otap_handle, &prof_num));
		
    AVK_LOG(srv_email_otap_add_prof(avk_msg_email_cntx.otap_handle, 1, current_profile_info.prof_name, &avk_msg_email_cntx.curr_acct.acct_id));

    AVK_LOG(srv_email_otap_modify_prof(
                        avk_msg_email_cntx.otap_handle, 
                        1, 
                        current_profile_info.prof_name,
                        avk_msg_email_cntx.curr_acct.acct_id));

	AVK_LOG(srv_email_otap_update_prof(
						avk_msg_email_cntx.otap_handle, 
						1, 
						current_profile_info.prof_name));

	AVK_LOG(srv_email_otap_add_prof_async(
						avk_msg_email_cntx.otap_handle, 
						1, 
						current_profile_info.prof_name,
						&avk_msg_email_cntx.curr_acct.acct_id, 
						&avk_msg_email_cntx.req_id, 
						avk_msg_email_004_otap_async_add_profile_callback, 
						NULL));

    AVK_LOG(srv_email_otap_replace_prof_async(
                        avk_msg_email_cntx.otap_handle, 
                        1,
                        current_profile_info.prof_name,
                        avk_msg_email_cntx.curr_acct.acct_id,
                        &replaced_account_id,
                        &avk_msg_email_cntx.req_id,
                        avk_msg_email_004_otap_async_replace_profile_callback, 
                        NULL));

    AVK_LOG(srv_email_otap_finish_install(avk_msg_email_cntx.otap_handle));
	AVK_LOG(srv_email_clear_otap_notify(avk_msg_email_cntx.srv_handle));
	AVK_LOG(srv_email_otap_skip_prof(
								avk_msg_email_cntx.otap_handle, 
								MMI_FALSE, 
								1, 
								SRV_EMAIL_SKIP_ERROR));
		
	AVK_LOG(srv_email_otap_get_prof_info(avk_msg_email_cntx.otap_handle, 
							1, &current_profile_info));

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);

#else
	AVK_LOG_FUN_UNSUPPORTED(srv_email_register_otap_notify);
	AVK_ASYN_DONE();
#endif
}

static void avk_msg_email_003_msg_size_callback(MMI_BOOL succ, S32 err_major, S32 err_minor, U32 size, void *user_data)
{

}

void avk_msg_email_003_msg_notify_callback(srv_email_om_notify_struct *notify_data, void *user_data)
{

}

static void avk_msg_email_003_msg_parse_save_done(srv_email_result_struct *result_p, EMAIL_REQ_ID req_id, void *user_data)
{
    
}

static void avk_msg_email_003_msg_proc_callback(srv_email_nwk_proc_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data->status)
    {
        case SRV_EMAIL_NWK_CONNECTING:
            break;
        case SRV_EMAIL_NWK_AUTHORIZING:
            break;
        case SRV_EMAIL_NWK_CBM_QUERYING:
            break;
        case SRV_EMAIL_NWK_QUERYING:
            return;
        case SRV_EMAIL_NWK_UPDATING:
            break;
        case SRV_EMAIL_NWK_SENDING:
            break;
        case SRV_EMAIL_NWK_RECEIVING:
            break;
        case SRV_EMAIL_NWK_SYNCING:
            break;
        case SRV_EMAIL_NWK_DELETING:
            break;
        case SRV_EMAIL_NWK_LISTING_FOLDER:
            break;
        case SRV_EMAIL_NWK_DISCONNECTING:
            break;
    }
}

void avk_msg_email_003_msg_general_callback(srv_email_result_struct *result, EMAIL_REQ_ID req_id, void *user_data)
{
	//srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    U32 sub_len = 0,cont_len = 0;
    S32 sub_char = 0, cont_char = 0;
    srv_email_msg_get_basic_info_struct msg_basic_info;
	srv_email_msg_update_basic_info_struct msg_update_info;
	srv_email_msg_update_content_struct msg_update_c_info;
    srv_email_addr_struct addr_list[AVK_MSG_EMAIL_MAX_ADDR_NUM];
    srv_email_msg_get_recipient_struct recp_info;
    WCHAR subj[AVK_MSG_EMAIL_MAX_SUBJ_LEN + 1];
	WCHAR content[AVK_MSG_EMAIL_MAX_CONT_LEN + 1];
	srv_email_addr_struct addr_info;
	MMI_BOOL is_valid = MMI_FALSE;
    S8 text_status = 0;
    S8 html_status = 0;
    U32 plain_text_size;
    U32 html_text_size;
	srv_email_attach_struct attach_info;
	S32 number = 0;
	WCHAR file_path[AVK_MSG_EMAIL_MAX_PATH_LEN + 1];
	srv_email_msg_copy_struct msg_copy;
	U32 item_count = 1;
	srv_email_fldr_msg_info_struct msg_info;
	static WCHAR loading_str[100];
	//srv_email_fldr_sort_msg_struct email_app_sort_info;


	if (!result->result)
	{
		AVK_LOG(srv_email_fldr_clear_callback(avk_msg_email_cntx.fldr_handle));
		srv_email_fldr_clear_notify(avk_msg_email_cntx.fldr_handle);
		srv_email_fldr_destroy(avk_msg_email_cntx.fldr_handle);
		kal_wsprintf(loading_str,"%w\n \n ",L"Failed");
		//wgui_cat_popup_update_string((UI_string_type)loading_str);
		return;
	}
	else
	{
	
		kal_wsprintf(loading_str,"%w\n \n ",L"Pass");
		//wgui_cat_popup_update_string((UI_string_type)loading_str);

		AVK_LOG(srv_email_fldr_get_msg_list(
								avk_msg_email_cntx.fldr_handle,
								(U32)0,
								&item_count,&msg_info));
	
	    //email_app_sort_info.msg_id = msg_info.msg_id;
	    //email_app_sort_info.sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME;
	    //email_app_sort_info.sort_order = MMI_TRUE;

		//AVK_LOG(srv_email_fldr_sort_msg(avk_msg_email_cntx.fldr_handle,
	    //                            &email_app_sort_info));

		AVK_LOG(srv_email_msg_create(avk_msg_email_cntx.srv_handle, &avk_msg_email_cntx.msg_handle));
		
		AVK_LOG(srv_email_msg_open(
						avk_msg_email_cntx.msg_handle,
						avk_msg_email_cntx.acct_id,
						avk_msg_email_cntx.fldr_id,
						msg_info.msg_id));	
	
		AVK_LOG(srv_email_msg_get_permission(avk_msg_email_cntx.msg_handle));
		
		AVK_LOG(srv_email_msg_id_to_acct_id(avk_msg_email_cntx.msg_id));
		AVK_LOG(srv_email_msg_id_to_fldr_id(avk_msg_email_cntx.msg_id));
			
		AVK_LOG(srv_email_msg_check_valid(avk_msg_email_cntx.msg_id, &is_valid));
		AVK_LOG(srv_email_msg_set_flag(avk_msg_email_cntx.msg_handle, EMAIL_MSG_FLAG_SEEN, EMAIL_MSG_FLAG_SEEN));
	
	
		AVK_LOG(srv_email_msg_regist_callback(avk_msg_email_cntx.msg_handle, avk_msg_email_003_msg_parse_save_done, NULL));
		
		AVK_LOG(srv_email_msg_regist_proc_callback(
			   avk_msg_email_cntx.msg_handle,
			   avk_msg_email_003_msg_proc_callback,
			   (void*)(&avk_msg_email_cntx.curr_opt)));
		
		AVK_LOG(srv_email_msg_regist_notify(avk_msg_email_003_msg_notify_callback, NULL));
	
		AVK_LOG(srv_email_msg_get_basic_info(avk_msg_email_cntx.msg_handle, &msg_basic_info));
	
		AVK_LOG(srv_email_msg_update_basic_info(avk_msg_email_cntx.msg_handle, &msg_update_info));
	
		AVK_LOG(srv_email_msg_cont_size(avk_msg_email_cntx.msg_handle, &plain_text_size, &html_text_size));
	
	 	AVK_LOG(srv_email_msg_get_sender(avk_msg_email_cntx.msg_handle, &addr_info));
	
		AVK_LOG(srv_email_msg_update_sender(avk_msg_email_cntx.msg_handle, &addr_info));
	
		AVK_LOG(srv_email_msg_get_reply_to(avk_msg_email_cntx.msg_handle,addr_list));

		AVK_LOG(srv_email_msg_update_reply_to(avk_msg_email_cntx.msg_handle,addr_list));
		
		recp_info.type = SRV_EMAIL_ADDR_TYPE_TO;
		recp_info.number = 1;
		recp_info.addr_list = addr_list;
		recp_info.start_index = 0;
		
		AVK_LOG(srv_email_msg_get_recipient(avk_msg_email_cntx.msg_handle, &recp_info));

	
		AVK_LOG(srv_email_msg_update_recipient(avk_msg_email_cntx.msg_handle,SRV_EMAIL_ADDR_TYPE_CC,1,&addr_info));

	
		AVK_LOG(srv_email_msg_get_subject_len(
					avk_msg_email_cntx.msg_handle,
					&sub_len,
					&sub_char));

		sub_len++;
		
		AVK_LOG(srv_email_msg_get_subject(
				avk_msg_email_cntx.msg_handle,
				subj,
				&sub_len));
	
		AVK_LOG(srv_email_msg_update_subject(
					avk_msg_email_cntx.msg_handle,
					subj,
					MMI_CHSET_UCS2,
					sub_len));

	
		AVK_LOG(srv_email_msg_cont_status(avk_msg_email_cntx.msg_handle, &text_status, &html_status));

		
		AVK_LOG(srv_email_msg_get_content_len(
						avk_msg_email_cntx.msg_handle,
						&cont_len,
						&cont_char));
			
		cont_len++;
			
		AVK_LOG(srv_email_msg_get_content(
						avk_msg_email_cntx.msg_handle,
						MMI_TRUE,
						content,
						&cont_len));
			
		AVK_LOG(srv_email_msg_update_content(
						avk_msg_email_cntx.msg_handle,
						&msg_update_c_info));
	
		AVK_LOG(srv_email_msg_get_attachment_info(
							avk_msg_email_cntx.msg_handle, 
							0, 
							&number, 
							&attach_info));
	
	
		AVK_LOG(srv_email_msg_update_attach(avk_msg_email_cntx.msg_handle,number, &attach_info));
	
		AVK_LOG(srv_email_comp_msg_size(avk_msg_email_cntx.msg_handle, avk_msg_email_003_msg_size_callback, NULL));
	
		AVK_LOG(srv_email_msg_get_attachment_path(
						   avk_msg_email_cntx.msg_handle, 
						   attach_info.attach_id,
						   file_path,
						   AVK_MSG_EMAIL_MAX_PATH_LEN));

	
		AVK_LOG(srv_email_attch_id_to_msg_id(attach_info.attach_id));
	
		avk_msg_email_cntx.save_part = SRV_EMAIL_MSG_SAVE_SUBJECT;
	
		AVK_LOG(srv_email_msg_save(
							avk_msg_email_cntx.msg_handle,
							avk_msg_email_cntx.save_part,
							&avk_msg_email_cntx.req_id));
	
		AVK_LOG(srv_email_msg_save_new(
							avk_msg_email_cntx.msg_handle,
							avk_msg_email_cntx.acct_id,
							avk_msg_email_cntx.fldr_id,
							&avk_msg_email_cntx.new_msg_id,
							&avk_msg_email_cntx.req_id));
		
		AVK_LOG(srv_email_msg_move(
			avk_msg_email_cntx.msg_handle,
			avk_msg_email_cntx.acct_id,
			avk_msg_email_cntx.fldr_id,
			&avk_msg_email_cntx.new_msg_id));
	
		msg_copy.dst_acct_id = avk_msg_email_cntx.acct_id;
		msg_copy.dst_fldr_id = SRV_EMAIL_FLDR_TYPE_DRAFT;
		
		AVK_LOG(srv_email_msg_copy(avk_msg_email_cntx.msg_handle,
										&msg_copy,
										&avk_msg_email_cntx.req_id));
	
		AVK_LOG(srv_email_msg_send(
					avk_msg_email_cntx.msg_handle,
					MMI_TRUE,
					&avk_msg_email_cntx.req_id));
	
		AVK_LOG(srv_email_msg_retrieve(
					avk_msg_email_cntx.msg_handle,
					SRV_EMAIL_RETRIEVE_ALL_PARTS,
					0,
					&avk_msg_email_cntx.req_id));
	
		AVK_LOG(srv_email_msg_delete(avk_msg_email_cntx.msg_handle, MMI_FALSE, MMI_FALSE));
	}
	
}


void avk_msg_email_003_msg(void)
{
	//srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
	
	S32 number = 0;
	S32 folder_num = 4;
	S32 acct_num = 0;
	U32 acct_num_u = 0;
    EMAIL_FLDR_ID fldr_id_array[4] = {0};
	EMAIL_ACCT_ID acct_id_list[10] = {0};
	static WCHAR loading_str[100];
	//srv_email_result_struct result;

	avk_msg_email_cntx.index = 2;
	
    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_AVK_SCN_12, NULL, avk_msg_email_003_msg, MMI_FRM_FULL_SCRN);

    ShowCategory227Screen(0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, avk_msg_email_display_screen, NULL);
	
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);

	srv_email_acct_get_num(&acct_num_u);
	
	kal_wsprintf(loading_str,"%w\n \n ",L"Please wait...");
	//wgui_cat_popup_update_string((UI_string_type)loading_str);

	acct_num = (S32)acct_num_u;
		
	srv_email_acct_get_acct_id(0, &acct_num, acct_id_list);

	srv_email_acct_create(avk_msg_email_cntx.srv_handle, &avk_msg_email_cntx.acct_handle);

	srv_email_acct_open(avk_msg_email_cntx.acct_handle, acct_id_list[0]);
	
	AVK_LOG(srv_email_acct_get_fldr_id(
		avk_msg_email_cntx.acct_handle,
		SRV_EMAIL_ACCT_FLDR_TYPE_BASIC,
		0,
		&folder_num,
		fldr_id_array));
	
	avk_msg_email_cntx.folder_info.fldr_id = fldr_id_array[0];
	avk_msg_email_cntx.folder_info.acct_id = acct_id_list[0];
	avk_msg_email_cntx.folder_info.sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME;
	avk_msg_email_cntx.folder_info.sort_order = MMI_FALSE;
	avk_msg_email_cntx.folder_info.list_field = 0;

	avk_msg_email_cntx.acct_id = acct_id_list[0];
	avk_msg_email_cntx.fldr_id = fldr_id_array[0];

	srv_email_fldr_create(  avk_msg_email_cntx.srv_handle,
						    &avk_msg_email_cntx.folder_info,
							&avk_msg_email_cntx.fldr_handle);

	srv_email_set_mem_func( avk_msg_email_cntx.srv_handle,
							avk_msg_email_mem_malloc,
							avk_msg_email_mem_free);
	
	AVK_LOG(srv_email_msg_set_new(avk_msg_email_cntx.msg_handle));

    AVK_LOG(srv_email_fldr_get_msg_num(
        avk_msg_email_cntx.fldr_handle,
        SRV_EMAIL_FLDR_MSG,
        &number));
	
	srv_email_fldr_regist_callback(avk_msg_email_cntx.fldr_handle, avk_msg_email_003_msg_general_callback, NULL);
	srv_email_fldr_regist_proc_callback(avk_msg_email_cntx.fldr_handle, avk_msg_email_002_fldr_send_all_proc_callback, NULL);
	srv_email_fldr_regist_notify(avk_msg_email_cntx.fldr_handle, avk_msg_email_002_fldr_notify_callback, NULL);

#ifndef __COSMOS_MMI_PACKAGE__
	AVK_LOG(srv_email_fldr_list_msg(
						avk_msg_email_cntx.fldr_handle,
						SRV_EMAIL_MSG_TEXT_SUBJ,
						SRV_EMAIL_MSG_CREATED_DATE,
						&avk_msg_email_cntx.req_id));
		
	//result.result = MMI_TRUE;
	//avk_msg_email_003_msg_general_callback(&result, 0, NULL);
#else
	AVK_LOG(srv_email_fldr_list_msg_ext(avk_msg_email_cntx.fldr_handle,
						SRV_EMAIL_MSG_TEXT_SUBJ,
						SRV_EMAIL_MSG_CREATED_DATE,
						&avk_msg_email_cntx.req_id));
#endif
		
	AVK_LOG(srv_email_msg_abort(avk_msg_email_cntx.msg_handle,avk_msg_email_cntx.req_id));
	
	AVK_LOG(srv_email_msg_destroy(avk_msg_email_cntx.msg_handle));
	AVK_LOG(srv_email_msg_clear_callback(avk_msg_email_cntx.msg_handle));
	AVK_LOG(srv_email_msg_clear_notify());
	AVK_LOG(srv_email_msg_clear_proc_callback(avk_msg_email_cntx.msg_handle));
		
}

void avk_msg_email_002_fldr_general_callback(srv_email_result_struct *result, EMAIL_REQ_ID req_id, void *user_data)
{
	static WCHAR loading_str[100];


	if (!result->result)
	{
		kal_wsprintf(loading_str,"%w\n \n ",L"Failed");
		//wgui_cat_popup_update_string((UI_string_type)loading_str);
	}
	else
	{
	
		kal_wsprintf(loading_str,"%w\n \n ",L"Pass");
		//wgui_cat_popup_update_string((UI_string_type)loading_str);
	}
	
}

void avk_msg_email_002_fldr_notify_callback(srv_email_om_notify_struct *notify_data, void *user_data)
{

}

static void avk_msg_email_002_fldr_send_all_proc_callback(srv_email_nwk_proc_struct *data)
{
	switch (data->status)
   {
	   case SRV_EMAIL_NWK_CONNECTING:
		   break;
	   case SRV_EMAIL_NWK_AUTHORIZING:
		   break;
	   case SRV_EMAIL_NWK_CBM_QUERYING:
		   break;
	   case SRV_EMAIL_NWK_QUERYING:
		   return;
	   case SRV_EMAIL_NWK_SENDING:
		   break;
	   case SRV_EMAIL_NWK_SEND_DONE:
		   break;
   }
}

void avk_msg_email_002_fldr_send()
{
    //srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    //srv_email_fldr_msg_info_struct msg_info;
	srv_email_fldr_delete_msg_struct delete_info;
	//srv_email_fldr_sort_msg_struct email_app_sort_info;
	srv_email_fldr_set_msg_flag_struct flag;
	//U32 item_count = 1;

	AVK_LOG(srv_email_fldr_send(
				avk_msg_email_cntx.fldr_handle,
				MMI_TRUE,
				&avk_msg_email_cntx.req_id));
	
    //email_app_sort_info.msg_id = 1;
    //email_app_sort_info.msg_index = 1;
    //email_app_sort_info.sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME;
    //email_app_sort_info.sort_order = MMI_TRUE;


	//AVK_LOG(srv_email_fldr_sort_msg_async(
    //            avk_msg_email_cntx.fldr_handle,
    //            &email_app_sort_info,
    //            &avk_msg_email_cntx.req_id));
		
    AVK_LOG(srv_email_fldr_mark_msg(
                avk_msg_email_cntx.fldr_handle,
                MMI_TRUE, 1, MMI_TRUE));

	memset(&flag, 0, sizeof(srv_email_fldr_set_msg_flag_struct));
	
	flag.set_all = MMI_FALSE;
	flag.set_all_marked = MMI_FALSE;
	flag.msg_id = 1;
	flag.msg_flag = 0x01;
	flag.flag_mask = 0x01;
	
	AVK_LOG(srv_email_fldr_set_msg_flag(
			avk_msg_email_cntx.fldr_handle,
			&flag,
			&avk_msg_email_cntx.req_id));
	
	//item_count = 1;

	//AVK_LOG(srv_email_fldr_get_msg_list(
	//							avk_msg_email_cntx.fldr_handle,
	//							(U32)0,
	//							&item_count,&msg_info));

    delete_info.delete_all = MMI_FALSE;
    delete_info.delete_all_marked = MMI_FALSE;
    delete_info.delete_header = MMI_FALSE;
    delete_info.delete_server = MMI_TRUE;
    delete_info.msg_id = 0;
    delete_info.delete_header = MMI_TRUE;

    AVK_LOG(srv_email_fldr_delete_msg(
            avk_msg_email_cntx.fldr_handle,
            &delete_info,
            &avk_msg_email_cntx.req_id));
	
}

void avk_msg_email_002_fldr(void)
{
	
	srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
	srv_email_acct_folder_struct folder_info;
	srv_email_fldr_basic_info_struct base_info;
	WCHAR name[260];
	U32 item_count = 1;
	srv_email_inbox_index_msg_struct get_info[1];
	S32 folder_num = 1;
    EMAIL_FLDR_ID fldr_id_array[4] = {0};
	EMAIL_ACCT_ID acct_id_list[10] = {0};
	S32 acct_num = 0;
	U32 acct_num_u = 0;
    U32 msgCnt = 0;
    EMAIL_MSG_ID matchedMsgId = EMAIL_MSG_INVALID_ID;
	srv_email_fldr_create_by_type_info_struct fldr_create;
	EMAIL_FLDR_ID fldr_id = EMAIL_FLDR_INVALID_ID;

	avk_msg_email_cntx.index = 1;

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_AVK_SCN_13, NULL, avk_msg_email_002_fldr, MMI_FRM_FULL_SCRN);

    ShowCategory227Screen(0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, avk_msg_email_display_screen, NULL);

	srv_email_acct_get_num(&acct_num_u);
		
	if( acct_num>10)
	{
		return;
	}
	else
	{
		acct_num = (S32)acct_num_u;
	}

	srv_email_acct_get_acct_id(0, &acct_num, acct_id_list);

	srv_op_result = srv_email_acct_create(avk_msg_email_cntx.srv_handle, &avk_msg_email_cntx.acct_handle);

	if (srv_op_result != SRV_EMAIL_RESULT_SUCC)
	{
		return;
	}
	
	srv_op_result = srv_email_acct_open(avk_msg_email_cntx.acct_handle, acct_id_list[0]);
	
	if (srv_op_result != SRV_EMAIL_RESULT_SUCC)
	{
		srv_email_acct_destroy(avk_msg_email_cntx.acct_handle);
		avk_msg_email_cntx.acct_handle = 0;
		return;
	}

	AVK_LOG(srv_email_set_mem_func( avk_msg_email_cntx.srv_handle,
							avk_msg_email_mem_malloc,
							avk_msg_email_mem_free));

	srv_email_acct_get_fldr_id(
		avk_msg_email_cntx.acct_handle,
		SRV_EMAIL_ACCT_FLDR_TYPE_BASIC,
		0,
		&folder_num,
		fldr_id_array);
	
	if (folder_num<=0)
	{
		srv_email_acct_destroy(avk_msg_email_cntx.acct_handle);
		avk_msg_email_cntx.acct_handle = 0;
		return;
	}


    avk_msg_email_cntx.folder_info.fldr_id = fldr_id_array[0];
    avk_msg_email_cntx.folder_info.acct_id = acct_id_list[0];
    avk_msg_email_cntx.folder_info.sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME;
    avk_msg_email_cntx.folder_info.sort_order = MMI_FALSE;
    avk_msg_email_cntx.folder_info.list_field = 0;

	fldr_create.fldr_type = SRV_EMAIL_FLDR_TYPE_INBOX;
	fldr_create.list_field = 0;
	fldr_create.sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME;
	fldr_create.sort_order = MMI_FALSE;

	AVK_LOG(srv_email_fldr_create_by_type(
										avk_msg_email_cntx.srv_handle,
										&fldr_create,
										&avk_msg_email_cntx.fldr_handle));

    AVK_LOG(srv_op_result = srv_email_fldr_create(
                avk_msg_email_cntx.srv_handle,
                &avk_msg_email_cntx.folder_info,
                &avk_msg_email_cntx.fldr_handle));

	if (srv_op_result != SRV_EMAIL_RESULT_SUCC)
    {
		srv_email_acct_destroy(avk_msg_email_cntx.acct_handle);
		avk_msg_email_cntx.acct_handle = 0;
	 	goto LAST_NODE;
    } 

    AVK_LOG(srv_email_fldr_regist_callback(avk_msg_email_cntx.fldr_handle, avk_msg_email_002_fldr_general_callback, NULL));
	AVK_LOG(srv_email_fldr_regist_proc_callback(avk_msg_email_cntx.fldr_handle, avk_msg_email_002_fldr_send_all_proc_callback, NULL));
	AVK_LOG(srv_email_fldr_regist_notify(avk_msg_email_cntx.fldr_handle, avk_msg_email_002_fldr_notify_callback, NULL));
	AVK_LOG_NORMAL(srv_email_recent_list_notify_set( avk_msg_email_query_update_id_array, avk_msg_email_answer_update_id_array));


	 AVK_LOG(srv_email_fldr_receive(avk_msg_email_cntx.fldr_handle,
                                		SRV_EMAIL_RECEIVE_ALL_EMAIL,
                                		&avk_msg_email_cntx.req_id));
 	 AVK_LOG(fldr_id = srv_email_fldr_type_to_fldr_id(acct_id_list[0], SRV_EMAIL_FLDR_TYPE_INBOX));
 	
	 AVK_LOG(srv_email_fldr_get_all_msg_id(
		 acct_id_list[0],
		 fldr_id,
		 EMAIL_MSG_FLAG_SEEN,
		 0,
		 &msgCnt,
		 &matchedMsgId));

	AVK_LOG(srv_email_fldr_get_basic_info(avk_msg_email_cntx.fldr_handle,&base_info));
	
	AVK_LOG(srv_email_acct_get_fldr_info(avk_msg_email_cntx.acct_handle, fldr_id_array[0], &folder_info));

	AVK_LOG(srv_email_fldr_get_name(avk_msg_email_cntx.fldr_handle,name,260));
									
	AVK_LOG(srv_email_fldr_id_to_fldr_type(avk_msg_email_cntx.acct_id, fldr_id_array[0]) != SRV_EMAIL_FLDR_TYPE_INBOX);
	
	avk_msg_email_002_fldr_send();
	
    AVK_LOG(srv_op_result = srv_email_fldr_inbox_get_recent_list(
						  avk_msg_email_cntx.acct_id,
						  0,&item_count,1,0,get_info));
				
	AVK_LOG(srv_email_fldr_sync(avk_msg_email_cntx.fldr_handle, &avk_msg_email_cntx.req_id));
		
	AVK_LOG(srv_email_fldr_abort(avk_msg_email_cntx.fldr_handle,	avk_msg_email_cntx.req_id));
	AVK_LOG(srv_email_fldr_clear_proc_callback(avk_msg_email_cntx.fldr_handle));
	AVK_LOG(srv_email_fldr_clear_callback(avk_msg_email_cntx.fldr_handle));

	
LAST_NODE:
	
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
						  
}



void avk_msg_email_001_account_unread_notify(srv_email_all_msg_unread_notify_type type, U32 num)
{

}


static void avk_msg_email_001_account_callback(srv_email_result_struct *result, EMAIL_REQ_ID req_id, void *user_data)
{
	static WCHAR loading_str[100];

	if(req_id == avk_msg_email_cntx.req_id)
    {
	    if (!result->result)
	    {
			kal_wsprintf(loading_str,"%w\n \n ",L"Failed");
			//wgui_cat_popup_update_string((UI_string_type)loading_str);
	    }
	    else
	    {
	    	// result
			kal_wsprintf(loading_str,"%w\n \n ",L"Pass");
			//wgui_cat_popup_update_string((UI_string_type)loading_str);
			
	    }
	}
}

static void avk_msg_email_001_account_proc_callback(srv_email_nwk_proc_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	static WCHAR fldr_recv_loading_str[100];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data->status)
    {
        case SRV_EMAIL_NWK_CONNECTING:
            kal_wsprintf(
                fldr_recv_loading_str,
                "%w\n \n ",
                (WCHAR*)GetString(STR_GLOBAL_CONNECTING));
            break;
        case SRV_EMAIL_NWK_AUTHORIZING:
            kal_wsprintf(
                fldr_recv_loading_str,
                "%w\n \n ",
                (WCHAR*)L"NWK Authorizing");
            break;
        case SRV_EMAIL_NWK_CBM_QUERYING:
            kal_wsprintf(
                fldr_recv_loading_str,
                "%w\n \n ",
                (WCHAR*)L"CBM Querying");
            break;
        case SRV_EMAIL_NWK_QUERYING:
			 kal_wsprintf(
                fldr_recv_loading_str,
                "%w\n \n ",
                (WCHAR*)L"NWK Querying");
			break;
        case SRV_EMAIL_NWK_UPDATING:
            kal_wsprintf(
                fldr_recv_loading_str,
                "%w\n \n ",
                (WCHAR*)L"Updataing");
            break;
        case SRV_EMAIL_NWK_RECEIVING:
 			{
                srv_email_receiving_data_struct *recv = (srv_email_receiving_data_struct*)data->status_data;

                if (recv->received_num < recv->total_num)
                {
                    kal_wsprintf(
                        fldr_recv_loading_str,
                        "%w\n\n(%d / %d)",
                        GetString(STR_GLOBAL_RECEIVING),
                        recv->received_num + 1,
                        recv->total_num);
                }
            }           
			break;
        case SRV_EMAIL_NWK_SYNCING:
            kal_wsprintf(
                fldr_recv_loading_str,
                "%w\n \n ",
                (WCHAR*)L"Syncing");
            break;
        case SRV_EMAIL_NWK_DISCONNECTING:
            kal_wsprintf(
                fldr_recv_loading_str,
                "%w\n \n ",
                (WCHAR*)L"Disconnecting");
            break;
    }

	//wgui_cat_popup_update_string((UI_string_type)fldr_recv_loading_str);
}

MMI_BOOL avk_msg_email_001_account_app_info_for_srv(
                    srv_email_app_info_query_struct *app_info_p,
                    U16 *str_id,
                    U16 *icon_id)
{
	return MMI_TRUE;
}

static void avk_msg_email_001_async_save_acct_callback(srv_email_result_enum result, void *user_data)
{

}


S32 avk_msg_email_001_account_remote(void)
{
	//srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
	srv_email_acct_remote_fldr_info_strcut remote_folder_info;
	U32 folder_num = 1;
	MMI_BOOL subscribe = MMI_TRUE;

	AVK_LOG(srv_email_acct_list_remote_fldr(
						avk_msg_email_cntx.acct_handle, 
						20, 
						&avk_msg_email_cntx.req_id));
	
	AVK_LOG(srv_email_acct_get_remote_fldr_num(
						avk_msg_email_cntx.acct_handle,
						&avk_msg_email_cntx.remote_folder_num));

	AVK_LOG(srv_email_acct_get_remote_fldr_info(
								avk_msg_email_cntx.acct_handle,
								1, 
								&folder_num, 
								&remote_folder_info));
	
				
	AVK_LOG(srv_email_acct_subscribe_remote_fldr(
								avk_msg_email_cntx.acct_handle,
								1, 
								subscribe));
				
	AVK_LOG(srv_email_acct_remote_fldr_submit_subscribe(avk_msg_email_cntx.acct_handle));
	
	return 0;

}


void avk_msg_email_001_account(void)
{
	S32 i = 0,count;
	U32 unread, count_u;
	CHAR now = 0;
    CHAR org = 0;
	EMAIL_ACCT_HANDLE acct_handle;
	EMAIL_ACCT_ID acct_id_list[50];
	srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
	srv_email_acct_info_struct acct;
        WCHAR acct_name[(SRV_EMAIL_MAX_ACCT_NAME_LEN + 1)*2] = {0};
        CHAR tempPtr[256];
	cbm_account_info_struct acctInfo;
	cbm_app_info_struct info;
	srv_email_acct_info_struct curr_acct;
	CHAR *path = NULL;
	static WCHAR fldr_recv_loading_str[100];
	EMAIL_REQ_ID reqId = EMAIL_REQ_INVALID_ID;
	MMI_BOOL is_valid;
	S32 folder_num;
	
	avk_msg_email_cntx.index = 0;

	avk_msg_email_init_all();

	AVK_LOG(path = srv_email_get_root_path());

	if(path == NULL)
	{
		return;
	}
	
	AVK_LOG(org = srv_email_get_drive());
	AVK_LOG(srv_email_set_drive('c'));
	AVK_LOG(now = srv_email_get_drive());


    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_AVK_SCN_14, NULL, avk_msg_email_001_account, MMI_FRM_FULL_SCRN);

    ShowCategory227Screen(0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, avk_msg_email_display_screen, NULL);


	if('c' == now)
	{
		AVK_LOG(srv_email_set_drive(org));
	}

	AVK_LOG(srv_email_errno_get());
	
	memset(&curr_acct,0,sizeof(curr_acct));

	AVK_LOG_NORMAL(srv_email_acct_cache_notify_set((srv_email_all_msg_unread_notify_funcptr)avk_msg_email_001_account_unread_notify,NULL));

	AVK_LOG(srv_email_acct_create(avk_msg_email_cntx.srv_handle, &acct_handle));
	AVK_LOG(srv_email_acct_init_acct_info(&curr_acct));

	kal_wsprintf(
		fldr_recv_loading_str,
		"%w\n \n ",
		(WCHAR*)L"Please wait...");
	
	//wgui_cat_popup_update_string((UI_string_type)fldr_recv_loading_str);

	AVK_LOG(srv_op_result = srv_email_acct_new(acct_handle, &curr_acct.acct_id));
	
	strcpy(tempPtr,"test account");
    mmi_asc_to_wcs((U16*) curr_acct.acct_name, (CHAR*) tempPtr);
#ifdef WIN32
	strcpy(tempPtr,"Zhiwei.Yang@iceman.com");
    mmi_asc_to_wcs((U16*) curr_acct.email_addr.email_addr, (CHAR*) tempPtr);
	strcpy(tempPtr,"MTK80213@iceman.com");
    mmi_asc_to_wcs((U16*) curr_acct.in_auth.username, (CHAR*) tempPtr);
	strcpy(tempPtr,"Mbj-0121");
    mmi_asc_to_wcs((U16*) curr_acct.in_auth.password, (CHAR*) tempPtr);
	strcpy(tempPtr,"MTK80213@iceman.com");
    mmi_asc_to_wcs((U16*) curr_acct.out_auth.username, (CHAR*) tempPtr);
	strcpy(tempPtr,"Mbj-0121");
    mmi_asc_to_wcs((U16*) curr_acct.out_auth.password, (CHAR*) tempPtr);
	strcpy(tempPtr,"172.27.4.53");
    mmi_asc_to_wcs((U16*) curr_acct.in_server.server_name, (CHAR*) tempPtr);
	strcpy(tempPtr,"172.27.4.53");
    mmi_asc_to_wcs((U16*) curr_acct.out_server.server_name, (CHAR*) tempPtr);
#else
	strcpy(tempPtr,"mtk_test001@126.com");
	mmi_asc_to_wcs((U16*) curr_acct.email_addr.email_addr, (CHAR*) tempPtr);
	strcpy(tempPtr,"mtk_test001");
	mmi_asc_to_wcs((U16*) curr_acct.in_auth.username, (CHAR*) tempPtr);
	strcpy(tempPtr,"000000");
	mmi_asc_to_wcs((U16*) curr_acct.in_auth.password, (CHAR*) tempPtr);
	strcpy(tempPtr,"mtk_test001");
	mmi_asc_to_wcs((U16*) curr_acct.out_auth.username, (CHAR*) tempPtr);
	strcpy(tempPtr,"000000");
	mmi_asc_to_wcs((U16*) curr_acct.out_auth.password, (CHAR*) tempPtr);
	strcpy(tempPtr,"pop.126.com");
	mmi_asc_to_wcs((U16*) curr_acct.in_server.server_name, (CHAR*) tempPtr);
	strcpy(tempPtr,"smtp.126.com");
	mmi_asc_to_wcs((U16*) curr_acct.out_server.server_name, (CHAR*) tempPtr);
#endif

	curr_acct.acct_type = SRV_EMAIL_ACCT_USER_CONFIGURED;
	curr_acct.send_option = SRV_EMAIL_SEND_IMMEDIATELY;
	curr_acct.read_only = KAL_FALSE;
	curr_acct.acct_attr = 3;
	curr_acct.download_size = 102400;
	curr_acct.retrieve_amount = 100;
	curr_acct.delete_option = SRV_EMAIL_DELETE_ALWAYS_ASK;
	curr_acct.protocol = SRV_EMAIL_PROT_POP3;
	curr_acct.notify_option = SRV_EMAIL_NOTIFY_OFF;
	curr_acct.download_option = SRV_EMAIL_DOWNLOAD_HEADER;
	curr_acct.in_server.port_num = 110;
	curr_acct.in_server.sec_port_num = 995;
	curr_acct.in_server.sec_mode = SRV_EMAIL_SEC_NONE;
	curr_acct.out_server.port_num = 25;
	curr_acct.in_server.sec_port_num = 465;
	curr_acct.in_server.sec_mode = SRV_EMAIL_SEC_NONE;
	curr_acct.in_auth.auth_type = SRV_EMAIL_AUTH_USER;
	curr_acct.out_auth.auth_type = SRV_EMAIL_AUTH_USER;

    
	info.app_str_id = STR_GLOBAL_OK;
	info.app_icon_id = IMG_GLOBAL_OK;
	info.app_type = DTCNT_APPTYPE_EMAIL;
	cbm_register_app_id_with_app_info(&info, &avk_msg_email_app_id);
	
	acctInfo.account[0].account_id = CBM_DEFAULT_ACCT_ID;
	acctInfo.account[0].is_always_ask = KAL_FALSE;
	acctInfo.account[0].sim_id = CBM_SIM_ID_SIM1;
	acctInfo.acct_num = 1;
    acctInfo.app_id = avk_msg_email_app_id;

	cbm_encode_data_account_id_ext(curr_acct.acct_id, &curr_acct.in_server.data_acct[0], &acctInfo);

	curr_acct.out_server.data_acct[0] = curr_acct.in_server.data_acct[0];

    AVK_LOG(srv_email_acct_edit(acct_handle, &curr_acct));

  	AVK_LOG(srv_op_result = srv_email_acct_save(acct_handle));
	
    AVK_LOG(srv_email_acct_save_async( acct_handle, avk_msg_email_001_async_save_acct_callback,NULL));
	AVK_LOG_NORMAL(srv_email_acct_save_async_abort());

#ifndef __COSMOS_MMI_PACKAGE__
	mmi_email_store_acct_misc_info(curr_acct.acct_id);
#endif

	AVK_LOG(srv_email_acct_get_permission(acct_handle));
	
	AVK_LOG(srv_email_acct_read(acct_handle, &acct));
	
	AVK_LOG(srv_email_acct_get_num(&count_u));
	
	if (count_u > 0)
	{
		
		srv_email_acct_info_cache_struct acct_info_cache;
		
		count = (S32)count_u;

		AVK_LOG(srv_op_result = srv_email_acct_get_acct_id(0, &count, acct_id_list));
		if (SRV_EMAIL_RESULT_SUCC == srv_op_result)
		{
		    for(i = 0; i<count; i++)
			{
				AVK_LOG_NORMAL(srv_email_acct_cache_get(acct_id_list[i], &acct_info_cache));
				AVK_LOG(srv_email_acct_total_unread_num_get(&unread));
	
				AVK_LOG(srv_email_acct_get_name( acct_id_list[i],
									 acct_name,
									 SRV_EMAIL_MAX_ACCT_NAME_LEN + 1));
				if(mmi_wcscmp(acct_name,acct.acct_name) == 0)
				{
					avk_msg_email_cntx.acct_id = acct_id_list[i];
			  		break;
				}
		    }
		}
	}

	AVK_LOG(srv_email_acct_check_valid(avk_msg_email_cntx.acct_id, &is_valid));
		
	avk_msg_email_cntx.acct_handle = acct_handle;

	AVK_LOG(srv_op_result = srv_email_acct_open(acct_handle, avk_msg_email_cntx.acct_id));

 	AVK_LOG(srv_email_acct_register_callback(acct_handle, avk_msg_email_001_account_callback, NULL));
 	AVK_LOG(srv_email_acct_register_proc_callback(acct_handle, avk_msg_email_001_account_proc_callback, NULL));

   AVK_LOG(srv_email_acct_set_default(avk_msg_email_cntx.acct_id));
   AVK_LOG(srv_email_acct_get_default(&avk_msg_email_cntx.acct_id));

   AVK_LOG(srv_op_result = srv_email_acct_nwk_test(acct_handle, MMI_FALSE, &reqId));
	      
   AVK_LOG(srv_email_acct_connect(acct_handle, MMI_TRUE, &reqId));
   
   AVK_LOG(srv_email_cbm_hold(curr_acct.acct_id, MMI_TRUE, MMI_TRUE));

   AVK_LOG(srv_email_acct_send(acct_handle, MMI_TRUE, &reqId));

    AVK_LOG(srv_op_result = srv_email_acct_receive(acct_handle,
	   SRV_EMAIL_RECEIVE_NEW_EMAIL,&avk_msg_email_cntx.req_id));
   
   if ((srv_op_result != SRV_EMAIL_RESULT_SUCC) && (srv_op_result != SRV_EMAIL_RESULT_WOULDBLOCK))
   {
   }
   
   AVK_LOG(srv_email_acct_disconnect(acct_handle, MMI_TRUE, MMI_FALSE, &reqId));

   avk_msg_email_001_account_remote();

   AVK_LOG(srv_email_acct_sync(avk_msg_email_cntx.curr_acct.acct_id, &reqId));

   AVK_LOG(srv_email_acct_refresh(avk_msg_email_cntx.curr_acct.acct_id,
   				   SRV_EMAIL_RECEIVE_NEW_EMAIL,
				   &reqId));



   AVK_LOG(srv_email_acct_get_fldr_num(
								acct_handle,
								SRV_EMAIL_ACCT_FLDR_TYPE_LOCAL,
								&folder_num));
   
   AVK_LOG(srv_email_cbm_release(avk_msg_email_cntx.curr_acct.acct_id, MMI_TRUE, MMI_TRUE));
   AVK_LOG(srv_email_acct_clear_callback(acct_handle));
   AVK_LOG(srv_email_acct_clear_proc_callback(acct_handle));
   
   AVK_LOG(srv_email_acct_abort(acct_handle,avk_msg_email_cntx.req_id));
   
   AVK_LOG(srv_email_acct_destroy(acct_handle));
   
   //AVK_LOG(srv_email_acct_cancel(avk_msg_email_cntx.curr_acct.acct_id));
   AVK_LOG(srv_email_acct_delete(avk_msg_email_cntx.acct_id));
   AVK_LOG(srv_email_destroy(avk_msg_email_cntx.srv_handle));

//LAST_NODE:

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);

   
}


void avk_msg_email_display_screen(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dis_str[AVK_MSG_EMAIL_BUFFER_SIZE];
    U8 dis_buf[AVK_MSG_EMAIL_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(coordinate);

    memset(dis_buf, 0, AVK_MSG_EMAIL_BUFFER_SIZE);
    memset(dis_str, 0, AVK_MSG_EMAIL_BUFFER_SIZE);

	gui_set_font(&UI_DEFAULT_FONT);
	
	gui_set_text_color(gui_color(128, 0, 255));
	gui_set_text_border_color(gui_color(255, 255, 255));

	gui_move_text_cursor(5, 40);

	switch (avk_msg_email_cntx.index)
	{
		case 0:
			gui_print_text((UI_string_type) L"Email data account");
			gui_set_text_color(gui_color(0, 0, 0));
			gui_move_text_cursor(5, 100);
			gui_print_bordered_text((UI_string_type) L"Pass");
			break;
		case 1:
			gui_print_text((UI_string_type) L"Email fldr");
			gui_set_text_color(gui_color(0, 0, 0));
			gui_move_text_cursor(5, 100);
			gui_print_bordered_text((UI_string_type) L"Pass");
			break;
		case 2:
			gui_print_text((UI_string_type) L"Email msg");
			gui_set_text_color(gui_color(0, 0, 0));
			gui_move_text_cursor(5, 100);
			gui_print_bordered_text((UI_string_type) L"Pass");
			break;
        case 3:
    #ifdef __MMI_EMAIL_OTAP__
            gui_print_text((UI_string_type) L"Email otap");
    #else 
            gui_print_text((UI_string_type) L"Email not support otap");
    #endif 
            gui_set_text_color(gui_color(0, 0, 0));
			gui_move_text_cursor(5, 100);
			gui_print_bordered_text((UI_string_type) L"Pass");
            break;
        case 4:
    #if defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__)
            gui_print_text((UI_string_type) L"Email emn");
    #else 
            gui_print_text((UI_string_type) L"Email not support emn");
    #endif 
			gui_set_text_color(gui_color(0, 0, 0));
			gui_move_text_cursor(5, 100);
			gui_print_bordered_text((UI_string_type) L"Pass");
            break;
        default:
            break;
    }

}


void avk_msg_email_pass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//avk_msg_email_deinit_all();
	AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(AVK_FAIL);
    screen_id = mmi_frm_scrn_get_active_id();
    mmi_frm_scrn_close(GRP_ID_AVK,screen_id);
}

void avk_msg_email_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avk_msg_email_deinit_all();
	AVK_SET_FAILKEY(AVK_FAIL);
    screen_id = mmi_frm_scrn_get_active_id();
    mmi_frm_scrn_close(GRP_ID_AVK,screen_id);
}

void avk_msg_email_init_srv_related(srv_email_init_state_enum result, S32 err_no, void *user_data)
{
    if (result == SRV_EMAIL_INIT_STATE_READY)
    {
    }
}

MMI_BOOL avk_msg_email_get_app_info_by_acct_id_for_srv(
                    srv_email_app_info_query_struct *app_info_p,
                    U16 *str_id,
                    U16 *icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_app_info_struct app_info;
    U8 app_id = CBM_INVALID_APP_ID;
    kal_int8 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //app_info.app_type = DTCNT_APPTYPE_EMAIL;
	//app_info.app_str_id
	//app_info.app_icon_id

	ret = cbm_register_app_id_with_app_info(&app_info, &app_id);
	if (ret != CBM_OK)
	{
		return MMI_FALSE;
	}

	cbm_set_app_id(app_info_p->dataacct_id, app_id);
	cbm_deregister_app_id(app_id);

	return MMI_TRUE;
}
	     

void avk_msg_email_deinit_all(void)
{
	if(avk_msg_email_cntx.msg_handle != 0)
	{
		AVK_LOG(srv_email_msg_destroy(avk_msg_email_cntx.msg_handle));
		avk_msg_email_cntx.msg_handle = 0;
	}
	
	if(avk_msg_email_cntx.fldr_handle != 0)
	{
		AVK_LOG(srv_email_fldr_clear_notify(avk_msg_email_cntx.fldr_handle));
		AVK_LOG(srv_email_fldr_destroy(avk_msg_email_cntx.fldr_handle));
		avk_msg_email_cntx.fldr_handle = 0;
	}

	if(avk_msg_email_cntx.acct_id != 0)
	{
		AVK_LOG(srv_email_acct_delete(avk_msg_email_cntx.acct_id));
		avk_msg_email_cntx.acct_id = 0;
	}
	
	if(avk_msg_email_cntx.acct_handle != 0)
	{
		AVK_LOG(srv_email_acct_del_default());
		AVK_LOG(srv_email_acct_destroy(avk_msg_email_cntx.acct_handle));
		avk_msg_email_cntx.acct_handle = 0;
	}
	
	if(avk_msg_email_cntx.srv_handle != 0)
	{
		avk_msg_email_cntx.srv_handle = 0;
	}
	
}

void avk_msg_email_notify_msg_func(const srv_email_om_notify_struct *notifyData)
{
	
}

void avk_msg_email_init_all(void)
{
	srv_email_init_state_enum res = SRV_EMAIL_INIT_STATE_ERROR;
	
	AVK_LOG(res = srv_email_get_srv_init_state());

	if (res == SRV_EMAIL_INIT_STATE_READY)
	{
		avk_msg_email_cntx.srv_handle = 0;
		avk_msg_email_cntx.acct_handle = 0;
		avk_msg_email_cntx.fldr_handle = 0;
		avk_msg_email_cntx.msg_handle = 0;
		avk_msg_email_cntx.acct_id = 0;

		AVK_LOG(srv_email_app_init_set_callback(avk_msg_email_init_srv_related, NULL));
		AVK_LOG(srv_email_create(&avk_msg_email_cntx.srv_handle));
		
		AVK_LOG(srv_email_om_set_notify(
							   SRV_EMAIL_OM_NOTIFY_OBJ_MSG,
							   &avk_msg_email_notify_msg_func,
							   &avk_msg_email_cntx.msgNotifyId));
		
        AVK_LOG_NORMAL(srv_email_om_unset_notify(SRV_EMAIL_OM_NOTIFY_OBJ_MSG, avk_msg_email_cntx.msgNotifyId));
		
		AVK_LOG(srv_email_register_app_id_query_callback(avk_msg_email_cntx.srv_handle,
            avk_msg_email_get_app_info_by_acct_id_for_srv));

	}
}


AVK_ADD_ITEM(AVK_MSG_EMAIL_MANU1,L"avk_msg_email_001_account",AVK_MSG_EMAIL);
AVK_ADD_ITEM(AVK_MSG_EMAIL_MANU2,L"avk_msg_email_002_fldr",AVK_MSG_EMAIL);
AVK_ADD_ITEM(AVK_MSG_EMAIL_MANU3,L"avk_msg_email_003_msg",AVK_MSG_EMAIL);
AVK_ADD_ITEM(AVK_MSG_EMAIL_MANU4,L"avk_msg_email_004_otap",AVK_MSG_EMAIL);
AVK_ADD_ITEM(AVK_MSG_EMAIL_MANU5,L"avk_msg_email_005_emn",AVK_MSG_EMAIL);

AVK_MANUAL_CASE(AVK_MSG_EMAIL_CASE1,AVK_MSG_EMAIL_MANU1)
{
    avk_msg_email_001_account();
}

AVK_MANUAL_CASE(AVK_MSG_EMAIL_CASE2,AVK_MSG_EMAIL_MANU2)
{
    avk_msg_email_002_fldr();
}

AVK_MANUAL_CASE(AVK_MSG_EMAIL_CASE3,AVK_MSG_EMAIL_MANU3)
{
    avk_msg_email_003_msg();
}

AVK_MANUAL_CASE(AVK_MSG_EMAIL_CASE4,AVK_MSG_EMAIL_MANU4)
{
    avk_msg_email_004_otap();
}

AVK_MANUAL_CASE(AVK_MSG_EMAIL_CASE5,AVK_MSG_EMAIL_MANU5)
{
    avk_msg_email_005_emn();
}

#endif

#endif


