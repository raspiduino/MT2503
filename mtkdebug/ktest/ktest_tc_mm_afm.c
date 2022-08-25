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
 *   ktest_tc_mm_afm.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  kal afm test case
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
 *============================================================================
 ****************************************************************************/

/* this file is valid only when __KTEST__ has been defined. */
#ifdef __KTEST__
 
#include "ktest_common.h"
#include "mmu.h"
#include "cache_sw.h"
#include "kal_afm.h"

/******************************************************************************
 * external APIs needed in this file.
 *****************************************************************************/
extern void* kal_sys_mem_alloc(kal_uint32 size);

/******************************************************************************
 * global variables and macros.
 *****************************************************************************/
#define _SIZEOF(arr) (sizeof(arr) / sizeof((arr)[0]))

#define BIG_SUBPOOL_SIZE {50, 100, 150, 300, 512, AFM_SUBPOOL_END_PATTERN}
#define BIG_SUBPOOL_NR {3, 10, 4, 1, 6, AFM_SUBPOOL_END_PATTERN}

#define SMALL_SUBPOOL_SIZE {50, AFM_SUBPOOL_END_PATTERN}
#define SMALL_SUBPOOL_NR {3, AFM_SUBPOOL_END_PATTERN}

#if defined(__MTK_TARGET__) && defined(__ARM9_MMU__)
#define OPTION	AFM_OPT_ALIGN_ALLOC | AFM_OPT_DBG | AFM_OPT_CUSLOG
#else
#define OPTION	AFM_OPT_DBG | AFM_OPT_CUSLOG
#endif

#define ABIGSIZE (KAL_AFM_POOL_OVERHEAD(OPTION, 5) + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 50, 3) \
	    + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 100, 10) + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 150, 4)  \
	    + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 300, 1) + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 512, 6))

#pragma arm section rwdata="DYNAMICCACHEABLERW_NC", zidata="DYNAMICCACHEABLEZI_NC"
static char a_cacheable_buf_nc[ABIGSIZE];
#pragma arm section rwdata, zidata
#pragma arm section rwdata="DYNAMICCACHEABLERW_C", zidata="DYNAMICCACHEABLEZI_C"
static char a_cacheable_buf_c[ABIGSIZE];
#pragma arm section rwdata, zidata

#undef OPTION
#undef ABIGSIZE

/******************************************************************************
 * do afm test (alloc/free, all query function)
 * test the following function:
 *      kal_afm_get_subpool_num
 *      kal_afm_info_get
 *      kal_afm_get_left_subpool_num
 *      kal_afm_alloc_dbg
 *      kal_afm_alloc_noncacheable_dbg
 *      kal_afm_alloc_cacheable_dbg
 *      kal_afm_free
 *      kal_afm_check_integrity
 * test sequence:
 *      Query basic information
 *      Allocate all buffer, should return non NULL
 *      Allocate again, should return NULL. check the pointer, set all buffer to 0xFE
 *      Free all
 *      Check integrity
 *****************************************************************************/
static int do_afm_alloc_test( KAL_AFM_ID afmid, kal_uint32 total_size,
                              kal_uint32 *subpool_size, kal_uint32 *subpool_nr,
                              kal_uint32 subpool_cnt, kal_uint32 option )
{
    void **ptrs;
    kal_uint32 ptrs_cnt = 0, ptrs_i = 0;
    kal_uint32 i, j;
    kal_uint32 status;
    void *p;
    kal_uint32 left;

    i = kal_afm_get_subpool_num( afmid );
    if( i != subpool_cnt )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_afm_get_subpool_num(afmid)=%u != %u",
                      i, subpool_cnt );
        ktest_reset_target();
    }

    /* check kal_afm_info_get() */
    {
        kal_uint32 option_r;
        kal_uint32 *buff_size_r, *buff_nr_r, *left_buf_nr_r;
        kal_uint32 total_left_mem_sz;
        kal_int32 t;

        buff_size_r = kal_sys_mem_alloc( sizeof(kal_uint32) * (subpool_cnt + 1) );
        buff_nr_r = kal_sys_mem_alloc( sizeof(kal_uint32) * (subpool_cnt + 1) );
        left_buf_nr_r = kal_sys_mem_alloc( sizeof(kal_uint32) * (subpool_cnt + 1) );
        if( buff_size_r == NULL || buff_nr_r == NULL || left_buf_nr_r == NULL )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "Out of sys memory" );
            ktest_reset_target();
        }

        buff_size_r[subpool_cnt] = AFM_SUBPOOL_END_PATTERN;
        buff_nr_r[subpool_cnt] = AFM_SUBPOOL_END_PATTERN;
        left_buf_nr_r[subpool_cnt] = AFM_SUBPOOL_END_PATTERN;

        t = kal_afm_info_get( afmid, &option_r, buff_size_r, buff_nr_r,
                              left_buf_nr_r, &total_left_mem_sz );
        if( t != 0 )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_afm_info_get() failed!" );
            ktest_reset_target();
        }
        if( option != option_r )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID,
                          "from kal_afm_info_get(): option: %x != %x",
                          option, option_r );
            ktest_reset_target();
        }
        ptrs_cnt = 0; left = 0;
        for( i = 0; i < subpool_cnt; i++ )
        {
            if( buff_size_r[i] < subpool_size[i] )
            {
                ktest_report( KTEST_FAIL, KTEST_TCID,
                              "from kal_afm_info_get(): subpool_size invalid" );
                ktest_reset_target();
            }
            if( buff_nr_r[i] != subpool_nr[i] )
            {
                ktest_report( KTEST_FAIL, KTEST_TCID,
                              "from kal_afm_info_get(): subpool_nr invalid" );
                ktest_reset_target();
            }
            if( left_buf_nr_r[i] != subpool_nr[i] )
            {
                ktest_report( KTEST_FAIL, KTEST_TCID,
                              "from kal_afm_info_get(): left_buf_nr_r invalid" );
                ktest_reset_target();
            }
            left += subpool_nr[i] * subpool_size[i];
        }

        if( total_left_mem_sz < left )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID,
                          "from kal_afm_info_get(): total_left_mem_sz invalid %u %u",
                          left, total_left_mem_sz );
            ktest_reset_target();
        }
    }

    for( i = 0; i < subpool_cnt; i++ )
    {
        ptrs_cnt += subpool_nr[i];
    }
    ptrs = kal_sys_mem_alloc( ptrs_cnt * sizeof(void *) );
    if( ptrs == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      ptrs_cnt * sizeof(void *) );
        ktest_reset_target();
    }

    /* allocate all buffers */
    for( i = 0; i < subpool_cnt; i++ )
    {
        for( j = 0; j < subpool_nr[i]; j++ )
        {
            kal_uint32 alloc_size;
            kal_uint32 delta;
            kal_uint32 actual_size;

            if( i == 0 )
            {
                alloc_size = 0;
            }
            else
            {
                alloc_size = subpool_size[i - 1];
            }
            delta = (subpool_size[i] - alloc_size) * (1 + j) / subpool_nr[i];
            if( delta == 0 )
            {
                delta = 1;
            }
            alloc_size += delta;

#if defined( __MTK_TARGET__ ) && defined( __ARM9_MMU__ )
            if( option & AFM_OPT_ALIGN_ALLOC )
            {
                if( (i + j) % 3 == 0 )
                {
                    p = kal_afm_alloc_noncacheable_dbg( afmid, alloc_size,
                                                        option, &actual_size,
                                                        __FILE__, __LINE__ );
                }
                else
                {
                    p = kal_afm_alloc_cacheable_dbg( afmid, alloc_size, option,
                                                     &actual_size, __FILE__,
                                                     __LINE__ );
                }
            }
            else
#endif
            {
                p = kal_afm_alloc_dbg( afmid, alloc_size, &actual_size,
                                       __FILE__, __LINE__ );
            }

            if( p == NULL )
            {
                ktest_report( KTEST_FAIL, KTEST_TCID,
                              "Couldn't allocate for size %u", alloc_size );
                ktest_reset_target();
            }
            if( actual_size < alloc_size )
            {
                ktest_report( KTEST_FAIL, KTEST_TCID,
                              "kal_afm_alloc(afmid, %u)=%p, but actual size %u < request size %u",
                              alloc_size, p, actual_size, alloc_size );
                ktest_reset_target();
            }
#if defined( __MTK_TARGET__ ) && defined( __ARM9_MMU__ )
            if( option & AFM_OPT_ALIGN_ALLOC )
            {
                if( !IS_CACHE_LINE_SIZE_ALIGNED( (kal_uint32) p ) )
                {
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_afm_alloc(afmid, %u)=%p, but p is not 32-Byte alignment",
                                  alloc_size, p );
                    ktest_reset_target();
                }
            }
#endif

/* due to cache inconsistent, disable this check */
/* if you really want it, flush the cache first !*/
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
#endif
            memset( p, 0xDF, alloc_size );

            left = kal_afm_get_left_subpool_num( afmid, alloc_size );
            if( left + j + 1 != subpool_nr[i] )
            {
                ktest_report( KTEST_FAIL, KTEST_TCID,
                              "kal_afm_get_left_subpool_num(afmid, alloc_size)=%u != %u",
                              left, subpool_nr[i] - 1 - j );
                ktest_reset_target();
            }

#if defined( __MTK_TARGET__ ) && defined( __ARM9_MMU__ )
            /* if cacheable, dynamic switch */
            if( option & AFM_OPT_ALIGN_ALLOC )
            {
                dynamic_switch_cacheable_region( &p, ((actual_size+31)/32)*32,
                                                 (i + j) % 2 == 0 ? PAGE_CACHEABLE : PAGE_NO_CACHE );
                memset( p, 0xBF, alloc_size );
            }
#endif
            if( (option & AFM_OPT_DBG)
                && (status = kal_afm_check_integrity(afmid)) != 0 )
            {
                ktest_report( KTEST_FAIL, KTEST_TCID,
                              "kal_afm_check_integrity(afmid)=%u != 0", status );
                ktest_reset_target();
            }

            ptrs[ptrs_i++] = p;
        }
    }

    /* try again, should return NULL */
    for( i = 0; i < subpool_cnt; i++ )
    {
        p = kal_afm_alloc_dbg( afmid, subpool_size[i], NULL, __FILE__, __LINE__ );
        if( p != NULL )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_afm_alloc(afmid, %u)=%p != NULL",
                          subpool_size[i], p );
            ktest_reset_target();
        }

        left = kal_afm_get_left_subpool_num( afmid, subpool_size[i] );
        if( left != 0 )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_afm_get_left_subpool_num(afmid, %u)=%d != 0",
                          subpool_size[i], left );
            ktest_reset_target();
        }
    }

    /* free all */
    for( i = 0; i < ptrs_cnt; i++ )
    {
        kal_afm_free( afmid, ptrs[i] );
        ptrs[i] = NULL;
    }

    /* check integrity */
    if( (option & AFM_OPT_DBG)
        && (status = kal_afm_check_integrity( afmid )) != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_afm_check_integrity(afmid)=%u != 0", status );
        ktest_reset_target();
    }

    return 0;
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_size1
 * @remark brief: run do_afm_alloc_test for OPTION 0 with 1 subpool
 * @remark dependency: none
 * @remark expecation: all operation succeed, not fatal/ASSERT/exception
 *****************************************************************************/
kal_int32 ktest_afm_size1( kal_uint32 argc, void *argv )
{
    kal_uint32 subpool_size[] = SMALL_SUBPOOL_SIZE;
    kal_uint32 subpool_nr[] = SMALL_SUBPOOL_NR;
    kal_uint32 size;
    void *p;
    KAL_AFM_ID afmid; kal_uint32 left_mem;

    KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

#define OPTION	0
	size = KAL_AFM_POOL_OVERHEAD( OPTION, _SIZEOF(subpool_size)-1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 50, 3 );
    p = kal_sys_mem_alloc( size );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      size );
        ktest_reset_target();
    }

    afmid = kal_afm_create( p, size, subpool_size, subpool_nr, OPTION,
                            &left_mem );
    ktest_print( "for non option, left_mem=%u\r\n", left_mem );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF(subpool_size) - 1, OPTION );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF(subpool_size) - 1, OPTION );
#undef OPTION
    {
        kal_uint32 status = kal_afm_delete( afmid );
        if( status != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_afm_delete(afmid) = %u",
                          status );
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    return KTEST_PASS;
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_size2
 * @remark brief: run do_afm_alloc_test for OPTION 0 with multiple subpools
 * @remark dependency: none
 * @remark expecation: all operation succeed, not fatal/ASSERT/exception
 *****************************************************************************/
kal_int32 ktest_afm_size2( kal_uint32 argc, void *argv )
{
    kal_uint32 subpool_size[] = BIG_SUBPOOL_SIZE;
    kal_uint32 subpool_nr[] = BIG_SUBPOOL_NR;
    kal_uint32 size;
    void *p;
    KAL_AFM_ID afmid; kal_uint32 left_mem;

    KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

#define OPTION	0
	size = KAL_AFM_POOL_OVERHEAD( OPTION, _SIZEOF(subpool_size) - 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 50, 3 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 100, 10 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 150, 4 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 300, 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 512, 6 );
	p = kal_sys_mem_alloc( size );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      size );
        ktest_reset_target();
    }

    afmid = kal_afm_create( p, size, subpool_size, subpool_nr, OPTION,
                            &left_mem );
    ktest_print( "for non option, left_mem=%u\r\n", left_mem );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
#undef OPTION
    {
        kal_uint32 status = kal_afm_delete( afmid );
        if( status != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_afm_delete(afmid) = %u",
                          status );
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    return KTEST_PASS;
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_size3
 * @remark brief: run do_afm_alloc_test for OPTION AFM_OPT_DBG with 1 subpool
 * @remark dependency: none
 * @remark expecation: all operation succeed, not fatal/ASSERT/exception
 *****************************************************************************/
kal_int32 ktest_afm_size3( kal_uint32 argc, void *argv )
{
    kal_uint32 subpool_size[] = SMALL_SUBPOOL_SIZE;
    kal_uint32 subpool_nr[] = SMALL_SUBPOOL_NR;
    kal_uint32 size;
    void *p;
    KAL_AFM_ID afmid; kal_uint32 left_mem;

    KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

#define OPTION	AFM_OPT_DBG
	size = KAL_AFM_POOL_OVERHEAD( OPTION, _SIZEOF( subpool_size ) - 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 50, 3 );
    p = kal_sys_mem_alloc( size );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      size );
        ktest_reset_target();
    }

    afmid = kal_afm_create( p, size, subpool_size, subpool_nr, OPTION,
                            &left_mem );
    ktest_print( "for option 0x%08x, left_mem=%u\r\n", OPTION, left_mem );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
#undef OPTION
    {
        kal_uint32 status = kal_afm_delete( afmid );
        if( status != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_afm_delete(afmid) = %u",
                          status );
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    return KTEST_PASS;
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_size4
 * @remark brief: run do_afm_alloc_test for OPTION AFM_OPT_DBG with multiple subpools
 * @remark dependency: none
 * @remark expecation: all operation succeed, not fatal/ASSERT/exception
 *****************************************************************************/
kal_int32 ktest_afm_size4( kal_uint32 argc, void *argv )
{
    kal_uint32 subpool_size[] = BIG_SUBPOOL_SIZE;
    kal_uint32 subpool_nr[] = BIG_SUBPOOL_NR;
    kal_uint32 size;
    void *p;
    KAL_AFM_ID afmid; kal_uint32 left_mem;

    KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

#define OPTION	AFM_OPT_DBG
	size = KAL_AFM_POOL_OVERHEAD( OPTION, _SIZEOF( subpool_size ) - 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 50, 3 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 100, 10 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 150, 4 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 300, 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 512, 6 );
	p = kal_sys_mem_alloc( size );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      size );
        ktest_reset_target();
    }

    afmid = kal_afm_create( p, size, subpool_size, subpool_nr, OPTION,
                            &left_mem );
    ktest_print( "for option 0x%08x, left_mem=%u\r\n", OPTION, left_mem );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
#undef OPTION
    {
        kal_uint32 status = kal_afm_delete( afmid );
        if( status != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_afm_delete(afmid) = %u",
                          status );
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    return KTEST_PASS;
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_size5
 * @remark brief: run do_afm_alloc_test for OPTION AFM_OPT_CUSLOG with 1 subpool
 * @remark dependency: none
 * @remark expecation: all operation succeed, not fatal/ASSERT/exception
 *****************************************************************************/
kal_int32 ktest_afm_size5( kal_uint32 argc, void *argv )
{
    kal_uint32 subpool_size[] = SMALL_SUBPOOL_SIZE;
    kal_uint32 subpool_nr[] = SMALL_SUBPOOL_NR;
    kal_uint32 size;
    void *p;
    KAL_AFM_ID afmid; kal_uint32 left_mem;

    KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

#define OPTION	AFM_OPT_CUSLOG
	size = KAL_AFM_POOL_OVERHEAD( OPTION, _SIZEOF( subpool_size ) - 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 50, 3 );
    p = kal_sys_mem_alloc( size );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      size );
        ktest_reset_target();
    }

    afmid = kal_afm_create( p, size, subpool_size, subpool_nr, OPTION,
                            &left_mem );
    ktest_print( "for option 0x%08x, left_mem=%u\r\n", OPTION, left_mem );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
#undef OPTION
    {
        kal_uint32 status = kal_afm_delete( afmid );
        if( status != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_afm_delete(afmid) = %u",
                          status );
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    return KTEST_PASS;
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_size6
 * @remark brief: run do_afm_alloc_test for OPTION AFM_OPT_CUSLOG with multiple
 *                subpools.
 * @remark dependency: none
 * @remark expecation: all operation succeed, not fatal/ASSERT/exception
 *****************************************************************************/
kal_int32 ktest_afm_size6( kal_uint32 argc, void *argv )
{
    kal_uint32 subpool_size[] = BIG_SUBPOOL_SIZE;
    kal_uint32 subpool_nr[] = BIG_SUBPOOL_NR;
    kal_uint32 size;
    void *p;
    KAL_AFM_ID afmid; kal_uint32 left_mem;

    KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

#define OPTION	AFM_OPT_CUSLOG
	size = KAL_AFM_POOL_OVERHEAD( OPTION, _SIZEOF( subpool_size ) - 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 50, 3 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 100, 10 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 150, 4 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 300, 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 512, 6 );
	p = kal_sys_mem_alloc( size );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      size );
        ktest_reset_target();
    }

    afmid = kal_afm_create( p, size, subpool_size, subpool_nr, OPTION,
                            &left_mem );
    ktest_print( "for option 0x%08x, left_mem=%u\r\n", OPTION, left_mem );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
#undef OPTION
    {
        kal_uint32 status = kal_afm_delete( afmid );
        if( status != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_afm_delete(afmid) = %u",
                          status );
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    return KTEST_PASS;
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_size7
 * @remark brief: run do_afm_alloc_test for OPTION AFM_OPT_ALIGN_ALLOC with 1
 *                subpool.
 * @remark dependency: none
 * @remark expecation: all operation succeed, not fatal/ASSERT/exception
 *****************************************************************************/
kal_int32 ktest_afm_size7( kal_uint32 argc, void *argv )
{
    kal_uint32 subpool_size[] = SMALL_SUBPOOL_SIZE;
    kal_uint32 subpool_nr[] = SMALL_SUBPOOL_NR;
    kal_uint32 size;
    void *p;
    KAL_AFM_ID afmid; kal_uint32 left_mem;

    KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

#define OPTION	AFM_OPT_ALIGN_ALLOC
	size = KAL_AFM_POOL_OVERHEAD( OPTION, _SIZEOF( subpool_size ) - 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 50, 3 );
    p = a_cacheable_buf_c; //kal_sys_mem_alloc(size);
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      size );
        ktest_reset_target();
    }

    afmid = kal_afm_create( p, size, subpool_size, subpool_nr, OPTION,
                            &left_mem );
    ktest_print( "for option 0x%08x, left_mem=%u\r\n", OPTION, left_mem );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
#undef OPTION
    {
        kal_uint32 status = kal_afm_delete( afmid );
        if( status != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_afm_delete(afmid) = %u",
                          status );
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    return KTEST_PASS;
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_size8
 * @remark brief: run do_afm_alloc_test for OPTION AFM_OPT_ALIGN_ALLOC with
 *                multiple subpools.
 * @remark dependency: none
 * @remark expecation: all operation succeed, not fatal/ASSERT/exception
 *****************************************************************************/
kal_int32 ktest_afm_size8( kal_uint32 argc, void *argv )
{
    kal_uint32 subpool_size[] = BIG_SUBPOOL_SIZE;
    kal_uint32 subpool_nr[] = BIG_SUBPOOL_NR;
    kal_uint32 size;
    void *p;
    KAL_AFM_ID afmid; kal_uint32 left_mem;

    KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

#define OPTION	AFM_OPT_ALIGN_ALLOC
	size = KAL_AFM_POOL_OVERHEAD( OPTION, _SIZEOF( subpool_size ) - 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 50, 3 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 100, 10 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 150, 4 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 300, 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 512, 6 );
	p = a_cacheable_buf_c; //kal_sys_mem_alloc(size);
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      size );
        ktest_reset_target();
    }

    afmid = kal_afm_create( p, size, subpool_size, subpool_nr, OPTION,
                            &left_mem );
    ktest_print( "for option 0x%08x, left_mem=%u\r\n", OPTION, left_mem );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
#undef OPTION
    {
        kal_uint32 status = kal_afm_delete( afmid );
        if( status != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_afm_delete(afmid) = %u",
                          status );
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    return KTEST_PASS;
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_size9
 * @remark brief: run do_afm_alloc_test
 *                for OPTION AFM_OPT_ALIGN_ALLOC | AFM_OPT_DBG | AFM_OPT_CUSLOG
 *                with 1 subpool on default non-cacheable memory
 * @remark dependency: none
 * @remark expecation: all operation succeed, not fatal/ASSERT/exception
 *****************************************************************************/
kal_int32 ktest_afm_size9( kal_uint32 argc, void *argv )
{
    kal_uint32 subpool_size[] = SMALL_SUBPOOL_SIZE;
    kal_uint32 subpool_nr[] = SMALL_SUBPOOL_NR;
    kal_uint32 size;
    void *p;
    KAL_AFM_ID afmid; kal_uint32 left_mem;

    if( argc == 0 )
    {
        KTEST_TCID = KTEST_FUNCTION_NAME;
    }
    else
    {
        KTEST_TCID = "ktest_afm_size11";
    }
	KTEST_EXPECT_ERR_CODE = 0;

#if defined( __MTK_TARGET__ ) && defined( __ARM9_MMU__ )
#define OPTION	AFM_OPT_ALIGN_ALLOC | AFM_OPT_DBG | AFM_OPT_CUSLOG
#else
#define OPTION	AFM_OPT_DBG | AFM_OPT_CUSLOG
#endif
	size = KAL_AFM_POOL_OVERHEAD( OPTION, _SIZEOF( subpool_size ) - 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 50, 3 );
    if( argc == 0 )
    {
        p = a_cacheable_buf_nc; //kal_sys_mem_alloc(size);
    }
    else
    {
        p = a_cacheable_buf_c; //kal_sys_mem_alloc(size);
    }
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      size );
        ktest_reset_target();
    }

    afmid = kal_afm_create( p, size, subpool_size, subpool_nr, OPTION,
                            &left_mem );
    ktest_print( "for option 0x%08x, left_mem=%u\r\n", OPTION, left_mem );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
#undef OPTION
    {
        kal_uint32 status = kal_afm_delete( afmid );
        if( status != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_afm_delete(afmid) = %u",
                          status );
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    return KTEST_PASS;
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_size10
 * @remark brief: run do_afm_alloc_test
 *                for OPTION AFM_OPT_ALIGN_ALLOC | AFM_OPT_DBG | AFM_OPT_CUSLOG
 *                with multiple subpools on default non-cacheable memory
 * @remark dependency: none
 * @remark expecation: all operation succeed, not fatal/ASSERT/exception
 *****************************************************************************/
kal_int32 ktest_afm_size10( kal_uint32 argc, void *argv )
{
    kal_uint32 subpool_size[] = BIG_SUBPOOL_SIZE;
    kal_uint32 subpool_nr[] = BIG_SUBPOOL_NR;
    kal_uint32 size;
    void *p;
    KAL_AFM_ID afmid; kal_uint32 left_mem;

    if( argc == 0 )
    {
        KTEST_TCID = KTEST_FUNCTION_NAME;
    }
    else
    {
        KTEST_TCID = "ktest_afm_size12";
    }
    KTEST_EXPECT_ERR_CODE = 0;

#if defined( __MTK_TARGET__ ) && defined( __ARM9_MMU__ )
#define OPTION	AFM_OPT_ALIGN_ALLOC | AFM_OPT_DBG | AFM_OPT_CUSLOG
#else
#define OPTION	AFM_OPT_DBG | AFM_OPT_CUSLOG
#endif
	size = KAL_AFM_POOL_OVERHEAD( OPTION, _SIZEOF( subpool_size ) - 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 50, 3 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 100, 10 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 150, 4 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 300, 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 512, 6 );
    if( argc == 0 )
    {
        p = a_cacheable_buf_nc; //kal_sys_mem_alloc(size);
    }
    else
    {
        p = a_cacheable_buf_c; //kal_sys_mem_alloc(size);
    }
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      size );
        ktest_reset_target();
    }

    afmid = kal_afm_create( p, size, subpool_size, subpool_nr, OPTION,
                            &left_mem );
    ktest_print( "for option 0x%08x, left_mem=%u\r\n", OPTION, left_mem );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
    do_afm_alloc_test( afmid, size, subpool_size, subpool_nr,
                       _SIZEOF( subpool_size ) - 1, OPTION );
#undef OPTION
    {
        kal_uint32 status = kal_afm_delete( afmid );
        if( status != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_afm_delete(afmid) = %u",
                          status );
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    return KTEST_PASS;
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_size11
 * @remark brief: run do_afm_alloc_test
 *                for OPTION AFM_OPT_ALIGN_ALLOC | AFM_OPT_DBG | AFM_OPT_CUSLOG
 *                with 1 subpool on default cacheable memory
 * @remark dependency: none
 * @remark expecation: all operation succeed, not fatal/ASSERT/exception
 *****************************************************************************/
kal_int32 ktest_afm_size11( kal_uint32 argc, void *argv )
{
    return ktest_afm_size9( 1, NULL );
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_size12
 * @remark brief: run do_afm_alloc_test
 *                for OPTION AFM_OPT_ALIGN_ALLOC | AFM_OPT_DBG | AFM_OPT_CUSLOG
 *                with multiple subpools on default cacheable memory
 * @remark dependency: none
 * @remark expecation: all operation succeed, not fatal/ASSERT/exception
 *****************************************************************************/
kal_int32 ktest_afm_size12( kal_uint32 argc, void *argv )
{
    return ktest_afm_size10( 1, NULL );
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_fallback
 * @remark brief: test afm can fallback to larger size subpool if the nearest
 *                fit size subpool is not available for default option.
 * @remark dependency: none
 * @remark expecation: afm allocate a memory from a larger size subpool
 *****************************************************************************/
kal_int32 ktest_afm_fallback( kal_uint32 argc, void *argv )
{
    kal_uint32 subpool_size[] = BIG_SUBPOOL_SIZE;
    kal_uint32 subpool_nr[] = BIG_SUBPOOL_NR;
    kal_uint32 size, i;
    void *p;
    KAL_AFM_ID afmid; kal_uint32 left_mem;

    KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

#if defined( __MTK_TARGET__ ) && defined( __ARM9_MMU__ )
#define OPTION	AFM_OPT_ALIGN_ALLOC | AFM_OPT_DBG | AFM_OPT_CUSLOG
#else
#define OPTION	AFM_OPT_DBG | AFM_OPT_CUSLOG
#endif
	size = KAL_AFM_POOL_OVERHEAD( OPTION, _SIZEOF( subpool_size ) - 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 50, 3 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 100, 10 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 150, 4 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 300, 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 512, 6 );
    if( argc == 0 )
    {
        p = a_cacheable_buf_nc; //kal_sys_mem_alloc(size);
    }
    else
    {
        p = a_cacheable_buf_c; //kal_sys_mem_alloc(size);
    }

    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      size );
        ktest_reset_target();
    }

    afmid = kal_afm_create( p, size, subpool_size, subpool_nr, OPTION,
                            &left_mem );
#undef OPTION
    for( i = 0; i < 3 + 10 + 4 + 1 + 6; i++ )
    {
        /* if i > 3, size pool 50 run out & fallback happend. */
        p = kal_afm_alloc( afmid, 50 );
        if( p == NULL )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_afm_alloc(afmid, 50) should not return NULL" );
            ktest_reset_target();
        }
    }
    /* now check all size pool run out */
    for( i = 1; i < _SIZEOF( subpool_size ) - 1; i++ )
    {
        p = kal_afm_alloc( afmid, subpool_size[i] );
        if( p != NULL )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_afm_alloc(afmid, 50) should return NULL" );
            ktest_reset_target();
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    return KTEST_PASS;
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_no_fallback
 * @remark brief: test afm won't fallback to larger size subpool if the
 * nearest fit size subpool is not available for option AFM_OPT_NOFALLBACK_ALLOC
 * @remark dependency: none
 * @remark expecation: afm allocate no memory
 *****************************************************************************/
kal_int32 ktest_afm_no_fallback( kal_uint32 argc, void *argv )
{
    kal_uint32 subpool_size[] = BIG_SUBPOOL_SIZE;
    kal_uint32 subpool_nr[] = BIG_SUBPOOL_NR;
    kal_uint32 size, i;
    void *p;
    KAL_AFM_ID afmid; kal_uint32 left_mem;

    KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

#if defined( __MTK_TARGET__ ) && defined( __ARM9_MMU__ )
#define OPTION	AFM_OPT_ALIGN_ALLOC | AFM_OPT_DBG | AFM_OPT_CUSLOG | AFM_OPT_NOFALLBACK_ALLOC
#else
#define OPTION	AFM_OPT_DBG | AFM_OPT_CUSLOG | AFM_OPT_NOFALLBACK_ALLOC
#endif
	size = KAL_AFM_POOL_OVERHEAD( OPTION, _SIZEOF( subpool_size ) - 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 50, 3 )
           + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 100, 10 )
           + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 150, 4 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 300, 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 512, 6 );
    if( argc == 0 )
    {
        p = a_cacheable_buf_nc; //kal_sys_mem_alloc(size);
    }
    else
    {
        p = a_cacheable_buf_c; //kal_sys_mem_alloc(size);
    }

    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      size );
        ktest_reset_target();
    }

    afmid = kal_afm_create( p, size, subpool_size, subpool_nr, OPTION,
                            &left_mem );
    if( afmid == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_afm_create() == NULL" );
        ktest_reset_target();
    }
#undef OPTION
    /* size pool 50 run out */
    for( i = 0; i < 3; i++ )
    {
        p = kal_afm_alloc( afmid, 50 );
        if( p == NULL )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_afm_alloc(afmid, 50) should not return NULL" );
            ktest_reset_target();
        }
    }
    /* now check no fallback to next size */
    p = kal_afm_alloc( afmid, 50 );
    if( p != NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_afm_alloc(afmid, 50) should return NULL" );
        ktest_reset_target();
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    return KTEST_PASS;
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_create_invalid_subpoolsize
 * @remark brief: afm create funtion will fail (ASSERT or return NULL) for
 *                invalid subpool size setting
 * @remark dependency: none
 * @remark expecation: kal_afm_create return NULL
 *****************************************************************************/
kal_int32 ktest_afm_create_invalid_subpoolsize( kal_uint32 argc, void *argv )
{
    kal_uint32 subpool_size[] = {5, 15, 7, AFM_SUBPOOL_END_PATTERN};
    kal_uint32 subpool_nr[] = SMALL_SUBPOOL_NR;
    kal_uint32 size;
    void *p;
    KAL_AFM_ID afmid; kal_uint32 left_mem;

    KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_AFM_CREATE_FAILED;

#define OPTION	AFM_OPT_DBG
	size = KAL_AFM_POOL_OVERHEAD( OPTION, _SIZEOF( subpool_size ) - 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 50, 3 );
    p = kal_sys_mem_alloc( size );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      size );
        ktest_reset_target();
    }

    afmid = kal_afm_create( p, size, subpool_size, subpool_nr, OPTION,
                            &left_mem );

#undef OPTION
    if( afmid == NULL )
    {
        ktest_report( KTEST_PASS, KTEST_TCID,
                      "kal_afm_create() == NULL for invalid subpool_size parameter",
                      afmid );
        return KTEST_PASS;
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "ASSERT or afmid(%p) == NULL expected", afmid );
        return KTEST_FAIL;
    }
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_create_invalid_subpoolnr
 * @remark brief: afm create funtion will fail (ASSERT or return NULL) for
 *                invalid subpool nr setting.
 * @remark dependency: none
 * @remark expecation: kal_afm_create return NULL
 *****************************************************************************/
kal_int32 ktest_afm_create_invalid_subpoolnr( kal_uint32 argc, void *argv )
{
    kal_uint32 subpool_size[] = SMALL_SUBPOOL_SIZE;
    kal_uint32 subpool_nr[] = {3, 7, AFM_SUBPOOL_END_PATTERN};
    kal_uint32 size;
    void *p;
    KAL_AFM_ID afmid; kal_uint32 left_mem;

    KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_AFM_CREATE_FAILED;

#define OPTION	AFM_OPT_DBG
	size = KAL_AFM_POOL_OVERHEAD( OPTION, _SIZEOF( subpool_size ) - 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 50, 3 );
    p = kal_sys_mem_alloc( size );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      size );
        ktest_reset_target();
    }

    afmid = kal_afm_create( p, size, subpool_size, subpool_nr, OPTION,
                            &left_mem );
#undef OPTION
    if( afmid == NULL )
    {
        ktest_report( KTEST_PASS, KTEST_TCID,
                      "kal_afm_create() == NULL for invalid subpool_nr parameter",
                      afmid );
        return KTEST_PASS;
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "ASSERT or afmid(%p) == NULL expected", afmid );
        return KTEST_FAIL;
    }
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_corrupt_head
 * @remark brief: afm can detect header corruption for option AFM_OPT_DBG
 * @remark dependency: none
 * @remark expecation: ASSERT
 *****************************************************************************/
kal_int32 ktest_afm_corrupt_head( kal_uint32 argc, void *argv )
{
    kal_uint32 subpool_size[] = SMALL_SUBPOOL_SIZE;
    kal_uint32 subpool_nr[] = SMALL_SUBPOOL_NR;
    kal_uint32 size;
    void *p;
    KAL_AFM_ID afmid; kal_uint32 left_mem;

    KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_AFM_HEADER_FAILED;

#define OPTION	AFM_OPT_DBG
	size = KAL_AFM_POOL_OVERHEAD( OPTION, _SIZEOF( subpool_size ) - 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 50, 3 );
    p = kal_sys_mem_alloc( size );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      size );
        ktest_reset_target();
    }

    afmid = kal_afm_create( p, size, subpool_size, subpool_nr, OPTION,
                            &left_mem );

    p = kal_afm_alloc( afmid, subpool_size[0] );
    *( (int *) p - 1 ) = 0xaaaaaaa;
    kal_afm_free( afmid, p );

#undef OPTION
    ktest_report( KTEST_FAIL, KTEST_TCID, "ASSERT expected!" );
    return KTEST_FAIL;
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_corrupt_foot
 * @remark brief: afm can detect footer corruption for option AFM_OPT_DBG
 * @remark dependency: none
 * @remark expecation: ASSERT
 *****************************************************************************/
kal_int32 ktest_afm_corrupt_foot( kal_uint32 argc, void *argv )
{
    kal_uint32 subpool_size[] = SMALL_SUBPOOL_SIZE;
    kal_uint32 subpool_nr[] = SMALL_SUBPOOL_NR;
    kal_uint32 size;
    void *p;
    KAL_AFM_ID afmid; kal_uint32 left_mem;

    KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_AFM_FOOTER_FAILED;

#define OPTION	AFM_OPT_DBG
	size = KAL_AFM_POOL_OVERHEAD( OPTION, _SIZEOF( subpool_size ) - 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 50, 3 );
    p = kal_sys_mem_alloc( size );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      size );
        ktest_reset_target();
    }

    afmid = kal_afm_create( p, size, subpool_size, subpool_nr, OPTION,
                            &left_mem );

    p = kal_afm_alloc( afmid, subpool_size[0] );
    ((int *) p)[(subpool_size[0] + 3) / 4] = 0xaaaaaaa;
    kal_afm_free( afmid, p );

#undef OPTION
    ktest_report( KTEST_FAIL, KTEST_TCID, "ASSERT expected!" );
    return KTEST_FAIL;
}

/******************************************************************************
 * @remark category: afm
 * @remark name: ktest_afm_test_cuslogging
 * @remark brief: test afm can start/stop/pause/clear custom logging,
 *                and retrieve correct result.
 * @remark dependency: none
 * @remark expecation: all operation succeeded
 *****************************************************************************/
kal_int32 ktest_afm_test_cuslogging( kal_uint32 argc, void *argv )
{
    kal_uint32 subpool_size[] = BIG_SUBPOOL_SIZE; //{50, 100, 150, 300, 512, AFM_SUBPOOL_END_PATTERN}
    kal_uint32 subpool_nr[] = BIG_SUBPOOL_NR; //{3, 10, 4, 1, 6, AFM_SUBPOOL_END_PATTERN}
    kal_uint32 size;
    void *p, *p1, *p2, *p3;
    KAL_AFM_ID afmid; kal_uint32 left_mem;
    kal_uint32 logen;

    kal_uint32 subpool_size2[] = {0, 0, 0, 0, 0, AFM_SUBPOOL_END_PATTERN};
    kal_uint32 subpool_nr2[] = {0, 0, 0, 0, 0, AFM_SUBPOOL_END_PATTERN};
    kal_uint32 alloc_cnt2[] = {0, 0, 0, 0, 0, AFM_SUBPOOL_END_PATTERN};
    kal_uint32 minleft2[] = {0, 0, 0, 0, 0, AFM_SUBPOOL_END_PATTERN};
    kal_uint32 option;

    KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

#define OPTION	AFM_OPT_DBG | AFM_OPT_CUSLOG
	size = KAL_AFM_POOL_OVERHEAD( OPTION, _SIZEOF( subpool_size ) - 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 50, 3 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 100, 10 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 150, 4 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 300, 1 )
	       + KAL_AFM_SUBPOOL_OVERHEAD( OPTION, 512, 6 );
    p = a_cacheable_buf_c; //kal_sys_mem_alloc(size);
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc(%u) == NULL",
                      size );
        ktest_reset_target();
    }

    afmid = kal_afm_create( p, size, subpool_size, subpool_nr, OPTION,
                            &left_mem );
#undef OPTION
    if( kal_afm_get_cuslogging( afmid, &logen ) != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_afm_get_cuslogging(afmid) failed" );
        ktest_reset_target();
    }
    if( logen != AFM_LOG_STR )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "logen %d != AFM_LOG_STR", logen );
        ktest_reset_target();
    }
    if( kal_afm_set_cuslogging( afmid, AFM_LOG_PAUSE | AFM_LOG_CLR ) != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_afm_set_cuslogging(afmid, AFM_LOG_PAUSE | AFM_LOG_CLR) failed" );
        ktest_reset_target();
    }
    if( kal_afm_set_cuslogging( afmid, AFM_LOG_STR | AFM_LOG_CLR ) != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_afm_set_cuslogging(afmid, AFM_LOG_PAUSE | AFM_LOG_CLR) failed" );
        ktest_reset_target();
    }

    /* allocate 3 buffers on pool0, and assert its performance counters */
    p1 = kal_afm_alloc( afmid, 48 );
    p2 = kal_afm_alloc( afmid, 50 );
    p3 = kal_afm_alloc( afmid, 1 );
    if( kal_afm_custom_performance_info_get( afmid, &option, subpool_size2,
                                             subpool_nr2, alloc_cnt2, minleft2 )
        != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_afm_custom_performance_info_get(afmid) failed" );
        ktest_reset_target();
    }
    if( alloc_cnt2[0] != 3 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "A. alloc_cnt2[0] should be 3, but it is %u",
                      alloc_cnt2[0] );
        ktest_reset_target();
    }
    if( minleft2[0] != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "A. minleft2[0] should be 0, but it is %u", minleft2[0] );
        ktest_reset_target();
    }
    kal_afm_free( afmid, p1 );
    kal_afm_free( afmid, p2 );
    kal_afm_free( afmid, p3 );

    /* verify after free */
    if( kal_afm_custom_performance_info_get( afmid, &option, subpool_size2,
                                             subpool_nr2, alloc_cnt2, minleft2 )
        != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_afm_custom_performance_info_get(afmid) failed" );
        ktest_reset_target();
    }
    if( alloc_cnt2[0] != 3 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "B. alloc_cnt2[0] should be 3, but it is %u",
                      alloc_cnt2[0] );
        ktest_reset_target();
    }
    if( minleft2[0] != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "B. minleft2[0] should be 0, but it is %u", minleft2[0] );
        ktest_reset_target();
    }

    /* pause & clear, verify */
    kal_afm_set_cuslogging( afmid, AFM_LOG_PAUSE | AFM_LOG_CLR );
    if( kal_afm_custom_performance_info_get( afmid, &option, subpool_size2,
                                             subpool_nr2, alloc_cnt2, minleft2 )
        != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_afm_custom_performance_info_get(afmid) failed" );
        ktest_reset_target();
    }

    if( alloc_cnt2[0] != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "C. alloc_cnt2[0] should be 0, but it is %u",
                      alloc_cnt2[0] );
        ktest_reset_target();
    }

    if( minleft2[0] != 3 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "C. minleft2[0] should be 3, but it is %u", minleft2[0] );
        ktest_reset_target();
    }

    /* cuslog is pause, do some allocate... */
    p1 = kal_afm_alloc( afmid, 80 );
    p2 = kal_afm_alloc( afmid, 120 );
    p3 = kal_afm_alloc( afmid, 180 );

    if( kal_afm_custom_performance_info_get( afmid, &option, subpool_size2,
                                             subpool_nr2, alloc_cnt2, minleft2 )
        != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_afm_custom_performance_info_get(afmid) failed" );
        ktest_reset_target();
    }

    if( alloc_cnt2[0] != 0 || alloc_cnt2[1] != 0 || alloc_cnt2[2] != 0
                           || alloc_cnt2[3] != 0 || alloc_cnt2[4] != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "a. alloc_cnt2[] should be {%d, %d, %d, %d, %d}, but get {%d, %d, %d, %d, %d}",
                      0, 0, 0, 0, 0, alloc_cnt2[0], alloc_cnt2[1],
                      alloc_cnt2[2], alloc_cnt2[3], alloc_cnt2[4] );
        ktest_reset_target();
    }

    if( minleft2[0] != 3 || minleft2[1] != 10 || minleft2[2] != 4
                         || minleft2[3] != 1 || minleft2[4] != 6 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "a. minleft2[] should be {%d, %d, %d, %d, %d}, but get {%d, %d, %d, %d, %d}",
                      3, 10, 4, 1, 6, minleft2[0], minleft2[1], minleft2[2],
                      minleft2[3], minleft2[4] );
        ktest_reset_target();
    }

    kal_afm_free( afmid, p1 );
    kal_afm_free( afmid, p2 );
    kal_afm_free( afmid, p3 );

    /* start again */
    if( kal_afm_set_cuslogging( afmid, AFM_LOG_STR ) != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_afm_set_cuslogging(afmid, AFM_LOG_PAUSE | AFM_LOG_CLR) failed" );
        ktest_reset_target();
    }

    /* alloc & verify */
    p1 = kal_afm_alloc( afmid, 80 );
    p2 = kal_afm_alloc( afmid, 120 );
    p3 = kal_afm_alloc( afmid, 180 );

    if( kal_afm_custom_performance_info_get( afmid, &option, subpool_size2,
                                             subpool_nr2, alloc_cnt2, minleft2 )
        != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_afm_custom_performance_info_get(afmid) failed" );
        ktest_reset_target();
    }

    if( alloc_cnt2[0] != 0 || alloc_cnt2[1] != 1 || alloc_cnt2[2] != 1
                           || alloc_cnt2[3] != 1 || alloc_cnt2[4] != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "b. alloc_cnt2[] should be {%d, %d, %d, %d, %d}, but get {%d, %d, %d, %d, %d}",
                      0, 1, 1, 1, 0, alloc_cnt2[0], alloc_cnt2[1],
                      alloc_cnt2[2], alloc_cnt2[3], alloc_cnt2[4] );
        ktest_reset_target();
    }

    if( minleft2[0] != 3 || minleft2[1] != 9 || minleft2[2] != 3
                         || minleft2[3] != 0 || minleft2[4] != 6 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "b. minleft2[] should be {%d, %d, %d, %d, %d}, but get {%d, %d, %d, %d, %d}",
                      3, 9, 3, 0, 6, minleft2[0], minleft2[1], minleft2[2],
                      minleft2[3], minleft2[4] );
        ktest_reset_target();
    }

    kal_afm_free( afmid, p1 );
    kal_afm_free( afmid, p2 );
    kal_afm_free( afmid, p3 );

    {
        kal_uint32 status = kal_afm_delete( afmid );
        if( status != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_afm_delete(afmid) = %u",
                          status );
            ktest_reset_target();
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    return KTEST_PASS;
}

/******************************************************************************
 * test case table of afm module in pre-schedule stage.
 * note that the ones wrapped with FIX_OSCAR_FAIL will only be tested on target,
 *           but will be ignored on OSCAR.
 *****************************************************************************/
const ktest_tc_struct ktest_pre_tc_mm_afm_tbl[] =
{
	{ktest_fake_test, 0, NULL}
};

/******************************************************************************
 * test case table of afm module in post-schedule stage.
 * note that the ones wrapped with FIX_OSCAR_FAIL will only be tested on target,
 *           but will be ignored on OSCAR.
 *****************************************************************************/
const ktest_tc_struct ktest_tc_mm_afm_tbl[] =
{
    {ktest_afm_size1, 0, NULL},
	{ktest_afm_size2, 0, NULL},
	{ktest_afm_size3, 0, NULL},
	{ktest_afm_size4, 0, NULL},
	{ktest_afm_size5, 0, NULL},
	{ktest_afm_size6, 0, NULL},
	{ktest_afm_size7, 0, NULL},
	{ktest_afm_size8, 0, NULL},
	{ktest_afm_size9, 0, NULL},
	{ktest_afm_size10, 0, NULL},
	{ktest_afm_size11, 0, NULL},
	{ktest_afm_size12, 0, NULL},
	{ktest_afm_fallback, 0, NULL},
	{ktest_afm_no_fallback, 0, NULL},
	{ktest_afm_create_invalid_subpoolsize, 0, NULL},
	{ktest_afm_create_invalid_subpoolnr, 0, NULL},
	{ktest_afm_corrupt_head, 0, NULL},
	{ktest_afm_corrupt_foot, 0, NULL},
	{ktest_afm_test_cuslogging, 0, NULL},
};

/******************************************************************************
 * Name:
 *     ktest_pre_tc_mm_afm_num
 * Functionality:
 *     caculate there are how many test cases of afm module in pre-schedule
 *     stage.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of test cases of afm moduel in pre-schedule stage.
 *****************************************************************************/
kal_uint32 ktest_pre_tc_mm_afm_num( void )
{
	return sizeof( ktest_pre_tc_mm_afm_tbl ) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * Name:
 *     ktest_tc_mm_afm_num
 * Functionality:
 *     caculate there are how many test cases of afm module in post-schedule
 *     stage.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of test cases of afm module in post-schedule stage.
 *****************************************************************************/
kal_uint32 ktest_tc_mm_afm_num( void )
{
	return sizeof( ktest_tc_mm_afm_tbl ) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * Name:
 *     ktest_mm_afm_init
 * Functionality:
 *     the initialization function of afm module.
 * Parameters:
 *     mod: id of afm module.
 * Returns:
 *     void.
 * Note:
 *     we should call this function in ktest_testcase_register to register
 *     afm module into KTEST.
 *****************************************************************************/
void ktest_mm_afm_init( kal_uint32 mod )
{
	tc_all_tbls[mod] = ktest_tc_mm_afm_tbl;
	pre_tc_all_tbls[mod] = ktest_pre_tc_mm_afm_tbl;

	tc_modules_num[mod] = ktest_tc_mm_afm_num();
	pre_tc_modules_num[mod] = ktest_pre_tc_mm_afm_num();
}

#endif
