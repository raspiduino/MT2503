/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   mav_decoder.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Main include file of JPEG memory.
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MAV_DECODER_H__
#define __MAV_DECODER_H__


#include "mav_common.h"
#include "fsal.h"
#include "fs_gprot.h"
#include "ivlw_common.h"
#include "jpeg_decode_api.h"
#include "jpeg_misc_api.h"
#include "ivlw_decoder.h"

typedef enum
{
   MAV_DEC_STATUS_OK = 0,
   MAV_DEC_STATUS_HANDLE_UNAVAILABLE,
   MAV_DEC_STATUS_MEM_UNAVAILABLE,
   MAV_DEC_STATUS_INVALID_FILE,
   MAV_DEC_STATUS_INVALID_PARA,
   MAV_DEC_STATUS_FS_FAIL = 5,
   MAV_DEC_STATUS_FS_ASYNC_NOT_SUPPORT,
   MAV_DEC_STATUS_FAIL,
   MAV_DEC_STATUS_INVALID_CALL_SEQENCE,
   MAV_DEC_STATUS_JPEG_HANDLE_UNAVAILABLE,
   MAV_DEC_STATUS_JPEG_HANDLE_FREE_FAIL = 10,
   MAV_DEC_STATUS_JPEG_FAIL,
   MAV_DEC_STATUS_RSZ_FAIL,
   MAV_DEC_STATUS_RSZ_UNAVAILABLE,
   MAV_DEC_STATUS_IVLW_FAIL,

   MAV_DEC_STATUS_RSVD
}MAV_DEC_STATUS;


typedef struct
{
   STFSAL *fp;
   kal_uint32 frameCnt;
   kal_uint32 partitionCount;
   kal_uint32 frameHeaderLen;

   kal_uint8 *fsalCacheAddr;
   kal_uint32 fsalCacheSize;
   kal_uint8 *fsalReadBufferAddr;
   kal_uint32 fsalReadBufferSize;
   

   //Support HW RSZ in MAV
   MY_RECTANGLE rszSrcWnd;
   MY_RECTANGLE canvasWnd;
   MY_RECTANGLE outputWnd;
   MY_RECTANGLE clipWnd;
   void *rszSrcCanvasBuffer[3]; //src image buffer address of rsz
   kal_uint32 rszSrcCanvasBufferSize[3];
   void *canvasBuffer[3];
   JPEG_RGB_FORMAT_ENUM rgbCanvasFormat;
   JPEG_YUV_FORMAT_ENUM yuvCanvasFormat;
   kal_bool upScale;
   kal_uint8* tempOutputBuffer; //working buffer for src image of RSZ used when resize is needed.
   kal_uint32 tempOutputBufferSize; //used when resize is needed.

   
   IVLW_DECODER_HANDLE *ivlwHandle;
   JPEG_DECODER_HANDLE jpegHandle;
   JPEG_STATUS_ENUM jpegStatus;
}MAV_DECODER_HANDLE;

typedef void (*mav_async_get_srcbuf_callback)(MAV_DEC_STATUS error_code, void *callback_para);
typedef void (*mav_abort_callback)(MAV_DEC_STATUS error_code, void *callback_para);


MAV_DEC_STATUS
mavDecGetHandle(MAV_DECODER_HANDLE** handlePtr, JPEG_CODEC_TYPE_ENUM jpegCodecType);
MAV_DEC_STATUS
mavDecReleaseHandle(MAV_DECODER_HANDLE** handle);
MAV_DEC_STATUS
mavDecQuerySrcFileBuf(
   MAV_DECODER_HANDLE* handle, 
   kal_uint32 *readBufferSizeBest,
   kal_uint32 *readBufferSizeMinimum,
   kal_uint32 *fsalCacheSizeBest, 
   kal_uint32 *fsalCacheSizeMinimum);
MAV_DEC_STATUS
mavDecSetSrcFile(
   MAV_DECODER_HANDLE* handle, 
   STFSAL *fp, 
   kal_uint8 *fsalCacheAddr,
   kal_uint32 fsalCacheSize,
   kal_uint8 *fsalReadBufferAddr, 
   kal_uint32 fsalReadBufferSize);

MAV_DEC_STATUS
mavDecSetSrcFile(
   MAV_DECODER_HANDLE* handle, 
   STFSAL *fp, 
   kal_uint8 *fsalCacheAddr,
   kal_uint32 fsalCacheSize,
   kal_uint8 *fsalReadBufferAddr, 
   kal_uint32 fsalReadBufferSize);

MAV_DEC_STATUS
mavDecQuerySrcImageResolution(
   MAV_DECODER_HANDLE* handle,
   kal_uint32 *width,
   kal_uint32 *height);


MAV_DEC_STATUS
mavDecQueryWorkingMemory(
   MAV_DECODER_HANDLE* handle,       
   kal_uint32 *intMemorySizeBest,   
   kal_uint32 *intMemorySizeMinimum,
   kal_uint32 *extMemorySizeBest,   
   kal_uint32 *extMemorySizeMinimum);


MAV_DEC_STATUS
mavDecSetWorkingMemory(
   MAV_DECODER_HANDLE* handle,       
   kal_uint32 *intMemoryAddr,   
   kal_uint32  intMemorySize,
   kal_uint32 *extMemoryAddr,   
   kal_uint32  extMemorySize);

MAV_DEC_STATUS
mavDecSetRGBCanvas(
   MAV_DECODER_HANDLE* handle,       
   void *buffer, 
   kal_uint32 width, 
   kal_uint32 height, 
   JPEG_RGB_FORMAT_ENUM format);

MAV_DEC_STATUS
mavDecSetYUVCanvas(
   MAV_DECODER_HANDLE* handle,       
   void  *buffer0,
   void  *buffer1,
   void  *buffer2,
   kal_uint32   width,
   kal_uint32   height,
   JPEG_YUV_FORMAT_ENUM   format);


MAV_DEC_STATUS
mavDecSetOutputWindow(
   MAV_DECODER_HANDLE* handle, 
   kal_int32 x, 
   kal_int32 y, 
   kal_uint32 w, 
   kal_uint32 h );

MAV_DEC_STATUS
mavDecSetClipWindow(
   MAV_DECODER_HANDLE* handle, 
   kal_int32 x, 
   kal_int32 y, 
   kal_uint32 w, 
   kal_uint32 h );


MAV_DEC_STATUS
mavDecSetCallbackFunction(
   MAV_DECODER_HANDLE* handle, 
   kal_int32 (*callback_function)(JPEG_CODEC_STATE_ENUM state));


MAV_DEC_STATUS
mavDecSetCheckAbortFunction(
   MAV_DECODER_HANDLE* handle, 
   kal_int32 (*check_abort_func)(void));


MAV_DEC_STATUS
mavDecSetDecodeMode(
   MAV_DECODER_HANDLE* handle, 
   JPEG_DECODE_MODE_ENUM mode);


MAV_DEC_STATUS
mavDecGetLastError(
   MAV_DECODER_HANDLE* handle);


MAV_DEC_STATUS
mavDecQueryFrameCount(
   MAV_DECODER_HANDLE* handle,
   kal_uint32 *frame_count);


MAV_DEC_STATUS
mavDecStart(
   MAV_DECODER_HANDLE* handle,
   unsigned int frameIdx );

MAV_DEC_STATUS
mavDecReset(MAV_DECODER_HANDLE* handle);

MAV_DEC_STATUS
mavDecQueryIsMAV(
   MAV_DECODER_HANDLE* handle,
   kal_bool* yOrn);

#endif //__MAV_DECODER_H__
