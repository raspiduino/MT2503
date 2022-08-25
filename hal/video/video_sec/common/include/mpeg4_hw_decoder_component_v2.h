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
 *   mpeg4_decoder_component.h
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
 *
 *
 *
 *
 *
 ****************************************************************************/
#ifndef MPEG4_HW_DECODER_COMPONENT_H
#define MPEG4_HW_DECODER_COMPONENT_H

#include "drv_comm.h"
#include "drv_features_video.h"

#ifdef __VE_VIDEO_ARCHI_V2__
#ifdef __VE_MPEG4_DEC_HW_SUPPORT__
#include "kal_general_types.h"
#include "video_codec_type_v2.h"
#include "video_codec_if_v2.h"

#define VOP_START_CODE    0x1b6

typedef enum
{
    MPEG4_SWITCH_TO_CACHE = 0,
    MPEG4_SWITCH_TO_NONCACHE,
    MPEG4_SWITCH_NONE
}MPEG4_HWDEC_MEMORY_SWITCH_T;

typedef struct
{
    kal_uint8* pu1ExtMemAddr;
    kal_uint32 u4ExtMemSize;
    kal_uint8* pu1ExtMemAddrAlign; // Cache line aligned start address
    kal_uint32 u4ExtMemSizeAlign; // Cache line aligned size
    MPEG4_HWDEC_MEMORY_SWITCH_T eExtMemSwitch;
} MPEG4_HW_DECODER_EXT_MEM_T;

typedef struct
{
    kal_bool fgBSBufferCacheable;
    kal_bool fgFrmBufferCacheable;
    kal_bool fgIsBufferDefaultCacheable;

    kal_bool fgIsCodecInit;
    kal_bool fgIsOutputDisplay;
    kal_bool fgIsOutputRepeat;
    kal_bool fgInitBuffer;
    kal_bool fgCheckedBS;
    kal_uint8* pu1RefYUVAddr;
    kal_uint8* pu1DecYUVAddr;
    kal_uint8* pu1NextDisplayAddr;
    kal_uint16 u2FrameWidth; // 16 aligned
    kal_uint16 u2FrameHeight; // 16 aligned
    kal_uint16 u2RealFrameWidth; // VOL width
    kal_uint16 u2RealFrameHeight; // VOL height
    kal_uint32 u4FrmBufferSize;
    kal_bool fgIsFirstFrameIn; // 1st frame input for decode
    kal_bool fgIsFirstFrameOut; // 1st frame output for display
    kal_uint32  u4BitRate;
    kal_uint32  u4FrameRate;
    kal_bool fgEOFSet; // EOF is set

    // Record the bitstream to be returned
    kal_uint8 *pu1DecodingBuffer;
    kal_uint32 u4DecodingBuffSize;

    // External memory
    MPEG4_HW_DECODER_EXT_MEM_T rExtMem;
    MPEG4_HW_DECODER_EXT_MEM_T rIntMem; // External memory for internal memory not enough

    VIDEO_CODEC_FRAME_TYPE_T eDisplayFrameType;
    MPEG4_HWDEC_MEMORY_SWITCH_T eBSBufferOperation;
    MPEG4_HWDEC_MEMORY_SWITCH_T eFrmBufferOperation;

    VIDEO_DECODER_SCENARIO_T eScenario;
    kal_uint32 u4MaxWidth;
    kal_uint32 u4MaxHeight;
}MPEG4_HW_DECODER_CTRL_T;

VIDEO_DECODER_CODEC_API_T* GetMPEG4HwDecoderHandler(VIDEO_DECODER_SCENARIO_T eType);

#endif /* __VE_MPEG4_DEC_HW_SUPPORT__ */
#endif /* __VE_VIDEO_ARCHI_V2__ */
#endif /* MPEG4_HW_DECODER_COMPONENT_H */
