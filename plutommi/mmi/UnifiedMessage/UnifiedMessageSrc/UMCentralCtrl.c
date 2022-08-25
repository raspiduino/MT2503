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
 * UMCentralCtrl.c
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
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __UM_SUPPORT__
#include "UMDefs.h"
#include "UMProt.h"
#include "UMSrvGprot.h"
#include "SimCtrlSrvGprot.h" /* mmi_um_ui_cc_sim_ctrl_unavailable_hdlr */
#include "mmi_rp_app_unifiedmessage_def.h" /* mmi_um_ui_cc_sim_ctrl_available_hdlr */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "string.h"
#include "GlobalResDef.h"
#include "kal_public_api.h"
#include "mmi_frm_scenario_gprot.h"
#include "UmSrvDefs.h"
#include "mmi_common_app_trc.h"
#include "ModeSwitchSrvGprot.h" /* srv_mode_switch_is_network_service_available */
#include "NetSetAppGprot.h"
#include "NwUsabSrvGprot.h"
#include "SettingResDef.h" /* SCR9000_SETTINGS */
#include "CustMenuRes.h"
#include "SatSrvGprot.h"

#ifdef __MMI_BT_MAP_CLIENT__
extern MMI_BOOL g_um_is_new_group;
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_create_scrn_cntx
 * DESCRIPTION
 *  It is used to create the screen context in global screen table
 *
 * PARAMETERS
 *  setting                 [IN]: setting for screen context
 *  init                    [IN]: the initialize function for 
 *                                FSM, Screen handler, Appearance
 *
 * RETURNS
 *  MMI_TRUE: Create successfully
 *  MMI_FALSE: Create fail(The screen table is full)
 *****************************************************************************/
MMI_BOOL mmi_um_ui_cc_create_scrn_cntx(
                    mmi_um_ui_cc_scrn_cntx_setting_struct *setting, 
                    scrn_init_func init)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID int_grp_id;
    MMI_ID root_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_cc_grp_cntx_struct *grp_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CC_CREATE_SCRN_CNTX, setting->scrn_id);
    
    scrn_cntx = mmi_um_ui_cc_get_free_scrn_cntx();

    if (scrn_cntx == NULL)
    {
        return MMI_FALSE;
    }

    memset(scrn_cntx, 0, sizeof(mmi_um_ui_cc_scrn_cntx_struct));
    int_grp_id = root_grp_id = GRP_ID_INVALID;

    if (MMI_TRUE == setting->new_grp)
    {
        /* create a new root group for message application */
        #ifdef __MMI_BT_MAP_CLIENT__
        g_sms_um_ui_main_menu_scrn_id = 0;
        #endif
        grp_cntx = mmi_um_ui_cc_get_free_grp_cntx();
        MMI_ASSERT(NULL != grp_cntx);
        root_grp_id = mmi_frm_group_create(
                        setting->parent_group_id, 
                        GRP_ID_AUTO_GEN, 
                        NULL, 
                        (void*) grp_cntx);
        mmi_frm_group_enter(root_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        grp_cntx->root_grp_id = root_grp_id;

        /* create a internal group for UM app */

    #ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
        int_grp_id = mmi_frm_group_create(
                        root_grp_id, 
                        GRP_ID_UM_ROOT, 
                        mmi_um_ui_cc_grp_proc, 
                        (void*) grp_cntx);
    #else
        int_grp_id = mmi_frm_group_create(
                        root_grp_id, 
                        GRP_ID_AUTO_GEN, 
                        mmi_um_ui_cc_grp_proc, 
                        (void*) grp_cntx);
    #endif
        mmi_frm_group_enter(int_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        grp_cntx->grp_id = int_grp_id;
        g_um_ui_p->cc_cntx.num_of_grp++;
    }
    else
    {
        /* no need to create new group */
        int_grp_id = setting->parent_group_id;
    }
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CC_GROUP_CNTX, root_grp_id, int_grp_id, setting->new_grp);
    /* set the group id */
    scrn_cntx->group_id = int_grp_id;

    scrn_cntx->scrn_id = setting->scrn_id;
    scrn_cntx->parent_scrn_id = setting->parent_scrn_id;
    scrn_cntx->event_hdlr = setting->event_hdlr;

    init(scrn_cntx, setting);

    g_um_ui_p->cc_cntx.num_of_scrn++;

#ifdef __MMI_BT_MAP_CLIENT__
    if (g_um_is_entry_main_menu || g_um_is_new_group)
    {
        g_um_is_new_group = MMI_FALSE;
        mmi_sms_bt_app_set_cntx(g_um_ui_p);
    }
#endif

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_send_event
 * DESCRIPTION
 *  Send the speficied event to screen id. If the screen_id is equal to 0, it
 *  will send the event to all existed screens. Currently, it does not allow
 *  event handler return MMI_FALSE.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the speficied screen id
 *  event               [IN]: the event enum
 *  arg                 [IN]: the event argument
 *
 * RETURNS
 *  MMI_TRUE: send event successfully
 *  MMI_FALSE: send event failed
 *****************************************************************************/
MMI_BOOL mmi_um_ui_cc_send_event(U16 scrn_id, mmi_um_ui_event_enum event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CC_SEND_EVENT, scrn_id, event);

    if (g_um_ui_p->cc_cntx.num_of_scrn == 0)
    {
        return MMI_TRUE;
    }

    /* Broadcast the event to all existed screens */
    if (scrn_id == 0)
    {
        for (i = 0; i < MMI_UM_UI_MAX_SCRN_CNTX_NUM; i++)
        {
            if (g_um_ui_p->cc_cntx.scrn_table[i].scrn_id != 0)
            {
                scrn_id = g_um_ui_p->cc_cntx.scrn_table[i].scrn_id;
                result = g_um_ui_p->cc_cntx.scrn_table[i].event_hdlr(scrn_id, (U16)event, arg);
                if (result == MMI_FALSE)
                {
                    MMI_ASSERT(0);
                    return result;
                }
            }
        }

        return MMI_TRUE;
    }

    /* find the specified screen id */
    for (i = 0; i < MMI_UM_UI_MAX_SCRN_CNTX_NUM; i++)
    {
        if (g_um_ui_p->cc_cntx.scrn_table[i].scrn_id == scrn_id)
        {
            break;
        }
    }

    /* could not find the specified screen id */
    if (i == MMI_UM_UI_MAX_SCRN_CNTX_NUM)
    {
        return MMI_FALSE;
    }

    result = g_um_ui_p->cc_cntx.scrn_table[i].event_hdlr(scrn_id, (U16)event, arg);

    if (result == MMI_FALSE)
    {
        MMI_ASSERT(0);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_scrn_cntx_struct
 * DESCRIPTION
 *  Get the screen context from the central controller
 *
 * PARAMETERS
 *  scrn_id             [IN]: the speficied screen id
 *
 * RETURNS
 *  The pointer of screen context
 *****************************************************************************/
mmi_um_ui_cc_scrn_cntx_struct *mmi_um_ui_cc_get_scrn_cntx(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = NULL;
    for (i = 0; i < MMI_UM_UI_MAX_SCRN_CNTX_NUM; i++)
    {
        if (scrn_id == g_um_ui_p->cc_cntx.scrn_table[i].scrn_id)
        {
            scrn_cntx = &(g_um_ui_p->cc_cntx.scrn_table[i]);
            break;
        }
    }

    return scrn_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_get_parent_scrn_id
 * DESCRIPTION
 *  Get the parent screen id.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the current screen id
 *
 * RETURNS
 *  Parent screen id
 *****************************************************************************/
U16 mmi_um_ui_cc_get_parent_scrn_id(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);

    if (NULL == scrn_cntx)
    {
        /* No finding any screen context */
        return 0;
    }

    return scrn_cntx->parent_scrn_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_get_child_scrn_id
 * DESCRIPTION
 *  Get the child screen id.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the current screen id
 *
 * RETURNS
 *  Child screen id
 *****************************************************************************/
U16 mmi_um_ui_cc_get_child_scrn_id(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);

    if (NULL == scrn_cntx)
    {
        /* No finding any screen context */
        return 0;
    }

    return scrn_cntx->child_scrn_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_check_scrn_alive
 * DESCRIPTION
 *  check the screen is alive in the screen table.
 *
 * PARAMETERS
 *
 * RETURNS
 *  MMI_TRUE: the screen exists in the table.
 *  MMI_FLASE: the screen does not exist in the table.
 *****************************************************************************/
MMI_BOOL mmi_um_ui_cc_check_scrn_alive(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_FALSE;

    /* No child screen */
    if (scrn_id == 0)
    {
        return result;
    }
    
    for (i = 0; i < MMI_UM_UI_MAX_SCRN_CNTX_NUM ; i++)
    {
        /* hit */
        if (g_um_ui_p->cc_cntx.scrn_table[i].scrn_id == scrn_id)
        {
            result = MMI_TRUE;
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_delete_scrn_cntx
 * DESCRIPTION
 *  check the screen is alive in the screen table.
 *
 * PARAMETERS
 *  scrn_id             [IN]: Deleted screen id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_cc_delete_scrn_cntx(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);

    if (scrn_cntx == NULL)
    {
        return;
    }

    memset(scrn_cntx, 0, sizeof(mmi_um_ui_cc_scrn_cntx_struct));
    
    g_um_ui_p->cc_cntx.num_of_scrn--;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_get_free_scrn_cntx
 * DESCRIPTION
 *  Get the availabe screen context from table
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mmi_um_ui_cc_scrn_cntx_struct* mmi_um_ui_cc_get_free_scrn_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = NULL;
    for (i = 0; i < MMI_UM_UI_MAX_SCRN_CNTX_NUM; i++)
    {
        if (g_um_ui_p->cc_cntx.scrn_table[i].scrn_id == 0)
        {
            scrn_cntx = &g_um_ui_p->cc_cntx.scrn_table[i];
            return scrn_cntx;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_delete_all_scrn
 * DESCRIPTION
 *  Delete all screen in the screen table
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_cc_delete_all_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0 ; i < MMI_UM_UI_MAX_SCRN_CNTX_NUM ; i++)
    {
        if (g_um_ui_p->cc_cntx.scrn_table[i].scrn_id > 0)
        {
            result = mmi_um_ui_cc_send_event(g_um_ui_p->cc_cntx.scrn_table[i].scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
            MMI_ASSERT(result == MMI_TRUE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_get_support_msg_type_by_scrn_id
 * DESCRIPTION
 *  Get the support message type based on screen id
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  Supported message type
 *****************************************************************************/
srv_um_msg_enum mmi_um_ui_cc_get_support_msg_type_by_scrn_id(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    srv_um_msg_enum support_msg_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    support_msg_type = SRV_UM_MSG_NONE;
    
    for (i = 0 ; i < MMI_UM_UI_MAX_SCRN_CNTX_NUM ; i++)
    {
        if (g_um_ui_p->cc_cntx.scrn_table[i].scrn_id == scrn_id)
        {
            break;
        }
    }

    if (i == MMI_UM_UI_MAX_SCRN_CNTX_NUM)
    {
        return support_msg_type;
    }

    support_msg_type = g_um_ui_p->cc_cntx.scrn_table[i].screen_hdlr.folder_type.msg_type;
    
    return support_msg_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_get_disp_scrn_id
 * DESCRIPTION
 *  Get displayed screen id by the input screen id.
 *
 * PARAMETERS
 *  scrn_id:            [IN]    input screen id
 *
 * RETURNS
 *  Diplayed screen id(framework-based)
 *****************************************************************************/
U16 mmi_um_ui_cc_get_disp_scrn_id(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);

    if (scrn_cntx == NULL)
    {
        return 0;
    }

    return scrn_cntx->screen_hdlr.disp_scrn_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_get_grp_id
 * DESCRIPTION
 *  Get screen group id by the input screen id.
 *
 * PARAMETERS
 *  scrn_id:            [IN]    input screen id
 *
 * RETURNS
 *  Screen group id(framework-based)
 *****************************************************************************/
U16 mmi_um_ui_cc_get_grp_id(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);

    if (scrn_cntx == NULL)
    {
        return 0;
    }

    return scrn_cntx->group_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_get_scrn_id_by_box_type
 * DESCRIPTION
 *  Get scrn id by message box type.
 *
 * PARAMETERS
 *  box_type:           [IN]    Message box type
 *
 * RETURNS
 *  Screen id
 *****************************************************************************/
U16 mmi_um_ui_cc_get_scrn_id_by_box_type(srv_um_msg_box_enum box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = NULL;
    for (i = 0; i < MMI_UM_UI_MAX_SCRN_CNTX_NUM; i++)
    {
        if (g_um_ui_p->cc_cntx.scrn_table[i].screen_hdlr.folder_type.msg_box_type == box_type)
        {
            scrn_cntx = &g_um_ui_p->cc_cntx.scrn_table[i];
            return scrn_cntx->scrn_id;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_get_free_grp_cntx
 * DESCRIPTION
 *  Get the availabe group context from table
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mmi_um_ui_cc_grp_cntx_struct *mmi_um_ui_cc_get_free_grp_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    mmi_um_ui_cc_grp_cntx_struct *grp_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_cntx = NULL;

    for (i = 0; i < MMI_UM_UI_MAX_GRP_CNTX_NUM; i++)
    {
        if (g_um_ui_p->cc_cntx.grp_table[i].grp_id == 0)
        {
            grp_cntx = &g_um_ui_p->cc_cntx.grp_table[i];
            break;
        }
    }

    return grp_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_del_grp_cntx
 * DESCRIPTION
 *  Delete the group context
 *
 * PARAMETERS
 *  grp_cntx            [IN]: The pointer of group context
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_cc_del_grp_cntx(mmi_um_ui_cc_grp_cntx_struct *grp_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(grp_cntx, 0, sizeof(mmi_um_ui_cc_grp_cntx_struct));
    grp_cntx->grp_id = GRP_ID_INVALID;
    g_um_ui_p->cc_cntx.num_of_grp--;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_grp_proc
 * DESCRIPTION
 *  Screen group proc of Centraol controller.
 *  It needs to handle the SG event like Delete/goback history.
 *
 * PARAMETERS
 *  evt                 [IN]: event structure pointer
 *  
 * RETURNS
 *  MMI_RET_OK: process successfully
 *  Others: process fail
 *****************************************************************************/
mmi_ret mmi_um_ui_cc_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;
    mmi_um_ui_cc_grp_cntx_struct *grp_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_cntx = (mmi_um_ui_cc_grp_cntx_struct *)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
        {
            break;
        }
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_um_ui_cc_del_grp_cntx(grp_cntx);
            break;
        }
        default:
        {
            break;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_get_grp_num
 * DESCRIPTION
 *  Get the number of screen group in the UM app.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  The number of group.
 *****************************************************************************/
U16 mmi_um_ui_cc_get_grp_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 num_of_grp = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_UM_UI_MAX_GRP_CNTX_NUM; i++)
    {
        if (g_um_ui_p->cc_cntx.grp_table[i].grp_id != GRP_ID_INVALID)
        {
            num_of_grp++;
        }
    }

    return num_of_grp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_destroy_all_grp
 * DESCRIPTION
 *  Destroy all screen group in the UM app.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  The destroy result
 *****************************************************************************/
mmi_ret mmi_um_ui_cc_destroy_all_grp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_UM_UI_MAX_GRP_CNTX_NUM; i++)
    {
        if (g_um_ui_p->cc_cntx.grp_table[i].grp_id != GRP_ID_INVALID)
        {
            /* call framework api to destroy, destroy the root group id */
            ret = mmi_frm_group_close(g_um_ui_p->cc_cntx.grp_table[i].root_grp_id);
            if (MMI_RET_OK != ret)
            {
                return ret;
            }
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_get_root_grp_id
 * DESCRIPTION
 *  Get the root of gruop id.
 *
 * PARAMETERS
 *  group_id            [IN]: UM internal group id
 *  
 * RETURNS
 *  The message root group id
 *****************************************************************************/
MMI_ID mmi_um_ui_cc_get_root_grp_id(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    MMI_ID root_grp_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_UM_UI_MAX_GRP_CNTX_NUM; i++)
    {
        if (g_um_ui_p->cc_cntx.grp_table[i].grp_id == group_id)
        {
            root_grp_id = g_um_ui_p->cc_cntx.grp_table[i].root_grp_id;
            break;
        }
    }

    return root_grp_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_get_active_scrn_msg_box
 * DESCRIPTION
 *  Get the message box type of current active screen instance. If there is
 *  no any instance or no screen is active, it returns SRV_UM_MSG_BOX_NONE.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  The active screen's message box type
 *****************************************************************************/
srv_um_msg_box_enum mmi_um_ui_cc_get_active_scrn_msg_box(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    srv_um_msg_box_enum active_scrn_box_type = SRV_UM_MSG_BOX_NONE;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_UM_UI_MAX_SCRN_CNTX_NUM; i++)
    {
        scrn_cntx = &(g_um_ui_p->cc_cntx.scrn_table[i]);
        /* has instance & active */
        if (0 != scrn_cntx->scrn_id &&
            MMI_SCENARIO_STATE_ACTIVE == mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
        {
            active_scrn_box_type = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
            break;
        }
    }

    return active_scrn_box_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_sim_ctrl_unavailable_hdlr
 * DESCRIPTION
 *  Handler function for sim control unavailable. If sim card is unavailable, 
 *  UM should close message group in order to avoid some unexpected problem.
 *
 * PARAMETERS
 *  evt             [IN]: event sent from sim control.
 *  
 * RETURNS
 *  MMI_RET_OK if handling successfully
 *****************************************************************************/
mmi_ret mmi_um_ui_cc_sim_ctrl_unavailable_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;
#ifdef __MMI_SIMAP_SUPPORT__
    srv_sim_ctrl_unavailable_evt_struct *sim_ctrl_evt;
#endif /* __MMI_SIMAP_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SIMAP_SUPPORT__
    sim_ctrl_evt = (srv_sim_ctrl_unavailable_evt_struct *)evt;
    /* If it is BT access SIM1 profile */
    if (SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE == srv_sim_ctrl_get_unavailable_cause(MMI_SIM1) &&
        MMI_SIM1 == sim_ctrl_evt->sim)
    {
        /* check UM's group status */
        if (mmi_um_ui_cc_get_grp_num() > 0)
        {
            mmi_um_ui_cc_destroy_all_grp();
        }
    }
#endif /* __MMI_SIMAP_SUPPORT__ */
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_sim_ctrl_available_hdlr
 * DESCRIPTION
 *  Handler function for sim control available. 
 *  Special case:
 *      1) BT connects sim1 card and cause the messaging main menu only last 
 *         email menu item
 *      2) BT disconnects sim1 card and release the sim control but sim card
 *         is still not available
 *      3) entry messaging quickly and see only email exist
 *      4) sim card is available and it should update the main menu as normal
 *         mode
 *  It is the special case and handler to handle this kind of case. After the
 *  bootupmenu control revised, this function may be removed.
 *
 * PARAMETERS
 *  evt             [IN]: event sent from sim control.
 *  
 * RETURNS
 *  MMI_RET_OK if handling successfully
 *****************************************************************************/
mmi_ret mmi_um_ui_cc_sim_ctrl_available_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;
#ifdef __MMI_SIMAP_SUPPORT__
    U16 grp_id;
    srv_sim_ctrl_available_evt_struct *sim_ctrl_evt;
#endif /* __MMI_SIMAP_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SIMAP_SUPPORT__
    sim_ctrl_evt = (srv_sim_ctrl_available_evt_struct *)evt;
    /* If it is BT access SIM1 profile */
    if (SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE == sim_ctrl_evt->ua_cause_before &&
        MMI_SIM1 == sim_ctrl_evt->sim)
    {
        /* check UM's group status */
        if (mmi_um_ui_cc_get_grp_num() > 0)
        {
            /* get the gruop id */
            grp_id = mmi_um_ui_cc_get_grp_id(SCR_ID_UM_MAIN_MESSAGE);
            /* Entry dummy then delete it */
            if (MMI_SCENARIO_STATE_ACTIVE == mmi_frm_scrn_get_state(grp_id, SCR_ID_UM_MAIN_MESSAGE))
            {
                /* Entry dummy then goback history */
                mmi_frm_display_dummy_screen();
                mmi_frm_scrn_close_active_id();
            }
        }
    }
#endif /* __MMI_SIMAP_SUPPORT__ */
    
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_cc_sim_status_hdlr
 * DESCRIPTION
 *  Handler function for EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED and 
 *  EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY
 *  Just find the screen context of main msg and 
 *  call mmi_um_ui_sh_main_msg_arrange_menu_item to show/hide items
 *
 * PARAMETERS
 *  evt             [IN]: event sent from sim control.
 *  
 * RETURNS
 *  MMI_RET_OK if handling successfully
 *****************************************************************************/
mmi_ret mmi_um_ui_cc_sim_status_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;
    U16 active_scr_id;
    srv_sim_ctrl_availability_changed_evt_struct * sim_evt =
        (srv_sim_ctrl_availability_changed_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_evt->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE
        || sim_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE
        || sim_evt->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED
        || sim_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED
#if (defined(__SIM_RECOVERY_ENHANCEMENT__))
        || sim_evt->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_RECOVERY
        || sim_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_RECOVERY
#endif
        )
    {
    	  mmi_um_ui_cc_destroy_all_grp();
    }
    else 
  	{
		    active_scr_id = mmi_frm_scrn_get_active_id();
		    if (SCR_ID_UM_MAIN_MESSAGE == active_scr_id || SCR9000_SETTINGS == active_scr_id)
		    {
                mmi_frm_display_dummy_screen();
		        mmi_frm_scrn_close_active_id();
		    }
    } 
    return ret;
}

mmi_ret mmi_um_ui_cc_mode_switch_status_hdlr(mmi_event_struct *evt)
{
    mmi_ret ret = MMI_RET_OK;
    U16 active_scr_id;
    active_scr_id=mmi_frm_scrn_get_active_id();
    if((active_scr_id == SCR_ID_UM_MAIN_MESSAGE) || (SCR9000_SETTINGS == active_scr_id))
    {
        mmi_frm_display_dummy_screen();
		mmi_frm_scrn_close_active_id();
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_sim_refresh_event_hdlr
 * DESCRIPTION
 *  Handler function for sim refresh by SAT application. If sms is busy reading message from 
 *  sim card UM should close message group in order to avoid some unexpected problem.
 *
 * PARAMETERS
 *  evt             [IN]: event sent from SAT application.
 *  
 * RETURNS
 *  MMI_RET_OK if handling successfully
 *****************************************************************************/
MMI_RET mmi_um_sim_refresh_event_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_sat_sim_refresh_event_struct *event_data = (srv_sat_sim_refresh_event_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if((event_data->full_change) ||
		(event_data->refresh_type == SRV_SAT_REFRESH_FILE_CHANGE))
	{
		/* check UM's group status */
        if (mmi_um_ui_cc_get_grp_num() > 0)
        {
            mmi_um_ui_cc_destroy_all_grp();
        }
	}
	return MMI_RET_OK;
}
#endif /* __UM_SUPPORT__ */
