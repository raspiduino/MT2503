/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   drv_gfx_dynamic_switch.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_general_types.h"

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
   #include "mmu.h"
   #include "cache_sw.h"
#endif

kal_bool drv_gfx_dynamic_switch_cacheable(void *memoryAddrPtr, kal_uint32 memorySize, kal_bool forceCheck)
{
   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      kal_uint32 memoryAddr = (kal_uint32)(*(kal_uint32 *)memoryAddrPtr);

      if(KAL_TRUE == forceCheck)
      {
         if((IS_CACHE_LINE_SIZE_ALIGNED(memoryAddr)) &&
            (IS_CACHE_LINE_SIZE_ALIGNED(memorySize)) &&
            (is_predef_dyna_c_region(memoryAddr, memorySize)))
         {
            if(KAL_TRUE == INT_QueryIsNonCachedRAM(memoryAddr, memorySize))
            {
               dynamic_switch_cacheable_region((void*)memoryAddrPtr, memorySize, PAGE_CACHEABLE);
               return KAL_TRUE;
            }
         }
      }
      else
      {
         dynamic_switch_cacheable_region((void*)memoryAddrPtr, memorySize, PAGE_CACHEABLE);

         return KAL_TRUE;
      }
   #endif

   return KAL_FALSE;
}



kal_bool drv_gfx_dynamic_switch_noncacheable(void *memoryAddrPtr, kal_uint32 memorySize, kal_bool forceCheck)
{
   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      kal_uint32 memoryAddr = (kal_uint32)(*(kal_uint32 *)memoryAddrPtr);

      if(KAL_TRUE == forceCheck)
      {
         if((IS_CACHE_LINE_SIZE_ALIGNED(memoryAddr)) &&
            (IS_CACHE_LINE_SIZE_ALIGNED(memorySize)) &&
            (is_predef_dyna_c_region(memoryAddr, memorySize)))
         {
            if(KAL_TRUE == INT_QueryIsCachedRAM(memoryAddr, memorySize))
            {
               dynamic_switch_cacheable_region((void*)memoryAddrPtr, memorySize, PAGE_NO_CACHE);
               return KAL_TRUE;
            }
         }
      }
      else
      {
         dynamic_switch_cacheable_region((void*)memoryAddrPtr, memorySize, PAGE_NO_CACHE);
         return KAL_TRUE;
      }
   #endif

   return KAL_FALSE;
}
