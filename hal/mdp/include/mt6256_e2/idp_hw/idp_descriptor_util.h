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
 *  idp_descriptor_util.h 
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
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
 * 09 22 2011 chelun.tsai
 * removed!
 * .
 *
 * 05 27 2011 chelun.tsai
 * removed!
 * MT6526 E2 MDP driver.
 *
 * 05 05 2011 chelun.tsai
 * removed!
 * last check in befor sample back.
 *
 * 01 07 2011 chrono.wu
 * removed!
 * .
 *
 * 12 06 2010 gellmann.chang
 * removed!
 * .
 *
 * 11 23 2010 gellmann.chang
 * removed!
 * .
 *
 * 10 18 2010 holmes.chiou
 * removed!
 * .
 *
 * removed!
 * removed!
 * MT6256 naming check-in
 *
 * removed!
 * removed!
 * MT6255 HQA check-in
 *
 * removed!
 * removed!
 * MM integration check-in
 *
 * removed!
 * removed!
 * Modify the typo error
 *
 * removed!
 * removed!
 * DVT check-in
 *
 * removed!
 * removed!
 * DVT check-in
 *
 * removed!
 * removed!
 * MDP driver
 *
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __idp_imgdma_descriptor_util_mt6256_e2_h__
#define __idp_imgdma_descriptor_util_mt6256_e2_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>

//#include "idp_imgdma_vdorot.h"
//#include "idp_imgdma_rgbrot0.h"
//#include "idp_imgdma_rgbrot1.h"

// original


#define IDP_HW_DESCRIPTOR_DEFINITION(name)                              \
  void                                                                  \
  idp_imgdma_##name##_queue_push(                                       \
      kal_uint32 const data)                                            \
  {                                                                     \
    IMGDMA_##name##_PUSH_QUEUE_DATA(data);                              \
    while(KAL_FALSE == IMGDMA_##name##_IS_QUEUE_WRITE_BUSY());          \
  }                                                                     \
                                    \
  void                                                                  \
  idp_imgdma_##name##_set_queue_base_addr(                             \
      kal_uint32 const data)                                            \
  {                                                                     \
    IMGDMA_##name##_SET_QUEUE_BASE_ADDR(data);                          \
  }                                                                     \
                                    \
  void                                                                  \
  idp_imgdma_##name##_set_queue_depth(                                 \
      kal_uint32 const data)                                            \
  {                                                                     \
    IMGDMA_##name##_SET_QUEUE_DEPTH(data);                              \
  }                                                                     \
                                                                        \
  void                                                                  \
  idp_imgdma_##name##_set_queue_segs(                                  \
      kal_uint32 const data)                                            \
  {                                                                     \
    IMGDMA_##name##_SET_DESCIPTOR_SEG(data);                            \
  }                                                                     \
  void                                                                  \
  idp_imgdma_##name##_enable_descriptor_mode(                           \
            kal_bool enable)                                            \
  {                                                                    \
    if(enable)                                                         \
    {                                                                  \
      IMGDMA_##name##_DESCRIPTOR_MODE();                             \
    }else                                                            \
    {                                                                \
      IMGDMA_##name##_REGISTER_MODE();                               \
                                                                     \
    }                                                               \
  }                                                                  \
  void                                                               \
  idp_imgdma_##name##_queue_empty_drop(                              \
            kal_bool enable)                                         \
  {                                                                  \
    if(enable)                                                       \
    {                                                                \
      IMGDMA_##name##_QUEUE_EMPTY_DROP();                            \
    }else                                                            \
    {                                                                \
      IMGDMA_##name##_QUEUE_EMPTY_STALL();                           \
                                                                     \
    }                                                               \
  }

#endif  //__idp_imgdma_descriptor_util_mt6256_e2_h__

