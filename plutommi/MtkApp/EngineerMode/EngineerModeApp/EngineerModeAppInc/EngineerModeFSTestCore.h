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
 *   EngineerModeFSTestCore.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines all structure needed in FS Test Core
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _EM_FS_TEST_CORE_PROG_
#define _EM_FS_TEST_CORE_PROG_

#if ( defined (__MMI_EM_PROFILING_FS_TEST__) && !defined(FMT_NOT_PRESENT) && !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__) )

//#define	__MMI_EM_PROFILING_FS_TEST_FS_SEEK__ 
#define __MMI_EM_PROFILING_FS_TEST_FS_BASIC_RW_TIMES__
//#define __MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__

//#define _MMI_EM_FS_TEST_TIME_MODIS_SWITCH_		
#define _MMI_EM_FS_TEST_TRACE_SWITCH_

#define MMI_EM_FS_TEST_FMT_RESULT_NO_ERROR    (0)
#define MMI_EM_FS_TEST_FMT_RESULT_UNFINISH    (-1)
#define MMI_EM_FS_TEST_FMT_RESULT_ERROR          (-2)

#define MMI_EM_FS_TEST_FMT_MAX_PATH_LEN      100

#define MMI_EM_FS_TEST_FMT_SAVE_LINE_MAX_CHAR_NUM 1024

#define FMT_TEST_RESULT_TIME_MAX				0xFFFFFFFF 

typedef enum
{

    MMI_EM_FS_TEST_FMT_DISK_PHONE,
#if defined(__FS_CARD_SUPPORT__)    
    MMI_EM_FS_TEST_FMT_DISK_MEMORY_CARD,
#endif
    MMI_EM_FS_TEST_FMT_DISK_TOTAL
}mmi_em_fs_test_fmt_disk_enum;

typedef enum
{
    MMI_EM_FS_TEST_FMT_CATEGORY_BASIC,
    MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
    MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
    
    MMI_EM_FS_TEST_FMT_CATEGORY_TOTAL
}mmi_em_fs_test_fmt_category_enum;

typedef enum
{

     MMI_EM_FS_TEST_FMT_OP_NONE = 0,
     MMI_EM_FS_TEST_FMT_OP_NORMAL =1,
     MMI_EM_FS_TEST_FMT_OP_READ=2,
     MMI_EM_FS_TEST_FMT_OP_WRITE=4,
     MMI_EM_FS_TEST_FMT_OP_DELETE=8,
     MMI_EM_FS_TEST_FMT_OP_SEEK=16,

     MMI_EM_FS_TEST_FMT_OP_TOTAL
}mmi_em_fs_test_fmt_op_enum;

typedef enum
{

    MMI_EM_FS_TEST_FMT_RESULT_UINT_MS,
    MMI_EM_FS_TEST_FMT_RESULT_UINT_S,
    MMI_EM_FS_TEST_FMT_RESULT_UINT_TICKS,
    MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S,

   MMI_EM_FS_TEST_FMT_RESULT_UINT_ALL
}mmi_em_fs_test_fmt_result_uint;
typedef enum
{
	/*The flowing is FS_Write and FS_Read ID */
    MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_8_ID,
    MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_8_ID,
    
    MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_128_ID,
    MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_128_ID,
    
    MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_1k_ID,
    MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_1k_ID,
    
    MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_2k_ID,
    MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_2k_ID,
    
    MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_16k_ID,
    MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_16k_ID,
    
    MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_32k_ID,
    MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_32k_ID,
    
#if defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
    MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_16MB_ID,
    MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_16MB_ID, 
#endif /* defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__) */ 
    /*The above is FS_Write and FS_Read ID*/
    
	/*FS_Delete */
    MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_DELETE_16MB_ID,
    
	/* test case Id should be added above this line */
    MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_TOTAL  
}mmi_em_fs_test_fmt_basic_test_case_id_enum;

typedef enum
{
	/*The flowing is FS_Write and FS_Read ID */
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_8_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_8_ID,
    
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_128_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_128_ID,
    
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_1k_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_1k_ID,
    
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_2k_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_2k_ID,
    
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_16k_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_16k_ID,
    
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_32k_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_32k_ID,
    
#if defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_16MB_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_16MB_ID, 
#endif /* defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__) */ 
    /*The above is FS_Write and FS_Read ID */
    
	/*FS_Delete ID*/
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_DELETE_16MB_ID,

	/*FS_Write + Flush ID*/
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_FLUSH_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_NO_FLUSH_ID,
    
	/*FS_Read + Sleep ID */
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_SLEEP_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_NO_SLEEP_ID,

	/*FS_Open/Write/Read/Delete ID*/
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_OPEN_WRITE_READ_CLOSE_DELETE_ID,
    
	/* The flowing is FS_Seek ID */
#if defined(__MMI_EM_PROFILING_FS_TEST_FS_SEEK__)
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_OPEN_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_SEEK_HEAD_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_SEEK_MID_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_SEEK_TAIL_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_CLOSE_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_DELETE_ID,

    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_OPEN_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_SEEK_HEAD_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_SEEK_MID_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_SEEK_TAIL_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_CLOSE_ID,
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_DELETE_ID,
#endif /* defined(__MMI_EM_PROFILING_FS_TEST_FS_SEEK__) */ 
	/*The above is FS_Seek ID */

	/* test case Id should be added above this line */
    MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_TOTAL
}mmi_em_fs_test_fmt_normal_test_case_id_enum;

typedef enum
{
	/*FS_FindFirst ID */
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FIND_FIRST_ID,

	/*FS_FindNext ID*/
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FIND_NEXT_ID,
    
	/*The above is FSAL_Write and Read ID*/
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_1K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_1K_ID,
    
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_2K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_2K_ID,
    
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_4K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_4K_ID,
    
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_8K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_8K_ID,
    
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_16K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_16K_ID,
    
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_1K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_1K_ID,
    
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_2K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_2K_ID,
    
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_4K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_4K_ID,
    
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_8K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_8K_ID,
    
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_16K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_16K_ID,

    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_1K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_1K_ID,
    
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_2K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_2K_ID,
    
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_4K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_4K_ID,
    
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_8K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_8K_ID,
    
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_16K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_16K_ID,

    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_1K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_1K_ID,
    
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_2K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_2K_ID,
    
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_4K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_4K_ID,
    
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_8K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_8K_ID,
    
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_16K_ID,
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_16K_ID,
	/*The above is FSAL_Write and FSAL_Write ID */

	/* test case Id should be added above this line */
    MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_TOTAL  
}mmi_em_fs_test_fmt_advance_test_case_id_enum;

typedef kal_bool(*mmi_em_fs_test_fmt_test_case_handler_ptr) (kal_uint32 block_size,
                                                             kal_uint32 op_times, kal_uint32 *result,
                                                             kal_uint32 result_length, mmi_em_fs_test_fmt_op_enum op);

typedef kal_uint32 (*mmi_em_fs_test_fmt_get_time_ptr)(void);

/*data struct for starting test req*/
typedef struct
{
    kal_uint8  ref_count;
    kal_uint16 msg_len;

    kal_uint8 * buffer;
    kal_int8 category[MMI_EM_FS_TEST_FMT_CATEGORY_TOTAL];    /*category:Basic,Normal,Advance*/
    kal_int8 drv_letter[MMI_EM_FS_TEST_FMT_DISK_TOTAL];
} mmi_em_fs_test_fmt_start_req_struct;

/*data struct for the respond to starting test req*/
typedef struct
{
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    
    kal_uint16 test_status; /*reserved*/
} mmi_em_fs_test_fmt_start_cnf_struct;

typedef struct
{
    kal_int8  category[MMI_EM_FS_TEST_FMT_CATEGORY_TOTAL];
    kal_uint32 basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_TOTAL];
    kal_uint32 normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_TOTAL];
    kal_uint32 advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_TOTAL];
}mmi_em_fs_test_fmt_result_struct;

/*data struct for the test result*/
typedef struct
{
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    
    kal_int16 result_status;                        /*Sucess:>=0;otherwise,failed*/ 
    
    mmi_em_fs_test_fmt_result_struct data[MMI_EM_FS_TEST_FMT_DISK_TOTAL];
    
} mmi_em_fs_test_fmt_finish_iln_struct;

typedef enum
{
    MMI_EM_FS_TEST_FMT_ENGINE_STATUS_INIT,
    MMI_EM_FS_TEST_FMT_ENGINE_STATUS_READY,
    MMI_EM_FS_TEST_FMT_ENGINE_STATUS_RUNNING,
    MMI_EM_FS_TEST_FMT_ENGINE_STATUS_ABORT,
    MMI_EM_FS_TEST_FMT_ENGINE_STATUS_STOPED,

    MMI_EM_FS_TEST_FMT_ENGINE_STATUS_NONE
}mmi_em_fs_test_fmt_engine_status_enum;

typedef struct
{

    kal_int8 drv_letter[MMI_EM_FS_TEST_FMT_DISK_TOTAL];
    kal_bool drv_is_dirty[MMI_EM_FS_TEST_FMT_DISK_TOTAL];
    kal_int8 category[MMI_EM_FS_TEST_FMT_CATEGORY_TOTAL];
     
    kal_int8 active_driver;

    kal_uint8 *buffer;  /* should be 32KB */

    mmi_em_fs_test_fmt_get_time_ptr get_time_handler; 
    
    WCHAR long_file_name[MMI_EM_FS_TEST_FMT_MAX_PATH_LEN];

     mmi_em_fs_test_fmt_engine_status_enum engine_status;

    kal_int16 dirty_rate;
    
}mmi_em_fs_test_fmt_conext_struct;

typedef struct
{
     mmi_em_fs_test_fmt_test_case_handler_ptr handler;
    kal_uint32 block_size;
    kal_uint32 op_times;
    kal_uint32 result_length;
    mmi_em_fs_test_fmt_op_enum op;
    
}mmi_em_fs_test_fmt_test_case_struct;

typedef struct
{

    kal_int8 driver;
    kal_uint64 total_space;
    kal_uint64 free_space;
    kal_uint16 ratio;
    
}mmi_em_fs_test_fmt_disk_info_struct;

typedef struct
{
    kal_uint8  ref_count;
    kal_uint16 msg_len;

    kal_int16 data_num;

     mmi_em_fs_test_fmt_result_struct * data_ptr[MMI_EM_FS_TEST_FMT_DISK_TOTAL];

    WCHAR file_name[MMI_EM_FS_TEST_FMT_MAX_PATH_LEN]; 

    kal_uint8 *bufffer; /* buffer for temp use */
    
}mmi_em_fs_test_fmt_save_data_req_struct;

typedef enum
{
    MMI_EM_FS_TEST_FMT_SAVE_NO_ERROR,
    MMI_EM_FS_TEST_FMT_SAVE_DISK_FULL,
    MMI_EM_FS_TEST_FMT_SAVE_PATH_NO_EXIST,
    MMI_EM_FS_TEST_FMT_SAVE_UNKNOWN_ERROR,
    MMI_EM_FS_TEST_FMT_SAVE_RESULT_TOTAL
}MMI_EM_FS_TEST_FMT_SAVE_RESULT_ENUM;
typedef struct
{
    kal_uint8  ref_count;
    kal_uint16 msg_len;

    MMI_EM_FS_TEST_FMT_SAVE_RESULT_ENUM result;
}mmi_em_fs_test_fmt_save_data_cnf_struct;

//extern void mmi_em_fs_test_cancel_callback(void);

void mmi_em_fs_test_engine_init();
void mmi_em_fs_test_set_engine_status(mmi_em_fs_test_fmt_engine_status_enum  status);
mmi_em_fs_test_fmt_engine_status_enum mmi_em_fs_test_get_engine_status();

/*the above code is added for FS Test*/
#endif /* ( defined (__MMI_EM_PROFILING_FS_TEST__) && !defined(FMT_NOT_PRESENT) && !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__)) */ 
#endif /* _EM_FS_TEST_CORE_PROG_ */ 

