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
 * DataRoaming.c
 *
 * Project:
 * --------
 * MAUI
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
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_DATA_LOCK__

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "menucuigprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "mmi_rp_app_connectivity_mainmenu_def.h"
#include "DataLockSrvGprot.h"


/*****************************************************************************
 * Declarations
 *****************************************************************************/
static void mmi_data_roaming_launch(void);
static mmi_ret mmi_data_roaming_proc(mmi_event_struct *evt);
static void mmi_data_roaming_entry_main(MMI_ID parent_id);


/*****************************************************************************
 * FUNCTION
 *  mmi_data_roaming_highlight_hdlr
 * DESCRIPTION
 *  highlight hdlr for MENU_ID_DATA_ROAMING
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_data_roaming_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(mmi_data_roaming_launch, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_data_roaming_launch, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_data_roaming_launch
 * DESCRIPTION
 *  launch data roaming application
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_data_roaming_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID grp_id;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_id = mmi_frm_group_create_ex(GRP_ID_ROOT, 
							GRP_ID_AUTO_GEN, 
							mmi_data_roaming_proc, 
							NULL, 
							MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_data_roaming_entry_main(grp_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_data_roaming_proc
 * DESCRIPTION
 *  proc for data roaming
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_data_roaming_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_lock;
    mmi_menu_id highlight_menu;
    cui_menu_event_struct *menu_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_event = (cui_menu_event_struct*)evt;
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (menu_event->parent_menu_id == MENU_ID_DATA_ROAMING)
            {
                is_lock = srv_data_lock_network_roaming_get_setting();
                highlight_menu = MENU_ID_DATA_ROAMING_OFF + is_lock;
                cui_menu_set_currlist_highlighted_id(menu_event->sender_id, highlight_menu);
				cui_menu_set_default_title_image(
                    menu_event->sender_id, 
                    get_image(GetRootTitleIcon(MENU_ID_DATA_ROAMING)));
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
            if (menu_event->highlighted_menu_id == MENU_ID_DATA_ROAMING_ON)
            {
                is_lock = MMI_TRUE;
            }
            else
            {
                is_lock = MMI_FALSE;
            }
            srv_data_lock_network_roaming_set_setting(is_lock);
            mmi_popup_display(
                (WCHAR*)GetString(STR_GLOBAL_DONE),
                MMI_EVENT_SUCCESS,
                NULL);
            cui_menu_close(menu_event->sender_id);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_event->sender_id);
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_data_roaming_entry_main
 * DESCRIPTION
 *  entry main screen of data roaming
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_data_roaming_entry_main(MMI_ID parent_id)
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
                    MENU_ID_DATA_ROAMING,
                    MMI_TRUE,
                    NULL);
    cui_menu_set_default_left_softkey_by_id(menu_cui_id, STR_GLOBAL_OK);
    cui_menu_set_default_title_string_by_id(menu_cui_id, STR_ID_DATA_ROAMING);
    cui_menu_run(menu_cui_id);
}

#endif /* __MMI_DATA_LOCK__ */

