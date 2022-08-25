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
 *   media_session_int.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MEDIA_SESSION_INT_H
#define _MEDIA_SESSION_INT_H

#if defined(__VIDEO_ARCHI_V2__)

#include "kal_general_types.h"
#include "kal_public_defs.h"

#include "mpl_common.h" // mpl common type definition
#include "mpl_player.h" // mpl player interface definition

#include "media_provider.h"
#include "media_player.h"

#include "fs_type.h" // for file handle
/***************************************************************************** 
 * Define
 *****************************************************************************/

#define MEDIA_SESSION_INVALID_INDEX (0xFFFFFFFF)

#define MSES_SET_FLAG(flag_) (self->bit_flag |= (flag_))
#define MSES_UNSET_FLAG(flag_) (self->bit_flag &= (~(flag_)))
#define MSES_IS_FLAG_SET(flag_) ((self->bit_flag & (flag_)) == (flag_))

/* Configurable */
#define MSES_BUFFER_TIME_FOR_PLAY    (1000*6)
#define MSES_IGNORE_TIME_LEN (2000)
#define MSES_VID_THUMBNAIL_TIME (2000)

/***************************************************************************** 
 * Enumeration
 *****************************************************************************/

typedef enum
{
    MSES_SEEK_STATE_IDLE,
    MSES_SEEK_STATE_WAIT_PLAYER_DONE,
    MSES_SEEK_STATE_PLAYER_DONE,
    MSES_SEEK_STATE_BUFFER_DONE,
    MSES_SEEK_STATE_GET_THUMBNAIL
} media_session_seek_state_enum;

typedef enum
{
    MSES_PLAYER_FLAG_IS_AUD_VOLUME_SET          = 1,        /* 1 */
    MSES_PLAYER_FLAG_IS_STOP_TIME_SET           = (1 << 1), /* 2 */
    MSES_PLAYER_FLAG_IS_SLEEP_TIME_SET          = (1 << 2), /* 4 */
    MSES_PLAYER_FLAG_IS_PROVIDER_VIDEO_ERROR    = (1 << 3), /* 8 */
    MSES_PLAYER_FLAG_IS_PROVIDER_AUDIO_ERROR    = (1 << 4), /* 16 */
    MSES_PLAYER_FLAG_IS_RECEIVE_AUDIO_EOS       = (1 << 5), /* 32 */
    MSES_PLAYER_FLAG_IS_PROVIDER_STARTED        = (1 << 6), /* 64 */
    MSES_PLAYER_FLAG_IS_AUD_BUFFERED            = (1 << 7), /* 128 */
    MSES_PLAYER_FLAG_IS_VID_BUFFERED            = (1 << 8) /* 256 */
} media_session_bit_flag_enum;


/***************************************************************************** 
 * Structure
 *****************************************************************************/

typedef struct
{
    /* memory pool */
    kal_uint8* mem_pool;
    KAL_ADM_ID adm_pool_id;
    kal_mutexid adm_mutex;
    kal_uint8 ref_count;
    kal_uint32 alloc_count;
} media_session_mem_struct;

typedef struct
{
    mpl_player_t mpl;
    mpl_player_client_t* mpl_client;

    media_provider_t* provider;
    media_provider_client_t provider_client;

    media_player_t* player;
    media_player_client_t player_client;

    mpl_player_ctrl_dl_t dl_control;

    med_mode_enum media_mode;
    med_track_enum media_track;
    mpl_scenario_enum media_scenario;
    media_session_state_enum state;
    kal_bool fgSeekable;
    kal_uint16 app_id;
    
    kal_uint32 vid_stream_index;
    kal_uint32 aud_stream_index;
    media_stream_t aud_stream;
    media_stream_t vid_stream;

    kal_bool force_seek;
    media_time_t curr_time;
    
    FS_HANDLE fs_handle;

    kal_uint8 aud_volume;
    kal_uint64 stop_time;
    kal_uint8 elapse_ticks;
    kal_uint8 sleep_ticks;
    kal_uint8 brightness;
    kal_uint8 contrast;
    kal_uint32 bit_flag;
    kal_uint8 retry_count;

    kal_bool fgBuffSupplier;    // indicate should provide bitstream buffer or not
    media_session_seek_state_enum seek_state;
} media_session_struct;

/***************************************************************************** 
 * Declaration
 *****************************************************************************/

/* For Debug Use */
#define MEDIA_SESSION_MAX_CONTEXT 2


static media_error_t media_session_play_internal(mpl_player_t* mpl, kal_uint32 play_speed, kal_bool close_bt_codec);
static media_error_t media_session_stop_seek(mpl_player_t* mpl);
static media_error_t media_session_get_buffer_percent(mpl_player_ctrl_dl_t* dl, kal_uint32* percent);
static media_error_t media_session_pause_visual_update(mpl_player_t* mpl);
static media_error_t media_session_notify_stream_seek_done(mpl_player_t* mpl);

extern void media_session_do_recover(media_player_client_t* client, media_player_event_t event, kal_uint32 event_param);
extern kal_bool media_session_player_is_underflow(mpl_player_t* mpl);
extern media_error_t media_session_stop_play(mpl_player_t* mpl);
extern media_error_t player_event_to_med_result_enum(mpl_player_t* mpl, media_player_event_t event, media_error_t error);
extern media_time_t media_session_get_play_time(mpl_player_t* mpl);
extern void media_session_pretend_eos(mpl_player_t* mpl, kal_uint32 stream_index);
#endif /* defined (__VIDEO_ARCHI_V2__) */

#endif /* _MEDIA_SESSION_INT_H */

