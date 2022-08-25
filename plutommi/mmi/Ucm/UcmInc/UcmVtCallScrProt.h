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

/*******************************************************************************
 * Filename:
 * ---------
 *   VTCallScrProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video Telephony Call Screen Prototype
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef VT_CALL_SCR_PROT_H
#define VT_CALL_SCR_PROT_H

#include "MMI_features.h"
#ifdef __MMI_VIDEO_TELEPHONY__

/***************************************************************************** 
 * Feature Define
 *****************************************************************************/
//#define __MMI_UCM_VT_FEATURE_AUD_REC__
#ifdef __MMI_TOUCH_SCREEN__
    #define __MMI_VTCS_FEATURE_TOUCH__
#endif

//#define __MMI_VTCS_FEATURE_TIME_PANEL_DUAL_LINE__

#ifdef DUAL_CAMERA_SUPPORT
#define __MMI_UCM_VT_DUAL_CAMERA__
#endif 

#ifdef __MMI_FTE_SUPPORT__
    #define __MMI_VTCS_FTE__
#endif

#ifdef __OP01__
    #define __MMI_VTCS_OP01__ 
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/


#define MMI_VTCS_CAMERA_KEY       (KEY_1)
#define MMI_VTCS_MIC_KEY          (KEY_2)
#define MMI_VTCS_SPEAKER_KEY      (KEY_3)
#define MMI_VTCS_AUD_REC_KEY      (KEY_4)
#define MMI_VTCS_EV_INC_KEY       (KEY_RIGHT_ARROW)
#define MMI_VTCS_EV_DEC_KEY       (KEY_LEFT_ARROW)
#define MMI_VTCS_ZOOM_IN_KEY      (KEY_UP_ARROW)
#define MMI_VTCS_ZOOM_OUT_KEY     (KEY_DOWN_ARROW)
#define MMI_VTCS_VOL_UP_KEY       (KEY_VOL_UP)
#define MMI_VTCS_VOL_DOWN_KEY     (KEY_VOL_DOWN)
    
#define MMI_VTCS_CTRL_PANEL_RESTORE_DUR   (1500)   /* control panel will restore to timer after 1.5sec */

#define MMI_VTCS_TITLE_LEN          (50) 
#define MMI_VTCS_TITLE_BUF_SIZE     ((MMI_VTCS_TITLE_LEN + 1) * ENCODING_LENGTH)

#define MMI_VTCS_COST_LEN           (30) 
#define MMI_VTCS_COST_BUF_SIZE      ((MMI_VTCS_COST_LEN + 1) * ENCODING_LENGTH)

#define MMI_VTCS_INPUT_BOX_LEN         (50) 
#define MMI_VTCS_INPUT_BOX_BUF_SIZE    ((MMI_VTCS_INPUT_BOX_LEN + 1) * ENCODING_LENGTH)

/* colors */
#define MMI_VTCS_TEXT_COLOR                                 \
            (gui_color(g_mmi_vtcs_skin_cntx.text_color.r,   \
                       g_mmi_vtcs_skin_cntx.text_color.g,   \
                       g_mmi_vtcs_skin_cntx.text_color.b))
                       
#define MMI_VTCS_TEXT_BORDER_COLOR                                  \
            (gui_color(g_mmi_vtcs_skin_cntx.text_color.border_r,    \
                       g_mmi_vtcs_skin_cntx.text_color.border_g,    \
                       g_mmi_vtcs_skin_cntx.text_color.border_b))
                       
#define MMI_VTCS_WND_BG_GDI_COLOR       (gdi_act_color_from_rgb(255, 0, 0, 0))  

#define MMI_VTCS_DTMF_KEY_NO              (13)

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/* TODO: move to vt */
typedef enum
{
    MMI_VT_EV_N4 = 0,
    MMI_VT_EV_N3,
    MMI_VT_EV_N2,
    MMI_VT_EV_N1,
    MMI_VT_EV_0,
    MMI_VT_EV_P1,
    MMI_VT_EV_P2,
    MMI_VT_EV_P3,    
    MMI_VT_EV_P4,

    MMI_VT_EV_TOTAL
} mmi_vt_ev_enum;


typedef enum
{
    MMI_VT_VOL_0 = 0,
    MMI_VT_VOL_1,
    MMI_VT_VOL_2,
    MMI_VT_VOL_3,
    MMI_VT_VOL_4,
    MMI_VT_VOL_5,
    MMI_VT_VOL_6,
    
    MMI_VT_VOL_TOTAL
} mmi_vt_vol_enum;

typedef enum
{
    /* TODO: can add more if needed */
    MMI_VT_ZOOM_10X = 0,
    MMI_VT_ZOOM_15X,
    MMI_VT_ZOOM_20X,
    MMI_VT_ZOOM_25X,    
    MMI_VT_ZOOM_30X,        
    MMI_VT_ZOOM_35X,
    MMI_VT_ZOOM_40X,    
    
    MMI_VT_ZOOM_TOTAL
} mmi_vt_zoom_enum;

typedef enum
{
    MMI_VT_VIDEO_QUALITY_SMOOTH,
    MMI_VT_VIDEO_QUALITY_NORMAL,
    MMI_VT_VIDEO_QUALITY_SHARP,
    MMI_VT_VIDEO_QUALITY_END_OF_ENUM
} mmi_vt_video_quality_enum;

typedef enum
{
    MMI_VT_NIGHT_MODE_OFF,
    MMI_VT_NIGHT_MODE_ON,
    MMI_VT_NIGHT_MODE_ENUM
} mmi_vt_night_mode;

typedef enum
{
    MMI_VT_CAM_ROTATE_0,
    MMI_VT_CAM_ROTATE_0_MIRROR,

    MMI_VT_CAM_ROTATE_TOTAL
} mmi_vt_cam_rotate_enum;


typedef enum
{
    MMI_VT_ENC_SIZE_QCIF,  /* default */  
    MMI_VT_ENC_SIZE_SQCIF,

    MMI_VT_ENC_SIZE_TOTAL
} mmi_vt_enc_size_enum;

typedef enum
{
    MMI_VT_HAND_HELD,
    MMI_VT_HAND_FREE,

    MMI_VT_HAND_TOTAL
} mmi_vt_hand_enum;


typedef enum
{
    MMI_VT_CAMERA_OFF,
    MMI_VT_CAMERA_ON,
    MMI_VT_CAMERA_FRONT,
    MMI_VT_CAMERA_BACK    
} mmi_vt_camera_enum;

typedef enum
{
    MMI_VT_NIGHT_OFF,
    MMI_VT_NIGHT_ON
} mmi_vt_night_mode_enum;

typedef enum
{
    MMI_VT_MIC_OFF,
    MMI_VT_MIC_ON
} mmi_vt_mic_enum;

typedef enum
{
    MMI_VT_SPEAKER_OFF,
    MMI_VT_SPEAKER_ON
} mmi_vt_speaker_enum;

typedef enum
{
    MMI_VT_CONTRAST_NORMAL,
    MMI_VT_CONTRAST_REDUCE,
    MMI_VT_CONTRAST_ENHANCE
    
} mmi_vt_contrast_enum;

typedef enum
{
    MMI_VT_BRIGHTNESS_LEVEL0,
    MMI_VT_BRIGHTNESS_LEVEL1,
    MMI_VT_BRIGHTNESS_LEVEL2,
    MMI_VT_BRIGHTNESS_LEVEL3,    
    MMI_VT_BRIGHTNESS_LEVEL4,    
    MMI_VT_BRIGHTNESS_LEVEL5
    
} mmi_vt_brightness_enum;


typedef enum
{
    MMI_VT_AUD_REC_OFF,
    MMI_VT_AUD_REC_ON
} mmi_vt_aud_rec_enum;


typedef struct
{
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
    MMI_BOOL is_press;
    MMI_BOOL is_usable;
} mmi_vtcs_touch_struct;

typedef enum
{
    MMI_VTCS_PANEL_STATE_TIME_ICON,     /* time      / icon */
    MMI_VTCS_PANEL_STATE_SCROLL_EV,     /* ev text   / scroll */
    MMI_VTCS_PANEL_STATE_SCROLL_ZOOM,   /* zoom text / scroll */
    MMI_VTCS_PANEL_STATE_SCROLL_VOL,    /* vol text  / scroll */     
    MMI_VTCS_PANEL_STATE_USER_INPUT_VK, /* input box / vk */

    MMI_VTCS_CTRL_PANEL_STATE_TOTAL    
} mmi_vtcs_panel_state_enum;

typedef enum
{
    MMI_VTCS_LOCAL_IMG_NONE,            /* none */
    MMI_VTCS_LOCAL_IMG_DEFAULT_ID,      /* default image */
    MMI_VTCS_LOCAL_IMG_USER_ID,         /* user id */
    MMI_VTCS_LOCAL_IMG_USER_FILE,       /* user file */

    MMI_VTCS_LOCAL_IMG_TOTAL
} mmi_vtcs_local_img_enum;

typedef enum
{
    MMI_VTCS_TOUCH_NONE,
    MMI_VTCS_TOUCH_EV,
    MMI_VTCS_TOUCH_ZOOM,
    MMI_VTCS_TOUCH_CAMERA,
    MMI_VTCS_TOUCH_MIC,
    MMI_VTCS_TOUCH_SPEAKER,
    MMI_VTCS_TOUCH_AUD_REC,
    MMI_VTCS_TOUCH_SNAPSHOT,    
    MMI_VTCS_TOUCH_BRIGHTNESS_UP,    
    MMI_VTCS_TOUCH_BRIGHTNESS_DOWN,    
    MMI_VTCS_TOUCH_CONTRAST,        
    MMI_VTCS_TOUCH_FULLSCREEN,        
    MMI_VTCS_TOUCH_VK,        
    MMI_VTCS_TOUCH_LSK,
    MMI_VTCS_TOUCH_RSK,
    MMI_VTCS_TOUCH_INC,
    MMI_VTCS_TOUCH_DEC,    
    MMI_VTCS_TOUCH_SLIDER,
    MMI_VTCS_TOUCH_VK_0,    
    MMI_VTCS_TOUCH_VK_1,    
    MMI_VTCS_TOUCH_VK_2,        
    MMI_VTCS_TOUCH_VK_3,
    MMI_VTCS_TOUCH_VK_4,
    MMI_VTCS_TOUCH_VK_5,
    MMI_VTCS_TOUCH_VK_6,
    MMI_VTCS_TOUCH_VK_7,
    MMI_VTCS_TOUCH_VK_8,
    MMI_VTCS_TOUCH_VK_9,
    MMI_VTCS_TOUCH_VK_STAR,
    MMI_VTCS_TOUCH_VK_POUND
    
} mmi_vtcs_touch_obj_enum;


/*         
 *             Main Window      Sub Window      Note
 * ----------------------------------------------------------------------------
 * MODE 1      Peer Video       Local Video     Encode video to peer
 * MODE 2      Local Video      Peer Video      Encode video to peer
 * MODE 3      Peer Video       Local Image     Encode image to peer
 * MODE 4      Local Image      Peer Video      Encode image to peer 
 * MODE 5      Peer Image       Local Video     Preview only 
 * MODE 6      Local Video      Peer Image      Preview only
 * MODE 7      Peer Image       Local Image     No preview
 * MODE 8      Local Image      Peer Image      No preview
  */

typedef enum 
{
    MMI_VTCS_DISPLAY_MODE_NONE,
    MMI_VTCS_DISPLAY_MODE_1,
    MMI_VTCS_DISPLAY_MODE_2,
    MMI_VTCS_DISPLAY_MODE_3,
    MMI_VTCS_DISPLAY_MODE_4,
    MMI_VTCS_DISPLAY_MODE_5,
    MMI_VTCS_DISPLAY_MODE_6,
    MMI_VTCS_DISPLAY_MODE_7,
    MMI_VTCS_DISPLAY_MODE_8,
        
    MMI_VTCS_DISPLAY_MODE_BG_1,
    MMI_VTCS_DISPLAY_MODE_BG_2,    

    MMI_VTCS_DISPLAY_MODE_TOTAL
} mmi_vtcs_display_mode_enum;

typedef enum
{
    MMI_VTCS_STATE_EXIT,
    MMI_VTCS_STATE_FOREGROUND,    
    MMI_VTCS_STATE_BACKGROUND,    
    
    MMI_VTCS_STATE_END
} mmi_vtcs_state_enum;



/* context */
typedef struct
{
    /* layers */
    gdi_handle skin_layer_handle;
    gdi_handle main_wnd_layer_handle;
    gdi_handle main_wnd_hw_layer_handle;    
    gdi_handle sub_wnd_layer_handle;
    gdi_handle sub_wnd_hw_layer_handle;    
    gdi_handle encode_layer_handle;
    gdi_handle snapshot_layer_handle;
    gdi_handle info_layer_handle;    
    gdi_handle bg_main_wnd_layer_handle;
    gdi_handle prev_status_layer_handle;
    
    PU8 skin_layer_buf_ptr;
    PU8 encode_layer_buf_ptr;

    /* state */
    mmi_vtcs_state_enum state;
    
    mmi_vt_camera_enum camera_state;
    mmi_vt_contrast_enum contrast_state;
    mmi_vt_brightness_enum brightness_state;
    mmi_vt_brightness_enum original_brightness_state;    
    mmi_vt_mic_enum mic_state;
    mmi_vt_speaker_enum speaker_state;
    mmi_vt_aud_rec_enum aud_rec_state;  
    mmi_vt_night_mode_enum night_mode_state;
    
    mmi_vt_cam_rotate_enum cam_rotate_state;
    mmi_vt_video_quality_enum peer_enc_qty_state;
    mmi_vt_video_quality_enum local_enc_qty_state;    
    mmi_vt_enc_size_enum enc_size_state;    
    mmi_vt_hand_enum hand_state;

    /* volum */
    mmi_vt_vol_enum vol_value;

    /* ev */ 
    mmi_vt_ev_enum  ev_value;
    mmi_vt_ev_enum  ev_max_value;
    mmi_vt_ev_enum  ev_min_value;
    U16             ev_valid_value_count;   

    /* zoom */
    U16             zoom_step;    
    U16             zoom_max_step;   

    /* slider bar */
    S32 bar_step_width_shift10;
    S32 bar_offset_x;
    S32 bar_width;

    /* sub wnd */
    MMI_BOOL is_hide_sub;
    
    mmi_vtcs_local_img_enum local_img_state;
    mmi_vtcs_local_img_enum peer_img_state;    
    mmi_vtcs_panel_state_enum panel_state;

    mmi_vtcs_touch_obj_enum touch_obj;
#ifdef __MMI_VTCS_FTE__
    /* advance pannel mean the VK/ZOOM/EV/VOL panel need to press some icon or key to truger */
    /* it can be recovered to original panel by timeout xor press back */
    /* if the pannel need back to recover to origanl panel but timeout, the variables two_setp_ad_panel_mode will be set to mark this */
    MMI_BOOL two_setp_ad_panel_mode;
#endif
    mmi_vtcs_touch_struct touch_camera;
    mmi_vtcs_touch_struct touch_mic;
    mmi_vtcs_touch_struct touch_speaker;
    mmi_vtcs_touch_struct touch_vk;    
    mmi_vtcs_touch_struct touch_aud_rec;    
    mmi_vtcs_touch_struct touch_ev;
    mmi_vtcs_touch_struct touch_zoom;    
    mmi_vtcs_touch_struct touch_snapshot;
    mmi_vtcs_touch_struct touch_inc;
    mmi_vtcs_touch_struct touch_dec; 
    mmi_vtcs_touch_struct touch_slider;   
    mmi_vtcs_touch_struct touch_brightness_up;
    mmi_vtcs_touch_struct touch_brightness_down;    
    mmi_vtcs_touch_struct touch_contrast;    
    mmi_vtcs_touch_struct touch_fullscreen;    
    mmi_vtcs_touch_struct touch_lsk;
    mmi_vtcs_touch_struct touch_rsk;    
    mmi_vtcs_touch_struct touch_vk_0;   
    mmi_vtcs_touch_struct touch_vk_1;       
    mmi_vtcs_touch_struct touch_vk_2;           
    mmi_vtcs_touch_struct touch_vk_3;
    mmi_vtcs_touch_struct touch_vk_4;
    mmi_vtcs_touch_struct touch_vk_5;
    mmi_vtcs_touch_struct touch_vk_6;           
    mmi_vtcs_touch_struct touch_vk_7;
    mmi_vtcs_touch_struct touch_vk_8;
    mmi_vtcs_touch_struct touch_vk_9;
    mmi_vtcs_touch_struct touch_vk_star;    
    mmi_vtcs_touch_struct touch_vk_pound;
    
    /* mode */
    mmi_vtcs_display_mode_enum mode;

    /* scroll */
    U16 scroll_inc_img_id;
    U16 scroll_dec_img_id;
    S32 scroll_cur_value;
    S32 scroll_total_value;    

    /* title */
    CHAR title_buf[MMI_VTCS_TITLE_BUF_SIZE];   /* unicode */

    /* softkey */
    U16 lsk_str_id;
    U16 rsk_str_id;    

    /* time panel */
    U32 call_dur;
    U32 call_start_time;    /* from RTC start */
    U32 call_cur_time;      /* from RTC start */
    CHAR call_cost_str[MMI_VTCS_COST_BUF_SIZE];   /* unicode */

    /* user image */
    U16 user_img_id;
    CHAR user_img_file_path[SRV_FMGR_PATH_BUFFER_SIZE];
    U16 default_peer_img_id;
    CHAR default_peer_img_file_path[SRV_FMGR_PATH_BUFFER_SIZE];    

    /* user input */
    CHAR input_box_buf[MMI_VTCS_INPUT_BOX_BUF_SIZE];

    /* misc */
    MMI_BOOL is_cam_mirror;
    MMI_BOOL is_sub_display;
    MMI_BOOL is_ut;
    MMI_BOOL is_display_cost;
    MMI_BOOL is_snapshot;
	MMI_BOOL is_fullscreen_state;
    
    CHAR *bg_mem_ptr;

    /* memorize if have opened MED or not */
    MMI_BOOL has_open_MED;
    MMI_BOOL is_enc_path_built;  /* MED may return open succes but ch is not built yet, so the isp is not set  zoom/ev cannt apply really */    
	MMI_BOOL is_local_image_off;
    
    MMI_ID parent_sg_id;
} mmi_vtcs_cntx_struct; /* video telephony call screen */


/***************************************************************************** 
 * Variable 
 *****************************************************************************/


/***************************************************************************** 
 * Function 
 *****************************************************************************/


#endif /* __MMI_VIDEO_TELEPHONY__ */
#endif /* VT_CALL_SCR_PROT_H */ 

