
#ifndef KMXSIP_ADPTER_H
#define KMXSIP_ADPTER_H

#ifndef KMXSIP_CONFIG_H
	#include "Kmxsip_config.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define KMX_MAX_COMMIT                  64
#define KMX_MAX_COMPOSITION             64
#define KMX_FLAG_COMP_TEXT              0x0001

#define WCHAR_BACKSPACE         0x08
#define WCHAR_TAB               0x09
#define WCHAR_RETURN            0x0D
#define WCHAR_SPACE             0x20

typedef struct tag_KEYPAD KEYPAD;

typedef enum
{
    KMX_NOTIFY_MSG_NONE,

    KMX_NOTIFY_MSG_CLEAR_IME_COMP,
    KMX_NOTIFY_MSG_SET_IME_COMP,
    KMX_NOTIFY_MSG_END_IME_COMP,

    KMX_NOTIFY_MSG_END
}KMX_NOTIFY_MSG_CODE;

typedef struct
{
    int         sequencial_number;
    int         flags;
    int         commit_length;
    KMX_WCHAR   commit_text[KMX_MAX_COMMIT];
    int         composition_length;
    KMX_WCHAR   composition_text[KMX_MAX_COMPOSITION];
} KMX_SIP_OUTPUT;


struct tag_KEYPAD
{
    KMX_KEYPAD      api;

    int             metric;
    int             x;
    int             y;
    int             width;
    int             height;

    int             bottom_line;

    int             support_composition;

    KMX_IMM         imm;
    
    int             is_aux_window_visible;
    KMX_BUTTON      echo_button;

    int             is_timer1_actived : 1;
    int             is_timer2_actived : 1;
    int             is_timer3_actived : 1;
    int             is_pen_down_on_keypad : 1;
    int             is_keypad_input_mode_changed : 1;

    int             is_handwriting_panel_on : 1;
    int             is_cancel_insertion : 1;
    int             skip_editor_cursor_movement : 1;

    int             last_pen_down_x;
    int             last_pen_down_y;

    int             language;
    int             user_data_size;
    char*           user_data_buffer;
    
    int             comp_text_length;

    int             output_sequencial_number;
    KMX_SIP_OUTPUT  output;

    mmi_imm_input_mode_enum curr_input_mode;
    mmi_imm_input_mode_enum last_input_mode;
    
    int             prev_x;
    int             prev_y;
    int             prev_width;
    int             prev_height;

};

/* Draw Button */
void mtk_keypad_draw_button(
    KEYPAD*                 keypad,
    const KMX_BUTTON*       buttons,
    int                     num_buttons);

/* Hide and Show Echo Button */
void mtk_create_echo_layer(void);

void mtk_destory_echo_layer(void);

void mtk_keypad_echo_button(
    KEYPAD*                 keypad,
    const KMX_BUTTON*       button);

/* Get Context in Editor  */
void mtk_keypad_get_context(
    KEYPAD*                 keypad,
    KMX_CONTEXT*            context);

/* Draw Rect */
void mtk_keypad_draw_rect(
    KEYPAD*                 keypad,
    int                     left,
    int                     top,
    int                     right,
    int                     bottom,
    KMX_COLOR               c);

/* Draw Background */
void mtk_keypad_draw_background(
    KEYPAD*                 keypad,
    int                     left,
    int                     top,
    int                     right,
    int                     bottom);

/* Draw Text */
void mtk_keypad_draw_text(
    KEYPAD*                 keypad,
    int                     x,
    int                     y,
    const KMX_WCHAR*        text,
    int                     length,
    int                     font_size,
    KMX_COLOR               c);

/* Get Text Size */
void mtk_keypad_get_text_size(
    KEYPAD*                 keypad,
    const KMX_WCHAR*        text,
    int                     length,
    int                     font_size,
    int*                    width,
    int*                    height);

/* Timer */

void mtk_keypad_stop_all_timer(void);

void mtk_keypad_set_timer(
    KEYPAD*                 keypad,
    int                     timer_id,
    int                     time);

/* Notification Handler */
void mtk_keypad_on_notify_input_mode_changed(void);

int mtk_keypad_notify_editor(KEYPAD* keypad, KMX_NOTIFY_MSG_CODE code, int param1, int param2);

#ifdef __cplusplus
}
#endif

#endif /* #ifdef KMXSIP_ADPTER_H */
