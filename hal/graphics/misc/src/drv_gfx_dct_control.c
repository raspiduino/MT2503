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
 *    drv_gfx_dct_control.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   DCT control interface
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#include "intrCtrl.h"
#include "reg_base.h"
#include "config_hw.h"
#include "drvpdn.h"
#include "drv_features.h"
#include "mm_power_ctrl.h"
#include "drv_gfx_dct_control.h"
#include "drv_features_jpeg.h"


#if   defined(DRV_FEATURE__MM_POWER_CTRL_IF) || defined(__CLKG_DEFINE__)
   /// New MM power gating enumeration.
   #define MMCG_DCT_BIT       MMPWRMGR_DCT
#else
   /// For chips using legacy power control.
   #define REG_PDN_CLR_DCT    *(PDN_CLR3)
   #define REG_PDN_SET_DCT    *(PDN_SET3)   
   #define PDN_CTRL_DCT_BIT   0x2000
#endif


#if defined(__MTK_TARGET__) && defined(__DRV_GRAPHICS_HW_DCT_CONTROL_NEEDED__) && !defined(__UL1_STANDALONE__) && !defined(__L1_STANDALONE__)


static volatile DCT_USER_ENUM _dct_current_user = DCT_USER_NONE;
static volatile kal_uint32 _dct_preempting_flag = 0;


kal_int32 drv_gfx_open_dct(DCT_USER_ENUM dct_user)
{
   kal_uint32 savedMask;

   /// Protect global variable from race condition.
   savedMask = SaveAndSetIRQMask();
   if (DCT_USER_NONE == _dct_current_user)
   {
      _dct_current_user = dct_user;
      _dct_preempting_flag = 0;
   }
   else if (dct_user == _dct_current_user)
   {
      /// Nothing to do.
      RestoreIRQMask(savedMask);
      return 1;
   }
   else
   {
      RestoreIRQMask(savedMask);
      return 0;
   }
   RestoreIRQMask(savedMask);

   #if defined(DRV_FEATURE__MM_POWER_CTRL_IF) || defined(__CLKG_DEFINE__)
      mm_enable_power(MMCG_DCT_BIT);
   #elif defined(__DRV_GRAPHICS_JPEG_6268_SERIES__)
      REG_MMCG_CLR |= MMCG_DCT_BIT;
   #else
      /// For legacy PDN control.
      #if defined(__JPEG_CODEC_PATCH_FOR_WHQA00003764__)
      if ((DCT_USER_JPEG_DECODER == dct_user) || (DCT_USER_JPEG_ENCODER == dct_user))
      {
         volatile kal_uint32 index;

         *PDN_CLR3 = (kal_uint16)(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT);
         for (index = 0; index < 200; index++) {};
         *PDN_SET3 = (kal_uint16)(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT);
      }
      #endif

      REG_PDN_CLR_DCT |= PDN_CTRL_DCT_BIT;
   #endif

   return 1;
}



kal_int32 drv_gfx_preempt_dct(DCT_USER_ENUM dct_user)
{
   kal_int32 timeout_counter = 50;

   if (dct_user == _dct_current_user)
   {
      return 1;
   }

   /// DCT is used by others, notify the current user to abort DCT.
   if (DCT_USER_NONE != _dct_current_user)
   {
      _dct_preempting_flag = 1;
   }

   /// Polling until DCT is released.
   while (DCT_USER_NONE != _dct_current_user)
   {
      if (--timeout_counter < 0)
      {
         ASSERT(0);
         return 0;
      }
      kal_sleep_task(2);
   }

   if (1 != drv_gfx_open_dct(dct_user))
   {
      ASSERT(0);
   }
   return 1;
}



kal_int32 drv_gfx_check_dct_preemption(DCT_USER_ENUM dct_user)
{
   return (kal_uint32)_dct_preempting_flag;
}



kal_int32 drv_gfx_close_dct(DCT_USER_ENUM dct_user)
{
   kal_uint32 savedMask;

   /// Protect global variable from race condition.
   savedMask = SaveAndSetIRQMask();
   if (dct_user != _dct_current_user)
   {
      RestoreIRQMask(savedMask);
      return 0;
   }
   RestoreIRQMask(savedMask);

#if defined(__JPEG_DEC_PATCH_FOR_HQA00009744__)
   // after mpeg4 use, must reset it for turely releasing dct hw module
   if (DCT_USER_MPEG4_CODEC == dct_user)
   {
      *((volatile unsigned int *) 0x94060000) = 0x7;
      *((volatile unsigned int *) 0x94060000) = 0x7;
      *((volatile unsigned int *) 0x94060000) = 0x7;
      *((volatile unsigned int *) 0x94060000) = 0x7;
      *((volatile unsigned int *) 0x94060000) = 0x7;
   }
#endif

   #if defined(DRV_FEATURE__MM_POWER_CTRL_IF) || defined(__CLKG_DEFINE__)
      mm_disable_power(MMCG_DCT_BIT);
   #else
      #if defined(__DRV_GRAPHICS_JPEG_6268_SERIES__)
         REG_MMCG_SET |= MMCG_DCT_BIT;
      #else
         /// For legacy PDN control.
         REG_PDN_SET_DCT |= PDN_CTRL_DCT_BIT;
      #endif
   #endif

   /// Protect global variable from race condition.
   savedMask = SaveAndSetIRQMask();
   _dct_current_user = DCT_USER_NONE;
   RestoreIRQMask(savedMask);

   return 1;
}



#else



kal_int32 drv_gfx_open_dct(DCT_USER_ENUM dct_user)
{
   return 1;
}



kal_int32 drv_gfx_close_dct(DCT_USER_ENUM dct_user)
{
   return 1;
}



kal_int32 drv_gfx_preempt_dct(DCT_USER_ENUM dct_user)
{
   return 1;
}



kal_int32 drv_gfx_check_dct_preemption(DCT_USER_ENUM dct_user)
{
   return 0;
}

#endif   /// End of #if defined(__MTK_TARGET__) && defined(__DRV_GRAPHICS_HW_DCT_CONTROL_NEEDED__)
