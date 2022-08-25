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
 *  VideoCall_IL_Client.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains vcall il client
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef VIDEOCALL_IL_CLIENT_H
#define VIDEOCALL_IL_CLIENT_H
#include "drv_features_video.h"
#if defined(__VE_VIDEO_ARCHI_V2__) && defined(__VE_VIDEO_VT_SUPPORT__)

#include "video_types_v2.h"
#include "va2_comp_video_renderer.h"
#include "mpl_vt.h"

#include "video_buffer_management_v2.h"
#include "kal_public_defs.h"
#include "video_comm_component_v2.h"
#include "kal_general_types.h"


#define VT_VIDEO_ENC_EVENT_SOURCE_COMPLETE				       ((kal_uint32)0x00000001)
#define VT_VIDEO_ENC_EVENT_SOURCE_ERROR				              ((kal_uint32)0x00000002)

#define VT_VIDEO_ENC_EVENT_CLOCK_COMPLETE				       ((kal_uint32)0x00000010)
#define VT_VIDEO_ENC_EVENT_CLOCK_ERROR				              ((kal_uint32)0x00000020)

#define VT_VIDEO_ENC_EVENT_ENCODER_COMPLETE			       ((kal_uint32)0x00000100)
#define VT_VIDEO_ENC_EVENT_ENCODER_ERROR					((kal_uint32)0x00000200)

#define VT_VIDEO_DEC_EVENT_DECODER_COMPLETE                         ((kal_uint32)0x00000010)
#define VT_VIDEO_DEC_EVENT_DECODER_ERROR                                 ((kal_uint32)0x00000020)
#define VT_VIDEO_DEC_EVENT_DECODER_NOTIFY_WAIT_BUFFER	((kal_uint32)0x00000040)
#define VT_VIDEO_DEC_EVENT_DECODER_NOTIFY_COMPLETE         ((kal_uint32)0x00000080)

#define VT_VIDEO_DEC_EVENT_SCHEDULER_COMPLETE                     ((kal_uint32)0x00000100)
#define VT_VIDEO_DEC_EVENT_SCHEDULER_ERROR                             ((kal_uint32)0x00000200)

#define VT_VIDEO_DEC_EVENT_CLOCK_COMPLETE                              ((kal_uint32)0x00001000)
#define VT_VIDEO_DEC_EVENT_CLOCK_ERROR                                      ((kal_uint32)0x00002000)
#define VT_VIDEO_DEC_EVENT_CLOCK_START                                       ((kal_uint32)0x00004000)

#define VT_VIDEO_DEC_EVENT_RENDER_COMPLETE                             ((kal_uint32)0x00010000)
#define VT_VIDEO_DEC_EVENT_RENDER_ERROR                                     ((kal_uint32)0x00020000)

typedef struct
{
    void *frame_meta;
    kal_uint8 session_id;
} VideoCall_dec_data_struct;

typedef struct
{
    /* memory */
    VIDEO_EXTMEM_HANDLER_T* ext_handler_ptr;
    VIDEO_INTMEM_HANDLER_T* int_handler_ptr;

    /* decode path component */
    kal_eventgrpid encEvent;
    VIDEO_COMPONENT_TYPE_T *dec_prVideoDecoderHandle;
    VIDEO_COMPONENT_TYPE_T *dec_prVideoSchedulerHandle;
    VIDEO_COMPONENT_TYPE_T *dec_prVideoRenderHandle;

    /* encode path component */
    kal_eventgrpid decEvent;
    VIDEO_COMPONENT_TYPE_T *enc_prVideoFileWriterHandle;
    VIDEO_COMPONENT_TYPE_T *enc_prVideoEncoderHandle;
    VIDEO_COMPONENT_TYPE_T *enc_prVideoSourceHandle;

    /* encode data buffer related variables */
    VIDEO_COMM_STATE_T rCommState;
    kal_mutexid eMutex;  // for VideoComm
    VIDEO_BUFFERHEADER_TYPE_T enc_data;
    kal_uint8 u1Uplink_denominator;
    kal_uint8 u1Uplink_numerator;

    /* decode data buffer related variables */
    VideoCall_dec_data_struct dec_data[50];
    VIDEO_BUFFERHEADER_TYPE_T dec_buff_header;

    kal_uint8 dec_data_start_ind;
    kal_uint8 dec_data_end_ind;
    VIDEO_BUFFERHEADER_TYPE_T *dec_buf_header;

    /* enc component param*/
    VIDEO_ENCODER_TYPE_T eEncoderType;

    /* dec component param*/
    kal_uint64 dec_param_stream_time;   /* the related time from 1st frame*/
    kal_uint64 dec_param_RecoverTolerance;  /* Indicate how much time scheduler can handle AV unsync tolerance in us */
    kal_uint32 dec_param_PlaySpeed;
    kal_uint64 dec_param_StartTime;
    kal_bool dec_param_audio_enable;
    va2_video_renderer_rotate_flip_t dec_param_rot_flip;
    VA2_FRAME_SIZE_T  dec_param_fb_size;	

    /* callback function */
    PFN_EVENT_CALLBACK_T *prEncCallback;
    PFN_EVENT_CALLBACK_T *prDecCallback;

    /* flag */
    kal_bool recv_first_pkt;
    kal_bool enc_is_open;
    kal_bool fg_init_ILClient;
    kal_bool on_stop_enc;
    kal_bool fg_consume_enc_fail;

}VideoCall_context;


typedef enum
{
    VT_NO_ERROR = 0,
    VT_ERROR_FULL,
    VT_ERROR_EMPTY,
    VT_ERROR_END
} VideoCall_Error_Code_enum;

extern VideoCall_Error_Code_enum VideoCall_init_encoder(VideoCall_enc_init_param_struct param);
extern VideoCall_Error_Code_enum VideoCall_deinit_encoder(VideoCall_enc_deinit_param_struct param);
extern VideoCall_Error_Code_enum VideoCall_open_encoder(VideoCall_enc_open_param_struct param);
extern VideoCall_Error_Code_enum VideoCall_close_encoder(VideoCall_enc_close_param_struct param);

extern VideoCall_Error_Code_enum VideoCall_init_decoder(VideoCall_dec_init_param_struct param);
extern VideoCall_Error_Code_enum VideoCall_open_decoder(VideoCall_dec_open_param_struct param);
extern VideoCall_Error_Code_enum VideoCall_close_decoder(VideoCall_dec_close_param_struct param);
extern VideoCall_Error_Code_enum VideoCall_pause_decoder(VideoCall_dec_pause_param_struct param);
extern VideoCall_Error_Code_enum VideoCall_resume_decoder(VideoCall_dec_resume_param_struct param);

extern VideoCall_Error_Code_enum VideoCall_trigger_decoder(VideoCall_dec_trigger_param_struct param);

extern VideoCall_Error_Code_enum VideoCall_alloc_Memory(VideoCall_alloc_memory_struct param);
extern VideoCall_Error_Code_enum VideoCall_free_Memory(VideoCall_free_memory_struct param);

extern VideoCall_Error_Code_enum VideoCall_get_enc_data(VIDEO_BUFFERHEADER_TYPE_T* enc_data);
extern kal_bool VideoCall_Enc_InputIsblockYUV(void);
extern VideoCall_Error_Code_enum VideoCall_Enc_UpdateI(void);
extern void VideoCall_consume_encoder(VideoCall_enc_consume_param_struct* param);
extern VideoCall_Error_Code_enum VideoCall_Get_Snapshot(VideoCall_dec_get_snapshot_param_struct param);
extern VideoCall_Error_Code_enum VideoCall_Dec_ControlVOS(MPL_VT_CONTROL_VOS_T pVos);

extern void VideoCall_init_ILClient(VideoCall_ilclient_init_param_struct param);
extern void VideoCall_deinit_ILClient(VideoCall_ilclient_deinit_param_struct param);

#endif

#endif

