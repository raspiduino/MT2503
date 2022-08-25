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
 *  EngineerModeMMIFramework.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for engineer mode MMI framework ralated items, includes:
 *       - TouchScreen           
 *       - CASCADE Menu        
 *       - CSB(Category screen browser)
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
//#include "MMI_include.h"
#include "MMI_features.h"

#ifdef __MMI_ENGINEER_MODE__ 

#include "CommonScreens.h"

#if defined (__MMI_CSB_BROWSER__)
#include "CatScreenBrowserDefs.h"
#include "CatScreenBrowserProts.h"
#endif

#include "EngineerModeUtil.h"
//#include "FactoryModeDef.h"

#include "EngineerModeMMIFramework.h"
#include "EngineerModeCommUI.h"

#include "mmi_frm_input_gprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "wgui.h"
#include "wgui_touch_screen.h"
#include "gui.h"
#include "wgui_categories.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "wgui_categories_text_viewer.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "GlobalMenuItems.h"
#include "CustMenuRes.h"
#include "wgui_categories_list.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"

#include "mmi_rp_app_engineermode1_def.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/


/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
//extern S8 EMFMUnicodeDisplayBuf[MAX_TEST_STRING_BUF * 2];
//extern U8 EMFMAsciiDisplayBuf[MAX_TEST_STRING_BUF];

#define EM_MISC_TOUCH_SCREEN
/*-----------------------------------------------------------------------------*/
/*--------------------------- Misc -> Touch screen ----------------------------*/
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_MISC_TOUCH_SCREEN__)


#undef EM_PEN_TEST_HANW

#ifdef EM_PEN_TEST_HANW
#include "hw.h"
#endif 

/* Previous point in pen test program */
static mmi_pen_point_struct gEmPenPreviousPoint;

/* Capture pen events by test drawing program */
static BOOL gEmPenTestCapture = MMI_FALSE;

/* Line color */
static color gEmPenLineColor = {0, 0, 0, 100};

/* Stroke test */
#define EM_PEN_STROKE_BUFFER_SIZE 500
static mmi_pen_point_struct *gEmPenStrokeBuffer;

/* Max distance between points of successive pen move event */
static S16 gEmPenMaxDisplacementX = 0;
static S16 gEmPenMaxDisplacementY = 0;

static mmi_pen_handwriting_area_struct gEmPenStrokeArea;

#ifdef EM_PEN_TEST_HANW
/* Single line input box for display candidates for hand writing */
static single_line_input_box touchCandidateArea;
extern unsigned char bufRam[12 * 1024];
extern const unsigned char hand_writing_data[];
#endif /* EM_PEN_TEST_HANW */ 


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
static void pen_down_hdlr(mmi_pen_point_struct pos);
static void pen_long_tap_hdlr(mmi_pen_point_struct pos);
static void pen_abort_hdlr(mmi_pen_point_struct pos);
static void pen_repeat_hdlr(mmi_pen_point_struct pos);
static void pen_move_hdlr(mmi_pen_point_struct pos);
static void pen_up_hdlr(mmi_pen_point_struct pos);
static void stroke_down_hdlr(mmi_pen_point_struct pos);
static void stroke_move_hdlr(mmi_pen_point_struct pos);
static void stroke_up_hdlr(mmi_pen_point_struct pos);
static void stroke_up_timer_hdlr(void);
static void show_border(void);
static void mmi_em_misc_ts_pen_event_test_exit(void);

/*****************************************************************************
 * FUNCTION
 *  pen_down_hdlr
 * DESCRIPTION
 *  pen down  handler of touch screen test screen
 * PARAMETERS
 *  pos     :[IN]  coordinate of point        
 * RETURNS
 *  void
 *****************************************************************************/
static void pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 test_x1 = (S16) MMI_content_x;
    S16 test_x2 = (S16) (MMI_content_x + MMI_content_width - 1);
    S16 test_y1 = (S16) MMI_content_y;
    S16 test_y2 = (S16) (MMI_content_y + MMI_content_height - 1);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pos.x < test_x1 || pos.x > test_x2 || pos.y < test_y1 || pos.y > test_y2)
    {
        gEmPenPreviousPoint.x = -1;
        gEmPenPreviousPoint.y = -1;
        wgui_general_pen_down_hdlr(pos);
        gEmPenTestCapture = MMI_FALSE;
    }
    else
    {
        gEmPenPreviousPoint.x = pos.x;
        gEmPenPreviousPoint.y = pos.y;
        gEmPenTestCapture = MMI_TRUE;
        gEmPenLineColor = gui_color(0, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  pen_long_tap_hdlr
 * DESCRIPTION
 *  pen long tap handler of touch screen test
 * PARAMETERS
 *  pos      :[IN]   coordinate of point      
 * RETURNS
 *  void
 *****************************************************************************/
static void pen_long_tap_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gEmPenTestCapture)
    {
        wgui_general_pen_long_tap_hdlr(pos);
    }
    else
    {
        gEmPenLineColor = gui_color(255, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  pen_abort_hdlr
 * DESCRIPTION
 *  pen abort handler of touch screen test screen
 * PARAMETERS
 *  pos       :[IN]  coordinate of point   
 * RETURNS
 *  void
 *****************************************************************************/
static void pen_abort_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gEmPenTestCapture)
    {
        wgui_general_pen_abort_hdlr(pos);
    }
}


/*****************************************************************************
 * FUNCTION
 *  pen_repeat_hdlr
 * DESCRIPTION
 *  pen repeat handler of touch screen test screen
 * PARAMETERS
 *  pos      :[IN]  coordinate of point       
 * RETURNS
 *  void
 *****************************************************************************/
static void pen_repeat_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gEmPenTestCapture)
    {
        wgui_general_pen_repeat_hdlr(pos);
    }
    else
    {
        gEmPenLineColor = gui_color(19, 7, 248);
    }
}


/*****************************************************************************
 * FUNCTION
 *  pen_move_hdlr
 * DESCRIPTION
 *  pen move handler of touch screen test screen
 * PARAMETERS
 *  pos     :[IN]   coordinate of point      
 * RETURNS
 *  void
 *****************************************************************************/
static void pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 test_x1 = MMI_content_x;
    S16 test_x2 = MMI_content_x + MMI_content_width - 1;
    S16 test_y1 = MMI_content_y;
    S16 test_y2 = MMI_content_y + MMI_content_height - 1;
    S16 disp_x, disp_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gEmPenTestCapture)
    {
        wgui_general_pen_move_hdlr(pos);
        return;
    }

    if (pos.x < test_x1)
    {
        pos.x = test_x1;
    }
    if (pos.x > test_x2)
    {
        pos.x = test_x2;
    }
    if (pos.y < test_y1)
    {
        pos.y = test_y1;
    }
    if (pos.y > test_y2)
    {
        pos.y = test_y2;
    }
    gui_lock_double_buffer();
    gui_push_clip();
    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
    gui_line(gEmPenPreviousPoint.x, gEmPenPreviousPoint.y, pos.x, pos.y, gEmPenLineColor);

    disp_x = PEN_ABS(pos.x, gEmPenPreviousPoint.x);
    disp_y = PEN_ABS(pos.y, gEmPenPreviousPoint.y);
    if (disp_x > gEmPenMaxDisplacementX)
    {
        gEmPenMaxDisplacementX = disp_x;
    }
    if (disp_y > gEmPenMaxDisplacementY)
    {
        gEmPenMaxDisplacementY = disp_y;
    }

    gui_pop_clip();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        PEN_MIN(gEmPenPreviousPoint.x, pos.x),
        PEN_MIN(gEmPenPreviousPoint.y, pos.y),
        PEN_MAX(gEmPenPreviousPoint.x, pos.x),
        PEN_MAX(gEmPenPreviousPoint.y, pos.y));

    gEmPenPreviousPoint.x = pos.x;
    gEmPenPreviousPoint.y = pos.y;
}


/*****************************************************************************
 * FUNCTION
 *  pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gEmPenTestCapture)
    {
        wgui_general_pen_up_hdlr(pos);
    }
    else
    {
        gui_lock_double_buffer();

        pen_move_hdlr(pos);

        gui_line(pos.x - 2, pos.y - 2, pos.x + 2, pos.y + 2, gEmPenLineColor);
        gui_line(pos.x - 2, pos.y + 2, pos.x + 2, pos.y - 2, gEmPenLineColor);
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(pos.x - 2, pos.y - 2, pos.x + 2, pos.y + 2);
        gEmPenPreviousPoint.x = -1;
        gEmPenPreviousPoint.y = -1;
        gEmPenLineColor = gui_color(0, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  stroke_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void stroke_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gEmPenPreviousPoint.x = pos.x;
    gEmPenPreviousPoint.y = pos.y;
    gEmPenLineColor = gui_color(0, 255, 0);
}


/*****************************************************************************
 * FUNCTION
 *  stroke_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void stroke_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_push_clip();
    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
    gui_line(gEmPenPreviousPoint.x, gEmPenPreviousPoint.y, pos.x, pos.y, gEmPenLineColor);
    gui_line(gEmPenPreviousPoint.x + 1, gEmPenPreviousPoint.y, pos.x + 1, pos.y, gEmPenLineColor);
    gui_line(gEmPenPreviousPoint.x, gEmPenPreviousPoint.y + 1, pos.x, pos.y + 1, gEmPenLineColor);
    gui_line(gEmPenPreviousPoint.x - 1, gEmPenPreviousPoint.y, pos.x - 1, pos.y, gEmPenLineColor);
    gui_line(gEmPenPreviousPoint.x, gEmPenPreviousPoint.y - 1, pos.x, pos.y - 1, gEmPenLineColor);

    gui_pop_clip();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        PEN_MIN(gEmPenPreviousPoint.x, pos.x) - 1,
        PEN_MIN(gEmPenPreviousPoint.y, pos.y) - 1,
        PEN_MAX(gEmPenPreviousPoint.x, pos.x) + 1,
        PEN_MAX(gEmPenPreviousPoint.y, pos.y) + 1);

    gEmPenPreviousPoint.x = pos.x;
    gEmPenPreviousPoint.y = pos.y;
}


/*****************************************************************************
 * FUNCTION
 *  stroke_up_hdlr
 * DESCRIPTION
 *  stroke up handler of touch screen test screen
 * PARAMETERS
 *  pos     :[IN] point of pen        
 * RETURNS
 *  void
 *****************************************************************************/
static void stroke_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stroke_move_hdlr(pos);
    gEmPenPreviousPoint.x = -1;
    gEmPenPreviousPoint.y = -1;
    gui_cancel_timer(stroke_up_timer_hdlr);
    gui_start_timer(1000, stroke_up_timer_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  stroke_up_timer_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void stroke_up_timer_hdlr(void)
{
#ifdef EM_PEN_TEST_HANW
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL has_unfinished_stroke;
    U16 *psBufferTouch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_peek_stroke_state(&has_unfinished_stroke);
    if (!has_unfinished_stroke)
    {
        int num = 0, i = 0;
        char szResult[40];
        UI_character_type curCh;

        mmi_pen_end_strokes_of_character();

        psBufferTouch = (U16*) OslMalloc((10 + 2) * sizeof(U16));
        gui_create_single_line_input_box_use_buffer(
            &touchCandidateArea,
            MMI_multitap_x,
            MMI_multitap_y - 2, /* +1, */
            MMI_multitap_width,
            MMI_multitap_height,
            psBufferTouch,
            ((10 + 1) * sizeof(U16)));
        touchCandidateArea.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_SCROLLING;
        touchCandidateArea.flags |= UI_SINGLE_LINE_INPUT_BOX_CHARACTER_HIGHLIGHT;

        HWSetDictionary((DWORD) bufRam, (DWORD) hand_writing_data);
        gui_single_line_input_box_delete_all(&touchCandidateArea);

        num = HWRecognize((U16*) gEmPenStrokeBuffer, szResult, 5, ALC_CHINESE_COMMON);
        for (; i < num * 2; i += 2)
        {
            U16 c1 = szResult[i];
            U16 c2 = szResult[i + 1];

            curCh = c1 | (c2 << 8);
            gui_single_line_input_box_insert_character(&touchCandidateArea, (UI_character_type) curCh);
        }
        gui_single_line_input_box_goto_first_character(&touchCandidateArea);
        gui_single_line_input_box_next(&touchCandidateArea);
        touchCandidateArea.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
        touchCandidateArea.flags |= UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR;
        gui_lock_double_buffer();
        gui_show_single_line_input_box(&touchCandidateArea);
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
        mmi_pen_begin_strokes_of_character();

        OslMfree(psBufferTouch);
    }
#else /* EM_PEN_TEST_HANW */ 
    MMI_BOOL has_unfinished_stroke;

    mmi_pen_peek_stroke_state(&has_unfinished_stroke);
    if (!has_unfinished_stroke)
    {
        mmi_pen_end_strokes_of_character();
        mmi_pen_begin_strokes_of_character();
    }
#endif /* EM_PEN_TEST_HANW */ 
}


/*****************************************************************************
 * FUNCTION
 *  EmPenTestShowBorder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void show_border(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_draw_rectangle(
        gEmPenStrokeArea.x1,
        gEmPenStrokeArea.y1,
        gEmPenStrokeArea.x2,
        gEmPenStrokeArea.y2,
        gui_color(128, 128, 128));
}

/*****************************************************************************
 * FUNCTION
 *  ts_test_exit
 * DESCRIPTION
 *  exit function of the touch screen test screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ts_test_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_stop_capture_strokes();
    OslMfree(gEmPenStrokeBuffer);
    gEmPenStrokeBuffer = NULL;
    gdi_lcd_set_te_ctrl(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  ts_test_enter
 * DESCRIPTION
 *  touch screen test screen's enter function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ts_test_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    mmi_pen_handwriting_area_struct ext_stroke;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_FALSE == mmi_frm_scrn_enter(
            GRP_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT,
            SCR_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT, 
            ts_test_exit, 
            ts_test_enter,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }
    gdi_lcd_set_te_ctrl(KAL_FALSE);
    ext_stroke.x1 = 0;
    ext_stroke.y1 = 0;
    ext_stroke.x2 = UI_device_width - 1;
    ext_stroke.y2 = UI_device_height - 1;
    gEmPenPreviousPoint.x = -1;
    gEmPenPreviousPoint.y = -1;
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT, SCR_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT);
    gui_lock_double_buffer();
    ShowCategory400Screen(
        STR_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        guiBuffer);

    gEmPenStrokeArea.x1 = MMI_content_x + (MMI_content_width >> 3);
    gEmPenStrokeArea.x2 = MMI_content_x + MMI_content_width - (MMI_content_width >> 3);
    gEmPenStrokeArea.y1 = MMI_content_y + (MMI_content_height >> 3);
    gEmPenStrokeArea.y2 = MMI_content_y + MMI_content_height - (MMI_content_height >> 3);

    show_border();

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

    wgui_register_pen_down_handler(pen_down_hdlr);
    wgui_register_pen_move_handler(pen_move_hdlr);
    wgui_register_pen_up_handler(pen_up_hdlr);
    wgui_register_pen_repeat_handler(pen_repeat_hdlr);
    wgui_register_pen_long_tap_handler(pen_long_tap_hdlr);
    wgui_register_pen_abort_handler(pen_abort_hdlr);

    gEmPenStrokeBuffer = (mmi_pen_point_struct*) OslMalloc(sizeof(mmi_pen_point_struct) * EM_PEN_STROKE_BUFFER_SIZE);
    mmi_pen_start_capture_strokes(EM_PEN_STROKE_BUFFER_SIZE, gEmPenStrokeBuffer, 1, &gEmPenStrokeArea, &ext_stroke);
    mmi_pen_register_stroke_down_handler(stroke_down_hdlr);
    mmi_pen_register_stroke_move_handler(stroke_move_hdlr);
    mmi_pen_register_stroke_up_handler(stroke_up_hdlr);
    mmi_pen_begin_strokes_of_character();

#ifdef __COSMOS_MMI_PACKAGE__
    SetKeyHandler(mmi_em_misc_ts_pen_event_test_exit, KEY_BACK, KEY_EVENT_UP);
#else
    SetRightSoftkeyFunction(mmi_em_misc_ts_pen_event_test_exit, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  ts_test_proc
 * DESCRIPTION
 *  This function is used to handle event of touch screen test module
 * PARAMETERS
 *  evt    : [IN] event that will be handled in proc
 * RETURNS
 *  mmi_ret value to indicate the event handling results
 *****************************************************************************/
static mmi_ret ts_test_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;    
}

static void mmi_em_misc_ts_pen_event_test_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_ts_pen_event_test_launch
 * DESCRIPTION
 *  This function is used to launch touch screen test in engineer mode 
 * PARAMETERS
 *  parent_id    : [IN] parent group id
 * RETURNS
 *  group id of touch screen test module
 *****************************************************************************/
MMI_ID mmi_em_misc_ts_pen_event_test_launch(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(parent_id, GRP_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT, ts_test_proc, NULL);
    mmi_frm_group_enter(GRP_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_first_enter(GRP_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT, SCR_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT, ts_test_enter, NULL);
    return GRP_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT;
}

#endif /* #if defined(__MMI_EM_MISC_TOUCH_SCREEN__) */ 

#define EM_MISC_CASCADE_MENU
/*-----------------------------------------------------------------------------*/
/*-------------------------------- Cascade menu -------------------------------*/
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_MISC_CASCADE_MENU__)
/*****************************************************************************
 * FUNCTION
 *  HighlightCascadeMenuTest
 * DESCRIPTION
 *  Cascade menu test highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCascadeMenuTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_common_set_left_softkey(MMI_TRUE);
    SetLeftSoftkeyFunction(mmi_em_entry_cascade_menu_test, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_entry_cascade_menu_test
 * DESCRIPTION
 *  Cascade menu test entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_entry_cascade_menu_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cascade_menu_test();    
}
#endif /* #if defined(__MMI_EM_MISC_CASCADE_MENU__)) */

#define EM_CSB_BROWSER
/*-----------------------------------------------------------------------------*/
/*------------------------- CSB(Category screen browser)  ---------------------*/
/*-----------------------------------------------------------------------------*/
#if defined (__MMI_CSB_BROWSER__)
/*****************************************************************************
 * FUNCTION
 *  HighlightCSB
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCSB(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(PreEntryCSBMainMenu, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif	/* __MMI_CSB_BROWSER__ */



#endif /* __MMI_ENGINEER_MODE__ */

