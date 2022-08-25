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
*  CallLogSrvComp.c
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
#include "mmi_include.h"

#ifdef __MMI_TELEPHONY_SUPPORT__
#include "string.h"

#include "kal_general_types.h"
#include "kal_trace.h"
#include "lcd_cqueue.h"

#include "custom_calllog.h"
#include "nvram_common_defs.h"

#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvStore.h"
#include "CallLogSrvComp.h"
#include "CallLogSrvProt.h"

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
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

/* Component initialization */
static void srv_clog_comp_reset(srv_clog_comp_struct *comp);

/* Job manager */
static srv_clog_job_mgr_struct *srv_clog_job_create(U32 mem_type, U32 max_job_num);

static srv_clog_job_struct *srv_clog_job_new(srv_clog_job_mgr_struct *job_mgr, srv_clog_job_type_enum type);

static srv_clog_job_mgr_struct *srv_clog_job_create_from_mem(void *mem_data, U32 mem_size, U32 max_job_num);
static void srv_clog_job_free_para(srv_clog_job_struct *job, U32 is_free_req);
static S32 srv_clog_job_add_head(srv_clog_job_mgr_struct *job_mgr, srv_clog_job_struct *job);

static srv_clog_job_struct *srv_clog_job_reuse(
                                srv_clog_job_mgr_struct *job_mgr,
                                srv_clog_job_struct *job,
                                srv_clog_job_type_enum new_type);

static void srv_clog_job_reset(srv_clog_job_struct *job);
static S32 srv_clog_job_cancel(srv_clog_job_struct *job);

static S32 srv_clog_stl_is_bit_style(U32 type, U32 *grp);


/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

#define SRV_CLOG_COMP_COMP


/*****************************************************************************
 * FUNCTION
 *  srv_clog_comp_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_type        [IN]        
 *  cntx            [?]         
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_comp_struct *srv_clog_comp_create(U32 mem_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_comp_struct *comp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    comp = SRV_CLOG_TALLOC(mem_type, srv_clog_comp_struct);
    srv_clog_comp_reset(comp);
    
    return comp;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_cur_comp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]         
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_comp_struct *srv_clog_get_cur_comp(srv_clog_cntx_struct *cntx, SRV_CLOG_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle)
        return (SRV_CLOG_INST(handle))->comp;
    return cntx->comp;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_comp_destroy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  comp        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_comp_destroy(srv_clog_comp_struct *comp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_MFREE(SRV_CLOG_MEM_TYPE_SYS, comp);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_comp_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  comp        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_comp_reset(srv_clog_comp_struct *comp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    comp->job_mgr = NULL;
    comp->style_mgr = NULL;
    comp->si_tbl = NULL;
    comp->idx_tbl = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_comp_create_elments
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_type            [IN]        
 *  comp                [?]         
 *  st_user_data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_comp_create_elments(U32 mem_type, srv_clog_comp_struct *comp, void *st_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Init style manager */
    comp->style_mgr = srv_clog_stl_create(mem_type);

    /* Init job manager */
    comp->job_mgr = srv_clog_job_create(mem_type, SRV_CLOG_MAX_JOB_NUM);

    /* Init sort info table */
    comp->si_tbl = srv_clog_si_create(SRV_CLOG_MEM_TYPE_SYS);

    /* Init index info table */
    comp->idx_tbl = srv_clog_idx_create(SRV_CLOG_MEM_TYPE_SYS, comp->si_tbl, comp->style_mgr);
}


/*----------------------------------------------------------------------------*/
/* Job List                                                                   */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_COMP_JOB


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_type        [IN]        
 *  max_job_num     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_clog_job_mgr_struct *srv_clog_job_create(U32 mem_type, U32 max_job_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *buffer;
    U32 size = sizeof(srv_clog_job_mgr_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size += new_lcd_cqueue_mem_size(max_job_num);
    buffer = SRV_CLOG_MALLOC(mem_type, size);
    return srv_clog_job_create_from_mem(buffer, size, max_job_num);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_create_from_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_data        [?]         
 *  mem_size        [IN]        
 *  max_job_num     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_clog_job_mgr_struct *srv_clog_job_create_from_mem(void *mem_data, U32 mem_size, U32 max_job_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_job_mgr_struct *mgr = (srv_clog_job_mgr_struct*) mem_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ASSERT(mem_data && mem_size >= sizeof(srv_clog_job_mgr_struct) + new_lcd_cqueue_mem_size(max_job_num));

    mgr->queue_size = max_job_num;
    mgr->queue = lcd_create_cqueue_with_mem(max_job_num, (U8*) mem_data + sizeof(srv_clog_job_mgr_struct));

    return mgr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_is_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job_mgr     [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_job_is_empty(srv_clog_job_mgr_struct *job_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return lcd_cqueue_is_empty(job_mgr->queue);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job_mgr     [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_job_num(srv_clog_job_mgr_struct *job_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return lcd_cqueue_num_of_items(job_mgr->queue);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_is_blocked
 * DESCRIPTION
 *  Only PENDING and WAITING here,  PENDING: can be push by next async event triggled by itself,
 *  WAITING:  can only be push by next async event triggled by others such as PHB_READY
 * PARAMETERS
 *  job_mgr     [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_job_is_blocked(srv_clog_job_mgr_struct *job_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 num;
    srv_clog_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num = srv_clog_job_num(job_mgr);
    for (i = num - 1; i >= 0; i--)
    {
        job = srv_clog_job_index(job_mgr, i);
        if (job->job_state == SRV_CLOG_JOB_STATE_WAITING || job->job_state == SRV_CLOG_JOB_STATE_PENDING)
            return MMI_TRUE;
    }
    return MMI_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_get_type_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job_mgr     [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_job_get_type_num(srv_clog_job_mgr_struct *job_mgr, srv_clog_job_type_enum job_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 num;
    S32 count = 0;
    srv_clog_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num = srv_clog_job_num(job_mgr);
    for (i = num - 1; i >= 0; i--)
    {
        job = srv_clog_job_index(job_mgr, i);
        if (job->job_type == job_type)
            count++;
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_new
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_job_struct *srv_clog_job_new(srv_clog_job_mgr_struct *job_mgr, srv_clog_job_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = SRV_CLOG_TALLOC(SRV_CLOG_MEM_TYPE_TEMP, srv_clog_job_struct);
    srv_clog_job_reset(job);
    job->job_type = type;

    return job;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_job_reset(srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(job, 0x0, sizeof(srv_clog_job_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_job_free(srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!job)
        return;

    if (job->req_data)
        srv_clog_job_free_para(job, MMI_TRUE);
    if (job->cnf_data)
        srv_clog_job_free_para(job, MMI_FALSE);
    SRV_CLOG_MFREE(SRV_CLOG_MEM_TYPE_TEMP, job);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_new_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job             [?]         
 *  para_size       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_clog_job_new_para(srv_clog_job_struct *job, U32 para_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (para_size == 0)
        return NULL;
    
    para = SRV_CLOG_MALLOC(SRV_CLOG_MEM_TYPE_TEMP, para_size);
    memset(para, 0x0, para_size);
    return para;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_free_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job             [?]         
 *  is_free_req     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_job_free_para(srv_clog_job_struct *job, U32 is_free_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_free_req && job->req_data)
    {
        SRV_CLOG_MFREE(SRV_CLOG_MEM_TYPE_TEMP, job->req_data);
        job->req_data = NULL;
    }
    else if (!is_free_req && job->cnf_data)
    {
        SRV_CLOG_MFREE(SRV_CLOG_MEM_TYPE_TEMP, job->cnf_data);
        job->cnf_data = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job_mgr     [?]         
 *  idx         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_job_struct *srv_clog_job_index(srv_clog_job_mgr_struct *job_mgr, U32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx >= job_mgr->queue_size)
        return NULL;
    if (lcd_cqueue_is_empty(job_mgr->queue))
        return NULL;
    return (srv_clog_job_struct*) lcd_cqueue_index(job_mgr->queue, idx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_add_head
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job_mgr     [?]     
 *  job         [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_job_add_head(srv_clog_job_mgr_struct *job_mgr, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lcd_cqueue_is_full(job_mgr->queue))
        return SRV_CLOG_RET_FAIL;
    lcd_cqueue_insert_front(job_mgr->queue, (void*)job);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_add_tail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job_mgr     [?]     
 *  job         [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_job_add_tail(srv_clog_job_mgr_struct *job_mgr, srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lcd_cqueue_is_full(job_mgr->queue))
        return SRV_CLOG_RET_FAIL;
    lcd_cqueue_insert(job_mgr->queue, (void*)job);
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_remove_head
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job_mgr     [?]     
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_job_struct *srv_clog_job_remove_head(srv_clog_job_mgr_struct *job_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lcd_cqueue_is_empty(job_mgr->queue))
        return NULL;

    return (srv_clog_job_struct*) lcd_cqueue_remove(job_mgr->queue);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_submit_head
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job_mgr         [?]         
 *  job_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_job_struct *srv_clog_job_submit_head(srv_clog_job_mgr_struct *job_mgr, srv_clog_job_type_enum job_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = srv_clog_job_new(job_mgr, job_type);
    ret = srv_clog_job_add_head(job_mgr, job);
    if (ret != SRV_CLOG_RET_OK)
    {
        srv_clog_job_free(job);
        SRV_CLOG_ASSERT(0);
        return NULL;
    }
    return job;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_submit_tail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job_mgr         [?]         
 *  job_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_job_struct *srv_clog_job_submit_tail(srv_clog_job_mgr_struct *job_mgr, srv_clog_job_type_enum job_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 num;
    S32 ret;
    srv_clog_job_struct *job = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num = srv_clog_job_num(job_mgr);
    if (num > 0)
    {
        job = srv_clog_job_index(job_mgr, num - 1);
        /* Check if can reuse it to save control buffer and queue slot resource, 
           It can not be the first one. the reason is:
           it may be in processing and in deading and not dead completely as the CANCELING state is removed for slim,
           and there are some flow to be handled just before this time point, so not allow to reuse it,
           as it's the only one in queue, no meaning to save this slot.
         */
        if (job->job_state == SRV_CLOG_JOB_STATE_CANCELED && job != srv_clog_job_index(job_mgr, 0))
        {
            job = srv_clog_job_reuse(job_mgr, job, job_type);
            return job;
        }
    }
    job = srv_clog_job_new(job_mgr, job_type);
    ret = srv_clog_job_add_tail(job_mgr, job);
    if (ret != SRV_CLOG_RET_OK)
    {
        srv_clog_job_free(job);
        SRV_CLOG_ASSERT(0);
        return NULL;
    }
    return job;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_reuse
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job_mgr         [?]         
 *  job             [?]         
 *  new_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_clog_job_struct *srv_clog_job_reuse(
                        srv_clog_job_mgr_struct *job_mgr,
                        srv_clog_job_struct *job,
                        srv_clog_job_type_enum new_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free req_data cnf_data, no use now */
    if (job->req_data)
        srv_clog_job_free_para(job, MMI_TRUE);
    if (job->cnf_data)
        srv_clog_job_free_para(job, MMI_FALSE);
    srv_clog_job_reset(job);
    job->job_type = new_type;
    return job;
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
#endif //0

/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_job_cancel(srv_clog_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   SRV_CLOG_PARAM_CHECK(!job, SRV_CLOG_RET_INVALID_PARAM);

    //FlowChanged: Can remove job immediatelly even not done, 
    //specially for LogRevise/SimSync, it's also ok as they are internally flow.

    /* To get good maintainability, not allow to cancel current job in handling as it may cause the job state changed
       unlikely which cause hard effor to mantain it, just to remove the func_cb to avoid bother caller any more */
    if (job->job_state != SRV_CLOG_JOB_STATE_HANDLING)
        job->job_state = SRV_CLOG_JOB_STATE_CANCELED;

    job->func_cb = NULL;

    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_job_cancel_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job_mgr     [?]         
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_job_cancel_handle(srv_clog_job_mgr_struct *job_mgr, SRV_CLOG_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    U32 num;
    srv_clog_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_clog_job_is_empty(job_mgr))
        return SRV_CLOG_RET_NOT_FOUND;

    num = srv_clog_job_num(job_mgr);

    for (i = 0, j = 0; i < num; i++)
    {

        job = srv_clog_job_index(job_mgr, i);
        if (job->handle == handle)
        {
            srv_clog_job_cancel(job);
            job->handle = SRV_CLOG_INVALID_ELM;
            j++;
        }
    }
    if (j == 0)
    {
        SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_JOB_CANCEL_HANDLE));
        return SRV_CLOG_RET_NOT_FOUND;
    }
    return j;
}

/*----------------------------------------------------------------------------*/
/* Style Manager                                                              */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_COMP_STYLE


/*****************************************************************************
 * FUNCTION
 *  srv_clog_set_def_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  style       [IN]        
 *  data        [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_set_def_style(U32 type, U32 style, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK(SRV_CLOG_RET_OK != srv_clog_stl_valid(type, style, data, MMI_FALSE), SRV_CLOG_RET_INVALID_PARAM);

    /* Should first to init the service module */
    SRV_CLOG_PARAM_CHECK (!srv_clog_is_init(), SRV_CLOG_RET_NOT_INIT);

    if (srv_clog_is_ready())
        return SRV_CLOG_RET_NOT_AVAILABLE;

    ret = srv_clog_stl_set_style(srv_clog_get_cntx()->comp->style_mgr, type, style, data);

    SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SET_DEF_STYLE, type, style, data == NULL ? 0 : (U32) data, ret));
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_def_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  style       [?]         
 *  data        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_get_def_style(U32 type, U32 *style, void **data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK(type >= SRV_CLOG_STYLE_TYPE_DEF_MAX_ITEM && type < SRV_CLOG_STYLE_TYPE_BASE ||
        type >= SRV_CLOG_STYLE_TYPE_MAX_ITEM || !style, SRV_CLOG_RET_INVALID_PARAM);

    /* Should first to init the service module */
    SRV_CLOG_PARAM_CHECK (!srv_clog_is_init(), SRV_CLOG_RET_NOT_INIT);

    ret = srv_clog_stl_get_style(srv_clog_get_cntx()->comp->style_mgr, type, style, data);

    SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_GET_DEF_STYLE, type, *style));
    return ret;
}

/* once set its style, should set all style to it. */

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
/* under construction !*/
/* under construction !*/
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
 *  srv_clog_stl_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_stl_mgr_struct *srv_clog_stl_create(U32 mem_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_stl_mgr_struct *stl_mgr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stl_mgr = SRV_CLOG_TALLOC(mem_type, srv_clog_stl_mgr_struct);
    memset(stl_mgr, 0x0, sizeof(srv_clog_stl_mgr_struct));
    return stl_mgr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_destroy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  style_mgr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_stl_destroy(srv_clog_stl_mgr_struct *style_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_MFREE(SRV_CLOG_MEM_TYPE_SYS, style_mgr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_set_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  style_mgr       [?]         
 *  type            [IN]        
 *  style           [IN]        
 *  data            [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_stl_set_style(srv_clog_stl_mgr_struct *style_mgr, U32 type, U32 style, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx;
    U32 grp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = srv_clog_stl_is_bit_style(type, &grp);
    if (idx >= 0)
    {
        if (style)
            SRV_CLOG_SET_BIT(style_mgr->bit_styles[idx], style);
        else
            SRV_CLOG_CLEAR_BIT(style_mgr->bit_styles[idx], grp);
        return SRV_CLOG_RET_OK;
    }
    return SRV_CLOG_RET_NOT_SUPPORT;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_get_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  style_mgr       [?]         
 *  type            [IN]        
 *  style           [?]         
 *  data            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_stl_get_style(srv_clog_stl_mgr_struct *style_mgr, U32 type, U32 *style, void **data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx;
    U32 grp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK(!style, SRV_CLOG_RET_INVALID_PARAM);
    
    idx = srv_clog_stl_is_bit_style(type, &grp);
    if (idx >= 0)
    {
        *style = SRV_CLOG_GET_BIT(style_mgr->bit_styles[idx], grp);
        if (data)
            *data = NULL;
        return SRV_CLOG_RET_OK;
    }
    *style = 0;
    return SRV_CLOG_RET_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [IN]        
 *  style           [IN]        
 *  data            [?]         
 *  is_special      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_stl_valid(U32 type, U32 style, void *data, S32 is_special)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK(!(type < SRV_CLOG_STYLE_TYPE_DEF_MAX_ITEM ||
          type >= SRV_CLOG_STYLE_TYPE_BASE && type < SRV_CLOG_STYLE_TYPE_MAX_ITEM),
          SRV_CLOG_RET_INVALID_PARAM);

    if (is_special)
    {
        if (type < SRV_CLOG_STYLE_TYPE_DEF_MAX_ITEM)
            return SRV_CLOG_RET_NOT_SUPPORT;    /* not support handle's style now */
    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_is_bit_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  grp         [?]         
 * RETURNS
 *  The index of the style array which has this style
 *****************************************************************************/
static S32 srv_clog_stl_is_bit_style(U32 type, U32 *grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    static const U8 bit_styles_1[] = 
    {
        SRV_CLOG_STYLE_TYPE_MERGE,
        SRV_CLOG_STYLE_TYPE_NUM,
        
#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
        SRV_CLOG_STYLE_TYPE_SIM_SYNC,
#endif

#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
        SRV_CLOG_STYLE_TYPE_PHB_SYNC,
#endif
    };

    static const U32 bit_style_grp_1[] = 
    {
        SRV_CLOG_STYLE_MERGE_GRP,
        SRV_CLOG_STYLE_NUM_GRP,
        
#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
        SRV_CLOG_STYLE_SIM_SYNC_GRP,
#endif

#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
        SRV_CLOG_STYLE_PHB_SYNC_GRP,
#endif
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(bit_styles_1) / sizeof(U8); i++)
    {
        if (type == bit_styles_1[i])
        {
            if (grp)
                *grp = bit_style_grp_1[i];
            return 0; /* Only one element in style array */
        }
    }
    /* TODO: continue to check next bit group */

    return -1;
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
#endif //0
    


#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_support_sim_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  style_mgr       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_stl_support_sim_sync(srv_clog_stl_mgr_struct *style_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sync_style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_stl_get_style(style_mgr, SRV_CLOG_STYLE_TYPE_SIM_SYNC, &sync_style, NULL);
    if (SRV_CLOG_CHECK_BIT(sync_style, SRV_CLOG_STYLE_SIM_SYNC_READ | SRV_CLOG_STYLE_SIM_SYNC_WRITE))
        return MMI_TRUE;
    return MMI_FALSE;
}
#endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */


#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_support_phb_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  style_mgr       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_stl_support_phb_sync(srv_clog_stl_mgr_struct *style_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sync_style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_stl_get_style(style_mgr, SRV_CLOG_STYLE_TYPE_PHB_SYNC, &sync_style, NULL);
    if (sync_style)
        return MMI_TRUE;
    return MMI_FALSE;
}
#endif //0

/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_support_merge
 * DESCRIPTION
 *  
 * PARAMETERS
 *  style_mgr       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_stl_support_merge(srv_clog_stl_mgr_struct *style_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 merge_style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_stl_get_style(style_mgr, SRV_CLOG_STYLE_TYPE_MERGE, &merge_style, NULL);
    if (merge_style)
        return MMI_TRUE;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_support_thread
 * DESCRIPTION
 *  
 * PARAMETERS
 *  style_mgr       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_stl_support_thread(srv_clog_stl_mgr_struct *style_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 merge_style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_stl_get_style(style_mgr, SRV_CLOG_STYLE_TYPE_MERGE, &merge_style, NULL);

    if (SRV_CLOG_CHECK_BIT(merge_style, SRV_CLOG_STYLE_MERGE_THREAD))
        return MMI_TRUE;
    return MMI_FALSE;
}

#endif /* __MMI_TELEPHONY_SUPPORT__ */
