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
 *  PhnsetMenuService.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for phone setup menu service interface
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
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
/*  Include: MMI header file */

/* auto add by kw_check begin */
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
/* auto add by kw_check end */

#include "SettingMenuService.h"
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_MENU__)
#include "mmi_rp_app_shortcuts_def.h"
#endif

#include "NetSetSrvGprot.h"
#ifdef __MMI_TELEPHONY_SUPPORT__
#include "mmi_rp_srv_flight_mode_def.h"
#endif
#include "PhoneSetupGprots.h"
#include "mmi_rp_app_phonesetting_new_def.h"
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
#ifdef __MMI_DEDICATED_KEY_SHORTCUTS__
static MMI_BOOL mmi_phnset_is_hide_dedicated_key(void);
#endif

static MMI_BOOL mmi_phnset_is_hide_flight_mode(void);

#ifdef __MMI_VUI_LAUNCHER_KEY__
static MMI_BOOL mmi_phnset_is_hide_widget_setting(void);
static MMI_BOOL mmi_phnset_is_hide_shortcut_setting(void);
#endif
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

/* local hide menu structure array */
const mmi_setting_hide_menu_struct mmi_phnset_hide_menu[] =
{
#ifdef __MMI_DEDICATED_KEY_SHORTCUTS__
	{MENU_SETTING_DEDICATED_KEYS, mmi_phnset_is_hide_dedicated_key},
#endif
#ifdef __MMI_TELEPHONY_SUPPORT__
	{MENU_SETTING_FLIGHT_MODE, mmi_phnset_is_hide_flight_mode},
#endif
#ifdef __MMI_VUI_LAUNCHER_KEY__
	{MENU_ID_KEY_LAUNGCHER_WGTMGR, mmi_phnset_is_hide_widget_setting},
	{MENU_ID_FTE_LAUNGCHER_SHORTCUT, mmi_phnset_is_hide_shortcut_setting},
#endif

	{0, NULL}
};


/* MENU_SETTING_DEDICATED_KEYS */
#ifdef __MMI_DEDICATED_KEY_SHORTCUTS__
/*****************************************************************************
* FUNCTION
*  mmi_phnset_is_hide_dedicated_key
* DESCRIPTION
*  This function is used to get dedicated key menu status
* PARAMETERS
*  void          
* RETURNS
*  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_phnset_is_hide_dedicated_key(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL result = MMI_FALSE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
	return result;
}
#endif /* __MMI_DEDICATED_KEY_SHORTCUTS__ */
/* MENU_SETTING_DEDICATED_KEYS */


/* MENU_SETTING_FLIGHT_MODE */
static MMI_BOOL mmi_phnset_is_hide_flight_mode(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
	if (srv_netset_get_pref_mode() == SRV_NETSET_PREF_MODE_WLAN_ONLY)
	{
		return MMI_TRUE;
	}
#endif
	
	return MMI_FALSE;
}
#ifdef __MMI_VUI_LAUNCHER_KEY__
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_is_hide_widget_setting
 * DESCRIPTION
 *  check if the menu should be hided.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI BOOL: MMI_TRUE: need hide. MMI_FALSE: Not hide
 *****************************************************************************/
static MMI_BOOL mmi_phnset_is_hide_widget_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef __MMI_VUI_LAUNCHER__
	ret = (MMI_BOOL)(!(mmi_phnset_launcher_get_launcher_type() == MMI_PHNSET_LAUNCHER_KEY));
#endif
	return ret;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_is_hide_shortcut_setting
 * DESCRIPTION
 *  check if the menu should be hided.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI BOOL: MMI_TRUE: need hide. MMI_FALSE: Not hide
 *****************************************************************************/
static MMI_BOOL mmi_phnset_is_hide_shortcut_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	#ifdef __MMI_VUI_LAUNCHER__
	ret = (MMI_BOOL)(!(mmi_phnset_launcher_get_launcher_type() == MMI_PHNSET_LAUNCHER_KEY));
	#endif
#if 0
	#ifdef __OP01__
/* under construction !*/
	#endif
	#endif
	return ret;

}

#endif
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
/* MENU_SETTING_FLIGHT_MODE */
