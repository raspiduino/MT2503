/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   media_enum.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
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

#ifndef _MEDIA_ENUM_H
#define _MEDIA_ENUM_H

/***************************************************************************** 
 * Media Session
 *****************************************************************************/
typedef enum
{
    MEDIA_SESSION_STATE_CLOSED = 0,
    MEDIA_SESSION_STATE_OPENING,
    MEDIA_SESSION_STATE_OPENED,
    MEDIA_SESSION_STATE_SEEKING,
    MEDIA_SESSION_STATE_STARTED
} media_session_state_enum;

/***************************************************************************** 
 * Media Player
 *****************************************************************************/

/* DEFINE */
#define MPLY_AUD_FRAME_NUM_START_TO_PLAY (60)

/* ENUM */
typedef enum
{
    MEDIA_PLAYER_EVENT_STARTED,
    MEDIA_PLAYER_EVENT_END_OF_MEDIA,
    MEDIA_PLAYER_EVENT_STOP_TIME_REACHED,
    MEDIA_PLAYER_EVENT_RECOVER_JUMP_TO_I,
    MEDIA_PLAYER_EVENT_RECOVER_STOP_AUDIO,
    MEDIA_PLAYER_EVENT_AUDIO_PLAY_ERROR,
    MEDIA_PLAYER_EVENT_VIDEO_PLAY_ERROR,
    MEDIA_PLAYER_EVENT_VIDEO_DECODER_NOT_SUPPORT,
    MEDIA_PLAYER_EVENT_AUDIO_DATA_REQUEST,
    MEDIA_PLAYER_EVENT_AUDIO_UNDERFLOW,
    MEDIA_PLAYER_EVENT_AUDIO_FRAME_READY,
} media_player_event_t;

typedef enum
{
    MEDIA_PLAYER_PLAY_MODE,
    MEDIA_PLAYER_SEEK_MODE
} media_player_start_mode_t;

typedef enum
{
    MEDIA_PLAYER_PARAM_TYPE_VOLUME,
    MEDIA_PLAYER_PARAM_TYPE_PLAY_TIME,
    MEDIA_PLAYER_PARAM_TYPE_STOP_TIME,
    MEDIA_PLAYER_PARAM_TYPE_SLEEP_TIME,
    MEDIA_PLAYER_PARAM_TYPE_UPDATE_VID_DURATION,
    MEDIA_PLAYER_PARAM_TYPE_PLAY_SPEED,
    MEDIA_PLAYER_PARAM_TYPE_AUD_BUFFER_SIZE,
    MEDIA_PLAYER_PARAM_TYPE_AUD_BUFFER_NUM,
    MEDIA_PLAYER_PARAM_TYPE_AUD_BUFFER_TIME,
    MEDIA_PLAYER_PARAM_TYPE_VIDEO_RESOLUTION,
    MEDIA_PLAYER_PARAM_TYPE_DUMMY_AUD_PLAYING,
    MEDIA_PLAYER_PARAM_TYPE_AUD_PLAYING,
    MEDIA_PLAYER_PARAM_TYPE_AUD_TIME_DIFF,
    MEDIA_PLAYER_PARAM_TYPE_NEED_AUD_FRAME,
    MEDIA_PLAYER_PARAM_TYPE_MAX_VID_FRAME_TIME,
    MEDIA_PLAYER_PARAM_TYPE_STOP_DECODER,
    MEDIA_PLAYER_PARAM_TYPE_RUN_DECODER,
    MEDIA_PLAYER_PARAM_TYPE_BRIGHTNESS,
    MEDIA_PLAYER_PARAM_TYPE_CONTRAST,
    MEDIA_PLAYER_PARAM_TYPE_FRAME
} media_player_param_type_t;

typedef enum
{
    MPLY_STATE_CLOSED,
    MPLY_STATE_OPENED,
    MPLY_STATE_PREPARED,
    MPLY_STATE_BUFFERING,
    MPLY_STATE_VID_BUFFERED,
    MPLY_STATE_AUD_BUFFERED,
    MPLY_STATE_PLAYING,
    MPLY_STATE_VID_PLAY_FINISH,
    MPLY_STATE_AUD_PLAY_FINISH,
    MPLY_STATE_SEEKING,
    MPLY_STATE_SEEK_DONE
} media_player_state_enum;

typedef enum{
    MPLY_AUD_STREAM_NONE,
    MPLY_AUD_STREAM_RECEIVED,
    MPLY_AUD_STREAM_END
}media_player_aud_stream_status_enum;

typedef enum{
    MPLY_VID_STREAM_NONE,
    MPLY_VID_STREAM_END_WAIT_NOTIFY,
    MPLY_VID_STREAM_END_NOTIFIED,
    MPLY_VID_STREAM_COMPLETE,
    MPLY_VID_STREAM_PLAY_FINISH
}media_player_vid_stream_status_enum;

typedef enum
{
    MPLY_EVT_DECODER_WAIT_BUFFER            = 1,        /* 0 */
    MPLY_EVT_DECODER_COMPLETE               = (1 << 1), /* 2 */
    MPLY_EVT_DECODER_ERROR                  = (1 << 2), /* 4 */
    MPLY_EVT_DECODER_RESOLUTION_NOT_SUPPORT = (1 << 3), /* 8 */
    MPLY_EVT_SCHEDULER_COMPLETE             = (1 << 4), /* 16 */
    MPLY_EVT_SCHEDULER_RECOVER_JUMP_TO_I    = (1 << 5), /* 32 */ 
    MPLY_EVT_SCHEDULER_RECOVER_STOP_AUDIO   = (1 << 6), /* 64 */ 
    MPLY_EVT_CLOCK_START                    = (1 << 7), /* 128 */ 
    MPLY_EVT_CLOCK_STOP                     = (1 << 8), /* 256 */
    MPLY_EVT_CLOCK_EXPECTED_BUF_NUM_RDY     = (1 << 9), /* 512 */
    MPLY_EVT_RENDER_ERROR                   = (1 << 10) /* 1024 */
} media_player_comp_evt_enum;

typedef enum{
    MPLY_QUEUE_AUDIO,
    MPLY_QUEUE_VIDEO,
    MPLY_QUEUE_VIDEO_WRITTEN
}media_player_queue_type_enum;

#endif /* _MEDIA_SESSION_H */

