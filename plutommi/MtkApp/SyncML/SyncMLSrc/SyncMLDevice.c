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
 *  SyncMLDevice.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  The file impliment DataSync between Device and Device
 *
 *					Near end								Far end
 *		------------------------------------------------------------------------
 *		| 	MMI		|		   | syncml task |	syncml task	  			|MMI|
 *		------------------------------------------------------------------------
 *		   |	START_SYNC_REQ		|			   |     ASK_CONN_IND
 *		   |----------------------->|			   |----------------------->|
 *		   |		Waiting...		|			   |	 ASK_CONN_RES		|
 *		   |	BT_CONN_IND			|			   |<---------------------- |
 *		   |<-----------------------|	 Obex	   |	 BT_CONN_IND		|
 *		   |						|	 layer	   |----------------------->|
 *		   | Waiting to sync		|	   		   |	REMOTE_INFO_IND		|
 *		   |						|			   |----------------------->|
 *		   |	data transfer		|  			   |	REMOTE_INFO_RES		|
 *		   |------------------------|  			   |<-----------------------|
 *		   |                        |              |    SYNC_DB_IND         |
 *         |                        |              |----------------------->|   
 *				.......Sync			record exchange			.......Sync     |
 *				
 *		   |	BT_DISCONN_IND		|			   |	BT_DISCONN_IND		|
 *		   |<-----------------------|			   |----------------------->|
 *		   |	SYNC_FINISH_IND		|			   |	SYNC_FINISH_IND		|
 *		   |<-----------------------|			   |----------------------->|
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifdef __MMI_SYNCML_DEVICE_SYNC__

#include "common_nvram_editor_data_item.h"
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "bt_a2dp_base_struct.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "wgui_touch_screen.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "string.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "AlertScreen.h"
#include "mmi_rp_srv_syncml_def.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "Unicodexdcl.h"
#include "MMI_common_app_trc.h"
#include "mmi_conn_app_trc.h"
#include "MMI_conn_app_trc.h"
#include "kal_trace.h"
#include "CommonScreensResDef.h"
#include "CustDataRes.h"
#include "wgui_categories_list.h"
#include "GlobalConstants.h"
#include "wgui_categories.h"
#include "custom_events_notify.h"
#include "wgui_categories_popup.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_msg_struct.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "ImeGprot.h"
#include "wgui_categories_inputs.h"
#include "mmi_frm_history_gprot.h"
#include "BTMMIScrGprots.h"
#include "BtcmCuiGprot.h"
#include "BtcmSrvGprot.h"
#include "UcmSrvGprot.h"
#include "nvram_enums.h"
#include "mmi2syncml_struct.h"
#include "SyncMLDef.h"
#include "SyncMLStruct.h"
#include "SyncMLProt.h"
#include "SyncMLGprot.h"
#include "Conversions.h"
#include "fseditorcuigprot.h"
#include "menucuigprot.h"
#include "ProfilesSrvGprot.h"
#include "BTMMISCOPathGProts.h"
#include "app_mine.h"


/*****************************************************************************
 * Define
 *****************************************************************************/
/* Synchronizing check */
#define MMI_SYNCML_CHECK_SYNC                           \
        do {	                                        \
	        if (mmi_syncml_is_sync_now())	            \
	        {	                                        \
                mmi_popup_display_simple(               \
                    (WCHAR*)get_string(STR_ID_SYNC_CODE_FORBIDDEN), \
                    MMI_EVENT_FAILURE,                  \
                    GRP_ID_ROOT,                        \
                    NULL);                              \
                return;	                                \
	        }	                                        \
    	}while(0);

/* re_entry sync menu*/
#define MMI_SYNCML_CHECK_REENTRY \
        do {	\
	        if (!mmi_syncml_device_sync_reentry_check())	\
	        {	\
                return;	\
	        }	\
    	}while(0);

#define CALLBACK_FUNC(ptr, x) if (ptr!= NULL){ptr(x);} /*BT concurrency */

#define PHONE_COD_MASK (MMI_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK | MMI_BT_PHONE_MAJOR_DEVICE_MASK | MMI_BT_TELEPHONY_MAJOR_SERVICE_MASK)
/*****************************************************************************
 * Global Variable
 *****************************************************************************/
mmi_syncml_device_sync_context_struct g_mmi_syncml_device_cntx;
mmi_syncml_device_account_context_struct g_mmi_syncml_device_accnt_cntx;
mmi_syncml_device_setting_context_struct g_mmi_syncml_device_setting_cntx;

mmi_syncml_device_sync_context_struct *const mmi_syncml_dev_p = &g_mmi_syncml_device_cntx;
mmi_syncml_device_setting_context_struct *const mmi_syncml_dev_setting_p = &g_mmi_syncml_device_setting_cntx;
mmi_syncml_device_account_context_struct *const mmi_syncml_dev_accnt_p = &g_mmi_syncml_device_accnt_cntx;

/*****************************************************************************
 * Local Variable
 *****************************************************************************/
/* name buffer for rename */
static U8 g_syncml_device_accnt_name_buffer[(MAX_SYNCML_DEV_NAME_LEN + 1) * ENCODING_LENGTH];

/* Event based sound id for confirm screen */
static srv_prof_tone_enum g_mmi_syncml_dev_snd_id;


/*****************************************************************************
 * Local Function
 *****************************************************************************/
/* BT related */
static void mmi_syncml_device_sel_hdlr(MMI_BOOL result, U32 lap, U8 uap, U16 nap);

/* nvram related */
static void mmi_syncml_device_read_setting(void);
static void mmi_syncml_device_update_setting(void);
static void mmi_syncml_device_update_account(U8 record_id, void* nvram_buffer);

/* Message related */
static void mmi_syncml_device_delete_req(U8 dev_id);
static void mmi_syncml_device_delete_rsp(void* param);
static void mmi_syncml_device_delete_all_req(void);
static void mmi_syncml_device_delete_all_rsp(void* param);
static void mmi_syncml_device_start_sync_req(U8 *imei);

/* menu cui handler */
static void mmi_syncml_device_menu_cui_select_evt_hdlr(mmi_event_struct *param);
static void mmi_syncml_device_menu_cui_entry_evt_hdlr(mmi_event_struct *param);
static void mmi_syncml_device_menu_cui_exit_evt_hdlr(mmi_event_struct *param);
static void mmi_syncml_device_menu_cui_notify_close_evt_hdlr(mmi_event_struct *param);

/* screen */
static void mmi_syncml_device_entry_main_menu(void);
static void mmi_syncml_device_entry_new_sync_menu(void);
static void mmi_syncml_device_entry_app_to_sync(void);
static void mmi_syncml_device_app_to_sync_entry_evt_hdlr(cui_menu_event_struct* evt);
static void mmi_syncml_device_app_to_sync_exit_evt_hdlr(cui_menu_event_struct* evt);
static void mmi_syncml_device_entry_app_save_confirm(void);
static void mmi_syncml_device_entry_phones_delete(void);
static void mmi_syncml_device_phones_delete_yes(void);
static void mmi_syncml_device_entry_phones_delete_all(void);
static void mmi_syncml_device_phones_delete_all_yes(void);
static void mmi_syncml_device_phones_reset_hdlr(void *param);

static void mmi_syncml_device_entry_phones_view_log(void);

static pBOOL mmi_syncml_device_get_phones(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static void mmi_syncml_device_entry_phones_list(void);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_syncml_device_phone_list_tap_callback(mmi_tap_type_enum tap_type, S32 index);
#endif
static void mmi_syncml_device_entry_phones_options(void);
static void mmi_syncml_device_highlight_phone_list(S32 index);

static void mmi_syncml_device_phones_start_sync_precheck(void);
static void mmi_syncml_device_phones_start_sync(void);
static void mmi_syncml_device_entry_phones_rename(void);

/* util */
static void mmi_syncml_device_pre_check_callback(U8 result);
static MMI_BOOL mmi_syncml_device_sync_reentry_check(void);
static void mmi_syncml_device_sync_pre_check(mmi_syncml_device_client_callback client_callback);
static void mmi_syncml_device_bt_pwron_callback(MMI_BOOL result);
static void mmi_syncml_device_rename_save(mmi_event_struct* param);

/* screen group */
static void mmi_syncml_device_group_entry_main_menu(void);
static mmi_ret mmi_syncml_device_group_main_proc(mmi_event_struct *param);
static mmi_ret mmi_syncml_device_group_bt_cui_proc(mmi_event_struct* event);
static void mmi_syncml_device_sync_entry_bt_power_on_cui(void);
static mmi_ret mmi_syncml_device_no_application_popup_proc(mmi_event_struct* param);


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_sync_launch
 * DESCRIPTION
 *  launch device sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_sync_launch(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    mmi_syncml_device_group_entry_main_menu();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_read_nvram
 * DESCRIPTION
 *  Device init function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_read_nvram(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    g_mmi_syncml_cntx.dev_cntx_ptr = &g_mmi_syncml_device_cntx;
    mmi_syncml_dev_p->accnt_ptr = (mmi_syncml_device_account_context_struct *)&g_mmi_syncml_device_accnt_cntx;
    mmi_syncml_dev_p->setting_ptr = (mmi_syncml_device_setting_context_struct *)&g_mmi_syncml_device_setting_cntx;
    
	mmi_syncml_device_read_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_init
 * DESCRIPTION
 *  Device init function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	
    if (mmi_syncml_dev_setting_p->app_to_sync & SYNCML_DB_PHONEBOOK)
    {
        mmi_syncml_dev_p->selected_app[SYNCML_SYNC_DEVICE_APP_PHB] = 1;
    }
#ifdef __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__
    if (mmi_syncml_dev_setting_p->app_to_sync & SYNCML_DB_CALENDAR)
    {
        mmi_syncml_dev_p->selected_app[SYNCML_SYNC_DEVICE_APP_CAL] = 1;
    }
#endif /* __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_DEVICE_TASK_SUPPORT__
    if (mmi_syncml_dev_setting_p->app_to_sync & SYNCML_DB_TASK)
    {
        mmi_syncml_dev_p->selected_app[SYNCML_SYNC_DEVICE_APP_TASK] = 1;
    }
#endif /* __MMI_SYNCML_DEVICE_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    if (mmi_syncml_dev_setting_p->app_to_sync & SYNCML_DB_NOTE)
    {
        mmi_syncml_dev_p->selected_app[SYNCML_SYNC_DEVICE_APP_NOTE] = 1;
    }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
	/* Set to invalid */
	mmi_syncml_dev_p->selected_dev = 0;

    mmi_syncml_dev_setting_p->report_status = 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_init_anchor
 * DESCRIPTION
 *  Init device message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_init_anchor(void )
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/    
    if (mmi_syncml_dev_p->app_to_sync & SYNCML_DB_PHONEBOOK)
    {
        g_mmi_syncml_cntx.next_phb_anchor = mmi_syncml_dev_setting_p->last_phb_anchor[mmi_syncml_dev_p->selected_dev - 1] + 1;
    }
#ifdef __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__
    if (mmi_syncml_dev_p->app_to_sync & SYNCML_DB_CALENDAR)
    {
        g_mmi_syncml_cntx.next_cal_anchor = mmi_syncml_dev_setting_p->last_cal_anchor[mmi_syncml_dev_p->selected_dev - 1] + 1;
    }
#endif /* __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_DEVICE_TASK_SUPPORT__
    if (mmi_syncml_dev_p->app_to_sync & SYNCML_DB_TASK)
    {
        g_mmi_syncml_cntx.next_task_anchor = mmi_syncml_dev_setting_p->last_task_anchor[mmi_syncml_dev_p->selected_dev - 1] + 1;
    }
#endif /* __MMI_SYNCML_DEVICE_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    if (mmi_syncml_dev_p->app_to_sync & SYNCML_DB_NOTE)
    {
        g_mmi_syncml_cntx.next_note_anchor = mmi_syncml_dev_setting_p->last_note_anchor[mmi_syncml_dev_p->selected_dev - 1] + 1;
    }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_finish
 * DESCRIPTION
 *  Init device message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_finish(void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_syncml_device_setting_context_struct *setting_ptr;
	mmi_syncml_device_account_context_struct *accnt_ptr;
	
	mmi_syncml_finish_sync_ind_struct *finish_info_ptr;
	mmi_syncml_device_finish_info_struct *dev_info_ptr;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_ASSERT(param != NULL);

	finish_info_ptr = (mmi_syncml_finish_sync_ind_struct *)param;
	dev_info_ptr = &finish_info_ptr->d2d_info;
	
	setting_ptr = mmi_syncml_dev_p->setting_ptr;
	accnt_ptr = mmi_syncml_dev_p->accnt_ptr;
	
    /*
	* The role may be changed, 
	* eg: the phone has been deleted by far end, and then sync from far end.
	*/
    if (dev_info_ptr->f_sml_role_updated)
    {
        accnt_ptr->role = dev_info_ptr->sml_new_role;
    } 
	
    if (strlen((CHAR*)dev_info_ptr->device_uri))
    {
        strncpy((CHAR*)accnt_ptr->dev_uri, (CHAR*)dev_info_ptr->device_uri, MAX_SYNCML_SERVER_ADDR_LEN);
    }
    
    if (strlen((CHAR*)dev_info_ptr->contact_database_uri))
    {
        strncpy((CHAR*)accnt_ptr->contact_address, (CHAR*)dev_info_ptr->contact_database_uri, MAX_SYNCML_DATABASE_ADDR_LEN);
    }
    
    if (strlen((CHAR*)dev_info_ptr->calendar_database_uri))
    {
        strncpy((CHAR*)accnt_ptr->calendar_address, (CHAR*)dev_info_ptr->calendar_database_uri, MAX_SYNCML_DATABASE_ADDR_LEN);
    }
    
    if (strlen((CHAR*)dev_info_ptr->task_database_uri))
    {
        strncpy((CHAR*)accnt_ptr->task_address, (CHAR*)dev_info_ptr->task_database_uri, MAX_SYNCML_DATABASE_ADDR_LEN);
    }
    
    if (strlen((CHAR*)dev_info_ptr->note_database_uri))
    {
        strncpy((CHAR*)accnt_ptr->note_address, (CHAR*)dev_info_ptr->note_database_uri, MAX_SYNCML_DATABASE_ADDR_LEN);
    }
    
    if (SYNCML_GET_SYNC_STATUS(finish_info_ptr->result) == SYNCML_OK)
    {
		/* update the last anchor because of sync completion */
		if (mmi_syncml_dev_p->app_to_sync & SYNCML_DB_PHONEBOOK) 
		{
			if (!(g_mmi_syncml_cntx.db_sync_result & SYNCML_DB_PHONEBOOK))
			{
				setting_ptr->last_phb_anchor[mmi_syncml_dev_p->selected_dev - 1] = g_mmi_syncml_cntx.next_phb_anchor;
				
				memcpy(g_mmi_syncml_cntx.svr_contact_ok_cnt, 
					finish_info_ptr->svr_contact_ok_cnt, 
					sizeof(g_mmi_syncml_cntx.svr_contact_ok_cnt));
				
				g_mmi_syncml_cntx.svr_contact_ng_cnt = finish_info_ptr->svr_contact_ng_cnt;
				/* For we write change log when receiving data from server,
				* it need clear change log here to avoid log is remained after sync succeed.
				* ex, when in local no data change to send, change log can not be cleared automatically by protocol.
				*/ 
				mmi_syncml_device_clearall_change_log(mmi_syncml_dev_p->selected_dev, SYNCML_DB_PHONEBOOK);
				memcpy(accnt_ptr->contact_remote_anchor, dev_info_ptr->contact_remote_anchor, MAX_SYNCML_REMOTE_ANCHOR_SIZE);
			}
			else /* if phb failed, don't update anchor and change log */
			{
				g_mmi_syncml_cntx.next_phb_anchor= setting_ptr->last_phb_anchor[mmi_syncml_dev_p->selected_dev - 1];
			}
			
		}
#ifdef __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__
		if (mmi_syncml_dev_p->app_to_sync & SYNCML_DB_CALENDAR)
		{
			
			if (!(g_mmi_syncml_cntx.db_sync_result & SYNCML_DB_CALENDAR))
			{
				setting_ptr->last_cal_anchor[mmi_syncml_dev_p->selected_dev - 1] = g_mmi_syncml_cntx.next_cal_anchor;
				
				memcpy(g_mmi_syncml_cntx.svr_calendar_ok_cnt, 
					finish_info_ptr->svr_calendar_ok_cnt, 
					sizeof(g_mmi_syncml_cntx.svr_calendar_ok_cnt));
				
				g_mmi_syncml_cntx.svr_calendar_ng_cnt = finish_info_ptr->svr_calendar_ng_cnt;
				
				mmi_syncml_device_clearall_change_log(mmi_syncml_dev_p->selected_dev, SYNCML_DB_CALENDAR);
				/* Remote anchor and database name */
				memcpy(accnt_ptr->calendar_remote_anchor, dev_info_ptr->calendar_remote_anchor, MAX_SYNCML_REMOTE_ANCHOR_SIZE);
			}
			else /* if calendar failed, don't update anchor and change log */
			{
				g_mmi_syncml_cntx.next_cal_anchor= setting_ptr->last_cal_anchor[mmi_syncml_dev_p->selected_dev - 1];
			}
		}
#endif /* __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__ */
        
#ifdef __MMI_SYNCML_DEVICE_TASK_SUPPORT__
		if (mmi_syncml_dev_p->app_to_sync & SYNCML_DB_TASK)
		{
			
			if (!(g_mmi_syncml_cntx.db_sync_result & SYNCML_DB_TASK))
			{
				setting_ptr->last_task_anchor[mmi_syncml_dev_p->selected_dev - 1] = g_mmi_syncml_cntx.next_task_anchor;
				
				memcpy(g_mmi_syncml_cntx.svr_task_ok_cnt, 
					finish_info_ptr->svr_task_ok_cnt, 
					sizeof(g_mmi_syncml_cntx.svr_task_ok_cnt));
				
				g_mmi_syncml_cntx.svr_task_ng_cnt = finish_info_ptr->svr_task_ng_cnt;
				
				mmi_syncml_device_clearall_change_log(mmi_syncml_dev_p->selected_dev, SYNCML_DB_TASK);
				/* Remote anchor and database name */
				memcpy(accnt_ptr->task_remote_anchor, dev_info_ptr->task_remote_anchor, MAX_SYNCML_REMOTE_ANCHOR_SIZE); 
			}
			else /* if sync failed, don't update anchor and change log */
			{
				g_mmi_syncml_cntx.next_task_anchor= setting_ptr->last_task_anchor[mmi_syncml_dev_p->selected_dev - 1];
			}
		}
#endif /* __MMI_SYNCML_DEVICE_TASK_SUPPORT__ */
		
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        if (mmi_syncml_dev_p->app_to_sync & SYNCML_DB_NOTE)
        {
            
            if (!(g_mmi_syncml_cntx.db_sync_result & SYNCML_DB_NOTE))
            {
                setting_ptr->last_note_anchor[mmi_syncml_dev_p->selected_dev - 1] = g_mmi_syncml_cntx.next_note_anchor;
                
                memcpy(g_mmi_syncml_cntx.svr_note_ok_cnt, 
                    finish_info_ptr->svr_note_ok_cnt, 
                    sizeof(g_mmi_syncml_cntx.svr_note_ok_cnt));
                
                g_mmi_syncml_cntx.svr_note_ng_cnt = finish_info_ptr->svr_note_ng_cnt;
                
                mmi_syncml_device_clearall_change_log(mmi_syncml_dev_p->selected_dev, SYNCML_DB_NOTE);
                /* Remote anchor and database name */
                memcpy(accnt_ptr->note_remote_anchor, dev_info_ptr->note_remote_anchor, MAX_SYNCML_REMOTE_ANCHOR_SIZE); 
            }
            else /* if task failed, don't update anchor and change log */
            {
                g_mmi_syncml_cntx.next_note_anchor= setting_ptr->last_note_anchor[mmi_syncml_dev_p->selected_dev - 1];
            }
        }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
		
		mmi_syncml_device_update_setting();
    }
    else
    {
        if (mmi_syncml_dev_p->app_to_sync & SYNCML_DB_PHONEBOOK)
        {
			g_mmi_syncml_cntx.next_phb_anchor= setting_ptr->last_phb_anchor[mmi_syncml_dev_p->selected_dev - 1];
        }
#ifdef __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__
        if (mmi_syncml_dev_p->app_to_sync & SYNCML_DB_CALENDAR)
        {
			g_mmi_syncml_cntx.next_cal_anchor = setting_ptr->last_cal_anchor[mmi_syncml_dev_p->selected_dev - 1];
        }
#endif /* __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_DEVICE_TASK_SUPPORT__
        if (mmi_syncml_dev_p->app_to_sync & SYNCML_DB_TASK)
        {
			g_mmi_syncml_cntx.next_task_anchor = setting_ptr->last_task_anchor[mmi_syncml_dev_p->selected_dev - 1];
        }
#endif /* __MMI_SYNCML_DEVICE_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        if (mmi_syncml_dev_p->app_to_sync & SYNCML_DB_NOTE)
        {
			g_mmi_syncml_cntx.next_note_anchor = setting_ptr->last_note_anchor[mmi_syncml_dev_p->selected_dev - 1];
        }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */		
    }
	
    /* Update current account info */
    mmi_syncml_device_update_account(mmi_syncml_dev_p->selected_dev, (void *)accnt_ptr);
	
    g_mmi_syncml_cntx.is_dev_log = MMI_TRUE;

    mmi_syncml_update_sync_log_to_nvram();

    g_mmi_syncml_cntx.is_dev_log = MMI_FALSE;
	
    if ((mmi_syncml_dev_p->app_to_sync & SYNCML_DB_CALENDAR) || 
        (mmi_syncml_dev_p->app_to_sync & SYNCML_DB_TASK))
    {
        mmi_syncml_enable_alarm(); /* enable alarm */
    }

    /*
     * If app_to_sync for device B is 0, query indication will not come, so reset function can't be call.
     */
    if (mmi_syncml_dev_p->app_to_sync == 0)
    {
        mmi_syncml_enable_alarm();
    }
	
	/* Set to invalid */
    mmi_syncml_dev_p->is_new_dev = MMI_FALSE;
    g_mmi_syncml_cntx.is_dev_log = MMI_FALSE;
    
    /* 
	* If need to report status, then after sync report, restore them.
	*/
    if (SYNCML_GET_SYNC_STATUS(finish_info_ptr->result) != SYNCML_OK)
    {
		g_mmi_syncml_cntx.is_dev_sync = MMI_FALSE;
    }
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_start_sync
 * DESCRIPTION
 *  Load device sync setting from nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_start_sync(U8 *imei)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
     
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    g_mmi_syncml_cntx.is_pre_sync = 0;
    
    if (g_mmi_syncml_common_cntx.dev_role == MMI_SYNCML_DEV_ROLE_A)
    {
#ifdef __MMI_SYNCML_STATUS_ICON_SUPPORT__
        mmi_syncml_set_status_icon(MMI_TRUE);
#endif
        mmi_bt_suppress_profile_popup(SRV_BT_CM_SYNCML_DEV_PROFILE_UUID, MMI_TRUE);

        mmi_syncml_device_start_sync_req(imei);
    }
    else if (g_mmi_syncml_common_cntx.dev_role == MMI_SYNCML_DEV_ROLE_B)
    {
        strcpy((CHAR*)g_mmi_syncml_common_cntx.imei, (const CHAR*)imei); 
        
        mmi_syncml_device_remoteinfo_confirm_check();
    }
    else
    {
        MMI_ASSERT(!"[Sycnml]Wrong role");
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_start_sync_req
 * DESCRIPTION
 *  Device A start sync request
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_start_sync_req(U8 *imei)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_syncml_device_start_sync_req_struct *data_ptr;
    mmi_syncml_device_account_context_struct *accnt_ptr;
    applib_mime_type_struct *mime;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	accnt_ptr = mmi_syncml_dev_p->accnt_ptr;

    data_ptr =
        (mmi_syncml_device_start_sync_req_struct*) construct_local_para(sizeof(mmi_syncml_device_start_sync_req_struct), TD_CTRL|TD_RESET);
	MMI_ASSERT(data_ptr != NULL);

    /* also record remote bt address for conn indication */
	g_mmi_syncml_common_cntx.remote_bt_addr.lap = data_ptr->bt_addr_lap = accnt_ptr->dev_bt_addr.lap;
	g_mmi_syncml_common_cntx.remote_bt_addr.uap = data_ptr->bt_addr_uap= accnt_ptr->dev_bt_addr.uap;
	g_mmi_syncml_common_cntx.remote_bt_addr.nap = data_ptr->bt_addr_nap= accnt_ptr->dev_bt_addr.nap;
    
	data_ptr->sml_role = accnt_ptr->role;
    strcpy((CHAR*)data_ptr->device_uri, (CHAR*)accnt_ptr->dev_uri);

    mmi_syncml_dev_p->app_to_sync = mmi_syncml_dev_setting_p->app_to_sync;
    
	if (mmi_syncml_dev_p->app_to_sync & SYNCML_DB_PHONEBOOK)
    {
        strcpy((CHAR*)data_ptr->db_info.contact_database_uri, (CHAR*)accnt_ptr->contact_address);
        mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_XVCARD);
        if (mime)
        {
            strcpy((CHAR*) data_ptr->db_info.contact_mime_type, mime->mime_string);
        }        
        
        data_ptr->db_info.contact_last_anchor = mmi_syncml_dev_setting_p->last_phb_anchor[mmi_syncml_dev_p->selected_dev - 1];
        data_ptr->db_info.contact_next_anchor = g_mmi_syncml_cntx.next_phb_anchor;
		memcpy((void *)data_ptr->db_info.contact_remote_anchor, 
			   (void *)accnt_ptr->contact_remote_anchor,
			   MAX_SYNCML_REMOTE_ANCHOR_SIZE);

		g_mmi_syncml_cntx.contact_sync_state = MMI_TRUE; /* synchronizing */
    }
#ifdef __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__
    if (mmi_syncml_dev_p->app_to_sync & SYNCML_DB_CALENDAR)
    {
        strcpy((CHAR*)data_ptr->db_info.calendar_database_uri, (CHAR*)accnt_ptr->calendar_address);
        mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_XVCALENDAR);
        if (mime)
        {
            strcpy((CHAR*)data_ptr->db_info.calendar_mime_type, mime->mime_string);
        }        
        
        data_ptr->db_info.calendar_last_anchor = mmi_syncml_dev_setting_p->last_cal_anchor[mmi_syncml_dev_p->selected_dev - 1];
        data_ptr->db_info.calendar_next_anchor = g_mmi_syncml_cntx.next_cal_anchor;
		memcpy((void *)data_ptr->db_info.calendar_remote_anchor, 
			   (void *)accnt_ptr->calendar_remote_anchor,
			   MAX_SYNCML_REMOTE_ANCHOR_SIZE);
        
        mmi_syncml_disable_alarm();

		g_mmi_syncml_cntx.calendar_sync_state = MMI_TRUE; /* synchronizing */
    }
#endif /* __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_DEVICE_TASK_SUPPORT__
    if (mmi_syncml_dev_p->app_to_sync & SYNCML_DB_TASK)
    {
        strcpy((CHAR*)data_ptr->db_info.task_database_uri, (CHAR*)accnt_ptr->task_address);
        mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_XVCALENDAR);
        if (mime)
        {
            strcpy((CHAR*)data_ptr->db_info.task_mime_type, mime->mime_string);
        }        
        
        data_ptr->db_info.task_last_anchor = mmi_syncml_dev_setting_p->last_task_anchor[mmi_syncml_dev_p->selected_dev - 1];
        data_ptr->db_info.task_next_anchor = g_mmi_syncml_cntx.next_task_anchor;
		memcpy((void *)data_ptr->db_info.task_remote_anchor, 
			   (void *)accnt_ptr->task_remote_anchor,
			   MAX_SYNCML_REMOTE_ANCHOR_SIZE);
        
        mmi_syncml_disable_alarm();
        
		g_mmi_syncml_cntx.task_sync_state = MMI_TRUE; /* synchronizing */
    }
#endif /* __MMI_SYNCML_DEVICE_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    if (mmi_syncml_dev_p->app_to_sync & SYNCML_DB_NOTE)
    {
        strcpy((CHAR*)data_ptr->db_info.note_database_uri, (CHAR*)accnt_ptr->note_address);
        mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_PLAIN);
        if (mime)
        {
            strcpy((CHAR*)data_ptr->db_info.note_mime_type, mime->mime_string);
        }        
        
        data_ptr->db_info.note_last_anchor = mmi_syncml_dev_setting_p->last_note_anchor[mmi_syncml_dev_p->selected_dev - 1];
        data_ptr->db_info.note_next_anchor = g_mmi_syncml_cntx.next_note_anchor;
        memcpy((void *)data_ptr->db_info.note_remote_anchor, 
               (void *)accnt_ptr->note_remote_anchor,
               MAX_SYNCML_REMOTE_ANCHOR_SIZE);
                
        g_mmi_syncml_cntx.note_sync_state = MMI_TRUE; /* synchronizing */
    }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

	/* Local IMEI */
    memcpy(&data_ptr->imei[0], "IMEI:", 5);
    memcpy(&data_ptr->imei[5], imei, 15);
    data_ptr->imei[20] = 0;

    data_ptr->sync_type = SYNCML_SYNC_TWO_WAY_SYNC;

    g_mmi_syncml_cntx.abort_state = MMI_FALSE;

    mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_DEVICE_START_SYNC_REQ, (oslParaType*)data_ptr, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_read_setting
 * DESCRIPTION
 *  Load device sync setting from nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_read_setting(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    S16 error;
     
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
   ReadRecord(NVRAM_EF_SYNCML_DEV_SETTING_LID, 
   			  1, 
   			  (void *)&g_mmi_syncml_device_setting_cntx, 
   			  NVRAM_EF_SYNCML_DEV_SETTING_SIZE, 
   			  &error);
	
	if (error != NVRAM_READ_SUCCESS) 
	{
	    MMI_ASSERT(!"SyncMLDev read setting nvram error");
	}	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_update_setting
 * DESCRIPTION
 *  Save setting to nvram 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_update_setting(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    S16 error;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	WriteRecord(NVRAM_EF_SYNCML_DEV_SETTING_LID, 
			  1, 
			  (void*)&g_mmi_syncml_device_setting_cntx, 
			  NVRAM_EF_SYNCML_DEV_SETTING_SIZE, 
			  &error);

	if (error != NVRAM_WRITE_SUCCESS) 
	{
	    MMI_ASSERT(!"SyncMLDev wriet setting nvram error");
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_read_account
 * DESCRIPTION
 *  Read account info from nvram
 * PARAMETERS
 *  record_id		[IN]		record id
 *	nvram_buffer	[IN]		nvram data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_read_account(U8 record_id, void* nvram_buffer)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S16 error;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
   ReadRecord(
	   NVRAM_EF_SYNCML_DEV_ACCOUNT_LID,
	   (U16)record_id,
	   nvram_buffer,
	   NVRAM_EF_SYNCML_DEV_ACCOUNT_SIZE,
	   &error);
	
	if (error != NVRAM_READ_SUCCESS) 
	{
	    MMI_ASSERT(!"SyncMLDev read acount nvram error");
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_update_account
 * DESCRIPTION
 *  Init device info
 * PARAMETERS
 *  record_id		[IN]		record id
 *	nvram_buffer	[IN]		nvram data buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_update_account(U8 record_id, void* nvram_buffer)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    S16 error;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
   WriteRecord(
	   NVRAM_EF_SYNCML_DEV_ACCOUNT_LID,
	   (U16)record_id,
	   nvram_buffer,
	   NVRAM_EF_SYNCML_DEV_ACCOUNT_SIZE,
	   &error);
	
	if (error != NVRAM_WRITE_SUCCESS) 
	{
	    MMI_ASSERT(!"SyncMLDev update acount nvram error");
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_remoteinfo_ind_res
 * DESCRIPTION
 *  send remonte info to syncml, if no such record, all the devinfo is empty
 * PARAMETERS
 *  U8			status			1->accept, 0->reject
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_remoteinfo_ind_res(U8* imei, U8 status)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	typedef mmi_syncml_device_remoteinfo_res_struct dev_rmtinfo_res_struct ;
	dev_rmtinfo_res_struct *remote_info_res_ptr;
    mmi_syncml_device_db_info_struct *db_info_ptr;
    
    mmi_syncml_device_account_context_struct *accnt_ptr;
    applib_mime_type_struct *mime;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/    
	remote_info_res_ptr = (dev_rmtinfo_res_struct *)construct_local_para(sizeof(dev_rmtinfo_res_struct), TD_CTRL|TD_RESET);
	MMI_ASSERT(remote_info_res_ptr != NULL);

    remote_info_res_ptr->sml_role = mmi_syncml_dev_p->sync_role;
	remote_info_res_ptr->result = status; /* 1 or 0 */
    
    mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_SYNC_ASK_RSP);
    
    if (status == MMI_SYNCML_DEV_SYNC_ACCEPT && !mmi_syncml_dev_p->is_new_dev)
    {

#ifdef __MMI_SYNCML_STATUS_ICON_SUPPORT__
        mmi_syncml_set_status_icon(MMI_TRUE);
#endif 
        
        accnt_ptr = mmi_syncml_dev_p->accnt_ptr;
        /*
         * Fill db info, syncml task will use it as reference.
         */
        remote_info_res_ptr->sml_role = accnt_ptr->role;
        
        db_info_ptr = &remote_info_res_ptr->db_info;
        strcpy((CHAR*)db_info_ptr->contact_database_uri, (CHAR*)accnt_ptr->contact_address);
        mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_XVCARD);
        if (mime)
        {
            strcpy((CHAR*)db_info_ptr->contact_mime_type, mime->mime_string);
        }       
        
        db_info_ptr->contact_last_anchor = mmi_syncml_dev_setting_p->last_phb_anchor[mmi_syncml_dev_p->selected_dev - 1];
        db_info_ptr->contact_next_anchor = db_info_ptr->contact_last_anchor + 1;
        strcpy((CHAR*)db_info_ptr->contact_remote_anchor, (CHAR*)accnt_ptr->contact_remote_anchor);
        g_mmi_syncml_cntx.next_phb_anchor = db_info_ptr->contact_next_anchor;
        
#ifdef __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__
        strcpy((CHAR*)db_info_ptr->calendar_database_uri, (CHAR*)accnt_ptr->calendar_address);
        mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_XVCALENDAR);
        if (mime)
        {
            strcpy((CHAR*)db_info_ptr->calendar_mime_type, mime->mime_string);
        }        
        
        db_info_ptr->calendar_last_anchor = mmi_syncml_dev_setting_p->last_cal_anchor[mmi_syncml_dev_p->selected_dev - 1];
        db_info_ptr->calendar_next_anchor = db_info_ptr->calendar_last_anchor + 1;
        strcpy((CHAR*)db_info_ptr->calendar_remote_anchor, (CHAR*)accnt_ptr->calendar_remote_anchor);
        g_mmi_syncml_cntx.next_cal_anchor = db_info_ptr->calendar_next_anchor;
#endif /* __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_DEVICE_TASK_SUPPORT__
        strcpy((CHAR*)db_info_ptr->task_database_uri, (CHAR*)accnt_ptr->task_address);
        mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_XVCALENDAR);
        if (mime)
        {
            strcpy((CHAR*)db_info_ptr->task_mime_type, mime->mime_string);
        }       
        
        db_info_ptr->task_last_anchor = mmi_syncml_dev_setting_p->last_task_anchor[mmi_syncml_dev_p->selected_dev - 1];
        db_info_ptr->task_next_anchor = db_info_ptr->task_last_anchor + 1;
        strcpy((CHAR*)db_info_ptr->task_remote_anchor, (CHAR*)accnt_ptr->task_remote_anchor);
        g_mmi_syncml_cntx.next_task_anchor = db_info_ptr->task_next_anchor;
#endif /* __MMI_SYNCML_DEVICE_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        strcpy((CHAR*)db_info_ptr->note_database_uri, (CHAR*)accnt_ptr->note_address);
        mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_PLAIN);
        if (mime)
        {
            strcpy((CHAR*)db_info_ptr->note_mime_type, mime->mime_string);
        }
                
        db_info_ptr->note_last_anchor = mmi_syncml_dev_setting_p->last_note_anchor[mmi_syncml_dev_p->selected_dev - 1];
        db_info_ptr->note_next_anchor = db_info_ptr->note_last_anchor + 1;
        strcpy((CHAR*)db_info_ptr->note_remote_anchor, (CHAR*)accnt_ptr->note_remote_anchor);
        g_mmi_syncml_cntx.next_note_anchor = db_info_ptr->note_next_anchor;
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

        memcpy(&remote_info_res_ptr->imei[0], "IMEI:", 5);
        memcpy(&remote_info_res_ptr->imei[5], imei, 15);
        remote_info_res_ptr->imei[20] = 0;

    }
    /* If reject or new device, then just return empty */
    else
    {
        memset(&remote_info_res_ptr->db_info, 0, sizeof(mmi_syncml_device_db_info_struct));
        mmi_syncml_device_unlock_all_db();
        g_mmi_syncml_common_cntx.dev_role = MMI_SYNCML_DEV_ROLE_NONE;
        g_mmi_syncml_cntx.is_dev_sync = MMI_FALSE;
    }
	
	mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_DEVICE_REMOTEINFO_RES, (oslParaType*)remote_info_res_ptr, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_sync_yes
 * DESCRIPTION
 *  Ask usr's confirm to start sync.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_sync_yes(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/   	
	if (!mmi_syncml_device_locate_new_dev(&g_mmi_syncml_common_cntx.remote_bt_addr, MMI_FALSE))
	{ 
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_ID_SYNC_PHONE_LIST_FULL), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);
        mmi_frm_group_close(GRP_ID_SYNC_BT_SYNC_REQ);

		mmi_syncml_comm_disconn();
		return ;
	}

    mmi_syncml_device_state_pre_check();

    mmi_frm_group_close(GRP_ID_SYNC_BT_SYNC_REQ);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_sync_no
 * DESCRIPTION
 *  Ask usr's confirm to start sync.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_sync_no(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mmi_syncml_device_remoteinfo_ind_res(NULL, MMI_SYNCML_DEV_SYNC_REJECT);  
	mmi_frm_group_close(GRP_ID_SYNC_BT_SYNC_REQ);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_idmap_insert
 * DESCRIPTION
 *  Inset a new id in idmap list
 * PARAMETERS
 *  map			[IN] 		the old map
 *	id			[IN]		the new id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_idmap_insert(U8 *map, const U8 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = MAX_SYNCML_DEV_NUM - 1; i > 0; i--)
	{
		map[i] = map[i - 1];
	}
	
	map[0] = id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_idmap_remove
 * DESCRIPTION
 *  Remove the id from the current map
 * PARAMETERS
 *  map			[IN]		the current map
 *	id			[IN]		id in map
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_idmap_remove(U8 *map, const U8 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 total_valid = 0;
	U8 j = MAX_SYNCML_DEV_NUM;
	U8 i;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < MAX_SYNCML_DEV_NUM; i++)
	{
		if (map[i] == id)
		{
			j = i;
		}
		
		if (map[i] != 0)
		{
			++total_valid;
		}
	}

	MMI_ASSERT(j < MAX_SYNCML_DEV_NUM);
		
	
	for (i = j; i < MAX_SYNCML_DEV_NUM - 1; i++)
	{
		map[i] = map[i + 1];
	}
	
	map[total_valid - 1] = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_idmap_exist
 * DESCRIPTION
 *  To test wheth the id is already in id-location list
 * PARAMETERS
 *  map				[IN]			the current idmap
 *	id				[IN]			ID
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_syncml_idmap_exist(U8 *map, const U8 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < MAX_SYNCML_DEV_NUM; i++)
	{
		if (map[i] == id)
		{
			return MMI_TRUE;
		}
	}
	
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_read_namelist
 * DESCRIPTION
 *  Entry main menu for device sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_read_namelist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_syncml_device_account_context_struct accnt;
	U8 i;
    MMI_BOOL exist_flag;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_syncml_dev_p->total_phones = 0;
    
	/* read phone name list */
	for (i = 0; i < MAX_SYNCML_DEV_NUM; i++)
	{
        exist_flag = mmi_syncml_idmap_exist(mmi_syncml_dev_setting_p->name_id_map, (U8)(i + 1));
		mmi_syncml_device_read_account((U8)(i + 1), (void *)&accnt);
		if (accnt.dev_id != 0xFF)
		{
			mmi_ucs2cpy((CHAR*)mmi_syncml_dev_p->name_list[i], (CHAR *)accnt.dev_name);

			if (!exist_flag) /* new device */
			{
				mmi_syncml_idmap_insert(mmi_syncml_dev_setting_p->name_id_map, (U8)(i + 1));
			}
			mmi_syncml_dev_p->total_phones++;
		}
        else
        {
        
         if (exist_flag) /* be deleted device */
         {
            mmi_syncml_idmap_remove(mmi_syncml_dev_setting_p->name_id_map, (U8)(i + 1));
         }
            mmi_syncml_dev_p->name_list[i][0] = 0;
        }
	}
    	/* Update id map to nvram */
	mmi_syncml_device_update_setting();
    
	MMI_SYNCML_TRACE6(MMI_SYNCML_DEV_NAMEMAP, 
                      0, 
                      mmi_syncml_dev_setting_p->name_id_map[0], 
                      1,
                      mmi_syncml_dev_setting_p->name_id_map[1],
                      2,
                      mmi_syncml_dev_setting_p->name_id_map[2]);
    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_add_remote_device
 * DESCRIPTION
 *  Add remote device to phone list, Only after sync is going on, 
 *   the device will be added to phoen list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_add_remote_device(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_device_account_context_struct *accnt_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_syncml_dev_p->is_new_dev)
    {
        return;
    }
    
    MMI_ASSERT(mmi_syncml_dev_p->selected_dev > 0 && mmi_syncml_dev_p->selected_dev <= MAX_SYNCML_DEV_NUM);
    
    accnt_ptr = mmi_syncml_dev_p->accnt_ptr;
    
    memset((void*)accnt_ptr, 0, sizeof(mmi_syncml_device_account_context_struct));
	memcpy((void*)&accnt_ptr->dev_bt_addr, (void*)&g_mmi_syncml_common_cntx.remote_bt_addr, sizeof(srv_bt_cm_bt_addr));
    mmi_ucs2cpy((CHAR*)accnt_ptr->dev_name, (CHAR*)g_mmi_syncml_common_cntx.remote_dev_name);
    
  	accnt_ptr->dev_id = mmi_syncml_dev_p->selected_dev;
    /*
     * If new device, the role will be set from the accept or start sync.
     */
    if (g_mmi_syncml_common_cntx.dev_role == MMI_SYNCML_DEV_ROLE_A)
    {
        accnt_ptr->role = mmi_syncml_dev_p->sync_role = SYNCML_DS_SERVER;
    }
    else
    {
        accnt_ptr->role = mmi_syncml_dev_p->sync_role = SYNCML_DS_CLIENT;
    }

    /* Save cod for BT */
    accnt_ptr->dev_bt_cod = srv_bt_cm_get_dev_cod(&(g_mmi_syncml_common_cntx.remote_bt_addr));
    
	mmi_syncml_device_update_account(mmi_syncml_dev_p->selected_dev, (void *)accnt_ptr);

	/* reset anchor */
	mmi_syncml_dev_setting_p->last_phb_anchor[mmi_syncml_dev_p->selected_dev - 1] = 0;
#ifdef __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__
	mmi_syncml_dev_setting_p->last_cal_anchor[mmi_syncml_dev_p->selected_dev - 1] = 0;
#endif /* __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_DEVICE_TASK_SUPPORT__
    mmi_syncml_dev_setting_p->last_task_anchor[mmi_syncml_dev_p->selected_dev - 1] = 0;
#endif /* __MMI_SYNCML_DEVICE_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    mmi_syncml_dev_setting_p->last_note_anchor[mmi_syncml_dev_p->selected_dev - 1] = 0;
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
   
    mmi_syncml_dev_setting_p->report_status = 1;
    mmi_syncml_device_update_setting();
    
    mmi_syncml_dev_p->is_new_dev = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_pre_check_callback
 * DESCRIPTION
 *  Entry main menu for device sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_pre_check_callback(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_syncml_common_cntx.dev_role == MMI_SYNCML_DEV_ROLE_B)
    {
        mmi_syncml_device_unlock_all_db();
    }

    if (result == MMI_SYNCML_DEVICE_ERROR_SUCCESS)
    {
        mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_START);
    }
    else /* Fail, Do roll back */
    {
        mmi_syncml_dev_p->app_to_sync = 0;
        
        if (g_mmi_syncml_common_cntx.dev_role == MMI_SYNCML_DEV_ROLE_A)
        {
            g_mmi_syncml_cntx.is_pre_sync = 0;
			g_mmi_syncml_cntx.is_dev_sync = MMI_FALSE;
			
			g_mmi_syncml_common_cntx.dev_role = MMI_SYNCML_DEV_ROLE_NONE;
            mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_BT_ON);
        }
        
        if (g_mmi_syncml_common_cntx.dev_role == MMI_SYNCML_DEV_ROLE_B)
        {
            mmi_syncml_device_remoteinfo_ind_res(NULL, MMI_SYNCML_DEV_SYNC_REJECT);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_group_entry_main_menu
 * DESCRIPTION
 *  Entry main menu for device sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_group_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SYNCML_CHECK_REENTRY
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SYNC_DEV_MAIN, mmi_syncml_device_group_main_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SYNC_DEV_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_syncml_device_entry_main_menu();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_entry_main_menu
 * DESCRIPTION
 *  Entry main menu for device sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
                        GRP_ID_SYNC_DEV_MAIN, 
                        CUI_MENU_SRC_TYPE_RESOURCE, 
                        CUI_MENU_TYPE_APPMAIN, 
                        MENU_ID_SYNCML_DEV_MAIN, 
                        MMI_FALSE, 
                        NULL);

    cui_menu_set_default_title(
        menu_cui_gid, 
        (WCHAR *)get_string(STR_ID_SYNC_DEV_MAIN), 
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_SYNCML_DEV_MAIN)));

    cui_menu_run(menu_cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_entry_new_sync_menu
 * DESCRIPTION
 *  Search new device and sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_entry_new_sync_menu(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    /* 1. sync finished has not coming
     * 2. Accept connection, but server has not ask for sync confirm yet */
    if (g_mmi_syncml_common_cntx.curr_state >= MMI_SYNCML_DEVICE_STATE_SYNCING 
        || (g_mmi_syncml_common_cntx.cm_conn_id != MMI_SYNCML_DEV_INVALID_CONN_ID 
        &&  !mmi_syncml_is_sync_now()))
    {
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_ID_SYNC_CODE_FORBIDDEN), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);
        return;
    }
    
    if (mmi_syncml_dev_setting_p->app_to_sync == 0)
    {   
        mmi_syncml_popup_display_with_proc(
            GRP_ID_SYNC_DEV_MAIN,
            (WCHAR*)get_string(STR_ID_SYNC_NO_APPLICATION), 
            MMI_EVENT_FAILURE, 
            mmi_syncml_device_no_application_popup_proc, 
            NULL);
        return;
    }
    
    mmi_syncml_device_sync_entry_bt_select_cui();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_device_valid
 * DESCRIPTION
 *  This function is LSK when select dev success
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
	
static MMI_BOOL mmi_syncml_is_device_valid(U32 device_cod, U32 specific_cod)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	MMI_BOOL match = MMI_FALSE;
	U32 major_service = 0, major_device = 0, minor_device = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	if (specific_cod == 0xFFFFFFFF)
	{
		match = MMI_TRUE;
	}
	//#define MMI_BT_MISCELLANEOUS_MAJOR_DEVICE_MASK							(0x000000)
	else if (specific_cod == 0x000000)
	{
		match = MMI_TRUE;
	}
	else
	{
		major_service = 0x00FFE000 & specific_cod;
		major_device = 0x00001F00 & specific_cod;
		minor_device = 0x000000FC & specific_cod;
		if ((major_service & device_cod) != 0)
		{
			if ((major_device == 0) && (minor_device == 0))
			{
				match = MMI_TRUE;
			}
			else if (((device_cod & 0x1F00) == major_device) && ((minor_device == 0) || ((device_cod & 0xFF) == minor_device)))
			{
				match = MMI_TRUE;
			}
		}
	}
	
	return match;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_sel_hdlr
 * DESCRIPTION
 *  This function is LSK when select dev success
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_sel_hdlr(MMI_BOOL result, U32 lap, U8 uap, U16 nap)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	CHAR name_buff[MAX_SYNCML_DEV_NAME_LEN];
	U32 dev_code;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/    
	if (result)
	{
#if defined(__MMI_BT_AUDIO_SUPPORT__)
	    if (mmi_bt_sco_is_connected(MMI_BT_SCO_HFP_SCO) &&
            srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
	    {
	        mmi_bt_popup_operation_not_allowed();
	        return;
	    }
#endif /* __MMI_BT_AUDIO_SUPPORT__ */

        /* Blocked device will not come here */   
        g_mmi_syncml_common_cntx.remote_bt_addr.lap = lap;
        g_mmi_syncml_common_cntx.remote_bt_addr.uap = uap;
        g_mmi_syncml_common_cntx.remote_bt_addr.nap = nap;
        
        srv_bt_cm_get_dev_name(&g_mmi_syncml_common_cntx.remote_bt_addr, MAX_SYNCML_DEV_NAME_LEN, (U8*)name_buff);

		dev_code = srv_bt_cm_get_dev_cod(&g_mmi_syncml_common_cntx.remote_bt_addr);
		if(!mmi_syncml_is_device_valid(dev_code, PHONE_COD_MASK))
		{
            mmi_popup_display_simple(
                (WCHAR*)get_string(STR_ID_SYNC_DEV_INVALID), 
                MMI_EVENT_FAILURE, 
                GRP_ID_ROOT, 
                NULL);
			return ;
		}
		
        /* Device name from CM is utf8 */
        mmi_chset_utf8_to_ucs2_string(
            (U8*)g_mmi_syncml_common_cntx.remote_dev_name, 
            (MAX_SYNCML_DEV_NAME_LEN + 1) * ENCODING_LENGTH, 
            (U8*)name_buff);

        if (!mmi_syncml_device_locate_new_dev(&g_mmi_syncml_common_cntx.remote_bt_addr, MMI_FALSE))
		{
            mmi_popup_display_simple(
                (WCHAR*)get_string(STR_ID_SYNC_PHONE_LIST_FULL), 
                MMI_EVENT_FAILURE, 
                GRP_ID_ROOT, 
                NULL);
			return ;
		}
		
		/* Start sync as near end */
		g_mmi_syncml_common_cntx.dev_role = MMI_SYNCML_DEV_ROLE_A;
        g_mmi_syncml_cntx.is_dev_sync = MMI_TRUE;

        mmi_syncml_device_state_pre_check();
	}
	else
	{
		/* usr has cancel this option */
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_save_app_to_sync
 * DESCRIPTION
 *  Save of the application to sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_save_app_to_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple(
        (WCHAR*)get_string(STR_GLOBAL_SAVED), 
        MMI_EVENT_SUCCESS, 
        GRP_ID_ROOT, 
        NULL);
    
    mmi_syncml_dev_setting_p->app_to_sync = 0;
    
    if (mmi_syncml_dev_p->selected_app[SYNCML_SYNC_DEVICE_APP_PHB])
    {
        mmi_syncml_dev_setting_p->app_to_sync |= SYNCML_DB_PHONEBOOK;
    }
#ifdef __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__
    if (mmi_syncml_dev_p->selected_app[SYNCML_SYNC_DEVICE_APP_CAL])
    {
        mmi_syncml_dev_setting_p->app_to_sync |= SYNCML_DB_CALENDAR;
    }
#endif /* __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_DEVICE_TASK_SUPPORT__
    if (mmi_syncml_dev_p->selected_app[SYNCML_SYNC_DEVICE_APP_TASK])
    {
        mmi_syncml_dev_setting_p->app_to_sync |= SYNCML_DB_TASK;
    }
#endif /* __MMI_SYNCML_DEVICE_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        if (mmi_syncml_dev_p->selected_app[SYNCML_SYNC_DEVICE_APP_NOTE])
        {
            mmi_syncml_dev_setting_p->app_to_sync |= SYNCML_DB_NOTE;
        }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

    mmi_syncml_device_update_setting();

    cui_menu_close(g_mmi_syncml_cntx.temp_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_cancel_app_to_sync
 * DESCRIPTION
 *  Cancellation of the application to sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_cancel_app_to_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_close(g_mmi_syncml_cntx.temp_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_entry_app_save_confirm
 * DESCRIPTION
 *  Confirmation of the application to sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_entry_app_save_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_syncml_confirm_display_with_proc(
        GRP_ID_ROOT, 
        (WCHAR*)get_string(STR_GLOBAL_SAVE_ASK),
        CNFM_TYPE_YESNO, 
        mmi_syncml_device_save_app_to_sync,
        mmi_syncml_device_cancel_app_to_sync,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_no_application_popup_proc
 * DESCRIPTION
 *  Confirmation of the application to sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_device_no_application_popup_proc(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct *)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            if (MMI_POPUP_NORMAL_EXIT == evt->result)
            {
                mmi_syncml_confirm_display_with_proc(
                    GRP_ID_SYNC_DEV_MAIN, 
                    (WCHAR*)get_string(STR_ID_SYNC_EDIT_APP_TO_SYNC_QUREY),
                    CNFM_TYPE_YESNO, 
                    mmi_syncml_device_entry_app_to_sync,
                    mmi_frm_scrn_close_active_id,
                    NULL);
            }
            break;
        }
        
        default:
            break;
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_entry_app_to_sync
 * DESCRIPTION
 *  Application to sync 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_entry_app_to_sync(void)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
                        GRP_ID_SYNC_DEV_MAIN, 
                        CUI_MENU_SRC_TYPE_APPCREATE, 
                        CUI_MENU_TYPE_APPSUB, 
                        MENU_ID_SYNCML_DEV_APP_TO_SYNC, 
                        MMI_FALSE, 
                        NULL);

    cui_menu_run(menu_cui_gid);
    
    g_mmi_syncml_cntx.temp_gid = menu_cui_gid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_app_to_sync_entry_evt_hdlr
 * DESCRIPTION
 *  Application to sync 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_app_to_sync_entry_evt_hdlr(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id list_of_ids[SYNCML_SYNC_DEVICE_APP_TOTAL];
    mmi_menu_id i;
    U8 list_of_state[SYNCML_SYNC_DEVICE_APP_TOTAL];
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (i = 0; i < SYNCML_SYNC_DEVICE_APP_TOTAL; i++) 
    {
        list_of_ids[i] = SYNCML_SYNC_DEVICE_APP_PHB + i ;
    }
    
    cui_menu_set_currlist(
        evt->sender_id, 
        SYNCML_SYNC_DEVICE_APP_TOTAL, 
        list_of_ids);
    
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_CHECK_BOX_LIST);

    cui_menu_set_currlist_title(
        evt->sender_id, 
        (UI_string_type)GetString(STR_ID_SYNC_APPLICATIONS), 
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_SYNCML_DEV_MAIN)));

    for(i = 0; i < SYNCML_SYNC_DEVICE_APP_TOTAL; i++)
    {
        cui_menu_set_item_string(
            evt->sender_id, 
            (mmi_menu_id)(SYNCML_SYNC_DEVICE_APP_PHB + i), 
            (UI_string_type)GetString((U16)(STR_ID_SYNC_APP_PHB + i)));
    }

    if (mmi_syncml_dev_setting_p->app_to_sync & SYNCML_DB_PHONEBOOK)
    {
        list_of_state[SYNCML_SYNC_DEVICE_APP_PHB] = 1;
    }
    else
    {
        list_of_state[SYNCML_SYNC_DEVICE_APP_PHB] = 0;
    }
    
#ifdef __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__
    if (mmi_syncml_dev_setting_p->app_to_sync & SYNCML_DB_CALENDAR)
    {
        list_of_state[SYNCML_SYNC_DEVICE_APP_CAL] = 1;
    }
    else
    {
        list_of_state[SYNCML_SYNC_DEVICE_APP_CAL] = 0;
    }
#endif /* __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_DEVICE_TASK_SUPPORT__
    if (mmi_syncml_dev_setting_p->app_to_sync & SYNCML_DB_TASK)
    {
        list_of_state[SYNCML_SYNC_DEVICE_APP_TASK] = 1;
    }
    else
    {
        list_of_state[SYNCML_SYNC_DEVICE_APP_TASK] = 0;
    }
#endif /* __MMI_SYNCML_DEVICE_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    if (mmi_syncml_dev_setting_p->app_to_sync & SYNCML_DB_NOTE)
    {
        list_of_state[SYNCML_SYNC_DEVICE_APP_NOTE] = 1;
    }
    else
    {
        list_of_state[SYNCML_SYNC_DEVICE_APP_NOTE] = 0;
    }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

    cui_menu_set_checkbox_state(evt->sender_id, list_of_state);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_app_to_sync_exit_evt_hdlr
 * DESCRIPTION
 *  Application to sync 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_app_to_sync_exit_evt_hdlr(cui_menu_event_struct* evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    cui_menu_get_checkbox_state(evt->sender_id, mmi_syncml_dev_p->selected_app);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_entry_phones_list
 * DESCRIPTION
 *  Application to sync 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_entry_phones_list(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    S32 hilite_item;
	U8* gui_buffer;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (mmi_syncml_dev_p->total_phones == 0)
	{ 
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_GLOBAL_EMPTY), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);
		return;
	}

	/* name list */
    if (!mmi_frm_scrn_enter(
            GRP_ID_SYNC_DEV_MAIN, 
            SCR_ID_SYNC_DEV_PHONES_LIST,
            NULL, 
            mmi_syncml_device_entry_phones_list, 
            MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
    
    ShowCategory184Screen(
        STR_ID_SYNC_DEV_PHONES,
        GetRootTitleIcon(MENU_ID_SYNCML_DEV_MAIN),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        mmi_syncml_dev_p->total_phones,
        mmi_syncml_device_get_phones,
        0,
        0, /* highlight */
        gui_buffer);

    if (gui_buffer == NULL)
    {
        mmi_syncml_dev_p->selected_dev = mmi_syncml_dev_setting_p->name_id_map[0];
    }
    else
    {
        hilite_item = DynamicListGetHighlightedItem(NULL);
        mmi_syncml_dev_p->selected_dev = mmi_syncml_dev_setting_p->name_id_map[hilite_item];
    }
    		
	RegisterHighlightHandler(mmi_syncml_device_highlight_phone_list);
	
    SetLeftSoftkeyFunction(mmi_syncml_device_entry_phones_options, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);	
    SetCenterSoftkeyFunction(mmi_syncml_device_entry_phones_options, KEY_EVENT_UP);
    
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_syncml_device_phone_list_tap_callback);
#endif
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_phone_list_tap_callback
 * DESCRIPTION
 *  account tap callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_phone_list_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if ((tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM) && wgui_category_if_pop_option_menu())
    {
        mmi_syncml_device_entry_phones_options();
    }
}
#endif /* __MMI_FTE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_get_phones
 * DESCRIPTION
 *  entry phone's option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL mmi_syncml_device_get_phones(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 idx;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	idx = mmi_syncml_dev_setting_p->name_id_map[item_index];

	mmi_ucs2cpy((CHAR*) str_buff, 
	             mmi_syncml_dev_p->name_list[idx - 1]);
	
	*img_buff_p = (PU8) GetImage((U16) (IMG_GLOBAL_L1 + item_index));

	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_highlight_phone_list
 * DESCRIPTION
 *  entry phone's option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_highlight_phone_list(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_syncml_dev_p->selected_dev = mmi_syncml_dev_setting_p->name_id_map[index];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_entry_phones_options
 * DESCRIPTION
 *  entry phone's option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_entry_phones_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
                        GRP_ID_SYNC_DEV_MAIN, 
                        CUI_MENU_SRC_TYPE_RESOURCE, 
                        CUI_MENU_TYPE_OPTION, 
                        MENU_ID_SYNCML_DEV_PHONES_OPTION, 
                        MMI_FALSE, 
                        NULL);
    
    cui_menu_set_default_title(
        menu_cui_gid, 
        (UI_string_type)GetString(STR_GLOBAL_OPTIONS), 
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_SYNCML_DEV_MAIN)));
    
    cui_menu_run(menu_cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_entry_phones_delete_confirm
 * DESCRIPTION
 *  To test whether the two address is same
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_entry_phones_delete(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	CHAR del_ask_str[32];
    mmi_confirm_property_struct arg;
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*) del_ask_str, (CHAR*) get_string(STR_GLOBAL_DELETE));
    mmi_ucs2cat((CHAR*) del_ask_str, (CHAR*) get_string(STR_ID_SYNCML_QUETION_MARK));  

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    
    arg.f_auto_map_empty_softkey = MMI_FALSE;
    
    mmi_syncml_confirm_display_with_proc(
        GRP_ID_ROOT, 
        (WCHAR*)del_ask_str,
        CNFM_TYPE_YESNO, 
        mmi_syncml_device_phones_delete_yes,
        mmi_frm_scrn_close_active_id,
        (void*)&arg);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_phones_exit_delete_process
 * DESCRIPTION
 *  Exit function for delete process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_phones_exit_delete_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_stop_tone(g_mmi_syncml_dev_snd_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_phones_delete_yes
 * DESCRIPTION
 *  To test whether the two address is same
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_phones_delete_yes(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8 *gui_buffer;
	U16 img_id;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            GRP_ID_SYNC_DEV_MAIN, 
            SCR_ID_SYNC_DEV_PHONES_DELETE,
            mmi_syncml_device_phones_exit_delete_process, 
            mmi_syncml_device_phones_delete_yes, 
            MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    
	img_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
	g_mmi_syncml_dev_snd_id = mmi_get_event_based_sound(MMI_EVENT_PROGRESS);
	
    ShowCategory66Screen(
        STR_GLOBAL_DELETE,
        GetRootTitleIcon(MENU_ID_SYNCML_DEV_MAIN),
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_GLOBAL_DELETING),
        img_id,
        gui_buffer);

    if(gui_buffer == NULL &&
       !srv_prof_is_tone_playing(g_mmi_syncml_dev_snd_id))
	{
        srv_prof_play_tone(g_mmi_syncml_dev_snd_id, NULL);
    }
	
    if (gui_buffer == NULL)
    {
        mmi_syncml_device_delete_req(mmi_syncml_dev_p->selected_dev);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_delete_req
 * DESCRIPTION
 *  To test whether the two address is same
 * PARAMETERS
 *  dev_id       [IN]    device id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_delete_req(U8 dev_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_device_account_context_struct accnt;
    mmi_syncml_device_delete_req_struct *del_req_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    del_req_ptr =
        (mmi_syncml_device_delete_req_struct*) construct_local_para(sizeof(mmi_syncml_device_delete_req_struct), TD_CTRL|TD_RESET);
	MMI_ASSERT(del_req_ptr != NULL);

    mmi_syncml_device_read_account(dev_id, (void *)&accnt);
    memcpy(del_req_ptr->device_uri, accnt.dev_uri, MAX_SYNCML_SERVER_ADDR_LEN);
    del_req_ptr->device_uri[MAX_SYNCML_SERVER_ADDR_LEN - 1] = 0;
    
    SetProtocolEventHandler(mmi_syncml_device_delete_rsp, MSG_ID_MMI_SYNCML_DEVICE_DELETE_RSP);
    mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_DEVICE_DELETE_REQ, (oslParaType*)del_req_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_delete_rsp
 * DESCRIPTION
 *  To test whether the two address is same
 * PARAMETERS
 *  param       [IN]    struct for delete result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_delete_rsp(void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_device_delete_rsp_struct *rsp_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param != NULL);
    rsp_ptr = (mmi_syncml_device_delete_rsp_struct *)param;
    
    if (rsp_ptr->result == SYNCML_DEV_OK)
    {       
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_GLOBAL_DELETED), 
            MMI_EVENT_SUCCESS, 
            GRP_ID_SYNC_DEV_MAIN, 
            NULL);
    	memset(mmi_syncml_dev_p->accnt_ptr, 0, sizeof(mmi_syncml_device_account_context_struct));
    	mmi_syncml_dev_p->accnt_ptr->dev_id = 0xFF; /* set as invalid id */
        
    	mmi_syncml_device_update_account(mmi_syncml_dev_p->selected_dev, (void*)mmi_syncml_dev_p->accnt_ptr);

        mmi_syncml_dev_setting_p->last_phb_anchor[mmi_syncml_dev_p->selected_dev - 1] = 0;
        mmi_syncml_device_clearall_change_log(mmi_syncml_dev_p->selected_dev, SYNCML_DB_PHONEBOOK);
        
#ifdef __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__
        mmi_syncml_dev_setting_p->last_cal_anchor[mmi_syncml_dev_p->selected_dev - 1] = 0;
        mmi_syncml_device_clearall_change_log(mmi_syncml_dev_p->selected_dev, SYNCML_DB_CALENDAR);
#endif /* __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_DEVICE_TASK_SUPPORT__
        mmi_syncml_dev_setting_p->last_task_anchor[mmi_syncml_dev_p->selected_dev - 1] = 0;
        mmi_syncml_device_clearall_change_log(mmi_syncml_dev_p->selected_dev, SYNCML_DB_TASK);
#endif /* __MMI_SYNCML_DEVICE_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        mmi_syncml_dev_setting_p->last_note_anchor[mmi_syncml_dev_p->selected_dev - 1] = 0;
        mmi_syncml_device_clearall_change_log(mmi_syncml_dev_p->selected_dev, SYNCML_DB_NOTE);
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

        mmi_syncml_device_update_setting();
        
    	mmi_syncml_device_read_namelist();

        /* If no phone remain, then don't show phone list screen. */
    	if (mmi_syncml_dev_p->total_phones == 0)
    	{
    	    mmi_frm_scrn_close(GRP_ID_SYNC_DEV_MAIN, SCR_ID_SYNC_DEV_PHONES_LIST);
    	}
    }
    else
    {
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_GLOBAL_ERROR), 
            MMI_EVENT_FAILURE, 
            GRP_ID_SYNC_DEV_MAIN, 
            NULL);
    }
    
    mmi_frm_scrn_close(GRP_ID_SYNC_DEV_MAIN, SCR_ID_SYNC_DEV_PHONES_DELETE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_entry_phones_delete_confir
 * DESCRIPTION
 *  To test whether the two address is same
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_entry_phones_delete_all(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	CHAR del_ask_str[32];
    mmi_confirm_property_struct arg;
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*) del_ask_str, (CHAR*) get_string(STR_GLOBAL_DELETE_ALL));
    mmi_ucs2cat((CHAR*) del_ask_str, (CHAR*) get_string(STR_ID_SYNCML_QUETION_MARK));

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    
    arg.f_auto_map_empty_softkey = MMI_FALSE;
    
    mmi_syncml_confirm_display_with_proc(
        GRP_ID_ROOT, 
        (WCHAR*)del_ask_str,
        CNFM_TYPE_YESNO, 
        mmi_syncml_device_phones_delete_all_yes,
        mmi_frm_scrn_close_active_id,
        (void*)&arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_phones_delete_all_yes
 * DESCRIPTION
 *  To test whether the two address is same
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_phones_delete_all_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 img_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            GRP_ID_SYNC_DEV_MAIN, 
            SCR_ID_SYNC_DEV_PHONES_DELETE_ALL,
            mmi_syncml_device_phones_exit_delete_process, 
            mmi_syncml_device_phones_delete_all_yes, 
            MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        
	img_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
	g_mmi_syncml_dev_snd_id = mmi_get_event_based_sound(MMI_EVENT_PROGRESS);
	
    ShowCategory66Screen(
        STR_GLOBAL_DELETE_ALL,
        GetRootTitleIcon(MENU_ID_SYNCML_DEV_MAIN),
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_GLOBAL_DELETING),
        img_id,
        gui_buffer);
    
    if(gui_buffer == NULL &&
       !srv_prof_is_tone_playing(g_mmi_syncml_dev_snd_id))
	{
        srv_prof_play_tone(g_mmi_syncml_dev_snd_id, NULL);
    }
	  
    if (gui_buffer == NULL)
    {
        mmi_syncml_device_delete_all_req();
    }
    
    /* Keep in deleting screen and no input can be accepted */
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_delete_all_req
 * DESCRIPTION
 *  To test whether the two address is same
 * PARAMETERS
 *  param       [IN]    struct for delete result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_delete_all_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_device_delete_req_struct *del_req_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    del_req_ptr =
        (mmi_syncml_device_delete_req_struct*) construct_local_para(sizeof(mmi_syncml_device_delete_req_struct), TD_CTRL|TD_RESET);
	MMI_ASSERT(del_req_ptr != NULL);
    
    SetProtocolEventHandler(mmi_syncml_device_delete_all_rsp, MSG_ID_MMI_SYNCML_DEVICE_DELETE_ALL_RSP);
    mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_DEVICE_DELETE_ALL_REQ, (oslParaType*)del_req_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_delete_all_rsp
 * DESCRIPTION
 *  To test whether the two address is same
 * PARAMETERS
 *  param       [IN]    struct for delete result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_delete_all_rsp(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_device_delete_all_rsp_struct *rsp_ptr;
  
#ifdef __MTK_TARGET__
	MMIEQNVRAMRESETREQ *local_data;
#endif 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param != NULL);
    rsp_ptr = (mmi_syncml_device_delete_all_rsp_struct *)param;

    /* SYNCML_DEV_OK, reset nvram info  */
    if (rsp_ptr->result == SYNCML_DEV_OK)
    {
#ifdef __MTK_TARGET__
    	local_data = (MMIEQNVRAMRESETREQ*) OslConstructDataPtr(sizeof(MMIEQNVRAMRESETREQ));

    	local_data->lid = NVRAM_EF_SYNCML_DEV_ACCOUNT_LID;

    	local_data->reset_category = NVRAM_RESET_CERTAIN;
        local_data->rec_index = 1;
        local_data->rec_amount = NVRAM_EF_SYNCML_DEV_ACCOUNT_TOTAL;

    	SetProtocolEventHandler(mmi_syncml_device_phones_reset_hdlr, MSG_ID_MMI_EQ_NVRAM_RESET_RSP);
        mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_NVRAM_RESET_REQ, (oslParaType*)local_data, NULL);
#else
    	mmi_syncml_device_phones_reset_hdlr(NULL);
#endif /* __MTK_TARGET__ */
    }
    /* SYNCML_DEV_ERROR, do nothing */
    else 
    {
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_GLOBAL_ERROR), 
            MMI_EVENT_FAILURE, 
            GRP_ID_SYNC_DEV_MAIN, 
            NULL);        
        mmi_frm_scrn_close(GRP_ID_SYNC_DEV_MAIN, SCR_ID_SYNC_DEV_PHONES_DELETE_ALL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_phones_reset_hdlr
 * DESCRIPTION
 *  To test whether the two address is same
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_phones_reset_hdlr(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_popup_display_simple(
        (WCHAR*)get_string(STR_GLOBAL_DELETED), 
        MMI_EVENT_SUCCESS, 
        GRP_ID_SYNC_DEV_MAIN, 
        NULL); 
    /* Set current account to invalid */
    memset(mmi_syncml_dev_p->accnt_ptr, 0, sizeof(mmi_syncml_device_account_context_struct));
    mmi_syncml_dev_p->accnt_ptr->dev_id = 0xFF;
    
#ifndef __MTK_TARGET__
	for (i = 0; i < MAX_SYNCML_DEV_NUM; i++)
	{
		mmi_syncml_device_update_account((U8)(i + 1), (void*)mmi_syncml_dev_p->accnt_ptr);
	}
    
#endif /* __MTK_TARGET__ */

    /* Restet anchor and change log */
    for (i = 0; i < MAX_SYNCML_DEV_NUM; i++)
    {
        mmi_syncml_dev_setting_p->last_phb_anchor[i] = 0;
        mmi_syncml_device_clearall_change_log(mmi_syncml_dev_p->selected_dev, SYNCML_DB_PHONEBOOK);

#ifdef __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__
        mmi_syncml_dev_setting_p->last_cal_anchor[i] = 0;
        mmi_syncml_device_clearall_change_log(mmi_syncml_dev_p->selected_dev, SYNCML_DB_CALENDAR);
#endif /* __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_DEVICE_TASK_SUPPORT__
        mmi_syncml_dev_setting_p->last_task_anchor[i] = 0;
        mmi_syncml_device_clearall_change_log(mmi_syncml_dev_p->selected_dev, SYNCML_DB_TASK);
#endif /* __MMI_SYNCML_DEVICE_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        mmi_syncml_dev_setting_p->last_note_anchor[i] = 0;
        mmi_syncml_device_clearall_change_log(mmi_syncml_dev_p->selected_dev, SYNCML_DB_NOTE);
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

    }
    mmi_syncml_device_update_setting();

    /* Update the namelist */
    mmi_syncml_device_read_namelist();
    
    mmi_frm_scrn_close(GRP_ID_SYNC_DEV_MAIN, SCR_ID_SYNC_DEV_PHONES_DELETE_ALL);
    mmi_frm_scrn_close(GRP_ID_SYNC_DEV_MAIN, SCR_ID_SYNC_DEV_PHONES_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_phones_start_sync_precheck
 * DESCRIPTION
 *  To test whether the two address is same
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_phones_start_sync_precheck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_device_account_context_struct *accnt_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Has accept the phone connection, should reject the role as Device A
     */
    if (g_mmi_syncml_common_cntx.cm_conn_id != MMI_SYNCML_DEV_INVALID_CONN_ID 
        && !mmi_syncml_is_sync_now())
    {
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_ID_SYNC_CODE_FORBIDDEN), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL); 
        return;
    }
    
    if (mmi_syncml_dev_setting_p->app_to_sync == 0)
    {   
        mmi_syncml_popup_display_with_proc(
            GRP_ID_SYNC_DEV_MAIN,
            (WCHAR*)get_string(STR_ID_SYNC_NO_APPLICATION), 
            MMI_EVENT_FAILURE, 
            mmi_syncml_device_no_application_popup_proc, 
            NULL);
        return;
    }	
    
#if defined(__MMI_BT_AUDIO_SUPPORT__)
    if (mmi_bt_sco_is_connected(MMI_BT_SCO_HFP_SCO) && 
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        mmi_bt_popup_operation_not_allowed();
        return;
    }
#endif /* __MMI_BT_AUDIO_SUPPORT__ */
    
    if (!mmi_bt_is_permission(MMI_TRUE))
    {
        return;
    }
    
    
    accnt_ptr = mmi_syncml_dev_p->accnt_ptr;

    mmi_syncml_device_read_account(mmi_syncml_dev_p->selected_dev, (void *)accnt_ptr);
    memcpy(&g_mmi_syncml_common_cntx.remote_bt_addr, &accnt_ptr->dev_bt_addr, sizeof(srv_bt_cm_bt_addr));/*BT concurrency */

#ifdef __MMI_BT_AUTHORIZE__
    if (srv_bt_cm_get_authorize(&g_mmi_syncml_common_cntx.remote_bt_addr) == SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT)
    {
        mmi_bt_popup_prohibited_by_blocked_device();
        return;
    }
#endif /* __MMI_BT_AUTHORIZE__ */

    if (mmi_bt_is_power_on(MMI_FALSE))
    {
        mmi_syncml_device_phones_start_sync();
    }
    else
    {
		/* only bt power off, need use bt power on cui */	
        mmi_syncml_device_sync_entry_bt_power_on_cui();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_syncml_device_sync_entry_bt_power_on_cui
* DESCRIPTION
*  bt cui
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_syncml_device_sync_entry_bt_power_on_cui(void)
{
   	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/  
    mmi_id gid;
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/     
    gid = cui_bt_power_on_create(GRP_ID_SYNC_DEV_MAIN);

    if (gid != GRP_ID_INVALID)
    {
        cui_bt_power_on_run(gid);
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_sync_entry_bt_select_cui
 * DESCRIPTION
 *  bt cui
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_sync_entry_bt_select_cui(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/  
    mmi_id gid;
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/ 
	gid = cui_bt_device_select_screen_create(GRP_ID_SYNC_DEV_MAIN);

    if (gid != GRP_ID_INVALID)
    {
        cui_bt_device_select_screen_set_mask(
            gid, 
            MMI_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK | 
            MMI_BT_PHONE_MAJOR_DEVICE_MASK |
            MMI_BT_TELEPHONY_MAJOR_SERVICE_MASK, 
            0);
        
        cui_bt_device_select_screen_set_option_flag(
            gid, 
            CUI_BT_CM_DEVICE_SELECT_OPTION_SELECT);
        
        cui_bt_device_select_screen_run(gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_group_bt_cui_proc
 * DESCRIPTION
 *  process function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_device_group_bt_cui_proc(mmi_event_struct* event)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/  
    cui_event_bt_cm_device_select_result_struct *bt_selete_evt;
    cui_event_bt_cm_power_on_result_struct *bt_power_on_evt;
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/ 
    switch(event->evt_id)
    {
        case EVT_ID_CUI_BT_CM_POWER_ON_RESULT:
            
            bt_power_on_evt = (cui_event_bt_cm_power_on_result_struct*)event;
            
            mmi_syncml_device_bt_pwron_callback(bt_power_on_evt->result);
            
            cui_bt_power_on_close(GRP_ID_BT_CM_POWER_ON_CNF);  
            
            break;
            
        case EVT_ID_CUI_BT_CM_DEVICE_SELECT:
            
            bt_selete_evt = (cui_event_bt_cm_device_select_result_struct*)event;

            mmi_syncml_device_sel_hdlr(bt_selete_evt->result, bt_selete_evt->lap, bt_selete_evt->uap, bt_selete_evt->nap);
            
            cui_bt_device_select_screen_close(GRP_ID_BT_CM_SELECT_DEVICE);   
            
            break;

        case EVT_ID_GROUP_DEINIT:
            /* handle endkey */
            break;
            
        default:
            break;
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_syncml_device_bt_pwron_callback
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_syncml_device_bt_pwron_callback(MMI_BOOL result)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    if (result)
    {
        mmi_syncml_device_phones_start_sync();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_phones_start_sync
 * DESCRIPTION
 *  To test whether the two address is same
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_phones_start_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_device_account_context_struct *accnt_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    accnt_ptr = mmi_syncml_dev_p->accnt_ptr;

    /* Account has been ready at precheck */
    mmi_ucs2cpy((CHAR*)g_mmi_syncml_common_cntx.remote_dev_name, (CHAR*)accnt_ptr->dev_name);
    
	g_mmi_syncml_cntx.is_dev_sync = MMI_TRUE;
	g_mmi_syncml_common_cntx.dev_role = MMI_SYNCML_DEV_ROLE_A;
    
    mmi_syncml_device_state_pre_check();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_entry_phones_rename
 * DESCRIPTION
 *  To test whether the two address is same
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_entry_phones_rename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 fseditor_gid;
    U16 title_icon;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fseditor_gid = cui_fseditor_create(GRP_ID_SYNC_DEV_MAIN);

    if (fseditor_gid != GRP_ID_INVALID)
    {
        title_icon = GetRootTitleIcon(MENU_ID_SYNCML_DEV_MAIN),
 
        cui_fseditor_set_title(fseditor_gid, STR_GLOBAL_RENAME, title_icon);
        
        mmi_ucs2cpy(
            (CHAR*)g_syncml_device_accnt_name_buffer,
            (CHAR*)mmi_syncml_dev_p->name_list[mmi_syncml_dev_p->selected_dev - 1]);
        
        cui_fseditor_set_buffer(
            fseditor_gid, 
            g_syncml_device_accnt_name_buffer, 
            (MAX_SYNCML_DEV_NAME_LEN + 1) * ENCODING_LENGTH,
            (SRV_BT_CM_BD_NAME_UCS2_LEN - 2) / ENCODING_LENGTH);
        
        cui_fseditor_set_input_method(
            fseditor_gid, 
            IMM_INPUT_TYPE_SENTENCE, 
            NULL,
            INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
        
        g_mmi_syncml_cntx.temp_gid = fseditor_gid;
        
        cui_fseditor_run(fseditor_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_profile_edit_name_save
 * DESCRIPTION
 *  "Profile Name" menu save function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_rename_save(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 index;
    cui_fseditor_evt_struct *evt = (cui_fseditor_evt_struct *)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_fseditor_get_text(
        evt->sender_id, 
        (WCHAR *)g_syncml_device_accnt_name_buffer, 
        (MAX_SYNCML_DEV_NAME_LEN + 1) * ENCODING_LENGTH);
        
    if (mmi_ucs2strlen((CHAR*)g_syncml_device_accnt_name_buffer) == 0)
    {        
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_GLOBAL_EMPTY), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);
        return;
    }
    
    mmi_popup_display_simple(
        (WCHAR*)get_string(STR_GLOBAL_SAVED), 
        MMI_EVENT_SUCCESS, 
        GRP_ID_ROOT, 
        NULL);
	index = mmi_syncml_dev_p->selected_dev - 1;
    mmi_syncml_device_read_account(mmi_syncml_dev_p->selected_dev, (void *)mmi_syncml_dev_p->accnt_ptr);
	mmi_ucs2cpy((CHAR*)mmi_syncml_dev_p->accnt_ptr->dev_name, (CHAR*)g_syncml_device_accnt_name_buffer);
	
    mmi_ucs2cpy((CHAR*)mmi_syncml_dev_p->name_list[index], (CHAR*)mmi_syncml_dev_p->accnt_ptr->dev_name);

	mmi_syncml_device_update_account(mmi_syncml_dev_p->selected_dev, (void *)mmi_syncml_dev_p->accnt_ptr);
	memset(&g_syncml_device_accnt_name_buffer, 0, 2);

	cui_fseditor_close(g_mmi_syncml_cntx.temp_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_read_sync_log
 * DESCRIPTION
 *  Read sync log info from nvram
 * PARAMETERS
 *  record_id		[IN]		record id
 *	nvram_buffer	[IN]		nvram data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_read_sync_log(U8 record_id, void* nvram_buffer)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S16 error;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
   ReadRecord(
	   NVRAM_EF_SYNCML_DEV_SYNC_LOG_LID,
	   (U16)record_id,
	   nvram_buffer,
	   NVRAM_EF_SYNCML_DEV_SYNC_LOG_SIZE,
	   &error);
	
	if (error != NVRAM_READ_SUCCESS) 
	{
	    MMI_ASSERT(!"SyncMLDev read sync log nvram error");
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_entry_phones_viewlog
 * DESCRIPTION
 *  To test whether the two address is same
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_entry_phones_view_log(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_syncml_cntx.is_dev_log = MMI_TRUE;
    mmi_ucs2cpy((CHAR*)g_mmi_syncml_common_cntx.remote_dev_name,  
                (CHAR*)mmi_syncml_dev_p->name_list[mmi_syncml_dev_p->selected_dev - 1]);
    mmi_syncml_entry_sync_log();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_go_back_history
 * DESCRIPTION
 *  Go back history function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_go_back_history(void)
{
#if defined(__MMI_NCENTER_SUPPORT__)
	mmi_syncml_ncenter_sync_bkg_create(MMI_SYNCML_NOTIFICATION_SYNC_DEVICE);
#endif
	GoBackHistory();
}


#define MMI_SYNCML_DEV_HILITE_HDLR
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_highlight_new_sync_menu
 * DESCRIPTION
 *  To test whether the two address is same
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_highlight_phonesync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_syncml_device_group_entry_main_menu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_syncml_device_go_back_history, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_syncml_device_group_entry_main_menu, KEY_EVENT_UP);
}


#define MMI_SYNCML_DEV_UTIL
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_is_viewlog
 * DESCRIPTION
 *  To check whether this device is syncable,
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_syncml_device_is_viewlog(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    return g_mmi_syncml_cntx.is_dev_log;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_locate_new_dev
 * DESCRIPTION
 *    Locate the incoming device position, if it is known one, locate to the selected 
 *  device, if it is unknow, then add it to device list
 * PARAMETERS
 *  bt_addr		[IN]
 *  peer_flag   [IN]    peer the remote device, don't set the current context
 * RETURNS
 *  MMI_BOOL	
 *****************************************************************************/
MMI_BOOL mmi_syncml_device_locate_new_dev(srv_bt_cm_bt_addr *bt_addr, MMI_BOOL peer_flag)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    mmi_syncml_device_account_context_struct *accnt_ptr;
	U8 first_slot = 0xFF;
    MMI_BOOL ret = MMI_FALSE;
	U8 i;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	/* Locate the new coming device */
    accnt_ptr = mmi_syncml_dev_p->accnt_ptr;
    
	for (i = 0; i < MAX_SYNCML_DEV_NUM; i++)
	{
		mmi_syncml_device_read_account((U8)(i + 1), (void *)accnt_ptr);
		if (accnt_ptr->dev_id == 0xFF)
		{
			if (first_slot == 0xFF)
			{
				first_slot = i;
			}	
		}
		/* Already exist device */
		else if (mmi_syncml_device_bt_addr_compare((srv_bt_cm_bt_addr *)&accnt_ptr->dev_bt_addr, bt_addr))
        {      
            /* If the incoming device has exist, then use the name in phone list */
            if (peer_flag)
            {
                mmi_ucs2cpy((CHAR*)g_mmi_syncml_common_cntx.remote_dev_name, (CHAR*)accnt_ptr->dev_name);
            }
            else /* Using the original role of the last sync */
            {
                mmi_syncml_dev_p->sync_role = accnt_ptr->role;
    			mmi_syncml_dev_p->selected_dev = i + 1;
            }
            ret = MMI_TRUE;
			break;
		}
	}

	/* New device, add to the device list  */
	if (i == MAX_SYNCML_DEV_NUM && !peer_flag)
	{
		if (first_slot == 0xFF)
		{
			/* No slot to install new device, return */
            ret = MMI_FALSE;
		}
		else
		{
		    mmi_syncml_dev_p->is_new_dev = MMI_TRUE;
            mmi_syncml_dev_p->selected_dev = first_slot + 1;
            ret = MMI_TRUE;
		}
	}
    MMI_SYNCML_TRACE3(MMI_SYNCML_DEV_LOCATE, mmi_syncml_dev_p->is_new_dev, mmi_syncml_dev_p->selected_dev, mmi_syncml_dev_p->sync_role);
    
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_sync_reentry_check
 * DESCRIPTION
 *  Notify Syncml task about BT power on, syncml task will register OBEX
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL    Can reentry or not	
 *****************************************************************************/
static MMI_BOOL mmi_syncml_device_sync_reentry_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL sync_flag;
    U16 curr_state = mmi_syncml_device_get_curr_state();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sync_flag = mmi_syncml_is_sync_now();
    
    MMI_SYNCML_TRACE5(MMI_SYNCML_DEV_REENTRY, 
                      sync_flag, 
                      g_mmi_syncml_common_cntx.cm_conn_id, 
                      g_mmi_syncml_cntx.is_pre_sync, 
                      g_mmi_syncml_cntx.is_dev_sync, 
                      g_mmi_syncml_common_cntx.dev_role);

    /* (passive) after connected, haven't accept sync yet */
    if (!sync_flag && 
        g_mmi_syncml_common_cntx.cm_conn_id != MMI_SYNCML_DEV_INVALID_CONN_ID)
    {
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_ID_SYNC_CODE_FORBIDDEN), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);
        return MMI_FALSE;
    }
    
    if (sync_flag || g_mmi_syncml_cntx.is_pre_sync == 1)
    {
        /* Phone sync is syncing */
        if (g_mmi_syncml_cntx.is_dev_sync)
        {            
            mmi_syncml_group_entry_sync_start(GRP_ID_ROOT);
        }
        
        /* DS(PC sync) is syncing, then return */
        else
        {
            /* accept conn_ask, but sync_ask do not arrive */
            if (g_mmi_syncml_common_cntx.dev_role == MMI_SYNCML_DEV_ROLE_B &&
                g_mmi_syncml_common_cntx.cm_conn_id == MMI_SYNCML_DEV_INVALID_CONN_ID)
            {
                return MMI_FALSE;
            }
            mmi_popup_display_simple(
                (WCHAR*)get_string(STR_ID_SYNC_CODE_FORBIDDEN), 
                MMI_EVENT_FAILURE, 
                GRP_ID_ROOT, 
                NULL);
        }
        
        return MMI_FALSE;
    }
    
    return MMI_TRUE;
}       


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_state_pre_check
 * DESCRIPTION
 *  Notify Syncml task about BT power on, syncml task will register OBEX
 * PARAMETERS
 *  void
 * RETURNS
 *  void	
 *****************************************************************************/
void mmi_syncml_device_state_pre_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_syncml_is_sync_now() && g_mmi_syncml_common_cntx.dev_role == MMI_SYNCML_DEV_ROLE_A)
    {
        g_mmi_syncml_cntx.is_pre_sync = 1;
    }
   
    if (g_mmi_syncml_common_cntx.dev_role == MMI_SYNCML_DEV_ROLE_A)
    {
        mmi_syncml_dev_p->app_to_sync = mmi_syncml_dev_setting_p->app_to_sync;
    }
    else /* If Dev B, this param is unknow at this time */
    {
        mmi_syncml_dev_p->app_to_sync = 0;
    }
    
    mmi_syncml_dev_setting_p->report_status = 1;
    
    mmi_syncml_device_sync_pre_check(mmi_syncml_device_pre_check_callback);   
}	

	        
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_sync_pre_check
 * DESCRIPTION
 *  Notify Syncml task about BT power on, syncml task will register OBEX
 * PARAMETERS
 *  void
 * RETURNS
 *  void	
 *****************************************************************************/
static void mmi_syncml_device_sync_pre_check(mmi_syncml_device_client_callback client_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_syncml_device_account_context_struct *accnt_ptr;
	CHAR name_buff[MAX_SYNCML_DEV_NAME_LEN + 1] = {'\0'};
    U8 dev_role;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_syncml_is_sync_now())
    {
        g_mmi_syncml_cntx.is_pre_sync = 1;
    }
    
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
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
#endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

    if (!mmi_syncml_is_phb_ready_inner())
    {
        /* phonebook busy */
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_ID_SYNC_PHB_BUSY), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);
        CALLBACK_FUNC(client_callback, MMI_SYNCML_DEVICE_ERROR_PRE_CHECK);
        return;
    }
    
    dev_role = mmi_syncml_device_get_curr_role();
    
    if (MMI_SYNCML_DEV_ROLE_A == dev_role)
    {

		/* get local device name from bt cm */
    	srv_bt_cm_get_dev_name(
        	&g_mmi_syncml_common_cntx.remote_bt_addr,
        	(MAX_SYNCML_DEV_NAME_LEN + 1), 
        	(U8*)name_buff);

		
		g_mmi_syncml_common_cntx.cm_conn_id = srv_bt_cm_start_conn(MMI_FALSE, 
					SRV_BT_CM_SYNCML_DEV_PROFILE_UUID,
        			&g_mmi_syncml_common_cntx.remote_bt_addr,
					name_buff);
		
		// need to handle error infomation
		if (g_mmi_syncml_common_cntx.cm_conn_id < 0)
		{
			mmi_popup_display_simple(
            	(WCHAR*)get_string(STR_ID_SYNC_CONN_BT_BUSY), 
            	MMI_EVENT_FAILURE, 
            	GRP_ID_ROOT, 
            	NULL);
			CALLBACK_FUNC(client_callback, MMI_SYNCML_DEVICE_ERROR_PRE_CHECK);
			return;
		}	
	}

    CALLBACK_FUNC(client_callback, MMI_SYNCML_DEVICE_ERROR_SUCCESS);
    
    if (MMI_SYNCML_DEV_ROLE_A == dev_role)
    {
        mmi_syncml_group_entry_sync_start(GRP_ID_SYNC_DEV_MAIN);
    }
    else if(MMI_SYNCML_DEV_ROLE_B == dev_role)
    {        
        mmi_syncml_group_entry_sync_start(GRP_ID_ROOT);
    }
    else
    {
        ASSERT("Role error");
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
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */
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
}

        
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_get_setting_cntx
 * DESCRIPTION
 *  Notify Syncml task about BT power on, syncml task will register OBEX
 * PARAMETERS
 *  void
 * RETURNS
 *  void	
 *****************************************************************************/
void* mmi_syncml_device_get_setting_cntx(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    return (void*)&g_mmi_syncml_device_setting_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_device_sync
 * DESCRIPTION
 *  Check function if email is ready to sync
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
MMI_BOOL mmi_syncml_is_device_sync(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/    
    return g_mmi_syncml_cntx.is_dev_sync;
}


#define Common_UI_part
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_menu_cui_entry_evt_hdlr
 * DESCRIPTION
 *  Entry main menu for device sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_menu_cui_entry_evt_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct*)param;

    switch(evt->parent_menu_id)
    {
        case MENU_ID_SYNCML_DEV_MAIN:
        {
            /* should update the phone number */
            mmi_syncml_device_read_namelist();
            break;
        }
        case MENU_ID_SYNCML_DEV_APP_TO_SYNC:
        {
            mmi_syncml_device_app_to_sync_entry_evt_hdlr(evt);
            break;
        }
       
		default:
			break;
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_menu_cui_select_evt_hdlr
 * DESCRIPTION
 *  Entry main menu for device sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_menu_cui_select_evt_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct*)param;

    /* press done in app to sync screen */
    if (MENU_ID_SYNCML_DEV_APP_TO_SYNC == evt->parent_menu_id)
    {
        mmi_syncml_device_entry_app_save_confirm();
        return;
    }
    
    switch(evt->highlighted_menu_id)
    {
        case MENU_ID_SYNCML_DEV_SYNC:
        {
            mmi_syncml_device_entry_new_sync_menu();
            break;
        }
        case MENU_ID_SYNCML_DEV_APP_TO_SYNC:
        {
            mmi_syncml_device_entry_app_to_sync();
            break;
        }
        case MENU_ID_SYNCML_DEV_PHONES:
        {
            mmi_syncml_device_entry_phones_list();
            break;
        }
        case MENU_ID_SYNCML_DEV_PHONES_OPTION:
        {
            mmi_syncml_device_entry_phones_options();
            break;
        }
        case MENU_ID_SYNCML_DEV_PHONES_OPTION_SYNC:
        {
            mmi_syncml_device_phones_start_sync_precheck();
            break;
        }
        case MENU_ID_SYNCML_DEV_PHONES_OPTION_RENAME:
        {
            mmi_syncml_device_entry_phones_rename();
            break;
        }
        case MENU_ID_SYNCML_DEV_PHONES_OPTION_VIEWLOG:
        {
            mmi_syncml_device_entry_phones_view_log();
            break;
        }
        case MENU_ID_SYNCML_DEV_PHONES_OPTION_DELETE:
        {
            mmi_syncml_device_entry_phones_delete();
            break;
        }
        case MENU_ID_SYNCML_DEV_PHONES_OPTION_DELETE_ALL:
        {
            mmi_syncml_device_entry_phones_delete_all();
            break;
        }
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_menu_cui_exit_evt_hdlr
 * DESCRIPTION
 *  Entry main menu for device sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_menu_cui_exit_evt_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct*)param;
    
    switch(evt->parent_menu_id)
    {
        case MENU_ID_SYNCML_DEV_APP_TO_SYNC:
        {
            mmi_syncml_device_app_to_sync_exit_evt_hdlr(evt);
            break;
        }

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_menu_cui_notify_close_evt_hdlr
 * DESCRIPTION
 *  Entry main menu for device sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_menu_cui_notify_close_evt_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct*)param;
    cui_menu_close(evt->sender_id);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_group_entry_main_menu
 * DESCRIPTION
 *  Entry main menu for device sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_device_group_main_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    switch(param->evt_id)
    {
        case EVT_ID_SYNC_MINIMIZE:
        {
            mmi_frm_group_close(GRP_ID_SYNC_DEV_MAIN);
            break;
        }
        
        /* menu cui event hdlr */
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_syncml_device_menu_cui_select_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            mmi_syncml_device_menu_cui_entry_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_MENU_LIST_EXIT:
        {
            mmi_syncml_device_menu_cui_exit_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            mmi_syncml_device_menu_cui_notify_close_evt_hdlr(param);
            break;
        }

        /* bt select and power on CUI */
        case EVT_ID_CUI_BT_CM_DEVICE_SELECT:
        case EVT_ID_CUI_BT_CM_POWER_ON_RESULT:
        {
            mmi_syncml_device_group_bt_cui_proc(param);
            break;
        }
        
        /* full editor CUI */
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        {
            mmi_syncml_device_rename_save(param);
            break;
        }
        case EVT_ID_CUI_FSEDITOR_ABORT:
        {
            cui_fseditor_close(g_mmi_syncml_cntx.temp_gid);
            break;
        }
        
        case EVT_ID_GROUP_DEINIT:
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}

#endif /* __MMI_SYNCML_DEVICE_SYNC__ */


