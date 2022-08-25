/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  MMSMessageSettings.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the ui and NVRAm integration for message settings
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/***************************************************************************** 
* Include
*****************************************************************************/
#if defined (OBIGO_Q03C_MMS_V01)
#include "MMI_include.h"
#include "mmi_features.h"
#include "commonscreens.h"


/*For Frofile*/
#ifdef __MMI_WAP_PROF__
#include "WAPProfileGProt.h"
#include "WAPProfileType.h"
#include "WAPprovisioningType.h"
#endif /* __MMI_WAP_PROF__ */
#include "mea_api.h"
#include "q03c_mms_V01_agentprot.h"
#include "q03c_mms_V01_agentResDef.h"
#include "q03c_mms_V01_agentSettings.h"


/***************************************************************************** 
* Global setting contetx
*****************************************************************************/

mmsV01_agent_setting_context_struct mmsv01_agent_setting_context;
mmsV01_agent_setting_context_struct *g_mmsv01_agent_setting_context = &mmsv01_agent_setting_context;

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_message_settings_init
 * DESCRIPTION
 *  This function init the hilight handlers of message settings menu items.
 *  This is called at boot up time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_settings_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_mmsv01_agent_read_nvram_settings();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_read_nvram_settings
 * DESCRIPTION
 *  Read the the message settings from NVRAM
 * PARAMETERS
 *  set_mma     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_read_nvram_settings()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_READ_NVRAM_SETTINGS);
    /*Compose settigs*/
    ReadRecord(
        NVRAM_EF_MMSV01_COMPOSE_SETTINGS_LID,
        1,
        &g_mmsv01_agent_setting_context->nvram_compose_settings,
        NVRAM_MMSV01_COMPOSE_SETTINGS_SIZE,
        &error);

    if (g_mmsv01_agent_setting_context->nvram_compose_settings.creation_mode == 0xFF)
    {
        
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_READ_NVRAM_COMPOSE_SETTINGS_FAILED);

        g_mmsv01_agent_setting_context->nvram_compose_settings.creation_mode = 
            (U8) MMSV01_AGENT_DEFAULT_CREATION_MODE;
   
        g_mmsv01_agent_setting_context->nvram_compose_settings.auto_signature = 
            (U8)MMSV01_AGENT_DEFAULT_AUTO_SIGNATURE;
    

        g_mmsv01_agent_setting_context->nvram_compose_settings.best_page_duration = 
            (U8)MMSV01_AGENT_DEFAULT_BEST_PAGE_DURATION;

#ifdef JPG_ENCODE        
        g_mmsv01_agent_setting_context->nvram_compose_settings.image_resize_option = 
            (U8)MMSV01_AGENT_DEFAULT_IMAGE_RESIZING;
#endif

        memset(
            g_mmsv01_agent_setting_context->nvram_compose_settings.auto_signature_content,
            0x00,
            (MMSV01_AGENT_MAX_AUTO_SIGN_LENGTH + 1) * ENCODING_LENGTH);        
        WriteRecord(
            NVRAM_EF_MMSV01_COMPOSE_SETTINGS_LID,
            1,
            &g_mmsv01_agent_setting_context->nvram_compose_settings,
            NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
            &error);
        ReadRecord(
            NVRAM_EF_MMSV01_COMPOSE_SETTINGS_LID,
            1,
            &g_mmsv01_agent_setting_context->nvram_compose_settings,
            NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
            &error);
    }

    /*Sending settings*/
    ReadRecord(
        NVRAM_EF_MMSV01_SENDING_SETTINGS_LID,
        1,
        &g_mmsv01_agent_setting_context->nvram_sending_settings,
        NVRAM_MMSV01_SENDING_SETTINGS_SIZE,
        &error);

    if (g_mmsv01_agent_setting_context->nvram_sending_settings.delivery_report == 0xFF)
    {

        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_READ_NVRAM_SENDING_SETTINGS_FAILED);
        /*Delivery Report*/
        g_mmsv01_agent_setting_context->nvram_sending_settings.delivery_report = 
            (U8) MMSV01_AGENT_DEFAULT_DELIVERY_REPORT_DURING_SENDING;
        /*Delivery Time*/
        g_mmsv01_agent_setting_context->nvram_sending_settings.delivery_time = 
            (U8)MMSV01_AGENT_DEFAULT_DELIVERY_TIME;

#ifdef __MMI_MMS_BGSR_SUPPORT__
        /*Save and Send*/
        g_mmsv01_agent_setting_context->nvram_sending_settings.send_and_save = 
            (U8)MMSV01_AGENT_DEFAULT_SAVE_AND_SEND;
#endif
        /*Priority*/
        g_mmsv01_agent_setting_context->nvram_sending_settings.priority = 
            (U8) MMSV01_AGENT_DEFAULT_PRIORITY;
        /*Read Report*/
        g_mmsv01_agent_setting_context->nvram_sending_settings.read_report = 
            (U8) MMSV01_AGENT_DEFAULT_READ_REPORT_DURING_SENDING;
        /*Validity Period*/
        g_mmsv01_agent_setting_context->nvram_sending_settings.validity_period = 
            (U8) MMSV01_AGENT_DEFAULT_VALIDITY_PERIOD;
        /*Slide Time*/
        g_mmsv01_agent_setting_context->nvram_sending_settings.default_slide_time = 
            ((U32) MMSV01_AGENT_DEFAULT_SLIDE_DURATION) / 1000; /* /convert to seconds */

        WriteRecord(
            NVRAM_EF_MMSV01_SENDING_SETTINGS_LID,
            1,
            &g_mmsv01_agent_setting_context->nvram_sending_settings,
            NVRAM_MMSV01_SENDING_SETTINGS_SIZE,
            &error);
        ReadRecord(
            NVRAM_EF_MMSV01_SENDING_SETTINGS_LID,
            1,
            &g_mmsv01_agent_setting_context->nvram_sending_settings,
            NVRAM_MMSV01_SENDING_SETTINGS_SIZE,
            &error);
    }

    /*reterival settings + filters*/
    ReadValue(NVRAM_MMSV01_RETRIEVAL_SETTINGS, 
        &g_mmsv01_agent_setting_context->nvram_retrieval_settings, 
        DS_DOUBLE, 
        &error);

    if (g_mmsv01_agent_setting_context->nvram_retrieval_settings.home_network == 0xFF)
    {    
       MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_READ_NVRAM_RETRIVAL_SETTINGS_FAILED);
        /*Home Network*/
        g_mmsv01_agent_setting_context->nvram_retrieval_settings.home_network = 
                                        (U8)MMSV01_AGENT_DEFAULT_HOME_RETRIEVAL_MODE;
        /*Read report*/
        g_mmsv01_agent_setting_context->nvram_retrieval_settings.read_report = 
            (U8) MMSV01_AGENT_DEFAULT_READ_REPORT_DURING_RETRIEVAL;
        /*Delivery Report*/
        g_mmsv01_agent_setting_context->nvram_retrieval_settings.delivery_report = 
            (U8) MMSV01_AGENT_DEFAULT_DELIVERY_REPORT_DURING_RETRIEVAL;
        /*Roaming Network*/
        g_mmsv01_agent_setting_context->nvram_retrieval_settings.roaming =            
            (U8)MMSV01_AGENT_DEFAULT_ROAMING_RETRIEVAL_MODE;

        /* Anonymous filter*/
        g_mmsv01_agent_setting_context->nvram_retrieval_settings.anonymous_filter =
            (U8)MMSV01_AGENT_DEFAULT_ANONYMOUS_FILTER_VALUE;

        /* Advertisement filter*/
        g_mmsv01_agent_setting_context->nvram_retrieval_settings.advertisement_filter =
            (U8)MMSV01_AGENT_DEFAULT_ADVERTISEMENT_FILTER_VALUE;
       
        WriteValue(NVRAM_MMSV01_RETRIEVAL_SETTINGS, 
            &g_mmsv01_agent_setting_context->nvram_retrieval_settings, 
            DS_DOUBLE, 
            &error);
        ReadValue(NVRAM_MMSV01_RETRIEVAL_SETTINGS, 
            &g_mmsv01_agent_setting_context->nvram_retrieval_settings, 
            DS_DOUBLE, 
            &error);
    }
}

#ifdef __MMI_WAP_PROF__
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_get_active_profile_rsp_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
void mmi_mmsv01_get_active_profile_rsp_callback(mmi_wap_prof_sim_id_enum sim_id,
                                              mmi_wap_prof_profile_content_struct * profile_content_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(profile_content_p);
    
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_GET_ACTIVE_PROFILE_RSP_CALLBACK);

    mmi_mmsv01_agent_send_set_profile_req(profile_content_p, (kal_uint8)sim_id);

    OslMfree(profile_content_p);
    profile_content_p = NULL;
}

#ifdef __MMI_MMS_DUAL_SIM__
void mmi_mmsv01_clear_profile_set_flag(void)
{
    g_mmsv01_agent_setting_context->profile_set_for_sim1 = FALSE;
    g_mmsv01_agent_setting_context->profile_set_for_sim2 = FALSE;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_set_current_profile_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_set_current_profile_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_prof_profile_content_struct* profile_struct = NULL;
#ifdef __MMI_MMS_DUAL_SIM__
    mmi_wap_prof_profile_content_struct* profile_struct_2 = NULL;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_SET_CURRENT_PROFILE_REQ);

#ifdef __MMI_MMS_DUAL_SIM__
	if(g_mmi_mms_V01_agent_ctx.is_sim1_valid && 
       g_mmsv01_agent_setting_context->profile_set_for_sim1 == FALSE)
#endif
	{
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_GET_CURRENT_PROFILE_FOR_SIM_1);

        profile_struct = (mmi_wap_prof_profile_content_struct*)mmi_wap_prof_get_profile_content(
                                                                   MMI_WAP_PROF_SIMID_SIM1,
                                                                   MMI_WAP_PROF_APPID_MMS,
                                                                   (U8) -1,
                                                                   mmi_mmsv01_get_active_profile_rsp_callback);
                                                                                               
	                                                                      
	                                                                      
	}

#ifdef __MMI_MMS_DUAL_SIM__
	if(g_mmi_mms_V01_agent_ctx.is_sim2_valid &&
        g_mmsv01_agent_setting_context->profile_set_for_sim2 == FALSE)
	{

        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_GET_CURRENT_PROFILE_FOR_SIM_2);

        profile_struct_2 = (mmi_wap_prof_profile_content_struct*)mmi_wap_prof_get_profile_content(
                                                                   MMI_WAP_PROF_SIMID_SIM2,
                                                                   MMI_WAP_PROF_APPID_MMS,
                                                                   (U8) -1,
                                                                   mmi_mmsv01_get_active_profile_rsp_callback);
		   
	}
#endif /*__MMI_MMS_DUAL_SIM__*/
    
    if(profile_struct)
    {
        mmi_mmsv01_agent_send_set_profile_req(profile_struct, MMI_WAP_PROF_SIMID_SIM1);
#ifdef __MMI_MMS_DUAL_SIM__
		g_mmsv01_agent_setting_context->profile_set_for_sim1 = TRUE;
#endif
	    OslMfree(profile_struct);
        profile_struct = NULL;

    }
#ifdef __MMI_MMS_DUAL_SIM__
    if(profile_struct_2)
    {
    
        mmi_mmsv01_agent_send_set_profile_req(profile_struct_2, MMI_WAP_PROF_SIMID_SIM2);
		g_mmsv01_agent_setting_context->profile_set_for_sim2 = TRUE;

	    OslMfree(profile_struct_2);
        profile_struct_2 = NULL;
    }
#endif /*__MMI_MMS_DUAL_SIM__*/
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_active_mms_profile_change_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profile_content_p       [?]         
 *  sim_id                  [IN]        
 *  callback                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_active_mms_profile_change_hdlr(
        mmi_wap_prof_profile_content_struct *profile_content_p,
        mmi_wap_prof_sim_id_enum sim_id,
        mmi_wap_prof_response_funcptr_type callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_ACTIVE_MMS_PROFILE_CHANGE_HDLR, sim_id);

    ASSERT(profile_content_p);

    mmi_mmsv01_agent_send_set_profile_req(profile_content_p, (kal_uint8)sim_id);

    /*Save the RSP callback in glb context*/    
    g_mmsv01_agent_setting_context->rsp_callback = callback;
    
    OslMfree(profile_content_p);
    profile_content_p = NULL;
}


#endif /*__MMI_WAP_PROF__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_get_settings_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_get_settings_req_hdlr(void)
{
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_GET_SETTINGS_REQ_HDLR);

    mmi_mmsv01_send_settings_data(MSG_ID_MEA_GET_SETTING_RSP,
                        &(g_mmsv01_agent_setting_context->nvram_compose_settings),
                        &(g_mmsv01_agent_setting_context->nvram_sending_settings),
                        &(g_mmsv01_agent_setting_context->nvram_retrieval_settings));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_set_settings_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_set_settings_req(void)
{

    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_SET_SETTINGS_REQ_HDLR);

    mmi_mmsv01_send_settings_data(MSG_ID_MEA_SET_SETTING_REQ,
                        &(g_mmsv01_agent_setting_context->nvram_compose_settings),
                        &(g_mmsv01_agent_setting_context->nvram_sending_settings),
                        &(g_mmsv01_agent_setting_context->nvram_retrieval_settings));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_entry_message_settings
 * DESCRIPTION
 *  This function is the entry  handler of message settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_entry_message_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;              /* Buffer holding history data */
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item = 0;                   /* Stores no of children in the submenu */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_MMSV01_AGENT_MESSAGE_SETTINGS, NULL, mmi_mmsv01_entry_message_settings, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_MMSV01_AGENT_MESSAGE_SETTINGS);
    num_item = GetNumOfChild_Ext(MENU_ID_MMSV01_AGENT_SETTINGS_DUMMY);
    GetSequenceStringIds_Ext(MENU_ID_MMSV01_AGENT_SETTINGS_DUMMY, str_item_list);

    SetParentHandler(MENU_ID_MMSV01_AGENT_SETTINGS_DUMMY);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_MMSV01_AGENT_SETTINGS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_entry_common_settings
 * DESCRIPTION
 *  This function is the entry  handler of message settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_entry_common_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;                     /* Buffer holding history data */
    U16 str_item_list[MAX_SUB_MENUS] = {0,};   /* Stores the strings id of submenus returned */
    U16 num_item = 0;                          /* Stores no of children in the submenu */
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    EntryNewScreen(SCR_ID_MMSV01_AGENT_MESSAGE_COMMON_SETTINGS, NULL, mmi_mmsv01_entry_common_settings, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_MMSV01_AGENT_MESSAGE_COMMON_SETTINGS);

    num_item = GetNumOfChild_Ext(MENU_ID_MMSV01_AGENT_SETTINGS_FOR_COMMON_HANDLING);
    GetSequenceStringIds_Ext(MENU_ID_MMSV01_AGENT_SETTINGS_FOR_COMMON_HANDLING, str_item_list);

    SetParentHandler(MENU_ID_MMSV01_AGENT_SETTINGS_FOR_COMMON_HANDLING);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_MMSV01_AGENT_COMMON_SETTINGS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_settings_mms_enter_edit_profile
 * DESCRIPTION
 *  This function is the entry  handler of profile settings according to sim id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_settings_mms_enter_edit_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WAP_PROF__

#ifdef __MMI_MMS_DUAL_SIM__
	if((g_mmi_mms_V01_agent_ctx.is_sim1_valid) || ((!g_mmi_mms_V01_agent_ctx.is_sim1_valid) && (!g_mmi_mms_V01_agent_ctx.is_sim2_valid)))
	{
		mmi_wap_prof_display_profile_list(MMI_WAP_PROF_SIMID_DEFAULT, MMI_WAP_PROF_APPID_MMS, GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID));
	}
	else
	{
		mmi_wap_prof_display_profile_list(MMI_WAP_PROF_SIMID_SIM2, MMI_WAP_PROF_APPID_MMS, GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID));
	}
#else
    mmi_wap_prof_display_profile_list(MMI_WAP_PROF_SIMID_DEFAULT, MMI_WAP_PROF_APPID_MMS, GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID));
#endif

#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_pre_entry_profile_settings
 * DESCRIPTION
 *  This function is the entry  handler of profile settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_pre_entry_profile_settings(void)
{
     

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_DUAL_SIM__
    PU8 gui_buffer = NULL;              /* Buffer holding history data */
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item = 0;					/* Stores no of children in the submenu */
#endif /*__MMI_MMS_DUAL_SIM__*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_DUAL_SIM__
    if(!((g_mmi_mms_V01_agent_ctx.is_sim1_valid) && (g_mmi_mms_V01_agent_ctx.is_sim2_valid)))
#endif
    {
        mmi_mmsv01_settings_mms_enter_edit_profile();
        return;
    }
#ifdef __MMI_MMS_DUAL_SIM__
    EntryNewScreen(SCR_ID_MMSV01_AGENT_MESSAGE_SETTINGS_SIM_SELECTION, NULL, mmi_mmsv01_pre_entry_profile_settings, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_MMSV01_AGENT_MESSAGE_SETTINGS_SIM_SELECTION);
    num_item = GetNumOfChild_Ext(MENU_ID_MMSV01_AGENT_SETTINGS_EDIT_PROFILE);
    GetSequenceStringIds_Ext(MENU_ID_MMSV01_AGENT_SETTINGS_EDIT_PROFILE, str_item_list);

    SetParentHandler(MENU_ID_MMSV01_AGENT_SETTINGS_EDIT_PROFILE);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    
    ShowCategory52Screen(
        MEA_STR_ID_EDIT_PROFILE,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#endif /*__MMI_MMS_DUAL_SIM__*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_highlight_common_mms_settings
 * DESCRIPTION
 *  highlight handler for common mms settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_highlight_common_mms_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_mmsv01_entry_common_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_mmsv01_entry_common_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_highlight_edit_profile
 * DESCRIPTION
 *  highlight handler for edit profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_highlight_edit_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_mmsv01_pre_entry_profile_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_mmsv01_pre_entry_profile_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

#ifdef __MMI_MMS_DUAL_SIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_settings_mms_enter_edit_profile_for_sim1
 * DESCRIPTION
 *  This function is the entry  handler of profile settings for sim1
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_settings_mms_enter_edit_profile_for_sim1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WAP_PROF__
    mmi_wap_prof_display_profile_list(MMI_WAP_PROF_SIMID_DEFAULT, MMI_WAP_PROF_APPID_MMS, GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID));
#endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_settings_mms_enter_edit_profile_for_sim2
 * DESCRIPTION
 *  This function is the entry  handler of profile settings for sim2
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_settings_mms_enter_edit_profile_for_sim2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WAP_PROF__
    mmi_wap_prof_display_profile_list(MMI_WAP_PROF_SIMID_SIM2, MMI_WAP_PROF_APPID_MMS, GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID));
#endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_highlight_mms_setting_sim1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_highlight_mms_setting_sim1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_mmsv01_settings_mms_enter_edit_profile_for_sim1, KEY_EVENT_UP);
    SetKeyHandler(mmi_mmsv01_settings_mms_enter_edit_profile_for_sim1, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_mms_setting_sim2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_highlight_mms_setting_sim2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_mmsv01_settings_mms_enter_edit_profile_for_sim2, KEY_EVENT_UP);
    SetKeyHandler(mmi_mmsv01_settings_mms_enter_edit_profile_for_sim2, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /*__MMI_MMS_DUAL_SIM__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_exit_compose_settings
 * DESCRIPTION
 *  Exit fn for compose settings screeen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_exit_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);

    GenericExitInlineScreen(SCR_ID_MMSV01_AGENT_MESSAGE_COMPOSE_SETTINGS, mmi_mmsv01_entry_compose_settings);     /* added for inline edit history */

    if (g_mmsv01_agent_setting_context->mmsv01_inline_lists != NULL)
    {
        OslMfree(g_mmsv01_agent_setting_context->mmsv01_inline_lists);
        g_mmsv01_agent_setting_context->mmsv01_inline_lists  = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_save_compose_settings
 * DESCRIPTION
 *  write the compose settings to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_save_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 temp_max_no_pages = 0;
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    /*Creation mode*/
    g_mmsv01_agent_setting_context->nvram_compose_settings.creation_mode =
        g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.creation_mode;

    /*Image resizing*/
    g_mmsv01_agent_setting_context->nvram_compose_settings.image_resize_option =
        g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.image_resize_option;

    /*Best page duration*/
    g_mmsv01_agent_setting_context->nvram_compose_settings.best_page_duration =
        g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.best_page_duration;

    /*Auto signature*/
    g_mmsv01_agent_setting_context->nvram_compose_settings.auto_signature =
        g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.auto_signature;
    
    
    WriteRecord(
        NVRAM_EF_MMSV01_COMPOSE_SETTINGS_LID,
        1,
        &g_mmsv01_agent_setting_context->nvram_compose_settings,
        NVRAM_MMSV01_COMPOSE_SETTINGS_SIZE,
        &error);

    
    mmi_mmsv01_send_settings_data(MSG_ID_MEA_SET_SETTING_REQ,
                        &(g_mmsv01_agent_setting_context->nvram_compose_settings),
                        &(g_mmsv01_agent_setting_context->nvram_sending_settings),
                        &(g_mmsv01_agent_setting_context->nvram_retrieval_settings));


    mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS);

    DeleteUptoScrID(SCR_ID_MMSV01_AGENT_MESSAGE_COMMON_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_exit_confirm_screen
 * DESCRIPTION
 *  exit from the confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_exit_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ///read back the auto sign content.Required because we are using the original auto sign buffer for input
    ///the auto sign content
    ReadRecord(
        NVRAM_EF_MMSV01_COMPOSE_SETTINGS_LID,
        1,
        &g_mmsv01_agent_setting_context->nvram_compose_settings,
        NVRAM_MMSV01_COMPOSE_SETTINGS_SIZE,
        &error);
    GoBacknHistory(1);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_read_back_auto_sign_content
 * DESCRIPTION
 *  Read the Compose setting from NVRAm for the auto sign content
 *  Read back is required because we are using the original auto sign buffer for input
 *  the auto sign content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_read_back_auto_sign_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_MMSV01_COMPOSE_SETTINGS_LID,
        1,
        &g_mmsv01_agent_setting_context->nvram_compose_settings,
        NVRAM_MMSV01_COMPOSE_SETTINGS_SIZE,
        &error);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_confirm_save_compose_settings
 * DESCRIPTION
 *  It checks for default slide time value and auto sign (on/Off). If deafult slide time
 *  input 0 then error pop up. If auto sign is on buyt content is empty then also error pop up.
 *  If more than 20 slide then also error pop up.Otherwise  ask confirmation to save compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_confirm_save_compose_settings(void)
{
 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp = 0;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
  
    /*Check for auto signature*/
    if ((g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.auto_signature == E_ON)
        &&
        (mmi_ucs2ncmp
         ((S8*) g_mmsv01_agent_setting_context->nvram_compose_settings.auto_signature_content, "\0",
          MMSV01_AGENT_MAX_AUTO_SIGN_LENGTH * ENCODING_LENGTH) == 0))
    {
        mmi_display_popup(
            (UI_string_type) GetString(STR_ID_MMSV01_AGENT_NO_CONTENT),
            MMI_EVENT_ERROR);
        return;
    }


   
    mmi_mmsv01_agent_display_confirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_SAVE_ASK),
            MMI_EVENT_QUERY);
 
   SetLeftSoftkeyFunction(mmi_mmsv01_save_compose_settings, KEY_EVENT_UP);
   SetRightSoftkeyFunction(mmi_mmsv01_exit_confirm_screen, KEY_EVENT_UP);
   
   SetDelScrnIDCallbackHandler(SCR_ID_MMSV01_AGENT_MESSAGE_COMPOSE_SETTINGS, (HistoryDelCBPtr) mmi_mmsv01_read_back_auto_sign_content);
}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_settings_highlight_hdlr
 * DESCRIPTION
 *  Highligh handler of retrieval settings screen items
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_compose_settings_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_compose_inline_custom_func
 * DESCRIPTION
 *  Highligh handler of retrieval settings screen items
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_compose_inline_custom_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
    SetInputMethodAndDoneCaptionIcon(GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID));
    SetDelScrnIDCallbackHandler(SCR_ID_MMSV01_AGENT_MESSAGE_COMPOSE_SETTINGS, (HistoryDelCBPtr)mmi_mmsv01_read_back_auto_sign_content);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_compose_fill_inline_struct
 * DESCRIPTION
 *  Fills the inline items for compose settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_compose_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmsv01_agent_setting_context->mmsv01_inline_lists == NULL)
    {
        g_mmsv01_agent_setting_context->mmsv01_inline_lists =
            (mmsV01_agent_common_inline_lists_struct*) OslMalloc(sizeof(mmsV01_agent_common_inline_lists_struct));
    }

    g_mmsv01_agent_setting_context->mmsv01_inline_lists->on_off_list[E_OFF] = GetString(STR_GLOBAL_OFF);
    g_mmsv01_agent_setting_context->mmsv01_inline_lists->on_off_list[E_ON] = GetString(STR_GLOBAL_ON);

    /*Creation Mode*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.creation_modes_list[MEA_CREATION_MODE_RESTRICTED] 
        = GetString(STR_ID_MMSV01_AGENT_CREATION_MODE_RESTRICTED);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.creation_modes_list[MEA_CREATION_MODE_WARNING] 
        = GetString(STR_ID_MMSV01_AGENT_CREATION_MODE_WARNING);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.creation_modes_list[MEA_CREATION_MODE_FREE] 
        = GetString(STR_ID_MMSV01_AGENT_CREATION_MODE_FREE);

    /*Image Resizing*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.image_resize_list[MEA_IMAGE_RESIZE_OFF] 
        = GetString(STR_GLOBAL_OFF);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.image_resize_list[MEA_IMAGE_RESIZE_160x120] 
        = GetString(STR_ID_MMSV01_AGENT_160x120);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.image_resize_list[MEA_IMAGE_RESIZE_320x240] 
        = GetString(STR_ID_MMSV01_AGENT_320x240);
#if !(defined(__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__) && (__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__ == __320x240__))
    g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.image_resize_list[MEA_IMAGE_RESIZE_640x480] 
        = GetString(STR_ID_MMSV01_AGENT_640x480);
#endif

    /* Creation Mode*/
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_CREATION_MODES_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_CREATION_MODES_CAPTION],
        (U8*) GetString(STR_ID_MMSV01_AGENT_CREATION_MODE));
    SetInlineItemSelect(
        &wgui_inline_items[E_COMPOSE_CREATION_MODES],
        MEA_CREATION_MODE_TOTAL,
        (U8 **) g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.creation_modes_list,
        (S32*)&g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.creation_mode);    
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_CREATION_MODES], 
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 
        0);

    /*Image Resizing*/
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_IMAGE_RESIZE_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_IMAGE_RESIZE_CAPTION],
        (U8*) GetString(STR_ID_MMSV01_AGENT_IMAGE_RESIZE));
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_IMAGE_RESIZING], 
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 
        0);
    SetInlineItemSelect(
        &wgui_inline_items[E_COMPOSE_IMAGE_RESIZING],
        MEA_IMAGE_RESIZE_TOTAL,
        (U8 **) g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.image_resize_list,
        &g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.image_resize_option);

    /*Best Page Time*/
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_BEST_PAGE_DURATION_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_BEST_PAGE_DURATION_CAPTION],
        (U8*) GetString(STR_ID_MMSV01_AGENT_BEST_SLIDE_DURATION));
    SetInlineItemSelect(
        &wgui_inline_items[E_COMPOSE_BEST_PAGE_DURATION],
        2,
        (U8 **) g_mmsv01_agent_setting_context->mmsv01_inline_lists->on_off_list,
        &g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.best_page_duration);
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_BEST_PAGE_DURATION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

     /*Auto signature*/
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE_CAPTION],
        (U8*) GetString(STR_ID_MMSV01_AGENT_AUTO_SIGNATURE));
    SetInlineItemSelect(
        &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE],
        2,
        (U8 **) g_mmsv01_agent_setting_context->mmsv01_inline_lists->on_off_list,
        &g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.auto_signature);
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE], 
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 
        0);

    /*Signature*/   
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE_CONTENT_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);  
     SetInlineItemCaption(
           &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE_CONTENT_CAPTION],
          (U8*) GetString(STR_ID_MMSV01_AGENT_SIGNATURE));
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE_CONTENT], 
        KEY_LSK, 
        KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE_CONTENT],
        STR_ID_MMSV01_AGENT_SIGNATURE,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        (PU8) g_mmsv01_agent_setting_context->nvram_compose_settings.auto_signature_content,
        MMSV01_AGENT_MAX_AUTO_SIGN_LENGTH + 1,
        IMM_INPUT_TYPE_SENTENCE);
    SetInlineFullScreenEditCustomFunction(
        &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE_CONTENT],
        mmi_mmsv01_compose_inline_custom_func);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_entry_compose_settings
 * DESCRIPTION
 *  This is entry fn for compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_entry_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *inputBuffer = NULL;     /* added for inline edit history */
    U16 inputBufferSize = 0;    /* added for inline edit history */
    U16 image_list[COMPOSE_INLINE_TOTAL] = {0};
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MMSV01_AGENT_MESSAGE_COMPOSE_SETTINGS, mmi_mmsv01_exit_compose_settings, NULL, NULL);

    set_leading_zero(FALSE);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MMSV01_AGENT_MESSAGE_COMPOSE_SETTINGS);

    InitializeCategory57Screen();

    mmi_mmsv01_compose_fill_inline_struct();
    //RegisterHighlightHandler(mmi_mmsv01_compose_settings_highlight_hdlr);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MMSV01_AGENT_MESSAGE_COMPOSE_SETTINGS);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_MMSV01_AGENT_MESSAGE_COMPOSE_SETTINGS, &inputBufferSize);  /* added for inline edit history */

    if (inputBuffer)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, COMPOSE_INLINE_TOTAL, inputBuffer);        /* sets the data */
    }

    image_list[E_COMPOSE_CREATION_MODES_CAPTION] = gIndexIconsImageList[count];
    image_list[E_COMPOSE_IMAGE_RESIZE_CAPTION] = gIndexIconsImageList[++count];
    image_list[E_COMPOSE_BEST_PAGE_DURATION_CAPTION] = gIndexIconsImageList[++count];
    image_list[E_COMPOSE_AUTO_SIGNATURE_CAPTION] = gIndexIconsImageList[++count];
    image_list[E_COMPOSE_AUTO_SIGNATURE_CONTENT_CAPTION] = gIndexIconsImageList[++count];
    

    ShowCategory57Screen(
        STR_ID_MMSV01_AGENT_CONFIG_COMPOSE,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        COMPOSE_INLINE_TOTAL,
        image_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_mmsv01_confirm_save_compose_settings, GoBackHistory);

    SetDelScrnIDCallbackHandler(SCR_ID_MMSV01_AGENT_MESSAGE_COMPOSE_SETTINGS, (HistoryDelCBPtr)mmi_mmsv01_read_back_auto_sign_content);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_pre_entry_compose_settings
 * DESCRIPTION
 *  this is pre entry fn for compose settings. Init the inline items for compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_pre_entry_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    
    g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.auto_signature =
        g_mmsv01_agent_setting_context->nvram_compose_settings.auto_signature;


    g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.best_page_duration =
        g_mmsv01_agent_setting_context->nvram_compose_settings.best_page_duration;

    g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.creation_mode =
        g_mmsv01_agent_setting_context->nvram_compose_settings.creation_mode;

    g_mmsv01_agent_setting_context->mmsv01_inline_items.compose_items_list.image_resize_option =
        g_mmsv01_agent_setting_context->nvram_compose_settings.image_resize_option;    

    mmi_mmsv01_entry_compose_settings();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_highlight_compose_setings
 * DESCRIPTION
 *  This function is the highlight handler of compose message settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_highlight_compose_setings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_mmsv01_pre_entry_compose_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_mmsv01_pre_entry_compose_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    

}



/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_entry_sending_settings
 * DESCRIPTION
 *  Entry fn for retrieval setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_entry_sending_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *inputBuffer = NULL;     /* added for inline edit history */
    U16 inputBufferSize = 0;    /* added for inline edit history */
    U16 image_list[SENDING_INLINE_TOTAL] = {0};
    U8 index = 0;
    U16 total_items = SENDING_INLINE_TOTAL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MMSV01_AGENT_MESSAGE_SENDING_SETTINGS, mmi_mmsv01_exit_sending_settings, NULL, NULL);

    set_leading_zero(FALSE);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MMSV01_AGENT_MESSAGE_SENDING_SETTINGS);

    InitializeCategory57Screen();

    mmi_mmsv01_sending_fill_inline_struct();

  //  RegisterHighlightHandler(mmi_mmsv01_sending_settings_highlight_hdlr);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MMSV01_AGENT_MESSAGE_SENDING_SETTINGS);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_MMSV01_AGENT_MESSAGE_SENDING_SETTINGS, &inputBufferSize);        /* added for inline edit history */

    if (inputBuffer)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, SENDING_INLINE_TOTAL, inputBuffer);      /* sets the data */
    }

    /*May need to chage the icon for sending*/

    
    image_list[E_SENDING_VALIDITY_PERIOD_CAPTION] = gIndexIconsImageList[index++];
    image_list[E_SENDING_DELIVERY_REPORT_CAPTION] = gIndexIconsImageList[index++];
    image_list[E_SENDING_READ_REPORT_CAPTION] = gIndexIconsImageList[index++];
    image_list[E_SENDING_PRIORITY_CAPTION] = gIndexIconsImageList[index++];
    image_list[E_SENDING_DEFAULT_SLIDE_TIME_CAPTION] = gIndexIconsImageList[index++];
    image_list[E_SENDING_DELIVERY_TIME_CAPTION] = gIndexIconsImageList[index++];
   
    ShowCategory57Screen(
        STR_ID_MMSV01_AGENT_CONFIG_SENDING,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        SENDING_INLINE_TOTAL,
        image_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_mmsv01_confirm_save_sending_settings, GoBackHistory);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_exit_sending_settings
 * DESCRIPTION
 *  Entry fn for retrieval setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_exit_sending_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
 
    GenericExitInlineScreen(SCR_ID_MMSV01_AGENT_MESSAGE_SENDING_SETTINGS, mmi_mmsv01_entry_sending_settings); /* added for inline edit history */

    if (g_mmsv01_agent_setting_context->mmsv01_inline_lists != NULL)
    {
        OslMfree(g_mmsv01_agent_setting_context->mmsv01_inline_lists );
        g_mmsv01_agent_setting_context->mmsv01_inline_lists = NULL;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_save_sending_settings
 * DESCRIPTION
 *  write the compose settings to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_save_sending_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S16 error = 0;
    U16 temp_slide_time_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    temp_slide_time_value = gui_atoi((UI_string_type) g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.defualt_slide_time_buffer);

    /*Check for slide timing*/
    if (temp_slide_time_value == 0)
    {
        mmi_display_popup(
            (UI_string_type) GetString(STR_ID_MMSV01_AGENT_CANT_INPUT_EMPTY_VALUE),
            MMI_EVENT_ERROR);
        return;
    }

    /*Slide Timing*/
    g_mmsv01_agent_setting_context->nvram_sending_settings.default_slide_time = (U32)temp_slide_time_value;        

    /*Validity Period*/
    g_mmsv01_agent_setting_context->nvram_sending_settings.validity_period = 
        g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.validity_period;

    /*Delivery Report*/
    g_mmsv01_agent_setting_context->nvram_sending_settings.delivery_report = 
        g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.delivery_report;

    /*Delivery Time*/
    g_mmsv01_agent_setting_context->nvram_sending_settings.delivery_time = 
        g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.delivery_time;

    /*Priority*/
    g_mmsv01_agent_setting_context->nvram_sending_settings.priority = 
        g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.priority;

    /*Read Report*/
    g_mmsv01_agent_setting_context->nvram_sending_settings.read_report = 
        g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.read_report;

    //g_mmsv01_agent_setting_context->nvram_sending_settings.send_and_save = (U8) E_OFF;  
    WriteRecord(
        NVRAM_EF_MMSV01_SENDING_SETTINGS_LID,
        1,
        &g_mmsv01_agent_setting_context->nvram_sending_settings,
        NVRAM_MMSV01_SENDING_SETTINGS_SIZE,
        &error);

    mmi_mmsv01_send_settings_data(MSG_ID_MEA_SET_SETTING_REQ,
                        &(g_mmsv01_agent_setting_context->nvram_compose_settings),
                        &(g_mmsv01_agent_setting_context->nvram_sending_settings),
                        &(g_mmsv01_agent_setting_context->nvram_retrieval_settings));


    mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS);
    DeleteUptoScrID(SCR_ID_MMSV01_AGENT_MESSAGE_COMMON_SETTINGS);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_sending_fill_inline_struct
 * DESCRIPTION
 *  Fills the inline items for retrieval settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_sending_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U16 retrieval_option = 0;

    if (g_mmsv01_agent_setting_context->mmsv01_inline_lists == NULL)
    {
        g_mmsv01_agent_setting_context->mmsv01_inline_lists =
            (mmsV01_agent_common_inline_lists_struct*) OslMalloc(sizeof(mmsV01_agent_common_inline_lists_struct));

    }

    /*validity period List*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.validity_period_list[MEA_EXPIRY_1_HOUR]
        = GetString(STR_ID_MMSV01_AGENT_CONFIG_1_HOUR);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.validity_period_list[MEA_EXPIRY_6_HOURS] 
        = GetString(STR_ID_MMSV01_AGENT_CONFIG_6_HOURS);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.validity_period_list[MEA_EXPIRY_12_HOURS] 
        = GetString(STR_ID_MMSV01_AGENT_CONFIG_12_HOURS);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.validity_period_list[MEA_EXPIRY_1_DAY] 
        = GetString(STR_ID_MMSV01_AGENT_CONFIG_1_DAY);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.validity_period_list[MEA_EXPIRY_1_WEEK] 
        = GetString(STR_ID_MMSV01_AGENT_CONFIG_1_WEEK);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.validity_period_list[MEA_EXPIRY_MAX] 
        = GetString(STR_ID_MMSV01_AGENT_CONFIG_MAX);

    /*Priority List*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.priority_list[MEA_PRIORITY_LOW] 
        = GetString(STR_ID_MMSV01_AGENT_CONFIG_LOW);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.priority_list[MEA_PRIORITY_NORMAL] 
        = GetString(STR_ID_MMSV01_AGENT_CONFIG_NORMAL);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.priority_list[MEA_PRIORITY_HIGH] 
        = GetString(STR_ID_MMSV01_AGENT_CONFIG_HIGH);

    /*Delivery Time list*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.delivery_time_list[MEA_DELIVERY_TIME_IMMEDIATE] 
        = GetString(STR_ID_MMSV01_AGENT_CONFIG_IMMEDIATE);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.delivery_time_list[MEA_DELIVERY_TIME_1_HOUR] 
        = GetString(STR_ID_MMSV01_AGENT_CONFIG_IN_ONE_HOUR);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.delivery_time_list[MEA_DELIVERY_TIME_12_HOURS] 
        = GetString(STR_ID_MMSV01_AGENT_CONFIG_IN_12_HOURS);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.delivery_time_list[MEA_DELIVERY_TIME_24_HOURS] 
        = GetString(STR_ID_MMSV01_AGENT_CONFIG_IN_24_HOURS);

    /*For read report/Delivery report*/
    g_mmsv01_agent_setting_context->mmsv01_inline_lists->on_off_list[0] = GetString(STR_GLOBAL_OFF);
    g_mmsv01_agent_setting_context->mmsv01_inline_lists->on_off_list[1] = GetString(STR_GLOBAL_ON);

    /*validity period*/
    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_VALIDITY_PERIOD_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_VALIDITY_PERIOD_CAPTION],
        (U8*) GetString(STR_ID_MMSV01_AGENT_CONFIG_VAL_PER));

    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_VALIDITY_PERIOD],
        MEA_EXPIRY_TOTAL,
        (U8 **) g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.validity_period_list,
        &g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.validity_period);
    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_VALIDITY_PERIOD],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    /*Delivery Report*/
    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_DELIVERY_REPORT_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_DELIVERY_REPORT_CAPTION],
        (U8*) GetString(STR_ID_MMSV01_AGENT_CONFIG_DR));
    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_DELIVERY_REPORT],
        2,
        (U8 **) g_mmsv01_agent_setting_context->mmsv01_inline_lists->on_off_list,
        &g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.delivery_report);
    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_DELIVERY_REPORT], 
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 
        0);

    /*Read report*/
    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_READ_REPORT_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_READ_REPORT_CAPTION],
        (U8*) GetString(STR_ID_MMSV01_AGENT_CONFIG_RR));
    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_READ_REPORT],
        2,
        (U8 **) g_mmsv01_agent_setting_context->mmsv01_inline_lists->on_off_list,
        &g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.read_report);
    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_READ_REPORT], 
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 
        0);
    /*Priority*/    
    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_PRIORITY_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_PRIORITY_CAPTION],
        (U8*) GetString(STR_ID_MMSV01_AGENT_CONFIG_PRIORITY));

    SetInlineItemSelect(&wgui_inline_items[E_SENDING_PRIORITY],
                        MEA_PRIORITY_TOTAL,
                        (U8 **) g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.priority_list,
                        &g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.priority);
    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_PRIORITY],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    /*Slide Time*/
    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_DEFAULT_SLIDE_TIME_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_DEFAULT_SLIDE_TIME_CAPTION],
        (U8*) GetString(STR_ID_MMSV01_AGENT_DURATION));

    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_DEFAULT_SLIDE_TIME],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemTextEdit(
        &wgui_inline_items[E_SENDING_DEFAULT_SLIDE_TIME],
        (U8*) g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.defualt_slide_time_buffer,
        (MMSV01_AGENT_MAX_DEFAULT_SLIDE_TIME_INPUT + 1),
        IMM_INPUT_TYPE_NUMERIC);

    /*Delivery Time*/

    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_DELIVERY_TIME_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_DELIVERY_TIME_CAPTION],
        (U8*) GetString(STR_ID_MMSV01_AGENT_DELIVERY_TIME));

    SetInlineItemSelect(&wgui_inline_items[E_SENDING_DELIVERY_TIME],
                        MEA_DELIVERY_TIME_TOTAL,
                        (U8 **) g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.delivery_time_list,
                        &g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.delivery_time);
    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_DELIVERY_TIME],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);


}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_confirm_save_sending_settings
 * DESCRIPTION
 *  Confirmation screen entry fn for saving retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_confirm_save_sending_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_slide_time_value = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    temp_slide_time_value = gui_atoi((UI_string_type) g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.defualt_slide_time_buffer);

    /*Check for slide timing*/
    if (temp_slide_time_value < MMSV01_AGENT_MIN_SLIDE_DURATION || temp_slide_time_value > MMSV01_AGENT_MAX_SLIDE_DURATION)
    {
        mmi_display_popup(
            (UI_string_type) GetString(STR_ID_MMSV01_AGENT_MIN_TIME_DURATION),
            MMI_EVENT_ERROR);
        return;
    }
    mmi_mmsv01_agent_display_confirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_SAVE_ASK),
            MMI_EVENT_QUERY);
 
    SetLeftSoftkeyFunction(mmi_mmsv01_save_sending_settings, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_mmsv01_exit_confirm_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_sending_settings_highlight_hdlr
 * DESCRIPTION
 *  Highligh handler of retrieval settings screen items
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
#ifdef __MMI_MMS_2_RETRIVAL_MODE_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MMS_2_RETRIVAL_MODE_SETTING__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_pre_entry_sending_settings
 * DESCRIPTION
 *  Pre Entry fn for retrieval setting screeen.It init the retreival inline items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_pre_entry_sending_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Slide Timing*/
    gui_itoa(
        (S32) g_mmsv01_agent_setting_context->nvram_sending_settings.default_slide_time,
        (UI_string_type) g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.defualt_slide_time_buffer,
        10);

    /*Validity period*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.validity_period =
        (S32) g_mmsv01_agent_setting_context->nvram_sending_settings.validity_period;

    /*Delivery Report*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.delivery_report =
        (S32) g_mmsv01_agent_setting_context->nvram_sending_settings.delivery_report;

    /*Read Report*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.read_report =
        (S32) g_mmsv01_agent_setting_context->nvram_sending_settings.read_report;

    /*Priority*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.priority =
        (S32) g_mmsv01_agent_setting_context->nvram_sending_settings.priority;

    /*Delivery Time*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.delivery_time =
        (S32) g_mmsv01_agent_setting_context->nvram_sending_settings.delivery_time;

    /*Save and Send*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.sending_items_list.send_and_save =
        (S32) g_mmsv01_agent_setting_context->nvram_sending_settings.send_and_save;


    mmi_mmsv01_entry_sending_settings();
}




/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_highlight_sending_setings
 * DESCRIPTION
 *  This function is the highlight handler of sending message settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_highlight_sending_setings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_mmsv01_pre_entry_sending_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_mmsv01_pre_entry_sending_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_exit_retrieval_settings
 * DESCRIPTION
 *  Exit fn for the retrieval setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_exit_retrieval_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
 
    GenericExitInlineScreen(SCR_ID_MMSV01_AGENT_MESSAGE_RETRIEVAL_SETTINGS, mmi_mmsv01_entry_retrieval_settings); /* added for inline edit history */

    if (g_mmsv01_agent_setting_context->mmsv01_inline_lists != NULL)
    {
        OslMfree(g_mmsv01_agent_setting_context->mmsv01_inline_lists );
        g_mmsv01_agent_setting_context->mmsv01_inline_lists = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_save_retrieval_settings
 * DESCRIPTION
 *  write the compose settings to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_save_retrieval_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S16 error = 0;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*Home Network*/
    g_mmsv01_agent_setting_context->nvram_retrieval_settings.home_network = 
        g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.home_network;

    /*Roaming*/
    g_mmsv01_agent_setting_context->nvram_retrieval_settings.roaming = 
        g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.roaming;

    /*Read Report*/
    g_mmsv01_agent_setting_context->nvram_retrieval_settings.read_report = 
        g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.read_report;

    /*Delivery report*/
    g_mmsv01_agent_setting_context->nvram_retrieval_settings.delivery_report =
        g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.delivery_report;
    
    WriteValue(NVRAM_MMSV01_RETRIEVAL_SETTINGS, &g_mmsv01_agent_setting_context->nvram_retrieval_settings, DS_DOUBLE, &error);

    mmi_mmsv01_send_settings_data(MSG_ID_MEA_SET_SETTING_REQ,
                            &(g_mmsv01_agent_setting_context->nvram_compose_settings),
                            &(g_mmsv01_agent_setting_context->nvram_sending_settings),
                            &(g_mmsv01_agent_setting_context->nvram_retrieval_settings));

    mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS);
    DeleteUptoScrID(SCR_ID_MMSV01_AGENT_MESSAGE_COMMON_SETTINGS);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_retrieval_fill_inline_struct
 * DESCRIPTION
 *  Fills the inline items for retrieval settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_retrieval_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U16 retrieval_option = 0;

    if (g_mmsv01_agent_setting_context->mmsv01_inline_lists == NULL)
    {
        g_mmsv01_agent_setting_context->mmsv01_inline_lists =
            (mmsV01_agent_common_inline_lists_struct*) OslMalloc(sizeof(mmsV01_agent_common_inline_lists_struct));

    }

    /*Home Network*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.home_network_list[MEA_RETRIEVAL_MODE_AUTOMATIC] = 
        GetString(STR_ID_MMSV01_AGENT_IM_RETRIEVAL);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.home_network_list[MEA_RETRIEVAL_MODE_ALWAYS_ASK] = 
        GetString(STR_ID_MMSV01_AGENT_CONFIG_DEL_RETRIEVAL);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.home_network_list[MEA_RETRIEVAL_MODE_RESTRICTED] = 
        GetString(STR_ID_MMSV01_AGENT_RES_RETRIEVAL_ROAM);

    /*Roaming*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.roaming_list[MEA_RETRIEVAL_MODE_ROAMING_AUTOMATIC] 
        = GetString(STR_ID_MMSV01_AGENT_AUTO_RETRIEVAL_ROAM);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.roaming_list[MEA_RETRIEVAL_MODE_ROAMING_ALWAYS_ASK] 
        = GetString(STR_ID_MMSV01_AGENT_ASK_RETRIEVAL_ROAM);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.roaming_list[MEA_RETRIEVAL_MODE_ROAMING_RESTRICTED] 
        = GetString(STR_ID_MMSV01_AGENT_RES_RETRIEVAL_ROAM);

    /*Read Report*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.read_report_list[MEA_SEND_READ_REPORT_ON_REQUEST] = 
        GetString(STR_ID_MMSV01_AGENT_CONFIG_ON_REQUEST);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.read_report_list[MEA_SEND_READ_REPORT_ALWAYS] = 
        GetString(STR_ID_MMSV01_AGENT_CONFIG_ALWAYS);
    g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.read_report_list[MEA_SEND_READ_REPORT_NEVER] = 
        GetString(MEA_STR_ID_CONFIG_NEVER);

    /*On Off List*/
    g_mmsv01_agent_setting_context->mmsv01_inline_lists->on_off_list[E_OFF] = GetString(STR_GLOBAL_OFF);
    g_mmsv01_agent_setting_context->mmsv01_inline_lists->on_off_list[E_ON] = GetString(STR_GLOBAL_ON);


    /*Home Network*/
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_HOME_NETWORK_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_RETRIEVAL_HOME_NETWORK_CAPTION],
        (U8*) GetString(STR_ID_MMSV01_AGENT_CONFIG_MSG_RETR_HOME_MODE));
    SetInlineItemSelect(
        &wgui_inline_items[E_RETRIEVAL_HOME_NETWORK],
        MEA_RETRIEVAL_MODE_TOTAL,
        (U8 **) g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.home_network_list,
        &g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.home_network);
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_HOME_NETWORK],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    /*Roaming*/
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_ROAMING_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_RETRIEVAL_ROAMING_CAPTION],
        (U8*) GetString(STR_ID_MMSV01_AGENT_CONFIG_MSG_RETR_ROAM_MODE));
    SetInlineItemSelect(
        &wgui_inline_items[E_RETRIEVAL_ROAMING],
        MEA_RETRIEVAL_MODE_ROAMING_TOTAL,
        (U8 **) g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.roaming_list,
        &g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.roaming);
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_ROAMING], 
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 
        0);

    /*Read Report*/    
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_READ_REPORT_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_RETRIEVAL_READ_REPORT_CAPTION],
        (U8*) GetString(STR_ID_MMSV01_AGENT_CONFIG_RR));
    SetInlineItemSelect(
        &wgui_inline_items[E_RETRIEVAL_READ_REPORT],
        MEA_SEND_READ_REPORT_TOTAL,
        (U8 **) g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.read_report_list,
        &g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.read_report);
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_READ_REPORT],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    /*Delivery report*/
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_DELIVERY_REPORT_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_RETRIEVAL_DELIVERY_REPORT_CAPTION],
        (U8*) GetString(STR_ID_MMSV01_AGENT_CONFIG_DR));
    SetInlineItemSelect(
        &wgui_inline_items[E_RETRIEVAL_DELIVERY_REPORT],
        E_ON_OFF_TOTAL,
        (U8 **) g_mmsv01_agent_setting_context->mmsv01_inline_lists->on_off_list,
        &g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.delivery_report);
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_DELIVERY_REPORT],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);


}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_confirm_save_retrieval_settings
 * DESCRIPTION
 *  Confirmation screen entry fn for saving retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_confirm_save_retrieval_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mmsv01_agent_display_confirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_SAVE_ASK),
            MMI_EVENT_QUERY);

    SetLeftSoftkeyFunction(mmi_mmsv01_save_retrieval_settings, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_mmsv01_exit_confirm_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_retrieval_settings_highlight_hdlr
 * DESCRIPTION
 *  Highligh handler of retrieval settings screen items
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_retrieval_settings_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
#ifdef __MMI_MMS_2_RETRIVAL_MODE_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MMS_2_RETRIVAL_MODE_SETTING__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_entry_retrieval_settings
 * DESCRIPTION
 *  Entry fn for retrieval setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_entry_retrieval_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *inputBuffer = NULL;     /* added for inline edit history */
    U16 inputBufferSize = 0;    /* added for inline edit history */
    U16 image_list[RETRIEVAL_INLINE_TOTAL] = {0};
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MMSV01_AGENT_MESSAGE_RETRIEVAL_SETTINGS, mmi_mmsv01_exit_retrieval_settings, NULL, NULL);

    set_leading_zero(FALSE);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MMSV01_AGENT_MESSAGE_RETRIEVAL_SETTINGS);

    InitializeCategory57Screen();

    mmi_mmsv01_retrieval_fill_inline_struct();

    //RegisterHighlightHandler(mmi_mmsv01_retrieval_settings_highlight_hdlr);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MMSV01_AGENT_MESSAGE_RETRIEVAL_SETTINGS);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_MMSV01_AGENT_MESSAGE_RETRIEVAL_SETTINGS, &inputBufferSize);        /* added for inline edit history */

    if (inputBuffer)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, RETRIEVAL_INLINE_TOTAL, inputBuffer);      /* sets the data */
    }
    
    image_list[E_RETRIEVAL_HOME_NETWORK_CAPTION] = gIndexIconsImageList[index++];
    image_list[E_RETRIEVAL_ROAMING_CAPTION] = gIndexIconsImageList[index++];    
    image_list[E_RETRIEVAL_READ_REPORT_CAPTION] = gIndexIconsImageList[index++];
    image_list[E_RETRIEVAL_DELIVERY_REPORT_CAPTION] = gIndexIconsImageList[index++];
   
    ShowCategory57Screen(
        STR_ID_MMSV01_AGENT_MSG_RETRIEVAL,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        RETRIEVAL_INLINE_TOTAL,
        image_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_mmsv01_confirm_save_retrieval_settings, GoBackHistory);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_pre_entry_retrieval_settings
 * DESCRIPTION
 *  Pre Entry fn for retrieval setting screeen.It init the retreival inline items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_pre_entry_retrieval_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*Home Network*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.home_network =
        (S32) g_mmsv01_agent_setting_context->nvram_retrieval_settings.home_network;

    /*Roaming*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.roaming =
        (S32) g_mmsv01_agent_setting_context->nvram_retrieval_settings.roaming;

    /*Read Report*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.read_report =
        (S32) g_mmsv01_agent_setting_context->nvram_retrieval_settings.read_report;

    /*Delivery report*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.retrieval_items_list.delivery_report =
        (S32) g_mmsv01_agent_setting_context->nvram_retrieval_settings.delivery_report;

    mmi_mmsv01_entry_retrieval_settings();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_highlight_retrieval_setings
 * DESCRIPTION
 *  This function is the highlight handler of retrieval message settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_highlight_retrieval_setings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_mmsv01_pre_entry_retrieval_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_mmsv01_pre_entry_retrieval_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_exit_filter_settings
 * DESCRIPTION
 *  Exit fn for the retrieval setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_exit_filter_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
 
    GenericExitInlineScreen(SCR_ID_MMSV01_AGENT_MESSAGE_RETRIEVAL_SETTINGS, mmi_mmsv01_entry_filter_settings); /* added for inline edit history */

    if (g_mmsv01_agent_setting_context->mmsv01_inline_lists != NULL)
    {
        OslMfree(g_mmsv01_agent_setting_context->mmsv01_inline_lists );
        g_mmsv01_agent_setting_context->mmsv01_inline_lists = NULL;
    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_save_filter_settings
 * DESCRIPTION
 *  write the compose settings to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_save_filter_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S16 error = 0;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*Home Network*/
    g_mmsv01_agent_setting_context->nvram_retrieval_settings.anonymous_filter = 
        g_mmsv01_agent_setting_context->mmsv01_inline_items.filter_items_list.anonymous_filter;

    /*Roaming*/
    g_mmsv01_agent_setting_context->nvram_retrieval_settings.advertisement_filter = 
        g_mmsv01_agent_setting_context->mmsv01_inline_items.filter_items_list.advertisement_filter;   
    
    WriteValue(NVRAM_MMSV01_RETRIEVAL_SETTINGS, &g_mmsv01_agent_setting_context->nvram_retrieval_settings, DS_DOUBLE, &error);

    mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS);
    DeleteUptoScrID(SCR_ID_MMSV01_AGENT_MESSAGE_COMMON_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_filter_fill_inline_struct
 * DESCRIPTION
 *  Fills the inline items for retrieval settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_filter_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U16 retrieval_option = 0;

    if (g_mmsv01_agent_setting_context->mmsv01_inline_lists == NULL)
    {
        g_mmsv01_agent_setting_context->mmsv01_inline_lists =
            (mmsV01_agent_common_inline_lists_struct*) OslMalloc(sizeof(mmsV01_agent_common_inline_lists_struct));

    }

    g_mmsv01_agent_setting_context->mmsv01_inline_lists->allow_reject_list[0] = GetString(STR_ID_MMSV01_AGENT_REJECT);
    g_mmsv01_agent_setting_context->mmsv01_inline_lists->allow_reject_list[1] = GetString(STR_ID_MMSV01_AGENT_ALLOW);

    /* anonymous_filter*/

    SetInlineItemActivation(
        &wgui_inline_items[E_FILTER_ANONYMOUS_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_FILTER_ANONYMOUS_CAPTION],
        (U8*) GetString(STR_ID_MMSV01_AGENT_CONFIG_ANONYM));

    SetInlineItemSelect(
        &wgui_inline_items[E_FILTER_ANONYMOUS],
        2,
        (U8 **) g_mmsv01_agent_setting_context->mmsv01_inline_lists->allow_reject_list,
        &g_mmsv01_agent_setting_context->mmsv01_inline_items.filter_items_list.anonymous_filter);
    SetInlineItemActivation(
        &wgui_inline_items[E_FILTER_ANONYMOUS],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    /*advertisement_filter*/
    SetInlineItemActivation(
        &wgui_inline_items[E_FILTER_ADVERTISEMENT_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_FILTER_ADVERTISEMENT_CAPTION],
        (U8*) GetString(STR_ID_MMSV01_AGENT_CONFIG_ADVERT));
    SetInlineItemSelect(
        &wgui_inline_items[E_FILTER_ADVERTISEMENT],
        2,
        (U8 **) g_mmsv01_agent_setting_context->mmsv01_inline_lists->allow_reject_list,
        &g_mmsv01_agent_setting_context->mmsv01_inline_items.filter_items_list.advertisement_filter);
    SetInlineItemActivation(
        &wgui_inline_items[E_FILTER_ADVERTISEMENT], 
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 
        0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_confirm_save_filter_settings
 * DESCRIPTION
 *  Confirmation screen entry fn for saving retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_confirm_save_filter_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mmsv01_agent_display_confirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_SAVE_ASK),
            MMI_EVENT_QUERY);

    SetLeftSoftkeyFunction(mmi_mmsv01_save_filter_settings, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_mmsv01_exit_confirm_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_filter_settings_highlight_hdlr
 * DESCRIPTION
 *  Highligh handler of retrieval settings screen items
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_filter_settings_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
#ifdef __MMI_MMS_2_RETRIVAL_MODE_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MMS_2_RETRIVAL_MODE_SETTING__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_entry_filter_settings
 * DESCRIPTION
 *  Entry fn for retrieval setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_entry_filter_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *inputBuffer = NULL;     /* added for inline edit history */
    U16 inputBufferSize = 0;    /* added for inline edit history */
    U16 image_list[FILTER_INLINE_TOTAL] = {0};
    U8 index = 0;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MMSV01_AGENT_MESSAGE_FILTER_SETTINGS, mmi_mmsv01_exit_filter_settings, NULL, NULL);

    set_leading_zero(FALSE);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MMSV01_AGENT_MESSAGE_FILTER_SETTINGS);

    InitializeCategory57Screen();

    mmi_mmsv01_filter_fill_inline_struct();

    RegisterHighlightHandler(mmi_mmsv01_filter_settings_highlight_hdlr);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MMSV01_AGENT_MESSAGE_FILTER_SETTINGS);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_MMSV01_AGENT_MESSAGE_FILTER_SETTINGS, &inputBufferSize);        /* added for inline edit history */

    if (inputBuffer)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, FILTER_INLINE_TOTAL, inputBuffer);      /* sets the data */
    }

    
    image_list[E_FILTER_ANONYMOUS_CAPTION] = gIndexIconsImageList[index++];
    image_list[E_FILTER_ADVERTISEMENT_CAPTION] = gIndexIconsImageList[index++];
   
    ShowCategory57Screen(
        STR_ID_MMSV01_AGENT_CONFIG_MSG_FILTERS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        FILTER_INLINE_TOTAL,
        image_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_mmsv01_confirm_save_filter_settings, GoBackHistory);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_pre_entry_retrieval_settings
 * DESCRIPTION
 *  Pre Entry fn for retrieval setting screeen.It init the retreival inline items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_pre_entry_filter_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmsv01_agent_setting_context->mmsv01_inline_items.filter_items_list.anonymous_filter =
        (S32) g_mmsv01_agent_setting_context->nvram_retrieval_settings.anonymous_filter;


    g_mmsv01_agent_setting_context->mmsv01_inline_items.filter_items_list.advertisement_filter =
        (S32) g_mmsv01_agent_setting_context->nvram_retrieval_settings.advertisement_filter;  


    mmi_mmsv01_entry_filter_settings();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_retrieval_setings
 * DESCRIPTION
 *  This function is the highlight handler of retrieval message settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_highlight_filter_setings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_mmsv01_pre_entry_filter_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_mmsv01_pre_entry_filter_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* SetKeyHandler(mmi_umms_pre_entry_retrieval_settings, KEY_WAP, KEY_EVENT_DOWN); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_entry_memory_status_screen
 * DESCRIPTION
 *  This function is entry function for memory status.
 * function is updated no need of request response and pre_entry so take the number and memory status based on API
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_entry_memory_status_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*) L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */
	memset(subMenuData, 0, sizeof(subMenuData));
    EntryNewScreen(SCR_ID_MMSV01_AGENT_MESSAGE_MEMORY_STATUS, NULL, mmi_mmsv01_entry_memory_status_screen, NULL);

    mea_mmsV01_agent_create_memory_status_text((kal_uint8*)subMenuData);
   
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MMSV01_AGENT_MESSAGE_MEMORY_STATUS);

    /*Rahul:- y we are using this?????????????????*/
    //SetMessagesCurrScrnID(SCR_ID_MMSV01_AGENT_MESSAGE_MEMORY_STATUS);
    //SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MMSV01_AGENT_MESSAGE_MEMORY_STATUS);

    ShowCategory7Screen(
        STR_GLOBAL_MEMORY_STATUS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) subMenuData,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_highlight_memory_status
 * DESCRIPTION
 *  This function is the highlight handler of retrieval message settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_highlight_memory_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_mmsv01_entry_memory_status_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_mmsv01_entry_memory_status_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* SetKeyHandler(mmi_umms_pre_entry_retrieval_settings, KEY_WAP, KEY_EVENT_DOWN); */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_set_profile_rsp_hdlr
 * DESCRIPTION
 *  This function is the highlight handler of retrieval message settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
void mmi_mmsv01_set_profile_rsp_hdlr(void *p)
{
    if (g_mmsv01_agent_setting_context->rsp_callback != NULL)
    {
        /*Need to do error handling*/
        g_mmsv01_agent_setting_context->rsp_callback(MMI_WAP_PROF_SUCCESS);
        g_mmsv01_agent_setting_context->rsp_callback = NULL;

    }
      

}
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_deinit_settings_ui
 * DESCRIPTION
 *  This function is used to deinit settings UI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/

void mmi_mmsv01_deinit_settings_ui(void)
{
    DeleteScreenIfPresent(SCR_ID_MMSV01_AGENT_MESSAGE_SETTINGS);
    DeleteScreenIfPresent(SCR_ID_MMSV01_AGENT_MESSAGE_COMMON_SETTINGS);
    DeleteScreenIfPresent(SCR_ID_MMSV01_AGENT_MESSAGE_SETTINGS_SIM_SELECTION);
    DeleteScreenIfPresent(SCR_ID_MMSV01_AGENT_MESSAGE_COMPOSE_SETTINGS);
    DeleteScreenIfPresent(SCR_ID_MMSV01_AGENT_MESSAGE_SENDING_SETTINGS);
    DeleteScreenIfPresent(SCR_ID_MMSV01_AGENT_MESSAGE_RETRIEVAL_SETTINGS);
    DeleteScreenIfPresent(SCR_ID_MMSV01_AGENT_MESSAGE_FILTER_SETTINGS);
    DeleteScreenIfPresent(SCR_ID_MMSV01_AGENT_MESSAGE_MEMORY_STATUS);
    mmi_wap_prof_kill_profile(MMI_WAP_PROF_APPID_MMS);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_get_creation_mode
 * DESCRIPTION
 *  This function is used to get the creation mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/

kal_uint8 mmi_mmsv01_get_creation_mode()
{
    return g_mmsv01_agent_setting_context->nvram_compose_settings.creation_mode;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_get_image_resize
 * DESCRIPTION
 *  This function is used to get the cimage resize value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/

kal_uint8 mmi_mmsv01_get_image_resize()
{
    return g_mmsv01_agent_setting_context->nvram_compose_settings.image_resize_option;
}


#endif