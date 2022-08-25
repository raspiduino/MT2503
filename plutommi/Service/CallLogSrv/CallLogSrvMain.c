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
*  CallLogSrvMain.c
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

#include "kal_general_types.h"
#include "kal_trace.h"

#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvComp.h"
#include "CallLogSrvProt.h"

#ifdef __MMI_TELEPHONY_SUPPORT__

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
/* Context Initialization & operation */
static void srv_clog_cntx_init(void);
static srv_clog_cntx_struct *srv_clog_cntx_create(void);

/* Sub module initialization */
static void srv_clog_others_init(void);

/* Instance initialization & operation */
static srv_clog_inst_tbl_struct *srv_clog_inst_create(void);
static srv_clog_inst_struct *srv_clog_inst_alloc(srv_clog_inst_tbl_struct *inst_tbl);
static S32 srv_clog_inst_free(srv_clog_inst_tbl_struct *inst_tbl, srv_clog_inst_struct *inst);
static void srv_clog_inst_reset(srv_clog_inst_struct *inst);

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
static srv_clog_cntx_struct *srv_clog_cntx_p;

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

#define SRV_CLOG_M_INIT


/*****************************************************************************
 * FUNCTION
 *  srv_clog_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET srv_clog_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_clog_is_init())
        return MMI_RET_OK;

    SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_INIT, 0));

    srv_clog_mem_init();

    srv_clog_cntx_init();

    srv_clog_others_init();

    srv_clog_evt_init();

    SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_INIT, 1));

    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cntx_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_p = srv_clog_cntx_create();
    srv_clog_cntx_p->inst_tbl = srv_clog_inst_create();
    srv_clog_cntx_p->comp = srv_clog_comp_create(SRV_CLOG_MEM_TYPE_SYS);
    srv_clog_comp_create_elments(SRV_CLOG_MEM_TYPE_SYS, srv_clog_cntx_p->comp, srv_clog_cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cntx_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static srv_clog_cntx_struct *srv_clog_cntx_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = SRV_CLOG_TALLOC(SRV_CLOG_MEM_TYPE_SYS, srv_clog_cntx_struct);
    memset(cntx, 0x0, sizeof(srv_clog_cntx_struct));
    return cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_cntx_struct *srv_clog_get_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_clog_cntx_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_is_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_is_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_clog_get_cntx() != NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_is_initializing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_is_initializing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_clog_get_cntx()->state == SRV_CLOG_STATE_INITING);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_is_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_is_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_clog_is_init())
        return MMI_FALSE;

    return (srv_clog_get_cntx()->state >= SRV_CLOG_STATE_READY);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_new_log_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 * RETURNS
 *  
 *****************************************************************************/
SRV_CLOG_ID srv_clog_new_log_id(srv_clog_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->max_log_id += SRV_CLOG_LOG_ID_STEP_LEN;
    return cntx->max_log_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_reset_log_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 * RETURNS
 *  
 *****************************************************************************/
SRV_CLOG_ID srv_clog_reset_log_id(srv_clog_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->max_log_id = SRV_CLOG_LOG_ID_START;
    return cntx->max_log_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_new_log_id_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  log_id      [?]     
 * RETURNS
 *  
 *****************************************************************************/
SRV_CLOG_ID srv_clog_new_log_id_ex(srv_clog_cntx_struct *cntx, U32 *log_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *log_id += SRV_CLOG_LOG_ID_STEP_LEN;
    return *log_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_reserve_log_ids
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  count       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
SRV_CLOG_ID srv_clog_reserve_log_ids(srv_clog_cntx_struct *cntx, U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_CLOG_ID start_log_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->max_log_id = srv_clog_revise_log_id(cntx->max_log_id);
    start_log_id = cntx->max_log_id;
    cntx->max_log_id += SRV_CLOG_LOG_ID_STEP_LEN * count;
    return start_log_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_revise_log_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  log_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
SRV_CLOG_ID srv_clog_revise_log_id(SRV_CLOG_ID log_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (log_id <= SRV_CLOG_LOG_ID_START)
        return log_id + SRV_CLOG_LOG_ID_START;
    return log_id;
}


#if 0 // APIReserved
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
 *  srv_clog_new_pid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_new_pid(srv_clog_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->max_pid++;
    return cntx->max_pid;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_others_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_others_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_CLOG_ATCMD_SUPPORT__
    /* Init AT command module */
    srv_clog_at_init();
#endif /* __MMI_CLOG_ATCMD_SUPPORT__ */

#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
    /* Init SIM Sync module */
    srv_clog_sim_init();

#endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */ 

}

#define SRV_CLOG_M_INST


/*****************************************************************************
 * FUNCTION
 *  srv_clog_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  create      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
SRV_CLOG_HANDLE srv_clog_create(const srv_clog_create_struct *create)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_clog_create_int(create, 0);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_create_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  create      [IN]        
 *  flags       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
SRV_CLOG_HANDLE srv_clog_create_int(const srv_clog_create_struct *create, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_inst_struct *inst;
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* First to check if initialized, 
       as other AP may initialized earlier than this service */
    if (!srv_clog_is_init())
        srv_clog_init(NULL);

    inst = srv_clog_inst_alloc(cntx->inst_tbl);

    /* Create data can be NULL, if NULL, use global data */
    if (create)
    {
        srv_clog_pi_cp_i((srv_clog_log_identity_struct*) & create->identity, &inst->idt);
        srv_clog_pi_revise_i(&inst->idt, MMI_TRUE);
        inst->user_data = create->user_data;

        SRV_CLOG_IT_TRACE((
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_CREATE,
            create->identity.cate,
            create->identity.sim_id,
            create->identity.log_type,
            create->identity.sub_type));
    }

    /*
     * Default to use the components of the context, 
     * can allocate a private components later if use special styles 
     */
    inst->comp = cntx->comp;
    SRV_CLOG_SET_BIT(inst->flags, flags);
    return SRV_CLOG_HDL(inst);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_inst_priority
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_clog_get_inst_priority(SRV_CLOG_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_inst_struct *inst = SRV_CLOG_INST(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!inst) /* Can be NULL here as pass by caller module */
        return 0;
    if (SRV_CLOG_CHECK_BIT(inst->flags, SRV_CLOG_INST_FLAG_HIGH_PRIORITY))
        return 1;
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_inst_flags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_clog_get_inst_flags(SRV_CLOG_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_inst_struct *inst = SRV_CLOG_INST(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!inst)
        return 0;
    return inst->flags;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_destroy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_destroy(SRV_CLOG_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_cntx_struct *cntx = srv_clog_get_cntx();
    srv_clog_inst_struct *inst = SRV_CLOG_INST(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_CLOG_IS_ELM_INVALID(handle))
        return SRV_CLOG_RET_INVALID_PARAM;

    if (!srv_clog_is_init())
        return SRV_CLOG_RET_NOT_INIT;

    srv_clog_job_cancel_handle(cntx->comp->job_mgr, handle);

/* FlowReserved

    if (inst->comp->style_mgr != cntx->comp->style_mgr)
    {
        srv_clog_stl_destroy(inst->comp->style_mgr);
        inst->comp->style_mgr = NULL;
    }
    if (inst->comp != cntx->comp)
    {
        srv_clog_comp_destroy(inst->comp);
        inst->comp = NULL;
    }
*/
    SRV_CLOG_IT_TRACE((
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_DESTRORY,
        handle,
        inst->idt.cate,
        inst->idt.sim_id,
        inst->idt.log_type,
        inst->idt.sub_type));

    srv_clog_inst_free(cntx->inst_tbl, inst);

    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_user_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_clog_get_user_data(SRV_CLOG_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_inst_struct *inst = SRV_CLOG_INST(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inst)
        return inst->user_data;
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_inst_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static srv_clog_inst_tbl_struct *srv_clog_inst_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_clog_inst_tbl_struct *inst_tbl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst_tbl = SRV_CLOG_TALLOC(SRV_CLOG_MEM_TYPE_SYS, srv_clog_inst_tbl_struct);
    for (i = 0; i < SRV_CLOG_MAX_INST_NUM; i++)
    {
        if (i < SRV_CLOG_INST_MAX_PRE_DEF_NUM)
        {
            inst_tbl->data[i] = SRV_CLOG_TALLOC(SRV_CLOG_MEM_TYPE_SYS, srv_clog_inst_struct);
            srv_clog_inst_reset(inst_tbl->data[i]);
            SRV_CLOG_SET_BIT((inst_tbl->data[i])->flags, SRV_CLOG_INST_FLAG_PRE_DEF);
        }
        else
            inst_tbl->data[i] = NULL;
    }
    return inst_tbl;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_inst_alloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst_tbl        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static srv_clog_inst_struct *srv_clog_inst_alloc(srv_clog_inst_tbl_struct *inst_tbl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_clog_inst_struct *inst = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * All predefined instance are located in the front of the instance table forever,
     * So it's ok to allocate it dynamically once find an empty slot 
     */
    for (i = 0; i < SRV_CLOG_MAX_INST_NUM; i++)
    {
        inst = inst_tbl->data[i];

        /* Skip two cases: predefined-in-use and temp-alloc-in-use*/
        if (inst && SRV_CLOG_CHECK_BIT(inst->flags, SRV_CLOG_INST_FLAG_IN_USE))
            continue;

        if (!inst) /* Can only be temp-allocate segement*/
        {
            inst = SRV_CLOG_TALLOC(SRV_CLOG_MEM_TYPE_TEMP, srv_clog_inst_struct);
            srv_clog_inst_reset(inst);
            inst_tbl->data[i] = inst;
        }
        SRV_CLOG_SET_BIT(inst->flags, SRV_CLOG_INST_FLAG_IN_USE);
        SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_INST_INEW, inst, i, i < SRV_CLOG_INST_MAX_PRE_DEF_NUM ? 1 : 0));
        break;
    }
    return inst;

}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_inst_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst_tbl        [?]     
 *  inst            [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_inst_free(srv_clog_inst_tbl_struct *inst_tbl, srv_clog_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CLOG_MAX_INST_NUM; i++)
    {
        if (inst_tbl->data[i] != inst)
            continue;

        SRV_CLOG_ASSERT(SRV_CLOG_CHECK_BIT(inst->flags, SRV_CLOG_INST_FLAG_IN_USE));

        if (i < SRV_CLOG_INST_MAX_PRE_DEF_NUM)
        {
            srv_clog_inst_reset(inst);
        }
        else
        {
            SRV_CLOG_MFREE(SRV_CLOG_MEM_TYPE_TEMP, inst);
            inst_tbl->data[i] = NULL;
        }
        SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_INST_FREE, inst, i, i < SRV_CLOG_INST_MAX_PRE_DEF_NUM ? 1 : 0));

        return SRV_CLOG_RET_OK;
    }
    return SRV_CLOG_RET_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_inst_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_inst_reset(srv_clog_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(inst, 0x0, sizeof(srv_clog_inst_struct));
    srv_clog_pi_reset_i(&inst->idt);
}

#else /* __MMI_TELEPHONY_SUPPORT__ */

MMI_RET srv_clog_init(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

SRV_CLOG_HANDLE srv_clog_create(const srv_clog_create_struct *create)
{
    return 0;
}

S32 srv_clog_delete_all_logs(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            const srv_clog_del_all_logs_req_struct *req_data,
            SRV_CLOG_BASE_CB func_cb)
{
    return 0;
}

S32 srv_clog_destroy(SRV_CLOG_HANDLE handle)
{
    return 0;
}

S32 srv_clog_get_list_num_info(
            SRV_CLOG_HANDLE handle,
            const srv_clog_log_identity_struct *identity,
            srv_clog_num_info_struct *num_info)
{
    return 0;
}

U32 srv_clog_get_unread_missed_call_num(void)
{
    return 0;
}

S32 srv_clog_init_para(srv_clog_para_enum para_type, void *para_data)
{
    return 0;
}

S32 srv_clog_get_list_log(
            SRV_CLOG_HANDLE handle,
            const srv_clog_get_list_log_req_struct *req_data,
            srv_clog_get_list_log_cnf_struct *cnf_data)
{
    return 0;
}

S32 srv_clog_set_def_style(U32 type, U32 style, void *data)
{
    return 0;
}

S32 srv_clog_start(void)
{
    return 0;
}

mmi_frm_proc_result_enum srv_clog_shutdown_hdlr(void *arg, const mmi_frm_proc_id_info_struct id_info)
{
    return MMI_FRM_PROC_RESULT_COMPLETED;
}

S32 srv_clog_log_call(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            const srv_clog_log_call_req_struct *req_data,
            SRV_CLOG_ID *log_id,
            SRV_CLOG_BASE_CB func_cb)
{
    return 0;
}

S32 srv_clog_log_duration(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            const srv_clog_log_duration_req_struct *req_data,
            SRV_CLOG_BASE_CB func_cb)
{
    return 0;
}

S32 srv_clog_get_last_log(
            SRV_CLOG_HANDLE handle,
            const srv_clog_get_last_log_req_struct *req_data,
            srv_clog_get_last_log_cnf_struct *cnf_data)
{
    return 0;
}

S32 srv_clog_get_log_by_id(SRV_CLOG_HANDLE handle, SRV_CLOG_ID log_id, U32 fields, srv_clog_log_struct *log)
{
    return 0;
}

S32 srv_clog_update_all_logs(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            const srv_clog_update_all_logs_req_struct *req_data,
            SRV_CLOG_BASE_CB func_cb)
{
    return 0;
}

#endif /* __MMI_TELEPHONY_SUPPORT__ */
