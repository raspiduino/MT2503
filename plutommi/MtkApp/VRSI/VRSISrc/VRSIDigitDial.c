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
 * VRSIDigitDial.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for digit dial of VRSI.
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
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifndef _MMI_DIGITDIAL_C
#define _MMI_DIGITDIAL_C

#if defined(__MMI_VRSI__)

/*  Include: MMI header file */

/* ... Add More MMI header */
#include "med_main.h"
#include "med_api.h"
#include "mdi_audio.h"
#include "VRSIType.h"
#include "VRSIProt.h"
#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif/*__MMI_DUAL_SIM_MASTER__*/
#include "mmi_rp_srv_vrsi_def.h"

    #include "MMI_features.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "GeneralDeviceGprot.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "mmi_frm_events_gprot.h"
    #include "wgui_categories_popup.h"
    #include "mmi_rp_app_mainmenu_def.h"
    #include "GlobalResDef.h"
    #include "GlobalConstants.h"
    #include "wgui_categories_util.h"
    #include "CustDataRes.h"
    #include "gui_data_types.h"
    #include "AlertScreen.h"
    #include "stack_config.h"
    #include "Unicodexdcl.h"
    #include "mmi_frm_input_gprot.h"
/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */

/* 
 * Local Function
 */

/* 
 * Global Variable
 */

/* 
 * Global Function
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ddial_rcg
 * DESCRIPTION
 *  This function is entry function of digit dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ddial_rcg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);
    entry_ret = mmi_frm_scrn_enter(
       GRP_ID_VRSI, 
       SCR_ID_VRSI_DIGIT_DIAL_MAIN, 
       mmi_vrsi_exit_ddial_rcg, 
       mmi_vrsi_entry_ddial_rcg, 
       MMI_FRM_FG_ONLY_SCRN);    
    if (!entry_ret)
    {
        return;
    }  
    ShowCategory8Screen(
        STR_ID_VRSI_APP,
        GetRootTitleIcon(MENU_ID_VRSI_SETTING),
        0,                          /* LSK STR */
        0,                          /* LSK IMG */
        STR_GLOBAL_CANCEL,           /* RSK STR */
        0,                          /* RSK IMG */
        STR_ID_VRSI_DIGIT_PROMPT,   /* message id */
        IMG_ID_VRSI_RECORDING,      /* icon id */
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);

    g_vrsi_cntx.curr_grammar = MMI_VRSI_GRAMMAR_DIGIT;  /* Assign grammar for rcg result callback */
    g_vrsi_cntx.curr_scenario = VRSI_CMD1_DIGIT_DIAL;

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) GetString(STR_ID_VRSI_DIGIT_PROMPT), mmi_vrsi_ddial_start_command);

    g_vrsi_cntx.retry++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_ddial_rcg
 * DESCRIPTION
 *  This function is exit function of digit dial, it will close engine if leave VR session
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_ddial_rcg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID scr_id;
    MMI_ID group_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If next screen is not VRSI digit recognition result screen, abort and leave VR-Session */
    //scr_id = mmi_frm_scrn_get_active_id();
    mmi_frm_get_active_scrn_id(&group_id, &scr_id);
    if ((scr_id == SCR_ID_VRSI_DIGIT_DIAL_MAIN) || (scr_id == SCR_ID_VRSI_DIGIT_DIAL_CONFIRM))
    {
        return;
    }
    else
    {
        mmi_vrsi_rcg_close();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ddial_start_command
 * DESCRIPTION
 *  This function start engine to init digit recognition.
 *  It will start according to current language.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ddial_start_command(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_cntx.lang == MED_VRSI_INVALID_LANG)
    {   
        //failure
        mmi_popup_display_simple((UI_string_type)GetString(STR_ID_VRSI_LANG_NOT_SUPPORT), MMI_EVENT_FAILURE, GRP_ID_VRSI, 0);
        return;
    }

    /* Check engine state and init digit dial */
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
    {
        g_vrsi_cntx.session_id = mdi_audio_vrsi_new_session_id();

        result = media_aud_vrsi_start_digit_rcg(MOD_MMI, g_vrsi_cntx.session_id, g_vrsi_cntx.lang, 0);  /* 0: means no limit */

        if (result == MED_RES_OK)
        {
            return;
        }
        if (result == MED_RES_VRSI_ERR_EVALUATE_LIMIT)
        {
            //failure
            mmi_popup_display_simple((UI_string_type)GetString(STR_ID_VRSI_DEMO_ERROR), MMI_EVENT_FAILURE, GRP_ID_VRSI, 0);
            return;
        }
    }
    //failure
    
    mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, GRP_ID_VRSI, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ddial_read_result
 * DESCRIPTION
 *  This function read the digit recognition result from engine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ddial_read_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 length;
    U16 *digit_list;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_vrsi_read_dgt_rcg_result(&length, &digit_list);

    if (length == 0)    /* No speak */
    {
        if (g_vrsi_cntx.retry <= MMI_VRSI_MAX_RETRY)
        {
            /* Play prompt TTS, and speak again */
            mmi_vrsi_util_play_tts((U16*) GetString(STR_ID_VRSI_DIGIT_PROMPT), mmi_vrsi_ddial_start_command);
            g_vrsi_cntx.retry++;
        }
        else
        {
            mmi_frm_scrn_close_active_id();
        }
    }
    else if (length > MMI_VRSI_MAX_DIAL_DIGIT)
    {
        if (g_vrsi_cntx.retry <= MMI_VRSI_MAX_RETRY)
        {
            /* Play prompt TTS, and speak again */
            mmi_vrsi_util_play_tts((U16*) GetString(STR_ID_VRSI_DIAL_DIGIT_TOO_LONG), mmi_vrsi_ddial_start_command);
            g_vrsi_cntx.retry++;
        }
        else
        {
            mmi_frm_scrn_close_active_id();
        }
    }
    else
    {
        for (i = 0; i < length; i++)
        {
            g_vrsi_cntx.digit_list[i] = (U8) (digit_list[i] + 0x0030);
        }

        g_vrsi_cntx.digit_list[i] = '\0';

        /* SI engine should still ready here. */
        g_vrsi_cntx.retry = 0;
        mmi_vrsi_rcg_init(mmi_vrsi_entry_ddial_dial_confirm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ddial_dial_confirm
 * DESCRIPTION
 *  Entry function of dial confirmation screen of digit recognition result.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ddial_dial_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_digit[(MMI_VRSI_MAX_DIAL_DIGIT + 1) * ENCODING_LENGTH];
    S8 str_prompt[(MMI_VRSI_MAX_DIAL_DIGIT + 1 + 60) * ENCODING_LENGTH];
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Concatenate prompt string */
    mmi_asc_to_ucs2(str_digit, (S8*) g_vrsi_cntx.digit_list);

    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_DIAL_PROMPT));
    mmi_ucs2cat(str_prompt, str_digit);
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR4_PROMPT));

    TurnOnBacklight(1);
    entry_ret = mmi_frm_scrn_enter(
       GRP_ID_VRSI, 
       SCR_ID_VRSI_DIGIT_DIAL_CONFIRM, 
       mmi_vrsi_exit_ddial_dial_confirm, 
       mmi_vrsi_entry_ddial_dial_confirm, 
       MMI_FRM_FG_ONLY_SCRN);    
    if (!entry_ret)
    {
        return;
    } 
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    ShowCategory66Screen(
        STR_ID_VRSI_APP,
        GetRootTitleIcon(MENU_ID_VRSI_SETTING),
        STR_GLOBAL_DIAL,    /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_CANCEL,   /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_prompt,   /* message string */
        IMG_GLOBAL_QUESTION, /* icon id */
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsi_ddial_dial_number, KEY_EVENT_UP);

    mmi_ucm_handle_sendkeys_for_call(mmi_vrsi_ddial_dial_number_for_sendkey, KEY_EVENT_DOWN);
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_vrsi_ddial_dial_number, KEY_EVENT_UP);
    }

    g_vrsi_cntx.curr_grammar = MMI_VRSI_GRAMMAR_4;  /* Assign grammar for rcg result callback */
    g_vrsi_cntx.curr_scenario = VRSI_CMD1_DIGIT_DIAL;

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_rcg_start_command);

    g_vrsi_cntx.retry++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_ddial_dial_confirm
 * DESCRIPTION
 *  Exit function of dial confirmation screen of digit recognition result.
 *  It will close engine if leave VR session.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_ddial_dial_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID scr_id;
    MMI_ID group_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //scr_id = mmi_frm_scrn_get_active_id();
    mmi_frm_get_active_scrn_id(&group_id, &scr_id);
    if ((scr_id == SCR_ID_VRSI_DIGIT_DIAL_MAIN) ||  /* Re-enter digit */
        (scr_id == SCR_ID_VRSI_DIGIT_DIAL_CONFIRM))
    {
        return;
    }
    else
    {
        mmi_vrsi_rcg_close();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ddial_dial_confirm_in_history
 * DESCRIPTION
 *  This screen should be the same as "void mmi_vrsi_entry_ddial_dial_confirm(void)"
 *  except VR command. This is for placing this screen in history for keypad operation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ddial_dial_confirm_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_digit[(MMI_VRSI_MAX_DIAL_DIGIT + 1) * ENCODING_LENGTH];
    S8 str_prompt[(MMI_VRSI_MAX_DIAL_DIGIT + 1 + 60) * ENCODING_LENGTH];
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Concatenate prompt string */
    mmi_asc_to_ucs2(str_digit, (S8*) g_vrsi_cntx.digit_list);

    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_DIAL_PROMPT));
    mmi_ucs2cat(str_prompt, str_digit);
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR4_PROMPT));

    TurnOnBacklight(1);
    entry_ret = mmi_frm_scrn_enter(
       GRP_ID_VRSI, 
       SCR_ID_VRSI_DIGIT_DIAL_CONFIRM_IN_HISTORY, 
       NULL, 
       mmi_vrsi_entry_ddial_dial_confirm_in_history, 
       MMI_FRM_FG_ONLY_SCRN); 
    if (!entry_ret)
    {
        return;
    } 
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    ShowCategory66Screen(
        STR_ID_VRSI_APP,
        GetRootTitleIcon(MENU_ID_VRSI_SETTING),
        STR_GLOBAL_DIAL,    /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_CANCEL,   /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_prompt,   /* message string */
        IMG_GLOBAL_QUESTION, /* icon id */
        NULL);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsi_ddial_dial_number, KEY_EVENT_UP);

    mmi_ucm_handle_sendkeys_for_call(mmi_vrsi_ddial_dial_number_for_sendkey, KEY_EVENT_DOWN);
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_vrsi_ddial_dial_number, KEY_EVENT_UP);
    }
   /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ddial_dial_number
 * DESCRIPTION
 *  Call call management function and dial out the number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ddial_dial_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_digit[(MMI_VRSI_MAX_DIAL_DIGIT + 1) * ENCODING_LENGTH];
    mmi_ucm_make_call_para_struct make_call_para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2(str_digit, (S8*) g_vrsi_cntx.digit_list);

    if (mmi_ucs2strlen(str_digit))
    {
        mmi_ucm_init_call_para(&make_call_para);     
        make_call_para.ucs2_num_uri = (U16*)str_digit;
        mmi_ucm_call_launch(0, &make_call_para);
    }
    else
    {
        //failure
        mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, GRP_ID_VRSI, 0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ddial_dial_number_for_sendkey
 * DESCRIPTION
 *  Call call management function and dial out the number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ddial_dial_number_for_sendkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_digit[(MMI_VRSI_MAX_DIAL_DIGIT + 1) * ENCODING_LENGTH];
    mmi_ucm_make_call_para_struct sendkey_makecall_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2(str_digit, (S8*) g_vrsi_cntx.digit_list);
    
    if (mmi_ucs2strlen(str_digit))
    {
        mmi_ucm_init_call_para_for_sendkey(&sendkey_makecall_para); 
        sendkey_makecall_para.ucs2_num_uri = (U16 *)str_digit;   
        mmi_ucm_call_launch(0, &sendkey_makecall_para); 
    }
    else
    {
        mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, GRP_ID_VRSI, 0);	
    }
}

#endif /* defined(__MMI_VRSI__) */ /* #if defined(__MMI_VRSI__) */
#endif /* _MMI_DIGITDIAL_C */ /* #ifndef _MMI_DIGITDIAL_C */

