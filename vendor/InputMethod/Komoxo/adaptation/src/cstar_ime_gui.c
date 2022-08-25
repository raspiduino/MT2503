
#include "kmx_input_config.h"
#include "cstar_ime_gui.h"

#include "gui.h"
#include "gdi_include.h"

#define MAKE_MTK_GUI_COLOR(c) (gui_color(KMX_GUI_COLOR_R(c), KMX_GUI_COLOR_G(c), KMX_GUI_COLOR_B(c)))

static stFontAttribute g_cstar_text_font;

void cstar_gui_init(void)
{

}

void cstar_gui_exit(void)
{

}

int cstar_gui_begin_paint(const KMX_GUI_RECT* r)
{
    if (r)
    {
        gui_lock_double_buffer();

        gdi_layer_push_clip();

        gdi_layer_set_clip(r->left, r->top, r->right, r->bottom);
    }        

    return 1;
}

int cstar_gui_end_paint(const KMX_GUI_RECT* r)
{
    if (r)
    {        
        gdi_layer_pop_clip();

        gui_unlock_double_buffer();

        gui_BLT_double_buffer(r->left, r->top, r->right, r->bottom);
    }
    
    return 1;
}

int cstar_gui_draw_text(int x, int y, 
                        int font_size, 
                        const unsigned short* text, int length,
                        KMX_GUI_COLOR c)
{
    g_cstar_text_font.size = (U8)font_size;
    gui_set_font(&g_cstar_text_font);

    gui_set_text_color(MAKE_MTK_GUI_COLOR(c));
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    {
        S32 height, ascent, descent;
        mmi_fe_get_char_info_of_all_lang((U8) font_size, &height, &ascent, &descent);
        mmi_fe_show_string_n_baseline(x, y, (U8*)text, length, ascent);
    }
#else
    gui_move_text_cursor(x, y);
    gui_print_text_n((CS_UI_WCHAR*)text, length);
#endif

    return 1;
}                      

int cstar_gui_draw_rect(const KMX_GUI_RECT* r, KMX_GUI_COLOR c)
{    
    gui_fill_rectangle(r->left, r->top, r->right - 1, r->bottom - 1, MAKE_MTK_GUI_COLOR(c));
    return 1;
}

int cstar_gui_draw_pixel(int x, int y,
                         KMX_GUI_COLOR c)
{
    gui_putpixel(x, y, MAKE_MTK_GUI_COLOR(c));
    return 1;
}
                       
int cstar_gui_draw_image(int x, int y,
                         void* image)
{
    gui_show_image(x, y, image);
    return 1;
}                         

int cstar_gui_draw_resized_image(const KMX_GUI_RECT* r,
                                 void* image)
{
    gui_push_clip();
    gui_set_clip(r->left, r->top + 1, r->right - 1, r->bottom);                    
    
    #ifdef __MMI_IME_FTE_ENHANCE__                
    gdi_image_draw_resized_blend2layers(r->left, 
               r->top, 
               r->right - r->left, 
               r->bottom - r->top,
               (U8*)image);
    #else
    gui_draw_filled_area(r->left, r->top + 1, 
                         r->right - 1, r->bottom, 
                         (UI_filled_area*)image);
    #endif
    gui_pop_clip();

    return 1;
}

int cstar_gui_draw_resized_image_by_id(const KMX_GUI_RECT* r,
                                       int image_id)
{
    return cstar_gui_draw_resized_image(r, GetImage((MMI_ID_TYPE)image_id));
}                                       

int cstar_gui_strlen(const unsigned short* text)
{
    return mmi_ucs2strlen((const S8*) text);
}

int cstar_gui_update_control(unsigned int control_set)
{
    return 0;
}

int cstar_gui_is_gui_control(void* ptr)
{
    return 0;
}
