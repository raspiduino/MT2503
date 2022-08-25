#ifdef __MMI_TOUCH_SCREEN__
#define AVK_PLUTO_TOUCH_STROKE_DN_MASK 0x0001
#define AVK_PLUTO_TOUCH_STROKE_MV_MASK 0x0002
#define AVK_PLUTO_TOUCH_STROKE_UP_MASK 0x0004

#define AVK_PLUTO_TOUCH_002_PASS_MARKER 0x00F0
#define AVK_PLUTO_TOUCH_002_PASS_MASK 0x0007

#define AVK_PLUTO_TOUCH_STROKE_BUF_SIZE 500
static mmi_pen_handwriting_area_struct g_avk_pluto_touch_area;
static mmi_pen_point_struct *g_avk_pluto_touch_buffer = NULL;
static U32 g_avk_pluto_touch_count = 0;

void avk_pluto_touch_001_entry();
void avk_pluto_touch_002_entry();
void avk_pluto_touch_002_exit(void);

AVK_MANUAL_CASE(AVK_PLUTO_TOUCH_MANU_1,AVK_PLUTO_TOUCH)
{
    avk_pluto_touch_001_entry();
}

AVK_MANUAL_CASE(AVK_PLUTO_TOUCH_MANU_2,AVK_PLUTO_TOUCH)
{
    avk_pluto_touch_002_entry();
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_touch_pen_hdlr
 * DESCRIPTION
 *  Simple program to test touch screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_touch_pen_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_polygon_area_struct area;
    mmi_pen_point_struct points[4];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    memset(points, 0, sizeof(points));
    points[2].x = points[1].x = UI_device_width;
    points[2].y = points[3].y = UI_device_height;

    AVK_LOG_NORMAL(mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_2, MMI_PEN_SAMPLING_PERIOD_2));
    AVK_LOG_NORMAL(mmi_pen_config_move_offset(
        MMI_PEN_SKIP_MOVE_OFFSET,
        MMI_PEN_SKIP_STROKE_MOVE_OFFSET,
        MMI_PEN_SKIP_LONGTAP_OFFSET,
        MMI_PEN_SKIP_STROKE_LONGTAP_OFFSET));
    area.points = points;
    area.num = 4;
    AVK_LOG(mmi_pen_check_inside_polygon(&area, pos));
    
#endif /* __MMI_TOUCH_SCREEN__ */ 
    mmi_frm_scrn_close_active_id();
    AVK_CASE_RESULT(AVK_PASS);
    AVK_ASYN_DONE(); 
}

#endif

void avk_pluto_touch_001_entry()
{
#ifdef __MMI_TOUCH_SCREEN__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;
    U16 text_buffer_1[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(GRP_ID_ROOT,
        AVK_SCR_ID_1,
        NULL,
        avk_pluto_touch_001_entry,
        MMI_FRM_FULL_SCRN);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    kal_wstrcpy(text_buffer_1,(const WCHAR *)L"Touch the screen and wait for LSK to appear");
    ShowCategory78Screen(
        0,
        0,
        0,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8)text_buffer_1,
        2*kal_wstrlen(text_buffer_1),
        gui_buffer);

    AVK_LOG_EX(mmi_pen_get_pen_handler(MMI_PEN_EVENT_UP));    
    AVK_LOG_NORMAL(mmi_pen_register_down_handler(avk_pluto_touch_pen_hdlr));
    AVK_LOG_NORMAL(mmi_pen_register_long_tap_handler(avk_pluto_touch_pen_hdlr));
    AVK_LOG_NORMAL(mmi_pen_register_move_handler(avk_pluto_touch_pen_hdlr));
    AVK_LOG_NORMAL(mmi_pen_register_repeat_handler(avk_pluto_touch_pen_hdlr));
    AVK_SET_FAILKEY(NULL);
    ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
#else 
   	AVK_LOG_FUN_UNSUPPORTED(mmi_pen_register_down_handler);
    AVK_LOG_FUN_UNSUPPORTED(mmi_pen_register_long_tap_handler);
    AVK_LOG_FUN_UNSUPPORTED(mmi_pen_register_move_handler);
    AVK_LOG_FUN_UNSUPPORTED(mmi_pen_register_repeat_handler);
#endif
    
}

#ifdef __MMI_TOUCH_SCREEN__

void avk_pluto_touch_002_timer_cb_2(void);
void avk_pluto_touch_002_timer_cb(void);

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_touch_stroke_dn_hdlr
 * DESCRIPTION
 *  Simple program to test touch screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_touch_stroke_dn_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_avk_pluto_touch_count |= AVK_PLUTO_TOUCH_STROKE_DN_MASK;
    
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_touch_stroke_mv_hdlr
 * DESCRIPTION
 *  Simple program to test touch screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_touch_stroke_mv_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_avk_pluto_touch_count |= AVK_PLUTO_TOUCH_STROKE_MV_MASK;
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_touch_stroke_up_hdlr
 * DESCRIPTION
 *  Simple program to test touch screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_touch_stroke_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_avk_pluto_touch_count |= AVK_PLUTO_TOUCH_STROKE_UP_MASK;
    if (g_avk_pluto_touch_count & AVK_PLUTO_TOUCH_002_PASS_MARKER)
    {
        avk_pluto_touch_002_timer_cb_2();
    }
    else
    {
        avk_pluto_touch_002_timer_cb();
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_touch_pen_dn_hdlr
 * DESCRIPTION
 *  Simple program to test touch screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_touch_pen_dn_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_avk_pluto_touch_count & AVK_PLUTO_TOUCH_002_PASS_MARKER)
    {
        mmi_pen_disable_stroke_event();

    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_touch_pen_up_hdlr
 * DESCRIPTION
 *  Simple program to test touch screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_touch_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_enable_stroke_event();
    mmi_pen_register_down_handler(mmi_pen_dummy_hdlr);
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_touch_002_timer_cb_2
 * DESCRIPTION
 *  Simple program to test touch screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_touch_002_timer_cb_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(0x2345);
    mmi_pen_end_strokes_of_character();
    if (g_avk_pluto_touch_count & AVK_PLUTO_TOUCH_002_PASS_MASK)
    {
        AVK_CASE_RESULT(AVK_PASS);
#ifdef __COSMOS_MMI_PACKAGE__
        mmi_frm_scrn_close_active_id();
#endif 
        
    }
    else
    {
        AVK_CASE_RESULT(AVK_FAIL);
    }
    AVK_ASYN_DONE();
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_touch_002_next
 * DESCRIPTION
 *  Simple program to test touch screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_touch_002_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_handwriting_area_struct ext_stroke;
    U16 text_buffer_1[128];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ext_stroke.x1 = 0;
    ext_stroke.y1 = 0;
    ext_stroke.x2 = UI_device_width - 1;
    ext_stroke.y2 = UI_device_height - 1;
    g_avk_pluto_touch_count |= AVK_PLUTO_TOUCH_002_PASS_MARKER;
    mmi_frm_scrn_close_active_id();
    kal_wstrcpy(text_buffer_1,(WCHAR*)L"Again (twice this time)...(LSK should appear)");
    
    mmi_frm_scrn_enter(GRP_ID_ROOT,
        AVK_SCR_ID_2,
        avk_pluto_touch_002_exit,
        avk_pluto_touch_002_next,
        MMI_FRM_FULL_SCRN);

    gui_lock_double_buffer();
    ShowCategory78Screen(
        0,
        0,
        0,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8)text_buffer_1,
        sizeof(text_buffer_1),
        NULL);
	g_avk_pluto_touch_buffer = (mmi_pen_point_struct*) AVK_MALLOC(sizeof(mmi_pen_point_struct) * AVK_PLUTO_TOUCH_STROKE_BUF_SIZE);
    mmi_pen_start_capture_strokes(
        AVK_PLUTO_TOUCH_STROKE_BUF_SIZE,
        g_avk_pluto_touch_buffer,
        1,
        &g_avk_pluto_touch_area,
        &ext_stroke);
    
        
    g_avk_pluto_touch_area.x1 = MMI_content_x + (MMI_content_width >> 3);
    g_avk_pluto_touch_area.x2 = MMI_content_x + MMI_content_width - (MMI_content_width >> 3);
    g_avk_pluto_touch_area.y1 = MMI_content_y + (MMI_content_height >> 1);
    g_avk_pluto_touch_area.y2 = MMI_content_y + MMI_content_height - (MMI_content_height >> 3);
    gui_draw_rectangle(
        g_avk_pluto_touch_area.x1,
        g_avk_pluto_touch_area.y1,
        g_avk_pluto_touch_area.x2,
        g_avk_pluto_touch_area.y2,
        gui_color(128,128,128));
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
    
    AVK_LOG_NORMAL(mmi_pen_register_stroke_down_handler(avk_pluto_touch_stroke_dn_hdlr));
    AVK_LOG_NORMAL(mmi_pen_register_stroke_move_handler(avk_pluto_touch_stroke_mv_hdlr));
    AVK_LOG_NORMAL(mmi_pen_register_stroke_up_handler(avk_pluto_touch_stroke_up_hdlr));
    AVK_LOG_NORMAL(mmi_pen_register_down_handler(avk_pluto_touch_pen_dn_hdlr));
    AVK_LOG_NORMAL(mmi_pen_register_up_handler(avk_pluto_touch_pen_up_hdlr));
    AVK_LOG_NORMAL(mmi_pen_change_handwriting_area(
        1,
        &g_avk_pluto_touch_area,
        &ext_stroke));
        
    AVK_LOG_NORMAL(mmi_pen_begin_strokes_of_character());
    
//    StartTimer(0x2345, 5000, avk_pluto_touch_002_timer_cb_2);
    AVK_SET_FAILKEY(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_touch_002_timer_cb
 * DESCRIPTION
 *  Simple program to test touch screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_touch_002_timer_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(0x2345);
    AVK_LOG_NORMAL(mmi_pen_end_strokes_of_character());

    if (g_avk_pluto_touch_count & AVK_PLUTO_TOUCH_002_PASS_MASK)
    {
        avk_pluto_touch_002_next();
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_touch_002_exit
 * DESCRIPTION
 *  Simple program to test touch screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_touch_002_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG_NORMAL(mmi_pen_stop_capture_strokes());
    AVK_FREE(g_avk_pluto_touch_buffer);
    g_avk_pluto_touch_buffer = NULL;
}

#endif
/*****************************************************************************
 * FUNCTION
 *  avk_pluto_touch_002_entry
 * DESCRIPTION
 *  Simple program to test touch screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_touch_002_entry()

{
#ifdef __MMI_TOUCH_SCREEN__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    mmi_pen_handwriting_area_struct ext_stroke;
    wchar_t text_buffer_1[] = L"Draw a stroke and remove pen to test in 5 seconds";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ext_stroke.x1 = 0;
    ext_stroke.y1 = 0;
    ext_stroke.x2 = UI_device_width - 1;
    ext_stroke.y2 = UI_device_height - 1;
    g_avk_pluto_touch_count = 0;
    mmi_frm_scrn_enter(GRP_ID_ROOT,
        AVK_SCR_ID_1,
        avk_pluto_touch_002_exit,
        avk_pluto_touch_002_entry,
        MMI_FRM_FULL_SCRN);
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    gui_lock_double_buffer();
    ShowCategory78Screen(
        0,
        0,
        0,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8)text_buffer_1,
        sizeof(text_buffer_1),
        guiBuffer);
    AVK_SET_FAILKEY(NULL);
    
    g_avk_pluto_touch_area.x1 = MMI_content_x + (MMI_content_width >> 3);
    g_avk_pluto_touch_area.x2 = MMI_content_x + MMI_content_width - (MMI_content_width >> 3);
    g_avk_pluto_touch_area.y1 = MMI_content_y + (MMI_content_height >> 2);
    g_avk_pluto_touch_area.y2 = MMI_content_y + MMI_content_height - (MMI_content_height >> 3);

    gui_draw_rectangle(
        g_avk_pluto_touch_area.x1,
        g_avk_pluto_touch_area.y1,
        g_avk_pluto_touch_area.x2,
        g_avk_pluto_touch_area.y2,
        gui_color(128,128,128));

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
    g_avk_pluto_touch_buffer = (mmi_pen_point_struct*) AVK_MALLOC(sizeof(mmi_pen_point_struct) * AVK_PLUTO_TOUCH_STROKE_BUF_SIZE);
    AVK_LOG_NORMAL(mmi_pen_start_capture_strokes(
        AVK_PLUTO_TOUCH_STROKE_BUF_SIZE,
        g_avk_pluto_touch_buffer,
        1,
        &g_avk_pluto_touch_area,
        &ext_stroke));
        
    AVK_LOG_NORMAL(mmi_pen_register_stroke_down_handler(avk_pluto_touch_stroke_dn_hdlr));
    AVK_LOG_NORMAL(mmi_pen_register_stroke_move_handler(avk_pluto_touch_stroke_mv_hdlr));
    AVK_LOG_NORMAL(mmi_pen_register_stroke_up_handler(avk_pluto_touch_stroke_up_hdlr));
    AVK_LOG_NORMAL(mmi_pen_begin_strokes_of_character());
    
#else 
	AVK_LOG_FUN_UNSUPPORTED(mmi_pen_start_capture_strokes);
    AVK_LOG_FUN_UNSUPPORTED(mmi_pen_register_stroke_down_handler);
    AVK_LOG_FUN_UNSUPPORTED(mmi_pen_register_stroke_move_handler);
    AVK_LOG_FUN_UNSUPPORTED(mmi_pen_register_stroke_up_handler);
    AVK_LOG_FUN_UNSUPPORTED(mmi_pen_begin_strokes_of_character);
#endif

}
