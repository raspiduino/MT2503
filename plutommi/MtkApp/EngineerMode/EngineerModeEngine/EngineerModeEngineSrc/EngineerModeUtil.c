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
 *  EngineerModeStorage.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#include "EngineerModeUtil.h"
#ifdef __MMI_ENGINEER_MODE__ 

#if defined(COSMOS_EM_INTERNAL_DCM)
#include "dcmgr.h"
#elif defined (PLUTO_EM_INTERNAL_DCM)
#include "MMI_ap_dcm_config.h"  
#endif /* COSMOS_EM_INTERNAL_DCM */

#if defined(PLUTO_EM_INTERNAL_DCM)
#pragma arm section rodata = "DYNAMIC_CODE_EM_RODATA" , code = "DYNAMIC_CODE_EM_ROCODE"
#elif defined(COSMOS_EM_INTERNAL_DCM)
#pragma arm section rodata = "DYNAMIC_CODE_COSMOS_EM_RODATA" , code = "DYNAMIC_CODE_COSMOS_EM_ROCODE"
#endif /* PLUTO_EM_INTERNAL_DCM */ 


#include "MMIDataType.h"
#include "wgui_categories_list.h"
#include "EngineerModeResDef.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "mmi_res_range_def.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_popup.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "stack_msgs.h"
#include "mmi_frm_history_gprot.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "stack_common.h"
#include "nvram_data_items.h"
#include "mmi_frm_nvram_gprot.h"
#include "l4c_common_enum.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "gui_data_types.h"
#include "custom_events_notify.h"
#include "CommonScreens.h"
#include "UcmSrvGprot.h"
#include "dcl.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "ModeSwitchSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "EngineerModeDef.h"
#include "EngineerModeUtil.h"
#include "EngineerModeGprot.h"
#include "EngineerModeCommUI.h"
#include "mmi_rp_app_engineermode1_def.h"
#include "ps_public_enum.h"
#include "SimCtrlSrvGprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
U8 currentHighlightIndex;

//static U8 g_mmi_em_fresh_scrn_flag = 0;

MMI_ID g_mmi_em_main_menu_id = 0;

static FuncPtr g_em_dualmode_switch_callback;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

extern MMI_ID g_em_root_group_id;

/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/***************************************************************************** 
 * Global Function
 *****************************************************************************/
extern void ShowCategory64Screen(U16 message, U16 message_icon, U8 *history_buffer);

static mmi_ret mmi_em_dualmode_switch_callback(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  SetHighlightIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetHighlightIndex(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentHighlightIndex = (U8) nIndex;
}


void mmi_em_popup_by_str(MMI_ID str_id, mmi_event_notify_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id = mmi_em_get_root_group();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple_ext(str_id, event_type, grp_id, NULL);
}


void mmi_em_popup(MMI_ID gid, MMI_ID title_id, mmi_event_notify_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple_ext(title_id, event_type, gid, NULL);
}


void mmi_em_display_confirm_internal(MMI_ID group_id, mmi_proc_func callback, mmi_confirm_property_struct *arg,mmi_confirm_type_enum type)
{
    mmi_confirm_property_init(arg, type);
    arg->callback = callback;
    arg->parent_id = group_id;
    arg->f_auto_map_empty_softkey =  MMI_FALSE;
}


void mmi_em_display_confirm(MMI_STR_ID title_id, MMI_ID group_id, mmi_event_notify_enum event_type, mmi_proc_func callback)
{
    mmi_em_display_confirm_by_type(title_id, group_id, CNFM_TYPE_YESNO, event_type, callback);
}


void mmi_em_display_confirm_by_type(MMI_STR_ID title_id, MMI_ID group_id, mmi_confirm_type_enum type, mmi_event_notify_enum event_type, mmi_proc_func callback)
{    
    mmi_confirm_property_struct arg;

    mmi_em_display_confirm_internal(group_id, callback, &arg, type);

    mmi_confirm_display_ext(title_id, event_type, &arg);
}


void mmi_em_display_confirm_by_str(WCHAR* title, MMI_ID group_id, mmi_event_notify_enum event_type, mmi_proc_func callback)
{    
    mmi_confirm_property_struct arg;

    mmi_em_display_confirm_internal(group_id, callback, &arg, CNFM_TYPE_YESNO);

    mmi_confirm_display(title, event_type, &arg);
}


MMI_ID mmi_em_get_main_menu_id(void)
{
    return g_mmi_em_main_menu_id;
}

void mmi_em_set_main_menu_id(MMI_ID menu_id)
{
	g_mmi_em_main_menu_id = menu_id;
}


void mmi_em_shutdown(void)
{
    srv_shutdown_normal_start(APP_ENGINEERMODE1);
}

void mmi_em_shutdown_exit_system(void)
{
	srv_shutdown_exit_system(APP_ENGINEERMODE1);
}

/*****************************************************************************
 * FUNCTION
 *  EngineerModeSuccessRebootNotice
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stringId        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSuccessRebootNotice(U16 stringId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(mmi_em_get_root_group(), GLOBAL_SCR_DUMMY, NULL, NULL,
        MMI_FRM_FULL_SCRN))
    {
        return;
    }
    ShowCategory64Screen(stringId, IMG_GLOBAL_WARNING, 0);
    StartTimer(EM_NOTIFYDURATION_TIMER, 3000, mmi_em_shutdown);

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
}


#define EM_MSG_HANDLER

/*****************************************************************************
 * FUNCTION
 *  EngineerModeSetSleepModeReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSetSleepModeReq(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_sleep_mode_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_set_sleep_mode_req_struct));
    if (index == 0)
        msg_p->on_off = KAL_TRUE;
    else
        msg_p->on_off = KAL_FALSE;

    EngineerModeSendMsg(MSG_ID_MMI_EQ_SET_SLEEP_MODE_REQ, msg_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSendMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         
 *  peer_buf_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSendMsg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm((oslModuleType) MOD_L4C, (oslMsgType)msg_id, 
                        (oslParaType*)local_param_ptr, (oslPeerBuffType*)peer_buf_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSendMsg_Check_Prefer_SIM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         
 *  peer_buf_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSendMsg_Check_Prefer_SIM(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__        
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #ifdef __MMI_DUAL_SIM_SINGLE_CALL__ */
/* under construction !*/
#endif

	    /*----------------------------------------------------------------*/
		/* Local Variables												  */
		/*----------------------------------------------------------------*/
		U16 source_id = MOD_L4C;
		
		/*----------------------------------------------------------------*/
		/* Code Body													  */
		/*----------------------------------------------------------------*/
#if defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM > 1)

			U8	 buffer[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
			//S32 count;
		
			ReadRecordSlim(NVRAM_EF_SYS_CACHE_OCTET_LID,
				   NVRAM_SYS_FLIGHTMODE_STATE, 
				   (void*)buffer, 
				   NVRAM_EF_SYS_CACHE_OCTET_SIZE);
	
			switch(buffer[L4C_SETTING_DUAL_SIM_UART])
			{
				case RMMI_UART_TO_SIM1:
					source_id = MOD_L4C;
					break;
        #if (MMI_MAX_SIM_NUM >= 2)
				case RMMI_UART_TO_SIM2:
					source_id = MOD_L4C_2;
					break;
        #endif
        #if (MMI_MAX_SIM_NUM >= 3)
				case RMMI_UART_TO_SIM3:
					source_id = MOD_L4C_3;
					break;
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
				case RMMI_UART_TO_SIM4:
					source_id = MOD_L4C_4;
					break;
        #endif
				default:
					source_id = MOD_L4C;
					break;
			}
	
	/*
			count = buffer[L4C_SETTING_DUAL_SIM_UART] - RMMI__UART_TO_SIM1;
			if (count < MMI_MAX_SIM_NUM)
				source_id = MOD_L4C + count;
	*/
		
#endif /* #if (MMI_MAX_SIM_NUM > 1)*/   






    mmi_frm_send_ilm((oslModuleType) source_id, (oslMsgType)msg_id, 
                        (oslParaType*)local_param_ptr, (oslPeerBuffType*)peer_buf_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSendMsg_Ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         
 *  peer_buf_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSendMsg_Ext(U16 msg_id, U16 dest_mod_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm((oslModuleType) dest_mod_id, (oslMsgType)msg_id, 
        (oslParaType*)local_param_ptr, (oslPeerBuffType*)peer_buf_ptr);
}

MMI_BOOL mmi_em_is_in_call(void)
{
	S32 count;
 	count = srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL);
	if(count > 0)
		return MMI_TRUE;
	else
		return MMI_FALSE;
}


void mmi_em_dualmode_enter_flight_mode(FuncPtr callback)
{
    MMI_ASSERT(!g_em_dualmode_switch_callback);
    g_em_dualmode_switch_callback = callback;

    mmi_em_entry_dualmode_switch_progress();
    //srv_mode_switch_switch_rf_mode(SRV_MODE_SWITCH_ALL_OFF, mmi_em_dualmode_switch_callback, NULL);
}

static mmi_ret mmi_em_dualmode_switch_callback(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_SRV_MODE_SWITCH_FINISH)
    {
        mmi_em_close_dualmode_switch_progress();
        if (((srv_mode_switch_rsp_event_struct*)evt)->result)
        {
            if (g_em_dualmode_switch_callback)
            {
                g_em_dualmode_switch_callback();
            }
        }
        else
        {
            mmi_em_popup_by_str(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE);
        }
    }
     g_em_dualmode_switch_callback = NULL;
     return MMI_RET_OK;
}

void mmi_em_entry_dualmode_switch_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_progress_cntx_struct cntx = {0};
    
    cntx.title_id = STR_GLOBAL_PLEASE_WAIT;
    cntx.message = (U8*)get_string(STR_GLOBAL_PLEASE_WAIT);
    cntx.scrn_id = SCR_ID_EM_DUALMODE_SWITCH_PROGRESS;
    cntx.esk_func = mmi_em_progress_sftkey_null_hdlr;
    
    mmi_em_show_progress_scrn(&cntx);
}

void mmi_em_close_dualmode_switch_progress(void)
{
    mmi_frm_scrn_close(mmi_em_get_root_group(), SCR_ID_EM_DUALMODE_SWITCH_PROGRESS);
}

/* Screen Level Nofity */
void mmi_em_scr_level_notify(U32 cur_flag, MMI_ID cur_id, U32 parent_flag, MMI_ID parent_id)
{
    mmi_em_scr_level_nofity_ind_struct *data;

    
    data = OslConstructDataPtr(sizeof(mmi_em_scr_level_nofity_ind_struct));
    
    data->cntx.cur_flag = cur_flag;
    data->cntx.cur_id = cur_id;
    data->cntx.cur_flag = parent_flag;
    data->cntx.parent_id = parent_id;
    
    mmi_frm_send_ilm((oslModuleType) MOD_MMI, (oslMsgType)MSG_ID_MMI_EM_SCR_LEVEL_NOTIFY_IND, 
                        (oslParaType*)data, (oslPeerBuffType*)NULL);
}

void mmi_em_set_menu_list_items_title(mmi_id menu_group_id, U16 temp_str_id)
{
    U32 i;
    U32 list_num;
    mmi_menu_id menu_id;

           
    list_num = cui_menu_get_currlist_item_count(menu_group_id);
            
    for (i = 0; i < list_num; i++)
    {
        kal_wsprintf((WCHAR*)subMenuData[i], "%w %d", get_string(temp_str_id), i);
        menu_id = cui_menu_get_currlist_menu_id_from_index(menu_group_id, i);
        cui_menu_set_item_string(menu_group_id, menu_id, (WCHAR*)subMenuData[i]);
    }
}

void mmi_em_fresh_active_scrn(void)
{
     mmi_frm_scrn_create(mmi_em_get_root_group(), SCR_ID_DUMMY, NULL, NULL);

     mmi_frm_scrn_close(mmi_em_get_root_group(), SCR_ID_DUMMY);
}

MMI_BOOL mmi_em_ctrl_sim_is_available(mmi_sim_enum sim_id)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return MMI_TRUE;
}

void mmi_em_common_set_left_softkey(U32 item)
{    
    if (item)
    {
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        change_left_softkey(STR_GLOBAL_ON, 0);
    }

    redraw_left_softkey();
}



U32 mmi_em_itoa(S32 i, S32 base, WCHAR *buf)
{
    CHAR *s;
    CHAR *d;
    CHAR wcs_buf[20] = {0};
    S32 rem;
    U32 count = 0;
    static CHAR rev[21];

    d = wcs_buf;
    rev[20] = 0;
    if (i == 0)
    {
        (*d) = '0';
        *(++d) = '\0';
        count++;
    }
    else
    {
        s = &rev[20];

        while (i)
        {
           rem = i % base;
           if (rem < 10)
               *--s = rem + '0';
           else if (base == 16)
               *--s = "abcdef"[rem - 10];
           i /= base;
        }
        while (*s)
        {
           (*d) = *s++;
           ++d;
           count++;
        }
    }
    mmi_asc_to_wcs(buf,wcs_buf);

    return count;
}


//DCM require
#if (defined(COSMOS_EM_INTERNAL_DCM) || defined(PLUTO_EM_INTERNAL_DCM))
#pragma arm section rodata , code
#endif /* COSMOS_EM_INTERNAL_DCM || PLUTO_EM_INTERNAL_DCM */ 

/*****************************************************************************
 * FUNCTION
 *  EngineerModeSetSleepModeRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSetSleepModeRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_sleep_mode_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_display_notify_popup(rsp_p->result);
}


void mmi_em_display_notify_popup(MMI_BOOL result)
{
    if (result)
    {
        mmi_em_success_popup();
    }
    else
    {
        mmi_em_fail_popup();
    }
}


void mmi_em_success_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //DCM Need
    MMI_ID grp_id = g_em_root_group_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, grp_id, NULL);
}


void mmi_em_fail_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //DCM Need
    MMI_ID grp_id = g_em_root_group_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple_ext(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE, grp_id, NULL);
}


#ifdef COSMOS_EM_INTERNAL_DCM 

void mmi_em_send_dcm_unload_process(void)
{
    if(DCM_Isloaded(DYNAMIC_CODE_COMPRESS_COSMOS_EM)== KAL_TRUE)
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_COSMOS_EM);
    }
}

#endif /* COSMOS_EM_INTERNAL_DCM  */



#endif /* __MMI_ENGINEER_MODE__ */
