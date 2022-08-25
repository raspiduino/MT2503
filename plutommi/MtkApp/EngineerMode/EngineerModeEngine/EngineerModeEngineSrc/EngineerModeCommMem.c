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
 *  EngineerModeCommMem.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for engineer mode common memory.
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
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#include "MMI_features.h"
#include "EngineerModeUtil.h"

#ifdef __MMI_ENGINEER_MODE__

/***************************************************************************** 
* Include 
*****************************************************************************/

#if defined(COSMOS_EM_INTERNAL_DCM)
#include "dcmgr.h"
#elif defined (PLUTO_EM_INTERNAL_DCM)
#include "MMI_ap_dcm_config.h"  
#endif /* COSMOS_EM_INTERNAL_DCM */

#if defined(PLUTO_EM_INTERNAL_DCM)
#pragma arm section rodata = "DYNAMIC_CODE_EM_RODATA" , code = "DYNAMIC_CODE_EM_ROCODE"
#elif defined(COSMOS_EM_INTERNAL_DCM)
#pragma arm section rodata = "DYNAMIC_CODE_COSMOS_EM_RODATA" , code = "DYNAMIC_CODE_COSMOS_EM_ROCODE"
#endif /* PLUTO_EM_INTERNAL_DCM */ 


#include "MMIDataType.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_mem_gprot.h"

#include "App_mem.h"
#include "mmi_rp_app_engineermode1_def.h"
#include "EngineerModeGProt.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeResDef.h"

/***************************************************************************** 
* Struct 
*****************************************************************************/
typedef void (*mmi_em_comm_mem_asm_stop_callback_func)(void);

typedef struct mmi_em_comm_mem_release_info_struct_tag
{
    mmi_em_comm_mem_stop_callback_func release_cb;
    struct mmi_em_comm_mem_release_info_struct_tag *next; 
} mmi_em_comm_mem_release_info_struct;


typedef struct
{
    U8 ref_count;
    U8 state;
    KAL_ADM_ID adm_id;
    U8* asm_pool;
    mmi_em_comm_mem_start_callback_func app_start_cb;
    mmi_em_comm_mem_release_info_struct *app_release_cb;
} mmi_em_comm_mem_status_struct;

/***************************************************************************** 
* Global
*****************************************************************************/
static void mmi_em_comm_mem_start_callback(void);
static void mmi_em_comm_mem_stop_callback(void);
static void mmi_em_comm_mem_delete_cb_node(mmi_em_comm_mem_release_info_struct *node);
static void mmi_em_comm_mem_insert_cb_head(mmi_em_comm_mem_stop_callback_func cb);
static void mmi_em_comm_mem_delete_cb(mmi_em_comm_mem_stop_callback_func cb);


static mmi_em_comm_mem_status_struct g_em_comm_mem_status;


/***************************************************************************** 
* Function
*****************************************************************************/
void mmi_em_comm_mem_ap_register(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_register(APPLIB_MEM_AP_ID_EM_COMM_MEM, STR_ID_EM_APP_NAME, 
        IMG_ID_EM_MAIN_ICON, mmi_em_comm_mem_stop_callback);
    g_em_comm_mem_status.state = MMI_EM_COMM_MEM_STATE_INIT;
}


void mmi_em_comm_mem_ap_create_adm(void)
{
    /* Init ADM*/
    g_em_comm_mem_status.adm_id = kal_adm_create(g_em_comm_mem_status.asm_pool, MMI_EM_COMM_MEM_ASM_POOL_SIZE, NULL, KAL_FALSE);
    MMI_ASSERT(g_em_comm_mem_status.adm_id);
    g_em_comm_mem_status.ref_count++;
    g_em_comm_mem_status.state = MMI_EM_COMM_MEM_STATE_READY;
}

MMI_BOOL mmi_em_comm_mem_ap_init(mmi_em_comm_mem_start_callback_func ap_start_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_comm_mem_status_struct *item_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_status = &g_em_comm_mem_status;

    
    if (item_status->state != MMI_EM_COMM_MEM_STATE_INIT &&
        item_status->state != MMI_EM_COMM_MEM_STATE_READY &&
        item_status->state != MMI_EM_COMM_MEM_STATE_ALLOCING)
    {
        MMI_ASSERT(0);
        return MMI_FALSE;
    }
    
    /* Already init*/
    if (item_status->state != MMI_EM_COMM_MEM_STATE_ALLOCING &&
        item_status->ref_count > 0)
    {
        item_status->ref_count++;
        return MMI_TRUE;
    }

    /* Get ASM*/
    item_status->asm_pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_EM_COMM_MEM, MMI_EM_COMM_MEM_ASM_POOL_SIZE);
    if (item_status->asm_pool == NULL)
    {
        item_status->app_start_cb = ap_start_cb;
        
        mmi_frm_appmem_prompt_to_release_mem(STR_ID_EM_APP_NAME,
            IMG_ID_EM_MAIN_ICON, MMI_EM_COMM_MEM_ASM_POOL_SIZE, mmi_em_comm_mem_start_callback);
        
        item_status->state = MMI_EM_COMM_MEM_STATE_ALLOCING;
        return MMI_FALSE;
    }

    /* Init ADM*/
    mmi_em_comm_mem_ap_create_adm();

    return MMI_TRUE;
}

void mmi_em_comm_mem_ap_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_comm_mem_status_struct *item_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_status = &g_em_comm_mem_status;
    
    if (item_status->state != MMI_EM_COMM_MEM_STATE_READY ||
        item_status->ref_count == 0)
    {
        return;
    }
    item_status->ref_count--;
    if (item_status->ref_count == 0)
    {
        kal_adm_delete(item_status->adm_id);
        item_status->adm_id = 0;

        applib_mem_ap_free(item_status->asm_pool);
        item_status->asm_pool = NULL;
        
        item_status->state = MMI_EM_COMM_MEM_STATE_INIT;
    }
}


void mmi_em_comm_mem_ap_stop_finished(void)
{    
    mmi_em_comm_mem_delete_cb_node(g_em_comm_mem_status.app_release_cb);
    mmi_em_comm_mem_stop_callback();
}


void* mmi_em_comm_mem_alloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_em_comm_mem_status.state != MMI_EM_COMM_MEM_STATE_READY ||
        !g_em_comm_mem_status.adm_id)
    {
        MMI_ASSERT(0);
        return NULL;
    }

    p = kal_adm_alloc(g_em_comm_mem_status.adm_id, size);
    MMI_ASSERT(p);

    return p;
}


void mmi_em_comm_mem_free(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    if (g_em_comm_mem_status.state != MMI_EM_COMM_MEM_STATE_READY ||
        !g_em_comm_mem_status.adm_id)
    {
        MMI_ASSERT(0);
        return;
    }

    kal_adm_free(g_em_comm_mem_status.adm_id, p);
}

static void mmi_em_comm_mem_start_callback()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_comm_mem_status_struct *item_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_status = &g_em_comm_mem_status;
    
    MMI_ASSERT(item_status->state == MMI_EM_COMM_MEM_STATE_ALLOCING);
    
    /* Retry to get ASM*/
    /* Get ASM*/
    item_status->asm_pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_EM_COMM_MEM, MMI_EM_COMM_MEM_ASM_POOL_SIZE);
    if (item_status->asm_pool == NULL)
    {
        MMI_ASSERT(0);
        item_status->state = MMI_EM_COMM_MEM_STATE_INIT;
        return;
    }

    /* Init ADM*/
    mmi_em_comm_mem_ap_create_adm();

    if (item_status->app_start_cb)
        item_status->app_start_cb();
    item_status->app_start_cb = NULL;
}


void mmi_em_comm_mem_ap_reg_stop_hdlr(mmi_em_comm_mem_stop_callback_func ap_stop_cb)
{
    mmi_em_comm_mem_insert_cb_head(ap_stop_cb);
}


void mmi_em_comm_mem_ap_unreg_stop_hdlr(mmi_em_comm_mem_stop_callback_func ap_stop_cb)
{    
    mmi_em_comm_mem_delete_cb(ap_stop_cb);
}


static void mmi_em_comm_mem_insert_cb_head(mmi_em_comm_mem_stop_callback_func cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_comm_mem_release_info_struct *node;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = mmi_em_comm_mem_alloc(sizeof(mmi_em_comm_mem_release_info_struct));
    if (!node)
    {
        return;
    }

    node->release_cb = cb;
    node->next = g_em_comm_mem_status.app_release_cb;
    g_em_comm_mem_status.app_release_cb = node;
}

static void mmi_em_comm_mem_delete_cb_node(mmi_em_comm_mem_release_info_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_comm_mem_release_info_struct *prev = NULL;
    mmi_em_comm_mem_release_info_struct *cur  = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur = g_em_comm_mem_status.app_release_cb;
    
    prev = cur;

    while(cur)
    {
        if (cur == node)
        {
            if (cur == g_em_comm_mem_status.app_release_cb)
            {
                g_em_comm_mem_status.app_release_cb = cur->next;
            }
            else
            {
                prev->next = cur->next;
            }
            mmi_em_comm_mem_free(node);
            return;
        }
        prev = cur;
        cur  = cur->next;
    }
}

static void mmi_em_comm_mem_delete_cb(mmi_em_comm_mem_stop_callback_func cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_comm_mem_release_info_struct *node;
    mmi_em_comm_mem_release_info_struct *prev;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //use header node to initial node
    node = g_em_comm_mem_status.app_release_cb;
    
    prev = node;

    while(node)
    {
        if (node->release_cb == cb)
        {
            //node is header node.
            if (node == g_em_comm_mem_status.app_release_cb)
            {
                g_em_comm_mem_status.app_release_cb = node->next;
            }
            else
            {
                //node is not header node
                prev->next = node->next;
            }
            mmi_em_comm_mem_free(node);
            node = NULL;
            return;
        }
        prev = node;
        node = node->next;
    }
}

static void mmi_em_comm_mem_stop_callback()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MMI_BOOL ret;
    mmi_em_comm_mem_status_struct *item_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_status = &g_em_comm_mem_status;
    
    while (item_status->app_release_cb)
    {
        if (item_status->app_release_cb->release_cb)
        {
            //ret = item_status->app_release_cb->release_cb();
            item_status->app_release_cb->release_cb();
            mmi_em_comm_mem_delete_cb_node(item_status->app_release_cb);
        }
    }

    if (item_status->adm_id)
    {
        kal_adm_delete(item_status->adm_id);
        item_status->adm_id = 0;
    }
    if (item_status->asm_pool)
    {
        applib_mem_ap_free(item_status->asm_pool);
        item_status->asm_pool = NULL;
    }

    item_status->ref_count = 0;
    item_status->state = MMI_EM_COMM_MEM_STATE_INIT;
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_EM_COMM_MEM, MMI_TRUE);
}


void mmi_em_comm_mem_hold(void)
{
    g_em_comm_mem_status.ref_count++;
}

void mmi_em_comm_mem_stop_hold(void)
{
    g_em_comm_mem_status.ref_count--;
}

#if (defined(COSMOS_EM_INTERNAL_DCM) || defined(PLUTO_EM_INTERNAL_DCM))
#pragma arm section rodata , code
#endif /* #ifdef COSMOS_EM_INTERNAL_DCM  || PLUTO_EM_INTERNAL_DCM */ 

#endif /* __MMI_ENGINEER_MODE__*/
