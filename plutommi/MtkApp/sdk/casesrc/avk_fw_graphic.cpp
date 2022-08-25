extern "C"
{
#include "gdi_include.h"    
}

#define VS_MAX_LAYER_NUM 3
#define VS_LAYER_BUFFER_SIZE ((LCD_WIDTH*LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)

typedef struct
{
    U16 layer_buffer2[VS_LAYER_BUFFER_SIZE];
    gdi_handle handle[3];
    gdi_handle layerhandle;
    gdi_handle basehandle;
    gdi_handle frame_layer_handle;
    PU16 screen_asmp;
    PU8 screen_asmp_framebuffer;
    gdi_image_cache_bmp_struct backup_bitmap;
    gdi_handle anim_handle;
    mdi_handle aud_handle;
    U32 delay_t;
    MMI_BOOL is_hilight;
    void (*entry_app_callback) (void);
    void *app_mem_pool;
    void *app_mem_pool_1;
    void *app_mem_pool_framebuffer;  
} avk_fw_graphic_ctx_struct;

void vs_fw_gdi_exit(void);
static void vs_fw_gdi_003_img_redraw(void);
static void vs_fw_gdi_003_img_nbdraw(void);
void vs_fw_gdi_005_layer_test1(void);
void vs_fw_gdi_005_layer_test2(void);
void vs_fw_gdi_006_lcd_pass(void);
/* framebuffer related test */
static void vs_fw_gdi_011_fb_related_test1_pass(void);
static void vs_fw_gdi_011_fb_related_test1_fail(void);
static void vs_fw_gdi_011_fb_related_callback(void);
static void vs_fw_gdi_011_fb_related_test1_exit(void);
static void vs_fw_gdi_011_fb_related_test2_pass(void);
static void vs_fw_gdi_011_fb_related_test2_fail(void);

static void vs_fw_gdi_011_fb_related_test2_pre(void);
static void vs_fw_gdi_011_fb_related_test2(void);
static void vs_fw_gdi_011_fb_related_test2_exit(void);

static avk_fw_graphic_ctx_struct* g_avk_fw_graphic_ctx;

AVK_MANUAL_CASE(AVK_FW_GRAPHIC_INIT,AVK_FW_GRAPHIC)
{
    g_avk_fw_graphic_ctx = (avk_fw_graphic_ctx_struct*)AVK_MALLOC(sizeof(avk_fw_graphic_ctx_struct));
    memset(g_avk_fw_graphic_ctx,0,sizeof(avk_fw_graphic_ctx_struct));
    AVK_CASE_RESULT(g_avk_fw_graphic_ctx);
    AVK_ASYN_DONE();
}

/*****************************************************************************
 * FUNCTION
 *  gui_callback_rotate_timer
 * DESCRIPTION
 *  show image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_callback_rotate_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 layer_rotate;
    static U8 num = 4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->handle[1]);
    layer_rotate = gdi_layer_get_rotate();
    gdi_layer_set_rotate((U8)(layer_rotate + GDI_LAYER_ROTATE_90));
    gdi_layer_pop_and_restore_active();
    gdi_layer_set_blt_layer(
        g_avk_fw_graphic_ctx->basehandle,
        g_avk_fw_graphic_ctx->handle[0],
        g_avk_fw_graphic_ctx->handle[1],
        g_avk_fw_graphic_ctx->handle[2]);
    gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);
    if (num > 0)
    {
        gui_start_timer(500, gui_callback_rotate_timer);
        num--;
    }
    else
    {
        num = 4;
    }
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_memory_002_ap_stop1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_memory_002_ap_stop1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   	if(g_avk_fw_graphic_ctx->app_mem_pool_1!= NULL)
	{
		applib_mem_ap_free(g_avk_fw_graphic_ctx->app_mem_pool_1);
        applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VS_TEST1, KAL_TRUE);
        g_avk_fw_graphic_ctx->app_mem_pool_1 = NULL;
	}
   
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_001_draw_error
 * DESCRIPTION
 *  show image
 * PARAMETERS
 *  result      [IN]        
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_001_draw_error(GDI_RESULT result, GDI_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < 0)
    {
      	mmi_popup_display_simple((WCHAR*)L"gdi_image error", MMI_EVENT_FAILURE, GRP_ID_AVK, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_001_after_blt
 * DESCRIPTION
 *  show image
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_001_after_blt(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(80, 150, 200, 180, GDI_COLOR_RED);
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_001_before_blt
 * DESCRIPTION
 *  show image
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_001_before_blt(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->basehandle);
    AVK_LOG_NORMAL(gdi_layer_clear_background(GDI_COLOR_RED));
    AVK_LOG_NORMAL(gdi_layer_pop_and_restore_active());
    gdi_layer_set_blt_layer(g_avk_fw_graphic_ctx->basehandle, g_avk_fw_graphic_ctx->layerhandle, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_001_show_time
 * DESCRIPTION
 *  show image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_001_show_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[10];
    U16 temp_2[5];
    U16 info[30];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(temp, "%d", g_avk_fw_graphic_ctx->delay_t);
    mmi_asc_to_wcs(temp_2, temp);
    mmi_wcscpy(info, (WCHAR*)L"Animation delay time is :");
    mmi_wcscat(info, temp_2);
    mmi_popup_display_simple(info, MMI_EVENT_SUCCESS, GRP_ID_AVK, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_001_show_img
 * DESCRIPTION
 *  show image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_001_show_img(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 size = 0;
    U8 *ptr;
    S32 f_count;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, vs_fw_gdi_exit, vs_fw_gdi_001_show_img, MMI_FRM_FULL_SCRN);
    if(ret == MMI_FALSE)
        return;    
    /* stop lcd sleep */
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
//    VibratorOn();

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    
    AVK_LOG_EX(GDI_SUCCEED == gdi_layer_get_base_handle(&g_avk_fw_graphic_ctx->basehandle));    
    ptr = gdi_image_get_buf_ptr_from_id(IMG_ID_AVK_DEVAPP_1);
    AVK_LOG_FUN(gdi_image_get_buf_ptr_from_id,ptr);
    AVK_LOG(size = gdi_image_get_buf_len((PU8) GetImage(IMG_ID_AVK_DEVAPP_1)));
    AVK_LOG_EX(GDI_SUCCEED == gdi_layer_create(0, 0, LCD_WIDTH, LCD_HEIGHT, &g_avk_fw_graphic_ctx->layerhandle));
    
    ASSERT(g_avk_fw_graphic_ctx->layerhandle != GDI_LAYER_EMPTY_HANDLE);
    AVK_LOG_EX(GDI_SUCCEED == gdi_anim_set_blt_before_callback(vs_fw_gdi_001_before_blt));
    AVK_LOG_EX(GDI_SUCCEED == gdi_anim_set_blt_after_callback(vs_fw_gdi_001_after_blt));

    AVK_LOG_NORMAL(gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->layerhandle));
    AVK_LOG_NORMAL(gdi_layer_clear_background(GDI_COLOR_WHITE));
	AVK_LOG_NORMAL(gdi_anim_set_disable_blt());
    if (guiBuffer != NULL)
    {
        AVK_LOG(gdi_layer_set_opacity(FALSE, 0));
        AVK_DRAW_SOFTKEY(KEY_LSK,AVK_STR_PASS);
        AVK_DRAW_SOFTKEY(KEY_RSK,AVK_STR_FAIL);
        AVK_SET_PASSKEY(NULL);
        AVK_SET_FAILKEY(NULL);
    }
    else
    {
        AVK_DRAW_SOFTKEY(KEY_LSK, STR_GLOBAL_OK);
        AVK_LOG(gdi_layer_set_opacity(TRUE, 50));
        SETLEFTKEY(vs_fw_gdi_001_show_time);
    }

	AVK_LOG(gdi_image_get_frame_count_mem(GDI_IMAGE_TYPE_GIF,ptr,size,&f_count));

    AVK_LOG_NORMAL(gdi_nb_set_done_callback(vs_fw_gdi_001_draw_error));
	gui_set_font(&MMI_medium_font);
	gui_set_text_color(gui_color(200,100, 70));
	if(f_count == 5)
	{	
        AVK_LOG_EX(GDI_SUCCEED == gdi_anim_draw_id(0,AVK_FRAMEWORK_SOFTKEY_HEIGHT + 1,IMG_ID_AVK_DEVAPP_1,&g_avk_fw_graphic_ctx->anim_handle));
		gui_move_text_cursor(0, 190);
	    gui_print_text((WCHAR*)L"Frame count =5 ");
	}

    g_avk_fw_graphic_ctx->delay_t = gdi_anim_get_delay();
    AVK_LOG_NORMAL(gdi_layer_pop_and_restore_active());

    AVK_LOG_NORMAL(gdi_layer_set_blt_layer(g_avk_fw_graphic_ctx->basehandle, g_avk_fw_graphic_ctx->layerhandle, 0, 0));
    AVK_LOG_NORMAL(gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT));

}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_exit
 * DESCRIPTION
 *  make call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_avk_fw_graphic_ctx->layerhandle != GDI_LAYER_EMPTY_HANDLE)
	{
        AVK_LOG(gdi_layer_free(g_avk_fw_graphic_ctx->layerhandle));
        g_avk_fw_graphic_ctx->layerhandle = GDI_LAYER_EMPTY_HANDLE;
	}
    gdi_layer_set_blt_layer(g_avk_fw_graphic_ctx->basehandle, 0, 0, 0);
    if (g_avk_fw_graphic_ctx->backup_bitmap.buf_ptr != NULL)
    {
        applib_mem_screen_free(g_avk_fw_graphic_ctx->backup_bitmap.buf_ptr);
        g_avk_fw_graphic_ctx->backup_bitmap.buf_ptr = NULL;
    }
    gdi_anim_set_blt_before_callback(NULL);
    gdi_anim_set_blt_after_callback(NULL);
    srv_backlight_turn_off();
//    VibratorOff();
}

AVK_MANUAL_CASE(AVK_FW_GRAPHIC_SHOW_IMG,AVK_FW_GRAPHIC_INIT)
{
    
    AVK_MANU_SHOW_TIPS(L"1.show translusent page\n2.click OK, show time\n3.click OK, no translusent effect",
        vs_fw_gdi_001_show_img);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_002_draw
 * DESCRIPTION
 *  make call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_002_draw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, vs_fw_gdi_exit, vs_fw_gdi_002_draw, MMI_FRM_FULL_SCRN);
    if(ret == MMI_FALSE)
    return;
    AVK_LOG(gdi_layer_create(0, 0, LCD_WIDTH, LCD_HEIGHT, &g_avk_fw_graphic_ctx->layerhandle));
    ASSERT(g_avk_fw_graphic_ctx->layerhandle != GDI_LAYER_EMPTY_HANDLE);    
    
    AVK_LOG_NORMAL(gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->layerhandle));
    AVK_LOG_NORMAL(gdi_layer_clear_background(GDI_COLOR_WHITE));

	AVK_DRAW_TITLE((WCHAR *)L"GDI Draw");
    AVK_DRAW_SOFTKEY(KEY_LSK,AVK_STR_PASS);
    AVK_DRAW_SOFTKEY(KEY_RSK,AVK_STR_FAIL);

    AVK_LOG_NORMAL(gdi_draw_point(200, 200 + AVK_FRAMEWORK_SOFTKEY_HEIGHT, GDI_COLOR_RED));
    AVK_LOG_NORMAL(gdi_draw_line(0, AVK_FRAMEWORK_SOFTKEY_HEIGHT, 5, 100, GDI_COLOR_GREEN));

    AVK_LOG_NORMAL(gdi_draw_antialiasing_line(10, 20 + AVK_FRAMEWORK_SOFTKEY_HEIGHT, 150, 150, GDI_COLOR_BLUE));
    AVK_LOG_NORMAL(gdi_draw_rect(10, 10 + AVK_FRAMEWORK_SOFTKEY_HEIGHT, 50, 200, GDI_COLOR_RED));
    AVK_LOG_NORMAL(gdi_draw_solid_rect(20, 150 + AVK_FRAMEWORK_SOFTKEY_HEIGHT, 30, 180 + AVK_FRAMEWORK_SOFTKEY_HEIGHT, GDI_COLOR_RED));
    AVK_LOG_NORMAL(gdi_draw_circle(150, 150, 30, GDI_COLOR_BLACK));
    AVK_LOG_NORMAL(gdi_draw_arc(100, 100, 20 + AVK_FRAMEWORK_SOFTKEY_HEIGHT, 30, 90, GDI_COLOR_RED));
    /* gdi_draw_solid_arc(50, 50, 40, 10, 90, GDI_COLOR_GREEN); */
    AVK_LOG_NORMAL(gdi_draw_round_rect(150, 280, 220, 320, GDI_COLOR_RED, GDI_COLOR_GREEN, 3));
    AVK_LOG_NORMAL(gdi_draw_darken_rect(150, 10 + AVK_FRAMEWORK_SOFTKEY_HEIGHT, 180, 40 + AVK_FRAMEWORK_SOFTKEY_HEIGHT, 2));
    AVK_LOG_NORMAL(gdi_effect_alpha_blending_rect(g_avk_fw_graphic_ctx->layerhandle, 110, 130, 150, 160, 100, 100, 210, 7));
    AVK_LOG_NORMAL(gdi_layer_pop_and_restore_active());

    AVK_LOG_MANUAL(gdi_layer_get_base_handle(&g_avk_fw_graphic_ctx->basehandle));
    AVK_LOG_MANUAL(gdi_layer_set_blt_layer(g_avk_fw_graphic_ctx->basehandle, g_avk_fw_graphic_ctx->layerhandle, 0, 0));

    AVK_LOG_MANUAL(gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT));

//    AVK_DRAW_SOFTKEY(KEY_LSK,AVK_STR_PASS);
//    AVK_DRAW_SOFTKEY(KEY_RSK,AVK_STR_FAIL);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}

AVK_MANUAL_CASE(AVK_FW_GRAPHIC_DRAW,AVK_FW_GRAPHIC_INIT)
{
    AVK_MANU_SHOW_TIPS(L"Show many shapes",vs_fw_gdi_002_draw);
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_003_img
 * DESCRIPTION
 *  verify the iamge related API
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_003_img(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 im;
    U16 size = 0;
    U16 image_path[100];
    PU8 ptr = NULL;
    S8 buf[10];
    S32 ret_drv;
    S32 display_x_offset, display_y_offset;
    S32 display_width, display_height;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, vs_fw_gdi_exit, vs_fw_gdi_003_img, MMI_FRM_FULL_SCRN);
    if(ret == MMI_FALSE)
    {
        return;
    }
    
    gdi_layer_create(0, 0, LCD_WIDTH, LCD_HEIGHT, &g_avk_fw_graphic_ctx->layerhandle);
    ASSERT(g_avk_fw_graphic_ctx->layerhandle != GDI_LAYER_EMPTY_HANDLE);
    
    im = (PU8) GetImage(IMG_ID_AVK_DEVAPP_1);

    gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->layerhandle);
    gdi_layer_clear_background(GDI_COLOR_WHITE);

    AVK_DRAW_TITLE((WCHAR*)L"Img");
    AVK_DRAW_SOFTKEY(KEY_LSK, AVK_STR_PASS);
    AVK_DRAW_SOFTKEY(KEY_RSK, AVK_STR_FAIL);

    AVK_LOG_NORMAL(gdi_util_fit_box(
        GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
        30,
        80 + AVK_FRAMEWORK_SOFTKEY_HEIGHT,
        60,
        60,
        &display_x_offset,
        &display_y_offset,
        &display_width,
        &display_height));
        
    AVK_LOG_NORMAL(gdi_image_draw_resized(display_x_offset, display_y_offset, display_width, display_height, im));
    AVK_LOG_NORMAL(gdi_image_draw_frames(100, AVK_FRAMEWORK_SOFTKEY_HEIGHT + 1, im, 2));
    AVK_LOG_NORMAL(gdi_image_draw_resized_frames(0, 50 + AVK_FRAMEWORK_SOFTKEY_HEIGHT, 50, 50 + AVK_FRAMEWORK_SOFTKEY_HEIGHT, im, 3));
    
    AVK_LOG_NORMAL(gdi_image_abm_get_source_layer(&g_avk_fw_graphic_ctx->basehandle));
    AVK_LOG_NORMAL(gdi_image_abm_set_source_layer(g_avk_fw_graphic_ctx->layerhandle));
    AVK_LOG_NORMAL(gdi_image_draw_id(120, 50 + AVK_FRAMEWORK_SOFTKEY_HEIGHT, IMG_ID_AVK_DEVAPP_3));
    AVK_LOG_NORMAL(gdi_image_abm_set_source_layer(g_avk_fw_graphic_ctx->basehandle));

    AVK_LOG_NORMAL(gdi_image_draw_resized_id(50, 100, 40, 40, IMG_ID_AVK_DEVAPP_1));
    AVK_LOG_NORMAL(gdi_image_draw_id_with_transparent_color(180, 50 + AVK_FRAMEWORK_SOFTKEY_HEIGHT, IMG_ID_AVK_DEVAPP_1));

    ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);
    if (ret_drv >= 0)
    {
        sprintf(buf, "%c:\\", (U8) ret_drv);
        mmi_asc_to_wcs((PU16) image_path, buf);
        mmi_wcscat((PU16) image_path, (PU16) L"AVK\\test file\\avk_fw_graphic\\boy.gif");
    }

    AVK_LOG(size = gdi_image_get_buf_len(im));
    AVK_LOG(ptr = gdi_image_get_buf_ptr_from_id(IMG_ID_AVK_DEVAPP_1));
    AVK_LOG_NORMAL(gdi_image_draw_mem(0, 275, ptr, GDI_IMAGE_TYPE_GIF, size));
    AVK_LOG_NORMAL(gdi_image_draw_resized_ext(70, 275, 40, 40, ptr, GDI_IMAGE_TYPE_GIF, size));
    AVK_LOG_NORMAL(gdi_image_draw_mem_frames(120, 275, ptr, GDI_IMAGE_TYPE_GIF, size, 2));
    AVK_LOG_NORMAL(gdi_image_draw_resized_mem_frames(185, 275, 50, 50, ptr, GDI_IMAGE_TYPE_GIF, size, 4));

    {
        S32 temp_width, temp_height;
        gdi_image_get_dimension_file((S8 *)image_path, &temp_width, &temp_height);
        AVK_LOG_NORMAL(gdi_image_draw_file(LCD_WIDTH - temp_width, 150, image_path));
        AVK_LOG_NORMAL(gdi_image_draw_resized_file(60, 150, 30, 30, image_path));
        AVK_LOG_NORMAL(gdi_image_draw_file_frames(LCD_WIDTH - temp_width - 40, 170, image_path, 2));
        AVK_LOG_NORMAL(gdi_image_draw_resized_file_frames(150, 150, 60, 60, image_path, 2));
        AVK_LOG_NORMAL(gdi_image_draw_resized_file_frames(150, 150, 60, 60, image_path, 1));
        AVK_LOG_NORMAL(gdi_image_draw_resized_file_frames(150, 150, 60, 60, image_path, 2));
        AVK_LOG_NORMAL(gdi_image_draw_resized_file_frames(150, 150, 60, 60, image_path, 3));
    }

    gdi_layer_pop_and_restore_active();

    AVK_LOG_NORMAL(gdi_layer_get_base_handle(&g_avk_fw_graphic_ctx->basehandle));
    gdi_layer_set_blt_layer(g_avk_fw_graphic_ctx->basehandle, g_avk_fw_graphic_ctx->layerhandle, 0, 0);
    gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}

AVK_MANUAL_CASE(AVK_FW_GRAPHIC_IMG,AVK_FW_GRAPHIC_INIT)
{
    AVK_MANU_SHOW_TIPS(L"Show 14 image",vs_fw_gdi_003_img);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_003_img_info_exit
 * DESCRIPTION
 *  make call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_003_img_info_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_avk_fw_graphic_ctx->screen_asmp != NULL)
    {
        applib_mem_screen_free(g_avk_fw_graphic_ctx->screen_asmp);
        g_avk_fw_graphic_ctx->screen_asmp = NULL;
    }
}


void vs_fw_gdi_003_dummy(U32 start_id, U32 end_id, PU8 buffer)
{

}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_003_img_redraw
 * DESCRIPTION
 *  vs_fw_gdi_003_img_redraw
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_gdi_003_img_redraw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 im;
    S32 width, height;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, vs_fw_gdi_exit, vs_fw_gdi_003_img_redraw, MMI_FRM_FULL_SCRN);
    if(ret == MMI_FALSE)
    return;    
    gdi_layer_create(0, 0, LCD_WIDTH, LCD_HEIGHT, &g_avk_fw_graphic_ctx->layerhandle);
    ASSERT(g_avk_fw_graphic_ctx->layerhandle != GDI_LAYER_EMPTY_HANDLE);
    
    im = (PU8) GetImage(IMG_ID_AVK_DEVAPP_2);
    AVK_LOG_NORMAL(gdi_image_get_dimension(im, &width, &height));
    g_avk_fw_graphic_ctx->backup_bitmap.buf_ptr = (PU8) applib_mem_screen_alloc(6 * 1024);

    gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->layerhandle);
    gdi_layer_clear_background(GDI_COLOR_WHITE);

	AVK_DRAW_TITLE((WCHAR*)L"Img redraw");
	AVK_DRAW_SOFTKEY(KEY_LSK,AVK_STR_PASS);
    AVK_DRAW_SOFTKEY(KEY_RSK,AVK_STR_FAIL);
    
    AVK_LOG_NORMAL(gdi_image_draw(0, AVK_FRAMEWORK_SOFTKEY_HEIGHT + 1, im));

	if(width > LCD_WIDTH)
		width = LCD_WIDTH;

	if(height >LCD_HEIGHT)
        height = LCD_HEIGHT;
		 
    AVK_LOG_NORMAL(gdi_bitblt_resized(
        g_avk_fw_graphic_ctx->layerhandle,
        0,
        0,
        width - 1,
        height - 1,
        150,
        150,
        LCD_WIDTH,
        LCD_HEIGHT - AVK_FRAMEWORK_SOFTKEY_HEIGHT - 1));

    AVK_LOG_NORMAL(gdi_image_cache_reset());
    AVK_LOG_NORMAL(gdi_image_cache_bmp_get(150, 150, 200, 200, &g_avk_fw_graphic_ctx->backup_bitmap));
    AVK_LOG_NORMAL(gdi_image_cache_bmp_draw(0, 270, &g_avk_fw_graphic_ctx->backup_bitmap));
    gdi_layer_pop_and_restore_active();
    gdi_layer_get_base_handle(&g_avk_fw_graphic_ctx->basehandle);
    gdi_layer_set_blt_layer(g_avk_fw_graphic_ctx->basehandle, g_avk_fw_graphic_ctx->layerhandle, 0, 0);
    gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);

    
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_003_img_info
 * DESCRIPTION
 *  verify the iamge related API
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_gdi_003_img_info(void)
{
#ifdef __MMI_EBOOK_READER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 ptr;
    U16 size;
    U16 image_path[100];
    S32 frame_count;
    U16 temp[5];
    S32 width;
    S32 height;
    gui_page_info_app ebook;
    gui_page_info_app *ebook_need = &ebook;
    S8 buf[10];
    S32 ret_drv;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, vs_fw_gdi_003_img_info_exit, vs_fw_gdi_003_img_info, MMI_FRM_FULL_SCRN);
    if(ret == MMI_FALSE)
    return;
    g_avk_fw_graphic_ctx->screen_asmp = (U16*) applib_mem_screen_alloc(1024);

    ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);
    if (ret_drv >= 0)
    {
        sprintf(buf, "%c:\\", (U8) ret_drv);
        mmi_asc_to_wcs((PU16) image_path, buf);
        mmi_wcscat((PU16) image_path, (PU16) L"AVK\\test file\\avk_fw_graphic\\boy.gif");
    }
    mmi_wcscpy(g_avk_fw_graphic_ctx->screen_asmp, (WCHAR*)L"The 1st group:frame count is");
    AVK_LOG_NORMAL(gdi_image_get_frame_count_id(IMG_ID_AVK_DEVAPP_1, &frame_count));
    gui_itoa(frame_count, temp, 10);
    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, temp);

    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, (WCHAR*)L".width&height is ");
    AVK_LOG_NORMAL(gdi_image_get_dimension_id(IMG_ID_AVK_DEVAPP_1, &width, &height));
    gui_itoa(width, temp, 10);
    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, temp);
    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, (WCHAR*)L" ");
    gui_itoa(height, temp, 10);
    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, temp);

    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, (WCHAR*)L".img type is ");
    if (AVK_LOG(gdi_image_get_type_from_id(IMG_ID_AVK_DEVAPP_1)) == GDI_IMAGE_TYPE_GIF)
    {
        mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, (WCHAR*)L"GIF.");
    }
    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, (WCHAR*)L"size ");
    size = gdi_image_get_buf_len_from_id(IMG_ID_AVK_DEVAPP_1);
    gui_itoa(size, temp, 10);
    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, temp);

    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, (WCHAR*)L"\n 2nd group frame count is ");
    gdi_image_get_frame_count_file((PU8) image_path, &frame_count);
    gui_itoa(frame_count, temp, 10);
    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, temp);

    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, (WCHAR*)L".width&height is ");
    gdi_image_get_dimension_file((PS8) image_path, &width, &height);
    gui_itoa(width, temp, 10);
    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, temp);
    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, (WCHAR*)L" ");
    gui_itoa(height, temp, 10);
    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, temp);

    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, (WCHAR*)L".img type is ");
    if (gdi_image_get_type_from_file((PS8) image_path) == GDI_IMAGE_TYPE_GIF_FILE)
    {
        mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, (WCHAR*)L"GIF.");
    }

    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, (WCHAR*)L"\n 3rd group width&height is ");
    ptr = gdi_image_get_buf_ptr((PU8) GetImage(IMG_ID_AVK_DEVAPP_1));
    gdi_image_get_dimension_mem(
        (U8) gdi_image_get_buf_type((PU8) GetImage(IMG_ID_AVK_DEVAPP_1)),
        ptr,
        gdi_image_get_buf_len((PU8) GetImage(IMG_ID_AVK_DEVAPP_1)),
        &width,
        &height);
    gui_itoa(width, temp, 10);
    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, temp);
    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, (WCHAR*)L" ");
    gui_itoa(height, temp, 10);
    mmi_wcscat(g_avk_fw_graphic_ctx->screen_asmp, temp);

    ebook_need->end_id = 10;
    ebook_need->start_id = 1;
    ebook_need->doc_size = 100;
    ebook_need->last_text_offset_y = 0;
    ebook_need->jump_offset_from_app = 0;
    ebook_need->text_offset = 0;
    ebook_need->scroll_speed = 0;
    ebook_need->scroll_type = 1;
    ebook_need->scroll_flag = 0;
    ebook_need->font_size = 1;
    ebook_need->search_str_len = 3;
    ebook_need->font_style = 0;
    ebook_need->jump_to_end = FALSE;
    ebook_need->highlight_string = FALSE;
    ebook_need->search_flag_is_on = FALSE;
    ebook_need->last_showed_percentage = 10;
    ebook_need->get_page_cb = vs_fw_gdi_003_dummy; 

    ShowCategory75Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        (PU8) g_avk_fw_graphic_ctx->screen_asmp,
        mmi_wcslen(g_avk_fw_graphic_ctx->screen_asmp),
        NULL,
        NULL,
        &ebook_need);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
#else
	vs_fw_gdi_003_img_redraw();
#endif
}

AVK_MANUAL_CASE(AVK_FW_GRAPHIC_IMG_INFO,AVK_FW_GRAPHIC_INIT)
{
    AVK_MANU_SHOW_TIPS(L"If not blank page, pass",vs_fw_gdi_003_img_info);
}

void vs_fw_gdi_003_img_nbdraw_2 (void)
{
	mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_2, NULL, NULL, MMI_FRM_FULL_SCRN);
	GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_003_img_nbdraw_stop
 * DESCRIPTION
 *  redraw_image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_003_img_nbdraw_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_nb_stop_all();
    gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->layerhandle);
    avk_framework_draw_softkey(KEY_RSK, STR_GLOBAL_REFRESH);
    gdi_layer_pop_and_restore_active();
    gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);

    SETRIGHTKEY(vs_fw_gdi_003_img_nbdraw_2);
 
#ifdef __MMI_TOUCH_SCREEN__    
//		mmi_pen_register_down_handler(mmi_vs_framework_pen_down_hdlr);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_003_img_nbdraw
 * DESCRIPTION
 *  redraw_image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_gdi_003_img_nbdraw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 im;
    U8 *guibuffer;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, vs_fw_gdi_exit, vs_fw_gdi_003_img_nbdraw, MMI_FRM_FULL_SCRN);

	if(ret == MMI_FALSE)
		return;

	guibuffer = mmi_frm_scrn_get_active_gui_buf(); 
    im = (PU8) GetImage(IMG_ID_AVK_DEVAPP_1);
    gdi_nb_set_blt(MMI_FALSE, MMI_FALSE);
    gdi_layer_create(0, 0, LCD_WIDTH, LCD_HEIGHT, &g_avk_fw_graphic_ctx->layerhandle);
    ASSERT(g_avk_fw_graphic_ctx->layerhandle != GDI_LAYER_EMPTY_HANDLE);
    gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->layerhandle);
    gdi_layer_clear_background(GDI_COLOR_WHITE);

    AVK_DRAW_TITLE((WCHAR*)L"img nbdraw");
    if (guibuffer == NULL)
    {
        avk_framework_draw_softkey(KEY_RSK, STR_GLOBAL_STOP);
        SETRIGHTKEY(vs_fw_gdi_003_img_nbdraw_stop);
    }
    else
    {
        AVK_DRAW_SOFTKEY(KEY_LSK,AVK_STR_PASS);
        AVK_DRAW_SOFTKEY(KEY_RSK,AVK_STR_FAIL);
        AVK_SET_PASSKEY(NULL);
        AVK_SET_FAILKEY(NULL);
    }
    gdi_image_nb_draw(5, AVK_FRAMEWORK_SOFTKEY_HEIGHT + 1, im);
    gdi_image_nb_draw_resized(70, AVK_FRAMEWORK_SOFTKEY_HEIGHT + 1, 40, 40, im);
    gdi_image_nb_draw_frames(120, AVK_FRAMEWORK_SOFTKEY_HEIGHT + 1, im, 3);
    gdi_image_nb_draw_resized_frames(185, AVK_FRAMEWORK_SOFTKEY_HEIGHT + 1, 50, 50, im, 2);

    gdi_layer_pop_and_restore_active();

    gdi_layer_get_base_handle(&g_avk_fw_graphic_ctx->basehandle);
    gdi_layer_set_blt_layer(g_avk_fw_graphic_ctx->basehandle, g_avk_fw_graphic_ctx->layerhandle, 0, 0);
    gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);
}

AVK_MANUAL_CASE(AVK_FW_GRAPHIC_IMG_NBDRAW,AVK_FW_GRAPHIC_INIT)
{
    AVK_MANU_SHOW_TIPS(L"If not blank page, pass",vs_fw_gdi_003_img_nbdraw);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_003_img_anim
 * DESCRIPTION
 *  redraw_image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_gdi_003_img_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 ptr;
    U32 size;
    U8 type;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, vs_fw_gdi_exit, vs_fw_gdi_003_img_anim, MMI_FRM_FULL_SCRN);
    if(ret == MMI_FALSE)
    {
        return;
    }        
    gdi_layer_create(0, 0, LCD_WIDTH, LCD_HEIGHT, &g_avk_fw_graphic_ctx->layerhandle);
    ASSERT(g_avk_fw_graphic_ctx->layerhandle != GDI_LAYER_EMPTY_HANDLE);
    gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->layerhandle);
    gdi_layer_clear_background(GDI_COLOR_WHITE);

    AVK_DRAW_TITLE((WCHAR*)L"Img anim");
    AVK_DRAW_SOFTKEY(KEY_LSK,AVK_STR_PASS);
    AVK_DRAW_SOFTKEY(KEY_RSK,AVK_STR_FAIL);

    ptr = gdi_image_get_buf_ptr_from_id(IMG_ID_AVK_DEVAPP_1);
    type = gdi_image_get_type_from_mem((PS8) ptr);
    size = gdi_image_get_buf_len((PU8) GetImage(IMG_ID_AVK_DEVAPP_1));

    gdi_anim_draw_resized_frames(50, 240, 60, 60, GetImage(IMG_ID_AVK_DEVAPP_1), &g_avk_fw_graphic_ctx->anim_handle, 0);
    gdi_anim_draw_mem_resized_frames(
        100,
        AVK_FRAMEWORK_SOFTKEY_HEIGHT + 1,
        40,
        40,
        ptr,
        type,
        size,
        &g_avk_fw_graphic_ctx->anim_handle,
        0);
    gdi_anim_draw_mem_resized(0, 100 + AVK_FRAMEWORK_SOFTKEY_HEIGHT + 1, 40, 40, ptr, type, size, &g_avk_fw_graphic_ctx->anim_handle);
    gdi_anim_draw_mem_once(100, 100 + AVK_FRAMEWORK_SOFTKEY_HEIGHT + 1, ptr, type, size, &g_avk_fw_graphic_ctx->anim_handle);
    gdi_layer_pop_and_restore_active();

    gdi_layer_get_base_handle(&g_avk_fw_graphic_ctx->basehandle);
    gdi_layer_set_blt_layer(g_avk_fw_graphic_ctx->basehandle, g_avk_fw_graphic_ctx->layerhandle, 0, 0);
    gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}

AVK_MANUAL_CASE(AVK_FW_GRAPHIC_IMG_ANIM,AVK_FW_GRAPHIC_INIT)
{
    AVK_MANU_SHOW_TIPS(L"If not blank page, pass",vs_fw_gdi_003_img_anim);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_layer_create
 * DESCRIPTION
 *  add menuitem
 * PARAMETERS
 *  layer_num       [IN]        
 *  strId           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_gdi_layer_create(U8 layer_num, WCHAR* title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color color;
    PU8 buf_ptr = NULL;
    int layer_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_avk_fw_graphic_ctx->handle, 0, VS_MAX_LAYER_NUM * 8);
    /* gdi_layer_multi_layer_enable(); */

    if (layer_num > VS_MAX_LAYER_NUM)
    {
        layer_num = VS_MAX_LAYER_NUM;
    }
    for (layer_index = 0; layer_index < layer_num; layer_index++)
    {
        switch (layer_index)
        {
            case 0:
                gdi_layer_create(0, 0, LCD_WIDTH, LCD_HEIGHT, &g_avk_fw_graphic_ctx->handle[layer_index]);
                break;
            case 1:
                gdi_layer_get_buffer_ptr(&buf_ptr);
                gdi_layer_create_using_outside_memory(
                    0,
                    0,
                    LCD_WIDTH,
                    LCD_HEIGHT,
                    &g_avk_fw_graphic_ctx->handle[layer_index],
                    (PU8) buf_ptr,
                    (S32) VS_LAYER_BUFFER_SIZE);
                /* gdi_layer_create_using_outside_memory(0, 0, LCD_WIDTH, LCD_HEIGHT, 
                   &g_avk_fw_graphic_ctx->handle[layer_index], (PU8)layer_buffer1, (S32)VS_LAYER_BUFFER_SIZE); */
                break;
            case 2:
                gdi_layer_create_double_using_outside_memory(
                    0,
                    0,
                    LCD_WIDTH,
                    LCD_HEIGHT,
                    &g_avk_fw_graphic_ctx->handle[layer_index],
                    (PU8) g_avk_fw_graphic_ctx->layer_buffer2,
                    (S32) (VS_LAYER_BUFFER_SIZE * 2));
                break;
            case 3:
                gdi_layer_create_double(0, 0, LCD_WIDTH, LCD_HEIGHT, &g_avk_fw_graphic_ctx->handle[layer_index]);
                break;
            default:
                return;
        }
        ASSERT(g_avk_fw_graphic_ctx->handle[layer_index] != GDI_LAYER_EMPTY_HANDLE);
        gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->handle[layer_index]);
        if (layer_index == 2)
        {
            gdi_layer_toggle_double();
            gdi_layer_copy_double();
        }

        gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        switch (layer_index)
        {
            case 0:
                color = gdi_layer_get_background();
                if (color != GDI_COLOR_WHITE)
                {
                    gdi_layer_set_background(GDI_COLOR_WHITE);
                }
                gdi_draw_solid_rect(20, 100, 50, 180, GDI_COLOR_GRAY);
                break;
            case 1:
                gdi_draw_circle(50, 130, 20, GDI_COLOR_GREEN);
                break;
            case 2:
                gdi_draw_line(20, 100, 50, 180, GDI_COLOR_RED);
                break;
            case 3:
                gdi_draw_circle(50, 130, 20, GDI_COLOR_GREEN);
                break;
            default:
                return;
        }

        AVK_DRAW_TITLE(title);
        AVK_DRAW_SOFTKEY(KEY_LSK, AVK_STR_PASS);
        AVK_DRAW_SOFTKEY(KEY_RSK, AVK_STR_FAIL);

        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_layer_free
 * DESCRIPTION
 *  show image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_layer_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_flatten_previous_to_base();
    for (i = 0; i < VS_MAX_LAYER_NUM; i++)
    {
        if (g_avk_fw_graphic_ctx->handle[i] != 0)
        {
            gdi_layer_free(g_avk_fw_graphic_ctx->handle[i]);
            g_avk_fw_graphic_ctx->handle[i] = 0;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_004_layer_save0
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_gdi_004_layer_save0(U16 fullname[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG_EX(GDI_SUCCEED == gdi_layer_save_jpeg_file(g_avk_fw_graphic_ctx->basehandle, (S8*) fullname));
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_004_layer_save1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_gdi_004_layer_save1(U16 fullname[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG_EX(GDI_SUCCEED == gdi_layer_save_pbm_file(g_avk_fw_graphic_ctx->basehandle, (S8*) fullname));
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_004_layer_save2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_gdi_004_layer_save2(U16 fullname[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG_EX(GDI_SUCCEED == gdi_layer_save_bmp_file(g_avk_fw_graphic_ctx->basehandle, (S8*) fullname));
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_004_layer
 * DESCRIPTION
 *  add menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_004_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[10];
    S32 ret_drv;
    U16 fullname[80];
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, vs_fw_gdi_layer_free, vs_fw_gdi_004_layer, MMI_FRM_FULL_SCRN);
    if(ret == MMI_FALSE)
    return;
    vs_fw_gdi_layer_create(3, (WCHAR*)L"Layer Blt1");

    gdi_layer_get_base_handle(&g_avk_fw_graphic_ctx->basehandle);
    /* gdi_layer_clear_background(GDI_COLOR_WHITE); */
    gdi_layer_set_blt_layer(
        g_avk_fw_graphic_ctx->basehandle,
        g_avk_fw_graphic_ctx->handle[0],
        g_avk_fw_graphic_ctx->handle[1],
        g_avk_fw_graphic_ctx->handle[2]);

    /* gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT); */
    gdi_lcd_repaint_all();
    ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);
    if (ret_drv >= 0)
    {
		sprintf(buf, "%c:\\", (U8)ret_drv);
		memset(fullname,0,sizeof(fullname));
        mmi_asc_to_wcs((PU16)fullname, buf);		
		mmi_wcscat((PU16)fullname, (PU16)L"AVK\\test file\\avk_fw_graphic\\test.JPG");
		vs_fw_gdi_004_layer_save0(fullname);

		memset(fullname,0,sizeof(fullname));
        mmi_asc_to_wcs((PU16)fullname, buf);		
		mmi_wcscat((PU16)fullname, (PU16)L"AVK\\test file\\avk_fw_graphic\\test.PBM");
		vs_fw_gdi_004_layer_save1(fullname);
		
		memset(fullname,0,sizeof(fullname));
        mmi_asc_to_wcs((PU16)fullname, buf);		
		mmi_wcscat((PU16)fullname, (PU16)L"AVK\\test file\\avk_fw_graphic\\test.BMP");
		vs_fw_gdi_004_layer_save2(fullname);
	}

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_005_layer_test0
 * DESCRIPTION
 *  show image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_005_layer_test0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->handle[0]);
    gdi_layer_set_rotate(GDI_LAYER_ROTATE_270);
    gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
    gdi_layer_pop_and_restore_active();
    gdi_lcd_blt(g_avk_fw_graphic_ctx->basehandle, g_avk_fw_graphic_ctx->handle[0], g_avk_fw_graphic_ctx->handle[1], 0);

	AVK_DRAW_TITLE((WCHAR*)L"Layer Blt2");
	AVK_DRAW_SOFTKEY(KEY_LSK, STR_GLOBAL_CONTINUE);
	AVK_DRAW_SOFTKEY(KEY_RSK, AVK_STR_FAIL);
	
    SETLEFTKEY(vs_fw_gdi_005_layer_test1);
    AVK_SET_FAILKEY(NULL);
#ifdef __MMI_TOUCH_SCREEN__    
//		mmi_pen_register_down_handler(mmi_vs_framework_pen_down_hdlr);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_005_layer_test1
 * DESCRIPTION
 *  show image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_005_layer_test1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->basehandle);
    gdi_layer_flatten(g_avk_fw_graphic_ctx->handle[0], g_avk_fw_graphic_ctx->handle[1], g_avk_fw_graphic_ctx->handle[2], 0);
    gdi_layer_pop_and_restore_active();
    gdi_layer_set_blt_layer(g_avk_fw_graphic_ctx->basehandle, 0, 0, 0);
    gdi_lcd_repaint(0, 0, LCD_WIDTH, LCD_HEIGHT);

    AVK_DRAW_TITLE((WCHAR*)L"Layer Blt2");
    AVK_DRAW_SOFTKEY(KEY_LSK, STR_GLOBAL_CONTINUE);
    AVK_DRAW_SOFTKEY(KEY_RSK, AVK_STR_FAIL);

    SETLEFTKEY(vs_fw_gdi_005_layer_test2);
    AVK_SET_FAILKEY(NULL);
#ifdef __MMI_TOUCH_SCREEN__    
//		mmi_pen_register_down_handler(mmi_vs_framework_pen_down_hdlr);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_005_layer_test2
 * DESCRIPTION
 *  show image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_005_layer_test2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_flatten_to_base(g_avk_fw_graphic_ctx->handle[0], g_avk_fw_graphic_ctx->handle[1], g_avk_fw_graphic_ctx->handle[2], 0);
    gdi_layer_blt_base_layer(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

	AVK_DRAW_SOFTKEY(KEY_LSK, AVK_STR_PASS);
    AVK_DRAW_SOFTKEY(KEY_RSK, AVK_STR_FAIL);
    
	AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
#ifdef __MMI_TOUCH_SCREEN__    
//		mmi_pen_register_down_handler(mmi_vs_framework_pen_down_hdlr);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_005_layer
 * DESCRIPTION
 *  show image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_005_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, vs_fw_gdi_layer_free, vs_fw_gdi_005_layer, MMI_FRM_FULL_SCRN);
    if(ret == MMI_FALSE)
    return;
    vs_fw_gdi_layer_create(3, (WCHAR*)L"Layer Blt2");

    gdi_layer_get_base_handle(&g_avk_fw_graphic_ctx->basehandle);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_layer_blt(
        g_avk_fw_graphic_ctx->basehandle,
        g_avk_fw_graphic_ctx->handle[0],
        g_avk_fw_graphic_ctx->handle[1],
        0,
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT);

	AVK_DRAW_SOFTKEY(KEY_LSK, STR_GLOBAL_CONTINUE);
	AVK_DRAW_SOFTKEY(KEY_RSK, AVK_STR_FAIL);
		

    SETLEFTKEY(vs_fw_gdi_005_layer_test0);
    AVK_SET_FAILKEY(NULL);
}

AVK_MANUAL_CASE(AVK_FW_GRAPHIC_LAYER,AVK_FW_GRAPHIC_INIT)
{
    AVK_MANU_SHOW_TIPS(L"If not blank page, pass",vs_fw_gdi_005_layer);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_005_layer
 * DESCRIPTION
 *  show image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_010_font(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_filled_area background_border = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
        UI_IMAGE_ID_NULL,
        NULL,
        {255, 60, 255, 100},   
        {0, 0, 0, 0},
        {0, 0, 0, 100},         /* black border */
        {0, 0, 0, 0},
        0
    };

    U16 *info = (U16 *)L"[Welcome to MTK]";
    U16 * add_info = (U16 *)L"stringerror";
    S32 w=0;
    S32 width,height;
    S32 wi,h;
    S32 i,j;
    mmi_fe_color fe_color;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, vs_fw_gdi_exit, vs_fw_gdi_010_font, MMI_FRM_FULL_SCRN);
    if(ret == MMI_FALSE)
    return;
	gdi_layer_create(0, 0, LCD_WIDTH, LCD_HEIGHT, &g_avk_fw_graphic_ctx->layerhandle);
    ASSERT(g_avk_fw_graphic_ctx->layerhandle != GDI_LAYER_EMPTY_HANDLE);
	
    gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->layerhandle);
    gdi_layer_clear_background(GDI_COLOR_WHITE);
	
    AVK_DRAW_TITLE((WCHAR*)L"GDI font");
    AVK_DRAW_SOFTKEY(KEY_RSK, AVK_STR_FAIL);
    AVK_DRAW_SOFTKEY(KEY_LSK, AVK_STR_PASS);
	gui_draw_filled_area(
        20 - 1,
        50 - 1,
        150 + 1,
        100 + 1,
        &background_border);

	w = gui_get_character_width((UI_character_type) '[');
	gui_measure_string_n(info,8,&width,&height);
	i= gui_get_string_width_n(info,8);
	if(i == width)
	{
		gui_move_text_cursor(20,50);
		gui_print_text_n(info,8);
	}

	Get_CharWidthHeight('[', &wi, &h);
	if((wi == w) && (h == height))
	{
		fe_color.a = 200;
		fe_color.r = 160;
		fe_color.g = 160;
		fe_color.b = 175;
		mmi_fe_set_text_color(fe_color);
		mmi_fe_show_string_n(50,100,(U8*)add_info,6);
	}

	gui_measure_string(info,&width,&height);
	j = gui_get_string_width(info);
	if(j == width)
	{
		gui_set_text_color(gui_color(10, 255, 100));
		gui_move_text_cursor(20+w,50+height);
		gui_print_text(info);
	}
    gdi_layer_pop_and_restore_active();
	
    gdi_layer_get_base_handle(&g_avk_fw_graphic_ctx->basehandle);
    gdi_layer_set_blt_layer(g_avk_fw_graphic_ctx->basehandle, g_avk_fw_graphic_ctx->layerhandle, 0, 0);
    gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);
	
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}

AVK_MANUAL_CASE(AVK_FW_GRAPHIC_FONT,AVK_FW_GRAPHIC_INIT)
{    
    AVK_MANU_SHOW_TIPS(L"screen will show two line text.[welcome and [welcome to MTK]",vs_fw_gdi_010_font);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_011_fb_related_test1
 * DESCRIPTION
 *  framebuffer related test 1
 *  applib_mem_ap_alloc_framebuffer() & gdi_layer_create_using_outside_memory()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_011_fb_related_test1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate a frame buffer using app-based ASM */
    if (g_avk_fw_graphic_ctx->app_mem_pool_framebuffer == NULL)
    {
        applib_mem_ap_register(APPLIB_MEM_AP_ID_VS_TEST1, STR_GLOBAL_1, IMG_GLOBAL_L1, vs_fw_memory_002_ap_stop1);
        g_avk_fw_graphic_ctx->app_mem_pool_framebuffer = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_VS_TEST1, VS_LAYER_BUFFER_SIZE);

        if (g_avk_fw_graphic_ctx->app_mem_pool_framebuffer == NULL)
        {
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_VS_TEST1,
                0,
                VS_LAYER_BUFFER_SIZE,
                vs_fw_gdi_011_fb_related_callback);
            return;
        }
    }

    /* entry new screen */
    ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, vs_fw_gdi_011_fb_related_test1_exit, vs_fw_gdi_011_fb_related_test1, MMI_FRM_FULL_SCRN);
    if(ret == MMI_FALSE)
        return;
    /* Create a layer using the frame buffer */
    if (g_avk_fw_graphic_ctx->frame_layer_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_create_using_outside_memory(
                    0,
                    0,
                    LCD_WIDTH,
                    LCD_HEIGHT,
                    &g_avk_fw_graphic_ctx->frame_layer_handle,
                    (U8*)g_avk_fw_graphic_ctx->app_mem_pool_framebuffer,
                    VS_LAYER_BUFFER_SIZE);
    }
    ASSERT(g_avk_fw_graphic_ctx->frame_layer_handle != GDI_LAYER_EMPTY_HANDLE);

    /* Draw on the new layer */
    gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->frame_layer_handle);

    /* Clear screen */
    gdi_layer_clear_background(GDI_COLOR_WHITE);
    gdi_draw_line(100, 200, 150, 300, GDI_COLOR_GREEN);
    gdi_draw_rect(10, 10 + AVK_FRAMEWORK_SOFTKEY_HEIGHT, 50, 200, GDI_COLOR_RED);
    gdi_draw_circle(150, 150, 30, GDI_COLOR_BLUE);

    /* Draw title and soft key button */
    AVK_DRAW_TITLE((WCHAR*)L"Framebuffer related");
    AVK_DRAW_SOFTKEY(KEY_RSK, AVK_STR_FAIL);
    AVK_DRAW_SOFTKEY(KEY_LSK, AVK_STR_PASS);

    gdi_layer_pop_and_restore_active();

    /* Bitblt */
    gdi_layer_get_base_handle(&g_avk_fw_graphic_ctx->basehandle);
    gdi_layer_set_blt_layer(g_avk_fw_graphic_ctx->basehandle, g_avk_fw_graphic_ctx->frame_layer_handle, 0, 0);
    gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);   
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_011_fb_related_callback
 * DESCRIPTION
 *  Callback function when getting memory successfully
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_gdi_011_fb_related_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_avk_fw_graphic_ctx->app_mem_pool_framebuffer
        = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_VS_TEST1, VS_LAYER_BUFFER_SIZE);
    ASSERT(g_avk_fw_graphic_ctx->app_mem_pool_framebuffer != NULL);  /* It should provide enough memory */
    vs_fw_gdi_011_fb_related_test1();
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_011_fb_related_test1_exit
 * DESCRIPTION
 *  framebuffer related test case exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_gdi_011_fb_related_test1_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free frame buffer */
    if (g_avk_fw_graphic_ctx->app_mem_pool_framebuffer != NULL)
    {
        applib_mem_ap_free((void*)g_avk_fw_graphic_ctx->app_mem_pool_framebuffer);
        g_avk_fw_graphic_ctx->app_mem_pool_framebuffer = NULL;
    }

    /* Free frame layer */
    if (g_avk_fw_graphic_ctx->frame_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_avk_fw_graphic_ctx->frame_layer_handle);
        g_avk_fw_graphic_ctx->frame_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }
}

AVK_MANUAL_CASE(AVK_FW_GRAPHIC_FB_RELATED,AVK_FW_GRAPHIC_INIT)
{  
    AVK_MANU_SHOW_TIPS(L"Show a circle, a line and a rectangle",vs_fw_gdi_011_fb_related_test1);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_011_fb_related_test2_pre
 * DESCRIPTION
 *  framebuffer related test case 2 pre-function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_gdi_011_fb_related_test2_pre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drv_letter;
    U8 avk_directory[10];       /* AVK directory */
    U8 source_file_path[100];    /* Source image path */
    MMI_BOOL ret ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, NULL, vs_fw_gdi_011_fb_related_test2_pre, MMI_FRM_FULL_SCRN);
    if(ret == MMI_FALSE)
    return;
    /* Get the source image file path */
    drv_letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL); 

    if (drv_letter >= 0)
    {
        /* Get drive letter */
        sprintf((char*)avk_directory, "%c:\\", (U8) drv_letter);

        /* Source image file path */
        mmi_asc_to_wcs((PU16) source_file_path, (PS8) avk_directory);
        mmi_wcscat((PU16) source_file_path, (PU16) L"AVK\\test file\\avk_fw_graphic\\test.bmp");
    }

    gdi_layer_get_base_handle(&g_avk_fw_graphic_ctx->basehandle);
    gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->basehandle);
    
    /* Clear screen */    
    gdi_layer_clear_background(GDI_COLOR_WHITE);

    /* Draw the source image file */
    gdi_image_draw_file(0, 0, (PS8) source_file_path);

    /* Draw the left soft key button */
    avk_framework_draw_softkey(KEY_LSK, STR_GLOBAL_OK);
    
    gdi_layer_pop_and_restore_active();

    /* Bitblt */
    gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);

    SETLEFTKEY(vs_fw_gdi_011_fb_related_test2); 
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_011_fb_related_test2
 * DESCRIPTION
 *  framebuffer related test 2
 *  applib_mem_screen_alloc_framebuffer() & gdi_image_encode_file_to_jpeg()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_gdi_011_fb_related_test2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drv_letter;
    U8 avk_directory[10];       /* AVK directory */
    U8 source_file_path[100];    /* Source image path */
    U8 dest_file_path[100];      /* Dest image path */
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    ret= mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_2,
	 	vs_fw_gdi_011_fb_related_test2_exit, vs_fw_gdi_011_fb_related_test2, MMI_FRM_FULL_SCRN);
    if(ret == MMI_FALSE)
        return;
    entry_full_screen();
    /* Allocate a frame buffer using screen-based ASM */
    if (g_avk_fw_graphic_ctx->screen_asmp_framebuffer == NULL)
    {
        g_avk_fw_graphic_ctx->screen_asmp_framebuffer = (U8*) applib_mem_screen_alloc_framebuffer(VS_LAYER_BUFFER_SIZE);
    }
    ASSERT(g_avk_fw_graphic_ctx->screen_asmp_framebuffer != NULL);

    /* Get the source & dest image file path */
    drv_letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL); 

    if (drv_letter >= 0)
    {
        /* Get drive letter */
        sprintf((char*)avk_directory, "%c:\\", (U8) drv_letter);

        /* Source image file path */
        mmi_asc_to_wcs((PU16) source_file_path, (PS8) avk_directory);
        mmi_wcscat((PU16) source_file_path, (PU16) L"AVK\\test file\\avk_fw_graphic\\test.bmp");

        /* Dest image file path */
        mmi_asc_to_wcs((PU16) dest_file_path, (PS8) avk_directory);
        mmi_wcscat((PU16) dest_file_path, (PU16) L"AVK\\test file\\avk_fw_graphic\\dest.jpg");
    }

    /* Encode the source image to a small size image */
    if (g_avk_fw_graphic_ctx->screen_asmp_framebuffer != NULL)
    {
        gdi_image_encode_file_to_jpeg(
                    (PS8) source_file_path,
                    (PS8) dest_file_path,
                    60,
                    64,
                    g_avk_fw_graphic_ctx->screen_asmp_framebuffer,
                    VS_LAYER_BUFFER_SIZE);
    }
    
    gdi_layer_get_base_handle(&g_avk_fw_graphic_ctx->basehandle);
    gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->basehandle);
    
    /* Clear screen */
    gdi_layer_clear_background(GDI_COLOR_WHITE);

    /* Draw the dest image file */
    gdi_image_draw_file(60, 100, (PS8) dest_file_path);

    /* Draw the soft key button */
    avk_framework_draw_softkey(KEY_RSK, AVK_STR_FAIL);
    avk_framework_draw_softkey(KEY_LSK, AVK_STR_PASS);

    gdi_layer_pop_and_restore_active();

    /* Bitblt */
    gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_011_fb_related_test2_exit
 * DESCRIPTION
 *  framebuffer related test 2 exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_gdi_011_fb_related_test2_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free frame buffer */
    if (g_avk_fw_graphic_ctx->screen_asmp_framebuffer != NULL)
    {
        applib_mem_screen_free((void*)g_avk_fw_graphic_ctx->screen_asmp_framebuffer);
        g_avk_fw_graphic_ctx->screen_asmp_framebuffer = NULL;
    }
	leave_full_screen();
}

AVK_MANUAL_CASE(AVK_FW_GRAPHIC_FB_RELATED_2,AVK_FW_GRAPHIC_INIT)
{
    AVK_MANU_SHOW_TIPS(L"Show blank page",vs_fw_gdi_011_fb_related_test2_pre);
}

/* Because ShowCategory426Screen() is not opened to Vendor, so comment out the Case temporarily. */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_012_layer_cf_exit
 * DESCRIPTION
 *  Layer(CF) test case exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_gdi_012_layer_cf_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free frame buffer */
    if (g_avk_fw_graphic_ctx->screen_asmp_framebuffer != NULL)
    {
        applib_mem_screen_free((void*)g_avk_fw_graphic_ctx->screen_asmp_framebuffer);
        g_avk_fw_graphic_ctx->screen_asmp_framebuffer = NULL;
    }
    /* Free layer */
    if (g_avk_fw_graphic_ctx->layerhandle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_avk_fw_graphic_ctx->layerhandle);
        g_avk_fw_graphic_ctx->layerhandle = GDI_LAYER_EMPTY_HANDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_012_layer_cf
 * DESCRIPTION
 *  test case for API: gdi_layer_create_cf_double_using_outside_memory()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_012_layer_cf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U8* mainBufferPtr = NULL;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* entry new screen */
    ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, vs_fw_gdi_012_layer_cf_exit,vs_fw_gdi_012_layer_cf, MMI_FRM_FULL_SCRN);
    if(ret == MMI_FALSE)
    return;
    /* Get the first memory */
    if (g_avk_fw_graphic_ctx->screen_asmp_framebuffer == NULL)
    {
        g_avk_fw_graphic_ctx->screen_asmp_framebuffer = (U8*) applib_mem_screen_alloc_framebuffer(VS_LAYER_BUFFER_SIZE);
    }
    ASSERT(g_avk_fw_graphic_ctx->screen_asmp_framebuffer != NULL);

    /* Get the second memory */
    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
	gdi_layer_get_buffer_ptr(&mainBufferPtr);
    gdi_layer_clear(GDI_COLOR_WHITE);
    /* Draw title and soft key button */
    AVK_DRAW_TITLE((WCHAR*)L"Create Layer(CF)");
    avk_framework_draw_softkey(KEY_RSK, AVK_STR_FAIL);
    avk_framework_draw_softkey(KEY_LSK, AVK_STR_PASS);
    gdi_draw_rect(24, LCD_HEIGHT/4, 96, LCD_HEIGHT/4+40, GDI_COLOR_BLACK);
    gdi_draw_rect(144, LCD_HEIGHT/4, 216, LCD_HEIGHT/4+40, GDI_COLOR_BLACK);
    gdi_draw_circle(60, LCD_HEIGHT/2, 36, GDI_COLOR_BLUE);    
    gdi_draw_circle(180, LCD_HEIGHT/2, 36, GDI_COLOR_BLUE);    
    gdi_draw_line(60, LCD_HEIGHT-LCD_HEIGHT/4, 180, LCD_HEIGHT - LCD_HEIGHT/4, GDI_COLOR_GREEN);
    gdi_layer_pop_and_restore_active();

    g_avk_fw_graphic_ctx->layerhandle = GDI_LAYER_EMPTY_HANDLE;
    gdi_layer_create_cf_double_using_outside_memory(
        GDI_LCD->cf,
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &g_avk_fw_graphic_ctx->layerhandle, 
        g_avk_fw_graphic_ctx->screen_asmp_framebuffer,   /* the first memory */
        VS_LAYER_BUFFER_SIZE, 
        mainBufferPtr,                          /* the second memory */
        VS_LAYER_BUFFER_SIZE);
    ASSERT(g_avk_fw_graphic_ctx->layerhandle != GDI_LAYER_EMPTY_HANDLE);

    gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->layerhandle);    
	memcpy(g_avk_fw_graphic_ctx->screen_asmp_framebuffer, mainBufferPtr, VS_LAYER_BUFFER_SIZE);
	gdi_layer_pop_and_restore_active();
    
    /* Bitblt */
    gdi_layer_get_base_handle(&g_avk_fw_graphic_ctx->basehandle);
    gdi_layer_set_blt_layer(g_avk_fw_graphic_ctx->basehandle, g_avk_fw_graphic_ctx->layerhandle, 0, 0);
    gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);  
}

AVK_MANUAL_CASE(AVK_FW_GRAPHIC_LAYER_CF,AVK_FW_GRAPHIC_INIT)
{
    AVK_MANU_SHOW_TIPS(L"Show 2 rectangle,2 circle,1 line",vs_fw_gdi_012_layer_cf);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_006_lcd
 * DESCRIPTION
 *  show image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_006_lcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;
    S32 lcd_width, lcd_height;
    BOOL is_lcd_freeze;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  	ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, vs_fw_gdi_layer_free, vs_fw_gdi_006_lcd, MMI_FRM_FULL_SCRN);
 	if(ret == MMI_FALSE)
		return;

    vs_fw_gdi_layer_create(3, (WCHAR*)L"GDI lcd");

    gdi_lcd_get_active(&old_lcd_handle);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    gdi_lcd_get_dimension(&lcd_width, &lcd_height);
    gdi_layer_reset_clip();
    gdi_layer_clear_background(GDI_COLOR_WHITE);

    gdi_lcd_paint_all(
        g_avk_fw_graphic_ctx->handle[0], 
        g_avk_fw_graphic_ctx->handle[1], 
        g_avk_fw_graphic_ctx->handle[2], 
        0);

    is_lcd_freeze = gdi_lcd_get_freeze();
    gdi_lcd_freeze(FALSE);
    gdi_layer_blt_previous(0, 0, 0, 0);

    gdi_lcd_freeze(is_lcd_freeze);
    gdi_lcd_set_active(old_lcd_handle);

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}

AVK_MANUAL_CASE(AVK_FW_GRAPHIC_LCD,AVK_FW_GRAPHIC_INIT)
{
    AVK_MANU_SHOW_TIPS(L"Show a line",vs_fw_gdi_006_lcd);
}

/*****************************************************************************
 * FUNCTION
 *  test_gdi_rotate_exit
 * DESCRIPTION
 *  show image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void test_gdi_rotate_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(gui_callback_rotate_timer);
    vs_fw_gdi_layer_free();
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_007_rotate
 * DESCRIPTION
 *  show image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_007_rotate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U8 layer_rotate; */
    gdi_handle prev_lcd_handle;
    S32 clip_x1;
    S32 clip_y1;
    S32 clip_x2;
    S32 clip_y2;
    S32 lcd_width, lcd_height;
    S32 layer_width, layer_height;
    S32 layer_offset_x, layer_offset_y;
    MMI_BOOL ret;
    gdi_color_format layer_format;     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  	ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, test_gdi_rotate_exit, vs_fw_gdi_007_rotate, MMI_FRM_FULL_SCRN);
    
	if(ret == MMI_FALSE)
		return;
    vs_fw_gdi_layer_create(3, (WCHAR*)L"GDI rotate");

    gdi_lcd_get_active(&prev_lcd_handle);
    /* gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE); */
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    gdi_lcd_get_rotate();
    gdi_lcd_get_dimension(&lcd_width, &lcd_height);
    gdi_lcd_set_active(prev_lcd_handle);

    /* get disp layer's paramters */
    gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->handle[0]);
    gdi_layer_toggle_double();

    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_color_format(GDI_COLOR_FORMAT_UYVY422);
    gdi_layer_get_color_format(&layer_format);

    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    /* layer_rotate = gdi_layer_get_rotate(); */
    gdi_layer_pop_and_restore_active();

    gui_start_timer(500, gui_callback_rotate_timer);

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);   
}

AVK_MANUAL_CASE(AVK_FW_GRAPHIC_ROTATE,AVK_FW_GRAPHIC_INIT)
{
    AVK_MANU_SHOW_TIPS(L"If it rotates, pass",vs_fw_gdi_007_rotate);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_008_clip
 * DESCRIPTION
 *  show image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_008_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   	ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, vs_fw_gdi_layer_free, vs_fw_gdi_008_clip, MMI_FRM_FULL_SCRN);
 	if(ret == MMI_FALSE)
		return;
    gdi_layer_create(0, 0, LCD_WIDTH, LCD_HEIGHT, &g_avk_fw_graphic_ctx->handle[0]);
    ASSERT(g_avk_fw_graphic_ctx->handle[0] != GDI_LAYER_EMPTY_HANDLE);
    gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->handle[0]);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_layer_lock_frame_buffer();
    /* get disp layer's paramters */
    gdi_layer_push_clip();
    gdi_layer_set_clip(30, 100, 70, 140);
    gdi_draw_circle(50, 120, 20, gdi_act_color_from_rgb(255, 255, 0,0));
    gdi_layer_set_clip_preset(0, 0, 500, 500);
    gdi_draw_line(0, 0, 150, 180, GDI_COLOR_RED);
    gdi_layer_reset_clip();
    gdi_layer_pop_clip();

//    AVK_DRAW_TITLE(L"GDI clip");
//    avk_framework_draw_softkey(KEY_LSK, AVK_STR_PASS);
//    avk_framework_draw_softkey(KEY_RSK, AVK_STR_FAIL);

    gdi_layer_unlock_frame_buffer();
    gdi_layer_pop_and_restore_active();
	gdi_layer_get_base_handle(&g_avk_fw_graphic_ctx->basehandle);
    gdi_layer_set_blt_layer(g_avk_fw_graphic_ctx->basehandle, g_avk_fw_graphic_ctx->handle[0], 0, 0);
    gdi_layer_blt_previous(0, 0, 150, 180);

    AVK_DRAW_TITLE((WCHAR*)L"GDI clip");
    avk_framework_draw_softkey(KEY_LSK, AVK_STR_PASS);
    avk_framework_draw_softkey(KEY_RSK, AVK_STR_FAIL);

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL); 
}

AVK_MANUAL_CASE(AVK_FW_GRAPHIC_CLIP,AVK_FW_GRAPHIC_INIT)
{
    AVK_MANU_SHOW_TIPS(L"If it transparent and draw line and circle, pass",vs_fw_gdi_008_clip);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_009_nbdraw_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_009_nbdraw_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_flatten_previous_to_base();
    mmi_popup_display_simple(
        (WCHAR*)L"Change!!",
        MMI_EVENT_WARNING,
        GRP_ID_AVK,
        NULL); 
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_gdi_009_nbdraw_control
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_gdi_009_nbdraw_control(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    PU8 im;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, vs_fw_gdi_exit, vs_fw_gdi_009_nbdraw_control, MMI_FRM_SMALL_SCRN);
    if(ret == MMI_FALSE)
	return;
     guiBuffer =mmi_frm_scrn_get_active_gui_buf();
    im = (PU8) GetImage(IMG_ID_AVK_DEVAPP_1);

    gdi_layer_create(0, 0, LCD_WIDTH, LCD_HEIGHT, &g_avk_fw_graphic_ctx->layerhandle);
    ASSERT(g_avk_fw_graphic_ctx->layerhandle != GDI_LAYER_EMPTY_HANDLE);
    gdi_layer_push_and_set_active(g_avk_fw_graphic_ctx->layerhandle);
    gdi_layer_clear_background(GDI_COLOR_WHITE);
    AVK_DRAW_TITLE((WCHAR*)L"GDI control");
    if (guiBuffer == NULL)
    {
        gdi_enable_non_block_blt();
        avk_framework_draw_softkey(KEY_LSK, STR_GLOBAL_CONFIRM);
        SETLEFTKEY(vs_fw_gdi_009_nbdraw_confirm);
    }
    else
    {
        gdi_disable_non_block_blt();
        avk_framework_draw_softkey(KEY_LSK, AVK_STR_PASS);
        avk_framework_draw_softkey(KEY_RSK, AVK_STR_FAIL);
        AVK_SET_PASSKEY(NULL);
        AVK_SET_FAILKEY(NULL);
    }
    gdi_image_nb_draw(0, 40, im);
    gdi_image_nb_draw_resized(70, 40, 40, 40, im);

    gdi_layer_pop_and_restore_active();

    gdi_layer_get_base_handle(&g_avk_fw_graphic_ctx->basehandle);
    gdi_layer_set_blt_layer(g_avk_fw_graphic_ctx->basehandle, g_avk_fw_graphic_ctx->layerhandle, 0, 0);
    gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);

}

AVK_MANUAL_CASE(AVK_FW_GRAPHIC_CONTROL,AVK_FW_GRAPHIC_INIT)
{
    AVK_MANU_SHOW_TIPS(L"If not blank page, pass",vs_fw_gdi_009_nbdraw_control);
}

AVK_MANUAL_CASE(AVK_FW_GRAPHIC_DEINIT,AVK_FW_GRAPHIC)
{
    AVK_FREE(g_avk_fw_graphic_ctx);
	AVK_CASE_RESULT(AVK_PASS);
    AVK_ASYN_DONE();
}

