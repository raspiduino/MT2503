

#include "MMI_features.h"
#include "kmx_input_config.h"

#ifdef __MMI_KMX_TOUCH_INPUT__

#include "kmxsip_config.h"
#include "kmxsip_user_data.h"

#include "kmximmapi.h"
#include "kmxldbapi.h"
#include "Kmxsip_imm.h"


/* MTK related start */
#include "ImeGprot.h"
#include "Imc.h"
#include "GlobalDefs.h"
#include "Wgui_include.h"
#include "Wgui_categories_util.h"
#include "Wgui_softkeys.h"
#include "Imc_key.h"
#include "Imc_pen.h"

#include "kmxsip_keypad.h"
#include "kmxsip_input_method.h"
#include "kmxsip_adapter.h"

#include "kmx_input_prot.h"
#include "kmx_gui.h"
#include "mmi_rp_app_uiframework_def.h"


/* MTK related end */

#define MAX_ALLOW_INPUT_MODE_NUM 64

static KEYPAD g_kmx_sip_keypad;

static U32 keypad_send_ime_message(KEYPAD* keypad, 
                                    mmi_imc_editor_message_id_enum msg_id, 
                                    U32 param0, 
                                    U32 param1);

static KMX_IME_STATE keypad_get_ime_state(KEYPAD *keypad);

static int keypad_send_simple_imm_message(
                                    KEYPAD*     keypad,
                                    int         code,
                                    int         param1,
                                    int         param2);

static int keypad_sync_state(KEYPAD* keypad, int curr_state);

static void keypad_enter_handwriting_panel(KEYPAD*     keypad);

static int keypad_is_auto_capitalization_enabled(KEYPAD* keypad);

static void keypad_post_reset_skip_editor_cursor_movement(KEYPAD* keypad);

void kmx_timer_handler(void * arg)
{
    KEYPAD * keypad = &g_kmx_sip_keypad;

    keypad_handle_message(keypad, KMX_MSG_TIMER, (int)arg, 0);
}

static int kmx_ime_mode_convert_to_input_mode(int ime_id, int language, int case_info)
{
    int i;
    int allow_mode_num, input_mode = 0;
    const KMX_IME_CONFIG * config;    
    mmi_imm_input_mode_enum allow_modes[MAX_ALLOW_INPUT_MODE_NUM];

    allow_mode_num = kmx_ime_get_curr_allow_input_mode_list(allow_modes, MAX_ALLOW_INPUT_MODE_NUM);


    for (i = 0; i < allow_mode_num; i++)
    {
        int mode_case_info;
        input_mode = allow_modes[i];
        config = kmx_imm_get_ime_config(input_mode);
        if (!config)
            continue;        
        mode_case_info = kmx_imm_get_case_info_by_mode(input_mode);
        if (config->input_method == ime_id && 
            config->language == language && 
            (mode_case_info == KMX_LANG_NOCASE || case_info == mode_case_info))
            break;
    }

    if(i == allow_mode_num)
    {        
        return IMM_INPUT_MODE_NONE;
    }
    
    return input_mode;    
}

static void on_notify_ime_change(KEYPAD * keypad, int ime_id, int extra_info)
{

    int input_mode = 0;
    int language, case_info;         
    
    KMX_UNPACK_IME_CHAGE_PARAM2(extra_info, language, case_info);
    
    if(ime_id == KMX_IME_LATIN_MULTITAP || ime_id == KMX_IME_LATIN_SMART)
    {        
        keypad->support_composition = 1;
        #ifdef __MMI_IME_AUTO_CAPITALIZATION__            
        /* Check whether is case change only. */
        if (keypad_is_auto_capitalization_enabled(keypad))       
        {
            const KMX_IME_CONFIG* config;
            int curr_case_info;
            config = kmx_imm_get_ime_config(keypad->curr_input_mode);
            curr_case_info = kmx_imm_get_case_info_by_mode(keypad->curr_input_mode);
            if (config)
            {
                if ((config->language == language && config->input_method == ime_id) 
                    && (curr_case_info != case_info)
                    )
                    {
                        keypad->skip_editor_cursor_movement = 1;
                        keypad_post_reset_skip_editor_cursor_movement(keypad);
                    }
            }
        }        
        #endif 
    }

    input_mode = kmx_ime_mode_convert_to_input_mode(ime_id, language, case_info);
    
    if(input_mode == IMM_INPUT_MODE_NONE)
    {                
        return;
    }

    keypad->curr_input_mode = (mmi_imm_input_mode_enum)input_mode;                
    keypad->is_keypad_input_mode_changed = 1;
}

static void keypad_handle_key_press(KEYPAD *keypad, int bid, int flags)
{
    switch(bid)
    {
    case KMX_BID_BACK:
        if((flags & KMX_BF_REPEAT) || (flags & KMX_BF_HOLD))
        {
            keypad_send_ime_message(keypad, MMI_IMC_MESSAGE_CLEAR_ALL, 0, 0);
        }
        break;
    case KMX_BID_HIDE:        
        #ifdef __MMI_IME_FTE_ENHANCE__
        {
            mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
            mmi_ime_sdk_redraw_screen_by_state();
        }
        #endif
        break;
            
    default:
        break;
    }
}

static void keypad_sync_edit_to_multitap_state(KEYPAD *keypad, int cur_state)
{
    #ifdef __MMI_IME_AUTO_CAPITALIZATION__    
    mmi_imc_global_data_struct_p global_data = 0;
    mmi_ime_word_capital_state_enum old_capital_state, new_capital_state;
    
    if (!keypad_is_auto_capitalization_enabled(keypad))
    {
        return;
    }
    
    global_data = mmi_imc_get_global_data();
    
    if (!global_data)
        return;        
        
    old_capital_state = global_data->capital_state;
    
    if (old_capital_state > MMI_IME_WORD_CAPITAL_STATE_NONE && 
        old_capital_state < MMI_IME_WORD_CAPITAL_STATE_MAX)
    {
        mtk_keypad_notify_editor(keypad, KMX_NOTIFY_MSG_END_IME_COMP, 0, 0);
        keypad->is_cancel_insertion = 1;

        new_capital_state = mmi_imc_get_candidate_case_before_cursor();
        
        if (old_capital_state != new_capital_state)
        {
            global_data->capital_state = new_capital_state;
            mmi_imc_change_input_mode_according_to_capital_state(new_capital_state);    
        }        
    }        
    #endif
}

static void on_notify_state_changed(KEYPAD *keypad, int cur_state, int prev_state)
{
    if (cur_state == KMX_STATE_NORMAL && prev_state == KMX_STATE_MULTITAP)
    {
        keypad_sync_state(keypad, cur_state);
    }
    else if (cur_state >= KMX_STATE_MULTITAP0 && cur_state <= KMX_STATE_MULTITAP_MARK 
          && prev_state == KMX_STATE_EDIT)
    {
        keypad_sync_edit_to_multitap_state(keypad, cur_state);
    }
}

static void keypad_handle_notify(
                                 KEYPAD * keypad, 
                                 KMX_MSG * notify_msg)
{
    if(!keypad)
        return;
    
    if (!notify_msg)
        return;
    
    switch(notify_msg->code)
    {
    case KMX_NOTIFY_MSG_IME_CHANGE:
        on_notify_ime_change(keypad, notify_msg->param1, notify_msg->param2);
        break;
    case KMX_NOTIFY_MSG_KEY_PRESSED:
        keypad_handle_key_press(keypad, notify_msg->param1, notify_msg->param2);
        break;
    case KMX_NOTIFY_MSG_STATE_CHANGE:
        on_notify_state_changed(keypad, notify_msg->param1, notify_msg->param2);
        break;
    }
}

typedef struct
{
    unsigned short metric;
    unsigned short reduced_button_height;
    unsigned short qwerty_button_height;
}KMX_KEYBOARD_METRICS;

#ifdef __MMI_MAINLCD_176X220__
static KMX_KEYBOARD_METRICS g_kmx_keyboard_metrics = {176, 18, 18};
#elif defined(__MMI_MAINLCD_240X320__)
static KMX_KEYBOARD_METRICS g_kmx_keyboard_metrics = {240, 22, 25};
#elif defined(__MMI_MAINLCD_240X400__)
static KMX_KEYBOARD_METRICS g_kmx_keyboard_metrics = {240, 27, 31};
#elif defined(__MMI_MAINLCD_320X480__)
static KMX_KEYBOARD_METRICS g_kmx_keyboard_metrics = {320, 32, 35};
#else 
    #error ------------->Unsupported screen resolution for KMX TOUCH INPUT!
#endif

static int keypad_initialize_imm(KEYPAD* keypad);
static void keypad_draw_background(KEYPAD* keypad);

void keypad_update_size(KEYPAD * keypad)
{        
    int w, h;
    kmx_imm_get_window_size(keypad->imm, &w, &h);

    keypad->height = h;
    keypad->width = w;

    keypad->y = keypad->bottom_line - keypad->height + 1;
}

static int kmx_is_newline_disabled(void)
{
    extern S16 MMI_current_input_ext_type;
    return MMI_current_input_ext_type & INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
}

KEYPAD* keypad_create(void)
{
    KEYPAD* keypad;
    mmi_imui_param_struct ui_param;
    
    keypad = &g_kmx_sip_keypad;
    
    memset(keypad, 0, sizeof(KEYPAD));

    keypad->api.f_get_context    = (KMX_KEYPAD_GET_CONTEXT_PROC)   mtk_keypad_get_context;
    keypad->api.f_set_timer      = (KMX_KEYPAD_SET_TIMER_PROC)     mtk_keypad_set_timer;
    keypad->api.f_echo_button    = (KMX_KEYPAD_ECHO_BUTTON_PROC)   mtk_keypad_echo_button;
    keypad->api.f_get_text_size  = (KMX_KEYPAD_GET_TEXT_SIZE_PROC) mtk_keypad_get_text_size;
    keypad->api.f_draw_text      = (KMX_KEYPAD_DRAW_TEXT_PROC)     mtk_keypad_draw_text;
    keypad->api.f_draw_rect      = (KMX_KEYPAD_DRAW_RECT_PROC)     mtk_keypad_draw_rect;
    keypad->api.f_draw_background  = (KMX_KEYPAD_DRAW_BACKGROUND_PROC) mtk_keypad_draw_background;
    keypad->api.f_draw_button    = (KMX_KEYPAD_DRAW_BUTTON_PROC)   mtk_keypad_draw_button;
    keypad->api.f_notify_handler = (KMX_KEYPAD_IMM_NOTIFY_HANDLER) keypad_handle_notify;
    
    keypad->metric = g_kmx_keyboard_metrics.metric;
    
    memset(&ui_param, 0, sizeof(ui_param));
    mmi_ime_sdk_get_imui_param(&ui_param);

    keypad->x = ui_param.imui_x;
    keypad->bottom_line = ui_param.imui_bottom;

    if (!keypad_initialize_imm(keypad))
        return 0;
    
    keypad_update_size(keypad);

    mtk_create_echo_layer();        
    
    return keypad;
}

#ifndef KMX_CFG_USER_DATA_08
    static __inline void keypad_get_user_data(KMX_IME_CONFIG *config, int input_mode)
    {
        extern void kmx_find_user_data_by_im(int input_method, void **user_data, int *user_data_size);
        kmx_find_user_data_by_im(input_mode, &config->user_data, &config->user_data_size);
    }
#endif

static void kmx_set_case_caps(KMX_IME_CONFIG *config, int input_mode)
{        
    if(config->input_method == KMX_IME_LATIN_SMART || config->input_method == KMX_IME_LATIN_MULTITAP)
    {
        unsigned char case_info;
        case_info = kmx_imm_get_case_info_by_mode(input_mode);
        if (case_info != KMX_LANG_NOCASE)
        {
            switch(case_info) {                                
            case KMX_LANG_LOWERCASE:
                case_info = KMX_LANG_CAP_LOWERCASE;
            	break;
            case KMX_LANG_UPPERCASE:
                case_info = KMX_LANG_CAP_UPPERCASE;
            	break;
            case KMX_LANG_INITIALCASE:
                case_info = KMX_LANG_CAP_INITIALCASE;
            	break;
            default:
                /* Unknown case info. */
                MMI_ASSERT(0);
            }
            config->secondary_database = (const void*)((unsigned int)(config->secondary_database) | case_info);
        }
    }    
}

/* Valid Symbolist */

typedef struct {
    mmi_imm_input_type_enum input_type;    
    const unsigned short*   symbol_list;
}KMX_SYMBOL_LIST_ENTRY;

static KMX_SYMBOL_LIST_ENTRY g_kmx_valid_symbol_list_table[] = {
    {
        IMM_INPUT_TYPE_EMAIL,
        L"\\+-_.@!#$%&*/=?^{|}~"
    },

    {
        IMM_INPUT_TYPE_URL,
        L"\\+-_.@!#$%&*/=?^{|}~"
    },

    {
        IMM_INPUT_TYPE_NONE,
        0
    }

};

static const unsigned short* kmx_get_valid_symbol_list_by_input_type(mmi_imm_input_type_enum input_type)
{
    const KMX_SYMBOL_LIST_ENTRY* p;
    p = g_kmx_valid_symbol_list_table;

    while(p->input_type != IMM_INPUT_TYPE_NONE)
    {
        if (p->input_type == input_type)
            return p->symbol_list;
        p++;
    }
    return 0;
}

static int keypad_initialize_imm(KEYPAD* keypad)
{
  
    /* Sym Ime will always loaded */
    KMX_IME_CONFIG ime_list[KMX_IME_TYPE_MAX_NUM + 1];
    char actived_ime_types[KMX_IME_TYPE_MAX_NUM];

    mmi_imm_input_mode_enum allow_modes[MAX_ALLOW_INPUT_MODE_NUM]; 
    int allow_mode_num;
    int actived_ime_num = 0;
    int i;
    KMX_IME_CONFIG * sym_config;
    unsigned int properties = 0;

    kmx_load_user_data();

    memset(ime_list, 0, sizeof(ime_list));
    memset(actived_ime_types, 0, sizeof(actived_ime_types));
    
    allow_mode_num = kmx_ime_get_curr_allow_input_mode_list(allow_modes, MAX_ALLOW_INPUT_MODE_NUM);
    
    for (i = 0; i < allow_mode_num; i++)
    {
        kmx_input_method_type_enum ime_type;                

        ime_type = kmx_imm_get_ime_type(allow_modes[i]);
        if (ime_type == KMX_IME_TYPE_MAX_NUM)
        {
            continue;
        }
        
        if (actived_ime_types[ime_type] == 0)
        {
            /* Avoid Re-Inititalize, some input mode may map to the same ime */
            const KMX_IME_CONFIG * config;
            KMX_IME_CONFIG * cur_config = &ime_list[actived_ime_num];
            const void ** db_ptr;
            
            config = kmx_imm_get_ime_config_by_type(ime_type);
            if (!config)
                continue;
                        
            memcpy(cur_config, config, sizeof(KMX_IME_CONFIG));
            if (cur_config->primary_database)
            {
                db_ptr = (const void **)cur_config->primary_database;
                cur_config->primary_database = *db_ptr;
            }
            if (cur_config->secondary_database)
            {
                db_ptr = (const void **)cur_config->secondary_database;
                cur_config->secondary_database = *db_ptr;
            }
            
            if(cur_config->input_method == KMX_IME_LATIN_SMART || cur_config->input_method == KMX_IME_LATIN_MULTITAP)
            {
                MMI_ASSERT(cur_config->secondary_database == 0);
                kmx_set_case_caps(cur_config, allow_modes[i]);
            }            

        #ifndef KMX_CFG_USER_DATA_08
            keypad_get_user_data(cur_config, allow_modes[i]);
        #endif
            actived_ime_num++;
            /* record indices */
            actived_ime_types[ime_type] = (char)actived_ime_num;
        }
        else
        {
            KMX_IME_CONFIG * cur_config;
            cur_config = &ime_list[actived_ime_types[ime_type] - 1];
            kmx_set_case_caps(cur_config, allow_modes[i]);
        }         
    }    
    
    sym_config = &ime_list[actived_ime_num];
    sym_config->input_method = KMX_IME_SYM;
    /* get the sym language */
    if(actived_ime_num > 0)
    {
        KMX_IME_CONFIG * last_config = &ime_list[actived_ime_num - 1];
        sym_config->language = last_config->language;
        sym_config->ui_language = last_config->ui_language;
    }
    else
    {
        sym_config->language = KMX_LANG_ENGLISH;
        sym_config->ui_language = KMX_LANG_ENGLISH;
    }
    actived_ime_num++;
    
#if !defined(__NO_HANDWRITING__)
    /* set property */
    if (!mmi_imc_is_handwriting_disabled())
    {
        properties|= KMX_PROPERTY_HW_SWITCH;
    }
#endif /* #if !defined(__NO_HANDWRITING__) */

    if (kmx_is_newline_disabled())
    {
        properties|= KMX_PROPERTY_NO_SHOW_NEW_LINE_SYMBOL;        
    }    

    keypad->imm = kmx_imm_create_ex_with_properties((KMX_KEYPAD*)keypad, g_kmx_keyboard_metrics.metric, 
        g_kmx_keyboard_metrics.reduced_button_height, 
        g_kmx_keyboard_metrics.qwerty_button_height, 
        kmx_keypad_get_keypad_type(), ime_list, actived_ime_num,
        properties);

    if (!keypad->imm)
        return FALSE;

    kmx_imm_get_window_size(keypad->imm, &(keypad->width), &(keypad->height));

    {
        /* Set symbol filter by input type */
        const unsigned short* valid_symbol_list;
        valid_symbol_list = kmx_get_valid_symbol_list_by_input_type(mmi_ime_sdk_get_current_input_type());

        if (valid_symbol_list)
            keypad_send_simple_imm_message(keypad, KMX_MSG_SET_VALID_SYMBOL_LIST, (int)valid_symbol_list, 0);
    }

    return TRUE;
}

void keypad_destroy(KEYPAD* keypad)
{
    mtk_destory_echo_layer();
    
    mtk_keypad_notify_editor(keypad, KMX_NOTIFY_MSG_END_IME_COMP, 0, 0);

    kmx_imm_destroy(keypad->imm);
    
    mtk_keypad_stop_all_timer();

    kmx_save_user_data();
}

void keypad_on_paint(KEYPAD* keypad)
{
    KMX_GUI_RECT r;
    
    if (!kmx_input_method_is_visible())
        return;
        
    /* Update NO NEWLINE SHOW when paint */
    if (kmx_is_newline_disabled())
    {
        keypad_send_simple_imm_message(keypad, KMX_MSG_ADD_PROPERTY, KMX_PROPERTY_NO_SHOW_NEW_LINE_SYMBOL, 0);        
    }
    else
    {
        keypad_send_simple_imm_message(keypad, KMX_MSG_CLR_PROPERTY, KMX_PROPERTY_NO_SHOW_NEW_LINE_SYMBOL, 0);            
    }
    
    r.left = keypad->x;
    r.right = keypad->x + keypad->width;
    r.top = keypad->y;
    r.bottom = keypad->y + keypad->height - 1;
    
    kmx_gui_begin_paint(&r);
    
    keypad_draw_background(keypad);
    
    kmx_imm_paint_window(keypad->imm);
    
    kmx_gui_end_paint(&r);
}

static int keypad_sync_state(KEYPAD* keypad, int curr_state)
{
    mmi_ime_sdk_state_enum prev_state, new_state;

    prev_state = mmi_ime_sdk_get_state();

    switch(curr_state) {
    case KMX_STATE_NORMAL:        
        new_state = MMI_IME_SDK_STATE_INITIAL;        
        break;
    case KMX_STATE_MULTITAP:
        new_state = (mmi_ime_sdk_state_enum)MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_MULTITAP;
        break;
    case KMX_STATE_MULTITAP0:
    case KMX_STATE_MULTITAP1:
    case KMX_STATE_MULTITAP2:
    case KMX_STATE_MULTITAP3:
    case KMX_STATE_MULTITAP4:
    case KMX_STATE_MULTITAP5:
    case KMX_STATE_MULTITAP6:
    case KMX_STATE_MULTITAP7:
    case KMX_STATE_MULTITAP8:
    case KMX_STATE_MULTITAP9:
    case KMX_STATE_MULTITAP_MARK:
        new_state = (mmi_ime_sdk_state_enum)MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_MULTITAP_HOVER;
        break;
    default:
        new_state = (mmi_ime_sdk_state_enum)MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_INPUT;
        break;
    }
    
    if (new_state != prev_state)
    {
        mmi_ime_sdk_set_state(new_state);
    }    
    return new_state != prev_state;    
}

static int kmx_ime_is_same_smart_mode(int input_mode, int prev_input_mode)
{
    const sIMEModeDetails *cur_details, *pre_details;
    cur_details = mmi_ime_sdk_get_input_mode_array_item((mmi_imm_input_mode_enum)input_mode);
    pre_details = mmi_ime_sdk_get_input_mode_array_item((mmi_imm_input_mode_enum)prev_input_mode);
    
    if((cur_details->Mode_Special_Attrib  & IME_MODE_ATTR_SMART && cur_details->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
        && (pre_details->Mode_Special_Attrib  & IME_MODE_ATTR_SMART && pre_details->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
        )
    {
        return cur_details->lang_id == pre_details->lang_id;
    }
    return 0;
}   

static int kmx_ime_change_ime(int input_mode, int prev_input_mode)
{        
    mmi_ime_sdk_set_current_input_mode((mmi_imm_input_mode_enum)input_mode);
    if (mmi_ime_sdk_change_input_mode((mmi_imm_input_mode_enum)input_mode))
    {
        /* If only case change in smart alphabetic, dont set state to initial */
        if (!kmx_ime_is_same_smart_mode(input_mode, prev_input_mode))
        {
            mmi_ime_sdk_set_state(MMI_IME_SDK_STATE_INITIAL);
        }
        return 1;
    }

    return 0;
}

static void keypad_send_imm_message(
    KEYPAD*     keypad,
    int         code,
    int         param1,
    int         param2)
{
    KMX_MSG message;
    KMX_OUTPUT output;
    int status;
    KMX_IME_STATE curr_state;
    int sys_state_changed = 0;
    
    if (!keypad)
        return;            

    /* Avoid blink. komoxo 2009-10-20 */
    gui_lock_double_buffer();

    memset(&output, 0, sizeof(output));    

    message.code = code;
    message.param1 = param1;
    message.param2 = param2;
    status = kmx_imm_handle_message(keypad->imm, &message, &output);

    #if !defined(__NO_HANDWRITING__)
    if ((status & KMX_FLAG_ENTER_HW) && !mmi_imc_is_handwriting_disabled())
    {        
        keypad_enter_handwriting_panel(keypad);
        mmi_ime_sdk_redraw_screen_by_state();
        gui_unlock_double_buffer();
        gdi_lcd_repaint_all();
        return;
    }
    #endif /* #if !defined(__NO_HANDWRITING__) */

    /* IME change && CASE change dont redraw screen */
    if (code == KMX_MSG_IME_CHANGE || code == KMX_MSG_CASE_CHANGE)
    {
        status &= ~KMX_FLAG_UPDATE_DISPLAY;
    }
        
    if (status & KMX_FLAG_UPDATE_SIZE)
    {        
        keypad_update_size(keypad);     
    }        
    if (keypad->support_composition)
    {
        if (output.commit_length > 0)
        {
            if (output.commit_text[0] == WCHAR_BACKSPACE)
            {
                keypad_send_ime_message(keypad, MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0xFFFF); 
                output.commit_length = 0;
            }
            else
            {
                mtk_keypad_notify_editor(keypad, KMX_NOTIFY_MSG_CLEAR_IME_COMP, 0, 0);
                output.commit_text[output.commit_length] = L'\0';
                if (keypad->is_cancel_insertion)
                {
                    keypad->is_cancel_insertion = 0;
                }
                else
                {
                    keypad_send_ime_message(keypad, MMI_IMC_MESSAGE_INSERT_STRING, (U32)output.commit_text, 0);
                }                    

                keypad->output.composition_length = 0;
            }
        }
        if (output.flags == keypad->output.flags &&
            output.commit_length == 0 &&
            output.composition_length == keypad->output.composition_length &&
            memcmp(output.composition_text, keypad->output.composition_text, sizeof(wchar_t) * output.composition_length) == 0)
        {
            /* Do nothing when composition not changed for speed up */
        }
        else
        {
            keypad->output_sequencial_number++;
            keypad->output.sequencial_number = keypad->output_sequencial_number;

            if(output.composition_length > 0)
            {
                /* KMX TEMP HANDLE, comp text must be zero length ended, overboundary problem may be introduced. */
                output.composition_text[output.composition_length] = 0;
                mtk_keypad_notify_editor(keypad, KMX_NOTIFY_MSG_SET_IME_COMP, (int)output.composition_text, output.composition_length);
            }
            else if(keypad->output.composition_length > 0 && output.composition_length == 0)
            /* Backspace button pressed */
            {
                mtk_keypad_notify_editor(keypad, KMX_NOTIFY_MSG_CLEAR_IME_COMP, 0, 0);                
            }

            keypad->output.flags = output.flags;

            keypad->output.commit_length = output.commit_length;
            memcpy(keypad->output.commit_text, output.commit_text, sizeof(wchar_t) * output.commit_length);
            keypad->output.commit_text[output.commit_length] = L'\0';
            
            keypad->output.composition_length = output.composition_length;
            memcpy(keypad->output.composition_text, output.composition_text, sizeof(wchar_t) * output.composition_length);
            keypad->output.composition_text[output.composition_length] = L'\0';                        
        }
    }
    else
    {
        if (output.commit_length > 0)
        {
            if (output.commit_length == 1 && output.commit_text[0] == WCHAR_BACKSPACE)
            {
                keypad_send_ime_message(keypad, MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0xFFFF); 
            }
            else
            {
                if(output.commit_length == 1)
                {
                    keypad_send_ime_message(keypad, MMI_IMC_MESSAGE_INSERT_CHAR, output.commit_text[0], 0);
                }
                else
                {
                    output.commit_text[output.commit_length] = L'\0';
                    if (keypad->is_cancel_insertion)
                    {
                        keypad->is_cancel_insertion = 0;
                    }
                    else
                    {
                        keypad_send_ime_message(keypad, MMI_IMC_MESSAGE_INSERT_STRING, (U32)output.commit_text, 0);
                    }
                }
            }
        }
    }

    /* Redraw right softkey */
    /* Setting right softkey handler must consider the ime state. komoxo 2010-02-22  */
    curr_state = keypad_get_ime_state(keypad);
        
    sys_state_changed = keypad_sync_state(keypad, curr_state);   
    
    if ((status & KMX_FLAG_UPDATE_DISPLAY) || sys_state_changed)
    {
        mmi_ime_sdk_redraw_screen_by_state();
        /* Avoid blink. komoxo 2009-10-20 */
        gui_unlock_double_buffer();
        gdi_lcd_repaint_all();
    }
    else
    {
        gui_unlock_double_buffer();
    }
    
    /* FOR FIX COMPOSITION BUG */
    /* input mode may have to change since we press button */
    if (keypad->is_keypad_input_mode_changed 
        && (keypad->curr_input_mode != mmi_ime_sdk_get_current_input_mode()))
    {        
        keypad->is_keypad_input_mode_changed = 0;
        if (kmx_ime_change_ime(keypad->curr_input_mode, mmi_ime_sdk_get_current_input_mode()))
        {
		    /* komoxo 2009-12-11 */
		    
            keypad_send_ime_message(keypad, MMI_IMC_MESSAGE_MODE_CHANGED, 0, 0);

            mmi_ime_sdk_redraw_screen_by_state();
        }
    }
    keypad->last_input_mode = mmi_ime_sdk_get_current_input_mode();
    
}

static U32 keypad_send_ime_message(KEYPAD* keypad, mmi_imc_editor_message_id_enum msg_id, U32 param0, U32 param1)
{
    mmi_imc_message_struct msg;
        
    msg.message_id = msg_id;
    msg.param_0 = param0;
    msg.param_1 = param1;
    
    return mmi_ime_sdk_send_editor_msg(&msg);
}

static int ScreenToKeypad(KEYPAD* keypad, int screen_x, int screen_y, int * keypad_x, int * keypad_y)
{
    if (!keypad_x || !keypad_y)
        return 0;
    
    if(screen_x < keypad->x || screen_y < keypad->y || screen_x > keypad->x + keypad->width || screen_y > keypad->y + keypad->height)
        return 0;

    *keypad_x = screen_x - keypad->x;
    *keypad_y = screen_y - keypad->y;
   return 1;
}

static void keypad_update_pen_down_pos(KEYPAD* keypad, int x, int y)
{    
    keypad->is_pen_down_on_keypad = 1;
    keypad->last_pen_down_x = x;
    keypad->last_pen_down_y = y;    
}

static void keypad_reset_pen_down_pos(KEYPAD* keypad)
{
    keypad->is_pen_down_on_keypad = 0;
    keypad->last_pen_down_x = 0;
    keypad->last_pen_down_y = 0;
}

static int keypad_append_pen_up_msg(KEYPAD* keypad, int x, int y)
{ 
    if (keypad->is_pen_down_on_keypad)
    { 
        keypad_reset_pen_down_pos(keypad);
        keypad_send_imm_message(keypad, KMX_MSG_PEN_DOWN, 0, 0);
        keypad_send_imm_message(keypad, KMX_MSG_PEN_UP, 0, 0);        
        
        return 1;        
    }

    /* A pen down up pair not on keypad  */        
        return 0;       
}

static int keypad_handle_pen_event(KEYPAD * keypad, int msg, int wParam, int lParam)
{
    int x, y;             

    if (ScreenToKeypad(keypad, wParam, lParam, &x, &y))
    {
        /* Pen on keypad */

        if (msg == KMX_MSG_PEN_DOWN || msg == KMX_MSG_PEN_MOVE)
            keypad_update_pen_down_pos(keypad, x, y);

        if (msg == KMX_MSG_PEN_UP)
            keypad_reset_pen_down_pos(keypad);

        keypad_send_imm_message(keypad, msg, x, y);
        return 1;
    }

    /* pen out of keypad */
    /* Pen down out of keypad is ignored */
    
    if (msg == KMX_MSG_PEN_MOVE || msg == KMX_MSG_PEN_UP)
        return keypad_append_pen_up_msg(keypad, wParam, lParam);;
    
    return 0;    
}

static KMX_IME_STATE keypad_get_ime_state(KEYPAD *keypad)
{
    KMX_MSG message;
    KMX_IME_STATE state;
    
    state = KMX_STATE_NORMAL;
    message.code = KMX_MSG_GET_IME_STATE;
    message.param1 = (int)&state;
    message.param2 = 0;
    kmx_imm_handle_message(keypad->imm, &message, 0);
    return state;
}

void keypad_reset(KEYPAD * keypad)
{
    KMX_MSG message = {0};
    int status;
        
    mtk_keypad_notify_editor(keypad, KMX_NOTIFY_MSG_END_IME_COMP, 0, 0);
    
    keypad->output.composition_length = 0;
    
    mtk_keypad_stop_all_timer();
    keypad->is_timer1_actived = 0;
    keypad->is_timer2_actived = 0;    

    message.code = KMX_MSG_RESET;
    status = kmx_imm_handle_message(keypad->imm, &message, 0);

    if (status & KMX_FLAG_UPDATE_SIZE)
    {
        keypad_update_size(keypad);
    }    
}

static int keypad_handle_key_event(KEYPAD * keypad, int wParam, int lParam)
{
    if(keypad_get_ime_state(keypad) != KMX_STATE_NORMAL ||
        (keypad->support_composition && keypad->output.composition_length > 0))
    {
        if(wParam == KEY_RSK)
        {
            if(lParam)
            {
                keypad_send_imm_message(keypad, KMX_MSG_KEY_PRESSED, KMX_BID_BACK, KMX_BF_HOLD);
            }
            else
            {
                keypad_send_imm_message(keypad, KMX_MSG_KEY_PRESSED, KMX_BID_BACK, lParam);
            }
            return 1;
        }

        if(wParam >= KEY_0 &&  wParam <= KEY_9)
        {
            keypad_reset(keypad);
        }
    }

    return 0;
}

/* Erase the keypad first when hide. komoxo 2009-10-20 */
static void keypad_hide_window(KEYPAD * keypad)
{
    if (keypad)
    {              
        mmi_ime_sdk_redraw_imui_background(keypad->x, keypad->y, keypad->x + keypad->width - 1, keypad->y + keypad->height - 1);
    }
}


int keypad_handle_message(KEYPAD * keypad, int msg, int wParam, int lParam)
{    
    int handled = 0;    
    
    switch(msg) {
    case KMX_MSG_TIMER:
        keypad_send_imm_message(keypad, KMX_MSG_TIMER, wParam, 0);
        break;
    case KMX_MSG_PEN_DOWN:
    case KMX_MSG_PEN_MOVE:
    case KMX_MSG_PEN_UP:   
        handled = keypad_handle_pen_event(keypad, msg, wParam, lParam);
    	break;
    case KMX_MSG_METRIC_CHANGE:
        break;
    case KMX_SIP_MSG_PAINT:
        keypad_on_paint(keypad);
        break;
    case KMX_SIP_MSG_SHOW:
        break;
    case KMX_SIP_MSG_HIDE:
        /* Erase the keypad first when hide. komoxo 2009-10-20 */
        keypad_hide_window(keypad);
        break;
    case KMX_MSG_IME_CHANGE:        
        keypad_send_imm_message(keypad, KMX_MSG_IME_CHANGE, wParam, lParam);
        if(wParam == KMX_IME_LATIN_MULTITAP || wParam == KMX_IME_LATIN_SMART)
        {
            keypad->support_composition = 1;
        }
        break;
    case KMX_MSG_CASE_CHANGE:
        keypad_send_imm_message(keypad, KMX_MSG_CASE_CHANGE, wParam, lParam);
        break;
    case KMX_MSG_KEY_PRESSED:
        handled = keypad_handle_key_event(keypad, wParam, lParam);
        break;
    default:
        break;
    }
    return handled;
}

void keypad_get_size(KEYPAD* keypad, int* width, int* height)
{
    if (!keypad)
        return;

    if (width)
        *width = keypad->width;

    if (height)
        *height = keypad->height;
}

void keypad_get_pos(KEYPAD* keypad, int *x, int *y)
{
    if (!keypad)
        return;

    if(x)
        *x = keypad->x;

    if(y)
        *y = keypad->y;
}

static void keypad_draw_background(KEYPAD* keypad)
{
    if (kmx_input_method_is_visible())
        mtk_keypad_draw_rect(keypad, 0, 0, keypad->width, keypad->height, DEFAULT_BK_COLOR);
}

void kmx_pen_down_in_editor(KEYPAD* keypad)
{
    if(keypad->output.composition_length > 0)
    {
        keypad_reset(keypad);
    }
}

void keypad_update_bottom_line(KEYPAD * keypad, int bottom_line)
{
    if (!keypad)
        return;

    keypad->bottom_line = bottom_line;
    keypad->y           = keypad->bottom_line - keypad->height + 1;
}

static int g_kmx_keypad_type = KMX_KEYBOARD_TYPE_DIGIT;
void kmx_keypad_set_keypad_type(int keypad_type)
{
    if (keypad_type >= KMX_KEYBOARD_TYPE_MAX || keypad_type < KMX_KEYBOARD_TYPE_DIGIT)
        MMI_ASSERT(0);

    g_kmx_keypad_type = keypad_type;
}

int kmx_keypad_get_keypad_type(void)
{
#if !defined(__MMI_KMX_NORMAL_TOUCH_INPUT__)
    return KMX_KEYBOARD_TYPE_QWERTY;
#endif

#if !defined(__MMI_KMX_QWERTY_TOUCH_INPUT__)
    return KMX_KEYBOARD_TYPE_DIGIT;
#endif

    return g_kmx_keypad_type;
}

static int keypad_send_simple_imm_message(
    KEYPAD*     keypad,
    int         code,
    int         param1,
    int         param2)
{
    KMX_MSG message;

    message.code = code;
    message.param1 = param1;
    message.param2 = param2;
    return kmx_imm_handle_message(keypad->imm, &message, 0);        
}

#if !defined(__NO_HANDWRITING__)
static void keypad_enter_handwriting_panel(KEYPAD* keypad)
{
    keypad->is_handwriting_panel_on = 1;
    mmi_imc_pen_set_curr_input_style(MMI_IMC_PEN_INPUT_STYLE_HW);
	#ifdef __MMI_IME_V3__
	    mmi_imc_pen_vk_enable_single_block_hw(MMI_TRUE);
	#else
		mmi_imc_pen_vk_enable_single_block_hw();
	#endif
}

int keypad_exit_handwriting_panel(KEYPAD* keypad, int on_input_mode_changing)
{
    if (keypad->is_handwriting_panel_on)
    {
        mmi_imc_cancel_timer();
        
        if (!on_input_mode_changing)
        {
            /*  Input mode not changed, but switch from IM LIST to normal */
            keypad_send_imm_message(keypad, KMX_MSG_KEY_PRESSED, KMX_BID_CANCEL, 0);
        }
        mmi_imc_pen_set_curr_input_style(IMM_KEYPAD_QWERTY);
        mmi_imc_pen_stop_singleblock_handwriting();
        /* 
         * Trick!!! shall we update the keyboard type according to the input mode?
         * If not set, GUI_VIRTUAL_KEYBOARD_TRAY would fire handwriting then. 
         */
        mmi_ime_sdk_set_virtual_keyboard_type(GUI_VIRTUAL_KEYBOARD_ENGLISH);
        keypad->is_handwriting_panel_on = 0;
        mmi_ime_sdk_set_state(MMI_IME_SDK_STATE_INITIAL);
        return 1;
    }
    return 0;
}

int keypad_is_handwriting_panel_on(KEYPAD* keypad)
{
    return keypad->is_handwriting_panel_on != 0;
}

void keypad_enable_handwriting_panel(KEYPAD* keypad, int enable)
{
    if (keypad)
    {
        if (enable)
        {
            keypad_send_simple_imm_message(keypad, KMX_MSG_ADD_PROPERTY, KMX_PROPERTY_HW_SWITCH, 0);
        }
        else
        {
            keypad_send_simple_imm_message(keypad, KMX_MSG_CLR_PROPERTY, KMX_PROPERTY_HW_SWITCH, 0);
        }
    }
}
#endif /* #if !defined(__NO_HANDWRITING__) */

static int keypad_is_auto_capitalization_enabled(KEYPAD* keypad)
{
    return kmx_ime_is_auto_capitalization_enabled();
}

int keypad_on_editor_cursor_moved(KEYPAD* keypad)
{
    #ifdef __MMI_IME_AUTO_CAPITALIZATION__        
    mmi_imc_global_data_struct_p global_data = 0;
    mmi_ime_word_capital_state_enum old_capital_state, new_capital_state;
    mmi_ime_sdk_state_enum state;
        
    if (!keypad_is_auto_capitalization_enabled(keypad))
    {
        return 0;
    }
    
    if (keypad->skip_editor_cursor_movement)
    {
        return 1;
    }
    
    state = mmi_ime_sdk_get_state();
    
    if (state == MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_MULTITAP || state == MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_INPUT)
    {
        /* eat this event in mt and input state */
        return 1;
    }
    
    global_data = mmi_imc_get_global_data();

    if (!global_data)
        return 0;        

    old_capital_state = global_data->capital_state;

    if (old_capital_state > MMI_IME_WORD_CAPITAL_STATE_NONE && 
        old_capital_state < MMI_IME_WORD_CAPITAL_STATE_MAX)
    {        
        new_capital_state = mmi_imc_get_candidate_case_before_cursor();

        if (old_capital_state != new_capital_state
            && (!global_data->capital_lock || new_capital_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER))
        {
            MMI_BOOL change_success = MMI_FALSE;
            global_data->capital_state = new_capital_state;
            global_data->capital_lock = MMI_FALSE;
            keypad_send_simple_imm_message(keypad, KMX_MSG_LOCK_IME, 1, 0);
            change_success = mmi_imc_change_input_mode_according_to_capital_state(new_capital_state);
            keypad_send_simple_imm_message(keypad, KMX_MSG_LOCK_IME, 0, 0);
            if (change_success)
            {                
                mmi_ime_sdk_redraw_screen_by_state();
            }            
        }
    }
    return 1;
    #else
    return 0;
    #endif    
}

void keypad_clear_keypad_area(KEYPAD* keypad)
{
    if (keypad->prev_width && keypad->prev_height)
        mmi_ime_sdk_redraw_imui_background(keypad->prev_x, keypad->prev_y, 
                                           keypad->prev_x + keypad->prev_width - 1,
                                           keypad->prev_y + keypad->prev_height - 1);
                                       
}

static void keypad_reset_skip_editor_cursor_movement_int(void* arg)
{
    KEYPAD* keypad;
    keypad = (KEYPAD*) arg;
    keypad->skip_editor_cursor_movement = 0;
}

static void keypad_post_reset_skip_editor_cursor_movement(KEYPAD* keypad)
{
    gui_start_timer_ex(0, keypad_reset_skip_editor_cursor_movement_int, keypad);
}

void keypad_save_curr_window_pos(KEYPAD* keypad)
{
    if (keypad)
    {
        keypad->prev_x = keypad->x;
        keypad->prev_y = keypad->y;
        keypad->prev_width = keypad->width;
        keypad->prev_height = keypad->height;
    }
}

#endif /* #ifdef __MMI_KMX_TOUCH_INPUT__ */
