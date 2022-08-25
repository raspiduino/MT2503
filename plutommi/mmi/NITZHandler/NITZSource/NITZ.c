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
 * NITZ.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements interface and message handler for NITZ.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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


#ifdef __MMI_NITZ__
/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMIDataType.h"
#include "NITZ.h"
#include "Worldclock.h"

#include "GSM7BitDefaultAlphabet.h"	/* for CovertStringForPlatform */
#include "GpioSrvGprot.h"	/* for srv_backlight_turn_on */
#include "DateTimeGprot.h"  /* mmi_dt_set_rtc_dt */
#include "IdleGprot.h"
#include "SettingProt.h"    /* RstGetNITZStatusDefault */
#include "DateTimeType.h"

#include "MenuCuiGprot.h"

    #include "MMI_common_app_trc.h"
    #include "DebugInitDef_Int.h"
    #include "custom_mmi_default_value.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "app_datetime.h"
    #include "stack_config.h"
    #include "kal_trace.h"
    #include "string.h"
    #include "mmi_msg_struct.h"
    #include "mmi_frm_nvram_gprot.h"
    #include "Unicodexdcl.h"
    #include "mmi_frm_mem_gprot.h"
    #include "stack_msgs.h"
    #include "mmi_frm_events_gprot.h"
    #include "nvram_common_defs.h"
    #include "GlobalResDef.h"
    #include "mmi_rp_app_nitz_def.h"
    #include "CustDataRes.h"
    #include "wgui_categories_util.h"
    #include "AlertScreen.h"
    #include "CommonScreensResDef.h"
    #include "mmi_frm_input_gprot.h"
    #include "wgui_categories_text_viewer.h"
    #include "GlobalConstants.h"
    #include "wgui_categories.h"
    #include "ps_public_enum.h"
    #include "mmi_common_app_trc.h"
    #include "ps_public_struct.h"
    #include "kal_general_types.h"
    #include "kal_public_api.h"
    #include "mmi_frm_utility_gprot.h"
 #include "NITZSrvGprot.h"
 #include "NITZSrvIprot.h"
	#include "Mmi_rp_app_mainmenu_def.h"   
    
/***************************************************************************** 
* Define
*****************************************************************************/

#define NITZ_SIGN_BIT	0x08
#define NITZ_TZ_BIT		0x07

#define NITZ_HIGH_BIT	0xF0
#define NITZ_LOW_BIT	0x0F

#define srv_set_nitz_state(state)	srv_set_nitz_state_ext(state, __LINE__)
#define srv_get_nitz_state()		srv_get_nitz_state_ext(__LINE__)

// Add trace definition
#define MMI_NITZ_TRACE0(sub_grp) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp)

#define MMI_NITZ_TRACE1(sub_grp, arg) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg)
		
#define MMI_NITZ_TRACE2(sub_grp, arg1, arg2) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2)

#define MMI_NITZ_TRACE3(sub_grp, arg1, arg2, arg3) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3)

#define MMI_NITZ_TRACE7(sub_grp, arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3, arg4, arg5, arg6, arg7)
		

/***************************************************************************** 
* Global Variable
*****************************************************************************/
#ifdef __MMI_NITZ_TZ_SUPPORT__
static S16 nitzTempDST;
static S16 nitzTempTZ;
#endif /* __MMI_NITZ_TZ_SUPPORT__ */ 

	static srv_nitz_context_struct g_nitz_cntx;

/*
 * for geting nw name, we don't need to read nvram every time.
 */

/***************************************************************************** 
* Local Function
*****************************************************************************/

/* NITZ MMI Functions */
/* NITZ Application functions */
static void mmi_nitz_update_datetime(void);
static void mmi_nitz_update_operator_name(void);

/* NITZ confirm screen functions */
static void mmi_entry_nitz_app(mmi_id parent_id);
extern void mmi_nitz_entry_confirm_screen(void);
static void mmi_nitz_confirm_screen_accept(void);
static void mmi_nitz_confirm_screen_ignore(void);
static void mmi_nitz_write_nw_name_to_nvram(U8 sim_type, nitz_nw_name_struct *nw_name);
#ifdef __MMI_NITZ_TZ_SUPPORT__
static U8 mmi_nitz_check_tz(U32 tz_valid_flag);
#endif

/***************************************************************************** 
* External Function
*****************************************************************************/
extern U8 applib_dt_sec_2_mytime(U32 utc_sec, applib_time_struct *result);


#ifdef __MMI_NITZ_TZ_SUPPORT__
/*****************************************************************************
* FUNCTION
*  mmi_nitz_check_tz
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
 *****************************************************************************/
static U8 mmi_nitz_check_tz(U32 tz_valid_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
	U32 dst_val;
	U32 ret = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check time zone */
    MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_RTC_NITZ_CHECK_TZ);
    
    /* init dst */
    ReadValue(NVRAM_SETTING_DT_DST, &(g_nitz_cntx.day_light_saving), DS_BYTE, &error);
	dst_val = g_nitz_cntx.day_light_saving;
    
    if (g_nitz_cntx.update_local_time_zone == MMI_TRUE)
    {
        MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_RTC_NITZ_CHECK_TZ_INFO, (S32) g_nitz_cntx.nitz_timezone, (S32) nitzTempTZ, dst_val, (S32) nitzTempDST);
        /* init timezone */
        ReadValue(NVRAM_TIMEZONE, &(g_nitz_cntx.nitz_timezone), DS_SHORT, &error);		    
        if ((g_nitz_cntx.nitz_timezone + (nitzTempDST * 4)) != nitzTempTZ || nitzTempDST != dst_val)
        {
        	if(tz_valid_flag)
            {
				ret = MMI_TRUE;
            }
        }
    }
    else if(g_nitz_cntx.update_day_light_saving == MMI_TRUE)
    {               
 		if (nitzTempDST != dst_val)
        {
            ret = MMI_TRUE;
            }
        }
	else if(dst_val == MMI_TRUE)
        {
		ret = MMI_TRUE;
    }
    return ret;
}

#endif /* __MMI_NITZ_TZ_SUPPORT__ */

/* NITZ MMI functions Start */

/* Auto Update Date & Time Screen */
/*****************************************************************************
 * FUNCTION
 *  mmi_nitz_phnset_menu_handler
 * DESCRIPTION
 *  This function is high light handler of NITZ menu
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_nitz_phnset_menu_handler(cui_menu_event_struct *menu_evt, mmi_id parent_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct *evt = (cui_menu_event_struct *)menu_evt;
    U16 evt_id = evt->evt_id;
	S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt != NULL && parent_id != GRP_ID_INVALID);
    
	if (evt->highlighted_menu_id == MENU_ID_NITZ_APP &&
        (evt_id == EVT_ID_CUI_MENU_ITEM_SELECT ||
	    evt_id == EVT_ID_CUI_MENU_ITEM_TAP ||
	    evt_id == EVT_ID_CUI_MENU_ITEM_CSK_SELECT))
    {
        mmi_entry_nitz_app(parent_id);
        
        ret = MMI_RET_OK;
    }

    ret = MMI_RET_DONT_CARE;
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nitz_get_curr_nitz_string
 * DESCRIPTION
 *  The current selected nitz string
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_nitz_get_curr_nitz_string(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_nitz_type_enum type = srv_get_apply_nitz_type();
	U32 ret = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(type)
	{
	case SRV_NITZ_OFF:
		ret = STR_GLOBAL_OFF;
		break;
		
	case SRV_NITZ_CONFIRM_FIRST:
		ret = STR_ID_NITZ_APP_CONFIRM_FIRST;
		break;
		
	case SRV_NITZ_ON:
		ret = STR_GLOBAL_ON;
		break;
		
	default:
		break;
	}
	
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nitz_group_proc
 * DESCRIPTION
 *  This function is high light handler of NITZ menu
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_nitz_group_proc(mmi_event_struct* evt)
{
		/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
	mmi_id cui_id = menu_evt->sender_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(evt->evt_id)
	{
	     case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            if (menu_evt->parent_menu_id == MENU_ID_NITZ_APP)
            {
                mmi_menu_id menu_list[3] = {
                        MENU_ID_NITZ_APP_OFF,
                        MENU_ID_NITZ_APP_CONFIRM_FIRST,
                        MENU_ID_NITZ_APP_ON
                    };
                cui_menu_set_currlist_flags(cui_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                cui_menu_set_default_title_string_by_id(cui_id, STR_ID_NITZ_APP);
				cui_menu_set_default_title_image_by_id(cui_id, MAIN_MENU_TITLE_SETTINGS_ICON);
                cui_menu_set_currlist(cui_id, 3, menu_list);
				cui_menu_set_currlist_left_softkey_by_id(cui_id, STR_GLOBAL_OK);
                cui_menu_set_item_string_by_id(cui_id, MENU_ID_NITZ_APP_OFF, STR_GLOBAL_OFF);
                cui_menu_set_item_string_by_id(cui_id, MENU_ID_NITZ_APP_CONFIRM_FIRST, STR_ID_NITZ_APP_CONFIRM_FIRST);            
                cui_menu_set_item_string_by_id(cui_id, MENU_ID_NITZ_APP_ON, STR_GLOBAL_ON);

		if (menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
		{
	        	cui_menu_set_currlist_highlighted_id(cui_id, MENU_ID_NITZ_APP_OFF + srv_get_apply_nitz_type());            
                }                
            }
        }
        break;
        
    case EVT_ID_CUI_MENU_ITEM_SELECT:
		case EVT_ID_CUI_MENU_ITEM_TAP:
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            if (menu_evt->parent_menu_id == MENU_ID_NITZ_APP)
            {
        		srv_set_apply_nitz_type((srv_nitz_type_enum)(menu_evt->highlighted_menu_id - MENU_ID_NITZ_APP_OFF));
				mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
				cui_menu_close(cui_id);
            }
        }
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(cui_id);
        }
        break;
		
	case EVT_ID_ALERT_QUIT:
		{
			mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
			if (alert && alert->user_tag)
			{
				U16 user_data = *(U16*)alert->user_tag;
				if (user_data == STR_GLOBAL_DONE)
				{
					mmi_frm_group_close(GRP_ID_NITZ_APP);
				}
			}
		}
		break;
		
        default:
        	break;
      }
      
      return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_entry_nitz_app
 * DESCRIPTION
 *  This function is entry function of NITZ menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_entry_nitz_app(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id;
    mmi_id cui_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_id = mmi_frm_group_create_ex(parent_id, 
                                  GRP_ID_NITZ_APP, 
                                  mmi_nitz_group_proc, 
                                  NULL,
                                  MMI_FRM_NODE_SMART_CLOSE_FLAG);


    cui_menu_id = cui_menu_create(grp_id, 
                                  CUI_MENU_SRC_TYPE_APPCREATE, 
                                  CUI_MENU_TYPE_APPSUB, 
                                  MENU_ID_NITZ_APP, 
                                  MMI_FALSE, 
                                  NULL);

    cui_menu_run(cui_menu_id);
}

/* Auto Update Date & Time Screen */


/* Auto Update Date & Time Confirm Screen */
/*****************************************************************************
 * FUNCTION
 *  mmi_nitz_is_need_update
 * DESCRIPTION
 *  This function is to check whether need update NITZ in idle callback
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_nitz_is_need_update(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* NITZ apply type is "Confirm First" and status is wait update */
	if ((srv_get_apply_nitz_type() == SRV_NITZ_CONFIRM_FIRST) && (srv_get_nitz_state() == SRV_NITZ_WAIT_UPDATE))
	{
		return 1;
	}

	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nitz_entry_nitz_confirm_screen
 * DESCRIPTION
 *  This function is to entry auto update date and time confirm screen
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nitz_entry_nitz_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 *gui_buffer;
	mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	grp_id = mmi_idle_get_group_id();
	if(mmi_frm_scrn_is_present(grp_id,SCR_ID_NITZ_CONFIRM,MMI_FRM_NODE_ALL_FLAG))
	{
		return;
	}

    if (mmi_frm_scrn_enter(
            grp_id, 
            SCR_ID_NITZ_CONFIRM, 
            NULL, 
            NULL, 
            MMI_FRM_FULL_SCRN))
    {
    ClearKeyEvents();
	
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
		
		EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		
        ShowCategory7Screen(
            STR_ID_NITZ_CONFIRM_TITLE,
            GetRootTitleIcon(MENU_ID_NITZ_APP),
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (U8*)GetString(STR_ID_NITZ_CONFIRM_INFO),
            gui_buffer);

		wgui_inputs_ml_set_style(0, GUI_MULTI_LINE_INPUT_BOX_DISABLE_CLIPBOARD);

        SetLeftSoftkeyFunction(mmi_nitz_confirm_screen_accept, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_nitz_confirm_screen_accept, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_nitz_confirm_screen_ignore, KEY_EVENT_UP);
        SetKeyHandler(mmi_nitz_confirm_screen_ignore, KEY_END, KEY_EVENT_DOWN);
}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_nitz_confirm_screen_accept
 * DESCRIPTION
 *  This function is LSK function of NITZ confirm screen
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nitz_confirm_screen_accept(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_nitz_update_datetime();
	mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nitz_confirm_screen_cancel
 * DESCRIPTION
 *  This function is LSK function of NITZ confirm screen
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nitz_confirm_screen_ignore(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_scrn_close_active_id();
	memset(&g_nitz_cntx, 0x00, sizeof(srv_nitz_context_struct));
	srv_set_nitz_state(SRV_NITZ_IDLE);
}


/*****************************************************************************
* FUNCTION
*  mmi_nitz_update_operator_name
* DESCRIPTION
*  This API to update operator name
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_nitz_update_operator_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nitz_nw_name_struct nwk_name;
	srv_nitz_nw_name_update_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    memset(&nwk_name, 0x00, sizeof(nitz_nw_name_struct));

    if (g_nitz_cntx.operator_short_name[0])
    {
        memcpy(&(nwk_name.name), &g_nitz_cntx.operator_short_name, MAX_NW_LEN * ENCODING_LENGTH);
        nwk_name.add_ci = (U8) g_nitz_cntx.add_ci;

		memcpy(&(nwk_name.plmn), g_nitz_cntx.nitz_plmn, MAX_PLMN_LEN);	
    }
    else if (g_nitz_cntx.operator_full_name[0])
    {
        memcpy(&nwk_name.name, &g_nitz_cntx.operator_full_name, MAX_NW_LEN * ENCODING_LENGTH);
        nwk_name.add_ci = (U8) g_nitz_cntx.add_ci;

		memcpy(&(nwk_name.plmn), g_nitz_cntx.nitz_plmn, MAX_PLMN_LEN);	
    }
        mmi_nitz_write_nw_name_to_nvram(g_nitz_cntx.sim_id, &nwk_name);        
        mmi_idle_notify_event();
	if(nwk_name.name[0])
	{
	    MMI_FRM_INIT_EVENT(&evt, EVT_ID_NITZ_NW_NAME_UPDATE_NOTIFY);
		evt.sim_id = g_nitz_cntx.sim_id;
	    MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
	}
    }


/*****************************************************************************
* FUNCTION
*  mmi_nitz_write_nw_name_to_nvram
* DESCRIPTION
*  This API to write network name to NVRAM
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_nitz_write_nw_name_to_nvram(U8 sim_type, nitz_nw_name_struct *nw_name)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
	U32 sim_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	sim_index = mmi_frm_sim_to_index((mmi_sim_enum)sim_type) + 1;

    WriteRecord(NVRAM_EF_NITZ_NW_NAME_LID, sim_index, nw_name, sizeof(nitz_nw_name_struct), &error);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_nitz_update_datetime
 * DESCRIPTION
 *  This function is to update date and time with NITZ information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nitz_update_datetime(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 tick_count_2, diff_second;
    applib_time_struct incTime;
#ifdef __MMI_NITZ_TZ_SUPPORT__
    applib_time_struct resultTime;
    FLOAT nitz_tz, diff_tz = 0;   
    applib_time_struct currTime;
	U32 tz_valid_flag;
#endif 
	MYTIME *nitz_timeP;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	nitz_timeP = &g_nitz_cntx.nitz_time;
#ifdef __MMI_NITZ_TZ_SUPPORT__
	nitzTempTZ = g_nitz_cntx.nitz_timezone;
	nitzTempDST = g_nitz_cntx.day_light_saving;

	/* check if time zone is valid */
    if (mmi_wc_set_home_city_from_nitz(nitzTempTZ, MMI_WC_CHECK_HOME_CITY) == -1)
    {
		MMI_NITZ_TRACE0(MMI_RTC_NITZ_RECV_INVALID_TZ);
        tz_valid_flag = 0;
    }
    else
    {
        tz_valid_flag = 0xffff;
    }
#endif
    if (mmi_dt_is_valid(nitz_timeP))
{
        kal_get_time(&tick_count_2);
    
        MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_NITZ_TRACE_002, tick_count_2);
        
        if (tick_count_2 >= g_nitz_cntx.recv_tick_count)
        {
            diff_second = kal_ticks_to_secs(tick_count_2 - g_nitz_cntx.recv_tick_count);
        }
        else
        {
            diff_second = kal_ticks_to_secs(0xFFFF - (g_nitz_cntx.recv_tick_count - tick_count_2));
}
        
        applib_dt_sec_2_mytime(diff_second, (applib_time_struct*)&incTime);
        
        IncrementTime(g_nitz_cntx.nitz_time, incTime, nitz_timeP);

#ifdef __MMI_NITZ_TZ_SUPPORT__
        /* set time zone */        
        /* If time zone is invalid, set time zone as GMT 0 */
        mmi_wc_set_home_city_from_nitz((S16) (tz_valid_flag & (g_nitz_cntx.nitz_timezone - (g_nitz_cntx.day_light_saving * 4))), MMI_WC_SET_HOME_CITY);
        
        mmi_dt_set_dst((U8) g_nitz_cntx.day_light_saving);
#endif /* __MMI_NITZ_TZ_SUPPORT__ */ 
        
        mmi_dt_set_rtc_dt((MYTIME*)nitz_timeP);
    }
#ifdef __MMI_NITZ_TZ_SUPPORT__
    else if (mmi_nitz_check_tz(tz_valid_flag))
    {
        DTGetRTCTime(&currTime);
        
        nitz_tz = (FLOAT) nitzTempTZ;
        nitz_tz /= 4;

        if (!g_nitz_cntx.update_local_time_zone)
        {
            diff_tz = nitz_tz - nitzTempDST - g_nitz_cntx.nitz_timezone/4;            
        }
        
        /* turn DST off */
        if (applib_dt_is_dst_enabled() == MMI_TRUE && nitzTempDST == 0)
        {
            diff_tz -= 1;
        }
        else if (applib_dt_is_dst_enabled() == MMI_FALSE && nitzTempDST == 1)
        {
            diff_tz += nitzTempDST;
        }   
        
        applib_dt_utc_to_rtc(diff_tz, (applib_time_struct*) & currTime, (applib_time_struct*) &resultTime);
        memcpy(nitz_timeP, &resultTime, sizeof(applib_time_struct));
        mmi_dt_set_rtc_dt((MYTIME*)nitz_timeP);    
        
        /* set time zone */
        g_nitz_cntx.nitz_timezone = nitzTempTZ;
        g_nitz_cntx.day_light_saving = (U8)nitzTempDST;
        
        /* If time zone is invalid, set time zone as GMT 0 */
        mmi_wc_set_home_city_from_nitz((S16) (tz_valid_flag & (g_nitz_cntx.nitz_timezone - (g_nitz_cntx.day_light_saving * 4))), MMI_WC_SET_HOME_CITY);
        mmi_dt_set_dst((U8) g_nitz_cntx.day_light_saving);        
    }
	
#endif /* __MMI_NITZ_TZ_SUPPORT__ */ 
	memset(&g_nitz_cntx, 0x00, sizeof(srv_nitz_context_struct));
	srv_set_nitz_state(SRV_NITZ_IDLE);


}

/*****************************************************************************
* FUNCTION
*  mmi_nitz_dt_update_handler
* DESCRIPTION
*  EVT_ID_SRV_NITZ_UPDATE_REQ event handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_nitz_dt_update_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_nitz_update_req_event_struct *nitz_evt = (srv_nitz_update_req_event_struct*)evt;
	
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	memcpy(&g_nitz_cntx, &(nitz_evt->nitz_data), sizeof(srv_nitz_context_struct));
	mmi_nitz_update_operator_name();

    /* NITZ status is ON and need update date and time directly */
    if (srv_get_apply_nitz_type() == SRV_NITZ_ON)
    {
        mmi_nitz_update_datetime();	
    }
    else
    {
        srv_set_nitz_state(SRV_NITZ_WAIT_UPDATE);

		if (mmi_idle_is_active())
{
			mmi_idle_display();
	    }
    }
    
}


/* NITZ MMI functions End */

#endif /* __MMI_NITZ__ */

