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

/*******************************************************************************
 * Filename:
 * ---------
 *  Sample_Memory.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Sample code for ASM and ADM
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

#include "APPSDKFrameworkGProt.h"
#include "APPSDKSystemServiceGProt.h"

#include "CommonScreens.h"
#include "DevAppDef.h"
#include "GlobalResDef.h"

#define MMI_SAMPLE_MEMORY_ASM_BUFFER_SIZE   100 * 1024  /* 100K */
#define MMI_SAMPLE_MEMORY_BLOCK_BUFFER_SIZE 1024        /* 1K */

static void mmi_sample_mem_entry_scr_base_asm_screen(void);
static void mmi_sample_mem_exit_scr_base_asm_screen(void);
static void mmi_sample_mem_entry_app_base_asm_screen(void);
static void mmi_sample_mem_exit_app_base_asm_screen(void);
static void *mmi_sample_mem_app_base_asm_alloc(kal_uint32 mem_size);
static void mmi_sample_mem_app_base_asm_free(void *mem_ptr);
static void mmi_sample_mem_app_base_asm_stop_callback(void);
static void mmi_sample_mem_app_base_asm_success_callback(void);

/****************************************************************************
*
*  [Sample]
*  Purpose  : Get and free screen-based memory.
*
*  Function : Get memory in the 'entry function' -- mmi_sample_mem_entry_scr_base_asm_screen(), and
*           free the memory in the 'exit function' -- mmi_sample_mem_exit_scr_base_asm_screen().
*
*  Notice 1  : This memory can only be allocated within a screen's scope.
*           We usually allocate when enter screen, and must free it when exit screen.
*  Notice 2  : To use this memory, we need to add our upper bound to ScrMemMgr.h.
*           We may be able to expand the upper bound if we having plutommi source code.
*  Notice 3  : From the beginning of MT6235/38/39, GDI layer framebuffer must use  
*           non-cached RAM buffer with special handling. Otherwise,  ASSERT.
*           So, we provide the following New API for allocating layer framebuffer:
*             applib_mem_screen_alloc_framebuffer()
*           When we want to allocate a buffer to create layers, we should use this API
*           instead of applib_mem_screen_alloc().
*
*  Branch   : 08A, 08B, MAUI
*
*  API Ref  : applib_mem_screen_alloc()
*             applib_mem_screen_free() 
*  
*
*****************************************************************************/

/* Pointer of screen-based memory */
static S8 *g_sample_scr_mem_p;


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_mem_entry_scr_base_asm_screen
 * DESCRIPTION
 *  entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_mem_entry_scr_base_asm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    mmi_frm_scrn_enter(
        GRP_ID_DEVAPP, 
        SCR_ID_DEVAPP_MAIN, 
        mmi_sample_mem_exit_scr_base_asm_screen, 
        mmi_sample_mem_entry_scr_base_asm_screen, 
        MMI_FRM_FULL_SCRN);
#endif

    /* allocate memory */
    g_sample_scr_mem_p = (S8*) applib_mem_screen_alloc(MMI_SAMPLE_MEMORY_ASM_BUFFER_SIZE);

    if (g_sample_scr_mem_p == NULL)
    {
        /* 
         * We can't 100% gaurantee to get buffer from screen memory manager.
         * Add assert to find the problem, or add some error handling 
         */

        ASSERT(0);
    }

    /* 
     * g_sample_scr_mem_p manipluate
     * ...
     * ..
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_mem_exit_scr_base_asm_screen
 * DESCRIPTION
 *  exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_mem_exit_scr_base_asm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free memory */
    applib_mem_screen_free(g_sample_scr_mem_p);
    g_sample_scr_mem_p = NULL;
}

/****************************************************************************
*
*  [Sample]
*  Purpose  : Get app-based memory, and manage the memory by ADM.
*
*  Function : Get memory in the 'entry function' -- mmi_sample_mem_entry_app_base_asm_screen(),
*           and free the memory in the 'exit function' -- mmi_sample_mem_exit_app_base_asm_screen(). 
*           In addition, we need to register two callback functions. One is used by applib  
*           to free APP-Based Memory, and the other one is used by applib when getting memory successfully.
*
*  Notice 1   : To use the app-based memory, we need to add our upper bound to
*            App_mem_config.h, and add our APP ID to App_mem.h.
*  Notice 2   : From the beginning of MT6235/38/39, GDI layer framebuffer must use  
*           non-cached RAM buffer with special handling. Otherwise,  ASSERT.
*           So, we provide the following New APIs for allocating layer framebuffer:
*             applib_mem_ap_alloc_framebuffer()
*             MMI_FRM_ADM_ALLOC_FRAMEBUFFER()
*           When we want to allocate a buffer to create layers, we should use applib_mem_ap_alloc_framebuffer()
*           instead of applib_mem_screen_alloc(), and use MMI_FRM_ADM_ALLOC_FRAMEBUFFER() instead of
*           kal_adm_alloc().
*
*  Branch   : 08A, 08B, MAUI
*
*  API Ref  : applib_mem_ap_register()
*             applib_mem_ap_notify_stop_finished()
*             applib_mem_ap_alloc() 
*             mmi_frm_appmem_prompt_to_release_mem()
*             applib_mem_ap_free() 
*             kal_adm_create()
*             kal_adm_alloc()
*             kal_adm_free() 
*             kal_adm_delete()
*  
*
*****************************************************************************/

/* Pointer of app-based memory */
static S8 *g_sample_app_mem_p;

/* ID of ADM pool */
static KAL_ADM_ID g_sample_adm_pool_id;

/* Pointer of memory allocated from the ADM pool */
static S8 *g_sample_from_adm_pool_p;


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_mem_entry_app_base_asm_screen
 * DESCRIPTION
 *  entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_mem_entry_app_base_asm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* allocate memory from App-Based ASM */
    g_sample_app_mem_p = (S8*) mmi_sample_mem_app_base_asm_alloc(MMI_SAMPLE_MEMORY_ASM_BUFFER_SIZE);

    if (g_sample_scr_mem_p == NULL)
    {
        return;
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    mmi_frm_scrn_enter(
        GRP_ID_DEVAPP, 
        SCR_ID_DEVAPP_MAIN, 
        mmi_sample_mem_exit_app_base_asm_screen, 
        mmi_sample_mem_entry_app_base_asm_screen, 
        MMI_FRM_FULL_SCRN);
#endif

    /* We can manage the allocated memory by ADM as below. */

    /* Create ADM pool with the ASM address acquired */
    if (g_sample_app_mem_p != NULL)
    {
        g_sample_adm_pool_id = kal_adm_create((void*)g_sample_app_mem_p, MMI_SAMPLE_MEMORY_ASM_BUFFER_SIZE, NULL, KAL_FALSE);
        ASSERT(g_sample_adm_pool_id != NULL);
    }

    /* Get a memory block */
    g_sample_from_adm_pool_p = kal_adm_alloc(g_sample_adm_pool_id, MMI_SAMPLE_MEMORY_BLOCK_BUFFER_SIZE);

    /* 
     * g_sample_from_adm_pool_p manipluate
     * ...
     * ..
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_mem_exit_app_base_asm_screen
 * DESCRIPTION
 *  exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_mem_exit_app_base_asm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_status ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free allocated ADM pool memory */
    if (g_sample_from_adm_pool_p != NULL)
    {
        kal_adm_free(g_sample_adm_pool_id, (void*)g_sample_from_adm_pool_p);
        g_sample_from_adm_pool_p = NULL;
    }

    /* delete ADM */
    if (g_sample_adm_pool_id != NULL)
    {
        ret = kal_adm_delete(g_sample_adm_pool_id);

        ASSERT(ret == KAL_SUCCESS);
        g_sample_adm_pool_id = NULL;
    }

    /* Free the app-based ASM buffer */
    mmi_sample_mem_app_base_asm_free(g_sample_app_mem_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_mem_app_base_asm_alloc
 * DESCRIPTION
 *  Get app-based memory.
 * PARAMETERS
 *  mem_size        [IN]        Memory size
 * RETURNS
 *  Allocated memory block.
 *****************************************************************************/
static void *mmi_sample_mem_app_base_asm_alloc(kal_uint32 mem_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *app_base_asm_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* allocate memory from App-Based ASM */
    if (app_base_asm_p == NULL)
    {
        /* register application that uses app-based ASM, and this function should be used when an application is initialized at boot. */
        applib_mem_ap_register(
            APPLIB_MEM_AP_ID_VS_TEST,                   /* Application ID defined in applib_mem_ap_id_enum. Here is an example */
            STR_GLOBAL_1,                               /* The MMI string ID of application name */
            IMG_GLOBAL_L1,                              /* Application ID defined in applib_mem_ap_id_enum */
            mmi_sample_mem_app_base_asm_stop_callback); /* Callback function when user chooses to stop the application */

        /* allocate memory */
        app_base_asm_p = (S8*) applib_mem_ap_alloc(APPLIB_MEM_AP_ID_VS_TEST, mem_size);

        if (app_base_asm_p == NULL)
        {
            /* 
             * We can't 100% gaurantee to get buffer from app memory manager.
             * Add following function to show "out-of-memory" screen and prompt 
             * user to stop other applications in order to release more memory.
             */

            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_VS_TEST,
                0,
                mem_size,
                mmi_sample_mem_app_base_asm_success_callback);
            return NULL;
        }
    }

    return app_base_asm_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_mem_app_base_asm_free
 * DESCRIPTION
 *  Free allocated app-based memory.
 * PARAMETERS
 *  mem_ptr     [IN]        Memory block to be released
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_mem_app_base_asm_free(void *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free the app-based ASM buffer */
    if (mem_ptr != NULL)
    {
        applib_mem_ap_free((void*)mem_ptr);
        mem_ptr = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_mem_app_base_asm_stop_callback
 * DESCRIPTION
 *  Callback function used by applib to free APP-Based Memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_mem_app_base_asm_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free memory */
    mmi_sample_mem_exit_app_base_asm_screen();
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VS_TEST, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_mem_app_base_asm_success_callback
 * DESCRIPTION
 *  Callback function when getting memory successfully.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_mem_app_base_asm_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* allocate memory */
    g_sample_app_mem_p = (S8*) applib_mem_ap_alloc(APPLIB_MEM_AP_ID_VS_TEST, MMI_SAMPLE_MEMORY_ASM_BUFFER_SIZE);
    ASSERT(g_sample_app_mem_p != NULL); /* It should provide enough memory */
    mmi_sample_mem_entry_app_base_asm_screen();
}

