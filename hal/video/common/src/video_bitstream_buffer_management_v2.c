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
 *   video_bitstream_buffer_management_v2.c
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
 ****************************************************************************/
 #include "drv_comm.h"
#ifdef __VIDEO_ARCHI_V2__
#if defined(__MPEG4_DEC_SUPPORT__) || defined(__H264_DEC_SUPPORT__)
#include "kal_release.h"      /* Basic data type */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"      /* Task creation */
#include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"       /* Event scheduler */
#include "stack_timer.h"      /* Stack timer */
#include "video_types_v2.h"
#include "video_filereader_component_v2.h"
#include "video_bitstream_buffer_management_v2.h"

/*********************************************************
*
* Extern  function
*
*********************************************************/
static kal_uint32 VideoBitstreamBuffGetFillThreshold(VIDEO_BITSTREM_BUFF_STATUS_T *pBitstreamBuff);

//////////////////////////////////////////////////////////
//    Bitstream buffer related functions
/////////////////////////////////////////////////////////
// Initialize bitstream buffer structure
//
void VideoBitstreamBuffInit(VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuff, kal_uint8 *pu1StartAddr, kal_uint32 u4TotalSize, kal_uint32 u4MaxHeaderCount)
{
    if (!prBitstreamBuff || !pu1StartAddr)
    {
        ASSERT(0);
        return;
    }

    // Initialize bitstream buffer
    //
    if (u4TotalSize <= VIDEO_FILEREADER_BITSTREAM_BUFF_SIZE)
    {
        prBitstreamBuff->rBitstreamBuff.u4TotalSize = u4TotalSize;
    }
    else
    {
        ASSERT(0);
    }
        
    
    prBitstreamBuff->rBitstreamBuff.pu1BuffStartAddr = pu1StartAddr;
    prBitstreamBuff->rBitstreamBuff.u4ReadOffset = 0;
    prBitstreamBuff->rBitstreamBuff.u4WriteOffset = 0;
    prBitstreamBuff->rBitstreamBuff.fgIsFull = KAL_FALSE;

    kal_mem_set(prBitstreamBuff->rBitstreamBuff.pu1BuffStartAddr, 0x00, prBitstreamBuff->rBitstreamBuff.u4TotalSize);

    // Initialize buffer header control block 
    //

    kal_mem_set(&prBitstreamBuff->rBuffHeader, 0x00, sizeof(VIDEO_BITSTREM_BUFF_HEADER_T));

    if (u4MaxHeaderCount <= VIDEO_BITSTREAM_BUFF_MAX_NUM)
    {
        prBitstreamBuff->rBuffHeader.u4MaxHeaderCount = u4MaxHeaderCount;
    }
    else
    {
        ASSERT(0);
    }
}

kal_bool VideoBitstreamBuffQueryHeaderEmpty(VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuff)
{
    if (!prBitstreamBuff)
    {
        ASSERT(0);
        return KAL_FALSE;
    }
    if (!prBitstreamBuff->rBuffHeader.fgIsFull && prBitstreamBuff->rBuffHeader.u4ReadIndex == prBitstreamBuff->rBuffHeader.u4WriteIndex)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
    
}

kal_bool VideoBitstreamBuffQueryHeaderFull(VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuff)
{
    if (!prBitstreamBuff)
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    if (prBitstreamBuff->rBuffHeader.fgIsFull && prBitstreamBuff->rBuffHeader.u4ReadIndex == prBitstreamBuff->rBuffHeader.u4WriteIndex)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

// TODO: Considerate two different cases
kal_uint32 VideoBitstreamBuffQueryAvailable(VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuff, kal_bool fgWrapped)
{
    kal_uint32 nRetBuffSize;
    kal_uint32 u4ReadOffset;
    kal_uint32 u4WriteOffset;
    kal_uint32 u4TotalSize;    

    if (!prBitstreamBuff)
    {
        ASSERT(0);
        return 0;
    }    

    u4ReadOffset = prBitstreamBuff->rBitstreamBuff.u4ReadOffset;
    u4WriteOffset = prBitstreamBuff->rBitstreamBuff.u4WriteOffset; // u4WriteOffset should point to next write offset (empty space)
    u4TotalSize = prBitstreamBuff->rBitstreamBuff.u4TotalSize;    

    // The range of u4ReadOffset and u4WriteOffset is in [0 ~ (u4TotalSize - 1)]
    //
    if (u4ReadOffset >= u4TotalSize || u4WriteOffset >= u4TotalSize)
    {
        ASSERT(0);
    }
    
    if (u4WriteOffset > u4ReadOffset)
    {
        (fgWrapped == KAL_TRUE)? \
            (nRetBuffSize = u4TotalSize - u4WriteOffset + u4ReadOffset): \
            (nRetBuffSize = u4TotalSize - u4WriteOffset);
    }
    else if (u4WriteOffset < u4ReadOffset)
    {
        nRetBuffSize = u4ReadOffset - u4WriteOffset;
    }
    else if (prBitstreamBuff->rBitstreamBuff.fgIsFull)
    {
        nRetBuffSize = 0;
    }
    else
    {
        nRetBuffSize = u4TotalSize;
    }
    
    return nRetBuffSize; 
}

// Get bitstream buffer fill threshold.
// 
static kal_uint32 VideoBitstreamBuffGetFillThreshold(VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuff)
{
    kal_uint32 u4Threshold;
    
    if (!prBitstreamBuff)
    {
        ASSERT(0);
        return 0;
    }     

    u4Threshold = prBitstreamBuff->rBitstreamBuff.u4FillThreshold;

    ASSERT(u4Threshold <= prBitstreamBuff->rBitstreamBuff.u4TotalSize);
    return u4Threshold;
}

// Set bitstream buffer fill threshold.
// 
kal_bool VideoBitstreamBuffSetFillThreshold(VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuff, kal_uint32 u4Threashold)
{
    kal_uint32 u4InputThreshold;
    kal_uint32 u4ThresholdLimit;
    
    if (!prBitstreamBuff)
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    if (prBitstreamBuff->rBitstreamBuff.u4TotalSize != 0)
    {
        u4ThresholdLimit = (prBitstreamBuff->rBitstreamBuff.u4TotalSize >> 2);
    }
    else
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    u4InputThreshold = u4Threashold;

    if (u4Threashold > u4ThresholdLimit)
    {
        
        u4Threashold = u4ThresholdLimit;
    }

    drv_trace2(TRACE_GROUP_9, VFILE_BITSTREAM_THRESHOLD, u4Threashold, u4InputThreshold);
    
    prBitstreamBuff->rBitstreamBuff.u4FillThreshold = u4Threashold;

    return KAL_TRUE;
}

kal_bool VideoBitstreamBuffCheckFillThreshold(VIDEO_BITSTREM_BUFF_STATUS_T *prBitstreamBuff, kal_uint32 *pu4AvailableSize)
{
    kal_uint32 u4Threshold;
    kal_uint32 u4AvailableSize;

    if (!prBitstreamBuff || !pu4AvailableSize)
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    if (KAL_TRUE == VideoBitstreamBuffQueryHeaderFull(prBitstreamBuff))
    {
        return KAL_FALSE;
    }
    // Bitstream buffer header is not full
    //
    else
    {
        u4Threshold = VideoBitstreamBuffGetFillThreshold(prBitstreamBuff);
        u4AvailableSize = VideoBitstreamBuffQueryAvailable(prBitstreamBuff, KAL_TRUE);

        if (u4Threshold < u4AvailableSize)
        {
            *pu4AvailableSize = u4AvailableSize;

            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
}
#endif /*#if defined(__MPEG4_DEC_SUPPORT__) || defined(__H264_DEC_SUPPORT__)*/
#endif /* __VIDEO_ARCHI_V2__ */
