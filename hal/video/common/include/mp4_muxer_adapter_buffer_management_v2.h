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
 *   mp4_muxer_adapter_buffer_management_v2.h
 *
 * Project:
 * --------
 *   MAUI
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
 ****************************************************************************/
#ifndef __MP4_MUXER_ADAPTER_BUFFER_MANAGEMENT_V2_H
#define __MP4_MUXER_ADAPTER_BUFFER_MANAGEMENT_V2_H

#include "video_types_v2.h"

// write control block number, the control block only keep start address and size of each frame
// Note: MP4_BITSTREAM_CTRL_NUM must be greater than 2 because at least 1
//       entry and at most 2 entries are wasted on purpose for easier programming.
#define MP4_BITSTREAM_CTRL_NUM              18
#define MP4_MAX_WASTED_BIT_CTRL_UNITS        2

/******************************************************************************
* Structure Definition
******************************************************************************/
typedef enum
{
    MP4_BIT_CTRL_UNIT_NOT_USED = 0,
    MP4_BIT_CTRL_UNIT_TO_BE_COLLECTED,   // The amount of data has not reached the threshold.
    MP4_BIT_CTRL_UNIT_TO_BE_WRITTEN,     // The amount of data has reached the threshold, and is to be written to file.
    MP4_BIT_CTRL_UNIT_TO_BE_FREED        // The data has been written to file, and is to be freed.
} MP4_BIT_CTRL_UINT_STATUS_T;

// keep start address and size of each continous bitstream buffer
// change control unit when encounter (1) not continous bitstream adddress (2) reach threshold
typedef struct
{
    kal_uint32 u4StartAddr;
    kal_uint32 u4Size;
    MP4_BIT_CTRL_UINT_STATUS_T eStatus;
} MP4_BIT_CTRL_UNIT_T;

typedef struct
{
    MP4_BIT_CTRL_UNIT_T arBitCtrlUnit[MP4_BITSTREAM_CTRL_NUM];
    kal_uint32 u4ReadIdx;   // read index of control unit
    kal_uint32 u4WriteIdx;  // write index of control unit
    kal_uint32 u4Entries;   // the number of control units (in this bit-control manager)
                            // At most 2 entries are wasted on purpose for easier programming!
                            // When u4WriteIdx is incremented, be sure to increment u4Entries.
                            // When u4ReadIdx is incremented, be sure to decrement u4Entries.
    kal_uint32 u4BitstreamTotalSize;
    kal_uint32 u4BitStreamOffset;
} MP4_BIT_CTRL_MGR_T;


/******************************************************************************
* Exported API
******************************************************************************/
extern void MP4_InitBitBuffer(MP4_BIT_CTRL_MGR_T *prBitCtrlMgr);

extern kal_bool MP4_AddBitBuffer(MP4_BIT_CTRL_MGR_T *prBitCtrlMgr,
        kal_uint32 u4Addr, kal_uint32 u4Size);

extern kal_bool MP4_QueryBitBufferStatus(MP4_BIT_CTRL_MGR_T *prBitCtrlMgr);

extern kal_bool MP4_GetBitBuffer(MP4_BIT_CTRL_MGR_T *prBitCtrlMgr,
        kal_uint8 **pu1Addr, kal_uint32 *pu4Size);

extern kal_bool MP4_QueryFreedBitBuffer(MP4_BIT_CTRL_MGR_T *prBitCtrlMgr,
        kal_uint8 **pu1Addr, kal_uint32 *pu4Size);

extern kal_bool MP4_MarkBitBufferForFlush(MP4_BIT_CTRL_MGR_T *prBitCtrlMgr);

extern void MP4_FreeBitBufferUnit(MP4_BIT_CTRL_MGR_T *prBitCtrlMgr);

extern void MP4_MarkFirstUnitOnError(MP4_BIT_CTRL_MGR_T *prBitCtrlMgr);
extern kal_uint32 MP4_QueryWrittenBufferCount(MP4_BIT_CTRL_MGR_T * const prBitCtrlMgr);
#endif // __MP4_MUXER_ADAPTER_BUFFER_MANAGEMENT_V2_H
