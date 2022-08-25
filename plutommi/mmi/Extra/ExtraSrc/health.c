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
 *  health.c
 *
 * Project:
 * -------- 
 *  
 *
 * Description:
 * ------------
 *  Parse Data Account Configuration.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_features.h"
#if defined(__MMI_BMI__) || defined(__MMI_MENSTRUAL__)
#include "menucuigprot.h"
#include "Bmi.h"
#include "Healthmenstural.h"
#include "mmi_rp_app_health_def.h"
#include "MMIDataType.h"
#include "wgui_categories_util.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "gui_data_types.h"
#include "GlobalConstants.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_general_types.h"
/* 
 * Local Function
 */
void mmi_health_entry_app(void);
static mmi_ret mmi_health_cui_event_proc(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  mmi_health_cui_event_proc
 * DESCRIPTION
 *  proc function for health.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_health_cui_event_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	cui_menu_event_struct *menu_evt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	/* Menu cui revise */
    menu_evt = (cui_menu_event_struct*)evt;  
    
    switch (menu_evt->evt_id)
    {
    	case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (menu_evt->parent_menu_id == EXTRA_HEALTH_MENU)
            { 
            	cui_menu_set_default_title_image(
					menu_evt->sender_id, 
					get_image(GetRootTitleIcon(EXTRA_HEALTH_MENU)));
				
            	/*cui_menu_set_item_image(
		            menu_evt->sender_id,
		            EXTRA_HEALTH_MENU_BMI,
		            IMG_GLOBAL_L1);
		        cui_menu_set_item_image(
		            menu_evt->sender_id,
		            EXTRA_HEALTH_MENU_MENSTRUAL,
		            IMG_GLOBAL_L2);*/
				cui_menu_set_default_left_softkey(menu_evt->sender_id, (UI_string_type)GetString(STR_GLOBAL_OK));
        	}
            break;
    	case EVT_ID_CUI_MENU_ITEM_HILITE:
			switch (menu_evt->highlighted_menu_id) 
			{
			#ifdef __MMI_BMI__
				case EXTRA_HEALTH_MENU_BMI:
					ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
					SetCenterSoftkeyFunction(mmi_bmi_pre_entry_welcome_screen, KEY_EVENT_UP);					
					break;
			#endif
			
			#ifdef __MMI_MENSTRUAL__
				case EXTRA_HEALTH_MENU_MENSTRUAL:
					isbackfromresult = 0;
					ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
				    SetCenterSoftkeyFunction(mmi_mens_pre_entry_welcome_screen, KEY_EVENT_UP);
					break;
			#endif
				default:
					break;
        	}
			break;
		case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch (menu_evt->highlighted_menu_id)
            {
            #ifdef __MMI_BMI__
            	case EXTRA_HEALTH_MENU_BMI:
					mmi_bmi_pre_entry_welcome_screen();
					break;
			#endif
			
			#ifdef __MMI_MENSTRUAL__
				case EXTRA_HEALTH_MENU_MENSTRUAL:
					mmi_mens_pre_entry_welcome_screen();
					break;
			#endif
				default:
					break;
        	}
            break;
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:			
			cui_menu_close(menu_evt->sender_id);
			break;
		default:
			break;
	}
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_health_entry_app
 * DESCRIPTION
 *  Display list of health applications.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_health_entry_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID health_grp_id;
	mmi_id health_menu_cui_id;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    health_grp_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_health_cui_event_proc, NULL);
    mmi_frm_group_enter(health_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	health_menu_cui_id = cui_menu_create(
                    health_grp_id,
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_APPMAIN,
                    EXTRA_HEALTH_MENU,
                    MMI_TRUE,
                    NULL);   
    cui_menu_run(health_menu_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_health_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Health menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_health_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetLeftSoftkeyFunction(mmi_health_entry_app, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_health_entry_app, KEY_EVENT_UP);
}

#endif /* defined(__MMI_BMI__)|| defined(__MMI_MENSTRUAL__) */ 

