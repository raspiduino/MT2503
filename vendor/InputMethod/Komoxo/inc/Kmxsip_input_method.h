
#ifndef KMXSIP_INPUT_METHOD_H
#define KMXSIP_INPUT_METHOD_H


#ifdef __cplusplus
extern "C" {
#endif

typedef int (*EDITOR_MESSAGE_PROC) (void *, void *);

int kmx_input_method_select(void);

int kmx_input_method_deselect(void);

void kmx_input_method_show(void);

void kmx_input_method_hide(void);

int kmx_input_method_is_visible(void);

int kmx_input_method_update_view(int bottom_line);

int kmx_input_method_pen_down(int x, int y);

int kmx_input_method_pen_up(int x, int y);

int kmx_input_method_pen_move(int x, int y);

int kmx_input_method_change_input_mode(int input_mode);

int kmx_input_method_get_keypad_size(int * w, int * h);

int kmx_input_method_get_keypad_pos(int * x, int * y);

void kmx_input_method_enable_keypad(int enabled);

int kmx_input_method_is_keypad_enable(void);

int kmx_input_method_handle_key_event(int key_code, int key_type);

void kmx_input_method_reset(void);

#if !defined(__NO_HANDWRITING__)
int kmx_input_method_is_handwriting_panel_on(void);

int kmx_input_method_exit_handwriting_panel(void);
#endif /* #if !defined(__NO_HANDWRITING__) */

int kmx_input_method_on_editor_cursor_moved(void);

void kmxsip_input_method_clear_keypad_area(void);

#ifdef __cplusplus
}
#endif

#endif /* KMXSIP_INPUT_METHOD_H */
