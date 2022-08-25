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
 *   ktest_tc_mm_ctrlbuf.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file implements MediaTek KAL (Kernel Abstraction Layer) auto test task
 *   functions.
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/

/* this file is valid only when __KTEST__ has been defined. */
#ifdef __KTEST__
 
#include "ktest_common.h"
#include "app_buff_alloc.h"
#include "stack_buff_pool.h"
#include "Ctrl_buff_pool.h"

kal_uint32 max_consume_record[RPS_CREATED_CTRL_BUFF_POOLS];
kal_uint32 fake;

/******************************************************************************
 * external KAL APIs that will be used in this module.
 *****************************************************************************/
extern void* kal_sys_mem_alloc( kal_uint32 size );
extern void kal_sys_mem_free( void* mem_ptr );
extern void* kal_debug_mem_alloc( kal_uint32 size );
extern void kal_debug_mem_free( void* mem_ptr );

/******************************************************************************
 * Name:
 *     ktest_mem_poolid_corruption
 * Functionality:
 *     test control buffer pool id corruption fata error.
 * Results:
 *     if a fatal error with code KAL_ERROR_BUFFMNGR_ISVALID_FAILED occurs,
 *     report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32  ktest_mem_poolid_corruption( kal_uint32 argc, void *argv )
{
    void *buff_ptr;
    void *update_ptr = NULL;
    kal_uint32 corrupted_pool_id = 0x55555555;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_ISVALID_FAILED;

    buff_ptr = get_ctrl_buffer( 8 );

    /* corrupt the pool id. */
    update_ptr = (kal_char *) KAL_GET_POOLID_PTR_IN_BUFF_HEADER( buff_ptr );
    kal_mem_cpy( (void *) update_ptr, (void *) &corrupted_pool_id,
                 sizeof( kal_poolid ) );

    /* should fatal error and report the result in the fatal error handler.*/
    free_ctrl_buffer( buff_ptr );

    /* report FAIL if no fatal error occurs. */
    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_mem_leakage
 * Functionality:
 *     test control buffer memory leakage fatal error.
 * Results:
 *     if a fatal error with code KAL_ERROR_BUFFMNGR_GETBUFF_FAILED occurs,
 *     report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mem_leakage( kal_uint32 argc, void *argv )
{
    void *buff_ptr;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_GETBUFF_NOT_AVAILABLE;

    /* make a memory leakage issue. */
    do
    {
        buff_ptr = get_ctrl_buffer( 8 );
    } while( buff_ptr != NULL );

    /* report FAIL if no fatal error occurs. */
    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
}


/******************************************************************************
 * Name:
 *     ktest_mem_pool_info_corruption
 * Functionality:
 *     test control buffer memory structure ctrl_buff_pool_info_g ASSERT happen.
 * Results:
 *     if a fatal error with code KAL_ERROR_BUFFMNGR_GETBUFF_FAILED with
 *     sub error code KAL_ERROR_KAL_SUB_ERROR_CODE2 occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32  ktest_mem_pool_info_corruption( kal_uint32 argc, void *argv )
{
    void *buff_ptr;
    kal_int32 pool_indx = 0;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_GETBUFF_POOL_NOT_EXIST;

    /* corrupte ctrl_buff_pool_info_g. */
    while( pool_indx < RPS_CREATED_CTRL_BUFF_POOLS )
    {
        ctrl_buff_pool_info_g[pool_indx++].pool_id = NULL;
    }

    buff_ptr = get_ctrl_buffer( 8 );

    /* report FAIL if no fatal error occurs. */
    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_mem_allocate_size_check
 * Functionality:
 *     test user error input 0 size buffer request, ASSERT will happen.
 * Results:
 *     if an ASSERT with exception buff_size > 0 occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mem_allocate_size_check( kal_uint32 argc, void *argv )
{
    void *buff_ptr;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE =KAL_ERROR_BUFFMNGR_GETBUFF_FAILED;

    /* make a memory leakage issue. */
    buff_ptr = get_ctrl_buffer( 0 );

    /* report FAIL if no fatal error occurs. */
    ktest_report( KTEST_FAIL, KTEST_TCID,NULL );
}

/******************************************************************************
 * Name:
 *     ktest_mem_allocate_size_check2
 * Functionality:
 *     test user request size beyond pool max size, ASSERT will happen.
 * Results:
 *     if an ASSERT exception pool_indx < RPS_CREATED_CTRL_BUFF_POOLS occurs,
 *     report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mem_allocate_size_check2( kal_uint32 argc, void *argv )
{
    void *buff_ptr;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_GETBUFF_POOLINDX_OUT_OF_RANGE;

    /* try to alloate a bigger one. */
    buff_ptr = get_ctrl_buffer( 0xFFFFFFFF );

    /* report FAIL if no fatal error occurs. */
    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_mem_allocate_header_corrupt_detect
 * Functionality:
 *     test control buffer header corruption when allocating fatal error.
 * Results:
 *     if a fatal error with code KAL_ERROR_BUFFMNGR_HEADER_FAILED_GET occurs,
 *     report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mem_allocate_header_corrupt_detect( kal_uint32 argc, void *argv )
{
    void *buff_ptr;
    kal_uint32 *header;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_HEADER_FAILED_GET;

    /* make a header corruption issue when allocate. */
    buff_ptr = get_ctrl_buffer( 8 );
    free_ctrl_buffer( buff_ptr );

    header = (kal_uint32 *) ( (kal_uint8 *) buff_ptr - KAL_BUFF_HEADER_SIZE );
    *header = 0x55555555;

    do
    {
        buff_ptr = get_ctrl_buffer( 8 );
    } while( buff_ptr != NULL );

    /* report FAIL if no fatal error occurs. */
    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_mem_allocate_footer_corrupt_detect
 * Functionality:
 *     test control buffer footer corruption when allocating fatal error.
 * Results:
 *     if a fatal error with code KAL_ERROR_BUFFMNGR_FOOTER_FAILED_GET occurs,
 *     report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mem_allocate_footer_corrupt_detect( kal_uint32 argc, void *argv )
{
    void *buff_ptr;
    kal_uint8 *footer;
    kal_uint8 i;
    void *tmp_ptr;
    kal_internal_poolid pool_id_ptr;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_FOOTER_FAILED_GET;

    /* make a footer corruption issue when allocate. */
    buff_ptr = get_ctrl_buffer( 8 );
    free_ctrl_buffer( buff_ptr );

    tmp_ptr = KAL_GET_POOLID_PTR_IN_BUFF_HEADER( buff_ptr );
    kal_mem_cpy( (void *) &pool_id_ptr, (void *) tmp_ptr, sizeof( kal_poolid ) );

    footer = (kal_uint8 *)( (kal_uint8 *) buff_ptr + pool_id_ptr->buff_size );

    for( i = 0; i < 4; i++ )
    {
        *footer = 0x55;
        footer += 1;
    }

    do
    {
        buff_ptr = get_ctrl_buffer( 8 );
    } while( buff_ptr != NULL );

    /* report FAIL if no fatal error occurs. */
    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_mem_free_header_corrupt_detect
 * Functionality:
 *     test control buffer header corruption when free fatal error.
 * Results:
 *     if a fatal error with code KAL_ERROR_BUFFMNGR_HEADER_FAILED_GET occurs,
 *     report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mem_free_header_corrupt_detect( kal_uint32 argc, void *argv )
{
    void *buff_ptr;
    kal_uint8 *header;
    kal_uint8 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_HEADER_FAILED;

    /* make a header corrupt issue when allocate. */
    buff_ptr = get_ctrl_buffer( 8 );
    header = (kal_uint8 *) ( (kal_uint8 *) buff_ptr - KAL_BUFF_HEADER_SIZE );
    for( i=0; i<4; i++ )
    {
        *header = 0x55;
        header += 1;
    }

    free_ctrl_buffer( buff_ptr );

    /* report FAIL if no fatal error occurs. */
    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_mem_free_footer_corrupt_detect
 * Functionality:
 *     test control buffer footer corruption when free fatal error.
 * Results:
 *     if a fatal error with code KAL_ERROR_BUFFMNGR_STAMP_FAILED occurs,
 *     report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mem_free_footer_corrupt_detect( kal_uint32 argc, void *argv )
{
    void *buff_ptr;
    void *tmp_ptr;
    kal_internal_poolid pool_id_ptr;
    kal_uint8 *footer;
    kal_uint8 i;
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_FOOTER_FAILED;

    /* make a memory leakage issue. */
    buff_ptr = get_ctrl_buffer( 8 );
    tmp_ptr = KAL_GET_POOLID_PTR_IN_BUFF_HEADER( buff_ptr );
    kal_mem_cpy( (void *) &pool_id_ptr, (void *) tmp_ptr, sizeof( kal_poolid ) );
    footer = (kal_uint8 *) ( (kal_uint8 *) buff_ptr + pool_id_ptr->buff_size );
    for( i=0; i<4; i++ )
    {
        *footer = 0x55;
        footer += 1;
    }
    free_ctrl_buffer( buff_ptr );

    /* report FAIL if no fatal error occurs. */
    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
}


/******************************************************************************
 * Name:
 *     ktest_mem_free_buff_arg_error
 * Functionality:
 *     test control buffer free input argument is NULL fatal error.
 * Results:
 *     if a fatal error with code KAL_ERROR_BUFFMNGR_RELEASEBUFF_FAILED occurs,
 *     report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mem_free_buff_arg_error( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_RELEASEBUFF_NILPTR;

    /* make an error free issue. */
    free_ctrl_buffer( NULL );

    /* report FAIL if no fatal error occurs. */
    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_mem_double_free_error
 * Functionality:
 *     test control buffer double free error fatal error.
 * Results:
 *     if a fatal error with code KAL_ERROR_BUFFMNGR_RELEASEBUFF_FAILED occurs,
 *     report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mem_double_free_error( kal_uint32 argc, void *argv )
{
    void *buff_ptr;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_RELEASEBUFF_INTERNAL_FAILED;

    /* make a double free issue. */
    buff_ptr = get_ctrl_buffer( 8 );
    free_ctrl_buffer( buff_ptr );
    free_ctrl_buffer( buff_ptr );

    /* report FAIL if no fatal error occurs. */
    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_mem_free_usr_footer_error
 * Functionality:
 *     test control buffer usr footer corruption when free fatal error.
 * Results:
 *     if a fatal error with code KAL_ERROR_BUFFMNGR_FOOTER_FAILED_GET occurs,
 *     report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mem_free_usr_footer_error( kal_uint32 argc, void *argv )
{
    void *i = NULL;
    kal_uint8 count = 0;
    void *temp = NULL;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_EXT_FOOTER_FAILED;

#if defined( DEBUG_KAL ) && defined( DEBUG_BUF2 )
    /* make a memory leakage issue. */
    i = get_ctrl_buffer( 2 );
    temp = (char *) i + 2;
    for( count = 0; count <4; count++ )
    {
        *(char *) temp = 0x55;
        temp = (char *) temp + 1;
    }

    free_ctrl_buffer( i );

    /* report FAIL if no fatal error occurs. */
    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
#else
    /* if DEBUG_BUF2 is not defined, then pass this test case. */
    ktest_report( KTEST_PASS, KTEST_TCID,
                  "DEBUG_KAL or DEBUG_BUF2 not defined, by pass." );
#endif
}

/******************************************************************************
 * Name:
 *     ktest_mem_free_buff_arg_error2
 * Functionality:
 *     test control buffer input argument error(not NULL) when free.
 * Results:
 *     if a fatal error with code KAL_ERROR_BUFFMNGR_ISVALID_FAILED occurs,
 *     report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mem_free_buff_arg_error2( kal_uint32 argc, void *argv )
{
    void *i = &fake;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_ISVALID_FAILED;

    /* make a memory leakage issue. */
    free_ctrl_buffer( i );

    /* report FAIL if no fatal error occurs. */
    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_mem_free_buff_arg_error3
 * Functionality:
 *     test control buffer address range check.
 * Results:
 *     if a fatal error with code KAL_ERROR_BUFFMNGR_ISVALID_FAILED occurs,
 *     report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mem_free_buff_arg_error3( kal_uint32 argc, void *argv )
{
    void *i;
    kal_uint32 virtual[2];

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_ISVALID_FAILED;

    /* make a memory leakage issue. */
    i = get_ctrl_buffer( 8 );
    virtual[0] = 0xF1F1F1F1;
    free_ctrl_buffer( &(virtual[1]) );

    /* report FAIL if no fatal error occurs. */
    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
}

/******************************************************************************
 * the test case below assumes at lease 5 buffer.
 *****************************************************************************/
#define KTEST_CTRL_BUFF_QUERY_NUM 5

/******************************************************************************
 * Name:
 *     ktest_mem_ctrl_buff_query
 * Functionality:
 *     test basic functionality of kal_query_ctrlbuf_max_consumption.
 * Results:
 *     if the query is the same as we expected, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mem_ctrl_buff_query( kal_uint32 argc, void *argv )
{
    kal_uint32 record[RPS_CREATED_CTRL_BUFF_POOLS];
    kal_uint8 i;
    kal_uint8 j;
    void * mark[RPS_CREATED_CTRL_BUFF_POOLS][KTEST_CTRL_BUFF_QUERY_NUM];

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_ISVALID_FAILED;

    /* make a memory leakage issue. */
    if( !kal_query_ctrlbuf_max_consumption( record ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    for( i=0; i < RPS_CREATED_CTRL_BUFF_POOLS; i++ )
    {
        if( ctrl_buff_pool_info_g[i].pool_id != 0 )
        {
            for( j = 0; j < KTEST_CTRL_BUFF_QUERY_NUM; j++ )
                mark[i][j] = get_ctrl_buffer( ctrl_buff_pool_info_g[i].size );
        }
    }

    if( !kal_query_ctrlbuf_max_consumption( max_consume_record ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    for( i = 0;
         i < RPS_CREATED_CTRL_BUFF_POOLS && ctrl_buff_pool_info_g[i].pool_id != 0;
         i++ )
    {
        if( max_consume_record[i] - record[i] != KTEST_CTRL_BUFF_QUERY_NUM )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        }
    }

    for( i = 0; i < RPS_CREATED_CTRL_BUFF_POOLS; i++ )
    {
        if( ctrl_buff_pool_info_g[i].pool_id != 0 )
        {
            for( j = 0; j < KTEST_CTRL_BUFF_QUERY_NUM; j++ )
            {
                free_ctrl_buffer( mark[i][j] );
            }
        }
    }

    if( !kal_query_ctrlbuf_max_consumption( max_consume_record ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    for( i = 0;
         i < RPS_CREATED_CTRL_BUFF_POOLS && ctrl_buff_pool_info_g[i].pool_id != 0;
         i++ )
    {
        if( max_consume_record[i] - record[i] != KTEST_CTRL_BUFF_QUERY_NUM )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_mem_system_mem_query
 * Functionality:
 *     test basic functionality of kal_sys_mem_query_freesize.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mem_system_mem_query( kal_uint32 argc, void *argv )
{
    void* record;
    kal_uint32 i = 4;
    kal_uint32 mark;
    kal_uint32 j;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_ISVALID_FAILED;

    /* make a memory leakage issue. */
    j = kal_sys_mem_query_freesize();
    mark = j;

    while( 1 )
    {
        if( mark > i )
        {
            record = kal_sys_mem_alloc( i );
            mark = kal_sys_mem_query_freesize();

            if( mark != (j - i) )
            {
                ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
            }
            else
            {
                j = mark;
                i = i<<1;
            }
        }
        else
        {
            break;
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_mem_debug_mem_query
 * Functionality:
 *     test basic functionality of kal_debug_mem_query_freesize.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mem_debug_mem_query( kal_uint32 argc, void *argv )
{
    void* record;
    kal_uint32 i = 4;
    kal_uint32 mark;
    kal_uint32 j;
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_ISVALID_FAILED;

    /* make a memory leakage issue. */
    j = kal_debug_mem_query_freesize();
    mark = j;

    while( 1 )
    {
        if( mark > i )
        {
            record = kal_debug_mem_alloc( i );
            mark = kal_debug_mem_query_freesize();
            if( mark != (j - i) )
            {
                ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
            }
            else
            {
                j = mark;
                i = i<<1;
            }
        }
        else
        {
            break;
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * test case table of ctrl_buff module in post-schedule stage.
 * note that the test case wrapped with FIX_OSCAR_FAIL will only be tested on
 *           target, but will be ignored on OSCAR.
 *****************************************************************************/
const ktest_tc_struct ktest_tc_mm_ctrlbuf_tbl[] =
{
    {ktest_mem_poolid_corruption, 0, NULL},
    {ktest_mem_leakage, 0, NULL},
    {ktest_mem_pool_info_corruption, 0, NULL},
    {ktest_mem_allocate_size_check, 0, NULL},
    {ktest_mem_allocate_size_check2, 0, NULL},
    {ktest_mem_allocate_header_corrupt_detect, 0, NULL},
    {ktest_mem_allocate_footer_corrupt_detect, 0, NULL},
    {ktest_mem_free_header_corrupt_detect, 0, NULL},
    {ktest_mem_free_footer_corrupt_detect, 0, NULL},
    {ktest_mem_free_usr_footer_error, 0, NULL},
    {ktest_mem_double_free_error, 0, NULL},
    {ktest_mem_free_buff_arg_error, 0, NULL},
    {ktest_mem_free_buff_arg_error2, 0, NULL},
    {ktest_mem_free_buff_arg_error3, 0, NULL},
    {ktest_mem_ctrl_buff_query, 0, NULL},
    {ktest_mem_system_mem_query, 0, NULL},
    {ktest_mem_debug_mem_query, 0, NULL}
};

/******************************************************************************
 * test case table of ctrl_buff module in pre-schedule stage.
 * note that the test case wrapped with FIX_OSCAR_FAIL will only be tested on
 *           target, but will be ignored on OSCAR.
 *****************************************************************************/
const ktest_tc_struct ktest_pre_tc_mm_ctrlbuf_tbl[] =
{
    {ktest_fake_test, 0, NULL},
};

/******************************************************************************
 * Name:
 *     ktest_tc_mm_ctrlbuf_num
 * Functionality:
 *     caculate there are how many test cases of ctrl_buff module in
 *     post-schedule stage.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of all test cases of ctrl_buff module in post-schedule
 *     stage.
 *****************************************************************************/
kal_uint32 ktest_tc_mm_ctrlbuf_num( void )
{
    return sizeof( ktest_tc_mm_ctrlbuf_tbl ) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * Name:
 *     ktest_pre_tc_mm_ctrlbuf_num
 * Functionality:
 *     caculate there are how many test cases of ctrl_buff module in
 *     pre-schedule stage.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of all test cases of ctrl_buff module in pre-schedule
 *     stage.
 *****************************************************************************/
kal_uint32 ktest_pre_tc_mm_ctrlbuf_num( void )
{
    return sizeof( ktest_pre_tc_mm_ctrlbuf_tbl ) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * Name:
 *     ktest_mm_ctrlbuf_init
 * Functionality:
 *     the initialize function of ctrl_buff module.
 * Parameters:
 *     mod: id of ctrl_buff module.
 * Returns:
 *     void.
 * Note:
 *     this is the initialization function of ctrl_buff module, and we should
 *     call it in ktest_testcase_register, so as to register the ctrl_buff
 *     module into KTEST.
 *****************************************************************************/
void ktest_mm_ctrlbuf_init( kal_uint32 mod )
{
    tc_all_tbls[mod] = ktest_tc_mm_ctrlbuf_tbl;
    pre_tc_all_tbls[mod] = ktest_pre_tc_mm_ctrlbuf_tbl;

    tc_modules_num[mod] = ktest_tc_mm_ctrlbuf_num();
    pre_tc_modules_num[mod] = ktest_pre_tc_mm_ctrlbuf_num();
}

#endif /*__KTEST__*/
