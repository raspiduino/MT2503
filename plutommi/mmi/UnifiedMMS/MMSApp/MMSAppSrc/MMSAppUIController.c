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
 * MMSAppUIController.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * 
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
// #include "MMI_include.h"
#include "MMI_features.h"
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
#ifdef __MMI_MMS_2__
#include "Fs_type.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_sms_def.h"
#include "MMSAppResDef.h"
#include "MMSAppUIController.h"
#include "MMSAppUICommon.h"
#include "MMSAppDataManager.h"
//#include "mmsadp.h"
//#include "wap_ps_struct.h"
//#include "custom_wap_config.h"
//#include "mmsadp.h"
//#include "mmi_rp_app_umms_mms_def.h"
//#include "inlineCuiGprot.h"
#include "MMSAppResourceCntrlDB.h"
// #include "MMSMemoryManagerSrv.h"
#include "MMSAppScrHdlrEx.h"
// #include "MessagesResourceData.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_cntrlr_screen_render_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_cntrlr_screen_render_start(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_UMMS_ERROR result = MMI_UMMS_FALSE;
    const mmi_umms_app_cntrlr_struct *cntrlr_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntrlr_cntx = mmi_umms_app_resource_get_cntrlrDB(scr_id);

    if (cntrlr_cntx == NULL)
    {
        result = MMI_UMMS_FALSE;
        goto END;
    }

    if (cntrlr_cntx->pre_func)
    {
        result = cntrlr_cntx->pre_func(scr_id);
    }

    if (result == MMI_UMMS_FALSE)
    {
        goto END;
    }
    if (result == MMI_UMMS_ASYNC_WAIT)
    {
        U16 scr_id =
            (mmi_umms_dtmgr_get_group_id() ==
             GRP_ID_UMMS_LIST_TEMPLATES) ? SCR_ID_UMMS_PROGRESS_TMPLT : SCR_ID_UMMS_PROGRESS;
        if(scr_id == SCR_ID_UMMS_PROGRESS)
        {
        mmi_umms_app_dtmgr_set_progress_scrn_data(STR_MMS_MENUENTRY, STR_GLOBAL_PLEASE_WAIT);
        }
        mmi_umms_app_cntrlr_screen_render_start(scr_id);
        result = MMI_UMMS_TRUE;
        goto END;
    }

    if (cntrlr_cntx->create_func)
    {
        cntrlr_cntx->create_func(scr_id);
    }

    if (cntrlr_cntx->show_func)
    {
        cntrlr_cntx->show_func(scr_id);
        result = MMI_UMMS_FALSE;
        goto END;
    }

    if (cntrlr_cntx->post_func)
    {
        cntrlr_cntx->post_func(scr_id);
    }

    result = MMI_UMMS_TRUE;

  END:
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_cntrlr_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_cntrlr_pre_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_UMMS_ERROR error, result = MMI_UMMS_FALSE;
    const mmi_umms_app_cntrlr_struct *cntrlr_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntrlr_cntx = mmi_umms_app_resource_get_cntrlrDB(scr_id);

    if (cntrlr_cntx == NULL)
    {
        result = MMI_UMMS_FALSE;
        goto END;
    }

    if (cntrlr_cntx->data_ready_func)
    {
        error = cntrlr_cntx->data_ready_func(scr_id);
        if (!error)
        {
            if (cntrlr_cntx->get_async_func)
            {
                error = cntrlr_cntx->get_async_func(scr_id);
                if (error == MMI_UMMS_FALSE)
                {
                    result = MMI_UMMS_FALSE;
                }
                else
                {
                    result = MMI_UMMS_ASYNC_WAIT;
                }
            }
        }
        else
        {
            if (error == MMI_UMMS_SYNC_FAIL)
            {
                result = MMI_UMMS_FALSE;
            }
            else
            {
                result = MMI_UMMS_TRUE;
            }
        }
    }

  END:
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_template_cntrlr_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_template_cntrlr_pre_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_UMMS_ERROR result = MMI_UMMS_FALSE;
    const mmi_umms_app_cntrlr_struct *cntrlr_cntx;
    MMI_UMMS_ERROR check_state = MMI_UMMS_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntrlr_cntx = mmi_umms_app_resource_get_cntrlrDB(scr_id);
    if (cntrlr_cntx == NULL)
    {
        result = MMI_UMMS_FALSE;
        goto END;
    }

    if (cntrlr_cntx->data_ready_func)
    {
        if (!cntrlr_cntx->data_ready_func(scr_id))
        {
            if (cntrlr_cntx->get_async_func)
            {
                check_state = cntrlr_cntx->get_async_func(scr_id);
                if (check_state == MMI_UMMS_FALSE)
                {
                    result = MMI_UMMS_FALSE;
                    goto END;
                }
                else
                {
                    result = MMI_UMMS_ASYNC_WAIT;
                }
            }
        }
        else
        {
            result = MMI_UMMS_TRUE;
        }
    }

  END:
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_cntrlr_create_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_cntrlr_create_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_cntrlr_show_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_cntrlr_show_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_sh_init_function(scr_id);
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_cntrlr_post_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_cntrlr_post_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_cntrl_get_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_cntrl_get_info(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_cntrl_check_data_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_cntrl_check_data_ready(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_UMMS_TRUE;
}

#endif /* __MMI_MMS_2__ */ 

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 

