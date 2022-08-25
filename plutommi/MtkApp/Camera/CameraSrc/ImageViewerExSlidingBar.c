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
 *  ImageViewerEXSlidingBar.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  ImageViewer's header file
 *
 * Author:
 * -------
 * -------
 *                      
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_IMAGE_VIEWER_EX__) && defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
#include "ImageViewerEXSlidingBar.h"
#include "ImageViewerExApp.h"

extern SlidingBarLayout g_sliding_bar_layout_skin_0;
extern SlidingBarLayout g_sliding_bar_layout_skin_270;

extern MMI_BOOL sliding_bar_is_in_sliding_bar(SlidingBar *sb, S32 x, S32 y);

static SlidingBarLayout g_sliding_bar_layout_0;
static SlidingBarLayout g_sliding_bar_layout_270;

static void sliding_bar_relocate_slider (double progress, SlidingBarLayout *layout) {
    layout->slider_rect.x = (S32) (layout->min_edge + (layout->max_edge - layout->min_edge) * progress / 100.0 - layout->slider_rect.w / 2);
    layout->slider_event_rect.x= layout->slider_rect.x - (layout->slider_event_rect.w - layout->slider_rect.w) / 2;
    layout->slider_event_rect.y= layout->slider_rect.y - (layout->slider_event_rect.h - layout->slider_rect.h) / 2;
}

/**
 * Initialize sliding bar.
 */
void sliding_bar_init (SlidingBar *sb, U16 bg, U16 slider, U16 highlighted_slider, U8 orientation) {
	
	MMI_ASSERT(sb != NULL);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGVIEW_SLIDING_BAR_INIT);
	
	memset(sb, 0, sizeof(SlidingBar));
    memcpy(&g_sliding_bar_layout_0, &g_sliding_bar_layout_skin_0, sizeof(SlidingBarLayout));
    memcpy(&g_sliding_bar_layout_270, &g_sliding_bar_layout_skin_270, sizeof(SlidingBarLayout));

	sb->bg_image = bg;
	sb->slider_image = slider;
	sb->slider_image_pressed = highlighted_slider;

    sliding_bar_set_active_layout(sb, orientation);
}

void sliding_bar_deinit (SlidingBar *sb) {
}

void sliding_bar_redraw(SlidingBar *sb) {
	U16 slider_image_id;
    gdi_handle layer = GDI_LAYER_EMPTY_HANDLE;


    if (sb->active_layout == &g_sliding_bar_layout_270)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGVIEW_SLIDING_BAR_REDRAW, GDI_LCD_LAYER_ROTATE_90);
        layer = sb->panel_layer;
    }
    else if (sb->active_layout == &g_sliding_bar_layout_0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGVIEW_SLIDING_BAR_REDRAW, GDI_LCD_LAYER_ROTATE_0);
        layer = sb->external_layer;
    }
    else {
        MMI_ASSERT(0);
    }

    sliding_bar_relocate_slider(sb->progress, sb->active_layout);
    
	gdi_layer_push_and_set_active(layer);
    gdi_push_and_set_alpha_blending_source_layer(layer);
    if (sb->active_layout == &g_sliding_bar_layout_270)
    {
        gdi_draw_solid_rect(0, 0, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_270-1, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_270-1, GDI_COLOR_TRANSPARENT);
    }
    else if (sb->active_layout == &g_sliding_bar_layout_0)
    {
        gdi_draw_solid_rect(0, 0, MMI_IVEX_OSD_SLIDING_BAR_LAYER_WIDTH_0-1, MMI_IVEX_OSD_SLIDING_BAR_LAYER_HEIGHT_0-1, GDI_COLOR_TRANSPARENT);
    }
    else {
        MMI_ASSERT(0);
    }
	gdi_image_draw_resized( 
		sb->active_layout->bg_rect.x, 
		sb->active_layout->bg_rect.y, 
		sb->active_layout->bg_rect.w, 
		sb->active_layout->bg_rect.h,
		GetImage(sb->bg_image));
	slider_image_id = sb->slider_pressed ? sb->slider_image_pressed : sb->slider_image;
	gdi_image_draw_resized(
		sb->active_layout->slider_rect.x,
		sb->active_layout->slider_rect.y,
		sb->active_layout->slider_rect.w,
		sb->active_layout->slider_rect.h,
		GetImage(slider_image_id));

#if defined(__SLIDING_BAR_DEBUG__) && defined(__MMI_TOUCH_SCREEN__)
    gdi_draw_line(
        sb->last_position.x,
        0,
        sb->last_position.x,
        48,
        GDI_COLOR_RED);
    gdi_draw_line(
        0,
        sb->last_position.y,
        268,
        sb->last_position.y,
        GDI_COLOR_RED);
#endif
    
    gdi_pop_and_restore_alpha_blending_source_layer();
	gdi_layer_pop_and_restore_active();
}


#ifdef __MMI_TOUCH_SCREEN__
static S32 sliding_bar_constraint_to_range(SlidingBar *sb, S32 x);
static double sliding_bar_calculate_progress(SlidingBar *sb, S32 x);

void sliding_bar_pen_down_handler(SlidingBar *sb, mmi_pen_point_struct *pos) {
	S32 effective_x;
	double effective_progress;
	effective_x = sliding_bar_constraint_to_range(sb, pos->x);
	effective_progress = sliding_bar_calculate_progress(sb, effective_x);
#if defined(__SLIDING_BAR_DEBUG__)
	sb->last_position.x = pos->x;
	sb->last_position.y = pos->y;
#endif
	sb->slider_pressed = MMI_TRUE;
	sliding_bar_set_progress(sb, effective_progress);
}

void sliding_bar_pen_move_handler(SlidingBar *sb, mmi_pen_point_struct *pos) {
	S32 effective_x;
	double effective_progress;

	effective_x = sliding_bar_constraint_to_range(sb, pos->x);
	effective_progress = sliding_bar_calculate_progress(sb, effective_x);
#if defined(__SLIDING_BAR_DEBUG__)
	sb->last_position.x = pos->x;
	sb->last_position.y = pos->y;
#endif
	sliding_bar_set_progress(sb, effective_progress);
}

void sliding_bar_pen_up_handler(SlidingBar *sb, mmi_pen_point_struct *pos) {
	S32 effective_x;
	double effective_progress;

	effective_x = sliding_bar_constraint_to_range(sb, pos->x);
	effective_progress = sliding_bar_calculate_progress(sb, effective_x);
#if defined(__SLIDING_BAR_DEBUG__)
	sb->last_position.x = 0;
	sb->last_position.y = 0;
#endif
	sb->slider_pressed = MMI_FALSE;
	sliding_bar_set_progress(sb, effective_progress);
}

void sliding_bar_pen_abort_handler(SlidingBar *sb, mmi_pen_point_struct *pos) {
	sliding_bar_pen_up_handler(sb, pos);
}

MMI_BOOL sliding_bar_is_in_slider(SlidingBar *sb, S32 x, S32 y) {
	if ((x >= sb->active_layout->slider_event_rect.x) &&
		(x <= (sb->active_layout->slider_event_rect.x + sb->active_layout->slider_event_rect.w)) &&
		(y >= sb->active_layout->slider_event_rect.y) &&
		(y <= (sb->active_layout->slider_event_rect.y + sb->active_layout->slider_event_rect.h)))
	{
		return MMI_TRUE;
	}
	else
		return MMI_FALSE;
}

MMI_BOOL sliding_bar_is_in_sliding_bar(SlidingBar *sb, S32 x, S32 y) {
	if ((x >= sb->active_layout->bg_event_rect.x) &&
		(x <= (sb->active_layout->bg_event_rect.x + sb->active_layout->bg_event_rect.w)) &&
		(y >= sb->active_layout->bg_event_rect.y) &&
		(y <= (sb->active_layout->bg_event_rect.y + sb->active_layout->bg_event_rect.h)))
	{
		return MMI_TRUE;
	}
	else
		return MMI_FALSE;
}

static S32 sliding_bar_constraint_to_range(SlidingBar *sb, S32 x) {
	if (x < sb->active_layout->min_edge)
		return sb->active_layout->min_edge;
	else if (x > sb->active_layout->max_edge)
		return sb->active_layout->max_edge;
	else
		return x;
}

static double sliding_bar_calculate_progress(SlidingBar *sb, S32 x) {
	double progress;
	MMI_ASSERT(sb != NULL && x >= sb->active_layout->min_edge && x <= sb->active_layout->max_edge);
	progress = (x - sb->active_layout->min_edge) * 100.0 / (sb->active_layout->max_edge - sb->active_layout->min_edge);
    if (progress < 0.0)
        progress = 0.0;
    if (progress > 100.0)
        progress = 100.0;
	return progress;
}
#endif /* __MMI_TOUCH_SCREEN__ */

void sliding_bar_set_progress_ex(SlidingBar *sb, double progress, MMI_BOOL redraw, MMI_BOOL notify) {
	MMI_ASSERT(sb != NULL);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGVIEW_SLIDING_BAR_SET_PROGRESS, (int)(progress), redraw, notify);
    if (progress < 0.0)
        progress = 0.0;

    if (progress > 100.0)
        progress = 100.0;

	sb->progress = progress;
	if (redraw) {
		sliding_bar_redraw(sb);
	}
	if (notify) {
		sliding_bar_notify_observer(sb);
	}
}

void sliding_bar_set_progress_observer(SlidingBar *sb, sliding_bar_progess_observer observer, void *userdata) {
    sb->observer = observer;
    sb->userdata = userdata;
}

void sliding_bar_clear_progress_observer(SlidingBar *sb) {
    sb->observer = NULL;
    sb->userdata = NULL;
}

void sliding_bar_notify_observer(SlidingBar *sb) {
	if (sb->observer != NULL) {
		sb->observer(sb, sb->userdata);
	}
}

void sliding_bar_set_active_layout(SlidingBar *sb, U8 orientation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGVIEW_SLIDING_BAR_SET_ORIENTATION, orientation);
    if (orientation == GDI_LCD_LAYER_ROTATE_90)
    {
        sb->active_layout = &g_sliding_bar_layout_270;
    }
    else if (orientation == GDI_LCD_LAYER_ROTATE_0)
    {
        sb->active_layout = &g_sliding_bar_layout_0;
    }
    else {
        MMI_ASSERT(0);
    }
}

#endif /* __MMI_IMAGE_VIEWER_EX__ */
