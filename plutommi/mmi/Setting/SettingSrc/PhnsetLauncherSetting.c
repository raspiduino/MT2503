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
 * PhnsetLauncherSetting.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for launcher switch setting
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
/* MMI standard headers */
#include "MMI_features.h"

#if ((defined(__MMI_LAUNCHER_APP_LIST__) && defined(__MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__) || defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_VUI_LAUNCHER__)))
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories.h"
#include "nvram_common_defs.h"
#include "mmi_rp_app_mainmenu_def.h"

#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
/* UI */
#include "menucuigprot.h"
#include "mmi_rp_app_phonesetting_new_def.h"
#include "mmi_rp_app_setting_menu_effect_def.h"
#include "IdleGprot.h"
/*TEMP imgage resource.*/
#include "PhoneSetupGprots.h"
#include "PhoneSetup.h"
#include "MMI_ap_dcm_config.h"
/* Device headers */

/***************************************************************************** 
* Local Functions
*****************************************************************************/
static void mmi_phnset_launcher_switch_entry_main(MMI_ID parent_id);
static mmi_ret mmi_phnset_launcher_switch_proc(mmi_event_struct *evt);
static void mmi_phnset_launcher_set_launcher_type(U8 type);


/***************************************************************************** 
* local define
*****************************************************************************/

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/***************************************************************************** 
* Local Varibles
*****************************************************************************/
static U8 g_back_idle_flag;
static MMI_ID g_grp_id;

/***************************************************************************** 
* Global Varibles
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_launcher_switch_hilight_hdlr
 * DESCRIPTION
 *  phone setting launcher switch setting hilight function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_launcher_switch_hilight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetLeftSoftkeyFunction(mmi_phnset_launcher_switch_launch, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_phnset_launcher_switch_launch, KEY_EVENT_UP);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_launcher_switch_launch
 * DESCRIPTION
 *  phone setting launcher switch launch switch app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_launcher_switch_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_grp_id = mmi_frm_group_create_ex(GRP_ID_ROOT, 
							GRP_ID_AUTO_GEN, 
							mmi_phnset_launcher_switch_proc, 
							NULL, 
							MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_phnset_launcher_switch_entry_main(g_grp_id);
	
}
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_launcher_switch_entry_main
 * DESCRIPTION
 *  entry main screen of launcher switch manu
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phnset_launcher_switch_entry_main(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_id = cui_menu_create(
                    parent_id,
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_APPMAIN,
                    MENU_ID_VUI_PHNSET_LAUNCHER,
                    MMI_TRUE,
                    NULL);
    cui_menu_set_default_left_softkey_by_id(menu_cui_id, STR_GLOBAL_OK);
    cui_menu_set_default_title_string_by_id(menu_cui_id, STR_ID_VUI_PHNSET_LAUNCHER);
    cui_menu_run(menu_cui_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_launcher_switch_proc
 * DESCRIPTION
 *  proc for launcher switch
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_phnset_launcher_switch_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 type;
    mmi_menu_id highlight_menu;
    cui_menu_event_struct *menu_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_event = (cui_menu_event_struct*)evt;
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (menu_event->parent_menu_id == MENU_ID_VUI_PHNSET_LAUNCHER)
            {
                type = (U8)mmi_phnset_launcher_get_launcher_type();
                highlight_menu = MENU_ID_VUI_PHNSET_LAUNCHER_1 + type;
                cui_menu_set_currlist_highlighted_id(menu_event->sender_id, highlight_menu);
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
			type = (U8)(menu_event->highlighted_menu_id - MENU_ID_VUI_PHNSET_LAUNCHER_1);
			if(type != (U8)mmi_phnset_launcher_get_launcher_type())
			{
			    mmi_phnset_launcher_set_launcher_type(type);
				g_back_idle_flag = 1; /* need back to idle, after launcher switch */
			}
            mmi_popup_display_simple_ext(
                STR_GLOBAL_DONE,
                MMI_EVENT_SUCCESS,
                g_grp_id,
                NULL);
            cui_menu_close(menu_event->sender_id);
            break;

		case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
		case EVT_ID_GROUP_GOBACK_IN_END_KEY:
			g_back_idle_flag = 0;
			break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_event->sender_id);
            break;
            
        case EVT_ID_GROUP_DEINIT:
			if(g_back_idle_flag)
			{
				mmi_idle_display();
				g_back_idle_flag = 0;
			}
			break;
			
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
*  mmi_phnset_launcher_switch_hint
* DESCRIPTION
* Lanucher switch setting menu hint string.
* PARAMETERS
*  evt        [VOID]
* RETURNS
*  void
*****************************************************************************/
void mmi_phnset_launcher_switch_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_phnset_launcher_type_enum type;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	type = mmi_phnset_launcher_get_launcher_type();
#if defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_VUI_LAUNCHER__)
	cui_menu_set_item_hint(
		mmi_frm_group_get_active_id(),
        MENU_ID_VUI_PHNSET_LAUNCHER,
        (WCHAR*)GetString(STR_ID_VUI_PHNSET_LAUNCHER_1 + type));
#else
	cui_menu_set_item_hint(
		mmi_frm_group_get_active_id(),
        MENU_ID_VUI_PHNSET_LAUNCHER,
        (WCHAR*)GetString(STR_ID_VUI_PHNSET_LAUNCHER_0 + type));   
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_launcher_set_launcher_type
 * DESCRIPTION
 *  Set launcher type to nvram
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phnset_launcher_set_launcher_type(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 Err;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	WriteValue(NVRAM_PHNSET_LAUNCHER_SETTING, &type, DS_BYTE, &Err);
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_launcher_get_launcher_type
 * DESCRIPTION
 *  get launcher type from nvram
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_phnset_launcher_type_enum mmi_phnset_launcher_get_launcher_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 Err;
	U8 type;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ReadValue(NVRAM_PHNSET_LAUNCHER_SETTING, &type, DS_BYTE, &Err);
	if(type >= MMI_PHNSET_LAUNCHER_TOTAL || type < 0)
	{
#if defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_VUI_LAUNCHER__)
    		type = MMI_PHNSET_LAUNCHER_FTE;
#else
            type = MMI_PHNSET_LAUNCHER_CLASSIC; 
#endif
	}
	return (mmi_phnset_launcher_type_enum)type;
}

#endif

