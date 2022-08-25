/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  IdleSwatch.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the Swatch IDLE, for idle framework to call.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"


/****************************************************************************
 * Include
 ****************************************************************************/

#if defined(__MMI_WEARABLE_DEVICE__)

#include "MMIDataType.h"
#include "gui_typedef.h"
#include "mmi_common_app_trc.h"
#include "IdleCommon.h"
#include "IdleSwatch.h"
#include "SwatchGProt.h"




/****************************************************************************
 * Function
 ****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_on_want_to_run
 * DESCRIPTION
 *  This function checks the swatch idle wants to run.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_idle_swatch_on_want_to_run(void)
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
 *  mmi_idle_swatch_on_enter
 * DESCRIPTION
 *  This function is the enter function.
 * PARAMETERS
 *  obj             : [IN]          Idle object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_on_enter(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_swatch_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (mmi_idle_swatch_struct *)obj;
   
    mmi_idle_swatch_enter(p->this_gid);
    
    /* Key handler: */
    mmi_idle_set_handler((mmi_idle_obj_struct *)p);

    ClearKeyEvents();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_on_exit
 * DESCRIPTION
 *  This function is the exit function.
 * PARAMETERS
 *  obj             : [IN]          Idle object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_on_exit(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_idle_swatch_exit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_on_init
 * DESCRIPTION
 *  This function initializes the idle object.
 * PARAMETERS
 *  obj           : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_swatch_on_init(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_swatch_struct *p;
    //mmi_idle_capability_struct *capability;
    U32 *capability;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_on_init(obj);

    p = (mmi_idle_swatch_struct *)obj;

    /* Member variable. */
    p->type = MMI_IDLE_TYPE_SWATCH;

    /* Member function. */
    p->on_enter = mmi_idle_swatch_on_enter;
    p->on_exit = mmi_idle_swatch_on_exit;

    /* Change the capabilities. */
    capability = &obj->capability;
    *capability &= ~ENABLE_SOFT_KEY_AREA;
    *capability &= ~ENABLE_CENTER_SOFT_KEY;  
    *capability &= ~ENABLE_LEFT_SOFT_KEY; 
    *capability &= ~ENABLE_RIGHT_SOFT_KEY; 
    *capability &= ~ENABLE_NAVIGATION_KEY;
#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
	if (mmi_frm_kbd_is_key_supported(KEY_POWER) == MMI_TRUE)
	{
		*capability &= ~ENABLE_END_KEY;
	}
#endif
}

#endif /* defined(__MMI_WEARABLE_DEVICE__) */


