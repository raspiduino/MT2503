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
 *   drv_gfx_l1sm_ctrl.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file for drv_gfx_l1sm_ctrl.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __DRV_GFX_L1SM_CTRL_H__
#define __DRV_GFX_L1SM_CTRL_H__

#include "kal_general_types.h"


#define SM_CTRL_NULL_HANDLE      0xFFFFFFFF
#define SM_CTRL_MAX_ENTRY_COUNT  32


typedef enum {
   DRV_GFX_L1SM_USER_NULL = -1,
   DRV_GFX_L1SM_USER_JPEG,
   DRV_GFX_L1SM_USER_PNG,
   DRV_GFX_L1SM_USER_GIF,
   DRV_GFX_L1SM_USER_G2D,
   DRV_GFX_L1SM_USER_M3D,
   DRV_GFX_L1SM_USER_CHE,
   DRV_GFX_L1SM_USER_GCU,
   DRV_GFX_L1SM_USER_LAST_ONE
} DRV_GFX_L1SM_USER_ENUM;



/**
 * @brief       Block the L1 from going into sleep mode.
 * @param user  the HW module wants to block sleep mode
 * @return      If the function succeeds, return 1;
 *              otherwise return 0.
 * @remarks
 */
kal_int32 drv_gfx_l1sm_sleep_block(DRV_GFX_L1SM_USER_ENUM user);



/**
 * @brief       Unblock the L1 sleep mode mechanism.
 * @param user  the HW module wants to unblock sleep mode
 * @return      If the function succeeds, return 1;
 *              otherwise return 0.
 * @remarks     The parameter index must be the same as the returned value of drv_gfx_l1sm_sleep_block,
 *              otherwise the assertion failure occurs.
 */
kal_int32 drv_gfx_l1sm_sleep_unblock(DRV_GFX_L1SM_USER_ENUM user);


#endif /// __DRV_GFX_L1SM_CTRL_H__
