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
 *  mdi_bitstream.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface for bitstreaming playback audio and video buffer
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

#include "MMI_features.h"
#if defined(__BITSTREAM_API_SUPPORT__)

#include "mmi_frm_gprot.h"

#include "kal_public_api.h"

#include "l1audio.h"
#include "med_struct.h"
#include "med_main.h"
#include "med_global.h"
#include "bitstream_api.h"
#include "aud_main.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "mdi_datatype.h"   /* mdi datatype */
#include "mdi_bitstream.h"
#include "mdi_include.h"
#include "mdi_audio.h"
#include "mdi_video.h"
#include "mdi_bitstream.h"
#include "UcmSrvGprot.h"
#ifdef __MMI_TVOUT__
#include "mdi_tv.h"
#endif 
#if defined(__MMI_BT_AUDIO_VIA_SCO__)
//#include "ProfileGprots.h"
//#include "BTMMISCOPathGprots.h"
#include "BthScoPathSrvGProt.h"
#endif

#ifdef __MTK_TARGET__
#define MDI_BITSTREAM_DRIVER_AVAILABLE
#endif

/***************************************************/
/* defines                                         */
/***************************************************/


/***************************************************/
/* structures                                      */
/***************************************************/

typedef struct
{
    kal_uint8 open_num;
} mdi_bitstream_audio_context_struct;

typedef struct
{
    mdi_bitstream_audio_context_struct audio;
} mdi_bitstream_context_struct;


/***************************************************/
/* globals                                         */
/***************************************************/
mdi_bitstream_context_struct g_mdi_bitstream_cntx;
mdi_bitstream_context_struct *mdi_bitstream_p = &g_mdi_bitstream_cntx;
void (*g_mdi_bitsream_audio_callback_func)(MDI_HANDLE handle, MDI_RESULT result);
void (*g_mdi_bitsream_record_callback_func)(MDI_HANDLE handle, MDI_RESULT result);

/***************************************************/
/* functions                                       */
/***************************************************/

/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_init
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_bitstream_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mdi_bitstream_p->audio.open_num = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_codec_type_mdi_to_med
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 mdi_bitstream_codec_type_mdi_to_med(kal_uint16 mdi_codectype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_uint32 med_codectype;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_CODEC_TYPE_MDI_TO_MED);
    
    switch (mdi_codectype)
    {
        case MDI_BITSTREAM_CODEC_TYPE_NONE:
            med_codectype = MED_BITSTREAM_CODEC_TYPE_NONE;
            break;

        case MDI_BITSTREAM_CODEC_TYPE_AMR:
            med_codectype = MED_BITSTREAM_CODEC_TYPE_AMR;
            break;

        case MDI_BITSTREAM_CODEC_TYPE_AMRWB:
        case MDI_BITSTREAM_CODEC_TYPE_MP4A:
        case MDI_BITSTREAM_CODEC_TYPE_MP4AG:
        default:
            /* not supported for now */
            med_codectype = MED_BITSTREAM_CODEC_TYPE_NONE;            
            break;            
    }
    
    return med_codectype;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_get_result
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_bitstream_get_result(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT mdi_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (result)
    {
        case MED_RES_OK:
            mdi_result = MDI_RES_BITSTREAM_SUCCEED;
            break;
        case MED_RES_BITSTREAM_BUFFER_UNDERFLOW:
        case MED_RES_BITSTREAM_RECOVER:
            mdi_result = MDI_RES_BITSTREAM_BUFFER_OVERFLOW;
            break;
        case MED_RES_BITSTREAM_BUFFER_OVERFLOW:
            mdi_result = MDI_RES_BITSTREAM_BUFFER_UNDERFLOW;
            break;
        case MED_RES_BITSTREAM_BUFFER_NOT_AVAILABLE:
            mdi_result = MDI_RES_BITSTREAM_ERR_FAILED;
            break;
        case MED_RES_BITSTREAM_UNSUPPORTED_CODEC:
            mdi_result = MDI_RES_BITSTREAM_ERR_UNSUPPORTED_FORMAT;
            break;
        case MED_RES_BITSTREAM_INVALID_RESOLUTION:
            mdi_result = MDI_RES_BITSTREAM_ERR_INVALID_RESOULTION;      /*  video width , height or both are not supported*/
            break;            
        case MED_RES_BITSTREAM_MEMORY_INSUFFICIENT:
            mdi_result = MDI_RES_BITSTREAM_ERR_INSUFFICIENT_MEMORY;     /* MED memory is not enough, should check MED memory scenario */
            break;
        case MED_RES_BITSTREAM_INVALID_FORMAT:
            mdi_result = MDI_RES_BITSTREAM_ERR_INVALID_FORMAT;          /* there is some error while decoding the frame, the frame may not be a valid one */
            break;
        case MED_RES_BITSTREAM_NOT_SUPPORTED:
            mdi_result = MDI_RES_BITSTREAM_NOT_SUPPORTED;               /* Something which is not supported by Bitstream API, e.g. incorrect invoking sequence, features not available */
            break;
        case MED_RES_BITSTREAM_INVALID_PARAMETER:
            mdi_result = MDI_RES_BITSTREAM_INVALID_PARAMETER;           /* The parameter passed through the API is invalid */
            break;

        case MED_RES_BITSTREAM_FAILED:
        default:
            mdi_result = MDI_RES_BITSTREAM_ERR_FAILED;
            break;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_GET_RESULT, mdi_result);
    return mdi_result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_get_event
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_bitstream_get_event(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT mdi_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (result)
    {
        case MEDIA_DATA_REQUEST:
            mdi_event = MDI_RES_BITSTREAM_EVENT_DATA_REQUEST;
            break;
        case MEDIA_ERROR:
            mdi_event = MDI_RES_BITSTREAM_EVENT_ERROR;
            break;
        default:
            mdi_event = MDI_RES_BITSTREAM_EVENT_NONE;
            break;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_GET_EVENT, mdi_event);
    return mdi_event;
}


/***************************************************/
/*  Audio                                          */
/***************************************************/

/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_audio_callback_handler
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_bitstream_audio_callback_handler(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_callback_ind_struct *msg_p = (media_bitstream_audio_callback_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_AUD_CALLBACK_HANDLER);

    if(g_mdi_bitsream_audio_callback_func != NULL)
    {
        g_mdi_bitsream_audio_callback_func(msg_p->handle, mdi_bitstream_get_event(msg_p->event));
    }
}


/*****************************************************************************
* FUNCTION
*  mdi_bitstream_audio_open_handle
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS           
*  
*****************************************************************************/
MDI_RESULT mdi_bitstream_audio_open_handle(
    MDI_HANDLE* p_handle,
    mdi_bitstream_audio_cfg_struct* p_cfg,
    void (*result_callback)(MDI_HANDLE handle, MDI_RESULT result))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_int32 bsa_handle;
//    kal_uint8 bsa_type;
    bitstream_audio_open_param_struct open_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_AUD_OPEN_HANDLE, p_cfg->codec_type);

    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) != 0)
    {
        return MDI_RES_BITSTREAM_ERR_FAILED;
    }

    switch (p_cfg->codec_type)
    {
        case MDI_BITSTREAM_CODEC_TYPE_SILENT:
            return MDI_RES_BITSTREAM_ERR_UNSUPPORTED_FORMAT;
//            break;
        case MDI_BITSTREAM_CODEC_TYPE_AMR:
            open_param.codec_type = MED_TYPE_AMR;
            break;
        case MDI_BITSTREAM_CODEC_TYPE_AMRWB:
            open_param.codec_type = MED_TYPE_AMR_WB;
            break;
        case MDI_BITSTREAM_CODEC_TYPE_AAC:
            open_param.codec_type = MED_TYPE_AAC;
            break;
        case MDI_BITSTREAM_CODEC_TYPE_DAF:
            open_param.codec_type = MED_TYPE_DAF;
            break;
    #ifdef WAV_CODEC
        case MDI_BITSTREAM_CODEC_TYPE_PCM:
            open_param.codec_type = MED_TYPE_PCM_16K; /* always use 16K, but the real bitrate is decided by the input param */
            open_param.isStereo = p_cfg->isStereo;
            open_param.bitPerSample = p_cfg->bitPerSample;

            switch(p_cfg->sampleFreq)
            {
                case MDI_BITSTREAM_SAMPLE_FREQ_8000:
                    open_param.sampleFreq = 8000;
                    break;
                case MDI_BITSTREAM_SAMPLE_FREQ_11025:
                    open_param.sampleFreq = 11025;
                    break;
                case MDI_BITSTREAM_SAMPLE_FREQ_16000:
                    open_param.sampleFreq = 16000;
                    break;
                case MDI_BITSTREAM_SAMPLE_FREQ_22050:
                    open_param.sampleFreq = 22050;
                    break;
                case MDI_BITSTREAM_SAMPLE_FREQ_24000:
                    open_param.sampleFreq = 24000;
                    break;
                case MDI_BITSTREAM_SAMPLE_FREQ_32000:
                    open_param.sampleFreq = 32000;
                    break;
                case MDI_BITSTREAM_SAMPLE_FREQ_44100:
                    open_param.sampleFreq = 44100;
                    break;
                case MDI_BITSTREAM_SAMPLE_FREQ_48000:
                    open_param.sampleFreq = 48000;
                    break;
                default :
                    return MDI_RES_BITSTREAM_ERR_UNSUPPORTED_FORMAT;
            }

            break;
    #endif /* WAV_CODEC */

        default:
            return MDI_RES_BITSTREAM_ERR_UNSUPPORTED_FORMAT;
//            break;
    }

#ifdef __MMI_BT_AUDIO_VIA_SCO__
	/* Connect audio via SCO when stream opened, and remain SCO open */
    srv_btsco_connect_audio_via_sco();
    srv_btsco_set_always_on(MMI_FALSE);
#endif /*__MMI_BT_AUDIO_VIA_SCO__*/

    result = media_bitstream_audio_open_handle(kal_get_active_module_id(), &bsa_handle, &open_param);

    if((result == MED_RES_OK) && (bsa_handle != 0))
    {
        SetProtocolEventHandler(mdi_bitstream_audio_callback_handler, MSG_ID_MEDIA_BITSTREAM_AUDIO_CALLBACK_IND);
        *p_handle = bsa_handle;
        g_mdi_bitsream_audio_callback_func = result_callback;

        mdi_bitstream_p->audio.open_num++;
    }

    return mdi_bitstream_get_result(result);
}


/*****************************************************************************
* FUNCTION
*  mdi_bitstream_audio_close
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS           
*  
*****************************************************************************/
MDI_RESULT mdi_bitstream_audio_close(MDI_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_AUD_CLOSE, mdi_bitstream_p->audio.open_num);

    media_bitstream_audio_close(kal_get_active_module_id(), handle);

    ClearProtocolEventHandler(MSG_ID_MEDIA_BITSTREAM_AUDIO_CALLBACK_IND);
    g_mdi_bitsream_audio_callback_func = NULL;

    mdi_bitstream_p->audio.open_num--;

#ifdef __MMI_BT_AUDIO_VIA_SCO__
    if(mdi_bitstream_p->audio.open_num == 0)
    {
        srv_btsco_set_always_on(MMI_FALSE);
    }
#endif /*__MMI_BT_AUDIO_VIA_SCO__*/

    return MDI_RES_BITSTREAM_SUCCEED;
}


/*****************************************************************************
* FUNCTION
*  mdi_bitstream_audio_get_buffer_status
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS           
*  
*****************************************************************************/
MDI_RESULT mdi_bitstream_audio_get_buffer_status(MDI_HANDLE handle, mdi_bitstream_audio_buffer_status* p_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_bitstream_audio_get_buffer_status(kal_get_active_module_id(), handle, &p_status->total_buf_size, &p_status->free_buf_size);

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_AUD_GET_BUF_STATUS, p_status->total_buf_size, p_status->free_buf_size);

    return mdi_bitstream_get_result(result);
}


/*****************************************************************************
* FUNCTION
*  mdi_bitstream_audio_put_data
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS           
*  
*****************************************************************************/
MDI_RESULT mdi_bitstream_audio_put_data(MDI_HANDLE handle, U8* p_buffer, U32 buffer_size, U32* p_used_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_bitstream_audio_put_data(kal_get_active_module_id(), handle, p_buffer, buffer_size, p_used_size);

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_AUD_PUT_DATA, buffer_size, *p_used_size);

    return mdi_bitstream_get_result(result);
}


/*****************************************************************************
* FUNCTION
*  mdi_bitstream_audio_put_frame
* DESCRIPTION
*  This function is to put audio frame align to video frame with timestamp
* PARAMETERS
*  
* RETURNS           
*  
*****************************************************************************/
MDI_RESULT mdi_bitstream_audio_put_frame(MDI_HANDLE handle, U8* p_buffer, U32 buffer_size, U32 timestamp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_AUD_PUT_FRAME, buffer_size, timestamp);

    result = media_bitstream_audio_put_frame(kal_get_active_module_id(), handle, p_buffer, buffer_size, timestamp);

    return mdi_bitstream_get_result(result);
}


/*****************************************************************************
* FUNCTION
*  mdi_bitstream_audio_start
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS           
*  
*****************************************************************************/
MDI_RESULT mdi_bitstream_audio_start(MDI_HANDLE handle, mdi_bitstream_audio_start_param* p_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_AUD_START);

#ifdef __BT_SPK_VOL_CONTROL__
   mdi_audio_set_volume_to_bt(p_para->volume);
#endif

    result = media_bitstream_audio_start(kal_get_active_module_id(), handle, p_para->start_time, p_para->audio_path, p_para->volume);

    return mdi_bitstream_get_result(result);
}


/*****************************************************************************
* FUNCTION
*  mdi_bitstream_audio_stop
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS           
*  
*****************************************************************************/
MDI_RESULT mdi_bitstream_audio_stop(MDI_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_AUD_STOP);

    result = media_bitstream_audio_stop(kal_get_active_module_id(), handle);

    return mdi_bitstream_get_result(result);
}

/*****************************************************************************
* FUNCTION
*  mdi_bitstream_audio_finished
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS           
*  
*****************************************************************************/
MDI_RESULT mdi_bitstream_audio_finished(MDI_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_AUD_FINISHED);

    result = media_bitstream_audio_finished(kal_get_active_module_id(), handle);

    return mdi_bitstream_get_result(result);
}


/*****************************************************************************
* FUNCTION
*  mdi_bitstream_audio_get_play_time
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS           
*  
*****************************************************************************/
MDI_RESULT mdi_bitstream_audio_get_play_time(MDI_HANDLE handle, U32* p_ms_current_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_bitstream_audio_get_play_time(kal_get_active_module_id(), handle, p_ms_current_time);

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_AUD_GET_PLAY_TIME, *p_ms_current_time);

	return mdi_bitstream_get_result(result);
}


/*****************************************************************************
* FUNCTION
*  mdi_bitstream_audio_get_total_handle
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS           
*  
*****************************************************************************/
U16 mdi_bitstream_audio_get_open_handle_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mdi_bitstream_p->audio.open_num;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_record_callback_handler
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_bitstream_record_callback_handler(void *data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_record_callback_ind_struct *msg_p = (media_bitstream_record_callback_ind_struct*) data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_RECORD_CALLBACK_HANDLER);

    if (g_mdi_bitsream_record_callback_func != NULL)
    {
        g_mdi_bitsream_record_callback_func(msg_p->handle, mdi_bitstream_get_event(msg_p->event));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_record_open
 * DESCRIPTION
 *  This function is to open a record handle for bit-stream record.
 * PARAMETERS
 *  handle_p        [OUT]       Recorder handle.
 *  cfg_p           [IN]        Recorder configuration.
 *  callback        [IN]        Callback function to handle record event.
 * RETURNS
 *  MDI_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
MDI_RESULT mdi_bitstream_record_open(MDI_HANDLE* handle_p,
                                     mdi_bitstream_record_cfg_struct* cfg_p,
                                     void (*callback)(MDI_HANDLE handle, MDI_RESULT result))
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32  result;
    kal_int32  handle;
    kal_uint8  med_type;
    kal_uint8  med_quality;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_RECORD_OPEN, cfg_p->codec_type, cfg_p->quality);

    switch (cfg_p->codec_type)
    {
        case MDI_BITSTREAM_CODEC_TYPE_AMR:
            med_type = MED_TYPE_AMR;
            break;

    #ifdef AMRWB_ENCODE
        case MDI_BITSTREAM_CODEC_TYPE_AMRWB:
            med_type = MED_TYPE_AMR_WB;
            break;
    #endif /*AMRWB_ENCODE*/

    #ifdef WAV_CODEC
        case MDI_BITSTREAM_CODEC_TYPE_WAV:
            med_type = MED_TYPE_WAV;
            break;
        case MDI_BITSTREAM_CODEC_TYPE_ADPCM:
            med_type = MED_TYPE_WAV_DVI_ADPCM;
            break;
        case MDI_BITSTREAM_CODEC_TYPE_PCM:
            med_type = MED_TYPE_PCM_8K;
            break;
    #endif /*WAV_CODEC*/

        default:
            return MDI_RES_BITSTREAM_ERR_UNSUPPORTED_FORMAT;
    }

    switch (cfg_p->quality)
    {
        case MDI_BITSTREAM_RECORD_QUALITY_LOW:   /* Low quality */
            med_quality = AUD_REC_QUALITY_LOW;
            break;
        case MDI_BITSTREAM_RECORD_QUALITY_HIGH:  /* High quality */
            med_quality = AUD_REC_QUALITY_HIGH;
            break;
        case MDI_BITSTREAM_RECORD_AMR_4_75:      /* AMR 4.75 kbit/s */
            med_quality = AUD_REC_QUALITY_AMR_4_75;
            break;
        case MDI_BITSTREAM_RECORD_AMR_5_15:      /* AMR 5.15 kbit/s */
            med_quality = AUD_REC_QUALITY_AMR_5_15;
            break;
        case MDI_BITSTREAM_RECORD_AMR_5_9:       /* AMR 5.9  kbit/s */
            med_quality = AUD_REC_QUALITY_AMR_5_9;
            break;
        case MDI_BITSTREAM_RECORD_AMR_6_7:       /* AMR 6.7  kbit/s */
            med_quality = AUD_REC_QUALITY_AMR_6_7;
            break;
        case MDI_BITSTREAM_RECORD_AMR_7_4:       /* AMR 7.4  kbit/s */
            med_quality = AUD_REC_QUALITY_AMR_7_4;
            break;
        case MDI_BITSTREAM_RECORD_AMR_7_95:      /* AMR 7.95 kbit/s */
            med_quality = AUD_REC_QUALITY_AMR_7_95;
            break;
        case MDI_BITSTREAM_RECORD_AMR_10_2:      /* AMR 10.2 kbit/s */
            med_quality = AUD_REC_QUALITY_AMR_10_2;
            break;
        case MDI_BITSTREAM_RECORD_AMR_12_2:      /* AMR 12.2 kbit/s */
            med_quality = AUD_REC_QUALITY_AMR_12_2;
            break;
        case MDI_BITSTREAM_RECORD_AWB_6_6:       /* AWB 6.6   kbit/s */
            med_quality = AUD_REC_QUALITY_AWB_6_6;
            break;
        case MDI_BITSTREAM_RECORD_AWB_8_85:      /* AWB 8.85  kbit/s */
            med_quality = AUD_REC_QUALITY_AWB_8_85;
            break;
        case MDI_BITSTREAM_RECORD_AWB_12_65:     /* AWB 12.65 kbit/s */
            med_quality = AUD_REC_QUALITY_AWB_12_65;
            break;
        case MDI_BITSTREAM_RECORD_AWB_14_25:     /* AWB 14.25 kbit/s */
            med_quality = AUD_REC_QUALITY_AWB_14_25;
            break;
        case MDI_BITSTREAM_RECORD_AWB_15_85:     /* AWB 15.85 kbit/s */
            med_quality = AUD_REC_QUALITY_AWB_15_85;
            break;
        case MDI_BITSTREAM_RECORD_AWB_18_25:     /* AWB 18.25 kbit/s */
            med_quality = AUD_REC_QUALITY_AWB_18_25;
            break;
        case MDI_BITSTREAM_RECORD_AWB_19_85:     /* AWB 19.85 kbit/s */
            med_quality = AUD_REC_QUALITY_AWB_19_85;
            break;
        case MDI_BITSTREAM_RECORD_AWB_23_05:     /* AWB 23.05 kbit/s */
            med_quality = AUD_REC_QUALITY_AWB_23_05;
            break;
        case MDI_BITSTREAM_RECORD_AWB_23_85:     /* AWB 23.85 kbit/s */
            med_quality = AUD_REC_QUALITY_AWB_23_85;
            break;
        case MDI_BITSTREAM_RECORD_QUALITY_MED:   /* Reserved */
        case MDI_BITSTREAM_RECORD_QUALITY_BEST:  /* Reserved */
        default:
            return MDI_RES_BITSTREAM_ERR_UNSUPPORTED_FORMAT;
    }

    result = media_bitstream_record_open(med_type, med_quality, &handle);

    if (result == MED_RES_OK)
    {
        SetProtocolEventHandler(mdi_bitstream_record_callback_handler, MSG_ID_MEDIA_BITSTREAM_RECORD_CALLBACK_IND);
        g_mdi_bitsream_record_callback_func = callback;
        
        *handle_p = (MDI_HANDLE)handle;
    }

    return mdi_bitstream_get_result(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_record_close
 * DESCRIPTION
 *  This function is to close a bit-stream record handle.
 * PARAMETERS
 *  handle_p        [IN]        Recorder handle.
 * RETURNS
 *  MDI_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
MDI_RESULT mdi_bitstream_record_close(MDI_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_RECORD_CLOSE, handle);

    media_bitstream_record_close(handle);
    ClearProtocolEventHandler(MSG_ID_MEDIA_BITSTREAM_RECORD_CALLBACK_IND);
    g_mdi_bitsream_record_callback_func = NULL;

    return MDI_RES_BITSTREAM_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_record_start
 * DESCRIPTION
 *  This function is to start bit-stream record process.
 * PARAMETERS
 *  handle_p        [IN]        Recorder handle.
 * RETURNS
 *  MDI_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
MDI_RESULT mdi_bitstream_record_start(MDI_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32  result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_RECORD_START, handle);

    result = media_bitstream_record_start(handle);
    
    return mdi_bitstream_get_result(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_record_stop
 * DESCRIPTION
 *  This function is to stop bit-stream record process.
 * PARAMETERS
 *  handle_p        [IN]        Recorder handle.
 * RETURNS
 *  MDI_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
MDI_RESULT mdi_bitstream_record_stop(MDI_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32  result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_RECORD_STOP, handle);

    result = media_bitstream_record_stop(handle);
    
    return mdi_bitstream_get_result(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_record_get
 * DESCRIPTION
 *  This function is a general get function to get information in the 
 *  bit-stream recorder.
 * PARAMETERS
 *  handle          [IN]        Recorder handle.
 *  get_type        [IN]        The information to be got.
 *  data_p          [OUT]       Data buffer. The information will be stored to
 *                              the data buffer.
 *  data_len_p      [IN/OUT]    When input, it indicates the length of data buffer. 
 *                              When output, it indicates the length of data that
 *                              is retrieved.
 * RETURNS
 *  MDI_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
MDI_RESULT mdi_bitstream_record_get(MDI_HANDLE handle,
                                    mdi_bitstream_record_get_type_enum get_type,
                                    void* data_p,
                                    U16* data_len_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32  result;
    kal_uint8  med_get_type = BITSTREAM_RECORD_GET_LAST_ENTRY;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_RECORD_GET, handle, get_type);

    switch (get_type)
    {
        case MDI_BITSTREAM_RECORD_GET_LENGTH:
            med_get_type = BITSTREAM_RECORD_GET_LENGTH;
            break;
        case MDI_BITSTREAM_RECORD_GET_DATA:
            med_get_type = BITSTREAM_RECORD_GET_DATA;
            break;
        case MDI_BITSTREAM_RECORD_GET_STRENGTH:
            med_get_type = BITSTREAM_RECORD_GET_STRENGTH;
            break;

        default:
            break;
    }

    result = media_bitstream_record_get(handle, med_get_type, data_p, data_len_p);
    
    return mdi_bitstream_get_result(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_record_set
 * DESCRIPTION
 *  This function is a general set function to parameter of the bit-stream recorder.
 * PARAMETERS
 *  handle          [IN]        Recorder handle.
 *  set_type        [IN]        The type of the parameter to be set.
 *  data_p          [IN]        Data buffer. The data in the data buffer will be
 *                              set to bit-stream recorder.
 *  data_len        [IN]        The length of data. Note that the length of data
 *                              should be equal to the length of the parameter to
 *                              be set.
 * RETURNS
 *  MDI_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
MDI_RESULT mdi_bitstream_record_set(MDI_HANDLE handle,
                                    mdi_bitstream_record_set_type_enum set_type,
                                    void* data_p,
                                    U16 data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32  result;
    kal_uint8  med_set_type = BITSTREAM_RECORD_SET_LAST_ENTRY;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_BITSTREAM_RECORD_SET, handle, set_type);

    switch (set_type)
    {
        case MDI_BITSTREAM_RECORD_SET_PAUSE:
            med_set_type = BITSTREAM_RECORD_SET_PAUSE;
            break;
        case MDI_BITSTREAM_RECORD_SET_RESUME:
            med_set_type = BITSTREAM_RECORD_SET_RESUME;
            break;
        case MDI_BITSTREAM_RECORD_SET_CB_THRESHOLD:
            med_set_type = BITSTREAM_RECORD_SET_CB_THRESHOLD;
            break;
        default:
            break;
    }
    
    result = media_bitstream_record_set(handle, med_set_type, data_p, data_len);
    
    return mdi_bitstream_get_result(result);
}


#endif /*defined(__BITSTREAM_API_SUPPORT__)*/

