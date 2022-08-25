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
 * WAPProfileMain.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is main source file for UPP profile module.
 *
 * Author: Ramneek Kalra
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"


#ifdef __COSMOS_MMI_PACKAGE__
#ifdef __cplusplus
extern "C"
{
#endif
	
#include "vapp_dtcnt_gprot.h"
#include "vapp_dtcnt_cui_gprot.h"

#ifdef __cplusplus
}
#endif
#else
#include "DataAccountGProt.h"
#include "DataAccountCUIGprot.h"
#endif

#include "Wap_ps_struct.h"
#include "custom_nvram_editor_data_item.h"
#include "UcmSrvGprot.h" /* UCM 3.0 */
//#include "Nvram_enums.h"
//#include "ConnectManageGprot.h"
//#include "SettingProfile.h"     /* Error tones */
#include "Conversions.h"
//#include "CallManagementIdDef.h"
#include "UCMGprot.h"   /* GetCmMarkerScrnID */

//#include "CommonScreens.h"


#include "DtcntSrvGprot.h"

#include "Custom_data_account.h"
//#include "dtcntsrviprot.h"


#ifdef __MMI_WAP_PROF__

#include "WAPProfConfig.h"
#include "WAPProfileType.h"
#include "WAPProvisioningSrvType.h"        /* prov action enum. */
#include "WAPProfileProt.h"
#include "WAPProfileGprot.h"
#include "WAPProfResDef.h"
#include "mmi_rp_app_mmi_wap_prof_def.h"
#include "WAPProvisioningSrvProt.h"  
#include "WAPProvisioningProt.h"        /* For prov init. */
#include "app_url.h"
//#include "UCMResDef.h"

//------------------------------ suggest Add ------------------------------

#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "MMI_inet_app_trc.h"
#include "kal_public_api.h"
#include "cbm_api.h"
#include "kal_general_types.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "cbm_consts.h"
#include "string.h"
#include "stack_config.h"
#include "mmi_frm_scenario_gprot.h"
#include "common_nvram_editor_data_item.h"
#include "Unicodexdcl.h"
#include "stdio.h"
#include "mmi_frm_mem_gprot.h"
//#include "app_buff_alloc.h"
#include "mmi_frm_history_gprot.h"
//------------------------------ usage ------------------------------




#ifdef __COSMOS_MMI_PACKAGE__
//extern  enum VappDtcntAcctValidTypeEnum;
#endif

mmi_wap_prof_context_struct g_mmi_wap_prof_cntx;

static mmi_ret mmi_wap_prof_dtcnt_profile_changes_reg_event(void *user_data);
static S32 mmi_wap_prof_dtcnt_changed_handler(mmi_event_struct* param);

static mmi_wap_prof_job_list_data_struct *g_mmi_wap_prof_job_list_p;
static U8 g_mmi_wap_prof_job_count = 0;
static U8 g_mmi_wap_prof_wifi_prefer_flag = 0;
static mmi_wap_prof_job_list_data_struct *g_mmi_wap_prof_job_list_last_p;

mmi_id  mmi_wap_prof_dtcnt_cui_id =  GRP_ID_INVALID;


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_add_job
 * DESCRIPTION
 *  Adds job to job list.
 * PARAMETERS
 *  job_type        [IN]        
 *  mod_id          [IN]        
 *  sim_id          [IN]        
 *  app_id          [IN]        
 *  data            [?]         
 *  msg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_add_job(
        mmi_wap_prof_job_type_enum job_type,
        U16 mod_id,
        mmi_wap_prof_sim_id_enum sim_id,
        mmi_wap_prof_app_id_enum app_id,
        void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_ADD_JOB, g_mmi_wap_prof_job_count, job_type);

    if (!(g_mmi_wap_prof_job_list_p))
    {
        /* List empty */
        g_mmi_wap_prof_job_list_p =
            (mmi_wap_prof_job_list_data_struct*) mmi_wap_prof_mem_allocate(sizeof(mmi_wap_prof_job_list_data_struct));
        g_mmi_wap_prof_job_list_last_p = g_mmi_wap_prof_job_list_p;
    }
    else
    {
        /* List contains data */
        ASSERT(g_mmi_wap_prof_job_list_last_p);
        g_mmi_wap_prof_job_list_last_p->next =
            (mmi_wap_prof_job_list_data_struct*) mmi_wap_prof_mem_allocate(sizeof(mmi_wap_prof_job_list_data_struct));
        g_mmi_wap_prof_job_list_last_p = g_mmi_wap_prof_job_list_last_p->next;
    }

    g_mmi_wap_prof_job_list_last_p->job_type = job_type;
    g_mmi_wap_prof_job_list_last_p->src_mod_id = mod_id;
    g_mmi_wap_prof_job_list_last_p->job_sim_id = sim_id;
    g_mmi_wap_prof_job_list_last_p->job_app_id = app_id;
    g_mmi_wap_prof_job_list_last_p->job_data = data;
    g_mmi_wap_prof_job_list_last_p->next = NULL;
    g_mmi_wap_prof_job_count++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_delete_job
 * DESCRIPTION
 *  Deletes the current job which has been processed.
 * PARAMETERS
 *  void
 *  msg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_delete_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_prof_job_list_data_struct *lp_job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_WAP_PROF_TRC_GRP9,
        TRC_MMI_WAP_PROF_DELETE_JOB,
        g_mmi_wap_prof_job_count);

    if (g_mmi_wap_prof_job_list_p)
    {
        lp_job = g_mmi_wap_prof_job_list_p->next;
        mmi_wap_prof_mem_free(g_mmi_wap_prof_job_list_p);
        g_mmi_wap_prof_job_list_p = NULL;
        g_mmi_wap_prof_job_count--;
        g_mmi_wap_prof_job_list_p = lp_job;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_process_job
 * DESCRIPTION
 *  Processes current job.
 * PARAMETERS
 *  void
 *  msg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_process_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_prof_profile_content_struct *profile_content;
    mmi_wap_prof_get_profile_rsp_funcptr_type temp_func_ptr;
    mmi_wap_prof_job_get_profile_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_wap_prof_job_list_p)
    {
        MMI_TRACE(
            MMI_WAP_PROF_TRC_GRP9,
            TRC_MMI_WAP_PROF_PROCESS_JOB,
            g_mmi_wap_prof_job_count,
            g_mmi_wap_prof_job_list_p->job_type);
        switch (g_mmi_wap_prof_job_list_p->job_type)
        {
            case MMI_WAP_PROF_JOB_GET_PROFILE_CONTENT:
            {
                job_data = (mmi_wap_prof_job_get_profile_struct*) g_mmi_wap_prof_job_list_p->job_data;
                profile_content = mmi_wap_prof_get_profile_content(
                                    g_mmi_wap_prof_job_list_p->job_sim_id,
                                    g_mmi_wap_prof_job_list_p->job_app_id,
                                    job_data->profile_id,
                                    job_data->dtcnt_type,
                                    NULL);

                //10ADA
              /*  if (job_data->callback)
                {*/
                    MMI_TRACE(
                        MMI_WAP_PROF_TRC_GRP9,
                        TRC_MMI_WAP_PROF_JOB_GET_PROFILE_CONTENT_CALLBACK_RSP,
                        g_mmi_wap_prof_job_list_p->src_mod_id);
                    /* Function ptr exists (Q05a) reply through callback. mem will be freed in the callback by Q05a */
                    temp_func_ptr = (mmi_wap_prof_get_profile_rsp_funcptr_type) (job_data->callback);

                    temp_func_ptr(g_mmi_wap_prof_job_list_p->job_sim_id, profile_content);

            /*    } //10ADA
                else
                {
                    MMI_TRACE(
                        MMI_WAP_PROF_TRC_GRP9,
                        TRC_MMI_WAP_PROF_JOB_GET_PROFILE_CONTENT_SAP_RSP,
                        g_mmi_wap_prof_job_list_p->src_mod_id);
                     fnc ptr does not exist reply through primitive to requesting mod 
                    mmi_wap_prof_send_get_profile_content_cnf(
                        g_mmi_wap_prof_job_list_p->src_mod_id,
                        g_mmi_wap_prof_job_list_p->job_sim_id,
                        g_mmi_wap_prof_job_list_p->job_app_id,
                        job_data,
                        profile_content);
                    if (profile_content)
                    {
                        mmi_wap_prof_mem_free(profile_content);
                        profile_content = NULL;
                    }
                } */
                mmi_wap_prof_mem_free(job_data);
                job_data = NULL;
            }
                break;

                /* Add all cases above this line */
            default:
                /* Should not reach here */
                ASSERT(0);
        }

        mmi_wap_prof_delete_job();
        if (g_mmi_wap_prof_job_list_p)
        {
            /* More jobs to process. */
            mmi_wap_prof_send_process_job_queue_ind();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_init
 * DESCRIPTION
 *  This is the WAP PROF Initialization API. Called at bootup.
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_prof_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_wap_prof_sim_id_enum sim_id = MMI_WAP_PROF_SIMID_SIM1;
	cbm_app_info_struct info;
    g_mmi_wap_prof_wifi_prefer_flag = 0;
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_INIT_ENTER);

   /***** initialization for Browser *******/

    info.app_str_id = STR_ID_WAP_PROF_CBM_BROWSER;
    info.app_icon_id = IMG_GLOBAL_WEB_BROWSER_CSK; //GetRootTitleIcon(SERVICES_WAP_MENU_ID);

#ifdef WAP2

#ifndef __COSMOS_MMI_PACKAGE__
    info.app_type = DTCNT_APPTYPE_BRW_WAP | DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_SPECIFIC_PROFILE;
#else
	info.app_type = DTCNT_APPTYPE_BRW_WAP | DTCNT_APPTYPE_BRW_HTTP;
#endif

#else

    info.app_type = DTCNT_APPTYPE_BRW_WAP | DTCNT_APPTYPE_SPECIFIC_PROFILE;

#endif 


    cbm_register_app_id_with_app_info(
                                     &info,
                                     &g_mmi_wap_prof_cntx.cbm_brw_app_id_1);

#if (MMI_MAX_SIM_NUM >=2)                
	    info.app_icon_id =  IMG_GLOBAL_COMMON_CSK; //GetRootTitleIcon(SERVICES_WAP_MENU_ID);
    cbm_register_app_id_with_app_info(
                                     &info,
                                     &g_mmi_wap_prof_cntx.cbm_brw_app_id_2);

#if (MMI_MAX_SIM_NUM >= 3) 

	info.app_icon_id =  IMG_GLOBAL_MARK_CSK; //GetRootTitleIcon(SERVICES_WAP_MENU_ID);
	cbm_register_app_id_with_app_info(
		&info,
		&g_mmi_wap_prof_cntx.cbm_brw_app_id_3);

#if (MMI_MAX_SIM_NUM >= 4)
	info.app_icon_id =  IMG_GLOBAL_NEXT_CSK; //GetRootTitleIcon(SERVICES_WAP_MENU_ID);
	cbm_register_app_id_with_app_info(
		&info,
		&g_mmi_wap_prof_cntx.cbm_brw_app_id_4);	
#endif
#endif
#endif 



    info.app_str_id = STR_GLOBAL_MULTIMEDIA_MESSAGE;
    info.app_icon_id = IMG_GLOBAL_WEB_BROWSER_CSK;//GetRootTitleIcon(SERVICES_WAP_MENU_ID);
    info.app_type = DTCNT_APPTYPE_MMS;


    cbm_register_app_id_with_app_info(
                                     &info,
                                     &g_mmi_wap_prof_cntx.cbm_mms_app_id_1);
#if (MMI_MAX_SIM_NUM >=2)             

    info.app_icon_id =  IMG_GLOBAL_COMMON_CSK; //GetRootTitleIcon(SERVICES_WAP_MENU_ID);
    cbm_register_app_id_with_app_info(
                                     &info,
                                     &g_mmi_wap_prof_cntx.cbm_mms_app_id_2);

#if (MMI_MAX_SIM_NUM >= 3) 


	info.app_icon_id = IMG_GLOBAL_MARK_CSK; //GetRootTitleIcon(SERVICES_WAP_MENU_ID);
	cbm_register_app_id_with_app_info(
		&info,
		&g_mmi_wap_prof_cntx.cbm_mms_app_id_3);

#if (MMI_MAX_SIM_NUM >= 4)

	info.app_icon_id = IMG_GLOBAL_NEXT_CSK; //GetRootTitleIcon(SERVICES_WAP_MENU_ID);
	cbm_register_app_id_with_app_info(
		&info,
		&g_mmi_wap_prof_cntx.cbm_mms_app_id_4);	
#endif
#endif
#endif

    
	mmi_wap_prof_nvram_read_active_profile_index(sim_id, MMI_WAP_PROF_APPID_BRW); 
#if (MMI_MAX_SIM_NUM >= 2)

    mmi_wap_prof_nvram_read_active_profile_index(MMI_WAP_PROF_SIMID_SIM2, MMI_WAP_PROF_APPID_BRW); 
#if (MMI_MAX_SIM_NUM >= 3)
	mmi_wap_prof_nvram_read_active_profile_index(MMI_WAP_PROF_SIMID_SIM3, MMI_WAP_PROF_APPID_BRW);
#if (MMI_MAX_SIM_NUM >= 4) 
	mmi_wap_prof_nvram_read_active_profile_index(MMI_WAP_PROF_SIMID_SIM4, MMI_WAP_PROF_APPID_BRW);
#endif
#endif
#endif

	mmi_wap_prof_nvram_read_active_profile_index(sim_id, MMI_WAP_PROF_APPID_MMS);
#if (MMI_MAX_SIM_NUM >= 2)

	mmi_wap_prof_nvram_read_active_profile_index(MMI_WAP_PROF_SIMID_SIM2, MMI_WAP_PROF_APPID_MMS);          
#if (MMI_MAX_SIM_NUM >= 3) 
	mmi_wap_prof_nvram_read_active_profile_index(MMI_WAP_PROF_SIMID_SIM3, MMI_WAP_PROF_APPID_MMS);
#if (MMI_MAX_SIM_NUM >= 4) 
	mmi_wap_prof_nvram_read_active_profile_index(MMI_WAP_PROF_SIMID_SIM4, MMI_WAP_PROF_APPID_MMS);
#endif
#endif
#endif




    



    SetProtocolEventHandler(mmi_wap_prof_process_job_queue_ind_hdlr, MSG_ID_MMI_WAP_PROF_PROCESS_JOB_QUEUE_IND);


    /* Init provisioning */
    srv_wap_prof_prov_init();

    mmi_wap_prof_reset_status();

    mmi_wap_prof_dtcnt_profile_changes_reg_event(NULL);

    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_INIT_EXIT);
    
    return MMI_RET_OK;
}





/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_dtcnt_profile_changes_reg_event
 * DESCRIPTION
 *  Register event callback dynamically with user data pointer.
 * PARAMETERS
 *  evt_id :      [IN]  callback execution type.
 *  user_data :   [IN]  user data pointer.
 * RETURNS
 *  Return MMI_RET_OK if success to register callback with designated user data;
 *  return MMI_RET_ERR_HAS_BEEN_REGISTERED if the designated callback with 
 *  designated user data has been registered.
 *****************************************************************************/
static mmi_ret mmi_wap_prof_dtcnt_profile_changes_reg_event(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND, mmi_wap_prof_dtcnt_changed_handler, user_data);
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_ACCT_DELETE_IND, mmi_wap_prof_dtcnt_changed_handler, user_data);
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_BEARER_STATUS, mmi_wap_prof_dtcnt_changed_handler, user_data);
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_prov_callback_handler
 * DESCRIPTION
 *  function to handle the service callback
 * PARAMETERS
 *    param :      [IN]  event parameter.
 * RETURNS
 *  Return MMI_RET_OK if success;
 *****************************************************************************/
static S32 mmi_wap_prof_dtcnt_changed_handler(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    switch (param->evt_id)
    {
    case EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND:
        mmi_wap_prof_dtcnt_updated_ind_hdlr(param);
        break;
    case EVT_ID_SRV_DTCNT_ACCT_DELETE_IND:
        mmi_wap_prof_dtcnt_deleted_ind_hdlr(param);
        break;
#ifdef __MMI_BROWSER_2__ 
    case EVT_ID_SRV_DTCNT_WLAN_BEARER_STATUS:
    	  if (g_mmi_wap_prof_wifi_prefer_flag==0)
        mmi_wap_prof_wlan_account_updated_ind_hdlr(param);
        break;
#endif

    default:
        break;
    }

    return MMI_RET_OK;
}



#ifdef __MMI_BROWSER_2__
 
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_wlan_account_updated_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param      [IN]            
 * RETURNS
 *  
 *****************************************************************************/
void mmi_wap_prof_wlan_account_updated_ind_hdlr(mmi_event_struct *param)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     srv_dtcnt_wlan_bearer_status_evt_struct  * event_struct;

	mmi_wap_prof_sim_id_enum sim_id = MMI_WAP_PROF_SIMID_SIM1;
     U8 primary_dtcnt_id = (U8) -1;
     U32 browser_account_id;
    
	 cbm_account_info_struct data_account_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    event_struct = (srv_dtcnt_wlan_bearer_status_evt_struct *)param;

    g_mmi_wap_prof_cntx.dtcnt_update_flag = MMI_FALSE;
    g_mmi_wap_prof_cntx.profile_content_src = MMI_WAP_PROF_SRC_WLAN_DTCNT_CHANGED;
	while(sim_id <MMI_WAP_PROF_SIM_TOTAL)
	{
    if((event_struct->status == SRV_DTCNT_WLAN_STATUS_INACTIVE || event_struct->status ==  SRV_DTCNT_WLAN_STATUS_ACTIVE)  && mmi_wap_prof_target_app_is_ready(MMI_WAP_PROF_APPID_BRW))
    {

			browser_account_id  = mmi_wap_prof_get_active_dtcnt_index(sim_id, MMI_WAP_PROF_APPID_BRW);

        cbm_decode_data_account_id_ext(browser_account_id, &data_account_info);

        primary_dtcnt_id = data_account_info.account[0].account_id;

        if(primary_dtcnt_id ==  CBM_DEFAULT_ACCT_ID)
        {  
            g_mmi_wap_prof_cntx.app_id =  MMI_WAP_PROF_APPID_BRW;
            g_mmi_wap_prof_cntx.dtcnt_update_flag = MMI_TRUE;
            g_mmi_wap_prof_wifi_prefer_flag = 1;
				mmi_wap_prof_activate_profile(browser_account_id, MMI_TRUE, sim_id,  MMI_WAP_PROF_APPID_BRW);
				break;
        }
        else
        {
				sim_id++;

            
                     }



    }
        else
            break;

}
}
#endif /* __MMI_BROWSER_2__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_dtcnt_updated_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param      [IN]            
 * RETURNS
 *  
 *****************************************************************************/
void mmi_wap_prof_dtcnt_updated_ind_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_acct_update_ind_evt_struct *account_info;
    mmi_wap_prof_sim_id_enum sim_id = MMI_WAP_PROF_SIMID_SIM1;
    U32 data_account_id;

#ifdef __MMI_BROWSER_2__ 
    U32 browser_account_id;
    MMI_BOOL browser_dtcnt_activated = MMI_FALSE;
#endif
#ifdef MMS_SUPPORT
    MMI_BOOL mms_dtcnt_activated = MMI_FALSE;
    U32 mms_account_id;
#endif

    
	U8 primary_dtcnt_id = (U8) -1;
    U8 secondary_dtcnt_id = (U8) -1;
 

	cbm_account_info_struct data_account_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_info = (srv_dtcnt_acct_update_ind_evt_struct *)param;

    if(g_mmi_wap_prof_cntx.module_status != MMI_WAP_PROF_WAITING && account_info->cause !=1) // Cause is not provisioning
    {

		switch(account_info->sim_id)
		{
		case 1:
			sim_id = MMI_WAP_PROF_SIMID_SIM1;
			break;
#if (MMI_MAX_SIM_NUM>=2)
		case 2:
           sim_id = MMI_WAP_PROF_SIMID_SIM2;
			break;
#if (MMI_MAX_SIM_NUM>=3)
		case 3:
			sim_id = MMI_WAP_PROF_SIMID_SIM3;
			break;
#if (MMI_MAX_SIM_NUM>=4)
		case 4:
			sim_id = MMI_WAP_PROF_SIMID_SIM4;
			break;
#endif
#endif
    #endif
		}



        g_mmi_wap_prof_cntx.profile_content_src = MMI_WAP_PROF_PROFILE_SRC_DTCNT_CHANGED;
        g_mmi_wap_prof_cntx.dtcnt_update_flag = MMI_FALSE;
        g_mmi_wap_prof_cntx.sim_id = sim_id;


#ifdef __MMI_BROWSER_2__  //Only for Q05A app

    /* FOR BROWSER */
        browser_account_id  = mmi_wap_prof_get_active_dtcnt_index(sim_id, MMI_WAP_PROF_APPID_BRW);

        cbm_decode_data_account_id_ext(browser_account_id, &data_account_info);

        primary_dtcnt_id = data_account_info.account[0].account_id;
        secondary_dtcnt_id = data_account_info.account[1].account_id;

    
        if(primary_dtcnt_id == CBM_DEFAULT_ACCT_ID || secondary_dtcnt_id == CBM_DEFAULT_ACCT_ID)
        {
            
            srv_dtcnt_get_auto_acc_id(browser_account_id, &data_account_id); 

            cbm_decode_data_account_id_ext(data_account_id, &data_account_info);

            primary_dtcnt_id = data_account_info.account[0].account_id;
            secondary_dtcnt_id = data_account_info.account[1].account_id;     
            
        		if(account_info->cause == 2 &&  mmi_wap_prof_target_app_is_ready(MMI_WAP_PROF_APPID_BRW))
						{
							browser_dtcnt_activated = MMI_TRUE;
        }
        }




        if((primary_dtcnt_id == (U8)account_info->acc_id  || secondary_dtcnt_id == (U8)account_info->acc_id) && mmi_wap_prof_target_app_is_ready(MMI_WAP_PROF_APPID_BRW))
        {

            browser_dtcnt_activated = MMI_TRUE;

        }
    
#endif   


#ifdef MMS_SUPPORT
    /* FOR MMS  */
        mms_account_id  = mmi_wap_prof_get_active_dtcnt_index(sim_id, MMI_WAP_PROF_APPID_MMS);

        cbm_decode_data_account_id_ext(mms_account_id, &data_account_info);

        primary_dtcnt_id = data_account_info.account[0].account_id;
        secondary_dtcnt_id = data_account_info.account[1].account_id;
    
   
       if(primary_dtcnt_id == CBM_DEFAULT_ACCT_ID || secondary_dtcnt_id == CBM_DEFAULT_ACCT_ID)
        {
            
            srv_dtcnt_get_auto_acc_id(mms_account_id, &data_account_id); 

            cbm_decode_data_account_id_ext(data_account_id, &data_account_info);

            primary_dtcnt_id = data_account_info.account[0].account_id;
            secondary_dtcnt_id = data_account_info.account[1].account_id;     
            
            if(account_info->cause == 2 &&  mmi_wap_prof_target_app_is_ready(MMI_WAP_PROF_APPID_MMS))
						{
							mms_dtcnt_activated = MMI_TRUE;
							
#ifdef __MMI_BROWSER_2__  

             if(browser_dtcnt_activated == MMI_TRUE)
             {
                g_mmi_wap_prof_cntx.dtcnt_update_flag = MMI_TRUE;
                g_mmi_wap_prof_cntx.updated_mms_dtcnt = mms_account_id;
             }
#endif
						} 
               
        }


        if((primary_dtcnt_id == (U8)account_info->acc_id  || secondary_dtcnt_id == (U8)account_info->acc_id) && mmi_wap_prof_target_app_is_ready(MMI_WAP_PROF_APPID_MMS))
        {
             mms_dtcnt_activated = MMI_TRUE;

#ifdef __MMI_BROWSER_2__  

             if(browser_dtcnt_activated == MMI_TRUE)
             {
                g_mmi_wap_prof_cntx.dtcnt_update_flag = MMI_TRUE;
                g_mmi_wap_prof_cntx.updated_mms_dtcnt = mms_account_id;
             }
#endif
    
        }
#endif

#ifdef __MMI_BROWSER_2__  
        if( browser_dtcnt_activated == MMI_TRUE)
        {
            g_mmi_wap_prof_cntx.app_id =  MMI_WAP_PROF_APPID_BRW;
            mmi_wap_prof_activate_profile(browser_account_id, MMI_TRUE, sim_id, MMI_WAP_PROF_APPID_BRW);
            return;
        }
        
#endif
#ifdef MMS_SUPPORT
        if( mms_dtcnt_activated == MMI_TRUE)
        {
            g_mmi_wap_prof_cntx.app_id =  MMI_WAP_PROF_APPID_MMS;
            mmi_wap_prof_activate_profile(mms_account_id, MMI_TRUE, sim_id, MMI_WAP_PROF_APPID_MMS);
        }
#endif

    }/* if(g_mmi_wap_prof_cntx.module_status != MMI_WAP_PROF_WAITING) */


}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_dtcnt_updated_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param      [IN]            
 * RETURNS
 *  
 *****************************************************************************/
void mmi_wap_prof_dtcnt_deleted_ind_hdlr(mmi_event_struct *param)
{

/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_acct_delete_ind_evt_struct *account_info;
    mmi_wap_prof_sim_id_enum sim_id = MMI_WAP_PROF_SIMID_SIM1;
    U32 account_id;
#ifdef __MMI_BROWSER_2__ 
    MMI_BOOL browser_dtcnt_activated = MMI_FALSE;
    U32 browser_activate_account_id;
#endif
#ifdef MMS_SUPPORT
    MMI_BOOL mms_dtcnt_activated = MMI_FALSE;
    U32 mms_activate_account_id;
#endif

    
	U8 primary_dtcnt_id = (U8) -1;
    U8 secondary_dtcnt_id = (U8) -1;
	U8 loop_index;
    MMI_BOOL flag = MMI_FALSE;
	cbm_account_info_struct data_account_info;
/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_info = (srv_dtcnt_acct_delete_ind_evt_struct *)param;

        MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_DTCNT_DELETED_HDLR,account_info->del_num);

	memset(g_mmi_wap_prof_cntx.update_account_info, (U8)-1, sizeof(g_mmi_wap_prof_cntx.update_account_info));

    if(g_mmi_wap_prof_cntx.module_status != MMI_WAP_PROF_WAITING)
    {

        g_mmi_wap_prof_cntx.profile_content_src = MMI_WAP_PROF_PROFILE_SRC_DTCNT_DELETED;

		g_mmi_wap_prof_cntx.update_account_count = 0;


#ifdef __MMI_BROWSER_2__ 
    /* FOR BROWSER */

 
	   MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_DTCNT_DELETED_BRW_HDLR);

  
		for(sim_id = MMI_WAP_PROF_SIMID_SIM1; sim_id < MMI_WAP_PROF_SIM_TOTAL; sim_id++)
		{
        account_id  = mmi_wap_prof_get_active_dtcnt_index(sim_id, MMI_WAP_PROF_APPID_BRW);

        cbm_decode_data_account_id_ext(account_id, &data_account_info);

        primary_dtcnt_id = data_account_info.account[0].account_id;
        secondary_dtcnt_id = data_account_info.account[1].account_id;

 
				
				for(loop_index = 0; loop_index < account_info->del_num; loop_index++)
        {  
					if(primary_dtcnt_id == (U8)account_info->acc_id[loop_index] )
            {
						primary_dtcnt_id = CBM_INVALID_NWK_ACCT_ID;
						flag = MMI_TRUE;
					}

					if(secondary_dtcnt_id == (U8)account_info->acc_id[loop_index])  // if it matches with any 
					{
						secondary_dtcnt_id = CBM_INVALID_NWK_ACCT_ID;
						flag = MMI_TRUE;
					}

            }


				if(flag == MMI_TRUE)
            {

					if(primary_dtcnt_id == CBM_INVALID_NWK_ACCT_ID)
					{
						if(secondary_dtcnt_id == CBM_INVALID_NWK_ACCT_ID)
						{
							browser_activate_account_id = mmi_wap_prof_encode_dtcnt(CBM_DEFAULT_ACCT_ID, (U8)-1, sim_id, MMI_WAP_PROF_APPID_BRW );
            }
						else
						{
							browser_activate_account_id = mmi_wap_prof_encode_dtcnt(secondary_dtcnt_id, (U8)-1, sim_id, MMI_WAP_PROF_APPID_BRW );
						}
					}
					else
						{
							
							browser_activate_account_id = mmi_wap_prof_encode_dtcnt(primary_dtcnt_id, (U8)-1, sim_id, MMI_WAP_PROF_APPID_BRW );
							
						}
							
						
					

    
					
					g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_count].app_id = MMI_WAP_PROF_APPID_BRW;
					g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_count].sim_id = sim_id;
					g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_count].activate_data_account_id = browser_activate_account_id;
					g_mmi_wap_prof_cntx.update_account_count++;
					flag = MMI_FALSE;
        }

		MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_DTCNT_DELETED_TOTAL_COUNT, g_mmi_wap_prof_cntx.update_account_count);
		 	
		}
#endif

    /* FOR MMS  */
#ifdef MMS_SUPPORT

  MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_DTCNT_DELETED_MMS_HDLR);


		for(sim_id = MMI_WAP_PROF_SIMID_SIM1; sim_id <MMI_WAP_PROF_SIM_TOTAL; sim_id++)
		{
        account_id  = mmi_wap_prof_get_active_dtcnt_index(sim_id, MMI_WAP_PROF_APPID_MMS);

        cbm_decode_data_account_id_ext(account_id, &data_account_info);

        primary_dtcnt_id = data_account_info.account[0].account_id;
        secondary_dtcnt_id = data_account_info.account[1].account_id;
    
 				
				for(loop_index=0; loop_index<account_info->del_num; loop_index++)
        {

					if(primary_dtcnt_id == (U8)account_info->acc_id[loop_index] )
            {
						primary_dtcnt_id = CBM_INVALID_NWK_ACCT_ID;
						flag = MMI_TRUE;
					}

					if(secondary_dtcnt_id == (U8)account_info->acc_id[loop_index])  // if it matches with any 
                 {
						secondary_dtcnt_id = CBM_INVALID_NWK_ACCT_ID;
						flag = MMI_TRUE;
                 }
    
            }
    
				if(flag == MMI_TRUE)
				{

					if(primary_dtcnt_id == CBM_INVALID_NWK_ACCT_ID)
                 {
						if(secondary_dtcnt_id == CBM_INVALID_NWK_ACCT_ID)
						{
							mms_activate_account_id = mmi_wap_prof_encode_dtcnt(CBM_DEFAULT_ACCT_ID, (U8)-1, sim_id, MMI_WAP_PROF_APPID_MMS );
						}
						else
						{
							mms_activate_account_id = mmi_wap_prof_encode_dtcnt(secondary_dtcnt_id, (U8)-1, sim_id, MMI_WAP_PROF_APPID_MMS );

						}
						
					}
						else
						{
							
							mms_activate_account_id = mmi_wap_prof_encode_dtcnt(primary_dtcnt_id, (U8)-1, sim_id, MMI_WAP_PROF_APPID_MMS );
							
						}
                
 
					
					g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_count].app_id = MMI_WAP_PROF_APPID_MMS;
					g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_count].sim_id = sim_id;
					g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_count].activate_data_account_id = mms_activate_account_id;
					g_mmi_wap_prof_cntx.update_account_count++;
					flag = MMI_FALSE;
            }
			
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_DTCNT_DELETED_TOTAL_COUNT, g_mmi_wap_prof_cntx.update_account_count);
        }


#endif /* MMS_SUPPORT*/




		if(g_mmi_wap_prof_cntx.update_account_count > 0 )
		{
			g_mmi_wap_prof_cntx.update_account_index = 0;

#ifdef __MMI_BROWSER_2__

			if(g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index].app_id == MMI_WAP_PROF_APPID_BRW)
        {
            g_mmi_wap_prof_cntx.app_id =  MMI_WAP_PROF_APPID_BRW;
				
				if(mmi_wap_prof_target_app_is_ready(MMI_WAP_PROF_APPID_BRW))
				{
				g_mmi_wap_prof_cntx.update_account_index++;
					mmi_wap_prof_activate_profile(g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index-1].activate_data_account_id,
												  MMI_TRUE, g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index-1].sim_id, 
												  MMI_WAP_PROF_APPID_BRW);
					//flag = MMI_TRUE;
					
            return;
        }
				else
				{
					MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_DTCNT_DELETED_BRW_NOT_READY);
					

					while(g_mmi_wap_prof_cntx.update_account_index   <  g_mmi_wap_prof_cntx.update_account_count 
						&& g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index ].app_id == MMI_WAP_PROF_APPID_BRW )
					{
						g_mmi_wap_prof_cntx.update_account_index++;
						mmi_wap_prof_activate_profile(g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index-1].activate_data_account_id,
													  MMI_FALSE, g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index-1 ].sim_id, 
													  MMI_WAP_PROF_APPID_BRW);
						
					}	
					//flag = MMI_FALSE;

				}

			}

       
#endif

#ifdef MMS_SUPPORT
			if(g_mmi_wap_prof_cntx.update_account_index < g_mmi_wap_prof_cntx.update_account_count)// && flag == FALSE)
        {
			
				if(mmi_wap_prof_target_app_is_ready(MMI_WAP_PROF_APPID_MMS))
				{
					g_mmi_wap_prof_cntx.update_account_index++;
					mmi_wap_prof_activate_profile(g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index-1].activate_data_account_id,
												  MMI_TRUE, g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index-1].sim_id,
												  MMI_WAP_PROF_APPID_MMS);
					
					
				}
				else
				{
					MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_DTCNT_DELETED_MMS_NOT_READY);

					while(g_mmi_wap_prof_cntx.update_account_index   <  g_mmi_wap_prof_cntx.update_account_count 
						&& g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index ].app_id == MMI_WAP_PROF_APPID_MMS )
					{
						g_mmi_wap_prof_cntx.update_account_index++;
						mmi_wap_prof_activate_profile(g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index-1].activate_data_account_id,
													  MMI_FALSE, g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index-1].sim_id, 
													  MMI_WAP_PROF_APPID_MMS);
						
					}	
				}
        }
#endif
		}


    }/* if(g_mmi_wap_prof_cntx.module_status != MMI_WAP_PROF_WAITING)*/

}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_reset_status
 * DESCRIPTION
 *  Resets status of profile module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_reset_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_RESET_STATUS);

    g_mmi_wap_prof_cntx.module_status = MMI_WAP_PROF_READY;

    g_mmi_wap_prof_cntx.callback = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_deinit
 * DESCRIPTION
 *  This is the deinitialization routine & reset values used by WAP_PROF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_prof_reset_status();

    cbm_deregister_app_id(g_mmi_wap_prof_cntx.cbm_brw_app_id_1);
    cbm_deregister_app_id(g_mmi_wap_prof_cntx.cbm_mms_app_id_1);
#if (MMI_MAX_SIM_NUM>=2)
	cbm_deregister_app_id(g_mmi_wap_prof_cntx.cbm_brw_app_id_2);
    cbm_deregister_app_id(g_mmi_wap_prof_cntx.cbm_mms_app_id_2);
#if (MMI_MAX_SIM_NUM>=3)
	cbm_deregister_app_id(g_mmi_wap_prof_cntx.cbm_mms_app_id_3);
	cbm_deregister_app_id(g_mmi_wap_prof_cntx.cbm_brw_app_id_3);
#if (MMI_MAX_SIM_NUM>=4)
	cbm_deregister_app_id(g_mmi_wap_prof_cntx.cbm_brw_app_id_4);
	cbm_deregister_app_id(g_mmi_wap_prof_cntx.cbm_mms_app_id_4);
#endif
#endif
#endif


}




/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_display_profile_list
 * DESCRIPTION
 *  Interface API for other modules to display profile list.
 * PARAMETERS
 *  sim_id      [IN]        
 *  app_id      [IN]        
 *  titlebar_icon_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_display_profile_list(
        mmi_wap_prof_sim_id_enum sim_id,
        mmi_wap_prof_app_id_enum app_id,
        U16 titlebar_icon_id,
        mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if ((MMI_MAX_SIM_NUM  >= 2)) && defined(__MMI_WLAN_FEATURES__)
    U32 data_account_id;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if (!(MMI_MAX_SIM_NUM >= 2))
    /* wrong SIM ID. */
    ASSERT(MMI_WAP_PROF_SIMID_DEFAULT == sim_id);
#endif /* __MMI_WAP_DUAL_SIM__ */ 

	
    MMI_TRACE(
        MMI_WAP_PROF_TRC_GRP9,
        TRC_MMI_WAP_PROF_UI_SHOW_PROFILE_LIST,
        sim_id,
        app_id);
 
    if (MMI_FALSE == mmi_wap_prof_is_re_entry_allowed())

    {
        mmi_wap_prof_ui_display_popup((U16) STR_GLOBAL_NOT_AVAILABLE, MMI_WAP_PROF_ERR, MMI_TRUE, NULL, NULL);    /* Global string usage */
        return;
    }


    g_mmi_wap_prof_cntx.sim_id = sim_id;
    g_mmi_wap_prof_cntx.app_id = app_id;
    g_mmi_wap_prof_cntx.titlebar_icon_id = 0;
    g_mmi_wap_prof_cntx.profile_content_src = MMI_WAP_PROF_PROFILE_SRC_USER;
    g_mmi_wap_prof_cntx.parent_id = parent_id;


#if ((MMI_MAX_SIM_NUM >= 2)) && defined(__MMI_WLAN_FEATURES__)

    if (g_mmi_wap_prof_cntx.sim_id == MMI_WAP_PROF_SIMID_WLAN)
    {

  
    //		#define CBM_WIFI_ACCT_ID    (0x38)
        data_account_id =  cbm_encode_data_account_id(CBM_WIFI_ACCT_ID, CBM_SIM_ID_SIM1, g_mmi_wap_prof_cntx.cbm_brw_app_id_1, FALSE);
     if(data_account_id != mmi_wap_prof_get_active_dtcnt_index(g_mmi_wap_prof_cntx.sim_id, g_mmi_wap_prof_cntx.app_id) )
        mmi_wap_prof_activate_profile(data_account_id, MMI_TRUE, sim_id, app_id);
        return;
   
     }
    
#endif /*(__MMI_WAP_DUAL_SIM__ ) && defined(__MMI_WLAN_FEATURES__)*/

#ifdef __COSMOS_MMI_PACKAGE__
	if( vappDtcntReadyCheck(mmi_wap_prof_entry_dtcnt_cui, MMI_FALSE) )
#else

	if( mmi_dtcnt_ready_check(mmi_wap_prof_entry_dtcnt_cui, MMI_FALSE) )
#endif  		
    {
    mmi_wap_prof_entry_dtcnt_cui();
    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_entry_dtcnt_cui
 * DESCRIPTION
 *  API for entering the data account cui.
 * PARAMETERS
 *  void                    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_entry_dtcnt_cui()
{
  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_sim_id_enum cbm_sim_id = CBM_SIM_ID_SIM1;
    
    #ifdef __COSMOS_MMI_PACKAGE__
      VappDtcntAcctValidTypeEnum dtcnt_validity_status_sim1;
      //U8 dtcnt_validity_status_sim1;
      srv_dtcnt_sim_type_enum sim_info; 
      cui_dtcnt_select_run_struct para;
    #ifdef __MMI_WAP_DUAL_SIM__ 
      VappDtcntAcctValidTypeEnum dtcnt_validity_status_sim2;
      //U8 dtcnt_validity_status_sim2;
    #endif
    #else  
    mmi_dtcnt_acct_valid_type_enum  dtcnt_validity_status;
    cui_dtcnt_select_run_struct run_para;
    mmi_wap_prof_sim_id_enum sim_id = MMI_WAP_PROF_SIMID_SIM1;
    cui_dtcnt_select_sim_enum cui_dtcnt_select_sim = CUI_DTCNT_SELECT_SIM1;
    
    #endif
    
    
    
   
	U8 primary_dtcnt_id = (U8) -1;
    U8 secondary_dtcnt_id = (U8) -1;
    
	cbm_account_info_struct data_account_info;
	U8 cbm_app_id;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#ifdef __COSMOS_MMI_PACKAGE__

    {
	#ifdef __MMI_WAP_DUAL_SIM__
		if (MMI_WAP_PROF_SIMID_SIM2 == g_mmi_wap_prof_cntx.sim_id)
        {
			cbm_sim_id = CBM_SIM_ID_SIM2;
        }
	#endif /* __MMI_WAP_DUAL_SIM__ */ 


	if(g_mmi_wap_prof_cntx.app_id  ==  MMI_WAP_PROF_APPID_BRW)
	{ 
		if(cbm_sim_id == CBM_SIM_ID_SIM1)
		{
			cbm_app_id =  g_mmi_wap_prof_cntx.cbm_brw_app_id_1;
		}
		else
		{
			cbm_app_id =  g_mmi_wap_prof_cntx.cbm_brw_app_id_2;
		}
	}
	else
	{
		if(cbm_sim_id == CBM_SIM_ID_SIM1)
		{
			cbm_app_id =  g_mmi_wap_prof_cntx.cbm_mms_app_id_1;
		}
		else
		{
			cbm_app_id =  g_mmi_wap_prof_cntx.cbm_mms_app_id_2;
		}

	}

    	para.sim1_account_id  = mmi_wap_prof_get_active_dtcnt_index(MMI_WAP_PROF_SIMID_SIM1, g_mmi_wap_prof_cntx.app_id);
       // para.sim1_account_id = VAPP_DTCNT_AUTOMATIC_ID; 
		dtcnt_validity_status_sim1 = vappDtcntAcctIsValid( para.sim1_account_id, MMI_FALSE);
     if (dtcnt_validity_status_sim1 == DTCNT_ACCT_VALID_NONE)
        {

		    para.sim1_account_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, CBM_SIM_ID_SIM1, cbm_app_id, FALSE);  

        }
#ifdef __MMI_WAP_DUAL_SIM__    
    para.sim2_account_id =  mmi_wap_prof_get_active_dtcnt_index(MMI_WAP_PROF_SIMID_SIM2, g_mmi_wap_prof_cntx.app_id);
    // para.sim2_account_id = VAPP_DTCNT_AUTOMATIC_ID;
	 dtcnt_validity_status_sim2 = vappDtcntAcctIsValid( para.sim2_account_id, MMI_FALSE);
    if (dtcnt_validity_status_sim2 == DTCNT_ACCT_VALID_NONE)
        {
           
		    para.sim2_account_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, CBM_SIM_ID_SIM2, cbm_app_id, FALSE);  

        }
#endif    //para.bearers = DATA_ACCOUNT_BEARER_CSD | DATA_ACCOUNT_BEARER_GPRS;
    para.bearers = mmi_wap_prof_get_data_account_list_bearer_scope(g_mmi_wap_prof_cntx.app_id);
    para.option = CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT;
    
    
    //if(g_mmi_wap_prof_cntx.app_id  ==  MMI_WAP_PROF_APPID_BRW)
   // { 

    


    //}
   
   para.icon_id = g_mmi_wap_prof_cntx.titlebar_icon_id;
	 para.str_id = STR_GLOBAL_DATA_ACCOUNT;
  
   para.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
  

       

    /*if(g_mmi_wap_prof_cntx.sim_id == MMI_WAP_PROF_SIMID_SIM1 )
	  {
   para.sim_selection = CUI_DTCNT_SELECT_SIM1;
	   }
    else
	  {
    para.sim_selection = CUI_DTCNT_SELECT_SIM2;
	  }*/

        
    #ifdef __MMI_WAP_DUAL_SIM__
             para.sim_selection = CUI_DTCNT_SELECT_DUAL_SIM;
    #else         
         srv_dtcnt_get_sim_preference(&sim_info);
		      para.sim_selection = sim_info;
		#endif      



     
    if(g_mmi_wap_prof_cntx.app_id == MMI_WAP_PROF_APPID_BRW)
    {
        if(para.sim_selection == CUI_DTCNT_SELECT_SIM1 )
        {

            para.app_id = g_mmi_wap_prof_cntx.cbm_brw_app_id_1;

        }
    else
        {
    
            para.app_id = g_mmi_wap_prof_cntx.cbm_brw_app_id_2;
         }
    }
    else
    {
        if(para.sim_selection == CUI_DTCNT_SELECT_SIM1 )
        {

            para.app_id = g_mmi_wap_prof_cntx.cbm_mms_app_id_1;

	       }
        else
	      {

           para.app_id = g_mmi_wap_prof_cntx.cbm_mms_app_id_2;
	      }


	  }
     if(g_mmi_wap_prof_cntx.app_id == MMI_WAP_PROF_APPID_MMS)
 	  {
       para.option |= CUI_DTCNT_SELECT_SIM_PROFILE;

    }


    mmi_frm_group_create (g_mmi_wap_prof_cntx.parent_id, MMI_WAP_PROF_DTCNT_CUI_GRP_ID, mmi_wap_prof_dtcnt_cui_proc, NULL);

    mmi_frm_group_enter (MMI_WAP_PROF_DTCNT_CUI_GRP_ID, MMI_FRM_NODE_SMART_CLOSE_FLAG);


    mmi_wap_prof_dtcnt_cui_id = cui_dtcnt_select_create(MMI_WAP_PROF_DTCNT_CUI_GRP_ID);

 
    cui_dtcnt_select_set_param(mmi_wap_prof_dtcnt_cui_id, &para);


    cui_dtcnt_select_run(mmi_wap_prof_dtcnt_cui_id);

   } 

#else   

    {
    	
    	
    	switch (g_mmi_wap_prof_cntx.sim_id)
		{
	case MMI_WAP_PROF_SIMID_SIM1:
		run_para.sim_selection = CUI_DTCNT_SELECT_SIM1;
		cbm_sim_id = CBM_SIM_ID_SIM1;
			if (g_mmi_wap_prof_cntx.app_id  ==  MMI_WAP_PROF_APPID_BRW)
			run_para.app_id = g_mmi_wap_prof_cntx.cbm_brw_app_id_1;
			else
			run_para.app_id = g_mmi_wap_prof_cntx.cbm_mms_app_id_1;
			break;
#if (MMI_MAX_SIM_NUM>=2)
	case MMI_WAP_PROF_SIMID_SIM2:
		run_para.sim_selection = CUI_DTCNT_SELECT_SIM2;
		cbm_sim_id = CBM_SIM_ID_SIM2;
		if (g_mmi_wap_prof_cntx.app_id  ==  MMI_WAP_PROF_APPID_BRW)
			run_para.app_id = g_mmi_wap_prof_cntx.cbm_brw_app_id_2;
		else
			run_para.app_id = g_mmi_wap_prof_cntx.cbm_mms_app_id_2;
		break;
#if (MMI_MAX_SIM_NUM>=3)
	case MMI_WAP_PROF_SIMID_SIM3:
		run_para.sim_selection = CUI_DTCNT_SELECT_SIM3;
		cbm_sim_id = CBM_SIM_ID_SIM3;
			if(g_mmi_wap_prof_cntx.app_id  ==  MMI_WAP_PROF_APPID_BRW)
			run_para.app_id = g_mmi_wap_prof_cntx.cbm_brw_app_id_3;
			else
			run_para.app_id = g_mmi_wap_prof_cntx.cbm_mms_app_id_3;
		break;
#if (MMI_MAX_SIM_NUM>=4)
	case MMI_WAP_PROF_SIMID_SIM4:
		run_para.sim_selection = CUI_DTCNT_SELECT_SIM4;
		cbm_sim_id = CBM_SIM_ID_SIM4;
		if (g_mmi_wap_prof_cntx.app_id  ==  MMI_WAP_PROF_APPID_BRW)
			run_para.app_id = g_mmi_wap_prof_cntx.cbm_brw_app_id_4;
		else
			run_para.app_id = g_mmi_wap_prof_cntx.cbm_mms_app_id_4;
		break;
#endif
#endif
#endif
	default: 
		break;
	}


    	run_para.account_id = mmi_wap_prof_get_active_dtcnt_index(g_mmi_wap_prof_cntx.sim_id, g_mmi_wap_prof_cntx.app_id);
      dtcnt_validity_status = mmi_dtcnt_acct_is_valid( run_para.account_id );


	MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_ENTRY_DTCNT_CUI, dtcnt_validity_status);

#if defined (__MMI_WAP_PROF_CBM_WAP_FALLBACK_SUPPORT__) 

    if(g_mmi_wap_prof_cntx.app_id  ==  MMI_WAP_PROF_APPID_BRW)
    { 

        if (dtcnt_validity_status == MMI_DTCNT_ACCT_VALID_NONE) // MMI_DTCNT_ACCT_VALID_FIRST)
        {
			run_para.account_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, cbm_sim_id, cbm_app_id, FALSE);

        }
        else if (dtcnt_validity_status == MMI_DTCNT_ACCT_VALID_SECOND)
		{
			//logic for copying secondary data account to primary 

	        cbm_decode_data_account_id_ext(run_para.account_id, &data_account_info);

            primary_dtcnt_id = data_account_info.account[0].account_id;
            secondary_dtcnt_id = data_account_info.account[1].account_id;

			run_para.account_id = cbm_encode_data_account_id(secondary_dtcnt_id, cbm_sim_id, cbm_app_id, FALSE);

        }

    }

#else

 if(g_mmi_wap_prof_cntx.app_id  ==  MMI_WAP_PROF_APPID_BRW)
    { 

        if (dtcnt_validity_status == MMI_DTCNT_ACCT_VALID_NONE)
        {
           
		    run_para.account_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, cbm_sim_id, cbm_app_id, FALSE);  

        }

    }


#endif



#if defined (__MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__) 

    if(g_mmi_wap_prof_cntx.app_id  ==  MMI_WAP_PROF_APPID_MMS)
    { 

    if (dtcnt_validity_status == MMI_DTCNT_ACCT_VALID_NONE) // MMI_DTCNT_ACCT_VALID_FIRST)
        {
			run_para.account_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, cbm_sim_id, cbm_app_id, FALSE);     
        }
        else if (dtcnt_validity_status == MMI_DTCNT_ACCT_VALID_SECOND)
		{
			//logic for copying secondary data account to primary 

	        cbm_decode_data_account_id_ext(run_para.account_id, &data_account_info);

            primary_dtcnt_id = data_account_info.account[0].account_id;
            secondary_dtcnt_id = data_account_info.account[1].account_id;

			run_para.account_id = cbm_encode_data_account_id(secondary_dtcnt_id, cbm_sim_id, cbm_app_id, FALSE);

		}  

    }

#else

 if(g_mmi_wap_prof_cntx.app_id  ==  MMI_WAP_PROF_APPID_MMS)
    { 

		if (dtcnt_validity_status == MMI_DTCNT_ACCT_VALID_NONE)
        {

	    run_para.account_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, cbm_sim_id, cbm_app_id, FALSE);  
           
   
        }

    }


#endif

		run_para.bearers = mmi_wap_prof_get_data_account_list_bearer_scope(g_mmi_wap_prof_cntx.app_id);
		run_para.AppMenuID = 0; 

  
#if defined (__MMI_WAP_PROF_CBM_WAP_FALLBACK_SUPPORT__) 

    if(g_mmi_wap_prof_cntx.app_id  ==  MMI_WAP_PROF_APPID_BRW)

         run_para.option = CUI_DTCNT_SELECT_BEARER_SWITCH | CUI_DTCNT_SELECT_ALLOW_SAME_BEARER_SWITCH | CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT;
#else

  if(g_mmi_wap_prof_cntx.app_id  ==  MMI_WAP_PROF_APPID_BRW)

        run_para.option = CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT;

#endif

#if defined (__MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__)

    if(g_mmi_wap_prof_cntx.app_id == MMI_WAP_PROF_APPID_MMS)

       run_para.option = CUI_DTCNT_SELECT_BEARER_SWITCH | CUI_DTCNT_SELECT_ALLOW_SAME_BEARER_SWITCH | CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT;
#else

    if(g_mmi_wap_prof_cntx.app_id == MMI_WAP_PROF_APPID_MMS)

         run_para.option =CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT;
#endif
	          

	run_para.icon_id = g_mmi_wap_prof_cntx.titlebar_icon_id;
	run_para.str_id = STR_GLOBAL_DATA_ACCOUNT;
  
    run_para.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
  
       MMI_PRINT(
        MMI_WAP_PROF_MOD_INET_APP,
        MMI_WAP_PROF_TRC_GRP9,
        (S8*) "[WAP_PROF] Entry CUI parameters. bearer = %d, appid = %d, icon_id = %d, account_id = %d, select_option = %d, sim_selection = %d",
		run_para.bearers,
		run_para.app_id,
		run_para.icon_id,
		run_para.account_id,
		run_para.option,
		run_para.sim_selection);

 if(g_mmi_wap_prof_cntx.app_id == MMI_WAP_PROF_APPID_MMS)
 	{
        run_para.option |= CUI_DTCNT_SELECT_SIM_PROFILE;

  }


    mmi_frm_group_create (g_mmi_wap_prof_cntx.parent_id, MMI_WAP_PROF_DTCNT_CUI_GRP_ID, mmi_wap_prof_dtcnt_cui_proc, NULL);

    mmi_frm_group_enter (MMI_WAP_PROF_DTCNT_CUI_GRP_ID, MMI_FRM_NODE_SMART_CLOSE_FLAG);


    mmi_wap_prof_dtcnt_cui_id = cui_dtcnt_select_create(MMI_WAP_PROF_DTCNT_CUI_GRP_ID);

 
    cui_dtcnt_select_set_param(mmi_wap_prof_dtcnt_cui_id, &run_para);


    cui_dtcnt_select_run(mmi_wap_prof_dtcnt_cui_id);


}

#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_dtcnt_cui_proc
 * DESCRIPTION
 *  Proc function for Data account CUI.
 * PARAMETERS
 *  mmi_event_struct*                    [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_prof_dtcnt_cui_proc(mmi_event_struct* evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dtcnt_select_event_struct *event;
    U32 get_account_id;
 

	U8 decode_result = 0;
	U8 primary_dtcnt_id = (U8) -1;
    U8 secondary_dtcnt_id = (U8) -1;
    U8 flag_test = 0;
  #ifdef __COSMOS_MMI_PACKAGE__
        	cui_dtcnt_sim_enum sim;
        	U32 sim1AccountId;
        #ifdef __MMI_WAP_DUAL_SIM__	
        	U32 sim2AccountId;
        #endif 
  #endif       	  



    cbm_account_info_struct data_account_info;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    event = (cui_dtcnt_select_event_struct*)evt;
    switch(event->evt_id)
    {

		 case EVT_ID_GROUP_DEINIT:
			#ifndef __COSMOS_MMI_PACKAGE__
			 MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_DTCNT_CUI_EVENT_FROUP_DEINIT, event->account_id);
      #endif      
             mmi_wap_prof_dtcnt_cui_id = GRP_ID_INVALID;  
              break;
  #ifdef __COSMOS_MMI_PACKAGE__
      case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:

          flag_test = 1;
      #endif
/* If user selected an account and press OK, send this event to APP’s proc, APP need to save the account ID and close the CUI */
                    
        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
        	#ifdef __COSMOS_MMI_PACKAGE__
        	sim = event->selectSim;
        	
        switch(sim)
        	{
        		case CUI_DTCNT_SIM1:
        			sim1AccountId = (U32)event->accountId[CUI_DTCNT_SIM1];
        			get_account_id = sim1AccountId;
        			g_mmi_wap_prof_cntx.sim_id = MMI_WAP_PROF_SIMID_SIM1;
        			break;
        		#ifdef __MMI_WAP_DUAL_SIM__
        		case CUI_DTCNT_SIM2:
        			sim2AccountId = (U32)event->accountId[CUI_DTCNT_SIM2];
        			get_account_id = sim2AccountId;
        			g_mmi_wap_prof_cntx.sim_id = MMI_WAP_PROF_SIMID_SIM2;
        			break;
        		#endif
        		case CUI_DTCNT_SIM_TOTAL:
        			cui_dtcnt_select_close(mmi_wap_prof_dtcnt_cui_id);
                    mmi_frm_group_close(MMI_WAP_PROF_DTCNT_CUI_GRP_ID);
                    mmi_wap_prof_dtcnt_cui_id = GRP_ID_INVALID;
                    return MMI_RET_OK;

                    break;
				
            default :
            	break;  
            }
           #else
            
        get_account_id = event->account_id;
           #endif  

			MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_DTCNT_CUI_EVENT_OK, get_account_id);



    if(get_account_id != mmi_wap_prof_get_active_dtcnt_index(g_mmi_wap_prof_cntx.sim_id, g_mmi_wap_prof_cntx.app_id) )
    {


				decode_result = cbm_decode_data_account_id_ext(get_account_id, &data_account_info);

	            primary_dtcnt_id = data_account_info.account[0].account_id;
		        secondary_dtcnt_id = (U8) - 1;

			    if (data_account_info.acct_num > 1)
				{
					secondary_dtcnt_id = data_account_info.account[1].account_id;
				}
  


				if (data_account_info.acct_num > 1 && primary_dtcnt_id == secondary_dtcnt_id)
				{
					//10ADA: correction string id
					mmi_wap_prof_ui_display_popup((U16) STR_ID_WAP_PROF_ERR_MSG_INVALID_DATA_ACCOUNT, MMI_WAP_PROF_ERR, MMI_TRUE, NULL, NULL);    /* Global string usage */
					//ADD_APPLICATION_STRING2(STR_ID_WAP_PROF_ERR_MSG_INVALID_DATA_ACCOUNT , "Invalid data account", "Error message displayed on popup, when user tries to save profile with invalid data account."); /* MAUI_01414973 */    
				}
				else
				{



                    mmi_wap_prof_activate_profile(get_account_id, MMI_TRUE, g_mmi_wap_prof_cntx.sim_id, g_mmi_wap_prof_cntx.app_id);
				}

     }
    
	 else if(get_account_id == mmi_wap_prof_get_active_dtcnt_index(g_mmi_wap_prof_cntx.sim_id, g_mmi_wap_prof_cntx.app_id) )
        
	 {    
		 if(MMI_WAP_PROF_AXN_CFG_DTCNT == g_mmi_wap_prof_cntx.action)
       
		 mmi_wap_prof_activate_profile(get_account_id, MMI_TRUE, g_mmi_wap_prof_cntx.sim_id, g_mmi_wap_prof_cntx.app_id);
	 }

              if (flag_test !=1)
    {
            cui_dtcnt_select_close(mmi_wap_prof_dtcnt_cui_id);
            mmi_frm_group_close(MMI_WAP_PROF_DTCNT_CUI_GRP_ID);
            mmi_wap_prof_dtcnt_cui_id = GRP_ID_INVALID;
            flag_test = 0;
            break;
    }
    else 
            break;
    
    
/* If user press cancel, send this event to APP’s proc, APP can just close the CUI */
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:

			#ifndef __COSMOS_MMI_PACKAGE__
			MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_DTCNT_CUI_EVENT_CANCEL, event->account_id);
      #endif


            cui_dtcnt_select_close(mmi_wap_prof_dtcnt_cui_id);
            mmi_frm_group_close(MMI_WAP_PROF_DTCNT_CUI_GRP_ID);
            mmi_wap_prof_dtcnt_cui_id = GRP_ID_INVALID;


#ifdef __MMI_WAP_PROF_CFG_DTCNT_SUPPORT__
		    if (MMI_WAP_PROF_AXN_CFG_DTCNT == g_mmi_wap_prof_cntx.action && g_mmi_wap_prof_cntx.callback != NULL)
			{
				mmi_wap_prof_cfg_error_response(g_mmi_wap_prof_cntx.sim_id, 
					                        g_mmi_wap_prof_cntx.app_id,
						                    (U8)-1,
							                (mmi_wap_prof_configure_dtcnt_cnf_funcptr_type) g_mmi_wap_prof_cntx.callback);
				g_mmi_wap_prof_cntx.callback = NULL;
			}
#endif


            break;

/* If CUI’s part screen closed abnormally not by user, send this event to APP’s proc, APP can just  close the CUI*/
        case CUI_DTCNT_SELECT_EVENT_CLOSE:
			#ifndef __COSMOS_MMI_PACKAGE__
			MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_DTCNT_CUI_EVENT_CLOSE, event->account_id);
      #endif      
            cui_dtcnt_select_close(mmi_wap_prof_dtcnt_cui_id);
            mmi_frm_group_close(MMI_WAP_PROF_DTCNT_CUI_GRP_ID);
            mmi_wap_prof_dtcnt_cui_id = GRP_ID_INVALID;


#ifdef __MMI_WAP_PROF_CFG_DTCNT_SUPPORT__
		    if (MMI_WAP_PROF_AXN_CFG_DTCNT == g_mmi_wap_prof_cntx.action &&
               !mmi_frm_scrn_is_present(MMI_WAP_PROF_PROGRESS_GRP_ID, SCR_ID_WAP_PROF_PLEASE_WAIT, MMI_FRM_NODE_ALL_FLAG)) 
			{
				mmi_wap_prof_cfg_error_response(g_mmi_wap_prof_cntx.sim_id, 
					                        g_mmi_wap_prof_cntx.app_id,
						                    (U8)-1,
							                (mmi_wap_prof_configure_dtcnt_cnf_funcptr_type) g_mmi_wap_prof_cntx.callback);
				g_mmi_wap_prof_cntx.callback = NULL;
			}
#endif


            break;

/* If APP fill wrong parameter to run CUI it will send this event, no need to close CUI */   
        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
#ifndef __COSMOS_MMI_PACKAGE__
			MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_DTCNT_CUI_EVENT_FAILED, event->account_id);
#endif            
            break;
    }

    return MMI_RET_OK;
}





/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_activate_profile
 * DESCRIPTION
 *  Activates a profile. It is a Non-Blocking API as primitive needs to be sent to WAP.
 *  if other modules need not be informed then pass MMI_FALSE as 2nd parm.
 * PARAMETERS
 *  index                       [IN]        
 *  b_inform_other_module       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_activate_profile(U32 index, MMI_BOOL b_inform_other_module, mmi_wap_prof_sim_id_enum sim_info, mmi_wap_prof_app_id_enum app_info )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_prof_sim_id_enum sim_id = sim_info;
    mmi_wap_prof_app_id_enum app_id = app_info;
  

    U16  app_str_id = STR_GLOBAL_MULTIMEDIA_MESSAGE;
    U16 app_icon_id = IMG_GLOBAL_WEB_BROWSER_CSK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_ACTIVATE_PROFILE, index);

    if ((app_id >= MMI_WAP_PROF_APPID_END) || (sim_id >= MMI_WAP_PROF_SIMID_END))
    {
        ASSERT(app_id < MMI_WAP_PROF_APPID_END);
        ASSERT(sim_id < MMI_WAP_PROF_SIMID_END);
        return;
    }


    if(MMI_WAP_PROF_APPID_BRW == app_id)
    {
        app_str_id = STR_ID_WAP_PROF_CBM_BROWSER;
    }


#if (MMI_MAX_SIM_NUM >= 2)
	switch(sim_info)
    {
	case MMI_WAP_PROF_SIMID_SIM2:
        app_icon_id = IMG_GLOBAL_COMMON_CSK;
		break;
#if (MMI_MAX_SIM_NUM >=3)
	case MMI_WAP_PROF_SIMID_SIM3:
		app_icon_id = IMG_GLOBAL_MARK_CSK;
		break;
#if (MMI_MAX_SIM_NUM >=4)
	case MMI_WAP_PROF_SIMID_SIM4:
		app_icon_id = IMG_GLOBAL_NEXT_CSK;
		break;
#endif
#endif
	default:
		break;
    }

#endif

    //10ADA
    if(MMI_WAP_PROF_PROFILE_SRC_USER != g_mmi_wap_prof_cntx.profile_content_src && 
        MMI_WAP_PROF_PROFILE_SRC_DTCNT_CHANGED!= g_mmi_wap_prof_cntx.profile_content_src &&
        MMI_WAP_PROF_SRC_WLAN_DTCNT_CHANGED!= g_mmi_wap_prof_cntx.profile_content_src && 
		MMI_WAP_PROF_PROFILE_SRC_DTCNT_DELETED != g_mmi_wap_prof_cntx.profile_content_src) //Only in case of provisioning

#ifdef __COSMOS_MMI_PACKAGE__

    vappDtcntSubscribeAccount(mmi_wap_prof_get_active_dtcnt_index(sim_info, app_id), 
                                index, 
                                app_str_id,
                                app_icon_id);
#else 
    mmi_dtcnt_subscribe_account(mmi_wap_prof_get_active_dtcnt_index(sim_info, app_id), 
                                index, 
                                app_str_id,
                                app_icon_id);
                                //GetRootTitleIcon(SERVICES_WAP_MENU_ID));
#endif                                


    /* Update active profile index. Dont commit to NVRAM. */
    /* Commit to NVRAM if not informing other modules. */
    /* index has to be from 0-9 only, and 10-12 for SIM profiles. */
	mmi_wap_prof_set_active_profile_index(sim_info, app_id, index, (!b_inform_other_module));

	if (MMI_TRUE == b_inform_other_module)
    {
        g_mmi_wap_prof_cntx.module_status = MMI_WAP_PROF_WAITING;
        /* Call other application API/ Primitive to change active profile. */
		mmi_wap_prof_active_profile_changed(sim_info, app_id);
        /*
         * Do not do anything after sending active profile changed req as it is Non Blocking. 
         * * anythign else should be done in mmi_wap_prof_active_profile_change_confirmation_callback(..)
         */
		}
    }




/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_active_profile_change_confirmation_callback
 * DESCRIPTION
 *  This will be called when active profile chg rsp is recieved, To continue the processing.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_active_profile_change_confirmation_callback(mmi_wap_prof_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    mmi_wap_prof_app_id_enum app_id = g_mmi_wap_prof_cntx.app_id;
    mmi_wap_prof_sim_id_enum sim_id = g_mmi_wap_prof_cntx.sim_id;


#if defined (__MMI_BROWSER_2__)
    U8 primary_dtcnt_id = (U8) -1;
    U32 browser_account_id;
    
    cbm_account_info_struct data_account_info;

#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_ACTIVE_PROFILE_CHANGED_CONFIRMATION_ENTER, result);

    if ((app_id >= MMI_WAP_PROF_APPID_END) || (sim_id >= MMI_WAP_PROF_SIMID_END))
    {
        ASSERT(app_id < MMI_WAP_PROF_APPID_END);
        ASSERT(sim_id < MMI_WAP_PROF_SIMID_END);
        return;
    }

    if (MMI_TRUE == g_mmi_wap_prof_cntx.end_key_pressed)
    {
        /*
         * End key was pressed revert back.
         * * change result to err.
         */
        result = MMI_WAP_PROF_ERR;
    }

    if (MMI_WAP_PROF_SUCCESS == result)
    {
        /* Commit active profile index to NVRAM. */
        MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_ACTIVE_PROFILE_CHANGED_COMMIT_CHANGES);

#if (MMI_MAX_SIM_NUM >=2) && defined(__MMI_WLAN_FEATURES__)

    if (g_mmi_wap_prof_cntx.sim_id != MMI_WAP_PROF_SIMID_WLAN)
    {

        mmi_wap_prof_nvram_write_active_profile_index(sim_id, app_id);
        g_mmi_wap_prof_wifi_prefer_flag = 0;
   
    }
    
#else /*(__MMI_WAP_DUAL_SIM__ ) && defined(__MMI_WLAN_FEATURES__)*/


        mmi_wap_prof_nvram_write_active_profile_index(sim_id, app_id);

#endif
    }
    else  //10ADA if (MMI_WAP_PROF_AXN_ACTIVATE == g_mmi_wap_prof_cntx.action)
    {
        MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_ACTIVE_PROFILE_CHANGED_REVERT_CHANGES);
        /*
         * Revert back as result failed, only if user activated, if user deleted active profile or user edited
         * * active profile then do not revert.
         */


#if (MMI_MAX_SIM_NUM >=2) && defined(__MMI_WLAN_FEATURES__)

    if (g_mmi_wap_prof_cntx.sim_id != MMI_WAP_PROF_SIMID_WLAN)
    {

        mmi_wap_prof_nvram_read_active_profile_index(sim_id, app_id);
        g_mmi_wap_prof_wifi_prefer_flag = 0;

        }

#else /*(__MMI_WAP_DUAL_SIM__ ) && defined(__MMI_WLAN_FEATURES__)*/


        mmi_wap_prof_nvram_read_active_profile_index(sim_id, app_id);

#endif
        

        }


    /* Change status to ready. */
    g_mmi_wap_prof_cntx.module_status = MMI_WAP_PROF_READY;


#ifndef __COSMOS_MMI_PACKAGE__

	if (MMI_WAP_PROF_PROFILE_SRC_USER == g_mmi_wap_prof_cntx.profile_content_src || MMI_WAP_PROF_PROFILE_SRC_DTCNT_DELETED == g_mmi_wap_prof_cntx.profile_content_src)
        {

		if (MMI_FALSE == g_mmi_wap_prof_cntx.end_key_pressed)
        {


            if(MMI_WAP_PROF_AXN_CFG_DTCNT == g_mmi_wap_prof_cntx.action)
        {
                mmi_wap_prof_cfg_success_response();
        }


            mmi_frm_scrn_close(MMI_WAP_PROF_PROGRESS_GRP_ID, SCR_ID_WAP_PROF_PLEASE_WAIT);

    }
	}	
#endif	
	 if (MMI_WAP_PROF_PROFILE_SRC_OTA_PROV == g_mmi_wap_prof_cntx.profile_content_src)
    {
        if (MMI_FALSE == g_mmi_wap_prof_cntx.end_key_pressed)
        {
				 mmi_wap_prov_app_provisioning_ui_done(MMI_TRUE); //10ADA : Critical: Check it
        }
    }
		
    if ((MMI_WAP_PROF_PROFILE_SRC_USIM_PROV == g_mmi_wap_prof_cntx.profile_content_src) ||
             (MMI_WAP_PROF_PROFILE_SRC_DM_PROV == g_mmi_wap_prof_cntx.profile_content_src) )   //10ADA critical
    {

		 mmi_wap_prov_app_provisioning_ui_done(MMI_FALSE);
		
    }

        
    

#if defined (__MMI_BROWSER_2__)

     if(MMI_WAP_PROF_SRC_WLAN_DTCNT_CHANGED == g_mmi_wap_prof_cntx.profile_content_src && g_mmi_wap_prof_cntx.dtcnt_update_flag == MMI_TRUE )
    {

		browser_account_id  = mmi_wap_prof_get_active_dtcnt_index(sim_id, MMI_WAP_PROF_APPID_BRW);
        cbm_decode_data_account_id_ext(browser_account_id, &data_account_info);

        primary_dtcnt_id = data_account_info.account[0].account_id;

        g_mmi_wap_prof_cntx.dtcnt_update_flag = MMI_FALSE; 

        if(primary_dtcnt_id ==  CBM_DEFAULT_ACCT_ID)
        {  
            g_mmi_wap_prof_cntx.app_id =  MMI_WAP_PROF_APPID_BRW;
			mmi_wap_prof_activate_profile(browser_account_id, MMI_TRUE, sim_id, MMI_WAP_PROF_APPID_BRW);
        }

    }
#endif


	 if (MMI_WAP_PROF_PROFILE_SRC_DTCNT_DELETED == g_mmi_wap_prof_cntx.profile_content_src)
	{


		MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_DTCNT_DELETED_ACTIVATED_CONFIRMATION,
			g_mmi_wap_prof_cntx.update_account_index,
			g_mmi_wap_prof_cntx.update_account_count);


		if(g_mmi_wap_prof_cntx.update_account_index  < g_mmi_wap_prof_cntx.update_account_count )
		{
#ifdef __MMI_BROWSER_2__
			if(g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index].app_id == MMI_WAP_PROF_APPID_BRW)
			{
				g_mmi_wap_prof_cntx.app_id =  MMI_WAP_PROF_APPID_BRW;
				g_mmi_wap_prof_cntx.update_account_index++;
				mmi_wap_prof_activate_profile(g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index-1].activate_data_account_id,
												  MMI_TRUE, g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index-1].sim_id,
												  MMI_WAP_PROF_APPID_BRW);
					
					
			}
			
#endif
#ifdef MMS_SUPPORT
			if(g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index].app_id == MMI_WAP_PROF_APPID_MMS)
			{
				
				g_mmi_wap_prof_cntx.app_id =  MMI_WAP_PROF_APPID_MMS;
			
				if(mmi_wap_prof_target_app_is_ready(MMI_WAP_PROF_APPID_MMS))
				{
					g_mmi_wap_prof_cntx.update_account_index++;
					mmi_wap_prof_activate_profile(g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index-1].activate_data_account_id,
												  MMI_TRUE, g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index-1].sim_id,
												  MMI_WAP_PROF_APPID_MMS);
					
					
				}
				else
				{
					MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_DTCNT_DELETED_MMS_NOT_READY);

					while(g_mmi_wap_prof_cntx.update_account_index   <  g_mmi_wap_prof_cntx.update_account_count 
						&& g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index ].app_id == MMI_WAP_PROF_APPID_MMS )
					{
						g_mmi_wap_prof_cntx.update_account_index++;
						mmi_wap_prof_activate_profile(g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index-1].activate_data_account_id,
													  MMI_FALSE, g_mmi_wap_prof_cntx.update_account_info[g_mmi_wap_prof_cntx.update_account_index-1].sim_id, MMI_WAP_PROF_APPID_MMS);
						
					}	
				}

			}
#endif
		}
		else
		{	g_mmi_wap_prof_cntx.update_account_index =0;
			g_mmi_wap_prof_cntx.update_account_count =0;
			memset(g_mmi_wap_prof_cntx.update_account_info, (U8)-1, sizeof(g_mmi_wap_prof_cntx.update_account_info));
		}
	}
#ifdef MMS_SUPPORT
   // else if(MMI_WAP_PROF_PROFILE_SRC_DTCNT_CHANGED == g_mmi_wap_prof_cntx.profile_content_src 
	else if( g_mmi_wap_prof_cntx.dtcnt_update_flag == MMI_TRUE
            && mmi_wap_prof_target_app_is_ready(MMI_WAP_PROF_APPID_MMS))
    {

        g_mmi_wap_prof_cntx.app_id = MMI_WAP_PROF_APPID_MMS;

        mmi_wap_prof_activate_profile(g_mmi_wap_prof_cntx.updated_mms_dtcnt, MMI_TRUE, g_mmi_wap_prof_cntx.sim_id, g_mmi_wap_prof_cntx.app_id);
    
        g_mmi_wap_prof_cntx.dtcnt_update_flag = MMI_FALSE;  
        
    
    }
#endif


    }

    


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_validate_url
 * DESCRIPTION
 *  Utility function to validate the url.
 * PARAMETERS
 *  url_p                       [IN]        Url in unicode to be validated
 *  b_blank_url_is_valid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 mmi_wap_prof_validate_url(U8 *url_p, MMI_BOOL b_blank_url_is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp[NVRAM_WAP_PROF_URL_LEN + 1];
    U8 url_ascii[NVRAM_WAP_PROF_URL_LEN + 1];
    U8 uri_schm_len;
    applib_url_struct url_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the zero length */
    if (MMI_FALSE == b_blank_url_is_valid)
    {
        if (!mmi_ucs2strlen((S8*) url_p))
        {
            return APPLIB_URL_ERR_INVALID_PARAM;
        }
    }

    /* convert the UCS2 URL string into UTF-8 */
    mmi_chset_ucs2_to_utf8_string((U8*) url_ascii, NVRAM_WAP_PROF_URL_LEN + 1, (U8*) url_p);

    MMI_PRINT(MMI_WAP_PROF_MOD_INET_APP, MMI_WAP_PROF_TRC_GRP9, "[WAP_PROF] Validate URL = %s", (S8*) url_ascii);
    /* parse the URL string by using Applib API */
    if (!(S32) applib_parse_url((S8*) url_ascii, &url_info))
    {
        /* if there is an empty URI scheme in the URL then append the default ("http://") */
        /* URI scheme */
        if (url_info.scheme_type == applib_scheme_empty)
        {
            uri_schm_len = strlen((S8*) MMI_WAP_PROF_DEFAULT_URL);
            if (strlen((S8*) url_ascii) > (NVRAM_WAP_PROF_URL_LEN - uri_schm_len))
            {
                strncpy((S8*) temp, (S8*) url_ascii, NVRAM_WAP_PROF_URL_LEN - uri_schm_len);
                temp[NVRAM_WAP_PROF_URL_LEN - uri_schm_len] = '\0';
            }
            else
            {
                strcpy((S8*) temp, (S8*) url_ascii);
            }
            strcpy((S8*) url_ascii, (S8*) MMI_WAP_PROF_DEFAULT_URL);
            strcat((S8*) url_ascii, (S8*) temp);
            mmi_chset_utf8_to_ucs2_string((U8*) url_p, (NVRAM_WAP_PROF_URL_LEN) * ENCODING_LENGTH, (U8*) url_ascii);

            /* check whether it contain HTTP or HTTPS URI scheme with empty host */
            if (MMI_FALSE == b_blank_url_is_valid)
            {
                if (!(S32) applib_parse_url((S8*) url_ascii, &url_info))
                {
                    if ((url_info.scheme_type == applib_scheme_http) || (url_info.scheme_type == applib_scheme_https))
                    {

                        if (!url_info.len[APPLIB_URL_HOST_PART])
                        {
                            return APPLIB_URL_ERR_INVALID_HOST;
                        }
                    }
                }
            }
        }
        /* check whether it contain HTTP or HTTPS URI scheme with empty host */
        else if ((url_info.scheme_type == applib_scheme_http) || (url_info.scheme_type == applib_scheme_https))
        {
            if (MMI_FALSE == b_blank_url_is_valid)
            {
                if (!url_info.len[APPLIB_URL_HOST_PART])
                {
                    return APPLIB_URL_ERR_INVALID_HOST;
                }
            }
        }
    }

    /* validate the UTF-8 URL string by using Applib API */
    return (S32) applib_url_is_valid((S8*) url_ascii);
}






/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_get_cbm_app_id
 * DESCRIPTION
 *  Returns CBM registered app id for BRW / MMS
 * PARAMETERS
 *  app_id                          [IN]        
 *  mmi_wap_prof_app_id_enum(?)     [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_wap_prof_get_cbm_app_id(mmi_wap_prof_app_id_enum app_id, mmi_wap_prof_sim_id_enum  sim_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	switch(sim_info)
        {   
	case MMI_WAP_PROF_SIMID_SIM1:
		if (MMI_WAP_PROF_APPID_BRW == app_id)
                return g_mmi_wap_prof_cntx.cbm_brw_app_id_1;
        else
			return g_mmi_wap_prof_cntx.cbm_mms_app_id_1;
		break;
#if (MMI_MAX_SIM_NUM>=2)
	case MMI_WAP_PROF_SIMID_SIM2:
		if (MMI_WAP_PROF_APPID_BRW == app_id)
           return g_mmi_wap_prof_cntx.cbm_brw_app_id_2;
		else
                  return g_mmi_wap_prof_cntx.cbm_mms_app_id_2;
		break;
#if (MMI_MAX_SIM_NUM>=3)
	case MMI_WAP_PROF_SIMID_SIM3:
		if (MMI_WAP_PROF_APPID_BRW == app_id)
			return g_mmi_wap_prof_cntx.cbm_brw_app_id_3;
		else
			return g_mmi_wap_prof_cntx.cbm_mms_app_id_3;
		break;
#if (MMI_MAX_SIM_NUM>=4)
	case MMI_WAP_PROF_SIMID_SIM4:
		if (MMI_WAP_PROF_APPID_BRW == app_id)
			return g_mmi_wap_prof_cntx.cbm_brw_app_id_4;
    else
			return g_mmi_wap_prof_cntx.cbm_mms_app_id_4;
		break;
#endif
#endif
#endif

	default:
        ASSERT(0);
		break;
    }

    return 0;   /* Only to remove warning. */
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_handle_service_n_port_param
 * DESCRIPTION
 *  it fills the service / port parameter for the proxy.
 * PARAMETERS
 *  proxy_content       [IN]        
 *  service_parm        [IN]        
 *  portnbr_parm        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_handle_service_n_port_param(
                            U16 px_port,
                            U16  px_service,
                            U16 *conn_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * CL-WAP            9200  WAP
     * CO-WSP            9201  WAP
     * CL-SEC-WSP        9202  WAP + Security ON
     * CO-SEC-WSP        9203  WAP + Security ON
     * CO-SEC-WTA        not supported
     * CL-SEC-WTA        not supported
     * OTA-HTTP-TO       80    HTTP
     * OTA-HTTP-TLS-TO   443   HTTP + Security ON
     * OTA-HTTP-PO       80    HTTP
     * OTA-HTTP-TLS-PO   443   HTTP + Security ON
     * 
     * all others --> HTTP
     * 
     */
#ifdef __MMI_WAP_PROF_PORT_PRIORITY__
 
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_PROV_RCVD_PORT_N_SERVICE_VALUE, px_port, px_service);

    /* First priority is of port number */
    switch (px_port)
    {
        case 9200:
        case 9201:
            *conn_type = MMI_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED;
        
            break;

        case 9202:
        case 9203:
            *conn_type = MMI_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE;
        
            break;
    #ifdef WAP2
        case 80:
        case 8080:
        case 443:
            *conn_type = MMI_WAP_PROF_CONN_TYPE_HTTP;
           
            break;
    #endif /* WAP2 */ 
        default:
            /* If standard port numbers did not match, change port number according to service. */
        {
            switch (px_service)
            {

                case SRV_DTCNT_PROF_PX_SRV_CL_WSP:
                case SRV_DTCNT_PROF_PX_SRV_CO_WSP:
                   *conn_type = MMI_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED;
                   
                    break;

                case SRV_DTCNT_PROF_PX_SRV_CL_SEC_WSP:
                case SRV_DTCNT_PROF_PX_SRV_CO_SEC_WSP:
                    *conn_type = MMI_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE;
                   
                    break;
            #ifdef WAP2
                case SRV_DTCNT_PROF_PX_SRV_HTTP:
                case SRV_DTCNT_PROF_PX_SRV_HTTP_TLS:
                   *conn_type = MMI_WAP_PROF_CONN_TYPE_HTTP;
                    break;

            #endif /* WAP2 */ 
                default:
                   *conn_type = SRV_WAP_PROF_PROV_DEFAULT_CONN_TYPE;
      
            }
        }
            break;
    }

#else /* __MMI_WAP_PROF_PORT_PRIORITY__ */ 


    /* Service has higher priority. */
    switch (px_service)
    {
        case SRV_DTCNT_PROF_PX_SRV_CL_WSP:
        case SRV_DTCNT_PROF_PX_SRV_CO_WSP:
           *conn_type = MMI_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED;
          
            break;

        case SRV_DTCNT_PROF_PX_SRV_CL_SEC_WSP:
        case SRV_DTCNT_PROF_PX_SRV_CO_SEC_WSP:
            *conn_type = MMI_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE;
           
            break;
    #ifdef WAP2
        case SRV_DTCNT_PROF_PX_SRV_HTTP:
        case SRV_DTCNT_PROF_PX_SRV_HTTP_TLS:
            *conn_type = MMI_WAP_PROF_CONN_TYPE_HTTP;
 
            break;
    #endif /* WAP2 */ 
        default:
            
                if (px_port == 9200 || px_port == 9201)
                {
                    *conn_type = MMI_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED;
                }
                else if (px_port == 9202 || px_port == 9203)
                {
                    *conn_type = MMI_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE;
                }
                else
                {
                #ifdef WAP2
                    *conn_type = MMI_WAP_PROF_CONN_TYPE_HTTP;
                #else 
                    *conn_type = MMI_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED;
                #endif 
                }
          
    }
#endif /* __MMI_WAP_PROF_PORT_PRIORITY__ */ 


}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_get_profile_content
 * DESCRIPTION
 *  Returns profile content based on profile index, if -1 is index then active profile is returned.
 *  if callback is provided then reply is through callback, if callback is NULL and status is waiting
 *  reply NULL is returned.
 *  If module is ready, then content is returned even if callback is provided.
 * PARAMETERS
 *  sim_id                          [IN]        
 *  app_id                          [IN]        
 *  profile_index                   [IN]        
 *  get_profile_rsp_callback        [IN]        
 *  prof_conn_type_enum(?)          [IN]        
 * RETURNS
 *  wap_prof_conn_type_enum
 *****************************************************************************/
mmi_wap_prof_profile_content_struct *mmi_wap_prof_get_profile_content(
                                        mmi_wap_prof_sim_id_enum sim_id,
                                        mmi_wap_prof_app_id_enum app_id,
                                        U8 profile_index,
                                        mmi_wap_prof_dtcnt_count_enum  dtcnt_type,
                                        mmi_wap_prof_get_profile_rsp_funcptr_type get_profile_rsp_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    mmi_wap_prof_profile_content_struct *profile_content = NULL;
  
    mmi_wap_prof_job_get_profile_struct *job_data = NULL;
    U8 cbm_app_id = 0;
	cbm_sim_id_enum cbm_sim_id = CBM_SIM_ID_SIM1;

	mmi_wap_prof_sim_id_enum sim_info = MMI_WAP_PROF_SIMID_DEFAULT;

//10ADA
    U32 data_account_id = 0;
	U32 smart_encoded_acc_id = 0;
    srv_dtcnt_prof_proxy_info_struct  dtcnt_proxy_struct;
    srv_dtcnt_prof_str_info_qry_struct homepage_struct;
    U16 conn_type;
	srv_dtcnt_account_enum dtcnt_account_type;
	U8 decode_result = 0;
	U8 primary_dtcnt_id = (U8) -1;
    U8 secondary_dtcnt_id = (U8) -1;
#ifndef __COSMOS_MMI_PACKAGE__   
	mmi_dtcnt_acct_valid_type_enum  dtcnt_validity_status;
#else
  VappDtcntAcctValidTypeEnum dtcnt_validity_status;
#endif  
	S8 trace_string[NVRAM_WAP_PROF_URL_LEN * 4] = {0, };
	S8 ip_address[16] = { '\0' };
    
   
    cbm_account_info_struct data_account_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_WAP_PROF_TRC_GRP9,
        TRC_MMI_WAP_PROF_GET_PROFILE,
        sim_id,
        app_id,
        profile_index,
        (U16) g_mmi_wap_prof_cntx.module_status);


    if ((get_profile_rsp_callback) && (g_mmi_wap_prof_cntx.module_status != MMI_WAP_PROF_READY))
    {
        /* Response required as a callback, and Module not ready. */
        job_data =
            (mmi_wap_prof_job_get_profile_struct*)
            mmi_wap_prof_mem_allocate(sizeof(mmi_wap_prof_job_get_profile_struct));
        job_data->profile_id = profile_index;
        job_data->dtcnt_type = dtcnt_type;
        job_data->callback = (void*)get_profile_rsp_callback;
        mmi_wap_prof_add_job(MMI_WAP_PROF_JOB_GET_PROFILE_CONTENT, MOD_MMI, sim_id, app_id, (void*)job_data);
        mmi_wap_prof_send_process_job_queue_ind();
        return NULL;
    }
    else
    {
        if (MMI_WAP_PROF_BOOTUP_NOT_READY == g_mmi_wap_prof_cntx.module_status)
        {
            MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_GET_PROFILE_MODULE_NOT_READY_ERROR);
            /*
             * Module not ready and No callback. 
             * * Do not change the above condition to != READY, as during activate, status is waiting.
             */
            ASSERT(get_profile_rsp_callback);
            return NULL;
        }
    }



		if(dtcnt_type == MMI_WAP_PROF_DTCNT_PRIMARY )
    {
		    dtcnt_account_type = SRV_DTCNT_ACCOUNT_PRIMARY;
    }
		else
    {
		    dtcnt_account_type = SRV_DTCNT_ACCOUNT_SECONDARY;
    }


	switch (sim_id)
    {
	case MMI_WAP_PROF_SIMID_SIM1:
		cbm_sim_id = CBM_SIM_ID_SIM1;
			if (g_mmi_wap_prof_cntx.app_id  ==  MMI_WAP_PROF_APPID_BRW)
            cbm_app_id = g_mmi_wap_prof_cntx.cbm_brw_app_id_1;
    else
			cbm_app_id =  g_mmi_wap_prof_cntx.cbm_mms_app_id_1;
			break;
#if (MMI_MAX_SIM_NUM>=2)
	case MMI_WAP_PROF_SIMID_SIM2:
		cbm_sim_id = CBM_SIM_ID_SIM2;
		if (g_mmi_wap_prof_cntx.app_id  ==  MMI_WAP_PROF_APPID_BRW)
            cbm_app_id = g_mmi_wap_prof_cntx.cbm_brw_app_id_2;
    else
			cbm_app_id =  g_mmi_wap_prof_cntx.cbm_mms_app_id_2;
		break;
#if (MMI_MAX_SIM_NUM>=3)
	case MMI_WAP_PROF_SIMID_SIM3:
		cbm_sim_id = CBM_SIM_ID_SIM3;
			if(g_mmi_wap_prof_cntx.app_id  ==  MMI_WAP_PROF_APPID_BRW)
			cbm_app_id =  g_mmi_wap_prof_cntx.cbm_brw_app_id_3;
        else
			cbm_app_id =  g_mmi_wap_prof_cntx.cbm_mms_app_id_3;
		break;
#if (MMI_MAX_SIM_NUM>=4)
	case MMI_WAP_PROF_SIMID_SIM4:
		cbm_sim_id = CBM_SIM_ID_SIM4;
		if (g_mmi_wap_prof_cntx.app_id  ==  MMI_WAP_PROF_APPID_BRW)
			cbm_app_id =  g_mmi_wap_prof_cntx.cbm_brw_app_id_4;
        else
			cbm_app_id =  g_mmi_wap_prof_cntx.cbm_mms_app_id_4;
		break;
#endif
#endif
#endif
	default:
		break;
    }




        profile_content =
            (mmi_wap_prof_profile_content_struct*)
            mmi_wap_prof_mem_allocate(sizeof(mmi_wap_prof_profile_content_struct));

        memset(profile_content, 0 , (sizeof(mmi_wap_prof_profile_content_struct)));

/* for WLAN Profiles : Primary as WLan and secondary as invalid*/
	//Falback won't hapeen

#if (MMI_MAX_SIM_NUM>=2) && defined(__MMI_WLAN_FEATURES__)
 	if( MMI_WAP_PROF_SIMID_WLAN == sim_id) // WLAN Profile
        {

//		#define CBM_WIFI_ACCT_ID    (0x38)
        data_account_id =  cbm_encode_data_account_id(CBM_WIFI_ACCT_ID, CBM_SIM_ID_SIM1, g_mmi_wap_prof_cntx.cbm_brw_app_id_1, FALSE);

		dtcnt_account_type = SRV_DTCNT_ACCOUNT_PRIMARY;

            }
	else
#endif 
 
	{ /* Start: normal sim profile case */


        if(profile_index == 0)
        {

         secondary_dtcnt_id = (U8) - 1;

         smart_encoded_acc_id = mmi_wap_prof_encode_dtcnt(CBM_DEFAULT_ACCT_ID, secondary_dtcnt_id, sim_id,  app_id );

         srv_dtcnt_get_auto_acc_id(smart_encoded_acc_id, &data_account_id); //10A Da return value: Critical

        }
        else
        { 

        data_account_id = mmi_wap_prof_get_active_dtcnt_index(sim_id, app_id);



    


		cbm_decode_data_account_id_ext(data_account_id, &data_account_info);

		primary_dtcnt_id = data_account_info.account[0].account_id;
		secondary_dtcnt_id = (U8) - 1;

		if (data_account_info.acct_num > 1)
            {
			secondary_dtcnt_id = data_account_info.account[1].account_id;
            }


#ifdef __COSMOS_MMI_PACKAGE__
   dtcnt_validity_status = vappDtcntAcctIsValid( data_account_id, MMI_FALSE) ;
#else
   dtcnt_validity_status = mmi_dtcnt_acct_is_valid( data_account_id) ;
#endif     

/*  DO NOT DELETE

  srv_dtcnt_get_auto_acc_id() : API behavior

	for Primary no issues: Primary is returned as the auto id and secondary as the same value
	2003737 -> 2003700
	2003E37 -> 2003E00
	2000237 -> 2000200



	for Secondary check  issues: 
	2003737 -> 2003700 : if primary also auto, no use
	200373E -> 2003E3E : If primary invalid, secondary also invalid
	2003702 -> 2000002 : OK
 */   


	if(dtcnt_account_type == SRV_DTCNT_ACCOUNT_PRIMARY)
            {
#ifndef __COSMOS_MMI_PACKAGE__
        if(dtcnt_validity_status == MMI_DTCNT_ACCT_VALID_NONE || dtcnt_validity_status == MMI_DTCNT_ACCT_VALID_SECOND )
#else
        if(dtcnt_validity_status ==DTCNT_ACCT_VALID_NONE)
#endif        	
            {
            smart_encoded_acc_id = mmi_wap_prof_encode_dtcnt(CBM_DEFAULT_ACCT_ID, secondary_dtcnt_id, sim_id,  app_id );

            srv_dtcnt_get_auto_acc_id(smart_encoded_acc_id, &data_account_id); //10A Da return value: Critical
        }
        else if(primary_dtcnt_id == CBM_DEFAULT_ACCT_ID)
            {

			smart_encoded_acc_id = data_account_id;
			smart_encoded_acc_id = mmi_wap_prof_encode_dtcnt(CBM_DEFAULT_ACCT_ID, secondary_dtcnt_id, sim_id,  app_id );

         //   cbm_set_app_id(smart_encoded_acc_id, cbm_app_id );

			srv_dtcnt_get_auto_acc_id(smart_encoded_acc_id, &data_account_id); //10A Da return value: Critical

		}


            }
	else  //Secondary data account : SRV_DTCNT_ACCOUNT_SECONDARY
            {

#ifndef __COSMOS_MMI_PACKAGE__
        if(dtcnt_validity_status ==  MMI_DTCNT_ACCT_VALID_FIRST || dtcnt_validity_status ==  MMI_DTCNT_ACCT_VALID_NONE)
        
#else
        if(dtcnt_validity_status == DTCNT_ACCT_VALID_FIRST || dtcnt_validity_status == DTCNT_ACCT_VALID_NONE)        	
  
#endif            //SET SECONDARY AS DEFAULT
          {  smart_encoded_acc_id = mmi_wap_prof_encode_dtcnt(primary_dtcnt_id, CBM_DEFAULT_ACCT_ID, sim_id,  app_id );

            srv_dtcnt_get_auto_acc_id(smart_encoded_acc_id, &data_account_id); //10A Da return value: Critical
        }
        else if (secondary_dtcnt_id == CBM_DEFAULT_ACCT_ID)
        {
				smart_encoded_acc_id = data_account_id;
				smart_encoded_acc_id = mmi_wap_prof_encode_dtcnt(primary_dtcnt_id, CBM_DEFAULT_ACCT_ID, sim_id,  app_id );
               // cbm_set_app_id(smart_encoded_acc_id, cbm_app_id );
				srv_dtcnt_get_auto_acc_id(smart_encoded_acc_id, &data_account_id); //10A Da return value: Critical
        }


        }
   
     }
	} /* End : normal sim profile case */




	homepage_struct.dest = (S8*)mmi_wap_prof_mem_allocate(NVRAM_WAP_PROF_URL_LEN);
	memset((S8*)homepage_struct.dest, 0, NVRAM_WAP_PROF_URL_LEN);
	homepage_struct.dest_len = NVRAM_WAP_PROF_URL_LEN;
	homepage_struct.req_len = 0; //10ADA check it

	if (MMI_FALSE ==  srv_dtcnt_get_homepage(
			data_account_id,
			&homepage_struct,
			dtcnt_account_type))  
        {
   
	    
        if(profile_index == 0)
        strcpy((S8*)profile_content->url, (S8*) "http://google.com");
        else
			strcpy((S8*)profile_content->url, (S8*) "http://");
        }
    else
    {    
    	   if ((strcmp((S8*) homepage_struct.dest, "") == 0) && (profile_index == 0))
	      {
	      strcpy((S8*)profile_content->url, (S8*) "http://google.com");
    	  }
		else if (strcmp((S8*) homepage_struct.dest, "") == 0)
		{   
            strcpy((S8*)profile_content->url, (S8*) "http://");
		}
 	else
    
    {
         strncpy((S8*) profile_content->url, (S8*) homepage_struct.dest, NVRAM_WAP_PROF_URL_LEN-1);
    }  
    }

    mmi_wap_prof_mem_free(homepage_struct.dest);


    memset(&dtcnt_proxy_struct, 0 , (sizeof( srv_dtcnt_prof_proxy_info_struct)));

    if(MMI_FALSE == srv_dtcnt_get_proxy_info(
            data_account_id,
            &dtcnt_proxy_struct,
            dtcnt_account_type) )   // 10ADA check the return type of this API
        {
        //Error handling
   // erro check : remove this line later + 10A Critical SPECIAL WLAN CASES as discussed with Will 

        profile_content->proxy_port = MMI_WAP_PROF_DEFAULT_PORT;



        profile_content->proxy_ip[0] =  MMI_WAP_PROF_DEFAULT_IP1;
        profile_content->proxy_ip[1] =  MMI_WAP_PROF_DEFAULT_IP2;
        profile_content->proxy_ip[2] =  MMI_WAP_PROF_DEFAULT_IP3;
        profile_content->proxy_ip[3] =  MMI_WAP_PROF_DEFAULT_IP4;

        profile_content->conn_type = 0;

        strcpy((S8*) profile_content->username, (S8*)MMI_WAP_PROF_DEFAULT_USERNAME);
        strcpy((S8*) profile_content->password, (S8*)MMI_WAP_PROF_DEFAULT_PASSWORD);

        }
    else
    {

	profile_content->proxy_port = dtcnt_proxy_struct.px_port;



	profile_content->proxy_ip[0] =  dtcnt_proxy_struct.px_addr[0];
	profile_content->proxy_ip[1] =  dtcnt_proxy_struct.px_addr[1];
	profile_content->proxy_ip[2] =  dtcnt_proxy_struct.px_addr[2];
	profile_content->proxy_ip[3] =  dtcnt_proxy_struct.px_addr[3];



	mmi_wap_prof_handle_service_n_port_param(
						dtcnt_proxy_struct.px_port,
						dtcnt_proxy_struct.px_service,
						&conn_type); //10ADA check the data type of conn_type

	profile_content->conn_type = conn_type;


	strncpy((S8*) profile_content->username, (S8*) dtcnt_proxy_struct.px_authid, NVRAM_WAP_PROF_PROFILE_USERNAME_LEN-1);
	strncpy((S8*) profile_content->password, (S8*) dtcnt_proxy_struct.px_authpw, NVRAM_WAP_PROF_PROFILE_PASSWORD_LEN-1); 


    }


	profile_content->data_account_primary_id = data_account_id;
	profile_content->data_account_secondary_id = (U32) - 1;


  //  MMI_PRINT(MMI_WAP_PROF_MOD_INET_APP, MMI_WAP_PROF_TRC_GRP9, "[WAP_PROF] Homepage URL = %s", (S8*) homepage_struct.dest);

       sprintf(
        ip_address,
        "%d.%d.%d.%d",
        profile_content->proxy_ip[0],
        profile_content->proxy_ip[1],
        profile_content->proxy_ip[2],
        profile_content->proxy_ip[3]);

	    sprintf(
        (S8*) trace_string,
        (S8*) "[WAP_PROF]Content:IP= %s, port= %d, dtcnt 1= %d, uid= %s, PW= %s, conn= %d, url = %s, ap_id= %d, sim_id= %d",
        (S8*) ip_address,
        profile_content->proxy_port,
        profile_content->data_account_primary_id,
        (S8*) profile_content->username,
        (S8*) profile_content->password,
        profile_content->conn_type,
        (S8*) profile_content->url,
        app_id,
		sim_id);

    MMI_PRINT(MMI_WAP_PROF_MOD_INET_APP, MMI_WAP_PROF_TRC_GRP9, (S8*) trace_string);

    return profile_content;
    }



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_get_active_profile_connection_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id      [IN]        
 * RETURNS
 *  prof_conn_type_enum
 *****************************************************************************/
mmi_wap_prof_conn_type_enum mmi_wap_prof_get_active_profile_connection_type(mmi_wap_prof_app_id_enum app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    U32 data_account_id = 0;
    srv_dtcnt_prof_proxy_info_struct  dtcnt_proxy_struct;
    U16 conn_type =0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    data_account_id =  mmi_wap_prof_get_active_dtcnt_index(MMI_WAP_PROF_SIMID_DEFAULT, app_id);

	MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_ENTRY_ACTIVE_CONN_TYPE, data_account_id);

    srv_dtcnt_get_proxy_info(
            data_account_id,
            &dtcnt_proxy_struct,
            SRV_DTCNT_ACCOUNT_PRIMARY);

//10ADA : get api from MMS for data account type : although after discussion with Vikas no need

     mmi_wap_prof_handle_service_n_port_param(
                            dtcnt_proxy_struct.px_port,
                            dtcnt_proxy_struct.px_service,
                            &(conn_type));  //10ADA check the data type of conn_type


    if (MMI_WAP_PROF_CONN_TYPE_HTTP == conn_type)
        return MMI_WAP_PROF_CONN_TYPE_HTTP;
    else
        return MMI_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_mem_allocate
 * DESCRIPTION
 *  Allocates requested memory from control buffer.
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_wap_prof_mem_allocate(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *result = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = (void*)OslMalloc(size);

    if (NULL == result)
    {
        ASSERT(result);
        return result;
    }
/*
    MMI_PRINT(
        MMI_WAP_PROF_MOD_INET_APP,
        MMI_WAP_PROF_TRC_GRP9,
        "[WAP_PROF][MEM] Allocated = %d, at ADD = %x",
        size,
        (U32) result);
*/
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_MEM_ALLOCATED, size, (U32) result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_mem_free
 * DESCRIPTION
 *  Releases memory pointed by ptr.
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_mem_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == ptr)
    {
        ASSERT(ptr);
        return;
    }

/*    MMI_PRINT(MMI_WAP_PROF_MOD_INET_APP, MMI_WAP_PROF_TRC_GRP9, "[WAP_PROF][MEM] Released ADD = %x", (U32) ptr); */
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_MEM_RELEASED, (U32) ptr);
    OslMfree(ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_check_is_active_call
 * DESCRIPTION
 *  Checks if there is any active UI call running..
 * PARAMETERS
 *  void
 *  ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_wap_prof_check_is_active_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__

    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0
        || srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
        return MMI_TRUE;
    else
        return MMI_FALSE;

#else /* __MMI_BACKGROUND_CALL__ */ 

    /* return MMI_TRUE if in voice call, not for Wapcall. */
    if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0) && (IsScreenPresent(mmi_ucm_get_marker_scrn_id())))
        return MMI_TRUE;
    else
        return MMI_FALSE;

#endif /* __MMI_BACKGROUND_CALL__ */ 
}

#ifndef __MMI_BACKGROUND_CALL__


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_check_is_call_screen_active
 * DESCRIPTION
 *  Checks if the active screen is a call screen, this is for popup only.
 * PARAMETERS
 *  void
 *  ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_wap_prof_check_is_call_screen_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        /*if ((GetActiveScreenId() == SCR_CM_ACTIVECALLSCREEN) ||
            (GetActiveScreenId() == ITEMSCR_INCOMING_CALL) ||
            (GetActiveScreenId() == SCR1004_CM_DISPENDCALLDURATION) ||
            (GetActiveScreenId() == SCR1001_CM_OUTGOINGCALLSCREEN) || 
            (GetActiveScreenId() == SCR_CM_NOTIFYCALLABORTED)   ||
            (GetActiveScreenId() == SCR_ID_UCM_INCOMING)    ||
            (GetActiveScreenId() == SCR_ID_UCM_OUTGOING))*/
        if((srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ) ||
           (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0))

        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}
#endif /* __MMI_BACKGROUND_CALL__ */ 




/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_get_call_marker_screen_id
 * DESCRIPTION
 *  Returns call marker screen id.
 * PARAMETERS
 *  void
 *  string        [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_wap_prof_get_call_marker_screen_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__

    return mmi_ucm_app_get_intermediate_marker_scrn_id();

#else /* __MMI_BACKGROUND_CALL__ */ 

    return mmi_ucm_get_marker_scrn_id();

#endif /* __MMI_BACKGROUND_CALL__ */ 
}


/* MAUI_01508716 starts */
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_kill_profile
 * DESCRIPTION
 *  Kills all the profile operations abruptly.
 * PARAMETERS
 *  app_id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_kill_profile(mmi_wap_prof_app_id_enum app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

/*    MMI_PRINT(MMI_WAP_PROF_MOD_INET_APP, MMI_WAP_PROF_TRC_GRP9, "[WAP_PROF] Profile killed abruptly.");   */
	
	if(	g_mmi_wap_prof_cntx.app_id == app_id)
	{
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_ERR_KILL_PROFILE, g_mmi_wap_prof_cntx.action);

    //DeleteScreenIfPresent(SCR_ID_WAP_PROF_PLEASE_WAIT);
    //if(SCR_ID_WAP_PROF_PLEASE_WAIT !=	mmi_frm_scrn_get_active_id() )
     mmi_frm_scrn_close(MMI_WAP_PROF_PROGRESS_GRP_ID, SCR_ID_WAP_PROF_PLEASE_WAIT);


        //10ADA : Delete CUI of Data Account
if( mmi_wap_prof_dtcnt_cui_id != GRP_ID_INVALID )
{
            cui_dtcnt_select_close(mmi_wap_prof_dtcnt_cui_id);
            mmi_frm_group_close(MMI_WAP_PROF_DTCNT_CUI_GRP_ID);
            mmi_wap_prof_dtcnt_cui_id = GRP_ID_INVALID;
		
}

    mmi_wap_prof_reset_status();

}
}





/* MAUI_01730813 starts */
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_is_re_entry_allowed
 * DESCRIPTION
 *  This API checks if profile re-entry scenario is allowed. If yes, it de-inits previous instance.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_wap_prof_is_re_entry_allowed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_REENTRY_CHECK, g_mmi_wap_prof_cntx.module_status);

    //if ((IsScreenPresent(SCR_ID_WAP_PROF_PROV_DISPLAY_INFO)) || (MMI_WAP_PROF_WAITING == g_mmi_wap_prof_cntx.module_status))
    if((mmi_frm_scrn_is_present(MMI_WAP_PROV_CCA_GRP_ID, SCR_ID_WAP_PROF_PROV_DISPLAY_INFO, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
      ||(MMI_WAP_PROF_WAITING == g_mmi_wap_prof_cntx.module_status))
    {
        /* 
         * Re-entry not allowed in case if provisioning is going on or profile is waiting, which will be ready after sometime.
         * If does not become ready, then it is a bug. Display info screen is deleted by UM if ProvBox is ON, hence this check
         * will work only when Provisioning inbox is turned OFF.
         */
        return MMI_FALSE;
    }
    else if ( mmi_wap_prof_dtcnt_cui_id != GRP_ID_INVALID ) //10ADA Checks if DA screen is present
   /* ((IsScreenPresent(SCR_ID_WAP_PROF_PROFILE_LIST)) ||
            (IsScreenPresent(SCR_ID_WAP_PROF_PROFILE_DETAILS)))*/
    {

#ifdef __MMI_WAP_PROF_CFG_DTCNT_SUPPORT__
		if (MMI_WAP_PROF_AXN_CFG_DTCNT == g_mmi_wap_prof_cntx.action)
		{
			mmi_wap_prof_cfg_error_response(g_mmi_wap_prof_cntx.sim_id,
				g_mmi_wap_prof_cntx.app_id,
				(U8)-1,
				(mmi_wap_prof_configure_dtcnt_cnf_funcptr_type) g_mmi_wap_prof_cntx.callback);

			g_mmi_wap_prof_cntx.callback = NULL;
		}

#endif /* __MMI_WAP_PROF_CFG_DTCNT_SUPPORT__ */


        mmi_wap_prof_kill_profile(g_mmi_wap_prof_cntx.app_id);
    }

    return MMI_TRUE;
}
/* MAUI_01730813 ends */


#ifdef __MMI_WAP_PROF_CFG_DTCNT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 * mmi_wap_prof_is_dtcnt_valid
 * DESCRIPTION
 *  This will be check the validity of the data account.
 *  profile_id to be passed is (-1) for active profile, else a number between 0-9.
 * PARAMETERS
 *  sim_id     [IN]
 *  app_id     [IN]
 *  profile_id [IN]
 * RETURNS
 * MMI_BOOL 
 *****************************************************************************/
kal_bool mmi_wap_prof_is_dtcnt_valid(mmi_wap_prof_sim_id_enum sim_id, 
                                     mmi_wap_prof_app_id_enum app_id, 
                                     U8 profile_id)
{

kal_bool result = KAL_TRUE;

#ifdef __MMI_WAP_PROF_10A_DTCNT_CHANGES_NOT_APPLICABLE__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_wap_prof_profile_content_struct *content_p = NULL;
    
    kal_bool result = KAL_FALSE;
    MMI_BOOL mem_flag = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((app_id >= MMI_WAP_PROF_APPID_END) || (sim_id >= MMI_WAP_PROF_SIMID_END))
    {
        ASSERT(app_id < MMI_WAP_PROF_APPID_END);
        ASSERT(sim_id < MMI_WAP_PROF_SIMID_END);
        return result;
    }


#if (MMI_MAX_SIM_NUM>=2) && defined(__MMI_WLAN_FEATURES__)

   if(g_mmi_wap_prof_cntx.sim_id == MMI_WAP_PROF_SIMID_WLAN )
   { 
        return KAL_TRUE ;  
   }
#endif


    if ((U8) -1 != profile_id)
    {
        profile_names_list = mmi_wap_prof_get_profile_names_list(sim_id, app_id);

        content_p = mmi_wap_prof_get_content_by_profile_id(sim_id, app_id, profile_id, profile_names_list);
	    if (NULL == content_p)
		{
			ASSERT(content_p);
            return;
		}
        mmi_wap_prof_mem_free(profile_names_list);
        profile_names_list = NULL;
        mem_flag = MMI_TRUE;
    }
    else
    {
        content_p = mmi_wap_prof_get_active_profile_content_value(sim_id, app_id);
    }

    if (content_p->data_account_primary_id != (U32) -1)
    {
        result = KAL_TRUE;
    }
    
    if (MMI_TRUE == mem_flag)
    {
        mmi_wap_prof_mem_free(content_p);
        content_p = NULL;
    }

    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_IS_DTCNT_VALID, sim_id, app_id, profile_id, result);
    return result;
#endif  /*__MMI_WAP_PROF_10A_DTCNT_CHANGES_NOT_APPLICABLE__*/



#ifndef __COSMOS_MMI_PACKAGE__
    mmi_dtcnt_acct_valid_type_enum  dtcnt_validity_status;
#else
    VappDtcntAcctValidTypeEnum dtcnt_validity_status;
#endif    


#if (MMI_MAX_SIM_NUM >=2) && defined(__MMI_WLAN_FEATURES__)

   if(sim_id == MMI_WAP_PROF_SIMID_WLAN )
   { 
        return KAL_TRUE ;  
   }
#endif

   if(profile_id != 0)
   {
  #ifdef  __COSMOS_MMI_PACKAGE__ 	
    dtcnt_validity_status = vappDtcntAcctIsValid( mmi_wap_prof_get_active_dtcnt_index(sim_id, app_id),MMI_FALSE );
    if (dtcnt_validity_status == DTCNT_ACCT_VALID_NONE)
  #else
    dtcnt_validity_status = mmi_dtcnt_acct_is_valid( mmi_wap_prof_get_active_dtcnt_index(sim_id, app_id) );
  
    if (dtcnt_validity_status == MMI_DTCNT_ACCT_VALID_SECOND || dtcnt_validity_status == MMI_DTCNT_ACCT_VALID_NONE) 
 #endif  
    {   

        result = KAL_FALSE;
}

	MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_IS_DTCNT_VALID, sim_id, app_id, profile_id, result);

   }

    return result;
}



/*****************************************************************************
 * FUNCTION
 * mmi_wap_prof_configure_dtcnt
 * DESCRIPTION
 *  This will be called when configure data account indication is recieved.
 * PARAMETERS
 *  sim_id              [IN] 
 *  app_id              [IN] 
 *  profile_id          [IN]
 *  response_functptr   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_configure_dtcnt(mmi_wap_prof_sim_id_enum sim_id, 
                                  mmi_wap_prof_app_id_enum app_id,
                                  U8 profile_id, 
				  U16 titlebar_icon_id,
                                  mmi_wap_prof_configure_dtcnt_cnf_funcptr_type response_functptr,
                                  mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_CONFIGURE_DTCNT, sim_id, app_id, profile_id, (U32) response_functptr);

    if ((app_id >= MMI_WAP_PROF_APPID_END) || (sim_id >= MMI_WAP_PROF_SIMID_END))
    {
        ASSERT(app_id < MMI_WAP_PROF_APPID_END);
        ASSERT(sim_id < MMI_WAP_PROF_SIMID_END);
        return;
    }

    /*Don't do anything before this check...*/
    if (MMI_FALSE == mmi_wap_prof_is_re_entry_allowed())
    {
        mmi_wap_prof_ui_display_popup((U16) STR_GLOBAL_NOT_AVAILABLE, MMI_WAP_PROF_ERR, MMI_TRUE, NULL, NULL);
        mmi_wap_prof_send_cfg_dtcnt_send_response_ind(sim_id, app_id, profile_id, MMI_WAP_PROF_ERR, (void*) response_functptr);
        return;
    }

    g_mmi_wap_prof_cntx.callback  =  (void*) response_functptr;
    g_mmi_wap_prof_cntx.sim_id = sim_id;
    g_mmi_wap_prof_cntx.app_id = app_id;
    g_mmi_wap_prof_cntx.end_key_pressed = MMI_FALSE;
    g_mmi_wap_prof_cntx.module_status = MMI_WAP_PROF_READY;
    g_mmi_wap_prof_cntx.action = MMI_WAP_PROF_AXN_CFG_DTCNT;
    g_mmi_wap_prof_cntx.profile_content_src = MMI_WAP_PROF_PROFILE_SRC_USER;


    if(KAL_TRUE == mmi_wap_prof_is_dtcnt_valid(sim_id, app_id , profile_id))
    { 
			
	
        mmi_wap_prof_ui_display_popup((U16)STR_ID_WAP_PROF_DTCNT_ALREADY_CONFIGURED, MMI_EVENT_INFO, MMI_TRUE, NULL, NULL); 
		
	mmi_wap_prof_cfg_success_response();

	return;
    }

    g_mmi_wap_prof_cntx.titlebar_icon_id = titlebar_icon_id;
    g_mmi_wap_prof_cntx.parent_id = parent_id;

    mmi_wap_prof_entry_dtcnt_cui();  



}


/*****************************************************************************
 * FUNCTION
 * mmi_wap_prof_cfg_success_response
 * DESCRIPTION
 *  Sends the response as success  to other modules in case of configure data account indication.
 * PARAMETERS
 *  void  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_cfg_success_response(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 profile_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_CFG_DTCNT_SUCCESS_RSP, 
              g_mmi_wap_prof_cntx.sim_id, 
              g_mmi_wap_prof_cntx.app_id);
            //  g_mmi_wap_prof_cntx.select_index);*/ 

    if (g_mmi_wap_prof_cntx.callback)
    {
      /*  if (mmi_wap_prof_ui_get_selected_index() == mmi_wap_prof_get_active_profile_index(g_mmi_wap_prof_cntx.sim_id,
                                                                                          g_mmi_wap_prof_cntx.app_id))
        {
            profile_id = (U8) -1 ;
        }
        else
        {
            profile_id = mmi_wap_prof_ui_get_selected_index();
        }
        */
        profile_id = (U8) -1 ;

        mmi_wap_prof_send_cfg_dtcnt_send_response_ind(g_mmi_wap_prof_cntx.sim_id, 
                                                      g_mmi_wap_prof_cntx.app_id, 
                                                      profile_id, 
                                                      MMI_WAP_PROF_SUCCESS, 
                                                      g_mmi_wap_prof_cntx.callback);
        g_mmi_wap_prof_cntx.callback = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 * mmi_wap_prof_cfg_error_response
 * DESCRIPTION
 * Sends the response as error to other modules in case of configure data account indication.
 * PARAMETERS
 *  sim_id              [IN]
 *  app_id              [IN]
 *  profile_id          [IN]
 *  response_functptr   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_cfg_error_response(mmi_wap_prof_sim_id_enum sim_id, 
                                     mmi_wap_prof_app_id_enum app_id,
                                     U8 profile_index, 
                                     mmi_wap_prof_configure_dtcnt_cnf_funcptr_type response_functptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 profile_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_CFG_DTCNT_ERR_RSP, sim_id, app_id, profile_index);
    
    if (response_functptr)
    {
       /* if (profile_index == mmi_wap_prof_get_active_profile_index(sim_id, app_id))
        {
            profile_id =  (U8) -1 ;
        }
        else
        {
            profile_id = profile_index;
        }*/

        profile_id =  (U8) -1 ;

        mmi_wap_prof_send_cfg_dtcnt_send_response_ind(sim_id, app_id, profile_id, MMI_WAP_PROF_ERR, (void*) response_functptr);
    }
 
        }
#endif /* __MMI_WAP_PROF_CFG_DTCNT_SUPPORT__ */
        
        

#endif /* __MMI_WAP_PROF__ */ 
