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
 *  ImageViewerEXApp.h
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_VIEWER_EX_H_
#define _IMAGE_VIEWER_EX_H_

#include "MMI_features.h"

#include "kal_general_types.h"
#include "fs_type.h"
#include "gdi_datatype.h"
#include "gdi_const.h"
#include "gui_data_types.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_input_gprot.h"

#include "ImageViewerGprot.h"
#include "ImageViewerEXAppGprot.h"
#include "ImageViewerEXSkin.h"

#include "MediaCacheSrvGprot.h"

#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
#include "ImageViewerExSlidingBar.h"
#endif

#if defined(__MMI_REDUCED_KEYPAD__) && defined (__MMI_TOUCH_SCREEN__)
#define __MMI_IMGVIEWEX_TOUCH__
#endif

#if defined(MOTION_SENSOR_SUPPORT)
#ifndef __MULTIPLE_ANGLE_VIEW_SUPPORT__
#define __MMI_IMGVIEWEX_MOTION__
#else
#define __MMI_IMGVIEWEX_MAV_MOTION__
#endif
#include "mdi_datatype.h"       /* mdi datatype, it is necessary, or error for can not find the mdi_result type */
//#include "mdi_motion.h"
#include "sensorSrvGport.h"
#endif

/************************************************************************/
/* Define, Struct, Enum                                                 */
/************************************************************************/
#define MMI_IVEX_DB_START_LIMIT_MAX    (10000)
#define MMI_IVEX_ROUND_ADD_VALUE   (0.99f)  /* Fault-tolerant value, avoid cut edge of image */
#define MMI_IVEX_MAGNIFICATION_VALUE   (1000)  /* Fault-tolerant value */

#define MMI_IVEX_ZOOM_STEP      (5.0f)      /* after zoom in/out once, still cost steps to max/min */
#define MMI_IVEX_FIRST_ZOOMIN_S_STEP      (0.6f)      /* the first step zoom more */
#define MMI_IVEX_FIRST_ZOOMIN_L_STEP      (0.4f)      /* the first step of l(arge) is less than s(mall) to avoid jump */
#define MMI_IVEX_FIRST_ZOOMOUT_S_STEP      (0.7f)      /* the first step zoom more */
#define MMI_IVEX_FIRST_ZOOMOUT_L_STEP      (0.85f)      /* the first step of l(arge) is more than s(mall) to cater for repaid effect */
#define MMI_IVEX_KEY_ZOOM_UNIT      (7)      /* enlarge 1.02^5 when press key once */
#define MMI_IVEX_KEY_MOVE_MIN_UNIT      (12)      /* One key down move image five pixels */
#define MMI_IVEX_KEY_MOVE_MAX_UNIT      (120)      /* One key down move image five pixels */
#define MMI_IVEX_KEY_GROUP_NUM_ALL  (24)
#define MMI_IVEX_SWITCH_FRAME_STEP  (12)
#define MMI_IVEX_SWITCH_PERCENT       (17)

#if defined(__MMI_FTE_SUPPORT__)
#define MMI_IVEX_LOADING_IMAGE_NUMBER       (6)
#else
#define MMI_IVEX_LOADING_IMAGE_NUMBER       (12)
#endif
#define MMI_IVEX_IMAGE_ROTATE_EFFECT_CNT    (4)
#define MMI_IVEX_SWITCH_IMAGE_LIMIT_PERCENT   (20)  /* only the image is draged out more than 20 pixels, it is realy switch to another image */
#define MMI_IVEX_SWITCH_IMAGE_LIMIT_PERCENT_L   (30)  /* only the image is draged out more than 20 pixels, it is realy switch to another image */
#define MMI_IVEX_BOUNCE_SLIDE_STEP   (2)  /* only the image is draged out more than 20 pixels, it is realy switch to another image */
#define MMI_IVEX_AUTO_MOVE_THRESHOLD   (20)  /* only the image is draged out more than 20 pixels, it is realy switch to another image */
#define MMI_IVEX_AUTO_MOVE_TIME_LIMI   (40)

#define MMI_IVEX_DRAW_LOADING_EFFECT_TIMER_INTERVAL     (400)   /* timer */
#define MMI_IVEX_BLT_TO_LCD_TIMER_INTERNAL              (100)     /* timer */
#define MMI_IVEX_DRAW_ROTATE_EFFECT_DURATION            (50)      /* timer */
#define MMI_IVEX_KEY_MOVE_DURATION_1          (300)      /* timer, first longer to cater to single step move */
#define MMI_IVEX_KEY_MOVE_DURATION          (66)      /* timer */
#define MMI_IVEX_PLAY_SWTICH_DURATION       (1000)  /* timer */
#define MMI_IVEX_PLAY_SWTICH_SKIP_DURATION       (400)  /* timer */
#define MMI_IVEX_ZOOM_INTERVAL              (45)  /* timer */
#define MMI_IVEX_SINGLE_CLICK_INTERVAL   (50)  /* timer (ticks) */
#define MMI_IVEX_DOUBLE_CLICK_INTERVAL   (450)  /* timer (ticks) */
#define MMI_IVEX_SINGLE_TAP_VALID_RADIUS   (10)  /* valid radius */
#define MMI_IVEX_DOUBLE_CLICK_VALID_RADIUS   (20)  /* valid radius */

#ifdef __IVEX_SUPPORT_IES__
#define MMI_IVEX_RENDERER_TIMER_DURATION    (66)  /* timer : 33ms ~= 30 fps */
#else
#define MMI_IVEX_RENDERER_TIMER_DURATION    (66)  /* timer : 66ms ~= 15 fps */
#endif
#define MMI_IVEX_SWITCH_EASE_OUT_INTERVAL   (40)  /* timer for slide layer *///[jibin detail]
#define MMI_IVEX_IMAGE_SPACING              (20)  /* interval distance between two layer */

#define MMI_IVEX_OSD_FADE_OPACITY_VALUE     (255)
#define MMI_IVEX_OSD_FADE_OUT_STEP_VALUE    (40)
#define MMI_IVEX_OSD_FADE_IN_STEP_VALUE     (40)
#define MMI_IVEX_OSD_FADE_INTERVAL_VALUE    (32)
#define MMI_IVEX_OSD_FADE_OUT_DURATION      (6 * 1000)  /* timer */
#define MMI_IVEX_OSD_FADE_INTERVAL_DURATION (100)       /* timer */

#define LIMIT_ERROR_STR_LEN    (100)
#define LIMIT_ERROR_BUF_SIZE   ((LIMIT_ERROR_STR_LEN+1)*ENCODING_LENGTH)

/* index of mem_cache in context */
enum{
    MMI_IVEX_SMALL_INDEX = 0,
    MMI_IVEX_LARGE_INDEX,
    MMI_IVEX_LCD_INDEX,
#ifdef __MMI_IMGVIEWEX_DB__
    MMI_IVEX_DB_INDEX,
#endif
    MMI_IVEX_CACHE_TOTAL
};
 
typedef enum
{
    MMI_IVEX_VIEW_STATE_EXIT,
    MMI_IVEX_VIEW_STATE_PAUSE,
    MMI_IVEX_VIEW_STATE_VIEW,
    MMI_IVEX_VIEW_STATE_END
}ivex_view_state_enum;

typedef enum
{
    MMI_IVEX_OSD_STATE_SHOW,
    MMI_IVEX_OSD_STATE_HIDE,
    MMI_IVEX_OSD_STATE_FADE_IN,
    MMI_IVEX_OSD_STATE_FADE_OUT,
    MMI_IVEX_OSD_STATE_SHOW_P2H,
    MMI_IVEX_OSD_STATE_SHOW_H2P,
    MMI_IVEX_OSD_STATE_ARROW_PREV,
    MMI_IVEX_OSD_STATE_ARROW_NEXT,
    MMI_IVEX_OSD_STATE_END
}ivex_osd_state_enum;

typedef enum
{
    MMI_IVEX_IMAGE_STATE_STILL,
    MMI_IVEX_IMAGE_STATE_STILL_P2H,
    MMI_IVEX_IMAGE_STATE_STILL_H2P,
    MMI_IVEX_IMAGE_STATE_SWITCH_PREV,
    MMI_IVEX_IMAGE_STATE_SWITCH_NEXT,
    MMI_IVEX_IMAGE_STATE_PLAY,
    MMI_IVEX_IMAGE_STATE_END
}ivex_image_state_enum;

typedef enum
{
    MMI_IVEX_ROTATE_NONE,
    MMI_IVEX_ROTATE_JUST_CW,
    MMI_IVEX_ROTATE_JUST_CCW
}ivex_rotate_state_enum;

typedef enum
{
    MMI_IVEX_SWITCH_NONE,
    MMI_IVEX_SWITCH_JUST_PRE,
    MMI_IVEX_SWITCH_JUST_NEXT
}ivex_switch_state_enum;

typedef enum
{
    MMI_IVEX_ZOOM_NONE,
    MMI_IVEX_ZOOMIN_TO_MAX,
    MMI_IVEX_ZOOMOUT_TO_MIN
}ivex_zoom_to_limitation_enum;

typedef enum
{
    MMI_IVEX_MOTION_ORIENTATION_NONE,
    MMI_IVEX_MOTION_ORIENTATION_VERTICAL,
    MMI_IVEX_MOTION_ORIENTATION_HORIZONTAL
}ivex_motion_orientation_state_enum;

#if defined(__DRM_SUPPORT__)
typedef enum
{
    MMI_IVEX_DRM_STATE_EXIT,
    MMI_IVEX_DRM_STATE_CONSUME,
    MMI_IVEX_DRM_STATE_PAUSE,
    MMI_IVEX_DRM_STATE_DECODING,
    MMI_IVEX_DRM_STATE_TOTAL_COUNT
}ivex_drm_state_enum;

typedef enum
{
    MMI_IVEX_DRM_RET_NOT_DRM_FILE = 0,
    MMI_IVEX_DRM_RET_DRM_FILE = 0x00000001,
    MMI_IVEX_DRM_RET_DISPLAY_VALID = 0x00000010,
    MMI_IVEX_DRM_RET_PRINT_VALID   = 0x00000100,
    MMI_IVEX_DRM_RET_MULTI_PART   = 0x00001000,
    MMI_IVEX_DRM_RET_MIMETYPE_NON_IMAGE= 0x00010000,
    MMI_IVEX_DRM_RET_DRM_NEED_RIGHT = 0x00100000,
    MMI_IVEX_DRM_RET_OTHER_ERROR = 0x01000000,
    MMI_IVEX_DRM_RET_DRM_NO_PERMISSION = 0x10000000
}ivex_drm_ret_enum;
#endif /* defined(__DRM_SUPPORT__)*/

#ifdef __MMI_TOUCH_SCREEN__
typedef enum
{
    MMI_IVEX_TOUCH_OBJ_RSK = 0,
    MMI_IVEX_TOUCH_OBJ_LSK,
    MMI_IVEX_TOUCH_OBJ_ZOOMIN,
    MMI_IVEX_TOUCH_OBJ_ZOOMOUT,
    MMI_IVEX_TOUCH_OBJ_ROTATE_CCW,
    MMI_IVEX_TOUCH_OBJ_ROTATE_CW,
    MMI_IVEX_TOUCH_OBJ_CENTER_PLAY,
    MMI_IVEX_TOUCH_OBJ_CENTER_STOP_PLAY,
    MMI_IVEX_TOUCH_OBJ_CENTER_SWITCH_UI,
    MMI_IVEX_TOUCH_OBJ_LARROW,
    MMI_IVEX_TOUCH_OBJ_RARROW,
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    MMI_IVEX_TOUCH_OBJ_SLIDING_BAR,
#endif

    MMI_IVEX_TOUCH_OBJ_NONE
} ivex_touch_obj_enum;
#endif

typedef enum
{
    MMI_IVEX_IMG_HEALTH_OK = 0,
    MMI_IVEX_IMG_HEALTH_ERROR =  -1,
    MMI_IVEX_IMG_HEALTH_DRM_INVALID = -2,
    MMI_IVEX_IMG_HEALTH_INVALID_FORMAT = -3,
    MMI_IVEX_IMG_HEALTH_NON_FIRST_DECODE_ERR = -4,
    MMI_IVEX_IMG_HEALTH_FIRST_TIME_DECODE_ERR = -5,
    MMI_IVEX_IMG_HEALTH_DRM_NEED_RIGHT = -6,
    MMI_IVEX_IMG_HEALTH_DRM_GET_RIGHT_FAIL = -7
}ivex_img_health_enum;

typedef enum
{
    MMI_IVEX_ARROW_KEY_DOWN,
    MMI_IVEX_ARROW_KEY_UP,
    MMI_IVEX_ARROW_KEY_RIGHT,
    MMI_IVEX_ARROW_KEY_LEFT
}ivex_arrow_key_orientation_enum;

typedef enum
{
    MMI_IVEX_SWITCH_AXIS_NONE,
    MMI_IVEX_SWITCH_AXIS_X,
    MMI_IVEX_SWITCH_AXIS_Y
}ivex_switch_axis_enum;

typedef enum
{
    MMI_IVEX_REDECODE_CASE_NONE,
    MMI_IVEX_REDECODE_CASE_BUSY,
    MMI_IVEX_REDECODE_CASE_BUSY_OVER,
    MMI_IVEX_REDECODE_CASE_ERROR,
    MMI_IVEX_REDECODE_CASE_FROM_DB,
    MMI_IVEX_REDECODE_CASE_LARGE_OK,
    MMI_IVEX_REDECODE_CASE_END
}ivex_redecode_case_enum;

typedef enum
{
    MMI_IVEX_MEMORY_TYPE_NONE,
    MMI_IVEX_MEMORY_TYPE_MED,
    MMI_IVEX_MEMORY_TYPE_APP_BASED,
    MMI_IVEX_MEMORY_TYPE_SCREEN_BASED,
    MMI_IVEX_MEMORY_TYPE_END
} ivex_memory_type_enum;

typedef enum
{
    MMI_IVEX_DIRECT_EXIT_NONE = 0X00,
    MMI_IVEX_DIRECT_EXIT_VIEWSCRN = 0X01,
    MMI_IVEX_DIRECT_EXIT_VIEWSCRN_EXT = 0X02,
    MMI_IVEX_DIRECT_EXIT_HELPSCRN = 0X04,
    MMI_IVEX_DIRECT_EXIT_INFOSCRN = 0X08,
    MMI_IVEX_DIRECT_EXIT_END
} ivex_direct_exit_enum;

/*typedef enum
{
    MMI_IVEX_SETTINGS_SPEED_CAP,
    MMI_IVEX_SETTINGS_SPEED,
    MMI_IVEX_SETTINGS_NUM
} ivex_settings_item_enum;*/

typedef enum
{
    MMI_IVEX_SPEED_LOW,
    MMI_IVEX_SPEED_NORMAL,
    MMI_IVEX_SPEED_FAST,
    MMI_IVEX_SPEED_NUM
} ivex_speed_grade_enum;

typedef enum
{
    MMI_IVEX_SPEED_CONST_1S = 1,
    MMI_IVEX_SPEED_CONST_3S = 3,
    MMI_IVEX_SPEED_CONST_5S = 5,
    MMI_IVEX_SPEED_CONST_NUM
} ivex_speed_const_enum;

#ifdef __IVEX_SUPPORT_IES__
typedef enum
{
    MMI_IVEX_caps_stop_animate,
    MMI_IVEX_caps_running_animate,
    MMI_IVEX_caps_rotation,
    MMI_IVEX_caps_move,
    MMI_IVEX_caps_display
}ivex_caps_enum;
#endif /* __IVEX_SUPPORT_IES__ */

typedef enum
{
    MMI_IVEX_FILE_STATE_NONE,  /* please never use */
    MMI_IVEX_FILE_STATE_LOADING,
    MMI_IVEX_FILE_STATE_READY,
    MMI_IVEX_FILE_STATE_END
}ivex_file_state_enum;

typedef struct
{
    S32 filelist_index;           /* the image index in filelist */
    S32 original_width;         /* original image width */
    S32 original_height;
    S32 resized_width;         /* resized image width of being shown */
    S32 resized_height;
    S32 resized_image_width; /* resized image dimension */
    S32 resized_image_height;
    S32 resized_offset_x;    /* offset x relative resized image, from here to draw image */
    S32 resized_offset_y;
    S32 draw_offset_x;        /* the offset x to draw layer (LCD) */
    S32 draw_offset_y;
    S32 center_x;
    S32 center_y;
    gdi_handle handle;     /* animation/mav decode handle */
    U16 image_type;             /* image type */
    CHAR   *filepath;                 /* image file path */
    GDI_RESULT result;         /* the result of parsing image */
    CHAR* err_str_ptr;             /* error string pointer */
    U16 err_img_id;             /* the image id of the effect when error hanppened */

#ifdef __DRM_SUPPORT__
    S32 drm_id;
    FS_HANDLE drm_handle;
    ivex_drm_state_enum drm_state;
    ivex_drm_ret_enum    drm_valid;
#endif

    float min_zoom_factor; /* factor of the first show panorama, in fact it is zoom out rate, it must be <= 1 */
    float max_zoom_factor;
    float zoom_factor;               /* when move one pixel, zoom rate */
    float curr_zoom_factor;      /* current shown image zoom out rate, it is also must <=1 */
    U16 zoom_cnt;

    U8 loading_hint_index;                 /* loading hint image index */
    MMI_BOOL is_loading;                    /* this image is under deconding state and show loading errect */

    MMI_BOOL need_drm_right;
    MMI_BOOL is_drm;
    MMI_BOOL is_zoomin_able;
    MMI_BOOL is_zoomout_able;
    MMI_BOOL is_printable;
    MMI_BOOL is_err;          /* if error happened */
    MMI_BOOL is_animation;          /* if is animation */
    MMI_BOOL is_anim_done;
    MMI_BOOL is_first_ok;          /* if decode the first frame is ok for animation/mav */
    MMI_BOOL is_from_l1;        /* is the image is already from L1 */
    ivex_file_state_enum file_state;    /* indicate the file is ready or not */

#ifdef __IVEX_SUPPORT_IES__
    float CAPS_zoom_progrss;
    float CAPS_zoom_level;
    float CAPS_max_level;
    ivex_caps_enum CAPS_flag;
    int CAPS_rotation_step;
    int CAPS_move_x;
    int CAPS_move_y;
    S32 fit_screen_height;
    S32 fit_screen_width;
    
#endif /* __IVEX_SUPPORT_IES__ */

#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    MMI_BOOL is_mav;
    MMI_BOOL is_mav_decoding;
    S32 mav_current_frame;
    S32 mav_total_frames;
#endif
}ivex_image_info_struct;

typedef struct
{
    void *buffer;
    S32 size;
    ivex_memory_type_enum    type;
}ivex_memory_struct;

typedef struct
{
    U16 interval_sec;
} ivex_settings_nvram_struct;

typedef struct
{
    gdi_handle temp_layer_handle;  /* App display image layer */
    PU8        temp_layer_buffer;
    S32        temp_layer_buffer_size;
} ivex_temp_layer_struct;

#ifdef __MMI_IMGVIEWEX_MAV_MOTION__
typedef enum
{
    MAV_MOTION_DIRECTION_NONE,
    MAV_MOTION_DIRECTION_NEXT,
    MAV_MOTION_DIRECTION_PREV,
} ivex_mav_motion_direction;
#endif

typedef struct
{
    S32 total_image_count;                  /* total image number */
    ivex_image_info_struct   image_info;    /* image info */
    ivex_image_info_struct   switch_image_info; /* switch image info */
    ivex_osd_layout_struct *active_osd_layout_ptr;
    ivex_settings_nvram_struct ivex_settings;
    ivex_temp_layer_struct temp_display_layer;
    S32 speed_index;
    mmi_id settings_cui_inline_gid;

    S32 view_layer_height;
    S32 view_layer_width;
    S32 switch_layer_height;
    S32 switch_layer_width;
    CHAR   *title_str;
    gdi_handle display_layer_handle;  /* App display image layer */
    gdi_handle switch_layer_handle;   /* App switch image layer */
    gdi_handle osd_title_layer;     /* switch icon used */
    gdi_handle osd_panel_layer;       /* softkey and zoom used */
    PU8 app_layer_buf_ptr;
    U16 osd_opacity;                  /* osd layer fade out value */
    U16 osd_fade_percent;             /* osd layer fade out value */
    S32 display_layer_last_offset_x;  /* last location, the x is in view layer's axis, it means relative coordinate */
    S32 display_layer_last_offset_y;  /* last location, when ui is different orientation with image layer */
    S32 percent_numerator;                /* how many percent the layer offset is in ext ui width */
    S32 abs_move_offset_x;               /* the movement in screen movement, this will remember how may pixels the layer will move actually, this is screen coordinate */
    S32 abs_move_offset_y;              /* the movement in screen movement, this will remember how may pixels the layer will move actually */
    S32 play_skip_number;                /* play skip number */
    U8  switch_frame_index;           /* remember the index of slide in frame or rotate */
    U8  view_image_rotate;            /* image rotate angle */
    U8  ui_display_rotate;            /* ui rotate angle */
    U8  switch_frame_precent;         /* remember the index of slide in frame or rotate */
    U8  renderer_ref_count;           /* render count */
    U8  redecode_time;           /* if decode error, but the small is ok, should be try to decode large*/

    S32 iv_limit_width;      /* zoom limitation from ivsrv */
    S32 iv_limit_height;

    S32 roxbr;                        /* Resized Offset X Before Rotate */
    S32 roybr;                        /* Resized Offset Y Before Rotate */
    S32 drwbr;                        /* Draw Resize Width Before Rotate */
    S32 drhbr;                        /* Draw Resize Height Before Rotate */
    S32 doxbr;                        /* Draw Offset X Before Rotate */
    S32 doybr;                        /* Draw Offset Y Before Rotate */
    float czfbr;                      /* Current Zoom Factor Before Rotate */
    float ozfbr;                      /* Original Zoom Factor Before Rotate */
    U16 zcbr;                         /* Zoom Count Before Rotate */
    ivex_rotate_state_enum rot_oriention; /* rotate orientation */
    ivex_switch_state_enum switch_orientation; /* switch orientation */
    ivex_zoom_to_limitation_enum zoom_orientation; /* zoom to limitation */
    MMI_BOOL is_switch_two;      /* remember if touch next key twice continuously */

    MMI_BOOL image_rotated;

    void *app_mem_pool;
    U32  app_mem_size;
    void *app_adm_id;

    U16 caller_app_id;
    mmi_id option_cui_menu_gid;
    U16 option_send_menu_id;
    U16 option_send_child_index;
    U16 option_use_menu_id;
    U16 option_use_child_index;

    ivex_memory_struct mem_cache[MMI_IVEX_CACHE_TOTAL];  /* see MMI_IVEX_xxx_INDEX */
    ivex_memory_struct mem_osd_title;  /* Screen memory */
    ivex_memory_struct mem_osd_panel;    /* Screen memory */
    CHAR* info_h_buffer;
#ifdef __MMI_IMGVIEWEX_DB__
    CHAR   *filepath;                 /* image file path */
    MMI_BOOL is_db_start;
#endif

#ifdef __MMI_TOUCH_SCREEN__
    ivex_touch_obj_enum       touch_object;
    S32              pen_down_x;
    S32              pen_down_y;
    S32              pen_move_x;
    S32              pen_move_y;
    U32              pen_move_time1;
    U32              pen_move_interval;
    S16              double1_x;
    S16              double1_y;
    U32              start_ticks_1;
    U32              start_ticks_2;
    ivex_switch_state_enum pen_switch_orientation; /* last switch orientation */
    MMI_BOOL          is_pen_down;
    MMI_BOOL    is_pen_down_zoom;
    MMI_BOOL    is_double_click;
    MMI_BOOL    is_pen_move;
    MMI_BOOL    is_pen_down_on_switch;
    MMI_BOOL    is_auto_move;
#endif /* __MMI_TOUCH_SCREEN__ */

#ifdef __MMI_IMGVIEWEX_MOTION__
    MMI_BOOL is_register_mcb;             /* if register motion control */
    mdi_handle motion_handle;             /* if register motion control */
    U8 mot_ui_state;                             /* the UI state from motion check */
#endif
#ifdef __MMI_IMGVIEWEX_MAV_MOTION__
    mdi_handle mav_motion_handle;             /* if register motion control */
#endif

    ivex_view_state_enum view_state;      /* view state */
    ivex_osd_state_enum   osd_state;      /* current osd state */
    ivex_image_state_enum image_state;    /* current image state */
    ivex_image_state_enum pre_image_state;/* previous state */
    ivex_direct_exit_enum       direct_exit;
    MMI_BOOL is_fading;                   /* not switch image successfully and come back to the original image */
    MMI_BOOL is_spring;                   /* not switch image successfully and come back to the original image */
    MMI_BOOL is_move_two;                 /* if move two image by pen */
    MMI_BOOL is_resume;                   /* if come back from history */
    MMI_BOOL key_press;                   /* if key pressed */
    MMI_BOOL key_first_move;                   /* if key pressed */
    MMI_BOOL ui_rotating;                 /* if key pressed */
    MMI_BOOL play_switch_done;            /* if switch is done under play state */
    MMI_BOOL is_play_start;                /* if user start play, it is for non-motion */
    MMI_BOOL is_play_stop;                /* if user stop play */
    MMI_BOOL view_from_fmgr;
    MMI_BOOL view_one_from_other_app;
    MMI_BOOL is_card_out;
    MMI_BOOL is_zoomin;
    MMI_BOOL is_zoomout;
    srv_handle srv_mediacache_handle;
    CHAR *srv_mediacache_run_buffer;
#ifdef __IVEX_SUPPORT_IES__
    MMI_BOOL is_scalado_anim;
    float    Caps_step;
    CHAR       *p_ies_work_buf;
#endif //__IVEX_SUPPORT_IES__

#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    ivex_memory_struct mem_osd_sliding_bar;    /* Screen memory */
    SlidingBar osd_sliding_bar;
#ifdef __MMI_IMGVIEWEX_MAV_MOTION__
    MMI_BOOL mav_motion_is_enabled;
    ivex_mav_motion_direction mav_motion_direction;
    MMI_BOOL mav_motion_pulse_started;
    S32 mav_motion_angle_x; /* -1 means invalid */
    S32 mav_motion_angle_y;
    S32 mav_motion_angle_z;
#endif /* __MMI_IMGVIEWEX_MAV_MOTION__ */
#endif /* __MULTIPLE_ANGLE_VIEW_SUPPORT__ */
}ivex_context_struct;

static void mmi_ivex_entry_view_screen(void);
static void mmi_ivex_asm_stop_cb(void);
static void mmi_ivex_get_image_base_info(S32 fl_index, MMI_BOOL is_disp_img, ivex_image_info_struct *img_info);
static void mmi_ivex_reset_image_info(ivex_image_info_struct *img_info);
static void mmi_ivex_init_osd_icon_info(void);
static void mmi_ivex_get_active_osd_cntx(void);
static void mmi_ivex_draw_osd_title_layer(void);
static void mmi_ivex_draw_osd_panel_layer(void);

static void mmi_ivex_init_image_display_info(ivex_image_info_struct *img_info, MMI_BOOL is_switch);
static void mmi_ivex_init_key_handler(void);
static void mmi_ivex_init_pen_event_handler(void);
static void mmi_ivex_get_curr_img_callback(S32 err_group, S32 err_code,  void *user_data);
static void mmi_ivex_get_one_img_callback(S32 err_group, S32 err_code,  void *user_data);
static float mmi_ivex_calculate_real_zoom_factor(float base, U16 index);
static void mmi_ivex_get_image_gdi_limit_value(U16 image_type, S32 *width, S32 *height);
static void mmi_ivex_display_error_sg(mmi_id parent_gid, UI_string_type str_ptr, mmi_event_notify_enum event, U16 rotate, mmi_imgview_popup_result_process_enum process);
static void mmi_ivex_draw_drm_effect(gdi_handle draw_layer_hdlr, MMI_BOOL is_switch);
static void mmi_ivex_draw_err_effect(gdi_handle draw_layer_hdlr, MMI_BOOL is_switch);
static void mmi_ivex_view_layers_and_imginfo_switch(void);
static void mmi_ivex_osd_fade_out_cyclic(void);
static void mmi_ivex_osd_fade_in_cyclic(void);
static void mmi_ivex_prepare_rotate_reduce_image(void);
static void mmi_ivex_prepare_rotate_increase_image(void);
static void mmi_ivex_prepare_rotate_reduce_image_to_half(void);
static void mmi_ivex_prepare_rotate_increase_image_to_full(void);
static void mmi_ivex_restore_image_info_for_interrupt_rotate_to_full(ivex_image_info_struct* img_info);
static void mmi_ivex_save_image_info_for_interrupt_rotate(ivex_image_info_struct* img_info);
static U16 mmi_ivex_calculate_zoom_cnt(float base, float curr);
static void mmi_ivex_move_up_press(void);
static void mmi_ivex_move_down_press(void);
static void mmi_ivex_move_left_press(void);
static void mmi_ivex_move_right_press(void);
static void mmi_ivex_update_enlarged_image_info(mmi_pen_point_struct pos);
static MMI_BOOL mmi_ivex_if_start_slide_cyclic(ivex_image_state_enum img_state, ivex_image_info_struct *img_info, MMI_BOOL is_stop);
static void mmi_ivex_start_slide_cyclic(void);
static void mmi_ivex_play_slide_cyclic(void);
static void mmi_ivex_change_play_index(void);
static void mmi_ivex_curr_img_draw_loading_effect(void);
static void mmi_ivex_curr_img_draw_error_effect(void);
static void mmi_ivex_zoomin_cyclic(void);
static void mmi_ivex_zoomout_cyclic(void);
static void mmi_ivex_rotate_cw_release(void);
static void mmi_ivex_rotate_ccw_release(void);
static void mmi_ivex_stop_anim_if_need(ivex_image_info_struct* img_info, gdi_handle layer_handle);
static void mmi_ivex_draw_animation_file(ivex_image_info_struct* img_info);
static void mmi_ivex_process_curr_image_decode_abnormal(S32 ret);
static void mmi_ivex_process_switch_image_decode_abnormal(S32 ret);
static S32 mmi_ivex_get_ext_ui_width(void);
static S32 mmi_ivex_animator_ease_out(S32 cur_percent);
static U8 mmi_ivex_get_ease_out_percent(U8 ui_angle, U8 view_angle, S32 distance_x, S32 distance_y);
static void mmi_ivex_start_renderer(void);
static void mmi_ivex_stop_renderer(void);
static MMI_BOOL mmi_ivex_switch_next_ease_out(void);
static MMI_BOOL mmi_ivex_switch_previous_ease_out(void);
static void mmi_ivex_switch_previous_image_for_key(void);
static void mmi_ivex_switch_next_image_for_key(void);
static void mmi_ivex_process_abnormal_image(gdi_handle layer_handle, ivex_image_info_struct *img_info, MMI_BOOL is_switch);
static void mmi_ivex_switch_next_cyclic(void);
static void mmi_ivex_switch_previous_cyclic(void);
static void mmi_ivex_next_image_release(void);
static void mmi_ivex_previous_image_release(void);
static void mmi_ivex_stop_move(void);
static void mmi_ivex_start_curr_loading_effect(void);
static void mmi_ivex_stop_curr_loading_effect(void);
static void mmi_ivex_start_switch_loading_effect(void);
static void mmi_ivex_stop_switch_loading_effect(void);
static void mmi_ivex_start_switch_pre(void);
static void mmi_ivex_stop_switch_pre(void);
static void mmi_ivex_start_switch_next(void);
static void mmi_ivex_stop_switch_next(void);
static void mmi_ivex_start_zoomin(void);
static void mmi_ivex_stop_zoomin(void);
static void mmi_ivex_start_zoomout(void);
static void mmi_ivex_stop_zoomout(void);
static void mmi_ivex_shortcut_zoom_start_hdlr(void);
static void mmi_ivex_shortcut_zoom_stop_hdlr(void);
static void mmi_ivex_start_rotate(void);
static void mmi_ivex_stop_rotate(void);
static void mmi_ivex_start_play(void);
static void mmi_ivex_sleep_play(void);
static void mmi_ivex_stop_play(void);
static void mmi_ivex_start_osd_fade_out(void);
static void mmi_ivex_stop_osd_fade_out(void);
static void mmi_ivex_start_osd_fade_in(void);
static void mmi_ivex_stop_osd_fade_in(void);
static void mmi_ivex_stop_renderer_cyclic(void);
static void mmi_ivex_enable_osd_fade(MMI_BOOL is_start);
static void mmi_ivex_left_arrow_key_down_hdlr(void);
static void mmi_ivex_group_key_hdlr(void);
static void mmi_ivex_osd_fade_update_position(void);
static void mmi_ivex_set_zoomable_after_rotate(void);
static void mmi_ivex_disable_image_zoomable(ivex_image_info_struct *img_info);
static void mmi_ivex_entry_view_screen_ext(void);
static U8 mmi_ivex_get_curr_img_switch_axis_orien(U8 ui_angle, U8 view_angle);
static S32 mmi_ivex_get_view_switch_distance(U8 ui_angle, U8 view_angle, S32 distance_x, S32 distance_y, MMI_BOOL is_abs);
static MMI_BOOL mmi_ivex_reach_large_image_edge(U8 ui_angle,
                                                    U8 view_angle,
                                                    ivex_arrow_key_orientation_enum orientation,
                                                    ivex_image_info_struct *img_info);
static void mmi_ivex_get_changed_view_switch_distance(S32 abs_axis_dis, S32 abs_axis_move, S32* layer_offset);
static S32 mmi_ivex_convert_view_layer_offset_to_abs_axis_distance(S32 layer_offset);
static void mmi_ivex_adjust_to_align_motion(void);
static void mmi_ivex_layer_reset_switch_layer_info(gdi_handle layer_handler);
static MMI_BOOL mmi_ivex_entry_ivex_is_prohibit(void);
static MMI_BOOL mmi_ivex_is_file_exist(CHAR *file_path, FS_HANDLE *fs_hdlr);
static MMI_BOOL mmi_ivex_non_move_axis_is_bounce_ava(U8 orient);
static void mmi_ivex_util_read_settings_data(void);
static void mmi_ivex_view_option_entry_settings_screen(void);
static void mmi_ivex_remove_app_mem_cache_and_adm_mem(void);
static mmi_ret mmi_ivex_load_file_proc(mmi_event_struct *param);
static void mmi_ivex_draw_curr_loading_effect(void);

/* Image view CUI part */
static MMI_BOOL mmi_ivex_lsk_custmize_is_enable(void);
static void mmi_ivex_lsk_custmize_confirmed(void);
static void mmi_ivex_prefetch_image(MMI_BOOL is_next);
static GDI_RESULT mmi_ivex_draw_alpha_bmp_id_nb_concurrent(
    gdi_handle dst_layer,
    S32 dst_layer_x,
    S32 dst_layer_y,
    gdi_handle src_layer,
    U16 ImageId);


#if defined(__DRM_SUPPORT__)
static void mmi_ivex_drm_consume_rights(ivex_image_info_struct* img_info, MMI_BOOL is_resume);
static void mmi_ivex_start_drm_consume(ivex_image_info_struct* img_info);
static void mmi_ivex_pause_drm_consume(ivex_image_info_struct* img_info);
static void mmi_ivex_resume_drm_consume(ivex_image_info_struct* img_info, MMI_BOOL is_resume);
static void mmi_ivex_stop_drm_consume(void);
static void mmi_ivex_drm_callback_hdlr(kal_int32 result, kal_int32 id);
static void mmi_ivex_check_file_drm_right(ivex_image_info_struct *img_info);
static ivex_drm_ret_enum mmi_ivex_process_drm_hdlr(ivex_image_info_struct *img_info);
#endif
#if defined(__MMI_TOUCH_SCREEN__)
static void mmi_ivex_shortcut_osd_hide_unhide_switch(void);
static MMI_BOOL mmi_ivex_pen_move_is_valid(void);
static void mmi_ivex_stop_rebound_back(void);
static void mmi_ivex_non_move_axis_stop_bounce(void);
static void mmi_ivex_stop_auto_move(void);
static void mmi_ivex_pen_up_and_rebound_current_image(void);
static MMI_BOOL mmi_ivex_get_image_and_set_state(S32 offset, S32 move_dis);
static MMI_BOOL mmi_ivex_protect_gesture_switch(ivex_image_state_enum image_state);
#endif
#if defined(__MMI_IMGVIEWEX_MOTION__)
static void mmi_ivex_start_listen_motion(void);
static void mmi_ivex_stop_listen_motion(void);
//static void mmi_ivex_rotate_image_tilt_callback(mdi_motion_angle_enum direct,
 //                                                                             mdi_motion_action_enum action,
 //                                                                             mdi_motion_tilt_detail_struct *detail,
  //                                                                            void *user_data);

void mmi_ivex_rotate_image_tilt_callback(
        srv_sensor_type_enum sensor_type,
        void *sensor_data,
        void *user_data  );
#endif /* __MMI_IMGVIEWEX_MOTION__ */
#endif /* _IMAGE_VIEWER_ADV_H_ */

