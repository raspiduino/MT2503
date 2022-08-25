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
 *   init_trc_api.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains definitions for trace on target.
 *
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
  
#ifndef _INIT_TRC_API_H
#define _INIT_TRC_API_H

#include "stack_config.h"
#include "kal_trace.h"

/*************************************************************************
  * Define macros.
  *************************************************************************/
/*
 * NoteXXX: 
 *          (1) Use print_trace(_with_info)() instead of print_bootup_trace(_with_info)()
 *          after TST task init
 *          (2) xxx_enter() and xxx_exit() should be used in a pair
 *          (3) xxx_enter() and xxx_exit() are invalid before TDMA timer is init
 */
#if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
#define print_bootup_trace(i) \
        do {  \
            kal_bootup_trace(TRACE_INFO, i); \
        } while (0)

#define print_bootup_trace_enter(i) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_current_time(); \
            kal_bootup_trace(TRACE_INFO, i##_ENTER); \
        } while (0)

#define print_bootup_trace_exit(i) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_duration_ms(init_duration); \
            kal_bootup_trace(TRACE_INFO, i##_EXIT, init_duration); \
        } while (0)

#define print_trace(i) \
        do {  \
            kal_trace(TRACE_INFO, i); \
        } while (0)

#define print_bootup_trace_with_info_enter(i, info) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_current_time(); \
            kal_bootup_trace(TRACE_INFO, i##_ENTER, info); \
        } while (0)

#define print_bootup_trace_with_info_exit(i, info) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_duration_ms(init_duration); \
            kal_bootup_trace(TRACE_INFO, i##_EXIT, info, init_duration); \
        } while (0)

#define print_trace_with_info_enter(i, info) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_current_time(); \
            kal_trace(TRACE_INFO, i##_ENTER, info); \
        } while (0)

#define print_trace_with_info_exit(i, info) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_duration_ms(init_duration); \
            kal_trace(TRACE_INFO, i##_EXIT, info, init_duration); \
        } while (0)

#define print_boot_mode(m) \
        do {  \
            extern void INT_printBootMode(void); \
            INT_printBootMode(); \
        } while (0)
#else /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */
#define print_bootup_trace(i)
#define print_bootup_trace_enter(i)
#define print_bootup_trace_exit(i)
#define print_trace(i)
#define print_bootup_trace_with_info_enter(i, info)
#define print_bootup_trace_with_info_exit(i, info)
#define print_trace_with_info_enter(i, info)
#define print_trace_with_info_exit(i, info)
#define print_boot_mode(m)
#endif /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */

#endif	/* _INIT_TRC_API_H */

