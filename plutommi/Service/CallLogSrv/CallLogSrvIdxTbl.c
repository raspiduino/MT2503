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
*  CallLogSrvIdxTbl.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "mmi_include.h"

#ifdef __MMI_TELEPHONY_SUPPORT__
#include "string.h"

#include "kal_general_types.h"
#include "kal_trace.h"
#include "app_datetime.h"

#include "custom_calllog.h"
#include "common_nvram_editor_data_item.h"

#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvComp.h"
#include "CallLogSrvProt.h"

/*----------------------------------------------------------------------------*/
/* Micro                                                                      */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_IDX_GET_ELM(idx_tbl, info_type, info, info_data, total_num)  \
    do {                                                                      \
        info = idx_tbl->idx_info[info_type];                                  \
        info_data = (U16*)info->data;                                         \
        total_num = info->total_num;                                          \
    }while(0)

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
typedef enum
{
    SRV_CLOG_FULL_NONE,
    SRV_CLOG_FULL_SLOT,
    SRV_CLOG_FULL_BASE,
    SRV_CLOG_FULL_TYPE,
    SRV_CLOG_FULL_MAX_ITEM
} srv_clog_full_enum;

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/

/*---------------------- Sort Operation --------------------------------------*/
/* FlowReserved
static SRV_CLOG_COMPARE_FUNC srv_clog_get_sort_func_by_type(
                        srv_clog_sort_enum sort_type,
                        srv_clog_direction_enum direction,
                        srv_clog_sort_algorithm_enum algorithm);
static S32 srv_clog_sort_by_timestamp(void *src, void *dst);
*/
static S32 srv_clog_sort_by_log_id(void *src, void *dst);

/*---------------------- Index Table Operation -------------------------------*/
static srv_clog_idx_info_struct *srv_clog_idx_new_info(U32 mem_type, U32 data_size);
static void srv_clog_idx_clear_info(srv_clog_idx_info_struct *idx_info);

static S32 srv_clog_idx_prepare(srv_clog_idx_tbl_struct *idx_tbl);
static void srv_clog_idx_init_sort(srv_clog_idx_tbl_struct *idx_tbl);
static void srv_clog_idx_init_idx_info_idt(
                srv_clog_idx_tbl_struct *idx_tbl,
                srv_clog_idx_info_enum info_type,
                S32 init_all);
static void srv_clog_idx_reset_info(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type);

static S32 srv_clog_idx_reset_l1(srv_clog_idx_tbl_struct *idx_tbl);
static S32 srv_clog_idx_reset_l2(srv_clog_idx_tbl_struct *idx_tbl);
static S32 srv_clog_idx_sort_l1(srv_clog_idx_tbl_struct *idx_tbl);
static S32 srv_clog_idx_merge_l1(srv_clog_idx_tbl_struct *idx_tbl);
static S32 srv_clog_idx_add(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_idx_info_enum info_type,
            srv_clog_si_struct *si_log,
            U32 si_tbl_idx);
static S32 srv_clog_idx_insert(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_idx_info_enum info_type,
            U32 idx_info_idx,
            U32 si_tbl_idx);

static S32 srv_clog_idx_filter_reset(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type);
static S32 srv_clog_idx_is_same_sort(srv_clog_idx_info_struct *src, srv_clog_idx_info_struct *dst);

static S32 srv_clog_idx_lv1_get_log_by_id(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_idx_info_enum info_type,
            SRV_CLOG_ID log_id,
            U32 fields,
            srv_clog_log_struct *log);

#if 0 /*APIReserved */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0

static srv_clog_idx_info_enum srv_clog_idx_level2info(
                                srv_clog_idx_tbl_struct *idx_tbl,
                                srv_clog_list_level_enum list_level,
                                srv_clog_log_identity_struct *idt,
                                S32 *diff);

static S32 srv_clog_idx_lv1_delete_id(srv_clog_idx_tbl_struct *idx_tbl, SRV_CLOG_ID log_id);

#if 0 //APIReserved
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0

static S32 srv_clog_idx_lv2_delete_id(srv_clog_idx_tbl_struct *idx_tbl, SRV_CLOG_ID log_id);
static S32 srv_clog_idx_lv1_delete_index(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_idx_info_enum info_type,
            U32 idx_info_idx);

static S32 srv_clog_idx_check_merge(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_job_add_log_req_struct *req_data);
static srv_clog_full_enum srv_clog_idx_check_full(
                            srv_clog_idx_tbl_struct *idx_tbl,
                            srv_clog_si_struct *si_log,
                            srv_clog_log_identity_struct *type_idt);
static S32 srv_clog_idx_find_oldest(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_job_add_log_req_struct *req_data);
static S32 srv_clog_idx_base_get_oldest(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_job_add_log_req_struct *req_data);
static S32 srv_clog_idx_base_get_oldest_by_i(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_job_add_log_req_struct *req_data);

/*----------------------------------------------------------------------------*/
/* Extern Function Declaration                                                */
/*----------------------------------------------------------------------------*/

#define SRV_CLOG_IDX_SORT

#if 0 //APIReserved
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
#endif //0

/*****************************************************************************
 * FUNCTION
 *  srv_clog_sort_by_log_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [?]     
 *  dst     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_sort_by_log_id(void *src, void *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_base_info_struct *src_node = (srv_clog_base_info_struct*) src;
    srv_clog_base_info_struct *dst_node = (srv_clog_base_info_struct*) dst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ASSERT(src != NULL && dst != NULL);

    /* if the timestamp is same, just sort it according the received time. */

    if (src_node->log_id < dst_node->log_id)
        return -1;
    else if (src_node->log_id == dst_node->log_id)
        return 0;
    else
        return 1;
}



/*--------------- Index info table -------------------------------------------*/

#define SRV_CLOG_IDX_BASE


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_type        [IN]        
 *  si_tbl          [?]         
 *  style_mgr       [?]         
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_idx_tbl_struct *srv_clog_idx_create(
                            U32 mem_type,
                            srv_clog_si_tbl_struct *si_tbl,
                            srv_clog_stl_mgr_struct *style_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_clog_idx_tbl_struct *idx_tbl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx_tbl = SRV_CLOG_TALLOC(mem_type, srv_clog_idx_tbl_struct);
    memset(idx_tbl, 0x0, sizeof(srv_clog_idx_tbl_struct));
    idx_tbl->si_tbl = si_tbl;
    idx_tbl->style_mgr = style_mgr;

    idx_tbl->idx_info[SRV_CLOG_IDX_INFO_BASE] = srv_clog_idx_new_info(mem_type, SRV_CLOG_LOG_MAX_NUM);
    idx_tbl->idx_info[SRV_CLOG_IDX_INFO_THREAD] = srv_clog_idx_new_info(mem_type, SRV_CLOG_LOG_MAX_NUM);

    for (i = SRV_CLOG_IDX_INFO_FILTER; i < SRV_CLOG_IDX_INFO_MAX_ITEM; i++)
        idx_tbl->idx_info[i] = srv_clog_idx_new_info(mem_type, SRV_CLOG_OP_TYPE_MAX_NUM);
    return idx_tbl;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_new_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_type        [IN]        
 *  data_size       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_clog_idx_info_struct *srv_clog_idx_new_info(U32 mem_type, U32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_idx_info_struct *idx_info;
    U32 mem_size = data_size * sizeof(U16);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx_info = SRV_CLOG_TALLOC(mem_type, srv_clog_idx_info_struct);
    memset(idx_info, 0x0, sizeof(srv_clog_idx_info_struct));
#ifndef __SRV_CLOG_UT__
    idx_info->data = SRV_CLOG_MALLOC(mem_type, mem_size);
#endif 
    memset(idx_info->data, SRV_CLOG_IDX_INVALID_IDX, mem_size);
    idx_info->max_size = data_size;
    return idx_info;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_get_idt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_log_identity_struct *srv_clog_idx_get_idt(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_log_identity_struct *idt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ASSERT(info_type < SRV_CLOG_IDX_INFO_MAX_ITEM);

    idt = &(idx_tbl->idx_info[info_type]->idt);
    return idt;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_total_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 *  idt             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_clog_idx_total_num(
        srv_clog_idx_tbl_struct *idx_tbl,
        srv_clog_idx_info_enum info_type,
        srv_clog_log_identity_struct **idt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx_tbl->idx_info[info_type])
    {
        if (idt)
            *idt = &((idx_tbl->idx_info[info_type])->idt);
        return (idx_tbl->idx_info[info_type])->total_num;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 *  index           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_clog_idx_index(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_idx_info_struct *idx_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx_info = idx_tbl->idx_info[info_type];
    if (index >= idx_info->total_num)
        return SRV_CLOG_IDX_INVALID_IDX;
    return idx_info->data[index];
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_clear
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl     [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_idx_clear(srv_clog_idx_tbl_struct *idx_tbl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CLOG_IDX_INFO_MAX_ITEM; i++)
    {
        srv_clog_idx_clear_info(idx_tbl->idx_info[i]);
    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_clear_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_idx_clear_info(srv_clog_idx_info_struct *idx_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(idx_info->data, SRV_CLOG_IDX_INVALID_IDX, sizeof(U16) * idx_info->total_num);
    idx_info->total_num = 0;
}



/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_get_ur_mclt_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  num_list        [?]         
 *  sim_num         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_clog_idx_get_ur_mclt_num(srv_clog_idx_tbl_struct *idx_tbl, U32 *num_list, U32 sim_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 total_num = 0;
    srv_clog_log_identity_struct idt = { 0 };
    srv_clog_num_info_struct num_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {   
        idt.sim_id = SRV_CLOG_IDX2BIT(i);
        srv_clog_idx_get_num_info(idx_tbl, &idt, &num_info);
        if (num_list && i < sim_num)
        {
            num_list[i] = num_info.num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM];
        }
        total_num += num_info.num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM];
        SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_GET_UR_MCLT_NUM_SINGLE, i, num_info.num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM]));
    }
    SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_GET_UR_MCLT_NUM_TOTAL, total_num));
    return total_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_get_num_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  level           [IN]        
 *  idt             [?]         
 *  num_info        [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_idx_get_num_info(
        srv_clog_idx_tbl_struct *idx_tbl,
        srv_clog_log_identity_struct *idt,
        srv_clog_num_info_struct *num_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 props;
    U32 total_num;
    U16 *idx_list;
    srv_clog_si_struct *si_log;
    srv_clog_idx_info_struct *base_idx_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //?? Check if Base info can be changed at any time? if so, better use srv_clog_si_get_num_info to do this
    base_idx_info = idx_tbl->idx_info[SRV_CLOG_IDX_INFO_BASE];
    total_num = base_idx_info->total_num;
    idx_list = (U16*) base_idx_info->data;
    memset(num_info, 0x0, sizeof(srv_clog_num_info_struct));
    
    for (i = 0; i < total_num; i++)
    {
        si_log = srv_clog_si_index(idx_tbl->si_tbl, idx_list[i]);
        SRV_CLOG_IT_ASSERT(srv_clog_si_is_valid(si_log));
        props = SRV_CLOG_SI_GET_P(si_log);
        if (!srv_clog_pi_is_ip_sub(idt, props))
            continue;
        
        num_info->num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS]++;
        num_info->num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM] += SRV_CLOG_SI_GET_URNUM(si_log);
    }
    return SRV_CLOG_RET_OK;
}


#define SRV_CLOG_IDX_RESET


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_parse
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl     [?]     
 * RETURNS
 *  
 *****************************************************************************/
extern S32 srv_clog_idx_parse(srv_clog_idx_tbl_struct *idx_tbl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_idx_prepare(idx_tbl);
    return srv_clog_idx_reset(idx_tbl, SRV_CLOG_IDX_INFO_BASE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_prepare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_prepare(srv_clog_idx_tbl_struct *idx_tbl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_idx_init_sort(idx_tbl);
    srv_clog_idx_init_idx_info_idt(idx_tbl, SRV_CLOG_IDX_INFO_BASE, MMI_TRUE);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_init_sort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_idx_init_sort(srv_clog_idx_tbl_struct *idx_tbl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_clog_idx_info_struct *idx_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set the sort style,  use the same sort style for all index table now */
//FlowReserved
//    srv_clog_stl_get_style(idx_tbl->style_mgr, SRV_CLOG_STYLE_TYPE_BASE_SORT, &sort_style, NULL);


    for (i = 0; i < SRV_CLOG_IDX_INFO_MAX_ITEM; i++)
    {
        idx_info = idx_tbl->idx_info[i];
//FlowReserved
//        srv_clog_stl_parse_sort(sort_style, &idx_info->sort_type, &idx_info->sort_dir, &idx_info->sort_algo);
        idx_info->flags = 0;
        idx_info->total_num = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_init_idx_info_idt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 *  init_all        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_idx_init_idx_info_idt(
                srv_clog_idx_tbl_struct *idx_tbl,
                srv_clog_idx_info_enum info_type,
                S32 init_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_log_identity_struct idt = 
    {
        SRV_CLOG_CATE_CALL,
        SRV_CLOG_SIM_ID_ALL,
        SRV_CLOG_CLT_ALL,
        SRV_CLOG_CALL_TYPE_ALL
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Set the base filter here, 
     * the missed call and received call are treated as more important than others
     */
    if (init_all || info_type == SRV_CLOG_IDX_INFO_BASE)
        srv_clog_pi_cp_i(&idt, &idx_tbl->idx_info[SRV_CLOG_IDX_INFO_BASE]->idt);

    if (init_all || info_type == SRV_CLOG_IDX_INFO_FILTER)
    {
        idt.log_type = SRV_CLOG_CLT_MISSED;
        srv_clog_pi_cp_i(&idt, &idx_tbl->idx_info[SRV_CLOG_IDX_INFO_FILTER]->idt);
    }

    if (init_all || info_type == SRV_CLOG_IDX_INFO_FILTER_EX)
    {
   //FlowReserved     
   //     if (!srv_clog_stl_support_thread(idx_tbl->style_mgr))
        {
            idt.log_type = SRV_CLOG_CLT_RECVED;
            srv_clog_pi_cp_i(&idt, &idx_tbl->idx_info[SRV_CLOG_IDX_INFO_FILTER_EX]->idt);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_reset_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_idx_reset_info(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_idx_info_struct *info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info = idx_tbl->idx_info[info_type];
    info->total_num = 0;
    info->flags = 0;
    /* srv_clog_idx_init_idx_info_idt(idx_tbl, info_type, MMI_FALSE); */
    memset(info->data, SRV_CLOG_IDX_INVALID_IDX, sizeof(U16) * info->max_size);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_idx_reset(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_CLOG_RET_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_RESET, info_type);

    switch (info_type)
    {
        case SRV_CLOG_IDX_INFO_BASE:
            ret = srv_clog_idx_reset_l1(idx_tbl);
            ret = srv_clog_idx_reset_l2(idx_tbl);
            break;

        case SRV_CLOG_IDX_INFO_FILTER:
            ret = srv_clog_idx_filter_reset(idx_tbl, SRV_CLOG_IDX_INFO_FILTER);
            break;

        case SRV_CLOG_IDX_INFO_THREAD:
            //FlowReserved
//            if (!srv_clog_stl_support_thread(idx_tbl->style_mgr))
            {
                ret = srv_clog_idx_filter_reset(idx_tbl, SRV_CLOG_IDX_INFO_FILTER_EX);
            }
            break;

        default:
            break;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_reset_l1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_reset_l1(srv_clog_idx_tbl_struct *idx_tbl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx_tbl->last_get_idx = 0;

    /* to reset base index table */
    ret = srv_clog_idx_sort_l1(idx_tbl);
    /* merge data and reset base idx table */
    ret = srv_clog_idx_merge_l1(idx_tbl);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_reset_l2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_reset_l2(srv_clog_idx_tbl_struct *idx_tbl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_idx_filter_reset(idx_tbl, SRV_CLOG_IDX_INFO_FILTER);
//FlowReserved
//    if (!srv_clog_stl_support_thread(idx_tbl->style_mgr))
        ret = srv_clog_idx_filter_reset(idx_tbl, SRV_CLOG_IDX_INFO_FILTER_EX);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_sort_l1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_sort_l1(srv_clog_idx_tbl_struct *idx_tbl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_clog_si_struct *si_log;
    srv_clog_si_tbl_struct *si_tbl = idx_tbl->si_tbl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_idx_reset_info(idx_tbl, SRV_CLOG_IDX_INFO_BASE);

    for (i = 0; i < SRV_CLOG_LOG_MAX_NUM; i++)
    {
        si_log = srv_clog_si_index(si_tbl, i);
        if (!srv_clog_si_is_valid(si_log))
            continue;
        if (!srv_clog_pi_is_ip_sub(&(idx_tbl->idx_info[SRV_CLOG_IDX_INFO_BASE]->idt), SRV_CLOG_SI_GET_P(si_log)))
            continue;
        srv_clog_idx_add(idx_tbl, SRV_CLOG_IDX_INFO_BASE, si_log, i);
    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_merge_l1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_merge_l1(srv_clog_idx_tbl_struct *idx_tbl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SRV_CLOG_RET_NOT_SUPPORT;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 *  si_log          [?]         
 *  si_tbl_idx      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_add(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_idx_info_enum info_type,
            srv_clog_si_struct *si_log,
            U32 si_tbl_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U16 *idx_data;
    U32 idx_total_num;
    srv_clog_si_struct **si_list;
    srv_clog_idx_info_struct *idx_info;
    SRV_CLOG_COMPARE_FUNC sort_func = srv_clog_sort_by_log_id;
    srv_clog_si_struct *dst_si_log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx_info = idx_tbl->idx_info[info_type];
    idx_data = idx_info->data;
    idx_total_num = idx_info->total_num;
    si_list = (srv_clog_si_struct **) idx_tbl->si_tbl->data;

/* FlowReserved
    sort_func = srv_clog_get_sort_func_by_type((srv_clog_sort_enum)idx_info->sort_type, 
                (srv_clog_direction_enum)idx_info->sort_dir, (srv_clog_sort_algorithm_enum)idx_info->sort_algo);
*/
    for (i = 0; i < idx_total_num; i++)
    {
        /* Skip itself */
        if (idx_data[i] == si_tbl_idx)
            continue;
        dst_si_log = si_list[idx_data[i]];
        if (sort_func((void*)si_log, (void*)dst_si_log) > 0)
            break;
    }
    /* just to add it to the end if i  == idx_total_num */
    srv_clog_idx_insert(idx_tbl, info_type, i, si_tbl_idx);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_insert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl             [?]         
 *  info_type           [IN]        
 *  idx_info_idx        [IN]        
 *  si_tbl_idx          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_insert(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_idx_info_enum info_type,
            U32 idx_info_idx,
            U32 si_tbl_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U16 *idx_data;
    srv_clog_idx_info_struct *idx_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ASSERT(idx_tbl && info_type <= SRV_CLOG_IDX_INFO_MAX_ITEM &&
                    idx_info_idx <= SRV_CLOG_LOG_MAX_NUM && si_tbl_idx <= SRV_CLOG_LOG_MAX_NUM);

    idx_info = idx_tbl->idx_info[info_type];

    /* Must not full here */
    SRV_CLOG_ASSERT(idx_info->total_num + 1 <= idx_info->max_size && idx_info_idx <= idx_info->total_num);

    idx_data = (U16*) idx_info->data;
    if (idx_info->total_num == 0)
    {
        idx_data[idx_info_idx] = si_tbl_idx;
        idx_info->total_num++;
        return SRV_CLOG_RET_OK;
    }
    for (i = idx_info->total_num - 1; i >= idx_info_idx; i--)
    {
        idx_data[i + 1] = idx_data[i];
        if (i == 0)
            break;
    }
    idx_data[idx_info_idx] = si_tbl_idx;
    idx_info->total_num++;
    return SRV_CLOG_RET_OK;
}

#define SRV_CLOG_IDX_ACT


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_filter_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_filter_reset(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;

    /* Base table variables */
    srv_clog_idx_info_struct *idx_base;
    U16 *idx_base_data;

    /* filter table variables */
    srv_clog_idx_info_struct *idx_flt;
    U16 *idx_flt_data;
    srv_clog_log_identity_struct *flt_idt;

    /* SI table variables */
    srv_clog_si_struct *si_log;
    srv_clog_si_tbl_struct *si_tbl = idx_tbl->si_tbl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_idx_reset_info(idx_tbl, info_type);
    idx_base = idx_tbl->idx_info[SRV_CLOG_IDX_INFO_BASE];
    idx_base_data = (U16*) idx_base->data;

    idx_flt = idx_tbl->idx_info[info_type];
    idx_flt_data = idx_flt->data;
    flt_idt = &idx_flt->idt;

    idx_flt->total_num = 0;

    if (srv_clog_idx_is_same_sort(idx_base, idx_flt))
    {
        for (i = 0, j = 0; i < idx_base->total_num; i++)
        {
            si_log = srv_clog_si_index(si_tbl, idx_base_data[i]);
            if (srv_clog_pi_is_ip_sub(flt_idt, SRV_CLOG_SI_GET_P(si_log)))
            {
                idx_flt_data[j] = idx_base_data[i];
                j++;
            }
        }
        idx_flt->total_num = j;
    }
    else
    {
        for (i = 0, j = 0; i < idx_base->total_num; i++)
        {
            si_log = srv_clog_si_index(si_tbl, idx_base_data[i]);
            if (srv_clog_pi_is_ip_sub(flt_idt, SRV_CLOG_SI_GET_P(si_log)))
            {
                srv_clog_idx_add(idx_tbl, info_type, si_log, idx_base_data[i]);
            }
        }
    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_is_same_sort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [?]     
 *  dst     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_is_same_sort(srv_clog_idx_info_struct *src, srv_clog_idx_info_struct *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* No need to check algorithm here because algorithm only affect the sort speed */
    return (src->sort_type == dst->sort_type && src->sort_dir == dst->sort_dir);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_set_idt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 *  idt             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_set_idt(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_idx_info_enum info_type,
            srv_clog_log_identity_struct *idt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_log_identity_struct *dst_idt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dst_idt = &idx_tbl->idx_info[info_type]->idt;
    srv_clog_pi_cp_i(idt, dst_idt);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_level2info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  list_level      [IN]        
 *  idt             [?]         
 *  diff            [?]         
 * RETURNS
 *  
 *****************************************************************************/
static srv_clog_idx_info_enum srv_clog_idx_level2info(
                                srv_clog_idx_tbl_struct *idx_tbl,
                                srv_clog_list_level_enum list_level,
                                srv_clog_log_identity_struct *idt,
                                S32 *diff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rand_sel = MMI_FALSE;
    S32 need_refresh = MMI_FALSE;
    S32 is_support_thread = 0;
    srv_clog_idx_info_enum info_type = SRV_CLOG_IDX_INFO_BASE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //FlowReserved
    //is_support_thread = srv_clog_stl_support_thread(idx_tbl->style_mgr);

    switch (list_level)
    {
        case SRV_CLOG_LIST_LEVEL_DEFAULT:
        case SRV_CLOG_LIST_LEVEL_SORT:
        case SRV_CLOG_LIST_LEVEL_STORE:
            if (!idt)
            {
                info_type = SRV_CLOG_IDX_INFO_BASE;
            }
            else if (srv_clog_pi_is_ii_equal(&idx_tbl->idx_info[SRV_CLOG_IDX_INFO_BASE]->idt, idt))
            {
                info_type = SRV_CLOG_IDX_INFO_BASE;
            }
            else if (!is_support_thread &&
                     srv_clog_pi_is_ii_equal(&idx_tbl->idx_info[SRV_CLOG_IDX_INFO_FILTER_EX]->idt, idt))
            {
                info_type = SRV_CLOG_IDX_INFO_FILTER_EX;
            }
            else if (srv_clog_pi_is_ii_equal(&idx_tbl->idx_info[SRV_CLOG_IDX_INFO_FILTER]->idt, idt))
            {
                info_type = SRV_CLOG_IDX_INFO_FILTER;
            }
            else
            {
                //TO DO: check if category = ALL case, may better to use thread here as thread has max length 
                // and can support special case: such as cate = ALL or log_type = DIALED/MISSED
                //Also check SIM limited number style side effect, each log type can be max size
#if 0 //FlowReserved
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
            
                info_type = SRV_CLOG_IDX_INFO_FILTER_EX;
                need_refresh = MMI_TRUE;
                rand_sel = MMI_TRUE;
            }
            break;

        case SRV_CLOG_LIST_LEVEL_THREAD:
            info_type = SRV_CLOG_IDX_INFO_THREAD;
            SRV_CLOG_ASSERT(0);
            break;

        default:
            SRV_CLOG_ASSERT(0);
            break;
    }

    if (diff)
        *diff = need_refresh;

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_IDX_LEVEL2INFO,
        list_level,
        idt->cate,
        idt->sim_id,
        idt->log_type,
        idt->sub_type,
        info_type,
        need_refresh,
        rand_sel);

    return info_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_lv1_get_ids_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 *  start_idx       [IN]        
 *  log_num         [IN]        
 *  ids             [?]         
 *  ids_size        [?]         
 *  next_idx        [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_idx_lv1_get_ids_by_index(
        srv_clog_idx_tbl_struct *idx_tbl,
        srv_clog_idx_info_enum info_type,
        U32 start_idx,
        U32 log_num,
        SRV_CLOG_ID *ids,
        U32 *ids_size,
        U32 *next_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    U32 total_num;
    srv_clog_idx_info_struct *idx_info;

    /* srv_clog_si_struct **si_list; */
    U16 *idx_list;
    srv_clog_si_tbl_struct *si_tbl = idx_tbl->si_tbl;
    srv_clog_si_struct *si_log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx_info = idx_tbl->idx_info[info_type];
    total_num = idx_info->total_num;
    if (start_idx >= total_num)
        return SRV_CLOG_RET_INVALID_PARAM;
    idx_list = (U16*) idx_info->data;

    for (i = start_idx, j = 0; i < total_num && j < log_num; i++)
    {
        si_log = srv_clog_si_index(si_tbl, idx_list[i]);
        if (!srv_clog_si_is_valid(si_log))
            continue;
        ids[j] = SRV_CLOG_SI_GET_LOG_ID(si_log);
        j++;
    }
    *ids_size = j;
    if (i < total_num)
        *next_idx = i;
    else
        *next_idx = SRV_CLOG_INVALID_ELM;

    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_id2idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 *  log_id          [IN]        
 *  idx_tbl_idx     [?]         
 *  si_tbl_idx      [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_idx_id2idx(
        srv_clog_idx_tbl_struct *idx_tbl,
        srv_clog_idx_info_enum info_type,
        SRV_CLOG_ID log_id,
        U32 *idx_tbl_idx,
        U32 *si_tbl_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 total_num;
    srv_clog_idx_info_struct *idx_info;
    U16 *idx_info_data;
    srv_clog_si_struct **si_tbl_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx_info = idx_tbl->idx_info[info_type];
    if (log_id == SRV_CLOG_INVALID_ELM)
    {
        *idx_tbl_idx = 0;
        if (si_tbl_idx)
            *si_tbl_idx = idx_info->data[0];

        SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_ID2IDX, info_type, log_id, 0, idx_info->data[0]));

        return SRV_CLOG_RET_OK;
    }
/*  FlowReserved  
    if (info_type == SRV_CLOG_IDX_INFO_THREAD && srv_clog_stl_support_thread(idx_tbl->style_mgr))
        total_num = SRV_CLOG_LOG_MAX_NUM;
    else
*/     
        total_num = idx_info->total_num;
    idx_info_data = (U16*) idx_info->data;
    si_tbl_data = (srv_clog_si_struct **) idx_tbl->si_tbl->data;
    for (i = 0; i < total_num; i++)
    {
        if (idx_info_data[i] == SRV_CLOG_IDX_INVALID_IDX)
            continue;

        if (log_id != SRV_CLOG_SI_GET_LOG_ID(si_tbl_data[idx_info_data[i]]))
            continue;
        *idx_tbl_idx = i;
        if (si_tbl_idx)
            *si_tbl_idx = idx_info_data[i];

        MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_ID2IDX, info_type, log_id, i, idx_info_data[i]);

        return SRV_CLOG_RET_OK;
    }
    *idx_tbl_idx = (U32) SRV_CLOG_IDX_INVALID_IDX;  /* Please note SRV_CLOG_IDX_INVALID_IDX is U16 type */
    if (si_tbl_idx)
        *si_tbl_idx = (U32) SRV_CLOG_IDX_INVALID_IDX;

    SRV_CLOG_IT_TRACE((
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_IDX_ID2IDX,
        info_type,
        log_id,
        SRV_CLOG_IDX_INVALID_IDX,
        SRV_CLOG_IDX_INVALID_IDX));

    return SRV_CLOG_RET_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_lv1_get_ids_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 *  start_id        [IN]        
 *  log_num         [IN]        
 *  ids             [?]         
 *  ids_size        [?]         
 *  next_id         [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_idx_lv1_get_ids_by_id(
        srv_clog_idx_tbl_struct *idx_tbl,
        srv_clog_idx_info_enum info_type,
        U32 start_id,
        U32 log_num,
        SRV_CLOG_ID *ids,
        U32 *ids_size,
        SRV_CLOG_ID *next_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 start_idx;
    U32 next_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_idx_id2idx(idx_tbl, info_type, start_id, &start_idx, NULL);
    if (ret != SRV_CLOG_RET_OK)
    {
        *next_id = SRV_CLOG_INVALID_ELM;
        *ids_size = 0;

        SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_LV1_GET_IDS_BY_ID,
            info_type, start_id, -1, log_num, *ids_size, *next_id, -1, ret));

        return SRV_CLOG_RET_NOT_FOUND;
    }
    ret = srv_clog_idx_lv1_get_ids_by_index(idx_tbl, info_type, start_idx, log_num, ids, ids_size, &next_idx);
    if (SRV_CLOG_IS_ELM_INVALID(next_idx))
    {
        *next_id = SRV_CLOG_INVALID_ELM;

        SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_LV1_GET_IDS_BY_ID, 
            info_type, start_id, start_idx, log_num, *ids_size, *next_id, -1, ret));
        return ret;
    }
    *next_id = srv_clog_idx_idx2id(idx_tbl, info_type, next_idx);

    SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_LV1_GET_IDS_BY_ID,
        info_type, start_id, start_idx, log_num, *ids_size, *next_id, next_idx, ret));

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_idx2id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 *  index           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
SRV_CLOG_ID srv_clog_idx_idx2id(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_idx_info_enum info_type, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sit_idx;
    srv_clog_si_struct *si_log;
    SRV_CLOG_ID log_id = SRV_CLOG_INVALID_ELM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= idx_tbl->idx_info[info_type]->total_num)
        return SRV_CLOG_INVALID_ELM;

    sit_idx = idx_tbl->idx_info[info_type]->data[index];
    si_log = srv_clog_si_index(idx_tbl->si_tbl, sit_idx);
    if (srv_clog_si_is_valid(si_log))
        log_id = SRV_CLOG_SI_GET_LOG_ID(si_log);

    SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_IDX2ID, 
        info_type, index, sit_idx, log_id, SRV_CLOG_SI_GET_P(si_log)));
    return log_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_get_list_ids
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 *  req_data        [IN]        
 *  cnf_data        [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_idx_get_list_ids(
        srv_clog_idx_tbl_struct *idx_tbl,
        srv_clog_idx_info_enum info_type,
        const srv_clog_get_list_log_ids_req_struct *req_data,
        srv_clog_get_list_log_ids_cnf_struct *cnf_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_data->start_by == SRV_CLOG_BY_IDX)
    {
        ret = srv_clog_idx_lv1_get_ids_by_index(
                idx_tbl,
                info_type,
                req_data->start_elm,
                req_data->log_num,
                (SRV_CLOG_ID*) cnf_data->log_ids,
                &cnf_data->log_num,
                (U32*) & cnf_data->next_start_elm);
    }
    else
    {
        ret = srv_clog_idx_lv1_get_ids_by_id(
                idx_tbl,
                info_type,
                req_data->start_elm,
                req_data->log_num,
                (SRV_CLOG_ID*) cnf_data->log_ids,
                &cnf_data->log_num,
                (SRV_CLOG_ID*) & cnf_data->next_start_elm);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_refresh
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  level           [IN]        
 *  idt             [?]         
 *  info_type       [?]         
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_ret_enum srv_clog_idx_refresh(
        srv_clog_idx_tbl_struct *idx_tbl,
        srv_clog_list_level_enum level,
        srv_clog_log_identity_struct *idt,
        srv_clog_idx_info_enum *info_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 diff = 0;
    srv_clog_ret_enum ret = SRV_CLOG_RET_OK;
    srv_clog_log_identity_struct *dst_idt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *info_type = srv_clog_idx_level2info(idx_tbl, level, idt, &diff);
    if (diff)
    {
        dst_idt = &idx_tbl->idx_info[*info_type]->idt;
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_IDX_REFRESH,
            level,
            dst_idt->cate,
            dst_idt->sim_id,
            dst_idt->log_type,
            dst_idt->sub_type,
            *info_type,
            diff,
            ret);
        srv_clog_idx_set_idt(idx_tbl, *info_type, idt);
        ret = (srv_clog_ret_enum)srv_clog_idx_reset(idx_tbl, *info_type);
    }
    SRV_CLOG_IT_TRACE((
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_IDX_REFRESH,
        level,
        idt->cate,
        idt->sim_id,
        idt->log_type,
        idt->sub_type,
        *info_type,
        diff,
        ret));

    return ret;
}


#if 0 //APIReserved
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
#endif //0 

/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_get_list_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  level_type       [IN]        
 *  req_data        [?]         
 *  cnf_data        [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_idx_get_list_log(
        srv_clog_idx_tbl_struct *idx_tbl,
        srv_clog_list_level_enum level_type,
        srv_clog_get_list_log_req_struct *req_data,
        srv_clog_get_list_log_cnf_struct *cnf_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_idx_info_enum info_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_data->ret = srv_clog_idx_refresh(idx_tbl, level_type, (srv_clog_log_identity_struct*) cnf_data, &info_type);

    if (cnf_data->ret != SRV_CLOG_RET_OK)
        return cnf_data->ret;

    if (req_data->get_by == SRV_CLOG_BY_ID)
        ret = srv_clog_idx_get_log_by_id(idx_tbl, info_type, req_data->get_elm, req_data->fields, &cnf_data->log);
    else
        ret = srv_clog_idx_get_log_by_idx(idx_tbl, info_type, req_data->get_elm, req_data->fields, &cnf_data->log);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_get_log_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 *  log_id          [IN]        
 *  fields          [IN]        
 *  log             [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_idx_get_log_by_id(
        srv_clog_idx_tbl_struct *idx_tbl,
        srv_clog_idx_info_enum info_type,
        SRV_CLOG_ID log_id,
        U32 fields,
        srv_clog_log_struct *log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    S32 ret;
//    S32 has_thread;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (info_type != SRV_CLOG_IDX_INFO_UNKNOWN)
    {
        return srv_clog_idx_lv1_get_log_by_id(idx_tbl, info_type, log_id, fields, log);
    }
    else
    {
       return srv_clog_idx_lv1_get_log_by_id(idx_tbl, SRV_CLOG_IDX_INFO_BASE, log_id, fields, log);

/* FlowReserved        
        if (ret != SRV_CLOG_RET_NOT_FOUND)
            return ret;

        has_thread = srv_clog_stl_support_thread(idx_tbl->style_mgr);
        if (!has_thread)
            return ret;
        return srv_clog_idx_lv1_get_log_by_id(idx_tbl, SRV_CLOG_IDX_INFO_THREAD, log_id, fields, log);
*/        
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_lv1_get_log_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 *  log_id          [IN]        
 *  fields          [IN]        
 *  log             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_lv1_get_log_by_id(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_idx_info_enum info_type,
            SRV_CLOG_ID log_id,
            U32 fields,
            srv_clog_log_struct *log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    U16 max_size;
    U16 *idx_data;
    U32 last_idx = idx_tbl->last_get_idx + 1;
    srv_clog_si_tbl_struct *si_tbl = idx_tbl->si_tbl;
    srv_clog_si_struct *si_log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    max_size = idx_tbl->idx_info[info_type]->max_size;
    idx_data = (U16*) idx_tbl->idx_info[info_type]->data;

    for (i = 0, j = last_idx; i < max_size; i++, j++)
    {
        if (j == max_size)
            j = 0;
        if (idx_data[j] == SRV_CLOG_IDX_INVALID_IDX)
            continue;
        si_log = srv_clog_si_index(si_tbl, idx_data[j]);
        if (!srv_clog_si_is_valid(si_log))
            continue;
        if (log_id == SRV_CLOG_SI_GET_LOG_ID(si_log))
        {
            idx_tbl->last_get_idx = (U16) j;
            srv_clog_si_log_si2cmn(si_log, fields, log);
            return SRV_CLOG_RET_OK;
        }
    }
    return SRV_CLOG_RET_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_peek_si_by_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 *  idx             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_si_struct *srv_clog_idx_peek_si_by_idx(
                        srv_clog_idx_tbl_struct *idx_tbl,
                        srv_clog_idx_info_enum info_type,
                        U32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_idx_info_struct *idx_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx_info = idx_tbl->idx_info[info_type];
    if (idx >= idx_info->total_num)
        return NULL;
    return idx_tbl->si_tbl->data[idx_info->data[idx]];
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_get_log_by_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]         
 *  info_type       [IN]        
 *  idx             [IN]        
 *  fields          [IN]        
 *  log             [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_idx_get_log_by_idx(
        srv_clog_idx_tbl_struct *idx_tbl,
        srv_clog_idx_info_enum info_type,
        U32 idx,
        U32 fields,
        srv_clog_log_struct *log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_idx_info_struct *idx_info;
    srv_clog_si_struct *si_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx_info = idx_tbl->idx_info[info_type];
    if (idx >= idx_info->total_num)
        return SRV_CLOG_RET_NOT_FOUND;
    si_info = idx_tbl->si_tbl->data[idx_info->data[idx]];
    return srv_clog_si_log_si2cmn(si_info, fields, log);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_get_last_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl     [?]     
 *  idt         [?]     
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_si_struct *srv_clog_idx_get_last_log(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_log_identity_struct *idt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    U32 log_id = SRV_CLOG_INVALID_ELM;
    U32 idx = 0;
    U16 total_num;
    srv_clog_si_struct *sort_info;
    srv_clog_si_struct **si_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    si_list = (srv_clog_si_struct **) idx_tbl->si_tbl->data;
    total_num = idx_tbl->si_tbl->total_num;
    for (i = 0, j = 0; i < SRV_CLOG_LOG_MAX_NUM && j < total_num; i++)
    {
        sort_info = si_list[i];
        if (!srv_clog_si_is_valid(sort_info))
            continue;
        j++;
        if (srv_clog_pi_is_ip_sub(idt, SRV_CLOG_SI_GET_P(sort_info)))
        {
            if (SRV_CLOG_SI_GET_LOG_ID(sort_info) > log_id)
            {
                idx = i;
                log_id = SRV_CLOG_SI_GET_LOG_ID(sort_info);
            }
        }
    }
    if (log_id == SRV_CLOG_INVALID_ELM)
        return NULL;
    return si_list[idx];
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_delete_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl     [?]         
 *  log_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_idx_delete_id(srv_clog_idx_tbl_struct *idx_tbl, SRV_CLOG_ID log_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_idx_lv1_delete_id(idx_tbl, log_id);
    srv_clog_idx_lv2_delete_id(idx_tbl, log_id);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_lv1_delete_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl     [?]         
 *  log_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_lv1_delete_id(srv_clog_idx_tbl_struct *idx_tbl, SRV_CLOG_ID log_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* may need to revise thread info */
    S32 ret;
    U32 idx_tbl_idx;
    U32 si_tbl_idx;
    //srv_clog_si_struct *si_log;
    //U32 total_num;
    //U32 ur_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_idx_id2idx(idx_tbl, SRV_CLOG_IDX_INFO_BASE, log_id, &idx_tbl_idx, &si_tbl_idx);
    if (ret == SRV_CLOG_RET_OK)
    {
/* FlowReserved        
        if (srv_clog_stl_support_thread(idx_tbl->style_mgr))
            srv_clog_idx_tread_delete_index(idx_tbl, SRV_CLOG_IDX_INFO_THREAD, si_tbl_idx);
        else
*/        
            srv_clog_idx_lv1_delete_index(idx_tbl, SRV_CLOG_IDX_INFO_BASE, idx_tbl_idx);
        return SRV_CLOG_RET_OK;
    }

    SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_IDX_LV1_DELETE_ID, log_id, -1, ret));
    return SRV_CLOG_RET_NOT_FOUND;
}


#if 0 //APIReserved
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
#endif //0

/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_lv2_delete_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl     [?]         
 *  log_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_lv2_delete_id(srv_clog_idx_tbl_struct *idx_tbl, SRV_CLOG_ID log_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 idx_tbl_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_idx_id2idx(idx_tbl, SRV_CLOG_IDX_INFO_FILTER, log_id, &idx_tbl_idx, NULL);
    if (ret == SRV_CLOG_RET_OK)
    {
        srv_clog_idx_lv1_delete_index(idx_tbl, SRV_CLOG_IDX_INFO_FILTER, idx_tbl_idx);
    }
//FlowReserved
//    if (!srv_clog_stl_support_thread(idx_tbl->style_mgr))
    {
        ret = srv_clog_idx_id2idx(idx_tbl, SRV_CLOG_IDX_INFO_FILTER_EX, log_id, &idx_tbl_idx, NULL);
        if (ret == SRV_CLOG_RET_OK)
        {
            srv_clog_idx_lv1_delete_index(idx_tbl, SRV_CLOG_IDX_INFO_FILTER_EX, idx_tbl_idx);
        }
    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_lv1_delete_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl             [?]         
 *  info_type           [IN]        
 *  idx_info_idx        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_lv1_delete_index(
            srv_clog_idx_tbl_struct *idx_tbl,
            srv_clog_idx_info_enum info_type,
            U32 idx_info_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 total_num;
    srv_clog_idx_info_struct *idx_info;
    U16 *idx_info_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx_info = idx_tbl->idx_info[info_type];
    idx_info_data = (U16*) idx_info->data;
    total_num = idx_info->total_num;
    if (total_num == 0)
        return SRV_CLOG_RET_OK;

    for (i = idx_info_idx; i < total_num - 1; i++)
    {
        idx_info_data[i] = idx_info_data[i + 1];
    }
    idx_info_data[total_num - 1] = SRV_CLOG_IDX_INVALID_IDX;
    idx_info->total_num--;
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_add_prepare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]     
 *  req_data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_idx_add_prepare(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_job_add_log_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_CLOG_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_idx_check_merge(idx_tbl, req_data);
    req_data->is_full = (U8) srv_clog_idx_check_full(idx_tbl, &req_data->si_log, &req_data->type_idt);

    if (!req_data->need_merge)
    {
        if (req_data->is_full)  /* add but full, find one to delete */
        {
            ret = srv_clog_idx_find_oldest(idx_tbl, req_data);
            SRV_CLOG_ASSERT(ret == SRV_CLOG_RET_OK);
            req_data->best_sit_idx = req_data->old_sit_idx;
        }
        else    /* find slot to add */
        {
            ret = srv_clog_si_find_best_slot(idx_tbl->si_tbl, &req_data->best_sit_idx);
            SRV_CLOG_ASSERT(ret == SRV_CLOG_RET_OK);
        }
    }

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_IDX_ADD_PREPARE_OLD,
        req_data->need_merge,
        req_data->is_full,
        req_data->old_sit_idx,
        req_data->old_log_id,
        req_data->old_props,
        req_data->old_idxi_idx,
        req_data->old_info_type);
    
    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_IDX_ADD_PREPARE_NEW,
        req_data->best_sit_idx,
        req_data->type_idt.cate,
        req_data->type_idt.sim_id,
        req_data->type_idt.log_type,
        req_data->type_idt.sub_type,
        SRV_CLOG_SI_GET_LOG_ID(&req_data->si_log),
        SRV_CLOG_SI_GET_P(&req_data->si_log),
        req_data->ret);

    return ret;
}

/* to check if need merge, merge to which one, if add to new slot */


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_check_merge
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]     
 *  req_data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_check_merge(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_job_add_log_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 ret;
    srv_clog_idx_info_struct *idx_info;
    U16 *idx_info_data;
    U32 total_num;
    srv_clog_si_tbl_struct *si_tbl = idx_tbl->si_tbl;
    srv_clog_si_struct *si_log;
    U32 merge_style;
    U32 match_props = 0;
    U32 log_total_num;
    U32 log_ur_num;
    srv_clog_idx_info_enum info_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_stl_get_style(idx_tbl->style_mgr, SRV_CLOG_STYLE_TYPE_MERGE, &merge_style, NULL);
    req_data->sup_merge = (merge_style == 0 ? 0 : 1);
    req_data->sup_thread = 0;

//  FlowReserved    
//    req_data->sup_thread = SRV_CLOG_CHECK_BIT(merge_style, SRV_CLOG_STYLE_MERGE_THREAD);

    if (!req_data->sup_merge || req_data->sup_thread)
        req_data->need_merge = MMI_FALSE;
    if (!req_data->sup_merge)
        return SRV_CLOG_RET_OK;

    /* continue to find which existing one should be merged */

    info_type = SRV_CLOG_IDX_INFO_BASE;
    SRV_CLOG_IDX_GET_ELM(idx_tbl, info_type, idx_info, idx_info_data, total_num);

#if 0 //FlowReserved
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0

    if (SRV_CLOG_CHECK_BIT(merge_style, SRV_CLOG_STYLE_MERGE_IN_CATE))
        match_props |= SRV_CLOG_LSP_CATE;
    if (SRV_CLOG_CHECK_BIT(merge_style, SRV_CLOG_STYLE_MERGE_IN_SIM_ID))
        match_props |= SRV_CLOG_LSP_SIM_ID;
    if (SRV_CLOG_CHECK_BIT(merge_style, SRV_CLOG_STYLE_MERGE_IN_LOG_TYPE))
        match_props |= SRV_CLOG_LSP_CATE | SRV_CLOG_LSP_LT;
    if (SRV_CLOG_CHECK_BIT(merge_style, SRV_CLOG_STYLE_MERGE_IN_SUB_TYPE))
        match_props |= SRV_CLOG_LSP_CATE | SRV_CLOG_LSP_LT | SRV_CLOG_LSP_ST;

    for (i = 0; i < total_num; i++)
    {
        si_log = srv_clog_si_index(si_tbl, idx_info_data[i]);
        /* If the scope not matched just skip it */
        if (!SRV_CLOG_PI_PP_CMP(SRV_CLOG_SI_GET_P(&req_data->si_log), SRV_CLOG_SI_GET_P(si_log), match_props))
            continue;

        ret = srv_clog_si_check_merge(&req_data->si_log, si_log, merge_style);
        if (ret)    /* can merge */
        {
            req_data->old_log_id = SRV_CLOG_SI_GET_LOG_ID(si_log);
            req_data->old_props = SRV_CLOG_SI_GET_P(si_log);
            req_data->old_sit_idx = idx_info_data[i];
            req_data->old_info_type = info_type;
            req_data->old_idxi_idx = i;
            if (!req_data->sup_thread)
            {
                req_data->best_sit_idx = req_data->old_sit_idx;
                req_data->need_merge = MMI_TRUE;    /* should replace this one. */
                srv_clog_si_get_num(si_log, &log_total_num, &log_ur_num);
                srv_clog_si_update_num(&req_data->si_log, log_total_num, log_ur_num, MMI_TRUE);
            }
            break;
        }
        else    /* if (diff_type > 0) //current not matched, should stop because need to check type and type changed. */
        {
            if (SRV_CLOG_CHECK_BIT(merge_style, SRV_CLOG_STYLE_MERGE_CONSECUTIVE))
            {
                /* not same, stop */
                req_data->need_merge = MMI_FALSE;
                break;
            }
        }
    }
    if (i == total_num) /* not find any one to replace or merge */
    {
        req_data->need_merge = MMI_FALSE;
    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_check_full
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]     
 *  si_log          [?]     
 *  type_idt        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static srv_clog_full_enum srv_clog_idx_check_full(
                            srv_clog_idx_tbl_struct *idx_tbl,
                            srv_clog_si_struct *si_log,
                            srv_clog_log_identity_struct *type_idt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 num_style;
    U32 type_limit = 0;
    srv_clog_num_info_struct num_info;
    srv_clog_full_enum full_type = SRV_CLOG_FULL_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx_tbl->si_tbl->total_num == SRV_CLOG_LOG_MAX_NUM)
        full_type = SRV_CLOG_FULL_SLOT;

    if (idx_tbl->idx_info[SRV_CLOG_IDX_INFO_BASE]->total_num == SRV_CLOG_LOG_MAX_NUM)
        full_type = SRV_CLOG_FULL_BASE;

    /* Check if limited by log type or by SIM id, not support by call type yet which is so complex to end user */
    srv_clog_stl_get_style(idx_tbl->style_mgr, SRV_CLOG_STYLE_TYPE_NUM, &num_style, NULL);
    if (SRV_CLOG_CHECK_BIT(num_style, SRV_CLOG_STYLE_NUM_TYPE_LIMITED | SRV_CLOG_STYLE_NUM_SIM_LIMITED))
    {
        type_limit = srv_clog_pi_get_num_limit_by_p(num_style, SRV_CLOG_SI_GET_P(si_log), type_idt);
        srv_clog_idx_get_num_info(idx_tbl, /* SRV_CLOG_LIST_LEVEL_STORE, */ type_idt, &num_info);
        if (type_limit <= num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS])
            full_type = SRV_CLOG_FULL_TYPE;
    }

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_IDX_CHECK_FULL,
        num_style,
        SRV_CLOG_SI_GET_P(si_log),
        type_limit,
        num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS],
        full_type);

    return full_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_find_oldest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]     
 *  req_data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_find_oldest(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_job_add_log_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_CLOG_RET_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (req_data->is_full)
    {
        case SRV_CLOG_FULL_NONE:
            break;

        case SRV_CLOG_FULL_SLOT:
        case SRV_CLOG_FULL_BASE:
            ret = srv_clog_idx_base_get_oldest(idx_tbl, req_data);
            break;

        case SRV_CLOG_FULL_TYPE:
            ret = srv_clog_idx_base_get_oldest_by_i(idx_tbl, req_data);
            break;

        default:
            break;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_base_get_oldest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]     
 *  req_data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_base_get_oldest(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_job_add_log_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 total_num;
    srv_clog_si_struct *si_log;
    srv_clog_idx_info_struct *idx_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_data->old_info_type = SRV_CLOG_IDX_INFO_BASE;
    idx_info = idx_tbl->idx_info[SRV_CLOG_IDX_INFO_BASE];
    total_num = idx_info->total_num;

//FlowReserved
//    if (idx_info->sort_type == SRV_CLOG_SORT_BY_LOG_ID || idx_info->sort_type == SRV_CLOG_SORT_BY_TIMESTAMP)
    {
        req_data->old_idxi_idx = total_num - 1;
    
/* FlowReserved
        if (idx_info->sort_dir == SRV_CLOG_DIRECTION_DESCENDING ||
            idx_info->sort_dir == SRV_CLOG_DIRECTOIN_UNCLASSIFIED)
        {
            req_data->old_idxi_idx = total_num - 1;
        }
        else if (idx_info->sort_dir == SRV_CLOG_DIRECTION_ASCENDING)
        {
            req_data->old_idxi_idx = 0;
        }
        else
        {
            SRV_CLOG_ASSERT(0);
        }
*/        
        req_data->old_sit_idx = idx_info->data[req_data->old_idxi_idx];
        si_log = srv_clog_si_index(idx_tbl->si_tbl, req_data->old_sit_idx);
        req_data->old_log_id = SRV_CLOG_SI_GET_LOG_ID(si_log);
        req_data->old_props = SRV_CLOG_SI_GET_P(si_log);
        return SRV_CLOG_RET_OK;
    }
    /* Search idx_base and find the oldest log */
//    return SRV_CLOG_RET_NOT_SUPPORT;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_base_get_oldest_by_i
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]     
 *  req_data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_idx_base_get_oldest_by_i(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_job_add_log_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_clog_idx_info_struct *idx_info;
    U16 *idx_info_data;
    U32 total_num;
    srv_clog_si_struct *si_log;
    srv_clog_si_tbl_struct *si_tbl = idx_tbl->si_tbl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_data->old_info_type = SRV_CLOG_IDX_INFO_BASE;
    idx_info = idx_tbl->idx_info[SRV_CLOG_IDX_INFO_BASE];
    idx_info_data = (U16*) idx_info->data;
    total_num = idx_info->total_num;

//FlowReserved
//    if (idx_info->sort_type == SRV_CLOG_SORT_BY_LOG_ID || idx_info->sort_type == SRV_CLOG_SORT_BY_TIMESTAMP)
    {
/* FlowReserved
        if (idx_info->sort_dir == SRV_CLOG_DIRECTION_DESCENDING ||
            idx_info->sort_dir == SRV_CLOG_DIRECTOIN_UNCLASSIFIED)
*/            
        {
            for (i = total_num - 1; i != 0; i--)
            {
                si_log = srv_clog_si_index(si_tbl, idx_info_data[i]);
                if (srv_clog_pi_is_ip_sub(&req_data->type_idt, SRV_CLOG_SI_GET_P(si_log)))
                {
                    req_data->old_idxi_idx = i;
                    req_data->old_sit_idx = idx_info->data[i];
                    req_data->old_log_id = SRV_CLOG_SI_GET_LOG_ID(si_log);
                    req_data->old_props = SRV_CLOG_SI_GET_P(si_log);
                    break;
                }
            }
            if (i == total_num)
                return SRV_CLOG_RET_NOT_FOUND;
            return SRV_CLOG_RET_OK;
        }
    }
//    return SRV_CLOG_RET_NOT_SUPPORT;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_add_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl         [?]     
 *  req_data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_idx_add_update(srv_clog_idx_tbl_struct *idx_tbl, srv_clog_job_add_log_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U32 total_num;
    //U32 ur_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_idx_add(idx_tbl, SRV_CLOG_IDX_INFO_BASE, &req_data->si_log, req_data->best_sit_idx);
    srv_clog_idx_reset_l2(idx_tbl);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_idx_search_ids_by_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_tbl             [?]         
 *  info_type           [IN]        
 *  req_data            [?]         
 *  cnf_data            [?]         
 *  idx_start_idx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_idx_search_ids_by_idx(
        srv_clog_idx_tbl_struct *idx_tbl,
        srv_clog_idx_info_enum info_type,
        srv_clog_search_list_log_ids_req_struct *req_data,
        srv_clog_search_list_log_ids_cnf_struct *cnf_data,
        U32 idx_start_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    U32 total_num;
    U16 *idx_tbl_data;
    SRV_CLOG_ID log_id;
    U32 find_last = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_num = srv_clog_idx_total_num(idx_tbl, info_type, NULL);
    idx_tbl_data = (U16*) ((idx_tbl->idx_info[info_type])->data);
    for (i = idx_start_idx, j = 0; i < total_num; i++)
    {
        if (srv_clog_si_check_match(idx_tbl->si_tbl, idx_tbl_data[i], req_data, &log_id))
        {
            if (j <= SRV_CLOG_LOG_ID_LIST_MAX_NUM)
                cnf_data->log_ids[j] = log_id;
            j++;            
            if (j > SRV_CLOG_LOG_ID_LIST_MAX_NUM)
            {
                j--;
                find_last = 1;
                break;
            }
        }
    }
    if (find_last)
    {
        if (req_data->start_by == SRV_CLOG_BY_IDX)
            cnf_data->next_elm = i;
        else
            cnf_data->next_elm = log_id;
    }
    else
    {
        cnf_data->next_elm = SRV_CLOG_INVALID_ELM;
    }
    cnf_data->id_num = j;
    cnf_data->ret = SRV_CLOG_RET_OK;
    return SRV_CLOG_RET_OK;
}

#endif /* __MMI_TELEPHONY_SUPPORT__ */
