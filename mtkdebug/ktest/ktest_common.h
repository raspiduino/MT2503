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
 *     ktest_common.h
 *
 * Project:
 * --------
 *     Maui_Software
 *
 * Description:
 * ------------
 *     This file expose the API or global varibles to test case files
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
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __KTEST_COMMON_H
#define __KTEST_COMMON_H
 
#include "kal_release.h"
#include "intrCtrl.h"
#include "ktest_interface.h"
#include "kal_public_defs.h"
#include "kal_internal_api.h"
#include "hisr_config.h"

/* some test cases will fail in oscar as we expected, so we have wrapped these
 * test cases with FIX_OSCAR_FAIL compilation option, in order to make them
 * not run in oscar.
 * But since we didn't define FIX_OSCAR_FAIL at all, so these cases wrapped
 * with FIX_OSCAR_FAIL also won't run on target, and this is not what we want
 * to see.
 * For the reason above, we define FIX_OSCAR_FAIL here when __MTK_TARGET__ has
 * been defined. And we hope this can gurantee those test cases wrapped with
 * FIX_OSCAR_FAIL will still run on target, but not run in oscar.
 * Note:
 *     if your have test cases wrapped with FIX_OSCAR_FAIL, and you need them
 *     to run on target, please include this file in your test case files. */
#ifdef __MTK_TARGET__
#define FIX_OSCAR_FAIL
#endif  /* __MTK_TARGET__ */

/******************************************************************************
 * Macros:
 *     KTEST_TC_LABEL_MAGIC: the head of test case label.
 *     KTEST_TC_LABEL_TAIL:  the tail of test case label.
 *     KTEST_TC_MAGIC_TRASH: when destroy the test case label, we overwrite the
 *                           head with this macro's value.
 *     KTEST_TC_TAIL_TRASH:  when destroy the test case label, we overwrite the
 *                           tail with this macro's value.
 *     KTEST_TC_MAGIC_LEN:   length of the head of test case label.
 *     KTEST_TC_TAIL_LEN:    length of the tail of test case label.
 *****************************************************************************/
#define KTEST_TC_LABEL_MAGIC	"KTESTz"
#define KTEST_TC_LABEL_TAIL	    "jmf"
#define KTEST_TC_MAGIC_TRASH	"RABISH"
#define KTEST_TC_TAIL_TRASH	    "xnd"
#define KTEST_TC_MAGIC_LEN	    6
#define KTEST_TC_TAIL_LEN	    3

/******************************************************************************
 * No test case should use system memory more than 30K
 *****************************************************************************/
#define KTEST_SYS_MEM_WATERMARK 30 * 1024

/******************************************************************************
 * test case label in KTEST
 *     magic: head of label. if it's not "KTESTz", then label is invalid.
 *     tail:  tail of label. if it's not "jmf", then label is invalid.
 *     stage: it indicates KTEST is in pre-schedule or post-schedule stage.
 *     module: it indicates the current test case module.
 *     index: it indicates which test case is running now.
 *****************************************************************************/
typedef struct {
	kal_char	magic[KTEST_TC_MAGIC_LEN];
	kal_uint8	stage;
	kal_uint8	module;
	kal_int8	index;
	kal_char	tail[KTEST_TC_TAIL_LEN];
} ktest_tc_label;

/******************************************************************************
 * three values defined for data memeber "stage" in ktest_tc_label
 *****************************************************************************/
typedef enum {
    TC_PRE_SCHEDULE = 0,
    TC_POST_SCHEDULE = 1,
    TC_STAGE_OVER
} ktest_tc_stage;

/******************************************************************************
 * exposed APIs.
 *****************************************************************************/
extern void ktest_init_uart_port( void );
extern kal_bool ktest_is_init_stage( const ktest_tc_label *tc_id );
extern kal_bool ktest_next_tc( ktest_tc_label *tc_id );
extern kal_bool ktest_write_tc_label( const ktest_tc_label *tc_id );
extern kal_bool ktest_read_tc_label( ktest_tc_label * tc_id );
extern kal_uint32 ktest_run_tc( const ktest_tc_label *tc_ptr );
extern kal_bool ktest_init_tc_label( void );
extern kal_uint32 ktest_init_env( void );
extern kal_bool ktest_sys_check( void );
extern void ktest_engine( void );

#endif	/*__KTEST_COMMON_H*/
