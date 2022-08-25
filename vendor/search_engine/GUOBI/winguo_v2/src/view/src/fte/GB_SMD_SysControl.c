
/*
 *  winguo_smd\src\view\src\fte\GB_SMD_SysControl.c
 *
 *  Copyright (C) , 2012 , company Co.Ltd.
 *  
 *   All right reserved.
 *
 */

#include "MMI_features.h"


#ifdef __MMI_GB_WINGUO_V2__

#undef GB_PACKAGE

/*================================================================
*
* include
*
================================================================*/

/*********************系统外部头文件调用********************/
#include "MMI_include.h"
#include "mmi_rp_app_gb_winguo_def.h"
#include "wgui_inputs.h"
#include "gui_fixed_menus.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "gui_buttons.h"
#include "gui_font_size.h"
#include "wgui_categories_util.h"

//list 图片资源id
#include "mmi_rp_app_phonebook_def.h"
#include "mmi_rp_app_calllog_def.h"

//list data show
#include "Wgui_categories_search.h"

#include "Wgui_fixed_menuitems.h"

//光标闪动有关的
#include "mmi_rp_app_uiframework_def.h"

/*内部头文件*/
#include "GB_WG_Common.h"
#include "GB_SMD_SysControl.h"
#include "GB_SMD_Element.h"
 
/*
 * Global Variable or Function
 */
static GB_U16 g_gb_wg_search_button_id = 0;
static GB_PU8 g_gb_wg_search_button_up_image = GB_NULL;
static GB_PU8 g_gb_wg_search_button_down_image = GB_NULL;
static GB_FuncPtr g_gb_wg_search_button_function = GB_NULL;
//static GB_U8 g_gb_wg_handle_pen_change = 0;

/***************************************************************************** 
* Static Function(静态函数定义区域)
*****************************************************************************/
static GB_U32  _InputBox_Msg_Callback(GB_VOID * input_box_handle, mmi_imc_message_struct_p msg_ptr);
static GB_INT  _Search_List_Get_Item(GB_INT item_index, gui_iconlist_menu_item *menu_data, GB_INT data_size);
static GB_VOID _Draw_Button_Background(void *button);
static GB_VOID _Refresh_Search_List(GB_U16 *pInputBuff);
static GB_VOID _Search_Button_Handler(GB_VOID);
static GB_VOID _InputBox_Change_Callback(GB_VOID);
static GB_BOOL _List_Menu_Pre_Key_Handler(MMI_key_code_type key_code);
static GB_VOID _Set_Text_Coordinates(GB_INT item_index, fixed_icontext_list_menuitem_type * menuitem);
static GB_VOID _Resize_And_Draw(GB_INT virtual_keyboard_h);

/***************************************************************************** 
* External Variable or Function(外部函数或变量调用区域)
*****************************************************************************/
extern GB_U16 *g_p_winguo_request_input_buffer;
extern GB_INT g_gb_wg_item_index ;
extern fixed_icontext_list_menuitem MMI_fixed_icontext_list_menuitem;
extern GB_VOID GB_WG_SMD_Control_show_list_menuitem_ex(void *item, void *common_item_data, S32 x, S32 y);
extern GB_VOID GB_WG_SMD_Highlight_Handler(GB_INT item_index);
extern GB_VOID GB_WG_SMD_Screen_Close();
extern GB_U16 GB_WG_SMD_List_Get_InputStr_Data(GB_U16 *pusInputStr);


/***************************************************************************** 
* Macro Definition(宏定义区域)
*****************************************************************************/


/*================================================================
*
* code
*
================================================================*/


/*
 *   判断输入框是否激活
 *
 */
GB_BOOL GB_WG_SMD_Control_Is_InputBox_Active(GB_VOID)
{
	GB_BOOL result = GB_FALSE;
 
	if (!(MMI_singleline_inputbox.flags & (UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL | UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW)))
	{
		result = GB_TRUE;        
	}

	return result;
}


/*
 *    判断列表是否激活.
 *
 */
GB_BOOL GB_WG_SMD_Control_Is_List_Menu_Active(GB_VOID)
{
	GB_BOOL result = GB_TRUE;

	if (MMI_fixed_icontext_list_menuitem.flags & UI_MENUITEM_DISABLE_HIGHLIGHT)
	{
		return GB_FALSE;        
	}

	return result;
}


/*
 *     激活.输入框，设置flags
 *
 */
GB_VOID GB_WG_SMD_Control_Set_InputBox_Focus_State(GB_BOOL active)
{
	GB_BOOL ret = GB_FALSE;

	if (active == GB_TRUE)
	{
		ret = GB_WG_SMD_Control_Is_InputBox_Active();
		//g_gb_wg_handle_pen_change = 0;
		MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
		MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;

		if (ret == MMI_FALSE)
		{
			wgui_inputs_sl_set_RSK();
		}
		wgui_inputs_sl_register_keys();
	}
	else
	{                
		MMI_singleline_inputbox.flags |= (UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL | UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW);

		ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
		ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
		StopTimer(BLINKING_CURSOR); /* disable cursor */
	}
}

/*
 *     激活列表，设置flags
 *
 */
GB_VOID GB_WG_SMD_Control_Set_List_Menu_Focus_State(GB_BOOL active)
{
	if (active == GB_TRUE)
	{
		MMI_fixed_icontext_list_menuitem.flags &= ~UI_MENUITEM_DISABLE_HIGHLIGHT;
		MMI_fixed_icontext_list_menuitem.ext_flags &= ~UI_MENUITEM_EXT_DISABLED_SCROLL;
		register_asyncdynamic_list_keys();
 		set_right_softkey_label(get_string(STR_GLOBAL_BACK));
		//set_right_softkey_icon(wgui_singleline_inputbox_RSK_label_icon);
		redraw_right_softkey();
		set_right_softkey_function(NULL, KEY_EVENT_DOWN);
		set_right_softkey_function(GB_WG_SMD_Screen_Close, KEY_EVENT_UP);
		set_right_softkey_function(NULL, KEY_LONG_PRESS);
		//wgui_inputs_sl_move_cursor(WGUI_INPUTS_CURSOR_POS_END);
	}
	else
	{
		//MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_DISABLE_HIGHLIGHT;
		MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_DISABLE_HIGHLIGHT;
		MMI_fixed_icontext_list_menuitem.ext_flags |= UI_MENUITEM_EXT_DISABLED_SCROLL;
		MMI_fixed_list_menu.highlighted_item = 0;
		//gui_pop_up_description_stop_scroll();
		gui_fixed_icontext_menuitem_stop_scroll();
	}
}


/*
 *     上下键的handler
 *     切换焦点，重画屏幕
 *
 */
static GB_BOOL _List_Menu_Pre_Key_Handler(MMI_key_code_type key_code)
{

	GB_BOOL result = GB_FALSE; 

	switch (key_code)
	{  
		case KEY_UP_ARROW:
		case KEY_VOL_UP:
			if (GB_WG_SMD_Control_Is_InputBox_Active() == GB_TRUE)
			{
				GB_WG_SMD_Control_Set_InputBox_Focus_State(GB_FALSE);
				GB_WG_SMD_Control_Set_List_Menu_Focus_State(GB_TRUE);
				asyncdynamic_list_goto_item_no_redraw(0);
				redraw_asyncdynamic_list();
				wgui_inputs_sl_redraw();		
				result = MMI_TRUE;
			}
			else if (GB_WG_SMD_Control_Is_List_Menu_Active() == GB_TRUE)
			{
				if (MMI_fixed_list_menu.highlighted_item == 0)
				{
					/* editor do what? */
					GB_WG_SMD_Control_Set_InputBox_Focus_State(MMI_TRUE);
					g_gb_wg_item_index = 0;
					wgui_inputs_sl_redraw();
			
					/* set menu inactive */
					GB_WG_SMD_Control_Set_List_Menu_Focus_State(MMI_FALSE);
					asyncdynamic_list_goto_item_no_redraw(0);
					MMI_fixed_list_menu.highlighted_item = 0;
					wgui_text_menuitem_reset_scrolling(); /* reset menuitem not to scroll */
					redraw_asyncdynamic_list();
					
					result = MMI_TRUE;
				}
			}
			break;
		case KEY_DOWN_ARROW:
		case KEY_VOL_DOWN: 
			if (GB_WG_SMD_Control_Is_InputBox_Active() == GB_TRUE)
			{
				GB_WG_SMD_Control_Set_InputBox_Focus_State(GB_FALSE);
				GB_WG_SMD_Control_Set_List_Menu_Focus_State(GB_TRUE);
				asyncdynamic_list_goto_item_no_redraw(0);
				redraw_asyncdynamic_list();
				wgui_inputs_sl_redraw();
				result = GB_TRUE;
			}
			else if (GB_WG_SMD_Control_Is_List_Menu_Active() == GB_TRUE)
			{
				if (MMI_fixed_list_menu.highlighted_item == MMI_fixed_list_menu.n_items - 1)
				{
					GB_WG_SMD_Control_Set_InputBox_Focus_State(MMI_TRUE);
				    g_gb_wg_item_index = 0;
					wgui_inputs_sl_redraw();
					GB_WG_SMD_Control_Set_List_Menu_Focus_State(MMI_FALSE);                    
					asyncdynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.n_items - 1);
					wgui_text_menuitem_reset_scrolling(); /* reset menuitem not to scroll */
					redraw_asyncdynamic_list();
					MMI_fixed_list_menu.highlighted_item = 0;
					result = MMI_TRUE;		
				}
			}
			break;
		default:
			break; 
	}

	return result;
}



/*
 *    重写 MMI_fixed_list_menu.item_display_function 函数
 *    用于显示
 *
 */
static GB_VOID _Show_List_MenuItem_CallBack(GB_VOID *item, GB_VOID *common_item_data, GB_INT x, GB_INT y)
{
	if (MMI_fixed_list_menu.current_displayed_item == -1)
	{ 
		_Set_Text_Coordinates(MMI_fixed_list_menu.highlighted_item, item);
	}
	else
	{
		_Set_Text_Coordinates(MMI_fixed_list_menu.current_displayed_item, item);
	}
	GB_WG_SMD_Control_show_list_menuitem_ex(item, common_item_data, x, y);
}


/*
 *    创建listview的相关操作
 *
 */
GB_VOID GB_WG_SMD_Control_CreateList(GB_U16 usCount,GB_INT hightItem,GB_PU8 pHisBuff)
{
	GB_INT left_icon_w = 0, left_icon_h = 0;
	GB_PU8 left_icon   = GB_NULL;
	GB_INT list_height = 0;

	left_icon= (GB_PU8) get_image(IMG_ID_PHB_TAB_GROUP);
	//g_gb_wg_handle_pen_change = 0;
	
	wgui_async_list_create_multi_icontext_menu(
		usCount,
		4,
		1,
		_Search_List_Get_Item,
		NULL,
		WGUI_LIST_INVALID_HIGHLIGHT/*hightItem*/,
		MMI_menuitem_height+5,
		0/*WGUI_ASYNC_DYNAMIC_LIST_MENU_TWO_LINE*/,
		0,
		GB_NULL);

	wgui_fixed_list_register_pre_key_handler(_List_Menu_Pre_Key_Handler);

	MMI_fixed_list_menu.flags |= UI_LIST_MENU_ALIGN_TO_TOP;
	MMI_fixed_list_menu.item_display_function = _Show_List_MenuItem_CallBack;
	//MMI_fixed_list_menu.item_pen_function = _ItemPenFunction;
	//MMI_fixed_list_menu.item_get_flag_function = _ItemGetFlagFunction;
	if (left_icon != GB_NULL)
	{
		gui_measure_image(left_icon, &left_icon_w, &left_icon_h);
	}
	
	set_fixed_icontext_list_icon_coordinates(
		0, 
		4,
		0,
		left_icon_w, 
		MMI_ICONTEXT_MENUITEM_HEIGHT);

#ifdef __MMI_FTE_SUPPORT__
	if (wgui_icon_bar_is_created())
	{
		list_height = UI_device_height-MMI_BUTTON_BAR_HEIGHT - GB_WG_LIST_Y - MMI_ICON_BAR_HEIGHT;
	}
	else
#endif /* __MMI_FTE_SUPPORT__ */
	{
		list_height = UI_device_height-MMI_BUTTON_BAR_HEIGHT - GB_WG_LIST_Y;
	}

	wgui_async_list_resize_multi_icontext_menu(MMI_content_width, list_height);
	wgui_async_list_move_multi_icontext_menu(GB_WG_LIST_X, GB_WG_LIST_Y);	
	resize_asyncdynamic_icontext_menuitems_to_list_width();
//	set_asyncdynamic_pop_up_descriptions(hightItem);

}


/*
 *    创建输入框的相关操作
 *
 */
GB_VOID GB_WG_SMD_Control_CreateInputBox(GB_U16 *pusInputBuff,GB_U16 usInputMaxLen,GB_PU8 left_softkey,
										 GB_PU8 right_softkey,GB_U16 inputbox_width,GB_PU8 pHisBuff)
{

	U8 h_flag;
	S32 first_item, last_item;
	S32 no_entries;
	MMI_BOOL is_empty_buffer = MMI_TRUE;
	
	h_flag = set_list_menu_category_history(GB_WG_MMI_CAT_ID, pHisBuff);

	if (h_flag)
	{
		S32 size = sizeof(list_menu_category_history);

		size = (size + 3) / 4;
		size *= 4;
		
		wgui_inputs_sl_setup_ext(
			GB_WG_INPUTBOX_X,
			GB_WG_INPUTBOX_Y,
			inputbox_width,
			GB_WG_INPUTBOX_HEIGHT,
			(GB_PU8)pusInputBuff,
			usInputMaxLen,
			GB_WG_MMI_CAT_ID,
			(UI_string_type)right_softkey,
			NULL,
			IMM_INPUT_TYPE_SENTENCE,
			(U8*) (pHisBuff + size),
			NULL,
			_InputBox_Msg_Callback);

		//first_item = MMI_fixed_list_menu.first_displayed_item;
		//last_item = MMI_fixed_list_menu.last_displayed_item;
	
		//asyncdynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
	
		//MMI_fixed_list_menu.first_displayed_item = first_item;
		//MMI_fixed_list_menu.last_displayed_item = last_item;

		// wgui_inputs_sl_disable_up_down_key_register(MMI_TRUE);
		//wgui_inputs_sl_disable_left_right_key_register(MMI_TRUE);

		if ((pusInputBuff != NULL) && ((pusInputBuff[0] != 0) || (pusInputBuff[1] != 0)))
		{
			is_empty_buffer = MMI_FALSE;
		}
		if (GB_WG_SMD_Control_Is_InputBox_Active() == MMI_TRUE)  /* highlight on editor */
		{
			GB_WG_SMD_Control_Set_InputBox_Focus_State(MMI_TRUE);
			GB_WG_SMD_Control_Set_List_Menu_Focus_State(MMI_FALSE);
			asyncdynamic_list_goto_item_no_redraw(0);
		}
		else /* highlight on menu */
		{
			GB_WG_SMD_Control_Set_InputBox_Focus_State(MMI_FALSE);
			GB_WG_SMD_Control_Set_List_Menu_Focus_State(MMI_TRUE);
		}


		/* when input method changed, we will clear the input buffer, so the highlight item need to reset */
		if ((pusInputBuff != NULL) && (is_empty_buffer == MMI_FALSE) && ((pusInputBuff[0] == 0) && (pusInputBuff[1] == 0)))
		{
			MMI_fixed_list_menu.highlighted_item = 0;
		}
		no_entries = GB_WG_SMD_Control_Get_Input_Data(g_p_winguo_request_input_buffer);
		init_asyncdynamic_item_buffer(no_entries, asyncdynamic_item_buffer.load_func, asyncdynamic_item_buffer.hint_func);
		MMI_fixed_list_menu.n_items = no_entries;
		wgui_async_list_resize_multi_icontext_menu(MMI_fixed_list_menu.width, MMI_fixed_list_menu.height - wgui_inputs_get_current_imui_height(MMI_EDITOR_MULTILINE_INPUT_BOX));
		asyncdynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
		set_list_menu_category_history(GB_WG_MMI_CAT_ID, pHisBuff);

		if(no_entries == 0)  /* when no result, highlight should back to editor */
		{
			GB_WG_SMD_Control_Set_InputBox_Focus_State(MMI_TRUE);
			GB_WG_SMD_Control_Set_List_Menu_Focus_State(MMI_FALSE);
			asyncdynamic_list_goto_item_no_redraw(0);
		}
	}
	else
	{
		//mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_HIDE);
		wgui_inputs_sl_disable_up_down_key_register(GB_TRUE);
		GB_WG_SMD_Control_Set_List_Menu_Focus_State(MMI_FALSE);
		asyncdynamic_list_goto_item_no_redraw(0);

		wgui_inputs_sl_setup_ext(
			GB_WG_INPUTBOX_X,
			GB_WG_INPUTBOX_Y,
			inputbox_width,
			GB_WG_INPUTBOX_HEIGHT,
			(GB_PU8)pusInputBuff,
			usInputMaxLen,
			GB_WG_MMI_CAT_ID,
			(UI_string_type)right_softkey,
			NULL,
			IMM_INPUT_TYPE_SENTENCE,
			NULL,
			0,
			_InputBox_Msg_Callback);

		no_entries = GB_WG_SMD_Control_Get_Input_Data(g_p_winguo_request_input_buffer);
		init_asyncdynamic_item_buffer(no_entries, asyncdynamic_item_buffer.load_func, asyncdynamic_item_buffer.hint_func);
		MMI_fixed_list_menu.n_items = no_entries;
		asyncdynamic_list_goto_item_no_redraw(0);
		MMI_current_input_ext_type |= INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
	
	}
	redraw_asyncdynamic_list();
	singleline_inputbox_input_callback();
}


/*
 *    创建button 的相关操作
 *
 */
#if  defined(__MMI_TOUCH_SCREEN__)
GB_VOID GB_WG_SMD_Control_CreateButton() 
{
	icontext_button *search_bt;

	if (_Search_Button_Handler)
	{
		g_gb_wg_search_button_id = dm_add_button(
			GB_NULL,
			g_gb_wg_search_button_up_image,
			g_gb_wg_search_button_down_image,
			_Draw_Button_Background);
		dm_register_button_functions(g_gb_wg_search_button_id, KEY_EVENT_UP, _Search_Button_Handler);
		search_bt = dm_get_button(g_gb_wg_search_button_id);
		//search_bt->draw_down_fp = _Search_Button_Draw_Down;
		//search_bt->draw_up_fp = _Search_Button_Draw_Up;
		search_bt->flags |= UI_BUTTON_NO_SHIFT_BUTTON;
	}
}
#endif


/*
 *    GB_WG_SMD_Control_Set_Search_Button
 *
 */
#if defined(__MMI_TOUCH_SCREEN__)
GB_VOID GB_WG_SMD_Control_Set_Search_Button(GB_PU8 up_image, GB_PU8 down_image, GB_FuncPtr search_function)
{
	g_gb_wg_search_button_up_image   = up_image;
	g_gb_wg_search_button_down_image = down_image;
	g_gb_wg_search_button_function   = search_function;
}
#endif


/*
 *    button handler
 *
 */
static GB_VOID _Search_Button_Handler(GB_VOID)
{
	if (g_gb_wg_search_button_function != NULL)
	{
		g_gb_wg_search_button_function();
	}
}


/*
 *    _Draw_Button_Background
 *
 */
static GB_VOID _Draw_Button_Background(void *button)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	icontext_button *b = (icontext_button*) button;
	S32 x1 = b->x;
	S32 y1 = b->y;
	S32 x2 = b->x + b->width - 1;
	S32 y2 = b->y + b->height - 1;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	gdi_layer_lock_frame_buffer(); 

	/* draw the background */  
	//gui_draw_filled_area(x1, y1, x2 + 1, y2 + 1, (current_MMI_theme->singleline_editor_bg_filler));
	wgui_category_clear_region_with_transparent_color(x1, y1, x2 + 1, y2 + 1);

	gdi_layer_unlock_frame_buffer();
}


/*
 *   _Refresh_Search_List call this
 *
 */
static GB_VOID _Refresh_Search_List_Change_List(GB_INT no_entries, GB_INT highlighted_item)
{
	GB_INT     max_entries = 0;
	GB_BOOL    showOption;

	MMI_fixed_list_menu.highlighted_item = highlighted_item;
	MMI_fixed_list_menu.n_items = no_entries;
	MMI_fixed_list_menu.displayed_items = no_entries;

	set_menu_item_count(no_entries);

	showOption = no_entries > 0 ? GB_TRUE : GB_FALSE;

	if (showOption)
	{
		if (no_entries == 0)
		{
			gui_fixed_icontext_list_menuitem_stop_scroll();
			//gui_pop_up_description_stop_scroll();
		}
		init_asyncdynamic_item_buffer(no_entries, asyncdynamic_item_buffer.load_func, asyncdynamic_item_buffer.hint_func);
		MMI_fixed_list_menu.n_items = no_entries;
		asyncdynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
	}
	else
	{
		gui_fixed_icontext_list_menuitem_stop_scroll();
		//gui_pop_up_description_stop_scroll();
		//wgui_current_pop_up_description_index = -1;
	}

	draw_title();

	wgui_async_list_show_multi_icontext_menu();

}


/*
 *   刷新listview，比如输入框数据改变，虚拟键盘显示
 *
 */
static GB_VOID _Refresh_Search_List(GB_U16 *pInputBuff)
{
	_Refresh_Search_List_Change_List(GB_WG_SMD_Control_Get_Input_Data(pInputBuff), 0);
}


/*
 *     输入值改变callback
 *
 */
static GB_BOOL _InputBox_Change_Event_Callback(gui_multi_line_input_box_change_event_enum event, GB_U16 inputBuff)
{
	GB_BOOL result = GB_TRUE;
	GB_INT input_used = mmi_wcslen(g_p_winguo_request_input_buffer);

	switch (event)
	{
		case GUI_MULTI_LINE_INPUT_BOX_INSERT_CHAR:
			if (input_used + wgui_inputs_ucs2_to_gb_len(inputBuff) > (GB_WG_SEARCH_WEB_MAX_INPUT_LEN - 1))
			{
				result = GB_FALSE;
			}
			else
			{
				input_used += wgui_inputs_ucs2_to_gb_len(inputBuff);
			}
			break;
		case GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR:
			input_used -= wgui_inputs_ucs2_to_gb_len(inputBuff);
			break;
		case GUI_MULTI_LINE_INPUT_BOX_DELETEALL:
			input_used = 0;
			break;
		case GUI_MULTI_LINE_INPUT_BOX_INSERT_STRING:
			if ((input_used + inputBuff) > (GB_WG_SEARCH_WEB_MAX_INPUT_LEN - 1))
			{
				result = GB_FALSE;
			}
		default:break;
	}

	if (result == GB_FALSE)
	{
		UI_editor_play_tone_cannot_insert();
	}

	return result;
}


/*
 *    注册 输入值改变callback
 *
 */
GB_VOID GB_WG_SMD_Control_Register_InputBox_Event_Callback(GB_VOID)
{
	wgui_inputs_sl_register_change_event_handler(_InputBox_Change_Event_Callback);
}


/*
 *    获取数据
 *
 */
GB_U16 GB_WG_SMD_Control_Get_Input_Data(GB_U16 *pusInputStr)
{
	GB_U16 usCount = 0;
	GB_U16 usStrLen = 0;
	GB_INT ret = 0;

	if (pusInputStr == GB_NULL)
	{
		return 0;
	}

// 	//USB模式下直接返回
// 	if (GB_WG_Get_Phone_Mode() == e_GB_WG_PHONE_MODE_USB)
// 	{
// 		return 0;
// 	}

	//飞行模式以及无效SIM卡的时候可以搜本地应用等	
// 	else if (GB_WG_Get_Phone_Mode() == e_GB_WG_PHONE_MODE_FLIGHT
// 		|| GB_WG_Get_Phone_Mode() == e_GB_WG_PHONE_MODE_NOSIM)
// 	{
// 		GB_WG_SetSearchFlag(GB_WG_GetSearchFlag() & 
// 			~(EmumToFlag(GBMD_CachType_App)|EmumToFlag(GBMD_CachType_WinguoFunction)|EmumToFlag(GBMD_CachType_Encrypt)));
// 	}

	usCount = GB_WG_SMD_List_Get_InputStr_Data(pusInputStr);

	return usCount;
}




/*
 *    输入框callback
 *
 */
static GB_U32 _InputBox_Msg_Callback(GB_VOID * input_box_handle, mmi_imc_message_struct_p msg_ptr)
{
	GB_U32                      lresult = 0;
	GB_BOOL                     need_default_handle = GB_TRUE;
	single_line_input_box      *editor_ptr;
	GB_BOOL                     ret = GB_FALSE;

#if defined(__MMI_TOUCH_SCREEN__)
	gui_single_line_input_box_pen_enum single_line_input_box_event;
#endif

	editor_ptr = (single_line_input_box *)((mmi_editor_handler_struct *)input_box_handle)->input_box_handler;

	if (editor_ptr == &MMI_singleline_inputbox)
	{
		switch (msg_ptr->message_id)
		{
		
#if defined(__MMI_CLIPBOARD__)
			case MMI_IMC_MESSAGE_CLIPBOARD_SAVE_STATUS:
				wgui_async_list_show_multi_icontext_menu();      
				need_default_handle = GB_TRUE;
				break;

			case MMI_IMC_MESSAGE_CLIPBOARD_RESTORE_STATUS:
				wgui_async_list_show_multi_icontext_menu();
				need_default_handle = GB_TRUE;
				break;
#endif
			case MMI_IMC_MESSAGE_RESIZE:

				if (msg_ptr->param_1 > UI_device_height*2/3)
				{
					_Resize_And_Draw(MMI_content_y+MMI_content_height-(editor_ptr->y+(GB_INT)msg_ptr->param_1));
				}
				else
				{
					_Resize_And_Draw(MMI_content_y+MMI_content_height-(editor_ptr->y+(GB_INT)msg_ptr->param_1-MMI_MENUITEM_HEIGHT));
				}
				need_default_handle = GB_FALSE;
				break;

			case MMI_IMC_MESSAGE_REDRAW:
				if (msg_ptr->param_0 == 1)
				{
					dm_imui_window_hide();
				}
				else
				{
					GB_WG_SMD_Control_Resize_And_DrawEx();
				}
				need_default_handle = GB_FALSE;
				break;

			case MMI_IMC_MESSAGE_SET_KEY:

				wgui_inputs_sl_set_RSK();
				wgui_inputs_sl_register_keys();
				if (GB_WG_SMD_Control_Is_InputBox_Active() == MMI_FALSE)
 				{
					GB_WG_SMD_Control_Set_InputBox_Focus_State(MMI_FALSE);
					GB_WG_SMD_Control_Set_List_Menu_Focus_State(MMI_TRUE);  
				}
				register_fixed_list_highlight_handler(asyncdynamic_list_highlight_handler);
				register_asyncdynamic_list_keys();
				need_default_handle = GB_FALSE;
				break;

			case MMI_IMC_MESSAGE_PEN_EVENT:
#if defined(__MMI_TOUCH_SCREEN__)
				ret = (MMI_BOOL)gui_single_line_input_box_translate_pen_event(
					editor_ptr,
					((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event,
					((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x,
					((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y,
					&single_line_input_box_event);

				if (ret)
				{ 
					if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_UP)
					{
						if (GB_WG_SMD_Control_Is_InputBox_Active() == MMI_TRUE) 
						{
							wgui_text_menuitem_reset_scrolling(); /* reset menuitem not to scroll */
							redraw_asyncdynamic_list();
						}
					}
					else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_LONG_TAP ||
						((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_DOWN)
					{
						if (GB_WG_SMD_Control_Is_InputBox_Active() == MMI_FALSE)
						{
							GB_WG_SMD_Control_Set_InputBox_Focus_State(GB_TRUE);
							GB_WG_SMD_Control_Set_List_Menu_Focus_State(GB_FALSE);  
							asyncdynamic_list_goto_item(0);
						}
					}					
				}		
				need_default_handle = GB_TRUE;
	
#endif
				break;

			default:
				break;
		}

		if (need_default_handle)
		{
			lresult = mmi_input_box_msg_call_back_singleline(input_box_handle, msg_ptr);
		}
	}

	return lresult;

}


/*
 *    输入框Change callback
 *
 */
static GB_VOID _InputBox_Change_Callback(GB_VOID)
{
	gdi_layer_lock_frame_buffer();
	//MMI_fixed_list_menu.last_displayed_item -= MMI_fixed_list_menu.first_displayed_item;
	//	MMI_fixed_list_menu.first_displayed_item = 0;
	_Refresh_Search_List(g_p_winguo_request_input_buffer);

	if (MMI_fixed_list_menu.n_items <= 0 && gb_wg_wcslen(g_p_winguo_request_input_buffer) > 0)
	{
		if (!GBCand_IsActive())
		{
			GB_WG_SMD_Highlight_Handler(-1);
		}
	}

	GB_WG_SMD_Control_Set_InputBox_Focus_State(MMI_TRUE);
	wgui_inputs_sl_handle_input();
	wgui_inputs_sl_redraw();

	/* set menu inactive */
	GB_WG_SMD_Control_Set_List_Menu_Focus_State(MMI_FALSE);    
	asyncdynamic_list_goto_item_no_redraw(0);
	MMI_fixed_list_menu.highlighted_item = 0;
	
	wgui_text_menuitem_reset_scrolling(); /* reset menuitem not to scroll */
	redraw_asyncdynamic_list();

	gdi_layer_unlock_frame_buffer();
	gdi_lcd_repaint_all();
}

/*
 *    注册输入框Change callback
 *
 */
GB_VOID GB_WG_SMD_Control_Register_InputBox_Change_Callback(GB_VOID)
{
	register_singleline_inputbox_input_callback(_InputBox_Change_Callback);
}


/*
 *    listview获取数据，高亮显示
 *
 */
static GB_INT _Search_List_Get_Item(GB_INT item_index, gui_iconlist_menu_item *menu_data, GB_INT data_size)
{
	GB_U16               i;
	GB_SMD_ElementShowInfoStr pShowInfo ={0};
	
	for (i = 0; i < data_size; i++)
	{
		GB_SMD_GetCachShowDataByIndex(i+item_index, &pShowInfo);

		if (pShowInfo.subject.InfoString[0] == '\0')
		{
			gb_wg_wcscpy(pShowInfo.subject.InfoString, (GB_WCHAR*)get_string(STR_GB_WINGUO_UNNAMED));
		}

		if (pShowInfo.explain.InfoString[0] == '\0')
		{
			gb_wg_wcscpy(pShowInfo.explain.InfoString, (GB_WCHAR*)get_string(STR_GB_WINGUO_NO_NUMBER));
		}
		 
		if ((pShowInfo.subject.nHighlightLen > 0 && pShowInfo.subject.nHighlightLen < 50)||(pShowInfo.explain.nHighlightLen > 0 && pShowInfo.explain.nHighlightLen < 50))
		{	
			if(pShowInfo.subject.pHighlightStart)//高亮在上面
			{
 				mmi_ucs2ncpy((GB_CHAR*) menu_data[i].item_list[0], (GB_CHAR*) pShowInfo.subject.InfoString, pShowInfo.subject.point);
 				mmi_ucs2ncpy((GB_CHAR*) menu_data[i].item_list[1], (GB_CHAR*) pShowInfo.subject.pHighlightStart, pShowInfo.subject.nHighlightLen);
				mmi_ucs2cpy((GB_CHAR*) menu_data[i].item_list[2], (GB_CHAR*)(pShowInfo.subject.pHighlightStart +pShowInfo.subject.nHighlightLen));
			  	mmi_ucs2cpy((GB_CHAR*) menu_data[i].item_list[3], (GB_CHAR*) pShowInfo.explain.InfoString);
			}
			else//高亮在下面
			{
			    	mmi_ucs2cpy((GB_CHAR*) menu_data[i].item_list[0], (GB_CHAR*) pShowInfo.subject.InfoString);
				mmi_ucs2ncpy((GB_CHAR*) menu_data[i].item_list[1], (GB_CHAR*) pShowInfo.explain.InfoString, pShowInfo.explain.point);
 				mmi_ucs2ncpy((GB_CHAR*) menu_data[i].item_list[2], (GB_CHAR*) pShowInfo.explain.pHighlightStart, pShowInfo.explain.nHighlightLen);
				mmi_ucs2cpy((GB_CHAR*) menu_data[i].item_list[3], (GB_CHAR*)(pShowInfo.explain.pHighlightStart +pShowInfo.explain.nHighlightLen));		
			}
		}
		else //不高亮
		{
				mmi_ucs2cpy((GB_CHAR*) menu_data[i].item_list[0], (GB_CHAR*) pShowInfo.subject.InfoString);
				mmi_ucs2cpy((GB_CHAR*) menu_data[i].item_list[1], NULL);
				mmi_ucs2cpy((GB_CHAR*) menu_data[i].item_list[2], NULL);
				mmi_ucs2cpy((GB_CHAR*) menu_data[i].item_list[3], (GB_CHAR*) pShowInfo.explain.InfoString);
		}

		menu_data[i].image_list[0] = (GB_PU8) pShowInfo.pimg;
		
	}

	return data_size;
}


/*
 *    设置文本显示位置
 *
 */
static GB_VOID _Set_Text_Coordinates(GB_INT item_index, fixed_icontext_list_menuitem_type * menuitem)
{
	GB_INT left_icon_w = 0, left_icon_h = 0;
	GB_PU8 left_icon   = GB_NULL;
	GB_INT sec_fh, fir_fh,var;
	GB_U32 width1 = 0, height;
	GB_U32 width2 = 0, breadth_max = 0;
	GB_INT i=0;
	GB_SMD_ElementShowInfoStr pShowInfo ={0};
	
	gui_set_fixed_icontext_list_menuitem_current_theme(&MMI_fixed_icontext_list_menuitem);

	left_icon= (GB_PU8) get_image(IMG_WG_SMARTDAIL_CALL_IN);
	
	if (left_icon != GB_NULL)
 	{
 		gui_measure_image(left_icon, &left_icon_w, &left_icon_h);
  	}

	fir_fh = Get_CharHeightOfAllLang(gui_font_get_type(GUI_FONT_SIZE_LIST)->size);
	sec_fh = Get_CharHeightOfAllLang(SMALL_FONT);
	var = (MMI_menuitem_height + 5 - fir_fh - sec_fh)>>1;
	breadth_max = UI_device_width - (4 + 8 +2*left_icon_w);
    
	GB_SMD_GetCachShowDataByIndex(item_index, &pShowInfo);
	
	if ((pShowInfo.subject.nHighlightLen > 0 && pShowInfo.subject.nHighlightLen < 50)||(pShowInfo.explain.nHighlightLen > 0 && pShowInfo.explain.nHighlightLen < 50))
	{	
			if(pShowInfo.subject.pHighlightStart)
			{
				MMI_fixed_icontext_list_menuitem.text_fonts[0] = &MMI_medium_font;
				MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_medium_font;
				MMI_fixed_icontext_list_menuitem.text_fonts[2] = &MMI_medium_font;
				MMI_fixed_icontext_list_menuitem.text_fonts[3] = &MMI_small_font;
				MMI_fixed_icontext_list_menuitem.normal_text_colors[1]  = gui_color(255,0,0);
 				MMI_fixed_icontext_list_menuitem.focussed_text_colors[1] = gui_color(255,0,0);
				gui_set_font(&MMI_medium_font);
				gui_measure_string((GB_U16*) menuitem->item_texts[0], &width1, &height);
				gui_measure_string((GB_U16*) menuitem->item_texts[1], &width2, &height);
 
				if(width1 >breadth_max)
				{
					width1 = breadth_max;
				}
				if(width1+width2 > breadth_max)
				{
					width2 = breadth_max - width1;
				}
                                                
				set_fixed_icontext_list_text_coordinates(3, 4+left_icon_w+8, var + fir_fh + 2, 
					breadth_max, 
					sec_fh);
				set_fixed_icontext_list_text_coordinates(0, 4+left_icon_w+8, var, 
					width1, fir_fh);
				set_fixed_icontext_list_text_coordinates(1, 4+left_icon_w+8+width1, var, 
					width2, fir_fh);
				set_fixed_icontext_list_text_coordinates(2, 4+left_icon_w+8+width1+width2, var, 
					breadth_max - width1 - width2, fir_fh);			
			}
			else
			{
				MMI_fixed_icontext_list_menuitem.text_fonts[0] = &MMI_medium_font;
				MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_small_font;
				MMI_fixed_icontext_list_menuitem.text_fonts[2] = &MMI_small_font;
				MMI_fixed_icontext_list_menuitem.text_fonts[3] = &MMI_small_font;
				MMI_fixed_icontext_list_menuitem.normal_text_colors[2]  = gui_color(255,0,0);
 				MMI_fixed_icontext_list_menuitem.focussed_text_colors[2] = gui_color(255,0,0);
				gui_set_font(&MMI_small_font);
				gui_measure_string((GB_U16*) menuitem->item_texts[1], &width1, &height);
				gui_measure_string((GB_U16*) menuitem->item_texts[2], &width2, &height);\

                            if(width1 >breadth_max)
				{
					width1 = breadth_max;
				}
				if(width1+width2 > breadth_max)
				{
					width2 = breadth_max - width1;
				}
                            
				set_fixed_icontext_list_text_coordinates(0, 4+left_icon_w+8, var, 
					breadth_max, 
					fir_fh);
				set_fixed_icontext_list_text_coordinates(1, 4+left_icon_w+8, var + fir_fh + 2, 
					width1, sec_fh);
				set_fixed_icontext_list_text_coordinates(2, 4+left_icon_w+8+width1, var + fir_fh + 2, 
					width2, sec_fh);
				set_fixed_icontext_list_text_coordinates(3, 4+left_icon_w+8+width1+width2, var + fir_fh + 2, 
					breadth_max - width1 - width2, sec_fh);						
			}
	}
	else
	{
				MMI_fixed_icontext_list_menuitem.text_fonts[0] = &MMI_medium_font;
				MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_medium_font;
				MMI_fixed_icontext_list_menuitem.text_fonts[2] = &MMI_medium_font;
				MMI_fixed_icontext_list_menuitem.text_fonts[3] = &MMI_small_font;
				MMI_fixed_icontext_list_menuitem.normal_text_colors[1]  = gui_color(255,0,0);
		 		MMI_fixed_icontext_list_menuitem.focussed_text_colors[1] = gui_color(255,0,0);
				gui_set_font(&MMI_medium_font);
				gui_measure_string((GB_U16*) menuitem->item_texts[0], &width1, &height);
				width2 = 0;
				set_fixed_icontext_list_text_coordinates(3, 4+left_icon_w+8, var + fir_fh + 2, 
					breadth_max, 
					sec_fh);
				set_fixed_icontext_list_text_coordinates(0, 4+left_icon_w+8, var, 
					width1, fir_fh);
				set_fixed_icontext_list_text_coordinates(1, 4+left_icon_w+8+width1, var, 
					width2, fir_fh);			
				set_fixed_icontext_list_text_coordinates(2, 4+left_icon_w+8+width1+width2, var, 
					breadth_max - width1 - width2, fir_fh);
	}
}

 
/*
 *    重画屏幕
 *
 */
static GB_VOID _Resize_And_Draw(GB_INT virtual_keyboard_h)
{
	GB_INT first_item, last_item;
	GB_INT list_height = 0;
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
	extern S32 gblock_list_effect;
	S32 temp;
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
	temp = gblock_list_effect;
	gblock_list_effect = 1;
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 
#ifdef __MMI_FTE_SUPPORT__
	if (wgui_icon_bar_is_created())
	{
		list_height = UI_device_height-MMI_BUTTON_BAR_HEIGHT - GB_WG_LIST_Y - MMI_ICON_BAR_HEIGHT;
	}
	else
#endif /* __MMI_FTE_SUPPORT__ */
	{
		list_height = UI_device_height-MMI_BUTTON_BAR_HEIGHT - GB_WG_LIST_Y;
	}

	if (virtual_keyboard_h > 50)
	{
		//resize_fixed_list(MMI_fixed_list_menu.width, UI_device_height-virtual_keyboard_h - GB_WG_LIST_Y);
		wgui_async_list_resize_multi_icontext_menu(MMI_fixed_list_menu.width, UI_device_height-virtual_keyboard_h - GB_WG_LIST_Y);
	}
	else
	{
		//resize_fixed_list(MMI_fixed_list_menu.width,list_height);
		wgui_async_list_resize_multi_icontext_menu(MMI_fixed_list_menu.width,list_height);
	}

 	if (MMI_fixed_list_menu.n_items > 0)
 	{
 		gui_asyncdynamic_list_menu_locate_highlighted_item(&MMI_fixed_list_menu);
 	}	

	first_item = MMI_fixed_list_menu.first_displayed_item;
	last_item = MMI_fixed_list_menu.last_displayed_item;

	asyncdynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);

     MMI_fixed_list_menu.first_displayed_item = first_item;
	MMI_fixed_list_menu.last_displayed_item = last_item;
    //show_asyncdynamic_list();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
	gblock_list_effect = temp;
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 
}


/*
 *    重画屏幕
 *
 */
GB_VOID GB_WG_SMD_Control_Resize_And_DrawEx()
{
	icontext_button      *search_bt;
	GB_INT                bt_w;
	GB_INT                bt_h;
	gdi_handle            active_layer;
    #ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    extern S32 gblock_list_effect;
    S32 temp;
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 

	gdi_layer_lock_frame_buffer();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    temp = gblock_list_effect;
    gblock_list_effect = 1;
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 

	wgui_async_list_show_multi_icontext_menu();

	wgui_inputs_sl_move(GB_WG_INPUTBOX_X, GB_WG_INPUTBOX_Y); 

	search_bt = dm_get_button(g_gb_wg_search_button_id);
	gdi_image_get_dimension(g_gb_wg_search_button_up_image, &bt_w, &bt_h);
	if ((bt_w > 0) && (bt_h > 0))
	{
// 		gui_move_icontext_button(
// 			search_bt, 
// 			GB_WG_SEARCHBUTTON_x+12,
// 			MMI_singleline_inputbox.y + (((MMI_SINGLELINE_INPUTBOX_HEIGHT) - (bt_h)) >> 1));
// 		gui_resize_icontext_button(search_bt, bt_w, bt_h);
// 		gui_icontext_button_overwirte_pen_response_area(
// 			search_bt,
// 			search_bt->x,
// 			search_bt->y,
// 			search_bt->x + search_bt->width,
// 			search_bt->y + search_bt->height);
// 
// 		/* show search button */
// 		gdi_layer_get_active(&active_layer);
// 		gdi_push_and_set_alpha_blending_source_layer(active_layer);
		gui_show_icontext_button(search_bt);
/*		gdi_pop_and_restore_alpha_blending_source_layer();*/

		/* show the singleline inputbox */
		wgui_inputs_sl_resize(
			GB_WG_INPUTBOX_WIDTH,
			GB_WG_INPUTBOX_HEIGHT);
		wgui_inputs_sl_show();
	}
	else 
	{
		wgui_inputs_sl_show();
	}
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gblock_list_effect = temp;
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 

	gdi_layer_unlock_frame_buffer();
	gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

}



/*
 *    call by _Screen_ReleaseEx
 *
 */
GB_VOID GB_WG_SMD_Control_Release(GB_VOID)
{
	reset_fixed_list();
	wgui_inputs_sl_close();

	g_gb_wg_search_button_id = 0;
	g_gb_wg_search_button_up_image = GB_NULL;
	g_gb_wg_search_button_down_image = GB_NULL;
	g_gb_wg_search_button_function = GB_NULL;

	reset_asyncdynamic_list();
	//reset_pop_up_descriptions();
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    reset_all_force_flags_for_hints();
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_inputs_cache_switch(0);
#endif

}


/*
 *    GB_WG_SetInputCandString
 *
 */
GB_VOID GB_WG_SetInputCandString(GB_WCHAR *pCnadstring)
{	
	refresh_search_list_change_list_ext(GB_WG_SMD_Control_Get_Input_Data(pCnadstring), 0);
}

#endif /*#ifdef __MMI_GB_WINGUO_V2__*/
