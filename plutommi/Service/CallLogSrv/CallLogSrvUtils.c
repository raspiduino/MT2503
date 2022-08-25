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
*  CallLogSrvUtils.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/


/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
#include "mmi_include.h"

#ifdef __MMI_TELEPHONY_SUPPORT__
#include "string.h"

#include "kal_general_types.h"
#include "kal_trace.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_debug.h"

#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "lcd_cqueue.h"

#include "custom_voip_config.h"
#include "custom_phb_config.h"
#include "custom_calllog.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"

#include "smu_common_enums.h"
#include "sim_common_enums.h"

#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "Unicodexdcl.h"
#include "mmi_frm_utility_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_events_gprot.h"

#include "PhbSrvGprot.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvStore.h"
#include "CallLogSrvComp.h"
#include "CallLogSrvProt.h"

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_4BYTES_ALIGN(size)              ((size + 3) & (~0x03))

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*---------------------- Memory Manager --------------------------------------*/
/* Should make sure all the following sizes are 4-bytes aligned */

/* cntx */
#define SRV_CLOG_ELM_CNTX_SIZE                      (SRV_CLOG_4BYTES_ALIGN(sizeof(srv_clog_cntx_struct)))
/* inst */
#define SRV_CLOG_ELM_INST_TBL_SIZE                  (SRV_CLOG_4BYTES_ALIGN(sizeof(srv_clog_inst_tbl_struct)))
#define SRV_CLOG_ELM_INST_SIZE                      (SRV_CLOG_4BYTES_ALIGN(sizeof(srv_clog_inst_struct)))
/* comp */
#define SRV_CLOG_ELM_COMP_SIZE                      (SRV_CLOG_4BYTES_ALIGN(sizeof(srv_clog_comp_struct)))
/* style manager */
#define SRV_CLOG_ELM_STL_MGR_SIZE                   (SRV_CLOG_4BYTES_ALIGN(sizeof(srv_clog_stl_mgr_struct)))
/* job */
#define SRV_CLOG_ELM_JOB_MGR_SIZE                   (SRV_CLOG_4BYTES_ALIGN(sizeof(srv_clog_job_mgr_struct)))
#define SRV_CLOG_ELM_JOB_QUEUE_SIZE                 (SRV_CLOG_4BYTES_ALIGN(sizeof(lcd_cqueue)))
#define SRV_CLOG_ELM_JOB_SLOT_SIZE                  (SRV_CLOG_4BYTES_ALIGN(sizeof(void*)))

/* sort info table */
#define SRV_CLOG_ELM_SI_TBL_SIZE                    (SRV_CLOG_4BYTES_ALIGN(sizeof(srv_clog_si_tbl_struct)))
#define SRV_CLOG_ELM_SI_SIZE                        (SRV_CLOG_4BYTES_ALIGN(sizeof(srv_clog_si_struct)))
/* index table */
#define SRV_CLOG_ELM_IDX_TBL_SIZE                   (SRV_CLOG_4BYTES_ALIGN(sizeof(srv_clog_idx_tbl_struct)))
#define SRV_CLOG_ELM_IDX_INFO_SIZE                  (SRV_CLOG_4BYTES_ALIGN(sizeof(srv_clog_idx_info_struct)))
#define SRV_CLOG_ELM_IDX_BASE_INFO_SIZE             (SRV_CLOG_4BYTES_ALIGN(SRV_CLOG_LOG_MAX_NUM * sizeof(U16)))
#define SRV_CLOG_ELM_IDX_THREAD_INFO_SIZE           (SRV_CLOG_4BYTES_ALIGN(SRV_CLOG_LOG_MAX_NUM * sizeof(U16)))
#define SRV_CLOG_ELM_IDX_FILTER_INFO_SIZE           (SRV_CLOG_4BYTES_ALIGN(SRV_CLOG_OP_TYPE_MAX_NUM * sizeof(U16)))

#define SRV_CLOG_ELM_CNTX_SYS_NUM                   (1)

#define SRV_CLOG_ELM_INST_TBL_SYS_NUM               (1)
#define SRV_CLOG_ELM_INST_SYS_NUM                   (SRV_CLOG_INST_MAX_PRE_DEF_NUM)

#define SRV_CLOG_ELM_COMP_SYS_NUM                   (1)

#define SRV_CLOG_ELM_STL_MGR_SYS_NUM                (1)

#define SRV_CLOG_ELM_JOB_MGR_SYS_NUM                (1)
#define SRV_CLOG_ELM_JOB_QUEUE_SYS_NUM              (1)
#define SRV_CLOG_ELM_JOB_SLOT_SYS_NUM               (SRV_CLOG_MAX_JOB_NUM)

#define SRV_CLOG_ELM_SI_TBL_SYS_NUM                 (1)
#define SRV_CLOG_ELM_SI_SYS_NUM                     (SRV_CLOG_LOG_MAX_NUM)

#define SRV_CLOG_ELM_IDX_TBL_SYS_NUM                (1)
#define SRV_CLOG_ELM_IDX_INFO_SYS_NUM               (SRV_CLOG_IDX_INFO_MAX_ITEM)
#define SRV_CLOG_ELM_IDX_BASE_INFO_SYS_NUM          (1)
#define SRV_CLOG_ELM_IDX_THREAD_INFO_SYS_NUM        (1)
#define SRV_CLOG_ELM_IDX_FILTER_INFO_SYS_NUM        (SRV_CLOG_IDX_INFO_MAX_ITEM - SRV_CLOG_IDX_INFO_FILTER)

#define SRV_CLOG_ELM_CNTX_TOTAL_SIZE                (SRV_CLOG_ELM_CNTX_SIZE  *  SRV_CLOG_ELM_CNTX_SYS_NUM)

#define SRV_CLOG_ELM_INST_TOTAL_SIZE                (SRV_CLOG_ELM_INST_TBL_SIZE * SRV_CLOG_ELM_INST_TBL_SYS_NUM + SRV_CLOG_ELM_INST_SIZE * SRV_CLOG_ELM_INST_SYS_NUM)

#define SRV_CLOG_ELM_COMP_TOTAL_SIZE                (SRV_CLOG_ELM_COMP_SIZE * SRV_CLOG_ELM_COMP_SYS_NUM)

#define SRV_CLOG_ELM_STL_TOTAL_SIZE                 (SRV_CLOG_ELM_STL_MGR_SIZE * SRV_CLOG_ELM_STL_MGR_SYS_NUM)

#define SRV_CLOG_ELM_JOB_TOTAL_SIZE                                                     \
            (SRV_CLOG_ELM_JOB_MGR_SIZE * SRV_CLOG_ELM_JOB_MGR_SYS_NUM +                 \
            SRV_CLOG_ELM_JOB_QUEUE_SIZE * SRV_CLOG_ELM_JOB_QUEUE_SYS_NUM +              \
            SRV_CLOG_ELM_JOB_SLOT_SIZE *  SRV_CLOG_ELM_JOB_SLOT_SYS_NUM)

#define SRV_CLOG_ELM_SI_TOTAL_SIZE                                                      \
            (SRV_CLOG_ELM_SI_TBL_SIZE * SRV_CLOG_ELM_SI_TBL_SYS_NUM +                   \
            SRV_CLOG_ELM_SI_SIZE * SRV_CLOG_ELM_SI_SYS_NUM)

#ifdef __SRV_CLOG_UT__
#define SRV_CLOG_ELM_IDX_TOTAL_SIZE                                                     \
            (SRV_CLOG_ELM_IDX_TBL_SIZE * SRV_CLOG_ELM_IDX_TBL_SYS_NUM +                 \
            SRV_CLOG_ELM_IDX_INFO_SIZE * SRV_CLOG_ELM_IDX_INFO_SYS_NUM)

#else /* __SRV_CLOG_UT__ */ 
#define SRV_CLOG_ELM_IDX_TOTAL_SIZE                                                     \
            (SRV_CLOG_ELM_IDX_TBL_SIZE * SRV_CLOG_ELM_IDX_TBL_SYS_NUM +                 \
            SRV_CLOG_ELM_IDX_INFO_SIZE * SRV_CLOG_ELM_IDX_INFO_SYS_NUM +                \
            SRV_CLOG_ELM_IDX_BASE_INFO_SIZE * SRV_CLOG_ELM_IDX_BASE_INFO_SYS_NUM +      \
            SRV_CLOG_ELM_IDX_THREAD_INFO_SIZE * SRV_CLOG_ELM_IDX_THREAD_INFO_SYS_NUM +  \
            SRV_CLOG_ELM_IDX_FILTER_INFO_SIZE * SRV_CLOG_ELM_IDX_FILTER_INFO_SYS_NUM)
#endif /* __SRV_CLOG_UT__ */ 

#define SRV_CLOG_MEM_POOL_SYS_SIZE                                              \
                            (SRV_CLOG_ELM_CNTX_TOTAL_SIZE +                     \
                            SRV_CLOG_ELM_INST_TOTAL_SIZE +                      \
                            SRV_CLOG_ELM_COMP_TOTAL_SIZE +                      \
                            SRV_CLOG_ELM_STL_TOTAL_SIZE +                       \
                            SRV_CLOG_ELM_JOB_TOTAL_SIZE +                       \
                            SRV_CLOG_ELM_SI_TOTAL_SIZE +                        \
                            SRV_CLOG_ELM_IDX_TOTAL_SIZE)

#define SRV_CLOG_MEM_POOL_MIN_DYNC_SIZE     (100)

#ifdef __SRV_CLOG_MEM_DEBUG__
#define SRV_CLOG_MEM_POOL_GUARD             (0xFDFCFBFA)
#define SRV_CLOG_MEM_POOL_GUARD_SIZE        (sizeof(U32))
#else /* __SRV_CLOG_MEM_DEBUG__ */ 
#define SRV_CLOG_MEM_POOL_GUARD_SIZE        (0)
#endif /* __SRV_CLOG_MEM_DEBUG__ */ 

/*---------------------- Job Manager -----------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/* To define this enum, just to slim g_srv_clog_para_size_tbl[] */
typedef enum 
{
  SRV_CLOG_PARA_SIZE_CREATE =                   sizeof(srv_clog_create_struct),
  SRV_CLOG_PARA_SIZE_IDENTITY =                 sizeof(srv_clog_log_identity_struct),
  SRV_CLOG_PARA_SIZE_IDENTIFIER =               sizeof(srv_clog_log_identifier_struct),
  SRV_CLOG_PARA_SIZE_NUM_INFO =                 sizeof(srv_clog_num_info_struct),
  SRV_CLOG_PARA_SIZE_GET_LIST_LOG_IDS_REQ =     sizeof(srv_clog_get_list_log_ids_req_struct),
  SRV_CLOG_PARA_SIZE_GET_LIST_LOG_IDS_CNF =     sizeof(srv_clog_get_list_log_ids_cnf_struct),
  SRV_CLOG_PARA_SIZE_GET_LIST_LOG_REQ =         sizeof(srv_clog_get_list_log_req_struct),
  SRV_CLOG_PARA_SIZE_GET_LIST_LOG_CNF =         sizeof(srv_clog_get_list_log_cnf_struct),
  SRV_CLOG_PARA_SIZE_GET_LAST_LOG_REQ =         sizeof(srv_clog_get_last_log_req_struct),
  SRV_CLOG_PARA_SIZE_GET_LAST_LOG_CNF =         sizeof(srv_clog_get_last_log_cnf_struct),
  SRV_CLOG_PARA_SIZE_LOG =                      sizeof(srv_clog_log_struct),
  SRV_CLOG_PARA_SIZE_ADD_LOG_REQ =              sizeof(srv_clog_add_log_req_struct),
  SRV_CLOG_PARA_SIZE_ADD_LOG_CNF =              sizeof(srv_clog_add_log_cnf_struct),
  SRV_CLOG_PARA_SIZE_LOG_CALL_REQ =             sizeof(srv_clog_log_call_req_struct),
  SRV_CLOG_PARA_SIZE_LOG_CALL_CNF =             sizeof(srv_clog_log_call_cnf_struct),
  SRV_CLOG_PARA_SIZE_LOG_DURATION_REQ =         sizeof(srv_clog_log_duration_req_struct),
  SRV_CLOG_PARA_SIZE_LOG_DURATION_CNF =         sizeof(srv_clog_log_duration_cnf_struct),
  SRV_CLOG_PARA_SIZE_UPDATE_LOG_REQ =           sizeof(srv_clog_update_log_req_struct),
  SRV_CLOG_PARA_SIZE_UPDATE_LOG_CNF =           sizeof(srv_clog_update_log_cnf_struct),
  SRV_CLOG_PARA_SIZE_UPDATE_ALL_LOGS_REQ =      sizeof(srv_clog_update_all_logs_req_struct),
  SRV_CLOG_PARA_SIZE_UPDATE_ALL_LOGS_CNF =      sizeof(srv_clog_update_all_logs_cnf_struct),
  SRV_CLOG_PARA_SIZE_DEL_LOG_REQ =              sizeof(srv_clog_del_log_req_struct),
  SRV_CLOG_PARA_SIZE_DEL_LOG_CNF =              sizeof(srv_clog_del_log_cnf_struct),
  SRV_CLOG_PARA_SIZE_DEL_ALL_LOGS_REQ =         sizeof(srv_clog_del_all_logs_req_struct),
  SRV_CLOG_PARA_SIZE_DEL_ALL_LOGS_CNF =         sizeof(srv_clog_del_all_logs_cnf_struct),
  SRV_CLOG_PARA_SIZE_DEL_MULTI_LOGS_REQ =       sizeof(srv_clog_del_multi_logs_req_struct),
  SRV_CLOG_PARA_SIZE_DEL_MULTI_LOGS_CNF =       sizeof(srv_clog_del_multi_logs_cnf_struct),
  SRV_CLOG_PARA_SIZE_SEARCH_LIST_LOG_IDS_REQ =  sizeof(srv_clog_search_list_log_ids_req_struct),
  SRV_CLOG_PARA_SIZE_SEARCH_LIST_LOG_IDS_CNF =  sizeof(srv_clog_search_list_log_ids_cnf_struct),
  SRV_CLOG_PARA_SIZE_MAX_ITEM
}srv_clog_para_size_enum;

/* To define this enum, just to slim g_srv_clog_clt_max_size_tbl[] */
typedef enum
{
    SRV_CLOG_LOG_NUM_DIALED = SRV_CLOG_MAX_DIALED_CLT_NUM,
    SRV_CLOG_LOG_NUM_MISSED = SRV_CLOG_MAX_MISSED_CLT_NUM,
    SRV_CLOG_LOG_NUM_RECVED = SRV_CLOG_MAX_RECVED_CLT_NUM,
    SRV_CLOG_LOG_NUM_REJED  = SRV_CLOG_MAX_REJED_CLT_NUM,
    SRV_CLOG_LOG_NUM_ALL    = SRV_CLOG_LOG_MAX_NUM,
    SRV_CLOG_LOG_NUM_MAX_ITEM
}srv_clog_log_num_enum;



/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/
typedef void *(*SRV_CLOG_MALLOC_FUNC) (U32 size);
typedef void (*SRV_CLOG_MFREE_FUNC) (void *p);

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
#ifdef __SRV_CLOG_MEM_DEBUG__

typedef struct
{
    U32 size;
    U32 num;
    U32 total;
} srv_clog_mem_size_struct;

#endif /* __SRV_CLOG_MEM_DEBUG__ */ 

typedef struct
{
    SRV_CLOG_MALLOC_FUNC malloc;
    SRV_CLOG_MFREE_FUNC mfree;
} srv_clog_mem_op_struct;

typedef struct
{
    U32 sys_cur_pos;
    U8 sys_pool[SRV_CLOG_MEM_POOL_SYS_SIZE + SRV_CLOG_MEM_POOL_GUARD_SIZE];     /* Should be 4-bytes aligned */

#if (SRV_CLOG_MEM_POOL_DYNC_SIZE > SRV_CLOG_MEM_POOL_MIN_DYNC_SIZE)
    KAL_ADM_ID adm_id;
    U8 dync_pool[SRV_CLOG_MEM_POOL_DYNC_SIZE];  /* Should be 4-bytes aligned */
#endif

} srv_clog_mem_mgr_struct;

typedef struct
{
    /* U8 para_type; */ /* Comment it for slim, keep it for maintainability */
    srv_clog_para_size_enum para_size;
} srv_clog_para_size_struct;


typedef struct
{
    /* U8 srv_clog_clt_idx_enum clt_idx; */ /* Comment it for slim, keep it for maintainability */
    srv_clog_log_num_enum log_num;
}srv_clog_clt_log_num_map_struct;


/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
/* Memory operation */
static void *srv_clog_sys_malloc(U32 size);
static void srv_clog_sys_mfree(void *p);
#if (SRV_CLOG_MEM_POOL_DYNC_SIZE > SRV_CLOG_MEM_POOL_MIN_DYNC_SIZE)
static void *srv_clog_dync_malloc(U32 size);
static void srv_clog_dync_mfree(void *p);
#endif
static void *srv_clog_ctrl_buf_malloc(U32 size);
static void srv_clog_ctrl_buf_mfree(void *p);
static void *srv_clog_temp_malloc(U32 size);
static void srv_clog_temp_mfree(void *p);

/* Param operation */
static U32 srv_clog_get_para_size(srv_clog_para_enum para_type);

/*----------------------------------------------------------------------------*/
/* Extern Function Declaration                                                */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
static srv_clog_mem_mgr_struct g_srv_clog_mem_cntx;

static const srv_clog_mem_op_struct g_srv_clog_mem_op_tbl[] = 
{
    {srv_clog_sys_malloc, srv_clog_sys_mfree},
    {srv_clog_ctrl_buf_malloc, srv_clog_ctrl_buf_mfree},
    {srv_clog_temp_malloc, srv_clog_temp_mfree},

#if (SRV_CLOG_MEM_POOL_DYNC_SIZE > SRV_CLOG_MEM_POOL_MIN_DYNC_SIZE)
    {srv_clog_dync_malloc, srv_clog_dync_mfree},
#endif
};

#ifdef __SRV_CLOG_MEM_DEBUG__

static const srv_clog_mem_size_struct g_srv_clog_mem_size_tbl[] = 
{
    {SRV_CLOG_ELM_CNTX_SIZE, SRV_CLOG_ELM_CNTX_SYS_NUM, SRV_CLOG_ELM_CNTX_SIZE * SRV_CLOG_ELM_CNTX_SYS_NUM},//0

    {SRV_CLOG_ELM_INST_SIZE, SRV_CLOG_ELM_INST_SYS_NUM, SRV_CLOG_ELM_INST_SIZE * SRV_CLOG_ELM_INST_SYS_NUM},//1
    {SRV_CLOG_ELM_INST_TBL_SIZE, SRV_CLOG_ELM_INST_TBL_SYS_NUM, SRV_CLOG_ELM_INST_TBL_SIZE * SRV_CLOG_ELM_INST_TBL_SYS_NUM},//2

    {SRV_CLOG_ELM_COMP_SIZE, SRV_CLOG_ELM_COMP_SYS_NUM, SRV_CLOG_ELM_COMP_SIZE * SRV_CLOG_ELM_COMP_SYS_NUM},//3

    {SRV_CLOG_ELM_STL_MGR_SIZE, SRV_CLOG_ELM_STL_MGR_SYS_NUM, SRV_CLOG_ELM_STL_MGR_SIZE * SRV_CLOG_ELM_STL_MGR_SYS_NUM},//4

    {SRV_CLOG_ELM_JOB_MGR_SIZE, SRV_CLOG_ELM_JOB_MGR_SYS_NUM, SRV_CLOG_ELM_JOB_MGR_SIZE * SRV_CLOG_ELM_JOB_MGR_SYS_NUM},//5
    {SRV_CLOG_ELM_JOB_QUEUE_SIZE, SRV_CLOG_ELM_JOB_QUEUE_SYS_NUM, SRV_CLOG_ELM_JOB_QUEUE_SIZE * SRV_CLOG_ELM_JOB_QUEUE_SYS_NUM},//6
    {SRV_CLOG_ELM_JOB_SLOT_SIZE, SRV_CLOG_ELM_JOB_SLOT_SYS_NUM, SRV_CLOG_ELM_JOB_SLOT_SIZE * SRV_CLOG_ELM_JOB_SLOT_SYS_NUM},//7

    {SRV_CLOG_ELM_SI_SIZE, SRV_CLOG_ELM_SI_SYS_NUM, SRV_CLOG_ELM_SI_SIZE * SRV_CLOG_ELM_SI_SYS_NUM},//8
    {SRV_CLOG_ELM_SI_TBL_SIZE, SRV_CLOG_ELM_SI_TBL_SYS_NUM, SRV_CLOG_ELM_SI_TBL_SIZE * SRV_CLOG_ELM_SI_TBL_SYS_NUM},//9

    {SRV_CLOG_ELM_IDX_INFO_SIZE, SRV_CLOG_ELM_IDX_INFO_SYS_NUM, SRV_CLOG_ELM_IDX_INFO_SIZE * SRV_CLOG_ELM_IDX_INFO_SYS_NUM},//10
    {SRV_CLOG_ELM_IDX_TBL_SIZE, SRV_CLOG_ELM_IDX_TBL_SYS_NUM, SRV_CLOG_ELM_IDX_TBL_SIZE * SRV_CLOG_ELM_IDX_TBL_SYS_NUM},//11

 #ifndef __SRV_CLOG_UT__

    {SRV_CLOG_ELM_IDX_BASE_INFO_SIZE, SRV_CLOG_ELM_IDX_BASE_INFO_SYS_NUM, SRV_CLOG_ELM_IDX_BASE_INFO_SIZE * SRV_CLOG_ELM_IDX_BASE_INFO_SYS_NUM},//12
    {SRV_CLOG_ELM_IDX_THREAD_INFO_SIZE, SRV_CLOG_ELM_IDX_THREAD_INFO_SYS_NUM, SRV_CLOG_ELM_IDX_THREAD_INFO_SIZE * SRV_CLOG_ELM_IDX_THREAD_INFO_SYS_NUM},//13
    {SRV_CLOG_ELM_IDX_FILTER_INFO_SIZE, SRV_CLOG_ELM_IDX_FILTER_INFO_SYS_NUM, SRV_CLOG_ELM_IDX_FILTER_INFO_SIZE * SRV_CLOG_ELM_IDX_FILTER_INFO_SYS_NUM}//14
 #endif /* __SRV_CLOG_UT__ */ 
};
#endif /* __SRV_CLOG_MEM_DEBUG__ */ 




/* Please note: once add new enum value in SRV_CLOG_PARA_MAX_ITEM,
   must review this table as it use this enum as table index to save code size */
static const srv_clog_para_size_struct g_srv_clog_para_size_tbl[] = 
{
    {/* SRV_CLOG_PARA_CREATE,*/                     SRV_CLOG_PARA_SIZE_CREATE},
    {/* SRV_CLOG_PARA_IDENTITY, */                  SRV_CLOG_PARA_SIZE_IDENTITY},
    {/* SRV_CLOG_PARA_IDENTIFIER, */                SRV_CLOG_PARA_SIZE_IDENTIFIER},
    {/* SRV_CLOG_PARA_NUM_INFO, */                  SRV_CLOG_PARA_SIZE_NUM_INFO},
    {/* SRV_CLOG_PARA_GET_LIST_LOG_IDS_REQ, */      SRV_CLOG_PARA_SIZE_GET_LIST_LOG_IDS_REQ},
    {/* SRV_CLOG_PARA_GET_LIST_LOG_IDS_CNF, */      SRV_CLOG_PARA_SIZE_GET_LIST_LOG_IDS_CNF},
    {/* SRV_CLOG_PARA_GET_LIST_LOG_REQ, */          SRV_CLOG_PARA_SIZE_GET_LIST_LOG_REQ},
    {/* SRV_CLOG_PARA_GET_LIST_LOG_CNF, */          SRV_CLOG_PARA_SIZE_GET_LIST_LOG_CNF},
    {/* SRV_CLOG_PARA_GET_LAST_LOG_REQ, */          SRV_CLOG_PARA_SIZE_GET_LAST_LOG_REQ},
    {/* SRV_CLOG_PARA_GET_LAST_LOG_CNF, */          SRV_CLOG_PARA_SIZE_GET_LAST_LOG_CNF},
    {/* SRV_CLOG_PARA_LOG, */                       SRV_CLOG_PARA_SIZE_LOG},
    {/* SRV_CLOG_PARA_ADD_LOG_REQ, */               SRV_CLOG_PARA_SIZE_ADD_LOG_REQ},
    {/* SRV_CLOG_PARA_ADD_LOG_CNF, */               SRV_CLOG_PARA_SIZE_ADD_LOG_CNF},
    {/* SRV_CLOG_PARA_LOG_CALL_REQ, */              SRV_CLOG_PARA_SIZE_LOG_CALL_REQ},
    {/* SRV_CLOG_PARA_LOG_CALL_CNF, */              SRV_CLOG_PARA_SIZE_LOG_CALL_CNF},
    {/* SRV_CLOG_PARA_LOG_DURATION_REQ, */          SRV_CLOG_PARA_SIZE_LOG_DURATION_REQ},
    {/* SRV_CLOG_PARA_LOG_DURATION_CNF, */          SRV_CLOG_PARA_SIZE_LOG_DURATION_CNF},
    {/* SRV_CLOG_PARA_UPDATE_LOG_REQ, */            SRV_CLOG_PARA_SIZE_UPDATE_LOG_REQ},
    {/* SRV_CLOG_PARA_UPDATE_LOG_CNF, */            SRV_CLOG_PARA_SIZE_UPDATE_LOG_CNF},
    {/* SRV_CLOG_PARA_UPDATE_ALL_LOGS_REQ, */       SRV_CLOG_PARA_SIZE_UPDATE_ALL_LOGS_REQ},
    {/* SRV_CLOG_PARA_UPDATE_ALL_LOGS_CNF, */       SRV_CLOG_PARA_SIZE_UPDATE_ALL_LOGS_CNF},
    {/* SRV_CLOG_PARA_DEL_LOG_REQ, */               SRV_CLOG_PARA_SIZE_DEL_LOG_REQ},
    {/* SRV_CLOG_PARA_DEL_LOG_CNF, */               SRV_CLOG_PARA_SIZE_DEL_LOG_CNF},
    {/* SRV_CLOG_PARA_DEL_ALL_LOGS_REQ, */          SRV_CLOG_PARA_SIZE_DEL_ALL_LOGS_REQ},
    {/* SRV_CLOG_PARA_DEL_ALL_LOGS_CNF, */          SRV_CLOG_PARA_SIZE_DEL_ALL_LOGS_CNF},
    {/* SRV_CLOG_PARA_DEL_MULTI_LOGS_REQ, */        SRV_CLOG_PARA_SIZE_DEL_MULTI_LOGS_REQ},
    {/* SRV_CLOG_PARA_DEL_MULTI_LOGS_CNF, */        SRV_CLOG_PARA_SIZE_DEL_MULTI_LOGS_CNF},
    {/* SRV_CLOG_PARA_SEARCH_LIST_LOG_IDS_REQ, */   SRV_CLOG_PARA_SIZE_SEARCH_LIST_LOG_IDS_REQ},
    {/* SRV_CLOG_PARA_SEARCH_LIST_LOG_IDS_CNF, */   SRV_CLOG_PARA_SIZE_SEARCH_LIST_LOG_IDS_CNF}
};


static const srv_clog_clt_log_num_map_struct g_srv_clog_clt_max_size_tbl[] = 
{
    {/*SRV_CLOG_CLT_IDX_DIALED, */      SRV_CLOG_LOG_NUM_DIALED},
    {/*SRV_CLOG_CLT_IDX_MISSED, */      SRV_CLOG_LOG_NUM_MISSED},
    {/*SRV_CLOG_CLT_IDX_RECVED, */      SRV_CLOG_LOG_NUM_RECVED},
    {/*SRV_CLOG_CLT_IDX_REJED,  */      SRV_CLOG_LOG_NUM_REJED},
    {/*SRV_CLOG_CLT_IDX_ALL,    */      SRV_CLOG_LOG_NUM_ALL}
};



/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_UTILS_DEBUG

#ifdef __SRV_CLOG_DEBUG__

#ifdef __MTK_TARGET__
static U8 g_srv_clog_debug_log_enable = SRV_CLOG_TARGET_DUMP_GRP;   /* If dump on target */
#else 
static U8 g_srv_clog_debug_log_enable = SRV_CLOG_MODIS_DUMP_GRP;    /* If dump on MODIS */
#endif 


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_debug_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_clog_get_debug_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_clog_debug_log_enable;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_print
 * DESCRIPTION
 *  
 * PARAMETERS
 *  format      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_print(CHAR *format, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define SRV_CLOG_PRINT_MAX_CHAR_LEN                  (512)

    char log[SRV_CLOG_PRINT_MAX_CHAR_LEN];
    va_list arg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_PRINT))
        return;

    va_start(arg_list, format);

#ifdef __MTK_TARGET__
    vsnprintf(log, SRV_CLOG_PRINT_MAX_CHAR_LEN, format, arg_list);
#else 
    _vsnprintf(log, SRV_CLOG_PRINT_MAX_CHAR_LEN, format, arg_list);
#endif 
    log[SRV_CLOG_PRINT_MAX_CHAR_LEN - 1] = '\0';
    va_end(arg_list);

#ifdef __MTK_TARGET__
    /*
     * PRINT_INFORMATION_2(CCA_TRACE_INFO, "%s", log);
     */
#else 
    kal_printf("%s", log);
#endif 

}

#ifdef __SRV_CLOG_DUMP__


/*****************************************************************************
 * FUNCTION
 *  srv_clog_is_ascii_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_is_ascii_string(const WCHAR *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 p1;
    U8 p2;
    WCHAR c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*str != 0)
    {
        c = *str;
        p1 = c & 0xFF;
        p2 = (c & 0xFF00) >> 8;
        if (p1 > 0x7F || p2 != 0)
            return 0;
        str++;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sel_dump
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_sel_dump(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_CNTX_DUMP))
        return;

    if (type == SRV_CLOG_DUMP_TYPE_ALL)
        type = SRV_CLOG_DUMP_TYPE_CNTX | SRV_CLOG_DUMP_TYPE_PHB_SYNC | SRV_CLOG_DUMP_TYPE_SIM_SYNC;

    if (SRV_CLOG_CHECK_BIT_GRP(type, SRV_CLOG_DUMP_TYPE_CNTX, SRV_CLOG_DUMP_TYPE_CNTX))
        SRV_CLOG_CLEAR_BIT(type, SRV_CLOG_DUMP_TYPE_COMP);

    if (SRV_CLOG_CHECK_BIT_GRP(type, SRV_CLOG_DUMP_TYPE_CNTX, SRV_CLOG_DUMP_TYPE_PHB_SYNC))
        SRV_CLOG_CLEAR_BIT(type, SRV_CLOG_DUMP_TYPE_PHB_SYNC_EVT);

    if (SRV_CLOG_CHECK_BIT_GRP(type, SRV_CLOG_DUMP_TYPE_CNTX, SRV_CLOG_DUMP_TYPE_SIM_SYNC))
        SRV_CLOG_CLEAR_BIT(type,
            SRV_CLOG_DUMP_TYPE_SIM_SYNC_REQ_DATA | SRV_CLOG_DUMP_TYPE_SIM_SYNC_SYNC_ID | SRV_CLOG_DUMP_TYPE_SIM_SYNC_FSM);

    if (SRV_CLOG_CHECK_BIT(type, SRV_CLOG_DUMP_TYPE_CNTX))
        srv_clog_dump();

    /* The following case only can be called together by bit mask */
    if (SRV_CLOG_CHECK_BIT(type, SRV_CLOG_DUMP_TYPE_STL))
        srv_clog_stl_dump();

    if (SRV_CLOG_CHECK_BIT(type, SRV_CLOG_DUMP_TYPE_ST))
        srv_clog_st_dump();

    if (SRV_CLOG_CHECK_BIT(type, SRV_CLOG_DUMP_TYPE_JB))
        srv_clog_job_dump();

    if (SRV_CLOG_CHECK_BIT(type, SRV_CLOG_DUMP_TYPE_SI))
        srv_clog_si_dump();

    if (SRV_CLOG_CHECK_BIT(type, SRV_CLOG_DUMP_TYPE_IDX))
        srv_clog_idx_dump();

    if (SRV_CLOG_CHECK_BIT(type, SRV_CLOG_DUMP_TYPE_IDX_NUM))
        srv_clog_idx_dump_num();

#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
    if (SRV_CLOG_CHECK_BIT(type, SRV_CLOG_DUMP_TYPE_PHB_SYNC))
        srv_clog_phb_dump();

    if (SRV_CLOG_CHECK_BIT(type, SRV_CLOG_DUMP_TYPE_PHB_SYNC_EVT))
        srv_clog_phb_dump_evt();
#endif /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */

#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__

    if (SRV_CLOG_CHECK_BIT(type, SRV_CLOG_DUMP_TYPE_SIM_SYNC))
        srv_clog_sim_dump();

    if (SRV_CLOG_CHECK_BIT(type, SRV_CLOG_DUMP_TYPE_SIM_SYNC_REQ_DATA))
        srv_clog_sim_dump_req_data();

    if (SRV_CLOG_CHECK_BIT(type, SRV_CLOG_DUMP_TYPE_SIM_SYNC_SYNC_ID))
        srv_clog_sim_dump_sync_id();

    if (SRV_CLOG_CHECK_BIT(type, SRV_CLOG_DUMP_TYPE_SIM_SYNC_FSM))
        srv_clog_sim_dump_fsm();

#endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_dump
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_dump(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx || !SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_CNTX_DUMP))
        return;

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_DUMP, 0);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_DUMP, "\n\n[CLogSrv]----- srv_clog_dump(%d) ------------------\n"),
                  0));

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_DUMP_CNTX_BASE_INFO,
        cntx->state,
        cntx->max_log_id,
        cntx->max_pid,
        cntx->flags);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_DUMP_CNTX_BASE_INFO,
                   "[CLogSrv]context base_info(state=%d,max_log_id=%d,max_pid=%d,flags=0x%x)"), cntx->state,
                  cntx->max_log_id, cntx->max_pid, cntx->flags));

    srv_clog_comp_dump();

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_DUMP, 1);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_DUMP, "\n\n[CLogSrv]----- srv_clog_dump(%d) ------------------\n"),
                  1));
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_comp_dump
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_comp_dump(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_CNTX_DUMP))
        return;

    srv_clog_stl_dump();
    srv_clog_st_dump();
    srv_clog_job_dump();
    srv_clog_si_dump();
    srv_clog_idx_dump();
    srv_clog_idx_dump_num();
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_is_dump
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_is_dump(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_si_dump();
    srv_clog_idx_dump();
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_dump
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_stl_dump(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 num_style = 0;
    U32 merge_style = 0;
    U32 phb_sync_style = 0;
    U32 sim_sync_style = 0;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_stl_mgr_struct *mgr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_CNTX_DUMP))
        return;
    if (!cntx || !cntx->comp || !cntx->comp->style_mgr)
        return;
    mgr = cntx->comp->style_mgr;

    srv_clog_stl_get_style(mgr, SRV_CLOG_STYLE_TYPE_NUM, &merge_style, NULL);
    srv_clog_stl_get_style(mgr, SRV_CLOG_STYLE_TYPE_MERGE, &merge_style, NULL);
    srv_clog_stl_get_style(mgr, SRV_CLOG_STYLE_TYPE_PHB_SYNC, &merge_style, NULL);
    srv_clog_stl_get_style(mgr, SRV_CLOG_STYLE_TYPE_SIM_SYNC, &merge_style, NULL);

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_STL_DUMP, num_style, merge_style, phb_sync_style, sim_sync_style);

    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_STL_DUMP,
                   "\n[CLogSrv]srv_clog_stl_dump():--> num_style=0x%x, merge_style=0x%x, phb_sync=0x%x, sim_sync=0x%x"),
                  num_style, merge_style, phb_sync_style, sim_sync_style));

    for (i = 0; i < SRV_CLOG_STL_MAX_BIT_SLOT_NUM; i++)
    {
        MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_STL_DUMP_VALUE, mgr->bit_styles[i]);
        SRV_CLOG_TRC((SRV_CLOG_TS(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_STL_DUMP_VALUE, "[CLogSrv]value=0x%x "),
                      mgr->bit_styles[i]));
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_st_dump
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_st_dump(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_CNTX_DUMP))
        return;

    if (!cntx || !cntx->comp)
        return;

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_ST_DUMP, 0, NVRAM_EF_CLOG_LOG_LID, SRV_CLOG_LOG_MAX_NUM);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_ST_DUMP,
                   "\n[CLogSrv]srv_clog_st_dump(store_type=%d,lid=%d,rec_max_num=%d)"),
                   0, NVRAM_EF_CLOG_LOG_LID, SRV_CLOG_LOG_MAX_NUM));
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_dump
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_job_dump(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 num;
    srv_clog_job_struct *job;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_job_mgr_struct *mgr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_CNTX_DUMP))
        return;

    if (!cntx || !cntx->comp || !cntx->comp->job_mgr)
        return;
    mgr = cntx->comp->job_mgr;

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_JOB_DUMP, 0);
    SRV_CLOG_TRC((SRV_CLOG_TS(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_JOB_DUMP, "\n[CLogSrv]srv_clog_job_dump(%d):-->"), 0));
    num = srv_clog_job_num(mgr);
    for (i = 0; i < num; i++)
    {
        job = srv_clog_job_index(mgr, i);
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_JOB_DUMP_INFO,
            i,
            job->job_type,
            job->job_state,
            job->proc_state,
            job->pid,
            job->init_value,
            job->req_data);
        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_JOB_DUMP_INFO,
                       "[CLogSrv]idx=%d,job_type=%d,job_state=%d,proc_state=%d,pid=%d,init_val=%d,req_data=0x%x"), i,
                      job->job_type, job->job_state, job->proc_state, job->pid, job->init_value, job->req_data));

    }
    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_JOB_DUMP, 1);
    SRV_CLOG_TRC((SRV_CLOG_TS(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_JOB_DUMP, "[CLogSrv]srv_clog_job_dump(%d):-->"), 1));
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_dump
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_si_dump(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    srv_clog_si_struct *si_log;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_si_tbl_struct *si_tbl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_CNTX_DUMP))
        return;
    if (!cntx || !cntx->comp || !cntx->comp->si_tbl)
        return;

    si_tbl = cntx->comp->si_tbl;

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SI_DUMP, 0);
    SRV_CLOG_TRC((SRV_CLOG_TS(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SI_DUMP, "\n[CLogSrv]srv_clog_si_dump(%d):-->"), 0));

    for (i = 0, j = 0; i < SRV_CLOG_LOG_MAX_NUM; i++)
    {
        si_log = srv_clog_si_index(si_tbl, i);
        if (!srv_clog_si_is_valid(si_log))
            continue;
        srv_clog_si_dump_log(i, si_log);
        j++;
        if (j > 200)
            break;
    }

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SI_DUMP, 1);
    SRV_CLOG_TRC((SRV_CLOG_TS(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SI_DUMP, "[CLogSrv]srv_clog_si_dump(%d):-->"), 1));
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_dump_log_by_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_si_dump_log_by_idx(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_si_tbl_struct *si_tbl;
    srv_clog_si_struct *si_log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_CNTX_DUMP))
        return;

    if (!cntx || !cntx->comp || !cntx->comp->si_tbl)
        return;
    si_tbl = cntx->comp->si_tbl;

    si_log = srv_clog_si_index(si_tbl, index);
    srv_clog_si_dump_log(index, (srv_clog_si_struct*) si_log);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_dump_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 *  log_data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_si_dump_log(U32 index, void *log_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cate_idx;
    U32 sim_idx;
    U32 lt_idx;
    U32 st_idx;
    U32 local_sec;
    SRV_PHB_ID phb_id;
    applib_time_struct app_time;
    srv_clog_si_struct *si_log = (srv_clog_si_struct*) log_data;
    CHAR asc_name[SRV_CLOG_NAME_MAX_LEN + 1] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_CNTX_DUMP))
        return;

    if (!srv_clog_si_is_valid(si_log))
        return;
    phb_id = SRV_CLOG_SI_GET_PHB_ID(si_log);
    local_sec = applib_dt_sec_utc_to_local(si_log->base_log.timestamp[SRV_CLOG_LASTEST_TIME_IDX]);
    applib_dt_utc_sec_2_mytime(local_sec, &app_time, MMI_FALSE);

    srv_clog_pi_p2idx(SRV_CLOG_SI_GET_P(si_log), &cate_idx, &sim_idx, &lt_idx, &st_idx);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SI_DUMP_LOG_VALUE,
        index,
        SRV_CLOG_SI_GET_LOG_ID(si_log),
        SRV_CLOG_SI_GET_P(si_log),
        cate_idx,
        sim_idx,
        lt_idx,
        st_idx,
        phb_id,
        phb_id.storage_type,
        phb_id.number_index,
        phb_id.contact_index,
        app_time.nYear,
        app_time.nMonth,
        app_time.nDay,
        app_time.nHour,
        app_time.nMin,
        app_time.nSec,
        SRV_CLOG_SI_GET_URNUM(si_log),
        SRV_CLOG_SI_GET_TNUM(si_log));

    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SI_DUMP_LOG_VALUE,
                   "[CLogSrv]%d: id=%d,p=0x%x(%d:%d:%d:%d),pid=0x%x(%d:%d:%d), %d-%d-%d %d:%d:%d, num=%d/%d"),
                  index, SRV_CLOG_SI_GET_LOG_ID(si_log), SRV_CLOG_SI_GET_P(si_log), cate_idx, sim_idx, lt_idx, st_idx,
                  phb_id, phb_id.storage_type, phb_id.number_index, phb_id.contact_index, app_time.nYear,
                  app_time.nMonth, app_time.nDay, app_time.nHour, app_time.nMin, app_time.nSec,
                  SRV_CLOG_SI_GET_URNUM(si_log), SRV_CLOG_SI_GET_TNUM(si_log)));


    if (!SRV_CLOG_IS_STR_EMPTY(SRV_CLOG_SI_GET_NAME(si_log)))
    {
        if (srv_clog_is_ascii_string(SRV_CLOG_SI_GET_NAME(si_log)))
            mmi_wcs_to_asc(asc_name, (WCHAR*) SRV_CLOG_SI_GET_NAME(si_log));
        else
            memcpy(asc_name, "ucs-name", sizeof("ucs-name"));
    }
    MMI_PRINT(MOD_MMI_COMMON_APP,
              SRV_CLOG_TRC_INFO,
              "[CLogSrv]srv_clog_si_dump_log---> %d: cid=%s,name=%s",
              index,
              SRV_CLOG_SI_GET_CID(si_log),
              asc_name);

    SRV_CLOG_TRC((SRV_CLOG_TS
                 (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SI_DUMP_LOG_STRING,
                 "[CLogSrv]srv_clog_si_dump_log---> %d: cid=%s,name=%s"), index, SRV_CLOG_SI_GET_CID(si_log),
                 asc_name));

}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_dump
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_idx_dump(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_idx_tbl_struct *idx_tbl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_CNTX_DUMP))
        return;

    if (!cntx || !cntx->comp || !cntx->comp->idx_tbl)
        return;
    idx_tbl = cntx->comp->idx_tbl;

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_DUMP, 0, idx_tbl->last_get_idx);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_DUMP, "\n[CLogSrv]srv_clog_idx_dump(%d):-->last_get_idx=%d"), 0,
                  idx_tbl->last_get_idx));

    for (i = 0; i < SRV_CLOG_IDX_INFO_MAX_ITEM; i++)
    {
        srv_clog_idx_dump_info(i);
    }

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_DUMP_END, 1);
    SRV_CLOG_TRC((SRV_CLOG_TS(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_DUMP_END, "[CLogSrv]srv_clog_idx_dump(%d):-->"), 1));
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_dump_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_clog_idx_dump_info(U32 info_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define SRV_CLOG_IDX_LINE_NUM   (10)    /* Should >= 10 */
    U32 i;
    U32 count;
    U32 remind;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_idx_tbl_struct *idx_tbl;
    srv_clog_idx_info_struct *idx_info;
    U16 idx_list[SRV_CLOG_IDX_LINE_NUM * 2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_CNTX_DUMP))
        return;

    if (!cntx || !cntx->comp || !cntx->comp->idx_tbl)
        return;
    idx_tbl = cntx->comp->idx_tbl;

    memset(idx_list, SRV_CLOG_IDX_INVALID_IDX, sizeof(U16) * (SRV_CLOG_IDX_LINE_NUM * 2));
    idx_info = idx_tbl->idx_info[info_type];
    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_IDX_DUMP_IDX_INFO,
        info_type,
        idx_info->max_size,
        idx_info->total_num,
        idx_info->idt.cate,
        idx_info->idt.sim_id,
        idx_info->idt.log_type,
        idx_info->idt.sub_type);

    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_DUMP_IDX_INFO,
                   "[CLogSrv] ---->info_type=%d, max_size=%d, total_num=%d,idt=0x%x:0x%x:0x%x:0x%x  ---->"), info_type,
                  idx_info->max_size, idx_info->total_num, idx_info->idt.cate, idx_info->idt.sim_id,
                  idx_info->idt.log_type, idx_info->idt.sub_type));

    if (idx_info->total_num % SRV_CLOG_IDX_LINE_NUM == 0)
        count = idx_info->total_num / SRV_CLOG_IDX_LINE_NUM;
    else
        count = idx_info->total_num / SRV_CLOG_IDX_LINE_NUM + 1;

    remind = idx_info->total_num % SRV_CLOG_IDX_LINE_NUM;

    for (i = 0; i < count; i++)
    {
        if (remind == 0 || i != count - 1)  /* has remind */
            memcpy(idx_list, (idx_info->data) + i * SRV_CLOG_IDX_LINE_NUM, sizeof(U16) * SRV_CLOG_IDX_LINE_NUM);
        else
        {
            memcpy(idx_list, (idx_info->data) + i * SRV_CLOG_IDX_LINE_NUM, sizeof(U16) * remind);
            memset(idx_list + remind, SRV_CLOG_IDX_INVALID_IDX, sizeof(U16) * (SRV_CLOG_IDX_LINE_NUM - remind));
        }
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_IDX_DUMP_IDX_INFO_VALUE,
            idx_list[0],
            idx_list[1],
            idx_list[2],
            idx_list[3],
            idx_list[4],
            idx_list[5],
            idx_list[6],
            idx_list[7],
            idx_list[8],
            idx_list[9],
            idx_list[10]);
        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_DUMP_IDX_INFO_VALUE,
                       "[CLogSrv]%4d %4d %4d %4d %4d %4d %4d %4d %4d %4d ->0x%x"), idx_list[0], idx_list[1],
                      idx_list[2], idx_list[3], idx_list[4], idx_list[5], idx_list[6], idx_list[7], idx_list[8],
                      idx_list[9], idx_list[10]));
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_dump_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_idx_dump_num(void)
{
/*----------------------------------------------------------------*/
/* Local Define                                                   */
/*----------------------------------------------------------------*/
#define SRV_CLOG_NUM_STAT_MAX_NUM   (SRV_CLOG_CATE_IDX_MAX_ITEM * SRV_CLOG_SIM_IDX_MAX_ITEM * SRV_CLOG_CLT_IDX_MAX_ITEM * SRV_CLOG_CALL_TYPE_IDX_MAX_ITEM)
            
#define SRV_CLOG_IDX_GET_4ARRAY_IDX(cate_idx, sim_idx, lt_idx, ct_idx)                                                              \
                            ((cate_idx) * (SRV_CLOG_SIM_IDX_MAX_ITEM * SRV_CLOG_CLT_IDX_MAX_ITEM * SRV_CLOG_CALL_TYPE_IDX_MAX_ITEM) +           \
                             (sim_idx) * (SRV_CLOG_CLT_IDX_MAX_ITEM * SRV_CLOG_CALL_TYPE_IDX_MAX_ITEM) +                                        \
                             (lt_idx) * SRV_CLOG_CALL_TYPE_IDX_MAX_ITEM +                                                                       \
                             (ct_idx))
            
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    U32 m;
    U32 n;
    U32 index;
    U32 props;
    U16 *idx_list;
    U32 total_num;
    U32 elm_idx;
    srv_clog_si_struct *si_log;
    srv_clog_num_info_struct clt_num_info;
    srv_clog_num_info_struct sim_num_info;
    srv_clog_idx_tbl_struct *idx_tbl;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_idx_info_struct *base_idx_info;
    U32 mclt_num_list[SRV_CLOG_SIM_IDX_MAX_ITEM];
    srv_clog_num_info_struct *num_list;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_CNTX_DUMP))
        return;

    if (!cntx || !cntx->comp || !cntx->comp->idx_tbl)
        return;
    
    idx_tbl = cntx->comp->idx_tbl;
    base_idx_info = idx_tbl->idx_info[SRV_CLOG_IDX_INFO_BASE];
    idx_list = (U16*) base_idx_info->data;
    total_num = base_idx_info->total_num;

    /* Allocate buffer */
    memset(mclt_num_list, 0x0, sizeof(U32) * SRV_CLOG_SIM_IDX_MAX_ITEM);
    num_list = SRV_CLOG_MALLOC(SRV_CLOG_MEM_TYPE_CTRL_BUF, SRV_CLOG_NUM_STAT_MAX_NUM * sizeof(srv_clog_num_info_struct));
    memset(num_list, 0x0, sizeof(srv_clog_num_info_struct) * SRV_CLOG_NUM_STAT_MAX_NUM);

    /* Collect number information */
    for (elm_idx = 0; elm_idx < total_num; elm_idx++)
    {
        si_log = srv_clog_si_index(idx_tbl->si_tbl, idx_list[elm_idx]);
        SRV_CLOG_IT_ASSERT(srv_clog_si_is_valid(si_log));
        
        props = SRV_CLOG_SI_GET_P(si_log);
        srv_clog_pi_p2idx(props, &i, &j, &m, &n);
        index = SRV_CLOG_IDX_GET_4ARRAY_IDX(i, j, m, n);        
        num_list[index].num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS]++;
        num_list[index].num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM] += SRV_CLOG_SI_GET_URNUM(si_log);
    }

    /* Dump unread missed call number */
    total_num = srv_clog_get_sim_unread_missed_call_num((U32 *) mclt_num_list, SRV_CLOG_SIM_IDX_MAX_ITEM);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_IDX_DUMP_IDX_NUM_STAT,
        total_num,
        mclt_num_list[SRV_CLOG_SIM_IDX_SIM1],
        SRV_CLOG_TRC_SIM_VAL(MMI_SIM2, mclt_num_list[SRV_CLOG_SIM_IDX_SIM2]));
    
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_DUMP_IDX_NUM_STAT,
                   "\n[CLogSrv]srv_clog_idx_dump_num: total_num=%d, ur1=%d, ur2=%d"), total_num,
                   mclt_num_list[SRV_CLOG_SIM_IDX_SIM1],
                   SRV_CLOG_TRC_SIM_VAL(MMI_SIM2, mclt_num_list[SRV_CLOG_SIM_IDX_SIM2])));

    /* Dump detail number information */
    for (i = 0; i < SRV_CLOG_CATE_IDX_MAX_ITEM; i++)
    {
        if (i > SRV_CLOG_CATE_IDX_CALL)
            break;
        
        for (j = 0; j < SRV_CLOG_SIM_IDX_MAX_ITEM; j++)
        {
            /* Only support call here */
            sim_num_info.num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM] = 0;
            sim_num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS] = 0;
            
            for (m = 0; m < SRV_CLOG_CLT_IDX_MAX_ITEM; m++)
            {
                if (m > SRV_CLOG_CLT_IDX_REJED)
                    break;
                clt_num_info.num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM] = 0;
                clt_num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS] = 0;
                
                for (n = 0; n < SRV_CLOG_CALL_TYPE_IDX_MAX_ITEM; n++)
                {
                    index = SRV_CLOG_IDX_GET_4ARRAY_IDX(i, j, m, n);
                    clt_num_info.num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM] += num_list[index].num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM];
                    clt_num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS] += num_list[index].num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS];

                    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_DUMP_IDX_NUM_DATA, 
                          index, i, j, m, n, num_list[index].num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM],
                          num_list[index].num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS]);
                    SRV_CLOG_TRC((SRV_CLOG_TS(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_DUMP_IDX_NUM_DATA, "[CLogSrv]idt(%2d):  %d : %d : %d : %d: %d/%d"),
                          index, i, j, m, n, num_list[index].num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM],
                          num_list[index].num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS]));
                }
                sim_num_info.num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM] += clt_num_info.num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM];
                sim_num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS] += clt_num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS];

                MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_DUMP_IDX_SIM_LT_NUM_DATA,
                       index, i, j, m, SRV_CLOG_ST_ALL,
                       clt_num_info.num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM], clt_num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS]);
                SRV_CLOG_TRC((SRV_CLOG_TS
                       (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_DUMP_IDX_SIM_LT_NUM_DATA,
                       "[CLogSrv]idt(%2d):  %d : %d : %d : %d:  clt---- %d/%d -------\n"), index, i, j, m, SRV_CLOG_ST_ALL,
                       clt_num_info.num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM], clt_num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS]));
             }
             
             MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_DUMP_IDX_SIM_LT_NUM_DATA,
                    index, i, j, SRV_CLOG_LT_ALL, SRV_CLOG_ST_ALL,
                    sim_num_info.num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM], sim_num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS]);
             SRV_CLOG_TRC((SRV_CLOG_TS
                    (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_DUMP_IDX_SIM_LT_NUM_DATA,
                    "[CLogSrv]idt(%2d):  %d : %d : %d : %d:  --sim---- %d/%d -----\n\n"), index, i, j, SRV_CLOG_LT_ALL, SRV_CLOG_ST_ALL,
                    sim_num_info.num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM], sim_num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS]));
        }
    }
    SRV_CLOG_MFREE(SRV_CLOG_MEM_TYPE_CTRL_BUF, num_list);
}

#endif /* __SRV_CLOG_DUMP__ */ 

#endif /* __SRV_CLOG_DEBUG__ */ 






/*----------------------------------------------------------------------------*/
/* Memory Manager                                                             */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_UTILS_MEMORY_MANAGER


/*****************************************************************************
 * FUNCTION
 *  srv_clog_mem_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_mem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_clog_mem_cntx.sys_cur_pos = 0;

#if (SRV_CLOG_MEM_POOL_DYNC_SIZE > SRV_CLOG_MEM_POOL_MIN_DYNC_SIZE)

        g_srv_clog_mem_cntx.adm_id = kal_adm_create(
                                        (void*)((U8*) g_srv_clog_mem_cntx.dync_pool),
                                        (kal_uint32) SRV_CLOG_MEM_POOL_DYNC_SIZE,
                                        NULL,
                                        KAL_FALSE);
#endif

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_MEM_INIT,
        sizeof(g_srv_clog_mem_cntx),
        SRV_CLOG_MEM_POOL_SYS_SIZE,
        SRV_CLOG_MEM_POOL_DYNC_SIZE);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_MEM_INIT, "[CLogSrv]srv_clog_mem_init(total=%d, sys=%d, dync=%d)"),
                  sizeof(g_srv_clog_mem_cntx), SRV_CLOG_MEM_POOL_SYS_SIZE, SRV_CLOG_MEM_POOL_DYNC_SIZE));

#ifdef __SRV_CLOG_MEM_DEBUG__
    {
        U32 i;
        U32 size_count = 0;
        U32 *guard;

        for (i = 0; i < sizeof(g_srv_clog_mem_size_tbl) / sizeof(srv_clog_mem_size_struct); i++)
        {
            if (g_srv_clog_mem_size_tbl[i].num * g_srv_clog_mem_size_tbl[i].size != g_srv_clog_mem_size_tbl[i].total)
                continue;
            size_count += g_srv_clog_mem_size_tbl[i].total;
        }

        memset(g_srv_clog_mem_cntx.sys_pool, 0xAB, SRV_CLOG_MEM_POOL_SYS_SIZE);
        guard = (U32*) ((U8*) g_srv_clog_mem_cntx.sys_pool + SRV_CLOG_MEM_POOL_SYS_SIZE);
        *guard = SRV_CLOG_MEM_POOL_GUARD;
    }
#endif /* __SRV_CLOG_MEM_DEBUG__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_type        [IN]        
 *  size            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_clog_malloc(U32 mem_type, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ASSERT(mem_type < SRV_CLOG_MEM_TYPE_MAX_ITEM);

    if (g_srv_clog_mem_op_tbl[mem_type].malloc)
    {
        p = g_srv_clog_mem_op_tbl[mem_type].malloc(size);

    #ifdef __SRV_CLOG_MEM_DEBUG__
        {
            U32 *guard;

            if (p)
                memset(p, 0xCD, size);
            guard = (U32*) ((U8*) g_srv_clog_mem_cntx.sys_pool + SRV_CLOG_MEM_POOL_SYS_SIZE);
            SRV_CLOG_ASSERT(*guard == SRV_CLOG_MEM_POOL_GUARD);
        }
    #endif /* __SRV_CLOG_MEM_DEBUG__ */ 
        return p;
    }

    return NULL;
}

#if 0 //FlowReserved
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
#if (SRV_CLOG_MEM_POOL_DYNC_SIZE > SRV_CLOG_MEM_POOL_MIN_DYNC_SIZE)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0


/*****************************************************************************
 * FUNCTION
 *  srv_clog_mfree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_type        [IN]        
 *  p               [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_mfree(U32 mem_type, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ASSERT(mem_type < SRV_CLOG_MEM_TYPE_MAX_ITEM);

    if (g_srv_clog_mem_op_tbl[mem_type].mfree)
        g_srv_clog_mem_op_tbl[mem_type].mfree(p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sys_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void *srv_clog_sys_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ASSERT(size > 0 &&
                    (g_srv_clog_mem_cntx.sys_cur_pos + SRV_CLOG_4BYTES_ALIGN(size) <= SRV_CLOG_MEM_POOL_SYS_SIZE));

    if (size == 0)
        return NULL;

    if (g_srv_clog_mem_cntx.sys_cur_pos == 0)
    {
        MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SYS_MALLOC_START);
    }

    p = (U8*) g_srv_clog_mem_cntx.sys_pool + g_srv_clog_mem_cntx.sys_cur_pos;
    g_srv_clog_mem_cntx.sys_cur_pos += SRV_CLOG_4BYTES_ALIGN(size);

#ifdef __SRV_CLOG_MEM_DEBUG__
    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SYS_MALLOC, size, g_srv_clog_mem_cntx.sys_cur_pos, p);

    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SYS_MALLOC,
                   "[CLogSrv]srv_clog_sys_malloc(size=%d,sys_cur_pos=%d,p=%d)"), size, g_srv_clog_mem_cntx.sys_cur_pos,
                  p));
#endif /* __SRV_CLOG_MEM_DEBUG__ */ 

    if (g_srv_clog_mem_cntx.sys_cur_pos == SRV_CLOG_MEM_POOL_SYS_SIZE)
    {
        MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SYS_MALLOC_END);
        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SYS_MALLOC_END,
                       "\n\n[CLogSrv]srv_clog_sys_malloc(End: no sys memory, right!) \n\n")));
    }

    return p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sys_mfree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_sys_mfree(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* may use a simple fixed block allocation mechanism. */
    SRV_CLOG_ASSERT(0);

    MMI_TRACE(SRV_CLOG_TRC_ERROR, TRC_SRV_CLOG_SYS_MFREE, p);
}


#if (SRV_CLOG_MEM_POOL_DYNC_SIZE > SRV_CLOG_MEM_POOL_MIN_DYNC_SIZE)

/*****************************************************************************
 * FUNCTION
 *  srv_clog_dync_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void *srv_clog_dync_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size == 0 || !g_srv_clog_mem_cntx.adm_id)
        return NULL;

    p = kal_adm_alloc(g_srv_clog_mem_cntx.adm_id, (kal_uint32) size);
    if (!p)
    {
    #ifdef __SRV_CLOG_MEM_DEBUG__
        MMI_TRACE(
            SRV_CLOG_TRC_WARNING,
            TRC_SRV_CLOG_DYNC_MALLOC_FAIL,
            size,
            kal_adm_get_total_left_size(g_srv_clog_mem_cntx.adm_id),
            kal_adm_get_max_alloc_size(g_srv_clog_mem_cntx.adm_id));

        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_WARNING, TRC_SRV_CLOG_DYNC_MALLOC_FAIL,
                       "[CLogSrv]srv_clog_dync_malloc(size=%d,total_left=%d,max_alloc_size=%d"), size,
                      kal_adm_get_total_left_size(g_srv_clog_mem_cntx.adm_id),
                      kal_adm_get_max_alloc_size(g_srv_clog_mem_cntx.adm_id)));

    #endif /* __SRV_CLOG_MEM_DEBUG__ */ 

        return NULL;
    }

#ifdef __SRV_CLOG_MEM_DEBUG__

    MMI_TRACE(
        SRV_CLOG_TRC_WARNING,
        TRC_SRV_CLOG_DYNC_MALLOC_OK,
        size,
        kal_adm_get_total_left_size(g_srv_clog_mem_cntx.adm_id),
        kal_adm_get_max_alloc_size(g_srv_clog_mem_cntx.adm_id),
        p);

    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_WARNING, TRC_SRV_CLOG_DYNC_MALLOC_OK,
                   "[CLogSrv]srv_clog_dync_malloc(size=%d,total_left=%d,max_alloc_size=%d, p=%d"), size,
                  kal_adm_get_total_left_size(g_srv_clog_mem_cntx.adm_id),
                  kal_adm_get_max_alloc_size(g_srv_clog_mem_cntx.adm_id), p));
#endif /* __SRV_CLOG_MEM_DEBUG__ */ 

    return p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_dync_mfree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_dync_mfree(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!p || !g_srv_clog_mem_cntx.adm_id)
        return;

    kal_adm_free(g_srv_clog_mem_cntx.adm_id, p);
}
#endif /* SRV_CLOG_MEM_POOL_DYNC_SIZE <= SRV_CLOG_MEM_POOL_MIN_DYNC_SIZE */


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ctrl_buf_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void *srv_clog_ctrl_buf_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return OslMalloc(size);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ctrl_buf_mfree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ctrl_buf_mfree(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OslMfree(p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_temp_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void *srv_clog_temp_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (SRV_CLOG_MEM_POOL_DYNC_SIZE > SRV_CLOG_MEM_POOL_MIN_DYNC_SIZE)
    void *p;

    p = srv_clog_dync_malloc(size);
    if (p)
        return p;
#endif

    return srv_clog_ctrl_buf_malloc(size);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_temp_mfree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_temp_mfree(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (SRV_CLOG_MEM_POOL_DYNC_SIZE > SRV_CLOG_MEM_POOL_MIN_DYNC_SIZE)

    if ((U8*) p >= g_srv_clog_mem_cntx.dync_pool &&
        (U8*) p < g_srv_clog_mem_cntx.dync_pool + SRV_CLOG_MEM_POOL_DYNC_SIZE)
    {
        srv_clog_dync_mfree(p);
    }
    else
    {
        srv_clog_ctrl_buf_mfree(p);
    }
#else
        srv_clog_ctrl_buf_mfree(p);
#endif
}

/*----------------------------------------------------------------------------*/
/* Send ILM                                                                   */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_UTILS_SEND_ILM


/*****************************************************************************
 * FUNCTION
 *  srv_clog_send_l4c_ilm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id_grp          [IN]    It can be bit group        
 *  msg_id              [IN]        
 *  local_data          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_send_l4c_ilm(mmi_sim_enum sim_id_grp, U16 msg_id, void *local_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    module_type mod_id;
    mmi_sim_enum  sim_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ASSERT(SRV_CLOG_CHECK_BIT(sim_id_grp, SRV_CLOG_SIM_ID_ALL));

    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {
        sim_id = (mmi_sim_enum)SRV_CLOG_IDX2BIT(i);
        if (!SRV_CLOG_CHECK_BIT(sim_id_grp, sim_id))
            continue;
        mod_id = mmi_frm_sim_to_l4c_mod(sim_id);
        mmi_frm_send_ilm(mod_id, (oslMsgType)msg_id, local_data, NULL);
    }
}


/*----------------------------------------------------------------------------*/
/* String operation                                                           */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_UTILS_STRING



/*****************************************************************************
 * FUNCTION
 *  srv_clog_comp_asc_cid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cid1        [?]     
 *  cid2        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_comp_asc_cid(CHAR *cid1, CHAR *cid2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    /* The call stack is ok for this  even customer enlarge the number to 100 */
    WCHAR w_cid1[SRV_CLOG_CID_MAX_LEN + 1]; 
    WCHAR w_cid2[SRV_CLOG_CID_MAX_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_wcs(w_cid1, cid1, SRV_CLOG_CID_MAX_LEN);
    mmi_asc_n_to_wcs(w_cid2, cid2, SRV_CLOG_CID_MAX_LEN);
    ret = srv_phb_compare_number(w_cid1, w_cid2);
    return ret;
}


/*----------------------------------------------------------------------------*/
/* Parameter operation                                                        */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_UTILS_PARAM_OPERATION


/*****************************************************************************
 * FUNCTION
 *  srv_clog_init_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para_type       [IN]        
 *  para_data       [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_init_para(srv_clog_para_enum para_type, void *para_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ASSERT(para_type < SRV_CLOG_PARA_MAX_ITEM && para_data);

    size = srv_clog_get_para_size(para_type);
    memset(para_data, 0x0, size);

    switch (para_type)
    {
        case SRV_CLOG_PARA_SEARCH_LIST_LOG_IDS_REQ:
        {
            srv_clog_search_list_log_ids_req_struct *req_data;

            req_data = (srv_clog_search_list_log_ids_req_struct*) para_data;
            memset(req_data->phb_idx, 0xFFFF, sizeof(U16) * SRV_CLOG_PHB_IDX_MAX_SEARCH_NUM);
            break;
        }

        case SRV_CLOG_PARA_LOG_CALL_REQ:
        {
            srv_clog_log_call_req_struct *req_data;

            req_data = (srv_clog_log_call_req_struct*) para_data;
            SRV_CLOG_SET_INVALID_PHB_ID(req_data->phb_id);
            break;
        }

        case SRV_CLOG_PARA_LOG:
        {
            srv_clog_log_struct *log;

            log = (srv_clog_log_struct*) para_data;
            SRV_CLOG_SET_INVALID_PHB_ID(log->data.call_log.phb_id);
            break;
        }

        default:
            break;

    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_para_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U32 srv_clog_get_para_size(srv_clog_para_enum para_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_IT_ASSERT(para_type < sizeof(g_srv_clog_para_size_tbl)/sizeof(srv_clog_para_size_struct));
    
    return g_srv_clog_para_size_tbl[para_type].para_size;
}



/*----------------------------------------------------------------------------*/
/* Property and Identity operation (PI)                                     */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_UTILS_PI_OPERATION


/*****************************************************************************
 * FUNCTION
 *  srv_clog_pi_is_i_invalid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_pi_is_i_invalid(const srv_clog_log_identity_struct *idt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* allow NULL value which means to get all logs without any identity as filter */
    if (!idt)
        return MMI_FALSE;

    if (!SRV_CLOG_CHECK_BIT_GRP(idt->cate, SRV_CLOG_CATE_ALL, idt->cate))
        return MMI_TRUE;

    if (!SRV_CLOG_CHECK_BIT_GRP(idt->sim_id, SRV_CLOG_SIM_ID_ALL, idt->sim_id))
        return MMI_TRUE;

    if (!SRV_CLOG_CHECK_BIT_GRP(idt->log_type, SRV_CLOG_LT_ALL, idt->log_type))
        return MMI_TRUE;

    if (!SRV_CLOG_CHECK_BIT_GRP(idt->sub_type, SRV_CLOG_CALL_TYPE_ALL, idt->sub_type))
        return MMI_TRUE;

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_pi_p2idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  props           [IN]        
 *  cate_idx        [?]         
 *  sim_idx         [?]         
 *  lt_idx          [?]         
 *  st_idx          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_pi_p2idx(U32 props, U32 *cate_idx, U32 *sim_idx, U32 *lt_idx, U32 *st_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *cate_idx = SRV_CLOG_PI_P2IDX(props, SRV_CLOG_LSP_CATE, SRV_CLOG_LSP_CATE_POS);
    *sim_idx = SRV_CLOG_PI_P2IDX(props, SRV_CLOG_LSP_SIM_ID, SRV_CLOG_LSP_SIM_ID_POS);
    *lt_idx = SRV_CLOG_PI_P2IDX(props, SRV_CLOG_LSP_LT, SRV_CLOG_LSP_LT_POS);
    *st_idx = SRV_CLOG_PI_P2IDX(props, SRV_CLOG_LSP_ST, SRV_CLOG_LSP_ST_POS);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_pi_p2i
 * DESCRIPTION
 *  
 * PARAMETERS
 *  props           [IN]        
 *  identity        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_pi_p2i(U32 props, srv_clog_log_identity_struct *identity)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = SRV_CLOG_PI_P2IDX(props, SRV_CLOG_LSP_CATE, SRV_CLOG_LSP_CATE_POS);
    identity->cate = SRV_CLOG_IDX2BIT(idx);
    idx = SRV_CLOG_PI_P2IDX(props, SRV_CLOG_LSP_SIM_ID, SRV_CLOG_LSP_SIM_ID_POS);
    identity->sim_id = SRV_CLOG_IDX2BIT(idx);
    idx = SRV_CLOG_PI_P2IDX(props, SRV_CLOG_LSP_LT, SRV_CLOG_LSP_LT_POS);
    identity->log_type = SRV_CLOG_IDX2BIT(idx);
    idx = SRV_CLOG_PI_P2IDX(props, SRV_CLOG_LSP_ST, SRV_CLOG_LSP_ST_POS);
    identity->sub_type = SRV_CLOG_IDX2BIT(idx);
}

/* identity should not use as filter */


/*****************************************************************************
 * FUNCTION
 *  srv_clog_pi_i2p
 * DESCRIPTION
 *  
 * PARAMETERS
 *  identity        [?]     
 *  props           [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_pi_i2p(srv_clog_log_identity_struct *identity, U32 *props)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_BIT2IDX(identity->cate, idx);
    SRV_CLOG_PI_IDX2P(*props, idx, SRV_CLOG_LSP_CATE_POS);

    SRV_CLOG_BIT2IDX(identity->sim_id, idx);
    SRV_CLOG_PI_IDX2P(*props, idx, SRV_CLOG_LSP_SIM_ID_POS);

    SRV_CLOG_BIT2IDX(identity->log_type, idx);
    SRV_CLOG_PI_IDX2P(*props, idx, SRV_CLOG_LSP_LT_POS);

    SRV_CLOG_BIT2IDX(identity->sub_type, idx);
    SRV_CLOG_PI_IDX2P(*props, idx, SRV_CLOG_LSP_ST_POS);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_pi_is_ii_sub
 * DESCRIPTION
 *  src can be filter, but dst can not bu filter, every field should is valid value
 * PARAMETERS
 *  src     [?]     
 *  dst     [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_pi_is_ii_sub(srv_clog_log_identity_struct *src, srv_clog_log_identity_struct *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src->cate != 0)
    {
        if (dst->cate == 0 && src->cate != SRV_CLOG_CATE_ALL)
            return MMI_FALSE;
        if (dst->cate != 0 && !SRV_CLOG_CHECK_BIT_GRP(src->cate, dst->cate, dst->cate))
            return MMI_FALSE;
    }

    if (src->sim_id != 0)
    {
        if (dst->sim_id == 0 && src->sim_id != SRV_CLOG_SIM_ID_ALL)
            return MMI_FALSE;
        if (dst->sim_id != 0 && !SRV_CLOG_CHECK_BIT_GRP(src->sim_id, dst->sim_id, dst->sim_id))
            return MMI_FALSE;
    }

    if (src->log_type != 0)
    {
        if (dst->log_type == 0 &&
            (src->cate == SRV_CLOG_CATE_CALL && src->log_type != SRV_CLOG_CLT_ALL))
        {
            return MMI_FALSE;
        }
        if (dst->log_type != 0 && !SRV_CLOG_CHECK_BIT_GRP(src->log_type, dst->log_type, dst->log_type))
            return MMI_FALSE;
    }

    /* For SMS and NWPD, no sub_type yet */
    if (src->sub_type != 0)
    {
        if (dst->sub_type == 0 && (src->cate == SRV_CLOG_CATE_CALL && src->sub_type != SRV_CLOG_CALL_TYPE_ALL))
        {
            return MMI_FALSE;
        }
        if (dst->sub_type != 0 && !SRV_CLOG_CHECK_BIT_GRP(src->sub_type, dst->sub_type, dst->sub_type))
            return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_pi_is_ip_sub
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idt         [?]         
 *  props       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_pi_is_ip_sub(srv_clog_log_identity_struct *idt, U32 props)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_log_identity_struct dst_idt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_pi_p2i(props, &dst_idt);
    return srv_clog_pi_is_ii_sub(idt, &dst_idt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_pi_merge_ii_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_f       [IN]        
 *  dst_f       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_pi_merge_ii_field(U8 src_f, U8 dst_f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src_f != 0)
    {
        if (dst_f == 0)
            dst_f = src_f;
        else
            dst_f = SRV_CLOG_GET_BIT(src_f, dst_f);
    }
    return dst_f;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_pi_merge_ii
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_idt     [?]     
 *  dst_idt     [?]     
 *  out_idt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_pi_merge_ii(
        srv_clog_log_identity_struct *src_idt,
        srv_clog_log_identity_struct *dst_idt,
        srv_clog_log_identity_struct *out_idt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_log_identity_struct *tmp_cpy_idt = src_idt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK (!out_idt, SRV_CLOG_RET_INVALID_PARAM);
    SRV_CLOG_PARAM_CHECK (!src_idt && !dst_idt, SRV_CLOG_RET_INVALID_PARAM);

    if (! (src_idt && dst_idt))
    {
        if (!src_idt)
            tmp_cpy_idt = dst_idt;
        
        memcpy(out_idt, tmp_cpy_idt, sizeof(srv_clog_log_identity_struct));
        return SRV_CLOG_RET_OK;
    }
    
    out_idt->cate = srv_clog_pi_merge_ii_field(src_idt->cate, dst_idt->cate);
    out_idt->sim_id = srv_clog_pi_merge_ii_field(src_idt->sim_id, dst_idt->sim_id);
    out_idt->log_type = srv_clog_pi_merge_ii_field(src_idt->log_type, dst_idt->log_type);
    out_idt->sub_type = srv_clog_pi_merge_ii_field(src_idt->sub_type, dst_idt->sub_type);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_pi_is_ii_equal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [?]     
 *  dst     [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_pi_is_ii_equal(srv_clog_log_identity_struct *src, srv_clog_log_identity_struct *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == memcmp((const void*)src, (const void*)dst, sizeof(srv_clog_log_identity_struct)))
        return MMI_TRUE;

    /* TO do: check 0??? */
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_pi_reset_i
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idt     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_pi_reset_i(srv_clog_log_identity_struct *idt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idt->cate = SRV_CLOG_CATE_ALL;
    idt->sim_id = SRV_CLOG_SIM_ID_ALL;
    idt->log_type = SRV_CLOG_LT_ALL;
    idt->sub_type = SRV_CLOG_ST_ALL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_pi_revise_i
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idt             [?]         
 *  is_filter       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_log_identity_struct *srv_clog_pi_revise_i(srv_clog_log_identity_struct *idt, S32 is_filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!idt)
        return NULL;

    /* work as filter */
    if (is_filter)
    {
        if (idt->cate == 0)
            idt->cate = SRV_CLOG_CATE_ALL;
        if (idt->sim_id == 0)
            idt->sim_id = SRV_CLOG_SIM_ID_ALL;
        if (idt->log_type == 0)
            idt->log_type = SRV_CLOG_CLT_ALL;
        if (idt->sub_type == 0)
            idt->sub_type = SRV_CLOG_CALL_TYPE_ALL;
    }
    else
    {
        if (idt->cate == 0)
            idt->cate = SRV_CLOG_CATE_CALL;
        if (idt->sim_id == 0)
            idt->sim_id = MMI_SIM1;
        if (idt->log_type == 0)
            idt->log_type = SRV_CLOG_CLT_DIALED;
        if (idt->sub_type == 0)
            idt->sub_type = SRV_CLOG_CALL_TYPE_VOICE;
    }
    return idt;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_pi_cp_i
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_idt     [?]     
 *  dst_idt     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_pi_cp_i(srv_clog_log_identity_struct *src_idt, srv_clog_log_identity_struct *dst_idt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ASSERT(src_idt && dst_idt);

    memcpy(dst_idt, src_idt, sizeof(srv_clog_log_identity_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_pi_get_clt_max_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_idx     [IN]        
 *  clt_idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_clog_pi_get_clt_max_size(mmi_sim_enum sim_id, srv_clog_clt_enum clt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 max_size;
    U32 clt_idx = SRV_CLOG_CLT_MAX_ITEM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == MMI_SIM_ALL && clt_id == SRV_CLOG_CLT_ALL)
        return SRV_CLOG_LOG_MAX_NUM;

    if (clt_id != SRV_CLOG_CLT_ALL)
        SRV_CLOG_BIT2IDX(clt_id, clt_idx);
    
    SRV_CLOG_IT_ASSERT(clt_idx < sizeof(g_srv_clog_clt_max_size_tbl) / sizeof(srv_clog_clt_log_num_map_struct));

    max_size = g_srv_clog_clt_max_size_tbl[clt_idx].log_num;

    if (sim_id != MMI_SIM_ALL) /* Check if limited by SIM id */
        max_size /= MMI_SIM_TOTAL;
    return max_size;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_pi_get_num_limit_by_p
 * DESCRIPTION
 *  
 * PARAMETERS
 *  props           [IN]        
 *  type_idt        [?]         
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_clog_pi_get_num_limit_by_p(U32 num_style, U32 props, srv_clog_log_identity_struct *type_idt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 limit = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_pi_p2i(props, type_idt);
    if (!SRV_CLOG_CHECK_BIT(num_style, SRV_CLOG_STYLE_NUM_SIM_LIMITED))
        type_idt->sim_id = SRV_CLOG_SIM_ID_ALL;

    if (!SRV_CLOG_CHECK_BIT(num_style, SRV_CLOG_STYLE_NUM_TYPE_LIMITED))
        type_idt->log_type = SRV_CLOG_CLT_ALL;
    switch (type_idt->cate)
    {
        case SRV_CLOG_CATE_CALL:
            limit = srv_clog_pi_get_clt_max_size((mmi_sim_enum)type_idt->sim_id, (srv_clog_clt_enum)type_idt->log_type);
            break;

        default:
            SRV_CLOG_ASSERT(0);
            break;
    }
    return limit;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_pi_is_p_support
 * DESCRIPTION
 *  This API is used to verify if projects version is changed or not.
 * PARAMETERS
 *  props       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_pi_is_p_support(U32 props)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_log_identity_struct idt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_pi_p2i(props, &idt);

    /* only support call log now */
    if (idt.cate != SRV_CLOG_CATE_CALL)
        return MMI_FALSE;

    if (!SRV_CLOG_CHECK_BIT(idt.sim_id, SRV_CLOG_SIM_ID_ALL))
        return MMI_FALSE;

#ifndef __MMI_VIDEO_TELEPHONY__
    if (idt.sub_type == SRV_CLOG_CALL_TYPE_VIDEO)
        return MMI_FALSE;
#endif /* __MMI_VIDEO_TELEPHONY__ */ 

#ifndef __MMI_VOIP__
    if (idt.sub_type == SRV_CLOG_CALL_TYPE_VOIP)
        return MMI_FALSE;
#endif /* __MMI_VOIP__ */ 

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ib_bit2idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_clog_ib_bit2idx(U32 bit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx = 0;                                                    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((idx < sizeof(U32) * 8) && !((0x01 << idx) & bit))    
    {                                                           
        idx++;                                                  
    }                                                           
   return idx;     
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_id_clog2ps
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
 U32 srv_clog_sim_id_clog2ps(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    static const sim_interface_enum  ps_sim_tbl[] = {
        SIM1, 
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))
        SIM2,
#endif

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
        SIM3,
#endif

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 4))
        SIM4
#endif
        };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = SRV_CLOG_BIT2IDX(sim_id, index);
    SRV_CLOG_ASSERT(index < SRV_CLOG_SIM_IDX_MAX_ITEM);

    return ps_sim_tbl[index];
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_is_single_sim_replaced
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_clog_is_single_sim_replaced(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    smu_sim_status_enum  sim_status;

#ifdef __GEMINI__
    U32 simInterface = srv_clog_sim_id_clog2ps(sim_id);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_status = check_sim_status((kal_uint8)simInterface);

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IS_SINGLE_SIM_REPLACED, sim_id, sim_status, 0);

    if ( sim_status == SMU_SIM_REPLACED)
        return MMI_TRUE;
    
#else /* __GEMINI__ */ 

    sim_status = check_sim_status();

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IS_SINGLE_SIM_REPLACED, sim_id, sim_status, 0);
    if (sim_id == MMI_SIM1 &&  sim_status == SMU_SIM_REPLACED)
        return MMI_TRUE;

#endif /* __GEMINI__ */ 

    return MMI_FALSE;
}

#endif /* __MMI_TELEPHONY_SUPPORT__ */




