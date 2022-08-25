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
 *   ktest_tc_mm_adm.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/
#ifdef __KTEST__
#include "ktest_common.h"
#include <stdlib.h>
 
void *kal_sys_mem_alloc(kal_uint32 size);
#define RESET ktest_reset_target(); return KTEST_FAIL;

#define LOG_OVERHEAD 24
#define NOLOG_OVERHEAD 8
#define LOG_SIZE(x) (LOG_OVERHEAD + (x))
#define NOLOG_SIZE(x) (NOLOG_OVERHEAD + (x))

#define kal_adm_alloc_align_with_info(adm_id, size, align, actual_size) __kal_adm_alloc((adm_id), (size), (actual_size), (align) & ~ADM_OPT_MASK, __FILE__, __LINE__)
#define kal_adm_alloc_align_topmost_with_info(adm_id, size, align, actual_size) __kal_adm_alloc((adm_id), (size), (actual_size), ((align) & ~ADM_OPT_MASK) | ADM_OPT_TOPMOST_ALLOC, __FILE__, __LINE__)

#ifdef KAL_WITH_ADM_0
extern KAL_ADM_ID kal_adm_create_0(void *mem_addr, kal_uint32 size, kal_uint32 *subpool_size, kal_bool islogging);
extern void *__kal_adm_alloc_0(KAL_ADM_ID adm_id, kal_uint32 size, kal_uint32 *actual_size, kal_uint32 opt, char *filename, kal_uint32 line);
extern void *__kal_adm_alloc_nc_0(KAL_ADM_ID adm_id, kal_uint32 size, kal_uint32 *actual_size, kal_uint32 option, char *filename, kal_uint32 line);
extern void *__kal_adm_alloc_c_0(KAL_ADM_ID adm_id, kal_uint32 size, kal_uint32 *actual_size, kal_uint32 option, char *filename, kal_uint32 line);
extern void kal_adm_free_0(KAL_ADM_ID adm_id, void *mem_addr);

#define kal_adm_alloc_0(adm_id, size) __kal_adm_alloc_0((adm_id), (size), NULL, 0, __FILE__, __LINE__)
#define kal_adm_alloc_with_info_0(adm_id, size, actual_size) __kal_adm_alloc_0((adm_id), (size), (actual_size), 0x0, __FILE__, __LINE__)
#define kal_adm_alloc_align_with_info_0(adm_id, size, align, actual_size) __kal_adm_alloc_0((adm_id), (size), (actual_size), (align) & ~ADM_OPT_MASK, __FILE__, __LINE__)
#endif

#if __MTK_TARGET__
#define KTEST_ALIGN __align(1024)
#else
#define KTEST_ALIGN __declspec(align(1024))
#endif
KTEST_ALIGN char admbuf20K[20 * 1024];
KTEST_ALIGN char admbuf200K[200 * 1024];


/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_create3
 * @remark brief: Test kal_adm_alloc basic functionality on a logging adm
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_create3( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p;
    kal_status r;
    kal_uint32 rsize;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    ap = kal_adm_create( admbuf20K, sizeof( admbuf20K ), NULL, 1 );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    p = kal_adm_alloc_with_info( ap, 192, &rsize );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 192, &rsize) == NULL" );
        RESET;
    }
    if( rsize < LOG_SIZE(192) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 192, &rsize) return Non-NULL, but it's really size < 192"
                    );
        RESET;
    }

    kal_adm_free( ap, p );

    r = kal_adm_delete( ap );
    if( r != KAL_SUCCESS )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_delete() == %d", r );
        RESET;
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "kal_adm_alloc_with_info(ap, 192, &rsize) = %p, real size=%u",
                  p, rsize - LOG_OVERHEAD );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_create1
 * @remark brief: Using kal_adm_create to create a logging adm
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_create1( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p;
    kal_status r;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    ap = kal_adm_create( admbuf20K, sizeof( admbuf20K ), NULL, 1 );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }

    r = kal_adm_delete( ap );
    if( r != KAL_SUCCESS )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_delete() == %d", r );
        RESET;
    }

    ktest_report( KTEST_PASS, KTEST_TCID, "" );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_create2
 * @remark brief: Using kal_adm_create to create a no-logging adm
 * @remark dependency: none
 * @remark expecation: none
 *****************************************************************************/
kal_int32 ktest_adm_create2( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p;
    kal_status r;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    ap = kal_adm_create( admbuf20K, sizeof( admbuf20K ), NULL, 0 );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }

    r = kal_adm_delete( ap );
    if( r != KAL_SUCCESS )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_delete() == %d", r );
        RESET;
    }

    ktest_report( KTEST_PASS, KTEST_TCID, "" );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_create4
 * @remark brief: Test kal_adm_delete with an un-free memory block
 * @remark dependency: none
 * @remark expecation: kal_adm_delete return KAL_MEMORY_NOT_RELEASE
 *****************************************************************************/
kal_int32 ktest_adm_create4( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p;
    kal_status r;
    kal_uint32 rsize;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    ap = kal_adm_create( admbuf20K, sizeof( admbuf20K ), NULL, 1 );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    p = kal_adm_alloc_with_info( ap, 192, &rsize );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 192, &rsize) == NULL" );
        RESET;
    }
    if( rsize < LOG_SIZE(192) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 192, &rsize) return Non-NULL, but it's really size < 192"
                    );
        RESET;
    }

    r = kal_adm_delete( ap );
    if( r != KAL_MEMORY_NOT_RELEASE )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_delete() == %d, should be %d",
                      r, KAL_MEMORY_NOT_RELEASE );
        RESET;
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "kal_adm_alloc_with_info(ap, 192, &rsize) = %p, real size=%u",
                  p, rsize - LOG_OVERHEAD );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_alloc_size0
 * @remark brief: Test kal_adm_alloc with size=0
 * @remark dependency: none
 * @remark expecation: kal_adm_alloc with size=0 should return NULL
 *****************************************************************************/
kal_int32 ktest_adm_alloc_size0( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p;
    kal_status r;
    kal_uint32 rsize;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    ap = kal_adm_create( admbuf20K, sizeof( admbuf20K ), NULL, 1 );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    p = kal_adm_alloc_with_info( ap, 0, &rsize );
    if( p != NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 0, &rsize) = %p, BUT SHOULD BE 0",
                      p );
        RESET;
    }

    r = kal_adm_delete( ap );
    if( r != KAL_SUCCESS )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_delete() == %d, should be %d", r, KAL_SUCCESS );
        RESET;
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "kal_adm_alloc_with_info(ap, 0, &rsize) pass" );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_simplecase1
 * @remark brief: Test logging adm allocate/free: allocate a, b, c, d, free a,
 *                b, c, d, each 4 byte.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_simplecase1( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p, *pa, *pb, *pc, *pd;
    kal_status r;
    kal_uint32 rsize;

    kal_uint32 reqsize;
    kal_uint32 logging;

    KTEST_EXPECT_ERR_CODE = 0;
    if( argc == 0 )
    {
    	KTEST_TCID = KTEST_FUNCTION_NAME;
    	reqsize = 4;
    	logging = 1;
	}
	else if( argc == 1 )
    {
	    KTEST_TCID = "ktest_adm_simplecase2";
	    reqsize = 8;
	    logging = 1;
	}
	else if( argc == 2 )
    {
	    KTEST_TCID = "ktest_adm_simplecase3";
	    reqsize = 4;
	    logging = 0;
	}
	else if( argc == 3 )
    {
	    KTEST_TCID = "ktest_adm_simplecase4";
	    reqsize = 8;
	    logging = 0;
	}

    ap = kal_adm_create( admbuf20K, sizeof( admbuf20K ), NULL, logging );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    pa = kal_adm_alloc_with_info( ap, reqsize, &rsize );
    if( pa == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 0, &rsize) = %p, BUT SHOULD NOT BE 0",
                      p );
        RESET;
    }
    pb = kal_adm_alloc_with_info( ap, reqsize, &rsize );
    if( pb == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 0, &rsize) = %p, BUT SHOULD NOT BE 0",
                      p );
        RESET;
    }
    pc = kal_adm_alloc_with_info( ap, reqsize, &rsize );
    if( pc == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 0, &rsize) = %p, BUT SHOULD NOT BE 0",
                      p );
        RESET;
    }
    pd = kal_adm_alloc_with_info( ap, reqsize, &rsize );
    if( pd == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 0, &rsize) = %p, BUT SHOULD NOT BE 0",
                      p );
        RESET;
    }

    kal_adm_free( ap, pa );
    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }
    kal_adm_free( ap, pb );
    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }
    kal_adm_free( ap, pc );
    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }
    kal_adm_free( ap, pd );
    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }

    r = kal_adm_delete( ap );
    if( r != KAL_SUCCESS )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_delete() == %d, should be %d", r, KAL_SUCCESS );
        RESET;
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "kal_adm_alloc_with_info(ap, %d, &rsize) pass", reqsize );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_simplecase2
 * @remark brief: Test logging adm allocate/free: allocate a, b, c, d, free a,
 *                b, c, d, each 8 byte.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_simplecase2( kal_uint32 argc, void *argv )
{
    return ktest_adm_simplecase1( 1, NULL );
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_simplecase3
 * @remark brief: Test no-logging allocate/free: allocate a, b, c, d, free a, b,
 *                c, d, each 4 byte.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_simplecase3( kal_uint32 argc, void *argv )
{
    return ktest_adm_simplecase1( 2, NULL );
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_simplecase4
 * @remark brief: Test no-logging allocate/free: allocate a, b, c, d, free a, b,
 *                c, d, each 8 byte.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_simplecase4( kal_uint32 argc, void *argv )
{
    return ktest_adm_simplecase1( 3, NULL );
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_simplecase5
 * @remark brief: Test logging adm allocate/free: allocate a, b, c, d, free c,
 *                a, b, d, each 4 byte.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_simplecase5( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p, *pa, *pb, *pc, *pd;
    kal_status r;
    kal_uint32 rsize;

    kal_uint32 reqsize;
    kal_uint32 logging;

    KTEST_EXPECT_ERR_CODE = 0;
    if( argc == 0 )
    {
    	KTEST_TCID = KTEST_FUNCTION_NAME;
    	reqsize = 4;
    	logging = 1;
	}
	else if( argc == 1 )
    {
	    KTEST_TCID = "ktest_adm_simplecase6";
	    reqsize = 8;
	    logging = 1;
	}
	else if( argc == 2 )
    {
	    KTEST_TCID = "ktest_adm_simplecase7";
	    reqsize = 4;
	    logging = 0;
	}
	else if( argc == 3 )
    {
	    KTEST_TCID = "ktest_adm_simplecase8";
	    reqsize = 8;
	    logging = 0;
	}

    ap = kal_adm_create( admbuf20K, sizeof( admbuf20K ), NULL, logging );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    pa = kal_adm_alloc_with_info( ap, reqsize, &rsize );
    if( pa == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 0, &rsize) = %p, BUT SHOULD NOT BE 0",
                      p );
        RESET;
    }
    pb = kal_adm_alloc_with_info( ap, reqsize, &rsize );
    if( pb == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 0, &rsize) = %p, BUT SHOULD NOT BE 0",
                      p );
        RESET;
    }
    pc = kal_adm_alloc_with_info( ap, reqsize, &rsize );
    if( pc == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 0, &rsize) = %p, BUT SHOULD NOT BE 0",
                      p );
        RESET;
    }
    pd = kal_adm_alloc_with_info( ap, reqsize, &rsize );
    if( pd == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 0, &rsize) = %p, BUT SHOULD NOT BE 0",
                      p );
        RESET;
    }

    kal_adm_free( ap, pc );
    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }
    kal_adm_free( ap, pa );
    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }
    kal_adm_free( ap, pb );
    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }
    kal_adm_free( ap, pd );
    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }

    r = kal_adm_delete( ap );
    if( r != KAL_SUCCESS )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_delete() == %d, should be %d", r, KAL_SUCCESS );
        RESET;
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "kal_adm_alloc_with_info(ap, %d, &rsize) pass", reqsize );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_simplecase6
 * @remark brief: Test logging allocate/free: allocate a, b, c, d, free c, a, b,
 *                d, each 8 byte.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_simplecase6( kal_uint32 argc, void *argv )
{
    return ktest_adm_simplecase5( 1, NULL );
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_simplecase7
 * @remark brief: Test no-logging allocate/free: allocate a, b, c, d, free c, a,
 *                b, d, each 4 byte.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_simplecase7( kal_uint32 argc, void *argv )
{
    return ktest_adm_simplecase5( 2, NULL );
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_simplecase8
 * @remark brief: Test no-logging allocate/free: allocate a, b, c, d, free c, a,
 *                b, d, each 8 byte.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_simplecase8( kal_uint32 argc, void *argv )
{
    return ktest_adm_simplecase5( 3, NULL );
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_corrupte_head1
 * @remark brief: for ADM with logging, corrupte the head, offset at -0x4 (header print)
 * @remark dependency: none
 * @remark expecation: ASSERT(0)
 *****************************************************************************/
kal_int32 ktest_adm_corrupte_head1( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p;
    int *pi;
    kal_status r;
    kal_uint32 rsize;

    if( argc == 0 )
    {
	    KTEST_TCID = KTEST_FUNCTION_NAME;
		KTEST_EXPECT_ERR_CODE = KAL_ERROR_ADM_HEADER_FAILED;
	}
	else if( argc == 1 )
    {
	    KTEST_TCID = "ktest_adm_corrupte_head2";
		KTEST_EXPECT_ERR_CODE = KAL_ERROR_ADM_FREE_FAILED;
	}

    ap = kal_adm_create( admbuf20K, sizeof( admbuf20K ), NULL, 1 );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    p = kal_adm_alloc_with_info( ap, 4, &rsize );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_alloc(ap, 4) == NULL" );
        RESET;
    }
    pi = p;
    if( argc == 0 )
    {
        pi[-3] = (int) ap;
    }
    else if( argc == 1 )
    {
        pi[-4] = (int) ap;
    }

    kal_adm_free( ap, p );

    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_corrupte_head2
 * @remark brief: for ADM with logging, corrupte the head, offset at -0x10 (header print)
 * @remark dependency: none
 * @remark expecation: ASSERT(0)
 *****************************************************************************/
kal_int32 ktest_adm_corrupte_head2( kal_uint32 argc, void *argv )
{
    return ktest_adm_corrupte_head1( 1, NULL );
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_corrupte_head4
 * @remark brief: for ADM with LOG, corrupte the head, offset at -4 (header print)
 * @remark dependency: none
 * @remark expecation: ASSERT(0)
 *****************************************************************************/
kal_int32 ktest_adm_corrupte_head4( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p;
    int *pi;
    kal_status r;
    kal_uint32 rsize;

    if( argc == 0 )
    {
	    KTEST_TCID = KTEST_FUNCTION_NAME;
		KTEST_EXPECT_ERR_CODE = KAL_ERROR_ADM_HEADER_FAILED;
	}

    ap = kal_adm_create( admbuf20K, sizeof( admbuf20K ), NULL, 1 );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    p = kal_adm_alloc_with_info( ap, 4, &rsize );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_alloc(ap, 4) == NULL" );
        RESET;
    }
    pi = p;
    pi[-3] = 0;
    kal_adm_free( ap, p );

    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_corrupte_foot1
 * @remark brief: for ADM with LOG, corrupte the head, offset at 4 (footer print)
 * @remark dependency: none
 * @remark expecation: ASSERT(0)
 *****************************************************************************/
kal_int32 ktest_adm_corrupte_foot1( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p;
    int *pi;
    kal_status r;
    kal_uint32 rsize;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ADM_FOOTER_FAILED;

    ap = kal_adm_create( admbuf20K, sizeof( admbuf20K ), NULL, 1 );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    p = kal_adm_alloc_with_info( ap, 4, &rsize );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_alloc(ap, 4) == NULL" );
        RESET;
    }
    pi = p;
    pi[1] = 0;
    kal_adm_free( ap, p );

    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_corrupte_nolog_head1
 * @remark brief: for ADM with NO-LOG, corrupte the head, offset at -4 (header print)
 * @remark dependency: none
 * @remark expecation: ASSERT(0)
 *****************************************************************************/
kal_int32 ktest_adm_corrupte_nolog_head1( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p;
    int *pi;
    kal_status r;
    kal_uint32 rsize;

    if( argc == 0 )
    {
	    KTEST_TCID = KTEST_FUNCTION_NAME;
		KTEST_EXPECT_ERR_CODE = KAL_ERROR_ADM_FREE_FAILED;
	}
	else if( argc == 1 )
    {
	    KTEST_TCID = "ktest_adm_corrupte_nolog_head2";
		KTEST_EXPECT_ERR_CODE = KAL_ERROR_ADM_FREE_FAILED;
	};

    ap = kal_adm_create( admbuf20K, sizeof( admbuf20K ), NULL, 0 );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    p = kal_adm_alloc_with_info( ap, 4, &rsize );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_alloc(ap, 4) == NULL" );
        RESET;
    }
    pi = p;
    if( argc == 0 )
    {
        pi[-1] = (int) ap;
    }
    else if( argc == 1 )
    {
        pi[-2] = (int) ap;
    }
    kal_adm_free( ap, p );

    ktest_report( KTEST_FAIL, KTEST_TCID, "ASSERT(0) expected but not happened" );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_corrupte_nolog_head2
 * @remark brief: for ADM with NO-LOG, corrupte the head, offset at -8 (header print)
 * @remark dependency: none
 * @remark expecation: ASSERT(0)
 *****************************************************************************/
kal_int32 ktest_adm_corrupte_nolog_head2( kal_uint32 argc, void *argv )
{
	 return ktest_adm_corrupte_nolog_head1( 1, NULL );
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_dummyhead_1
 * @remark brief: Test kal_adm_alloc_align many times, every time it should merge the padding size with init_mb_head,
    check the padding size can be un-merge back.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_dummyhead_1( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p, *p1;
    int i;
    kal_status r;
    kal_uint32 rsize;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    ap = kal_adm_create( admbuf20K, sizeof( admbuf20K ), NULL, 1 );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    p = kal_adm_alloc_align_with_info( ap, 192/*size*/, 192/*align*/, &rsize );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_align_with_info(ap, 192, 192, &rsize) == NULL" );
        RESET;
    }
    if( rsize < LOG_SIZE(192) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_align_with_info(ap, 192, 192, &rsize) return Non-NULL, but it's really size < 192"
                    );
        RESET;
    }
    if( ((kal_uint32)p) % 192 != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_align_with_info(ap, 192, 192, &rsize)=%p, but not aligned to 192",
                      p );
    }
    kal_adm_free( ap, p );

    for( i = 0; i < 16; i++ )
    {
        p1 = kal_adm_alloc_align_with_info( ap, 192/*size*/, 192/*align*/, &rsize );
        if( p1 == NULL )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_adm_alloc_align_with_info(ap, 192, 192, &rsize) == NULL"
                        );
            RESET;
        }
        if( rsize < LOG_SIZE(192) )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_adm_alloc_align_with_info(ap, 192, 192, &rsize) return Non-NULL, but it's really size < 192"
                        );
            RESET;
        }
        if( p1 != p )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_adm_alloc_align_with_info(ap, 192, 192, &rsize) return difference pointers, get %p, expected %p",
                          p1, p );
        }
        kal_adm_free( ap, p1 );
    }

    r = kal_adm_delete( ap );
    if( r != KAL_SUCCESS )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_delete() == %d, should be %d", r, KAL_SUCCESS );
        RESET;
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "kal_adm_alloc_with_info(ap, 192, &rsize) = %p, real size=%u",
                  p, rsize - LOG_OVERHEAD );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_old_alloc_overhead1
 * @remark brief: adm old implementation require an extra overhead, but this
 *                room should be return back.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_old_alloc_overhead1( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;

#ifndef KAL_WITH_ADM_0
    ktest_report( KTEST_PASS, KTEST_TCID, "no old implementation, by pass" );
#else
    KAL_ADM_ID ap;
    void *p, *p1, *p2;
    int i;
    kal_status r;
    kal_uint32 rsize;

	KTEST_EXPECT_ERR_CODE = 0;

    ap = kal_adm_create_0( admbuf20K, sizeof( admbuf20K ), NULL, 1 );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    p1 = kal_adm_alloc_0( ap, 48 );
    p2 = kal_adm_alloc_0( ap, 4 );
    kal_adm_free_0( ap, p1 );

    p = kal_adm_alloc_align_with_info_0( ap, 4/*size*/, 4/*align*/, &rsize );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 4 &rsize) == NULL" );
        RESET;
    }
    if( rsize < LOG_SIZE(4) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 4, &rsize) return Non-NULL, but it's really size(%d) < 15",
                      rsize );
        RESET;
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "realsize is %d, extra overhead size is %d",
                  rsize - LOG_OVERHEAD, rsize - LOG_OVERHEAD - 4 );
    RESET;
#endif
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_new_alloc_overhead1
 * @remark brief: logging adm new implementation consume no overhead when align=4
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_new_alloc_overhead1( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p, *p1, *p2;
    int i;
    kal_status r;
    kal_uint32 rsize;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    ap = kal_adm_create( admbuf20K, sizeof(admbuf20K), NULL, 1 );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    p1 = kal_adm_alloc( ap, 48 );
    p2 = kal_adm_alloc( ap, 4 );
    kal_adm_free( ap, p1 );

    p = kal_adm_alloc_align_with_info( ap, 4/*size*/, 4/*align*/, &rsize );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 4, &rsize) == NULL" );
        RESET;
    }
    if( rsize < LOG_SIZE(4) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 4, &rsize) return Non-NULL, but it's really size(%d) < 15",
                      rsize );
        RESET;
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "realsize is %d, extra overhead size is %d",
                  rsize - LOG_OVERHEAD, rsize - LOG_OVERHEAD - 4 );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_new_alloc_overhead2
 * @remark brief: no-logging adm new implementation consume no overhead when align=4
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_new_alloc_overhead2( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p, *p1, *p2;
    int i;
    kal_status r;
    kal_uint32 rsize;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    ap = kal_adm_create( admbuf20K, sizeof(admbuf20K), NULL, 0 );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    p1 = kal_adm_alloc( ap, 48 );
    p2 = kal_adm_alloc( ap, 4 );
    kal_adm_free( ap, p1 );

    p = kal_adm_alloc_align_with_info( ap, 4/*size*/, 4/*align*/, &rsize );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 4, &rsize) == NULL" );
        RESET;
    }
    if( rsize < 16 || rsize < NOLOG_SIZE(4) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc_with_info(ap, 4, &rsize) return Non-NULL, but it's really size(%d) < 15",
                      rsize );
        RESET;
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "realsize is %d, extra overhead size is %d",
                  rsize - NOLOG_OVERHEAD, rsize - NOLOG_OVERHEAD - 4 );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_max_alloc1
 * @remark brief: for default setting, adm can allocate a size of kal_adm_get_max_alloc_size()
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_max_alloc1( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p, *p1, *p2;
    int i;
    kal_status r;
    kal_uint32 maxsize, rsize;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    ap = kal_adm_create( admbuf20K, sizeof(admbuf20K), NULL, 1 );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    maxsize = kal_adm_get_max_alloc_size( ap );
    p = kal_adm_alloc_with_info( ap, maxsize, &rsize );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "max_alloc_size()=%u, but failed to malloc from!",
                      maxsize );
        RESET;
    }
    if( rsize < LOG_SIZE(maxsize) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "max_alloc_size()=%u, alloc()=%p, but real size(%d) < req size",
                      maxsize, p, rsize - LOG_OVERHEAD );
        RESET;
    }
    kal_adm_free( ap, p );

    p = kal_adm_alloc_align_with_info( ap, maxsize, 4/*align*/, &rsize );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "max_alloc_size()=%u, but failed to malloc from with align 4!",
                      maxsize );
        RESET;
    }
    if( rsize < LOG_SIZE(maxsize) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "max_alloc_size()=%u, alloc_align4()=%p, but real size(%d) < req size",
                      maxsize, p, rsize - LOG_OVERHEAD );
        RESET;
    }
    kal_adm_free( ap, p );

    ktest_report( KTEST_PASS, KTEST_TCID, "new adm can allocate maximum size" );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_leftsize1
 * @remark brief: for ADM with LOG, rand allocate/free 4 byte memory block.
 *                if not memory available, the left size must be ZERO
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_leftsize1( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p, **ptrs;
    int nptrs, i, j, k, t, v;
    kal_status r;
    kal_uint32 alloc_size, maxsize, rsize;
    kal_uint32 align;
    kal_uint32 acnt = 0, aacnt = 0, nullret = 0, totalsize = 0;

    if( argc == 0 )
    {
	    KTEST_TCID = KTEST_FUNCTION_NAME;
	}
	else
    {
	    KTEST_TCID = "ktest_adm_leftsize2";
	}
	KTEST_EXPECT_ERR_CODE = 0;

    ptrs = kal_sys_mem_alloc( 10000 * sizeof(void *) );
    if( ptrs == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc == NULL" );
        RESET;
    }

    for( i = 0; i < 4; i++ )
    {
        kal_mem_set( ptrs, 0, 10000 * sizeof(void *) );
        nptrs = 0;
        kal_mem_set( admbuf20K, 0, sizeof(admbuf20K) );
        ap = kal_adm_create( admbuf20K, sizeof(admbuf20K), NULL,
                             argc == 0 ? 1 : 0 );
        if( ap == NULL )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
            RESET;
        }

        while( 1 )
        {
            t = rand() % 3; // t=0,1: allocate; t=2: free
            if( t <= 1 )
            {
                // allocate from ADM
                acnt++;
                alloc_size = 4;
                align = 4;
                p = kal_adm_alloc_align_with_info( ap, alloc_size, align,
                                                   &rsize );
                if( p == NULL )
                {
                    nullret++;
                    maxsize = kal_adm_get_max_alloc_size( ap );
                    rsize = kal_adm_get_total_left_size( ap );
                    if( maxsize != 0 || rsize != 0 )
                    {
                        ktest_report( KTEST_FAIL, KTEST_TCID,
                                      "we expect maxsize(%u)==0 && rsize(%u)==0",
                                      maxsize, rsize );
                        RESET;
                    }
                    break;
                }
                else if( (argc == 0 && rsize < LOG_SIZE(alloc_size))
                         || (argc == 1 && rsize < NOLOG_SIZE(alloc_size)) )
                {
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= %p: but real_size=%u",
                                  alloc_size, align, p, rsize );
                    RESET;
                }
                else if( align && ((kal_uint32)p % align != 0) )
                {
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= %p: but NOT ALIGNED!",
                                  alloc_size, align, p );
                    RESET;
                }
                totalsize += alloc_size;
                kal_mem_set( p, 0xEB, alloc_size );
                ptrs[nptrs++] = p;
            }
            else if( nptrs > 0 )
            {
                // free an buffer
                v = rand() % nptrs;
                *(kal_uint32 *) ptrs[v] = 0xFD579BA1;
                kal_adm_free( ap, ptrs[v] );
                nptrs--;
                for( k = v; k < nptrs; k++ )
                {
                    ptrs[k] = ptrs[k + 1];
                }
                ptrs[nptrs] = NULL;
            }
        }

        // free all!
        for( j = nptrs - 1; j >= 0; j-- )
        {
            kal_adm_free( ap, ptrs[j] );
            ptrs[j] = NULL;
        }
        r = kal_adm_delete( ap );
        if( r != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_free() == %d", r );
            RESET;
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "new adm random test for kal_adm_get_total_left_size() pass: total=%u(align=%u, non-align=%u), nullret=%u, totalsize=%u",
                  aacnt + acnt, aacnt, acnt, nullret, totalsize );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_leftsize2
 * @remark brief: for ADM with NO-LOG, rand allocate/free 4 byte memory block.
 *                if not memory available, the left size must be ZERO
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_leftsize2( kal_uint32 argc, void *argv )
{
    return ktest_adm_leftsize1( 1, NULL );
}

static void check_pointers( void **ptrs, int nptrs, int islogging, void *nop )
{
    int i;
    void *p;

    struct PH
    {
        struct PH *prev;
        struct PH *next;
    } *ph, *phprev, *phnext;

 return ;
    for( i = 0; i < nptrs; i++ )
    {
        p = ptrs[i];
        if( p == nop )
            continue;

        ph = (struct PH *) ( (unsigned long) p - (islogging ? 20 : 8) );

        ASSERT( (unsigned long) (ph->prev) & 1 );
        phprev = (struct PH *) ( (unsigned long) (ph->prev) & ~1 );
        ASSERT( (0x0FFFFFFF & ( (unsigned long) (phprev->next) & ~1 ) ) == ( 0x0FFFFFFF & (unsigned long) (ph) ) );
        phnext = (struct PH *) ( (unsigned long) (ph->next) & ~1 );
        ASSERT( (0x0FFFFFFF & ( (unsigned long) (phnext->prev) & ~1 ) ) == ( 0x0FFFFFFF & (unsigned long) (ph) ) );
    }
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_randalloc1
 * @remark brief: for ADM with LOG, random test, verify we can allocate if the
 *                max free size is less than guarantee size.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_randalloc1( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p, *ptrs[100];
    int nptrs, i, j, k, t, v;
    kal_status r;
    kal_uint32 alloc_size, maxsize, rsize;
    kal_uint32 align;
    kal_uint32 acnt = 0, aacnt = 0, nullret = 0, totalsize = 0;

    if( argc == 0 )
    {
	    KTEST_TCID = KTEST_FUNCTION_NAME;
	}
	else
    {
	    KTEST_TCID = "ktest_adm_randalloc2";
	}
	KTEST_EXPECT_ERR_CODE = 0;

    for( i = 0; i < 8; i++ )
    {
        kal_mem_set( ptrs, 0, sizeof(ptrs) );
        nptrs = 0;
        kal_mem_set( admbuf20K, 0, sizeof(admbuf20K) );
        ap = kal_adm_create( admbuf20K, sizeof(admbuf20K), NULL, argc == 0 ? 1 : 0 );
        if( ap == NULL )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
            RESET;
        }

        for( j = 0; j < 3000; j++ )
        {
            t = rand() % 3; // t=0,1: allocate; t=2: free
            if( t <= 1 && nptrs < sizeof(ptrs) / sizeof(ptrs[0]) )
            {
                // allocate from ADM
                const static int somesizes[] = {1, 4, 7, 17, 32, 100, 15, 13, 5,
                                                200};
                const static int somealigns[] = {4, 8, 4, 16, 4, 32, 16, 128};

                t = rand() % ( sizeof(somesizes) / sizeof(somesizes[0]) );
                alloc_size = somesizes[t];

                t = rand() % 50; // t=49: do maximum allocate
                align = somealigns[rand() % ( sizeof(somealigns) / sizeof(somealigns[0]) )];
                if( t == 49 )
                {
                    maxsize = kal_adm_get_max_alloc_size( ap );
                    if( maxsize > align )
                    {
                        alloc_size = maxsize - align;
                    }
                }

                if( align && align != 4 )
                {
                    aacnt++;
                }
                else
                {
                    acnt++;
                }

                p = kal_adm_alloc_align_with_info( ap, alloc_size, align, &rsize );
                if( p == NULL )
                {
                    nullret++;
                    maxsize = kal_adm_get_max_alloc_size( ap );
                    rsize = kal_adm_calc_worst_alloc_size( ap, alloc_size, align );
                    if( rsize > maxsize )
                    {
                        continue;
                    }
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= NULL: but max_size=%u, guarantee_size=%u",
                                  alloc_size, align, maxsize, rsize );
                    RESET;
                }
                if( rsize < 16 )
                {
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= %p: but real_size=%u < 16",
                                  alloc_size, align, p, rsize );
                    RESET;
                }
                else if( ( argc == 0 && rsize < LOG_SIZE(alloc_size) )
                         || ( argc == 1 && rsize < NOLOG_SIZE(alloc_size) ) )
                {
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= %p: but real_size=%u",
                                  alloc_size, align, p, rsize );
                    RESET;
                }
                else if( align && ( (kal_uint32)p % align != 0 ) )
                {
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= %p: but NOT ALIGNED!",
                                  alloc_size, align, p );
                    RESET;
                }
                totalsize += alloc_size;
                kal_mem_set( p, 0xEB, alloc_size );
                ptrs[nptrs++] = p;

                check_pointers( ptrs, nptrs, argc == 0 ? 1 : 0, NULL );
            }
            else if( nptrs > 0 )
            {
                // free an buffer
                v = rand() % nptrs;
                *(kal_uint32 *) ptrs[v] = 0xFD579BA5;
                kal_adm_free( ap, ptrs[v] );

                check_pointers( ptrs, nptrs, argc == 0 ? 1 : 0, ptrs[v] );
                nptrs--;
                for( k = v; k < nptrs; k++ )
                {
                    ptrs[k] = ptrs[k + 1];
                }
                ptrs[nptrs] = NULL;
            }
            if( nptrs == sizeof(ptrs) / sizeof(ptrs[0]) )
            {
                // random free 10 buffers
                for( k = 0; k < 10; k++ )
                {
                    v = rand() % nptrs;
                    *(kal_uint32 *) ptrs[v] = 0xFD579BA3;
                    kal_adm_free( ap, ptrs[v] );

                    check_pointers( ptrs, nptrs, argc == 0 ? 1 : 0, ptrs[v] );
                    nptrs--;
                    for( k = v; k < nptrs; k++ )
                    {
                        ptrs[k] = ptrs[k + 1];
                    }
                    ptrs[nptrs] = NULL;
                }
            }
        }

        // free all!
        for( j = nptrs - 1; j >= 0; j-- )
        {
            kal_adm_free( ap, ptrs[j] );
            ptrs[j] = NULL;
        }
        r = kal_adm_delete( ap );
        if( r != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_free() == %d", r );
            RESET;
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "new adm random test pass: total=%u(align=%u, non-align=%u), nullret=%u, totalsize=%u",
                  aacnt + acnt, aacnt, acnt, nullret, totalsize );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_reallocnull
 * @remark brief: for ADM realloc parameter null pointer,verify we can allocate memory.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_reallocnull( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p, *pa ;
	kal_status r;

    KTEST_EXPECT_ERR_CODE = 0;
    KTEST_TCID = KTEST_FUNCTION_NAME;

    ap = kal_adm_create( admbuf20K, sizeof(admbuf20K), NULL, 0 );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    pa = kal_adm_realloc( ap, NULL, 8 );
    if( pa == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_realloc(ap, NULL,8) == NULL,but the expected should not be NULL" );
        RESET;
    }
	kal_mem_set( pa, 0xEB, 8 );
    kal_adm_free( ap, pa );
    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }
	r = kal_adm_delete( ap );
    if( r != KAL_SUCCESS )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_delete() == %d, should be %d", r, KAL_SUCCESS );
        RESET;
    }
    ktest_report( KTEST_PASS, KTEST_TCID, "kal_adm_realloc(ap,NULL,8) pass" );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_reallocsize0
 * @remark brief: for ADM realloc parameter size 0,verify we can free memory.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_reallocsize0( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p1, *pa,*p;
	kal_status r;

    KTEST_EXPECT_ERR_CODE = 0;
    KTEST_TCID = KTEST_FUNCTION_NAME;

    ap = kal_adm_create( admbuf20K, sizeof(admbuf20K), NULL, 0 );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }
    pa = kal_adm_alloc( ap,8 );
    if( pa == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc(ap,8)== NULL,but the expected should not be NULL" );
        RESET;
    }
	kal_mem_set( pa, 0xEB, 8 );
    p1 = kal_adm_realloc( ap, pa, 0 );
    if( p1 != NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_realloc(ap,pa,0) != NULL, but the expected should be NULL" );
        RESET;
    }
	kal_adm_free( ap, p1 );
    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }
	r = kal_adm_delete( ap );
    if( r != KAL_SUCCESS )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_delete() == %d, should be %d", r, KAL_SUCCESS );
        RESET;
    }
    ktest_report( KTEST_PASS, KTEST_TCID, "kal_adm_realloc(ap,pa,0) pass" );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_realloc_simplecase1
 * @remark brief: Test logging adm allocate/realloc/free: allocate a, b, c, d,
 *                realloc a, b, c,d, free a, b, c, d, each alloc 4 bytes and
 *                then realloc 8 bytes.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_realloc_simplecase1( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p, *pa, *pb, *pc, *pd;
	void *temp;
    kal_status r;
    kal_uint32 rsize;

    kal_uint32 reqsize;
	kal_uint32 reallocsize;
    kal_uint32 logging;

    KTEST_EXPECT_ERR_CODE = 0;
    if( argc == 0 )
    {
    	KTEST_TCID = KTEST_FUNCTION_NAME;
    	reqsize = 4;
		reallocsize = 8;
    	logging = 1;
	}
	else if( argc == 1 )
    {
	    KTEST_TCID = "ktest_adm_realloc_simplecase2";
	    reqsize = 8;
		reallocsize = 4;
	    logging = 1;
	}
	else if( argc == 2 )
    {
	    KTEST_TCID = "ktest_adm_realloc_simplecase3";
	    reqsize = 4;
		reallocsize = 8;
	    logging = 0;
	}
	else if( argc == 3 )
    {
	    KTEST_TCID = "ktest_adm_realloc_simplecase4";
	    reqsize = 8;
		reallocsize = 4;
	    logging = 0;
	}

    ap = kal_adm_create( admbuf20K, sizeof(admbuf20K), NULL, logging );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    pa = kal_adm_alloc( ap, reqsize );
    if( pa == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc(ap,%d) == NULL,but the expected should not be NULL",
                      rsize );
        RESET;
    }
	kal_mem_set( pa, 0xEB, reqsize );
    pb = kal_adm_alloc( ap, reqsize );
    if( pb == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc(ap,%d) == NULL, but the expected should not be NULL",
                      rsize );
        RESET;
    }
	kal_mem_set( pb, 0xEB, reqsize );
    pc = kal_adm_alloc( ap, reqsize );
    if( pc == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc(ap,%d) == NULL, but the expected should not be NULL",
                      rsize );
        RESET;
    }
	kal_mem_set( pc, 0xEB, reqsize );
    pd = kal_adm_alloc( ap, reqsize );
    if( pd == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc(ap,%d) == NULL, but the expected should not be NULL",
                      rsize );
        RESET;
    }
	kal_mem_set( pd, 0xEB, reqsize );
    temp= kal_adm_realloc( ap, pa, reallocsize );
	if( temp == NULL )
    {
		ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_realloc(ap,pa,%d)==NULL, but the expected should not be NULL",
                      reallocsize );
		RESET;
	}
	pa = temp;
	kal_mem_set( pa, 0xEB, reallocsize );
	temp= kal_adm_realloc( ap, pb, reallocsize );
	if( temp == NULL )
    {
		ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_realloc(ap,pb,%d)==NULL, but the expected should not be NULL",
                      reallocsize );
		RESET;
	}
	pb = temp;
	kal_mem_set( pb, 0xEB, reallocsize );

	temp= kal_adm_realloc( ap, pc, reallocsize );
	if( temp == NULL )
    {
		ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_realloc(ap,pc,%d)==NULL, but the expected should not be NULL",
                      reallocsize );
		RESET;
	}
	pc = temp;
	kal_mem_set( pc, 0xEB, reallocsize );

	temp= kal_adm_realloc( ap, pd, reallocsize );
	if( temp == NULL )
    {
		ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_realloc(ap,pd,%d)==NULL, but the expected should not be NULL",
                      reallocsize );
		RESET;
	}
	pd = temp;
	kal_mem_set( pd, 0xEB, reallocsize );

    kal_adm_free( ap, pa );
    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }
    kal_adm_free( ap, pb );
    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }
    kal_adm_free( ap, pc );
    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }
    kal_adm_free( ap, pd );
    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }

    r = kal_adm_delete( ap );
    if( r != KAL_SUCCESS )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_delete() == %d, should be %d", r, KAL_SUCCESS );
        RESET;
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "kal_adm_realloc(ap, pointer, %d) pass", reallocsize );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_realloc_simplecase2
 * @remark brief: Test logging adm allocate/realloc/free: allocate a, b, c, d,
 *                realloc a, b, c,d, free a, b, c, d, each alloc 8 bytes and
 *                then realloc 4 bytes.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_realloc_simplecase2( kal_uint32 argc, void *argv )
{
    return ktest_adm_realloc_simplecase1( 1, NULL );
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_realloc_simplecase3
 * @remark brief: Test no-logging allocate/realloc/free: allocate a, b, c, d,
 *                realloc a, b, c,d, free a, b, c, d, each alloc 4 byte and
 *                then realloc 8 bytes.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_realloc_simplecase3( kal_uint32 argc, void *argv )
{
    return ktest_adm_realloc_simplecase1( 2, NULL );
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_realloc_simplecase4
 * @remark brief: Test no-logging allocate/realloc/free: allocate a, b, c, d,
 *                realloc a, b, c,d, free a, b, c, d, each alloc 8 bytes and
 *                then realloc 4 bytes.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_realloc_simplecase4( kal_uint32 argc, void *argv )
{
    return ktest_adm_realloc_simplecase1( 3, NULL );
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_realloc_mergecase1
 * @remark brief: Test logging adm allocate/realloc/free: allocate a 4bytes,
 *                b 4bytes, c 4bytes, free b,realloc a  16bytes,realloc c 8byets.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_realloc_mergecase1( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p, *pa, *pb, *pc;
	void *temp;
    kal_status r;
    kal_uint32 rsize;
    kal_uint32 reqsize = 4;
    kal_uint32 logging;

    KTEST_EXPECT_ERR_CODE = 0;
    if( argc == 0 )
    {
    	KTEST_TCID = KTEST_FUNCTION_NAME;
    	logging = 1;
	}
	else if( argc == 1 )
    {
	    KTEST_TCID = "ktest_adm_realloc_mergecase2";
	    logging = 0;
	}

    ap = kal_adm_create( admbuf20K, sizeof(admbuf20K), NULL, logging );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    pa = kal_adm_alloc( ap, reqsize );
    if( pa == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc(ap,%d) == NULL,but the expected should not be NULL",
                      rsize );
        RESET;
    }
	kal_mem_set( pa, 0xEB, reqsize );
    pb = kal_adm_alloc( ap, reqsize );
    if( pb == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc(ap,%d) == NULL, but the expected should not be NULL",
                      rsize );
        RESET;
    }
	kal_mem_set( pb, 0xEB, reqsize );

    pc = kal_adm_alloc( ap, reqsize );
    if( pc == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_alloc(ap,%d) == NULL, but the expected should not be NULL",
                      rsize );
        RESET;
    }
	kal_mem_set( pc, 0xEB, reqsize );
    kal_adm_free( ap, pb );
    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }

    temp= kal_adm_realloc( ap, pa, 16 );
	if( temp == NULL )
    {
		ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_realloc(ap,pa,16)==NULL, but the expected should not be NULL" );
		RESET;
	}
	pa = temp;
	kal_mem_set( pa, 0xEB, 16 );

	temp= kal_adm_realloc( ap, pc, 8 );
	if( temp == NULL )
    {
		ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_realloc(ap,pc,8)==NULL, but the expected should not be NULL" );
		RESET;
	}
	pc = temp;
	kal_mem_set( pc, 0xEB, 8 );

    kal_adm_free( ap, pa );
    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }

    kal_adm_free( ap, pc );
    p = kal_adm_check_integrity( ap );
    if( p )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_check_integrity() == %p",
                      p );
        RESET;
    }

    r = kal_adm_delete( ap );
    if( r != KAL_SUCCESS )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_adm_delete() == %d, should be %d", r, KAL_SUCCESS );
        RESET;
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "kal_adm_realloc(ap, pointer,size) pass" );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_realloc_mergecase2
 * @remark brief: Test no_logging adm allocate/realloc/free: allocate a 4bytes,
 *                b 4bytes, c 4bytes, free b,realloc a  16bytes,realloc c 8byets.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_realloc_mergecase2( kal_uint32 argc, void *argv )
{
    return ktest_adm_realloc_mergecase1( 1, NULL );
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_randrealloc1
 * @remark brief: for ADM LOG, random test, verify we can reallocate if the max
 *                free size is less than guarantee size.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_randrealloc1( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p, *ptrs[100];
    int nptrs, i, j, k, t, v,m;
    kal_status r;
    kal_uint32 alloc_size, maxsize, rsize;
    kal_uint32 align;
	kal_uint32 realloc_size;
    kal_uint32 acnt = 0, aacnt = 0, nullret = 0, totalsize = 0;

    if( argc == 0 )
    {
	    KTEST_TCID = KTEST_FUNCTION_NAME;
	}
	else
    {
	    KTEST_TCID = "ktest_adm_randrealloc2";
	}
	KTEST_EXPECT_ERR_CODE = 0;

    for( i = 0; i < 8; i++ )
    {
        kal_mem_set( ptrs, 0, sizeof(ptrs) );
        nptrs = 0;
        kal_mem_set( admbuf20K, 0, sizeof(admbuf20K) );
        ap = kal_adm_create( admbuf20K, sizeof(admbuf20K), NULL,
                             argc == 0 ? 1 : 0 );
        if( ap == NULL )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
            RESET;
        }

        for( j = 0; j < 3000; j++ )
        {
            t = rand() % 4; // t=0,1: reallocate; t=2:alloc;t=3,free
            if( t <= 2 && nptrs < sizeof(ptrs) / sizeof(ptrs[0]) )
            {
                // allocate from ADM
                const static int somesizes[] = { 1, 4, 7, 17, 32, 100, 15, 13,
                                                 5, 200};
				const static int someresizes[]={ 200, 100, 1, 4, 32, 15, 13, 5,
                                                 17, 7, 500, 64 };
				const static int somealigns[] = { 4, 8, 4, 16, 4, 32, 16, 128 };

				align = somealigns[rand() % ( sizeof(somealigns) / sizeof(somealigns[0]) )];

                if( align && align != 4 )
                {
                    aacnt++;
                }
                else
                {
                    acnt++;
                }

                if( t <= 1 )
                {
					m = rand() % ( sizeof(someresizes) / sizeof(someresizes[0]) );
					realloc_size = someresizes[m];
					if( nptrs == 0 )
                    {
						p = kal_adm_realloc( ap, NULL, realloc_size );
						if( p != NULL )
                        {
							ptrs[nptrs++] = p;
						}
					}
					else
                    {
						v = rand() % nptrs;
						p = kal_adm_realloc( ap, ptrs[v], realloc_size );
						if( p != NULL )
                        {
							ptrs[v] = p;
						}
		            }
					if( p == NULL )
                    {
		                nullret++;
		                maxsize = kal_adm_get_max_alloc_size( ap );
		                rsize = kal_adm_calc_worst_alloc_size( ap, realloc_size, 4 );
		                if( rsize > maxsize )
                        {
		                    continue;
		                }
		                ktest_report( KTEST_FAIL, KTEST_TCID,
                                      "kal_adm_realloc(req_size=%u)= NULL: but max_size=%u, guarantee_size=%u",
		                              realloc_size, maxsize, rsize );
		                RESET;
		            }
	                totalsize += realloc_size;
	                kal_mem_set( p, 0xEB, realloc_size );
				    *(kal_uint32 *) p = realloc_size + 0xff000000;
				    if( realloc_size == 0x0f )
				    {
					    int ljy;
					    ljy = 0;
					    ljy++;
				    }
	                check_pointers( ptrs, nptrs, argc == 0 ? 1 : 0, NULL );
				}
				else
                {
					m = rand() % ( sizeof(somesizes) / sizeof(somesizes[0]) );
					alloc_size = somesizes[m];
					m = rand() % 50; // t=49: do maximum allocate

		            if( m == 49 )
                    {
		                maxsize = kal_adm_get_max_alloc_size( ap );
		                if( maxsize > align )
                        {
		                    alloc_size = maxsize - align;
		                }
                	}
					p = kal_adm_alloc_align_with_info( ap, alloc_size, align, &rsize );
	                if( p == NULL )
                    {
	                    maxsize = kal_adm_get_max_alloc_size( ap );
	                    rsize = kal_adm_calc_worst_alloc_size( ap, alloc_size, align );
	                    if( rsize > maxsize )
                        {
	                        continue;
	                    }
	                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                      "kal_adm_alloc(req_size=%u, align=%u)= NULL: but max_size=%u, guarantee_size=%u",
	                                  alloc_size, align, maxsize, rsize );
	                    RESET;
	                }
	                if( rsize < 16 )
                    {
	                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                      "kal_adm_alloc(req_size=%u, align=%u)= %p: but real_size=%u < 16",
	                                  alloc_size, align, p, rsize );
	                    RESET;
	                }
	                else if( ( argc == 0 && rsize < LOG_SIZE(alloc_size) )
                             || ( argc == 1 && rsize < NOLOG_SIZE(alloc_size) ) )
                    {
	                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                      "kal_adm_alloc(req_size=%u, align=%u)= %p: but real_size=%u",
	                                  alloc_size, align, p, rsize );
	                    RESET;
	                }
	                else if( align && ( (kal_uint32)p % align != 0 ) )
                    {
	                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                      "kal_adm_alloc(req_size=%u, align=%u)= %p: but NOT ALIGNED!",
	                                  alloc_size, align, p );
	                    RESET;
	                }
					kal_mem_set( p, 0xEB, alloc_size );
					*(kal_uint32 *) p = alloc_size;
	                ptrs[nptrs++] = p;
					if( alloc_size == 0x0f )
					{
						int ljy;
						ljy = 0;
						ljy++;
					}

	                check_pointers( ptrs, nptrs, argc == 0 ? 1 : 0, NULL );
				}
            }
            else if( nptrs > 0)
            {
                // free an buffer
                v = rand() % nptrs;
                *(kal_uint32 *) ptrs[v] = 0xFD579BA5;
                kal_adm_free( ap, ptrs[v] );
                check_pointers( ptrs, nptrs, argc == 0 ? 1 : 0, ptrs[v] );
                nptrs--;
                for( k = v; k < nptrs; k++ )
                {
                    ptrs[k] = ptrs[k + 1];
                }
                ptrs[nptrs] = NULL;
            }
            if( nptrs == sizeof(ptrs) / sizeof(ptrs[0]) )
            {
                // random free 10 buffers
                for( k = 0; k < 10; k++ )
                {
                    v = rand() % nptrs;
                    *(kal_uint32 *) ptrs[v] = 0xFD579BA3;
                    kal_adm_free( ap, ptrs[v] );
                    check_pointers( ptrs, nptrs, argc == 0 ? 1 : 0, ptrs[v] );
                    nptrs--;
                    for( k = v; k < nptrs; k++ )
                    {
                        ptrs[k] = ptrs[k + 1];
                    }
                    ptrs[nptrs] = NULL;
                }
            }
        }

        // free all!
        for( j = nptrs - 1; j >= 0; j-- )
        {
            kal_adm_free( ap, ptrs[j] );
            ptrs[j] = NULL;
        }
        r = kal_adm_delete( ap );
        if( r != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_free() == %d", r );
            RESET;
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "adm random realloc test pass: total=%u(align=%u, non-align=%u), nullret=%u, totalsize=%u",
                  aacnt + acnt, aacnt, acnt, nullret, totalsize );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_randrealloc2
 * @remark brief: for ADM with NO-LOG, random test, verify we can realloc if
 *                the max free size is less than guarantee size.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_randrealloc2( kal_uint32 argc, void *argv )
{
    return ktest_adm_randrealloc1( 1, NULL );
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_randalloc2
 * @remark brief: for ADM with NO-LOG, random test, verify we can allocate
 *                if the max free size is less than guarantee size.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_randalloc2( kal_uint32 argc, void *argv )
{
    return ktest_adm_randalloc1( 1, NULL );
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_topmost_leftsize1
 * @remark brief: for ADM with LOG, rand allocate/free 4 byte memory block from
 *                topmost. if not memory available, the left size must be 0.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_topmost_leftsize1( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p;
    static void *ptrs[50 * 1000];
    int nptrs, i, j, k, t, v;
    kal_status r;
    kal_uint32 alloc_size, maxsize, rsize;
    kal_uint32 align;
    kal_uint32 acnt = 0, aacnt = 0, nullret = 0, totalsize = 0;

    if( argc == 0 )
    {
	    KTEST_TCID = KTEST_FUNCTION_NAME;
	}
	else
    {
	    KTEST_TCID = "ktest_adm_topmost_leftsize2";
	}
	KTEST_EXPECT_ERR_CODE = 0;

    for( i = 0; i < 4; i++ )
    {
        kal_mem_set( ptrs, 0, sizeof(ptrs) );
        nptrs = 0;
        kal_mem_set( admbuf200K, 0, sizeof(admbuf200K) );
        ap = kal_adm_create( admbuf200K, sizeof(admbuf200K), NULL,
                             argc == 0 ? 1 : 0 );
        if( ap == NULL )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
            RESET;
        }

        while( 1 )
        {
            t = rand() % 3; // t=0,1: allocate; t=2: free
            if( t <= 1 )
            {
                // allocate from ADM
                acnt++;
                alloc_size = 4;
                align = 4;
                p = kal_adm_alloc_align_topmost_with_info( ap, alloc_size, align, &rsize );
                if( p == NULL )
                {
                    nullret++;
                    maxsize = kal_adm_get_max_alloc_size( ap );
                    rsize = kal_adm_get_total_left_size( ap );

                    if( maxsize != 0 || rsize != 0 )
                    {
                        ktest_report( KTEST_FAIL, KTEST_TCID,
                                      "we expect maxsize(%u)==0 && rsize(%u)==0",
                                      maxsize, rsize );
                        RESET;
                    }
                    break;
                }
                else if( ( argc == 0 && rsize < LOG_SIZE(alloc_size) )
                         || ( argc == 1 && rsize < NOLOG_SIZE(alloc_size) ) )
                {
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= %p: but real_size=%u",
                                  alloc_size, align, p, rsize );
                    RESET;
                }
                else if( align && ( (kal_uint32)p % align != 0 ) )
                {
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= %p: but NOT ALIGNED!",
                                  alloc_size, align, p );
                    RESET;
                }
                totalsize += alloc_size;
                kal_mem_set( p, 0xEB, alloc_size );
                ptrs[nptrs++] = p;
            }
            else if( nptrs > 0 )
            {
                // free an buffer
                v = rand() % nptrs;
                *(kal_uint32 *) ptrs[v] = 0xFD579BA7;
                kal_adm_free( ap, ptrs[v] );
                nptrs--;
                for( k = v; k < nptrs; k++ )
                {
                    ptrs[k] = ptrs[k + 1];
                }
                ptrs[nptrs] = NULL;
            }
        }

        // free all!
        for( j = nptrs - 1; j >= 0; j-- )
        {
            kal_adm_free( ap, ptrs[j] );
            ptrs[j] = NULL;
        }
        r = kal_adm_delete( ap );
        if( r != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_free() == %d", r );
            RESET;
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "new adm random test for kal_adm_get_total_left_size() pass: total=%u(align=%u, non-align=%u), nullret=%u, totalsize=%u",
                  aacnt + acnt, aacnt, acnt, nullret, totalsize );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_topmost_leftsize2
 * @remark brief: for ADM with NO-LOG, rand allocate/free 4 byte memory block
 *                from topmost. if not memory available, the left size must be 0.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_topmost_leftsize2( kal_uint32 argc, void *argv )
{
    return ktest_adm_topmost_leftsize1( 1, NULL );
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_topmost_randalloc1
 * @remark brief: for ADM with LOG, random test topmost allocate, verify we can
 *                allocate if the max free size is less than guarantee size.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_topmost_randalloc1( kal_uint32 argc, void *argv )
{
    KAL_ADM_ID ap;
    void *p, *ptrs[200];
    int nptrs, i, j, k, t, v;
    kal_status r;
    kal_uint32 alloc_size, maxsize, rsize;
    kal_uint32 align;
    kal_uint32 acnt = 0, aacnt = 0, nullret = 0, totalsize = 0;

    if( argc == 0 )
    {
	    KTEST_TCID = KTEST_FUNCTION_NAME;
	}
	else
    {
	    KTEST_TCID = "ktest_adm_topmost_randalloc2";
	}
	KTEST_EXPECT_ERR_CODE = 0;

    for( i = 0; i < 8; i++ )
    {
        kal_mem_set( ptrs, 0, sizeof(ptrs) );
        nptrs = 0;
        kal_mem_set( admbuf200K, 0, sizeof(admbuf200K) );
        ap = kal_adm_create( admbuf200K, sizeof(admbuf200K), NULL,
                             argc == 0 ? 1 : 0 );
        if( ap == NULL )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
            RESET;
        }

        for( j = 0; j < 3000; j++ )
        {
            t = rand() % 3; // t=0,1: allocate; t=2: free
            if( t <= 1 && nptrs < sizeof(ptrs) / sizeof(ptrs[0]) )
            {
                // allocate from ADM
                const static int somesizes[] = {1, 4, 7, 17, 32, 100, 15, 13, 5,
                                                200};
                const static int somealigns[] = {4, 8, 4, 16, 4, 32, 16, 128};

                t = rand() % ( sizeof(somesizes) / sizeof(somesizes[0]) );
                alloc_size = somesizes[t];

                t = rand() % 50; // t=49: do maximum allocate
                align = somealigns[rand() % ( sizeof(somealigns) / sizeof(somealigns[0]) )];
                if( t == 49 )
                {
                    maxsize = kal_adm_get_max_alloc_size( ap );
                    if( maxsize > align )
                    {
                        alloc_size = maxsize - align;
                    }
                }

                if( align && align != 4 )
                {
                    aacnt++;
                }
                else
                {
                    acnt++;
                }

                p = kal_adm_alloc_align_topmost_with_info( ap, alloc_size, align, &rsize );
                if( p == NULL )
                {
                    nullret++;
                    maxsize = kal_adm_get_max_alloc_size( ap );
                    rsize = kal_adm_calc_worst_alloc_size( ap, alloc_size, align );
                    if( rsize > maxsize )
                    {
                        continue;
                    }
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= NULL: but max_size=%u, guarantee_size=%u",
                                  alloc_size, align, maxsize, rsize );
                    RESET;
                }
                else if( ( argc == 0 && rsize < LOG_SIZE(alloc_size) )
                         || ( argc == 1 && rsize < NOLOG_SIZE(alloc_size) ) )
                {
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= %p: but real_size=%u",
                                  alloc_size, align, p, rsize );
                    RESET;
                }
                else if( align && ( (kal_uint32) p % align != 0 ) )
                {
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= %p: but NOT ALIGNED!",
                                  alloc_size, align, p );
                    RESET;
                }
                totalsize += alloc_size;
                kal_mem_set( p, 0xEB, alloc_size );
                ptrs[nptrs++] = p;
            }
            else if( nptrs > 0 )
            {
                // free an buffer
                v = rand() % nptrs;
                *(kal_uint32 *) ptrs[v] = 0xFD579B71;
                kal_adm_free( ap, ptrs[v] );
                nptrs--;
                for( k = v; k < nptrs; k++ )
                {
                    ptrs[k] = ptrs[k + 1];
                }
                ptrs[nptrs] = NULL;
            }
            if( nptrs == sizeof(ptrs) / sizeof(ptrs[0]) )
            {
                // random free 10 buffers
                for( k = 0; k < 10; k++ )
                {
                    v = rand() % nptrs;
                    *(kal_uint32 *) ptrs[v] = 0xFD579B73;
                    kal_adm_free( ap, ptrs[v] );
                    nptrs--;
                    for( k = v; k < nptrs; k++ )
                    {
                        ptrs[k] = ptrs[k + 1];
                    }
                    ptrs[nptrs] = NULL;
                }
            }
        }

        // free all!
        for( j = nptrs - 1; j >= 0; j-- )
        {
            kal_adm_free( ap, ptrs[j] );
            ptrs[j] = NULL;
        }
        r = kal_adm_delete( ap );
        if( r != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_free() == %d", r );
            RESET;
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "new adm random test for topmost pass: total=%u(align=%u, non-align=%u), nullret=%u, totalsize=%u",
                  aacnt + acnt, aacnt, acnt, nullret, totalsize );
    RESET;
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_topmost_randalloc2
 * @remark brief: for ADM with NO-LOG, random test topmost allocate, verify we
 *                can allocate if the max free size is less than guarantee size.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_topmost_randalloc2( kal_uint32 argc, void *argv )
{
    return ktest_adm_topmost_randalloc1( 1, NULL );
}

#if defined( __MTK_TARGET__ ) \
    && ( defined( __ARM9_MMU__ ) || defined( __ARM11_MMU__ ) )

#include "mmu.h"
#include "cache_sw.h"

#pragma arm section rwdata = "DYNAMICCACHEABLERW_NC", zidata = "DYNAMICCACHEABLEZI_NC"
KTEST_ALIGN char admbuf200K_nc[200 * 1024];
#pragma arm section rwdata, zidata
#pragma arm section rwdata = "DYNAMICCACHEABLERW_C", zidata = "DYNAMICCACHEABLEZI_C"
KTEST_ALIGN char admbuf200K_c[200 * 1024];
#pragma arm section rwdata, zidata

#endif /* __MTK_TARGET__ && ( __ARM9_MMU__ || __ARM11_MMU__ ) */

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_dyncache_randalloc1
 * @remark brief: for ADM with LOG, random test cache allocate & dynamic switch
 *                cacheability function.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_dyncache_randalloc1( kal_uint32 argc, void *argv )
{
#if defined( __MTK_TARGET__ ) && defined( __ARM9_MMU__ )
    KAL_ADM_ID ap;
    void *p, *ptrs[100];
    int nptrs, i, j, k, t, v;
    kal_status r;
    kal_uint32 alloc_size, maxsize, rsize;
    kal_uint32 align;
    kal_uint32 acnt = 0, aacnt = 0, nullret = 0, totalsize = 0;

    if( argc == 0 )
    {
	    KTEST_TCID = KTEST_FUNCTION_NAME;
	}
	else if( argc == 1 )
    {
	    KTEST_TCID = "ktest_adm_dyncache_randalloc2";
	}
	else if( argc == 2 )
    {
	    KTEST_TCID = "ktest_adm_dyncache_randalloc3";
	}
	else if( argc == 3 )
    {
	    KTEST_TCID = "ktest_adm_dyncache_randalloc4";
	}
	KTEST_EXPECT_ERR_CODE = 0;

    for( i = 0; i < 8; i++ )
    {
        kal_mem_set( ptrs, 0, sizeof(ptrs) );
        nptrs = 0;
        kal_mem_set( admbuf200K_nc, 0, sizeof(admbuf200K_nc) );
        if( argc == 0 )
        {
            ap = kal_adm_create( admbuf200K_nc, sizeof(admbuf200K_nc), NULL, 1 );
        }
        else if( argc == 1 )
        {
            ap = kal_adm_create( admbuf200K_nc, sizeof(admbuf200K_nc), NULL, 0 );
        }
        else if( argc == 2 )
        {
            ap = kal_adm_create( admbuf200K_c, sizeof(admbuf200K_c), NULL, 1 );
        }
        else if( argc == 3 )
        {
            ap = kal_adm_create( admbuf200K_c, sizeof(admbuf200K_c), NULL, 0 );
        }

        if( ap == NULL )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
            RESET;
        }

        for( j = 0; j < 3000; j++ )
        {
            t = rand() % 3; // t=0,1: allocate; t=2: free
            if( t <= 1 && nptrs < sizeof(ptrs) / sizeof(ptrs[0]) )
            {
                // allocate from ADM
                const static int somesizes[] = {1,17, 32, 100, 15, 13, 5,
                                                200, 32, 64, 32, 64, 96, 128};
                const static int somealigns[] = {32, 64, 32, 32, 64, 128,};

                t = rand() % ( sizeof(somesizes) / sizeof(somesizes[0]) );
                alloc_size = somesizes[t];

                t = rand() % 50; // t=49: do maximum allocate
                align = somealigns[rand() % ( sizeof(somealigns) / sizeof(somealigns[0]) )];
                if( t == 49 )
                {
                    maxsize = kal_adm_get_max_alloc_size( ap );
                    if( maxsize > align )
                    {
                        alloc_size = maxsize - align;
                    }
                }

                if( align && align != 4 )
                {
                    aacnt++;
                }
                else
                {
                    acnt++;
                }

                align = 32; /* ARM9 cacheable alloc only support 32-byte alignment */
                if( argc == 0 || argc == 1 )
                {
                    p = kal_adm_alloc_cacheable_with_info( ap, alloc_size, align, &rsize );
                }
                else if( argc == 2 || argc == 3 )
                {
                    p = kal_adm_alloc_noncacheable_with_info( ap, alloc_size, align, &rsize );
                }
                alloc_size = ( (alloc_size) + align - 1 ) / align * align;

                if( p == NULL )
                {
                    nullret++;
                    maxsize = kal_adm_get_max_alloc_size( ap );
                    rsize = kal_adm_calc_worst_alloc_size( ap, alloc_size, align );
                    if( rsize > maxsize )
                    {
                        continue;
                    }
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= NULL: but max_size=%u, guarantee_size=%u",
                                  alloc_size, align, maxsize, rsize );
                    RESET;
                }
                if( rsize < 16 )
                {
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= %p: but real_size=%u < 16",
                                  alloc_size, align, p, rsize );
                    RESET;
                }
                else if( ( argc == 0 && rsize < LOG_SIZE(alloc_size) )
                         || ( argc == 1 && rsize < NOLOG_SIZE(alloc_size) ) )
                {
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= %p: but real_size=%u",
                                  alloc_size, align, p, rsize );
                    RESET;
                }
                else if( align && ( (kal_uint32) p % align != 0 ) )
                {
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= %p: but NOT ALIGNED!",
                                  alloc_size, align, p );
                    RESET;
                }

                if( argc == 0 || argc == 1 )
                {
                    dynamic_switch_cacheable_region( &p, alloc_size, PAGE_CACHEABLE );
                    if( rand() % 2 == 0 )
                    {
                        dynamic_switch_cacheable_region( &p, alloc_size, PAGE_NO_CACHE );
                    }
                }
                else if( argc == 2 || argc == 3 )
                {
                    dynamic_switch_cacheable_region( &p, alloc_size, PAGE_NO_CACHE );
                    if( rand() % 2 == 0 )
                    {
                        dynamic_switch_cacheable_region( &p, alloc_size, PAGE_CACHEABLE );
                    }
                }

                totalsize += alloc_size;
                kal_mem_set( p, 0xEB, alloc_size );
                ptrs[nptrs++] = p;

                check_pointers( ptrs, nptrs, argc == 0 ? 1 : 0, NULL );
            }
            else if( nptrs > 0 )
            {
                // free an buffer
                v = rand() % nptrs;
                *(kal_uint32 *) ptrs[v] = 0xFD579BA5;
                kal_adm_free( ap, ptrs[v] );
                check_pointers( ptrs, nptrs, argc == 0 ? 1 : 0, ptrs[v] );
                nptrs--;
                for( k = v; k < nptrs; k++ )
                {
                    ptrs[k] = ptrs[k + 1];
                }
                ptrs[nptrs] = NULL;
            }
            if( nptrs == sizeof(ptrs) / sizeof(ptrs[0]) )
            {
                // random free 10 buffers
                for( k = 0; k < 10; k++ )
                {
                    v = rand() % nptrs;
                    *(kal_uint32 *) ptrs[v] = 0xFD579BA3;
                    kal_adm_free( ap, ptrs[v] );
                    check_pointers( ptrs, nptrs, argc == 0 ? 1 : 0, ptrs[v] );
                    nptrs--;
                    for( k = v; k < nptrs; k++ )
                    {
                        ptrs[k] = ptrs[k + 1];
                    }
                    ptrs[nptrs] = NULL;
                }
            }
        }

        // free all!
        for( j = nptrs - 1; j >= 0; j-- )
        {
            kal_adm_free( ap, ptrs[j] );
            ptrs[j] = NULL;
        }
        r = kal_adm_delete( ap );
        if( r != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_free() == %d", r );
            RESET;
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "new adm random test pass: total=%u(align=%u, non-align=%u), nullret=%u, totalsize=%u",
                  aacnt + acnt, aacnt, acnt, nullret, totalsize );
    RESET;
#else   /*__ARM9_MMU__*/
    ktest_report( KTEST_PASS, KTEST_FUNCTION_NAME, "__ARM9_MMU__ not supported" );
#endif
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_dyncache_randalloc2
 * @remark brief: for ADM with NO-LOG, random test cache allocate & dynamic
 *                switch cacheability function.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_dyncache_randalloc2( kal_uint32 argc, void *argv )
{
#if defined( __MTK_TARGET__ ) && defined( __ARM9_MMU__ )
    return ktest_adm_dyncache_randalloc1( 1, NULL );
#else
    KTEST_TCID = KTEST_FUNCTION_NAME;
    ktest_report( KTEST_PASS, KTEST_TCID, "__ARM9_MMU__ not supported" );
#endif
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_dyncache_randalloc3
 * @remark brief: for ADM with LOG, random test noncache allocate & dynamic
 *                switch cacheability function.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_dyncache_randalloc3( kal_uint32 argc, void *argv )
{
#if defined( __MTK_TARGET__ ) && defined( __ARM9_MMU__ )
    return ktest_adm_dyncache_randalloc1( 2, NULL );
#else
    KTEST_TCID = KTEST_FUNCTION_NAME;
    ktest_report( KTEST_PASS, KTEST_TCID, "__ARM9_MMU__ not supported" );
#endif
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_dyncache_randalloc4
 * @remark brief: for ADM with NO-LOG, random test noncache allocate & dynamic
 *                switch cacheability function.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_dyncache_randalloc4( kal_uint32 argc, void *argv )
{
#if defined( __MTK_TARGET__ ) && defined( __ARM9_MMU__ )
    return ktest_adm_dyncache_randalloc1( 3, NULL );
#else
    KTEST_TCID = KTEST_FUNCTION_NAME;
    ktest_report( KTEST_PASS, KTEST_TCID, "__ARM9_MMU__ not supported" );
#endif
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_dyncache_randrealloc1
 * @remark brief: for ADM with LOG, random test cache reallocate & dynamic
 *                switch cacheability function.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_dyncache_randrealloc1( kal_uint32 argc, void *argv )
{
#if defined( __MTK_TARGET__ ) && defined( __DYNAMIC_SWITCH_CACHEABILITY__ )
    KAL_ADM_ID ap;
    void *p, *ptrs[100];
    int nptrs, i, j, k, t, v,m;
    kal_status r;
    kal_uint32 alloc_size, maxsize, rsize, realloc_size;
    kal_uint32 align=32;
    kal_uint32 acnt = 0, aacnt = 0, nullret = 0, totalsize = 0;

    if( argc == 0 )
    {
	    KTEST_TCID = KTEST_FUNCTION_NAME;
	}
	else if( argc == 1 )
    {
	    KTEST_TCID = "ktest_adm_dyncache_randrealloc2";
	}
	else if( argc == 2 )
    {
	    KTEST_TCID = "ktest_adm_dyncache_randrealloc3";
	}
	else if( argc == 3 )
    {
	    KTEST_TCID = "ktest_adm_dyncache_randrealloc4";
	}
	KTEST_EXPECT_ERR_CODE = 0;

    for( i = 0; i < 8; i++ )
    {
        kal_mem_set( ptrs, 0, sizeof(ptrs) );
        nptrs = 0;
        kal_mem_set( admbuf200K_nc, 0, sizeof(admbuf200K_nc) );
        if( argc == 0 )
        {
            ap = kal_adm_create( admbuf200K_nc, sizeof(admbuf200K_nc), NULL, 1 );
        }
        else if( argc == 1 )
        {
            ap = kal_adm_create( admbuf200K_nc, sizeof(admbuf200K_nc), NULL, 0 );
        }
        else if( argc == 2 )
        {
            ap = kal_adm_create( admbuf200K_c, sizeof(admbuf200K_c), NULL, 1 );
        }
        else if( argc == 3 )
        {
            ap = kal_adm_create( admbuf200K_c, sizeof(admbuf200K_c), NULL, 0 );
        }

        if( ap == NULL )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
            RESET;
        }

        for( j = 0; j < 3000; j++ )
        {
            t = rand() % 4; // t=0,1: reallocate; t=2 allocate,t=3: free
            if( t <= 2 && nptrs < sizeof(ptrs) / sizeof(ptrs[0]) )
            {
                // allocate from ADM
                const static int somesizes[] = {1,17, 32, 100, 15, 13, 5,
                                                200, 32, 64, 32, 64, 96, 128};
				const static int someresizes[]={32,100,19,50,180,1,32,64,200,17,
					                             96,124,50,7};

                if( t <= 1 )
                {
					m = rand() % ( sizeof(someresizes) / sizeof(someresizes[0]) );
					realloc_size = someresizes[m];
					realloc_size = ( (realloc_size) + align - 1 ) / align * align;
					if( nptrs == 0 )
                    {
						if( argc == 0 || argc == 1 )
                        {
                    		p = kal_adm_realloc_cacheable( ap, NULL, realloc_size );
                 		}
                		else if( argc == 2 || argc == 3 )
                        {
                    		p = kal_adm_realloc_noncacheable( ap, NULL, realloc_size );
                		}
						if( p != NULL )
                        {
						        if( argc == 0 || argc == 1 )
                                {
		                			dynamic_switch_cacheable_region( &p, realloc_size, PAGE_CACHEABLE );
		                			if( rand() % 2 == 0 )
                                    {
		                    			dynamic_switch_cacheable_region( &p, realloc_size, PAGE_NO_CACHE );
		                    		}
		                		}
		                		else if( argc == 2 || argc == 3 )
                                {
		                			dynamic_switch_cacheable_region( &p, realloc_size, PAGE_NO_CACHE );
		                			if( rand() % 2 == 0 )
                                    {
		                    			dynamic_switch_cacheable_region( &p, realloc_size, PAGE_CACHEABLE );
		                			}
				        		}
							ptrs[nptrs++] = p;
						}
					}
					else
                    {
						v = rand() % nptrs;
						if( argc == 0 || argc == 1 )
                        {
                    		p = kal_adm_realloc_cacheable( ap, ptrs[v], realloc_size );
                 		}
                		else if( argc == 2 || argc == 3 )
                        {
                    		p = kal_adm_realloc_noncacheable( ap, ptrs[v], realloc_size );
                		}
						if( p != NULL )
                        {
							if( argc == 0 || argc == 1 )
                            {
	                			dynamic_switch_cacheable_region( &p, realloc_size, PAGE_CACHEABLE );
	                			if( rand() % 2 == 0 )
                                {
	                    			dynamic_switch_cacheable_region( &p, realloc_size, PAGE_NO_CACHE );
	                    		}
	                		}
	                		else if( argc == 2 || argc == 3 )
                            {
	                			dynamic_switch_cacheable_region( &p, realloc_size, PAGE_NO_CACHE );
	                			if( rand() % 2 == 0 )
                                {
	                    			dynamic_switch_cacheable_region( &p, realloc_size, PAGE_CACHEABLE );
	                			}
			        		}
							ptrs[v] = p;
						}
		            }

					if( p == NULL )
                    {
	                	nullret++;
	                	maxsize = kal_adm_get_max_alloc_size( ap );
	                	rsize = kal_adm_calc_worst_alloc_size( ap, realloc_size, align );
	                	if( rsize > maxsize )
                        {
	                    	continue;
	                	}
	                	ktest_report( KTEST_FAIL, KTEST_TCID,
                                      "kal_adm_realloc(req_size=%u)= NULL: but max_size=%u, guarantee_size=%u",
	                    	          realloc_size, maxsize, rsize );
	                	RESET;
			       }

		           totalsize += realloc_size;
		           kal_mem_set( p, 0xEB, realloc_size );
		           check_pointers( ptrs, nptrs, argc == 0 ? 1 : 0, NULL );
				}
				else
                {
                	m = rand() % ( sizeof(somesizes) / sizeof(somesizes[0]) );
                	alloc_size = somesizes[m];
					alloc_size = ( (alloc_size) + align - 1 ) / align * align;
					m = rand() % 50; // t=49: do maximum allocate
                	if( m == 49 )
                    {
                    	maxsize = kal_adm_get_max_alloc_size( ap );
                    	if( maxsize > align )
                        {
                        	alloc_size = maxsize - align;
                    	}
                	}

	                if( argc == 0 || argc == 1 )
                    {
	                    p = kal_adm_alloc_cacheable_with_info( ap, alloc_size, align, &rsize );
	                }
	                else if( argc == 2 || argc == 3 )
                    {
	                    p = kal_adm_alloc_noncacheable_with_info( ap, alloc_size, align, &rsize );
	                }
	                alloc_size = ( (alloc_size) + align - 1 ) / align * align;

	                if( p == NULL )
                    {
	                    maxsize = kal_adm_get_max_alloc_size( ap );
	                    rsize = kal_adm_calc_worst_alloc_size( ap, alloc_size, align );
	                    if( rsize > maxsize )
                        {
	                        continue;
	                    }
	                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                      "kal_adm_alloc(req_size=%u, align=%u)= NULL: but max_size=%u, guarantee_size=%u",
	                                  alloc_size, align, maxsize, rsize );
	                    RESET;
	                }
	                if( rsize < 16 )
                    {
	                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                      "kal_adm_alloc(req_size=%u, align=%u)= %p: but real_size=%u < 16",
	                                  alloc_size, align, p, rsize );
	                    RESET;
	                }
	                else if( ( argc == 0 && rsize < LOG_SIZE(alloc_size) )
                             || ( argc == 1 && rsize < NOLOG_SIZE(alloc_size) ) )
                    {
	                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                      "kal_adm_alloc(req_size=%u, align=%u)= %p: but real_size=%u",
	                                  alloc_size, align, p, rsize );
	                    RESET;
	                }
	                else if( align && ( (kal_uint32)p % align != 0 ) )
                    {
	                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                      "kal_adm_alloc(req_size=%u, align=%u)= %p: but NOT ALIGNED!",
	                                  alloc_size, align, p );
	                    RESET;
	                }
				    if( argc == 0 || argc == 1 )
                    {
	                	dynamic_switch_cacheable_region( &p, alloc_size, PAGE_CACHEABLE );
	                	if( rand() % 2 == 0 )
                        {
	                    	dynamic_switch_cacheable_region( &p, alloc_size, PAGE_NO_CACHE );
	                    }
	                }
	                else if( argc == 2 || argc == 3 )
                    {
	                	dynamic_switch_cacheable_region( &p, alloc_size, PAGE_NO_CACHE );
	                	if( rand() % 2 == 0 )
                        {
	                    	dynamic_switch_cacheable_region( &p, alloc_size, PAGE_CACHEABLE );
	                	}
			        }
					kal_mem_set( p, 0xEB, alloc_size );
	                ptrs[nptrs++] = p;

	                check_pointers( ptrs, nptrs, argc == 0 ? 1 : 0, NULL );
	            }
            }
            else if( nptrs > 0 )
            {
                // free an buffer
                v = rand() % nptrs;
                *(kal_uint32 *) ptrs[v] = 0xFD579BA5;
                kal_adm_free( ap, ptrs[v] );
                check_pointers( ptrs, nptrs, argc == 0 ? 1 : 0, ptrs[v] );
                nptrs--;
                for( k = v; k < nptrs; k++ )
                {
                    ptrs[k] = ptrs[k + 1];
                }
                ptrs[nptrs] = NULL;
            }
            if( nptrs == sizeof(ptrs) / sizeof(ptrs[0]) )
            {
                // random free 10 buffers
                for( k = 0; k < 10; k++ )
                {
                    v = rand() % nptrs;
                    *(kal_uint32 *) ptrs[v] = 0xFD579BA3;
                    kal_adm_free( ap, ptrs[v] );
                    check_pointers( ptrs, nptrs, argc == 0 ? 1 : 0, ptrs[v] );
                    nptrs--;
                    for( k = v; k < nptrs; k++ )
                    {
                        ptrs[k] = ptrs[k + 1];
                    }
                    ptrs[nptrs] = NULL;
                }
            }
        }

        // free all!
        for( j = nptrs - 1; j >= 0; j-- )
        {
            kal_adm_free( ap, ptrs[j] );
            ptrs[j] = NULL;
        }
        r = kal_adm_delete( ap );
        if( r != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_free() == %d", r );
            RESET;
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "new adm realloc dynamic_cache_switchable random test pass: total=%u(align=%u, non-align=%u), nullret=%u, totalsize=%u",
                  aacnt + acnt, aacnt, acnt, nullret, totalsize );
    RESET;
#else
    ktest_report( KTEST_PASS, KTEST_FUNCTION_NAME,
                  "__DYNAMIC_SWITCH_CACHEABILITY__ not supported" );
#endif
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_dyncache_randrealloc2
 * @remark brief: for ADM with NO-LOG, random test cache reallocate & dynamic
 *                switch cacheability function.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_dyncache_randrealloc2( kal_uint32 argc, void *argv )
{
#if defined( __MTK_TARGET__ ) && defined( __DYNAMIC_SWITCH_CACHEABILITY__ )
    return ktest_adm_dyncache_randrealloc1( 1, NULL );
#else
    KTEST_TCID = KTEST_FUNCTION_NAME;
    ktest_report( KTEST_PASS, KTEST_TCID,
                  "__DYNAMIC_SWITCH_CACHEABILITY__ not supported" );
#endif
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_dyncache_randrealloc3
 * @remark brief: for ADM with LOG, random test noncache allocate & dynamic
 *                switch cacheability function.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_dyncache_randrealloc3( kal_uint32 argc, void *argv )
{
#if defined( __MTK_TARGET__ ) && defined( __DYNAMIC_SWITCH_CACHEABILITY__ )
    return ktest_adm_dyncache_randrealloc1( 2, NULL );
#else
    KTEST_TCID = KTEST_FUNCTION_NAME;
    ktest_report( KTEST_PASS, KTEST_TCID,
                  "__DYNAMIC_SWITCH_CACHEABILITY__ not supported" );
#endif
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_dyncache_randrealloc4
 * @remark brief: for ADM with NO-LOG, random test noncache allocate & dynamic
 *                switch cacheability function.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_dyncache_randrealloc4( kal_uint32 argc, void *argv )
{
#if defined( __MTK_TARGET__ ) && defined( __DYNAMIC_SWITCH_CACHEABILITY__ )
    return ktest_adm_dyncache_randrealloc1( 3, NULL );
#else
    KTEST_TCID = KTEST_FUNCTION_NAME;
    ktest_report( KTEST_PASS, KTEST_TCID,
                  "__DYNAMIC_SWITCH_CACHEABILITY__ not supported" );
#endif
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_MTKL1Cache_randalloc1
 * @remark brief: for ADM with LOG on MTKL1Cache, random test cache allocate &
 *                dynamic switch cacheability function.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_MTKL1Cache_randalloc1( kal_uint32 argc, void *argv )
{
#if defined( __MTK_TARGET__ ) && defined( __MTK_L1CACHEABLE__ )
    KAL_ADM_ID ap;
    void *p, *ptrs[100];
    void *cacheptr = NULL;
    int nptrs, i, j, k, t, v;
    kal_status r;
    kal_uint32 alloc_size, maxsize, rsize;
    kal_uint32 align;
    kal_uint32 acnt = 0, aacnt = 0, nullret = 0, totalsize = 0;
    kal_uint32 cacnt = 0;

    if( argc == 0 )
    {
	    KTEST_TCID = KTEST_FUNCTION_NAME;
	}
	else
    {
	    KTEST_TCID = "ktest_adm_MTKL1Cache_randalloc2";
	}
	KTEST_EXPECT_ERR_CODE = 0;

    for( i = 0; i < 8; i++ )
    {
        kal_mem_set( ptrs, 0, sizeof(ptrs) );
        nptrs = 0;
        kal_mem_set( admbuf200K, 0, sizeof(admbuf200K) );
        ap = kal_adm_create( admbuf200K, sizeof(admbuf200K), NULL,
                             argc == 0 ? 1 : 0 );
        if( ap == NULL )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
            RESET;
        }

        for( j = 0; j < 3000; j++ )
        {
            if( j % 50 == 0 && cacheptr != NULL )
            {
                kal_adm_free( ap, cacheptr );
                cacheptr = NULL;
            }
            if( j % 100 == 0 && cacheptr == NULL )
            {
                const static int csomesizes[] = { 1, 100, 1024, 1025, 8196, 8195, 8197 };
                t = rand() % ( sizeof(csomesizes) / sizeof(csomesizes[0]) );
                alloc_size = csomesizes[t];

                p = kal_adm_alloc_mtkL1_cacheable( ap, alloc_size, ADM_CACHE_ALL_CHANNEL_COVER );
                if( p == NULL )
                {
                    continue;
                }
                cacheptr = p;
                kal_mem_set( p, 0xEB, alloc_size );
                cacnt++;
            }

            t = rand() % 3; // t=0,1: allocate; t=2: free
            if( t <= 1 && nptrs < sizeof(ptrs) / sizeof(ptrs[0]) )
            {
                // allocate from ADM
                const static int somesizes[] = {1, 4, 7, 17, 32, 100, 15, 13, 5,
                                                200};
                const static int somealigns[] = {4, 8, 4, 16, 4, 32, 16, 128};

                t = rand() % ( sizeof(somesizes) / sizeof(somesizes[0]) );
                alloc_size = somesizes[t];

                t = rand() % 50; // t=49: do maximum allocate
                align = somealigns[rand() % ( sizeof(somealigns) / sizeof(somealigns[0]) )];
                if( t == 49 )
                {
                    maxsize = kal_adm_get_max_alloc_size( ap );
                    if( maxsize > align )
                    {
                        alloc_size = maxsize - align;
                    }
                }

                if( align && align != 4 )
                {
                    aacnt++;
                }
                else
                {
                    acnt++;
                }

                p = kal_adm_alloc_align_with_info( ap, alloc_size, align, &rsize );
                if( p == NULL )
                {
                    nullret++;
                    maxsize = kal_adm_get_max_alloc_size( ap );
                    rsize = kal_adm_calc_worst_alloc_size( ap, alloc_size, align );
                    if( rsize > maxsize )
                    {
                        continue;
                    }
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= NULL: but max_size=%u, guarantee_size=%u",
                                  alloc_size, align, maxsize, rsize );
                    RESET;
                }
                if( rsize < 16 )
                {
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= %p: but real_size=%u < 16",
                                  alloc_size, align, p, rsize );
                    RESET;
                }
                else if( ( argc == 0 && rsize < LOG_SIZE(alloc_size) )
                         || ( argc == 1 && rsize < NOLOG_SIZE(alloc_size) ) )
                {
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= %p: but real_size=%u",
                                  alloc_size, align, p, rsize );
                    RESET;
                }
                else if( align && ( (kal_uint32) p % align != 0 ) )
                {
                    ktest_report( KTEST_FAIL, KTEST_TCID,
                                  "kal_adm_alloc(req_size=%u, align=%u)= %p: but NOT ALIGNED!",
                                  alloc_size, align, p );
                    RESET;
                }
                totalsize += alloc_size;
                kal_mem_set( p, 0xEB, alloc_size );
                ptrs[nptrs++] = p;

                check_pointers( ptrs, nptrs, argc == 0 ? 1 : 0, NULL );
            }
            else if( nptrs > 0 )
            {
                // free an buffer
                v = rand() % nptrs;
                *(kal_uint32 *) ptrs[v] = 0xFD579BA5;
                kal_adm_free( ap, ptrs[v] );
                check_pointers( ptrs, nptrs, argc == 0 ? 1 : 0, ptrs[v] );
                nptrs--;
                for( k = v; k < nptrs; k++ )
                {
                    ptrs[k] = ptrs[k + 1];
                }
                ptrs[nptrs] = NULL;
            }

            if( nptrs == sizeof(ptrs) / sizeof(ptrs[0]) )
            {
                // random free 10 buffers
                for( k = 0; k < 10; k++ )
                {
                    v = rand() % nptrs;
                    *(kal_uint32 *) ptrs[v] = 0xFD579BA3;
                    kal_adm_free( ap, ptrs[v] );
                    check_pointers( ptrs, nptrs, argc == 0 ? 1 : 0, ptrs[v] );
                    nptrs--;
                    for( k = v; k < nptrs; k++ )
                    {
                        ptrs[k] = ptrs[k + 1];
                    }
                    ptrs[nptrs] = NULL;
                }
            }
        }

        // free all!
        for( j = nptrs - 1; j >= 0; j-- )
        {
            kal_adm_free( ap, ptrs[j] );
            ptrs[j] = NULL;
        }
        if( cacheptr != NULL )
        {
            kal_adm_free( ap, cacheptr );
            cacheptr = NULL;
        }
        r = kal_adm_delete( ap );
        if( r != KAL_SUCCESS )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_free() == %d", r );
            RESET;
        }
    }

    ktest_report( KTEST_PASS, KTEST_TCID,
                  "new adm random test pass: total=%u(align=%u, non-align=%u), nullret=%u, totalsize=%u, cacnt=%u",
                  aacnt + acnt, aacnt, acnt, nullret, totalsize, cacnt );
    RESET;
#else   /*__MTK_L1CACHEABLE__*/
    ktest_report( KTEST_PASS, KTEST_FUNCTION_NAME, "__MTK_L1CACHEABLE__ not supported" );
#endif
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_MTKL1Cache_randalloc2
 * @remark brief: for ADM with NO-LOG on MTKL1Cache, random test cache allocate
 *                & dynamic switch cacheability function.
 * @remark dependency: none
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_adm_MTKL1Cache_randalloc2( kal_uint32 argc, void *argv )
{
#if defined( __MTK_TARGET__ ) && defined( __MTK_L1CACHEABLE__ )
    return ktest_adm_MTKL1Cache_randalloc1( 1, NULL );
#else /*__MTK_L1CACHEABLE__*/
    ktest_report( KTEST_PASS, KTEST_FUNCTION_NAME, "__MTK_L1CACHEABLE__ not supported" );
#endif
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_MTKL1Cache_alignalloc_31K_to_32K
 * @remark brief: kal_adm_alloc_mtkL1_cacheable() can return a 32K-aligned
 *                pointer if the adm pool is 31K-aligned.
 * @remark dependency: none
 * @remark expecation: kal_adm_alloc_mtkL1_cacheable()'s return pointer is 32K-align
 *****************************************************************************/
kal_int32 ktest_adm_MTKL1Cache_alignalloc_31K_to_32K( kal_uint32 argc, void *argv )
{
#if defined( __MTK_TARGET__ ) && defined( __MTK_L1CACHEABLE__ )
    KAL_ADM_ID ap;
    void *p;
    void *p_31K;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    p_31K = (void *) ( ((unsigned)admbuf200K + 32 * 1024 - 1) / (32 * 1024) * (32 * 1024) + 31 * 1024 );

    ap = kal_adm_create( p_31K, sizeof(admbuf200K) - ((unsigned)p_31K - (unsigned)admbuf200K), NULL, 1 );
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        RESET;
    }

    p = kal_adm_alloc_mtkL1_cacheable( ap, 4096, ADM_CACHE_ALL_CHANNEL_COVER );
    if( p == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_alloc_mtkL1_cacheable() == NULL" );
        RESET;
    }
    if( (unsigned) p % (32 * 1024) != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "pool_addr=%p, kal_adm_alloc_mtkL1_cacheable() == %p, but is not 32K-aligned",
                      p_31K, p );
        RESET;
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    RESET;
#else /*__MTK_L1CACHEABLE__*/
    ktest_report( KTEST_PASS, KTEST_FUNCTION_NAME, "__MTK_L1CACHEABLE__ not supported" );
#endif
}

/******************************************************************************
 * @remark category: adm
 * @remark name: ktest_adm_cache_fragment
 * @remark brief: try to show the fragmentation caused by different search size
 *                & split size for cache allocation.
 * @remark dependency: none
 * @remark expecation: fragmentation happened
 *****************************************************************************/
kal_int32 ktest_adm_cache_fragment( kal_uint32 argc, void *argv )
{
#if defined( __MTK_TARGET__ ) && defined( __ARM9_MMU__ )
    KAL_ADM_ID ap;
    kal_uint32 sz1, sz2;
    void *p1, *p2;
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    ap = kal_adm_create( admbuf200K_c, sizeof(admbuf200K_c), NULL, 0 ); // no logging
    if( ap == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_create() == NULL" );
        ktest_reset_target();
    }

    sz1 = kal_adm_get_max_alloc_size( ap ) - 1024;
    p1 = kal_adm_alloc_cacheable( ap, sz1, 0 );
    if( p1 == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_alloc_cacheable(%u) == NULL", sz1 );
        ktest_reset_target();
    }
    sz2 = kal_adm_get_max_alloc_size( ap );
    p2 = kal_adm_alloc( ap, sz2 );
    if( p2 == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_adm_alloc(%u) == NULL", sz2 );
        ktest_reset_target();
    }

    kal_adm_free( ap, p1 );
    p1 = kal_adm_alloc_cacheable( ap, sz1, 0 );
    if( p1 != NULL )
    {
		ktest_report( KTEST_PASS, KTEST_TCID,
                      "watch kal_adm_free(%u), then kal_adm_alloc_cacheable(%u) == NULL",
                      sz1, sz1 );
    }
    else
    {
         ktest_report( KTEST_FAIL, KTEST_TCID,
                       "expected kal_adm_alloc_cacheable(%u) == NULL, but got %p",
                       sz1, p1 );
    }
    ktest_reset_target();
#else
    ktest_report( KTEST_PASS, KTEST_FUNCTION_NAME,
                  "test case bypass because of absent of __ARM9_MMU__ option" );
#endif
}


/******************************************************************************
 * test case table of adm module in post-schedule stage.
 * note that the ones wrapped with FIX_OSCAR_FAIL will only be tested on target,
 *           but will be ignored on OSCAR.
 *****************************************************************************/
const ktest_tc_struct ktest_tc_mm_adm_tbl[] =
{
    {ktest_adm_create1, 0, NULL},
    {ktest_adm_create2, 0, NULL},
    {ktest_adm_create3, 0, NULL},
    {ktest_adm_create4, 0, NULL},
    {ktest_adm_alloc_size0, 0, NULL},
    {ktest_adm_simplecase1, 0, NULL},
    {ktest_adm_simplecase2, 0, NULL},
    {ktest_adm_simplecase3, 0, NULL},
    {ktest_adm_simplecase4, 0, NULL},
    {ktest_adm_simplecase5, 0, NULL},
    {ktest_adm_simplecase6, 0, NULL},
    {ktest_adm_simplecase7, 0, NULL},
    {ktest_adm_simplecase8, 0, NULL},
    {ktest_adm_corrupte_head1, 0, NULL},
#ifdef FIX_OSCAR_FAIL
    {ktest_adm_corrupte_head2, 0, NULL},
#endif
    {ktest_adm_corrupte_head4, 0, NULL},
    {ktest_adm_corrupte_foot1, 0, NULL},
#ifdef FIX_OSCAR_FAIL
    {ktest_adm_corrupte_nolog_head1, 0, NULL},
    {ktest_adm_corrupte_nolog_head2, 0, NULL},
#endif
    {ktest_adm_dummyhead_1, 0, NULL},
    {ktest_adm_old_alloc_overhead1, 0, NULL},
    {ktest_adm_new_alloc_overhead1, 0, NULL},
    {ktest_adm_new_alloc_overhead2, 0, NULL},
    {ktest_adm_max_alloc1, 0, NULL},
    {ktest_adm_leftsize1, 0, NULL},
    {ktest_adm_leftsize2, 0, NULL},
    {ktest_adm_randalloc1, 0, NULL},
    {ktest_adm_randalloc2, 0, NULL},
    {ktest_adm_topmost_leftsize1, 0, NULL},
    {ktest_adm_topmost_leftsize2, 0, NULL},
    {ktest_adm_topmost_randalloc1, 0, NULL},
    {ktest_adm_topmost_randalloc2, 0, NULL},
    {ktest_adm_dyncache_randalloc1, 0, NULL},
    {ktest_adm_dyncache_randalloc2, 0, NULL},
    {ktest_adm_dyncache_randalloc3, 0, NULL},
    {ktest_adm_dyncache_randalloc4, 0, NULL},
    {ktest_adm_MTKL1Cache_randalloc1, 0, NULL},
    {ktest_adm_MTKL1Cache_randalloc2, 0, NULL},
    {ktest_adm_MTKL1Cache_alignalloc_31K_to_32K, 0, NULL},
    {ktest_adm_cache_fragment, 0, NULL},
    {ktest_adm_reallocnull,0,NULL},
    {ktest_adm_reallocsize0,0,NULL},
	{ktest_adm_realloc_simplecase1,0,NULL},
	{ktest_adm_realloc_simplecase2,0,NULL},
	{ktest_adm_realloc_simplecase3,0,NULL},
	{ktest_adm_realloc_simplecase4,0,NULL},
	{ktest_adm_realloc_mergecase1,0,NULL},
	{ktest_adm_realloc_mergecase2,0,NULL},
	{ktest_adm_randrealloc1,0,NULL},
	{ktest_adm_randrealloc2,0,NULL},
	{ktest_adm_dyncache_randrealloc1,0,NULL},
	{ktest_adm_dyncache_randrealloc2,0,NULL},
	{ktest_adm_dyncache_randrealloc3,0,NULL},
	{ktest_adm_dyncache_randrealloc4,0,NULL},
};

/******************************************************************************
 * test case label of adm module in pre-schedule stage.
 * note that the ones wrapped with FIX_OSCAR_FAIL will only be tested on target,
 *           but will be ignored on OSCAR.
 *****************************************************************************/
const ktest_tc_struct ktest_pre_tc_mm_adm_tbl[] =
{
	{ktest_fake_test, 0, NULL},
};

/******************************************************************************
 * Name:
 *     ktest_tc_mm_adm_num
 * Functionality:
 *     caculate there are how many test cases of adm module in post-schedule
 *     stage.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of test cases of adm module in pre-schedule stage.
 *****************************************************************************/
kal_uint32 ktest_tc_mm_adm_num( void )
{
	return sizeof( ktest_tc_mm_adm_tbl ) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * Name:
 *     ktest_pre_tc_mm_adm_num
 * Functionality:
 *     caculate there are how many test cases of adm module in pre-schedule
 *     stage.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of test cases of adm module in pre-schedule stage.
 *****************************************************************************/
kal_uint32 ktest_pre_tc_mm_adm_num( void )
{
	return sizeof( ktest_pre_tc_mm_adm_tbl ) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * Name:
 *     ktest_mm_adm_init
 * Functionality:
 *     the initialization function of adm module.
 * Parameters:
 *     mod: id of adm module.
 * Returns:
 *     void.
 * Note:
 *     we should call this function in ktest_testcase_register, in order to
 *     register adm module into KTEST.
 *****************************************************************************/
void ktest_mm_adm_init(kal_uint32 mod)
{
	tc_all_tbls[mod] = ktest_tc_mm_adm_tbl;
	pre_tc_all_tbls[mod] = ktest_pre_tc_mm_adm_tbl;

	tc_modules_num[mod] = ktest_tc_mm_adm_num();
	pre_tc_modules_num[mod] = ktest_pre_tc_mm_adm_num();
}

#endif /*__KTEST__*/
