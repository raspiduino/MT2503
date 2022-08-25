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
 *  SIMProvAgentEFHdlr.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Read EF files
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifdef __SPA_SUPPORT__

#include "SIMProvAgentConst.h"
#include "MMIDataType.h"
#include "SIMProvAgentDefs.h"
#include "SIMProvAgentConfig.h"
#include "MMI_features.h"
#include "sim_common_enums.h"
#include "kal_general_types.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "string.h"
#include "fs_func.h"
#include "fs_type.h"
#include "kal_public_api.h"
#include "fs_errcode.h"
#include "app_datetime.h"
#include "CcaSrvGprot.h"
#include "sim_public_api.h"
#include "ps_public_utility.h"

/**************************************************************/
/**********************  Header Files *************************/
/**************************************************************/
#include "SIMAccessSrvGProt.h"
#include "SIMProvAgentProt.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
#include "ProvBoxSrvGprot.h"
#endif

/*****************************************************************/
/******* Constants / Structure / Variables Declaration ***********/
/*****************************************************************/
typedef struct
{
    mmi_spa_sim_id_enum sim_id;
    S32 hRoot;
    S16 ef_table_idx;
    S16 ef_process_fail;
    S16 ef_cca_mem_full;
    spa_sim_ef_process_callback callback;
#ifdef MMI_SPA_JOB_SUPPORT
    mmi_spa_ef_process_job_list job_list;
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    mmi_spa_provbox_app_data_struct app_data;
#endif
#endif 
} mmi_spa_ef_handler_context_struct;

/* EF info table for EF access */
#ifdef __MMSICP_SUPPORT__
static mmi_spa_check_ef_status_result_enum mmi_spa_mmsicp_status_check(mmi_spa_sim_id_enum sim_id);
static mmi_spa_result_enum mmi_spa_mmsicp_read(
                            mmi_spa_sim_id_enum sim_id,
                            sim_file_index_enum file_idx,
                            mmi_spa_ef_type_enum file_type,
                            spa_sim_ef_read_callback_fn callback);
#ifndef MMI_SPA_JOB_SUPPORT
static void mmi_spa_mmsicp_read_callback(mmi_spa_ef_read_result_struct *result);
#endif 
#endif /* __MMSICP_SUPPORT__ */ 

#ifdef MMI_SPA_JOB_SUPPORT
static void mmi_spa_job_ef_read_callback(mmi_spa_ef_read_result_struct *result);
#endif 

#ifdef MMI_SPA_JOB_SUPPORT
static mmi_spa_ef_table_item_struct g_ef_table[] = 
{
#ifdef __MMSICP_SUPPORT__
    {SIM_TYPE_SIM,
     FILE_MMSICP_IDX,
     MMI_SPA_EF_TYPE_TRANSPARENT,
     mmi_spa_mmsicp_status_check,
     mmi_spa_mmsicp_read,
     mmi_spa_job_ef_read_callback,
     mmi_spa_mmsicp_parser, NULL,
    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
     MMI_SPA_FLAG_SIM1_MMSICP_SAVED_FLAG,
     MMI_SPA_FLAG_SIM2_MMSICP_SAVED_FLAG,
    #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 
     0
    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
     , 0
    #endif 
     },
#endif /* __MMSICP_SUPPORT__ */ 
    {(sim_type_query_enum)0xff, (sim_file_index_enum)0, (mmi_spa_ef_type_enum)0, NULL, NULL, NULL, NULL, NULL,
    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
     0, 0,
    #endif 
     0
    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
     , 0
    #endif 
     }
};
#else /* MMI_SPA_JOB_SUPPORT */ 
static const mmi_spa_ef_table_item_struct g_ef_table[] = 
{
#ifdef __MMSICP_SUPPORT__
    {SIM_TYPE_SIM,
     FILE_MMSICP_IDX,
     MMI_SPA_EF_TYPE_TRANSPARENT,
     MMI_SPA_FLAG_EF_MMSICP_PROCESSED,
     mmi_spa_mmsicp_status_check,
     mmi_spa_mmsicp_read,
     mmi_spa_mmsicp_read_callback,
     mmi_spa_mmsicp_parser, NULL},
#endif /* __MMSICP_SUPPORT__ */ 
    {0xff, 0, 0, 0, 0}
};
#endif /* MMI_SPA_JOB_SUPPORT */ 

static const U16 g_sim_mmsicp_service_table[] = {SERVICE_MMS};
//static const U16 g_usim_mmsicp_service_table[] = {SERVICE_U_MMS};

/* Global variables */
static mmi_spa_ef_handler_context_struct g_spa_ef_handler_context;

#ifdef __MMSICP_SUPPORT__
static mmi_spa_read_context_struct g_spa_ef_read_context;
#endif 
static U32 g_spa_sim1_ef_processed_flag = 0;
static U32 g_spa_sim2_ef_processed_flag = 0;

#define MMI_SPA_MIN(a, b) ((a) < (b) ? (a) : (b))
/*****************************************************************/
/************************ Functions ******************************/
/*****************************************************************/
#ifdef __MMSICP_SUPPORT__
static mmi_spa_check_ef_status_result_enum
mmi_spa_ef_status_check(mmi_spa_sim_id_enum sim_id, const U16 *service_table, U16 table_len);

static U16 mmi_spa_read_ef_get_file_info(
            mmi_spa_sim_id_enum sim_id,
            sim_file_index_enum file_idx,
            SrvSimCallbackFunc callback);

static void mmi_spa_mmsicp_get_file_info_callback(U16 err_code, U16 file_size, U16 rec_num);
static void mmi_spa_mmsicp_get_file_info_callback_ext(srv_sim_cb_struct *data);

static U16 mmi_spa_read_ef_read_file(
            mmi_spa_sim_id_enum sim_id,
            sim_file_index_enum file_idx,
            mmi_spa_ef_type_enum file_type,
            U16 file_len,
            U16 rec_num,
            U8 *buf);

//static void mmi_spa_read_ef_read_file_callback(U16 err_code, U16 read_len);
static void mmi_spa_read_ef_read_file_callback_ext(srv_sim_cb_struct* callback_data);

static void mmi_spa_release_read_context(void);
static mmi_spa_result_enum mmi_spa_result_convert(U16 error);
#endif /* __MMSICP_SUPPORT__ */ 

static MMI_BOOL mmi_spa_is_valid_ef_tbl_item(mmi_spa_ef_table_item_struct *item);

#ifdef SPA_EF_TEST
#ifdef __MMSICP_SUPPORT__
static U8 *mmi_spa_ef_test_read_file(mmi_spa_sim_id_enum sim_id, U16 *buf_len);
#endif 
#endif /* SPA_EF_TEST */ 

#ifndef MMI_SPA_JOB_SUPPORT

static void mmi_spa_ef_finalize_handle(mmi_spa_result_enum result);
static void mmi_spa_ef_process_next(void);

/* sim processed flag */
static void mmi_spa_set_ef_processed_flag(mmi_spa_sim_id_enum sim_id, U32 ef_flag);
static U32 mmi_spa_get_ef_processed_flag(mmi_spa_sim_id_enum sim_id, U32 ef_flag);

#ifdef __MMSICP_SUPPORT__
static void mmi_spa_reset_all_ef_processed_flag(mmi_spa_sim_id_enum sim_id);
#endif 

#else /* MMI_SPA_JOB_SUPPORT */ 

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
static MMI_BOOL mmi_spa_is_ef_saving(mmi_spa_ef_table_item_struct *ef_item, mmi_spa_sim_id_enum sim_id);
static void mmi_spa_set_ef_saving(mmi_spa_ef_table_item_struct *ef_item, mmi_spa_sim_id_enum sim_id);
static void mmi_spa_clear_ef_saving(mmi_spa_ef_table_item_struct *ef_item, mmi_spa_sim_id_enum sim_id);
static void mmi_spa_remove_sim_save_job_by_ef(U8 ef_index, mmi_spa_sim_id_enum sim_id);
static void mmi_spa_do_sim_save(mmi_spa_ef_process_job_node_struct *job);
static void mmi_spa_do_box_install(mmi_spa_ef_process_job_node_struct *job);
static void mmi_spa_set_ef_saved_flag(U8 ef_tbl_index, mmi_spa_sim_id_enum sim_id);
static MMI_BOOL mmi_spa_get_ef_saved_flag(U8 ef_tbl_index, mmi_spa_sim_id_enum sim_id);
static void mmi_spa_continue_box_install(mmi_spa_ef_process_job_node_struct *job);
static void mmi_spa_save_ef_to_box(mmi_spa_ef_process_job_node_struct *job);
static void mmi_spa_set_msg_cmn_info(
                mmi_provbox_save_msg_req_struct *msg_data,
                mmi_spa_ef_process_job_node_struct *job);
static void mmi_spa_set_msg_config_info(
                mmi_provbox_save_msg_req_struct *msg_data,
                mmi_spa_ef_process_job_node_struct *job);
static void mmi_spa_set_msg_data(
                mmi_provbox_save_msg_req_struct *msg_data,
                void *app_data,
                S16 app_data_size,
                mmi_provbox_save_data_type_enum data_type,
                S16 prov_data_size,
                void *prov_data,
                U16 *prov_file);
static U8 mmi_spa_get_ef_tbl_index_from_app_data(mmi_spa_provbox_app_data_struct *app_data);
static void mmi_spa_save_ef_msg_info(
                mmi_spa_ef_process_job_node_struct *job,
                mmi_cca_source_new_doc_rsp_struct *data);
static void mmi_spa_set_config_results(
                mmi_provbox_msg_config_status_struct *provbox_result,
                mmi_cca_source_new_doc_rsp_struct *cca_result);
static mmi_provbox_config_id_enum mmi_spa_config_id_convert_cca2provbox(U16 cca_config_id);
static mmi_provbox_config_status_enum mmi_spa_config_status_convert_cca2provbox(cca_status_enum cca_status);
static void mmi_spa_clear_ef_msg_info(U8 ef_tbl_index, mmi_spa_sim_id_enum sim_id);
static U32 mmi_spa_get_timestamp(void);
static void mmi_spa_add_box_install_job(mmi_cca_source_install_prov_msg_req_struct *data);

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

static MMI_BOOL mmi_spa_is_ef_installing(mmi_spa_ef_table_item_struct *ef_item, mmi_spa_sim_id_enum sim_id);
static void mmi_spa_set_ef_installing(mmi_spa_ef_table_item_struct *ef_item, mmi_spa_sim_id_enum sim_id);
static void mmi_spa_clear_ef_installing(mmi_spa_ef_table_item_struct *ef_item, mmi_spa_sim_id_enum sim_id);
static mmi_spa_result_enum mmi_spa_insert_job(
                            U8 ef_tbl_index,
                            mmi_spa_sim_id_enum sim_id,
                            U32 msg_id,
                            U32 trans_id,
                            mmi_spa_job_type_enum type);
static void mmi_spa_remove_job(mmi_spa_ef_process_job_node_struct *item);
static void mmi_spa_cancel_cur_job(void);
static void mmi_spa_stop_job(mmi_spa_ef_process_job_node_struct *job);
static void mmi_spa_insert_job_list_node(mmi_spa_ef_process_job_node_struct *node);
static void mmi_spa_delete_job_list_node(mmi_spa_ef_process_job_node_struct *node);
static void mmi_spa_do_sim_install(mmi_spa_ef_process_job_node_struct *job);
static void mmi_spa_set_job_state(mmi_spa_ef_process_job_node_struct *job, mmi_spa_job_state_enum state);
static void mmi_spa_continue_sim_install(mmi_spa_ef_process_job_node_struct *job);
static void mmi_spa_set_ef_installed_flag(U8 ef_tbl_index, mmi_spa_sim_id_enum sim_id);
static MMI_BOOL mmi_spa_get_ef_installed_flag(U8 ef_tbl_index, mmi_spa_sim_id_enum sim_id);
static void mmi_spa_increase_ef_install_retry_count(U8 ef_tbl_index, mmi_spa_sim_id_enum sim_id);
static void mmi_spa_continue_job_after_read_ef(mmi_spa_ef_process_job_node_struct *job);
static U8 mmi_spa_get_ef_install_retry_count(U8 ef_tbl_index, mmi_spa_sim_id_enum sim_id);
static mmi_spa_result_enum mmi_spa_parse_and_create_cca_doc(
                            mmi_spa_ef_process_job_node_struct *job,
                            U8 *data,
                            U16 len,
                            S32 *hconfig_ret);

#endif /* MMI_SPA_JOB_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_ef_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MMI_SPA_JOB_SUPPORT
mmi_spa_result_enum mmi_spa_ef_hdlr(mmi_spa_sim_id_enum sim_id, spa_sim_ef_process_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_result_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_HDLR, sim_id);

    memset(&g_spa_ef_handler_context, 0, sizeof(mmi_spa_ef_handler_context_struct));

    g_spa_ef_handler_context.sim_id = sim_id;
    g_spa_ef_handler_context.callback = callback;
    g_spa_ef_handler_context.hRoot = mmi_cca_doc_new_rootnode();

    if (!g_spa_ef_handler_context.hRoot)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_HDLR_HROOT_FAIL);
        return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
    }

    while (mmi_spa_is_valid_ef_tbl_item
           ((mmi_spa_ef_table_item_struct*) & g_ef_table[g_spa_ef_handler_context.ef_table_idx]))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_HDLR_IN_WHILE, g_spa_ef_handler_context.ef_table_idx);

        /* Processed one, to next one */
        if (mmi_spa_get_ef_processed_flag(
                sim_id,
                g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_file_processed_flag))
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_HDLR_IN_WHILE_PROCESSED_ITEM);
            g_spa_ef_handler_context.ef_table_idx++;
            continue;
        }

        /* Check this EF */
        if (g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_status_checker)
        {
            /* Not activate, go to next */
            if (MMI_SPA_CHECK_EF_STATUS_RESULT_ACTIVATED !=
                g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_status_checker(sim_id))
            {
                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_HDLR_IN_WHILE_INACTIVATE_EF);

                /* Will not process this one again */
                mmi_spa_set_ef_processed_flag(
                    sim_id,
                    g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_file_processed_flag);

                /* To next one */
                g_spa_ef_handler_context.ef_table_idx++;
                continue;
            }
        }

        /* Read it */
        if (g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_reader)
        {
            ret = g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_reader(
                                                                        sim_id,
                                                                        g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_file_idx,
                                                                        g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_file_type,
                                                                        g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_reader_callback);

            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_HDLR_READER_RET, ret);

            /* If read fail, go to next */
            if (MMI_SPA_RESULT_OK != ret)
            {
                if (ret == MMI_SPA_RESULT_FAIL) /* Can't process again */
                {
                    mmi_cca_docroot_release(g_spa_ef_handler_context.hRoot);
                    g_spa_ef_handler_context.hRoot = 0;
                    return ret;
                }
                else if (ret == MMI_SPA_RESULT_TEMP_FAIL)   /* Retry this EF next time */
                {
                    /* To next one */
                    g_spa_ef_handler_context.ef_table_idx++;
                    g_spa_ef_handler_context.ef_process_fail = 1;
                    continue;
                }
                else if (ret == MMI_SPA_RESULT_IGNORE_THIS_FILE)
                {
                    /* Will not process this one again */
                    mmi_spa_set_ef_processed_flag(
                        sim_id,
                        g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_file_processed_flag);

                    /* To next one */
                    g_spa_ef_handler_context.ef_table_idx++;

                    continue;
                }
                else
                {
                    /* To next one */
                    g_spa_ef_handler_context.ef_table_idx++;
                    g_spa_ef_handler_context.ef_process_fail = 1;
                    continue;
                }
            }
            return MMI_SPA_RESULT_OK;
        }
    }

    if (g_spa_ef_handler_context.ef_process_fail)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_HDLR_RETURN_TEMP_FAIL);
        return MMI_SPA_RESULT_TEMP_FAIL;
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_HDLR_RETURN_NO_ACTIVATED_EF);
    return MMI_SPA_RESULT_NO_ACTIVATED_EF;
}
#endif /* MMI_SPA_JOB_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_ef_table_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_spa_get_ef_table_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(g_ef_table) / sizeof(mmi_spa_ef_table_item_struct);
}

#ifdef __MMSICP_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_ef_process_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MMI_SPA_JOB_SUPPORT

static void mmi_spa_ef_process_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_result_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_PROCESS_NEXT, g_spa_ef_handler_context.ef_table_idx);

    g_spa_ef_handler_context.ef_table_idx++;

    while (mmi_spa_is_valid_ef_tbl_item
           ((mmi_spa_ef_table_item_struct*) & g_ef_table[g_spa_ef_handler_context.ef_table_idx]))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_PROCESS_NEXT_IN_WHILE, g_spa_ef_handler_context.ef_table_idx);

        /* Processed one, to next one */
        if (mmi_spa_get_ef_processed_flag(
                g_spa_ef_handler_context.sim_id,
                g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_file_processed_flag))
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_PROCESS_NEXT_IN_WHILE_PORCESSED_ITEM);
            g_spa_ef_handler_context.ef_table_idx++;
            continue;
        }

        /* Check this EF */
        if (g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_status_checker)
        {
            if (MMI_SPA_CHECK_EF_STATUS_RESULT_ACTIVATED !=
                g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_status_checker(g_spa_ef_handler_context.sim_id))
            {
                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_PROCESS_NEXT_IN_WHILE_NOT_ACTIVATE);

                /* Will not process this one again */
                mmi_spa_set_ef_processed_flag(
                    g_spa_ef_handler_context.sim_id,
                    g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_file_processed_flag);

                /* To next one */
                g_spa_ef_handler_context.ef_table_idx++;
                continue;
            }
        }

        /* Read it */
        if (g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_reader)
        {
            ret = g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_reader(
                                                                        g_spa_ef_handler_context.sim_id,
                                                                        g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_file_idx,
                                                                        g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_file_type,
                                                                        g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_reader_callback);

            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_HDLR_READER_RET, ret);

            if (MMI_SPA_RESULT_OK != ret)
            {
                if (ret == MMI_SPA_RESULT_FAIL) /* Can't process again */
                {
                    mmi_spa_ef_finalize_handle(MMI_SPA_RESULT_FAIL);
                    return;
                }
                else if (ret == MMI_SPA_RESULT_TEMP_FAIL)   /* Retry this EF next time */
                {
                    /* To next one */
                    g_spa_ef_handler_context.ef_table_idx++;
                    g_spa_ef_handler_context.ef_process_fail = 1;
                    continue;
                }
                else if (ret == MMI_SPA_RESULT_IGNORE_THIS_FILE)
                {
                    /* Will not process this one again */
                    mmi_spa_set_ef_processed_flag(
                        g_spa_ef_handler_context.sim_id,
                        g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_file_processed_flag);

                    /* To next one */
                    g_spa_ef_handler_context.ef_table_idx++;

                    continue;
                }
                else
                {
                    /* To next one */
                    g_spa_ef_handler_context.ef_table_idx++;
                    g_spa_ef_handler_context.ef_process_fail = 1;
                    continue;
                }
            }
            return;
        }
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_PROCESS_NEXT_END);
    mmi_spa_ef_finalize_handle(MMI_SPA_RESULT_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_ef_finalize_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_ef_finalize_handle(mmi_spa_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hConfig;
    kal_int32 hDeprel;
    mmi_spa_sim_ef_process_result_struct process_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_FINALIZE_HANDLE, result);

    memset(&process_result, 0, sizeof(mmi_spa_sim_ef_process_result_struct));

    process_result.sim_id = g_spa_ef_handler_context.sim_id;
    process_result.result = result;

    if (result == MMI_SPA_RESULT_OK)
    {
        /* validate and fix OMA document */
        mmi_cca_oma_fix_doc(g_spa_ef_handler_context.hRoot);

        /* generate dependency relationship node */
        hDeprel = mmi_cca_oma_generate_deprel_node(g_spa_ef_handler_context.hRoot);
        if (!hDeprel)
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_FINALIZE_HANDLE_DEPREL_ERR);

            mmi_cca_docroot_release(g_spa_ef_handler_context.hRoot);
            g_spa_ef_handler_context.hRoot = 0;
            process_result.result = MMI_SPA_RESULT_FAIL_IN_FINALIZE;    /* MMI_SPA_RESULT_PARSE_CCA_MEM_FULL; */

            mmi_spa_reset_all_ef_processed_flag(g_spa_ef_handler_context.sim_id);
            g_spa_ef_handler_context.callback(&process_result);

            return;
        }

        mmi_cca_doc_attach_node_to_parent(hDeprel, g_spa_ef_handler_context.hRoot);

        /* sort document */
        mmi_cca_oma_sort_new_doc(g_spa_ef_handler_context.hRoot);

        /* construct CCA document */
        hConfig = mmi_cca_doc_new(g_spa_ef_handler_context.hRoot);

        if (hConfig == 0)
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_FINALIZE_HANDLE_DOC_NEW_ERR);

            mmi_cca_docroot_release(g_spa_ef_handler_context.hRoot);
            g_spa_ef_handler_context.hRoot = 0;
            process_result.result = MMI_SPA_RESULT_FAIL_IN_FINALIZE;    /* MMI_SPA_RESULT_PARSE_CCA_MEM_FULL; */
            process_result.hconfig = 0;

            mmi_spa_reset_all_ef_processed_flag(g_spa_ef_handler_context.sim_id);
            g_spa_ef_handler_context.callback(&process_result);

            return;
        }

        if (!mmi_spa_check_hconfig(hConfig))
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_FINALIZE_HANDLE_CHECK_CONFIG_ERR);
            mmi_cca_doc_release(hConfig);
            g_spa_ef_handler_context.hRoot = 0;
            process_result.result = MMI_SPA_RESULT_PARSE_EMPTY_ROOT;
            process_result.hconfig = 0;
            g_spa_ef_handler_context.callback(&process_result);

            return;
        }

        if (g_spa_ef_handler_context.ef_process_fail == 1)
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_FINALIZE_HANDLE_HAVE_PROCESS_FAIL);
            process_result.result = MMI_SPA_RESULT_NOT_ALL_PROCESSED;
        }

        process_result.hconfig = hConfig;
    }
    else
    {
        mmi_cca_docroot_release(g_spa_ef_handler_context.hRoot);
        g_spa_ef_handler_context.hRoot = 0;
        /* process_result.result = MMI_SPA_RESULT_FAIL; */
        process_result.hconfig = 0;
    }

    g_spa_ef_handler_context.callback(&process_result);
}

#endif /* MMI_SPA_JOB_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_status_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_spa_check_ef_status_result_enum mmi_spa_mmsicp_status_check(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_spa_ef_status_check(
            sim_id,
            g_sim_mmsicp_service_table,
            (U16) (sizeof(g_sim_mmsicp_service_table) / sizeof(U16)));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_ef_status_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id              [IN]        
 *  service_table       [IN]        
 *  table_len           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_spa_check_ef_status_result_enum
mmi_spa_ef_status_check(mmi_spa_sim_id_enum sim_id, const U16 *service_table, U16 table_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    sim_service_state_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_STATUS_CHECK);

#ifdef SPA_EF_TEST
    if (mmi_spa_is_test_code_open())
    {
        return MMI_SPA_CHECK_EF_STATUS_RESULT_ACTIVATED;
    }
#endif /* SPA_EF_TEST */ 
    if (!service_table)
    {
        return MMI_SPA_CHECK_EF_STATUS_RESULT_INACTIVATED;
    }

    for (i = 0; i < table_len; i++)
    {
    #ifdef __GEMINI__
        //ret = sim_service_table_query((sim_service_enum) service_table[i], mmi_spa_sim_id_convert(sim_id));
        ret = sim_service_table_query((sim_service_enum) service_table[i], 
            l4c_gemini_get_switched_sim_id(mmi_spa_sim_id_convert(sim_id)));
    #else 
        ret = sim_service_table_query((sim_service_enum) service_table[i]);
    #endif 

        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_STATUS_CHECK_RET, ret);

        if (SERVICE_SUPPORT != ret)
        {
            return MMI_SPA_CHECK_EF_STATUS_RESULT_INACTIVATED;
        }
    }

    return MMI_SPA_CHECK_EF_STATUS_RESULT_ACTIVATED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  file_idx        [IN]        
 *  file_type       [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_spa_result_enum mmi_spa_mmsicp_read(
                            mmi_spa_sim_id_enum sim_id,
                            sim_file_index_enum file_idx,
                            mmi_spa_ef_type_enum file_type,
                            spa_sim_ef_read_callback_fn callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_READ, sim_id, file_type);

    memset(&g_spa_ef_read_context, 0, sizeof(g_spa_ef_read_context));

    g_spa_ef_read_context.sim_id = sim_id;
    g_spa_ef_read_context.file_idx = file_idx;
    g_spa_ef_read_context.read_callback = callback;
    g_spa_ef_read_context.status = MMI_SPA_EF_READ_STATE_GETTING_INFO;
    g_spa_ef_read_context.file_type = file_type;

#ifdef SPA_EF_TEST
    if (mmi_spa_is_test_code_open())
    {
        g_spa_ef_read_context.file_idx = FILE_SST_IDX;
    }
#endif /* SPA_EF_TEST */ 

    ret = mmi_spa_read_ef_get_file_info(sim_id, g_spa_ef_read_context.file_idx, mmi_spa_mmsicp_get_file_info_callback_ext);

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_GET_INFO_RET, ret);

    if (ret == MMI_TRUE)
    {
        return MMI_SPA_RESULT_OK;
    }

    return MMI_SPA_RESULT_TEMP_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_read_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MMI_SPA_JOB_SUPPORT

static void mmi_spa_mmsicp_read_callback(mmi_spa_ef_read_result_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_result_enum ret;
    mmi_spa_sim_mmsicp_parse_param_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_READ_CALLBACK, result->result);

    if (result->result != MMI_SPA_RESULT_OK)
    {
        if (result->buf)
        {
            mmi_spa_free(result->buf);
            result->buf = NULL;
        }

        if (result->result == MMI_SPA_RESULT_FAIL)
        {
            mmi_spa_ef_finalize_handle(result->result);
            mmi_spa_release_read_context();
            return;
        }

        if (result->result == MMI_SPA_RESULT_IGNORE_THIS_FILE || result->result == MMI_SPA_RESULT_EMPTY_EF)
        {
            /* Will not process this one again */
            mmi_spa_set_ef_processed_flag(
                g_spa_ef_handler_context.sim_id,
                g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_file_processed_flag);
        }

        mmi_spa_release_read_context();

        /* Go to next EF */
        g_spa_ef_handler_context.ef_process_fail = 1;
        mmi_spa_ef_process_next();
        return;
    }

#ifdef SPA_EF_TEST
    if (mmi_spa_is_test_code_open())
    {
        mmi_spa_free(result->buf);
        result->buf = NULL;
        result->read_len = 0;

        result->buf = mmi_spa_ef_test_read_file(g_spa_ef_handler_context.sim_id, &result->read_len);
        if (!result->buf)
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_TEST_READ_TEST_FILE_FAIL);
            g_spa_ef_handler_context.ef_process_fail = 1;
            mmi_spa_release_read_context();
            mmi_spa_ef_process_next();
            return;
        }
    }
#endif /* SPA_EF_TEST */ 

    mmi_spa_release_read_context();

    /* parse */
    param.buf = result->buf;
    param.len = (S32) result->read_len;
    param.hRoot = g_spa_ef_handler_context.hRoot;

    ret = g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_parser(
                                                                (void*)&param,
                                                                g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_parser_callback);

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_READ_CALLBACK_PARSER_RET, ret);

    if (result->buf)
    {
        mmi_spa_free(result->buf);
        result->buf = NULL;
    }

    if (ret != MMI_SPA_RESULT_OK)
    {
        if (ret == MMI_SPA_RESULT_PARSE_ERROR_LENGTH || ret == MMI_SPA_RESULT_PARSE_INVALID_DATA)
        {
            /* Error because of invalid content, so can't process again */
            mmi_spa_set_ef_processed_flag(
                g_spa_ef_handler_context.sim_id,
                g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_file_processed_flag);
        }

        g_spa_ef_handler_context.ef_process_fail = 1;
        mmi_spa_ef_process_next();
        return;
    }

    /* Process ok, no need to process again */
    mmi_spa_set_ef_processed_flag(
        g_spa_ef_handler_context.sim_id,
        g_ef_table[g_spa_ef_handler_context.ef_table_idx].ef_file_processed_flag);

    /* goto next */
    mmi_spa_ef_process_next();
}
#endif /* MMI_SPA_JOB_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_read_ef_get_file_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  file_idx        [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_spa_read_ef_get_file_info(
            mmi_spa_sim_id_enum sim_id,
            sim_file_index_enum file_idx,
            SrvSimCallbackFunc callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //return mmi_sim_access_file_info((U8) file_idx, NULL, (U8) APP_SPA, callback, mmi_spa_sim_id_convert(sim_id));
    return srv_sim_get_file_info((U8) file_idx, NULL, mmi_spa_sim_id_spa2mmi(sim_id), callback, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_get_file_info_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  err_code        [IN]        
 *  file_size       [IN]        
 *  rec_num         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_mmsicp_get_file_info_callback(U16 err_code, U16 file_size, U16 rec_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *buf = NULL;
    U16 ret;
    mmi_spa_ef_read_result_struct result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_GET_FILE_INFO_CALLBACK, err_code, file_size, rec_num);

    if (g_spa_ef_read_context.status != MMI_SPA_EF_READ_STATE_GETTING_INFO)
    {
        /* ASSERT(!"Error state"); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_ERROR_FILE_INFO_STATE);

        memset(&result, 0, sizeof(mmi_spa_ef_read_result_struct));
        result.result = MMI_SPA_RESULT_SIM_FILE_ACCESS_ERROR_STATUS;

        g_spa_ef_read_context.read_callback(&result);
        return;
    }

    if (err_code != SIM_CMD_SUCCESS)
    {
        memset(&result, 0, sizeof(mmi_spa_ef_read_result_struct));
        result.result = mmi_spa_result_convert(err_code);

        g_spa_ef_read_context.read_callback(&result);
        return;
    }

    if (file_size == 0)
    {
        memset(&result, 0, sizeof(mmi_spa_ef_read_result_struct));
        result.result = MMI_SPA_RESULT_EMPTY_EF;

        g_spa_ef_read_context.read_callback(&result);
        return;
    }

    g_spa_ef_read_context.file_len = file_size;

    buf = mmi_spa_malloc(file_size);
    if (!buf)
    {
        /* ASSERT(!"SPA MEM FAIL"); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_GET_FILE_INFO_CALLBACK_SPA_MEM_FAIL);

        memset(&result, 0, sizeof(mmi_spa_ef_read_result_struct));
        result.result = MMI_SPA_RESULT_MEM_FULL;

        g_spa_ef_read_context.read_callback(&result);
        return;
    }

    g_spa_ef_read_context.buf = buf;

    ret = mmi_spa_read_ef_read_file(
            g_spa_ef_read_context.sim_id,
            g_spa_ef_read_context.file_idx,
            g_spa_ef_read_context.file_type,
            g_spa_ef_read_context.file_len,
            g_spa_ef_read_context.rec_num,
            g_spa_ef_read_context.buf);

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_GET_FILE_INFO_CALLBACK_READ_FILE_RET, ret);

    if (!ret)
    {
        /* ASSERT(!"read file fail"); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_ERROR_READ_EF_RETURN_FALSE);

        mmi_spa_free(buf);

        memset(&result, 0, sizeof(mmi_spa_ef_read_result_struct));
        result.result = MMI_SPA_RESULT_SIM_BUSY;

        g_spa_ef_read_context.read_callback(&result);
        return;
    }

    g_spa_ef_read_context.status = MMI_SPA_EF_READ_STATE_READING;

    return;
}

static void mmi_spa_mmsicp_get_file_info_callback_ext(srv_sim_cb_struct *data)
{
    U16 err_code;
    srv_sim_file_info_struct *info;
    
    if (data->action != SRV_SIM_GET_FILE_INF)
    {
        return;
    }

    if (data->result)
    {
        err_code = SIM_CMD_SUCCESS;
    }
    else
    {
        err_code = data->cause;
    }

    info = (srv_sim_file_info_struct*)data->data;
    mmi_spa_mmsicp_get_file_info_callback(err_code, info->file_size, info->num_of_rec);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_spa_read_ef_read_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  file_idx        [IN]        
 *  file_type       [IN]        
 *  file_len        [IN]        
 *  rec_num         [IN]        
 *  buf             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_spa_read_ef_read_file(
            mmi_spa_sim_id_enum sim_id,
            sim_file_index_enum file_idx,
            mmi_spa_ef_type_enum file_type,
            U16 file_len,
            U16 rec_num,
            U8 *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_READ_EF_READ_FILE, sim_id, file_idx, file_type, file_len, rec_num);

    switch (file_type)
    {
        case MMI_SPA_EF_TYPE_TRANSPARENT:
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
            #endif
            return srv_sim_read_binary((U16)file_idx, NULL, 0, file_len, mmi_spa_sim_id_spa2mmi(sim_id), mmi_spa_read_ef_read_file_callback_ext, NULL);
            break;
        case MMI_SPA_EF_TYPE_LINEAR_FIXED:
            /* ASSERT(0); */
            return MMI_SPA_RESULT_FAIL;
        case MMI_SPA_EF_TYPE_CYLIC:
            /* ASSERT(0); */
            return MMI_SPA_RESULT_FAIL;
            /* default: */
            /* ASSERT(0); */
    }
    return MMI_SPA_RESULT_FAIL;
}

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
#endif

static void mmi_spa_read_ef_read_file_callback_ext(srv_sim_cb_struct* callback_data)
{
    U16 err_code;
    srv_sim_data_struct *info;
    mmi_spa_ef_read_result_struct result;

	MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_READ_EF_READ_FILE_CALLBACK, 0, 0);

    memset(&result, 0, sizeof(mmi_spa_ef_read_result_struct));

    if (callback_data->action != SRV_SIM_READ_BINARY)
    {
        return;
    }

    if (g_spa_ef_read_context.status != MMI_SPA_EF_READ_STATE_READING)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_ERROR_ERR_STATE_IN_READ_CALLBACK);

        /* Reset read context */
        if (g_spa_ef_read_context.buf)
        {
            mmi_spa_free(g_spa_ef_read_context.buf);
            g_spa_ef_read_context.buf = NULL;
        }

        result.result = MMI_SPA_RESULT_SIM_FILE_ACCESS_ERROR_STATUS;
        g_spa_ef_read_context.read_callback(&result);
        return;
    }
    
    if (callback_data->result)
    {
        err_code = SIM_CMD_SUCCESS;
    }
    else
    {
        err_code = callback_data->cause;
    }

    if (err_code != SIM_CMD_SUCCESS)
    {
        /* Reset read context */
        if (g_spa_ef_read_context.buf)
        {
            mmi_spa_free(g_spa_ef_read_context.buf);
            g_spa_ef_read_context.buf = NULL;
        }

        result.result = mmi_spa_result_convert(err_code);
        g_spa_ef_read_context.read_callback(&result);
        return;
    }
    
    info = (srv_sim_data_struct*)callback_data->data;
    
    /* fill result */
    memcpy(g_spa_ef_read_context.buf, info->data, info->length);
    
    result.buf = g_spa_ef_read_context.buf;
    result.file_size = g_spa_ef_read_context.file_len;
    result.read_len = info->length;
    result.rec_num = g_spa_ef_read_context.rec_num;
    result.result = MMI_SPA_RESULT_OK;

    g_spa_ef_read_context.buf = NULL;

    g_spa_ef_read_context.read_callback(&result);
}

#endif /* __MMSICP_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_sim_id_convert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_spa_sim_id_convert(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1 || sim_id == MMI_SPA_SIM_ID_DEFAULT)
    {
        if (sim_id == MMI_SPA_SIM_ID_DEFAULT)
        {
            /* ASSERT(0); */
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_SIM_ID_CONVERT_FROM_DEFAULT);
        }
        return SIM1;
    }
    if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        return SIM2;
    }
    /* ASSERT(0); */
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_UNSUPPORT_SIM_ID, sim_id);

    return SIM1;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_spa_sim_id_spa2mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_sim_enum mmi_spa_sim_id_spa2mmi(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1 || sim_id == MMI_SPA_SIM_ID_DEFAULT)
    {
        if (sim_id == MMI_SPA_SIM_ID_DEFAULT)
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_SIM_ID_CONVERT_FROM_DEFAULT);
        }
        return MMI_SIM1;
    }
    if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        return MMI_SIM2;
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ASSERT_UNSUPPORT_SIM_ID, sim_id);

    return MMI_SIM1;
}

#ifdef __MMSICP_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_result_convert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_spa_result_enum mmi_spa_result_convert(U16 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (error)
    {
        case SIM_CMD_SUCCESS:
            return MMI_SPA_RESULT_OK;

        case SIM_CHV_NOT_INIT:
        case SIM_CHV_RETRY_ALLOW:
        case SIM_CHV_BLOCK:
        case SIM_SAT_CMD_BUSY:
        case SIM_MEMORY_PROBLEM:
        case SIM_RECORD_NOT_FOUND:
        case SIM_REF_DATA_NOT_FOUND:
        case SIM_INCREASE_FAIL:
        case SIM_PUK_UNLOCK:
        case SIM_ACCESS_NOT_ALLOW:
            return MMI_SPA_RESULT_TEMP_FAIL;

        case SIM_FILE_NOT_FOUND:
            return MMI_SPA_RESULT_IGNORE_THIS_FILE;

        case SIM_CMD_FAIL:
        case SIM_FATAL_ERROR:
        case SIM_NO_INSERTED:
        case SIM_DL_ERROR:
        case SIM_TECHNICAL_PROBLEM:
        case SIM_EF_RECORD_FULL:
        case SIM_SELECT_FILE_INVALID:
        case SIM_SELECT_DF_TERMINATED:
        case SIM_NO_EF_SELECTED:
        case SIM_AUTH_ERROR_WRONG_MAC:
        case SIM_AUTH_ERROR_GSM_NOT_SUPPORT:
        case SIM_WRONG_INSTRUCTION_CLASS:
        default:
            return MMI_SPA_RESULT_FAIL;
    }
}

#endif /* __MMSICP_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_ef_processed_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 *  ef_flag     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MMI_SPA_JOB_SUPPORT
static void mmi_spa_set_ef_processed_flag(mmi_spa_sim_id_enum sim_id, U32 ef_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        g_spa_sim1_ef_processed_flag |= ef_flag;
    }
    else
    {
        g_spa_sim2_ef_processed_flag |= ef_flag;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_ef_processed_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 *  ef_flag     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U32 mmi_spa_get_ef_processed_flag(mmi_spa_sim_id_enum sim_id, U32 ef_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        result = g_spa_sim1_ef_processed_flag & ef_flag;
    }
    else
    {
        result = g_spa_sim2_ef_processed_flag & ef_flag;
    }

    return result;
}

#ifdef __MMSICP_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_reset_all_ef_processed_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_reset_all_ef_processed_flag(mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        g_spa_sim1_ef_processed_flag = 0;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        g_spa_sim2_ef_processed_flag = 0;
    }
}
#endif /* __MMSICP_SUPPORT__ */ 
#endif /* MMI_SPA_JOB_SUPPORT */ 

#ifdef __MMSICP_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_release_read_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_release_read_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_RELEASE_READ_CONTEXT);
    memset(&g_spa_ef_read_context, 0, sizeof(mmi_spa_read_context_struct));
}
#endif /* __MMSICP_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_is_valid_ef_tbl_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item        [IN]
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_spa_is_valid_ef_tbl_item(mmi_spa_ef_table_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item->sim_type == 0xFF)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}

#ifdef SPA_EF_TEST
#define EF_TEST_FILE_NAME   "C:\\\\"
#define EF_TEST_FILE_NAME_RECORDER  L"C:\\\\spa_test_file_name"
#define EF_TEST_FILE_TEST_CODE_CONTROL  L"C:\\\\spa_test_code_ctrl"
#define EF_TEST_FILE_READ_POS   0x100
#define EF_TEST_FILE_NAME_LEN   32

static S16 g_cur_sim1_ef_file[EF_TEST_FILE_NAME_LEN] = {0x00};
static S16 g_cur_sim2_ef_file[EF_TEST_FILE_NAME_LEN] = {0x00};


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_clear_ef_process_flags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_clear_ef_process_flags(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_spa_sim1_ef_processed_flag = 0;
    g_spa_sim2_ef_processed_flag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_ef_test_asc2unicode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [OUT]
 *  src         [IN]
 * RETURNS
 *  
 *****************************************************************************/
static S8 *mmi_spa_ef_test_asc2unicode(S8 *dest, S8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pSrc = src;
    S8 *pDest = dest;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_TEST_ASC2UNICODE);

    while (*pSrc != 0)
    {

        *pDest = *pSrc;
        *(pDest + 1) = 0;
        pDest += 2;
        pSrc++;
    }
    *pDest = *(pDest + 1) = 0;
    return dest;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_write_test_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_write_test_file_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hFile;
    UINT len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hFile = FS_Open(EF_TEST_FILE_NAME_RECORDER, FS_READ_WRITE);
    if (hFile <= 0)
    {
        return;
    }

    FS_Write(hFile, (void*)g_cur_sim1_ef_file, EF_TEST_FILE_NAME_LEN * sizeof(S16), &len);
    FS_Write(hFile, (void*)g_cur_sim2_ef_file, EF_TEST_FILE_NAME_LEN * sizeof(S16), &len);

    FS_Close(hFile);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_read_test_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_read_test_file_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hFile;
    S32 attr = 0;
    UINT len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hFile = FS_Open(EF_TEST_FILE_NAME_RECORDER, FS_READ_ONLY);
    if (hFile <= 0)
    {
        /* Create file */
        hFile = FS_Open(EF_TEST_FILE_NAME_RECORDER, FS_CREATE);
        FS_Close(hFile);

        /* Set it hidden file */
        attr = FS_GetAttributes(EF_TEST_FILE_NAME_RECORDER);
        attr |= FS_ATTR_HIDDEN;
        FS_SetAttributes(EF_TEST_FILE_NAME_RECORDER, (U8) attr);

        g_cur_sim1_ef_file[0] = 0x00;
        g_cur_sim2_ef_file[0] = 0x00;

        return;
    }

    FS_Read(hFile, (void*)g_cur_sim1_ef_file, EF_TEST_FILE_NAME_LEN * sizeof(S16), &len);
    FS_Read(hFile, (void*)g_cur_sim2_ef_file, EF_TEST_FILE_NAME_LEN * sizeof(S16), &len);

    FS_Close(hFile);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_cur_ef_file_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 *  file        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_set_cur_ef_file_idx(mmi_spa_sim_id_enum sim_id, S8 *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        mmi_spa_ef_test_asc2unicode((S8*) g_cur_sim1_ef_file, file);
    }
    else
    {
        mmi_spa_ef_test_asc2unicode((S8*) g_cur_sim2_ef_file, file);
    }

    mmi_spa_write_test_file_name();
}

#ifdef __MMSICP_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_ef_test_read_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 *  buf_len     [IN]
 * RETURNS
 *  
 *****************************************************************************/
static U8 *mmi_spa_ef_test_read_file(mmi_spa_sim_id_enum sim_id, U16 *buf_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hFile;
    U8 *buf = NULL;
    UINT len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_TEST_READ_FILE, sim_id);

    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        hFile = FS_Open((const WCHAR*)g_cur_sim1_ef_file, FS_READ_ONLY);
    }
    else
    {
        hFile = FS_Open((const WCHAR*)g_cur_sim2_ef_file, FS_READ_ONLY);
    }

    if (hFile <= 0)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_TEST_READ_FILE_OPEN_FILE_FAIL, hFile);
        return NULL;
    }

    FS_GetFileSize(hFile, &len);

    if (len == 0)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_TEST_READ_FILE_ZERO_LEN);
        FS_Close(hFile);
        return NULL;
    }

    len -= EF_TEST_FILE_READ_POS;

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_TEST_READ_FILE_LEN, len);

    buf = mmi_spa_malloc(len);
    if (!buf)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_TEST_READ_FILE_BUF_FAIL);
        FS_Close(hFile);
        return NULL;
    }

    FS_Seek(hFile, EF_TEST_FILE_READ_POS, FS_FILE_BEGIN);

    if (0 != FS_Read(hFile, (void*)buf, len, &len))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_TEST_READ_FILE_READ_FAIL);
        mmi_spa_free(buf);
        FS_Close(hFile);
        return NULL;
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_TEST_READ_FILE_FINISH);
    FS_Close(hFile);
    *buf_len = (U16) len;
    return buf;
}
#endif /* __MMSICP_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_test_code_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_set_test_code_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hFile;
    S32 attr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hFile = FS_Open(EF_TEST_FILE_TEST_CODE_CONTROL, FS_CREATE_ALWAYS);
    if (hFile <= 0)
    {
        return;
    }

    FS_Close(hFile);

    /* Set it hidden file */
    attr = FS_GetAttributes(EF_TEST_FILE_TEST_CODE_CONTROL);
    attr |= FS_ATTR_HIDDEN;
    FS_SetAttributes(EF_TEST_FILE_TEST_CODE_CONTROL, (U8) attr);

    /* Set test code controlling variable */
    mmi_spa_test_code_open_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_test_code_off
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_set_test_code_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Delete(EF_TEST_FILE_TEST_CODE_CONTROL);
    mmi_spa_test_code_open_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_is_test_code_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_spa_is_test_code_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hFile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hFile = FS_Open(EF_TEST_FILE_TEST_CODE_CONTROL, FS_READ_ONLY);
    if (hFile <= 0)
    {
        return MMI_FALSE;
    }

    FS_Close(hFile);
    return MMI_TRUE;
}

#endif /* SPA_EF_TEST */ 

#ifdef MMI_SPA_JOB_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_add_sim_ef_jobs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_spa_add_sim_ef_jobs(mmi_spa_sim_id_enum sim_id, mmi_spa_job_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_ef_table_item_struct *item;
    U8 table_index;
    MMI_BOOL add_job = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ADD_SIM_EF_JOBS, sim_id, type);

    /* Add SIM1 EF jobs */
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ADD_SIM_EF_JOBS_ADD_SIM1_JOBS);

    if (sim_id == MMI_SPA_SIM_ID_SIM1 || sim_id == MMI_SPA_SIM_ID_DUAL_SIM)
    {
        table_index = 0;

        while (mmi_spa_is_valid_ef_tbl_item((mmi_spa_ef_table_item_struct*) & g_ef_table[table_index]))
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ADD_SIM_EF_JOBS_CUR_INDEX, table_index);

            item = g_ef_table + table_index;

            /* If EF is not open, just ignore it */
            if (MMI_SPA_CHECK_EF_STATUS_RESULT_ACTIVATED != item->ef_status_checker(MMI_SPA_SIM_ID_SIM1))
            {
                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ADD_SIM_EF_JOBS_EF_NOT_ACTIVATED);
                table_index++;
                continue;
            }

            /* Install SIM EF */
            if (type == MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE)
            {
                if (!mmi_spa_is_ef_installing(item, MMI_SPA_SIM_ID_SIM1) &&
                    !mmi_spa_get_ef_installed_flag(table_index, MMI_SPA_SIM_ID_SIM1))
                {
                    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ADD_SIM_EF_JOBS_ADD_SIM_INSTALL_JOB);
                    if (MMI_SPA_RESULT_OK == mmi_spa_insert_job(
                                                table_index,
                                                MMI_SPA_SIM_ID_SIM1,
                                                0,
                                                0,
                                                MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE))
                    {
                        mmi_spa_set_ef_installing(item, MMI_SPA_SIM_ID_SIM1);
                        add_job = MMI_TRUE;
                    }
                }
            }
        #ifdef __MMI_PROV_MESSAGE_SUPPORT__
            else if (type == MMI_SPA_JOB_TYPE_SAVE_TO_BOX)  /* Save SIM EF to Provisioning Inbox */
            {
                /* Add save job only if this EF is not saved and not being saving.
                   And if this EF is not installed and not being installing, don't save it */
                if (!mmi_spa_get_ef_saved_flag(table_index, MMI_SPA_SIM_ID_SIM1) &&
                    !mmi_spa_is_ef_saving(item, MMI_SPA_SIM_ID_SIM1) &&
                    (mmi_spa_get_ef_installed_flag(table_index, MMI_SPA_SIM_ID_SIM1) ||
                     mmi_spa_is_ef_installing(item, MMI_SPA_SIM_ID_SIM1)))
                {
                    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ADD_SIM_EF_JOBS_ADD_SIM_SAVE_JOB);
                    if (MMI_SPA_RESULT_OK == mmi_spa_insert_job(
                                                table_index,
                                                MMI_SPA_SIM_ID_SIM1,
                                                0,
                                                0,
                                                MMI_SPA_JOB_TYPE_SAVE_TO_BOX))
                    {
                        mmi_spa_set_ef_saving(item, MMI_SPA_SIM_ID_SIM1);
                        add_job = MMI_TRUE;
                    }
                }
            }
        #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

            table_index++;
        }
    }

    /* Add SIM2 EF jobs */
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ADD_SIM_EF_JOBS_ADD_SIM2_JOBS);

    if (sim_id == MMI_SPA_SIM_ID_SIM2 || sim_id == MMI_SPA_SIM_ID_DUAL_SIM)
    {
        table_index = 0;

        while (mmi_spa_is_valid_ef_tbl_item((mmi_spa_ef_table_item_struct*) & g_ef_table[table_index]))
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ADD_SIM_EF_JOBS_CUR_INDEX, table_index);

            item = g_ef_table + table_index;

            /* If EF is not open, just ignore it */
            if (MMI_SPA_CHECK_EF_STATUS_RESULT_ACTIVATED != item->ef_status_checker(MMI_SPA_SIM_ID_SIM2))
            {
                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_ADD_SIM_EF_JOBS_EF_NOT_ACTIVATED);
                table_index++;
                continue;
            }

            /* Install SIM EF */
            if (type == MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE)
            {
                if (!mmi_spa_is_ef_installing(item, MMI_SPA_SIM_ID_SIM2) &&
                    !mmi_spa_get_ef_installed_flag(table_index, MMI_SPA_SIM_ID_SIM2))
                {
                    if (MMI_SPA_RESULT_OK == mmi_spa_insert_job(
                                                table_index,
                                                MMI_SPA_SIM_ID_SIM2,
                                                0,
                                                0,
                                                MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE))
                    {
                        mmi_spa_set_ef_installing(item, MMI_SPA_SIM_ID_SIM2);
                        add_job = MMI_TRUE;
                    }
                }
            }
        #ifdef __MMI_PROV_MESSAGE_SUPPORT__
            else if (type == MMI_SPA_JOB_TYPE_SAVE_TO_BOX)  /* Save SIM EF to Provisioning Inbox */
            {
                /* Add save job only if this EF is not saved and not being saving.
                   And if this EF is not installed and not being installing, don't save it */
                if (!mmi_spa_get_ef_saved_flag(table_index, MMI_SPA_SIM_ID_SIM2) &&
                    !mmi_spa_is_ef_saving(item, MMI_SPA_SIM_ID_SIM2) &&
                    (mmi_spa_get_ef_installed_flag(table_index, MMI_SPA_SIM_ID_SIM2) ||
                     mmi_spa_is_ef_installing(item, MMI_SPA_SIM_ID_SIM2)))
                {
                    if (MMI_SPA_RESULT_OK == mmi_spa_insert_job(table_index, MMI_SPA_SIM_ID_SIM2, 0, 0, MMI_SPA_JOB_TYPE_SAVE_TO_BOX))
                    {
                        mmi_spa_set_ef_saving(item, MMI_SPA_SIM_ID_SIM2);
                        add_job = MMI_TRUE;
                    }
                }
            }
        #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

            table_index++;
        }
    }

    return add_job;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_remove_sim_ef_jobs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_remove_sim_ef_jobs(mmi_spa_sim_id_enum sim_id, mmi_spa_job_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_ef_process_job_node_struct *job;
    mmi_spa_ef_process_job_node_struct *next_job;
    mmi_spa_ef_table_item_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_REMOVE_SIM_EF_JOBS, sim_id, type);

    job = g_spa_ef_handler_context.job_list.head;

    while (job)
    {
        MMI_ASSERT(job->state == MMI_SPA_JOB_STATE_IDLE);

        /* This job will be removed */
        if (job->type == type && (job->sim_id == sim_id || sim_id == MMI_SPA_SIM_ID_DUAL_SIM))
        {
            item = g_ef_table + job->ef_info_table_index;

            if (type == MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE)
            {
                mmi_spa_clear_ef_installing(item, job->sim_id);
            }
        #ifdef __MMI_PROV_MESSAGE_SUPPORT__
            else if (type == MMI_SPA_JOB_TYPE_SAVE_TO_BOX)
            {
                mmi_spa_clear_ef_saving(item, job->sim_id);
            }
        #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 
            /* Delete node from list */
            next_job = job->next;
            mmi_spa_remove_job(job);
            job = next_job;
            continue;
        }

        job = job->next;
    }

    /* Check current job */
    job = g_spa_ef_handler_context.job_list.cur_job;

    if (job && (job->sim_id == sim_id || sim_id == MMI_SPA_SIM_ID_DUAL_SIM) && job->type == type)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_REMOVE_SIM_EF_JOBS_CANCEL_CUR_JOB);
        mmi_spa_cancel_cur_job();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_start_next_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_start_next_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_START_NEXT_JOB);

    /* There is running job */
    if (g_spa_ef_handler_context.job_list.cur_job)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_START_NEXT_JOB_NO_CUR_JOB);
        return;
    }

    /* No job to run */
    if (!g_spa_ef_handler_context.job_list.head)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_START_NEXT_JOB_NO_JOB);
        return;
    }

    /* Jobs in list must be IDLE */
    MMI_ASSERT(g_spa_ef_handler_context.job_list.head->state == MMI_SPA_JOB_STATE_IDLE);

    /* Pick the first job to run */
    g_spa_ef_handler_context.job_list.cur_job = g_spa_ef_handler_context.job_list.head;
    g_spa_ef_handler_context.job_list.head = g_spa_ef_handler_context.job_list.head->next;

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_START_NEXT_JOB_JOB_PARAM, g_spa_ef_handler_context.job_list.cur_job->type);

    switch (g_spa_ef_handler_context.job_list.cur_job->type)
    {
    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        case MMI_SPA_JOB_TYPE_SAVE_TO_BOX:
            mmi_spa_do_sim_save(g_spa_ef_handler_context.job_list.cur_job);
            break;
    #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 
        case MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE:
            mmi_spa_do_sim_install(g_spa_ef_handler_context.job_list.cur_job);
            break;
    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        case MMI_SPA_JOB_TYPE_INSTALL_BOX_PROFILE:
            mmi_spa_do_box_install(g_spa_ef_handler_context.job_list.cur_job);
            break;
    #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 
        default:
            /* MMI_ASSERT(0); */
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_START_NEXT_JOB_JOB_PARAM_ASSERT);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_do_sim_install
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_do_sim_install(mmi_spa_ef_process_job_node_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 trans_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Job must be IDLE and SIM must be available */
    MMI_ASSERT(mmi_spa_is_sim_available(job->sim_id));
    MMI_ASSERT(job->state == MMI_SPA_JOB_STATE_IDLE);

    /* Send new_setting_ind to CCA */
    mmi_spa_send_cca_new_setting_ind(job->sim_id, job->msg_id, &trans_id);
    /* Wait new_setting_rsp */
    mmi_spa_set_job_state(job, MMI_SPA_JOB_STATE_WATING_NEW_SETTING_RSP);

    job->trans_id = trans_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_new_setting_rsp_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  result          [IN]        
 *  trans_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_new_setting_rsp_handler(mmi_spa_sim_id_enum sim_id, mmi_spa_result_enum result, U32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_NEW_SETTING_RSP_HANDLER, sim_id);

    /* Check cur job */
    if (!g_spa_ef_handler_context.job_list.cur_job)
    {
        /* MMI_ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_NEW_SETTING_RSP_HANDLER_ASSERT);
        return;
    }

    /* Check trans id */
    if (trans_id != g_spa_ef_handler_context.job_list.cur_job->trans_id)
    {
        /* MMI_ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_NEW_SETTING_RSP_HANDLER_ASSERT1);
        return;
    }

    /* If SIM is disabled, this job should not be here */
    /* MMI_ASSERT(mmi_spa_is_sim_available(g_spa_ef_handler_context.job_list.cur_job->sim_id)); */
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CUR_JOB_TYPE, g_spa_ef_handler_context.job_list.cur_job->type);

    switch (g_spa_ef_handler_context.job_list.cur_job->type)
    {
        case MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE:
            mmi_spa_continue_sim_install(g_spa_ef_handler_context.job_list.cur_job);
            break;

    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        case MMI_SPA_JOB_TYPE_INSTALL_BOX_PROFILE:
            mmi_spa_continue_box_install(g_spa_ef_handler_context.job_list.cur_job);
            break;
    #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 
        default:
            /* MMI_ASSERT(0); */
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_NEW_SETTING_RSP_HANDLER_ASSERT2);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_continue_sim_install
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_continue_sim_install(mmi_spa_ef_process_job_node_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_result_enum ret;
    mmi_spa_ef_table_item_struct *ef_tbl_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CONTINUE_SIM_INSTALL, job->state);

    /* The job is cancelled, send empty new doc to end it */
    if (job->state == MMI_SPA_JOB_STATE_CANCELLING)
    {
        mmi_spa_send_empty_cca_new_doc(job->sim_id);
        return;
    }

    ef_tbl_item = g_ef_table + job->ef_info_table_index;

    MMI_ASSERT(ef_tbl_item->ef_status_checker);

    /* Not activate, stop this job */
    if (MMI_SPA_CHECK_EF_STATUS_RESULT_ACTIVATED != ef_tbl_item->ef_status_checker(job->sim_id))
    {
        /* Not install it again */
        mmi_spa_set_ef_installed_flag(job->ef_info_table_index, job->sim_id);
        /* Stop this job and start next */
        mmi_spa_stop_job(job);
        mmi_spa_start_next_job();
        return;
    }

    /* Read raw data from EF */
    MMI_ASSERT(ef_tbl_item->ef_reader);
    ret = ef_tbl_item->ef_reader(
                        job->sim_id,
                        ef_tbl_item->ef_file_idx,
                        ef_tbl_item->ef_file_type,
                        mmi_spa_job_ef_read_callback);

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_DO_SIM_SAVE_READ_RETURN, ret);

    /* Read fail, stop this file */
    if (ret != MMI_SPA_RESULT_OK)
    {
        /* Delete save job for this EF */
    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        mmi_spa_remove_sim_save_job_by_ef(job->ef_info_table_index, job->sim_id);
    #endif 
        mmi_spa_cancel_cur_job();
        mmi_spa_send_empty_cca_new_doc(job->sim_id);

        mmi_spa_release_read_context();
        return;
    }

    mmi_spa_set_job_state(job, MMI_SPA_JOB_STATE_READING_EF);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_install_ef_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_install_ef_profile(mmi_spa_ef_process_job_node_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hConfig;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_INSTALL_EF_PROFILE, job->state);

    /* The job is cancelled */
    if (job->state == MMI_SPA_JOB_STATE_CANCELLING)
    {
        /* Release buffer */
        if (g_spa_ef_read_context.buf)
        {
            mmi_spa_free(g_spa_ef_read_context.buf);
            g_spa_ef_read_context.buf = NULL;

        }
        mmi_spa_release_read_context();
        /* Send empty new doc */
        mmi_spa_send_empty_cca_new_doc(job->sim_id);
        return;
    }

    /* Parse and create document */
    if (MMI_SPA_RESULT_OK != mmi_spa_parse_and_create_cca_doc(
                                job,
                                g_spa_ef_read_context.buf,
                                g_spa_ef_read_context.file_len,
                                &hConfig))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_INSTALL_EF_PROFILE_PARSE_FAIL);

        if (g_spa_ef_read_context.buf)
        {
            mmi_spa_free(g_spa_ef_read_context.buf);
            g_spa_ef_read_context.buf = NULL;

        }
        mmi_spa_release_read_context();
    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        mmi_spa_remove_sim_save_job_by_ef(job->ef_info_table_index, job->sim_id);
    #endif 
        mmi_spa_cancel_cur_job();
        mmi_spa_send_empty_cca_new_doc(job->sim_id);
        return;
    }

    /* Update sim changed info */
    mmi_spa_update_sim_changed_flag();
    /* Send new doc ind */
    mmi_spa_send_cca_new_doc_ind(mmi_spa_get_sim_flag(), job->sim_id, hConfig);

    /* Wait new_doc_rsp */
    mmi_spa_set_job_state(job, MMI_SPA_JOB_STATE_INSTALLING);

    /* Release buffer */
    if (g_spa_ef_read_context.buf)
    {
        mmi_spa_free(g_spa_ef_read_context.buf);
        g_spa_ef_read_context.buf = NULL;

    }
    mmi_spa_release_read_context();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_parse_and_create_cca_doc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job             [IN]
 *  data            [IN]
 *  len             [IN]        
 *  hconfig_ret     [OUT]
 * RETURNS
 *  
 *****************************************************************************/
static mmi_spa_result_enum mmi_spa_parse_and_create_cca_doc(
                            mmi_spa_ef_process_job_node_struct *job,
                            U8 *data,
                            U16 len,
                            S32 *hconfig_ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_result_enum ret;
    mmi_spa_sim_mmsicp_parse_param_struct param;
    S32 hDeprel;
    S32 hConfig;
    S32 hRoot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_PARSE_AND_CREATE_CCA_DOC);

    *hconfig_ret = 0;

    /* Create hroot */
    hRoot = mmi_cca_doc_new_rootnode();

    if (!hRoot)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_HDLR_HROOT_FAIL);
        return MMI_SPA_RESULT_PARSE_CCA_ERROR;
    }

    /* parse */
    param.buf = data;
    param.len = (S32) len;
    param.hRoot = hRoot;

    ret = g_ef_table[job->ef_info_table_index].ef_parser(
                                                (void*)&param,
                                                g_ef_table[job->ef_info_table_index].ef_parser_callback);

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_READ_CALLBACK_PARSER_RET, ret);

    if (ret != MMI_SPA_RESULT_OK)
    {
        mmi_cca_docroot_release(hRoot);

        if ((ret == MMI_SPA_RESULT_PARSE_ERROR_LENGTH || ret == MMI_SPA_RESULT_PARSE_INVALID_DATA) &&
            job->type == MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE)
        {
            /* Error because of invalid content, so can't process again */
            mmi_spa_set_ef_installed_flag(job->ef_info_table_index, job->sim_id);
        }

        if (job->type == MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE)
        {
            mmi_spa_increase_ef_install_retry_count(job->ef_info_table_index, job->sim_id);
        }
        return ret;
    }

    /* validate and fix OMA document */
    mmi_cca_oma_fix_doc(hRoot);

    /* generate dependency relationship node */
    hDeprel = mmi_cca_oma_generate_deprel_node(hRoot);
    if (!hDeprel)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_FINALIZE_HANDLE_DEPREL_ERR);

        mmi_cca_docroot_release(hRoot);
        if (job->type == MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE)
        {
            mmi_spa_increase_ef_install_retry_count(job->ef_info_table_index, job->sim_id);
        }

        return MMI_SPA_RESULT_PARSE_CCA_ERROR;
    }

    mmi_cca_doc_attach_node_to_parent(hDeprel, hRoot);

    /* sort document */
    mmi_cca_oma_sort_new_doc(hRoot);

    /* construct CCA document */
    hConfig = mmi_cca_doc_new(hRoot);

    if (hConfig == 0)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_FINALIZE_HANDLE_DOC_NEW_ERR);

        mmi_cca_docroot_release(hRoot);
        if (job->type == MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE)
        {
            mmi_spa_increase_ef_install_retry_count(job->ef_info_table_index, job->sim_id);
        }

        return MMI_SPA_RESULT_PARSE_CCA_ERROR;
    }

    if (!mmi_spa_check_hconfig(hConfig))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_EF_FINALIZE_HANDLE_CHECK_CONFIG_ERR);

        mmi_cca_doc_release(hConfig);
        if (job->type == MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE)
        {
            mmi_spa_increase_ef_install_retry_count(job->ef_info_table_index, job->sim_id);
        }
        return MMI_SPA_RESULT_PARSE_ERROR;
    }

    *hconfig_ret = hConfig;

    return MMI_SPA_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_cca_new_doc_rsp_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]
 *  sim_id      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_cca_new_doc_rsp_handler(mmi_cca_source_new_doc_rsp_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_ef_process_job_node_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_NEW_DOC_RSP_HANDLER_JOB);

    /*  MMI_ASSERT(g_spa_ef_handler_context.job_list.cur_job); */
    if (!g_spa_ef_handler_context.job_list.cur_job)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_NEW_DOC_RSP_HANDLER_JOB_ASSERT);
        return;
    }

    job = g_spa_ef_handler_context.job_list.cur_job;

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_NEW_DOC_RSP_HANDLER_JOB_JOB_STATE, job->state, job->type);

    switch (job->type)
    {
        case MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE:
            mmi_spa_set_sim_changed_status_ok(mmi_spa_sim_id_converter_cca2spa((mmi_cca_sim_id_enum)data->sim_id));
    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
            mmi_spa_save_ef_msg_info(job, data);
    #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 
            mmi_spa_set_ef_installed_flag(job->ef_info_table_index, job->sim_id);
            mmi_spa_stop_job(job);
            mmi_spa_start_next_job();
            break;

    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        case MMI_SPA_JOB_TYPE_INSTALL_BOX_PROFILE:
            mmi_spa_send_cca_install_msg_cnf(job->sim_id, job->msg_id, job->src_trans_id, MMI_SPA_RESULT_OK);
            mmi_spa_stop_job(job);
            mmi_spa_start_next_job();
            break;
    #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 
        default:
            /* MMI_ASSERT(0); */
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_NEW_DOC_RSP_HANDLER_JOB_JOB_STATE_ASSERT);
            return;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_spa_is_job_type_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id        [IN]
 *  type      [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_spa_is_job_type_exist(mmi_spa_sim_id_enum sim_id, mmi_spa_job_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_ef_process_job_node_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = g_spa_ef_handler_context.job_list.head;
    while(job)
    {
        if (job->sim_id == sim_id &&
            job->type == type)
        {
            return MMI_TRUE;
        }
        job = job->next;
    }

    if (g_spa_ef_handler_context.job_list.cur_job &&
        g_spa_ef_handler_context.job_list.cur_job->sim_id == sim_id &&
        g_spa_ef_handler_context.job_list.cur_job->type == type)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_spa_cca_install_msg_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
void mmi_spa_cca_install_msg_req_handler(mmi_cca_source_install_prov_msg_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_INSTALL_MSG_REQ_HANDLER);

    mmi_spa_add_box_install_job(data);
    mmi_spa_start_next_job();
}
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_job_ef_read_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_job_ef_read_callback(mmi_spa_ef_read_result_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_ef_process_job_node_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_JOB_EF_READ_CALLBACK, result->result);

    /* ASSERT(g_spa_ef_handler_context.job_list.cur_job); */
    if (!g_spa_ef_handler_context.job_list.cur_job)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_JOB_EF_READ_CALLBACK_ASSERT);
        return;
    }

    job = g_spa_ef_handler_context.job_list.cur_job;

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_JOB_EF_READ_CALLBACK_JOB_STATE, job->state);

    /* Job is cancelled, stop it here. */
    if (job->state == MMI_SPA_JOB_STATE_CANCELLING)
    {
        /* Release buffer */
        if (result->buf)
        {
            mmi_spa_free(result->buf);
            result->buf = NULL;
        }
        mmi_spa_release_read_context();

        /* Stop cur job and start next one */
        if (job->type == MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE)
        {
            mmi_spa_cancel_cur_job();
            mmi_spa_send_empty_cca_new_doc(job->sim_id);
        }
        else
        {
            mmi_spa_stop_job(job);
            mmi_spa_start_next_job();
        }
        return;
    }

    /* Read fail */
    if (result->result != MMI_SPA_RESULT_OK ||
        result->buf[0] == 0xff)
    {
        if (result->buf[0] == 0xff)
        {
            result->result = MMI_SPA_RESULT_EMPTY_EF;
        }
        
        /* Release buffer */
        if (result->buf)
        {
            mmi_spa_free(result->buf);
            result->buf = NULL;
        }
        mmi_spa_release_read_context();

        /* File is no need process again */
    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        if (result->result == MMI_SPA_RESULT_IGNORE_THIS_FILE || result->result == MMI_SPA_RESULT_EMPTY_EF)
        {
            mmi_spa_set_ef_saved_flag(job->ef_info_table_index, job->sim_id);
        }
    #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

        /* Stop cur job and start next one */
        if (job->type == MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE)
        {
        #ifdef __MMI_PROV_MESSAGE_SUPPORT__
            mmi_spa_remove_sim_save_job_by_ef(job->ef_info_table_index, job->sim_id);
        #endif 
            mmi_spa_cancel_cur_job();
            mmi_spa_send_empty_cca_new_doc(job->sim_id);
        }
        else
        {
            mmi_spa_stop_job(job);
            mmi_spa_start_next_job();
        }

        return;
    }

    /* Read data from test file */
#ifdef SPA_EF_TEST
    if (mmi_spa_is_test_code_open())
    {
        mmi_spa_free(result->buf);
        result->buf = NULL;
        result->read_len = 0;

        result->buf = mmi_spa_ef_test_read_file(job->sim_id, &result->read_len);
        if (!result->buf)
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_TEST_READ_TEST_FILE_FAIL);

            mmi_spa_release_read_context();
            mmi_spa_stop_job(job);
            mmi_spa_start_next_job();

            return;
        }
    }
#endif /* SPA_EF_TEST */ 

    /* Save raw data */
    g_spa_ef_read_context.buf = result->buf;
    g_spa_ef_read_context.file_len = result->read_len;
    g_spa_ef_read_context.rec_num = result->rec_num;
    /* g_spa_ef_read_context.rec_size = result->read_len / result->rec_num; */

    mmi_spa_continue_job_after_read_ef(job);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_continue_job_after_read_ef
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_continue_job_after_read_ef(mmi_spa_ef_process_job_node_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CONTINUE_JOB_AFTER_READ_EF, job->type);

    /* State error, just return */
    if (job->state != MMI_SPA_JOB_STATE_READING_EF)
    {
        /* MMI_ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CONTINUE_JOB_AFTER_READ_EF_ASSERT);
        return;
    }

    switch (job->type)
    {
    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        case MMI_SPA_JOB_TYPE_SAVE_TO_BOX:
            mmi_spa_save_ef_to_box(job);
            break;
    #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 
        case MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE:
            mmi_spa_install_ef_profile(job);
            break;

        default:
            /* MMI_ASSERT(0); */
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CONTINUE_JOB_AFTER_READ_EF_ASSERT1);
            return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_stop_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_stop_job(mmi_spa_ef_process_job_node_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_STOP_JOB);

    /* Only cur job can be stopped in IDLE state */
    MMI_ASSERT(job == g_spa_ef_handler_context.job_list.cur_job);

    switch (job->type)
    {
    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        case MMI_SPA_JOB_TYPE_SAVE_TO_BOX:
            mmi_spa_clear_ef_saving(&g_ef_table[job->ef_info_table_index], job->sim_id);
            break;
    #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 
        case MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE:
            mmi_spa_clear_ef_installing(&g_ef_table[job->ef_info_table_index], job->sim_id);
            /* Delete save job for this EF */
            /* mmi_spa_remove_sim_save_job_by_ef(job->ef_info_table_index, job->sim_id); */
            break;

        default:
            break;
    }

    mmi_spa_free(job);
    g_spa_ef_handler_context.job_list.cur_job = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_job_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job         [IN]
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_job_state(mmi_spa_ef_process_job_node_struct *job, mmi_spa_job_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job->state = state;
}

#ifdef __MMI_PROV_MESSAGE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_ef_saved_state_in_table
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  saved_flags     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_set_ef_saved_state_in_table(mmi_spa_sim_id_enum sim_id, U16 saved_flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 table_index = 0;
    mmi_spa_ef_table_item_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SET_EF_SAVED_STATE_IN_TABLE, saved_flags);

    while (mmi_spa_is_valid_ef_tbl_item((mmi_spa_ef_table_item_struct*) & g_ef_table[table_index]))
    {
        item = g_ef_table + table_index;

        /* Check if sim1 ef is saved */
        if (sim_id == MMI_SPA_SIM_ID_SIM1)
        {
            if (item->ef_sim1_saved_flag_mask & saved_flags)
            {
                item->ef_processed_flag |= MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM1_SAVED;
            }
            else
            {
                item->ef_processed_flag &= ~MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM1_SAVED;
            }
        }

        /* Check if sim2 ef is saved */
        if (sim_id == MMI_SPA_SIM_ID_SIM2)
        {
            if (item->ef_sim2_saved_flag_mask & saved_flags)
            {
                item->ef_processed_flag |= MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM2_SAVED;
            }
            else
            {
                item->ef_processed_flag &= ~MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM2_SAVED;
            }
        }

        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SET_EF_SAVED_STATE_IN_TABLE_RESULT, table_index, item->ef_processed_flag);

        table_index++;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_ef_saved_state_in_table
 * DESCRIPTION
 *  
 * PARAMETERS
 *  saved_flags     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_get_ef_saved_state_in_table(U16 *saved_flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 table_index = 0;
    mmi_spa_ef_table_item_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_GET_EF_SAVED_STATE_IN_TABLE);

    while (mmi_spa_is_valid_ef_tbl_item((mmi_spa_ef_table_item_struct*) & g_ef_table[table_index]))
    {
        item = g_ef_table + table_index;

        /* Set SIM1 and SIM2 saved flag */
        *saved_flags |= item->ef_processed_flag & MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM1_SAVED;
        *saved_flags |= item->ef_processed_flag & MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM2_SAVED;

        table_index++;
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_GET_EF_SAVED_STATE_IN_TABLE_RESULT, *saved_flags);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_do_sim_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_do_sim_save(mmi_spa_ef_process_job_node_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_result_enum ret;
    mmi_spa_ef_table_item_struct *ef_tbl_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_DO_SIM_SAVE);

    /* Job must be IDLE and SIM must be available */
    MMI_ASSERT(mmi_spa_is_sim_available(job->sim_id));
    MMI_ASSERT(job->state == MMI_SPA_JOB_STATE_IDLE);

    /* check EF supported status */
    ef_tbl_item = g_ef_table + job->ef_info_table_index;

    /* MMI_ASSERT(ef_tbl_item->ef_status_checker); */

    /* Read raw data from EF. */
    MMI_ASSERT(ef_tbl_item->ef_reader);
    ret = ef_tbl_item->ef_reader(
                        job->sim_id,
                        ef_tbl_item->ef_file_idx,
                        ef_tbl_item->ef_file_type,
                        mmi_spa_job_ef_read_callback);

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_DO_SIM_SAVE_READ_RETURN, ret);

    /* Read fail */
    if (ret != MMI_SPA_RESULT_OK)
    {
        /* Stop this job, will retry save next time */
        /* mmi_spa_set_ef_saved_flag(job->ef_info_table_index, job->sim_id); */
        mmi_spa_stop_job(job);
        mmi_spa_start_next_job();
        return;
    }

    /* Wait for reading result, continue process in reading callback */
    mmi_spa_set_job_state(job, MMI_SPA_JOB_STATE_READING_EF);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_do_box_install
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_do_box_install(mmi_spa_ef_process_job_node_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_DO_BOX_INSTALL);

    MMI_ASSERT(job->state == MMI_SPA_JOB_STATE_IDLE);

    /* Start install directly */
    mmi_spa_continue_box_install(job);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_continue_box_install
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_continue_box_install(mmi_spa_ef_process_job_node_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 trans_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CONTINUE_BOX_INSTALL, job->state);

    /* The job is cancelled, send empty new doc to end it */
    if (job->state == MMI_SPA_JOB_STATE_CANCELLING)
    {
        mmi_spa_send_empty_cca_new_doc(job->sim_id);
        mmi_spa_send_cca_install_msg_cnf(
            job->sim_id,
            job->msg_id,
            job->src_trans_id,
            MMI_SPA_RESULT_PROVBOX_OP_CANCELLED);
        return;
    }

    /* Get data from ProvBox */
    mmi_spa_send_provbox_get_msg_data_req(job->msg_id, &trans_id);
    mmi_spa_set_job_state(job, MMI_SPA_JOB_STATE_GETTING_MSG_DATA);

    job->trans_id = trans_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_provbox_get_msg_data_cnf_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]
 * RETURNS
 *  
 *****************************************************************************/
mmi_spa_result_enum mmi_spa_provbox_get_msg_data_cnf_handler(mmi_provbox_get_msg_data_cnf_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *raw_data_buf = NULL;
    U8 ef_tbl_index;
    //mmi_spa_ef_table_item_struct *ef_tbl_item;
    S32 file_handle;
    U32 file_len;
    UINT read_len;
    S32 ret;
    S32 hConfig;
    mmi_spa_ef_process_job_node_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_PROVBOX_GET_MSG_DATA_CNF_HANDLER);

    job = g_spa_ef_handler_context.job_list.cur_job;

    /* MMI_ASSERT(job != NULL); */
    if (!job)
    {
        return MMI_SPA_RESULT_MSG_NOT_HANDLED;
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_PROVBOX_GET_MSG_DATA_CNF_HANDLER_JOB_STATE, job->state);

    /* Check trans id */
    if (job->trans_id != data->trans_id || job->state != MMI_SPA_JOB_STATE_GETTING_MSG_DATA)
    {
        return MMI_SPA_RESULT_MSG_NOT_HANDLED;
    }

    /* It is a cancelled job. When install from box, no cca_new_setting_ind sent,
       so no need send cca_new_doc and can do next job here directly */
    if (job->state == MMI_SPA_JOB_STATE_CANCELLING)
    {
        /* mmi_spa_send_empty_cca_new_doc(job->sim_id); */
        mmi_spa_send_cca_install_msg_cnf(
            job->sim_id,
            job->msg_id,
            job->src_trans_id,
            MMI_SPA_RESULT_PROVBOX_OP_CANCELLED);
        /* Free app data from ProvBox */
        if (data->app_data)
        {
            mmi_provbox_free_app_data(data->app_data);
            data->app_data = NULL;
        }

        /* Cancel this job */
        mmi_spa_stop_job(job);
        mmi_spa_start_next_job();
        return MMI_SPA_RESULT_OK;
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_PROVBOX_GET_MSG_DATA_CNF_HANDLER_DATA, data->result);

    /* Get meg data fail */
    if (data->result != SRV_PROVBOX_RESULT_OK || !data->app_data)
    {
        /* Invalid setting */
        mmi_spa_send_cca_invalid_setting_ind(job->sim_id, job->msg_id, CCA_STATUS_INVALID_SETTING);
        /* Install cnf */
        mmi_spa_send_cca_install_msg_cnf(
            job->sim_id,
            job->msg_id,
            job->src_trans_id,
            MMI_SPA_RESULT_PROVBOX_INVALID_MSG_DATA);

        /* Free app data */
        if (data->app_data)
        {
            mmi_provbox_free_app_data(data->app_data);
            data->app_data = NULL;
        }

        /* Cancel this job */
        mmi_spa_stop_job(job);
        mmi_spa_start_next_job();

        return MMI_SPA_RESULT_OK;
    }

    /* App data is ef table index */
    ef_tbl_index = mmi_spa_get_ef_tbl_index_from_app_data((mmi_spa_provbox_app_data_struct*)data->app_data);
    
    /* Free */
    mmi_provbox_free_app_data(data->app_data);
    data->app_data = NULL;

    /* Invalid index */
    if (ef_tbl_index >= mmi_spa_get_ef_table_size())
    {
        /* Invalid setting */
        mmi_spa_send_cca_invalid_setting_ind(job->sim_id, job->msg_id, CCA_STATUS_INVALID_SETTING);
        mmi_spa_send_cca_install_msg_cnf(
            job->sim_id,
            job->msg_id,
            job->src_trans_id,
            MMI_SPA_RESULT_PROVBOX_UNSUPPORTED_SETTING);

        /* Cancel this job */
        mmi_spa_stop_job(job);
        mmi_spa_start_next_job();

        return MMI_SPA_RESULT_OK;
    }

    /* Get ef info table item */
    //ef_tbl_item = g_ef_table + ef_tbl_index;

    /* Read file */
    file_handle = FS_Open(data->filename, FS_READ_ONLY);
    if (file_handle < FS_NO_ERROR)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_PROVBOX_GET_MSG_DATA_CNF_FILE_OPEN_FAIL);

        /* Invalid setting */
        mmi_spa_send_cca_invalid_setting_ind(job->sim_id, job->msg_id, CCA_STATUS_INVALID_SETTING);
        mmi_spa_send_cca_install_msg_cnf(
            job->sim_id,
            job->msg_id,
            job->src_trans_id,
            MMI_SPA_RESULT_PROVBOX_READ_BOX_FILE_FAIL);

        /* Cancel this job */
        mmi_spa_stop_job(job);
        mmi_spa_start_next_job();

        return MMI_SPA_RESULT_OK;
    }

    /* Get file size */
    ret = FS_GetFileSize(file_handle, &file_len);
    if (ret != FS_NO_ERROR || file_len == 0)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_PROVBOX_GET_MSG_DATA_CNF_GET_FILE_SIZE_FAIL);

        FS_Close(file_handle);
        /* Invalid setting */
        mmi_spa_send_cca_invalid_setting_ind(job->sim_id, job->msg_id, CCA_STATUS_INVALID_SETTING);
        mmi_spa_send_cca_install_msg_cnf(
            job->sim_id,
            job->msg_id,
            job->src_trans_id,
            MMI_SPA_RESULT_PROVBOX_EMPTY_BOX_FILE);

        /* Cancel this job */
        mmi_spa_stop_job(job);
        mmi_spa_start_next_job();

        return MMI_SPA_RESULT_OK;
    }

    /* Alloc buffer */
    raw_data_buf = mmi_spa_malloc(file_len);
    if (!raw_data_buf)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_PROVBOX_GET_MSG_DATA_CNF_MALLOC_BUF_FAIL);

        FS_Close(file_handle);
        /* Invalid setting */
        mmi_spa_send_cca_invalid_setting_ind(job->sim_id, job->msg_id, CCA_STATUS_INVALID_SETTING);
        mmi_spa_send_cca_install_msg_cnf(job->sim_id, job->msg_id, job->src_trans_id, MMI_SPA_RESULT_MEM_FULL);

        /* Cancel this job */
        mmi_spa_stop_job(job);
        mmi_spa_start_next_job();

        return MMI_SPA_RESULT_OK;
    }

    /* Read file */
    ret = FS_Read(file_handle, (void*)raw_data_buf, file_len, &read_len);
    if (ret != FS_NO_ERROR)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_PROVBOX_GET_MSG_DATA_CNF_READ_FILE_FAIL);

        FS_Close(file_handle);
        /* Invalid setting */
        mmi_spa_send_cca_invalid_setting_ind(job->sim_id, job->msg_id, CCA_STATUS_INVALID_SETTING);
        mmi_spa_send_cca_install_msg_cnf(
            job->sim_id,
            job->msg_id,
            job->src_trans_id,
            MMI_SPA_RESULT_PROVBOX_READ_BOX_FILE_FAIL);

        /* Cancel this job */
        mmi_spa_stop_job(job);
        mmi_spa_start_next_job();

        return MMI_SPA_RESULT_OK;
    }

    FS_Close(file_handle);

    /* Raw data read ok, create cca doc */
    if (MMI_SPA_RESULT_OK != mmi_spa_parse_and_create_cca_doc(job, raw_data_buf, (U16) file_len, &hConfig))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_PROVBOX_GET_MSG_DATA_CNF_PARSE_DATA_FAIL);

        /* Free buffer */
        if (raw_data_buf)
        {
            mmi_spa_free(raw_data_buf);
            raw_data_buf = NULL;
        }

        /* Invalid setting */
        mmi_spa_send_cca_invalid_setting_ind(job->sim_id, job->msg_id, CCA_STATUS_INVALID_SETTING);
        mmi_spa_send_cca_install_msg_cnf(job->sim_id, job->msg_id, job->src_trans_id, MMI_SPA_RESULT_PARSE_ERROR);

        /* Cancel this job */
        mmi_spa_stop_job(job);
        mmi_spa_start_next_job();

        return MMI_SPA_RESULT_OK;
    }

    /* Update sim changed info */
    mmi_spa_update_sim_changed_flag();
    /* Send new doc ind */
    mmi_spa_send_cca_new_doc_ind(mmi_spa_get_sim_flag(), job->sim_id, hConfig);

    mmi_spa_set_job_state(job, MMI_SPA_JOB_STATE_INSTALLING);

    if (raw_data_buf)
    {
        mmi_spa_free(raw_data_buf);
        raw_data_buf = NULL;

    }

    return MMI_SPA_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_ef_tbl_index_from_app_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_spa_get_ef_tbl_index_from_app_data(mmi_spa_provbox_app_data_struct *app_data)
{
    sim_file_index_enum file_idx;
    U8 ef_tbl_index = 0;
    
    if (!app_data)
    {
        return mmi_spa_get_ef_table_size();
    }

    file_idx = app_data->file_index;
    while(mmi_spa_is_valid_ef_tbl_item((mmi_spa_ef_table_item_struct*) & g_ef_table[ef_tbl_index]))
    {
        if (g_ef_table[ef_tbl_index].ef_file_idx == file_idx)
        {
            return ef_tbl_index;
        }
        ef_tbl_index++;
    }

    return ef_tbl_index + 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_provbox_save_msg_available_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_provbox_save_msg_available_ind_handler(mmi_provbox_save_msg_available_ind_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL sim1_available = MMI_FALSE;
    MMI_BOOL sim2_available = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_PROVBOX_SAVE_MSG_AVAILABLE_IND_HANDLER);

    sim1_available = mmi_spa_is_sim_available(MMI_SPA_SIM_ID_SIM1);
    sim2_available = mmi_spa_is_sim_available(MMI_SPA_SIM_ID_SIM2);

    MMI_TRACE(
        SPA_TRACE_INFO,
        TRC_MMI_SPA_PROVBOX_SAVE_MSG_AVAILABLE_IND_HANDLER_SIM_AVAILABLE,
        sim1_available,
        sim2_available);

    /* sim save jobs */
    if (sim1_available)
    {
        mmi_spa_add_sim_ef_jobs(MMI_SPA_SIM_ID_SIM1, MMI_SPA_JOB_TYPE_SAVE_TO_BOX);
    }
    if (sim2_available)
    {
        mmi_spa_add_sim_ef_jobs(MMI_SPA_SIM_ID_SIM2, MMI_SPA_JOB_TYPE_SAVE_TO_BOX);
    }
    mmi_spa_start_next_job();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_save_ef_msg_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job         [IN/OUT]
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_save_ef_msg_info(mmi_spa_ef_process_job_node_struct *job, mmi_cca_source_new_doc_rsp_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ef_tbl_index;
    mmi_spa_ef_table_item_struct *ef_tbl_item;
    mmi_spa_ef_msg_info_struct *msg_info_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SAVE_EF_MSG_INFO);

    /* get ef table index */
    ef_tbl_index = job->ef_info_table_index;

    /* Invalid index */
    if (ef_tbl_index >= mmi_spa_get_ef_table_size())
    {
        /* MMI_ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SAVE_EF_MSG_INFO_ASSERT);
        return;
    }

    /* Will not save this EF to ProvBox because it has been saved,
       so config result is not stored here */
    if (mmi_spa_get_ef_saved_flag(ef_tbl_index, job->sim_id))
    {
        return;
    }

    ef_tbl_item = g_ef_table + ef_tbl_index;

    if (job->sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        if (!ef_tbl_item->ef_msg_info.sim1_info)
        {
            ef_tbl_item->ef_msg_info.sim1_info = mmi_spa_malloc(sizeof(mmi_spa_ef_msg_info_struct));
            if (!ef_tbl_item->ef_msg_info.sim1_info)
            {
                /* MMI_ASSERT(0); */
                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SAVE_EF_MSG_INFO_ASSERT1);
                return;
            }
        }
        msg_info_item = ef_tbl_item->ef_msg_info.sim1_info;
    }
    else if (job->sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        if (!ef_tbl_item->ef_msg_info.sim2_info)
        {
            ef_tbl_item->ef_msg_info.sim2_info = mmi_spa_malloc(sizeof(mmi_spa_ef_msg_info_struct));
            if (!ef_tbl_item->ef_msg_info.sim2_info)
            {
                /* MMI_ASSERT(0); */
                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SAVE_EF_MSG_INFO_ASSERT2);
                return;
            }
        }
        msg_info_item = ef_tbl_item->ef_msg_info.sim2_info;
    }
    else
    {
        /* MMI_ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SAVE_EF_MSG_INFO_ASSERT3);
        return;
    }

    /* Save config status to msg_info_item->msg_config_status */
    mmi_spa_set_config_results(&msg_info_item->msg_config_status, data);
    msg_info_item->install_timestamp = mmi_spa_get_timestamp();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_config_results
 * DESCRIPTION
 *  
 * PARAMETERS
 *  provbox_result      [OUT]
 *  cca_result          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_config_results(
                mmi_provbox_msg_config_status_struct *provbox_result,
                mmi_cca_source_new_doc_rsp_struct *cca_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    provbox_result->app_num = MMI_SPA_MIN(MMI_PROVBOX_MAX_APP_INFO_NUM, cca_result->config_num);
    provbox_result->config_status = mmi_spa_config_status_convert_cca2provbox(cca_result->msg_config_result);
    memset(provbox_result->app_config_status, 0, sizeof(provbox_result->app_config_status));

    for (i = 0; i < provbox_result->app_num; i++)
    {
        provbox_result->app_config_status[i].config_id = mmi_spa_config_id_convert_cca2provbox(cca_result->app_config_result[i].config_id);
        provbox_result->app_config_status[i].status = mmi_spa_config_status_convert_cca2provbox(cca_result->app_config_result[i].result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_config_id_convert_cca2provbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cca_config_id       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_provbox_config_id_enum mmi_spa_config_id_convert_cca2provbox(U16 cca_config_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cca_config_id)
    {
        case CCA_CONFIG_INVALID:
            return MMI_PROVBOX_CONFIG_ID_INVALID;

        case CCA_CONFIG_TEST:
            return MMI_PROVBOX_CONFIG_ID_TEST;

        case CCA_CONFIG_DTACCT:
            return MMI_PROVBOX_CONFIG_ID_DATAACCOUNT;
        case CCA_CONFIG_WLAN:
            return MMI_PROVBOX_CONFIG_ID_WLAN;

        case CCA_CONFIG_BROWSER:
            return MMI_PROVBOX_CONFIG_ID_BROWSER;

        case CCA_CONFIG_MMS:
            return MMI_PROVBOX_CONFIG_ID_MMS;

        case CCA_CONFIG_SIP:
            return MMI_PROVBOX_CONFIG_ID_SIP;

        case CCA_CONFIG_IMPS:
            return MMI_PROVBOX_CONFIG_ID_IMPS;

        case CCA_CONFIG_EMAIL:
            return MMI_PROVBOX_CONFIG_ID_EMAIL;

        case CCA_CONFIG_SYNCMLDS:
            return MMI_PROVBOX_CONFIG_ID_SYNCMLDS;

        case CCA_CONFIG_SYNCMLDM:
            return MMI_PROVBOX_CONFIG_ID_SYNCMLDM;

        case CCA_CONFIG_PUSH:
            return MMI_PROVBOX_CONFIG_ID_PUSH;

    #ifdef __MMI_WLAN_OTAP_DMP__
        case CCA_CONFIG_WLAN_DMP:
            return MMI_PROVBOX_CONFIG_ID_WLAN_DMP;
    #endif /* __MMI_WLAN_OTAP_DMP__ */ 

    #ifdef __MMI_VOIP_OTAP_DMP__
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_VOIP_OTAP_DMP__ */ 

    case CCA_CONFIG_RTSP:
        return MMI_PROVBOX_CONFIG_ID_RTSP;

    case CCA_CONFIG_SUPL:
        return MMI_PROVBOX_CONFIG_ID_SUPL;
    
        default:
            return MMI_PROVBOX_CONFIG_ID_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_config_status_convert_cca2provbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cca_status      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_provbox_config_status_enum mmi_spa_config_status_convert_cca2provbox(cca_status_enum cca_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cca_status)
    {
        case CCA_STATUS_OK:
            return MMI_PROVBOX_CONFIG_STATUS_CONFIGED;

        case CCA_STATUS_FAIL:
            return MMI_PROVBOX_CONFIG_STATUS_FAILED;

        case CCA_STATUS_INVALID_SETTING:
            return MMI_PROVBOX_CONFIG_STATUS_INVALID;

        case CCA_STATUS_SETTING_UPDATED:
            return MMI_PROVBOX_CONFIG_STATUS_UPDATED;

        case CCA_STATUS_SETTING_SKIPPED:
            return MMI_PROVBOX_CONFIG_STATUS_SKIPPED;

        case CCA_STATUS_SETTING_NOT_INSTALLED:
            return MMI_PROVBOX_CONFIG_STATUS_NOT_INSTALLED;

        case CCA_STATUS_UNSUPPORTED_SETTING:
            return MMI_PROVBOX_CONFIG_STATUS_UNSUPPORTED;

        case CCA_STATUS_CORRUPTED_SETTING:
            return MMI_PROVBOX_CONFIG_STATUS_CORRUPTED;

        case CCA_STATUS_MISSING_DATA:
            return MMI_PROVBOX_CONFIG_STATUS_MISSING_DATA;

        case CCA_STATUS_SETTING_NOAPP:
            return MMI_PROVBOX_CONFIG_STATUS_NOAPP;

        default:
            return MMI_PROVBOX_CONFIG_STATUS_NOT_INSTALLED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_clear_ef_msg_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ef_tbl_index        [IN]        
 *  sim_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_clear_ef_msg_info(U8 ef_tbl_index, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_ef_table_item_struct *ef_tbl_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CLEAR_EF_MSG_INFO, ef_tbl_index, sim_id);

    /* Invalid index */
    if (ef_tbl_index >= mmi_spa_get_ef_table_size())
    {
        /* MMI_ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CLEAR_EF_MSG_INFO_ASSERT);
        return;
    }

    ef_tbl_item = g_ef_table + ef_tbl_index;

    if (sim_id == MMI_SPA_SIM_ID_SIM1 && ef_tbl_item->ef_msg_info.sim1_info)
    {
        mmi_spa_free(ef_tbl_item->ef_msg_info.sim1_info);
        ef_tbl_item->ef_msg_info.sim1_info = NULL;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2 && ef_tbl_item->ef_msg_info.sim2_info)
    {
        mmi_spa_free(ef_tbl_item->ef_msg_info.sim2_info);
        ef_tbl_item->ef_msg_info.sim2_info = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_timestamp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static U32 mmi_spa_get_timestamp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get cur time */
    applib_dt_get_rtc_time(&time);
    /* Cur time to utc */
    /* return applib_dt_mytime_2_utc_sec(&time, MMI_FALSE); */
    return applib_dt_sec_local_to_utc(applib_dt_mytime_2_utc_sec(&time, MMI_FALSE));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_add_box_install_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_add_box_install_job(mmi_cca_source_install_prov_msg_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Add a new job of type MMI_SPA_JOB_TYPE_INSTALL_BOX_PROFILE */
    if (MMI_SPA_RESULT_OK != mmi_spa_insert_job(
                                0,
                                mmi_spa_sim_id_converter_cca2spa((mmi_cca_sim_id_enum)data->sim_id),
                                data->msg_id,
                                data->trans_id,
                                MMI_SPA_JOB_TYPE_INSTALL_BOX_PROFILE))
    {
        mmi_spa_send_cca_install_msg_cnf((mmi_spa_sim_id_enum)data->sim_id, data->msg_id, data->trans_id, MMI_SPA_RESULT_MEM_FULL);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_save_ef_to_box
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_save_ef_to_box(mmi_spa_ef_process_job_node_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 trans_id;
    mmi_provbox_save_msg_req_struct msg_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SAVE_EF_TO_BOX);

    /* Fill msg data with prov data and app data */
    mmi_spa_set_msg_cmn_info(&msg_data, job);
    mmi_spa_set_msg_config_info(&msg_data, job);

    g_spa_ef_handler_context.app_data.file_index = g_ef_table[job->ef_info_table_index].ef_file_idx;
    mmi_spa_set_msg_data(
        &msg_data,
        (void*)&g_spa_ef_handler_context.app_data,
        (U16) sizeof(mmi_spa_provbox_app_data_struct),
        MMI_PROVBOX_SAVE_DATA_TYPE_RAW_DATA,
        g_spa_ef_read_context.file_len,
        (void*)g_spa_ef_read_context.buf,
        NULL);

    /* Send save req */
    mmi_spa_send_provbox_save_msg_data_req(job->sim_id, MMI_PROVBOX_MSG_TYPE_SIM_MMSICP, &msg_data, &trans_id);

    /* Wait saving result */
    job->trans_id = trans_id;
    mmi_spa_set_job_state(job, MMI_SPA_JOB_STATE_SAVING_MSG_DATA);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_msg_cmn_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_data        [OUT]
 *  job             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_msg_cmn_info(
                mmi_provbox_save_msg_req_struct *msg_data,
                mmi_spa_ef_process_job_node_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_ef_table_item_struct *ef_tbl_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SET_MSG_CMN_INFO);

    /* Get ef table item */
    if (job->ef_info_table_index >= mmi_spa_get_ef_table_size())
    {
        /* MMI_ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SET_MSG_CMN_INFO_ASSERT);
        memset(&msg_data->cmn_info, 0, sizeof(mmi_provbox_msg_cmn_info_struct));
        return;
    }

    ef_tbl_item = g_ef_table + job->ef_info_table_index;

    msg_data->cmn_info.msg_id = MMI_PROVBOX_INVALID_MSG_ID;
    msg_data->cmn_info.msg_type = MMI_PROVBOX_MSG_TYPE_SIM_MMSICP;
    /* msg_data->cmn_info.sim_id = job->sim_id; */
    msg_data->cmn_info.src_id = MMI_PROVBOX_SOURCE_ID_SPA;
    msg_data->cmn_info.box_type = MMI_PROVBOX_BOX_TYPE_UNKNOWN;
    /* SIM provisioning sender address is displayed by ProvBoxUI by its SIM id */
    memset(&msg_data->cmn_info.sender_addr, 0, sizeof(mmi_provbox_addr_struct));

    /* Installed */
    if (mmi_spa_get_ef_installed_flag(job->ef_info_table_index, job->sim_id))
    {
        msg_data->cmn_info.read_status = MMI_PROVBOX_MSG_READ_STATUS_READ;
        if (job->sim_id == MMI_SPA_SIM_ID_SIM1 && ef_tbl_item->ef_msg_info.sim1_info)
        {
            msg_data->cmn_info.install_time = ef_tbl_item->ef_msg_info.sim1_info->install_timestamp;
        }
        else if (job->sim_id == MMI_SPA_SIM_ID_SIM2 && ef_tbl_item->ef_msg_info.sim2_info)
        {
            msg_data->cmn_info.install_time = ef_tbl_item->ef_msg_info.sim2_info->install_timestamp;
        }
        else
        {
            msg_data->cmn_info.install_time = 0;
        }

        msg_data->cmn_info.timestamp = mmi_spa_get_timestamp();
    }
    else
    {
        msg_data->cmn_info.read_status = MMI_PROVBOX_MSG_READ_STATUS_UNREAD;
        msg_data->cmn_info.install_time = 0;
        msg_data->cmn_info.timestamp = mmi_spa_get_timestamp();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_msg_config_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_data        [OUT]
 *  job             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_msg_config_info(
                mmi_provbox_save_msg_req_struct *msg_data,
                mmi_spa_ef_process_job_node_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_ef_table_item_struct *ef_tbl_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SET_MSG_CONFIG_INFO);

    /* Get ef table item */
    if (job->ef_info_table_index >= mmi_spa_get_ef_table_size())
    {
        /* MMI_ASSERT(0); */
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SET_MSG_CONFIG_INFO_ASSERT);
        memset(&msg_data->cmn_info, 0, sizeof(mmi_provbox_msg_cmn_info_struct));
        return;
    }

    ef_tbl_item = g_ef_table + job->ef_info_table_index;

    if (mmi_spa_get_ef_installed_flag(job->ef_info_table_index, job->sim_id))
    {
        if (job->sim_id == MMI_SPA_SIM_ID_SIM1 && ef_tbl_item->ef_msg_info.sim1_info)
        {
            memcpy(
                &msg_data->msg_config_status,
                &ef_tbl_item->ef_msg_info.sim1_info->msg_config_status,
                sizeof(mmi_provbox_msg_config_status_struct));
        }
        else if (job->sim_id == MMI_SPA_SIM_ID_SIM2 && ef_tbl_item->ef_msg_info.sim2_info)
        {
            memcpy(
                &msg_data->msg_config_status,
                &ef_tbl_item->ef_msg_info.sim2_info->msg_config_status,
                sizeof(mmi_provbox_msg_config_status_struct));
        }
        else
        {
            memset(&msg_data->msg_config_status, 0, sizeof(mmi_provbox_msg_config_status_struct));
            msg_data->msg_config_status.config_status = MMI_PROVBOX_CONFIG_STATUS_CONFIGED;
        }
    }
    else
    {
        memset(&msg_data->msg_config_status, 0, sizeof(mmi_provbox_msg_config_status_struct));
        msg_data->msg_config_status.config_status = MMI_PROVBOX_CONFIG_STATUS_NOT_INSTALLED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_msg_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_data            [OUT]
 *  app_data            [IN]
 *  app_data_size       [IN]        
 *  data_type           [IN]        
 *  prov_data_size      [IN]        
 *  prov_data           [IN]
 *  prov_file           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_msg_data(
                mmi_provbox_save_msg_req_struct *msg_data,
                void *app_data,
                S16 app_data_size,
                mmi_provbox_save_data_type_enum data_type,
                S16 prov_data_size,
                void *prov_data,
                U16 *prov_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_SET_MSG_DATA);

    msg_data->msg_data.app_data = app_data;
    msg_data->msg_data.app_data_size = app_data_size;
    msg_data->msg_data.prov_data_type = data_type;
    msg_data->msg_data.prov_data_size = prov_data_size;
    msg_data->msg_data.prov_data = prov_data;
    msg_data->msg_data.prov_file = prov_file;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_provbox_save_msg_data_cnf_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_provbox_save_msg_data_cnf_handler(mmi_provbox_save_msg_cnf_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_ef_process_job_node_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_PROVBOX_SAVE_MSG_DATA_CNF_HANDLER, data->result);

    /* Check cur job */
    /* ASSERT(g_spa_ef_handler_context.job_list.cur_job); */
    if (!g_spa_ef_handler_context.job_list.cur_job)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_PROVBOX_SAVE_MSG_DATA_CNF_HANDLER_ASSERT);
        return;
    }
    job = g_spa_ef_handler_context.job_list.cur_job;

    /* Check trans id */
    if (job->trans_id != data->trans_id)
    {
        return;
    }

    /* Save end, release buffer */
    if (g_spa_ef_read_context.buf)
    {
        mmi_spa_free(g_spa_ef_read_context.buf);
        g_spa_ef_read_context.buf = NULL;
    }
    mmi_spa_release_read_context();

    /* Save success, set EF save flag */
    if (data->result == SRV_PROVBOX_RESULT_OK)
    {
        /* Will not save this EF again */
        mmi_spa_set_ef_saved_flag(job->ef_info_table_index, job->sim_id);
        mmi_spa_clear_ef_msg_info(job->ef_info_table_index, job->sim_id);
    }

    job->state = MMI_SPA_JOB_STATE_IDLE;

    /* Stop this job and start next one */
    mmi_spa_stop_job(job);
    mmi_spa_start_next_job();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_remove_sim_save_job_by_ef
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ef_index        [IN]        
 *  sim_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_remove_sim_save_job_by_ef(U8 ef_index, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_ef_process_job_node_struct *job = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_spa_ef_handler_context.job_list.head)
    {
        return;
    }

    job = g_spa_ef_handler_context.job_list.head;
    while (job)
    {
        if (job->type == MMI_SPA_JOB_TYPE_SAVE_TO_BOX && job->ef_info_table_index == ef_index && job->sim_id == sim_id)
        {
            mmi_spa_clear_ef_saving(&g_ef_table[ef_index], sim_id);
            mmi_spa_remove_job(job);
            break;
        }
        job = job->next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_ef_saved_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ef_tbl_index        [IN]        
 *  sim_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_ef_saved_flag(U8 ef_tbl_index, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        g_ef_table[ef_tbl_index].ef_processed_flag |= MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM1_SAVED;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        g_ef_table[ef_tbl_index].ef_processed_flag |= MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM2_SAVED;
    }

    /* Save saved status in NVRAM */
    mmi_spa_write_ef_saved_flag_to_nvram();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_ef_saved_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ef_tbl_index        [IN]        
 *  sim_id              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_spa_get_ef_saved_flag(U8 ef_tbl_index, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_GET_EF_SAVED_FLAG, sim_id, g_ef_table[ef_tbl_index].ef_processed_flag);

    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        return ((g_ef_table[ef_tbl_index].ef_processed_flag & MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM1_SAVED) ==
                MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM1_SAVED);
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        return ((g_ef_table[ef_tbl_index].ef_processed_flag & MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM2_SAVED) ==
                MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM2_SAVED);
    }
    return MMI_FALSE;
}
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_ef_installed_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ef_tbl_index        [IN]        
 *  sim_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_ef_installed_flag(U8 ef_tbl_index, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        g_ef_table[ef_tbl_index].ef_processed_flag |= MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM1_INSTALLED;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        g_ef_table[ef_tbl_index].ef_processed_flag |= MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM2_INSTALLED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_ef_installed_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ef_tbl_index        [IN]        
 *  sim_id              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_spa_get_ef_installed_flag(U8 ef_tbl_index, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        SPA_TRACE_INFO,
        TRC_MMI_SPA_GET_EF_INSTALLED_FLAG,
        ef_tbl_index,
        sim_id,
        g_ef_table[ef_tbl_index].ef_processed_flag);

    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        return ((g_ef_table[ef_tbl_index].ef_processed_flag & MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM1_INSTALLED) ==
                MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM1_INSTALLED);
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        return ((g_ef_table[ef_tbl_index].ef_processed_flag & MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM2_INSTALLED) ==
                MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM2_INSTALLED);
    }
    /* MMI_ASSERT(0); */
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_increase_ef_install_retry_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ef_tbl_index        [IN]        
 *  sim_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_increase_ef_install_retry_count(U8 ef_tbl_index, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = mmi_spa_get_ef_install_retry_count(ef_tbl_index, sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (count >= MMI_SPA_MAX_SIM_READ_MAX_RETRY_COUNT)
    {
        return;
    }

    count++;

    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        g_ef_table[ef_tbl_index].ef_processed_flag |= ((count << 4) & MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM1_INSTALLED);
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        g_ef_table[ef_tbl_index].ef_processed_flag |= ((count << 6) & MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM2_INSTALLED);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_get_ef_install_retry_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ef_tbl_index        [IN]        
 *  sim_id              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_spa_get_ef_install_retry_count(U8 ef_tbl_index, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        return (g_ef_table[ef_tbl_index].ef_processed_flag &
                MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM1_PROCESSED_COUNT_MASK) >> 4;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        return (g_ef_table[ef_tbl_index].ef_processed_flag &
                MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM2_PROCESSED_COUNT_MASK) >> 6;
    }
    else
    {
        /* MMI_ASSERT(0); */
        return MMI_SPA_MAX_SIM_READ_MAX_RETRY_COUNT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_insert_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ef_tbl_index        [IN]        
 *  sim_id              [IN]        
 *  msg_id              [IN]        
 *  trans_id            [IN]        
 *  type                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_spa_result_enum mmi_spa_insert_job(
                            U8 ef_tbl_index,
                            mmi_spa_sim_id_enum sim_id,
                            U32 msg_id,
                            U32 trans_id,
                            mmi_spa_job_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_ef_process_job_node_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item = mmi_spa_malloc(sizeof(mmi_spa_ef_process_job_node_struct));
    if (!item)
    {
        return MMI_SPA_RESULT_MEM_FULL;
    }

    item->ef_info_table_index = ef_tbl_index;
    item->sim_id = sim_id;
    item->type = type;
    item->state = MMI_SPA_JOB_STATE_IDLE;
    item->next = NULL;
    item->msg_id = msg_id;
    item->src_trans_id = trans_id;
    item->trans_id = 0;

    mmi_spa_insert_job_list_node(item);

    return MMI_SPA_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_remove_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_remove_job(mmi_spa_ef_process_job_node_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(item);
    MMI_ASSERT(item->state == MMI_SPA_JOB_STATE_IDLE);
    mmi_spa_delete_job_list_node(item);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_cancel_cur_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_cancel_cur_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CANCEL_CUR_JOB);

    /* No cur job */
    if (!g_spa_ef_handler_context.job_list.cur_job)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CANCEL_CUR_JOB_NO_CUR_JOB);
        return;
    }

    MMI_TRACE(
        SPA_TRACE_INFO,
        TRC_MMI_SPA_CANCEL_CUR_JOB_NO_CUR_JOB_STATE,
        g_spa_ef_handler_context.job_list.cur_job->state);

    /* Cur job is IDLE, delete it directly */
    if (g_spa_ef_handler_context.job_list.cur_job->state == MMI_SPA_JOB_STATE_IDLE)
    {
        mmi_spa_remove_job(g_spa_ef_handler_context.job_list.cur_job);
        g_spa_ef_handler_context.job_list.cur_job = NULL;
        return;
    }

    g_spa_ef_handler_context.job_list.cur_job->state = MMI_SPA_JOB_STATE_CANCELLING;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_insert_job_list_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_insert_job_list_node(mmi_spa_ef_process_job_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_ef_process_job_node_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = g_spa_ef_handler_context.job_list.head;

    if (!job)
    {
        g_spa_ef_handler_context.job_list.head = node;
        g_spa_ef_handler_context.job_list.head->next = NULL;
        return;
    }

    while (job->next)
    {
        job = job->next;
    }

    job->next = node;
    node->next = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_delete_job_list_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_delete_job_list_node(mmi_spa_ef_process_job_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_ef_process_job_node_struct *job;
    mmi_spa_ef_process_job_node_struct *prev_job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(node);

    job = g_spa_ef_handler_context.job_list.head;

    /* empty list */
    if (!job)
    {
        return;
    }
    else if (job == node)   /* Delete head */
    {
        g_spa_ef_handler_context.job_list.head = job->next;
        mmi_spa_free(node);
    }
    else
    {
        prev_job = job;
        job = job->next;

        while (job && job != node)
        {
            prev_job = job;
            job = job->next;
        }

        if (job == node)
        {
            prev_job->next = job->next;
            mmi_spa_free(node);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_is_ef_installing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ef_item     [IN]
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_spa_is_ef_installing(mmi_spa_ef_table_item_struct *ef_item, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_IS_EF_INSTALLING, sim_id, ef_item->ef_job_state_flag);

    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        if (ef_item->ef_job_state_flag & MMI_SPA_FLAG_EF_JOB_STATE_SIM1_INSTALLING)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        if (ef_item->ef_job_state_flag & MMI_SPA_FLAG_EF_JOB_STATE_SIM2_INSTALLING)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_ef_installing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ef_item     [OUT]
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_ef_installing(mmi_spa_ef_table_item_struct *ef_item, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        ef_item->ef_job_state_flag |= MMI_SPA_FLAG_EF_JOB_STATE_SIM1_INSTALLING;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        ef_item->ef_job_state_flag |= MMI_SPA_FLAG_EF_JOB_STATE_SIM2_INSTALLING;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_clear_ef_installing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ef_item     [OUT]
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_clear_ef_installing(mmi_spa_ef_table_item_struct *ef_item, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        ef_item->ef_job_state_flag &= ~MMI_SPA_FLAG_EF_JOB_STATE_SIM1_INSTALLING;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        ef_item->ef_job_state_flag &= ~MMI_SPA_FLAG_EF_JOB_STATE_SIM2_INSTALLING;
    }
}

#ifdef __MMI_PROV_MESSAGE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_is_ef_saving
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ef_item     [IN]
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_spa_is_ef_saving(mmi_spa_ef_table_item_struct *ef_item, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_IS_EF_SAVING, sim_id, ef_item->ef_job_state_flag);

    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        if (ef_item->ef_job_state_flag & MMI_SPA_FLAG_EF_JOB_STATE_SIM1_SAVING)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        if (ef_item->ef_job_state_flag & MMI_SPA_FLAG_EF_JOB_STATE_SIM2_SAVING)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_set_ef_saving
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ef_item     [OUT]
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_set_ef_saving(mmi_spa_ef_table_item_struct *ef_item, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        ef_item->ef_job_state_flag |= MMI_SPA_FLAG_EF_JOB_STATE_SIM1_SAVING;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        ef_item->ef_job_state_flag |= MMI_SPA_FLAG_EF_JOB_STATE_SIM2_SAVING;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_clear_ef_saving
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ef_item     [OUT
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_clear_ef_saving(mmi_spa_ef_table_item_struct *ef_item, mmi_spa_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SPA_SIM_ID_SIM1)
    {
        ef_item->ef_job_state_flag &= ~MMI_SPA_FLAG_EF_JOB_STATE_SIM1_SAVING;
    }
    else if (sim_id == MMI_SPA_SIM_ID_SIM2)
    {
        ef_item->ef_job_state_flag &= ~MMI_SPA_FLAG_EF_JOB_STATE_SIM2_SAVING;
    }
}

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

#endif /* MMI_SPA_JOB_SUPPORT */ 

#endif /* __SPA_SUPPORT__ */ 

