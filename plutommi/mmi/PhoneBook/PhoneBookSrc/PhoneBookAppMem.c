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
 *  PhoneBooklAppMem.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the phonebook memory management functions.
 *
 * Author:
 * -------
 *  
 *
 *
 *  
 * 
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"


#include "mmi_rp_app_phonebook_def.h"
#include "PhonebookProt.h"
#include "PhonebookGprot.h"
#include "PhoneBookAppMem.h"

#include "app_mem.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "MMIDataType.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_inet_app_trc.h"
#include "PhbSrvGprot.h"

static mmi_phonebook_app_mem_cntx_struct g_mmi_phonebook_app_mem_cntx;
static mmi_phonebook_app_mem_cntx_struct *mmi_phonebook_app_mem_p = &g_mmi_phonebook_app_mem_cntx;

BOOL g_phonebook_is_asm_created_by_others;
void *g_phonebook_memory_pool_ptr = NULL;
void *g_phonebook_view_memory_pool_ptr = NULL;


/*****************************************************************************
 * FUNCTION
 *  mmi_phonebook_stop_app_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phonebook_stop_app_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
	//MMI_TRACE(MMI_PHB_TRACE_GROUP, _mmi_phonebook_stop_app_callback);
    
	mmi_phb_cntx_mgr_clear_history();
	kal_prompt_trace(MOD_MMI,"[phonebook]mmi_phonebook_stop_app_callback");
	
	 if(NULL != mmi_phonebook_app_mem_p->mem_adm_id)
     {
       kal_prompt_trace(MOD_MMI,"[phonebook]NULL != mmi_phonebook_app_mem_p->mem_adm_id");
        kal_adm_delete(mmi_phonebook_app_mem_p->mem_adm_id);
        mmi_phonebook_app_mem_p->mem_adm_id = NULL;
	 }
	 if(NULL != mmi_phonebook_app_mem_p->mem_ptr)
	 {
	 	
		kal_prompt_trace(MOD_MMI,"[phonebook]NULL != mmi_phonebook_app_mem_p->mem_ptr");
        applib_mem_ap_free(mmi_phonebook_app_mem_p->mem_ptr);
        mmi_phonebook_app_mem_p->mem_ptr = NULL;
       
	 }
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_PHONEBOOK, KAL_TRUE);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phonebook_app_mem_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phonebook_app_mem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
	//MMI_TRACE(MMI_PHB_TRACE_GROUP, mmi_phonebook_app_mem_init);

    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_PHONEBOOK, 
        STR_SCR_PBOOK_VIEW_CAPTION, 
        0, 
        mmi_phonebook_stop_app_callback);
    mmi_phonebook_app_mem_p->mem_ptr = NULL;
    mmi_phonebook_app_mem_p->mem_adm_id = NULL;
    return;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phonebook_app_mem_pool_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void *mmi_phonebook_app_mem_pool_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr = NULL;
    KAL_ADM_ID mem_pool_id = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//MMI_TRACE(MMI_PHB_TRACE_GROUP, mmi_phonebook_app_mem_pool_malloc);
	
    MMI_ASSERT((NULL == mmi_phonebook_app_mem_p->mem_ptr) && (NULL == mmi_phonebook_app_mem_p->mem_adm_id));

    ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_PHONEBOOK, size);
    if (NULL == ptr)
    {
        goto MMI_PHONEBOOK_APP_MEM_POOL_MALLOC_END;
    }
    
    mem_pool_id = kal_adm_create(ptr, size, NULL, MMI_TRUE);
    if (NULL == mem_pool_id)
    {
        applib_mem_ap_free(ptr);
        ptr = NULL;
        goto MMI_PHONEBOOK_APP_MEM_POOL_MALLOC_END;
    }

    mmi_phonebook_app_mem_p->mem_ptr = ptr;
    mmi_phonebook_app_mem_p->mem_adm_id = mem_pool_id;
    
MMI_PHONEBOOK_APP_MEM_POOL_MALLOC_END:
    //MMI_TRACE(MMI_PHB_TRACE_GROUP, mmi_phonebook_app_mem_pool_malloc);
    return ptr;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phonebook_app_mem_get_ptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void *mmi_phonebook_app_mem_get_ptr(void)
{
	//MMI_TRACE(MMI_PHB_TRACE_GROUP, mmi_phonebook_app_mem_get_ptr,mmi_phonebook_app_mem_p->mem_ptr);
    
    return mmi_phonebook_app_mem_p->mem_ptr;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phonebook_app_mem_pool_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phonebook_app_mem_pool_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_PHB_TRACE_GROUP, mmi_phonebook_app_mem_pool_free,mmi_phonebook_app_mem_p->mem_ptr);
    kal_prompt_trace(MOD_MMI,"[phonebook]mmi_phonebook_app_mem_pool_free");

	 if(NULL != ptr)
     {
      kal_prompt_trace(MOD_MMI,"[phonebook]NULL != ptr");
	 if(ptr == mmi_phonebook_app_mem_p->mem_ptr)
       {
       kal_prompt_trace(MOD_MMI,"[phonebook]ptr == mmi_phonebook_app_mem_p->mem_ptr");
        kal_adm_delete(mmi_phonebook_app_mem_p->mem_adm_id);
        mmi_phonebook_app_mem_p->mem_adm_id = NULL;

        applib_mem_ap_free(mmi_phonebook_app_mem_p->mem_ptr);
        mmi_phonebook_app_mem_p->mem_ptr = NULL;
       }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phonebook_app_mem_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void *mmi_phonebook_app_mem_malloc(U32 size,srv_phb_memory_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = kal_adm_alloc(mmi_phonebook_app_mem_p->mem_adm_id, size);
    //MMI_TRACE(MMI_PHB_TRACE_GROUP, mmi_phonebook_app_mem_malloc, size, ptr);
    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phonebook_app_mem_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phonebook_app_mem_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_PHB_TRACE_GROUP, mmi_phonebook_app_mem_free, mmi_phonebook_app_mem_p->mem_adm_id, ptr);
    if(mmi_phonebook_app_mem_p->mem_adm_id!=NULL)
    {
   		 kal_adm_free(mmi_phonebook_app_mem_p->mem_adm_id, ptr);
		// ptr = NULL;
    }
	
	return;
}

/*
void *mmi_phoneboook_select_contact_asm_create(void (*caller)(void))
{
   

    g_phonebook_memory_pool_ptr = mmi_phonebook_app_mem_get_ptr();
    if (g_phonebook_memory_pool_ptr == NULL)
    {
        g_phonebook_is_asm_created_by_others = FALSE;
        g_phonebook_memory_pool_ptr = mmi_phonebook_app_mem_pool_malloc(MMI_PHONEBOOK_MEM_POOL_SIZE);
        if (g_phonebook_memory_pool_ptr == NULL)
        {
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_PHONEBOOK,
                0,
                MMI_PHONEBOOK_MEM_POOL_SIZE,
                caller);
            return NULL;
        }
    }
    else
    {
        g_phonebook_is_asm_created_by_others = TRUE;
    }

    return g_phonebook_memory_pool_ptr;
}


void mmi_phoneboook_select_contact_asm_destroy(void)
{
   

   / /Free ASM 
    if (!g_phonebook_is_asm_created_by_others)
    {
        if (mmi_phonebook_app_mem_get_ptr() != NULL)
        {
            mmi_phonebook_app_mem_pool_free(g_phonebook_memory_pool_ptr);
        }
        g_phonebook_is_asm_created_by_others = FALSE;
        g_phonebook_memory_pool_ptr = NULL;
    }
}
*/

