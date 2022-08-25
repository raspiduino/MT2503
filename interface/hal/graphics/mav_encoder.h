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
 *   mav_encoder.h
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
#ifndef __MAV_ENCODER_H__
#define __MAV_ENCODER_H__

#ifdef WIN32
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#endif

#include "fsal.h"

#include "ivlw_encoder.h"

#include "mav_common.h"
#include "mav_mem.h"


#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)

typedef enum
{
   MAV_ENC_STATUS_OK,
   MAV_ENC_STATUS_HANDLE_UNAVAILABLE,
   MAV_ENC_STATUS_MEM_UNAVAILABLE,
   MAV_ENC_STATUS_INVALID_FILE,
   MAV_ENC_STATUS_INVALID_PARA,
   MAV_ENC_STATUS_FS_FAIL,
   MAV_ENC_STATUS_FAIL,
   MAV_ENC_STATUS_GEN_HEADER_FAIL,
   MAV_ENC_STATUS_INVALID_CALL_SEQENCE,
   MAV_ENC_STATUS_WORKING_BUF_NOT_ENOUGH,
   MAV_ENC_STATUS_RSVD
}MAV_ENC_STATUS;

typedef enum
{
   //MAV_ENC_FILE_PNG,   //input png file name//Not support. Caller shall convert PNG to BMP file.
   MAV_ENC_FILE_BMP,   //input bmp file name
   //MAV_ENC_FILE_PBM,
   MAV_ENC_FILE_PPM,  //input ppm src buffer 
   MAV_ENC_FILE_RSVD
}MAV_ENC_FILE_TYPE;


typedef struct
{
   kal_uint32 srcWidth;
   kal_uint32 srcHeight;

   JPEG_ENCODE_SOURCE_ENUM srcMode;
   JPEG_RGB_FORMAT_ENUM srcRGBFormat;
   JPEG_YUV_FORMAT_ENUM srcSamplingFormat;
   JPEG_YUV_FORMAT_ENUM dstSamplingFormat;
   JPEG_FILE_FORMAT_ENUM dstFileFormat;

   unsigned char *working_buf;
   unsigned int working_buf_size;
   unsigned char *src_buf;
   unsigned int src_buf_size;
   unsigned char *dst_buf;
   unsigned int dst_buf_size;

   STFSAL     *src_fsal_handle;       ///< fsal handle
   STFSAL     *dst_fsal_handle;       ///< fsal handle
   MAV_Header_Struct mav_header;

   alloc_func _alloc_func;
   free_func  _free_func;
  
   unsigned int frame_cnt;
   unsigned char *in_buf[MAV_IMAGE_NUM];
   unsigned int in_buf_size[MAV_IMAGE_NUM];

   //JPEG_ENCODER_HANDLE jpeg_wrapper_handle;
   IVLW_ENCODER_HANDLE *ivlw_handle;

}MAV_ENC_WRAPPER;

typedef MAV_ENC_WRAPPER* MAV_ENCODER_HANDLE;


MAV_ENC_STATUS
mavEncWrapperOpen(MAV_ENCODER_HANDLE* handlePtr);

MAV_ENC_STATUS
mavEncWrapperClose(MAV_ENCODER_HANDLE handle);

MAV_ENC_STATUS
mavEncWrapperStart(
   MAV_ENCODER_HANDLE handle,
   MAV_ENC_WRAPPER *wrapperPtr);

MAV_ENC_STATUS
mavEncWrapperGetEncodedData(
    MAV_ENCODER_HANDLE handle, 
    kal_uint8 **encodeBufferAddr, 
    kal_uint32 *encodeBufferSize);

#endif  // __MULTIPLE_ANGLE_VIEW_SUPPORT__

#endif //__MAV_ENCODER_H__

