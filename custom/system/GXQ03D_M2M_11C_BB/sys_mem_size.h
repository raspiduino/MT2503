/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *  sys_mem_size.h 
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contain definition of custom component module configuration variables, and routines
 *
 * Author:
 * -------
 *   jianming Fan (mtk80457)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __SYS_MEM_SIZE_H__
#define __SYS_MEM_SIZE_H__

/* GLOBAL_MEM_SIZE = accurate_sys_mem + estimate_sys_mem - g_stack_sharing_stack_size - g_custom_stack_size. 
 * estimate_sys_mem  is for timer, event group, sem created at run time.
 * You may modify the estimate_sys_mem to meet you own need
 */
    #define STACK_POOL_COEFFECIENT (100 - 38)
    #define STACK_POOL_SHARING_SIZE  (67770 * STACK_POOL_COEFFECIENT/100) 
    #define STACK_POOL_SIZE  (STACK_POOL_SHARING_SIZE + 30520 + 3072)
    #define STACK_POOL_COEFFECIENT_FACTORY (100 - 0 /*15*/)
    #define STACK_POOL_SHARING_SIZE_FACTORY (33686 * STACK_POOL_COEFFECIENT_FACTORY/100)
    #define STACK_POOL_SIZE_FACTORY  (STACK_POOL_SHARING_SIZE_FACTORY + 17352 + 0)
    #define GLOBAL_MEM_SIZE  (225096 + 21032 - (67770 * (100-STACK_POOL_COEFFECIENT)/100))
    #define GLOBAL_MEM_SIZE_FACTORY  (154096 + 8232 - (33686 * (100-STACK_POOL_COEFFECIENT_FACTORY)/100))
    #define FACTORY_REMAIN_MEM_SIZE  (GLOBAL_MEM_SIZE - GLOBAL_MEM_SIZE_FACTORY)
    #define TOTAL_TASK_STACK_SIZE  (67770 + 30520 + 3072)
    #define GLOBAL_DEBUG_MEM_SIZE  (1324)
    #define GLOBAL_HISR_SHARED_IRAM_STACK_SIZE  (1536)
    #define GLOBAL_TOTAL_CREATED_TASK_NUMBER    (46)
#endif  
