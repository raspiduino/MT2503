#ifndef CSTAR_IME_GUI_H
#define CSTAR_IME_GUI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "kmx_gui.h"

void cstar_gui_init(void);
void cstar_gui_exit(void);

int cstar_gui_begin_paint(const KMX_GUI_RECT* r);
int cstar_gui_end_paint(const KMX_GUI_RECT* r);

int cstar_gui_draw_text(int x, int y, 
                      int font_size, 
                      const unsigned short* text, int length,
                      KMX_GUI_COLOR c);

int cstar_gui_draw_rect(const KMX_GUI_RECT* r, KMX_GUI_COLOR c);

int cstar_gui_draw_pixel(int x, int y,
                         KMX_GUI_COLOR c);
                       
int cstar_gui_draw_image(int x, int y,
                         void* image);

int cstar_gui_draw_resized_image(const KMX_GUI_RECT* r,
                                 void* image);

int cstar_gui_draw_resized_image_by_id(const KMX_GUI_RECT* r,
                                       int image_id);

int cstar_gui_strlen(const unsigned short* text);

int cstar_gui_update_control(unsigned int control_set);
int cstar_gui_is_gui_control(void* ptr);

#ifdef __cplusplus
}
#endif

#endif /* CSTAR_IME_GUI_H */
