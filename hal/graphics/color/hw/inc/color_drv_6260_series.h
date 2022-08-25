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
 *   color_drv_6260_series.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Driver definition of COLOR for MT6260 series chip.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_color.h"

#ifndef __COLOR_DRV_6260_SERIES_H__
#define __COLOR_DRV_6260_SERIES_H__

#if defined(__DRV_COLOR_MT6260_SERIES__) && defined(__DRV_COLOR_HW_SUPPORT__)

#include "reg_base.h"
#include "mm_power_ctrl.h"


#define COLOR_base                         MM_COLOR_base
#define REG_COLOR_EN                       *(volatile kal_uint32 *)(COLOR_base + 0x00)
#define REG_COLOR_BYPASS                   *(volatile kal_uint32 *)(COLOR_base + 0x04)
#define REG_COLOR_SHARP_CON                *(volatile kal_uint32 *)(COLOR_base + 0x10)
#define REG_COLOR_CONTRAST_POINT           *(volatile kal_uint32 *)(COLOR_base + 0x20)
#define REG_COLOR_CONTRAST_OFFSET          *(volatile kal_uint32 *)(COLOR_base + 0x24)
#define REG_COLOR_CONTRAST_GAIN            *(volatile kal_uint32 *)(COLOR_base + 0x28)
#define REG_COLOR_SAT_POINT                *(volatile kal_uint32 *)(COLOR_base + 0x30)
#define REG_COLOR_SAT_GAIN                 *(volatile kal_uint32 *)(COLOR_base + 0x38)
#define REG_COLOR_SRC_SIZE                 *(volatile kal_uint32 *)(COLOR_base + 0x50)

#define REG_MMCG_CON       *(volatile kal_uint32 *)(MMCG_CON0)
#define REG_MMCG_CLR       *(volatile kal_uint32 *)(MMCG_CLR0)
#define REG_MMCG_SET       *(volatile kal_uint32 *)(MMCG_SET0)
#define MMCG_COLOR_BIT     (MMPWRMGR_MM_COLOR)


/* Definition for control bit in REG_COLOR_BYPASS */
#define COLOR_BYPASS_NONE               0x00000000
#define COLOR_BYPASS_SAT                0x00000001
#define COLOR_BYPASS_CONTRAST           0x00000002
#define COLOR_BYPASS_SHARP              0x00000004
#define COLOR_BYPASS_Y2R                0x00000008
#define COLOR_BYPASS_R2Y                0x00000010
#define COLOR_BYPASS_ALL                0x0000001F
#define COLOR_BYPASS_STALL              0x00000080
#define COLOR_BYPASS_MASK               0x0000009F


#endif  // __DRV_COLOR_MT6260_SERIES__

#endif  // __COLOR_DRV_6260_SERIES_H__

