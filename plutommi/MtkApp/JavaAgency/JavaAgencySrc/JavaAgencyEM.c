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
 * JavaSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to handle all scenario of Java Content Manager and 
 *   interaction betweens MMI and Java task.
 *
 * Author:
 * -------
 * -------
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifdef __J2ME__
#include "MMI_include.h"

#include "JavaAgencyDef.h"
#include "JavaAgencyProt.h"
#include "JavaAgencyGProt.h"
#include "jal.h"
#include "jvm_adaptor.h"
#include "jam_interface.h"
#include "jam_msg_handler.h"

#include "CommonScreens.h"          /* DisplayPopup */

#include "EngineerModeUtil.h"
#include "EngineerModeCommUI.h"
#include "menucuigprot.h"

extern java_context_struct g_java;
extern kal_bool g_mmi_java_is_no_network_usable;

#ifdef KDWP_DEBUG
static const U16 g_mmi_java_em_kdwp_modes[] = {STR_GLOBAL_OFF, STR_JAVA_EM_KDWP_CATCHER_MODE, STR_JAVA_EM_KDWP_COMPORT_MODE};
extern kal_int32 g_jvm_debug_mode;
#endif
static mmi_id g_java_em_menu_id;


#ifdef __COSMOS_MMI_PACKAGE__
void mmi_java_em_dummy_entry(void)
{
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_set_mode_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_SET_MODE_REQ to MOD_J2ME
 *  to send TCK mode and set protocol event handler of  MSG_ID_MMI_JAVA_SET_MODE_CNF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_set_mode_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_set_mode_req_struct *msg;
    kal_int32 vm_id = 0;
#ifdef __COSMOS_MMI_PACKAGE__
    mmi_frm_asm_property_struct p;
#endif  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_SET_MODE_REQ);
    ClearInputEventHandler(MMI_DEVICE_ALL);

    msg = (mmi_java_set_mode_req_struct*) OslConstructDataPtr(sizeof(mmi_java_set_mode_req_struct));

    msg->java_mode = g_java.tck_index;
    msg->execute = (kal_bool)g_java.tck_execute;

#ifdef __COSMOS_MMI_PACKAGE__
    if(g_java.tck_execute && !mmi_frm_group_is_present(APP_JAVA))
    {
        mmi_frm_group_create_ex(GRP_ID_ROOT, APP_JAVA, NULL, NULL, 0);
        mmi_frm_scrn_enter(APP_JAVA, SCR_JAVA_DUMMY,NULL, mmi_java_em_dummy_entry, MMI_FRM_FULL_SCRN);
        ShowCategoryDummyScreen();
        mmi_frm_asm_property_init(&p);
        p.f_prepare_w_reserve = 1;
        mmi_frm_asm_set_property(APP_JAVA, &p);
    }
#endif

    g_mmi_java_is_no_network_usable = mmi_java_is_no_network_service();

    mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_SET_MODE_REQ, msg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_set_mode_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_SET_MODE_CNF from MOD_J2ME to
 *  go back to EM screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_set_mode_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_set_mode_cnf_struct *java_setmode_cnf_ptr;
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_SET_MODE_CNF);
    java_setmode_cnf_ptr = (mmi_java_set_mode_cnf_struct *)MsgStruct;
    ASSERT(java_setmode_cnf_ptr);
    if(java_setmode_cnf_ptr->error_code == J2ME_NO_ERROR)
    {
        jam_enter_screen(java_setmode_cnf_ptr->vm_id);
    }
    else
    {
        mmi_popup_property_init(&arg);
        arg.parent_id = GRP_ID_JAVA_EM;
        mmi_popup_display((UI_string_type)GetString(STR_GLOBAL_ERROR),MMI_EVENT_FAILURE,&arg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_tck_result_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_tck_result_ind(void* MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;
	
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
#ifdef J2ME_SLIM_MEMORY_SUPPORT
    mmi_frm_scrn_close(GRP_ID_JAVA_EM, SCR_JAVA_DUMMY);
#endif
    mmi_popup_property_init(&arg);
    arg.parent_id = GRP_ID_JAVA_EM;
    mmi_popup_display((UI_string_type)GetString(STR_GLOBAL_DONE),MMI_EVENT_SUCCESS,&arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_terminate_tck_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_terminate_tck_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_java.tck_execute = MMI_FALSE;
    /* SCR1251-Cannon+ */
    mmi_java_send_set_mode_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_execute_em_tck
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tck_index   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_execute_em_tck(U8 tck_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_java.tck_index = tck_index;
    g_java.tck_execute = MMI_TRUE;

#ifdef J2ME_SLIM_MEMORY_SUPPORT
    mmi_frm_group_close(mmi_em_get_root_group());

    mmi_frm_scrn_enter(GRP_ID_JAVA_EM, SCR_JAVA_DUMMY, NULL,NULL, MMI_FRM_FULL_SCRN);
#endif

    /* SCR1251-Cannon+ */
    mmi_java_send_set_mode_req();
}


#ifdef KDWP_DEBUG
/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_kdwp_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_kdwp_config(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_currlist_title_by_id(g_java_em_menu_id, STR_JAVA_EM_KDWP, mmi_java_get_title_icon());
    cui_menu_set_currlist_left_softkey_by_id(g_java_em_menu_id, g_mmi_java_em_kdwp_modes[g_jvm_debug_mode]);	
    cui_menu_set_item_hint(g_java_em_menu_id, MENU_ID_JAVA_EM_KDWP_MODE, (UI_string_type)GetString(g_mmi_java_em_kdwp_modes[g_jvm_debug_mode]));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_kdwp_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_em_kdwp_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (++g_jvm_debug_mode >= sizeof(g_mmi_java_em_kdwp_modes)/sizeof(g_mmi_java_em_kdwp_modes[0])) {
        g_jvm_debug_mode = 0;
    }

    cui_menu_change_left_softkey_string_by_id(g_java_em_menu_id, g_mmi_java_em_kdwp_modes[g_jvm_debug_mode]);
    cui_menu_set_item_hint(g_java_em_menu_id, MENU_ID_JAVA_EM_KDWP_MODE, (UI_string_type)GetString(g_mmi_java_em_kdwp_modes[g_jvm_debug_mode]));
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_java_em_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_java_em_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
#ifdef KDWP_DEBUG
                if (menu_evt->parent_menu_id == MENU_ID_JAVA_EM_TCK)
                {
                    cui_menu_set_non_leaf_item(g_java_em_menu_id, MENU_ID_JAVA_EM_KDWP, MMI_TRUE);
                }
                else if (menu_evt->parent_menu_id == MENU_ID_JAVA_EM_KDWP)
                {
                    mmi_java_entry_kdwp_config();
                }
#endif /* KDWP_DEBUG */
                break;
            }
        case EVT_ID_CUI_MENU_LIST_EXIT:
            {
                break;
            }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            {
                break;
            }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
            {
                if (menu_evt->highlighted_menu_id == MENU_ID_JAVA_EM_NORMAL)
                {
                    mmi_java_execute_em_tck(0);   /* JAVA_NORMAL_MODE */
                }
                else if (menu_evt->highlighted_menu_id == MENU_ID_JAVA_EM_CLDC_TCK)
                {
                    mmi_java_execute_em_tck(1);   /* JAVA_CLDC_TCK_MODE */
                }
                else if (menu_evt->highlighted_menu_id == MENU_ID_JAVA_EM_MIDP_TCK)
                {
                    mmi_java_execute_em_tck(2);   /* JAVA_MIDP_TCK_MODE */
                }
                else if (menu_evt->highlighted_menu_id == MENU_ID_JAVA_EM_WMAPI_TCK)
                {
                    mmi_java_execute_em_tck(3);   /* JAVA_WMA_TCK_MODE */
                }
                else if (menu_evt->highlighted_menu_id == MENU_ID_JAVA_EM_MMAPI_TCK)
                {
                    mmi_java_execute_em_tck(4);	  /* JAVA_MMAPI_TCK_MODE */
                }
#ifdef KDWP_DEBUG
                else if (menu_evt->highlighted_menu_id == MENU_ID_JAVA_EM_KDWP_MODE)
                {
                    mmi_java_em_kdwp_mode();
                }
#endif /* KDWP_DEBUG */
                break;
            }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                mmi_java_em_tck_close();
                break;
            }
        default:
            break;
	}
	
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_em_tck_list_entry
 * DESCRIPTION
 *  Main Menu->FunAndGames->Java->EngineerMode Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_em_tck_list_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_java_em_menu_id = cui_menu_create(GRP_ID_JAVA_EM, 
                                        CUI_MENU_SRC_TYPE_RESOURCE, 
                                        CUI_MENU_TYPE_APPSUB, 
                                        MENU_ID_JAVA_EM_TCK, 
                                        MMI_FALSE, NULL);

    cui_menu_set_default_title_by_id(g_java_em_menu_id, STR_JAVA_EM_TCK, mmi_java_get_title_icon());

    cui_menu_set_default_left_softkey_by_id(g_java_em_menu_id, STR_GLOBAL_OK);

    cui_menu_run(g_java_em_menu_id);

    mmi_java_load_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_em_warning_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_em_warning_back(void)
{
    mmi_frm_scrn_close(GRP_ID_JAVA_EM, SCR_JAVA_EM_TCK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_em_warning_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_em_warning_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
	
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    if (jam_vm_is_busy())
    {
        mmi_java_display_is_busy();
        return; /* drop the timealarm request */
    }
	
#ifdef J2ME_SLIM_MEMORY_SUPPORT
    mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_JAVA_EM, mmi_java_em_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
#else
    mmi_frm_group_create_ex(mmi_em_get_root_group(), GRP_ID_JAVA_EM, mmi_java_em_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
#endif

    if(!mmi_frm_scrn_enter(GRP_ID_JAVA_EM, SCR_JAVA_EM_TCK, NULL, mmi_java_em_warning_show, MMI_FRM_FG_ONLY_SCRN))
    {
        return;
    }

    guiBuffer = (U8*)(L"J2ME TCK is only for Java vendor, unexpected error may happen without connected Java TCK server. Do you want to continue?");
    ShowCategory74Screen(
        STR_JAVA_EM_TCK,
        mmi_java_get_install_title_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        guiBuffer,
        mmi_ucs2strlen((CHAR*) guiBuffer),
        NULL);
    SetLeftSoftkeyFunction(mmi_java_em_tck_list_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_java_em_warning_back, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_em_tck_enter
 * DESCRIPTION
 *  Main Menu->FunAndGames->Java->EngineerMode Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_em_tck_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_java_em_warning_show();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_em_tck_close
 * DESCRIPTION
 *  Main Menu->FunAndGames->Java->EngineerMode Exit Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_em_tck_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_close(g_java_em_menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_tck_is_execute
 * DESCRIPTION
 *  Main Menu->FunAndGames->Java->EngineerMode->Tck Exit Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_java_tck_is_execute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_java.tck_execute;
}
#endif /* __J2ME__ */ 

