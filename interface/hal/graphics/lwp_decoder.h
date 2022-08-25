#ifndef __LWP_RAW_PARSER_H__
#define __LWP_RAW_PARSER_H__

#ifdef WIN32
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#endif

#include "fsal.h"
#include "app_zlib.h"
//#if defined(__MTK_TARGET__)
#include "fs_gprot.h"
//#endif

#define __LWP_SWLA_DEBUG__

typedef enum
{
   LWP_FALSE,
   LWP_TRUE
}LWP_bool;


typedef enum
{
   LWP_TYPE_ZLIB_COMPRESSED = 1,
   LWP_TYPE_UNCOMPRESSED,
   LWP_TYPE_RSVD
}LWP_TYPE_FORMAT;

typedef enum
{
   LWP_READ_FILE_SYNC = 0,
   LWP_READ_FILE_ASYNC,
   LWP_READ_FILE_RSVD
}LWP_READ_FILE_MODE_ENUM;


typedef enum
{
   LWP_STATUS_OK,
   LWP_STATUS_HANDLE_UNAVAILABLE,
   LWP_STATUS_MEM_UNAVAILABLE,
   LWP_STATUS_INVALID_FILE,
   LWP_STATUS_INVALID_PARA,
   LWP_STATUS_FS_FAIL,
   LWP_STATUS_FAIL,
   LWP_STATUS_RSVD
}LWP_DEC_STATUS;


typedef enum
{
   LWP_DEC_RGB565,
   LWP_DEC_RGB888,
   LWP_DEC_FORMAT_RSVD
}LWP_DEC_COLOR_FORMAT;


typedef struct
{
   unsigned int frame_offset; //respect to random access table end
   unsigned int raw_data_size;
   unsigned int compressed_data_size;
}LWP_RANDOM_ACCESS_TABLE_T;


typedef struct
{
   unsigned int width;
   unsigned int height;
   unsigned int padding_count;
}LWP_FRAME_HEADER_T;


typedef void (*lwp_async_get_frame_callback)(LWP_DEC_STATUS error_code, void *callback_para);

typedef struct
{
    unsigned int frame_index;
	
	lwp_async_get_frame_callback callback; //async_get_frame_callback

	void *para; //async_get_frame_callback_para

	LWP_DEC_STATUS status; //async_get_frame_status
	
	fs_overlapped_struct file_overlapped;

}LWP_ASYNC_FS_CTRL_BLOCK;


typedef struct
{
   STFSAL     *fsal_handle;       ///< fsal handle
   LWP_bool   fparsed;            ///< header been parsed or not?
   LWP_bool   fcompressed;

   unsigned int frame_count;
   unsigned int src_width;
   unsigned int src_height;
   LWP_DEC_COLOR_FORMAT format;

   LWP_RANDOM_ACCESS_TABLE_T* random_access_table;
   unsigned int data_trunk_start_offset;

//private data:
   alloc_func gzalloc_func;
   free_func  gzfree_func;

   LWP_ASYNC_FS_CTRL_BLOCK  aysnc_fs_ctrl;

   unsigned int current_dec_frame_index;

// for debug
   unsigned int async_read_busy;
   
   unsigned char* current_src_buf;
   
}LWP_DEC_CTRL_BLOCK;


typedef LWP_DEC_CTRL_BLOCK   LWP_DECODER_HANDLE;


LWP_DEC_STATUS
lwpDecGetHandle(LWP_DECODER_HANDLE** handle);


LWP_DEC_STATUS
lwpDecReleaseHandle(LWP_DECODER_HANDLE** handle);


LWP_DEC_STATUS
lwpDecSetSrcFile(LWP_DECODER_HANDLE* handle, STFSAL *fp);


LWP_DEC_STATUS
lwpDecQuerySrcResolution(
  LWP_DECODER_HANDLE* handle,
  unsigned int* width,
  unsigned int* height);


LWP_DEC_STATUS
lwpDecQuerySrcFormat(LWP_DECODER_HANDLE* handle, LWP_DEC_COLOR_FORMAT *srcFormat);


LWP_DEC_STATUS
lwpDecQueryFrameCount(LWP_DECODER_HANDLE* handle, unsigned int *frameCnt);


LWP_DEC_STATUS
lwpDecQuerySrcFrameBufSize(LWP_DECODER_HANDLE* handle, unsigned int frame_index, unsigned int *buf_size);


LWP_DEC_STATUS
lwpDecQueryFrameHeaderLength(LWP_DECODER_HANDLE* handle, unsigned int *frame_header_len);



LWP_DEC_STATUS
lwpDecSetAllocAndFree(
   LWP_DECODER_HANDLE* handle,
   alloc_func alloc_func,
   free_func free_func);


LWP_DEC_STATUS
lwpDecGetFrameSrcBuf(
   LWP_DECODER_HANDLE *handle,
   LWP_READ_FILE_MODE_ENUM read_mode,
   unsigned int frame_index,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned int *output_size,
   lwp_async_get_frame_callback  callback,
   void               *param);


LWP_DEC_STATUS
lwpDecGetFramePixelData(
   LWP_DECODER_HANDLE *handle,
   unsigned char  *src_buf,
   unsigned int   src_buf_size,
   unsigned char  *dstBuf,
   unsigned int   dst_buf_size);



#endif //__LWP_RAW_PARSER_H__
