/**************************************************************
* Header Files Include
**************************************************************/
#include "MMI_features.h"
#ifdef __MMI_BT_MAP_CLIENT__

#include "GlobalResDef.h"
#include "kal_general_types.h"
#include "CustDataRes.h"
#include "GlobalConstants.h"
#include "gui_data_types.h"
#include "wgui_categories_util.h"
#include "gui_typedef.h"
#include "Unicodexdcl.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "ImeGprot.h"
#include "string.h"
#include "ps_public_enum.h"
#include "mmi_rp_app_sms_def.h"
#include "MessagesMiscell.h"
#include "ems.h"
#include "Wgui_ems.h"
#include "Ems.h"
#include "SmsAppGprot.h"
#include "SmsAppProt.h"
#include "SmsAppType.h"
#include "SmsAppUtil.h"
#include "SmsCuiGprot.h"
#include "SmsSrvGprot.h"

#include "AlarmFrameworkProt.h"

#include "PhbSrvGprot.h"
#include "PhbCuiGprot.h"
#include "Conversions.h"
#include "gui_ems.h"
#include "mmi_rp_app_sms_def.h"

/**************************************************
******* BT headers ********************************
**************************************************/

#include "SmsUmBtMapProt.h"
#include "SmsBtAppProt.h"
#include "SmsBtmapcSrvStorage.h"
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__ 
#include "BookmarkCuiGprot.h"
#endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__  */

#include "UcmSrvGprot.h"
#include "UmGprot.h"
#ifdef __MMI_SMS_APP_EMS_SUPPORT__
#include "SmsAppEms.h"
#endif
#include "MenuCuiGprot.h"
#include "SimCtrlSrvGProt.h"
#include "NwUsabSrvGprot.h"
#include "wgui_categories_UCE.h"
#ifdef __ULC_SLIM_EMS__
/* used when EMS lib did not provide charactor counter function */
#include "Gsm7BitNationalLang.h"
#include "wgui_categories_UCE.h"
#endif /* __ULC_SLIM_EMS__ */
#include "SmsUmBtMapProt.h"
#include "mmi_rp_app_smsbtunifiedmessage_def.h"  /*added for resgen */
#include "SmsBtMapCSrvGProt.h"
#include "UcmGprotBt.h"
#include "UcmGprot.h"
#include "GlobalResDef.h"

#undef __MMI_MESSAGE_SMS_HILITE_VIEWER__


#define MMI_SMS_BT_MAX_DETAILS_SCREEN_BUFFER   150

static WCHAR *sms_bt_detail_buff = NULL;

extern mmi_sms_bt_entry_folder_userdata g_ef_usdata;
extern mmi_um_tab_page g_tab_last_enter;
static mmi_frm_nmgr_alert_struct g_bt_new_msg_alert;
NMGR_HANDLE g_new_bt_msg_handle;
U8 g_new_bt_msg_dev_mask = 0;

static void mmi_sms_bt_viewer_pre_entry_details(void);
static mmi_ret mmi_sms_bt_editor_scrn_leave_proc(mmi_event_struct *param);
static mmi_ret mmi_sms_bt_group_entry_proc(mmi_event_struct* evt);
static mmi_ret mmi_sms_bt_editor_scrn_leave_proc(mmi_event_struct *param);
static mmi_ret mmi_sms_group_entry_proc(mmi_event_struct* evt);

static U32 mmi_sms_editor_remaining_char_count(wgui_uce_text_info_struct *current_text_info);
static U32 mmi_sms_editor_segment_count(wgui_uce_text_info_struct *current_text_info);
static U32 mmi_sms_editor_get_message_size_callback(wgui_uce_text_info_struct *current_text_info, wgui_uce_msg_type_enum uce_msg_type);
static wgui_uce_text_change_result_enum mmi_sms_editor_text_change_callback(wgui_uce_text_info_struct *new_text_info);
static wgui_uce_display_enum mmi_sms_editor_display_type_callback(void);
static void mmi_sms_bt_menu_cui_select_hdlr(mmi_event_struct* evt);
static void mmi_sms_bt_pre_entry_viewer_opt(void);
static void mmi_sms_bt_go_back_from_viewer(void);
static mmi_ret mmi_sms_bt_viewer_scrn_leave_proc(mmi_event_struct *param);
static void mmi_sms_bt_view_curr_msg_callback(mmi_sms_result_enum result, void *data);
static void mmi_sms_read_msg_rsp(srv_sms_callback_struct* callback_data);
static U8 *mmi_sms_bt_get_viewer_header(void);
static void mmi_sms_bt_default_viewer_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
static void mmi_sms_bt_viewer_opt_reply(void);
static void mmi_sms_bt_viewer_opt_forward();
static void mmi_sms_viewer_opt_operation(mmi_sms_bt_send_case_enum send_case);
static void mmi_sms_bt_viewer_opt_operation(mmi_sms_bt_send_case_enum send_case);
static void mmi_sms_bt_entry_editor_options(void);
static void mmi_sms_bt_ed_opt_save_to_drafts();
static mmi_ret mmi_sms_bt_save_to_drafts_proc(mmi_event_struct *evt);
static void mmi_sms_ed_send_to();
static void mmi_sms_bt_viewer_opt_delete(void);
void mmi_sms_bt_entry_add_recipient(void);
static void mmi_sms_bt_update_ems_length(EMSData *ems_data);
static void mmi_sms_bt_get_msg_callback (srv_sms_callback_struct* callback_data);
static void mmi_sms_bt_draft_viewer_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
void mmi_sms_count_buffer_charactor(const S8 *content_buffer, mmi_7bit_counter_struct *content_text_info);
static void mmi_sms_update_editor_info(CHAR* text_buff);
typedef void (*SmsCBFuncPtr) (mmi_sms_result_enum, void*);
static void mmi_sms_bt_viewer_call_sender(void);
static void mmi_sms_bt_default_outbox_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
static void mmi_sms_bt_default_sent_fail_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
extern void mmi_sms_bt_read_msg(U16 msg_id, MMI_BOOL change_status, SmsCBFuncPtr callback_func);
MMI_BOOL mmi_sms_bt_check_is_valid_oa_addr(U16 msg_id);
void mmi_sms_bt_get_inbox_list_cb(srv_sms_callback_struct* data);
static void mmi_sms_bt_menu_cui_entry_hdlr(mmi_event_struct* evt);
static void mmi_sms_bt_inbox_viewer_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id);
static mmi_sms_bt_csk_opt_hdlr(void);

#define MMI_SMS_MAX_VIEWER_HEADER_LEN 120

MMI_ID editor_gid = 0;  //  

/**************************************************************
 * Static Variables Defination
 **************************************************************/
static S8 *viewer_header_buff = NULL;

/**************************************************************
* Static Variables Defination
**************************************************************/
static mmi_id sms_bt_save_to_draft_child_gid  = GRP_ID_INVALID;
static mmi_id sms_bt_save_to_draft_parent_gid  = GRP_ID_INVALID;
static S16 sms_bt_process_body_str_id;
static U16 sms_bt_process_rsk_str_id;
static MMI_ID sms_bt_process_gid = GRP_ID_INVALID;
static g_menu_cui_gid=0; 
const S8 *textBuffer = NULL;
srv_sms_msg_data_struct *msg_data =NULL;
srv_sms_msg_data_struct *send_data= NULL;

/*Global Varibales */
/* extern varibale */
extern MMI_ID g_sms_bt_gid;
extern mmi_sms_bt_context_struct g_sms_bt_cntx;
extern mmi_sms_bt_cntx_struct *g_sms_bt_ui_p;
extern srv_sms_btmapc_bt_enum	g_sms_active_dev_index;	   /* Bt index ID */


#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
mmi_sms_hilite_struct hilite_cntx;
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */

MMI_ID mmi_sms_bt_group_entry(MMI_ID parent_gid);
MMI_ID cui_sms_bt_write_launch(mmi_id parent_grp_id);
MMI_ID  g_sms_bt_parent_gid;



MMI_BOOL mmi_sms_bt_check_is_valid_oa_addr(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ucs2_addr;
    S8 ucs2_num[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
    MMI_BOOL is_number_valid = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    srv_sms_btmapc_get_msg_address(msg_id, ucs2_num);
    ucs2_addr = (S8*)ucs2_num;
    is_number_valid = srv_sms_btmapc_check_ucs2_number(ucs2_addr);

    if (((ucs2_addr[0] == '\0') && (ucs2_addr[1] == '\0')) ||
        (is_number_valid == MMI_FALSE))
    {
        return MMI_FALSE;
    }
    
    return MMI_TRUE;
}

MMI_ID cui_sms_bt_write_launch(mmi_id parent_grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_sms_bt_group_entry(parent_grp_id);

    mmi_sms_bt_pre_entry_editor();

    return g_sms_bt_gid;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_pre_entry_editor
 * DESCRIPTION
 *  Pre-Entry SMS/EMS Editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_pre_entry_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_bt_entry_editor();
}

void mmi_sms_bt_entry_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    EMSData *ems_data;

    mmi_id curr_gid = g_sms_bt_gid;
	MMI_BOOL is_forward = MMI_FALSE;
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    wgui_cat28_recipients_label_struct  lable;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(curr_gid, SCR_ID_SMS_BT_EDITOR, NULL, mmi_sms_bt_entry_editor, MMI_FRM_FULL_SCRN))
    {

        
		 mmi_sms_bt_send_case_enum send_case;
		 S8 *msg_content;
		gui_buffer = mmi_frm_scrn_get_gui_buf(curr_gid, SCR_ID_SMS_BT_EDITOR);
                send_case = mmi_sms_bt_get_send_msg_case();       
		if(send_data == NULL)
		send_data = mmi_sms_bt_get_msg_data_for_forward();
			
		if(((send_data != NULL) && (send_case == SMS_BT_SEND_CASE_FORWARD)) || gui_buffer != NULL)
			{
				
			}
			else
			{
		    msg_content = (S8*)OslMalloc(SRV_SMS_BTMAPC_DISPLAY_BUFFER_SIZE);
			memset(msg_content, 0,SRV_SMS_BTMAPC_DISPLAY_BUFFER_SIZE);
			send_data = NULL;
			send_data = (srv_sms_msg_data_struct*)OslMalloc(sizeof(srv_sms_msg_data_struct));
		        memset(send_data, 0, sizeof(srv_sms_msg_data_struct));
			send_data->para_flag = (srv_sms_para_enum)(SRV_SMS_PARA_CONTENT_BUFF | SRV_SMS_PARA_ORI_8BIT_DATA);
			send_data->content_buff_size = SRV_SMS_BTMAPC_DISPLAY_BUFFER_SIZE;
			send_data->content_buff = msg_content;
			
			}

		 wgui_uce_initialize_editor(
            send_data->content_buff,
            (send_data->content_buff_size / ENCODING_LENGTH + 1),
            1,
            1,
            send_data->content_buff_size / ENCODING_LENGTH,
            mmi_sms_editor_get_message_size_callback,
            mmi_sms_editor_text_change_callback,
            mmi_sms_editor_display_type_callback,
            mmi_sms_editor_remaining_char_count,
            mmi_sms_editor_segment_count,
            NULL,
            NULL);
    

   
       mmi_sms_update_editor_info((CHAR*)send_data->content_buff);
       ShowCategory280Screen(
        STR_ID_SMS_BT_MESSAGE_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        WGUI_UCE_MSG_TYPE_SMS,
        IMM_INPUT_TYPE_SENTENCE,
        NULL,
        NULL,
        gui_buffer);
        SetCategory280RightSoftkeyFunction( mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

      SetLeftSoftkeyFunction(mmi_sms_bt_entry_editor_options, KEY_EVENT_UP);
      SetCenterSoftkeyFunction(mmi_sms_bt_entry_editor_options, KEY_EVENT_UP);
       
    
       
        mmi_frm_scrn_set_leave_proc(
            curr_gid,
            SCR_ID_SMS_BT_EDITOR,
            mmi_sms_bt_editor_scrn_leave_proc);
    }
}

static void mmi_sms_save_to_drafts_bg_del_rsp(srv_sms_callback_struct *callback_data)
{
	ASSERT(0);
}

static void mmi_sms_save_to_drafts_background(srv_sms_sim_enum sim)
{
	ASSERT(0);
}

static mmi_ret mmi_sms_bt_editor_scrn_leave_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *ems_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
	      MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_MSG_EDITOR_SCREEN_DEINIT);
	      if(msg_data != NULL)
		   {
			OslMfree(msg_data->content_buff);
			OslMfree(msg_data);
			msg_data->content_buff = NULL;
			msg_data = NULL;
			send_data = NULL;
			 }
				/*case when the editor was directly open without forward case
				  In this case send_data was explicitly allocated, while msg_data will be NULL
				  So free send_data and set it to NULL*/

				if(send_data != NULL) 
					{
						OslMfree(send_data->content_buff);
						OslMfree(send_data);
						send_data->content_buff = NULL;
						send_data = NULL;
				   }
			
		mmi_sms_bt_set_send_msg_case( SMS_SEND_CASE_NONE);
		mmi_sms_bt_reset_recipient_data();
		break;

        default:
            break;
    }

    return MMI_RET_OK; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_group_entry
 * DESCRIPTION
 *  SMS initiate a group id and enter into this group
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_ID mmi_sms_bt_group_entry(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_GROUP_ENTRY, parent_gid);

    if (parent_gid == GRP_ID_INVALID)
    {
        return GRP_ID_INVALID;
    }

    g_sms_bt_parent_gid = parent_gid;

    if (g_sms_bt_gid != GRP_ID_INVALID)
    {

        mmi_frm_group_close(g_sms_bt_gid);
    }

    g_sms_bt_gid = mmi_frm_group_create_ex(
        parent_gid,
        GRP_ID_AUTO_GEN,
        mmi_sms_bt_group_entry_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_GROUP_ENTRY_2, g_sms_bt_gid);

    return g_sms_bt_gid;
}

static void mmi_sms_bt_menu_cui_entry_hdlr(mmi_event_struct* evt)
{
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    U16 curr_msg_id = g_sms_bt_cntx.curr_msg_id;

    if(cui_menu_is_menu_event(menu_evt->evt_id))
    {
        wgui_inputs_options_menu_handler((mmi_event_struct*)menu_evt, g_sms_bt_gid);
    }

    switch (menu_evt->parent_menu_id)
    {
        case MENU_ID_SMS_BT_INBOX_VIEWER_OPT:
            mmi_sms_bt_inbox_viewer_opt_entry_hdlr(menu_evt, curr_msg_id);
            break;
    #if defined(__MMI_BT_BOX__) || defined(__MMI_WEARABLE_DEVICE__)
	case MENU_ID_SMS_BT_OUTBOX_VIEWER_OPT:
	    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_SMS_BT_VIEWER_OPT_FORWARD, MMI_TRUE);		
	    break;
    #endif
    }
}
static void mmi_sms_bt_inbox_viewer_opt_entry_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    MMI_ID cui_menu_gid = menu_evt->sender_id;
    U16 curr_msg_id = msg_id;
    if (mmi_sms_bt_check_is_valid_oa_addr(curr_msg_id) == MMI_TRUE)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_BT_VIEWER_OPT_REPLY, MMI_FALSE);
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_BT_VIEWER_CALL_SENDER, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_BT_VIEWER_OPT_REPLY, MMI_TRUE);
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_BT_VIEWER_CALL_SENDER, MMI_TRUE);
    }
#if defined(__MMI_BT_BOX__) || defined(__MMI_WEARABLE_DEVICE__)
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_BT_VIEWER_OPT_FORWARD, MMI_TRUE);
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_BT_VIEWER_OPT_REPLY, MMI_TRUE);
#endif /*__MMI_BT_BOX__*/

}
static mmi_ret mmi_sms_bt_group_entry_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
	switch (evt->evt_id)
	{
		case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_sms_bt_menu_cui_entry_hdlr(evt);
            break;
		case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_sms_bt_menu_cui_select_hdlr(evt);
            break;
		case EVT_ID_CUI_MENU_CLOSE_REQUEST: 
			cui_menu_close(menu_evt->sender_id);
            break;
		case EVT_ID_GROUP_INACTIVE:
            if (!mmi_frm_scrn_get_count(g_sms_bt_gid))
            {
                mmi_frm_group_close(g_sms_bt_gid);
            }
            break;
		case EVT_ID_GROUP_DEINIT:
				   g_sms_bt_gid = GRP_ID_INVALID;
				   g_sms_bt_parent_gid = GRP_ID_ROOT;
				   if(msg_data != NULL)
				   {
					OslMfree(msg_data->content_buff);
					OslMfree(msg_data);
					msg_data->content_buff = NULL;
					msg_data = NULL;
					send_data = NULL;
				   }
				   break;
		default:
			break;
	
	}
  

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_get_message_size_callback
 * DESCRIPTION
 *  Return msg size
 * PARAMETERS
 *  current_text_info       [?]         
 *  uce_msg_type            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_sms_editor_get_message_size_callback(wgui_uce_text_info_struct *current_text_info, wgui_uce_msg_type_enum uce_msg_type)
{
     return current_text_info->char_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_text_change_callback
 * DESCRIPTION
 *  Check if the text is allowed to be inserted
 * PARAMETERS
 *  new_text_info       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
wgui_uce_text_change_result_enum mmi_sms_editor_text_change_callback(wgui_uce_text_info_struct *new_text_info)
{
    
    if (new_text_info->UCS2_count > 0)
    {
        if (new_text_info->char_count > (SRV_SMS_BTMAPC_DISPLAY_BUFFER_SIZE / 2))
        {
            return WGUI_UCE_TEXT_CHANGE_NOT_ALLOWED;
        }
    }
    else
    {
        if (new_text_info->char_count + new_text_info->extension_char_count >
            (SRV_SMS_BTMAPC_DISPLAY_BUFFER_SIZE / 2))
        {
            return WGUI_UCE_TEXT_CHANGE_NOT_ALLOWED;
        }
    }
    return WGUI_UCE_TEXT_CHANGE_ALLOWED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_display_type_callback
 * DESCRIPTION
 *  Check which display type should be used for mms , display  character or size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
wgui_uce_display_enum mmi_sms_editor_display_type_callback(void)
{
    return WGUI_UCE_DISPLAY_SIZE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_insert_text_to_editor
 * DESCRIPTION
 *  Insert Text to the SMS Editor
 * PARAMETERS
 *  text_buff       [IN] the Input Text Buffer
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_sms_insert_text_to_editor(S8* text_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_remaining_char_count
 * DESCRIPTION
 *  Initialize editor
 * PARAMETERS
 *  current_text_info       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_sms_editor_remaining_char_count(wgui_uce_text_info_struct *current_text_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call to do SMS srv internal operations. */
    /*return (U32) srv_sms_get_last_segment_remaining(
                    current_text_info->UCS2_count,
                    current_text_info->char_count,
                    current_text_info->extension_char_count);*/
    return (SRV_SMS_BTMAPC_DISPLAY_BUFFER_SIZE - current_text_info->char_count);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_segment_count
 * DESCRIPTION
 *  Initialize editor
 * PARAMETERS
 *  current_text_info       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_sms_editor_segment_count(wgui_uce_text_info_struct *current_text_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 local_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*local_value = srv_sms_get_sms_segment_number(
                    current_text_info->UCS2_count,
                    current_text_info->char_count,
                    current_text_info->extension_char_count);*/
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_opt_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_bt_editor_opt_select_hdlr(mmi_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *cui_menu_evt = (cui_menu_event_struct*)menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cui_menu_evt->highlighted_menu_id)
    {
		case MENU_ID_SMS_BT_ED_OPT_SEND_TO:
		
				mmi_sms_ed_send_to();
				///TODO:
			   // ASSERT(0);
			
            break;
	   case MENU_ID_SMS_BT_ED_OPT_SAVE_TO_DRAFTS:
       {
			srv_sms_sim_enum sim_id = SRV_SMS_SIM_1;
			/***************************************************************
			***** Currently saving in SIM 1 always *************************
			***** As there is no sim option screen in specs ****************
			***************************************************************/

		/*	mmi_sim_enum total_sim = MMI_SIM_NONE;
			mmi_sim_enum sim1_valid = srv_nw_usab_is_usable(MMI_SIM1)? MMI_SIM1:MMI_SIM_NONE;
			 #if (MMI_MAX_SIM_NUM >=2)
			mmi_sim_enum sim2_valid = srv_nw_usab_is_usable(MMI_SIM2)?MMI_SIM2:MMI_SIM_NONE;
			#endif
			#if (MMI_MAX_SIM_NUM  >=3)
			mmi_sim_enum sim3_valid = srv_nw_usab_is_usable(MMI_SIM3)?MMI_SIM3:MMI_SIM_NONE;
			#endif
			
			 #if (MMI_MAX_SIM_NUM  >=4)
			mmi_sim_enum sim4_valid = srv_nw_usab_is_usable(MMI_SIM4)?MMI_SIM4:MMI_SIM_NONE;
			#endif
			total_sim = sim1_valid
										 #if (MMI_MAX_SIM_NUM >=2)
										 |sim2_valid
										 #endif
										 #if (MMI_MAX_SIM_NUM  >=3)
										 |sim3_valid
										 #endif
										 #if (MMI_MAX_SIM_NUM  >=4)
										 |sim4_valid
										 #endif
										 ;
			
			switch(total_sim)
			{
				case MMI_SIM_NONE:
				case MMI_SIM1:
				 sim_id = SRV_SMS_BT_SIM_1;
				 break;
				 
				   #if (MMI_MAX_SIM_NUM >=2)
				   case MMI_SIM2:
				  sim_id = SRV_SMS_BT_SIM_2;
				 break;
				 
				   #if (MMI_MAX_SIM_NUM  >=3)
				   case MMI_SIM3:
				  sim_id = SRV_SMS_BT_SIM_3;
				 break;
				 
				  #if (MMI_MAX_SIM_NUM  >=4)
				   case MMI_SIM4:
				  sim_id = SRV_SMS_BT_SIM_4;
                break;
				
				 #endif
 			    #endif
				 #endif
				
				 default:
				 return MMI_RET_OK;
                }
				*/

            mmi_sms_bt_ed_opt_save_to_drafts();
          }
            break;


            break;
				
		default:
				 break;
      }
          
          
     return MMI_RET_OK;
           
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_save_msg_cb
 * DESCRIPTION
 *  The callback message for draft saving
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_save_msg_cb(srv_sms_callback_struct* cb_data)
{
	if(cb_data->result == MMI_TRUE)
	{
		mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS);
	}
	else
	{
		mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE);
	}
   /* mmi_frm_group_close(g_sms_bt_gid);
	g_sms_bt_gid = GRP_ID_INVALID;*/
	g_sms_bt_cntx.curr_msg_id = SRV_SMS_INVALID_MSG_ID;
        mmi_frm_group_close(g_sms_bt_gid);
	g_sms_bt_gid = GRP_ID_INVALID;
	mmi_frm_scrn_close(((*g_sms_um_ui_p).cc_cntx).grp_table[0].grp_id, SCR_ID_SMS_UM_BT_FOLDER);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_highlight_mark_as_unread
 * DESCRIPTION
 *  The "Send as Email" menu LSK Handle Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_ed_opt_save_to_drafts()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	SMS_HANDLE handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  /*  sms_bt_save_to_draft_parent_gid = mmi_frm_group_create_ex(
                                        GRP_ID_ROOT,
                                        GRP_ID_AUTO_GEN,
                                        mmi_sms_bt_save_to_drafts_proc,
                                        NULL,
                                        MMI_FRM_NODE_SMART_CLOSE_FLAG);*/

	handle = srv_sms_btmapc_get_save_handle();
	srv_sms_btmapc_set_save_index(handle, g_sms_active_dev_index);
	srv_sms_btmapc_set_status(handle, SRV_SMS_STATUS_DRAFT);
	srv_sms_btmapc_set_content(handle, send_data->content_buff, send_data->content_buff_size);
	mmi_sms_bt_set_and_entry_processing_sg(g_sms_bt_gid, STR_GLOBAL_SAVING, 0);
	srv_sms_btmapc_save_msg(
        handle,
        mmi_sms_bt_save_msg_cb,
        NULL);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_menu_cui_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_menu_cui_select_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    U16 curr_msg_id = g_sms_bt_cntx.curr_msg_id;
    mmi_menu_id highlighted_menu_id = menu_evt->highlighted_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
		switch (menu_evt->parent_menu_id)
			{
		    
				case MENU_ID_SMS_BT_EDITOR_OPTIONS:
					mmi_sms_bt_editor_opt_select_hdlr(evt);
					break;
				case MENU_ID_SMS_BT_INBOX_VIEWER_OPT:
					mmi_sms_bt_default_viewer_opt_select_hdlr(menu_evt, curr_msg_id); /* select handler for viewer options */
					break;
			    case MENU_ID_SMS_BT_DRAFT_VIEWER_OPT:
					mmi_sms_bt_draft_viewer_opt_select_hdlr(menu_evt, curr_msg_id);
					break;
				case MENU_ID_SMS_BT_OUTBOX_VIEWER_OPT:
					mmi_sms_bt_default_outbox_opt_select_hdlr(menu_evt, curr_msg_id); /* select handler for viewer options */
					break;
				case MENU_ID_SMS_BT_SENT_FAIL_VIEWER_OPT:
					mmi_sms_bt_default_sent_fail_opt_select_hdlr(menu_evt, curr_msg_id); /* select handler for viewer options */
					break;
				default:
					break;
			}
}
        

static mmi_sms_bt_send_hdlr()
{
    S8 *ucs2_addr;
    S8 ucs2_num[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
    MMI_BOOL is_number_valid = MMI_FALSE;
    mmi_ucm_make_call_para_struct param; 
    srv_sms_status_enum curr_msg_status = srv_sms_btmapc_get_msg_status(g_sms_bt_cntx.curr_msg_id);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    
    if (curr_msg_status & SRV_SMS_STATUS_READ)
    {
        srv_sms_btmapc_get_msg_address(g_sms_bt_cntx.curr_msg_id, ucs2_num);
        ucs2_addr = (S8*)ucs2_num;
        is_number_valid = srv_sms_btmapc_check_ucs2_number(ucs2_addr);

        if (((ucs2_addr[0] == '\0') && (ucs2_addr[1] == '\0')) ||
            (is_number_valid == MMI_FALSE))
        {
            return MMI_FALSE;
        }    

        mmi_ucm_init_call_para(&param);
        param.dial_type = SRV_UCM_CALL_TYPE_ALL;
        param.ucs2_num_uri = (U16 *)ucs2_num;
        mmi_ucm_call_launch(0, &param);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_viewer
 * DESCRIPTION
 *  Entry the SMS Viewer Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_entry_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    U8 *header_buff;
#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
    MMI_BOOL isHilite = srv_sms_is_highlight_view_setting();
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */
    mmi_id curr_sms_gid = g_sms_bt_gid;
    MMI_BOOL enable_action = MMI_TRUE;
    U16 lsk_str = STR_GLOBAL_OPTIONS;
    MYTIME time;
    WCHAR time_buffer[40] = {0};
    WCHAR d[20] = {0};
    WCHAR t[20] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_MSG_VIEWER_ACTIVE_GROUP, mmi_frm_group_get_active_id);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_MSG_VIEWER_SMS_GROUP, g_sms_bt_gid);    
    if (mmi_frm_scrn_enter(
            curr_sms_gid,
            SCR_ID_SMS_BT_VIEWER,
            NULL,
            mmi_sms_bt_entry_viewer,
            MMI_FRM_FULL_SCRN))
    {
        srv_sms_box_enum curr_box_type;
        gui_buffer = mmi_frm_scrn_get_gui_buf(curr_sms_gid, SCR_ID_SMS_BT_VIEWER);

        srv_sms_btmapc_get_msg_list_index(&curr_box_type, g_sms_bt_cntx.curr_msg_id);
   

        srv_sms_btmapc_get_msg_timestamp(g_sms_bt_cntx.curr_msg_id, &time);  
        date_string((MYTIME*) & time, d, DT_IDLE_SCREEN);
        mmi_wcscpy(time_buffer, (const WCHAR*) d);  
        mmi_ucs2cat((CHAR*) time_buffer, (const CHAR*) (L" "));
        time_string((MYTIME*) & time, t, DT_IDLE_SCREEN);
        mmi_ucs2cat((CHAR*) time_buffer, (const CHAR*) t);
        mmi_ucs2cat((CHAR*) time_buffer, (const CHAR*) (L"\n\n"));
        
        set_cat145_show_number_finish();

        ShowBTNotiCategory145Screen(
            (U8*)GetString(STR_SCR6024_CAPTION),
            IMG_SMS_ENTRY_SCRN_CAPTION,
            lsk_str,
            IMG_SMS_COMMON_NOIMAGE,
            STR_GLOBAL_BACK,
            IMG_SMS_COMMON_NOIMAGE,
            0,
            (U8*)time_buffer,
            (U8*)msg_data->content_buff,
            0,
            gui_buffer); 

        if (enable_action)
        {
            SetLeftSoftkeyFunction(mmi_sms_bt_pre_entry_viewer_opt, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_sms_bt_csk_opt_hdlr, KEY_EVENT_UP);
            SetKeyHandler(mmi_sms_bt_send_hdlr, KEY_SEND, KEY_EVENT_UP);
        }

        SetRightSoftkeyFunction(mmi_sms_bt_go_back_from_viewer, KEY_EVENT_UP);
        
        mmi_frm_scrn_set_leave_proc(
            curr_sms_gid,
            SCR_ID_SMS_BT_VIEWER,
            mmi_sms_bt_viewer_scrn_leave_proc);
    }
}

static mmi_sms_bt_csk_opt_hdlr()
{
    switch (g_sms_bt_cntx.curr_box_type)
    {
        case SRV_SMS_BOX_INBOX:
        {
            if (mmi_sms_bt_check_is_valid_oa_addr(g_sms_bt_cntx.curr_msg_id) == MMI_TRUE)
                mmi_sms_bt_viewer_opt_reply();
            else
                mmi_sms_bt_viewer_opt_forward();
            break;
        }
        case SRV_SMS_BOX_OUTBOX:
        {
            mmi_sms_bt_viewer_opt_forward();
            break;
        }
        case SRV_SMS_BOX_DRAFTS:
        {
            mmi_sms_bt_viewer_opt_forward();
            break;
        }
        case SRV_SMS_BOX_UNSENT:
        {
            mmi_sms_bt_viewer_opt_delete();
            break;
        }
        default:
        {
            return;
        }
    }
        
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_pre_entry_viewer_opt
 * DESCRIPTION
 *  Entry SMS Viwer Options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_pre_entry_viewer_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_MENU_ID menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = mmi_sms_bt_get_viewer_opt_menu_id(g_sms_bt_cntx.curr_msg_id);

    mmi_sms_bt_entry_menu_cui_options_generic(
        g_sms_bt_gid,
        menu_id,
        0);

}



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_go_back_from_viewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_go_back_from_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    
      mmi_frm_scrn_close_active_id();
   

}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_scrn_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sms_bt_viewer_scrn_leave_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
		default:
            if (!mmi_frm_scrn_get_count(g_sms_bt_gid))
            {
                mmi_frm_group_close(g_sms_bt_gid);/*FM_QA : call it here? Answer: In create proc*/
                g_sms_bt_gid = GRP_ID_INVALID;
            }
            break;
    }

    return MMI_RET_OK; 
}
void mmi_sms_bt_get_msg_cb(srv_sms_callback_struct *data)
{
        srv_bt_mapc_bt_enum *bt_index;
	 MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_MSG_GET_MSG_CB, data->result);
	if(MMI_TRUE == data->result)
	{

        S8 *msg_content = (S8 *)OslMalloc(SRV_SMS_BTMAPC_DISPLAY_BUFFER_SIZE);
        srv_sms_msg_data_struct *msg_dt = (srv_sms_msg_data_struct*)OslMalloc(sizeof(srv_sms_msg_data_struct));
        bt_index = data->user_data;
        msg_dt->para_flag = (srv_sms_para_enum)(SRV_SMS_PARA_CONTENT_BUFF | SRV_SMS_PARA_ORI_8BIT_DATA);
        msg_dt->content_buff_size = SRV_SMS_BTMAPC_DISPLAY_BUFFER_SIZE;
        msg_dt->content_buff = msg_content;
		MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_MSG_SEND_READ_MSG_REQ, data->result);
        srv_sms_btmapc_read_msg(*bt_index, g_sms_bt_cntx.curr_msg_id, MMI_TRUE, msg_dt,mmi_sms_bt_get_msg_callback, NULL);
        
	}
	else if(MMI_FALSE == data->result)
	{
		mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE);
		mmi_frm_group_close(g_sms_bt_gid);
                g_sms_bt_gid = GRP_ID_INVALID;
		return;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_box_list_opt_pre_view
 * DESCRIPTION
 *  Pre entry list option view msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_box_list_opt_pre_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_prompt_trace(MOD_MMI, "Entry into mmi_sms_bt_box_list_opt_pre_view");
mmi_sms_bt_set_and_entry_processing_sg(g_sms_bt_gid, STR_GLOBAL_LOADING, 0);
	srv_sms_btmapc_get_msg(
                g_sms_active_dev_index,
                g_sms_bt_cntx.curr_msg_id,
                mmi_sms_bt_get_msg_cb,
                &g_sms_active_dev_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_read_msg_text_only
 * DESCRIPTION
 *  Read Message
 * PARAMETERS
 *  msg_index           [IN]    Msg Index
 *  callback_func   [IN]    Callback Function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_read_msg(U16 msg_id, MMI_BOOL change_status, SmsCBFuncPtr callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    	textBuffer = srv_sms_btmapc_get_msg_content(msg_id);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_sms_bt_entry_viewer();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_view_curr_msg_callback
 * DESCRIPTION
 *  Read current msg callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_view_curr_msg_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
        mmi_sms_bt_msg_status_enum msg_status = *(mmi_sms_bt_msg_status_enum*)data;

        g_sms_bt_cntx.curr_msg_status = msg_status;

            if ((g_sms_bt_gid == mmi_frm_group_get_active_id())
                && (SCR_ID_SMS_BT_PROCESSING == mmi_frm_scrn_get_active_id())
                )
            {
                mmi_sms_bt_entry_viewer();
                mmi_frm_scrn_close(g_sms_bt_gid, SCR_ID_SMS_BT_PROCESSING);
            }
            else if (mmi_frm_scrn_is_present(g_sms_bt_gid, SCR_ID_SMS_BT_PROCESSING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                mmi_frm_node_struct new_node_info;
                new_node_info.id = SCR_ID_SMS_BT_VIEWER;
                new_node_info.entry_proc = (mmi_proc_func)mmi_sms_bt_entry_viewer;
                mmi_frm_scrn_replace(g_sms_bt_gid, SCR_ID_SMS_BT_PROCESSING, &new_node_info);
            }
      }
    
    else
    {
        mmi_frm_scrn_close(g_sms_bt_gid, SCR_ID_SMS_BT_PROCESSING);
    }
}


void mmi_sms_bt_get_msg_callback (srv_sms_callback_struct* callback_data)
{
	//srv_sms_msg_data_struct *msg_data = NULL;
    srv_sms_read_msg_cb_struct *cb = (srv_sms_read_msg_cb_struct *)callback_data->action_data;

   MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_MSG_READ_MSG_CB, callback_data->result);
	 if(callback_data->result)
    {
        msg_data = cb->msg_data;
		kal_prompt_trace(MOD_MMI, "Call mmi_sms_bt_get_msg_callback with msg_data = %s", msg_data->content_buff);
		kal_prompt_trace(MOD_MMI, "Here g_sms_bt_gid = %d", g_sms_bt_gid);
		MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_MSG_SEND_CALL_VIEWER, g_sms_bt_gid);
		//mmi_sms_bt_entry_viewer();
		
		if ((g_sms_bt_gid == mmi_frm_group_get_active_id())
                && (SCR_ID_SMS_BT_PROCESSING == mmi_frm_scrn_get_active_id())
                )
            {
		mmi_sms_bt_entry_viewer();
                mmi_frm_scrn_close(g_sms_bt_gid, SCR_ID_SMS_BT_PROCESSING);
            }
            else if (mmi_frm_scrn_is_present(g_sms_bt_gid, SCR_ID_SMS_BT_PROCESSING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                mmi_frm_node_struct new_node_info;
                new_node_info.id = SCR_ID_SMS_BT_VIEWER;
                new_node_info.entry_proc = (mmi_proc_func)mmi_sms_bt_entry_viewer;
                mmi_frm_scrn_replace(g_sms_bt_gid, SCR_ID_SMS_BT_PROCESSING, &new_node_info);
            }
    }
	 else
	 {
		 if(cb->msg_data != NULL)
		 {
			 OslMfree(cb->msg_data->content_buff);
			 cb->msg_data->content_buff = NULL;
			 OslMfree(cb->msg_data);
			 cb->msg_data = NULL;
		 }
		 mmi_display_popup(GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE);
		 mmi_frm_group_close(g_sms_bt_gid);
		 g_sms_bt_gid=GRP_ID_INVALID;
		 return;
	 }
}




/*****************************************************************************
 * FUNCTION
 *  mmi_sms_read_msg_rsp
 * DESCRIPTION
 *  Entry send screen
 * PARAMETERS
 *  data        [IN]    Dummy
 *  mod         [IN]    Module Type
 *  result      [IN]    SMS Framework Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_read_msg_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_read_msg_cb_struct *read_msg_cb_data;
    srv_sms_msg_data_struct *msg_data;
    SmsCBFuncPtr callback_func;
    mmi_sms_result_enum action_result;
    mmi_sms_bt_msg_status_enum msg_status = SMS_BT_STATUS_UNSUPPORT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_msg_cb_data = (srv_sms_read_msg_cb_struct*)callback_data->action_data;
    callback_func = (SmsCBFuncPtr)callback_data->user_data;

    msg_data = read_msg_cb_data->msg_data;

	if (callback_data->result == MMI_FALSE)
	{
   
        {
            mmi_popup_display_ext(
                STR_GLOBAL_UNFINISHED,
                MMI_EVENT_FAILURE,
                NULL);
        }

        action_result = SMS_RESULT_ERROR;
	}
    else
    {
        if (msg_data->mti == SRV_SMS_MTI_STATUS_REPORT)
        {
            if (msg_data->tp_st == ST_COMP_MSG_RECV_BY_SME)
            {
                msg_status = SMS_BT_STATUS_DELIVERY_REPORT;
            }
            else
            {
                msg_status = SMS_BT_STATUS_PENDING_REPORT;
            }
        }
        else
        {
            srv_sms_status_enum srv_status = msg_data->status;

            if (srv_status & SRV_SMS_STATUS_UNSUPPORTED)
            {
                msg_status = SMS_BT_STATUS_UNSUPPORT;
            }
            else
            {
                switch (srv_status)
                {
                    case SRV_SMS_STATUS_UNREAD:
                        msg_status = SMS_BT_STATUS_UNREAD;
                        break;

                    case SRV_SMS_STATUS_READ:
                        msg_status = SMS_BT_STATUS_INBOX;
                        break;

                    case SRV_SMS_STATUS_SENT:
                        msg_status = SMS_BT_STATUS_SENT;
                        break;

                    case SRV_SMS_STATUS_UNSENT:
                        msg_status = SMS_BT_STATUS_UNSENT;
                        break;

                    case SRV_SMS_STATUS_DRAFT:
                        msg_status = SMS_BT_STATUS_DRAFTS;
                        break;

                    default:
                        MMI_ASSERT(0);
                        break;
                }

            }
        }

        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
    #if (MMI_MAX_SIM_NUM == 2)
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);
    #endif

        action_result = SMS_RESULT_OK;
    }

 //   OslMfree(msg_data);

    if (callback_func != NULL)
    {
        callback_func(action_result, &msg_status);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_viewer_opt_menu_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_MENU_ID mmi_sms_bt_get_viewer_opt_menu_id(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id menu_id;
    srv_sms_box_enum curr_box_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_bt_cntx.curr_msg_id = (U16)msg_id;
    srv_sms_btmapc_get_msg_list_index(&curr_box_type, g_sms_bt_cntx.curr_msg_id);

    switch (curr_box_type)
    {
        case SRV_SMS_BOX_INBOX:
        {
            menu_id = MENU_ID_SMS_BT_INBOX_VIEWER_OPT;
            break;
        }

	case SRV_SMS_BOX_DRAFTS:
        {
            menu_id = MENU_ID_SMS_BT_DRAFT_VIEWER_OPT;
            break;
        }
        
	case SRV_SMS_BOX_OUTBOX:
        {
            menu_id = MENU_ID_SMS_BT_OUTBOX_VIEWER_OPT;
            break;
        }
        
	case SRV_SMS_BOX_UNSENT:
		{
            menu_id = MENU_ID_SMS_BT_SENT_FAIL_VIEWER_OPT;
            break;
        }
        
        default:
            menu_id = MENU_ID_SMS_DEFAULT_VIEWER_OPT;
            break;
    }

    return menu_id;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_menu_cui_options_generic
 * DESCRIPTION
 *  Go back two screen history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_entry_menu_cui_options_generic(MMI_ID parent_gid, MMI_MENU_ID menu_id, U16 title_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
                        parent_gid,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_OPTION,
                        menu_id,
                        MMI_FALSE,
                        NULL);
    g_menu_cui_gid = menu_cui_gid;
    if (title_id != 0)
    {
        cui_menu_set_default_title_string_by_id(menu_cui_gid, title_id);
    }
#ifndef __MMI_SMS_SLIM__
    cui_menu_set_default_title_image_by_id(menu_cui_gid, IMG_SMS_ENTRY_SCRN_CAPTION);
#endif

    cui_menu_run(menu_cui_gid);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_default_viewer_opt_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_default_sent_fail_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *cui_menu_evt = menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_bt_cntx.curr_msg_id = msg_id;

    switch (cui_menu_evt->highlighted_menu_id)
    {
        case MENU_ID_SMS_BT_VIEWER_OPT_RESEND:
            mmi_sms_bt_viewer_opt_forward();
            break;

        case MENU_ID_SMS_BT_VIEWER_OPT_DELETE:
            mmi_sms_bt_viewer_opt_delete();
            break;
        case MENU_ID_SMS_BT_VIEWER_OPT_DETAIL:
            mmi_sms_bt_viewer_pre_entry_details();
            break;
        default:
            ASSERT(0);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_default_viewer_opt_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_default_outbox_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *cui_menu_evt = menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_bt_cntx.curr_msg_id = msg_id;

    switch (cui_menu_evt->highlighted_menu_id)
    {
        case MENU_ID_SMS_BT_VIEWER_OPT_FORWARD:
            mmi_sms_bt_viewer_opt_forward();
            break;

        case MENU_ID_SMS_BT_VIEWER_OPT_DELETE:
            mmi_sms_bt_viewer_opt_delete();
            break;
        case MENU_ID_SMS_BT_VIEWER_OPT_DETAIL:
            mmi_sms_bt_viewer_pre_entry_details();
            break;
        default:
            ASSERT(0);
    }
}


void mmi_sms_bt_get_msg_date_time(U16 msg_id, S8 *date_str, S8 *time_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_time datetime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_get_msg_timestamp(msg_id, (MYTIME*)&datetime);

    if (date_str != NULL)
    {
        date_string(&datetime, (UI_string_type)date_str, DT_IDLE_SCREEN);
    }

    if (time_str != NULL)
    {
        time_string(&datetime, (UI_string_type)time_str, DT_IDLE_SCREEN);
    }
}


static WCHAR* mmi_sms_bt_get_details_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum sms_status;
    U16 msg_id = g_sms_bt_cntx.curr_msg_id;
    U16 addr_caption_str_id = STR_SMS_MESSAGE_HEADER_TO;
    U16 date_caption_str_id = STR_ID_SMS_BT_CREATION_DATE;
    U16 storage_type_str_id = STR_GLOBAL_PHONE;
    WCHAR address[SRV_SMS_MAX_ADDR_LEN + 1];
    WCHAR ts_date[MAX_TIMESTAMP_SIZE + 1];
    WCHAR ts_time[MAX_TIMESTAMP_SIZE + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_status = srv_sms_btmapc_get_msg_status(msg_id);

    if (sms_bt_detail_buff != NULL)
    {
        OslMfree(sms_bt_detail_buff);
        sms_bt_detail_buff = NULL;
    }
    sms_bt_detail_buff = OslMalloc((MMI_SMS_BT_MAX_DETAILS_SCREEN_BUFFER + 1) * ENCODING_LENGTH);

    if ((sms_status & SRV_SMS_STATUS_UNREAD) || (sms_status & SRV_SMS_STATUS_READ))
    {
        addr_caption_str_id = STR_ID_SMS_BT_FROM;
        date_caption_str_id = STR_ID_SMS_BT_CREATION_DATE;
    }

    /* address number, not support email */
    srv_sms_btmapc_get_msg_address(msg_id, (S8*)address);
    if (address[0] == '\0')
    {
        mmi_ucs2cpy((S8*)address, GetString(STR_GLOBAL_EMPTY_LIST));
    }

    /* Date time */
    mmi_sms_bt_get_msg_date_time(msg_id, (S8*)ts_date, (S8*)ts_time);


    kal_wsprintf(sms_bt_detail_buff, 
                "%w%w%w%w%w%w%w%w%w%w%w%w%w%w%w%w%w", 
                GetString(addr_caption_str_id),
                (S8*) L"\n----\n", 
                (S8*) address,
                (S8*) L"\n\n",
                GetString(STR_ID_SMS_BT_TYPE),
                (S8*) L"\n----\n",
                GetString(STR_GLOBAL_TEXT_MESSAGE),
                (S8*) L"\n\n",
                GetString(date_caption_str_id),
                (S8*)L"\n----\n",
                (S8*)ts_date,
                (S8*)L"\n",
                (S8*)ts_time,
                (S8*)L"\n\n",
                GetString(STR_ID_SMS_BT_STORAGE),
                (S8*)L"\n----\n",
                GetString(storage_type_str_id));

    MMI_ASSERT(mmi_wcslen(sms_bt_detail_buff) <= MMI_SMS_BT_MAX_DETAILS_SCREEN_BUFFER);

    return sms_bt_detail_buff;
}


static void mmi_sms_bt_box_list_opt_entry_details()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    U8* detail_buffer = (U8*)mmi_sms_bt_get_details_info();
    U8 *gui_buffer = mmi_frm_scrn_get_gui_buf(g_sms_bt_gid, SCR_ID_SMS_BT_DETAIL);

    ShowCategory74Screen(
        STR_GLOBAL_DETAILS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        detail_buffer,
        (MMI_SMS_BT_MAX_DETAILS_SCREEN_BUFFER + 1) * ENCODING_LENGTH,
        gui_buffer);
}


mmi_ret mmi_sms_bt_detail_scrn_proc (mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_sms_bt_box_list_opt_entry_details();
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
            if (sms_bt_detail_buff != NULL)
            {
                OslMfree(sms_bt_detail_buff);
                sms_bt_detail_buff = NULL;
            }
            break;
        }
    }
    return MMI_RET_OK;
}

static void mmi_sms_bt_viewer_pre_entry_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_create(
        g_sms_bt_gid, 
        SCR_ID_SMS_BT_DETAIL, 
        mmi_sms_bt_detail_scrn_proc,
        NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_default_viewer_opt_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_default_viewer_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *cui_menu_evt = menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_bt_cntx.curr_msg_id = msg_id;

    switch (cui_menu_evt->highlighted_menu_id)
    {
        case MENU_ID_SMS_BT_VIEWER_OPT_REPLY:
        {
            mmi_sms_write_msg_para_struct sendData;            
            CHAR ascii_number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
            
            memset(&sendData, 0, sizeof(mmi_sms_write_msg_para_struct));
            memset(ascii_number, 0, sizeof(ascii_number));

            mmi_ucs2_to_asc(ascii_number, msg_data->number);

            sendData.flag = MMI_SMS_ENTRY_WRITE_REPLY;
            sendData.ascii_addr = (U8*) ascii_number;
            mmi_sms_write_msg_lanch(g_sms_bt_gid, &sendData);
            
            break;
        }

        case MENU_ID_SMS_BT_VIEWER_OPT_FORWARD:
        {
            //mmi_sms_bt_viewer_opt_forward();
            mmi_sms_write_msg_para_struct sendData;            

            memset(&sendData, 0, sizeof(mmi_sms_write_msg_para_struct));

            sendData.string = msg_data->content_buff;
            sendData.stringlength = wcslen((WCHAR *)msg_data->content_buff);

            mmi_sms_write_msg_lanch(g_sms_bt_gid, &sendData);
            break;
        }

        case MENU_ID_SMS_BT_VIEWER_OPT_DELETE:
            mmi_sms_bt_viewer_opt_delete();
            break;

		case MENU_ID_SMS_BT_VIEWER_CALL_SENDER:
			mmi_sms_bt_viewer_call_sender();
			break;

        case MENU_ID_SMS_BT_VIEWER_OPT_DETAIL:
            mmi_sms_bt_viewer_pre_entry_details();
            break;

        default:
            ASSERT(0);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_default_viewer_opt_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_draft_viewer_opt_select_hdlr(cui_menu_event_struct *menu_evt, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *cui_menu_evt = menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_bt_cntx.curr_msg_id = msg_id;

    switch (cui_menu_evt->highlighted_menu_id)
    {
        case MENU_ID_SMS_BT_VIEWER_OPT_EDIT:
        {
            mmi_sms_write_msg_para_struct sendData;            

            memset(&sendData, 0, sizeof(mmi_sms_write_msg_para_struct));

            sendData.string = msg_data->content_buff;
            sendData.stringlength = wcslen((WCHAR *)msg_data->content_buff);
            mmi_sms_set_send_msg_case(SMS_SEND_CASE_EDIT_DRAFT);
            mmi_sms_write_msg_lanch(g_sms_bt_gid, &sendData);
            break;
        }

        case MENU_ID_SMS_BT_VIEWER_OPT_DELETE:
            mmi_sms_bt_viewer_opt_delete();
            break;

        default:
            ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_reply
 * DESCRIPTION
 *  Highlight replay handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_viewer_opt_reply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //srv_sms_box_enum curr_box_type;
    //mmi_sms_send_case_enum send_case;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //srv_sms_get_msg_list_index(&curr_box_type, g_sms_bt_cntx.curr_msg_id);
    
    //send_case = SMS_BT_SEND_CASE_REPLY;
    

    //mmi_sms_bt_viewer_opt_operation(send_case);
    mmi_sms_write_msg_para_struct sendData;            
    CHAR ascii_number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    
    memset(&sendData, 0, sizeof(mmi_sms_write_msg_para_struct));
    memset(ascii_number, 0, sizeof(ascii_number));

    mmi_ucs2_to_asc(ascii_number, msg_data->number);

    sendData.flag = MMI_SMS_ENTRY_WRITE_REPLY;
    sendData.ascii_addr = (U8*) ascii_number;
    mmi_sms_write_msg_lanch(g_sms_bt_gid, &sendData);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_reply
 * DESCRIPTION
 *  Highlight replay handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_viewer_opt_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //srv_sms_box_enum curr_box_type;
    //mmi_sms_send_case_enum send_case;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //srv_sms_get_msg_list_index(&curr_box_type, g_sms_bt_cntx.curr_msg_id);
    
    //send_case = SMS_BT_SEND_CASE_FORWARD;
    

    //mmi_sms_bt_viewer_opt_operation(send_case);
    mmi_sms_write_msg_para_struct sendData;            

    memset(&sendData, 0, sizeof(mmi_sms_write_msg_para_struct));

    sendData.string = msg_data->content_buff;
    sendData.stringlength = wcslen((WCHAR *)msg_data->content_buff);

    mmi_sms_write_msg_lanch(g_sms_bt_gid, &sendData);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_delete_callback
 * DESCRIPTION
 *  Delete callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_viewer_opt_delete_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_MSG_DELETE_MSG_CB, result);
    if (result == SMS_RESULT_OK)
    {
        mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS);

    }
    else
    {
        mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE);
    }

        /*g_sms_bt_cntx.curr_msg_id = SRV_SMS_INVALID_MSG_ID;
            mi_frm_group_close(g_sms_bt_gid);
            sms_bt_gid = GRP_ID_INVALID;
            mi_frm_scrn_close(((*g_sms_um_ui_p).cc_cntx).grp_table[0].grp_id, SCR_ID_SMS_UM_BT_FOLDER);*/
 }

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_delete_msg_rsp
 * DESCRIPTION
 *  Delete Msg Response
 * PARAMETERS
 *  data        [IN]    Dummy
 *  mod         [IN]    Module Type
 *  result      [IN]    SMS Framework Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_delete_msg_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_result_enum action_result = SMS_RESULT_OK;
    SmsCBFuncPtr callback_func;
    srv_sms_btmapc_delete_msg_struct *delete_msg_cntx;
    srv_sms_btmapc_bt_enum  bt_index;       /* Bt index ID */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_msg_cntx = (srv_sms_btmapc_delete_msg_struct*)callback_data->user_data;
    callback_func = delete_msg_cntx->callback_func;
    bt_index = delete_msg_cntx->bt_index;
    if (callback_data->result == MMI_FALSE)
    {
        mmi_popup_display_ext(
            STR_GLOBAL_UNFINISHED,
            MMI_EVENT_FAILURE,
            NULL);

        action_result = SMS_RESULT_ERROR;
    }
    else if(callback_data->result == MMI_TRUE)
    {
        g_sms_bt_ui_p[bt_index].mmi_need_update_list = MMI_TRUE;    
        mmi_popup_display_ext(
            STR_GLOBAL_DONE,
            MMI_EVENT_SUCCESS,
            NULL);

        action_result = SMS_RESULT_OK;

    }
    

    mmi_frm_scrn_close(g_sms_bt_gid, SCR_ID_SMS_BT_PROCESSING);
    mmi_frm_group_close(g_sms_bt_gid);
   // mmi_sms_um_bt_close_list_screen();
    g_menu_cui_gid = GRP_ID_INVALID;
    g_sms_bt_gid = GRP_ID_INVALID;
    if (callback_func != NULL)
    {
        callback_func(action_result, NULL);
    }

    if (delete_msg_cntx != NULL)
    {
        OslMfree(delete_msg_cntx);
    }
}




/*****************************************************************************
 * FUNCTION
 *  mmi_sms_delete_msg
 * DESCRIPTION
 *  Delete Msg
 * PARAMETERS
 *  index           [IN]    Msg Index
 *  callback_func   [IN]    Callback Function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_delete_msg(srv_sms_btmapc_bt_enum bt_index, U16 msg_id, SmsCBFuncPtr callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_delete_msg_struct *delete_msg_cntx = OslMalloc(sizeof(srv_sms_btmapc_delete_msg_struct));
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(delete_msg_cntx, 0, sizeof(srv_sms_btmapc_delete_msg_struct));
    delete_msg_cntx->bt_index = bt_index;
    delete_msg_cntx->callback_func = callback_func;
    delete_msg_cntx->msg_id = msg_id;
    {
        mmi_sms_bt_set_and_entry_processing_sg(g_sms_bt_gid, STR_GLOBAL_DELETING, 0);

        srv_sms_btmapc_delete_msg(
            bt_index,
            msg_id,
            mmi_sms_bt_delete_msg_rsp,
            delete_msg_cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_reply
 * DESCRIPTION
 *  Highlight replay handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_viewer_opt_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_sms_bt_set_and_entry_processing_sg(g_sms_bt_gid, STR_GLOBAL_DELETING, 0);
    mmi_sms_bt_delete_msg(g_sms_active_dev_index, g_sms_bt_cntx.curr_msg_id, mmi_sms_bt_viewer_opt_delete_callback);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_reply
 * DESCRIPTION
 *  Highlight replay handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_viewer_call_sender(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
      U16 number[SRV_SMS_MAX_ADDR_LEN + 1];
	  //U8 asc_num[SRV_SMS_MAX_ADDR_LEN + 1];
      mmi_ucm_make_call_para_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	 srv_sms_btmapc_get_msg_address(g_sms_bt_cntx.curr_msg_id, (S8*)number);

	 //mmi_ucs2_to_asc((CHAR*)&asc_num, (CHAR*)&number);

	 //mmi_ucm_dial_option_bt((CHAR *)asc_num);
     if ((number[0] != '\0') || (number[1] != '\0'))
    {
        mmi_ucm_init_call_para(&param);
    
        param.dial_type = SRV_UCM_CALL_TYPE_ALL;
        param.ucs2_num_uri = (U16 *)number;
    
        mmi_ucm_call_launch(0, &param);
    }
    else
    {
        mmi_popup_display_ext(
            STR_GLOBAL_NO_NUMBER,
            MMI_EVENT_FAILURE,
            NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_opt_operation
 * DESCRIPTION
 *  Pre entry list option send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_viewer_opt_operation(mmi_sms_bt_send_case_enum send_case)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_bt_entry_write_msg(send_case);

    mmi_frm_scrn_close(g_sms_bt_gid, SCR_ID_SMS_BT_VIEWER);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_editor_options
 * DESCRIPTION
 *  SMS/EMS Editor Options Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_entry_editor_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/



     /*----------------------------------------------------------------*/
	 /*----------------------------------------------------------------*/
	 /********** update the length of the ems buffer **************************/
	 /******************************************************************/

    mmi_sms_bt_entry_menu_cui_options_generic(
        g_sms_bt_gid,
        MENU_ID_SMS_BT_EDITOR_OPTIONS,
        0);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_send_msg_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static mmi_ret mmi_sms_bt_save_to_drafts_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
        case EVT_ID_GROUP_INACTIVE:
            break;

        case EVT_ID_GROUP_DEINIT:
            /* need addd code to release buffer */
            sms_bt_save_to_draft_child_gid = GRP_ID_INVALID;
            break;

        case EVT_ID_CUI_SMS_SAVE:
            mmi_sms_reset_recipient_data();

            mmi_frm_scrn_close(g_sms_bt_gid, SCR_ID_SMS_BT_EDITOR);

            cui_sms_save_close(sms_bt_save_to_draft_child_gid);
            mmi_frm_group_close(sms_bt_save_to_draft_parent_gid);
            break;

        case EVT_ID_CUI_SMS_SAVE_CANCEL:
            cui_sms_save_close(sms_bt_save_to_draft_child_gid);
            mmi_frm_group_close(sms_bt_save_to_draft_parent_gid);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}



/********************************************************************************************************************************
********************* Move this code to SmsBtAppEditor **************************************************************************
********************************************************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_ed_send_to
 * DESCRIPTION
 *  The "Send to" menu LSK Handle Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_ed_send_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_bt_entry_add_recipient();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_add_recipient
 * DESCRIPTION
 *  Entry Add Recipient Screen Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_entry_add_recipient(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

//	srv_sms_msg_data_struct* send_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 
	/*	S8 *msg_content = (S8 *)OslMalloc(1024);
		send_data = NULL;
		send_data = (srv_sms_msg_data_struct*)OslMalloc(sizeof(srv_sms_msg_data_struct));
		   
		send_data->para_flag = (srv_sms_para_enum)(SRV_SMS_PARA_CONTENT_BUFF | SRV_SMS_PARA_ORI_8BIT_DATA);
		send_data->content_buff_size = 1024;
		send_data->content_buff = msg_content;
		memset(send_data->content_buff, 1024, 0);*/
		mmi_sms_bt_send_sms_dummy();
}



/****************************************************************************
************************ sender cui flow ************************************
****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_edit_phone_number
 * DESCRIPTION
 *  Entry Phone Number/Address Full Edit Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_sms_bt_send_edit_phone_number(mmi_id parent_id, U16* addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // mmi_id sms_send_gid = cui_sms_get_active_send_gid();
   // cui_sms_send_handle_struct *handle = cui_sms_get_send_handle(sms_send_gid);
   // cui_sms_edit_phone_number_struct *edit_num_info = cui_sms_get_edit_number_info(sms_send_gid);
	CHAR buff_num[25] = {0,};
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_gid = cui_fseditor_create(parent_id);



    if (editor_gid != GRP_ID_INVALID)
    {
        U32 input_type = IMM_INPUT_TYPE_SIM_NUMERIC | INPUT_TYPE_PLUS_CHARACTER_HANDLING;
        cui_fseditor_set_title(editor_gid, STR_GLOBAL_EDIT, IMG_SMS_ENTRY_SCRN_CAPTION);
		cui_fseditor_set_input_method(editor_gid, input_type, NULL, 0);
        if(addr != NULL)
		{
			cui_fseditor_set_text(editor_gid, addr, 21 * ENCODING_LENGTH, 21);
		}
		else
		{
			cui_fseditor_set_text(editor_gid, buff_num, 21 * ENCODING_LENGTH, 21);
		}
        
        {
            MMI_ID lsk_string = STR_GLOBAL_OK;
            lsk_string = STR_GLOBAL_SEARCH;

            cui_fseditor_set_softkey_text(editor_gid, MMI_LEFT_SOFTKEY, lsk_string);
            cui_fseditor_set_softkey_icon(editor_gid, MMI_LEFT_SOFTKEY, IMG_SMS_COMMON_NOIMAGE);
            cui_fseditor_run(editor_gid);
        }
    }
    else
    {
        //cui_sms_entry_phone_number_leave_proc(handle);
    }
}




/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_phone_number_generic
 * DESCRIPTION
 *  Entry Phone Number/Address Full Edit screen Generic Function
 * PARAMETERS
 *  screen_id           [IN]    Screen ID
 *  tilte_id            [IN]    Title String ID
 *  addr_type           [IN]    Address Type (SMS Phone Number / Email Address)
 *  ucs2_addr           [IN]    The original Address
 *  done_func           [IN]    Edit Finish Callback Function
 *  is_search_phonebook [IN]    Whether Allow to search Phonebook Or Not
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_bt_entry_phone_number_generic(
            U16 screen_id,
            U16 tilte_id,
            cui_sms_bt_address_type_enum addr_type,
            S8 *ucs2_addr,
            U16 max_addr_len,
            SmsBtFullEditFuncPtr done_func,
            MMI_BOOL is_search_phonebook)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid = cui_sms_get_active_send_gid();
    cui_sms_bt_edit_phone_number_struct *edit_num_info = OslMalloc(sizeof(cui_sms_bt_edit_phone_number_struct));
   // cui_sms_send_handle_data_struct *hd_data = cui_sms_get_send_handle_data(sms_send_gid);
   // hd_data->edit_num_info = edit_num_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_ENTER_PHONE_NUMBER_GENERIC, sms_send_gid);

    edit_num_info->editor_gid = GRP_ID_INVALID;
    edit_num_info->phone_number_title_id = tilte_id;
    edit_num_info->phone_number_done_func = done_func;
    edit_num_info->phone_number_search_flag = is_search_phonebook;
    edit_num_info->phone_number_addr_type = addr_type;
    edit_num_info->phone_number_max_addr_len = max_addr_len;
    edit_num_info->is_refresh_scrn = MMI_FALSE;

    edit_num_info->phone_number_buff = OslMalloc((edit_num_info->phone_number_max_addr_len + 1) * ENCODING_LENGTH);

    mmi_ucs2cpy(edit_num_info->phone_number_buff, ucs2_addr);

    cui_sms_send_edit_phone_number();
}

/*****************************************************************************
 * FUNCTION
 *  cui_sms_processing_generic_time_out
 * DESCRIPTION
 *  Time out call back of processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_bt_processing_generic_time_out_sg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MESSAGES_INPROGRESS_TIMER_ID);

    if (mmi_frm_scrn_get_active_id() == SCR_ID_SMS_BT_PROCESSING)
    {
        mmi_popup_display_ext(
            STR_GLOBAL_UNFINISHED,
            MMI_EVENT_FAILURE,
            NULL);
    }

    mmi_frm_scrn_close(sms_bt_process_gid, SCR_ID_SMS_BT_PROCESSING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_exit_processing_generic
 * DESCRIPTION
 *  Exit MSG generic processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_exit_processing_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MESSAGES_INPROGRESS_TIMER_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_processing_generic_sg
 * DESCRIPTION
 *  Entry MSG generic processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_entry_processing_generic_sg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 process_image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_prompt_trace(MOD_MMI, "Akhil enter progressing screen");
    if (mmi_frm_scrn_enter(
            sms_bt_process_gid,
            SCR_ID_SMS_BT_PROCESSING,
            mmi_sms_exit_processing_generic,
            mmi_sms_bt_entry_processing_generic_sg,
            MMI_FRM_FULL_SCRN))
    {
		kal_prompt_trace(MOD_MMI, "Akhil entry sucessful progressing screen");
        process_image_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
        #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
		mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
	#endif

        /*do not set title and title icon, otherwise processing screen will be a full screen*/
        ShowCategory8Screen(
            0,
            0,
            0,
            0,
            sms_bt_process_rsk_str_id,
            0,
            sms_bt_process_body_str_id,
            process_image_id,
            NULL);


        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);

        if (sms_bt_process_rsk_str_id == 0)
        {
            StartTimer(MESSAGES_INPROGRESS_TIMER_ID, MMI_SMS_PROGRESS_TIME_OUT, mmi_sms_bt_processing_generic_time_out_sg);
        }

        if (sms_bt_process_rsk_str_id != 0)
        {
            SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);       
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_processing_screen_sg
 * DESCRIPTION
 *  Set string and image for MSG processing screen
 * PARAMETERS
 *  captionStrId            [IN]        
 *  bodyStrId               [IN]        
 *  animationImageId        [IN]        
 *  rskStrId                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_set_processing_screen_sg(mmi_id sms_gid, U16 bodyStrId, U16 rskStrId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_bt_process_body_str_id = bodyStrId;
    sms_bt_process_rsk_str_id = rskStrId;
    sms_bt_process_gid = sms_gid;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_and_entry_processing_sg
 * DESCRIPTION
 *  Set string and image for MSG processing screen
 * PARAMETERS
 *  captionStrId            [IN]        
 *  bodyStrId               [IN]        
 *  animationImageId        [IN]        
 *  rskStrId                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_set_and_entry_processing_sg(mmi_id sms_gid, U16 bodyStrId, U16 rskStrId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_bt_set_processing_screen_sg(sms_gid, bodyStrId, rskStrId);
    mmi_sms_bt_entry_processing_generic_sg();
}
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*********************************** EMS PART **********************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  DeInitMessagesEMSBuffer
 * DESCRIPTION
 *  Releaset EMS buffer
 * PARAMETERS
 *  pE      [IN]        
 * RETURNS
 *  EMS buffer valid flag
 *****************************************************************************/
void SmsBtDeInitMessagesEMSBuffer(EMSData *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS retVal;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p)
    {
        retVal = ReleaseEMSData(p);
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_FRM_DEINIT_MESSAGES_EMS_BUFFER, retVal);
    }
}


/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*********************************** EMS PART **********************************/
/*********************************** Move to SmsBtAppUtil ************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_add_gsm_text_to_ems_data
 * DESCRIPTION
 *  add (GSM character set, UCS2 Format) Text into EMS Data
 * PARAMETERS
 *  ems_data        [IN]    EMS Data to be added
 *  ucs2_content    [IN]    UCS2 content 
 * RETURNS
 *  void
 *****************************************************************************/
EMSTATUS mmi_sms_bt_add_gsm_text_to_ems_data(EMSData * ems_data,S8 * ucs2_content)
{
   
   EMSTATUS result = EMS_OK;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_add_data_to_ems_data
 * DESCRIPTION
 *  Add text into the EMS Data
 * PARAMETERS
 *  ems_data        [IN]    EMS Data to be added
 *  src_port        [IN]    Source port number
 *  dest_port       [IN]    Destination port number
 *  file_path       [IN]    File path of the content 
 *  content_buff    [IN]    The buffer ot content
 *  buff_size       [IN]    The buffer size of content_buff
 * RETURNS
 *  EMSTATUS
 *****************************************************************************/
EMSTATUS mmi_sms_bt_add_data_to_ems_data(EMSData * ems_data,U16 src_port,U16 dest_port,S8 * file_path,S8 * content_buff,U32 buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS result = EMS_OK;
    S8 *ucs2_content = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        U16 char_num = 0;

        if (file_path != NULL)
        {
            FS_HANDLE fs_hd;

            fs_hd = FS_Open((WCHAR*)file_path, FS_READ_ONLY);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ADD_DATA_TO_EMS_DATA_1, fs_hd);

            if (fs_hd > 0)
            {
                U32 content_file_size;

                FS_GetFileSize(fs_hd, (UINT*)&content_file_size);

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ADD_DATA_TO_EMS_DATA_2, content_file_size);

                if (content_file_size > 0)
                {
                    if (content_file_size > ((MMI_SMS_MAX_BUFF_SIZE / ENCODING_LENGTH) - 1))
                    {
                        result = EMS_EMS_DATA_EXCEEDED;
                    }
                    else
                    {
                        S32 fs_err_code = 0;
                        S8 *temp_buff;
                        S32 read_size = 0;

                        temp_buff = OslMalloc(content_file_size + 1);
                        fs_err_code = FS_Read(fs_hd, temp_buff, content_file_size, (UINT*)&read_size);

                        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ADD_DATA_TO_EMS_DATA_3, fs_err_code);

                        if (fs_err_code < 0)
                        {
                            result = EMS_INVALID_EMS_DATA;
                        }
                        else
                        {
                            ucs2_content = OslMalloc((content_file_size + 1) * ENCODING_LENGTH);

                             mmi_sms_bt_asc_to_wchar(ucs2_content, temp_buff, content_file_size);
                            char_num = content_file_size;
                        }

                        OslMfree(temp_buff);
                    }
                }
            }
            else
            {
                result = EMS_INVALID_EMS_DATA;
            }

            FS_Close(fs_hd);

            if (result != EMS_OK)
            {
                break;
            }
        }
        else if ((content_buff != NULL) && (buff_size > 0))
        {
            ucs2_content = OslMalloc((buff_size + 1) * ENCODING_LENGTH);

            mmi_sms_bt_asc_to_wchar(ucs2_content, content_buff, buff_size);
            char_num = buff_size;
        }

        result = EMSSetPortNum(ems_data, src_port, dest_port);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ADD_DATA_TO_EMS_DATA_4, result);

        if (result != EMS_OK)
        {
            break;
        }

        result = EMSSetDCS(ems_data, SMSAL_8BIT_DCS);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ADD_DATA_TO_EMS_DATA_5, result);

        if (result != EMS_OK)
        {
            result = EMS_EMS_DATA_EXCEEDED;
            break;
        }

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ADD_DATA_TO_EMS_DATA_6, char_num);

        if (char_num > 0)
        {
        #ifdef __ULC_SLIM_EMS__
          //  result = mmi_sms_bt_append_string_to_ems_buffer(ems_data, (CHAR*)ucs2_content, char_num);
        #else /* __ULC_SLIM_EMS__ */
            result = AddString(ems_data, (U8*)ucs2_content, char_num, NULL);
        #endif /* __ULC_SLIM_EMS__ */

            if (result != EMS_OK)
            {
                result = EMS_EMS_DATA_EXCEEDED;
            }
        }
    } while (0);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ADD_DATA_TO_EMS_DATA_7, result);

    if (ucs2_content != NULL)
    {
        OslMfree(ucs2_content);
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_asc_to_wchar
 * DESCRIPTION
 *  convert the each byte of the source to one wise char according to 
 *  the source buffer len
 * PARAMETERS
 *  dest_buf        [OUT]       destintaion buffer
 *  src_buf         [IN]        source buffer
 *  src_buf_len     [IN]        source buffer length
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_asc_to_wchar(S8 *dest_buf, S8 *src_buf, U32 src_buf_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *wchar_dest_buff = (U16*)dest_buf;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < src_buf_len; i++)
    {
        wchar_dest_buff[i] = (U16)src_buf[i];
    }

    wchar_dest_buff[i] = '\0';
}


#ifdef __ULC_SLIM_EMS__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_append_string_to_ems_buffer
 * DESCRIPTION
 *  copy text buffer to ems data text buffer, used instead of AddString of EMS lib
 * PARAMETERS      
 *  msg_id              [IN]        
 *  address             [OUT]         
 *  max_address_len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
EMSTATUS mmi_sms_bt_append_string_to_ems_buffer(EMSData *pEms, CHAR *ucs2_buffer, S32 textLen)
{
    MMI_BOOL result;
    EMSTATUS EMS_result = EMS_EMS_DATA_EXCEEDED;
    result = mmi_sms_check_if_insert_text_possible((const CHAR*)pEms->textBuffer, (const CHAR*)ucs2_buffer);
    if (result)
    {
        mmi_ucs2ncpy((CHAR*)pEms->textBuffer, (const CHAR *)ucs2_buffer, textLen);
        pEms->textLength = textLen * ENCODING_LENGTH;
        EMS_result = EMS_OK;
    }
    
    return EMS_result;
}

#endif /* __ULC_SLIM_EMS__ */


#ifndef __ULC_SLIM_EMS__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_is_ems_content_empty
 * DESCRIPTION
 *  Check whether the EMS Data is empty
 * PARAMETERS
 *  ems_data        [IN]    EMS Data to be added
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_bt_is_ems_content_empty(EMSData *ems_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ems_data->textLength == 0) && (ems_data->listHead == NULL))
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}

#else /* __ULC_SLIM_EMS__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_is_ems_content_empty
 * DESCRIPTION
 *  Check whether the EMS Data is empty
 * PARAMETERS
 *  ems_data        [IN]    EMS Data to be added
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_bt_is_ems_content_empty(EMSData *ems_data)
{

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)(mmi_ucs2strlen((const CHAR *)ems_data->textBuffer) == 0);
}

#endif /* __ULC_SLIM_EMS__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_update_ems_length
 * DESCRIPTION
 *  Initialize editor
 * PARAMETERS
 *  current_text_info       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_update_ems_length(EMSData *ems_data)
{
	MMI_ASSERT(ems_data != NULL);
    ems_data->textLength = mmi_ucs2strlen((const CHAR *)ems_data->textBuffer) * ENCODING_LENGTH;
    MMI_ASSERT(ems_data->textLength <= (ems_data->textBufferSize));
}


srv_sms_msg_data_struct *mmi_sms_bt_get_msg_data_for_forward()
{
	//MMI_ASSERT(msg_data != NULL);
	return msg_data;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_insert_text_to_editor
 * DESCRIPTION
 *  Insert Text to the SMS Editor
 * PARAMETERS
 *  text_buff       [IN] the Input Text Buffer
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void mmi_sms_update_editor_info(CHAR* text_buff)
{
    wgui_uce_text_info_struct editor_text_info;
    mmi_7bit_counter_struct gsm_text_info;
    mmi_sms_count_buffer_charactor(text_buff, &gsm_text_info);
    editor_text_info.char_count = gsm_text_info.gsm_count + gsm_text_info.ucs2_count + gsm_text_info.gsm_ext_count;
    editor_text_info.extension_char_count = gsm_text_info.gsm_ext_count;
    editor_text_info.UCS2_count = gsm_text_info.ucs2_count;
    editor_text_info.utf8_msg_len = 0;
    wgui_uce_set_current_text_info(&editor_text_info);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_count_buffer_charactor()
 * DESCRIPTION
 *  count content character nubmers
 * PARAMETERS
 *  content_buffer              : [IN]  content to be counted
 *  content_text_info           : [OUT] result of buffer count
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_count_buffer_charactor(const S8 *content_buffer, mmi_7bit_counter_struct *content_text_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_7bit_counter_struct *temp_counter = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_7bit_counter_init((U8*)content_buffer);
    temp_counter = mmi_7bit_counter_get_info();
    if (content_text_info != NULL)
    {
        memcpy(content_text_info, temp_counter, sizeof(mmi_7bit_counter_struct));
    }
}

mmi_sms_bt_box_enum mmi_sms_bt_get_mmi_box_type_by_bt(srv_sms_btmapc_box_enum box_type)
{
    mmi_sms_bt_box_enum mmi_box_type = MMI_SMS_BT_BOX_NONE;

    switch (box_type)
    {
        case SRV_SMS_BTMAPC_BOX_INBOX:
        {
            mmi_box_type = MMI_SMS_BT_BOX_INBOX;
            break;
        }
        case SRV_SMS_BTMAPC_BOX_UNSENT:
        {
            mmi_box_type = MMI_SMS_BT_BOX_UNSENT;
            break;
        }
        case SRV_SMS_BTMAPC_BOX_OUTBOX:
        {
            mmi_box_type = MMI_SMS_BT_BOX_OUTBOX;
            break;
        }
        case SRV_SMS_BTMAPC_BOX_DRAFTS:
        {
            mmi_box_type = MMI_SMS_BT_BOX_DRAFTS;
            break;
        }
        case SRV_SMS_BTMAPC_BOX_DELETED:
        {
            mmi_box_type = MMI_SMS_BT_BOX_DELETED;
            break;
        }
        default:
        {
            mmi_box_type = MMI_SMS_BT_BOX_NONE;
        }
    }   
    return mmi_box_type;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bt_new_msg_receive
 * DESCRIPTION
 *  mmi_sms_bt_new_msg_receive
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret  mmi_sms_bt_new_msg_receive(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_bt_entry_folder_userdata *userdata;
    srv_sms_event_struct *evt = (srv_sms_event_struct *)param;
    srv_sms_btmapc_event_new_sms_struct *evt_data;
    mmi_sms_bt_box_enum mmi_box_type = MMI_SMS_BT_BOX_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    evt_data = (srv_sms_btmapc_event_new_sms_struct *)evt->event_info;
    scrn_cntx = mmi_sms_um_bt_ui_sh_get_active_user_data();

    kal_wap_trace(MOD_MMI_COMMON_APP,TRACE_GROUP_6,"APP newmsg mmi_folder : %d,service_folder: %d", mmi_box_type,evt_data->box_type);
    mmi_box_type = mmi_sms_bt_get_mmi_box_type_by_bt(evt_data->box_type);
    g_sms_bt_ui_p[evt_data->bt_index].need_refresh[mmi_box_type] = MMI_TRUE;
    if (scrn_cntx != NULL)
    {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_bt_new_msg_receive userdata->scrn_id = %d  scrn_cntx->aprc.st_type = %d", scrn_cntx->scrn_id, scrn_cntx->aprc.st_type );
        g_sms_bt_ui_p[evt_data->bt_index].mmi_need_update_list = MMI_TRUE;

        if (scrn_cntx->aprc.st_type == MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER && 
            scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type == SRV_UM_MSG_BTMAPC_BOX_INBOX &&
            g_sms_active_dev_index == evt_data->bt_index && !g_sms_bt_ui_p[evt_data->bt_index].is_on_request)
        {
            userdata = &g_ef_usdata;
            userdata->is_back_folder = MMI_TRUE;
            userdata->scrn_id = scrn_cntx->scrn_id;
            userdata->bt_index = evt_data->bt_index;

            scrn_cntx->child_scrn_id = mmi_sms_um_bt_ui_if_entry_processing(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE);
            g_sms_bt_ui_p[evt_data->bt_index].is_on_request = MMI_TRUE;
            g_sms_bt_ui_p[evt_data->bt_index].sms_handle = srv_sms_btmapc_get_msg_list_by_tab(evt_data->bt_index, MMI_TRUE,
                scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type,
                mmi_sms_bt_get_inbox_list_cb,
                userdata);
            kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_bt_new_msg_receive mmi_sms_um_bt_ui_ut_send_init_event  ");

            mmi_sms_um_bt_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
            return MMI_RET_OK;
                
        }
    }
    if (mmi_box_type == MMI_SMS_BT_BOX_INBOX)
    {
        kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_bt_new_msg_receive wgui_status_icon_bar_show_icon  ");
    	g_bt_new_msg_alert.app_id = APP_SMSBTUNIFIEDMESSAGE; //your app id
    	g_bt_new_msg_alert.alert_option = MMI_FRM_NMGR_DISABLE_PREVIEW;
        g_bt_new_msg_alert.status_bar_icon_para.icon_id = STATUS_ICON_BT_INCOMING_SMS;
    	g_new_bt_msg_handle = mmi_frm_nmgr_compose_alert_handle(APP_SMSBTUNIFIEDMESSAGE,MMI_EVENT_DEFAULT, 0);
    	g_new_bt_msg_handle = mmi_frm_nmgr_alert(&g_bt_new_msg_alert);
        wgui_status_icon_bar_show_icon(STATUS_ICON_BT_INCOMING_SMS);
		if(evt_data->bt_index == SRV_SMS_BTMAPC_BT_INDEX0)
			g_new_bt_msg_dev_mask |= MMI_SMS_BT_DEV0;
		else if(evt_data->bt_index == SRV_SMS_BTMAPC_BT_INDEX1)
			g_new_bt_msg_dev_mask |= MMI_SMS_BT_DEV1;
    }

    return MMI_RET_OK;
}


mmi_ret mmi_sms_bt_update_ui(mmi_event_struct *param)
{
    int i = 0;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_bt_entry_folder_userdata *userdata;
    srv_sms_event_struct *evt = (srv_sms_event_struct *)param;
    srv_sms_btmapc_conn_struct *event_data = (srv_sms_btmapc_conn_struct *)evt->event_info;
    mmi_sms_bt_box_enum mmi_box_type = MMI_SMS_BT_BOX_NONE;
    SrvSmsCallbackFunc callback;
    scrn_cntx = mmi_sms_um_bt_ui_sh_get_active_user_data();
    
    if (scrn_cntx != NULL)
    {
        if (scrn_cntx->aprc.st_type == MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER)
        {          
            mmi_scrn_essential_struct ess_struct;

            ess_struct.scrn_id = scrn_cntx->screen_hdlr.disp_scrn_id;
            ess_struct.group_id = scrn_cntx->group_id;
            ess_struct.user_data = scrn_cntx;
            mmi_sms_bt_um_ui_aprc_263_tab_BT(&ess_struct);
        }
    }
    
}


mmi_ret mmi_sms_bt_update_ui_list(void)
{
    int i = 0;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_bt_entry_folder_userdata *userdata;
    mmi_sms_bt_box_enum mmi_box_type = MMI_SMS_BT_BOX_NONE;
    scrn_cntx = mmi_sms_um_bt_ui_sh_get_active_user_data();
    kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_update_ui_list");
    if (scrn_cntx != NULL)
    {
        kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_update_ui_list  scrn_cntx != NULL");
        if (scrn_cntx->aprc.st_type == MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER)
        {          
            mmi_scrn_essential_struct ess_struct;

            ess_struct.scrn_id = scrn_cntx->screen_hdlr.disp_scrn_id;
            ess_struct.group_id = scrn_cntx->group_id;
            ess_struct.user_data = scrn_cntx;
            kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_bt_disconnected bt_active_index = %d  disp_scrn_id = %d  group_id = %d", g_sms_bt_ui_p->bt_active_index, scrn_cntx->screen_hdlr.disp_scrn_id, scrn_cntx->group_id);			
            wgui_cat1032_refresh_list(0,0, NULL,NULL);
            mmi_sms_bt_um_ui_aprc_263_tab_BT(&ess_struct);
        }
    }
    
}


mmi_um_tab_page mmi_sms_tab_id_to_tab_pags(srv_sms_btmapc_bt_enum bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_tab_page tab_pages_enter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (bt_index)
    {
        case SRV_SMS_BTMAPC_BT_INDEX0:
        {
            tab_pages_enter = MMI_UM_TAB_PAGE_BT;
            break;
        }
        case SRV_SMS_BTMAPC_BT_INDEX1:
        {
            tab_pages_enter = MMI_UM_TAB_PAGE_BT2;
            break;
        }
        case SRV_SMS_BTMAPC_BT_INDEX2:
        {
            tab_pages_enter = MMI_UM_TAB_PAGE_LOCAL;
            break;
        }
        default:
        {
            break;
        }        
    }
    return tab_pages_enter;
}


mmi_ret mmi_sms_bt_connected(mmi_event_struct *param)
{
    int i = 0;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_bt_entry_folder_userdata *userdata;
    srv_sms_event_struct *evt = (srv_sms_event_struct *)param;
    srv_sms_btmapc_conn_struct *event_data = (srv_sms_btmapc_conn_struct *)evt->event_info;
    mmi_sms_bt_box_enum mmi_box_type = MMI_SMS_BT_BOX_NONE;
    SrvSmsCallbackFunc callback;
    U8 index = 0;
    scrn_cntx = mmi_sms_um_bt_ui_sh_get_active_user_data();
    memset(&g_sms_bt_ui_p[event_data->bt_index], 0, sizeof(g_sms_bt_ui_p));
    
    kal_wap_trace(MOD_MMI_COMMON_APP,TRACE_GROUP_6,"APP CONNECTED : %d", event_data->error);
    if (event_data->error == SRV_BT_MAPC_SUCCESS)
    {
        g_sms_bt_ui_p[event_data->bt_index].is_bt_connected = MMI_TRUE;
        g_sms_bt_ui_p[event_data->bt_index].last_entered = SRV_SMS_BTMAPC_BOX_NONE;
        for (i = 0; i < MMI_SMS_BT_BOX_END; i++)
        {
            g_sms_bt_ui_p[event_data->bt_index].need_refresh[i] = MMI_TRUE;
        }
        if (scrn_cntx != NULL)
        {
            mmi_box_type = mmi_sms_bt_get_mmi_box_type_by_bt(scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type);
            callback = mmi_sms_bt_get_callback_hdlr(scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type);
            userdata = &g_ef_usdata;
            userdata->is_back_folder = MMI_TRUE;
            userdata->scrn_id = scrn_cntx->scrn_id;
            userdata->bt_index = event_data->bt_index;
            g_sms_bt_ui_p[event_data->bt_index].mmi_need_update_list = MMI_TRUE;
            if (scrn_cntx->aprc.st_type == MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER &&
                g_sms_active_dev_index == event_data->bt_index &&
                !g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request)
            {
                scrn_cntx->child_scrn_id = mmi_sms_um_bt_ui_if_entry_processing(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE);
                g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request = MMI_TRUE;
                g_sms_bt_ui_p[g_sms_active_dev_index].sms_handle = srv_sms_btmapc_get_msg_list_by_tab(g_sms_active_dev_index,MMI_TRUE,
                    scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type,
                    callback,
                    userdata);

                mmi_sms_um_bt_ui_ut_send_init_event(scrn_cntx->child_scrn_id);                 
            }
        }
        g_tab_last_enter = MMI_UM_TAB_PAGE_BT;
        return MMI_RET_OK;
    }
    else if (event_data->error == SRV_BT_MAPC_FAIL_NOT_SUPPORTED)
    {
        g_sms_bt_ui_p[event_data->bt_index].remote_not_support = MMI_TRUE;
    }
    g_sms_bt_ui_p[event_data->bt_index].is_bt_connected = MMI_FALSE;
    g_sms_bt_ui_p[event_data->bt_index].last_entered = SRV_SMS_BTMAPC_BOX_NONE;
    return MMI_RET_OK;
}

extern mmi_id mmi_sms_bt_editor_send_parent_gid;
mmi_ret mmi_sms_bt_disconnected(mmi_event_struct *param)
{
    int i = 0;
    srv_sms_event_struct *evt = (srv_sms_event_struct *)param;
    srv_sms_btmapc_conn_struct *event_data = (srv_sms_btmapc_conn_struct *)evt->event_info;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx = mmi_sms_um_bt_ui_sh_get_active_user_data();
	srv_sms_btmapc_box_enum cur_box = g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered;
    kal_wap_trace(MOD_MMI_COMMON_APP,TRACE_GROUP_6,"APP DISCONNECTED");

	memset(&g_sms_bt_ui_p[event_data->bt_index], 0, sizeof(g_sms_bt_ui_p));
    //memset(g_sms_bt_ui_p, 0, sizeof(g_sms_bt_ui_p));
    g_sms_bt_ui_p[event_data->bt_index].is_bt_connected = MMI_FALSE;
    g_sms_bt_ui_p[event_data->bt_index].last_entered = SRV_SMS_BTMAPC_BOX_NONE;
    g_sms_bt_ui_p[event_data->bt_index].remote_not_support = MMI_FALSE;
    g_sms_bt_ui_p[event_data->bt_index].mmi_need_update_list = MMI_TRUE;
    g_sms_bt_ui_p[event_data->bt_index].mmi_need_keep_list = MMI_FALSE;	
	g_sms_bt_ui_p[event_data->bt_index].is_on_request = MMI_FALSE;
    for (i = 0; i < MMI_SMS_BT_BOX_END; i++)
    {
        g_sms_bt_ui_p[event_data->bt_index].need_refresh[i] = MMI_TRUE;
    }
	
	if(event_data->bt_index != g_sms_active_dev_index)
		return MMI_RET_OK;
	
    srv_sms_btmapc_cancel_op(g_sms_bt_ui_p[g_sms_active_dev_index].sms_handle);
    StopTimer(MESSAGES_INPROGRESS_TIMER_ID);
	
    if(mmi_sms_bt_editor_send_parent_gid != GRP_ID_INVALID)
    {
        mmi_frm_group_close(mmi_sms_bt_editor_send_parent_gid);
    }
	
    if (g_sms_gid != GRP_ID_INVALID)
    {
        mmi_frm_group_close(g_sms_gid);
    }

    if (g_sms_bt_gid != GRP_ID_INVALID)
    {
        mmi_frm_group_close(g_sms_bt_gid);
    }

    if (g_new_bt_msg_handle)
    {
    	if(event_data->bt_index == SRV_SMS_BTMAPC_BT_INDEX0)
        {
        	if(g_new_bt_msg_dev_mask & MMI_SMS_BT_DEV0)
				g_new_bt_msg_dev_mask &= ~MMI_SMS_BT_DEV0;
			if(!g_new_bt_msg_dev_mask)
        	{
        		mmi_frm_nmgr_alert_cancel(g_new_bt_msg_handle);
				g_new_bt_msg_handle = NULL;
			}
			
    	}
		else if(event_data->bt_index == SRV_SMS_BTMAPC_BT_INDEX1)
        {
        	if(g_new_bt_msg_dev_mask & MMI_SMS_BT_DEV1)
        		g_new_bt_msg_dev_mask &= ~MMI_SMS_BT_DEV1;
			if(!g_new_bt_msg_dev_mask)
        	{
        		mmi_frm_nmgr_alert_cancel(g_new_bt_msg_handle);
				g_new_bt_msg_handle = NULL;
			}
			
    	}
	}
    if (scrn_cntx == NULL)
        return MMI_RET_OK;
    kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_bt_disconnected bt_active_index = %d  disp_scrn_id = %d  group_id = %d", g_sms_bt_ui_p->bt_active_index, scrn_cntx->screen_hdlr.disp_scrn_id, scrn_cntx->group_id);
    kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_bt_disconnected scrn_cntx->aprc.st_type =%d",scrn_cntx->aprc.st_type );

    if (scrn_cntx->aprc.st_type == MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER )
    {
        mmi_sms_bt_update_ui_list();
    }
	else if(scrn_cntx->aprc.st_type == MMI_SMS_UM_BT_UI_SCRN_TYPE_LOADING )
	{
	    kal_prompt_trace(MOD_MMI, "[SMS], scrn_cntx->aprc.st_type == MMI_SMS_UM_BT_UI_SCRN_TYPE_LOADING " );
        mmi_sms_um_bt_ui_sh_main_msg_entry_folder(cur_box, g_sms_um_ui_main_menu_scrn_id);        
	}
    return MMI_RET_OK;
}
extern MMI_BOOL g_sms_bt_disable_del_event;
mmi_ret  mmi_sms_bt_msg_deleted(mmi_event_struct *param)
{
    int i = 0;	
	srv_sms_event_struct *evt_sms = (srv_sms_event_struct *)param;
    srv_sms_btmapc_event_new_sms_struct *evt = (srv_sms_btmapc_event_new_sms_struct *)evt_sms->event_info;
	
    kal_wap_trace(MOD_MMI_COMMON_APP,TRACE_GROUP_6,"SP DELETED");
	if(g_sms_bt_disable_del_event)
		 return MMI_RET_OK;  
    for (i = 0; i < MMI_SMS_BT_BOX_END; i++)
    {
        g_sms_bt_ui_p[evt->bt_index].need_refresh[i] = MMI_TRUE;
    }
    return MMI_RET_OK;   
}
#endif
