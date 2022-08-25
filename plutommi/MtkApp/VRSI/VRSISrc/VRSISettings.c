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
 * VRSISettings.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for settings of VRSI.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _MMI_VRSISETTINGS_C
#define _MMI_VRSISETTINGS_C

#ifdef __MTK_TARGET__

#if defined(__MMI_VRSI__)

/*  Include: MMI header file */
/* ... Add More MMI header */
#include "med_main.h"
#include "med_api.h"
#include "mdi_audio.h"
#include "VRSIType.h"
#include "VRSIProt.h"
#include "USBDeviceGprot.h"
#ifdef __SYNCML_SUPPORT__
#include "SyncMLGprot.h"
#endif /* __SYNCML_SUPPORT__ */ 

#if defined(__MMI_BT_SUPPORT__)
#include "BTMMISCOPathGprots.h"
#endif 
#include "BtcmSrvGprot.h"

#include "menucuigprot.h"

#include "mmi_rp_srv_vrsi_def.h"
#include "MMIDataType.h"
#include "FontRes.h"
#include "mmi_frm_nvram_gprot.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "MMI_features.h"
#include "AlertScreen.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "wgui_categories_list.h"
#include "kal_general_types.h"
#include "CommonScreensResDef.h"
#include "FileMgrSrvGProt.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "CustDataRes.h"
#include "mmi_rp_srv_syncml_def.h"
#include "Unicodexdcl.h"
#include "DebugInitDef_Int.h"
#include "MMI_media_app_trc.h"
#include "mmi_media_app_trc.h"
#include "GeneralDeviceGprot.h"
#include "wgui_categories_popup.h"
#include "nvram_common_defs.h"
#include "mmi_frm_history_gprot.h"
#include "string.h"
#include "wgui_categories_text_viewer.h"
#include "SSCStringTable.h"
#include "stdio.h"
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
#if defined (__MMI_VRSI_TRAIN_TAG__)
static BOOL g_vrsi_change_highlight;    /* Check if highlight changed during SD tag playing */
#endif 
//extern g_gid_vrsi;
/* 
 * Local Function
 */

static U8 mmi_vrsi_delscr_setting_menu_hdlr(void *param_p);
mmi_ret mmi_vrsi_settings_event_proc(mmi_event_struct *evt);

/* 
 * Global Variable
 */
extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;

/* 
 * Global Function
 */

#define MMI_VRSI_SETTING_MAIN


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_setting_init
 * DESCRIPTION
 *  init function for VRSI setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_setting_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read VRSI recognition value from NVRAM */
    ReadValue(NVRAM_VRSI_RCG_SETTING, &g_vrsi_cntx.rcg_enable, DS_BYTE, &pError);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_setting_menu
 * DESCRIPTION
 *  Highlight function for VRSI setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_setting_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_vrsi_setting_menu_pre_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_vrsi_setting_menu_pre_entry, KEY_EVENT_UP);
    }
}

static U8 mmi_vrsi_delscr_setting_menu_hdlr(void *param_p)
{    
#if defined(__MMI_BT_PROFILE__)    
      
#ifdef __MMI_BT_AUDIO_VIA_SCO__
        mmi_bt_sco_enable_sco_timeout();
#else
        mmi_bt_sco_disconnect_sco();
#endif
    
#endif   

    return 0;
}


mmi_ret mmi_vrsi_alert_cui(mmi_event_struct *evt)
{

    mmi_alert_result_evt_struct *confirm = (mmi_alert_result_evt_struct *)evt;
    kal_prompt_trace(MOD_MMI, "[VR] mmi_vrsi_alert_cui settings result = %d, alert_id = %d",confirm->result, confirm->alert_id);
    switch (confirm->result)
    {
        case MMI_POPUP_INTERRUPT_EXIT:
        case MMI_ALERT_NORMAL_EXIT:
        {
            break;
        }
        case MMI_ALERT_CNFM_OK:  
        case MMI_ALERT_CNFM_YES:   
            {      
                switch ((S32)confirm->user_tag)
                {
                    default:
                    {
                        ((FuncPtr)confirm->user_tag)();
                        break;
                    }
                }
            }
            break; 
        case MMI_ALERT_CNFM_NO:         
        case MMI_ALERT_CNFM_CANCEL: 
            {
                switch ((S32)confirm->user_tag)
                {
                    default:
                    {
                        mmi_alert_dismiss(confirm->alert_id);
                        break;
                    }
                }
                break;
            }
        default:
            break;
    }
    return MMI_RET_OK;
}

mmi_ret mmi_vrsi_settings_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "[vr]mmi_vrsi_settings_event_proc evt->id = %d, menu_id = %d",evt->evt_id,menu_evt->highlighted_menu_id );
    switch (evt->evt_id)
    {
/*************************Menu CUI event***************************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:            
            if(menu_evt->parent_menu_id == MENU_ID_VRSI_SETTING_MAIN)
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            }
            else if(menu_evt->parent_menu_id == MENU_ID_VRSI_TRAIN_OPTION_MAIN)
            {
                if((*(U32*)(menu_evt->app_data)) == 1)/* add */
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_VRSI_TRAIN_OPTION_ADD, MMI_FALSE);
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_VRSI_TRAIN_OPTION_DEL, MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_VRSI_TRAIN_OPTION_PLAY, MMI_TRUE);
                }
                else if(*(U32*)(menu_evt->app_data) == 2) /* del */
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_VRSI_TRAIN_OPTION_ADD, MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_VRSI_TRAIN_OPTION_DEL, MMI_FALSE);
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_VRSI_TRAIN_OPTION_PLAY, MMI_FALSE);
                }     
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            }
            else if(menu_evt->parent_menu_id == MENU_ID_VRSI_SETTING_TRAIN_TAG)
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            }
            break;
            
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            if(menu_evt->parent_menu_id == MENU_ID_VRSI_SETTING_MAIN)
            {
                if(menu_evt->highlighted_menu_id == MENU_ID_VRSI_SETTING_RCG)
                {                   
                    if (g_vrsi_cntx.rcg_enable)
                    {
                        cui_menu_set_item_hint(menu_evt->sender_id,MENU_ID_VRSI_SETTING_RCG,get_string(STR_GLOBAL_ON));
                        cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_OFF));
                    }
                    else
                    {
                        cui_menu_set_item_hint(menu_evt->sender_id,MENU_ID_VRSI_SETTING_RCG,get_string(STR_GLOBAL_OFF));
                        cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_ON));
                    }
                }                
            }
            break;           

        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
            
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            mmi_vrsi_delscr_setting_menu_hdlr(NULL);
            cui_menu_close(menu_evt->sender_id);
            break;
            
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            
            if (menu_evt->parent_menu_id == MENU_ID_VRSI_SETTING_MAIN)
            {
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_VRSI_SETTING_RCG:
                       mmi_vrsi_rcg_enable_toggle();
                       break;
                    case MENU_ID_VRSI_SETTING_TRAIN_TAG:
                       mmi_vrsi_entry_train_tag_main();
                       break;
                    case MENU_ID_VRSI_SETTING_DIGIT_ADAPT:
                        mmi_vrsi_digit_adapt_init();
                        break;
                }
            }
            else if(menu_evt->parent_menu_id == MENU_ID_VRSI_SETTING_TRAIN_TAG)
            {
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_VRSI_TRAIN_NAME_LIST:
                        mmi_vrsi_ndial_train_list_pre_entry();
                        break;
                    case MENU_ID_VRSI_TRAIN_SHORTCUT_LIST:
                        mmi_vrsi_entry_scut_list();
                        break;
		            case MENU_ID_VRSI_TRAIN_CITY_LIST:
                        mmi_vrsi_entry_city_list();
                        break;
                    case MENU_ID_VRSI_TRAIN_DELETE_ALL:
                        mmi_vrsi_entry_train_delele_all_confirm();
                        break;
                    case MENU_ID_VRSI_TRAIN_TAG_STATUS:
                        mmi_vrsi_entry_train_status();
                        break;
                }
            } 
            else if(menu_evt->parent_menu_id == MENU_ID_VRSI_TRAIN_OPTION_MAIN)
            {
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_VRSI_TRAIN_OPTION_ADD:
                        mmi_vrsi_train_option_pre_add();
                        break;
                    case MENU_ID_VRSI_TRAIN_OPTION_DEL:
                        mmi_vrsi_train_option_delete_confirm();
                        break;
                     case MENU_ID_VRSI_TRAIN_OPTION_PLAY:
                        mmi_vrsi_train_option_pre_playback();
                        break;
                }
            }
            break;  
/**********************Alert CUI event*************************/
        case EVT_ID_ALERT_QUIT:
            return mmi_vrsi_alert_cui(evt);
            break;                
/**********************FS event*************************/
        case EVT_ID_SRV_FMGR_ASYNC_DONE:
        {            
            break;
        }
        
        
        default:
            break;
    }    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_setting_menu_callback
 * DESCRIPTION
 *  Entry function for VRSI setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vrsi_setting_menu_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Callback by init function, so close engine */

    mmi_vrsi_rcg_close();
    mmi_frm_group_create(GRP_ID_VRSI, GRP_ID_VRSI_SETTING_MENU, mmi_vrsi_settings_event_proc, (void*)NULL); 

    mmi_frm_group_enter(GRP_ID_VRSI_SETTING_MENU, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_gid = cui_menu_create(
                        GRP_ID_VRSI_SETTING_MENU,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_APPSUB,
                        MENU_ID_VRSI_SETTING_MAIN,
                        MMI_FALSE, NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
       cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_VRSI_SETTING)));
 //       cui_menu_set_default_title(cui_gid,(UI_string_type),UI_image_type img);
        cui_menu_run(cui_gid);
    }
    else
    {   
        mmi_popup_display_simple((UI_string_type)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE,GRP_ID_VRSI, 0);
    }

#if defined(__MMI_BT_PROFILE__)
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
 *  mmi_vrsi_setting_menu_pre_entry
 * DESCRIPTION
 *  Pre Entry function for VRSI setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_setting_menu_pre_entry(void)
{

    mmi_vrsi_entry_setting_menu();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_setting_menu
 * DESCRIPTION
 *  Entry function for VRSI setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_setting_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if in USB mode before enter setting */
    if (!mmi_frm_group_is_present(GRP_ID_VRSI))
    {
        mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_VRSI, mmi_vrsi_settings_event_proc, NULL);
        mmi_frm_group_enter(GRP_ID_VRSI, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    /* Check if in USB mode before enter setting */
#if defined(__USB_IN_NORMAL_MODE__)
    if (mmi_usb_is_in_mass_storage_mode())
    {
        MMI_STR_ID string_id = 0;
        mmi_event_notify_enum event_type = 0;
        string_id = mmi_usb_get_error_info(MMI_USB_ERR_IS_UNAVAILABLE, &event_type);
        mmi_popup_display_simple((UI_string_type)GetString(string_id), event_type,GRP_ID_VRSI,0);
        return;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

#if defined(__MMI_BACKGROUND_CALL__)
     if (srv_ucm_is_background_call())
     {
        MMI_STR_ID string_id = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL;
        mmi_popup_display_simple((UI_string_type)GetString(string_id), MMI_EVENT_FAILURE,GRP_ID_VRSI,0);
            return;
     }
#endif

#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_phb_sync_now())
    {
    	//progress        
        mmi_popup_display_simple((UI_string_type)GetString(STR_ID_SYNC_PLEASE_WAIT), MMI_EVENT_PROGRESS,GRP_ID_VRSI,0);
       
        return;
    }
#endif /* __SYNCML_SUPPORT__ */ 

    /* Call init function to sync tag for first time use. */
    mmi_vrsi_rcg_init(mmi_vrsi_setting_menu_callback);

}

#define MMI_VRSI_SETTING_RCG_ENABLE


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_rcg_enable
 * DESCRIPTION
 *  Highlight function for VRSI setting menu option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_rcg_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_cntx.rcg_enable)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }
   // SetLeftSoftkeyFunction(mmi_vrsi_rcg_enable_toggle, KEY_EVENT_UP);
   // SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_hint_rcg_enable
 * DESCRIPTION
 *  Hint function for VRSI setting menu option
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_hint_rcg_enable(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_cntx.rcg_enable)
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_OFF));
    }
}


void mmi_vrsi_dummy_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_scrn_enter(GRP_ID_VRSI, GLOBAL_SCR_DUMMY, NULL, mmi_vrsi_dummy_function, MMI_FRM_FG_ONLY_SCRN))
    {
        mmi_frm_scrn_close(GRP_ID_VRSI, GLOBAL_SCR_DUMMY);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_rcg_enable_toggle
 * DESCRIPTION
 *  toggle VRSI recognition enable/disable settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_rcg_enable_toggle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 index;
    U16 str_LSK = STR_GLOBAL_OFF, str_hint = STR_GLOBAL_ON;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI,"[vr]mmi_vrsi_rcg_enable_toggle");
    //index = GetCurrHiliteID();

    if (g_vrsi_cntx.rcg_enable)
    {
        g_vrsi_cntx.rcg_enable = 0;
        str_LSK = STR_GLOBAL_ON;
        str_hint = STR_GLOBAL_OFF;
    }
    else
    {
        g_vrsi_cntx.rcg_enable = 1;
    }

    if(mmi_frm_scrn_enter(GRP_ID_VRSI, GLOBAL_SCR_DUMMY, NULL, mmi_vrsi_dummy_function, MMI_FRM_FG_ONLY_SCRN))
    {
    mmi_frm_scrn_close(GRP_ID_VRSI, GLOBAL_SCR_DUMMY);
    }
    /* Write Back To NVRAM */
    WriteValue(NVRAM_VRSI_RCG_SETTING, &g_vrsi_cntx.rcg_enable, DS_BYTE, &pError);

    /* DisplayPopup((U8*)GetString(str_hint), IMG_GLOBAL_ACTIVATED,  TRUE, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE); */
}


#define MMI_VRSI_TRAIN_TAG
#if defined(__MMI_VRSI_TRAIN_TAG__)
#define MMI_VRSI_TRAIN_TAG_MAIN


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_tag
 * DESCRIPTION
 *  Highlight function for VRSI setting menu option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

//    SetLeftSoftkeyFunction(mmi_vrsi_entry_train_tag_main, KEY_EVENT_UP);
 //   SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

 //   SetKeyHandler(mmi_vrsi_entry_train_tag_main, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
 //   SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_name_list
 * DESCRIPTION
 *  Highlight function for VRSI train SD tag option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_name_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // SetLeftSoftkeyFunction(mmi_vrsi_ndial_train_list_pre_entry, KEY_EVENT_UP);
   // SetKeyHandler(mmi_vrsi_ndial_train_list_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_shortcut_list
 * DESCRIPTION
 *  Highlight function for VRSI train SD tag option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_shortcut_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  SetLeftSoftkeyFunction(mmi_vrsi_entry_scut_list, KEY_EVENT_UP);
 //   SetKeyHandler(mmi_vrsi_entry_scut_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_city_list
 * DESCRIPTION
 *  Highlight function for VRSI train SD tag option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_city_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vrsi_entry_city_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_vrsi_entry_city_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_delete_all
 * DESCRIPTION
 *  Highlight function for VRSI train SD tag option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  SetLeftSoftkeyFunction(mmi_vrsi_entry_train_delele_all_confirm, KEY_EVENT_UP);
//    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_tag_status
 * DESCRIPTION
 *  Highlight function for VRSI train SD tag option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_tag_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 //   SetLeftSoftkeyFunction(mmi_vrsi_entry_train_status, KEY_EVENT_UP);
//    SetKeyHandler(mmi_vrsi_entry_train_status, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_train_tag_main
 * DESCRIPTION
 *  Entry train SD tag main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_train_tag_main(void)
{
    MMI_ID cui_gid;

    mmi_vrsi_rcg_close();
    kal_prompt_trace(MOD_MMI, "mmi_vrsi_entry_train_tag_main");
    mmi_frm_group_create(GRP_ID_VRSI_SETTING_MENU, GRP_ID_VRSI_TRAIN_TAG_MAIN, mmi_vrsi_settings_event_proc, (void*)NULL); 

    mmi_frm_group_enter(GRP_ID_VRSI_TRAIN_TAG_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_gid = cui_menu_create(
                        GRP_ID_VRSI_TRAIN_TAG_MAIN,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_APPSUB,
                        MENU_ID_VRSI_SETTING_TRAIN_TAG,
                        MMI_FALSE, NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_VRSI_SETTING)));
        cui_menu_run(cui_gid);
    }
    else
    {   
        mmi_popup_display_simple((UI_string_type)STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE,GRP_ID_VRSI,0);
    }
}

#define MMI_VRSI_TRAIN_TAG_LIST


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_option_add
 * DESCRIPTION
 *  Highlight function for VRSI train tag option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_option_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 //  g_vrsi_change_highlight = TRUE;

    
 //   ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
 //   SetLeftSoftkeyFunction(mmi_vrsi_train_option_pre_add, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_option_del
 * DESCRIPTION
 *  Highlight function for VRSI train tag option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_option_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 //  g_vrsi_change_highlight = TRUE;

//   ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
 //   SetLeftSoftkeyFunction(mmi_vrsi_train_option_delete_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_option_playback
 * DESCRIPTION
 *  Highlight function for VRSI train tag option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_option_playback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    g_vrsi_change_highlight = TRUE;

 //   ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
 //   SetLeftSoftkeyFunction(mmi_vrsi_train_option_pre_playback, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_train_option_add
 * DESCRIPTION
 *  Pre entry function for VRSI train tag option, it will display add option only
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_train_option_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_entry_train_option(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_train_option_del
 * DESCRIPTION
 *  Pre entry function for VRSI train tag option, it will display delete ad playback option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_train_option_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_entry_train_option(2);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_train_option
 * DESCRIPTION
 *  This is the option list for train VRSI tag
 * PARAMETERS
 *  type        [IN]        1: add 2: delete/playback
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_train_option(U8 type)
{
    MMI_ID cui_gid;

    kal_prompt_trace(MOD_MMI, "mmi_vrsi_entry_train_option type = %d", type);
    mmi_vrsi_rcg_close();
    mmi_frm_group_create(GRP_ID_VRSI, GRP_ID_VRSI_TRAIN_OPTION_MAIN, mmi_vrsi_settings_event_proc, (void*)NULL); 

    mmi_frm_group_enter(GRP_ID_VRSI_TRAIN_OPTION_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_gid = cui_menu_create(
                        GRP_ID_VRSI_TRAIN_OPTION_MAIN,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_OPTION,
                        MENU_ID_VRSI_TRAIN_OPTION_MAIN,
                        MMI_FALSE, (void*)&type);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_VRSI_SETTING)));
        cui_menu_run(cui_gid);
    }
    else
    {
        mmi_popup_display_simple((UI_string_type)STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE,GRP_ID_VRSI,0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_train_option
 * DESCRIPTION
 *  This is the exit function for option list for train VRSI tag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_train_option(void)
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
    if (scr_id == SCR_ID_VRSI_TRAIN_OPTION_ADD_PROMPT)
    {
#if defined(__MMI_BT_PROFILE__)
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
        return;
    }
    else
    {
        mmi_vrsi_rcg_close();
#if defined(__MMI_BT_PROFILE__)
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
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_option_pre_add
 * DESCRIPTION
 *  Get free SD tag mapping slot before training
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_pre_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tag_pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get free Tag */
#if defined(__MMI_BACKGROUND_CALL__)
        if (srv_ucm_is_background_call())
        {
        MMI_STR_ID string_id = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL;
        mmi_popup_display_simple((UI_string_type)get_string(string_id), MMI_EVENT_FAILURE,GRP_ID_VRSI,0);
            return;
        }
#endif
    tag_pos = mmi_vrsi_train_util_get_id_and_loc(MMI_VRSI_APP_NONE, 0xffff, NULL);

    if (tag_pos != 0xff)
    {
        g_vrsi_cntx.curr_tag = tag_pos;
        mmi_vrsi_rcg_init(mmi_vrsi_train_option_add_start);
    }
    else
    {
    	//failure
        mmi_popup_display_simple((UI_string_type)GetString(STR_ID_VRSI_SD_TAG_FULL), MMI_EVENT_FAILURE,GRP_ID_VRSI,NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_option_add_start
 * DESCRIPTION
 *  Start traing tag function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_add_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Start Digit Adaptation */
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
    {
        g_vrsi_cntx.session_id = mdi_audio_vrsi_new_session_id();

        result = media_aud_vrsi_start_cmd_trn(
                    MOD_MMI,
                    g_vrsi_cntx.session_id,
                    (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1],
                    g_vrsi_cntx.long_name_ptr,
                    g_vrsi_cntx.long_list[0]);

        MMI_TRACE(
            MMI_MEDIA_TRC_G2_APP,
            MMI_VRSI_FUNC_TRAIN_ADD_START,
            result,
            g_vrsi_cntx.session_id,
            g_vrsi_cntx.long_list[0]);

        if (result == MED_RES_OK)
        {
            return;
        }
        else
        {
            mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);
            mdi_audio_vrsi_close();
            g_vrsi_cntx.vrsi_state = MMI_VRSI_STATE_IDLE;
        }
    }

  	mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE,GRP_ID_VRSI,NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_train_option_add_prompt
 * DESCRIPTION
 *  Entry train SD tag prompt message screen.
 * PARAMETERS
 *  prompt      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_train_option_add_prompt(U8 prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);
    kal_prompt_trace(MOD_MMI, "mmi_vrsi_entry_train_option_add_prompt prompt = %d", prompt);
    if (prompt == 1)
    {
        str_id = STR_ID_VRSI_TRAIN_TAG_PROMPT1;
    }
    else    /* prompt == 2 */
    {
        str_id = STR_ID_VRSI_TRAIN_TAG_PROMPT2;
    }

    mdi_audio_suspend_background_play();
    entry_ret = mmi_frm_scrn_enter(
              GRP_ID_VRSI_TRAIN_OPTION_MAIN, 
              SCR_ID_VRSI_TRAIN_OPTION_ADD_PROMPT, 
              mmi_vrsi_exit_train_option_add_prompt, 
              NULL, 
              MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    } 

    ShowCategory8Screen(
        STR_ID_VRSI_APP,
        GetRootTitleIcon(MENU_ID_VRSI_SETTING),
        0,                      /* LSK STR */
        0,                      /* LSK IMG */
        STR_GLOBAL_CANCEL,      /* RSK STR */
        0,                      /* RSK IMG */
        str_id,                 /* message id */
        IMG_GLOBAL_INFO,    /* icon id */
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
#if defined(__MMI_BT_PROFILE__)
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

    /* Play Prompt Tone and send confirm after prompt */
    mmi_vrsi_rcg_play_prompt_tone();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_train_option_add_prompt
 * DESCRIPTION
 *  Exit train SD tag prompt message screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_train_option_add_prompt(void)
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
    if (scr_id == SCR_ID_VRSI_TRAIN_OPTION_ADD_PROMPT)
    {
#if defined(__MMI_BT_PROFILE__)
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
        return;
    }
    else
    {
        mmi_vrsi_rcg_close();
#if defined(__MMI_BT_PROFILE__)
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
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_option_add_result
 * DESCRIPTION
 *  Train success, write result to mapping table
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_add_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Retrieve data from NVRAM */
    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    tag_list[g_vrsi_cntx.curr_tag].tag_long = g_vrsi_cntx.long_list[0];
    tag_list[g_vrsi_cntx.curr_tag].tag_id = media_aud_vrsi_read_cmd_trn_result();
    tag_list[g_vrsi_cntx.curr_tag].app_id = g_vrsi_cntx.curr_app;

    MMI_TRACE(
        MMI_MEDIA_TRC_G2_APP,
        MMI_VRSI_FUNC_TRAIN_ADD_RESULT,
        g_vrsi_cntx.curr_tag,
        tag_list[g_vrsi_cntx.curr_tag].app_id,
        tag_list[g_vrsi_cntx.curr_tag].tag_long,
        tag_list[g_vrsi_cntx.curr_tag].tag_id);

    /* Save result to NVRAM */
    WriteRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    	//success
    mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_DONE),MMI_EVENT_SUCCESS, GRP_ID_VRSI, 0);
    //mmi_frm_group_close(GRP_ID_VRSI_TRAIN_OPTION_MAIN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_option_delete_confirm
 * DESCRIPTION
 *  Delete SD tag confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_delete_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id;
    mmi_confirm_property_struct property;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_vrsi_train_util_get_id_and_loc(g_vrsi_cntx.curr_app, g_vrsi_cntx.long_list[0], &tag_id) == 0xFF)
    {
        /* Delete tag in mapping table */
        mmi_vrsi_train_util_del_tag(g_vrsi_cntx.curr_app, g_vrsi_cntx.long_list[0]);        	
        mmi_popup_display_simple(
			(UI_string_type)GetString(STR_GLOBAL_EMPTY),
			MMI_EVENT_FAILURE, GRP_ID_VRSI,0);
        DeleteNScrId(SCR_ID_VRSI_TRAIN_OPTION_MAIN);  
        return;
    }
    kal_prompt_trace(MOD_MMI, "mmi_vrsi_train_option_delete_confirm");
    mmi_confirm_property_init(&property, CNFM_TYPE_YESNO);
    property.parent_id = GRP_ID_VRSI_TRAIN_OPTION_MAIN;
    property.user_tag = (void*)mmi_vrsi_train_option_pre_delete_tag;
    mmi_confirm_display((UI_string_type)GetString(STR_ID_VRSI_DELETE_QUESTION), MMI_EVENT_QUERY, &property);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_option_pre_delete_tag
 * DESCRIPTION
 *  Delete SD tag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_pre_delete_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "mmi_vrsi_train_option_pre_delete_tag");
    /* System busy */
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
    {
    	//failure
    	mmi_popup_display_simple((UI_string_type)GetString(STR_ID_VRSI_BUSY),MMI_EVENT_FAILURE,GRP_ID_VRSI, NULL);
        return;
    }

    /* Init VR engine for delete sd tag */
    mmi_vrsi_rcg_init(mmi_vrsi_train_option_delete_tag);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_option_delete_tag
 * DESCRIPTION
 *  Delete SD tag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_delete_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id[1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* VR should already in running state. */
    if (g_vrsi_cntx.vrsi_state != MMI_VRSI_STATE_RUNNING)
    {
    	//failure
    	mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_ERROR),MMI_EVENT_FAILURE,GRP_ID_VRSI, NULL);
    }

    /* get SD tag id mapping. */
    mmi_vrsi_train_util_get_id_and_loc(g_vrsi_cntx.curr_app, g_vrsi_cntx.long_list[0], &tag_id[0]);

    media_aud_vrsi_del_tags(MOD_MMI, (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1], 1, tag_id);

    mmi_vrsi_rcg_close();
#if defined(__MMI_BT_PROFILE__)
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

    /* Delete tag in mapping table */
    mmi_vrsi_train_util_del_tag(g_vrsi_cntx.curr_app, g_vrsi_cntx.long_list[0]);
    	//success

  	mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_DELETED),MMI_EVENT_SUCCESS,GRP_ID_VRSI, NULL);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_option_pre_playback
 * DESCRIPTION
 *  Pre-check state for playback SD tag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_pre_playback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "mmi_vrsi_train_option_pre_playback");
    /* System busy */
#if defined(__MMI_BACKGROUND_CALL__)
        if (srv_ucm_is_background_call())
        {
            MMI_STR_ID string_id = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL;
            mmi_popup_display_simple((UI_string_type)get_string(string_id), MMI_EVENT_FAILURE,GRP_ID_VRSI,0);
            return;
        }
#endif
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
    {
    	//failure
    	mmi_popup_display_simple((UI_string_type)GetString(STR_ID_VRSI_BUSY), MMI_EVENT_FAILURE, GRP_ID_VRSI, 0);
        return;
    }

    /* indicate that the tag wasn't found*/
    if (mmi_vrsi_train_util_get_id_and_loc(g_vrsi_cntx.curr_app, g_vrsi_cntx.long_list[0], &tag_id) == 0xFF)   
    {
        mmi_vrsi_train_util_del_tag(g_vrsi_cntx.curr_app, g_vrsi_cntx.long_list[0]);
        mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE,GRP_ID_VRSI, 0);
        
        mmi_frm_group_close(GRP_ID_VRSI_TRAIN_OPTION_MAIN);
        return;
    }
    /* Init VR engine for playback */
    mmi_vrsi_rcg_init(mmi_vrsi_train_option_playback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_option_playback
 * DESCRIPTION
 *  Playback SD tag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_playback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    MMI_ID scr_id;
    MMI_ID group_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "mmi_vrsi_train_option_playback");
    /* VR should already in running state. */
    if (g_vrsi_cntx.vrsi_state != MMI_VRSI_STATE_RUNNING)
    {
    	//failure
    	mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_ERROR),MMI_EVENT_FAILURE,GRP_ID_VRSI, NULL);
    }
    // to do check
    /* If it is in first time initialize screen, go back to option menu */
    mmi_frm_get_active_scrn_id(&group_id, &scr_id);
  //  if (scr_id == SCR_ID_VRSI_INIT_PROCESSING)
    {
        mmi_frm_group_close(GRP_ID_VRSI_TRAIN_OPTION_MAIN);
    }

    /* get SD tag id mapping and playback. */
    result = mmi_vrsi_util_play_tag(
                MMI_VRSI_GRAMMAR_1,
                g_vrsi_cntx.curr_app,
                g_vrsi_cntx.long_list[0],
                mmi_vrsi_train_option_playback_finish);

    if (result == MED_RES_OK)
    {
        /* avoid user continue pressing */
//        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
 //       ClearKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
  //      ClearKeyHandler(KEY_CSK, KEY_EVENT_DOWN);
        g_vrsi_change_highlight = FALSE;
        return;
    }
    else if (result == MED_RES_VRSI_ERR_NO_MATCH_TAG)   /* Tag not in engine, delete tag mapping */
    {
        mmi_vrsi_train_util_del_tag(g_vrsi_cntx.curr_app, g_vrsi_cntx.long_list[0]);
        	//failure
        mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_EMPTY),MMI_EVENT_FAILURE,GRP_ID_VRSI, NULL);
        
        mmi_frm_group_close(GRP_ID_VRSI_TRAIN_OPTION_MAIN);
    }

    mmi_vrsi_rcg_close();
#if defined(__MMI_BT_PROFILE__)
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
 *  mmi_vrsi_train_option_playback_finish
 * DESCRIPTION
 *  Call back function when play SD tag finish
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_playback_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_vrsi_change_highlight)
    {
  //      mmi_vrsi_highlight_train_option_playback();
    }
  //  mmi_frm_group_close(GRP_ID_VRSI_TRAIN_OPTION_MAIN);
    mmi_vrsi_rcg_close();
#if defined(__MMI_BT_PROFILE__)
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

#define MMI_VRSI_TRAIN_TAG_DELETE_ALL


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_train_delele_all_confirm
 * DESCRIPTION
 *  Confirm delete all screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_train_delele_all_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count_list[MMI_VRSI_APP_TOTAL];
    mmi_confirm_property_struct property;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_train_util_get_tag_count(count_list);

    if (count_list[MMI_VRSI_APP_ALL] > 0)
    {
        mmi_confirm_property_init(&property, CNFM_TYPE_YESNO);
        property.parent_id = GRP_ID_VRSI_TRAIN_TAG_MAIN;
        property.user_tag = (void*)mmi_vrsi_train_pre_del_all_tag;
        mmi_confirm_display((UI_string_type)GetString(STR_ID_VRSI_DELETE_ALL_QUESTION), MMI_EVENT_QUERY, &property);
    }
    else
    {
        	//failure
        mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_EMPTY),MMI_EVENT_FAILURE,GRP_ID_VRSI, NULL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_pre_del_all_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_pre_del_all_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* System busy */
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
    {
    	//failure
        mmi_popup_display_simple((UI_string_type)GetString(STR_ID_VRSI_BUSY),MMI_EVENT_FAILURE,GRP_ID_VRSI, NULL);
        return;
    }

    /* Init VR engine for playback */
    mmi_vrsi_rcg_init(mmi_vrsi_train_del_all_tag);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_del_all_tag
 * DESCRIPTION
 *  Delete all SD tag in mapping table
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_del_all_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    U16 i, tag_num = 0;
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* VR should already in running state. */
    if (g_vrsi_cntx.vrsi_state != MMI_VRSI_STATE_RUNNING)
    {
    	//failure
        mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_ERROR),MMI_EVENT_FAILURE,GRP_ID_VRSI, NULL);
    }

    /* Read out mapping table and build ID list */
    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSI_MAX_SD_TAG; i++)
    {
        if (tag_list[i].tag_id != 0xffff)
        {
            tag_id[tag_num] = tag_list[i].tag_id;
            tag_num++;
        }
    }

    if (tag_num > 0)
    {
        /* Delete tag in engine */
        media_aud_vrsi_del_tags(MOD_MMI, (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1], tag_num, tag_id);

        /* Delete mapping in NVRAM */
        memset(tag_list, 0xff, sizeof(vrsi_sd_tag_struct) * MMI_VRSI_MAX_SD_TAG);
        WriteRecord(
            NVRAM_EF_VRSI_TAG_LID,
            1,
            (void*)tag_list,
            MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct),
            &pError);

        	//success
       
        mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_DELETED),MMI_EVENT_SUCCESS,GRP_ID_VRSI, NULL);
    }
    else
    {
    	//failure
        mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_EMPTY),MMI_EVENT_FAILURE,GRP_ID_VRSI, NULL);
    }

    /* Close engine */
    mmi_vrsi_rcg_close();
#if defined(__MMI_BT_PROFILE__)
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

#define MMI_VRSI_TRAIN_TAG_STATUS


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_train_status
 * DESCRIPTION
 *  Entry SD tag status screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_train_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 tag_status[256];
    U16 count_list[MMI_VRSI_APP_TOTAL];
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_train_util_get_tag_count(count_list);

    memset(tag_status, 0, 2);
    /* mmi_vrsi_train_tag_status_print_string(STR_ID_VRSI_TRAIN_TAG_STATUS, count_list[MMI_VRSI_APP_ALL],tag_status); */
    mmi_vrsi_train_tag_status_print_string(STR_ID_VRSI_NAME_LIST, count_list[MMI_VRSI_APP_DIAL], tag_status);
    mmi_vrsi_train_tag_status_print_string(STR_ID_VRSI_SHORTCUT_LIST, count_list[MMI_VRSI_APP_SHORTCUT], tag_status);
    mmi_vrsi_train_tag_status_print_string(STR_ID_VRSI_CITY_LIST, count_list[MMI_VRSI_APP_CITY], tag_status);
    mmi_frm_group_create(GRP_ID_VRSI_TRAIN_TAG_MAIN, GRP_ID_VRSI_TRAIN_TAG_STATUS, mmi_vrsi_settings_event_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_VRSI_TRAIN_TAG_STATUS, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    entry_ret = mmi_frm_scrn_enter(
        GRP_ID_VRSI_TRAIN_TAG_STATUS, 
        SCR_ID_VRSI_TRAIN_TAG_STATUS, 
        NULL, 
        mmi_vrsi_entry_train_status, 
        MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    

    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_VRSI_TRAIN_TAG_STATUS,SCR_ID_VRSI_TRAIN_TAG_STATUS);
    ShowCategory7Screen(
        STR_ID_VRSI_TRAIN_TAG_STATUS,
        GetRootTitleIcon(MENU_ID_VRSI_SETTING),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) tag_status,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_tag_status_print_string
 * DESCRIPTION
 *  print tag status string.
 * PARAMETERS
 *  str_id          [IN]        
 *  count           [IN]        
 *  tag_status      [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_tag_status_print_string(U16 str_id, U16 count, S8 *tag_status)
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

    if (str_id == STR_ID_VRSI_TRAIN_TAG_STATUS)
    {
        if (!strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_TCHINESE) ||
            !strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SCHINESE))
        {
            sprintf(tmpStr, "\r\n%d/%d\n", count, MMI_VRSI_MAX_SD_TAG);
        }
        else
        {
            sprintf(tmpStr, ": %d/%d\n", count, MMI_VRSI_MAX_SD_TAG);
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

#define MMI_VRSI_TRAIN_TAG_UTIL


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_util_get_id_and_loc
 * DESCRIPTION
 *  Get mapping table data
 * PARAMETERS
 *  app_id          [IN]        
 *  tag_long        [IN]        
 *  tag_id          [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_vrsi_train_util_get_id_and_loc(U8 app_id, U16 tag_long, U16 *tag_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VRSI_FUNC_TRAIN_GET_ID_LOC, app_id, tag_long, *tag_id);

    if (tag_id != NULL)
    {
        *tag_id = 0xffff;
    }

    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSI_MAX_SD_TAG; i++)
    {
        if ((tag_list[i].app_id == app_id) && (tag_list[i].tag_long == tag_long))
        {
            if (tag_id != NULL)
            {
                *tag_id = tag_list[i].tag_id;
            }

            return i;
        }
    }

    return 0xff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_util_get_loc_in_list
 * DESCRIPTION
 *  Get mapping table data
 * PARAMETERS
 *  app_id          [IN]        
 *  tag_long        [IN]        
 *  tag_list        [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_vrsi_train_util_get_loc_in_list(U8 app_id, U16 tag_long, vrsi_sd_tag_struct *tag_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_VRSI_MAX_SD_TAG; i++)
    {
        if ((tag_list[i].app_id == app_id) && (tag_list[i].tag_long == tag_long))
        {
            return i;
        }
    }

    return 0xff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_util_del_tag
 * DESCRIPTION
 *  Delete SD tag in mapping table
 * PARAMETERS
 *  app_id          [IN]        
 *  tag_long        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_util_del_tag(U8 app_id, U16 tag_long)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    U16 i;
    U8 has_mapping = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSI_MAX_SD_TAG; i++)
    {
        if ((tag_list[i].app_id == app_id) && (tag_list[i].tag_long == tag_long))
        {
            memset(&tag_list[i], 0xff, sizeof(vrsi_sd_tag_struct));
            has_mapping = 1;
        }
    }

    if (has_mapping)
    {
        WriteRecord(
            NVRAM_EF_VRSI_TAG_LID,
            1,
            (void*)tag_list,
            MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct),
            &pError);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_util_get_tag_count
 * DESCRIPTION
 *  Get SD tag count
 * PARAMETERS
 *  count_list      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_util_get_tag_count(U16 *count_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(count_list, 0, sizeof(U16) * MMI_VRSI_APP_TOTAL);

    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSI_MAX_SD_TAG; i++)
    {
        if ((tag_list[i].app_id == MMI_VRSI_APP_DIAL) && (tag_list[i].tag_long != 0xffff))
        {
            count_list[MMI_VRSI_APP_DIAL]++;
        }
        else if ((tag_list[i].app_id == MMI_VRSI_APP_SHORTCUT) && (tag_list[i].tag_long != 0xffff))
        {
            count_list[MMI_VRSI_APP_SHORTCUT]++;
        }
        else if ((tag_list[i].app_id == MMI_VRSI_APP_CITY) && (tag_list[i].tag_long != 0xffff))
        {
            count_list[MMI_VRSI_APP_CITY]++;
        }
    }

    for (i = 1; i < MMI_VRSI_APP_TOTAL; i++)
    {
        count_list[MMI_VRSI_APP_ALL] += count_list[i];
    }
}

#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ /* #if defined(__MMI_VRSI_TRAIN_TAG__) */

#define MMI_VRSI_DIGIT_ADAPT
#if defined(__MMI_VRSI_DIGIT_ADAPT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_digit_adapt
 * DESCRIPTION
 *  Highlight function for VRSI setting menu option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_digit_adapt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

 //   SetLeftSoftkeyFunction(mmi_vrsi_digit_adapt_init, KEY_EVENT_UP);
  //  SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_digit_adapt_init
 * DESCRIPTION
 *  Init engine for digit adaptation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_digit_adapt_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        MMI_STR_ID string_id = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL;
        mmi_popup_display_simple((UI_string_type)get_string(string_id), MMI_EVENT_FAILURE,GRP_ID_VRSI,0);
        return;
    }
#endif
    mmi_vrsi_rcg_init(mmi_vrsi_entry_digit_adapt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_digit_adapt
 * DESCRIPTION
 *  Entry function for digil adapt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_digit_adapt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "mmi_vrsi_entry_digit_adapt");
    TurnOnBacklight(1);

    mdi_audio_suspend_background_play();
    mmi_frm_group_create(GRP_ID_VRSI_SETTING_MENU, GRP_ID_VRSI_DIGIT_ADAPT, mmi_vrsi_settings_event_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_VRSI_DIGIT_ADAPT, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    entry_ret = mmi_frm_scrn_enter(
            GRP_ID_VRSI_DIGIT_ADAPT, 
            SCR_ID_VRSI_DIGIT_ADAPT, 
            mmi_vrsi_exit_digit_adapt, 
            mmi_vrsi_entry_digit_adapt, 
            MMI_FRM_FG_ONLY_SCRN);
    if (!entry_ret)
    {
        return;
    }    

    ShowCategory8Screen(
        STR_ID_VRSI_DIGIT_ADAPT,
        GetRootTitleIcon(MENU_ID_VRSI_SETTING),
        0,                              /* LSK STR */
        0,                              /* LSK IMG */
        STR_GLOBAL_CANCEL,              /* RSK STR */
        0,                              /* RSK IMG */
        STR_ID_VRSI_DIGIT_ADAPT_PROMPT, /* message id */
        IMG_GLOBAL_INFO,            /* icon id */
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);

    g_vrsi_cntx.curr_grammar = MMI_VRSI_GRAMMAR_TOTAL;  /* No use here */
    g_vrsi_cntx.curr_scenario = VRSI_CMD1_NONE;         /* No use here */

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) GetString(STR_ID_VRSI_DIGIT_ADAPT_PROMPT), mmi_vrsi_digit_adapt_start);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_digit_adapt
 * DESCRIPTION
 *  Exit function for digil adapt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_digit_adapt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID scr_id;
    MMI_ID group_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //scr_id = GetActiveScreenId();
   // scr_id = mmi_frm_scrn_get_active_id();
    mmi_frm_get_active_scrn_id(&group_id, &scr_id);
    if (scr_id == SCR_ID_VRSI_DIGIT_ADAPT_PROMPT)
    {
#if defined(__MMI_BT_PROFILE__)
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
        return;
    }
    else
    {
    
        mmi_vrsi_rcg_close();
    #if defined(__MMI_BT_PROFILE__)
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
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_digit_adapt_start
 * DESCRIPTION
 *  Start digit adapt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_digit_adapt_start(void)
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
        mmi_popup_display_simple((UI_string_type)GetString(STR_ID_VRSI_LANG_NOT_SUPPORT),MMI_EVENT_FAILURE,GRP_ID_VRSI, 0);
        return;
    }

    /* Start Digit Adaptation */
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
    {
        g_vrsi_cntx.session_id = mdi_audio_vrsi_new_session_id();

        result = media_aud_vrsi_start_digit_adapt(MOD_MMI, g_vrsi_cntx.session_id, g_vrsi_cntx.lang);

        if (result == MED_RES_OK)
        {
            return;
        }
    }
    	//failure
    mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_ERROR),MMI_EVENT_FAILURE,GRP_ID_VRSI, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_digit_adapt_prompt
 * DESCRIPTION
 *  Entry digit adapt prompt screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_digit_adapt_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 length;
    const U16 *str_prompt;  /* pointer to a const U16 string */
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_vrsi_read_dgt_adp_prompt(&length, &str_prompt);
    kal_prompt_trace(MOD_MMI, "mmi_vrsi_entry_digit_adapt_prompt");
    TurnOnBacklight(1);

    entry_ret = mmi_frm_scrn_enter(
            GRP_ID_VRSI_DIGIT_ADAPT, 
            SCR_ID_VRSI_DIGIT_ADAPT_PROMPT, 
            mmi_vrsi_exit_digit_adapt_prompt, 
            mmi_vrsi_entry_digit_adapt_prompt, 
            MMI_FRM_FG_ONLY_SCRN);
    if (!entry_ret)
    {
        return;
    }    

    ShowCategory66Screen(
        STR_ID_VRSI_DIGIT_ADAPT,
        GetRootTitleIcon(MENU_ID_VRSI_SETTING),
        0,                  /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_CANCEL,  /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_prompt,   /* message string */
        0,                  /* icon id */
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);

    /* Play Prompt Tone and send confirm after prompt */
    mmi_vrsi_rcg_play_prompt_tone();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_digit_adapt_prompt
 * DESCRIPTION
 *  Exit digit adapt prompt screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_digit_adapt_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID scr_id;
    MMI_ID group_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 //    scr_id = GetActiveScreenId();
    //scr_id = mmi_frm_scrn_get_active_id();
    mmi_frm_get_active_scrn_id(&group_id, &scr_id);
    if (scr_id == SCR_ID_VRSI_DIGIT_ADAPT_PROMPT)
    {
    #if defined(__MMI_BT_PROFILE__)
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
        return;
    }
    else
    {
        mmi_vrsi_rcg_close();
    #if defined(__MMI_BT_PROFILE__)
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
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_digit_adapt_result
 * DESCRIPTION
 *  Get digit adapt result.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_digit_adapt_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    	//success
    mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_DONE),MMI_EVENT_SUCCESS,GRP_ID_VRSI, 0);

 
}
#endif /* defined(__MMI_VRSI_DIGIT_ADAPT__) */ /* #if defined(__MMI_VRSI_DIGIT_ADAPT__) */

#endif /* defined(__MMI_VRSI__) */ /* #if defined(__MMI_VRSI__) */

#else /* __MTK_TARGET__ */ 
#include "CommonScreens.h"
#include "MainMenuDef.h"
void mmi_vrsi_highlight_setting_menu(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_setting_init
 * DESCRIPTION
 *  init function for VRSI setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_setting_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}



void mmi_vrsi_popup_no_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_NOT_SUPPORT_AT_PC_SIMULATOR),MMI_EVENT_WARNING,GRP_ID_ROOT, 0);
    return;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_setting_menu
 * DESCRIPTION
 *  Highlight function for VRSI setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_setting_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_vrsi_popup_no_support, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}

/* for simulator after modify the sethilitehandler */


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_hint_rcg_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_hint_rcg_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_tag_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_tag_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_delete_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_city_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_city_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_shortcut_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_shortcut_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_name_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_name_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_digit_adapt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_digit_adapt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_rcg_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_rcg_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mi_vrsi_highlight_setting_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mi_vrsi_highlight_setting_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __MTK_TARGET__ */ 
#endif /* _MMI_VRSISETTINGS_C */ /* #ifndef _MMI_VRSISETTINGS_C */

