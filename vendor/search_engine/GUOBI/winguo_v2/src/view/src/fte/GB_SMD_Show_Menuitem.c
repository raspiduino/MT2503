#include "gui_fixed_menuitems.h"
#include "CustMenuRes.h"
#include "gui_fixed_menus.h"


/***************************************************************************** 
 *  Declaration
 *****************************************************************************/ 
extern BOOL r2lMMIFlag;
extern gui_effect_struct    *g_slide_effect;
extern UI_filled_area fixed_single_line_menuitem_filled_area;
extern S32 GUI_current_fixed_icontext_list_menuitem_x;
extern S32 GUI_current_fixed_icontext_list_menuitem_y;
extern S32 MMI_current_menu_type;
extern fixed_list_menu MMI_fixed_list_menu;

#define gui_list_set_alpha_blending_layer() gui_list_set_alpha_blending_layer_ex(0, MMI_FALSE)

void GB_WG_SMD_Control_show_list_menuitem_ex(void *item, void *common_item_data, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, menu_y1, menu_y2;
    S32 ix1, iy1, ix2, iy2;
    color text_color;
    UI_filled_area *f = NULL;
    fixed_icontext_list_menuitem *m = (fixed_icontext_list_menuitem*) common_item_data;
    fixed_icontext_list_menuitem_type *mi = (fixed_icontext_list_menuitem_type*) item;
    U32 flags, flags_ext;
    UI_string_type _text;
    PU8 _icon;
    U8 focussed_flag = 0;
    S32 i, sw, sh;
    gdi_handle old_alpha_layer = GDI_NULL_HANDLE;
    S32 icon_width, icon_height;
    S32 count = 0;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;
    gdi_handle act_layer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    flags     = mi->flags | m->flags;
    flags_ext = mi->ext_flags | m->ext_flags;

	if (MMI_fixed_list_menu.current_displayed_item == MMI_fixed_list_menu.n_items - 1 &&
		(flags & UI_MENUITEM_STATE_FOCUSSED) &&
		MMI_fixed_list_menu.current_displayed_item != MMI_fixed_list_menu.highlighted_item)   
	{
		flags &= ~UI_MENUITEM_STATE_FOCUSSED;
	}

    if (flags & UI_MENUITEM_STATE_FOCUSSED)
    {
        GUI_current_fixed_icontext_list_menuitem_x = x;
        GUI_current_fixed_icontext_list_menuitem_y = y;
    }

    x1 = x;
    y1 = y;
    y2 = y1 + m->height - 1;
    x2 = x1 + m->width - 1;  
    menu_y1 = m->parent_list->y;
    menu_y2 = m->parent_list->y + m->parent_list->height - 1;

    if ((flags & UI_MENUITEM_STATE_FOCUSSED) && !(flags & UI_MENUITEM_DISABLE_HIGHLIGHT))
    {
        f = (UI_filled_area *)gui_list_get_focussed_filler((gui_common_menuitem_base_struct*) m);
        fixed_single_line_menuitem_filled_area = *f;
        focussed_flag = 1; 
    }	
    gui_push_clip();
    
    clip_x1 = x1;
    clip_x2 = x2;
    clip_y1 = y1;
    clip_y2 = y2;

    gdi_layer_get_active(&act_layer);
    if (MMI_current_menu_type == LIST_MENU && clip_y1 < m->parent_list->y && m->parent_list->act_layer_handle == act_layer)
    {
        clip_y1 = m->parent_list->y;
    }            
    if (y1 >= menu_y2)
    {
        clip_y1 = menu_y2;
        clip_y2 = menu_y2;
    }
    else if (y2 >= menu_y2)
    {
        clip_y2 = menu_y2;
    }
    
    gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);

    if (f != NULL && (!(flags & UI_MENUITEM_HIGHLIGHT_SWITCH_ICON)) && !g_slide_effect->in_flatten)
    {
    #ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
        {
            mmi_frm_dss_set_menu_highlight(MMI_SCREEN_HIGHLIGHT_ICONTEXT_LIST);
        }
    #endif

    old_alpha_layer = gui_list_set_alpha_blending_layer();
    set_start_position_and_item_parameters_for_list_highlighter_effect(item, common_item_data, x1, y1);

        gui_draw_list_filled_area(x1, y1, x2, y2, f);

        gui_list_reset_alpha_blending_layer(old_alpha_layer);
    }
	
    /* show checkbox, show it here to correspond to list effects since */
    old_alpha_layer = gui_list_set_alpha_blending_layer_ex(flags, MMI_TRUE);

    for (i = 0; i < m->n_icon_columns; i++)
    {
        /* For bi-degree main menu */
        /* selected item, should draw selected image */
        if (mi->item_icon_handles[i] != GDI_ERROR_HANDLE)
        {
            gdi_image_stop_animation(mi->item_icon_handles[i]);
            mi->item_icon_handles[i] = GDI_ERROR_HANDLE;
        }
        _icon = mi->item_icons[i];

        /* calculate the icon position */
        iy1 = m->icon_coordinates[i].y + y1;
            gui_measure_image(_icon, &icon_width, &icon_height);
            iy1 = m->icon_coordinates[i].y + y1 + (m->icon_coordinates[i].height >> 1) - (icon_height >> 1);
        
            if (r2lMMIFlag)
            {
                ix1 = x2 - m->icon_coordinates[i].x - icon_width + 1;
            }
            else
            {
                ix1 = m->icon_coordinates[i].x + x1;
            }
            ix2 = ix1 + icon_width - 1;
            iy2 = iy1 + icon_height - 1;

        if (ix2 > x2)
        {
            ix2 = x2;
        }
        if (iy2 > y2)
        {
            iy2 = y2;
        }

        gui_push_clip();

        clip_x1 = ix1;
        clip_y1 = iy1;
        clip_x2 = ix2;
        clip_y2 = iy2;

        gdi_layer_get_active(&act_layer);
        if (MMI_current_menu_type == LIST_MENU && clip_y1 < m->parent_list->y && m->parent_list->act_layer_handle == act_layer)
        {
            clip_y1 = m->parent_list->y;
        }            
        if (iy1 >= menu_y2)
        {
            clip_y1 = menu_y2;
            clip_y2 = menu_y2;
        }
        else if (iy2 >= menu_y2)
        {
            clip_y2 = menu_y2;
        }
        gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);

        if (_icon != UI_NULL_IMAGE && iy1 < y2)
        {
            UI_filled_area         *anim_bkg_filler = NULL;
            gdi_image_draw_frames(ix1, iy1, _icon, 0);
         }
        gui_pop_clip();

    }
    
    gui_list_reset_alpha_blending_layer(old_alpha_layer);

    gui_push_text_clip();

    clip_x1 = x1;
    clip_y1 = y1;
    clip_x2 = x2;
    clip_y2 = y2;

    gdi_layer_get_active(&act_layer);
    if (MMI_current_menu_type == LIST_MENU && clip_y1 < m->parent_list->y && m->parent_list->act_layer_handle == act_layer)
    {
        clip_y1 = m->parent_list->y;
    }            
    if (y1 >= menu_y2)
    {
        clip_y1 = menu_y2;
        clip_y2 = menu_y2;
    }
    else if (y2 >= menu_y2)
    {
        clip_y2 = menu_y2;
    }
    gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
    if (!(flags & UI_MENUITEM_DISABLE_TEXT_DISPLAY))
    {
        S32 col1_iy1 = 0, col1_ascent = 0, baseline = 0;
#ifdef  __MMI_VECTOR_FONT_SUPPORT__
        old_alpha_layer = gui_list_set_alpha_blending_layer_ex(flags, MMI_TRUE);
#endif  // __MMI_VECTOR_FONT_SUPPORT__

        for (i = 0; i < m->n_text_columns; i++)
        {
            _text = mi->item_texts[i];
            if ((mi->flags & UI_MENUITEM_STATE_FOCUSSED) && 
                (MMI_current_menu_type == LIST_MENU) && 
                (!(flags & UI_MENUITEM_DISABLE_HIGHLIGHT)) &&
                (m->selected_fonts[i]))
            {
                gui_set_font(m->selected_fonts[i]);
            }
            else
            {
                gui_set_font(m->text_fonts[i]);
            }
            gui_measure_string(_text, &sw, &sh);

         {
           S32 ww;
           WCHAR   widthstr[6]={0x6211, 0x6f56,'o', 'k','g', 0};	
           mmi_fe_get_string_info_param_struct query;
           memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
           query.String = (U8*)widthstr;
           query.checkCompleteWord = MMI_FALSE;
           query.enableTruncated = MMI_FALSE;
           query.n =  mmi_ucs2strlen((const char*)widthstr);
           query.w = 0;
           mmi_fe_get_string_widthheight(&query);
           gui_measure_string(widthstr, &ww, &sh);
           baseline = query.baseline;
         }

            iy1 = m->text_coordinates[i].y + y1;
            iy2 = iy1 + m->text_coordinates[i].height - 1;
  	        iy1 = m->text_coordinates[i].y + y1 + (m->text_coordinates[i].height >> 1) - (sh >> 1);
            iy2 = iy1 + sh - 1;			
	
            if (r2lMMIFlag)
            {
                ix1 = x2 - m->text_coordinates[i].x - m->text_coordinates[i].width + 1;
                ix2 = ix1 + m->text_coordinates[i].width - 1;
            }
            else
            {
                ix1 = m->text_coordinates[i].x + x1;
                ix2 = ix1 + m->text_coordinates[i].width - 1;
            }

            if (ix2 > x2)
            {
                ix2 = x2;
            }

            if (iy2 > y2)
            {
                iy2 = y2;
            }

            if ( _text && mmi_ucs2strlen((CHAR *)_text) && iy1 < y2)
            {
                    if (focussed_flag)
                    {
                        text_color = m->focussed_text_colors[i];
                    }
                    else
                    {
                        text_color = m->normal_text_colors[i];
                    }
                    
                    gui_push_clip();
                    if (!(flags & UI_MENUITEM_DISABLE_TEXT_CLIP))
                    {
                        clip_x1 = ix1;
                        clip_x2 = ix2;
                        clip_y1 = iy1;
                        clip_y2 = iy2;

                        gdi_layer_get_active(&act_layer);
                        if (MMI_current_menu_type == LIST_MENU && clip_y1 < m->parent_list->y && m->parent_list->act_layer_handle == act_layer)
                        {
                            clip_y1 = m->parent_list->y;
                        }            
                        if (iy1 >= menu_y2)
                        {
                            clip_y1 = menu_y2;
                            clip_y2 = menu_y2;
                        }
                        else if (iy2 >= menu_y2)
                        {
                            clip_y2 = menu_y2;
                        }

                        gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
                    }
                    gui_set_text_color(text_color);

                    {       
                        S32 temp_text_width = m->text_coordinates[i].width;
                        if (flags & UI_MENUITEM_STATE_FOCUSSED)
                            /* Second Column Text Scroll Change For Multi Row List */
                        {
                            if (sw > temp_text_width)
                            {
                                if (r2lMMIFlag)
                                {
                                    gui_move_text_cursor(ix2 + m->scroll_x, iy1);
                                }
                                else
                                {
                                    gui_move_text_cursor(ix1 + m->scroll_x, iy1);
                                }
                            }
                            else
                            {
                                if (r2lMMIFlag)
                                {
                                    gui_move_text_cursor(ix2, iy1);
                                }
                                else
                                {
                                    gui_move_text_cursor(ix1, iy1);
                                }
                            }
                            gui_set_line_height(sh);
                            mmi_fe_show_ellipsis_text_ext(ix1, iy1, temp_text_width, (U8 *)_text, (U8*)(UI_string_type) GUI_TEXT_TRUNCATE_SUFFIX, MMI_FALSE, MMI_FE_ELLIPSIS_TAIL, baseline);           
                        }
                        else
                        {
                                if (r2lMMIFlag)
                                {
                                    gui_move_text_cursor(ix2, iy1);
                                }
                                else
                                {
                                    gui_move_text_cursor(ix1, iy1);
                                }  
                                gui_set_line_height(sh);
                                mmi_fe_show_ellipsis_text_ext(ix1, iy1, temp_text_width, (U8 *)_text, (U8*)(UI_string_type) GUI_TEXT_TRUNCATE_SUFFIX, MMI_FALSE, MMI_FE_ELLIPSIS_TAIL, baseline);	                       
                        }
                    }
                    gui_pop_clip();
                }
            }
            
#ifdef  __MMI_VECTOR_FONT_SUPPORT__
            gui_list_reset_alpha_blending_layer(old_alpha_layer);
#endif
        }

    gdi_layer_get_active(&act_layer);
    gui_pop_text_clip();
    gui_pop_clip();
}
