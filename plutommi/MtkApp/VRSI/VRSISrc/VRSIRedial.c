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
 * VRSIRedial.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for redial of VRSI.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _MMI_VRSIREDIAL_C
#define _MMI_VRSIREDIAL_C

#if defined(__MMI_VRSI__)

/*  Include: MMI header file */

/* ... Add More MMI header */
#include "VRSIType.h"
#include "VRSIProt.h"
/* Call Related */
#include "CallLogSrvGprot.h"
#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif
#include "mmi_rp_srv_vrsi_def.h"


#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "GeneralDeviceGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_popup.h"
#include "mmi_rp_app_mainmenu_def.h"
/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Typedef 
 */
typedef enum
{
    VRSI_DUAL_OPEN,
    VRSI_SIM1_OPEN,
    VRSI_SIM2_OPEN,
    VRSI_SIM_ENUM
}vrsi_redial_sim_enum;

/* 
 * Define
 */

/* 
 * Local Variable
 */
static U8 g_vrsi_redial_type;
static U8 g_vrsi_sim_status;
static MMI_BOOL g_sim_num_flag = MMI_FALSE;  /*sim1 redial num */

static srv_clog_get_last_log_cnf_struct  cnf_data_vr;

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
 *  mmi_vrsi_redial_rcg_grammar1_result
 * DESCRIPTION
 *  This function get redial type by recognition result
 * PARAMETERS
 *  rcg_result      [IN]        Index of recognition result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_redial_rcg_grammar1_result(U16 rcg_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    S32 ret = 0;
    srv_clog_get_last_log_req_struct req_data;
    srv_clog_create_struct  create;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*
#define SRV_CLOG_LOG_IDENTITY               \
    U8 cate;                                \
    U8 sim_id;                              \
    U8 log_type;                            \
    U8 sub_type
*/
    g_sim_num_flag = MMI_FALSE;
    
    if (rcg_result == VRSI_CMD1_REDIAL_DIALED)
    {
        g_vrsi_redial_type = SRV_CLOG_CLT_DIALED;
    }
    else if (rcg_result == VRSI_CMD1_REDIAL_MISSED)
    {
        g_vrsi_redial_type = SRV_CLOG_CLT_MISSED;
    }
    else if (rcg_result == VRSI_CMD1_REDIAL_RECEIVED)
    {
        g_vrsi_redial_type = SRV_CLOG_CLT_RECVED;
    }

    srv_clog_init_para(SRV_CLOG_PARA_CREATE, &create);
    handle =  srv_clog_create((const srv_clog_create_struct *)&create);
    srv_clog_init_para(SRV_CLOG_PARA_GET_LAST_LOG_REQ,  (srv_clog_get_last_log_req_struct*)&req_data);
    srv_clog_init_para(SRV_CLOG_PARA_GET_LAST_LOG_CNF,  (srv_clog_get_last_log_cnf_struct*)&cnf_data_vr);
    req_data.cate = SRV_CLOG_CATE_CALL;
    req_data.sim_id = MMI_SIM1 |MMI_SIM2;
    req_data.log_type = g_vrsi_redial_type;
    req_data.sub_type = SRV_CLOG_CALL_TYPE_ALL;
    req_data.fields = 0;

    ret = srv_clog_get_last_log(handle, &req_data, &cnf_data_vr);

    srv_clog_destroy(handle);
    if(ret == SRV_CLOG_RET_OK)
    {
        if (mmi_ucs2strlen((S8*)(cnf_data_vr.log.data.call_log.cid)) > 0)
        {
            mmi_vrsi_entry_redial_dial_prompt();
        }
        else
        {
            mmi_vrsi_redial_no_number();
        }

    }
    else if(ret == SRV_CLOG_RET_NOT_FOUND)
    {
        mmi_vrsi_redial_no_entry();   
    }
    else
    {
    	mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE,  GRP_ID_VRSI, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_redial_dial_prompt_message
 * DESCRIPTION
 *  This function prepare redial prompt message.
 * PARAMETERS
 *  str_prompt      [IN]        Prompt string buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_redial_dial_prompt_message(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // LOG_CALL *redial_call = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_redial_type == SRV_CLOG_CLT_DIALED)
    {
        mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_REDIAL_DIALED));
    }
    else if (g_vrsi_redial_type == SRV_CLOG_CLT_MISSED)
    {
        mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_REDIAL_MISSED));
    }
    else if (g_vrsi_redial_type == SRV_CLOG_CLT_RECVED)
    {
        mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_REDIAL_RECEIVED));
    }
    else
    {
    	//failure
    	mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE,  GRP_ID_VRSI, 0);
        return;
    }
    mmi_ucs2cat(str_prompt, (S8*) L" ");

    /* Append Name or Number */
    if (mmi_ucs2strlen((S8*)(cnf_data_vr.log.data.call_log.name)))
    {
        mmi_ucs2cat(str_prompt, (S8*)(cnf_data_vr.log.data.call_log.name));
    }
    else
    {
        mmi_ucs2cat(str_prompt, (S8*)(cnf_data_vr.log.data.call_log.cid));
    }

    /* Append dialing string */
    mmi_ucs2cat(str_prompt, (S8*) L" ");
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_DIALING_PROMPT));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_redial_dial_prompt
 * DESCRIPTION
 *  This function is entry function of redial prompt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_redial_dial_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_redial_dial_prompt_message(str_prompt);

    TurnOnBacklight(1);
    entry_ret = mmi_frm_scrn_enter(
       GRP_ID_VRSI, 
       SCR_ID_VRSI_REDIAL_PROMPT, 
       mmi_vrsi_exit_redial_dial_prompt, 
       mmi_vrsi_entry_redial_dial_prompt, 
       MMI_FRM_FG_ONLY_SCRN);
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        EnableCenterSoftkey( 0, IMG_GLOBAL_COMMON_CSK);
    }
    ShowCategory66Screen(
        STR_ID_VRSI_APP,
        GetRootTitleIcon(MENU_ID_VRSI_SETTING),
        STR_GLOBAL_DIAL,    /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_CANCEL,   /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_prompt,   /* message id */
        IMG_GLOBAL_QUESTION, /* icon id */
        NULL);

    SetLeftSoftkeyFunction(mmi_vrsi_redial_dial_number, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        ChangeCenterSoftkey( 0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_vrsi_redial_dial_number, KEY_EVENT_UP);
    }
    mmi_ucm_handle_sendkeys_for_call(mmi_vrsi_redial_dial_number_for_sendkey,KEY_EVENT_DOWN);   


    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_redial_dial_number);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_redial_dial_prompt
 * DESCRIPTION
 *  This function is exit function of redial prompt, it will close engine if leave VR session
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_redial_dial_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_rcg_close();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_redial_dial_number
 * DESCRIPTION
 *  Call call management function and dial out the number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_redial_dial_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct make_call_para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*)(cnf_data_vr.log.data.call_log.cid)))
    {
        mmi_ucm_init_call_para(&make_call_para);     
        make_call_para.ucs2_num_uri = (U16*)(cnf_data_vr.log.data.call_log.cid);
        mmi_ucm_call_launch(0, &make_call_para);       
    }
    else
    {
    	//failure
    	mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE,  GRP_ID_VRSI, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_redial_dial_number_for_sendkey
 * DESCRIPTION
 *  Call call management function and dial out the number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_redial_dial_number_for_sendkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct sendkey_makecall_para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*)(cnf_data_vr.log.data.call_log.cid)))
    {
        mmi_ucm_init_call_para_for_sendkey(&sendkey_makecall_para);  
        sendkey_makecall_para.ucs2_num_uri = (U16*)(cnf_data_vr.log.data.call_log.cid);
        mmi_ucm_call_launch(0, &sendkey_makecall_para);
    }
    else
    {
    	//failure
    	mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE,  GRP_ID_VRSI, 0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_redial_no_number
 * DESCRIPTION
 *  no number to dial prompt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_redial_no_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Append redial type */
    if (g_vrsi_redial_type == SRV_CLOG_CLT_DIALED)
    {
        mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_REDIAL_DIALED));
    }
    else if (g_vrsi_redial_type == SRV_CLOG_CLT_MISSED)
    {
        mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_REDIAL_MISSED));
    }
    else if (g_vrsi_redial_type == SRV_CLOG_CLT_RECVED)
    {
        mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_REDIAL_RECEIVED));
    }

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_entry_rcg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_redial_no_entry
 * DESCRIPTION
 *  Entry function for no redial entry prompt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_redial_no_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_RCG_NOT_FOUND));

    if (g_vrsi_redial_type == SRV_CLOG_CLT_DIALED)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_REDIAL_DIALED));
    }
    else if (g_vrsi_redial_type == SRV_CLOG_CLT_MISSED)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_REDIAL_MISSED));
    }
    else if (g_vrsi_redial_type == SRV_CLOG_CLT_RECVED)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_REDIAL_RECEIVED));
    }

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_entry_rcg);
}

#endif /* defined(__MMI_VRSI__) */ /* #if defined(__MMI_VRSI__) */
#endif /* _MMI_VRSIREDIAL_C */ /* #ifndef _MMI_VRSIREDIAL_C */

