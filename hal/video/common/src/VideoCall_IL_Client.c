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
 *  VideoCall_IL_Client.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "drv_features_video.h"
#if defined(__VE_VIDEO_ARCHI_V2__) && defined(__VE_VIDEO_VT_SUPPORT__)
#include "VideoCall_IL_Client.h"
#include "video_recorder_source_component_if_v2.h"
#include "video_recorder_clock_utility_if_v2.h"
#include "video_encoder_component_if_v2.h"
#include "video_decscheduler_component_if_v2.h"
#include "video_decoder_component_v2.h"
#include "vcodec_v2_trc.h"

#include "video_types_v2.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_release.h"
#include "video_comm_component_v2.h"
#include "string.h"
#include "va2_comp_video_renderer.h"
#include "video_buffer_management_v2.h"
#include "custom_video_enc_if.h"

#include "drv_comm.h"

VideoCall_context vt_il_ctx;

static VIDEO_ERROR_TYPE_T VideoCall_dec_decorder_evt_hdlr(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData);
static VIDEO_ERROR_TYPE_T VideoCall_dec_scheduler_evt_hdlr(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData);
static VIDEO_ERROR_TYPE_T VideoCall_dec_render_evt_hdlr(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData);
static VIDEO_ERROR_TYPE_T VideoCall_enc_source_evt_hdlr(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData);
static VIDEO_ERROR_TYPE_T VideoCall_enc_encorder_evt_hdlr(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData);

static const VIDEO_CALLBACK_TYPE_T _VT_VideoDecoderCallback =
{
    VideoCall_dec_decorder_evt_hdlr
};

static const VIDEO_CALLBACK_TYPE_T _VT_VideoSchedulerCallback =
{
    VideoCall_dec_scheduler_evt_hdlr
};

static const VIDEO_CALLBACK_TYPE_T _VT_VideoRenderCallback =
{
    VideoCall_dec_render_evt_hdlr
};

static const VIDEO_CALLBACK_TYPE_T _VT_VideoSourceCallback =
{
    VideoCall_enc_source_evt_hdlr
};

static const VIDEO_CALLBACK_TYPE_T _VT_VideoEncoderCallback =
{
    VideoCall_enc_encorder_evt_hdlr
};

#define COMP_GET_ENC_HANDLE()     \
    do{\
    vt_il_ctx.enc_prVideoSourceHandle = GetVideoRecorderSourceHandle(VIDEO_RECORDER_SOURCE_COMM, vt_il_ctx.ext_handler_ptr);  \
    ASSERT(vt_il_ctx.enc_prVideoSourceHandle != NULL);                                                                               \
    vt_il_ctx.enc_prVideoEncoderHandle = GetVideoEncoderHandle(VIDEO_ENCODER_UNKNOWN_VT, vt_il_ctx.ext_handler_ptr, vt_il_ctx.int_handler_ptr);             \
    ASSERT(vt_il_ctx.enc_prVideoEncoderHandle != NULL);} while(0)

#define COMP_RELEASE_ENC_HANDLE()   \
    do{\
    err_code = ReleaseVideoRecorderSourceHandle(vt_il_ctx.enc_prVideoSourceHandle);             \
    ASSERT(err_code == VIDEO_ERROR_NONE);                                                                      \
    err_code = ReleaseVideoEncoderHandle(vt_il_ctx.enc_prVideoEncoderHandle);                     \
    ASSERT(err_code == VIDEO_ERROR_NONE);} while(0)

#define COMP_GET_DEC_HANDLE()     \
    do{\
    vt_il_ctx.dec_prVideoDecoderHandle = GetVideoDecoderHandle(&rDecoderConfig).pComponent;           \
    ASSERT(vt_il_ctx.dec_prVideoDecoderHandle != NULL);                                                                           \
    vt_il_ctx.dec_prVideoSchedulerHandle = GetVideoDecSchedulerHandle(VIDEO_SCHEDULER_COMM, vt_il_ctx.ext_handler_ptr);                \
    ASSERT(vt_il_ctx.dec_prVideoSchedulerHandle != NULL);                                                                        \
    vt_il_ctx.dec_prVideoRenderHandle = GetVideoRendererHandle(VIDEO_RENDERER_VIDEO_TELEPHONY, vt_il_ctx.ext_handler_ptr, vt_il_ctx.int_handler_ptr);    \
    ASSERT(vt_il_ctx.dec_prVideoRenderHandle != NULL);} while(0)

#define COMP_RELEASE_DEC_HANDLE()   \
    do{\
    err_code = ReleaseVideoDecoderHandle(vt_il_ctx.dec_prVideoDecoderHandle);       \
    ASSERT(err_code == VIDEO_ERROR_NONE);                                                       \
    err_code = ReleaseVideoDecSchedulerHandle(vt_il_ctx.dec_prVideoSchedulerHandle);  \
    ASSERT(err_code == VIDEO_ERROR_NONE);                                                       \
    err_code = ReleaseVideoRendererHandle(vt_il_ctx.dec_prVideoRenderHandle);       \
    ASSERT(err_code == VIDEO_ERROR_NONE);} while(0)

#define COMP_SET_STATE_AND_CHECK(comp,state) \
    do{\
    err_code = vt_il_ctx.##comp##->pfnSendCommand(VIDEO_COMMAND_STATESET, state); \
    ASSERT(err_code == VIDEO_ERROR_NONE);} while(0)

#define COMP_WAIT_STATE_NOTIFY(mode, MODE, COMP) \
    do{\
    kal_retrieve_eg_events(vt_il_ctx.##mode##Event, (VT_VIDEO_##MODE##_EVENT_##COMP##_COMPLETE|VT_VIDEO_##MODE##_EVENT_##COMP##_ERROR), KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);     \
    ASSERT((u4EventGroup&VT_VIDEO_##MODE##_EVENT_##COMP##_ERROR) == 0);} while(0)

#define COMP_SET_STATE(comp,state,COMP)                          \
    do{\
    COMP_SET_STATE_AND_CHECK(##comp##,##state##);     \
    COMP_WAIT_STATE_NOTIFY(dec,DEC,##COMP##);} while(0)

#define ENC_COMP_SET_STATE(state) \
    do{\
    COMP_SET_STATE_AND_CHECK(enc_prVideoSourceHandle, ##state##);        \
    COMP_SET_STATE_AND_CHECK(enc_prVideoEncoderHandle, ##state##);      \
    COMP_WAIT_STATE_NOTIFY(enc,ENC,SOURCE);                                                           \
    COMP_WAIT_STATE_NOTIFY(enc,ENC,ENCODER);} while(0)

#define DEC_COMP_SET_BW_STATE(state) \
    do{\
    COMP_SET_STATE_AND_CHECK(dec_prVideoRenderHandle, ##state##);        \
    COMP_SET_STATE_AND_CHECK(dec_prVideoSchedulerHandle, ##state##);    \
    COMP_SET_STATE_AND_CHECK(dec_prVideoDecoderHandle, ##state##);      \
    COMP_WAIT_STATE_NOTIFY(dec,DEC,RENDER);                                                           \
    COMP_WAIT_STATE_NOTIFY(dec,DEC,SCHEDULER);                                                      \
    COMP_WAIT_STATE_NOTIFY(dec,DEC,DECODER);} while(0)

#define DEC_COMP_SET_FW_STATE(state) \
    do{\
    COMP_SET_STATE_AND_CHECK(dec_prVideoDecoderHandle, ##state##);      \
    COMP_SET_STATE_AND_CHECK(dec_prVideoSchedulerHandle, ##state##);    \
    COMP_SET_STATE_AND_CHECK(dec_prVideoRenderHandle, ##state##);        \
    COMP_WAIT_STATE_NOTIFY(dec,DEC,DECODER);                                                        \
    COMP_WAIT_STATE_NOTIFY(dec,DEC,SCHEDULER);                                                     \
    COMP_WAIT_STATE_NOTIFY(dec,DEC,RENDER);} while(0)

#define COMP_SET_PARAM(comp, param, arg) \
    do{\
    err_code = vt_il_ctx.##comp##->pfnSetParameter(##param##, (void*) ##arg##);  \
    ASSERT(err_code == VIDEO_ERROR_NONE);} while(0)

//extern void vcall_enc_data_callback(void * param);
//extern void vcall_dec_data_callback(void * param);

/*****************************************************************************
 * FUNCTION
 *  VideoCall_enc_source_evt_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  VideoCall_VT_EVT
 * RETURNS
 *  void
 *****************************************************************************/
static VIDEO_ERROR_TYPE_T VideoCall_enc_source_evt_hdlr(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(u4Data1 == VIDEO_COMMAND_STATESET)
    {
        if(eEvent == VIDEO_EVENT_COMPLETE)
        {
            kal_set_eg_events(vt_il_ctx.encEvent, VT_VIDEO_ENC_EVENT_SOURCE_COMPLETE, KAL_OR);
        }
    }
    return eError;
}


/*****************************************************************************
 * FUNCTION
 *  VideoCall_enc_encorder_evt_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  VideoCall_VT_EVT
 * RETURNS
 *  void
 *****************************************************************************/
static VIDEO_ERROR_TYPE_T VideoCall_enc_encorder_evt_hdlr(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(u4Data1 == VIDEO_COMMAND_STATESET)
    {
        if(eEvent == VIDEO_EVENT_COMPLETE)
        {
            kal_set_eg_events(vt_il_ctx.encEvent, VT_VIDEO_ENC_EVENT_ENCODER_COMPLETE, KAL_OR);
        }
    }
    return eError;
}


/*****************************************************************************
 * FUNCTION
 *  VideoCall_enc_med_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  VCALL_VT_EVT
 * RETURNS
 *  void
 *****************************************************************************/
static VIDEO_ERROR_TYPE_T VideoCall_enc_med_callback(VIDEO_BUFFERHEADER_TYPE_T *buf_header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_bool fgRet = KAL_FALSE;
    VIDEO_COMM_STATE_T* const prCommState = &vt_il_ctx.rCommState;

    drv_trace8(TRACE_GROUP_10, VCALL_IL_ENC_CALLBACK, (kal_uint32)buf_header->pu1Buffer,buf_header->u4BuffSize,buf_header->eFlags,
        (kal_uint32)((buf_header->u8TimeStamp>>32)&0xFFFFFFFF),(kal_uint32)((buf_header->u8TimeStamp)&0xFFFFFFFF),buf_header->pu1Buffer[2],buf_header->pu1Buffer[3],buf_header->pu1Buffer[4]);

    ASSERT(buf_header->u4BuffSize > 0);

        if(vt_il_ctx.on_stop_enc)
        {
            while(VideoCommPopInputBuff(prCommState, &vt_il_ctx.enc_data))
            {
                vt_il_ctx.enc_prVideoEncoderHandle->pfnFillThisBuffer(&vt_il_ctx.enc_data);
            }
            vt_il_ctx.enc_prVideoEncoderHandle->pfnFillThisBuffer(buf_header);
            return VIDEO_ERROR_NONE;
        }
        else if (vt_il_ctx.fg_consume_enc_fail && vt_il_ctx.enc_data.u4BuffSize != 0)
        {
            if(vt_il_ctx.enc_prVideoEncoderHandle->pfnFillThisBuffer(&vt_il_ctx.enc_data) == VIDEO_ERROR_NONE)
            {
                vt_il_ctx.enc_data.u4BuffSize = 0;
                vt_il_ctx.fg_consume_enc_fail = KAL_FALSE;
            }
            return VIDEO_ERROR_BUFF_FULL;
        }
        else
        {
            fgRet = VideoCommPushInputBuff(prCommState, buf_header);
            if (fgRet == KAL_FALSE)
            {
                //error handling
                return VIDEO_ERROR_BUFF_FULL;
            }
            else
                (*vt_il_ctx.prEncCallback)((void*) buf_header);
        }

    return VIDEO_ERROR_NONE;
}




/*****************************************************************************
 * FUNCTION
 *  VideoCall_dec_decorder_evt_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  VideoCall_VT_EVT
 * RETURNS
 *  void
 *****************************************************************************/
static VIDEO_ERROR_TYPE_T VideoCall_dec_decorder_evt_hdlr(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (u4Data1 == VIDEO_COMMAND_STATESET)
    {
        if (eEvent == VIDEO_EVENT_COMPLETE)
        {
            kal_set_eg_events(vt_il_ctx.decEvent, VT_VIDEO_DEC_EVENT_DECODER_COMPLETE, KAL_OR);
        }

    }

    return eError;
}


/*****************************************************************************
 * FUNCTION
 *  VideoCall_dec_scheduler_evt_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  VideoCall_VT_EVT
 * RETURNS
 *  void
 *****************************************************************************/
static VIDEO_ERROR_TYPE_T VideoCall_dec_scheduler_evt_hdlr(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (u4Data1 == VIDEO_COMMAND_STATESET)
    {
        if (eEvent == VIDEO_EVENT_COMPLETE)
        {
            kal_set_eg_events(vt_il_ctx.decEvent, VT_VIDEO_DEC_EVENT_SCHEDULER_COMPLETE, KAL_OR);
        }

    }

    return eError;
}


/*****************************************************************************
 * FUNCTION
 *  VideoCall_dec_clock_evt_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  VideoCall_VT_EVT
 * RETURNS
 *  void
 *****************************************************************************/
static VIDEO_ERROR_TYPE_T VideoCall_dec_clock_evt_hdlr(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (u4Data1 == VIDEO_COMMAND_STATESET)
    {
        if (eEvent == VIDEO_EVENT_COMPLETE)
        {
            kal_set_eg_events(vt_il_ctx.decEvent, VT_VIDEO_DEC_EVENT_CLOCK_COMPLETE, KAL_OR);
        }

    }

    return eError;
}


/*****************************************************************************
 * FUNCTION
 *  VideoCall_dec_render_evt_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  VideoCall_VT_EVT
 * RETURNS
 *  void
 *****************************************************************************/
static VIDEO_ERROR_TYPE_T VideoCall_dec_render_evt_hdlr(VIDEO_EVENT_TYPE_T eEvent, kal_uint32 u4Data1, kal_uint32 u4Data2, void* pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (u4Data1 == VIDEO_COMMAND_STATESET)
    {
        if (eEvent == VIDEO_EVENT_COMPLETE)
        {
            kal_set_eg_events(vt_il_ctx.decEvent, VT_VIDEO_DEC_EVENT_RENDER_COMPLETE, KAL_OR);
        }
    }
    return eError;
}


/*****************************************************************************
 * FUNCTION
 *  VideoCall_dec_med_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  VideoCall_VT_EVT
 * RETURNS
 *  void
 *****************************************************************************/
static VIDEO_ERROR_TYPE_T VideoCall_dec_med_callback(VIDEO_BUFFERHEADER_TYPE_T *buf_header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VIDEO_ERROR_TYPE_T result = VIDEO_ERROR_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_trace8(TRACE_GROUP_10, VCALL_IL_DEC_CALLBACK, (kal_uint32)buf_header->pu1Buffer,buf_header->u4BuffSize,buf_header->eFlags,
      (kal_uint32)((buf_header->u8TimeStamp>>32)&0xFFFFFFFF),(kal_uint32)((buf_header->u8TimeStamp)&0xFFFFFFFF),buf_header->pu1Buffer[2],buf_header->pu1Buffer[3],buf_header->pu1Buffer[4]);
    (*vt_il_ctx.prDecCallback)((void*)&vt_il_ctx.dec_data[vt_il_ctx.dec_data_start_ind]);
    vt_il_ctx.dec_data_start_ind = (vt_il_ctx.dec_data_start_ind +1)%50;
    return result;

}

/*****************************************************************************
 * FUNCTION
 *  VideoCall_consume_encoder
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
void VideoCall_consume_encoder(VideoCall_enc_consume_param_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_trace2(TRACE_GROUP_10, VCALL_IL_ENC_CONSUME, (kal_uint32)param->u4Uplink_numerator,(kal_uint32)param->u4Uplink_denominator);
    vt_il_ctx.u1Uplink_denominator = param->u4Uplink_denominator;
    vt_il_ctx.u1Uplink_numerator= param->u4Uplink_numerator;

    if(vt_il_ctx.enc_is_open)
    {
        if(vt_il_ctx.enc_data.u4BuffSize == 0)
        {
            ASSERT(0);  // The enc_data.u4BuffSize should > 0
        }
        if(vt_il_ctx.enc_prVideoEncoderHandle->pfnFillThisBuffer(&vt_il_ctx.enc_data) == VIDEO_ERROR_NONE)
        {
            vt_il_ctx.enc_data.u4BuffSize = 0;
            vt_il_ctx.fg_consume_enc_fail = KAL_FALSE;
        }
        else
        {
            // ASSERT(0); //It maybe fail due to V2DEC can't run.
            vt_il_ctx.fg_consume_enc_fail = KAL_TRUE;
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  VideoCall_GetUplinkInfo
 * DESCRIPTION
 *
 * PARAMETERS
 *  VCALL_UPLINK_INFO_T*
 * RETURNS
 *  void
 *****************************************************************************/
void VideoCall_GetUplinkInfo(VCALL_UPLINK_INFO_T* param)
{
    param->u1denominator = vt_il_ctx.u1Uplink_denominator;
    param->u1numerator = vt_il_ctx.u1Uplink_numerator;
}

/*****************************************************************************
 * FUNCTION
 *  VideoCall_get_enc_data
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
VideoCall_Error_Code_enum VideoCall_get_enc_data(VIDEO_BUFFERHEADER_TYPE_T* enc_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VideoCall_Error_Code_enum result = VT_NO_ERROR;
    VIDEO_COMM_STATE_T* const prCommState = &vt_il_ctx.rCommState;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

     if(!vt_il_ctx.enc_is_open)
         ASSERT(0);

     if (VideoCommPopInputBuff(prCommState, &vt_il_ctx.enc_data))
     {
        MPEG4_PACKET_INPUT_PARAM_T* packet_data;
        packet_data = vt_il_ctx.enc_data.pPrivateData;

         memcpy(enc_data, &vt_il_ctx.enc_data, sizeof(VIDEO_BUFFERHEADER_TYPE_T));
         drv_trace8(TRACE_GROUP_10,VCALL_IL_ENC_GET_DATA,(kal_uint32)vt_il_ctx.enc_data.pu1Buffer,vt_il_ctx.enc_data.u4BuffSize,
            packet_data->u4PayloadNumber,packet_data->pu1PayloadAddress->u4Address, packet_data->pu1PayloadAddress->u4Length,
            ((kal_uint8*)packet_data->pu1PayloadAddress->u4Address)[2],((kal_uint8*)packet_data->pu1PayloadAddress->u4Address)[3],
            ((kal_uint8*)packet_data->pu1PayloadAddress->u4Address)[4]);
     }
     else
         result = VT_ERROR_EMPTY;
     return result;
}


/*****************************************************************************
 * FUNCTION
 *  VideoCall_Enc_UpdateI
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
VideoCall_Error_Code_enum VideoCall_Enc_UpdateI()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VideoCall_Error_Code_enum result = VT_NO_ERROR;
    VIDEO_ERROR_TYPE_T err_code;
    kal_bool encodeI = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     if(!vt_il_ctx.enc_is_open)
         return result;

    //drv_trace0(TRACE_GROUP_10, VIDEOCALL_DRV_TRC_ENC_UPDATE_I);
    drv_trace0(TRACE_GROUP_10,VCALL_IL_ENC_UPDATE_I);
     COMP_SET_PARAM(enc_prVideoEncoderHandle, VIDEO_PARAM_ENCODER_ENCODE_I, &encodeI);

     return result;
}

/*****************************************************************************
 * FUNCTION
 *  VideoCall_Dec_ControlVOS
 * DESCRIPTION
 *
 * PARAMETERS
 *  MPL_VT_CONTROL_VOS_T* pVos
 * RETURNS
 *  VideoCall_Error_Code_enum
 *****************************************************************************/
VideoCall_Error_Code_enum VideoCall_Dec_ControlVOS(MPL_VT_CONTROL_VOS_T pVos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VideoCall_Error_Code_enum result = VT_NO_ERROR;
    VT_CTRL_VOS_T param;
    VIDEO_ERROR_TYPE_T err_code;

    param.pu1BufferAddr = pVos.u4Address;
    param.u4BuffSize = pVos.u4Length;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     ASSERT(vt_il_ctx.dec_prVideoDecoderHandle);
     COMP_SET_PARAM(dec_prVideoDecoderHandle, VIDEO_PARAM_SET_CTRL_VOS, &param);

     return result;
}


/*****************************************************************************
 * FUNCTION
 *  VideoCall_Enc_InputIsblockYUV
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool VideoCall_Enc_InputIsblockYUV()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool fgBlockYUV = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(vt_il_ctx.enc_prVideoEncoderHandle != NULL);
    vt_il_ctx.enc_prVideoEncoderHandle->pfnGetParameter(VIDEO_PARAM_ENCODER_IS_BLOCKBASED_YUV, &fgBlockYUV);

    drv_trace0(TRACE_GROUP_10, VCALL_IL_ENC_IS_BLOCK_YUV);
    return fgBlockYUV;
}

/*****************************************************************************
 * FUNCTION
 *  VideoCall_init_encoder
 * DESCRIPTION
 *  init video encoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VideoCall_Error_Code_enum VideoCall_init_encoder(VideoCall_enc_init_param_struct param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VideoCall_Error_Code_enum result = VT_NO_ERROR;
    VIDEO_ERROR_TYPE_T err_code;
    kal_uint32 u4EventGroup;
    VENC_RESOLUTION_T encoder_resolution;

    VIDEO_PORT_CONFIG_T rVideoConfig;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* create encoder part ilClient inner component*/
    VIDEO_COMPONENT_INIT_T rInitConfig;
    drv_trace4(TRACE_GROUP_10,VCALL_IL_ENC_INIT,param.width,param.height,param.bitrate, 0);

    kal_mem_set((void*)&rVideoConfig, 0, sizeof(rVideoConfig));
    rVideoConfig.ePortType    = VIDEO_PORT_VIDEO_DATA;
    rVideoConfig.fgSupplier   = KAL_FALSE;

    rInitConfig.prInputPort1 = &rVideoConfig;
    rInitConfig.prInputPort2 = NULL;
    rInitConfig.prOutputPort1 = NULL;
    rInitConfig.prOutputPort2 = NULL;
    rInitConfig.u4CmdQSize = 0;
    rInitConfig.u4InputBuffQSize = VIDEO_VT_IL_INPUT_BUFFER_Q_NUM;
    rInitConfig.u4OutputBuffQSize = 0;
    rInitConfig.prExtMemHdlr = vt_il_ctx.ext_handler_ptr;
    vt_il_ctx.eMutex = rInitConfig.eMutex = VideoGetMutex(MUTEX_USER_VTMPL);
    err_code = VideoCommInit(&vt_il_ctx.rCommState, &rInitConfig, "VT_IL");
    ASSERT(err_code == VIDEO_ERROR_NONE);
    vt_il_ctx.rCommState.eState = VIDEO_STATE_INIT;

    /* create conponent */
    VRCLK_ResetAll();
    COMP_GET_ENC_HANDLE();

    /* set conponent CB*/
    err_code = vt_il_ctx.enc_prVideoSourceHandle->pfnSetCallbacks((VIDEO_CALLBACK_TYPE_T *)&_VT_VideoSourceCallback);
    ASSERT(err_code == VIDEO_ERROR_NONE);

    err_code = vt_il_ctx.enc_prVideoEncoderHandle->pfnSetCallbacks((VIDEO_CALLBACK_TYPE_T *)&_VT_VideoEncoderCallback);
    ASSERT(err_code == VIDEO_ERROR_NONE);

    ENC_COMP_SET_STATE(VIDEO_STATE_INIT);

    /* connect these conponents */
    err_code = VideoSetupTunnel(vt_il_ctx.enc_prVideoSourceHandle, vt_il_ctx.enc_prVideoEncoderHandle, VIDEO_PORT_VIDEO_DATA);
    ASSERT(err_code == VIDEO_ERROR_NONE);

    err_code = VideoConfigComp(vt_il_ctx.enc_prVideoEncoderHandle, KAL_FALSE, VIDEO_PORT_VIDEO_DATA, VideoCall_enc_med_callback);
    ASSERT(err_code == VIDEO_ERROR_NONE);

    /* set conponent param */
    //COMP_SET_PARAM(enc_prVideoEncoderHandle, VIDEO_PARAM_ENCODER_WIDTH, &param.width);
    //COMP_SET_PARAM(enc_prVideoEncoderHandle, VIDEO_PARAM_ENCODER_HEIGHT, &param.height);
    encoder_resolution.u4EncodeWidth = param.width;
    encoder_resolution.u4EncodeHeight = param.height;
    COMP_SET_PARAM(enc_prVideoEncoderHandle, VIDEO_PARAM_ENCODER_RESOLUTION, &encoder_resolution);
    COMP_SET_PARAM(enc_prVideoEncoderHandle, VIDEO_PARAM_ENCODER_BITRATE, &param.bitrate);

    /* set conponent state as idle */
    ENC_COMP_SET_STATE(VIDEO_STATE_IDLE);
    VRCLK_ResetTime();

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  VideoCall_deinit_encoder
 * DESCRIPTION
 *  stop video encoder
 * PARAMETERS
 *  kal_bool
 * RETURNS
 *  void
 *****************************************************************************/
VideoCall_Error_Code_enum VideoCall_deinit_encoder(VideoCall_enc_deinit_param_struct param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VideoCall_Error_Code_enum result = VT_NO_ERROR;
    VIDEO_ERROR_TYPE_T err_code = VIDEO_ERROR_NONE;
    kal_uint32 u4EventGroup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_trace1(TRACE_GROUP_10,VCALL_IL_ENC_DEINIT,param.is_running);

    if(param.is_running)
    {
        kal_bool stop_enc_now = KAL_TRUE;
        VIDEO_STATE_TYPE_T eState;

        err_code = vt_il_ctx.enc_prVideoEncoderHandle->pfnGetParameter(
                VIDEO_PARAM_ENCODER_GET_STATE, &eState);
        if (VIDEO_STATE_RUN == eState)
        {
            COMP_SET_PARAM(enc_prVideoEncoderHandle, VIDEO_PARAM_ENCODER_STOP_INSTANTLY, &stop_enc_now);
        }

        /* set conponent state as stop */
        VRCLK_StopClock();
        ENC_COMP_SET_STATE(VIDEO_STATE_STOP);
    }

    /* set conponent state as close */
    ENC_COMP_SET_STATE(VIDEO_STATE_CLOSE);
    vt_il_ctx.enc_is_open = KAL_FALSE;

    /* destory conponent */
    COMP_RELEASE_ENC_HANDLE();
    VideoFreeMutex(MUTEX_USER_VTMPL, vt_il_ctx.eMutex);
    VideoCommDeInit(&vt_il_ctx.rCommState);
    vt_il_ctx.rCommState.eState = VIDEO_STATE_CLOSE;

    return result;

}

/*****************************************************************************
 * FUNCTION
 *  VideoCall_open_encoder
 * DESCRIPTION
 *  open and start video encoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

VideoCall_Error_Code_enum VideoCall_open_encoder(VideoCall_enc_open_param_struct param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VideoCall_Error_Code_enum result = VT_NO_ERROR;
    VIDEO_ERROR_TYPE_T err_code;
    kal_uint32 u4EventGroup;
    kal_uint32 u4MaxPacketSize = 512*8; // set bits to encoder
    const kal_bool fgUseAudioClock = KAL_FALSE;
    PFN_VCALL_GET_UPLINKINFO_T pfnVTGetupinfo = VideoCall_GetUplinkInfo;
    VENC_RESOLUTION_T encoder_resolution;
    //VIDEO_RECORDER_SOURCE_SCENARIO_T eScenario = VIDEO_RECORDER_SOURCE_SCENARIO_VT;
//    kal_uint32 u4FrameRate = vcall_video_enc_get_video_frame_rate();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_trace8(TRACE_GROUP_10,VCALL_IL_ENC_OPEN, param.width,param.height,param.bitrate,param.yuv_duration,
        param.yuv_addr,param.is_image_view,param.u4FrameRate,0);
    
    VideoCommClrAllQ(&vt_il_ctx.rCommState);

    if(MPL_VT_CODEC_MPEG4 == param.enc_param_EncoderType)
    {
        vt_il_ctx.eEncoderType = VIDEO_ENCODER_MPEG4_VT;
    }
    else if(MPL_VT_CODEC_H263 == param.enc_param_EncoderType)
    {
        vt_il_ctx.eEncoderType = VIDEO_ENCODER_H263_VT;
    }
    else
    {
        ASSERT(0);
    }

    //COMP_SET_PARAM(enc_prVideoSourceHandle, VIDEO_PARAM_RECODER_SOURCE_SECNARIO, &eScenario);
    COMP_SET_PARAM(enc_prVideoEncoderHandle, VIDEO_PARAM_ENCODER_SETUP_CODEC, &vt_il_ctx.eEncoderType);
    //COMP_SET_PARAM(enc_prVideoEncoderHandle, VIDEO_PARAM_ENCODER_WIDTH, &param.width);
    //COMP_SET_PARAM(enc_prVideoEncoderHandle, VIDEO_PARAM_ENCODER_HEIGHT, &param.height);
    encoder_resolution.u4EncodeWidth = param.width;
    encoder_resolution.u4EncodeHeight = param.height;
    COMP_SET_PARAM(enc_prVideoEncoderHandle, VIDEO_PARAM_ENCODER_RESOLUTION, &encoder_resolution);
	
    COMP_SET_PARAM(enc_prVideoEncoderHandle, VIDEO_PARAM_ENCODER_BITRATE, &param.bitrate);
    COMP_SET_PARAM(enc_prVideoEncoderHandle, VIDEO_PARAM_ENCODER_GEN_HEADER_FRM_RATE, &param.u4TimeIncrResolution);
    COMP_SET_PARAM(enc_prVideoEncoderHandle, VIDEO_PARAM_ENCODER_MAX_PKG_SIZE, &u4MaxPacketSize);
    VRCLK_SetClockProperties(fgUseAudioClock, MEDIA_FORMAT_UNKNOWN);
    COMP_SET_PARAM(enc_prVideoEncoderHandle, VIDEO_PARAM_ENCODER_FRAME_RATE, &param.u4FrameRate);
    COMP_SET_PARAM(enc_prVideoEncoderHandle, VIDEO_PARAM_ENCODER_VT_RESTART, &param.is_restartopen);
    COMP_SET_PARAM(enc_prVideoEncoderHandle, VIDEO_PARAM_ENCODER_SET_UPLINK_CALLBACK, &pfnVTGetupinfo);
    /* set encoder buf & feg to let driver update screen automatically when not use camera*/
    if(param.is_image_view)
    {
        COMP_SET_PARAM(enc_prVideoSourceHandle, VIDEO_PARAM_RECODER_SOURCE_YUV_INTERVAL, &param.yuv_duration);
        COMP_SET_PARAM(enc_prVideoSourceHandle, VIDEO_PARAM_RECODER_SOURCE_YUV_BUFFER, param.yuv_addr);
    }
    else
    {
        COMP_SET_PARAM(enc_prVideoSourceHandle, VIDEO_PARAM_RECODER_SOURCE_YUV_BUFFER, NULL);
    }

    /* set conponent state as run */
    VRCLK_StartClock();
    ENC_COMP_SET_STATE(VIDEO_STATE_RUN);

    vt_il_ctx.enc_is_open = KAL_TRUE;
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  VideoCall_close_encoder
 * DESCRIPTION
 *  stop and close video encoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VideoCall_Error_Code_enum VideoCall_close_encoder(VideoCall_enc_close_param_struct param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VideoCall_Error_Code_enum result = VT_NO_ERROR;
    VIDEO_ERROR_TYPE_T err_code = VIDEO_ERROR_NONE;
    VIDEO_COMM_STATE_T* const prCommState = &vt_il_ctx.rCommState;

    kal_uint32 u4EventGroup;
    kal_bool stop_enc_now = KAL_TRUE;
    kal_bool fgStopInstantly = KAL_TRUE;
    VIDEO_STATE_TYPE_T eState;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_trace0(TRACE_GROUP_10, VCALL_IL_ENC_CLOSE);
   while(VideoCommPopInputBuff(prCommState, &vt_il_ctx.enc_data))
   {
       vt_il_ctx.enc_prVideoEncoderHandle->pfnFillThisBuffer(&vt_il_ctx.enc_data);
   }


    /* to prevent encoder send un-sent packet to block MED / MMI  */
    err_code = vt_il_ctx.enc_prVideoEncoderHandle->pfnGetParameter(
                VIDEO_PARAM_ENCODER_GET_STATE, &eState);
    if (VIDEO_STATE_RUN == eState)
    {    
        COMP_SET_PARAM(enc_prVideoEncoderHandle, VIDEO_PARAM_ENCODER_STOP_INSTANTLY, &stop_enc_now);
    }
    COMP_SET_PARAM(enc_prVideoSourceHandle, VIDEO_PARAM_RECORDER_SOURCE_STOP_INSTANTLY, (void*)&fgStopInstantly);

    /* set conponent state as stop */
    vt_il_ctx.on_stop_enc = KAL_TRUE;
    VRCLK_StopClock();
    ENC_COMP_SET_STATE(VIDEO_STATE_STOP);
    ENC_COMP_SET_STATE(VIDEO_STATE_IDLE);
    vt_il_ctx.on_stop_enc = KAL_FALSE;
    vt_il_ctx.enc_is_open = KAL_FALSE;
    return result;
}

VideoCall_Error_Code_enum VideoCall_init_decoder(VideoCall_dec_init_param_struct param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VideoCall_Error_Code_enum result = VT_NO_ERROR;
    VIDEO_ERROR_TYPE_T err_code;
    kal_uint32 u4EventGroup;
    kal_bool bypass = KAL_TRUE;
    kal_bool keep_curr_ptr = KAL_FALSE;
    VIDEO_DECODER_HDLR_INFO_T rDecoderConfig;
    VIDEO_CONTAINER_INFO_T rContainerInfo;
	
//  kal_bool dec_triger_lcd = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_trace0(TRACE_GROUP_10,VCALL_IL_DEC_INIT);
    /* create conponent  and set CB */
	
    kal_mem_set(&rContainerInfo, 0, sizeof(VIDEO_CONTAINER_INFO_T));
    if( MPL_VT_CODEC_MPEG4 == param.dec_param_DecoderType)
    {
        rDecoderConfig.eCodec = VIDEO_CODEC_MPEG4;
    }
    else
    {
        rDecoderConfig.eCodec = VIDEO_CODEC_H263;    
    }
    rDecoderConfig.eScenario = VIDEO_SCENARIO_VT;
    rDecoderConfig.prContainerInfo = &rContainerInfo;
    rDecoderConfig.prExtMemHdr = vt_il_ctx.ext_handler_ptr;
    rDecoderConfig.prIntMexHdr = vt_il_ctx.int_handler_ptr;
	
    COMP_GET_DEC_HANDLE();

    err_code = vt_il_ctx.dec_prVideoDecoderHandle->pfnSetCallbacks((VIDEO_CALLBACK_TYPE_T *)&_VT_VideoDecoderCallback);
    ASSERT(err_code == VIDEO_ERROR_NONE);
    err_code = vt_il_ctx.dec_prVideoSchedulerHandle->pfnSetCallbacks((VIDEO_CALLBACK_TYPE_T *)&_VT_VideoSchedulerCallback);
    ASSERT(err_code == VIDEO_ERROR_NONE);
    err_code = vt_il_ctx.dec_prVideoRenderHandle->pfnSetCallbacks((VIDEO_CALLBACK_TYPE_T *)&_VT_VideoRenderCallback);
    ASSERT(err_code == VIDEO_ERROR_NONE);

    DEC_COMP_SET_BW_STATE(VIDEO_STATE_INIT);

    /* connect conponents */
    err_code = VideoConfigComp(vt_il_ctx.dec_prVideoDecoderHandle, KAL_TRUE, VIDEO_PORT_VIDEO_DATA, VideoCall_dec_med_callback);
    ASSERT(err_code == VIDEO_ERROR_NONE);
    err_code = VideoSetupTunnel(vt_il_ctx.dec_prVideoDecoderHandle, vt_il_ctx.dec_prVideoSchedulerHandle, VIDEO_PORT_VIDEO_DATA);
    ASSERT(err_code == VIDEO_ERROR_NONE);
    err_code = VideoSetupTunnel(vt_il_ctx.dec_prVideoSchedulerHandle, vt_il_ctx.dec_prVideoRenderHandle, VIDEO_PORT_VIDEO_DATA);
    ASSERT(err_code == VIDEO_ERROR_NONE);

    // TODO: note this!! for MT6268, IDP still need internal memory...please set it down via this this parameter as before...
    /* set dec param */
    vt_il_ctx.dec_param_stream_time = 0;
    vt_il_ctx.dec_param_RecoverTolerance = 10000000;
    vt_il_ctx.dec_param_PlaySpeed = 100;
    vt_il_ctx.dec_param_StartTime = 0;
    vt_il_ctx.dec_param_audio_enable = KAL_FALSE;
    vt_il_ctx.dec_param_rot_flip.b_flip = KAL_FALSE;
    vt_il_ctx.dec_param_rot_flip.u2_cw_rotate_angle= 0;
    vt_il_ctx.dec_param_fb_size.u4_width = param.dec_param_fb_size.u4_width;
    vt_il_ctx.dec_param_fb_size.u4_height = param.dec_param_fb_size.u4_height;	
    /*if encode HW update , decode no need to HW update */
    /*peer is HIDE mean background , also no need to update */
/*
    if(param.is_fg_dec)
        dec_triger_lcd = KAL_TRUE;
*/
    /* set conponent state as idle */
    DEC_COMP_SET_BW_STATE(VIDEO_STATE_IDLE);

    /* set conponent param */
    COMP_SET_PARAM(dec_prVideoSchedulerHandle, VIDEO_PARAM_AVSYNC_TOLERANCE0, &vt_il_ctx.dec_param_RecoverTolerance);
    COMP_SET_PARAM(dec_prVideoSchedulerHandle, VIDEO_PARAM_AUDIO_ON, &vt_il_ctx.dec_param_audio_enable);
    COMP_SET_PARAM(dec_prVideoSchedulerHandle, VIDEO_PARAM_PLAY_SPEED, &vt_il_ctx.dec_param_PlaySpeed);
    COMP_SET_PARAM(dec_prVideoSchedulerHandle, VIDEO_PARAM_START_TIME, &vt_il_ctx.dec_param_StartTime);
    COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DISPLAY_SURFACE, &param.lcd_data);	
    COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_BYPASS, &bypass);
    COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_KEEP_CURR_PTR, &keep_curr_ptr);
    //COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_INTERNAL_MEMORY, &param.dec_param_intmem);
    COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DST_FB_ADDR, &param.dec_param_fb);
    //COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DST_FB_ADDR, &param.dec_param_fb2); //render will allocate itself.
    COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_ROTATE_FLIP, &vt_il_ctx.dec_param_rot_flip);
    COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DST_FB_SIZE, &vt_il_ctx.dec_param_fb_size);
    COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_TRIGGER_DISPLAY, &param.dec_triger_lcd);
    COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_CONFIG_RENDERER_RESIZE_DST_SIZE, &param.dec_param_dst_size);
    COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DST_COLOR_FORMAT, &param.format);

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  VideoCall_open_decoder
 * DESCRIPTION
 *  open video decoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VideoCall_Error_Code_enum VideoCall_open_decoder(VideoCall_dec_open_param_struct param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VideoCall_Error_Code_enum result = VT_NO_ERROR;
    VIDEO_ERROR_TYPE_T err_code;
    kal_uint32 u4EventGroup;
    kal_bool fgEnableClock = KAL_TRUE;
    kal_bool bypass = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_trace0(TRACE_GROUP_10, VCALL_IL_DEC_OPEN);
    vt_il_ctx.dec_param_rot_flip.b_flip = param.dec_param_rot_flip.b_flip;
    vt_il_ctx.dec_param_rot_flip.u2_cw_rotate_angle = param.dec_param_rot_flip.u2_cw_rotate_angle;

    /* set conponent param */
    COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_BYPASS, &bypass);
    COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_ROTATE_FLIP, &vt_il_ctx.dec_param_rot_flip);

    /* set conponent state as run */
    DEC_COMP_SET_BW_STATE(VIDEO_STATE_RUN);

    /* set conponent param */
    COMP_SET_PARAM(dec_prVideoSchedulerHandle, VIDEO_PARAM_CLOCK_ENABLE, &fgEnableClock);

    vt_il_ctx.recv_first_pkt = KAL_FALSE;

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  VideoCall_close_decoder
 * DESCRIPTION
 *  close video decoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VideoCall_Error_Code_enum VideoCall_close_decoder(VideoCall_dec_close_param_struct param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VideoCall_Error_Code_enum result = VT_NO_ERROR;
    VIDEO_ERROR_TYPE_T err_code;
    kal_uint32 u4EventGroup;
    kal_bool fgEnableClock = KAL_FALSE;
    kal_bool dec_triger_lcd = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_trace0(TRACE_GROUP_10, VCALL_IL_DEC_CLOSE);

    COMP_SET_PARAM(dec_prVideoSchedulerHandle, VIDEO_PARAM_CLOCK_ENABLE, &fgEnableClock);

    /* set conponent state as stop */
    DEC_COMP_SET_FW_STATE(VIDEO_STATE_STOP);
    COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_TRIGGER_DISPLAY, &dec_triger_lcd);	
    /* set conponent state as close */
    DEC_COMP_SET_FW_STATE(VIDEO_STATE_CLOSE);

    /* destory conponent */
    COMP_RELEASE_DEC_HANDLE();

     return result;
}


/*****************************************************************************
 * FUNCTION
 *  VideoCall_update_decoder
 * DESCRIPTION
 *  update video decoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VideoCall_Error_Code_enum VideoCall_pause_decoder(VideoCall_dec_pause_param_struct param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VideoCall_Error_Code_enum result = VT_NO_ERROR;
    VIDEO_ERROR_TYPE_T err_code;
    kal_uint32 u4EventGroup;
    kal_bool dec_triger_lcd = KAL_FALSE;	

    drv_trace0(TRACE_GROUP_10,VCALL_IL_DEC_PAUSE);
    COMP_SET_STATE(dec_prVideoRenderHandle, VIDEO_STATE_STOP,RENDER);
    COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_TRIGGER_DISPLAY, &dec_triger_lcd);	
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  VideoCall_update_decoder
 * DESCRIPTION
 *  update video decoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VideoCall_Error_Code_enum VideoCall_resume_decoder(VideoCall_dec_resume_param_struct param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VideoCall_Error_Code_enum result = VT_NO_ERROR;
    VIDEO_ERROR_TYPE_T err_code;
    kal_uint32 u4EventGroup;
    kal_bool dec_triger_lcd = KAL_FALSE;
    kal_bool bypass = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vt_il_ctx.dec_param_fb_size.u4_width = param.dec_param_fb_size.u4_width;
    vt_il_ctx.dec_param_fb_size.u4_height = param.dec_param_fb_size.u4_height;	

	
    drv_trace8(TRACE_GROUP_10,VCALL_IL_DEC_RESUME,
        param.is_fg_dec,
        param.dec_param_fb.r_fb_addr.u4_fb_addr_plane0,
        param.dec_param_fb2.r_fb_addr.u4_fb_addr_plane0,
        param.dec_param_fb_size.u4_width,
        param.dec_param_fb_size.u4_height,
        param.dec_triger_lcd,
        param.dec_param_dst_size.u4_width,
        param.dec_param_dst_size.u4_height);

    vt_il_ctx.dec_param_rot_flip.b_flip = param.dec_param_rot_flip.b_flip;
    vt_il_ctx.dec_param_rot_flip.u2_cw_rotate_angle = param.dec_param_rot_flip.u2_cw_rotate_angle;

    if(param.is_fg_dec && param.is_peer_camera_on)
    {
        // Render must in STOP state
        COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DISPLAY_SURFACE, &param.lcd_data);
        COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DST_FB_ADDR, &param.dec_param_fb);
        //COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DST_FB_ADDR, &param.dec_param_fb2);  //render will allocate itself.
        COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DST_FB_SIZE, &vt_il_ctx.dec_param_fb_size);
        COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_TRIGGER_DISPLAY, &param.dec_triger_lcd);

	COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_CONFIG_RENDERER_RESIZE_DST_SIZE, &param.dec_param_dst_size);
        COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_ROTATE_FLIP, &vt_il_ctx.dec_param_rot_flip);
    }
    else
    {
        // Render must in STOP state    
        COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_BYPASS, &bypass);
        COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_TRIGGER_DISPLAY, &dec_triger_lcd);
        COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_ROTATE_FLIP, &vt_il_ctx.dec_param_rot_flip);
    }
    COMP_SET_STATE(dec_prVideoRenderHandle, VIDEO_STATE_RUN,RENDER);	
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  VideoCall_Get_Snapshot
 * DESCRIPTION
 *  Get Snapshot of peer view
 * PARAMETERS
 *  VideoCall_dec_get_snapshot_param_struct
 * RETURNS
 *  VideoCall_Error_Code_enum
 *****************************************************************************/
VideoCall_Error_Code_enum VideoCall_Get_Snapshot(VideoCall_dec_get_snapshot_param_struct param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VideoCall_Error_Code_enum result = VT_NO_ERROR;
    VIDEO_ERROR_TYPE_T err_code;	
    kal_uint32 u4EventGroup;	
    VIDEO_STATE_TYPE_T eRenderState = VIDEO_STATE_CLOSE;
    VA2_VIDEO_RENDERER_COLOR_FORMAT_T eRenderColorFormat;
    va2_video_renderer_dst_fb_t dst_fb;
    kal_uint32 render_addr;
    kal_uint32 dummy_addr;
	
    kal_mem_set(&dst_fb, 0, sizeof(va2_video_renderer_dst_fb_t));
	
    err_code = vt_il_ctx.dec_prVideoRenderHandle->pfnGetParameter(VIDEO_CONFIG_RENDERER_STATUS, &eRenderState);
	
    err_code = vt_il_ctx.dec_prVideoRenderHandle->pfnGetParameter(VIDEO_PARAM_RENDERER_DST_COLOR_FORMAT, &eRenderColorFormat);
	
    if(eRenderState == VIDEO_STATE_RUN)
    {
        COMP_SET_STATE(dec_prVideoRenderHandle, VIDEO_STATE_STOP,RENDER);

        COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DST_COLOR_FORMAT, &param.format);
        COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_ROTATE_FLIP, &vt_il_ctx.dec_param_rot_flip);   
        COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DST_FB_SIZE, &vt_il_ctx.dec_param_fb_size);		
        vt_il_ctx.dec_prVideoRenderHandle->pfnGetParameter(VIDEO_PARAM_RENDERER_DST_FB_ADDR, &dst_fb);
	render_addr = dst_fb.r_fb_addr.u4_fb_addr_plane0;
	dst_fb.r_fb_addr.u4_fb_addr_plane0 = (kal_uint32)param.buffer_addr;
	COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DST_FB_ADDR, &dst_fb);
    
        vt_il_ctx.dec_prVideoRenderHandle->pfnGetParameter(VIDEO_PARAM_RENDERER_RENDER_DISPLAY_BUFFER, &dummy_addr);
	ASSERT(dummy_addr == dst_fb.r_fb_addr.u4_fb_addr_plane0);
		
	dst_fb.r_fb_addr.u4_fb_addr_plane0 = render_addr;
	COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DST_FB_ADDR, &dst_fb);
    
        COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DST_COLOR_FORMAT, &eRenderColorFormat);
        COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_ROTATE_FLIP, &vt_il_ctx.dec_param_rot_flip);

        COMP_SET_STATE(dec_prVideoRenderHandle, VIDEO_STATE_RUN,RENDER);
    }
    else
    {
        COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DST_COLOR_FORMAT, &param.format);	
        COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_ROTATE_FLIP, &vt_il_ctx.dec_param_rot_flip);                
        COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DST_FB_SIZE, &vt_il_ctx.dec_param_fb_size);		
        vt_il_ctx.dec_prVideoRenderHandle->pfnGetParameter(VIDEO_PARAM_RENDERER_DST_FB_ADDR, &dst_fb);
	render_addr = dst_fb.r_fb_addr.u4_fb_addr_plane0;
	dst_fb.r_fb_addr.u4_fb_addr_plane0 = (kal_uint32)param.buffer_addr;
	COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DST_FB_ADDR, &dst_fb);
    
        vt_il_ctx.dec_prVideoRenderHandle->pfnGetParameter(VIDEO_PARAM_RENDERER_RENDER_DISPLAY_BUFFER, &dummy_addr);
	ASSERT(dummy_addr == dst_fb.r_fb_addr.u4_fb_addr_plane0);
		
	dst_fb.r_fb_addr.u4_fb_addr_plane0 = render_addr;
	COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DST_FB_ADDR, &dst_fb);        
        
        COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_DST_COLOR_FORMAT, &eRenderColorFormat);

    }
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  VideoCall_trigger_decoder
 * DESCRIPTION
 *  trigger one frame decode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VideoCall_Error_Code_enum VideoCall_trigger_decoder(VideoCall_dec_trigger_param_struct param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VideoCall_Error_Code_enum result = VT_NO_ERROR;
    VIDEO_ERROR_TYPE_T err_code;
    kal_uint32 u4EventGroup;
    kal_bool bypass = KAL_TRUE;
    VIDEO_STATE_TYPE_T eRenderState = VIDEO_STATE_CLOSE;
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    drv_trace8(TRACE_GROUP_10,VCALL_IL_DEC_TRIGGER_1, (kal_uint32)param.frame_meta, param.b_sync_frame,param.session_id,(kal_uint32)param.frame_data_ptr,
        param.frame_size,param.frame_duration,param.dec_param_dst_size.u4_width,param.dec_param_dst_size.u4_height);
    drv_trace8(TRACE_GROUP_10,VCALL_IL_DEC_TRIGGER_2,param.frame_data_ptr[0],param.frame_data_ptr[1],param.frame_data_ptr[2],param.frame_data_ptr[3],
        param.frame_data_ptr[4],param.frame_data_ptr[5],param.frame_data_ptr[6],param.frame_data_ptr[7]);

    err_code = vt_il_ctx.dec_prVideoRenderHandle->pfnGetParameter(VIDEO_CONFIG_RENDERER_STATUS, &eRenderState);
    ASSERT(err_code == VIDEO_ERROR_NONE);
	
    if(eRenderState == VIDEO_STATE_RUN)
    {
        if(param.is_fg_dec && param.is_peer_camera_on)
        {

            /*check and set by pass as false */
            err_code = vt_il_ctx.dec_prVideoRenderHandle->pfnGetParameter(VIDEO_PARAM_RENDERER_BYPASS, &bypass);
            ASSERT(err_code == VIDEO_ERROR_NONE);
            if(bypass == KAL_TRUE)
            {
                COMP_SET_STATE(dec_prVideoRenderHandle, VIDEO_STATE_STOP,RENDER);
                bypass = KAL_FALSE;
                COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_BYPASS, &bypass);
                COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_ROTATE_FLIP, &vt_il_ctx.dec_param_rot_flip);
                COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_CONFIG_RENDERER_RESIZE_DST_SIZE, &param.dec_param_dst_size);
                COMP_SET_STATE(dec_prVideoRenderHandle, VIDEO_STATE_RUN,RENDER);
            }

            COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_CONFIG_RENDERER_DST_CLIP, &param.dec_param_clip_wnd);

        }
        else
        {
            /* set by pass as true */
            COMP_SET_STATE(dec_prVideoRenderHandle, VIDEO_STATE_STOP,RENDER);
            COMP_SET_PARAM(dec_prVideoRenderHandle, VIDEO_PARAM_RENDERER_BYPASS, &bypass);
            COMP_SET_STATE(dec_prVideoRenderHandle, VIDEO_STATE_RUN,RENDER);

        }
    }

    /* fill the dec buffer header */
    vt_il_ctx.dec_buff_header.pu1Buffer = param.frame_data_ptr;
    vt_il_ctx.dec_buff_header.u4BuffSize = param.frame_size;
    vt_il_ctx.dec_buff_header.u8TimeStamp = vt_il_ctx.dec_param_stream_time;
    vt_il_ctx.dec_param_stream_time += param.frame_duration * 1000;
    if(!vt_il_ctx.recv_first_pkt)
    {
        vt_il_ctx.dec_buff_header.eFlags = VIDEO_BUFFERFLAG_PARAMETERSET;
        vt_il_ctx.recv_first_pkt = KAL_TRUE;
    }
    else
    {
        if(param.b_sync_frame)
            vt_il_ctx.dec_buff_header.eFlags = VIDEO_BUFFERFLAG_SYNCFRAME;
        else
            vt_il_ctx.dec_buff_header.eFlags = VIDEO_BUFFERFLAG_NONE;
    }
    vt_il_ctx.dec_buff_header.u4InputPort  = 0;
    vt_il_ctx.dec_buff_header.u4OutputPort = 1;

    /* pass buffer header to decoder */
    err_code = vt_il_ctx.dec_prVideoDecoderHandle->pfnEmptyThisBuffer(&(vt_il_ctx.dec_buff_header));
    if(err_code == VIDEO_ERROR_BUFF_FULL)
    {
        result = VT_ERROR_FULL;
    }
    else
    {
        vt_il_ctx.dec_data[vt_il_ctx.dec_data_end_ind].frame_meta = param.frame_meta;
        vt_il_ctx.dec_data[vt_il_ctx.dec_data_end_ind].session_id = param.session_id;
        vt_il_ctx.dec_data_end_ind = (vt_il_ctx.dec_data_end_ind +1)%50;

        result =  VT_NO_ERROR;
    }
    return result;
}

VideoCall_Error_Code_enum VideoCall_alloc_Memory(VideoCall_alloc_memory_struct param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VideoCall_Error_Code_enum result = VT_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_trace4(TRACE_GROUP_10,VCALL_IL_ALLOC_MEMORY, (kal_uint32)param.ext_conponent_mem_ptr,
        param.ext_conponent_mem_size,(kal_uint32)param.int_conponent_mem_ptr,param.int_conponent_mem_size);
    ASSERT(param.ext_conponent_mem_ptr != 0);
    ASSERT(param.ext_conponent_mem_size != 0);
    vt_il_ctx.ext_handler_ptr = VideoInitExtBuffer((kal_uint32)param.ext_conponent_mem_ptr, param.ext_conponent_mem_size, VIDEO_SCENARIO_VCALL);
    vt_il_ctx.int_handler_ptr = VideoInitIntBuffer((kal_uint32)param.int_conponent_mem_ptr, param.int_conponent_mem_size, VIDEO_SCENARIO_VCALL);
    return result;
}

VideoCall_Error_Code_enum VideoCall_free_Memory(VideoCall_free_memory_struct param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VideoCall_Error_Code_enum result = VT_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_trace2(TRACE_GROUP_10, VCALL_IL_FREE_MEMORY, (kal_uint32)param.ext_conponent_mem_ptr,(kal_uint32)param.int_conponent_mem_ptr);
    VideoDeInitExtBuffer(vt_il_ctx.ext_handler_ptr);
    VideoDeInitIntBuffer(vt_il_ctx.int_handler_ptr, VIDEO_SCENARIO_VCALL);
    return result;
}

void VideoCall_init_ILClient(VideoCall_ilclient_init_param_struct param)
{
    drv_trace0(TRACE_GROUP_10,VCALL_IL_INIT);
    ASSERT(vt_il_ctx.rCommState.eState == VIDEO_STATE_CLOSE);

    if (vt_il_ctx.decEvent==0)
    {
        vt_il_ctx.decEvent = kal_create_event_group("VIDEO_DEC_EVEVT");
    }
    if (vt_il_ctx.encEvent==0)
    {
        vt_il_ctx.encEvent = kal_create_event_group("VIDEO_ENC_EVEVT");
    }
    vt_il_ctx.dec_data_start_ind = 0;
    vt_il_ctx.dec_data_end_ind = 0;

    vt_il_ctx.prEncCallback = param.prEncCallback;
    vt_il_ctx.prDecCallback = param.prDecCallback;

    VideoCall_alloc_Memory(param.alloc_memory_param);
    vt_il_ctx.fg_init_ILClient = KAL_TRUE;
    vt_il_ctx.fg_consume_enc_fail = KAL_FALSE;

    stack_change_priority_by_module_ID(MOD_VCODEC_V2, TASK_PRIORITY_VTCODEC);
}

void VideoCall_deinit_ILClient(VideoCall_ilclient_deinit_param_struct param)
{
    drv_trace0(TRACE_GROUP_10,VCALL_IL_DEINIT);
    ASSERT(vt_il_ctx.rCommState.eState == VIDEO_STATE_CLOSE);
    ASSERT(vt_il_ctx.fg_init_ILClient == KAL_TRUE);

    if (vt_il_ctx.decEvent !=0)
    {
        kal_delete_eventgrp(vt_il_ctx.decEvent);
        vt_il_ctx.decEvent = 0;
    }
    if (vt_il_ctx.encEvent !=0)
    {
        kal_delete_eventgrp(vt_il_ctx.encEvent);
        vt_il_ctx.encEvent = 0;
    }

    VideoCall_free_Memory(param.free_memory_param);
    vt_il_ctx.fg_init_ILClient = KAL_FALSE;

    stack_change_priority_by_module_ID(MOD_VCODEC_V2, TASK_PRIORITY_VCODEC_V2);
}

#endif

