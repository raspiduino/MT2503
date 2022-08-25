/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  TTSSetting.c
 *
 * Project:
 * --------
 *  PLUTO
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_Features.h"
#ifdef __GENERAL_TTS__
#include "MMIDataType.h"
#include "TTSSettingGprot.h"
#include "PhoneSetup.h"
#include "mmi_rp_app_tts_setting_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "MMI_ap_dcm_config.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Functions 
 *****************************************************************************/
static mmi_ret mmi_tts_setting_call_tts_setting_proc(mmi_event_struct *evt);
static mmi_ret mmi_tts_setting_sms_tts_setting_proc(mmi_event_struct *evt);


/***************************************************************************** 
 * Phone book TTS Setting
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_tts_setting_is_call_tts_enabled
 * DESCRIPTION
 *  Check if phone book TTS is turn ON 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_tts_setting_is_call_tts_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CALL_TTS_SETTING, &data, DS_BYTE, &error);
    if (data > (U8)MMI_TRUE)
	{
	    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_CALL_TTS_SETTING, &data);
        WriteValue(NVRAM_CALL_TTS_SETTING, &data, DS_BYTE, &error);        
	}
    return (MMI_BOOL)data;
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_tts_setting_call_tts_set_enable
 * DESCRIPTION
 *  Enable / Disable phone book TTS setting 
 * PARAMETERS
 *  is_enabled  :   [IN] MMI_TRUE enable, MMI_FALSE disable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tts_setting_call_tts_set_enable(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (U8)is_enabled;
    WriteValue(NVRAM_CALL_TTS_SETTING, &data, DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tts_setting_entry_call_tts_setting
 * DESCRIPTION
 *  Enter phone book TTS setting menu 
 * PARAMETERS
 *  parent_gid  :   [IN] Group ID of parent
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tts_setting_entry_call_tts_setting(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_appcreate_menucui_create(
        parent_gid,
        GRP_ID_PHB_TTS_SETTING_MENU,
        STR_ID_PHB_TTS_SETTING,
        mmi_tts_setting_call_tts_setting_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tts_setting_call_tts_setting_proc
 * DESCRIPTION
 *  Proc function for phone book TTS setting 
 * PARAMETERS
 *  evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_tts_setting_call_tts_setting_proc(mmi_event_struct *evt)
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
        mmi_phnset_init_on_off_radio_button_menu(
            GRP_ID_PHB_TTS_SETTING_MENU,
            STR_ID_PHB_TTS_SETTING,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            (U8)mmi_tts_setting_is_call_tts_enabled());
        return MMI_RET_OK;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        mmi_tts_setting_call_tts_set_enable((MMI_BOOL)menu_evt->highlighted_menu_id);
        
        mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);    
        mmi_frm_group_close(GRP_ID_PHB_TTS_SETTING_MENU);   
        return MMI_RET_OK;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(menu_evt->sender_id);
		return MMI_RET_OK;
		
    default:
		break;
    }
    return MMI_RET_OK;    
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
/***************************************************************************** 
 * SMS TTS Setting
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_tts_setting_is_sms_tts_enabled
 * DESCRIPTION
 *  Check if SMS TTS is turn ON 
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_tts_setting_is_sms_tts_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SMS_TTS_SETTING, &data, DS_BYTE, &error);
    if (data > (U8)MMI_TRUE)
	{
	    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_SMS_TTS_SETTING, &data);
        WriteValue(NVRAM_SMS_TTS_SETTING, &data, DS_BYTE, &error);        
	}
    return (MMI_BOOL)data;
} 
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_tts_setting_sms_tts_set_enable
 * DESCRIPTION
 *  Enable / Disable SMS TTS setting 
 * PARAMETERS
 *  is_enabled  :   [IN] MMI_TRUE enable, MMI_FALSE disable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tts_setting_sms_tts_set_enable(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (U8)is_enabled;
    WriteValue(NVRAM_SMS_TTS_SETTING, &data, DS_BYTE, &error);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_tts_setting_entry_call_tts_setting
 * DESCRIPTION
 *  Enter phone book TTS setting menu 
 * PARAMETERS
 *  parent_gid  :   [IN] Group ID of parent
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tts_setting_entry_sms_tts_setting(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_appcreate_menucui_create(
        parent_gid,
        GRP_ID_SMS_TTS_SETTING_MENU,
        STR_ID_SMS_TTS_SETTING,
        mmi_tts_setting_sms_tts_setting_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tts_setting_call_tts_setting_proc
 * DESCRIPTION
 *  Proc function for phone book TTS setting 
 * PARAMETERS
 *  evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_tts_setting_sms_tts_setting_proc(mmi_event_struct *evt)
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
        mmi_phnset_init_on_off_radio_button_menu(
            GRP_ID_SMS_TTS_SETTING_MENU,
            STR_ID_SMS_TTS_SETTING,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            (U8)mmi_tts_setting_is_sms_tts_enabled());
        return MMI_RET_OK;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        mmi_tts_setting_sms_tts_set_enable((MMI_BOOL)menu_evt->highlighted_menu_id);
        
        mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);    
        mmi_frm_group_close(GRP_ID_SMS_TTS_SETTING_MENU);   
        return MMI_RET_OK;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(menu_evt->sender_id);
		return MMI_RET_OK;
		
    default:
		break;
    }
    return MMI_RET_OK;    
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#endif /* __GENERAL_TTS__ */
