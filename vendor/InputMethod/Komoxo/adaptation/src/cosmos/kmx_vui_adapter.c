
#include "kmx_input_config.h"

#ifdef __MMI_KMX_VUI_SUPPORT__
#include "kmx_vui_adapter.h"
#include "kmx_vui_p2v_adapter.h"

#define KMX_VUI_MAX_ITEM_NUM 128

typedef struct tagKMX_VUI_ENGINE
{
    int count;
    KMX_VUI_VISUAL_ITEM items[KMX_VUI_MAX_ITEM_NUM];    
};

/* Must create copy for text item. Use a internal simple buffer */
#define KMX_VUI_MAX_TEXT_POOL_SIZE (1024)
typedef struct
{
    unsigned int used;
    unsigned short buffer[KMX_VUI_MAX_TEXT_POOL_SIZE];    
}KMX_VUI_TEXT_POOL;

static KMX_VUI_TEXT_POOL g_kmx_vui_text_pool;

/*
 * Text pool Declarations
 */

static void k_text_pool_reset(void);
static unsigned int k_text_pool_get_left_capacity(void);
static unsigned short* k_text_pool_clone_text(const unsigned short*, unsigned short length);

/*
 * Engine 
 */

static KMX_VUI_ENGINE g_kmx_vui_engine;

static void k_reset_engine(KMX_VUI_ENGINE* engine)
{
    engine->count = 0;
    k_text_pool_reset();
}

static int k_validate_capacity(KMX_VUI_ENGINE* engine)
{
    if (engine->count < 0 || engine->count >= KMX_VUI_MAX_ITEM_NUM)
    {
        /* Enlarge KMX_VUI_MAX_ITEM_NUM to avoid this situation! */
        MMI_ASSERT(0);
        return 0;
    }
    
    return 1;    
}

void kmx_vui_create_engine(void)
{
    k_reset_engine(&g_kmx_vui_engine);    
}

void kmx_vui_destroy_engine(void)
{
    k_reset_engine(&g_kmx_vui_engine);
}

int kmx_vui_begin_paint(const KMX_GUI_RECT* r)
{
    KMX_VUI_ENGINE* engine = &g_kmx_vui_engine;
    int bottom = 0;
    
    if (r)
        bottom = r->bottom;
        
    k_reset_engine(engine);
    kmx_vui_layout_control(bottom);
    kmx_vui_set_dirty();
    return 1;    
}

int kmx_vui_end_paint(const KMX_GUI_RECT* r)
{
    return 1;
}

int kmx_vui_draw_text(int x, int y, 
                      int font_size, 
                      const unsigned short* text, int length,
                      KMX_GUI_COLOR c)
{
    KMX_VUI_TEXT_ITEM *item;
    KMX_VUI_ENGINE* engine = &g_kmx_vui_engine;
    
    if (!k_validate_capacity(engine))
        return 0;
    
    engine->items[engine->count].type = KMX_VUI_VISUAL_TEXT;
    
    item = (KMX_VUI_TEXT_ITEM*)&engine->items[engine->count].item_body;
    item->x = (unsigned short)x;
    item->y = (unsigned short)y;        
    item->font_size = (unsigned short) font_size;
    item->text = k_text_pool_clone_text(text, length);
    if (!item->text)
        return 0;
    item->length = (unsigned short)length;    
    item->c = c;
    
    engine->count += 1;
    
    return 1;
}

int kmx_vui_draw_rect(const KMX_GUI_RECT* r, KMX_GUI_COLOR c)
{
    KMX_VUI_RECT_ITEM *item;
    KMX_VUI_ENGINE* engine = &g_kmx_vui_engine;
    
    if (!k_validate_capacity(engine))
        return 0;
    
    engine->items[engine->count].type = KMX_VUI_VISUAL_RECT;
    
    item = (KMX_VUI_RECT_ITEM*)&engine->items[engine->count].item_body;
    item->rect = *r;
    item->c = c;
    
    engine->count += 1;
    
    return 1;
}                      

int kmx_vui_draw_pixel(int x, int y,
                       KMX_GUI_COLOR c)
{
    KMX_VUI_PIXEL_ITEM *item;
    KMX_VUI_ENGINE* engine = &g_kmx_vui_engine;
    
    if (!k_validate_capacity(engine))
        return 0;
    
    engine->items[engine->count].type = KMX_VUI_VISUAL_PIXEL;
    
    item = (KMX_VUI_PIXEL_ITEM*)&engine->items[engine->count].item_body;
    item->x = (unsigned short)x;
    item->y = (unsigned short)y;
    item->c = (unsigned short)c;
    
    engine->count += 1;
    
    return 1;    
}                       
                       
int kmx_vui_draw_image(int x, int y,
                       void* image)
{
    KMX_VUI_IMAGE_ITEM *item;
    KMX_VUI_ENGINE* engine = &g_kmx_vui_engine;
    
    if (!k_validate_capacity(engine))
        return 0;
    
    engine->items[engine->count].type = KMX_VUI_VISUAL_IMAGE;
    
    item = (KMX_VUI_IMAGE_ITEM*)&engine->items[engine->count].item_body;
    item->x = (unsigned short)x;
    item->y = (unsigned short)y;
    item->image = (int)image;
    item->use_id = 0;
    
    engine->count += 1;
    
    return 1;    
}                       

int kmx_vui_draw_resized_image(const KMX_GUI_RECT* r,
                               void* image)
{
    KMX_VUI_RESIZED_IMAGE_ITEM *item;
    KMX_VUI_ENGINE* engine = &g_kmx_vui_engine;
    
    if (!k_validate_capacity(engine))
        return 0;
    
    engine->items[engine->count].type = KMX_VUI_VISUAL_RESIZED_IMAGE;
    
    item = (KMX_VUI_RESIZED_IMAGE_ITEM*)&engine->items[engine->count].item_body;
    item->rect = *r;    
    item->image = (int)image;
    item->use_id = 0;
    
    engine->count += 1;
    
    return 1;    
}

int kmx_vui_draw_resized_image_by_id(const KMX_GUI_RECT* r,
                                     int image_id)
{
    KMX_VUI_RESIZED_IMAGE_ITEM *item;
    KMX_VUI_ENGINE* engine = &g_kmx_vui_engine;
    
    if (!k_validate_capacity(engine))
        return 0;
    
    engine->items[engine->count].type = KMX_VUI_VISUAL_RESIZED_IMAGE;
    
    item = (KMX_VUI_RESIZED_IMAGE_ITEM*)&engine->items[engine->count].item_body;
    item->rect = *r;    
    item->image = image_id;
    item->use_id = 1;
    
    engine->count += 1;
    
    return 1;        
}                                                                    
                               
int kmx_vui_get_visual_items(const KMX_VUI_VISUAL_ITEM** items,
                             int   *count)
{
    KMX_VUI_ENGINE* engine = &g_kmx_vui_engine;
    
    if (!items || !count)
        return 0;
    
    *count = engine->count;
    *items = engine->items;        
    return 1;        
}                             

/*
 * Text pool implementation
 */
static void k_text_pool_reset(void)
{
    g_kmx_vui_text_pool.used = 0;
}

static unsigned int k_text_pool_get_left_capacity(void)
{
    return KMX_VUI_MAX_TEXT_POOL_SIZE - g_kmx_vui_text_pool.used;
}
static unsigned short* k_text_pool_clone_text(const unsigned short *text, unsigned short length)
{
    unsigned short* start;
    if (k_text_pool_get_left_capacity() < length)
        return NULL;
        
    start = g_kmx_vui_text_pool.buffer + g_kmx_vui_text_pool.used;
    memcpy(start, text, sizeof(text[0]) * length);
    
    g_kmx_vui_text_pool.used += length;
    
    return start;
}
#endif
