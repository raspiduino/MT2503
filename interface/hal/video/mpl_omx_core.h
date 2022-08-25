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
 * mpl_if.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes function prototypes of open max IL data type.
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _MPL_OMX_CORE_H_
#define _MPL_OMX_CORE_H_

#include "kal_general_types.h"

typedef enum
{
    VIDEO_ERROR_NONE = 0,
    VIDEO_ERROR_INIT_ERROR,
    VIDEO_ERROR_DEINIT_ERROR,
    VIDEO_ERROR_FSAL_ERROR,
    VIDEO_ERROR_PARSER_ERROR,
    VIDEO_ERROR_BUFF_FULL,
    VIDEO_ERROR_BUFF_HIGH,
    VIDEO_ERROR_INPUT_PARAM_ERROR,
    VIDEO_ERROR_QUERY_FRAME_SIZE,
    VIDEO_ERROR_DECODER_ERROR,
    VIDEO_ERROR_ENCODER_ERROR,
    VIDEO_ERROR_ENCODER_RESOLUTION_ERROR,
    VIDEO_ERROR_CODEC_NOT_SUPPORT,
    VIDEO_ERROR_NO_VISUAL_TRACK,
    VIDEO_ERROR_NO_FRAME_HAS_BEEN_ENCODED,  /* No frame has been encoded. */
    VIDEO_ERROR_UNDEFINED,
    VIDEO_ERROR_NO_FRAME_TO_FLUSH,
    VIDEO_ERROR_GET_HANDLE_ERROR,
    VIDEO_ERROR_UNUSED_OPERATION,
    VIDEO_ERROR_TIME_STAMP,
    VIDEO_ERROR_ASYNC_OPERATION,
    VIDEO_ERROR_NO_MEMORY,

    /*Error code of Muxer*/
    VIDEO_ERROR_MUXER_ERROR_BEGIN = 100,
    VIDEO_ERROR_MUXER_ERROR,
    VIDEO_ERROR_MUXER_NOT_SUPPORT,
    VIDEO_ERROR_MUXER_WRITE_NOTHING,
    VIDEO_ERROR_MUXER_FS_ERROR,
    VIDEO_ERROR_MUXER_DISK_FULL,
    VIDEO_ERROR_MUXER_FAILED_2_CREATE_FILE,
    VIDEO_ERROR_MUXER_INCORRECT_FILE_SIZE,
    VIDEO_ERROR_MUXER_NO_DISK,
    VIDEO_ERROR_MUXER_ERROR_END,
    VIDEO_ERROR_MUXER_REACH_SIZE_LIMIT,
    VIDEO_ERROR_MUXER_NO_TEMP_FILE,
    VIDEO_ERROR_MUXER_EXIST_TEMP_FILE,
    VIDEO_ERROR_MUXER_NO_VIDEO_FRAME_ENCODED,
    VIDEO_ERROR_MUXER_ABORT_SAVING_DONE,
    VIDEO_ERROR_MAX
} VIDEO_ERROR_TYPE_T;

typedef enum
{
    VIDEO_BUFFERFLAG_NONE               = 0x00000001,
    VIDEO_BUFFERFLAG_EOF                = 0x00000002,
    VIDEO_BUFFERFLAG_STARTTIME          = 0x00000004,
    VIDEO_BUFFERFLAG_DECODEONLY         = 0x00000008,
    VIDEO_BUFFERFLAG_DATACORRUPT        = 0x00000010,
    VIDEO_BUFFERFLAG_SYNCFRAME          = 0x00000020,
    VIDEO_BUFFERFLAG_PARAMETERSET       = 0x00000040,
    VIDEO_BUFFERFLAG_SILENT             = 0x00000080,
    VIDEO_BUFFERFLAG_END_OF_FRAME       = 0x00000100,
    VIDEO_BUFFERFLAG_EXCEED_TIME_LIMIT  = 0x00000200,
    VIDEO_BUFFERFLAG_TRIGGER_AUDIO      = 0x00000400,
    VIDEO_BUFFERFLAG_INVALID_FRAME      = 0x00000800,
    VIDEO_BUFFERFLAG_RENDER_DISPLAY     = 0x00001000,    
    VIDEO_BUFFERFLAG_MAX                = 0x40000000
} VIDEO_BUFFERFLAG_TYPE_T;

typedef struct
{
    kal_uint8 *pu1Buffer;
    kal_uint32 u4BuffSize;
    //kal_uint32 u4FillSize;
    //kal_uint32 u4Offset;
    kal_uint64 u8TimeStamp;
    VIDEO_BUFFERFLAG_TYPE_T eFlags;
    kal_uint32 u4InputPort;
    kal_uint32 u4OutputPort;
    void      *pPrivateData;
} VIDEO_BUFFERHEADER_TYPE_T;

#endif /* _MPL_OMX_CORE_H_ */
