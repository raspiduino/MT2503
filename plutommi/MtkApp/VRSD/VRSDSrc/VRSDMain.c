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
 * VRSDMain.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Voice Command
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_include.h"
#ifndef _MMI_VRSDMAIN_C
#define _MMI_VRSDMAIN_C

#if defined(__MMI_VRSD__)

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "nvram_user_defs.h"
#include "SettingProfile.h"
#include "ProtocolEvents.h"
#include "IdleAppDef.h"
#include "worldclock.h"
#include "PhonebookResDef.h"
#include "CallManagementGProt.h"
#include "SSCStringHandle.h"
#include "ProfileGProts.h"
#include "gpioInc.h"


#if defined(__MMI_BT_SUPPORT__)
#include "BTMMIScrGProts.h"
#include "BTMMISCOPathGprots.h"
#endif 
#include "BtcmSrvGprot.h"
/* Med */
#include "med_global.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_main.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"

#include "VRSDResDef.h"
#include "VRSD.h"
#include "VRSDRedial.h"
#if defined(__MMI_VRSD_DIAL__)
#include "VRSDDial.h"
#endif 
#include "VRSDProfile.h"
#include "VRSDAudplayer.h"

#include "MainMenuDef.h"
#include "SSCStringHandle.h"
#include "USBDeviceGprot.h"
#include "SimDetectionGprot.h"

#include "UCMGProt.h"
#include "UcmSrvGprot.h"

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */
vrsd_context_struct g_vrsd_cntx;    /* Global Context */

#if defined(__MMI_BT_SUPPORT__)
static BOOL g_vrsd_init_by_bt;
static BOOL g_vrsd_close_by_bt;  
#endif /* defined(__MMI_BT_SUPPORT__) */ 
/* 
 * Local Function
 */
static U8 mmi_vrsd_delscrn_main_menu_hdlr(void *param_p);

/* 
 * Global Variable
 */
extern const U8 g_vrsd_recv_voice_prompt[];
extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif 
extern pBOOL mmi_bootup_is_sim_valid(void);

/* 
 * Global Function
 */

#define MMI_VRSD_INIT


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_init
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Clear Variables. */
    mmi_vrsd_clear_rcg_callback();
    g_vrsd_cntx.vrtag_sync = 0;

    ReadValue(NVRAM_VRSD_RCG_SETTING, &g_vrsd_cntx.rcg_enable, DS_BYTE, &pError);

    /* Register Highlight Handler */
    mmi_vrsd_init_highlight_handler();

#if defined(__MMI_VRSD_DIAL__)
    mmi_vrsddial_init();
#endif 

#if defined(__MMI_VRSD_REDIAL__)
    mmi_vrsdredial_init();
#endif 

#if defined(__MMI_VRSD_PROFILE__)
    mmi_vrsdprf_init();
#endif 

#if defined(__MMI_VRSD_AUDPLAYER__)
    mmi_vrsdaudp_init();
#endif 

#if defined(__MMI_VRSD_SHORTCUT__)
    mmi_vrsdscut_init();
#endif 
#if defined(__MMI_BT_SUPPORT__)
    SetProtocolEventHandler(mmi_vrsd_bt_set_ind_hdlr, PRT_MMI_L4_BT_SET_VR_REQ_IND);
    SetProtocolEventHandler(mmi_vrsd_bt_set_rsp_hdlr, PRT_MMI_L4_BT_SET_VR_RSP);
    g_vrsd_init_by_bt = FALSE;
    g_vrsd_close_by_bt = FALSE; 
#endif /* defined(__MMI_BT_SUPPORT__) */  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_init_highlight_handler
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_init_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_VRSD_APP, mmi_vrsd_highlight_main_menu);

    /* For Main Menu */
    SetHiliteHandler(MENU_ID_VRSD_RCG, mmi_vrsd_highlight_rcg_enable);
    SetHintHandler(MENU_ID_VRSD_RCG, mmi_vrsd_hint_rcg_enable);
    SetHiliteHandler(MENU_ID_VRSD_DELETE_ALL, mmi_vrsd_highlight_delete_all);
    SetHiliteHandler(MENU_ID_VRSD_STATUS, mmi_vrsd_highlight_status);
}

static U8 mmi_vrsd_delscrn_main_menu_hdlr(void *param_p)
{

#if defined(__MMI_BT_SUPPORT__)    
      
#ifdef __MMI_BT_AUDIO_VIA_SCO__
        mmi_bt_sco_enable_sco_timeout();
#else
        mmi_bt_sco_disconnect_sco();
#endif
    
#endif 

    
    return 0;
}
#define MMI_VRSD_MAIN_MENU


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_highlight_main_menu
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_highlight_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

#ifdef __MTK_TARGET__
    SetLeftSoftkeyFunction(mmi_vrsd_main_menu_pre_entry, KEY_EVENT_UP);
#else 
    SetLeftSoftkeyFunction(PopupNoSupport, KEY_EVENT_UP);
#endif 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsd_main_menu_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_main_menu_pre_entry
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_main_menu_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if in USB mode before enter setting */
#if defined(__USB_IN_NORMAL_MODE__)
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 


#if defined(__MMI_VRSD_DIAL__)
    if (mmi_vrsddial_check_sim_change_not_at_idle())
    {
        return;
    }
#endif /* defined(__MMI_VRSD_DIAL__) */ 

    /* Synchronize with file system for first time entry. */
    mmi_vrsd_sync_tag_with_db();
    mmi_vrsd_entry_main_menu();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_entry_main_menu
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MMI_VRSD_APP_TOTAL + 5];
    U16 nNumofItem;
    U8 *hintList[MMI_VRSD_APP_TOTAL + 5];   /* Array for hint */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VRSD_MAIN_MENU, mmi_vrsd_exit_main_menu, mmi_vrsd_entry_main_menu, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSD_MAIN_MENU);    /* Getting the Index from history */
    SetDelScrnIDCallbackHandler(SCR_ID_VRSD_MAIN_MENU,mmi_vrsd_delscrn_main_menu_hdlr);

    nNumofItem = GetNumOfChild(MENU_ID_VRSD_MAIN_MENU);
    GetSequenceStringIds(MENU_ID_VRSD_MAIN_MENU, nStrItemList);
    SetParentHandler(MENU_ID_VRSD_MAIN_MENU);

    RegisterHighlightHandler(mmi_vrsd_main_menu_highlight_hdlr);

    /* Construct List To Show Hint */
    ConstructHintsList(MENU_ID_VRSD_MAIN_MENU, hintList);

    /* Screen with hint */
    ShowCategory52Screen(
        STR_ID_VRSD_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_ON,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        hintList,
        0,
        0,
        guiBuffer);
        
#if defined(__MMI_BT_SUPPORT__)
    if (mmi_bt_sco_connect_sco(NULL))
    {
    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        mmi_bt_sco_disable_sco_timeout();
    #endif        
    }
    else if ((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)))
    {
    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        mmi_bt_sco_disable_sco_timeout();
    #endif     
    }
    else
    {
        //no bt support, nothing to do
    } 
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_exit_main_menu
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_exit_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(VRSD_DIAL_PLAYBACK_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_main_menu_highlight_hdlr
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  hiliteid        [IN]        
 *  a(?)            [IN/OUT]        First variable, used as returns(?)
 *  b(?)            [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_main_menu_highlight_hdlr(S32 hiliteid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(VRSD_DIAL_PLAYBACK_TIMER);

    ExecuteCurrHiliteHandler(hiliteid);
}

#define MMI_VRSD_RCG_ENABLE


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_highlight_rcg_enable
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_highlight_rcg_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsd_cntx.rcg_enable)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }

    SetLeftSoftkeyFunction(mmi_vrsd_rcg_enable_switch, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_hint_rcg_enable
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_hint_rcg_enable(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsd_cntx.rcg_enable)
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_rcg_enable_switch
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_rcg_enable_switch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 msg;
    S16 pError;
    U16 index;
    U16 str_LSK = STR_GLOBAL_OFF, str_hint = STR_GLOBAL_ON;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID(); 
    if (g_vrsd_cntx.rcg_enable)
    {
        g_vrsd_cntx.rcg_enable = 0;
        //msg = STR_GLOBAL_OFF;
        str_LSK = STR_GLOBAL_ON;
        str_hint = STR_GLOBAL_OFF;
    }
    else
    {
        g_vrsd_cntx.rcg_enable = 1;
        //msg = STR_GLOBAL_ON;
    }

    ChangeLeftSoftkey(str_LSK, IMG_GLOBAL_OK);
    mmi_ucs2cpy((S8*) hintData[index], GetString(str_hint));
    Category52ChangeItemDescription(index, hintData[index]);

    /* Redraw the Category Screen As Hint Handler and LSK are going to Chnage */
    RedrawCategoryFunction();
    /* Write Back To NVRAM */
    WriteValue(NVRAM_VRSD_RCG_SETTING, &g_vrsd_cntx.rcg_enable, DS_BYTE, &pError);

#if 0
/* under construction !*/
#endif
}

#define MMI_VRSD_TRAIN


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_train_init
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  app_id              [IN]        
 *  appref_id           [IN]        
 *  trn_callback        [IN]        
 *  a(?)                [IN/OUT]        First variable, used as returns(?)
 *  b(?)                [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_train_init(U8 app_id, U16 appref_id, void (*trn_callback) (U8))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Suspend all background play during receiving voice */
#if defined(__MMI_BACKGROUND_CALL__)
        if (srv_ucm_is_background_call())
        {
            mmi_ucm_entry_error_message();
            return;
        }
#endif
    mdi_audio_suspend_background_play();

    /* Get session id and initial vr engine */
    g_vrsd_cntx.session_id = media_aud_vr_new_session_id();
    result = media_aud_vr_init_trn(
                MOD_MMI,
                g_vrsd_cntx.session_id,
                MED_VR_ISD_MODE,
                MED_VR_NO_CARE_LANG,
                MMI_VRSD_GROUP_ALL,
                g_vrsd_cntx.vrtag_id,
                0);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VRSD_FUNC_TRAIN_INIT, app_id, appref_id, g_vrsd_cntx.session_id, result);

    if (result == MED_RES_OK)
    {
        g_vrsd_cntx.trn_callback = trn_callback;
        g_vrsd_cntx.vrstage = MMI_VRSD_STATE_TRN_VOICE_IN_FIRST;        /* For traing 1st time */
        g_vrsd_cntx.app_id = app_id;
        g_vrsd_cntx.appref_id = appref_id;
        mmi_vrsd_entry_recv_voice();
    }
    else    /* Init fail */
    {
        if (result == MED_RES_BUSY) /* To avoid server hang in busy state. */
        {
            mdi_audio_vr_abort();
        }

        g_vrsd_cntx.vrstage = MMI_VRSD_STATE_IDLE;

        trn_callback(MMI_VRSD_TRN_FAIL);    /* Callback application init fail handling. */

        /* Resume all background after init fail */
        mdi_audio_resume_background_play();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_train_result_ind
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  result      [IN]        
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_train_result_ind(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VRSD_FUNC_TRAIN_RESULT_IND, result);

    /* Training stage 1 Success */
    if (result == MED_RES_TRAINING_CONTINUE && g_vrsd_cntx.vrstage == MMI_VRSD_STATE_TRN_VOICE_IN_FIRST)
    {
        /* Check session id consistency */
        if (g_vrsd_cntx.session_id != mdi_audio_vr_trn_session_id())
        {
            g_vrsd_cntx.vrstage = MMI_VRSD_STATE_IDLE;
            	//failure
		    mmi_display_popup(
			    (UI_string_type)GetString(STR_ID_VRSD_WRONG_SESSION),
			    MMI_EVENT_FAILURE);
            
            return;
        }

        g_vrsd_cntx.vrstage = MMI_VRSD_STATE_TRN_VOICE_IN_SECOND;
        mmi_vrsd_entry_recv_voice();
    }
    /* Training success, Note that Cyberon train twice, other may train only once */
    else if (result == MED_RES_OK)
    {
        g_vrsd_cntx.vrstage = MMI_VRSD_STATE_IDLE;

        /* Check session id consistency */
        if (g_vrsd_cntx.session_id != mdi_audio_vr_trn_session_id())
        {
            mmi_display_popup(
			    (UI_string_type)GetString(STR_ID_VRSD_WRONG_SESSION),
			    MMI_EVENT_FAILURE);
            return;
        }

        /* write back to NVRAM */
        mmi_vrsd_train_success();

        g_vrsd_cntx.trn_callback(MMI_VRSD_TRN_SUCCESS);
    }
    else if (result == MDI_AUDIO_TERMINATED)    /* Interrupt */
    {
        if (!g_vrsd_cntx.user_abort)
        {
            return;
        }
    }
    else    /* Error */
    {
        g_vrsd_cntx.vrstage = MMI_VRSD_STATE_IDLE;
        mmi_vrsd_error_popup((U16) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_train_success
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_train_success(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Retrieve data from NVRAM */
    ReadRecord(
        NVRAM_EF_VRSD_TAG_LID,
        MMI_VRSD_GROUP_ALL,
        (void*)tag_list,
        MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
        &pError);

    tag_list[g_vrsd_cntx.vrtag_id].appref_id = g_vrsd_cntx.appref_id;
    tag_list[g_vrsd_cntx.vrtag_id].app_id = g_vrsd_cntx.app_id;

    WriteRecord(
        NVRAM_EF_VRSD_TAG_LID,
        MMI_VRSD_GROUP_ALL,
        (void*)tag_list,
        MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
        &pError);
}

#define MMI_VRSD_RCG


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_rcg_pre_entry
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_rcg_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if in USB mode before enter setting */

#ifndef __MTK_TARGET__
    PopupNoSupport();
    return;
#endif /* __MTK_TARGET__ */ 

#if defined(__USB_IN_NORMAL_MODE__)
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_entry_error_message();
        return;
    }
#endif
#if defined(__MMI_VRSD_DIAL__)
    if (mmi_vrsddial_check_sim_change())
    {
        return;
    }
#endif /* defined(__MMI_VRSD_DIAL__) */ 

    /* Synchronize with file system for first time login. */
    mmi_vrsd_sync_tag_with_db();

    /* Check if list empty. */
    if (g_vrsd_cntx.rcg_enable)
    {
        if (!mmi_vrsd_get_total_tag_count(MMI_VRSD_APP_ALL))
        {
        	//failure
		    mmi_display_popup(
			    (UI_string_type)GetString(STR_ID_VRSD_NO_TAG_EXIST),
			    MMI_EVENT_FAILURE);
           
            return;
        }
#if defined(__MMI_BT_SUPPORT__)
        mmi_vrsd_bt_set_req(TRUE);
#endif 

        mmi_vrsd_rcg_init();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_rcg_init
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_rcg_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Suspend all background play during receiving voice */
#if defined(__MMI_BACKGROUND_CALL__)
            if (srv_ucm_is_background_call())
            {
                mmi_ucm_entry_error_message();
                return;
            }
#endif
    mdi_audio_suspend_background_play();

    /* Get session id and initial vr engine */
    g_vrsd_cntx.session_id = media_aud_vr_new_session_id();
    result = media_aud_vr_init_rcg(
                MOD_MMI,
                g_vrsd_cntx.session_id,
                MED_VR_ISD_MODE,
                MED_VR_NO_CARE_LANG,
                MMI_VRSD_GROUP_ALL,
                0);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VRSD_FUNC_RCG_INIT, g_vrsd_cntx.session_id, result);

    if (result == MED_RES_OK)
    {
        g_vrsd_cntx.vrstage = MMI_VRSD_STATE_RCG_VOICE_IN;  /* Only one stage for recognition */
        mmi_vrsd_entry_recv_voice();
    }
    else
    {
        if (result == MED_RES_BUSY)
        {
            mdi_audio_vr_abort();
        }

        g_vrsd_cntx.vrstage = MMI_VRSD_STATE_IDLE;
        	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_FAILURE),
			MMI_EVENT_FAILURE);

        /* Resume all background play during receiving voice */
        mdi_audio_resume_background_play();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_rcg_result_ind
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  result      [IN]        
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_rcg_result_ind(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *id_array;
    U16 appref_id;
    U8 app_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VRSD_FUNC_RCG_RESULT_IND_1, result);

    g_vrsd_cntx.vrstage = MMI_VRSD_STATE_IDLE;

    if (result == MED_RES_OK)
    {
        /* Check Session Consistency */
        if (g_vrsd_cntx.session_id != mdi_audio_vr_rcg_session_id())
        {
        	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_ID_VRSD_WRONG_SESSION),
			MMI_EVENT_FAILURE);    
            
            return;
        }

        /* retrieve application ref id from tag id */
        id_array = mdi_audio_vr_rcg_result_id_array();

        g_vrsd_cntx.vrtag_id = id_array[0];
        mmi_vrsd_get_mapping_index(id_array[0], &appref_id, &app_id);

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VRSD_FUNC_RCG_RESULT_IND_2, g_vrsd_cntx.vrtag_id, app_id, appref_id);

        /* Match Voice Tag, Call Application registered callback function. */
        if ((appref_id != 0xffff) && (app_id < MMI_VRSD_APP_TOTAL))
            if (g_vrsd_cntx.rcg_callback[app_id] != NULL)
            {
                g_vrsd_cntx.rcg_callback[app_id] (appref_id);
                return;
            }

        	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_FAILURE),
			MMI_EVENT_FAILURE);
    }
    else if (result == MDI_AUDIO_TERMINATED)    /* Interrupt */
    {
        return;
    }
    else    /* Error */
    {
        mmi_vrsd_error_popup((U16) result);
    }
}

#define MMI_VRSD_RECEIVE_VOICE


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_entry_recv_voice
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_entry_recv_voice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 message_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsd_cntx.user_abort = 0;

    if (g_vrsd_cntx.vrstage == MMI_VRSD_STATE_TRN_VOICE_IN_FIRST || g_vrsd_cntx.vrstage == MMI_VRSD_STATE_RCG_VOICE_IN)
    {
        message_id = STR_ID_VRSD_VOICE_IN;
    }
    else
    {
        message_id = STR_ID_VRSD_VOICE_IN_AGAIN;
    }

    EntryNewScreen(SCR_ID_VRSD_RECV_VOICE, mmi_vrsd_exit_recv_voice, NULL, NULL);

    ShowCategory8Screen(
        STR_ID_VRSD_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        0,                      /* LSK STR */
        0,                      /* LSK IMG */
        STR_GLOBAL_CANCEL,      /* RSK STR */
        0,                      /* RSK IMG */
        message_id,             /* message id */
        IMG_ID_VRSD_RECORDING,  /* icon id */
        NULL);

    ClearInputEventHandler(MMI_DEVICE_KEY);
    //ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    //ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    //ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    //ClearKeyHandler(KEY_END, KEY_REPEAT);

    SetRightSoftkeyFunction(mmi_vrsd_recv_voice_abort, KEY_EVENT_UP);

    /* Start a timer to play prompt tone. */

#if defined(__MMI_BT_SUPPORT__)
        if (g_vrsd_init_by_bt == TRUE)
        {
            if (mmi_bt_sco_connect_sco(mmi_vrsd_bt_connect_sco_hdlr))
            {
            #ifdef __MMI_BT_AUDIO_VIA_SCO__
                mmi_bt_sco_disable_sco_timeout();
            #endif       
            }
            else if ((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)))
            {
            #ifdef __MMI_BT_AUDIO_VIA_SCO__
                mmi_bt_sco_disable_sco_timeout();
            #endif
                StartTimer(VRSD_PLAYTONE_TIMER, MMI_VRSD_PLAY_TONE_DELAY_TIME, mmi_vrsd_recv_voice_prompt_tone); 
            }
            else
            {
                mmi_vrsd_recv_voice_abort();      
            }
        }
        else
        {            
            if ((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)))
            {
            #ifdef __MMI_BT_AUDIO_VIA_SCO__
                mmi_bt_sco_disable_sco_timeout();
            #endif
                StartTimer(VRSD_PLAYTONE_TIMER, MMI_VRSD_PLAY_TONE_DELAY_TIME, mmi_vrsd_recv_voice_prompt_tone); 
            }
            else
            {
                // no bt support
                StartTimer(VRSD_PLAYTONE_TIMER, MMI_VRSD_PLAY_TONE_DELAY_TIME, mmi_vrsd_recv_voice_prompt_tone);       
            }
        }
        return;
#endif

    StartTimer(VRSD_PLAYTONE_TIMER, MMI_VRSD_PLAY_TONE_DELAY_TIME, mmi_vrsd_recv_voice_prompt_tone);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_exit_recv_voice
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_exit_recv_voice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(VRSD_PLAYTONE_TIMER);

    /* Abort engine if next screen ID is not Voice Dial application. */
    scr_id = GetActiveScreenId();
    if (!((scr_id == SCR_ID_VRSD_RCG_FOUND) || (scr_id == SCR_ID_VRSD_RECV_VOICE)))
    {
        g_vrsd_cntx.vrstage = MMI_VRSD_STATE_IDLE;
        mdi_audio_vr_abort();
    }

    /* Resume background play after receiving voice done */
    if (scr_id != SCR_ID_VRSD_RECV_VOICE)
    {
#if defined(__MMI_BT_SUPPORT__)
        if (g_vrsd_init_by_bt == TRUE)
        {
            if (g_vrsd_close_by_bt == FALSE)  
            {
                mmi_vrsd_bt_set_req(FALSE);
            }
#ifdef __MMI_BT_AUDIO_VIA_SCO__
            mmi_bt_sco_enable_sco_timeout();
#else
            mmi_bt_sco_disconnect_sco();
#endif
        }
        mdi_audio_resume_background_play();
#endif        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_recv_voice_abort
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_recv_voice_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Abort engine in exit function. */
    g_vrsd_cntx.user_abort = 1;
    GoBackHistory();
    /* DisplayPopup((U8*)GetString(STR_GLOBAL_CANCEL), IMG_GLOBAL_WARNING,  TRUE, UI_POPUP_NOTIFYDURATION_TIME, WARNING_TONE); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_recv_voice_prompt_tone
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_recv_voice_prompt_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Play Tone, and then record after play finish */

    mdi_audio_play_string(
        (void*)g_vrsd_recv_voice_prompt,
        mmi_vrsd_get_prompt_tone_size(),
        MDI_FORMAT_WAV,
        DEVICE_AUDIO_PLAY_ONCE,
        mmi_vrsd_recv_voice_req
        NULL);
#if defined(__MMI_BT_SUPPORT__)
    if (mmi_bt_sco_connect_sco(NULL))
    {
    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        mmi_bt_sco_disable_sco_timeout();
    #endif        
    }
    else if ((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)))
    {
    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        mmi_bt_sco_disable_sco_timeout();
    #endif     
    }
    else
    {
        //no bt support, nothing to do
    } 
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_recv_voice_req
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  event       [IN]        
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_recv_voice_req(mdi_result event, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = MED_RES_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((event == MDI_AUDIO_END_OF_FILE) && (GetActiveScreenId() == SCR_ID_VRSD_RECV_VOICE))
    {
        /* Training 0 : first sampe; 1: second sample */
        if (g_vrsd_cntx.vrstage == MMI_VRSD_STATE_TRN_VOICE_IN_FIRST ||
            g_vrsd_cntx.vrstage == MMI_VRSD_STATE_TRN_VOICE_IN_SECOND)
        {
            result = mdi_audio_start_vr_voice_record(
                        g_vrsd_cntx.session_id,
                        (U8) (g_vrsd_cntx.vrstage - 1),
                        mmi_vrsd_train_result_ind,
                        NULL);
        }
        /* Recognition */
        else if (g_vrsd_cntx.vrstage == MMI_VRSD_STATE_RCG_VOICE_IN)
        {
            result = mdi_audio_start_vr_voice_record(g_vrsd_cntx.session_id, 0, mmi_vrsd_rcg_result_ind, NULL);
        }

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VRSD_FUNC_RECV_VOICE_REQ, result);

        if (result != MED_RES_OK)
        {
        	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_ID_VRSD_RECV_VOICE_FAIL),
			MMI_EVENT_FAILURE);
            
        }
    }
    //else
    //   DisplayPopup((U8*)GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR,  TRUE, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);

}

#define MMI_VRSD_DELETE_ALL


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_highlight_delete_all
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_highlight_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_vrsd_entry_delete_all, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsd_entry_delete_all, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_entry_delete_all
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_entry_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer;
    U16 nStrItemList[MMI_VRSD_APP_TOTAL + 1];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VRSD_DELETE_ALL, NULL, mmi_vrsd_entry_delete_all, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSD_DELETE_ALL);   /* Getting the Index from history */

    nNumofItem = GetNumOfChild(MENU_ID_VRSD_DELETE_ALL);
    GetSequenceStringIds(MENU_ID_VRSD_DELETE_ALL, nStrItemList);
    SetParentHandler(MENU_ID_VRSD_DELETE_ALL);

    RegisterHighlightHandler(mmi_vrsd_delete_all_highlight_hdlr);

    ShowCategory15Screen(
        STR_GLOBAL_DELETE_ALL,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_vrsd_delete_all_confirm, KEY_EVENT_UP);
    SetKeyHandler(mmi_vrsd_delete_all_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_delete_all_highlight_hdlr
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  hiliteid        [IN]        
 *  a(?)            [IN/OUT]        First variable, used as returns(?)
 *  b(?)            [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_delete_all_highlight_hdlr(S32 hiliteid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nMenuItemList[MMI_VRSD_APP_TOTAL + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceItemIds(MENU_ID_VRSD_DELETE_ALL, nMenuItemList);

    g_vrsd_cntx.app_id = mmi_vrsd_get_appid_by_menuid(nMenuItemList[hiliteid]);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_delete_all_confirm
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_delete_all_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count_list[MMI_VRSD_APP_TOTAL];
    U16 i;
    U16 len;
    U16 str_id;
    S8 str_cnf[120];
    S8 temp_string[120];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(count_list, 0, sizeof(U16) * MMI_VRSD_APP_TOTAL);
    mmi_vrsd_get_each_tag_count(count_list);

    if (count_list[g_vrsd_cntx.app_id] != 0)
    {
        str_id = mmi_vrsd_get_strid_by_appid(g_vrsd_cntx.app_id);
    #ifdef __MMI_VRSD_REDIAL__
        if (str_id == STR_ID_VRSD_REDIAL)
        {
            mmi_ucs2ncpy(str_cnf, GetString(STR_GLOBAL_DELETE), 100);
        }
        else
    #endif /* __MMI_VRSD_REDIAL__ */ 
    #ifdef __MMI_VRSD_AUDPLAYER__
        if (str_id == STR_ID_VRSD_AUD_PLAYER)
        {
            mmi_ucs2ncpy(str_cnf, GetString(STR_GLOBAL_DELETE), 100);
        }
        else
    #endif /* __MMI_VRSD_AUDPLAYER__ */ 
        {
            mmi_ucs2ncpy(str_cnf, GetString(STR_ID_VRSD_DELETE_ALL), 100);
        }

        if (str_id != 0)
        {
            mmi_ucs2cpy((S8*) temp_string, (S8*) GetString(str_id));
            if (!strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_ENGLISH))
            {
                mmi_ucs2cat((S8*) str_cnf, (S8*) L" ");
                len = mmi_ucs2strlen(temp_string);
                for (i = 0; i < len; i++)
                {
                    temp_string[i] = (UI_character_type) mmi_towlower((kal_wchar) temp_string[i]);
                }
            }
            mmi_ucs2cat((S8*) str_cnf, (S8*) temp_string);

        }
        if (!strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_ENGLISH))
        {
            mmi_ucs2cat((S8*) str_cnf, (S8*) L" ");
        }
    #ifdef __MMI_VRSD_REDIAL__
        if (str_id == STR_ID_VRSD_REDIAL)
        {
            mmi_ucs2cat((S8*) str_cnf, (S8*) GetString(STR_ID_VRSD_TAG_QUESTION));
        }
        else
    #endif /* __MMI_VRSD_REDIAL__ */ 
    #ifdef __MMI_VRSD_AUDPLAYER__
        if (str_id == STR_ID_VRSD_AUD_PLAYER)
        {
            mmi_ucs2cat((S8*) str_cnf, (S8*) GetString(STR_ID_VRSD_TAG_QUESTION));
        }
        else
    #endif /* __MMI_VRSD_AUDPLAYER__ */ 
        {
            mmi_ucs2cat((S8*) str_cnf, (S8*) GetString(STR_ID_VRSD_REQUESTION));
        }
        mmi_display_popup_confirm(
            (UI_string_type)GetString(STR_GLOBAL_YES),
            (PU8)GetImage(IMG_GLOBAL_YES),
            (UI_string_type)GetString(STR_GLOBAL_NO),
            (PU8)GetImage(IMG_GLOBAL_NO),
            (UI_string_type)str_cnf,
            MMI_EVENT_QUERY);
       
        SetLeftSoftkeyFunction(mmi_vrsd_del_all_tag_by_appid, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
    	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_EMPTY),
			MMI_EVENT_FAILURE);
       
    }

}

#define MMI_VRSD_STATUS


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_highlight_status
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_highlight_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_vrsd_entry_status, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsd_entry_status, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_entry_status
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_entry_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 tag_status[256];
    U16 count_list[MMI_VRSD_APP_TOTAL];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tag_status, 0, 256);
    memset(count_list, 0, sizeof(U16) * MMI_VRSD_APP_TOTAL);

    mmi_vrsd_get_each_tag_count(count_list);

    mmi_vrsd_tag_status_print_string(STR_ID_VRSD_TAG_STATUS, count_list[MMI_VRSD_APP_ALL], tag_status);
#if defined(__MMI_VRSD_DIAL__)
    mmi_vrsd_tag_status_print_string(STR_ID_VRSD_DIAL, count_list[MMI_VRSD_APP_DIAL], tag_status);
#endif 
#if defined(__MMI_VRSD_REDIAL__)
    mmi_vrsd_tag_status_print_string(STR_ID_VRSD_REDIAL, count_list[MMI_VRSD_APP_REDIAL], tag_status);
#endif 
#if defined(__MMI_VRSD_PROFILE__)
    mmi_vrsd_tag_status_print_string(STR_ID_VRSD_PROFILE, count_list[MMI_VRSD_APP_PROFILE], tag_status);
#endif 
#if defined(__MMI_VRSD_AUDPLAYER__)
    mmi_vrsd_tag_status_print_string(STR_ID_VRSD_AUD_PLAYER, count_list[MMI_VRSD_APP_AUDPLAYER], tag_status);
#endif 
#if defined(__MMI_VRSD_SHORTCUT__)
    mmi_vrsd_tag_status_print_string(STR_ID_VRSD_SHORTCUT, count_list[MMI_VRSD_APP_SHORTCUT], tag_status);
#endif 

    EntryNewScreen(SCR_ID_VRSD_STATUS, NULL, mmi_vrsd_entry_status, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSD_STATUS);
    ShowCategory7Screen(
        STR_ID_VRSD_TAG_STATUS,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) tag_status,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_tag_status_print_string
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  str_id          [IN]        
 *  count           [IN]        
 *  tag_status      [?]         [?]
 *  a(?)            [IN/OUT]        First variable, used as returns(?)
 *  b(?)            [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_tag_status_print_string(U16 str_id, U16 count, S8 *tag_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 tmpStr[20];
    S8 tmpStr_UCS2[40];
    U8 colon[4] = {0x1A, 0xFF, 0x00, 0x00};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cat(tag_status, GetString(str_id));
    memset(tmpStr, 0, 20);

    if (str_id == STR_ID_VRSD_TAG_STATUS)
    {
        if (!strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_TCHINESE) ||
            !strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SCHINESE))
        {
            sprintf(tmpStr, "\r\n%d/%d\n", count, MMI_VRSD_MAX_TAG);
        }
        else
        {
            sprintf(tmpStr, ": %d/%d\n", count, MMI_VRSD_MAX_TAG);
        }
    }
    else
    {
        if (!strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_TCHINESE) ||
            !strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SCHINESE))
        {
            sprintf(tmpStr, " %d\n", count);
        }
        else
        {
            sprintf(tmpStr, ": %d\n", count);
        }
    }

    mmi_asc_to_ucs2(tmpStr_UCS2, tmpStr);
    if (!strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_TCHINESE) ||
        !strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SCHINESE))
    {
        mmi_ucs2cat(tag_status, (S8*) colon);
    }
    mmi_ucs2cat(tag_status, tmpStr_UCS2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_get_each_tag_count
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  count_list      [?]     [?]
 *  a(?)            [IN/OUT]        First variable, used as returns(?)
 *  b(?)            [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_get_each_tag_count(U16 *count_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    S16 pError;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_VRSD_TAG_LID, 1, (void*)tag_list, MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSD_MAX_TAG; i++)
    {
    #if defined(__MMI_VRSD_DIAL__)
        if (((tag_list[i].app_id == MMI_VRSD_APP_DIAL) && (tag_list[i].appref_id != 0xffff)))
        {
            count_list[MMI_VRSD_APP_DIAL]++;
        }
    #endif /* defined(__MMI_VRSD_DIAL__) */ 
    #if defined(__MMI_VRSD_REDIAL__)
        if (((tag_list[i].app_id == MMI_VRSD_APP_REDIAL) && (tag_list[i].appref_id != 0xffff)))
        {
            count_list[MMI_VRSD_APP_REDIAL]++;
        }
    #endif /* defined(__MMI_VRSD_REDIAL__) */ 
    #if defined(__MMI_VRSD_PROFILE__)
        if (((tag_list[i].app_id == MMI_VRSD_APP_PROFILE) && (tag_list[i].appref_id != 0xffff)))
        {
            count_list[MMI_VRSD_APP_PROFILE]++;
        }
    #endif /* defined(__MMI_VRSD_PROFILE__) */ 
    #if defined(__MMI_VRSD_AUDPLAYER__)
        if (((tag_list[i].app_id == MMI_VRSD_APP_AUDPLAYER) && (tag_list[i].appref_id != 0xffff)))
        {
            count_list[MMI_VRSD_APP_AUDPLAYER]++;
        }
    #endif /* defined(__MMI_VRSD_AUDPLAYER__) */ 
    #if defined(__MMI_VRSD_SHORTCUT__)
        if (((tag_list[i].app_id == MMI_VRSD_APP_SHORTCUT) && (tag_list[i].appref_id != 0xffff)))
        {
            count_list[MMI_VRSD_APP_SHORTCUT]++;
        }
    #endif /* defined(__MMI_VRSD_SHORTCUT__) */ 
    }

    for (i = 1; i < MMI_VRSD_APP_TOTAL; i++)
    {
        count_list[MMI_VRSD_APP_ALL] += count_list[i];
    }

}

#define MMI_VRSD_UTILITY


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_sync_tag_with_db
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_sync_tag_with_db(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    U16 syn_list[MMI_VRSD_MAX_TAG];
    S16 pError;
    U16 i, j;
    U16 syn_length = 0, org_length;
    S32 result;
    BOOL in_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsd_cntx.vrtag_sync != 2)
    {
        /* Retrieve data from NVRAM */
        ReadRecord(
            NVRAM_EF_VRSD_TAG_LID,
            MMI_VRSD_GROUP_ALL,
            (void*)tag_list,
            MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
            &pError);

        /* Build Sync List for MED */
        for (i = 0; i < MMI_VRSD_MAX_TAG; i++)
            if ((tag_list[i].appref_id != 0xffff) && (tag_list[i].app_id != MMI_VRSD_APP_NONE))
            {
                syn_list[syn_length++] = i;
            }

        /* Sync with MED */
        org_length = syn_length;
        result = media_aud_vr_sync_db(
                    MOD_MMI,
                    MED_VR_ISD_MODE,
                    MED_VR_NO_CARE_LANG,
                    MMI_VRSD_GROUP_ALL,
                    &syn_length,
                    (U16*) syn_list);

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VRSD_FUNC_SYNC_TAG_WITH_DB, result, org_length, syn_length);

        /* Sync result from MED if list has changed */
        if ((result == MED_RES_OK) && (org_length != syn_length))
        {
            for (i = 0; i < MMI_VRSD_MAX_TAG; i++)
            {
                in_list = FALSE;
                for (j = 0; j < syn_length; j++)
                {
                    if (i == syn_list[j])
                    {
                        in_list = TRUE;
                        break;
                    }
                }
                if (!in_list)
                {
                    tag_list[i].appref_id = 0xffff;
                    tag_list[i].app_id = MMI_VRSD_APP_NONE;
                }
            }

            WriteRecord(
                NVRAM_EF_VRSD_TAG_LID,
                MMI_VRSD_GROUP_ALL,
                (void*)tag_list,
                MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
                &pError);
        }

        g_vrsd_cntx.vrtag_sync = 2;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_util_get_tag_id
 * DESCRIPTION
 *  This function is return the voice tag id using application id and application reference id.
 *  If user wants to find an enpty tag, just past MMI_VRSD_APP_NONE and 0xffff
 * PARAMETERS
 *  app_id          [IN]        Application ID of voice control application
 *  appref_id       [IN]        Application Reference ID which maintain by app itself
 * RETURNS
 *  voice tag ID
 *****************************************************************************/
U16 mmi_vrsd_util_get_tag_id(U8 app_id, U16 appref_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    S16 pError;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Retrieve data from NVRAM */
    ReadRecord(NVRAM_EF_VRSD_TAG_LID, 1, (void*)tag_list, MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSD_MAX_TAG; i++)
    {
        if ((tag_list[i].app_id == app_id) && (tag_list[i].appref_id == appref_id))
        {
            return i;
        }
    }

    return 0xffff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_util_get_tag_id_in_list
 * DESCRIPTION
 *  This function is return the voice tag id using application id and application reference id.
 *  (Note 1) If user wants to find an enpty tag, just past MMI_VRSD_APP_NONE and 0xffff
 *  (Note 2) User should read the voice tag list before enter this function.
 * PARAMETERS
 *  app_id          [IN]        Application ID of voice control application
 *  appref_id       [IN]        Application Reference ID which maintain by app itself
 *  tag_list        [IN]        Voice Tag List Read outside this function.
 * RETURNS
 *  voice tag ID
 *****************************************************************************/
U16 mmi_vrsd_util_get_tag_id_in_list(U8 app_id, U16 appref_id, vrsd_tag_struct *tag_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_VRSD_MAX_TAG; i++)
    {
        if ((tag_list[i].app_id == app_id) && (tag_list[i].appref_id == appref_id))
        {
            return i;
        }
    }

    return 0xffff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_playback_req
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  tag_id          [IN]        
 *  callback        [IN]        
 *  a(?)            [IN/OUT]        First variable, used as returns(?)
 *  b(?)            [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_playback_req(U16 tag_id, void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__)
        if (srv_ucm_is_background_call())
        {
            /* not need to show popup here */
            //mmi_ucm_entry_error_message();
            return;
        }
#endif
    if (callback != NULL)
    {
        g_vrsd_cntx.play_callback = callback;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8)GetRingVolumeLevel());
        result = mdi_audio_play_voice_tag(
                    MED_VR_ISD_MODE,
                    MED_VR_NO_CARE_LANG,
                    MMI_VRSD_GROUP_ALL,
                    tag_id,
                    mmi_vrsd_playback_finish,
                    NULL);
    }
    else
    {
    		mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8)GetRingVolumeLevel());
        result = mdi_audio_play_voice_tag(MED_VR_ISD_MODE, MED_VR_NO_CARE_LANG, MMI_VRSD_GROUP_ALL, tag_id, NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_playback_finish
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  result      [IN]        
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_playback_finish(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* call back is not null and play finish */
    if ((g_vrsd_cntx.play_callback != NULL) && (result == MDI_AUDIO_END_OF_FILE))
    {
        g_vrsd_cntx.play_callback();
    }
    else
    {
        	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_FAILURE),
			MMI_EVENT_FAILURE);
    }

    g_vrsd_cntx.play_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_get_total_tag_count
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  app_id      [IN]        
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
U16 mmi_vrsd_get_total_tag_count(U8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    U16 i;
    U16 count = 0;
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Retrieve data from NVRAM */
    ReadRecord(
        NVRAM_EF_VRSD_TAG_LID,
        MMI_VRSD_GROUP_ALL,
        (void*)tag_list,
        MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
        &pError);

    if (app_id != MMI_VRSD_APP_ALL)
    {
        for (i = 0; i < MMI_VRSD_MAX_TAG; i++)
        {
            if (((tag_list[i].app_id == app_id) && (tag_list[i].appref_id != 0xffff)))
            {
                count++;
            }
        }
    }
    else
    {
        for (i = 0; i < MMI_VRSD_MAX_TAG; i++)
        {
            if ((tag_list[i].appref_id != 0xffff))
            {
                count++;
            }
        }
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_error_popup
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  error_id        [IN]        
 *  a(?)            [IN/OUT]        First variable, used as returns(?)
 *  b(?)            [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_error_popup(U16 error_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (error_id)
    {
        case MED_RES_NO_SOUND:
            error_id = STR_ID_VRSD_NO_SOUND;
            break;
        case MED_RES_NO_MATCH:
            error_id = STR_ID_VRSD_NO_MATCH;
            break;
        case MED_RES_TOO_SIMILAR:
            error_id = STR_ID_VRSD_TOO_SIMILAR;
            break;
        case MED_RES_TOO_DIFFERENT:
            error_id = STR_ID_VRSD_TOO_DIFFERENT;
            break;
        case MED_RES_DISC_FULL:
            error_id = STR_GLOBAL_MEMORY_FULL;
            break;
        case MED_RES_SPEAK_TOO_LONG:
            error_id = STR_ID_VRSD_SPEAK_TOO_LONG;
            break;
        case MED_RES_SPEAK_TOO_SHORT:
            error_id = STR_ID_VRSD_SPEAK_TOO_SHORT;
            break;
        default:
            error_id = STR_ID_VRSD_RECV_VOICE_FAIL;
            break;
    }
    	//failure
		mmi_display_popup(
			(UI_string_type)GetString(error_id),
			MMI_EVENT_FAILURE);
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_clear_rcg_callback
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_clear_rcg_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_VRSD_APP_TOTAL; i++)
    {
        g_vrsd_cntx.rcg_callback[i] = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_register_rcg_callback
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  app_id              [IN]        
 *  rcg_callback        [IN]        
 *  a(?)                [IN/OUT]        First variable, used as returns(?)
 *  b(?)                [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_register_rcg_callback(U8 app_id, void (*rcg_callback) (U16))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsd_cntx.rcg_callback[app_id] = rcg_callback;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_get_mapping_index
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  tag_id          [IN]        
 *  appref_id       [?]         [?]
 *  app_id          [?]         [?]
 *  a(?)            [IN/OUT]        First variable, used as returns(?)
 *  b(?)            [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_get_mapping_index(U16 tag_id, U16 *appref_id, U8 *app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Retrieve data from NVRAM */
    ReadRecord(NVRAM_EF_VRSD_TAG_LID, 1, (void*)tag_list, MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct), &pError);

    if (tag_id < MMI_VRSD_MAX_TAG)
    {
        *appref_id = tag_list[tag_id].appref_id;
        *app_id = tag_list[tag_id].app_id;
    }
    else
    {
        *appref_id = 0xffff;
        *app_id = MMI_VRSD_APP_NONE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_del_tag_req
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  vrtag_id        [IN]        
 *  a(?)            [IN/OUT]        First variable, used as returns(?)
 *  b(?)            [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
BOOL mmi_vrsd_del_tag_req(U16 vrtag_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_vr_del_tag(MOD_MMI, MED_VR_ISD_MODE, MED_VR_NO_CARE_LANG, MMI_VRSD_GROUP_ALL, vrtag_id);

    if (result == MED_RES_OK)
    {
        vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
        S16 pError;

        /* Retrieve data from NVRAM */
        ReadRecord(NVRAM_EF_VRSD_TAG_LID, 1, (void*)tag_list, MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct), &pError);

        tag_list[vrtag_id].appref_id = 0xffff;
        tag_list[vrtag_id].app_id = MMI_VRSD_APP_NONE;

        WriteRecord(NVRAM_EF_VRSD_TAG_LID, 1, (void*)tag_list, MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct), &pError);
     	//success
	    mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_DELETED),
			MMI_EVENT_SUCCESS);   
        
    }
    else
    {
    	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_UNFINISHED),
			MMI_EVENT_FAILURE);
       
    }
    return (result == MED_RES_OK)? TRUE : FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_del_all_tag_by_appid
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.(?)(?)
 *****************************************************************************/
void mmi_vrsd_del_all_tag_by_appid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    S16 pError;
    S32 result;
    BOOL error = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Retrieve data from NVRAM */
    ReadRecord(
        NVRAM_EF_VRSD_TAG_LID,
        MMI_VRSD_GROUP_ALL,
        (void*)tag_list,
        MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
        &pError);

    for (i = 0; i < MMI_VRSD_MAX_TAG; i++)
    {
        if (((g_vrsd_cntx.app_id == MMI_VRSD_APP_ALL) && (tag_list[i].appref_id != 0xffff)) ||
            ((tag_list[i].app_id == g_vrsd_cntx.app_id) && (tag_list[i].appref_id != 0xffff)))
        {
            result = media_aud_vr_del_tag(MOD_MMI, MED_VR_ISD_MODE, MED_VR_NO_CARE_LANG, MMI_VRSD_GROUP_ALL, i);

            if (result != MED_RES_OK)
            {
                error = TRUE;
                continue;
            }

            tag_list[i].appref_id = 0xffff;
            tag_list[i].app_id = MMI_VRSD_APP_NONE;
        }
    }

    WriteRecord(
        NVRAM_EF_VRSD_TAG_LID,
        MMI_VRSD_GROUP_ALL,
        (void*)tag_list,
        MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
        &pError);

    /* Reset status flag for some applications */
#if defined(__MMI_VRSD_REDIAL__)
    if (g_vrsd_cntx.app_id == MMI_VRSD_APP_ALL || g_vrsd_cntx.app_id == MMI_VRSD_APP_REDIAL)
    {
        mmi_vrsdredial_del_tag_rest_flag();
    }
#endif /* defined(__MMI_VRSD_REDIAL__) */ 
#if defined(__MMI_VRSD_PROFILE__)
    if (g_vrsd_cntx.app_id == MMI_VRSD_APP_ALL || g_vrsd_cntx.app_id == MMI_VRSD_APP_PROFILE)
    {
        mmi_vrsdprf_del_tag_reset_flag();
    }
#endif /* defined(__MMI_VRSD_PROFILE__) */ 
#if defined(__MMI_VRSD_AUDPLAYER__)
    if (g_vrsd_cntx.app_id == MMI_VRSD_APP_ALL || g_vrsd_cntx.app_id == MMI_VRSD_APP_AUDPLAYER)
    {
        mmi_vrsdaudp_del_tag_reset_flag();
    }
#endif /* defined(__MMI_VRSD_AUDPLAYER__) */ 

    if (error)
    {
        	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_FAILURE),
			MMI_EVENT_FAILURE);
    }
    else
    {
    	//success
	    mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_DELETED),
			MMI_EVENT_SUCCESS);
       
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_get_strid_by_appid
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  app_id      [IN]        
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
U16 mmi_vrsd_get_strid_by_appid(U8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (app_id)
    {
    #if defined(__MMI_VRSD_DIAL__)
        case MMI_VRSD_APP_DIAL:
            return STR_ID_VRSD_DIAL;
    #endif /* defined(__MMI_VRSD_DIAL__) */ 
    #if defined(__MMI_VRSD_REDIAL__)
        case MMI_VRSD_APP_REDIAL:
            return STR_ID_VRSD_REDIAL;
    #endif /* defined(__MMI_VRSD_REDIAL__) */ 
    #if defined(__MMI_VRSD_PROFILE__)
        case MMI_VRSD_APP_PROFILE:
            return STR_ID_VRSD_PROFILE;
    #endif /* defined(__MMI_VRSD_PROFILE__) */ 
    #if defined(__MMI_VRSD_AUDPLAYER__)
        case MMI_VRSD_APP_AUDPLAYER:
            return STR_ID_VRSD_AUD_PLAYER;
    #endif /* defined(__MMI_VRSD_AUDPLAYER__) */ 
    #if defined(__MMI_VRSD_SHORTCUT__)
        case MMI_VRSD_APP_SHORTCUT:
            return STR_ID_VRSD_SHORTCUT;
    #endif /* defined(__MMI_VRSD_SHORTCUT__) */ 
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_get_appid_by_menuid
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  menu_id     [IN]        
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
U16 mmi_vrsd_get_appid_by_menuid(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_id)
    {
    #if defined(__MMI_VRSD_DIAL__)
        case MENU_ID_VRSD_DELETE_ALL_DIAL:
            return MMI_VRSD_APP_DIAL;
    #endif /* defined(__MMI_VRSD_DIAL__) */ 
    #if defined(__MMI_VRSD_REDIAL__)
        case MENU_ID_VRSD_DELETE_ALL_REDIAL:
            return MMI_VRSD_APP_REDIAL;
    #endif /* defined(__MMI_VRSD_REDIAL__) */ 
    #if defined(__MMI_VRSD_PROFILE__)
        case MENU_ID_VRSD_DELETE_ALL_PROFILE:
            return MMI_VRSD_APP_PROFILE;
    #endif /* defined(__MMI_VRSD_PROFILE__) */ 
    #if defined(__MMI_VRSD_AUDPLAYER__)
        case MENU_ID_VRSD_DELETE_ALL_AUDPLAYER:
            return MMI_VRSD_APP_AUDPLAYER;
    #endif /* defined(__MMI_VRSD_AUDPLAYER__) */ 
    #if defined(__MMI_VRSD_SHORTCUT__)
        case MENU_ID_VRSD_DELETE_ALL_SHORTCUT:
            return MMI_VRSD_APP_SHORTCUT;
    #endif /* defined(__MMI_VRSD_SHORTCUT__) */ 
        default:    /* MENU_ID_VRSD_DELETE_ALL_ALL */
            return MMI_VRSD_APP_ALL;
    }

}

#if defined(__MMI_BT_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_bt_set_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsd_bt_set_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4_bt_set_vr_req_ind_struct *local_p;
    U16 scr_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_p = (mmi_l4_bt_set_vr_req_ind_struct*) msg;

    /* Activate VR */
    if (local_p->on_off)
    {
        /* Check if in USB mode before enter VR */
#if defined(__USB_IN_NORMAL_MODE__)
        if (mmi_usb_is_in_mass_storage_mode())
        {
            mmi_usb_app_unavailable_popup(0);

            mmi_vrsd_bt_set_ind_cnf(FALSE);
            g_vrsd_init_by_bt = FALSE;
            return;
        }
#endif /* defined(__USB_IN_NORMAL_MODE__) */
    
#if defined(__MMI_VRSD_DIAL__)
        if (mmi_vrsddial_check_sim_change())
        {
            mmi_vrsd_bt_set_ind_cnf(FALSE);
            g_vrsd_init_by_bt = FALSE;        
            return;
        }
#endif
        
        /* If VR is turned on and not in call, init VR procedure */
        if (g_vrsd_cntx.rcg_enable &&
            (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0) &&
            (GetActiveScreenId() == IDLE_SCREEN_ID) &&
            (g_vrsd_cntx.vrstage == MMI_VRSD_STATE_IDLE))
        {

            
            mmi_vrsd_sync_tag_with_db();
            
            if (!mmi_vrsd_get_total_tag_count(MMI_VRSD_APP_ALL))
            {
            
	        //failure
		        mmi_display_popup(
			        (UI_string_type)GetString(STR_ID_VRSD_NO_TAG_EXIST),
			        MMI_EVENT_FAILURE);
                mmi_vrsd_bt_set_ind_cnf(FALSE);
                return;
            }
            
            mmi_vrsd_bt_set_ind_cnf(TRUE);
            g_vrsd_init_by_bt = TRUE;

            mmi_vrsd_rcg_init();
        }
        else
        {
            mmi_vrsd_bt_set_ind_cnf(FALSE);
            g_vrsd_init_by_bt = FALSE;
        }
    }
    /* Deactivate VR */
    else
    {        
        scr_id = GetActiveScreenId();
        if (scr_id == SCR_ID_VRSD_RECV_VOICE)
        {
            mmi_vrsd_bt_set_ind_cnf(TRUE);
            g_vrsd_cntx.user_abort = 1;
            g_vrsd_close_by_bt = 1;  
            GoBackHistory();
        }
        else
        {
            mmi_vrsd_bt_set_ind_cnf(TRUE);
        }
        g_vrsd_init_by_bt = FALSE;
        g_vrsd_close_by_bt = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_bt_set_ind_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  success     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsd_bt_set_ind_cnf(BOOL success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_general_res_req_struct *msg_p;
    MYQUEUE message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
    if (success)
    {
        msg_p->result = KAL_TRUE;
    }
    else
    {
        msg_p->result = KAL_FALSE;
    }

    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_L4C;
    message.oslMsgId = MSG_ID_MMI_AT_GENERAL_RES_REQ;
    message.oslDataPtr = (oslParaType*) msg_p;
    message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_bt_set_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_activate     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsd_bt_set_req(BOOL is_activate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4_bt_set_vr_req_struct *msg_p;
    MYQUEUE message;
    BOOL vr_on_off = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Activate VR */
    if (is_activate)
    {
        /* Inform bluetooth */
        if ((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)))
        {
            vr_on_off = TRUE;
            g_vrsd_init_by_bt = TRUE;
        }
        /* Bluetooth is not connected, no need to inform it */
        else
        {
            g_vrsd_init_by_bt = FALSE;
            return;
        }
    }
    /* Deactivate VR */
    else
    {
        /* Bluetooth exists and VR informed Bluetooth at activate phase */
        if ((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)) && g_vrsd_init_by_bt)
        {
            vr_on_off = FALSE;
            g_vrsd_init_by_bt = FALSE;
        }
        else
        {
            return;
        }
    }

    msg_p = (mmi_l4_bt_set_vr_req_struct*) OslConstructDataPtr(sizeof(mmi_l4_bt_set_vr_req_struct));

    if (vr_on_off)
    {
        msg_p->on_off = KAL_TRUE;
    }
    else
    {
        msg_p->on_off = KAL_FALSE;
    }

    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_L4C;
    message.oslMsgId = PRT_MMI_L4_BT_SET_VR_REQ;
    message.oslDataPtr = (oslParaType*) msg_p;
    message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_bt_set_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsd_bt_set_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4_bt_set_vr_rsp_struct *local_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_p = (mmi_l4_bt_set_vr_rsp_struct*) msg;

    /* Do nothing currently. */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_bt_connect_sco_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsd_bt_connect_sco_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    StartTimer(VRSD_PLAYTONE_TIMER, MMI_VRSD_PLAY_TONE_DELAY_TIME, mmi_vrsd_recv_voice_prompt_tone);
}

#endif /* defined(__MMI_BT_SUPPORT__) */

#endif /* defined(__MMI_VRSD__) */ /* #if defined(__MMI_VRSD__) */
#endif /* _MMI_VRSDMAIN_C */ /* #ifndef _MMI_VRSDMAIN_C */

