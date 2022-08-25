#ifndef KMXSIP_KEYPAD_H
#define KMXSIP_KEYPAD_H

#ifndef KMXSIP_CONFIG_H
    #include "kmxsip_config.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


#define KMX_SIP_MSG_PAINT 0x80
#define KMX_SIP_MSG_TIMER 0x81

#define KMX_SIP_MSG_SHOW  0x82
#define KMX_SIP_MSG_HIDE  0x83

typedef struct tag_KEYPAD KEYPAD;

KEYPAD* keypad_create(void);
void keypad_destroy(KEYPAD* keypad);

void keypad_get_size(KEYPAD* keypad, int* width, int* height);
void keypad_get_pos(KEYPAD* keypad, int *x, int *y);
void keypad_on_paint(KEYPAD* keypad);
void keypad_on_timer(KEYPAD* keypad, int id);
void keypad_update_size(KEYPAD * keypad);
void keypad_update_bottom_line(KEYPAD * keypad, int bottom_line);
void keypad_on_mouse_down(KEYPAD* keypad, int wParam, int lParam);
int keypad_handle_message(KEYPAD*, int msg, int wParam, int lParam);

void keypad_reset(KEYPAD * keypad);
void keypad_reset_no_draw(KEYPAD * keypad);

void kmx_pen_down_in_editor(KEYPAD* keypad);

void kmx_keypad_set_keypad_type(int keypad_type);
int kmx_keypad_get_keypad_type(void);

#if !defined(__NO_HANDWRITING__)
int keypad_is_handwriting_panel_on(KEYPAD* keypad);
int keypad_exit_handwriting_panel(KEYPAD* keypad, int on_input_mode_changing);
void keypad_enable_handwriting_panel(KEYPAD* keypad, int enable);
#endif /* #if !defined(__NO_HANDWRITING__) */

int keypad_on_editor_cursor_moved(KEYPAD* keypad);

void keypad_clear_keypad_area(KEYPAD* keypad);

void keypad_save_curr_window_pos(KEYPAD* keypad);

#ifdef __cplusplus
}
#endif

#endif /* KMXSIP_KEYPAD_H */
