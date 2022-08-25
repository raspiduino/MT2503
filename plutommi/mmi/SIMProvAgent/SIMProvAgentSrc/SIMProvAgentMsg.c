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
 *  SIMProvAgentMsg.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SPA message handlers
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifdef __SPA_SUPPORT__

/**************************************************************/
/**********************  Header Files *************************/
/**************************************************************/
#include "MMIDataType.h"
#include "SIMProvAgentConst.h"
#include "SIMProvAgentDefs.h"
#include "SIMProvAgentConfig.h"
#include "MMI_features.h"
#include "kal_general_types.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_events_gprot.h"
#include "sim_common_enums.h"
#include "ps_public_struct.h"
#include "ps_public_utility.h"
#include "string.h"
#include "sim_public_api.h"

#include "CcaSrvGprot.h"

#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "SIMProvAgentProt.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
#include "ProvBoxSrvGprot.h"
#endif


/*****************************************************************/
/******* Constants / Structure / Variables Declaration ***********/
/*****************************************************************/
/* static U16 mmi_spa_new_setting_trans_id = 0; */
static U32 g_spa_job_trans_id = 0;

/*****************************************************************/
/******* Functions ***********/
/*****************************************************************/
static void mmi_spa_set_cca_show_sim_profile_flag(U32 *flag, mmi_spa_sim_id_enum sim_id);
static void mmi_spa_reset_cca_show_sim_profile_flag(U32 *flag, mmi_spa_sim_id_enum sim_id);
static void mmi_spa_set_cca_sim_changed_flag(U32 *flag, mmi_spa_sim_id_enum sim_id);
static void mmi_spa_reset_cca_sim_changed_flag(U32 *flag, mmi_spa_sim_id_enum sim_id);
static mmi_cca_sim_id_enum mmi_spa_sim_id_converter_spa2cca(mmi_spa_sim_id_enum spa_sim_id);

/* static U16 mmi_spa_get_new_setting_trans_id(void); */
static void mmi_spa_convert_sim_info_ext(const srv_sim_ctrl_availability_changed_evt_struct *sim_info,
                mmi_spa_sim_status_info_ind_struct *info);
static void mmi_spa_convert_sim_info_from_mode(const srv_mode_switch_notify_struct *sim_info,
                mmi_spa_sim_status_info_ind_struct *info);

static U32 mmi_spa_get_trans_id(void);

#ifdef MMI_SPA_JOB_SUPPORT

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
static mmi_provbox_sim_id_enum mmi_spa_sim_id_convert_spa2provbox(mmi_spa_sim_id_enum sim_id);
static MMI_BOOL mmi_spa_is_msg_type_of_spa(mmi_provbox_msg_type_enum type);
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

#endif /* MMI_SPA_JOB_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_sim_info_notify_hdlr
 * DESCRIPTION
 *  SPA SIM info notify ind handler
 * PARAMETERS
 *  msg             [IN]        
 *  mod_src         [IN]        
 *  peer_buf        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef SPA_TEST_CODE
void mmi_spa_test_send_get_ef_info_req(U8 idx);
#endif 
U8 mmi_spa_sim_info_notify_hdlr(void *msg, int mod_src, void *peer_buf)
{
    return 0;
}

mmi_ret mmi_spa_sim_available_change_hdlr(mmi_event_struct *evt)
{
    srv_sim_ctrl_availability_changed_evt_struct *sim_info = (srv_sim_ctrl_availability_changed_evt_struct*)evt;
    mmi_spa_sim_status_info_ind_struct info;

    mmi_spa_convert_sim_info_ext(sim_info, &info);
    mmi_spa_sim_info_handler(&info);
    
    return MMI_RET_OK;
}

mmi_ret mmi_spa_mode_switch_event_hdlr(mmi_event_struct *evt)
{
    srv_mode_switch_notify_struct *sim_info = (srv_mode_switch_notify_struct*)evt;
    mmi_spa_sim_status_info_ind_struct info;

    mmi_spa_convert_sim_info_from_mode(sim_info, &info);
    mmi_spa_sim_info_handler(&info);
    return MMI_RET_OK;
}


static void mmi_spa_convert_sim_info_ext(const srv_sim_ctrl_availability_changed_evt_struct *sim_info,
                mmi_spa_sim_status_info_ind_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL sim1_insert = MMI_FALSE;
    MMI_BOOL sim2_insert = MMI_FALSE;
    srv_mode_switch_type_enum mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CONVERT_SIM_INFO);

    if (!sim_info || !info)
    {
        return;
    }
    
    /* sim id */
    switch(sim_info->sim)
    {
        case MMI_SIM1:
            info->sim_id = MMI_SPA_SIM_ID_SIM1;
            break;
            
        case MMI_SIM2:
            info->sim_id = MMI_SPA_SIM_ID_SIM2;
            break;

        case MMI_SIM_NONE:
            info->sim_id = MMI_SPA_SIM_ID_NO_SIM;
            break;
            
        default:
            if (sim_info->sim == MMI_SIM1 | MMI_SIM2)
            {
                info->sim_id = MMI_SPA_SIM_ID_DUAL_SIM;
                break;
            }
            info->sim_id = MMI_SPA_SIM_ID_SIM1;
            break;
    }
    
    /* sim_inserted */
    sim1_insert = (MMI_BOOL)srv_sim_ctrl_is_inserted(MMI_SIM1);
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
#endif
    if (sim1_insert && sim2_insert)
    {
        info->sim_inserted = MMI_SPA_SIM_ID_DUAL_SIM;
    }
    else if (sim1_insert)
    {
        info->sim_inserted = MMI_SPA_SIM_ID_SIM1;
    }
    else if (sim2_insert)
    {
        info->sim_inserted = MMI_SPA_SIM_ID_SIM2;
    }
    else
    {
        info->sim_inserted = MMI_SPA_SIM_ID_NO_SIM;
    }
    
    /* setting_mode */
    mode = srv_mode_switch_get_current_mode();
    switch(mode)
    {
        case SRV_MODE_SWITCH_ALL_OFF:
            info->setting_mode = MMI_SPA_SIM_ID_FLIGHT_MODE;
            break;
            
	case SRV_MODE_SWITCH_SIM1:
            info->setting_mode = MMI_SPA_SIM_ID_SIM1;
            break;
            
	case SRV_MODE_SWITCH_SIM2:
            info->setting_mode = MMI_SPA_SIM_ID_SIM2;
            break;
            
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        default:
            info->setting_mode = MMI_SPA_SIM_ID_DEFAULT;
            break;
    }
    
    /* can read*/
    info->sim1_can_read = srv_sim_ctrl_is_available(MMI_SIM1);
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
#endif
    /* sim1_type */
    if (!sim1_insert)
    {
        info->sim1_type = MMI_SPA_SIM_TYPE_UNKNOWN;
    }
    else if (srv_nw_info_sim_is_rejected(MMI_SIM1))
    {
        info->sim1_type = MMI_SPA_SIM_TYPE_INVALID_SIM;
    }
    else if (srv_sim_ctrl_chv1_is_blocked(MMI_SIM1))
    {
        info->sim1_type = MMI_SPA_SIM_TYPE_BLOCKED_SIM;
    }
    else
    {
        info->sim1_type = MMI_SPA_SIM_TYPE_VALID_SIM;
    }
#ifdef __MMI_DUAL_SIM__
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
#endif
}

static void mmi_spa_convert_sim_info_from_mode(const srv_mode_switch_notify_struct *sim_info,
                mmi_spa_sim_status_info_ind_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL sim1_insert = MMI_FALSE;
    MMI_BOOL sim2_insert = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CONVERT_SIM_INFO);

    if (!sim_info || !info)
    {
        return;
    }
    
    /* sim id */
    info->sim_id = MMI_SPA_SIM_ID_DUAL_SIM;
    
    /* sim_inserted */
    sim1_insert = (MMI_BOOL)srv_sim_ctrl_is_inserted(MMI_SIM1);
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
#endif
    if (sim1_insert && sim2_insert)
    {
        info->sim_inserted = MMI_SPA_SIM_ID_DUAL_SIM;
    }
    else if (sim1_insert)
    {
        info->sim_inserted = MMI_SPA_SIM_ID_SIM1;
    }
    else if (sim2_insert)
    {
        info->sim_inserted = MMI_SPA_SIM_ID_SIM2;
    }
    else
    {
        info->sim_inserted = MMI_SPA_SIM_ID_NO_SIM;
    }
    
    /* setting_mode */
    switch(sim_info->gsm_select_mode)
    {
        case SRV_MODE_SWITCH_ALL_OFF:
            info->setting_mode = MMI_SPA_SIM_ID_FLIGHT_MODE;
            break;
            
	case SRV_MODE_SWITCH_SIM1:
            info->setting_mode = MMI_SPA_SIM_ID_SIM1;
            break;
            
	case SRV_MODE_SWITCH_SIM2:
            info->setting_mode = MMI_SPA_SIM_ID_SIM2;
            break;

#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        default:
            info->setting_mode = MMI_SPA_SIM_ID_DEFAULT;
            break;
    }
    
    /* can read*/
    info->sim1_can_read = srv_sim_ctrl_is_available(MMI_SIM1);
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
#endif
    /* sim1_type */
    if (!sim1_insert)
    {
        info->sim1_type = MMI_SPA_SIM_TYPE_UNKNOWN;
    }
    else if (!srv_nw_info_sim_is_rejected(MMI_SIM1))
    {
        info->sim1_type = MMI_SPA_SIM_TYPE_INVALID_SIM;
    }
    else if (srv_sim_ctrl_chv1_is_blocked(MMI_SIM1))
    {
        info->sim1_type = MMI_SPA_SIM_TYPE_BLOCKED_SIM;
    }
    else
    {
        info->sim1_type = MMI_SPA_SIM_TYPE_VALID_SIM;
    }
#ifdef __MMI_DUAL_SIM__
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
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_spa_cca_new_setting_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_cca_new_setting_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_source_ui_new_setting_rsp_struct *info = (mmi_cca_source_ui_new_setting_rsp_struct*) msg;
    mmi_spa_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CCA_NEW_SETTING_RSP_HDLR, info->sim_id);

    if (info->response == CCA_STATUS_OK)
    {
        result = MMI_SPA_RESULT_OK;
    }
    else
    {
        result = MMI_SPA_RESULT_FAIL;
    }

#ifdef MMI_SPA_JOB_SUPPORT
    mmi_spa_new_setting_rsp_handler(mmi_spa_sim_id_converter_cca2spa((mmi_cca_sim_id_enum)info->sim_id), result, (U32) info->trans_id);
#else 
    mmi_spa_new_setting_rsp_handler(mmi_spa_sim_id_converter_cca2spa((mmi_cca_sim_id_enum)info->sim_id), result);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_cca_new_doc_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_cca_new_doc_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_source_new_doc_rsp_struct *data = (mmi_cca_source_new_doc_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CCA_NEW_DOC_RSP_HDLR, data->sim_id);
#ifndef MMI_SPA_JOB_SUPPORT
    mmi_spa_cca_new_doc_rsp_handler(mmi_spa_sim_id_converter_cca2spa(data->sim_id));
#else 
    mmi_spa_cca_new_doc_rsp_handler(data);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_send_cca_sim_profile_status_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_send_cca_sim_profile_status_ind(mmi_spa_sim_id_enum sim_id, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_source_sim_profile_status_ind_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SEND_CCA_SIM_PROV_IND, sim_id, flag);

    data = (mmi_cca_source_sim_profile_status_ind_struct*)
        OslConstructDataPtr(sizeof(mmi_cca_source_sim_profile_status_ind_struct));

    data->source_id = CCA_SOURCE_SPA;
    data->prov_type = MMI_CCA_PROV_TYPE_SIM_PROV;
    data->prov_flag = 0;
    data->spec_id = CCA_SPEC_OMA;
    data->sim_id = (U16) mmi_spa_sim_id_converter_spa2cca(sim_id);

    /* SIM1 show? */
    if (flag & MMI_SPA_FLAG_SIM1_SHOW)
    {
        mmi_spa_set_cca_show_sim_profile_flag((U32*) (&data->prov_flag), MMI_SPA_SIM_ID_SIM1);
    }
    else
    {
        mmi_spa_reset_cca_show_sim_profile_flag((U32*) (&data->prov_flag), MMI_SPA_SIM_ID_SIM1);
    }
    /* SIM2 show? */
    if (flag & MMI_SPA_FLAG_SIM2_SHOW)
    {
        mmi_spa_set_cca_show_sim_profile_flag((U32*) (&data->prov_flag), MMI_SPA_SIM_ID_SIM2);
    }
    else
    {
        mmi_spa_reset_cca_show_sim_profile_flag((U32*) (&data->prov_flag), MMI_SPA_SIM_ID_SIM2);
    }

    mmi_spa_reset_cca_sim_changed_flag((U32*) (&data->prov_flag), MMI_SPA_SIM_ID_SIM1);
    mmi_spa_reset_cca_sim_changed_flag((U32*) (&data->prov_flag), MMI_SPA_SIM_ID_SIM2);
    mmi_spa_set_sim_changed_status_ok(sim_id);

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SEND_CCA_SIM_PROV_IND_FLAG, data->prov_flag);

    mmi_frm_send_ilm((oslModuleType) MOD_MMI, MSG_ID_MMI_CCA_SOURCE_SIM_PROFILE_STATUS_IND, 
                        (oslParaType*)data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_send_cca_new_doc_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 *  sim_id      [IN]        
 *  hConfig     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_send_cca_new_doc_ind(U32 flag, mmi_spa_sim_id_enum sim_id, S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_source_new_doc_ind_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SEND_CCA_NEW_DOC_IND, flag, sim_id, hConfig);

    data = (mmi_cca_source_new_doc_ind_struct*) OslConstructDataPtr(sizeof(mmi_cca_source_new_doc_ind_struct));

    data->source_id = CCA_SOURCE_SPA;
    data->prov_type = MMI_CCA_PROV_TYPE_SIM_PROV;
    data->prov_flag = 0;
    data->sim_id = (U16) mmi_spa_sim_id_converter_spa2cca(sim_id);
    data->spec_id = CCA_SPEC_OMA;
    data->hConfig = hConfig;

    /* SIM1 show? */
    if (flag & MMI_SPA_FLAG_SIM1_SHOW)
    {
        mmi_spa_set_cca_show_sim_profile_flag((U32*) (&data->prov_flag), MMI_SPA_SIM_ID_SIM1);
    }
    else
    {
        mmi_spa_reset_cca_show_sim_profile_flag((U32*) (&data->prov_flag), MMI_SPA_SIM_ID_SIM1);
    }
    /* SIM2 show? */
    if (flag & MMI_SPA_FLAG_SIM2_SHOW)
    {
        mmi_spa_set_cca_show_sim_profile_flag((U32*) (&data->prov_flag), MMI_SPA_SIM_ID_SIM2);
    }
    else
    {
        mmi_spa_reset_cca_show_sim_profile_flag((U32*) (&data->prov_flag), MMI_SPA_SIM_ID_SIM2);
    }

    if (hConfig && mmi_spa_is_sim_changed(MMI_SPA_SIM_ID_SIM1))
    {
        mmi_spa_set_cca_sim_changed_flag((U32*) (&data->prov_flag), MMI_SPA_SIM_ID_SIM1);
    }
    else
    {
        mmi_spa_reset_cca_sim_changed_flag((U32*) (&data->prov_flag), MMI_SPA_SIM_ID_SIM1);
    }

    if (hConfig && mmi_spa_is_sim_changed(MMI_SPA_SIM_ID_SIM2))
    {
        mmi_spa_set_cca_sim_changed_flag((U32*) (&data->prov_flag), MMI_SPA_SIM_ID_SIM2);
    }
    else
    {
        mmi_spa_reset_cca_sim_changed_flag((U32*) (&data->prov_flag), MMI_SPA_SIM_ID_SIM2);
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SEND_CCA_NEW_DOC_IND_FLAG, data->prov_flag);

    mmi_frm_send_ilm((oslModuleType) MOD_MMI, MSG_ID_MMI_CCA_SOURCE_NEW_DOC_IND, 
                        (oslParaType*)data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_cca_show_sim_profile_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN/OUT]        
 *  sim_id      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_cca_show_sim_profile_flag(U32 *flag, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        *flag = *flag | MMI_CCA_PROV_FLAG_SHOW_SIM1_PROFILE;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        *flag = *flag | MMI_CCA_PROV_FLAG_SHOW_SIM2_PROFILE;
    }
    else
    {
        /* ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_ERR_SIM_ID_SEST_CCA_SHOW, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_reset_cca_show_sim_profile_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN/OUT]        
 *  sim_id      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_reset_cca_show_sim_profile_flag(U32 *flag, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        *flag = *flag & (~MMI_CCA_PROV_FLAG_SHOW_SIM1_PROFILE);
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        *flag = *flag & (~MMI_CCA_PROV_FLAG_SHOW_SIM2_PROFILE);
    }
    else
    {
        /* ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_ERR_SIM_ID_RESET_CCA_SHOW, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_cca_sim_changed_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN/OUT]        
 *  sim_id      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_cca_sim_changed_flag(U32 *flag, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        *flag = *flag | MMI_CCA_PROV_FLAG_ACTIVATE_SIM1_PROFILE;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        *flag = *flag | MMI_CCA_PROV_FLAG_ACTIVATE_SIM2_PROFILE;
    }
    else
    {
        /* ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_ERR_SIM_ID_SET_CCA_CHANGED, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_reset_cca_sim_changed_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN/OUT]        
 *  sim_id      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_reset_cca_sim_changed_flag(U32 *flag, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        *flag = *flag & (~MMI_CCA_PROV_FLAG_ACTIVATE_SIM1_PROFILE);
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        *flag = *flag & (~MMI_CCA_PROV_FLAG_ACTIVATE_SIM2_PROFILE);
    }
    else
    {
        /* ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_ERR_SIM_ID_RESET_CCA_CHANGED, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_send_cca_new_setting_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  msg_id          [IN]        
 *  trans_id        [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_send_cca_new_setting_ind(mmi_spa_sim_id_enum sim_id, U32 msg_id, U32 *trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_source_ui_new_setting_ind_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SEND_CCA_NEW_SETTING_IND, sim_id);

    data = (mmi_cca_source_ui_new_setting_ind_struct*)
        OslConstructDataPtr(sizeof(mmi_cca_source_ui_new_setting_ind_struct));

    data->num_apps = 0;
    data->source_id = CCA_SOURCE_SPA;
    data->prov_type = MMI_CCA_PROV_TYPE_SIM_PROV;
    data->sim_id = (U16) mmi_spa_sim_id_converter_spa2cca(sim_id);
    data->spec_id = CCA_SPEC_OMA;
    data->trans_id = (U32) mmi_spa_get_trans_id();  /* mmi_spa_get_new_setting_trans_id(); */

    if (trans_id)
    {
        *trans_id = (U32) data->trans_id;
    }

    mmi_frm_send_ilm((oslModuleType) MOD_MMI, MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_IND, 
                        (oslParaType*)data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_sim_id_converter_cca2spa
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cca_sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_spa_sim_id_enum mmi_spa_sim_id_converter_cca2spa(mmi_cca_sim_id_enum cca_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cca_sim_id)
    {
        case MMI_CCA_SIM_ID_SIM1:
            return MMI_SPA_SIM_ID_SIM1;

        case MMI_CCA_SIM_ID_SIM2:
            return MMI_SPA_SIM_ID_SIM2;

        case MMI_CCA_SIM_ID_DUAL_SIM:
            return MMI_SPA_SIM_ID_DUAL_SIM;

        default:
            return MMI_SPA_SIM_ID_SIM1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_sim_id_converter_spa2cca
 * DESCRIPTION
 *  
 * PARAMETERS
 *  spa_sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_cca_sim_id_enum mmi_spa_sim_id_converter_spa2cca(mmi_spa_sim_id_enum spa_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (spa_sim_id)
    {
        case MMI_SPA_SIM_ID_SIM1:
            return MMI_CCA_SIM_ID_SIM1;

        case MMI_SPA_SIM_ID_SIM2:
            return MMI_CCA_SIM_ID_SIM2;

        case MMI_SPA_SIM_ID_DUAL_SIM:
            return MMI_CCA_SIM_ID_DUAL_SIM;

        default:
            /* ASSERT(0); */
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_ERR_SIM_ID_SPA2CCA, spa_sim_id);
            return MMI_CCA_SIM_ID_SIM1;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_spa_cca_ready_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cca_ready_ind       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_cca_ready_ind_hdlr(void *cca_ready_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CCA_READY_IND_HDLR);
    mmi_spa_cca_ready_ind_handler();
}

#ifdef SPA_TEST_CODE
static U8 *ef_buf = NULL;
static U16 ef_len = 0;
static U8 ef_idx = 0;

void mmi_spa_test_get_ef_info_rsp_hdlr(void *info);
void mmi_spa_test_send_read_ef_req(U8 idx, U16 len, U8 *buf);
void mmi_spa_test_read_ef_rsp_hdlr(void *info);


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_test_send_get_ef_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_test_send_get_ef_info_req(U8 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_file_info_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ef_idx = idx;

    SetProtocolEventHandler(mmi_spa_test_get_ef_info_rsp_hdlr, MSG_ID_MMI_SMU_READ_FILE_INFO_RSP);

    dataPtr = (mmi_smu_read_file_info_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_file_info_req_struct));
    dataPtr->file_idx = (U8) idx;
    mmi_frm_send_ilm((oslModuleType) MOD_L4C, MSG_ID_MMI_SMU_READ_FILE_INFO_REQ, 
                        (oslParaType*)dataPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_test_get_ef_info_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_test_get_ef_info_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_file_info_rsp_struct *ef_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ef_info = (mmi_smu_read_file_info_rsp_struct*) info;

#ifdef __GEMINI__
    if (ef_info->result.flag == 0 && sim_service_table_query(SERVICE_MMS, l4c_gemini_get_switched_sim_id(0)) == SERVICE_SUPPORT)
#else 
    if (ef_info->result.flag == 0 && sim_service_table_query(SERVICE_MMS) == SERVICE_SUPPORT)
#endif 
    {
        ef_len = ef_info->file_size;
        ef_buf = mmi_spa_malloc(ef_len);
        if (!ef_buf)
        {
            /* ASSERT(0); */
            return;
        }
        mmi_spa_test_send_read_ef_req(ef_idx, ef_len, ef_buf);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_test_send_read_ef_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 *  len     [IN]        
 *  buf     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_test_send_read_ef_req(U8 idx, U16 len, U8 *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_spa_test_read_ef_rsp_hdlr, MSG_ID_MMI_SMU_READ_SIM_RSP);

    dataPtr = (mmi_smu_read_sim_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    dataPtr->file_idx = (U8) idx;   /* SPDI...FILE_SPDI_IDX */
    dataPtr->para = 0;
    dataPtr->length = len;
    mmi_frm_send_ilm((oslModuleType) MOD_L4C, MSG_ID_MMI_SMU_READ_SIM_REQ, 
                        (oslParaType*)dataPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_test_read_ef_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_test_read_ef_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_rsp_struct *ef_data;
    mmi_spa_sim_mmsicp_parse_param_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ef_data = (mmi_smu_read_sim_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_MMI_SMU_READ_SIM_RSP);

    if (ef_data->result.flag == 0)
    {
        memcpy(ef_buf, (void*)ef_data->data, ef_data->length);
    }

    param.buf = ef_buf;
    param.len = (S32) ef_data->length;
    param.hRoot = mmi_cca_doc_new_rootnode();

    mmi_spa_mmsicp_parser(&param, NULL);
}

#endif /* SPA_TEST_CODE */ 

#ifdef MMI_SPA_JOB_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_send_cca_invalid_setting_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_send_cca_invalid_setting_ind(mmi_spa_sim_id_enum sim_id, U32 msg_id, cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_source_ui_invalid_setting_ind_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SEND_CCA_INVALID_SETTING_IND, status);

    data = (mmi_cca_source_ui_invalid_setting_ind_struct*)
        OslConstructDataPtr(sizeof(mmi_cca_source_ui_invalid_setting_ind_struct));

    data->source_id = CCA_SOURCE_SPA;
    data->prov_type = MMI_CCA_PROV_TYPE_SIM_PROV;
    data->status = status;
    data->msg_id = msg_id;
    data->sim_id = mmi_spa_sim_id_converter_spa2cca(sim_id);
    
    mmi_frm_send_ilm((oslModuleType) MOD_MMI, MSG_ID_MMI_CCA_SOURCE_UI_INVALID_SETTING_IND, 
                        (oslParaType*)data, NULL);
}

#ifdef __MMI_PROV_MESSAGE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_is_msg_type_of_spa
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_spa_is_msg_type_of_spa(mmi_provbox_msg_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMI_PROVBOX_MSG_TYPE_SIM_MMSICP:
            return MMI_TRUE;

        default:
            return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_send_provbox_save_msg_data_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  msg_type        [IN]        
 *  msg_data        [IN]
 *  trans_id        [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_send_provbox_save_msg_data_req(
        mmi_spa_sim_id_enum sim_id,
        mmi_provbox_msg_type_enum msg_type,
        mmi_provbox_save_msg_req_struct *msg_data,
        U32 *trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_save_msg_req_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SEND_PROVBOX_SAVE_MSG_DATA_REQ, sim_id);

    data = (mmi_provbox_save_msg_req_struct*) OslConstructDataPtr(sizeof(mmi_provbox_save_msg_req_struct));

    /* memcpy(data, msg_data, sizeof(mmi_provbox_save_msg_req_struct)); */
    data->trans_id = mmi_spa_get_trans_id();
    memcpy(&data->cmn_info, &msg_data->cmn_info, sizeof(mmi_provbox_msg_cmn_info_struct));
    memcpy(&data->msg_config_status, &msg_data->msg_config_status, sizeof(data->msg_config_status));
    memcpy(&data->msg_data, &msg_data->msg_data, sizeof(mmi_provbox_msg_data_struct));
    data->cmn_info.sim_id = mmi_spa_sim_id_convert_spa2provbox(sim_id);
    data->cmn_info.msg_type = msg_type;

    *trans_id = data->trans_id;

    mmi_frm_send_ilm((oslModuleType) MOD_MMI, MSG_ID_MMI_PROVBOX_SAVE_MSG_REQ, 
                        (oslParaType*)data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_provbox_save_msg_data_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg             [IN]
 *  src_mod         [IN]        
 *  peer_buf        [IN]
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_spa_provbox_save_msg_data_cnf_hdlr(void *msg, int src_mod, void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_save_msg_cnf_struct *data = (mmi_provbox_save_msg_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_PROVBOX_SAVE_MSG_DATA_CNF_HDLR);

    if (!mmi_spa_is_msg_type_of_spa(data->msg_type))
    {
        return 0;
    }

    mmi_spa_provbox_save_msg_data_cnf_handler(data);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_provbox_save_msg_available_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg             [IN]
 *  src_mod         [IN]        
 *  peer_buf        [IN]
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_spa_provbox_save_msg_available_ind_hdlr(void *msg, int src_mod, void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_save_msg_available_ind_struct *data = (mmi_provbox_save_msg_available_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SAVE_MSG_AVAILABLE_IND_HDLR);
    mmi_spa_provbox_save_msg_available_ind_handler(data);

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_cca_install_msg_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg             [IN]
 *  src_mod         [IN]        
 *  peer_buf        [IN]
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_spa_cca_install_msg_req_hdlr(void *msg, int src_mod, void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_source_install_prov_msg_req_struct *data = (mmi_cca_source_install_prov_msg_req_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_INSTALL_MSG_REQ_HDLR, data->prov_type);

    if (data->prov_type != MMI_CCA_PROV_TYPE_SIM_PROV)
    {
        return 0;
    }

    mmi_spa_cca_install_msg_req_handler(data);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_send_cca_install_msg_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  msg_id          [IN]        
 *  trans_id        [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_send_cca_install_msg_cnf(mmi_spa_sim_id_enum sim_id, U32 msg_id, U32 trans_id, mmi_spa_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_source_install_prov_msg_cnf_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SEND_CCA_INSTALL_MSG_CNF);

    data =
        (mmi_cca_source_install_prov_msg_cnf_struct*)
        OslConstructDataPtr(sizeof(mmi_cca_source_install_prov_msg_cnf_struct));

    data->source_id = CCA_SOURCE_SPA;
    data->trans_id = trans_id;
    data->sim_id = mmi_spa_sim_id_converter_spa2cca(sim_id);
    data->msg_id = msg_id;
    data->prov_type = MMI_CCA_PROV_TYPE_SIM_PROV;
    data->status = mmi_spa_convert_result_spa2cca(result);

    mmi_frm_send_ilm((oslModuleType) MOD_MMI, MSG_ID_MMI_CCA_SOURCE_INSTALL_PROV_MSG_CNF, 
                        (oslParaType*)data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_send_provbox_get_msg_data_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  trans_id        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_send_provbox_get_msg_data_req(U32 msg_id, U32 *trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_get_msg_data_req_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SEND_PROVBOX_GET_MSG_DATA_REQ);

    data = (mmi_provbox_get_msg_data_req_struct*) OslConstructDataPtr(sizeof(mmi_provbox_get_msg_data_req_struct));

    data->msg_id = msg_id;
    data->trans_id = mmi_spa_get_trans_id();
    data->src_id = MMI_PROVBOX_SOURCE_ID_SPA;

    *trans_id = data->trans_id;

    mmi_frm_send_ilm((oslModuleType) MOD_MMI, MSG_ID_MMI_PROVBOX_GET_MSG_DATA_REQ, 
                        (oslParaType*)data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_provbox_get_msg_data_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg             [IN]
 *  src_mod         [IN]        
 *  peer_buf        [IN]
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_spa_provbox_get_msg_data_cnf_hdlr(void *msg, int src_mod, void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_get_msg_data_cnf_struct *data = (mmi_provbox_get_msg_data_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_PROVBOX_GET_MSG_DATA_CNF_HDLR);

    if (MMI_SPA_RESULT_MSG_NOT_HANDLED == mmi_spa_provbox_get_msg_data_cnf_handler(data))
    {
        return 0;
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_sim_id_convert_spa2provbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_provbox_sim_id_enum mmi_spa_sim_id_convert_spa2provbox(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {
        case MMI_SPA_SIM_ID_DEFAULT:
        case MMI_SPA_SIM_ID_SIM1:
            return (mmi_provbox_sim_id_enum)MMI_SIM1;//MMI_PROVBOX_SIM_ID_SIM1;

        case MMI_SPA_SIM_ID_SIM2:
            return (mmi_provbox_sim_id_enum)MMI_SIM2; //MMI_PROVBOX_SIM_ID_SIM2;

        case MMI_SPA_SIM_ID_DUAL_SIM:
            return (mmi_provbox_sim_id_enum)(MMI_SIM1 | MMI_SIM2);//MMI_PROVBOX_SIM_ID_DUAL_SIM;

        default:
            /* MMI_ASSERT(0); */
            return (mmi_provbox_sim_id_enum)MMI_SIM1;//MMI_PROVBOX_SIM_ID_SIM1;
    }
}

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

#endif /* MMI_SPA_JOB_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_trans_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static U32 mmi_spa_get_trans_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_spa_job_trans_id++;
}

#endif /* __SPA_SUPPORT__ */ 

