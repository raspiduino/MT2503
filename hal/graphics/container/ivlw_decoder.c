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
 *   ivlw_decoder.c
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
#include "ivlw_decoder.h"
#include "iul_color_convert.h"

#if defined(IVLW_DECODER_STANDALONE)
#include "ABMLoader.h"
#include "gdi_image_alpha_bmp_v2_internal.h"
#else
  #if defined(__MTK_TARGET__)
     #include "cache_sw.h"
     #define __IVLW_SWITCH_SRC_BUF_TO_CACHABLE_BUFFER__
  #endif
//#define __IVLW_PFMC_LOG_SUPPORT__
#endif

//debug information
//#define IVLW_MALLOC_DEBUG
//#define IVLW_MEM_DBG_MSG_SUPPORT


#define IVLW_FS_ASYNC_RD_BLOCK_SZ (32 * 1024)
#define IVLW_FS_HINT_CNT           2047

#define IVLW_ASYNC_FS_WORKING_BUF_SIZE  FS_ASYNC_WORKING_BUFFER_SIZE;


#if defined(__IVLW_PFMC_LOG_SUPPORT__)

#define IVLW_DEC_PFMC_LOG_ENTRY_CNT 16
typedef struct
{
   unsigned int set_file_start_time;
   unsigned int set_file_end_time;
   unsigned int set_file_exet_time;

   unsigned int sync_index;
   unsigned int sync_rd_start_time;
   unsigned int sync_rd_end_time;
   unsigned int sync_exet_time[IVLW_DEC_PFMC_LOG_ENTRY_CNT];

   unsigned int async_index;
   unsigned int async_rd_start_time;
   unsigned int async_rd_end_time;
   unsigned int async_exet_time[IVLW_DEC_PFMC_LOG_ENTRY_CNT];

   unsigned int dec_index;
   unsigned int dec_start_time;
   unsigned int dec_end_time;
   unsigned int dec_exet_time[IVLW_DEC_PFMC_LOG_ENTRY_CNT];


   unsigned int seek_index;
   unsigned int seek_start_time;
   unsigned int seek_end_time;
   unsigned int seek_exet_time[IVLW_DEC_PFMC_LOG_ENTRY_CNT];


   unsigned int switch_validate_buffer_index;
   unsigned int switch_validate_buffer_start_time;
   unsigned int switch_validate_buffer_end_time;
   unsigned int switch_validate_buffer_time[IVLW_DEC_PFMC_LOG_ENTRY_CNT];

} ivlw_dec_pfmc_log_t;
ivlw_dec_pfmc_log_t ivlw_dec_pfmc_log_blk = {0};


#define IVLW_DEC_SET_FILE_PFMC_LOG_START()                            \
do{                                                                   \
  ivlw_dec_pfmc_log_blk.set_file_start_time = drv_get_current_time(); \
}while(0)

#define IVLW_DEC_SET_FILE_PFMC_LOG_END()                              \
do{                                                                   \
  ivlw_dec_pfmc_log_blk.set_file_end_time = drv_get_current_time();   \
  ivlw_dec_pfmc_log_blk.set_file_exet_time = drv_get_duration_tick(ivlw_dec_pfmc_log_blk.set_file_start_time, ivlw_dec_pfmc_log_blk.set_file_end_time);\
}while(0)


#define IVLW_DEC_SYNC_RD_PFMC_LOG_START()                             \
do{                                                                   \
  ivlw_dec_pfmc_log_blk.sync_rd_start_time = drv_get_current_time();  \
}while(0)

#define IVLW_DEC_SYNC_RD_PFMC_LOG_END()                               \
do{                                                                   \
  ivlw_dec_pfmc_log_blk.sync_rd_end_time = drv_get_current_time();    \
  ivlw_dec_pfmc_log_blk.sync_exet_time[ivlw_dec_pfmc_log_blk.sync_index] = drv_get_duration_tick(ivlw_dec_pfmc_log_blk.sync_rd_start_time, ivlw_dec_pfmc_log_blk.sync_rd_end_time);\
  ivlw_dec_pfmc_log_blk.sync_index++;                                 \
  ivlw_dec_pfmc_log_blk.sync_index &= (IVLW_DEC_PFMC_LOG_ENTRY_CNT-1);\
}while(0)

#define IVLW_DEC_ASYNC_RD_PFMC_LOG_START()                            \
do{                                                                   \
  ivlw_dec_pfmc_log_blk.async_rd_start_time = drv_get_current_time(); \
}while(0)

#define IVLW_DEC_ASYNC_RD_PFMC_LOG_END()                              \
do{                                                                   \
  ivlw_dec_pfmc_log_blk.async_rd_end_time = drv_get_current_time();   \
  ivlw_dec_pfmc_log_blk.async_exet_time[ivlw_dec_pfmc_log_blk.async_index] = drv_get_duration_tick(ivlw_dec_pfmc_log_blk.async_rd_start_time, ivlw_dec_pfmc_log_blk.async_rd_end_time);\
  ivlw_dec_pfmc_log_blk.async_index++;                                \
  ivlw_dec_pfmc_log_blk.async_index &= (IVLW_DEC_PFMC_LOG_ENTRY_CNT-1);\
}while(0)

#define IVLW_DEC_PFMC_LOG_START()                                     \
do{                                                                   \
  ivlw_dec_pfmc_log_blk.dec_start_time = drv_get_current_time();      \
}while(0)

#define IVLW_DEC_PFMC_LOG_END()                                       \
do{                                                                   \
  ivlw_dec_pfmc_log_blk.dec_end_time = drv_get_current_time();        \
  ivlw_dec_pfmc_log_blk.dec_exet_time[ivlw_dec_pfmc_log_blk.dec_index] = drv_get_duration_tick(ivlw_dec_pfmc_log_blk.dec_start_time, ivlw_dec_pfmc_log_blk.dec_end_time);\
  ivlw_dec_pfmc_log_blk.dec_index++;                                  \
  ivlw_dec_pfmc_log_blk.dec_index &= (IVLW_DEC_PFMC_LOG_ENTRY_CNT-1); \
}while(0)

#define IVLW_DEC_SEEK_PFMC_LOG_START()                                \
do{                                                                   \
  ivlw_dec_pfmc_log_blk.seek_start_time = drv_get_current_time();     \
}while(0)

#define IVLW_DEC_SEEK_PFMC_LOG_END()                                  \
do{                                                                   \
  ivlw_dec_pfmc_log_blk.seek_end_time = drv_get_current_time();       \
  ivlw_dec_pfmc_log_blk.seek_exet_time[ivlw_dec_pfmc_log_blk.seek_index] = drv_get_duration_tick(ivlw_dec_pfmc_log_blk.seek_start_time, ivlw_dec_pfmc_log_blk.seek_end_time);\
  ivlw_dec_pfmc_log_blk.seek_index++;                                 \
  ivlw_dec_pfmc_log_blk.seek_index &= (IVLW_DEC_PFMC_LOG_ENTRY_CNT-1);\
}while(0)

#define IVLW_DEC_SWITCH_VALIDATE_BUF_PFMC_LOG_START()                 \
do{                                                                   \
  ivlw_dec_pfmc_log_blk.switch_validate_buffer_start_time = drv_get_current_time();\
}while(0)

#define IVLW_DEC_SWITCH_VALIDATE_BUF_PFMC_LOG_END()                   \
do{                                                                   \
  ivlw_dec_pfmc_log_blk.switch_validate_buffer_end_time = drv_get_current_time();\
  ivlw_dec_pfmc_log_blk.switch_validate_buffer_time[ivlw_dec_pfmc_log_blk.seek_index] = drv_get_duration_tick(ivlw_dec_pfmc_log_blk.switch_validate_buffer_start_time, ivlw_dec_pfmc_log_blk.switch_validate_buffer_end_time);\
  ivlw_dec_pfmc_log_blk.switch_validate_buffer_index++;               \
  ivlw_dec_pfmc_log_blk.switch_validate_buffer_index &= (IVLW_DEC_PFMC_LOG_ENTRY_CNT-1);\
}while(0)

#else //defined(__IVLW_PFMC_LOG_SUPPORT__)
#define IVLW_DEC_SET_FILE_PFMC_LOG_START()
#define IVLW_DEC_SET_FILE_PFMC_LOG_END()
#define IVLW_DEC_SYNC_RD_PFMC_LOG_START()
#define IVLW_DEC_SYNC_RD_PFMC_LOG_END()
#define IVLW_DEC_ASYNC_RD_PFMC_LOG_START()
#define IVLW_DEC_ASYNC_RD_PFMC_LOG_END()
#define IVLW_DEC_PFMC_LOG_START()
#define IVLW_DEC_PFMC_LOG_END()
#define IVLW_DEC_SEEK_PFMC_LOG_START()
#define IVLW_DEC_SEEK_PFMC_LOG_END()
#define IVLW_DEC_SWITCH_VALIDATE_BUF_PFMC_LOG_START() {}
#define IVLW_DEC_SWITCH_VALIDATE_BUF_PFMC_LOG_END() {}
#endif //__IVLW_PFMC_LOG_SUPPORT__

#undef __IVLW_SWLA_DEBUG__
#if defined(__MTK_TARGET__) && defined(__IVLW_SWLA_DEBUG__)
#define IVLW_SWLA_DEBUG(tag,start) SLA_CustomLogging((tag), (start));
#else
#define IVLW_SWLA_DEBUG(tag,start)
#endif

#if !defined(IVLW_DECODER_STANDALONE)
  #define IVLW_MOD MOD_GFX
  //#if (!defined(LOW_COST_SUPPORT))
  //  #define IVLW_TRACE  kal_prompt_trace
  //#else
    #define IVLW_TRACE(...)
  //#endif
#else //!defined(IVLW_DECODER_STANDALONE)
#define IVLW_TRACE(...)
#define IVLW_MOD
#endif


#if !defined(IVLW_DECODER_STANDALONE)
kal_mutexid  ivlwMutex;
#define IVLW_TAKE_MUTEX() \
do{\
  if (KAL_FALSE == kal_query_systemInit())\
  {\
     kal_take_mutex(ivlwMutex);\
  } \
}while(0)

#define IVLW_GIVE_MUTEX() \
do{\
  if (KAL_FALSE == kal_query_systemInit())\
  {\
     kal_give_mutex(ivlwMutex);\
  } \
}while(0)

#define IVLW_CREATE_MUTEX()\
do{\
  if (0 == ivlwMutex)\
  {\
     ivlwMutex = kal_create_mutex("IVLW_MGR");\
  }\
}while(0)
#else //!defined(IVLW_DECODER_STANDALONE)
unsigned int  ivlwMutex;
#define IVLW_TAKE_MUTEX()
#define IVLW_GIVE_MUTEX()
#define IVLW_CREATE_MUTEX()
#endif

IVLW_DECODER_HANDLE  *ivlw_current_handle;

#if defined(IVLW_MALLOC_DEBUG)
static kal_uint32 alloc_total_size = 0;
static kal_uint32 free_total_size = 0;
static kal_uint32 free_size = 0;
static kal_uint32 alloc_size = 0;

#define IVLW_MALLOC_TOTAL_SIZE_STATISTIC(size)\
{\
   alloc_total_size += size;\
}
#define IVLW_MFREE_TOTAL_SIZE_STATISTIC(size)\
{\
   free_total_size += size;\
}
#define IVLW_MFREE_SET_FREE_SIZE(size)\
{\
   free_size = size;\
}

#define IVLW_MFREE_SET_ALLOC_SIZE(size)       \
{                                             \
   alloc_size = size;                         \
}
#else  //defined(IVLW_MALLOC_DEBUG)
#define IVLW_MALLOC_TOTAL_SIZE_STATISTIC(size)
#define IVLW_MFREE_TOTAL_SIZE_STATISTIC(size)
#define IVLW_MFREE_SET_FREE_SIZE(size)
#define IVLW_MFREE_SET_ALLOC_SIZE(size)
#endif  //defined(IVLW_MALLOC_DEBUG)


typedef enum
{
  IVLW_EVT_FSASYNC_RD_CB = 1,
  IVLW_EVT_RSVD = 0xff
}IVLW_EVENT_ENUM;

unsigned int FSAsyncReadFailCount = 0;
unsigned int FSSyncReadFailCount = 0;


typedef enum
{
  IVLW_LOCK________ASYNC_RSC0,
  IVLW_UNLOCK______ASYNC_RSC0,

  IVLW_LOCK________ASYNC_RSC1,
  IVLW_UNLOCK______ASYNC_RSC1,

  IVLW_GET_SRC_BUF_ASYNC_CB_B,
  IVLW_GET_SRC_BUF_ASYNC_CB_E,

  IVLW_GET_SRC_BUF__________B,
  IVLW_GET_SRC_BUF_______SYNC,
  IVLW_GET_SRC_BUF______ASYNC,
  IVLW_GET_SRC_BUF__________E,

  IVLW_GET_SRC_BUF____ABORT_B,
  IVLW_GET_SRC_BUF____ABORT_E,
  IVLW_GET_SRC_BUF____ABORT_F,

  IVLW_GET_FRM_DTA__________B,
  IVLW_GET_FRM_DTA__________E,

  IVLW_TIMER________TIMESTAMP,
  IVLW_TIMER________RELEASE_1,
  IVLW_TIMER________RELEASE_2,
  IVLW_TIMER________RELEASE_3,
  IVLW_TIMER________RELEASE_4,

  IVLW_TIMER________ALLOC___1,
  IVLW_TIMER________ALLOC___2,
  IVLW_TIMER________ALLOC___3,
  IVLW_TIMER________ALLOC___4,
  IVLW_TIMER________ALLOC___5,
  IVLW_TIMER________ALLOC___6,
  IVLW_TIMER________ALLOC___7,

  IVLW_TIMER_____PARSE_P_INFO,

  IVLW_GET_FRM_DTA________RSD
}IVLW_DBG_MSG_ENUM;


//#define IVLW_MEM_DBG_MSG_SUPPORT
#if defined(IVLW_MEM_DBG_MSG_SUPPORT)
#include "kal_release.h"
#include "dcl.h"
volatile static DCL_HANDLE ivlw_timer_handle = NULL;
static unsigned int ivlw_time_interval = 100; //1s
static IVLW_BOOL ivle_timer_start = IVLW_FALSE;
typedef struct
{
  IVLW_DBG_MSG_ENUM msg;
  unsigned int free_size;
  unsigned int alloc_size;
  IVLW_DECODER_HANDLE *handle;
  unsigned char *src_buf;
  unsigned char async0_lock;
  unsigned char async1_lock;
  unsigned int time;
}IVLW_DBG_BLK;
#define IVLW_DBG_MSG_CNT 128
volatile kal_uint32 ivlw_debug_count= 0;
volatile IVLW_DBG_BLK ivlw_debug_data[IVLW_DBG_MSG_CNT];
void ivlw_dbg_trace(IVLW_DBG_MSG_ENUM msg)
{
   kal_uint32 save_irq_mask;
   //Avoid racing problem
   save_irq_mask=SaveAndSetIRQMask();
   ivlw_debug_data[ivlw_debug_count].msg = msg;
   ivlw_debug_data[ivlw_debug_count].async0_lock = ivlw_current_handle->aysnc_fs_ctrl[0].occupied;
   ivlw_debug_data[ivlw_debug_count].async1_lock = ivlw_current_handle->aysnc_fs_ctrl[1].occupied;
   if (ivlw_debug_data[ivlw_debug_count].async0_lock)
   {
      ivlw_debug_data[ivlw_debug_count].src_buf = ivlw_current_handle->aysnc_fs_ctrl[0].read_buf;
   }
   else
   {
      ivlw_debug_data[ivlw_debug_count].src_buf = ivlw_current_handle->aysnc_fs_ctrl[1].read_buf;
   }
   ivlw_debug_data[ivlw_debug_count].time = drv_get_current_time();


   ivlw_debug_data[ivlw_debug_count].free_size = 0;
   if ((IVLW_TIMER________RELEASE_1 == msg) ||
       (IVLW_TIMER________RELEASE_2 == msg) ||
       (IVLW_TIMER________RELEASE_3 == msg) ||
       (IVLW_TIMER________RELEASE_4 == msg))
   {
      ivlw_debug_data[ivlw_debug_count].free_size = free_size;
   }


   ivlw_debug_data[ivlw_debug_count].alloc_size = 0;
   if ((IVLW_TIMER________ALLOC___1 == msg) ||
       (IVLW_TIMER________ALLOC___2 == msg) ||
       (IVLW_TIMER________ALLOC___3 == msg) ||
       (IVLW_TIMER________ALLOC___4 == msg))
   {
      ivlw_debug_data[ivlw_debug_count].alloc_size = alloc_size;
   }

   ivlw_debug_count++;
   ivlw_debug_count = ivlw_debug_count & (IVLW_DBG_MSG_CNT - 1);
   RestoreIRQMask(save_irq_mask);
}



static
void _ivlw_init_internal_timer(unsigned int time_interval)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}



static
void _ivlw_timer_cb(void *parameter)
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
#endif
}



static
void _ivlw_start_internal_timer(void)
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
#endif
}



static
void _ivlw_stop_internal_timer(void)
{
   //ivle_timer_start = KAL_FALSE;
}



#else //IVLW_MEM_DBG_MSG_SUPPORT
void ivlw_dbg_trace(IVLW_DBG_MSG_ENUM msg) { }
void _ivlw_init_internal_timer(unsigned int time_interval){}
void _ivlw_start_internal_timer(void){}
void _ivlw_stop_internal_timer(void){}

#endif //IVLW_MEM_DBG_MSG_SUPPORT



static void *_ivlwDecDefaultMalloc(void *opaque, unsigned int items, unsigned int size)
{
   unsigned int total_bytes;
   void *buffer_ptr;

   if (opaque)
   {
      items += size - size;   /// make compiler happy
   }
   total_bytes = items * size;
   IVLW_MALLOC_TOTAL_SIZE_STATISTIC(total_bytes);
   buffer_ptr = get_ctrl_buffer(total_bytes);
   return buffer_ptr;
}



static void _ivlwDecDefaultFree(void *opaque, void *address)
{
   free_ctrl_buffer(address);
#if defined(IVLW_MALLOC_DEBUG)
   IVLW_MFREE_TOTAL_SIZE_STATISTIC(free_size);
#endif //IVLW_MALLOC_DEBUG
   return;
}



IVLW_DEC_STATUS
_ivlwDecDecryptBuf(
   unsigned int key,
   unsigned char *frame_buffer,
   unsigned int frame_buf_size)
{
#if defined (IVLW_ENCRYPT_HEADER)

   unsigned int i, *ptr, temp;
   if (frame_buf_size & 3)
   {
      return IVLW_DEC_STATUS_INVALID_PARA;
   }
   if (0 == key)
   {
      return IVLW_DEC_STATUS_INVALID_PARA;
   }

   frame_buf_size = frame_buf_size >> 2;
   ptr = (unsigned int*) frame_buffer;
   for (i = 0; i < frame_buf_size; i++)
   {
      temp = (*ptr) ^ (key);
      *ptr++ = IVLW_SWAP_BACK_4_3210(temp);
   }
#endif
   return IVLW_DEC_STATUS_OK;
}



IVLW_DEC_STATUS
_ivlwDecGetEncryptKey(
   IVLW_DECODER_HANDLE* handle,
   unsigned int version,
   unsigned int *key)
{
#if defined(IVLW_ENCRYPT_HEADER)
   FSAL_Status fsal_status;
   unsigned int buffer[2];
   STFSAL *fp = handle->fsal_handle;

   if (0 == version)
   {
      //Fill Encrypt Key value int the file end.
      unsigned int cur_pos;

      fsal_status = FSAL_GetCurPos(fp, &cur_pos);
      if (FSAL_OK != fsal_status)
      {
         IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecSetSrcFile: FSAL_GetCurPos Fail.\n");
         return IVLW_DEC_STATUS_FS_FAIL;
      }

      fsal_status = FSAL_Seek(fp, (handle->file_size - 4));
      if (FSAL_OK != fsal_status)
      {
         IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecSetSrcFile: FSAL_Seek Fail.\n");
         return IVLW_DEC_STATUS_FS_FAIL;
      }
      fsal_status = FSAL_Read(fp, (unsigned char*) key, 4);
      if (FSAL_OK != fsal_status)
      {
         IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecSetSrcFile: FSAL_Read Fail.\n");
         return IVLW_DEC_STATUS_FS_FAIL;
      }
      fsal_status = FSAL_Seek(fp, cur_pos);
      if (FSAL_OK != fsal_status)
      {
         IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecSetSrcFile: FSAL_Seek Fail.\n");
         return IVLW_DEC_STATUS_FS_FAIL;
      }
   }
   else if (1 == version)
   {
      fsal_status = FSAL_Seek(fp, 0);
      if (FSAL_OK != fsal_status)
      {
         IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecSetSrcFile: FSAL_Seek Fail.\n");
         return IVLW_DEC_STATUS_FS_FAIL;
      }
      fsal_status = FSAL_Read(fp, (unsigned char*) &buffer, 8);
      if (FSAL_OK != fsal_status)
      {
         IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecSetSrcFile: FSAL_Read Fail.\n");
         return IVLW_DEC_STATUS_FS_FAIL;
      }
      *key = buffer[0];
   }
   else if (1 < version)
   {
      ASSERT(0);
   }

   if (0 == *key)
   {
      IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecSetSrcFile: encrypt_key Fail.\n");
      return IVLW_DEC_STATUS_INVALID_FILE;
   }
#else
   *key = 0;
#endif //#if defined(IVLW_ENCRYPT_HEADER)
   return IVLW_DEC_STATUS_OK;
}



IVLW_DEC_STATUS
_ivlwGetVersionNum(
   IVLW_DECODER_HANDLE *handle,
   unsigned int version,
   unsigned int *key,
   IVLW_Header_FIXED_PART_Struct *fixed_header)
{
   IVLW_DEC_STATUS status;
   FSAL_Status fs_status;
   unsigned int offset = 0;

   /* V1 Modification:
   ** For V0, we put the 4 bytes key value in file tail.
   ** For V1, we move the 8 bytes key value from file tail to file head
   ** in order to enhance performance of Set Source File. (reduce one
   ** seek from file head to file tail)
   ** But because our bad design of V0: encrypt the version number, 
   ** when V1 is implement, we find we have no idea about if one file is of V0 or V1,
   ** if this file doesn't decrypte.
   ** Currently, we try from V0 to V1 and check the fixed header part value to know
   ** one file is of V0 or V1.
   */
      
   status = _ivlwDecGetEncryptKey(handle, version, key);
   if (IVLW_DEC_STATUS_OK != status)
   {
      return status;
   }

   offset = V0_IVLW_HEADER_FIXED_PART_OFFSET;
   if (1 == version)
   {
      offset = V1_IVLW_HEADER_FIXED_PART_OFFSET;
   }

   // Read FixedHeader Part
   fs_status = FSAL_Seek(handle->fsal_handle, offset);
   if (FSAL_OK != fs_status)
   {
      return IVLW_DEC_STATUS_FS_FAIL;
   }
   fs_status = FSAL_Read(handle->fsal_handle, (unsigned char*)(fixed_header), IVLW_HEADER_FIXED_PART_LEN);
   if (FSAL_OK != fs_status)
   {
      IVLW_TRACE(IVLW_MOD, "[IVLW] _ivlwParseFixHeader: FSAL_Read Fail.\n");
      return IVLW_DEC_STATUS_FS_FAIL;
   }
   status = _ivlwDecDecryptBuf(handle->encrypt_key,
                   (unsigned char*)(&handle->ivlw_header.fixed_header),
                   IVLW_HEADER_FIXED_PART_LEN);
   if (IVLW_DEC_STATUS_OK != status)
   {
      return status;
   }

   if ((0 == handle->encrypt_key) ||
     (IVLW_ALG_RSVD <= fixed_header->compress_algorithm) ||
     (IVLW_COLOR_RSVD <= fixed_header->img_format) ||
     (IVLW_MAX_IMAGE_WIDTH < fixed_header->img_width) ||
     (IVLW_MAX_IMAGE_HEIGHT < fixed_header->img_height) ||
     (IVLW_MAX_PARTITION_COUNT < fixed_header->total_partition_count) ||
     (IVLW_MAX_FRAME_COUNT < fixed_header->total_frame_count) ||
     (IVLW_COLOR_RSVD <= fixed_header->img_format))
   {
      return IVLW_DEC_STATUS_INVALID_FILE;
   }
   return IVLW_DEC_STATUS_OK;
}



IVLW_DEC_STATUS
_ivlwParseFixHeader(IVLW_DECODER_HANDLE *handle)
{
   IVLW_DEC_STATUS ivlw_status = IVLW_DEC_STATUS_OK;
   unsigned int version = 0;
   IVLW_Header_FIXED_PART_Struct *fixed_header = &handle->ivlw_header.fixed_header;

   if (handle->fix_header_parsed)
   {
      return IVLW_DEC_STATUS_OK;
   }

   /* V1 Modification:
   **
   */
   for (version = 0; version <= IVLW_ENCODER_VERSION_NUM; version++)
   {
      ivlw_status = _ivlwGetVersionNum(handle, version, &handle->encrypt_key, &handle->ivlw_header.fixed_header);
      if (IVLW_DEC_STATUS_OK == ivlw_status)
      {
         break;
      }
   }

   if (version > IVLW_ENCODER_VERSION_NUM)
   {
      return IVLW_DEC_STATUS_INVALID_FILE;
   }

   /* V1 Modification:
   ** For Prepattern of frame data:
   ** V0: 4 bytes 5C5C5C5C
   ** V1: Remove the prepattern in order to enhance FSAL read performance.
   */
   if ((IVLW_ALG_MAV == fixed_header->compress_algorithm) ||
       (IVLW_ALG_NONE == fixed_header->compress_algorithm))
   {
      // For this condition, we will read pre-pattern + source buffer in _ivlwDecGetFramePixelDataRAW()
      // and store it to destination buffer to reduce one memory copy.
      // For V1, we have removed the pre-parrern in order to enhance overall performance,
      // For V0, because customer has had generate such pattern ivlw files, we need to be backword compatible.
      // Thus, check the pre-pattern size in this function.
      
      if (0 == fixed_header->verion)
      {
         handle->src_buf_prepattern_size = V0_IVLW_PIXEL_DATA_START_PATERN_SIZE;
      }
      else if (1 == fixed_header->verion)
      {
         handle->src_buf_prepattern_size = V1_IVLW_PIXEL_DATA_START_PATERN_SIZE;
      }
      else
      {
         ASSERT(0);
      }
   }
   else
   {
      // For AB2 format, ABM can't accept the pre-pattern. It will interprete the pre-pattern
      // as ABM header. Thus we will pass the address of (the source buffer + pre-pattern size)
      // to make sure ABM decode correctly. --> No prepattern will appear in the destination buffer
      // -->set the value as 0
      handle->src_buf_prepattern_size = 0;
   }

   handle->fix_header_parsed = IVLW_TRUE;
   return IVLW_DEC_STATUS_OK;
}



IVLW_DEC_STATUS
_ivlwParsePartitionHeader(IVLW_DECODER_HANDLE *handle)
{
   IVLW_DEC_STATUS ivlw_status;
   FSAL_Status fs_status;
   unsigned int offset = 0;
   if (handle->partition_header_parsed)
   {
      return IVLW_DEC_STATUS_OK;
   }

   {
      unsigned int frame_count = 0;
      unsigned int p_count = 0;
      IVLW_Header_FIXED_PART_Struct *fixed_header = &handle->ivlw_header.fixed_header;

      if (IVLW_FALSE == handle->fix_header_parsed)
      {
         ivlw_status = _ivlwParseFixHeader(handle);
         if (IVLW_DEC_STATUS_OK != ivlw_status)
         {
            return ivlw_status;
         }
      }

      p_count = fixed_header->total_partition_count;
      if (0 == p_count)
      {
         IVLW_TRACE(IVLW_MOD, "[IVLW] _ivlwParsePartitionHeader: Error: p_count = 0\n ");
         return IVLW_DEC_STATUS_INVALID_FILE;
      }

      if (NULL == handle->ivlw_header.partition_header)
      {
         handle->ivlw_header.total_partition_header_size = IVLE_PARTITION_HEADER_SIZE * p_count;
         handle->ivlw_header.partition_header = handle->_alloc_func(NULL, 1, IVLE_PARTITION_HEADER_SIZE * p_count);
         IVLW_MFREE_SET_ALLOC_SIZE(handle->ivlw_header.total_partition_header_size);
         //ivlw_dbg_trace(IVLW_TIMER________ALLOC___1);
         if (NULL == handle->ivlw_header.partition_header)
         {
            IVLW_TRACE(IVLW_MOD, "[IVLW] _ivlwParsePartitionHeader: Error: handle->ivlw_header.partition_header == 0\n ");
            return IVLW_DEC_STATUS_MEM_UNAVAILABLE;
         }
      }
      else
      {
        //Something wrong here. Check it.
        //ASSERT(0);
      }

      // Skip FixedHeader Part
      offset = V0_IVLW_HEADER_PARTITION_PART_OFFSET;
      if (1 == handle->ivlw_header.fixed_header.verion)
      {
         offset = V1_IVLW_HEADER_PARTITION_PART_OFFSET;
      }
      fs_status = FSAL_Seek(handle->fsal_handle, offset);
      if (FSAL_OK != fs_status)
      {
         return IVLW_DEC_STATUS_FS_FAIL;
      }

      // Read PartitionHeader Part
      fs_status = FSAL_Read(handle->fsal_handle,
                   (unsigned char*)(handle->ivlw_header.partition_header),
                   IVLE_PARTITION_HEADER_SIZE * p_count);
      if (FSAL_OK != fs_status)
      {
         IVLW_TRACE(IVLW_MOD, "[IVLW] _ivlwParsePartitionHeader: FSAL_Read Error\n ");
         return IVLW_DEC_STATUS_FS_FAIL;
      }
      ivlw_status = _ivlwDecDecryptBuf(handle->encrypt_key,
                    (unsigned char*)(handle->ivlw_header.partition_header),
                    IVLE_PARTITION_HEADER_SIZE * p_count);
      if (IVLW_DEC_STATUS_OK != ivlw_status)
      {
         //IVLW_TRACE(IVLW_MOD, ("[IVLW] _ivlwParsePartitionHeader: _ivlwDecDecryptBuf Error\n ");
         return ivlw_status;
      }

      //Check Parameters
      handle->partition_header_parsed = IVLW_TRUE;
   }
   return IVLW_DEC_STATUS_OK;
}



IVLW_DEC_STATUS
_ivlwParseFrameHeader(IVLW_DECODER_HANDLE *handle)
{
   IVLW_DEC_STATUS ivlw_status;
   FSAL_Status fs_status;

   if (handle->frame_header_parsed)
   {
      return IVLW_DEC_STATUS_OK;
   }

   {
      unsigned int frame_count = 0;
      unsigned int p_count = 0;
      unsigned int offset = 0;
      IVLW_Header_FIXED_PART_Struct *fixed_header = &handle->ivlw_header.fixed_header;

      if (IVLW_FALSE == handle->partition_header_parsed)
      {
         ivlw_status = _ivlwParsePartitionHeader(handle);
         if (IVLW_DEC_STATUS_OK != ivlw_status)
         {
            IVLW_TRACE(IVLW_MOD, "[IVLW] _ivlwParseFrameHeader: _ivlwParsePartitionHeader Error\n ");
            return ivlw_status;
         }
      }
      if ((0 == fixed_header->total_partition_count)||(0 == fixed_header->total_frame_count))
      {
         IVLW_TRACE(IVLW_MOD, "[IVLW] _ivlwParseFrameHeader: Error-> PC = 0 or FC = 0\n ");
         return IVLW_DEC_STATUS_INVALID_FILE;
      }

      offset = V0_IVLW_HEADER_PARTITION_PART_OFFSET;
      if (1 == handle->ivlw_header.fixed_header.verion)
      {
         offset = V1_IVLW_HEADER_PARTITION_PART_OFFSET;
      }
      offset += IVLE_PARTITION_HEADER_SIZE * fixed_header->total_partition_count;
      frame_count = fixed_header->total_frame_count;
      if (NULL == handle->ivlw_header.frame_header)
      {
         handle->ivlw_header.total_frame_header_size = IVLE_FRAME_HEADER_SIZE * frame_count;
         handle->ivlw_header.frame_header = (IVLW_Frame_Header_Struct *) handle->_alloc_func(NULL, 1, IVLE_FRAME_HEADER_SIZE * frame_count);
         IVLW_MFREE_SET_ALLOC_SIZE(handle->ivlw_header.total_frame_header_size);
         //ivlw_dbg_trace(IVLW_TIMER________ALLOC___2);
         if (NULL == handle->ivlw_header.frame_header)
         {
            IVLW_TRACE(IVLW_MOD, "[IVLW] _ivlwParseFrameHeader: Error-> Can't get FrameHeaderBuf. Alloc fail\n ");
            return IVLW_DEC_STATUS_MEM_UNAVAILABLE;
         }
      }
      else
      {
         //something wrong here. Check it.
         //ASSERT(0);
      }


      // Read FrameHeader Part
      fs_status = FSAL_Seek(handle->fsal_handle, offset);
      if (FSAL_OK != fs_status)
      {
         return IVLW_DEC_STATUS_FS_FAIL;
      }

      fs_status = FSAL_Read(handle->fsal_handle,
                  (unsigned char*)(handle->ivlw_header.frame_header),
                  IVLE_FRAME_HEADER_SIZE * frame_count);
      if (FSAL_OK != fs_status)
      {
         IVLW_TRACE(IVLW_MOD, "[IVLW] _ivlwParseFrameHeader: Error-> FSAL_READ fail\n ");
         return IVLW_DEC_STATUS_FS_FAIL;
      }

      ivlw_status = _ivlwDecDecryptBuf(handle->encrypt_key,
                  (unsigned char*)(handle->ivlw_header.frame_header),
                  IVLE_FRAME_HEADER_SIZE * frame_count);
      if (IVLW_DEC_STATUS_OK != ivlw_status)
      {
         IVLW_TRACE(IVLW_MOD, "[IVLW] _ivlwParseFrameHeader: Error-> _ivlwDecDecryptBuf fail\n ");
         return ivlw_status;
      }

      handle->frame_header_parsed = IVLW_TRUE;
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
#endif
   return IVLW_DEC_STATUS_OK;
}




IVLW_DEC_STATUS
ivlwDecGetHandle(IVLW_DECODER_HANDLE** handlePtr)
{
   IVLW_DECODER_HANDLE *h = NULL;
   IVLW_DEC_STATUS rtn;

   IVLW_CREATE_MUTEX();
   //IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecGetHandle+ \n");

   h = (IVLW_DECODER_HANDLE*) get_ctrl_buffer(sizeof(IVLW_DECODER_HANDLE));
   if (h)
   {
      memset(h, 0, sizeof(IVLW_DECODER_HANDLE));
      rtn = IVLW_DEC_STATUS_OK;
      *handlePtr = h;
   }
   else
   {
      *handlePtr = NULL;
      rtn = IVLW_DEC_STATUS_HANDLE_UNAVAILABLE;
   }

   ivlw_current_handle = h;
   memset((*handlePtr), 0, sizeof(IVLW_DECODER_HANDLE));
   _ivlw_init_internal_timer(100); //1s
   _ivlw_start_internal_timer();

   //IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecGetHandle- \n");
   return rtn;
}



IVLW_DEC_STATUS
ivlwDecSetDecodeFunc(IVLW_DECODER_HANDLE* handle, _ivlwDecodeCodec decode_codec)
{
   if (NULL == handle)
   {
      return IVLW_DEC_STATUS_INVALID_PARA;
   }
   handle->decode_codec = decode_codec;
   return IVLW_DEC_STATUS_OK;
}



static IVLW_DEC_STATUS
_ivlwDecReleaseBuf(IVLW_DECODER_HANDLE* handle)
{
   if (NULL != handle->_free_func)
   {
#if defined(__MTK_TARGET__)
      unsigned int i;
      for (i = 0; i < IVLW_ASYNC_CMD_MAX_CNT; i++)
      {
         if (NULL != (handle)->aysnc_fs_ctrl[i].file_overlapped.buf)
         {
            while (IVLW_TRUE == (handle)->aysnc_fs_ctrl[i].occupied)
            {
               kal_sleep_task(1);
            }
            IVLW_MFREE_SET_FREE_SIZE(FS_ASYNC_WORKING_BUFFER_SIZE);
            (handle)->_free_func(NULL, (handle)->aysnc_fs_ctrl[i].file_overlapped.buf);
            (handle)->aysnc_fs_ctrl[i].file_overlapped.buf = NULL;
            ivlw_dbg_trace(IVLW_TIMER________RELEASE_1);
         }
      }
      (handle)->aysnc_fs_ctrl_init = IVLW_FALSE;

      if (NULL != (handle)->pt_fsal_seek_hint)
      {
         IVLW_MFREE_SET_FREE_SIZE(handle->fsal_seek_hint_buf_size);
         (handle)->_free_func(NULL, (void*)(handle)->pt_fsal_seek_hint);
         (handle)->pt_fsal_seek_hint = NULL;
         ivlw_dbg_trace(IVLW_TIMER________RELEASE_2);
      }
#endif //defined(__MTK_TARGET__)
      if ((handle)->ivlw_header.frame_header)
      {
         IVLW_MFREE_SET_FREE_SIZE((handle)->ivlw_header.total_frame_header_size);
         (handle)->_free_func(NULL, (handle)->ivlw_header.frame_header);
         (handle)->ivlw_header.frame_header = NULL;
         (handle)->ivlw_header.total_frame_header_size = 0;
         ivlw_dbg_trace(IVLW_TIMER________RELEASE_3);
      }
      if ((handle)->ivlw_header.partition_header)
      {
         IVLW_MFREE_SET_FREE_SIZE((handle)->ivlw_header.total_partition_header_size);
         (handle)->_free_func(NULL, (handle)->ivlw_header.partition_header);
         (handle)->ivlw_header.partition_header = NULL;
         (handle)->ivlw_header.total_partition_header_size = 0;
      }
   }
   _ivlw_stop_internal_timer();
   return IVLW_DEC_STATUS_OK;
}



static IVLW_DEC_STATUS
_ivlwDecResetBuf(IVLW_DECODER_HANDLE* handle)
{
   return _ivlwDecReleaseBuf(handle);
}



IVLW_DEC_STATUS
ivlwDecReleaseHandle(IVLW_DECODER_HANDLE** handle)
{
   IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecReleaseHandle+ \n");

   _ivlwDecReleaseBuf(*handle);
#if defined(IVLW_MALLOC_DEBUG)
   if (free_total_size != alloc_total_size)
   {
      ASSERT(0);
   }
#endif

   if ((*handle))
   {
      free_ctrl_buffer((void*) (*handle));
      *handle = NULL;
   }
   ivlw_current_handle = NULL;
   IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecReleaseHandle- \n");
   return IVLW_DEC_STATUS_OK;
}



IVLW_DEC_STATUS
_ivlwDecSetSeekHint(IVLW_DECODER_HANDLE* handle, STFSAL *fp, unsigned int file_size)
{
#if defined(__MTK_TARGET__)
    //FILE Hint is Not Supported for MODIS
    if(file_size > IVLW_FS_HINT_CNT)
    {
       IVLW_Frame_Header_Struct *frame_header;
       unsigned int frame_cnt = handle->ivlw_header.fixed_header.total_frame_count;
       unsigned int fs_cluster_sz;
       FS_FileInfo  fileInfo;
       FS_HANDLE    FileHandle;
       signed int f_idx;
       int fs_status;

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
#else
       /* V1 Modification:
        ** We remove the calling of FS_GetFileInfo and FS_GetClusterSize to enhance performance of open a IVLW file here.
        **Assume driver allocated cluster size is 32KB.
        **Then use 32KB to perform FSAL API will gain the best performance.
        **(ie. file pointer always at 32 KB offset )
        **0 > 32 > 64 > 96 > 128 > 160 > 192 > 224 > 256 > ...
        **When  Set Seek Hint ,
        **due to the defaule cluster value of Windows Format or SD Formatter will never larger than 32KB, and
        **other cluster value will satisfy the criteria: 32KB = Cluster_Size * N, thus we set cluster size to
        **be 32KB will be OK here.
        */
       fs_cluster_sz = 32 * 1024; //32KB
#endif

       frame_header = handle->ivlw_header.frame_header;
       //handle->fsal_seek_hint_cnt = frame_cnt;
       handle->fsal_seek_hint_buf_size =  frame_cnt * sizeof(FS_FileLocationHint);
       handle->pt_fsal_seek_hint = handle->_alloc_func(NULL, 1, frame_cnt * sizeof(FS_FileLocationHint));
       IVLW_MFREE_SET_ALLOC_SIZE(handle->fsal_seek_hint_buf_size);
       //ivlw_dbg_trace(handle, IVLW_TIMER________ALLOC___3);

       for (f_idx = 0; f_idx < frame_cnt; f_idx++)
       {
          handle->pt_fsal_seek_hint[f_idx].Index = (frame_header[f_idx].frame_offset/fs_cluster_sz) * fs_cluster_sz;
       }
       if (NULL != handle->pt_fsal_seek_hint)
       {
          FSAL_SetSeekHint(fp, frame_cnt, handle->pt_fsal_seek_hint);
          //if (FSAL_OK != FSAL_SetSeekHint(fp, frame_cnt, handle->pt_fsal_seek_hint))
          //{
          //   return IVLW_DEC_STATUS_FS_FAIL;
          //}
       }
   }
#endif
   return IVLW_DEC_STATUS_OK;
}



IVLW_DEC_STATUS
ivlwDecSetSrcFile(IVLW_DECODER_HANDLE* handle, STFSAL *fp)
{
   IVLW_DEC_STATUS ivlw_status = IVLW_DEC_STATUS_OK;
   if (NULL == fp)
   {
     return IVLW_DEC_STATUS_INVALID_FILE;
   }

   if ((NULL != handle->fsal_handle) ||
       (handle->ivlw_header.frame_header) ||
       (handle->ivlw_header.partition_header) ||
#if defined(__MTK_TARGET__)
       (handle->aysnc_fs_ctrl[0].file_overlapped.buf) ||
       (handle->pt_fsal_seek_hint) ||
#endif
       (0))
   {
      IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecSetSrcFile: Check Fail.\n");
      ASSERT(0);
   }
   else
   {
      if ((NULL == handle->_free_func) || (NULL == handle->_alloc_func))
      {
         handle->_alloc_func = _ivlwDecDefaultMalloc;
         handle->_free_func = _ivlwDecDefaultFree;
      }
   }
   handle->fsal_handle = fp;

   _ivlwDecReleaseBuf(handle);
   handle->fix_header_parsed = IVLW_FALSE;
   handle->partition_header_parsed = IVLW_FALSE;
   handle->frame_header_parsed = IVLW_FALSE;
   handle->ivlw_header.frame_header = NULL;
   handle->ivlw_header.partition_header = NULL;
   if ((NULL == handle->_free_func) || (NULL == handle->_alloc_func))
   {
      ASSERT(0);
   }

   /* V1 Modification:
   **
   */
   IVLW_DEC_SET_FILE_PFMC_LOG_START();
   {
      FSAL_Status fsal_status;

      fsal_status = FSAL_GetFileSize(fp, &handle->file_size);
      if (FSAL_OK != fsal_status)
      {
         IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecSetSrcFile: FSAL_GetFileSize Fail.\n");
         return IVLW_DEC_STATUS_FS_FAIL;
      }

      if (IVLW_FALSE == handle->frame_header_parsed)
      {
         ivlw_status = _ivlwParseFrameHeader(handle);
         if (ivlw_status != IVLW_DEC_STATUS_OK)
         {
            IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecSetSrcFile: Error: _ivlwParseFrameHeader.\n");
            _ivlwDecReleaseBuf(handle); //free resource here....
            goto _return;
         }
      }

      ivlw_status = _ivlwDecSetSeekHint(handle, fp, handle->file_size);
      if (IVLW_DEC_STATUS_OK != ivlw_status)
      {
         goto _return;
      }
   }
_return:
   IVLW_DEC_SET_FILE_PFMC_LOG_END();
   return ivlw_status;
}



IVLW_DEC_STATUS
ivlwDecSetAllocAndFree(
   IVLW_DECODER_HANDLE* handle,
   alloc_func alloc_func,
   free_func free_func)
{
   if ((NULL != handle->_free_func) || (NULL != handle->_alloc_func))
   {
      return IVLW_DEC_STATUS_INVALID_CALL_SEQENCE;
   }

   handle->_alloc_func = alloc_func;
   handle->_free_func = free_func;
   return IVLW_DEC_STATUS_OK;
}



IVLW_DEC_STATUS
ivlwDecQuerySrcResolution(
   IVLW_DECODER_HANDLE* handle,
   unsigned int* width,
   unsigned int* height)
{
   IVLW_DEC_STATUS status;

   if (IVLW_FALSE == handle->fix_header_parsed)
   {
      status = _ivlwParseFixHeader(handle);
      if (status != IVLW_DEC_STATUS_OK)
      {
         return status;
      }
   }
   *width = handle->ivlw_header.fixed_header.img_width;
   *height = handle->ivlw_header.fixed_header.img_height;
   return IVLW_DEC_STATUS_OK;
}



IVLW_DEC_STATUS
ivlwDecQuerySrcFileType(
   IVLW_DECODER_HANDLE* handle,
   IVLW_FILE_TYPE* file_type)
{
   IVLW_DEC_STATUS status;
   IVLW_Header_FIXED_PART_Struct *fixed_header = &handle->ivlw_header.fixed_header;

   if (IVLW_FALSE == handle->fix_header_parsed)
   {
      status = _ivlwParseFixHeader(handle);
      if (status != IVLW_DEC_STATUS_OK)
      {
         return status;
      }
   }

   switch (fixed_header->compress_algorithm)
   {
     case IVLW_ALG_AB2:
     case IVLW_ALG_NONE:
        *file_type = IVLW_FILE_TYPE_VLW; break;
     case IVLW_ALG_MAV:
        *file_type = IVLW_FILE_TYPE_MAV; break;
     default:
        *file_type = IVLW_FILE_TYPE_RSVD; break;
   }
   return IVLW_DEC_STATUS_OK;
}



IVLW_DEC_STATUS
ivlwDecQuerySrcEncodeType(
   IVLW_DECODER_HANDLE* handle,
   IVLW_ALGORITHM* encode_type)
{
   IVLW_DEC_STATUS status;
   IVLW_Header_FIXED_PART_Struct *fixed_header = &handle->ivlw_header.fixed_header;

   if (IVLW_FALSE == handle->fix_header_parsed)
   {
      status = _ivlwParseFixHeader(handle);
      if (status != IVLW_DEC_STATUS_OK)
      {
         return status;
      }
   }

   *encode_type = (fixed_header->compress_algorithm);
   return IVLW_DEC_STATUS_OK;
}



IVLW_DEC_STATUS
ivlwDecQueryFrameCount(
   IVLW_DECODER_HANDLE* handle,
   unsigned int *frameCnt)
{
   IVLW_DEC_STATUS status;

   if (IVLW_FALSE == handle->fix_header_parsed)
   {
      status = _ivlwParseFixHeader(handle);
      if (status != IVLW_DEC_STATUS_OK)
      {
         return status;
      }
   }
   *frameCnt = handle->ivlw_header.fixed_header.total_frame_count;
   return IVLW_DEC_STATUS_OK;
}



IVLW_DEC_STATUS
ivlwDecQueryPartitionCount(
   IVLW_DECODER_HANDLE* handle,
   unsigned int *partitionCnt)
{
   IVLW_DEC_STATUS status;

   if (IVLW_FALSE == handle->fix_header_parsed)
   {
      status = _ivlwParseFixHeader(handle);
      if (status != IVLW_DEC_STATUS_OK)
      {
         return status;
      }
   }
   *partitionCnt = handle->ivlw_header.fixed_header.total_partition_count;
   return IVLW_DEC_STATUS_OK;
}



IVLW_DEC_STATUS
ivlwDecQueryPartitionInfo(
   IVLW_DECODER_HANDLE* handle,
   unsigned int partitionIdx,
   unsigned int *frame_count,
   unsigned int *frame_start_index)
{
   IVLW_DEC_STATUS status;

   if (IVLW_FALSE == handle->partition_header_parsed)
   {
      status = _ivlwParsePartitionHeader(handle);
      if (status != IVLW_DEC_STATUS_OK)
      {
         return status;
      }
   }
   *frame_count = handle->ivlw_header.partition_header[partitionIdx].p_frame_count;
   *frame_start_index = handle->ivlw_header.partition_header[partitionIdx].start_frame_index;
   return IVLW_DEC_STATUS_OK;
}




IVLW_DEC_STATUS
ivlwDecQueryFrameInfo(
   IVLW_DECODER_HANDLE* handle,
   unsigned int frameIdx,
   unsigned int *frame_file_offset,
   unsigned int *frame_file_size)
{
   IVLW_DEC_STATUS status;

   if (IVLW_FALSE == handle->frame_header_parsed)
   {
      status = _ivlwParseFrameHeader(handle);
      if (status != IVLW_DEC_STATUS_OK)
      {
         return status;
      }
   }
   *frame_file_offset = handle->ivlw_header.frame_header[frameIdx].frame_offset;
   *frame_file_size = handle->ivlw_header.frame_header[frameIdx].compressed_data_size;
   return IVLW_DEC_STATUS_OK;
}



IVLW_DEC_STATUS
ivlwDecQuerySrcFrameBufSize(
   IVLW_DECODER_HANDLE* handle,
   unsigned int frame_index,
   unsigned int *buf_size)
{
   IVLW_DEC_STATUS status;
   unsigned int pattern_size;
   IVLW_Header_FIXED_PART_Struct *fixed_header = &handle->ivlw_header.fixed_header;

   if (IVLW_FALSE == handle->frame_header_parsed)
   {
      status = _ivlwParseFrameHeader(handle);
      if (status != IVLW_DEC_STATUS_OK)
      {
         return status;
      }
   }

   if ((frame_index >= fixed_header->total_frame_count) || (!buf_size))
   {
      return IVLW_DEC_STATUS_INVALID_PARA;
   }

   pattern_size = handle->src_buf_prepattern_size;
   //*buf_size = handle->ivlw_header.frame_header[frame_index].compressed_data_size + pattern_size;

   if ((IVLW_ALG_MAV == handle->ivlw_header.fixed_header.compress_algorithm)||
       (IVLW_ALG_NONE == handle->ivlw_header.fixed_header.compress_algorithm))
   {
      *buf_size = 0;
   }
   else if (IVLW_ALG_AB2 == handle->ivlw_header.fixed_header.compress_algorithm)
   {
      *buf_size = handle->ivlw_header.frame_header[frame_index].compressed_data_size + pattern_size; 
   }
   return IVLW_DEC_STATUS_OK;
}



/*
 * Query the destination frame buffer 's header length.
 *
*/
IVLW_DEC_STATUS
ivlwDecQueryFrameHeaderLength(
   IVLW_DECODER_HANDLE* handle,
   unsigned int *frame_header_len)
{
   if (!frame_header_len)
   {
      return IVLW_DEC_STATUS_INVALID_PARA;
   }
   *frame_header_len = handle->src_buf_prepattern_size;
   return IVLW_DEC_STATUS_OK;
}



IVLW_DEC_STATUS
ivlwDecSetDstFormat(
   IVLW_DECODER_HANDLE* handle,
   IVLW_COLOR_FORMAT colorFormat)
{
   if (colorFormat >= IVLW_COLOR_RSVD)
   {
      return IVLW_DEC_STATUS_INVALID_PARA;
   }
   handle->output_format = colorFormat;
   return IVLW_DEC_STATUS_OK;
}



//LWP Register callback to FS Interface for Async File Read
static signed int
_ivlwFSAsyncReadCallback(
   fs_job_id job_id,
   ivlw_int64 result,
   fs_async_callback_data_struct *data)
{
#if defined(__MTK_TARGET__) && defined(__FS_ASYNC_SUPPORT__)

   IVLW_DECODER_HANDLE *handle;
   IVLW_DEC_STATUS status;
   IVLW_ASYNC_FS_CTRL_BLOCK *paysnc_fs_ctrl = (IVLW_ASYNC_FS_CTRL_BLOCK *)data->param;
   IVLW_BOOL fabort = IVLW_FALSE; //When aborting is TRUE, caller doesn't want to recieve the callback funciton.
                                  //because from W12.11, aborting function is blocking mode.
                                  //MAUI_03150963

   //IVLW_TRACE(IVLW_MOD, "[IVLW] _ivlwFSAsyncReadCallback+ \n");
   ivlw_dbg_trace(IVLW_GET_SRC_BUF_ASYNC_CB_B);
   IVLW_DEC_ASYNC_RD_PFMC_LOG_END();

   if(NULL == paysnc_fs_ctrl)
   {
      ASSERT(0);
   }

   handle = (IVLW_DECODER_HANDLE*) paysnc_fs_ctrl->ivlw_handle;
   if (result >= 0) //success
   {
      status = IVLW_DEC_STATUS_OK;
   }
   else
   {
      status = IVLW_DEC_STATUS_FS_FAIL;
      FSAsyncReadFailCount++;
   }

   IVLW_TAKE_MUTEX();
   paysnc_fs_ctrl->occupied = IVLW_FALSE;
   //IVLW_TRACE(IVLW_MOD, "[IVLW] _ivlwFSAsyncReadCallback: %x->occupied = 0.\n", paysnc_fs_ctrl);
   if (0)
   {
      if (paysnc_fs_ctrl == &ivlw_current_handle->aysnc_fs_ctrl[0])
      {
         ivlw_dbg_trace(IVLW_UNLOCK______ASYNC_RSC0);
      }
      else if (paysnc_fs_ctrl == &ivlw_current_handle->aysnc_fs_ctrl[1])
      {
         ivlw_dbg_trace(IVLW_UNLOCK______ASYNC_RSC1);
      }
   }

   if (IVLW_TRUE == handle->aborting)
   {
      kal_set_eg_events(paysnc_fs_ctrl->event, IVLW_EVT_FSASYNC_RD_CB ,KAL_OR);
   }
   fabort = handle->aborting;
   handle->aborting = IVLW_FALSE;

   IVLW_GIVE_MUTEX();
   IVLW_TRACE(IVLW_MOD, "[IVLW] _ivlwFSAsyncReadCallback: JobID=%d. FrmIdx=%d. SrcBufAddr=%x \n", paysnc_fs_ctrl->fsal_job_id, paysnc_fs_ctrl->frame_index, paysnc_fs_ctrl->read_buf);
   if ((!fabort) && (paysnc_fs_ctrl->callback))
   {
      paysnc_fs_ctrl->callback(status, paysnc_fs_ctrl->para);
   }

   ivlw_dbg_trace(IVLW_GET_SRC_BUF_ASYNC_CB_E);

   //IVLW_TRACE(IVLW_MOD, "[IVLW] _ivlwFSAsyncReadCallback- \n");
#endif //defined(__MTK_TARGET__)
   return 1;
}



IVLW_DEC_STATUS
ivlwDecGetFrameSrcBuf(
   IVLW_DECODER_HANDLE *handle,
   IVLW_FILE_ACCESS_MODE_ENUM read_mode,
   unsigned int frame_index,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned int *actual_rd_size,
   ivlw_async_get_frame_callback  callback, //// AP register callback to LWP for Async File Read. Called when LWP's FS' Async callback is invoked.
   void *param)
{
   IVLW_DEC_STATUS status;
   IVLW_Frame_Header_Struct* frame_header = NULL;
   unsigned int frame_offset;
   unsigned int read_buffer_size;
   FSAL_Status fs_status;
   unsigned int i; //used in target
   kal_uint32 fsal_read_size = 0;
   IVLW_Header_FIXED_PART_Struct *fixed_header = &handle->ivlw_header.fixed_header;

   ivlw_dbg_trace(IVLW_GET_SRC_BUF__________B);

   IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecGetFrameSrcBuf+. SrcBuf=%x, Frm_idx=%d \n", src_buf, frame_index);
   if (handle->f_to_be_released)
   {
      ASSERT(0);
   }

   if (IVLW_FALSE == handle->frame_header_parsed)
   {
      status = _ivlwParseFrameHeader(handle);
      if (status != IVLW_DEC_STATUS_OK)
      {
         return status;
      }
   }

   // For RAW format, we modify it as always read file data in _ivlwDecGetFramePixelDataRAW(~),
   // Thus invoke callback here, and return, even if the source buffer is not NULL...
   if (((IVLW_ALG_MAV == fixed_header->compress_algorithm)||
        (IVLW_ALG_NONE == fixed_header->compress_algorithm)) /*&&
       (0 == src_buf_size)*/)
   {
      handle->current_src_buf = src_buf;
      handle->current_dec_frame_index = frame_index;
      if (actual_rd_size)
      {
         *actual_rd_size = 0;
      }
      if ((IVLW_READ_FILE_ASYNC == read_mode) && (callback))
      {
         IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecGetFrameSrcBuf: exec async callback()\n");
         callback(IVLW_DEC_STATUS_OK, param);
      }
      return IVLW_DEC_STATUS_OK;
   }

   //For RAW format file, read the image data when calling ivlwDecGetFramePixelData
   // to reduce 1 memory copy, enhancing performance.
   //The following operations are for AB2 format source file.
   if (NULL == src_buf)
   {
      return IVLW_DEC_STATUS_MEM_UNAVAILABLE;
   }


   IVLW_TAKE_MUTEX();
#if defined(__MTK_TARGET__)
   //if (0)//if (IVLW_READ_FILE_ASYNC == read_mode)
   {
      for (i = 0; i < IVLW_ASYNC_CMD_MAX_CNT; i++)
      {
         if ((handle->aysnc_fs_ctrl[i].read_buf == src_buf) &&
             (IVLW_TRUE == handle->aysnc_fs_ctrl[i].occupied))
         {
            ASSERT(0); //This read buffer is occupied by the previous request.
            break;
         }
      }
   }
#endif //defined(__MTK_TARGET__)
   handle->current_src_buf = src_buf;
   handle->current_dec_frame_index = frame_index;
   IVLW_GIVE_MUTEX();
   FSSyncReadFailCount = 0;

   if (NULL == handle->ivlw_header.frame_header)
   {
      return IVLW_DEC_STATUS_INVALID_FILE;
   }
   frame_header = &handle->ivlw_header.frame_header[frame_index];
   frame_offset = frame_header->frame_offset;

   IVLW_DEC_SEEK_PFMC_LOG_START();
   fs_status = FSAL_Seek(handle->fsal_handle, frame_offset);
   if (FSAL_OK != fs_status)
   {
      FSSyncReadFailCount++;
      IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecGetFrameSrcBuf: FSAL_Seek Fail. Return.\n");
      IVLW_DEC_SEEK_PFMC_LOG_END();
      return IVLW_DEC_STATUS_FS_FAIL;
   }
   IVLW_DEC_SEEK_PFMC_LOG_END();

   read_buffer_size = frame_header->compressed_data_size;
   fsal_read_size = read_buffer_size + handle->src_buf_prepattern_size;
   if (src_buf_size < fsal_read_size)
   {
      IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecGetFrameSrcBuf: src_buf_size < read_buffer_size. Return.\n");
      return IVLW_DEC_STATUS_INVALID_PARA;
   }


#if !defined(IVLW_DECODER_STANDALONE)
   {
      if (IVLW_READ_FILE_SYNC == read_mode)
      {
         IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecGetFrameSrcBuf: fs_sync_read.\n");
         ivlw_dbg_trace(IVLW_GET_SRC_BUF_______SYNC);

         IVLW_DEC_SYNC_RD_PFMC_LOG_START();
         IVLW_SWLA_DEBUG("VRD", 1);
         fs_status = FSAL_Read(handle->fsal_handle, src_buf, fsal_read_size);
         IVLW_SWLA_DEBUG("VRD", 0);
         IVLW_DEC_SYNC_RD_PFMC_LOG_END();

         if (FSAL_OK != fs_status)
         {
            FSSyncReadFailCount++;
            return IVLW_DEC_STATUS_FS_FAIL;
         }
         if(actual_rd_size)
         {
           *actual_rd_size = fsal_read_size;
         }
      }
#if defined(__MTK_TARGET__) && defined(__FS_ASYNC_SUPPORT__)
      else
      {
         kal_int32 ret;
         IVLW_ASYNC_FS_CTRL_BLOCK *paysnc_fs_ctrl = NULL;
         ivlw_dbg_trace(IVLW_GET_SRC_BUF______ASYNC);

         IVLW_SWLA_DEBUG("VR0", 1);
         if (!handle->aysnc_fs_ctrl_init)
         {
            for (i = 0; i < IVLW_ASYNC_CMD_MAX_CNT; i++)
            {
               if (NULL == handle->aysnc_fs_ctrl[i].file_overlapped.buf)
               {
                  handle->aysnc_fs_ctrl[i].file_overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
                  handle->aysnc_fs_ctrl[i].file_overlapped.buf = handle->_alloc_func(NULL, 1, FS_ASYNC_WORKING_BUFFER_SIZE);
                  IVLW_MFREE_SET_ALLOC_SIZE(FS_ASYNC_WORKING_BUFFER_SIZE);
                  //ivlw_dbg_trace(IVLW_TIMER________ALLOC___4);

                  if (NULL == handle->aysnc_fs_ctrl[i].file_overlapped.buf)
                  {
                     ASSERT(0);
                     return IVLW_DEC_STATUS_MEM_UNAVAILABLE;
                  }
               }
            }
            handle->aysnc_fs_ctrl[0].event = kal_create_event_group("IVLW_0");
            handle->aysnc_fs_ctrl[1].event = kal_create_event_group("IVLW_1");
            if ((!handle->aysnc_fs_ctrl[0].event) || (!handle->aysnc_fs_ctrl[1].event))
            {
               ASSERT(0);
               return IVLW_DEC_STATUS_MEM_UNAVAILABLE;
            }
            handle->aysnc_fs_ctrl_init = IVLW_TRUE;
         }

         {
            IVLW_TAKE_MUTEX();
            for (i = 0; i < IVLW_ASYNC_CMD_MAX_CNT; i++)
            {
               if (IVLW_FALSE == handle->aysnc_fs_ctrl[i].occupied)
               {
                  paysnc_fs_ctrl = &handle->aysnc_fs_ctrl[i];
                  //IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecGetFrameSrcBuf: %x->occupied = 1.\n", paysnc_fs_ctrl);
                  paysnc_fs_ctrl->occupied = IVLW_TRUE;
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
                  #endif //debug only
                  paysnc_fs_ctrl->frame_index = frame_index;
                  kal_set_eg_events(paysnc_fs_ctrl->event, 0, KAL_AND);
                  break;
               }
            }
            IVLW_GIVE_MUTEX();

            if (NULL == paysnc_fs_ctrl)
            {
               ASSERT(0);
               return IVLW_DEC_STATUS_ASYNC_RD_CMD_UNAVAILABLE;
            }

            paysnc_fs_ctrl->ivlw_handle = (void*) handle;
            if (callback)
            {
               paysnc_fs_ctrl->callback = callback;
               paysnc_fs_ctrl->para = param;
            }
            else
            {
               if (IVLW_READ_FILE_ASYNC == read_mode)
               {
                  IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecGetFrameSrcBuf: callback Null, Return.\n");
                  return IVLW_DEC_STATUS_INVALID_PARA;
               }
            }
         }
         IVLW_SWLA_DEBUG("VR0", 0);

         IVLW_DEC_ASYNC_RD_PFMC_LOG_START();
         IVLW_SWLA_DEBUG("VR1", 1);
         paysnc_fs_ctrl->read_buf = src_buf;
         paysnc_fs_ctrl->file_overlapped.callback = (fs_async_callback) _ivlwFSAsyncReadCallback;
         paysnc_fs_ctrl->file_overlapped.param = (void*) paysnc_fs_ctrl;
         paysnc_fs_ctrl->file_overlapped.priority_value = 146;
         paysnc_fs_ctrl->file_overlapped.response_flag = FS_RESPONSE_CALLBACK;
         paysnc_fs_ctrl->file_overlapped.priority = FS_PRIORITY_ASSIGN; //FS_PRIORITY_DEFAULT;

         //MAUI_03206033
         //The 4th parameter of fs_async_read_interleave may be referenced in abort function.
         //If we want to get the information, we need to pass a global variable to this function.
         //otherwise, memory cruption might occur due variable life cycle problem.
         //when abort function access this address, the variable had has been released ....
         paysnc_fs_ctrl->fsal_job_id = fs_async_read_interleave(
                             handle->fsal_handle->hFile, src_buf, fsal_read_size,
                             NULL, IVLW_FS_ASYNC_RD_BLOCK_SZ,
                             &paysnc_fs_ctrl->file_overlapped);
         IVLW_SWLA_DEBUG("VR1", 0);
         IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecGetFrameSrcBuf: fs_async_read. JobID=%d. FrmIdx=%d\n", paysnc_fs_ctrl->fsal_job_id, paysnc_fs_ctrl->frame_index);
         if (paysnc_fs_ctrl->fsal_job_id < 0)
         {
            IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecGetFrameSrcBuf: fs_async_read. JobID Error\n");
            return IVLW_DEC_STATUS_FS_FAIL;
         }
         if(actual_rd_size)
         {
           *actual_rd_size = fsal_read_size;
         }
      }
#else //defined(__MTK_TARGET__) && defined(__FS_ASYNC_SUPPORT__)
      else
      {
         //FS not support async read.
         return IVLW_DEC_STATUS_FS_ASYNC_NOT_SUPPORT;
      }
#endif //defined(__MTK_TARGET__) && defined(__FS_ASYNC_SUPPORT__)
   }
#else //#if defined(IVLW_DECODER_STANDALONE)
   {
    fs_status = FSAL_Read(handle->fsal_handle, src_buf, fsal_read_size);

      if (FSAL_OK != fs_status)
      {
         return IVLW_DEC_STATUS_FS_FAIL;
      }
      if (actual_rd_size)
      {
         *actual_rd_size = fsal_read_size;
      }
      if (IVLW_READ_FILE_ASYNC == read_mode)
      {
         _ivlwFSAsyncReadCallback(0, 1, (void*)handle);
      }
   }
#endif

   //IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecGetFrameSrcBuf- \n");
   ivlw_dbg_trace(IVLW_GET_SRC_BUF__________E);

   return IVLW_DEC_STATUS_OK;
}



IVLW_DEC_STATUS
ivlwDecAbortGetFrameSrcBuf(IVLW_DECODER_HANDLE *handle)
{
#if defined(__MTK_TARGET__) && defined(__FS_ASYNC_SUPPORT__)
    signed int abort_status;
    unsigned int i;
    IVLW_ASYNC_FS_CTRL_BLOCK  *paysnc_fs_ctrl = 0;
    unsigned int frame_idx = handle->current_dec_frame_index;
    kal_uint32 event_group;
    //kal_uint32 time_interval = 100; // 1000ms

    //IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecAbortGetFrameSrcBuf+ \n");
    ivlw_dbg_trace(IVLW_GET_SRC_BUF____ABORT_B);

    if (handle->f_to_be_released)
    {
       ASSERT(0);
    }

    for (i = 0; i < IVLW_ASYNC_CMD_MAX_CNT; i++)
    {
       if (frame_idx == handle->aysnc_fs_ctrl[i].frame_index)
       {
          paysnc_fs_ctrl = &handle->aysnc_fs_ctrl[i];
          break;
       }
    }
    if (NULL == paysnc_fs_ctrl)
    {
       ASSERT(0);
       //something wrong here... check it.
    }

    IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecAbortGetFrameSrcBuf: job_id = %d, src_buf=%x\n", paysnc_fs_ctrl->fsal_job_id, paysnc_fs_ctrl->read_buf);
    abort_status = fs_async_abort_ex(paysnc_fs_ctrl->fsal_job_id, paysnc_fs_ctrl->file_overlapped.buf);
    IVLW_TAKE_MUTEX();
    handle->aborting = IVLW_TRUE;
    IVLW_GIVE_MUTEX();
    if (FS_ERR_INVALID_JOB_ID == abort_status )
    {
       ASSERT(0);
    }

    if ((abort_status != FS_NO_ERROR) && (abort_status != FS_ERR_ASYNC_JOB_NOT_FOUND))
    {
       //IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecAbortGetFrameSrcBuf: Fail\n");
       //return IVLW_DEC_STATUS_ABORT_FAIL;
       //This jpb has been finished.
       IVLW_TAKE_MUTEX();
       handle->aborting = IVLW_FALSE;
       IVLW_GIVE_MUTEX();
       ivlw_dbg_trace(IVLW_GET_SRC_BUF____ABORT_F);
    }
    else
    {
       //blocking waiting for abort finish.
       kal_retrieve_eg_events(paysnc_fs_ctrl->event, IVLW_EVT_FSASYNC_RD_CB,
                              KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
       //kal_retrieve_eg_events_timeout(paysnc_fs_ctrl->event, IVLW_EVT_FSASYNC_RD_CB,
       //                       KAL_OR_CONSUME, &event_group, KAL_TICKS_100_MSEC);
    }

    ivlw_dbg_trace(IVLW_GET_SRC_BUF____ABORT_E);

    IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecAbortGetFrameSrcBuf- \n");
#endif //#if defined(__MTK_TARGET__) && defined(__FS_ASYNC_SUPPORT__)
  return IVLW_DEC_STATUS_OK;
}



static IVLW_DEC_STATUS
_ivlwDecGetFramePixelDataRAW(
   IVLW_DECODER_HANDLE *handle,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned char* dstBuf,
   unsigned int dst_buf_size)
{
   IVLW_Header_FIXED_PART_Struct *fixed_header = &handle->ivlw_header.fixed_header;
   IVLW_Frame_Header_Struct* frame_header = NULL;
   unsigned int frame_offset, pattern_size;
   FSAL_Status fs_status;
   unsigned char* real_dst_addr;

   if ((IVLW_ALG_MAV != fixed_header->compress_algorithm) &&
        (IVLW_ALG_NONE != fixed_header->compress_algorithm))
   {
      return IVLW_DEC_STATUS_INVALID_PARA;
   }

   /* V1 Modification:
   ** To reduce one memory copy from source buffer to destination budder for RAW format,
   ** we move the FSAL read from ivlwDecGetFrameSrcBuf(~) to this function.
   */
   real_dst_addr = dstBuf;
   //For FSAL read performance, non-cachable buffer is better than cahchable buffer.
   {
      unsigned int current_dec_frame_index;
      unsigned int fsal_read_size;
      IVLW_TAKE_MUTEX();
      current_dec_frame_index = handle->current_dec_frame_index;
      IVLW_GIVE_MUTEX();

      IVLW_TRACE(IVLW_MOD, "[IVLW] _ivlwDecGetFramePixelDataRAW: fs_sync_read. current_dec_frame_index%d\n", handle->current_dec_frame_index);
      ivlw_dbg_trace(IVLW_GET_SRC_BUF_______SYNC);

      frame_header = &handle->ivlw_header.frame_header[current_dec_frame_index];
      frame_offset = frame_header->frame_offset;

      /* V1 Modification:
      ** Every frame offset of V1 is 32K alignment in order to enhance FSAL read performance.
      ** Don't seek to (frame_offset + V0_IVLW_PIXEL_DATA_START_PATERN_SIZE) because 
      ** the offset address will violate 32K alignment, and degrade FSAL performance.
      */
      fs_status = FSAL_Seek(handle->fsal_handle, frame_offset);
      if (FSAL_OK != fs_status)
      {
         FSSyncReadFailCount++;
         IVLW_TRACE(IVLW_MOD, "[IVLW] _ivlwDecGetFramePixelDataRAW: FSAL_Seek Fail. Return.\n");
         return IVLW_DEC_STATUS_FS_FAIL;
      }

      fsal_read_size = frame_header->compressed_data_size + handle->src_buf_prepattern_size;
      if (dst_buf_size < fsal_read_size)
      {
         IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecGetFrameSrcBuf: dst_buf_size < fsal_read_size. Return.\n");
         return IVLW_DEC_STATUS_INVALID_PARA;
      }
      IVLW_SWLA_DEBUG("VRD", 1);
      fs_status = FSAL_Read(handle->fsal_handle, real_dst_addr, fsal_read_size);
      IVLW_SWLA_DEBUG("VRD", 0);
      if (FSAL_OK != fs_status)
      {
         FSSyncReadFailCount++;
         return IVLW_DEC_STATUS_FS_FAIL;
      }
   }

   if ((IVLW_COLOR_RGB888 == fixed_header->img_format) &&
       (IVLW_COLOR_RGB565 == handle->output_format))
   {
      //transform RGB888 to RGB565
      unsigned int i, j;
      unsigned char R,G,B;
      unsigned short *dstptr;

      real_dst_addr = dstBuf;
#if defined(__IVLW_SWITCH_SRC_BUF_TO_CACHABLE_BUFFER__)
      IVLW_DEC_SWITCH_VALIDATE_BUF_PFMC_LOG_START();
      real_dst_addr = (unsigned char*)phys_to_virt(dstBuf);
      clean_and_invalidate_dcache((unsigned int)real_dst_addr, (unsigned int)(dst_buf_size / 32) * 32);
      IVLW_DEC_SWITCH_VALIDATE_BUF_PFMC_LOG_END();
#endif

      dstptr = (unsigned short *)real_dst_addr;
      for (i = 0; i < fixed_header->img_width; i++)
      {
         for (j = 0; j < fixed_header->img_height; j++)
         {
            R = *real_dst_addr++;
            G = *real_dst_addr++;
            B = *real_dst_addr++;
            *dstptr++ = IVLW_RGB888_TO_RGB565(R,G,B);
         }
      }
   }
   else if ((IVLW_COLOR_RGB565 == fixed_header->img_format) &&
            (IVLW_COLOR_RGB888 == handle->output_format))
   {
      // to do. with dither.
      ASSERT(0);
   }
   else
   {
      /* V1 Modification:
      ** Reduce one memory copy from source buffer to destination budder for RAW format.
      */
      //memcpy(dstBuf, src_buf, src_buf_size);
   }
   return IVLW_DEC_STATUS_OK;
}



static IVLW_DEC_STATUS
_ivlwDecGetFramePixelDataAB2(
   IVLW_DECODER_HANDLE *handle,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned char* dstBuf,
   unsigned int dst_buf_size)
{
#if defined(IVLW_DECODER_STANDALONE)
   int ret = 0;
   gdi_image_ab2_info_struct info;
   gdi_image_ab2_img_buf_struct img_buf;

   IVLW_SWLA_DEBUG("VLW", 1);
   gdi_image_ab2_read_header(&info, src_buf);
   img_buf.pixel_bytes = 2;
   img_buf.cf = GDI_COLOR_FORMAT_16;
   if (IVLW_COLOR_RGB888 == handle->output_format)
   {
      img_buf.pixel_bytes = 3;
      img_buf.cf = GDI_COLOR_FORMAT_24;
   }
   img_buf.ptr = (U8 *)dstBuf;
   img_buf.pitch_bytes = info.width * img_buf.pixel_bytes;

   /* gdi_image_ab2_draw_to_buf_internal
   ** This function will process BMP R/B channel swap. Thus for AB2 encoder part,
   ** we don't need to do R/B channel swap. Otherwise, the output result will be wrong.
   */
   ret = gdi_image_ab2_draw_to_buf_decode_mode(&img_buf,
                              0, 0, src_buf,
                              GDI_IMAGE_AB2_DECODE_MODE_OUTPUT);
   IVLW_SWLA_DEBUG("VLW", 0);
#if defined(IVLW_DECODER_STANDALONE)
   if (MMI_TRUE != ret)
#else
   if (GDI_SUCCEED != ret)
#endif
   {
      IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecGetFramePixelData: Decode Fail\n");
      return IVLW_DEC_STATUS_FAIL;
   }
#endif
   return IVLW_DEC_STATUS_OK;
}



IVLW_DEC_STATUS
ivlwDecGetFramePixelData(
   IVLW_DECODER_HANDLE *handle,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned char* dstBuf,
   unsigned int dst_buf_size)
{
   IVLW_DEC_STATUS status = IVLW_DEC_STATUS_OK;
   IVLW_ALGORITHM compress_algorithm;
   unsigned int pattern_len = 0;
   unsigned int real_src_buf_sizs = 0;

   IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecGetFramePixelData+. SrcBuf=%x\n", src_buf);
   ivlw_dbg_trace(IVLW_GET_FRM_DTA__________B);

   if (handle->f_to_be_released)
   {
      ASSERT(0); //re-entry
   }

   if (IVLW_FALSE == handle->frame_header_parsed)
   {
      status = _ivlwParseFrameHeader(handle);
      if (status != IVLW_DEC_STATUS_OK)
      {
         return status;
      }
   }

   if ((NULL == handle->_alloc_func) || (NULL == handle->_free_func))
   {
      return IVLW_DEC_STATUS_INVALID_PARA; //ASSERT(0);
   }


   /* V1 Modification:
   ** Modificatio due to reduction of one memory copy from source 
   ** buffer to destination budder for RAW format.
   */
   compress_algorithm = handle->ivlw_header.fixed_header.compress_algorithm;
   if ((IVLW_ALG_MAV != compress_algorithm)&&
       (IVLW_ALG_NONE != compress_algorithm) &&
       (NULL == src_buf))
   {
      return IVLW_DEC_STATUS_INVALID_PARA; //ASSERT(0);
   }

#if defined(__MTK_TARGET__) && defined(__FS_ASYNC_SUPPORT__)
   IVLW_TAKE_MUTEX();
   if (1)
   {
      unsigned int i;
      for (i = 0; i < IVLW_ASYNC_CMD_MAX_CNT; i++)
      {
         if ((handle->aysnc_fs_ctrl[i].read_buf == src_buf) &&
             (IVLW_TRUE == handle->aysnc_fs_ctrl[i].occupied))
         {
            ASSERT(0); //This src buffer is not ready
            return IVLW_DEC_STATUS_ABORTED_SRC_CONTENT;            
         }
      }
   }
   IVLW_GIVE_MUTEX();
#endif //defined(__MTK_TARGET__) && defined(__FS_ASYNC_SUPPORT__)

   if (FSSyncReadFailCount)
   {
      IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecGetFramePixelData. Error: The SrcBuf is invalid.\n");
      //ASSERT(0);
   }


   IVLW_DEC_PFMC_LOG_START();
   if ((IVLW_ALG_MAV == compress_algorithm)||
       (IVLW_ALG_NONE == compress_algorithm))
   {
      status = _ivlwDecGetFramePixelDataRAW(handle, src_buf, src_buf_size, dstBuf, dst_buf_size);
   }
   else if (IVLW_ALG_AB2 == handle->ivlw_header.fixed_header.compress_algorithm)
   {
      //switch non-catchable source buffer to catchable buffer to enhance decode performance
      unsigned char* catch_src_buffer;

      //remove the source frame prepattern for AB2 format.
      if (0 == handle->ivlw_header.fixed_header.verion)
      {
        pattern_len = V0_IVLW_PIXEL_DATA_START_PATERN_SIZE;
      }
      else
      {
        pattern_len = V1_IVLW_PIXEL_DATA_START_PATERN_SIZE;
      }
      real_src_buf_sizs = (src_buf_size - pattern_len);

      catch_src_buffer = src_buf;
#if defined(__IVLW_SWITCH_SRC_BUF_TO_CACHABLE_BUFFER__)
      IVLW_DEC_SWITCH_VALIDATE_BUF_PFMC_LOG_START();
      catch_src_buffer = (unsigned char*)phys_to_virt(src_buf);
      clean_and_invalidate_dcache((unsigned int)catch_src_buffer, (unsigned int)( src_buf_size / 32) * 32);
      IVLW_DEC_SWITCH_VALIDATE_BUF_PFMC_LOG_END();
#endif

#if defined(IVLW_DECODER_STANDALONE)
      _ivlwDecGetFramePixelDataAB2(handle, catch_src_buffer + pattern_len, real_src_buf_sizs , dstBuf, dst_buf_size);
#else
      status = handle->decode_codec(handle, catch_src_buffer + pattern_len, real_src_buf_sizs , dstBuf, dst_buf_size);
#endif
   }
   IVLW_DEC_PFMC_LOG_END();

   ivlw_dbg_trace(IVLW_GET_FRM_DTA__________E);
   if (status != IVLW_DEC_STATUS_OK)
   {
      return status;
   }

   IVLW_TRACE(IVLW_MOD, "[IVLW] ivlwDecGetFramePixelData- \n");
   return IVLW_DEC_STATUS_OK;
}



