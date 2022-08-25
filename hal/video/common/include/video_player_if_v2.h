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
 *   video_player_if.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video player interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#ifndef __VIDEO_PLAYER_IF_V2_H__
#define __VIDEO_PLAYER_IF_V2_H__

#ifdef __VIDEO_ARCHI_V2__

#include "mp4_parser.h"
#include "fsal.h"

#define VIDEO_PLAY_EVENT_FILEREADER_COMPLETE                ((kal_uint32)0x00000001)
#define VIDEO_PLAY_EVENT_FILEREADER_ERROR                   ((kal_uint32)0x00000002)

#define VIDEO_PLAY_EVENT_DECODER_COMPLETE                   ((kal_uint32)0x00000010)
#define VIDEO_PLAY_EVENT_DECODER_ERROR                      ((kal_uint32)0x00000020)
#define VIDEO_PLAY_EVENT_DECODER_NOTIFY_WAIT_BUFFER			((kal_uint32)0x00000040)
#define VIDEO_PLAY_EVENT_DECODER_NOTIFY_COMPLETE            ((kal_uint32)0x00000080)

#define VIDEO_PLAY_EVENT_SCHEDULER_COMPLETE                 ((kal_uint32)0x00000100)
#define VIDEO_PLAY_EVENT_SCHEDULER_ERROR                    ((kal_uint32)0x00000200)

#define VIDEO_PLAY_EVENT_CLOCK_COMPLETE                     ((kal_uint32)0x00001000)
#define VIDEO_PLAY_EVENT_CLOCK_ERROR                        ((kal_uint32)0x00002000)
#define VIDEO_PLAY_EVENT_CLOCK_START                        ((kal_uint32)0x00004000)

#define VIDEO_PLAY_EVENT_RENDER_COMPLETE                    ((kal_uint32)0x00010000)
#define VIDEO_PLAY_EVENT_RENDER_ERROR                       ((kal_uint32)0x00020000)

#define VIDEO_ANYBASE_TO_ANYBASE(_TIME_SRC, _TIME_BASE_SRC, _TIME_BASE_DST)    ((kal_uint64)_TIME_SRC*(kal_uint64)_TIME_BASE_DST/(kal_uint64)_TIME_BASE_SRC)

// Support frame size definition
#define VIDEO_PLAY_SUPPORT_MAX_WIDTH       ((kal_uint32)640)
#define VIDEO_PLAY_SUPPORT_MAX_HEIGHT      ((kal_uint32)480)

// Support frame rate definition
#define VIDEO_PLAY_SUPPORT_MAX_FRAME        120

typedef enum
{
    VIDEO_PLAY_DECODER_WAIT_BUFFER = 0x1,
    VIDEO_PLAY_DECODER_COMPLETE = 0x2,
    VIDEO_PLAY_CLOCK_START = 0x4,
    VIDEO_PLAY_SCHEDULER_RECOVER = 0x8,
    VIDEO_PLAY_SCHEDULER_COMPLETE = 0x10,
    VIDEO_PLAY_DECODER_ERROR = 0x20,
    VIDEO_PLAY_FILEREADER_ERROR = 0x40
}VIDEO_PLAY_HDRL_TYPE_T;

typedef enum
{
    VIDEO_PLAY_COMPONENT_FILEREADER,
    VIDEO_PLAY_COMPONENT_DECODER,
    VIDEO_PLAY_COMPONENT_SCHEDULER,
    VIDEO_PLAY_COMPONENT_CLOCK,    
    VIDEO_PLAY_COMPONENT_RENDER
}VIDEO_PLAY_COMPONENT_TYPE_T;

typedef enum
{
    VIDEO_PLAY_STATE_CLOSE,
    VIDEO_PLAY_STATE_INIT,    
    VIDEO_PLAY_STATE_SEEKING,
    VIDEO_PLAY_STATE_SEEK_DONE,
    VIDEO_PLAY_STATE_PLAYING,
    VIDEO_PLAY_STATE_PLAY_DONE,
    VIDEO_PLAY_STATE_COMPLETE,
    VIDEO_PLAY_STATE_STOP
}VIDEO_PLAY_STATE_T;

typedef struct
{
    VIDEO_PLAY_HDRL_TYPE_T eHdlr;
    VIDEO_PLAY_COMPONENT_TYPE_T eComponent;
    VIDEO_EVENT_TYPE_T eEvent;
}VIDEO_PLAY_HDLR_STRUCT_T;

typedef struct
{
    kal_eventgrpid eEvent;
    VIDEO_COMPONENT_TYPE_T *prVideoFileReaderHandle;
    VIDEO_COMPONENT_TYPE_T *prVideoDecoderHandle;
    VIDEO_COMPONENT_TYPE_T *prVideoSchedulerHandle;
    VIDEO_COMPONENT_TYPE_T *prVideoClockHandle;
    VIDEO_COMPONENT_TYPE_T *prVideoRenderHandle;
    
    void (*pfnVideoDecCB)(kal_uint8 u1Event);
    VIDEO_PLAY_STATE_T eState;
    kal_uint32 u4HdlrType;
    kal_bool fgDecoderComplete;
    kal_bool fgSchedulerComplete;

    // Video recover
    kal_bool fgRecover;
    kal_uint32 u4RecoverCount;
    kal_uint64 u8RecoverTolerance;  // Indicate how much time scheduler can handle AV unsync tolerance in us

    // Mp4 video parser
    STMp4Parser *prMp4Parser;
    // File system abstration layer
    STFSAL *prFSAL;
    MP4_Parser_Status eParserStatus;

    // Video information
    kal_uint32 u4VideoWidth;
    kal_uint32 u4VideoHeight;

    // For the audio only control information
    // Video Control information
    kal_bool fgHasVisualTrack;
    kal_uint32 u4PlaySpeed;
}VIDEO_PLAY_STRUCT_T;

////////////////////////////////////////////////
//     external use
///////////////////////////////////////////////

/*Input struct: Start*/
typedef struct
{
    STMp4Parser *pstMp4Parser;
    STFSAL *pstFSAL;
    void (*video_dec_callback)(kal_uint8 event);
    kal_uint16 max_width;
    kal_uint16 max_height;
    kal_bool audio_enable;
    kal_bool b_drm;
    kal_int32 drm_handle;
    kal_uint32 intmem_start_address;
    kal_uint32 intmem_size;
    kal_uint32 extmem_start_address;
    kal_uint32 extmem_size;
    kal_uint32 max_lcd_width;
    kal_uint32 max_lcd_height;
} MP4DEC_INIT_STRUCT;

/* Video Event for upper layer */
typedef enum
{
    // Buffer empty event, upper layer should fill up the buffer
    VIDEO_DEC_EVENT_BUFFER_EMPTY = 0,
    // Decode complete event
    VIDEO_DEC_EVENT_COMPLETE,
    // Partial Seek ready event, because long file seek
    VIDEO_DEC_EVENT_SEEK_PARTIAL_DONE,
    // Seek ready event
    VIDEO_DEC_EVENT_SEEK_DONE,
    // No Video track event
    VIDEO_DEC_EVENT_NO_TRACK,
    // Someting wrong in video driver, upper layer should call function
    // to obtain error casue.
    VIDEO_DEC_EVENT_FAIL,
    // MCU is too busy to run this video.
    // When upper layer receive this event, call video_dec_recover to pause/resume/recover this video.
    VIDEO_DEC_RECOVER,
    // audio complete event for seek
    VIDEO_DEC_SEEK_AUDIO_EVENT_COMPLETE,
    // video seek handler.
    VIDEO_DEC_DRV_SEEK_ACTION,
    // Total Events
    VIDEO_DEC_MAX_EVENT
}VIDEO_DEC_EVENT;


//IDP related, will remove later
#include "lcd_if.h"
typedef struct
{
    lcd_frame_update_struct *lcd_data;
    kal_uint32 lcd_buf_addr;
    kal_uint32 lcd_buf_size;
    kal_uint16 disp_width;
    kal_uint16 disp_height;
    kal_uint16 video_display_offset_x;
    kal_uint16 video_display_offset_y;
    kal_uint8 contrast_level;   /* IPP contrast gain level */
    kal_uint8 brightness_level; /* IPP brightness level */
    kal_bool force_lcd_hw_trigger;
//#if defined (DRV_MP4_V2) || defined (SW_VIDEO_MT6236_HQA)  
    kal_bool image_pitch_mode;    /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;  /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes; /* pitch width */
    kal_bool tv_output;
    kal_uint32 tv_output_frame_buffer1_address;
    kal_uint32 tv_output_frame_buffer2_address;
    kal_uint32 tv_output_frame_buffer_size;
//#endif #if defined (DRV_MP4_V2) || defined (SW_VIDEO_MT6236_HQA) 

//#ifdef SW_VIDEO_MT6236_HQA
    kal_uint32 rotate_angle;
    kal_uint32 lcd_buf_addr_2;
    kal_uint32 lcd_buf_size_2;
//#endif
} MP4DEC_IMGPATH_STRUCT;

typedef struct
{
    kal_uint32 disp_width;
    kal_uint32 disp_height;
    kal_uint32 lcd_buf_addr;
    kal_uint32 lcd_buf_size;
    kal_uint8 contrast_level;   /* IPP contrast gain level */
    kal_uint8 brightness_level; /* IPP brightness level */
//#if defined (DRV_MP4_V2) || defined (SW_VIDEO_MT6236_HQA)  
    kal_bool image_pitch_mode;    /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;  /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes; /* pitch width */
    kal_bool tv_output;
//#endif

//#ifdef SW_VIDEO_MT6236_HQA
    kal_uint32 rotate_angle;
    kal_uint32 lcd_buf_addr_2;
    kal_uint32 lcd_buf_size_2;
//#endif
} MP4DEC_MEMMODE_STRUCT;

/* Video image path state */
typedef enum
{
    VIDEO_DEC_IMG_PATH_NONE = 0,
    VIDEO_DEC_IMG_PATH_HW,
    VIDEO_DEC_IMG_PATH_SW,
    VIDEO_DEC_MAX_IMG_PATH
}VIDEO_DEC_IMG_PATH_TYPE;

extern MEDIA_STATUS_CODE video_dec_initialize(MP4DEC_INIT_STRUCT *prInitInput);
extern MEDIA_STATUS_CODE video_dec_seek(kal_uint64 u8SeekTime, void (*pfnCallback)(kal_uint8 u1Event));
extern MEDIA_STATUS_CODE video_dec_seek_done(void);
extern void video_seek_action(void);
extern MEDIA_STATUS_CODE video_dec_play(kal_uint32 * pu4AudioFrameNo, void (*pfnCallback)(kal_uint8 u1Event));
extern MEDIA_STATUS_CODE video_dec_recover(kal_uint32 * pu4AudioFrameNo, void (*pfnCallback)(kal_uint8 u1Event));
extern void video_dec_stop(void);
extern void video_dec_close(void);
extern void video_dec_set_play_speed(kal_uint16 u2PlaySpeed);
extern void video_dec_get_total_time(kal_uint64 * pu8AudioTime, kal_uint64 * pu8VideoTime);
extern MEDIA_STATUS_CODE video_dec_get_total_play_time(kal_uint64 * pu8TotalPlayTime);
extern MEDIA_STATUS_CODE video_dec_get_play_time(kal_uint64 * pu8CurrentTime);
extern void video_dec_get_frame_size(kal_uint16* pu2Width, kal_uint16* pu2Height);
extern void video_dec_set_audio(kal_bool fgEnable);
extern void video_dec_set_display(kal_bool fgEnable);
extern void video_dec_change_display_size(kal_uint32 u4Width, kal_uint32 u4Height);
extern MEDIA_STATUS_CODE video_dec_frame2time(kal_uint32 u4Frame, kal_uint32 * pu4Time);
extern MEDIA_STATUS_CODE video_dec_time2frame(kal_uint32 u4Time, kal_uint32 * pu4Frame);
extern VIDEO_DECODER_TYPE_T video_dec_get_decoder_type(void);
extern kal_uint32 video_dec_get_display_addr(void);

#endif

#endif /* __VV2_MAIN_V2_H__ */ 

