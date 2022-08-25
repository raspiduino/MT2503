#ifndef KMX_GUI_H
#define KMX_GUI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ImeSDKGprot.h"

/*
 *  Typedef and Enums
 */

typedef struct
{
    int left;
    int top;
    int right;
    int bottom;            
}KMX_GUI_RECT;

typedef unsigned int KMX_GUI_COLOR;

/*
 *  Macro define
 */
#define KMX_GUI_MAKE_COLOR(r, g, b) ((b) | (g) << 8 | (r) << 16)
#define KMX_GUI_COLOR_R(c) ((c) >> 16)
#define KMX_GUI_COLOR_G(c) ((c) >> 8)
#define KMX_GUI_COLOR_B(b) ((c) & 0xFF)

/* Vector font size. */
#define KMX_GUI_MAKE_VF_SIZE(size) (0x80 | ((size) & 0x7F))

/*
 *  Interface
 */

void kmx_gui_setup(void);

extern void (*kmx_gui_init)(void);
extern void (*kmx_gui_exit)(void);

extern int (*kmx_gui_begin_paint)(const KMX_GUI_RECT* r);
extern int (*kmx_gui_end_paint)(const KMX_GUI_RECT* r);

extern int (*kmx_gui_draw_text)(int x, int y, 
                                int font_size, 
                                const unsigned short* text, int length,
                                KMX_GUI_COLOR c);

extern int (*kmx_gui_draw_rect)(const KMX_GUI_RECT* r, KMX_GUI_COLOR c);

extern int (*kmx_gui_draw_pixel)(int x, int y,
                                 KMX_GUI_COLOR c);
                       
extern int (*kmx_gui_draw_image)(int x, int y,
                                 void *image);

extern int (*kmx_gui_draw_resized_image)(const KMX_GUI_RECT* r,
                                         void * image);

extern int (*kmx_gui_draw_resized_image_by_id)(const KMX_GUI_RECT* r,
                                               int image_id);                                               

extern int (*kmx_gui_strlen)(const unsigned short *text);

extern int (*kmx_gui_is_gui_control)(void* control_ptr);
/* Update control visiblity */
extern int (*kmx_gui_update_control)(unsigned int control_set);


#ifdef __cplusplus
}
#endif


#endif /* KMX_GUI_H */
