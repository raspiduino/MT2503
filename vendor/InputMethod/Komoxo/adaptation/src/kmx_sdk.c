
#include "MMI_features.h"

#ifdef __MMI_IME_PLUG_IN__
#include "kmx_input_config.h"

#include "kmx_input_prot.h"

#ifdef __MMI_KMX_TOUCH_INPUT__
#include "kmxsip_input_method.h"
#endif 

#include "kmximmapi.h"
#include "cstar_ime.h"

#include "kmx_sdk_translate.h"

#include "GlobalResDef.h"
#include "wgui_categories_util.h"

#include "kmx_gui.h"

#include "Mmi_frm_input_gprot.h"

static U32 mmi_ime_sdk_send_imc_message(mmi_imc_editor_message_id_enum msg_id, U32 param0, U32 param1)
{
    mmi_imc_message_struct msg;
        
    msg.message_id = msg_id;
    msg.param_0 = param0;
    msg.param_1 = param1;

    return mmi_ime_sdk_send_editor_msg(&msg);
}

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
int kmx_update_special_key_status(mmi_ime_sdk_key_event_data_struct_p key_data, mmi_ime_sdk_special_key_status_struct_p special_key_status);
static int kmx_on_special_key_status_changed(U32 special_key_flag, U32 special_key_lock_flag);
static int kmx_on_special_key_status_reset(void);
#endif 
static void kmx_on_cursor_moved(void);
void kmx_ime_sdk_set_softkey_by_state(mmi_ime_sdk_state_enum state);
void kmx_ime_sdk_redraw_softkey_by_state(mmi_ime_sdk_state_enum state);
#if defined(__MMI_TOUCH_SCREEN__)
U32 kmx_ime_sdk_imui_control_translate_pen_event(mmi_ime_sdk_imui_control_enum control, 
                                                 mmi_ime_sdk_pen_event_data_struct_p pen_event_data);
#endif

U32 kmx_ime_sdk_get_ui_set_by_state(mmi_ime_sdk_state_enum state);
void kmx_ime_sdk_update_controls(U32 imui_set);

void kmx_ime_add_ui_all_controls(void);

int kmx_ime_is_ime_support(void);

static int g_kmx_is_ime_supported;

static U32 kmx_check_input_mode_avaliable(mmi_imm_input_mode_enum input_mode);

#ifdef __MMI_IME_AUTO_CAPITALIZATION__
static MMI_BOOL g_kmx_skip_cursor_movement_event = MMI_FALSE;
#endif

#ifdef __MMI_KMX_TOUCH_INPUT__
/* Return 0 if state is intital state or non-vk state, otherwise return 1 */
int kmx_ime_is_vk_input_state(mmi_ime_sdk_state_enum state);
#endif

int kmx_ime_is_key_input_state(mmi_ime_sdk_state_enum state);

U32 mmi_ime_sdk_vendor_handle_message(mmi_ime_sdk_msg_id_enum message_id, U32 param0, U32 param1)
{
    U32 ret = MMI_TRUE;
        
    switch(message_id) {
    case MMI_IME_SDK_MSG_EDITOR_CONNECTED:
        {            
		    kmx_ime_setup_input_method();
            #ifdef __MMI_KMX_TOUCH_INPUT__
            kmx_input_method_select();
            #endif
            kmx_ime_config_feature_options();
            #ifdef __MMI_IME_AUTO_CAPITALIZATION__
            g_kmx_skip_cursor_movement_event = MMI_TRUE;
            #endif
        }
    	break;
    case MMI_IME_SDK_MSG_EDITOR_DISCONNECTING:
        {            
            #ifdef __MMI_KMX_TOUCH_INPUT__
            kmx_input_method_deselect();
            #endif
            kmx_ime_close_input_method();    
            #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
            kmx_on_special_key_status_reset();
            #endif
            
            kmx_gui_exit();
        }
        break;
    case MMI_IME_SDK_MSG_EDITOR_DISCONNECTED:
    {
        break;
    }        
    case MMI_IME_SDK_MSG_STATE_CHANGED:        
        {
            mmi_ime_sdk_state_enum pre_state, cur_state;            
            pre_state = (mmi_ime_sdk_state_enum)param0;
			cur_state = (mmi_ime_sdk_state_enum)param1;
            if (pre_state != cur_state && cur_state == MMI_IME_SDK_STATE_INITIAL)
            {				                
                cstar_ime_reset_state();
            }
        }
		break;
	case MMI_IME_SDK_MSG_RESET:
		{		    
            cstar_ime_reset_state();
			break;
		}
    case MMI_IME_SDK_MSG_CHANGE_INPUT_MODE:
        {
            g_kmx_is_ime_supported = 0;
            g_kmx_is_ime_supported |= kmx_ime_set_input_mode((int)param0);
            #ifdef __MMI_KMX_TOUCH_INPUT__
	        g_kmx_is_ime_supported |= kmx_input_method_change_input_mode((int)param0);
            #endif            
        }
        break;
    case MMI_IME_SDK_MSG_KEY_EVENT:
        if(cstar_ime_is_ime_support())
        {            
            U16 key_code, key_type;
			UI_character_type ucs2_code = 0;
			U32 special_key_flag = 0;
            int handled = 0;

			mmi_ime_sdk_key_event_data_struct_p key_event_data;
			mmi_ime_sdk_key_event_special_data_struct_p key_special_data;

			key_event_data = (mmi_ime_sdk_key_event_data_struct_p) param0;
			key_special_data = (mmi_ime_sdk_key_event_special_data_struct_p) param1;

			key_code = key_event_data->mmi_key_code;
			key_type = key_event_data->mmi_key_type;
            
            /* Filter event type */
            if (key_type != KEY_EVENT_DOWN && key_type != KEY_EVENT_UP && key_type != KEY_LONG_PRESS)
            {
                /* just eat other type event */
                break;
            }

			if(key_special_data)
			{
				ucs2_code = key_special_data->ucs2_code;
				special_key_flag = key_special_data->special_key_flag;
			}
            
        #ifdef __MMI_KMX_TOUCH_INPUT__            
            if(!kmx_input_method_handle_key_event(key_code, key_type))
        #endif
                if(!cstar_ime_handle_key(key_code, key_type, (int)ucs2_code))
                {                    
                    handled = kmx_default_handle_key(key_code, key_type, ucs2_code);
                    #ifdef __MMI_KMX_TOUCH_INPUT__
                    if (!handled)
                    {
                        if (kmx_input_method_is_keypad_enable()
                                && kmx_ime_is_vk_input_state(mmi_ime_sdk_get_state())
                                && (key_code == KEY_LSK && key_type == KEY_EVENT_UP)
                                )
                        {
                            mmi_ime_sdk_set_state(MMI_IME_SDK_STATE_INITIAL);
                            mmi_ime_sdk_redraw_screen_by_state();
                        }
                    }
                    #endif
                    if (!handled && key_code == KEY_END)
                        ret = MMI_FALSE;
                }
        }
        else
        {
            ret = MMI_FALSE;
        }
        break;
    #ifdef __MMI_VIRTUAL_KEYBOARD__
    case MMI_IME_SDK_MSG_VK_EVENT:        
        {
			mmi_pen_event_type_enum pen_event_type;
			mmi_ime_sdk_vk_event_data_struct_p vk_event_data;
			
			pen_event_type = (mmi_pen_event_type_enum) param0;
			vk_event_data  = (mmi_ime_sdk_vk_event_data_struct_p) param1;

            #if defined(__MMI_KMX_TOUCH_INPUT__) && !defined(__NO_HANDWRITING__)
            if (vk_event_data && vk_event_data->vk_event == GUI_VKBD_PEN_HANDWRITING && pen_event_type == MMI_PEN_EVENT_UP)
            {
                if (kmx_input_method_exit_handwriting_panel())
                    mmi_ime_sdk_redraw_screen_by_state();
                break;
            }
            #endif

            if(!cstar_ime_is_ime_support() || !vk_event_data)
            {
                ret = MMI_FALSE;
                break;
            }

            #ifdef __MMI_KMX_HALF_QWERTY_BOPOMOFO__
            {                
                if (kmx_ime_handle_bopomofo_half_qwerty_char(pen_event_type, vk_event_data->character, vk_event_data->vk_event))
                    break;
            }
            #endif

            if (pen_event_type != MMI_PEN_EVENT_UP)
            {
                ret = MMI_FALSE;
                break;
            }

            switch(vk_event_data->vk_event)
            {
                case GUI_VKBD_PEN_BAKSPACE:
                #ifdef __MMI_IME_FTE_ENHANCE__
                case GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE:
                #endif
                    {             
                        ret = cstar_ime_handle_key(KEY_RSK, KEY_EVENT_UP, 0);
                    }
                    break;
                case GUI_VKBD_PEN_CHAR_I:
                    {                        
                        if(!cstar_ime_handle_event(1, (int)vk_event_data->character, 0))
                        {
                            mmi_ime_sdk_send_imc_message(MMI_IMC_MESSAGE_INSERT_CHAR, vk_event_data->character, 0);
                        }		            		                
                    }
                    break;
                #ifdef __MMI_IME_FTE_ENHANCE__
                case GUI_VKBD_PEN_STROKE_1:
                    {
                        kmx_ime_handle_stroke_char(0xF004);
                    }
                    break;
                case GUI_VKBD_PEN_STROKE_2:
                    {                     
                        kmx_ime_handle_stroke_char(0xF001);
                    }
                    break;
                case GUI_VKBD_PEN_STROKE_3:
                    {                     
                        kmx_ime_handle_stroke_char(0xF007);
                    }
                    break;
                case GUI_VKBD_PEN_STROKE_4:
                    {                     
                        kmx_ime_handle_stroke_char(0xF002);
                    }
                    break;
                case GUI_VKBD_PEN_STROKE_5:
                    {                     
                        kmx_ime_handle_stroke_char(0xF005);
                    }
                    break;
                case GUI_VKBD_PEN_STROKE_DEPART:
                    {                     
                        kmx_ime_handle_stroke_char(0xF000);
                    }
                    break;
                #endif
                    default:
                    ret = MMI_FALSE;
                    break;
            }
        }
        break;
    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
    case MMI_IME_SDK_MSG_VK_CALLBACK_EVENT:
        {
            #ifdef __MMI_KMX_HALF_QWERTY_BOPOMOFO__
            mmi_ime_sdk_vk_event_callback_data_struct_p vk_callback_data;
            vk_callback_data = (mmi_ime_sdk_vk_event_callback_data_struct_p)param0;
            ret = MMI_FALSE;            
            if(vk_callback_data)
            {                
                ret = kmx_ime_handle_vk_event_callback(vk_callback_data->vk_event,
                                                       vk_callback_data->key_param,
                                                       (int)vk_callback_data->ret_ptr,
                                                       (int)vk_callback_data->ret_val_ptr);
            }
            #else
            ret = MMI_FALSE;            
            #endif
        }
        break;
    #endif
    #endif
    case MMI_IME_SDK_MSG_CLEAR_LAST_FIXED_UI_CONTROLS:
        {            
            CS_UI_RECT ime_wnd;
            if (param0 & MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_IME_WINDOW))
            {
                kmx_get_ime_window_difference(&ime_wnd);
                if( (ime_wnd.left != ime_wnd.right) && (ime_wnd.top != ime_wnd.bottom))
                    mmi_ime_sdk_redraw_imui_background(ime_wnd.left, ime_wnd.top, ime_wnd.right - 1, ime_wnd.bottom);
            }
            #if defined(__MMI_VIRTUAL_KEYBOARD__)
            if (param0 & MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD))
            {
                #ifdef __MMI_KMX_TOUCH_INPUT__
                kmxsip_input_method_clear_keypad_area();
                #endif
            }
            #endif
        }
        break;
    case MMI_IME_SDK_MSG_DRAW_CURRENT_FIXED_UI_CONTROLS:
        {
            int bottom_y;
            bottom_y = param1;
            
            #if defined(__MMI_VIRTUAL_KEYBOARD__)
            if (param0 & MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD))
            {
                #ifdef __MMI_KMX_TOUCH_INPUT__
                kmx_input_method_update_view(bottom_y);            
                kmx_input_method_get_keypad_pos(0, &bottom_y);
                bottom_y -= 1;
                #endif
            }
            #endif

            if (param0 & MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_IME_WINDOW))
            {                                
                bottom_y = (U32)kmx_ime_paint_ime_window(0, bottom_y);
            }
            
            ret = bottom_y;
        }
        break;
    case MMI_IME_SDK_MSG_GET_CURRENT_FIXED_CONTROL_SET:
        {
            PU32 imui_set_ptr = (PU32) param0;

            if(!kmx_ime_is_ime_support())
            {
                ret = MMI_FALSE;
                break;
            }

            if (imui_set_ptr)
            {
                *imui_set_ptr = kmx_ime_sdk_get_ui_set_by_state(mmi_ime_sdk_get_state());
            }
        }
        break;
    case MMI_IME_SDK_MSG_CONFIG_UI_CONTROLS_BY_IME_STATE:
        {
            U32 imui_set;
            
            if(!kmx_ime_is_ime_support())
            {
                ret = MMI_FALSE;
                break;
            }
            
            #if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__)
            /* Return False if current input pattern is handwriting */
            if (mmi_imm_get_keyboard_type() == IMM_KEYPAD_HANDWRITING)
            {
                ret = MMI_FALSE;
                break;
            }                        
            #endif /* #if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) */

            #if defined(__MMI_KMX_TOUCH_INPUT__) && defined(__MMI_IME_FTE_ENHANCE__)
            /* if VK is set to off, change input state to initial state */
            if (kmx_input_method_is_keypad_enable()
                && kmx_ime_is_vk_input_state(mmi_ime_sdk_get_state())
                && (mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON) == MMI_FALSE))
            {
                mmi_ime_sdk_set_state(MMI_IME_SDK_STATE_INITIAL);
            }
            #endif
            imui_set = kmx_ime_sdk_get_ui_set_by_state(mmi_ime_sdk_get_state());
            kmx_ime_sdk_update_controls(imui_set);                            
        }
        break;
    case MMI_IME_SDK_MSG_GET_UI_CONTROL_HEIGHT:
        {
            ret = 0;
            if (param0 & MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_IME_WINDOW))
            {                
                ret += kmx_get_ime_window_height();
            }
            #if defined(__MMI_VIRTUAL_KEYBOARD__)
			#ifdef __MMI_KMX_TOUCH_INPUT__
            if (param0 & MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD))
            {                
                int w, h;
                kmx_input_method_get_keypad_size(&w, &h);
                ret += h;
            }
			#endif
            #endif
        }
        break;
    #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    case MMI_IME_SDK_MSG_UPDATE_SPECIAL_KEY_STATUS:
        {
            mmi_ime_sdk_key_event_data_struct_p key_data;
			mmi_ime_sdk_special_key_status_struct_p	special_key_status;
			
            if(!mmi_imc_is_connected() || !cstar_ime_is_ime_support())
            {
                ret = MMI_FALSE;
                break;
            }

            key_data           = (mmi_ime_sdk_key_event_data_struct_p)param0;
            special_key_status = (mmi_ime_sdk_special_key_status_struct_p)param1;            
            
            if (special_key_status && key_data)
            {
                memset(special_key_status, 0, sizeof(*special_key_status));
                if(!kmx_update_special_key_status(key_data, special_key_status))                
                    ret = MMI_FALSE;                
            }
        }
        break;
    case MMI_IME_SDK_MSG_SPECIAL_KEY_STATUS_CHANGED:
		{
			mmi_ime_sdk_special_key_status_struct_p special_key_status;
			special_key_status = (mmi_ime_sdk_special_key_status_struct_p)param0;
			kmx_on_special_key_status_changed(special_key_status->special_key_flag, special_key_status->special_key_lock_flags);
		}
        break;
    case MMI_IME_SDK_MSG_GET_INVALID_QWERTY_SPECIAL_KEY:
        {
            U32 invalid_flag;
            const KMX_INPUT_MODE_ATTRIBUTES* mode_attr;
            invalid_flag = (U32) param0;

            mode_attr = kmx_get_curr_input_mode_attr();
            ret = invalid_flag;

            /* TODO: May be we should cancel shift status for no smart case-sensitive input */
            if (mode_attr && (mode_attr->ime == KMX_IME_STROKE || mode_attr->ime == KMX_IME_PINYIN || mode_attr->ime == KMX_IME_BOPOMOFO))
            {
                /* enable FN for these input mode */
                ret = invalid_flag & ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN;
            }            
        }
        break;
    #endif
    case MMI_IME_SDK_MSG_EDITOR_CURSOR_MOVED:
        {
            mmi_ime_sdk_state_enum state;
            state = mmi_ime_sdk_get_state();
            
            #ifdef __MMI_IME_AUTO_CAPITALIZATION__
            if (g_kmx_skip_cursor_movement_event)
            {
                g_kmx_skip_cursor_movement_event = MMI_FALSE;
                ret = MMI_FALSE;
                break;
            }
            #endif
            
            #ifdef __MMI_KMX_TOUCH_INPUT__
            if (state == MMI_IME_SDK_STATE_INITIAL || kmx_ime_is_vk_input_state(state))
            {
                if (kmx_input_method_on_editor_cursor_moved())
                {
                    ret = MMI_TRUE;
                    break;
                }
            }
            #endif
            
            /* TODO: key engine handle this message? */
            
            if (state == MMI_IME_SDK_STATE_MTK ||
                state == MMI_IME_SDK_STATE_INITIAL ||
                state == MMI_IMC_STATE_NONE
            )
            {
                /* Let platform handle this situation. */
                ret = MMI_FALSE;
            }
            else
            {
                ret = MMI_TRUE;
            }        
        }
        break;
	case MMI_IME_SDK_MSG_REDRAW_UI_CONTROLS:
		// TODO:
		break;
	case MMI_IME_SDK_MSG_ADD_ALL_CONTROLS:
		{
			kmx_ime_add_ui_all_controls();
		}
		break;
    case MMI_IME_SDK_MSG_SET_SOFTKEY_BY_STATE:
        {
            mmi_ime_sdk_state_enum state = (mmi_ime_sdk_state_enum) param0;
            if(!kmx_ime_is_ime_support())
            {
                ret = MMI_FALSE;
                break;
            }
            kmx_ime_sdk_set_softkey_by_state(state);
        }
        break;
    case MMI_IME_SDK_MSG_REDRAW_SOFTKEY_BY_STATE:
        {
            mmi_ime_sdk_state_enum state = (mmi_ime_sdk_state_enum) param0;
            if(!kmx_ime_is_ime_support())
            {
                ret = MMI_FALSE;
                break;
            }
            kmx_ime_sdk_redraw_softkey_by_state(state);
        }
        break;
    #if defined(__MMI_TOUCH_SCREEN__)
    case MMI_IME_SDK_MSG_IMUI_CONTROL_TRANSLATE_PEN_EVENT:
        {
            mmi_ime_sdk_imui_control_enum control = (mmi_ime_sdk_imui_control_enum) param0;
            mmi_ime_sdk_pen_event_data_struct_p pen_event_data = (mmi_ime_sdk_pen_event_data_struct_p) param1;

            if(!kmx_ime_is_ime_support())
            {
                ret = MMI_FALSE;
                break;
            }
            ret =  kmx_ime_sdk_imui_control_translate_pen_event(control, pen_event_data);
        }
        break;
    #endif        
    case MMI_IME_SDK_MSG_CONFIG_VK_IN_MTK_STATE:
        {
            if(!kmx_ime_is_ime_support())
            {
                ret = MMI_FALSE;
                break;
            }
        
            #ifdef __MMI_KMX_TOUCH_INPUT__
                if (kmx_input_method_is_keypad_enable() 
                    #if !defined(__NO_HANDWRITING__)
                    && !kmx_input_method_is_handwriting_panel_on()
                    #endif /* #if !defined(__NO_HANDWRITING__) */ 
                    )
                {
                    /* Do not show MTK VK */
                    #ifdef __MMI_IME_FTE_ENHANCE__
                    if (mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
                    #endif
                    {
                        mmi_ime_sdk_set_visible_control((mmi_ime_sdk_imui_control_enum)MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD);
                        if (param0)
                        {
                            *((U32*)param0) = MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD);
                        }                        
                    }
                    #ifdef __MMI_IME_FTE_ENHANCE__
                    else
                    {
                        mmi_ime_sdk_set_hidden_control((mmi_ime_sdk_imui_control_enum)MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD);
                        if (param0)
                        {
                            *((U32*)param0) = 0;
                        }                        
                    }
                    #endif
                }
                else
                    ret = MMI_FALSE;
            #else
                ret = MMI_FALSE;
            #endif
        }
        break;
    case MMI_IME_SDK_MSG_GET_CURRENT_FLOATING_CONTROL_SET:
        if (kmx_ime_is_ime_support())
        {            
            /* TODO: Add floating controls */
            ret = 0;
        }
        else
        {
            ret = 0;
        }
        break;
    case MMI_IME_SDK_MSG_DRAW_CURRENT_FLOATING_UI_CONTROLS:
        if (kmx_ime_is_ime_support())
        {
            ret = 1;
        }
        else
        {
            ret = 0;
        }
        break;
    case MMI_IME_SDK_MSG_GET_CURRENT_FLOATING_UI_RECT:
        if (kmx_ime_is_ime_support())
        {
            mmi_imc_rect_p r = (mmi_imc_rect_p)param1;
            if (r)
                memset(r, 0, sizeof(*r));
        }        
        break;
    case MMI_IME_SDK_MSG_CHECK_INPUT_MODE_AVAILABLE:
        ret = kmx_check_input_mode_avaliable((mmi_imm_input_mode_enum)param0);
        break;
    case MMI_IME_SDK_MSG_IS_IMUI_CONTROL:
        ret = (U32)kmx_gui_is_gui_control((void*)param0);        
        break;        
    default:
        ret = MMI_FALSE;
        break;
    }
    
    #ifdef _MSC_VER
    {
        const char * msg_name;

        msg_name = kmx_translate_sdk_msg_name(message_id);
        
        printf("-----> Here Come Msg %s, val: %d, ret: %d, p1:%X, p2:%X\r\n", msg_name, message_id, ret, param0, param1);    

    }
    #endif
    return ret;
}

void kmx_ime_vendor_init(void)
{
	mmi_ime_sdk_register_msg_callback(mmi_ime_sdk_vendor_handle_message);
    #ifdef __MMI_IME_PLUG_IN_SETTING__ 
    {
        extern void mmi_input_method_setting_callback(MMI_ID parent_gid);
        mmi_ime_sdk_register_setting_callback(mmi_input_method_setting_callback);
    }
    #endif
}

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
static U32 g_kmx_special_key_flag;
static U32 g_kmx_special_key_lock_flags;
    
int kmx_update_special_key_status(mmi_ime_sdk_key_event_data_struct_p key_data, mmi_ime_sdk_special_key_status_struct_p special_key_status)
{
    S16 mmi_key_code, mmi_key_type;
    static S16 pre_down_key_bak;
    static S16 pre_down_key;
    static U32 special_key_flag_bak;
    static U32 special_key_lock_flags_bak;
    
    mmi_key_code = (S16)key_data->mmi_key_code;
    mmi_key_type = (S16)key_data->mmi_key_type;
    
    if (mmi_key_code != KEY_SHIFT && mmi_key_code != KEY_FN)
    {
        if (mmi_key_type == KEY_EVENT_UP)
        {

            if ((g_kmx_special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
                 && !(g_kmx_special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
                 )
            {
                g_kmx_special_key_flag &= ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN;

                g_kmx_special_key_flag = special_key_flag_bak;
                g_kmx_special_key_lock_flags = special_key_lock_flags_bak;
                pre_down_key = pre_down_key_bak;
            }
        }
    }

    if (mmi_key_code == KEY_SHIFT && !(g_kmx_special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
        && !(g_kmx_special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_NUMLOCK))
    {
       if (mmi_key_type == KEY_EVENT_DOWN)
       {
           if (!(g_kmx_special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT))
           {
               g_kmx_special_key_flag = MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
			   g_kmx_special_key_lock_flags = 0;
           }
           else if ((g_kmx_special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
			        && !(g_kmx_special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT))
           {
               g_kmx_special_key_lock_flags = MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
           }
           else if (g_kmx_special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
           {
               g_kmx_special_key_flag &= ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
			   g_kmx_special_key_lock_flags &= ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
           }
       }
       else if (mmi_key_type == KEY_EVENT_UP)
       {
           if ((g_kmx_special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
                 && !(g_kmx_special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
                 && pre_down_key != KEY_SHIFT)
           {
                g_kmx_special_key_flag &= ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
           }
       }
    }
    else if (mmi_key_code == KEY_FN)
    {
       if (mmi_key_type == KEY_EVENT_DOWN)
       {
           if (!(g_kmx_special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN))
           {
               special_key_flag_bak = g_kmx_special_key_flag;
               special_key_lock_flags_bak = g_kmx_special_key_lock_flags;
               pre_down_key_bak = pre_down_key;
               
               g_kmx_special_key_flag = MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN;
			   g_kmx_special_key_lock_flags = 0;
           }
           else if ((g_kmx_special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
			        && !(g_kmx_special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN))
           {
               g_kmx_special_key_lock_flags = MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN;
           }
           else if (g_kmx_special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
           {
               g_kmx_special_key_flag &= ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN;
			   g_kmx_special_key_lock_flags &= ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN;

               g_kmx_special_key_flag = special_key_flag_bak;
               g_kmx_special_key_lock_flags = special_key_lock_flags_bak;
               pre_down_key = pre_down_key_bak;
           }
       }
       else if (mmi_key_type == KEY_EVENT_UP)
       {
           if ((g_kmx_special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
                 && !(g_kmx_special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
                 && pre_down_key != KEY_FN)
           {
               g_kmx_special_key_flag &= ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN;

               g_kmx_special_key_flag = special_key_flag_bak;
               g_kmx_special_key_lock_flags = special_key_lock_flags_bak;
               pre_down_key = pre_down_key_bak;
           }
       }
    }
    else if (mmi_key_code == KEY_NUM_LOCK)
    {
       if (mmi_key_type == KEY_EVENT_DOWN)
       {
           if (g_kmx_special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_NUMLOCK)
           {
               g_kmx_special_key_flag = 0;
               g_kmx_special_key_lock_flags = 0;
           }
           else 
           {
               g_kmx_special_key_flag = 0;
               g_kmx_special_key_lock_flags = MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_NUMLOCK;
           }
       }
    }
    
    if (mmi_key_type == KEY_EVENT_DOWN)
    {
        pre_down_key = mmi_key_code;
    }

    special_key_status->special_key_flag = g_kmx_special_key_flag;
    special_key_status->special_key_lock_flags = g_kmx_special_key_lock_flags;

    return 1;
}

static int kmx_on_special_key_status_changed(U32 special_key_flag, U32 special_key_lock_flag)
{
    int new_case_info;
    const KMX_INPUT_MODE_ATTRIBUTES* mode_attr;

    g_kmx_special_key_flag = special_key_flag;
    g_kmx_special_key_lock_flags = special_key_lock_flag;
    
    mode_attr = kmx_get_curr_input_mode_attr();
    
    if (mode_attr && (mode_attr->ime == KMX_IME_LATIN_SMART || mode_attr->ime == KMX_IME_LATIN_MULTITAP))    
    {
            
        if (special_key_lock_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
        {
            new_case_info = KMX_LANG_UPPERCASE;
        }
        else if (special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
        {
            new_case_info = KMX_LANG_INITIALCASE;
        }
        else
        {
           new_case_info = KMX_LANG_LOWERCASE;
        }
        kmx_ime_update_case(new_case_info);
    }
    return 1;
}

static int kmx_on_special_key_status_reset()
{
    g_kmx_special_key_flag = 0;
    g_kmx_special_key_lock_flags = 0;
    return 1;
}

#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */

static void kmx_on_cursor_moved(void)
{

}

void kmx_ime_add_ui_all_controls(void)
{
    kmx_gui_setup();
    
    kmx_gui_init();
    
	if (!mmi_ime_sdk_is_in_imui_control_set((mmi_ime_sdk_imui_control_enum)MMI_IME_SDK_IMUI_IME_WINDOW))
		mmi_ime_sdk_add_imui_control((mmi_ime_sdk_imui_control_enum)MMI_IME_SDK_IMUI_IME_WINDOW);

	#ifdef __MMI_KMX_TOUCH_INPUT__	
	if (!mmi_ime_sdk_is_in_imui_control_set((mmi_ime_sdk_imui_control_enum)MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD))
		mmi_ime_sdk_add_imui_control((mmi_ime_sdk_imui_control_enum)MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD);
	#endif	
}

void kmx_ime_sdk_set_softkey_by_state(mmi_ime_sdk_state_enum state)
{
    switch(state)
    {
    case MMI_IME_SDK_STATE_MULTITAP:
    case MMI_IME_SDK_STATE_CAND_SELECTING:
    case MMI_IME_SDK_STATE_VK_CAND:
    case MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_INPUT:
    case MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_MULTITAP:
    case MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_MULTITAP_HOVER:
        /* LSK */
        mmi_ime_sdk_set_softkey_function(UI_dummy_function, KEY_EVENT_DOWN, MMI_LEFT_SOFTKEY);
        mmi_ime_sdk_set_softkey_function(UI_dummy_function, KEY_EVENT_DOWN, MMI_CENTER_SOFTKEY);
        mmi_ime_sdk_set_softkey_function(mmi_imc_key_group_key_up, KEY_EVENT_UP, MMI_LEFT_SOFTKEY);

        if (state != MMI_IME_SDK_STATE_MULTITAP && state != MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_MULTITAP)
        {
            mmi_ime_sdk_set_softkey_function(mmi_imc_key_group_key_up, KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
            mmi_ime_sdk_set_softkey_label_in_ime_state(NULL, MMI_CENTER_SOFTKEY);
            mmi_ime_sdk_set_softkey_icon_in_ime_state(get_image(IMG_GLOBAL_COMMON_CSK), MMI_CENTER_SOFTKEY);
        }
        mmi_ime_sdk_register_softkey_handler(MMI_CENTER_SOFTKEY);

			if(mmi_frm_kbd_is_key_supported(KEY_CLEAR))
			{
			    mmi_ime_sdk_set_key_handler(mmi_imc_key_group_key_down, KEY_CLEAR, KEY_EVENT_DOWN);
                mmi_ime_sdk_set_key_handler(mmi_imc_key_group_key_down, KEY_CLEAR, KEY_EVENT_UP);
                mmi_ime_sdk_set_key_handler(mmi_imc_key_group_key_down, KEY_CLEAR, KEY_EVENT_LONG_PRESS);
			}
			else
			{
				mmi_ime_sdk_set_softkey_function(mmi_imc_key_group_key_down, KEY_EVENT_DOWN, MMI_RIGHT_SOFTKEY);
                mmi_ime_sdk_set_softkey_function(mmi_imc_key_group_key_long, KEY_EVENT_LONG_PRESS, MMI_RIGHT_SOFTKEY);
                mmi_ime_sdk_set_softkey_function(mmi_imc_key_group_key_up, KEY_EVENT_UP, MMI_RIGHT_SOFTKEY);
			}

            mmi_ime_sdk_set_key_handler(mmi_imc_key_group_key_down, KEY_UP_ARROW, KEY_EVENT_DOWN);
            mmi_ime_sdk_set_key_handler(mmi_imc_key_group_key_down, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            mmi_ime_sdk_set_key_handler(mmi_imc_key_group_key_down, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            mmi_ime_sdk_set_key_handler(mmi_imc_key_group_key_down, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

            mmi_ime_sdk_set_key_handler(UI_dummy_function, KEY_UP_ARROW, KEY_EVENT_UP);
            mmi_ime_sdk_set_key_handler(UI_dummy_function, KEY_DOWN_ARROW, KEY_EVENT_UP);
            mmi_ime_sdk_set_key_handler(UI_dummy_function, KEY_UP_ARROW, KEY_EVENT_LONG_PRESS);
            mmi_ime_sdk_set_key_handler(UI_dummy_function, KEY_DOWN_ARROW, KEY_EVENT_LONG_PRESS);
            mmi_ime_sdk_clear_key_handler(KEY_UP_ARROW, KEY_EVENT_REPEAT);
            mmi_ime_sdk_clear_key_handler(KEY_DOWN_ARROW, KEY_EVENT_REPEAT);

            mmi_ime_sdk_set_key_handler(UI_dummy_function, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            mmi_ime_sdk_set_key_handler(UI_dummy_function, KEY_LEFT_ARROW, KEY_EVENT_UP);
            mmi_ime_sdk_set_key_handler(UI_dummy_function, KEY_RIGHT_ARROW, KEY_EVENT_LONG_PRESS);
            mmi_ime_sdk_set_key_handler(UI_dummy_function, KEY_LEFT_ARROW, KEY_EVENT_LONG_PRESS);

            mmi_ime_sdk_clear_key_handler(KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
            mmi_ime_sdk_clear_key_handler(KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
            
        break;
    }
}

void kmx_ime_sdk_redraw_softkey_by_state(mmi_ime_sdk_state_enum state)
{
    switch(state)
    {    
    case MMI_IME_SDK_STATE_CAND_SELECTING:
    case MMI_IME_SDK_STATE_VK_CAND:
    case MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_INPUT:
    case MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_MULTITAP_HOVER:
        /* KMX TODO: When to display save str? */
        /* LSK */
        mmi_ime_sdk_set_softkey_label_in_ime_state((UI_string_type) get_string(STR_GLOBAL_SELECT), MMI_LEFT_SOFTKEY);
        mmi_ime_sdk_set_softkey_icon_in_ime_state(NULL, MMI_LEFT_SOFTKEY);
        mmi_ime_sdk_show_softkey(MMI_LEFT_SOFTKEY);
        mmi_ime_sdk_register_softkey_handler(MMI_LEFT_SOFTKEY);

        /* RSK */
        mmi_ime_sdk_set_softkey_label_in_ime_state((UI_string_type) get_string(STR_GLOBAL_CLEAR), MMI_RIGHT_SOFTKEY); 
        mmi_ime_sdk_set_softkey_icon_in_ime_state(NULL, MMI_RIGHT_SOFTKEY);
        mmi_ime_sdk_show_softkey(MMI_RIGHT_SOFTKEY);
        mmi_ime_sdk_register_softkey_handler(MMI_RIGHT_SOFTKEY);
        break;
    
    case MMI_IME_SDK_STATE_MULTITAP:
    case MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_MULTITAP:
        mmi_ime_sdk_show_softkey(MMI_LEFT_SOFTKEY);
        mmi_ime_sdk_register_softkey_handler(MMI_LEFT_SOFTKEY);

        mmi_ime_sdk_show_softkey(MMI_RIGHT_SOFTKEY);
        mmi_ime_sdk_register_softkey_handler(MMI_RIGHT_SOFTKEY);
        break;
    }
}

#if defined(__MMI_TOUCH_SCREEN__)
U32 kmx_ime_sdk_imui_control_translate_pen_event(
    mmi_ime_sdk_imui_control_enum               control, 
    mmi_ime_sdk_pen_event_data_struct_p         pen_event_data)
{
    U32 ret = MMI_FALSE;

    if (!pen_event_data || !mmi_ime_sdk_is_visible_control(control))
        return MMI_FALSE;
    
    if (control == MMI_IME_SDK_IMUI_IME_WINDOW)
    {
        switch(pen_event_data->event_type)
        {
        case MMI_PEN_EVENT_DOWN:
            {                
                ret = (U32) cstar_pen_down_handler(pen_event_data->pos.x, pen_event_data->pos.y);
            }
            break;
        case MMI_PEN_EVENT_UP:
            {                
                ret = (U32) cstar_pen_up_handler(pen_event_data->pos.x, pen_event_data->pos.y);
            }
            break;
        case MMI_PEN_EVENT_MOVE:
            {                
                ret = (U32) cstar_pen_move_handler(pen_event_data->pos.x, pen_event_data->pos.y);
            }
            break;
        }
    }
    #ifdef __MMI_KMX_TOUCH_INPUT__
    else if (control == MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD)
    {
        switch(pen_event_data->event_type)
        {
        case MMI_PEN_EVENT_DOWN:
            {                
                ret = kmx_input_method_pen_down(pen_event_data->pos.x, pen_event_data->pos.y);
            }
            break;
        case MMI_PEN_EVENT_UP:
            {             
                ret = kmx_input_method_pen_up(pen_event_data->pos.x, pen_event_data->pos.y);
            }
            break;
        case MMI_PEN_EVENT_MOVE:
            {             
                ret = kmx_input_method_pen_move(pen_event_data->pos.x, pen_event_data->pos.y);
            }
             break;
        }
    }
    #endif

    return ret;
}
#endif

typedef struct
{
    U8  state;
    U32 imui_set;
}KMX_IME_SDK_STATE_CONTROL_ENTRY;

#ifdef __MMI_TOUCH_SCREEN__

    #if defined(__MMI_IME_FTE_ENHANCE__) 
    static KMX_IME_SDK_STATE_CONTROL_ENTRY g_kmx_ime_sdk_state_set[] = {

        {MMI_IME_SDK_STATE_INITIAL, 0},

        {MMI_IME_SDK_STATE_MULTITAP, 0},

        {MMI_IME_SDK_STATE_CAND_SELECTING, MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_IME_WINDOW)},

        {MMI_IME_SDK_STATE_VK_CAND, MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_IME_WINDOW)},

        #ifdef __MMI_KMX_TOUCH_INPUT__
        {MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_INPUT, MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD)},

        {MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_MULTITAP, MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD)},
        
        {MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_MULTITAP_HOVER, MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD)},
        
        #endif

        {MMI_IME_SDK_STATE_NONE, 0}
    };

    #else
    static KMX_IME_SDK_STATE_CONTROL_ENTRY g_kmx_ime_sdk_state_set[] = {
        
        {MMI_IME_SDK_STATE_INITIAL, MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD)},

        {MMI_IME_SDK_STATE_MULTITAP, MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD)},

        {MMI_IME_SDK_STATE_CAND_SELECTING, MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_IME_WINDOW)},

        {MMI_IME_SDK_STATE_VK_CAND, MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD) | MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_IME_WINDOW)},

        #ifdef __MMI_KMX_TOUCH_INPUT__
        {MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_INPUT, MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD)},

        {MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_MULTITAP, MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD)},
        #endif

        {MMI_IME_SDK_STATE_NONE, 0}
    };
    #endif /* __MMI_IME_FTE_ENHANCE__ */
#else
    static KMX_IME_SDK_STATE_CONTROL_ENTRY g_kmx_ime_sdk_state_set[] = {

        {MMI_IME_SDK_STATE_INITIAL, 0},

        {MMI_IME_SDK_STATE_MULTITAP, 0},

        {MMI_IME_SDK_STATE_CAND_SELECTING, MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_IME_WINDOW)},

        {MMI_IME_SDK_STATE_NONE, 0}
    };
#endif

static U32 kmx_ime_sdk_fte_vk_adjust(U32 imui_set);

U32 kmx_ime_sdk_get_ui_set_by_state(mmi_ime_sdk_state_enum state)
{
    KMX_IME_SDK_STATE_CONTROL_ENTRY *e;
    U32 imui_set;
    e = g_kmx_ime_sdk_state_set;
    while(e->state != MMI_IME_SDK_STATE_NONE)
    {
        if (e->state == state)        
            break;        
        e++;
    }

    MMI_ASSERT(e->state != MMI_IME_SDK_STATE_NONE);
    
    imui_set = e->imui_set;
    
    #if defined(__MMI_IME_FTE_ENHANCE__)
    imui_set = kmx_ime_sdk_fte_vk_adjust(imui_set);
    #endif

    #ifdef __MMI_KMX_TOUCH_INPUT__
    if (!kmx_input_method_is_keypad_enable()
        #if !defined(__NO_HANDWRITING__)
        || kmx_input_method_is_handwriting_panel_on()
        #endif /* #if !defined(__NO_HANDWRITING__) */ 
        )
    #endif
    {
        /* Switch vendor vk to mtk vk */
        if (imui_set & MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD))
        {
            imui_set &= ~MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD);
            imui_set |= MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_CONTROL_MTK_VK);
        }
    }
    
    return imui_set;
}

void kmx_ime_sdk_update_controls(U32 imui_set)
{
    mmi_ime_sdk_imui_control_enum control;

    #ifdef __MMI_VIRTUAL_KEYBOARD__
    if (imui_set & MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_CONTROL_MTK_VK))
    {
	    mmi_ime_sdk_set_visible_control(MMI_IME_SDK_IMUI_CONTROL_MTK_VK);        
    }
    else
    {
        mmi_ime_sdk_set_hidden_control(MMI_IME_SDK_IMUI_CONTROL_MTK_VK);
    }
    #endif
    
    for (control = MMI_IME_SDK_IMUI_CONTROL_BEGIN; control <= MMI_IME_SDK_IMUI_CONTROL_LAST; control++)
    {
        if (imui_set & MMI_IME_SDK_IMUI_CONTROL_MASK(control))
        {
		    mmi_ime_sdk_set_visible_control(control);		    
        }
        else
        {
            mmi_ime_sdk_set_hidden_control(control);            
        }    	    
    }
    
    kmx_gui_update_control(imui_set);
}

#if defined(__MMI_IME_FTE_ENHANCE__)
static U32 kmx_ime_sdk_fte_vk_adjust(U32 imui_set)
{    
    if (mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
    {
        imui_set |= MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD);
    }
    else
    {
        imui_set &= ~MMI_IME_SDK_IMUI_CONTROL_MASK(MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD);
    }
    return imui_set;
}
#endif

#ifdef __MMI_KMX_TOUCH_INPUT__
int kmx_ime_is_vk_input_state(mmi_ime_sdk_state_enum state)
{    
    return state >= MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_INPUT && state <= MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_MULTITAP_HOVER;
}
#endif

int kmx_ime_is_key_input_state(mmi_ime_sdk_state_enum state)
{
    return state >= MMI_IME_SDK_STATE_MULTITAP && state <= MMI_IME_SDK_STATE_VK_CAND;
}

/* static assertion */
/* MMI_IMUI_VENDOR_CONTROL_END <= MMI_IMUI_VENDOR_CONTROL_MAX ...  */

int kmx_ime_is_ime_support(void)
{    
    return g_kmx_is_ime_supported;
}

static U32 kmx_check_input_mode_avaliable(mmi_imm_input_mode_enum input_mode)
{
    switch (input_mode)
    {
        /* Not supported input mode list below: */
    case IMM_INPUT_MODE_SM_MULTITAP_PINYIN:
        return 1;
    }
    return 0;
}

int kmx_ime_is_auto_capitalization_enabled(void)
{
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    return (int)mmi_imm_is_auto_capitalization_valid();
#else
    return 0;
#endif
}

S32 kmx_ime_get_curr_allow_input_mode_list(mmi_imm_input_mode_enum *mode_array, S32 max)
{
    S32 num;
    num = mmi_ime_sdk_get_curr_allow_input_mode_list_of_curr_writing_lang(mode_array, max);
    if (!num)
    {
        num = mmi_ime_sdk_get_current_allowed_input_mode_list(mode_array, max);
    }
    return num;
}

#endif
