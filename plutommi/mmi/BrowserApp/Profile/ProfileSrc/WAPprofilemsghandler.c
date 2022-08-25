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
 * WAPProfileMsgHandler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is source file for message / interface handling for profile module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include "MMI_include.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#ifdef __MMI_WAP_PROF__

//#include "WAPProfConfig.h"
#include "WAPProfileType.h"
//#include "WAPProfResDef.h"
//#include "mmi_rp_app_mmi_wap_prof_def.h"
#include "WAPProfileProt.h"
//#include "WAPProfileGProt.h"
//#include "Wap_ps_struct.h"
//#include "custom_nvram_editor_data_item.h"
//#include "Nvram_enums.h"
//#include "ConnectManageGprot.h"
//#include "DataAccountGProt.h"

//------------------------------ suggest Add ------------------------------

#include "stack_config.h"
#include "stack_msgs.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "MMI_inet_app_trc.h"

#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
//------------------------------ usage ------------------------------

    
    


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_send_process_job_queue_ind
 * DESCRIPTION
 *  Sends process job queue indication to UPP itself.
 *  PARAMETERS:
 *  void
 *  sim_id(?)
 *  app_id(?)
 *  content(?)
 *****************************************************************************/
void mmi_wap_prof_send_process_job_queue_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_prof_send_msg(MOD_MMI, MSG_ID_MMI_WAP_PROF_PROCESS_JOB_QUEUE_IND, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_process_job_queue_ind_hdlr
 * DESCRIPTION
 *  Handler for processing job queue.
 *  
 *  PARAMETERS:
 *  msg     [?]     
 *****************************************************************************/
void mmi_wap_prof_process_job_queue_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_WAP_PROF_READY != g_mmi_wap_prof_cntx.module_status)
    {
/*        MMI_PRINT(MMI_WAP_PROF_MOD_INET_APP, MMI_WAP_PROF_TRC_GRP9, "[WAP_PROF] Process job fail, Profile is busy status = %d", g_mmi_wap_prof_cntx.module_status); */
        MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_ERR_PROCESS_JOB_FAIL_PROFILE_BUSY, g_mmi_wap_prof_cntx.module_status);

        /* job will be processed when ready. */
        return;
    }

    mmi_wap_prof_process_job();
}






/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_send_msg
 * DESCRIPTION
 *  Send message to other modules
 *  
 *  PARAMETERS:
 *  dst_mod_id          [IN]        
 *  msg_id              [IN]        
 *  local_param_ptr     [IN]        
 *  peer_buf_ptr        [IN]        
 *****************************************************************************/
void mmi_wap_prof_send_msg(U16 dst_mod_id, U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslMsgId = (oslMsgType) msg_id;         /* Type casting, to make compiler happer */
    Message.oslDataPtr = (oslParaType*) local_param_ptr;
    Message.oslPeerBuffPtr = peer_buf_ptr;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = (oslModuleType) dst_mod_id; /* Type casting, to make compiler happer */
    OslMsgSendExtQueue(&Message);
}

#ifdef __MMI_WAP_PROF_CFG_DTCNT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_cfg_dtcnt_send_response_ind_hdlr
 * DESCRIPTION
 *  This API sends a primitive to self to make callback nonblocking.
 * PARAMETERS
 *  msg                 [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_cfg_dtcnt_send_response_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_prof_cfg_dtcnt_send_response_ind_struct *rsp_data;
    mmi_wap_prof_configure_dtcnt_cnf_funcptr_type callback;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    rsp_data = (mmi_wap_prof_cfg_dtcnt_send_response_ind_struct*) msg;

    callback = (mmi_wap_prof_configure_dtcnt_cnf_funcptr_type) rsp_data->callback;
    callback(rsp_data->sim_id,
             rsp_data->app_id,
             rsp_data->profile_id,
             rsp_data->response);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_send_cfg_dtcnt_send_response_ind
 * DESCRIPTION
 *  This API sends a primitive to self to make callback nonblocking.
 * PARAMETERS
 *  sim_id                  [IN]
 *  app_id                  [IN]
 *  result                  [IN]
 *  callback                [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_send_cfg_dtcnt_send_response_ind(mmi_wap_prof_sim_id_enum sim_id,
                                                   mmi_wap_prof_app_id_enum app_id,
                                                   U8 profile_id,
                                                   mmi_wap_prof_result_enum result,
                                                   void *callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     mmi_wap_prof_cfg_dtcnt_send_response_ind_struct *l_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    l_data = (mmi_wap_prof_cfg_dtcnt_send_response_ind_struct*)
                OslConstructDataPtr(sizeof(mmi_wap_prof_cfg_dtcnt_send_response_ind_struct));
    l_data->sim_id = sim_id;
    l_data->app_id = app_id;
    l_data->profile_id = profile_id;
    l_data->response = result;
    l_data->callback = callback;

    SetProtocolEventHandler(mmi_wap_prof_cfg_dtcnt_send_response_ind_hdlr, MSG_ID_MMI_WAP_PROF_CFG_DTCNT_SEND_RESPONSE_IND);

    mmi_wap_prof_send_msg(MOD_MMI, MSG_ID_MMI_WAP_PROF_CFG_DTCNT_SEND_RESPONSE_IND, (void*)l_data, NULL);
}


#endif /* __MMI_WAP_PROF_CFG_DTCNT_SUPPORT__ */
#endif /* __MMI_WAP_PROF__ */
