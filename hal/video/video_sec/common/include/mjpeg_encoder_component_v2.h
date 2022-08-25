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
 *   mjpeg_encoder_component_v2.h
 *
 * Project:
 * --------
 *	MTK
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
 ****************************************************************************/
#ifndef MJPEG_ENCODER_COMPONENT_V2_H
#define MJPEG_ENCODER_COMPONENT_V2_H

#include "drv_comm.h"

#ifdef __VIDEO_ARCHI_V2__
#include "video_encoder_component_v2.h"
#include "video_types_v2.h"
#include "video_codec_if_v2.h"

#include "jpeg_encode_api.h"

typedef enum
{
    MJPEG_SCENARIO_UNKNOWN = 0,
    MJPEG_SCENARIO_RECORDER
}MJPEG_ENC_SCENARIO_T;



typedef struct
{
    kal_uint8*  pu1StartAddr;
    kal_uint8*  pu1EndAddr;
    kal_uint8*  pu1WriteAddr;
    kal_uint8*  pu1ReadAddr;
    kal_uint32  u4AvailableLength;
    kal_uint32  u4TotalLength;
}MJPEG_BS_INFO_T;



typedef enum
{
    MJPEG_ENC_CLOSE,
    MJPEG_ENC_OPEN,
    MJPEG_ENC_INIT,
    MJPEG_ENC_READY_2_ENCODE,
    MJPEG_ENC_READY_2_GET_STREAM,
    MJPEG_ENC_DEINIT
}MJPEG_ENC_STATE_T;


typedef enum
{
    MJPEG_ENC_TYPE_SW = 0,
    MJPEG_ENC_TYPE_HW
}MJPEG_ENC_TYPE_ENUM;



typedef struct
{
    JPEG_CODEC_STATE_ENUM eCallbackStatus;
    kal_eventgrpid  rEncodeEvent;
    kal_uint32  u4EncodeEventGroup;
    MJPEG_ENC_STATE_T eEncState;
    kal_uint32  u4Width;
    kal_uint32  u4Height;
    kal_uint32  u4DstRequiredSize;
    
    kal_uint32  u4IntMemSizeBest;
    kal_uint32  u4IntMemSizeMin;    
    kal_uint32  u4ExtMemSizeBest;
    kal_uint32  u4ExtMemSizeMin; 
    kal_uint8*  pu1IntMemAddr;
    kal_uint8*  pu1ExtMemAddr;

    kal_uint8*  pu1CodingFrameAddr;
    kal_bool    fgWaitingCallback;

    MJPEG_BS_INFO_T rBistreamInfo;
    
    JPEG_YUV_FORMAT_ENUM   eSrcFormat;
    JPEG_ENCODE_QUALITTY_ENUM   eQuality;
    VIDEO_CODEC_ROTATE_ANGLE_T eGotRotateAngle;             //The rotation angle set from common part
    JPEG_ENCODE_ROTATE_ANGLE_ENUM   eCodecRotationAngle;    //The rotation angle going to set to codec
    
    MJPEG_ENC_SCENARIO_T    eScenario;
    JPEG_ENCODER_HANDLE     rJPGHandle;
} MJPEG_ENCODER_MGR_T;

VIDEO_ENCODER_CODEC_API_T* GetMJPEGEncoderHandler(MJPEG_ENC_SCENARIO_T eScenario);
VIDEO_ENCODER_CODEC_ERROR_T GetMJPEGEncoderType(MJPEG_ENC_TYPE_ENUM *type);


#endif /* __VIDEO_ARCHI_V2__*/
#endif /* MJPEG_ENCODER_COMPONENT_V2_H */


