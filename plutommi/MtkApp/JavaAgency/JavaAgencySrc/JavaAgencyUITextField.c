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
 *   JavaAgencyUITextField.c
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
 * JavaAgencyTextField.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to implement MMI style TextField editor
 *
 * Author:
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifdef __J2ME__

#include "mmi_include.h"

#include "CommonScreens.h"

/* added for phone book */
#ifndef __COSMOS_MMI_PACKAGE__
#include "PhbCuiGprot.h"
#else
#include "vcui_phb_gprot.h"
#endif

#include "PhbSrvGprot.h"
/* added for phone book end */
#include "FSEditorCuiGprot.h"   /* added for editor cui */

#include "JavaAgencyUITextField.h"
#include "JavaAgencyUICommon.h"
#include "JavaAgencyGProt.h"
#include "JavaAgencyDef.h"

#include "mmi_rp_app_java_def.h"        /* string Id */

#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_java_srv.h"
#endif

static void mmi_java_ui_textfield_enter(void);
static mmi_ret mmi_java_ui_textfield_proc(mmi_event_struct *evt);

MMI_ID mmi_java_ui_textfield_phone_numer_id;
MMI_ID mmi_java_ui_textfield_phone_number_group_id;

static MMI_ID mmi_java_ui_textfield_editor_id = GRP_ID_INVALID;
static MMI_ID mmi_java_ui_textfield_editor_group_id = GRP_ID_INVALID;

static kal_bool mmi_java_ui_textfield_search_flag = KAL_FALSE;
static kal_bool mmi_java_ui_textfield_active = KAL_FALSE;

/* Java JTWI spec */
static const U8 *JTWISymbol[5] = 
{
    (U8 *) "\x5e\0\0",  /* circumflex accent */
    (U8 *) "\x60\0\0",  /* grave acent */
    (U8 *) "\x7c\0\0",  /* vertical bar */
    (U8 *) "\xa1\0\0",  /* inverted exclamation */
    (U8 *) "\xbf\0\0",  /* inverted question mark */
};

static mmi_java_ui_textfield_data_struct g_mmi_java_ui_textfield;

static kal_int32 mmi_java_ui_textfield_add_extra_symbol(
                    kal_uint8 *out,
                    kal_int32 out_max,
                    kal_uint8 **in,
                    kal_int32 in_max);
static kal_bool mmi_java_ui_textfield_is_need_add_extra_symbol(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textfield_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_textfield_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler((PsFuncPtr) mmi_java_ui_textfield_show_req, MSG_ID_MMI_JAVA_UI_TEXTFIELD_SHOW_REQ);
    /* SetProtocolEventHandler((PsFuncPtr) mmi_java_ui_textfield_hide_req, MSG_ID_MMI_JAVA_UI_TEXTFIELD_HIDE_REQ); */

    mmi_java_ui_common_register_is_need_add_extra_symbol_callback(mmi_java_ui_textfield_is_need_add_extra_symbol);
    mmi_java_ui_common_register_add_extra_symbol_callback(mmi_java_ui_textfield_add_extra_symbol);
}



#ifdef __COSMOS_MMI_PACKAGE__

extern void jvm_home_key_handler(void);
extern void jvm_end_key_handler(void);
extern void vapp_java_ui_textfield_exit(void);

void vapp_java_ui_textfield_backkey_handler(void)
{
    vapp_java_ui_textfield_hide();
}
void mmi_java_ui_textfield_exit_screen(MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //vapp_java_ui_textfield_exit();
    
    mmi_frm_get_active_scrn_id(&group_id, &screen_id);

    mmi_frm_scrn_close(GRP_ID_JAVA_APP, scrn_id);

    /*if (screen_id == scrn_id)
    {
        mmi_frm_scrn_close_active_id();
    }*/
}

void vapp_java_ui_exit_textfield(void)
{
    mmi_java_ui_textfield_active = KAL_FALSE;
    vapp_java_ui_textfield_exit();
}


void vapp_java_ui_entry_textfield(void)
{
    mmi_frm_scrn_enter(
        GRP_ID_JAVA_APP,
        SCR_ID_JAVA_UI_TEXTFIELD_EDITOR,
        vapp_java_ui_exit_textfield,
        vapp_java_ui_entry_textfield,
        MMI_FRM_FULL_SCRN);
    SetKeyHandler(jvm_home_key_handler, KEY_HOME, KEY_EVENT_DOWN);
    SetKeyHandler(vapp_java_ui_textfield_backkey_handler, KEY_BACK, KEY_EVENT_DOWN);
	SetKeyHandler(jvm_end_key_handler, KEY_END, KEY_EVENT_DOWN);
    vapp_java_ui_textfield_launch(&g_mmi_java_ui_textfield);
    mmi_java_ui_textfield_active = KAL_TRUE;
}

#ifndef J2ME_SLIM_MEMORY_SUPPORT
void mmi_java_ui_textfield_delete_phb_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_java_ui_textfield_phone_number_group_id != GRP_ID_INVALID)
    {
        mmi_frm_group_close(mmi_java_ui_textfield_phone_number_group_id);
        mmi_java_ui_textfield_phone_number_group_id = GRP_ID_INVALID;
    }

}


mmi_ret mmi_java_ui_textfield_set_number(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_node_struct  scrn_node_info;
    vcui_phb_list_result_event_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
        case EVT_ID_GROUP_INACTIVE:
            break;

        case EVT_ID_GROUP_ACTIVE:
            break;

        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
            break;

        case EVT_ID_GROUP_DEINIT:
            break;
        case EVT_ID_CUI_PHB_LIST_RESULT:
            result = (vcui_phb_list_result_event_struct*) evt;
            if (result->result && result->select_count == 1)
            {
                vcui_phb_list_get_selected_contact_data(
                    mmi_java_ui_textfield_phone_numer_id,
                    g_mmi_java_ui_textfield.text,
                    g_mmi_java_ui_textfield.max_size - 1);
                
            }
            scrn_node_info.id = SCR_ID_JAVA_UI_TEXTBOX_EDITOR;
            scrn_node_info.entry_proc = &vapp_java_ui_entry_textfield;
            mmi_frm_scrn_replace(
                GRP_ID_JAVA_APP,
                SCR_ID_JAVA_UI_TEXTBOX_EDITOR,
                &scrn_node_info);
            vcui_phb_list_close(mmi_java_ui_textfield_phone_numer_id);
            mmi_java_ui_textfield_phone_number_group_id = GRP_ID_INVALID;
            break;

        case EVT_ID_ASM_FORCE_FREE:
            vcui_phb_list_close(mmi_java_ui_textfield_phone_numer_id);
            mmi_java_ui_textfield_phone_number_group_id = GRP_ID_INVALID;
            break;
        default:
            break;
    }

    return MMI_RET_OK;
}


mmi_ret mmi_java_ui_textfield_set_number_prepare_proc(mmi_frm_asm_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_ASM_CANCELED:
            break;
        case EVT_ID_ASM_PREPARED:
            mmi_java_ui_textfield_phone_numer_id = vcui_phb_list_create(VAPP_JAVA_TEXTBOX);
	
			vcui_phb_list_set_drag_ncenter_flag(mmi_java_ui_textfield_phone_numer_id, MMI_FALSE);
            vcui_phb_list_set_req_type(mmi_java_ui_textfield_phone_numer_id, VAPP_PHB_LIST_SINGLE_SELECTOR);
	
            vcui_phb_list_set_req_field(mmi_java_ui_textfield_phone_numer_id, MMI_PHB_CONTACT_FIELD_NUMBER);
	
            vcui_phb_list_run(mmi_java_ui_textfield_phone_numer_id);
			
            break;
        default:
            break;
    }

    return MMI_RET_OK;
}

#endif /*J2ME_SLIM_MEMORY_SUPPORT*/

    
#endif /*__COSMOS_MMI_PACKAGE__*/



/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textfield_show_req
 * DESCRIPTION
 *  enter fullscreen editor
 * CALLS
 *  
 * PARAMETERS
 *  msg_struct      [?]         
 *  mod_src(?)      [IN]        
 *  msg         [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_textfield_show_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 input_type;
    mmi_java_ui_textfield_show_req_struct *msg = (mmi_java_ui_textfield_show_req_struct*) msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);
    g_mmi_java_ui_textfield.text = msg->text;
    g_mmi_java_ui_textfield.max_size = msg->max_size;
    g_mmi_java_ui_textfield.constraints = msg->constraints;
    g_mmi_java_ui_textfield.callback = msg->callback;
    g_mmi_java_ui_textfield.vm_id = msg->vm_id;

    ClearKeyEvents();   /* clear all keypad buffer */
#ifndef __COSMOS_MMI_PACKAGE__
    mmi_java_ui_textfield_enter();
#else
    vapp_java_ui_entry_textfield();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textfield_hide_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_textfield_hide_req(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_textfield_show_req_struct *msg = (mmi_java_ui_textfield_show_req_struct*) msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg != NULL);
    ASSERT(msg->vm_id == g_mmi_java_ui_textfield.vm_id);

    /* TODO */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textfield_enter
 * DESCRIPTION
 *  enter full screen editor and put mmi_java_ui_textfield screen into history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_textfield_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* we only backup the buffer for the first time */
    /* mmi_java_ui_textfield_backup_editor_buffer(mmi_java_ui_textfield_input_buffer,mmi_java_ui_textfield_input_buffer_max_len); */
    if (mmi_java_ui_textfield_editor_group_id != GRP_ID_INVALID)
    {
        mmi_frm_group_close(mmi_java_ui_textfield_editor_group_id);
        mmi_java_ui_textfield_editor_group_id = GRP_ID_INVALID;
    }

    mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_JAVA_TEXTFIELD, mmi_java_ui_textfield_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_java_ui_textfield_search_flag = KAL_FALSE;

    mmi_java_ui_textfield_editor_id = cui_fseditor_create(GRP_ID_JAVA_TEXTFIELD);

    if (mmi_java_ui_textfield_editor_id != GRP_ID_INVALID)
    {
        cui_fseditor_set_title(mmi_java_ui_textfield_editor_id, STR_GLOBAL_TEXT, mmi_java_get_title_icon());
        cui_fseditor_set_text(
            mmi_java_ui_textfield_editor_id,
            (WCHAR*) g_mmi_java_ui_textfield.text,
            g_mmi_java_ui_textfield.max_size * 2,
            g_mmi_java_ui_textfield.max_size - 1);
        cui_fseditor_set_input_method(
            mmi_java_ui_textfield_editor_id,
            g_mmi_java_ui_textfield.constraints,
            NULL,
            IMM_INPUT_MODE_NONE);
        cui_fseditor_set_is_disable_ncenter(mmi_java_ui_textfield_editor_id, MMI_TRUE);
        cui_fseditor_run(mmi_java_ui_textfield_editor_id);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textfield_proc
 * DESCRIPTION
 *  enter full screen editor and put textfield screen into history
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_java_ui_textfield_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__
    cui_phb_select_contact_result_struct *event;
#endif
    S8 *number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
            mmi_java_ui_textfield_active = KAL_TRUE;
            break;
        case EVT_ID_GROUP_INACTIVE:
            mmi_java_ui_textfield_active = KAL_FALSE;
            break;
        case EVT_ID_GROUP_DEINIT:
            mmi_java_ui_textfield_active = KAL_FALSE;
            break;
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
            mmi_frm_group_close(GRP_ID_JAVA_TEXTFIELD);
            break;

        case EVT_ID_CUI_FSEDITOR_CSK_PRESSED:
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
            /* Handler when user confirm input */
            if (mmi_java_ui_textfield_search_flag)
            {
#ifndef __COSMOS_MMI_PACKAGE__
			    if(jam_mvm_get_vm_state(jam_mvm_get_current_vm_id())!= JVM_TERMINATE_STATE &&
                   jam_mvm_get_vm_state(jam_mvm_get_current_vm_id())!= JVM_TERMINATING_STATE)
			    {
                mmi_java_ui_textfield_phone_numer_id = cui_phb_list_select_contact_create(GRP_ID_JAVA_TEXTFIELD);
#ifdef __MMI_NCENTER_SUPPORT__
				cui_phb_list_select_contact_set_ncenter(mmi_java_ui_textfield_phone_numer_id, KAL_TRUE);
#endif
                cui_phb_list_select_contact_set_field_filter(
                    mmi_java_ui_textfield_phone_numer_id,
                    SRV_PHB_ENTRY_FIELD_GSM_NUM);
                cui_phb_list_select_contact_run(mmi_java_ui_textfield_phone_numer_id);
               }
#endif
            }
            else
            {
                cui_fseditor_get_text(
                    mmi_java_ui_textfield_editor_id,
                    (WCHAR*) g_mmi_java_ui_textfield.text,
                    g_mmi_java_ui_textfield.max_size * ENCODING_LENGTH);

                if (g_mmi_java_ui_textfield.callback != NULL)
                    g_mmi_java_ui_textfield.callback(KAL_TRUE, g_mmi_java_ui_textfield.vm_id);
                cui_fseditor_close(mmi_java_ui_textfield_editor_id);
            }
            break;
        case EVT_ID_CUI_FSEDITOR_ABORT:
            /* Handler when user Cancel input */

            if (g_mmi_java_ui_textfield.callback != NULL)
                g_mmi_java_ui_textfield.callback(KAL_FALSE, g_mmi_java_ui_textfield.vm_id);
            cui_fseditor_close(mmi_java_ui_textfield_editor_id);
            break;
        case EVT_ID_CUI_FSEDITOR_EMPTY:
            /* Handler when editor content is empty */
			if(jam_mvm_get_vm_state(jam_mvm_get_current_vm_id())!= JVM_TERMINATE_STATE &&
            jam_mvm_get_vm_state(jam_mvm_get_current_vm_id())!= JVM_TERMINATING_STATE)
			{
                if ((g_mmi_java_ui_textfield.constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_PHONE_NUMBER)
                {
                    cui_fseditor_set_softkey_text(mmi_java_ui_textfield_editor_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_SEARCH);
                    cui_fseditor_set_softkey_icon(mmi_java_ui_textfield_editor_id, MMI_LEFT_SOFTKEY, 0);
                    cui_fseditor_set_softkey_icon(
                        mmi_java_ui_textfield_editor_id,
                        MMI_CENTER_SOFTKEY,
                        IMG_GLOBAL_COMMON_CSK);
                    mmi_java_ui_textfield_search_flag = KAL_TRUE;
                }
			}
            break;
        case EVT_ID_CUI_FSEDITOR_NOT_EMPTY:
            /* Handler when editor content is not empty */
            if ((g_mmi_java_ui_textfield.constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_PHONE_NUMBER)
            {
                cui_fseditor_set_softkey_text(mmi_java_ui_textfield_editor_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_OK);
                cui_fseditor_set_softkey_icon(mmi_java_ui_textfield_editor_id, MMI_LEFT_SOFTKEY, 0);
                cui_fseditor_set_softkey_icon(
                    mmi_java_ui_textfield_editor_id,
                    MMI_CENTER_SOFTKEY,
                    IMG_GLOBAL_COMMON_CSK);
                mmi_java_ui_textfield_search_flag = KAL_FALSE;
            }
            break;
#ifndef __COSMOS_MMI_PACKAGE__
        case EVT_ID_PHB_SELECT_CONTACT:
            event = (cui_phb_select_contact_result_struct*) evt;
            number = (S8*) (event->select_data);
            if (number)
            {
                mmi_ucs2ncpy((S8*) g_mmi_java_ui_textfield.text, (PS8) number, g_mmi_java_ui_textfield.max_size - 1);
                cui_fseditor_set_text(
                    mmi_java_ui_textfield_editor_id,
                    (WCHAR*) g_mmi_java_ui_textfield.text,
                    g_mmi_java_ui_textfield.max_size,
                    g_mmi_java_ui_textfield.max_size - 1);
            }
            cui_phb_list_select_contact_close(mmi_java_ui_textfield_phone_numer_id);
            break;
        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
            cui_phb_list_select_contact_close(mmi_java_ui_textfield_phone_numer_id);
            break;
#endif
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textfield_add_extra_symbol
 * DESCRIPTION
 *  Add extra symbols into symbol table
 * CALLS
 *  
 * PARAMETERS
 *  out         [?]         [?]         [?]
 *  out_max     [IN]        
 *  in          [IN]        
 *  in_max      [IN]        
 * RETURNS
 *  S32         numbers of symbols to add
 *****************************************************************************/
kal_int32 mmi_java_ui_textfield_add_extra_symbol(kal_uint8 *out, kal_int32 out_max, kal_uint8 **in, kal_int32 in_max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(JTWISymbol) / 4; i++)
    {
        memcpy(out + in_max * 4 + i * 4, *(JTWISymbol + i), 4);
    }
    return (in_max + sizeof(JTWISymbol) / 4);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textfield_is_need_add_extra_symbol
 * DESCRIPTION
 *  Add extra symbols into symbol table
 * CALLS
 *  
 * PARAMETERS
 *  void
 *  in_max(?)       [IN]        
 *  in(?)           [IN]        
 *  out_max(?)      [IN]        
 *  out         [?]         [?](?)
 * RETURNS
 *  S32         numbers of symbols to add
 *****************************************************************************/
kal_bool mmi_java_ui_textfield_is_need_add_extra_symbol()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//#ifndef __COSMOS_MMI_PACKAGE__
    return mmi_java_ui_textfield_active;
//#else
    //return vapp_java_ui_is_textfield_active();
//#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ui_textfield_remove_screen
 * DESCRIPTION
 *  This function will remove mmi_java_ui_textfield-related fullscreen editor screen
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_ui_textfield_remove_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0   /* 09B */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

#if 0   /* 10A */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTFIELD_EDITOR_OPTION);
    mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTFIELD_EDITOR);

    //DeleteScreenIfPresent(MMIAPI_SCREEN_FULLSCREEN_EDITOR_OPTION);   //10A
    //DeleteScreenIfPresent(MMIAPI_SCREEN_FULLSCREEN_EDITOR);

    mmi_frm_scrn_close(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTFIELD_EDITOR_OPTION);
    mmi_frm_scrn_close(GRP_ID_JAVA_APP, SCR_ID_JAVA_UI_TEXTFIELD_EDITOR_OPTION);

}

/*****************************************************************************
* FUNCTION
*  mmiapi_goto_textbox_search_number
* DESCRIPTION
*  this function will goto edit option menu.
* CALLS
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_java_ui_textfield_close_phb_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__
	cui_phb_list_select_contact_close(mmi_java_ui_textfield_phone_numer_id);
#endif
}


#endif /* __J2ME__ */ 

