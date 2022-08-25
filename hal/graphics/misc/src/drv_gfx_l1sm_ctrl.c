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
 *   drv_gfx_l1sm_ctrl.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   drv_gfx_l1sm_ctrl.c provides the capability of L1SM handle sharing for drv_graphics HW modules.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_gfx_l1sm_ctrl.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"

#if defined(__MTK_TARGET__)
   #include "intrctrl.h"

   extern kal_uint8 L1SM_GetHandle(void);
   extern void L1SM_SleepEnable(kal_uint8 handle);
   extern void L1SM_SleepDisable(kal_uint8 handle);
#else

   #define L1SM_SleepDisable()         (0xAA)
   #define L1SM_SleepEnable(HANDLE)    do {} while (0)
   #define L1SM_SleepDisable(HANDLE)   do {} while (0)
#endif

static kal_uint32 _drv_gfx_l1sm_handle = SM_CTRL_NULL_HANDLE;
static kal_uint32 _drv_gfx_l1sm_user_state = 0;


kal_int32 drv_gfx_l1sm_sleep_block(DRV_GFX_L1SM_USER_ENUM user)
{
   kal_uint32 savedMask;

   ASSERT(DRV_GFX_L1SM_USER_NULL != user);
   ASSERT(DRV_GFX_L1SM_USER_LAST_ONE <= SM_CTRL_MAX_ENTRY_COUNT);

   if (SM_CTRL_NULL_HANDLE == _drv_gfx_l1sm_handle)
   {
      _drv_gfx_l1sm_handle = L1SM_GetHandle();
   }

   if (0 == _drv_gfx_l1sm_user_state)
   {
      /// Disable the L1 SM now since the _drv_gfx_l1sm_user_state is going to be set.
      L1SM_SleepDisable(_drv_gfx_l1sm_handle);
   }

   savedMask = SaveAndSetIRQMask();

   _drv_gfx_l1sm_user_state |= (1 << user);

   RestoreIRQMask(savedMask);

   return 1;
}



kal_int32 drv_gfx_l1sm_sleep_unblock(DRV_GFX_L1SM_USER_ENUM user)
{
   kal_uint32 savedMask;

   ASSERT(DRV_GFX_L1SM_USER_NULL != user);
   ASSERT(DRV_GFX_L1SM_USER_LAST_ONE <= SM_CTRL_MAX_ENTRY_COUNT);
   ASSERT(SM_CTRL_NULL_HANDLE != _drv_gfx_l1sm_handle);

   savedMask = SaveAndSetIRQMask();

   _drv_gfx_l1sm_user_state &= ~(1 << user);

   RestoreIRQMask(savedMask);

   if (0 == _drv_gfx_l1sm_user_state)
   {
      L1SM_SleepEnable(_drv_gfx_l1sm_handle);
   }
   
   return 1;
}
