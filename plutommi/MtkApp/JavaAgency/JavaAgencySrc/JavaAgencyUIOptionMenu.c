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
 *   JavaAgencyUIOptionMenu.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __J2ME__

#include "JavaAgencyUIOptionMenu.h"
#include "JavaAgencyUICommon.h"
#include "JavaAgencyDef.h"

#include "CommonScreens.h"
#include "CommonScreensResDef.h"
#include "wgui_categories_util.h"

#include "jam_internal.h"
#include "jui_interface.h"
#include "JavaAgencyGProt.h"

#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_java_srv.h"
#endif

extern void jvm_end_key_handler(void);

mmi_java_ui_option_menu_data_struct g_mmi_java_ui_option_menu;


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_option_menu_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_option_menu_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler((PsFuncPtr) mmi_java_ui_option_menu_show_req, MSG_ID_MMI_JAVA_UI_OPTION_MENU_SHOW_REQ);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_ui_option_menu_hide_req, MSG_ID_MMI_JAVA_UI_OPTION_MENU_HIDE_REQ);
    #ifdef __USE_JUI_POPUP__
    SetProtocolEventHandler((PsFuncPtr) mmi_java_ui_popup_show_req, MSG_ID_MMI_JAVA_UI_POPUP_SHOW_REQ);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_ui_popup_hide_req, MSG_ID_MMI_JAVA_UI_POPUP_HIDE_REQ);
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_option_menu_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_option_menu_highlight_handler(kal_int32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < 0)
        return;

    g_mmi_java_ui_option_menu.selected_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_option_menu_leftkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_option_menu_leftkey_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jui_widget_is_auto_back_from_mmi())
        GoBackHistory();

    jam_notify_vm();
    /* jui_widget_run_command(mmiapi_menu_ids[mmiapi_menu_index]); */

    jui_widget_mvm_fire_event_listener_void_int(
        g_mmi_java_ui_option_menu.vm_id,
        JUI_EVENT_RUN_COMMAND,
        g_mmi_java_ui_option_menu.command_id[g_mmi_java_ui_option_menu.selected_index]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_option_menu_rightkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_option_menu_rightkey_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();

    /* kal_trace(TRACE_STATE, FUNC_J2ME_JUI_SELECT_MENU_SHOW, mmiapi_menu_ids[mmiapi_menu_index],mmiapi_menu_index); */
    jam_notify_vm();
    /* jui_widget_run_command(-2); */
    jui_widget_mvm_fire_event_listener_void_int(
        g_mmi_java_ui_option_menu.vm_id,
        JUI_EVENT_RUN_COMMAND,
        JUI_EVENT_OPTION_MENU_CANCEL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_option_menu_endkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_option_menu_endkey_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_end_key_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_option_menu_exit_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_option_menu_exit_screen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_java_ui_option_menu.icons)
    {
        applib_mem_screen_free(g_mmi_java_ui_option_menu.icons);
        g_mmi_java_ui_option_menu.icons = NULL;
    }

    if (g_mmi_java_ui_option_menu.screen_disppear_callback != NULL)
        g_mmi_java_ui_option_menu.screen_disppear_callback(g_mmi_java_ui_option_menu.vm_id);

    jam_exit_fg_mmi_screen_callback(SCR_ID_JAVA_UI_OPTION_MENU, GetActiveScreenId(), NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_option_menu_entry_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_ui_option_menu_entry_screen()
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;
    kal_uint16 oldScreenId = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(
        GRP_ID_JAVA_APP,
        SCR_ID_JAVA_UI_OPTION_MENU,
        mmi_java_ui_option_menu_exit_screen,
        NULL,
        MMI_FRM_FULL_SCRN);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    g_mmi_java_ui_option_menu.icons =
        (U8 **) applib_mem_screen_alloc(g_mmi_java_ui_option_menu.command_num * sizeof(U8*));
    for (i = 0; i < g_mmi_java_ui_option_menu.command_num; i++)
    {
        g_mmi_java_ui_option_menu.icons[i] = (U8*) get_image(gIndexIconsImageList[i]);
    }

    RegisterHighlightHandler(mmi_java_ui_option_menu_highlight_handler);
    ShowCategory170Screen(
        (U8*) get_string(STR_GLOBAL_OPTIONS),
        (PU8) get_image(mmi_java_get_title_icon()),
        (U8*) get_string(STR_GLOBAL_OK),
        (U8*) get_image(IMG_GLOBAL_OK),
        (U8*) get_string(STR_GLOBAL_BACK),
        (U8*) get_image(IMG_GLOBAL_BACK),
        (S32) g_mmi_java_ui_option_menu.command_num,
        (U8 **) g_mmi_java_ui_option_menu.command_label,
        g_mmi_java_ui_option_menu.icons,
        0,
        0,
        NULL);
    SetLeftSoftkeyFunction(mmi_java_ui_option_menu_leftkey_handler, KEY_EVENT_UP);
    SetKeyHandler(mmi_java_ui_option_menu_leftkey_handler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(mmi_java_ui_option_menu_rightkey_handler, KEY_EVENT_UP);
    SetKeyHandler(mmi_java_ui_option_menu_rightkey_handler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetCenterSoftkeyFunction(mmi_java_ui_option_menu_leftkey_handler, KEY_EVENT_UP);

    SetKeyHandler(mmi_java_ui_option_menu_endkey_handler, KEY_END, KEY_EVENT_DOWN);

    jam_resume_fg_mmi_screen_callback(
        oldScreenId,
        SCR_ID_JAVA_UI_OPTION_MENU,
        MMI_JAVA_UI_SCREEN_TYPE_JAVA,
        MMI_JAVA_UI_SCREEN_TYPE_JAVA_MMI);
}


#ifdef __COSMOS_MMI_PACKAGE__

void vapp_java_ui_option_menu_exit_screen(void)
{
    mmi_frm_scrn_close(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_OPTION_MENU);
    
}

void vapp_java_ui_option_menu_entry_screen(void)
{
    mmi_frm_scrn_enter(
        GRP_ID_JAVA_APP,
        SCR_ID_JAVA_UI_OPTION_MENU,
		vapp_java_ui_option_menu_exit,
        NULL,
        MMI_FRM_FULL_SCRN);
    mmi_frm_scrn_clear_attribute(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_OPTION_MENU, MMI_SCRN_ATTRIB_ADD_HISTORY);
    vapp_java_ui_option_menu_launch(&g_mmi_java_ui_option_menu);
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_option_menu_show_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]         
 *  msg(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_option_menu_show_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 i;

    mmi_java_ui_option_menu_show_req_struct *msg = (mmi_java_ui_option_menu_show_req_struct*) msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);

    if (!jam_is_in_fg_screen(msg->vm_id))
        return;
    memset(&g_mmi_java_ui_option_menu, 0x00, sizeof(mmi_java_ui_option_menu_data_struct));
    if (msg->command_num > 0)
    {
        memcpy(g_mmi_java_ui_option_menu.command_id, msg->command_id, (msg->command_num) * sizeof(kal_int32));
        memcpy(
            g_mmi_java_ui_option_menu.command_label_length,
            msg->command_label_length,
            (msg->command_num) * sizeof(kal_int32));
    }
    for (i = 0; i < msg->command_num; i++)
    {
        /* memcpy(g_mmi_java_ui_option_menu.command_label[i],msg->command_label[i],(msg->command_label_length[i]) * sizeof(kal_uint16)); */
        g_mmi_java_ui_option_menu.command_label[i] = msg->command_label[i];
    }
    g_mmi_java_ui_option_menu.command_num = msg->command_num;
    g_mmi_java_ui_option_menu.selected_index = 0;
    g_mmi_java_ui_option_menu.vm_id = msg->vm_id;
    g_mmi_java_ui_option_menu.screen_disppear_callback = msg->screen_disppear_callback;

    if (jam_is_in_fg_screen(msg->vm_id))
    {
#ifndef __COSMOS_MMI_PACKAGE__
        mmi_java_ui_option_menu_entry_screen();
#else
        vapp_java_ui_option_menu_entry_screen();
#endif
    }

    if (msg->callback)
        msg->callback(msg->vm_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_option_menu_hide_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]         
 *  msg(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_option_menu_hide_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID screen_id;

    mmi_java_ui_option_menu_show_req_struct *msg = (mmi_java_ui_option_menu_show_req_struct*) msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);
    if(msg->vm_id == g_mmi_java_ui_option_menu.vm_id)
    {
#ifndef __COSMOS_MMI_PACKAGE__
        mmi_frm_scrn_close(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_OPTION_MENU);

        mmi_frm_get_active_scrn_id(&group_id, &screen_id);
        if (screen_id == SCR_ID_JAVA_UI_OPTION_MENU)
        {
            mmi_frm_scrn_close_active_id();

        }
#else
        vapp_java_ui_option_menu_hide(KAL_FALSE);
#endif
    }
    if (msg->callback)
        msg->callback(msg->vm_id);
}

#ifdef __USE_JUI_POPUP__
/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_popup_show_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]         
 *  msg(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_popup_show_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 i;

    mmi_java_ui_popup_show_req_struct *msg = (mmi_java_ui_popup_show_req_struct*) msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);

    if (!jam_is_in_fg_screen(msg->vm_id))
        return;
    memset(&g_mmi_java_ui_option_menu, 0x00, sizeof(mmi_java_ui_option_menu_data_struct));
    if (msg->command_num > 0)
    {
        memcpy(g_mmi_java_ui_option_menu.command_id, msg->command_id, (msg->command_num) * sizeof(kal_int32));
        memcpy(
            g_mmi_java_ui_option_menu.command_label_length,
            msg->command_label_length,
            (msg->command_num) * sizeof(kal_int32));
    }
    for (i = 0; i < msg->command_num; i++)
    {
        /* memcpy(g_mmi_java_ui_option_menu.command_label[i],msg->command_label[i],(msg->command_label_length[i]) * sizeof(kal_uint16)); */
        g_mmi_java_ui_option_menu.command_label[i] = msg->command_label[i];
    }
    g_mmi_java_ui_option_menu.command_num = msg->command_num;
    g_mmi_java_ui_option_menu.selected_index = 0;
    g_mmi_java_ui_option_menu.vm_id = msg->vm_id;
    g_mmi_java_ui_option_menu.screen_disppear_callback = msg->screen_disppear_callback;

    if (jam_is_in_fg_screen(msg->vm_id))
    {
        mmi_java_ui_option_menu_entry_screen();
    }

    if (msg->callback)
        msg->callback(msg->vm_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_popup_hide_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]         
 *  msg(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_popup_hide_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID screen_id;

    mmi_java_ui_popup_show_req_struct *msg = (mmi_java_ui_popup_show_req_struct*) msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);
    if(msg->vm_id == g_mmi_java_ui_option_menu.vm_id)
    {
        mmi_frm_scrn_close(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_OPTION_MENU);

        mmi_frm_get_active_scrn_id(&group_id, &screen_id);
        if (screen_id == SCR_ID_JAVA_UI_OPTION_MENU)
        {
            mmi_frm_scrn_close_active_id();
        }
    }

    if (msg->callback)
        msg->callback(msg->vm_id);

}
#endif
#endif /* __J2ME__ */ 

