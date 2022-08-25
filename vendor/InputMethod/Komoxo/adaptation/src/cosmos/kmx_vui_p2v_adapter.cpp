
#include "kmx_vui_p2v_adapter.h"
#include "kmx_input_config.h"

#ifdef __MMI_KMX_VUI_SUPPORT__

#include "kmx_vui_adapter.h"

#ifdef __MMI_KMX_TOUCH_INPUT__
    #include "kmxsip_input_method.h"
#endif

extern "C"
{
    #include "MMI_features.h"    
    #include "MMIDataType.h"    
    #include "imui.h"
    #include "kmx_input_prot.h"
    #include "cstar_ime.h"
    #include "ImeSDKProt.h"
} 

    #include "kmx_vui_adapter.h"
    
    #include "vfx_datatype.h"
    #include "vfx_object.h"
    #include "vfx_class_info.h"        
    #include "vfx_basic_type.h"
    #include "vfx_control.h"
    #include "vfx_top_level.h"
    #include "vsrv_input_method_interface.h"
   
class KMXUIAdapter : public VfxControl
{
    VFX_DECLARE_CLASS(KMXUIAdapter);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(KMXUIAdapter);
    
public:
    KMXUIAdapter();    
    ~KMXUIAdapter();
    
    void initUI(void);    
    void exitUI(void);
    VfxBool isIMUIControl(VfxControl *control);
    void layoutAllComponents(int bottom);
    int updateControl(U32 control_set);
    
protected:
    virtual VfxBool onPenInput(
        VfxPenEvent &event          // [IN] The pen event to be handled
    );
    
    virtual void onDraw(
        VfxDrawContext &dc
    );
private:
    mmi_ime_sdk_imui_control_enum m_controlType;        
};
    
void kmx_vui_init(void)
{
    VFX_OBJ_GET_INSTANCE(KMXUIAdapter)->initUI();
}

void kmx_vui_exit(void)
{   
    VFX_OBJ_GET_INSTANCE(KMXUIAdapter)->exitUI();
}

int kmx_vui_is_vui_control(void* ptr)
{
    return VFX_OBJ_GET_INSTANCE(KMXUIAdapter)->isIMUIControl((VfxControl*)ptr) == VFX_TRUE;
}

void kmx_vui_layout_control(int bottom_y)
{
    VFX_OBJ_GET_INSTANCE(KMXUIAdapter)->layoutAllComponents(bottom_y);
}

void kmx_vui_set_dirty(void)
{
    VFX_OBJ_GET_INSTANCE(KMXUIAdapter)->invalidate();
}

int kmx_vui_update_control(unsigned int control_set)
{
    return VFX_OBJ_GET_INSTANCE(KMXUIAdapter)->updateControl(control_set);
}

static VfxU32 map_color_value(KMX_GUI_COLOR c)
{
    return (VfxU32)VRT_COLOR_MAKE(255, KMX_GUI_COLOR_R(c), KMX_GUI_COLOR_G(c), KMX_GUI_COLOR_B(c));
}

static VfxFontDesc map_font_desc(int font_size)
{
    if (font_size & 0x80)
    {
        return VfxFontDesc(VFX_FONT_DESC_VF_SIZE(font_size & 0x7F));
    }
        
    if (font_size == SMALL_FONT)
    {
        return VfxFontDesc(VFX_FONT_DESC_SIZE_SMALL);
    }
    else if (font_size == MEDIUM_FONT)
    {
        return VfxFontDesc(VFX_FONT_DESC_SIZE_MEDIUM);
    }
    else if (font_size == LARGE_FONT)
    {
        return VfxFontDesc(VFX_FONT_DESC_SIZE_LARGE);
    }
    else
    {
        return VfxFontDesc(VFX_FONT_DESC_SIZE_MEDIUM);
    }
}

/* Implemenation of KMXUIAdapter */
VFX_IMPLEMENT_CLASS("KMXUIAdapter", KMXUIAdapter, VfxControl);    
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(KMXUIAdapter);    

KMXUIAdapter::KMXUIAdapter()
{

}

KMXUIAdapter::~KMXUIAdapter()
{

}

void KMXUIAdapter::initUI(void)
{
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->addChild(this);
    this->setPosZ(VFX_TOP_LEVEL_Z_IME_UI);
    this->setHidden(VFX_TRUE);
    
    m_controlType = (mmi_ime_sdk_imui_control_enum) MMI_IME_SDK_IMUI_IME_WINDOW;
    kmx_vui_create_engine();
}

void KMXUIAdapter::exitUI(void)
{
    kmx_vui_destroy_engine();
    
    this->setHidden(VFX_TRUE);
    this->removeFromParent();
}

VfxBool KMXUIAdapter::isIMUIControl(VfxControl *control)
{
    if (control == this)
        return VFX_TRUE;
    
    return VFX_FALSE;        
}

VfxBool KMXUIAdapter::onPenInput(
        VfxPenEvent &event
    )
{
    mmi_ime_sdk_pen_event_data_struct sdk_pen_evt;
    sdk_pen_evt.pos.x = event.pos.x;
    sdk_pen_evt.pos.y = event.pos.y;
    
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            sdk_pen_evt.event_type = MMI_PEN_EVENT_DOWN;
            break;           

        case VFX_PEN_EVENT_TYPE_LONG_TAP:
            sdk_pen_evt.event_type = MMI_PEN_EVENT_LONG_TAP;
            break;
                        
        case VFX_PEN_EVENT_TYPE_MOVE:
            sdk_pen_evt.event_type = MMI_PEN_EVENT_MOVE;
            break;           
        
        case VFX_PEN_EVENT_TYPE_UP:
            sdk_pen_evt.event_type = MMI_PEN_EVENT_UP;
            break;           
        
        case VFX_PEN_EVENT_TYPE_ABORT:
            sdk_pen_evt.event_type = MMI_PEN_EVENT_ABORT;
            break;
            
        default:
            return VFX_FALSE;
    }
    
    return mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_IMUI_CONTROL_TRANSLATE_PEN_EVENT, 
                            (U32)m_controlType,
                            (U32)&sdk_pen_evt) ? VFX_TRUE : VFX_FALSE;

}    

void KMXUIAdapter::layoutAllComponents(int bottom)
{
    #ifdef __MMI_KMX_TOUCH_INPUT__
    if (mmi_ime_sdk_is_visible_control((mmi_ime_sdk_imui_control_enum)MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD))
    {                
        int x, y, w, h;        
        if (kmx_input_method_get_keypad_pos(&x, &y))
        {
            this->setPos(x, y);
        }        
        if (kmx_input_method_get_keypad_size(&w, &h))
        {
            this->setSize(w, h);
        }                        
    }
    else 
    #endif
    if (mmi_ime_sdk_is_visible_control((mmi_ime_sdk_imui_control_enum)MMI_IME_SDK_IMUI_IME_WINDOW))
    {
        CS_UI_RECT r;
        cstar_ime_get_ime_window_rect(&r);
        this->setPos(r.left, r.top);
        this->setSize(r.right - r.left, r.bottom - r.top);                        
    }        
}

int KMXUIAdapter::updateControl(U32 control_set)
{
    #ifdef __MMI_KMX_TOUCH_INPUT__
    if (mmi_ime_sdk_is_visible_control((mmi_ime_sdk_imui_control_enum)MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD))
    {
        m_controlType = (mmi_ime_sdk_imui_control_enum)MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD;
        this->setHidden(VFX_FALSE);
    }
    else
    #endif
    if (mmi_ime_sdk_is_visible_control((mmi_ime_sdk_imui_control_enum)MMI_IME_SDK_IMUI_IME_WINDOW))
    {
        m_controlType = (mmi_ime_sdk_imui_control_enum)MMI_IME_SDK_IMUI_IME_WINDOW;
        this->setHidden(VFX_FALSE);
    }
    else
    {
        this->setHidden(VFX_TRUE);
    }
    
    return 1;
}

void KMXUIAdapter::onDraw(VfxDrawContext &dc)
{
    int item_count;
    const KMX_VUI_VISUAL_ITEM* items;
    
    if (!kmx_vui_get_visual_items(&items, &item_count))
        return;
        
    if (!item_count)
        return;
            
    unsigned short offset_x, offset_y;
    
    int i;
    
    offset_x = (unsigned short) this->getPos().x;
    offset_y = (unsigned short) this->getPos().y;
    
    for (i = 0; i < item_count; i++)
    {        
        switch(items[i].type)
        {
        default:
            break;
        case KMX_VUI_VISUAL_TEXT:
            {
                KMX_VUI_TEXT_ITEM *item = (KMX_VUI_TEXT_ITEM*) &items[i].item_body;
                dc.setFillColor(map_color_value(item->c));                
                dc.setFont(map_font_desc(item->font_size));
                #ifdef __MMI_VECTOR_FONT_SUPPORT__
                {                    
                    mmi_fe_get_string_info_param_struct query;
                    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
                    query.String = (U8*) item->text;
                    query.n = item->length;
                    query.enableTruncated = MMI_FALSE;
                    query.w = 0;
                    mmi_fe_get_string_widthheight(&query);
                    
                    S32 height, ascent, descent;
                    mmi_fe_get_char_info_of_all_lang((U8) item->font_size, &height, &ascent, &descent);
                    
                    dc.drawTextBaseline(item->x - offset_x, 
                                        item->y - offset_y, 
                                        query.adv_w, 
                                        query.pHeight, 
                                        ascent,
                                        item->text, item->length);
                }
                #else                        
                dc.drawText(item->x - offset_x, item->y - offset_y, item->text, item->length);
                #endif
            }
            break;                    
        case KMX_VUI_VISUAL_RECT:
            {
                KMX_VUI_RECT_ITEM *item = (KMX_VUI_RECT_ITEM*) &items[i].item_body;
                dc.setFillColor(map_color_value(item->c));                                
                dc.fillRect(item->rect.left - offset_x, item->rect.top - offset_y, 
                            item->rect.right - item->rect.left, 
                            item->rect.bottom - item->rect.top);
            }
            break;                    
        case KMX_VUI_VISUAL_PIXEL:
            {
                KMX_VUI_PIXEL_ITEM *item = (KMX_VUI_PIXEL_ITEM*) &items[i].item_body;
                dc.setFillColor(map_color_value(item->c));                
                dc.drawPixel(item->x - offset_x, item->y - offset_y);
            }
            break;
        case KMX_VUI_VISUAL_IMAGE:
            {
                KMX_VUI_IMAGE_ITEM *item = (KMX_VUI_IMAGE_ITEM*) &items[i].item_body;
                if (item->use_id)
                    dc.drawImageFromRes(item->x - offset_x, item->y - offset_y, (VfxResId)item->image);
                else
                    dc.drawImageFromMem(item->x - offset_x, item->y - offset_y, (const void*)item->image);
            }
            break;                                        
        case KMX_VUI_VISUAL_RESIZED_IMAGE:
            {
                KMX_VUI_RESIZED_IMAGE_ITEM *item = (KMX_VUI_RESIZED_IMAGE_ITEM*) &items[i].item_body;                
                VfxRect r(item->rect.left - offset_x, item->rect.top - offset_y, 
                item->rect.right - item->rect.left, 
                item->rect.bottom - item->rect.top
                );
                
                if (item->use_id)
                    dc.drawResizedImageFromRes(r, (VfxResId)item->image);
                else                
                    dc.drawResizedImageFromMem(r, (const void*)item->image);
            }
            break;                                                    
        }    
    }                
}    

#endif
