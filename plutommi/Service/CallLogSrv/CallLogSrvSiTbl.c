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
*  CallLogSrvSiTbl.c
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
static void srv_clog_si_reset(srv_clog_si_struct *si_log);

static S32 srv_clog_si_add_index(srv_clog_si_tbl_struct *si_tbl, U32 index, srv_clog_st_log_struct *st_log);
static S32 srv_clog_si_set_st_by_index(srv_clog_si_tbl_struct *si_tbl, U32 index, srv_clog_st_log_struct *st_log);
static S32 srv_clog_si_log_si2cmn_call(srv_clog_si_struct *sort_info, U32 fields, srv_clog_log_struct *log);

static S32 srv_clog_si_log_cmn2si_call(srv_clog_log_struct *cmn_log, srv_clog_si_struct *sort_info);

#if 0//APIReserved
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0

static S32 srv_clog_si_update_call_cmn_info(
            srv_clog_call_info_struct *call_info,
            srv_clog_update_all_logs_req_struct *req_data);

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
srv_clog_si_tbl_struct *srv_clog_si_create(U32 mem_type)
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
        srv_clog_si_reset(si_tbl->data[i]);
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
static void srv_clog_si_reset(srv_clog_si_struct *si_log)
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
 *  srv_clog_si_clear
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_tbl      [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_si_clear(srv_clog_si_tbl_struct *si_tbl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    si_tbl->total_num = 0;
    si_tbl->last_add_idx = 0;
    for (i = 0; i < SRV_CLOG_LOG_MAX_NUM; i++)
    {
        srv_clog_si_reset(si_tbl->data[i]);
    }
    return SRV_CLOG_RET_OK;
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
U32 srv_clog_si_total_num(srv_clog_si_tbl_struct *si_tbl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return si_tbl->total_num;
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
#endif //0

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
S32 srv_clog_si_is_valid(srv_clog_si_struct *sort_info)
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
    if (SRV_CLOG_IS_ELM_INVALID(SRV_CLOG_SI_GET_LOG_ID(sort_info)))
        return MMI_FALSE;

    if (SRV_CLOG_CHECK_BIT(SRV_CLOG_SI_GET_P(sort_info), SRV_CLOG_LDP_DELETED))
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
srv_clog_si_struct *srv_clog_si_index(srv_clog_si_tbl_struct *si_tbl, U32 index)
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
 *  srv_clog_si_get_log_total_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sort_info       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_clog_si_get_log_total_num(srv_clog_si_struct *sort_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 total_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_si_get_num(sort_info, &total_num, NULL);
    return total_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_get_log_unread_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sort_info       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_clog_si_get_log_unread_num(srv_clog_si_struct *sort_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 unread_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_si_get_num(sort_info, NULL, &unread_num);
    return unread_num;
}


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
void srv_clog_si_get_num(srv_clog_si_struct *sort_info, U32 *total_num, U32 *unread_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_call_info_struct *call_info = (srv_clog_call_info_struct*)sort_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (total_num)
       *total_num = SRV_CLOG_PI_GET_TNUM(SRV_CLOG_SI_GET_P(sort_info), call_info->total_num);
    if (unread_num)
      *unread_num = SRV_CLOG_PI_GET_URNUM(SRV_CLOG_SI_GET_P(sort_info), call_info->unread_num);
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
void srv_clog_si_update_num(srv_clog_si_struct *sort_info, U32 ext_tt_num, U32 ext_ur_num, S32 is_add)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 new_tt_num;
    U32 new_ur_num;
    srv_clog_call_info_struct *call_info = (srv_clog_call_info_struct*)sort_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_si_get_num(sort_info, &new_tt_num, &new_ur_num);
    if (is_add)
    {
        new_tt_num += ext_tt_num;
        new_ur_num += ext_ur_num;

        if (new_tt_num > SRV_CLOG_PI_GET_TNUM(SRV_CLOG_LSP_TOTAL_NUM, 0xFF))
        {
            MMI_TRACE(
                SRV_CLOG_TRC_INFO,
                TRC_SRV_CLOG_SI_UPDATE_NUM_LIMIT,
                SRV_CLOG_SI_GET_LOG_ID(sort_info),
                ext_tt_num,
                ext_ur_num,
                is_add,
                new_tt_num,
                new_ur_num);

            new_tt_num = SRV_CLOG_PI_GET_TNUM(SRV_CLOG_LSP_TOTAL_NUM, 0xFF);
        }
        if (new_ur_num > SRV_CLOG_PI_GET_URNUM(SRV_CLOG_LSP_UNREAD_NUM, 0xFF))
        {
            MMI_TRACE(
                SRV_CLOG_TRC_INFO,
                TRC_SRV_CLOG_SI_UPDATE_NUM_LIMIT,
                SRV_CLOG_SI_GET_LOG_ID(sort_info),
                ext_tt_num,
                ext_ur_num,
                is_add,
                new_tt_num,
                new_ur_num);
            new_ur_num = SRV_CLOG_PI_GET_URNUM(SRV_CLOG_LSP_UNREAD_NUM, 0xFF);
        }
    }
    else
    {
        SRV_CLOG_ASSERT(new_tt_num >= ext_tt_num && new_ur_num >= ext_ur_num);
        new_tt_num -= ext_tt_num;
        new_ur_num -= ext_ur_num;
    }

    SRV_CLOG_CLEAR_BIT(SRV_CLOG_SI_GET_P(sort_info), SRV_CLOG_LSP_TOTAL_NUM);
    SRV_CLOG_CLEAR_BIT(SRV_CLOG_SI_GET_P(sort_info), SRV_CLOG_LSP_UNREAD_NUM);
    SRV_CLOG_PI_SET_TNUM(SRV_CLOG_SI_GET_P(sort_info), call_info->total_num, new_tt_num);
    SRV_CLOG_PI_SET_URNUM(SRV_CLOG_SI_GET_P(sort_info), call_info->unread_num, new_ur_num);
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
CHAR *srv_clog_si_get_cid(srv_clog_si_struct *si_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (CHAR*) (((srv_clog_call_info_struct*) si_info)->cid);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_get_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_info     [?]     
 * RETURNS
 *  
 *****************************************************************************/
WCHAR *srv_clog_si_get_name(srv_clog_si_struct *si_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLOG_SLIM__ //SlimName   
    return NULL;
#else
    return ((srv_clog_call_info_struct*) si_info)->name;
#endif
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
U32 srv_clog_si_get_max_log_id(srv_clog_si_tbl_struct *si_tbl)
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
        cur_log_id = SRV_CLOG_SI_GET_LOG_ID(info_list[i]);
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
S32 srv_clog_si_parse(srv_clog_si_tbl_struct *si_tbl, U32 start_idx, srv_clog_st_log_struct *st_logs, U32 log_num)
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
        if (!srv_clog_pi_is_p_support(st_logs[i].base_log.props))
            continue;
        srv_clog_si_add_index(si_tbl, start_idx + i, &st_logs[i]);
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
static S32 srv_clog_si_add_index(srv_clog_si_tbl_struct *si_tbl, U32 index, srv_clog_st_log_struct *st_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!si_tbl || index >= SRV_CLOG_LOG_MAX_NUM)
        return SRV_CLOG_RET_INVALID_PARAM;

    ret = srv_clog_si_set_st_by_index(si_tbl, index, st_log);
    if (ret == SRV_CLOG_RET_OK)
    {
#ifndef __MMI_CLOG_PHB_SYNC_SUPPORT__
        SRV_CLOG_SET_INVALID_PHB_ID(SRV_CLOG_SI_GET_PHB_ID(si_tbl->data[index]));
#endif
        si_tbl->total_num++;
    }
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
S32 srv_clog_si_delete_index(srv_clog_si_tbl_struct *si_tbl, U32 index)
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

    if (!srv_clog_si_is_valid(si_tbl->data[index]))
        return SRV_CLOG_RET_NOT_FOUND;
    srv_clog_si_reset(si_tbl->data[index]);
    si_tbl->total_num--;

    if (si_tbl->last_add_idx == index)
    {
        for (i = 0, j = index - 1; i < SRV_CLOG_LOG_MAX_NUM; i++, j--)
        {
            if (j < 0)
                j = SRV_CLOG_LOG_MAX_NUM - 1;

            if (srv_clog_si_is_valid(si_tbl->data[j]))
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


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_set_st_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_tbl      [?]         
 *  index       [IN]        
 *  st_log      [?]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_si_set_st_by_index(srv_clog_si_tbl_struct *si_tbl, U32 index, srv_clog_st_log_struct *st_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!si_tbl || index >= SRV_CLOG_LOG_MAX_NUM || !st_log)
        return SRV_CLOG_RET_INVALID_PARAM;

    srv_clog_si_st2si(st_log, si_tbl->data[index]);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_set_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_tbl      [?]         
 *  index       [IN]        
 *  si_log      [?]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_si_set_index(srv_clog_si_tbl_struct *si_tbl, U32 index, srv_clog_si_struct *si_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(si_tbl->data[index], si_log, sizeof(srv_clog_si_struct));
    return SRV_CLOG_RET_OK;
}

#define SRV_CLOG_SI_TRANSFORM


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_st2si
 * DESCRIPTION
 *  
 * PARAMETERS
 *  st_log      [?]     
 *  si_log      [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_si_st2si(srv_clog_st_log_struct *st_log, srv_clog_si_struct *si_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__MMI_CLOG_SLIM__) && !defined(__MMI_VOIP__))
    srv_clog_st_call_log_struct *st_call_log = (srv_clog_st_call_log_struct*)st_log;

    memcpy((srv_clog_base_info_struct*)si_log, (srv_clog_base_info_struct*)st_log, sizeof(srv_clog_base_info_struct)); 
    /* this BCD code comes from NVRAM, not from SIM card */
    srv_phb_convert_to_digit_ex(si_log->cid, ((srv_clog_call_info_struct*)st_log)->cid,  SRV_CLOG_CID_MAX_LEN, MMI_FALSE);
    
    memcpy(si_log->duration, st_call_log->duration, sizeof(si_log->duration[0]) * SRV_CLOG_TIME_DETAIL_MAX_NUM);
    si_log->total_num = st_call_log->total_num;
    si_log->unread_num = st_call_log->unread_num;
    return SRV_CLOG_RET_OK;

#else  /* (defined(__MMI_CLOG_SLIM__) && !defined(__MMI_VOIP__)) */
    
    SRV_CLOG_ASSERT(sizeof(srv_clog_st_log_struct) == sizeof(srv_clog_si_struct));
    memcpy(si_log, st_log, sizeof(srv_clog_st_log_struct));
    return SRV_CLOG_RET_OK;
    
#endif /* (defined(__MMI_CLOG_SLIM__) && !defined(__MMI_VOIP__)) */
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_si2st
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_log      [?]     
 *  st_log      [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_si_si2st(srv_clog_si_struct *si_log, srv_clog_st_log_struct *st_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__MMI_CLOG_SLIM__) && !defined(__MMI_VOIP__))
    srv_clog_st_call_log_struct *st_call_log = (srv_clog_st_call_log_struct*)st_log;

    memset(st_log, 0x0, sizeof(srv_clog_st_log_struct));

    memcpy((srv_clog_base_info_struct*)st_log, (srv_clog_base_info_struct*)si_log, sizeof(srv_clog_base_info_struct));   
    srv_phb_convert_to_bcd(st_call_log->cid, si_log->cid,  NVRAM_CLOG_CID_BCD_MAX_LEN);

    memcpy(st_call_log->duration, si_log->duration, sizeof(si_log->duration[0]) * SRV_CLOG_TIME_DETAIL_MAX_NUM);
    st_call_log->total_num = si_log->total_num;
    st_call_log->unread_num = si_log->unread_num;
    return SRV_CLOG_RET_OK;

#else  /* (defined(__MMI_CLOG_SLIM__) && !defined(__MMI_VOIP__)) */

    SRV_CLOG_ASSERT(sizeof(srv_clog_st_log_struct) == sizeof(srv_clog_si_struct));
    
    memcpy(st_log, si_log, sizeof(srv_clog_st_log_struct));
    SRV_CLOG_CLEAR_BIT(st_log->base_log.props, SRV_CLOG_LDP_GRP);
    return SRV_CLOG_RET_OK;
    
#endif /* (defined(__MMI_CLOG_SLIM__) && !defined(__MMI_VOIP__)) */

}


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
S32 srv_clog_si_id2idx(srv_clog_si_tbl_struct *si_tbl, SRV_CLOG_ID log_id, U32 *idx)
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
        if (!srv_clog_si_is_valid(info_list[i]))
            continue;
        if (SRV_CLOG_SI_GET_LOG_ID(info_list[i]) != log_id)
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
    U8 cate_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(log, 0x0, sizeof(srv_clog_log_struct));
    cate_idx = SRV_CLOG_PI_P2IDX(sort_info->base_log.props, SRV_CLOG_LSP_CATE, SRV_CLOG_LSP_CATE_POS);
    log->cate = SRV_CLOG_IDX2BIT(cate_idx);
    
    return srv_clog_si_log_si2cmn_call(sort_info, fields, log);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_log_si2cmn_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sort_info       [?]         
 *  fields          [IN]        
 *  log             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_si_log_si2cmn_call(srv_clog_si_struct *sort_info, U32 fields, srv_clog_log_struct *log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_clog_call_log_struct *call_log;
    srv_clog_call_info_struct *call_info;
    WCHAR phb_num[SRV_CLOG_CID_MAX_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_clog_si_is_valid(sort_info))
        return SRV_CLOG_RET_EMPTY;
    if (fields == 0)
        fields = SRV_CLOG_LOG_FIELD_ALL;

    SRV_CLOG_ASSERT(log->cate == SRV_CLOG_CATE_CALL);
    call_log = &log->data.call_log;
    call_info = (srv_clog_call_info_struct*) sort_info;

    call_log->log_id = call_info->log_id;

    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_IDENTITY))
        srv_clog_pi_p2i(call_info->props, (srv_clog_log_identity_struct*) call_log);

    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_LOG_ID))
        call_log->log_id = call_info->log_id;

    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_TIMESTAMP))
        memcpy(call_log->timestamp, call_info->timestamp, sizeof(call_info->timestamp[0]) * SRV_CLOG_TIME_DETAIL_MAX_NUM);

    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_DURATION))
        //call_log->duration[SRV_CLOG_LASTEST_TIME_IDX] = SRV_CLOG_PI_GET_DUR(call_info->props, call_info->duration[SRV_CLOG_LASTEST_TIME_IDX]);
    {
        for (i = 0; i < SRV_CLOG_TIME_DETAIL_MAX_NUM; i++)
            call_log->duration[i] = call_info->duration[i];
    }

    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_TOTAL_NUM))
        call_log->total_num = SRV_CLOG_PI_GET_TNUM(call_info->props, call_info->total_num);

    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_UNREAD_NUM))
        call_log->unread_num = SRV_CLOG_PI_GET_URNUM(call_info->props, call_info->unread_num);

    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_IS_PRIVATE_CID))
        call_log->is_private_cid = SRV_CLOG_CHECK_BIT(call_info->props, SRV_CLOG_LSP_CID_IS_PRIVATE);

    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_IS_NEW_EVENT))
        call_log->is_new_event = SRV_CLOG_CHECK_BIT(call_info->props, SRV_CLOG_LSP_NEW_EVENT);

    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_NAME) || SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_PHB_ID))
    {
#ifdef __MMI_CLOG_SLIM__ //SlimName

#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__

           /* Check if cid is same when phb_id is same, if both same, get name from phb, if not, the phb number may be damaged abnormally,
               in some abnormally case, the cid is different even phb_id is same,
               such as insert the sim card in another target and modify the phb number and then insert back to this target,
               the phb entry may be changed greatly even with same phb_id, if so, just show the name saved in calllog,
               temp solution for this special case */
            MMI_BOOL ret2;
            WCHAR log_num[SRV_CLOG_CID_MAX_LEN + 1];

            ret2 = srv_phb_get_number_by_number_id(phb_num, SRV_CLOG_SI_GET_PHB_ID(sort_info), SRV_CLOG_CID_MAX_LEN);
            if (ret2)
            {
                mmi_asc_n_to_ucs2((CHAR *)log_num, SRV_CLOG_SI_GET_CID(sort_info), SRV_CLOG_CID_MAX_LEN);
                /* PHB_ID is same, if number is same too, we will use contact's name, else
                   PHB_ID is same, but number is diff, we will set NULL to log name and set invalid PHB_ID to log */
                if (srv_phb_compare_number(phb_num, log_num))
                    srv_phb_get_name_by_number_id(call_log->name, SRV_CLOG_SI_GET_PHB_ID(sort_info), SRV_CLOG_NAME_MAX_LEN);
                else
                {
                    /* TODO: save it to NVRAM? */
                    SRV_CLOG_SET_INVALID_PHB_ID(call_info->phb_id);
                }
            }

        if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_PHB_ID))
            call_log->phb_id = call_info->phb_id;

#else /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */

        mmi_asc_n_to_wcs(phb_num, (CHAR*)call_info->cid,  SRV_CLOG_CID_MAX_LEN);
        srv_phb_get_name_by_number(phb_num, call_log->name, SRV_CLOG_NAME_MAX_LEN);
#endif /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */

#else /* __MMI_CLOG_SLIM__ */

        MMI_BOOL ret = MMI_FALSE;

        /* Should make sure the PHB_ID in si_log is set right always */
        if (SRV_CLOG_IS_PHB_ID_VALID(SRV_CLOG_SI_GET_PHB_ID(sort_info)))
        {
            /* Check if cid is same when phb_id is same, if both same, get name from phb, if not, the phb number may be damaged abnormally,
               in some abnormally case, the cid is different even phb_id is same,
               such as insert the sim card in another target and modify the phb number and then insert back to this target,
               the phb entry may be changed greatly even with same phb_id, if so, just show the name saved in calllog,
               temp solution for this special case */
            MMI_BOOL ret2;
            WCHAR log_num[SRV_CLOG_CID_MAX_LEN + 1];

            ret2 = srv_phb_get_number_by_number_id(phb_num, SRV_CLOG_SI_GET_PHB_ID(sort_info), SRV_CLOG_CID_MAX_LEN);
            if (ret2)
            {
                mmi_asc_n_to_ucs2((CHAR *)log_num, SRV_CLOG_SI_GET_CID(sort_info), SRV_CLOG_CID_MAX_LEN);
                /* PHB_ID is same, if number is same too, we will use contact's name, else
                   PHB_ID is same, but number is diff, we will set NULL to log name and set invalid PHB_ID to log */
                if (srv_phb_compare_number(phb_num, log_num))
                    ret = srv_phb_get_name_by_number_id(call_log->name, SRV_CLOG_SI_GET_PHB_ID(sort_info), SRV_CLOG_NAME_MAX_LEN);
                else
                {
                    /* TODO: save it to NVRAM? */
                    call_info->name[0] = 0;
                    SRV_CLOG_SET_INVALID_PHB_ID(call_info->phb_id);
                }
            }
        }
        if (!ret)
            mmi_wcscpy(call_log->name, call_info->name);

        if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_PHB_ID))
            call_log->phb_id = call_info->phb_id;

#endif /* __MMI_CLOG_SLIM__ */
    }
    
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_CID))
        mmi_asc_to_ucs2((CHAR*) call_log->cid, (CHAR*) call_info->cid);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_log_cmn2si
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_clog_si_log_cmn2si_call(cmn_log, sort_info);
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
static S32 srv_clog_si_log_cmn2si_call(srv_clog_log_struct *cmn_log, srv_clog_si_struct *sort_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_call_log_struct *cmn_call;
    srv_clog_call_info_struct *call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmn_call = &cmn_log->data.call_log;
    call_info = (srv_clog_call_info_struct*) sort_info;

    srv_clog_pi_revise_i((srv_clog_log_identity_struct*) cmn_call, MMI_FALSE);
    srv_clog_pi_i2p((srv_clog_log_identity_struct*) cmn_call, &call_info->props);
    call_info->log_id = cmn_call->log_id;
    call_info->phb_id = cmn_call->phb_id;
    if (SRV_CLOG_IS_PHB_ID_VALID(call_info->phb_id))
        SRV_CLOG_SET_BIT(call_info->props, SRV_CLOG_LSP_HAS_PHB_ID);
    call_info->timestamp[SRV_CLOG_LASTEST_TIME_IDX] = cmn_call->timestamp[SRV_CLOG_LASTEST_TIME_IDX];
    SRV_CLOG_PI_SET_DUR(call_info->props, call_info->duration[SRV_CLOG_LASTEST_TIME_IDX], cmn_call->duration[SRV_CLOG_LASTEST_TIME_IDX]);
    
    SRV_CLOG_PI_SET_TNUM(call_info->props, call_info->total_num, cmn_call->total_num);
    SRV_CLOG_PI_SET_URNUM(call_info->props, call_info->unread_num, cmn_call->unread_num);
    if (cmn_call->is_new_event)
        SRV_CLOG_SET_BIT(call_info->props, SRV_CLOG_LSP_NEW_EVENT);
    else
        SRV_CLOG_CLEAR_BIT(call_info->props, SRV_CLOG_LSP_NEW_EVENT);
    SRV_CLOG_PI_IDX2P(call_info->props, SRV_CLOG_IF_TRUE(cmn_call->is_private_cid), SRV_CLOG_LSP_CID_POS);

#ifndef __MMI_CLOG_SLIM__  //SlimName  
    mmi_wcscpy((WCHAR*) call_info->name, (const WCHAR*)cmn_call->name);
#endif

    mmi_wcs_n_to_asc((CHAR*) call_info->cid, cmn_call->cid, SRV_CLOG_CID_MAX_LEN * ENCODING_LENGTH);
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
S32 srv_clog_si_find_best_slot(srv_clog_si_tbl_struct *si_tbl, U32 *si_idx)
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
        if (srv_clog_si_is_valid(si_list[j]))
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
S32 srv_clog_si_check_merge(srv_clog_si_struct *src, srv_clog_si_struct *dst, U32 merge_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *src_cid; 
    CHAR *dst_cid;
    WCHAR *src_name;
    WCHAR *dst_name;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(
            merge_style,
            SRV_CLOG_STYLE_MERGE_BY_PHB_ID | SRV_CLOG_STYLE_MERGE_BY_NUM | SRV_CLOG_STYLE_MERGE_BY_NAME))
        return MMI_FALSE;

    src_cid = SRV_CLOG_SI_GET_CID(src);
    dst_cid = SRV_CLOG_SI_GET_CID(dst);


    if (SRV_CLOG_CHECK_BIT(merge_style, SRV_CLOG_STYLE_MERGE_BY_PHB_ID))
    {
        if (!SRV_CLOG_IS_PHB_ID_VALID(SRV_CLOG_SI_GET_PHB_ID(src)) &&
            !SRV_CLOG_IS_PHB_ID_VALID(SRV_CLOG_SI_GET_PHB_ID(dst)))
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
            if (!(SRV_CLOG_IS_SAME_PHB_ID(SRV_CLOG_SI_GET_PHB_ID(src), SRV_CLOG_SI_GET_PHB_ID(dst))))
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

    /* If check name */
    if (SRV_CLOG_CHECK_BIT(merge_style, SRV_CLOG_STYLE_MERGE_BY_NAME))
    {
        src_name = SRV_CLOG_SI_GET_NAME(src);
        dst_name = SRV_CLOG_SI_GET_NAME(dst);

        if (src_name && dst_name)
        {
            if (0 != mmi_wcscmp((const WCHAR*)src_name, (const WCHAR*)dst_name))
            {
                return MMI_FALSE;
            }
        }
        else if (!src_name && !dst_name)
        {
            /* do nothing */
        }
        else
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
S32 srv_clog_si_add_update(srv_clog_si_tbl_struct *si_tbl, srv_clog_job_add_log_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_si_set_index(si_tbl, req_data->best_sit_idx, &req_data->si_log);
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
S32 srv_clog_si_update_log(srv_clog_si_struct *si_log, srv_clog_log_struct *cmn_log, U32 fields)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_call_info_struct* call_info;
    srv_clog_call_log_struct *call_log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    call_log = (srv_clog_call_log_struct*) (&cmn_log->data.call_log);
    call_info = (srv_clog_call_info_struct*)si_log;

    
    if (fields == 0)
        fields = SRV_CLOG_LOG_FIELD_ALL;

    srv_clog_si_update_phb_info(si_log, fields, call_log->phb_id, call_log->name, call_log->cid);
    
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_TIMESTAMP))
    {
        call_info->timestamp[SRV_CLOG_LASTEST_TIME_IDX] = call_log->timestamp[SRV_CLOG_LASTEST_TIME_IDX];
    }
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_DURATION))
    {
        SRV_CLOG_PI_SET_DUR(call_info->props, call_info->duration[SRV_CLOG_LASTEST_TIME_IDX], call_log->duration[SRV_CLOG_LASTEST_TIME_IDX]);
    }
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_TOTAL_NUM))
    {
        SRV_CLOG_PI_SET_TNUM(call_info->props, call_info->total_num, call_log->total_num);
    }
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_UNREAD_NUM))
    {
        SRV_CLOG_PI_SET_URNUM(call_info->props, call_info->unread_num, call_log->unread_num);
    }

    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_IS_NEW_EVENT))
    {
        if (call_log->is_new_event)
            SRV_CLOG_SET_BIT(call_info->props, SRV_CLOG_LSP_NEW_EVENT);
        else
            SRV_CLOG_CLEAR_BIT(call_info->props, SRV_CLOG_LSP_NEW_EVENT);
    }

    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_IS_PRIVATE_CID))
    {
        SRV_CLOG_CLEAR_BIT(call_info->props, SRV_CLOG_LSP_CID_IS_PRIVATE);
        SRV_CLOG_SET_BIT(call_info->props, call_log->is_private_cid);
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
S32 srv_clog_si_update_cmn_info(srv_clog_si_struct *si_log, srv_clog_update_all_logs_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_clog_si_update_call_cmn_info((srv_clog_call_info_struct*) si_log, req_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_si_update_call_cmn_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  call_info       [?]     
 *  req_data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_si_update_call_cmn_info(
            srv_clog_call_info_struct *call_info,
            srv_clog_update_all_logs_req_struct *req_data)
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
        SRV_CLOG_PI_SET_URNUM(call_info->props, call_info->unread_num, 0);
    }
    if (SRV_CLOG_CHECK_BIT(req_data->req_fields, SRV_CLOG_LOG_FIELD_IS_NEW_EVENT))
    {
        SRV_CLOG_CLEAR_BIT(call_info->props, SRV_CLOG_LSP_NEW_EVENT);
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
S32 srv_clog_si_check_match(
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
        phb_id = SRV_CLOG_SI_GET_PHB_ID(si_tbl->data[sit_idx]);
        phb_idx = SRV_CLOG_PHB_ID2IDX(phb_id);
        for (i = 0; i < req_data->phb_idx_num; i++)
        {
            if (req_data->phb_idx[i] == phb_idx)
                break;
        }
        if (i == req_data->phb_idx_num)
            return MMI_FALSE;
        *log_id = SRV_CLOG_SI_GET_LOG_ID(si_tbl->data[sit_idx]);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

#define SRV_CLOG_SI_PHB_SYNC


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
S32 srv_clog_si_flash(srv_clog_si_tbl_struct *si_tbl, U32 *start_idx, U32 *saved_num, U32 *faied_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 ret;
    U32 new_saved = 0;
    U32 new_failed = 0;
    srv_clog_si_struct *si_log;
    srv_clog_st_log_struct *st_log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*start_idx >= SRV_CLOG_LOG_MAX_NUM)
        return SRV_CLOG_RET_OK;
    st_log = SRV_CLOG_TALLOC(SRV_CLOG_MEM_TYPE_CTRL_BUF, srv_clog_st_log_struct);
    for (i = *start_idx; i < SRV_CLOG_LOG_MAX_NUM; i++)
    {
        si_log = si_tbl->data[i];
        if (!srv_clog_si_is_valid(si_log))
            continue;
        if (!SRV_CLOG_CHECK_BIT(SRV_CLOG_SI_GET_P(si_log), SRV_CLOG_LDP_DIRTY | SRV_CLOG_LDP_DELETED))
            continue;
        if (SRV_CLOG_CHECK_BIT(SRV_CLOG_SI_GET_P(si_log), SRV_CLOG_LDP_DELETED))
            memset(st_log, 0x0, sizeof(srv_clog_st_log_struct));
        else
            srv_clog_si_si2st(si_log, st_log);
        ret = srv_clog_st_write_log(i, st_log);
        if (ret == SRV_CLOG_RET_OK)
        {
            SRV_CLOG_CLEAR_BIT(SRV_CLOG_SI_GET_P(si_log), SRV_CLOG_LDP_DIRTY | SRV_CLOG_LDP_DELETED);
            new_saved++;
        }
        else
        {
            new_failed++;
        }
        if (new_saved + new_failed >= SRV_CLOG_ST_SINGLE_OP_MAX_NUM)
        {
            i++;
            break;
        }
    }
    SRV_CLOG_MFREE(SRV_CLOG_MEM_TYPE_CTRL_BUF, st_log);
    *start_idx = i; /* next start index */
    *saved_num = new_saved;
    *faied_num = new_failed;
    return SRV_CLOG_RET_OK;
}


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
void srv_clog_si_update_phb_info(srv_clog_si_struct *si_log, U32 fields, SRV_PHB_ID phb_id, WCHAR *name, WCHAR *cid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_log_cmn_head_struct *head;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    head = (srv_clog_log_cmn_head_struct*) si_log;

    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_PHB_ID))
    {
        si_log->base_log.phb_id = phb_id;
        if (!SRV_CLOG_IS_PHB_ID_VALID(phb_id))
            SRV_CLOG_CLEAR_BIT(SRV_CLOG_SI_GET_P(si_log), SRV_CLOG_LSP_HAS_PHB_ID);
        else
            SRV_CLOG_SET_BIT(SRV_CLOG_SI_GET_P(si_log), SRV_CLOG_LSP_HAS_PHB_ID);
    }
    
#ifndef __MMI_CLOG_SLIM__  //SlimName  

    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_NAME))
    {
        if (SRV_CLOG_IS_STR_EMPTY(name))
            SRV_CLOG_SET_STR_EMPTY(head->name);
        else
            mmi_wcscpy((WCHAR*) head->name, (const WCHAR*)name);      /* we keep same length with PHB */
    }

#endif /* __MMI_CLOG_SLIM__ */    

    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_LOG_FIELD_CID))
    {
        if (SRV_CLOG_IS_STR_EMPTY(cid))
            SRV_CLOG_SET_STR_EMPTY(head->cid);
        else
            mmi_wcs_n_to_asc((CHAR*) head->cid, (WCHAR*) cid, SRV_CLOG_CID_MAX_LEN * ENCODING_LENGTH);
    }
}

#endif /* __MMI_TELEPHONY_SUPPORT__ */
