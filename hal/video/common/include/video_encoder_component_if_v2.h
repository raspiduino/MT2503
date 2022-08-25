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
 *   video_encoder_component_if_v2.h
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
 * removed!
 * removed!
 *
 *
 *
 ****************************************************************************/

#ifndef VIDEO_ENCODER_COMPONENT_IF_V2_H
#define VIDEO_ENCODER_COMPONENT_IF_V2_H

#include "drv_features_video.h"

#if defined(__VE_VIDEO_ARCHI_V2__)


#include "video_types_v2.h"
#include "app_ltlcom.h"
#include "video_buffer_management_v2.h"
#include "kal_general_types.h"
#include "mpl_recorder.h"
#include "video_encoder_if.h"
#include "video_codec_mem_v2.h"

#define VENC_COMMAND_Q_NUM             10
#define VIDEO_ENCODER_INPUT_BUFFER_Q_NUM        10
#define VENC_OUTPUT_BUFFER_Q_NUM       10
#define VIDEO_ENCODER_RESEND_Q_NUM              6
#define VIDEO_ENCODER_YUV_HEADER_Q_NUM          10
#define VENC_TIME_STAMP_Q_NUM          VIDEO_ENCODER_YUV_HEADER_Q_NUM
#define VIDEO_ENCODER_MAX_YUV_BUF_NUM           (VIDEO_ENC_MAX_YUV_FRAME_NUM)


/* This is the buffer header used internally by the encoder component. */
// Make sure: VIDEO_ENCODER_YUV_HEADER_Q_ITEM_SIZE >= sizeof(VIDEO_YUV_HEADER_T)
#define VENC_YUV_HEADER_Q_ITEM_SIZE    56
typedef struct
{
    VIDEO_BUFFERHEADER_TYPE_T rBuffHeader;
    kal_bool fgInUse;
    kal_bool fgReceived;
} VIDEO_YUV_HEADER_T;


// Make sure: VIDEO_ENCODER_TIME_STAMP_Q_ITEM_SIZE >= sizeof(kal_uint64)
#define VENC_TIME_STAMP_Q_ITEM_SIZE    8
typedef struct
{
    kal_uint64 *pau8TimeStamp;
    kal_uint64 *pu8Start;                   // Always point to &(au8TimeStamp[0])
    kal_uint64 *pu8End;                     // Always point to &(au8TimeStamp[VIDEO_ENCODER_TIME_STAMP_Q_NUM])
    kal_uint64 *pu8RP;                      // Read pointer
    kal_uint64 *pu8WP;                      // Write pointer
    kal_uint32 u4NumOfItems;                // Number of items in the queue
    kal_uint32 u4AccumNum;                  // Accumulated number of items in the queue (for debugging)
} VIDEO_ENCODER_TIME_STAMP_Q_T;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 u4Param1;
    kal_uint32 u4Param2;
} VIDEO_ENCODER_IND_T;


typedef enum
{
    MSG_COMMAND = 0,
    MSG_FILLBUFFER,
    MSG_EMPTYBUFFER,
    MSG_WAKEUP
} VIDEO_ENCODER_MESSAGE_T;

// clock-wise
typedef enum
{
    VENC_ROTATE_0     =   0,
    VENC_ROTATE_90    =   1,
    VENC_ROTATE_180   =   2,
    VENC_ROTATE_270   =   3
}VIDEO_ENCODER_ROTATE_ANGLE_T;

typedef struct
{
    kal_uint32 u4EncodeWidth;
    kal_uint32 u4EncodeHeight;
} VENC_RESOLUTION_T;

extern void VideoEncoderMainNonDCM(ilm_struct *ilm_ptr);
extern VIDEO_COMPONENT_TYPE_T* GetVideoEncoderHandle(VIDEO_ENCODER_TYPE_T eType, VIDEO_EXTMEM_HANDLER_T* prExtMemHdlr, VIDEO_INTMEM_HANDLER_T* prIntMemHdlr);
extern VIDEO_ERROR_TYPE_T ReleaseVideoEncoderHandle(VIDEO_COMPONENT_TYPE_T *prHandle);
extern void VideoEncoderWakeUp(void* pParam);

kal_uint32 GetVideoEncoderExtMemSize(
    VIDEO_ENCODER_TYPE_T eType,
    kal_uint32 u4EncWidth,
    kal_uint32 u4EncHeight);

extern MPL_BUFFER_INFO_T VENC_GetBistreamBuffer(void);
extern void VENC_ReturnBistreamBuffer(MPL_BUFFER_INFO_T rBuff);

#endif /*__VE_VIDEO_ARCHI_V2__*/
#endif /* VIDEO_ENCODER_COMPONENT_IF_V2_H */

