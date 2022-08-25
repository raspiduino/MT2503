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
 *   ivlw_encoder.h
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __IVLW_ENCODER_H__
#define __IVLW_ENCODER_H__

#ifdef WIN32
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#endif

#include "fsal.h"
#include "ivlw_common.h"

#if defined(IVLW_DECODER_STANDALONE)
#include "iul_ppm_reader.h"
#include "bmp_utility.h"
#else //defined(IVLW_DECODER_STANDALONE)
  #include "jpeg_encode_api.h"
#endif

typedef enum
{
   IVLW_ENC_STATUS_OK,
   IVLW_ENC_STATUS_HANDLE_UNAVAILABLE,
   IVLW_ENC_STATUS_MEM_UNAVAILABLE,
   IVLW_ENC_STATUS_INVALID_FILE,
   IVLW_ENC_STATUS_INVALID_PARA,
   IVLW_ENC_STATUS_FS_FAIL,
   IVLW_ENC_STATUS_FAIL,
   IVLW_ENC_STATUS_GEN_HEADER_FAIL,
   IVLW_ENC_STATUS_INVALID_CALL_SEQENCE,
   IVLW_ENC_STATUS_WORKING_BUF_NOT_ENOUGH,
   IVLW_ENC_STATUS_RSVD
}IVLW_ENC_STATUS;


typedef enum
{
   IVLW_ENC_FILE_BMP,   //input bmp file name
   //IVLW_ENC_FILE_PBM,
   IVLW_ENC_FILE_PPM,  //input ppm src buffer 
   IVLW_ENC_FILE_PNG,   //input png file name//Not support. Caller shall convert PNG to BMP file.
   IVLW_ENC_FILE_RSVD
}IVLW_ENC_FILE_TYPE;



typedef struct
{
    unsigned int width;  /// the width of the source file
    unsigned int height; /// the height of the source file
    unsigned int   bpp;

    unsigned char  *pixel_start_p;         /* pointer to bitmap data */
    unsigned int   pixel_data_size;
    IVLW_COLOR_FORMAT color_format;

}IVLW_PPM_INFO_T;



typedef struct
{
    signed int     bmp_width;                  /* bitmap width */
    signed int     bmp_height;                 /* bitmap height */
    IVLW_COLOR_FORMAT color_format;
    signed int     bmp_bpp;                    /* bitmap bits per pixel */
    signed int     bmp_palette_num;            /* number of colors in the palette */  
    unsigned int   bmp_palette[256];               /* bitmap palette (8-bit bpp max) */    
    unsigned char  *pixel_start_p;         /* pointer to bitmap data */
    unsigned int   line_padding_bytes;         /* line padding bytes */
    signed int     src_key_color_enable;       /* for PBM source key color */
    signed int     is_windows_bmp;             /* windows BMP 32-bit is always XRGB8888, not expected ARGB8888. */

    unsigned int    pixel_data_size;

}IVLW_BMP_INFO_T;


typedef struct
{
   unsigned int fgen_header;
   unsigned char src_filename[IVLW_FILE_NAME_LEN];	   ///< fsal handle

   unsigned char *working_buf;
   unsigned int working_buf_size;

   unsigned char *src_buf;
   unsigned int src_buf_size;
   IVLW_COLOR_FORMAT src_format;
   unsigned char *dst_buf;
   unsigned int dst_buf_size;
   unsigned char *dst_write_ptr;
   unsigned int dst_write_size;

   STFSAL     *src_fsal_handle;       ///< fsal handle
   STFSAL     *dst_fsal_handle;       ///< fsal handle
   IVLW_ENC_FILE_TYPE src_file_type;

   IVLW_Header_Struct ivlw_header;

   IVLW_BMP_INFO_T bmp_info;
   IVLW_PPM_INFO_T ppm_info; 

//private data:
   alloc_func _alloc_func;
   free_func  _free_func;
  
   unsigned int encrypt_key;
   unsigned int current_output_file_offet;

#if !defined(IVLW_DECODER_STANDALONE)
   JPEG_ENCODER_HANDLE jpeg_encoder_handle;
#endif
}IVLW_ENC_CTRL_BLOCK;

typedef IVLW_ENC_CTRL_BLOCK IVLW_ENCODER_HANDLE;



IVLW_ENC_STATUS
ivlwEncGetHandle(IVLW_ENCODER_HANDLE** handlePtr);

IVLW_ENC_STATUS
ivlwEncReleaseHandle(IVLW_ENCODER_HANDLE** handle);

IVLW_ENC_STATUS
ivlwEncSetDstFile(
   IVLW_ENCODER_HANDLE* handle,
   STFSAL *fp);

IVLW_ENC_STATUS
ivlwEncSetSrcFileHandle(
   IVLW_ENCODER_HANDLE* handle,
   STFSAL *fp,
   IVLW_ENC_FILE_TYPE src_file_type);

IVLW_ENC_STATUS
ivlwEncSetDstBuf(
   IVLW_ENCODER_HANDLE* handle,
   unsigned char *dst_buf,
   unsigned int dst_buf_size);

IVLW_ENC_STATUS
ivlwEncGetEncodedData(
   IVLW_ENCODER_HANDLE* handle,
   unsigned char **encoded_buf,
   unsigned int *encoded_buf_size);

IVLW_ENC_STATUS
ivlwEncSetAllocAndFree(
   IVLW_ENCODER_HANDLE* handle,
   alloc_func ilvw_alloc_func,
   free_func ilvw_free_func);

IVLW_ENC_STATUS
ivlwEncSetEncMethod(
   IVLW_ENCODER_HANDLE* handle,
   IVLW_ALGORITHM method);

IVLW_ENC_STATUS
ivlwEncSetDstFormat(
   IVLW_ENCODER_HANDLE* handle,
   IVLW_COLOR_FORMAT dstFormat);

IVLW_ENC_STATUS
ivlwEncSetTotalFrameCount(
   IVLW_ENCODER_HANDLE* handle,
   unsigned int frameCnt);

IVLW_ENC_STATUS
ivlwEncSetTotalPartitionCount(
   IVLW_ENCODER_HANDLE* handle,
   unsigned int partition_count);

//total frame count in this partition
IVLW_ENC_STATUS
ivlwEncSetPartitionInfo(
   IVLW_ENCODER_HANDLE* handle,
   unsigned int partition_index,
   unsigned int partition_frame_count, 
   unsigned int start_frame_inx);


IVLW_ENC_STATUS
ivlwEncFrame(
   IVLW_ENCODER_HANDLE* handle,
   unsigned int frame_index,
   unsigned char *frame_buffer, //dst buf
   unsigned int frame_buf_size,
   unsigned int align_num );  //align_num shall less than 64


IVLW_ENC_STATUS
ivlwEncQueryWorkingBufSize(
   IVLW_ENCODER_HANDLE* handle,
   IVLW_ENC_FILE_TYPE src_file_type,
   unsigned int *working_buf_size);


IVLW_ENC_STATUS
ivlwEncSetWorkingBuf(
   IVLW_ENCODER_HANDLE* handle,
   unsigned char *working_buf,
   unsigned int working_buf_size);



IVLW_ENC_STATUS
ivlwEncSetSrcFile(
   IVLW_ENCODER_HANDLE* handle,
   unsigned char *src_filename,
   IVLW_ENC_FILE_TYPE src_file_type);



IVLW_ENC_STATUS
ivlwEncSetBMPInfo(
   IVLW_ENCODER_HANDLE* handle,
   IVLW_BMP_INFO_T* bmp_info);


IVLW_ENC_STATUS
ivlwEncSetPPMInfo(
   IVLW_ENCODER_HANDLE* handle,
   IVLW_PPM_INFO_T* ppm_info);


IVLW_ENC_STATUS
ivlwEncSetSrcBuf(
   IVLW_ENCODER_HANDLE* handle,
   IVLW_COLOR_FORMAT src_format,
   unsigned char* src_buf,
   unsigned int src_buf_sz);

#endif //__IVLW_ENCODER_H__
