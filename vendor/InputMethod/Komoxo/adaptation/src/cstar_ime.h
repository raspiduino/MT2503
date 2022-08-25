#ifndef CSTAR_IME_H
#define CSTAR_IME_H

#ifndef CSK2API_H
#include "csk2api.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif
	
#define CS_UI_FONT              int
#define CS_UI_COLOR             int
#define CS_UI_WCHAR             unsigned short

#define CS_UI_TEXT_FONT         0
#define CS_UI_LABEL_FONT        1
#define CS_UI_FONT_COUNT        2

#define CS_UI_BK_COLOR          0
#define CS_UI_TEXT_COLOR        1
#define CS_UI_HOT_COLOR_1       2
#define CS_UI_HOT_COLOR_2       3
#define CS_UI_HOT_COLOR_3       4
#define CS_UI_HOT_TEXT_COLOR    5
#define CS_UI_HOT_BK_COLOR      6
#define CS_UI_HOT_TEXT_COLOR_1  7
#define CS_UI_HOT_BK_COLOR_1    8
#define CS_UI_DIGIT_LABEL_COLOR 9
#define CS_UI_TIP_TEXT          10
#define CS_UI_COLOR_COUNT       11

typedef struct tagCS_UI_RECT
{
    int                         left;
    int                         top;
    int                         right;
    int                         bottom;
} CS_UI_RECT;

typedef struct tagCS_UI_EXTRA_METRICS
{
    unsigned short              line_top_gap;
    unsigned short              line_bottom_gap;
    unsigned short              line_left_gap;
    unsigned short              line_right_gap;
} CS_UI_EXTRA_METRICS;

typedef enum
{
    CS_UI_KEY_BASE = 0x100,

    CS_UI_KEY_0,
    CS_UI_KEY_1,
    CS_UI_KEY_2,
    CS_UI_KEY_3,
    CS_UI_KEY_4,
    CS_UI_KEY_5,
    CS_UI_KEY_6,
    CS_UI_KEY_7,
    CS_UI_KEY_8,
    CS_UI_KEY_9,
    CS_UI_KEY_L1,
    CS_UI_KEY_L2,
    CS_UI_KEY_L3,
    CS_UI_KEY_R1,
    CS_UI_KEY_R2,
    CS_UI_KEY_R3,
    CS_UI_KEY_STAR,
    CS_UI_KEY_POUND,
    CS_UI_KEY_LEFT,
    CS_UI_KEY_RIGHT,
    CS_UI_KEY_UP,
    CS_UI_KEY_DOWN,
    CS_UI_KEY_OK,
    CS_UI_KEY_LSK,
    CS_UI_KEY_RSK,

    CS_UI_KEY_A = CS_UI_KEY_BASE + 0x61,
    CS_UI_KEY_LAST = CS_UI_KEY_A + 32,

    CS_UI_KEY_END
} CS_UI_KEY;

typedef enum
{
    CS_IMM_STATE_INITIAL,
    CS_IMM_STATE_VK_CAND,
    CS_IMM_STATE_CAND_SELECT,
    CS_IMM_STATE_MULTITAP

} CS_IMM_STATE;

typedef void (*IndicatorPainter)(const CS_UI_RECT* r, CS_UI_COLOR c);

typedef struct  
{
    int width;
    int height;
    IndicatorPainter paint;           
}CS_UI_INDICATOR;

/* Adapter API */

void* cs_gui_load_ime_userdata(int *length);
void cs_gui_save_ime_userdata(void *data, int length);
int cs_gui_load_ime_options(void *data, int *length);
void cs_gui_save_ime_options(void *options, int length);
void cs_gui_disable_ime_timer(void);
void cs_gui_enable_ime_timer(int interval, void (*time_proc)(void));
void cs_initialize_tables(void);
int cs_gui_get_char_height(int font, CS_UI_WCHAR c);
int cs_gui_get_line_height(int font);
int cs_gui_get_char_width(int font, CS_UI_WCHAR c);
int cs_gui_get_text_width(int font, const CS_UI_WCHAR* text, int text_len);
void cs_gui_draw_pixel(int x, int y, int pixel_color);
void cs_gui_draw_rect(const CS_UI_RECT* r, int rect_color);
void cs_gui_draw_text(int x, int y, int font,
    const CS_UI_WCHAR* text, int text_len, int text_color);
void cs_gui_begin_paint(const CS_UI_RECT* r);
void cs_gui_end_paint(const CS_UI_RECT* r);
void cs_gui_set_state(CS_IMM_STATE state);
int CS_GuiMode2CstarMode(int input_method);
int kmx_is_pinyin_ime(int m);
int kmx_is_zhuyin_ime(int m);
int cs_ui_cfg_imewnd_right(void);
void cs_set_comp(const unsigned short *text, int length);
void cs_clear_comp(void);
void cs_end_comp(void);
int cs_ime_wcslen(unsigned short *text);
void cs_gui_invalidate(void);
void cs_delete_char(void);
void cs_insert_text(const unsigned short *text, int length);
int cstar_ime_is_suretype_enabled(void);

void cs_get_hint_by_im(int im);
CS_UI_WCHAR * cs_get_hint_text(int index);

/* Platform Independent API */
int cstar_ime_handle_event(int is_char_event, int key, int presshold);
unsigned long cstar_ime_get_fuzzy(void);
void cstar_ime_set_fuzzy(unsigned long value);
unsigned long cstar_ime_get_pinyin_mode(void);
void cstar_ime_set_pinyin_mode(unsigned long value);
unsigned long cstar_ime_get_candidate_mode(void);
void cstar_ime_set_candidate_mode(unsigned long value);
unsigned int cstar_ime_get_martian_script_option(void);
void cstar_ime_set_martian_script_option(unsigned int enable);

void cstar_ime_close_input_method(void);
void cstar_ime_set_input_method(int input_method);

typedef int (*CS_TRAVERSE_FUNC) (int im_mode, const unsigned short * word, int word_len);
int cstar_ime_traverse_predefined_user_words(CS_TRAVERSE_FUNC func);

typedef void (*CS_HOOK_FUNC) (void);
typedef void (*CS_HOOK_FUNC_EX) (int);
typedef int (*CS_HOOK_FUNC_EX2) (unsigned short*, int);
typedef unsigned short(*CS_HOOK_FUNC_EX3) (void);
typedef int (*CS_HOOK_FUNC_EX4) (void);

void cstar_ime_add_user_multitap(int im_id, const CS_MULTI_STRING_TABLE * mt_table);
CS_HOOK_FUNC cstar_ime_set_initialize_hook(CS_HOOK_FUNC hook);
CS_HOOK_FUNC_EX cstar_ime_set_change_input_method_hook(CS_HOOK_FUNC_EX hook);
CS_HOOK_FUNC_EX2 cstar_ime_set_update_comp_text_hook(CS_HOOK_FUNC_EX2 hook);
CS_HOOK_FUNC_EX3 cstar_ime_set_get_prev_char_hook(CS_HOOK_FUNC_EX3 hook);
CALLBACK_READ_UPDATE_DATA cstar_ime_set_read_update_data_callback(CALLBACK_READ_UPDATE_DATA callback);
CS_HOOK_FUNC_EX4 cstar_ime_set_get_arrow_style_hook(CS_HOOK_FUNC_EX4 hook);
CS_HOOK_FUNC_EX4 cstar_ime_set_update_case_hook(CS_HOOK_FUNC_EX4 hook);
CS_HOOK_FUNC_EX4 cstar_ime_set_get_curr_capital_state_hook(CS_HOOK_FUNC_EX4 hook);
CS_HOOK_FUNC cstar_ime_set_remove_ime_options_hook(CS_HOOK_FUNC hook);
void cstar_ime_set_custom_indicator(CS_UI_INDICATOR *lidt, CS_UI_INDICATOR *ridt);
int cstar_ime_is_custom_indicator_enable(void);
int cstar_ime_get_ime_window_rect(CS_UI_RECT * r);

void kmx_update_user_word_start(void);
void kmx_update_user_word_finalize(void);
void kmx_load_update_data(void);
int kmx_read_update_data(unsigned char* buf, int offset, int len);

int cstar_ime_get_input_method(void);

typedef struct {
    unsigned int    input_mode;
    unsigned int    flags;
    unsigned char   case_info;
    unsigned char   ime;
    unsigned char   reserved;    
}KMX_INPUT_MODE_ATTRIBUTES;

const KMX_INPUT_MODE_ATTRIBUTES* kmx_get_curr_input_mode_attr(void);

int kmx_get_input_mode_attr(unsigned int input_mode, KMX_INPUT_MODE_ATTRIBUTES* attr);

int cstar_ime_is_ime_support(void);
int cstar_ime_handle_key(int key_code, int key_type, int ucs2_value);
int cstar_ime_paint_window(int x, int bottom_y);
void cstar_ime_reset_state(void);

int kmx_ime_paint_ime_window(int x, int bottom_y);

int cstar_pen_down_handler(int x, int y);
int cstar_pen_up_handler(int x, int y);
int cstar_pen_move_handler(int x, int y);

void kmx_ime_setup_input_method(void);
void kmx_ime_close_input_method(void);
int kmx_ime_set_input_mode(int input_mode);

extern int kmx_ime_handle_stroke_char(int c);

int kmx_default_handle_key(int key_code, unsigned short key_type, int ucs2_value);

void kmx_get_ime_window_difference(CS_UI_RECT * r);
void kmx_save_ime_window_pos(int bottom_line);
int kmx_get_ime_window_height(void);

int kmx_ime_update_case(int case_info);
int kmx_get_curr_case_info(void);
void kmx_set_curr_case_info(int case_info);

#ifdef __MMI_KMX_HALF_QWERTY_BOPOMOFO__
int kmx_ime_handle_bopomofo_half_qwerty_char(int pen_event, unsigned short ch, int vk_event);
int kmx_ime_handle_vk_event_callback(int key_event, int key_param, int ret_addr, int ret_val_addr);
#endif

void kmx_ime_config_feature_options(void);

CS_IMM_OPTIONS * cstar_ime_get_cur_options(void);
int cstar_ime_update_options(void);
void cstar_ime_reset_ime_options(void);

#ifdef __cplusplus
}
#endif

#endif
