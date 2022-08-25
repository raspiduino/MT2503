extern "C"
{
#include "InlineCuiGprot.h"
#include "mmi_rp_app_uiframework_def.h"
}
static const cui_inline_item_caption_struct mmi_dict_tts_speaking_caption[] = {STR_GLOBAL_SELECT,STR_GLOBAL_EDIT,STR_GLOBAL_DETAILS};

static const U16 remote_settings_autoam_status_str[] = 
{
    STR_GLOBAL_OFF,
    STR_GLOBAL_ON
};

static const cui_inline_item_select_struct remote_settings_autoam_status = 
{
    sizeof(remote_settings_autoam_status_str) / sizeof(U16), 0, remote_settings_autoam_status_str
};

static const cui_inline_item_text_edit_struct remote_settings_autoam_hotkey = 
{
    0,                              /* string id */
    0,                              /* default text string id */
    2,                              /* string count */
    IMM_INPUT_TYPE_NUMERIC,    /* input type */
    IMM_INPUT_TYPE_NONE,    /* input extended type */
    NULL                            /* required input mode */
};

static const cui_inline_set_item_struct vs_fw_pluto_inline_screen_item[] = 
{

    {CUI_INLINE_ITEM_ID_BASE + 0, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1,(void*)&mmi_dict_tts_speaking_caption[0] },
    {CUI_INLINE_ITEM_ID_BASE + 1, CUI_INLINE_ITEM_TYPE_SELECT, 0,(void *)&remote_settings_autoam_status},
    {CUI_INLINE_ITEM_ID_BASE + 2, CUI_INLINE_ITEM_TYPE_CAPTION, 0,(void*)&mmi_dict_tts_speaking_caption[1]},
    {CUI_INLINE_ITEM_ID_BASE + 3, CUI_INLINE_ITEM_TYPE_CAPTION, 0,(void*)&mmi_dict_tts_speaking_caption[2]},
    {CUI_INLINE_ITEM_ID_BASE + 4, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, NULL},
	 
};

static cui_inline_item_softkey_struct vs_fw_pluto_inline_screen_softkey = 
{
    {
     {AVK_STR_PASS, 0}, /* MMI_LEFT_SOFTKEY */
     {AVK_STR_FAIL, 0}, /* MMI_RIGHT_SOFTKEY */
     {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0}  /* MMI_CENTER_SOFTKEY */
     }
};

static const cui_inline_struct vs_fw_pluto_inline_setting_data = 
{
    5,
    0,
    0,
    CUI_INLINE_SCREEN_DISABLE_DONE,
    &vs_fw_pluto_inline_screen_softkey,
    vs_fw_pluto_inline_screen_item
};

/*************************Inline 002**********************/

cui_inline_item_fullscreen_edit_struct certman_ocsp_default_web_addr_struct1 = 
{
    0,
    0,
    STR_GLOBAL_EDIT,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_URL,
    50,
    NULL
};

static const cui_inline_item_caption_struct g_phoart_text_text_color_caption[] = 
{
    STR_GLOBAL_EDIT,
	STR_GLOBAL_DATE,
	STR_GLOBAL_TIME,
	STR_GLOBAL_STORAGE
};

static const cui_inline_set_item_struct g_phoart_text_style_items[] =
{
   
    {CUI_INLINE_ITEM_ID_BASE + 0,  CUI_INLINE_ITEM_TYPE_CAPTION,                                       IMG_GLOBAL_L1,    (void*)&g_phoart_text_text_color_caption[0]},
    {CUI_INLINE_ITEM_ID_BASE + 1,   CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, &certman_ocsp_default_web_addr_struct1},
    {CUI_INLINE_ITEM_ID_BASE + 2,  CUI_INLINE_ITEM_TYPE_CAPTION,                                       IMG_GLOBAL_L2,    (void*)&g_phoart_text_text_color_caption[1]},
    {CUI_INLINE_ITEM_ID_BASE + 3,   CUI_INLINE_ITEM_TYPE_DATE , 0,  NULL},
	{CUI_INLINE_ITEM_ID_BASE + 4,  CUI_INLINE_ITEM_TYPE_CAPTION,                                       IMG_GLOBAL_L3,    (void*)&g_phoart_text_text_color_caption[2]},
	{CUI_INLINE_ITEM_ID_BASE + 5,  CUI_INLINE_ITEM_TYPE_TIME,                                       0,    NULL},
	{CUI_INLINE_ITEM_ID_BASE + 6,  CUI_INLINE_ITEM_TYPE_CAPTION,                                    0,   (void*)&g_phoart_text_text_color_caption[3]},
	{CUI_INLINE_ITEM_ID_BASE + 7,  CUI_INLINE_ITEM_TYPE_SELECT,                                    0,   NULL},
   };


static const cui_inline_struct vs_fw_pluto_inline_setting_data_002 = 
{
    8,
    0,
    0,
    CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    g_phoart_text_style_items
};

void vs_fw_pluto_inline_001(void);
void vs_fw_pluto_inline_002(void);

AVK_MANUAL_CASE(AVK_CUI_INLINE_001,AVK_CUI_INLINE)
{
    AVK_MANU_SHOW_TIPS(L"Display Select,Details => Pass",vs_fw_pluto_inline_001);
}

AVK_MANUAL_CASE(AVK_CUI_INLINE_002,AVK_CUI_INLINE)
{
    AVK_MANU_SHOW_TIPS(L"Display Edit, Date, Time, Attachment => Pass",vs_fw_pluto_inline_002);
}

void vs_fw_pluto_inline_set_result(void)
{
     AVK_CASE_RESULT(AVK_PASS);
     AVK_ASYN_DONE();
     mmi_frm_group_close(AVK_GRP_ID_1);
}

void vs_fw_pluto_inline_set_result2(void)
{
     AVK_CASE_RESULT(AVK_PASS);
     AVK_ASYN_DONE();
     mmi_frm_group_close(AVK_GRP_ID_1);
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_pluto_inline_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt             [?]         
 *  index(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret vs_fw_pluto_inline_proc(mmi_event_struct *evt)
{
 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U16 buffer[50];
	U16 get_buffer[50] = {0};


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 mmi_wcscpy((WCHAR *)buffer ,(WCHAR*)L"Display Only control");
    switch (evt->evt_id)
    {

        case EVT_ID_CUI_INLINE_NOTIFY:
			{    cui_event_inline_notify_struct *inline_submit_event = (cui_event_inline_notify_struct*) evt; 
			    if (inline_submit_event->event_type == CUI_INLINE_NOTIFY_ITEM_CHANGED)
			{
                                   // cui_inline_set_value(inline_submit_event->sender_id, CUI_INLINE_ITEM_ID_BASE + 3, buffer);
				  // cui_inline_get_value(inline_submit_event->sender_id, CUI_INLINE_ITEM_ID_BASE + 3, get_buffer);

				}
     			break;
			}

		case EVT_ID_CUI_INLINE_SUBMIT:
			{
				cui_event_inline_abort_struct *inline_evt = (cui_event_inline_abort_struct*) evt;
//			         vs_tfw_trace_result(L"vs_fw_pluto_inline_001", MMI_TRUE, 0, VS_TA_FW_CUI_INLINE);
//			         vs_tfw_finish_case_extern(VS_FW_INLINE_CUI_001, SCR_ID_VS_INLINE);
                AVK_CASE_RESULT(AVK_PASS);               
                cui_inline_close(inline_evt->sender_id);
                mmi_frm_group_close(AVK_GRP_ID_1);
                AVK_ASYN_DONE();
				break;

			}


		case EVT_ID_CUI_INLINE_ABORT:
			{	
						   cui_event_inline_abort_struct *inline_evt = (cui_event_inline_abort_struct*) evt;
//			        vs_tfw_trace_result(L"vs_fw_pluto_inline_001", MMI_FALSE, 0, VS_TA_FW_CUI_INLINE);
//			        vs_tfw_finish_case_extern(VS_FW_INLINE_CUI_001, SCR_ID_VS_INLINE);
                AVK_CASE_RESULT(AVK_FAIL);
                cui_inline_close(inline_evt->sender_id);
				mmi_frm_group_close(AVK_GRP_ID_1);
				AVK_ASYN_DONE();
				break;
			}

		case EVT_ID_CUI_INLINE_SET_KEY:
			{
			  cui_event_inline_set_key_struct  *inline_setkey_event = (cui_event_inline_set_key_struct*)evt;
			  if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + 4)
			  {
			     SetLeftSoftkeyFunction(vs_fw_pluto_inline_set_result,KEY_EVENT_UP);
				 SetCenterSoftkeyFunction(NULL,KEY_EVENT_UP);
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
 *  vs_fw_pluto_inline_001
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_pluto_inline_001(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                                     */
	/*----------------------------------------------------------------*/   
	MMI_ID inline_id = GRP_ID_INVALID;
	U8 data = 0;
	U8 buffer[50];
	U8 edit_buff[50];
	MMI_ID_TYPE item_icons[] = 
	{
		IMG_GLOBAL_L1,
		0,
		IMG_GLOBAL_L2,
		0,
		IMG_GLOBAL_L3,
		0
	};
	U16 get_attr,get_scr_attr, get_parent_data;
	cui_inline_set_item_struct new_item = {0};
	cui_inline_item_display_only_struct display_item; 
#ifdef __MMI_TOUCH_SCREEN__
	gui_virtual_keyboard_pen_enum disable_event_keys_list[] = { GUI_VKBD_PEN_NONE};
#endif

	cui_inline_set_multiline_rd_highlight_list_struct highlight_list = {0};

		

	/*----------------------------------------------------------------*/
	/* Code Body                                                                             */
	/*----------------------------------------------------------------*/
	mmi_frm_group_create(GRP_ID_AVK, AVK_GRP_ID_1, vs_fw_pluto_inline_proc, NULL);
	mmi_frm_group_enter(AVK_GRP_ID_1,MMI_FRM_NODE_SMART_CLOSE_FLAG);

	mmi_wcscpy((WCHAR *)buffer ,(WCHAR *)L"Display Only control");
	mmi_wcscpy((WCHAR *)edit_buff ,(WCHAR *)L"Inline Editor");

	inline_id = cui_inline_create(AVK_GRP_ID_1, &vs_fw_pluto_inline_setting_data);
	AVK_LOG_FUN(cui_inline_create, inline_id!= GRP_ID_INVALID);
	AVK_LOG_NORMAL(cui_inline_set_title(inline_id, STR_GLOBAL_SETTINGS, IMG_GLOBAL_L10));
	AVK_LOG_NORMAL(cui_inline_set_title_icon(inline_id,IMG_GLOBAL_L10));
	AVK_LOG_NORMAL(cui_inline_set_title_string(inline_id,(UI_string_type)GetString(STR_GLOBAL_SETTINGS)));


	// cui_inline_set_text_len( inline_id,CUI_INLINE_ITEM_ID_BASE + 2, 40);
	// get_text_len = cui_inline_get_text_len(inline_id,CUI_INLINE_ITEM_ID_BASE + 2);

	AVK_LOG_NORMAL(cui_inline_set_item_attributes(inline_id,CUI_INLINE_ITEM_ID_BASE + 4,CUI_INLINE_SET_ATTRIBUTE,CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW));
	get_attr = cui_inline_get_item_attributes(inline_id,CUI_INLINE_ITEM_ID_BASE + 4);
	AVK_LOG_FUN(cui_inline_get_item_attributes,(get_attr&0xff) == CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY);

	AVK_LOG_NORMAL(cui_inline_set_screen_attributes(inline_id,CUI_INLINE_SET_ATTRIBUTE,CUI_INLINE_SCREEN_DISABLE_DONE));
	get_scr_attr = cui_inline_get_screen_attributes(inline_id);
	AVK_LOG_FUN(cui_inline_get_screen_attributes, get_scr_attr ==  CUI_INLINE_SCREEN_DISABLE_DONE);

	AVK_LOG_NORMAL(cui_inline_set_parent_data(inline_id, 101));
	get_parent_data = cui_inline_get_parent_data(inline_id);
	AVK_LOG_FUN(cui_inline_get_parent_data, get_parent_data == 101);
#ifdef __MMI_TOUCH_SCREEN__
	AVK_LOG_NORMAL(cui_inline_set_imm_events(inline_id,MMI_FALSE,disable_event_keys_list));
	AVK_LOG_NORMAL(cui_inline_disable_handwriting(inline_id));
#endif

	AVK_LOG_NORMAL(cui_inline_set_input_buffer_allocator(inline_id,NULL,NULL));

	AVK_LOG_MANUAL(cui_inline_set_softkey_text(inline_id, CUI_INLINE_ITEM_ID_BASE + 1, MMI_LEFT_SOFTKEY, AVK_STR_PASS));
	// cui_inline_set_softkey_text(inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_LEFT_SOFTKEY, AVK_STR_PASS);
	cui_inline_set_softkey_text(inline_id, CUI_INLINE_ITEM_ID_BASE + 1, MMI_RIGHT_SOFTKEY, AVK_STR_FAIL);
	cui_inline_set_softkey_text(inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_RIGHT_SOFTKEY, AVK_STR_FAIL);
	cui_inline_set_softkey_text(inline_id, CUI_INLINE_ITEM_ID_BASE + 4, MMI_RIGHT_SOFTKEY, AVK_STR_FAIL);

	display_item.string_id = 0;



	AVK_LOG_NORMAL(cui_inline_set_highlight_item(inline_id,CUI_INLINE_ITEM_ID_BASE + 4));
	 
    AVK_LOG_NORMAL(cui_inline_set_value(
        inline_id,
        CUI_INLINE_ITEM_ID_BASE + 1,
        (void*)&data));

	/*cui_inline_set_value(
        inline_id,
        CUI_INLINE_ITEM_ID_BASE + 3,
        (void*)edit_buff);*/

	 cui_inline_set_value(
        inline_id,
        CUI_INLINE_ITEM_ID_BASE + 4,
        (void*)buffer);

	AVK_LOG_NORMAL(cui_inline_set_softkey_icon(
        inline_id,
        CUI_INLINE_ITEM_ID_BASE + 0,
        MMI_CENTER_SOFTKEY, IMG_GLOBAL_L5));

	AVK_LOG_NORMAL(cui_inline_set_softkey_text(
        inline_id,
        CUI_INLINE_ITEM_ID_BASE + 1,
        MMI_RIGHT_SOFTKEY,
        STR_GLOBAL_BACK));
#if defined(__MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined(__MMI_INLINE_ITEM_MULTILINE_EDIT__)
	AVK_LOG_NORMAL(cui_inline_set_ml_rdly_set_hilite_list(inline_id,CUI_INLINE_ITEM_ID_BASE + 3,&highlight_list));
#endif /* __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__ || __MMI_INLINE_ITEM_MULTILINE_EDIT__ */

	AVK_LOG_NORMAL(cui_inline_set_icon_list(inline_id, (U16*) item_icons));
	AVK_LOG_NORMAL(cui_inline_run(inline_id));

}

mmi_imm_input_mode_enum inp_mode = IMM_INPUT_MODE_NONE;
const wchar_t char_allow[] = L"_\\-.!~*\\\\'()&=+$,;?/%@:A-Za-z0-9";
/*****************************************************************************
 * FUNCTION
 *  vs_fw_pluto_inline_proc_002
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt             [?]         
 *  index(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret vs_fw_pluto_inline_proc_002(mmi_event_struct *evt)
{
 switch (evt->evt_id)
    {

        case EVT_ID_CUI_INLINE_NOTIFY:
			{
			cui_event_inline_notify_struct *inline_evt = (cui_event_inline_notify_struct*)evt;
			    cui_inline_set_default_icon_style(inline_evt->sender_id,(U8*) GetImage(CHECKBOX_ON_IMAGE_ID));
               cui_inline_set_softkey_text(inline_evt->sender_id,inline_evt->item_id,MMI_RIGHT_SOFTKEY,AVK_STR_FAIL);
               cui_inline_set_softkey_text(inline_evt->sender_id,inline_evt->item_id,MMI_LEFT_SOFTKEY,AVK_STR_PASS);


			break;
			}
		case EVT_ID_CUI_INLINE_SUBMIT:
			{
			    cui_event_inline_abort_struct *inline_evt = (cui_event_inline_abort_struct*) evt;
//			  vs_tfw_trace_result(L"vs_fw_pluto_inline_002", MMI_TRUE, 0, VS_TA_FW_CUI_INLINE);
//			  vs_tfw_finish_case_extern(VS_FW_INLINE_CUI_002, SCR_ID_VS_INLINE);
			   
			    cui_inline_lock_main_screen(inline_evt->sender_id);
			    cui_inline_set_softkey_text(inline_evt->sender_id,CUI_INLINE_ITEM_ID_BASE + 3,MMI_RIGHT_SOFTKEY,AVK_STR_FAIL);

			    cui_inline_unlock_main_screen(inline_evt->sender_id);
			    cui_inline_redraw_screen(inline_evt->sender_id);
			    
                cui_inline_close(inline_evt->sender_id);
			    mmi_frm_group_close(AVK_GRP_ID_1);
			    AVK_CASE_RESULT(AVK_PASS);
			    AVK_ASYN_DONE();
			    break;

			}


		case EVT_ID_CUI_INLINE_ABORT:
			{	

			cui_event_inline_abort_struct *inline_evt = (cui_event_inline_abort_struct*) evt;			   
//     			vs_tfw_trace_result(L"vs_fw_pluto_inline_002", MMI_FALSE, 0, VS_TA_FW_CUI_INLINE);
//     			vs_tfw_finish_case_extern(VS_FW_INLINE_CUI_002, SCR_ID_VS_INLINE);
			AVK_CASE_RESULT(AVK_FAIL);   
            cui_inline_close(inline_evt->sender_id);
			mmi_frm_group_close(AVK_GRP_ID_1);
			AVK_ASYN_DONE();
			break;
			}


		case EVT_ID_CUI_INLINE_SET_KEY:
			{
			  cui_event_inline_set_key_struct  *inline_setkey_event = (cui_event_inline_set_key_struct*)evt;
			  if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + 7)
			  {
			     SetLeftSoftkeyFunction(vs_fw_pluto_inline_set_result2,KEY_EVENT_UP);
				 SetCenterSoftkeyFunction(vs_fw_pluto_inline_set_result2,KEY_EVENT_UP);
               
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
 *  vs_fw_pluto_inline_002
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_pluto_inline_002(void)
{

	  /*----------------------------------------------------------------*/
    /* Local Variables                                                                    */
    /*----------------------------------------------------------------*/   
    U8 *storage_str_p[2];
     MMI_ID inline_id = GRP_ID_INVALID;
	 U8 edit_buff[50];
	     MMI_ID_TYPE item_icons[] = 
    {
        IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
        IMG_GLOBAL_L3,
        0
    };
	U16 get_defualt_id,count;	    
	U32 item_id;
	U32 str_id = STR_GLOBAL_USE_TEMPLATE;
	cui_inline_set_item_struct set_item = {0};
    cui_inline_draw_top_info_struct draw_struct;

	  /*----------------------------------------------------------------*/
    /* Code Body                                                                            */
    /*----------------------------------------------------------------*/
	 mmi_wcscpy((WCHAR *)edit_buff ,(WCHAR *)L"Append");
	 storage_str_p[0] = (U8 *)L"Tom";
    storage_str_p[1] =(U8 *)L"Jerry";

    mmi_frm_group_create(GRP_ID_AVK, AVK_GRP_ID_1, vs_fw_pluto_inline_proc_002, NULL);
    mmi_frm_group_enter(AVK_GRP_ID_1,MMI_FRM_NODE_SMART_CLOSE_FLAG);

	inline_id = cui_inline_create(AVK_GRP_ID_1, &vs_fw_pluto_inline_setting_data_002);

	cui_inline_set_softkey_text(inline_id, CUI_INLINE_ITEM_ID_BASE + 1, MMI_LEFT_SOFTKEY, AVK_STR_PASS);
	cui_inline_set_softkey_text(inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_LEFT_SOFTKEY, AVK_STR_PASS);
	cui_inline_set_softkey_text(inline_id, CUI_INLINE_ITEM_ID_BASE + 5, MMI_LEFT_SOFTKEY, AVK_STR_PASS);
	cui_inline_set_softkey_text(inline_id, CUI_INLINE_ITEM_ID_BASE + 7, MMI_LEFT_SOFTKEY, AVK_STR_PASS);
	cui_inline_set_softkey_text(inline_id, CUI_INLINE_ITEM_ID_BASE + 1, MMI_RIGHT_SOFTKEY, AVK_STR_FAIL);
	cui_inline_set_softkey_text(inline_id, CUI_INLINE_ITEM_ID_BASE + 3, MMI_RIGHT_SOFTKEY, AVK_STR_FAIL);
	cui_inline_set_softkey_text(inline_id, CUI_INLINE_ITEM_ID_BASE + 5, MMI_RIGHT_SOFTKEY, AVK_STR_FAIL);
	cui_inline_set_softkey_text(inline_id, CUI_INLINE_ITEM_ID_BASE + 7, MMI_RIGHT_SOFTKEY, AVK_STR_FAIL);

	AVK_LOG_NORMAL(cui_inline_set_item_text_edit_default_text(inline_id,CUI_INLINE_ITEM_ID_BASE + 1,STR_GLOBAL_USE_TEMPLATE));

	AVK_LOG_EX(STR_GLOBAL_USE_TEMPLATE == cui_inline_get_default_text_id(inline_id,CUI_INLINE_ITEM_ID_BASE + 1));
	AVK_LOG_EX(8 == cui_inline_get_instance_item_count(inline_id));

	AVK_LOG_EX(CUI_INLINE_ITEM_ID_BASE + 6 == cui_inline_get_item_id_by_index(inline_id, 6));

#if defined(__MMI_INLINE_ITEM_DATE__)
	AVK_LOG_NORMAL(cui_inline_set_date_boundary(inline_id,CUI_INLINE_ITEM_ID_BASE + 3,2030,1800,12,1));
#endif /* __MMI_INLINE_ITEM_DATE__*/

	AVK_LOG_NORMAL(cui_inline_set_input_method(inline_id,CUI_INLINE_ITEM_ID_BASE + 1,IMM_INPUT_TYPE_NUMERIC,&inp_mode,0));

	AVK_LOG_NORMAL(cui_inline_set_item_select(inline_id,CUI_INLINE_ITEM_ID_BASE + 7,2,(U8 **) storage_str_p,1));

	AVK_LOG_NORMAL(cui_inline_delete_item(inline_id,CUI_INLINE_ITEM_ID_BASE + 7));

	                     
	set_item.item_id = CUI_INLINE_ITEM_ID_BASE + 7;                        
	set_item.item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
	set_item.image_id = 0;                            
	set_item.item_data = NULL ; 

	AVK_LOG_NORMAL(cui_inline_insert_item(inline_id,CUI_INLINE_ITEM_ID_BASE + 6,&set_item));

	AVK_LOG_NORMAL(cui_inline_set_item_select(inline_id,CUI_INLINE_ITEM_ID_BASE + 7,2,(U8 **) storage_str_p,1));

	draw_struct.num_of_info_box_rows = 1;
	draw_struct.is_draw_once = FALSE;
	draw_struct.hide_info_callback = NULL;
	draw_struct.draw_info_callback = NULL;

	AVK_LOG_NORMAL(cui_inline_draw_top_info_box(inline_id,&draw_struct));

	AVK_LOG_NORMAL(cui_inline_set_characters_filter(inline_id,MMI_TRUE,(UI_character_type*)char_allow));

	AVK_LOG_NORMAL(cui_inline_set_fullscreen_edit_title_icon(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + 1,
        0));

	AVK_LOG_NORMAL(cui_inline_multiline_append_string(inline_id,CUI_INLINE_ITEM_ID_BASE + 1,edit_buff));

    AVK_LOG_NORMAL(cui_inline_run(inline_id));

}
