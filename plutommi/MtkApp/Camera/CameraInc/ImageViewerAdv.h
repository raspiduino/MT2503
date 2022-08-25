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
 *  ImageViewerAdv.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_VIEWER_ADV_H_
#define _IMAGE_VIEWER_ADV_H_

#include "MMI_features.h"

#if defined(__MMI_NONBLOCKING_DECODE__)
#define __MMI_IMGADV_NONBLOCKING_DECODE__
#endif

#if defined(__MMI_IMAGE_VIEWER_ADV__)

#include "kal_general_types.h"
#include "fs_type.h"
#include "lcd_sw_inc.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gui_windows.h"
#include "MMIDataType.h"
#include "mmi_frm_input_gprot.h"

#ifndef _FILE_MGR_H_
#include "filemgr.h"
#endif

#include "FileMgrGProt.h"
#include "ImageViewerGprot.h"

/************************************************************************/
/* Imagviewer ADV                                                       */
/************************************************************************/
#if defined(__DRM_SUPPORT__)

typedef enum
{
    IMGADV_DRM_STATE_EXIT = 0,
    IMGADV_DRM_STATE_CONSUME,
    IMGADV_DRM_STATE_PAUSE,
    IMGADV_DRM_STATE_DECODING,
    IMGADV_DRM_STATE_TOTAL_COUNT
}imgadv_drm_state_enum;

typedef enum
{
    IMGADV_DRM_NOT_DRM_FILE = 0,
    IMGADV_DRM_DRM_FILE = 0x00000001,
    IMGADV_DRM_DISPLAY_VALID = 0x00000010,
    IMGADV_DRM_PRINT_VALID   = 0x00000100,
    IMGADV_DRM_MULTI_PART   = 0x00001000,
    IMGADV_DRM_MIMETYPE_NON_IMAGE= 0x00010000
  
}imgadv_drm_ret_enum;
#endif /* defined(__DRM_SUPPORT__)*/

#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
#error "not support this lcm size"
#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
#error "not support this lcm size"
#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
    #define MMI_IMGADV_MAP_WIDTH        40
    #define MMI_IMGADV_MAP_HEIGHT       40
    #define MMI_IMGADV_MAP_POSITION_X   4
    #define MMI_IMGADV_MAP_POSITION_Y   157
    #define MMI_IMGADV_ROTATED_MAP_POSITION_X   170
    #define MMI_IMGADV_ROTATED_MAP_POSITION_Y   110
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
    #define MMI_IMGADV_MAP_WIDTH        50
    #define MMI_IMGADV_MAP_HEIGHT       50
    #define MMI_IMGADV_MAP_POSITION_X   187
    #define MMI_IMGADV_MAP_POSITION_Y   235
    #define MMI_IMGADV_ROTATED_MAP_POSITION_X   267
    #define MMI_IMGADV_ROTATED_MAP_POSITION_Y   155
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
    #define MMI_IMGADV_MAP_WIDTH        50
    #define MMI_IMGADV_MAP_HEIGHT       50
    #define MMI_IMGADV_MAP_POSITION_X   267
    #define MMI_IMGADV_MAP_POSITION_Y   160
    #define MMI_IMGADV_ROTATED_MAP_POSITION_X   187
    #define MMI_IMGADV_ROTATED_MAP_POSITION_Y   240
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 400) )
    #define MMI_IMGADV_MAP_WIDTH        50
    #define MMI_IMGADV_MAP_HEIGHT       50
    #define MMI_IMGADV_MAP_POSITION_X   187
    #define MMI_IMGADV_MAP_POSITION_Y   240
    #define MMI_IMGADV_ROTATED_MAP_POSITION_X   335
    #define MMI_IMGADV_ROTATED_MAP_POSITION_Y   155
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480) )
    #define MMI_IMGADV_MAP_WIDTH        70
    #define MMI_IMGADV_MAP_HEIGHT       70
    #define MMI_IMGADV_MAP_POSITION_X   240
    #define MMI_IMGADV_MAP_POSITION_Y   320
    #define MMI_IMGADV_ROTATED_MAP_POSITION_X   390
    #define MMI_IMGADV_ROTATED_MAP_POSITION_Y   210
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */


typedef enum
{
    IMGADV_TOUCH_RSK = 0,
    IMGADV_TOUCH_LSK,
    IMGADV_TOUCH_ZOOMIN,
    IMGADV_TOUCH_ZOOMOUT,
    IMGADV_TOUCH_ROTATE,
    IMGADV_TOUCH_LEFT_ARROW,
    IMGADV_TOUCH_RIGHT_ARROW,

    IMGADV_TOUCH_NONE
} imgadv_touch_obj_enum;

typedef enum
{
    IMGADV_DIRECT_EXIT_NONE = 0X00,
    IMGADV_DIRECT_EXIT_VIEWSCRN = 0X01,
    IMGADV_DIRECT_EXIT_VIEWSCRN_EXT = 0X02,
    IMGADV_DIRECT_EXIT_VIEWSCRN_REQUIRE = 0X04,
    IMGADV_DIRECT_EXIT_VIEWSCRN_EXT_REQUIRE = 0X08,
    IMGADV_DIRECT_EXIT_END
} imgadv_direct_exit_enum;


typedef enum
{
    IMGADV_NON_KEY = 0,
    IMGADV_LSK,
    IMGADV_RSK
}imgadv_key_enum;

typedef struct
{
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
    BOOL is_show;
    BOOL is_press;
} imgadv_osd_icon_struct;

typedef struct 
{
	U8 r;
	U8 g;	
	U8 b;		
	U8 style_r;
	U8 style_g;	
	U8 style_b;
	U16 style;	
} imgadv_style_text_struct;

typedef struct
{
	S32 offset_x;
	S32 offset_y;
	S32 width;
	S32 height;
	BOOL	is_show;
} imgadv_osd_title_struct;

typedef struct 
{
    imgadv_osd_icon_struct larrow;
    imgadv_osd_icon_struct rarrow;
    imgadv_osd_title_struct num_count;
    imgadv_osd_icon_struct rotate;
    imgadv_osd_icon_struct zoomin;
    imgadv_osd_icon_struct zoomout;
    imgadv_osd_title_struct title;
}imgadv_osd_layout_struct;

typedef struct
{
    S32 map_offset_x;
    S32 map_offset_y;
    S32 width;
    S32 height;
    S32 wnd_offset_x;
    S32 wnd_offset_y;
    S32 wnd_width;
    S32 wnd_height;
    float ratio_map_to_image;
    float ratio_map_to_thumbnail;
    float ratio_map_to_resized_image;
    float ratio_width_to_height;
    float zoom_factor;
    MMI_BOOL is_zoomin_able;
    MMI_BOOL is_zoomout_able;
    U16 zoom_factor_cnt;
    U16 max_zoom_factor_cnt;
}imgadv_map_struct;

typedef struct 
{
    U8                          imgview_rotate;
    MMI_BOOL                    is_change_image;
    MMI_BOOL                    is_show_filename;
    MMI_BOOL                    is_external_req;
    MMI_BOOL                    is_real_decode;
    MMI_BOOL                    is_rotate_action;
    MMI_BOOL                    is_refreshing;
    MMI_BOOL                    is_truncated;
#ifdef __DRM_SUPPORT__
    FS_HANDLE                   drm_handle;
    U32                         drm_id;
    imgadv_drm_state_enum       drm_state;
    imgadv_drm_ret_enum         drm_valid;
#endif
   imgadv_direct_exit_enum      direct_exit;

    pBOOL                       is_short;
    pBOOL                       is_width_dominate;
    pBOOL                       is_permitted;
    pBOOL                       is_resume;
    pBOOL                       is_gif_file;
    pBOOL                       is_initialized;
    pBOOL                       is_trigger_by_keypad;
    pBOOL                       is_reset_application;
    pBOOL                       is_err_displayed;
    pBOOL                       is_decoding;
    pBOOL                       is_printable;
    pBOOL                       is_decode_timer_on;
    pBOOL                       is_scrolling_title;
    U16                         image_type;
    S32                         image_height;
    S32                         image_width;    
    gdi_handle                  cache_layer_handle;
    imgadv_osd_layout_struct    *active_osd_layout_ptr;
    gdi_handle                  animation_on_tv;
    gdi_handle                  base_layer_handle;
    CHAR                          *buf_filename_no_ext;
    PU8                         cache_buf_ptr;
    S32                         cache_layer_height;
    S32                         cache_layer_width;
    CHAR                          *count_str;
    S32                         error_event;
    CHAR                          *err_str_ptr;
    CHAR                          *ext_filepath;
    CHAR                          *filepath;
    U32                         file_size;    
    gdi_handle                  ivadv_org_bld_layer;

    imgadv_osd_icon_struct      lsk;
    imgadv_map_struct           map;
    gdi_handle                  nb_handle;

    S32                         resized_img_height;
    S32                         resized_img_width;
    GDI_RESULT                  result;
    scrolling_text              scrolling_title;
    PU8                         thumbnail_buf_ptr;
    gdi_handle                  thumbnail_layer_handle;
    S32                         thumbnail_layer_height;    
    S32                         thumbnail_layer_width;
    S32                         total_count;
    S32 truncated_width;
#ifdef __MMI_TVOUT__
    S32                         tvout_width;
#endif
    imgadv_osd_icon_struct      rsk;
#ifdef __MMI_TOUCH_SCREEN__
    S32                         pen_down_x;
    S32                         pen_down_y;
    pBOOL                       is_pen_down;
#endif /* __MMI_TOUCH_SCREEN__ */
    U16                         osd_opacity;

    imgadv_key_enum key_object;
    MMI_BOOL on_icon_pen_down;
    MMI_BOOL                    rotate_able;
    imgadv_touch_obj_enum       touch_object;

}imgadv_context_struct;

#define MMI_IMGADV_OK                0
#define MMI_IMGADV_ERROR            -1
#define MMI_IMGADV_DRM_INVALID      -2
#define MMI_IMGADV_INVALID_FORMAT   -3
#define MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR -4
#define MMI_IMGADV_FIRST_TIME_DECODE_ERR -5

static void mmi_imgadv_create_resource(void);
static void mmi_imgadv_free_resource(void);
static void mmi_imgadv_display_error_sg(mmi_id parent_gid, mmi_imgview_popup_result_process_enum process);
static U8 mmi_imgadv_del_scr_callback(void* ptr);

static void mmi_imgadv_start_decode(void);
static void mmi_imgadv_init_image_info(void);
static void mmi_imgadv_extract_image_to_cache_layer(void);
static void mmi_imgadv_extract_image_to_thumbnail_layer(void);
static void mmi_imgadv_init_key_handler(void);
static void mmi_imgadv_init_default_touch_and_key_handler(void);

static void mmi_imgadv_unlock_filelist(void);
static void mmi_imgadv_init_map_box(void);
static void mmi_imgadv_draw_map(void);
static BOOL mmi_imgadv_zoomin(void);
static BOOL mmi_imgadv_zoomout(void);
static void mmi_imgadv_reenter(void);
static void mmi_imgadv_print_req(void);
static BOOL mmi_imgadv_validate_drm_right(void);

static void mmi_imgadv_zoomin_press(void);
static void mmi_imgadv_zoomin_release(void);
static void mmi_imgadv_zoomout_press(void);
static void mmi_imgadv_zoomout_release(void);
static void mmi_imgadv_rotate_press(void);
static void mmi_imgadv_rotate_release(void);
static void mmi_imgadv_lsk_press(void);
static void mmi_imgadv_lsk_release(void);
static void mmi_imgadv_rsk_press(void);
static void mmi_imgadv_rsk_release(void);
static void mmi_imgadv_move_key_release(void);
static void mmi_imgadv_translate(S32 x, S32 y);
static void mmi_imgadv_move_down_press(void);
static void mmi_imgadv_move_left_press(void);
static void mmi_imgadv_move_up_press(void);
static void mmi_imgadv_move_right_press(void);
static void mmi_imgadv_next_image_press(void);
static void mmi_imgadv_previous_image_press(void);
static void mmi_imgadv_next_image_release(void);
static void mmi_imgadv_previous_image_release(void);
static MMI_BOOL mmi_imgadv_check_jpg_resizer_limitation(void);

static void mmi_imgadv_init_osd_icon_position(void);
static void mmi_imgadv_get_active_osd_cntx(void);
static void mmi_imgadv_draw_osd(void);
static void mmi_imgadv_draw_style_text(imgadv_key_enum key_object, CHAR* str, S32 offset_x, S32 offset_y);
static void mmi_imgadv_draw_softkey(void);
static void mmi_imgadv_draw_num_count(void);
static void mmi_imgadv_strolling_text_redraw_bg(S32 x1, S32 y1, S32 x2, S32 y2);
static void mmi_imgadv_scrolling_text_handle(void);

#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
static void mmi_imgadv_decode_done_callback(GDI_RESULT result, gdi_handle handle);
static void mmi_imgadv_dummy(void);
static void mmi_imgadv_draw_truncated_style_text(CHAR* str, S32 offset_x, S32 offset_y, S32 width);
#endif

#if defined(__MMI_TVOUT__)
static void mmi_imgadv_anim_callback(GDI_RESULT result);
static void mmi_imgadv_tvout_decode(void);
static void mmi_imgadv_tvout_clear_bg(void);
#endif

#if defined(__MMI_TOUCH_SCREEN__)
static BOOL mmi_imgadv_touch_scr_hit_test(S32 pos_x, S32 pos_y, imgadv_osd_icon_struct  *touch_obj);
static void mmi_imgadv_pen_down_hdlr(mmi_pen_point_struct pos);
static void mmi_imgadv_pen_up_hdlr(mmi_pen_point_struct pos);
#ifdef __MTK_TARGET__
static void mmi_imgadv_pen_abort_hdlr(mmi_pen_point_struct pos);
#endif
static void mmi_imgadv_pen_move_hdlr(mmi_pen_point_struct pos);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#if defined(__DRM_SUPPORT__)
static imgadv_drm_ret_enum mmi_imgadv_process_drm_hdlr(void);
static void mmi_imgadv_pause_drm_consume_if_need(void);
static void mmi_imgadv_drm_callback_hdlr(kal_int32 result, kal_int32 id);
#endif
/* CUI part */
static void mmi_imgadv_lsk_custmize_confirmed(void);
static void mmi_imgadv_prefetch_image(MMI_BOOL is_next);

#endif /* __MMI_IMAGE_VIEWER_ADV__ */
#endif /* _IMAGE_VIEWER_ADV_H_ */ 

