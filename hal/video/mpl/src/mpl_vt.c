/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*   mpl_vt.c
*
* Project:
* --------
*	MediaTek
*
* Description:
* ------------
*
*
* Author:
* -------
 * -------
*
*=============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*-----------------------------------------------------------------------------
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
* Upper this line, this part is controlled by CQ. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/
#include "drv_features_video.h"

#ifdef __VE_VIDEO_ARCHI_V2__
#ifdef __VE_VIDEO_VT_SUPPORT__

#include "mpl_vt.h"    // mpl VT interface definition
#include "VideoCall_IL_Client.h"
#include "video_recorder_source_component_if_v2.h"  // Public interface of recorder source component
#include "video_vt_api_v2.h"
#include "video_encoder_component_if_v2.h"


/*****************************************************************************
* Global variable(s)
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  MPL_VT_get_param
 * DESCRIPTION
 *  The function is to get param
 * PARAMETERS
 *
 * RETURNS
 *  media_error_t
 *****************************************************************************/
 media_error_t MPL_VT_get_param(mpl_vt_param_enum param, void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_error_t ret = MED_S_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param)
    {
    case MPL_VT_PARAM_PFN_GET_BUFFER:
        *(PFN_VAL_VT_GET_BUFFER_T*)value = VideoRecorderGetSourceBuffer;
        break;
    case MPL_VT_PARAM_PFN_RETURN_BUFFER:
        *(PFN_VAL_VT_COMPLETE_BUFFER_T*)value = VideoRecorderCompleteSourceBuffer;
        break;
    case MPL_VT_PARAM_CODEC_ENCODE_FORMAT:
        if(VideoCall_Enc_InputIsblockYUV())
        {
             *(VIDEO_ENC_INPUT_TYPE*)value = VIDEO_ENC_INPUT_YUV_BLOCK_BASE;
        }
        else
        {
             *(VIDEO_ENC_INPUT_TYPE*)value = VIDEO_ENC_INPUT_YUV_LINE_BASE;
        }
        break;
    case MPL_VT_PARAM_GET_SNAPSHOT:
        VideoCall_Get_Snapshot(*(VideoCall_dec_get_snapshot_param_struct*)value);
	break;
    case MPL_VT_PARAM_GET_VOS:
        {
            VIDEO_ENCODER_GEN_HEADER_PARAM_T param;
            if(((VIDEO_ENCODER_GEN_HEADER_PARAM_T*)value)->eType >= MPL_VT_CODEC_11A)
            {
                switch(((VIDEO_ENCODER_GEN_HEADER_PARAM_T*)value)->eType)
                {
                    case MPL_VT_CODEC_MPEG4:
                        param.eType = VIDEO_ENCODER_MPEG4_VT;
                    break;
                    case MPL_VT_CODEC_H263:
                        param.eType = VIDEO_ENCODER_H263_VT;
                    break;
                    default:
                        ASSERT(0);
                }
            }
            else
            {
                param.eType = ((VIDEO_ENCODER_GEN_HEADER_PARAM_T*)value)->eType;
            }

            param.pu1Buffer = ((VIDEO_ENCODER_GEN_HEADER_PARAM_T*)value)->pu1Buffer;
            param.pu4EncodedSize = ((VIDEO_ENCODER_GEN_HEADER_PARAM_T*)value)->pu4EncodedSize;
            param.u4BufferSize = ((VIDEO_ENCODER_GEN_HEADER_PARAM_T*)value)->u4BufferSize;
            param.u4TimeIncrResolution = ((VIDEO_ENCODER_GEN_HEADER_PARAM_T*)value)->u4TimeIncrResolution;

            if(KAL_TRUE != VideoEncoderGenStreamHeader(&param))
            {
                ret = MED_E_FAIL;
            }
        }
    break;
    default:
            ret = MED_E_NOT_SUPPORTED;
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  MPL_VT_set_param
 * DESCRIPTION
 *  The function is to set param
 * PARAMETERS
 *
 * RETURNS
 *  media_error_t
 *****************************************************************************/
 media_error_t MPL_VT_set_param(mpl_vt_param_enum param, void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_error_t ret = MED_S_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param)
    {
    case MPL_VT_PARAM_CODEC_DECODE_TYPE:
        if(VideoCall_SetDecParseCodec(*(VIDEO_CALL_CODEC_TYPE*)value) != VIDEO_CALL_STATUS_OK)
            ret = MED_E_FAIL;
        break;
    case MPL_VT_PARAM_ENCODE_IFRAME:
        VideoCall_Enc_UpdateI();
        break;
    case MPL_VT_PARAM_SET_CONTROL_VOS:
        if(VideoCall_Dec_ControlVOS(*(MPL_VT_CONTROL_VOS_T*)value) != VT_NO_ERROR)
            ret = MED_E_FAIL;		
        break;
    default:
            ret = MED_E_NOT_SUPPORTED;
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  MPL_VT_control
 * DESCRIPTION
 *  The function is to control IL Client
 * PARAMETERS
 *
 * RETURNS
 *  media_error_t
 *****************************************************************************/
 media_error_t MPL_VT_control(mpl_vt_scenario_enum type, mpl_vt_control_enum control, void * param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_error_t ret = MED_S_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MPL_VT_SCENARIO_ENC == type)
    {
        switch(control)
        {
        case MPL_VT_CONTROL_INIT:
            VideoCall_init_encoder(*(VideoCall_enc_init_param_struct*)param);
            break;
        case MPL_VT_CONTROL_OPEN:
        {
            VideoCall_enc_open_param_struct enc_open_param;
            if(((VideoCall_enc_open_param_struct*)param)->enc_param_EncoderType < MPL_VT_CODEC_11A )
            {
                switch(((VideoCall_enc_open_param_struct*)param)->enc_param_EncoderType)
                {
                    case 2:
                        enc_open_param.enc_param_EncoderType = MPL_VT_CODEC_MPEG4;
                    break;
                    case 3:
                        enc_open_param.enc_param_EncoderType = MPL_VT_CODEC_H263;
                    break;
                    default:
                        ASSERT(0);
                }
            }
            else
            {
                enc_open_param.enc_param_EncoderType = ((VideoCall_enc_open_param_struct*)param)->enc_param_EncoderType;
            }
            enc_open_param.width = ((VideoCall_enc_open_param_struct*)param)->width;
            enc_open_param.height = ((VideoCall_enc_open_param_struct*)param)->height;
            enc_open_param.bitrate = ((VideoCall_enc_open_param_struct*)param)->bitrate;
            enc_open_param.yuv_duration = ((VideoCall_enc_open_param_struct*)param)->yuv_duration;
            enc_open_param.yuv_addr = ((VideoCall_enc_open_param_struct*)param)->yuv_addr;
            enc_open_param.is_image_view = ((VideoCall_enc_open_param_struct*)param)->is_image_view;
            enc_open_param.u4FrameRate = ((VideoCall_enc_open_param_struct*)param)->u4FrameRate;
            enc_open_param.is_restartopen = ((VideoCall_enc_open_param_struct*)param)->is_restartopen;
            enc_open_param.u4TimeIncrResolution = ((VideoCall_enc_open_param_struct*)param)->u4TimeIncrResolution;

            VideoCall_open_encoder(enc_open_param);
        }
            break;
        case MPL_VT_CONTROL_CLOSE:
            VideoCall_close_encoder(*(VideoCall_enc_close_param_struct*)param);
            break;
        case MPL_VT_CONTROL_DEINIT:
            VideoCall_deinit_encoder(*(VideoCall_enc_deinit_param_struct*)param);
            break;
        default:
            ASSERT(0);
        }
    }
    else if(MPL_VT_SCENARIO_DEC == type)
    {
        switch(control)
        {
        case MPL_VT_CONTROL_INIT:
        {
            VideoCall_dec_init_param_struct dec_init_param;
            if(((VideoCall_dec_init_param_struct*)param)->dec_param_DecoderType < MPL_VT_CODEC_11A )
            {
                switch(((VideoCall_dec_init_param_struct*)param)->dec_param_DecoderType)
                {
                    case 0:
                        dec_init_param.dec_param_DecoderType = MPL_VT_CODEC_MPEG4;
                    break;
                    case 1:
                        dec_init_param.dec_param_DecoderType = MPL_VT_CODEC_H263;
                    break;
                    default:
                        ASSERT(0);
                }
            }
            else
            {
                dec_init_param.dec_param_DecoderType = ((VideoCall_dec_init_param_struct*)param)->dec_param_DecoderType;
            }
            dec_init_param.dec_param_dst_size = ((VideoCall_dec_init_param_struct*)param)->dec_param_dst_size;
            dec_init_param.dec_param_fb = ((VideoCall_dec_init_param_struct*)param)->dec_param_fb;
            dec_init_param.dec_param_fb2 = ((VideoCall_dec_init_param_struct*)param)->dec_param_fb2;
            dec_init_param.dec_param_fb_size = ((VideoCall_dec_init_param_struct*)param)->dec_param_fb_size;
            dec_init_param.dec_triger_lcd = ((VideoCall_dec_init_param_struct*)param)->dec_triger_lcd;
            dec_init_param.lcd_data = ((VideoCall_dec_init_param_struct*)param)->lcd_data;
            dec_init_param.format = ((VideoCall_dec_init_param_struct*)param)->format;

            VideoCall_init_decoder(dec_init_param);
        }
            break;
        case MPL_VT_CONTROL_OPEN:
            VideoCall_open_decoder(*(VideoCall_dec_open_param_struct*)param);
            break;
        case MPL_VT_CONTROL_PAUSE:
            VideoCall_pause_decoder(*(VideoCall_dec_pause_param_struct*)param);
            break;
        case MPL_VT_CONTROL_RESUME:
            VideoCall_resume_decoder(*(VideoCall_dec_resume_param_struct*)param);
            break;
        case MPL_VT_CONTROL_CLOSE:
            VideoCall_close_decoder(*(VideoCall_dec_close_param_struct*)param);
            break;
        default:
            ASSERT(0);
        }
    }
    else
    {
        ASSERT(0);
    }


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  MPL_VT_transmit
 * DESCRIPTION
 *  The function is to transmit buffer to IL Client
 * PARAMETERS
 *
 * RETURNS
 *  media_error_t
 *****************************************************************************/
mpl_vt_error_code_enum MPL_VT_transmit(mpl_vt_scenario_enum type, mpl_vt_transmit_enum control, void * param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mpl_vt_error_code_enum ret = MPL_VT_ERROR_NONE;
    VideoCall_Error_Code_enum eResult = VT_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MPL_VT_SCENARIO_ENC == type)
    {
        switch(control)
        {
        case MPL_VT_TRANSMIT_GET:
        eResult = VideoCall_get_enc_data((VIDEO_BUFFERHEADER_TYPE_T*)param);
        if(eResult == VT_ERROR_EMPTY)
            ret = MPL_VT_ERROR_BUFFER_EMPTY;
        else
            ASSERT(eResult == VT_NO_ERROR);
            break;

        case MPL_VT_TRANSMIT_SEND:
            VideoCall_consume_encoder((VideoCall_enc_consume_param_struct*)param);
            break;
        default:
            ASSERT(0);
        }
    }
    else if(MPL_VT_SCENARIO_DEC == type)
    {
        switch(control)
        {
        case MPL_VT_TRANSMIT_SEND:
        eResult = VideoCall_trigger_decoder(*(VideoCall_dec_trigger_param_struct*)param);
        if(eResult == VT_ERROR_FULL)
            ret = MPL_VT_ERROR_BUFFER_FULL;
        else
            ASSERT(eResult == VT_NO_ERROR);
            break;
        default:
            ASSERT(0);
        }
    }
    else
    {
        ASSERT(0);
    }

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  construct_mpl_vt
 * DESCRIPTION
 *  The function is to construct vt mpl
 * PARAMETERS
 *  mpl_vt_t
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool  construct_mpl_vt(mpl_vt_t* mpl)
{
    kal_bool ret = KAL_TRUE;
    mpl->init_ilclient = VideoCall_init_ILClient;
    mpl->deinit_ilclient  = VideoCall_deinit_ILClient;
    mpl->get_param = MPL_VT_get_param;
    mpl->set_param = MPL_VT_set_param;
    mpl->control = MPL_VT_control;
    mpl->transmit = MPL_VT_transmit;
    mpl->genheader = VideoEncoderGenStreamHeader;
    mpl->parse_packet = VideoCall_ParsePacket;
    return ret;
}

#endif  // __VE_VIDEO_VT_SUPPORT__
#endif  // __VE_VIDEO_ARCHI_V2__

