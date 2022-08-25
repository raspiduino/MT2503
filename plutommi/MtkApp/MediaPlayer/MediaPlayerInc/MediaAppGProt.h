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
*  MediaAppGProt.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Media application golbal export interface
*   For other applications only need to include this header and utilize identical
*   interface to cooperate with media applications
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifndef MEDIA_APP_GPROT_H
#define MEDIA_APP_GPROT_H
#include "MMI_features.h"
#include "AudioPlayerProt.h"
#include "VdoPlyGProt.h"
#include "MediaPlayerGProt.h"
#include "MMIDataType.h"

/*Audio*/
#ifndef __MMI_MEDIA_PLAYER_AUDIO__
    #define mmi_media_app_play_audio(a,b,c)     mmi_audply_single_play((UI_string_type)a,b,c)
    #define mmi_media_app_play_audio_with_title(a,b,c,d)    mmi_audply_single_play((UI_string_type)a,b,c)
    #define mmi_media_app_delete_play_audio       mmi_audply_exit_single_play
#else
    #define mmi_media_app_play_audio(a,b,c)     mmi_medply_single_play_audio((UI_string_type)a,b)
    #define mmi_media_app_play_audio_with_title(a,b,c,d)    mmi_medply_single_play_audio_with_title((UI_string_type)a,b,(UI_string_type)d)
    #define mmi_media_app_delete_play_audio       mmi_medply_single_delete_player_screen
#endif

/*SnapShot*/
#if defined(__MMI_VIDEO_PLY_SNAPSHOT_SUPPORT__)
    #if defined(__MMI_VIDEO_PLAYER__)
        /*Video player*/
        #define mmi_media_app_get_next_snapshot_filename(a,b)   mmi_vdoply_get_next_snapshot_filename((CHAR*)a,(CHAR*)b)
    #elif (defined(__MMI_MEDIA_PLAYER_VIDEO__) || defined(__MMI_MEDIA_PLAYER_STREAM__))
        /*Media player*/
        #define mmi_media_app_get_next_snapshot_filename(a,b)   mmi_medply_get_next_snapshot_filename((CHAR*)a,(CHAR*)b)
    #else
        #define mmi_media_app_get_next_snapshot_filename(a,b)
    #endif
#endif

 #if defined(__MMI_VIDEO_PLAYER__)
    #define mmi_media_app_play_video(a,b)       mmi_vdoply_entry_player_screen_from_file((CHAR*)a,(MMI_BOOL)b)
    #define mmi_media_app_play_video_ext(a,b,c)       mmi_vdoply_entry_player_screen_from_file_ext((CHAR*)a,(MMI_BOOL)b,(CHAR*)c)
#elif defined(__MMI_MEDIA_PLAYER_VIDEO__)
    #define mmi_media_app_play_video(a,b)       mmi_medply_single_play_video((UI_string_type)a,(MMI_BOOL)b)
    #define mmi_media_app_play_video_ext(a,b,c)       mmi_medply_single_play_video_with_title((UI_string_type)a,(MMI_BOOL)b,(UI_string_type)c)
#else
    #define mmi_media_app_play_video(a,b)
    #define mmi_media_app_play_video_ext(a,b,c)
#endif

/*Stream*/
#ifdef __MMI_VIDEO_STREAM__

#if defined(__MMI_VIDEO_PLAYER__)
    #define mmi_media_app_play_stream_from_rtsp_link(a)     mmi_vdoply_entry_player_screen_from_rtsp_link((CHAR*)a)
    #define mmi_media_app_play_stream_from_sdp_file(a,b)    mmi_vdoply_entry_player_screen_from_sdp_file((CHAR*)a,(MMI_BOOL)b)
    #define mmi_media_app_play_stream_from_sdp_file_ext(a,b,c)    mmi_vdoply_entry_player_screen_from_sdp_file_ext((CHAR*)a,(MMI_BOOL)b,(CHAR*)c)
    #define mmi_media_app_play_stream_from_ram_file(a,b)    mmi_vdoply_entry_player_screen_from_ram_file((CHAR*)a,(MMI_BOOL)b)
    #define mmi_media_app_send_rtsp_url(a)                  mmi_vdoply_send_rtsp_url_req((CHAR*) a)
#elif defined(__MMI_MEDIA_PLAYER_STREAM__)
    #define mmi_media_app_play_stream_from_rtsp_link(a)     mmi_medply_single_play_stream_from_rtsp_link((UI_string_type)a)
    #define mmi_media_app_play_stream_from_sdp_file(a,b)    mmi_medply_single_play_stream_from_sdp_file((UI_string_type)a,(MMI_BOOL)b)
    #define mmi_media_app_play_stream_from_sdp_file_ext(a,b,c)  mmi_medply_single_play_stream_from_sdp_file_with_title((UI_string_type)a,(MMI_BOOL)b,(UI_string_type)c)
    #define mmi_media_app_play_stream_from_ram_file(a,b)    mmi_medply_single_play_stream_from_ram_file((UI_string_type)a,(MMI_BOOL)b)
    #define mmi_media_app_send_rtsp_url(a)                  mmi_medply_send_rtsp_url_req((CHAR*) a)
#else
    #define mmi_media_app_play_stream_from_rtsp_link(a)
    #define mmi_media_app_play_stream_from_sdp_file(a,b)
    #define mmi_media_app_play_stream_from_sdp_file_ext(a,b,c)
    #define mmi_media_app_play_stream_from_ram_file(a,b)
    #define mmi_media_app_send_rtsp_url(a)
#endif

#endif /*__MMI_VIDEO_STREAM__*/

#endif /* MEDIA_APP_GPROT_H */ 

