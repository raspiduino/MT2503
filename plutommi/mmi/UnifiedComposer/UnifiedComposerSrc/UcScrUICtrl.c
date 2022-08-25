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
 * UcScrUICtrl.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements generic handling of screen controler, resource controller, Db handling, key handling for Unified Composer application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_TELEPHONY_SUPPORT__

#ifndef _UNIFIED_COMPOSER_SCR_UI_CTRL_C
#define _UNIFIED_COMPOSER_SCR_UI_CTRL_C

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

//#include "Custom_events_notify.h"

//#include "AlarmFrameworkProt.h"
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#include "Wgui_icon_bar.h"
#endif
#include "wapadp.h"
//#include "UmGprot.h"
#ifdef __MMI_MMS_2__
#include "MmsSrvGprot.h"
#endif
#include "UcResDef.h"
#include "UcAppGprot.h"
#include "FileMgr.h"
#include "FileMgrGProt.h"
#include "UcAppProt.h"
#include "UcScrUIProt.h"
#include "UcScrUIDb.h"
//suggested add
    #include "MMI_features.h"
    #include "MMIDataType.h"
   // #include "kal_general_types.h"
    #include "mmi_frm_mem_gprot.h"
    //#include "kal_public_api.h"

/***************************************************************************** 
* Define
*****************************************************************************/
mmi_uc_frm_screen_context g_uc_frm_screen_cntx[MAX_UC_SCREENS_AT_ONE_FLOW];

/****************************************************************************
* Constants
*****************************************************************************/
/****************************************************************************
 * Type definitions
 ****************************************************************************/
/***************************************************************************** 
* Extern Function
*****************************************************************************/
extern void mmi_frm_highlight_input_method_generic(void);

/***************************************************************************** 
* Local static Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/*-------------------------------cntrlr-------------------------------------*/

/* when data comes to data handler */


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_cntrlr_screen_render_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_cntrlr_screen_render_start(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_uc_frm_cntrlr_pre_func(instance_hash_id);
    if (result == MMI_UC_ASYNC_WAIT)
    {
        mmi_uc_frm_cntrlr_screen_render_start(MMI_UC_FLOW_INSTANCE_ID_PROCESSING);
        return;
    }
    mmi_uc_frm_cntrlr_create_func(instance_hash_id);
    mmi_uc_frm_cntrlr_show_func(instance_hash_id);
    mmi_uc_frm_cntrlr_post_func(instance_hash_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_cntrlr_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_uc_frm_result_enum mmi_uc_frm_cntrlr_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_UC_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_cntrlr_create_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_uc_frm_result_enum mmi_uc_frm_cntrlr_create_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_UC_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_cntrlr_show_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_uc_frm_result_enum mmi_uc_frm_cntrlr_show_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_sh_init_function(instance_hash_id);
    return MMI_UC_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_cntrlr_post_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_uc_frm_result_enum mmi_uc_frm_cntrlr_post_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_UC_TRUE;
}

/***********************************screen-DB*********************/
/*
 * mmi_uc_frm_cntrlr_struct* mmi_uc_frm_get_cntrlr_resource(U16 instance_hash_id)
 * {
 * U8 index = g_uc_frm_screenDB[instance_hash_id].scrn_id - UNIFIED_COMPOSER_BASE;
 * 
 * return &g_uc_frm_cntrlrDB[index];
 * }
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_get_screenDB
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const mmi_uc_frm_screenDB_struct *mmi_uc_frm_get_screenDB(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_uc_frm_screenDB[instance_hash_id];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_get_resourceDB
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const mmi_uc_frm_resourceDB_struct *mmi_uc_frm_get_resourceDB(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_uc_frm_resourceDB[instance_hash_id];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_generic_default_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_generic_default_data(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_generic_data_default_ready_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_generic_data_default_ready_check(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}

/***********************************screen-handling********************/


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_sh_init_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_sh_init_function(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    const mmi_uc_frm_screenDB_struct *ScrDB = mmi_uc_frm_get_screenDB(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ScrDB->create_func(instance_hash_id);
    ScrDB->pre_func(instance_hash_id);
    ScrDB->draw_func(instance_hash_id);
    ScrDB->post_func(instance_hash_id);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_sh_create_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_sh_create_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_sh_dummy_history_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_sh_dummy_history_func(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_sh_get_scr_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_uc_frm_sh_get_scr_context(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MAX_UC_SCREENS_AT_ONE_FLOW; index++)
    {
        if (g_uc_frm_screen_cntx[index].instance_flow_hash_id == instance_hash_id)
        {
            return g_uc_frm_screen_cntx[index].scr_data;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_sh_set_screen_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 *  data                    [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_sh_set_screen_context(U16 instance_hash_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MAX_UC_SCREENS_AT_ONE_FLOW; index++)
    {
        if (g_uc_frm_screen_cntx[index].instance_flow_hash_id == 0)
        {
            g_uc_frm_screen_cntx[index].instance_flow_hash_id = instance_hash_id;
            g_uc_frm_screen_cntx[index].scr_id = scrDB->scrn_id;
            g_uc_frm_screen_cntx[index].scr_data = data;
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_sh_delete_screen_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_sh_delete_screen_context(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MAX_UC_SCREENS_AT_ONE_FLOW; index++)
    {
        if (g_uc_frm_screen_cntx[index].instance_flow_hash_id == instance_hash_id)
        {
            g_uc_frm_screen_cntx[index].instance_flow_hash_id = 0;
            g_uc_frm_screen_cntx[index].scr_id = 0;
            if (g_uc_frm_screen_cntx[index].scr_data != NULL)
            {
                OslMfree(g_uc_frm_screen_cntx[index].scr_data);
                g_uc_frm_screen_cntx[index].scr_data = NULL;
            }
            break;
        }
    }
}

#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */ 
#endif /* _UNIFIED_COMPOSER_SCR_UI_CTRL_C */ 

#endif /* __MMI_TELEPHONY_SUPPORT__ */
