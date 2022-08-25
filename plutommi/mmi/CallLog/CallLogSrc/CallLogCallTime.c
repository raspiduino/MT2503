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
*  CallLogCallTime.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*   This file is intends for show call duration
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_include.h"
#include "MMI_features.h"
#ifdef __MMI_CLOG_CALL_TIME__
/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_utility_gprot.h"
#include "menucuigprot.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "GlobalConstants.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "CommonScreens.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
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
#define MMI_CLOG_CTIME_MENU_ITEMS   (4)
/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

typedef struct
{
    U16 Hour;
    U8 Min;
    U8 Sec;
} mmi_clog_ctime_struct;

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static void mmi_clog_ctime_sec_2_mytime(U32 call_duration_sec, mmi_clog_ctime_struct *call_duration);
//static MMI_RET mmi_clog_enter_ctime_proc(mmi_event_struct *evt);
//static void mmi_clog_ctime_reset_confirm(void);
static void mmi_clog_ctime_reset_hdlr(void);


#if (MMI_MAX_SIM_NUM >= 3)

#include "wgui_categories_list.h"


/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
//static mmi_sim_enum g_mmi_clog_ctime_curr_sim;

static WCHAR g_ctime_buffer[400]={0};

static U16 g_clog_ctime_reset_type;


/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/

static void mmi_clog_enter_ctime_scrn(void);




static void mmi_clog_ctime_op_select_hdlr(cui_menu_event_struct *menu_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID str_id = STR_ID_CLOG_CTIME_IF_RESET_ALL;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	  g_clog_ctime_reset_type = menu_item->highlighted_menu_id;
	  
	switch (menu_item->highlighted_menu_id)
	{
		case MENU_ID_CLOG_CTIME_RESET_ALL_SIM1:
			str_id = STR_ID_CLOG_CTIME_IF_RESET_ALL_SIM1;
			break;

	#if (MMI_MAX_SIM_NUM >= 2) 
		case MENU_ID_CLOG_CTIME_RESET_ALL_SIM2:
			str_id = STR_ID_CLOG_CTIME_IF_RESET_ALL_SIM2;
			break;
	#endif
			
	#if (MMI_MAX_SIM_NUM >= 3) 
		case MENU_ID_CLOG_CTIME_RESET_ALL_SIM3:
			str_id = STR_ID_CLOG_CTIME_IF_RESET_ALL_SIM3;
			break;
	#endif
	
	#if (MMI_MAX_SIM_NUM >= 4) 
		case MENU_ID_CLOG_CTIME_RESET_ALL_SIM4:
			str_id = STR_ID_CLOG_CTIME_IF_RESET_ALL_SIM4;
			break;
	#endif

		default:
		break;
	}
	  
	  mmi_clog_confirm(
	        CNFM_TYPE_YESNO,
	        str_id,
	        MMI_EVENT_QUERY,
	        GRP_ID_CLOG_CALL_TIME_OPTION,
	        NULL,
	        MMI_CLOG_ALERT_FLAG_AUTO_DISMISS);

}


/* SIM3, SIM4 Call timers UE enhance */
static MMI_RET mmi_clog_ctimes_op_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_clog_ctime_op_select_hdlr((cui_menu_event_struct*) evt);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

		   
	    case EVT_ID_ALERT_QUIT:
	    {
		   mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;
	   
		   switch (alert->result)
		   {
			   case MMI_ALERT_CNFM_YES:
				   mmi_clog_ctime_reset_hdlr();
				   break;
	   
			   case MMI_ALERT_CNFM_NO:
			   case MMI_ALERT_NORMAL_EXIT:
			   default:
				   break;
		   }
	    }

        default:
            break;
     	}
     	return MMI_RET_OK;
}


static void mmi_clog_ctime_option()
{
	//mmi_id parent_gid;
	mmi_id cui_id;
	
	mmi_frm_group_create_ex(GRP_ID_CLOG_CALL_TIME, 
		GRP_ID_CLOG_CALL_TIME_OPTION, mmi_clog_ctimes_op_group_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	
	cui_id = cui_menu_create(
                GRP_ID_CLOG_CALL_TIME_OPTION,
                CUI_MENU_SRC_TYPE_RESOURCE,
                CUI_MENU_TYPE_OPTION,
                MENU_ID_CLOG_CTIME_OPTION,
                MMI_TRUE,
                NULL);

	cui_menu_set_default_title_by_id(
        cui_id,
        STR_ID_CLOG_CALL_TIME,
        GetRootTitleIcon(MAIN_MENU_CALL_LOG));

	 cui_menu_run(cui_id);
}


static void mmi_clog_ctime_close()
{
	g_ctime_buffer[0] = 0;
    mmi_frm_group_close(GRP_ID_CLOG_CALL_TIME);
}


static void mmi_clog_ctime_show_text()
{
	S32 i;
    S32 max_loop = 1;
    //S32 menu_idx = 0;
    mmi_clog_ctime_struct t;
    WCHAR temp_str[4][MAX_SUBMENU_CHARACTERS]={0};
	WCHAR tmp[50] = {0};
    srv_clog_ctime_data_struct ctime[4];

	U8 *guiBuffer;

	const MMI_ID string_sim[] = 
			{
			
					STR_ID_CLOG_CTIME_SIM1_LAST_CALL,
					STR_ID_CLOG_CTIME_SIM1_ALL_DIALED_CALL,
					STR_ID_CLOG_CTIME_SIM1_ALL_RECIVED_CALL,
					STR_ID_CLOG_CTIME_SIM2_LAST_CALL,
					STR_ID_CLOG_CTIME_SIM2_ALL_DIALED_CALL,
					STR_ID_CLOG_CTIME_SIM2_ALL_RECIVED_CALL,
					STR_ID_CLOG_CTIME_SIM3_LAST_CALL,
					STR_ID_CLOG_CTIME_SIM3_ALL_DIALED_CALL,
					STR_ID_CLOG_CTIME_SIM3_ALL_RECIVED_CALL,
				#if (MMI_MAX_SIM_NUM >= 4)
					STR_ID_CLOG_CTIME_SIM4_LAST_CALL,
					STR_ID_CLOG_CTIME_SIM4_ALL_DIALED_CALL,
					STR_ID_CLOG_CTIME_SIM4_ALL_RECIVED_CALL,
				#endif
			};



    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* get call times for service */
    srv_clog_ctime_get_data(MMI_SIM1, SRV_CLOG_CALL_TYPE_VOICE, SRV_CLOG_CTIME_OP_TYPE_SINGLE, &ctime[0], 1);
    srv_clog_ctime_get_data(MMI_SIM2, SRV_CLOG_CALL_TYPE_VOICE, SRV_CLOG_CTIME_OP_TYPE_SINGLE, &ctime[1], 1);
	srv_clog_ctime_get_data(MMI_SIM3, SRV_CLOG_CALL_TYPE_VOICE, SRV_CLOG_CTIME_OP_TYPE_SINGLE, &ctime[2], 1);
	max_loop = 3;

#if (MMI_MAX_SIM_NUM >= 4)
	 srv_clog_ctime_get_data(MMI_SIM4, SRV_CLOG_CALL_TYPE_VOICE, SRV_CLOG_CTIME_OP_TYPE_SINGLE, &ctime[3], 1);
	 max_loop = 4;
#endif


#if 0
#ifdef __MMI_VOIP__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_VOIP__ */ 
#endif


	/* format text string */

	/* i=0: indicate sim1, i=1: indicate sim2, i=2: indicate voip */
	for (i = 0; i < max_loop; i++)
	{
		/* For last call duration */
		if (ctime[i].last_type == SRV_CLOG_CLT_DIALED)
		{
			mmi_clog_ctime_sec_2_mytime(ctime[i].last_dialed, &t);
		}
		else
		{
			mmi_clog_ctime_sec_2_mytime(ctime[i].last_recved, &t);
		}
		kal_wsprintf(temp_str[0], "%02d:%02d:%02d", t.Hour, t.Min, t.Sec);
		//cui_menu_set_item_hint(g_clog_ctime_cui, submenu[menu_idx++], temp_str);

		/* For all dialed duration */
		mmi_clog_ctime_sec_2_mytime(ctime[i].total_dialed, &t);
		kal_wsprintf(temp_str[1], "%02d:%02d:%02d", t.Hour, t.Min, t.Sec);
		//cui_menu_set_item_hint(g_clog_ctime_cui, submenu[menu_idx++], temp_str);

		/* For all recvd duration */
		mmi_clog_ctime_sec_2_mytime(ctime[i].total_recved, &t);
		kal_wsprintf(temp_str[2], "%02d:%02d:%02d", t.Hour, t.Min, t.Sec);
		//cui_menu_set_item_hint(g_clog_ctime_cui, submenu[menu_idx++], temp_str);

		/* For reset menu */
		//menu_idx++;


		kal_wsprintf(tmp,"%w\n",GetString(string_sim[i*3]));
			mmi_wcscat(g_ctime_buffer, tmp);
			mmi_wcscat(g_ctime_buffer, temp_str[0]);
			kal_wsprintf(tmp,"\n");
			mmi_wcscat(g_ctime_buffer, tmp);
			
		kal_wsprintf(tmp,"%w\n",GetString(string_sim[i*3+1]));
			mmi_wcscat(g_ctime_buffer, tmp);
			mmi_wcscat(g_ctime_buffer, temp_str[1]);
			kal_wsprintf(tmp,"\n");
			mmi_wcscat(g_ctime_buffer, tmp);
			
		kal_wsprintf(tmp,"%w\n",GetString(string_sim[i*3+2]));
			mmi_wcscat(g_ctime_buffer, tmp);
			mmi_wcscat(g_ctime_buffer, temp_str[2]);
			kal_wsprintf(tmp,"\n");
		kal_wsprintf(tmp,"\n----------------\n");
			mmi_wcscat(g_ctime_buffer, tmp);


	}

	 guiBuffer = mmi_frm_scrn_get_active_gui_buf();
	

	    ShowCategory74Screen(
        STR_ID_CLOG_CALL_TIME,
        GetRootTitleIcon(MAIN_MENU_CALL_LOG),
        STR_GLOBAL_OPTIONS,
        NULL,
        STR_GLOBAL_BACK,
        NULL,
        (U8*) g_ctime_buffer,
        (S32) (mmi_wcslen(g_ctime_buffer) + 1),
        guiBuffer);

		SetLeftSoftkeyFunction( mmi_clog_ctime_option, KEY_EVENT_UP);
                SetKeyHandler(mmi_clog_ctime_option, KEY_CSK, KEY_EVENT_UP);

		SetRightSoftkeyFunction( mmi_clog_ctime_close, KEY_EVENT_UP);
}

void mmi_clog_exit_ctime(MMI_ID parent_gid)
{
	g_ctime_buffer[0] = 0;
}

static MMI_RET mmi_clog_ctime_proc(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_ctime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_enter_ctime(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* Show text view */
	mmi_frm_group_create_ex(parent_gid, GRP_ID_CLOG_CALL_TIME, mmi_clog_ctime_proc, NULL, MMI_FRM_NODE_NONE_FLAG); //MMI_FRM_NODE_SMART_CLOSE_FLAG

	mmi_clog_enter_ctime_scrn();
}

void mmi_clog_enter_ctime_scrn(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												 */
	/*----------------------------------------------------------------*/
	 S32 ret;
    
	/*----------------------------------------------------------------*/
	/* Code Body 													 */
	/*----------------------------------------------------------------*/

	ret = mmi_frm_scrn_enter(
		GRP_ID_CLOG_CALL_TIME,
		SCR_ID_CLOG_VIEWER,
		(FuncPtr) mmi_clog_exit_ctime,
		(FuncPtr) mmi_clog_enter_ctime_scrn,
	MMI_FRM_FULL_SCRN);

	if (!ret)
		return; 

	/*Set CSK icon*/
	EnableCenterSoftkey(
            0,
            IMG_GLOBAL_OPTION_CSK);

	redraw_center_softkey();
	

	mmi_clog_ctime_show_text();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ctime_reset_hdlr
 * DESCRIPTION
 *  call time common reset counter value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ctime_reset_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

	/* Sim 1  */	
    if (g_clog_ctime_reset_type == MENU_ID_CLOG_CTIME_RESET_ALL_SIM1)
    {
        srv_clog_ctime_reset_data(MMI_SIM1, SRV_CLOG_CALL_TYPE_NON_VOIP, SRV_CLOG_CTIME_FIELD_ALL);
    }
	/* Sim 2 */
    else if (g_clog_ctime_reset_type == MENU_ID_CLOG_CTIME_RESET_ALL_SIM2)
    {
        srv_clog_ctime_reset_data(MMI_SIM2, SRV_CLOG_CALL_TYPE_NON_VOIP, SRV_CLOG_CTIME_FIELD_ALL);
    }
	/* Sim 3 */
    else if (g_clog_ctime_reset_type == MENU_ID_CLOG_CTIME_RESET_ALL_SIM3)
    {
        srv_clog_ctime_reset_data(MMI_SIM3, SRV_CLOG_CALL_TYPE_NON_VOIP, SRV_CLOG_CTIME_FIELD_ALL);
    }
#if (MMI_MAX_SIM_NUM >= 4)

	/* Sim 4 */
    else if (g_clog_ctime_reset_type == MENU_ID_CLOG_CTIME_RESET_ALL_SIM4)
    {
        srv_clog_ctime_reset_data(MMI_SIM4, SRV_CLOG_CALL_TYPE_NON_VOIP, SRV_CLOG_CTIME_FIELD_ALL);
    }

#endif

	else
	{
		return;
	}
	
	 mmi_clog_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_CLOG_CALL_TIME, NULL);

}

#else /* (MMI_MAX_SIM_NUM >= 3) */

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
static U16 g_clog_ctime_reset_type;
static MMI_ID g_clog_ctime_cui = GRP_ID_INVALID;

static WCHAR g_ctime_buffer[400]={0};

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/

void mmi_clog_enter_ctime_scrn(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ctime_op_select_hdlr
 * DESCRIPTION
 *  Option group slect handler
 * PARAMETERS
 *  cui_menu_event_struct *menu_item  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ctime_op_select_hdlr(cui_menu_event_struct *menu_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_STR_ID str_id = STR_ID_CLOG_CTIME_IF_RESET_ALL;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	  g_clog_ctime_reset_type = menu_item->highlighted_menu_id;
	  

	switch (menu_item->highlighted_menu_id)
	{
		case MENU_ID_CLOG_CTIME_RESET_ALL_SIM1:
			str_id = STR_ID_CLOG_CTIME_IF_RESET_ALL_SIM1;
			break;

	#if (MMI_MAX_SIM_NUM >= 2) 
		case MENU_ID_CLOG_CTIME_RESET_ALL_SIM2:
			str_id = STR_ID_CLOG_CTIME_IF_RESET_ALL_SIM2;
			break;
	#endif
			
	#if (MMI_MAX_SIM_NUM >= 3) 
		case MENU_ID_CLOG_CTIME_RESET_ALL_SIM3:
			str_id = STR_ID_CLOG_CTIME_IF_RESET_ALL_SIM3;
			break;
	#endif
	
	#if (MMI_MAX_SIM_NUM >= 4) 
		case MENU_ID_CLOG_CTIME_RESET_ALL_SIM4:
			str_id = STR_ID_CLOG_CTIME_IF_RESET_ALL_SIM4;
			break;
	#endif

		default:
		break;
	}
	  
	  mmi_clog_confirm(
	        CNFM_TYPE_YESNO,
	        str_id,
	        MMI_EVENT_QUERY,
	        GRP_ID_CLOG_CALL_TIME_OPTION,
	        NULL,
	        MMI_CLOG_ALERT_FLAG_AUTO_DISMISS);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ctimes_op_group_proc
 * DESCRIPTION
 *  Option group proc
 * PARAMETERS
 *  NULL  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_clog_ctimes_op_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_clog_ctime_op_select_hdlr((cui_menu_event_struct*) evt);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

		   
	    case EVT_ID_ALERT_QUIT:
	    {
		   mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;
	   
		   switch (alert->result)
		   {
			   case MMI_ALERT_CNFM_YES:
				   mmi_clog_ctime_reset_hdlr();
				   break;
	   
			   case MMI_ALERT_CNFM_NO:
			   case MMI_ALERT_NORMAL_EXIT:
			   default:
				   break;
		   }
	    }

        default:
            break;
     	}
     	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ctime_option
 * DESCRIPTION
 *  enter ctime option
 * PARAMETERS
 *  NULL  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ctime_option()
{
	//mmi_id parent_gid;
	mmi_id cui_id;
	
	mmi_frm_group_create_ex(GRP_ID_CLOG_CALL_TIME, 
		GRP_ID_CLOG_CALL_TIME_OPTION, mmi_clog_ctimes_op_group_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	
	cui_id = cui_menu_create(
                GRP_ID_CLOG_CALL_TIME_OPTION,
                CUI_MENU_SRC_TYPE_RESOURCE,
                CUI_MENU_TYPE_OPTION,
                MENU_ID_CLOG_CTIME_OPTION,
                MMI_TRUE,
                NULL);

	cui_menu_set_default_title_by_id(
        cui_id,
        STR_ID_CLOG_CALL_TIME,
        GetRootTitleIcon(MAIN_MENU_CALL_LOG));

	 cui_menu_run(cui_id);
}


static void mmi_clog_ctime_close()
{
	g_ctime_buffer[0] = 0;

    mmi_frm_group_close(GRP_ID_CLOG_CALL_TIME);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ctime_show_text
 * DESCRIPTION
 *  Show ctime text view
 * PARAMETERS
 *  NULL  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ctime_show_text()
{
	S32 i;
    S32 max_loop = 1;
    //S32 menu_idx = 0;
    mmi_clog_ctime_struct t;
    WCHAR temp_str[3][MAX_SUBMENU_CHARACTERS]={0};
	
	WCHAR tmp[50] = {0};
    srv_clog_ctime_data_struct ctime[3];

	U8 *guiBuffer;

	const MMI_ID string_sim[] = 
		{
			#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
			#else
				STR_ID_CLOG_CTIME_SIM1_LAST_CALL,
				STR_ID_CLOG_CTIME_SIM1_ALL_DIALED_CALL,
				STR_ID_CLOG_CTIME_SIM1_ALL_RECIVED_CALL,
			#endif
		};


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* get call times for service */
    srv_clog_ctime_get_data(MMI_SIM1, SRV_CLOG_CALL_TYPE_VOICE, SRV_CLOG_CTIME_OP_TYPE_SINGLE, &ctime[0], 1);
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */ 
#ifdef __MMI_VOIP__
    max_loop = 3;
    srv_clog_ctime_get_data(MMI_SIM1, SRV_CLOG_CALL_TYPE_VOIP, SRV_CLOG_CTIME_OP_TYPE_SINGLE, &ctime[2], 1);
#endif /* __MMI_VOIP__ */ 

	/* format text string */

	/* i=0: indicate sim1, i=1: indicate sim2, i=2: indicate voip */
	for (i = 0; i < max_loop; i++)
	{
		/* For last call duration */
		if (ctime[i].last_type == SRV_CLOG_CLT_DIALED)
		{
			mmi_clog_ctime_sec_2_mytime(ctime[i].last_dialed, &t);
		}
		else
		{
			mmi_clog_ctime_sec_2_mytime(ctime[i].last_recved, &t);
		}
		kal_wsprintf(temp_str[0], "%02d:%02d:%02d", t.Hour, t.Min, t.Sec);

		/* For all dialed duration */
		mmi_clog_ctime_sec_2_mytime(ctime[i].total_dialed, &t);
		kal_wsprintf(temp_str[1], "%02d:%02d:%02d", t.Hour, t.Min, t.Sec);

		/* For all recvd duration */
		mmi_clog_ctime_sec_2_mytime(ctime[i].total_recved, &t);
		kal_wsprintf(temp_str[2], "%02d:%02d:%02d", t.Hour, t.Min, t.Sec);

		/* For reset menu */
		//menu_idx++;

		if (max_loop <= 2 )
		{
			kal_wsprintf(tmp,"%w\n",GetString(string_sim[i*3]));
			mmi_wcscat(g_ctime_buffer, tmp);
			mmi_wcscat(g_ctime_buffer, temp_str[0]);
			kal_wsprintf(tmp,"\n");
			mmi_wcscat(g_ctime_buffer, tmp);
			
			kal_wsprintf(tmp,"%w\n",GetString(string_sim[i*3+1]));
			mmi_wcscat(g_ctime_buffer, tmp);
			mmi_wcscat(g_ctime_buffer, temp_str[1]);
			kal_wsprintf(tmp,"\n");
			mmi_wcscat(g_ctime_buffer, tmp);
			
			kal_wsprintf(tmp,"%w\n",GetString(string_sim[i*3+2]));
			mmi_wcscat(g_ctime_buffer, tmp);
			mmi_wcscat(g_ctime_buffer, temp_str[2]);
			kal_wsprintf(tmp,"\n");
			kal_wsprintf(tmp,"\n----------------\n");
			mmi_wcscat(g_ctime_buffer, tmp);
		}
	}

	 guiBuffer = mmi_frm_scrn_get_active_gui_buf();
	

	    ShowCategory74Screen(
		STR_ID_CLOG_CALL_TIME,
		GetRootTitleIcon(MAIN_MENU_CALL_LOG),
        STR_GLOBAL_OPTIONS,
        NULL,
        STR_GLOBAL_BACK,
        NULL,
        (U8*) g_ctime_buffer,
        (S32) (mmi_wcslen(g_ctime_buffer) + 1),
        guiBuffer);

		SetLeftSoftkeyFunction( mmi_clog_ctime_option, KEY_EVENT_UP);
		SetKeyHandler(mmi_clog_ctime_option, KEY_CSK, KEY_EVENT_UP);
		SetRightSoftkeyFunction( mmi_clog_ctime_close, KEY_EVENT_UP);
}

void mmi_clog_exit_ctime(MMI_ID parent_gid)
{
	g_ctime_buffer[0] = 0;
}

static MMI_RET mmi_clog_ctime_proc(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_ctime
 * DESCRIPTION
 *  Entry screen for call times (at most include sim1 & sim2 & voip last/all sent/all recvd
 * PARAMETERS
 *  parent_gid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_enter_ctime(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* create group */
	
	/* Show text view */
	mmi_frm_group_create_ex(parent_gid, GRP_ID_CLOG_CALL_TIME, mmi_clog_ctime_proc, NULL, MMI_FRM_NODE_NONE_FLAG); //MMI_FRM_NODE_SMART_CLOSE_FLAG
	
	mmi_clog_enter_ctime_scrn();
}

void mmi_clog_enter_ctime_scrn()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(
        GRP_ID_CLOG_CALL_TIME,
        SCR_ID_CLOG_VIEWER,      
        (FuncPtr) mmi_clog_exit_ctime,
		(FuncPtr) mmi_clog_enter_ctime_scrn,
	MMI_FRM_FULL_SCRN);

	if (!ret)
		return; 

		/*Set CSK icon*/
	EnableCenterSoftkey(
            0,
            IMG_GLOBAL_OPTION_CSK);

	redraw_center_softkey();

	mmi_clog_ctime_show_text();
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ctime_reset_hdlr
 * DESCRIPTION
 *  call time common reset counter value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ctime_reset_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* Sim 1 only */	
    if (g_clog_ctime_reset_type == MENU_ID_CLOG_CTIME_RESET_ALL_SIM1)
    {
        srv_clog_ctime_reset_data(MMI_SIM1, SRV_CLOG_CALL_TYPE_NON_VOIP, SRV_CLOG_CTIME_FIELD_ALL);
    }

	/* Dual SIM */
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */ 

    else
    {
        return;
    }
    mmi_clog_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_CLOG_CALL_TIME, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ctime_update_duration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_ctime_update_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_refresh_currlist(g_clog_ctime_cui);
}

#endif /* (MMI_MAX_SIM_NUM >= 3) */


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ctime_sec_2_mytime
 * DESCRIPTION
 *  transfer second to mytime type only for show hintdata
 * PARAMETERS
 *  call_duration_sec       [IN]        
 *  call_duration           [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ctime_sec_2_mytime(U32 call_duration_sec, mmi_clog_ctime_struct *call_duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(call_duration, 0, sizeof(mmi_clog_ctime_struct));

    call_duration->Hour = call_duration_sec / 3600;
    call_duration->Min = call_duration_sec % 3600 / 60;
    call_duration->Sec = call_duration_sec % 60;

}


#endif /* __MMI_CLOG_CALL_TIME__ */


