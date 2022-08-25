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
 *   ivlw_decoder.h
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __IVLW_DECODER_H__
#define __IVLW_DECODER_H__


#include "ivlw_common.h"
#include "fsal.h"
#include "fs_gprot.h"

typedef enum
{
   IVLW_DEC_STATUS_OK,
   IVLW_DEC_STATUS_HANDLE_UNAVAILABLE,
   IVLW_DEC_STATUS_MEM_UNAVAILABLE,
   IVLW_DEC_STATUS_INVALID_FILE,
   IVLW_DEC_STATUS_INVALID_PARA,
   IVLW_DEC_STATUS_FS_FAIL,
   IVLW_DEC_STATUS_FS_ASYNC_NOT_SUPPORT,
   IVLW_DEC_STATUS_FAIL,
   IVLW_DEC_STATUS_INVALID_CALL_SEQENCE,
   IVLW_DEC_STATUS_ASYNC_RD_CMD_UNAVAILABLE,
   IVLW_DEC_STATUS_ABORT_FAIL,
   IVLW_DEC_STATUS_ABORTED_SRC_CONTENT,

   IVLW_DEC_STATUS_RSVD
}IVLW_DEC_STATUS;


typedef struct _IVLW_DEC_CTRL_BLOCK_S IVLW_DECODER_HANDLE;
typedef IVLW_DEC_STATUS (*_ivlwDecodeCodec)(
   IVLW_DECODER_HANDLE *handle,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned char* dstBuf,
   unsigned int dst_buf_size);


typedef void (*ivlw_async_get_frame_callback)(IVLW_DEC_STATUS error_code, void *callback_para);
typedef struct
{
   void* /*IVLW_DECODER_HANDLE **/ ivlw_handle;
   kal_int32 fsal_job_id;

   unsigned int frame_index;
   IVLW_BOOL occupied;
#if defined(__MTK_TARGET__) && defined(__FS_ASYNC_SUPPORT__)
   volatile kal_eventgrpid event;
#endif 

   unsigned char* read_buf;
   ivlw_async_get_frame_callback callback; //async_get_frame_callback

   void *para; //async_get_frame_callback_para

   IVLW_DEC_STATUS status; //async_get_frame_status

   fs_overlapped_struct file_overlapped;

}IVLW_ASYNC_FS_CTRL_BLOCK;



#define IVLW_ASYNC_CMD_MAX_CNT 2
struct _IVLW_DEC_CTRL_BLOCK_S
{
   STFSAL *fsal_handle;     ///< fsal handle
   unsigned int file_size;
   
   IVLW_BOOL f_to_be_released;
   IVLW_BOOL aborting;

   IVLW_BOOL fix_header_parsed;
   IVLW_BOOL partition_header_parsed;
   IVLW_BOOL frame_header_parsed;
   IVLW_Header_Struct ivlw_header;
   IVLW_COLOR_FORMAT output_format;

   kal_int32 job_id;

//private data:
   alloc_func _alloc_func;
   free_func  _free_func;
   IVLW_BOOL aysnc_fs_ctrl_init;

   unsigned int current_dec_frame_index;
   unsigned int encrypt_key;
#if defined(__MTK_TARGET__)
   IVLW_ASYNC_FS_CTRL_BLOCK  aysnc_fs_ctrl[IVLW_ASYNC_CMD_MAX_CNT];
   //IVLW_BOOL aysnc_fs_ctrl_occupied[IVLW_ASYNC_CMD_MAX_CNT];
   FS_FileLocationHint* pt_fsal_seek_hint;
   unsigned int fsal_seek_hint_buf_size;
#endif
   unsigned int src_buf_prepattern_size;

// for debug
   unsigned char* current_src_buf;

// Temp workaround
   _ivlwDecodeCodec decode_codec;

};
//IVLW_DEC_CTRL_BLOCK

IVLW_DEC_STATUS
ivlwDecGetHandle(IVLW_DECODER_HANDLE** handlePtr);

IVLW_DEC_STATUS
ivlwDecReleaseHandle(IVLW_DECODER_HANDLE** handle);

IVLW_DEC_STATUS
ivlwDecSetSrcFile(IVLW_DECODER_HANDLE* handle, STFSAL *fp);

IVLW_DEC_STATUS
ivlwDecSetAllocAndFree(
   IVLW_DECODER_HANDLE* handle,
   alloc_func alloc_func,
   free_func free_func);

IVLW_DEC_STATUS
ivlwDecQuerySrcResolution(
   IVLW_DECODER_HANDLE* handle,
   unsigned int* width,
   unsigned int* height);

//IVLW_DEC_STATUS
//ivlwDecQuerySrcFormat(
//   IVLW_DECODER_HANDLE* handle,
//   IVLW_COLOR_FORMAT *colorFormat);


IVLW_DEC_STATUS
ivlwDecSetDstFormat(
   IVLW_DECODER_HANDLE* handle,
   IVLW_COLOR_FORMAT colorFormat);


IVLW_DEC_STATUS
ivlwDecQueryFrameCount(
   IVLW_DECODER_HANDLE* handle,
   unsigned int *frameCnt);


IVLW_DEC_STATUS
ivlwDecQueryPartitionCount(
   IVLW_DECODER_HANDLE* handle,
   unsigned int *partitionCnt);


IVLW_DEC_STATUS
ivlwDecQueryPartitionInfo(
   IVLW_DECODER_HANDLE* handle,
   unsigned int partitionIdx,
   unsigned int *frame_count,
   unsigned int *frame_start_index);


IVLW_DEC_STATUS
ivlwDecQueryFrameInfo(
   IVLW_DECODER_HANDLE* handle,
   unsigned int frameIdx,
   unsigned int *frame_file_offset,
   unsigned int *frame_file_size);


IVLW_DEC_STATUS
ivlwDecQuerySrcFrameBufSize(
   IVLW_DECODER_HANDLE* handle,
   unsigned int frame_index,
   unsigned int *buf_size);


//IVLW_DEC_STATUS
//ivlwDecQueryDstFrameBufSize(
//   IVLW_DECODER_HANDLE* handle,
//   unsigned int *buf_size);


IVLW_DEC_STATUS
ivlwDecQueryFrameHeaderLength(
   IVLW_DECODER_HANDLE* handle,
   unsigned int *frame_header_len);


IVLW_DEC_STATUS
ivlwDecGetFrameSrcBuf(
   IVLW_DECODER_HANDLE *handle,
   IVLW_FILE_ACCESS_MODE_ENUM read_mode,
   unsigned int frame_index,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned int *actual_rd_size,
   ivlw_async_get_frame_callback  callback, //// AP register callback to LWP for Async File Read. Called when LWP's FS' Async callback is invoked.
   void *param);


IVLW_DEC_STATUS
ivlwDecGetFramePixelData(
   IVLW_DECODER_HANDLE *handle,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned char* dstBuf,
   unsigned int dst_buf_size);


IVLW_DEC_STATUS
ivlwDecQuerySrcFileType(
   IVLW_DECODER_HANDLE* handle,
   IVLW_FILE_TYPE* file_type);

#define IVLW_DEC_MAX_WORKING_MEMORY_SIZE(W,H,BPP,PNum,FNum) (W*H*BPP*2+IVLE_PARTITION_HEADER_SIZE*PNum+FNum*IVLE_FRAME_HEADER_SIZE+FS_ASYNC_WORKING_BUFFER_SIZE+sizeof(IVLW_DECODER_HANDLE))

#define IVLW_RGB565_R_MASK   0xF800    ///< mask for R component in RGB565 packed data
#define IVLW_RGB565_G_MASK   0x07E0    ///< mask for G component in RGB565 packed data
#define IVLW_RGB565_B_MASK   0x001F    ///< mask for B component in RGB565 packed data

/// Convert RGB888 data into RGB565 packed data
#define IVLW_RGB888_TO_RGB565(R, G, B)   ((unsigned short)(((B) & 0xF8)  >> 3) | (((G) & 0xFC) << 3) | (((R) & 0xF8) << 8))

/// Extract the R component from RGB565 data and extend it to 8 bits
#define IVLW_RGB565_TO_RGB888_R(VALUE) ((((VALUE) & IVLW__RGB565_R_MASK) >> 8))

/// Extract the G component from RGB565 data and extend it to 8 bits
#define IVLW_RGB565_TO_RGB888_G(VALUE) ((((VALUE) & IVLW__RGB565_G_MASK) >> 3))

/// Extract the B component from RGB565 data and extend it to 8 bits
#define IVLW_RGB565_TO_RGB888_B(VALUE)   ((((VALUE) & IVLW__RGB565_B_MASK) << 3))


IVLW_DEC_STATUS
ivlwDecSetDecodeFunc(IVLW_DECODER_HANDLE* handle, _ivlwDecodeCodec decode_codec);

#endif //__IVLW_DECODER_H__
