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
 *   rgb_rotator_int.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   RGB Resizer
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
#ifndef __RGB_ROTATOR_INT_H__
#define __RGB_ROTATOR_INT_H__

#include "kal_general_types.h"

#include "rotator_enum.h"
#include "rgb_rotator_structure.h"

/// rgb_rotator_int_sw.c
ROTATOR_STATUS_ENUM sw_rgb_rotator_query_working_memory(RGB_ROTATOR_HANDLE_STRUCT *handle, kal_uint32 *intMemBest, kal_uint32 *intMemMin,
                                                                                           kal_uint32 *extMemBest, kal_uint32 *extMemMin);

ROTATOR_STATUS_ENUM sw_rgb_rotator_set_working_memory(RGB_ROTATOR_HANDLE_STRUCT *handle);

ROTATOR_STATUS_ENUM sw_rgb_rotator_start(RGB_ROTATOR_HANDLE_STRUCT *handle);


/// rgb_rotator_int_hw.c  
ROTATOR_STATUS_ENUM rgb_rotator_drv_query_working_memory(RGB_ROTATOR_HANDLE_STRUCT *handle, kal_uint32 *intMemBest, kal_uint32 *intMemMin,
                                                                                            kal_uint32 *extMemBest, kal_uint32 *extMemMin);

kal_int32 rgb_rotator_drv_init(void);
kal_int32 rgb_rotator_drv_open(void);
kal_int32 rgb_rotator_drv_close(void);
kal_int32 rgb_rotator_drv_start(RGB_ROTATOR_HANDLE_STRUCT *handle);        
kal_int32 rgb_rotator_drv_get_status(void);

                                                                                                                                                                
#endif
