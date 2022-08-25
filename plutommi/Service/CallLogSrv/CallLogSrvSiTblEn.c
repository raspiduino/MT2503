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
*  CallLogSrvSiTblEn.c
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
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "mmi_include.h"

#include "string.h"

#include "kal_general_types.h"
#include "kal_trace.h"

#include "custom_voip_config.h"
#include "custom_phb_config.h"
#include "custom_calllog.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"

#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "Unicodexdcl.h"

#include "PhbSrvGprot.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvStore.h"
#include "CallLogSrvComp.h"
#include "CallLogSrvProt.h"

/*----------------------------------------------------------------------------*/
/* Micro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/

/*---------------------- SI Table Operation ----------------------------------*/
static void srv_clog_si_log_reset(srv_clog_si_struct *si_log);
static S32 srv_clog_si_tbl_add_index(srv_clog_si_tbl_struct *si_tbl, U32 index, srv_clog_st_log_struct *st_log);



/*----------------------------------------------------------------------------*/
/* Extern Function Declaration                                                */
/*----------------------------------------------------------------------------*/

#define SRV_CLOG_SI_BASE
/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_type        [IN]        
 *  st_mgr          [?]         
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_si_tbl_struct *srv_clog_si_tbl_create(U32 mem_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_clog_si_tbl_struct *si_tbl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    si_tbl = SRV_CLOG_TALLOC(mem_type, srv_clog_si_tbl_struct);
    
    for (i = 0; i < SRV_CLOG_LOG_MAX_NUM; i++)
    {
        si_tbl->data[i] = SRV_CLOG_TALLOC(mem_type, srv_clog_si_struct);
        srv_clog_si_log_reset(si_tbl->data[i]);
    }
    si_tbl->total_num = 0;
    si_tbl->last_add_idx = 0;

    return si_tbl;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_log      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_si_log_reset(srv_clog_si_struct *si_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (si_log)
        memset(si_log, 0x0, sizeof(srv_clog_si_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_total_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_tbl      [?]     
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_clog_si_tbl_total_num(srv_clog_si_tbl_struct *si_tbl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return si_tbl->total_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_is_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sort_info       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_si_log_is_valid(srv_clog_si_struct *sort_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* may be empty */
    if (!sort_info)
        return MMI_FALSE;

    if (SRV_CLOG_IS_ELM_INVALID(SRV_CLOG_SILOG_GET_LOG_ID(sort_info)))
        return MMI_FALSE;

    if (SRV_CLOG_CHECK_BIT(SRV_CLOG_SILOG_GET_TYPE_ID(sort_info), SRV_CLOG_TDP_DELETED))
        return MMI_FALSE;

    return MMI_TRUE;
}

/* no use?? */


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_tbl      [?]         
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_si_struct *srv_clog_si_tbl_index(srv_clog_si_tbl_struct *si_tbl, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* better to defined a macro for quickly access */
    SRV_CLOG_ASSERT(index < SRV_CLOG_LOG_MAX_NUM);
    return si_tbl->data[index];
}


#define SRV_CLOG_SI_GET
/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_get_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sort_info       [?]     
 *  total_num       [?]     
 *  unread_num      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_si_log_get_num(srv_clog_si_struct *sort_info, U32 *total_num, U32 *unread_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (total_num)
       *total_num = SRV_CLOG_SILOG_GET_TOTALNUM(sort_info);
    if (unread_num)
      *unread_num = SRV_CLOG_SILOG_GET_UNREADNUM(sort_info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_update_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sort_info       [?]         
 *  ext_tt_num      [IN]        
 *  ext_ur_num      [IN]        
 *  is_add          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_si_log_update_num(srv_clog_si_struct *sort_info, U32 ext_tt_num, U32 ext_ur_num, S32 is_add)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 new_tt_num;
    U32 new_ur_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_si_log_get_num(sort_info, &new_tt_num, &new_ur_num);
    if (is_add)
    {
        new_tt_num += ext_tt_num;
        new_ur_num += ext_ur_num;

        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_SI_UPDATE_NUM_LIMIT,
            SRV_CLOG_SILOG_GET_LOG_ID(sort_info),
            ext_tt_num,
            ext_ur_num,
            is_add,
            new_tt_num,
            new_ur_num);

        if (new_tt_num > 0xFF)      new_tt_num = 0xFF;
        if (new_ur_num > 0xFF)      new_ur_num = 0xFF;
    }
    else
    {
        SRV_CLOG_ASSERT(new_tt_num >= ext_tt_num && new_ur_num >= ext_ur_num);
        new_tt_num -= ext_tt_num;
        new_ur_num -= ext_ur_num;
    }

    SRV_CLOG_SILOG_SET_TOTALNUM(sort_info, new_tt_num);
    SRV_CLOG_SILOG_SET_UNREADNUM(sort_info, new_ur_num);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_get_cid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_info     [?]     
 * RETURNS
 *  
 *****************************************************************************/
CHAR *srv_clog_si_log_get_cid(srv_clog_si_struct *si_info, CHAR *call_number, U32 max_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_convert_to_digit_ex(call_number, si_info->cid, max_len/*SRV_CLOG_CID_MAX_LEN*/, MMI_FALSE);
    return call_number;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_get_max_log_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_tbl      [?]     
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_clog_si_tbl_get_max_log_id(srv_clog_si_tbl_struct *si_tbl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    U32 total_num;
    U32 max_log_id = 0;
    U32 max_id_idx = 0;
    U32 cur_log_id;
    srv_clog_si_struct **info_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_num = si_tbl->total_num;
    info_list = (srv_clog_si_struct **) si_tbl->data;

    for (i = 0, j = 0; i < SRV_CLOG_LOG_MAX_NUM; i++)
    {
        if (j == total_num)
            break;
        if (!info_list[i])
            continue;
        cur_log_id = SRV_CLOG_SILOG_GET_LOG_ID(info_list[i]);
        if (SRV_CLOG_IS_ELM_INVALID(cur_log_id))
            continue;
        if (cur_log_id > max_log_id)
        {
            max_log_id = cur_log_id;
            max_id_idx = i;
        }
        j++;
    }
    si_tbl->last_add_idx = max_id_idx;
    return srv_clog_revise_log_id(max_log_id);
}


#define SRV_CLOG_SI_BASE_ACT
/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_parse
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_tbl          [?]         
 *  start_idx       [IN]        
 *  st_logs         [?]         
 *  log_num         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_si_tbl_parse(srv_clog_si_tbl_struct *si_tbl, U32 start_idx, srv_clog_st_log_struct *st_logs, U32 log_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ASSERT(start_idx + log_num <= SRV_CLOG_LOG_MAX_NUM);

    for (i = 0; i < log_num; i++)
    {
        if (!srv_clog_st_log_valid(&st_logs[i]))
            continue;
        if (!SRV_CLOG_CHECK_BIT(SRV_CLOG_SILOG_GET_TYPE_ID(&st_logs[i]), SRV_CLOG_TSP_CLT_ALL))
            continue;
        srv_clog_si_tbl_add_index(si_tbl, start_idx + i, &st_logs[i]);
    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_add_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_tbl      [?]         
 *  index       [IN]        
 *  st_log      [?]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_si_tbl_add_index(srv_clog_si_tbl_struct *si_tbl, U32 index, srv_clog_st_log_struct *st_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!si_tbl || index >= SRV_CLOG_LOG_MAX_NUM || !st_log)
        return SRV_CLOG_RET_INVALID_PARAM;

    memcpy(si_tbl->data[index], st_log, sizeof(srv_clog_st_log_struct));

#ifndef __MMI_CLOG_PHB_SYNC_SUPPORT__
    SRV_CLOG_SET_INVALID_PHB_ID(SRV_CLOG_SILOG_GET_PHB_ID(si_tbl->data[index]));
#endif
    si_tbl->total_num++;

    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_delete_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_tbl      [?]         
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_si_tbl_delete_index(srv_clog_si_tbl_struct *si_tbl, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!si_tbl || index >= SRV_CLOG_LOG_MAX_NUM)
        return SRV_CLOG_RET_INVALID_PARAM;

    if (!srv_clog_si_log_is_valid(si_tbl->data[index]))
        return SRV_CLOG_RET_NOT_FOUND;

    srv_clog_si_log_reset(si_tbl->data[index]);
    si_tbl->total_num--;

    if (si_tbl->last_add_idx == index)
    {
        for (i = 0, j = index - 1; i < SRV_CLOG_LOG_MAX_NUM; i++, j--)
        {
            if (j < 0)
                j = SRV_CLOG_LOG_MAX_NUM - 1;

            if (srv_clog_si_log_is_valid(si_tbl->data[j]))
            {
                si_tbl->last_add_idx = j;
                break;
            }
        }

        if (i == SRV_CLOG_LOG_MAX_NUM)
            si_tbl->last_add_idx = 0;
    }

    return SRV_CLOG_RET_OK;
}


#define SRV_CLOG_SI_TRANSFORM
/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_id2idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_tbl      [?]         
 *  log_id      [IN]        
 *  idx         [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_si_tbl_id2idx(srv_clog_si_tbl_struct *si_tbl, SRV_CLOG_ID log_id, U32 *idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_clog_si_struct **info_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info_list = (srv_clog_si_struct **) si_tbl->data;
    for (i = 0; i < SRV_CLOG_LOG_MAX_NUM; i++)
    {
        if (!srv_clog_si_log_is_valid(info_list[i]))
            continue;
        if (SRV_CLOG_SILOG_GET_LOG_ID(info_list[i]) != log_id)
            continue;
        *idx = i;
        return SRV_CLOG_RET_OK;
    }
    return SRV_CLOG_RET_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_log_si2cmn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sort_info       [?]         
 *  fields          [IN]        
 *  log             [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_si_log_si2cmn(srv_clog_si_struct *sort_info, U32 fields, srv_clog_log_struct *log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_clog_call_log_struct *call_log;
    kal_uint8 call_number[SRV_CLOG_CID_MAX_LEN + 1];
    WCHAR phb_num[SRV_CLOG_CID_MAX_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(log, 0x0, sizeof(srv_clog_log_struct));
    log->cate = SRV_CLOG_CATE_CALL;     // only support call log now

    if (!srv_clog_si_log_is_valid(sort_info))
        return SRV_CLOG_RET_EMPTY;
    if (fields == 0)
        fields = SRV_CLOG_LOG_FIELD_ALL;

    call_log = &log->data.call_log;
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_IDENTITY))
    {
        call_log->cate = SRV_CLOG_CATE_CALL;
        call_log->sim_id = SRV_CLOG_PI_P2IDX(SRV_CLOG_SILOG_GET_TYPE_ID(sort_info), SRV_CLOG_TSP_SIM_ID_GRP, SRV_CLOG_TSP_SIM_ID_POS)+1;
        call_log->log_type = SRV_CLOG_PI_P2IDX(SRV_CLOG_SILOG_GET_TYPE_ID(sort_info), SRV_CLOG_TSP_CLT_GRP, SRV_CLOG_TSP_CLT_POS);
        call_log->sub_type = SRV_CLOG_CALL_TYPE_VOICE;
    }
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_LOG_ID))
    {
        call_log->log_id = SRV_CLOG_SILOG_GET_LOG_ID(sort_info);
    }
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_TIMESTAMP))
    {
        memcpy(call_log->timestamp, sort_info->timestamp, sizeof(sort_info->timestamp[0]) * SRV_CLOG_TIME_DETAIL_MAX_NUM);
    }
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_DURATION))
    {
        for (i = 0; i < SRV_CLOG_TIME_DETAIL_MAX_NUM; i++)
            call_log->duration[i] = sort_info->duration[i];
    }
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_TOTAL_NUM))
    {
        call_log->total_num = SRV_CLOG_SILOG_GET_TOTALNUM(sort_info);
    }
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_UNREAD_NUM))
    {
        call_log->unread_num = SRV_CLOG_SILOG_GET_UNREADNUM(sort_info);
    }
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_IS_NEW_EVENT))
    {
        call_log->is_new_event = SRV_CLOG_PI_P2IDX(SRV_CLOG_SILOG_GET_TYPE_ID(sort_info), SRV_CLOG_TDP_NEW_EVENT_GRP, SRV_CLOG_TDP_NEW_EVENT_POS);
    }

    srv_clog_si_log_get_cid(sort_info, call_number, SRV_CLOG_CID_MAX_LEN);
    if ( SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_PHB_ID) )
    {
    #ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
        /* Check if cid is same when phb_id is same, if both same, get name from phb, if not, the phb number may be damaged abnormally,
            in some abnormally case, the cid is different even phb_id is same,
            such as insert the sim card in another target and modify the phb number and then insert back to this target,
            the phb entry may be changed greatly even with same phb_id, if so, just show the name saved in calllog,
            temp solution for this special case */
        MMI_BOOL ret2;
        WCHAR log_num[SRV_CLOG_CID_MAX_LEN + 1];
        
        ret2 = srv_phb_get_number_by_number_id(phb_num, SRV_CLOG_SILOG_GET_PHB_ID(sort_info), SRV_CLOG_CID_MAX_LEN);

        if (ret2)
        {
            mmi_asc_n_to_ucs2((CHAR *)log_num, call_number, SRV_CLOG_CID_MAX_LEN);
            /* PHB_ID is same, if number is same too, we will use contact's name, else
                PHB_ID is same, but number is diff, we will set NULL to log name and set invalid PHB_ID to log */
            if (srv_phb_compare_number(phb_num, log_num))
                srv_phb_get_name_by_number_id(call_log->name, SRV_CLOG_SILOG_GET_PHB_ID(sort_info), SRV_CLOG_NAME_MAX_LEN);
            else
            {
                /* TODO: save it to NVRAM? */
                SRV_CLOG_SET_INVALID_PHB_ID(sort_info->phb_id);
            }
        }

        if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_PHB_ID))
            call_log->phb_id = SRV_CLOG_SILOG_GET_PHB_ID(sort_info);
    #else /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */
        mmi_asc_n_to_wcs(phb_num, (CHAR*)call_number,  SRV_CLOG_CID_MAX_LEN);
        srv_phb_get_name_by_number(phb_num, call_log->name, SRV_CLOG_NAME_MAX_LEN);
    #endif /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */
    }
    
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_CID))
    {
        mmi_asc_to_ucs2((CHAR*) call_log->cid, (CHAR*) call_number);
    }
    
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_log_cmn2si_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cmn_log         [?]     
 *  sort_info       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_si_log_cmn2si(srv_clog_log_struct *cmn_log, srv_clog_si_struct *sort_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_call_log_struct *cmn_call;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmn_call = &cmn_log->data.call_log;

    SRV_CLOG_SILOG_SET_TOTALNUM(sort_info, cmn_call->total_num);
    SRV_CLOG_SILOG_SET_UNREADNUM(sort_info, cmn_call->unread_num);

    srv_clog_pi_revise_i((srv_clog_log_identity_struct*) cmn_call, MMI_FALSE);
    SRV_CLOG_PI_IDX2P(sort_info->type_id, cmn_call->log_type, SRV_CLOG_TSP_CLT_POS);
    SRV_CLOG_PI_IDX2P(sort_info->type_id, srv_clog_ib_bit2idx(cmn_call->sim_id), SRV_CLOG_TSP_SIM_ID_POS);

    SRV_CLOG_SILOG_SET_LOG_ID(sort_info, cmn_call->log_id);
    SRV_CLOG_SILOG_SET_PHB_ID(sort_info, cmn_call->phb_id);
    
    sort_info->timestamp[SRV_CLOG_LASTEST_TIME_IDX] = cmn_call->timestamp[SRV_CLOG_LASTEST_TIME_IDX];
    sort_info->duration[SRV_CLOG_LASTEST_TIME_IDX] = cmn_call->duration[SRV_CLOG_LASTEST_TIME_IDX];

    if (cmn_call->is_new_event)
        SRV_CLOG_SET_BIT(SRV_CLOG_SILOG_GET_TYPE_ID(sort_info), SRV_CLOG_TDP_NEW_EVENT);
    else
        SRV_CLOG_CLEAR_BIT(SRV_CLOG_SILOG_GET_TYPE_ID(sort_info), SRV_CLOG_TDP_NEW_EVENT);

    srv_clog_wcs_n_to_BCD(sort_info->cid, (WCHAR*) cmn_call->cid, SRV_CLOG_CID_MAX_LEN * ENCODING_LENGTH);

    return SRV_CLOG_RET_OK;

}


#define SRV_CLOG_SI_UPDATE
/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_find_best_slot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_tbl      [?]     
 *  si_idx      [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_si_tbl_find_best_slot(srv_clog_si_tbl_struct *si_tbl, U32 *si_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    srv_clog_si_struct **si_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (si_tbl->total_num)
        j = si_tbl->last_add_idx + 1;
    else
        j = si_tbl->last_add_idx;

    si_list = (srv_clog_si_struct **) si_tbl->data;
    for (i = 0; i < SRV_CLOG_LOG_MAX_NUM; i++, j++)
    {
        if (j == SRV_CLOG_LOG_MAX_NUM)
            j = 0;
        if (srv_clog_si_log_is_valid(si_list[j]))
            continue;
        *si_idx = j;
        return SRV_CLOG_RET_OK;
    }
    return SRV_CLOG_RET_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_check_merge
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src             [?]         
 *  dst             [?]         
 *  merge_style     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_si_log_check_merge(srv_clog_si_struct *src, srv_clog_si_struct *dst, U32 merge_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 src_cid[SRV_CLOG_CID_MAX_LEN + 1];
    kal_uint8 dst_cid[SRV_CLOG_CID_MAX_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(merge_style,
            SRV_CLOG_STYLE_MERGE_BY_PHB_ID | SRV_CLOG_STYLE_MERGE_BY_NUM | SRV_CLOG_STYLE_MERGE_BY_NAME))
        return MMI_FALSE;

    srv_clog_si_log_get_cid(src, src_cid, SRV_CLOG_CID_MAX_LEN);
    srv_clog_si_log_get_cid(dst, dst_cid, SRV_CLOG_CID_MAX_LEN);

    if (SRV_CLOG_CHECK_BIT(merge_style, SRV_CLOG_STYLE_MERGE_BY_PHB_ID))
    {
        if (!SRV_CLOG_IS_PHB_ID_VALID(SRV_CLOG_SILOG_GET_PHB_ID(src)) &&
            !SRV_CLOG_IS_PHB_ID_VALID(SRV_CLOG_SILOG_GET_PHB_ID(dst)))
        {
            /* If no saved in Phone book and both has valid number*/
            if (src_cid && dst_cid)
            {
                SRV_CLOG_SET_BIT(merge_style, SRV_CLOG_STYLE_MERGE_BY_NUM);
            }
            else if (!src_cid && !dst_cid) /* If both have no number */
            {
                SRV_CLOG_SET_BIT(merge_style, SRV_CLOG_STYLE_MERGE_BY_NAME);
            }
        }
        else    /* At least one has PHB ID */
        {
            if (!(SRV_CLOG_IS_SAME_PHB_ID(SRV_CLOG_SILOG_GET_PHB_ID(src), SRV_CLOG_SILOG_GET_PHB_ID(dst))))
                return MMI_FALSE;
            else  //TODO: review
                SRV_CLOG_SET_BIT(merge_style, SRV_CLOG_STYLE_MERGE_BY_NUM);
        }
    }

    /* If check number */
    if (SRV_CLOG_CHECK_BIT(merge_style, SRV_CLOG_STYLE_MERGE_BY_NUM))
    {
        /* If both are empty string */
        if (SRV_CLOG_IS_STR_EMPTY(src_cid) && SRV_CLOG_IS_STR_EMPTY(dst_cid))
        {
            SRV_CLOG_SET_BIT(merge_style, SRV_CLOG_STYLE_MERGE_BY_NAME);
        }
        else if (MMI_FALSE == srv_clog_comp_asc_cid(src_cid, dst_cid))
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_add_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_tbl          [?]     
 *  req_data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_si_tbl_add_update(srv_clog_si_tbl_struct *si_tbl, srv_clog_add_log_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(si_tbl->data[req_data->best_sit_idx], &req_data->si_log, sizeof(srv_clog_si_struct));
    si_tbl->total_num += 1;
    si_tbl->last_add_idx = req_data->best_sit_idx;  /* remember the index of the last one to add. */
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_update_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_log      [?]         
 *  cmn_log     [?]         
 *  fields      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_si_log_update_log(srv_clog_si_struct *si_log, srv_clog_log_struct *cmn_log, U32 fields)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_call_log_struct *call_log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    call_log = (srv_clog_call_log_struct*) (&cmn_log->data.call_log);
    
    if (fields == 0)
        fields = SRV_CLOG_LOG_FIELD_ALL;

    srv_clog_si_update_phb_info(si_log, fields, call_log->phb_id, call_log->cid);
    
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_TIMESTAMP))
    {
        si_log->timestamp[SRV_CLOG_LASTEST_TIME_IDX] = call_log->timestamp[SRV_CLOG_LASTEST_TIME_IDX];
    }
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_DURATION))
    {
        si_log->duration[SRV_CLOG_LASTEST_TIME_IDX] = call_log->duration[SRV_CLOG_LASTEST_TIME_IDX];
    }
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_TOTAL_NUM))
    {
        SRV_CLOG_SILOG_SET_TOTALNUM(si_log, call_log->total_num);
    }
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_UNREAD_NUM))
    {
        SRV_CLOG_SILOG_SET_UNREADNUM(si_log, call_log->unread_num);
    }
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_IS_NEW_EVENT))
    {
        if (call_log->is_new_event)
            SRV_CLOG_SET_BIT(SRV_CLOG_SILOG_GET_TYPE_ID(si_log), SRV_CLOG_TDP_NEW_EVENT);
        else
            SRV_CLOG_CLEAR_BIT(SRV_CLOG_SILOG_GET_TYPE_ID(si_log), SRV_CLOG_TDP_NEW_EVENT);
    }

    return SRV_CLOG_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_update_cmn_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_log          [?]     
 *  req_data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_si_log_update_cmn_info(srv_clog_si_struct *si_log, srv_clog_update_all_logs_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK(!SRV_CLOG_CHECK_BIT(req_data->req_fields, SRV_CLOG_LOG_FIELD_UNREAD_NUM | SRV_CLOG_LOG_FIELD_IS_NEW_EVENT), SRV_CLOG_RET_NOT_SUPPORT);

    if (SRV_CLOG_CHECK_BIT(req_data->req_fields, SRV_CLOG_LOG_FIELD_UNREAD_NUM))
    {
        SRV_CLOG_SILOG_SET_UNREADNUM(si_log, 0);
    }
    if (SRV_CLOG_CHECK_BIT(req_data->req_fields, SRV_CLOG_LOG_FIELD_IS_NEW_EVENT))
    {
        SRV_CLOG_CLEAR_BIT(SRV_CLOG_SILOG_GET_TYPE_ID(si_log), SRV_CLOG_TDP_NEW_EVENT);
    }

    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_check_match
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_tbl          [?]         
 *  sit_idx         [IN]        
 *  req_data        [?]         
 *  log_id          [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_si_log_check_match(
        srv_clog_si_tbl_struct *si_tbl,
        U32 sit_idx,
        srv_clog_search_list_log_ids_req_struct *req_data,
        SRV_CLOG_ID *log_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    SRV_PHB_ID phb_id;
    U16 phb_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_CLOG_CHECK_BIT(req_data->search_fields, SRV_CLOG_LOG_FIELD_PHB_IDXS))
    {
        phb_id = SRV_CLOG_SILOG_GET_PHB_ID(si_tbl->data[sit_idx]);
        phb_idx = SRV_CLOG_PHB_ID2IDX(phb_id);
        for (i = 0; i < req_data->phb_idx_num; i++)
        {
            if (req_data->phb_idx[i] == phb_idx)
                break;
        }
        if (i == req_data->phb_idx_num)
            return MMI_FALSE;
        *log_id = SRV_CLOG_SILOG_GET_LOG_ID(si_tbl->data[sit_idx]);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


#define SRV_CLOG_SI_PHB_SYNC
#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_flash
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_tbl          [?]     
 *  start_idx       [?]     
 *  saved_num       [?]     
 *  faied_num       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_si_flash(srv_clog_si_tbl_struct *si_tbl, U32 start_idx, U32 end_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 ret;
    srv_clog_si_struct *si_log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (start_idx >= SRV_CLOG_LOG_MAX_NUM)
        return SRV_CLOG_RET_OK;

    for (i = start_idx; i < end_idx; i++)
    {
        si_log = si_tbl->data[i];

        if (!srv_clog_si_log_is_valid(si_log))
            continue;

        if (SRV_CLOG_CHECK_BIT(SRV_CLOG_SILOG_GET_TYPE_ID(si_log), SRV_CLOG_TDP_DELETED))
            memset(si_log, 0x0, sizeof(srv_clog_st_log_struct));
    }

    ret = srv_clog_st_write_logs(start_idx, end_idx+1, &(si_tbl->data[0]));

    return SRV_CLOG_RET_OK;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_update_phb_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_log      [?]         
 *  fields      [IN]        
 *  phb_id      [IN]        
 *  name        [?]        name can be NULL 
 *  cid         [?]        cid can be NULL 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_si_update_phb_info(srv_clog_si_struct *si_log, U32 fields, SRV_PHB_ID phb_id, WCHAR *cid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_PHB_ID))
    {
        SRV_CLOG_SILOG_SET_PHB_ID(si_log, phb_id);
    }
    
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_CID))
    {
        if (SRV_CLOG_IS_STR_EMPTY(cid))
            SRV_CLOG_SET_STR_EMPTY(si_log->cid);
        else
            srv_clog_wcs_n_to_BCD(si_log->cid, (WCHAR*) cid, SRV_CLOG_CID_MAX_LEN * ENCODING_LENGTH);
    }
}

