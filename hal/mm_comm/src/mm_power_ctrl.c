/****************************************************************************
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
 *    mm_power_ctrl.c
 *
 * Project:
 * --------
 *	  MAUI
 *
 * Description:
 * ------------
 *    This file manages MMSYS power control and clock gating of all MM engines. 
 *    Currently this file is only used in MT6268 project.
 *    Each project should re-write this set of functions according to HW design.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 10 12 2011 chrono.wu
 * removed!
 * .
 *
 * 09 09 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 08 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 01 11 2011 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * 10 18 2010 sophie.chen
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "reg_base.h"
#include "drv_comm.h"
#include "mm_power_ctrl.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "mmsys_pwrmgr.h"

#if defined(__MTK_TARGET__)
#if defined(DRV_FEATURE__MM_POWER_CTRL_IF)
extern void _mm_disable_power(kal_uint32 module);
extern void _mm_enable_power(kal_uint32 module);
extern void _mm_disable_clock(kal_uint32 module);
extern void _mm_enable_clock(kal_uint32 module);
extern kal_bool _mm_query_clock_status(kal_uint32 module);
#endif //#if defined(DRV_FEATURE__MM_POWER_CTRL_IF)
#endif //#if defined(__MTK_TARGET__) 

void mm_enable_power(kal_uint32 module)
{
#if defined(__MTK_TARGET__)
#if defined(DRV_FEATURE__MM_POWER_CTRL_IF)
    if (MMPWRMGR_MAX_DEV <= module)
    {
      return;
    }

    _mm_enable_power(module);
#endif //#if defined(DRV_FEATURE__MM_POWER_CTRL_IF)
#endif //#if defined(__MTK_TARGET__) 
}



void mm_disable_power(kal_uint32 module)
{
#if defined(__MTK_TARGET__)
#if defined(DRV_FEATURE__MM_POWER_CTRL_IF)
    if (MMPWRMGR_MAX_DEV <= module)
    {
      return;
    }

    _mm_disable_power(module);
#endif //#if defined(DRV_FEATURE__MM_POWER_CTRL_IF)
#endif //#if defined(__MTK_TARGET__) 
}



void mm_disable_clock(kal_uint32 module)
{
#if 0
#if defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if defined(__MTK_TARGET__) 
#endif
}



void mm_enable_clock(kal_uint32 module)
{
#if 0
#if defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if defined(__MTK_TARGET__) 
#endif
}


// This API is only supported when __CLKG_DEFINE__ is enabled.
kal_bool mm_query_clock_status(kal_uint32 module)
{
#if defined(__MTK_TARGET__)
#if defined(DRV_FEATURE__MM_POWER_CTRL_IF)
#if defined(__CLKG_DEFINE__)
   if (MMPWRMGR_MAX_DEV <= module)
   {
     return KAL_TRUE;
   }
   return _mm_query_clock_status(module);
#else //#if defined(__CLKG_DEFINE__)
   return KAL_FALSE;
#endif      
#endif //#if defined(DRV_FEATURE__MM_POWER_CTRL_IF)
#else //#if defined(__MTK_TARGET__)
   return KAL_FALSE;
#endif      

}

