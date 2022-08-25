
#include "MMI_features.h"

#ifdef __MMI_GB_WINGUO__

#undef GB_PACKAGE

#include "MMIDataType.h"
#include "wgui.h"
#include "ImeGprot.h"
#include "imc.h"
#include "wgui_softkeys.h"

#include "GB_App.h"
#include "GB_WG_InputPort.h"
#include "GB_PlatIme.h"
#include "GB_WG_SYSApp.h"
#include "GB_SystemPlat.h"

#include "GB_WG_MTKPlatver.h"
#include "gb_candidate.h" 
/************************************************************************************************/
/************************************************************************************************/
 
static U32 ime_callback( void * handle, mmi_imc_message_struct_p msg);
static void ime_background_filler(S32 x1, S32 y1, S32 x2, S32 y2);
static void ime_softkey_background_filler(S32 x1, S32 y1, S32 x2, S32 y2);
static void internal_set_input_type(GB_INT editorType, GB_INT inputType);
static MMI_BOOL GB_WG_ime_pre_key_handler(U16 keycode, U16 keytype);
static void GB_WG_registerKeyHandlerForIME();
static U32 ime_msg_unimplemented(mmi_imc_message_struct_p msg);
static void GB_WG_RecoverKeyHandler(void);
static GB_VOID GB_WG_CancelSMDNumInputStat(GB_VOID);
static GB_VOID GB_WG_ClearSMDNumInput(GB_VOID);
static GB_VOID GB_WG_SMDNumInputSetInitial(GB_VOID);
static MMI_BOOL GB_WG_ChangeInputmod(mmi_imm_input_mode_enum mode);

GB_VOID GB_WG_SetInputCandString(GB_WCHAR *pCnadstring);

static mmi_imc_rect imui_rect ={0};

static mmi_imm_input_mode_enum GB_WG_ProInputMode = IMM_INPUT_MODE_NONE;
//#ifndef GBWG_VIRTUAL_KEY
static GB_BOOL GB_WG_VK_is_show = GB_FALSE;		//判断输入法connect后是否显示虚拟键盘  zhangchenglong
//#endif
static GB_WG_IME_EditorType GB_WG_EditorType = GB_WG_IME_InputType_SINGLELINE;

static int GB_WG_ime_handler;

/************************************************************************************************/
/************************************************************************************************/
#ifndef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_GB__			//按键处理,modify by zhangchenglong 2011_11_10
#include "gb_platform.h"
extern void GBDrawCandWnd_ext(void);
extern GBIInputBox gbCurInputBox;
MMI_BOOL GB_WG_Ime_EditorInsertChar(GB_WCHAR c)
{
	unsigned short insertstring[2] = {0};
	insertstring[0] = c;
	return GB_WG_Ime_EditorInsertString(insertstring);
}
GB_VOID GB_WB_CheckInputString(const GB_WCHAR* srcinputstring, GB_WCHAR* destinputstring, GB_INT destinputbufferlength)
{
	GB_INT i=0;
	while(i<destinputbufferlength && *srcinputstring!=0)
	{
		if (*srcinputstring == '*' ||  *srcinputstring == '#')
		{
			srcinputstring++;
		}
		else
		{
			*destinputstring = *srcinputstring ;
			srcinputstring++;
			destinputstring++;		
			i++;
		}
	}
	*destinputstring = 0;
}

MMI_BOOL GB_WG_GuobiCandIsShow(GB_VOID)
{
	MMI_BOOL ret = MMI_FALSE;
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_VIRTUAL_KEYBOARD__)
	if(GUI_VIRTUAL_KEYBOARD_GUOBI_CAND == MMI_VIRTUAL_KEYBOARD_LANG)
#else
	if(GBCand_IsActive())
#endif
	{
		ret = MMI_TRUE;
	}
	return ret;
}
GB_VOID GB_WG_ShowSMDGuobiCandWnd(GB_VOID)
{
	if (GB_WG_EditorType == GB_WG_IME_InputType_SMD_SINGLELINE && (!mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON) || GB_WG_PlatIme_is_vk_disabled()))
	{
		GB_WCHAR *pInputstr = NULL;
		GB_WG_Ime_GetText(&pInputstr);
		GBChangeInputModeForInputBox(IMM_INPUT_MODE_SM_PINYIN);
// 		GBEngine_SwitchInputMode(GBEngine_GetEnineInstance(),GBIM_Pinyin, GBL_Chinese, GBL_Sub_Not_Spec);
// 		GBEngine_SetEngineOption(GBEngine_GetEnineInstance(), GB_ENGINE_CHINESE, GBCFG_CHARSET_SET, GB_CHARSET_ALL);
		if (pInputstr && *pInputstr)
		{
			GB_WCHAR destinputstring[GB_INPUT_MAX_LEN + 1] = {0};
			GB_WB_CheckInputString(pInputstr, destinputstring, GB_INPUT_MAX_LEN);
			if (destinputstring[0])
			{
				GBEngine_SendKeyEvent(GBEngine_GetEnineInstance(), GBEVENT_SET_INPUT_STRING, (GB_ULONG)destinputstring);
				GBDrawCandWnd_ext();
			}
		}
		GBEngine_Reset(GBEngine_GetEnineInstance());
	}
}
GB_VOID GB_WG_ResetIMESoftKey(GB_VOID)
{
	reset_softkeys();
 	set_softkey_label(NULL, MMI_RIGHT_SOFTKEY);
 	set_softkey_label(NULL, MMI_LEFT_SOFTKEY);
	register_default_hide_softkeys();

//	GB_WG_SetInputCandString(L"");
}
GB_VOID GB_WG_ResetGBIMEHandle(GB_VOID)
{
	GBIInputBox multiline = 
	{
		GB_WG_Ime_EditorInsertChar,
		GB_WG_ResetIMESoftKey,
		GB_WG_RegisterControlKeyHandle,
		GB_WG_Ime_EditorAllChar,
		GB_WG_Ime_EditorIsEmpty,
		NULL,
		GBMultilineInputBox,
	};
	// 输入法左右按键需要清空 [lzp 2012-1-25]
	Old_left_softkey_label = NULL;
	Old_right_softkey_label = NULL;
	multiline.pfChangeInputMode = gbCurInputBox.pfChangeInputMode;
	GBSetCurInputBox(&multiline);
	GBResetCandCoordInfo();  //输入法候选框重置 [lzp 2012-1-23]
}

#endif // __MMI_GB__
#endif // __COSMOS_MMI_PACKAGE__
/************************************************************************************************/
/************************************************************************************************/
GB_BOOL GB_WG_PlatIme_is_vk_disabled(GB_VOID)
{
	#if defined(__MMI_TOUCH_SCREEN__)
		return mmi_imc_is_vk_disabled();
	#endif
	return GB_TRUE;
}
static GB_VOID GB_WG_PlatImeSetImeRect(GB_INT x, GB_INT y, GB_INT width, GB_INT height)
{
	mmi_imc_rect rect;
	mmi_imc_rect temprect = {0};
	rect.x = x;
	rect.y = y;
	rect.width = width;
	rect.height = height;

	//  [4/18/2012 liangchuanhui]
	GB_MEMCPY(&temprect, &imui_rect, sizeof(temprect));
// 	if (rect.height != imui_rect.height)
// 	{
// 		if (rect.height != 0)
// 		{
// 			GB_WG_Ime_VkHide_CallBack(GB_TRUE);
// 		}
// 		else
// 		{
// 			GB_WG_Ime_VkHide_CallBack(GB_FALSE);
// 		}
//	}
	if (GB_MEMCMP(&rect, &imui_rect, sizeof(imui_rect)) != 0)
	{
		if (imui_rect.height > 0 && imui_rect.width > 0)
		{
			GB_Rect gbRect;
			gbRect.xPos = imui_rect.x - 1;  // -1容错 [12/30/2011 lzp]
			gbRect.yPos = imui_rect.y-1;  // -1容错 [12/30/2011 lzp]
			gbRect.width = imui_rect.width + 2;  // +2容错 [12/30/2011 lzp]
			gbRect.height = imui_rect.height+2; // +2容错 [12/30/2011 lzp]
			// 更新刷新区域
 			GB_WG_Ime_SetRedrawRect(&gbRect);
		}
		GB_MEMCPY(&imui_rect, &rect, sizeof(imui_rect));
		//  [4/18/2012 liangchuanhui]
		if (rect.height != temprect.height)
		{
			if (rect.height != 0)
			{
				GB_WG_VK_is_show = GB_TRUE;
				GB_WG_Ime_VkHide_CallBack(GB_TRUE);
			}
			else
			{
				GB_WG_VK_is_show = GB_FALSE;
				GB_WG_Ime_VkHide_CallBack(GB_FALSE);
			}

		}
	}
}

GB_VOID GB_WG_R_ImeInit(GB_VOID)
{
	GB_WG_ProInputMode = IMM_INPUT_MODE_NONE;
}
GB_VOID GB_WG_R_Release(GB_VOID)
{
	GB_WG_ProInputMode = IMM_INPUT_MODE_NONE;
	GB_WG_VK_is_show = GB_FALSE;
}

GB_VOID GB_WG_R_SetVKDefaltShow(GB_BOOL isShow)
{
	GB_WG_VK_is_show = isShow;
#if defined(__MMI_VIRTUAL_KEYBOARD__)
	if (!GB_WG_VK_is_show)
	{
		gui_lock_double_buffer();
		mmi_imc_pen_vk_hide();
		gui_unlock_double_buffer();
	}
#endif
}

GB_VOID GB_WG_R_ImeConnect(GB_INT editorType, GB_INT inputType, GB_INT inputmodData)
{
	if(!mmi_imc_is_connected())
	{  
#ifdef __MMI_TOUCH_SCREEN__ 
		mmi_pen_stop_capture_strokes(); // 解决winguo界面输入法还可以手写的bug [9/19/2011 lzp]
#endif
	// 如果是系统切换的输入法就不恢复记录，不恢复输入法 [11/29/2011 liangchuanhui]
		if (mmi_imm_get_user_desired_input_mode() != IMM_INPUT_MODE_NONE )
		{
			GB_WG_ProInputMode = IMM_INPUT_MODE_NONE;
		}

// #ifndef __MMI_FTE_SUPPORT__
// 		
// #else
		mmi_imc_set_softkey_background_filler(ime_softkey_background_filler);
// 		register_default_hide_softkeys();
// #ifdef __MMI_WALLPAPER_ON_BOTTOM__
// 		wgui_set_wallpaper_on_bottom(MMI_TRUE);
// #endif 
// 	#ifdef GBWG_VIRTUAL_KEY
// 		mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_HIDE);
// 		mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_ENLARGE);
// 	#else
//  [6/2/2012 liangchuanhui]
//#ifndef GBWG_VIRTUAL_KEY	
		if (!GB_WG_Get_isVirtual_key())
		{
			if(editorType == GB_WG_IME_InputType_SMD_SINGLELINE)
			{
				GB_WG_VK_is_show = 0;
			}
		}

//#endif
#ifdef __MMI_FTE_SUPPORT__
		if (GB_WG_VK_is_show)
		{
			mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_ENLARGE);
		}
		else
		{
			mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_HIDE);		//针对有物理按键的手机，隐藏虚拟键盘 zhangchenglong add
		}
#endif
//	#endif
// #endif
		// for techfaith68, disable handwriting
#if defined(__MMI_MAINLCD_320X240__) && defined(__MMI_TOUCH_SCREEN__)
		mmi_imc_disable_handwriting();
#endif
		mmi_imc_set_backgroud_filler(ime_background_filler);
		internal_set_input_type(editorType, inputType);
		mmi_imc_disable_csk();
		mmi_imc_set_is_disable_candidate_box(MMI_FALSE);
		mmi_imc_connect((void*)&GB_WG_ime_handler, ime_callback);
		GB_WG_R_SetVKDefaltShow(GB_WG_VK_is_show);
		
//		mmi_immc_config_softkeys_changeable(GB_FALSE);

#ifndef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_GB__  //按键处理,modify by zhangchenglong 2011_11_10
		GB_WG_ResetGBIMEHandle();
#endif
#endif // __COSMOS_MMI_PACKAGE__

// 		if (GB_WG_ProInputMode != IMM_INPUT_MODE_NONE)
// 		{
// 			mmi_imc_change_input_mode(GB_WG_ProInputMode, 0);
// 		}
		// 恢复输入法 [11/29/2011 liangchuanhui]
		
		if (GB_WG_ProInputMode != IMM_INPUT_MODE_NONE && inputmodData != 0 && mmi_imm_is_curr_allow_input_mode(inputmodData))
		{
			// mmi_imm_change_input_mode_for_wcss(inputmodData);
			GB_WG_ChangeInputmod(inputmodData);
		}
		else if (GB_WG_ProInputMode != IMM_INPUT_MODE_NONE && mmi_imm_is_curr_allow_input_mode(GB_WG_ProInputMode))
		{
			//	mmi_imc_change_input_mode(GB_WG_ProInputMode, 0);
			// mmi_imm_change_input_mode_for_wcss(GB_WG_ProInputMode);
			GB_WG_ChangeInputmod(GB_WG_ProInputMode);
		}
		
	}
	mmi_imc_key_set_pre_key_handler(GB_WG_ime_pre_key_handler);
#ifdef __MMI_FTE_SUPPORT__
#ifdef GB_MTK_11B6255
#if defined(__MMI_VIRTUAL_KEYBOARD__)
	if (!GB_WG_VK_is_show)
	{
		mmi_imc_pen_vk_hide();
	}
#endif
#endif
#else
#if defined(__MMI_VIRTUAL_KEYBOARD__)
	if (!GB_WG_VK_is_show)
	{
		mmi_imc_pen_vk_hide();
	}
#endif
#ifdef __MMI_TOUCH_SCREEN__
	if (editorType != GB_WG_IME_InputType_MULTILINE)
	{
		// 关闭手写
		//mmi_imc_pen_disable_handwriting();
		mmi_pen_stop_capture_strokes();
	}
#endif
	// 当键盘版SMD状态时，不显示虚拟键盘 [lzp 2012-2-28]
	//  [6/2/2012 liangchuanhui]
//#ifndef GBWG_VIRTUAL_KEY	
	if (!GB_WG_Get_isVirtual_key())
	{
		if(GB_WG_EditorType == GB_WG_IME_InputType_SMD_SINGLELINE)
		{
#if defined(__MMI_VIRTUAL_KEYBOARD__)
			mmi_imc_disable_virtual_keyboard();
#endif
		}
	}
	
//#endif
#endif

	
	//	mmi_imc_redraw_softkey_background();
	//	GB_WG_registerKeyHandlerForIME();
//	mmi_imc_redraw_screen_by_state();
}

GB_VOID GB_WG_R_ImeDisconnect(GB_VOID)
{
	if(mmi_imc_is_connected())
	{
		GB_WG_CancelSMDNumInputStat();
		GB_WG_ProInputMode = mmi_imm_get_curr_input_mode();
		// 输入框记录下当前输入法 [12/2/2011 lzp]
		GB_WG_Ime_SetInputmodData(mmi_imm_get_curr_input_mode());
		
//#ifndef GBWG_VIRTUAL_KEY		
// 		if (GB_WG_R_ImeVKIsShowState())		//add by zhangchenglong 2011_11_18
// 		{
// 			GB_WG_VK_is_show = GB_TRUE;
// 		}
// 		else
// 		{
// 			GB_WG_VK_is_show = GB_FALSE;
// 		}
//#endif		
		//		mmi_imc_get_input_method_history(&input_method_histroy);
		mmi_imc_reset_ime_state();
		mmi_imc_disconnect();
		
#ifdef __MMI_FTE_SUPPORT__
		mmi_imc_set_vk_present(MMI_IMC_VK_PRESENT_DEFAULT);
#endif
		mmi_imc_redraw_screen_by_state();
	}
	// 输入法区域清空
	GB_WG_PlatImeSetImeRect(0, 0, 0, 0);
	GB_WG_RecoverKeyHandler();
}

GB_VOID GB_WG_R_ImeShow(GB_VOID)
{
	mmi_imc_redraw_screen_by_state();
}

GB_BOOL GB_WG_R_ImeCanShow(GB_VOID)
{
	if (MMI_IMC_STATE_HAND_WRITING == mmi_imc_get_state())
	{
		return GB_FALSE;
	}
#ifndef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_GB__								//按键处理,modify by zhangchenglong 2011_11_10
	if (GB_WG_GuobiCandIsShow())
	{
		return GB_FALSE;
	}
#endif
#endif // __COSMOS_MMI_PACKAGE__
	return GB_TRUE;
}

GB_INT GB_WG_R_ImeSetCandInputString(GB_WCHAR *pInputString)
{
	GB_INT ret = 0;
	if (mmi_imc_is_connected())
	{
#ifndef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_GB__
		GB_WCHAR destinputstring[GB_INPUT_MAX_LEN + 1] = {0};
		GB_WB_CheckInputString(pInputString, destinputstring, GB_INPUT_MAX_LEN);
		// 输入法输入字符串的接口 [lzp 2012-1-23]
		ret = GBEventHandler(GBEVENT_SET_INPUT_STRING, (GB_ULONG)destinputstring);
#endif
#endif // __COSMOS_MMI_PACKAGE__
	}
	return ret;
};
GB_BOOL GB_WG_R_ImeVKIsShowState(GB_VOID)
{
	return mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON);
}

GB_VOID GB_WG_R_ImeDrawImeIcon(GB_INT x, GB_INT y,GB_INT width,GB_INT height)
{
	if (GB_WG_EditorType != GB_WG_IME_InputType_SMD_SINGLELINE && !GB_WG_R_ImeVKIsShowState())		// 当虚拟键盘出现或者在smartdial界面时不显示输入法图标zhangchenglong 2011-11-22
	{
		//  [6/2/2012 liangchuanhui]
//#ifndef GBWG_VIRTUAL_KEY
		if (!GB_WG_Get_isVirtual_key())
		{
			//mmi_imui_draw_ime_indicator(x, y, x + width-1, y + height-1);
			mmi_imc_draw_input_mode_hint(x, y, x + width-1, y + height-1);
		}

//#endif
	}
}


#ifdef __MMI_TOUCH_SCREEN__
//#ifndef GBWG_VIRTUAL_KEY//  [6/2/2012 liangchuanhui]
GB_INT GB_WG_R_ImeIconHandle(mmi_imc_editor_pen_event_struct_p evt)
{
	if (!GB_WG_Get_isVirtual_key())
	{

		if(evt->mmi_pen_event == MMI_PEN_EVENT_DOWN)
		{
			if (GB_WG_Ime_IsInImeIconRect(evt->pos.x , evt->pos.y))
			{
#ifndef __COSMOS_MMI_PACKAGE__			
#ifdef __MMI_GB__ 
				if (gbCurInputBox.pfChangeInputMode)
				{
					gbCurInputBox.pfChangeInputMode();
				}
#else
				ASSERT(0);
#endif
#endif
				//mmi_imc_key_change_input_mode();
				//			mmi_imc_key_handle_mode_change_key();
				//mmi_imc_key_send_message(MMI_IMC_MESSAGE_MODE_CHANGED, 0, 0);
				//mmi_imc_redraw_screen_by_state();
			}		
		}

		return 1;
	}

}
//#endif
#endif
//  [4/18/2012 liangchuanhui]
GB_INT GB_WG_R_ImeGetRectEx(GB_Rect *rect)
{
	rect->xPos = imui_rect.x;
	rect->yPos = imui_rect.y;
	rect->height = imui_rect.height;
	rect->width = imui_rect.width;
	return 1;
}
GB_BOOL GB_WG_R_IsImeGetRectOK(GB_Rect *rect)
{
 	if (!GB_WG_R_ImeCanShow())
 	{
 		return GB_TRUE;
 	}
	// fte状态时，虚拟键盘打开，不能重画虚拟键盘区域，因为系统有状态判断，在输入时它不会去显示虚拟键盘
#ifdef __MMI_FTE_SUPPORT__
	if (GB_WG_R_ImeVKIsShowState() && MMI_IMC_STATE_INITIAL != mmi_imc_get_state())
	{
		rect->yPos += 1;
		return GB_TRUE;
	}
#endif // __MMI_FTE_SUPPORT__
	return GB_FALSE;
}
// GB_INT GB_WG_R_ImeGetRect(GB_Rect *rect)
// {
//  	rect->xPos = imui_rect.x;
//  	rect->yPos = imui_rect.y;
//  	rect->height = imui_rect.height;
//  	rect->width = imui_rect.width;
// 	if (!GB_WG_R_ImeCanShow())
// 	{
// 		return 1;
// 	}
// 	// fte状态时，虚拟键盘打开，不能重画虚拟键盘区域，因为系统有状态判断，在输入时它不会去显示虚拟键盘
// #ifdef __MMI_FTE_SUPPORT__
// 	if (GB_WG_R_ImeVKIsShowState() && MMI_IMC_STATE_INITIAL != mmi_imc_get_state())
// 	{
// 		rect->yPos += 1;
// 		return 1;
// 	}
// #endif // __MMI_FTE_SUPPORT__
// 	GB_MEMSET(rect, 0, sizeof(*rect));
// 	return 1;
// }


static BOOL is_pos_in_rect(int x, int y, mmi_imc_rect * rect)
{
	return (x >= rect->x) && (x < rect->width + rect->x)
		&& (y >= rect->y) && (y < rect->height + rect->y);
}

static GB_INT GB_WG_HandlePenHandle(mmi_pen_event_type_enum event, GB_INT x, GB_INT y)
{
	GB_INT ret = 0;
	if (MMI_PEN_EVENT_DOWN == event)
	{
		GB_WG_HandlePen_Win(GBPEN_DOWN, x, y);
	}
	else if (MMI_PEN_EVENT_UP == event)
	{
		GB_WG_HandlePen_Win(GBPEN_UP, x, y);
	}
	else if (MMI_PEN_EVENT_MOVE == event)
	{
		GB_WG_HandlePen_Win(GBPEN_MOVE, x, y);
	}
	else if (MMI_PEN_EVENT_LONG_TAP == event)
	{
		GB_WG_HandlePen_Win(GBPEN_LONGTAP, x, y);
	}
	return ret;
}

static U32 ime_callback( void * handle, mmi_imc_message_struct_p msg)
{
	GB_INT ret = 0;
	ime_msg_unimplemented(msg);
	switch (msg->message_id)
	{
	case MMI_IMC_MESSAGE_INSERT_STRING_NO_DRAW:
	case MMI_IMC_MESSAGE_INSERT_STRING:
		{
			
			ret = GB_WG_Ime_EditorInsertString((unsigned short*)msg->param_0);
			GB_WG_CancelSMDNumInputStat();
			return ret;
			//			return opera_ime_insert_string((unsigned short*)msg->param_0);	
		}    
	case MMI_IMC_MESSAGE_INSERT_CHAR:
		{
			//TODO beep if full, return TRUE if insert success
			unsigned short insertstring[2] = {0};
			insertstring[0] = msg->param_0;
			ret = GB_WG_Ime_EditorInsertString(insertstring);
			GB_WG_CancelSMDNumInputStat();
			return ret;
			//			return opera_ime_insert_char((unsigned short)msg->param_0);
		} 
	case MMI_IMC_MESSAGE_INSERT_NEW_LINE:
		{
			
			ret = GB_WG_Ime_EditorInsertString(L"\n"); 
			GB_WG_CancelSMDNumInputStat();
			return ret;
			//			return opera_ime_insert_char((unsigned short)'\n');		
		} 
	case MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR:
		{
			unsigned short insertstring[2] = {0};
			insertstring[0] = msg->param_0;
			ret = GB_WG_Ime_EditorInsertString(insertstring);
			GB_WG_CancelSMDNumInputStat();
			return ret;
			//return if insert success
			//			return opera_ime_insert_multitap_char((unsigned short)msg->param_0);
		} 
	case MMI_IMC_MESSAGE_INSERT_MULTITAP_STRING:
		{
			
			ret = GB_WG_Ime_EditorInsertString((unsigned short*)msg->param_0);
			GB_WG_CancelSMDNumInputStat();
			return ret;
			//return number of inserted chars
			//			return opera_ime_insert_multitap_string((unsigned short*)msg->param_0);
		} 
	case MMI_IMC_MESSAGE_DELETE_CHAR:
		{
			// radraw 
			return GB_WG_Ime_EditorDeleteAChar();
			//			return opera_ime_delete_string((int)msg->param_0);
		} 
	case MMI_IMC_MESSAGE_DELETE_STRING:
		{
			int i = (int)msg->param_0;
			int ret = 1;
			for(; i > 0 && ret > 0; i--)
			{
				ret = GB_WG_Ime_EditorDeleteAChar();
			}
			return ret;
			//param_1 :0: redraw immediately
			//         1: not redraw
			// opera always redraw
			//			return opera_ime_delete_string((int)msg->param_0);
		} 
	case MMI_IMC_MESSAGE_CLEAR_ALL:
		{
			//			opera_ime_clear_all();
			GB_WG_Ime_EditorAllChar();
			return 0;
		} 
	case MMI_IMC_MESSAGE_CLEAR_HILIGHT:
		{
			//no redraw, but opera always redraw
			//			return opera_ime_clear_hilight();
			GB_WG_Ime_CancelSelect();
			return 1;
		} 
	case MMI_IMC_MESSAGE_MOVE_CURSOR_TO_HIGHLIGHT_START:
		{
			//			return opera_ime_move_cursor_to_highlight_start();
		}
	case MMI_IMC_MESSAGE_MOVE_CURSOR:
		{
			//redraw
			//			return opera_ime_move_cursor((OPDEV_MMI_IMC_EDITOR_CUSOR_MOVE_DIRECTION_ENUM)msg->param_0, (int)msg->param_1);
			if (msg->param_0 == MMI_IMC_EDITOR_CURSOR_LEFT)
			{
				GB_WG_Ime_MoveCursorLeft();
			}
			else if (msg->param_0 == MMI_IMC_EDITOR_CURSOR_RIGHT)
			{
				GB_WG_Ime_MoveCursorRight();
			}
		} 
	case MMI_IMC_MESSAGE_HILIGHT_BFCURSOR:
		{
			//param_1 :no use
			//			return opera_ime_set_hilight(OPDEV_MMI_IMC_EDITOR_CURSOR_LEFT,(int)msg->param_0, 0);
			return 0;
		} 
	case MMI_IMC_MESSAGE_GET_INPUT_BOX_RECT:
		{
			GB_Rect rect;
			mmi_imc_rect *pRect = (mmi_imc_rect*)msg->param_0;
			GB_WG_Ime_GetEditorRect(&rect);
			pRect->x = rect.xPos;
			pRect->y = rect.yPos;
			pRect->width = rect.width;
			pRect->height = rect.height;
			return 1;
			//			return opera_ime_get_input_box_rect(&(rect->x), &(rect->y), &(rect->width), &(rect->height));
		} 
	case MMI_IMC_MESSAGE_GET_HANDWRITING_RECT:
		{	//just for FULLSCREEN_HANDWRITING
			//opera just use MULTI-BLOCK
			//opera return editor rect.
			//For fullscreen, start point of handwriting must in editor area
			mmi_imc_rect *rect = (mmi_imc_rect*)msg->param_0;
			return GB_WG_Ime_GetEditorRect((GB_Rect*)rect);
		} 
	case MMI_IMC_MESSAGE_GET_HANDWRITING_STYLE:
		{
			return 0;
#ifdef  __MMI_HANDWRITING_MULTI_BLOCK__
			//			return (U32)MMI_IMC_PEN_HANDWRITING_STYLE_MULTI_BLOCK;
#else
			//			return (U32)MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN;
#endif
		} 
	case MMI_IMC_MESSAGE_RESET_MULTITAP_STATE:
		{
			GB_WG_Ime_CancelSelect();
			return 0;
			//			opera_ime_set_smart_alphabetic_state(0);
			//			return opera_ime_set_multitap_state(0);
		} 
	case MMI_IMC_MESSAGE_RESIZE:
		{
			return GB_WG_Ime_ResizeEditor(msg->param_0, msg->param_1);
			//			return  opera_ime_set_editor_wh(msg->param_1, msg->param_0);
		} 
	case MMI_IMC_MESSAGE_MOVE:
		{
			return 0;
			//			return  opera_ime_set_editor_xy(msg->param_0, msg->param_1);
		} 
	case MMI_IMC_MESSAGE_REDRAW:
		{
			gdi_layer_push_clip();
			gdi_layer_set_clip(0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT);
			GB_WG_Ime_ShowContext();
			gdi_layer_pop_clip();
			return 0;
		} 
	case MMI_IMC_MESSAGE_UPDATE_SOFTKEY:
		{
			return 1;
		}
	case MMI_IMC_MESSAGE_KEY_EVENT:
		{
			return ime_msg_unimplemented(msg);
		} 
#ifdef __MMI_TOUCH_SCREEN__
	case MMI_IMC_MESSAGE_PEN_EVENT:
		{
			unsigned int ret=0;
			static BOOL need_wg_handle = FALSE;
			mmi_imc_editor_pen_event_struct_p evt = (mmi_imc_editor_pen_event_struct_p)msg->param_0;
			GB_Rect editorRect = {0};
			GB_INT in_editor_rect = 0;
			if(evt->mmi_pen_event == MMI_PEN_EVENT_DOWN)
			{
				// check if in imui area or ime hint area
				need_wg_handle = TRUE;
				if(is_pos_in_rect(evt->pos.x , evt->pos.y, &imui_rect))
				{
					need_wg_handle = FALSE;
				}
				else
				{
// #ifndef GBWG_VIRTUAL_KEY				
					//pen事件点击在右软键,当键盘输入候选框显示的时候，要让输入法自己去隐藏，所以在这里设置need_wg_handle = FALSE来阻止GB_WG_HandlePenHandle的调用;modify by zhangchenglong 2011_11_10
					mmi_imc_rect softkey_rect = {0};//{0, GB_WG_GetScrH()-gb_wg_get_bottombar_hight(), GB_WG_GetScrW(), gb_wg_get_bottombar_hight()};
					softkey_rect.x = 0;
					softkey_rect.y = GB_WG_GetScrH()-gb_wg_get_bottombar_hight();
					softkey_rect.width = GB_WG_GetScrW();
					softkey_rect.height = gb_wg_get_bottombar_hight(); 
					if(is_pos_in_rect(evt->pos.x , evt->pos.y, &softkey_rect) && 
						!(GB_WG_HandleKey == GetKeyHandler(KEY_RSK, KEY_EVENT_DOWN) && GB_WG_HandleKey == GetKeyHandler(KEY_RSK, KEY_EVENT_UP)))
					{
						need_wg_handle = FALSE;
					}
// #else
// 					need_wg_handle = TRUE;
// #endif					
				}
			}
			// 			//For PEN_EVENT_UP/ABORT, inherit flag(need_opera_handle) from PEN_EVENT_DOWN
			if(!need_wg_handle)
			{
				ret = 0;
			}
			else 
			{
				GB_WG_HandlePenHandle(evt->mmi_pen_event, evt->pos.x, evt->pos.y);
				//  [6/2/2012 liangchuanhui]
				if (GB_WG_Get_isVirtual_key())
				{
					ret = 1;
				}
				else
				{
					ret = GB_WG_R_ImeIconHandle(evt);
				}
// #ifdef GBWG_VIRTUAL_KEY
// 				ret = 1;
// #else
// 				ret = GB_WG_R_ImeIconHandle(evt);
// #endif
				
			}
			GB_WG_Ime_GetEditorRect(&editorRect);
			in_editor_rect = is_pos_in_rect(evt->pos.x, evt->pos.y, (mmi_imc_rect*)&editorRect);
			if(evt->mmi_pen_event == MMI_PEN_EVENT_DOWN 
				|| evt->mmi_pen_event == MMI_PEN_EVENT_LONG_TAP)
			{
				*(U32*)msg->param_1 = in_editor_rect;
			}
			else if(evt->mmi_pen_event == MMI_PEN_EVENT_UP)
			{
				msg->param_1 = in_editor_rect;
			}
			return ret;
		} 
#endif
	case MMI_IMC_MESSAGE_MODE_CHANGED:
		{
#ifndef __COSMOS_MMI_PACKAGE__
#if defined(__MMI_GB__)
			GB_WG_ResetGBIMEHandle();
#endif
#endif // __COSMOS_MMI_PACKAGE__
			//notification
			return 0;
		} 
	case MMI_IMC_MESSAGE_CHANGE_TO_INITIAL:
		{
			//Notification: INITIAL state: not multitap state
			GB_WG_SMDNumInputSetInitial();
			return 0;
		} 
	case MMI_IMC_MESSAGE_GET_TEXT:
		{
			return ime_msg_unimplemented(msg),0;
		} 
	case MMI_IMC_MESSAGE_GET_TEXT_LENGTH:
		{
			//			return opera_ime_get_text_length();
		}
	case MMI_IMC_MESSAGE_IS_EDITOR_EMPTY:
		{
			return GB_WG_Ime_EditorIsEmpty();
			//			return opera_ime_is_editor_empty();
		} 
	case MMI_IMC_MESSAGE_INSERT_SPELLING_DIRECTLY:
		{
			return ime_msg_unimplemented(msg),0;
		} 
	case MMI_IMC_MESSAGE_GET_PREVIOUS_CHAR:
		{
			//UI_character_type buf[2];
			//unsigned int ret=0;
			//*(UI_character_type *)msg->param_0 = 0;
			//// 			ret = opera_ime_get_string_before_caret(buf, 1);
			//// 			*(UI_character_type *)msg->param_0 = buf[0];
			//return ret;

			unsigned int ret=0;
			U16 *ptext = NULL;
			*(UI_character_type *)msg->param_0 = 0;
			GB_WG_Ime_GetText(&ptext);
			if(ptext)
			{
				GB_UINT nPos;
				GB_WG_Ime_GetCursorPos(&nPos);
				if(nPos > 0)
				{
					*(UI_character_type *)msg->param_0 = ptext[nPos-1];
				}
				ret = 1;
			}
			return ret;
		} 
	case MMI_IMC_MESSAGE_GET_STRING_BEFORE_CANDIDATE:
		{
			unsigned int i=0;
			UI_string_type  buf = (UI_string_type) msg->param_1;
			U16 *ptext = NULL;
			GB_UINT nPos;
			GB_WG_Ime_GetText(&ptext);
			GB_WG_Ime_GetCursorPos(&nPos);
			if (ptext)
			{
				int len = (msg->param_0 <= nPos ? msg->param_0 : nPos);
				for (i = 0; i < len; i++)
				{
					buf[i] = ptext[nPos-len+i];
				}
			}
			return i;
			//			return opera_ime_get_string_before_candidate(buf, (int)msg->param_0);
		} 
	case MMI_IMC_MESSAGE_HIDE_MULTITAP_CANDIDATE_BOX:
		{
			//show candidate box when in multitap state

			// 当键盘版SMD状态时，不显示系统候选框 [lzp 2012-2-28]
			//  [6/2/2012 liangchuanhui]
		//#ifndef GBWG_VIRTUAL_KEY	
	
			if(!GB_WG_Get_isVirtual_key() && (GB_WG_EditorType==GB_WG_IME_InputType_SMD_SINGLELINE))
			{
				return 1;
			}
			else
		//#endif
			return ime_msg_unimplemented(msg),0;
		} 
	case MMI_IMC_MESSAGE_INSERT_CHAR_AT_DESIRED_POSITION:
		{
			return ime_msg_unimplemented(msg);
			//return opera_ime_insert_char_at((int)msg->param_0, (unsigned short)msg->param_1);			
		} 
	case MMI_IMC_MESSAGE_DELETE_CHAR_AT_DESIRED_POSITION:
		{
			return ime_msg_unimplemented(msg);
			//return opera_ime_delete_char_at((int)msg->param_0);
		} 
	case MMI_IMC_MESSAGE_GET_CHAR_AT_DESIRED_POSITION:
		{
			return ime_msg_unimplemented(msg);
			//return opera_ime_get_char_at((int)msg->param_0);			
		} 
	case MMI_IMC_MESSAGE_SET_KEY:
		{
			//			opera_ime_set_keys();
//#ifndef GBWG_VIRTUAL_KEY
			GB_WG_RegisterControlKeyHandle();		//modify by zhangchenglong 2011_11_10
//#endif
			return 0;
		} 
	case MMI_IMC_MESSAGE_SET_MULTITAP_STATE:
		{
			
			return 0;
			//return opera_ime_set_multitap_state(1);
		} 
	case MMI_IMC_MESSAGE_SET_MASK:
		{
			return ime_msg_unimplemented(msg);
		} 
	case MMI_IMC_MESSAGE_INSERT_SPACE:
		{
			//			return opera_ime_insert_char((unsigned short)' ');
		} 
	case MMI_IMC_MESSAGE_DRAW_INFORMATION_BAR:
		{
			//we don't draw information bar
			return 0;
		} 
	case MMI_IMC_MESSAGE_DRAW_IME_HINT:
		{
			return 0;
			//			return OpDev_ImeDrawImeHint();
		} 
	case MMI_IMC_MESSAGE_IS_SOFTKEY_HIDE:
		{
			//  [6/2/2012 liangchuanhui]
			if (!GB_WG_Get_isVirtual_key())
			{
				if ((!GB_WG_PlatIme_is_vk_disabled()&& mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON)) || 
					(!mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON) /*&& GB_WG_GuobiCandIsShow()*/)) // by yyk
				{
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else
			{
				if (mmi_imc_get_state() != MMI_IMC_STATE_INITIAL) // mmi_imc_get_state != MMI_IMC_STATE_INITIAL 判断其是否有输入，有输入时才需要使用系统左右软件
				{
					SetKeyHandler(left_softkey_down, KEY_ENTER, KEY_EVENT_DOWN);
					SetKeyHandler(left_softkey_up, KEY_ENTER, KEY_EVENT_UP); 
					return 0;
				}
				else 
				{
					update_softkey_state_no_redraw(KEY_RSK, KEY_EVENT_UP);
					set_softkey_label(GB_WG_Ime_GetRightSoftKeyString(), MMI_RIGHT_SOFTKEY);
					set_softkey_icon(NULL,MMI_RIGHT_SOFTKEY);
					if((int)msg->param_0 == 0xff)
					  return 0xff;
					else
            return 1; 
				}
			}

// #ifndef GBWG_VIRTUAL_KEY		
// 			if ((!GB_WG_PlatIme_is_vk_disabled()&& mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON)) || 
// 				(!mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON) && GB_WG_GuobiCandIsShow()))
// 			{
// 				return 0;
// 			}
// 			else 
// 			{
// 				return 1;
// 			}
// #else
// 			if (!GB_WG_PlatIme_is_vk_disabled() && mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON) && mmi_imc_get_state() != MMI_IMC_STATE_INITIAL) // mmi_imc_get_state != MMI_IMC_STATE_INITIAL 判断其是否有输入，有输入时才需要使用系统左右软件
// 			{
// 				return 0;
// 			}
// 			else 
// 			{
// 				return 1;
// 			}
// 
// #endif			
			// return 1;
			
		} 
	case MMI_IMC_MESSAGE_CHECK_CSK_ENABLE:
		{
			//by mtk, the future input method don't use csk 
			return 0;
		} 
	case MMI_IMC_MESSAGE_CHECK_INFO_BAR_ENABL:
		{
			//don't draw information bar
			return 0;
		} 
	case MMI_IMC_MESSAGE_CHECK_MULTITAP_STATE:
		{
			return 0;
			//			return opera_ime_get_multitap_state();
		} 
	case MMI_IMC_MESSAGE_START_SMART_ALPHABETIC:
		{
			//TODO, need detail discuss, start input, need to remember some infomation
			//			opera_ime_set_smart_alphabetic_state(1);
			// 需要修改 lzp
// 			if (!GB_WG_Ime_IsSelectState())
// 			{
// 				GB_WG_Ime_StartSelect();
// 			}
			return 0;
		} 
	case MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC:
		{
			//TODO, need detail discuss
			//			opera_ime_set_smart_alphabetic_state(0);
			// 需要修改 lzp
			//GB_WG_Ime_CancelSelect();
			return 0;
		} 
	case MMI_IMC_MESSAGE_WCSS_CHECK:
		{
			//opera don't support
			return ime_msg_unimplemented(msg);
		} 
	case MMI_IMC_MESSAGE_IS_LAST_POSITION:
		{
			return ime_msg_unimplemented(msg);
		} 
	case MMI_IMC_MESSAGE_IS_OVERWRITE_MODE:
		{
			return 0;
		} 
	case MMI_IMC_MESSAGE_GET_TEXT_PTR_BEFORE_CANDIDATE:
		{
			//p0,p1 U8**
			//TODO, support auto_capitalization
			//*(U8**)(msg->param_0)=0;
			// *(U8**)(msg->param_1)=0; 
			// 			opera_ime_get_text_ptr_before_candidate(
			// 				(U16**)(msg->param_0), (U16**)(msg->param_1));
			ime_msg_unimplemented(msg);
			return 0;
		} 
	case MMI_IMC_MESSAGE_GET_EDITOR_SCROLL_BAR_WIDTH:
		{
			//hard to get width from webpage
			return 0;
		}
	case MMI_IMC_MESSAGE_GET_TEXT_PTR_BEFORE_CURSOR:
		{
			U16 *ptext = NULL;
			GB_UINT nPos;

			GB_WG_Ime_GetText(&ptext);
			(*(U16**)(msg->param_0)) = ptext;
			(*(U16**)(msg->param_1)) = NULL;
			if(ptext)
			{
				GB_WG_Ime_GetCursorPos(&nPos);
				(*(U16**)(msg->param_1)) = ptext+nPos;
			}
			return 1;
		}
	case MMI_IMC_MESSGAE_IS_WRITING_LANG_SELECTION_SCREEN_DISABLED:
		{
#if defined(__MMI_REDUCED_KEYPAD__) && !defined(__MMI_FTE_SUPPORT__)              // no writing lang selection screen
			return 1;
#else
			return 0;
#endif
		} 
	case MMI_IMC_MESSGAE_GET_EXT_INPUT_BOX_RECT:
		{
			// get rect except for ime hint/imui+softkey area
			mmi_imc_rect *rect = (mmi_imc_rect*)msg->param_0;
			// 			rect->x = 0;
			// 			rect->y = ime_hint_rect.y + ime_hint_rect.height;
			// 			rect->width = GetUiWidth();
			// 			rect->height = imui_rect.y - rect->y;
		} 
	case MMI_IMC_MESSAGE_IS_THERE_CURSOR:
		{
			return 1;
		} 
	case MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING:
		{
			// 			return opera_ime_insert_multitap_string((unsigned short*)msg->param_1?
			// 				(unsigned short*)msg->param_1 : L"");
			
			GB_WG_CancelSMDNumInputStat();
			if (!GB_WG_Ime_IsSelectState())
			{
				GB_WG_Ime_StartSelect();
			}
			return GB_WG_Ime_EditorInsertString((unsigned short*)msg->param_1?(unsigned short*)msg->param_1 : L"");
		} 
	case MMI_IMC_MESSAGE_GET_HIGHLIGHT_WORD:
		{
			return 1;
			//			return opera_ime_get_highlight_word((U16**)msg->param_0, (U16**)msg->param_1);
		} 
	case MMI_IMC_MESSAGE_IS_LOCK_GDI_FRAME_BUFFER_DISABLED:
		{
			// here return 0, to avoid dirty screen 
			return 0;
		} 
	case MMI_IMC_MESSAGE_INSERT_PAIRED_SYMBOLS:
		{
			//p0: string address, move one left
			//return if success
			// 			opera_ime_insert_string((unsigned short*)msg->param_0);
			// 			opera_ime_move_cursor(OPDEV_MMI_IMC_EDITOR_CURSOR_LEFT, 1);
			return 1;
		} 
	case MMI_IMC_MESSAGE_IS_BACKSPACE_DISABLED:
		{
			return 0;			
		} 
	case MMI_IMC_MESSAGE_IS_AUTO_CLEAR_HIGHLIGHT_WORD_MODE:
		{
			//return if (1) in auto clear highlight mode && (2) need to replace highlight string
			//include user manual selected highlight
			//			return opera_ime_has_highlight();
			return 0;
		} 
	case MMI_IMC_MESSAGE_IMUI_RECTANGLE_IS_UPDATED:
		{
			int relayout=0;
			mmi_imc_rect * rect = (mmi_imc_rect*)msg->param_0;
			GB_WG_PlatImeSetImeRect(rect->x, rect->y, rect->width, rect->height);

			
			if (GB_WG_R_ImeVKIsShowState())
			{
				imui_rect.y += 1;
			}
			return relayout;
		} 
	case MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW:
		{
			return ime_msg_unimplemented(msg), 1;
		} 
	case MMI_IMC_MESSAGE_GET_CURSOR_RECT:
		{
			// return if success
			GB_Rect gb_rect;
			mmi_imc_rect *rect = (mmi_imc_rect*)msg->param_0;
			GB_WG_Ime_GetEditorRect(&gb_rect);
			rect->x = gb_rect.xPos;
			rect->y = gb_rect.yPos;
			rect->width = gb_rect.width;
			rect->height = gb_rect.height + 10;
			
			//			return opera_ime_get_caret_position(&(rect->x), &(rect->y), &(rect->width), &(rect->height));
		}
	case MMI_IMC_MESSAGE_FLOATING_UI_APPEAR_INDICATION:
		{
			// indicate floating ui will appear, from invisible to visible
		}
	case MMI_IMC_MESSAGE_CLIPBOARD_IS_DISABLE:
		{
			return 1;
		}
	case MMI_IMC_MESSAGE_GET_STOP_CURSOR_CALLBACK_FUNCPTR:
		{
			//			return (U32)opera_ime_stop_cursor_cb;
		}
	case MMI_IMC_MESSAGE_GET_START_CURSOR_CALLBACK_FUNCPTR:
		{
			//			return (U32)opera_ime_start_cursor_cb;
		}
	case MMI_IMC_MESSAGE_HAS_SSP_ACTED:
		{
			return 0;
		}
	case MMI_IMC_MESSAGE_VK_HIDE:
		{
			
			GB_WG_VK_is_show = GB_FALSE;
			GB_WG_Ime_VkHide_CallBack(GB_FALSE);
			return 0;
		}
	default: 
		return ime_msg_unimplemented(msg);
	}

	return 0;
}

void ime_background_filler(S32 x1, S32 y1, S32 x2, S32 y2)
{
	GB_WG_Ime_ShowImeBackground(x1, y1, x2, y2);
}

void ime_softkey_background_filler(S32 x1, S32 y1, S32 x2, S32 y2)
{
	gdi_layer_push_clip();
	gdi_layer_set_clip(x1-1, y1, x2+1, y2);

	GB_WG_Ime_ShowSoftKeyBackUp();

	gdi_layer_pop_clip();
}


static void InitImeState()
{
	
}

void internal_set_input_type(GB_INT editorType, GB_INT inputType)
{
	U32 input_type = IMM_INPUT_TYPE_SENTENCE;

	mmi_imm_input_mode_enum histroy_input_mode = IMM_INPUT_MODE_NONE;
	//	int constraint_type = CONSTRAINT_ALPHANUMERIC;

	//workaround, since just alphanumeric can be password. SEE bug 
	// 	if ((ime_state.constraints & CONSTRAINT_PASSWORD)  && (constraint_type == CONSTRAINT_ANY ))
	// 	{
	// 		constraint_type = CONSTRAINT_ALPHANUMERIC;
	// 	}

	InitImeState();
	GB_WG_EditorType = editorType;
	switch (inputType)
	{
	case GB_WG_IME_InputType_SENTENCE:
		input_type = IMM_INPUT_TYPE_SENTENCE; 
		break;

	case GB_WG_IME_InputType_ASCII_CHAR: 
		input_type = IMM_INPUT_TYPE_ASCII_CHAR; 
		break;
	case GB_WG_IME_InputType_ALPHANUMERIC: 
		input_type = IMM_INPUT_TYPE_ENGLISH_SENTENCE;
		break;

	case GB_WG_IME_InputType_NUMERIC: 
		input_type = IMM_INPUT_TYPE_NUMERIC; 
		break;
	case GB_WG_IME_InputType_EMAIL: 
		input_type = IMM_INPUT_TYPE_EMAIL; 
		break;
		/** Phone number. */
	case GB_WG_IME_InputType_PHONE_NUMBER: 
		input_type = IMM_INPUT_TYPE_PHONE_NUMBER;
		break;
		/** URL. */
	case GB_WG_IME_InputType_URL: 
		input_type = IMM_INPUT_TYPE_URL; 
		break;
	case GB_WG_IME_InputType_QUICK_SEARCH:
		input_type = IMM_INPUT_TYPE_PHONE_NUMBER;
		break;
	}

	if (editorType == GB_WG_IME_InputType_PASSWORD) 
	{
		input_type = IMM_INPUT_TYPE_NUMERIC;
		input_type |= IMM_INPUT_TYPE_EXT_PASSWORD;
	}//  [6/2/2012 liangchuanhui]
	else if(!GB_WG_Get_isVirtual_key() && editorType==GB_WG_IME_InputType_SMD_SINGLELINE)
	{
		input_type = IMM_INPUT_TYPE_PHONE_NUMBER;
	}
// #ifndef GBWG_VIRTUAL_KEY	
// 	else if(editorType == GB_WG_IME_InputType_SMD_SINGLELINE)
// 	{
// 		input_type = IMM_INPUT_TYPE_PHONE_NUMBER;
// 	}
// #endif
	if (editorType == GB_WG_IME_InputType_MULTILINE)
	{
		mmi_imm_set_editor_type(MMI_IME_EDITOR_TYPE_MULTILINE);
		wgui_inputs_get_editor_handler()->input_box_type = MMI_EDITOR_MULTILINE_INPUT_BOX;
		wgui_inputs_get_editor_handler()->input_box_sub_type = MMI_EDITOR_INLINE_MULTILINE_INPUT_BOX;
	}
	else 
	{
		mmi_imm_set_editor_type(MMI_IME_EDITOR_TYPE_SINGLELINE);
		wgui_inputs_get_editor_handler()->input_box_type = MMI_EDITOR_SINGLE_LINE_INPU_BOX;
		wgui_inputs_get_editor_handler()->input_box_sub_type = MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX;
	}

	

	mmi_imm_config_first_uppercase_input_modes(MMI_FALSE); /* Jun add for disable auto-capitalization */
// 	if(input_type & IMM_INPUT_TYPE_SENTENCE)
// 	{
// 		input_type |=IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE;
// 		input_type &= ~IMM_INPUT_TYPE_SENTENCE;
// 	}
//  [6/2/2012 liangchuanhui]
// 	if (!GB_WG_Get_isVirtual_key())
// 	{
// 		mmi_imm_set_required_mode_list(input_type, 0, 0);
// 	}
// 	else
// 	{
// 		if (editorType == GB_WG_IME_InputType_SMD_SINGLELINE)
// 		{
// 			const static mmi_imm_input_mode_enum pInputArry[] = {
// 				IMM_INPUT_MODE_SM_PINYIN, 
// 				IMM_INPUT_MODE_SM_STROKE, 
// 				IMM_INPUT_MODE_SMART_LOWERCASE_ABC, 
// 				IMM_INPUT_MODE_SMART_UPPERCASE_ABC, 
// 				IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC, 
// 				IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC, 
// 				IMM_INPUT_MODE_PHONE_NUMBER, 
// 				IMM_INPUT_MODE_NONE};
// 				mmi_imm_set_required_mode_list(IMM_INPUT_TYPE_USER_SPECIFIC, (mmi_imm_input_mode_enum*)pInputArry, IMM_INPUT_MODE_NONE);
// 		}
// 		else
// 		{
// 			mmi_imm_set_required_mode_list(input_type, NULL, IMM_INPUT_MODE_NONE);
// 		}
// 	}
	mmi_imm_set_required_mode_list(input_type&INPUT_TYPE_MASK, NULL, IMM_INPUT_MODE_NONE);

// #ifndef GBWG_VIRTUAL_KEY
// 	mmi_imm_set_required_mode_list(input_type, 0, 0);
// #else
// 	if (editorType == GB_WG_IME_InputType_SMD_SINGLELINE)
// 	{
// 		const static mmi_imm_input_mode_enum pInputArry[] = {
// 												IMM_INPUT_MODE_SM_PINYIN, 
// 												IMM_INPUT_MODE_SM_STROKE, 
// 												IMM_INPUT_MODE_SMART_LOWERCASE_ABC, 
// 												IMM_INPUT_MODE_SMART_UPPERCASE_ABC, 
// 												IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC, 
// 												IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC, 
// 												IMM_INPUT_MODE_PHONE_NUMBER, 
// 												IMM_INPUT_MODE_NONE};
// 		mmi_imm_set_required_mode_list(IMM_INPUT_TYPE_USER_SPECIFIC, (mmi_imm_input_mode_enum*)pInputArry, IMM_INPUT_MODE_NONE);
// 	}
// 	else
// 	{
// 		mmi_imm_set_required_mode_list(input_type, NULL, IMM_INPUT_MODE_NONE);
// 	}
// #endif	
	//mmi_imc_disable_handwriting();
	//int fixed = 1;
	//if(fixed)mmi_imc_set_fixed_input_box();
}


// smd界面拼音状态下也可以搜数字功能 [11/16/2011 lzp]
/************************************************************************************************/
/************************************************************************************************/
static GB_BOOL GB_WG_IsInSmdNumIputStat = 0;
static GB_BOOL GB_WG_ISKeyStat = 0;

// static GB_BOOL GB_WG_SMDNumInputHandler(GBKeyEvent keyEvent, GBKeyValue keyValue)
// {
// 	GB_WCHAR inputChar = 0;
// 	if(GBKEY_PRESS == keyEvent)
// 	{
// 		switch(keyValue)
// 		{
// 		case GB_WG_KEY_0:		
// 		case GB_WG_KEY_1:
// 		case GB_WG_KEY_2:
// 		case GB_WG_KEY_3:
// 		case GB_WG_KEY_4:
// 		case GB_WG_KEY_5:
// 		case GB_WG_KEY_6:
// 		case GB_WG_KEY_7:
// 		case GB_WG_KEY_8:
// 		case GB_WG_KEY_9:	
// 			inputChar = (keyValue-GB_WG_KEY_0) + '0';
// 			break;
// 		case GB_WG_KEY_STAR:
// 			
// 			inputChar = '*';
// 			GB_WG_Ime_StartSelect();
// 
// 			break;
// 		case GB_WG_KEY_POUND:
// 			inputChar = '#';
// 				break;
// 		}
// 	}
// 	if (inputChar)
// 	{
// // 		if (!GB_WG_Ime_IsSelectState())
// // 		{
// // 			GB_WG_Ime_StartSelect();
// // 		}
// 		unsigned short insertstring[2] = {0};
// 		insertstring[0] = inputChar;
// 		return GB_WG_Ime_EditorInsertString(insertstring);
// 		GB_WG_IsInSmdNumIputStat = 1;
// 		return GB_TRUE;
// 	}
// 	return GB_FALSE;
// }

static GB_VOID GB_WG_CancelSMDNumInputStat()
{
	if (GB_WG_IsInSmdNumIputStat)
	{
 		GB_WG_Ime_CancelSelect();
		GB_WG_IsInSmdNumIputStat = 0;
	}
	GB_WG_ISKeyStat = 0;
}




static GB_VOID GB_WG_ClearSMDNumInput(GB_VOID)
{
	if (GB_WG_IsInSmdNumIputStat)
	{
		if (GB_WG_Ime_IsSelectState())
		{
			GB_WG_Ime_EditorDeleteAChar();
		}
		GB_WG_CancelSMDNumInputStat();
	}
}

static GB_VOID GB_WG_SMDNumInputSetInitial(GB_VOID)
{
	if (GB_WG_ISKeyStat)
	{
		GB_WG_ClearSMDNumInput();
	}
	else
	{
		GB_WG_CancelSMDNumInputStat();
	}
}

GB_VOID GB_WG_SetInputCandString(GB_WCHAR *pCnadstring)
{
	if (GB_WG_Is_In_Winguo())
	{
		if (GB_WG_EditorType == GB_WG_IME_InputType_SMD_SINGLELINE)
		{
			if (pCnadstring && *pCnadstring)
			{
				GB_WG_IsInSmdNumIputStat = 1;
				if (!GB_WG_Ime_IsSelectState())
				{
					GB_WG_Ime_StartSelect();
				}
				GB_WG_Ime_EditorInsertString(pCnadstring);
			}
			else
			{
				GB_WG_ClearSMDNumInput();
			}
		}
	}
}


static MMI_BOOL GB_WG_ime_pre_key_handler(U16 keycode, U16 keytype)
{
// 	if (GB_WG_EditorType == GB_WG_IME_InputType_SMD_SINGLELINE)
// 	{
// 		GBKeyEvent keyEvent;
// 		GBKeyValue keyValue;
// 
// 		if (keytype == KEY_EVENT_DOWN)
// 		{
// 			GB_WG_ISKeyStat = 1;
// 		}
// 		else if (keytype == KEY_EVENT_UP)
// 		{
// 			GB_WG_ISKeyStat = 0;
// 		}
// //		#ifndef GBWG_VIRTUAL_KEY
// 		else if (keytype == KEY_LONG_PRESS)
// 		{
// 			
// #if defined(__MMI_MULTITAP_KEY_0__)
// 			if (keycode == MMI_IMC_KEY_SYM_0)
// 			{
// 				return 0;
// 			}
// #endif
// 			GB_WG_Dial_LongPress_Handle_ext(ime_get_editerText(), GetKeyValueFromPlat(keycode));
// 			return 1;
// 		}
//		#endif
// 		keyEvent = GetKeyEventFromPlat(keytype);
// 		keyValue = GetKeyValueFromPlat(keycode);
// 		if (!GB_WG_SMDNumInputHandler(keyEvent, keyValue))
// 		{
// 			GB_WG_HandleKey_Win(keyEvent, keyValue);
// 		}
//	}
	return 0;
}
/************************************************************************************************/
/************************************************************************************************/


static void null_handler(void)
{
}
static void lsk_handler(void)
{
	//Force close context menu, if has context menu , return TRUE, other return FALSE
	// 	if(!opera_ime_close_context_menu_if_exist(1))
	// 		ime_state.lsk_func();
}
static void rsk_up_handler(void)
{
	// 	if(ignore_pending_rsk_up_event) 
	// 	{
	// 		ignore_pending_rsk_up_event = 0;
	// 		return ;
	// 	}
	// 	if(!opera_ime_close_context_menu_if_exist(1))
	// 		ime_state.rsk_func();   //ime_state.rsk_func must NOT be NULL
}
static void rsk_long_press_handler(void)
{
	// 	if(!opera_ime_close_context_menu_if_exist(1))
	// 		ime_state.rsk_long_press_func(); //ime_state.rsk_long_press_func must NOT be NULL
}
static void rsk_down_handler(void)
{
	// 	ignore_pending_rsk_up_event = 0;
	// 	mmi_imc_set_softkey_function(null_handler,        KEY_EVENT_DOWN, MMI_IME_RIGHT_SOFTKEY );
	// 	mmi_imc_set_softkey_function(rsk_up_handler, KEY_EVENT_UP, MMI_IME_RIGHT_SOFTKEY);
}
static void set_key_handler_for_lsk_down(void)
{
	// 	mmi_imc_set_softkey_function(null_handler,        KEY_EVENT_DOWN, MMI_IME_LEFT_SOFTKEY );
	// 
	// 	mmi_imc_set_softkey_function(lsk_handler, KEY_EVENT_UP, MMI_IME_LEFT_SOFTKEY);
}
void GB_WG_registerKeyHandlerForIME()
{
	mmi_imc_set_softkey_function(rsk_down_handler, KEY_EVENT_DOWN, MMI_IME_RIGHT_SOFTKEY);

	//mmi_imc_set_softkey_function(set_key_handler_for_lsk_down, KEY_EVENT_DOWN, MMI_IME_LEFT_SOFTKEY);

	mmi_imc_set_softkey_function(null_handler, KEY_EVENT_DOWN, MMI_IME_LEFT_SOFTKEY);
	mmi_imc_set_softkey_function(lsk_handler, KEY_EVENT_UP, MMI_IME_LEFT_SOFTKEY);

	mmi_imc_set_softkey_function((FuncPtr)rsk_long_press_handler, KEY_LONG_PRESS, MMI_IME_RIGHT_SOFTKEY);
	// 	mmi_imc_set_softkey_label((UI_string_type)ime_state.rsk_text, MMI_IME_RIGHT_SOFTKEY);
	// 
	// 	mmi_imc_set_softkey_label((UI_string_type)ime_state.lsk_text, MMI_IME_LEFT_SOFTKEY);

}

void GB_WG_RecoverKeyHandler(void)
{
	GB_WG_RegisterKeyHandle(0);
}

static U32 ime_msg_unimplemented(mmi_imc_message_struct_p msg)
{
	return 0;
}

unsigned short* ime_get_editerText(void)
{

	mmi_imc_message_struct imc_msg;
	U8 *text_start = NULL, *text_end = NULL;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	imc_msg.message_id    = MMI_IMC_MESSAGE_GET_TEXT_PTR_BEFORE_CURSOR;
	imc_msg.param_0       = (U32)&text_start;
	imc_msg.param_1       = (U32)&text_end;
	mmi_imc_send_message(&imc_msg);
	return (unsigned short*)text_start;
}



GB_VOID GB_WG_SetPhoneNumInputmod(GB_VOID)
{
	if(mmi_imm_is_curr_allow_input_mode(IMM_INPUT_MODE_PHONE_NUMBER))
	{
	#ifdef __MMI_FTE_SUPPORT__
		mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_HIDE);
	#endif
		//mmi_imc_change_input_mode(IMM_INPUT_MODE_PHONE_NUMBER, 0);
		//mmi_imm_change_input_mode_for_wcss(IMM_INPUT_MODE_PHONE_NUMBER);
		GB_WG_ChangeInputmod(IMM_INPUT_MODE_PHONE_NUMBER);
	}
}

GB_VOID GB_WG_ShowSMDCandWnd(GB_VOID)
{		
#ifndef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_GB__	
	GB_WG_ShowSMDGuobiCandWnd();
#endif // __MMI_GB__
#endif
}

GB_BOOL GB_WG_R_IsInImeRect(GB_INT x, GB_INT y)				//判断点击是否在国笔候选框区域的接口 zhangchenglong 2011_11_18
{
	GB_BOOL ret = GB_FALSE;
	//  [6/2/2012 liangchuanhui]
//#ifndef GBWG_VIRTUAL_KEY
	if (!GB_WG_Get_isVirtual_key())
	{
#ifdef __MMI_GB__
		//if(GBCand_IsActive())
		if (GB_WG_EditorType == GB_WG_IME_InputType_SMD_SINGLELINE)
		{
			if(y >= GB_GetCandWinTop() && y <= GB_GetCandWinTop() + GB_GetCandWinHeight())
			{
				ret = GB_TRUE;
			}
		}
#endif
	}
//#endif
	return ret;
}
GB_BOOL GB_WG_R_ImeGetCandRect(GB_Rect *rect)				//获取输入法候选框的区域
{
	GB_BOOL ret = GB_FALSE;
	//  [6/2/2012 liangchuanhui]
//#ifndef GBWG_VIRTUAL_KEY
	if (!GB_WG_Get_isVirtual_key())
	{
#ifdef __MMI_GB__

		rect->xPos = 0;
		rect->width = GB_WG_GetScrW();
		rect->height = GBEngine_GetCandDisplayInputRowCount(GBEngine_GetEnineInstance())* CAND_LINE_HEIGHT;
		rect->yPos = CAND_BOTTOM - rect->height;


		ret = GB_TRUE;
#endif
	}

//#endif
	return ret;
}

MMI_BOOL GB_WG_ChangeInputmod(mmi_imm_input_mode_enum mode)
{
	MMI_BOOL ret = MMI_FALSE; 
	mmi_imc_message_struct imc_msg = {0};
	mmi_imm_input_mode_enum old_mode = mmi_imm_get_curr_input_mode();
	mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
	mmi_imm_set_history_input_mode(IMM_INPUT_MODE_NONE);
	mmi_imm_set_current_input_mode(mode);
	ret = mmi_imc_change_input_mode(mode, 0);
	if (ret)
	{
		imc_msg.message_id = MMI_IMC_MESSAGE_MODE_CHANGED;
		mmi_imc_send_message(&imc_msg);            
	}
	else
	{
		mmi_imm_set_current_input_mode(old_mode);
	}
	return ret;
}

GB_INT GB_WG_R_ImeKeyInput(GB_INT keyEvent,GB_INT keyValue)
{
	if(mmi_imc_is_connected())
	{
		U16 sys_keyEvent = GB_WG_WinguoKeyEventToSys(keyEvent);
		U16 sys_keyValue = GB_WG_WinguoKeyToSys(keyValue);
//		FuncPtr fun = mmi_frm_get_key_handler(sys_keyValue, GBKEY_PRESS); // 还需要考虑国笔输入法的情况，国笔输入法是注册平台按键处理的 [1/14/2012 lzp]
// #ifndef __COSMOS_MMI_PACKAGE__
// #ifdef __MMI_GB__	
// 		if(sys_keyEvent >=KEY_0 && sys_keyEvent <= KEY_9 && fun != mmi_imc_key_group_key_down) // 系统当前是使用guobi输入法的情况。
// 		{
// 			fun();
// 		}
// 		else
// #endif
// #endif
		{
			mmi_imc_key_group_key_down_int(sys_keyValue, GBKEY_PRESS/*sys_keyValue)*/);
			mmi_imc_key_group_key_up_int(sys_keyValue, GBKEY_RELEASE/*sys_keyValue*/);
		}
	}
	return 1;
}

GB_BOOL GB_WG_InputBoxCursorLoop(GB_INT InputBoxType)
{
#ifdef __COSMOS_MMI_PACKAGE__
	return GB_TRUE;
#else
	return GB_FALSE;
#endif
}

#endif /* #ifdef __MMI_GB_WINGUO__ */

