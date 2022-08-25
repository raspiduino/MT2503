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
/*******************************************************************************
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/
 /*****************************************************************************
 *
 * Filename:
 * ---------
 *  CertManMMIInterfaces.c
 *
 * Project:
 * --------
 *  Certificate Manager
 *
 * Description:
 * ------------
 *   This file is intends for handling request / responses of Certificate Manager
 *
 * Author:
 * ------------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
************************************************************************************/
#ifdef __PLUTO_MMI_PACKAGE__
#ifdef __CERTMAN_SUPPORT__
#include "CertManMMIGProts.h"
#include "CertManMMIResDef.h"
#include "CertManMMITypes.h"
#include "CertManMMIProts.h"
#include "MenuCuiGprot.h"
#include "certman_struct.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "stack_config.h"
#include "certman_api.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_public_api.h"
#include "kal_release.h"
#include "MMIDataType.h"
#include "certman_defs.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "gui_data_types.h"
#include "kal_general_types.h"
#include "AlertScreen.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "NotificationGprot.h"
#include "stack_common.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_rp_app_mmi_certman_def.h"
#include "kal_trace.h"
#include "DLAgentSrvGprot.h"

/*********Global Variable**************************************************/
mmi_certman_context_struct g_mmi_certman_context = {0, };

/**************************************************************************/
/*****************************CERTMAN'S PRIMITIVE HANDLERS*****************/
/**************************************************************************/

/**************************************************************************/
/*****************************IMPORT CERTIFICATES**************************/
/**************************************************************************/

MMI_BOOL mmi_scr_locker_is_locked();

/*****************************************************************************
 * FUNCTION
 *  mmi_certman_parse_begin_cnf_handler
 * DESCRIPTION
 *  handler for begin parsing
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_parse_begin_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    certman_parse_begin_cnf_struct *parsed_begin_cnf_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G3_CER_MAN, MMI_CERTMAN_BEGIN_CNF);
    parsed_begin_cnf_p = (certman_parse_begin_cnf_struct*) msg;
    if (g_mmi_certman_context.current_status == MMI_CERTMAN_IDLE)
    {
        certman_send_parse_end_req(MOD_MMI, parsed_begin_cnf_p->trans_id, parsed_begin_cnf_p->job_id);
        return;
    }
    if (g_mmi_certman_context.current_status == MMI_CERTMAN_VIEW
     || g_mmi_certman_context.current_status == MMI_CERTMAN_INVALID)
    {
        mmi_certman_view_invalid_state(msg);
    }
    else if (g_mmi_certman_context.current_status == MMI_CERTMAN_IMPORT)
    {
        mmi_certman_import_state(msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_certificates_detail_cnf_handler
 * DESCRIPTION
 *  handler for detail confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_certificates_detail_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    certman_parse_cert_detail_cnf_struct *cert_detail_p = (certman_parse_cert_detail_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G3_CER_MAN, MMI_CERTMAN_CERTIFICATES_DETAIL_CNF);
    if (g_mmi_certman_context.current_status == MMI_CERTMAN_IDLE)
    {
        certman_parsed_data_free(cert_detail_p->parsed_data);
		cert_detail_p->parsed_data = NULL;
        return;
    }
    if (g_mmi_certman_context.current_status == MMI_CERTMAN_VIEW
     || g_mmi_certman_context.current_status == MMI_CERTMAN_INVALID)
    {
        g_mmi_certman_context.view_invalid_context_p->parsed_data_p = cert_detail_p->parsed_data;
        mmi_certman_view_invalid_state(msg);
    }
    else if (g_mmi_certman_context.current_status == MMI_CERTMAN_IMPORT)
    {
        g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_DISPLAY;
        g_mmi_certman_context.import_context_p->parsed_data_p = cert_detail_p->parsed_data;
        mmi_certman_import_state(msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_import_cnf_handler
 * DESCRIPTION
 *  handler import confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_import_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G3_CER_MAN, MMI_CERTMAN_IMPORT_CNF);
    if (g_mmi_certman_context.current_status == MMI_CERTMAN_INVALID)
    {
        mmi_certman_view_invalid_state(msg);
    }
    else if (g_mmi_certman_context.current_status == MMI_CERTMAN_IMPORT)
    {
        mmi_certman_import_state(msg);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_certman_import_update_key_purpose_cnf_handler
 * DESCRIPTION
 *  handler for update key purpose cnf
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_import_update_key_purpose_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G3_CER_MAN, MMI_CERTMAN_IMPORT_UPDATE_KEY_PURPOSE_CNF);
    if (g_mmi_certman_context.current_status == MMI_CERTMAN_IMPORT)
    {
        mmi_certman_import_state(msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_send_parse_end_cnf_handler
 * DESCRIPTION
 *  handler for parse end cnf
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_send_parse_end_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    certman_parse_end_cnf_struct *parse_end_cnf_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parse_end_cnf_p = (certman_parse_end_cnf_struct*)msg;
    MMI_TRACE(MMI_INET_TRC_G3_CER_MAN, MMI_CERTMAN_SEND_PARSE_END_CNF);
    if ((g_mmi_certman_context.current_status == MMI_CERTMAN_IDLE) || (parse_end_cnf_p == NULL))
    {
        return;
    }
    switch(g_mmi_certman_context.current_status)
    {
    case MMI_CERTMAN_IMPORT:
        {
            if ((g_mmi_certman_context.import_context_p!=NULL)&&
                (g_mmi_certman_context.import_context_p->trans_id == parse_end_cnf_p->trans_id))
            {
                mmi_frm_group_close(GRP_ID_CERTMAN_IMPORT);
            }
        }
        break;
    case MMI_CERTMAN_VIEW:
        {
            if ((g_mmi_certman_context.view_invalid_context_p!=NULL)&&
                (g_mmi_certman_context.view_invalid_context_p->trans_id == parse_end_cnf_p->trans_id))
            {
                mmi_frm_group_close(GRP_ID_CERTMAN_VIEW);
            }
        }
        break;
    case MMI_CERTMAN_INVALID:
        {
            if ((g_mmi_certman_context.view_invalid_context_p!=NULL)&&
                (g_mmi_certman_context.view_invalid_context_p->trans_id == parse_end_cnf_p->trans_id))
            {
                mmi_frm_group_close(GRP_ID_CERTMAN_INVALID);
            }
        }
        break;
    default:
        break;
    }
}

/**************************************************************************/
/*****************************lAUNCH / SELECT CERTIFICATES*****************/
/**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_get_cert_list_by_group_cnf_handler
 * DESCRIPTION
 *  handler for group cnf
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_get_cert_list_by_group_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G3_CER_MAN, MMI_CERTMAN_GET_CERT_LIST_BY_GROUP_CNF);
    if ((g_mmi_certman_context.current_status == MMI_CERTMAN_LAUNCH)
      ||(g_mmi_certman_context.current_status == MMI_CERTMAN_SELECT))
    {
        mmi_certman_launch_select_state(msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_send_get_cert_disp_by_id_cnf_handler
 * DESCRIPTION
 *  handler for cert by id cnf
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_send_get_cert_disp_by_id_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    certman_get_cert_disp_by_id_cnf_struct *disp_cnf = (certman_get_cert_disp_by_id_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G3_CER_MAN, MMI_CERTMAN_GET_CERT_DISP_BY_ID_CNF);
    /* 20071108 Sanity Test Fail Tmp Patch */
    /* g_mmi_certman_context.launch_select_context_p->display_p = &(disp_cnf->cert); */
    g_mmi_certman_context.launch_select_context_p->display_p = get_ctrl_buffer(sizeof(certman_cert_display_struct));
    kal_mem_cpy(
        g_mmi_certman_context.launch_select_context_p->display_p,
        &(disp_cnf->cert),
        sizeof(certman_cert_display_struct));
    if (g_mmi_certman_context.current_status == MMI_CERTMAN_LAUNCH)
    {
        mmi_certman_launch_select_state(msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_launch_update_key_purpose_cnf_handler
 * DESCRIPTION
 *  handler for update key purpose in launch
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_launch_update_key_purpose_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    certman_update_key_purpose_cnf_struct *key_purpose_cnf = (certman_update_key_purpose_cnf_struct*) msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G3_CER_MAN, MMI_CERTMAN_LAUNCH_UPDATE_KEY_PURPOSE_CNF);
    index = g_mmi_certman_context.launch_select_context_p->selected_index;
    if (g_mmi_certman_context.current_status == MMI_CERTMAN_LAUNCH)
    {
        if (key_purpose_cnf->status == CERTMAN_ERR_NONE)
        {
            mmi_frm_scrn_close (GRP_ID_CERTMAN_LAUNCH, SCR_ID_CERTMAN_PROGRESS_SCREEN);
            
            mmi_certman_displaypop_with_callback(
                (PU8) GetString((U16)STR_GLOBAL_DONE),
                MMI_EVENT_SUCCESS,
                mmi_certman_launch_key_usage_done_callback,
                GRP_ID_CERTMAN_LAUNCH);
        }
        else
        {
            g_mmi_certman_context.launch_select_context_p->certificate_list[index].key_purpose =
            g_mmi_certman_context.launch_select_context_p->certificate_list[index].key_purpose_change;
            mmi_certman_handle_error(key_purpose_cnf->status, g_mmi_certman_context.g_mmi_certman_active_grp);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_send_delete_cert_cnf_handler
 * DESCRIPTION
 *  handler for delete cnf
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_send_delete_cert_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    certman_delete_cert_cnf_struct *delete_cnf = (certman_delete_cert_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G3_CER_MAN, MMI_CERTMAN_SEND_DELETE_CERT_CNF);

    if (g_mmi_certman_context.current_status == MMI_CERTMAN_LAUNCH)
    {
        if (delete_cnf->status == CERTMAN_ERR_NONE)
        {
            if (certman_get_cert_count(g_mmi_certman_context.launch_select_context_p->cert_group, CERTMAN_KP_NONE))
            {
                mmi_certman_display_message_with_callback(
                    STR_GLOBAL_DELETED,
                    MMI_EVENT_SUCCESS,
                    mmi_certman_refresh_display_list,
                    GRP_ID_CERTMAN_LAUNCH);

                mmi_frm_scrn_multiple_close(
                    GRP_ID_CERTMAN_LAUNCH, 
                    SCR_ID_CERTMAN_PROGRESS_SCREEN,
                    MMI_TRUE,
                    0,
                    SCR_ID_CERTMAN_CERTIFICATE_LIST,
                    MMI_FALSE);
            }
            else
            {
                mmi_popup_display_simple((WCHAR*)((UI_string_type)GetString((U16)STR_GLOBAL_DELETED)), MMI_EVENT_SUCCESS, GRP_ID_CERTMAN_LAUNCH, NULL);
                mmi_frm_scrn_multiple_close(
                    GRP_ID_CERTMAN_LAUNCH, 
                    SCR_ID_CERTMAN_PROGRESS_SCREEN,
                    MMI_TRUE,
                    0,
                    SCR_ID_CERTMAN_CERTIFICATE_LIST,
                    MMI_TRUE);
            }
        }
        else
        {

            mmi_certman_handle_error(delete_cnf->status, GRP_ID_CERTMAN_LAUNCH);

            mmi_frm_scrn_multiple_close (
            GRP_ID_CERTMAN_LAUNCH, 
            SCR_ID_CERTMAN_PROGRESS_SCREEN,
            MMI_TRUE, 0, 
            SCR_ID_CERTMAN_CERTIFICATE_GROUPS,
            MMI_FALSE);
        }
    }
}

/*********************************************************************************/
/*****************************Personal Certificate List***************************/
/*********************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_get_cert_list_by_issuers_file_cnf_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_get_cert_list_by_issuers_file_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G3_CER_MAN, MMI_CERTMAN_GET_CERT_LIST_BY_ISSUER_FILE_CNF);
    if (g_mmi_certman_context.current_status == MMI_CERTMAN_USER_CERT_LIST)
    {
        mmi_certman_select_user_certificate_state(msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_get_cert_list_by_issuers_data_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_get_cert_list_by_issuers_data_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G3_CER_MAN, MMI_CERTMAN_GET_CERT_LIST_BY_ISSUER_DATA_IND);
    if (g_mmi_certman_context.current_status == MMI_CERTMAN_USER_CERT_LIST)
    {
        mmi_certman_select_user_certificate_state(msg);
    }
}

/*********************************************************************************/
/*****************************PRIVATE KEY PASSWORD REQUEST ***********************/
/*********************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_privkey_usage_password_ind_handler
 * DESCRIPTION
 *  handler for pwd ind
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_privkey_usage_password_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL queue_full;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_certman_context.private_key_status == MMI_CERTMAN_PRIVATE_KEY_IDLE
        || (g_mmi_certman_context.private_key_status == MMI_CERTMAN_PRIVATE_KEY_PWD
            && ((certman_privkey_usage_password_ind_struct*) msg)->state != CERTMAN_PWDAUTH_FIRST))
    {
        mmi_certman_privkey_usage_password_ind(msg);
        return;
    }
    queue_full = mmi_certman_insert_priv_key_queue(MSG_ID_CERTMAN_PRIVKEY_USAGE_PASSWORD_IND, msg);
    if (queue_full == MMI_FALSE)
    {
        certman_send_privkey_usage_password_rsp(
            MOD_MMI,
            ((certman_privkey_usage_password_ind_struct*) msg)->trans_id,
            MMI_FALSE);
        return;
    }
    if (g_mmi_certman_context.private_key_status == MMI_CERTMAN_PRIVATE_KEY_IDLE)
    {
        mmi_certman_use_priv_key_queue();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_close_select_certificate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Void          
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_close_select_certificate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	 mmi_frm_group_close(GRP_ID_CERTMAN_SELECT);
}



/***************************************************************************/
/*****************************PRIVATE KEY CONFIRMATION**********************/
/***************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_send_privkey_usage_confirm_ind_handler
 * DESCRIPTION
 *  handler for confirm ind
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_send_privkey_usage_confirm_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL queue_full;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    queue_full = mmi_certman_insert_priv_key_queue(MSG_ID_CERTMAN_PRIVKEY_USAGE_CONFIRM_IND, msg);
    if (queue_full == MMI_FALSE)
    {
        certman_send_privkey_usage_password_rsp(
            MOD_MMI,
            ((certman_privkey_usage_confirm_ind_struct*) msg)->trans_id,
            MMI_FALSE);
        return;
    }
    if (g_mmi_certman_context.private_key_status == MMI_CERTMAN_PRIVATE_KEY_IDLE)
    {
        mmi_certman_use_priv_key_queue();
    }
}

/**************************************************************************/
/*****************************CERTMAN UI Primitives************************/
/**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_install_certificates_ind
 * DESCRIPTION
 *  function to install certificate indication
 * PARAMETERS
 *  src_mod         [IN]        
 *  action          [IN]        
 *  trans_id        [IN]        
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_install_certificates_ind(
        module_type src_mod,
        kal_bool action,
        kal_uint32 trans_id,
        kal_wchar *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_install_cert_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */
    data = (mmi_certman_install_cert_ind_struct*) OslConstructDataPtr(sizeof(mmi_certman_install_cert_ind_struct));
    mmi_ucs2cpy((S8*) data->cert_filename, (S8*) filename);
    data->action = action;
    data->trans_id = trans_id;
    g_mmi_certman_context.src_module = src_mod;

    mmi_certman_send_msg_on_queue(
        g_mmi_certman_context.src_module,
        MOD_MMI,
        (void*)data,
        MSG_ID_MMI_CERTMAN_INSTALL_CERT_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_install_certificates_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_install_certificates_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL queue_full;
    mmi_certman_install_cert_ind_struct *install_certificate_ind = (mmi_certman_install_cert_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (install_certificate_ind->action == MMI_CERTMAN_CANCEL)
    {
        if ((g_mmi_certman_context.src_module == g_mmi_certman_context.curr_module)
            && g_mmi_certman_context.current_status == MMI_CERTMAN_IMPORT)
        {
            if (g_mmi_certman_context.import_context_p->trans_id == install_certificate_ind->trans_id)
            {
                mmi_frm_group_close(GRP_ID_CERTMAN_IMPORT);
            }
            else
            {
                mmi_certman_delete_task_queue(
                    g_mmi_certman_context.src_module,
                    MSG_ID_MMI_CERTMAN_INSTALL_CERT_IND,
                    msg);
            }
        }
        else
        {
            mmi_certman_delete_task_queue(g_mmi_certman_context.src_module, MSG_ID_MMI_CERTMAN_INSTALL_CERT_IND, msg);
        }
    }
    else
    {	
	
#ifdef __DM_LAWMO_SUPPORT__
		if (TRUE == mmi_dmui_is_phone_lock())
		{
			queue_full = mmi_certman_insert_task_queue(
                            g_mmi_certman_context.src_module,
                            MSG_ID_MMI_CERTMAN_INSTALL_CERT_IND,
                            msg);
            if (queue_full == MMI_FALSE)
            {
                mmi_certman_install_certificates_rsp(MMI_FALSE, install_certificate_ind->trans_id);
            }
			return;
		}
#endif

        if (g_mmi_certman_context.current_status == MMI_CERTMAN_IDLE)
        {
            g_mmi_certman_context.curr_module = g_mmi_certman_context.src_module;
            mmi_certman_import_init(msg);
        }
        else
        {
            queue_full = mmi_certman_insert_task_queue(
                            g_mmi_certman_context.src_module,
                            MSG_ID_MMI_CERTMAN_INSTALL_CERT_IND,
                            msg);
            if (queue_full == MMI_FALSE)
            {
                mmi_certman_install_certificates_rsp(MMI_FALSE, install_certificate_ind->trans_id);
                return;
            }
        }
    }
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_install_certificates_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  trans_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_install_certificates_rsp(kal_bool result, kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_certman_install_cert_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */
    data = (mmi_certman_install_cert_rsp_struct*) OslConstructDataPtr(sizeof(mmi_certman_install_cert_rsp_struct));
    data->result = result;
    data->trans_id = trans_id;
    /* Send the response message. */
    mmi_certman_send_msg_on_queue(
        MOD_MMI,
        g_mmi_certman_context.curr_module,
        (void*)data,
        MSG_ID_MMI_CERTMAN_INSTALL_CERT_RSP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_certman_is_invalid_popup
 * DESCRIPTION
 *  
       
 * RETURNS
 *  True if certman showing popup
 *  False if no popup shown by certman
 *****************************************************************************/
MMI_BOOL mmi_certman_is_invalid_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	if(g_mmi_certman_context.view_invalid_context_p == NULL)
        return MMI_FALSE;
	else
	    return MMI_TRUE;
		
   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_certman_launch_certificates_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod         [IN]        
 *  action          [IN]        
 *  trans_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_launch_certificates_ind(module_type src_mod, kal_bool action, kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_certman_launch_cert_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_certman_launch_cert_ind_struct*) OslConstructDataPtr(sizeof(mmi_certman_launch_cert_ind_struct));
    data->action = action;
    data->trans_id = trans_id;
    g_mmi_certman_context.src_module = src_mod;
    mmi_certman_send_msg_on_queue(
        g_mmi_certman_context.src_module,
        MOD_MMI,
        (void*)data,
        MSG_ID_MMI_CERTMAN_LAUNCH_CERT_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_launch_certificates_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  trans_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_launch_certificates_rsp(kal_bool result, kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_certman_launch_cert_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  Allocate memory  */
    data = (mmi_certman_launch_cert_rsp_struct*) OslConstructDataPtr(sizeof(mmi_certman_launch_cert_rsp_struct));
    data->result = result;
    data->trans_id = trans_id;
    /* Send the response message */
    mmi_certman_send_msg_on_queue(
        MOD_MMI,
        g_mmi_certman_context.curr_module,
        (void*)data,
        MSG_ID_MMI_CERTMAN_LAUNCH_CERT_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_launch_certificates_ind_handler
 * DESCRIPTION
 *  function to launch CM
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_launch_certificates_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL queue_full;
    mmi_certman_launch_cert_ind_struct *launch_certificate_ind = (mmi_certman_launch_cert_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (launch_certificate_ind->action == MMI_CERTMAN_CANCEL)
    {
        if ((g_mmi_certman_context.src_module == g_mmi_certman_context.curr_module)
            && g_mmi_certman_context.current_status == MMI_CERTMAN_LAUNCH)
        {
            if (g_mmi_certman_context.launch_select_context_p->trans_id == launch_certificate_ind->trans_id)
            {
                mmi_frm_group_close(GRP_ID_CERTMAN_LAUNCH);
            }
            else
            {
                mmi_certman_delete_task_queue(
                    g_mmi_certman_context.src_module,
                    MSG_ID_MMI_CERTMAN_LAUNCH_CERT_IND,
                    msg);
            }
        }
        else
        {
            mmi_certman_delete_task_queue(g_mmi_certman_context.src_module, MSG_ID_MMI_CERTMAN_LAUNCH_CERT_IND, msg);
        }
    }
    else
    {
#ifdef __DM_LAWMO_SUPPORT__
		if (TRUE == mmi_dmui_is_phone_lock())
		{
			queue_full = mmi_certman_insert_task_queue(
                            g_mmi_certman_context.src_module,
                            MSG_ID_MMI_CERTMAN_LAUNCH_CERT_IND,
                            msg);
            if (queue_full == MMI_FALSE)
            {
                mmi_certman_launch_certificates_rsp(MMI_FALSE, launch_certificate_ind->trans_id);
            }
			return;
		}
#endif

        if (g_mmi_certman_context.current_status == MMI_CERTMAN_IDLE)
        {
            g_mmi_certman_context.curr_module = g_mmi_certman_context.src_module;
            mmi_certman_launch_init(msg);
        }
        else
        {
            queue_full = mmi_certman_insert_task_queue(
                            g_mmi_certman_context.src_module,
                            MSG_ID_MMI_CERTMAN_LAUNCH_CERT_IND,
                            msg);
            if (queue_full == MMI_FALSE)
            {
                mmi_certman_launch_certificates_rsp(MMI_FALSE, launch_certificate_ind->trans_id);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_certificates_ind
 * DESCRIPTION
 *  function to select certificate
 * PARAMETERS
 *  src_mod                     [IN]        
 *  action                      [IN]        
 *  multiple_selection_flag     [IN]        
 *  trans_id                    [IN]        
 *  cert_group                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_certificates_ind(
        module_type src_mod,
        kal_bool action,
        kal_bool multiple_selection_flag,
        kal_uint32 trans_id,
        mmi_certman_cert_group_enum cert_group,
        kal_uint32 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_certman_select_cert_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_certman_select_cert_ind_struct*) OslConstructDataPtr(sizeof(mmi_certman_select_cert_ind_struct));
    data->action = action;
    data->trans_id = trans_id;
    data->multiple_selection_flag = multiple_selection_flag;
    data->cert_group = cert_group;
    data->key_type = key_type;
    g_mmi_certman_context.src_module = src_mod;
    mmi_certman_send_msg_on_queue(
        g_mmi_certman_context.src_module,
        MOD_MMI,
        (void*)data,
        MSG_ID_MMI_CERTMAN_SELECT_CERT_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_certificates_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result              [IN]        
 *  count               [IN]        
 *  certificate_ids     [IN]        
 *  trans_id            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_certificates_rsp(
        kal_bool result,
        kal_uint32 count,
        kal_uint32 *certificate_ids,
        kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_certman_select_cert_rsp_struct *data;
    U16 temp_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */
    data = (mmi_certman_select_cert_rsp_struct*) OslConstructDataPtr(sizeof(mmi_certman_select_cert_rsp_struct));
    data->result = result;
    data->trans_id = trans_id;
    if (result == MMI_TRUE)
    {
        data->count = count;
        for (temp_count = 0; temp_count < count; temp_count++)
        {
            data->cert_ids[temp_count] = certificate_ids[temp_count];
        }
    }

    /* Send the response message. */
    mmi_certman_send_msg_on_queue(
        MOD_MMI,
        g_mmi_certman_context.curr_module,
        (void*)data,
        MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_certificates_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_certificates_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL queue_full;
    mmi_certman_select_cert_ind_struct *select_certificate_ind = (mmi_certman_select_cert_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (select_certificate_ind->action == MMI_CERTMAN_CANCEL)
    {
        if ((g_mmi_certman_context.src_module == g_mmi_certman_context.curr_module)
            && g_mmi_certman_context.current_status == MMI_CERTMAN_SELECT)
        {
            if (g_mmi_certman_context.launch_select_context_p->trans_id == select_certificate_ind->trans_id)
            {
                mmi_frm_group_close(GRP_ID_CERTMAN_SELECT);
            }
            else
            {
                mmi_certman_delete_task_queue(
                    g_mmi_certman_context.src_module,
                    MSG_ID_MMI_CERTMAN_SELECT_CERT_IND,
                    msg);
            }
        }
        else
        {
            mmi_certman_delete_task_queue(g_mmi_certman_context.src_module, MSG_ID_MMI_CERTMAN_SELECT_CERT_IND, msg);
        }
    }
    else
    {
#ifdef __DM_LAWMO_SUPPORT__
		if (TRUE == mmi_dmui_is_phone_lock())
		{
			queue_full = mmi_certman_insert_task_queue(
                            g_mmi_certman_context.src_module,
                            MSG_ID_MMI_CERTMAN_SELECT_CERT_IND,
                            msg);
            if (queue_full == MMI_FALSE)
            {
                mmi_certman_select_certificates_rsp(MMI_FALSE, 0, 0, select_certificate_ind->trans_id);
            }
		    return;
		}
#endif

       if ((g_mmi_certman_context.current_status == MMI_CERTMAN_SELECT)){
		    mmi_certman_exit_select_certificate();
                 }

        if ((g_mmi_certman_context.current_status == MMI_CERTMAN_IDLE))
        {
            g_mmi_certman_context.curr_module = g_mmi_certman_context.src_module;
            mmi_certman_select_init(msg);
        }
        else
        {
            queue_full = mmi_certman_insert_task_queue(
                            g_mmi_certman_context.src_module,
                            MSG_ID_MMI_CERTMAN_SELECT_CERT_IND,
                            msg);
            if (queue_full == MMI_FALSE)
            {
                mmi_certman_select_certificates_rsp(MMI_FALSE, 0, 0, select_certificate_ind->trans_id);
            }
        }
    }
}


/*****************************************************************************
 *  
 * FUNCTION
 *  mmi_certman_view_certificates_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod         [IN]        
 *  action          [IN]        
 *  file_name       [IN]        
 *  trans_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_view_certificates_ind(module_type src_mod, kal_bool action, kal_wchar *file_name, kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_view_cert_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */
    data = (mmi_certman_view_cert_ind_struct*) OslConstructDataPtr(sizeof(mmi_certman_view_cert_ind_struct));
    data->action = action;
    data->trans_id = trans_id;
    mmi_ucs2cpy((S8*) data->filename, (S8*) file_name);
    g_mmi_certman_context.src_module = src_mod;
    mmi_certman_send_msg_on_queue(
        g_mmi_certman_context.src_module,
        MOD_MMI,
        (void*)data,
        MSG_ID_MMI_CERTMAN_VIEW_CERT_IND);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_view_certificates_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_view_certificates_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL queue_full;
    mmi_certman_view_cert_ind_struct *view_certificate_ind = (mmi_certman_view_cert_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (view_certificate_ind->action == MMI_CERTMAN_CANCEL)
    {
        if ((g_mmi_certman_context.src_module == g_mmi_certman_context.curr_module)
            && g_mmi_certman_context.current_status == MMI_CERTMAN_VIEW)
        {
            if (g_mmi_certman_context.view_invalid_context_p->trans_id == view_certificate_ind->trans_id)
            {
                mmi_frm_group_close(GRP_ID_CERTMAN_VIEW);

            }
            else
            {
                mmi_certman_delete_task_queue(g_mmi_certman_context.src_module, MSG_ID_MMI_CERTMAN_VIEW_CERT_IND, msg);
            }
        }
        else
        {
            mmi_certman_delete_task_queue(g_mmi_certman_context.src_module, MSG_ID_MMI_CERTMAN_VIEW_CERT_IND, msg);
        }
    }
    else
    {

#ifdef __DM_LAWMO_SUPPORT__
		if (TRUE == mmi_dmui_is_phone_lock())
		{
		    queue_full = mmi_certman_insert_task_queue(g_mmi_certman_context.src_module, MSG_ID_MMI_CERTMAN_VIEW_CERT_IND, msg);
            if (queue_full == MMI_FALSE)
            {
                mmi_certman_view_certificates_rsp(MMI_FALSE, view_certificate_ind->trans_id);
            }
			return;
		}
#endif

        if ((g_mmi_certman_context.current_status == MMI_CERTMAN_IDLE)&&(!(mmi_scr_locker_is_locked())))
        {
            g_mmi_certman_context.curr_module = g_mmi_certman_context.src_module;
            mmi_certman_view_init(msg);
        }
        else
        {
            queue_full = mmi_certman_insert_task_queue(g_mmi_certman_context.src_module, MSG_ID_MMI_CERTMAN_VIEW_CERT_IND, msg);
            if (queue_full == MMI_FALSE)
            {
                mmi_certman_view_certificates_rsp(MMI_FALSE, view_certificate_ind->trans_id);
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_view_certificates_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  trans_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_view_certificates_rsp(kal_bool result, kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_view_cert_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */

    data = (mmi_certman_view_cert_rsp_struct*) OslConstructDataPtr(sizeof(mmi_certman_view_cert_rsp_struct));
    data->result = result;
    data->trans_id = trans_id;
    /* Send the response message. */
    mmi_certman_send_msg_on_queue(
        MOD_MMI,
        g_mmi_certman_context.curr_module,
        (void*)data,
        MSG_ID_MMI_CERTMAN_VIEW_CERT_RSP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_invalid_certificates_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod             [IN]        
 *  action              [IN]        
 *  disable_install     [IN]        
 *  error               [IN]        
 *  mod_name            [IN]        
 *  cert_filename       [IN]        
 *  trans_id            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_invalid_certificates_ind(
        module_type src_mod,
        kal_bool action,
        kal_bool disable_install,
        kal_uint32 error,
        kal_uint16 mod_name,
        kal_wchar *cert_filename,
        kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_invalid_cert_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */
    data = (mmi_certman_invalid_cert_ind_struct*) OslConstructDataPtr(sizeof(mmi_certman_invalid_cert_ind_struct));
    data->action = action;
    data->trans_id = trans_id;
    data->disable_install_option = disable_install;
    data->error = error;
    data->mod_name = mod_name;
    mmi_ucs2cpy((S8*) data->cert_filename, (S8*) cert_filename);
    g_mmi_certman_context.src_module = src_mod;
    /* Send the response message. */
    mmi_certman_send_msg_on_queue(
        g_mmi_certman_context.src_module,
        MOD_MMI,
        (void*)data,
        MSG_ID_MMI_CERTMAN_INVALID_CERT_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_invalid_certificates_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  invalid_cert_action     [IN]        
 *  trans_id                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_invalid_certificates_rsp(kal_uint16 invalid_cert_action, kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_invalid_cert_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */
    data = (mmi_certman_invalid_cert_rsp_struct*) OslConstructDataPtr(sizeof(mmi_certman_invalid_cert_rsp_struct));
    data->invalid_cert_action = invalid_cert_action;
    if (invalid_cert_action == MMI_CERTMAN_INVALID_CERT_DENY)
    {
        data->result = MMI_FALSE;
    }
    else
    {
        data->result = MMI_TRUE;
    }
    data->trans_id = trans_id;
    /* Send the response message. */
    mmi_certman_send_msg_on_queue(
        MOD_MMI,
        g_mmi_certman_context.curr_module,
        (void*)data,
        MSG_ID_MMI_CERTMAN_INVALID_CERT_RSP);
    mmi_frm_end_scenario(MMI_SCENARIO_ID_CERTMAN_INVALID_CERT);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_certman_nmgr_notify_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scen_id            [IN]        
 *  msg                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_certman_nmgr_notify_hdlr(mmi_scenario_id scen_id, void *msg)
{
    pBOOL queue_full;

    if (scen_id == MMI_SCENARIO_ID_CERTMAN_INVALID_CERT)
    {
        mmi_certman_invalid_cert_ind_struct *invalid_certificate_ind = (mmi_certman_invalid_cert_ind_struct*) msg;
        if (invalid_certificate_ind->action == MMI_CERTMAN_CANCEL)
        {
            if ((g_mmi_certman_context.src_module == g_mmi_certman_context.curr_module)
                && g_mmi_certman_context.current_status == MMI_CERTMAN_INVALID)
            {
                    if (g_mmi_certman_context.view_invalid_context_p->trans_id == invalid_certificate_ind->trans_id)
                    {
                        mmi_frm_group_close(GRP_ID_CERTMAN_INVALID);
                    }
                else
                {
                    mmi_certman_delete_task_queue(
                        g_mmi_certman_context.src_module,
                        MSG_ID_MMI_CERTMAN_INVALID_CERT_IND,
                        msg);
                }
            }
            else
            {
                mmi_certman_delete_task_queue(g_mmi_certman_context.src_module, MSG_ID_MMI_CERTMAN_INVALID_CERT_IND, msg);
            }
        }
        else
        {
            mmi_frm_start_scenario(MMI_SCENARIO_ID_CERTMAN_INVALID_CERT);
            if (g_mmi_certman_context.current_status == MMI_CERTMAN_IDLE )
            {
                g_mmi_certman_context.curr_module = g_mmi_certman_context.src_module;
                mmi_certman_invalid_certificate_init(msg);
            }
            else
            {
                queue_full = mmi_certman_insert_task_queue(
                                g_mmi_certman_context.src_module,
                                MSG_ID_MMI_CERTMAN_INVALID_CERT_IND,
                                msg);
                if (queue_full == MMI_FALSE)
                {
                    mmi_certman_invalid_certificates_rsp(MMI_CERTMAN_INVALID_CERT_DENY, invalid_certificate_ind->trans_id);
                }
            }
        }
    }
    else if (scen_id == MMI_SCENARIO_ID_CERTMAN_USER_CERT)
    {
        mmi_certman_select_user_cert_ind_struct *user_certificate_ind = (mmi_certman_select_user_cert_ind_struct*) msg;
        if (user_certificate_ind->action == MMI_CERTMAN_CANCEL)
        {
            if ((g_mmi_certman_context.src_module == g_mmi_certman_context.curr_module)
                && g_mmi_certman_context.current_status == MMI_CERTMAN_USER_CERT_LIST)
            {
                if (g_mmi_certman_context.user_cert_list_context_p->trans_id == user_certificate_ind->trans_id)
                {
                    mmi_frm_group_close(GRP_ID_CERTMAN_SELECT_USER);  
                }
                else
                {
                    mmi_certman_delete_task_queue(
                        g_mmi_certman_context.src_module,
                        MSG_ID_MMI_CERTMAN_SELECT_USER_CERT_IND,
                        msg);
                }
            }
            else
            {
                mmi_certman_delete_task_queue(
                    g_mmi_certman_context.src_module,
                    MSG_ID_MMI_CERTMAN_SELECT_USER_CERT_IND,
                    msg);
            }
        }
        else
        {
            mmi_frm_start_scenario(MMI_SCENARIO_ID_CERTMAN_USER_CERT);
            if (g_mmi_certman_context.current_status == MMI_CERTMAN_IDLE )
            {
                g_mmi_certman_context.curr_module = g_mmi_certman_context.src_module;
                mmi_certman_select_user_certificates_init(msg);
            }
            else
            {
                queue_full = mmi_certman_insert_task_queue(
                                g_mmi_certman_context.src_module,
                                MSG_ID_MMI_CERTMAN_SELECT_USER_CERT_IND,
                                msg);
                if (queue_full == MMI_FALSE)
                {
                    mmi_certman_select_user_certificates_rsp(0, MMI_FALSE, user_certificate_ind->trans_id);
                }
            }
        }
    }
    mmi_certman_free(msg);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_invalid_certificates_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_invalid_certificates_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    pBOOL queue_full;
#endif /* __DM_LAWMO_SUPPORT__ */
    mmi_certman_invalid_cert_ind_struct *invalid_certificate_ind = (mmi_certman_invalid_cert_ind_struct*) msg;
    mmi_certman_invalid_cert_ind_struct *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
	if (TRUE == mmi_dmui_is_phone_lock())
	{
            queue_full = mmi_certman_insert_task_queue(
                            g_mmi_certman_context.src_module,
                            MSG_ID_MMI_CERTMAN_INVALID_CERT_IND,
                            msg);
            if (queue_full == MMI_FALSE)
            {
                mmi_certman_invalid_certificates_rsp(MMI_CERTMAN_INVALID_CERT_DENY, invalid_certificate_ind->trans_id);
            }
	    return;
	}
#endif

    temp = (mmi_certman_invalid_cert_ind_struct*)mmi_certman_malloc(sizeof(mmi_certman_invalid_cert_ind_struct));
    
    temp->ref_count = invalid_certificate_ind->ref_count;
    temp->msg_len = invalid_certificate_ind->msg_len;
    temp->action = invalid_certificate_ind->action;
    temp->disable_install_option = invalid_certificate_ind->disable_install_option;
    temp->error = invalid_certificate_ind->error;
    temp->mod_name = invalid_certificate_ind->mod_name;
    temp->trans_id = invalid_certificate_ind->trans_id;
    memcpy (
        temp->cert_filename,
        invalid_certificate_ind->cert_filename,
        MMI_CERTMAN_MAX_FILE_PATH_LENGTH);

    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_CERTMAN_INVALID_CERT,
        MMI_EVENT_DEFAULT,
        mmi_certman_nmgr_notify_hdlr,
        temp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_user_certificates_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod                 [IN]        
 *  action                  [IN]        
 *  key_purpose             [IN]        
 *  cert_type_len           [IN]        
 *  cert_types              [IN]        
 *  mod_name                [IN]        
 *  issuers_filename        [IN]        
 *  trans_id                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_user_certificates_ind(
        module_type src_mod,
        kal_bool action,
        kal_uint32 key_purpose,
        kal_uint8 cert_type_len,
        kal_uint8 *cert_types,
        kal_uint16 mod_name,
        kal_wchar *issuers_filename,
        kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_select_user_cert_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data =
        (mmi_certman_select_user_cert_ind_struct*)
        OslConstructDataPtr(sizeof(mmi_certman_select_user_cert_ind_struct));

    data->action = action;
    data->trans_id = trans_id;
    data->key_purpose = key_purpose;
    data->cert_type_len = cert_type_len;
    memcpy((S8*) data->cert_types, (S8*) cert_types, data->cert_type_len);
    data->mod_name = mod_name;
    mmi_ucs2cpy((S8*) data->issuer_filename, (S8*) issuers_filename);
    g_mmi_certman_context.src_module = src_mod;
    mmi_certman_send_msg_on_queue(
        g_mmi_certman_context.src_module,
        MOD_MMI,
        (void*)data,
        MSG_ID_MMI_CERTMAN_SELECT_USER_CERT_IND);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_user_certificates_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cert_id         [IN]        
 *  result          [IN]        
 *  trans_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_user_certificates_rsp(kal_uint32 cert_id, kal_bool result, kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_select_user_cert_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */

    data =
        (mmi_certman_select_user_cert_rsp_struct*)
        OslConstructDataPtr(sizeof(mmi_certman_select_user_cert_rsp_struct));
    data->personal_cert_id = cert_id;
    data->result = result;
    data->trans_id = trans_id;
    /* Send the response message */
    mmi_certman_send_msg_on_queue(
        MOD_MMI,
        g_mmi_certman_context.curr_module,
        (void*)data,
        MSG_ID_MMI_CERTMAN_SELECT_USER_CERT_RSP);

    /* end scenario in response, cannot start scenario
       in mmi_certman_select_user_certificates_ind as it
       may be called more than once for the same scenario */
    mmi_frm_end_scenario(MMI_SCENARIO_ID_CERTMAN_USER_CERT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_send_msg_on_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod         [IN]        
 *  dest_mod        [IN]        
 *  data            [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_send_msg_on_queue(module_type src_mod, module_type dest_mod, void *data, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = src_mod;
    Message.oslDestId = dest_mod;
    Message.oslMsgId = msg_id;
    Message.oslSapId = MMI_CERTMAN_APP_SAP;
    Message.oslDataPtr = (oslParaType*) data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_user_certificates_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_user_certificates_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    pBOOL queue_full;
#endif /* __DM_LAWMO_SUPPORT__ */    
    mmi_certman_select_user_cert_ind_struct *user_certificate_ind = (mmi_certman_select_user_cert_ind_struct*) msg;
    mmi_certman_select_user_cert_ind_struct *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __DM_LAWMO_SUPPORT__
	if (TRUE == mmi_dmui_is_phone_lock())
	{
		queue_full = mmi_certman_insert_task_queue(
                            g_mmi_certman_context.src_module,
                            MSG_ID_MMI_CERTMAN_SELECT_USER_CERT_IND,
                            msg);
        if (queue_full == MMI_FALSE)
        {
            mmi_certman_select_user_certificates_rsp(0, MMI_FALSE, user_certificate_ind->trans_id);
        }
		return;
	}
#endif


    temp = (mmi_certman_select_user_cert_ind_struct*)mmi_certman_malloc(sizeof(mmi_certman_select_user_cert_ind_struct));

    temp->ref_count = user_certificate_ind->ref_count;
    temp->msg_len = user_certificate_ind->msg_len;
    temp->action = user_certificate_ind->action;
    temp->cert_type_len = user_certificate_ind->cert_type_len;
    temp->key_purpose = user_certificate_ind->key_purpose;
    temp->mod_name = user_certificate_ind->mod_name;
    temp->trans_id = user_certificate_ind->trans_id;

    memcpy(temp->issuer_filename, user_certificate_ind->issuer_filename, MMI_CERTMAN_MAX_FILE_PATH_LENGTH);
    memcpy(temp->cert_types, user_certificate_ind->cert_types, MMI_CERTMAN_MAX_CERT_TYPES);

    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_CERTMAN_USER_CERT,
        MMI_EVENT_DEFAULT,
        mmi_certman_nmgr_notify_hdlr,
        temp);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_highlight_install
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_highlight_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_certman_pre_enter_install, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_secset_main_menu_proc
 * DESCRIPTION
 *  Menu proc for security setting main menu
 *  The menu event of security setting menu will propogated into this function,
 *  we should only processed the event content we are interested in but ignore
 *  others.
 * PARAMETERS
 *  evt     [IN] cui_menu_event_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_certman_secset_main_menu_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            menu_evt = (cui_menu_event_struct*)evt;
            if (menu_evt->highlighted_menu_id == MENU_CERTIFICATE_MANAGER)
            {
                mmi_certman_launch_certficate_manager();
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_install_da_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_id                  [IN]        
 *  mime_type                   [IN]        
 *  mime_subtype                [IN]        
 *  action_type                 [IN]        
 *  filename                    [IN]        
 *  download_url                [IN]        
 *  mime_type_str_string        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_install_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action_type,
        PU16 filename,
        PS8 download_url,
        PS8 mime_type_str_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_install_certificates_ind(MOD_MMI, MMI_CERTMAN_OPEN, 1, (kal_wchar*) filename);
}


mmi_ret mmi_certman_install_da_file_hdlr(mmi_event_struct *param)
{
	srv_da_certman_install_file  *evt = (srv_da_certman_install_file *)param;
	mmi_certman_install_certificates_ind(MOD_MMI, MMI_CERTMAN_OPEN, 1, (kal_wchar*) (evt->filename));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_read_task_queue_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_read_task_queue_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_use_task_queue();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_read_task_queue_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_read_task_queue_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_certman_read_queue_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */
    data = (mmi_certman_read_queue_ind_struct*) OslConstructDataPtr(sizeof(mmi_certman_read_queue_ind_struct));
    /* Send the response message. */
    mmi_certman_send_msg_on_queue(MOD_MMI, MOD_MMI, (void*)data, MSG_ID_MMI_CERTMAN_READ_TASK_QUEUE_IND);
}
#else
/*****************************************************************************
 * FUNCTION
 *  mmi_certman_is_invalid_popup
 * DESCRIPTION
 *  
       
 * RETURNS
 * FALSE
 *****************************************************************************/
MMI_BOOL mmi_certman_is_invalid_popup(void)
{ 
       return MMI_FALSE;

}

#endif /* __CERTMAN_SUPPORT__ */ 
#endif /* __PLUTO_MMI_PACKAGE__  */
