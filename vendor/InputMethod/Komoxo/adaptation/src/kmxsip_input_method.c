
#include "MMI_features.h"
#include "kmx_input_config.h"

#ifdef __MMI_KMX_TOUCH_INPUT__

#include "Imc.h"

#include "Kmxsip_keypad.h"
#include "Kmxsip_input_method.h"
#include "Kmxsip_user_data.h"
#include "kmximmapi.h"
#include "Kmxsip_imm.h"
#include "Kmxsip_adapter.h"
#include "wgui_categories_enum.h"
#include "wgui_draw_manager.h"

#include "kmx_input_prot.h"

#if !defined(__MMI_NO_HANDWRITING__)
#include "Handwriting_engine.h"
#endif 

static KEYPAD * g_kmx_keypad;
static int g_sip_visible = 1;
static int g_sip_enabled = 1;

extern KMX_USER_PROFILE kmx_user_profile;

static int kmx_input_method_handle_message(int msg, int wParam, int lParam);

#define DTRACE   trace_str  

static void trace_str(const char * format, ...)
{
    #ifdef KMX_TOUCH_DEBUG
    static char buffer[128];
    va_list args;
    va_start(args, format);
    
    vsprintf(buffer, format, args);

    va_end(args);
#ifdef _MSC_VER
    printf("%s\n", buffer);
#else
    kal_prompt_trace(MOD_CC, "%s", buffer);
#endif
    #endif /* KMX_TOUCH_DEBUG */
}

static int kmx_input_method_check_support_curr_input_modes(void);

int kmx_input_method_select(void)
{    
    DTRACE("Enter kmx_input_method_select, enable: %d", g_sip_enabled);
    
    if (!kmx_input_method_check_support_curr_input_modes())
    {
        g_sip_enabled = 0;
        return 0;
    }
    else
    {
        g_sip_enabled = 1;
    }
    
    #if defined __MMI_IME_INPUT_PATTERN_SETTING__
    if (mmi_imm_get_keyboard_type() == IMM_KEYPAD_QWERTY)
    {
        kmx_keypad_set_keypad_type(KMX_KEYBOARD_TYPE_QWERTY);        
    }
    else
    {
        kmx_keypad_set_keypad_type(KMX_KEYBOARD_TYPE_DIGIT);
    }
    #else
    load_ime_user_setting();
    kmx_keypad_set_keypad_type(kmx_user_profile.softkeyboard_type);
    #endif    

    if (!g_sip_enabled)
        return 0;
    
    if (!g_kmx_keypad)
    {
        g_kmx_keypad = keypad_create();
    }

    DTRACE("Leave kmx_input_method_select");

    return g_kmx_keypad != 0;
}

int kmx_input_method_deselect(void)
{   

    DTRACE("Enter kmx_input_method_deselect enable: %d", g_sip_enabled);

    if (!g_sip_enabled)
        return 0;
    
    if (g_kmx_keypad)
    {
        keypad_destroy(g_kmx_keypad);
    }
    g_kmx_keypad = 0;
        
    DTRACE("Leave kmx_input_method_deselect");
    return 1;
}

void kmx_input_method_show(void)
{
    DTRACE("Enter kmx_input_method_show enable: %d", g_sip_enabled);
    
    if (!g_sip_enabled)
        return;
    
    if (!g_sip_visible)
    {
        g_sip_visible = 1;
        kmx_input_method_handle_message(KMX_SIP_MSG_SHOW, 0, 0);
    }

    DTRACE("Leave kmx_input_method_show");
}

void kmx_input_method_hide(void)
{
    DTRACE("Enter kmx_input_method_hide enable: %d", g_sip_enabled);
    if (!g_sip_enabled)
        return;
    
    if (g_sip_visible)
    {
        kmx_input_method_handle_message(KMX_SIP_MSG_HIDE, 0, 0);
        g_sip_visible = 0;
    }    

    DTRACE("Leave kmx_input_method_hide");
}

int kmx_input_method_is_visible(void)
{
    DTRACE("Enter kmx_input_method_is_visible: is_visible %d enable: %d", g_sip_visible, g_sip_enabled);
    if (!g_sip_enabled)
        return 0;

    DTRACE("Leave kmx_input_method_is_visible");
    return g_sip_visible;
}

int kmx_input_method_update_view(int bottom_line)
{
    DTRACE("Enter kmx_input_method_update_view enable: %d", g_sip_enabled);
    if (!g_sip_enabled)
        return 0;
    
    keypad_update_bottom_line(g_kmx_keypad, bottom_line);
    keypad_save_curr_window_pos(g_kmx_keypad);

    DTRACE("Leave kmx_input_method_update_view");

    return kmx_input_method_handle_message(KMX_SIP_MSG_PAINT, 0, 0);
}

int kmx_input_method_pen_down(int x, int y)
{
    DTRACE("Enter kmx_input_method_pen_down enable: %d x:%d y:%d", g_sip_enabled, x, y);

    if (!g_sip_enabled)
        return 0;
    
    return kmx_input_method_handle_message(KMX_MSG_PEN_DOWN, x, y);
}

int kmx_input_method_pen_up(int x, int y)
{
    DTRACE("Enter kmx_input_method_pen_up enable: %d x:%d y:%d", g_sip_enabled, x, y);
    if (!g_sip_enabled)
        return 0;
    
    return kmx_input_method_handle_message(KMX_MSG_PEN_UP, x, y);
}

int kmx_input_method_pen_move(int x, int y)
{
    DTRACE("Enter kmx_input_method_pen_move enable: %d x:%d y:%d", g_sip_enabled, x, y);
    if (!g_sip_enabled)
        return 0;
    
    return kmx_input_method_handle_message(KMX_MSG_PEN_MOVE, x, y);
}

static int kmx_input_method_handle_message(int msg, int wParam, int lParam)
{
    DTRACE("Enter kmx_input_method_handle_message enable: %d visible:%d keypad:0x%08X msg:%d p1:%d p2:%d", g_sip_enabled, g_sip_visible, (unsigned int)g_kmx_keypad, msg, wParam, lParam);
    if (!g_sip_enabled)
        return 0;
    
    if (g_kmx_keypad && g_sip_visible)
    {
        return keypad_handle_message(g_kmx_keypad, msg, wParam, lParam);
    }
    return 0;
}

int kmx_input_method_change_input_mode(int input_mode)
{
    const KMX_IME_CONFIG * ime_config = kmx_imm_get_ime_config(input_mode);
    unsigned char c = kmx_imm_get_case_info_by_mode(input_mode);
    
    DTRACE("Enter kmx_input_method_change_input_mode enable: %d visible:%d input_mode:%d", g_sip_enabled, g_sip_visible, input_mode);
    if (!g_sip_enabled)
        return 0;
    
    if (!g_kmx_keypad)
        return 0;

    if (ime_config)
    {
        g_kmx_keypad->curr_input_mode = (mmi_imm_input_mode_enum)input_mode;
        keypad_handle_message(g_kmx_keypad, KMX_MSG_IME_CHANGE, ime_config->input_method, ime_config->language);
        if(c != KMX_LANG_NOCASE)
            keypad_handle_message(g_kmx_keypad, KMX_MSG_CASE_CHANGE, ime_config->language, c);

        #if !defined(__NO_HANDWRITING__)
        {
            if (!mmi_imc_is_handwriting_disabled())
            {
                const sIMEModeDetails * mode_details_ptr;
                mmi_imc_pen_handwriting_type_enum hw_type;

                mode_details_ptr = mmi_ime_sdk_get_input_mode_array_item(input_mode);
                hw_type = (mmi_imc_pen_handwriting_type_enum)(U8)(mode_details_ptr->Handwriting_Attrib);

                if (hw_type == IMM_HANDWRITING_TYPE_NONE || !mmi_ime_hand_writing_hw_type_query(hw_type))
                {
                    keypad_enable_handwriting_panel(g_kmx_keypad, 0);
                    if (keypad_is_handwriting_panel_on(g_kmx_keypad))
                    {
                        keypad_exit_handwriting_panel(g_kmx_keypad, 1);
                    }
                }
                else
                {
                    keypad_enable_handwriting_panel(g_kmx_keypad, 1);
                }
             }
        }        
        #endif 
        return 1;
    }

    return 0;
}

int kmx_input_method_get_keypad_size(int * w, int * h)
{
    if (!g_sip_enabled)
    {
        if (w)
        {
            *w = 0;
        }
        if (h)
        {
            *h = 0;
        }
        return 0;
    }
    
    if (!g_kmx_keypad)
        return 0;

    keypad_get_size(g_kmx_keypad, w, h);
    return 1;
}

int kmx_input_method_get_keypad_pos(int * x, int * y)
{
    if (!g_sip_enabled)
    {
        if (x)
        {
            *x = 0;
        }
        if (y)
        {
            *y = 0;
        }
        return 0;
    }
    
    if (!g_kmx_keypad)
        return 0;

    keypad_get_pos(g_kmx_keypad, x, y);
    return 1;
}


void kmx_input_method_enable_keypad(int enabled)
{
    DTRACE("Enter kmx_input_method_enable_keypad enable: %d", enabled);
    g_sip_enabled = enabled;    
}

int kmx_input_method_is_keypad_enable(void)
{
    DTRACE("Enter kmx_input_method_is_keypad_enable enable: %d", g_sip_enabled);
    return g_sip_enabled;
}

static int kmx_input_method_is_valid_key(int key_code)
{
    return (key_code >= KEY_0 && key_code <= KEY_9) || key_code == KEY_RSK;
}

int kmx_input_method_handle_key_event(int key_code, int key_type)
{   
    extern int cstar_ime_is_ui_visible(void);

// komoxo 2010-3-4
    if(cstar_ime_is_ui_visible() || mmi_ime_sdk_get_state() == MMI_IME_SDK_STATE_MULTITAP)
        return 0;
    
    if (g_kmx_keypad && g_sip_visible)
    {
        if(key_type == KEY_EVENT_DOWN && kmx_input_method_is_valid_key(key_code) &&
            keypad_handle_message(g_kmx_keypad, KMX_MSG_KEY_PRESSED, key_code, 0))
        {
            return 1;
        }
        else if(key_type == KEY_LONG_PRESS && key_code == KEY_RSK)
        {
            keypad_handle_message(g_kmx_keypad, KMX_MSG_KEY_PRESSED, key_code, 1);
            return 1;
        }
        else if(key_type == KEY_EVENT_UP && key_code == KEY_RSK)
        {
            return 1;
        }
    }

    return 0;
}

void kmx_input_method_pen_down_in_editor(void)
{
    if (g_kmx_keypad && g_sip_visible)
    {
        kmx_pen_down_in_editor(g_kmx_keypad);
    }
}

void kmx_input_method_reset(void)
{
    if (g_kmx_keypad)
    {
        keypad_reset(g_kmx_keypad);
    }
}

#if !defined(__NO_HANDWRITING__)

int kmx_input_method_is_handwriting_panel_on(void)
{
    if (g_kmx_keypad)
    {
        return keypad_is_handwriting_panel_on(g_kmx_keypad);
    }
    return 0;
}

int kmx_input_method_exit_handwriting_panel(void)
{ 
    /* CAUTION: do not call this while change input mode. */   
    if (g_kmx_keypad)
    {
        return keypad_exit_handwriting_panel(g_kmx_keypad, 0);
    }
    return 0;
}
#endif /* #if !defined(__NO_HANDWRITING__) */

int kmx_input_method_on_editor_cursor_moved(void)
{    
    if (g_kmx_keypad && g_sip_enabled && g_sip_visible)
    {
        return keypad_on_editor_cursor_moved(g_kmx_keypad);
    }
    
    return 0;
}

void kmxsip_input_method_clear_keypad_area(void)
{
    if (g_kmx_keypad)
    {
        keypad_clear_keypad_area(g_kmx_keypad);
    }
}

#define MAX_ALLOW_INPUT_MODE_NUM 64
static mmi_imm_input_mode_enum g_kmx_allow_modes[MAX_ALLOW_INPUT_MODE_NUM];
static mmi_imm_input_mode_enum g_not_supported_mode_list[] = {
    IMM_INPUT_MODE_123,
    IMM_INPUT_MODE_SIGNED_123,
    IMM_INPUT_MODE_FLOAT_123,
    IMM_INPUT_MODE_PHONE_NUMBER,
    IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR,
    IMM_INPUT_MODE_SIGNED_FLOAT_123,
    IMM_INPUT_MODE_SIM_NUMERIC,
    IMM_INPUT_MODE_NONE
};
static int kmx_input_method_check_support_curr_input_modes(void)
{
    int allow_mode_num;
    allow_mode_num = kmx_ime_get_curr_allow_input_mode_list(g_kmx_allow_modes, MAX_ALLOW_INPUT_MODE_NUM);
    if (allow_mode_num == 1)
    {
        /* All can not switch num input would be affected. */
        mmi_imm_input_mode_enum mode;
        mmi_imm_input_mode_enum * p;
        mode = g_kmx_allow_modes[0];
        p = g_not_supported_mode_list;
        while (*p != IMM_INPUT_MODE_NONE)
        {
            if (*p == mode)
            {
                /* Find not supported mode */
                return 0;                
            }
            p++;
        }
    }
    return 1;
}

#endif /* #ifdef __MMI_KMX_TOUCH_INPUT__ */
