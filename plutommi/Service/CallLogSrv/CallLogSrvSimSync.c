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
*  CallLogSrvSimSync.c
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "mmi_include.h"

#include "string.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "ps_public_utility.h"

#include "mmi_msg_struct.h"
#include "sim_common_enums.h"
#include "smu_common_enums.h"
#include "l4c2phb_enums.h"
#include "l4c_aux_struct.h"
#include "sim_public_api.h"

#include "custom_calllog.h"

#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_utility_gprot.h"
#include "mmi_frm_queue_gprot.h"

#include "ProcedureGprot.h"
#include "SimCtrlSrvGprot.h"
#include "ShutDownSrvGprot.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvComp.h"
#include "CallLogSrvProt.h"

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
#define  SRV_CLOG_SIM_SUPPORT_CALL_TYPE                 (SRV_CLOG_CALL_TYPE_NON_VOIP)

#define  SRV_CLOG_SIM_FSM_FLAG_CLEAR_ALL_DONE            (0x0001)

/*
 * Can only be 1 now because L4PHB only can process one requirement at one time
 */
#define  SRV_CLOG_SIM_MAX_SYNC_ACT_NUM                  (2)     /* can only be PHB_CONCURRENCY_DEGREE - 1 now which is defined in L4PHB */

#define  SRV_CLOG_SIM_MAX_SYNC_DEL_ACT_NUM              (2)
#define  SRV_CLOG_SIM_MAX_SYNC_READ_ACT_NUM             (2)
#define  SRV_CLOG_SIM_MAX_SYNC_WRITE_ACT_NUM            (2)

#if (SRV_CLOG_SIM_MAX_SYNC_DEL_ACT_NUM > SRV_CLOG_SIM_MAX_SYNC_ACT_NUM || SRV_CLOG_SIM_MAX_SYNC_READ_ACT_NUM > SRV_CLOG_SIM_MAX_SYNC_ACT_NUM || SRV_CLOG_SIM_MAX_SYNC_WRITE_ACT_NUM > SRV_CLOG_SIM_MAX_SYNC_ACT_NUM)
#error "Not support so large sync action in CallLogSrvSimSync.c, please decrease it!"
#endif 

/* it's 255 according to spec index, to large a number to support can cause a very pool performance, 
   It's strangly not to set it to a value large than 20 for one SIM card */
#define  SRV_CLOG_SIM_EF_RECORD_MAX_SUP_NUM              (50)
#define  SRV_CLOG_SIM_EF_INVALID_NUM                     ((U16)(~0))

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/
typedef struct srv_clog_sim_sync_req_st srv_clog_sim_sync_req_struct;

typedef S32(*SRV_CLOG_SIM_NOTIFY_PROC) (srv_clog_sim_sync_req_struct *req_data,
                                        mmi_sim_enum sim_id, srv_clog_clt_enum clt_type, srv_clog_ret_enum ret);

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
typedef enum
{
    SRV_CLOG_SIM_SYNC_TYPE_PWON_READ,   /* read SIM only power on */
    SRV_CLOG_SIM_SYNC_TYPE_CMN_READ,    /* read SIM at anytime */
    SRV_CLOG_SIM_SYNC_TYPE_PWOF_WRITE,  /* write SIM only power off */
    SRV_CLOG_SIM_SYNC_TYPE_CMN_WRITE,   /* write SIM at anytime */
    SRV_CLOG_SIM_SYNC_TYPE_SIM_REFRESH, /* SIM refresh */
    SRV_CLOG_SIM_SYNC_TYPE_SAT_REFRESH, /* SAT refresh */
    SRV_CLOG_SIM_SYNC_TYPE_MAX_ITEM
} srv_clog_sim_sync_type_enum;

typedef enum
{
    SRV_CLOG_JOB_SIM_SYNC_STATE_INIT,
    SRV_CLOG_JOB_SIM_SYNC_STATE_START,
    SRV_CLOG_JOB_SIM_SYNC_STATE_DELETING,
    SRV_CLOG_JOB_SIM_SYNC_STATE_READING,
    SRV_CLOG_JOB_SIM_SYNC_STATE_DONE,
    SRV_CLOG_JOB_SIM_SYNC_STATE_MAX_ITEM
} srv_clog_job_sim_sync_enum;

typedef enum
{
    SRV_CLOG_SIM_STATE_INIT,
    SRV_CLOG_SIM_STATE_PROCESS_FIRST_EF,
    SRV_CLOG_SIM_STATE_PROCESS_NEXT_EF,
    SRV_CLOG_SIM_STATE_DEL_OLD_LOGS,
    SRV_CLOG_SIM_STATE_GET_EF_INFO,
    SRV_CLOG_SIM_STATE_READING,
    SRV_CLOG_SIM_STATE_WRITEING,
    SRV_CLOG_SIM_STATE_DELETING,
    SRV_CLOG_SIM_STATE_FINISHED,
    SRV_CLOG_SIM_STATE_CANCELING,
    SRV_CLOG_SIM_STATE_CANCELED,
    SRV_CLOG_SIM_STATE_MAX_ITEM
} srv_clog_sim_state_enum;

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
typedef struct srv_clog_sim_sync_req_st
{
    srv_clog_sim_sync_type_enum sync_type;
    mmi_sim_enum sim_id;
    srv_clog_clt_enum clt_type[SRV_CLOG_SIM_IDX_MAX_ITEM];
    SRV_CLOG_SIM_NOTIFY_PROC notify_proc;
    void *user_data;
    mmi_frm_proc_id_info_struct frm_proc_id;
} srv_clog_sim_sync_req_struct;

typedef struct
{
    mmi_sim_enum sim_id;
    srv_clog_sim_idx_enum sim_idx;
    srv_clog_clt_enum clt_type[SRV_CLOG_SIM_IDX_MAX_ITEM];
    srv_clog_clt_idx_enum clt_idx;
    srv_clog_ret_enum ret;
} srv_clog_sim_sync_id_struct;

typedef struct
{
    U16 total_rec;
    U16 used_rec;
} srv_clog_sim_ef_info_struct;

typedef struct
{
    U32 flags;
    S32 pid;
    U32 start_log_id;
    srv_clog_sim_state_enum state;
    U32 total_to_write;
    S32 cursor;
    S32 sync_act_cursor;
    srv_clog_ret_enum ret;
    srv_clog_idx_info_enum idx_info_type;
    srv_clog_sim_sync_id_struct cur;
    srv_clog_sim_ef_info_struct ef_info[SRV_CLOG_CLT_IDX_MAX_ITEM];
} srv_clog_sim_fsm_struct;

/* static info */
typedef struct
{
    U32 sync_style;
    srv_clog_cntx_struct *cntx;
    SRV_CLOG_HANDLE handle;
    srv_clog_sim_sync_req_struct req;
    srv_clog_sim_sync_id_struct done;
    U32 start_log_id;
    U32 cur_log_id;
    srv_clog_sim_fsm_struct fsm_list[SRV_CLOG_SIM_IDX_MAX_ITEM];
} srv_clog_sim_mgr_struct;

typedef struct
{
    U8 is_usim;
    srv_clog_clt_enum clt_type;
    sim_file_index_enum file_id;
    sim_service_enum srv_id;
} srv_clog_sim_ef_map_struct;

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static S32 srv_clog_sim_notify_proc_hdlr(
            srv_clog_sim_sync_req_struct *req_data,
            mmi_sim_enum sim_id,
            srv_clog_clt_enum clt_type,
            srv_clog_ret_enum ret);
static void srv_clog_sim_revise_job_req_data(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);
static void srv_clog_sim_set_req_data(srv_clog_sim_sync_req_struct * req_data, 
    srv_clog_sim_sync_type_enum sync_type, void *user_data, mmi_frm_proc_id_info_struct *proc_id_info);

static S32 srv_clog_sim_process_sync(srv_clog_cntx_struct *cntx, srv_clog_sim_sync_req_struct *req);
static srv_clog_sim_mgr_struct *srv_clog_sim_create(void);
static void srv_clog_sim_destroy(srv_clog_sim_mgr_struct *sim_mgr);
static srv_clog_sim_mgr_struct *srv_clog_sim_get_mgr(void);

static srv_clog_sim_fsm_struct *srv_clog_sim_get_fsm_by_pid(srv_clog_sim_mgr_struct *sim_mgr, S32 pid);
static srv_clog_sim_fsm_struct *srv_clog_sim_get_fsm_by_sim_id(srv_clog_sim_mgr_struct *sim_mgr, mmi_sim_enum sim_id);

static void srv_clog_sim_cp_req(srv_clog_sim_sync_req_struct *dst, srv_clog_sim_sync_req_struct *src);
static S32 srv_clog_sim_can_sync(srv_clog_sim_mgr_struct *sim_mgr);
static S32 srv_clog_sim_check_sync_style(srv_clog_sim_mgr_struct *sim_mgr);
static U32 srv_clog_sim_is_sim_replaced(mmi_sim_enum sim_id);
static S32 srv_clog_sim_any_sync(srv_clog_sim_mgr_struct *sim_mgr);
static S32 srv_clog_sim_is_sim_available(mmi_sim_enum sim_id);
static S32 srv_clog_sim_any_sync_clt(mmi_sim_enum sim_id, srv_clog_sim_sync_req_struct *req);

static MMI_BOOL srv_clog_sim_is_ef_srv_sup(mmi_sim_enum sim_id, srv_clog_clt_enum clt_type);
static S32 srv_clog_sim_is_ef_support(mmi_sim_enum sim_id, U16 ef_file_idx, srv_clog_clt_enum *clt_type);
static const srv_clog_sim_ef_map_struct *srv_clog_sim_search_map(mmi_sim_enum sim_id, srv_clog_clt_enum clt_type);
static U32 srv_clog_sim_get_clt_sup(mmi_sim_enum sim_id);


static S32 srv_clog_sim_start_next_sync(srv_clog_sim_mgr_struct *sim_mgr, srv_clog_sim_fsm_struct *fsm);
static S32 srv_clog_sim_get_next_ef(srv_clog_sim_mgr_struct *sim_mgr, srv_clog_sim_fsm_struct *fsm);
static S32 srv_clog_sim_delete_result_hdlr(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            void *req_data,
            void *cnf_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret);
static MMI_BOOL srv_clog_sim_is_read_action(srv_clog_sim_mgr_struct *sim_mgr);
static void srv_clog_sim_sync_cmn_result_hdlr(
                srv_clog_sim_mgr_struct *sim_mgr,
                srv_clog_sim_fsm_struct *fsm,
                srv_clog_ret_enum ret);
static void srv_clog_sim_start_read(srv_clog_sim_mgr_struct *sim_mgr, srv_clog_sim_fsm_struct *fsm);
static void srv_clog_sim_read_next(srv_clog_sim_mgr_struct *sim_mgr, srv_clog_sim_fsm_struct *fsm);
static void srv_clog_sim_start_write(srv_clog_sim_mgr_struct *sim_mgr, srv_clog_sim_fsm_struct *fsm);
static void srv_clog_sim_write_next(srv_clog_sim_mgr_struct *sim_mgr, srv_clog_sim_fsm_struct *fsm);
static void srv_clog_sim_delete_next(srv_clog_sim_mgr_struct *sim_mgr, srv_clog_sim_fsm_struct *fsm);

static void srv_clog_sim_pevt_init(void);
static U8 srv_clog_sim_phb_get_ln_type_info_rsp_hdlr(void *local_param, int mod_id, void *ilm);
static U8 srv_clog_sim_phb_read_sim_ln_rsp_hdlr(void *local_param, int mod_id, void *ilm);
static U8 srv_clog_sim_phb_write_sim_ln_rsp_hdlr(void *local_param, int mod_id, void *ilm);
static U8 srv_clog_sim_phb_delete_sim_ln_rsp_hdlr(void *local_param, int mod_id, void *ilm);

static void srv_clog_sim_send_phb_get_ln_type_info_req(mmi_sim_enum sim_id, srv_clog_clt_enum clt_type);
static void srv_clog_sim_send_phb_read_sim_ln_req(mmi_sim_enum sim_id, srv_clog_clt_enum clt_type, U32 rec_idx);
static void srv_clog_sim_send_phb_write_sim_ln_req(
                mmi_sim_enum sim_id,
                srv_clog_clt_enum clt_type,
                const srv_clog_si_struct *si_log);
static void srv_clog_sim_send_phb_delete_sim_ln_req(mmi_sim_enum sim_id, srv_clog_clt_enum clt_type);

static S32 srv_clog_sim_shutdown_result_hdlr(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            void *req_data,
            void *cnf_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret);

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
static const srv_clog_sim_ef_map_struct g_srv_clog_sim_ef_map_tbl[] = 
{
    {MMI_FALSE, SRV_CLOG_CLT_DIALED, FILE_LND_IDX, SERVICE_LND}
};

static srv_clog_sim_mgr_struct *srv_clog_sim_mgr_p;
static srv_clog_sim_ef_info_struct srv_clog_ef_info[SRV_CLOG_SIM_IDX_MAX_ITEM]; /* Temp solution to improve power off performance */

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

#define SRV_CLOG_SIM_DUMP

#ifdef __SRV_CLOG_DUMP__


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_dump
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_sim_dump(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_sim_mgr_struct *sim_mgr = srv_clog_sim_get_mgr();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx || !sim_mgr || !SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_SIM_SYNC_DUMP))
        return;

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_DUMP, 0);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_DUMP,
                   "\n\n[CLogSrv]----- srv_clog_sim_dump(%d) ------------------\n"), 0));

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SIM_DUMP_CMN_VALUE,
        sim_mgr->sync_style,
        sim_mgr->cntx,
        sim_mgr->handle,
        srv_clog_sim_get_clt_sup(MMI_SIM1),
        SRV_CLOG_TRC_SIM_VAL(MMI_SIM2, srv_clog_sim_get_clt_sup(MMI_SIM2)));

    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_DUMP_CMN_VALUE,
                   "[CLogSrv]srv_clog_sim_dump(style=0x%x,cntx=0x%x,handle=0x%x,clt_sup=0x%x:0x%x)"),
                  sim_mgr->sync_style, sim_mgr->cntx, sim_mgr->handle,
                  srv_clog_sim_get_clt_sup(MMI_SIM1),
                  SRV_CLOG_TRC_SIM_VAL(MMI_SIM2, srv_clog_sim_get_clt_sup(MMI_SIM2))));

    srv_clog_sim_dump_req_data();
    srv_clog_sim_dump_sync_id();
    srv_clog_sim_dump_fsm();

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_DUMP, 1);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_DUMP,
                   "\n\n[CLogSrv]----- srv_clog_sim_dump(%d) ------------------\n"), 1));
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_dump_req_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_sim_dump_req_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_sim_mgr_struct *sim_mgr = srv_clog_sim_get_mgr();
    srv_clog_sim_sync_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx || !sim_mgr || !SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_SIM_SYNC_DUMP))
        return;
    req = &sim_mgr->req;

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SIM_DUMP_REQ_DATA,
        req->sync_type,
        req->sim_id,
        req->clt_type[0],
        req->clt_type[1],
        req->notify_proc,
        req->user_data,
        req->frm_proc_id.parent_id,
        req->frm_proc_id.this_id);

    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_DUMP_REQ_DATA,
                   "[CLogSrv]srv_clog_sim_dump_req_data(sync_type=%d,sim_id=0x%x,clt=[0x%x:0x%x],proc=0x%x,user_data=0x%x,frm_proc_id=%d:%d)"),
                  req->sync_type, req->sim_id, req->clt_type[0], req->clt_type[1], req->notify_proc, req->user_data,
                  req->frm_proc_id.parent_id, req->frm_proc_id.this_id));
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_dump_sync_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_sim_dump_sync_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_sim_mgr_struct *sim_mgr = srv_clog_sim_get_mgr();
    srv_clog_sim_sync_id_struct *sync_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx || !sim_mgr || !SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_SIM_SYNC_DUMP))
        return;

    sync_id = &sim_mgr->done;

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SIM_DUMP_SYNC_ID,
        1,
        sync_id->sim_id,
        sync_id->sim_idx,
        sync_id->clt_type[0],
        sync_id->clt_type[1],
        sync_id->clt_idx,
        sync_id->ret);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_DUMP_SYNC_ID,
                   "[CLogSrv]srv_clog_sim_dump_sync_id(is_cur=%d: sim_id=0x%x,sim_idx=%d,clt_type=0x%x:0x%x,clt_idx=%d,ret=%d)"),
                  1, sync_id->sim_id, sync_id->sim_idx, sync_id->clt_type[0], sync_id->clt_type[1], sync_id->clt_idx,
                  sync_id->ret));
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_dump_fsm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_sim_dump_fsm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_SIM_SYNC_DUMP))
        return;

    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {
        srv_clog_sim_dump_fsm_by_idx(i);
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_dump_fsm_by_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_sim_dump_fsm_by_idx(U32 sim_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 clt_type_sup;
    U32 cur_clt_type;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_sim_mgr_struct *sim_mgr = srv_clog_sim_get_mgr();
    srv_clog_sim_fsm_struct *fsm;
    srv_clog_sim_sync_id_struct *cur;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx || !sim_mgr || !SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_SIM_SYNC_DUMP))
        return;
    fsm = &sim_mgr->fsm_list[sim_idx];

    /* dump common value */
    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SIM_DUMP_FSM_BY_IDX_CMN_VALUE,
        sim_idx,
        fsm->flags,
        fsm->pid,
        fsm->state,
        fsm->total_to_write,
        fsm->cursor,
        fsm->sync_act_cursor,
        fsm->ret,
        fsm->idx_info_type);

    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_DUMP_FSM_BY_IDX_CMN_VALUE,
                   "[CLogSrv]srv_clog_sim_dump_fsm_by_idx(sim_idx=%d,flags=0x%x,pid=%d,state=%d,tt_wr=%d,cursor=%d,sact_cur=%d,ret=%d,idx_type=%d)"),
                  sim_idx, fsm->flags, fsm->pid, fsm->state, fsm->total_to_write, fsm->cursor, fsm->sync_act_cursor,
                  fsm->ret, fsm->idx_info_type));

    /* dump sim_sync_id info */
    cur = &fsm->cur;
    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SIM_DUMP_FSM_BY_IDX_SYNC_ID,
        cur->sim_id,
        cur->sim_idx,
        cur->clt_type[0],
        cur->clt_type[1],
        cur->clt_idx,
        cur->ret);

    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_DUMP_FSM_BY_IDX_SYNC_ID,
                   "[CLogSrv]srv_clog_sim_dump_fsm_by_idx(sim_id=%d,sim_idx=%d,clt_type=0x%x:0x%x,clt_idx=%d,ret=%d)"),
                  cur->sim_id, cur->sim_idx, cur->clt_type[0], cur->clt_type[1], cur->clt_idx, cur->ret));

    clt_type_sup = srv_clog_sim_get_clt_sup(cur->sim_id);
    for (i = 0; i < SRV_CLOG_CLT_IDX_MAX_ITEM; i++)
    {
        cur_clt_type = SRV_CLOG_IDX2BIT(i);
        if (!SRV_CLOG_CHECK_BIT(clt_type_sup, cur_clt_type))
            continue;

        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_SIM_DUMP_FSM_BY_IDX_EF_INFO,
            cur->sim_id,
            cur_clt_type,
            fsm->ef_info[i].used_rec,
            fsm->ef_info[i].total_rec);

        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_DUMP_FSM_BY_IDX_EF_INFO,
                       "[CLogSrv]srv_clog_sim_dump_fsm_by_idx(sim_id=%d,clt_type=%d:  ---- %d/%d ----)"), cur->sim_id,
                      cur_clt_type, fsm->ef_info[i].used_rec, fsm->ef_info[i].total_rec));
    }

}

#endif /* __SRV_CLOG_DUMP__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_handle_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_pw_read          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_clog_sim_handle_test(MMI_BOOL is_pw_read)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 style;
    srv_clog_job_struct *job;
    srv_clog_sim_sync_req_struct *req_data;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_stl_get_style(cntx->comp->style_mgr, SRV_CLOG_STYLE_TYPE_SIM_SYNC, &style, NULL);
    if (!SRV_CLOG_CHECK_BIT(style, SRV_CLOG_STYLE_SIM_SYNC_READ))
    {
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_SIM_SHUTDOWN_HDLR,
            is_pw_read,
            0,
            MMI_FRM_PROC_RESULT_COMPLETED,
            2,
            style);

        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_SHUTDOWN_HDLR,
                       "[CLogSrv]srv_clog_sim_shutdown_hdlr(id=[%d:%d]),ret=%d,reson=%d[1:ready,2:style,3:job,4:defer],style=0x%x"),
                      is_pw_read, 0, MMI_FRM_PROC_RESULT_COMPLETED, 2, style));

        return;
    }
    /* To do: check if any logs are modified, if not, no need to same to SIM card */

    /* if better to submit job to head ? */
    if (srv_clog_job_is_blocked(cntx->comp->job_mgr))
        job = srv_clog_job_submit_tail(cntx->comp->job_mgr, SRV_CLOG_JOB_TYPE_SIM_SYNC);
    else
        job = srv_clog_job_submit_head(cntx->comp->job_mgr, SRV_CLOG_JOB_TYPE_SIM_SYNC);
    if (!job)
    {
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_SIM_SHUTDOWN_HDLR,
            is_pw_read,
            0,
            MMI_FRM_PROC_RESULT_COMPLETED,
            3,
            style);

        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_SHUTDOWN_HDLR,
                       "[CLogSrv]srv_clog_sim_shutdown_hdlr(id=[%d:%d]),ret=%d,reson=%d[1:ready,2:style,3:job,4:defer],style=0x%x"),
                      is_pw_read, 0, MMI_FRM_PROC_RESULT_COMPLETED, 3, style));

        return;
    }
    job->pid = srv_clog_new_pid(cntx);
    job->req_data = srv_clog_job_new_para(job, sizeof(srv_clog_sim_sync_req_struct));
    //memset(job->req_data, 0x0, sizeof(srv_clog_sim_sync_req_struct));
    req_data = (srv_clog_sim_sync_req_struct*) job->req_data;
    if (is_pw_read)
    {
        req_data->sync_type = SRV_CLOG_SIM_SYNC_TYPE_PWON_READ;
    }
    else
        req_data->sync_type = SRV_CLOG_SIM_SYNC_TYPE_PWOF_WRITE;
    req_data->sim_id = SRV_CLOG_SIM_ID_ALL;
    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
        req_data->clt_type[i] = (srv_clog_clt_enum)srv_clog_sim_get_clt_sup((mmi_sim_enum)SRV_CLOG_IDX2BIT(i));

    req_data->notify_proc = srv_clog_sim_notify_proc_hdlr;
    req_data->user_data = job;
    
    srv_clog_process_new_job(cntx, cntx->comp->job_mgr, job);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SIM_SHUTDOWN_HDLR,
        is_pw_read,
        0,
        MMI_FRM_PROC_RESULT_COMPLETED,
        4,
        style);

    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_SHUTDOWN_HDLR,
                   "[CLogSrv]srv_clog_sim_shutdown_hdlr(id=[%d:%d]),ret=%d,reson=%d[1:ready,2:style,3:job,4:defer],style=0x%x"),
                  is_pw_read, 0, MMI_FRM_PROC_RESULT_COMPLETED, 4, style));
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_pwon_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_sim_pwon_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_sim_handle_test(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_pwoff_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_sim_pwoff_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_sim_handle_test(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_sat_refresh_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_sim_sat_refresh_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_sim_sat_refresh_hdlr(SRV_CLOG_SIM_ID_ALL, FILE_LND_IDX);
}

#define SRV_CLOG_SIM_IF


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_sat_refresh_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  ef_file_idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_sim_sat_refresh_hdlr(mmi_sim_enum sim_id, U16 ef_file_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 style;
    srv_clog_job_struct *job;
    srv_clog_clt_enum clt_type;
    srv_clog_sim_sync_req_struct *req_data;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SIM_SAT_REFRESH_HDLR_PARAM,
        sim_id,
        ef_file_idx,
        ef_file_idx == FILE_LND_IDX ? 1 : 0);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_SAT_REFRESH_HDLR_PARAM,
                   "[CLogSrv]srv_clog_sat_refresh_hdlr(sim_id=%d, ef_file_idx=%d, is_LND=%d)"), sim_id, ef_file_idx,
                  ef_file_idx == FILE_LND_IDX ? 1 : 0));

    if (!SRV_CLOG_CHECK_BIT(sim_id, SRV_CLOG_SIM_ID_ALL))
        return SRV_CLOG_RET_INVALID_PARAM;

    if (!srv_clog_sim_is_ef_support(sim_id, ef_file_idx, &clt_type))
        return SRV_CLOG_RET_NOT_SUPPORT;

    srv_clog_stl_get_style(cntx->comp->style_mgr, SRV_CLOG_STYLE_TYPE_SIM_SYNC, &style, NULL);
    if (!SRV_CLOG_CHECK_BIT_GRP(
            style,
            SRV_CLOG_STYLE_SIM_SYNC_SAT_REFRESH | SRV_CLOG_STYLE_SIM_SYNC_READ,
            SRV_CLOG_STYLE_SIM_SYNC_SAT_REFRESH | SRV_CLOG_STYLE_SIM_SYNC_READ))
    {
        return SRV_CLOG_RET_NOT_SUPPORT;
    }

    /* Temp solution: drop the next refresh indication, only can handle one at the same time. */
    if (srv_clog_job_is_blocked(cntx->comp->job_mgr) || 
        0 < srv_clog_job_get_type_num(cntx->comp->job_mgr, SRV_CLOG_JOB_TYPE_SIM_SYNC))
        return SRV_CLOG_RET_NOT_AVAILABLE;
    
    job = srv_clog_job_submit_tail(cntx->comp->job_mgr, SRV_CLOG_JOB_TYPE_SIM_SYNC);
    if (!job)
        return SRV_CLOG_RET_QUEUE_FULL;
    job->pid = srv_clog_new_pid(cntx);
    job->req_data = srv_clog_job_new_para(job, sizeof(srv_clog_sim_sync_req_struct));
    req_data = (srv_clog_sim_sync_req_struct*) job->req_data;
    
    req_data->sync_type = SRV_CLOG_SIM_SYNC_TYPE_SAT_REFRESH;
    req_data->sim_id = sim_id;
    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {
        if (SRV_CLOG_CHECK_BIT(sim_id, SRV_CLOG_IDX2BIT(i)))
            req_data->clt_type[i] = clt_type;
    }
    req_data->notify_proc = srv_clog_sim_notify_proc_hdlr;
    req_data->user_data = job;

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SIM_SAT_REFRESH_HDLR,
        req_data->sync_type,
        req_data->sim_id,
        req_data->clt_type[SRV_CLOG_SIM_IDX_SIM1],
        SRV_CLOG_TRC_SIM_VAL(MMI_SIM2, req_data->clt_type[SRV_CLOG_SIM_IDX_SIM2]),
        req_data->user_data);

    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_SAT_REFRESH_HDLR,
                   "[CLogSrv]srv_clog_sat_refresh_hdlr(sync_type=%d,sim_id=0x%x,clt=[0x%x:0x%x],user_data=0x%x)"),
                  req_data->sync_type, req_data->sim_id, 
                  req_data->clt_type[SRV_CLOG_SIM_IDX_SIM1],
                  SRV_CLOG_TRC_SIM_VAL(MMI_SIM2, req_data->clt_type[SRV_CLOG_SIM_IDX_SIM2]),
                  req_data->user_data));
    srv_clog_process_new_job(cntx, cntx->comp->job_mgr, job);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_shutdown_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_RET srv_clog_sim_shutdown_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SIM_SHUTDOWN_EVT_HDLR,
        evt->evt_id,
        (evt->evt_id == EVT_ID_SRV_SHUTDOWN_HANDLER_RESET));
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_SHUTDOWN_EVT_HDLR,
                   "[CLogSrv]srv_clog_sim_shutdown_evt_hdlr(evt_id=%d,reset_pevt=%d)"), evt->evt_id,
                  (evt->evt_id == EVT_ID_SRV_SHUTDOWN_HANDLER_RESET)));

    if (evt->evt_id == EVT_ID_SRV_SHUTDOWN_HANDLER_RESET)
    {
        srv_clog_evt_init();
        srv_clog_sim_pevt_init();
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_shutdown_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg         [IN]        
 *  id_info     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_frm_proc_result_enum srv_clog_sim_shutdown_hdlr(void *arg, const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 style;
    srv_clog_job_struct *job;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Should try our best to decrease the shutdown time here */
    if (!srv_clog_is_ready())
    {
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_SIM_SHUTDOWN_HDLR,
            id_info.parent_id,
            id_info.this_id,
            MMI_FRM_PROC_RESULT_COMPLETED,
            1,
            0);

        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_SHUTDOWN_HDLR,
                       "[CLogSrv]srv_clog_sim_shutdown_hdlr(id=[%d:%d]),ret=%d,reson=%d[1:ready,2:style,3:job,4:defer],style=0x%x"),
                      id_info.parent_id, id_info.this_id, MMI_FRM_PROC_RESULT_COMPLETED, 1, 0));

        return MMI_FRM_PROC_RESULT_COMPLETED;
    }
    srv_clog_stl_get_style(cntx->comp->style_mgr, SRV_CLOG_STYLE_TYPE_SIM_SYNC, &style, NULL);
    if (!SRV_CLOG_CHECK_BIT(style, SRV_CLOG_STYLE_SIM_SYNC_WRITE))
    {
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_SIM_SHUTDOWN_HDLR,
            id_info.parent_id,
            id_info.this_id,
            MMI_FRM_PROC_RESULT_COMPLETED,
            2,
            style);
        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_SHUTDOWN_HDLR,
                       "[CLogSrv]srv_clog_sim_shutdown_hdlr(id=[%d:%d]),ret=%d,reson=%d[1:ready,2:style,3:job,4:defer],style=0x%x"),
                      id_info.parent_id, id_info.this_id, MMI_FRM_PROC_RESULT_COMPLETED, 2, style));

        return MMI_FRM_PROC_RESULT_COMPLETED;
    }
    
    /* if not receive PHB_LN_READY in bootup, so don't need sync to SIM when shutdown*/
    if (!SRV_CLOG_CHECK_BIT_GRP(cntx->flags, SRV_CLOG_CNTX_FLAG_PHB_READY_TOTAL, SRV_CLOG_CNTX_FLAG_PHB_READY_TOTAL))
    {
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_SIM_SHUTDOWN_HDLR,
            id_info.parent_id,
            id_info.this_id,
            MMI_FRM_PROC_RESULT_COMPLETED,
            11, /* 11 means Not ready */
            style);
        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_SHUTDOWN_HDLR,
                       "[CLogSrv]srv_clog_sim_shutdown_hdlr(id=[%d:%d]),ret=%d,reson=%d[1:ready,2:style,3:job,4:defer],style=0x%x"),
                      id_info.parent_id, id_info.this_id, MMI_FRM_PROC_RESULT_COMPLETED, 11, style));
        
        return MMI_FRM_PROC_RESULT_COMPLETED;
    }
    /* To do: check if any logs are modified, if not, no need to same to SIM card */

    /* if better to submit job to head ? */
    job = srv_clog_job_submit_head(cntx->comp->job_mgr, SRV_CLOG_JOB_TYPE_SIM_SYNC);
    if (!job)
    {
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_SIM_SHUTDOWN_HDLR,
            id_info.parent_id,
            id_info.this_id,
            MMI_FRM_PROC_RESULT_COMPLETED,
            3,
            style);
        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_SHUTDOWN_HDLR,
                       "[CLogSrv]srv_clog_sim_shutdown_hdlr(id=[%d:%d]),ret=%d,reson=%d[1:ready,2:style,3:job,4:defer],style=0x%x"),
                      id_info.parent_id, id_info.this_id, MMI_FRM_PROC_RESULT_COMPLETED, 3, style));

        return MMI_FRM_PROC_RESULT_COMPLETED;
    }
    job->pid = srv_clog_new_pid(cntx);
    job->req_data = srv_clog_job_new_para(job, sizeof(srv_clog_sim_sync_req_struct));

    srv_clog_sim_set_req_data(job->req_data, 
            SRV_CLOG_SIM_SYNC_TYPE_PWOF_WRITE, job, (mmi_frm_proc_id_info_struct*)&id_info);

    job->func_cb = srv_clog_sim_shutdown_result_hdlr;
    srv_clog_process_new_job(cntx, cntx->comp->job_mgr, job);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SIM_SHUTDOWN_HDLR,
        id_info.parent_id,
        id_info.this_id,
        MMI_FRM_PROC_RESULT_NOTIFY_LATER,
        4,
        style);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_SHUTDOWN_HDLR,
                   "[CLogSrv]srv_clog_sim_shutdown_hdlr(id=[%d:%d]),ret=%d,reson=%d[1:ready,2:style,3:job,4:defer],style=0x%x"),
                  id_info.parent_id, id_info.this_id, MMI_FRM_PROC_RESULT_NOTIFY_LATER, 4, style));

    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_shutdown_result_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  req_data        [?]         
 *  cnf_data        [?]         
 *  more            [IN]        
 *  ret             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 srv_clog_sim_shutdown_result_hdlr(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            void *req_data,
            void *cnf_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_sim_sync_req_struct *req = (srv_clog_sim_sync_req_struct*) req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Please note, srv_clog_sim_mgr_p is already destroyed now */
    SRV_CLOG_ASSERT(req_data);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SIM_SHUTDOWN_RESULT_HDLR,
        handle,
        pid,
        req->sync_type,
        ret,
        req->frm_proc_id.parent_id,
        req->frm_proc_id.this_id);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_SHUTDOWN_RESULT_HDLR,
                   "[CLogSrv]srv_clog_sim_shutdown_result_hdlr(handle=0x%x,pid=%d,sync_type=%d,ret=%d,proc_id=%d:%d)"),
                  handle, pid, req->sync_type, ret, req->frm_proc_id.parent_id, req->frm_proc_id.this_id));

    if (req->sync_type == SRV_CLOG_SIM_SYNC_TYPE_PWOF_WRITE)
    {
        mmi_frm_proc_notify_completed(req->frm_proc_id);
    }

    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_notify_proc_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_data        [?]         
 *  sim_id          [IN]        
 *  clt_type        [IN]        
 *  ret             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_sim_notify_proc_hdlr(
            srv_clog_sim_sync_req_struct *req_data,
            mmi_sim_enum sim_id,
            srv_clog_clt_enum clt_type,
            srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_job_struct *job;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_clog_job_struct*) req_data->user_data;

    SRV_CLOG_ASSERT(job);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SIM_NOTIFY_PROC_HDLR,
        (!sim_id && !clt_type),
        req_data->sync_type,
        sim_id,
        clt_type,
        ret,
        job->job_state,
        job->proc_state);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_NOTIFY_PROC_HDLR,
                   "[CLogSrv]srv_clog_sim_notify_proc_hdlr(done:%d -- sync_type=%d,sim_id=%d,clt_type=%d,ret=%d,job_state=%d,proc_state=%d)"),
                  (!sim_id && !clt_type), req_data->sync_type, sim_id, clt_type, ret, job->job_state, job->proc_state));

    /* All works are done */
    if (sim_id == 0 && clt_type == 0)
    {
        job->proc_state = SRV_CLOG_JOB_SIM_SYNC_STATE_DONE;
        job->ret = SRV_CLOG_RET_OK;
        srv_clog_async_process(cntx, job);
    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_sync_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job         [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_sim_sync_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job->proc_state == SRV_CLOG_JOB_SIM_SYNC_STATE_INIT)
    {
        if (!SRV_CLOG_CHECK_BIT_GRP(cntx->flags, SRV_CLOG_CNTX_FLAG_PHB_READY_TOTAL, SRV_CLOG_CNTX_FLAG_PHB_READY_TOTAL))
        {
            /* My be the SIM card is locked when initializing, but user can make SOS call at that time */
            job->job_state = SRV_CLOG_JOB_STATE_PENDING;
            
            return SRV_CLOG_RET_CONTINUE;
        }
        srv_clog_sim_revise_job_req_data(cntx, job);
        job->ret = (srv_clog_ret_enum)srv_clog_sim_process_sync(cntx, (srv_clog_sim_sync_req_struct*) job->req_data);
        if (job->ret != SRV_CLOG_RET_OK)
            job->proc_state = SRV_CLOG_JOB_SIM_SYNC_STATE_DONE;
        else
        {
            SRV_CLOG_DUMP(SRV_CLOG_DUMP_TYPE_ALL);

            job->proc_state = SRV_CLOG_JOB_SIM_SYNC_STATE_START;
        }
    }
    if (job->proc_state == SRV_CLOG_JOB_SIM_SYNC_STATE_START)
    {
        job->job_state = SRV_CLOG_JOB_STATE_WAITING;
    }
    if (job->proc_state == SRV_CLOG_JOB_SIM_SYNC_STATE_DONE)
    {
        /* delay destroy it here because may be some job related with this handle is just be done till now */
        srv_clog_sim_destroy(srv_clog_sim_get_mgr());
        if (job->func_cb)
            (job->func_cb) (job->handle, job->pid, job->req_data, job->cnf_data, MMI_FALSE, job->ret);
        if (job->req_data &&
            ((srv_clog_sim_sync_req_struct*) job->req_data)->sync_type == SRV_CLOG_SIM_SYNC_TYPE_PWON_READ)
        {
            SRV_CLOG_DUMP(SRV_CLOG_DUMP_TYPE_ALL);
        }
        job->job_state = SRV_CLOG_JOB_STATE_FINISHED;
    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_revise_job_req_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  job         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_sim_revise_job_req_data(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_sim_sync_req_struct *req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job->req_data)
        return;

	/* If req_data is NULL, treat it as SRV_CLOG_SIM_SYNC_TYPE_PWON_READ type */
    job->req_data = srv_clog_job_new_para(job, sizeof(srv_clog_sim_sync_req_struct));
    //memset(job->req_data, 0x0, sizeof(srv_clog_sim_sync_req_struct));
    req_data = (srv_clog_sim_sync_req_struct*) job->req_data;

    srv_clog_sim_set_req_data(job->req_data, SRV_CLOG_SIM_SYNC_TYPE_PWON_READ, job, NULL);

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SIM_REVISE_JOB_REQ_DATA,
        req_data->sim_id,
        req_data->clt_type[0],
        req_data->clt_type[1],
        req_data->user_data);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_REVISE_JOB_REQ_DATA,
                   "[CLogSrv]srv_clog_sim_revise_job_req_data(PowerOn:sim_id=0x%x,clt_type=%d:%d,user_data=0x%x)"),
                  req_data->sim_id, req_data->clt_type[0], req_data->clt_type[1], req_data->user_data));
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_set_req_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
static void srv_clog_sim_set_req_data(srv_clog_sim_sync_req_struct * req_data, 
    srv_clog_sim_sync_type_enum sync_type, void *user_data, mmi_frm_proc_id_info_struct *proc_id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    req_data->sync_type = sync_type;
    req_data->sim_id = SRV_CLOG_SIM_ID_ALL;
    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
        req_data->clt_type[i] = (srv_clog_clt_enum)srv_clog_sim_get_clt_sup((mmi_sim_enum)SRV_CLOG_IDX2BIT(i));
    req_data->notify_proc = srv_clog_sim_notify_proc_hdlr;
    req_data->user_data = user_data;
    if (proc_id_info) /* req_data is memset once allocated */
        req_data->frm_proc_id = *proc_id_info;
}





#define SRV_CLOG_SIM_PROCESS


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_process_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  req         [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_sim_process_sync(srv_clog_cntx_struct *cntx, srv_clog_sim_sync_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 ret;
    U32 count;
    mmi_sim_enum sim_id;
    srv_clog_sim_fsm_struct *fsm;
    srv_clog_create_struct create;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx || !req)
        return SRV_CLOG_RET_INVALID_PARAM;

    if (req->sync_type >= SRV_CLOG_SIM_SYNC_TYPE_MAX_ITEM ||
        !SRV_CLOG_CHECK_BIT(req->sim_id, SRV_CLOG_SIM_ID_ALL) ||
        !req->notify_proc)
    {
        return SRV_CLOG_RET_INVALID_PARAM;
    }
        
    for (i = 0, count = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {
        if (SRV_CLOG_CHECK_BIT(req->clt_type[i], SRV_CLOG_CLT_ALL))
            count++;
    }
    if (count == 0)
        return SRV_CLOG_RET_INVALID_PARAM;

    if (srv_clog_sim_mgr_p)
        return SRV_CLOG_RET_BUSY;

    srv_clog_sim_mgr_p = srv_clog_sim_create();
    srv_clog_sim_cp_req(&srv_clog_sim_mgr_p->req, req);
    srv_clog_sim_mgr_p->cntx = cntx;

    /* Check if can sync now */
    ret = srv_clog_sim_can_sync(srv_clog_sim_mgr_p);
    if (ret != SRV_CLOG_RET_OK)
    {
        /* Dump srv_clog_sim_mgr_p->req to see if any SIM/CLT should be sync as it may revised in srv_clog_sim_can_sync() */
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_SIM_PROCESS_SYNC,
            srv_clog_sim_mgr_p->req.sync_type,
            srv_clog_sim_mgr_p->req.sim_id,
            srv_clog_sim_mgr_p->req.clt_type[0],
            srv_clog_sim_mgr_p->req.clt_type[1],
            ret,
            srv_clog_sim_mgr_p->sync_style);

        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_PROCESS_SYNC,
                       "[CLogSrv]srv_clog_sim_process_sync(not sync: sync_type=%d,sim_id=%d,clt_type=%d:%d,ret=%d,style=0x0x)"),
                      srv_clog_sim_mgr_p->req.sync_type, srv_clog_sim_mgr_p->req.sim_id,
                      srv_clog_sim_mgr_p->req.clt_type[0], srv_clog_sim_mgr_p->req.clt_type[1], ret,
                      srv_clog_sim_mgr_p->sync_style));

        srv_clog_sim_destroy(srv_clog_sim_mgr_p);
        return ret;
    }

    /* Create special handle */
    SRV_CLOG_INIT_IDT(
        &create.identity,
        SRV_CLOG_CATE_CALL,
        SRV_CLOG_SIM_ID_ALL,
        SRV_CLOG_CLT_ALL,
        SRV_CLOG_CALL_TYPE_ALL);
    create.user_data = srv_clog_sim_mgr_p;
    srv_clog_sim_mgr_p->handle = srv_clog_create_int(&create, SRV_CLOG_INST_FLAG_HIGH_PRIORITY | SRV_CLOG_INST_FLAG_HAS_LOG_ID);
    if (SRV_CLOG_IS_ELM_INVALID(srv_clog_sim_mgr_p->handle))
    {
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_SIM_PROCESS_SYNC,
            srv_clog_sim_mgr_p->req.sync_type,
            srv_clog_sim_mgr_p->req.sim_id,
            srv_clog_sim_mgr_p->req.clt_type[0],
            srv_clog_sim_mgr_p->req.clt_type[1],
            SRV_CLOG_RET_MEM_FULL,
            srv_clog_sim_mgr_p->sync_style);
        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_PROCESS_SYNC,
                       "[CLogSrv]srv_clog_sim_process_sync(not sync: sync_type=%d,sim_id=%d,clt_type=%d:%d,ret=%d,style=0x0x)"),
                      srv_clog_sim_mgr_p->req.sync_type, srv_clog_sim_mgr_p->req.sim_id,
                      srv_clog_sim_mgr_p->req.clt_type[0], srv_clog_sim_mgr_p->req.clt_type[1], SRV_CLOG_RET_MEM_FULL,
                      srv_clog_sim_mgr_p->sync_style));

        srv_clog_sim_destroy(srv_clog_sim_mgr_p);
        return SRV_CLOG_RET_MEM_FULL;
    }

    /* Only reserve log_id for read action as it's used only for read action */
    if (srv_clog_sim_is_read_action(srv_clog_sim_mgr_p))
    {
        srv_clog_sim_mgr_p->start_log_id = srv_clog_reserve_log_ids(
                                            srv_clog_sim_mgr_p->cntx,
                                            SRV_CLOG_SIM_EF_RECORD_MAX_SUP_NUM * SRV_CLOG_SIM_IDX_MAX_ITEM);
    }
    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {
        sim_id = (mmi_sim_enum)SRV_CLOG_IDX2BIT(i);
        if (SRV_CLOG_CHECK_BIT(srv_clog_sim_mgr_p->req.sim_id, sim_id))
        {
            fsm = &srv_clog_sim_mgr_p->fsm_list[i];
            fsm->state = SRV_CLOG_SIM_STATE_PROCESS_FIRST_EF;
            fsm->cur.sim_id = sim_id;
            fsm->cur.sim_idx = (srv_clog_sim_idx_enum)i;
            if (srv_clog_sim_is_read_action(srv_clog_sim_mgr_p))
                fsm->start_log_id = srv_clog_sim_mgr_p->start_log_id + SRV_CLOG_SIM_EF_RECORD_MAX_SUP_NUM * i;
            srv_clog_sim_start_next_sync(srv_clog_sim_mgr_p, fsm);
        }
    }
    return SRV_CLOG_RET_OK;
}

#define SRV_CLOG_SIM_UTILS


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static srv_clog_sim_mgr_struct *srv_clog_sim_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_sim_mgr_struct *sim_mgr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_mgr = SRV_CLOG_TALLOC(SRV_CLOG_MEM_TYPE_TEMP, srv_clog_sim_mgr_struct);
    memset(sim_mgr, 0x0, sizeof(srv_clog_sim_mgr_struct));
    return sim_mgr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_destroy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_mgr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_sim_destroy(srv_clog_sim_mgr_struct *sim_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_DESTROY);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_DESTROY, "[CLogSrv]srv_clog_sim_destroy(Sim sync done)")));

    if (!srv_clog_sim_mgr_p)
        return;

    if (!SRV_CLOG_IS_ELM_INVALID(sim_mgr->handle))
        srv_clog_destroy(sim_mgr->handle);

    SRV_CLOG_ZFREE(SRV_CLOG_MEM_TYPE_TEMP, sim_mgr);
    srv_clog_sim_mgr_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_get_mgr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static srv_clog_sim_mgr_struct *srv_clog_sim_get_mgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_clog_sim_mgr_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_get_fsm_by_pid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_mgr     [?]         
 *  pid         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_clog_sim_fsm_struct *srv_clog_sim_get_fsm_by_pid(srv_clog_sim_mgr_struct *sim_mgr, S32 pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {
        if (sim_mgr->fsm_list[i].pid == pid)
            return &sim_mgr->fsm_list[i];
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_get_fsm_by_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_mgr     [?]         
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_clog_sim_fsm_struct *srv_clog_sim_get_fsm_by_sim_id(srv_clog_sim_mgr_struct *sim_mgr, mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {
        if (sim_mgr->fsm_list[i].cur.sim_id == sim_id)
            return &sim_mgr->fsm_list[i];
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_cp_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [?]     
 *  src     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_sim_cp_req(srv_clog_sim_sync_req_struct *dst, srv_clog_sim_sync_req_struct *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dst->sync_type = src->sync_type;
    dst->sim_id = src->sim_id;
    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
        dst->clt_type[i] = src->clt_type[i];
    dst->notify_proc = src->notify_proc;
    dst->user_data = src->user_data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_can_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_mgr     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_sim_can_sync(srv_clog_sim_mgr_struct *sim_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_sim_check_sync_style(sim_mgr);
    if (ret != SRV_CLOG_RET_OK)
        return ret;

    ret = srv_clog_sim_any_sync(sim_mgr);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_check_sync_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_mgr     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_sim_check_sync_style(srv_clog_sim_mgr_struct *sim_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 bit_grp;
    U32 sync_style;
    U32 sim_id;
    srv_clog_sim_sync_req_struct *req = &sim_mgr->req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_stl_get_style(sim_mgr->cntx->comp->style_mgr, SRV_CLOG_STYLE_TYPE_SIM_SYNC, &sync_style, NULL);
    sim_mgr->sync_style = sync_style;

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SIM_CHECK_SYNC_STYLE,
        sync_style,
        sim_mgr->req.sync_type,
        req->sim_id,
        srv_clog_sim_is_sim_replaced(SRV_CLOG_SIM_ID_ALL));

    if (!sync_style)
        return SRV_CLOG_RET_NOT_SUPPORT;

    if (req->sync_type == SRV_CLOG_SIM_SYNC_TYPE_PWON_READ || req->sync_type == SRV_CLOG_SIM_SYNC_TYPE_CMN_READ)
    {
        if (!SRV_CLOG_CHECK_BIT(sync_style, SRV_CLOG_STYLE_SIM_SYNC_READ))
            return SRV_CLOG_RET_NOT_SUPPORT;
    }

    if (req->sync_type == SRV_CLOG_SIM_SYNC_TYPE_PWOF_WRITE || req->sync_type == SRV_CLOG_SIM_SYNC_TYPE_CMN_WRITE)
    {
        if (!SRV_CLOG_CHECK_BIT(sync_style, SRV_CLOG_STYLE_SIM_SYNC_WRITE))
            return SRV_CLOG_RET_NOT_SUPPORT;
    }
    if (req->sync_type == SRV_CLOG_SIM_SYNC_TYPE_SIM_REFRESH)
    {
        bit_grp = SRV_CLOG_STYLE_SIM_SYNC_READ | SRV_CLOG_STYLE_SIM_SYNC_CMN_REFRESH;
        if (!SRV_CLOG_CHECK_BIT_GRP(sync_style, bit_grp, bit_grp))
            return SRV_CLOG_RET_NOT_SUPPORT;
    }

    if (req->sync_type == SRV_CLOG_SIM_SYNC_TYPE_SAT_REFRESH)
    {
        bit_grp = SRV_CLOG_STYLE_SIM_SYNC_READ | SRV_CLOG_STYLE_SIM_SYNC_SAT_REFRESH;
        if (!SRV_CLOG_CHECK_BIT_GRP(sync_style, bit_grp, bit_grp))
            return SRV_CLOG_RET_NOT_SUPPORT;
    }

    if (req->sync_type == SRV_CLOG_SIM_SYNC_TYPE_PWON_READ &&
        !SRV_CLOG_CHECK_BIT(sync_style, SRV_CLOG_STYLE_SIM_SYNC_FORCE_SYNC))
    {
        sim_id = srv_clog_sim_is_sim_replaced(req->sim_id);
        if (sim_id == 0)
            return SRV_CLOG_RET_NOT_SUPPORT;
        req->sim_id = (mmi_sim_enum)sim_id;
    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_is_sim_replaced
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U32 srv_clog_sim_is_sim_replaced(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 sim_id_sup = 0;
    U32 cur_sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {
        cur_sim_id = SRV_CLOG_IDX2BIT(i);
        if (SRV_CLOG_CHECK_BIT(sim_id, cur_sim_id))
        {
            if (srv_clog_is_single_sim_replaced((mmi_sim_enum)cur_sim_id))
                SRV_CLOG_SET_BIT(sim_id_sup, cur_sim_id);
        }
    }

    return sim_id_sup;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_any_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_mgr     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_sim_any_sync(srv_clog_sim_mgr_struct *sim_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 find = MMI_FALSE;
    mmi_sim_enum sim_id;
    srv_clog_sim_sync_req_struct *req = &sim_mgr->req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SIM_ANY_SYNC,
        srv_clog_sim_is_sim_available(MMI_SIM1),
        srv_clog_sim_is_sim_available(MMI_SIM2));

    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {
        sim_id = (mmi_sim_enum)SRV_CLOG_IDX2BIT(i);
        if (!SRV_CLOG_CHECK_BIT(req->sim_id, sim_id))
            continue;

        if (srv_clog_sim_is_sim_available(sim_id) && 
            SRV_CLOG_RET_OK == srv_clog_sim_any_sync_clt(sim_id, req))
        {
            find = MMI_TRUE;
            continue;
        }
        SRV_CLOG_CLEAR_BIT(req->sim_id, sim_id);
    }
    if (find)
        return SRV_CLOG_RET_OK;
    else
        return SRV_CLOG_RET_NOT_AVAILABLE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_is_sim_available
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_sim_is_sim_available(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* as srv_sim_ctrl_is_available() need to wrap SIM compile option, to remove the option and make code beautiful,
       here use this this bit check to remove those improper sim_id by utilizing MMI_SIM_ALL with compile option internally */

    if (!SRV_CLOG_CHECK_BIT(MMI_SIM_ALL, sim_id))
        return MMI_FALSE;
    
    return srv_sim_ctrl_is_available(sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_any_sync_clt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  req             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_sim_any_sync_clt(mmi_sim_enum sim_id, srv_clog_sim_sync_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 find = MMI_FALSE;
    U32 sim_idx;
    srv_clog_clt_enum cur_clt_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_BIT2IDX(sim_id, sim_idx);

    for (i = 0; i < SRV_CLOG_CLT_IDX_MAX_ITEM; i++)
    {
        cur_clt_type = (srv_clog_clt_enum)SRV_CLOG_IDX2BIT(i);
        if (!SRV_CLOG_CHECK_BIT(req->clt_type[sim_idx], cur_clt_type))
            continue;

        if (srv_clog_sim_is_ef_srv_sup(sim_id, cur_clt_type))
        {
            find = MMI_TRUE;
            continue;
        }
        SRV_CLOG_CLEAR_BIT(req->clt_type[sim_idx], cur_clt_type);
    }
    if (find)
        return SRV_CLOG_RET_OK;
    else
        return SRV_CLOG_RET_NOT_SUPPORT;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_is_ef_srv_sup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  clt_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_clog_sim_is_ef_srv_sup(mmi_sim_enum sim_id, srv_clog_clt_enum clt_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __GEMINI__ /* Should use global option as it's used by L4 interface */
    kal_uint8 simInterface;
	sim_interface_enum realSimId;
#endif

    sim_service_state_enum state;
    const srv_clog_sim_ef_map_struct *ef_map;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ef_map = srv_clog_sim_search_map(sim_id, clt_type);
    if (!ef_map)
        return MMI_FALSE;

#ifdef __GEMINI__
    simInterface = srv_clog_sim_id_clog2ps(sim_id);
	realSimId = l4c_gemini_get_switched_sim_id((sim_interface_enum)simInterface);
    state = sim_service_table_query(ef_map->srv_id, (kal_uint8)realSimId);
#else 
    state = sim_service_table_query(ef_map->srv_id);
#endif 

    if (state == SERVICE_SUPPORT)
        return MMI_TRUE;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_is_ef_support
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  ef_file_idx     [IN]        
 *  clt_type        [?]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_sim_is_ef_support(mmi_sim_enum sim_id, U16 ef_file_idx, srv_clog_clt_enum *clt_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clt_type)
        *clt_type = SRV_CLOG_CLT_DEFAULT;
    for (i = 0; i < sizeof(g_srv_clog_sim_ef_map_tbl) / sizeof(srv_clog_sim_ef_map_struct); i++)
    {
        if (g_srv_clog_sim_ef_map_tbl[i].file_id == ef_file_idx)
        {
            if (clt_type)
                *clt_type = g_srv_clog_sim_ef_map_tbl[i].clt_type;
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_search_map
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  clt_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static const srv_clog_sim_ef_map_struct *srv_clog_sim_search_map(mmi_sim_enum sim_id, srv_clog_clt_enum clt_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(g_srv_clog_sim_ef_map_tbl) / sizeof(srv_clog_sim_ef_map_struct); i++)
    {
        if (g_srv_clog_sim_ef_map_tbl[i].clt_type == clt_type)  /* also check sim type */
            return &g_srv_clog_sim_ef_map_tbl[i];
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_get_clt_sup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U32 srv_clog_sim_get_clt_sup(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 clt_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(g_srv_clog_sim_ef_map_tbl) / sizeof(srv_clog_sim_ef_map_struct); i++)
    {
        SRV_CLOG_SET_BIT(clt_type, g_srv_clog_sim_ef_map_tbl[i].clt_type);
    }
    return clt_type;
}



#define SRV_CLOG_SIM_ACT


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_start_next_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_mgr     [?]     
 *  fsm         [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_sim_start_next_sync(srv_clog_sim_mgr_struct *sim_mgr, srv_clog_sim_fsm_struct *fsm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_del_all_logs_req_struct req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fsm->state == SRV_CLOG_SIM_STATE_PROCESS_FIRST_EF || fsm->state == SRV_CLOG_SIM_STATE_PROCESS_NEXT_EF)
    {
        ret = srv_clog_sim_get_next_ef(sim_mgr, fsm);

        SRV_CLOG_DUMP(SRV_CLOG_DUMP_TYPE_SIM_SYNC);

        if (ret != SRV_CLOG_RET_OK)
        {
            /* Check if all SIM cards are handled, if not, just return */
            if (!SRV_CLOG_CHECK_BIT_GRP(sim_mgr->req.sim_id, sim_mgr->done.sim_id, sim_mgr->req.sim_id))
                return SRV_CLOG_RET_OK;

            /* all EF files are handled */
            MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_START_NEXT_SYNC_DONE, ret);
            SRV_CLOG_TRC((SRV_CLOG_TS
                          (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_START_NEXT_SYNC_DONE,
                           "[CLogSrv]srv_clog_sim_start_next_sync(done:ret=%d)"), ret));

            fsm->state = SRV_CLOG_SIM_STATE_FINISHED;
            (sim_mgr->req.notify_proc) (&sim_mgr->req, MMI_SIM_NONE, SRV_CLOG_CLT_DEFAULT, SRV_CLOG_RET_OK);

            /* srv_clog_sim_destroy(sim_mgr); */
            return ret;
        }
        /* Start to process next EF files */
        if (srv_clog_sim_is_read_action(sim_mgr))
        {
            if (SRV_CLOG_CHECK_BIT(sim_mgr->sync_style, SRV_CLOG_STYLE_SIM_SYNC_CLEAR_OLD) &&
                !SRV_CLOG_CHECK_BIT(fsm->flags, SRV_CLOG_SIM_FSM_FLAG_CLEAR_ALL_DONE))
            {
                fsm->state = SRV_CLOG_SIM_STATE_DEL_OLD_LOGS;
                SRV_CLOG_SET_BIT(fsm->flags, SRV_CLOG_SIM_FSM_FLAG_CLEAR_ALL_DONE);
            }
            else if (SRV_CLOG_CHECK_BIT(sim_mgr->sync_style, SRV_CLOG_STYLE_SIM_SYNC_CLEAR_OLD_BY_TYPE))
            {
                fsm->state = SRV_CLOG_SIM_STATE_DEL_OLD_LOGS;
            }
            else
            {
                fsm->state = SRV_CLOG_SIM_STATE_GET_EF_INFO;
            }
        }
        else
        {
            fsm->state = SRV_CLOG_SIM_STATE_GET_EF_INFO;
        }
    }

    if (fsm->state == SRV_CLOG_SIM_STATE_DEL_OLD_LOGS)
    {
        req_data.cate = SRV_CLOG_CATE_CALL;
        req_data.sim_id = fsm->cur.sim_id;
        if (SRV_CLOG_CHECK_BIT(sim_mgr->sync_style, SRV_CLOG_STYLE_SIM_SYNC_CLEAR_OLD_BY_TYPE))
            req_data.log_type = fsm->cur.clt_type[fsm->cur.sim_idx];
        else
            req_data.log_type = SRV_CLOG_CLT_ALL;

        req_data.sub_type = SRV_CLOG_CALL_TYPE_ALL;

        fsm->pid = srv_clog_delete_all_logs(
                    sim_mgr->handle,
                    0,
                    (const srv_clog_del_all_logs_req_struct*)&req_data,
                    srv_clog_sim_delete_result_hdlr);
        if (fsm->pid <= SRV_CLOG_RET_OK)
        {
            srv_clog_sim_sync_cmn_result_hdlr(sim_mgr, fsm, SRV_CLOG_RET_FAIL);
            return SRV_CLOG_RET_OK;
        }
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_SIM_START_NEXT_SYNC_CLEAR_OLD,
            req_data.sim_id,
            req_data.log_type,
            SRV_CLOG_RET_OK);
        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_START_NEXT_SYNC_CLEAR_OLD,
                       "[CLogSrv]srv_clog_sim_start_next_sync(clear: sim_id=0x%x,clt_type=0x%x,ret=%d)"),
                      req_data.sim_id, req_data.log_type, SRV_CLOG_RET_OK));
    }

    if (fsm->state == SRV_CLOG_SIM_STATE_GET_EF_INFO)
    {
        /* Temp solution to improve the power off performance */
        srv_clog_sim_ef_info_struct *cur_ef_info = &fsm->ef_info[fsm->cur.clt_idx];
        srv_clog_sim_ef_info_struct *backup_ef_info = &srv_clog_ef_info[fsm->cur.sim_idx];      /* Base on the condition support LND now */

        if (fsm->cur.clt_type[fsm->cur.sim_idx] == SRV_CLOG_CLT_DIALED &&
            backup_ef_info->total_rec != SRV_CLOG_SIM_EF_INVALID_NUM &&
            backup_ef_info->used_rec != SRV_CLOG_SIM_EF_INVALID_NUM)
        {
            cur_ef_info->total_rec = backup_ef_info->total_rec;
            cur_ef_info->used_rec = backup_ef_info->used_rec;

            if (srv_clog_sim_is_read_action(sim_mgr))
                srv_clog_sim_start_read(sim_mgr, fsm);
            else
                srv_clog_sim_start_write(sim_mgr, fsm);
        }
        else
        {
            (sim_mgr->req.notify_proc) (&sim_mgr->req, fsm->cur.sim_id, fsm->cur.clt_type[fsm->cur.sim_idx], fsm->ret);

            srv_clog_sim_send_phb_get_ln_type_info_req(fsm->cur.sim_id, fsm->cur.clt_type[fsm->cur.sim_idx]);
        }
    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_get_next_ef
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_mgr     [?]     
 *  fsm         [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_sim_get_next_ef(srv_clog_sim_mgr_struct *sim_mgr, srv_clog_sim_fsm_struct *fsm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_clog_clt_enum clt_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(sim_mgr->req.sim_id, fsm->cur.sim_id))
        return SRV_CLOG_RET_NOT_FOUND;

    for (i = 0; i < SRV_CLOG_CLT_IDX_MAX_ITEM; i++)
    {
        clt_type = (srv_clog_clt_enum)SRV_CLOG_IDX2BIT(i);
        /* check if request to sync */
        if (!SRV_CLOG_CHECK_BIT(sim_mgr->req.clt_type[fsm->cur.sim_idx], clt_type))
        {
            continue;
        }
        /* check if already sync done */
        if (SRV_CLOG_CHECK_BIT(sim_mgr->done.clt_type[fsm->cur.sim_idx], clt_type))
        {
            continue;
        }

        fsm->cur.clt_type[fsm->cur.sim_idx] = clt_type;
        fsm->cur.clt_idx = (srv_clog_clt_idx_enum)srv_clog_ib_bit2idx(clt_type);

        MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_GET_NEXT_EF_FIND, 1, fsm->cur.sim_id, clt_type);
        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_GET_NEXT_EF_FIND,
                       "[CLogSrv]srv_clog_sim_get_next_ef(find=%d:sim_id=0x%x,clt=0x%x)"), 1, fsm->cur.sim_id,
                      clt_type));
        break;
    }
    if (i == SRV_CLOG_CLT_IDX_MAX_ITEM)
    {
        return SRV_CLOG_RET_NOT_FOUND;
    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_delete_result_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  req_data        [?]         
 *  cnf_data        [?]         
 *  more            [IN]        
 *  ret             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_sim_delete_result_hdlr(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            void *req_data,
            void *cnf_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_sim_fsm_struct *fsm;
    srv_clog_sim_mgr_struct *sim_mgr = srv_clog_sim_get_mgr();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = srv_clog_sim_get_fsm_by_pid(sim_mgr, pid);

    if (fsm)
    {
        MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_DELETE_RESULT_HDLR, handle, pid, ret, fsm->state);
        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_DELETE_RESULT_HDLR,
                       "[CLogSrv]srv_clog_sim_delete_result_hdlr(handle=%d,pid=%d,ret=%d,state=%d)"), handle, pid, ret,
                      fsm->state));

        fsm->state = SRV_CLOG_SIM_STATE_GET_EF_INFO;
        srv_clog_sim_start_next_sync(sim_mgr, fsm);
    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_is_read_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_mgr     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_clog_sim_is_read_action(srv_clog_sim_mgr_struct *sim_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sync_type = sim_mgr->req.sync_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sync_type == SRV_CLOG_SIM_SYNC_TYPE_PWOF_WRITE || sync_type == SRV_CLOG_SIM_SYNC_TYPE_CMN_WRITE)
        return MMI_FALSE;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_sync_cmn_result_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_mgr     [?]         
 *  fsm         [?]         
 *  ret         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_sim_sync_cmn_result_hdlr(
                srv_clog_sim_mgr_struct *sim_mgr,
                srv_clog_sim_fsm_struct *fsm,
                srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_SYNC_CMN_RESULT_HDLR, ret);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_SYNC_CMN_RESULT_HDLR,
                   "[CLogSrv]srv_clog_sim_sync_cmn_result_hdlr(ret=%d)"), ret));

    if (ret != SRV_CLOG_RET_OK)
    {
        SRV_CLOG_DUMP(SRV_CLOG_DUMP_TYPE_SIM_SYNC);
    }

    if (fsm->ret == SRV_CLOG_RET_OK)
        fsm->ret = ret;
    SRV_CLOG_SET_BIT(sim_mgr->done.sim_id, fsm->cur.sim_id);
    SRV_CLOG_SET_BIT(sim_mgr->done.clt_type[fsm->cur.sim_idx], fsm->cur.clt_type[fsm->cur.sim_idx]);
    sim_mgr->done.ret = ret;
    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
        fsm->cur.clt_type[i] = SRV_CLOG_CLT_DEFAULT;
    fsm->cur.clt_idx = SRV_CLOG_CLT_IDX_DIALED;
    fsm->cursor = 0;
    fsm->sync_act_cursor = 0;
    fsm->state = SRV_CLOG_SIM_STATE_PROCESS_NEXT_EF;

    srv_clog_sim_start_next_sync(sim_mgr, fsm);

}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_start_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_mgr     [?]     
 *  fsm         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_sim_start_read(srv_clog_sim_mgr_struct *sim_mgr, srv_clog_sim_fsm_struct *fsm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_sim_ef_info_struct *ef_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ASSERT(sim_mgr && fsm);

    ef_info = &fsm->ef_info[fsm->cur.clt_idx];

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SIM_START_READ,
        fsm->state,
        fsm->cur.sim_id,
        fsm->cur.clt_type[fsm->cur.sim_idx],
        ef_info->used_rec,
        ef_info->total_rec);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_START_READ,
                   "[CLogSrv]srv_clog_sim_start_read(state=%d,cur_sim_id=%d,cur_clt=%d,ef_info=%d/%d)"), fsm->state,
                  fsm->cur.sim_id, fsm->cur.clt_type[fsm->cur.sim_idx], ef_info->used_rec, ef_info->total_rec));

    if (ef_info->used_rec == 0) /* empty */
    {
        srv_clog_sim_sync_cmn_result_hdlr(sim_mgr, fsm, SRV_CLOG_RET_OK);
        return;
    }
    fsm->state = SRV_CLOG_SIM_STATE_READING;
    fsm->cursor = ef_info->used_rec;
    fsm->sync_act_cursor = fsm->cursor;
    srv_clog_sim_read_next(sim_mgr, fsm);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_read_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_mgr     [?]     
 *  fsm         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_sim_read_next(srv_clog_sim_mgr_struct *sim_mgr, srv_clog_sim_fsm_struct *fsm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_clog_sim_ef_info_struct *ef_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fsm->cursor == 0)
    {
        ef_info = &fsm->ef_info[fsm->cur.clt_idx];

        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_SIM_READ_NEXT_DONE,
            fsm->state,
            1,
            fsm->cursor,
            ef_info->used_rec,
            ef_info->total_rec,
            fsm->cur.sim_id,
            fsm->cur.clt_type[fsm->cur.sim_idx]);
        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_READ_NEXT_DONE,
                       "[CLogSrv]srv_clog_sim_read_next(state=%d,done=%d,cursor=%d,ef=%d/%d,sim_id=%d,clt=%d)"),
                      fsm->state, 1, fsm->cursor, ef_info->used_rec, ef_info->total_rec, fsm->cur.sim_id,
                      fsm->cur.clt_type[fsm->cur.sim_idx]));

        srv_clog_sim_sync_cmn_result_hdlr(sim_mgr, fsm, SRV_CLOG_RET_OK);
        return;
    }

    for (i = 0; i < SRV_CLOG_SIM_MAX_SYNC_READ_ACT_NUM; i++)
    {
        srv_clog_sim_send_phb_read_sim_ln_req(fsm->cur.sim_id, fsm->cur.clt_type[fsm->cur.sim_idx], fsm->cursor);
        fsm->cursor--;  /* point to the array index of the next log to read */
        if (fsm->cursor == 0)
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_start_write
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_mgr     [?]     
 *  fsm         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_sim_start_write(srv_clog_sim_mgr_struct *sim_mgr, srv_clog_sim_fsm_struct *fsm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_sim_ef_info_struct *ef_info;
    srv_clog_log_identity_struct idt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fsm->state == SRV_CLOG_SIM_STATE_GET_EF_INFO)
    {
        idt.cate = SRV_CLOG_CATE_CALL;
        idt.sim_id = fsm->cur.sim_id;
        idt.log_type = fsm->cur.clt_type[fsm->cur.sim_idx];
        idt.sub_type = SRV_CLOG_SIM_SUPPORT_CALL_TYPE;

        srv_clog_idx_refresh(sim_mgr->cntx->comp->idx_tbl, SRV_CLOG_LIST_LEVEL_STORE, &idt, &fsm->idx_info_type);
        fsm->total_to_write = srv_clog_idx_total_num(sim_mgr->cntx->comp->idx_tbl, fsm->idx_info_type, NULL);

        /*
         * even delete all, we still need to reset SIM records 
         * if (sim_mgr->total_to_write == 0) 
         * {
         * srv_clog_sim_sync_cmn_result_hdlr(sim_mgr, SRV_CLOG_RET_OK);
         * return;
         * }
         */
    }
    ef_info = &fsm->ef_info[fsm->cur.clt_idx];

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_SIM_START_WRITE,
        fsm->state,
        fsm->cur.sim_id,
        fsm->cur.clt_type[fsm->cur.sim_idx],
        ef_info->used_rec,
        ef_info->total_rec,
        fsm->total_to_write,
        fsm->idx_info_type);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_START_WRITE,
                   "[CLogSrv]srv_clog_sim_start_write(state=%d,cur_sim_id=%d,cur_clt=%d,ef_info=%d/%d,to_write=%d,info_type=%d)"),
                  fsm->state, fsm->cur.sim_id, fsm->cur.clt_type[fsm->cur.sim_idx], ef_info->used_rec,
                  ef_info->total_rec, fsm->total_to_write, fsm->idx_info_type));

    if (fsm->state == SRV_CLOG_SIM_STATE_GET_EF_INFO && fsm->total_to_write < ef_info->total_rec)
    {
        fsm->cursor = ef_info->total_rec - fsm->total_to_write; /* sim record number to delete */
        fsm->state = SRV_CLOG_SIM_STATE_DELETING;
        fsm->sync_act_cursor = fsm->cursor;
        srv_clog_sim_delete_next(sim_mgr, fsm);
        return;
    }
    if (fsm->state == SRV_CLOG_SIM_STATE_GET_EF_INFO && fsm->total_to_write >= ef_info->total_rec || fsm->state == SRV_CLOG_SIM_STATE_DELETING && fsm->cursor == 0)     /* check if delete all */
    {
        if (fsm->total_to_write >= ef_info->total_rec)
            fsm->cursor = ef_info->total_rec;
        else
            fsm->cursor = fsm->total_to_write;
        fsm->state = SRV_CLOG_SIM_STATE_WRITEING;
        fsm->sync_act_cursor = fsm->cursor;
        srv_clog_sim_write_next(sim_mgr, fsm);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_write_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_mgr     [?]     
 *  fsm         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_sim_write_next(srv_clog_sim_mgr_struct *sim_mgr, srv_clog_sim_fsm_struct *fsm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 sit_idx;
    srv_clog_si_struct *si_log;
    srv_clog_idx_info_enum info_type;
    srv_clog_log_identity_struct idt;
    srv_clog_si_tbl_struct *si_tbl;
    srv_clog_idx_tbl_struct *idx_tbl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fsm->cursor == 0)
    {
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_SIM_WRITE_NEXT,
            fsm->state,
            1,
            fsm->cursor,
            fsm->cur.sim_id,
            fsm->cur.clt_type[fsm->cur.sim_idx],
            fsm->idx_info_type);
        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_WRITE_NEXT,
                       "[CLogSrv]srv_clog_sim_write_next(state=%d,done=%d,cursor=%d,sim_id=%d,clt=%d,info_type=%d)"),
                      fsm->state, 1, fsm->cursor, fsm->cur.sim_id, fsm->cur.clt_type[fsm->cur.sim_idx],
                      fsm->idx_info_type));

        srv_clog_sim_sync_cmn_result_hdlr(sim_mgr, fsm, SRV_CLOG_RET_OK);
        return;
    }

    si_tbl = sim_mgr->cntx->comp->si_tbl;
    idx_tbl = sim_mgr->cntx->comp->idx_tbl;

    idt.cate = SRV_CLOG_CATE_CALL;
    idt.sim_id = fsm->cur.sim_id;
    idt.log_type = fsm->cur.clt_type[fsm->cur.sim_idx];
    idt.sub_type = SRV_CLOG_SIM_SUPPORT_CALL_TYPE;
    srv_clog_idx_refresh(idx_tbl, SRV_CLOG_LIST_LEVEL_STORE, &idt, &info_type);
    for (i = 0; i < SRV_CLOG_SIM_MAX_SYNC_WRITE_ACT_NUM; i++)
    {
        sit_idx = srv_clog_idx_index(idx_tbl, info_type, fsm->cursor - 1);      /* cursor is SIM record index and start from 1 */
        /* Run some error check here */
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else /* 0 */ 

        if (sit_idx < SRV_CLOG_LOG_MAX_NUM)
        {
            si_log = srv_clog_si_index(si_tbl, sit_idx);
            if (srv_clog_si_is_valid(si_log))
                srv_clog_sim_send_phb_write_sim_ln_req(fsm->cur.sim_id, fsm->cur.clt_type[fsm->cur.sim_idx], si_log);
            else
            {
                fsm->sync_act_cursor--;

                MMI_TRACE(
                    SRV_CLOG_TRC_WARNING,
                    TRC_SRV_CLOG_SIM_WRITE_NEXT,
                    fsm->state,
                    -1,
                    fsm->cursor,
                    fsm->cur.sim_id,
                    fsm->cur.clt_type[fsm->cur.sim_idx],
                    fsm->sync_act_cursor);
                SRV_CLOG_TRC((SRV_CLOG_TS
                              (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_WRITE_NEXT,
                               "[CLogSrv]srv_clog_sim_write_next(state=%d,done=%d,cursor=%d,sim_id=%d,clt=%d,info_type=%d)"),
                              fsm->state, -1, fsm->cursor, fsm->cur.sim_id, fsm->cur.clt_type[fsm->cur.sim_idx],
                              fsm->sync_act_cursor));
            }
        }
        else
        {
            fsm->sync_act_cursor--;

            MMI_TRACE(
                SRV_CLOG_TRC_WARNING,
                TRC_SRV_CLOG_SIM_WRITE_NEXT,
                fsm->state,
                -2,
                fsm->cursor,
                fsm->cur.sim_id,
                fsm->cur.clt_type[fsm->cur.sim_idx],
                fsm->sync_act_cursor);
            SRV_CLOG_TRC((SRV_CLOG_TS
                          (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_WRITE_NEXT,
                           "[CLogSrv]srv_clog_sim_write_next(state=%d,done=%d,cursor=%d,sim_id=%d,clt=%d,info_type=%d)"),
                          fsm->state, -2, fsm->cursor, fsm->cur.sim_id, fsm->cur.clt_type[fsm->cur.sim_idx],
                          fsm->sync_act_cursor));
        }
    #endif /* 0 */ 

        fsm->cursor--;  /* point to the array index of the next log to write */
        if (fsm->cursor == 0)
            break;
    }
    if (fsm->sync_act_cursor == fsm->cursor)
        srv_clog_sim_write_next(sim_mgr, fsm);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_delete_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_mgr     [?]     
 *  fsm         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_sim_delete_next(srv_clog_sim_mgr_struct *sim_mgr, srv_clog_sim_fsm_struct *fsm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fsm->cursor == 0)   /* all LND records are delete, start to write */
    {
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_SIM_DELETE_NEXT,
            fsm->state,
            1,
            fsm->cur.sim_id,
            fsm->cur.clt_type[fsm->cur.sim_idx],
            fsm->cursor,
            fsm->cur.ret);
        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_DELETE_NEXT,
                       "[CLogSrv]srv_clog_sim_delete_next(done=%d,state=%d,sim_id=%d,clt=%d,cursor=%d,ret=%d)"),
                      fsm->state, 1, fsm->cur.sim_id, fsm->cur.clt_type[fsm->cur.sim_idx], fsm->cursor, fsm->cur.ret));

        srv_clog_sim_start_write(sim_mgr, fsm);
        return;
    }
    for (i = 0; i < SRV_CLOG_SIM_MAX_SYNC_DEL_ACT_NUM; i++)
    {
        srv_clog_sim_send_phb_delete_sim_ln_req(fsm->cur.sim_id, fsm->cur.clt_type[fsm->cur.sim_idx]);
        fsm->cursor--;
        if (fsm->cursor == 0)
            break;
    }
}

#define SRV_CLOG_SIM_MSG_HDLR


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_sim_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_INIT);

    SRV_CLOG_TRC((SRV_CLOG_TS(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SIM_INIT, "[CLogSrv]srv_clog_sim_init()")));

    srv_clog_sim_pevt_init();
    memset(
        srv_clog_ef_info,
        SRV_CLOG_SIM_EF_INVALID_NUM,
        sizeof(srv_clog_sim_ef_info_struct) * SRV_CLOG_SIM_IDX_MAX_ITEM);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_pevt_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_sim_pevt_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_PHB_GET_LN_TYPE_INFO_RSP, 
    (PsIntFuncPtr) srv_clog_sim_phb_get_ln_type_info_rsp_hdlr, MMI_FALSE);
    
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_PHB_READ_SIM_LN_RSP, 
        (PsIntFuncPtr) srv_clog_sim_phb_read_sim_ln_rsp_hdlr, MMI_FALSE);
    
 
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_PHB_WRITE_SIM_LN_RSP, 
        (PsIntFuncPtr) srv_clog_sim_phb_write_sim_ln_rsp_hdlr, MMI_FALSE);
    
     mmi_frm_set_protocol_event_handler(MSG_ID_MMI_PHB_DELETE_SIM_LN_RSP, 
        (PsIntFuncPtr) srv_clog_sim_phb_delete_sim_ln_rsp_hdlr, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_phb_get_ln_type_info_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_sim_phb_get_ln_type_info_rsp_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_get_ln_type_info_rsp_struct *rsp;
    srv_clog_sim_mgr_struct *sim_mgr = srv_clog_sim_get_mgr();
    srv_clog_sim_ef_info_struct *ef_info;
    srv_clog_sim_fsm_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!sim_mgr)
        return 0;
    fsm = srv_clog_sim_get_fsm_by_sim_id(sim_mgr, mmi_frm_l4c_mod_to_sim((module_type)mod_id));
    if (!fsm || fsm->state != SRV_CLOG_SIM_STATE_GET_EF_INFO || mod_id != mmi_frm_sim_to_l4c_mod(fsm->cur.sim_id))
        return 0;

    rsp = (mmi_phb_get_ln_type_info_rsp_struct*) local_param;

    if (rsp->result == MMI_FALSE)
    {
        srv_clog_sim_sync_cmn_result_hdlr(sim_mgr, fsm, SRV_CLOG_RET_FAIL);
        return 0;
    }
    ef_info = &fsm->ef_info[fsm->cur.clt_idx];
    ef_info->total_rec = rsp->num_of_tot_rec;
    ef_info->used_rec = rsp->num_of_used_rec;

    /*
     * To limited the max EF record number, too many records to read/write 
     * can cause very pool performance expecially on power-off-writing
     */
    if (ef_info->total_rec > SRV_CLOG_SIM_EF_RECORD_MAX_SUP_NUM)
        ef_info->total_rec = SRV_CLOG_SIM_EF_RECORD_MAX_SUP_NUM;
    if (ef_info->used_rec > SRV_CLOG_SIM_EF_RECORD_MAX_SUP_NUM)
        ef_info->used_rec = SRV_CLOG_SIM_EF_RECORD_MAX_SUP_NUM;

    /* Temp solution to improve power off performance */
    srv_clog_ef_info[fsm->cur.sim_idx].total_rec = ef_info->total_rec;
    srv_clog_ef_info[fsm->cur.sim_idx].used_rec = ef_info->used_rec;

    if (srv_clog_sim_is_read_action(sim_mgr))
        srv_clog_sim_start_read(sim_mgr, fsm);
    else
        srv_clog_sim_start_write(sim_mgr, fsm);
    return 0;

}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_phb_read_sim_ln_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_sim_phb_read_sim_ln_rsp_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_log_struct cmn_log;
    mmi_phb_read_sim_ln_rsp_struct *rsp;
    srv_clog_sim_mgr_struct *sim_mgr = srv_clog_sim_get_mgr();
    srv_clog_sim_fsm_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!sim_mgr)
        return 0;
    fsm = srv_clog_sim_get_fsm_by_sim_id(sim_mgr, mmi_frm_l4c_mod_to_sim((module_type)mod_id));
    if (!fsm || fsm->state != SRV_CLOG_SIM_STATE_READING || mod_id != mmi_frm_sim_to_l4c_mod(fsm->cur.sim_id))
        return 0;

    rsp = (mmi_phb_read_sim_ln_rsp_struct*) local_param;
    if (rsp->result.flag != L4C_OK)
    {
        /* to do change cause to ret?? */
        srv_clog_sim_sync_cmn_result_hdlr(sim_mgr, fsm, SRV_CLOG_RET_FAIL);
        return 0;
    }
    ret = srv_clog_is_ln_invalid((const l4c_phb_ln_entry_struct*)&rsp->entry);
    if (ret)
    {
        /* skip invalid logs */
        fsm->sync_act_cursor--;
        if (fsm->sync_act_cursor > fsm->cursor)
            return 0;
        srv_clog_sim_read_next(sim_mgr, fsm);
        return 0;
    }
    srv_clog_log_l4c2cmn(
        (const l4c_phb_ln_entry_struct*)&rsp->entry,
        fsm->cur.sim_id,
        fsm->cur.clt_type[fsm->cur.sim_idx],
        &cmn_log);
    cmn_log.data.call_log.log_id = srv_clog_new_log_id_ex(sim_mgr->cntx, &fsm->start_log_id);

    /*
     * First send primitive to MMI task, then send message to L4C, this can avoid to make MMI task queue full
     * currently not care the result
     */

    ret = srv_clog_add_log(sim_mgr->handle, 0, (const srv_clog_add_log_req_struct*)&cmn_log, NULL, NULL);
    if (ret <= SRV_CLOG_RET_OK)
    {
        /* If add fail, stop ? */
        srv_clog_sim_sync_cmn_result_hdlr(sim_mgr, fsm, SRV_CLOG_RET_FAIL);
        return 0;
    }

    fsm->sync_act_cursor--;
    if (fsm->sync_act_cursor > fsm->cursor)
        return 0;

    srv_clog_sim_read_next(sim_mgr, fsm);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_phb_write_sim_ln_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_sim_phb_write_sim_ln_rsp_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_write_sim_ln_rsp_struct *rsp;
    srv_clog_sim_mgr_struct *sim_mgr = srv_clog_sim_get_mgr();
    srv_clog_sim_fsm_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!sim_mgr)
        return 0;
    fsm = srv_clog_sim_get_fsm_by_sim_id(sim_mgr, mmi_frm_l4c_mod_to_sim((module_type)mod_id));
    if (!fsm || fsm->state != SRV_CLOG_SIM_STATE_WRITEING || mod_id != mmi_frm_sim_to_l4c_mod(fsm->cur.sim_id))
        return 0;

    rsp = (mmi_phb_write_sim_ln_rsp_struct*) local_param;
    if (rsp->result.flag != L4C_OK)
    {
        srv_clog_sim_sync_cmn_result_hdlr(sim_mgr, fsm, SRV_CLOG_RET_FAIL);
        return 0;
    }
    fsm->sync_act_cursor--;
    if (fsm->sync_act_cursor > fsm->cursor)
        return 0;

    srv_clog_sim_write_next(sim_mgr, fsm);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_phb_delete_sim_ln_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param     [?]         
 *  mod_id          [IN]        
 *  ilm             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_clog_sim_phb_delete_sim_ln_rsp_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_delete_sim_ln_rsp_struct *rsp;
    srv_clog_sim_mgr_struct *sim_mgr = srv_clog_sim_get_mgr();
    srv_clog_sim_fsm_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!sim_mgr)
        return 0;
    fsm = srv_clog_sim_get_fsm_by_sim_id(sim_mgr, mmi_frm_l4c_mod_to_sim((module_type)mod_id));
    if (!fsm || fsm->state != SRV_CLOG_SIM_STATE_DELETING || mod_id != mmi_frm_sim_to_l4c_mod(fsm->cur.sim_id))
        return 0;

    rsp = (mmi_phb_delete_sim_ln_rsp_struct*) local_param;
    if (rsp->result.flag != L4C_OK)
    {
        srv_clog_sim_sync_cmn_result_hdlr(sim_mgr, fsm, SRV_CLOG_RET_FAIL);
        return 0;
    }

    fsm->sync_act_cursor--;
    if (fsm->sync_act_cursor > fsm->cursor)
        return 0;

    srv_clog_sim_delete_next(sim_mgr, fsm);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_send_phb_get_ln_type_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  clt_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_sim_send_phb_get_ln_type_info_req(mmi_sim_enum sim_id, srv_clog_clt_enum clt_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_get_ln_type_info_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = SRV_CLOG_NEW_ILM_DATA(mmi_phb_get_ln_type_info_req_struct);
    req->type = srv_clog_clt_bit2l4c(clt_type);
    req->storage = PHB_STORAGE_SIM;

    srv_clog_send_l4c_ilm(sim_id, MSG_ID_MMI_PHB_GET_LN_TYPE_INFO_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_send_phb_read_sim_ln_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  clt_type        [IN]        
 *  rec_idx         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_sim_send_phb_read_sim_ln_req(mmi_sim_enum sim_id, srv_clog_clt_enum clt_type, U32 rec_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_read_sim_ln_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = SRV_CLOG_NEW_ILM_DATA(mmi_phb_read_sim_ln_req_struct);
    req->type = srv_clog_clt_bit2l4c(clt_type);
    req->record_index = rec_idx;

    srv_clog_send_l4c_ilm(sim_id, MSG_ID_MMI_PHB_READ_SIM_LN_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_send_phb_write_sim_ln_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  clt_type        [IN]        
 *  si_log          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_sim_send_phb_write_sim_ln_req(
                mmi_sim_enum sim_id,
                srv_clog_clt_enum clt_type,
                const srv_clog_si_struct *si_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_write_sim_ln_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = SRV_CLOG_NEW_ILM_DATA(mmi_phb_write_sim_ln_req_struct);
    req->type = srv_clog_clt_bit2l4c(clt_type);
    srv_clog_log_si2l4c(si_log, &req->entry);
    srv_clog_send_l4c_ilm(sim_id, MSG_ID_MMI_PHB_WRITE_SIM_LN_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_sim_send_phb_delete_sim_ln_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  clt_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_sim_send_phb_delete_sim_ln_req(mmi_sim_enum sim_id, srv_clog_clt_enum clt_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_delete_sim_ln_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = SRV_CLOG_NEW_ILM_DATA(mmi_phb_delete_sim_ln_req_struct);
    req->type = srv_clog_clt_bit2l4c(clt_type);
    srv_clog_send_l4c_ilm(sim_id, MSG_ID_MMI_PHB_DELETE_SIM_LN_REQ, req);
}

#endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */ 

