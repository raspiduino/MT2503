
#include "kmx_gui.h"

#include "kmx_input_config.h"

#include "kmx_input_prot.h"

#include "cstar_ime_gui.h"

#ifdef __MMI_KMX_VUI_SUPPORT__
#include ".\cosmos\kmx_vui_adapter.h"
#include ".\cosmos\kmx_vui_p2v_adapter.h"
#endif


void (*kmx_gui_init)(void);
void (*kmx_gui_exit)(void);

int (*kmx_gui_begin_paint)(const KMX_GUI_RECT* r);
int (*kmx_gui_end_paint)(const KMX_GUI_RECT* r);

int (*kmx_gui_draw_text)(int x, int y, 
                         int font_size, 
                         const unsigned short* text, int length,
                         KMX_GUI_COLOR c) ;

int (*kmx_gui_draw_rect)(const KMX_GUI_RECT* r, KMX_GUI_COLOR c);

int (*kmx_gui_draw_pixel)(int x, int y,
                          KMX_GUI_COLOR c);
                       
int (*kmx_gui_draw_image)(int x, int y,
                          void* image);

int (*kmx_gui_draw_resized_image)(const KMX_GUI_RECT* r,
                                  void* image);
                                        
int (*kmx_gui_draw_resized_image_by_id)(const KMX_GUI_RECT* r,
                                        int image_id);                                        

int (*kmx_gui_strlen)(const unsigned short *text);

int (*kmx_gui_update_control)(unsigned int control_set);

int (*kmx_gui_is_gui_control)(void* control_ptr);
                                        
void kmx_gui_setup(void)
{
    /* Common function */
    
    kmx_gui_strlen = cstar_gui_strlen;
    
    #ifdef __MMI_KMX_VUI_SUPPORT__
    if (mmi_ime_sdk_is_in_venus_ui_engine_state())
    {
        kmx_gui_init = kmx_vui_init;
        kmx_gui_exit = kmx_vui_exit;
        
        kmx_gui_begin_paint = kmx_vui_begin_paint;
        kmx_gui_end_paint = kmx_vui_end_paint;
        
        kmx_gui_draw_text = kmx_vui_draw_text;
        kmx_gui_draw_rect = kmx_vui_draw_rect;
        kmx_gui_draw_pixel = kmx_vui_draw_pixel;
        kmx_gui_draw_image = kmx_vui_draw_image;
        kmx_gui_draw_resized_image = kmx_vui_draw_resized_image;
        kmx_gui_draw_resized_image_by_id = kmx_vui_draw_resized_image_by_id;
                
        kmx_gui_update_control = kmx_vui_update_control;
        kmx_gui_is_gui_control = kmx_vui_is_vui_control;
        
        return;
    }
    #endif
    kmx_gui_init = cstar_gui_init;
    kmx_gui_exit = cstar_gui_exit;
    
    kmx_gui_begin_paint = cstar_gui_begin_paint;
    kmx_gui_end_paint = cstar_gui_end_paint;
    
    kmx_gui_draw_text = cstar_gui_draw_text;
    kmx_gui_draw_rect = cstar_gui_draw_rect;
    kmx_gui_draw_pixel = cstar_gui_draw_pixel;
    kmx_gui_draw_image = cstar_gui_draw_image;
    kmx_gui_draw_resized_image = cstar_gui_draw_resized_image;        
    kmx_gui_draw_resized_image_by_id = cstar_gui_draw_resized_image_by_id;
    
    kmx_gui_update_control = cstar_gui_update_control;
    kmx_gui_is_gui_control = cstar_gui_is_gui_control;
    
}