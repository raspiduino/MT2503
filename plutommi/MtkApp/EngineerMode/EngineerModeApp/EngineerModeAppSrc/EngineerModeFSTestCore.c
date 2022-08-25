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
 *   EngineerModeFSTestCore.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements all interface used for FS Test Core
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"

#include "kal_trace.h"
#include "fsal.h"
#include "MMI_include.h"

#if ( defined (__MMI_EM_PROFILING_FS_TEST__) && !defined(FMT_NOT_PRESENT) && !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__))
#include "EngineerModeFSTestCore.h"
#include "FileMgrSrvGProt.h"

#define FMT_CASE_NUM(case_type) (sizeof(case_type)/sizeof(mmi_em_fs_test_fmt_test_case_struct))

#define FMT_TEST_CASE_RUN(test_case,case_index,result)     \
    test_case[case_index].handler(                         \
    test_case[case_index].block_size,                      \
    test_case[case_index].op_times,                        \
    result,                                                \
    test_case[case_index].result_length,                   \
test_case[case_index].op)

#define FMT_TEST_COMMON_LONG_FILE_PREFIX        L"fs_test_long_file_"

#define FMT_TEST_COMMON_LONG_FILE_EXT           L".xls"

#define FMT_TEST_COMMON_DIR_NAME_PREFIX         L"fs_test_dir_"

#define FMT_TEST_FIND_DIR_NAME_PREFIX           L"find_fs_test_dir"

#define FMT_TEST_FIND_LONG_FILE_PREFIX          L"find_fs_test_file_"

#define FMT_TEST_DIRTY_DIR_NAME_PREFIX          L"Dirty_fs_testdir_"

#define FMT_TEST_DIRTY_LONG_FILE_NAME_PREFIX    L"Dirty_fs_test_file_"

#define FMT_FS_TEST_MEM_POOL_SIZE               (1024*32)       /* 32KB */

kal_uint8 *g_data_buffer;

mmi_em_fs_test_fmt_conext_struct g_fmt_test_context;

mmi_em_fs_test_fmt_finish_iln_struct test_result_struct;

WCHAR g_fmt_dir_name[MMI_EM_FS_TEST_FMT_MAX_PATH_LEN];
WCHAR g_fmt_file_name[MMI_EM_FS_TEST_FMT_MAX_PATH_LEN];

extern kal_bool mmi_em_fs_test_fmt_test_case_write_read(
                    kal_uint32 block_size,
                    kal_uint32 op_times,
                    kal_uint32 *result,
                    kal_uint32 result_length,
                    mmi_em_fs_test_fmt_op_enum op);
extern kal_bool mmi_em_fs_test_fmt_test_case_delete(
                    kal_uint32 block_size,
                    kal_uint32 op_times,
                    kal_uint32 *result,
                    kal_uint32 result_length,
                    mmi_em_fs_test_fmt_op_enum op);
extern kal_bool mmi_em_fs_test_fmt_test_case_write_flush(
                    kal_uint32 block_size,
                    kal_uint32 op_times,
                    kal_uint32 *result,
                    kal_uint32 result_length,
                    mmi_em_fs_test_fmt_op_enum op);
extern kal_bool mmi_em_fs_test_fmt_test_case_read_sleep(
                    kal_uint32 block_size,
                    kal_uint32 op_times,
                    kal_uint32 *result,
                    kal_uint32 result_length,
                    mmi_em_fs_test_fmt_op_enum op);
extern kal_bool mmi_em_fs_test_fmt_test_case_scenario(
                    kal_uint32 block_size,
                    kal_uint32 op_times,
                    kal_uint32 *result,
                    kal_uint32 result_length,
                    mmi_em_fs_test_fmt_op_enum op);

#if defined(__MMI_EM_PROFILING_FS_TEST_FS_SEEK__)
extern kal_bool mmi_em_fs_test_fmt_test_case_seek(
                    kal_uint32 block_size,
                    kal_uint32 op_times,
                    kal_uint32 *result,
                    kal_uint32 result_length,
                    mmi_em_fs_test_fmt_op_enum op);
#endif /* defined(__MMI_EM_PROFILING_FS_TEST_FS_SEEK__) */ 

extern kal_bool mmi_em_fs_test_fmt_test_case_find(
                    kal_uint32 block_size,
                    kal_uint32 op_times,
                    kal_uint32 *result,
                    kal_uint32 result_length,
                    mmi_em_fs_test_fmt_op_enum op);
extern kal_bool mmi_em_fs_test_fmt_test_case_write_read_cache(
                    kal_uint32 block_size,
                    kal_uint32 buffer_size,
                    kal_uint32 *result,
                    kal_uint32 result_length,
                    mmi_em_fs_test_fmt_op_enum op);

/* base test case */
/* base test will read or write a 16K file */
static const mmi_em_fs_test_fmt_test_case_struct fmt_basic_test_case[] = 
{
#if defined(__MMI_EM_PROFILING_FS_TEST_FS_BASIC_RW_TIMES__)
    {mmi_em_fs_test_fmt_test_case_write_read, 8, 100, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 128, 100, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 1024, 100, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 2048, 100, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 16384, 100, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 32768, 100, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
#else /* defined(__MMI_EM_PROFILING_FS_TEST_FS_BASIC_RW_TIMES__) */ 
    {mmi_em_fs_test_fmt_test_case_write_read, 8, 4096, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 128, 256, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 1024, 32, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 2048, 16, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 16384, 2, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 32768, 1, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
#endif /* defined(__MMI_EM_PROFILING_FS_TEST_FS_BASIC_RW_TIMES__) */ 

#if defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
    , {mmi_em_fs_test_fmt_test_case_write_read, 16384, 1024, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
#endif 
    , {mmi_em_fs_test_fmt_test_case_delete, 16777216, 1, 1, MMI_EM_FS_TEST_FMT_OP_DELETE}
};

/* normal test case */
static const mmi_em_fs_test_fmt_test_case_struct fmt_normal_test_case[] = 
{
#if defined(__MMI_EM_PROFILING_FS_TEST_FS_BASIC_RW_TIMES__)
    /* read and write a 32K file */
    {mmi_em_fs_test_fmt_test_case_write_read, 8, 100, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 128, 100, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 1024, 100, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 2048, 100, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 16384, 100, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 32768, 100, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
#else /* defined(__MMI_EM_PROFILING_FS_TEST_FS_BASIC_RW_TIMES__) */ 
    {mmi_em_fs_test_fmt_test_case_write_read, 8, 4096, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 128, 256, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 1024, 32, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 2048, 16, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 16384, 2, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read, 32768, 1, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
#endif /* defined(__MMI_EM_PROFILING_FS_TEST_FS_BASIC_RW_TIMES__) */ 
#if defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
    /* read and write a 16M file */
    , {mmi_em_fs_test_fmt_test_case_write_read, 16384, 1024, 2, MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
#endif /* defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__) */ 
    , {mmi_em_fs_test_fmt_test_case_delete, 16777216, 1, 1, MMI_EM_FS_TEST_FMT_OP_DELETE}

    , {mmi_em_fs_test_fmt_test_case_write_flush, 128, 1000, 2, MMI_EM_FS_TEST_FMT_OP_NORMAL}
    , {mmi_em_fs_test_fmt_test_case_read_sleep, 512, 1000, 2, MMI_EM_FS_TEST_FMT_OP_NORMAL}
    , {mmi_em_fs_test_fmt_test_case_scenario, 512, 1000, 1, MMI_EM_FS_TEST_FMT_OP_NORMAL}

#if defined(__MMI_EM_PROFILING_FS_TEST_FS_SEEK__)
    /* seek a file in full disk scenario */
    , {mmi_em_fs_test_fmt_test_case_seek, 0, 1, 6, MMI_EM_FS_TEST_FMT_OP_NORMAL}

    /* seek a 5M file */
    , {mmi_em_fs_test_fmt_test_case_seek, 5242880, 1, 6, MMI_EM_FS_TEST_FMT_OP_NORMAL}
#endif /* defined(__MMI_EM_PROFILING_FS_TEST_FS_SEEK__) */ 
};

/* advance test case */
static const mmi_em_fs_test_fmt_test_case_struct fmt_advance_test_case[] = 
{

    {mmi_em_fs_test_fmt_test_case_find, 0, 1, 2, MMI_EM_FS_TEST_FMT_OP_NORMAL},

    /* read and write a 16M file */
    {mmi_em_fs_test_fmt_test_case_write_read_cache, 32, 1024, 2,
     MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 32, 2048, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 32, 4096, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 32, 8192, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 32, 16384, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}

    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 512, 1024, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 512, 2048, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 512, 4096, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 512, 8192, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 512, 16384, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}

    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 2048, 1024, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 2048, 2048, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 2048, 4096, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 2048, 8192, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 2048, 16384, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}

    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 16384, 1024, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 16384, 2048, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 16384, 4096, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 16384, 8192, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
    , {mmi_em_fs_test_fmt_test_case_write_read_cache, 16384, 16384, 2,
       MMI_EM_FS_TEST_FMT_OP_READ | MMI_EM_FS_TEST_FMT_OP_WRITE}
};

static void mmi_em_fs_test_fmt_test_send_start_rsp_msg_to_mmi(void);

static void mmi_em_fs_test_fmt_test_send_finish_msg_to_mmi(mmi_em_fs_test_fmt_finish_iln_struct *data);

static void mmi_em_fs_test_fmt_test_send_save_finish_to_mmi(MMI_EM_FS_TEST_FMT_SAVE_RESULT_ENUM error_code);

static kal_bool mmi_em_fs_test_fmt_test_make_disk_dirty(kal_uint8 driver, kal_uint8 dirty_rate);

static kal_bool mmi_em_fs_test_fmt_test_erase_disk_dirty(kal_uint8 driver);

static void mmi_em_fs_test_fmt_test_erase_all_dirty_disks(void);

static kal_bool mmi_em_fs_test_fmt_test_get_disk_info(
                    kal_uint8 driver,
                    mmi_em_fs_test_fmt_disk_info_struct *disk_info);

static kal_bool mmi_em_fs_test_fmt_test_start_pre_handler(mmi_em_fs_test_fmt_start_req_struct *msg);

static void mmi_em_fs_test_fmt_test_start_handler_int(void);

static void mmi_em_fs_test_fmt_test_start_post_handler(void);

static void mmi_em_fs_test_fmt_test_cancel_handler_int(void);

static void mmi_em_fs_test_fmt_test_send_cancel_rsp_msg_to_mmi(void);

static kal_bool mmi_em_fs_test_fmt_test_create_file(const WCHAR *file_name, UINT flag, kal_uint32 size);

static kal_uint32 mmi_em_fs_test_fmt_test_get_time(void);


volatile int mmi_em_fs_test_mutex_cnt = 0;
volatile module_type mmi_em_fs_test_mutex_tid = MOD_NIL;

kal_mutexid g_mmi_em_fs_test_mutex;

/*****************************************************************************
 * FUNCTION
 *  jui_lcd_mutex_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_fs_test_mutex_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GDI_LOCK; */
    if (stack_int_get_active_module_id() != mmi_em_fs_test_mutex_tid)
    {
        kal_take_mutex(g_mmi_em_fs_test_mutex);
        mmi_em_fs_test_mutex_tid = stack_int_get_active_module_id();
    }
    ++mmi_em_fs_test_mutex_cnt;

}


/*****************************************************************************
 * FUNCTION
 *  jui_lcd_mutex_unlock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_fs_test_mutex_unlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mmi_em_fs_test_mutex_tid == stack_int_get_active_module_id());

    --mmi_em_fs_test_mutex_cnt;

    if (mmi_em_fs_test_mutex_cnt == 0)
    {
        mmi_em_fs_test_mutex_tid = MOD_NIL;
        kal_give_mutex(g_mmi_em_fs_test_mutex);
    }
    /* GDI_UNLOCK; */
}


void mmi_em_fs_test_engine_init()
{
    g_mmi_em_fs_test_mutex = kal_create_mutex("fs test");
}
/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_em_fs_test_fmt_test_init()
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_FMT,"[FMT]Entry test init"); */

    g_fmt_test_context.engine_status = MMI_EM_FS_TEST_FMT_ENGINE_STATUS_INIT;
    g_fmt_test_context.dirty_rate = 25;

    g_data_buffer = NULL;

    /* kal_prompt_trace(MOD_FMT,"[FMT]Test Init sucess"); */

    return KAL_TRUE;

}

void mmi_em_fs_test_set_engine_status(mmi_em_fs_test_fmt_engine_status_enum  status)
{
    mmi_em_fs_test_mutex_lock();
    g_fmt_test_context.engine_status = status;
    mmi_em_fs_test_mutex_unlock();
}

mmi_em_fs_test_fmt_engine_status_enum mmi_em_fs_test_get_engine_status()
{
    return g_fmt_test_context.engine_status;
}

/*****************************************************************************
 * FUNCTION
 *  fmt_test_start_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     [?]
 *  peer_buff_ptr       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_test_start_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    /* kal_prompt_trace(MOD_FMT,"[FMT]Entry test start handler"); */
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_START, __LINE__);
#endif /* defined(_MMI_EM_FS_TEST_TRACE_SWITCH_) */ 
    /* configure context */
    if(!mmi_em_fs_test_fmt_test_start_pre_handler((mmi_em_fs_test_fmt_start_req_struct*) local_para_ptr))
        {

           test_result_struct.result_status = MMI_EM_FS_TEST_FMT_RESULT_ERROR;
           mmi_em_fs_test_fmt_test_send_finish_msg_to_mmi(&test_result_struct);
        }
    else
    {
            mmi_em_fs_test_mutex_lock();
            if(mmi_em_fs_test_get_engine_status()!= MMI_EM_FS_TEST_FMT_ENGINE_STATUS_INIT)
            {
                mmi_em_fs_test_fmt_test_cancel_handler_int();
            }
            else
            {
                mmi_em_fs_test_set_engine_status(MMI_EM_FS_TEST_FMT_ENGINE_STATUS_RUNNING);
            }
            
            mmi_em_fs_test_mutex_unlock();
          /* do testing */
            mmi_em_fs_test_fmt_test_start_handler_int();

            /* restore context */
            mmi_em_fs_test_fmt_test_start_post_handler();
    }

#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    /* kal_prompt_trace(MOD_FMT,"[FMT]test finished"); */
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_END, __LINE__);
#endif /* defined(_MMI_EM_FS_TEST_TRACE_SWITCH_) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_start_pre_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool mmi_em_fs_test_fmt_test_start_pre_handler(mmi_em_fs_test_fmt_start_req_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(msg == NULL || msg->buffer == NULL)
	{
        return KAL_FALSE;
    }
	
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    /* kal_prompt_trace(MOD_FMT,"[FMT]entry start test configure handler"); */
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_START_PRE_HANDLER, msg->buffer, &test_result_struct);
#endif /* defined(_MMI_EM_FS_TEST_TRACE_SWITCH_) */ 
   

    g_fmt_test_context.buffer = msg->buffer;

    g_data_buffer = g_fmt_test_context.buffer;

    for (i = 0; i < MMI_EM_FS_TEST_FMT_DISK_TOTAL; i++)
        g_fmt_test_context.drv_letter[i] = msg->drv_letter[i];

    for (i = 0; i < MMI_EM_FS_TEST_FMT_CATEGORY_TOTAL; i++)
        g_fmt_test_context.category[i] = msg->category[i];

    memset(g_fmt_test_context.long_file_name, 0x00, sizeof(g_fmt_test_context.long_file_name));

    g_fmt_test_context.get_time_handler = mmi_em_fs_test_fmt_test_get_time;

    /* init all test time */
    for (i = 0; i < MMI_EM_FS_TEST_FMT_DISK_TOTAL; i++)
    {
        for (j = 0; j < MMI_EM_FS_TEST_FMT_CATEGORY_TOTAL; j++)
        {
            test_result_struct.data[i].category[j] = 0;
        }

        for (j = 0; j < MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_TOTAL; j++)
        {
            test_result_struct.data[i].basic_test_case_time[j] = FMT_TEST_RESULT_TIME_MAX;
        }
        for (j = 0; j < MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_TOTAL; j++)
        {
            test_result_struct.data[i].normal_test_case_time[j] = FMT_TEST_RESULT_TIME_MAX;
        }
        for (j = 0; j < MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_TOTAL; j++)
        {
            test_result_struct.data[i].advance_test_case_time[j] = FMT_TEST_RESULT_TIME_MAX;
        }
    }

    test_result_struct.result_status = MMI_EM_FS_TEST_FMT_RESULT_NO_ERROR;
    
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    /* kal_prompt_trace(MOD_FMT,"[FMT]start test configure handler finished"); */
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_START_PRE_HANDLER_END, __LINE__);
#endif /* defined(_MMI_EM_FS_TEST_TRACE_SWITCH_) */ 

    return KAL_TRUE;
}

static kal_bool mmi_em_fs_test_fmt_process_cancel_event()
{
    mmi_em_fs_test_mutex_lock();
    if(mmi_em_fs_test_get_engine_status() != MMI_EM_FS_TEST_FMT_ENGINE_STATUS_RUNNING)
    {
        mmi_em_fs_test_fmt_test_cancel_handler_int();
        mmi_em_fs_test_mutex_unlock();
        return KAL_TRUE;
    }    
    mmi_em_fs_test_mutex_unlock();
    return KAL_FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_start_handler_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_fmt_test_start_handler_int()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 case_index;
    kal_int32 case_num = 0;
    kal_int32 disk_index = 0;
    kal_int32 result_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_START_HANDLER_INT, g_fmt_test_context.engine_status, &test_result_struct);
#endif 

    if(mmi_em_fs_test_fmt_process_cancel_event())
        return;
    
    for (disk_index = 0; disk_index < MMI_EM_FS_TEST_FMT_DISK_TOTAL; disk_index++)
    {
    #if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
        kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_DISK_INDEX, disk_index);
    #endif /* defined(_MMI_EM_FS_TEST_TRACE_SWITCH_) */ 

        if(mmi_em_fs_test_fmt_process_cancel_event())
            return;
    
        if (srv_fmgr_drv_is_valid((U8)(g_fmt_test_context.drv_letter[disk_index])))
        {
            g_fmt_test_context.active_driver = g_fmt_test_context.drv_letter[disk_index];

            kal_wsprintf(
                g_fmt_test_context.long_file_name,
                "%c:\\%w%w",
                g_fmt_test_context.drv_letter[disk_index],
                FMT_TEST_COMMON_LONG_FILE_PREFIX,
                FMT_TEST_COMMON_LONG_FILE_EXT);

            if (g_fmt_test_context.category[MMI_EM_FS_TEST_FMT_CATEGORY_BASIC])
            {

                test_result_struct.data[disk_index].category[MMI_EM_FS_TEST_FMT_CATEGORY_BASIC] = 1;
                case_num = FMT_CASE_NUM(fmt_basic_test_case);
                result_index = 0;

                for (case_index = 0; case_index < case_num; case_index++)
                {
                #if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
                    /* kal_prompt_trace(MOD_FMT,"[FMT]run basic test case(id=%d)",case_index); */
                    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_START_BASIC_TEST_CASE, case_index);
                #endif /* defined(_MMI_EM_FS_TEST_TRACE_SWITCH_) */ 

                     if(mmi_em_fs_test_fmt_process_cancel_event())
                        return;

                    FMT_TEST_CASE_RUN(
                        fmt_basic_test_case,
                        case_index,
                        &(test_result_struct.data[disk_index].basic_test_case_time[result_index]));
                #if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
                    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_END_BASIC_TEST_CASE, case_index);
                #endif /* defined(_MMI_EM_FS_TEST_TRACE_SWITCH_) */ 
                    result_index += fmt_basic_test_case[case_index].result_length;

                }

            }
            if (g_fmt_test_context.category[MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL])
            {

                test_result_struct.data[disk_index].category[MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL] = 1;
                if (!g_fmt_test_context.drv_is_dirty[disk_index])
                {
                    if (mmi_em_fs_test_fmt_test_make_disk_dirty
                        (g_fmt_test_context.drv_letter[disk_index], g_fmt_test_context.dirty_rate))
                    {
                        g_fmt_test_context.drv_is_dirty[disk_index] = KAL_TRUE;
                    }
                    else
                    {
                        ASSERT(0);
                    }
                }

                case_num = FMT_CASE_NUM(fmt_normal_test_case);
                result_index = 0;
                for (case_index = 0; case_index < case_num; case_index++)
                {
                #if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
                    /* kal_prompt_trace(MOD_FMT,"[FMT]run normal test case(id=%d)",case_index); */
                    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_START_NORMAL_TEST_CASE, case_index);
                #endif /* defined(_MMI_EM_FS_TEST_TRACE_SWITCH_) */ 
                    if(mmi_em_fs_test_fmt_process_cancel_event())
                         return;
                    FMT_TEST_CASE_RUN(
                        fmt_normal_test_case,
                        case_index,
                        &(test_result_struct.data[disk_index].normal_test_case_time[result_index]));
                #if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
                    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_END_NORMAL_TEST_CASE, case_index);
                #endif /* defined(_MMI_EM_FS_TEST_TRACE_SWITCH_) */ 
                    result_index += fmt_normal_test_case[case_index].result_length;

                }

            }
            if (g_fmt_test_context.category[MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE])
            {
                test_result_struct.data[disk_index].category[MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE] = 1;

                if (!g_fmt_test_context.drv_is_dirty[disk_index])
                {
                    if (mmi_em_fs_test_fmt_test_make_disk_dirty
                        (g_fmt_test_context.drv_letter[disk_index], g_fmt_test_context.dirty_rate))
                    {
                        g_fmt_test_context.drv_is_dirty[disk_index] = KAL_TRUE;
                    }
                    else
                    {
                        ASSERT(0);
                    }
                }

                case_num = FMT_CASE_NUM(fmt_advance_test_case);
                result_index = 0;

                for (case_index = 0; case_index < case_num; case_index++)
                {
                #if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
                    /* kal_prompt_trace(MOD_FMT,"[FMT]run advance test case(id=%d)",case_index); */
                    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_START_ADVANCE_TEST_CASE, case_index);
                #endif /* defined(_MMI_EM_FS_TEST_TRACE_SWITCH_) */ 

                     if(mmi_em_fs_test_fmt_process_cancel_event())
                        return;

                    FMT_TEST_CASE_RUN(
                        fmt_advance_test_case,
                        case_index,
                        &(test_result_struct.data[disk_index].advance_test_case_time[result_index]));
                #if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
                    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_END_ADVANCE_TEST_CASE, case_index);
                #endif /* defined(_MMI_EM_FS_TEST_TRACE_SWITCH_) */ 
                    result_index += fmt_advance_test_case[case_index].result_length;

                }
            }
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_start_post_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_fmt_test_start_post_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_START_POST_HANDLE, g_fmt_test_context.engine_status, &test_result_struct);
#endif 
     if(mmi_em_fs_test_fmt_process_cancel_event())
        return;
     
    mmi_em_fs_test_set_engine_status(MMI_EM_FS_TEST_FMT_ENGINE_STATUS_STOPED);
    mmi_em_fs_test_fmt_test_erase_all_dirty_disks();
    mmi_em_fs_test_fmt_test_send_finish_msg_to_mmi(&test_result_struct);
    mmi_em_fs_test_set_engine_status(MMI_EM_FS_TEST_FMT_ENGINE_STATUS_INIT);
    
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_END_POST_HANDLE);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_erase_all_dirty_disks
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_fmt_test_erase_all_dirty_disks()
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 disk_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_ERASE_DIRTY_DISK);
#endif 
    for (disk_index = 0; disk_index < MMI_EM_FS_TEST_FMT_DISK_TOTAL; disk_index++)
    {
        if (g_fmt_test_context.drv_is_dirty[disk_index])
        {
            mmi_em_fs_test_fmt_test_erase_disk_dirty(g_fmt_test_context.drv_letter[disk_index]);
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_cancel_handler_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_fmt_test_cancel_handler_int()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_START_CANCEL_HANLDE, g_fmt_test_context.engine_status, &test_result_struct);
#endif 
    mmi_em_fs_test_mutex_lock();

    if (mmi_em_fs_test_get_engine_status() == MMI_EM_FS_TEST_FMT_ENGINE_STATUS_ABORT)
    {
        mmi_em_fs_test_fmt_test_erase_all_dirty_disks();
        mmi_em_fs_test_fmt_test_send_cancel_rsp_msg_to_mmi();
        mmi_em_fs_test_set_engine_status(MMI_EM_FS_TEST_FMT_ENGINE_STATUS_INIT);
    }
    mmi_em_fs_test_mutex_unlock();
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_END_CANCEL_HANLDE);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_send_start_rsp_msg_to_mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_fmt_test_send_start_rsp_msg_to_mmi()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *message;
    mmi_em_fs_test_fmt_start_cnf_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    message = allocate_ilm(MOD_FMT);

    data =
        (mmi_em_fs_test_fmt_start_cnf_struct*) construct_local_para(
                                                sizeof(mmi_em_fs_test_fmt_start_cnf_struct),
                                                TD_CTRL);
    data->test_status = 0;

    message->msg_id = MSG_ID_MMI_FMT_TEST_START_CNF;
    message->peer_buff_ptr = NULL;
    message->local_para_ptr = (local_para_struct*) data;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_MMI_SAP, message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_send_cancel_rsp_msg_to_mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_fmt_test_send_cancel_rsp_msg_to_mmi()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    message = allocate_ilm(MOD_FMT);

    message->msg_id = MSG_ID_MMI_FMT_TEST_START_CNF;
    message->peer_buff_ptr = NULL;
    message->local_para_ptr = NULL;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_MMI_SAP, message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_send_finish_msg_to_mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_fmt_test_send_finish_msg_to_mmi(mmi_em_fs_test_fmt_finish_iln_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    ilm_struct *message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    message = allocate_ilm(MOD_FMT);

    message->msg_id = MSG_ID_MMI_FMT_TEST_FINISH_IND;
    message->peer_buff_ptr = NULL;
    message->local_para_ptr = NULL;//(local_para_struct*) data;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_MMI_SAP, message);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_make_disk_dirty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  driver          [IN]        
 *  dirty_rate      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool mmi_em_fs_test_fmt_test_make_disk_dirty(kal_uint8 driver, kal_uint8 dirty_rate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    kal_uint16 dir_index, dir_index_to_delete, file_index, file_index_to_delete;
    kal_int16 file_result, dir_result;
    FS_HANDLE file_handler;
    kal_uint8 data = 0xFF;
    kal_uint32 write_length;
    kal_bool is_full = KAL_FALSE;
    kal_uint8 ratio = 0;
    mmi_em_fs_test_fmt_disk_info_struct disk_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_START_MAKE_DISK_DIRTY, driver, dirty_rate);
#endif /* defined(_MMI_EM_FS_TEST_TRACE_SWITCH_) */ 

    if (dirty_rate == 0 || dirty_rate >= 100)
    {
        return KAL_TRUE;
    }

    mmi_em_fs_test_fmt_test_get_disk_info( driver, &disk_info);

    if(disk_info.ratio>=ratio)
    {
        return KAL_TRUE;
    }

     ratio = 100 / dirty_rate;
    
    dir_index = 1;
    while (1)
    {

        if(mmi_em_fs_test_fmt_process_cancel_event())
        {
            return KAL_TRUE;
         }

        

        kal_wsprintf(g_fmt_dir_name, "%c:\\%w%d", driver, FMT_TEST_DIRTY_DIR_NAME_PREFIX, dir_index);
        dir_result = FS_CreateDir(g_fmt_dir_name);

        if (dir_result < 0)
        {
            is_full = KAL_TRUE;
            break;
        }

        for (file_index = 1000; file_index > 0; file_index--)
        {
             if(mmi_em_fs_test_fmt_process_cancel_event())
              {
            return KAL_TRUE;
         }
            kal_wsprintf(
                g_fmt_file_name,
                "%w\\%w%d%w",
                g_fmt_dir_name,
                FMT_TEST_DIRTY_LONG_FILE_NAME_PREFIX,
                file_index,
                FMT_TEST_COMMON_LONG_FILE_EXT);
            file_handler = FS_Open(g_fmt_file_name, FS_CREATE_ALWAYS);
            if(file_handler<0)
            {
                is_full = KAL_TRUE;
            }
            file_result = FS_Write(file_handler, &data, 1, &write_length);
            if (file_result < 0 || write_length != 1)
            {
                is_full = KAL_TRUE;
            }
            FS_Close(file_handler);

            if (is_full)
                break;
        }

        if (is_full)
            break;
        dir_index++;
    }

    kal_wsprintf(g_fmt_dir_name, "%c:\\%w%d", driver, FMT_TEST_DIRTY_DIR_NAME_PREFIX, dir_index);
    for (file_index_to_delete = 1000; file_index_to_delete >= file_index;
         file_index_to_delete = file_index_to_delete - ratio)
    {
         if(mmi_em_fs_test_fmt_process_cancel_event())
      {
            return KAL_TRUE;
      }
         
        kal_wsprintf(
            g_fmt_file_name,
            "%w\\%w%d%w",
            g_fmt_dir_name,
            FMT_TEST_DIRTY_LONG_FILE_NAME_PREFIX,
            file_index_to_delete,
            FMT_TEST_COMMON_LONG_FILE_EXT);
        FS_Delete(g_fmt_file_name);
    }

    

    for (dir_index_to_delete = dir_index - 1; dir_index_to_delete > 0; dir_index_to_delete--)
    {
         if(mmi_em_fs_test_fmt_process_cancel_event())
      {
            return KAL_TRUE;
      }

        kal_wsprintf(g_fmt_dir_name, "%c:\\%w%d", driver, FMT_TEST_DIRTY_DIR_NAME_PREFIX, dir_index_to_delete);
        for (file_index_to_delete = 1000; file_index_to_delete > 0; file_index_to_delete = file_index_to_delete - ratio)
        {
             if(mmi_em_fs_test_fmt_process_cancel_event())
      {
            return KAL_TRUE;
      }
            kal_wsprintf(
                g_fmt_file_name,
                "%w\\%w%d%w",
                g_fmt_dir_name,
                FMT_TEST_DIRTY_LONG_FILE_NAME_PREFIX,
                file_index_to_delete,
                FMT_TEST_COMMON_LONG_FILE_EXT);
            FS_Delete(g_fmt_file_name);
        }
    }
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    /* kal_prompt_trace(MOD_FMT,"[FMT]finish make disk dirty(disk= %d,ratio = %d",driver,dirty_rate); */
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_END_MAKE_DISK_DIRTY, driver, dirty_rate);
#endif /* defined(_MMI_EM_FS_TEST_TRACE_SWITCH_) */ 

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_erase_disk_dirty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  driver      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool mmi_em_fs_test_fmt_test_erase_disk_dirty(kal_uint8 driver)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //WCHAR pattern_name[MMI_EM_FS_TEST_FMT_MAX_PATH_LEN];
    //WCHAR file_name[MMI_EM_FS_TEST_FMT_MAX_PATH_LEN];
    //WCHAR dir_name[MMI_EM_FS_TEST_FMT_MAX_PATH_LEN];
    //FS_DOSDirEntry dir_entry;
    //FS_HANDLE file_handler;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*kal_wsprintf(pattern_name, "%c:\\%w*", driver, FMT_TEST_DIRTY_DIR_NAME_PREFIX);

    file_handler = FS_FindFirst(pattern_name, FS_ATTR_DIR, 0, &dir_entry, file_name, MMI_EM_FS_TEST_FMT_MAX_PATH_LEN);

    if (file_handler >= 0)
    {
        do
        {
            kal_wsprintf(dir_name, "%c:\\%w", driver, file_name);

            FS_RemoveDir(dir_name);

            if (FS_FindNext(file_handler, &dir_entry, file_name, MMI_EM_FS_TEST_FMT_MAX_PATH_LEN) < FS_NO_ERROR)
            {
                break;
            }
        } while (1);

        FS_FindClose(file_handler);
    }
    */
    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_get_disk_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  driver          [IN]        
 *  disk_info       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool mmi_em_fs_test_fmt_test_get_disk_info(kal_uint8 driver, mmi_em_fs_test_fmt_disk_info_struct *disk_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FS_DiskInfo fs_disk_info;
    kal_int32 fs_ret;
    WCHAR path[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(path, "%c:\\", driver);
    fs_ret = FS_GetDiskInfo((WCHAR*) path, &fs_disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    if (fs_ret >= 0)
    {
        disk_info->free_space =
            (kal_uint64) fs_disk_info.FreeClusters * fs_disk_info.SectorsPerCluster * fs_disk_info.BytesPerSector;
        disk_info->total_space =
            (kal_uint64) fs_disk_info.TotalClusters * fs_disk_info.SectorsPerCluster * fs_disk_info.BytesPerSector;

        if (fs_disk_info.TotalClusters > 0)
        {
            disk_info->ratio = (kal_uint32) (fs_disk_info.FreeClusters * 100 / fs_disk_info.TotalClusters);
        }
        else
            {
                disk_info->ratio = 0;
            }
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_create_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [IN]        
 *  flag            [IN]        
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool mmi_em_fs_test_fmt_test_create_file(const WCHAR *file_name, UINT flag, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handler;
    kal_uint32 file_size;
    mmi_em_fs_test_fmt_disk_info_struct disk_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size == 0)
    {
        mmi_em_fs_test_fmt_test_get_disk_info(g_fmt_test_context.active_driver, &disk_info);
        size = disk_info.free_space;
    }

    file_handler = FS_Open(file_name, flag);
    if(file_handler<0)
        return KAL_FALSE;

    if (FS_GetFileSize(file_handler, &file_size) != FS_NO_ERROR)
    {
        FS_Close(file_handler);
        FS_Delete(file_name);
        return KAL_FALSE;
    }

    if (file_size < size)
    {
        if (FS_Seek(file_handler, size, FS_FILE_BEGIN) < FS_NO_ERROR)
        {
            FS_Close(file_handler);
            FS_Delete(file_name);
            return KAL_FALSE;
        }
    }
    else if (file_size > size)
    {
        if (FS_Seek(file_handler, size, FS_FILE_BEGIN) < FS_NO_ERROR)
        {
            FS_Close(file_handler);
            FS_Delete(file_name);
            return KAL_FALSE;
        }
        FS_Truncate(file_handler);
    }

    FS_Close(file_handler);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_get_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint32 mmi_em_fs_test_fmt_test_get_time()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TIME_MODIS_SWITCH_)
    kal_uint32 time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&time);

    return time;
#endif /* defined(_MMI_EM_FS_TEST_TIME_MODIS_SWITCH_) */ /* defined(_FMT_TEST_DEBUG_) */

    return drv_get_current_time();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_write_line_to_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_em_fs_test_fmt_test_write_line_to_file()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  fmt_test_save_file_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     [?]
 *  peer_buff_ptr       [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
kal_bool fmt_test_save_file_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *full_path_name;

    char *data_buffer;

    kal_int16 index, category_index;
    kal_bool contain_data;

    mmi_em_fs_test_fmt_result_struct *data;
    FS_HANDLE file_handler;
    int write_result;
    UINT write_length;
    applib_time_struct current_time;

    MMI_EM_FS_TEST_FMT_SAVE_RESULT_ENUM error_code= MMI_EM_FS_TEST_FMT_SAVE_UNKNOWN_ERROR;

    mmi_em_fs_test_fmt_save_data_req_struct *local_para = (mmi_em_fs_test_fmt_save_data_req_struct*) local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_SAVE_FILE_HANDLE);
#endif 
    for (index = 0; index < MMI_EM_FS_TEST_FMT_DISK_TOTAL; index++)
    {
        data = local_para->data_ptr[index];

        contain_data = KAL_FALSE;
        for (category_index = 0; category_index < MMI_EM_FS_TEST_FMT_CATEGORY_TOTAL; category_index++)
        {
            if (data->category[category_index])
            {
                contain_data = KAL_TRUE;
                break;
            }
        }

        if (!contain_data)
            continue;
        applib_dt_get_date_time(&current_time);

        full_path_name = (WCHAR*) local_para->bufffer;
        memset(full_path_name, 0x00, MMI_EM_FS_TEST_FMT_MAX_PATH_LEN);

        kal_wsprintf(full_path_name, "%w%d_%d%d%d%d%d%d%w", local_para->file_name, index, current_time.nYear,current_time.nMonth,current_time.nDay,current_time.nHour,current_time.nMin,current_time.nSec, FMT_TEST_COMMON_LONG_FILE_EXT);

        file_handler = FS_Open(full_path_name, FS_CREATE_ALWAYS);

        if (file_handler < 0)
        {
            continue;
        }

        /* title */

        data_buffer = (char*)local_para->bufffer;
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
    #if defined(__MMI_EM_PROFILING_FS_TEST_FS_BASIC_RW_TIMES__)
    #if defined (__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
        kal_sprintf(data_buffer, "%s", "API\\Case\t8B\t128B\t1KB\t2KB\t16KB\t32KB\t16MB\n");
    #else 
        kal_sprintf(data_buffer, "%s", "API\\Case\t8B\t128B\t1KB\t2KB\t16KB\t32KB\n");
    #endif 
    #else /* defined(__MMI_EM_PROFILING_FS_TEST_FS_BASIC_RW_TIMES__) */ 
    #if defined (__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
        kal_sprintf(data_buffer, "%s", "API\\Case\t8B*4093\t128B*256\t1KB*32\t2KB*16\t16KB*2\t32KB*1\t16MB\n");
    #else 
        kal_sprintf(data_buffer, "%s", "API\\Case\t8B*4093\t128B*256\t1KB*32\t2KB*16\t16KB*2\t32KB*1\n");
    #endif 
    #endif /* defined(__MMI_EM_PROFILING_FS_TEST_FS_BASIC_RW_TIMES__) */ 
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* read */
        memset(data_buffer, 0x00, 100);
        kal_sprintf(data_buffer,
    #if defined (__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
                    "%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
    #else 
                    "%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
    #endif 
                    "Read",
                    data->basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_8_ID],
                    data->basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_128_ID],
                    data->basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_1k_ID],
                    data->basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_2k_ID],
                    data->basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_16k_ID],
                    data->basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_32k_ID]
    #if defined (__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
                    , data->basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_16MB_ID]
    #endif 
            );
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* write */
        memset(data_buffer, 0x00, 100);
        kal_sprintf(data_buffer,
    #if defined (__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
                    "%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
    #else 
                    "%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
    #endif 
                    "Write",
                    data->basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_8_ID],
                    data->basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_128_ID],
                    data->basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_1k_ID],
                    data->basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_2k_ID],
                    data->basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_16k_ID],
                    data->basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_32k_ID]
    #if defined (__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
                    , data->basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_16MB_ID]
    #endif 
            );
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* read dirty */
        memset(data_buffer, 0x00, 100);
        kal_sprintf(data_buffer,
    #if defined (__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
                    "%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
    #else 
                    "%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
    #endif 
                    "Dirty Read",
                    data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_8_ID],
                    data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_128_ID],
                    data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_1k_ID],
                    data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_2k_ID],
                    data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_16k_ID],
                    data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_32k_ID]
    #if defined (__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
                    , data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_16MB_ID]
    #endif 
            );
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* write dirty */
        memset(data_buffer, 0x00, 100);
        kal_sprintf(data_buffer,
    #if defined (__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
                    "%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
    #else 
                    "%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
    #endif 
                    "Dirty Write",
                    data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_8_ID],
                    data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_128_ID],
                    data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_1k_ID],
                    data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_2k_ID],
                    data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_16k_ID],
                    data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_32k_ID]
    #if defined (__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
                    , data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_16MB_ID]
    #endif 
            );
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        data_buffer[0] = '\n';
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(data_buffer, "\t%s\n", "ms");
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* delete */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Delete",
            data->basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_DELETE_16MB_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* delete dirty */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Dirty Delete",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_DELETE_16MB_ID]);

        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);
    #if defined(__MMI_EM_PROFILING_FS_TEST_FS_SEEK__)
        /* full delete */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Delete a full file",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_DELETE_ID]);

        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* 5MB delete */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Delete a 5MB file",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_DELETE_ID]);

        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);
    #endif /* defined(__MMI_EM_PROFILING_FS_TEST_FS_SEEK__) */ 
        /* write flush */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Write with flush(128B*1000)",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_FLUSH_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* write no flush */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Write no flush(128B*1000)",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_NO_FLUSH_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* read flush */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Read with sleep(512B*1000)",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_SLEEP_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* read no flush */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Read no sleep(512B*1000)",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_NO_SLEEP_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* scenario */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Create/Open/Write/Read/Close/Delete(512B*1000)",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_OPEN_WRITE_READ_CLOSE_DELETE_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

    #if defined (__MMI_EM_PROFILING_FS_TEST_FS_SEEK__)
        /* full open */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Open a full file",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_OPEN_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* 5MB open */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Open a 5MB file",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_OPEN_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* full close */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Close a full file",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_CLOSE_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* 5MB close */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Close a 5MB file",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_CLOSE_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* full seek head */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Seek the head of a full file",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_SEEK_HEAD_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* 5MB seek head */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Seek the head of a 5MB file",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_SEEK_HEAD_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* full seek mid */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Seek the middle of a full file",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_SEEK_MID_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* 5MB seek mid */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Seek the middle of a 5MB file",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_SEEK_MID_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* full seek tail */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Seek the tail of a full file",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_SEEK_TAIL_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* 5MB seek tail */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Seek the tail of a 5MB file",
            data->normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_SEEK_TAIL_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        data_buffer[0] = '\n';
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);
    #endif /* defined (__MMI_EM_PROFILING_FS_TEST_FS_SEEK__) */ 
        /* find first */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Find first",
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FIND_FIRST_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* find next */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\n",
            "Find next",
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FIND_NEXT_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* title */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(data_buffer, "%s", "API\\Buffer\t1K\t2K\t8K\t16K\n");
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\t%d\t%d\t%d\n",
            "FSAL_Read 32B",
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_1K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_2K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_8K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_16K_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\t%d\t%d\t%d\n",
            "FSAL_Read 512B",
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_1K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_2K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_8K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_16K_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\t%d\t%d\t%d\n",
            "FSAL_Read 2K",
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_1K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_2K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_8K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_16K_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\t%d\t%d\t%d\n",
            "FSAL_Read 16K",
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_1K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_2K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_8K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_16K_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        /* write 32B */
        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\t%d\t%d\t%d\n",
            "FSAL_Write 32B",
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_1K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_2K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_8K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_16K_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
       
        kal_sprintf(
            data_buffer,
            "%s\t%d\t%d\t%d\t%d\n",
            "FSAL_Write 512B",
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_1K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_2K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_8K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_16K_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\t%d\t%d\t%d\n",
            "FSAL_Write 2K",
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_1K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_2K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_8K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_16K_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(
            data_buffer,
            "%s\t%d\t%d\t%d\t%d\n",
            "FSAL_Write 16K",
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_1K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_2K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_8K_ID],
            data->advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_16K_ID]);
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        data_buffer[0] = '\n';
        FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL);

        memset(data_buffer, 0x00, MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM);
        kal_sprintf(data_buffer, "Note: dirty rate = %d\n", g_fmt_test_context.dirty_rate);
        write_result = FS_Write(file_handler, data_buffer, strlen(data_buffer), &write_length);

        if(write_result <0 || write_length != strlen(data_buffer))
            {
                error_code = MMI_EM_FS_TEST_FMT_SAVE_DISK_FULL;
            }
        else
        {
            error_code = MMI_EM_FS_TEST_FMT_SAVE_NO_ERROR;
        }

        FS_Close(file_handler);

        if(error_code != MMI_EM_FS_TEST_FMT_SAVE_NO_ERROR)
        {
            full_path_name = (WCHAR*) local_para->bufffer;
            memset(full_path_name, 0x00, MMI_EM_FS_TEST_FMT_MAX_PATH_LEN);
            kal_wsprintf(full_path_name, "%w%d_%d%d%d%d%d%d%w", local_para->file_name, index, current_time.nYear,current_time.nMonth,current_time.nDay,current_time.nHour,current_time.nMin,current_time.nSec, FMT_TEST_COMMON_LONG_FILE_EXT);
            FS_Delete(full_path_name);
            break;
         }
    }

    mmi_em_fs_test_fmt_test_send_save_finish_to_mmi(error_code);
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_END_FILE_HANDLE);
#endif 
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_send_save_finish_to_mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_fmt_test_send_save_finish_to_mmi(MMI_EM_FS_TEST_FMT_SAVE_RESULT_ENUM error_code
)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *message;
    mmi_em_fs_test_fmt_save_data_cnf_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    message = allocate_ilm(MOD_FMT);

    data =
        (mmi_em_fs_test_fmt_save_data_cnf_struct*)
        construct_local_para(sizeof(mmi_em_fs_test_fmt_save_data_cnf_struct), TD_CTRL);
    data->result = error_code;

    message->msg_id = MSG_ID_MMI_FMT_TEST_SAVE_CNF;
    message->peer_buff_ptr = NULL;
    message->local_para_ptr = (local_para_struct*) data;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_MMI_SAP, message);
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_get_duration_ms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_time      [IN]        
 *  end_time        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint32 mmi_em_fs_test_get_duration_ms(kal_uint32 start_time, kal_uint32 end_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 total_time = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TIME_MODIS_SWITCH_)
    return (kal_uint32) ((end_time - start_time) * 4.615);
#else /* defined(_MMI_EM_FS_TEST_TIME_MODIS_SWITCH_) */ 
    total_time = drv_get_duration_tick(start_time, end_time);
    return total_time * 1000 / 32768;
#endif /* defined(_MMI_EM_FS_TEST_TIME_MODIS_SWITCH_) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_average
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         
 *  data_length     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint32 mmi_em_fs_test_average(kal_uint32 *data, kal_int16 data_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 index;
    kal_int32 min, max;
    kal_int32 sum, ave;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_length == 0 || data == NULL)
        return 0;
    if (data_length <= 2)
        return (*data + *(data + 1)) / 2;
    sum = 0;
    min = *data;
    max = min;

    for (index = 0; index < data_length; index++)
    {
        sum += *(data + index);
        if (*(data + index) > max)
            max = *(data + index);
        if (*(data + index) < min)
            min = *(data + index);
    }

    ave = (sum - max - min) / (data_length - 2);
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_CACL_AVER, data[0], data[1], data[2], data[3], data[4], ave);
#endif 
    return ave;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_trans_ratio
 * DESCRIPTION
 *  
 * PARAMETERS
 *  total_time      [IN]        
 *  block_size      [IN]        
 *  op_times        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint32 mmi_em_fs_test_trans_ratio(kal_uint32 total_time, kal_uint32 block_size, kal_uint32 op_times)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (total_time == 0)
        return 0;
    return (kal_uint32) ((block_size * op_times * 1.0 / 1024) / (total_time / 60.0));
}

#if defined(__MMI_EM_PROFILING_FS_TEST_FS_BASIC_RW_TIMES__)


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_case_write_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  block_size          [IN]        
 *  op_times            [IN]        
 *  result              [?]         [?]
 *  result_length       [IN]        
 *  op                  [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_em_fs_test_fmt_test_case_write_read(
            kal_uint32 block_size,
            kal_uint32 op_times,
            kal_uint32 *result,
            kal_uint32 result_length,
            mmi_em_fs_test_fmt_op_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 start_time, end_time;
    kal_uint32 total_time, time_buffer[5];
    kal_int16 i, test_count;
    kal_uint32 result_count;
    kal_uint32 write_len, read_len;
    kal_int32 file_result;
    kal_uint16 data;
    kal_bool op_result;
    FS_HANDLE file_handler;
    const WCHAR *file_name = g_fmt_test_context.long_file_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_START_WRITE_READ, block_size, op_times, result, result_length);
    /*kal_prompt_trace(
        MOD_FMT,
        "[EM][FS_TEST]start test_write_read,block_size=%d,op_times=%d,result=%d,result_length=%d",
        block_size,
        op_times,
        result,
        result_length);*/
#endif /* defined(_MMI_EM_FS_TEST_TRACE_SWITCH_) */ 
    ASSERT(result_length == 2);
    ASSERT(block_size <= FMT_FS_TEST_MEM_POOL_SIZE);

    result_count = 0;

    if (op & MMI_EM_FS_TEST_FMT_OP_NONE)
        return KAL_TRUE;

    if (op & MMI_EM_FS_TEST_FMT_OP_WRITE || op & MMI_EM_FS_TEST_FMT_OP_NORMAL)
    {
        total_time = 0;

        data = 0x00;

        if(mmi_em_fs_test_fmt_process_cancel_event())
        {
            return KAL_FALSE;
        }

        for (i = 0; i < block_size; i++)
        {
            if (data > 0xFF)
                data = 0;
            memset(g_data_buffer + i, data, 1);
            data++;
        }

        op_result = KAL_TRUE;
        for (test_count = 0; test_count < 5; test_count++)
        {
            time_buffer[test_count] = 0;
            total_time = 0;
            file_handler = FS_Open(file_name, FS_CREATE_ALWAYS);
            if (file_handler < 0)
            {
                /*kal_prompt_trace(MOD_J2ME, "[WR_CASE]open write file failed!,block size= %d", block_size);*/
                return KAL_FALSE;
            }

            for (i = op_times - 1; i >= 0; i--)
            {
                if(mmi_em_fs_test_fmt_process_cancel_event())
                {
                    FS_Close(file_handler);
                    FS_Delete(file_name);
                    return KAL_FALSE;
                }
                start_time = g_fmt_test_context.get_time_handler();
                file_result = FS_Write(file_handler, g_data_buffer, block_size, &write_len);
                end_time = g_fmt_test_context.get_time_handler();

                if (file_result >= 0 && write_len == block_size)
                {
                    total_time += mmi_em_fs_test_get_duration_ms(start_time, end_time);
                }
                else
                {
                    op_result = KAL_FALSE;
                    break;
                }

            }

            FS_Close(file_handler);

            if (op_result)
            {
                time_buffer[test_count] = total_time;
            }
            else
            {
                FS_Delete(file_name);
                return KAL_TRUE;
            }
        }

        total_time = mmi_em_fs_test_average(time_buffer, 5);
        result[result_count++] = (kal_uint32) mmi_em_fs_test_trans_ratio(total_time, block_size, op_times);
    }
    else
    {
        result_count++;
    }

    if (op & MMI_EM_FS_TEST_FMT_OP_READ || op & MMI_EM_FS_TEST_FMT_OP_NORMAL)
    {
        if(mmi_em_fs_test_fmt_process_cancel_event())
        {
            return KAL_FALSE;
        }

        total_time = 0;
        memset(g_data_buffer, 0x00, block_size);

        op_result = KAL_TRUE;

        for (test_count = 0; test_count < 5; test_count++)
        {
            time_buffer[test_count] = 0;
            total_time = 0;
            file_handler = FS_Open(file_name, FS_READ_ONLY);
            if (file_handler < 0)
            {
                /*kal_prompt_trace(MOD_J2ME, "[WR_CASE]open read file failed!,block size= %d", block_size);*/

                return KAL_FALSE;
            }

            for (i = 0; i < op_times; i++)
            {
                if(mmi_em_fs_test_fmt_process_cancel_event())
                {
                    FS_Close(file_handler);
                    FS_Delete(file_name);
                    return KAL_FALSE;
                }
                start_time = g_fmt_test_context.get_time_handler();
                file_result = FS_Read(file_handler, g_data_buffer, block_size, &read_len);
                end_time = g_fmt_test_context.get_time_handler();

                if (file_result >= 0 && read_len == block_size)
                {
                    total_time += mmi_em_fs_test_get_duration_ms(start_time, end_time);
                }
                else
                {
                    op_result = KAL_FALSE;
                    break;
                }

            }

            FS_Close(file_handler);

            if (op_result)
            {
                time_buffer[test_count] = total_time;
            }
            else
            {
                FS_Delete(file_name);
                return KAL_TRUE;
            }

        }
        total_time = mmi_em_fs_test_average(time_buffer, 5);
        result[result_count++] = (kal_uint32) mmi_em_fs_test_trans_ratio(total_time, block_size, op_times);

    }

    FS_Delete(file_name);
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_END_WRITE_READ, result[0], result[1]);
#endif 
    return KAL_TRUE;

}
#else /* defined(__MMI_EM_PROFILING_FS_TEST_FS_BASIC_RW_TIMES__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_case_write_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  block_size          [IN]        
 *  op_times            [IN]        
 *  result              [?]         [?]
 *  result_length       [IN]        
 *  op                  [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_em_fs_test_fmt_test_case_write_read(
            kal_uint32 block_size,
            kal_uint32 op_times,
            kal_uint32 *result,
            kal_uint32 result_length,
            mmi_em_fs_test_fmt_op_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 start_time, end_time;
    kal_int16 i;
    kal_uint32 total_time;
    kal_uint32 result_count;
    kal_uint32 write_len, read_len;
    kal_int32 file_result;
    kal_bool op_result;
    FS_HANDLE file_handler;
    const WCHAR *file_name = g_fmt_test_context.long_file_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_START_WRITE_READ, block_size, op_times, result, result_length);
#endif 
    ASSERT(result_length == 2);
    ASSERT(block_size <= FMT_FS_TEST_MEM_POOL_SIZE);

    result_count = 0;

    if (op & MMI_EM_FS_TEST_FMT_OP_NONE)
        return KAL_TRUE;

    if (op & MMI_EM_FS_TEST_FMT_OP_WRITE || op & MMI_EM_FS_TEST_FMT_OP_NORMAL)
    {
        total_time = 0;

         if(mmi_em_fs_test_fmt_process_cancel_event())
                {
                    return KAL_FALSE;
                }
        memset(g_data_buffer, 0xFF, block_size);

        op_result = KAL_TRUE;
        file_handler = FS_Open(file_name, FS_CREATE_ALWAYS);

        /* ASSERT(file_handler >= 0); */

        if (file_handler < 0)
        {
            /*kal_prompt_trace(MOD_J2ME, "[WR_CASE]open write file failed!,block size= %d", block_size);*/

            return KAL_FALSE;
        }

        for (i = 0; i < op_times; i++)
        {
             if(mmi_em_fs_test_fmt_process_cancel_event())
            {
                    FS_Close(file_handler);
                    FS_Delete(file_name);
                return KAL_FALSE;
            }
            start_time = g_fmt_test_context.get_time_handler();
            file_result = FS_Write(file_handler, g_data_buffer, block_size, &write_len);
            end_time = g_fmt_test_context.get_time_handler();

            if (file_result >= 0 && write_len == block_size)
            {
                total_time += mmi_em_fs_test_get_duration_ms(start_time, end_time);
            }
            else
            {
                op_result = KAL_FALSE;
                break;
            }

        }

        FS_Close(file_handler);

        if (op_result)
        {
            /* result[result_count++] = total_time; */
            result[result_count++] = (kal_uint32) mmi_em_fs_test_trans_ratio(total_time, block_size, op_times);
        }
        else
        {
            FS_Delete(file_name);
            return KAL_TRUE;
        }
    }
    else
    {
        result_count++;
    }

    if (op & MMI_EM_FS_TEST_FMT_OP_READ || op & MMI_EM_FS_TEST_FMT_OP_NORMAL)
    {
        total_time = 0;

         if(mmi_em_fs_test_fmt_process_cancel_event())
                {
                    return KAL_FALSE;
                }
         
        memset(g_data_buffer, 0x00, block_size);
        op_result = KAL_TRUE;

        file_handler = FS_Open(file_name, FS_READ_ONLY);
        /* ASSERT(file_handler >= 0); */
        if (file_handler < 0)
        {
            /*kal_prompt_trace(MOD_J2ME, "[WR_CASE]open read file failed!,block size= %d", block_size);*/

            return KAL_FALSE;
        }

        for (i = 0; i < op_times; i++)
        {
             if(mmi_em_fs_test_fmt_process_cancel_event())
            {
                    FS_Close(file_handler);
                    FS_Delete(file_name);
                return KAL_FALSE;
            }

            start_time = g_fmt_test_context.get_time_handler();
            file_result = FS_Read(file_handler, g_data_buffer, block_size, &read_len);
            end_time = g_fmt_test_context.get_time_handler();

            if (file_result >= 0 && read_len == block_size)
            {
                total_time += mmi_em_fs_test_get_duration_ms(start_time, end_time);
            }
            else
            {
                op_result = KAL_FALSE;
                break;
            }

        }

        if (op_result)
        {

            /* result[result_count++] = total_time; */
            result[result_count++] = (kal_uint32) mmi_em_fs_test_trans_ratio(total_time, block_size, op_times);
        }
        FS_Close(file_handler);

    }

    FS_Delete(file_name);
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_END_WRITE_READ, result[0], result[1]);
#endif 
    return KAL_TRUE;

}
#endif /* defined(__MMI_EM_PROFILING_FS_TEST_FS_BASIC_RW_TIMES__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_case_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  block_size          [IN]        
 *  op_times            [IN]        
 *  result              [?]         [?]
 *  result_length       [IN]        
 *  op                  [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_em_fs_test_fmt_test_case_delete(
            kal_uint32 block_size,
            kal_uint32 op_times,
            kal_uint32 *result,
            kal_uint32 result_length,
            mmi_em_fs_test_fmt_op_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 start_time, end_time;

    const WCHAR *file_name = g_fmt_test_context.long_file_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_START_DELETE, block_size, op_times, result, result_length);
#endif 
    ASSERT(result_length == 1);

    if (!mmi_em_fs_test_fmt_test_create_file(file_name, FS_CREATE, block_size))
    {
        return KAL_TRUE;
    }

    start_time = g_fmt_test_context.get_time_handler();
    FS_Delete(file_name);
    end_time = g_fmt_test_context.get_time_handler();

    result[0] = mmi_em_fs_test_get_duration_ms(start_time, end_time);
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_END_DELETE, result[0]);
#endif 
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_case_write_flush
 * DESCRIPTION
 *  
 * PARAMETERS
 *  block_size          [IN]        
 *  op_times            [IN]        
 *  result              [?]         [?]
 *  result_length       [IN]        
 *  op                  [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_em_fs_test_fmt_test_case_write_flush(
            kal_uint32 block_size,
            kal_uint32 op_times,
            kal_uint32 *result,
            kal_uint32 result_length,
            mmi_em_fs_test_fmt_op_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 start_time, end_time;
    kal_int16 i;
    kal_uint32 total_time;
    kal_uint32 result_count;
    kal_uint32 write_len;
    kal_int32 file_result;

    kal_bool op_result;
    FS_HANDLE file_handler;
    const WCHAR *file_name = g_fmt_test_context.long_file_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_START_WRITE_FLUSH, block_size, op_times, result, result_length);
#endif 
    ASSERT(result_length == 2);
    ASSERT(block_size <= FMT_FS_TEST_MEM_POOL_SIZE);

    result_count = 0;

    if (op & MMI_EM_FS_TEST_FMT_OP_NONE)
        return KAL_TRUE;

    if(mmi_em_fs_test_fmt_process_cancel_event())
     {
            return KAL_FALSE;
     }

    /* test write with flush */
    total_time = 0;
    op_result = KAL_TRUE;
    memset(g_data_buffer, 0xFF, block_size);

    file_handler = FS_Open(file_name, FS_CREATE_ALWAYS);
    if (file_handler < 0)
    {
        /*kal_prompt_trace(MOD_J2ME, "[WFLUSH_CASE_1]open write file failed!,block size= %d", block_size);*/

        return KAL_FALSE;
    }

    for (i = 0; i < op_times; i++)
    {
        if(mmi_em_fs_test_fmt_process_cancel_event())
        {
            FS_Close(file_handler);
            FS_Delete(file_name);
            return KAL_FALSE;
        }
        
        start_time = g_fmt_test_context.get_time_handler();
        file_result = FS_Write(file_handler, g_data_buffer, block_size, &write_len);
        FS_Commit(file_handler);
        end_time = g_fmt_test_context.get_time_handler();

        if (file_result >= 0 && write_len == block_size)
        {
            total_time += mmi_em_fs_test_get_duration_ms(start_time, end_time);
        }
        else
        {
            op_result = KAL_FALSE;
            break;
        }
    }
    FS_Close(file_handler);
    FS_Delete(file_name);

    if (op_result)
        result[result_count++] = total_time;
    else
    {
        return KAL_TRUE;
    }

    /* test write without flush */

    if(mmi_em_fs_test_fmt_process_cancel_event())
        {
            return KAL_TRUE;

        }
    total_time = 0;
    op_result = KAL_TRUE;
    memset(g_data_buffer, 0xFF, block_size);

    file_handler = FS_Open(file_name, FS_CREATE_ALWAYS);
    /* ASSERT(file_handler >= 0); */
    if (file_handler < 0)
    {
        /*kal_prompt_trace(MOD_J2ME, "[WFLUSH_CASE_2]open write file failed!,block size= %d", block_size);*/

        return KAL_FALSE;
    }

    for (i = 0; i < op_times; i++)
    {
        if(mmi_em_fs_test_fmt_process_cancel_event())
        {
            FS_Close(file_handler);
            FS_Delete(file_name);
            return KAL_FALSE;
        }
        start_time = g_fmt_test_context.get_time_handler();
        file_result = FS_Write(file_handler, g_data_buffer, block_size, &write_len);
        end_time = g_fmt_test_context.get_time_handler();

        if (file_result >= 0 && write_len == block_size)
            total_time += mmi_em_fs_test_get_duration_ms(start_time, end_time);
        else
        {
            op_result = KAL_FALSE;
            break;
        }
    }
    FS_Close(file_handler);
    FS_Delete(file_name);

    if (op_result)
        result[result_count++] = total_time;
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_END_WRITE_FLUSH, result[0], result[1]);
#endif 
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_case_read_sleep
 * DESCRIPTION
 *  
 * PARAMETERS
 *  block_size          [IN]        
 *  op_times            [IN]        
 *  result              [?]         [?]
 *  result_length       [IN]        
 *  op                  [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_em_fs_test_fmt_test_case_read_sleep(
            kal_uint32 block_size,
            kal_uint32 op_times,
            kal_uint32 *result,
            kal_uint32 result_length,
            mmi_em_fs_test_fmt_op_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 start_time, end_time;
    kal_uint32 total_time;
    kal_int16 i;
    kal_uint32 result_count;
    kal_uint32 read_len;
    kal_int32 file_result;
    kal_bool op_result;

    FS_HANDLE file_handler;
    const WCHAR *file_name = g_fmt_test_context.long_file_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_START_READ_SLEEP, block_size, op_times, result, result_length);
#endif 
    ASSERT(result_length == 2);
    ASSERT(block_size <= FMT_FS_TEST_MEM_POOL_SIZE);

    if (op & MMI_EM_FS_TEST_FMT_OP_NONE)
        return KAL_TRUE;

    if (!mmi_em_fs_test_fmt_test_create_file(file_name, FS_CREATE, block_size))
    {
        return KAL_TRUE;
    }
     if(mmi_em_fs_test_fmt_process_cancel_event())
                {
                    return KAL_FALSE;
                }
    result_count = 0;

    /* test read with sleep */
    total_time = 0;
    op_result = KAL_TRUE;
    memset(g_data_buffer, 0x00, block_size);

    file_handler = FS_Open(file_name, FS_READ_ONLY);
    /* ASSERT(file_handler >= 0); */
    if (file_handler < 0)
    {
        /*kal_prompt_trace(MOD_J2ME, "[RSLEEP_CASE_1]Open file failed!,block size= %d", block_size);*/

        return KAL_FALSE;
    }

    for (i = 0; i < op_times; i++)
    {
         if(mmi_em_fs_test_fmt_process_cancel_event())
                {
                    FS_Close(file_handler);
                    FS_Delete(file_name);
                    return KAL_FALSE;
                }
        start_time = g_fmt_test_context.get_time_handler();
        file_result = FS_Read(file_handler, g_data_buffer, block_size, &read_len);
        kal_sleep_task(1);
        end_time = g_fmt_test_context.get_time_handler();
        total_time += mmi_em_fs_test_get_duration_ms(start_time, end_time);
    }

    FS_Close(file_handler);

    result[result_count++] = total_time;

    /* test read without sleep */
    total_time = 0;
    op_result = KAL_TRUE;
     if(mmi_em_fs_test_fmt_process_cancel_event())
                {
                    return KAL_FALSE;
                }
    memset(g_data_buffer, 0xFF, block_size);

    file_handler = FS_Open(file_name, FS_READ_ONLY);
    if (file_handler < 0)
    {
        //kal_prompt_trace(MOD_J2ME, "[RSLEEP_CASE_2]open  file failed!,block size= %d", block_size);

        return KAL_FALSE;
    }

    for (i = 0; i < op_times; i++)
    {
         if(mmi_em_fs_test_fmt_process_cancel_event())
          {
                    FS_Close(file_handler);
                    FS_Delete(file_name);
                    return KAL_FALSE;
           }
        start_time = g_fmt_test_context.get_time_handler();
        file_result = FS_Read(file_handler, g_data_buffer, block_size, &read_len);
        end_time = g_fmt_test_context.get_time_handler();
        total_time += mmi_em_fs_test_get_duration_ms(start_time, end_time);
    }
    FS_Close(file_handler);
    FS_Delete(file_name);

    result[result_count++] = total_time;
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_END_READ_SLEEP, result[0], result[1]);
#endif 
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_case_scenario
 * DESCRIPTION
 *  
 * PARAMETERS
 *  block_size          [IN]        
 *  op_times            [IN]        
 *  result              [?]         [?]
 *  result_length       [IN]        
 *  op                  [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_em_fs_test_fmt_test_case_scenario(
            kal_uint32 block_size,
            kal_uint32 op_times,
            kal_uint32 *result,
            kal_uint32 result_length,
            mmi_em_fs_test_fmt_op_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 start_time, end_time;
    kal_uint32 total_time;
    kal_int16 i;
    kal_uint32 write_len, read_len;
    kal_int32 file_result;
    kal_bool op_result;
    FS_HANDLE file_handler;
    const WCHAR *file_name = g_fmt_test_context.long_file_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_START_SCENARIO, block_size, op_times, result, result_length);
#endif 
    ASSERT(result_length == 1);
    ASSERT(block_size <= FMT_FS_TEST_MEM_POOL_SIZE);

    if (op & MMI_EM_FS_TEST_FMT_OP_NONE)
        return KAL_TRUE;

     if(mmi_em_fs_test_fmt_process_cancel_event())
                {
                    return KAL_FALSE;
                }
    op_result = KAL_TRUE;
    total_time = 0;
    memset(g_data_buffer, 0xFF, block_size);

    for (i = 0; i < op_times; i++)
    {
         if(mmi_em_fs_test_fmt_process_cancel_event())
                {
                   op_result = KAL_FALSE;
                    break;
                }
        start_time = g_fmt_test_context.get_time_handler();
        file_handler = FS_Open(file_name, FS_CREATE_ALWAYS);
        file_result = FS_Write(file_handler, g_data_buffer, block_size, &write_len);
        file_result = FS_Seek(file_handler, 0, FS_FILE_BEGIN);
        file_result = FS_Read(file_handler, g_data_buffer, block_size, &read_len);
        file_result = FS_Close(file_handler);
        file_result = FS_Delete(file_name);
        end_time = g_fmt_test_context.get_time_handler();

        if (write_len != block_size)
        {
            op_result = KAL_FALSE;
            break;
        }
         if(mmi_em_fs_test_fmt_process_cancel_event())
         {
                   op_result = KAL_FALSE;
                    break;
           }
         
        total_time += mmi_em_fs_test_get_duration_ms(start_time, end_time);
    }

    if (op_result)
        result[0] = total_time;
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_END_SCENARIO, result[0]);
#endif 
    return KAL_TRUE;
}

#if defined(__MMI_EM_PROFILING_FS_TEST_FS_SEEK__)


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_case_seek
 * DESCRIPTION
 *  
 * PARAMETERS
 *  block_size          [IN]        
 *  op_times            [IN]        
 *  result              [?]         [?]
 *  result_length       [IN]        
 *  op                  [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_em_fs_test_fmt_test_case_seek(
            kal_uint32 block_size,
            kal_uint32 op_times,
            kal_uint32 *result,
            kal_uint32 result_length,
            mmi_em_fs_test_fmt_op_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 start_time, end_time;

    kal_uint32 result_count;
    kal_uint32 file_size;
    kal_uint32 file_offset;

    FS_HANDLE file_handler;
    const WCHAR *file_name = g_fmt_test_context.long_file_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_START_SEEK, block_size, op_times, result, result_length);
#endif 
    ASSERT(result_length == 6);
    /* ASSERT(block_size<=FMT_FS_TEST_MEM_POOL_SIZE); */

    if (op & MMI_EM_FS_TEST_FMT_OP_NONE)
        return KAL_TRUE;

    if (!mmi_em_fs_test_fmt_test_create_file(file_name, FS_CREATE_ALWAYS, block_size))
        return KAL_TRUE;

    result_count = 0;

    start_time = g_fmt_test_context.get_time_handler();
    file_handler = FS_Open(file_name, FS_READ_ONLY);
    end_time = g_fmt_test_context.get_time_handler();
    ASSERT(file_handler >= 0);
    result[result_count++] = mmi_em_fs_test_get_duration_ms(start_time, end_time);

    start_time = g_fmt_test_context.get_time_handler();
    FS_Seek(file_handler, 0, FS_FILE_BEGIN);
    end_time = g_fmt_test_context.get_time_handler();
    result[result_count++] = mmi_em_fs_test_get_duration_ms(start_time, end_time);

    FS_GetFileSize(file_handler, &file_size);
    file_offset = file_size / 2;

    start_time = g_fmt_test_context.get_time_handler();
    FS_Seek(file_handler, file_offset, FS_FILE_BEGIN);
    end_time = g_fmt_test_context.get_time_handler();
    result[result_count++] = mmi_em_fs_test_get_duration_ms(start_time, end_time);

    start_time = g_fmt_test_context.get_time_handler();
    FS_Seek(file_handler, 0, FS_FILE_END);
    end_time = g_fmt_test_context.get_time_handler();
    result[result_count++] = mmi_em_fs_test_get_duration_ms(start_time, end_time);

    start_time = g_fmt_test_context.get_time_handler();
    FS_Close(file_handler);
    end_time = g_fmt_test_context.get_time_handler();
    result[result_count++] = mmi_em_fs_test_get_duration_ms(start_time, end_time);

    start_time = g_fmt_test_context.get_time_handler();
    FS_Delete(file_name);
    end_time = g_fmt_test_context.get_time_handler();
    result[result_count++] = mmi_em_fs_test_get_duration_ms(start_time, end_time);
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_END_FIND, __LINE__);
#endif 
    return KAL_TRUE;
}
#endif /* defined(__MMI_EM_PROFILING_FS_TEST_FS_SEEK__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_case_find
 * DESCRIPTION
 *  
 * PARAMETERS
 *  block_size          [IN]        
 *  op_times            [IN]        
 *  result              [?]         [?]
 *  result_length       [IN]        
 *  op                  [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_em_fs_test_fmt_test_case_find(
            kal_uint32 block_size,
            kal_uint32 op_times,
            kal_uint32 *result,
            kal_uint32 result_length,
            mmi_em_fs_test_fmt_op_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //WCHAR dir_name[MMI_EM_FS_TEST_FMT_MAX_PATH_LEN];
    //WCHAR tmp_file_name[MMI_EM_FS_TEST_FMT_MAX_PATH_LEN];
    WCHAR file_name_pattern[10];
    FS_DOSDirEntry dir_entry;

    kal_int16 dir_index, file_index, dir_index_to_delete, file_index_to_delete;
    kal_int16 dir_result, file_result, find_result;
    FS_HANDLE file_handler;
    kal_uint32 write_length = 0;
    kal_bool is_sucess = KAL_TRUE;

    kal_uint32 start_time, end_time, total_time;
    kal_uint32 result_count;

    file_index = -1;
    dir_index = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_START_FIND, block_size, op_times, result, result_length);
#endif 
    ASSERT(result_length == 2);
    if (op & MMI_EM_FS_TEST_FMT_OP_NONE)
        return KAL_TRUE;

    /* create 1000 folders */
    for (dir_index = 1000; dir_index > 0; dir_index--)
    {
        if(mmi_em_fs_test_fmt_process_cancel_event())
            {
                return KAL_FALSE;
            }

        kal_wsprintf(g_fmt_dir_name, "%c:\\%w%d", g_fmt_test_context.active_driver, FMT_TEST_FIND_DIR_NAME_PREFIX, dir_index);
        dir_result = FS_CreateDir(g_fmt_dir_name);

        if (dir_result < 0)
        {
            is_sucess = KAL_FALSE;
            break;
        }
    }

    /* create 1000 files */
    memset(g_data_buffer, 0xFF, 512);

    for (file_index = 1000; file_index > 0; file_index--)
    {
        if(mmi_em_fs_test_fmt_process_cancel_event())
            {
                return KAL_FALSE;
            }
        kal_wsprintf(
            g_fmt_file_name,
            "%c:\\%w%d%w",
            g_fmt_test_context.active_driver,
            FMT_TEST_FIND_LONG_FILE_PREFIX,
            file_index,
            FMT_TEST_COMMON_LONG_FILE_EXT);
        file_handler = FS_Open(g_fmt_file_name, FS_CREATE_ALWAYS);
        if (file_handler < 0)
        {
            is_sucess = KAL_FALSE;

        }
        else
        {
            file_result = FS_Write(file_handler, g_data_buffer, 512, &write_length);
            if (file_result < 0 || write_length != 512)
            {
                file_index--;
                is_sucess = KAL_FALSE;
            }
            FS_Close(file_handler);
        }

        if (!is_sucess)
            break;
    }

    if (is_sucess)
    {
        result_count = 0;
        kal_wsprintf(file_name_pattern, "%w", "*");

        start_time = g_fmt_test_context.get_time_handler();
        file_handler = FS_FindFirst(file_name_pattern, 0, 0, &dir_entry, g_fmt_file_name, 100);
        end_time = g_fmt_test_context.get_time_handler();

        if (file_handler >= 0)
        {
            result[result_count++] = mmi_em_fs_test_get_duration_ms(start_time, end_time);

            total_time = 0;

            while (1)
            {
                start_time = g_fmt_test_context.get_time_handler();
                find_result = FS_FindNext(file_handler, &dir_entry, g_fmt_file_name, 100);
                end_time = g_fmt_test_context.get_time_handler();

                total_time += mmi_em_fs_test_get_duration_ms(start_time, end_time);

                if (find_result != FS_NO_ERROR)
                {
                    break;
                }
            }

            FS_FindClose(file_handler);
            result[result_count++] = total_time;
        }
    }

    /* remove all created files and folders */
    if (dir_index >= 0)
    {
        for (dir_index_to_delete = 1000; dir_index_to_delete > dir_index; dir_index_to_delete--)
        {
             if(mmi_em_fs_test_fmt_process_cancel_event())
            {
                return KAL_FALSE;
            }
            kal_wsprintf(
                g_fmt_dir_name,
                "%c:\\%w%d",
                g_fmt_test_context.active_driver,
                FMT_TEST_FIND_DIR_NAME_PREFIX,
                dir_index_to_delete);
            FS_RemoveDir(g_fmt_dir_name);
        }
    }
    if (file_index >= 0)
    {
        for (file_index_to_delete = 1000; file_index_to_delete > file_index; file_index_to_delete--)
        {
             if(mmi_em_fs_test_fmt_process_cancel_event())
            {
                return KAL_FALSE;
            }

            kal_wsprintf(
                g_fmt_file_name,
                "%c:\\%w%d%w",
                g_fmt_test_context.active_driver,
                FMT_TEST_FIND_LONG_FILE_PREFIX,
                file_index_to_delete,
                FMT_TEST_COMMON_LONG_FILE_EXT);
            FS_Delete(g_fmt_file_name);
        }
    }
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_END_FIND, result[0], result[1]);
#endif 
    return KAL_TRUE;

}

#if defined (__MMI_EM_PROFILING_FS_TEST_FS_BASIC_RW_TIMES__)


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_case_write_read_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  block_size          [IN]        
 *  buffer_size         [IN]        
 *  result              [?]         [?]
 *  result_length       [IN]        
 *  op                  [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_em_fs_test_fmt_test_case_write_read_cache(
            kal_uint32 block_size,
            kal_uint32 buffer_size,
            kal_uint32 *result,
            kal_uint32 result_length,
            mmi_em_fs_test_fmt_op_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *file_name = g_fmt_test_context.long_file_name;
    STFSAL fsal;
    FSAL_Status fsal_status;
    kal_bool op_result;
    kal_uint32 op_times=0;
    kal_uint32 op_index, test_count;
    kal_uint32 start_time, end_time;
    kal_uint32 result_count = 0;
    kal_uint32 total_time, time_buffer[5];
    kal_int16 data;

    kal_uint8 *buffer_for_data = g_data_buffer;
    kal_uint32 buffer_size_for_data = block_size;

    kal_uint8 *buffer_for_file = g_data_buffer + buffer_size_for_data;
    kal_uint32 buffer_size_for_file = buffer_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(
        TRACE_GROUP_8,
        MMI_EM_FS_TEST_FMT_TEST_START_WRITE_AND_READ_CACHE,
        block_size,
        op_times,
        result,
        result_length);
#endif /* defined(_MMI_EM_FS_TEST_TRACE_SWITCH_) */ 
    ASSERT(result_length == 2);
    ASSERT(buffer_size_for_data + buffer_size_for_file <= FMT_FS_TEST_MEM_POOL_SIZE);

    if (op & MMI_EM_FS_TEST_FMT_OP_NONE)
        return KAL_TRUE;

    /* read/write a 16M file */
    op_times = 100;
    result_count = 0;

    if ((op & MMI_EM_FS_TEST_FMT_OP_WRITE) || (op & MMI_EM_FS_TEST_FMT_OP_NORMAL))
    {
        op_result = KAL_TRUE;

        for (test_count = 0; test_count < 5; test_count++)
        {
            time_buffer[test_count] = 0;

            if (FSAL_Open(&fsal, file_name, FSAL_WRITE) != FSAL_OK)
            {
                return KAL_TRUE;
            }

             if(mmi_em_fs_test_fmt_process_cancel_event())
                {
                      FSAL_Close(&fsal);
                      FS_Delete(file_name);
                    return KAL_FALSE;
                }
             
            FSAL_SetBuffer(&fsal, buffer_size_for_file, buffer_for_file);

            data = 0x00;
            for (op_index = 0; op_index < buffer_size_for_data; op_index++)
            {
                if (data > 0xFF)
                    data = 0;
                memset(buffer_for_data + op_index, data, 1);
                data++;
            }

            total_time = 0;

            for (op_index = 0; op_index < op_times; op_index++)
            {
                if(mmi_em_fs_test_fmt_process_cancel_event())
                {
                      FSAL_Close(&fsal);
                      FS_Delete(file_name);
                    return KAL_FALSE;
                }
                
                start_time = g_fmt_test_context.get_time_handler();
                fsal_status = FSAL_Write(&fsal, buffer_for_data, buffer_size_for_data);
                end_time = g_fmt_test_context.get_time_handler();

                if (fsal_status != FSAL_OK)
                {
                    op_result = KAL_FALSE;
                    break;
                }
                total_time += mmi_em_fs_test_get_duration_ms(start_time, end_time);
            }

            FSAL_Close(&fsal);

            if (!op_result)
            {
                FS_Delete(file_name);
                return KAL_TRUE;
            }
            /* result[result_count++] = total_time; */
            time_buffer[test_count] = total_time;

        }
        total_time = mmi_em_fs_test_average(time_buffer, 5);
        result[result_count++] = (kal_uint32) mmi_em_fs_test_trans_ratio(total_time, block_size, op_times);
    }
    else
    {
        result_count++;
    }

    if ((op & MMI_EM_FS_TEST_FMT_OP_WRITE) || (op & MMI_EM_FS_TEST_FMT_OP_NORMAL))
    {
        total_time = 0;

        for (test_count = 0; test_count < 5; test_count++)
        {
            time_buffer[test_count] = 0;
            if (FSAL_Open(&fsal, file_name, FSAL_WRITE) != FSAL_OK)
            {
                return KAL_TRUE;

            }

            if(mmi_em_fs_test_fmt_process_cancel_event())
                {
                      FSAL_Close(&fsal);
                      FS_Delete(file_name);
                    return KAL_FALSE;
                }
            
            FSAL_SetBuffer(&fsal, buffer_size_for_file, buffer_for_file);

            memset(buffer_for_data, 0x00, buffer_size_for_data);

            for (op_index = 0; op_index < op_times; op_index++)
            {
                if(mmi_em_fs_test_fmt_process_cancel_event())
                {
                      FSAL_Close(&fsal);
                      FS_Delete(file_name);
                    return KAL_FALSE;
                }
                start_time = g_fmt_test_context.get_time_handler();
                FSAL_Read(&fsal, buffer_for_data, buffer_size_for_data);
                end_time = g_fmt_test_context.get_time_handler();

                total_time += mmi_em_fs_test_get_duration_ms(start_time, end_time);
            }

            FSAL_Close(&fsal);
            /* result[result_count++] = total_time; */
            time_buffer[test_count] = total_time;
        }
        total_time = mmi_em_fs_test_average(time_buffer, 5);
        result[result_count++] = (kal_uint32) mmi_em_fs_test_trans_ratio(total_time, block_size, op_times);;
    }

    FS_Delete(file_name);
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_END_WRITE_AND_READ_CACHE, result[0], result[1]);
#endif 
    return KAL_TRUE;
}
#else /* defined (__MMI_EM_PROFILING_FS_TEST_FS_BASIC_RW_TIMES__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_fmt_test_case_write_read_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  block_size          [IN]        
 *  buffer_size         [IN]        
 *  result              [?]         [?]
 *  result_length       [IN]        
 *  op                  [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_em_fs_test_fmt_test_case_write_read_cache(
            kal_uint32 block_size,
            kal_uint32 buffer_size,
            kal_uint32 *result,
            kal_uint32 result_length,
            mmi_em_fs_test_fmt_op_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *file_name = g_fmt_test_context.long_file_name;
    STFSAL fsal;
    FSAL_Status fsal_status;
    kal_bool op_result;
    kal_uint32 op_times;
    kal_uint32 op_index;
    kal_uint32 start_time, end_time;
    kal_uint32 result_count = 0;
    kal_uint32 total_time = 0;

    kal_uint8 *buffer_for_data = g_data_buffer;
    kal_uint32 buffer_size_for_data = block_size;

    kal_uint8 *buffer_for_file = g_data_buffer + buffer_size_for_data;
    kal_uint32 buffer_size_for_file = buffer_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(
        TRACE_GROUP_8,
        MMI_EM_FS_TEST_FMT_TEST_START_WRITE_AND_READ_CACHE,
        block_size,
        op_times,
        result,
        result_length);
#endif /* defined(_MMI_EM_FS_TEST_TRACE_SWITCH_) */ 
    ASSERT(result_length == 2);
    ASSERT(buffer_size_for_data + buffer_size_for_file < FMT_FS_TEST_MEM_POOL_SIZE);

    if (op & MMI_EM_FS_TEST_FMT_OP_NONE)
        return KAL_TRUE;

    /* read/write a 16M file */
    op_times = 16 * 1024 * 1024 / buffer_size_for_data;
    result_count = 0;

    if ((op & MMI_EM_FS_TEST_FMT_OP_WRITE) || (op & MMI_EM_FS_TEST_FMT_OP_NORMAL))
    {
        op_result = KAL_TRUE;

        if (FSAL_Open(&fsal, file_name, FSAL_WRITE) != FSAL_OK)
        {
            return KAL_TRUE;
        }

        FSAL_SetBuffer(&fsal, buffer_size_for_file, buffer_for_file);

        memset(buffer_for_data, 0xFF, buffer_size_for_data);

        total_time = 0;

        for (op_index = 0; op_index < op_times; op_index++)
        {
            start_time = g_fmt_test_context.get_time_handler();
            fsal_status = FSAL_Write(&fsal, buffer_for_data, buffer_size_for_data);
            end_time = g_fmt_test_context.get_time_handler();

            if (fsal_status != FSAL_OK)
            {
                op_result = KAL_FALSE;
                break;
            }
            total_time += mmi_em_fs_test_get_duration_ms(start_time, end_time);
        }

        FSAL_Close(&fsal);

        if (!op_result)
        {
            FS_Delete(file_name);
            return KAL_TRUE;
        }
        result[result_count++] = total_time;
    }
    else
    {
        result_count++;
    }

    if ((op & MMI_EM_FS_TEST_FMT_OP_WRITE) || (op & MMI_EM_FS_TEST_FMT_OP_NORMAL))
    {
        total_time = 0;

        if (FSAL_Open(&fsal, file_name, FSAL_WRITE) != FSAL_OK)
        {
            return KAL_TRUE;

        }

        FSAL_SetBuffer(&fsal, buffer_size_for_file, buffer_for_file);

        memset(buffer_for_data, 0x00, buffer_size_for_data);

        for (op_index = 0; op_index < op_times; op_index++)
        {
            start_time = g_fmt_test_context.get_time_handler();
            FSAL_Read(&fsal, buffer_for_data, buffer_size_for_data);
            end_time = g_fmt_test_context.get_time_handler();

            total_time += mmi_em_fs_test_get_duration_ms(start_time, end_time);
        }

        result[result_count++] = total_time;

        FSAL_Close(&fsal);
    }

    FS_Delete(file_name);
#if defined(_MMI_EM_FS_TEST_TRACE_SWITCH_)
    kal_trace(TRACE_GROUP_8, MMI_EM_FS_TEST_FMT_TEST_END_WRITE_AND_READ_CACHE, result[0], result[1]);
#endif 
    return KAL_TRUE;
}
#endif /* defined (__MMI_EM_PROFILING_FS_TEST_FS_BASIC_RW_TIMES__) */ 

#endif /* ( defined (__MMI_EM_PROFILING_FS_TEST__) && !defined(FMT_NOT_PRESENT) && !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__)) */ 

