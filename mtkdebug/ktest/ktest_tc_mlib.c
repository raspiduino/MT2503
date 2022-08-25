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
 *   ktest_tc_mlib.c
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
#include "mlib_dll.h"
#include "lcd_ip_cqueue.h"

/******************************************************************************
 * each test case should return a value of kal_int32 type, but most test cases
 * call ktest_report at the end but forget to return a value.
 * so we define this macro to do this.
 *****************************************************************************/
#define MY_REPORT_RETURN(code, tcname, fmt) \
    ktest_report(code, tcname, fmt);\
    return code;

typedef struct test_struct{
	list_node  t_node;
	kal_uint32 t_data;
} test_struct;

kal_uint32 test_count = 0;

/******************************************************************************
 * a macro that help to use LCD_IP_CQUEUE.
 *****************************************************************************/
typedef LCD_IP_CQUEUE(kal_uint32, 1) test_c_queue;

/******************************************************************************
 * Name:
 *     ktest_lcd_cqueue
 * Functionality:
 *     test basic functioanlity of LCD_IP_CQUEUE_INSERT and LCD_IP_CQUEUE_REMOVE.
 * Results:
 *     if the content of the queue is correct when insert or remove an element,
 *     report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_lcd_cqueue( kal_uint32 argc, void *argv )
{
    test_c_queue *c_queue_ptr;
    kal_uint32 total, item;
    ktest_res result;

    total = item = 0;
    result = KTEST_PASS;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "lcd_ip_cqueue.h";

    /* allocate system memory for the queue. */
    c_queue_ptr =
        (test_c_queue *) kal_sys_mem_alloc( sizeof( test_c_queue )
                                            + ( sizeof( kal_uint32 ) * (10) )
                                          );

    /* init the queue, note that its capacity is 11. */
    LCD_IP_CQUEUE_INIT_N(*c_queue_ptr, 11);

    /* insert 5 elements into the queue, they are: 0, 1, 2, 3, 4. */
    LCD_IP_CQUEUE_INSERT(*c_queue_ptr, 0);
    LCD_IP_CQUEUE_INSERT(*c_queue_ptr, 1);
    LCD_IP_CQUEUE_INSERT(*c_queue_ptr, 2);
    LCD_IP_CQUEUE_INSERT(*c_queue_ptr, 3);
    LCD_IP_CQUEUE_INSERT(*c_queue_ptr, 4);

    /* check whether the number of items is correct. */
    LCD_IP_CQUEUE_NUM_OF_ITEMS( *c_queue_ptr, total );
    if( total != 5 )
    {
        result = KTEST_FAIL;
    }

    /* remove the first element from the queue. */
    LCD_IP_CQUEUE_REMOVE( *c_queue_ptr, item );
    if( item != 0 )
    {
        result = KTEST_FAIL;
    }

    /* remove the second element from the queue. */
    LCD_IP_CQUEUE_REMOVE( *c_queue_ptr, item );
    if( item != 1 )
    {
        result = KTEST_FAIL;
    }

    /* report the result. */
    MY_REPORT_RETURN( result, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_cmp_func
 * Functionality:
 *     help to compare two list_node.
 * Parameters:
 *     a: the first list node to compare.
 *     b: the second list node to compare.
 *     user_para: parameters may be used in comparison.
 * Returns:
 *     if a equals with b, return 0.
 *     if a is bigger than b, return 1.
 *     if a is less than b, return -1.
 * Note:
 *     this is not a test case, it is designed just to compare two list nodes.
 *****************************************************************************/
static kal_int32 ktest_cmp_func( const list_node *a, const list_node *b,
                                 void *user_para )
{
	test_struct *ts_a = NULL;
	test_struct *ts_b = NULL;
	if( a == NULL || b == NULL )
	{
		ASSERT( 0 );
	}

    /* convert the list nodes to the type of test_struct. */
	ts_a = List2Container( a, test_struct, t_node );
	ts_b = List2Container( b, test_struct, t_node );

    /* compare the two list nodes. */
	if( ts_a->t_data > ts_b->t_data )
	{
		return 1;
	}
	else if( ts_a->t_data == ts_b->t_data )
	{
        return 0;
    }
    else
    {
        return -1;
    }
}

/******************************************************************************
 * Name:
 *     ktest_cb_func
 * Functionality:
 *     increase test_count by one each time.
 * Parameters:
 *     a: not used here.
 *     para: note used here.
 * Returns:
 *     this function should return a value of kal_int32 type, but it returns
 *     nothing now, so this is what we need to fix in the furture.
 * Note:
 *     this is not a test case.
 *****************************************************************************/
static kal_int32 ktest_cb_func( list_node *a, void *para )
{
	test_count++;
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_insert_null
 * Functionality:
 *     test basic functionality of mlib_dll_insert_node.
 *     note that the new node that we want to insert to the list is null.
 * Results:
 *     since it's a null node, so mlib_dll_insert_node will return a value less
 *     than 0. if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_insert_null( kal_uint32 argc, void *argv )
{
    kal_int32 r_value;
   	list_node *header = NULL;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_insert_node insert a null to a list";

    /* insert a new node into the list. we must note that the new node is null.
     * so the return value should be less than 0. */
    r_value = mlib_dll_insert_node( &header, NULL, ktest_cmp_func, NULL );
    if( r_value < 0 )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_insert_no_cmp_func
 * Functionality:
 *     test basic functionality of mlib_dll_insert_node.
 *     insert a node to the list without cmp_func.
 * Results:
 *     since no cmp_func is provided when calling mlib_dll_insert_node, so the
 *     return value should be less than 0.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_insert_no_cmp_func( kal_uint32 argc, void *argv )
{
    kal_int32 r_value;
   	list_node *header = NULL;
   	test_struct ts1;
   	ts1.t_data = 5;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_insert_node insert a node to a list without cmp_func";

    /* try to insert a new node, but the cmp_func is null.
     * as we expected, a value less than 0 will be returned. */
    r_value = mlib_dll_insert_node( &header, &(ts1.t_node), NULL, NULL );
    if( r_value < 0 )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_insert_to_null
 * Functionality:
 *     test basic functionality of mlib_dll_insert_node.
 *     insert a node to an empty list.
 * Results:
 *     if the node is the only one in the list after insertion, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_insert_to_null( kal_uint32 argc, void *argv )
{
    kal_int32 r_value;
   	list_node *header = NULL;
   	test_struct ts1;
   	ts1.t_data = 5;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_insert_node insert a node to an empty list";

    /* insert a new node to an empty list.
     * this can be successful and the node which was just inserted is the only
     * one in the list now. */
    r_value = mlib_dll_insert_node( &header, &(ts1.t_node), ktest_cmp_func, NULL );
    if( ( header == &(ts1.t_node) ) && ( r_value == 0 ) )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_insert_to_head
 * Functionality:
 *     test basic functionality of mlib_dll_insert_node.
 *     insert two nodes to the list ( which is null at the beginning ), then
 *     test whether their order is correct.
 * Results:
 *     if the order of nodes that we have just insert to the list is correct,
 *     report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_insert_to_head( kal_uint32 argc, void *argv )
{
    kal_int32 r_value;
   	list_node *header = NULL;
   	test_struct ts1, ts2;
   	test_struct *p_ts1 = NULL;
   	test_struct *p_ts2 = NULL;
   	ts1.t_data = 14;
   	ts2.t_data = 6;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_insert_node insert a node to head of a list";

    /* insert a node into list, the list is empty now. */
    r_value = mlib_dll_insert_node( &header, &( ts1.t_node ), ktest_cmp_func,
                                    NULL );

    /* insert another node into list, we should notice that it will be inserted
     * to the head of list. */
    r_value = mlib_dll_insert_node( &header, &( ts2.t_node ), ktest_cmp_func,
                                    NULL );

    /* check whether the content of list is correct after insert two nodes into
     * it. */
    if( header != NULL )
    {
        /* as we expected, there should be two nodes in the list.
         * then we will get the value of them, and check whether they are in
         * ascending order. */
    	p_ts1 = List2Container( header, test_struct, t_node );
    	p_ts2 = List2Container( header->next, test_struct, t_node);
    	if( p_ts2->t_data < p_ts1->t_data )
    	{
            /* not in ascending order, this is not what we expected,
             * report FAIL here. */
    		MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    	}
    	else
    	{
            /* in ascending order, this is what we expected. report PASS. */
    		MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    	}
    }
    else
    {
        /* since we have inserted two nodes into the list, so it should not
         * be empty. if it's empty, report FAIL. */
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_insert_to_tail
 * Functionality:
 *     test basic functionality of mlib_dll_insert_node.
 *     insert a node to tail of a list.
 * Results:
 *     if the content of list is correct after insert two nodes into it, report
 *     PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_insert_to_tail( kal_uint32 argc, void *argv )
{
    kal_int32 r_value;
   	list_node *header = NULL;
   	test_struct ts1,ts2;
   	test_struct *p_ts1 = NULL;
   	test_struct *p_ts2 = NULL;
   	ts1.t_data = 6;
   	ts2.t_data = 15;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_insert_node insert a node to tail of a list";

    /* insert a node into list, the list is empty now. */
    r_value = mlib_dll_insert_node( &header, &( ts1.t_node ), ktest_cmp_func,
                                    NULL );

    /* insert another node into list, we should notice that it will be inserted
     * to the tail of list. */
    r_value = mlib_dll_insert_node( &header, &( ts2.t_node ), ktest_cmp_func, NULL );

    /* check whether the content of list is correct after insert two nodes into
     * it. */
    if( header != NULL )
    {
    	p_ts1 = List2Container( header, test_struct, t_node );
    	p_ts2 = List2Container( header->next, test_struct, t_node );
    	if( p_ts2->t_data < p_ts1->t_data )
    	{
    		MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    	}
    	else
    	{
    		MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    	}
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_insert_to_mid
 * Functionality:
 *     test basic functionality of mlib_dll_insert_node.
 *     insert a node to middle of a list.
 * Results:
 *     if the content of list is correct after insert two nodes into it, report
 *     PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_insert_to_mid( kal_uint32 argc, void *argv )
{
    kal_int32 r_value;
    kal_int32 num = 0;
   	list_node *header = NULL;
   	list_node *tmp_node = NULL;
   	test_struct ts1,ts2,ts3;
   	test_struct *p_ts1 = NULL;
   	test_struct *p_ts2 = NULL;
   	ts1.t_data = 14;
   	ts2.t_data = 6;
   	ts3.t_data = 11;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_insert_node insert a node to mid of a list";

    /* insert the 1st node into list, the list is empty now. */
    r_value = mlib_dll_insert_node( &header, &( ts1.t_node ), ktest_cmp_func,
                                    NULL );

    /* insert the 2nd node into list, and it will be inserted to the head of
     * list. */
    r_value = mlib_dll_insert_node( &header, &( ts2.t_node ), ktest_cmp_func,
                                    NULL );

    /* insert the 3rd node into list, we should notice that it will be inserted
     * in the middle of list. */
    r_value = mlib_dll_insert_node( &header, &( ts3.t_node ), ktest_cmp_func,
                                    NULL );

    /* check whether the content of list is correct. */
    tmp_node = header;
	if( tmp_node != NULL )
    {
        /* check the order of all nodes. */
		while( tmp_node->next != header )
		{
			p_ts1 = List2Container( tmp_node, test_struct, t_node );
    		p_ts2 = List2Container( tmp_node->next, test_struct, t_node );
			if( p_ts2->t_data < p_ts1->t_data )
			{
				MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
			}
			tmp_node = tmp_node->next;
		}
		MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
	}
  	else
  	{
  		MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
  	}
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_delete_null
 * Functionality:
 *     test basic functionality of mlib_dll_delete_node.
 *     try to delete null from a list.
 * Results:
 *     since we try to delete null from a list, KAL_FALSE will be returned.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_delete_null( kal_uint32 argc, void *argv )
{
    kal_bool r_value;
   	list_node *header = NULL;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_delete_node delete null from a list";

    /* try to delete null from a list. this will cause KAL_FALSE be returned. */
    r_value = mlib_dll_delete_node( &header, NULL );
    if( r_value == KAL_FALSE )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_delete_not_on_list
 * Functionality:
 *     test basic functionality of mlib_dll_delete_node.
 *     delete a node not on list.
 * Results:
 *     delete a node not on list will return KAL_FALSE.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_delete_not_on_list( kal_uint32 argc, void *argv )
{
    kal_int32 r_value;
   	list_node *header = NULL;
   	test_struct ts1,ts2;
   	ts1.t_data = 5;
	ts2.t_data = 25;
	ts2.t_node.prev = NULL;
	ts2.t_node.next = NULL;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_delete_node delete a node not on list";

    /* insert a node into list.
     * after this step, the list will have only 1 item. */
    r_value = mlib_dll_insert_node( &header, &( ts1.t_node ), ktest_cmp_func,
                                    NULL );

    /* try to delete a node not on list.
     * this will cause KAL_FALSE be returned. */
    r_value = mlib_dll_delete_node( &header, &( ts2.t_node ) );
    if( r_value == KAL_FALSE )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_delete_single
 * Functionality:
 *     test basic functionality of mlib_dll_delete_node.
 *     delete the only node on list.
 * Results:
 *     if success, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_delete_single( kal_uint32 argc, void *argv )
{
    kal_int32 r_value;
   	list_node *header = NULL;
   	test_struct ts1;
   	ts1.t_data = 5;
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_delete_node delete the only node on list";

    /* insert a node into list. after this step, the list will have only one
     * item in it. */
    r_value = mlib_dll_insert_node( &header, &( ts1.t_node ), ktest_cmp_func,
                                    NULL );

    /* delete the only one node from the list. */
    r_value = mlib_dll_delete_node( &header, &( ts1.t_node ) );
    if( header == NULL )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_delete_header
 * Functionality:
 *     test basic functionality of mlib_dll_delete_node.
 *     delete the header node from list.
 * Results:
 *     if success, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_delete_header( kal_uint32 argc, void *argv )
{
    kal_int32 r_value;
   	list_node *header = NULL;
   	list_node *saved_header = NULL;
   	test_struct ts1,ts2,ts3;
   	ts1.t_data = 35;
   	ts2.t_data = 15;
   	ts3.t_data = 17;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_delete_node delete header node on list";

    /* insert 3 nodes into list. after this step, the header node will be the
     * one with value "15". */
    r_value = mlib_dll_insert_node( &header, &( ts1.t_node ), ktest_cmp_func,
                                    NULL );
    r_value = mlib_dll_insert_node( &header, &( ts2.t_node ), ktest_cmp_func,
                                    NULL );
    r_value = mlib_dll_insert_node( &header, &( ts3.t_node ), ktest_cmp_func,
                                    NULL );

    /* delete the header node from list. */
    saved_header = header->next;
    r_value = mlib_dll_delete_node( &header, &( ts2.t_node ) );
    if( (header == saved_header) && (r_value == KAL_TRUE) )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_delete_mid
 * Functionality:
 *     test basic functionality of mlib_dll_delete_node.
 *     delete a node in the middle of list.
 * Results:
 *     if success, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_delete_mid( kal_uint32 argc, void *argv )
{
    kal_int32 r_value;
   	list_node *header = NULL;
   	list_node *saved_prev = NULL;
   	list_node *saved_next = NULL;
   	test_struct ts1,ts2,ts3;
   	ts1.t_data = 35;
   	ts2.t_data = 15;
   	ts3.t_data = 17;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_delete_node delete middle node on list";

    /* insert 3 nodes into list, after this step, the middle node in list will
     * be the one with value "17". */
    r_value = mlib_dll_insert_node( &header, &( ts1.t_node ), ktest_cmp_func,
                                    NULL );
    r_value = mlib_dll_insert_node( &header, &( ts2.t_node ), ktest_cmp_func,
                                    NULL );
    r_value = mlib_dll_insert_node( &header, &( ts3.t_node ), ktest_cmp_func,
                                    NULL );

    /* try to delete the node in the middle of list. */
    saved_prev = (ts3.t_node).prev;
    saved_next = (ts3.t_node).next;
    r_value = mlib_dll_delete_node( &header, &(ts3.t_node) );
    if( (saved_prev->next == saved_next) && (saved_next->prev == saved_prev) )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_delete_tail
 * Functionality:
 *     test basic functionality of mlib_dll_delete_node.
 *     delete tail node from a list.
 * Results:
 *     if success, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_delete_tail( kal_uint32 argc, void *argv )
{
    kal_int32 r_value;
   	list_node *header = NULL;
   	list_node *saved_tail = NULL;
   	test_struct ts1,ts2,ts3;
   	ts1.t_data = 35;
   	ts2.t_data = 15;
   	ts3.t_data = 17;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_delete_node delete tail node on list";

    /* insert 3 nodes into list. after this step, the tail node is the one with
     * value "35" ( ts1.t_node ). */
    r_value = mlib_dll_insert_node( &header, &( ts1.t_node ), ktest_cmp_func,
                                    NULL );
    r_value = mlib_dll_insert_node( &header, &( ts2.t_node ), ktest_cmp_func,
                                    NULL );
    r_value = mlib_dll_insert_node( &header, &( ts3.t_node ), ktest_cmp_func,
                                    NULL );

    /* try to delete tail node from the list. */
    saved_tail = (header->prev)->prev;
    r_value = mlib_dll_delete_node( &header, &( ts1.t_node ) );

    if( ( (header->prev) == saved_tail ) && ( r_value == KAL_TRUE ) )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_double_delete
 * Functionality:
 *     test basic functionality of mlib_dll_delete_node.
 *     double delete a node on list.
 * Results:
 *     as we expect, delete a node will remove it from the list. so when we try
 *     to delete it for the second time, because it is not in the list already,
 *     so KAL_FALSE will be returned to indicate an error.
 *     if return KAL_FALSE, report PASS.
 *     else, erport FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_double_delete( kal_uint32 argc, void *argv )
{
    kal_int32 r_value;
   	list_node *header = NULL;
   	test_struct ts1;
   	ts1.t_data = 5;
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_delete_node double delete a node on list";

    /* insert a node into the list. after this step, the list will have only
     * one node in it. */
    r_value = mlib_dll_insert_node( &header, &( ts1.t_node ), ktest_cmp_func,
                                    NULL );

    /* delete the node for the 1st time. */
    r_value = mlib_dll_delete_node( &header, &( ts1.t_node ) );

    /* after the step above, the list has no items in it at all. so when we try
     * to delete it for the 2nd time, KAL_FALSE will be returned. */
    r_value = mlib_dll_delete_node( &header, &( ts1.t_node ) );
    if( r_value == KAL_FALSE )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_split_null_1
 * Functionality:
 *     test basic functionality of mlib_dll_split_list.
 *     split an empty list.
 * Results:
 *     if it returns null, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_split_null_1( kal_uint32 argc, void *argv )
{
    list_node *r_ptr;
   	list_node *header = NULL;
   	test_struct ts1;
   	ts1.t_data = 5;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_split_list split an empty list.";

    /* try to split an empty list. */
    r_ptr = mlib_dll_split_list( &header, &( ts1.t_node ), ktest_cmp_func,
                                 NULL );

    /* as we expect, the return value should be null. */
    if( r_ptr == NULL )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_split_null_2
 * Functionality:
 *     test basic functionality of mlib_dll_split_list.
 *     split a list without cmp_func.
 * Results:
 *     if it returns null, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_split_null_2( kal_uint32 argc, void *argv )
{
    list_node *r_ptr;
   	list_node *header = NULL;
   	test_struct ts1,cmp_ts;
   	ts1.t_data = 5;
   	cmp_ts.t_data = 12;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_split_list split a list without cmp_func";

    /* insert a node into list. if success, try to split the list without
     * cmp_func. */
    if( mlib_dll_insert_node( &header, &(ts1.t_node), ktest_cmp_func, NULL )
        == 0 )
    {
        /* insert successfully, then try to split the list. note that the
         * cmp_func is NULL. */
	    r_ptr = mlib_dll_split_list( &header, &( cmp_ts.t_node ), NULL, NULL );
	    if( r_ptr == NULL )
	    {
	    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
	    }
	    else
	    {
	    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
	    }
    }
    else
    {
        /* insert failed. so we can not test mlib_dll_split_list now. */
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_split_head
 * Functionality:
 *     test basic functionality of mlib_dll_split_node.
 *     split from the header of list.
 * Results:
 *     split from the header of list will return a NULL.
 *     if it returns null actually, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_split_head( kal_uint32 argc, void *argv )
{
    list_node *r_ptr = (list_node *) 4;
   	list_node *header = NULL;

   	test_struct ts1,ts2,ts3,cmp_ts;
   	ts1.t_data = 35;
   	ts2.t_data = 15;
   	ts3.t_data = 17;
   	cmp_ts.t_data = 1;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_delete_node split from header";

    /* insert 3 nodes into list. */
    mlib_dll_insert_node( &header, &( ts1.t_node ), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &( ts2.t_node ), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &( ts3.t_node ), ktest_cmp_func, NULL );

    /* split the list. note that the cmp_node is not in the list at all, so
     * we will split the list from its header node, and a NULL will be returned.
     */
    r_ptr = mlib_dll_split_list( &header, &( cmp_ts.t_node ), ktest_cmp_func,
                                 NULL );
    if( r_ptr == NULL )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_split_tail
 * Functionality:
 *     test basic functionality of mlib_dll_split_node.
 *     split a list from its tail node.
 * Results:
 *     as we expect, it will return the whole list, and the original header
 *     pointer will be set to be NULL.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_split_tail( kal_uint32 argc, void *argv )
{
    list_node *r_ptr = (list_node *) 4;
   	list_node *header = NULL;
	list_node *saved_header = NULL;
   	test_struct ts1,ts2,ts3,cmp_ts;
   	ts1.t_data = 35;
   	ts2.t_data = 5;
   	ts3.t_data = 17;
   	cmp_ts.t_data = 40;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_delete_node split from tail";

    /* insert 3 nodes into the list. */
    mlib_dll_insert_node( &header, &( ts1.t_node ), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &( ts2.t_node ), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &( ts3.t_node ), ktest_cmp_func, NULL );

    /* split the list from its tail node. */
	saved_header = header;
    r_ptr = mlib_dll_split_list( &header, &( cmp_ts.t_node ), ktest_cmp_func,
                                 NULL );
    if( r_ptr == saved_header && header == NULL )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_split_mid
 * Functionality:
 *     test basic functionality of mlib_dll_split_node.
 *     split a list from its middle part.
 * Results:
 *     this will split the list into 2 parts which are seperated by cmp_node.
 *     then the first part will be returned and the original header pointer will
 *     point to the beginning of the second part.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_split_mid( kal_uint32 argc, void *argv )
{
    list_node *r_ptr = (list_node *) 4;
   	list_node *header = NULL;
	list_node *saved_header = NULL;
   	test_struct ts1,ts2,ts3,cmp_ts;
   	test_struct *chk_ts1,*chk_ts2;
   	ts1.t_data = 35;
   	ts2.t_data = 5;
   	ts3.t_data = 17;
   	cmp_ts.t_data = 21;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_delete_node split from middle";

    /* insert 3 nodes into the list. */
    mlib_dll_insert_node( &header, &( ts1.t_node ), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &( ts2.t_node ), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &( ts3.t_node ), ktest_cmp_func, NULL );

    /* split the list into 2 parts. the 1st part will contain the nodes with
     * value "5" and "17", and the 2nd part will contain the nodes with value
     * "35". */
    r_ptr = mlib_dll_split_list( &header, &( cmp_ts.t_node ), ktest_cmp_func,
                                 NULL );

    /* check whether the result is correct. */
    chk_ts1 = List2Container( r_ptr->prev, test_struct, t_node );
    chk_ts2 = List2Container( header, test_struct, t_node );

    if( (chk_ts1->t_data <= cmp_ts.t_data)
        && (cmp_ts.t_data <= chk_ts2->t_data) )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_append_null
 * Functionality:
 *     test basic functionality of mlib_dll_append_list.
 *     append a null to the list.
 * Results:
 *     if nothing happens and the list is still the same as original, report
 *     PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_append_null( kal_uint32 argc, void *argv )
{
    kal_int32 r_value;
   	list_node *header = NULL;
   	list_node *app_header = NULL;
   	list_node *save_tail = NULL;
   	test_struct ts1,ts2;
   	ts1.t_data = 14;
   	ts2.t_data = 6;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_append_list append a null to another list";

    /* insert 2 nodes into the list. */
    r_value = mlib_dll_insert_node( &header, &( ts1.t_node ), ktest_cmp_func,
                                    NULL );
    r_value = mlib_dll_insert_node( &header, &( ts2.t_node ), ktest_cmp_func,
                                    NULL );

    /* append a null to the list. */
    save_tail = header->prev;
    mlib_dll_append_list( &header, app_header );

    /* check whether the list has not been changed. */
    if( header->prev == save_tail )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_append_to_null
 * Functionality:
 *     test basic functionality of mlib_dll_append_list.
 *     append a list to an empty list.
 * Results:
 *     we will get a list that is the same as the one appended.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_append_to_null( kal_uint32 argc, void *argv )
{
    kal_int32 r_value;
   	list_node *header = NULL;
   	list_node *app_header = NULL;
   	test_struct ts1,ts2;
   	ts1.t_data = 14;
   	ts2.t_data = 6;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_append_list append a list to an empty list";

    /* insert 2 nodes into the list pointed to by "app_header". */
    r_value = mlib_dll_insert_node( &app_header, &( ts1.t_node ),
                                    ktest_cmp_func, NULL );
    r_value = mlib_dll_insert_node( &app_header, &( ts2.t_node ),
                                    ktest_cmp_func, NULL );

    /* append it to an empty list. */
    mlib_dll_append_list( &header, app_header );

    /* as we expect, the list pointed to by "header" will be the same as the one
     * pointed to by "app_header". */
    if( header == app_header )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_append_to_list
 * Functionality:
 *     test basic functionality of mlib_dll_append_list.
 *     append a list to another list.
 * Results:
 *     if the list's content is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_append_to_list( kal_uint32 argc, void *argv )
{
    kal_int32 r_value;
   	list_node *header = NULL;
   	list_node *app_header = NULL;
   	list_node *saved_head,*saved_tail;
   	test_struct ts1,ts2,ts3,ts4;
   	ts1.t_data = 14;
   	ts2.t_data = 6;
   	ts3.t_data = 10;
   	ts4.t_data = 34;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_append_list append a list to another list";

    /* insert 2 nodes into the list pointed to by "header". */
    r_value = mlib_dll_insert_node( &header, &( ts1.t_node ), ktest_cmp_func,
                                    NULL );
    r_value = mlib_dll_insert_node( &header, &( ts2.t_node ), ktest_cmp_func,
                                    NULL );

    /* insert 2 nodes into the list pointed to by "app_header". */
    r_value = mlib_dll_insert_node( &app_header, &( ts3.t_node ),
                                    ktest_cmp_func, NULL );
    r_value = mlib_dll_insert_node( &app_header, &( ts4.t_node ),
                                    ktest_cmp_func, NULL );

    /* append the list pointed to by "app_header"
     * to the one pointed to by "header". */
	saved_head = app_header;
	saved_tail = header->prev;
    mlib_dll_append_list( &header, app_header );

    /* check whether the result is correct. */
    if( (saved_tail->next == saved_head) && (saved_tail == saved_head->prev) )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_check_single_node_1
 * Functionality:
 *     test basic functionality of mlib_dll_is_single_node when it has only one
 *     node.
 * Results:
 *     if it returns true, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_check_single_node_1( kal_uint32 argc, void *argv )
{
    kal_bool r_value;
   	list_node *header = NULL;
   	test_struct ts1;
   	ts1.t_data = 14;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_is_single_node when only one node";

    /* insert one node into the list. note that the list has only one node after
     * this step. */
    mlib_dll_insert_node( &header, &( ts1.t_node ), ktest_cmp_func, NULL );

    /* check whether the list has only one node. */
    r_value = mlib_dll_is_single_node( &(ts1.t_node) );
    if( r_value == KAL_TRUE )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_check_single_node_0
 * Functionality:
 *     test basic functionality of mlib_dll_is_single_node when it has more
 *     than one node.
 * Results:
 *     if it returns false, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_check_single_node_0( kal_uint32 argc, void *argv )
{
    kal_bool r_value;
   	list_node *header = NULL;
   	test_struct ts1,ts2,ts3;
   	ts1.t_data = 14;
	ts2.t_data = 15;
	ts3.t_data = 16;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_is_single_node with more than one node";

    /* insert 3 nodes into the list. */
    mlib_dll_insert_node( &header, &( ts1.t_node ), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &( ts2.t_node ), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &( ts3.t_node ), ktest_cmp_func, NULL );

    /* check whether the list has only one node. */
    r_value = mlib_dll_is_single_node( &(ts1.t_node) );
    if( r_value == KAL_FALSE )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_delete_all
 * Functionality:
 *     test basic functionality of mlib_dll_delete_all_nodes.
 * Results:
 *     if the list has no items in it after deletion, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_delete_all( kal_uint32 argc, void *argv )
{
    kal_uint32 counter;
   	list_node *header = NULL;
   	test_struct ts1,ts2,ts3;
   	ts1.t_data = 14;
	ts2.t_data = 15;
	ts3.t_data = 16;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_delete_all_nodes";

    /* insert 3 nodes into the list. */
    mlib_dll_insert_node( &header, &( ts1.t_node ), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &( ts2.t_node ), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &( ts3.t_node ), ktest_cmp_func, NULL );

    /* delete all nodes from the list. note that the callback function:
     * ktest_cb_func will change the value of test_count. */
    counter = mlib_dll_delete_all_nodes( &header, ktest_cb_func, NULL );

    /* the list will be null after delete all nodes. */
    if( (header == NULL) && (test_count == 3) )
    {
    	test_count = 0;
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	test_count = 0;
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_double_delete_all
 * Functionality:
 *     test basic functionality of mlib_dll_delete_all_nodes.
 *     call mlib_dll_delete_all_nodes for 2 times.
 * Results:
 *     for the 1st time, it will delete all nodes from the list and increase
 *     the value of test_count. but for the 2nd time, since the list already
 *     has no items in it, so it does nothing bug return directly.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_double_delete_all( kal_uint32 argc, void *argv )
{
    kal_uint32 counter1,counter2;
   	list_node *header = NULL;
   	test_struct ts1,ts2,ts3;
   	ts1.t_data = 14;
	ts2.t_data = 15;
	ts3.t_data = 16;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_delete_all_nodes delete a list twice";

    /* insert 3 nodes into the list. */
    mlib_dll_insert_node( &header, &(ts1.t_node), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &(ts2.t_node), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &(ts3.t_node), ktest_cmp_func, NULL );

    /* delete all nodes from the list for the 1st time.
     * this will make the list to be empty, and return a value "3". */
    counter1 = mlib_dll_delete_all_nodes( &header, ktest_cb_func, NULL );

    /* delete all nodes from the lsit for the 2nd time.
     * this will do nothing since the list is already empty, and returns 0. */
    counter2 = mlib_dll_delete_all_nodes( &header, ktest_cb_func, NULL );

    /* check whether the return values are correct. */
    if( (counter1 == 3) && (counter2 == 0) )
    {
    	test_count = 0;
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	test_count = 0;
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_delete_all_no_cb
 * Functionality:
 *     test basic functionality of mlib_dll_delete_all_nodes.
 *     call this function without cb_func provided.
 * Results:
 *     if success, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_delete_all_no_cb( kal_uint32 argc, void *argv )
{
    kal_uint32 counter;
   	list_node *header = NULL;
   	test_struct ts1,ts2,ts3;
   	ts1.t_data = 14;
	ts2.t_data = 15;
	ts3.t_data = 16;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_delete_all_nodes";
    KTEST_EXP_ASSERT_STR = "0";

    /* insert 3 nodes into the list. */
    mlib_dll_insert_node( &header, &(ts1.t_node), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &(ts2.t_node), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &(ts3.t_node), ktest_cmp_func, NULL );

    /* try to delete all nodes from the list. */
    counter = mlib_dll_delete_all_nodes( &header, NULL, NULL );
    if( (header == NULL) && (counter == 3) )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_traverse_all
 * Functionality:
 *     test basic functionality of mlib_dll_traverse_all_nodes.
 * Results:
 *     if success, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_traverse_all( kal_uint32 argc, void *argv )
{
   	list_node *header = NULL;
   	test_struct ts1,ts2,ts3;
   	ts1.t_data = 14;
	ts2.t_data = 15;
	ts3.t_data = 16;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_traverse_all_nodes,with call cb_func";

    /* insert 3 nodes into the list. */
    mlib_dll_insert_node( &header, &(ts1.t_node), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &(ts2.t_node), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &(ts3.t_node), ktest_cmp_func, NULL );

    /* traverse all nodes in the list. note that the value of test_count will
     * be increased by the callback function: ktest_cb_func. */
    mlib_dll_traverse_all_nodes( header, ktest_cb_func, NULL );

    /* check whether the result is correct. */
    if( test_count == 3 )
    {
    	test_count = 0;
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	test_count = 0;
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_traverse_all_no_cb
 * Functionality:
 *     test basic functionality of mlib_dll_traverse_all_nodes without cb_func.
 * Results:
 *     if the result is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_traverse_all_no_cb( kal_uint32 argc, void *argv )
{
    kal_uint32 counter;
   	list_node *header = NULL;
   	test_struct ts1,ts2,ts3;
   	ts1.t_data = 14;
	ts2.t_data = 15;
	ts3.t_data = 16;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_delete_all_nodes";

    /* insert 3 nodes into the list. */
    mlib_dll_insert_node( &header, &(ts1.t_node), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &(ts2.t_node), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &(ts3.t_node), ktest_cmp_func, NULL );

    /* try to traverse all nodes in the list. note that the callback function
     * is null. */
    counter = mlib_dll_traverse_all_nodes(header,NULL,NULL);

    /* check whether the result is correct. */
    if( counter == 3 )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_locate_null_1
 * Functionality:
 *     test basic functionality of mlib_dll_locate_list.
 *     try to locate a node on an empty list.
 * Results:
 *     if it returns null, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_locate_null_1(kal_uint32 argc, void *argv)
{
    list_node *r_ptr;
   	list_node *header = NULL;
   	test_struct ts1;
   	ts1.t_data = 5;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_locate_list locate a node on an empty list.";

    /* try to locate the node. */
    r_ptr = mlib_dll_locate_node( header, &(ts1.t_node), ktest_cmp_func, NULL );

    /* since the list is empty, so it will return null. */
    if( r_ptr == NULL )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_locate_null_2
 * Functionality:
 *     test basic functionality of mlib_dll_locate_node.
 *     try to locate a node on a list without cmp_func.
 * Results:
 *     if it returns null, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_locate_null_2( kal_uint32 argc, void *argv )
{
    list_node *r_ptr;
   	list_node *header = NULL;
   	test_struct ts1,ts2,ts3;
   	ts1.t_data = 5;
   	ts2.t_data = 20;
   	ts3.t_data = 15;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_locate_node locate a node on a list without cmp_func";

    mlib_dll_insert_node( &header, &(ts1.t_node), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &(ts2.t_node), ktest_cmp_func, NULL );

    /* try to locate a node with value "15". since the callback function is
     * null, the function will return null. */
    r_ptr = mlib_dll_locate_node( header, &(ts3.t_node), NULL, NULL );
    if( r_ptr == NULL )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_locate_head
 * Functionality:
 *     test basic functionality of mlib_dll_locate_node.
 *     try to locate on the header node of list.
 * Results:
 *     if the locate position is the header of list, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_locate_head( kal_uint32 argc, void *argv )
{
    list_node *r_ptr = (list_node *) 4;
   	list_node *header = NULL;

   	test_struct ts1,ts2,ts3,cmp_ts;
   	ts1.t_data = 35;
   	ts2.t_data = 15;
   	ts3.t_data = 17;
   	cmp_ts.t_data = 1;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_delete_node split from header";

    /* insert 3 nodes into the list. */
    mlib_dll_insert_node( &header, &(ts1.t_node), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &(ts2.t_node), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &(ts3.t_node), ktest_cmp_func, NULL );

    /* locate the node with value "1", and this will return the pointer to
     * the header of list. */
    r_ptr = mlib_dll_locate_node( header, &(cmp_ts.t_node), ktest_cmp_func,
                                  NULL );
    if( r_ptr == header )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_locate_tail
 * Functionality:
 *     test basic functionality of mlib_dll_locate_node.
 *     try to locate a node on tail of a list.
 * Results:
 *     since the cmp_node's value is larger than all values of nodes in the list,
 *     it will return null.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_locate_tail( kal_uint32 argc, void *argv )
{
    list_node *r_ptr = (list_node *) 4;
   	list_node *header = NULL;
	list_node *saved_header = NULL;
   	test_struct ts1,ts2,ts3,cmp_ts;
   	ts1.t_data = 35;
   	ts2.t_data = 5;
   	ts3.t_data = 17;
   	cmp_ts.t_data = 40;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_locate_node locate on tail of a list";

    /* insert 3 nodes into the list. */
    mlib_dll_insert_node( &header, &(ts1.t_node), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &(ts2.t_node), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &(ts3.t_node), ktest_cmp_func, NULL );

    /* since the cmp_node's value is larger than that of all nodes in this list,
     * so this function will return null. */
	saved_header = header;
    r_ptr = mlib_dll_locate_node( header, &(cmp_ts.t_node), ktest_cmp_func,
                                  NULL );
    if( r_ptr == NULL )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_mlib_dll_locate_mid
 * Functionality:
 *     test basic functionality of mlib_dll_locate_node.
 *     locate in the middle of a list.
 * Results:
 *     if success, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_mlib_dll_locate_mid( kal_uint32 argc, void *argv )
{
    list_node *r_ptr = (list_node *) 4;
   	list_node *header = NULL;
	list_node *saved_header = NULL;
   	test_struct ts1, ts2, ts3, cmp_ts;
   	test_struct *chk_ts1, *chk_ts2;
   	ts1.t_data = 35;
   	ts2.t_data = 5;
   	ts3.t_data = 17;
   	cmp_ts.t_data = 21;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF= "Test mlib_dll_locate_node locate on middle from a list";

    /* insert 3 nodes into the list. */
    mlib_dll_insert_node( &header, &(ts1.t_node), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &(ts2.t_node), ktest_cmp_func, NULL );
    mlib_dll_insert_node( &header, &(ts3.t_node), ktest_cmp_func, NULL );

    /* locate the node in the middle part of the list. */
    r_ptr = mlib_dll_locate_node( header, &(cmp_ts.t_node), ktest_cmp_func,
                                  NULL );

    /* check whether the result is correct. */
    chk_ts1 = List2Container( r_ptr->prev, test_struct, t_node );
    chk_ts2 = List2Container( r_ptr, test_struct, t_node );
    if( (chk_ts1->t_data <= cmp_ts.t_data)
        && (cmp_ts.t_data <= chk_ts2->t_data) )
    {
    	MY_REPORT_RETURN( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
    	MY_REPORT_RETURN( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * test case table of mlib module in post-schedule stage.
 * note that the ones wrapped by FIX_OSCAR_FAIL will be tested only on target,
 *           but will be ignored on OSCAR.
 *****************************************************************************/
const ktest_tc_struct ktest_tc_mlib_tbl[] =
{
	{ktest_mlib_dll_insert_null, 0, NULL},
	{ktest_mlib_dll_insert_no_cmp_func, 0, NULL},
	{ktest_mlib_dll_insert_to_null, 0, NULL},
	{ktest_mlib_dll_insert_to_head, 0, NULL},
	{ktest_mlib_dll_insert_to_tail, 0, NULL},
	{ktest_mlib_dll_insert_to_mid, 0, NULL},
	{ktest_mlib_dll_delete_null, 0, NULL},
	{ktest_mlib_dll_delete_single, 0, NULL},
	{ktest_mlib_dll_delete_not_on_list, 0, NULL},
	{ktest_mlib_dll_delete_header, 0, NULL},
	{ktest_mlib_dll_delete_tail, 0, NULL},
	{ktest_mlib_dll_delete_mid, 0, NULL},
	{ktest_mlib_dll_double_delete, 0, NULL},
	{ktest_mlib_dll_split_null_1,0,NULL},
	{ktest_mlib_dll_split_null_2,0,NULL},
	{ktest_mlib_dll_split_head,0,NULL},
	{ktest_mlib_dll_split_mid,0,NULL},
	{ktest_mlib_dll_split_tail,0,NULL},
	{ktest_mlib_dll_append_null,0,NULL},
	{ktest_mlib_dll_append_to_null,0,NULL},
	{ktest_mlib_dll_append_to_list,0,NULL},
	{ktest_mlib_dll_check_single_node_0,0,NULL},
	{ktest_mlib_dll_check_single_node_1,0,NULL},
	{ktest_mlib_dll_delete_all,0,NULL},
	{ktest_mlib_dll_delete_all_no_cb,0,NULL},
	{ktest_mlib_dll_double_delete_all,0,NULL},
	{ktest_mlib_dll_traverse_all,0,NULL},
	{ktest_mlib_dll_traverse_all_no_cb,0,NULL},
	{ktest_mlib_dll_locate_null_1,0,NULL},
	{ktest_mlib_dll_locate_null_2,0,NULL},
	{ktest_mlib_dll_locate_head,0,NULL},
	{ktest_mlib_dll_locate_mid,0,NULL},
	{ktest_mlib_dll_locate_tail,0,NULL},
    {ktest_lcd_cqueue, 0, NULL},
};

/******************************************************************************
 * test case table of mlib module in pre-schedule stage.
 * note that the ones wrapped with FIX_OSCAR_FAIL will only be tested on target,
 *           but will be ignored
 *****************************************************************************/
const ktest_tc_struct ktest_pre_tc_mlib_tbl[] =
{
	{ktest_fake_test, 0, NULL},
};

/******************************************************************************
 * Name:
 *     ktest_tc_mlib_num
 * Functionality:
 *     caculate the total number of test cases of mlib module in post-schedule
 *     stage.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of test cases of mlib module in post-schedule stage.
 *****************************************************************************/
kal_uint32 ktest_tc_mlib_num( void )
{
	return sizeof( ktest_tc_mlib_tbl )/ sizeof(ktest_tc_struct);
}

/******************************************************************************
 * Name:
 *     ktest_pre_tc_mlib_num
 * Functionality:
 *     caculate the total number of test cases of mlib module in pre-schedule
 *     stage.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of test cases of mlib module in pre-schedule stage.
 *****************************************************************************/
kal_uint32 ktest_pre_tc_mlib_num( void )
{
	return sizeof( ktest_pre_tc_mlib_tbl ) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * Name:
 *     ktest_mlib_init
 * Functionality:
 *     this is the initialization function of mlib module.
 * Parameters:
 *     mod: id of mlib module.
 * Returns:
 *     void.
 * Note:
 *     this function should be called in ktest_testcase_register to register
 *     mlib module into KTEST.
 *****************************************************************************/
void ktest_mlib_init( kal_uint32 mod )
{
	tc_all_tbls[mod] = ktest_tc_mlib_tbl;
	pre_tc_all_tbls[mod] = ktest_pre_tc_mlib_tbl;

	tc_modules_num[mod] = ktest_tc_mlib_num();
	pre_tc_modules_num[mod] = ktest_pre_tc_mlib_num();
}

#endif /*__KTEST__*/
