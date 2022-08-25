#ifdef __cplusplus
extern "C"{
#endif

#include "lwp_decoder.h"
#include "app_zlib.h"
#include "fs_gprot.h"
//#if defined(__MTK_TARGET__)
//#include "drv_gfx_stack_switch_manager.h"
//#endif

#ifdef WIN32
#undef  get_ctrl_buffer
#undef  free_ctrl_buffer
#define get_ctrl_buffer(X) malloc(X)
#define free_ctrl_buffer(X) free(X)
#endif  //WIN32


#define LWP_ASYNC_FS_WORKING_BUF_SIZE  FS_ASYNC_WORKING_BUFFER_SIZE;

#if 0
/* under construction !*/
/* under construction !*/
#else
#define SWLA_DEBUG(tag,start) 
#endif

//unsigned int lwp_stack_size = 0xCE0;//= DRV_GFX_STACK_POOL_SIZE;
#define LWP_INFINITE_STACK_SIZE    0xFFFFFFF0
#define LWP_STACK_SIZE_MASK        0xFFFFFFF0
#define STACK_USER_ID_LWP          13
#define LWP_STACK_SIZE             (STACK_USER_ID_LWP + 0xCE0)
#define LWP_DRM_STACK_SIZE         (STACK_USER_ID_LWP + LWP_INFINITE_STACK_SIZE)
#define LWP_FILE_STACK_SIZE        (STACK_USER_ID_LWP + 0xCE0)


#define ZLIB_PATTERN                                (0x9C78)
#define UNCOMPRESSED_LWP_RANDOM_ACCESS_TABLE_OFFSET (0x64)
#define UNCOMPRESSED_LWP_HEADER_PATTERN1            ("interval")
#define UNCOMPRESSED_LWP_HEADER_PATTERN1_LEN        (sizeof(UNCOMPRESSED_LWP_HEADER_PATTERN1))
#define UNCOMPRESSED_LWP_HEADER_PATTERN2_OFFSET     (44)
#define UNCOMPRESSED_LWP_HEADER_PATTERN2            ("Wallpaper")
#define UNCOMPRESSED_LWP_HEADER_PATTERN2_LEN        (sizeof(UNCOMPRESSED_LWP_HEADER_PATTERN2))
#define UNCOMPRESSED_LWP_FRAME_COUNT_OFFSET         (80)
#define UNCOMPRESSED_LWP_FRAME_COUNT_SIZE           (4)

#define COMPRESSED_LWP_HEADER_PATTERN1_OFFSET       (4)
#define COMPRESSED_LWP_HEADER_PATTERN1              ("Wallpaper")
#define COMPRESSED_LWP_HEADER_PATTERN1_LEN          (sizeof(COMPRESSED_LWP_HEADER_PATTERN1))
#define COMPRESSED_LWP_FRAME_COUNT_OFFSET           (44)
#define COMPRESSED_LWP_FRAME_COUNT_SIZE             (4)
#define COMPRESSED_LWP_RANDOM_ACCESS_TABLE_OFFSET   (48)
#define COMPRESSED_LWP_RANDOM_ACCESS_TABLE_ENTRY_SIZE  (sizeof(LWP_RANDOM_ACCESS_TABLE_T))

#define ZLIB_STRING_SIZE 0


unsigned char g_buf[FS_ASYNC_WORKING_BUFFER_SIZE];
LWP_DECODER_HANDLE *g_current_handle;
#if !defined(LWP_DECODER_STANDALONE)
kal_mutexid  lwpMutex;
#define LWP_TAKE_MUTEX() \
do{\
	if (KAL_FALSE == kal_query_systemInit())\
	{\
	   kal_take_mutex(lwpMutex);\
	}	\
}while(0)

#define LWP_GIVE_MUTEX() \
do{\
	if (KAL_FALSE == kal_query_systemInit())\
	{\
	   kal_give_mutex(lwpMutex);\
	}	\
}while(0)
#define LWP_CREATE_MUTEX()\
do{\
	if (0 == lwpMutex)\
	{\
	   lwpMutex = kal_create_mutex("LWP_MGR");\
	}\
}while(0)
#else //!defined(LWP_DECODER_STANDALONE)
unsigned int  lwpMutex;
#define LWP_TAKE_MUTEX() 
#define LWP_GIVE_MUTEX()
#define LWP_CREATE_MUTEX()
#endif


LWP_DEC_STATUS
lwpDecGetHandle(LWP_DECODER_HANDLE** handlePtr)
{
   LWP_DECODER_HANDLE *h = NULL;
   LWP_DEC_STATUS rtn;

   LWP_CREATE_MUTEX();
   h = (LWP_DECODER_HANDLE*) get_ctrl_buffer(sizeof(LWP_DECODER_HANDLE));
   if (h)
   {
      memset(h, 0, sizeof(LWP_DECODER_HANDLE));
      rtn = LWP_STATUS_OK;
      *handlePtr = h;
   }
   else
   {
      *handlePtr = NULL;
      rtn = LWP_STATUS_HANDLE_UNAVAILABLE;
   }
   g_current_handle = h;
   return rtn;
}



LWP_DEC_STATUS
lwpDecReleaseHandle(LWP_DECODER_HANDLE** handle)
{
   if ((*handle)->random_access_table)
   {
      (*handle)->gzfree_func(NULL, (*handle)->random_access_table);
      (*handle)->random_access_table = NULL;
   }

   if ((*handle)->aysnc_fs_ctrl.file_overlapped.buf)
   {
      (*handle)->gzfree_func(NULL, (*handle)->aysnc_fs_ctrl.file_overlapped.buf);
      (*handle)->aysnc_fs_ctrl.file_overlapped.buf = NULL;
   }

   if ((*handle))
   {
      //med_free_ext_mem((void**)handle);
      free_ctrl_buffer((void*) (*handle));
      *handle = NULL;
   }
   g_current_handle = NULL;
   return LWP_STATUS_OK;
}



LWP_DEC_STATUS
lwpDecSetSrcFile(LWP_DECODER_HANDLE* handle, STFSAL *fp)
{
   handle->fsal_handle = fp;
   handle->fparsed = LWP_FALSE;
   return LWP_STATUS_OK;
}



LWP_DEC_STATUS
lwpDecSetAllocAndFree(
   LWP_DECODER_HANDLE* handle,
   alloc_func _alloc_func,
   free_func _free_func)
{
   if ((NULL == _alloc_func) || (NULL == _free_func))
   {
      return LWP_STATUS_INVALID_PARA;
   }

   handle->gzalloc_func = _alloc_func;
   handle->gzfree_func = _free_func;

   return LWP_STATUS_OK;
}



LWP_DEC_STATUS _lwpParseHeader(LWP_DECODER_HANDLE *handle)
{
   if (handle->fparsed)
   {
      return LWP_STATUS_OK;
   }

   {
      unsigned char tmp[20];
      unsigned int lwp_type = 0;
      unsigned int frame_count = 0;
      LWP_RANDOM_ACCESS_TABLE_T* paccess_table;
      LWP_FRAME_HEADER_T frame_header;
      FSAL_Status fs_status;

      fs_status = FSAL_Seek(handle->fsal_handle, 0);
      if (FSAL_OK != fs_status)
      {
         return LWP_STATUS_FS_FAIL;
      }

      fs_status = FSAL_Read(handle->fsal_handle, (unsigned char *)&lwp_type, 4); //FSAL_Seek(handle->fsal_handle, 4);
      if (FSAL_OK != fs_status)
      {
         return LWP_STATUS_FS_FAIL;
      }

      if (LWP_TYPE_UNCOMPRESSED == lwp_type) //un compress format
      {
         fs_status = FSAL_Read(handle->fsal_handle, tmp, UNCOMPRESSED_LWP_HEADER_PATTERN1_LEN);
         if (FSAL_OK != fs_status)
         {
            return LWP_STATUS_FS_FAIL;
         }
         if (0 != strcmp(tmp, UNCOMPRESSED_LWP_HEADER_PATTERN1))
         {
            return LWP_STATUS_FS_FAIL;
         }

         fs_status = FSAL_Seek(handle->fsal_handle, UNCOMPRESSED_LWP_HEADER_PATTERN2_OFFSET);
         if (FSAL_OK != fs_status)
         {
            return LWP_STATUS_FS_FAIL;
         }

         fs_status = FSAL_Read(handle->fsal_handle, tmp, UNCOMPRESSED_LWP_HEADER_PATTERN2_LEN);
         if (FSAL_OK != fs_status)
         {
            return LWP_STATUS_FS_FAIL;
         }

         if (0 != strcmp(tmp, UNCOMPRESSED_LWP_HEADER_PATTERN2))
         {
            return LWP_STATUS_INVALID_FILE;
         }

         fs_status = FSAL_Seek(handle->fsal_handle, UNCOMPRESSED_LWP_FRAME_COUNT_OFFSET);
         if (FSAL_OK != fs_status)
         {
            return LWP_STATUS_FS_FAIL;
         }

         fs_status = FSAL_Read(handle->fsal_handle, (unsigned char *)&frame_count, UNCOMPRESSED_LWP_FRAME_COUNT_SIZE);
         if (FSAL_OK != fs_status)
         {
            return LWP_STATUS_FS_FAIL;
         }

         if (0 == frame_count)
         {
            return LWP_STATUS_INVALID_FILE;
         }
         handle->frame_count = frame_count;

         paccess_table = (LWP_RANDOM_ACCESS_TABLE_T*)handle->gzalloc_func(NULL, 1, handle->frame_count * sizeof(LWP_RANDOM_ACCESS_TABLE_T));
         fs_status = FSAL_Seek(handle->fsal_handle, UNCOMPRESSED_LWP_RANDOM_ACCESS_TABLE_OFFSET);
         if (FSAL_OK != fs_status)
         {
            return LWP_STATUS_FS_FAIL;
         }

         fs_status = FSAL_Read(handle->fsal_handle, (unsigned char *)paccess_table, handle->frame_count * sizeof(LWP_RANDOM_ACCESS_TABLE_T));
         if (FSAL_OK != fs_status)
         {
            return LWP_STATUS_FS_FAIL;
         }

         handle->random_access_table = paccess_table;
         handle->data_trunk_start_offset = UNCOMPRESSED_LWP_RANDOM_ACCESS_TABLE_OFFSET + handle->frame_count * sizeof(LWP_RANDOM_ACCESS_TABLE_T);
         handle->fcompressed = LWP_FALSE;

         fs_status = FSAL_Seek(handle->fsal_handle, (paccess_table[0].frame_offset + handle->data_trunk_start_offset));
         if (FSAL_OK != fs_status)
         {
            return LWP_STATUS_FS_FAIL;
         }

         fs_status = FSAL_Read(handle->fsal_handle, (unsigned char *) &frame_header, sizeof(frame_header));
         if (FSAL_OK != fs_status)
         {
            return LWP_STATUS_FS_FAIL;
         }
         handle->src_width = frame_header.width;
         handle->src_height = frame_header.height;
      }
      else if (LWP_TYPE_ZLIB_COMPRESSED == lwp_type)
      {
         fs_status = FSAL_Read(handle->fsal_handle, tmp, COMPRESSED_LWP_HEADER_PATTERN1_LEN);
         if (FSAL_OK != fs_status)
         {
            return LWP_STATUS_FS_FAIL;
         }

         if (0 != strcmp(tmp, COMPRESSED_LWP_HEADER_PATTERN1))
         {
            return LWP_STATUS_FS_FAIL;
         }

         fs_status = FSAL_Seek(handle->fsal_handle, COMPRESSED_LWP_FRAME_COUNT_OFFSET);
         if (FSAL_OK != fs_status)
         {
            return LWP_STATUS_FS_FAIL;
         }

         fs_status = FSAL_Read(handle->fsal_handle, (unsigned char *)&frame_count, COMPRESSED_LWP_FRAME_COUNT_SIZE);
         if (FSAL_OK != fs_status)
         {
            return LWP_STATUS_FS_FAIL;
         }

         if (0 == frame_count)
         {
            return LWP_STATUS_INVALID_FILE;
         }
         handle->frame_count = frame_count;

         paccess_table = (LWP_RANDOM_ACCESS_TABLE_T*)handle->gzalloc_func(NULL, 1, handle->frame_count * COMPRESSED_LWP_RANDOM_ACCESS_TABLE_ENTRY_SIZE);
         fs_status = FSAL_Seek(handle->fsal_handle, COMPRESSED_LWP_RANDOM_ACCESS_TABLE_OFFSET);
         if (FSAL_OK != fs_status)
         {
            return LWP_STATUS_FS_FAIL;
         }
         fs_status = FSAL_Read(handle->fsal_handle, (unsigned char *)paccess_table, handle->frame_count * COMPRESSED_LWP_RANDOM_ACCESS_TABLE_ENTRY_SIZE);
         if (FSAL_OK != fs_status)
         {
            return LWP_STATUS_FS_FAIL;
         }

         handle->random_access_table = paccess_table;
         handle->data_trunk_start_offset = COMPRESSED_LWP_RANDOM_ACCESS_TABLE_OFFSET + handle->frame_count * COMPRESSED_LWP_RANDOM_ACCESS_TABLE_ENTRY_SIZE;
         handle->fcompressed = LWP_TRUE;

      }
      else
      {
         return LWP_STATUS_INVALID_FILE;
      }
      handle->fparsed = LWP_TRUE;
   }
   return LWP_STATUS_OK;
}



LWP_DEC_STATUS
lwpDecQuerySrcResolution(
   LWP_DECODER_HANDLE* handle,
   unsigned int* width,
   unsigned int* height)
{
   LWP_DEC_STATUS status;

   if (LWP_FALSE == handle->fparsed)
   {
      status = _lwpParseHeader(handle);
      if (status != LWP_STATUS_OK)
      {
         return status;
      }
   }

   if ((handle->src_width != 0) || (handle->src_height != 0))
   {
      *width = handle->src_width;
      *height = handle->src_height;
   }
   else
   {
      if (handle->fcompressed)
      {
         unsigned char *src_buf, *dst_buf;
         unsigned int src_buf_size, dst_buf_size, actual_read_size;

         src_buf_size = handle->random_access_table[0].compressed_data_size + ZLIB_STRING_SIZE; // 4: zlib pattern stream
         dst_buf_size = handle->random_access_table[0].raw_data_size;

         src_buf = handle->gzalloc_func(NULL, 1, src_buf_size);
         dst_buf = handle->gzalloc_func(NULL, 1, dst_buf_size);
       status = lwpDecGetFrameSrcBuf(handle, 
                                       LWP_READ_FILE_SYNC, 
                                       0, 
                                       src_buf, 
                                       src_buf_size, 
                                       &actual_read_size,
                                       NULL,
                                       NULL);
         if (status != LWP_STATUS_OK)
         {
            return status;
         }

         status = lwpDecGetFramePixelData(handle, src_buf, src_buf_size, dst_buf, dst_buf_size);
         if (status != LWP_STATUS_OK)
         {
            return status;
         }
         handle->gzfree_func(NULL, src_buf);
         handle->gzfree_func(NULL, dst_buf);
      }
      else
      {
         FSAL_Status fs_status;
         LWP_FRAME_HEADER_T frame_header;
         fs_status = FSAL_Seek(handle->fsal_handle, (handle->random_access_table[0].frame_offset + handle->data_trunk_start_offset));
         if (FSAL_OK != fs_status)
         {
            return LWP_STATUS_FS_FAIL;
         }
         fs_status = FSAL_Read(handle->fsal_handle, (unsigned char*) &frame_header, sizeof(frame_header));
         if (FSAL_OK != fs_status)
         {
            return LWP_STATUS_FS_FAIL;
         }

         handle->src_width = frame_header.width;
         handle->src_height = frame_header.height;
      }
   }

   *width = handle->src_width;
   *height = handle->src_height;
   return LWP_STATUS_OK;
}




LWP_DEC_STATUS
lwpDecQuerySrcFormat(
   LWP_DECODER_HANDLE* handle,
   LWP_DEC_COLOR_FORMAT *srcFormat)
{
   LWP_DEC_STATUS status;

   if (LWP_FALSE == handle->fparsed)
   {
      status = _lwpParseHeader(handle);
      if (status != LWP_STATUS_OK)
      {
         return status;
      }
   }
   *srcFormat = handle->format;
   return LWP_STATUS_OK;
}



LWP_DEC_STATUS
lwpDecQueryFrameCount(
   LWP_DECODER_HANDLE* handle,
   unsigned int *frameCnt)
{
   LWP_DEC_STATUS status;

   if (LWP_FALSE == handle->fparsed)
   {
      status = _lwpParseHeader(handle);
      if (status != LWP_STATUS_OK)
      {
         return status;
      }
   }
   *frameCnt = handle->frame_count;
   return LWP_STATUS_OK;
}



LWP_DEC_STATUS
lwpDecQueryStreamFormat(
   LWP_DECODER_HANDLE* handle,
   LWP_TYPE_FORMAT *formatType)
{
   LWP_DEC_STATUS status;

   if (LWP_FALSE == handle->fparsed)
   {
      status = _lwpParseHeader(handle);
      if (status != LWP_STATUS_OK)
      {
         return status;
      }
   }
   *formatType = (handle->fcompressed? LWP_TYPE_ZLIB_COMPRESSED: LWP_TYPE_UNCOMPRESSED);
   return LWP_STATUS_OK;
}



LWP_DEC_STATUS
lwpDecQuerySrcFrameBufSize(
   LWP_DECODER_HANDLE* handle,
   unsigned int frame_index,
   unsigned int *buf_size)
{
   LWP_DEC_STATUS status;

    if (LWP_FALSE == handle->fparsed)
    {
       status = _lwpParseHeader(handle);
       if (status != LWP_STATUS_OK)
       {
          return status;
       }
    }

   if (frame_index >= handle->frame_count)
   {
      return LWP_STATUS_INVALID_PARA;
   }

   if (handle->fcompressed)
   {
      *buf_size = handle->random_access_table[frame_index].compressed_data_size + ZLIB_STRING_SIZE; // 4: zlib pattern stream
   }
   else
   {
      //*buf_size = handle->random_access_table[frame_index].raw_data_size;
      *buf_size = 0;
   }

   return LWP_STATUS_OK;
}


//#define ZLIB_PARTIAL_DECODE : Not completely. Don't Enable This Option.

LWP_DEC_STATUS
lwpDecQueryFrameHeaderLength(
   LWP_DECODER_HANDLE* handle,
   unsigned int *frame_header_len)
{
   LWP_DEC_STATUS status;

   if (LWP_FALSE == handle->fparsed)
   {
      status = _lwpParseHeader(handle);
      if (status != LWP_STATUS_OK)
      {
         return status;
      }
   }

   if (handle->fcompressed)
   {
      *frame_header_len = sizeof(LWP_FRAME_HEADER_T);
   }
   else
   {
      *frame_header_len = 0;
   }
   return LWP_STATUS_OK;
}



//LWP Register callback to FS Interface for Async File Read
static signed int 
_lwpFSAsyncReadCallback(fs_job_id job_id, kal_int64 result, fs_async_callback_data_struct *data)
{
   LWP_DECODER_HANDLE *handle = data->param;
   LWP_DEC_STATUS status;

   if(g_current_handle != handle)
   {
      return 1;
   }
   
   if (result >= 0) //success
   {
       status = LWP_STATUS_OK;
   }
   else   
   {
      status = LWP_STATUS_FS_FAIL;
   }   

   LWP_TAKE_MUTEX();
   handle->async_read_busy = LWP_FALSE;
   LWP_GIVE_MUTEX();

   if (handle->aysnc_fs_ctrl.callback)
   {
      handle->aysnc_fs_ctrl.callback(status, handle->aysnc_fs_ctrl.para);
   }
   return 1;
}



LWP_DEC_STATUS
lwpDecGetFrameSrcBuf(
   LWP_DECODER_HANDLE *handle,
   LWP_READ_FILE_MODE_ENUM read_mode,
   unsigned int frame_index,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned int *actual_rd_size,
   lwp_async_get_frame_callback  callback, //// AP register callback to LWP for Async File Read. Called when LWP's FS' Async callback is invoked.
   void         *param)
{
   LWP_DEC_STATUS status;
   LWP_RANDOM_ACCESS_TABLE_T* paccess_table;
   unsigned int frame_offset;
   unsigned int read_buffer_size;
   FSAL_Status fs_status;

   if (LWP_FALSE == handle->fparsed)
   {
      status = _lwpParseHeader(handle);
     if (status != LWP_STATUS_OK)
      {
         return status;
      }
   }

   if ((!handle->fcompressed) && (0 == src_buf_size))
   {
      handle->current_src_buf = src_buf;
      handle->current_dec_frame_index = frame_index;
      *actual_rd_size = 0;

      // Hack
      paccess_table = &handle->random_access_table[frame_index];
      if(paccess_table)
      {
         frame_offset = paccess_table->frame_offset + handle->data_trunk_start_offset;
         fs_status = FSAL_Seek(handle->fsal_handle, frame_offset);
      }
      // --Hack end
   
      if ((LWP_READ_FILE_ASYNC == read_mode) && (callback))
      {
         callback(LWP_STATUS_OK, param);
      }
      return LWP_STATUS_OK;
   }

   if (NULL == src_buf)
   {
      return LWP_STATUS_MEM_UNAVAILABLE;
   }


   LWP_TAKE_MUTEX();
   if ((LWP_READ_FILE_ASYNC == read_mode) && (handle->async_read_busy == LWP_TRUE))
   {
      ASSERT(0); //re-entry 
   }

   if ((LWP_READ_FILE_ASYNC == read_mode) && //lwpDecGetFrameSrcBuf Re-entry.
       (handle->async_read_busy == LWP_TRUE) &&
       (frame_index != 0) &&
       (handle->current_dec_frame_index == frame_index))
   {
      ASSERT(0);//return LWP_STATUS_INVALID_PARA;
   }
   handle->current_src_buf = src_buf;
   handle->current_dec_frame_index = frame_index;
   LWP_GIVE_MUTEX();

   paccess_table = &handle->random_access_table[frame_index];
   if (NULL == paccess_table)
   {
      return LWP_STATUS_INVALID_FILE;
   }

   if (callback)
   {
      handle->aysnc_fs_ctrl.callback = callback;
      handle->aysnc_fs_ctrl.para = param;
   }
   else
   {
      if (LWP_READ_FILE_ASYNC == read_mode)
      {
         return LWP_STATUS_INVALID_PARA;
      }
   }

   frame_offset = paccess_table->frame_offset + handle->data_trunk_start_offset;
   fs_status = FSAL_Seek(handle->fsal_handle, frame_offset);
   if (FSAL_OK != fs_status)
   {
     return LWP_STATUS_FS_FAIL;
   }

#if !defined(LWP_DECODER_STANDALONE)
   //if (handle->fcompressed) //compress
   {
      read_buffer_size = paccess_table->compressed_data_size;
      if (src_buf_size < read_buffer_size)
      {
         return LWP_STATUS_INVALID_PARA;
      }

#if defined(__FS_ASYNC_SUPPORT__)
      if (LWP_READ_FILE_ASYNC == read_mode)
      {
         kal_int32 ret;

         SWLA_DEBUG("LR0", 1);
         if (NULL == handle->aysnc_fs_ctrl.file_overlapped.buf)
         {
            handle->aysnc_fs_ctrl.file_overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
            handle->aysnc_fs_ctrl.file_overlapped.buf = handle->gzalloc_func(NULL, 1, handle->aysnc_fs_ctrl.file_overlapped.buf_size);
            if (NULL == handle->aysnc_fs_ctrl.file_overlapped.buf)
            {
               return LWP_STATUS_MEM_UNAVAILABLE;
            }
         }
         SWLA_DEBUG("LR0", 0);
         SWLA_DEBUG("LR1", 1);
         handle->async_read_busy = LWP_TRUE;
         handle->aysnc_fs_ctrl.file_overlapped.callback = (fs_async_callback)_lwpFSAsyncReadCallback;
         handle->aysnc_fs_ctrl.file_overlapped.param = (void*) handle;
         handle->aysnc_fs_ctrl.file_overlapped.priority_value = 146;
         handle->aysnc_fs_ctrl.file_overlapped.priority = FS_PRIORITY_ASSIGN;
         ret = fs_async_read(handle->fsal_handle->hFile,
                   src_buf,
                   (read_buffer_size + ZLIB_STRING_SIZE),
                   actual_rd_size,
                   &handle->aysnc_fs_ctrl.file_overlapped);
         SWLA_DEBUG("LR1", 0);
         if (ret < 0)
         {
            return LWP_STATUS_FS_FAIL;
         }
         return LWP_STATUS_OK;
      } //(LWP_READ_FILE_ASYNC == read_mode)
#endif //defined(__FS_ASYNC_SUPPORT__)

      {
         //For the other case, use Sync mode to read src data.
         //if (LWP_READ_FILE_SYNC == read_mode)
         SWLA_DEBUG("LRD", 1); //LWP Read
         fs_status = FSAL_Read(handle->fsal_handle, src_buf, read_buffer_size + ZLIB_STRING_SIZE);
         SWLA_DEBUG("LRD", 0); //LWP Read
         if (FSAL_OK != fs_status)
         {
            return LWP_STATUS_FS_FAIL;
         }
         *actual_rd_size = read_buffer_size;
      }

      if (LWP_READ_FILE_ASYNC == read_mode)
      {
         _lwpFSAsyncReadCallback(0, 1, (void*)handle);
      }
   }
   //else //(handle->fcompressed) //compress
   //{
   //   *actual_rd_size = paccess_table->compressed_data_size;
   //   _lwpFSAsyncReadCallback(0, 1, (void*)handle);
   //}

#else //#if defined(LWP_DECODER_STANDALONE)
   if (handle->fcompressed) //compress
   {
      read_buffer_size = paccess_table->compressed_data_size;
      if (src_buf_size < read_buffer_size)
      {
           return LWP_STATUS_INVALID_PARA;
      }  
      fs_status = FSAL_Read(handle->fsal_handle, src_buf, read_buffer_size + ZLIB_STRING_SIZE);
      if (FSAL_OK != fs_status)
      {
         return LWP_STATUS_FS_FAIL;
      }
      *actual_rd_size = read_buffer_size;
      if (LWP_READ_FILE_ASYNC == read_mode)
      {
         _lwpFSAsyncReadCallback(0, 1, (void*)handle);
      }
   }
   else
   {
      *actual_rd_size = paccess_table->compressed_data_size;
       _lwpFSAsyncReadCallback(0, 1, (void*)handle);
   }
#endif

   return LWP_STATUS_OK;
}



LWP_DEC_STATUS
lwpDecGetFramePixelData(
   LWP_DECODER_HANDLE *handle,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned char* dstBuf,
   unsigned int dst_buf_size)
{
   LWP_DEC_STATUS status;
   unsigned int frame_offset;
   void *stk_ptr;  /* for switch stack */
   FSAL_Status fs_status;

   if (LWP_FALSE == handle->fparsed)
   {
      status = _lwpParseHeader(handle);
      if (status != LWP_STATUS_OK)
      {
         return status;
      }
   }

   if ((NULL == handle->gzalloc_func) || 
       (NULL == handle->gzfree_func))
   {
      return LWP_STATUS_INVALID_PARA;
   }

   LWP_TAKE_MUTEX();
   if ((src_buf == handle->current_src_buf) && (LWP_TRUE == handle->async_read_busy))
   {
      ASSERT(0);
   }
   LWP_GIVE_MUTEX();

   if (handle->fcompressed)
   {
      //compress
      int ret = 0;
      unsigned int magic_number = 0;
      unsigned int output_buffer_size;
      LWP_FRAME_HEADER_T *frame_header;
      unsigned char temp[256];

      if (NULL == src_buf)
      {
         return LWP_STATUS_MEM_UNAVAILABLE;
      }

      magic_number = *((unsigned int*) src_buf) & 0xFFFF;
      if (magic_number != 0x9C78)
      {
         return LWP_STATUS_INVALID_FILE;
      }
     
      {
         SWLA_DEBUG("LWP", 1); 
         output_buffer_size = dst_buf_size;
         ret = zlib_uncompress(
               dstBuf,
               (uLong*)&output_buffer_size,
               src_buf,
               (uLong)src_buf_size,
               handle->gzalloc_func, handle->gzfree_func);
         SWLA_DEBUG("LWP", 0); 
      }

      if (Z_OK != ret)
      {
          return LWP_STATUS_FAIL;
      }

      if ((0 == handle->src_width) && (0 == handle->src_height))
      {
          frame_header = (LWP_FRAME_HEADER_T *) dstBuf;
          handle->src_width = frame_header->width;
          handle->src_height = frame_header->height;
      }
   }
   else
   {
      LWP_FRAME_HEADER_T frame_header;
      LWP_RANDOM_ACCESS_TABLE_T* paccess_table = &handle->random_access_table[handle->current_dec_frame_index ];

      fs_status = FSAL_Read(handle->fsal_handle, (unsigned char*) &frame_header, sizeof(LWP_FRAME_HEADER_T));    //12byte frame header
      if (FSAL_OK != fs_status)
      {
         return LWP_STATUS_FS_FAIL;
      }

      if (KAL_FALSE == handle->fparsed)
      {
         handle->src_width = frame_header.width;
         handle->src_height = frame_header.height;
      }
      fs_status = FSAL_Read(handle->fsal_handle, (unsigned char*) dstBuf, (paccess_table->raw_data_size - sizeof(LWP_FRAME_HEADER_T)));  //raw data //
      if (FSAL_OK != fs_status)
      {
         return LWP_STATUS_FS_FAIL;
      }
   }
   return LWP_STATUS_OK;
}

#ifdef __cplusplus
}
#endif

