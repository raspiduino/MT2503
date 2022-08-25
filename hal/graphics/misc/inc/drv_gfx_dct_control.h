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
 *    drv_gfx_dct_control.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __DRV_GFX_DCT_CONTROL_H__
#define __DRV_GFX_DCT_CONTROL_H__

#include "kal_general_types.h"



typedef enum
{
   DCT_USER_NONE = 0,
   DCT_USER_MPEG4_CODEC,
   DCT_USER_JPEG_DECODER,
   DCT_USER_JPEG_ENCODER
} DCT_USER_ENUM;



/**
 * @brief            Get the control of DCT.
 * @param dct_user   the user who want to use DCT.
 * @return           If the function succeeds, return non-zero; otherwise return zero.
 * @remarks          The caller MUST handle the return value properly.
 */
kal_int32 drv_gfx_open_dct(DCT_USER_ENUM dct_user);



/**
 * @brief            Release the control of DCT.
 * @param dct_user   the user who owns the control of DCT.
 * @return           If the function succeeds, returns non-zero; otherwise returns zero.
 * @remarks          The caller MUST handle the return value properly.
 */
kal_int32 drv_gfx_close_dct(DCT_USER_ENUM dct_user);



/**
 * @brief            Preempt the control of DCT from current DCT user.
 * @param dct_user   the user who want to preempt the control of DCT.
 * @return           If the function succeeds, returns non-zero; otherwise returns zero.
 * @remarks          It is a blocking function. After the function returns, the control of DCT will owned by dct_user.
 */
kal_int32 drv_gfx_preempt_dct(DCT_USER_ENUM dct_user);



/**
 * @brief            Check the preemption status of DCT.
 * @param dct_user   the user who want to check the preemption status.
 * @return           If DCT is under preempting state, return 1; otherwise return 0.
 * @remarks
 */
kal_int32 drv_gfx_check_dct_preemption(DCT_USER_ENUM dct_user);


#endif
