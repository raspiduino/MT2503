/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * PhnsetGPIO.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for GPIO setting Menus
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
* Include
*****************************************************************************/
/* MMI standard headers */
#include "MMI_include.h"
#include "kal_general_types.h"
#include "MMIDataType.h"

/* nvram access */
#include "custom_mmi_default_value.h" 

/* Others */
#include "custom_equipment.h"

#include "mmi_frm_nvram_gprot.h"
#include "device.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories.h"
#ifdef __PLUTO_MMI_PACKAGE__
#include "mmi_rp_app_mainmenu_def.h"
#endif
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "Unicodexdcl.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
/* UI */
#include "menucuigprot.h"
#include "BootupSrvGprot.h"

#include "mmi_rp_app_gpio_def.h"
#include "mmi_rp_srv_gpio_def.h"
#include "PhnsetGPIO.h"
/* Device headers */
#include "GpioSrvGprot.h"
#include "MMI_ap_dcm_config.h"
#include "gdi_include.h"

#ifndef __PLUTO_MMI_PACKAGE__
#ifndef MAIN_MENU_TITLE_SETTINGS_ICON // for COSMOS Mainmenu Res Remove
#define MAIN_MENU_TITLE_SETTINGS_ICON  (0)
#endif
#endif
/***************************************************************************** 
* Local Functions
*****************************************************************************/
MMI_BOOL PhnsetRestoreToNvramContrast(void);
void PhnsetMainLCDContrast(U8 level);
void PhnsetSubLCDContrast(U8 level);

static void mmi_phset_gpio_entry_backlite(void);
#ifndef __MMI_MRE_DISABLE_FMGR__
static void mmi_phset_entry_MRE_version(void);
static void PhnsetGPIOMreVersionLSKHdlr(void);
static void PhnsetGPIOMreVersionRSKHdlr(void);
#endif
static void HighlightPhnsetBackLiteLevel(S32 index);
#ifdef __MMI_GPIO_SUPPORT_BL_TIME_SETTING__
static void HighlightPhnsetBackLiteHFTime(S32 index);
#endif
static mmi_ret mmi_phnset_gpio_bl_del_callback(void);
static void PhnsetGPIOBackLiteLSKHdlr(void);
static void PhnsetGPIOBackLiteRSKHdlr(void);

#ifdef __MMI_PHNSET_GPIO_COVER__
static void mmi_phset_gpio_entry_cover(void);
#endif

#if !defined(HARDWARE_LED_NOT_SUPPORT)
static void mmi_phnset_gpio_entry_led(MMI_ID parent_id);
static void mmi_phnset_gpio_led_switch(U8 on_flag, MMI_ID id);
#endif
#ifdef __MMI_MAINLCD_96X64__
void mmi_phset_gpio_entry_backlite_timeout(void);
#endif
#ifdef __LCD_COLOR_ENGINE_SUPPORT__
static U16 mmi_phnset_gpio_get_selected_picture_quality(void);
static void mmi_phnset_gpio_entry_picture_quality(void);
static MMI_BOOL mmi_phnset_get_picture_quality_status(void);
static void mmi_phnset_set_picture_quality_status(MMI_BOOL is_enable);
#endif
/***************************************************************************** 
* Local Varibles
*****************************************************************************/
static MMI_ID g_gpio_gid;
/***************************************************************************** 
* Global Varibles
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  PhnsetReadGPIOSetting
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetReadGPIOSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_gpio_setting_init();
}

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
* FUNCTION
*  mmi_phnset_gpio_select_menu
* DESCRIPTION
*  screen group of chat log manage callback function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_phnset_gpio_select_menu(mmi_menu_id id, MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (id)
    {
    #ifdef __MMI_BACKLIGHT_SUPPORT__
        case MENU_ID_PHNSET_GPIO_BACKLITE:
    	    mmi_phset_gpio_entry_backlite();
            break;
    #endif /* __MMI_BACKLIGHT_SUPPORT__ */
    #if !defined(HARDWARE_LED_NOT_SUPPORT)
    	case MENU_ID_PHNSET_GPIO_LED:
    		mmi_phnset_gpio_entry_led(parent_id);
            break; 
    #endif
    		    
    #ifdef __MMI_PHNSET_GPIO_COVER__
        case MENU_ID_PHNSET_GPIO_COVER_CLOSE:
			mmi_phset_gpio_entry_cover();
            break;
    #endif
    #ifndef __MMI_MRE_DISABLE_FMGR__
	#ifndef __BT_DIALER_SUPPORT__
		case MENU_ID_PHNSET_MRE_CURRENT_VERSION:
			mmi_phset_entry_MRE_version();
			break;
		#endif
	#endif

#ifdef __LCD_COLOR_ENGINE_SUPPORT__
        case MENU_ID_PHNSET_PICTURE_QUALITY:
            mmi_phnset_gpio_entry_picture_quality();
            break;
#endif

        default:
            break;
    }    
}


/*****************************************************************************
* FUNCTION
*  mmi_phnset_gpio_menu_handler
* DESCRIPTION
*  screen group of chat log manage callback function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_phnset_gpio_menu_handler(cui_menu_event_struct *menu_evt, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_evt->parent_menu_id == MENU_ID_PHNSET_GPIO_SETTING)
    {
        if (menu_evt->evt_id == EVT_ID_CUI_MENU_LIST_ENTRY)
        {
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
        #ifdef __LCD_COLOR_ENGINE_SUPPORT__
            if(mmi_phnset_get_picture_quality_status())
            {
                cui_menu_set_item_hint(
                            menu_evt->sender_id, 
                            MENU_ID_PHNSET_PICTURE_QUALITY, 
                            (UI_string_type)GetString(STR_GLOBAL_ON));
            }
            else
            {
                cui_menu_set_item_hint(
                            menu_evt->sender_id, 
                            MENU_ID_PHNSET_PICTURE_QUALITY, 
                            (UI_string_type)GetString(STR_GLOBAL_OFF));
            }
        #endif

        #ifdef __MMI_BTD_BOX_UI_STYLE__
	#ifndef __MMI_MRE_DISABLE_FMGR__
          cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PHNSET_MRE_CURRENT_VERSION, MMI_TRUE);
        #endif /*__MMI_MRE_DISABLE_FMGR__*/
	  cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PHNSET_PICTURE_QUALITY, MMI_TRUE);
	#endif /*__MMI_BTD_BOX_UI_STYLE__*/
		
        }
    }
    
	switch (menu_evt->highlighted_menu_id)
	{
    	case MENU_ID_PHNSET_GPIO_BACKLITE:
    #if !defined(HARDWARE_LED_NOT_SUPPORT)
    	case MENU_ID_PHNSET_GPIO_LED:
    #endif
    #ifdef __MMI_COVER_CLOSE_SETTING__
        case MENU_ID_PHNSET_GPIO_COVER_CLOSE:
    #endif
    #ifndef __MMI_MRE_DISABLE_FMGR__
	#ifndef __BT_DIALER_SUPPORT__
		case MENU_ID_PHNSET_MRE_CURRENT_VERSION:
		#endif
		#endif
        #ifdef __LCD_COLOR_ENGINE_SUPPORT__
            case MENU_ID_PHNSET_PICTURE_QUALITY:
        #endif
    	    break;

    default:
        return MMI_RET_DONT_CARE;
	}

    switch(menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            g_gpio_gid = parent_gid;
            mmi_phnset_gpio_select_menu(menu_evt->highlighted_menu_id, parent_gid);
            break;           
            
        default:
            break;
    }
    return MMI_RET_OK;
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif

#ifdef __MMI_BACKLIGHT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_gpio_set_bl_level_ncenter
 * DESCRIPTION
 *  Update backlight level when changes at NCenter backlight 
 * PARAMETERS
 *  evt      [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phnset_gpio_set_bl_level_ncenter(mmi_event_struct *evt)
{
      if(mmi_frm_scrn_is_present (g_gpio_gid, SCR_ID_GPIO_BACKLIGHT_SETTING, MMI_FRM_NODE_ALL_FLAG))
     {
        mmi_frm_scrn_clean_gui_buf(g_gpio_gid, SCR_ID_GPIO_BACKLIGHT_SETTING);
     }
     return MMI_RET_OK;
}

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_gpio_set_bl_level
 * DESCRIPTION
 *  set backlite level
 * PARAMETERS
 *  level
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_gpio_set_bl_level(S32 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_gpio_setting_set_bl_level(level, MMI_TRUE);
}

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetBackLiteLevel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void HighlightPhnsetBackLiteLevel(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index > 0 && index <= SRV_GPIO_BACKLIGHT_MAX_LEVEL)
    {
        srv_gpio_setting_set_bl_level(index, MMI_FALSE);
    }
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif

#ifdef __MMI_GPIO_SUPPORT_BL_TIME_SETTING__
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetBackLiteHFTime
 * DESCRIPTION
 *  This function is highlight handler for Phonesetup-> Contrast -> SubLCD
 *  Follow functions:
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void HighlightPhnsetBackLiteHFTime(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= 5 && index <= 60)
    {
        srv_gpio_setting_set_hf_time(index, MMI_FALSE);
    }
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#endif /* __MMI_GPIO_SUPPORT_BL_TIME_SETTING__ */

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  PhnsetGPIOBackLiteEndHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_phnset_gpio_bl_del_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_gpio_setting_bl_restore();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGPIOBackLiteLSKHdlr
 * DESCRIPTION
 *  This function is Left softkey handler
 *  for Phonesetup->Constract -> Main/Sub LCD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PhnsetGPIOBackLiteLSKHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValueSlim(NVRAM_BYTE_BL_SETTING_LEVEL, &data, DS_BYTE);
    if (data != g_phnset_gpio_cntx_p->bl_setting_level)
    {
        WriteValueSlim(NVRAM_BYTE_BL_SETTING_LEVEL, &(g_phnset_gpio_cntx_p->bl_setting_level), DS_BYTE);
    }
    
#ifdef __MMI_GPIO_SUPPORT_BL_TIME_SETTING__
    ReadValueSlim(NVRAM_BYTE_BL_SETTING_HFTIME, &data, DS_SHORT);
    if (data != g_phnset_gpio_cntx_p->bl_setting_hftime)
    {
        WriteValueSlim(NVRAM_BYTE_BL_SETTING_HFTIME, &(g_phnset_gpio_cntx_p->bl_setting_hftime), DS_SHORT);
    }

    srv_backlight_set_hf_time(SRV_BACKLIGHT_SET_TIMER_DEFAULT, g_phnset_gpio_cntx_p->bl_setting_hftime); 
    
	mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, g_gpio_gid, NULL);
#endif

    mmi_frm_scrn_close(g_gpio_gid, SCR_ID_GPIO_BACKLIGHT_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGPIOBackLiteRSKHdlr
 * DESCRIPTION
 *  This function is Right softkey handler
 *  for Phonesetup->Constract -> Main/Sub LCD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PhnsetGPIOBackLiteRSKHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_gpio_setting_bl_restore();

    mmi_frm_scrn_close_active_id();    
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#endif /* __MMI_BACKLIGHT_SUPPORT__ */
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
#endif

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
#ifndef __MMI_MRE_DISABLE_FMGR__
/*****************************************************************************
 * FUNCTION
 *  mmi_phset_gpio_entry_backlite
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PhnsetGPIOMreVersionLSKHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_close(g_gpio_gid, SCR_ID_GPIO_BACKLIGHT_SETTING);
}
static void PhnsetGPIOMreVersionRSKHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_close(g_gpio_gid, SCR_ID_GPIO_BACKLIGHT_SETTING);
}

static void mmi_phset_entry_MRE_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	U8 temp_str[40] = {0};
	U8 temp_str_input[40] = {0};
//	sprintf(temp_str,"MRE VERSION:%d",MRE_VERSION);
	sprintf((S8*)temp_str,"MRE VERSION:%d.%d.%02d",MRE_VERSION/1000,(MRE_VERSION%1000)/100,MRE_VERSION%100);

	mmi_asc_to_ucs2((PS8)temp_str_input,(PS8)temp_str); 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (!mmi_frm_scrn_enter(g_gpio_gid, SCR_ID_GPIO_BACKLIGHT_SETTING, 
           NULL, mmi_phset_entry_MRE_version, MMI_FRM_UNKNOW_SCRN))
        return;
	
	ShowCategory141Screen(
		STR_ID_AM_MRE_CURRENT_VERSION,
		MAIN_MENU_TITLE_SETTINGS_ICON,
		STR_GLOBAL_OK,
		0,

		STR_GLOBAL_BACK,
		0,
		temp_str_input,
		0,
		NULL);

	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(PhnsetGPIOMreVersionLSKHdlr, KEY_EVENT_UP);

	SetLeftSoftkeyFunction(PhnsetGPIOMreVersionLSKHdlr, KEY_EVENT_UP);
	SetRightSoftkeyFunction(PhnsetGPIOMreVersionRSKHdlr, KEY_EVENT_UP);
}
#endif


#if defined(__MMI_MAINLCD_96X64__) && defined(__MMI_BACKLIGHT_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phset_gpio_entry_backlite_timeout
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phset_gpio_entry_backlite_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gpio_gid = mmi_frm_group_create_ex(GRP_ID_ROOT,
       GRP_ID_AUTO_GEN,
       NULL,
       (void*)NULL,
       MMI_FRM_NODE_SMART_CLOSE_FLAG); 
    mmi_phset_gpio_entry_backlite();
}
#endif

#ifdef __MMI_BACKLIGHT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phset_gpio_entry_backlite
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phset_gpio_entry_backlite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_GPIO_SUPPORT_BL_TIME_SETTING__
    #define N_ITEMS   (1)
#else
    #define N_ITEMS   (2)
#endif
    
    U8 *guiBuffer;
    S32 lower_limit[N_ITEMS];
    S32 upper_limit[N_ITEMS];
    S32 *current_value[N_ITEMS];
    void (*cb_func[N_ITEMS]) (S32 value);
    U8 *str_list[N_ITEMS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (!mmi_frm_scrn_enter(g_gpio_gid, SCR_ID_GPIO_BACKLIGHT_SETTING, 
           NULL, mmi_phset_gpio_entry_backlite, MMI_FRM_UNKNOW_SCRN))
        return;

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    lower_limit[0] = 1;
    upper_limit[0] = SRV_GPIO_BACKLIGHT_MAX_LEVEL;
    current_value[0] = &(g_phnset_gpio_cntx_p->bl_setting_level);
    cb_func[0] = HighlightPhnsetBackLiteLevel;
    str_list[0] = (U8*) GetString(STR_ID_PHNSET_GPIO_BACKLITE_LEVEL);
    
#ifdef __MMI_GPIO_SUPPORT_BL_TIME_SETTING__
    lower_limit[1] = 5;
    upper_limit[1] = 60;
    current_value[1] = (S32 *)&(g_phnset_gpio_cntx_p->bl_setting_hftime);
    cb_func[1] = HighlightPhnsetBackLiteHFTime;
    str_list[1] = (U8*) GetString(STR_ID_PHNSET_GPIO_BACKLITE_HF_TIME);
#endif /* __MMI_GPIO_SUPPORT_BL_TIME_SETTING__ */     

    ShowCategory88Screen(
        STR_ID_PHNSET_GPIO_BACKLITE,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        0,
        N_ITEMS,
        str_list,
        lower_limit,
        upper_limit,
        current_value,
        cb_func,
        guiBuffer);

    mmi_frm_scrn_set_leave_proc(g_gpio_gid, SCR_ID_GPIO_BACKLIGHT_SETTING,
                (mmi_proc_func)mmi_phnset_gpio_bl_del_callback);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(PhnsetGPIOBackLiteLSKHdlr, KEY_EVENT_UP);

    SetLeftSoftkeyFunction(PhnsetGPIOBackLiteLSKHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(PhnsetGPIOBackLiteRSKHdlr, KEY_EVENT_UP);

}
#endif /* __MMI_BACKLIGHT_SUPPORT__ */

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif


#ifdef __MMI_PHNSET_GPIO_COVER__
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

/*****************************************************************************
 * FUNCTION
 *  PhnsetGPIOCoverLSKHdlr
 * DESCRIPTION
 *  This function is Left softkey handler
 *  for Phonesetup->Constract -> Main/Sub LCD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PhnsetGPIOCoverLSKHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValueSlim(NVRAM_BYTE_COVER_CLOSE_BACK_TO_IDLE, &(g_phnset_gpio_cntx_p->cover_close_back_to_idle), DS_BYTE);
    WriteValueSlim(NVRAM_BYTE_COVER_CLOSE_REJECT_CALL, &(g_phnset_gpio_cntx_p->cover_close_reject_call), DS_BYTE);
    WriteValueSlim(NVRAM_BYTE_COVER_CLOSE_KEYPAD_LOCK, &(g_phnset_gpio_cntx_p->cover_close_keypad_lock), DS_BYTE);

	mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, g_gpio_gid, NULL);
    
    mmi_frm_scrn_close(g_gpio_gid,SCR_ID_GPIO_COVER_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGPIOCoverFillInline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  InLineItems     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void PhnsetGPIOCoverFillInline(InlineItem *InLineItems)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&InLineItems[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&InLineItems[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&InLineItems[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_BACK_TO_IDLE_TITLE] =
        (PU8) GetString(STR_ID_PHNSET_GPIO_COVER_CLOSE_BACK_TO_IDLE);
    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_BACK_TO_IDLE_ON] = (PU8) GetString(STR_GLOBAL_OFF);
    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_BACK_TO_IDLE_OFF] = (PU8) GetString(STR_GLOBAL_ON);
    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_REJECT_CALL_TITLE] =
        (PU8) GetString(STR_ID_PHNSET_GPIO_COVER_CLOSE_REJECT_CALL);
    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_REJECT_CALL_YES] = (PU8) GetString(STR_GLOBAL_YES);
    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_REJECT_CALL_NO] = (PU8) GetString(STR_GLOBAL_NO);
    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_KEYPAD_LOCK_TITLE] =
        (PU8) GetString(STR_ID_PHNSET_GPIO_COVER_CLOSE_KEYPAD_LOCK);
    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_KEYPAD_LOCK_ON] = (PU8) GetString(STR_GLOBAL_OFF);
    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_KEYPAD_LOCK_OFF] = (PU8) GetString(STR_GLOBAL_ON);

    SetInlineItemCaption(&InLineItems[0], subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_BACK_TO_IDLE_TITLE]);
    SetInlineItemSelect(
        &InLineItems[1],
        2,
        &subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_BACK_TO_IDLE_ON],
        &(g_phnset_gpio_cntx_p->cover_close_back_to_idle));
    SetInlineItemCaption(&InLineItems[2], subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_REJECT_CALL_TITLE]);
    SetInlineItemSelect(
        &InLineItems[3],
        2,
        &subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_REJECT_CALL_YES],
        &(g_phnset_gpio_cntx_p->cover_close_reject_call));
    SetInlineItemCaption(&InLineItems[4], subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_KEYPAD_LOCK_TITLE]);
    SetInlineItemSelect(
        &InLineItems[5],
        2,
        &subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_KEYPAD_LOCK_ON],
        &(g_phnset_gpio_cntx_p->cover_close_keypad_lock));
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGPIOCoverInlineHiliteHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void PhnsetGPIOCoverInlineHiliteHdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(PhnsetGPIOCoverLSKHdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phset_gpio_entry_cover
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phset_gpio_entry_cover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 icons[6] = {IMG_SETTING_GREET_TEXT, 0, IMG_SETTING_GREET_TEXT, 0, IMG_SETTING_GREET_TEXT, 0};
    InlineItem InLineItems[6];
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_GPIO_COVER_SETTING, NULL, mmi_phset_gpio_entry_cover, NULL);

    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_GPIO_COVER_SETTING);
    memset((void*)InLineItems, 0, sizeof(InlineItem) * 6);

    PhnsetGPIOCoverFillInline(InLineItems);

    SetLeftSoftkeyFunction(PhnsetGPIOCoverLSKHdlr, KEY_EVENT_UP);
//    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    RegisterHighlightHandler(PhnsetGPIOCoverInlineHiliteHdlr);
    /* added for inline edit history */
    inputBuffer = GetCurrNInputBuffer(SCR_ID_GPIO_COVER_SETTING, &inputBufferSize);

    if (inputBuffer != NULL)    /* added for inline edit history */
    {
        SetCategory57Data(InLineItems, 6, inputBuffer); /* sets the data */
    }

    ShowCategory57Screen(
        STR_ID_PHNSET_GPIO_COVER_CLOSE,
        IMG_SCR_SETTING_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        6,
        icons,
        InLineItems,
        0,
        guiBuffer);
    DisableCategory57ScreenDone();

    SetCategory57RightSoftkeyFunctions(PhnsetGPIOCoverLSKHdlr, mmi_frm_scrn_close_active_id);
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#endif /* __MMI_PHNSET_GPIO_COVER__ */

#if !defined(HARDWARE_LED_NOT_SUPPORT)
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_gpio_led_off
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_gpio_led_switch(U8 on_flag, MMI_ID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_phnset_gpio_cntx_p->led_setting = on_flag;
    if (on_flag == 1)
        srv_led_pattern_start_background();
    else
        srv_led_pattern_stop_background();
	WriteValueSlim(NVRAM_BYTE_LED_SETTING, &(g_phnset_gpio_cntx_p->led_setting), DS_BYTE);
    srv_led_pattern_set_flag((MMI_BOOL)g_phnset_gpio_cntx_p->led_setting);
    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_GPIO_LED_SETTING, NULL);
	cui_menu_close(id);	
}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_gpio_group_handler
* DESCRIPTION
*  screen group of chat log manage callback function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_phnset_gpio_group_handler(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    cui_menu_event_struct *menucui_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (cui_menu_is_menu_event(param->evt_id))
    {
        menucui_event = (cui_menu_event_struct*)param;
		
		switch(menucui_event->evt_id)
        {
            case EVT_ID_CUI_MENU_LIST_ENTRY:
                if(menucui_event->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
                {
                    if (g_phnset_gpio_cntx_p->led_setting == 1)
                    {
                        cui_menu_set_radio_list_item(menucui_event->sender_id, MENU_ID_PHNSET_GPIO_LED_ON);
                    }
                    else
                    {
                        cui_menu_set_radio_list_item(menucui_event->sender_id, MENU_ID_PHNSET_GPIO_LED_OFF);
                    }
                }
                break;
      
            case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
				  switch (menucui_event->highlighted_menu_id)
				  {
				  case MENU_ID_PHNSET_GPIO_LED_ON:
		               mmi_phnset_gpio_led_switch(1, menucui_event->sender_id);
                       break;

                  case MENU_ID_PHNSET_GPIO_LED_OFF:
		               mmi_phnset_gpio_led_switch(0, menucui_event->sender_id);
                       break;

				  default:
                      break;
				  }
				  break;
            }

		    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
                cui_menu_close(mmi_frm_group_get_active_id());
                break;

		    default:
                return MMI_RET_OK;
		}	
	}
    return MMI_RET_OK; 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_gpio_entry_led
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_gpio_entry_led(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_group_create_ex(
        parent_id,
        GRP_ID_GPIO_LED_SETTING,
        mmi_phnset_gpio_group_handler,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

	menu_id = cui_menu_create(
        GRP_ID_GPIO_LED_SETTING,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_APPSUB,
        MENU_ID_PHNSET_GPIO_LED,
        MMI_TRUE,
        NULL);

    cui_menu_set_default_title_by_id(
        menu_id,
        STR_ID_PHNSET_GPIO_LED,
        MAIN_MENU_TITLE_SETTINGS_ICON);

	cui_menu_run(menu_id);
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif 
#endif /* HARDWARE_LED_NOT_SUPPORT */

#ifdef __LCD_COLOR_ENGINE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_gpio_get_selected_picture_quality
 * DESCRIPTION
 *  Interface the get the selected picture quality menu ID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_phnset_gpio_get_selected_picture_quality(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_phnset_get_picture_quality_status())
    {
        return MENU_ID_PHNSET_PICTURE_QUALITY_ON;
    }
    else
    {
        return MENU_ID_PHNSET_PICTURE_QUALITY_OFF;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_phset_gpio_entry_picture_quality_proc
 * DESCRIPTION
 *  This is the proc function for Picture quality menu cui
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phset_gpio_entry_picture_quality_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            if(menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
            {
                cui_menu_set_currlist_highlighted_id(menu_evt->sender_id,
                                                     mmi_phnset_gpio_get_selected_picture_quality());
            }
            break;
        }
	case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
        {
            if(menu_evt->highlighted_menu_id == MENU_ID_PHNSET_PICTURE_QUALITY_ON)
            {
                gdi_color_engine_custom_on();
                mmi_phnset_set_picture_quality_status(MMI_TRUE);
    	        mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_PHNSET_PICTURE_QUALITY_OFF)
            {
                gdi_color_engine_custom_off();
                mmi_phnset_set_picture_quality_status(MMI_FALSE);
    	        mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
            }
            cui_menu_close(menu_evt->sender_id);
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_gpio_entry_picture_quality
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_gpio_entry_picture_quality(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id;
    MMI_ID menu_cui_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_id = mmi_frm_group_create_ex(mmi_frm_group_get_active_id(),
       GRP_ID_AUTO_GEN,
       mmi_phset_gpio_entry_picture_quality_proc,
       (void*)NULL,
       MMI_FRM_NODE_SMART_CLOSE_FLAG); 

    menu_cui_id = cui_menu_create(
        grp_id,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_APPSUB,
        MENU_ID_PHNSET_PICTURE_QUALITY,
        MMI_TRUE,
        NULL);

    cui_menu_set_default_title_by_id(
        menu_cui_id,
        STR_ID_PHNSET_PICTURE_QUALITY,
        MAIN_MENU_TITLE_SETTINGS_ICON);

	cui_menu_run(menu_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_gpio_entry_picture_quality
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_picture_quality_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BOOL pq_status = mmi_phnset_get_picture_quality_status();
    if(pq_status)
    {
        gdi_color_engine_custom_on();
    }
    else
    {
        gdi_color_engine_custom_off();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_get_picture_quality_status
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_phnset_get_picture_quality_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    U8 data = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValueSlim(NVRAM_SETTING_PICTURE_QUALITY, &data, DS_BYTE);
    if(data != 0)
    {
        result = MMI_TRUE;
    }
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_set_picture_quality_status
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_set_picture_quality_status(MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = (U8)is_enable;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValueSlim(NVRAM_SETTING_PICTURE_QUALITY, &data, DS_BYTE);

}

#endif /* __LCD_COLOR_ENGINE_SUPPORT__ */


// Already phase out
MMI_BOOL PhnsetRestoreToNvramContrast(void)
{
    return MMI_TRUE;
}


// Already phase out
void PhnsetMainLCDContrast(U8 level)
{
}


// Already phase out
void PhnsetSubLCDContrast(U8 level)
{
}

