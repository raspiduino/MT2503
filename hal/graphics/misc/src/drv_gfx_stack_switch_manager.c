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
 *    drv_gfx_stack_switch_manager.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   driver graphics stack switch manager source file
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_gfx_stack_switch_manager.h"

#if defined(__MTK_TARGET__)

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "drv_features.h"



#define STACK_OWNER_NONE  (0xFFFFFFFF)


volatile kal_mutexid _drv_gfx_stack_mutex = 0;
volatile static kal_uint32 _drv_gfx_stack_owner_id = STACK_OWNER_NONE;
volatile static kal_uint32 _drv_gfx_stack_user_filter = 0;


static kal_uint32 _drv_gfx_stkmgr_gen_id(kal_uint32 stk_user_id);


#if defined(DRV_GRAPHICS_STACK_SWITCH_TO_INT_RAM)

   #pragma arm section rwdata = "INTERNRW2", zidata = "INTERNZI2"
   __align(4) static kal_uint8 _drv_gfx_stack[DRV_GFX_STACK_POOL_SIZE + 4];
   #pragma arm section rwdata , zidata

#elif defined(DRV_GRAPHICS_STACK_SWITCH_TO_TCM)

   #pragma arm section rwdata = "INTERNRW2", zidata = "INTERNZI2"
   __align(4) static kal_uint8 _drv_gfx_stack[DRV_GFX_STACK_POOL_SIZE + 4];
   #pragma arm section rwdata , zidata

#elif defined(DRV_GRAPHICS_STACK_SWITCH_TO_TCM_6235)

   #pragma arm section rwdata = "INTERNRW", zidata = "INTERNZI"
   __align(4) static kal_uint8 _drv_gfx_stack[DRV_GFX_STACK_POOL_SIZE + 4];
   #pragma arm section rwdata , zidata

#elif defined(DRV_GRAPHICS_STACK_SWITCH_TO_CACHEABLE_EXT_RAM)

   #pragma arm section rwdata = "CACHEDRW", zidata = "CACHEDZI"
   __align(4) static kal_uint8 _drv_gfx_stack[DRV_GFX_STACK_POOL_SIZE + 4];
   #pragma arm section rwdata , zidata

#else
   __align(4) static kal_uint8 _drv_gfx_stack[DRV_GFX_STACK_POOL_SIZE + 4];   // dummy

#endif




static kal_uint32 _drv_gfx_stkmgr_gen_id(kal_uint32 stk_user_id)
{
   _drv_gfx_stack_owner_id = (((stk_user_id & 0xFF) << 24) | (0xCCCCCC));

   return _drv_gfx_stack_owner_id;
}



kal_int32 drv_gfx_stkmgr_set_user_filter(kal_uint32 stk_size)
{
   const kal_uint32 stk_user_id = stk_size & (~STACK_SIZE_MASK);
   const kal_bool is_system_initializing = kal_query_systemInit();

   if (0 == _drv_gfx_stack_mutex)
   {
      _drv_gfx_stack_mutex = kal_create_mutex("STK_MGR");
   }

   if (_drv_gfx_stack_user_filter)
   {
      if (stk_user_id == _drv_gfx_stack_user_filter)
      {
         return 1;
      }
      /// The filter is aleady set by someone.
      /// It's abnormal so that we return an error code.
      return 0;
   }

   if (KAL_FALSE == is_system_initializing)
   {
      kal_take_mutex(_drv_gfx_stack_mutex);
   }

   _drv_gfx_stack_user_filter = stk_user_id;

   if (KAL_FALSE == is_system_initializing)
   {
      kal_give_mutex(_drv_gfx_stack_mutex);
   }

   while (_drv_gfx_stack_owner_id != STACK_OWNER_NONE)
   {
      kal_sleep_task(1);
   }

   return 1;
}



kal_int32 drv_gfx_stkmgr_unset_user_filter(kal_uint32 stk_size)
{
   const kal_uint32 stk_user_id = stk_size & (~STACK_SIZE_MASK);
   const kal_bool is_system_initializing = kal_query_systemInit();

   if (stk_user_id != _drv_gfx_stack_user_filter)
   {
      if (0 == _drv_gfx_stack_user_filter)
      {
         return 1;
      }
      /// The filter is not set by the user calling this API.
      /// It's abnormal so that we return an error code.
      return 0;
   }

   if (KAL_FALSE == is_system_initializing)
   {
      kal_take_mutex(_drv_gfx_stack_mutex);
   }

   _drv_gfx_stack_user_filter = 0;

   if (KAL_FALSE == is_system_initializing)
   {
      kal_give_mutex(_drv_gfx_stack_mutex);
   }
   return 1;
}



#if defined(STK_MGR_DEBUG)
void *drv_gfx_stkmgr_get_stack_internal(kal_uint32 stk_size, kal_char* file, kal_uint32 line)
#else
void *drv_gfx_stkmgr_get_stack_internal(kal_uint32 stk_size)
#endif
{
   kal_uint32 *stk_ptr;
   const kal_uint32 stk_user_id = stk_size & (~STACK_SIZE_MASK);
   const kal_bool is_system_initializing = kal_query_systemInit();

   stk_size &= STACK_SIZE_MASK;

   if (0 == _drv_gfx_stack_mutex)
   {
      _drv_gfx_stack_mutex = kal_create_mutex("STK_MGR");
   }

   if (KAL_FALSE == is_system_initializing)
   {
      kal_take_mutex(_drv_gfx_stack_mutex);   /// only one codec can do stack switching at the same time
   }

   if ((stk_size > DRV_GFX_STACK_POOL_SIZE) || 
       (STACK_OWNER_NONE != _drv_gfx_stack_owner_id) ||
       ((0 != _drv_gfx_stack_user_filter) && (stk_user_id != _drv_gfx_stack_user_filter)))
   {
      /// no availabe stack space
      stk_ptr = NULL;
   }
   else
   {
      /// owner id is write to the 3rd byte from the start of stack
      stk_ptr = (kal_uint32 *)&_drv_gfx_stack;
      *stk_ptr = _drv_gfx_stkmgr_gen_id(stk_user_id);
      stk_ptr++;

   #if defined(STK_MGR_DEBUG)
      kal_print_string_trace(MOD_MMI, TRACE_INFO, "[STKMGR] FILE: %s, LINE: %u get stack\n", file, line);
   #endif
   }

   if (KAL_FALSE == is_system_initializing)
   {
      kal_give_mutex(_drv_gfx_stack_mutex);
   }

   return (void *)stk_ptr;
}



#if defined(STK_MGR_DEBUG)
void drv_gfx_stkmgr_release_stack_internal(void *stk_ptr, kal_char* file, kal_uint32 line)
#else
void drv_gfx_stkmgr_release_stack_internal(void *stk_ptr)
#endif
{
   kal_uint32 *ptr;
   const kal_bool is_system_initializing = kal_query_systemInit();

   ASSERT(stk_ptr);
   ptr = (kal_uint32 *)stk_ptr;

   if (0 == _drv_gfx_stack_mutex)
   {
      /// in this case, drv_gfx_stkmgr_release_stack is called before drv_gfx_stkmgr_get_stack
      ASSERT(0);
   }

   if (KAL_FALSE == is_system_initializing)
   {
      kal_take_mutex(_drv_gfx_stack_mutex); /// only one codec can do stack switching at the same time
   }

   /// check stack owner id
   if (_drv_gfx_stack_owner_id != *(ptr - 1))
   {
      ASSERT(0);  /// wrong owner or stack corruption
   }
   else
   {
      _drv_gfx_stack_owner_id = STACK_OWNER_NONE;

   #if defined(STK_MGR_DEBUG)
      kal_print_string_trace(MOD_MMI, TRACE_INFO, "[STKMGR] FILE: %s, LINE: %u release stack\n", file, line);
   #endif
   }

   if (KAL_FALSE == is_system_initializing)
   {
      kal_give_mutex(_drv_gfx_stack_mutex);
   }
}


#endif   ///< #if defined(__MTK_TARGET__)
