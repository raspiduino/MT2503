
#include "MMI_features.h"
#include "kmx_input_config.h"

#ifdef __MMI_KMX_TOUCH_INPUT__

/* MTK related start */
#include "MMI_features.h"
#include "Gui.h"
#include "gdi_include.h"
#include "wgui_categories_util.h"
#include "wgui_categories_inputs.h"
#include "ImeGprot.h"
#include "Imc.h"
#include "Imui.h"
#include "Imc_key.h"
#include "Wgui_ems.h"
#include "font_engine_interface.h"

#include "kmxsip_config.h"
/* To be replaced */
#include "Mmi_rp_app_komoxo_def.h"

#include "kmximmapi.h"
#include "kmxsip_adapter.h"
#include "Kmxsip_keypad.h"
#include "Komoxo_logo.h"

#include "kmx_input_prot.h"

#include "kmx_image_id.h"

#include "TimerEvents.h"

#include "kmx_gui.h"

#define KMX_LABEL_FONT (&MMI_small_font)
#define KMX_TEXT_FONT  (&MMI_default_font)

#define KMX_LABEL_TEXT_COLOR (KMX_GUI_MAKE_COLOR(0, 0, 0))

static KMX_GUI_COLOR convert_color(KMX_COLOR c)
{
    return KMX_GUI_MAKE_COLOR(KMX_COLOR_RED(c), KMX_COLOR_GREEN(c), KMX_COLOR_BLUE(c));
}


static void mtk_get_string_width_height_n(U8* s, S32 len, S32* pwidth, S32* pheight)
{
#if defined(__MMI_VECTOR_FONT_SUPPORT__) && !defined(__MMI_SCRIPT_EASY__)    
    mmi_fe_get_string_info_param_struct query;

    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = s;
    query.n = len;
    query.enableTruncated = MMI_FALSE;

    mmi_fe_get_string_widthheight(&query);

    *pwidth = query.adv_w;
    *pheight = Get_CharHeight();
#else
    Get_StringWidthHeight((U8 *)s, pwidth, pheight);
#endif

}

static void mtk_get_string_width_height(U8* s, S32* pwidth, S32* pheight)
{
    mtk_get_string_width_height_n(s, kmx_gui_strlen((unsigned short*)s), pwidth, pheight);
}

/*********************************************************************************
 *
 *  Draw Button Image and Label.
 *
 *********************************************************************************/

extern BOOL r2lMMIFlag;
extern BOOL cancelWidth;

static void draw_button_label(  
                              int keypad_x,
                              int keypad_y,
                              const KMX_BUTTON*   button)
{
    S32 width, height;
    int x, y;
    KMX_GUI_COLOR c;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    static stFontAttribute text_font;
#endif
    
    if (!button->label_text)
        return;

    MMI_ASSERT(button->label_font_size != 0);	

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    text_font.size = KMX_GUI_MAKE_VF_SIZE(button->label_font_size);
    gui_set_font(&text_font);
#else
    gui_set_font(KMX_LABEL_FONT);
#endif
        
    mtk_get_string_width_height((U8*)button->label_text, &width, &height);    

    if (button->label_flags & KMX_LABEL_HCENTER)
        x = button->x + (button->width - width) / 2;
    else if (button->label_flags & KMX_LABEL_RTL)
        x = button->x + button->width - width - button->label_x;
    else
        x = button->x + button->label_x;
    
    x += keypad_x;
    
    if (button->label_flags & KMX_LABEL_VCENTER)
        y = button->y + (button->height - height) / 2;
    else
        y = button->y + button->label_y;
    
    y += keypad_y;       
        
    gui_push_text_clip();

    gui_set_text_clip(x, y, keypad_x + button->x + button->width, keypad_y + button->y + button->height);
        
    if (button->label_color == 0xFFFFFF)
    {
        c = KMX_LABEL_TEXT_COLOR;
    }
    else
    {
        c = convert_color(button->label_color);
    }    
    
    if (r2lMMIFlag && !cancelWidth)
    {
        x = x + width - 1;
    }

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    kmx_gui_draw_text(x, y, KMX_GUI_MAKE_VF_SIZE(button->label_font_size), button->label_text, kmx_gui_strlen(button->label_text), c);
#else    
    kmx_gui_draw_text(x, y, KMX_LABEL_FONT->size, button->label_text, kmx_gui_strlen(button->label_text), c);
#endif    

    gui_pop_text_clip();    
    
}

static void kmx_highlight_button(
    KEYPAD*             keypad,
    const KMX_BUTTON*   button)
{
        
}

#define KMX_IMAGE_HIGHLIGHT_ID_OFFSET (HIGHLIGHT_IMG_KOMOXO_COMMON_N - IMG_KOMOXO_COMMON_N)

static PU8 kmx_mtk_get_image(U16 image_id, int is_highlight_image)
{
    int low = 0, mid, high = sizeof(g_kmx_image_range_table) / (2 * sizeof(g_kmx_image_range_table[0]));
        
    while(low <= high)
    {
        mid = (low + high) >> 1;

        if (image_id >= g_kmx_image_range_table[mid * 2] && image_id <= g_kmx_image_range_table[mid * 2 + 1])
        {
            image_id = (unsigned short)(image_id - g_kmx_image_range_table[mid * 2] + g_kmx_image_map_table[mid]);
            if (is_highlight_image)
                image_id = (unsigned short)(image_id + KMX_IMAGE_HIGHLIGHT_ID_OFFSET);
            return get_image(image_id);
        }
        else if (image_id < g_kmx_image_range_table[mid * 2])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }        
    }

    return NULL;
    
}

static void draw_button_image(
    KEYPAD *            keypad,
    const KMX_BUTTON*   buttons, 
    int                 num_buttons)
{
    int i;
    int keypad_x = keypad->x;
    int keypad_y = keypad->y;
    
    for (i = 0; i < num_buttons; i++)
    {
        const KMX_BUTTON * button;
        PU8 image_buffer;
        
        button = &buttons[i];
        /* Do not Draw Zero Width Button */
        if(button->width && button->height)
        {   
            image_buffer = kmx_mtk_get_image(button->image, button->extra_flags & KMX_BUTTON_EXTRA_FLAG_HIGHLIGHT);
            kmx_gui_draw_image(keypad_x + button->x, keypad_y + button->y, image_buffer);
            if (button->extra_flags & KMX_BUTTON_EXTRA_FLAG_HIGHLIGHT)
            {
                kmx_highlight_button(keypad, button);
            }
        }
    }
 
}

void mtk_keypad_draw_button(
    KEYPAD*                 keypad,
    const KMX_BUTTON*       buttons,
    int                     num_buttons)
{
    int i;

    if (!keypad)
        return;
   
    draw_button_image(keypad, buttons, num_buttons);

    for (i = 0; i < num_buttons; i++)
        draw_button_label(keypad->x, keypad->y, &buttons[i]);
}

/*********************************************************************************
 *
 *  Hide and Show Echo Button.
 *
 *********************************************************************************/

#ifndef KMX_CFG_DISABLE_ECHO

#define KMX_MAX_ECHO_BUTTON_HEIGHT 50
#define KMX_ECHO_WINDOW_Y 130
#define KMX_LAYER_BUF_SIZE (240 * KMX_MAX_ECHO_BUTTON_HEIGHT * 2)

#if defined(__ARM9_MMU__) && defined(__MTK_TARGET__)
    #pragma arm section zidata = "NONCACHEDZI"
    static int kmx_layer_buf[KMX_LAYER_BUF_SIZE / 4];
    #pragma arm section zidata
#else
    static int kmx_layer_buf[KMX_LAYER_BUF_SIZE / 4];
#endif

static gdi_handle kmx_echo_button_layer;

#define KMX_MAX_LAYER_COUNT 4

static int kmx_select_layer(gdi_handle layer)
{
    gdi_handle layers[KMX_MAX_LAYER_COUNT];
    int i;

    memset(layers, 0, sizeof(gdi_handle) * KMX_MAX_LAYER_COUNT);
   
    gdi_layer_get_blt_layer(&layers[0], &layers[1], &layers[2], &layers[3]);

    for (i = 0; i < KMX_MAX_LAYER_COUNT; i ++)
    {
        /* already selected */
        if (layers[i] == layer)
        {
            return i + 1;        
        }
    }

    for (i = 0; i < KMX_MAX_LAYER_COUNT; i ++)
    {
        if (layers[i] == GDI_LAYER_EMPTY_HANDLE || layers[i] == GDI_ERROR_HANDLE)
        {
            layers[i] = layer;
            break;        
        }
    }
    /* layer was full, can not select more layer */
    if (i == KMX_MAX_LAYER_COUNT)
        return 0;

    /* select the layer */
    gdi_layer_blt(layers[0], layers[1], layers[2], layers[3], 0, 0, 1, 1);

    return i + 1;
}

static void kmx_deselect_layer(gdi_handle layer)
{
    gdi_handle layers[KMX_MAX_LAYER_COUNT];
    int i;

    memset(layers, 0, sizeof(gdi_handle) * KMX_MAX_LAYER_COUNT);
   
    gdi_layer_get_blt_layer(&layers[0], &layers[1], &layers[2], &layers[3]);

    for (i = 0; i < KMX_MAX_LAYER_COUNT; i ++)
    {
        if (layers[i] == layer)
        {
            layers[i] = GDI_LAYER_EMPTY_HANDLE;
            break;        
        }
    }
    /* layer not found, do nothing */
    if (i == KMX_MAX_LAYER_COUNT)
        return;

    /* deselect the layer */
    gdi_layer_blt(layers[0], layers[1], layers[2], layers[3], 0, 0, 1, 1);

    return;
}

void mtk_create_echo_layer(void)
{
    gdi_layer_create_using_outside_memory(0, KMX_ECHO_WINDOW_Y, 240, KMX_MAX_ECHO_BUTTON_HEIGHT, &kmx_echo_button_layer, (unsigned char *)kmx_layer_buf, KMX_LAYER_BUF_SIZE);
}

void mtk_destory_echo_layer(void)
{
    kmx_deselect_layer(kmx_echo_button_layer);
    gdi_layer_free(kmx_echo_button_layer);
    kmx_echo_button_layer = 0;
}

void mtk_keypad_echo_button(
    KEYPAD*                 keypad,
    const KMX_BUTTON*       button)
{
    KMX_RECT r;
    int x, y;
    
    if (!kmx_echo_button_layer)
        return;
       
    if (button)
    {

        keypad->echo_button = *button;
        keypad->echo_button.x = 0;
        keypad->echo_button.y = 0;
       
        // default to metric 240
        x = (240 - keypad->echo_button.width) / 2;
        y = KMX_ECHO_WINDOW_Y;
        
        r.left = x;
        r.top = y;
        r.right = x + keypad->echo_button.width;
        r.bottom = y + keypad->echo_button.height;
        
        
        gdi_layer_push_and_set_active(kmx_echo_button_layer);

        gdi_layer_reset_clip();
        
        gui_lock_double_buffer();

        gdi_layer_clear(GDI_COLOR_BLUE);
        
        gdi_layer_set_source_key(TRUE, GDI_COLOR_BLUE);

        draw_button_image(x, 0, &keypad->echo_button, 1);
    
        draw_button_label(x, 0, &keypad->echo_button);
         
        gui_unlock_double_buffer();
        
        kmx_select_layer(kmx_echo_button_layer);

        gdi_layer_blt_previous(r.left, r.top, r.right, r.bottom);

        gdi_layer_pop_and_restore_active(); 

        //kmx_deselect_layer(kmx_echo_button_layer);
        
    }
    else
    {
        x = (240 - keypad->echo_button.width) / 2;
        y = KMX_ECHO_WINDOW_Y;

        r.left = x;
        r.top = y;
        r.right = r.left + keypad->echo_button.width;
        r.bottom = r.top + keypad->echo_button.height;

        gdi_layer_push_and_set_active(kmx_echo_button_layer);
        
        gdi_layer_reset_clip();
        
        gdi_layer_clear(GDI_COLOR_BLUE);

        gdi_layer_pop_and_restore_active();
        
        
        kmx_select_layer(kmx_echo_button_layer);

        gdi_layer_blt_previous(r.left, r.top, r.right, r.bottom);

        //kmx_deselect_layer(kmx_echo_button_layer);
    }
}

#else

void mtk_create_echo_layer(void)
{

}

void mtk_destory_echo_layer(void)
{
 
}

void mtk_keypad_echo_button(
    KEYPAD*                 keypad,
    const KMX_BUTTON*       button)
{

}

#endif

static U32 __inline mtk_keypad_imc_send_message(U8 msg_id, int param_0, int param_1)
{
    mmi_imc_message_struct msg;  
    msg.message_id = msg_id;
    msg.param_0 = (U32)param_0;
    msg.param_1 = (U32)param_1;
    return mmi_ime_sdk_send_editor_msg(&msg);
}

/*********************************************************************************
 *
 *  Get Context in Editor
 *
 *********************************************************************************/

#define KMX_IS_PTR_WORD_ALIGNED(p) (!((unsigned int)(p) & 1))
#define KMX_MAX_CONTEXT_BUFFER_LENGTH 64

void mtk_keypad_get_context(
    KEYPAD*                 keypad,
    KMX_CONTEXT*            context)
{    
    U8 *text_start = NULL, *text_end = NULL;

    if(!keypad || !context)
        return;

    context->flags = 0;
    context->text_length = 0;
    context->caret_position = 0;
    
    context->flags = KMX_FLAG_COMP_SUPPORT;
    keypad->support_composition = TRUE;

    /* !We can only get text ptr before caret. */
    mtk_keypad_imc_send_message(MMI_IMC_MESSAGE_GET_TEXT_PTR_BEFORE_CANDIDATE, (int)&text_start, (int)&text_end);

    if (!text_start || !text_end || text_start > text_end)
        return;
    
    context->text_length = (text_end - text_start) / 2;

    /* Check parameters */
    if (!context->text_buffer || !context->text_buffer_length)
        return;

    if (context->text_length > context->text_buffer_length)
        context->text_length = context->text_buffer_length;
    
    memcpy(context->text_buffer, text_end - context->text_length * sizeof(KMX_WCHAR), context->text_length * sizeof(KMX_WCHAR));

    /* !Caret position is the pointer points the next character after caret char */
    context->caret_position = context->text_length;
}


/*********************************************************************************
 *
 *  Draw colored rectangle.
 *
 *********************************************************************************/

void mtk_keypad_draw_rect(
    KEYPAD*                 keypad,
    int                     left,
    int                     top,
    int                     right,
    int                     bottom,
    KMX_COLOR               c)
{
    KMX_GUI_RECT r;
    r.left = keypad->x + left;
    r.top = keypad->y + top;
    r.right = keypad->x + right;
    r.bottom = keypad->y + bottom;
    kmx_gui_draw_rect(&r, convert_color(c));
}


/*********************************************************************************
 *
 *  Draw Background rectangle.
 *
 *********************************************************************************/

void mtk_keypad_draw_background(
    KEYPAD*                 keypad,
    int                     left,
    int                     top,
    int                     right,
    int                     bottom)
{
    KMX_GUI_RECT r;
    r.left = keypad->x + left;
    r.top = keypad->y + top;
    r.right = keypad->x + right;
    r.bottom = keypad->y + bottom;

   kmx_gui_draw_rect(&r, convert_color(DEFAULT_BK_COLOR));
}

/*********************************************************************************
 *
 *  Draw Text.
 *
 *********************************************************************************/

void mtk_keypad_get_text_size(
    KEYPAD*                 keypad,
    const KMX_WCHAR*        text,
    int                     length,
    int                     font_size,
    int*                    width,
    int*                    height);

void mtk_keypad_draw_text(
    KEYPAD*                 keypad,
    int                     x,
    int                     y,
    const KMX_WCHAR*        text,
    int                     length,
    int                     font_size,
    KMX_COLOR               c)
{    
    if (r2lMMIFlag && !cancelWidth)
    {
        int width;
        mtk_keypad_get_text_size(keypad, text, length, font_size, &width, 0);
        x = x + width - 1;
    }

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    kmx_gui_draw_text(keypad->x + x, keypad->y + y, 
        KMX_GUI_MAKE_VF_SIZE(font_size),
        text, length,
        convert_color(c));
#else
    kmx_gui_draw_text(keypad->x + x, keypad->y + y, 
                      KMX_TEXT_FONT->size,
                      text, length,
                      convert_color(c));
#endif            
}

/*********************************************************************************
 *
 *  Get Text Size.
 *
 *********************************************************************************/


void mtk_keypad_get_text_size(
    KEYPAD*                 keypad,
    const KMX_WCHAR*        text,
    int                     length,
    int                     font_size,
    int*                    width,
    int*                    height)
{
    int w, h;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    static stFontAttribute text_font;
#endif

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    text_font.size = KMX_GUI_MAKE_VF_SIZE(font_size);
    gui_set_font(&text_font);
#else
    gui_set_font(KMX_TEXT_FONT);
#endif

    mtk_get_string_width_height_n((U8 *)text, length, &w, &h);
    
    if (width)
        *width = w;
    if (height)
        *height = h;
}


/*********************************************************************************
 *
 *  Timer.
 *
 *********************************************************************************/

extern void kmx_timer_handler(void * arg);

/* KMX TEMP HANDLE */
#define KMX_UI_TIMER_1 CSTAR_REQ_TIMER
#define KMX_UI_TIMER_2 CSTAR_FRAME_TIMER


void mtk_keypad_set_timer(
    KEYPAD*                 keypad,
    int                     timer_id,
    int                     time)
{
    if(!keypad)
        return;

    switch(timer_id) {
    case KMX_TIMER_1:
        if (keypad->is_timer1_actived)
        {
            StopTimer(KMX_UI_TIMER_1);
            keypad->is_timer1_actived = 0;
        }
        if (time > 0)
        {
            StartTimerEx(KMX_UI_TIMER_1, time, kmx_timer_handler, (void *)KMX_TIMER_1);
            keypad->is_timer1_actived = 1;
        }
    	break;
    case KMX_TIMER_2:
        if (keypad->is_timer2_actived)
        {
            StopTimer(KMX_UI_TIMER_2);
            keypad->is_timer2_actived = 0;
        }
        if (time > 0)
        {
            StartTimerEx(KMX_UI_TIMER_2, time, kmx_timer_handler, (void *)KMX_TIMER_2);
            keypad->is_timer2_actived = 1;
        }
        break;
    }
}

static void mtk_keypad_cancel_multitap_timer(
    KEYPAD*                 keypad,
    int                     cancel_insertion)
{
    if (!keypad)
        return;
    
    if (keypad->is_timer2_actived)
    {
        if (cancel_insertion)
            keypad->is_cancel_insertion = 1;
        kmx_timer_handler((void *)KMX_TIMER_2);
        if (cancel_insertion)
            keypad->is_cancel_insertion = 0;
        StopTimer(KMX_UI_TIMER_2);
        keypad->is_timer2_actived = 0;
    }
}

void mtk_keypad_stop_all_timer(void)
{
    StopTimer(KMX_UI_TIMER_1);
    StopTimer(KMX_UI_TIMER_2);
}

/*********************************************************************************
 *
 *  Notification Handler
 *
 *********************************************************************************/

extern int kmx_is_input_mode_multitap(mmi_imm_input_mode_enum input_mode);

static void mtk_keypad_end_comp(KEYPAD* keypad)
{
    if (keypad->comp_text_length > 0)
    {
        #ifdef KMX_CFG_MULTITAP_INPUT        
        if(kmx_is_input_mode_multitap(keypad->last_input_mode) && keypad->comp_text_length == 1)
        {
            mtk_keypad_imc_send_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
            mtk_keypad_imc_send_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
        }
        else
        #endif
        {
            mtk_keypad_imc_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
        }
        keypad->comp_text_length = 0;
    }
}

static void mtk_keypad_clear_comp(KEYPAD* keypad)
{
    if (keypad->comp_text_length > 0)
    {
        #ifdef KMX_CFG_MULTITAP_INPUT
        if(kmx_is_input_mode_multitap(keypad->last_input_mode))
        {
            mtk_keypad_imc_send_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
            mtk_keypad_imc_send_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
            mtk_keypad_imc_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);                        
        }
        else
        #endif
            mtk_keypad_imc_send_message(MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING, keypad->comp_text_length, (int)L"");
        keypad->comp_text_length = 0;
    }
    else
    {
        /* Force clear highlight */
        mtk_keypad_imc_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);        
    }
}

static void mtk_keypad_set_comp(KEYPAD* keypad, const UI_character_type *text, int length)
{
    #ifdef KMX_CFG_MULTITAP_INPUT
    if(kmx_is_input_mode_multitap(keypad->last_input_mode) && length == 1)
    {
        if(keypad->comp_text_length == 0)
        {
            mtk_keypad_imc_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
        }
        if(!mtk_keypad_imc_send_message(MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR, (int)text[0], 0))
        {
            /* can not set composition 2009-12-17 */
            if (keypad->comp_text_length == 0)
            {
                mtk_keypad_imc_send_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
                mtk_keypad_cancel_multitap_timer(keypad, 1);
            }
            return;
        }
    }
    else
    #endif
    {
        int highlighted_length;
        mtk_keypad_clear_comp(keypad);
        highlighted_length = (int)mtk_keypad_imc_send_message(MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING, keypad->comp_text_length, (int)text);
        if (highlighted_length < length)
        {
            /* Editor is full. Cancel highlight. */            
            keypad->comp_text_length = 0;
            mtk_keypad_imc_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
            keypad_reset(keypad);
            return;
        }
    }
    keypad->comp_text_length = length;
}

int mtk_keypad_notify_editor(KEYPAD* keypad, KMX_NOTIFY_MSG_CODE code, int param1, int param2)
{
    switch(code)
    {
    case KMX_NOTIFY_MSG_END_IME_COMP:
        mtk_keypad_end_comp(keypad);
        break;
    case KMX_NOTIFY_MSG_CLEAR_IME_COMP:
        mtk_keypad_clear_comp(keypad);
        break;
    case KMX_NOTIFY_MSG_SET_IME_COMP:
        mtk_keypad_set_comp(keypad, (const UI_character_type*)param1, param2);
        break;

    }

    return 1;
}

#endif /* #ifdef __MMI_KMX_TOUCH_INPUT__ */
