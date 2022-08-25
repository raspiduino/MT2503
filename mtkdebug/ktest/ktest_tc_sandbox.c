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
 *   ktest_tc_sandbox.c
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/
#ifdef __KTEST__
#include "ktest_common.h"
#include "kal_release.h"
#include "syscomp_config.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "lcd_ip_cqueue.h"
#include "task_config.h"
#include "app_buff_alloc.h"
 
/******************************************************************************
 * Name:
 *     ktest_data_abort
 * Functionality:
 *     generate a data abort.
 * Results:
 *     if a fatal error: KAL_ERROR_DABORT occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_data_abort( kal_uint32 argc, void *argv )
{
    kal_int32 a;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_DABORT;

    /* data abort will occur here.
     * and we will report PASS in fatal error handler. */
    *(int *) NULL = 0x0000FFFF;

    /* as expected, data abort will occur and fatal error handler will be called,
     * the statement below will not be executed at all. */
    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
}

/******************************************************************************
 * test case table of sandbox module in pre-schedule stage.
 * note that the ones wrapped with FIX_OSCAR_FAIL will only be tested on target,
 *           but will be ignored on OSCAR.
 *****************************************************************************/
const ktest_tc_struct ktest_pre_tc_sandbox_tbl[] =
{
    {ktest_fake_test, 0, NULL},
};

/******************************************************************************
 * test case table of sandbox module in post-schedule stage.
 * note that the ones wrapped with FIX_OSCAR_FAIL will only be tested on target,
 *           but will be ignored on OSCAR.
 *****************************************************************************/
const ktest_tc_struct ktest_tc_sandbox_tbl[] =
{
#ifdef FIX_OSCAR_FAIL
    /* data abort on VC will cause memory corruption. */
    {ktest_data_abort, 0, NULL},
#else
    /* on OSCAR, FIX_OSCAR_FAIL is not defined. so if we don't add the fake test
     * case below, the compiler will give an error because the table has nothing
     * in it. */
    {ktest_fake_test, 0, NULL},
#endif /* FIX_OSCAR_FAIL */
};

/******************************************************************************
 * Name:
 *     ktest_tc_sandbox_num
 * Functionality:
 *     caculate there are how many test cases of sandbox module in post-schedule
 *     stage.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of test cases of sandbox module in post-schedule stage.
 *****************************************************************************/
kal_uint32 ktest_tc_sandbox_num( void )
{
	return sizeof( ktest_tc_sandbox_tbl) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * Name:
 *     ktest_pre_tc_sandbox_num
 * Functionality:
 *     caculate there are how many test cases of sandbox module in pre-schedule
 *     stage.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of test cases of sandbox module in pre-schedule stage.
 *****************************************************************************/
kal_uint32 ktest_pre_tc_sandbox_num( void )
{
	return sizeof( ktest_pre_tc_sandbox_tbl) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * Name:
 *     ktest_sandbox_init
 * Functionality:
 *     the initialization function of sandbox module.
 * Parameters:
 *     mod: id of sandbox module.
 * Returns:
 *     void.
 * Note:
 *     this function should be called in ktest_testcase_register to register
 *     sandbox module into KTEST.
 *****************************************************************************/
void ktest_sandbox_init( kal_uint32 mod )
{
	tc_all_tbls[mod] = ktest_tc_sandbox_tbl;
	pre_tc_all_tbls[mod] = ktest_pre_tc_sandbox_tbl;

	tc_modules_num[mod] = ktest_tc_sandbox_num();
	pre_tc_modules_num[mod] = ktest_pre_tc_sandbox_num();
}

#endif /*__KTEST__*/
