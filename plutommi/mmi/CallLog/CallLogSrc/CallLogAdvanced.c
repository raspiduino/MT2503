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
*  CallLogMisc.c
*
* Project:
* --------
*  MAUI
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
#include "MMIDataType.h"

#ifdef __MMI_CLOG_ACCESSORIES__

#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "menucuigprot.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "GlobalResDef.h"
#include "CallLogConfig.h"
#include "CallLogProt.h"
#include "mmi_rp_app_calllog_def.h"


/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
#ifdef __MMI_CLOG_TAB_SUPPORT__
static MMI_RET mmi_clog_enter_advanced_proc(mmi_event_struct *evt);
#endif
/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

#ifdef __MMI_CLOG_TAB_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_advanced
 * DESCRIPTION
 *  Entry function to display advanced screen for sub module
 * PARAMETERS
 *  parent_gid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_enter_advanced(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(parent_gid, GRP_ID_CLOG_ADVANCED, mmi_clog_enter_advanced_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui = cui_menu_create(
            GRP_ID_CLOG_ADVANCED,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_APPSUB,
            MENU_ID_CLOG_ADVANCED,
            MMI_TRUE,
            NULL);

    cui_menu_set_default_title_by_id(cui, STR_GLOBAL_ADVANCED, GetRootTitleIcon(MAIN_MENU_CALL_LOG));
    cui_menu_set_default_left_softkey_by_id(cui, STR_GLOBAL_OK);

    cui_menu_run(cui);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_advanced_proc
 * DESCRIPTION
 *  proc of menu cui.
 *  It needs to handle the menu cui event like entry, select and exit.
 * PARAMETERS
 *  evt     [IN]        Event structure pointer
 * RETURNS
 *  MMI_RET_OK: process successfully
 *  Others: process fail
 *****************************************************************************/
static MMI_RET mmi_clog_enter_advanced_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_clog_enter_accessories(menu_evt->highlighted_menu_id, GRP_ID_CLOG_ADVANCED);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        default:
        {
            break;
        }
    }

    return MMI_RET_OK;
}

#endif /* __MMI_CLOG_TAB_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_accessories
 * DESCRIPTION
 * 
 * PARAMETERS
 *  menu_id        [IN]      
 *  parent_gid     [IN]      
 * RETURNS
 *  
 *  
 *****************************************************************************/
S32 mmi_clog_enter_accessories(MMI_MENU_ID menu_id, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL skip = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(menu_id)
    {
#ifdef __MMI_CLOG_CALL_TIME__        
        case MENU_ID_CLOG_CALL_TIME:
            mmi_clog_enter_ctime(parent_gid);
            break;
#endif /* __MMI_CLOG_CALL_TIME__ */ 

#ifdef __MMI_CLOG_CALL_COST__
        case MENU_ID_CLOG_CALL_COST:
            mmi_clog_enter_ccost(parent_gid);
            break;
#endif /* __MMI_CLOG_CALL_COST__ */

#ifdef __MMI_CLOG_SMS_COUNT__       
        case MENU_ID_CLOG_SMS_COUNT:
            mmi_clog_enter_sms_counter(parent_gid);
            break;
#endif /* __MMI_CLOG_SMS_COUNT__ */
        
#ifdef __MMI_CLOG_GPRS_COUNT__
        case MENU_ID_CLOG_GPRS_COUNT:
            mmi_clog_enter_gprs_counter(parent_gid);
        break;
#endif /* __MMI_CLOG_GPRS_COUNT__ */ 

        default: 
            skip = MMI_TRUE;
            break;
    }

    return skip;
}

#endif /* __MMI_CLOG_ACCESSORIES__ */



