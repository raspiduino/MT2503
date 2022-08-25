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
 *  PhnsetDispMenuService.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for phone setup disp menu service interface
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
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
/*  Include: MMI header file */
#include "MMI_features.h"
#include "SettingMenuService.h"
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
#endif
#endif
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_rp_app_phonesetting_new_def.h"
#ifdef __MMI_PHNSET_APPICON_SUPPORT__  
#include "mmi_rp_app_setting_appicon_def.h"
#endif
#include "MMI_common_app_trc.h"
#include "mmi_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "l4c_nw_cmd.h"
/* auto add by kw_check end */
#include "SimCtrlSrvGprot.h"
#include "PhoneSetupGprots.h"
#include "IdleGProt.h"
#include "FactoryGprot.h"
#include "IdleFactory.h"
#include "MMI_ap_dcm_config.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/


/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

/***************************************************************************** 
* External Function
*****************************************************************************/

/*****************************************************************************
* Local Function 
*****************************************************************************/
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
static MMI_BOOL mmi_phnset_disp_is_hide_mainmenu_style(void);
#endif
#ifdef __MMI_MOTION_DIAL__
static MMI_BOOL mmi_phnset_disp_is_hide_dial_style(void);
#endif
#if defined(__MMI_VUI_MAINMENU__) || ((defined(__MMI_VUI_LAUNCHER_KEY__) || defined(__MMI_VUI_LAUNCHER__)) && defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__))

static MMI_BOOL mmi_phnset_disp_is_hide_vui_mainmenu_effect(void);
#endif
#if 0
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
/* under construction !*/
#endif	
#endif
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
#endif
#endif
#ifdef __MMI_DUAL_CLOCK__
static MMI_BOOL mmi_phnset_disp_is_hide_dual_clock(void);
#endif

static MMI_BOOL mmi_phnset_disp_is_hide_show_datetime(void);

#ifdef __MMI_SCREEN_SWITCH_EFFECT__
static MMI_BOOL mmi_phnset_disp_is_hide_scrswitch_effect(void);
#endif

#if 0
#ifdef __MMI_OPERATOR_NAME_MENU__
/* under construction !*/
#endif
#endif

#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
static MMI_BOOL mmi_phnset_disp_is_hide_clock_type(void);
#endif
#ifdef __MMI_IDLE_SCREEN_OWNER_NUMBER__
static MMI_BOOL mmi_phnset_disp_is_hide_owner_number_main(void);
#endif
#ifdef __MMI_PHNSET_APPICON_SUPPORT__
static MMI_BOOL mmi_phnset_disp_is_hide_appicon(void);
#endif

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTING_RODATA" , code = "DYNAMIC_CODE_SETTING_ROCODE"
#endif
/* local hide menu structure array */
const mmi_setting_hide_menu_struct mmi_phnset_disp_hide_menu[] =
{
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
	{MENU_SETTING_MAINMENU_STYLE, mmi_phnset_disp_is_hide_mainmenu_style},
#endif
#ifdef __MMI_MOTION_DIAL__
	{MENU_SETTING_DIAL_STYLE, mmi_phnset_disp_is_hide_dial_style},
#endif
#if defined(__MMI_VUI_MAINMENU__) || ((defined(__MMI_VUI_LAUNCHER_KEY__) || defined(__MMI_VUI_LAUNCHER__)) && defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__))
	{MENU_ID_VUI_PHNSET_MAINMENU_EFFECT, mmi_phnset_disp_is_hide_vui_mainmenu_effect},
#endif
#if 0
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
/* under construction !*/
#endif
#endif
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
#endif
#endif
#ifdef __MMI_DUAL_CLOCK__
	{MENU_ID_PHNSET_DUAL_CLOCK_IDLESCREEN, mmi_phnset_disp_is_hide_dual_clock},
#endif
#ifndef __MMI_MAINLCD_96X64__
	{MENU_SETTING_SHOW_DT_TIME, mmi_phnset_disp_is_hide_show_datetime},
#endif	
#if 0
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#else
/* under construction !*/
#endif
#endif
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
	{MENU_ID_PHNSET_SCRSWITCH_EFFECT, mmi_phnset_disp_is_hide_scrswitch_effect},
#endif
#if 0
#ifdef __MMI_OPERATOR_NAME_MENU__
/* under construction !*/
#endif
#endif
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
	{MENU_SETTING_IDLE_CLOCK_TYPE, mmi_phnset_disp_is_hide_clock_type},
#endif
#ifdef __MMI_IDLE_SCREEN_OWNER_NUMBER__
    {MENU_SETTING_OWNER_NUMBER, mmi_phnset_disp_is_hide_owner_number_main},
#endif   
#ifdef __MMI_PHNSET_APPICON_SUPPORT__
        {MENU_SETTING_APP_ICON, mmi_phnset_disp_is_hide_appicon},
#endif        
	{0, NULL}
};


/* MENU_SETTING_MAINMENU_STYLE */
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
/*****************************************************************************
* FUNCTION
*  mmi_phnset_disp_is_hide_mainmenu_style
* DESCRIPTION
*  This function is used to get main menu style menu status
* PARAMETERS
*  void          
* RETURNS
*  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_phnset_disp_is_hide_mainmenu_style(void)
{
#ifdef __MMI_VUI_3D_MAINMENU__
	return MMI_TRUE;
#endif	
#ifndef __MMI_MAINMENU_STYLE_CHANGE_EN__
    return MMI_TRUE;
#endif

#ifdef __MMI_VUI_MAINMENU__
    return MMI_TRUE;
#endif /* __MMI_VUI_MAINMENU__ */
	
    return MMI_FALSE;
}

#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */
/* MENU_SETTING_MAINMENU_STYLE */


/* MENU_SETTING_DIAL_STYLE */
#ifdef __MMI_MOTION_DIAL__
/*****************************************************************************
* FUNCTION
*  mmi_phnset_disp_is_hide_dial_style
* DESCRIPTION
*  This function is used to get dial motion style menu status
* PARAMETERS
*  void          
* RETURNS
*  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_phnset_disp_is_hide_dial_style(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return MMI_FALSE;
}
#endif /* __MMI_MOTION_DIAL__ */
/* MENU_SETTING_DIAL_STYLE */





/* MENU_ID_VUI_PHNSET_MAINMENU_EFFECT */

#if defined(__MMI_VUI_MAINMENU__) || ((defined(__MMI_VUI_LAUNCHER_KEY__) || defined(__MMI_VUI_LAUNCHER__)) && defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__))
static MMI_BOOL mmi_phnset_disp_is_hide_vui_mainmenu_effect(void)
{
#if defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__) && defined(__MMI_VUI_LAUNCHER__)
	return (MMI_BOOL)(!(mmi_phnset_launcher_get_launcher_type() == MMI_PHNSET_LAUNCHER_KEY ||
						mmi_phnset_launcher_get_launcher_type() == MMI_PHNSET_LAUNCHER_FTE));
#else
    return MMI_FALSE;
#endif
}
#endif /* __MMI_VUI_MAINMENU__ */

/* MENU_ID_VUI_PHNSET_MAINMENU_EFFECT */

#if 0
/* under construction !*/
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP12_TOOLBAR__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_MAINLCD_320X240__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_VUI_LAUNCHER__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
/* under construction !*/
#endif
#if 0
/* under construction !*/
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
#endif
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__) */
/* under construction !*/
#endif

/* MENU_ID_PHNSET_DUAL_CLOCK_IDLESCREEN */
#ifdef __MMI_DUAL_CLOCK__
/*****************************************************************************
* FUNCTION
*  mmi_phnset_disp_is_hide_dual_clock
* DESCRIPTION
*  This function is used to get dual clock menu status
* PARAMETERS
*  void          
* RETURNS
*  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_phnset_disp_is_hide_dual_clock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL result = MMI_FALSE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WC_TZ_SUPPORT__ 
	MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_PHNSET_DISP_MENU_TRC_LINE, __LINE__);
	return MMI_TRUE;
#endif
#if 0	
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */
#endif
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
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
#endif
#if defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
		MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_PHNSET_DISP_MENU_TRC_LINE, __LINE__);
		result = MMI_TRUE;
#endif /* defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_VUI_LAUNCHER__) */
	return result;
}
#endif /* __MMI_DUAL_CLOCK__ */
/* MENU_ID_PHNSET_DUAL_CLOCK_IDLESCREEN */


#ifndef __MMI_MAINLCD_96X64__
/* MENU_SETTING_SHOW_DT_TIME */
/*****************************************************************************
* FUNCTION
*  mmi_phnset_disp_is_hide_show_datetime
* DESCRIPTION
*  This function is used to get show date time menu status
* PARAMETERS
*  void          
* RETURNS
*  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_phnset_disp_is_hide_show_datetime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */
#endif
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
#endif
    if(mmi_factory_get_favorite_type(mmi_idle_get_cfg_table()) == MMI_IDLE_TYPE_APPLIST)
     {
	    return MMI_TRUE;
     }
#if 0
#if defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_SHELL_OP01_HOMESCREEN__) || defined(__MMI_VUI_LAUNCHER_KEY__)
/* under construction !*/
/* under construction !*/
#else /* defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_SHELL_OP01_HOMESCREEN__) */
/* under construction !*/
#endif /* defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_SHELL_OP01_HOMESCREEN__) */
#else
#if defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
	MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_PHNSET_DISP_MENU_TRC_LINE, __LINE__);
	return MMI_TRUE;
#else /* defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_VUI_LAUNCHER__) */
	return MMI_FALSE;
#endif /* defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_VUI_LAUNCHER__) */

#endif
}
/* MENU_SETTING_SHOW_DT_TIME */
#endif

/* MENU_ID_PHNSET_SCRSWITCH_EFFECT */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
/*****************************************************************************
* FUNCTION
*  mmi_phnset_disp_is_hide_scrswitch_effect
* DESCRIPTION
*  This function is used to get screen switch effect menu status
* PARAMETERS
*  void          
* RETURNS
*  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_phnset_disp_is_hide_scrswitch_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return MMI_FALSE;
}
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */
/* MENU_ID_PHNSET_SCRSWITCH_EFFECT */

#if 0
/* under construction !*/
#ifdef __MMI_OPERATOR_NAME_MENU__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OPERATOR_NAME_MENU__ */
/* under construction !*/
#endif

/* MENU_SETTING_IDLE_CLOCK_TYPE */
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
/*****************************************************************************
* FUNCTION
*  mmi_phnset_disp_is_hide_clock_type
* DESCRIPTION
*  This function is used to get clock type menu status
* PARAMETERS
*  void          
* RETURNS
*  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_phnset_disp_is_hide_clock_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */
#endif
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
#endif
#if defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_PHNSET_DISP_MENU_TRC_LINE, __LINE__);
    return MMI_TRUE;
#else /* defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_VUI_LAUNCHER__) */
	return MMI_FALSE;
#endif /* defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_VUI_LAUNCHER__) */
}
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */
/* MENU_SETTING_IDLE_CLOCK_TYPE */

#ifdef __MMI_IDLE_SCREEN_OWNER_NUMBER__
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_disp_is_hide_owner_number_main
 * DESCRIPTION
 *  Check SIM status and return show owner number menu hide result 
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_phnset_disp_is_hide_owner_number_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL rtn = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GEMINI__
#if (MMI_MAX_SIM_NUM >= 3)
	return MMI_TRUE;
#endif
    if (!srv_sim_ctrl_is_available(MMI_SIM1) && !srv_sim_ctrl_is_available(MMI_SIM2)
    #if (MMI_MAX_SIM_NUM >= 3)  
        && !srv_sim_ctrl_is_available(MMI_SIM3)
    #if (MMI_MAX_SIM_NUM >= 4)
        && !srv_sim_ctrl_is_available(MMI_SIM4)
    #endif /* MMI_MAX_SIM_NUM >= 3 */
    #endif /* MMI_MAX_SIM_NUM >= 4 */
    )
	{
	    rtn = MMI_TRUE;
	}
#else
    if (!srv_sim_ctrl_is_available(MMI_SIM1))
	{
	    rtn = MMI_TRUE;
	}
#endif /* __GEMINI__ */
    return rtn;
}
#endif /* __MMI_IDLE_SCREEN_OWNER_NUMBER__ */
 
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#ifdef __MMI_PHNSET_APPICON_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_disp_is_hide_appicon
 * DESCRIPTION
 *  Check current type and return appicon menu hide result 
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_phnset_disp_is_hide_appicon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
   return (mmi_factory_get_favorite_type(mmi_idle_get_cfg_table()) == MMI_IDLE_TYPE_APPLIST ? MMI_FALSE : MMI_TRUE);
}
#endif
 

