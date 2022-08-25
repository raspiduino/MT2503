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
 *   ivlw_encoder.c
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
#include "ivlw_common.h"
#include "ivlw_encoder.h"
#if !defined(IVLW_DECODER_STANDALONE)

#include "iul_color_convert.h"
#include "iul_csc_macros.h"

#include "jpeg_enum.h"
#include "jpeg_encode_api.h"
#include "jpeg_encode_wrapper.h"
#include "gdi_image_alpha_bmp_v2.h"
#endif

#if defined(IVLW_DECODER_STANDALONE)
   #include "base.h"
   #include "bmp_utility.h"
   #include "iul_color_convert.h"
   #include "ABMLoader.h"

   #include "iul_ppm_writer.h"
   #include "iul_ppm_reader.h"

   #include <sys/stat.h>
   #include <string.h>
   #include <stdio.h>
   #include <errno.h>
char Enc_Debug = 0;
unsigned int debug_num = 0;
#endif

//#define IVLW_MAX_FRAME_COUNT 1024
static unsigned char abm_data[4 * IVLW_MAX_FRAME_COUNT * IVLW_MAX_FRAME_COUNT];  // 4 MB storage
#define IVLW_GET_0_FRAME_HEADER_FILE_OFFSET(h, offset)                                             \
do{                                                                                                \
   offset = V0_IVLW_HEADER_PARTITION_PART_OFFSET + (h)->ivlw_header.total_partition_header_size;   \
   if (1 == (h)->ivlw_header.fixed_header.verion)                                                  \
      offset = V1_IVLW_HEADER_PARTITION_PART_OFFSET + (h)->ivlw_header.total_partition_header_size;\
}while(0);

#define IVLW_GET_n_FRAME_HEADER_FILE_OFFSET(h, n, offset) 	\
{                                                         	\
   IVLW_GET_0_FRAME_HEADER_FILE_OFFSET(h, offset);        	\
   offset += n * IVLE_FRAME_HEADER_SIZE;                  	\
}

#define IVLW_SET_CTRLBLOCK_FILE_OFFSET_TO_PIXEL_DATA_START_POINT(h)      		\
do {                                                                     		\
  h->current_output_file_offet = h->ivlw_header.total_partition_header_size + h->ivlw_header.total_frame_header_size;\
  if (0 == (h)->ivlw_header.fixed_header.verion)                         		\
  {																																					\
     h->current_output_file_offet += V0_IVLW_HEADER_PARTITION_PART_OFFSET;	\
  }																																					\
  else if (1 == (h)->ivlw_header.fixed_header.verion)                    		\
  {																																					\
    h->current_output_file_offet += V1_IVLW_HEADER_PARTITION_PART_OFFSET;		\
  }																																					\
  else                                                                   		\
  {																																					\
    ASSERT(0);                                                           		\
  }																																					\
}while(0);

#define IVLW_UPDATE_CTRLBLOCK_FILE_OFFSET_BY_ADD(h, n)\
{																											\
  h->current_output_file_offet += n;									\
}

#define IVLW_SET_CTRLBLOCK_FILE_OFFSET(h, n)					\
{																											\
  h->current_output_file_offet = n;										\
}

#define IVLW_SET_DST_OFFSET(h, offset)								\
{																											\
  h->dst_write_ptr = h->dst_buf + offset;							\
}

#define IVLW_SET_DST_WRITE(h, buf, size)							\
{																											\
  memcpy(h->dst_write_ptr, buf, size);								\
  h->dst_write_ptr = h->dst_write_ptr + size;					\
  h->dst_write_size = h->dst_write_size + size;				\
}

extern int rand(void);
static void *_ivlwEncDefaultMalloc(void *opaque, unsigned int items, unsigned int size)
{
   unsigned int total_bytes;
   void *buffer_ptr;

   if (opaque)
   {
      items += size - size;   /// make compiler happy
   }
   total_bytes = items * size;
   buffer_ptr = get_ctrl_buffer(total_bytes);
   return buffer_ptr;
}



static void _ivlwEncDefaultFree(void *opaque, void *address)
{
   free_ctrl_buffer(address);
   return;
}



IVLW_ENC_STATUS
ivlwEncGetHandle(IVLW_ENCODER_HANDLE** handlePtr)
{
   IVLW_ENCODER_HANDLE *h = NULL;
   IVLW_ENC_STATUS rtn;

   h = (IVLW_ENCODER_HANDLE*) get_ctrl_buffer(sizeof(IVLW_ENCODER_HANDLE));
   if (h)
   {
      memset(h, 0, sizeof(IVLW_ENCODER_HANDLE));
      rtn = IVLW_ENC_STATUS_OK;
      *handlePtr = h;
   }
   else
   {
      *handlePtr = NULL;
      rtn = IVLW_ENC_STATUS_HANDLE_UNAVAILABLE;
   }

   (*handlePtr)->ivlw_header.fixed_header.compress_algorithm = IVLW_ALG_AB2;
   return rtn;
}



IVLW_ENC_STATUS
ivlwEncReleaseHandle(IVLW_ENCODER_HANDLE** handle)
{
   if (NULL == (*handle)->_free_func)
   {
      ASSERT(0);
   }

   if ((*handle)->ivlw_header.frame_header)
   {
      (*handle)->_free_func(NULL, (*handle)->ivlw_header.frame_header);
      (*handle)->ivlw_header.frame_header = NULL;
      (*handle)->ivlw_header.total_frame_header_size = 0;
   }

   if ((*handle)->ivlw_header.partition_header)
   {
      (*handle)->_free_func(NULL, (*handle)->ivlw_header.partition_header);
      (*handle)->ivlw_header.partition_header = NULL;
      (*handle)->ivlw_header.total_partition_header_size = 0;
   }

   if (*handle)
   {
      free_ctrl_buffer((void*)*handle);
      *handle = NULL;
   }
   return IVLW_ENC_STATUS_OK;
}



IVLW_ENC_STATUS
ivlwEncSetDstFile(
   IVLW_ENCODER_HANDLE* handle,
   STFSAL *fp)
{
   if ((NULL == handle) || (NULL == fp))
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }

   handle->dst_fsal_handle = fp;
   handle->encrypt_key = 0;
   return IVLW_ENC_STATUS_OK;
}



IVLW_ENC_STATUS
ivlwEncSetDstBuf(
   IVLW_ENCODER_HANDLE* handle,
   unsigned char *dst_buf,
   unsigned int dst_buf_size)
{
   if ((NULL == handle) || (NULL == dst_buf) || (0 == dst_buf_size))
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }

   handle->dst_buf = dst_buf;
   handle->dst_buf_size = dst_buf_size;
   return IVLW_ENC_STATUS_OK;
}



IVLW_ENC_STATUS
ivlwEncGetEncodedData(
   IVLW_ENCODER_HANDLE* handle,
   unsigned char **encoded_buf,
   unsigned int *encoded_buf_size)
{
   if ((NULL == handle) || (NULL == encoded_buf) || (NULL == encoded_buf_size))
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }

   *encoded_buf = handle->dst_buf;
   *encoded_buf_size = handle->dst_write_size;
   return IVLW_ENC_STATUS_OK;
}


IVLW_ENC_STATUS
ivlwEncSetAllocAndFree(
   IVLW_ENCODER_HANDLE* handle,
   alloc_func ilvw_alloc_func,
   free_func ilvw_free_func)
{
   if (NULL == handle)
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }

   handle->_alloc_func = ilvw_alloc_func;
   handle->_free_func = ilvw_free_func;
   return IVLW_ENC_STATUS_OK;
}



IVLW_ENC_STATUS
ivlwEncSetEncMethod(
   IVLW_ENCODER_HANDLE* handle,
   IVLW_ALGORITHM method)
{
   if ((NULL == handle) || (IVLW_ALG_RSVD <= method))
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }
   handle->ivlw_header.fixed_header.compress_algorithm = method;
   return IVLW_ENC_STATUS_OK;
}


//Used for IVLW Encoder
IVLW_ENC_STATUS
ivlwEncSetSrcFile(
   IVLW_ENCODER_HANDLE* handle,
   unsigned char *src_filename,
   IVLW_ENC_FILE_TYPE src_file_type)
{
   if ((NULL == handle) || (NULL == src_filename)||
       (IVLW_FILE_NAME_LEN <= strlen((const char *)src_filename))||
       (IVLW_ENC_FILE_RSVD <= src_file_type))
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }

   strcpy((char *)handle->src_filename, (const char *)src_filename);
   handle->src_file_type = src_file_type;
   return IVLW_ENC_STATUS_OK;
}


//Used for MAV Encoder
IVLW_ENC_STATUS
ivlwEncSetSrcFileHandle(
   IVLW_ENCODER_HANDLE* handle,
   STFSAL *fp,
   IVLW_ENC_FILE_TYPE src_file_type)
{
   if ((NULL == fp)||
       (IVLW_ENC_FILE_RSVD <= src_file_type))
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }
   handle->src_fsal_handle = fp;
   handle->src_file_type = src_file_type;
   return IVLW_ENC_STATUS_OK;
}



IVLW_ENC_STATUS
ivlwEncSetDstFormat(
   IVLW_ENCODER_HANDLE* handle,
   IVLW_COLOR_FORMAT dstFormat)
{
   if ((NULL == handle) ||
       (dstFormat >= IVLW_COLOR_RSVD))
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }
   handle->ivlw_header.fixed_header.img_format = dstFormat;
   return IVLW_ENC_STATUS_OK;
}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(IVLW_DECODER_STANDALONE)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //No used currently.



IVLW_ENC_STATUS
ivlwEncSetTotalFrameCount(
   IVLW_ENCODER_HANDLE* handle,
   unsigned int frameCnt)
{
   if (NULL == handle)
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }

   if ((NULL == handle->_free_func) || (NULL == handle->_alloc_func))
   {
      handle->_alloc_func = _ivlwEncDefaultMalloc;
      handle->_free_func = _ivlwEncDefaultFree;
   }

   handle->ivlw_header.fixed_header.total_frame_count = frameCnt;
   handle->ivlw_header.total_frame_header_size = sizeof(IVLW_Frame_Header_Struct) * frameCnt;
   handle->ivlw_header.frame_header = handle->_alloc_func(NULL, 1, handle->ivlw_header.total_frame_header_size);
   if (NULL == handle->ivlw_header.frame_header)
   {
      return IVLW_ENC_STATUS_MEM_UNAVAILABLE;
   }
   return IVLW_ENC_STATUS_OK;
}



IVLW_ENC_STATUS
ivlwEncSetTotalPartitionCount(
   IVLW_ENCODER_HANDLE* handle,
   unsigned int partition_count)
{
   if ((NULL == handle) || (0 == partition_count))
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }

   if ((NULL == handle->_free_func) || (NULL == handle->_alloc_func))
   {
      handle->_alloc_func = _ivlwEncDefaultMalloc;
      handle->_free_func = _ivlwEncDefaultFree;
   }

   handle->ivlw_header.fixed_header.total_partition_count = partition_count;
   handle->ivlw_header.total_partition_header_size = sizeof(IVLW_Partition_Header_Struct) * partition_count;
   handle->ivlw_header.partition_header = handle->_alloc_func(NULL, 1, handle->ivlw_header.total_partition_header_size);
   if (NULL == handle->ivlw_header.partition_header)
   {
      return IVLW_ENC_STATUS_MEM_UNAVAILABLE;
   }
   return IVLW_ENC_STATUS_OK;
}



IVLW_ENC_STATUS
ivlwEncSetPartitionInfo(
   IVLW_ENCODER_HANDLE* handle,
   unsigned int partition_index,
   unsigned int partition_frame_count, //total frame count in this partition
   unsigned int start_frame_inx)
{
   IVLW_Partition_Header_Struct *partition_header;

   if ((NULL == handle) ||
       (0 == partition_frame_count) ||
       (IVLW_MAX_FRAME_COUNT < partition_frame_count) ||
       (IVLW_MAX_FRAME_COUNT < start_frame_inx))
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }

   if (NULL == handle->ivlw_header.partition_header)
   {
      return IVLW_ENC_STATUS_INVALID_CALL_SEQENCE;
   }

   partition_header = &handle->ivlw_header.partition_header[partition_index];
   partition_header->p_frame_count = partition_frame_count;
   partition_header->start_frame_index = start_frame_inx;
   return IVLW_ENC_STATUS_OK;
}


IVLW_ENC_STATUS _ivlwEncGenEncryptKey(IVLW_ENCODER_HANDLE* handle)
{
   unsigned int dummy = 0;

   while (0 == dummy)
   {
      dummy = (unsigned int) rand();//drv_get_current_time();
   }

   while (0 == handle->encrypt_key)
   {
      handle->encrypt_key = (unsigned int) rand();//drv_get_current_time();
   }
  return IVLW_ENC_STATUS_OK;
}


IVLW_ENC_STATUS _ivlwEncOutputEncryptKey(IVLW_ENCODER_HANDLE* handle)
{
   FSAL_Status fs_status;

   //Fill Encrypt Key value int the file end.
   if (0 == IVLW_ENCODER_VERSION_NUM)
   {
      unsigned int cur_pos = 0;
      while (0 == handle->encrypt_key)
      {
         handle->encrypt_key = (unsigned int) rand();//drv_get_current_time();
      }

      if (handle->dst_fsal_handle)
      {
         fs_status = FSAL_Write(handle->dst_fsal_handle, (unsigned char*)&handle->encrypt_key, 4);
         if (FSAL_OK != fs_status)
         {
            return IVLW_ENC_STATUS_FS_FAIL;
         }
      }
      else
      {
         IVLW_SET_DST_WRITE(handle, (unsigned char*)&handle->encrypt_key, 4);
      }
   }
   else if (1 == IVLW_ENCODER_VERSION_NUM)
   {
      unsigned int cur_pos = 0;
      unsigned int dummy = 0;

      while (0 == dummy)
      {
         dummy = (unsigned int) rand();//drv_get_current_time();
      }

      if (handle->dst_fsal_handle)
      {
         fs_status = FSAL_Write(handle->dst_fsal_handle, (unsigned char*)&handle->encrypt_key, 4);
         if (FSAL_OK != fs_status)
         {
            return IVLW_ENC_STATUS_FS_FAIL;
         }
         fs_status = FSAL_Write(handle->dst_fsal_handle, (unsigned char*)&dummy, 4);
         if (FSAL_OK != fs_status)
         {
            return IVLW_ENC_STATUS_FS_FAIL;
         }
      }
      else
      {
         IVLW_SET_DST_WRITE(handle, (unsigned char*)&handle->encrypt_key, 4);
         IVLW_SET_DST_WRITE(handle, (unsigned char*)&dummy, 4);
      }
   }
   else
   {
      ASSERT(0);
   }
   return IVLW_ENC_STATUS_OK;
}



IVLW_ENC_STATUS
_ivlwEncEncryptBuf(
   unsigned int *key,
   unsigned char *frame_buffer,
   unsigned int frame_buf_size )
{
#if defined (IVLW_ENCRYPT_HEADER)

   unsigned int i, *ptr;
   if (frame_buf_size & 3)
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }

   while (0 == *key)
   {
      *key = (unsigned int) rand();//drv_get_current_time();
   }

   frame_buf_size = frame_buf_size >> 2;
   ptr = (unsigned int*) frame_buffer;
   for (i = 0; i < frame_buf_size; i++)
   {
      *ptr++ = (IVLW_SWAP_4_1203((*ptr))) ^ (*key);
   }
#else
   if (0 == *key)
   {
      *key = 0xca5eca5e;
   }
#endif
   return IVLW_ENC_STATUS_OK;
}



static IVLW_ENC_STATUS
_ivlwOutputFixedHeader(
   IVLW_ENCODER_HANDLE* handle)
{
   FSAL_Status fs_status;
   IVLW_ENC_STATUS status;
   unsigned char temp[IVLW_HEADER_FIXED_PART_LEN];
   unsigned int offset = 0;
   memcpy(temp, (unsigned char*)&handle->ivlw_header.fixed_header, IVLW_HEADER_FIXED_PART_LEN);
   status = _ivlwEncEncryptBuf(&handle->encrypt_key, temp, IVLW_HEADER_FIXED_PART_LEN);
   if (IVLW_ENC_STATUS_OK != status)
   {
      return status;
   }

   offset = V0_IVLW_HEADER_FIXED_PART_OFFSET;
   if (1 == IVLW_ENCODER_VERSION_NUM)
   {
      offset = V1_IVLW_HEADER_FIXED_PART_OFFSET;
   }

   if (handle->dst_fsal_handle)
   {
      fs_status = FSAL_Seek(handle->dst_fsal_handle, offset);
      fs_status = FSAL_Write(handle->dst_fsal_handle, temp, IVLW_HEADER_FIXED_PART_LEN);
      if (FSAL_OK != fs_status)
      {
         return IVLW_ENC_STATUS_FS_FAIL;
      }
   }
   else
   {
      IVLW_SET_DST_WRITE(handle, temp, IVLW_HEADER_FIXED_PART_LEN);
   }
   return IVLW_ENC_STATUS_OK;
}



static IVLW_ENC_STATUS
_ivlwOutputAllPartitionHeader(
   IVLW_ENCODER_HANDLE* handle)
{
   FSAL_Status fs_status;
   IVLW_ENC_STATUS status = IVLW_ENC_STATUS_OK;
   unsigned size, offset;
   unsigned char *temp;

   size = handle->ivlw_header.total_partition_header_size;
   if (0 == size)
   {
      return IVLW_ENC_STATUS_FAIL;
   }

   temp = (unsigned char*)get_ctrl_buffer(size);
   if (NULL == temp)
   {
      return IVLW_ENC_STATUS_MEM_UNAVAILABLE;
   }

   memcpy(temp, (unsigned char*)handle->ivlw_header.partition_header, size);
   status = _ivlwEncEncryptBuf(&handle->encrypt_key, temp, size);
   if (IVLW_ENC_STATUS_OK != status)
   {
      goto _partitionHeader_return;
   }

   offset = V0_IVLW_HEADER_PARTITION_PART_OFFSET;
   if (1 == handle->ivlw_header.fixed_header.verion)
   {
    offset = V1_IVLW_HEADER_PARTITION_PART_OFFSET;
   }

   if (handle->dst_fsal_handle)
   {
      fs_status = FSAL_Seek(handle->dst_fsal_handle, offset);
      fs_status = FSAL_Write(handle->dst_fsal_handle, temp, size);
      if (FSAL_OK != fs_status)
      {
         status = IVLW_ENC_STATUS_FS_FAIL;
      }
   }
   else
   {
      IVLW_SET_DST_WRITE(handle, temp, size);
   }

_partitionHeader_return:
   free_ctrl_buffer(temp);
   return status;
}



//This function is used to fill ivlw frame header data structure, not output to the dest file.
//For output to the dest file, call this function _ivlwOutputAllFrameHeader
static IVLW_ENC_STATUS
_ivlwFillFrameHeader(
   IVLW_ENCODER_HANDLE* handle,
   unsigned int frame_index,
   unsigned int compressed_data_size,
   unsigned int pading_count)
{
   IVLW_Frame_Header_Struct *frame_header = &handle->ivlw_header.frame_header[frame_index];
   frame_header->compressed_data_size = compressed_data_size;
   frame_header->frame_offset = handle->current_output_file_offet;
   frame_header->pading_count = pading_count;
   return IVLW_ENC_STATUS_OK;
}


/*
static IVLW_ENC_STATUS
_ivlwOutputFrameHeader(
   IVLW_ENCODER_HANDLE* handle,
   unsigned int frame_index)
{
   FSAL_Status fs_status;
   fs_status = FSAL_Seek(handle->fsal_handle, IVLW_GET_n_FRAME_HEADER_FILE_OFFSET(handle, frame_index));
   fs_status = FSAL_Write(handle->dst_fsal_handle,
                          (unsigned char*)(&(handle->ivlw_header.frame_header[frame_index])),
                          IVLE_FRAME_HEADER_SIZE);
   if (FSAL_OK != fs_status)
   {
      return IVLW_ENC_STATUS_FS_FAIL;
   }
   return IVLW_ENC_STATUS_OK;
}*/



static IVLW_ENC_STATUS
_ivlwOutputAllFrameHeader(
   IVLW_ENCODER_HANDLE* handle)
{
   unsigned int offset;
   FSAL_Status fs_status;
   IVLW_ENC_STATUS status = IVLW_ENC_STATUS_OK;
   unsigned size = handle->ivlw_header.total_frame_header_size;
   unsigned char *temp = (unsigned char *) get_ctrl_buffer(size);

   if (NULL == temp)
   {
      return IVLW_ENC_STATUS_MEM_UNAVAILABLE;
   }
   memcpy(temp, (unsigned char*)handle->ivlw_header.frame_header, size);
   status = _ivlwEncEncryptBuf(&handle->encrypt_key, temp, size);
   if (IVLW_ENC_STATUS_OK != status)
   {
      goto _frameHeader_return;
   }

   IVLW_GET_n_FRAME_HEADER_FILE_OFFSET(handle, 0, offset);
   if (handle->dst_fsal_handle)
   {
      fs_status = FSAL_Seek(handle->dst_fsal_handle, offset);
      fs_status = FSAL_Write(handle->dst_fsal_handle, temp, size);
      if (FSAL_OK != fs_status)
      {
         status = IVLW_ENC_STATUS_FS_FAIL;
      }
   }
   else
   {
      IVLW_SET_DST_OFFSET(handle, offset);
      IVLW_SET_DST_WRITE(handle, temp, size);
   }

_frameHeader_return:
  free_ctrl_buffer(temp);
  return status;
}



IVLW_ENC_STATUS
ivlwEncSetSrcBuf(
   IVLW_ENCODER_HANDLE* handle,
   IVLW_COLOR_FORMAT src_format,
   unsigned char* src_buf,
   unsigned int src_buf_sz)
{
   if ((NULL == handle) || (NULL == src_buf) ||(0 == src_buf_sz) || (IVLW_COLOR_RSVD <= src_format))
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }
   handle->src_buf = src_buf;
   handle->src_buf_size = src_buf_sz;
   handle->src_format = src_format;
   return IVLW_ENC_STATUS_OK;
}



IVLW_ENC_STATUS
ivlwEncSetBMPInfo(
   IVLW_ENCODER_HANDLE* handle,
   IVLW_BMP_INFO_T* bmp_info)
{
   if ((NULL == handle) || (NULL == bmp_info))
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }
   handle->src_file_type = IVLW_ENC_FILE_BMP;
   memcpy(&handle->bmp_info, bmp_info, sizeof(IVLW_BMP_INFO_T));
   return IVLW_ENC_STATUS_OK;
}



IVLW_ENC_STATUS
ivlwEncSetPPMInfo(
   IVLW_ENCODER_HANDLE* handle,
   IVLW_PPM_INFO_T* ppm_info)
{
   if ((NULL == handle) || (NULL == ppm_info))
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }
   handle->src_file_type = IVLW_ENC_FILE_PPM;
   memcpy(&handle->ppm_info, ppm_info, sizeof(IVLW_PPM_INFO_T));
   return IVLW_ENC_STATUS_OK;
}


static IVLW_ENC_STATUS
_ivlw_rb_channel_swap(
   unsigned int width,
   unsigned int height,
   unsigned char *src_buffer, //dst buf
   unsigned int src_data_size,
   IVLW_COLOR_FORMAT src_format,
   unsigned char *dst_buffer, //dst buf
   unsigned int   dst_buf_size)
{
   //Swap left&right, up&down due to bmp file.
   unsigned int i;
   unsigned char* src_temp_ptr;

   //SWAP R&B channel to meet MAUI's color format type.
   if (IVLW_COLOR_RGB888 == src_format)
   {
      {
         unsigned char *dst_ptr = (unsigned char*) dst_buffer;
         src_temp_ptr = src_buffer;
         for (i = 0; i < width * height; i++)
         {
            *dst_ptr       = *(src_temp_ptr + 2); //R
            *(dst_ptr + 2) = *(src_temp_ptr    ); //B
            *(dst_ptr + 1) = *(src_temp_ptr + 1); //G
            src_temp_ptr += 3;
            dst_ptr += 3;
         }
      }
   }
   else if (IVLW_COLOR_RGB565 == src_format)
   {
      {
         unsigned char r, b;
         unsigned short *dst_ptr16 = (unsigned short *)dst_buffer;
         unsigned short *src_ptr16 = (unsigned short *)src_buffer;

         for (i = 0; i < width * height; i++)
         {
            b = (*src_ptr16) & 0x1F;
            r = ((*src_ptr16)>>11) & 0x1F;
            (*dst_ptr16) = (b << 11) | (*src_ptr16) & 0x7E | (r);
            dst_ptr16++;
            src_ptr16++;
         }
      }
   }
   else
   {

   }

   return IVLW_ENC_STATUS_OK;
}



static IVLW_ENC_STATUS
_ivlw_color_conver_swap(
   unsigned int width,
   unsigned int height,
   unsigned char *src_buffer, //dst buf
   unsigned int src_data_size,
   IVLW_COLOR_FORMAT src_format,
   unsigned char *dst_buffer, //dst buf
   unsigned int   dst_buf_size,
   IVLW_COLOR_FORMAT dst_format,
   signed int  *dst_data_size)
{
   //Swap left&right, up&down due to bmp file.
   unsigned int i, j;
   unsigned char* src_temp_ptr;

   //SWAP R&B channel to meet MAUI's color format type.
   if (IVLW_COLOR_RGB888 == src_format)
   {
      if (IVLW_COLOR_RGB565 == dst_format)
      {
         unsigned char R,G,B;
         unsigned short *rgb565buf = (unsigned short*) dst_buffer;
         src_temp_ptr = src_buffer;
         for (i = 0; i < height ; i++)
         {
            for (j = 0; j < width; j++)
            {
               R = *src_temp_ptr++;
               G = *src_temp_ptr++;
               B = *src_temp_ptr++;
               *rgb565buf++ = RGB888_TO_RGB565(B,G,R);
            }
         }
         *dst_data_size = (width) * (height) * 2;
      }
      else if (IVLW_COLOR_RGB888 == dst_format)
      {
         unsigned char *dst_ptr = (unsigned char*) dst_buffer;
         src_temp_ptr = src_buffer;

         for (i = 0; i < width * height; i++)
         {
            *dst_ptr       = *(src_temp_ptr + 2); //R
            *(dst_ptr + 2) = *(src_temp_ptr    ); //B
            *(dst_ptr + 1) = *(src_temp_ptr + 1); //G
            src_temp_ptr += 3;
            dst_ptr += 3;
         }
         *dst_data_size = width * height * 3;
      }
      else if (IVLW_COLOR_YUV == src_format)
      {
         memcpy(dst_buffer, src_buffer, src_data_size);
         *dst_data_size = src_data_size;
      }
      else
      {
        ASSERT(0);;
      }
   }
   else if (IVLW_COLOR_RGB565 == src_format)
   {
      if (IVLW_COLOR_RGB888 == dst_format)
      {
         printf("Not Support Source Image RGB565 to Convert to RGB888 IVLW\n");
         ASSERT(0);
      }
      else if (IVLW_COLOR_RGB565 == dst_format)
      {
         unsigned char r, b;
         unsigned short *dst_ptr16 = (unsigned short *)dst_buffer;
         unsigned short *src_ptr16 = (unsigned short *)src_buffer;

         for (i = 0; i < width * height; i++)
         {
            b = (*src_ptr16) & 0x1F;
            r = ((*src_ptr16)>>11) & 0x1F;
            (*dst_ptr16) = (b << 11) | (*src_ptr16) & 0x7E | (r);
            dst_ptr16++;
            src_ptr16++;
         }
         *dst_data_size = (width) * (height) * 2;
      }
   }
   else if (IVLW_COLOR_YUV == src_format)
   {
      memcpy(dst_buffer, src_buffer, src_data_size);
      *dst_data_size = src_data_size;
   }
   else
   {
      //unsigned char *workbuf = (unsigned char *)get_ctrl_buffer( width * height * 3);
      printf("Not Support Source Image 1 BPP to Convert to RGB888/RGB565 IVLW\n");
      ASSERT(0);
   }
   return IVLW_ENC_STATUS_OK;
}



static IVLW_ENC_STATUS
_ivlw_color_conver(
   unsigned int width,
   unsigned int height,
   unsigned char *src_buffer, //dst buf
   unsigned int src_data_size,
   IVLW_COLOR_FORMAT src_format,
   unsigned char *dst_buffer, //dst buf
   unsigned int   dst_buf_size,
   IVLW_COLOR_FORMAT dst_format,
   signed int  *dst_data_size)
{
   //Swap left&right, up&down due to bmp file.
   unsigned int i, j;
   unsigned char* src_temp_ptr;

   //SWAP R&B channel to meet MAUI's color format type.
   if (IVLW_COLOR_RGB888 == src_format)
   {
      if (IVLW_COLOR_RGB565 == dst_format)
      {
         unsigned char R,G,B;
         unsigned short *rgb565buf = (unsigned short*) dst_buffer;
         src_temp_ptr = src_buffer;
         for (i = 0; i < height ; i++)
         {
            for (j = 0; j < width; j++)
            {
               R = *src_temp_ptr++;
               G = *src_temp_ptr++;
               B = *src_temp_ptr++;
               *rgb565buf++ = RGB888_TO_RGB565(R,G,B);
            }
         }
         *dst_data_size = (width) * (height) * 2;
      }
      else if (IVLW_COLOR_RGB888 == dst_format)
      {
         unsigned char *dst_ptr = (unsigned char*) dst_buffer;
         src_temp_ptr = src_buffer;
         *dst_data_size = src_data_size;
         if (dst_buffer != src_buffer)
         {
            memcpy(dst_buffer, src_buffer, src_data_size);
         }
      }
      else if (IVLW_COLOR_YUV == src_format)
      {
         if (dst_buffer != src_buffer)
         {
            memcpy(dst_buffer, src_buffer, src_data_size);
         }
      }
      else
      {
        ASSERT(0);;
      }
   }
   else if (IVLW_COLOR_RGB565 == src_format)
   {
      if (IVLW_COLOR_RGB888 == dst_format)
      {
         printf("Not Support Source Image RGB565 to Convert to RGB888 IVLW\n");
         ASSERT(0);
      }
      else if (IVLW_COLOR_RGB565 == dst_format)
      {
         unsigned short *dst_ptr16 = (unsigned short *)dst_buffer;
         unsigned short *src_ptr16 = (unsigned short *)src_buffer;
         *dst_data_size = src_data_size;
         if (dst_buffer != src_buffer)
         {
            memcpy(dst_buffer, src_buffer, src_data_size);
         }
      }
   }
   else if (IVLW_COLOR_YUV == src_format)
   {
      memcpy(dst_buffer, src_buffer, src_data_size);
   }
   else
   {
      //unsigned char *workbuf = (unsigned char *)get_ctrl_buffer( width * height * 3);
      printf("Not Support Source Image 1 BPP to Convert to RGB888/RGB565 IVLW\n");
      ASSERT(0);
   }
   return IVLW_ENC_STATUS_OK;
}


#if defined(IVLW_DECODER_STANDALONE)
static IVLW_ENC_STATUS
_ivlwEncGenAb2CtrlBlkByBMPInfo(
   IVLW_BMP_INFO_T* bmp_info,
   abm_enc_struct* abm_enc_blk)
{

   abm_enc_blk->bmp_width = bmp_info->bmp_width;
   abm_enc_blk->bmp_height = bmp_info->bmp_height;
   abm_enc_blk->bmp_bpp = bmp_info->bmp_bpp;
   abm_enc_blk->bmp_palette_num  = bmp_info->bmp_palette_num;
   //memcpy(abm_enc_blk->bmp_palette, bmp_info->bmp_palette, bmp_info->bmp_palette_num * 4);
   abm_enc_blk->bmp_pixel_start_p = bmp_info->pixel_start_p;
   abm_enc_blk->line_padding_bytes = bmp_info->line_padding_bytes;
   abm_enc_blk->x1 = 0;
   abm_enc_blk->y1 = 0;
   abm_enc_blk->x2 = 0;
   abm_enc_blk->y2 = 0;
   abm_enc_blk->src_key_color_enable = bmp_info->src_key_color_enable ;
   abm_enc_blk->is_windows_bmp = bmp_info->is_windows_bmp;;
   return IVLW_ENC_STATUS_OK;
}



static IVLW_ENC_STATUS
_ivlwEncGenAb2CtrlBlkByPPMInfo(
   IVLW_PPM_INFO_T* ppm_info,
   abm_enc_struct*  abm_enc_blk)
{
   abm_enc_blk->bmp_width = ppm_info->width;
   abm_enc_blk->bmp_height = ppm_info->height;
   abm_enc_blk->bmp_bpp = ppm_info->bpp * 8;
   abm_enc_blk->bmp_palette_num  = 0;
   abm_enc_blk->bmp_pixel_start_p = ppm_info->pixel_start_p;
   abm_enc_blk->line_padding_bytes = 0;
   abm_enc_blk->x1 = 0;
   abm_enc_blk->y1 = 0;
   abm_enc_blk->x2 = 0;
   abm_enc_blk->y2 = 0;
   abm_enc_blk->src_key_color_enable = 1;
   abm_enc_blk->is_windows_bmp = 1;
   return IVLW_ENC_STATUS_OK;
}
#endif



static IVLW_ENC_STATUS
_ivlwEncRaw(
   IVLW_ENCODER_HANDLE* handle,
   unsigned char *frame_buffer, //dst buf
   unsigned int frame_buf_size,
   signed int *encode_size,
   unsigned int *width,
   unsigned int *height)
{
   unsigned int bpp = 0;
   //unsigned int width;
   //unsigned int height;
   IVLW_ENC_STATUS status;

   if (NULL == handle)
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }

   // Do color convert and output to the destination buffer
   if (IVLW_ENC_FILE_BMP == handle->src_file_type)
   {
      IVLW_BMP_INFO_T* bmp_info = &handle->bmp_info;
      *width = (unsigned int)bmp_info->bmp_width;
      *height = (unsigned int)bmp_info->bmp_height;
      status = _ivlw_color_conver_swap((unsigned int)bmp_info->bmp_width,
                  (unsigned int)bmp_info->bmp_height,
                  bmp_info->pixel_start_p,
                  bmp_info->pixel_data_size,
                  bmp_info->color_format,
                  frame_buffer,
                  frame_buf_size,
                  (IVLW_COLOR_FORMAT)handle->ivlw_header.fixed_header.img_format,
                  encode_size);
      if (IVLW_ENC_STATUS_OK != status)
      {
        return status;
      }
   }
   else if (IVLW_ENC_FILE_PPM == handle->src_file_type)
   {
      IVLW_PPM_INFO_T* ppm_info = &handle->ppm_info;
      *width = (unsigned int)ppm_info->width;
      *height = (unsigned int)ppm_info->height;
      status = _ivlw_color_conver((unsigned int)ppm_info->width,
                  (unsigned int)ppm_info->height,
                  ppm_info->pixel_start_p,
                  ppm_info->pixel_data_size,
                  ppm_info->color_format,
                  frame_buffer,
                  frame_buf_size,
                  (IVLW_COLOR_FORMAT)handle->ivlw_header.fixed_header.img_format,
                  encode_size);
      if (IVLW_ENC_STATUS_OK != status)
      {
        return status;
      }
   }
   return IVLW_ENC_STATUS_OK;
}


static IVLW_ENC_STATUS
_ivlwEncAB2(
   IVLW_ENCODER_HANDLE* handle,
   unsigned char *frame_buffer, //dst buf
   unsigned int frame_buf_size,
   unsigned int *encode_size,
   unsigned int *width,
   unsigned int *height)
{
#if  defined(IVLW_DECODER_STANDALONE)
   signed int ret;
   signed int output_c_file = 0;
   unsigned int bpp = 0;
   IVLW_ENC_STATUS  status;

   abm_enc_struct abm_enc_blk;
   IVLW_BMP_INFO_T* bmp_info;

   if (NULL == handle)
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }
   bmp_info = &handle->bmp_info;

   if (IVLW_COLOR_RGB565 == handle->ivlw_header.fixed_header.img_format)
   {
      bpp = 16;
   }
   else if (IVLW_COLOR_RGB888 == handle->ivlw_header.fixed_header.img_format)
   {
      bpp = 24;
   }
   else
   {
      return IVLW_ENC_STATUS_INVALID_FILE;
   }

   // Do color convert and output to the destination buffer
   if (IVLW_ENC_FILE_BMP == handle->src_file_type)
   {
      IVLW_BMP_INFO_T* bmp_info = &handle->bmp_info;

      /*
      ** For AB2 encoder/decoder, the decoder part assump to accep BGR data.
      ** Thus we don't need to swap B/R channel here.
      ** Besides, ABM_load_with_BMP_info will process RGB888 convert to RGB565 operation,
      ** We don't need to do that here.
      */
      status = _ivlwEncGenAb2CtrlBlkByBMPInfo(bmp_info, &abm_enc_blk);
      if (IVLW_ENC_STATUS_OK != status)
      {
         return status;
      }

      if (0)//(Enc_Debug)
      {
          STFSAL dstFSAL;
          unsigned char outputName[64];
          sprintf(outputName, "%s%d%s", "Enc_Debug_Aft_", debug_num ,".ppm");
          FSAL_Open(&dstFSAL, outputName, FSAL_WRITE);
          if (IVLW_COLOR_RGB565 == handle->ivlw_header.fixed_header.img_format)
          {
             iul_ppm_writer_rgb565_to_ppm(&dstFSAL, bmp_info->pixel_start_p, (unsigned int)bmp_info->bmp_width, (unsigned int)bmp_info->bmp_height);
          }
          else if (IVLW_COLOR_RGB888 == handle->ivlw_header.fixed_header.img_format)
          {
             iul_ppm_writer_rgb888_to_ppm(&dstFSAL, bmp_info->pixel_start_p, (unsigned int)bmp_info->bmp_width, (unsigned int)bmp_info->bmp_height);
          }
          FSAL_Close(&dstFSAL);
          debug_num++;
      }
   }
   else if (IVLW_ENC_FILE_PPM == handle->src_file_type)
   {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
      return IVLW_ENC_STATUS_INVALID_PARA;
   }

   *encode_size = *width = *height = 0;
   ret = ABM_load_with_BMP_info(
       &abm_enc_blk,
       bpp,
       IMAGE_TYPE_DEVICE_BITMAP,
       ABM_ENC_OPTION_FLAG_AB2,
       frame_buffer,
       encode_size,
       width,
       height);

#endif //#if  defined(IVLW_DECODER_STANDALONE)

   return IVLW_ENC_STATUS_OK;
}




IVLW_ENC_STATUS
ivlwEncFrame(
   IVLW_ENCODER_HANDLE* handle,
   unsigned int frame_index,
   unsigned char *frame_buffer, //dst buf
   unsigned int frame_buf_size,
   unsigned int align_num) //align_num shall less than 64
{
#if !defined(__ARMULATOR__)
   unsigned int encode_size;
   unsigned int width, height;
   signed int output_c_file = 0;
   FSAL_Status fs_status;
   unsigned int pading_count, pattern, pattern_size;
   IVLW_ENC_STATUS ivlw_status = IVLW_ENC_STATUS_OK;
   unsigned int bpp = 0;
   IVLW_Header_FIXED_PART_Struct *fixed_header = &handle->ivlw_header.fixed_header;

   if ((NULL == handle) ||
       (frame_index >= fixed_header->total_frame_count)||
       0/*(IVLW_PIXEL_DATA_MAX_ALIGNMENT_NUM < align_num)*/)
   {
      return IVLW_ENC_STATUS_INVALID_PARA;
   }


   switch (fixed_header->compress_algorithm)
   {
     case IVLW_ALG_NONE:
     case IVLW_ALG_MAV:
     {
        ivlw_status = _ivlwEncRaw(handle, frame_buffer, frame_buf_size, &encode_size, &width, &height);
        if (IVLW_ENC_STATUS_OK != ivlw_status)
        {
           return ivlw_status;
        }
        break;
     }
     case IVLW_ALG_AB2:
     {
        ivlw_status = _ivlwEncAB2(handle, frame_buffer, frame_buf_size, &encode_size, &width, &height);
        if (IVLW_ENC_STATUS_OK != ivlw_status)
        {
           return ivlw_status;
        }

        break;
     }
     default:
        return IVLW_ENC_STATUS_INVALID_PARA;
   }

   //Output encoded result to dst file.
   {
     IVLW_Frame_Header_Struct *frame_header = &handle->ivlw_header.frame_header[frame_index];

#if defined(IVLW_VERSION_CTRL)
      fixed_header->verion = IVLW_ENCODER_VERSION_NUM;
#else
      fixed_header->verion = 0;
#endif
      fixed_header->img_width = width;
      fixed_header->img_height = height;

	  pattern_size = V0_IVLW_PIXEL_DATA_START_PATERN_SIZE;
	  pattern = V0_IVLW_PIXEL_DATA_START_PATERN;
	  if (1 == fixed_header->verion)
	  {
		 pattern_size = V1_IVLW_PIXEL_DATA_START_PATERN_SIZE;
		 pattern = V1_IVLW_PIXEL_DATA_START_PATERN;
	  }

      if (encode_size != 0)
      {
         if (IVLW_FALSE == handle->fgen_header)
         {
            if (handle->dst_fsal_handle)
            {
               FSAL_Seek(handle->dst_fsal_handle, 0);
            }
            else
            {
               IVLW_SET_DST_OFFSET(handle, 0);
            }

            _ivlwEncGenEncryptKey(handle);

            if (1 == IVLW_ENCODER_VERSION_NUM)
            {
               _ivlwEncOutputEncryptKey(handle);
            }

            ivlw_status = _ivlwOutputFixedHeader(handle);
            if (IVLW_ENC_STATUS_OK != ivlw_status)
            {
               return IVLW_ENC_STATUS_GEN_HEADER_FAIL;
            }
            ivlw_status = _ivlwOutputAllPartitionHeader(handle);
            if (IVLW_ENC_STATUS_OK != ivlw_status)
            {
               return IVLW_ENC_STATUS_GEN_HEADER_FAIL;
            }

            // preserve frame header size
            IVLW_SET_CTRLBLOCK_FILE_OFFSET_TO_PIXEL_DATA_START_POINT(handle);
            if (handle->dst_fsal_handle)
            {
               FSAL_Seek(handle->dst_fsal_handle, handle->current_output_file_offet);
            }
            else
            {
               IVLW_SET_DST_OFFSET(handle, handle->current_output_file_offet);
            }

            handle->fgen_header = IVLW_TRUE;
         }


         //pading_count = IVLW_PIXEL_DATA_ALIGNMENT - (encode_size & (IVLW_PIXEL_DATA_ALIGNMENT - 1));
         if ((0 == IVLW_ENCODER_VERSION_NUM)||
             (IVLW_ALG_MAV == fixed_header->compress_algorithm))
         {
            //4 Currently, V1 not support MAV.

            pading_count = 0;
            if (align_num >= 2)
            {
               pading_count = align_num - (encode_size & (align_num - 1));
            }

            //Fill n'th frame's frame header information
            //ivlw_status = _ivlwFillFrameHeader(handle, frame_index, encode_size, pading_count);
            //IVLW_Frame_Header_Struct *frame_header = &handle->ivlw_header.frame_header[frame_index];
            frame_header->compressed_data_size = encode_size;
            frame_header->frame_offset = handle->current_output_file_offet;
            frame_header->pading_count = pading_count;
            //if (IVLW_ENC_STATUS_OK != ivlw_status)
            //{
            //   return IVLW_ENC_STATUS_GEN_HEADER_FAIL;
            //}

            if ((0 != pattern) && (0 != pattern_size))
            {
               if (handle->dst_fsal_handle)
               {
                  fs_status = FSAL_Write(handle->dst_fsal_handle, (unsigned char*)&pattern, pattern_size);
                  if (FSAL_OK != fs_status)
                  {
                     return IVLW_ENC_STATUS_FS_FAIL;
                  }
               }
               else
               {
                  IVLW_SET_DST_WRITE(handle, (unsigned char*)&pattern, pattern_size);
               }
               IVLW_UPDATE_CTRLBLOCK_FILE_OFFSET_BY_ADD(handle, pattern_size);
            } //(0 != pattern)

            //Output n'th frame's compressed data to file.
            {
               unsigned char temp[IVLW_PIXEL_DATA_MAX_ALIGNMENT_NUM] = {IVLW_PIXEL_DATA_PADING_PATERN};

               if (handle->dst_fsal_handle)
               {
                  fs_status = FSAL_Write(handle->dst_fsal_handle, frame_buffer, encode_size);
                  if (FSAL_OK != fs_status)
                  {
                     return IVLW_ENC_STATUS_FS_FAIL;
                  }
                  fs_status = FSAL_Write(handle->dst_fsal_handle, temp, pading_count);
                  if (FSAL_OK != fs_status)
                  {
                     return IVLW_ENC_STATUS_FS_FAIL;
                  }
               }
               else
               {
                  IVLW_SET_DST_WRITE(handle, frame_buffer, encode_size);
                  IVLW_SET_DST_WRITE(handle, temp, pading_count);
               }
            }
            IVLW_UPDATE_CTRLBLOCK_FILE_OFFSET_BY_ADD(handle, (encode_size + pading_count));
         }
         else if (1 == IVLW_ENCODER_VERSION_NUM)
         {
             unsigned int cur_pos;
             FSAL_GetCurPos(handle->dst_fsal_handle, &cur_pos);

             //if (cur_pos != handle->current_output_file_offet)
             //{
             //   printf("Check Here\n");
             //}

             //Each Encoded Frame data shall align 32KB to enhance FSAL read performance
             frame_header->compressed_data_size = encode_size;
             pading_count = 0;
             frame_header->pading_count = 0;
             frame_header->frame_offset = (handle->current_output_file_offet / (align_num)) * (align_num);
             if (handle->current_output_file_offet & (align_num - 1))
             {
                frame_header->frame_offset += align_num;
             }
             //if (align_num >= 2)
             //{
             //   pading_count = align_num - (handle->current_output_file_offet & (align_num - 1));
             //}
             //frame_header->pading_count = pading_count;

             if (handle->dst_fsal_handle)
             {
                fs_status = FSAL_Seek(handle->dst_fsal_handle, frame_header->frame_offset);
                if ((0 != pattern) && (0 != pattern_size))
                {
                   fs_status = FSAL_Write(handle->dst_fsal_handle, (unsigned char*)&pattern, pattern_size);
                   if (FSAL_OK != fs_status)
                   {
                      return IVLW_ENC_STATUS_FS_FAIL;
                   }
                }
                fs_status = FSAL_Write(handle->dst_fsal_handle, frame_buffer, encode_size);
                if (FSAL_OK != fs_status)
                {
                   return IVLW_ENC_STATUS_FS_FAIL;
                }
             }
             else
             {
                IVLW_SET_DST_OFFSET(handle, frame_header->frame_offset);
                if (0 != pattern)
                {
                   IVLW_SET_DST_WRITE(handle, (unsigned char*)&pattern, pattern_size);
                }
                IVLW_SET_DST_WRITE(handle, frame_buffer, encode_size);
             }
             IVLW_SET_CTRLBLOCK_FILE_OFFSET(handle, (frame_header->frame_offset + encode_size + pattern_size));

         }
         else
         {
            ASSERT(0);
         }

         //For last frame, output all the frame header once.
         if ((handle->ivlw_header.fixed_header.total_frame_count - 1) == frame_index)
         {
            //Fill Encrypt Key value int the file end.
            if (0 == IVLW_ENCODER_VERSION_NUM)
            {
               _ivlwEncOutputEncryptKey(handle);
            }

            ivlw_status = _ivlwOutputAllFrameHeader(handle);
            if (IVLW_ENC_STATUS_OK != ivlw_status)
            {
               return IVLW_ENC_STATUS_GEN_HEADER_FAIL;
            }
         }
      }
   }

#endif // #if defined(__ARMULATOR__)
   return IVLW_ENC_STATUS_OK;
}





