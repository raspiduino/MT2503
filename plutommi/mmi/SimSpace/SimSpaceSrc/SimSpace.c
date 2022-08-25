/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  SimSpace.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the SimSpace application.
 *
 *
 * Author: Digvijay Arya (mtk33160)
 * -------
 *  
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
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_include.h"
#include "MMI_features.h"
#if(MMI_MAX_SIM_NUM >= 3) && defined(__PLUTO_MMI_PACKAGE__)

#include "IdleGprot.h"
#include "Menucuigprot.h"
#include "ModeSwitchSrvGprot.h"
#include "ModeSwitchAppGprot.h"
#include "NwNameSrvGprot.h"
#include "SimSpaceGprot.h"
#include "mmi_frm_utility_gprot.h"


static MMI_ID g_setting_scr_grp_id;
MMI_BOOL sim_state[MMI_SIM_TOTAL];
extern void mmi_mode_switch_entry_dynamic_switch_screen(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_sim_space_get_nw_info
 * DESCRIPTION
 *  callback handler to get the network strings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sim_space_get_nw_info(S32 sim_index, U8 sim_state, wgui_cat9010_text_struct *sim_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_service_indication_struct service_indication;
    //mmi_sim_enum sim_idx[]={MMI_SIM1, MMI_SIM2, MMI_SIM3, MMI_SIM4}; 
    WCHAR line1[WGUI_CAT9010_TEXT_SIZE+1];
    WCHAR line2[WGUI_CAT9010_TEXT_SIZE+1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_idle_get_service_indication_string(mmi_frm_index_to_sim(sim_index), &service_indication);
    mmi_wcsncpy(sim_info->text_0, service_indication.line1, WGUI_CAT9010_TEXT_SIZE);
    mmi_wcsncpy(sim_info->text_1, service_indication.line2, WGUI_CAT9010_TEXT_SIZE);     

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_space_exit
 * DESCRIPTION
 *  Bak handler for SIM Space screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sim_space_exit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_group_close(g_setting_scr_grp_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_space_launch
 * DESCRIPTION
 *  launch function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sim_space_launch()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    mmi_id cui_menu_id;
    U8 temp[MMI_SIM_TOTAL];
    U8 i;
    mmi_sim_enum sim_idx[]={MMI_SIM1, MMI_SIM2, MMI_SIM3, MMI_SIM4}; 
    U8 *scrbuffer=NULL;
    S8 *lsk_string;
    srv_mode_switch_type_enum curr_mode;
    U8 mode_all[]={SRV_MODE_SWITCH_SIM1, SRV_MODE_SWITCH_SIM2 
                #if(MMI_MAX_SIM_NUM>=3)
                     ,SRV_MODE_SWITCH_SIM3
                #endif
                #if(MMI_MAX_SIM_NUM>=4)
                     ,SRV_MODE_SWITCH_SIM4
                #endif
                    };
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*if (mmi_frm_group_is_present(GRP_ID_IDLE_SIM_SPACE))
    {
        mmi_popup_display(
            get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
            MMI_EVENT_FAILURE,
            NULL);
        return;
    }*/


    g_setting_scr_grp_id = mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_IDLE_SIM_SPACE,
        NULL,
        NULL);
    mmi_frm_group_enter(GRP_ID_IDLE_SIM_SPACE, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    
  /*  mmi_frm_scrn_first_enter(
        GRP_ID_IDLE_SIM_SPACE,
        SCR_ID_IDLE_SIM_SPACE_VIEW,
        (FuncPtr)mmi_sim_space_show_app,
        NULL);
    */
    
    mmi_frm_scrn_enter(GRP_ID_IDLE_SIM_SPACE, SCR_ID_IDLE_SIM_SPACE_VIEW, NULL, (FuncPtr)mmi_sim_space_launch, MMI_FRM_FULL_SCRN);

    scrbuffer= mmi_frm_scrn_get_active_gui_buf();
    
    
    curr_mode = srv_mode_switch_get_current_mode();
    for(i=0; i<MMI_SIM_TOTAL; i++)
    {
        sim_state[i] = temp[i] = MMI_FALSE;
        if(srv_sim_ctrl_is_available(sim_idx[i]))
        {   
            if(curr_mode & mode_all[i])
            {
			    sim_state[i] = temp[i] = MMI_TRUE;
            }
        }
    }
    if(srv_mode_switch_is_network_service_available())
    {
        //EnableCenterSoftkey(NULL, IMG_GLOBAL_COMMON_CSK);
        lsk_string = GetString(STR_GLOBAL_SETTINGS);
    }
    else
    {
        lsk_string = NULL;
    }
    
    wgui_cat9010_show(
	        (WCHAR *)GetString(STR_ID_SIM_SPACE),  //WCHAR* title
        	NULL,                                  //PU8 title_icon
        	(WCHAR *)lsk_string,                   //WCHAR* left_softkey
        	NULL,                                  //PU8 left_softkey_icon
        	(WCHAR *)GetString(STR_GLOBAL_BACK),    //WCHAR* right_softkey
        	(PU8)GetImage(IMG_GLOBAL_BACK),         //PU8 right_softkey_icon
			mmi_sim_space_get_nw_info,              //wgui_cat9010_get_text_func_type get_text_func
			MMI_SIM_TOTAL,                          //S32 sim_count
			(U8 *)temp,                             //U8 *sim_state
			0,                                      //wgui_cat9010_type_enum screen_type
			0,                                      //U8  highlight_index
 			scrbuffer);                             //U8* gui_buffer
 			
 	//SetCenterSoftkeyFunction(mmi_mode_switch_entry_dynamic_switch_screen, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_mode_switch_entry_dynamic_switch_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_sim_space_exit, KEY_EVENT_UP);

}

mmi_ret mmi_sim_space_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;
    srv_nw_name_changed_evt_struct *name_chngd;
    S32 sim_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_ASSERT(event);
    if (!mmi_frm_group_is_present(GRP_ID_IDLE_SIM_SPACE))
        return;
    
    switch(evt->evt_id)
    {
        case EVT_ID_SRV_NW_NAME_CHANGED:
            name_chngd = (srv_nw_name_changed_evt_struct *)evt;
            sim_idx = mmi_frm_sim_to_index(name_chngd->sim);
            wgui_cat9010_update(sim_idx, sim_state[sim_idx]);
            break;
    
    }

return MMI_RET_OK;

}
/*****************************************************************************
 * FUNCTION
 *  mmi_sim_space_setting_hint_hdlr
 * DESCRIPTION
 *  launch function
 * PARAMETERS
 *  evt      [IN]    mmi_event_struct
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sim_space_setting_hint_hdlr(cui_menu_event_struct *evt)
{
	  /*cui_menu_set_item_hint(
			evt->sender_id, 
			MENU_ID_NETSET_NETWORK_SELECTION,
			(UI_string_type)mmi_hint_netsel_select_mode());*/

}

#if 0
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
                #if(GEMINI_PLUS>=3)
/* under construction !*/
                #endif
                #if(GEMINI_PLUS>=4)
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
#endif

#endif/* GEMINI_PLUS >= 3*/
