/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  MediaAppPanel.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Panel for multi-media Apps.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 ****************************************************************************/

#include "MMI_features.h"

#include "gdi_include.h"
#include "gui_data_types.h"
#include "GUI.h"
#include "gui_font_size.h"
#include "MediaAppPanel.h"
#include "mmi_trc_int.h"
#include "gui_themes.h"         /* current_MMI_theme */
#include "PixcomFontEngine.h"

#define MED_PANEL_DUMMY_RES_ID  0
#if 0
/* under construction !*/
#endif
static void mmi_med_panel_update(med_panel_handle h_panel);
static void mmi_med_panel_draw_txtbtn(
                const med_panel_item_t *pbtn,
                gdi_handle h_dest_layer,
                S32 enable,
                med_panel_bg_struct *pBgData);
static void mmi_med_panel_draw_btn3(
                const med_panel_item_t *pbtn,
                gdi_handle h_dest_layer,
                S32 enable,
                med_panel_bg_struct *pBgData);
static void mmi_med_panel_draw_btn4(
                const med_panel_item_t *pbtn,
                gdi_handle h_dest_layer,
                S32 enable,
                med_panel_bg_struct *pBgData);


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_init_btn3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pbtn        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_med_panel_init_btn3(med_panel_item_t *pbtn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pbtn, 0, sizeof(med_panel_item_t));
    pbtn->type = MED_ITEM_BTN3;
    pbtn->draw = mmi_med_panel_draw_btn3;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_init_btn4
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pbtn        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_med_panel_init_btn4(med_panel_item_t *pbtn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pbtn, 0, sizeof(med_panel_item_t));
    pbtn->type = MED_ITEM_BTN4;
    pbtn->draw = mmi_med_panel_draw_btn4;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_init_txtbtn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptxtbtn     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_med_panel_init_txtbtn(med_panel_item_t *ptxtbtn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ptxtbtn, 0, sizeof(med_panel_item_t));
    ptxtbtn->type = MED_ITEM_TXTBTN;
    ptxtbtn->draw = mmi_med_panel_draw_txtbtn;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_init_prog
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pprog       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_med_panel_init_prog(med_panel_item_t *pprog)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pprog, 0, sizeof(med_panel_item_t));
    pprog->type = MED_ITEM_PROGRESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_draw_color_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_dest_layer        [IN]        
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 *  pBgData             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_med_panel_draw_color_bg(gdi_handle h_dest_layer, S32 x1, S32 y1, S32 x2, S32 y2, void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_COLOR color = ((med_panel_bg_struct*)userData)->bgData.bgColor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect_nb_concurrent(h_dest_layer, x1, y1, x2, y2, color);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_draw_img_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_dest_layer        [IN]        
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 *  pData               [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_med_panel_draw_img_bg(gdi_handle h_dest_layer, S32 x1, S32 y1, S32 x2, S32 y2, void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_panel_bg_struct *pBg = (med_panel_bg_struct*)userData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(h_dest_layer);
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    gdi_push_and_set_alpha_blending_source_layer(pBg->bgData.bgImg.blendLyr);
    gdi_image_draw_resized_id(
        pBg->bgData.bgImg.x,
        pBg->bgData.bgImg.y,
        pBg->bgData.bgImg.w,
        pBg->bgData.bgImg.h,
        pBg->bgData.bgImg.id);
    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_draw_layer_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_dest_layer        [IN]        
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 *  pBgData             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_med_panel_draw_layer_bg(gdi_handle h_dest_layer, S32 x1, S32 y1, S32 x2, S32 y2, void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle src_layer = ((med_panel_bg_struct*)userData)->bgData.bgLyr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(h_dest_layer);
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    gdi_layer_flatten(src_layer, GDI_LAYER_EMPTY_HANDLE, GDI_LAYER_EMPTY_HANDLE, GDI_LAYER_EMPTY_HANDLE);
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_init_color_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_panel         [IN]        
 *  bg_color        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_med_panel_init_color_bg(med_panel_handle h_panel, GDI_COLOR bg_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_panel_t *p_panel = (med_panel_t*) h_panel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_panel->bg.bgData.bgColor = bg_color;
    p_panel->bg.draw = mmi_med_panel_draw_color_bg;
    p_panel->bg.userData = (void*)&p_panel->bg;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_init_img_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_panel         [IN]        
 *  img_id          [IN]        
 *  blend_layer     [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  w               [IN]        
 *  h               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_med_panel_init_img_bg(
                med_panel_handle h_panel,
                MMI_IMG_ID img_id,
                GDI_HANDLE blend_layer,
                S32 x,
                S32 y,
                S32 w,
                S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_panel_t *p_panel = (med_panel_t*) h_panel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_panel->bg.bgData.bgImg.id = img_id;
    p_panel->bg.bgData.bgImg.blendLyr = blend_layer;
    p_panel->bg.bgData.bgImg.x = x;
    p_panel->bg.bgData.bgImg.y = y;
    p_panel->bg.bgData.bgImg.w = w;
    p_panel->bg.bgData.bgImg.h = h;
    p_panel->bg.draw = mmi_med_panel_draw_img_bg;
    p_panel->bg.userData = (void*)&p_panel->bg;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_init_layer_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_panel         [IN]        
 *  bg_layer        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_med_panel_init_layer_bg(med_panel_handle h_panel, GDI_HANDLE bg_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_panel_t *p_panel = (med_panel_t*) h_panel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_panel->bg.bgData.bgLyr = bg_layer;
    p_panel->bg.draw = mmi_med_panel_draw_layer_bg;
    p_panel->bg.userData = (void*)&p_panel->bg;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_init_custom_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_panel         [IN]        
 *  draw            [IN]        
 *  userData        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_med_panel_init_custom_bg(med_panel_handle h_panel, mmi_med_panel_draw_bg draw, void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_panel_t *p_panel = (med_panel_t*) h_panel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_panel->bg.userData = userData;
    p_panel->bg.draw = draw;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_create_panel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pbuf        [?]         
 *  h_layer     [IN]        
 *  x           [IN]        Position on layer
 *  y           [IN]        
 *  w           [IN]        
 *  h           [IN]        
 *  items       [?]         
 *  count       [IN]        
 *  h_bg_layer(?)
 * RETURNS
 *  
 *****************************************************************************/
med_panel_handle mmi_med_create_panel(
                    med_panel_t *pbuf,
                    gdi_handle h_layer,
                    S32 x,
                    S32 y,
                    S32 w,
                    S32 h,
                    med_panel_item_t items[],
                    U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(count <= MED_PANEL_MAX_ITEMS);

    memset(pbuf, 0, sizeof(med_panel_t));
    pbuf->x = x;
    pbuf->y = y;
    pbuf->w = w;
    pbuf->h = h;

    pbuf->h_layer = h_layer;
    pbuf->pitems = items;
    pbuf->item_count = count;

    pbuf->enable_flag = -1;
    pbuf->down_index = -1;

    return (med_panel_handle) pbuf;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_destroy_panel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_panel     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_med_destroy_panel(med_panel_handle h_panel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

static U32 mmi_med_panel_get_index(med_panel_t *p_panel, U32 id)
{
    U32 index;

    for(index = 0; index < p_panel->item_count; index++)
    {
        if(p_panel->pitems[index].id == id)
        {
            return index;
        }
    }

    return MED_PANEL_MAX_ITEMS;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_enable_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_panel     [IN]        
 *  id       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_med_panel_enable_item(med_panel_handle h_panel, U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_panel_t *p_panel = (med_panel_t*) h_panel;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_med_panel_get_index(p_panel, id);
    if(index == MED_PANEL_MAX_ITEMS){
        return;
    }
    
    if (p_panel->enable_flag & (0x1 << index))
    {
        return;
    }

    p_panel->enable_flag |= (0x1 << index);
    p_panel->update_flag |= (0x1 << index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_disable_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_panel     [IN]        
 *  id       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_med_panel_disable_item(med_panel_handle h_panel, U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_panel_t *p_panel = (med_panel_t*) h_panel;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_med_panel_get_index(p_panel, id);
    if(index == MED_PANEL_MAX_ITEMS){
        return;
    }
    
    if (!(p_panel->enable_flag & (0x1 << index)))
    {
        return;
    }

    p_panel->enable_flag &= ~(0x1 << index);
    p_panel->update_flag |= (0x1 << index);

#ifdef __MMI_TOUCH_SCREEN__
    if (p_panel->pen_stat == PANEL_STAT_DOWN_ITEM && p_panel->down_index == index)
    {
        /* disable will abort down operation */
        mmi_med_panel_penup(h_panel);
        p_panel->down_index = -1;
        p_panel->pen_stat = PANEL_STAT_INIT;
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_press_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_panel     [IN]        
 *  id       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_med_panel_press_item(med_panel_handle h_panel, U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_panel_t *p_panel = (med_panel_t*) h_panel;
    med_panel_item_t *pitem;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_med_panel_get_index(p_panel, id);
    if(index == MED_PANEL_MAX_ITEMS){
        return;
    }
    
    if (p_panel->down_index == index)
        return;

    if (!(p_panel->enable_flag & (0x1 << index)))
        return;

    pitem = &p_panel->pitems[index];
    if (MED_ITEM_IS_BTN(pitem->type))
    {
        pitem->data.btn3.stat = BTN_STAT_DOWN;
        pitem->draw(pitem, p_panel->h_layer, 1, &p_panel->bg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_up_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_panel     [IN]        
 *  id       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_med_panel_up_item(med_panel_handle h_panel, U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_panel_t *p_panel = (med_panel_t*) h_panel;
    med_panel_item_t *pitem;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_med_panel_get_index(p_panel, id);
    if(index == MED_PANEL_MAX_ITEMS){
        return;
    }
    

    pitem = &p_panel->pitems[index];
    if (MED_ITEM_IS_BTN(pitem->type))
    {
        if (pitem->data.btn3.stat == BTN_STAT_UP)
            return;

        pitem->data.btn3.stat = BTN_STAT_UP;
        if (!(p_panel->enable_flag & (0x1 << index)))
            return;
        pitem->draw(pitem, p_panel->h_layer, 1, &p_panel->bg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_draw_icon
 * DESCRIPTION
 *  Used to draw alpha bmp(png resource is generated to abm or ab2)
 * PARAMETERS
 *  dst_layer       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  ImageId         [IN]        
 *  src_layer(?)
 *  w(?)
 *  h(?)
 *  dst_layer_y(?)(?)
 *  dst_layer_x(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_med_panel_draw_icon(gdi_handle dst_layer, S32 x, S32 y, U16 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_type = gdi_image_get_type_from_id(ImageId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_IMAGE_TYPE_AB2 == img_type)
    {
        gdi_image_ab2_draw_id_nb_concurrent(dst_layer, x, y, dst_layer, ImageId);
    }
    else if (GDI_IMAGE_TYPE_ABM == img_type)
    {
        gdi_image_abm_draw_id_nb_concurrent(dst_layer, x, y, dst_layer, ImageId);
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_draw_txtbtn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pbtn                [IN]        
 *  h_dest_layer        [IN]        
 *  enable              [IN]        
 *  pBgData             [?]         
 *  h_bg_layer(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_med_panel_draw_txtbtn(
                const med_panel_item_t *pbtn,
                gdi_handle h_dest_layer,
                S32 enable,
                med_panel_bg_struct *pBg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x = 0;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define TXTBTN_COLOR            (*(current_MMI_theme->LSK_up_text_color))
#define TXTBTN_BORDER_COLOR     (*(current_MMI_theme->softkey_text_border_color))

    pBg->draw(h_dest_layer, pbtn->x - 1, pbtn->y - 1, pbtn->x + pbtn->w + 1, pbtn->y + pbtn->h + 1, pBg->userData);

    if (mmi_fe_get_r2l_state())
    {
        offset_x += pbtn->w;
    }

    if (pbtn->data.txtbtn.stat == BTN_STAT_DOWN)
    {
        offset_x++;
        offset_y++;
    }

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_FALSE);
#endif

    gdi_layer_push_and_set_active(h_dest_layer);
    gdi_layer_reset_clip();
    gdi_push_and_set_alpha_blending_source_layer(h_dest_layer);

    /* if is fullscreen display, or normal display but without mmi_softkey */
    gui_set_font((UI_font_type) gui_font_get_type(GUI_FONT_SIZE_BUTTON));

    gui_move_text_cursor(pbtn->x + offset_x, pbtn->y + offset_y);
    gui_set_text_color(TXTBTN_COLOR);
    gui_set_text_border_color(TXTBTN_BORDER_COLOR);
    gui_print_truncated_borderd_text(pbtn->x + offset_x, pbtn->y + offset_y, pbtn->w, (UI_string_type) pbtn->data.txtbtn.ptxt);
    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_TRUE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_draw_btn3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pbtn                [IN]        
 *  h_dest_layer        [IN]        
 *  enable              [IN]        
 *  pBgData             [?]         
 *  h_bg_layer(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_med_panel_draw_btn3(
                const med_panel_item_t *pbtn,
                gdi_handle h_dest_layer,
                S32 enable,
                med_panel_bg_struct *pBg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pBg->draw(h_dest_layer, pbtn->x, pbtn->y, pbtn->x + pbtn->w - 1, pbtn->y + pbtn->h - 1, pBg->userData);

    if (!enable)
    {
        icon_id = pbtn->data.btn3.icon_disable;
    }
    else if (pbtn->data.btn3.stat == BTN_STAT_DOWN)
    {
        icon_id = pbtn->data.btn3.icon_press;
    }
    else
    {
        icon_id = pbtn->data.btn3.icon_up;
    }

    mmi_med_panel_draw_icon(h_dest_layer, pbtn->x, pbtn->y, icon_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_draw_btn4
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pbtn                [IN]        
 *  h_dest_layer        [IN]        
 *  enable              [IN]        
 *  pBgData             [?]         
 *  h_bg_layer(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_med_panel_draw_btn4(
                const med_panel_item_t *pbtn,
                gdi_handle h_dest_layer,
                S32 enable,
                med_panel_bg_struct *pBg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_w, icon_h;
    MMI_IMG_ID mask_id = MED_PANEL_DUMMY_RES_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pBg->draw(h_dest_layer, pbtn->x, pbtn->y, pbtn->x + pbtn->w - 1, pbtn->y + pbtn->h - 1, pBg->userData);

    gdi_image_get_dimension_id(pbtn->data.btn4.icon, &icon_w, &icon_h);

#ifndef __MMI_FTE_SUPPORT__
    mmi_med_panel_draw_icon(h_dest_layer, pbtn->x, pbtn->y, pbtn->data.btn4.icon_bg);
#else
    gdi_layer_push_and_set_active(h_dest_layer);
    gdi_image_draw_resized_id(pbtn->x, pbtn->y, pbtn->w, pbtn->h, pbtn->data.btn4.icon_bg);
    gdi_layer_pop_and_restore_active();
#endif

    mmi_med_panel_draw_icon(
        h_dest_layer,
        pbtn->x + ((pbtn->w - icon_w) >> 1),
        pbtn->y + ((pbtn->h - icon_h) >> 1),
        pbtn->data.btn4.icon);

    if (!enable)
    {
        mask_id = pbtn->data.btn4.icon_dis_mask;
    }
    else if (pbtn->data.btn4.stat == BTN_STAT_DOWN)
    {
        mask_id = pbtn->data.btn4.icon_hl_mask;
    }

    if (MED_PANEL_DUMMY_RES_ID != mask_id)
    {
        gdi_layer_push_and_set_active(h_dest_layer);
        gdi_push_and_set_alpha_blending_source_layer(h_dest_layer);
        gdi_image_draw_resized_id(pbtn->x, pbtn->y, pbtn->w, pbtn->h, mask_id);
        gdi_pop_and_restore_alpha_blending_source_layer();
        gdi_layer_pop_and_restore_active();
    }
}

/* redraw each item */


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_redraw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_panel         [IN]        
 *  is_update       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_med_panel_redraw(med_panel_handle h_panel, MMI_BOOL is_update)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_panel_t *p_panel = (med_panel_t*) h_panel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_update == MMI_FALSE)
    {
        p_panel->update_flag = 0xFFFFFFFF;
    }
    if (!p_panel->update_flag)
    {
        return;
    }

    mmi_med_panel_update(h_panel);
}

/* redraw items which state change */


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_panel     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_med_panel_update(med_panel_handle h_panel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    med_panel_t *p_panel = (med_panel_t*) h_panel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!p_panel->update_flag)
        return;

    /* draw each item */
    for (i = 0; i < p_panel->item_count; i++)
    {
        if (p_panel->update_flag & (0x1 << i))
        {
            p_panel->pitems[i].draw(
                                &p_panel->pitems[i],
                                p_panel->h_layer,
                                p_panel->enable_flag & (0x1 << i),
                                &p_panel->bg);
        }
    }

    /* clear update flag */
    p_panel->update_flag = 0;
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_set_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_panel         [IN]        
 *  event_cb        [IN]        
 *  usrdata         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_med_panel_set_cb(med_panel_handle h_panel, med_panel_cb_t event_cb, void *usrdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_panel_t *p_panel = (med_panel_t*) h_panel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_panel->callback = event_cb;
    p_panel->usrdata = usrdata;
}


/*****************************************************************************
 * FUNCTION
 *  med_panel_get_item
 * DESCRIPTION
 *  Get item which the pos is in.
 * PARAMETERS
 *  p_panel     [?]         
 *  pos         [IN]        Pen pos.
 *  index       [OUT]       Item index. -1 : not in panel area. item_count: none-item area of panel.
 * RETURNS
 *  item.
 *****************************************************************************/
static med_panel_item_t *med_panel_get_item(med_panel_t *p_panel, mmi_pen_point_struct pos, int *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos.x -= p_panel->x;
    pos.y -= p_panel->y;

    for (i = 0; i < p_panel->item_count; i++)
    {
        if ((pos.x >= p_panel->pitems[i].x) && (pos.x < p_panel->pitems[i].x + p_panel->pitems[i].w)
            && (pos.y >= p_panel->pitems[i].y) && (pos.y < p_panel->pitems[i].y + p_panel->pitems[i].h))
        {
            *index = i;
            return &p_panel->pitems[i];
        }
    }

    return NULL;

}

static void mmi_med_panel_screen_to_layer(S16 *px, S16 *py, U8 lyrRotV)
{
    S16 temp;
    switch(lyrRotV)
    {
    case  GDI_LCD_LAYER_ROTATE_90:
        temp = *px;
        *px = *py;
        *py = LCD_WIDTH -temp;
        break;

    case  GDI_LCD_LAYER_ROTATE_180:
        *px = LCD_WIDTH -(*px);
        *py = LCD_HEIGHT -(*py);
        break;

    case  GDI_LCD_LAYER_ROTATE_270:
        temp = *px;
        *px = LCD_WIDTH -(*py);
        *py = temp;
        break;

    default:
        break;
    };
}

static void mmi_med_panel_scrn2view(gdi_handle h_layer, mmi_pen_point_struct *pos)
{
    U8 rot;

    gdi_layer_push_and_set_active(h_layer);
    rot = gdi_layer_get_rotate();
    gdi_layer_pop_and_restore_active();

    mmi_med_panel_screen_to_layer(&pos->x, &pos->y, rot);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_pendown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_panel     [IN]        
 *  pos         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_med_panel_pendown(med_panel_handle h_panel, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index;
    med_panel_t *p_panel = (med_panel_t*) h_panel;
    med_panel_item_t *pitem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_med_panel_scrn2view(p_panel->h_layer, &pos);
    
    if (pos.x < p_panel->x || pos.x >= p_panel->x + p_panel->w ||
        pos.y < p_panel->y || pos.y >= p_panel->y + p_panel->h)
    {   /* out panel */
        return MMI_FALSE;
    }

    pitem = med_panel_get_item(p_panel, pos, &index);

    if (pitem && (p_panel->enable_flag & (0x1 << index)))
    {   /* On enabled item */
        p_panel->down_index = index;
        p_panel->pen_stat = PANEL_STAT_DOWN_ITEM;
        if (MED_ITEM_IS_BTN(pitem->type))
        {
            pitem->data.btn3.stat = BTN_STAT_DOWN;
            pitem->draw(pitem, p_panel->h_layer, 1, &p_panel->bg);
            if (p_panel->callback)
            {
                p_panel->callback(pitem->id, MED_EVT_BTN_DOWN, p_panel->usrdata);
            }

        }
        else if (pitem->type == MED_ITEM_PROGRESS)
        {
        }
    }
    else
    {
        p_panel->pen_stat = PANEL_STAT_DOWN_N_ITEM;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_penup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_panel     [IN]        
 *  pos(?)
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_med_panel_penup(med_panel_handle h_panel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_panel_t *p_panel = (med_panel_t*) h_panel;
    med_panel_item_t *pitem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pitem = &(p_panel->pitems[p_panel->down_index]);

    switch (p_panel->pen_stat)
    {
        case PANEL_STAT_INIT:
            return MMI_FALSE;

        case PANEL_STAT_DOWN_ITEM:
            if (pitem)
            {
                if (MED_ITEM_IS_BTN(pitem->type) && pitem->data.btn3.stat == BTN_STAT_DOWN)
                {
                    pitem->data.btn3.stat = BTN_STAT_UP;

                    if (p_panel->callback)
                    {
                        p_panel->callback(pitem->id, MED_EVT_BTN_PRE_UP, p_panel->usrdata);
                    }
                    pitem->draw(pitem, p_panel->h_layer, 1, &p_panel->bg);
                    if (p_panel->callback)
                    {
                        p_panel->callback(pitem->id, MED_EVT_BTN_UP, p_panel->usrdata);
                    }

                }
                else if (pitem->type == MED_ITEM_PROGRESS)
                {
                }
            }
            break;

        case PANEL_STAT_DOWN_DISABLE:
            if (MED_ITEM_IS_BTN(pitem->type))
            {
                pitem->data.btn3.stat = BTN_STAT_UP;
            }
            break;

        default:
            break;
    };

    p_panel->down_index = -1;
    p_panel->pen_stat = PANEL_STAT_INIT;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_penmove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_panel     [IN]        
 *  pos         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_med_panel_penmove(med_panel_handle h_panel, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index;
    med_panel_t *p_panel = (med_panel_t*) h_panel;
    med_panel_item_t *pitem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_med_panel_scrn2view(p_panel->h_layer, &pos);
    
    switch (p_panel->pen_stat)
    {
        case PANEL_STAT_INIT:
            return MMI_FALSE;

        case PANEL_STAT_DOWN_ITEM:
            pitem = med_panel_get_item(p_panel, pos, &index);
            if (pitem != &p_panel->pitems[p_panel->down_index])
            {   /* Out of down item */
                pitem = &p_panel->pitems[p_panel->down_index];
                /* Cancel */
                if (MED_ITEM_IS_BTN(pitem->type) && pitem->data.btn3.stat == BTN_STAT_DOWN)
                {
                    pitem->data.btn3.stat = BTN_STAT_UP;
                    pitem->draw(pitem, p_panel->h_layer, 1, &p_panel->bg);
                    if (p_panel->callback)
                    {
                        p_panel->callback(pitem->id, MED_EVT_BTN_CANCEL, p_panel->usrdata);
                    }

                }
                else if (pitem->type == MED_ITEM_PROGRESS)
                {
                }

                p_panel->pen_stat = PANEL_STAT_DOWN_N_ITEM;
            }

            break;

        default:
            break;
    };

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_med_panel_penabort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_panel         [IN]        
 *  abort_type      [IN]        
 *  pos(?)
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_med_panel_penabort(med_panel_handle h_panel, mmi_pen_abort_type_enum abort_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_panel_t *p_panel = (med_panel_t*) h_panel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_panel->pen_stat)
    {
        case PANEL_STAT_INIT:
            return MMI_FALSE;

        case PANEL_STAT_DOWN_ITEM:
            /* get pen abort type, will do pen up action if pen up lost because queue full, or do nothing */
            if (abort_type == MMI_PEN_ABORT_TYPE_DRVQ_FULL)
            {
                mmi_med_panel_penup(h_panel);
            }
            break;

        default:
            break;
    };

    p_panel->down_index = -1;
    p_panel->pen_stat = PANEL_STAT_INIT;
    return MMI_TRUE;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

