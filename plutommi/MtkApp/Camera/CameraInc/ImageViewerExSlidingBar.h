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

#ifndef _IMAGE_VIEWER_EX_SLIDING_BAR_H_
#define _IMAGE_VIEWER_EX_SLIDING_BAR_H_

#include "MMI_features.h"

#if defined(__MMI_IMAGE_VIEWER_EX__) && defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)

#include "lcd_sw_inc.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "ImageViewerExAppGprot.h"

#include "mmi_frm_input_gprot.h"

//#define __SLIDING_BAR_DEBUG__

typedef struct {
	S32 x;
	S32 y;
	S32 w;
	S32 h;
} Rect;

typedef struct _SlidingBar SlidingBar;

typedef void (*sliding_bar_progess_observer) (SlidingBar *sb, void *userdata);

typedef struct _SlidingBarLayout {
	Rect bg_rect;       /* rect for presentation */
	Rect bg_event_rect; /* rect for touch event processing */
	Rect slider_rect;   /* x is not used */
	Rect slider_event_rect; /* x and y are not used */
	S32 min_edge;
	S32 max_edge;
	Rect panel_rect;
} SlidingBarLayout;

/**
 * Sliding Bar
 * 
 */
typedef struct _SlidingBar {
	U16 bg_image;
	U16 slider_image;
	U16 slider_image_pressed;
	MMI_BOOL slider_pressed;
	SlidingBarLayout *active_layout;
	double progress; /* valid range: [0, 100] */
#if defined(__SLIDING_BAR_DEBUG__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_pen_point_struct last_position;
#endif
	gdi_handle panel_layer;
    S32 panel_layer_width;
    S32 panel_layer_height;
    gdi_handle external_layer;
	sliding_bar_progess_observer observer;
	void *userdata;
} SlidingBar;

extern void sliding_bar_init(SlidingBar *sb, U16 bg, U16 slider, U16 highlighted_slider, U8 orientation);
#ifdef __MMI_TOUCH_SCREEN__
extern void sliding_bar_pen_down_handler(SlidingBar *sb, mmi_pen_point_struct *pos);
extern void sliding_bar_pen_move_handler(SlidingBar *sb, mmi_pen_point_struct *pos);
extern void sliding_bar_pen_up_handler(SlidingBar *sb, mmi_pen_point_struct *pos);
extern void sliding_bar_pen_abort_handler(SlidingBar *sb, mmi_pen_point_struct *pos);
extern MMI_BOOL sliding_bar_is_in_sliding_bar(SlidingBar *sb, S32 x, S32 y);
#endif
extern void sliding_bar_redraw(SlidingBar *sb);
extern void sliding_bar_set_progress_ex(SlidingBar *sb, double progress, MMI_BOOL redraw, MMI_BOOL notify);
#define sliding_bar_set_progress(sb, progress) sliding_bar_set_progress_ex(sb, progress, MMI_TRUE, MMI_TRUE);
extern void sliding_bar_set_progress_observer(SlidingBar *sb, sliding_bar_progess_observer observer, void *userdata);
extern void sliding_bar_clear_progress_observer(SlidingBar *sb);
extern void sliding_bar_notify_observer(SlidingBar *sb);
extern void sliding_bar_set_active_layout(SlidingBar *sb, U8 orientation);


#endif /* defined(__MMI_IMAGE_VIEWER_EX__) && defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__) */

#endif /* #ifndef _IMAGE_VIEWER_EX_SLIDING_BAR_H_ */
