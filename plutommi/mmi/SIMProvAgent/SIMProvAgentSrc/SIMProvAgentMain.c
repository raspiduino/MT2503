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
 *  SIMProvAgentMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SPA Main: primitive handlers / memory management / init / deinit
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifdef __SPA_SUPPORT__

#include "SIMProvAgentDefs.h"
#include "SIMProvAgentConfig.h"
#include "MMIDataType.h"
#include "kal_public_defs.h"
#include "SIMProvAgentConst.h"
#include "kal_general_types.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "kal_public_api.h"
#include "string.h"
#include "mmi_frm_events_gprot.h"
#include "stack_msgs.h"
#include "MMI_features.h"
//#include "smu_common_enums.h"
#include "ps_public_enum.h"
#include "sim_common_enums.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "wgui_categories_list.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "wgui_categories_popup.h"
#include "GlobalConstants.h"
#include "Unicodexdcl.h"

#include "CcaSrvGprot.h"
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
#include "ProvBoxSrvGprot.h"
#endif

/**************************************************************/
/**********************  Header Files *************************/
/**************************************************************/
#include "SIMProvAgentProt.h"
#include "mmi_rp_app_spa_def.h"

/*****************************************************************/
/******* Constants / Structure / Variables Declaration ***********/
/*****************************************************************/
static mmi_spa_context_struct g_spa_context;

/* Memory */
static U8 g_spa_mem_pool[MMI_SPA_MAX_MEM_SIZE];
static KAL_ADM_ID g_spa_adm_id;

/* Test code controller */
#ifdef SPA_EF_TEST
static U8 g_spa_test_code_on = 0;
#endif 

/*****************************************************************/
/******* Functions ***********/
/*****************************************************************/
static void mmi_spa_set_notify_wait_flag(void);
static void mmi_spa_reset_notify_wait_flag(void);
static U8 mmi_spa_get_notify_wait_flag(void);
static void mmi_spa_set_sim_profile_show_flag(mmi_spa_sim_id_enum sim_id);
static void mmi_spa_reset_sim_profile_show_flag(mmi_spa_sim_id_enum sim_id);

static void mmi_spa_set_sim_changed_flag(mmi_spa_sim_id_enum sim_id);
static void mmi_spa_reset_sim_changed_flag(mmi_spa_sim_id_enum sim_id);
static void mmi_spa_set_sim_can_read_flag(mmi_spa_sim_id_enum sim_id);
static void mmi_spa_reset_sim_can_read_flag(mmi_spa_sim_id_enum sim_id);
static U8 mmi_spa_get_sim_can_read_flag(mmi_spa_sim_id_enum sim_id);
static void mmi_spa_update_sim_show_flag(mmi_spa_sim_id_enum sim_id, U8 insert, U8 open, U8 can_read, U8 sim_type);
static void mmi_spa_update_all_sim_show_flag(
                U8 insert,
                U8 setting_mode,
                U8 sim1_can_read,
                U8 sim2_can_read,
                U8 sim1_type,
                U8 sim2_type);
static MMI_BOOL mmi_spa_is_cca_ready(void);
static MMI_BOOL mmi_spa_is_sim_status_notified(mmi_spa_sim_id_enum sim_id);
static void mmi_spa_set_sim_status_notified(mmi_spa_sim_id_enum sim_id);

void mmi_spa_send_empty_cca_new_doc(mmi_spa_sim_id_enum sim_id);
static mmi_spa_sim_id_enum mmi_spa_get_sim_status_notified(void);
static void mmi_spa_read_nvram_data(mmi_spa_sim_changed_data *data);
static void mmi_spa_write_nvram_data(mmi_spa_sim_id_enum sim_id, mmi_spa_sim_changed_data *data);
static void mmi_spa_set_sim_changed_status(mmi_spa_sim_id_enum sim_id);
static mmi_spa_sim_changed_status mmi_spa_get_sim_cur_changed_status(mmi_spa_sim_id_enum sim_id);
static mmi_spa_sim_changed_status mmi_spa_get_sim_cur_insert_status(mmi_spa_sim_id_enum sim_id);
static void mmi_spa_sim_write_back_new_sim_changed_status(mmi_spa_sim_id_enum sim_id, mmi_spa_sim_changed_data *data);

#ifdef SPA_EF_TEST
static void mmi_spa_ef_tst_inject_string_hdlr(U8 index, U8 *str);
#endif 

#ifdef MMI_SPA_JOB_SUPPORT

static void mmi_spa_init_sim_ef_processed_flag(mmi_spa_sim_id_enum sim_id);
static void mmi_spa_set_job_list(void);

#else /* MMI_SPA_JOB_SUPPORT */ 

static void mmi_spa_handle_one_sim(mmi_spa_sim_id_enum sim_id);
static void mmi_spa_process_next_sim_notify(void);
static void mmi_spa_ef_process_callback(mmi_spa_sim_ef_process_result_struct *data);
static MMI_BOOL mmi_spa_is_sim_need_to_read(mmi_spa_sim_id_enum sim_id);
static MMI_BOOL mmi_spa_is_sim_notified(mmi_spa_sim_id_enum sim_id, U8 inserted, U8 setting_mode, U8 sim_state);
static void mmi_spa_reset_sim_read_fail_flag(mmi_spa_sim_id_enum sim_id);
static void mmi_spa_set_sim_read_fail_flag(mmi_spa_sim_id_enum sim_id);
static U8 mmi_spa_get_sim_read_fail_flag(mmi_spa_sim_id_enum sim_id);
static void mmi_spa_set_sim_read_flag(mmi_spa_sim_id_enum sim_id);
static U8 mmi_spa_get_sim_read_flag(mmi_spa_sim_id_enum sim_id);
static mmi_spa_process_state_enum mmi_spa_get_process_status(void);
static void mmi_spa_set_process_status(mmi_spa_process_state_enum status);

#endif /* MMI_SPA_JOB_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_init
 * DESCRIPTION
 *  SPA initialisation function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_INIT);

    /* Init ADM */
    g_spa_adm_id = kal_adm_create(
                    (void*)g_spa_mem_pool,
                    (kal_uint32) MMI_SPA_MAX_MEM_SIZE,
                    NULL,
                    (MMI_BOOL) MMI_FALSE);
    MMI_ASSERT(g_spa_adm_id);

    /* Global variables */
    memset(&g_spa_context, 0, sizeof(g_spa_context));
    g_spa_context.sim_notified = MMI_SPA_SIM_ID_NO_SIM;

#ifdef MMI_SPA_JOB_SUPPORT
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_CCA_SOURCE_INSTALL_PROV_MSG_REQ,
        (PsIntFuncPtr) mmi_spa_cca_install_msg_req_hdlr,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_PROVBOX_GET_MSG_DATA_CNF,
        (PsIntFuncPtr) mmi_spa_provbox_get_msg_data_cnf_hdlr,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_PROVBOX_SAVE_MSG_CNF,
        (PsIntFuncPtr) mmi_spa_provbox_save_msg_data_cnf_hdlr,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_PROVBOX_SAVE_MSG_AVAILABLE_IND,
        (PsIntFuncPtr) mmi_spa_provbox_save_msg_available_ind_hdlr,
        MMI_TRUE);
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 
#endif /* MMI_SPA_JOB_SUPPORT */ 

#ifdef SPA_EF_TEST
    /* SetProtocolEventHandler((PsFuncPtr) mmi_spa_ef_tst_inject_string_hdlr, MSG_ID_TST_INJECT_STRING); */
    {
        extern void mmi_spa_read_test_file_name(void);

        mmi_spa_read_test_file_name();
    }
    mmi_spa_test_code_open_init();
#endif /* SPA_EF_TEST */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_malloc
 * DESCRIPTION
 *  SPA memory alloc
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_spa_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = kal_adm_alloc(g_spa_adm_id, (kal_uint32) size);
    //g_spa_mem_max_alloc = kal_adm_get_max_alloc_size(g_spa_adm_id);
    //g_spa_mem_total_left = kal_adm_get_total_left_size(g_spa_adm_id);

    if (!p)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MALLOC_ASSERT, size);
        /* ASSERT(0); */
    }

    return (void*)p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_free
 * DESCRIPTION
 *  SPA memory free
 * PARAMETERS
 *  p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_free(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_adm_free(g_spa_adm_id, p);
    //g_spa_mem_max_alloc = kal_adm_get_max_alloc_size(g_spa_adm_id);
    //g_spa_mem_total_left = kal_adm_get_total_left_size(g_spa_adm_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_sim_info_handler
 * DESCRIPTION
 *  SPA SIM info handler
 * PARAMETERS
 *  sim_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef MMI_SPA_JOB_SUPPORT

void mmi_spa_sim_info_handler(const mmi_spa_sim_status_info_ind_struct *sim_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SIM_INFO_HANDLER, sim_info);

    if (!sim_info)
    {
        return;
    }

    if (mmi_spa_get_ef_table_size() <= MMI_SPA_EMPTY_EF_TABLE_SIZE)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EMPTY_EF_TABLE);
        return;
    }

    MMI_TRACE(
        SPA_TRACE_INFO,
        TRC_MMI_SPA_SIM_INFO_HANDLER_VALUES,
        sim_info->sim_id,
        sim_info->sim_inserted,
        sim_info->setting_mode,
        sim_info->sim1_can_read,
        sim_info->sim2_can_read,
        sim_info->sim1_type,
        sim_info->sim2_type);

    if (sim_info->sim_inserted != MMI_SPA_SIM_ID_DEFAULT &&
        sim_info->sim_inserted != MMI_SPA_SIM_ID_SIM1 &&
        sim_info->sim_inserted != MMI_SPA_SIM_ID_SIM2 &&
        sim_info->sim_inserted != MMI_SPA_SIM_ID_DUAL_SIM && sim_info->sim_inserted != MMI_SPA_SIM_ID_NO_SIM)
    {
        /* ASSERT(!"Error sim_inserted"); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_ERROR_INSERT);
        return;
    }

    /* Save SIM status */
    g_spa_context.sim_status = sim_info->sim_inserted;
    g_spa_context.sim_setting_mode = sim_info->setting_mode;
    g_spa_context.sim1_type = sim_info->sim1_type;
    g_spa_context.sim2_type = sim_info->sim2_type;

    /* Set SIM notified flag */
    mmi_spa_set_sim_status_notified((mmi_spa_sim_id_enum)sim_info->sim_id);

    /* Update SIM changed falg */
    if (sim_info->sim_id == MMI_SPA_SIM_ID_SIM1 || sim_info->sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        /* Get data from NVRAM */
        mmi_spa_read_nvram_data(&g_spa_context.sim_changed_data);

        /* Set SIM changed status */
        mmi_spa_set_sim_changed_status((mmi_spa_sim_id_enum)sim_info->sim_id);
        MMI_TRACE(
            SPA_TRACE_INFO,
            TRC_MMI_SPA_SIM_INFO_HANDLER_CHANGED_RESULT,
            g_spa_context.sim_changed_data.sim1_changed,
            g_spa_context.sim_changed_data.sim2_changed);

        /* Write SIM changed status to NVRAM */
        mmi_spa_sim_write_back_new_sim_changed_status((mmi_spa_sim_id_enum)sim_info->sim_id, &g_spa_context.sim_changed_data);

        /* No SIM */
    #ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
    #else /* __MMI_DUAL_SIM__ */ 
        if (mmi_spa_get_sim_status_notified() == MMI_SPA_SIM_ID_SIM1 &&
            g_spa_context.sim_status == MMI_SPA_SIM_ID_NO_SIM)
    #endif /* __MMI_DUAL_SIM__ */ 
        {
            mmi_spa_set_sim_changed_status_ok(MMI_SPA_SIM_ID_SIM1);
        #ifdef __MMI_DUAL_SIM__
/* under construction !*/
        #endif 
        }
        /* else check all blocked */
    #ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else /* __MMI_DUAL_SIM__ */ 
        else if (mmi_spa_get_sim_status_notified() == MMI_SPA_SIM_ID_SIM1 &&
                 g_spa_context.sim_status == MMI_SPA_SIM_ID_SIM1 &&
                 g_spa_context.sim1_type == MMI_SPA_SIM_TYPE_BLOCKED_SIM)
    #endif /* __MMI_DUAL_SIM__ */ 
        {
            mmi_spa_set_sim_changed_status_ok(MMI_SPA_SIM_ID_SIM1);
        #ifdef __MMI_DUAL_SIM__
/* under construction !*/
        #endif 
        }

        /* Set EF processed flags */
        mmi_spa_init_sim_ef_processed_flag((mmi_spa_sim_id_enum)sim_info->sim_id);
    }

    if (g_spa_context.sim_status == MMI_SPA_SIM_ID_DEFAULT)
    {
        g_spa_context.sim_status = MMI_SPA_SIM_ID_SIM1;
    }

    /* Read flag save in mask */
    if (sim_info->sim1_can_read)
    {
        mmi_spa_set_sim_can_read_flag(MMI_SPA_SIM_ID_SIM1);
    }
    else
    {
        mmi_spa_reset_sim_can_read_flag(MMI_SPA_SIM_ID_SIM1);
    }

    if (sim_info->sim2_can_read)
    {
        mmi_spa_set_sim_can_read_flag(MMI_SPA_SIM_ID_SIM2);
    }
    else
    {
        mmi_spa_reset_sim_can_read_flag(MMI_SPA_SIM_ID_SIM2);
    }

    MMI_TRACE(
        SPA_TRACE_INFO,
        TRC_MMI_SPA_SIM_INFO_HANDLER_CONTEXT_DATA,
        g_spa_context.sim_process_status,
        g_spa_context.sim_flag,
        g_spa_context.sim1_read_retry_count,
        g_spa_context.sim2_read_retry_count);

    /* Not work if in Flight Mode */
    if (g_spa_context.sim_setting_mode == MMI_SPA_SIM_ID_FLIGHT_MODE)
    {
        mmi_spa_remove_sim_ef_jobs(MMI_SPA_SIM_ID_DUAL_SIM, MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE);
    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        mmi_spa_remove_sim_ef_jobs(MMI_SPA_SIM_ID_DUAL_SIM, MMI_SPA_JOB_TYPE_SAVE_TO_BOX);
    #endif 
        return;
    }

    /* If CCA is not ready, save this notification, handle it when CCA is ready */
    if (!mmi_spa_is_cca_ready())
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SIM_INFO_HANDLER_CCA_NOT_READY);
        mmi_spa_set_notify_wait_flag();
        return;
    }

    /* Set show flags */
    mmi_spa_update_all_sim_show_flag(
        g_spa_context.sim_status,
        g_spa_context.sim_setting_mode,
        mmi_spa_get_sim_can_read_flag(MMI_SPA_SIM_ID_SIM1),
        mmi_spa_get_sim_can_read_flag(MMI_SPA_SIM_ID_SIM2),
        g_spa_context.sim1_type,
        g_spa_context.sim2_type);
    /* Set SIM change flag */
    mmi_spa_update_sim_changed_flag();

    /* Add jobs for available SIMs */
    mmi_spa_set_job_list();
}

#else /* MMI_SPA_JOB_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_sim_info_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_sim_info_handler(const mmi_spa_sim_status_info_ind_struct *sim_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_prov_ind_count = 0;
    mmi_spa_sim_id_enum sim_notified;
    mmi_spa_sim_id_enum sim_id;
    mmi_spa_process_state_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SIM_INFO_HANDLER, sim_info);

    if (!sim_info)
    {
        return;
    }

    if (mmi_spa_get_ef_table_size() <= MMI_SPA_EMPTY_EF_TABLE_SIZE)
    {
        return;
    }

    MMI_TRACE(
        SPA_TRACE_INFO,
        TRC_MMI_SPA_SIM_INFO_HANDLER_VALUES,
        sim_info->sim_id,
        sim_info->sim_inserted,
        sim_info->setting_mode,
        sim_info->sim1_can_read,
        sim_info->sim2_can_read,
        sim_info->sim1_type,
        sim_info->sim2_type);

    if (sim_info->sim_inserted != MMI_SPA_SIM_ID_DEFAULT &&
        sim_info->sim_inserted != MMI_SPA_SIM_ID_SIM1 &&
        sim_info->sim_inserted != MMI_SPA_SIM_ID_SIM2 &&
        sim_info->sim_inserted != MMI_SPA_SIM_ID_DUAL_SIM && sim_info->sim_inserted != MMI_SPA_SIM_ID_NO_SIM)
    {
        /* ASSERT(!"Error sim_inserted"); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_ERROR_INSERT);
        return;
    }

    /* Save SIM status */
    g_spa_context.sim_status = sim_info->sim_inserted;
    g_spa_context.sim_setting_mode = sim_info->setting_mode;
    g_spa_context.sim1_type = sim_info->sim1_type;
    g_spa_context.sim2_type = sim_info->sim2_type;

    /* Set SIM notified flag */
    mmi_spa_set_sim_status_notified(sim_info->sim_id);

    /* Update SIM changed falg */
    if (sim_info->sim_id == MMI_SPA_SIM_ID_SIM1 || sim_info->sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        /* Get data from NVRAM */
        mmi_spa_read_nvram_data(&g_spa_context.sim_changed_data);

        mmi_spa_set_sim_changed_status(sim_info->sim_id);
        MMI_TRACE(
            SPA_TRACE_INFO,
            TRC_MMI_SPA_SIM_INFO_HANDLER_CHANGED_RESULT,
            g_spa_context.sim_changed_data.sim1_changed,
            g_spa_context.sim_changed_data.sim2_changed);

        /* Write data to NVRAM */
        mmi_spa_sim_write_back_new_sim_changed_status(sim_info->sim_id, &g_spa_context.sim_changed_data);

        /* No SIM */
    #ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
    #else /* __MMI_DUAL_SIM__ */ 
        if (mmi_spa_get_sim_status_notified() == MMI_SPA_SIM_ID_SIM1 &&
            g_spa_context.sim_status == MMI_SPA_SIM_ID_NO_SIM)
    #endif /* __MMI_DUAL_SIM__ */ 
        {
            mmi_spa_set_sim_changed_status_ok(MMI_SPA_SIM_ID_SIM1);
        #ifdef __MMI_DUAL_SIM__
/* under construction !*/
        #endif 
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
    #else /* __MMI_DUAL_SIM__ */ 
        else if (mmi_spa_get_sim_status_notified() == MMI_SPA_SIM_ID_SIM1 &&
                 g_spa_context.sim_status == MMI_SPA_SIM_ID_SIM1 &&
                 g_spa_context.sim1_type == MMI_SPA_SIM_TYPE_BLOCKED_SIM)
    #endif /* __MMI_DUAL_SIM__ */ 
        {
            mmi_spa_set_sim_changed_status_ok(MMI_SPA_SIM_ID_SIM1);
        #ifdef __MMI_DUAL_SIM__
/* under construction !*/
        #endif 
        }
    }

    if (g_spa_context.sim_status == MMI_SPA_SIM_ID_DEFAULT)
    {
        g_spa_context.sim_status = MMI_SPA_SIM_ID_SIM1;
    }

    /* Read flag save in mask */
    if (sim_info->sim1_can_read)
    {
        mmi_spa_set_sim_can_read_flag(MMI_SPA_SIM_ID_SIM1);
    }
    else
    {
        mmi_spa_reset_sim_can_read_flag(MMI_SPA_SIM_ID_SIM1);
    }

    if (sim_info->sim2_can_read)
    {
        mmi_spa_set_sim_can_read_flag(MMI_SPA_SIM_ID_SIM2);
    }
    else
    {
        mmi_spa_reset_sim_can_read_flag(MMI_SPA_SIM_ID_SIM2);
    }

    MMI_TRACE(
        SPA_TRACE_INFO,
        TRC_MMI_SPA_SIM_INFO_HANDLER_CONTEXT_DATA,
        g_spa_context.sim_process_status,
        g_spa_context.sim_flag,
        g_spa_context.sim1_read_retry_count,
        g_spa_context.sim2_read_retry_count);

    /* Not send message to CCA if in Flight Mode */
    if (g_spa_context.sim_setting_mode == MMI_SPA_SIM_ID_FLIGHT_MODE)
    {
        return;
    }

    /* If CCA is not ready, save this notification, handle it when CCA is ready */
    if (!mmi_spa_is_cca_ready())
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SIM_INFO_HANDLER_CCA_NOT_READY);
        mmi_spa_set_notify_wait_flag();
        return;
    }

    status = mmi_spa_get_process_status();

    if (status == MMI_SPA_PROCESS_STATE_IDLE)
    {
        /* In idle state, if both SIMs no need to read, just send MSG_ID_MMI_CCA_SOURCE_SIM_PROV_IND,
           or send MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_IND to process normally */

        if (mmi_spa_is_sim_notified(
                MMI_SPA_SIM_ID_SIM1,
                g_spa_context.sim_status,
                g_spa_context.sim_setting_mode,
                g_spa_context.sim1_type))
        {
            /* No need read SIM1? */
            if (!mmi_spa_get_sim_read_flag(MMI_SPA_SIM_ID_SIM1) ||
                (mmi_spa_get_sim_read_fail_flag(MMI_SPA_SIM_ID_SIM1) &&
                 g_spa_context.sim1_read_retry_count < MMI_SPA_MAX_SIM_READ_MAX_RETRY_COUNT))
            {

                sim_prov_ind_count++;
            }
        }

        if (mmi_spa_is_sim_notified(
                MMI_SPA_SIM_ID_SIM2,
                g_spa_context.sim_status,
                g_spa_context.sim_setting_mode,
                g_spa_context.sim2_type))
        {
            /* No need read SIM2? */
            if (!mmi_spa_get_sim_read_flag(MMI_SPA_SIM_ID_SIM2) ||
                (mmi_spa_get_sim_read_fail_flag(MMI_SPA_SIM_ID_SIM2) &&
                 g_spa_context.sim2_read_retry_count < MMI_SPA_MAX_SIM_READ_MAX_RETRY_COUNT))
            {
                sim_prov_ind_count++;
            }
        }

        /* No SIM to read */
        if (sim_prov_ind_count == 0)
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SIM_INFO_HANDLER_NO_SIM_NOTIFIED);

            mmi_spa_update_all_sim_show_flag(
                g_spa_context.sim_status,
                g_spa_context.sim_setting_mode,
                sim_info->sim1_can_read,
                sim_info->sim2_can_read,
                g_spa_context.sim1_type,
                g_spa_context.sim2_type);
            mmi_spa_update_sim_changed_flag();

            sim_notified = mmi_spa_get_sim_status_notified();
            if (sim_notified == MMI_SPA_SIM_ID_DUAL_SIM)
            {
                sim_id = MMI_SPA_SIM_ID_DUAL_SIM;
            }
            else
            {
                sim_id = sim_info->sim_id;
            }
            mmi_spa_send_cca_sim_profile_status_ind(sim_id, g_spa_context.sim_flag);
            return;
        }

        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SIM_INFO_HANDLER_SIM_NEED_HANDLE, sim_prov_ind_count);

        mmi_spa_set_process_status(MMI_SPA_PROCESS_STATE_WAIT_NEW_SETTING_RSP);

        if (mmi_spa_is_sim_status_notified(MMI_SPA_SIM_ID_SIM1))
        {
            mmi_spa_send_cca_new_setting_ind(MMI_SPA_SIM_ID_SIM1, 0, NULL);
        }
        else if (mmi_spa_is_sim_status_notified(MMI_SPA_SIM_ID_SIM2))
        {
            mmi_spa_set_process_status(MMI_SPA_PROCESS_STATE_WAIT_SIM2_NEW_SETTING_RSP);
            mmi_spa_send_cca_new_setting_ind(MMI_SPA_SIM_ID_SIM2, 0, NULL);
        }
    }
    else if (status == MMI_SPA_PROCESS_STATE_WAIT_NEW_SETTING_RSP)
    {
        return;
    }
    else if (status == MMI_SPA_PROCESS_STATE_WAIT_NEW_DOC_RSP ||
             status == MMI_SPA_PROCESS_STATE_WAIT_SIM2_NEW_SETTING_RSP)
    {
        mmi_spa_set_notify_wait_flag();
    }
    else
    {
        /* ASSERT(!"Error SPA process status"); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_ERROR_SPA_STATE);
    }
}

#endif /* MMI_SPA_JOB_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_cca_ready_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef MMI_SPA_JOB_SUPPORT

void mmi_spa_cca_ready_ind_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CCA_READY_IND_HANDLER);

    g_spa_context.cca_ready = 1;

    /* No SIM status, just return */
    if (!mmi_spa_get_notify_wait_flag())
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CCA_READY_IND_HANDLER_NOT_SIM_INFO);
        return;
    }

    mmi_spa_reset_notify_wait_flag();

    /* Set show flags */
    mmi_spa_update_all_sim_show_flag(
        g_spa_context.sim_status,
        g_spa_context.sim_setting_mode,
        mmi_spa_get_sim_can_read_flag(MMI_SPA_SIM_ID_SIM1),
        mmi_spa_get_sim_can_read_flag(MMI_SPA_SIM_ID_SIM2),
        g_spa_context.sim1_type,
        g_spa_context.sim2_type);
    /* Set SIM change flag */
    mmi_spa_update_sim_changed_flag();

    /* Add jobs for available SIMs */
    mmi_spa_set_job_list();
}

#else /* MMI_SPA_JOB_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_cca_ready_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_cca_ready_ind_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_prov_ind_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CCA_READY_IND_HANDLER);

    g_spa_context.cca_ready = 1;

    /* No SIM status, just return */
    if (!mmi_spa_get_notify_wait_flag())
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CCA_READY_IND_HANDLER_NOT_SIM_INFO);
        return;
    }

    /* Check state */
    if (mmi_spa_get_process_status() != MMI_SPA_PROCESS_STATE_IDLE)
    {
        /* ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_ERR_SPA_PROCESS_STATE_WHEN_READY);
        return;
    }

    mmi_spa_reset_notify_wait_flag();

    if (mmi_spa_is_sim_notified(
            MMI_SPA_SIM_ID_SIM1,
            g_spa_context.sim_status,
            g_spa_context.sim_setting_mode,
            g_spa_context.sim1_type))
    {
        /* No need read SIM1? */
        if (!mmi_spa_get_sim_read_flag(MMI_SPA_SIM_ID_SIM1) ||
            (mmi_spa_get_sim_read_fail_flag(MMI_SPA_SIM_ID_SIM1) &&
             g_spa_context.sim1_read_retry_count < MMI_SPA_MAX_SIM_READ_MAX_RETRY_COUNT))
        {

            sim_prov_ind_count++;
        }
    }

    if (mmi_spa_is_sim_notified(
            MMI_SPA_SIM_ID_SIM2,
            g_spa_context.sim_status,
            g_spa_context.sim_setting_mode,
            g_spa_context.sim2_type))
    {
        /* No need read SIM2? */
        if (!mmi_spa_get_sim_read_flag(MMI_SPA_SIM_ID_SIM2) ||
            (mmi_spa_get_sim_read_fail_flag(MMI_SPA_SIM_ID_SIM2) &&
             g_spa_context.sim2_read_retry_count < MMI_SPA_MAX_SIM_READ_MAX_RETRY_COUNT))
        {
            sim_prov_ind_count++;
        }
    }

    /* No SIM to read */
    if (sim_prov_ind_count == 0)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SIM_INFO_HANDLER_NO_SIM_NOTIFIED);

        mmi_spa_update_all_sim_show_flag(
            g_spa_context.sim_status,
            g_spa_context.sim_setting_mode,
            mmi_spa_get_sim_can_read_flag(MMI_SPA_SIM_ID_SIM1),
            mmi_spa_get_sim_can_read_flag(MMI_SPA_SIM_ID_SIM2),
            g_spa_context.sim1_type,
            g_spa_context.sim2_type);
        mmi_spa_update_sim_changed_flag();

        mmi_spa_send_cca_sim_profile_status_ind(mmi_spa_get_sim_status_notified(), g_spa_context.sim_flag);
        return;
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SIM_INFO_HANDLER_SIM_NEED_HANDLE, sim_prov_ind_count);

    mmi_spa_set_process_status(MMI_SPA_PROCESS_STATE_WAIT_NEW_SETTING_RSP);
    if (mmi_spa_is_sim_status_notified(MMI_SPA_SIM_ID_SIM1))
    {
        mmi_spa_send_cca_new_setting_ind(MMI_SPA_SIM_ID_SIM1, 0, NULL);
    }
    else if (mmi_spa_is_sim_status_notified(MMI_SPA_SIM_ID_SIM2))
    {
        mmi_spa_set_process_status(MMI_SPA_PROCESS_STATE_WAIT_SIM2_NEW_SETTING_RSP);
        mmi_spa_send_cca_new_setting_ind(MMI_SPA_SIM_ID_SIM2, 0, NULL);
    }
}

#endif /* MMI_SPA_JOB_SUPPORT */ 

#ifndef MMI_SPA_JOB_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_is_sim_notified
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id              [IN]        
 *  inserted            [IN]        
 *  setting_mode        [IN]        
 *  sim_state           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_spa_is_sim_notified(mmi_spa_sim_id_enum sim_id, U8 inserted, U8 setting_mode, U8 sim_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        if (g_spa_context.sim_notified != MMI_SPA_SIM_ID_SIM1 && g_spa_context.sim_notified != MMI_SPA_SIM_ID_DUAL_SIM)
        {
            return MMI_FALSE;
        }

        if ((inserted == MMI_SPA_SIM_ID_SIM1 ||
             inserted == MMI_SPA_SIM_ID_DUAL_SIM) &&
            (setting_mode == MMI_SPA_SIM_ID_SIM1 || setting_mode == MMI_SPA_SIM_ID_DUAL_SIM))
        {
            /* can read? */
            if (!mmi_spa_get_sim_can_read_flag(MMI_SPA_SIM_ID_SIM1))
            {
                return MMI_FALSE;
            }
            return MMI_TRUE;
        }
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        if (g_spa_context.sim_notified != MMI_SPA_SIM_ID_SIM2 && g_spa_context.sim_notified != MMI_SPA_SIM_ID_DUAL_SIM)
        {
            return MMI_FALSE;
        }

        if ((inserted == MMI_SPA_SIM_ID_SIM2 ||
             inserted == MMI_SPA_SIM_ID_DUAL_SIM) &&
            (setting_mode == MMI_SPA_SIM_ID_SIM2 || setting_mode == MMI_SPA_SIM_ID_DUAL_SIM))
        {
            /* can read? */
            if (!mmi_spa_get_sim_can_read_flag(MMI_SPA_SIM_ID_SIM2))
            {
                return MMI_FALSE;
            }
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_process_next_sim_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_process_next_sim_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_prov_ind_count = 0;
    mmi_spa_process_state_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = mmi_spa_get_process_status();

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_PROCESS_NEXT_SIM_NOTIFY, status);

    if (status == MMI_SPA_PROCESS_STATE_IDLE)
    {
        /* Clear this flag to remove this handled notify */
        mmi_spa_reset_notify_wait_flag();

        /* In idle state, if both SIMs no need to read, just send MSG_ID_MMI_CCA_SOURCE_SIM_PROV_IND,
           or send MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_IND to process normally */

        if (mmi_spa_is_sim_notified(
                MMI_SPA_SIM_ID_SIM1,
                g_spa_context.sim_status,
                g_spa_context.sim_setting_mode,
                g_spa_context.sim1_type))
        {
            /* No need read SIM1? */
            if (!mmi_spa_get_sim_read_flag(MMI_SPA_SIM_ID_SIM1) ||
                (mmi_spa_get_sim_read_fail_flag(MMI_SPA_SIM_ID_SIM1) &&
                 g_spa_context.sim1_read_retry_count < MMI_SPA_MAX_SIM_READ_MAX_RETRY_COUNT))
            {

                sim_prov_ind_count++;
            }
        }

        if (mmi_spa_is_sim_notified(
                MMI_SPA_SIM_ID_SIM2,
                g_spa_context.sim_status,
                g_spa_context.sim_setting_mode,
                g_spa_context.sim2_type))
        {
            /* No need read SIM2? */
            if (mmi_spa_get_sim_read_flag(MMI_SPA_SIM_ID_SIM2) &&
                (!mmi_spa_get_sim_read_fail_flag(MMI_SPA_SIM_ID_SIM2) ||
                 g_spa_context.sim2_read_retry_count >= MMI_SPA_MAX_SIM_READ_MAX_RETRY_COUNT))
            {
                sim_prov_ind_count++;
            }
        }

        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_PROCESS_NEXT_SIM_NOTIFY_SIM_IND_COUNT, sim_prov_ind_count);

        /* No SIM to read */
        if (sim_prov_ind_count == 0)
        {
            /* Set show flags */
            mmi_spa_update_all_sim_show_flag(
                g_spa_context.sim_status,
                g_spa_context.sim_setting_mode,
                mmi_spa_get_sim_can_read_flag(MMI_SPA_SIM_ID_SIM1),
                mmi_spa_get_sim_can_read_flag(MMI_SPA_SIM_ID_SIM2),
                g_spa_context.sim1_type,
                g_spa_context.sim2_type);
            /* Set SIM change flag */
            mmi_spa_update_sim_changed_flag();

            /* Send sim profile status ind to notify sim status directly */
            mmi_spa_send_cca_sim_profile_status_ind(mmi_spa_get_sim_status_notified(), g_spa_context.sim_flag);
            return;
        }

        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SIM_INFO_HANDLER_SIM_NEED_HANDLE, sim_prov_ind_count);

        mmi_spa_set_process_status(MMI_SPA_PROCESS_STATE_WAIT_NEW_SETTING_RSP);

        if (mmi_spa_is_sim_status_notified(MMI_SPA_SIM_ID_SIM1))
        {
            mmi_spa_send_cca_new_setting_ind(MMI_SPA_SIM_ID_SIM1, 0, NULL);
        }
        else if (mmi_spa_is_sim_status_notified(MMI_SPA_SIM_ID_SIM2))
        {
            mmi_spa_set_process_status(MMI_SPA_PROCESS_STATE_WAIT_SIM2_NEW_SETTING_RSP);
            mmi_spa_send_cca_new_setting_ind(MMI_SPA_SIM_ID_SIM2, 0, NULL);
        }
    }
    else
    {
        /* ASSERT(!"Should be idle state"); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_ERROR_SPA_STATE);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_new_setting_rsp_handler
 * DESCRIPTION
 *  Handle MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_RSP
 * PARAMETERS
 *  sim_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_new_setting_rsp_handler(mmi_spa_sim_id_enum sim_id, mmi_spa_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_NEW_SETTING_RSP_HANDLER, sim_id);

    if (result != MMI_SPA_RESULT_OK)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_NEW_SETTING_RSP_HANDLER_NOT_OK);
        mmi_spa_set_process_status(MMI_SPA_PROCESS_STATE_IDLE);
        mmi_spa_reset_notify_wait_flag();
        return;
    }

    mmi_spa_set_process_status(MMI_SPA_PROCESS_STATE_WAIT_NEW_DOC_RSP);

    /* This is a new sim status info notification, process starts from SIM1 if it need retry */
    if (sim_id == MMI_SPA_SIM_ID_SIM1 || sim_id == MMI_SPA_SIM_ID_SIM2 && mmi_spa_get_notify_wait_flag())
    {
        if (mmi_spa_get_notify_wait_flag())
        {
            mmi_spa_reset_notify_wait_flag();
        }

        if (mmi_spa_is_sim_need_to_read(MMI_SPA_SIM_ID_SIM1))
        {
            mmi_spa_handle_one_sim(MMI_SPA_SIM_ID_SIM1);
            return;
        }
        else if (mmi_spa_is_sim_status_notified(MMI_SPA_SIM_ID_SIM1))
        {
            /* Send empty new doc for SIM1 */
            mmi_spa_send_empty_cca_new_doc(MMI_SPA_SIM_ID_SIM1);
            return;
        }
    }

    /* This net setting rsp is from finish processing SIM1, so just process SIM2 */
    if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_NEW_SETTING_RSP_HANDLER_SIM2_DIRECTLY);

        if (mmi_spa_is_sim_need_to_read(MMI_SPA_SIM_ID_SIM2))
        {
            mmi_spa_handle_one_sim(MMI_SPA_SIM_ID_SIM2);
            return;
        }
        else if (mmi_spa_is_sim_status_notified(MMI_SPA_SIM_ID_SIM2))
        {
            mmi_spa_send_empty_cca_new_doc(MMI_SPA_SIM_ID_SIM2);
            return;
        }
        else
        {
            /* ASSERT(0); */
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_NO_SIM2);
        }
    }

    /* ASSERT(0); */
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_NEW_SETTING_RSP_LAST_ASSERT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_handle_one_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_handle_one_sim(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_result_enum ret = MMI_SPA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_HANDLE_ONE_SIM, sim_id);

    g_spa_context.sim_id = sim_id;

    /* start process EFs */
    ret = mmi_spa_ef_hdlr(g_spa_context.sim_id, mmi_spa_ef_process_callback);

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ONE_SIM_READ_HDLR_SIM2_HDLR_RET, ret);
    if (MMI_SPA_RESULT_OK == ret)
    {
        return;
    }
    switch (ret)
    {
        case MMI_SPA_RESULT_PARSE_CCA_MEM_FULL:
        case MMI_SPA_RESULT_TEMP_FAIL:
            /* Need retry again */
            mmi_spa_set_sim_read_flag(sim_id);
            mmi_spa_set_sim_read_fail_flag(sim_id);
            g_spa_context.sim2_read_retry_count++;
            break;

        case MMI_SPA_RESULT_NO_ACTIVATED_EF:    /* No file need process for SIM1, go to SIM2 */
            /* No need retry */
            mmi_spa_set_sim_read_flag(sim_id);
            mmi_spa_reset_sim_read_fail_flag(sim_id);
            break;

        default:
            /* No need retry */
            mmi_spa_set_sim_read_flag(sim_id);
            mmi_spa_reset_sim_read_fail_flag(sim_id);
            break;
    }
    mmi_spa_send_empty_cca_new_doc(sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_ef_process_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_ef_process_callback(mmi_spa_sim_ef_process_result_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 retry_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_PROCESS_CALLBACK, data);

    if (!data)
    {
        /* ASSERT(!"NULL pass to callback"); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_NO_PROCESS_CALLBACK);
        return;
    }

    MMI_TRACE(
        SPA_TRACE_INFO,
        TRC_MMI_SPA_EF_PROCESS_CALLBACK_DATA_VALUES,
        data->result,
        data->hconfig,
        g_spa_context.queue_sim_info_notify);

    if (data->result != MMI_SPA_RESULT_OK)
    {
        switch (data->result)
        {
            case MMI_SPA_RESULT_PARSE_EMPTY_ROOT:
            case MMI_SPA_RESULT_NOT_ALL_PROCESSED:
            case MMI_SPA_RESULT_PARSE_CCA_MEM_FULL:
                if (data->sim_id == MMI_SPA_SIM_ID_SIM1)
                {
                    retry_count = g_spa_context.sim1_read_retry_count;
                }
                else if (data->sim_id == MMI_SPA_SIM_ID_SIM2)
                {
                    retry_count = g_spa_context.sim2_read_retry_count;
                }

                /* If not build hconfig completely, only send it at last retry */
                if (retry_count == MMI_SPA_MAX_SIM_READ_MAX_RETRY_COUNT)
                {
                    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_PROCESS_CALLBACK_LAST_RETRY_PROCESS);
                    g_spa_context.hConfig = data->hconfig;
                }
                else
                {
                    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_PROCESS_CALLBACK_NOT_LAST_RETRY_PROCESS);
                    if (data->hconfig)
                    {
                        mmi_spa_ef_release_cca_config(data->hconfig);
                    }
                    g_spa_context.hConfig = 0;
                }

                /* Need retry again */
                mmi_spa_set_sim_read_flag(data->sim_id);
                mmi_spa_set_sim_read_fail_flag(data->sim_id);
                if (data->sim_id == MMI_SPA_SIM_ID_SIM1)
                {
                    g_spa_context.sim1_read_retry_count++;
                }
                else if (data->sim_id == MMI_SPA_SIM_ID_SIM2)
                {
                    g_spa_context.sim2_read_retry_count++;
                }
                break;

            case MMI_SPA_RESULT_FAIL_IN_FINALIZE:
                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_PROCESS_CALLBACK_FAIL_IN_FINALIZE);

                /* Need retry again */
                mmi_spa_set_sim_read_flag(data->sim_id);
                mmi_spa_set_sim_read_fail_flag(data->sim_id);

                /* Set retry count */
                if (data->sim_id == MMI_SPA_SIM_ID_SIM1)
                {
                    g_spa_context.sim1_read_retry_count++;
                }
                else if (data->sim_id == MMI_SPA_SIM_ID_SIM2)
                {
                    g_spa_context.sim2_read_retry_count++;
                }

                break;

            default:
                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_PROCESS_CALLBACK_DEFAULT_RESULT);
                /* hconifg is not sent to CCA, so release it here */
                if (data->hconfig)
                {
                    mmi_spa_ef_release_cca_config(data->hconfig);
                }
                g_spa_context.hConfig = 0;
                /* No need retry */
                mmi_spa_set_sim_read_flag(data->sim_id);
                mmi_spa_reset_sim_read_fail_flag(data->sim_id);
                break;
        }

        /* Update sim changed info */
        mmi_spa_update_sim_changed_flag();

        /* mmi_spa_send_cca_sim_prov_ind(g_spa_context.sim_flag, data->sim_id); */
        mmi_spa_send_cca_new_doc_ind(g_spa_context.sim_flag, data->sim_id, g_spa_context.hConfig);      /* Send new doc without hconfig */

        return;
    }

    /* Update sim changed info */
    mmi_spa_update_sim_changed_flag();
    /* Send new doc ind */
    mmi_spa_send_cca_new_doc_ind(g_spa_context.sim_flag, data->sim_id, data->hconfig);

    /* This SIM processed ok, so no need retry again */
    mmi_spa_set_sim_read_flag(data->sim_id);
    mmi_spa_reset_sim_read_fail_flag(data->sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_is_sim_need_to_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_spa_is_sim_need_to_read(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 read = 0;
    U8 read_fail = 1;
    U8 insert = 0;
    U8 open = 0;
    U8 retry = 0;
    U8 can_read = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U8 sim_available = 0; */

    MMI_TRACE(
        SPA_TRACE_INFO,
        TRC_MMI_SPA_IS_SIM_NEED_TO_READ,
        sim_id,
        g_spa_context.sim_flag,
        g_spa_context.sim_status,
        g_spa_context.sim_setting_mode,
        g_spa_context.sim_notified);

    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        if (!mmi_spa_is_sim_status_notified(MMI_SPA_SIM_ID_SIM1))
        {
            mmi_spa_update_sim_show_flag(sim_id, 0, 0, 0, 0);
            return MMI_FALSE;
        }

        if (g_spa_context.sim_status == MMI_SPA_SIM_ID_SIM1 || g_spa_context.sim_status == MMI_SPA_SIM_ID_DUAL_SIM)
        {
            insert = 1;
        }
        else
        {
            insert = 0;
        }

        if (g_spa_context.sim_setting_mode == MMI_SPA_SIM_ID_SIM1 ||
            g_spa_context.sim_setting_mode == MMI_SPA_SIM_ID_DUAL_SIM)
        {
            open = 1;
        }
        else
        {
            open = 0;
        }
        can_read = mmi_spa_get_sim_can_read_flag(sim_id);

        /* Determine if to show this SIM's profiles */
        mmi_spa_update_sim_show_flag(sim_id, insert, open, can_read, g_spa_context.sim1_type);

        /* Retry count */
        retry = g_spa_context.sim1_read_retry_count;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {

        if (!mmi_spa_is_sim_status_notified(MMI_SPA_SIM_ID_SIM2))
        {
            mmi_spa_update_sim_show_flag(sim_id, 0, 0, 0, 0);
            return MMI_FALSE;
        }

        if (g_spa_context.sim_status == MMI_SPA_SIM_ID_SIM2 || g_spa_context.sim_status == MMI_SPA_SIM_ID_DUAL_SIM)
        {
            insert = 1;
        }
        else
        {
            insert = 0;
        }

        if (g_spa_context.sim_setting_mode == MMI_SPA_SIM_ID_SIM2 ||
            g_spa_context.sim_setting_mode == MMI_SPA_SIM_ID_DUAL_SIM)
        {
            open = 1;
        }
        else
        {
            open = 0;
        }
        can_read = mmi_spa_get_sim_can_read_flag(sim_id);

        /* Determine if to show this SIM's profiles */
        mmi_spa_update_sim_show_flag(sim_id, insert, open, can_read, g_spa_context.sim2_type);

        retry = g_spa_context.sim2_read_retry_count;
    }

    /* Have card but can't read */
    if (!insert || !open || !can_read)
    {
        return MMI_FALSE;
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_IS_SIM_NEED_TO_READ_RETRY_COUNT, retry);

    read = mmi_spa_get_sim_read_flag(sim_id);
    read_fail = mmi_spa_get_sim_read_fail_flag(sim_id);

    /* Return that if should read this SIM */
    if ((read && !read_fail) || (read_fail && retry >= MMI_SPA_MAX_SIM_READ_MAX_RETRY_COUNT))
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_cca_new_doc_rsp_handler
 * DESCRIPTION
 *  Handle MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_RSP
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_cca_new_doc_rsp_handler(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        SPA_TRACE_INFO,
        TRC_MMI_SPA_CCA_NEW_DOC_RSP_HANDLER,
        sim_id,
        g_spa_context.sim_flag,
        g_spa_context.queue_sim_info_notify);

    mmi_spa_set_process_status(MMI_SPA_PROCESS_STATE_IDLE);
    mmi_spa_set_sim_changed_status_ok(sim_id);

    if (mmi_spa_get_notify_wait_flag())
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CCA_NEW_DOC_RSP_HANDLER_HAVE_SIM_NOTIFY);
        mmi_spa_process_next_sim_notify();
        return;
    }

    /* SIM1 process end, check SIM2 */
    if (sim_id == MMI_SPA_SIM_ID_SIM1 &&
        mmi_spa_is_sim_status_notified(MMI_SPA_SIM_ID_SIM2) && mmi_spa_is_sim_need_to_read(MMI_SPA_SIM_ID_SIM2))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CCA_NEW_DOC_RSP_HANDLER_NEED_READ);

        /* Use MMI_SPA_SIM_ID_SIM2 to indicate no need to process SIM1 */
        mmi_spa_send_cca_new_setting_ind(MMI_SPA_SIM_ID_SIM2, 0, NULL);
        mmi_spa_set_process_status(MMI_SPA_PROCESS_STATE_WAIT_SIM2_NEW_SETTING_RSP);
        return;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM1 && mmi_spa_is_sim_status_notified(MMI_SPA_SIM_ID_SIM2))
    {
        mmi_spa_send_cca_sim_profile_status_ind(MMI_SPA_SIM_ID_SIM2, g_spa_context.sim_flag);
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CCA_NEW_DOC_RSP_HANDLER_THIS_PROCEDURE_END);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_reset_sim_read_fail_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_reset_sim_read_fail_flag(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag & (~MMI_SPA_FLAG_SIM1_READ_FAIL);
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag & (~MMI_SPA_FLAG_SIM2_READ_FAIL);
    }
    else
    {
        /* ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_RESET_SIM_READ_FAIL_ERR_SIM_ID, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_sim_read_fail_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_sim_read_fail_flag(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag | MMI_SPA_FLAG_SIM1_READ_FAIL;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag | MMI_SPA_FLAG_SIM2_READ_FAIL;
    }
    else
    {
        /* ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_SET_SIM_READ_FAIL_ERR_SIM_ID, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_sim_read_fail_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_spa_get_sim_read_fail_flag(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        return (U8) ((g_spa_context.sim_flag & MMI_SPA_FLAG_SIM1_READ_FAIL) != 0);
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        return (U8) ((g_spa_context.sim_flag & MMI_SPA_FLAG_SIM2_READ_FAIL) != 0);
    }
    /* ASSERT(0); */
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_GET_SIM_READ_FAIL_ERR_SIM_ID, sim_id);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_sim_read_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_sim_read_flag(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag | MMI_SPA_FLAG_SIM1_READ;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag | MMI_SPA_FLAG_SIM2_READ;
    }
    else
    {
        /* ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_SET_SIM_READ_ERR_SIM_ID, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_sim_read_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_spa_get_sim_read_flag(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        return (U8) ((g_spa_context.sim_flag & MMI_SPA_FLAG_SIM1_READ) != 0);
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        return (U8) ((g_spa_context.sim_flag & MMI_SPA_FLAG_SIM2_READ) != 0);
    }
    /* ASSERT(0); */
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_GET_SIM_READ_ERR_SIM_ID, sim_id);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_process_status
 * DESCRIPTION
 *  CCA initialisation function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_spa_process_state_enum mmi_spa_get_process_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_spa_context.sim_process_status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_process_status
 * DESCRIPTION
 *  Set SPA process status
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_process_status(mmi_spa_process_state_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_spa_context.sim_process_status = status;
}

#endif /* MMI_SPA_JOB_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_send_empty_cca_new_doc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_send_empty_cca_new_doc(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_MMI_SPA_SEND_EMPTY_CCA_NEW_DOC, sim_id);

    mmi_spa_update_sim_changed_flag();

    mmi_spa_send_cca_new_doc_ind(g_spa_context.sim_flag, sim_id, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_update_sim_changed_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_update_sim_changed_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    smu_sim_status_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_UPDATE_SIM_CHANGED_FLAG);

    /* Is SIM changed */
#ifdef __GEMINI__

    ret = check_sim_status(SIM1);

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_UPDATE_SIM_CHANGED_FLAG_SIM1_RET, ret);

    if (ret == SMU_SIM_REPLACED)
    {
        mmi_spa_set_sim_changed_flag(MMI_SPA_SIM_ID_SIM1);
    }
    else
    {
        mmi_spa_reset_sim_changed_flag(MMI_SPA_SIM_ID_SIM1);
    }

    ret = check_sim_status(SIM2);

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_UPDATE_SIM_CHANGED_FLAG_SIM2_RET, ret);

    if (ret == SMU_SIM_REPLACED)
    {
        mmi_spa_set_sim_changed_flag(MMI_SPA_SIM_ID_SIM2);
    }
    else
    {
        mmi_spa_reset_sim_changed_flag(MMI_SPA_SIM_ID_SIM2);
    }
#else /* __GEMINI__ */ 

    ret = check_sim_status();

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_UPDATE_SIM_CHANGED_FLAG_SIM1_RET, ret);

    if (ret == SMU_SIM_REPLACED)
    {
        mmi_spa_set_sim_changed_flag(MMI_SPA_SIM_ID_SIM1);
    }
    else
    {
        mmi_spa_reset_sim_changed_flag(MMI_SPA_SIM_ID_SIM1);
    }
    /* SIM2 always not change */
    mmi_spa_reset_sim_changed_flag(MMI_SPA_SIM_ID_SIM2);
#endif /* __GEMINI__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_notify_wait_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_notify_wait_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_spa_context.queue_sim_info_notify = 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_reset_notify_wait_flag
 * DESCRIPTION
 *  CCA initialisation function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_reset_notify_wait_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_spa_context.queue_sim_info_notify = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_notify_wait_flag
 * DESCRIPTION
 *  CCA initialisation function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_spa_get_notify_wait_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_spa_context.queue_sim_info_notify;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_sim_can_read_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_spa_get_sim_can_read_flag(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        return ((g_spa_context.sim_flag & MMI_SPA_FLAG_SIM1_CAN_READ) != 0);
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        return ((g_spa_context.sim_flag & MMI_SPA_FLAG_SIM2_CAN_READ) != 0);
    }
    /* ASSERT(0); */
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_GET_SIM_CAN_READ_ERR_SIM_ID, sim_id);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_sim_can_read_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_sim_can_read_flag(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag | MMI_SPA_FLAG_SIM1_CAN_READ;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag | MMI_SPA_FLAG_SIM2_CAN_READ;
    }
    else
    {
        /* ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_SET_SIM_CAN_READ_ERR_SIM_ID, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_reset_sim_can_read_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_reset_sim_can_read_flag(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag & (~MMI_SPA_FLAG_SIM1_CAN_READ);
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag & (~MMI_SPA_FLAG_SIM2_CAN_READ);
    }
    else
    {
        /* ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_RESET_SIM_CAN_READ_ERR_SIM_ID, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_sim_profile_show_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_sim_profile_show_flag(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag | MMI_SPA_FLAG_SIM1_SHOW;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag | MMI_SPA_FLAG_SIM2_SHOW;
    }
    else
    {
        /* ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_SET_SIM_SHOW_ERR_SIM_ID, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_reset_sim_profile_show_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_reset_sim_profile_show_flag(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag & (~MMI_SPA_FLAG_SIM1_SHOW);
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag & (~MMI_SPA_FLAG_SIM2_SHOW);
    }
    else
    {
        /* ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_RESET_SIM_SHOW_ERR_SIM_ID, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_sim_changed_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_sim_changed_flag(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag | MMI_SPA_FLAG_SIM1_CHANGED;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag | MMI_SPA_FLAG_SIM2_CHANGED;
    }
    else
    {
        /* ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_SET_SIM_CHANGED_ERR_SIM_ID, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_reset_sim_changed_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_reset_sim_changed_flag(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag & (~MMI_SPA_FLAG_SIM1_CHANGED);
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        g_spa_context.sim_flag = g_spa_context.sim_flag & (~MMI_SPA_FLAG_SIM2_CHANGED);
    }
    else
    {
        /* ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_RESET_SIM_CHANGED_ERR_SIM_ID, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_update_sim_show_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  insert          [IN]        
 *  open            [IN]        
 *  can_read        [IN]        
 *  sim_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_update_sim_show_flag(mmi_spa_sim_id_enum sim_id, U8 insert, U8 open, U8 can_read, U8 sim_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!insert || !open || !can_read ||
        (sim_type != MMI_SPA_SIM_TYPE_VALID_SIM && sim_type != MMI_SPA_SIM_TYPE_INVALID_SIM))
    {
        mmi_spa_reset_sim_profile_show_flag(sim_id);
    }
    else
    {
        mmi_spa_set_sim_profile_show_flag(sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_update_all_sim_show_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  insert              [IN]        
 *  setting_mode        [IN]        
 *  sim1_can_read       [IN]        
 *  sim2_can_read       [IN]        
 *  sim1_type           [IN]        
 *  sim2_type           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_update_all_sim_show_flag(
                U8 insert,
                U8 setting_mode,
                U8 sim1_can_read,
                U8 sim2_can_read,
                U8 sim1_type,
                U8 sim2_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 open = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* SIM1 */
    if (insert == MMI_SPA_SIM_ID_SIM1 || insert == MMI_SPA_SIM_ID_DUAL_SIM)
    {
        if (setting_mode == MMI_SPA_SIM_ID_SIM1 || setting_mode == MMI_SPA_SIM_ID_DUAL_SIM)
        {
            open = 1;
        }
        else
        {
            open = 0;
        }

        /* Determine if to show this SIM's profiles */
        mmi_spa_update_sim_show_flag(MMI_SPA_SIM_ID_SIM1, MMI_TRUE, open, sim1_can_read, sim1_type);
    }
    else
    {
        mmi_spa_reset_sim_profile_show_flag(MMI_SPA_SIM_ID_SIM1);
    }

    /* SIM2 */
    if (insert == MMI_SPA_SIM_ID_SIM2 || insert == MMI_SPA_SIM_ID_DUAL_SIM)
    {
        if (setting_mode == MMI_SPA_SIM_ID_SIM2 || setting_mode == MMI_SPA_SIM_ID_DUAL_SIM)
        {
            open = 1;
        }
        else
        {
            open = 0;
        }

        /* Determine if to show this SIM's profiles */
        mmi_spa_update_sim_show_flag(MMI_SPA_SIM_ID_SIM2, MMI_TRUE, open, sim2_can_read, sim2_type);
    }
    else
    {
        mmi_spa_reset_sim_profile_show_flag(MMI_SPA_SIM_ID_SIM2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_is_cca_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_spa_is_cca_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)g_spa_context.cca_ready;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_is_sim_status_notified
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_spa_is_sim_status_notified(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {
        case MMI_SPA_SIM_ID_SIM1:
            if (g_spa_context.sim_notified == MMI_SPA_SIM_ID_SIM1 ||
                g_spa_context.sim_notified == MMI_SPA_SIM_ID_DUAL_SIM)
            {
                return MMI_TRUE;
            }
            return MMI_FALSE;

        case MMI_SPA_SIM_ID_SIM2:
            if (g_spa_context.sim_notified == MMI_SPA_SIM_ID_SIM2 ||
                g_spa_context.sim_notified == MMI_SPA_SIM_ID_DUAL_SIM)
            {
                return MMI_TRUE;
            }
            return MMI_FALSE;

        default:
            /* ASSERT(0); */
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_IS_SIM_NOTIFIED_ERR_SIM_ID, sim_id);
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_sim_status_notified
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_sim_status_notified(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SET_SIM_STATUS_NOTIFIED, g_spa_context.sim_notified);

    switch (g_spa_context.sim_notified)
    {
        case MMI_SPA_SIM_ID_NO_SIM:
            g_spa_context.sim_notified = sim_id;
            break;

        case MMI_SPA_SIM_ID_SIM1:
            if (sim_id == MMI_SPA_SIM_ID_SIM2 || sim_id == MMI_SPA_SIM_ID_DUAL_SIM)
            {
                g_spa_context.sim_notified = MMI_SPA_SIM_ID_DUAL_SIM;
            }
            break;

        case MMI_SPA_SIM_ID_SIM2:
            if (sim_id == MMI_SPA_SIM_ID_SIM1 || sim_id == MMI_SPA_SIM_ID_DUAL_SIM)
            {
                g_spa_context.sim_notified = MMI_SPA_SIM_ID_DUAL_SIM;
            }
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_sim_status_notified
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_spa_sim_id_enum mmi_spa_get_sim_status_notified(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_spa_context.sim_notified;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_read_nvram_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_read_nvram_data(mmi_spa_sim_changed_data *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 err = 0;
    U16 last_flags;
    U16 cur_flags;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_READ_NVRAM_DATA);

    if (data->read)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_READ_NVRAM_DATA_HAVE_READ);
        return;
    }

    data->read = 1;

    /* Read NVRAM */
    ReadValue(NVRAM_SPA_LAST_SIM_STATUS, &last_flags, DS_SHORT, &err);
    if (err != NVRAM_READ_SUCCESS)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_READ_NVRAM_DATA_LAST_ERR);
        last_flags = 0xFFFF;
    }
    ReadValue(NVRAM_SPA_CUR_SIM_STATUS, &cur_flags, DS_SHORT, &err);
    if (err != NVRAM_READ_SUCCESS)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_READ_NVRAM_DATA_CUR_ERR);
        cur_flags = 0xFFFF;
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_READ_NVRAM_DATA_READ_RESULT, last_flags, cur_flags);

    data->sim_last_flags = last_flags;
    data->sim_cur_flags = cur_flags;

    /* Set values */
    if (last_flags == 0xFFFF)
    {
        data->sim1_last_insert = 0xFF;
        data->sim1_last_status = 0xFF;
        data->sim2_last_insert = 0xFF;
        data->sim2_last_status = 0xFF;
        data->sim1_last_ok = 1;
        data->sim2_last_ok = 1;
    }
    else
    {
        /* sim1 last insert */
        if (last_flags & MMI_SPA_FLAG_SIM1_INSERT_NOT_INSERT)
        {
            data->sim1_last_insert = MMI_SPA_SIM_CHANGED_STATUS_NOT_INSERT;
        }
        else if (last_flags & MMI_SPA_FLAG_SIM1_INSERT_BLOCK)
        {
            data->sim1_last_insert = MMI_SPA_SIM_CHANGED_STATUS_INSERT_BLOCKED;
        }
        else
        {
            data->sim1_last_insert = MMI_SPA_SIM_CHANGED_STATUS_INSERT_NORMAL;
        }

        /* sim1 last change */
        if (last_flags & MMI_SPA_FLAG_SIM1_CHANGE_NO_IMSI)
        {
            data->sim1_last_status = MMI_SPA_SIM_CHANGED_STATUS_INSERT_NO_IMSI;
        }
        else if (last_flags & MMI_SPA_FLAG_SIM1_CHANGE_NOT_CHANGED)
        {
            data->sim1_last_status = MMI_SPA_SIM_CHANGED_STATUS_NOT_CHANGED;
        }
        else
        {
            data->sim1_last_status = MMI_SPA_SIM_CHANGED_STATUS_CHANGED;
        }

        /* sim2 last insert */
        if (last_flags & MMI_SPA_FLAG_SIM2_INSERT_NOT_INSERT)
        {
            data->sim2_last_insert = MMI_SPA_SIM_CHANGED_STATUS_NOT_INSERT;
        }
        else if (last_flags & MMI_SPA_FLAG_SIM2_INSERT_BLOCK)
        {
            data->sim2_last_insert = MMI_SPA_SIM_CHANGED_STATUS_INSERT_BLOCKED;
        }
        else
        {
            data->sim2_last_insert = MMI_SPA_SIM_CHANGED_STATUS_INSERT_NORMAL;
        }

        /* sim2 last change */
        if (last_flags & MMI_SPA_FLAG_SIM2_CHANGE_NO_IMSI)
        {
            data->sim2_last_status = MMI_SPA_SIM_CHANGED_STATUS_INSERT_NO_IMSI;
        }
        else if (last_flags & MMI_SPA_FLAG_SIM2_CHANGE_NOT_CHANGED)
        {
            data->sim2_last_status = MMI_SPA_SIM_CHANGED_STATUS_NOT_CHANGED;
        }
        else
        {
            data->sim2_last_status = MMI_SPA_SIM_CHANGED_STATUS_CHANGED;
        }
    }

    if (cur_flags == 0xFFFF)
    {
        data->sim1_cur_insert = 0xFF;
        data->sim1_cur_status = 0xFF;
        data->sim2_cur_insert = 0xFF;
        data->sim2_cur_status = 0xFF;
    }
    else
    {
        /* sim1 last insert */
        if (cur_flags & MMI_SPA_FLAG_SIM1_INSERT_NOT_INSERT)
        {
            data->sim1_cur_insert = MMI_SPA_SIM_CHANGED_STATUS_NOT_INSERT;
        }
        else if (cur_flags & MMI_SPA_FLAG_SIM1_INSERT_BLOCK)
        {
            data->sim1_cur_insert = MMI_SPA_SIM_CHANGED_STATUS_INSERT_BLOCKED;
        }
        else
        {
            data->sim1_cur_insert = MMI_SPA_SIM_CHANGED_STATUS_INSERT_NORMAL;
        }

        /* sim1 last change */
        if (cur_flags & MMI_SPA_FLAG_SIM1_CHANGE_NO_IMSI)
        {
            data->sim1_cur_status = MMI_SPA_SIM_CHANGED_STATUS_INSERT_NO_IMSI;
        }
        else if (cur_flags & MMI_SPA_FLAG_SIM1_CHANGE_NOT_CHANGED)
        {
            data->sim1_cur_status = MMI_SPA_SIM_CHANGED_STATUS_NOT_CHANGED;
        }
        else
        {
            data->sim1_cur_status = MMI_SPA_SIM_CHANGED_STATUS_CHANGED;
        }

        /* sim2 last insert */
        if (cur_flags & MMI_SPA_FLAG_SIM2_INSERT_NOT_INSERT)
        {
            data->sim2_cur_insert = MMI_SPA_SIM_CHANGED_STATUS_NOT_INSERT;
        }
        else if (cur_flags & MMI_SPA_FLAG_SIM2_INSERT_BLOCK)
        {
            data->sim2_cur_insert = MMI_SPA_SIM_CHANGED_STATUS_INSERT_BLOCKED;
        }
        else
        {
            data->sim2_cur_insert = MMI_SPA_SIM_CHANGED_STATUS_INSERT_NORMAL;
        }

        /* sim2 last change */
        if (cur_flags & MMI_SPA_FLAG_SIM2_CHANGE_NO_IMSI)
        {
            data->sim2_cur_status = MMI_SPA_SIM_CHANGED_STATUS_INSERT_NO_IMSI;
        }
        else if (cur_flags & MMI_SPA_FLAG_SIM2_CHANGE_NOT_CHANGED)
        {
            data->sim2_cur_status = MMI_SPA_SIM_CHANGED_STATUS_NOT_CHANGED;
        }
        else
        {
            data->sim2_cur_status = MMI_SPA_SIM_CHANGED_STATUS_CHANGED;
        }

        /* */
        if (cur_flags & MMI_SPA_FLAG_LAST_SIM1_STATUS_OK)
        {
            data->sim1_last_ok = 1;
        }
        if (cur_flags & MMI_SPA_FLAG_LAST_SIM2_STATUS_OK)
        {
            data->sim2_last_ok = 1;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_write_nvram_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_write_nvram_data(mmi_spa_sim_id_enum sim_id, mmi_spa_sim_changed_data *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 err = 0;
    U16 last_flags = 0x0000;
    U16 cur_flags = 0x0000;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_WRITE_NVRAM_DATA, sim_id);

    /* last values */
    if ((sim_id == MMI_SPA_SIM_ID_SIM1 || sim_id == MMI_SPA_SIM_ID_DUAL_SIM) && data->sim1_ok)
    {
        MMI_TRACE(
            SPA_TRACE_INFO,
            TRC_MMI_SPA_WRITE_NVRAM_DATA_SIM1_OK_LAST,
            data->sim1_last_insert,
            data->sim1_last_status);

        switch (data->sim1_last_insert)
        {
            case MMI_SPA_SIM_CHANGED_STATUS_NOT_INSERT:
                last_flags |= MMI_SPA_FLAG_SIM1_INSERT_NOT_INSERT;
                break;

            case MMI_SPA_SIM_CHANGED_STATUS_INSERT_BLOCKED:
                last_flags |= MMI_SPA_FLAG_SIM1_INSERT_BLOCK;
                break;

            case MMI_SPA_SIM_CHANGED_STATUS_INSERT_NORMAL:
            default:
                last_flags |= MMI_SPA_FLAG_SIM1_INSERT_OK;
                break;
        }

        switch (data->sim1_last_status)
        {
            case MMI_SPA_SIM_CHANGED_STATUS_INSERT_NO_IMSI:
                last_flags |= MMI_SPA_FLAG_SIM1_CHANGE_NO_IMSI;
                break;

            case MMI_SPA_SIM_CHANGED_STATUS_NOT_CHANGED:
                last_flags |= MMI_SPA_FLAG_SIM1_CHANGE_NOT_CHANGED;
                break;

            case MMI_SPA_SIM_CHANGED_STATUS_CHANGED:
            default:
                last_flags |= MMI_SPA_FLAG_SIM1_CHANGE_CHANGED;
                break;
        }
    }
    if ((sim_id == MMI_SPA_SIM_ID_SIM2 || sim_id == MMI_SPA_SIM_ID_DUAL_SIM) && data->sim2_ok)
    {
        MMI_TRACE(
            SPA_TRACE_INFO,
            TRC_MMI_SPA_WRITE_NVRAM_DATA_SIM2_OK_LAST,
            data->sim2_last_insert,
            data->sim2_last_status);

        switch (data->sim2_last_insert)
        {
            case MMI_SPA_SIM_CHANGED_STATUS_NOT_INSERT:
                last_flags |= MMI_SPA_FLAG_SIM2_INSERT_NOT_INSERT;
                break;

            case MMI_SPA_SIM_CHANGED_STATUS_INSERT_BLOCKED:
                last_flags |= MMI_SPA_FLAG_SIM2_INSERT_BLOCK;
                break;

            case MMI_SPA_SIM_CHANGED_STATUS_INSERT_NORMAL:
            default:
                last_flags |= MMI_SPA_FLAG_SIM2_INSERT_OK;
                break;
        }

        switch (data->sim2_last_status)
        {
            case MMI_SPA_SIM_CHANGED_STATUS_INSERT_NO_IMSI:
                last_flags |= MMI_SPA_FLAG_SIM2_CHANGE_NO_IMSI;
                break;

            case MMI_SPA_SIM_CHANGED_STATUS_NOT_CHANGED:
                last_flags |= MMI_SPA_FLAG_SIM2_CHANGE_NOT_CHANGED;
                break;

            case MMI_SPA_SIM_CHANGED_STATUS_CHANGED:
            default:
                last_flags |= MMI_SPA_FLAG_SIM2_CHANGE_CHANGED;
                break;
        }
    }   /* if (data->sim2_ok) */

    if ((sim_id == MMI_SPA_SIM_ID_SIM1 || sim_id == MMI_SPA_SIM_ID_DUAL_SIM) && data->sim1_ok)
    {
        data->sim_last_flags &= ~MMI_SPA_MASK_SIM1_FLAGS;
        data->sim_last_flags |= last_flags & MMI_SPA_MASK_SIM1_FLAGS;
        /* data->sim_last_flags |= MMI_SPA_FLAG_LAST_SIM1_STATUS_OK; */
    }

    if ((sim_id == MMI_SPA_SIM_ID_SIM2 || sim_id == MMI_SPA_SIM_ID_DUAL_SIM) && data->sim2_ok)
    {
        data->sim_last_flags &= ~MMI_SPA_MASK_SIM2_FLAGS;
        data->sim_last_flags |= last_flags & MMI_SPA_MASK_SIM2_FLAGS;
        /* last_flags |= MMI_SPA_FLAG_LAST_SIM1_STATUS_OK; */
    }

    if ((sim_id == MMI_SPA_SIM_ID_SIM1 || sim_id == MMI_SPA_SIM_ID_DUAL_SIM))
    {
        MMI_TRACE(
            SPA_TRACE_INFO,
            TRC_MMI_SPA_WRITE_NVRAM_DATA_SIM1_OK_CUR,
            data->sim1_cur_insert,
            data->sim1_cur_status);

        /* cur values */
        switch (data->sim1_cur_insert)
        {
            case MMI_SPA_SIM_CHANGED_STATUS_NOT_INSERT:
                cur_flags |= MMI_SPA_FLAG_SIM1_INSERT_NOT_INSERT;
                break;

            case MMI_SPA_SIM_CHANGED_STATUS_INSERT_BLOCKED:
                cur_flags |= MMI_SPA_FLAG_SIM1_INSERT_BLOCK;
                break;

            case MMI_SPA_SIM_CHANGED_STATUS_INSERT_NORMAL:
            default:
                cur_flags |= MMI_SPA_FLAG_SIM1_INSERT_OK;
                break;
        }

        switch (data->sim1_cur_status)
        {
            case MMI_SPA_SIM_CHANGED_STATUS_INSERT_NO_IMSI:
                cur_flags |= MMI_SPA_FLAG_SIM1_CHANGE_NO_IMSI;
                break;

            case MMI_SPA_SIM_CHANGED_STATUS_NOT_CHANGED:
                cur_flags |= MMI_SPA_FLAG_SIM1_CHANGE_NOT_CHANGED;
                break;

            case MMI_SPA_SIM_CHANGED_STATUS_CHANGED:
            default:
                cur_flags |= MMI_SPA_FLAG_SIM1_CHANGE_CHANGED;
                break;
        }
        if (!data->sim1_ok)
        {
            if ((sim_id == MMI_SPA_SIM_ID_SIM1 || sim_id == MMI_SPA_SIM_ID_DUAL_SIM))
            {
                data->sim_cur_flags &= ~MMI_SPA_MASK_SIM1_FLAGS;
                data->sim_cur_flags |= cur_flags & MMI_SPA_MASK_SIM1_FLAGS;
            }
            data->sim_cur_flags &= ~MMI_SPA_FLAG_LAST_SIM1_STATUS_OK;
        }
        else
        {
            data->sim_cur_flags &= ~MMI_SPA_MASK_SIM1_FLAGS;
            data->sim_cur_flags |= cur_flags & MMI_SPA_MASK_SIM1_FLAGS;
            data->sim_cur_flags |= MMI_SPA_FLAG_LAST_SIM1_STATUS_OK;
        }
    }

    if ((sim_id == MMI_SPA_SIM_ID_SIM2 || sim_id == MMI_SPA_SIM_ID_DUAL_SIM))
    {
        MMI_TRACE(
            SPA_TRACE_INFO,
            TRC_MMI_SPA_WRITE_NVRAM_DATA_SIM2_OK_CUR,
            data->sim2_cur_insert,
            data->sim2_cur_status);

        switch (data->sim2_cur_insert)
        {
            case MMI_SPA_SIM_CHANGED_STATUS_NOT_INSERT:
                cur_flags |= MMI_SPA_FLAG_SIM2_INSERT_NOT_INSERT;
                break;

            case MMI_SPA_SIM_CHANGED_STATUS_INSERT_BLOCKED:
                cur_flags |= MMI_SPA_FLAG_SIM2_INSERT_BLOCK;
                break;

            case MMI_SPA_SIM_CHANGED_STATUS_INSERT_NORMAL:
            default:
                cur_flags |= MMI_SPA_FLAG_SIM2_INSERT_OK;
                break;
        }

        switch (data->sim2_cur_status)
        {
            case MMI_SPA_SIM_CHANGED_STATUS_INSERT_NO_IMSI:
                cur_flags |= MMI_SPA_FLAG_SIM2_CHANGE_NO_IMSI;
                break;

            case MMI_SPA_SIM_CHANGED_STATUS_NOT_CHANGED:
                cur_flags |= MMI_SPA_FLAG_SIM2_CHANGE_NOT_CHANGED;
                break;

            case MMI_SPA_SIM_CHANGED_STATUS_CHANGED:
            default:
                cur_flags |= MMI_SPA_FLAG_SIM2_CHANGE_CHANGED;
                break;
        }
        if (!data->sim2_ok)
        {
            if ((sim_id == MMI_SPA_SIM_ID_SIM2 || sim_id == MMI_SPA_SIM_ID_DUAL_SIM))
            {
                data->sim_cur_flags &= ~MMI_SPA_MASK_SIM2_FLAGS;
                data->sim_cur_flags |= cur_flags & MMI_SPA_MASK_SIM2_FLAGS;
            }
            data->sim_cur_flags &= ~MMI_SPA_FLAG_LAST_SIM2_STATUS_OK;
        }
        else
        {
            data->sim_cur_flags &= ~MMI_SPA_MASK_SIM2_FLAGS;
            data->sim_cur_flags |= cur_flags & MMI_SPA_MASK_SIM2_FLAGS;
            data->sim_cur_flags |= MMI_SPA_FLAG_LAST_SIM2_STATUS_OK;
        }
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_WRITE_NVRAM_DATA_WRITE, data->sim_last_flags, data->sim_cur_flags);

    /* Write NVRAM */
    WriteValue(NVRAM_SPA_LAST_SIM_STATUS, &data->sim_last_flags, DS_SHORT, &err);
    WriteValue(NVRAM_SPA_CUR_SIM_STATUS, &data->sim_cur_flags, DS_SHORT, &err);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_sim_changed_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_sim_changed_status(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_sim_changed_status cur_insert;
    mmi_spa_sim_changed_status cur_changed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SET_SIM_CHANGED_STATUS, sim_id);

    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        g_spa_context.sim_changed_data.sim1_ok = 0;

        cur_insert = mmi_spa_get_sim_cur_insert_status(sim_id);
        cur_changed = mmi_spa_get_sim_cur_changed_status(sim_id);

        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SET_SIM_CHANGED_STATUS_CUR_STATUS, cur_insert, cur_changed);

        /* First bootup */
        if (g_spa_context.sim_changed_data.sim1_last_insert == 0xFF)
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SET_SIM_CHANGED_STATUS_FIRST_BOOTUP);

            g_spa_context.sim_changed_data.sim1_changed = 1;
            g_spa_context.sim_changed_data.sim1_cur_insert = cur_insert;
            g_spa_context.sim_changed_data.sim1_cur_status = cur_changed;
            return;
        }

        /* Use saved status */
        if (cur_changed != MMI_SPA_SIM_CHANGED_STATUS_CHANGED && !g_spa_context.sim_changed_data.sim1_last_ok)
        {
            MMI_TRACE(
                SPA_TRACE_INFO,
                TRC_MMI_SPA_SET_SIM_CHANGED_STATUS_USE_SAVED,
                g_spa_context.sim_changed_data.sim1_cur_insert,
                g_spa_context.sim_changed_data.sim1_cur_status);

            cur_insert = (mmi_spa_sim_changed_status)g_spa_context.sim_changed_data.sim1_cur_insert;
            cur_changed = (mmi_spa_sim_changed_status)g_spa_context.sim_changed_data.sim1_cur_status;
        }
        else
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SET_SIM_CHANGED_STATUS_USE_CUR);

            g_spa_context.sim_changed_data.sim1_cur_insert = cur_insert;
            g_spa_context.sim_changed_data.sim1_cur_status = cur_changed;
        }

        /* Blocked or not insert */
        if (cur_insert == MMI_SPA_SIM_CHANGED_STATUS_NOT_INSERT ||
            cur_insert == MMI_SPA_SIM_CHANGED_STATUS_INSERT_BLOCKED)
        {
            if (g_spa_context.sim_changed_data.sim1_last_insert == MMI_SPA_SIM_CHANGED_STATUS_INSERT_BLOCKED ||
                g_spa_context.sim_changed_data.sim1_last_insert == MMI_SPA_SIM_CHANGED_STATUS_NOT_INSERT)
            {
                g_spa_context.sim_changed_data.sim1_changed = 0;
                return;
            }
            g_spa_context.sim_changed_data.sim1_changed = 1;
            return;
        }

        /* No imsi */
        if (cur_changed == MMI_SPA_SIM_CHANGED_STATUS_INSERT_NO_IMSI)
        {
            if (g_spa_context.sim_changed_data.sim1_last_status == MMI_SPA_SIM_CHANGED_STATUS_INSERT_NO_IMSI &&
                g_spa_context.sim_changed_data.sim1_last_insert == MMI_SPA_SIM_CHANGED_STATUS_INSERT_NORMAL)
            {
                g_spa_context.sim_changed_data.sim1_changed = 0;
                return;
            }
            g_spa_context.sim_changed_data.sim1_changed = 1;
            return;
        }

        /* */
        if (g_spa_context.sim_changed_data.sim1_last_insert == MMI_SPA_SIM_CHANGED_STATUS_INSERT_NORMAL &&
            cur_insert == MMI_SPA_SIM_CHANGED_STATUS_INSERT_NORMAL &&
            g_spa_context.sim_changed_data.sim1_last_status != MMI_SPA_SIM_CHANGED_STATUS_INSERT_NO_IMSI)
        {
            if (cur_changed == MMI_SPA_SIM_CHANGED_STATUS_CHANGED)
            {
                g_spa_context.sim_changed_data.sim1_changed = 1;
                return;
            }
            g_spa_context.sim_changed_data.sim1_changed = 0;
            return;
        }
        g_spa_context.sim_changed_data.sim1_changed = 1;
        return;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        g_spa_context.sim_changed_data.sim2_ok = 0;

        cur_insert = mmi_spa_get_sim_cur_insert_status(sim_id);
        cur_changed = mmi_spa_get_sim_cur_changed_status(sim_id);

        /* First bootup */
        if (g_spa_context.sim_changed_data.sim2_last_insert == 0xFF)
        {
            g_spa_context.sim_changed_data.sim2_changed = 1;
            g_spa_context.sim_changed_data.sim2_cur_insert = cur_insert;
            g_spa_context.sim_changed_data.sim2_cur_status = cur_changed;
            return;
        }

        /* Use saved status */
        if (cur_changed != MMI_SPA_SIM_CHANGED_STATUS_CHANGED && !g_spa_context.sim_changed_data.sim2_last_ok)
        {
            cur_insert = (mmi_spa_sim_changed_status)g_spa_context.sim_changed_data.sim2_cur_insert;
            cur_changed = (mmi_spa_sim_changed_status)g_spa_context.sim_changed_data.sim2_cur_status;
        }
        else
        {
            g_spa_context.sim_changed_data.sim2_cur_insert = cur_insert;
            g_spa_context.sim_changed_data.sim2_cur_status = cur_changed;
        }

        /* Blocked or not insert */
        if (cur_insert == MMI_SPA_SIM_CHANGED_STATUS_NOT_INSERT ||
            cur_insert == MMI_SPA_SIM_CHANGED_STATUS_INSERT_BLOCKED)
        {
            if (g_spa_context.sim_changed_data.sim2_last_insert == MMI_SPA_SIM_CHANGED_STATUS_INSERT_BLOCKED ||
                g_spa_context.sim_changed_data.sim2_last_insert == MMI_SPA_SIM_CHANGED_STATUS_NOT_INSERT)
            {
                g_spa_context.sim_changed_data.sim2_changed = 0;
                return;
            }
            g_spa_context.sim_changed_data.sim2_changed = 1;
            return;
        }

        /* No imsi */
        if (cur_changed == MMI_SPA_SIM_CHANGED_STATUS_INSERT_NO_IMSI)
        {
            if (g_spa_context.sim_changed_data.sim2_last_status == MMI_SPA_SIM_CHANGED_STATUS_INSERT_NO_IMSI &&
                g_spa_context.sim_changed_data.sim2_last_insert == MMI_SPA_SIM_CHANGED_STATUS_INSERT_NORMAL)
            {
                g_spa_context.sim_changed_data.sim2_changed = 0;
                return;
            }
            g_spa_context.sim_changed_data.sim2_changed = 1;
            return;
        }

        /* */
        if (g_spa_context.sim_changed_data.sim2_last_insert == MMI_SPA_SIM_CHANGED_STATUS_INSERT_NORMAL &&
            cur_insert == MMI_SPA_SIM_CHANGED_STATUS_INSERT_NORMAL &&
            g_spa_context.sim_changed_data.sim2_last_status != MMI_SPA_SIM_CHANGED_STATUS_INSERT_NO_IMSI)
        {
            if (cur_changed == MMI_SPA_SIM_CHANGED_STATUS_CHANGED)
            {
                g_spa_context.sim_changed_data.sim2_changed = 1;
                return;
            }
            g_spa_context.sim_changed_data.sim2_changed = 0;
            return;
        }
        g_spa_context.sim_changed_data.sim2_changed = 1;
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_sim_write_back_new_sim_changed_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_sim_write_back_new_sim_changed_status(mmi_spa_sim_id_enum sim_id, mmi_spa_sim_changed_data *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SIM_WRITE_BACK_NEW_SIM_CHANGED_STATUS, sim_id, data->sim1_ok, data->sim2_ok);

    if ((sim_id == MMI_SPA_SIM_ID_SIM1 || sim_id == MMI_SPA_SIM_ID_DUAL_SIM) && data->sim1_ok)
    {
        data->sim1_last_insert = data->sim1_cur_insert;
        data->sim1_last_status = data->sim1_cur_status;
        //data->sim1_cur_insert = 0;
        //data->sim1_cur_status = 0;
    }
    if ((sim_id == MMI_SPA_SIM_ID_SIM2 || sim_id == MMI_SPA_SIM_ID_DUAL_SIM) && data->sim2_ok)
    {
        data->sim2_last_insert = data->sim2_cur_insert;
        data->sim2_last_status = data->sim2_cur_status;
        //data->sim2_cur_insert = 0;
        //data->sim2_cur_status = 0;
    }
    mmi_spa_write_nvram_data(sim_id, data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_sim_changed_status_ok
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_set_sim_changed_status_ok(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SET_SIM_CHANGED_STATUS_OK, sim_id);

    switch (sim_id)
    {
        case MMI_SPA_SIM_ID_SIM1:
            g_spa_context.sim_changed_data.sim1_ok = 1;
            mmi_spa_sim_write_back_new_sim_changed_status(MMI_SPA_SIM_ID_SIM1, &g_spa_context.sim_changed_data);
            break;

        case MMI_SPA_SIM_ID_SIM2:
            g_spa_context.sim_changed_data.sim2_ok = 1;
            mmi_spa_sim_write_back_new_sim_changed_status(MMI_SPA_SIM_ID_SIM2, &g_spa_context.sim_changed_data);
            break;

        case MMI_SPA_SIM_ID_DUAL_SIM:
            g_spa_context.sim_changed_data.sim1_ok = 1;
            g_spa_context.sim_changed_data.sim2_ok = 1;
            mmi_spa_sim_write_back_new_sim_changed_status(MMI_SPA_SIM_ID_DUAL_SIM, &g_spa_context.sim_changed_data);
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_sim_cur_insert_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_spa_sim_changed_status mmi_spa_get_sim_cur_insert_status(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        if (g_spa_context.sim_status != MMI_SPA_SIM_ID_SIM1 && g_spa_context.sim_status != MMI_SPA_SIM_ID_DUAL_SIM)
        {
            return MMI_SPA_SIM_CHANGED_STATUS_NOT_INSERT;
        }
        else if (g_spa_context.sim1_type == MMI_SPA_SIM_TYPE_BLOCKED_SIM)
        {
            return MMI_SPA_SIM_CHANGED_STATUS_INSERT_BLOCKED;
        }
        else
        {
            return MMI_SPA_SIM_CHANGED_STATUS_INSERT_NORMAL;
        }
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        if (g_spa_context.sim_status != MMI_SPA_SIM_ID_SIM2 && g_spa_context.sim_status != MMI_SPA_SIM_ID_DUAL_SIM)
        {
            return MMI_SPA_SIM_CHANGED_STATUS_NOT_INSERT;
        }
        else if (g_spa_context.sim2_type == MMI_SPA_SIM_TYPE_BLOCKED_SIM)
        {
            return MMI_SPA_SIM_CHANGED_STATUS_INSERT_BLOCKED;
        }
        else
        {
            return MMI_SPA_SIM_CHANGED_STATUS_INSERT_NORMAL;
        }
    }
    /* ASSERT(0); */
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_GET_SIM_CUR_INSERT_STATUS_ERR_SIM_ID, sim_id);
    return MMI_SPA_SIM_CHANGED_STATUS_NOT_INSERT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_sim_cur_changed_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_spa_sim_changed_status mmi_spa_get_sim_cur_changed_status(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __GEMINI__
    U8 sim;
#endif 
    smu_sim_status_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GEMINI__
    if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        sim = SIM2;
    }
    else
    {
        sim = SIM1;
    }
    ret = check_sim_status(sim);
#else /* __GEMINI__ */ 
    ret = check_sim_status();
#endif /* __GEMINI__ */ 

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_GET_SIM_CUR_CHANGED_STATUS, sim_id, ret);

    switch (ret)
    {
        case SMU_SIM_NO_IMSI:
            return MMI_SPA_SIM_CHANGED_STATUS_INSERT_NO_IMSI;

        case SMU_SIM_REPLACED:
            return MMI_SPA_SIM_CHANGED_STATUS_CHANGED;

        default:
            return MMI_SPA_SIM_CHANGED_STATUS_NOT_CHANGED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_is_sim_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_spa_is_sim_changed(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        return (MMI_BOOL)g_spa_context.sim_changed_data.sim1_changed;
    }
    else
    {
        return (MMI_BOOL)g_spa_context.sim_changed_data.sim2_changed;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_inject_string_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  str         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_inject_string_hdlr(U8 index, U8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef SPA_EF_TEST
    mmi_spa_ef_tst_inject_string_hdlr(index, str);
#endif 
}

#ifdef SPA_EF_TEST
#include "tst_sap.h"
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
//#include "mmi_rp_app_provboxui_def.h"
#endif

#define EF_TEST_IDX_CLEAR_FLAGS     70
#define EF_TEST_SET_SIM1_FILE       71
#define EF_TEST_SET_SIM2_FILE       72
#define EF_TEST_RESET_NVRAM_VALUES  73
#define EF_TEST_SET_TEST_CODE_ON    74
#define EF_TEST_SET_TEST_CODE_OFF   75
#define EF_TEST_POPUP_SCREEN        76

extern U8 EntryNewScreen(U16 newscrnID, FuncPtr newExitHandler, FuncPtr newEntryHandler, void *flag);
extern void ShowCategory65Screen(U8 *message, U16 message_icon, U8 *history_buffer);

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
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_test_set_list_item_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provboxui_test_set_list_item_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *name = NULL;
    S32 name_len;
    U16 temp[50] = {0, };
    U16 dest[MAX_SUBMENU_CHARACTERS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        /* List item */
        name = (S8*) temp;

        /* copy name */
        name_len = mmi_ucs2strlen(name);
        if (name_len < (MAX_SUBMENU_CHARACTERS - 1))
        {
            mmi_ucs2cpy((S8*) dest, name);
        }
        else
        {
            mmi_ucs2ncpy((S8*) dest, (const S8*)name, (MAX_SUBMENU_CHARACTERS - 1));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_ef_tst_inject_string_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  str         [IN]        
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_ef_tst_inject_string_hdlr(U8 index, U8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_TEST_TST_INJECT_STRING_HDLR, index);

    /* Cleare flags */
    if (index == EF_TEST_IDX_CLEAR_FLAGS)
    {
        g_spa_context.sim1_read_retry_count = 0;
        g_spa_context.sim2_read_retry_count = 0;
        g_spa_context.sim_flag = 0;
        mmi_spa_clear_ef_process_flags();
    }
    else if (index == EF_TEST_SET_SIM1_FILE)
    {
        mmi_spa_set_cur_ef_file_idx(MMI_SPA_SIM_ID_SIM1, (S8*) str);
    }
    else if (index == EF_TEST_SET_SIM2_FILE)
    {
        mmi_spa_set_cur_ef_file_idx(MMI_SPA_SIM_ID_SIM2, (S8*) str);
    }
    else if (index == EF_TEST_RESET_NVRAM_VALUES)
    {
        S16 err = 0;
        U16 val = 0xFFFF;

        WriteValue(NVRAM_SPA_LAST_SIM_STATUS, &val, DS_SHORT, &err);
        WriteValue(NVRAM_SPA_CUR_SIM_STATUS, &val, DS_SHORT, &err);
    }
    else if (index == EF_TEST_SET_TEST_CODE_ON)
    {
        mmi_spa_set_test_code_on();
    }
    else if (index == EF_TEST_SET_TEST_CODE_OFF)
    {
        mmi_spa_set_test_code_off();
    }
    /* else if (index == EF_TEST_POPUP_SCREEN)
       {
       mmi_spa_test_popup_test_screen();
       } */
    else if (index == EF_TEST_POPUP_SCREEN)
    {
        //extern void mmi_provboxui_enter_list_menu(void);
        //mmi_provboxui_enter_list_menu();
        //extern void mmi_cca_ui_entry_settings_info(void);
        //mmi_cca_ui_entry_settings_info();
        mmi_provboxui_test_set_list_item_text();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_is_test_code_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_spa_is_test_code_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)(g_spa_test_code_on != 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_test_code_open_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_test_code_open_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_spa_is_test_code_on())
    {
        g_spa_test_code_on = 1;
    }
    else
    {
        g_spa_test_code_on = 0;
    }
}

#endif /* SPA_EF_TEST */ 

#ifdef MMI_SPA_JOB_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_is_sim_available
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_spa_is_sim_available(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_IS_SIM_AVAILABLE, sim_id);

    if (sim_id == MMI_SPA_SIM_ID_SIM1 || sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        /* notified by SIM? */
        if (!mmi_spa_is_sim_status_notified(sim_id))
        {
            return MMI_FALSE;
        }

        /* SIM inserted? */
        if (g_spa_context.sim_status != sim_id && g_spa_context.sim_status != MMI_SPA_SIM_ID_DUAL_SIM)
        {
            return MMI_FALSE;
        }

        /* SIM open? */
        if (g_spa_context.sim_setting_mode != sim_id && g_spa_context.sim_setting_mode != MMI_SPA_SIM_ID_DUAL_SIM)
        {
            return MMI_FALSE;
        }

        if (!mmi_spa_get_sim_can_read_flag(sim_id))
        {
            return MMI_FALSE;
        }

        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_sim_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_spa_get_sim_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_spa_context.sim_flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_convert_result_spa2cca
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
cca_status_enum mmi_spa_convert_result_spa2cca(mmi_spa_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case MMI_SPA_RESULT_OK:
            return CCA_STATUS_OK;

        case MMI_SPA_RESULT_MEM_FULL:
        case MMI_SPA_RESULT_PARSE_CCA_MEM_FULL:
            return CCA_STATUS_MEMFULL;

        case MMI_SPA_RESULT_PARSE_ERROR:
        case MMI_SPA_RESULT_PARSE_CCA_ERROR:
            return CCA_STATUS_FAIL;

        default:
            return CCA_STATUS_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_init_sim_ef_processed_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_init_sim_ef_processed_flag(mmi_spa_sim_id_enum sim_id)
{
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 saved_flags;
    S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_INIT_SIM_EF_PROCESSED_FLAG);

    if (g_spa_context.saved_flag_init != 0)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_NO_INIT_FOR_DUAL_SIM_STATUS);
        return;
    }

#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_DUAL_SIM__ */ 
    g_spa_context.saved_flag_init = 1;
#endif /* __MMI_DUAL_SIM__ */ 

    /* Read NVRAM */
    ReadValue(NVRAM_SPA_EF_PROCESSED_FLAGS, (void*)&saved_flags, DS_SHORT, &err);

    /* saved_flags = 0; */
    if (err != NVRAM_READ_SUCCESS)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_READ_NVRAM_DATA_LAST_ERR);
        saved_flags = 0xFFFF;
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_READ_FLAG_VALUE, saved_flags);

    /* Not saved flags before, reset it to all not saved */
    if (saved_flags == 0xFFFF)
    {
        saved_flags = 0x0000;
    }

    /* Reset SIM1 flags if SIM1 is changed */
    if (sim_id == MMI_SPA_SIM_ID_SIM1 &&
        mmi_spa_is_sim_status_notified(MMI_SPA_SIM_ID_SIM1) && g_spa_context.sim_changed_data.sim1_changed)
    {
        saved_flags &= ~MMI_SPA_FLAG_ALL_SIM1_SAVED_FLAGS;
    }

    /* Reset SIM1 flags if SIM1 is changed */
    if (sim_id == MMI_SPA_SIM_ID_SIM2 &&
        mmi_spa_is_sim_status_notified(MMI_SPA_SIM_ID_SIM2) && g_spa_context.sim_changed_data.sim2_changed)
    {
        saved_flags &= ~MMI_SPA_FLAG_ALL_SIM2_SAVED_FLAGS;
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_WRITE_FLAG_VALUE, saved_flags);

    WriteValue(NVRAM_SPA_EF_PROCESSED_FLAGS, (void*)&saved_flags, DS_SHORT, &err);

    /* Set ef info table */
    mmi_spa_set_ef_saved_state_in_table(sim_id, saved_flags);

    /* g_spa_context.saved_flag_init = 1; */
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_write_ef_saved_flag_to_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_PROV_MESSAGE_SUPPORT__

void mmi_spa_write_ef_saved_flag_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Read cur flags */
    U16 saved_flags;
    S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_WRITE_EF_SAVED_FLAG_TO_NVRAM);

    /* Read NVRAM */
    ReadValue(NVRAM_SPA_EF_PROCESSED_FLAGS, (void*)&saved_flags, DS_SHORT, &err);
    if (err != NVRAM_READ_SUCCESS)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_READ_NVRAM_DATA_LAST_ERR);
        saved_flags = 0;
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_READ_FLAG_VALUE, saved_flags);

    mmi_spa_get_ef_saved_state_in_table(&saved_flags);

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_WRITE_FLAG_VALUE, saved_flags);
    /* Write NVRAM */
    WriteValue(NVRAM_SPA_EF_PROCESSED_FLAGS, (void*)&saved_flags, DS_SHORT, &err);
}
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_job_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_job_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL sim1_available = MMI_FALSE;
    MMI_BOOL sim2_available = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SET_JOB_LIST);

    sim1_available = mmi_spa_is_sim_available(MMI_SPA_SIM_ID_SIM1);
    sim2_available = mmi_spa_is_sim_available(MMI_SPA_SIM_ID_SIM2);

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SIM_AVAILABLE_STATUS, sim1_available, sim2_available);

    /* No sim available, remove all sim jobs */
    if (!sim1_available && !sim2_available)
    {
        mmi_spa_remove_sim_ef_jobs(MMI_SPA_SIM_ID_DUAL_SIM, MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE);
    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        mmi_spa_remove_sim_ef_jobs(MMI_SPA_SIM_ID_DUAL_SIM, MMI_SPA_JOB_TYPE_SAVE_TO_BOX);
    #endif 

        /* Send sim profile status ind to notify sim status directly */
        mmi_spa_send_cca_sim_profile_status_ind(mmi_spa_get_sim_status_notified(), g_spa_context.sim_flag);
    }
    else
    {
        /* sim install jobs */
        if (sim1_available)
        {
            if (!mmi_spa_add_sim_ef_jobs(MMI_SPA_SIM_ID_SIM1, MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE))
            {
                if (!mmi_spa_is_job_type_exist(MMI_SPA_SIM_ID_SIM1, MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE))
                {
                    mmi_spa_send_cca_sim_profile_status_ind(MMI_SPA_SIM_ID_SIM1, g_spa_context.sim_flag);
                }
            }
        }
        else
        {
            mmi_spa_remove_sim_ef_jobs(MMI_SPA_SIM_ID_SIM1, MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE);
            if (mmi_spa_is_sim_status_notified(MMI_SPA_SIM_ID_SIM1))
            {
                mmi_spa_send_cca_sim_profile_status_ind(MMI_SPA_SIM_ID_SIM1, g_spa_context.sim_flag);
            }
        }

        if (sim2_available)
        {
            if (!mmi_spa_add_sim_ef_jobs(MMI_SPA_SIM_ID_SIM2, MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE))
            {
                if (!mmi_spa_is_job_type_exist(MMI_SPA_SIM_ID_SIM2, MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE))
                {
                    mmi_spa_send_cca_sim_profile_status_ind(MMI_SPA_SIM_ID_SIM2, g_spa_context.sim_flag);
                }
            }
        }
        else
        {
            mmi_spa_remove_sim_ef_jobs(MMI_SPA_SIM_ID_SIM2, MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE);
            if (mmi_spa_is_sim_status_notified(MMI_SPA_SIM_ID_SIM2))
            {
                mmi_spa_send_cca_sim_profile_status_ind(MMI_SPA_SIM_ID_SIM2, g_spa_context.sim_flag);
            }
        }

    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        /* sim save jobs */
        if (sim1_available)
        {
            mmi_spa_add_sim_ef_jobs(MMI_SPA_SIM_ID_SIM1, MMI_SPA_JOB_TYPE_SAVE_TO_BOX);
        }
        else
        {
            mmi_spa_remove_sim_ef_jobs(MMI_SPA_SIM_ID_SIM1, MMI_SPA_JOB_TYPE_SAVE_TO_BOX);
        }

        if (sim2_available)
        {
            mmi_spa_add_sim_ef_jobs(MMI_SPA_SIM_ID_SIM2, MMI_SPA_JOB_TYPE_SAVE_TO_BOX);
        }
        else
        {
            mmi_spa_remove_sim_ef_jobs(MMI_SPA_SIM_ID_SIM2, MMI_SPA_JOB_TYPE_SAVE_TO_BOX);
        }
    #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 
    }

    mmi_spa_start_next_job();
}

#endif /* MMI_SPA_JOB_SUPPORT */ 

#endif /* __SPA_SUPPORT__ */ 

