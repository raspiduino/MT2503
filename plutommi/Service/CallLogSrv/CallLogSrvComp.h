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
 * CallLogSrvComp.h 
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef SRV_CALL_LOG_COMP_H
#define SRV_CALL_LOG_COMP_H

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "kal_general_types.h"

#include "custom_phb_config.h"

#include "MMIDataType.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvStore.h"
#include "CallLogSrvProt.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#ifdef __MMI_CLOG_SLIM_FOR_MT6261__

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* typedef in structure                                                       */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Extern Function                                                            */
/*----------------------------------------------------------------------------*/

/*---------------------- Components ------------------------------------------*/
extern srv_clog_comp_struct *srv_clog_comp_create(U32 mem_type);
extern void srv_clog_comp_create_elments(U32 mem_type, srv_clog_comp_struct *comp, void *st_user_data);
extern void srv_clog_comp_destroy(srv_clog_comp_struct *comp);

/*---------------------- Style Manager ---------------------------------------*/
extern srv_clog_stl_mgr_struct *srv_clog_stl_create(U32 mem_type);
extern void srv_clog_stl_destroy(srv_clog_stl_mgr_struct *style_mgr);
extern S32 srv_clog_stl_valid(U32 type, U32 style, void *data, S32 is_special);
extern S32 srv_clog_stl_set_style(srv_clog_stl_mgr_struct *style_mgr, U32 type, U32 style, void *data);
extern S32 srv_clog_stl_get_style(srv_clog_stl_mgr_struct *style_mgr, U32 type, U32 *style, void **data);
#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
extern S32 srv_clog_stl_support_phb_sync(srv_clog_stl_mgr_struct *style_mgr);
#endif
extern S32 srv_clog_stl_support_thread(srv_clog_stl_mgr_struct *style_mgr);
extern S32 srv_clog_stl_support_merge(srv_clog_stl_mgr_struct *style_mgr);

/*---------------------- main ---------------------------------------------*/
extern void srv_clog_message_init(void);
extern void srv_clog_emit_update_log_event(U32 fields, srv_clog_si_struct *si_log);

/*---------------------- SI Table Operation ----------------------------------*/
extern srv_clog_si_tbl_struct *srv_clog_si_tbl_create(U32 mem_type);
extern srv_clog_si_struct *srv_clog_si_tbl_index(srv_clog_si_tbl_struct *si_tbl, U32 index);
extern void srv_clog_si_log_get_num(srv_clog_si_struct *sort_info, U32 *total_num, U32 *unread_num);
extern void srv_clog_si_log_update_num(srv_clog_si_struct *sort_info, U32 ext_tt_num, U32 ext_ur_num, S32 is_add);
extern void srv_clog_si_update_phb_info(srv_clog_si_struct *si_log, U32 fields, SRV_PHB_ID phb_id, WCHAR *cid);
extern S32 srv_clog_si_log_is_valid(srv_clog_si_struct *sort_info);
extern S32 srv_clog_si_tbl_parse( srv_clog_si_tbl_struct *si_tbl, U32 start_idx, srv_clog_st_log_struct *st_logs, U32 log_num);
extern U32 srv_clog_si_tbl_get_max_log_id(srv_clog_si_tbl_struct *si_tbl);
extern U32 srv_clog_si_tbl_total_num(srv_clog_si_tbl_struct *si_tbl);
extern S32 srv_clog_si_tbl_delete_index(srv_clog_si_tbl_struct *si_tbl, U32 index);
extern S32 srv_clog_si_tbl_id2idx(srv_clog_si_tbl_struct *si_tbl, SRV_CLOG_ID log_id, U32 *idx);
extern S32 srv_clog_si_tbl_find_best_slot(srv_clog_si_tbl_struct *si_tbl, U32 *si_idx);
extern S32 srv_clog_si_log_check_merge(srv_clog_si_struct *src, srv_clog_si_struct *dst, U32 merge_style);
extern S32 srv_clog_si_si2st(srv_clog_si_struct *si_log, srv_clog_st_log_struct *st_log);
extern S32 srv_clog_si_tbl_add_update(srv_clog_si_tbl_struct *si_tbl, srv_clog_add_log_req_struct *req_data);
extern S32 srv_clog_si_log_update_log(srv_clog_si_struct *si_log, srv_clog_log_struct *cmn_log, U32 fields);
extern S32 srv_clog_si_log_check_match(srv_clog_si_tbl_struct *si_tbl, U32 sit_idx, srv_clog_search_list_log_ids_req_struct *req_data, SRV_CLOG_ID *log_id);
extern S32 srv_clog_si_flash(srv_clog_si_tbl_struct *si_tbl, U32 start_idx, U32 end_idx);
extern CHAR *srv_clog_si_log_get_cid(srv_clog_si_struct *si_info, CHAR *call_number, U32 max_len);

/*---------------------- Index Table Operation -------------------------------*/
extern srv_clog_idx_tbl_struct *srv_clog_idx_create(U32 mem_type, srv_clog_si_tbl_struct *si_tbl, srv_clog_stl_mgr_struct *stl_mgr);
extern srv_clog_si_struct *srv_clog_idx_peek_si_by_idx(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type, U32 idx);
extern srv_clog_si_struct *srv_clog_idx_get_last_log(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_log_identity_struct *idt);
extern srv_clog_ret_enum srv_clog_idx_refresh(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_list_level_enum level, srv_clog_log_identity_struct *idt, srv_clog_idx_info_enum *info_type);
extern SRV_CLOG_ID srv_clog_idx_idx2id(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type, U32 index);
extern S32 srv_clog_idx_clear(srv_clog_idx_tbl_struct *idx_tbl);
extern U32 srv_clog_idx_total_num(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type);
extern U32 srv_clog_idx_index(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type, U32 index);  /* to get si_index by idx_tbl_idx */
extern U32 srv_clog_idx_get_ur_mclt_num(srv_clog_idx_tbl_struct *idx_tbl, U32 *num_list, U32 sim_num);
extern S32 srv_clog_idx_get_num_info(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_log_identity_struct *idt, srv_clog_num_info_struct *num_info);
extern S32 srv_clog_idx_parse(srv_clog_idx_tbl_struct *idx_tbl);
extern S32 srv_clog_idx_reset(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type);
extern S32 srv_clog_idx_get_log_by_id(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type, SRV_CLOG_ID log_id, U32 fields, srv_clog_log_struct *log);
extern S32 srv_clog_idx_get_log_by_idx(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type, U32 idx, U32 fields, srv_clog_log_struct *log);
extern S32 srv_clog_idx_get_list_ids(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type, const srv_clog_get_list_log_ids_req_struct *req_data, srv_clog_get_list_log_ids_cnf_struct *cnf_data);
extern S32 srv_clog_idx_get_list_log(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_list_level_enum level_type, srv_clog_get_list_log_req_struct *req_data, srv_clog_get_list_log_cnf_struct *cnf_data);
extern S32 srv_clog_idx_delete_id(srv_clog_idx_tbl_struct *idx_tbl, SRV_CLOG_ID log_id);
extern S32 srv_clog_idx_add_prepare(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_add_log_req_struct *req_data);
extern S32 srv_clog_idx_add_update(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_add_log_req_struct *req_data);
extern S32 srv_clog_idx_search_ids_by_idx(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type, srv_clog_search_list_log_ids_req_struct *req_data, srv_clog_search_list_log_ids_cnf_struct *cnf_data, U32 idx_start_idx);
extern S32 srv_clog_idx_id2idx(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type, SRV_CLOG_ID log_id, U32 *idx_tbl_idx, U32 *si_tbl_idx);

#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
typedef enum
{
    SRV_CLOG_JOB_STATE_INIT,
    SRV_CLOG_JOB_STATE_READY = 0,
    SRV_CLOG_JOB_STATE_HANDLING,
    SRV_CLOG_JOB_STATE_WAITING,
    SRV_CLOG_JOB_STATE_CANCELING,
    SRV_CLOG_JOB_STATE_CANCELED,
    SRV_CLOG_JOB_STATE_FINISHED,
    SRV_CLOG_JOB_STATE_PENDING,
    SRV_CLOG_JOB_STATE_MAX_ITEM
} srv_clog_job_state_enum;


/* As use this enum as array index from the 2nd element,
  so the 1st element must be -1 and must add compile option to it */
typedef enum
{
    SRV_CLOG_JOB_TYPE_CMN_INIT = -1,
    SRV_CLOG_JOB_TYPE_LOAD_LOGS,
    SRV_CLOG_JOB_TYPE_PARSE_LOGS,
#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
    SRV_CLOG_JOB_TYPE_REVISE_LOGS,
#endif

#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
    SRV_CLOG_JOB_TYPE_SIM_SYNC,
#endif

    SRV_CLOG_JOB_TYPE_INIT_DONE,

    SRV_CLOG_JOB_TYPE_ADD_NEW_LOG,
    SRV_CLOG_JOB_TYPE_UPDATE_LOG,
    SRV_CLOG_JOB_TYPE_UPDATE_ALL_LOGS,
    SRV_CLOG_JOB_TYPE_DEL_LOG_BY_ID,
    SRV_CLOG_JOB_TYPE_DEL_ALL_LOGS,

#ifdef __MMI_CLOG_MARK_SEVERAL__
    SRV_CLOG_JOB_TYPE_DEL_MULTI_LOGS,
#endif

    SRV_CLOG_JOB_TYPE_SEARCH_LIST_IDS,

#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
    SRV_CLOG_JOB_TYPE_UPDATE_PHB_EVT,
#endif

    SRV_CLOG_JOB_TYPE_MAX_ITEM
} srv_clog_job_type_enum;

/*----------------------------------------------------------------------------*/
/* typedef in structure                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Extern Function                                                            */
/*----------------------------------------------------------------------------*/

/*---------------------- Components ------------------------------------------*/
extern srv_clog_comp_struct *srv_clog_comp_create(U32 mem_type);

extern void srv_clog_comp_destroy(srv_clog_comp_struct *comp);

extern void srv_clog_comp_create_elments(U32 mem_type, srv_clog_comp_struct *comp, void *st_user_data);

extern srv_clog_comp_struct *srv_clog_get_cur_comp(srv_clog_cntx_struct *cntx, SRV_CLOG_HANDLE handle);

/*---------------------- Style Manager ---------------------------------------*/
extern srv_clog_stl_mgr_struct *srv_clog_stl_create(U32 mem_type);

extern void srv_clog_stl_destroy(srv_clog_stl_mgr_struct *style_mgr);

extern S32 srv_clog_stl_valid(U32 type, U32 style, void *data, S32 is_special);

extern S32 srv_clog_stl_set_style(srv_clog_stl_mgr_struct *style_mgr, U32 type, U32 style, void *data);

extern S32 srv_clog_stl_get_style(srv_clog_stl_mgr_struct *style_mgr, U32 type, U32 *style, void **data);

//APIReserved
//extern S32 srv_clog_stl_parse_sort(U32 sort_style, U8 *sort_type, U8 *sort_dir, U8 *sort_algo);

#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
extern S32 srv_clog_stl_support_sim_sync(srv_clog_stl_mgr_struct *style_mgr);
#endif

#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
extern S32 srv_clog_stl_support_phb_sync(srv_clog_stl_mgr_struct *style_mgr);
#endif


extern S32 srv_clog_stl_support_thread(srv_clog_stl_mgr_struct *style_mgr);

extern S32 srv_clog_stl_support_merge(srv_clog_stl_mgr_struct *style_mgr);

/*---------------------- Job Manager -----------------------------------------*/
extern S32 srv_clog_job_is_empty(srv_clog_job_mgr_struct *job_mgr);

extern S32 srv_clog_job_num(srv_clog_job_mgr_struct *job_mgr);

extern S32 srv_clog_job_is_blocked(srv_clog_job_mgr_struct *job_mgr);

extern S32 srv_clog_job_get_type_num(srv_clog_job_mgr_struct *job_mgr, srv_clog_job_type_enum job_type);

extern void srv_clog_job_free(srv_clog_job_struct *job);

extern void *srv_clog_job_new_para(srv_clog_job_struct *job, U32 para_size);


extern srv_clog_job_struct *srv_clog_job_index(srv_clog_job_mgr_struct *job_mgr, U32 idx);

extern srv_clog_job_struct *srv_clog_job_submit(srv_clog_job_mgr_struct *job_mgr, srv_clog_job_type_enum job_type);

extern srv_clog_job_struct *srv_clog_job_remove_head(srv_clog_job_mgr_struct *job_mgr);

extern S32 srv_clog_job_add_tail(srv_clog_job_mgr_struct *job_mgr, srv_clog_job_struct *job);

extern srv_clog_job_struct *srv_clog_job_submit_head(
                                srv_clog_job_mgr_struct *job_mgr,
                                srv_clog_job_type_enum job_type);

extern srv_clog_job_struct *srv_clog_job_submit_tail(
                                srv_clog_job_mgr_struct *job_mgr,
                                srv_clog_job_type_enum job_type);
//APIReserved
//extern S32 srv_clog_job_cancel_pid(srv_clog_job_mgr_struct *job_mgr, S32 pid);

extern S32 srv_clog_job_cancel_handle(srv_clog_job_mgr_struct *job_mgr, SRV_CLOG_HANDLE handle);

/*---------------------- Job Handler -----------------------------------------*/
extern void srv_clog_evt_init(void);

extern S32 srv_clog_process_new_job(
            srv_clog_cntx_struct *cntx,
            srv_clog_job_mgr_struct *job_mgr,
            srv_clog_job_struct *job);

extern S32 srv_clog_continue_process_job(srv_clog_cntx_struct *cntx);

extern void srv_clog_emit_update_log_event(SRV_CLOG_HANDLE handle, U32 fields, srv_clog_si_struct *si_log);

extern S32 srv_clog_async_process(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);

#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
extern S32 srv_clog_phb_job_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);
#endif

/*---------------------- SI Table Operation ----------------------------------*/
extern srv_clog_si_tbl_struct *srv_clog_si_create(U32 mem_type);

extern S32 srv_clog_si_clear(srv_clog_si_tbl_struct *si_tbl);

extern U32 srv_clog_si_total_num(srv_clog_si_tbl_struct *si_tbl);

/* APIReserved
extern S32 srv_clog_si_get_num_info(
            srv_clog_si_tbl_struct *si_tbl,
            S32 sup_thread,
            srv_clog_log_identity_struct *idt,
            srv_clog_num_info_struct *num_info);
*/

extern U32 srv_clog_si_get_max_log_id(srv_clog_si_tbl_struct *si_tbl);

extern S32 srv_clog_si_is_valid(srv_clog_si_struct *sort_info);

extern U16 srv_clog_si_get_log_total_num(srv_clog_si_struct *sort_info);

extern U16 srv_clog_si_get_log_unread_num(srv_clog_si_struct *sort_info);

extern void srv_clog_si_get_num(srv_clog_si_struct *sort_info, U32 *total_num, U32 *unread_num);

extern CHAR *srv_clog_si_get_cid(srv_clog_si_struct *si_info);

extern WCHAR *srv_clog_si_get_name(srv_clog_si_struct *si_info);

extern srv_clog_si_struct *srv_clog_si_index(srv_clog_si_tbl_struct *si_tbl, U32 index);

extern S32 srv_clog_si_parse(
            srv_clog_si_tbl_struct *si_tbl,
            U32 start_idx,
            srv_clog_st_log_struct *st_logs,
            U32 log_num);

extern S32 srv_clog_si_delete_index(srv_clog_si_tbl_struct *si_tbl, U32 index);

extern S32 srv_clog_si_id2idx(srv_clog_si_tbl_struct *si_tbl, SRV_CLOG_ID log_id, U32 *idx);

extern S32 srv_clog_si_log_si2cmn(srv_clog_si_struct *sort_info, U32 fields, srv_clog_log_struct *log);

extern S32 srv_clog_si_log_cmn2si(srv_clog_log_struct *cmn_log, srv_clog_si_struct *sort_info);

extern S32 srv_clog_si_find_best_slot(srv_clog_si_tbl_struct *si_tbl, U32 *si_idx);

extern S32 srv_clog_si_check_merge(srv_clog_si_struct *src, srv_clog_si_struct *dst, U32 merge_style);

extern S32 srv_clog_si_st2si(srv_clog_st_log_struct *st_log, srv_clog_si_struct *si_log);

extern S32 srv_clog_si_si2st(srv_clog_si_struct *si_log, srv_clog_st_log_struct *st_log);

extern S32 srv_clog_si_add_update(srv_clog_si_tbl_struct *si_tbl, srv_clog_job_add_log_req_struct *req_data);

extern S32 srv_clog_si_update_log(srv_clog_si_struct *si_log, srv_clog_log_struct *cmn_log, U32 fields);

extern void srv_clog_si_update_num(srv_clog_si_struct *sort_info, U32 ext_tt_num, U32 ext_ur_num, S32 is_add);

extern S32 srv_clog_si_update_cmn_info(srv_clog_si_struct *si_log, srv_clog_update_all_logs_req_struct *req_data);

extern S32 srv_clog_si_check_match(
            srv_clog_si_tbl_struct *si_tbl,
            U32 sit_idx,
            srv_clog_search_list_log_ids_req_struct *req_data,
            SRV_CLOG_ID *log_id);

extern S32 srv_clog_si_flash(srv_clog_si_tbl_struct *si_tbl, U32 *start_idx, U32 *saved_num, U32 *faied_num);

extern void srv_clog_si_update_phb_info(
                srv_clog_si_struct *si_log,
                U32 fields,
                SRV_PHB_ID phb_id,
                WCHAR *name,
                WCHAR *cid);

/*---------------------- Index Table Operation -------------------------------*/
extern srv_clog_idx_tbl_struct *srv_clog_idx_create(
                                    U32 mem_type,
                                    srv_clog_si_tbl_struct *si_tbl,
                                    srv_clog_stl_mgr_struct *stl_mgr);

extern S32 srv_clog_idx_clear(srv_clog_idx_tbl_struct *idx_tbl);

extern U32 srv_clog_idx_total_num(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_idx_info_enum info_type,
            srv_clog_log_identity_struct **idt);

extern srv_clog_log_identity_struct *srv_clog_idx_get_idt(
                                        srv_clog_idx_tbl_struct *idx_tbl,
                                        srv_clog_idx_info_enum info_type);

extern U32 srv_clog_idx_index(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type, U32 index);  /* to get si_index by idx_tbl_idx */

extern U32 srv_clog_idx_get_ur_mclt_num(srv_clog_idx_tbl_struct *idx_tbl, U32 *num_list, U32 sim_num);

extern S32 srv_clog_idx_get_num_info(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_log_identity_struct *idt,
            srv_clog_num_info_struct *num_info);

extern S32 srv_clog_idx_parse(srv_clog_idx_tbl_struct *idx_tbl);

extern S32 srv_clog_idx_reset(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type);

extern S32 srv_clog_idx_get_log_by_id(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_idx_info_enum info_type,
            SRV_CLOG_ID log_id,
            U32 fields,
            srv_clog_log_struct *log);

extern SRV_CLOG_ID srv_clog_idx_idx2id(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type, U32 index);

extern S32 srv_clog_idx_get_log_by_idx(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_idx_info_enum info_type,
            U32 idx,
            U32 fields,
            srv_clog_log_struct *log);

extern srv_clog_si_struct *srv_clog_idx_peek_si_by_idx(
                            srv_clog_idx_tbl_struct *idx_tbl,
                            srv_clog_idx_info_enum info_type,
                            U32 idx);


extern srv_clog_si_struct *srv_clog_idx_get_last_log(
                            srv_clog_idx_tbl_struct *idx_tbl,
                            srv_clog_log_identity_struct *idt);

extern S32 srv_clog_idx_get_list_ids(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_idx_info_enum info_type,
            const srv_clog_get_list_log_ids_req_struct *req_data,
            srv_clog_get_list_log_ids_cnf_struct *cnf_data);

extern srv_clog_ret_enum srv_clog_idx_refresh(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_list_level_enum level,
            srv_clog_log_identity_struct *idt,
            srv_clog_idx_info_enum *info_type);

extern S32 srv_clog_idx_get_list_log(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_list_level_enum level_type,
            srv_clog_get_list_log_req_struct *req_data,
            srv_clog_get_list_log_cnf_struct *cnf_data);

extern S32 srv_clog_idx_delete_id(srv_clog_idx_tbl_struct *idx_tbl, SRV_CLOG_ID log_id);

extern S32 srv_clog_idx_add_prepare(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_job_add_log_req_struct *req_data);

extern S32 srv_clog_idx_add_update(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_job_add_log_req_struct *req_data);

extern S32 srv_clog_idx_search_ids_by_idx(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_idx_info_enum info_type,
            srv_clog_search_list_log_ids_req_struct *req_data,
            srv_clog_search_list_log_ids_cnf_struct *cnf_data,
            U32 idx_start_idx);

extern S32 srv_clog_idx_id2idx(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_idx_info_enum info_type,
            SRV_CLOG_ID log_id,
            U32 *idx_tbl_idx,
            U32 *si_tbl_idx);

#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif 


#endif /* SRV_CALL_LOG_COMP_H */ 

