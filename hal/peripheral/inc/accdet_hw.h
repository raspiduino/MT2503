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
 *    accdet_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for accessory detector driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
  * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef ACCDET_HW_H
#define ACCDET_HW_H
#include    "reg_base.h"


#define ACCDET_RSTB         ACCDET_base
#define ACCDET_CTRL         ACCDET_base + 0x04
#define ACCDET_STATE_SWCTRL ACCDET_base + 0x08
#define ACCDET_CMP_WIDTH    ACCDET_base + 0x0C
#define ACCDET_CMP_THRESH   ACCDET_base + 0x10
#define ACCDET_VTH_WIDTH    ACCDET_base + 0x14
#define ACCDET_VTH_THRESH   ACCDET_base + 0x18
#define ACCDET_BIAS_WIDTH   ACCDET_base + 0x1C
#define ACCDET_BIAS_THRESH  ACCDET_base + 0x20
#define ACCDET_EN_DELAY_NUM ACCDET_base + 0x24
#define ACCDET_PWM_IDLE     ACCDET_base + 0x28
#define ACCDET_DEBOUNCE0    ACCDET_base + 0x2C
#define ACCDET_DEBOUNCE1    ACCDET_base + 0x30
#define ACCDET_DEBOUNCE2    ACCDET_base + 0x34
#define ACCDET_DEBOUNCE3    ACCDET_base + 0x38
#define ACCDET_IRQ_STS      ACCDET_base + 0x3C
#define ACCDET_CURR_IN      ACCDET_base + 0x40
#define ACCDET_SAMPLE_IN    ACCDET_base + 0x44
#define ACCDET_MEMORIZED_IN ACCDET_base + 0x48
#define ACCDET_LAST_MEM_IN  ACCDET_base + 0x4C
#define ACCDET_FSM_STATE    ACCDET_base + 0x50
#define ACCDET_CURR_DEBDS   ACCDET_base + 0x54

#define ACCDET_ANASW      0x01
#define ACCDET_TV_DET     0x02
#define ACCDET_CMP_EN     0x04
#define ACCDET_VTH_EN     0x08
#define ACCDET_MICBIA_EN  0x10
#define ACCDET_SWCTRL_EN  0x1D

#define ACCDET_IRQ_CLR    0x100

#define ACCDET_IRQ_STS_IRQ 0x01

#endif //ACCDET_HW_H
