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
 *  EmailAppMem.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email memory management functions.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_EMAIL__
#include "mmi_rp_app_email_def.h"
#include "EmailAppProt.h"
#include "EmailAppMem.h"

#include "app_mem.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "MMIDataType.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_inet_app_trc.h"

static mmi_email_app_mem_cntx_struct g_mmi_email_app_mem_cntx;
static mmi_email_app_mem_cntx_struct *mmi_email_app_mem_p = &g_mmi_email_app_mem_cntx;

/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_mem_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_email_stop_app_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_STOP_APP_CALLBACK, __LINE__);

    mmi_email_exit_app_by_asm();
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_EMAIL, KAL_TRUE);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_mem_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_email_app_mem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MEM_INIT, __LINE__);

    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_EMAIL, 
        STR_GLOBAL_EMAIL, 
        IMG_EMAIL_MAIN_ID, 
        mmi_email_stop_app_callback);
    mmi_email_app_mem_p->mem_ptr = NULL;
    mmi_email_app_mem_p->mem_adm_id = NULL;
    return;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_mem_pool_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void *mmi_email_app_mem_pool_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr = NULL;
    KAL_ADM_ID mem_pool_id = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((NULL == mmi_email_app_mem_p->mem_ptr) && (NULL == mmi_email_app_mem_p->mem_adm_id));

    ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_EMAIL, size);
    if (NULL == ptr)
    {
        goto MMI_EMAIL_APP_MEM_POOL_MALLOC_END;
    }
    
    mem_pool_id = kal_adm_create(ptr, size, NULL, MMI_TRUE);
    if (NULL == mem_pool_id)
    {
        applib_mem_ap_free(ptr);
        ptr = NULL;
        goto MMI_EMAIL_APP_MEM_POOL_MALLOC_END;
    }

    mmi_email_app_mem_p->mem_ptr = ptr;
    mmi_email_app_mem_p->mem_adm_id = mem_pool_id;
    
MMI_EMAIL_APP_MEM_POOL_MALLOC_END:
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MEM_POOL_MALLOC, size, ptr);
    return ptr;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_mem_get_ptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void *mmi_email_app_mem_get_ptr(void)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MEM_GET_PTR, mmi_email_app_mem_p->mem_ptr);
    return mmi_email_app_mem_p->mem_ptr;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_mem_pool_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_email_app_mem_pool_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MEM_POOL_FREE, ptr, mmi_email_app_mem_p->mem_ptr);
    if ((NULL != ptr) && (ptr == mmi_email_app_mem_p->mem_ptr))
    {
        kal_adm_delete(mmi_email_app_mem_p->mem_adm_id);
        mmi_email_app_mem_p->mem_adm_id = NULL;

        applib_mem_ap_free(mmi_email_app_mem_p->mem_ptr);
        mmi_email_app_mem_p->mem_ptr = NULL;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_mem_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void *mmi_email_app_mem_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = kal_adm_alloc(mmi_email_app_mem_p->mem_adm_id, size);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MEM_MALLOC, size, ptr);
    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_mem_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_email_app_mem_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_MEM_FREE, mmi_email_app_mem_p->mem_adm_id, ptr);
    kal_adm_free(mmi_email_app_mem_p->mem_adm_id, ptr);
	return;
}
#endif /* __MMI_EMAIL__ */
