#ifndef KMX_VUI_ADAPTER_H
#define KMX_VUI_ADAPTER_H
    
#ifdef __cplusplus
extern "C" {
#endif

#include "kmx_gui.h"
/*
 *  Typedef and Enums
 */
typedef struct tagKMX_VUI_ENGINE KMX_VUI_ENGINE;

#define KMX_VUI_VISUAL_UNKNOWN         0
#define KMX_VUI_VISUAL_TEXT            1 
#define KMX_VUI_VISUAL_RECT            2
#define KMX_VUI_VISUAL_PIXEL           3
#define KMX_VUI_VISUAL_IMAGE           4
#define KMX_VUI_VISUAL_RESIZED_IMAGE   5

typedef struct
{    
    const unsigned short* text;
    unsigned short length;
    unsigned short x;
    unsigned short y;
    unsigned short font_size;
    KMX_GUI_COLOR  c;
}KMX_VUI_TEXT_ITEM;

typedef struct
{
    KMX_GUI_RECT   rect;    
    KMX_GUI_COLOR  c;
}KMX_VUI_RECT_ITEM;

typedef struct
{    
    unsigned short x;
    unsigned short y;
    KMX_GUI_COLOR  c;
}KMX_VUI_PIXEL_ITEM;

typedef struct
{    
    unsigned short x;
    unsigned short y;
    int            image;
    unsigned short use_id;
}KMX_VUI_IMAGE_ITEM;

typedef struct
{    
    KMX_GUI_RECT   rect;
    int            image;
    unsigned short use_id;
}KMX_VUI_RESIZED_IMAGE_ITEM;

typedef struct
{
    unsigned short type;
    
    union
    {
        KMX_VUI_TEXT_ITEM               text_item;
        KMX_VUI_RECT_ITEM               rect_item;
        KMX_VUI_PIXEL_ITEM              pixel_item;
        KMX_VUI_IMAGE_ITEM              image_item;
        KMX_VUI_RESIZED_IMAGE_ITEM      resized_image_item;
    } item_body;
    
}KMX_VUI_VISUAL_ITEM;
                          

/*
 *  Interface
 */

void kmx_vui_create_engine(void);
void kmx_vui_destroy_engine(void);

int kmx_vui_begin_paint(const KMX_GUI_RECT* r);
int kmx_vui_end_paint(const KMX_GUI_RECT* r);

int kmx_vui_draw_text(int x, int y, 
                      int font_size, 
                      const unsigned short* text, int length,
                      KMX_GUI_COLOR c);

int kmx_vui_draw_rect(const KMX_GUI_RECT* r, KMX_GUI_COLOR c);

int kmx_vui_draw_pixel(int x, int y,
                       KMX_GUI_COLOR c);
                       
int kmx_vui_draw_image(int x, int y,
                       void* image);

int kmx_vui_draw_resized_image(const KMX_GUI_RECT* r,
                               void* image);   

int kmx_vui_draw_resized_image_by_id(const KMX_GUI_RECT* r,
                                     int image_id);                                  
                               
int kmx_vui_get_visual_items(const KMX_VUI_VISUAL_ITEM** items,
                             int   *count);
                                                   

#ifdef __cplusplus
}
#endif

#endif
