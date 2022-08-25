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
 *   video_bitstream_buffer_management.h
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
 *
 ****************************************************************************/
#ifndef VIDEO_BITSTREAM_BUFFER_MANAGEMENT_H
#define VIDEO_BITSTREAM_BUFFER_MANAGEMENT_H
#ifdef __VIDEO_ARCHI_V2__
#include "video_types_v2.h"

///////////////////////////////////////////////////////
//            Bitstream buffer management
///////////////////////////////////////////////////////

#define VIDEO_BITSTREAM_BUFF_MAX_NUM   300

typedef struct
{
    kal_uint32 u4MaxHeaderCount;
    // TODO: check any place that change u4ReadIndex, u4WriteIndex and update fgIsFull
    kal_bool   fgIsFull;
    kal_uint32 u4ReadIndex;
    kal_uint32 u4WriteIndex;
    kal_uint32 u4DeliverIndex;
    kal_uint32 au4FrameNum[VIDEO_BITSTREAM_BUFF_MAX_NUM];
    kal_uint32 au4Address[VIDEO_BITSTREAM_BUFF_MAX_NUM];
    kal_uint32 au4Length[VIDEO_BITSTREAM_BUFF_MAX_NUM];
    // au8Timestamp uint: video timescale; an absolute value
    kal_uint64 au8Timestamp[VIDEO_BITSTREAM_BUFF_MAX_NUM];
}VIDEO_BITSTREM_BUFF_HEADER_T;

typedef struct
{
    kal_uint8 *pu1BuffStartAddr;
    kal_uint32 u4TotalSize;
    kal_bool   fgIsFull;
    kal_uint32 u4ReadOffset;
    kal_uint32 u4WriteOffset; // u4WriteOffset should point to next write offset (empty space)

    kal_uint32 u4FillThreshold;

}VIDEO_BITSTREM_BUFF_T;

typedef struct
{
    VIDEO_BITSTREM_BUFF_T rBitstreamBuff;
    VIDEO_BITSTREM_BUFF_HEADER_T rBuffHeader;
}VIDEO_BITSTREM_BUFF_STATUS_T;

extern void VideoBitstreamBuffInit(VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuff, kal_uint8 *pu1StartAddr, kal_uint32 u4TotalSize, kal_uint32 u4MaxHeaderCount);
extern kal_bool VideoBitstreamBuffQueryHeaderEmpty(VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuff);
extern kal_bool VideoBitstreamBuffQueryHeaderFull(VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuff);
extern kal_uint32 VideoBitstreamBuffQueryAvailable(VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuff, kal_bool fgWrapped);
extern kal_bool VideoBitstreamBuffSetFillThreshold(VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuff, kal_uint32 u4Threashold);
extern kal_bool VideoBitstreamBuffCheckFillThreshold(VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuff, kal_uint32 *pu4AvailableSize);
#endif /* __VIDEO_ARCHI_V2__ */
#endif /* VIDEO_BITSTREAM_BUFFER_MANAGEMENT_H */

