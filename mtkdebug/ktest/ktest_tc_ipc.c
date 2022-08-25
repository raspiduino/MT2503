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
 *     ktest_tc_ipc.c
 *
 * Project:
 * --------
 *     Maui_Software
 *
 * Description:
 * ------------
 *     The file implements MediaTek KAL (Kernel Abstraction Layer) auto test
 *     task functions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/

/* this file is valid only when __KTEST__ has been defined */
#ifdef __KTEST__
 
#include "ktest_common.h"
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "stack_ltlcom.h"
#include "stack_config.h"
#include "stack_types.h"
#include "task_config.h"
#include "lcd_ip_cqueue.h"

/******************************************************************************
 * external APIs and variables that will be used in this file.
 *****************************************************************************/
extern kal_uint32 kal_get_mytask_priority( void );
extern void *kal_sys_mem_alloc( kal_uint32 size );
extern int rand( void );

/******************************************************************************
 * macros
 *****************************************************************************/
#define tick_diff(t1, t2) ((int)( (t1) - (t2) ))

#define GPT_TICKSPERSEC 100
typedef void (*gpt_timer_handler)( void * );
#define MY_REPORT_RETURN3( code, tcname, fmt ) \
    ktest_report_reset3( code, tcname, fmt );\
    return code;

/******************************************************************************
 * Name:
 *     busyloop_delay_count
 * Functionality:
 *     delay some time in a busy loop.
 * Parameters:
 *     count: how many loops do you want to delay.
 * Returns:
 *     void.
 * Note:
 *     this function is used to support test cases.
 *     and it can modify the value of __useless.
 *****************************************************************************/
static volatile int __useless;
static void busyloop_delay_count( int count )
{
    int i;
    for( i = 0; i < count; i++ )
    {
        __useless = i;
    }
}

/******************************************************************************
 * Name:
 *     busyloop_delay_base
 * Functionality:
 *     caculate the delay_base ( how many loops in a million second ).
 * Parameters:
 *     void.
 * Returns:
 *     the value of that how many loops will be executed in a million second.
 * Note:
 *     this function is used to support test cases.
 *     and it can modify the value of __useless.
 *****************************************************************************/
static int delay_base;
static int busyloop_delay_base( void )
{
    int i = 0;
#define DELAY_MAX ( 1024 * 1024 * 4 )
    kal_uint32 start, now;
    kal_get_time( &start );
    for( i = 0; i < DELAY_MAX; i++ )
    {
        __useless = i;
    }
    kal_get_time( &now );

    delay_base = DELAY_MAX / (int) ( now - start );
    return delay_base;
}

/******************************************************************************
 * Name:
 *     busyloop_delay
 * Functionality:
 *     delay some time in a busy loop.
 * Parameters:
 *     ticks: how many ticks do you want to delay.
 * Returns:
 *     void.
 * Notes:
 *     this function is used to support test cases.
 *     and it can modify the value of __useless indirectly.
 *****************************************************************************/
static void busyloop_delay( kal_int32 ticks )
{
    busyloop_delay_count( ticks * delay_base );
}

/******************************************************************************
 * Name:
 *     rand2
 * Functionality:
 *     randomize a value.
 * Parameters:
 *     lower: the lower limitation of the generated value.
 *     upper: the upper limitation of the generated value.
 * Returns:
 *     the generated value.
 * Notes:
 *     this function is used to support test cases.
 *     and the generated value is in cope of [lower, upper)
 *****************************************************************************/
int rand2( int lower, int upper )
{
	int range = upper - lower;

	if( range <= 0 )
	{
		return lower;
	}

	return lower + rand() % range;
}

/******************************************************************************
 * a structure that contains 2 parts:
 *     part1: the header of a local_para_struct
 *     part2: a integer value.
 *****************************************************************************/
struct local_para_test_t
{
    LOCAL_PARA_HDR
    int a;
};

/******************************************************************************
 * Name:
 *     ktest_ipc_allocate_ilm1
 * Functionality:
 *     test the basic functionality of allocate_ilm/free_ilm.
 * Results:
 *     if the functions executed correctly, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_allocate_ilm1( kal_uint32 argc, void *argv )
{
	ilm_struct *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	p = allocate_ilm( MOD_IDLE );
	if( p == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "allocate_ilm returns NULL" );
	}
	p->msg_id = (msg_type) 100;
	free_ilm( p );

    /* allocate_ilm/free_ilm executed successfully. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_allocate_ilm2
 * Functionality:
 *     test the basic functionality of allocate_ilm/cancel_ilm.
 * Results:
 *     if the functions executed correctly, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_allocate_ilm2( kal_uint32 argc, void *argv )
{
	ilm_struct *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	p = allocate_ilm( MOD_IDLE );
	if( p == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "allocate_ilm returns NULL" );
	}
	cancel_ilm( MOD_IDLE );

    /* allocate_ilm/cancel_ilm executed successfully. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_allocate_ilm3
 * Functionality:
 *     test whether allocate_ilm can detect double-allocation.
 * Results:
 *     if KAL_ERROR_ITC_ILM_MULTIALLOC occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_allocate_ilm3( kal_uint32 argc, void *argv )
{
	ilm_struct *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ITC_ILM_MULTIALLOC;

	p = allocate_ilm( MOD_IDLE );
	if( p == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "the first allocate_ilm returns NULL" );
	}
	p->msg_id = (msg_type) 100;

    /* below is a double-allocation, and a fatal error is expected. */
	p = allocate_ilm( MOD_IDLE );

    /* no fatal error occurs, this is not what we expected, report FAIL. */
	MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_allocate_ilm4
 * Functionality:
 *     test whether allocate_ilm can detect double-allocation with a free_ilm
 *     between them.
 * Results:
 *     if KAL_ERROR_ITC_ILM_MULTIALLOC occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_allocate_ilm4( kal_uint32 argc, void *argv )
{
	ilm_struct *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ITC_ILM_MULTIALLOC;

	p = allocate_ilm( MOD_IDLE );
	if( p == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "the first allocate_ilm returns NULL" );
	}
	p->msg_id = (msg_type) 100;
	free_ilm( p );

    /* below is a double-allocation, and a fatal error is expected. */
	p = allocate_ilm( MOD_IDLE );

    /* no fatal error occurs, and this is not what we expected, report FAIL. */
	MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_allocate_ilm5
 * Functionality:
 *     test the execution sequence of allocate_ilm, cancel_ilm, allocate_ilm.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_allocate_ilm5( kal_uint32 argc, void *argv )
{
	ilm_struct *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	p = allocate_ilm( MOD_IDLE );
	cancel_ilm( MOD_IDLE );

    /* since cancel_ilm can clear the allocation bit mask, so we can use
     * allocate_ilm again, and no fatal error occurs. */
	p = allocate_ilm( MOD_IDLE );

    /* no error occurs, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_construct_local_para
 * Functionality:
 *     test the basic functionality of construct_local_para/free_local_para.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_construct_local_para( kal_uint32 argc, void *argv )
{
	struct local_para_test_t *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	p = construct_local_para( sizeof( struct local_para_test_t ), TD_RESET );

    /* since we used TD_RESET as a parameter when calling construct_local_para,
     * so the integer value "a" in local_para_test_t will be 0. */
	if( p->a != 0 )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "p->a != 0" );
	}
	p->a = 0xFE3D124A;
	free_local_para( (local_para_struct *) p );

    /* no error occurs, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_hold_local_para
 * Functionality:
 *     test multiple hold_local_para followed by multiple free_local_para.
 *     note that free_local_para is called one more time that hold_local_para.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_hold_local_para( kal_uint32 argc, void *argv )
{
	struct local_para_test_t *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	p = construct_local_para( sizeof( struct local_para_test_t ), TD_RESET );

    /* since we used TD_RESET as a parameter when calling construct_local_para,
     * so the integer value "a" in local_para_test_t will be 0. */
    if( p->a != 0 )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "p->a != 0" );
	}
	p->a = 0xFE3D124A;

    /* hold_local_para is called 2 times */
	hold_local_para( (local_para_struct *) p );
	hold_local_para( (local_para_struct *) p );

    /* free_local_para is called one more time than hold_local_para, so no
     * double-free error occurs here. */
	free_local_para( (local_para_struct *) p );
	free_local_para( (local_para_struct *) p );
	free_local_para( (local_para_struct *) p );

    /* no error occurs, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_hold_local_para2
 * Functionality:
 *     test whether free_local_para can detect a double-free error.
 * Results:
 *     if KAL_ERROR_ITC_ILM_DOUBLE_FREE occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_hold_local_para2( kal_uint32 argc, void *argv )
{
	struct local_para_test_t *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	p = construct_local_para( sizeof( struct local_para_test_t ), TD_RESET );

    /* since we used TD_RESET as a parameter when calling construct_local_para,
     * so the integer value "a" in local_para_test_t will be 0. */
	if( p->a != 0 )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "p->a != 0" );
	}
	p->a = 0xFE3D124A;

    /* hold_local_para 2 times and free_local_para 3 times,
     * after this, the ref_count of local para will be 0. */
	hold_local_para( (local_para_struct *) p );
	hold_local_para( (local_para_struct *) p );
	free_local_para( (local_para_struct *) p );
	free_local_para( (local_para_struct *) p );
	free_local_para( (local_para_struct *) p );

	/* below is a double-free fatal error, and a fatal error is expected here.
	 */
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ITC_ILM_DOUBLE_FREE;
	free_local_para( (local_para_struct *) p );

    /* no error occurs, this is not what we expected, report FAIL. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "We should detect extra free" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_get_local_para_ptr
 * Functionality:
 *     test the basic functionality of get_local_para_ptr
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_get_local_para_ptr( kal_uint32 argc, void *argv )
{
	struct local_para_test_t *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	p = construct_local_para( sizeof( struct local_para_test_t ), TD_RESET );

    /* since we used TD_RESET as a parameter when calling construct_local_para,
     * so the integer value "a" in local_para_test_t will be 0. */
	if( p->a != 0 )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "p->a != 0" );
	}
	p->a = 0xFE3D124A;

    /* test the basic functionality of get_local_para */
	{
	    void *dp;
	    kal_uint16 dlen;
	    dp = get_local_para_ptr( (local_para_struct *) p, &dlen );
	    if( dp == NULL || dlen < sizeof( struct local_para_test_t ) )
        {
	        ktest_report( KTEST_FAIL, KTEST_TCID,
                          "dp(%p) == NULL || dlen(%u) < sizeof(local_para_test_t)(%u)",
                          dp, dlen, sizeof( struct local_para_test_t ) );
	        return KTEST_FAIL;
	    }
	}

    /* no error occurs in get_local_para_ptr, free the local_para_struct
     * and report PASS. */
	free_local_para( (local_para_struct *) p );
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_construct_peer_buff
 * Functionality:
 *     test the basic functionality of construct_peer_buff/free_peer_buff.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_construct_peer_buff( kal_uint32 argc, void *argv )
{
	peer_buff_struct *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	p = construct_peer_buff( 100, 16, 16, 0 );

    /* if can't construct a peer_buff, report FAIL. */
	if( p == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "p == NULL" );
	}

    /* no error occurs, free the peer_buff and report PASS. */
	free_peer_buff( p );
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
}


/******************************************************************************
 * Name:
 *     ktest_ipc_hold_peer_buff
 * Functionality:
 *     test hold_peer_buff multiple times followed by free_peer_buff multiple
 *     times ( one more than hold_peer_buff ).
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_hold_peer_buff( kal_uint32 argc, void *argv )
{
	peer_buff_struct *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	p = construct_peer_buff( 100, 16, 16, 0 );
	if( p == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "construct_peer_buff returns NULL" );
	}

    /* call hold_peer_buff 2 times*/
	hold_peer_buff( p );
	hold_peer_buff( p );

    /* call free_peer_buff 3 times, so the ref_count will be 0,
     *and no double-free fatal error occurs. */
	free_peer_buff( p );
	free_peer_buff( p );
	free_peer_buff( p );

    /* no error occurs, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_hold_peer_buff2
 * Functionality:
 *     test whether free_peer_buff can detect double-free fatal error.
 * Results:
 *     if KAL_ERROR_ITC_ILM_DOUBLE_FREE occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_hold_peer_buff2( kal_uint32 argc, void *argv )
{
	peer_buff_struct *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	p = construct_peer_buff( 100, 16, 16, 0 );
	if( p == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "construct_peer_buff returns NULL" );
	}

    /* hold_peer_buff 2 times and free_peer_buff 3 times, then the ref_count
     * will be 0, and no double-free fatal error occurs till now. */
	hold_peer_buff( p );
	hold_peer_buff( p );
	free_peer_buff( p );
	free_peer_buff( p );
	free_peer_buff( p );

	/* one more free_peer_buff, a double-free fatal error is expected here. */
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ITC_ILM_DOUBLE_FREE;
	free_peer_buff( p );

    /* no error occurs, this is not what we expected, report FAIL. */
	MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "We should detect extra free" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_get_pdu_ptr
 * Functionality:
 *     test the basic functionality of ktest_ipc_get_pdu_ptr
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_get_pdu_ptr( kal_uint32 argc, void *argv )
{
	peer_buff_struct *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	p = construct_peer_buff( 100, 16, 16, 0 );
	if( p == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "construct_peer_buff returns NULL" );
	}

    /* test the basic functionality of ktest_ipc_get_pdu_ptr */
	{
	    void *dp;
	    kal_uint16 dlen;

	    dp = get_pdu_ptr( p, &dlen );

        /* if can't get pdu_ptr correctly, report FAIL. */
	    if( dp == NULL || dlen != 100 )
        {
	        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                               "dp == NULL || dlen != 100" );
	    }
	    strcpy( (char *) dp, "Hello world.\n" );
	}

    /* no error occurs, free peer buffer and report PASS. */
    free_peer_buff( p );
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_prepend_to_peer_buff
 * Functionality:
 *     test the basic functionality of prepend_to_peer_buff and
       remove_hdr_of_peer_buff.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_prepend_to_peer_buff( kal_uint32 argc, void *argv )
{
	peer_buff_struct *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	p = construct_peer_buff( 100, 16, 16, 0 );
	if( p == NULL ) {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "construct_peer_buff returns NULL" );
	}

    /* test the basic functionality of
     * prepend_to_peer_buff and remove_hdr_of_peer_buff */
	{
	    void *dp, *dp2;
	    kal_uint16 dlen, dlen2;

	    dp = get_pdu_ptr( p, &dlen );

        /* if can't get pdu_ptr correctly, report FAIL. */
	    if( dp == NULL || dlen != 100 )
        {
	        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                               "dp == NULL || dlen != 100" );
	    }

        /* prepend 8 characters to peer buffer */
	    prepend_to_peer_buff( p, "12345678", 8 );
	    dp2 = get_pdu_ptr( p, &dlen2 );
	    if( ( (char *) dp2 + 8 ) != dp || ( dlen2 - 8 ) != dlen )
        {
	        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                               "(dp2 + 8) != dp || (dlen2 - 8) != dlen" );
	    }

        /* remove 8 characters from the hdr of peer_buff */
	    remove_hdr_of_peer_buff( p, 8 );
	    dp2 = get_pdu_ptr( p, &dlen2 );
	    if( dp2 != dp || dlen2 != dlen )
        {
	        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                               "dp2 != dp || dlen2 != dlen" );
	    }
	}

    /* no error occurs, free peer buffer and report PASS. */
    free_peer_buff( p );
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_prepend_to_peer_buff2
 * Functionality:
 *     test prepend_to_peer_buff when its header buffer room is not enough.
 * Results:
 *     if RPS_COMMON_ERROR_INSUFF_MEM occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_prepend_to_peer_buff2( kal_uint32 argc, void *argv )
{
	peer_buff_struct *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0x10; /* RPS_COMMON_ERROR_INSUFF_MEM */

	p = construct_peer_buff( 100, 16, 16, 0 );
	if( p == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "construct_peer_buff returns NULL" );
	}

    /* test prepend_to_peer_buff when its header buffer room is not enough */
	{
	    void *dp;
        kal_uint16 dlen;

	    dp = get_pdu_ptr( p, &dlen );

        /* if can't get pdu_ptr correctly, report FAIL. */
	    if( dp == NULL || dlen != 100 )
        {
	        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                               "dp == NULL || dlen != 100" );
	    }

        /* prepend 16 characters to peer_buff, and header of peer_buff will have
         * no room now. */
	    prepend_to_peer_buff( p, "1234567890ABCDEF", 16 );

        /* prepend another character to peer_buff, since the header has no room
         * now, so a fatal error is expected here. */
	    prepend_to_peer_buff( p, "a", 1 );
	}

    /* no error occurs, this is not what we expected, report FAIL. */
	MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "exception should happened" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_append_to_peer_buff
 * Functionality:
 *     test the basic functionality of append_to_peer_buff and
 *     remove_tail_of_peer_buff.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_append_to_peer_buff( kal_uint32 argc, void *argv )
{
	peer_buff_struct *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	p = construct_peer_buff( 100, 16, 16, 0 );
	if( p == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "construct_peer_buff returns NULL" );
	}

    /* test append_to_peer_buff and remove_tail_of_peer_buff */
	{
	    void *dp, *dp2;
	    kal_uint16 dlen, dlen2;

	    dp = get_pdu_ptr( p, &dlen );
	    if( dp == NULL || dlen != 100 )
        {
	        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                               "dp == NULL || dlen != 100" );
	    }

        /* append 8 characters to peer_buff's tail,
         * if not success, report FAIL. */
	    append_to_peer_buff( p, "12345678", 8 );
	    dp2 = get_pdu_ptr( p, &dlen2 );
	    if( dp2 != dp || ( dlen2 - 8 ) != dlen )
        {
	        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                               "dp2 != dp || (dlen2 - 8) != dlen" );
	    }

        /* remove 8 characters from peer_buff's tail,
         * if not success, report FAIL. */
	    remove_tail_of_peer_buff( p, 8 );
	    dp2 = get_pdu_ptr( p, &dlen2 );
	    if( dp2 != dp || dlen2 != dlen )
        {
	        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                               "dp2 != dp || dlen2 != dlen" );
	    }
	}

    /* no error occurs, free peer_buff and report PASS. */
    free_peer_buff( p );
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_append_to_peer_buff2
 * Functionality:
 *     test append_to_peer_buff with insufficient room in peer_buff's tail.
 * Results:
 *     if RPS_COMMON_ERROR_INSUFF_MEM occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_append_to_peer_buff2( kal_uint32 argc, void *argv )
{
	peer_buff_struct *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0x10; /* RPS_COMMON_ERROR_INSUFF_MEM */

	p = construct_peer_buff( 100, 16, 16, 0 );
	if( p == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "construct_peer_buff returns NULL" );
	}

    /* test append_to_peer_buff with insufficient room in peer_buff's tail */
	{
	    void *dp;
	    kal_uint16 dlen;

	    dp = get_pdu_ptr( p, &dlen );
	    if( dp == NULL || dlen != 100 )
        {
	        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                               "dp == NULL || dlen != 100" );
	    }

        /* append 16 characters to peer_buff's tail, then peer_buff's tail will
         * have no room left. */
	    append_to_peer_buff( p, "1234567890ABCDEF", 16 );

        /* append another character to peer_buff's tail, and a fatal error is
         * expected here. */
	    append_to_peer_buff( p, "a", 1 );
	}

    /* no error occurs, this is not what we expected, report FAIL. */
	MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "exception should happened" );
}


/******************************************************************************
 * Name:
 *     ktest_ipc_update_peer_buff_hdr
 * Functionality:
 *     test update_peer_buff_hdr with the total size unchanged.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_update_peer_buff_hdr( kal_uint32 argc, void *argv )
{
	peer_buff_struct *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0x10;

	p = construct_peer_buff( 100, 16, 16, 0 );
	if( p == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "construct_peer_buff returns NULL" );
	}

    /* test update_peer_buff with the total size unchanged */
	{
	    void *dp;
	    kal_uint16 dlen;

        /* set new size of peer_buff's header, pdu and tail.
         * the new size is: header: 0, pdu: 132, tail: 0. */
	    update_peer_buff_hdr( p, 0, 132, 0 );
	    dp = get_pdu_ptr( p, &dlen );
	    if( dp == NULL || dlen != 132 )
        {
	        ktest_report( KTEST_FAIL, KTEST_TCID,
                          "dp(%p) == NULL || dlen(%d) != 132", dp, dlen );
	        ktest_reset_target();
	    }
	}

    /* no error occurs, free peer_buff and report PASS. */
    free_peer_buff( p );
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_update_peer_buff_hdrE1
 * Functionality:
 *     test update_peer_buff_hdr with the total size enlarged.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 * Note:
 *     this test case is not completed yet, and we want to detect the change of
 *     peer_buff's total size.
 *****************************************************************************/
kal_int32 ktest_ipc_update_peer_buff_hdrE1( kal_uint32 argc, void *argv )
{
	peer_buff_struct *p;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0x10;

	p = construct_peer_buff( 100, 16, 16, 0 );
	if( p == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "construct_peer_buff returns NULL" );
	}

    /* test update_peer_buff_hdr with total size enlarged */
	{
	    void *dp;
	    kal_uint16 dlen;

        /* enlarge peer_buff's size by 1 byte */
	    update_peer_buff_hdr( p, 0, 132 + 1, 0 );
	    dp = get_pdu_ptr( p, &dlen );
        if( dp == NULL || dlen != 132 + 1 )
        {
	        ktest_report( KTEST_FAIL, KTEST_TCID,
                          "dp(%p) == NULL || dlen(%d) != 132 + 1", dp, dlen );
	        ktest_reset_target();
	    }
	}

    /* no error occurs, free peer_buff and report PASS. */
    free_peer_buff( p );
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID,
                       "Suggest to detect total peer buffer size changed" );
}

/******************************************************************************
 * for MAUI KAL USER MANUAL 5.4
 *     Task Communication APIs for special purposes ( NOT encourage ).
 *****************************************************************************/
 #define TESTQ_RECORDSIZE 22
 #define TESTQ_SLOTS 16

/******************************************************************************
 * Name:
 *     ktest_ipc_create_msgq
 * Functionality:
 *     test the basic functionality of kal_create_msg_q and kal_get_queue_info.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_create_msgq( kal_uint32 argc, void *argv )
{
	kal_msgqid msgq;
    kal_msgq_info msgq_info;
    kal_bool r;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	msgq = kal_create_msg_q( "testmsgq", TESTQ_RECORDSIZE, TESTQ_SLOTS );
	if( msgq == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

	r = kal_get_queue_info( msgq, &msgq_info );
	if( r != KAL_TRUE || msgq_info.pending_msgs != 0
        || msgq_info.max_msgs != TESTQ_SLOTS )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_get_queue_info failed: ret=%d, pending=%d, max=%d",
                      r, msgq_info.pending_msgs, msgq_info.max_msgs );
	    return KTEST_FAIL;
	}

    /* no error occurs, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_enqueue_msgq1
 * Functionality:
 *     test kal_enque_msg: insert messages to a not-full queue in the pattern
 *                         of KAL_NO_WAIT.
 * Results:
 *     if no error occrus, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_enqueue_msgq1( kal_uint32 argc, void *argv )
{
	kal_msgqid msgq;
	kal_msgq_info msgq_info;
    kal_status r;
    int i;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	msgq = kal_create_msg_q( "testmsgq", TESTQ_RECORDSIZE, TESTQ_SLOTS );
	if( msgq == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

    /* insert messages to the queue until it is full */
	for( i = 0; i < TESTQ_SLOTS; i++ )
    {
	    char buf[TESTQ_RECORDSIZE];
	    int j;

	    /* generate a message string */
	    for( j = 0; j < TESTQ_RECORDSIZE - 1; j++ )
        {
	        buf[j] = '0' + i + j % 32;
	    }
	    buf[j] = 0;

        /* insert this message into the queue, use KAL_NO_WAIT. */
    	r = kal_enque_msg( msgq, buf, TESTQ_RECORDSIZE, KAL_NO_WAIT, KAL_FALSE );
    	if( r != KAL_SUCCESS )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_enque_msg failed: ret = %d", r );
    	    return KTEST_FAIL;
    	}

        /* check whether the queue's information is correct */
    	r = kal_get_queue_info( msgq, &msgq_info );
    	if( r != KAL_TRUE || msgq_info.pending_msgs != (i + 1) )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_get_queue_info failed: ret = %d, pending = %d",
                          r, msgq_info.pending_msgs );
    	    return KTEST_FAIL;
    	}
    }

    /* no error occurs, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_enqueue_msgq2
 * Functionality:
 *     test kal_enque_msg: insert messages to a not-full queue in the pattern
 *                         of KAL_INFINITE_WAIT.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_enqueue_msgq2( kal_uint32 argc, void *argv )
{
	kal_msgqid msgq;
	kal_msgq_info msgq_info;
    kal_status r;
    int i;

	KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "insert messages to a not-full queue with KAL_INFINITE_WAIT";
    KTEST_EXPECT_ERR_CODE = 0;

	msgq = kal_create_msg_q( "testmsgq", TESTQ_RECORDSIZE, TESTQ_SLOTS );
	if( msgq == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

    /* insert messages into the queue until it is full */
	for( i = 0; i < TESTQ_SLOTS; i++ )
    {
	    char buf[TESTQ_RECORDSIZE];
	    int j;

	    /* generate a message string */
	    for( j = 0; j < TESTQ_RECORDSIZE - 1; j++ )
        {
	        buf[j] = '0' + i + j % 32;
	    }
	    buf[j] = 0;

        /* insert this message into the queue, use KAL_INFINITE_WAIT. */
    	r = kal_enque_msg( msgq, buf, TESTQ_RECORDSIZE, KAL_INFINITE_WAIT, KAL_FALSE );
    	if( r != KAL_SUCCESS )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID, "kal_enque_msg failed: ret=%d", r );
    	    return KTEST_FAIL;
    	}

        /* check whether the queue's information is correct */
    	r = kal_get_queue_info( msgq, &msgq_info );
    	if( r != KAL_TRUE || msgq_info.pending_msgs != ( i+1 ) )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_get_queue_info failed: ret=%d, pending=%d",
                          r, msgq_info.pending_msgs );
    	}
    }

    /* no error occurs, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_enqueue_msgq3
 * Functionality:
 *     test kal_enque_msg: insert messages to a full queue in the pattern of
 *                         KAL_NO_WAIT.
 * Results:
 *     if kal_enqueue_msg returns KAL_Q_FULL, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_enqueue_msgq3( kal_uint32 argc, void *argv )
{
	kal_msgqid msgq;
    kal_status r;
    int i;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	msgq = kal_create_msg_q( "testmsgq", TESTQ_RECORDSIZE, TESTQ_SLOTS );
	if( msgq == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

    /* insert messages to a queue until it is full */
	for( i = 0; i < TESTQ_SLOTS; i++ )
    {
    	r = kal_enque_msg( msgq, "0123456789ABCDEF", TESTQ_RECORDSIZE,
                           KAL_NO_WAIT, KAL_FALSE );
    	if( r != KAL_SUCCESS )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_enque_msg failed: ret = %d", r );
    	}
    }

    /* the queue is full now, and the insertion below will return KAL_Q_FULL */
    for( i = 0; i < 4; i++ )
    {
        r = kal_enque_msg( msgq, "", TESTQ_RECORDSIZE, KAL_NO_WAIT, KAL_FALSE );

        /* if the return value is not KAL_Q_FULL, then this is not what we
         * expected, just report FAIL.*/
        if( r != KAL_Q_FULL )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_enque_msg(KAL_NO_WAIT) failed: ret=%d", r );
        }
    }

    /* kal_enqueue_msg returns KAL_Q_FULL as we expected, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_enqueue_msgq3a
 * Functionality:
 *     test kal_enque_msg: insert messages to a full queue in the pattern of
 *                         KAL_INFINITE_WAIT.
 * Results:
 *     if suspension occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_enqueue_msgq3a( kal_uint32 argc, void *argv )
{
	kal_msgqid msgq;
    kal_status r;
    int i;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	msgq = kal_create_msg_q( "testmsgq", TESTQ_RECORDSIZE, TESTQ_SLOTS );
	if( msgq == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

    /* insert messages to the queue until it is full */
	for( i = 0; i < TESTQ_SLOTS; i++ )
    {
    	r = kal_enque_msg( msgq, "0123456789ABCDEF", TESTQ_RECORDSIZE,
                           KAL_NO_WAIT, KAL_FALSE );
    	if( r != KAL_SUCCESS )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_enque_msg failed: ret = %d", r );
    	}
    }

    /* start a GPT timer to check suspension caused by kal_enque_msg below,
     * if suspension occurs, report PASS. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* insert an extra message to a full queue in the pattern of
     * KAL_INFINITE_WAIT, and a suspension is expected here. */
    kal_enque_msg( msgq, "", TESTQ_RECORDSIZE, KAL_INFINITE_WAIT, KAL_FALSE );

    /* if no suspension occurs, report FAIL. */
	MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_enque_msg shold not return" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_enqueue_msgq4
 * Functionality:
 *     test kal_enque_msg to a full queue from head in the pattern of
 *     KAL_NO_WAIT.
 * Results:
 *     if returns KAL_Q_FULL, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_enqueue_msgq4( kal_uint32 argc, void *argv )
{
	kal_msgqid msgq;
    kal_status r;
    int i;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	msgq = kal_create_msg_q( "testmsgq", TESTQ_RECORDSIZE, TESTQ_SLOTS );
	if( msgq == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

    /* insert to the queue until it is full */
	for( i = 0; i < TESTQ_SLOTS; i++ )
    {
    	r = kal_enque_msg( msgq, "0123456789ABCDEF", TESTQ_RECORDSIZE,
                           KAL_NO_WAIT, KAL_TRUE );
    	if( r != KAL_SUCCESS )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_enque_msg failed: ret = %d", r );
    	}
    }

    /* the queue is full now, and insertion below will return KAL_Q_FULL. */
    for( i = 0; i < 4; i++ )
    {
        r = kal_enque_msg( msgq, "", TESTQ_RECORDSIZE, KAL_NO_WAIT, KAL_TRUE );

        /* if the return value is not KAL_Q_FULL, then this is not what we
         * expected, just report FAIL. */
        if( r != KAL_Q_FULL )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_enque_msg(KAL_NO_WAIT) failed: ret=%d", r );
        }
    }

    /* kal_enque_msg returns KAL_Q_FULL as we expected, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_enqueue_msgq4a
 * Functionality:
 *     test kal_enque_msg: insert messages to a full queue from head in the
 *                         pattern of KAL_INFINITE_WAIT.
 * Results:
 *     if suspension occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_enqueue_msgq4a( kal_uint32 argc, void *argv )
{
	kal_msgqid msgq;
    kal_status r;
    int i;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	msgq = kal_create_msg_q( "testmsgq", TESTQ_RECORDSIZE, TESTQ_SLOTS );
	if( msgq == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

    /* insert messages into the queue from head until it is full */
	for( i = 0; i < TESTQ_SLOTS; i++ )
    {
    	r = kal_enque_msg( msgq, "0123456789ABCDEF", TESTQ_RECORDSIZE,
                           KAL_NO_WAIT, KAL_TRUE );
    	if( r != KAL_SUCCESS )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_enque_msg failed: ret = %d", r );
    	}
    }

    /* start a GPT timer to check suspension caused by kal_enque_msg below,
     * if suspension occurs, report PASS. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* insert an extra message to a full queue in the pattern of
     * KAL_INFINITE_WAIT, and a suspension is expected here. */
    kal_enque_msg( msgq, "", TESTQ_RECORDSIZE, KAL_INFINITE_WAIT, KAL_TRUE );

    /* no suspension occurs, this is not what we expected, report FAIL. */
	MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
	                   "kal_enque_msg should not return" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_dequeue_msgq1
 * Functionality:
 *     test kal_deque_msg: dequeue a message from a non-empty queue whose
 *                         messages are inserted from its tail.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_dequeue_msgq1( kal_uint32 argc, void *argv )
{
	kal_msgqid msgq;
	kal_msgq_info msgq_info;
    kal_status r;
    int i;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	msgq = kal_create_msg_q( "testmsgq", TESTQ_RECORDSIZE, TESTQ_SLOTS );
	if( msgq == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

    /* insert messages into the queue until it is full */
	for( i = 0; i < TESTQ_SLOTS; i++ )
    {
	    char buf[TESTQ_RECORDSIZE];
	    int j;

        /* generate a message string */
	    for( j = 0; j < TESTQ_RECORDSIZE - 1; j++ )
        {
	        buf[j] = '0' + i;
	    }
	    buf[j] = 0;

    	r = kal_enque_msg( msgq, buf, TESTQ_RECORDSIZE, KAL_NO_WAIT,
                           KAL_FALSE );
    	if( r != KAL_SUCCESS )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_enque_msg failed: ret = %d", r );
    	    ktest_reset_target();
    	    return KTEST_FAIL;
    	}
    }

    /* the queue is full now, then we will test kal_deque_msg's functionality */
    for( i = 0; i < TESTQ_SLOTS; i++ )
    {
	    char buf[TESTQ_RECORDSIZE];
        kal_uint16 mlen;
	    int j;

        /* test kal_deque_msg's functionality,
         * if any error occurs, report FAIL. */
    	r = kal_deque_msg( msgq, buf, &mlen, KAL_NO_WAIT );
    	if( r != KAL_SUCCESS || mlen < TESTQ_RECORDSIZE )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_deque_msg failed: ret = %d, mlen = %d",
                          r, mlen );
    	    ktest_reset_target();
    	    return KTEST_FAIL;
    	}

        /* test the content of the message,
         * if it is not correct, report FAIL. */
    	for( j = 0; j < TESTQ_RECORDSIZE - 1; j++ )
        {
	        if( buf[j] != '0' + i )
            {
	            MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "queue content corruption" );
	        }
	    }
	    if( buf[j] != 0 )
        {
	        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "queue content corruption" );
	    }

        /* test the information about the queue after dequeue completed,
         * if it's not correct, report FAIL. */
	    r = kal_get_queue_info( msgq, &msgq_info );
    	if( r != KAL_TRUE
            || msgq_info.pending_msgs != (TESTQ_SLOTS - (i + 1)) )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_get_queue_info failed: ret=%d, pending=%d", r,
                          msgq_info.pending_msgs );
    	    ktest_reset_target();
    	    return KTEST_FAIL;
    	}
    }

    /* no error occurs, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_dequeue_msgq1a
 * Functionality:
 *     test kal_dequeue_msgq: dequeue messages from a non-empty queue whose
 *                            messages are inserted from its head.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_dequeue_msgq1a( kal_uint32 argc, void *argv )
{
	kal_msgqid msgq;
	kal_msgq_info msgq_info;
    kal_status r;
    int i;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	msgq = kal_create_msg_q( "testmsgq", TESTQ_RECORDSIZE, TESTQ_SLOTS );
	if( msgq == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

    /* insert messages into the queue from its head until it is full */
	for( i = 0; i < TESTQ_SLOTS; i++ )
    {
	    char buf[TESTQ_RECORDSIZE];
	    int j;

        /* generate a message string */
	    for( j = 0; j < TESTQ_RECORDSIZE - 1; j++ )
        {
	        buf[j] = '0' + i;
	    }
	    buf[j] = 0;

        /* insert this message to the queue from its head */
    	r = kal_enque_msg( msgq, buf, TESTQ_RECORDSIZE, KAL_NO_WAIT, KAL_TRUE );
    	if( r != KAL_SUCCESS )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_enque_msg failed: ret = %d", r );
    	    ktest_reset_target();
    	    return KTEST_FAIL;
    	}
    }

    /* test the basic functionality of kal_deque_msg */
    for( i = 0; i < TESTQ_SLOTS; i++ )
    {
	    char buf[TESTQ_RECORDSIZE];
        kal_uint16 mlen;
	    int j;

        /* dequeue a message from the queue,
         * if any error occurs, report FAIL. */
    	r = kal_deque_msg( msgq, buf, &mlen, KAL_NO_WAIT );
    	if( r != KAL_SUCCESS || mlen < TESTQ_RECORDSIZE )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID, "kal_deque_msg failed: ret=%d", r );
    	    ktest_reset_target();
    	    return KTEST_FAIL;
    	}

        /* test the content of the message, if it's not correct, report FAIL. */
    	for( j = 0; j < TESTQ_RECORDSIZE - 1; j++ )
        {
	        if( buf[j] != '0' + TESTQ_SLOTS - 1 - i )
            {
	            MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "queue content corruption" );
	        }
	    }
	    if( buf[j] != 0 )
        {
	        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "queue content corruption" );
	    }

        /* test the queue's information after dequeue completed,
         * if it's not correct, report FAIL. */
	    r = kal_get_queue_info( msgq, &msgq_info );
    	if( r != KAL_TRUE || msgq_info.pending_msgs != (TESTQ_SLOTS - (i + 1)) )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_get_queue_info failed: ret=%d, pending=%d", r,
                          msgq_info.pending_msgs );
    	    ktest_reset_target();
    	    return KTEST_FAIL;
    	}
    }

    /* no error occurs, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_dequeue_msgq2
 * Functionality:
 *     test kal_deque_msg: dequeue messages from an empty queue after
 *                         enqueue/dequeue operations in the pattern of
 *                         KAL_NO_WAIT.
 * Results:
 *     if returns KAL_Q_EMPTY, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_dequeue_msgq2( kal_uint32 argc, void *argv )
{
	kal_msgqid msgq;
	kal_msgq_info msgq_info;
    kal_status r;
    int i;
	char buf[TESTQ_RECORDSIZE];
    kal_uint16 mlen;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	msgq = kal_create_msg_q( "testmsgq", TESTQ_RECORDSIZE, TESTQ_SLOTS );
	if( msgq == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

    /* insert messages into the queue until it's full */
	for( i = 0; i < TESTQ_SLOTS; i++ )
    {
	    int j;

        /* generate a message string */
	    for( j = 0; j < TESTQ_RECORDSIZE - 1; j++ )
        {
	        buf[j] = '0' + i;
	    }
	    buf[j] = 0;

        /* insert this message into the queue, if not success, report FAIL. */
    	r = kal_enque_msg( msgq, buf, TESTQ_RECORDSIZE, KAL_NO_WAIT, KAL_FALSE );
    	if( r != KAL_SUCCESS )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_enque_msg failed: ret = %d", r );
    	    ktest_reset_target();
    	    return KTEST_FAIL;
    	}
    }

    /* dequeue messages from the queue,
     * and test the functionality of kal_deque_msg */
    for( i = 0; i < TESTQ_SLOTS; i++ )
    {
	    int j;

        /* test the basic functionality of kal_deque_msg
         * if any error occurs, report FAIL. */
    	r = kal_deque_msg( msgq, buf, &mlen, KAL_NO_WAIT );
    	if( r != KAL_SUCCESS || mlen < TESTQ_RECORDSIZE )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID, "kal_deque_msg failed: ret=%d", r );
    	    ktest_reset_target();
    	    return KTEST_FAIL;
    	}

        /* test the content of a message, if it's not correct, report FAIL. */
    	for( j = 0; j < TESTQ_RECORDSIZE - 1; j++ )
        {
	        if( buf[j] != '0' + i )
            {
	            MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "queue content corruption" );
	        }
	    }
	    if( buf[j] != 0 )
        {
	        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "queue content corruption" );
	    }

        /* test the queue's information after dequeue completed */
	    r = kal_get_queue_info( msgq, &msgq_info );
    	if( r != KAL_TRUE || msgq_info.pending_msgs != (TESTQ_SLOTS - (i + 1)) )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID,
                          "kal_get_queue_info failed: ret=%d, pending=%d",
                          r, msgq_info.pending_msgs );
    	    ktest_reset_target();
    	    return KTEST_FAIL;
    	}
    }

    /* the queue is empty now, so kal_deque_msg below will return KAL_Q_EMPTY,
     * if not, report FAIL. */
    {
        r = kal_deque_msg( msgq, buf, &mlen, KAL_NO_WAIT );
        if( r != KAL_Q_EMPTY )
        {
            MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "queue should be empty" );
        }
    }

    /* kal_deque_msg returns KAL_Q_EMPTY as we expected, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_dequeue_msgq3
 * Functionality:
 *     test kal_deque_msg: dequeue messages in the pattern of KAL_NO_WAIT
 *                         from an empty queue that is just created.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_dequeue_msgq3( kal_uint32 argc, void *argv )
{
	kal_msgqid msgq;
    kal_status r;
	char buf[TESTQ_RECORDSIZE];
    kal_uint16 mlen;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	msgq = kal_create_msg_q( "testmsgq", TESTQ_RECORDSIZE, TESTQ_SLOTS );
	if( msgq == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

    /* the queue is just created, and has no messages in it.
     * so the dequeue operation below will cause KAL_Q_EMPTY returned.
     * if not, report FAIL. */
    {
        r = kal_deque_msg( msgq, buf, &mlen, KAL_NO_WAIT );
        if( r != KAL_Q_EMPTY )
        {
            MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "queue should be empty" );
        }
    }

    /* kal_deque_msg returns KAL_Q_EMPTY as we expected, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_dequeue_msgq4
 * Functionality:
 *     test kal_deque_msg: dequeue messages from an empty queue in the pattern
 *                         of KAL_INFINITE_WAIT.
 * Results:
 *     if suspension occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_dequeue_msgq4( kal_uint32 argc, void *argv )
{
	kal_msgqid msgq;
    kal_status r;
	char buf[TESTQ_RECORDSIZE];
	kal_uint16 mlen;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

	msgq = kal_create_msg_q( "testmsgq", TESTQ_RECORDSIZE, TESTQ_SLOTS );
	if( msgq == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

    /* create a GPT timer to check whether a suspension will occur when dequeue
     * messages in the pattern of KAL_INFINITE_WAIT. */
	ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* the queue is just created and has no messages in it, so kal_deque_msg
     * will cause a suspension. if not, report FAIL. */
    r = kal_deque_msg( msgq, buf, &mlen, KAL_INFINITE_WAIT );

    /* no suspension occurs, reporp FAIL. */
	MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_enque_msg shold not return" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_dequeue_msgqE1a
 * Functionality:
 *     test kal_deque_msg: dequeue a message with the buffer pointer as NULL.
 * Results:
 *     if a fatal error: KAL_ERROR_ITC_QDEQUE_NIL_FAILED occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_dequeue_msgqE1a( kal_uint32 argc, void *argv )
{
	kal_msgqid msgq;
    kal_status r;
	char buf[TESTQ_RECORDSIZE];
    kal_uint16 mlen = TESTQ_RECORDSIZE + 5;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ITC_QDEQUE_NIL_FAILED;

	msgq = kal_create_msg_q( "testmsgq", TESTQ_RECORDSIZE, TESTQ_SLOTS );
	if( msgq == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

    /* since the queue is just created and has no messages in it,
     * so kal_deque_msg will cause a fatal error. if not, report FAIL. */
    r = kal_deque_msg( msgq, NULL, &mlen, KAL_INFINITE_WAIT );

    /* no fatal error occurs, report FAIL. */
	MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_enque_msg shold not return" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_dequeue_msgqE1b
 * Functionality:
 *     test kal_deque_msg: dequeue a message with qid as NULL.
 * Results:
 *     if a fatal error: KAL_ERROR_ITC_QDEQUE_NIL_FAILED occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_dequeue_msgqE1b( kal_uint32 argc, void *argv )
{
	kal_msgqid msgq;
    kal_status r;
	char buf[TESTQ_RECORDSIZE];
    kal_uint16 mlen = TESTQ_RECORDSIZE + 5;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ITC_QDEQUE_NIL_FAILED;

	msgq = kal_create_msg_q( "testmsgq", TESTQ_RECORDSIZE, TESTQ_SLOTS );
	if( msgq == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

    /* since the queue is just created and has no messages in it,
     * so kal_deque_msg below will cause a fatal error. if not, report FAIL. */
    r = kal_deque_msg( NULL, buf, &mlen, KAL_INFINITE_WAIT );

    /* no fatal error occurs, report FAIL. */
	MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_enque_msg shold not return" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_pre_testqueue_thread
 * Functionality:
 *     the main function of a thread that enque or deque messages.
 * Parameters:
 *     param_ptr: if it's "sender", do enqueue operations.
 *                else, do dequeue operations.
 * Returns:
 *     void.
 * Note:
 *     this function is not a test case, but it is used to support severial test
 *     cases below.
 *****************************************************************************/
kal_msgqid _g_testqueue_msgq1;
void ktest_ipc_pre_testqueue_thread( void *param_ptr )
{
    const char *str = (const char *) param_ptr;
    char buf[TESTQ_RECORDSIZE];
    kal_uint16 mlen;
    kal_status r;

    if( strcmp(str, "sender") == 0 )
    {
        /* this thread executes as a sender, do enqueue operations. */
        while( 1 )
        {
            int i;
            char ch = '0' + rand() % 64;

            /* generate a message string */
            for( i = 0; i < TESTQ_RECORDSIZE - 1; i++ )
            {
                buf[i] = ch;
            }
            buf[i] = 0;

            /* insert this message into the queue */
            r = kal_enque_msg( _g_testqueue_msgq1, buf, TESTQ_RECORDSIZE,
                               KAL_INFINITE_WAIT, KAL_FALSE );
            if( r != KAL_SUCCESS )
            {
                ktest_report_reset3( KTEST_FAIL, KTEST_TCID, "kal_enque_msg_q failed" );
            }

            /* sleep for a while */
            if( rand() % 7 == 0 )
            {
                kal_sleep_task( 1 );
            }
        }
    }
    else {
        /* this thread executes as a receiver, do dequeue operations. */
        while( 1 )
        {
            int i;
            char ch;

            /* dequeue a message from the queue, if not success, report FAIL. */
            memset( buf, 0, sizeof(buf) );
            r = kal_deque_msg( _g_testqueue_msgq1, buf, &mlen, KAL_INFINITE_WAIT );
            if( r != KAL_SUCCESS )
            {
                ktest_report_reset3( KTEST_FAIL, KTEST_TCID, "kal_deque_msg_q failed" );
            }

            /* test whether the content of a message is correct.
             * if not, report FAIL. */
            ch = buf[0];
            for( i = 1; i < TESTQ_RECORDSIZE - 1; i++ )
            {
                if( buf[i] != ch )
                {
                    ktest_report_reset3( KTEST_FAIL, KTEST_TCID, "kal_deque_msg_q failed" );
                }
            }
            if( buf[i] != 0 )
            {
                ktest_report_reset3( KTEST_FAIL, KTEST_TCID, "kal_deque_msg_q failed" );
            }
        }
    }
}

/******************************************************************************
 * Name:
 *     ktest_ipc_testqueue1
 * Functionality:
 *     test kal_enque_msg/kal_deque_msg in the environment with multiple tasks.
 *     note that the task with higher priority will send messages to the one
 *               with lower priority.
 * Results:
 *     if the sender and receiver can run infinitly before the GPT timer
 *         expires (16 senconds), report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_testqueue1( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* create a queue for sender to insert messages to and reveiver to retrieve
     * messages from */
	_g_testqueue_msgq1 = kal_create_msg_q( "testmsgq", TESTQ_RECORDSIZE, TESTQ_SLOTS );
	if( _g_testqueue_msgq1 == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

    /* create a task with higher priority
     * to send messages to _g_test_queue_msgq1 infinitly */
    ktest_lib_createtask( 61,
                          (kal_task_func_ptr) ktest_ipc_pre_testqueue_thread,
                          "sender" );

    /* create a task with lower priority
     * to receive messages from _g_test_queue_msgq1 infinitly */
    ktest_lib_createtask( 62,
                          (kal_task_func_ptr) ktest_ipc_pre_testqueue_thread,
                          "receiver" );

    /* start a GPT timer to check whether the sender and receiver are running
     * infinitly. as we expected, they will always run before timer expires. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* suspend current task, to make sender and receiver run. */
    kal_sleep_task( KAL_SUSPEND );

    /* we come here before timer expires, this is not what we expected,
     * report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_testqueue2
 * Functionality:
 *     test kal_enque_msg/kal_deque_msg in the environment with multiple tasks.
 *     note that the task with lower priority will send messages to the one
 *               with higher priority.
 * Results:
 *     if the sender and receiver can run infinitly before the GPT timer
 *         expires (16 seconds), report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_testqueue2( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* create a queue for the sender to send messages to and the receiver
     * retrieve messages from */
	_g_testqueue_msgq1 = kal_create_msg_q( "testmsgq", TESTQ_RECORDSIZE, TESTQ_SLOTS );
	if( _g_testqueue_msgq1 == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

    /* create a task with lower priority
     * to send messages to _g_testqueue_msgq1 infinitly */
    ktest_lib_createtask( 62,
                          (kal_task_func_ptr) ktest_ipc_pre_testqueue_thread,
                          "sender" );

    /* create a task with higher priority
     * to receive messages from _g_testqueue_msgq1 infinitly */
    ktest_lib_createtask( 61,
                          (kal_task_func_ptr) ktest_ipc_pre_testqueue_thread,
                          "receiver" );

    /* start a GPT timer to check whether the sender and receiver are running
     * infinitly. as we expected, they will always run before timer expires */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* suspend current task, to make sender and receiver to run */
    kal_sleep_task( KAL_SUSPEND );

    /* we come here before the timer expires, this is not what we expected,
     * report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_testqueue3
 * Functionality:
 *     test kal_enque_msg/kal_deque_msg in the environment with multiple tasks.
 *     note that more than one sender and reciver tasks will work on one queue.
 * Results:
 *     if the sender and receiver tasks are running infinitly before the GPT
 *         timer expires (16 seconds), report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_testqueue3( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;

    /* create a queue for the sender and receiver tasks to work on */
	_g_testqueue_msgq1 = kal_create_msg_q( "testmsgq", TESTQ_RECORDSIZE, TESTQ_SLOTS );
	if( _g_testqueue_msgq1 == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

    /* create 2 sender tasks and 2 receiver tasks. and note that their
     * priorities from high to low is: receiver > sender > sender > receiver */
    ktest_lib_createtask( 62,
                          (kal_task_func_ptr) ktest_ipc_pre_testqueue_thread,
                          "sender" );
    ktest_lib_createtask( 61,
                          (kal_task_func_ptr) ktest_ipc_pre_testqueue_thread,
                          "receiver" );
    ktest_lib_createtask( 63,
                          (kal_task_func_ptr) ktest_ipc_pre_testqueue_thread,
                          "sender" );
    ktest_lib_createtask( 64,
                          (kal_task_func_ptr) ktest_ipc_pre_testqueue_thread,
                          "receiver" );

    /* start a GPT timer to check whether the sender and receiver tasks are
     * always running before the timer expires */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* suspend current task, to make sender and receiver tasks to run. */
    kal_sleep_task( KAL_SUSPEND );

    /* we come here before the timer expires, this is not what we expected,
     * report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * macros to access task_ext_qid and task_int_qid_ptr.
 *****************************************************************************/
#define TEST_EXTQ ( task_info_g[mod_task_g[MOD_IDLE]].task_ext_qid )
#define TEST_INTQ ( task_info_g[mod_task_g[MOD_IDLE]].task_int_qid_ptr )

/******************************************************************************
 * Name:
 *     create_queue
 * Functionality:
 *     create an external queue and an internal queue.
 * Parameters:
 *     void.
 * Returns:
 *     KAL_TRUE to indicate it executes successfully.
 *****************************************************************************/
static kal_bool create_queue( void )
{
    kal_msgqid extq;
	int_q_type *intq;

    /* create an external queue, if not success, report FAIL. */
	extq = kal_create_msg_q( "ilmqueue", sizeof(ilm_struct), TESTQ_SLOTS );
	if( extq == NULL )
    {
	    ktest_report_reset3( KTEST_FAIL, KTEST_TCID, "kal_create_msg_q failed" );
	}

    /* create an internal queue, if not success, report FAIL. */
	intq = kal_sys_mem_alloc( sizeof(int_q_type) + (TESTQ_SLOTS - 1) * sizeof(ilm_struct) );
	if( intq == NULL )
    {
	    ktest_report_reset3( KTEST_FAIL, KTEST_TCID, "kal_sys_mem_alloc for intq failed" );
	}
	LCD_IP_CQUEUE_INIT_N( (*intq), TESTQ_SLOTS );

    /* set task's ext_qid and int_qid_ptr */
	TEST_EXTQ = extq;
	TEST_INTQ = intq;

    /* create external queue and internal queue successfully */
	return KAL_TRUE;
}

/******************************************************************************
 * Name:
 *     ktest_ipc_create_intext_queue
 * Functionality:
 *     test the basic functionality of create external queue and internal queue.
 * Results:
 *     if create queues successfully, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_create_intext_queue( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an external queue and an internal queue.
     * if not success, report FAIL in create_queue. */
	create_queue();

    /* create queues successfully, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_msg_get_ext_queue_info
 * Functionality:
 *     test the basic functionality of msg_get_ext_queue_info and
 *     msg_get_ext_queue_length.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_msg_get_ext_queue_info( kal_uint32 argc, void *argv )
{
	kal_bool r;
	kal_uint32 len;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an external queue and an internal queue */
	create_queue();

    /* test the basic functionality of msg_get_ext_queue_info
     * if not success, report FAIL. */
	r = msg_get_ext_queue_info( TEST_EXTQ, &len );
	if( r != KAL_TRUE || len != 0 )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID,
                      "msg_get_ext_queue_info failed: r = %d (expected %d), len = %u (expected %u)",
                      r, KAL_TRUE, len, 0 );
	    ktest_reset_target();
	}

    /* test the basic functionality of msg_get_ext_queue_length
     * if not success, report FAIL. */
	r = msg_get_ext_queue_length( TEST_EXTQ, &len );
	if( r != KAL_TRUE || len != TESTQ_SLOTS )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID,
                      "msg_get_ext_queue_length failed: r = %d (expected %d), len = %u (expected %u)",
                      r, KAL_TRUE, len, TESTQ_SLOTS );
	    ktest_reset_target();
	}

    /* no error occurs, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_msg_send_ext_queue
 * Functionality:
 *     test the basic functionality of msg_send_ext_queue.
 * Results:
 *     if send messages and clear ILM allocation bit mask successfully,
 *         report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_msg_send_ext_queue( kal_uint32 argc, void *argv )
{
	ilm_struct *ilmp;
	kal_bool r;
	kal_uint32 len;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an external queue and an internal queue */
	create_queue();

    /* get the information that how many messages in the external queue now.
     * since it is just created, so the value must be 0. if not, report FAIL. */
	r = msg_get_ext_queue_info( TEST_EXTQ, &len );
	if( r != KAL_TRUE || len != 0 )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID,
                      "msg_get_ext_queue_info failed: r = %d (expected %d), len = %u (expected %u)",
                      r, KAL_TRUE, len, 0 );
	    ktest_reset_target();
	}

    /* get the information that how many messages can the queue contain, and the
     * value should be TESTQ_SLOTS. if not, report FAIL. */
	r = msg_get_ext_queue_length( TEST_EXTQ, &len );
	if( r != KAL_TRUE || len != TESTQ_SLOTS )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID,
                      "msg_get_ext_queue_length failed: r = %d (expected %d), len = %u (expected %u)",
                      r, KAL_TRUE, len, TESTQ_SLOTS );
	    ktest_reset_target();
	}

    /* allocate an ILM to send a message, if not success, report FAIL. */
	ilmp = allocate_ilm( MOD_USB );
	if( ilmp == NULL )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, "allocate_ilm failed" );
	    ktest_reset_target();
	}

    /* set the values of ILM */
	ilmp->src_mod_id = MOD_USB;
	ilmp->dest_mod_id = MOD_IDLE;
	ilmp->sap_id = (sap_type) 200;
	ilmp->msg_id = (msg_type) 100;
	ilmp->local_para_ptr = NULL;
	ilmp->peer_buff_ptr = NULL;

    /* send ILM to the external queue. if not success, report FAIL. */
	r = msg_send_ext_queue( ilmp );
	if( r != KAL_TRUE )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, "msg_send_ext_queue failed" );
	    ktest_reset_target();
	}

    /* test whether the external queue's information is correct after sending
     * an ILM to it. */
	r = msg_get_ext_queue_info( TEST_EXTQ, &len );
	if( r != KAL_TRUE || len != 1 )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID,
                      "msg_get_ext_queue_info failed: r = %d (expected %d), len = %u (expected %u)",
                      r, KAL_TRUE, len, 1 );
	    ktest_reset_target();
	}

    /* if send message successfully, the allocation bit mask will be cleared.
     * so the allocate_ilm below will execute successfully.
     * if not, report FAIL. */
	ilmp = allocate_ilm( MOD_USB );
	if( ilmp == NULL )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, "allocate_ilm failed" );
	    ktest_reset_target();
	}

    /* no error occurs, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_msg_send_ext_queue_to_head
 * Functionality:
 *     test the basic functionality of msg_send_ext_queue_to_head.
 *     that is, use msg_send_ext_queue_to_head() to send an ILM to MOD_IDLE,
 *              and verify that it will clear the allocation bit mask.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_msg_send_ext_queue_to_head( kal_uint32 argc, void *argv )
{
	ilm_struct *ilmp;
	kal_bool r;
	kal_uint32 len;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an external queue and an internal queue */
	create_queue();

    /* get that how many messages in the queue now.
     * if not correct, report FAIL. */
	r = msg_get_ext_queue_info( TEST_EXTQ, &len );
	if( r != KAL_TRUE || len != 0 )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID,
                      "msg_get_ext_queue_info failed: r = %d (expected %d), len = %u (expected %u)",
                      r, KAL_TRUE, len, 0 );
	    ktest_reset_target();
	}

    /* get that how many messages the queue can contain.
     * if it's not TESTQ_SLOTS, report FAIL. */
	r = msg_get_ext_queue_length( TEST_EXTQ, &len );
	if( r != KAL_TRUE || len != TESTQ_SLOTS )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID,
                      "msg_get_ext_queue_length failed: r = %d (expected %d), len = %u (expected %u)",
                      r, KAL_TRUE, len, TESTQ_SLOTS );
	    ktest_reset_target();
	}

    /* allocate an ILM to send. if not success, report FAIL. */
	ilmp = allocate_ilm( MOD_USB );
	if( ilmp == NULL )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, "allocate_ilm failed" );
	    ktest_reset_target();
	}

    /* set the value of ILM */
	ilmp->src_mod_id = MOD_USB;
	ilmp->dest_mod_id = MOD_IDLE;
	ilmp->sap_id = (sap_type) 200;
	ilmp->msg_id = (msg_type) 100;
	ilmp->local_para_ptr = NULL;
	ilmp->peer_buff_ptr = NULL;

    /* send the ILM to external queue. if not success, report FAIL. */
	r = msg_send_ext_queue_to_head( ilmp );
	if( r != KAL_TRUE )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, "msg_send_ext_queue failed" );
	    ktest_reset_target();
	}

    /* test whether the queue's information is correct after sending a message
     * to external queue. */
	r = msg_get_ext_queue_info( TEST_EXTQ, &len );
	if( r != KAL_TRUE || len != 1 )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID,
                      "msg_get_ext_queue_info failed: r = %d (expected %d), len = %u (expected %u)",
                      r, KAL_TRUE, len, 1 );
	    ktest_reset_target();
	}

    /* since msg_send_ext_queue_to_head will clear the ILM's allocation bit
     * mask, so allocate_ilm below will execute successfully.
     * if not, report FAIL. */
	ilmp = allocate_ilm( MOD_USB );
	if( ilmp == NULL )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, "allocate_ilm failed" );
	    ktest_reset_target();
	}

    /* no error occurs, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_msg_send_int_queue
 * Functionality:
 *     test the basic functionality of msg_send_int_queue.
 *     that is, use msg_send_int_queue() to send an ILM to MOD_IDLE, and verify
 *              it will clear the ILM's allocation bit mask.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_msg_send_int_queue( kal_uint32 argc, void *argv )
{
	ilm_struct *ilmp;
	kal_bool r;
	kal_uint32 len;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an external queue and an internal queue */
	create_queue();

    /* allocate an ILM to send. if not success, report FAIL. */
	ilmp = allocate_ilm( MOD_IDLE );
	if( ilmp == NULL )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, "allocate_ilm failed" );
	    ktest_reset_target();
	}

    /* set the value of ILM */
	ilmp->src_mod_id = MOD_IDLE;
	ilmp->dest_mod_id = MOD_IDLE;
	ilmp->sap_id = (sap_type) 200;
	ilmp->msg_id = (msg_type) 100;
	ilmp->local_para_ptr = NULL;
	ilmp->peer_buff_ptr = NULL;

    /* send the ILM to internal queue. if not success, report FAIL. */
	r = msg_send_int_queue( ilmp );
	if( r != KAL_TRUE )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, "msg_send_int_queue failed" );
	    ktest_reset_target();
	}

    /* since msg_send_int_queue will clear the ILM's allocation bit mask, so
     * allocate_ilm below will execute successfully. if not, report FAIL. */
	ilmp = allocate_ilm( MOD_USB );
	if( ilmp == NULL )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, "allocate_ilm failed" );
	    ktest_reset_target();
	}

    /* no error occurs, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_receive_msg_ext_q
 * Functionality:
 *     test receive_msg_ext_q on an empty external queue. as we expected, the
 *     task will be blocked forever.
 * Results:
 *     we start a timer (16 seconds) to check whether the receiver task has been
 *     blocked.
 *     if the task is still blocked before the timer expires, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_receive_msg_ext_q( kal_uint32 argc, void *argv )
{
	ilm_struct ilm;
	kal_status r;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an external queue and an internal queue */
	create_queue();

    /* since the receiver task works on an empty queue, so it will be blocked
     * forever. so we start a GPT timer (16 seconds), if the receiver task is
     * still be blocked when the timer expires, then we think that the receiver
     * task is in the status we expected. also, KTEST will report PASS in the
     * timer handler. */
	ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* receive messages from an empty external queue */
    r = receive_msg_ext_q( TEST_EXTQ, &ilm );

    /* we come here before the timer expires, this is not what we expected,
     * report FAIL. */
	MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_receive_msg_int_q
 * Functionality:
 *     test receive_msg_int_q on an empty internal queue. as expected, it will
 *     return KAL_FALSE.
 * Results:
 *     if return KAL_FALSE, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_receive_msg_int_q( kal_uint32 argc, void *argv )
{
	ilm_struct ilm;
	kal_bool r;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an external queue and an internal queue */
	create_queue();

    /* start a timer to check this situation:
     *     if we can't receive any message from the internal queue until the
     *     timer expires, then we think that the receiver is blocked. at this
     *     case, report FAIL.
     * but do we really need this ? */
	ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_FAIL );

    /* receive messages from an internal queue, note that the queue is empty. */
    r = receive_msg_int_q( mod_task_g[MOD_IDLE], &ilm );

    /* since the queue is empty, the receive_msg_int_q will return KAL_FALSE.
     * if so, return PASS; else, return FAIL. */
	if( r != KAL_FALSE )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "receive_msg_int_q return unexpected value" );
	}
    else
	{
        MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_ipc_msg_send_ext_queue2
 * Functionality:
 *     test msg_send_ext_queue/receive_msg_ext_q.
 *     that is, send a message to MOD_IDLE, then receive the message and check
 *              its content.
 * Results:
 *     if we can send and receive message successfully, and the content of the
 *     message is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_msg_send_ext_queue2( kal_uint32 argc, void *argv )
{
	ilm_struct *ilmp;
	ilm_struct ilm;
	kal_bool r;
	kal_uint32 len;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an external queue and an internal queue */
	create_queue();

    /* allocate an ILM. if not success, report FAIL. */
	ilmp = allocate_ilm( MOD_USB );
	if( ilmp == NULL )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, "allocate_ilm failed" );
	    ktest_reset_target();
	}

    /* set the value of ILM */
	ilmp->src_mod_id = MOD_USB;
	ilmp->dest_mod_id = MOD_IDLE;
	ilmp->sap_id = (sap_type) 200;
	ilmp->msg_id = (msg_type) 100;
	ilmp->local_para_ptr = (local_para_struct *) 1;
	ilmp->peer_buff_ptr = (peer_buff_struct *) 2;

    /* send the ILM to an external queue. if not success, report FAIL. */
	r = msg_send_ext_queue( ilmp );
	if( r != KAL_TRUE )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, "msg_send_ext_queue failed" );
	    ktest_reset_target();
	}

    /* check whether the queue's information is correct after sending an ILM
     * to it. */
	r = msg_get_ext_queue_info( TEST_EXTQ, &len );
	if( r != KAL_TRUE || len != 1 )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID,
                      "msg_get_ext_queue_info failed: r = %d (expected %d), len = %u (expected %u)",
                      r, KAL_TRUE, len, 1 );
	    ktest_reset_target();
	}

    /* since receive_msg_ext_q may be blocked on an empty queue, so we start a
     * timer to check this situation. if we can't receive a message until the
     * timer expires, then report FAIL. */
	ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_FAIL );

    /* receive messages from the external queue. if not success, report FAIL. */
	r = receive_msg_ext_q( TEST_EXTQ, &ilm );
	if( r != KAL_SUCCESS )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "receive_msg_ext_q failed" );
	}

    /* we come here because we have received a message, now check its
     * content. if it's not correct, report FAIL. */
	if( ilmp->src_mod_id != MOD_USB
	    || ilmp->dest_mod_id != MOD_IDLE
	    || ilmp->sap_id != (sap_type)200
	    || ilmp->msg_id != (msg_type)100
	    || ilmp->local_para_ptr != (local_para_struct *) 1
	    || ilmp->peer_buff_ptr != (peer_buff_struct *) 2 )
	{
	        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "ilm content corruptted" );
	}

    /* no error occurs, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_msg_send_ext_queue_to_head2
 * Functionality:
 *     test msg_send_ext_queue_to_head/receive_msg_ext_q.
 *     that is, send a message to the head of MOD_IDLE's external queue, then
 *              try to get it back and check its conten.
 * Results:
 *     if send and receive messages successfully, and its conent is correct,
 *     report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_msg_send_ext_queue_to_head2( kal_uint32 argc, void *argv )
{
	ilm_struct *ilmp;
	ilm_struct ilm;
	kal_bool r;
	kal_uint32 len;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an external queue and an internal queue */
	create_queue();

    /* allocate an ILM. if not success, report FAIL. */
	ilmp = allocate_ilm( MOD_USB );
	if( ilmp == NULL )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, "allocate_ilm failed" );
	    ktest_reset_target();
	}

    /* set the value of ILM */
	ilmp->src_mod_id = MOD_USB;
	ilmp->dest_mod_id = MOD_IDLE;
	ilmp->sap_id = (sap_type) 200;
	ilmp->msg_id = (msg_type) 100;
	ilmp->local_para_ptr = (local_para_struct *) 1;
	ilmp->peer_buff_ptr = (peer_buff_struct *) 2;

    /* send the message to the head  of external queue.
     * if not success, report FAIL. */
	r = msg_send_ext_queue_to_head( ilmp );
	if( r != KAL_TRUE )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, "msg_send_ext_queue failed" );
	    ktest_reset_target();
	}

    /* since receive_msg_ext_q may be blocked on an empty queue, so we start a
     * timer to check this situation. if we can't receive a message until the
     * timer expires, report FAIL. */
	ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_FAIL );

    /* try to receive a message from the external queue.
     * if not success, report FAIL. */
	r = receive_msg_ext_q( TEST_EXTQ, &ilm );
	if( r != KAL_SUCCESS )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "receive_msg_ext_q failed" );
	}

    /* a message has been received, now check its content.
     * if not correct, report FAIL. */
	if( ilmp->src_mod_id != MOD_USB
	    || ilmp->dest_mod_id != MOD_IDLE
	    || ilmp->sap_id != (sap_type) 200
	    || ilmp->msg_id != (msg_type) 100
	    || ilmp->local_para_ptr != (local_para_struct *) 1
	    || ilmp->peer_buff_ptr != (peer_buff_struct *) 2 )
	{
	        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "ilm content corruptted" );
	}

    /* no error occurs, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_msg_send_int_queue2
 * Functionality:
 *     test msg_send_int_q/receive_msg_int_q.
 *     that is, send a message to MOD_IDLE's internal queue, then try to receive
 *              it back and check its content.
 * Results:
 *     if send and receive messages successfully, and its content is correct,
 *     report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_msg_send_int_queue2( kal_uint32 argc, void *argv )
{
	ilm_struct *ilmp, ilm;
	kal_bool r;
	kal_uint32 len;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an external queue and an internal queue */
	create_queue();

    /* allocate an ILM to send. if not success, report FAIL. */
	ilmp = allocate_ilm( MOD_USB );
	if( ilmp == NULL )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, "allocate_ilm failed" );
	    ktest_reset_target();
	}

    /* set the value of ILM */
	ilmp->src_mod_id = MOD_USB;
	ilmp->dest_mod_id = MOD_IDLE;
	ilmp->sap_id = (sap_type) 200;
	ilmp->msg_id = (msg_type) 100;
	ilmp->local_para_ptr = (local_para_struct *) 1;
	ilmp->peer_buff_ptr = (peer_buff_struct *) 2;

    /* send the ILM to internal queue. if not success, report FAIL. */
	r = msg_send_int_queue( ilmp );
	if( r != KAL_TRUE )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, "msg_send_ext_queue failed" );
	    ktest_reset_target();
	}

    /* start a timer to check this situation:
     *     if we can't receive any message from the internal queue until the
     *     timer expires, then we think that the receiver is blocked. at this
     *     case, report FAIL.
     * but do we really need this ? */
	ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_FAIL );

    /* receive messages from the internal queue.
     * if not success, report FAIL. */
	r = receive_msg_int_q( mod_task_g[MOD_IDLE], &ilm );
	if( r != KAL_TRUE )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "receive_msg_ext_q failed" );
	}

    /* we have received an ILM now, then check its content.
     * if not correct, report FAIL. */
	if( ilmp->src_mod_id != MOD_USB
	    || ilmp->dest_mod_id != MOD_IDLE
	    || ilmp->sap_id != (sap_type) 200
	    || ilmp->msg_id != (msg_type) 100
	    || ilmp->local_para_ptr != (local_para_struct *) 1
	    || ilmp->peer_buff_ptr != (peer_buff_struct *) 2 )
	{
	        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "ilm content corruptted" );
	}

    /* no error occurs, report PASS. */
	MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_msg_send_ext_queue_full
 * Functionality:
 *     test msg_send_ext_queue on a full queue. as we expected, this will cause
 *     a fatal error: KAL_ERROR_ITC_QENQUE_EXT_FAILED.
 * Results:
 *     if a fatal error: KAL_ERROR_ITC_QENQUE_EXT_FAILED occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_msg_send_ext_queue_full( kal_uint32 argc, void *argv )
{
	ilm_struct *ilmp;
	kal_bool r;
	kal_uint32 len;
	int i;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an external queue and an internal queue. */
	create_queue();

    /* check the queue's information, in order to check whether we have sent
     * the message successfully. if not success, report FAIL. */
	r = msg_get_ext_queue_info( TEST_EXTQ, &len );
	if( r != KAL_TRUE || len != 0 )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID,
                      "msg_get_ext_queue_info failed: r = %d (expected %d), len = %u (expected %u)",
                      r, KAL_TRUE, len, 0 );
	    ktest_reset_target();
	}

    /* check the queue's max length, in order to check whether the queue is
     * correct after sending a message to it. if not, report FAIL. */
	r = msg_get_ext_queue_length( TEST_EXTQ, &len );
	if( r != KAL_TRUE || len != TESTQ_SLOTS )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID,
                      "msg_get_ext_queue_length failed: r = %d (expected %d), len = %u (expected %u)",
                      r, KAL_TRUE, len, TESTQ_SLOTS );
	    ktest_reset_target();
	}

    /* send messages to external queue until it is full */
	for( i = 0; i < TESTQ_SLOTS; i++ )
    {
send_one:
        /* allocate an ILM to send. if not success, report FAIL. */
	    ilmp = allocate_ilm( MOD_USB );
    	if( ilmp == NULL )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID, "allocate_ilm failed" );
    	    ktest_reset_target();
    	}

        /* set the value of ILM */
    	ilmp->src_mod_id = MOD_USB;
    	ilmp->dest_mod_id = MOD_IDLE;
    	ilmp->sap_id = (sap_type) 200;
    	ilmp->msg_id = (msg_type) 100;

        /* send the ILM to external queue. if not success, report FAIL. */
    	r = msg_send_ext_queue( ilmp );
    	if( r != KAL_TRUE )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID, "msg_send_ext_queue failed" );
    	    ktest_reset_target();
    	}
	}

    /* the queue is full now. then we will send one more message to it, and as
     * we expected, a fatal error will occur. */
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ITC_QENQUE_EXT_FAILED;
	goto send_one;

    /* no fatal error occurs, this is not what we expected, report FAIL. */
	MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_msg_send_int_queue_full
 * Functionality:
 *     test msg_send_int_queue to a full queue. as we expected, a fatal error:
 *     KAL_ERROR_ITC_QENQUE_INT_FAILED will occur.
 * Results:
 *     if KAL_ERROR_ITC_QENQUE_INT_FAILED occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_msg_send_int_queue_full( kal_uint32 argc, void *argv )
{
	ilm_struct *ilmp;
	kal_bool r;
	kal_uint32 len;
	int i;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an external queue and an internal queue. */
	create_queue();

    /* send messages to internal queue until it is full. */
	for( i = 0; i < TESTQ_SLOTS; i++ )
    {
send_one:
        /* allocate an ILM to send. if not success, report FAIL. */
	    ilmp = allocate_ilm( MOD_USB );
    	if( ilmp == NULL )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID, "allocate_ilm failed" );
    	    ktest_reset_target();
    	}

        /* set the value of ILM */
    	ilmp->src_mod_id = MOD_USB;
    	ilmp->dest_mod_id = MOD_IDLE;
    	ilmp->sap_id = (sap_type) 200;
    	ilmp->msg_id = (msg_type) 100;

        /* send the ILM to internal queue. if not success, report FAIL. */
    	r = msg_send_int_queue( ilmp );
    	if( r != KAL_TRUE )
        {
    	    ktest_report( KTEST_FAIL, KTEST_TCID, "msg_send_int_queue failed" );
    	    ktest_reset_target();
    	}
	}

    /* the internal queue is full now. then we will send one more ILM to it, as
     * we expected, this will cause a fatal error. */
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ITC_QENQUE_INT_FAILED;
	goto send_one;

    /* no fatal error occurs. this is not what we expected, report FAIL. */
	MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     kest_ipc_msg_send_ext_queue_thread
 * Functionality:
 *     a task to send or receive messages on external queue.
 * Parameters:
 *     role: if it is "hi-sender", the task will send messages.
 *           else if it is "lo-sender", the task will send messages.
 *           else, the task will receive messages.
 * Returns:
 *     void.
 * Note:
 *     this function is not a test case, it is to support severial test cases
 *     below.
 *****************************************************************************/
static void ktest_ipc_msg_send_ext_queue_thread( const char *role )
{
    int sender = 0;
    int hisender = 0;
    int index;
    module_type srcmod;
    kal_status r;

    /* check if the role is "hi-sender" or "lo-sender".
     * if so, this task will take the role as a sender.
     * else, as a receiver. */
    if( strncmp( role, "hi-sender", 9 ) == 0 )
    {
        sender = 1;
        index = role[9] - '1';
        srcmod = (module_type) ( MOD_MM + index );
        hisender = 1;
    }
    else if( strncmp( role, "lo-sender", 9 ) == 0 )
    {
        sender = 1;
        index = role[9] - '1';
        srcmod = (module_type) ( MOD_BT + index );
        hisender = 0;
    }

    if( sender )
    {
        /* this task is a sender */
        ilm_struct *ilmp;
        while( 1 )
        {
            int a, b;
            a = rand();
            b = rand();

            /* allocate an ILM. if not success, report FAIL. */
            ilmp = allocate_ilm( srcmod );
            if( ilmp == NULL )
            {
                ktest_report_reset3( KTEST_FAIL, KTEST_TCID, "allocate_ilm failed" );
            }

            /* set the value of ILM. */
            ilmp->src_mod_id = srcmod;
        	ilmp->dest_mod_id = MOD_IDLE;
        	ilmp->sap_id = (sap_type) a;
        	ilmp->msg_id = (msg_type) a;
        	ilmp->local_para_ptr = (local_para_struct *) b;
        	ilmp->peer_buff_ptr = (peer_buff_struct *) b;

            /* send the message into external queue.
             * if not success, report FAIL. */
        	r = msg_send_ext_queue( ilmp );
        	if( r != KAL_TRUE )
            {
                ktest_report_reset3( KTEST_FAIL, KTEST_TCID, "msg_send_ext_queue failed" );
            }

            /* the sender task with higher priority will suspend for a while,
             * in order to give changes to other tasks to run. */
            if( hisender )
            {
                kal_sleep_task( 1 );
            }
        }
    }
    else {
        /* this task is a receiver. */
        ilm_struct ilm;
        while( 1 )
        {
            /* try to receive a message from external queue.
             * if not success, report FAIL. */
            r = receive_msg_ext_q( TEST_EXTQ, &ilm );
            if( r != KAL_SUCCESS )
            {
                ktest_report_reset3( KTEST_FAIL, KTEST_TCID, "receive_msg_ext_q failed" );
            }

            /* we have received a message, then check its content.
             * if not correct, report FAIL. */
            if( ilm.dest_mod_id != MOD_IDLE
                || (int) ilm.sap_id != (int) ilm.msg_id
                || (int) ilm.local_para_ptr != (int) ilm.peer_buff_ptr )
            {
                ktest_report_reset3( KTEST_FAIL, KTEST_TCID, "ilm content corrupted" );
            }
        }
    }
}

/******************************************************************************
 * Name:
 *     ktest_ipc_msg_send_ext_queue_mt
 * Functionality:
 *     test external queue using multiple tasks.
 *     note that, we create 4 tasks to send and 1 task to receive.
 *     and their priority from high to low is:
 *         hi-sender1 > hi-sender2 > receiver > lo-sender1 > lo-sender2
 * Results:
 *     as we expected, the sender tasks and the receiver task will run
 *     infinitly. so we start a timer to check this, if the the sender and
 *     receiver is still running when the timer expires, then report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_msg_send_ext_queue_mt(kal_uint32 argc, void *argv)
{
	ilm_struct *ilmp;
	kal_bool r;
	kal_uint32 len;
	int i;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an external queue and an internal queue. */
	create_queue();

    /* create 4 sender tasks and 1 receiver task. note their priorities. */
    ktest_lib_createtask( 61, (kal_task_func_ptr) ktest_ipc_msg_send_ext_queue_thread, "hi-sender1" );
    ktest_lib_createtask( 62, (kal_task_func_ptr) ktest_ipc_msg_send_ext_queue_thread, "hi-sender2" );
    ktest_lib_createtask( 63, (kal_task_func_ptr) ktest_ipc_msg_send_ext_queue_thread, "receiver" );
    ktest_lib_createtask( 64, (kal_task_func_ptr) ktest_ipc_msg_send_ext_queue_thread, "lo-sender1" );
    ktest_lib_createtask( 65, (kal_task_func_ptr) ktest_ipc_msg_send_ext_queue_thread, "lo-sender2" );

    /* as we expected, the sender tasks and the receiver task will run infinitly
     * until the timer expires. so we report PASS in the timer handler. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* suspend current task, to make the senders and receiver to run. */
    kal_sleep_task( KAL_SUSPEND );

    /* we come here before timer expires, and this is not what we expected,
     * report FAIL.*/
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_pre_mutex1
 * Functionality:
 *     test the basic functionality of kal_create_mutex.
 * Results:
 *     if any error occurs, report FAIL.
 *     else, report PASS.
 *****************************************************************************/
kal_int32 ktest_ipc_pre_mutex1( kal_uint32 argc, void *argv )
{
	kal_mutexid mptr;
    kal_uint32 i;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create 24 mutexes using kal_create_mutex */
	for( i = 0; i < 24; i++ )
    {
    	mptr = kal_create_mutex( "tstmutex" );

        /* if fail to create a mutex, report FAIL. */
    	if( mptr == NULL )
        {
    	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
    	}
    }

    /* no error occurs, report PASS. */
    MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_mutex2
 * Functionality:
 *     test the basic functionality of kal_take_mutex and kal_give_mutex
 *     in single task.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_mutex2( kal_uint32 argc, void *argv )
{
	kal_mutexid mptr;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create a mutex. if not success, report FAIL. */
	mptr = kal_create_mutex( "tstmutex" );
	if( mptr == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
	}

    /* take the mutex in this task. */
	kal_take_mutex( mptr );

    /* give the mutex in this task. */
	kal_give_mutex( mptr );

    /* no error occurs, report PASS. */
    MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_pre_ipc_mutex3_thread
 * Functionality:
 *     main function of a task that will be used in ktest_ipc_mutex3
 * Parameters:
 *     noarg: argument transferred into the task.
 * Returns:
 *     void.
 * Note:
 *     this function is not a test case, and it's just to support
 *     ktest_ipc_mutex3 and ktest_ipc_mutex4.
 *****************************************************************************/
kal_mutexid _g_testmutex3_ptr1;
kal_mutexid _g_testmutex3_ptr2;
kal_uint32  _g_testmutex3_owner;
void ktest_pre_ipc_mutex3_thread( void *noarg )
{
    kal_uint32 prio = kal_get_mytask_priority();

    while( 1 )
    {
        /* take the mutex. if not success, wait for it. */
        kal_take_mutex( _g_testmutex3_ptr1 );

        /* if _g_testmutex3_owner is not 0, that means the value has been
         * modified by the other task. in our expectation, when one task has
         * taken the mutex, the other one can not take it and modify the value
         * of _g_testmutex3_owner. */
        if( _g_testmutex3_owner != 0 )
        {
            ktest_report_reset( KTEST_FAIL );
        }

        /* set the value of _g_testmutex3_owner. */
        _g_testmutex3_owner = prio;

        /* suspend self, then let the other task to run. */
        kal_sleep_task( rand2( 1, 5 ) );

        /* reset the value of _g_testmutex3_owner to 0. */
        _g_testmutex3_owner = 0;

        /* give the mutex. */
        kal_give_mutex( _g_testmutex3_ptr1 );
    }
}

/******************************************************************************
 * Name:
 *     ktest_ipc_mutex3
 * Functionality:
 *     test kal_take_mutex/kal_give_mutex in 2 tasks. as we expected, the two
 *     tasks can not enter the mutex at the same time.
 * Results:
 *     as we expected, the task with higher priority will always take the mutex,
 *     when it sleeps, the task with lower priority will try to take the mutex,
 *     but since the higher one has taken it, so the lower one will suspend and
 *     wait for the mutex. this will loop infinitly.
 *     so we start a timer (16 seconds) to check this, if they are still in loop
 *     when the timer expires, we think they work correctly, then report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_mutex3( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create the 1st mutex. if not success, report FAIL. */
	_g_testmutex3_ptr1 = kal_create_mutex( "tstmutx1" );
	if( _g_testmutex3_ptr1 == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
	}

    /* create the 2nd mutex. if not success, report FAIL. */
	_g_testmutex3_ptr2 = kal_create_mutex( "tstmutx2" );
	if( _g_testmutex3_ptr2 == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
	}

    /* create 2 tasks. note their priorities. */
    ktest_lib_createtask( 62, (kal_task_func_ptr) ktest_pre_ipc_mutex3_thread, NULL );
    ktest_lib_createtask( 61, (kal_task_func_ptr) ktest_pre_ipc_mutex3_thread, NULL );

    /* as we expected, the 2 tasks will loop infinitly. so we start a timer to
     * check this, if they are still in loop when the timer expires, we think
     * that they are working correctly, then report PASS. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* suspend self, to let other tasks to run. */
    kal_sleep_task( KAL_SUSPEND );

    /* if we come here, that means the 2 tasks don't run infinitly, so this is
     * not what we expected, report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_mutex4
 * Functionality:
 *     test kal_take_mutex/kal_give_mutex in 4 tasks. verify that no 2 tasks
 *     can enter the mutex at the same time.
 * Resutls:
 *     as we expected, the 4 tasks will run infinitly. in order to check this,
 *     we start a timer, if the tasks are still running when the timer expires,
 *     then we think that they work correctly, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_mutex4( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create the 1st mutex. */
	_g_testmutex3_ptr1 = kal_create_mutex( "tstmutx1" );
	if( _g_testmutex3_ptr1 == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
	}

    /* create the 2nd mutex. */
	_g_testmutex3_ptr2 = kal_create_mutex( "tstmutx2" );
	if( _g_testmutex3_ptr2 == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
	}

    /* create 4 tasks. as we expected, no 2 tasks can enter the mutex at the
     * same time. */
    ktest_lib_createtask( 62,
                          (kal_task_func_ptr) ktest_pre_ipc_mutex3_thread,
                          NULL );
    ktest_lib_createtask( 61,
                          (kal_task_func_ptr) ktest_pre_ipc_mutex3_thread,
                          NULL );
    ktest_lib_createtask( 64,
                          (kal_task_func_ptr) ktest_pre_ipc_mutex3_thread,
                          NULL );
    ktest_lib_createtask( 63,
                          (kal_task_func_ptr) ktest_pre_ipc_mutex3_thread,
                          NULL );

    /* start a timer to check whether the 4 tasks will run infinitly.
     * if they are still running when the timer expires, then we think they
     * work correctly, and report PASS in the timer handler. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* sleep self and let other tasks to run. */
    kal_sleep_task( KAL_SUSPEND );

    /* if we come here, that means the 4 tasks are not running infinitly. and
     * this is not what we expected. report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_pre_ipc_mutex5_thread
 * Functionality:
 *     the main function of tasks that used in ktest_ipc_mutex5.
 * Parameters:
 *     arg: arguments transferred into tasks.
 * Returns:
 *     void.
 * Note:
 *     this function is not a test case, it's just to support ktest_ipc_mutex5.
 *****************************************************************************/
void ktest_pre_ipc_mutex5_thread( const char *arg )
{
    if( strcmp( arg, "first" ) != 0 )
    {
        /* the "second" task will execute this flow. */
        kal_sleep_task( 20 );
        kal_take_mutex( _g_testmutex3_ptr1 );
        kal_sleep_task( 20 );
        kal_take_mutex( _g_testmutex3_ptr2 );
    }
    else
    {
        /* the "first" task will execute this flow. */
        kal_sleep_task( 1 );
        kal_take_mutex( _g_testmutex3_ptr2 );
        kal_sleep_task( 30 );
        kal_take_mutex( _g_testmutex3_ptr1 );
    }

    /* the task can not reach here, otherwise, report FAIL. */
    ktest_report( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_mutex5
 * Functionality:
 *     test mutex's deadlock behavior. that is, "first" task will take mutex2
 *     and "second" task will take mutex1, then "first" try to take mutex1 and
 *     "second" try to take mutex2, so a deadlock will happen.
 * Results:
 *     we start a timer to check the deadlock. if the two tasks are not out of
 *     the deadlock when the timer (16 seconds) expires, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_mutex5( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create mutex1 */
	_g_testmutex3_ptr1 = kal_create_mutex( "tstmutx1" );
	if( _g_testmutex3_ptr1 == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
	}

    /* create mutex2 */
	_g_testmutex3_ptr2 = kal_create_mutex( "tstmutx2" );
	if( _g_testmutex3_ptr2 == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
	}

    /* create 2 tasks, note that "first" has higher priority and "second" has
     * lower priority. */
    ktest_lib_createtask( 62,
                          (kal_task_func_ptr) ktest_pre_ipc_mutex5_thread,
                          "second" );
    ktest_lib_createtask( 61,
                          (kal_task_func_ptr) ktest_pre_ipc_mutex5_thread,
                          "first" );

    /* as we expected, a deadlock will happen. so we start a timer to check it,
     * if the 2 tasks are not out of deadlock when the timer expires, we think
     * the function is running correctly, report PASS in the timer handler. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* suspend self, let other tasks to run. */
    kal_sleep_task( KAL_SUSPEND );

    /* if we come here, that means no deadlock happens. and this is not what we
     * expected, report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_pre_sem1
 * Functionality:
 *     test the basic functionality of kal_create_sem.
 * Results:
 *     if create semaphores successfully, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_pre_sem1( kal_uint32 argc, void *argv )
{
	kal_semid mptr;
    int i;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create 24 semaphores. if any error occurs, report FAIL. */
	for( i = 0; i < 24; i++ )
    {
    	mptr = kal_create_sem( "tstsemph", i );
    	if( mptr == NULL )
        {
    	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
    	}
    }

    /* create one more semaphore. if error occurs, report FAIL. */
    mptr = kal_create_sem( "tstsemph", KTEST_MAX_SEM_CNT );
    if( mptr == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
    }

    /* no error occurs, report PASS. */
    MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_sem2
 * Functionality:
 *     test the basic functionality of kal_take_sem in single thread.
 *     that is, create a semphore with 3 count, then call kal_take_sem 3 times,
 *              there will be no error occurs as we expected.
 * Results:
 *     if kal_take_sem return a correct value immediatly, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_sem2( kal_uint32 argc, void *argv )
{
	kal_semid mptr;
    kal_status r;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create a semaphore with count 3. */
    mptr = kal_create_sem( "tstsemph", 3 );
    if( mptr == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
    }

    /* start a timer to check infinite wait. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_FAIL );

    /* call kal_take_sem for the 1st time. if not success, report FAIL. */
    r = kal_take_sem( mptr, KAL_INFINITE_WAIT );
    if( r != KAL_SUCCESS )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_take_sem failed" );
    }

    /* call kal_take_sem for the 2nd time. if not success, report FAIL. */
    r = kal_take_sem( mptr, KAL_INFINITE_WAIT );
    if( r != KAL_SUCCESS )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_take_sem failed" );
    }

    /* call kal_take_sem for the 3rd time. if not success, report FAIL. */
    r = kal_take_sem( mptr, KAL_INFINITE_WAIT );
    if( r != KAL_SUCCESS )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_take_sem failed" );
    }

    /* the semaphore's count will be 0 after take semaphore for 3 times.
     * and we will report PASS here. */
    MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_sem2a
 * Functionality:
 *     test kal_take_sem with KAL_NO_WAIT option.
 *     that is, create a semaphore with count 3, then call kal_take_sem for 3
 *              times, so the count will be 0 now. after this, we call
 *              kal_take_sem once more (with KAL_NO_WAIT option), as expected,
 *              it will return KAL_SEM_NOT_AVAILABLE immediately.
 * Results:
 *     if the last kal_take_sem return KAL_SEM_NOT_AVAILABLE immediately,
 *     report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_sem2a(kal_uint32 argc, void *argv)
{
	kal_semid mptr;
    kal_status r;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create a semaphore with count 3. */
    mptr = kal_create_sem( "tstsemph", 3 );
    if( mptr == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
    }

    /* start a timer to check infinite wait. but this will not happen here. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_FAIL );

    /* take the semaphore for the 1st time. the count will be 2 after this. */
    r = kal_take_sem( mptr, KAL_INFINITE_WAIT );
    if( r != KAL_SUCCESS )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_take_sem failed" );
    }

    /* take the semaphore for the 2nd time. the count will be 1 after this. */
    r = kal_take_sem( mptr, KAL_INFINITE_WAIT );
    if( r != KAL_SUCCESS )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_take_sem failed" );
    }

    /* take the semaphore for the 3rd time. the count will be 0 after this. */
    r = kal_take_sem( mptr, KAL_INFINITE_WAIT );
    if( r != KAL_SUCCESS )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_take_sem failed" );
    }

    /* try to take the semaphore for the 4th time (use KAL_NO_WAIT option).
     * since the count has been 0 now, so it will return KAL_SEM_NOT_AVAILABLE
     * as we expected. if not, report FAIL. */
    r = kal_take_sem( mptr, KAL_NO_WAIT );
    if( r != KAL_SEM_NOT_AVAILABLE )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_take_sem failed: expected KAL_SEM_NOT_AVAILABLE(%u), got %u",
                      KAL_SEM_NOT_AVAILABLE, r );
        return KTEST_FAIL;
    }

    /* it returns KAL_SEM_NOT_AVAILABLE as expected, report PASS. */
    MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_sem3
 * Functionality:
 *     test basic functionality of kal_take_sem with KAL_INFINITE_WAIT option.
 *     that is, create a semaphore with count 0, then call kal_take_sem with
 *              KAL_INFINITE_WAIT option. the task will be blocked as expected.
 * Results:
 *     we start a timer to check whether the task is blocked. if the task is
 *     still blocked when the timer expires, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_sem3( kal_uint32 argc, void *argv )
{
	kal_semid mptr;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create a semaphore with count 0. */
    mptr = kal_create_sem( "tstsemph", 0 );
    if( mptr == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
    }

    /* start a timer to check whether the task is blocked forever. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* try to take the semaphore with KAL_INFINITE_WAIT option. since the count
     * is 0 now, so the task will be blocked forever. */
    kal_take_sem( mptr, KAL_INFINITE_WAIT );

    /* if we come here, that means the task is not blocked. and this is not
     * what we expected, report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreach" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_sem3a
 * Functionality:
 *     test basic functionality of kal_take_sem with KAL_NO_WAIT option.
 *     that is, create a semaphore with count 0, then call kal_take_sem with
 *              KAL_NO_WAIT option. it will return KAL_SEM_NOT_AVAILABLE as we
 *              expected.
 * Results:
 *     if it returns KAL_SEM_NOT_AVAILABLE, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_sem3a( kal_uint32 argc, void *argv )
{
	kal_semid mptr;
	kal_status r;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create a semaphore with count 0. */
    mptr = kal_create_sem( "tstsemph", 0 );
    if( mptr == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
    }

    /* start a timer to check infinite wait. but this is not needed here. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_FAIL );

    /* try to take the semaphore with KAL_NO_WAIT option.
     * if it does not return KAL_SEM_NOT_AVAILABLE, report FAIL.*/
    r = kal_take_sem( mptr, KAL_NO_WAIT );
    if( r != KAL_SEM_NOT_AVAILABLE )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "kal_take_sem failed: expected KAL_SEM_NOT_AVAILABLE(%u), got %u",
                      KAL_SEM_NOT_AVAILABLE, r );
        return KTEST_FAIL;
    }

    /* if it returns KAL_SEM_NOT_AVAILABLE, report PASS. */
    MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_pre_ipc_sem4_thread
 * Functionality:
 *     the main function of tasks used in ktest_ipc_sem4 and ktest_ipc_sem6.
 * Parameters:
 *     arg: arguments transferred into the task.
 * Returns:
 *     void.
 *****************************************************************************/
kal_semid _g_test_sem1;
kal_mutexid _g_test_sem1_mutex;
int _g_test_sem1_count;
void ktest_pre_ipc_sem4_thread( void *arg )
{
    int max_count = (int) arg;
    int c;

    while( 1 )
    {
        /* take the semaphore with KAL_INFINITE_WAIT option. */
        kal_take_sem( _g_test_sem1, KAL_INFINITE_WAIT );

        /* take the mutex. note that it will wait infinitely if not success. */
        kal_take_mutex( _g_test_sem1_mutex );

        c = ++_g_test_sem1_count;

        /* give the mutex. */
        kal_give_mutex( _g_test_sem1_mutex );

        if( c < 0 || c > max_count )
        {
            ktest_report_reset3( KTEST_FAIL, KTEST_TCID, "invalid count" );
        }

        /* suspend self, in order to let other tasks to run. */
        kal_sleep_task( rand2( 1, 5 ) );

        /* take the mutex again. if not success, it will wait infinitely. */
        kal_take_mutex( _g_test_sem1_mutex );

        c = --_g_test_sem1_count;

        /* give the mutex again. */
        kal_give_mutex( _g_test_sem1_mutex );

        if( c < 0 || c > max_count )
        {
            ktest_report_reset3( KTEST_FAIL, KTEST_TCID, "invalid count" );
        }

        /* give the semaphore. */
        kal_give_sem( _g_test_sem1 );
    }
}

/******************************************************************************
 * Name:
 *     ktest_ipc_sem4
 * Functionality:
 *     test kal_take_sem/kal_give_sem in the environment with multiple tasks.
 *     create a semaphore with count 1, then create 6 tasks to compete for it.
 *     check the semaphore's owner counter is less than or equal to 1.
 * Results:
 *     if the 6 tasks are still running when the timer expires, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_sem4( kal_uint32 argc, void *argv )
{
    /* the semaphore's count is 1. */
	int initial_count = 1;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create the 1st semaphore. */
    _g_test_sem1 = kal_create_sem( "tstsemph", initial_count );
    if( _g_test_sem1 == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
    }

    /* create the 2nd semaphore. */
    _g_test_sem1_mutex = kal_create_mutex( "amutex" );
    if( _g_test_sem1_mutex == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
    }

    /* create 6 tasks to compete for the semaphore. */
    ktest_lib_createtask( 62, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );
    ktest_lib_createtask( 61, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );
    ktest_lib_createtask( 64, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );
    ktest_lib_createtask( 63, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );
    ktest_lib_createtask( 66, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );
    ktest_lib_createtask( 65, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );

    /* as we expected, the 6 tasks will run infinitely. so we start a timer to
     * check this, if they are still running when the timer expires, then we
     * report PASS in the timer handler.*/
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* suspend self, in order to let other tasks to run. */
    kal_sleep_task( KAL_SUSPEND );

    /* if we come here, that means the 6 tasks are not running infinitely. and
     * this is not what we expected. report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_sem5
 * Functionality:
 *     test kal_take_sem/kal_give_sem in the environment with multiple tasks.
 *     that is, create a semaphore with count 3, then create 6 tasks to compete
 *              for it. check the semaphore's owner counter is less than or
 *              equal to 3.
 * Results:
 *     as we expected, the 6 tasks will run infinitely when the timer expires.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_sem5( kal_uint32 argc, void *argv )
{
    /* the semaphore's count is 3. */
	int initial_count = 3;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create the 1st semaphore. */
    _g_test_sem1 = kal_create_sem( "tstsemph", initial_count );
    if( _g_test_sem1 == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
    }

    /* create the 2nd semaphore. */
    _g_test_sem1_mutex = kal_create_mutex( "amutex" );
    if( _g_test_sem1_mutex == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
    }

    /* create 6 tasks to compete for the semaphore. */
    ktest_lib_createtask( 62, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );
    ktest_lib_createtask( 61, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );
    ktest_lib_createtask( 64, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );
    ktest_lib_createtask( 63, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );
    ktest_lib_createtask( 66, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );
    ktest_lib_createtask( 65, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );

    /* as expected, the 6 tasks will run infinitely until the timer expires.
     * so we start a timer to check this case. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *)KTEST_PASS );

    /* suspend self to let other tasks to run. */
    kal_sleep_task( KAL_SUSPEND );

    /* if we come here, that means the 6 tasks are not running infinitely as
     * we expected, report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_pre_ipc_sem6_thread
 * Functionality:
 *     the main function of tasks that will be used in ktest_ipc_sem6.
 * Parameters:
 *     arg: arguments transferred into the task.
 * Returns:
 *     void.
 * Note:
 *     this function is not a test case. it's just to support ktest_ipc_sem6.
 *****************************************************************************/
void ktest_pre_ipc_sem6_thread( void *arg )
{
    int initial_count = (int) arg;
    int i;

    /* give semaphore for severial times. */
    for( i = 0; i < initial_count; i++ )
    {
        kal_give_sem( _g_test_sem1 );
    }

    /* suspend self to let other tasks to run. */
    kal_sleep_task( KAL_SUSPEND );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_sem6
 * Functionality:
 *     test give semaphore and take semaphore from different tasks.
 * Results:
 *     if a timeout happens, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_sem6( kal_uint32 argc, void *argv )
{
    /* the semaphore's count is 3. */
	kal_uint32 initial_count = 3;

	KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test give sem and take sem can be from different tasks";

	/* create a semaphore. and its count is 0 now. */
    _g_test_sem1 = kal_create_sem( "tstsemph", 0 );
    if( _g_test_sem1 == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
    }

    /* create a mutex. */
    _g_test_sem1_mutex = kal_create_mutex( "amutex" );
    if( _g_test_sem1_mutex == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
    }

    /* create a task to run ktest_pre_ipc_sem6_thread, note that it has the
     * highest priority of all the tasks below. Also, it will set the
     * semaphore's count to be 3 after it runs. */
    ktest_lib_createtask( 61, (kal_task_func_ptr) ktest_pre_ipc_sem6_thread, (void *) initial_count );

    /* create 6 tasks to compete for the semaphore. */
    ktest_lib_createtask( 62, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );
    ktest_lib_createtask( 64, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );
    ktest_lib_createtask( 63, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );
    ktest_lib_createtask( 66, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );
    ktest_lib_createtask( 65, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );
    ktest_lib_createtask( 67, (kal_task_func_ptr) ktest_pre_ipc_sem4_thread, (void *) initial_count );

    /* start a timer to check whether the 6 tasks will run infinitely.
     * if so, report PASS in the timer handler when it expires. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* suspend self to let other tasks run. */
    kal_sleep_task( KAL_SUSPEND );

    /* if we come here, that means the 6 tasks are not running infinitely.
     * and this is not what we expected, report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_pre_eg1
 * Functionality:
 *     test basic functionality of kal_create_event_group.
 * Results:
 *     if success, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_pre_eg1( kal_uint32 argc, void *argv )
{
	kal_eventgrpid mptr;
    int i;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create 24 event groups. if any error occurs, report FAIL. */
	for( i = 0; i < 24; i++ )
    {
    	mptr = kal_create_event_group( "tstevent" );
    	if( mptr == NULL )
        {
    	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                               "kal_create_mutex failed" );
    	}
    }

    /* no error occurs, report PASS. */
    MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_eg2
 * Functionality:
 *     test kal_create_event_group. verify that no event has been set after
 *     it's just created, and any tasks who want to retrieve it will be blocked
 *     forever.
 * Results:
 *     as we expected, a task that retrieve on an empty event group will be
 *     blocked forever. so we start a timer to check this, if it's blocked
 *     actually, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_eg2( kal_uint32 argc, void *argv )
{
	kal_eventgrpid mptr;
    kal_uint32 e;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an event group. */
	mptr = kal_create_event_group( "tstevent" );
	if( mptr == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
	}

    /* start a timer to check whether the task is blocked by retrieving from
     * an empty event group. */
	ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* try to retrieve events with KAL_SUSPEND option from an empty event group.
     * as expected, this will cause it be blocked forever. */
    kal_retrieve_eg_events( mptr, 0xFFFFFFFF, KAL_OR, &e, KAL_SUSPEND );

    /* we should not come here. otherwise, this means an error occurs,
     * report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_eg3
 * Functionality:
 *     test kal_retrieve_eg_events with KAL_OR option,
 *     verify that KAL_OR will retrieve all requested events.
 *                 and KAL_OR_CONSUME will retrieve and consume all requested
 *                 events.
 * Results:
 *     if any error occurs, report FAIL.
 *     else, report PASS.
 *****************************************************************************/
kal_int32 ktest_ipc_eg3( kal_uint32 argc, void *argv )
{
	kal_eventgrpid mptr;
    kal_uint32 e;
    kal_status r;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an event group. */
	mptr = kal_create_event_group( "tstevent" );
	if( mptr == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "kal_create_event_group failed" );
	}

    /* set events on this event group. */
	r = kal_set_eg_events( mptr, 0xe9113ef1, KAL_OR );
	if( r != KAL_SUCCESS )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_set_eg_events failed" );
	}

    /* retrieve events from this event group with KAL_OR option.
     * if not success, report FAIL. */
	r = kal_retrieve_eg_events( mptr, 0xFFFFFFFF, KAL_OR, &e, KAL_SUSPEND );
	if( r != KAL_SUCCESS || e != 0xe9113ef1 )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "kal_retrieve_eg_events failed" );
	}

    /* retrieve events with KAL_OR option again. */
	r = kal_retrieve_eg_events( mptr, 0xFFFFFFFF, KAL_OR, &e, KAL_SUSPEND );
	if( r != KAL_SUCCESS || e != 0xe9113ef1 )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "kal_retrieve_eg_events failed" );
	}

    /* as we expected, retrieve events with KAL_OR option will not clear the
     * events. so we can still retrieve it. */
	r = kal_retrieve_eg_events( mptr, 0xFFFFFFFF, KAL_OR_CONSUME, &e,
	                            KAL_SUSPEND );
	if( r != KAL_SUCCESS || e != 0xe9113ef1 )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "kal_retrieve_eg_events failed" );
	}

    /* KAL_OR_CONSUME will clear the events. so if we try to retrieve events
     * again, we will fail to retrieve it.
     * here, we start a timer to check this case. */
	ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* try to retrieve events again, and this will cause a infinite wait. */
    kal_retrieve_eg_events( mptr, 0xFFFFFFFF, KAL_OR, &e, KAL_SUSPEND );

    /* we should not come here, otherwise, report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_eg4
 * Functionality:
 *     test kal_set_eg_events with KAL_OR option will add new events.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_eg4( kal_uint32 argc, void *argv )
{
	kal_eventgrpid mptr;
    kal_uint32 e;
    kal_status r;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an event group. */
	mptr = kal_create_event_group( "tstevent" );
	if( mptr == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_event_group failed" );
	}

    /* set events on this event group. */
	r = kal_set_eg_events( mptr, 0xE9013EF0, KAL_OR );
	if( r != KAL_SUCCESS )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_set_eg_events failed" );
	}

    /* add new events on this event group with KAL_OR option.
     * after this, the events will be 0xE9113EF1. */
	r = kal_set_eg_events( mptr, 0x00100081, KAL_OR );
	if( r != KAL_SUCCESS )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_set_eg_events failed" );
	}

    /* retrieve events from the event group, and test whether the value is that
     * we expected. if not correct, report FAIL. */
	r = kal_retrieve_eg_events( mptr, 0xFFFFFFFF, KAL_OR, &e, KAL_SUSPEND );
	if( r != KAL_SUCCESS || e != 0xE9113EF1 )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_retrieve_eg_events failed" );
	}

    /* retrieve events again from the event group. its behavior is just like the
     * one above. */
	r = kal_retrieve_eg_events( mptr, 0xFFFFFFFF, KAL_OR, &e, KAL_SUSPEND );
	if( r != KAL_SUCCESS || e != 0xE9113EF1 )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_retrieve_eg_events failed" );
	}

    /* retrieve events with KAL_OR_CONSUME option.
     * as we expected, this will get the new value of events, then clear it. */
	r = kal_retrieve_eg_events( mptr, 0xFFFFFFFF, KAL_OR_CONSUME, &e,
	                            KAL_SUSPEND );
	if( r != KAL_SUCCESS || e != 0xE9113EF1 )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_retrieve_eg_events failed" );
	}

    /* since we have retrieved the events with KAL_OR_CONSUME option, so the
     * events will be cleared. if we still retrieve events from the event group,
     * it will not success. */
    /* start a timer to check the whether the next kal_retrieve_eg_events with
     * KAL_SUSPEND option will be blocked forever. if it's still blocked when
     * the timer expires, we think it works correctly, report PASS in the timer
     * handler. */
	ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );
    /* retrieve events with KAL_SUSPEND option. since the events have been
     * consumed, so the action will not success, and the task will be blocked
     * forever. */
    kal_retrieve_eg_events( mptr, 0xFFFFFFFF, KAL_OR, &e, KAL_SUSPEND );

    /* if we come here, that means the task is not blocked forever. and this is
     * not what we expected, report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_eg5
 * Functionality:
 *     test kal_set_eg_events with KAL_AND option will mask out events.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_eg5( kal_uint32 argc, void *argv )
{
	kal_eventgrpid mptr;
    kal_uint32 e;
    kal_status r;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an event group. */
	mptr = kal_create_event_group( "tstevent" );
	if( mptr == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_event_group failed" );
	}

    /* set events on this event group. after this, its value is 0xE9113EF1. */
	r = kal_set_eg_events( mptr, 0xE9113EF1, KAL_OR );
	if( r != KAL_SUCCESS )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_set_eg_events failed" );
	}

    /* set events with KAL_AND option. after this, its value is 0x00100081. */
	r = kal_set_eg_events( mptr, 0x00100081, KAL_AND );
	if( r != KAL_SUCCESS )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_set_eg_events failed" );
	}

    /* retrieve events with KAL_AND_CONSUME option. after this, its value is
     * 0x00100000. */
	r = kal_retrieve_eg_events( mptr, 0x00000081, KAL_AND_CONSUME, &e,
	                            KAL_NO_SUSPEND );
	if( r != KAL_SUCCESS || (e & 0x00000081) != 0x81 )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "kal_retrieve_eg_events1 failed" );
	}

    /* the events is 0x00100000 now, so the retrieve below will get nothing. */
	r = kal_retrieve_eg_events( mptr, ~0x00100000, KAL_OR_CONSUME, &e,
	                            KAL_NO_SUSPEND );
	if( r != KAL_NOT_PRESENT )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "kal_retrieve_eg_events2 failed" );
	}

    /* the events is 0x00100000 now. so the retrieve below will get 0x00100000,
     * then the events will be consumed. */
	r = kal_retrieve_eg_events( mptr, 0x00100000, KAL_AND_CONSUME, &e, KAL_SUSPEND );
	if( r != KAL_SUCCESS )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_retrieve_eg_events3 failed" );
	}

    /* the events have been cleared. so anyone want to retrieve it will get
     * nothing. */
    r = kal_retrieve_eg_events( mptr, 0xFFFFFFFF, KAL_OR, &e, KAL_NO_SUSPEND );
	if( r != KAL_NOT_PRESENT )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_retrieve_eg_events4 failed" );
	}

    /* no error occurs, report PASS. */
    MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_pre_enhmutex1
 * Functionality:
 *     test basic functionality of kal_create_enh_mutex.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_pre_enhmutex1( kal_uint32 argc, void *argv )
{
	kal_enhmutexid mptr;
    int i;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create 128 enhanced mutexes. if any error occurs, report FAIL. */
	for( i = 0; i < 128; i++ )
    {
    	mptr = kal_create_enh_mutex( "tstenmtx" );
    	if( mptr == NULL )
        {
    	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_enh_mutex failed" );
    	}
    }

    /* no error occurs and report PASS. */
    MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_enhmutex2
 * Functionality:
 *     test kal_take_enh_mutex/kal_give_enh_mutex in single task.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_enhmutex2( kal_uint32 argc, void *argv )
{
	kal_enhmutexid mptr;
    int i;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an enhanced mutex. */
	mptr = kal_create_enh_mutex( "tstenmtx" );
	if( mptr == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "kal_create_enh_mutex failed" );
	}

    /* start a timer to check whether a deadlock happens. if so, report FAIL. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_FAIL );

    /* take the enhanced mutex, then give it. do this for 128 times. */
    for( i = 0; i < 128; i++ )
    {
        kal_take_enh_mutex( mptr );
        kal_sleep_task( 10 );
        kal_give_enh_mutex( mptr );
    }

    /* no error occurs, report PASS. */
    MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, "" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_enhmutex3_thread
 * Functionality:
 *     main function of tasks that will be used in ktest_ipc_enhmutex3 and
 *     ktest_ipc_enhmutex4.
 * Parameters:
 *     noarg: arguments transferred into tasks. but we don't need it here.
 * Returns:
 *     void.
 * Note:
 *     this function is not a test case.
 *     it's just to support ktest_ipc_enhmutex3 and ktest_ipc_enhmutex4.
 *****************************************************************************/
static kal_enhmutexid g_enhmutex3_ptr;
static int g_enhmutex3_owner;
void ktest_ipc_enhmutex3_thread( void *noarg )
{
    kal_uint32 prio = kal_get_mytask_priority();

    while( 1 )
    {
        /* take the enhanced mutex. */
        kal_take_enh_mutex( g_enhmutex3_ptr );

        /* we use g_enhmutex3_owner to check whether another task can enter
         * the enhanced mutex. if it's not 0, that means another task has
         * entered the enhanced mutex. but this is not what we expected, so if
         * it happens, report FAIL. */
        if( g_enhmutex3_owner != 0 )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "error!" );
            ktest_reset_target();
        }

        /* set g_enhmutex3_owner's value. our aim is to indicate that the task
         * has entered the enhanced mutex. */
        g_enhmutex3_owner = prio;

        /* suspend self to let other tasks run. */
        kal_sleep_task( rand2( 1, 3 ) );

        /* before give the enhanced mutex, reset g_enhmutex3_owner's value. */
        g_enhmutex3_owner = 0;

        /* give the enhanced mutex. */
        kal_give_enh_mutex( g_enhmutex3_ptr );
    }
}

/******************************************************************************
 * Name:
 *     ktest_ipc_enhmutex3
 * Functionality:
 *     test kal_take_enh_mutex/kal_give_enh_mutex with 2 tasks.
 *     that is, use 2 tasks to take and give enhanced mutex, verify that no 2
 *              tasks can enter the critical section at the same time.
 * Results:
 *     as we expected, no 2 tasks can enter the critical section at the same
 *     time, so the 2 tasks will run infinitely.
 *     for this reason, we start a timer, if the 2 tasks is still running when
 *     the timer expires, we think that they work correctly on the enhanced
 *     mutex, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_enhmutex3( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an enhanced mutex. */
	g_enhmutex3_ptr = kal_create_enh_mutex( "tstenmtx" );
	if( g_enhmutex3_ptr == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "kal_create_enh_mutex failed" );
	}

    /* create 2 tasks to compete the enhanced mutex, note that they have
     * different priorities. */
    ktest_lib_createtask( 61, (kal_task_func_ptr) ktest_ipc_enhmutex3_thread,
                          NULL );
    ktest_lib_createtask( 62, (kal_task_func_ptr) ktest_ipc_enhmutex3_thread,
                          NULL );

    /* start a timer to check whether the 2 tasks will run infinitely on the
     * enhanced mutex. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* suspend self to let the 2 tasks run. */
    kal_sleep_task( KAL_SUSPEND );

    /* if we come here, that means the 2 tasks are not running infinitely on
     * the enhanced mutex. this is not what we expected, then report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_enhmutex4
 * Functionality:
 *     test kal_take_enh_mutex/kal_give_enh_mutex with 4 tasks.
 *     that is, use 4 tasks to take and give enhanced mutex, verify that no 2
 *              tasks can enter the critical section at the same time.
 * Results:
 *     as we expected, no 2 tasks can enter the critical section at the same
 *     time, so the 2 tasks will run infinitely.
 *     for this reason, we start a timer, if the 4 tasks is still running when
 *     the timer expires, we think that they work correctly on the enhanced
 *     mutex, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_enhmutex4( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an enhanced mutex. */
	g_enhmutex3_ptr = kal_create_enh_mutex( "tstenmtx" );
	if( g_enhmutex3_ptr == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_enh_mutex failed" );
	}

    /* create 4 tasks to compete the enhanced mutex. */
    ktest_lib_createtask( 61, (kal_task_func_ptr) ktest_ipc_enhmutex3_thread, NULL );
    ktest_lib_createtask( 62, (kal_task_func_ptr) ktest_ipc_enhmutex3_thread, NULL );
    ktest_lib_createtask( 63, (kal_task_func_ptr) ktest_ipc_enhmutex3_thread, NULL );
    ktest_lib_createtask( 64, (kal_task_func_ptr) ktest_ipc_enhmutex3_thread, NULL );

    /* since no 2 tasks can enter the enhanced mutex at the same time, so they
     * will run infinitely. we start a timer to check this case. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_PASS );

    /* suspend self to let other tasks run. */
    kal_sleep_task( KAL_SUSPEND );

    /* we should not come here, if so, report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_enhmutex5_thread
 * Functionality:
 *     this function is to support ktest_ipc_enhmutex5.
 * Parameters:
 *     arg: a value of "low", "mid" or "high".
 * Returns:
 *     void.
 * Note:
 *     this function is not a test case,
 *     it's just to support ktest_ipc_enhmutex5.
 *****************************************************************************/
static int scenario5_test_mutex;
static int scenario5_requestor;
static int scenario5_low_count;
static int scenario5_high_count;
static int scenario5_pi_count;
static int scenario5_preempt_count;
static int scenario5_highblock_count;
static void *scenario5_mutex;
static void (*scenario5_take)( void * );
static void (*scenario5_give)( void * );
void ktest_ipc_enhmutex5_thread( const char *arg )
{
    kal_uint32 prio = kal_get_mytask_priority();

    if( strcmp( arg, "low" ) == 0 )
    {
        /* the task with lower priority will do this. */
        while( 1 )
        {
            scenario5_requestor = prio;

            (*scenario5_take)( scenario5_mutex );
            scenario5_low_count++;
            busyloop_delay( rand2( 30, 70 ) );
            scenario5_requestor = 0;
            (*scenario5_give)( scenario5_mutex );

            kal_sleep_task( rand2( 10, 40 ) );
        }
    }
    else if( strcmp( arg, "high" ) == 0 )
    {
        /* the task with higher priority will do this. */
        kal_uint32 start_time, now;

        while( 1 )
        {
            scenario5_requestor = prio;
            kal_get_time( &start_time );

            (*scenario5_take)( scenario5_mutex );
            scenario5_high_count++;
            kal_get_time( &now );
            if( tick_diff( now, start_time ) >= 2 )
            {
            	scenario5_highblock_count++;
            }
            busyloop_delay( rand2( 30, 70 ) );
            (*scenario5_give)( scenario5_mutex );
            scenario5_requestor = 0;
            kal_sleep_task( rand2( 10, 40 ) );
        }
    }
    else
    {
        /* the task with middle priority will do this. */
        while( 1 )
        {
            int req;

            kal_sleep_task( 1 );
            req = scenario5_requestor;
            if( req == 0 )
            {
                continue;
            }
            if( req > prio )
            {
            	scenario5_preempt_count++;
            }
            if( req < prio )
            {
                scenario5_pi_count++;
            	if( scenario5_test_mutex == 0 )
                {
            	    ASSERT( scenario5_pi_count == 0 );
            	}
            }

        }
    }
}

/******************************************************************************
 * Name:
 *     monitor_enhmutex5
 * Functionality:
 *     this function is the handler of a timer that used in ktest_ipc_enhmutex5.
 * Parameters:
 *     arg: not used here.
 * Returns:
 *     void.
 * Note:
 *     this function is not a test case,
 *     it is just to support ktest_ipc_enhmutex5.
 *****************************************************************************/
void monitor_enhmutex5( const char *arg )
{
    /* timer handler for mutex. */
    if( strcmp( arg, "mutex" ) == 0 )
    {
        if( scenario5_pi_count )
        {
            ktest_report( KTEST_PASS, KTEST_TCID,
                          "Priority Inversion detected" );
        }
        else
        {
            ktest_report( KTEST_FAIL, KTEST_TCID,
                          "No Priority Inversion detected" );
        }
    }

    /* timer handler for enhanced mutex. */
    if( strcmp( arg, "enhmutex" ) == 0 )
    {
        if( scenario5_pi_count )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID,
                          "Priority Inversion detected" );
        }
        else
        {
            ktest_report( KTEST_PASS, KTEST_TCID,
                          "No Priority Inversion detected" );
        }
    }

    /* reset the target. */
    ktest_reset_target();
}

/******************************************************************************
 * Name:
 *     ktest_ipc_enhmutex5
 * Functionality:
 *     detect that mutex can't avoid priority inversion.
 * Results:
 *     if priority inversion occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_enhmutex5( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an enhanced mutex. */
	scenario5_mutex = kal_create_mutex( "tstmtx1" );
	if( scenario5_mutex == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
	}

    /* the function will be kal_take_mutex and kal_give_mutex.
     * note they are functions about mutex, not enhanced mutex. */
    scenario5_take = (void (*)(void *)) kal_take_mutex;
    scenario5_give = (void (*)(void *)) kal_give_mutex;
    scenario5_test_mutex = 1;
    busyloop_delay_base();

    /* create 3 tasks to test priority inversion. */
    ktest_lib_createtask( 65, (kal_task_func_ptr) ktest_ipc_enhmutex5_thread,
                          "low" );
    ktest_lib_createtask( 63, (kal_task_func_ptr) ktest_ipc_enhmutex5_thread,
                          "mid" );
    ktest_lib_createtask( 61, (kal_task_func_ptr) ktest_ipc_enhmutex5_thread,
                          "high" );

    /* start a timer to check whether priority inversion occurs. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) monitor_enhmutex5, "mutex" );

    /* suspend self to let other tasks run. */
    kal_sleep_task( KAL_SUSPEND );

    /* we should not come here. otherwise, report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_enhmutex6
 * Functionality:
 *     test that enhanced mutex can avoid priority inversion in the environment
 *     with 2 tasks.
 * Results:
 *     if no priority inversion occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_enhmutex6( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an enhanced mutex. */
	scenario5_mutex = kal_create_enh_mutex( "tstemtx1" );
	if( scenario5_mutex == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
	}

    /* use kal_take_enh_mutex and kal_give_enh_mutex.
     * note they are functions about enhanced mutex, note common mutex. */
    scenario5_take = (void (*)(void *)) kal_take_enh_mutex;
    scenario5_give = (void (*)(void *)) kal_give_enh_mutex;
    busyloop_delay_base();

    /* create 3 tasks to compete the enhanced mutex. */
    ktest_lib_createtask( 65, (kal_task_func_ptr) ktest_ipc_enhmutex5_thread,
                          "low" );
    ktest_lib_createtask( 63, (kal_task_func_ptr) ktest_ipc_enhmutex5_thread,
                          "mid" );
    ktest_lib_createtask( 61, (kal_task_func_ptr) ktest_ipc_enhmutex5_thread,
                          "high" );

    /* start a timer to check whether priority inversion occurs. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) monitor_enhmutex5, "enhmutex" );

    /* suspend self to let other tasks run. */
    kal_sleep_task( KAL_SUSPEND );

    /* we should not come here. otherwise, report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_enhmutex7
 * Functionality:
 *     test that enhanced mutex can avoid priority inversion in the environment
 *     with 5 tasks.
 * Results:
 *     if no priority inversion occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_enhmutex7( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create an enhanced mutex. */
	scenario5_mutex = kal_create_enh_mutex( "tstemtx1" );
	if( scenario5_mutex == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
	}

    /* use functions for enhanced mutex. */
    scenario5_take = (void (*)(void *)) kal_take_enh_mutex;
    scenario5_give = (void (*)(void *)) kal_give_enh_mutex;
    busyloop_delay_base();

    /* create 5 tasks to compete the enhanced mutex. */
    ktest_lib_createtask( 65, (kal_task_func_ptr) ktest_ipc_enhmutex5_thread,
                          "low" );
    ktest_lib_createtask( 64, (kal_task_func_ptr) ktest_ipc_enhmutex5_thread,
                          "mid1" );
    ktest_lib_createtask( 63, (kal_task_func_ptr) ktest_ipc_enhmutex5_thread,
                          "mid" );
    ktest_lib_createtask( 62, (kal_task_func_ptr) ktest_ipc_enhmutex5_thread,
                          "mid2" );
    ktest_lib_createtask( 61, (kal_task_func_ptr) ktest_ipc_enhmutex5_thread,
                          "high" );

    /* start a timer to check whether a priority inversion occurs. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) monitor_enhmutex5, "enhmutex" );

    /* suspend self to let other tasks run. */
    kal_sleep_task( KAL_SUSPEND );

    /* we should not come here. otherwise, report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     scenario8_func
 * Functionality:
 *     main function of tasks that will be used in ktest_ipc_enhmutex8.
 * Parameters:
 *     arg: a value of "low", "mid1", "mid2" or "high".
 * Returns:
 *     void.
 * Note:
 *     this function is not a test case.
 *     it's just to support ktest_ipc_enhmutex8.
 *****************************************************************************/
static int scenario8_requestor;
static int scenario8_low_count;
static int scenario8_mid1_count;
static int scenario8_high_count;
static int scenario8_pi_count;
static int scenario8_preempt_count;
static int scenario8_highblock_count;
static void *scenario8_mutex1;
static void *scenario8_mutex2;
static void (*scenario8_take)( void * );
static void (*scenario8_give)( void * );
static void scenario8_func( const char *arg )
{
    int prio = kal_get_mytask_priority();

    if( strcmp( arg, "low" ) == 0 )
    {
        /* the task with lower priority will do this. */
        while( 1 )
        {
            scenario8_requestor = prio;

            (*scenario8_take)( scenario8_mutex2 );
            scenario8_low_count++;
            busyloop_delay( rand2( 40, 50 ) );
            scenario8_requestor = 0;
            (*scenario8_give)( scenario8_mutex2 );

            kal_sleep_task( rand2( 5, 10 ) );
        }
    }
    else if( strcmp( arg, "mid1" ) == 0 )
    {
        /* the task with "mid1" priority will do this. */
        while( 1 )
        {
            scenario8_requestor = prio;

            (*scenario8_take)( scenario8_mutex1 );
            (*scenario8_take)( scenario8_mutex2 );
            scenario8_mid1_count++;
            busyloop_delay( rand2( 10, 40 ) );
            scenario8_requestor = 0;
            (*scenario8_give)( scenario8_mutex2 );
            (*scenario8_give)( scenario8_mutex1 );

            kal_sleep_task( rand2( 5, 10 ) );
        }
    }
    else if( strcmp( arg, "high" ) == 0 )
    {
        /* the task with highest priority will do this. */
        kal_uint32 start_time, now;

        while( 1 )
        {
            scenario8_requestor = prio;
            kal_get_time( &start_time );

            (*scenario8_take)( scenario8_mutex1 );
            scenario8_high_count++;
            kal_get_time( &now );
            if( tick_diff( now, start_time ) >= 2 )
            {
            	scenario8_highblock_count++;
            }
            busyloop_delay( rand2( 10, 15 ) );
            (*scenario8_give)( scenario8_mutex1 );
            scenario8_requestor = 0;
            kal_sleep_task( rand2( 50, 100 ) );
        }
    }
    else if( strcmp( arg, "mid2" ) == 0 )
    {
        /* the task with priority "mid2" will do this. */
        while( 1 )
        {
            int req;

            kal_sleep_task( 1 );
            req = scenario8_requestor;
            if( req == 0 )
            {
                continue;
            }
            if( req > prio )
            {
            	scenario8_preempt_count++;
            }
            if( req < prio )
            {
                scenario8_pi_count++;
            }

        }
    }
    else
    {
        /* invalid parameter. */
        ASSERT( 0 );
    }
}

/******************************************************************************
 * Name:
 *     monitor_enhmutex8
 * Functionality:
 *     timer handler used in ktest_ipc_enhmutex8.
 * Parameters:
 *     arg: a value of "mutex" or "enhmutex", it indicates that the handler is
 *          for mutex or enhanced mutex.
 * Returns:
 *     void.
 * Note:
 *     this function is not a test case, it's to support ktest_ipc_enhmutex8.
 *****************************************************************************/
void monitor_enhmutex8( const char *arg )
{
    /* timer handler for mutex. */
    if( strcmp( arg, "mutex" ) == 0 )
    {
        if( scenario8_pi_count )
        {
            ktest_report( KTEST_PASS, KTEST_TCID,
                          "Priority Inversion detected" );
        }
        else
        {
            ktest_report( KTEST_FAIL, KTEST_TCID,
                          "No Priority Inversion detected" );
        }
    }

    /* timer handler for enhanced mutex. */
    if( strcmp( arg, "enhmutex" ) == 0 )
    {
        if( scenario8_pi_count )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID,
                          "Priority Inversion detected" );
        }
        else
        {
            ktest_report( KTEST_PASS, KTEST_TCID,
                          "No Priority Inversion detected" );
        }
    }

    /* reset the target. */
    ktest_reset_target();
}

/******************************************************************************
 * Name:
 *     ktest_ipc_enhmutex8
 * Functionality:
 *     test that mutex can't avoid priority inversion in nested cases.
 * Results:
 *     if priority inversion occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_enhmutex8( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* create 2 mutexes. */
	scenario8_mutex1 = kal_create_mutex( "tstemtx1" );
	scenario8_mutex2 = kal_create_mutex( "tstemtx2" );
	if( scenario8_mutex1 == NULL || scenario8_mutex2 == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "kal_create_mutex failed" );
	}

    /* use functions about mutex. */
    scenario8_take = (void (*)(void *)) kal_take_mutex;
    scenario8_give = (void (*)(void *)) kal_give_mutex;
    busyloop_delay_base();

    /* create 4 tasks to compete mutex. */
    ktest_lib_createtask( 65, (kal_task_func_ptr) scenario8_func, "low" );
    ktest_lib_createtask( 64, (kal_task_func_ptr) scenario8_func, "mid1" );
    ktest_lib_createtask( 63, (kal_task_func_ptr) scenario8_func, "mid2" );
    ktest_lib_createtask( 61, (kal_task_func_ptr) scenario8_func, "high" );

    /* start a timer to check whether priority inversion occurs. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) monitor_enhmutex8, "mutex" );

    /* suspend self to let other tasks run. */
    kal_sleep_task( KAL_SUSPEND );

    /* we should not come here. otherwise, report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_ipc_enhmutex10
 * Functionality:
 *     test that enhanced mutex can avoid priority inversion in nested case.
 * Results:
 *     if no priority inversion occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_ipc_enhmutex10( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    /* creat 2 enhanced mutexes. */
	scenario8_mutex1 = kal_create_enh_mutex( "tstemtx1" );
	scenario8_mutex2 = kal_create_enh_mutex( "tstemtx2" );
	if( scenario8_mutex1 == NULL || scenario8_mutex2 == NULL )
    {
	    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "kal_create_enh_mutex failed" );
	}

    /* use functions about enhanced mutex. */
    scenario8_take = (void (*)(void *)) kal_take_enh_mutex;
    scenario8_give = (void (*)(void *)) kal_give_enh_mutex;
    busyloop_delay_base();

    /* creat 4 tasks to compete enhanced mutex. */
    ktest_lib_createtask( 65, (kal_task_func_ptr) scenario8_func, "low" );
    ktest_lib_createtask( 64, (kal_task_func_ptr) scenario8_func, "mid1" );
    ktest_lib_createtask( 62, (kal_task_func_ptr) scenario8_func, "mid2" );
    ktest_lib_createtask( 61, (kal_task_func_ptr) scenario8_func, "high" );

    /* start a timer to check whether priority inversion occurs. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) monitor_enhmutex8, "enhmutex" );

    /* suspend self to let other tasks run. */
    kal_sleep_task( KAL_SUSPEND );

    /* we should not come here. otherwise, report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

#define TASK_PRIORITY_TEST_MUTEX_LOW 65
#define TASK_PRIORITY_TEST_MUTEX_MID1 64
#define TASK_PRIORITY_TEST_MUTEX_MID2 63
#define TASK_PRIORITY_TEST_MUTEX_MID3 62
#define TASK_PRIORITY_TEST_MUTEX_HIGH 61

/******************************************************************************
 * a table that contains test cases in post-schedule stage of IPC module.
 * note that the ones wrapped with FIX_OSCAR_FAIL will not run on MoDIS, but
 *           they will run on target.
 *****************************************************************************/
const ktest_tc_struct ktest_tc_ipc_tbl[] =
{
    {ktest_ipc_mutex2, 0, NULL},
    {ktest_ipc_mutex3, 0, NULL},
    {ktest_ipc_mutex4, 0, NULL},
    {ktest_ipc_mutex5, 0, NULL},
    {ktest_ipc_sem2, 0, NULL},
    {ktest_ipc_sem2a, 0, NULL},
    {ktest_ipc_sem3, 0, NULL},
    {ktest_ipc_sem3a, 0, NULL},
    {ktest_ipc_sem4, 0, NULL},
    {ktest_ipc_sem5, 0, NULL},
    {ktest_ipc_sem6, 0, NULL},
    {ktest_ipc_eg2, 0, NULL},
    {ktest_ipc_eg3, 0, NULL},
    {ktest_ipc_eg4, 0, NULL},
    {ktest_ipc_eg5, 0, NULL},
    {ktest_ipc_enhmutex2, 0, NULL},
    {ktest_ipc_enhmutex3, 0, NULL},
    {ktest_ipc_enhmutex4, 0, NULL},
    {ktest_ipc_enhmutex5, 0, NULL},
    {ktest_ipc_enhmutex6, 0, NULL},
    {ktest_ipc_enhmutex7, 0, NULL},
    {ktest_ipc_enhmutex8, 0, NULL},
    {ktest_ipc_enhmutex10, 0, NULL},
    {ktest_ipc_allocate_ilm1, 0, NULL},
    {ktest_ipc_allocate_ilm2, 0, NULL},
    {ktest_ipc_allocate_ilm3, 0, NULL},
    {ktest_ipc_allocate_ilm4, 0, NULL},
    {ktest_ipc_allocate_ilm5, 0, NULL},
    {ktest_ipc_construct_local_para, 0, NULL},
    {ktest_ipc_hold_local_para, 0, NULL},
    {ktest_ipc_hold_local_para2, 0, NULL},
    {ktest_ipc_get_local_para_ptr, 0, NULL},
    {ktest_ipc_construct_peer_buff, 0, NULL},
    {ktest_ipc_hold_peer_buff, 0, NULL},
    {ktest_ipc_hold_peer_buff2, 0, NULL},
    {ktest_ipc_get_pdu_ptr, 0, NULL},
    {ktest_ipc_prepend_to_peer_buff, 0, NULL},
    {ktest_ipc_prepend_to_peer_buff2, 0, NULL},
    {ktest_ipc_append_to_peer_buff, 0, NULL},
    {ktest_ipc_append_to_peer_buff2, 0, NULL},
    {ktest_ipc_update_peer_buff_hdr, 0, NULL},
    {ktest_ipc_update_peer_buff_hdrE1, 0, NULL},
    {ktest_ipc_create_msgq, 0, NULL},
    {ktest_ipc_enqueue_msgq1, 0, NULL},
#ifdef FIX_OSCAR_FAIL
    /* this case will fail on OSCAR, because it call kal_enque_msg with infinite
     * wait option, but this is only supported on TARGET, not on OSCAR. */
    {ktest_ipc_enqueue_msgq2, 0, NULL},
#endif
    {ktest_ipc_enqueue_msgq3, 0, NULL},

#ifdef FIX_OSCAR_FAIL
    /* this case will fail on OSCAR, because it call kal_enque_msg with infinite
     * wait option, but this is only supported on TARGET, not on OSCAR. */
    {ktest_ipc_enqueue_msgq3a, 0, NULL},
#endif
    {ktest_ipc_enqueue_msgq4, 0, NULL},
#ifdef FIX_OSCAR_FAIL
    /* this case will fail on OSCAR, because it call kal_enque_msg with infinite
     * wait option, but this is only supported on TARGET, not on OSCAR. */
    {ktest_ipc_enqueue_msgq4a, 0, NULL},
#endif
    {ktest_ipc_dequeue_msgq1, 0, NULL},
    {ktest_ipc_dequeue_msgq1a, 0, NULL},
    {ktest_ipc_dequeue_msgq2, 0, NULL},
    {ktest_ipc_dequeue_msgq3, 0, NULL},
    {ktest_ipc_dequeue_msgq4, 0, NULL},
    {ktest_ipc_dequeue_msgqE1a, 0, NULL},
    {ktest_ipc_dequeue_msgqE1b, 0, NULL},
#ifdef FIX_OSCAR_FAIL
    /* the 3 cases below will fail on OSCAR, because they call kal_enque_msg
     * with infinite wait option, but this is only supported on TARGET, not on
     * OSCAR. */
    {ktest_ipc_testqueue1, 0, NULL},
    {ktest_ipc_testqueue2, 0, NULL},
    {ktest_ipc_testqueue3, 0, NULL},
#endif
    {ktest_ipc_create_intext_queue, 0, NULL},
    {ktest_ipc_msg_get_ext_queue_info, 0, NULL},
    {ktest_ipc_msg_send_ext_queue, 0, NULL},
    {ktest_ipc_msg_send_ext_queue_to_head, 0, NULL},
    {ktest_ipc_msg_send_int_queue, 0, NULL},
    {ktest_ipc_receive_msg_ext_q, 0, NULL},
    {ktest_ipc_receive_msg_int_q, 0, NULL},
    {ktest_ipc_msg_send_ext_queue2, 0, NULL},
    {ktest_ipc_msg_send_ext_queue_to_head2, 0, NULL},
    {ktest_ipc_msg_send_int_queue2, 0, NULL},
    {ktest_ipc_msg_send_ext_queue_full, 0, NULL},
    {ktest_ipc_msg_send_int_queue_full, 0, NULL},
    {ktest_ipc_msg_send_ext_queue_mt, 0, NULL},
};

/******************************************************************************
 * a table that contains test cases in pre-schedule stage of IPC module.
 * note that the ones wrapped with FIX_OSCAR_FAIL will not run on MoDIS, but
 *           they will run on target.
 *****************************************************************************/
const ktest_tc_struct ktest_pre_tc_ipc_tbl[] =
{
	{ktest_ipc_pre_mutex1, 0, NULL},
	{ktest_ipc_pre_sem1, 0, NULL},
	{ktest_ipc_pre_eg1, 0, NULL},
	{ktest_ipc_pre_enhmutex1, 0, NULL},
};

/******************************************************************************
 * caculate the total number of all test cases of IPC moduel in post-schedule
 * stage.
 *****************************************************************************/
kal_uint32 ktest_tc_ipc_num( void )
{
   	return sizeof( ktest_tc_ipc_tbl ) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * caculate the total number of all test cases of IPC module in pre-schedule
 * stage.
 *****************************************************************************/
kal_uint32 ktest_pre_tc_ipc_num( void )
{
	return sizeof( ktest_pre_tc_ipc_tbl ) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * register test case table (pre-schedule and post-schedule).
 * set the total number of test cases in each stage of IPC module.
 *****************************************************************************/
void ktest_ipc_init( kal_uint32 mod )
{
	tc_all_tbls[mod] = ktest_tc_ipc_tbl;
	pre_tc_all_tbls[mod] = ktest_pre_tc_ipc_tbl;

	tc_modules_num[mod] = ktest_tc_ipc_num();
	pre_tc_modules_num[mod] = ktest_pre_tc_ipc_num();
}

#endif  /*__KTEST__*/
