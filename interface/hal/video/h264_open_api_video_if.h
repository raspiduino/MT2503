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
 *
 * Filename:
 * ---------
 *    video_if.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file defines video H.264 application interface.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _VIDEO_IF_H_
#define _VIDEO_IF_H_

#include "med_status.h"
////////////////////
// common utilities
#ifndef __DRV_COMM_H__
#define DRV_WriteReg32(addr,data)     ((*(volatile kal_uint32 *)(addr)) = (kal_uint32)(data))
#define DRV_Reg32(addr)               (*(volatile kal_uint32 *)(addr))
#endif
#define H264_YUV_BUFFER 17

/*******************************************************************************
*   UT Usage
*******************************************************************************/
typedef enum
{
    NO_DELIMITER,
    THREE_TRAILING_ZERO_DELIMITER,
    START_CODE_DELIMITER
}VIDEO_H264_TEST_DELIMITER_T;

typedef struct
{
    kal_uint32 read_index;
    kal_uint32 write_index;
    kal_uint32 status[H264_YUV_BUFFER];
    kal_bool released[H264_YUV_BUFFER];
    kal_bool outputed[H264_YUV_BUFFER];
}YUV_BUFFER_INFO_T;

typedef struct
{
    kal_uint32 v_addr;
    kal_uint32 p_addr;
}MEM_NODE_TYPE_T;

/*
// Error code
typedef enum
{
    MEDIA_STATUS_OK = 0,
    VIDEO_ERROR,
    VIDEO_PROFILE_ERROR, 	// profile > 66
    VIDEO_LEVEL_ERROR, 		// level > 3.0
    VIDEO_RESOLUTION_ERROR,
    MAX_VIDEO_ERROR
} MEDIA_STATUS_CODE;
*/

/*******************************************************************************
*   Common Driver Interface
*******************************************************************************/

typedef enum
{
    OPEN_API_PARAM_WIDTH,
    OPEN_API_PARAM_HEIGHT,
    OPEN_API_PARAM_REAL_WIDTH,
    OPEN_API_PARAM_REAL_HEIGHT,
    OPEN_API_PARAM_MEM_INFO,
    OPEN_API_PARAM_FLUSH_BUFFER_CMD,
    OPEN_API_PARAM_CROPPING_INFO,
    OPEN_API_PARAM_TIMEOUT
}OPEN_API_PARAM_TYPE_T;

typedef enum
{
    H264_STATUS_OK,
    H264_STATUS_ERROR,
    H264_STATUS_SPS_ERROR,
    H264_STATUS_PPS_ERROR,
    H264_STATUS_DECODE_OK,
    H264_STATUS_DECODE_ERROR
}H264_DECODE_STATUS_CODE_T;

typedef struct
{
    kal_uint32 u4LeftX;
    kal_uint32 u4RightX;
    kal_uint32 u4TopY;
    kal_uint32 u4BottomY;
}H264_DECODE_CROPPING_T;

typedef struct
{
    kal_uint32 u4IntMemSize;
    kal_uint32 u4ExtMemSize;
    kal_uint32 isBsCacheable;
    kal_uint32 isFrameCacheable;
    kal_bool fgExtCacheable;
}OPEN_API_MEM_INFO_T;

typedef struct
{
    kal_uint32 u4AddrOfNALu;
    kal_uint32 u4LengthOfNALu;
    void *pReseved;
}VIDEO_DECODE_PARAM_T;

typedef struct
{
    MEM_NODE_TYPE_T int_mem_addr;
    kal_uint32 int_mem_size;
    MEM_NODE_TYPE_T ext_mem_addr;
    kal_uint32 ext_mem_size;

    kal_bool fgDisplayOrderMode;

    void (*pfnReturnBsBufferCallback)(kal_uint32 u4Address);
    void (*pfnSetFrameUnReferenceCallback)(kal_uint32 u4Address);
    void (*pfnOutputOneFrameCallback)(kal_uint32 u4Address, kal_bool fgCorruptedFrame);
    kal_uint32 (*pfnGetYUVBufferCallback)(void);
    kal_uint32 (*pfnVideoP2VAddrCallback)(kal_uint32 u4Address);
    kal_uint32 (*pfnVideoV2PAddrCallback)(kal_uint32 u4Address);    

    void *pReserved;
}H264_DEC_INIT_PARAM_TYPE_T;

extern MEDIA_STATUS_CODE VideoH264DecOpen(void *param);
extern MEDIA_STATUS_CODE VideoH264DecClose(void);
extern H264_DECODE_STATUS_CODE_T VideoH264DecNALu(VIDEO_DECODE_PARAM_T *prParam);
extern void VideoH264DecGetParam(OPEN_API_PARAM_TYPE_T rType, void *pParam, kal_uint32 u4Size);
extern void VideoH264DecSetParam(OPEN_API_PARAM_TYPE_T rType, void *pParam, kal_uint32 u4Size);
extern void VideoH264DecTimeoutReset(void);
extern MEDIA_STATUS_CODE VideoH264DecMemInit(kal_uint32 u4BsAddr, kal_uint32 u4BsSize, 
                                             kal_uint32 u4FrmAddr, kal_uint32 u4FrmSize);
extern void VideoH264DecMemDeInit(void);
extern kal_uint32 VideoH264DecMemGetBsBuffer(kal_uint32 u4Size);
extern kal_uint32 VideoH264DecMemGetYUVBuffer(kal_uint32 u4Size);
extern void VideoH264DecMemFreeBsBuffer(kal_uint32 u4Addr);

#endif /*VIDEO_DECODE_H*/


