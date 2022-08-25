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
 *  IdleFactory.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the factory of the idle object.
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
#include "IdleFactory.h"
#include "IdleGprot.h"
#include "IdleClassic.h"
#include "IdleObject.h"
#include "kal_public_api.h"
#include "mmi_frm_mem_gprot.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#if 0
/* under construction !*/
/* under construction !*/
#endif
#include "IdleShell.h"
#include "IdleLauncher.h"
#include "IdleLauncherKey.h"
#include "FactoryGprot.h"
#if defined(__MMI_WEARABLE_DEVICE__)
#include "IdleSwatch.h"
#endif  //defined(__MMI_WEARABLE_DEVICE__)
#if defined(__MMI_LAUNCHER_APP_LIST__)
#include "IdleAppList.h"
#endif


/****************************************************************************
 * Define
 ****************************************************************************/

/* This table registers the size of idle context */
typedef union
{
#if 0
#if defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
#endif /* defined(__MMI_OP11_HOMESCREEN__) */
/* under construction !*/
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
#endif

#if defined(__MMI_WEARABLE_DEVICE__)
    U8 IDLE_SWATCH_STRUCT[sizeof(mmi_idle_swatch_struct)];
#endif  //defined(__MMI_WEARABLE_DEVICE__)

#if defined(__MMI_LAUNCHER_APP_LIST__)
    U8 IDLE_APPLIST_STRUCT[sizeof(mmi_idle_applist_struct)];
#endif

#if 0
#if defined(__MMI_VUI_SHELL_APP__)
/* under construction !*/
#endif /* defined(__MMI_VUI_SHELL_APP__) */
#endif

#if defined(__MMI_VUI_LAUNCHER_KEY__)
    U8 IDLE_KEYLAUNCHER_STRUCT[sizeof(mmi_idle_keylauncher_struct)];
#endif /* defined(__MMI_VUI_LAUNCHER_KEY__) */

#if defined(__MMI_VUI_LAUNCHER__)
    U8 IDLE_LAUNCHER_STRUCT[sizeof(mmi_idle_launcher_struct)];
#endif /* defined(__MMI_VUI_LAUNCHER__) */

#if defined(__MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__)
    U8 IDLE_CLASSIC_STRUCT[sizeof(mmi_idle_classic_struct)];
#endif /*__MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__*/

} mmi_idle_context_struct_union;

#define MMI_IDLE_CONTEXT_SIZE   sizeof(mmi_idle_context_struct_union)
U8 g_mmi_idle_context[MMI_IDLE_CONTEXT_SIZE+3];


/****************************************************************************
 * Global Context
 ****************************************************************************/

/* This table registers the idle object. */
const static mmi_factory_cfg_struct g_mmi_idle_cfg_tbl[] =
{
#if 0
#if defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP11_HOMESCREEN__) */
/* under construction !*/
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
#endif

#if defined(__MMI_WEARABLE_DEVICE__)
    MMI_FACTORY_CFG_ADD(
        MMI_IDLE_TYPE_SWATCH,
        sizeof(mmi_idle_swatch_struct),
        mmi_idle_swatch_on_want_to_run,
        (mmi_factory_on_init_cb)mmi_idle_swatch_on_init,
        (mmi_factory_on_deinit_cb)mmi_idle_obj_on_deinit),
#endif  //defined(__MMI_WEARABLE_DEVICE__)

#if defined(__MMI_LAUNCHER_APP_LIST__)
    MMI_FACTORY_CFG_ADD(
        MMI_IDLE_TYPE_APPLIST,
        sizeof(mmi_idle_applist_struct),
        mmi_idle_applist_on_want_to_run,
        (mmi_factory_on_init_cb)mmi_idle_applist_on_init,
        (mmi_factory_on_deinit_cb)mmi_idle_obj_on_deinit),
#endif

#if defined(__MMI_VUI_LAUNCHER_KEY__)
    MMI_FACTORY_CFG_ADD(
        MMI_IDLE_TYPE_KEYLAUNCHER,
        sizeof(mmi_idle_keylauncher_struct),
        mmi_idle_keylauncher_on_want_to_run,
        (mmi_factory_on_init_cb)mmi_idle_keylauncher_on_init,
        (mmi_factory_on_deinit_cb)mmi_idle_obj_on_deinit),
#endif /* defined(__MMI_VUI_LAUNCHER_KEY__) */

#if 0
#if defined(__MMI_VUI_SHELL_APP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_VUI_SHELL_APP__) */
#endif

#if defined(__MMI_VUI_LAUNCHER__)
    MMI_FACTORY_CFG_ADD(
        MMI_IDLE_TYPE_LAUNCHER,
        sizeof(mmi_idle_launcher_struct),
        mmi_idle_obj_on_want_to_run,
        (mmi_factory_on_init_cb)mmi_idle_launcher_on_init,
        (mmi_factory_on_deinit_cb)mmi_idle_obj_on_deinit),
#endif /* defined(__MMI_VUI_LAUNCHER__) */

#ifdef __MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__
    MMI_FACTORY_CFG_ADD(
        MMI_IDLE_TYPE_CLASSIC,
        sizeof(mmi_idle_classic_struct),
        mmi_idle_obj_on_want_to_run,
        (mmi_factory_on_init_cb)mmi_idle_classic_on_init,
        (mmi_factory_on_deinit_cb)mmi_idle_obj_on_deinit),
#endif

    MMI_FACTORY_CFG_END()
};


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_cfg_table
 * DESCRIPTION
 *  This function gets the idle configure table.
 * PARAMETERS
 *  void
 * RETURNS
 *  Idle type.
 *****************************************************************************/
const mmi_factory_cfg_struct *mmi_idle_get_cfg_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_idle_cfg_tbl;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_buffer_malloc
 * DESCRIPTION
 *  This function is used to allocate idle buffer.
 * PARAMETERS
 *  size        : [IN]  buffer size
 * RETURNS
 *  the address of Idle buffer
 *****************************************************************************/
void *mmi_idle_buffer_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* must ensure 4-byte alignment here*/
    buf = (U8 *)(((U32)g_mmi_idle_context + 3) >> (2) << (2));
    memset( buf, 0, sizeof(mmi_idle_context_struct_union) );
    return buf;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_buffer_free
 * DESCRIPTION
 *  This function is used to free idle buffer.
 * PARAMETERS
 *  p        : [IN]  the buffer pointer
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_idle_buffer_free(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
}
