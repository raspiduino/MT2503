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

/*******************************************************************************
 * Filename:
 * ---------
 *  DebugInitDef_Int.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : DebugInitDef.h

   PURPOSE     : To implement debug print levels and their conditional configurations.

   REMARKS     : nil

   AUTHOR      : Pixtel Engineers

   DATE     : 

**************************************************************/

#ifndef DEBUGINITDEF_INT_H
#define DEBUGINITDEF_INT_H

/* DOM-NOT_FOR_SDK-BEGIN */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_public_api.h"

#ifndef __GNUC__
#define MMI_TRACE_FUNC        TRACE_FUNC
#define MMI_TRACE_STATE       TRACE_STATE
#define MMI_TRACE_INFO        TRACE_INFO
#define MMI_TRACE_WARNING     TRACE_WARNING
#define MMI_TRACE_ERROR       TRACE_ERROR
#define MMI_TRACE_G1_FRM      TRACE_GROUP_1
#define MMI_TRACE_G2_GUI      TRACE_GROUP_2
#define MMI_TRACE_G3_BOOTUP   TRACE_GROUP_3
#define MMI_TRACE_G4_PHB      TRACE_GROUP_4
#define MMI_TRACE_G5_CM       TRACE_GROUP_5
#define MMI_TRACE_G6_SMS      TRACE_GROUP_6
#define MMI_TRACE_G7_MISC     TRACE_GROUP_7
#define MMI_TRACE_G8_MEDIA    TRACE_GROUP_8
#define MMI_TRACE_G9_EMAIL    TRACE_GROUP_9
#define MMI_TRACE_G10_RESERVED TRACE_GROUP_10
#define MAX_MMI_TRACE_LOG_TYPE (MMI_TRACE_G10_RESERVED+1)
#else /* __GNUC__ */ 
typedef enum
{
    MMI_TRACE_FUNC = 0,
    MMI_TRACE_STATE,
    MMI_TRACE_INFO,
    MMI_TRACE_WARNING,
    MMI_TRACE_ERROR,

    MMI_TRACE_G1_FRM,
    MMI_TRACE_G2_GUI,
    MMI_TRACE_G3_BOOTUP,
    MMI_TRACE_G4_PHB,
    MMI_TRACE_G5_CM,
    MMI_TRACE_G6_SMS,
    MMI_TRACE_G7_MISC,
    MMI_TRACE_G8_MEDIA,
    MMI_TRACE_G9_EMAIL,
    MMI_TRACE_G10_RESERVED,
    MAX_MMI_TRACE_LOG_TYPE
} mmi_log_type_enum;
#endif /* __GNUC__ */ 

#if defined(__TST_MODULE__)
#define DEBUG_INFORMATION 1
#endif 

extern void Trace(S8 *fmt, ...);
extern void Trace2(U32 fmt, S8 *arg_type, ...);
extern void Trace3(U32 fmt, U32 arg_type, ...);
extern void mmi_wprintf(module_type mod_id, U32 fmt, WCHAR *wstr);
extern void init_trace_table(void);
extern char *get_trace_table(int msg_id);
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef DEBUG_INFORMATION
    #define PRINT_INFORMATION Trace
    #define PRINT_INFORMATION_2 Trace2
    #define MMI_PRINT kal_wap_trace
    #ifndef __GNUC__
        #define MMI_TRACE kal_trace
    #else 
      #ifdef WIN32
        #define MMI_TRACE 1 ? (void)0 : kal_trace   
      #else
        /* Only target compiler know (...) in the macro */
        #define MMI_TRACE(...)        
      #endif
    #endif 
#else /* DEBUG_INFORMATION */ 
    #ifdef WIN32
        /* KAL always has kal_trace()/kal_wap_trace() on PC simulator */
        #define PRINT_INFORMATION 1 ? (void)0 : Trace
        #define PRINT_INFORMATION_2 1 ? (void)0 : Trace2
        #define MMI_PRINT 1 ? (void)0 : kal_wap_trace
        #define MMI_TRACE 1 ? (void)0 : kal_trace   
    #else
        /* KAL may define kal_trace/kal_wap_trace to be NULL on the target, but PC compiler doesn't know (...) in the macro */
        #define PRINT_INFORMATION(...)        
        #define PRINT_INFORMATION_2(...)
/* DOM-NOT_FOR_SDK-END */

/*************************************************************************************
 *  For MMI_PRINT
 *       MMI_PRINT(MOD_MMI_XXX, MMI_XXX_TRC_GX "output string¡­¡­", variable);
 *  mod_id is one of MOD_MMI_FW, MOD_MMI_COMMON_APP, MOD_MMI_CONN_APP, MOD_MMI_MEDIA_APP, or MOD_MMI_INET_APP
 *  For example:
 *       MMI_PRINT(MOD_MMI_MEDIA_APP, MMI_MEDIA_TRC_G2_APP, "Data is : %s\n", temp_buffer);
*************************************************************************************/
        #define MMI_PRINT(...)
       
/**************************************************************************************
 * EXAMPLE
 * <code>
 *    In mcu\plutommi\mmi\inc\MMI_media_app_trc.h, register your trace ID,
 *    BEGIN_TRACE_MAP(MOD_MMI_MEDIA_APP)
 *     ¡­¡­
 *    TRC_MSG(TRC_MMI_VDOPLY_DA_CB_EVENT_TYPE, "[VDOPLY][DA] mmi_vdoply_da_cb(), event: %d")
 *    ¡­¡­
 *    END_TRACE_MAP(MOD_MMI_MEDIA_APP)
 *    In mcu\plutommi\mtkapp\video\videosrc\xxx.c call trace API in some place of your function,
 *    void mmi_vdoply_da_cb(void)
 *    {
 *   	¡­¡­
 *   	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_VDOPLY_DA_CB_EVENT_TYPE, yyy);
 *   	¡­¡­
 *    }
 * </code>
******************************************************************************************/        
     #define MMI_TRACE(...)

    #endif /* WIN32 */   
#endif /* DEBUG_INFORMATION */ 


/*
 * = MMI_ASSERT = 
 *
 * Equivalent to ASSERT(). We are sure that this should not happen, and we don't know how to recover from it.
 * 
 * Note: MMI_ASSERT might be REMOVED for __PRODUCTION_RELEASE__ in the future!!
 *
 * = MMI_DBG_ASSERT =
 *
 * MMI_DBG_ASSERT is ignored unless g_mmi_frm_enable_debug_assert is set in Engineer Mode.
 * It is used to test if something strange occurs, typically non-fatal errors.
 * However, we should prevent failure of MMI_DBG_ASSERT in most cases.
 * MMI_DBG_ASSERT is completely removed in produce release to save space and time.
 *
 * = MMI_EXT_ASSERT =
 *
 * In production release, it reset the mobile phone on failure.
 * In non-production release, it print error message on failure.
 */
#define MMI_ASSERT(expr)      ASSERT(expr)
/* See the discription of MMI_ASSERT */
#define MMI_EXT_ASSERT(expr, e1, e2, e3)  EXT_ASSERT(expr, e1, e2, e3)


/* See the discription of MMI_ASSERT */
#define MMI_DBG_ASSERT(expr)

/* DOM-NOT_FOR_SDK-BEGIN */
#define MEMORY_ALLOC_FAIL        "Memory alloc failed"
#define SEMAPHORE_RELEASE_FAIL      "Failed to release Semaphore"
#define MMI_QUEUE_WRITE_FAIL     "Failed to write in mmi queue"
#define TIMER_START_FAIL         "Failed to start timer"
#define TIMER_STOP_FAIL          "Failed to stop timer"
#define FATAL_ERR             "FATAL Error!!!"
#define KBD_QUEUE_WRITE_FAIL     "Failed to write in kbd queue"
#define KBH_QUEUE_WRITE_FAIL     "Failed to write in kbh queue"
#define TMR_QUEUE_WRITE_FAIL     "Failed to write in tmr queue"
#define PRT_QUEUE_WRITE_FAIL     "Failed to write in prt queue"
/* DOM-NOT_FOR_SDK-END */
#endif /* DEBUGINITDEF_INT_H */ 


