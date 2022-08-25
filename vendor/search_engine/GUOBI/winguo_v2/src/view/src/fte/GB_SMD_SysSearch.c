/*
 *  winguo_smd\src\view\src\fte\GB_SMD_SysSearch.c
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
#include "Browser_api.h"
#include "mmi_frm_app_launcher_gprot.h"
#include "mmi_rp_app_gb_winguo_def.h"
#include "gui_fixed_menuitems.h"

/*短信以及拨号相关的*/
#include "MessagesResourceData.h"
#include "MessagesExDcl.h"
#include "MessagesMiscell.h"
#include "GlobalDefs.h"
#include "mms_api.h"
#include "SmsAppGprot.h"
#include "UcmGProt.h"

/*保存联系人相关的*/
#include "phbcuigprot.h"

/*设置左右按键的函数*/
#include "wgui_categories_util.h"

/*按钮组合相关的*/
#include "PhoneBookProt.h"

/*调用输入法的*/
#include "gb_wrapper.h"

/*
 *   内部头文件调用
 */
 
#include "GB_WG_Common.h"
#include "GB_SMD_SysControl.h"
#include "GB_SMD_SysSearch.h"
#include "GB_SMD_Element.h"
#include "GB_SMD_ElementPhoneNum.h"
#include "GB_SMD_ElementApp.h"

/*
 * Global Variable 
 */
 
GB_U16 *g_p_winguo_request_input_buffer = GB_NULL;
GB_INT g_gb_wg_item_index = 0;
GB_U16 g_gb_wg_key_code = KEY_INVALID;
GB_PU8 *tempArry = GB_NULL;
GB_UINT nPointCount;

/***************************************************************************** 
* Static Function(静态函数定义区域)
*****************************************************************************/
static GB_INT  _winguo_launch_proc(mmi_event_struct *evt);
static GB_INT  _Screen_Launch(GB_VOID);
static GB_VOID _Screen_Release();
static GB_VOID _Input_Buff_Init(GB_VOID);
static GB_VOID _Screen_Entry(GB_VOID);
static GB_VOID _Screen_Exit(GB_VOID);
static GB_VOID _Create_Menu_Option(GB_VOID);
static GB_INT  _Screen_Launch_Proc(mmi_event_struct *evt);
static GB_INT  _Create_Menu_Option_Proc(mmi_event_struct *evt);
static GB_VOID _List_Menu_Send_MMS();
static GB_VOID _List_Menu_Send_SMS();
static GB_VOID _List_Menu_Call_Num();
static GB_VOID _List_Menu_Save_Contact();
static GB_VOID _Screen_Draw_Background(GB_INT x1, GB_INT y1, GB_INT x2, GB_INT y2);
static GB_VOID _Show_Screen(GB_PU8 title, GB_PU8 title_icon, GB_PU8 left_softkey, GB_PU8 right_softkey, GB_PU8 his_buff);
static GB_VOID _Screen_ReleaseEx();
static GB_PU8  _Get_History(GB_PU8 history_buffer);
static GB_INT  _Get_History_Size(GB_VOID);
static GB_VOID _Select_List_Item_Callback(mmi_tap_type_enum tap_type, GB_INT index);
static GB_VOID _Select_List_Item_Run(GB_INT index);
static GB_VOID _Select_List_Item_RunEx(GB_VOID);
static GB_INT  _List_Menu_Get_Data(GB_U16 *pCachType, GB_U16 *store_index, GB_U16 *pBuff, GB_U16 nBuffLen);

#ifdef __MMI_ICON_BAR_SUPPORT__
static GB_VOID _SubMenu_List_Callback(GB_INT index);
#endif
static GB_VOID _Ok_App(GB_VOID);
static GB_VOID _List_Menu_Number_Action(mmi_phb_op_action_enum action_op,GB_U16 store_index);
static GB_INT  _Non_Qwerty_Key_Proc(mmi_event_struct *evt);
static GB_VOID _Edit_Phb_Entry(GB_U16 store_index);

#ifdef __MMI_TOUCH_SCREEN__
mmi_pen_hdlr g_gb_original_pen_down_handler = NULL;
#endif /* __MMI_TOUCH_SCREEN__ */

/*
 * External Variable or Function
 */
extern fixed_icontext_list_menuitem MMI_fixed_icontext_list_menuitem;
extern GB_VOID mmi_gb_winguo_app_memory();
extern GB_VOID mmi_gb_winguo_app_free();
extern GB_VOID GB_WG_SeachString(GB_U16 *pString);

GB_VOID GB_WG_SMD_Screen_Close(GB_VOID);
GB_VOID GB_WG_SMD_Search_Button_Request(GB_VOID);
GB_VOID GB_WG_SMD_Highlight_Handler(GB_INT item_index);


/***************************************************************************** 
* Macro Definition(宏定义区域)
*****************************************************************************/
#define gb_wg_add_title_and_softkey(title, title_icon, left_softkey, right_softkey) \
	ShowListCategoryScreen_ext((UI_string_type)title, (GB_PU8)title_icon, (UI_string_type)left_softkey, (UI_string_type)right_softkey)

/*================================================================
*
* code
*
================================================================*/

/*
 *   进入winguo的入口
 *
 */
GB_VOID GB_WG_SMD_Search_Screen_Launch(GB_VOID* args, GB_U32 argSize)
{       
       GB_PU8* pPointData = (GB_PU8*)args;
	GB_UINT nPointCount = (GB_UINT)argSize;
	
	if (pPointData && nPointCount)
	{
		tempArry = (GB_PU8*)OslMalloc(nPointCount * sizeof(*pPointData));
		if (tempArry)
		{
			GB_MEMCPY(tempArry, pPointData, nPointCount * sizeof(*pPointData));
		}
		else
		{
			OslMfree(tempArry);
			tempArry = GB_NULL;
		}
	        mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_ENLARGE);
	}
	else
	{
	        mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_HIDE);	
	}
	g_gb_wg_key_code = KEY_INVALID;
	mmi_frm_app_launch(APP_GB_WINGUO, 0, 0, _winguo_launch_proc, NULL, MMI_FRM_APP_NORMAL_LAUNCH);
}

/*
 *   idle 界面按键进入winguo的接口
 *
 */
GB_VOID GB_WG_SMD_Search_Screen_Launch_By_Key(GB_U16 key_code,GB_U16 key_type)
{
	g_gb_wg_key_code = key_code;
	mmi_frm_app_launch(APP_GB_WINGUO, 0, 0, _winguo_launch_proc, NULL, MMI_FRM_APP_NORMAL_LAUNCH);
}

/*
 *  mmi_frm_app_launch(APP_GB_WINGUO, 0, 0, _winguo_launch_proc, NULL, MMI_FRM_APP_NORMAL_LAUNCH);
 *  进入应用事件处理
 *
 */
static GB_INT _winguo_launch_proc(mmi_event_struct *evt)
{
	//GB_INT app_id =	GET_APP_ID(evt);

	switch (evt->evt_id)
	{
		case EVT_ID_APP_ENTER:
			{
				mmi_event_struct event;
				MMI_FRM_INIT_EVENT(&event, 0);
				MMI_FRM_POST_EVENT(&event, _Screen_Launch, NULL);
				break;
			}

		case EVT_ID_APP_TOP_ACTIVE:
			{
				break;
			}

		case EVT_ID_APP_TOP_INACTIVE:

			break;

		case EVT_ID_APP_DEINIT:
			mmi_gb_winguo_app_free();
			break;
	}

	return MMI_RET_OK;

}

/*
 *  创建winguo的屏幕
 *
 */
static GB_INT _Screen_Launch(GB_VOID)
{
	if (mmi_frm_group_is_present(GRP_GB_WINGUO_SCREEN))
	{
		mmi_popup_display(
			get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
			MMI_EVENT_FAILURE,
			NULL);
		return GRP_ID_INVALID;
	}

	//给整个app先申请到内存
	mmi_gb_winguo_app_memory();

	//初始化输入值
	_Input_Buff_Init();

	//创建winguo的group
	mmi_frm_group_create(APP_GB_WINGUO, GRP_GB_WINGUO_SCREEN, _Screen_Launch_Proc,NULL);
	mmi_frm_group_enter(GRP_GB_WINGUO_SCREEN, MMI_FRM_NODE_SMART_CLOSE_FLAG);

	//初始化smd引擎数据
	GB_SMD_Init();

	mmi_frm_scrn_first_enter(
		GRP_GB_WINGUO_SCREEN,
		SCR_GB_WINGUO_SCREEN,
		(FuncPtr)_Screen_Entry,
		NULL);
	if (tempArry)
	{
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)&& !defined(__NO_HANDWRITING__)
#ifdef __MMI_TOUCH_SCREEN__
		GB_WG_show_handwriting_by_point_data((mmi_pen_point_struct*)tempArry, nPointCount);
		SetKeyHandler(GB_WG_SMD_Search_Button_Request, KEY_ENTER, KEY_EVENT_UP);
#endif
#endif
		OslMfree(tempArry);
		tempArry = GB_NULL;
	}
    
	return GRP_GB_WINGUO_SCREEN;
}

/*
 * mmi_frm_group_create(APP_GB_WINGUO, GRP_GB_WINGUO_SCREEN, _Screen_Launch_Proc,NULL);
 * 进入屏幕事件处理
 *
 */
static GB_INT _Screen_Launch_Proc(mmi_event_struct *evt) 
{
	switch (evt->evt_id)
	{
		case EVT_ID_GROUP_ENTER:
		case EVT_ID_GROUP_ACTIVE:
		case EVT_ID_GROUP_FOCUSED:
			  break;
			  
		case EVT_ID_GROUP_DEINIT:
			mmi_frm_group_close(GRP_GB_WINGUO_SCREEN);
			_Screen_Release();
			break;
	}

	return MMI_RET_OK;
}


/*
 *   获取屏幕历史
 *
 */
static GB_VOID _Screen_ReleaseEx()
{
     
#ifdef __MMI_TOUCH_SCREEN__
	g_gb_original_pen_down_handler = NULL;
#endif

	GB_WG_SMD_Control_Release();
}


/*
*
*  退出屏幕处理
*
*/
static GB_VOID _Screen_Release()
{
	if (g_p_winguo_request_input_buffer != GB_NULL)
	{
		OslMfree(g_p_winguo_request_input_buffer);
		g_p_winguo_request_input_buffer = GB_NULL;
	}

	ClearHighlightHandler();

	g_gb_wg_item_index = 0;

	g_gb_wg_key_code = KEY_INVALID;

	GB_SMD_Release();
}

 /*
 *    绘制屏幕
 *
 */
static GB_VOID _Screen_Entry(GB_VOID)
{
	GB_U8    *gui_buffer = GB_NULL;
	GB_U16    usCount = 0;
	GB_U16    inputbox_width = 0;
#ifdef __MMI_ICON_BAR_SUPPORT__
	GB_INT item_count = MMI_PHB_TOOLBAR_ENUM_TOTAL;
	GB_PU8 item_icon[MMI_PHB_TOOLBAR_ENUM_TOTAL];
	GB_PU8 item_disable_icon[MMI_PHB_TOOLBAR_ENUM_TOTAL];
	GB_PU8 pString[MMI_PHB_TOOLBAR_ENUM_TOTAL];
#endif /* __MMI_ICON_BAR_SUPPORT__ */
	//g_gb_wg_flags = 1;
	if (!mmi_frm_scrn_enter(
		GRP_GB_WINGUO_SCREEN,
		SCR_GB_WINGUO_SCREEN,
		(GB_FuncPtr)_Screen_Exit,
		(GB_FuncPtr)_Screen_Entry,
		MMI_FRM_FULL_SCRN))
	{
		return;
	}
#ifdef __MMI_UI_LIST_SLIDE_EFFECT__
    gui_block_list_effect();
#endif /* __MMI_UI_LIST_SLIDE_EFFECT__ */

#ifdef __MMI_ICON_BAR_SUPPORT__
	item_icon[MMI_PHB_VOICE_CALL] = get_image(IMG_GLOBAL_TOOLBAR_CALL);
	item_icon[MMI_PHB_SEND_MSG] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE);
	item_icon[MMI_PHB_EDIT] = get_image(IMG_GLOBAL_TOOLBAR_EDIT);
	item_disable_icon[MMI_PHB_VOICE_CALL] = get_image(IMG_GLOBAL_TOOLBAR_CALL_DISABLED);
	item_disable_icon[MMI_PHB_SEND_MSG] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE_DISABLED);
	item_disable_icon[MMI_PHB_EDIT] = get_image(IMG_GLOBAL_TOOLBAR_EDIT_DISABLED);
	pString[MMI_PHB_VOICE_CALL] = (GB_PU8)get_string(STR_GLOBAL_DIAL);
	pString[MMI_PHB_SEND_MSG] = (GB_PU8)get_string(STR_GLOBAL_SEND);
	pString[MMI_PHB_EDIT] = (GB_PU8)get_string(STR_GLOBAL_EDIT);

	wgui_icon_bar_setup(item_count, item_icon, item_disable_icon, pString,(GUIIconbarItemCallback)_SubMenu_List_Callback);
#endif
	
	gui_buffer = mmi_frm_scrn_get_active_gui_buf();

	RegisterHighlightHandler(GB_WG_SMD_Highlight_Handler);

	usCount = GB_WG_SMD_Control_Get_Input_Data(g_p_winguo_request_input_buffer);

	GB_WG_SMD_Control_CreateList(usCount,g_gb_wg_item_index,gui_buffer);

#if defined(__MMI_TOUCH_SCREEN__)
	GB_WG_SMD_Control_Set_Search_Button((GB_PU8)get_image(IMG_GB_WINGUO_SKINWHITE_SEARCH),
		(GB_PU8)get_image(IMG_GB_WINGUO_SKINWHITE_SEARCH_PRESS),
		GB_WG_SMD_Search_Button_Request);

	//创建按钮
	GB_WG_SMD_Control_CreateButton();
	inputbox_width = GB_WG_INPUTBOX_WIDTH;
#else
	inputbox_width = MAIN_LCD_DEVICE_WIDTH - GB_WG_X_BLANKSPACE*2;
#endif	

	GB_WG_SMD_Control_CreateInputBox(g_p_winguo_request_input_buffer,GB_WG_SEARCH_WEB_MAX_INPUT_LEN,(GB_PU8)get_string(STR_GLOBAL_OPTIONS),
		(GB_PU8)get_string(STR_GLOBAL_BACK),inputbox_width,gui_buffer);

	GB_WG_SMD_Control_Register_InputBox_Event_Callback(); ////注册输入框事件的回调

	GB_WG_SMD_Control_Register_InputBox_Change_Callback();

	_Show_Screen(
		(GB_PU8)get_string(STR_GB_WINGUO_SMARTSEARCH),
		GB_NULL,
		(GB_PU8)get_string(STR_GLOBAL_OPTIONS),
		(GB_PU8)get_string(STR_GLOBAL_BACK),
		gui_buffer);

	if(GB_WG_SMD_Control_Is_List_Menu_Active() == MMI_FALSE)
	{
		MMI_fixed_icontext_list_menuitem.flags &= ~UI_MENUITEM_DISABLE_HIGHLIGHT;
		MMI_fixed_icontext_list_menuitem.ext_flags &= ~UI_MENUITEM_EXT_DISABLED_SCROLL;
		gui_smooth_scrolling_effect_run();
		MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_DISABLE_HIGHLIGHT;
		MMI_fixed_icontext_list_menuitem.ext_flags |= UI_MENUITEM_EXT_DISABLED_SCROLL;
	}

	if (GB_WG_SMD_Control_Is_InputBox_Active() == MMI_TRUE)
	{
		g_gb_wg_item_index = 0;
	}
	else if (GB_WG_SMD_Control_Is_InputBox_Active() == MMI_TRUE)
	{
		g_gb_wg_item_index = MMI_fixed_list_menu.highlighted_item;
	}

	SetLeftSoftkeyFunction(_Create_Menu_Option, KEY_EVENT_UP);
	SetKeyHandler(GB_WG_SMD_Screen_Close, KEY_BACK, KEY_EVENT_UP);
	SetKeyHandler(GB_WG_SMD_Search_Button_Request, KEY_ENTER, KEY_EVENT_UP); 
	SetKeyHandler(_List_Menu_Call_Num, KEY_SEND, KEY_EVENT_UP);
  
	mmi_imc_key_register_ime_keys();

	MMI_WGUI_SET_KEY_PROC(_Non_Qwerty_Key_Proc,GB_NULL);

	wgui_register_tap_callback(_Select_List_Item_Callback);

	if (g_gb_wg_key_code != KEY_INVALID)
	{
		ExecuteCurrKeyHandler(g_gb_wg_key_code, KEY_EVENT_DOWN);
		g_gb_wg_key_code = KEY_INVALID;
	}
}

static GB_VOID _Screen_Exit(GB_VOID)
{
#ifdef __MMI_UI_LIST_SLIDE_EFFECT__
    gui_unblock_list_effect();
#endif /* __MMI_UI_LIST_SLIDE_EFFECT__ */

}


/*
 *     list列表高亮时的操作,
 *     左右软键的变化及iconbar的明暗变化
 *
 */
GB_VOID GB_WG_SMD_Highlight_Handler(GB_INT item_index)
{
	GB_U32  store_index = 0;
	GB_U16  CachType = 0;
	g_gb_wg_item_index   = item_index >=0 ? item_index : 0;
	
	if ((item_index>= 0)&&(GB_WG_SMD_Control_Is_List_Menu_Active()))
	{
			GB_SMD_GetCachDataByIndex(item_index, &CachType, &store_index);
			if (CachType == GBMD_CachType_Recalled)
			{
				Old_left_softkey_label = (UI_string_type)get_string(STR_GLOBAL_OPTIONS);
				set_left_softkey_label((UI_string_type)get_string(STR_GLOBAL_OPTIONS));
				set_left_softkey_icon(GB_NULL);
				redraw_left_softkey();
				SetLeftSoftkeyFunction(_Create_Menu_Option, KEY_EVENT_UP);

				wgui_icon_bar_set_item_enable_state(0, GB_TRUE);
				wgui_icon_bar_set_item_enable_state(1, GB_TRUE);
				wgui_icon_bar_set_item_enable_state(2, GB_FALSE);
			}
			else if (CachType == GBMD_CachType_PhoneBook)
			{
				Old_left_softkey_label = (UI_string_type)get_string(STR_GLOBAL_OPTIONS);
				set_left_softkey_label((UI_string_type)get_string(STR_GLOBAL_OPTIONS));
				set_left_softkey_icon(GB_NULL);
				redraw_left_softkey();
				SetLeftSoftkeyFunction(_Create_Menu_Option, KEY_EVENT_UP);
				
				wgui_icon_bar_set_item_enable_state(0, GB_TRUE);
				wgui_icon_bar_set_item_enable_state(1, GB_TRUE);
				wgui_icon_bar_set_item_enable_state(2, GB_TRUE);
			}
			else
			{
				Old_left_softkey_label = (UI_string_type)get_string(STR_GLOBAL_OK);
				set_left_softkey_label((UI_string_type)get_string(STR_GLOBAL_OK));
				set_left_softkey_icon(GB_NULL);
				redraw_left_softkey();
				SetLeftSoftkeyFunction(_Ok_App, KEY_EVENT_UP);
				
				wgui_icon_bar_set_item_enable_state(0, GB_FALSE);
				wgui_icon_bar_set_item_enable_state(1, GB_FALSE);
				wgui_icon_bar_set_item_enable_state(2, GB_FALSE);
			}

			Old_right_softkey_label = (UI_string_type)get_string(STR_GLOBAL_BACK);
			set_right_softkey_label(get_string(STR_GLOBAL_BACK));
			set_right_softkey_icon(GB_NULL);
			redraw_right_softkey(); 
			SetRightSoftkeyFunction(GB_WG_SMD_Screen_Close, KEY_EVENT_UP);
			SetKeyHandler(_Select_List_Item_RunEx, KEY_ENTER, KEY_EVENT_UP);
	}
	else
	{
		Old_left_softkey_label = (UI_string_type)get_string(STR_GLOBAL_OPTIONS);
		set_left_softkey_label((UI_string_type)get_string(STR_GLOBAL_OPTIONS));
		set_left_softkey_icon(GB_NULL);
		redraw_left_softkey();
		SetLeftSoftkeyFunction(_Create_Menu_Option, KEY_EVENT_UP);
		SetKeyHandler(GB_WG_SMD_Search_Button_Request, KEY_ENTER, KEY_EVENT_UP);

		if (wgui_inputs_sl_is_empty())
		{
			set_right_softkey_label(get_string(STR_GLOBAL_BACK));
			set_right_softkey_icon(GB_NULL);
			redraw_right_softkey();
		}

		wgui_icon_bar_set_item_enable_state(0, GB_TRUE);
		wgui_icon_bar_set_item_enable_state(1, GB_TRUE);
		wgui_icon_bar_set_item_enable_state(2, GB_TRUE);
		
	}

	wgui_icon_bar_update();
	
}


/*
 *    _Screen_Draw_Background
 *
 */
static GB_VOID _Screen_Draw_Background(GB_INT x1, GB_INT y1, GB_INT x2, GB_INT y2)
{
	gdi_layer_push_clip();
	gdi_layer_set_clip(x1, y1, x2, y2);

	gui_draw_filled_area(x1, y1, x2, y2, (UI_filled_area *)dm_get_current_scr_bg_filler());

	gdi_layer_pop_clip();
}

#ifdef __MMI_TOUCH_SCREEN__
MMI_BOOL wgui_gb_control_highlight_change(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    gui_list_pen_enum menu_event;
    S32 list_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLIPBOARD__
    if (mmi_imc_is_clipboard_state())
    {
        return ret;
    }
#endif /* __MMI_CLIPBOARD__ */

    MMI_fixed_list_menu.pen_redraw_menu_function = wgui_async_list_show_multi_icontext_menu;
    gui_vertical_scrollbar_set_pen_self_scroll(&MMI_fixed_list_menu.vbar, MMI_TRUE);
    gui_fixed_list_menu_set_pen_scroll_delay(&MMI_fixed_list_menu, GUI_DYNAMIC_LIST_PEN_SCROLL_DELAY);

    if ((MMI_fixed_list_menu.n_items * MMI_MENUITEM_HEIGHT) > MMI_fixed_list_menu.height)
    {
        list_h = MMI_fixed_list_menu.height;
    }
    else
    {
        list_h = MMI_fixed_list_menu.n_items * MMI_MENUITEM_HEIGHT;
    }
    
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    if (PEN_CHECK_BOUND(
            point.x, 
            point.y, 
            MMI_fixed_list_menu.x, 
            MMI_fixed_list_menu.y, 
            MMI_fixed_list_menu.width, 
            list_h))
    {
        if (GB_WG_SMD_Control_Is_InputBox_Active() == MMI_TRUE)
        {
            gui_lock_double_buffer();
            GB_WG_SMD_Control_Set_List_Menu_Focus_State(MMI_TRUE);
            asyncdynamic_list_highlight_handler(MMI_fixed_list_menu.highlighted_item);
            GB_WG_SMD_Control_Set_InputBox_Focus_State(MMI_FALSE);
            redraw_singleline_inputbox();
            gui_unlock_double_buffer();
        }
    }
    return MMI_FALSE;
#else
    ClearHighlightHandler();
    ret = gui_dynamic_list_menu_translate_pen_event(
            &MMI_fixed_list_menu,
            MMI_PEN_EVENT_DOWN,
            point.x,
            point.y,
            &menu_event);
    RegisterHighlightHandler(GB_WG_SMD_Highlight_Handler);
    if (ret)
    {
        if (menu_event == GUI_LIST_PEN_HIGHLIGHT_CHANGED 
            || menu_event == GUI_LIST_PEN_NEED_REDRAW 
            || GB_WG_SMD_Control_Is_InputBox_Active() == MMI_TRUE)
        {
            GB_WG_SMD_Control_Set_List_Menu_Focus_State(MMI_TRUE);
            asyncdynamic_list_highlight_handler(MMI_fixed_list_menu.highlighted_item);
            redraw_asyncdynamic_list();
            GB_WG_SMD_Control_Set_InputBox_Focus_State(MMI_FALSE);
            redraw_singleline_inputbox();
        }
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }    
#endif /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN */
}


void wgui_gb_pen_down_handler(mmi_pen_point_struct point)
{

      S32 old_highlight;

     if (g_gb_original_pen_down_handler != NULL)
    {
        register_asyncdynamic_list_keys();
        old_highlight = MMI_fixed_list_menu.highlighted_item;

       wgui_gb_control_highlight_change(point);
       g_gb_original_pen_down_handler(point);
       /*
        if ((g_dm_data.s32CatId == GB_WG_MMI_CAT_ID)  && (!GB_WG_SMD_Control_Is_InputBox_Active()))
        {
            MMI_fixed_list_menu.highlighted_item = old_highlight;
            if (MMI_fixed_list_menu.highlighted_item == WGUI_LIST_INVALID_HIGHLIGHT)
            {
                wgui_cat203_set_editor_focus_state(MMI_TRUE);

                if (!mmi_imc_is_clipboard_state())
                {
                    wgui_inputs_sl_redraw();
                }
                wgui_cat203_set_menu_focus_state(MMI_FALSE);
            }
        }
       */

    }	
}
#endif

/*
 *    for dm_redraw_category_screen.
 *
 */
static GB_VOID _Show_Screen(GB_PU8 title, GB_PU8 title_icon, GB_PU8 left_softkey, GB_PU8 right_softkey, GB_PU8 his_buff)
{
	gdi_layer_lock_frame_buffer();

	gb_wg_add_title_and_softkey(title, title_icon, left_softkey, right_softkey);

	_Screen_Draw_Background(0, 0, UI_device_width - 1, UI_device_height - 1);

	gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category(
		GB_WG_MMI_CAT_ID,
		DM_CLEAR_SCREEN_BACKGROUND | DM_SHOW_VKPAD,
		_Screen_ReleaseEx,
		_Get_History,
		_Get_History_Size);

	dm_register_vkpad_callback(mmi_imc_redraw_screen_by_state);
	
#ifdef __MMI_TOUCH_SCREEN__	
    /* take pen up and pen long tap handler, and register a new handler */
    g_gb_original_pen_down_handler = mmi_pen_get_pen_handler(MMI_PEN_EVENT_DOWN);
    mmi_pen_register_down_handler(wgui_gb_pen_down_handler);
#endif

	dm_redraw_category_screen();
}



/*
 *   获取屏幕历史
 *
 */
static GB_PU8 _Get_History(GB_PU8 history_buffer)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 s;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	get_list_menu_category_history(GB_WG_MMI_CAT_ID, history_buffer);
	s = sizeof(list_menu_category_history);
	s = (s + 3) / 4;
	s *= 4;
	wgui_inputs_sl_get_category_history(GB_WG_MMI_CAT_ID, (U8*) (history_buffer + s));
	return (history_buffer);

}


/*
 *   获取屏幕历史大小
 *
 */
static GB_INT _Get_History_Size(GB_VOID)
{
	return (((sizeof(list_menu_category_history) + 3) / 4) * 4 + sizeof(singleline_inputbox_category_history));
}


/*
 *     左按键选项进入选项界面
 *
 */
static GB_VOID _Create_Menu_Option(GB_VOID)
{
	mmi_id group_id, grp_id, cui_id;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	group_id = mmi_frm_group_get_active_id();
	grp_id = mmi_frm_group_create(
                group_id,
                GRP_ID_AUTO_GEN,
				_Create_Menu_Option_Proc,
                (void*)mmi_frm_group_get_user_data(group_id));
	
	mmi_frm_group_enter(grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	
	cui_id = cui_menu_create(
		grp_id,
		CUI_MENU_SRC_TYPE_RESOURCE,
		CUI_MENU_TYPE_OPTION,
		MITEM_WINGUO_VIEW_OPTIONS,
		GB_TRUE, GB_NULL);
    #ifdef __MMI_UNIFIED_COMPOSER__
        if (!mms_is_ready())
        {
            cui_menu_set_item_hidden(cui_id, MENU_ID_WINGUO_SEND_MMS, MMI_TRUE);
        }
    #else /* __MMI_UNIFIED_COMPOSER__ */
    #ifdef __MMI_MMS__
        if (!mms_is_ready())
        {
            cui_menu_set_item_hidden(cui_id, MENU_ID_WINGUO_SEND_MMS, MMI_TRUE);
        }
    #endif /* __MMI_MMS__ */
    #endif /* __MMI_UNIFIED_COMPOSER__ */
	if (cui_id != GRP_ID_INVALID)
	{
		cui_menu_run(cui_id);//g_gb_wg_menu_gid//
	}
}


/*
 *     进入选项CUI 菜单的事件处理
 *
 */
static GB_INT _Create_Menu_Option_Proc(mmi_event_struct *evt) 
{
	MMI_ID group_id;
	GB_INT                 result   = MMI_RET_OK;
	cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    
	switch (evt->evt_id)
	{
		case EVT_ID_CUI_MENU_LIST_ENTRY:
		case EVT_ID_CUI_MENU_ITEM_HILITE:
			break;
			 
		case EVT_ID_CUI_MENU_LIST_EXIT:
		
		case EVT_ID_CUI_MENU_ITEM_SELECT:
			switch(menu_evt->highlighted_menu_id)
			{
				case MENU_ID_WINGUO_DIAL:
					_List_Menu_Call_Num();
					break;
				
				case MENU_ID_WINGUO_SEND_SMS:
					_List_Menu_Send_SMS();
					break;

				case MENU_ID_WINGUO_SEND_MMS:
					_List_Menu_Send_MMS();
					break;

				case MENU_ID_WINGUO_SAVE_CONTACT:
					_List_Menu_Save_Contact();
					break;			

				case MENU_ID_WINGUO_SEARCH:
					GB_WG_SMD_Search_Button_Request();
					break;
				
				case MENU_ID_WINGUO_EXIT:
					mmi_frm_group_close(GRP_GB_WINGUO_SCREEN);		
					break;
				
				default:
					result = MMI_RET_DONT_CARE;
					break;
			}
			break;
			
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
			cui_menu_close(menu_evt->sender_id); //g_gb_wg_menu_gid = 0;
			break;
			
		default:
			break;
			
	}

	return MMI_RET_OK;
}


/*
 *      右键退出屏幕
 *
 */
 GB_VOID GB_WG_SMD_Screen_Close(GB_VOID)
{
	if (GB_WG_Platform_Is_Winguo())
	{
		mmi_frm_group_close(GRP_GB_WINGUO_SCREEN);
	}
}

		
/*
 *     按中键或button 进入网络
 *
 */
GB_VOID GB_WG_SMD_Search_Button_Request(GB_VOID)
{
	if (g_p_winguo_request_input_buffer)
	{
		GB_WG_SeachString(g_p_winguo_request_input_buffer);
	}
}


/*
 *     悬挂菜单的callback，for call ,sms or edit number
 *
 */
#ifdef __MMI_ICON_BAR_SUPPORT__
static GB_VOID _SubMenu_List_Callback(GB_INT index)
{
	GB_U32  store_index = 0;
	GB_U16  CachType    = 0;
	GB_INT  ret         = 0;

	if (GB_WG_SMD_Control_Is_List_Menu_Active())
	{	
		GB_SMD_GetCachDataByIndex(g_gb_wg_item_index, &CachType, &store_index);
			
		if (index == MMI_PHB_EDIT)
		{
			if (CachType != GBMD_CachType_Recalled)
			{
				if (MMI_fixed_list_menu.n_items > 0)
				{
					ret = 1;
				}							
			}
		}
	}
	else
	{
		if (index == MMI_PHB_EDIT)
		{
			ret = 4;
		}
	}

	if(index == MMI_PHB_VOICE_CALL)
	{
		ret = 2;
	}
	else if (index == MMI_PHB_SEND_MSG)
	{
		ret = 3;
	}

	if (ret > 0)
	{
		switch (ret)
		{
			case 1:
				_Edit_Phb_Entry(GB_SMD_PhoneNumGetRealId(store_index));
				break;
			case 2:
				_List_Menu_Call_Num();
				break;
			case 3:
				_List_Menu_Send_SMS();
				break;
			case 4:
				_List_Menu_Save_Contact();
				break;
			default:
				break;
		}
	}
}
#endif


/*
 *    触屏选中list 列表项操作入口
 *
 */
static GB_VOID _Select_List_Item_Callback(mmi_tap_type_enum tap_type, GB_INT index)
{
	_Select_List_Item_Run(index);
}


/*
 *    中键选中list 列表项操作入口
 *
 */
static GB_VOID _Select_List_Item_RunEx(GB_VOID)
{
	_Select_List_Item_Run(g_gb_wg_item_index);
}


/*
 *    选中list 列表项操作
 *
 */
static GB_VOID _Select_List_Item_Run(GB_INT index)
{
	GB_U16	CachType = 0;
	GB_U16	index_type = 0;
	GB_U32	store_index = 0;

	GB_SMD_GetCachDataByIndex(index, &CachType, &store_index);

	if (CachType == GBMD_CachType_PhoneBook)
	{
	//	g_gb_wg_flags = 0;
		// 电话簿中的联系人
		cui_phb_view_contact(GRP_GB_WINGUO_SCREEN, GB_SMD_PhoneNumGetRealId(store_index));
	}
	else if (CachType == GBMD_CachType_Recalled)
	{
		// 通话记录，需要处理
	}
	else if(CachType == GBMD_CachType_App)
	{
		GB_SMD_RunApp(store_index);
	}
}


/*
 *    左键进入应用
 * 
 */
static GB_VOID _Ok_App(GB_VOID)
{
	GB_U16               CachType = 0;
	GB_U32               store_index = 0;

	GB_SMD_GetCachDataByIndex(g_gb_wg_item_index, &CachType, &store_index);

	GB_SMD_RunApp(store_index);
}



/*
 *    获取索引信息
 *    pCachType 存储类型
 *    store_index存储索引
 *    pBuff  存储号码内容
 *    nBuffLen 长度
 *
 */
static GB_INT _List_Menu_Get_Data(GB_U16 *pCachType, GB_U16 *store_index, GB_U16 *pBuff, GB_U16 nBuffLen)
{
	GB_INT ret = 0;
	GB_U32 nId;
	GB_MEMSET(pBuff, 0, sizeof(*pBuff)*nBuffLen);

	GB_SMD_GetCachDataByIndex(g_gb_wg_item_index, pCachType, &nId);
	
	if (*pCachType == GBMD_CachType_PhoneBook)
	{
		GB_INT nCount = 0;
		nCount = GB_SMD_PhoneNumGetCountById(nId);
		if (nCount > 1)
		{
			ret = nCount;
		}
		*store_index = GB_SMD_PhoneNumGetRealId(nId);

		GB_SMD_PhoneNumGetNumById(nId, pBuff, nBuffLen);
	}
	else if(*pCachType == GBMD_CachType_Recalled)
	{
		GB_SMD_CallLogGetPhoneNumByIndex(nId, pBuff, nBuffLen);
		*store_index = nId;
	}
	else 
	{
		return -1;
	}

	return ret;
}


/*
 *      list 列表号码操作call, mms, or sms
 *
 */
static GB_VOID _List_Menu_Number_Action(mmi_phb_op_action_enum action_op,GB_U16 store_index)
{
	mmi_id sg_id;
	mmi_phb_op_action_cntx_struct op_cntx;

	sg_id =  mmi_frm_group_create_ex(
			GRP_GB_WINGUO_SCREEN,
			GRP_ID_PHB_BEGIN,
			mmi_dummy_proc,
			NULL,
			MMI_FRM_NODE_SMART_CLOSE_FLAG);
	
	GB_MEMSET(&op_cntx, 0, sizeof(mmi_phb_op_action_cntx_struct));
	op_cntx.store_index = store_index;
	op_cntx.op_action = action_op;    
	mmi_phb_op_start(&op_cntx, sg_id);
}


/*
 *      list 列表号码发送彩信
 *
 */
static GB_VOID _List_Menu_Send_MMS()
{
	GB_INT          iFlag       = 0;
	GB_U16          CachType    = 0;
	GB_U16          store_index = 0;
	GB_U16          tempBuff[GB_WG_LIST_MENU_MAX_BUFF_LEN+1] = {0};

	if (GB_WG_SMD_Control_Is_List_Menu_Active())
	{
		iFlag = _List_Menu_Get_Data(&CachType, &store_index, tempBuff, GB_WG_LIST_MENU_MAX_BUFF_LEN);
		if (CachType == GBMD_CachType_PhoneBook )
		{
			if(GB_WG_Get_Phone_Mode() != e_GB_WG_SMD_PHONE_NORMAL)
			{
				mmi_popup_display_ext(STR_GB_WINGUO_NOT_USE, MMI_EVENT_FAILURE, GB_NULL);
				return;
			}
	
#ifdef __MMI_UNIFIED_COMPOSER__
			_List_Menu_Number_Action(MMI_PHB_OP_MSG,store_index);    
#else
#ifdef __MMI_MMS__
			_List_Menu_Number_Action(MMI_PHB_OP_MMS,store_index);

#endif
#endif
			return;
		}
	}
	else
	{
		gb_wg_wcscpy(tempBuff,g_p_winguo_request_input_buffer);
	}

	if(0 != mmi_wcslen(tempBuff) && GB_WG_String_IsNumSymbol(tempBuff))
	{
		mms_address_insert_hdlr((GB_CHAR*)tempBuff);
	}
	else
	{
		mms_text_insert_hdlr(GB_NULL, 0, (GB_CHAR *)tempBuff,mmi_wcslen(tempBuff));
	}
}


/*
 *      list 列表号码发送短信
 *
 */
static GB_VOID _List_Menu_Send_SMS()
{
	GB_S8                           ascii_number[MMI_PHB_NUMBER_LENGTH + 1];
	mmi_sms_write_msg_para_struct   sendData;
	GB_INT                          iFlag       = 0;
	GB_U16                          CachType    = 0;
	GB_U16                          store_index = 0;
	GB_U16                          tempBuff[GB_WG_LIST_MENU_MAX_BUFF_LEN+1] = {0};

	if (GB_WG_SMD_Control_Is_List_Menu_Active())
	{
		iFlag = _List_Menu_Get_Data(&CachType, &store_index, tempBuff, GB_WG_LIST_MENU_MAX_BUFF_LEN);
		if (CachType == GBMD_CachType_PhoneBook )
		{
			if(GB_WG_Get_Phone_Mode() != e_GB_WG_SMD_PHONE_NORMAL)
			{
				mmi_popup_display_ext(STR_GB_WINGUO_NOT_USE, MMI_EVENT_FAILURE, GB_NULL);
				return;
			}

#ifdef __MMI_UNIFIED_COMPOSER__
			_List_Menu_Number_Action(MMI_PHB_OP_MSG,store_index);   
#else
			_List_Menu_Number_Action(MMI_PHB_OP_SMS,store_index);
#endif
			return;
		}
	}
	else
	{
		gb_wg_wcscpy(tempBuff,g_p_winguo_request_input_buffer);
	}

	mmi_msg_set_phb_send_case(MMI_SEND_SMS_FROM_PHB);

	GB_MEMSET(ascii_number, 0, sizeof(ascii_number));
	GB_MEMSET(&sendData, 0, sizeof(mmi_sms_write_msg_para_struct));

	if(0 != mmi_wcslen(tempBuff) && GB_WG_String_IsNumSymbol(tempBuff))
	{
		mmi_ucs2_n_to_asc((GB_S8*)ascii_number, (GB_S8*)tempBuff, MMI_PHB_NUMBER_LENGTH + 1);
		sendData.ascii_addr = (GB_PU8) ascii_number;
	}
	else
	{
		sendData.string = (GB_S8 *)tempBuff;
		sendData.stringlength = mmi_wcslen(tempBuff);	
	}	
	sendData.dcs = 0;
	sendData.flag = MMI_SMS_ENTRY_WRITE_REPLY;

	mmi_sms_write_msg_lanch(0, &sendData);
}


/*
 *       进入编辑联系人界面的事件处理
 *
 */
static GB_INT _Edit_Phb_Entry_Proc(mmi_event_struct *event)
{

	switch (event->evt_id)
	{
		case EVT_ID_PHB_SAVE_CONTACT:
		case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
			{
				mmi_group_event_struct *group_evt = (mmi_group_event_struct *)event;
				cui_phb_save_contact_close(group_evt->sender_id);
			}
			break;
			
		default:
			break;
	}

	return MMI_RET_OK;
}


/*
 *      list 列表号码进入编辑联系人界面
 *
 */
static GB_VOID _Edit_Phb_Entry(GB_U16 store_index)
{
		GB_INT         sg_id;
		GB_INT         parent_gid;

		parent_gid = mmi_frm_group_create_ex(
			GRP_GB_WINGUO_SCREEN,
			GRP_ID_AUTO_GEN,
			_Edit_Phb_Entry_Proc,
			NULL,
			MMI_FRM_NODE_SMART_CLOSE_FLAG);

		sg_id = cui_phb_save_contact_create(parent_gid);
		
		if(sg_id != GRP_ID_INVALID)
		{
			cui_phb_save_contact_set_store_index(sg_id, store_index);
			//g_mmi_phb_list_p->child_id = sg_id;
			cui_phb_save_contact_run(sg_id);
		}
		else
		{
			mmi_frm_group_close(parent_gid);
		}

}


/*
 *      list 列表号码保存或编辑接口
 *
 */
static GB_VOID _List_Menu_Save_Contact()
{
	mmi_id parent_gid, child_gid;
	GB_U16                          CachType    = 0;
	GB_U16                          store_index = 0;
	GB_U16                          tempBuff[GB_WG_LIST_MENU_MAX_BUFF_LEN+1] = {0};

	if (g_p_winguo_request_input_buffer == GB_NULL)
	{
		return;
	}

	if (GB_WG_SMD_Control_Is_List_Menu_Active())
	{
		_List_Menu_Get_Data(&CachType, &store_index, tempBuff, GB_WG_LIST_MENU_MAX_BUFF_LEN);

		if (CachType == GBMD_CachType_Recalled )
		{	
			goto END;

		}
		else if(CachType == GBMD_CachType_PhoneBook)
		{
			_Edit_Phb_Entry(store_index);	
			return;
		}
	}
	else
	{
		gb_wg_wcscpy(tempBuff,g_p_winguo_request_input_buffer);
	}

END:
	parent_gid = mmi_frm_group_create(
		GRP_GB_WINGUO_SCREEN,//	mmi_frm_group_get_active_id(),
		GRP_ID_AUTO_GEN,
		_Edit_Phb_Entry_Proc,
		GB_NULL);

	mmi_frm_group_enter(parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

	child_gid = cui_phb_save_contact_create(parent_gid);

	if (child_gid == GRP_ID_INVALID)
	{
		mmi_frm_group_close(parent_gid);
		return;
	}
	
	if(0 != mmi_wcslen(tempBuff) && GB_WG_String_IsNumSymbol(tempBuff))
		cui_phb_save_contact_set_number(child_gid, tempBuff);
	else
		cui_phb_save_contact_set_name(child_gid, tempBuff, NULL);
	cui_phb_save_contact_run(child_gid);
	
	return;
}


/*
 *      list 列表号码进入拨号的接口
 *
 */
static GB_VOID _List_Menu_Call_Num()
{
	GB_INT                          iFlag                                      = 0;
	mmi_ucm_make_call_para_struct   make_call_para;
	GB_U16                          CachType                                   = 0;
	GB_U16                          store_index                                = 0;
	GB_U16                          tempBuff[GB_WG_LIST_MENU_MAX_BUFF_LEN+1]   ={0};

	if (GB_WG_SMD_Control_Is_List_Menu_Active())
	{
		iFlag = _List_Menu_Get_Data(&CachType, &store_index, tempBuff, GB_WG_LIST_MENU_MAX_BUFF_LEN);
		if (CachType == GBMD_CachType_PhoneBook)
		{
			if(GB_WG_Get_Phone_Mode() != e_GB_WG_SMD_PHONE_NORMAL)
			{
				mmi_popup_display_ext(STR_GB_WINGUO_NOT_USE, MMI_EVENT_FAILURE, GB_NULL);
				return;
			}
			
			_List_Menu_Number_Action(MMI_PHB_OP_CALL,store_index);
			return;
		}
	}
	else
	{
		gb_wg_wcscpy(tempBuff,g_p_winguo_request_input_buffer);
	}

	if(0 != mmi_wcslen(tempBuff) && !GB_WG_String_IsNumSymbol(tempBuff))
	{
		mmi_popup_display_ext(STR_GB_WINGUO_INVALID_NUMBER, MMI_EVENT_FAILURE, GB_NULL);
		return;
	}

	mmi_ucm_init_call_para(&make_call_para);

		if (_Is_Dual_Usable())
		{
			make_call_para.dial_type &= ~SRV_UCM_VOIP_CALL_TYPE;
		}
		else if (srv_nw_usab_is_usable(MMI_SIM1))
		{
			make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
		}
		else if (srv_nw_usab_is_usable(MMI_SIM2))
		{
			make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
		}
#if (MMI_MAX_SIM_NUM >= 3)
		else if (srv_nw_usab_is_usable(MMI_SIM3))
		{
			make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
		}
#endif
#if (MMI_MAX_SIM_NUM >= 4)
		else if (srv_nw_usab_is_usable(MMI_SIM4))
		{
			make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
		}
#endif
		else
		{
			make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
		}

		make_call_para.ucs2_num_uri = (GB_U16*)tempBuff;
		mmi_ucm_call_launch(0, &make_call_para);
}


/*
 *  为g_p_winguo_request_input_buffer分配内存
 *
 */
static GB_VOID _Input_Buff_Init(GB_VOID)
{
	if (g_p_winguo_request_input_buffer == NULL)
	{
		g_p_winguo_request_input_buffer = (GB_U16*)OslMalloc((GB_WG_SEARCH_WEB_MAX_INPUT_LEN+1)*sizeof(GB_U16));
		GB_MEMSET(g_p_winguo_request_input_buffer, 0, (GB_WG_SEARCH_WEB_MAX_INPUT_LEN+1)*sizeof(GB_U16));
	}	
}


/*
 *      判断是不是多卡模式
 *
 */
static GB_BOOL _Is_Dual_Usable()
{
	GB_BOOL     ret = GB_FALSE;
	GB_INT      iCount = 0;

#ifdef __MMI_DUAL_SIM_MASTER__
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
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif

	if (iCount >= 2)
	{
		ret = GB_TRUE;
	}

	return ret;
}


/*
 *     虚拟键盘已弹出的情况下按左右软键时先隐藏虚拟键盘
 *
 */
static GB_INT _Non_Qwerty_Key_Proc(mmi_event_struct *evt)
{
	mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt; 

	if (key_evt->evt_id == EVT_ID_PRE_KEY)
	{
		if (GB_TRUE == mmi_imc_key_routing_event_handler(
			key_evt->key_code,
			key_evt->key_type,
			key_evt->ucs2_value,
			key_evt->special_key_flag))
		{
			return MMI_RET_KEY_HANDLED;
		}                            
	}

	return MMI_RET_OK;
}

#endif /*#ifdef __MMI_GB_WINGUO_V2__*/
