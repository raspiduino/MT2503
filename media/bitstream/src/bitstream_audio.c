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
 *   bitstream_audio.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains BITSTREAM audio procedures.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifdef WIN32
#include <stdio.h>
#endif 

/* KAL - RTOS Abstraction Layer */
#include "kal_release.h"

/* Task Message Communication */
//#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* local/peer struct */
//#include "stack_ltlcom.h"

/* Task Management */
//#include "syscomp_config.h"
//#include "task_config.h"

/* Timer Management  */
//#include "stacklib.h"
//#include "event_shed.h" /* event schedulet */
//#include "stack_timer.h"

//#include "app_buff_alloc.h"     /* buffer management API */
//#include "lcd_cqueue.h" /* circular queue */
//#include "app2soc_struct.h"     /* interface with Applications */

//#include "stack_utils.h"

#include "kal_trace.h"

#include "med_global.h"
#include "med_struct.h"
#include "med_trc.h"

#ifdef __MED_BITSTREAM_MOD__
/* global includes */
#include "l1audio.h"
#include "device.h"
//#include "custom_equipment.h"
//#include "custom_nvram_editor_data_item.h"

#include "med_main.h"
#include "aud_defs.h"
//#include "med_api.h"
#include "med_context.h"
//#include "med_utility.h"
#include "aud_main.h"

#include "bitstream_main.h"
#include "bitstream_api.h"

#include "fsal.h"
#include "kal_general_types.h"
#include "stack_config.h"
//#include "common_nvram_editor_data_item.h"

/* 
 * Defines
 */
typedef enum
{
    BITSTREAM_AUDIO_STATE_IDLE,
    BITSTREAM_AUDIO_STATE_PLAY,
    BITSTREAM_AUDIO_STATE_PAUSE,
    
    BITSTREAM_AUDIO_STATE_TOTAL
} bitstream_audio_state_enum;

typedef MHdl *(*media_open_func_ptr) (void (*handler) (MHdl *hdl, Media_Event event), STFSAL *pstFSAL, void *param);

/* 
 * Structures
 */
typedef struct
{
    MHdl *aud_handle;
    kal_int32 audio_format;
    bitstream_audio_state_enum state;
} bitstream_audio_context_struct;

/* 
 * Global variables
 */
bitstream_audio_context_struct bitstream_aud_cntx;
bitstream_audio_context_struct *bit_aud_cntx_p = &bitstream_aud_cntx;

/* 
 * Global functions
 */
#if defined(__MED_BT_A2DP_MOD__) && defined(__BTMTK__)
extern void aud_bt_a2dp_open_codec(kal_int32 audio_format);
#endif

/*****************************************************************************
 * FUNCTION
 *  bitstream_audio_init
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_audio_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bit_aud_cntx_p->aud_handle = NULL;
    bit_aud_cntx_p->state = BITSTREAM_AUDIO_STATE_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  bitstream_audio_open_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_audio_driver_event_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_driver_event_ind_struct *msg_p = (media_bitstream_audio_driver_event_ind_struct*) ilm_ptr->local_para_ptr;
    media_bitstream_audio_callback_ind_struct *ind_p;
    MHdl *mhdl_handle;
    Media_Event result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mhdl_handle = bit_aud_cntx_p->aud_handle;

    if(mhdl_handle == (MHdl*)msg_p->handle)
    {
        result = mhdl_handle->Process(mhdl_handle, (Media_Event) msg_p->event);

        /* Change state to idle, due to driver has changed state to idle after calling process function */
        if(result == MEDIA_ERROR)
        {
            bit_aud_cntx_p->state = BITSTREAM_AUDIO_STATE_IDLE;
            aud_enter_state(AUD_MEDIA_IDLE);
        }        

        BITSTREAM_AUD_VALUE_TRACE3(result, 0, 0, __LINE__);

        switch (result)
        {
            case MEDIA_UPDATE_DUR:
                break;
            default:
                ind_p = (media_bitstream_audio_callback_ind_struct*)
                        construct_local_para(sizeof(media_bitstream_audio_callback_ind_struct), TD_CTRL);

                ind_p->event = result;
                ind_p->handle = msg_p->handle;
            
                bitstream_send_msg(MOD_MED, MOD_MMI, MSG_ID_MEDIA_BITSTREAM_AUDIO_CALLBACK_IND, ind_p);
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  bitstream_audio_event_callback
 * DESCRIPTION
 *  This function is ....
 * PARAMETERS
 *  handle      [?]         
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void bitstream_audio_event_callback(MHdl *handle, Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_driver_event_ind_struct *ind_p = (media_bitstream_audio_driver_event_ind_struct*)
        construct_local_para(sizeof(media_bitstream_audio_driver_event_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p->event = (kal_uint8)event;
    ind_p->handle = (kal_int32)handle;

    bitstream_send_msg(MOD_L1SP, MOD_MED, MSG_ID_MEDIA_BITSTREAM_AUDIO_DRIVER_EVENT_IND, ind_p);
}


/*****************************************************************************
 * FUNCTION
 *  bitstream_audio_open_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_audio_open_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    media_open_func_ptr openFunc = NULL;
    Media_VM_PCM_Param vpFormat;
#ifdef WAV_CODEC
    Media_PCM_Stream_Param pcmParam;
#endif
    void *param = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_open_req_struct *msg_p = (media_bitstream_audio_open_req_struct*) ilm_ptr->local_para_ptr;

    /* Check if handle is currently used */
    if(bit_aud_cntx_p->aud_handle != NULL)
    {
        result = MED_RES_BUSY;
        goto BITSTREAM_OPEN_ERROR;    
    }

    /* Find support codec */
    switch (msg_p->codec_type)
    {
    #ifdef AMR_DECODE
        case MED_TYPE_AMR:
    #ifdef AMRWB_DECODE
        case MED_TYPE_AMR_WB:
    #endif
            vpFormat.mediaType = (Media_Format)msg_p->codec_type;
            vpFormat.vmParam = (kal_uint32) MEDIA_VMP_AS_RINGTONE;
            param = &vpFormat;
            openFunc = AMR_Open;
            break;
    #endif /*AMR_DECODE*/
    #ifdef DAF_DECODE
        case MED_TYPE_DAF:
            openFunc = DAF_Open;
            break;
    #endif /* DAF_DECODE */
    #if defined(AAC_DECODE)
        case MED_TYPE_AAC:
            openFunc = AAC_Open;
            break;
    #endif /*AAC_DECODE*/

    #ifdef WAV_CODEC
        case MED_TYPE_PCM_16K:
            pcmParam.isStereo = msg_p->isStereo;
            pcmParam.bitPerSample = msg_p->bitPerSample;
            pcmParam.sampleFreq = msg_p->sampleFreq;
            pcmParam.forceVoice = KAL_FALSE;
            param = &pcmParam;
            break;
    #endif /* WAV_CODEC */

        default:
            result = MED_RES_BITSTREAM_UNSUPPORTED_CODEC;
            goto BITSTREAM_OPEN_ERROR;            
            //break;
    }

    /* Open */
    if ( msg_p->codec_type != MED_TYPE_PCM_16K)
    {
        if((bit_aud_cntx_p->aud_handle = openFunc(bitstream_audio_event_callback, NULL, param)) == NULL)
        {
            result = MED_RES_FAIL;
            goto BITSTREAM_OPEN_ERROR;
        }
    }
#ifdef WAV_CODEC
    else if ((bit_aud_cntx_p->aud_handle = PCM_Strm_Open(bitstream_audio_event_callback, param)) == NULL)
    {
        result = MED_RES_FAIL;
        goto BITSTREAM_OPEN_ERROR;        
    }
#endif

    bit_aud_cntx_p->state = BITSTREAM_AUDIO_STATE_IDLE;
    bit_aud_cntx_p->audio_format = msg_p->codec_type;

    *(msg_p->handle) = (kal_int32)bit_aud_cntx_p->aud_handle;

    /* Assert the ring buffer was freed before being allocated. */
    ASSERT(aud_context_p->ring_buf == NULL);

    /* Set the ring buffer for audio driver */
    if (aud_context_p->ring_buf == NULL)
    {
        /*aud_context_p->ring_buf = (kal_uint16*)med_alloc_ext_mem(MED_RING_BUFFER_LEN*sizeof(kal_uint16));*/
        aud_util_alloc_ring_buffer_ext(MED_RING_BUFFER_SIZE, &aud_context_p->ring_buf);
        ASSERT(aud_context_p->ring_buf != NULL);
    }

    bit_aud_cntx_p->aud_handle->SetBuffer(bit_aud_cntx_p->aud_handle, (kal_uint8*) aud_context_p->ring_buf, MED_RING_BUFFER_SIZE);

    result = MED_RES_OK;

BITSTREAM_OPEN_ERROR:
    BITSTREAM_SET_RESULT(result);
    BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  bitstream_audio_close_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_audio_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_close_req_struct *msg_p = (media_bitstream_audio_close_req_struct*) ilm_ptr->local_para_ptr;

    ASSERT(bit_aud_cntx_p->aud_handle == (MHdl*)msg_p->handle);

    if(bit_aud_cntx_p->state == BITSTREAM_AUDIO_STATE_PLAY)
    {
        bit_aud_cntx_p->aud_handle->Stop(bit_aud_cntx_p->aud_handle);
    }
    bit_aud_cntx_p->aud_handle->Close(bit_aud_cntx_p->aud_handle);

    /* Free Ring buffer */
    if (aud_context_p->ring_buf)
    {
        aud_util_free_ring_buffer_ext((kal_uint16**)&aud_context_p->ring_buf);
        aud_context_p->ring_buf = NULL;
    }

    bit_aud_cntx_p->aud_handle = NULL;
    bit_aud_cntx_p->state = BITSTREAM_AUDIO_STATE_IDLE;
    aud_enter_state(AUD_MEDIA_IDLE);

    BITSTREAM_SET_RESULT(MED_RES_OK);
    BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  bitstream_audio_get_buffer_status_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_audio_get_buffer_status_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_get_buffer_status_req_struct *msg_p = (media_bitstream_audio_get_buffer_status_req_struct*) ilm_ptr->local_para_ptr;

    if(bit_aud_cntx_p->aud_handle != (MHdl*)msg_p->handle)
    {
        BITSTREAM_SET_RESULT(MED_RES_FAIL);
        BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);
        return;
    }

    ASSERT(bit_aud_cntx_p->aud_handle != NULL);

    *(msg_p->free_size) = bit_aud_cntx_p->aud_handle->GetFreeSpace(bit_aud_cntx_p->aud_handle);
    *(msg_p->total_size) = MED_RING_BUFFER_SIZE;

    BITSTREAM_SET_RESULT(MED_RES_OK);
    BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  bitstream_audio_put_data_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static kal_uint32 bitstream_audio_put_driver_buffer(MHdl *aud_handle, kal_uint8* p_app_buf, kal_uint32 app_buf_size, kal_uint32 *p_used_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *p_drv_buf;
    kal_uint32 drv_buf_size;
    kal_uint32 used_app_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BITSTREAM_FUNC_LOG2(BITSTREAM_TRC_AUD_FUNC_PUT_DRIVER_BUFFER, app_buf_size);

    /* Get empty buffer size from driver */
    aud_handle->GetWriteBuffer(aud_handle, &p_drv_buf, &drv_buf_size); /* in bytes */

    /* Overflow */
    if(drv_buf_size == 0)
    {
        *(p_used_size) = 0;
        return MED_RES_BITSTREAM_BUFFER_OVERFLOW;
    }

    /* Copy application data to driver buffer */
    if(drv_buf_size >= app_buf_size)
    {
        kal_mem_cpy(p_drv_buf, p_app_buf, app_buf_size);
        aud_handle->WriteDataDone(aud_handle, app_buf_size);
        used_app_len = app_buf_size;
    }
    else
    {
        kal_mem_cpy(p_drv_buf, p_app_buf, drv_buf_size);
        aud_handle->WriteDataDone(aud_handle, drv_buf_size);
        used_app_len = drv_buf_size;        

        /* Get empty buffer again */
        aud_handle->GetWriteBuffer(aud_handle, &p_drv_buf, &drv_buf_size); /* in bytes */

        if(drv_buf_size > 0)
        {
            if(drv_buf_size >= (app_buf_size - used_app_len))
            {
                kal_mem_cpy(p_drv_buf, (p_app_buf+used_app_len), (app_buf_size - used_app_len));
                aud_handle->WriteDataDone(aud_handle, (app_buf_size - used_app_len));
                used_app_len = app_buf_size;
            }
            else
            {
                kal_mem_cpy(p_drv_buf, (p_app_buf+used_app_len), drv_buf_size);
                aud_handle->WriteDataDone(aud_handle, drv_buf_size);
                used_app_len += drv_buf_size;
            }
        }
    }
    /* To inform audio driver to callback when need more data */
    aud_handle->FinishWriteData(aud_handle);

    *(p_used_size) = used_app_len;
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  bitstream_audio_put_data_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_audio_put_data_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result;
    kal_uint32 used_app_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_put_data_req_struct *msg_p = (media_bitstream_audio_put_data_req_struct*) ilm_ptr->local_para_ptr;

    if(bit_aud_cntx_p->aud_handle != (MHdl*)msg_p->handle)
    {
        BITSTREAM_SET_RESULT(MED_RES_FAIL);
        BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);
        return;
    }
    ASSERT(bit_aud_cntx_p->aud_handle != NULL);

    /* Put data to ring buffer */
    result = bitstream_audio_put_driver_buffer(bit_aud_cntx_p->aud_handle, msg_p->p_app_buf, msg_p->app_buf_size, &used_app_len);

    BITSTREAM_AUD_VALUE_TRACE3(result, used_app_len, -1, __LINE__);

    *(msg_p->p_used_size) = used_app_len;
    BITSTREAM_SET_RESULT(result);
    BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  bitstream_audio_put_frame_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_audio_put_frame_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result;
    kal_uint32 used_app_len;
    kal_uint32 free_buf_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_put_frame_req_struct *msg_p = (media_bitstream_audio_put_frame_req_struct*) ilm_ptr->local_para_ptr;

    if(bit_aud_cntx_p->aud_handle != (MHdl*)msg_p->handle)
    {
        BITSTREAM_SET_RESULT(MED_RES_FAIL);
        BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);
        return;
    }
    ASSERT(bit_aud_cntx_p->aud_handle != NULL);

    /* Check if ring buffer size is enough for a frame, must put a frame completely one time */
    free_buf_size = bit_aud_cntx_p->aud_handle->GetFreeSpace(bit_aud_cntx_p->aud_handle);

    if(free_buf_size < msg_p->app_buf_size)
    {
        BITSTREAM_SET_RESULT(MED_RES_BITSTREAM_BUFFER_OVERFLOW);
        BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);
        return;
    }

    /* Put data to ring buffer */
    result = bitstream_audio_put_driver_buffer(bit_aud_cntx_p->aud_handle, msg_p->p_app_buf, msg_p->app_buf_size, &used_app_len);

    BITSTREAM_AUD_VALUE_TRACE3(result, used_app_len, -1, __LINE__);

    BITSTREAM_SET_RESULT(result);
    BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  bitstream_audio_start_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_audio_start_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MHdl *mhdl_handle;
    Media_Status drv_result;
    kal_int32 bs_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_start_req_struct *msg_p = (media_bitstream_audio_start_req_struct*) ilm_ptr->local_para_ptr;

    mhdl_handle = bit_aud_cntx_p->aud_handle;
    if(mhdl_handle != (MHdl*)msg_p->handle)
    {
        BITSTREAM_SET_RESULT(MED_RES_FAIL);
        BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);
        return;
    }
    ASSERT(mhdl_handle != NULL);

    /* Set output path */
    aud_get_active_device_path_by_mode(msg_p->audio_path, aud_melody_set_output_device);

    /* Set output volume */

    SET_CURRENT_VOLUME_LEVEL(AUD_VOLUME_MEDIA, msg_p->volume);
    aud_set_active_ring_tone_volume();

    /* Set start time to driver, driver will return play time base on this setting */
    mhdl_handle->SetStartTime(mhdl_handle, msg_p->start_time);

#if defined(__MED_BT_A2DP_MOD__) && defined(__BTMTK__)
    aud_bt_a2dp_open_codec(bit_aud_cntx_p->audio_format);
#endif

    BITSTREAM_AUD_VALUE_TRACE3(bit_aud_cntx_p->state, 0, 0, __LINE__);
    if(bit_aud_cntx_p->state == BITSTREAM_AUDIO_STATE_IDLE)
    {
        drv_result = mhdl_handle->Play(mhdl_handle);
    }
    else
    {
        drv_result = mhdl_handle->Resume(mhdl_handle);
    }
    BITSTREAM_AUD_VALUE_TRACE3(drv_result, 0, 0, __LINE__);

    if(drv_result == MEDIA_SUCCESS)
    {
        bit_aud_cntx_p->state = BITSTREAM_AUDIO_STATE_PLAY;
        aud_enter_state(AUD_MEDIA_PLAY);
    }

    bs_result = aud_get_res(drv_result);

    BITSTREAM_SET_RESULT(bs_result);
    BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  bitstream_audio_stop_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_audio_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status drv_result;
    kal_int32 bs_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_stop_req_struct *msg_p = (media_bitstream_audio_stop_req_struct*) ilm_ptr->local_para_ptr;

    if(bit_aud_cntx_p->aud_handle != (MHdl*)msg_p->handle)
    {
        BITSTREAM_SET_RESULT(MED_RES_FAIL);
        BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);
        return;
    }
    ASSERT(bit_aud_cntx_p->aud_handle != NULL);

    BITSTREAM_AUD_VALUE_TRACE3(bit_aud_cntx_p->state, 0, 0, __LINE__);
    if(bit_aud_cntx_p->state == BITSTREAM_AUDIO_STATE_PLAY)
    {
        if((drv_result = bit_aud_cntx_p->aud_handle->Pause(bit_aud_cntx_p->aud_handle)) == MEDIA_SUCCESS)
        {
            bit_aud_cntx_p->state = BITSTREAM_AUDIO_STATE_PAUSE;
            aud_enter_state(AUD_MEDIA_PLAY_PAUSED);
        }
    }
    else
    {
        drv_result = bit_aud_cntx_p->aud_handle->Stop(bit_aud_cntx_p->aud_handle);
        bit_aud_cntx_p->state = BITSTREAM_AUDIO_STATE_IDLE;
        aud_enter_state(AUD_MEDIA_IDLE);
    }
    BITSTREAM_AUD_VALUE_TRACE3(drv_result, 0, 0, __LINE__);
    
    bs_result = aud_get_res(drv_result);

    BITSTREAM_SET_RESULT(bs_result);
    BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);
}

/*****************************************************************************
 * FUNCTION
 *  bitstream_audio_finished_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_audio_finished_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_finished_req_struct *msg_p = (media_bitstream_audio_finished_req_struct*) ilm_ptr->local_para_ptr;

    if(bit_aud_cntx_p->aud_handle != (MHdl*)msg_p->handle)
    {
        BITSTREAM_SET_RESULT(MED_RES_FAIL);
        BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);
        return;
    }
    ASSERT(bit_aud_cntx_p->aud_handle != NULL);

    BITSTREAM_AUD_VALUE_TRACE3(bit_aud_cntx_p->state, 0, 0, __LINE__);

    bit_aud_cntx_p->aud_handle->DataFinished(bit_aud_cntx_p->aud_handle) ;

    BITSTREAM_SET_RESULT(MED_RES_OK);
    BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);
}



/*****************************************************************************
 * FUNCTION
 *  bitstream_audio_get_play_time_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_audio_get_play_time_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_get_play_time_req_struct *msg_p = (media_bitstream_audio_get_play_time_req_struct*) ilm_ptr->local_para_ptr;

    if(bit_aud_cntx_p->aud_handle != (MHdl*)msg_p->handle)
    {
        BITSTREAM_SET_RESULT(MED_RES_FAIL);
        BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);
        return;
    }
    ASSERT(bit_aud_cntx_p->aud_handle != NULL);

    *(msg_p->play_time) = bit_aud_cntx_p->aud_handle->GetCurrentTime(bit_aud_cntx_p->aud_handle);

    BITSTREAM_SET_RESULT(MED_RES_OK);
    BITSTREAM_SET_EVENT(BITSTREAM_EVT_WAIT);

}


#endif /* __MED_BITSTREAM_MOD__ */


