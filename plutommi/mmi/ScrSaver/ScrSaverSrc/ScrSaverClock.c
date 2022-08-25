/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  ScrSaverClock.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the clock screen saver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_SCREEN_SAVER__)
#if defined(__MMI_ANALOG_CLOCK__) || defined(__MMI_DIGITAL_CLOCK__)

#include "WPSSProtos.h"

// TODO: phase-out this. (for DIGITAL_SCREEN_SAVER)
#include "IdleAppDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "ScrSaverClock.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_clock.h"
#include "ScrSaverObject.h"
#include "mmi_rp_app_scr_saver_def.h"
#include "wgui_categories_list.h"
#include "ScrSaverGprot.h"


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_clock_enter
 * DESCRIPTION
 *  This function is the enter function
 * PARAMETERS
 *  param           : [IN]          Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ssv_clock_enter(mmi_scrn_essential_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ssv_clock_struct *p;
    U16 ssv_id;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param && param->user_data);

    ret = mmi_frm_scrn_enter(
            param->group_id,
            param->scrn_id,
            NULL,
            NULL,
            MMI_FRM_FULL_SCRN);

    if (!ret)
    {
        return;
    }

    p = (mmi_ssv_clock_struct *)param->user_data;

    PhnsetGetCurScrSvr(&ssv_id);

    if (PhnsetIsScrSvrAnalogClock())
    {
        ShowCategory131Screen(ssv_id, ANALOG_SCREEN_SAVER, NULL);
    }
    else if (PhnsetIsScrSvrDigitalClock())
    {
        ShowCategory131Screen(ssv_id, DIGITAL_SCREEN_SAVER, NULL);
    }

    mmi_ssv_obj_set_handler((mmi_ssv_obj_struct *)p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_clock_on_run
 * DESCRIPTION
 *  This function runs the screen saver.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ssv_clock_on_run(mmi_ssv_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ssv_obj_on_run(obj);

    mmi_frm_group_enter(obj->this_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        obj->this_gid,
        SCR_ID_SSV_MAIN,
        (FuncPtr)mmi_ssv_clock_enter,
        obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_clock_on_want_to_run
 * DESCRIPTION
 *  This function checks if the screen saver wants to run.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_ssv_clock_on_want_to_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Ask parent.
     */
    if (!mmi_ssv_obj_on_want_to_run())
    {
        return MMI_FALSE;
    }

    if (!PhnsetIsScrSvrAnalogClock() && !PhnsetIsScrSvrDigitalClock())
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_clock_on_init
 * DESCRIPTION
 *  This function initializes the screen saver object.
 * PARAMETERS
 *  obj             : [IN]      Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssv_clock_on_init(mmi_ssv_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ssv_clock_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ssv_obj_on_init(obj);

    p = (mmi_ssv_clock_struct *)obj;

    /* Member variable. */
    p->type = MMI_SCR_SAVER_TYPE_CLOCK;

    /* Member function. */
    p->on_run = mmi_ssv_clock_on_run;
}

#endif /* defined(__MMI_ANALOG_CLOCK__) || defined(__MMI_DIGITAL_CLOCK__) */
#endif /* defined(__MMI_SCREEN_SAVER__) */

