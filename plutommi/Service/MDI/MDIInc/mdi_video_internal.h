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
 *  mdi_video.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface to access video related functions.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _MDI_VIDEO_INTERNAL_H
#define _MDI_VIDEO_INTERNAL_H

#ifndef _MDI_DATATYPE_H_
#include "mdi_datatype.h"
#endif

#ifndef _GDI_INCLUDE_H_
#include "gdi_include.h"
#endif
/* add for event type */
#include "custom_events_notify.h"
#include "cal_comm_def.h"
#include "med_api.h"
#include "mdi_camera.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "mmi_frm_events_gprot.h"
#include "gdi_datatype.h"
#include "MMI_features.h"
#include "app_ltlcom.h"
#include "mdi_video.h"

typedef enum
{
    MDI_VIDEO_STATE_IDLE= 0,
    MDI_VIDEO_STATE_POWER_ON,
    MDI_VIDEO_STATE_PREVIEWING,
    MDI_VIDEO_STATE_RECORDING
} mdi_video_state_enum;


#ifdef __MMI_VIDEO_STREAM__
#define MDI_VIDEO_STREAM_UAPROF_BUFF_LEN  512
#define MDI_VIDEO_STREAM_UA_STR_BUFF_LEN  64
#endif


typedef struct
{
    mdi_video_setting_struct setting;
    U64 record_time;
    U32 repeat_count;

    gdi_handle lcd_handle;
    gdi_handle hw_update_layer_handle;
    gdi_handle subtitle_layer_handle;
    gdi_color_format prev_color_format;

    U16 force_ui_rotate;

    U16 rec_state;
    U16 open_seq_num;
    U16 play_seq_num;
    U16 record_seq_num;
    U16 seek_seq_num;
    U16 merge_seq_num;
    U16 vt_seq_num;
    U16 cam_id;
    U16 app_id;
#ifdef __MMI_TVOUT__
    U16 tvout_prev_owner;
    BOOL is_tvout_owner;
#endif
    BOOL is_play_audio;
    BOOL is_seeking;
    BOOL is_get_frame;
    BOOL is_enable_partial_display;
    BOOL is_playing;
    BOOL is_seek_after_open;
    BOOL is_recording;
    BOOL is_poweron;
    BOOL is_enable_aud_only;
#ifdef __DRM_SUPPORT__
    BOOL is_drm_file;
    BOOL is_drm_consume_count;
    BOOL is_drm_consume_time;
    BOOL is_drm_time_limit_stop;
    mdi_video_drm_state_enum drm_file_state;
    U32 drm_file_id;
    FS_HANDLE drm_file_handle;
#endif

    BOOL is_bypass_3a_stable;
    U8 frame_mode;
    BOOL is_lcd_update; /* for landscape on portrait lcm */
    mdi_video_track_enum track;

    module_type mimic_module_id;
    media_vid_play_req_struct play_data;
    void *rec_user_data;
#if defined(__MDI_VIDEO_BLOCK_GPRS__)
    U8  cbm_app_id;
#endif
    U8  encode_rotate;
    U16 image_width;
    U16 image_height;
    
    /* drm */
    mpl_scenario_enum scenario;
    void *user_data;
#ifdef __GAIN_TABLE_SUPPORT__
    U8 media_type;
#endif
#ifndef __MTK_TARGET__
    /* dummy variable for MoDIS */
    U64 dummy_cur_time;
    U64 dummy_max_play_time;
    S32 dummy_loading_percentage;
    S32 dummy_counter;
    BOOL dummy_is_pdl;
#endif
} mdi_video_context_struct;


#ifdef __MMI_VIDEO_STREAM__
typedef struct
{
    CHAR uaprof_str[MDI_VIDEO_STREAM_UAPROF_BUFF_LEN];
    CHAR uaprof_diff_str[MDI_VIDEO_STREAM_UAPROF_BUFF_LEN];
    CHAR ua_str[MDI_VIDEO_STREAM_UA_STR_BUFF_LEN];

    mdi_video_info_struct video_info;
    S32 dummy;
    BOOL is_enable_partial_display;
    BOOL is_drm_consume_count;
    BOOL is_drm_consume_time;
    BOOL is_stream_connected;
    BOOL is_stream_init;
    BOOL is_playing;
    BOOL is_drm_streaming;
    BOOL is_tvout_owner;
    BOOL is_lcd_update;
    gdi_handle lcd_handle;
    gdi_handle hw_update_layer_handle;
    mdi_video_track_enum play_style;

    /* drm */
    mdi_video_drm_state_enum drm_streaming_state;
    U32 drm_streaming_id;
    FS_HANDLE drm_streaming_handle; /* for PDCF */

    U16 play_seq_num;
    U16 connect_seq_num;
    U16 buffering_seq_num;
    U16 tvout_prev_owner;
    U16 hw_rotator_rotate;

    U8 stream_session_id;
    mdi_video_sleep_struct sleep_value;
    void *user_data;

    mpl_scenario_enum scenario;
    U8 frame_mode;
    U8 mode_3d;
    U32 prebuffer_time;
    media_stream_rtp_connect_type_enum prefer_transport;

#ifndef __MTK_TARGET__
    /* dummy variable for MoDIS */
    U64 dummy_cur_time;
    U64 dummy_max_play_time;
    S32 dummy_loading_percentage;
    S32 dummy_counter;
#endif /* __MTK_TARGET__ */

} mdi_video_stream_context_t;
#endif /* __MMI_VIDEO_STREAM__ */

#ifdef __MMI_VIDEO_TELEPHONY__

typedef struct
{
    BOOL is_during_vcall;
    BOOL is_hw_layer_enable;
    gdi_handle local_layer_handle;
    gdi_handle peer_layer_handle;
    kal_uint32 local_layer_w;
    kal_uint32 local_layer_h;
    kal_uint32 peer_layer_w;
    kal_uint32 peer_layer_h;

}mdi_video_tel_context_struct;
#endif

#endif /* _MDI_VIDEO_INTERNAL_H */

