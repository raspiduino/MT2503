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
 *   ktest_tc_utl.c
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
#include "kal_release.h"
#include "lcd_ip_cqueue.h"

/******************************************************************************
 * each test case should return a value of kal_int32 type, but most test cases
 * call ktest_report at the end but forget to return a value.
 * so we define this macro to do this.
 *****************************************************************************/
#define MY_REPORT_RETURN(code, tcname, fmt) \
    ktest_report(code, tcname, fmt);\
    return code;

/******************************************************************************
 * compare results.
 *****************************************************************************/
#define KTEST_UTL_CMP_EQUAL    0
#define KTEST_UTL_CMP_GREATER  1
#define KTEST_UTL_CMP_LESS     -1

/******************************************************************************
 * buffer sizes.
 *****************************************************************************/
#define KTEST_BUFF_SIZE_10    10
#define KTEST_BUFF_SIZE_20    20
#define KTEST_BUFF_SIZE_30    30
#define KTEST_BUFF_SIZE_40    40
#define KTEST_BUFF_SIZE_50    50


/******************************************************************************
 * Name:
 *     ktest_utl_kal_mem_set
 * Functionality:
 *     test basic functionality of kal_mem_set(dest, value, size).
 *     that is, copy value into the first size bytes of the array pointed to
 *              by dest.
 * Results:
 *     the beginning "size" bytes of dest should be seted as "value".
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_mem_set( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    const kal_uint32 set_size = 5;
    kal_char buf[KTEST_BUFF_SIZE_10];
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize buf. */
    for( i = 0; i < buf_size; i++ )
    {
        buf[i] = 0x0F;
    }

    /* set buf's first "set_size" bytes to be 0. */
    kal_mem_set(buf, 0x0, set_size);

    /* test whether the first "set_size" bytes of buf are correct. */
    for( i = 0; i < set_size; i++ )
    {
        if( buf[i] != 0x0 )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_mem_set failed" );
        }
    }

    /* then test the last "set_size" bytes of buf. */
    for( i = set_size; i < buf_size; i++ )
    {
        if( buf[i] != 0x0F )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_mem_set failed" );
        }
    }

    /* buf's value is correct as expected, reprot PASS. */
    MY_REPORT_RETURN(KTEST_PASS, KTEST_TCID, NULL);
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_mem_cpy
 * Functionality:
 *     test basic functionality of kal_mem_cpy(dest, src, size).
 *     that is, copy "size" bytes from the array pointed to by src into the
 *              array pointed to by dest.
 * Results:
 *     the first "size" bytes of the array pointed to by dest is the same with
 *     the ones of the array pointed to by src.
 *     if so ,report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_mem_cpy( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    const kal_uint32 cpy_size = 5;
    kal_char src[KTEST_BUFF_SIZE_10];
    kal_char dest[KTEST_BUFF_SIZE_10];
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the src and dest buffer. */
    kal_mem_set(src, 0x0F, buf_size);
    kal_mem_set(dest, 0x0, buf_size);

    /* copy the first "cpy_size" bytes from src to dest. */
    kal_mem_cpy(dest, src, cpy_size);

    /* test whether the first "cpy_size" bytes of dest are correct. */
    for( i = 0; i < cpy_size; i++ )
    {
        if( dest[i] != 0x0F )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_mem_cpy failed" );
        }
    }

    /* then test whether the remaining bytes are correct. */
    for( i = cpy_size; i < buf_size; i++ )
    {
        if( dest[i] != 0x0 )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_mem_cpy failed" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_mem_cmp_func
 * Functionality:
 *     help to test basic functionality of kal_mem_cmp.
 * Parameters:
 *     src1: the first src to be compared.
 *     src2: the second src to be compared.
 *     cmp_size: how many bytes do you want to compare.
 *     expect_result: the result that you expected.
 *     tc_id: the name of the test case in which this function is called.
 * Returns:
 *     the return value is not used here.
 * Note:
 *     this is not a test case, but a function to help ktest_utl_kal_mem_cmp1,
 *     ktest_utl_kal_mem_cmp2, ktest_utl_kal_mem_cmp3 run.
 *****************************************************************************/
kal_int32 ktest_utl_kal_mem_cmp_func( const void *src1, const void *src2,
                                      kal_uint32 cmp_size,
                                      kal_int32 expect_result,
                                      const kal_char *tc_id )
{
    /* compare src1 with src2, and get the result of it. */
    kal_int32 result;
    result = kal_mem_cmp( src1, src2, cmp_size );
    if( result != KTEST_UTL_CMP_EQUAL )
    {
        result = (result > KTEST_UTL_CMP_EQUAL) ? KTEST_UTL_CMP_GREATER : KTEST_UTL_CMP_LESS;
    }

    /* test whether the real result is the one we expected. */
    if( result == expect_result )
    {
        MY_REPORT_RETURN( KTEST_PASS, tc_id, NULL );
    }
    else
    {
        MY_REPORT_RETURN( KTEST_FAIL, tc_id, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_mem_cmp1
 * Functionality:
 *     test basic functionality of kal_mem_cmp.
 *     that is, compare 2 strings with the same value.
 * Results:
 *     as we expected, the result of comparsion should be 0.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_mem_cmp1( kal_uint32 argc, void *argv )
{
    const kal_char *src1 = "abcdefg";
    const kal_char *src2 = "abcdefg";
    const kal_uint32 cmp_size = 5;
    const kal_int32 expect_result = KTEST_UTL_CMP_EQUAL;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* note that src1 and src2 have the same value. so the result we expected
     * is KTEST_UTL_CMP_EQUAL. */
    ret = ktest_utl_kal_mem_cmp_func( src1, src2, cmp_size, expect_result,
                                      KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_mem_cmp2
 * Functionality:
 *     test basic functionality of kal_mem_cmp.
 *     that is, compare 2 strings src1 and src2, and src1 is greater than src2.
 * Results:
 *     the result we expected is KTEST_UTL_CMP_GREATER.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_mem_cmp2( kal_uint32 argc, void *argv )
{
    const kal_char *src1 = "abcdefg";
    const kal_char *src2 = "abccdef";
    const kal_uint32 cmp_size = 5;
    const kal_int32 expect_result = KTEST_UTL_CMP_GREATER;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* note that src1 is greater than src2, so the result we expected is
     * KTEST_UTL_CMP_GREATER. */
    ret = ktest_utl_kal_mem_cmp_func( src1, src2, cmp_size, expect_result,
                                      KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_mem_cmp3
 * Functionality:
 *     test basic functionality of kal_mem_cmp.
 *     that is, compare 2 strings: src1 and src2, and src1 is less than src2.
 * Results:
 *     the result we expected is KTEST_UTL_CMP_LESS.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_mem_cmp3( kal_uint32 argc, void *argv )
{
    const kal_char *src1 = "abcdefg";
    const kal_char *src2 = "abcefgh";
    const kal_uint32 cmp_size = 5;
    const kal_int32 expect_result = KTEST_UTL_CMP_LESS;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* note that src1 is less than src2, so the expected result is
     * KTEST_UTL_CMP_LESS. */
    ret = ktest_utl_kal_mem_cmp_func( src1, src2, cmp_size, expect_result,
                                      KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strlen
 * Functionality:
 *     test basic functionality of kal_dchar_strlen, to get the length of a
 *     double character string, in terms of bytes.
 * Results:
 *     if the length of string is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strlen( kal_uint32 argc, void *argv )
{
    const kal_char *wstr = "ab\0cdef\0gh\0\0ikjl";
    const kal_int32 dchar_len = 10;
    const kal_uint32 cpy_size = 16;
    const kal_uint32 buf_size = 20;
    kal_char buf[KTEST_BUFF_SIZE_20];
    kal_int32 len;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize buf to be 0. */
    kal_mem_set(buf, 0x0, buf_size);

    /* copy "cpy_size" from wstr to buf. */
    kal_mem_cpy(buf, wstr, cpy_size);

    /* get the length of buf by calling kal_dchar_strlen, the result is in terms
     * of bytes. */
    len = kal_dchar_strlen(buf);

    /* in kal_dchar_strlen, the length of wstr should be 10.
     * test whether the real result is the same as we expected. */
    if( len == dchar_len )
    {
        MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strlen failed" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strcpy
 * Functionality:
 *     test basic functionality of kal_dchar_strcpy(to, from).
 *     that is, copy the content of double charactures string "from" into
 *              double charactures string "to".
 * Results:
 *     the content of "to" will be the same as "from" after calling
 *     kal_dchar_strcpy.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strcpy( kal_uint32 argc, void *argv )
{
    const kal_char *wstr = "ab\0cdef\0gh\0\0ikjl";
    const kal_uint32 cmp_size = 12;
    const kal_uint32 buf_size = 20;
    kal_char buf[KTEST_BUFF_SIZE_20];
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf". */
    kal_mem_set(buf, 0x0F, buf_size);

    /* copy the content of "wstr" to "buf". */
    kal_dchar_strcpy(buf, wstr);

    /* test whether the content of "buf" is correct after copy. */
    result = kal_mem_cmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strcpy failed" );
    }

    /* test whether the remaining part of "buf" is correct. */
    for( i = cmp_size; i < buf_size; i++ )
    {
        if( buf[i] != 0x0F )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_dchar_strcpy failed" );
        }
    }

    /* if we come here, that means the kal_dchar_cpy is correct. */
    MY_REPORT_RETURN(KTEST_PASS, KTEST_TCID, NULL);
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strncpy1
 * Functionality:
 *     test basic functionality of kal_dchar_strncpy(to, from, n).
 * Results:
 *     as expected, the first "n" bytes of double charactures string "to" should
 *     be the same as that of double charactures string "from".
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strncpy1( kal_uint32 argc, void *argv )
{
    const kal_char *wstr = "ab\0cdef\0gh\0\0ikjl";
    const kal_uint32 cpy_size = 8;
    const kal_uint32 cmp_size = 8;
    const kal_uint32 buf_size = 20;
    kal_char buf[KTEST_BUFF_SIZE_20];
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf". */
    kal_mem_set( buf, 0x0F, buf_size );

    /* copy the first "cpy_size" bytes from "wstr" to "buf". */
    kal_dchar_strncpy( buf, wstr, cpy_size );

    /* test whether the content of "buf" is correct. */
    result = kal_mem_cmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strncpy1 failed" );
    }

    if( buf[cmp_size] != 0x0 || buf[cmp_size + 1] != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strncpy1 failed" );
    }

    for( i = cmp_size + 2; i < buf_size; i++ )
    {
        if( buf[i] != 0x0F )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_dchar_strncpy1 failed" );
        }
    }

    /* the content of "buf" is correct after copy. */
    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strncpy2
 * Functionality:
 *     test basic functionality of kal_dchar_strncpy(to, from, n).
 * Results:
 *     if the content of "to" is correct after copy, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strncpy2( kal_uint32 argc, void *argv )
{
    const kal_char *wstr = "ab\0cdef\0gh\0\0ikjl";
    const kal_uint32 cpy_size = 14;
    const kal_uint32 cmp_size1 = 12;
    const kal_uint32 cmp_size2 = 14;
    const kal_uint32 buf_size = 20;
    kal_char buf[KTEST_BUFF_SIZE_20];
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf". */
    kal_mem_set( buf, 0xF, buf_size );

    /* copy the first "cpy_size" from "wstr" to "buf". */
    kal_dchar_strncpy( buf, wstr, cpy_size );

    /* test whether the content of "buf" is correct. */
    result = kal_mem_cmp( buf, wstr, cmp_size1 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strncpy2 failed" );
    }

    for( i = cmp_size1; i < cmp_size2; i++ )
    {
        if( buf[i] != 0x0 )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_dchar_strncpy2 failed" );
        }
    }

    for( i = cmp_size2; i < buf_size; i++ )
    {
        if( buf[i] != 0xF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_dchar_strncpy2 failed" );
        }
    }

    /* if the content of "buf" is correct, report PASS. */
    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strncpy3
 * Functionality:
 *     test basic functionality of kal_dchar_strncpy(to, from, n).
 *     that is, copy n + 1 ( n is odd and shorter than the length of charactures
 *              string "from" ) wide charactures from the content of double
 *              charactures string "from" into double charactures string "to".
 * Results:
 *     if the first (n + 1) bytes of double charactures string "to" is the same
 *     as the ones of double charactures string "from", report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strncpy3( kal_uint32 argc, void *argv )
{
    const kal_char *wstr = "ab\0cdef\0gh\0\0ikjl";
    const kal_uint32 cpy_size = 7;
    const kal_uint32 cmp_size = 8;
    const kal_uint32 buf_size = 20;
    kal_char buf[KTEST_BUFF_SIZE_20];
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf". */
    kal_mem_set( buf, 0xF, buf_size );

    /* copy "cpy_size" bytes from "wstr" to "buf". */
    kal_dchar_strncpy( buf, wstr, cpy_size );

    /* test whether the content of "buf" is correct. */
    result = kal_mem_cmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strncpy3 failed" );
    }

    if( buf[cmp_size] != 0x0 || buf[cmp_size + 1] != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strncpy3 failed" );
    }

    for( i = cmp_size + 2; i < buf_size; i++ )
    {
        if( buf[i] != 0xF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_dchar_strncpy3 failed" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strncpy4
 * Functionality:
 *     test kal_dchar_strncpy(to, from, n).
 *     that is, copy n + 1 ( n is odd and longer than the length of charactures
 *              string "from" ) wide charactures from the content of double
 *              charactures string from into double charactures string to.
 * Results:
 *     if the content of "to" is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strncpy4( kal_uint32 argc, void *argv )
{
    const kal_char *wstr = "ab\0cdef\0gh\0\0ikjl";
    const kal_uint32 cpy_size = 13;
    const kal_uint32 cmp_size1 = 12;
    const kal_uint32 cmp_size2 = 14;
    const kal_uint32 buf_size = 20;
    kal_char buf[KTEST_BUFF_SIZE_20];
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf". */
    kal_mem_set( buf, 0xF, buf_size );

    /* copy the first "cpy_size" bytes from "wstr" to "buf". */
    kal_dchar_strncpy( buf, wstr, cpy_size );

    /* test whether the content of "buf" is correct. */
    result = kal_mem_cmp( buf, wstr, cmp_size1 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strncpy4 failed" );
    }

    for( i = cmp_size1; i < cmp_size2; i++ )
    {
        if( buf[i] != 0x0 )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_dchar_strncpy4 failed" );
        }
    }

    for( i = cmp_size2; i < buf_size; i++ )
    {
        if( buf[i] != 0xF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_dchar_strncpy4 failed" );
        }
    }

    /* if the content of "buf" is correct, report PASS here. */
    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strcmp_func
 * Functionality:
 *     help to test kal_dchar_strcmp.
 * Parameters:
 *     src1: the first string to compare.
 *     src2: the second string to compare.
 *     expect_result: the result we expected.
 *     tc_id: function name of the test case.
 * Returns:
 *     a value of kal_int32 type, but not used here.
 * Note:
 *     this is not a test case, but will be used in ktest_utl_kal_dchar_strcmp1,
 *     ktest_utl_kal_dchar_strcmp2, ktest_utl_kal_dchar_strcmp3,
 *     ktest_utl_kal_dchar_strcmp4, ktest_utl_kal_dchar_strcmp5.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strcmp_func( const void *src1, const void *src2,
                                           kal_int32 expect_result,
                                           const kal_char *tc_id)
{
    kal_int32 result;

    /* compare src1 with src2, then check the result of this comparison. */
    result = kal_dchar_strcmp( src1, src2 );
    if( result != KTEST_UTL_CMP_EQUAL )
    {
        result = ( result > KTEST_UTL_CMP_EQUAL ) ?
                      KTEST_UTL_CMP_GREATER : KTEST_UTL_CMP_LESS;
    }

    if( result == expect_result )
    {
        MY_REPORT_RETURN( KTEST_PASS, tc_id, NULL );
    }
    else
    {
        MY_REPORT_RETURN( KTEST_FAIL, tc_id, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strcmp1
 * Functionality:
 *     test basic functionality of kal_dchar_strcmp.
 * Results:
 *     as we expected, the result of comparison should be KTEST_UTL_CMP_EQUAL,
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strcmp1( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 20;
    const kal_uint32 cpy_size = 14;
    kal_char buf1[KTEST_BUFF_SIZE_20];
    kal_char buf2[KTEST_BUFF_SIZE_20];
    const kal_int32 expect_result = KTEST_UTL_CMP_EQUAL;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize "buf1" and "buf2". note that they have the same value. */
    kal_mem_set(buf1, 0xFF, buf_size);
    kal_mem_set(buf2, 0xFF, buf_size);

    /* copy the same content to "buf1" and "buf2". */
    kal_mem_cpy(buf1, "ab\0cdef\0ghij\0\0", cpy_size);
    kal_mem_cpy(buf2, "ab\0cdef\0ghij\0\0", cpy_size);

    /* compare "buf1" with "buf2". */
    ret = ktest_utl_kal_dchar_strcmp_func( buf1, buf2, expect_result,
                                           KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strcmp2
 * Functionality:
 *     test basic functionality of kal_dchar_strcmp.
 * Results:
 *     if the result of this comparison is KTEST_UTL_CMP_LESS, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strcmp2( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 20;
    const kal_uint32 cpy_size = 14;
    kal_char buf1[KTEST_BUFF_SIZE_20];
    kal_char buf2[KTEST_BUFF_SIZE_20];
    const kal_int32 expect_result = KTEST_UTL_CMP_LESS;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize "buf1" and "buf2". */
    kal_mem_set( buf1, 0xFF, buf_size );
    kal_mem_set( buf2, 0xFF, buf_size );

    /* copy different values into "buf1" and "buf2". */
    kal_mem_cpy( buf1, "ab\0cdef\0ghij\0\0", cpy_size );
    kal_mem_cpy( buf2, "ab\0cdef\0hhij\0\0", cpy_size );

    /* compare "buf1" with "buf2". */
    ret = ktest_utl_kal_dchar_strcmp_func( buf1, buf2, expect_result,
                                           KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strcmp3
 * Functionality:
 *     test basic functionality of kal_dchar_strcmp.
 * Results:
 *     if the result of this comparison is KTEST_UTL_CMP_GREATER, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strcmp3( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 20;
    const kal_uint32 cpy_size = 14;
    kal_char buf1[KTEST_BUFF_SIZE_20];
    kal_char buf2[KTEST_BUFF_SIZE_20];
    const kal_int32 expect_result = KTEST_UTL_CMP_GREATER;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize "buf1" and "buf2". */
    kal_mem_set(buf1, 0xFF, buf_size);
    kal_mem_set(buf2, 0xFF, buf_size);

    /* copy different values into "buf1" and "buf2", note that "buf1" is greater
     * than "buf2". */
    kal_mem_cpy(buf1, "ab\0cdef\0hhij\0\0", cpy_size);
    kal_mem_cpy(buf2, "ab\0cdef\0ghij\0\0", cpy_size);

    /* compare "buf1" with "buf2". */
    ret = ktest_utl_kal_dchar_strcmp_func( buf1, buf2, expect_result,
                                           KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strcmp4
 * Functionality:
 *     test basic functionality of kal_dchar_strcmp.
 * Results:
 *     if the result of comparsion is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strcmp4( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 20;
    const kal_uint32 cpy_size = 14;
    kal_char buf1[KTEST_BUFF_SIZE_20];
    kal_char buf2[KTEST_BUFF_SIZE_20];
    const kal_int32 expect_result = KTEST_UTL_CMP_LESS;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize "buf1" and "buf2". */
    kal_mem_set( buf1, 0xFF, buf_size );
    kal_mem_set( buf2, 0xFF, buf_size );

    /* copy different values into "buf1" and "buf2", note that "buf1" is greater
     * than "buf2". */
    kal_mem_cpy( buf1, "ab\0cdef\0hhij\0\0", cpy_size );
    kal_mem_cpy( buf2, "ab\0cdef\0giij\0\0'", cpy_size );

    /* compare "buf1" with "buf2". */
    ret = ktest_utl_kal_dchar_strcmp_func( buf1, buf2, expect_result,
                                           KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strcmp5
 * Functionality:
 *     test basic functionality of kal_dchar_strcmp.
 * Results:
 *     if the result of comparsion is the same as we expected, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strcmp5( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 20;
    const kal_uint32 cpy_size = 14;
    kal_char buf1[KTEST_BUFF_SIZE_20];
    kal_char buf2[KTEST_BUFF_SIZE_20];
    const kal_int32 expect_result = KTEST_UTL_CMP_GREATER;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize "buf1" and "buf2". */
    kal_mem_set( buf1, 0xFF, buf_size );
    kal_mem_set( buf2, 0xFF, buf_size );

    /* copy different values into "buf1" and "buf2", note that "buf1" is less
     * than "buf2". */
    kal_mem_cpy( buf1, "ab\0cdef\0giij\0\0", cpy_size );
    kal_mem_cpy( buf2, "ab\0cdef\0hhij\0\0", cpy_size );

    ret = ktest_utl_kal_dchar_strcmp_func( buf1, buf2, expect_result,
                                           KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strncmp_func
 * Functionality:
 *     help to test kal_dchar_strncmp.
 * Parameters:
 *     src1: the first string to compare.
 *     src2: the second string to compare.
 *     cmp_size: how many bytes do you want to compare.
 *     expect_result: the result that you expected.
 *     tc_id: function name of the test case.
 * Returns:
 *     a value of kal_int32 type, but not used here.
 * Note:
 *     this is not a test case, and it will be only used in
 *     ktest_utl_kal_dchar_strncmp1, ktest_utl_kal_dchar_strncmp2,
 *     ktest_utl_kal_dchar_strncmp3, ktest_utl_kal_dchar_strncmp4,
 *     ktest_utl_kal_dchar_strncmp5, ktest_utl_kal_dchar_strncmp6.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strncmp_func( const void *src1, const void *src2,
                                            kal_uint32 cmp_size,
                                            kal_int32 expect_result,
                                            const kal_char *tc_id )
{
    kal_int32 result;

    /* compare "src1" with "src2", then check whether the result is the same as
     * we expected. */
    result = kal_dchar_strncmp( src1, src2, cmp_size );
    if( result != 0 )
    {
        result = ( result > KTEST_UTL_CMP_EQUAL ) ?
                     KTEST_UTL_CMP_GREATER : KTEST_UTL_CMP_LESS;
    }

    if( result == expect_result )
    {
        MY_REPORT_RETURN( KTEST_PASS, tc_id, NULL );
    }
    else
    {
        MY_REPORT_RETURN( KTEST_FAIL, tc_id, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strncmp1
 * Functionality:
 *     test basic functionality of kal_dchar_strncmp.
 * Results:
 *     if the result of comparison is just what we expected, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strncmp1( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 20;
    const kal_uint32 cpy_size = 14;
    const kal_uint32 cmp_size = 10;
    kal_char buf1[KTEST_BUFF_SIZE_20];
    kal_char buf2[KTEST_BUFF_SIZE_20];
    const kal_int32 expect_result = KTEST_UTL_CMP_EQUAL;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize "buf1" and "buf2". */
    kal_mem_set( buf1, 0xFF, buf_size );
    kal_mem_set( buf2, 0xFF, buf_size );

    /* copy the same value into "buf1" and "buf2". */
    kal_mem_cpy(buf1, "ab\0cdef\0ghij\0\0", cpy_size);
    kal_mem_cpy(buf2, "ab\0cdef\0ghij\0\0", cpy_size);

    /* compare "buf1" with "buf2", note that they have the same value. */
    ret = ktest_utl_kal_dchar_strncmp_func( buf1, buf2, cmp_size, expect_result,
                                            KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strncmp2
 * Functionality:
 *     test basic functionality of kal_dchar_strncmp.
 * Results:
 *     if the result of comparison is just what we expected, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strncmp2( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 20;
    const kal_uint32 cpy_size = 14;
    const kal_uint32 cmp_size = 16;
    kal_char buf1[KTEST_BUFF_SIZE_20];
    kal_char buf2[KTEST_BUFF_SIZE_20];
    const kal_int32 expect_result = KTEST_UTL_CMP_EQUAL;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize "buf1" and "buf2". */
    kal_mem_set( buf1, 0xFF, buf_size );
    kal_mem_set( buf2, 0xFF, buf_size );

    /* copy the same value into "buf1" and "buf2". */
    kal_mem_cpy(buf1, "ab\0cdef\0ghij\0\0", cpy_size);
    kal_mem_cpy(buf2, "ab\0cdef\0ghij\0\0", cpy_size);

    /* compare "buf1" with "buf2", note that the "cmp_size" is different from
     * the test case above. */
    ret = ktest_utl_kal_dchar_strncmp_func( buf1, buf2, cmp_size, expect_result,
                                            KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strncmp3
 * Functionality:
 *     test basic functionality of kal_dchar_strncmp.
 * Results:
 *     if the result of comparison is just the same as we expected, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strncmp3( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 20;
    const kal_uint32 cpy_size = 14;
    const kal_uint32 cmp_size = 10;
    kal_char buf1[KTEST_BUFF_SIZE_20];
    kal_char buf2[KTEST_BUFF_SIZE_20];
    const kal_int32 expect_result = KTEST_UTL_CMP_LESS;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize "buf1" and "buf2". */
    kal_mem_set( buf1, 0xFF, buf_size );
    kal_mem_set( buf2, 0xFF, buf_size );

    /* copy different values into "buf1" and "buf2", note that "buf1" is less
     * than "buf2". */
    kal_mem_cpy( buf1, "ab\0cdef\0ghij\0\0", cpy_size );
    kal_mem_cpy( buf2, "ab\0cdef\0hhij\0\0", cpy_size );

    /* compare "buf1" with "buf2". */
    ret = ktest_utl_kal_dchar_strncmp_func( buf1, buf2, cmp_size, expect_result,
                                            KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strncmp4
 * Functionality:
 *     test basic functionality of kal_dchar_strncmp.
 * Results:
 *     if the result of comparison is just the same as we expected, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strncmp4( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 20;
    const kal_uint32 cpy_size = 14;
    const kal_uint32 cmp_size = 10;
    kal_char buf1[KTEST_BUFF_SIZE_20];
    kal_char buf2[KTEST_BUFF_SIZE_20];
    const kal_int32 expect_result = KTEST_UTL_CMP_GREATER;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize "buf1" and "buf2". */
    kal_mem_set( buf1, 0xFF, buf_size );
    kal_mem_set( buf2, 0xFF, buf_size );

    /* copy different values into "buf1" and "buf2", note that "buf1" is greater
     * than "buf2". */
    kal_mem_cpy( buf1, "ab\0cdef\0hhij\0\0", cpy_size );
    kal_mem_cpy( buf2, "ab\0cdef\0ghij\0\0", cpy_size );

    /* compare "buf1" with "buf2". */
    ret = ktest_utl_kal_dchar_strncmp_func( buf1, buf2, cmp_size, expect_result,
                                            KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strncmp5
 * Functionality:
 *     test kal_dchar_strncmp.
 * Results:
 *     if the result of comparison is just the same as we expected, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strncmp5( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 20;
    const kal_uint32 cpy_size = 14;
    const kal_uint32 cmp_size = 10;
    kal_char buf1[KTEST_BUFF_SIZE_20];
    kal_char buf2[KTEST_BUFF_SIZE_20];
    const kal_int32 expect_result = KTEST_UTL_CMP_LESS;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize "buf1" and "buf2". */
    kal_mem_set( buf1, 0xFF, buf_size );
    kal_mem_set( buf2, 0xFF, buf_size );

    /* copy different values into "buf1" and "buf2", note that "buf1" is greater
     * than "buf2". */
    kal_mem_cpy( buf1, "ab\0cdef\0hhij\0\0", cpy_size );
    kal_mem_cpy( buf2, "ab\0cdef\0giij\0\0'", cpy_size );

    /* compare "buf1" with "buf2". */
    ret = ktest_utl_kal_dchar_strncmp_func( buf1, buf2, cmp_size, expect_result,
                                            KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strncmp6
 * Functionality:
 *     test basic functionality of kal_dchar_strncmp.
 * Results:
 *     if the result of comparison is just the same as we expected, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strncmp6( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 20;
    const kal_uint32 cpy_size = 14;
    const kal_uint32 cmp_size = 10;
    kal_char buf1[KTEST_BUFF_SIZE_20];
    kal_char buf2[KTEST_BUFF_SIZE_20];
    const kal_int32 expect_result = KTEST_UTL_CMP_GREATER;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize "buf1" and "buf2". */
    kal_mem_set( buf1, 0xFF, buf_size );
    kal_mem_set( buf2, 0xFF, buf_size );

    /* copy different values into "buf1" and "buf2", note that "buf1" is less
     * than "buf2". */
    kal_mem_cpy( buf1, "ab\0cdef\0giij\0\0", cpy_size );
    kal_mem_cpy( buf2, "ab\0cdef\0hhij\0\0", cpy_size );

    /* compare "buf1" with "buf2". */
    ret = ktest_utl_kal_dchar_strncmp_func( buf1, buf2, cmp_size, expect_result,
                                            KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strcat
 * Functionality:
 *     test basic functionality of kal_dchar_strcat.
 * Results:
 *     if the result after concatenate is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strcat(kal_uint32 argc, void *argv)
{
    const kal_char *wstr1 = "ab\0cdef\0gh\0\0ijkl";
    const kal_char *wstr2 = "lm\0mopq\0rs\0\0tuvw";
    const kal_uint32 cmp_size1 = 10;
    const kal_uint32 cmp_size2 = 12;
    const kal_uint32 buf_size = 40;
    kal_char buf[KTEST_BUFF_SIZE_40];
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf". */
    kal_mem_set( buf, 0xF, buf_size );

    /* copy the value of "wstr1" into "buf". */
    kal_dchar_strcpy( buf, wstr1 );

    /* append "wstr2" to "buf", so the content of "buf" should be the conetnt of
     * "wstr1" followed by that of "wstr2". */
    kal_dchar_strcat( buf, wstr2 );

    /* test whether the content of "buf" is correct. */
    result = kal_mem_cmp( buf, wstr1, cmp_size1 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strcat failed" );
    }

    result = kal_mem_cmp( buf + cmp_size1, wstr2, cmp_size2 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strcat failed" );
    }

    for( i = cmp_size1 + cmp_size2; i < buf_size; i++ )
    {
        if( buf[i] != 0xF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_dchar_strcat failed" );
        }
    }

    /* if we come here, that means the content of "buf" is the same as we
     * expected, report PASS here. */
    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strncat1
 * Functionality:
 *     test basic functionality of kal_dchar_strncat.
 * Results:
 *     if the result after concatenate is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strncat1( kal_uint32 argc, void *argv )
{
    const kal_char *wstr1 = "ab\0cdef\0gh\0\0ijkl";
    const kal_char *wstr2 = "lm\0mopq\0rs\0\0tuvw";
    const kal_uint32 cat_size = 6;
    const kal_uint32 cmp_size1 = 10;
    const kal_uint32 cmp_size2 = 6;
    const kal_uint32 buf_size = 40;
    kal_char buf[KTEST_BUFF_SIZE_40];
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf". */
    kal_mem_set( buf, 0xF, buf_size );

    /* copy the content of "wstr1" into "buf". */
    kal_dchar_strcpy( buf, wstr1 );

    /* concatenate the first "cat_size" of "wstr2" to "buf". */
    kal_dchar_strncat( buf, wstr2, cat_size );

    /* check whether the content of "buf" is correct. */
    result = kal_mem_cmp( buf, wstr1, cmp_size1 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strncat1 failed" );
    }

    result = kal_mem_cmp( buf + cmp_size1, wstr2, cmp_size2 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strncat1 failed" );
    }

    if( buf[cmp_size1 + cmp_size2] != 0x0
        || buf[cmp_size1 + cmp_size2 + 1] != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strncpy1 failed" );
    }

    for( i = cmp_size1 + cmp_size2 + 2; i < buf_size; i++ )
    {
        if( buf[i] != 0xF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_dchar_strncat1 failed" );
        }
    }

    /* the content of "buf" is correct after concatenation. */
    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strncat2
 * Functionality:
 *     test basic functionality of kal_dchar_strncat.
 * Results:
 *     if the result after concatenation is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strncat2( kal_uint32 argc, void *argv )
{
    const kal_char *wstr1 = "ab\0cdef\0gh\0\0ijkl";
    const kal_char *wstr2 = "lm\0mopq\0rs\0\0tuvw";
    const kal_uint32 cat_size = 14;
    const kal_uint32 cmp_size1 = 10;
    const kal_uint32 cmp_size2 = 12;
    const kal_uint32 buf_size = 40;
    kal_char buf[KTEST_BUFF_SIZE_40];
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf". */
    kal_mem_set( buf, 0xF, buf_size );

    /* copy the content of "wstr1" into "buf". */
    kal_dchar_strcpy( buf, wstr1 );

    /* concatenate the first "cat_size" of "wstr2" to "buf". */
    kal_dchar_strncat( buf, wstr2, cat_size );

    /* check whether the content of "buf" is just the same as we expected. */
    result = kal_mem_cmp( buf, wstr1, cmp_size1 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strncat2 failed" );
    }

    result = kal_mem_cmp( buf + cmp_size1, wstr2, cmp_size2 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strncat2 failed" );
    }

    for( i = cmp_size1 + cmp_size2; i < buf_size; i++ )
    {
        if( buf[i] != 0xF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_dchar_strncat2 failed" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strncat3
 * Functionality:
 *     test basic functionality of kal_dchar_strncat.
 * Results:
 *     if the content of "buf" is correct after concatenation, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strncat3( kal_uint32 argc, void *argv )
{
    const kal_char *wstr1 = "ab\0cdef\0gh\0\0ijkl";
    const kal_char *wstr2 = "lm\0mopq\0rs\0\0tuvw";
    const kal_uint32 cat_size = 5;
    const kal_uint32 cmp_size1 = 10;
    const kal_uint32 cmp_size2 = 6;
    const kal_uint32 buf_size = 40;
    kal_char buf[KTEST_BUFF_SIZE_40];
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf". */
    kal_mem_set( buf, 0xF, buf_size );

    /* copy "wstr1" to "buf". */
    kal_dchar_strcpy( buf, wstr1 );

    /* concatenate the first "cat_size" bytes of "wstr2" to "buf". */
    kal_dchar_strncat( buf, wstr2, cat_size );

    /* test whether the content of "buf" is correct. */
    result = kal_mem_cmp( buf, wstr1, cmp_size1 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strncat3 failed" );
    }

    result = kal_mem_cmp( buf + cmp_size1, wstr2, cmp_size2 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strncat3 failed" );
    }

    if( buf[cmp_size1 + cmp_size2] != 0x0
        || buf[cmp_size1 + cmp_size2 + 1] != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strncat3 failed" );
    }

    for( i = cmp_size1 + cmp_size2 + 2; i < buf_size; i++ )
    {
        if( buf[i] != 0xF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_dchar_strncat3 failed" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strncat4
 * Functionality:
 *     test basic functionality of kal_dchar_strncat.
 * Results:
 *     if the content of "buf" is correct after concatenation, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strncat4( kal_uint32 argc, void *argv )
{
    const kal_char *wstr1 = "ab\0cdef\0gh\0\0ijkl";
    const kal_char *wstr2 = "lm\0mopq\0rs\0\0tuvw";
    const kal_uint32 cat_size = 13;
    const kal_uint32 cmp_size1 = 10;
    const kal_uint32 cmp_size2 = 12;
    const kal_uint32 buf_size = 40;
    kal_char buf[KTEST_BUFF_SIZE_40];
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf". */
    kal_mem_set( buf, 0xF, buf_size );

    /* copy the content of "wstr1" to "buf". */
    kal_dchar_strcpy( buf, wstr1 );

    /* concatenate the first "cat_size" bytes of "wstr2" to "buf". */
    kal_dchar_strncat( buf, wstr2, cat_size );

    /* check whether the content of "buf" is correct. */
    result = kal_mem_cmp( buf, wstr1, cmp_size1 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strncat4 failed" );
    }

    result = kal_mem_cmp( buf + cmp_size1, wstr2, cmp_size2 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strncat4 failed" );
    }

    for( i = cmp_size1 + cmp_size2; i < buf_size; i++ )
    {
        if( buf[i] != 0xF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_dchar_strncat4 failed" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strchr1
 * Functionality:
 *     test basic functionality of kal_dchar_strchr.
 * Results:
 *     if it returns the first occurrence of the character, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strchr1( kal_uint32 argc, void *argv )
{
    const kal_char *wstr = "abcd\0bef\0cgbcdijbcklbcmn\0\0op";
    const kal_int32 chr_c = 0x6362; /* "bc" */
    const kal_uint32 chr_pos = 16;
    const kal_uint32 buf_size = 50;
    kal_char buf[KTEST_BUFF_SIZE_50];
    kal_char *result;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf". */
    kal_mem_set( buf, 0xFF, buf_size );

    /* copy the content of "wstr" to "buf". */
    kal_dchar_strcpy( buf, wstr );

    /* look for "chr_c" in "buf", if found, return its first occurrence. */
    result = kal_dchar_strchr( buf, chr_c );
    if( result != NULL && result == (char *) (buf + chr_pos) )
    {
        MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strchr1 failed" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strchr2
 * Functionality:
 *     test basic functionality of kal_dchar_strchr.
 * Results:
 *     since the character we look for is not in the string, so it will return
 *     null as we expected, if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strchr2( kal_uint32 argc, void *argv )
{
    const kal_char *wstr = "abcd\0bef\0cgbcdijklmn\0\0op";
    const kal_int32 chr_c = 0x6362; /* "bc" */
    const kal_uint32 buf_size = 50;
    kal_char buf[KTEST_BUFF_SIZE_50];
    kal_char *result;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf". */
    kal_mem_set( buf, 0xFF, buf_size );

    /* copy the content of "wstr" to "buf". */
    kal_dchar_strcpy( buf, wstr );

    /* look for "chr_c" in "buf". since it is not in "buf", so the return value
     * should be null. */
    result = kal_dchar_strchr( buf, chr_c );
    if( result == NULL )
    {
        MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strchr2 failed" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strrchr1
 * Functionality:
 *     test basic functionality of kal_dchar_strrchr.
 * Results:
 *     if it returns the last occurrence of the character, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strrchr1( kal_uint32 argc, void *argv )
{
    const kal_char *wstr = "abcd\0bef\0cgbcdijbcabcd\0bef\0cgbcdijbckl\0\0mn";
    const kal_int32 chr_c = 0x6362; /* "bc" */
    const kal_uint32 chr_pos = 34;
    const kal_uint32 buf_size = 50;
    kal_char buf[KTEST_BUFF_SIZE_50];
    kal_char *result;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf". */
    kal_mem_set( buf, 0xFF, buf_size );

    /* copy the content of "wstr" to "buf". */
    kal_dchar_strcpy( buf, wstr );

    /* look for the last occurrence of "chr_c" in "buf". */
    result = kal_dchar_strrchr( buf, chr_c );
    if( result != NULL && result == (char *) (buf + chr_pos) )
    {
        MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strrchr1 failed" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar_strrchr2
 * Functionality:
 *     test basic functionality of kal_dchar_strrchr.
 * Results:
 *     since the character is not in the string, so it will return null.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar_strrchr2( kal_uint32 argc, void *argv )
{
    const kal_char *wstr = "abcd\0bef\0cgbcdijabcd\0bef\0cgbcdijkl\0\0mn";
    const kal_int32 chr_c = 0x6362; /* "bc" */
    const kal_uint32 buf_size = 50;
    kal_char buf[KTEST_BUFF_SIZE_50];
    kal_char *result;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf". */
    kal_mem_set( buf, 0xFF, buf_size );

    /* copy the content of "wstr" into "buf". */
    kal_dchar_strcpy( buf, wstr );

    /* look for the last occurrence of "chr_c" in "buf". */
    result = kal_dchar_strrchr( buf, chr_c );
    if ( result == NULL )
    {
        MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar_strrchr2 failed" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_dchar2char
 * Functionality:
 *     test basic functionality of kal_dchar2char. that is, convert a wide
 *     character string to a single character string.
 * Results:
 *     if we can convert a wide character string to a single character one
 *     successfully, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_dchar2char( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    WCHAR wstr[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF, 0x1234,
                                       0x0056,0x789A, 0xBC00, 0xDEF0, 0x0000 };
    const kal_char str[KTEST_BUFF_SIZE_10] = { 0x23, 0x67, 0xAB, 0xEF, 0x34,
                                               0x56, 0x9A, 0x00 };
    const kal_uint32 cmp_size = 8;
    kal_char buf[KTEST_BUFF_SIZE_10];
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf". */
    kal_mem_set( buf, 0xF, buf_size );

    /* convert "wstr" to a single character string, and store the result into
     * "buf". */
    kal_dchar2char( wstr, buf );

    /* the result should be the same as that of "str". */
    result = kal_mem_cmp( buf, str, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_dchar2char failed" );
    }

    for( i = cmp_size; i < buf_size; i++ )
    {
        if( buf[i] != 0xF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_dchar2char failed" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrlen
 * Functionality:
 *     test basic functionality of kal_wstrlen. that is, get the length of a
 *     wide character string, in terms of WCHAR.
 * Results:
 *     if the length of the wide character string is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrlen( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    const WCHAR wstr[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                             0x1200, 0x3456, 0x0078, 0x9AB0,
                                             0x0000, 0xFFFF };
    const kal_int32 wstr_len = 8;
    kal_int32 len;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* caculate the length of "wstr". */
    len = kal_wstrlen( wstr );

    /* as we expected, the length of "wstr" should be 8. */
    if( len == wstr_len )
    {
        MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wstrlen failed" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrcmp_func
 * Functionality:
 *     help to compare two wild character strings.
 * Parameters:
 *     src1: the first wide character string to compare.
 *     src2: the second wide character string to compare.
 *     expect_result: the result we expected.
 *     tc_id: function name of the test caes.
 * Returns:
 *     a value of kal_int32 type, but not used here.
 * Note:
 *     this is not a test case, it will be used in ktest_utl_kal_wstrcmp1,
 *     ktest_utl_kal_wstrcmp2, ktest_utl_kal_wstrcmp3.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrcmp_func( const void *src1, const void *src2,
                                      kal_int32 expect_result,
                                      const kal_char *tc_id )
{
    kal_int32 result;

    /* compare two wide character strings. */
    result = kal_wstrcmp( src1, src2 );
    if( result != KTEST_UTL_CMP_EQUAL )
    {
        result = ( result > KTEST_UTL_CMP_EQUAL ) ?
                     KTEST_UTL_CMP_GREATER : KTEST_UTL_CMP_LESS;
    }

    if( result == expect_result )
    {
        MY_REPORT_RETURN( KTEST_PASS, tc_id, NULL );
    }
    else
    {
        MY_REPORT_RETURN( KTEST_FAIL, tc_id, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrcmp1
 * Functionality:
 *     test basic functionality of kal_wstrcmp.
 * Results:
 *     if the result of comparison is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrcmp1( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    const WCHAR wstr1[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x1200, 0x3456, 0x0078, 0x9AB0,
                                              0x0000, 0xCDEF };
    const WCHAR wstr2[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x1200, 0x3456, 0x0078, 0x9AB0,
                                              0x0000, 0x1234 };
    const kal_int32 expect_result = KTEST_UTL_CMP_EQUAL;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* compare "wstr1" with "wstr2", since they are all wide character strings,
     * so the contents of them are the same. */
    ret = ktest_utl_kal_wstrcmp_func( wstr1, wstr2, expect_result, KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrcmp2
 * Functionality:
 *     test basic functionality of kal_wstrcmp.
 * Results:
 *     since "wstr1" is greater than "wstr2", so the return value should be
 *     KTEST_UTL_CMP_GREATER.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrcmp2( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    const WCHAR wstr1[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x1200, 0x3456, 0x0078, 0x9AB1,
                                              0x0000, 0xFFFF };
    const WCHAR wstr2[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x1200, 0x3456, 0x0078, 0x9AB0,
                                              0x0000, 0xFFFF };
    const kal_int32 expect_result = KTEST_UTL_CMP_GREATER;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* compare "wstr1" with "wstr2".
     * note that "wstr1" is greater than "wstr2". */
    ret = ktest_utl_kal_wstrcmp_func( wstr1, wstr2, expect_result, KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrcmp3
 * Functionality:
 *     test basic functionality of kal_wstrcmp.
 * Results:
 *     since "wstr1" is less than "wstr2", so the result should be
 *     KTEST_UTL_CMP_LESS.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrcmp3( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    const WCHAR wstr1[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x1200, 0x3456, 0x0078, 0x9AB0,
                                              0x0000, 0xFFFF };
    const WCHAR wstr2[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x1200, 0x3456, 0x0078, 0x9AB1,
                                              0x0000, 0xFFFF };
    const kal_int32 expect_result = KTEST_UTL_CMP_LESS;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* compare "wstr1" with "wstr2", note that "wstr1" is less than "wstr2". */
    ret = ktest_utl_kal_wstrcmp_func( wstr1, wstr2, expect_result, KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrncmp_func
 * Functionality:
 *     help to test kal_wstrncmp.
 * Parameters:
 *     src1: the first wide character string to compare.
 *     src2: the second wide character string to compare.
 *     cmp_size: how many wide characters do you want to compare.
 *     expect_result: the result you expected.
 *     tc_id: function name of the test case.
 * Returns:
 *     a value of kal_int32 type, but not used here.
 * Note:
 *     this is not a test case, but only be used in ktest_utl_kal_wstrncmp1,
 *     ktest_utl_kal_wstrncmp2, ktest_utl_kal_wstrncmp3, ktest_utl_kal_wstrncmp4.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrncmp_func( const void *src1, const void *src2,
                                       kal_uint32 cmp_size,
                                       kal_int32 expect_result,
                                       const kal_char *tc_id )
{
    kal_int32 result;

    /* compare at most "cmp_size" wide characters of "src1" and "src2". */
    result = kal_wstrncmp( src1, src2, cmp_size );
    if( result != KTEST_UTL_CMP_EQUAL )
    {
        result = ( result > KTEST_UTL_CMP_EQUAL ) ?
                     KTEST_UTL_CMP_GREATER : KTEST_UTL_CMP_LESS;
    }

    if( result == expect_result )
    {
        MY_REPORT_RETURN( KTEST_PASS, tc_id, NULL );
    }
    else
    {
        MY_REPORT_RETURN( KTEST_FAIL, tc_id, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrncmp1
 * Functionality:
 *     test basic functionality of kal_wstrncmp.
 * Results:
 *     as we expected, the comparison of two strings with the same content will
 *     return KTEST_UTL_CMP_EQUAL. if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrncmp1( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    const WCHAR wstr1[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x1234, 0x1234, 0x0000, 0xFFFF,
                                              0xFFFF, 0xFFFF };
    const WCHAR wstr2[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x1234, 0x3456, 0x0000, 0xFFFF,
                                              0xFFFF, 0xFFFF };
    const kal_uint32 cmp_size = 5;
    const kal_int32 expect_result = KTEST_UTL_CMP_EQUAL;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* compare two wide character strings. note that "cmp_size" is 5, and the
     * first 5 wide characters in "wstr1" are same with the ones in "wstr2". */
    ret = ktest_utl_kal_wstrncmp_func( wstr1, wstr2, cmp_size, expect_result,
                                       KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrncmp2
 * Functionality:
 *     test basic functionality of kal_wstrncmp.
 * Results:
 *     if the comparison returns KTEST_UTL_CMP_EQUAL, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrncmp2( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    const WCHAR wstr1[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0x0000,
                                              0x1234, 0xFFFF, 0xFFFF, 0xFFFF,
                                              0xFFFF, 0xFFFF };
    const WCHAR wstr2[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0x0000,
                                              0x5678, 0xFFFF, 0xFFFF, 0xFFFF,
                                              0xFFFF, 0xFFFF };
    const kal_uint32 cmp_size = 5;
    const kal_int32 expect_result = KTEST_UTL_CMP_EQUAL;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* compare two wide character strings. although the "cmp_size" is 5, but
     * only the first 3 wide characters in "wstr1" should be compared with the
     * ones in "wstr2". */
    ret = ktest_utl_kal_wstrncmp_func( wstr1, wstr2, cmp_size, expect_result,
                                       KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrncmp3
 * Functionality:
 *     test basic functionality of kal_wstrncmp.
 * Results:
 *     since "wstr1" is greater than "wstr2", so the result should be
 *     KTEST_UTL_CMP_GREATER.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrncmp3( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    const WCHAR wstr1[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x3456, 0x3456, 0x0000, 0xFFFF,
                                              0xFFFF, 0xFFFF };
    const WCHAR wstr2[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x1234, 0x3456, 0x0000, 0xFFFF,
                                              0xFFFF, 0xFFFF };
    const kal_uint32 cmp_size = 5;
    const kal_int32 expect_result = KTEST_UTL_CMP_GREATER;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* compare the first "cmp_size" wide characters in "wstr1" with the ones in
     * "wstr2". */
    ret = ktest_utl_kal_wstrncmp_func( wstr1, wstr2, cmp_size, expect_result,
                                       KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrncmp4
 * Functionality:
 *     test basic functionality of kal_wstrncmp.
 * Results:
 *     since "wstr1" is less than "wstr2", so it will return KTEST_UTL_CMP_LESS.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrncmp4( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    const WCHAR wstr1[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x1234, 0x3456, 0x0000, 0xFFFF,
                                              0xFFFF, 0xFFFF };
    const WCHAR wstr2[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x3456, 0x3456, 0x0000, 0xFFFF,
                                              0xFFFF, 0xFFFF };
    const kal_uint32 cmp_size = 5;
    const kal_int32 expect_result = KTEST_UTL_CMP_LESS;
    kal_int32 ret;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* compare "wstr1" with "wstr2", note that "wstr1" is less than "wstr2". */
    ret = ktest_utl_kal_wstrncmp_func( wstr1, wstr2, cmp_size, expect_result,
                                       KTEST_TCID );
    return ret;
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrcpy
 * Functionality:
 *     test basic functionality of kal_wstrcpy.
 * Results:
 *     if success, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrcpy( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    const WCHAR wstr1[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x1200, 0x3456, 0x0078, 0x9AB0,
                                              0x0000, 0xFFFF };
    WCHAR wstr2[KTEST_BUFF_SIZE_10];
    const kal_uint32 cmp_size = 9;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "wstr2". */
    kal_mem_set( (kal_char *) wstr2, 0xFF, buf_size * 2 );

    /* copy the content of "wstr1" to "wstr2". */
    kal_wstrcpy( wstr2, wstr1 );

    /* check whether the content of "wstr2" is same as that of "wstr1". */
    result = kal_wstrncmp( wstr1, wstr2, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wstrcpy failed" );
    }

    for( i = cmp_size; i < buf_size; i++ )
    {
        if( wstr2[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wstrcpy failed" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrncpy1
 * Functionality:
 *     test basic functionality of kal_wstrncpy(to, from, n).
 *     that is, copy "n" ( "n" is shorter than the length of charactures string
 *              "from" ) wide characters from the content of wide characters
 *              string "from" into wide characters string "to".
 * Results:
 *     as we expected, the first "n" WCHAR of wide characters string "to" should
 *     be the same as the ones of wide characters string "from".
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrncpy1( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    const WCHAR wstr1[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x1200, 0x3456, 0x0000, 0xFFFF,
                                              0xFFFF, 0xFFFF };
    WCHAR wstr2[KTEST_BUFF_SIZE_10];
    const kal_uint32 cpy_size = 5;
    const kal_uint32 cmp_size = 5;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "wstr2". */
    kal_mem_set( (kal_char *) wstr2, 0xFF, buf_size * 2 );

    /* copy at most "cpy_size" wide characters of "wstr1" into "wstr2". */
    kal_wstrncpy( wstr2, wstr1, cpy_size );

    /* check whether the content of "wstr2" is what we expected. */
    result = kal_wstrncmp( wstr1, wstr2, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wstrncpy1 failed" );
    }

    if( wstr2[cmp_size] != 0x0 )
    {
        MY_REPORT_RETURN(KTEST_FAIL, KTEST_TCID,
                         "ktest_utl_kal_wstrncpy1 failed" );
    }

    for( i = cmp_size + 1; i < buf_size; i++ )
    {
        if( wstr2[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wstrncpy1 failed" );
        }
    }

    /* no error occurs, report PASS. */
    MY_REPORT_RETURN(KTEST_PASS, KTEST_FUNCTION_NAME, NULL);
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrncpy2
 * Functionality:
 *     test basic functionality of kal_wstrncpy(to, from, n).
 *     that is, copy "n" ( "n" is longer than the length of charactures string
 *              "from" ) wide characters from the content of wide characters
 *              string "from" into wide characters string "to".
 * Results:
 *     as we expected, the wide characters string "to" should be the same as
 *     wide characters string "from", and the charactures exceed to length of
 *     "from" are filled with '\0'.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrncpy2( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    const WCHAR wstr1[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x1200, 0x3456, 0x0000, 0xFFFF,
                                              0xFFFF, 0xFFFF };
    WCHAR wstr2[KTEST_BUFF_SIZE_10];
    const kal_uint32 cpy_size = 8;
    const kal_uint32 cmp_size1 = 6;
    const kal_uint32 cmp_size2 = 8;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "wstr2". */
    kal_mem_set( (kal_char *)wstr2, 0xFF, buf_size * 2 );

    /* copy the first "cpy_size" wide characters of "wstr1" into "wstr2".
     * note that the wide character at index "6" is 0x0000. */
    kal_wstrncpy( wstr2, wstr1, cpy_size );

    /* test whether the first "cmp_size1" wide characters of "wstr2" are the
     * same as those of "wstr1". */
    result = kal_wstrncmp( wstr1, wstr2, cmp_size1 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wstrncpy2 failed" );
    }

    for( i = cmp_size1; i < cmp_size2; i++ )
    {
        if( wstr2[i] != 0x0 )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wstrncpy2 failed" );
        }
    }

    for( i = cmp_size2; i < buf_size; i++ )
    {
        if( wstr2[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wstrncpy2 failed" );
        }
    }

    /* no error occurs, report PASS. */
    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrcat
 * Functionality:
 *     test basic functionality of kal_wstrcat(s1, s2).
 *     that is, concatenate a copy of wide characters string "s2" to the wide
 *              characters string "s1".
 * Results:
 *     as we expected, "s1" should be concatenated with a copy of "s2".
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrcat( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size1 = 10;
    const WCHAR wstr1[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x1200, 0x3456, 0x0078, 0x0000,
                                              0xFFFF, 0xFFFF };
    const WCHAR wstr2[KTEST_BUFF_SIZE_10] = { 0x3210, 0x7654, 0xBA98, 0xFEDC,
                                              0x3200, 0x7654, 0x0000, 0xFFFF,
                                              0xFFFF, 0xFFFF };
    const kal_uint32 cmp_size1 = 7;
    const kal_uint32 cmp_size2 = 6;
    const kal_uint32 buf_size2 = 20;
    WCHAR buf[KTEST_BUFF_SIZE_20];
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size2 * 2 );

    /* copy the content of "wstr1" into "buf". now the content of "buf" is the
     * same as that of "wstr1". */
    kal_wstrcpy( buf, wstr1 );

    /* concatenate the content of "wstr2" to "buf". */
    kal_wstrcat( buf, wstr2 );

    /* test whether the content of "buf" is correct.
     * as expected, it will be the content of "wstr1" followed by that of
     * "wstr2". */
    result = kal_wstrncmp( buf, wstr1, cmp_size1 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wstrcat failed" );
    }

    result = kal_wstrncmp( buf + cmp_size1, wstr2, cmp_size2 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wstrcat failed" );
    }

    if( buf[cmp_size1 + cmp_size2] != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wstrncat1 failed" );
    }

    for( i = cmp_size1 + cmp_size2 + 1; i < buf_size2; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wstrcat failed" );
        }
    }

    /* no error occurs, report PASS. */
    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrncat1
 * Functionality:
 *     test basic functionality of kal_wstrncat(s1, s2, n).
 *     that is, concatenate a copy of the first "n" wide characters of "s2" to
 *              "s1".
 * Results:
 *     as expected, "s1" should be concatenated with a copy of the first "n"
 *     wide characters of "s2".
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrncat1( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size1 = 10;
    const WCHAR wstr1[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x1200, 0x3456, 0x0078, 0x0000,
                                              0xFFFF, 0xFFFF };
    const WCHAR wstr2[KTEST_BUFF_SIZE_10] = { 0x3210, 0x7654, 0xBA98, 0xFEDC,
                                              0x3200, 0x7654, 0x0000, 0xFFFF,
                                              0xFFFF, 0xFFFF };
    const kal_uint32 cat_size = 3;
    const kal_uint32 cmp_size1 = 7;
    const kal_uint32 cmp_size2 = 3;
    const kal_uint32 buf_size2 = 20;
    WCHAR buf[KTEST_BUFF_SIZE_20];
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf", note that every wide characters in it is
     * 0xFF now. */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size2 * 2 );

    /* copy the content of "wstr1" into "buf", it will be ended when 0x0000 is
     * found. */
    kal_wstrcpy( buf, wstr1 );

    /* concatenate at most "cat_size" wide characters of "wstr2" to "buf".
     * it will be ended when 0x0000 is found. */
    kal_wstrncat( buf, wstr2, cat_size );

    /* now the content of "buf" should be the content of "wstr1" followed by
     * that of "wstr2". */
    result = kal_wstrncmp( buf, wstr1, cmp_size1 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wstrncat1 failed" );
    }

    result = kal_wstrncmp( buf + cmp_size1, wstr2, cmp_size2 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wstrncat1 failed" );
    }

    if( buf[cmp_size1 + cmp_size2] != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wstrncat1 failed" );
    }

    for( i = cmp_size1 + cmp_size2 + 1; i < buf_size2; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wstrncat1 failed" );
        }
    }

    /* no error occurs, report PASS. */
    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrncat2
 * Functionality:
 *     test basic functionality of kal_wstrncat(s1, s2, n).
 *     that is, concatenate a copy of the whole content of "s2" to "s1".
 * Results:
 *     as expected, "s1" should be concatenated with a copy of "s2".
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrncat2( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size1 = 10;
    const WCHAR wstr1[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                              0x1200, 0x3456, 0x0078, 0x0000,
                                              0xFFFF, 0xFFFF };
    const WCHAR wstr2[KTEST_BUFF_SIZE_10] = { 0x3210, 0x7654, 0xBA98, 0xFEDC,
                                              0x3200, 0x7654, 0x0000, 0xFFFF,
                                              0xFFFF, 0xFFFF };
    const kal_uint32 cat_size = 8;
    const kal_uint32 cmp_size1 = 7;
    const kal_uint32 cmp_size2 = 7;
    const kal_uint32 buf_size2 = 20;
    WCHAR buf[KTEST_BUFF_SIZE_20];
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* initialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size2 * 2 );

    /* copy the content of "wstr1" into "buf". */
    kal_wstrcpy( buf, wstr1 );

    /* concatenate at most "cat_size" wide characters of "wstr2" to "buf". */
    kal_wstrncat( buf, wstr2, cat_size );

    /* check whether the content of "buf" is just the same as we expected. */
    result = kal_wstrncmp( buf, wstr1, cmp_size1 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wstrncat1 failed" );
    }

    result = kal_wstrncmp( buf + cmp_size1, wstr2, cmp_size2 );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wstrncat1 failed" );
    }

    for( i = cmp_size1 + cmp_size2; i < buf_size2; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wstrncat1 failed" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrchr1
 * Functionality:
 *     test basic functionality of kal_wstrchr(s, c).
 *     that is, search the first occurrence of "c" in the wide characters string
 *              pointed to by "s".
 * Results:
 *     if it returns the first occurrence of "c" in "s", report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrchr1( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    const WCHAR wstr[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                             0x1200, 0x89AB, 0x0078, 0x9AB0,
                                             0x0000, 0xFFFF };
    const WCHAR chr = 0x89AB;
    const kal_uint32 chr_pos = 2;
    WCHAR *result;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* search "chr" in "wstr". if found, return its first occurrence. */
    result = kal_wstrchr( wstr, chr );
    if( result != NULL  && result == (WCHAR *) (wstr + chr_pos) )
    {
        MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );

    }
    else
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wstrchr1 failed" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrchr2
 * Functionality:
 *     test basic functionality of kal_wstrchr(s, c).
 *     that is, we can not find the occurrence of "c" since it is not in the
 *              wide characters string pointed to by "s".
 * Results:
 *     since "c" is not in "s", so the result should be null.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrchr2( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    const WCHAR wstr[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                             0x1200, 0x89AB, 0x0078, 0x9AB0,
                                             0x0000, 0xFFFF };
    const WCHAR chr = 0xFFFF;
    WCHAR *result;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* search "chr" in "wstr". since "chr" is not in "wstr", so it will return
     * null. */
    result = kal_wstrchr( wstr, chr );
    if( result == NULL )
    {
        MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );

    }
    else
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wstrchr2 failed" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrrchr1
 * Functionality:
 *     test basic functionality of kal_wstrrchr(s, c).
 *     that is, find the last occurrence of "c" in the wide characters string
 *              pointed to by "s".
 * Results:
 *     as expected, it will return the last occurrence of "c" in "s".
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrrchr1( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    const WCHAR wstr[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                             0x1200, 0x89AB, 0x0078, 0x9AB0,
                                             0x0000, 0xFFFF };
    const WCHAR chr = 0x89AB;
    const kal_uint32 chr_pos = 5;
    WCHAR *result;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* try to find the last occurrence of "chr" in "wstr". since it is really
     * in the string ,so the last occurrence of it will be returned. */
    result = kal_wstrrchr( wstr, chr );
    if( result != NULL && result == (WCHAR *) (wstr + chr_pos) )
    {
        MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );

    }
    else
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wstrrchr1 failed" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wstrrchr2
 * Functionality:
 *     test basic functionality of kal_wstrrchr(s, c).
 * Results:
 *     since "c" is not in "s", so the result should be null.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wstrrchr2( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 10;
    const WCHAR wstr[KTEST_BUFF_SIZE_10] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                             0x1200, 0x89AB, 0x0078, 0x9AB0,
                                             0x0000, 0xFFFF };
    const WCHAR chr = 0xFFFF;
    WCHAR *result;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    result = kal_wstrrchr( wstr, chr );
    if( result == NULL )
    {
        MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );

    }
    else
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wstrrchr2 failed" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wsprintf1
 * Functionality:
 *     test basic functionality of kal_wsprintf.
 *     write 2 characters into buffer, then check whether it is correct.
 * Results:
 *     if the result is correct after calling kal_wsprintf, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wsprintf1( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 20;
    const WCHAR wstr[KTEST_BUFF_SIZE_20] = { 0x0061, 0x002C, 0x0062, 0x0 }; /* a,b */
    WCHAR buf[KTEST_BUFF_SIZE_20];
    const kal_char c1 = 'a';
    const kal_char c2 = 'b';
    const kal_uint32 cmp_size = 4;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF="characters";

    /* inittialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size * 2 );

    /* print "c1" and "c2" into "buf". */
    kal_wsprintf(buf, "%c,%c", c1, c2);

    /* check whether the content of "buf" is correct. */
    result = kal_wstrncmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wsprintf1 failed1" );
    }

    for( i = cmp_size ; i < buf_size; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wsprintf1 failed2" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wsprintf2
 * Functionality:
 *     test basic functionality of kal_wsprintf.
 *     write 2 integers into the buffer, then check whether it is correct.
 * Results:
 *     if the buffer's content is correct after calling kal_wsprintf, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wsprintf2( kal_uint32 argc, void* argv )
{
    const kal_uint32 buf_size = 20;
    const WCHAR wstr[KTEST_BUFF_SIZE_20] = { 0x0031, 0x0032, 0x0033, 0x002C,
                                             0x002D, 0x0034, 0x0035, 0x0036,
                                             0x0037, 0x0 }; /* 123,-4567 */
    WCHAR buf[KTEST_BUFF_SIZE_20];
    const kal_int32 d1 = 123;
    const kal_int32 d2 = -4567;
    const kal_uint32 cmp_size = 10;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF="signed decimal";

    /* initialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size * 2 );

    /* write "d1" and "d2" to "buf". */
    kal_wsprintf( buf, "%d,%d", d1, d2 );

    /* check whether the content of "buf" is correct. */
    result = kal_wstrncmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wsprintf2 failed1" );
    }

    for( i = cmp_size ; i < buf_size; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wsprintf2 failed2" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wsprintf3
 * Functionality:
 *     test basic functionality of kal_wsprintf.
 *     write 2 integers into the buffer, then check whether it is correct.
 * Results:
 *     if the content of buffer is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wsprintf3( kal_uint32 argc, void *argv )
{

    const kal_uint32 buf_size = 20;
    const WCHAR wstr[KTEST_BUFF_SIZE_20] = { 0x0031, 0x0032, 0x0033, 0x002C,
                                             0x0020, 0x0020, 0x0020, 0x002D,
                                             0x0034, 0x0035, 0x0036, 0x0037,
                                             0x0 }; /* 123,000-4567 */
    WCHAR buf[KTEST_BUFF_SIZE_20];
    const kal_int32 d1 = 123;
    const kal_int32 d2 = -4567;
    const kal_uint32 cmp_size = 13;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF=" signed decimal with width";

    /* initialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size * 2 );

    /* write 2 integers into "buf". note they are signed decimal with width. */
    kal_wsprintf( buf, "%2d,%8d", d1, d2 );

    /* check whether the content of "buf" is correct. */
    result = kal_wstrncmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wsprintf3 failed1" );
    }

    for( i = cmp_size ; i < buf_size; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wsprintf3 failed2" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wsprintf4
 * Functionality:
 *     test basic functionality of kal_wsprintf.
 *     write 2 strings into the buffer, then check whether it is correct.
 * Results:
 *     if the content of buffer is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wsprintf4( kal_uint32 argc, void* argv )
{
    const kal_uint32 buf_size = 20;
    const WCHAR wstr[KTEST_BUFF_SIZE_20] = { 0x0031, 0x0032, 0x0033,
                                             0x002C, 0x0061, 0x0062,
                                             0x0 }; /* 123,ab */
    WCHAR buf[KTEST_BUFF_SIZE_20];
    const kal_char *s1 = "123";
    const kal_char *s2 = "ab";
    const kal_uint32 cmp_size = 8;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF="string";

    /* initialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size * 2 );

    /* write 2 strings into "buf". */
    kal_wsprintf( buf, "%s,%s", s1, s2 );

    /* check whether the content of "buf" is correct. */
    result = kal_wstrncmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wsprintf4 failed1" );
    }

    for( i = cmp_size ; i < buf_size; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wsprintf4 failed2" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wsprintf5
 * Functionality:
 *     test basic functionality of kal_wsprintf.
 *     write 2 unsigned decimals into buffer, then check whether it is correct.
 * Results:
 *     if the content of buffer is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wsprintf5( kal_uint32 argc, void* argv )
{
    const kal_uint32 buf_size = 20;
    const WCHAR wstr[KTEST_BUFF_SIZE_20] = { 0x0031, 0x0032, 0x0033, 0x002C,
                                             0x0034, 0x0032, 0x0039, 0x0034,
                                             0x0039, 0x0036, 0x0032, 0x0037,
                                             0x0032, 0x0039, 0x0 };
                                             /* 123,4294962729 */
    WCHAR buf[KTEST_BUFF_SIZE_20];
    const kal_int32 d1 = 123;
    const kal_int32 d2 = -4567;
    const kal_uint32 cmp_size = 15;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF="unsigned decimal";

    /* initialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size * 2 );

    /* write 2 unsigned decimals into "buf". */
    kal_wsprintf( buf, "%u,%u", d1, d2 );

    /* check whether the content of "buf" is correct. */
    result = kal_wstrncmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wsprintf5 failed1" );
    }

    for( i = cmp_size ; i < buf_size; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wsprintf5 failed2" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wsprintf6
 * Functionality:
 *     test basic functionality of kal_wsprintf.
 *     write 2 unsigned decimals with width into buffer, then check whether it
 *     is correct.
 * Results:
 *     if the content of buffer is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wsprintf6( kal_uint32 argc, void* argv )
{
    const kal_uint32 buf_size = 20;
    const WCHAR wstr[KTEST_BUFF_SIZE_20] = { 0x0031, 0x0032, 0x0033, 0x002C,
                                             0x0020, 0x0020, 0x0034, 0x0032,
                                             0x0039, 0x0034, 0x0039, 0x0036,
                                             0x0032, 0x0037, 0x0032, 0x0039,
                                             0x0 }; /* 123,004294962729 */
    WCHAR buf[KTEST_BUFF_SIZE_20];
    const kal_int32 d1 = 123;
    const kal_int32 d2 = -4567;
    const kal_uint32 cmp_size = 17;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF="unsigned decimal with width";

    /* initialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size * 2 );

    /* write 2 unsigned decimals with width into "buf". */
    kal_wsprintf( buf, "%2u,%12u", d1, d2 );

    /* check whether the content of "buf" is correct. */
    result = kal_wstrncmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wsprintf6 failed1" );
    }

    for( i = cmp_size ; i < buf_size; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wsprintf6 failed2" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wsprintf7
 * Functionality:
 *     test basic functionality of kal_wsprintf.
 *     write 2 wide character strings into buffer, then check whether it is
 *     correct.
 * Results:
 *     if the content of buffer is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wsprintf7( kal_uint32 argc, void* argv )
{

    const kal_uint32 buf_size = 20;
    const WCHAR wstr[KTEST_BUFF_SIZE_20] = { 0x0123, 0x4567, 0x89AB, 0xCDEF,
                                             0x002C, 0xFEDC, 0xBA98, 0x7654,
                                             0x0 };
    WCHAR buf[KTEST_BUFF_SIZE_20];
    const WCHAR w1[KTEST_BUFF_SIZE_20] = { 0x0123, 0x4567, 0x89AB, 0xCDEF, 0x0 };
    const WCHAR w2[KTEST_BUFF_SIZE_20] = { 0xFEDC, 0xBA98, 0x7654, 0x0 };
    const kal_uint32 cmp_size = 9;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF="string to WCHAR";

    /* initialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size * 2 );

    /* write 2 wide character strings into "buf". */
    kal_wsprintf( buf, "%w,%w", w1, w2 );

    /* check whether the content of "buf" is correct. */
    result = kal_wstrncmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wsprintf7 failed1" );
    }

    for( i = cmp_size ; i < buf_size; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wsprintf7 failed2" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wsprintf8
 * Functionality:
 *     test basic functionality of kal_wsprintf.
 *     write 2 decimals of upper hexadecimal type into buffer, then check
 *     whether it is correct.
 * Results:
 *     if the content of buffer is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wsprintf8( kal_uint32 argc, void* argv )
{

    const kal_uint32 buf_size = 20;
    const WCHAR wstr[KTEST_BUFF_SIZE_20] = { 0x0030, 0x0078, 0x0037, 0x0042,
                                             0x002c, 0x0030, 0x0078, 0x0046,
                                             0x0046, 0x0046, 0x0046, 0x0045,
                                             0x0045, 0x0032, 0x0039, 0x0000 };
    WCHAR buf[KTEST_BUFF_SIZE_20];
    const kal_int32 d1 = 123; /* 0x7B */
    const kal_int32 d2 = -4567; /* 0xFFFFEE29 */
    const kal_uint32 cmp_size = 16;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "upper hexadecimal";

    /* initialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size * 2 );

    /* write 2 upper hexadecimals into "buf". */
    kal_wsprintf( buf, "0x%X,0x%X", d1, d2 );

    /* check whether the content of "buf" is correct. */
    result = kal_wstrncmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wsprintf8 failed1" );
    }

    for( i = cmp_size ; i < buf_size; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wsprintf8 failed2" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wsprintf9
 * Functionality:
 *     test basic functionality of kal_wsprintf.
 *     write 2 unsigned hexadecimals with width into buffer, then check whether
 *     the content of buffer is correct.
 * Results:
 *     if the content of buffer is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wsprintf9( kal_uint32 argc, void* argv )
{
    const kal_uint32 buf_size = 20;
    const WCHAR wstr[KTEST_BUFF_SIZE_20] = { 0x0030, 0x0078, 0x0037, 0x0042,
                                             0x002c, 0x0030, 0x0078, 0x0020,
                                             0x0020, 0x0046, 0x0046, 0x0046,
                                             0x0046, 0x0045, 0x0045, 0x0032,
                                             0x0039, 0x0000 };
    WCHAR buf[KTEST_BUFF_SIZE_20];
    const kal_int32 d1 = 123; /* 0x7B */
    const kal_int32 d2 = -4567; /* 0xFFFFEE29 */
    const kal_uint32 cmp_size = 18;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "unsigned hexadecimal with width";

    /* initialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size * 2 );

    /* write 2 unsigned hexadecimals with width into "buf". */
    kal_wsprintf( buf, "0x%1X,0x%10X", d1, d2 );

    /* check whether the content of "buf" is correct. */
    result = kal_wstrncmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wsprintf9 failed1" );
    }

    for( i = cmp_size ; i < buf_size; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wsprintf9 failed2" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wsprintf10
 * Functionality:
 *     test basic functionality of kal_wsprintf.
 *     write 2 decimals with width into buffer, then check whether it is correct.
 * Results:
 *     if the content of buffer is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wsprintf10( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 20;
    const WCHAR wstr[KTEST_BUFF_SIZE_20] = { 0x0020, 0x0020, 0x0020, 0x0020,
                                             0x0020, 0x0031, 0x0032, 0x0033,
                                             0x002c, 0x0020, 0x0020, 0x0020,
                                             0x002d, 0x0034, 0x0035, 0x0036,
                                             0x0037, 0x0000 };
                                             /*     123,   -4567 */
    WCHAR buf[KTEST_BUFF_SIZE_20];
    const kal_int32 d1 = 123;  /* 0x7B */
    const kal_int32 d2 = -4567;  /* 0xFFFFEE29 */
    const kal_uint32 cmp_size = 18;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "insert blanks before Integer";

    /* initialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size * 2 );

    /* write 2 decimals with width into "buf". note that we need to add blanks
     * before the real number. */
    kal_wsprintf( buf, "%8d,%8d", d1, d2 );

    /* check whether the content of "buf" is correct. */
    result = kal_wstrncmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wsprintf10 failed1" );
    }

    for( i = cmp_size ; i < buf_size; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wsprintf10 failed2" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wsprintf11
 * Functionality:
 *     test basic functionality of kal_wsprintf.
 *     write 2 decimals to buffer, note that we may add "0" to fill the width.
 * Results:
 *     if the content of buffer is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wsprintf11( kal_uint32 argc, void *argv )
{

    const kal_uint32 buf_size = 20;
    const WCHAR wstr[KTEST_BUFF_SIZE_20] = { 0x0030, 0x0030, 0x0030, 0x0030,
                                             0x0030, 0x0031, 0x0032, 0x0033,
                                             0x002c, 0x002d, 0x0030, 0x0030,
                                             0x0030, 0x0034, 0x0035, 0x0036,
                                             0x0037, 0x0000 };
    WCHAR buf[KTEST_BUFF_SIZE_20];
    const kal_int32 d1 = 123;  /* 0x7B */
    const kal_int32 d2 = -4567;  /* 0xFFFFEE29 */
    const kal_uint32 cmp_size = 18;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "insert '0' before Integer";

    /* initialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size * 2 );

    /* write 2 decimals into "buf", use '0' to fill the width when needed. */
    kal_wsprintf( buf, "%08d,%08d", d1, d2 );

    /* check whether the content of "buf" is correct. */
    result = kal_wstrncmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wsprintf11 failed1" );
    }

    for( i = cmp_size ; i < buf_size; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wsprintf11 failed2" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wsprintf12
 * Functionality:
 *     test basic functionality of kal_wsprintf.
 *     write 2 lower hexadecimals with width into buffer, then check whether it
 *     is correct.
 * Results:
 *     if the content of buffer is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wsprintf12( kal_uint32 argc, void *argv )
{

    const kal_uint32 buf_size = 20;
    const WCHAR wstr[KTEST_BUFF_SIZE_20] = { 0x0030, 0x0078, 0x0020, 0x0020,
                                             0x0037, 0x0062, 0x002c, 0x0030,
                                             0x0078, 0x0020, 0x0020, 0x0066,
                                             0x0066, 0x0066, 0x0066, 0x0065,
                                             0x0065, 0x0032, 0x0039, 0x0000 };
    WCHAR buf[KTEST_BUFF_SIZE_20];
    const kal_int32 d1 = 123;  /* 0x7b */
    const kal_int32 d2 = -4567;  /* 0xffffee29 */
    const kal_uint32 cmp_size = 20;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "lower hexadecimal with width";

    /* initialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size * 2 );

    /* write 2 lower hexadecimals with width into "buf". */
    kal_wsprintf( buf, "0x%4x,0x%10x", d1, d2 );

    /* check whether the content of "buf" is correct. */
    result = kal_wstrncmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wsprintf12 failed1" );
    }

    for( i = cmp_size ; i < buf_size; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wsprintf12 failed2" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wsprintf13
 * Functionality:
 *     test basic functionality of kal_wsprintf.
 *     write 2 lower hexadecimals with width into buffer, and use '0' to fill
 *     width when  needed.
 * Results:
 *     if the content of buffer is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wsprintf13( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 30;
    const WCHAR wstr[KTEST_BUFF_SIZE_30] = { 0x0030, 0x0078, 0x0030, 0x0030,
                                             0x0030, 0x0030, 0x0030, 0x0030,
                                             0x0037, 0x0062, 0x002c, 0x0030,
                                             0x0078, 0x0030, 0x0066, 0x0066,
                                             0x0066, 0x0066, 0x0065, 0x0065,
                                             0x0032, 0x0039, 0x0000 };
    WCHAR buf[KTEST_BUFF_SIZE_30];
    const kal_int32 d1 = 123;  /* 0x7b */
    const kal_int32 d2 = -4567;  /* 0xffffee29 */
    const kal_uint32 cmp_size = 23;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "lower hexadecimal with width";

    /* initialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size * 2 );

    /* write 2 lower hexadecimals with width into "buf". */
    kal_wsprintf( buf, "0x%08x,0x%09x", d1, d2 );

    /* check whether the content of "buf" is correct. */
    result = kal_wstrncmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wsprintf13 failed1" );
    }

    for( i = cmp_size ; i < buf_size; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wsprintf13 failed2" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wsprintf14
 * Functionality:
 *     test basic functionality of kal_wsprintf.
 *     write 2 lower hexadecimals into buffer, then check whether it is correct.
 * Results:
 *     if the content of buffer is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wsprintf14( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 20;
    const WCHAR wstr[KTEST_BUFF_SIZE_20] = { 0x0030, 0x0078, 0x0037, 0x0062,
                                             0x002c, 0x0030, 0x0078, 0x0066,
                                             0x0066, 0x0066, 0x0066, 0x0065,
                                             0x0065, 0x0032, 0x0039, 0x0000 };
    WCHAR buf[KTEST_BUFF_SIZE_20];
    const kal_int32 d1 = 123;  /* 0x7b */
    const kal_int32 d2 = -4567;  /* 0xffffee29 */
    const kal_uint32 cmp_size = 18;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "lower hexadecimal";

    /* initialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size * 2 );

    /* write 2 lower hexadecimals into "buf". */
    kal_wsprintf( buf, "0x%x,0x%x", d1, d2 );

    /* check whether the content of "buf" is correct. */
    result = kal_wstrncmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wsprintf14 failed1" );
    }

    for( i = cmp_size ; i < buf_size; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wsprintf14 failed2" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wsprintf15
 * Functionality:
 *     test basic functionality of kal_wsprintf.
 *     write 2 upper hexadecimals with width into buffer, use '0' to fill width
 *     when needed, then check whether the content of buffer is correct.
 * Results:
 *     if the content of buffer is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wsprintf15( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 30;
    const WCHAR wstr[KTEST_BUFF_SIZE_30] = { 0x0030, 0x0078, 0x0030, 0x0030,
                                             0x0030, 0x0030, 0x0030, 0x0030,
                                             0x0037, 0x0042, 0x002c, 0x0030,
                                             0x0078, 0x0046, 0x0046, 0x0046,
                                             0x0046, 0x0045, 0x0045, 0x0032,
    	                                     0x0039, 0x0000 };
    WCHAR buf[KTEST_BUFF_SIZE_30];
    const kal_int32 d1 = 123;  /* 0x7B */
    const kal_int32 d2 = -4567;  /* 0xFFFFEE29 */
    const kal_uint32 cmp_size = 22;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "upper hexadecimal with width";

    /* initialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size * 2 );

    /* write 2 upper hexadecimals with width into "buf". note that it may add
     * '0' to fill the width when needed. */
    kal_wsprintf( buf, "0x%08X,0x%04X", d1, d2 );

    /* check whether the content of "buf" is correct. */
    result = kal_wstrncmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wsprintf15 failed1" );
    }

    for( i = cmp_size; i < buf_size; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wsprintf15 failed2" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_utl_kal_wsprintf16
 * Functionality:
 *     test basic functionality of kal_wsprintf.
 *     write 2 upper hexadecimals with width into buffer, blanks will be added
 *     when needed, then test whether the content of buffer is correct.
 * Results:
 *     if the content of buffer is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_utl_kal_wsprintf16( kal_uint32 argc, void *argv )
{
    const kal_uint32 buf_size = 30;
    const WCHAR wstr[KTEST_BUFF_SIZE_30] = { 0x0030, 0x0078, 0x0020, 0x0020,
                                             0x0020, 0x0020, 0x0020, 0x0020,
                                             0x0037, 0x0042, 0x002c, 0x0030,
                                             0x0078, 0x0046, 0x0046, 0x0046,
                                             0x0046, 0x0045, 0x0045, 0x0032,
    	                                     0x0039, 0x0000 };
    WCHAR buf[KTEST_BUFF_SIZE_30];
    const kal_int32 d1 = 123;  /* 0x7B */
    const kal_int32 d2 = -4567;  /* 0xFFFFEE29 */
    const kal_uint32 cmp_size = 22;
    kal_int32 result;
    kal_uint32 i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "upper hexadecimal fill width with blanks";

    /* initialize the content of "buf". */
    kal_mem_set( (kal_char *) buf, 0xFF, buf_size * 2 );

    /* write 2 upper hexadecimals into "buf", note that we may need to fill
     * width with blanks. */
    kal_wsprintf( buf, "0x%8X,0x%4X", d1, d2 );

    /* check whether the content of "buf" is correct. */
    result = kal_wstrncmp( buf, wstr, cmp_size );
    if( result != 0x0 )
    {
        MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                          "ktest_utl_kal_wsprintf16 failed1" );
    }

    for( i = cmp_size; i < buf_size; i++ )
    {
        if( buf[i] != 0xFFFF )
        {
            MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID,
                              "ktest_utl_kal_wsprintf16 failed2" );
        }
    }

    MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * test case table of utl module in post-schedule stage.
 * note that the ones wrapped by FIX_OSCAR_FAIL will be tested only on target,
 *           but will be ignored on OSCAR.
 *****************************************************************************/
const ktest_tc_struct ktest_tc_utl_tbl[] =
{
    {ktest_utl_kal_mem_set, 0, NULL},
    {ktest_utl_kal_mem_cpy, 0, NULL},
    {ktest_utl_kal_mem_cmp1, 0, NULL},
    {ktest_utl_kal_mem_cmp2, 0, NULL},
    {ktest_utl_kal_mem_cmp3, 0, NULL},
    {ktest_utl_kal_dchar_strlen, 0, NULL},
    {ktest_utl_kal_dchar_strcpy, 0, NULL},
    {ktest_utl_kal_dchar_strncpy1, 0, NULL},
    {ktest_utl_kal_dchar_strncpy2, 0, NULL},
    {ktest_utl_kal_dchar_strncpy3, 0, NULL},
    {ktest_utl_kal_dchar_strncpy4, 0, NULL},
    {ktest_utl_kal_dchar_strcmp1, 0, NULL},
    {ktest_utl_kal_dchar_strcmp2, 0, NULL},
    {ktest_utl_kal_dchar_strcmp3, 0, NULL},
    {ktest_utl_kal_dchar_strcmp4, 0, NULL},
    {ktest_utl_kal_dchar_strcmp5, 0, NULL},
    {ktest_utl_kal_dchar_strncmp1, 0, NULL},
    {ktest_utl_kal_dchar_strncmp2, 0, NULL},
    {ktest_utl_kal_dchar_strncmp3, 0, NULL},
    {ktest_utl_kal_dchar_strncmp4, 0, NULL},
    {ktest_utl_kal_dchar_strncmp5, 0, NULL},
    {ktest_utl_kal_dchar_strncmp6, 0, NULL},
    {ktest_utl_kal_dchar_strcat, 0, NULL},
    {ktest_utl_kal_dchar_strncat1, 0, NULL},
    {ktest_utl_kal_dchar_strncat2, 0, NULL},
    {ktest_utl_kal_dchar_strncat3, 0, NULL},
    {ktest_utl_kal_dchar_strncat4, 0, NULL},
    {ktest_utl_kal_dchar_strchr1, 0, NULL},
    {ktest_utl_kal_dchar_strchr2, 0, NULL},
    {ktest_utl_kal_dchar_strrchr1, 0, NULL},
    {ktest_utl_kal_dchar_strrchr2, 0, NULL},
    {ktest_utl_kal_dchar2char, 0, NULL},
    {ktest_utl_kal_wstrlen, 0, NULL},
    {ktest_utl_kal_wstrcmp1, 0, NULL},
    {ktest_utl_kal_wstrcmp2, 0, NULL},
    {ktest_utl_kal_wstrcmp3, 0, NULL},
    {ktest_utl_kal_wstrncmp1, 0, NULL},
    {ktest_utl_kal_wstrncmp2, 0, NULL},
    {ktest_utl_kal_wstrncmp3, 0, NULL},
    {ktest_utl_kal_wstrncmp4, 0, NULL},
    {ktest_utl_kal_wstrcpy, 0, NULL},
    {ktest_utl_kal_wstrncpy1, 0, NULL},
    {ktest_utl_kal_wstrncpy2, 0, NULL},
    {ktest_utl_kal_wstrcat, 0, NULL},
    {ktest_utl_kal_wstrncat1, 0, NULL},
    {ktest_utl_kal_wstrncat2, 0, NULL},
    {ktest_utl_kal_wstrchr1, 0, NULL},
    {ktest_utl_kal_wstrchr2, 0, NULL},
    {ktest_utl_kal_wstrrchr1, 0, NULL},
    {ktest_utl_kal_wstrrchr2, 0, NULL},
    {ktest_utl_kal_wsprintf1, 0, NULL},
    {ktest_utl_kal_wsprintf2, 0, NULL},
    {ktest_utl_kal_wsprintf3, 0, NULL},
    {ktest_utl_kal_wsprintf4, 0, NULL},
    {ktest_utl_kal_wsprintf5, 0, NULL},
    {ktest_utl_kal_wsprintf6, 0, NULL},
    {ktest_utl_kal_wsprintf7, 0, NULL},
    {ktest_utl_kal_wsprintf8, 0, NULL},
    {ktest_utl_kal_wsprintf9, 0, NULL},
    {ktest_utl_kal_wsprintf10, 0, NULL},
    {ktest_utl_kal_wsprintf11, 0, NULL},
    {ktest_utl_kal_wsprintf12, 0, NULL},
    {ktest_utl_kal_wsprintf13, 0, NULL},
    {ktest_utl_kal_wsprintf14, 0, NULL},
    {ktest_utl_kal_wsprintf15, 0, NULL},
    {ktest_utl_kal_wsprintf16, 0, NULL},
};

/******************************************************************************
 * test case table of utl module in pre-schedule stage.
 * note that the ones wrapped with FIX_OSCAR_FAIL will only be tested on target,
 *           but will be ignored
 *****************************************************************************/
const ktest_tc_struct ktest_pre_tc_utl_tbl[] =
{
	{ktest_fake_test, 0, NULL},
};

/******************************************************************************
 * Name:
 *     ktest_tc_utl_num
 * Functionality:
 *     caculate the total number of test cases of utl module in post-schedule
 *     stage.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of test cases of utl module in post-schedule stage.
 *****************************************************************************/
kal_uint32 ktest_tc_utl_num( void )
{
	return sizeof( ktest_tc_utl_tbl )/ sizeof(ktest_tc_struct);
}

/******************************************************************************
 * Name:
 *     ktest_pre_tc_utl_num
 * Functionality:
 *     caculate the total number of test cases of utl module in pre-schedule
 *     stage.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of test cases of utl module in pre-schedule stage.
 *****************************************************************************/
kal_uint32 ktest_pre_tc_utl_num( void )
{
	return sizeof( ktest_pre_tc_utl_tbl ) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * Name:
 *     ktest_utl_init
 * Functionality:
 *     this is the initialization function of utl module.
 * Parameters:
 *     mod: id of utl module.
 * Returns:
 *     void.
 * Note:
 *     this function should be called in ktest_testcase_register to register
 *     utl module into KTEST.
 *****************************************************************************/
void ktest_utl_init( kal_uint32 mod )
{
	tc_all_tbls[mod] = ktest_tc_utl_tbl;
	pre_tc_all_tbls[mod] = ktest_pre_tc_utl_tbl;

	tc_modules_num[mod] = ktest_tc_utl_num();
	pre_tc_modules_num[mod] = ktest_pre_tc_utl_num();
}

#endif /*__KTEST__*/
