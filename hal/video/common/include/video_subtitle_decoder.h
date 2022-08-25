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
 *   video_subtitle_decoder.h
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 ****************************************************************************/
#ifndef VIDEO_SUBTITLE_DECODER_H
#define VIDEO_SUBTITLE_DECODER_H


#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__


#include "video_types_v2.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
// #include "video_codec_utility_v2.h"
// #include "video_buffer_management_v2.h"
#include "video_subtitle_decoder_if.h"
#include "SubtitleFont_if.h"


typedef enum
{
    VSD_LUMP_STATUS_FREE            = 0,
    VSD_LUMP_STATUS_LEASED          = 1,  /* used by front end */
    VSD_LUMP_STATUS_BAILED_OUT      = 2,  /* used by back end */
    VSD_LUMP_STATUS_CEASED          = 3   /* to be freed (back end finished using it) */
} VSD_LUMP_STATUS_T;


typedef struct
{
    VSD_LUMP_STATUS_T eFlag;
    VIDEO_BUFFERHEADER_TYPE_T rBitHeader;
    VIDEO_BUFFERHEADER_TYPE_T rFrameHeader;
    kal_uint8 *pu1Buffer;  // FIXME: Eliminate it or change its name to pu1FrameBuffer.
    VA2_VIDEO_FRAME_T rVaPrivateData;
} VSD_LUMP_T;


typedef struct
{
    VSD_LUMP_T arLump[VIDEO_SUBTITLE_MAX_FRAMES];
    kal_uint8 *pu1FrameBufferStart;  // Starting address of the whole lump buffer.
    kal_uint32 u4TotalNum;
    kal_uint32 u4UsedNum;
    kal_uint32 u4GetIdx;        // Index of the buffer to be gotten
    kal_uint32 u4RetIdx;        // Index of the buffer to be returned
    //kal_bool fgInited;
} VSD_LUMP_MGR_T;


typedef enum
{
    VSD_ACTION_NONE                 = 0,
    VSD_ACTION_COMMAND              = 1,
    VSD_ACTION_PROCESS_BACK_END     = 2,
    VSD_ACTION_SEND_TO_FRONT_END    = 3,
    VSD_ACTION_SEND_TO_BACK_END     = 4,
    VSD_ACTION_PROCESS_FRONT_END    = 5,
    VSD_ACTION_MAX                  = 0x1FFF
} VSD_ACTION_T;


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0


typedef struct
{
    VIDEO_COMM_STATE_T rCommState;

    VIDEO_EXTMEM_HANDLER_T *prExtMemInfo;

    VSD_LUMP_MGR_T rLumpMgr;
    kal_uint64 u8PartialResetTimeStamp;

    VSD_CODEC_T eVsdCodec;
    VSD_CODEC_API_T *prCodecApi;
    subtitle_fontengine_struct rFontEngineApi;

    kal_uint32 u4Width;
    kal_uint32 u4Height;
    kal_uint32 u4FrameSize;

    kal_uint32 u4FontSize;
    VSD_COLORS_T rColors;
    VSD_ENCODING_T eEncoding;
    VSD_ALIGNMENT_T rAlignment;
    VSD_FONT_STYLES_T rFontStyles;

    // VSD_PROFILEING_T rProfiling;
    kal_bool fgClosing;

    kal_bool fgIsFrontEndReceiverFull;  // FIXME
    kal_bool fgIsBackEndReceiverFull;   // FIXME
    kal_bool fgGotPartialReset;
    kal_bool fgGotResetQueues;
    kal_bool fgNoMoreInput;
} VSD_MGR_T;


// typedef PFN_PROCESS_BUFFER_T PFN_VSD_PROCESS_BUFFER_T;


typedef enum
{
    VSD_MESSAGE_COMMAND         = 0,
    VSD_MESSAGE_FILL_BUFFER     = 1,
    VSD_MESSAGE_EMPTY_BUFFER    = 2,
    VSD_MESSAGE_WAKE_UP         = 3,
    VSD_MESSAGE_MAX             = 0x1FFF
} VSD_MESSAGE_T;


typedef enum
{
    VSD_PORT_FRONT_END_OUTPUT       = 0,
    VSD_PORT_BACK_END_OUTPUT        = 1
} VSD_PORT_T;


#ifndef ROUND_UP_TO_POWER_OF_TWO
#define ROUND_UP_TO_POWER_OF_TWO(data,x)        \
        (((kal_uint32)(data) + (kal_uint32)(x) - 1) & ~((kal_uint32)(x) - 1))
#endif  // ROUND_UP_TO_POWER_OF_TWO


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 u4Param1;
    kal_uint32 u4Param2;
} VSD_MSG_IND_T;


#endif  // __VE_VIDEO_ARCHI_V2__


#endif  // VIDEO_SUBTITLE_DECODER_H

