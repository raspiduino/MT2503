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
 *   bitstream.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains function prototypes of bitstream APIs.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#ifndef _BITSTREAM_H
#define _BITSTREAM_H

#include "kal_general_types.h"
#include "med_global.h"
#include "stack_config.h"
#include "med_struct.h"
#include "kal_release.h"
#include "app_ltlcom.h"
    
/*----------------------------------------------------------------*/
/* Defines                                                        */
/*----------------------------------------------------------------*/

#define BITSTREAM_WAIT_EVENT(evt_) do{                                  \
            kal_uint32 retrieved_events;                          \
            kal_retrieve_eg_events(bitstream_cntx_p->bs_event, (evt_), \
            KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define BITSTREAM_SET_EVENT(evt_) kal_set_eg_events(bitstream_cntx_p->bs_event, (evt_),KAL_OR)


#define BITSTREAM_SET_RESULT(result_) do{              \
            bitstream_cntx_p->return_status = result_; \
            BITSTREAM_RETURN_TRACE(result_); }while(0)

#define BITSTREAM_RETURN(ret_value) do{                  \
            bitstream_cntx_p->return_status = ret_value; \
            BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);           \
            BITSTREAM_RETURN_TRACE(ret_value);           \
            return; }while(0)


#define BITSTREAM_MAX_VID_SESSION_NUM   (1)

#define BITSTREAM_NALU_TYPE_SPS         (7)
#define BITSTREAM_NALU_TYPE_PPS         (8)
#define BITSTREAM_NALU_TYPE_MASK        (0x1F)
#define BITSTREAM_MAX_H264_SPS_LEN    64
#define BITSTREAM_MAX_H264_PPS_LEN    64
#define BITSTREAM_MAX_CFG_RECORD_SIZE (BITSTREAM_MAX_H264_SPS_LEN + BITSTREAM_MAX_H264_PPS_LEN + 6)

#if 0
/* under construction !*/
#endif

#ifdef __BITSTREAM_DEBUG_ON__
#define BITSTREAM_VID_DUMP_PATH   L"c:\\bs_vdo."
#endif /* __BITSTREAM_DEBUG_ON__ */


/*----------------------------------------------------------------*/
/* Enums                                                          */
/*----------------------------------------------------------------*/
typedef enum
{
    BITSTREAM_EVT_NOWAIT =        0,
    BITSTREAM_EVT_WAIT =     0x0001
}
bitstream_wait_event_enum;


typedef enum
{
    BITSTREAM_VIDEO_STATE_IDLE,
    BITSTREAM_VIDEO_STATE_STOP,
    BITSTREAM_VIDEO_STATE_PLAY,

    BITSTREAM_VIDEO_STATE_TOTAL
} bitstream_video_state_enum;


typedef enum
{
    BITSTREAM_CODEC_TYPE_NONE,
/* audio */
    BITSTREAM_CODEC_TYPE_AMR,
/* video */
    BITSTREAM_CODEC_TYPE_H264,

    BITSTREAM_CODEC_TYPE_TOTAL
} bitstream_codec_type_enum;

/*----------------------------------------------------------------*/
/* Structs                                                        */
/*----------------------------------------------------------------*/

typedef struct
{
    kal_eventgrpid bs_event;
    kal_int32 return_status;
   
} bitstream_context_struct;


/*----------------------------------------------------------------*/
/* Function Definitions                                           */
/*----------------------------------------------------------------*/
/* bitstream_main.c */
extern kal_bool bitstream_init(void);
extern void bitstream_main(ilm_struct *ilm_ptr);

/* bitstream_audio.c */
extern void bitstream_audio_init(void);
extern void bitstream_audio_driver_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void bitstream_audio_open_req_hdlr(ilm_struct *ilm_ptr);
extern void bitstream_audio_close_req_hdlr(ilm_struct *ilm_ptr);
extern void bitstream_audio_get_buffer_status_req_hdlr(ilm_struct *ilm_ptr);
extern void bitstream_audio_put_data_req_hdlr(ilm_struct *ilm_ptr);
extern void bitstream_audio_put_frame_req_hdlr(ilm_struct *ilm_ptr);
extern void bitstream_audio_start_req_hdlr(ilm_struct *ilm_ptr);
extern void bitstream_audio_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void bitstream_audio_finished_req_hdlr(ilm_struct *ilm_ptr);
extern void bitstream_audio_get_play_time_req_hdlr(ilm_struct *ilm_ptr);

/* bitstream_record.c */
extern void bitstream_record_driver_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void bitstream_record_open_req_hdlr(ilm_struct *ilm_ptr);
extern void bitstream_record_close_req_hdlr(ilm_struct *ilm_ptr);
extern void bitstream_record_start_req_hdlr(ilm_struct *ilm_ptr);
extern void bitstream_record_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void bitstream_record_get_req_hdlr(ilm_struct *ilm_ptr);
extern void bitstream_record_set_req_hdlr(ilm_struct *ilm_ptr);

/*----------------------------------------------------------------*/
/* Global variable                                                */
/*----------------------------------------------------------------*/
extern bitstream_context_struct *bitstream_cntx_p;

#endif /* _BITSTREAM_H */ 

