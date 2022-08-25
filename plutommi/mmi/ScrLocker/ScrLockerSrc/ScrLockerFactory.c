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
 *  ScrLockerFactory.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the factory of the screen locker.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"

#include "MMIDataType.h"
#include "ScrLockerFactory.h"
#include "ScrLockerGprot.h"
#include "ScrLockerClassic.h"
#include "ScrLockerObject.h"
#include "kal_public_api.h"
#include "mmi_frm_mem_gprot.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "ScrLockerLawmo.h"
#include "ScrLockerShell.h"
#include "ScrLockerFancy.h"
#include "ScrlockerScreenLockKey.h"

#include "MMI_ap_dcm_config.h"
#ifdef __MMI_AP_DCM_SCRLOCK__
#pragma arm section rodata = "DYNAMIC_CODE_SCRLOCK_RODATA" , code = "DYNAMIC_CODE_SCRLOCK_ROCODE"
#endif

/****************************************************************************
 * Global Context
 ****************************************************************************/

const static mmi_factory_cfg_struct g_mmi_slk_cfg_tbl[] =
{
#if defined(__DM_LAWMO_SUPPORT__)
    MMI_FACTORY_CFG_ADD(
        MMI_SCR_LOCKER_TYPE_LAWMO,
        sizeof(mmi_slk_lawmo_struct),
        mmi_slk_lawmo_on_want_to_run,
        mmi_slk_lawmo_on_init,
        mmi_slk_obj_on_deinit),
#endif /* defined(__DM_LAWMO_SUPPORT__) */

#if defined(__MMI_VUI_SCREEN_LOCK_KEY__)
    MMI_FACTORY_CFG_ADD(
        MMI_SCR_LOCKER_TYPE_SCRLOCK_KEY,
        sizeof(mmi_slk_scrlock_key_struct),
        mmi_slk_obj_on_want_to_run,
        mmi_slk_scrlock_key_on_init,
        mmi_slk_obj_on_deinit),
#endif

#if defined(__MMI_VUI_SHELL_SCREEN_LOCK__)
    MMI_FACTORY_CFG_ADD(
        MMI_SCR_LOCKER_TYPE_SHELL,
        sizeof(mmi_slk_shell_struct),
        mmi_slk_obj_on_want_to_run,
        mmi_slk_shell_on_init,
        mmi_slk_obj_on_deinit),
#endif /* defined(__MMI_VUI_SHELL_SCREEN_LOCK__) */
    
#if defined(__MMI_LAUNCHER_APP_LIST__)
    MMI_FACTORY_CFG_ADD(
        MMI_SCR_LOCKER_TYPE_FANCY,
        sizeof(mmi_slk_fancy_struct),
        mmi_slk_obj_on_want_to_run,
        mmi_slk_fancy_on_init,
        mmi_slk_obj_on_deinit),
#endif

#if defined(__MMI_SCREEN_LOCK_CLASSIC__)
    MMI_FACTORY_CFG_ADD(
        MMI_SCR_LOCKER_TYPE_CLASSIC,
        sizeof(mmi_slk_classic_struct),
        mmi_slk_obj_on_want_to_run,
        mmi_slk_classic_on_init,
        mmi_slk_obj_on_deinit),
#endif

    MMI_FACTORY_CFG_END()
};


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_slk_get_cfg_table
 * DESCRIPTION
 *  This function gets the scr locker configure table.
 * PARAMETERS
 *  void
 * RETURNS
 *  Idle type.
 *****************************************************************************/
const mmi_factory_cfg_struct *mmi_slk_get_cfg_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_slk_cfg_tbl;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_buffer_malloc
 * DESCRIPTION
 *  This function is used to allocate slk buffer
 * 
 * PARAMETERS
 *  size        : [IN]  buffer size
 *  arg         : [IN]  argument for malloc
 * RETURNS
 *  the address of Idle buffer
 *****************************************************************************/
void *mmi_slk_buffer_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_malloc(size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_buffer_free
 * DESCRIPTION
 *  This function is used to free slk buffer
 * 
 * PARAMETERS
 *  p        : [IN]  the buffer pointer
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_slk_buffer_free(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mfree(p);
}

#ifdef __MMI_AP_DCM_SCRLOCK__
#pragma arm section rodata , code
#endif

