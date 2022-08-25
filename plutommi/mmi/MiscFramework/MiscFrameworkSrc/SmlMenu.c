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
 *  SmlMenu.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for SIM-ME-Lock application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

/******************  KAL Layer header *****************/
#include "stdlib.h"                 /* atoi */
#include "stdio.h"                  /* sprintf */
#include "string.h"                 /* strcpy */
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "stack_msgs.h"             /* MSG_ID_MMI_SMU_SML_STATUS_RSP */
#include "stack_config.h"           /* MOD_L4C */

#include "sim_common_enums.h"       /* SIM1 */
#include "mmi_msg_struct.h"         /* mmi_smu_set_personalization_rsp_struct */
#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "app_ltlcom.h"             /* ilm_struct */


/******************  MMI Framework header *****************/
#include "MMI_features.h"
#include "MMIDataType.h"

#ifdef __MMI_SML_MENU__

#include "ProtocolEvents.h"             /* PRT_MMI_SMU_SET_PERSONALIZATION_RSP */
#include "CommonScreens.h"              /* UI_POPUP_NOTIFYDURATION_TIME */
#include "CommonScreensResDef.h"        /* EVT_ID_ALERT_QUIT */
#include "CustResDef.h"                 /* SSC_SML_LOCK_CMD */
#include "CustDataRes.h"                /* GetString */
#include "Unicodexdcl.h"                /* mmi_ucs2_to_asc */
#include "GlobalResDef.h"               /* IMG_GLOBAL_COMMON_CSK */
#include "GlobalConstants.h"            /* KEY_EVENT_UP */
#include "DebugInitDef_Int.h"           /* MMI_ASSERT */

#include "gui.h"                        /* gui_atoi */
#include "gui_data_types.h"             /* UI_string_type */

#include "mmi_frm_events_gprot.h"       /* mmi_event_notify_enum */
#include "mmi_frm_scenario_gprot.h"     /* mmi_frm_group_get_active_id */
#include "mmi_frm_history_gprot.h"      /* GoBackHistory */
#include "mmi_frm_input_gprot.h"        /* ClearKeyHandler */
#include "mmi_frm_timer_gprot.h"        /* StartTimer */
#include "mmi_frm_queue_gprot.h"        /* MYQUEUE */
#include "mmi_frm_utility_gprot.h"

#include "wgui_categories.h"            /* ShowCategory2Screen */
#include "wgui_categories_list.h"       /* ShowCategory11Screen */
#include "wgui_inline_edit.h"           /* INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT */
#include "wgui_categories_util.h"       /* ChangeLeftSoftkey */
#include "wgui_inputs.h"                /* RegisterInputBoxValidationFunction */
#include "wgui_categories_inputs.h"     /* ShowCategory111Screen */


/******************  MMI App header *****************/
#include "mmi_rp_app_sim_me_lock_def.h"         /* STR_ID_CATEGORY_CP_LOCK */

#include "SmlMenuGprot.h"               /* auto_data */
#include "SettingDefs.h"                /* MAX_PASS_COUNTDOWN_DISP */
#include "DialerGProt.h"                /* mmi_dialer_get_dial_string */

#ifdef __MMI_BACKGROUND_CALL__
#include "UCMGProt.h"                   /* mmi_ucm_app_entry_error_message */
#include "UCMSrvGProt.h"                /* srv_ucm_is_background_call */
#endif

#include "BootupSrvGprot.h"             /* srv_bootup_is_booting */
#include "ShutdownSrvGprot.h"           /* srv_shutdown_exit_system */
#include "SimCtrlSrvGprot.h"            /* srv_sim_ctrl_is_available */
#include "InlineCUIGprot.h"             /* cui_inline_item_caption_struct */
#include "MenuCUIGprot.h"               /* cui_menu_close */
#include "ImeGprot.h"                   /* IMM_INPUT_TYPE_EXT_PASSWORD */
#include "AlertScreen.h"                /* mmi_popup_property_struct */
#include "IdleAppDef.h"                 /* MAX_DIAL_PAD */
#include "ShutdownSrvGprot.h"           /* srv_shutdown_exit_system */

void mmi_sml_entry_add_data(void);
void mmi_sml_read_data_from_sim_query(void);
void mmi_sml_verify_key_req(void);
void mmi_sml_input_key(void);
void mmi_sml_confirm_key(void);

#ifdef __MMI_SML_AUTO_KEY_GEN__
extern void mmi_sml_auto_key_gen_implemetation(U8 *);
#endif 

mmi_sml_common_struct g_sml_common = {0};
mmi_sml_menu_struct g_sml_context;
mmi_sml_menu_struct *g_sml_context_p = &g_sml_context;
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif

U8 gSMLNewPassword[(MAX_SML_UNLOCK_KEY_LENGTH + 1) * ENCODING_LENGTH];
U8 gSMLConfirmPassword[(MAX_SML_UNLOCK_KEY_LENGTH + 1) *ENCODING_LENGTH];

static cui_inline_item_caption_struct mmi_sml_data_netcode_cap = 
{
    STR_ID_SML_NP_DATA
};

static cui_inline_item_caption_struct mmi_sml_data_gid1_cap = 
{
    STR_ID_SML_SP_DATA
};

static cui_inline_item_caption_struct mmi_sml_data_gid2_cap = 
{
    STR_ID_SML_CP_DATA
};

static cui_inline_item_text_edit_struct mmi_sml_data_netcode_val =
{
    0,
    0,
    0, // Need to configure runtime
    IMM_INPUT_TYPE_NUMERIC,
    0,
    NULL
};

static cui_inline_item_text_edit_struct mmi_sml_data_gid1_val =
{
    0,
    0,
    MAX_GID_LEN + 1,
    IMM_INPUT_TYPE_NUMERIC,
    0,
    NULL
};

static cui_inline_item_text_edit_struct mmi_sml_data_gid2_val =
{
    0,
    0,
    MAX_GID_LEN + 1,
    IMM_INPUT_TYPE_NUMERIC,
    0,
    NULL
};

static cui_inline_set_item_struct mmi_sml_data_inline[6] = 
{
    {CUI_INLINE_ITEM_ID_BASE + 0, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*) &mmi_sml_data_netcode_cap},
    {CUI_INLINE_ITEM_ID_BASE + 1, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*) &mmi_sml_data_netcode_val},
    {CUI_INLINE_ITEM_ID_BASE + 2, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*) &mmi_sml_data_gid1_cap},
    {CUI_INLINE_ITEM_ID_BASE + 3, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*) &mmi_sml_data_gid1_val},
    {CUI_INLINE_ITEM_ID_BASE + 4, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*) &mmi_sml_data_gid2_cap},
    {CUI_INLINE_ITEM_ID_BASE + 5, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*) &mmi_sml_data_gid2_val}
};

static cui_inline_struct mmi_sml_data_screen = 
{
    0, // Need to configure runtime
    STR_ID_SML_ADD_MENU,
    0,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    mmi_sml_data_inline
};

/*****************************************************************************
 * FUNCTION
 *  mmi_sml_reset_input_buffer
 * DESCRIPTION
 *  Reset input buffer of add data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sml_reset_input_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_sml_context_p->input_imsi, 0, (MAX_IMSI_LEN + 1) * ENCODING_LENGTH);
    memset(g_sml_context_p->input_gid1, 0, (MAX_GID_LEN + 1) * ENCODING_LENGTH);
    memset(g_sml_context_p->input_gid2, 0, (MAX_GID_LEN + 1) * ENCODING_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_query_state_popup_callback
 * DESCRIPTION
 *  Popup callback for query screens
 * PARAMETERS
 *  param
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_sml_query_state_popup_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_display_popup_plus_delete_sim_selection_scrn
 * DESCRIPTION
 *  SIM-ME-Lock popup screen wrapper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sml_display_popup_plus_delete_sim_selection_scrn(UI_string_type popup_string, mmi_event_notify_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct popup_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&popup_struct);
    popup_struct.callback = mmi_sml_query_state_popup_callback;
    mmi_popup_display(
        popup_string, 
        event_type, 
        &popup_struct);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_display_popup
 * DESCRIPTION
 *  SIM-ME-Lock popup screen wrapper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sml_display_popup(UI_string_type popup_string, mmi_event_notify_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple(
        popup_string,
        event_type,
        mmi_frm_group_get_active_id(),
        NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sml_cphs_info_ind
 * DESCRIPTION
 *  SIM-ME-Lock popup screen wrapper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_sml_cphs_info_ind(void *msgPtr, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cphs_mmi_info_ind_struct *mmiIndoInd;
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmiIndoInd = (mmi_cphs_mmi_info_ind_struct*) msgPtr;

    sim_id = mmi_frm_l4c_mod_to_sim(mod_src);

#if (MMI_MAX_SIM_NUM >= 2)
    if (sim_id == MMI_SIM2)
    {
        mmi_sml_entry_sim2_auto_lock(mmiIndoInd);
    }
    else if (sim_id == MMI_SIM1)
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    {
        mmi_sml_entry_sim1_auto_lock(mmiIndoInd);
    }

    return (U8)MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sml_init
 * DESCRIPTION
 *  SML initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DUAL_SIM_MASTER__

    g_sml_context_p->operation_type = 0xFF;
    g_sml_context_p->selected_category = 0;
    g_sml_context_p->action_not_from_menu = 0;
    mmi_sml_reset_input_buffer();

#else /* __MMI_DUAL_SIM_MASTER__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __SMS_DEPERSONALIZATION__
/* under construction !*/
#endif

    mmi_frm_set_protocol_event_handler(PRT_MSG_ID_MMI_CPHS_MMI_INFO_IND, (PsIntFuncPtr)mmi_sml_cphs_info_ind, MMI_TRUE);
}


#ifndef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sml_reset_menu_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_reset_menu_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sml_context_p->selected_category = 0;
}
#endif /* __MMI_DUAL_SIM_MASTER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_leave_no_category_screen
 * DESCRIPTION
 *  Exit function of no available category screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_leave_no_category_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_is_gid1_valid
 * DESCRIPTION
 *  GID1 validation
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_sml_is_gid1_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context_p->gid_valid_nibble & 0x01)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_is_gid2_valid
 * DESCRIPTION
 *  GID2 validation
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_sml_is_gid2_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context_p->gid_valid_nibble & 0x10)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_password_screen_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text            [IN]         
 *  cursor          [IN]         
 *  length          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sml_password_screen_lsk_hdlr(U8 *text, U8 *cursor, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (length < MIN_SML_UNLOCK_KEY_LENGTH)
    {
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
        if (GetActiveScreenId() == SCR_ID_SML_CONFIRM_KEY)
        {
            ChangeLeftSoftkey(0, 0);
        }
        else if (g_sml_context_p->operation_type == SML_OP_UNLOCK)
        {
            ChangeLeftSoftkey(0, 0);
        }
        else /* SML_OP_LOCK or SML_OP_ADD */
        {
        #ifdef __MMI_SML_AUTO_KEY_GEN__
            if (g_sml_context_p->key_state[g_sml_context_p->selected_category] == SML_KEY_EMPTY && mmi_ucs2strlen((S8*) gSMLNewPassword) == 0)
                EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            else
        #endif
                ChangeLeftSoftkey(0, 0);
        }
    }
    else
    {
        /* if its valid length then enable lsk */
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetKeyHandler(g_sml_common.password_len_callback, KEY_POUND, KEY_EVENT_UP);
    }
}


#ifdef __SMS_DEPERSONALIZATION__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#else /* __MMI_DUAL_SIM_MASTER__ */
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __SMS_DEPERSONALIZATION__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_convert_ansii_imsi_to_bcd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input           [IN]     
 *  output          [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_convert_ansii_imsi_to_bcd(U8 *input, U8 *output)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, j = 0;
    U8 low_byte = 9, high_byte = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_IMSI_LEN; i++)
    {
        if (i % 2 == 0)
        {
            high_byte = *(input + i) - 0x30;
            *(output + j) = (high_byte << 4) + low_byte;
            j++;
        }
        else
        {
            low_byte = *(input + i) - 0x30;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_compact_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input           [IN]     
 *  output          [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_compact_data(U8 *input, U8 *output)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 low_byte, high_byte;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    high_byte = *input - 0x30;
    low_byte = *(input + 1) - 0x30;
    *output = (high_byte << 4) + low_byte; // byte 1
    high_byte = *(input + 2) - 0x30;
    low_byte = *(input + 3) - 0x30;
    *(output + 1) = (high_byte << 4) + low_byte; // byte 2

    switch (strlen((S8*) input))
    {
        case 5:
            high_byte = *(input + 4) - 0x30;
            low_byte = 0x0F;
            *(output + 2) = (high_byte << 4) + low_byte; // byte 3
            break;

        case 6:
            high_byte = *(input + 4) - 0x30;
            low_byte = *(input + 5) - 0x30;
            *(output + 2) = (high_byte << 4) + low_byte; // byte 3
            break;

        case 7:
            high_byte = *(input + 4) - 0x30;
            low_byte = 0x0F;
            *(output + 2) = (high_byte << 4) + low_byte; // byte 3
            high_byte = *(input + 5) - 0x30;
            low_byte = *(input + 6) - 0x30;
            *(output + 3) = (high_byte << 4) + low_byte; // byte 4
            break;

        case 8:
            high_byte = *(input + 4) - 0x30;
            low_byte = *(input + 5) - 0x30;
            *(output + 2) = (high_byte << 4) + low_byte; // byte 3
            high_byte = *(input + 6) - 0x30;
            low_byte = *(input + 7) - 0x30;
            *(output + 3) = (high_byte << 4) + low_byte; // byte 4
            break;

        default:
           break;
    }
}


#ifdef __MMI_SML_AUTO_KEY_GEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_sml_set_auto_key_gen
 * DESCRIPTION
 *  Automatic key generation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_set_auto_key_gen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 auto_key[MAX_SML_UNLOCK_KEY_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sml_auto_key_gen_implemetation(auto_key);   /* defined in custom directory */
    mmi_asc_to_ucs2((S8*) gSMLNewPassword, (S8*) auto_key);
    mmi_asc_to_ucs2((S8*) gSMLConfirmPassword, (S8*) auto_key);
    mmi_sml_verify_key_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_auto_key_gen_confirm
 * DESCRIPTION
 *  Automatic key generation confirmation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_auto_key_gen_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_struct;
    mmi_id group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_frm_group_get_active_id();

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    mmi_confirm_property_init(&confirm_struct, CNFM_TYPE_YESNO);
    confirm_struct.parent_id = group_id;
    mmi_confirm_display(
        (WCHAR *) GetString(STR_ID_SML_AUTOKEY_CONFIRM), 
        MMI_EVENT_QUERY, 
        &confirm_struct);

    SetLeftSoftkeyFunction(mmi_sml_set_auto_key_gen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_sml_set_auto_key_gen, KEY_EVENT_UP);
}
#endif /* __MMI_SML_AUTO_KEY_GEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_add_data_popup_callback
 * DESCRIPTION
 *  Popup callback for add data screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sml_add_data_popup_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
            cui_inline_close(g_sml_common.inline_cui_id);
            g_sml_common.inline_cui_id = 0;
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_shutdown_timer_expire
 * DESCRIPTION
 *  Expired timer handler to reboot
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_shutdown_timer_expire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_shutdown_exit_system(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_add_data_reboot_check
 * DESCRIPTION
 *  Reboot check for add data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_add_data_reboot_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL need_reboot = MMI_FALSE;
    U8 tmp_gid1 = 0, tmp_gid2 = 0;
    S8 tmp_imsi[MAX_IMSI_LEN + 1];

    mmi_popup_property_struct popup_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc(tmp_imsi, (S8*) g_sml_context_p->input_imsi);
    if (g_sml_context_p->selected_category == SML_CAT_SP ||
        g_sml_context_p->selected_category == SML_CAT_C ||
        g_sml_context_p->selected_category == SML_CAT_NS_SP || g_sml_context_p->selected_category == SML_CAT_SIM_C)
    {
        tmp_gid1 = (U8) gui_atoi((U16*) g_sml_context_p->input_gid1);
    }

    if (g_sml_context_p->selected_category == SML_CAT_C || g_sml_context_p->selected_category == SML_CAT_SIM_C)
    {
        tmp_gid2 = (U8) gui_atoi((U16*) g_sml_context_p->input_gid2);
    }

    switch (g_sml_context_p->selected_category)
    {
        case SML_CAT_N:
        case SML_CAT_NS:
        case SML_CAT_SIM:
            if (strncmp((S8*) g_sml_context_p->imsi, tmp_imsi, strlen(tmp_imsi)) != 0)
            {
                need_reboot = MMI_TRUE;
            }
            break;

        case SML_CAT_SP:
        case SML_CAT_NS_SP:
            if (strncmp((S8*) g_sml_context_p->imsi, tmp_imsi, strlen(tmp_imsi)) != 0 || tmp_gid1 != g_sml_context_p->gid1)
            {
                need_reboot = MMI_TRUE;
            }
            break;

        case SML_CAT_C:
        case SML_CAT_SIM_C:
            if (strncmp((S8*) g_sml_context_p->imsi, tmp_imsi, strlen(tmp_imsi)) != 0 || tmp_gid1 != g_sml_context_p->gid1 ||
                tmp_gid2 != g_sml_context_p->gid2)
            {
                need_reboot = MMI_TRUE;
            }
            break;

        default:
            break;
    }

    if (need_reboot)
    {
        mmi_sml_display_popup((UI_string_type) GetString(STR_ID_SML_REBOOT_MSG), MMI_EVENT_SUCCESS);
        StartTimer(SML_AUTOLOCK_IDLE_NOTIFY_TIMER, UI_POPUP_NOTIFYDURATION_TIME, mmi_sml_shutdown_timer_expire);
    }
    else
    {
        //mmi_sml_display_popup((UI_string_type) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
        mmi_popup_property_init(&popup_struct);
        popup_struct.callback = mmi_sml_add_data_popup_callback;
        mmi_popup_display(
            (UI_string_type) GetString(STR_GLOBAL_DONE), 
            MMI_EVENT_SUCCESS, 
            &popup_struct);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_set_personalization_rsp
 * DESCRIPTION
 *  Verify lock/unlock key response
 * PARAMETERS
 *  info            [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_set_personalization_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_personalization_rsp_struct *resp;
    //historyNode *History;
    mmi_scrn_node_struct node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_set_personalization_rsp_struct*) (info);

    mmi_sml_clear_protocol_event_handler(PRT_MMI_SMU_SET_PERSONALIZATION_RSP);

    memset(gSMLNewPassword, 0, (MAX_SML_UNLOCK_KEY_LENGTH + 1) * ENCODING_LENGTH);
    memset(gSMLConfirmPassword, 0, (MAX_SML_UNLOCK_KEY_LENGTH + 1) * ENCODING_LENGTH);

    /* update retry count for each set personalization request */
    g_sml_context_p->retry_count[g_sml_context_p->selected_category] = resp->retry_count;
    /* update state for each set personalization request */
    g_sml_context_p->category_state[g_sml_context_p->selected_category] = resp->state;

    if (g_sml_context_p->action_not_from_menu)
    {
        if (resp->result.flag == L4C_OK)
        {
            mmi_sml_display_popup_plus_delete_sim_selection_scrn((UI_string_type) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
        }
        else
        {
            if (resp->retry_count == 1)
            {
                mmi_sml_display_popup_plus_delete_sim_selection_scrn((UI_string_type) GetString(STR_ID_LAST_RETRY_MSG), MMI_EVENT_FAILURE);
            }
            else
            {
                mmi_sml_display_popup_plus_delete_sim_selection_scrn((UI_string_type) GetString(STR_ID_GENERAL_RETRY_MSG), MMI_EVENT_FAILURE);
            }
        }

        g_sml_context_p->action_not_from_menu = 0;
        return;
    }

    if (resp->result.flag == L4C_OK)
    {
        switch (g_sml_context_p->operation_type)
        {
            case SML_OP_DISABLE:
                mmi_sml_display_popup((UI_string_type) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
                g_sml_context_p->category_state[g_sml_context_p->selected_category] = SML_STATE_DISABLE;
                break;

            case SML_OP_ADD:
                mmi_sml_add_data_reboot_check();
                g_sml_context_p->used_records[g_sml_context_p->selected_category]++;
                //DeleteScreenIfPresent(SCR_ID_SML_FILL_DATA);
                break;

            case SML_OP_REMOVE:
                mmi_sml_display_popup((UI_string_type) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
                g_sml_context_p->used_records[g_sml_context_p->selected_category] = 0;
                break;

            default:
                mmi_sml_display_popup((UI_string_type) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
                break;
        }

		//DeleteScreenIfPresent(SCR_ID_SML_INPUT_KEY);
		mmi_frm_scrn_close(GRP_ID_SML_PSWD, SCR_ID_SML_INPUT_KEY);
		//mmi_frm_group_close(GRP_ID_SML_PSWD);
    }
    else
    {
        //mmi_sml_popup_error_msg(resp->retry_count);
        if (resp->retry_count == 1)
        {
            mmi_sml_display_popup((UI_string_type) GetString(STR_ID_LAST_RETRY_MSG), MMI_EVENT_FAILURE);
        }
        else
        {
            mmi_sml_display_popup((UI_string_type) GetString(STR_ID_GENERAL_RETRY_MSG), MMI_EVENT_FAILURE);
        }

        if (mmi_frm_scrn_get_info(GRP_ID_SML_PSWD, SCR_ID_SML_INPUT_KEY, &node) == MMI_RET_OK)
        {
            if (node.input_buf != NULL)
            {
                memset(node.input_buf, 0, ENCODING_LENGTH);
            }
            if (node.gui_buf != NULL)
            {
                memset(node.gui_buf, 0, ENCODING_LENGTH);
            }
        }

        mmi_frm_scrn_close(GRP_ID_SML_PSWD, SCR_ID_SML_CONFIRM_KEY);
    }

    //DeleteScreenIfPresent(SCR_ID_SML_CONFIRM_KEY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_set_personalization_req
 * DESCRIPTION
 *  Verify lock/unlock key request
 * PARAMETERS
 *  key             [IN]
 *  category        [IN]        
 *  operation       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_set_personalization_req(U8 *key, U8 category, U8 operation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_personalization_req_struct *local_data;
    S8 tmp_gid[MAX_GID_LEN + 1];
    S8 tmp_imsi[MAX_IMSI_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */

    ClearAllKeyHandler();   /* ClearInputEventHandler(MMI_DEVICE_ALL); */
    mmi_sml_set_protocol_event_handler(mmi_sml_set_personalization_rsp, PRT_MMI_SMU_SET_PERSONALIZATION_RSP);

    local_data =
        (mmi_smu_set_personalization_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_set_personalization_req_struct));
    local_data->category = category;
    local_data->op = operation;
    memset(local_data->data, 0, 10);

    if (key != NULL)
    {
        strncpy((S8*) local_data->key, (S8*) key, 16);
    }
    else
    {
        local_data->key[0] = 0;
    }

    //strcpy((S8*)local_data->imei, (S8*)g_sml_context_p->input_imsi);
    //strcpy((S8*)local_data->gid1, (S8*)g_sml_context_p->input_gid1);
    //strcpy((S8*)local_data->gid2, (S8*)g_sml_context_p->input_gid2);
    if (operation == SML_OP_ADD)
    {
        switch (g_sml_context_p->selected_category)
        {
            case SML_CAT_N:
                mmi_ucs2_to_asc(tmp_imsi, (S8*) g_sml_context_p->input_imsi);
                mmi_sml_compact_data((U8*) tmp_imsi, local_data->data);
                local_data->len = 3;
                break;

            case SML_CAT_NS:
                mmi_ucs2_to_asc(tmp_imsi, (S8*) g_sml_context_p->input_imsi);
                mmi_sml_compact_data((U8*) tmp_imsi, local_data->data);
                local_data->len = 4;
                break;

            case SML_CAT_SP:
                mmi_ucs2_to_asc(tmp_imsi, (S8*) g_sml_context_p->input_imsi);
                mmi_sml_compact_data((U8*) tmp_imsi, local_data->data);
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context_p->input_gid1);
                local_data->data[3] = (U8) atoi(tmp_gid);
                local_data->len = 4;
                break;

            case SML_CAT_C:
                mmi_ucs2_to_asc(tmp_imsi, (S8*) g_sml_context_p->input_imsi);
                mmi_sml_compact_data((U8*) tmp_imsi, local_data->data);
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context_p->input_gid1);
                local_data->data[3] = (U8) atoi(tmp_gid);
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context_p->input_gid2);
                local_data->data[4] = (U8) atoi(tmp_gid);
                local_data->len = 5;
                break;

            case SML_CAT_SIM:
                mmi_ucs2_to_asc(tmp_imsi, (S8*) g_sml_context_p->input_imsi);
                mmi_sml_convert_ansii_imsi_to_bcd((U8*) tmp_imsi, local_data->data);
                local_data->len = 8;
                break;

            case SML_CAT_NS_SP:
                mmi_ucs2_to_asc(tmp_imsi, (S8*) g_sml_context_p->input_imsi);
                mmi_sml_compact_data((U8*) tmp_imsi, local_data->data);
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context_p->input_gid1);
                local_data->data[4] = (U8) atoi(tmp_gid);
                local_data->len = 5;
                break;

            case SML_CAT_SIM_C:
                mmi_ucs2_to_asc(tmp_imsi, (S8*) g_sml_context_p->input_imsi);
                mmi_sml_convert_ansii_imsi_to_bcd((U8*) tmp_imsi, local_data->data);
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context_p->input_gid1);
                local_data->data[8] = (U8) atoi(tmp_gid);
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context_p->input_gid2);
                local_data->data[9] = (U8) atoi(tmp_gid);
                local_data->len = 10;
                break;
        }
    }
    else
    {
        local_data->len = 0;
        //local_data->gid1 = 0;
        //local_data->gid2 = 0;
    }

    mmi_frm_send_ilm(mmi_sml_get_message_dest_module(), PRT_MMI_SMU_SET_PERSONALIZATION_REQ,
        (oslParaType*) local_data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_verify_key_req
 * DESCRIPTION
 *  Verify lock/unlock key request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_verify_key_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //historyNode *History;
    U8 key[MAX_SML_UNLOCK_KEY_LENGTH + 1];
    mmi_scrn_node_struct node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context_p->key_state[g_sml_context_p->selected_category] == SML_KEY_EMPTY &&
        g_sml_context_p->operation_type != SML_OP_UNLOCK)
    {
        /* check new key and confirmation key */
        if (mmi_ucs2cmp((S8*) gSMLNewPassword, (S8*) gSMLConfirmPassword) != 0)
        {
            memset(gSMLNewPassword, 0, (MAX_SML_UNLOCK_KEY_LENGTH + 1) * ENCODING_LENGTH);
            memset(gSMLConfirmPassword, 0, (MAX_SML_UNLOCK_KEY_LENGTH + 1) * ENCODING_LENGTH);

            mmi_sml_display_popup((UI_string_type) GetString(STR_ID_SML_DIFF_PASSWORD), MMI_EVENT_FAILURE);
            mmi_frm_scrn_close(GRP_ID_SML_PSWD, SCR_ID_SML_CONFIRM_KEY);

            if (mmi_frm_scrn_get_info(GRP_ID_SML_PSWD, SCR_ID_SML_INPUT_KEY, &node) == MMI_RET_OK)
            {
                if (node.input_buf != NULL)
                {
                    memset(node.input_buf, 0, ENCODING_LENGTH);
                }
                if (node.gui_buf != NULL)
                {
                    memset(node.gui_buf, 0, ENCODING_LENGTH);
                }
            }
            return;
        }
    }

    mmi_ucs2_to_asc((S8*) key, (S8*) gSMLNewPassword);

    if (g_sml_context_p->operation_type != SML_OP_ADD)
    {
        mmi_sml_reset_input_buffer();
    }

    mmi_sml_set_personalization_req(key, g_sml_context_p->selected_category, g_sml_context_p->operation_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_data_valid_check
 * DESCRIPTION
 *  Check the valiation of input data to add
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_sml_data_valid_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL rtn = 1;
    S8 tmp_gid[MAX_GID_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_sml_context_p->selected_category)
    {
        case SML_CAT_N:
            if (mmi_ucs2strlen((S8*) g_sml_context_p->input_imsi) > 0 &&
                mmi_ucs2strlen((S8*) g_sml_context_p->input_imsi) < MAX_NP_LEN - 1)
            {
                rtn = 0;
            }
            break;
        case SML_CAT_NS:
            if (mmi_ucs2strlen((S8*) g_sml_context_p->input_imsi) > 0 &&
                mmi_ucs2strlen((S8*) g_sml_context_p->input_imsi) < MAX_NSP_LEN - 1)
            {
                rtn = 0;
            }
            break;
        case SML_CAT_SP:
            if (mmi_ucs2strlen((S8*) g_sml_context_p->input_imsi) > 0 &&
                mmi_ucs2strlen((S8*) g_sml_context_p->input_imsi) < MAX_NP_LEN - 1)
            {
                rtn = 0;
            }
            else
            {
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context_p->input_gid1);
                if ((U16) atoi(tmp_gid) > 0xFF)
                {
                    rtn = 0;
                }
            }
            break;
        case SML_CAT_C:
            if (mmi_ucs2strlen((S8*) g_sml_context_p->input_imsi) > 0 &&
                mmi_ucs2strlen((S8*) g_sml_context_p->input_imsi) < MAX_NP_LEN - 1)
            {
                rtn = 0;
            }
            else
            {
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context_p->input_gid1);
                if ((U16) atoi(tmp_gid) > 0xFF)
                {
                    rtn = 0;
                }
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context_p->input_gid2);
                if ((U16) atoi(tmp_gid) > 0xFF)
                {
                    rtn = 0;
                }
            }
            break;
        case SML_CAT_SIM:
            if (mmi_ucs2strlen((S8*) g_sml_context_p->input_imsi) > 0 &&
                mmi_ucs2strlen((S8*) g_sml_context_p->input_imsi) < MAX_IMSI_LEN)
            {
                rtn = 0;
            }
            break;
        case SML_CAT_NS_SP:
            if (mmi_ucs2strlen((S8*) g_sml_context_p->input_imsi) > 0 &&
                mmi_ucs2strlen((S8*) g_sml_context_p->input_imsi) < MAX_NSP_LEN - 1)
            {
                rtn = 0;
            }
            else
            {
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context_p->input_gid1);
                if ((U16) atoi(tmp_gid) > 0xFF)
                {
                    rtn = 0;
                }
            }
            break;
        case SML_CAT_SIM_C:
            if (mmi_ucs2strlen((S8*) g_sml_context_p->input_imsi) > 0 &&
                mmi_ucs2strlen((S8*) g_sml_context_p->input_imsi) < MAX_IMSI_LEN)
            {
                rtn = 0;
            }
            else
            {
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context_p->input_gid1);
                if ((U16) atoi(tmp_gid) > 0xFF)
                {
                    rtn = 0;
                }
                mmi_ucs2_to_asc(tmp_gid, (S8*) g_sml_context_p->input_gid2);
                if ((U16) atoi(tmp_gid) > 0xFF)
                {
                    rtn = 0;
                }
            }
            break;
        default:
            break;
    }

    return rtn;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_allow_to_lock_or_unlock
 * DESCRIPTION
 *  Allow to send lock or unlock reuqest to L4C or not
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_sml_allow_to_lock_or_unlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context_p->operation_type == SML_OP_LOCK || g_sml_context_p->operation_type == SML_OP_UNLOCK)
    {
        if (g_sml_context_p->retry_count[g_sml_context_p->selected_category] == 0)
        {
            mmi_sml_display_popup((UI_string_type) GetString(STR_ID_SML_BLOCK_MSG), MMI_EVENT_FAILURE);
            return 0;
        }

        if (g_sml_context_p->used_records[g_sml_context_p->selected_category] == 0)
        {
            mmi_sml_display_popup((UI_string_type) GetString(STR_ID_NO_DATA_MSG), MMI_EVENT_FAILURE);
            return 0;
        }

        if (g_sml_context_p->operation_type == SML_OP_LOCK &&
            g_sml_context_p->category_state[g_sml_context_p->selected_category] == SML_STATE_LOCK)
        {
            mmi_sml_display_popup((UI_string_type) GetString(STR_ID_SML_CAT_LOCKED), MMI_EVENT_FAILURE);
            return 0;
        }

        if (g_sml_context_p->operation_type == SML_OP_UNLOCK &&
            g_sml_context_p->category_state[g_sml_context_p->selected_category] == SML_STATE_UNLOCK)
        {
            mmi_sml_display_popup((UI_string_type) GetString(STR_ID_SML_CAT_UNLOCKED), MMI_EVENT_FAILURE);
            return 0;
        }

        if (g_sml_context_p->category_state[g_sml_context_p->selected_category] == SML_STATE_AUTOLOCK)
        {
            mmi_sml_display_popup((UI_string_type) GetString(STR_ID_SML_CAT_AUTOLOCKED), MMI_EVENT_FAILURE);
            return 0;
        }
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_allow_to_lock_or_unlock_2
 * DESCRIPTION
 *  Allow to send lock or unlock reuqest to L4C or not
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_sml_allow_to_lock_or_unlock_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context_p->operation_type == SML_OP_LOCK || g_sml_context_p->operation_type == SML_OP_UNLOCK)
    {
        if (g_sml_context_p->retry_count[g_sml_context_p->selected_category] == 0)
        {
            mmi_sml_display_popup_plus_delete_sim_selection_scrn((UI_string_type) GetString(STR_ID_SML_BLOCK_MSG), MMI_EVENT_FAILURE);
            return 0;
        }

        if (g_sml_context_p->used_records[g_sml_context_p->selected_category] == 0)
        {
            mmi_sml_display_popup_plus_delete_sim_selection_scrn((UI_string_type) GetString(STR_ID_NO_DATA_MSG), MMI_EVENT_FAILURE);
            return 0;
        }

        if (g_sml_context_p->operation_type == SML_OP_LOCK &&
            g_sml_context_p->category_state[g_sml_context_p->selected_category] == SML_STATE_LOCK)
        {
            mmi_sml_display_popup_plus_delete_sim_selection_scrn((UI_string_type) GetString(STR_ID_SML_CAT_LOCKED), MMI_EVENT_FAILURE);
            return 0;
        }

        if (g_sml_context_p->operation_type == SML_OP_UNLOCK &&
            g_sml_context_p->category_state[g_sml_context_p->selected_category] == SML_STATE_UNLOCK)
        {
            mmi_sml_display_popup_plus_delete_sim_selection_scrn((UI_string_type) GetString(STR_ID_SML_CAT_UNLOCKED), MMI_EVENT_FAILURE);
            return 0;
        }

        if (g_sml_context_p->category_state[g_sml_context_p->selected_category] == SML_STATE_AUTOLOCK)
        {
            mmi_sml_display_popup_plus_delete_sim_selection_scrn((UI_string_type) GetString(STR_ID_SML_CAT_AUTOLOCKED), MMI_EVENT_FAILURE);
            return 0;
        }
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_confirm_key
 * DESCRIPTION
 *  SML password confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_confirm_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
//    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SML_AUTO_KEY_GEN__
    if (mmi_ucs2strlen((S8*) gSMLNewPassword) == 0)
    {
        mmi_sml_entry_auto_key_gen_confirm();
        return;
    }
#endif /* __MMI_SML_AUTO_KEY_GEN__ */

    mmi_frm_scrn_enter(GRP_ID_SML_PSWD, SCR_ID_SML_CONFIRM_KEY, NULL, mmi_sml_confirm_key, MMI_FRM_SMALL_SCRN);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
//    inputBuffer = (U8*) mmi_frm_scrn_get_active_input_buf();

    /* Hide LSK if input password length is not enough */
    RegisterInputBoxValidationFunction(mmi_sml_password_screen_lsk_hdlr);

#ifdef __MMI_SMALL_PIN_EDIT_SCREEN__
    enable_resized_small_screen();
#endif 

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_ID_SML_CONFIRM_PASSWORD,
        IMM_INPUT_TYPE_NUMERIC_PASSWORD,
        gSMLConfirmPassword,
        (MAX_SML_UNLOCK_KEY_LENGTH + 1),
        NULL,
        guiBuffer);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_sml_verify_key_req, KEY_POUND, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_sml_verify_key_req, KEY_EVENT_UP);
    g_sml_common.password_len_callback = mmi_sml_verify_key_req;

    if (mmi_ucs2strlen((S8*) gSMLConfirmPassword) < MIN_SML_UNLOCK_KEY_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_group_pswd_proc
 * DESCRIPTION
 *  SIM-ME-Lock password screen group
 * PARAMETERS
 *  param
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_sml_group_pswd_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_EXIT:
            g_sml_common.auto_data = 0;
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_input_key
 * DESCRIPTION
 *  SML password input screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_input_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
//    U8 *inputBuffer;
    S8 temp1[MAX_PASS_COUNTDOWN_DISP];
    S8 temp2[MAX_PASS_COUNTDOWN_DISP];

    mmi_id group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_sml_allow_to_lock_or_unlock())
    {
        return;
    }

    if (g_sml_context_p->operation_type == SML_OP_ADD && mmi_sml_data_valid_check() == 0)
    {
        mmi_sml_display_popup((UI_string_type) GetString(STR_GLOBAL_INVALID_INPUT), MMI_EVENT_FAILURE);
        return;
    }

    group_id = mmi_frm_group_get_active_id();

    mmi_frm_group_create(group_id, GRP_ID_SML_PSWD, mmi_sml_group_pswd_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SML_PSWD, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(GRP_ID_SML_PSWD, SCR_ID_SML_INPUT_KEY, NULL, mmi_sml_input_key, MMI_FRM_SMALL_SCRN);

    sprintf(temp1, "%d", g_sml_context_p->retry_count[g_sml_context_p->selected_category]);
    mmi_asc_to_ucs2(temp2, temp1);
    mmi_ucs2cpy((S8*) temp1, (S8*) GetString(STR_ID_SML_REMAIN_TRIALS));
    mmi_ucs2cat((S8*) temp1, (S8*) temp2);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
//    inputBuffer = (U8*) mmi_frm_scrn_get_active_input_buf();

    /* Hide LSK if input password length is not enough */
    RegisterInputBoxValidationFunction(mmi_sml_password_screen_lsk_hdlr);

#ifdef __MMI_SMALL_PIN_EDIT_SCREEN__
    enable_resized_small_screen();
#endif 

    if (g_sml_context_p->key_state[g_sml_context_p->selected_category] == SML_KEY_SET ||
        (g_sml_context_p->key_state[g_sml_context_p->selected_category] == SML_KEY_EMPTY &&
         g_sml_context_p->operation_type == SML_OP_UNLOCK))
    {
        if (g_sml_context_p->operation_type == SML_OP_UNLOCK)
        {
            ShowCategory111Screen(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                STR_ID_SML_INPUT_PASSWORD,
                IMM_INPUT_TYPE_NUMERIC_PASSWORD,
                gSMLNewPassword,
                (MAX_SML_UNLOCK_KEY_LENGTH + 1),
                (U8*) temp1,    /* apply retry count */
                guiBuffer);
        }
        else
        {
            ShowCategory111Screen(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                STR_ID_SML_INPUT_PASSWORD,
                IMM_INPUT_TYPE_NUMERIC_PASSWORD,
                gSMLNewPassword,
                (MAX_SML_UNLOCK_KEY_LENGTH + 1),
                NULL,   /* retry count only works for unlocking a category */
                guiBuffer);
        }

        SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(mmi_sml_verify_key_req, KEY_POUND, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_sml_verify_key_req, KEY_EVENT_UP);
        g_sml_common.password_len_callback = mmi_sml_verify_key_req;
    }
    else
    {
        ShowCategory111Screen(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            STR_ID_SML_INPUT_PASSWORD,
            IMM_INPUT_TYPE_NUMERIC_PASSWORD,
            gSMLNewPassword,
            (MAX_SML_UNLOCK_KEY_LENGTH + 1),
            NULL,   /* need to input key twice */
            guiBuffer);

        SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(mmi_sml_confirm_key, KEY_POUND, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_sml_confirm_key, KEY_EVENT_UP);
        g_sml_common.password_len_callback = mmi_sml_confirm_key;
    }

    if (mmi_ucs2strlen((S8*) gSMLNewPassword) < MIN_SML_UNLOCK_KEY_LENGTH)
    {
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
        if (g_sml_context_p->operation_type == SML_OP_UNLOCK)
        {
            ChangeLeftSoftkey(0, 0);
        }
        else /* SML_OP_LOCK or SML_OP_ADD */
        {
        #ifdef __MMI_SML_AUTO_KEY_GEN__
            if (!(g_sml_context_p->key_state[g_sml_context_p->selected_category] == SML_KEY_EMPTY && mmi_ucs2strlen((S8*) gSMLNewPassword) == 0))
        #endif
                ChangeLeftSoftkey(0, 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_generic_highlight_handler
 * DESCRIPTION
 *  SML generic highlight handler
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_generic_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    S32 count = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sml_context_p->selected_category = (U8) index;

    /* count the deactivated items */
    for (i = 0; i < SML_CAT_SIZE; i++)
    {
        if (g_sml_context_p->category_state[i] == SML_STATE_DISABLE || g_sml_context_p->category_state[i] == SML_STATE_NULL)
        {
            g_sml_context_p->selected_category++;
        }
        else
        {
            count++;
        }

        if (count == index)
        {
            break;
        }
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_group_main_proc
 * DESCRIPTION
 *  SIM-ME-Lock main screen group
 * PARAMETERS
 *  param
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_sml_group_main_proc(mmi_event_struct *param)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_lock_category_selection
 * DESCRIPTION
 *  Lock catrgories entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_lock_category_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nNumofItem = 0;  /* Need to get response from SMU */
    U8 *guiBuffer;
    U16 aStrItemList[SML_CAT_SIZE] =
        {STR_ID_CATEGORY_NP_LOCK, STR_ID_CATEGORY_NSP_LOCK, STR_ID_CATEGORY_SP_LOCK, STR_ID_CATEGORY_CP_LOCK,
        STR_ID_CATEGORY_SIMP_LOCK, STR_ID_CATEGORY_NSP_SP_LOCK, STR_ID_CATEGORY_SIMP_CP_LOCK};
    U16 nStrItemList[SML_CAT_SIZE];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DUAL_SIM_MASTER__
    if (!mmi_bootup_is_sim_valid())
    {
        return;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SML_MAIN, mmi_sml_group_main_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SML_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(GRP_ID_SML_MAIN, SCR_ID_SML_LOCK_MENU, NULL, mmi_sml_entry_lock_category_selection, MMI_FRM_FULL_SCRN);
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mmi_sml_generic_highlight_handler);

    /* Hide some unsupported personalization categories */
    for (i = 0; i < SML_CAT_SIZE; i++)
    {
        if (g_sml_context_p->category_state[i] != SML_STATE_DISABLE && g_sml_context_p->category_state[i] != SML_STATE_NULL)
        {
            nStrItemList[nNumofItem] = aStrItemList[i];
            nNumofItem++;
        }
    }

    if (g_sml_context_p->operation_type != SML_OP_LOCK)
    {
        g_sml_context_p->operation_type = SML_OP_LOCK;
        g_sml_context_p->selected_category = 0;
    }

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    if (nNumofItem == 0)
    {
        ShowCategory2Screen(
            STR_ID_SML_LOCK_MENU,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            STR_ID_EMPTY_CATEGORY_MSG,
            NULL);

        SetLeftSoftkeyFunction(mmi_sml_leave_no_category_screen, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory11Screen(
            STR_ID_SML_LOCK_MENU,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            g_sml_context_p->selected_category,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_sml_input_key, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

        SetCenterSoftkeyFunction(mmi_sml_input_key, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_unlock_category_selection
 * DESCRIPTION
 *  Unlock catrgories entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_unlock_category_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nNumofItem = 0;  /* Need to get response from SMU */
    U8 *guiBuffer;
    U16 aStrItemList[SML_CAT_SIZE] =
        {STR_ID_CATEGORY_NP_LOCK, STR_ID_CATEGORY_NSP_LOCK, STR_ID_CATEGORY_SP_LOCK, STR_ID_CATEGORY_CP_LOCK,
        STR_ID_CATEGORY_SIMP_LOCK, STR_ID_CATEGORY_NSP_SP_LOCK, STR_ID_CATEGORY_SIMP_CP_LOCK};
    U16 nStrItemList[SML_CAT_SIZE];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DUAL_SIM_MASTER__
    if (!mmi_bootup_is_sim_valid())
    {
        return;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SML_MAIN, mmi_sml_group_main_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SML_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(GRP_ID_SML_MAIN, SCR_ID_SML_UNLOCK_MENU, NULL, mmi_sml_entry_unlock_category_selection, MMI_FRM_FULL_SCRN);
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mmi_sml_generic_highlight_handler);

    /* Hide some unsupported personalization categories */
    for (i = 0; i < SML_CAT_SIZE; i++)
    {
        if (g_sml_context_p->category_state[i] != SML_STATE_DISABLE && g_sml_context_p->category_state[i] != SML_STATE_NULL)
        {
            nStrItemList[nNumofItem] = aStrItemList[i];
            nNumofItem++;
        }
    }

    if (g_sml_context_p->operation_type != SML_OP_UNLOCK)
    {
        g_sml_context_p->operation_type = SML_OP_UNLOCK;
        g_sml_context_p->selected_category = 0;
    }

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    if (nNumofItem == 0)
    {
        ShowCategory2Screen(
            STR_ID_SML_UNLOCK_MENU,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            STR_ID_EMPTY_CATEGORY_MSG,
            NULL);

        SetLeftSoftkeyFunction(mmi_sml_leave_no_category_screen, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory11Screen(
            STR_ID_SML_UNLOCK_MENU,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            g_sml_context_p->selected_category,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_sml_input_key, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

        SetCenterSoftkeyFunction(mmi_sml_input_key, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_fill_add_data_editor
 * DESCRIPTION
 *  Inline editor of add data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_fill_add_data_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_sml_context_p->selected_category)
    {
        case SML_CAT_NS:
        case SML_CAT_NS_SP:
            SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_SML_NSP_DATA));

            SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[1],
                (PU8) g_sml_context_p->input_imsi,
                MAX_NSP_LEN + 1,
                IMM_INPUT_TYPE_NUMERIC);
            break;

        case SML_CAT_SIM:
        case SML_CAT_SIM_C:
            SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_SML_SIMP_DATA));

            SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[1],
                (PU8) g_sml_context_p->input_imsi,
                MAX_IMSI_LEN + 1,
                IMM_INPUT_TYPE_NUMERIC);

            break;

        case SML_CAT_N:
        case SML_CAT_SP:
        case SML_CAT_C:
        default:
            SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_SML_NP_DATA));

            SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[1],
                (PU8) g_sml_context_p->input_imsi,
                MAX_NP_LEN + 1,
                IMM_INPUT_TYPE_NUMERIC);

            break;
    }

    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_ID_SML_SP_DATA));

    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[3], (PU8) g_sml_context_p->input_gid1, MAX_GID_LEN + 1, IMM_INPUT_TYPE_NUMERIC);

    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString(STR_ID_SML_CP_DATA));

    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[5], (PU8) g_sml_context_p->input_gid2, MAX_GID_LEN + 1, IMM_INPUT_TYPE_NUMERIC);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_process_add_data
 * DESCRIPTION
 *  Process of user input add data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_process_add_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) g_sml_context_p->input_imsi) == 0 /* && mmi_ucs2strlen((S8*)g_sml_context_p->input_gid1) == 0 */)
    {
        /* query for read data from SIM */
        mmi_sml_read_data_from_sim_query();
    }
    else
    {
        /* lock it */
        g_sml_common.auto_data = 0;
        mmi_sml_input_key();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_group_data_proc
 * DESCRIPTION
 *  SIM-ME-Lock data screen group
 * PARAMETERS
 *  param
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_sml_group_data_proc(mmi_event_struct *param)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    cui_event_inline_submit_struct *inline_submit_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
//            inline_submit_event = (cui_event_inline_submit_struct*) param;

            cui_inline_get_value(g_sml_common.inline_cui_id, CUI_INLINE_ITEM_ID_BASE + 1, (void*) g_sml_context_p->input_imsi);
            if (g_sml_context_p->selected_category == SML_CAT_SP ||
                g_sml_context_p->selected_category == SML_CAT_C ||
                g_sml_context_p->selected_category == SML_CAT_NS_SP ||
                g_sml_context_p->selected_category == SML_CAT_SIM_C)
            {
                cui_inline_get_value(g_sml_common.inline_cui_id, CUI_INLINE_ITEM_ID_BASE + 3, (void*) g_sml_context_p->input_gid1);
            }
            if (g_sml_context_p->selected_category == SML_CAT_C ||
                g_sml_context_p->selected_category == SML_CAT_SIM_C)
            {
                cui_inline_get_value(g_sml_common.inline_cui_id, CUI_INLINE_ITEM_ID_BASE + 5, (void*) g_sml_context_p->input_gid2);
            }

            mmi_sml_process_add_data();
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(g_sml_common.inline_cui_id);
            g_sml_common.inline_cui_id = 0;
            break;

        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
            if (g_sml_common.auto_data != 0)
            {
                mmi_sml_input_key();
            }
            break;

        case EVT_ID_CUI_INLINE_GROUP_DEINIT:
                g_sml_common.auto_data = 0;
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_add_data
 * DESCRIPTION
 *  Entry screen of input data to add
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_add_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context_p->category_state[g_sml_context_p->selected_category] == SML_STATE_LOCK)
    {
        mmi_sml_display_popup((UI_string_type) GetString(STR_ID_UNLOCK_FIRST_MSG), MMI_EVENT_FAILURE);
        return;
    }

    if (g_sml_context_p->used_records[g_sml_context_p->selected_category] ==
        g_sml_context_p->total_records[g_sml_context_p->selected_category])
    {
        mmi_sml_display_popup((UI_string_type) GetString(STR_ID_NO_RECORD_MSG), MMI_EVENT_FAILURE);
        return;
    }

    if (g_sml_context_p->category_state[g_sml_context_p->selected_category] == SML_STATE_AUTOLOCK)
    {
        mmi_sml_display_popup((UI_string_type) GetString(STR_ID_SML_CAT_AUTOLOCKED), MMI_EVENT_FAILURE);
        return;
    }

    mmi_sml_reset_input_buffer();

    switch (g_sml_context_p->selected_category)
    {
        case SML_CAT_N:
            mmi_sml_data_netcode_cap.string_id = STR_ID_SML_NP_DATA;
            mmi_sml_data_netcode_val.buffer_size = MAX_NP_LEN + 1,
            mmi_sml_data_screen.items_count = 2;
            break;
        case SML_CAT_NS:
            mmi_sml_data_netcode_cap.string_id = STR_ID_SML_NSP_DATA;
            mmi_sml_data_netcode_val.buffer_size = MAX_NSP_LEN + 1,
            mmi_sml_data_screen.items_count = 2;
            break;
        case SML_CAT_SP:
            mmi_sml_data_netcode_cap.string_id = STR_ID_SML_NP_DATA;
            mmi_sml_data_netcode_val.buffer_size = MAX_NP_LEN + 1,
            mmi_sml_data_screen.items_count = 4;
            break;
        case SML_CAT_C:
            mmi_sml_data_netcode_cap.string_id = STR_ID_SML_NP_DATA;
            mmi_sml_data_netcode_val.buffer_size = MAX_NP_LEN + 1,
            mmi_sml_data_screen.items_count = 6;
            break;
        case SML_CAT_SIM:
            mmi_sml_data_netcode_cap.string_id = STR_ID_SML_SIMP_DATA;
            mmi_sml_data_netcode_val.buffer_size = MAX_IMSI_LEN + 1;
            mmi_sml_data_screen.items_count = 2;
            break;
        case SML_CAT_NS_SP:
            mmi_sml_data_netcode_cap.string_id = STR_ID_SML_NSP_DATA;
            mmi_sml_data_netcode_val.buffer_size = MAX_NSP_LEN + 1,
            mmi_sml_data_screen.items_count = 4;
            break;
        case SML_CAT_SIM_C:
            mmi_sml_data_netcode_cap.string_id = STR_ID_SML_SIMP_DATA;
            mmi_sml_data_netcode_val.buffer_size = MAX_IMSI_LEN + 1,
            mmi_sml_data_screen.items_count = 6;
            break;
        default:
            break;
    }

    inline_id = cui_inline_create(GRP_ID_SML_DATA, &mmi_sml_data_screen); 

    switch (g_sml_context_p->selected_category)
    {
        case SML_CAT_C:
        case SML_CAT_SIM_C:
            cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + 5, (void*) g_sml_context_p->input_gid2);

        case SML_CAT_SP:
        case SML_CAT_NS_SP:
            cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + 3, (void*) g_sml_context_p->input_gid1);

        case SML_CAT_N:
        case SML_CAT_NS:
        case SML_CAT_SIM:
            cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + 1, (void*) g_sml_context_p->input_imsi);
            break;
            
        default:
            break;  
    }

    cui_inline_run(inline_id);
    
    g_sml_common.inline_cui_id = inline_id;
//    g_sml_context_p->inline_group_id = mmi_frm_group_get_active_id();
//    g_sml_context_p->inline_scrn_id = mmi_frm_scrn_get_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_auto_generate_data
 * DESCRIPTION
 *  Automatic data generation from SIM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_auto_generate_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sml_reset_input_buffer();

    switch (g_sml_context_p->selected_category)
    {
        case SML_CAT_N:
            mmi_asc_n_to_ucs2(
                (S8*) g_sml_context_p->input_imsi,
                (S8*) g_sml_context_p->imsi,
                g_sml_context_p->digits_of_mcc_mnc);
            break;
        case SML_CAT_NS:
            mmi_asc_n_to_ucs2(
                (S8*) g_sml_context_p->input_imsi,
                (S8*) g_sml_context_p->imsi,
                g_sml_context_p->digits_of_mcc_mnc + 2);
            break;
        case SML_CAT_SP:    /* 5 or 6 digits of IMSI + GID1 */
            if (!mmi_sml_is_gid1_valid())
            {
                mmi_sml_display_popup((UI_string_type) GetString(STR_ID_SML_NO_EF_GID), MMI_EVENT_FAILURE);
                return;
            }
            mmi_asc_n_to_ucs2(
                (S8*) g_sml_context_p->input_imsi,
                (S8*) g_sml_context_p->imsi,
                g_sml_context_p->digits_of_mcc_mnc);
            gui_itoa(g_sml_context_p->gid1, (U16*) (&g_sml_context_p->input_gid1[0]), 10);
            break;
        case SML_CAT_C: /* 5 or 6 digits of IMSI + GID1 + GID2 */
            if (!mmi_sml_is_gid1_valid() || !mmi_sml_is_gid2_valid())
            {
                mmi_sml_display_popup((UI_string_type) GetString(STR_ID_SML_NO_EF_GID), MMI_EVENT_FAILURE);
                return;
            }
            mmi_asc_n_to_ucs2(
                (S8*) g_sml_context_p->input_imsi,
                (S8*) g_sml_context_p->imsi,
                g_sml_context_p->digits_of_mcc_mnc);
            gui_itoa(g_sml_context_p->gid1, (U16*) (&g_sml_context_p->input_gid1[0]), 10);
            gui_itoa(g_sml_context_p->gid2, (U16*) (&g_sml_context_p->input_gid2[0]), 10);
            break;
        case SML_CAT_SIM:   /* IMSI */
            mmi_asc_to_ucs2((S8*) g_sml_context_p->input_imsi, (S8*) g_sml_context_p->imsi);
            break;
        case SML_CAT_NS_SP: /* 7 or 8 digits of IMSI + GID1 */
            if (!mmi_sml_is_gid1_valid())
            {
                mmi_sml_display_popup((UI_string_type) GetString(STR_ID_SML_NO_EF_GID), MMI_EVENT_FAILURE);
                return;
            }
            mmi_asc_n_to_ucs2(
                (S8*) g_sml_context_p->input_imsi,
                (S8*) g_sml_context_p->imsi,
                g_sml_context_p->digits_of_mcc_mnc + 2);
            gui_itoa(g_sml_context_p->gid1, (U16*) (&g_sml_context_p->input_gid1[0]), 10);
            break;
        case SML_CAT_SIM_C: /* IMSI + GID1 + GID2 */
            if (!mmi_sml_is_gid1_valid() || !mmi_sml_is_gid2_valid())
            {
                mmi_sml_display_popup((UI_string_type) GetString(STR_ID_SML_NO_EF_GID), MMI_EVENT_FAILURE);
                return;
            }
            mmi_asc_to_ucs2((S8*) g_sml_context_p->input_imsi, (S8*) g_sml_context_p->imsi);
            gui_itoa(g_sml_context_p->gid1, (U16*) (&g_sml_context_p->input_gid1[0]), 10);
            gui_itoa(g_sml_context_p->gid2, (U16*) (&g_sml_context_p->input_gid2[0]), 10);
            break;
        default:
            break;
    }

    g_sml_common.auto_data = 1;

    mmi_sml_display_popup((UI_string_type) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_read_data_from_sim_query
 * DESCRIPTION
 *  Query for automatically read data from SIM to add
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_read_data_from_sim_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_struct;
    mmi_id group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = GRP_ID_SML_DATA;//mmi_frm_group_get_active_id();

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    mmi_confirm_property_init(&confirm_struct, CNFM_TYPE_YESNO);
    confirm_struct.parent_id = group_id;
    mmi_confirm_display(
        (WCHAR *) GetString(STR_ID_SML_QUREY_MSG), 
        MMI_EVENT_QUERY, 
        &confirm_struct);

    SetLeftSoftkeyFunction(mmi_sml_auto_generate_data, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_sml_auto_generate_data, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_add_category_data
 * DESCRIPTION
 *  Add data catrgories entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_add_category_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nNumofItem = 0;  /* Need to get response from SMU */
    U8 *guiBuffer;
    U16 aStrItemList[SML_CAT_SIZE] =
        {STR_ID_CATEGORY_NP_LOCK, STR_ID_CATEGORY_NSP_LOCK, STR_ID_CATEGORY_SP_LOCK, STR_ID_CATEGORY_CP_LOCK,
        STR_ID_CATEGORY_SIMP_LOCK, STR_ID_CATEGORY_NSP_SP_LOCK, STR_ID_CATEGORY_SIMP_CP_LOCK};
    U16 nStrItemList[SML_CAT_SIZE];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DUAL_SIM_MASTER__
    if (!mmi_bootup_is_sim_valid())
    {
        return;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SML_DATA, mmi_sml_group_data_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SML_DATA, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(GRP_ID_SML_DATA, SCR_ID_SML_ADD_MENU, NULL, mmi_sml_entry_add_category_data, MMI_FRM_FULL_SCRN);
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mmi_sml_generic_highlight_handler);

    /* Hide some unsupported personalization categories */
    for (i = 0; i < SML_CAT_SIZE; i++)
    {
        if (g_sml_context_p->category_state[i] != SML_STATE_DISABLE && g_sml_context_p->category_state[i] != SML_STATE_NULL)
        {
            nStrItemList[nNumofItem] = aStrItemList[i];
            nNumofItem++;
        }
    }

    if (g_sml_context_p->operation_type != SML_OP_ADD)
    {
        g_sml_context_p->operation_type = SML_OP_ADD;
        g_sml_context_p->selected_category = 0;
    }

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    if (nNumofItem == 0)
    {
        ShowCategory2Screen(
            STR_ID_SML_ADD_MENU,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            STR_ID_EMPTY_CATEGORY_MSG,
            NULL);

        SetLeftSoftkeyFunction(mmi_sml_leave_no_category_screen, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory11Screen(
            STR_ID_SML_ADD_MENU,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            g_sml_context_p->selected_category,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_sml_entry_add_data, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

        SetCenterSoftkeyFunction(mmi_sml_entry_add_data, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_send_delete_req
 * DESCRIPTION
 *  Remove data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_send_delete_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sml_set_personalization_req(NULL, g_sml_context_p->selected_category, g_sml_context_p->operation_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_remove_confirm
 * DESCRIPTION
 *  Remove data confirmation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_remove_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context_p->category_state[g_sml_context_p->selected_category] == SML_STATE_LOCK)
    {
        mmi_sml_display_popup((UI_string_type) GetString(STR_ID_UNLOCK_FIRST_MSG), MMI_EVENT_FAILURE);
        return;
    }

    if (g_sml_context_p->used_records[g_sml_context_p->selected_category] == 0)
    {
        mmi_sml_display_popup((UI_string_type) GetString(STR_ID_NO_DATA_MSG), MMI_EVENT_FAILURE);
        return;
    }

    if (g_sml_context_p->category_state[g_sml_context_p->selected_category] == SML_STATE_AUTOLOCK)
    {
        mmi_sml_display_popup((UI_string_type) GetString(STR_ID_SML_CAT_AUTOLOCKED), MMI_EVENT_FAILURE);
        return;
    }

    mmi_confirm_property_init(&confirm_struct, CNFM_TYPE_YESNO);
    confirm_struct.parent_id = GRP_ID_SML_MAIN;
    mmi_confirm_display(
        (WCHAR *) GetString(STR_ID_SML_ASK_DELETE_CATEGORY), 
        MMI_EVENT_QUERY, 
        &confirm_struct);

    SetLeftSoftkeyFunction(mmi_sml_send_delete_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_remove_category_data
 * DESCRIPTION
 *  Remove data catrgories entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_remove_category_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nNumofItem = 0;  /* Need to get response from SMU */
    U8 *guiBuffer;
    U16 aStrItemList[SML_CAT_SIZE] =
        {STR_ID_CATEGORY_NP_LOCK, STR_ID_CATEGORY_NSP_LOCK, STR_ID_CATEGORY_SP_LOCK, STR_ID_CATEGORY_CP_LOCK,
        STR_ID_CATEGORY_SIMP_LOCK, STR_ID_CATEGORY_NSP_SP_LOCK, STR_ID_CATEGORY_SIMP_CP_LOCK};
    U16 nStrItemList[SML_CAT_SIZE];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DUAL_SIM_MASTER__
    if (!mmi_bootup_is_sim_valid())
    {
        return;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SML_MAIN, mmi_sml_group_main_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SML_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(GRP_ID_SML_MAIN, SCR_ID_SML_REMOVE_MENU, NULL, mmi_sml_entry_remove_category_data, MMI_FRM_FULL_SCRN);
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mmi_sml_generic_highlight_handler);

    /* Hide some unsupported personalization categories */
    for (i = 0; i < SML_CAT_SIZE; i++)
    {
        if (g_sml_context_p->category_state[i] != SML_STATE_DISABLE && g_sml_context_p->category_state[i] != SML_STATE_NULL)
        {
            nStrItemList[nNumofItem] = aStrItemList[i];
            nNumofItem++;
        }
    }

    if (g_sml_context_p->operation_type != SML_OP_REMOVE)
    {
        g_sml_context_p->operation_type = SML_OP_REMOVE;
        g_sml_context_p->selected_category = 0;
    }

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    if (nNumofItem == 0)
    {
        ShowCategory2Screen(
            STR_ID_SML_REMOVE_MENU,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            STR_ID_EMPTY_CATEGORY_MSG,
            NULL);

        SetLeftSoftkeyFunction(mmi_sml_leave_no_category_screen, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory11Screen(
            STR_ID_SML_REMOVE_MENU,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            g_sml_context_p->selected_category,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_sml_entry_remove_confirm, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

        SetCenterSoftkeyFunction(mmi_sml_entry_remove_confirm, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_deactivate_confirm
 * DESCRIPTION
 *  Permanent unlock confirmation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_deactivate_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context_p->category_state[g_sml_context_p->selected_category] == SML_STATE_LOCK)
    {
        mmi_sml_display_popup((UI_string_type) GetString(STR_ID_UNLOCK_FIRST_MSG), MMI_EVENT_FAILURE);
        return;
    }

    if (g_sml_context_p->category_state[g_sml_context_p->selected_category] == SML_STATE_AUTOLOCK)
    {
        mmi_sml_display_popup((UI_string_type) GetString(STR_ID_SML_CAT_AUTOLOCKED), MMI_EVENT_FAILURE);
        return;
    }

    mmi_confirm_property_init(&confirm_struct, CNFM_TYPE_YESNO);
    confirm_struct.parent_id = GRP_ID_SML_MAIN;
    mmi_confirm_display(
        (WCHAR *) GetString(STR_ID_SML_ASK_DISABLE_CATEGORY), 
        MMI_EVENT_QUERY, 
        &confirm_struct);

    SetLeftSoftkeyFunction(mmi_sml_send_delete_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_permanent_unlock_selection
 * DESCRIPTION
 *  Permanent unlock catrgories entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_permanent_unlock_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nNumofItem = 0;  /* Need to get response from SMU */
    U8 *guiBuffer;
    U16 aStrItemList[SML_CAT_SIZE] =
        {STR_ID_CATEGORY_NP_LOCK, STR_ID_CATEGORY_NSP_LOCK, STR_ID_CATEGORY_SP_LOCK, STR_ID_CATEGORY_CP_LOCK,
        STR_ID_CATEGORY_SIMP_LOCK, STR_ID_CATEGORY_NSP_SP_LOCK, STR_ID_CATEGORY_SIMP_CP_LOCK};
    U16 nStrItemList[SML_CAT_SIZE];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DUAL_SIM_MASTER__
    if (!mmi_bootup_is_sim_valid())
    {
        return;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SML_MAIN, mmi_sml_group_main_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SML_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(GRP_ID_SML_MAIN, SCR_ID_SML_DEACTIVATE_MENU, NULL, mmi_sml_entry_permanent_unlock_selection, MMI_FRM_FULL_SCRN);
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mmi_sml_generic_highlight_handler);

    /* Hide some unsupported personalization categories */
    for (i = 0; i < SML_CAT_SIZE; i++)
    {
        if (g_sml_context_p->category_state[i] != SML_STATE_DISABLE && g_sml_context_p->category_state[i] != SML_STATE_NULL)
        {
            nStrItemList[nNumofItem] = aStrItemList[i];
            nNumofItem++;
        }
    }

    if (g_sml_context_p->operation_type != SML_OP_DISABLE)
    {
        g_sml_context_p->operation_type = SML_OP_DISABLE;
        g_sml_context_p->selected_category = 0;
    }

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    if (nNumofItem == 0)
    {
        ShowCategory2Screen(
            STR_ID_SML_DEACTIVATE_MENU,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            STR_ID_EMPTY_CATEGORY_MSG,
            NULL);

        SetLeftSoftkeyFunction(mmi_sml_leave_no_category_screen, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory11Screen(
            STR_ID_SML_DEACTIVATE_MENU,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            g_sml_context_p->selected_category,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_sml_entry_deactivate_confirm, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

        SetCenterSoftkeyFunction(mmi_sml_entry_deactivate_confirm, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_send_lock_req_by_ssc
 * DESCRIPTION
 *  SSC for lock status query
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_sml_send_lock_req_by_ssc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ansii_ssc_string[MAX_DIAL_PAD];
    U8 *ptr1, *ptr2 = NULL;
    U8 i, count = 0, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DUAL_SIM_MASTER__
    mmi_ucs2_to_asc((S8*) g_sml_common.dial_string, (S8*) mmi_dialer_get_dial_string());
#endif
    strcpy((S8*) ansii_ssc_string, (S8*) g_sml_common.dial_string);

    if (memcmp(ansii_ssc_string, SSC_SML_LOCK_CMD, strlen(SSC_SML_LOCK_CMD)) == 0)
    {
        ptr1 = ansii_ssc_string + strlen(SSC_SML_LOCK_CMD);
        len = strlen((S8*) ptr1);

        for (i = 0; i < len; i++)
        {
            if (*(ptr1 + i) == '#')
            {
                count++;
                *(ptr1 + i) = 0;
                if (count == 1)
                {
                    ptr2 = ptr1 + i + 1;
                }
            }
        }

        if (count < 2)
        {
            /* input unfinished */
            return 0;
        }
        else
        {
            if (strlen((S8*) ptr1) > MAX_SML_UNLOCK_KEY_LENGTH || strlen((S8*) ptr1) < MIN_SML_UNLOCK_KEY_LENGTH)
            {
                mmi_popup_display(
                    get_string(STR_ID_SML_INVALID_LENGTH),
                    MMI_EVENT_FAILURE,
                    NULL);
                return 0;
            }

            /* send request */
            g_sml_context_p->selected_category = (U8) atoi((S8*) ptr2) - 1;

            if (strlen((S8*) ptr2) == 1 && g_sml_context_p->selected_category < SML_CAT_SIZE)
            {
                if (g_sml_context_p->category_state[g_sml_context_p->selected_category] == SML_STATE_DISABLE)
                {
                #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
                #endif
                    /* deactivated category */
                    return 0;
                }

                g_sml_context_p->operation_type = SML_OP_LOCK;

                if (!mmi_sml_allow_to_lock_or_unlock_2())
                {
                    return 0;
                }

                g_sml_context_p->action_not_from_menu = 1;
                mmi_sml_set_personalization_req(ptr1, g_sml_context_p->selected_category, SML_OP_LOCK);
                return 1;
            }
        }
    }

    /* wrong case for this function */
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_send_unlock_req_by_ssc
 * DESCRIPTION
 *  SSC for unlock status query
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_sml_send_unlock_req_by_ssc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ansii_ssc_string[MAX_DIAL_PAD];
    U8 *ptr1, *ptr2 = NULL;
    U8 i, count = 0, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DUAL_SIM_MASTER__
    mmi_ucs2_to_asc((S8*) g_sml_common.dial_string, (S8*) mmi_dialer_get_dial_string());
#endif
    strcpy((S8*) ansii_ssc_string, (S8*) g_sml_common.dial_string);

    if (memcmp(ansii_ssc_string, SSC_SML_UNLOCK_CMD, strlen(SSC_SML_UNLOCK_CMD)) == 0)
    {
        ptr1 = ansii_ssc_string + strlen(SSC_SML_UNLOCK_CMD);
        len = strlen((S8*) ptr1);

        for (i = 0; i < len; i++)
        {
            if (*(ptr1 + i) == '#')
            {
                count++;
                *(ptr1 + i) = 0;
                if (count == 1)
                {
                    ptr2 = ptr1 + i + 1;
                }
            }
        }

        if (count < 2)
        {
            /* input unfinished */
            return 0;
        }
        else
        {
            if (strlen((S8*) ptr1) > MAX_SML_UNLOCK_KEY_LENGTH || strlen((S8*) ptr1) < MIN_SML_UNLOCK_KEY_LENGTH)
            {
                mmi_popup_display(
                    get_string(STR_ID_SML_INVALID_LENGTH),
                    MMI_EVENT_FAILURE,
                    NULL);
                return 0;
            }

            /* send request */
            g_sml_context_p->selected_category = (U8) atoi((S8*) ptr2) - 1;

            if (strlen((S8*) ptr2) == 1 && g_sml_context_p->selected_category < SML_CAT_SIZE)
            {
                if (g_sml_context_p->category_state[g_sml_context_p->selected_category] == SML_STATE_DISABLE)
                {
                #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
                #endif
                    /* deactivated category */
                    return 0;
                }

                g_sml_context_p->operation_type = SML_OP_UNLOCK;

                if (!mmi_sml_allow_to_lock_or_unlock_2())
                {
                    return 0;
                }

                g_sml_context_p->action_not_from_menu = 1;
                mmi_sml_set_personalization_req(ptr1, g_sml_context_p->selected_category, SML_OP_UNLOCK);
                return 1;
            }
        }
    }

	/* wrong case for this function */
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_send_query_rsp_by_ssc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_send_query_rsp_by_ssc(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_sml_status_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_sml_status_rsp_struct*) (info);

    mmi_sml_clear_protocol_event_handler(PRT_MMI_SMU_SML_STATUS_RSP);

    /* display this category is locked or unlocked */
    if (resp->state[g_sml_context_p->selected_category] == SML_STATE_AUTOLOCK)
    {
        mmi_sml_display_popup_plus_delete_sim_selection_scrn((UI_string_type) GetString(STR_ID_SML_CAT_AUTOLOCKED), MMI_EVENT_SUCCESS);
    }
    else if (resp->state[g_sml_context_p->selected_category] == SML_STATE_LOCK)
    {
        mmi_sml_display_popup_plus_delete_sim_selection_scrn((UI_string_type) GetString(STR_ID_SML_CAT_LOCKED), MMI_EVENT_SUCCESS);
    }
    else
    {
        mmi_sml_display_popup_plus_delete_sim_selection_scrn((UI_string_type) GetString(STR_ID_SML_CAT_UNLOCKED), MMI_EVENT_SUCCESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_send_query_req_by_ssc
 * DESCRIPTION
 *  SSC for lock or unlock status query
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_sml_send_query_req_by_ssc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ansii_ssc_string[MAX_DIAL_PAD];
    U8 *ptr1;
    U8 i, count = 0, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DUAL_SIM_MASTER__
    mmi_ucs2_to_asc((S8*) g_sml_common.dial_string, (S8*) mmi_dialer_get_dial_string());
#endif
    strcpy((S8*) ansii_ssc_string, (S8*) g_sml_common.dial_string);

    if (memcmp(ansii_ssc_string, SSC_SML_QUERY_CMD, strlen(SSC_SML_QUERY_CMD)) == 0)
    {
        ptr1 = ansii_ssc_string + strlen(SSC_SML_QUERY_CMD);
        len = strlen((S8*) ptr1);

        for (i = 0; i < len; i++)
        {
            if (*(ptr1 + i) == '#')
            {
                count++;
                *(ptr1 + i) = 0;
            }
        }

        if (count < 1)
        {
            /* input unfinished */
            return 0;
        }
        else
        {
            g_sml_context_p->selected_category = (U8) atoi((S8*) ptr1) - 1;

            if (strlen((S8*) ptr1) == 1 && g_sml_context_p->selected_category < SML_CAT_SIZE)
            {
                if (g_sml_context_p->category_state[g_sml_context_p->selected_category] == SML_STATE_DISABLE)
                {
                #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
                #endif
                    /* deactivated category */
                    return 0;
                }

                /* send request */
                ClearAllKeyHandler();   /* ClearInputEventHandler(MMI_DEVICE_ALL); */
                mmi_sml_set_protocol_event_handler(mmi_sml_send_query_rsp_by_ssc, PRT_MMI_SMU_SML_STATUS_RSP);
                mmi_frm_send_ilm(mmi_sml_get_message_dest_module(), PRT_MMI_SMU_SML_STATUS_REQ, NULL, NULL);
                return 1;
            }
            else
            {
                /* wrong category */
                return 0;
            }
        }
    }
    else
    {
        /* wrong case for this function */
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_power_on_query_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#else
void mmi_sml_power_on_query_rsp(void *info)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_sml_status_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_sml_status_rsp_struct*) (info);

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

    //mmi_sml_clear_protocol_event_handler(PRT_MMI_SMU_SML_STATUS_RSP);

    memcpy(g_sml_context_p->category_state, resp->state, SML_CAT_SIZE);
    memcpy(g_sml_context_p->key_state, resp->key_state, SML_CAT_SIZE);
    memcpy(g_sml_context_p->total_records, resp->total_size_of_cat, SML_CAT_SIZE);
    memcpy(g_sml_context_p->used_records, resp->num_of_sets, SML_CAT_SIZE);
    memcpy(g_sml_context_p->retry_count, resp->retry_count, SML_CAT_SIZE);

    memset(g_sml_context_p->imsi, 0, MAX_IMSI_LEN + 1);
    strncpy((S8*) g_sml_context_p->imsi, (S8*) (resp->imsi) + 1, MAX_IMSI_LEN);

    g_sml_context_p->gid_valid_nibble = 0;
    if (resp->is_valid_gid1)
    {
        g_sml_context_p->gid_valid_nibble |= 0x01;
        g_sml_context_p->gid1 = resp->ef_gid1;
    }
    if (resp->is_valid_gid2)
    {
        g_sml_context_p->gid_valid_nibble |= 0x10;
        g_sml_context_p->gid2 = resp->ef_gid2;
    }

    if (resp->digits_of_mnc == 0)
    {
        g_sml_context_p->digits_of_mcc_mnc = 5;    /* default */
    }
    else
    {
        g_sml_context_p->digits_of_mcc_mnc = resp->digits_of_mnc + 3;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_power_on_query_req
 * DESCRIPTION
 *  Power on period query
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_power_on_query_req(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_sml_power_on_query_rsp, PRT_MMI_SMU_SML_STATUS_RSP);

    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(sim), PRT_MMI_SMU_SML_STATUS_REQ, NULL, NULL);
}


#ifndef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sml_auto_locked_fail
 * DESCRIPTION
 *  Auto lock a test SIM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sml_auto_locked_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sml_display_popup((UI_string_type) GetString(STR_ID_SML_FAIL_TO_AUTOLOCK), MMI_EVENT_WARNING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_auto_locked_done
 * DESCRIPTION
 *  Auto lock a normal SIM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sml_auto_locked_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sml_display_popup((UI_string_type) GetString(STR_ID_SML_AUTOLOCKED), MMI_EVENT_SUCCESS);
}
#endif /* __MMI_DUAL_SIM_MASTER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_display_auto_locked_notification
 * DESCRIPTION
 *  Display a popup for auto locked SIM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_display_auto_locked_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (g_sml_context_p->autolock_nibble != 0)
    {
        if (g_sml_context_p->autolock_nibble & 0x10)
        {
            StartTimer(SML_AUTOLOCK_IDLE_NOTIFY_TIMER, 3000, mmi_sml_auto_locked_done);
        }
        else
        {
            StartTimer(SML_AUTOLOCK_IDLE_NOTIFY_TIMER, 3000, mmi_sml_auto_locked_fail);
        }
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_get_message_dest_module
 * DESCRIPTION
 *  Get the destination module ID to send SIM-ME-Lock message to
 * PARAMETERS
 *  void
 * RETURNS
 *  module_type
 *****************************************************************************/
module_type mmi_sml_get_message_dest_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */
    return MOD_L4C;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_set_protocol_event_handler
 * DESCRIPTION
 *  SML wrapper for set protocol event handler
 * PARAMETERS
 *  funcPtr         [IN]
 *  eventID         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_set_protocol_event_handler(PsFuncPtr funcPtr, U16 eventID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(funcPtr, eventID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_clear_protocol_event_handler
 * DESCRIPTION
 *  SML wrapper for set protocol event handler
 * PARAMETERS
 *  eventID         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_clear_protocol_event_handler(U16 eventID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(eventID);
}


#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */


#ifdef __SIM_HOT_SWAP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sml_get_active_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_sim_enum
 *****************************************************************************/
static mmi_sim_enum mmi_sml_get_active_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sml_context_p == &g_sml_context)
    {
        return MMI_SIM1;
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else if (g_sml_context_p == &g_sml_context_2)
    {
        return MMI_SIM2;
    }
#endif
    else
    {
        return MMI_SIM_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_sim_status_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_sml_sim_event_detetced(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_event_detected_evt_struct *sim_ctrl_evt = (srv_sim_ctrl_event_detected_evt_struct*)evt;

    MMI_BOOL is_in_sims_group;
    MMI_BOOL is_in_main_group;
    MMI_BOOL is_in_data_group;
    MMI_BOOL is_in_pswd_group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_ctrl_evt->type)
    {
        case SRV_SIM_CTRL_EVENT_DET_BT_ACCESS_ON:
        case SRV_SIM_CTRL_EVENT_DET_DISCONNECTED:
        case SRV_SIM_CTRL_EVENT_DET_REMOVED:
        {
            is_in_sims_group = mmi_frm_group_is_present(GRP_ID_SML_SIMS);
            is_in_main_group = mmi_frm_group_is_present(GRP_ID_SML_MAIN);
            is_in_data_group = mmi_frm_group_is_present(GRP_ID_SML_DATA);
            is_in_pswd_group = mmi_frm_group_is_present(GRP_ID_SML_PSWD);

            if (is_in_sims_group)
            {
                mmi_frm_group_close(GRP_ID_SML_SIMS);
            }

            if (is_in_main_group || is_in_data_group || is_in_pswd_group)
            {
                if (sim_ctrl_evt->sim == mmi_sml_get_active_context())
                {
                    mmi_frm_group_close(GRP_ID_SML_MAIN);
                    mmi_frm_group_close(GRP_ID_SML_DATA);
                    mmi_frm_group_close(GRP_ID_SML_PSWD);
                }
            }

            break;
        }
    }
    
    return MMI_RET_OK;
}
#endif /* __SIM_HOT_SWAP_SUPPORT__ */


#endif /* __MMI_SML_MENU__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_entry_sim1_auto_lock
 * DESCRIPTION
 *  CPHS handler for SIM1 auto lock
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_entry_sim1_auto_lock(void *info)
{
#ifdef __MMI_SML_MENU__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cphs_mmi_info_ind_struct *local_data = (mmi_cphs_mmi_info_ind_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* SIM-ME-Lock auto lock check */
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif

    g_sml_context_p->autolock_nibble = 0;
    if (local_data->is_autolock_enable)
    {
        g_sml_context_p->autolock_nibble |= 0x01;
        if (local_data->autolock_result)
        {
            g_sml_context_p->autolock_nibble |= 0x10;
        }
    }

    if (srv_bootup_is_completed())
    {
        /* Prevent from entering idle screen then receive CPHS indication */
        mmi_sml_display_auto_locked_notification();
    }
#endif /* __MMI_SML_MENU__ */
}


#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SML_MENU__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SML_MENU__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_report_sim_error
 * DESCRIPTION
 *  Report of no more auto lock because the SIM is not present
 * PARAMETERS
 *  sim    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_report_sim_error(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SML_MENU__
    if (sim == MMI_SIM1)
    {
        g_sml_context.autolock_nibble = 0;
    }
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
    else
    {
        MMI_ASSERT(0);
    }
#endif /* __MMI_SML_MENU__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_sim_status_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_sml_sim_status_change(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SML_MENU__
    srv_sim_ctrl_availability_changed_evt_struct *avai_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avai_evt = (srv_sim_ctrl_availability_changed_evt_struct*) evt;
    
    if (avai_evt->sim == MMI_SIM1)
    {
        if (avai_evt->is_available_now)
        {
            mmi_sml_power_on_query_req(MMI_SIM1);
        }
        else
        {
            mmi_sml_report_sim_error(MMI_SIM1);
        }
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else if (avai_evt->sim == MMI_SIM2)
    {
        if (avai_evt->is_available_now)
        {
            mmi_sml_power_on_query_req(MMI_SIM2);
        }
        else
        {
            mmi_sml_report_sim_error(MMI_SIM2);
        }
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (avai_evt->sim == MMI_SIM3) // Gemini+
    {
        if (avai_evt->is_available_now)
        {
            //mmi_sml_power_on_query_req(MMI_SIM3);
        }
        else
        {
            //mmi_sml_report_sim_error(MMI_SIM3);
        }
    }
#if (MMI_MAX_SIM_NUM >= 4)
    else if (avai_evt->sim == MMI_SIM4) // Gemini+
    {
        if (avai_evt->is_available_now)
        {
            //mmi_sml_power_on_query_req(MMI_SIM4);
        }
        else
        {
            //mmi_sml_report_sim_error(MMI_SIM4);
        }
    }
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    else
    {
        MMI_ASSERT(0);
    }

#endif /* __MMI_SML_MENU__ */
    return MMI_RET_OK;
}


