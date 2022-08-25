/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *    dcl_pmu6261_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for PMU 6260 driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PMU6261_HW_H__
#define __PMU6261_HW_H__


#if defined(PMU_6261_REG_API)

#define MIXED_BASE_ADDR            PMU_base

#define MIXED_BASE_ADDR_END        (MIXED_BASE_ADDR + 0x1000)

#include "dcl_mixedsys6261_reg.h"

/* Special Commands */

// LDO Commands
// LDO_CON0
#define LDO_BUCK_EN_OFFSET          	CON0_MIXED_OFFSET
#define LDO_BUCK_EN_MASK               	0x0001
#define LDO_BUCK_EN_SHIFT              	0

#define LDO_BUCK_ON_SEL_OFFSET     		CON0_MIXED_OFFSET
#define LDO_BUCK_ON_SEL_MASK            0x0002
#define LDO_BUCK_ON_SEL_SHIFT           1

#define LDO_BUCK_RS_OFFSET				CON0_MIXED_OFFSET
#define LDO_BUCK_RS_MASK               	0x0004
#define LDO_BUCK_RS_SHIFT              	2

#define LDO_BUCK_VOL_SEL_OFFSET			CON0_MIXED_OFFSET // For VCAMA, VCAMD, VSIM1, VSIM2, VIBR, VMC, VSF, VCORE
#define LDO_BUCK_VOL_SEL_MASK          	0x01F0
#define LDO_BUCK_VOL_SEL_SHIFT         	4

#define LDO_BUCK_NDIS_EN_OFFSET			CON0_MIXED_OFFSET
#define LDO_BUCK_NDIS_EN_MASK          	0x0400
#define LDO_BUCK_NDIS_EN_SHIFT         	10

#define LDO_BUCK_STB_SEL_OFFSET			CON0_MIXED_OFFSET
#define LDO_BUCK_STB_SEL_MASK          	0x0800
#define LDO_BUCK_STB_SEL_SHIFT         	11

#define LDO_BUCK_OC_AUTO_OFF_OFFSET 	CON0_MIXED_OFFSET
#define LDO_BUCK_OC_AUTO_OFF_MASK      	0x1000
#define LDO_BUCK_OC_AUTO_OFF_SHIFT     	12

#define LDO_BUCK_OCFB_EN_OFFSET			CON0_MIXED_OFFSET
#define LDO_BUCK_OCFB_EN_MASK          	0x2000
#define LDO_BUCK_OCFB_EN_SHIFT         	13

#define LDO_BUCK_OC_FLAG_OFFSET			CON0_MIXED_OFFSET
#define LDO_BUCK_OC_FLAG_MASK          	0x4000
#define LDO_BUCK_OC_FLAG_SHIFT         	14

#define LDO_BUCK_STATUS_OFFSET			CON0_MIXED_OFFSET
#define LDO_BUCK_STATUS_MASK          	0x8000
#define LDO_BUCK_STATUS_SHIFT         	15

// LDO_CON1
#define LDO_CAL_OFFSET					CON1_MIXED_OFFSET
#define LDO_CAL_MASK              		0x00F0
#define LDO_CAL_SHIFT             		4

// LDO_CON2
#define LDO_OC_TD_OFFSET		        CON2_MIXED_OFFSET
#define LDO_OC_TD_MASK                  0x0030
#define LDO_OC_TD_SHIFT                 4

#define LDO_STB_TD_OFFSET		        CON2_MIXED_OFFSET
#define LDO_STB_TD_MASK                 0x00C0
#define LDO_STB_TD_SHIFT                6

// BUCK Commands
#define BUCK_VOSEL_SLEEP_OFFSET	        CON3_MIXED_OFFSET
#define BUCK_VOSEL_SLEEP_MASK           0x01F0
#define BUCK_VOSEL_SLEEP_SHIFT          4

#define BUCK_SFSTREN_OFFSET		        CON3_MIXED_OFFSET
#define BUCK_SFSTREN_MASK               0x0008
#define BUCK_SFSTREN_SHIFT              3

// CHR Commands
#define ADC_EN_OFFSET		            CON10_MIXED_OFFSET
#define ADC_EN_MASK                     0x0070   // All ADC channels are enabled at same time
#define ADC_EN_SHIFT                    4

// ISINK Commands

//ISINKS_CON0
#define ISINK_MODE_OFFSET				CON0_MIXED_OFFSET
#define ISINK_MODE_MASK           		0x0001
#define ISINK_MODE_SHIFT          		0

// ISINK_CON0
#define ISINK_EN_OFFSET					CON0_MIXED_OFFSET
#define ISINK_EN_MASK             		0x0001
#define ISINK_EN_SHIFT            		0

/*
#define ISINK_MODE_OFFSET				CON0_MIXED_OFFSET
#define ISINK_MODE_MASK           		0x0002
#define ISINK_MODE_SHIFT          		1
*/

#define ISINK_CHOP_ENB_OFFSET           CON0_MIXED_OFFSET
#define ISINK_CHOP_ENB_MASK             0x0004
#define ISINK_CHOP_ENB_SHIFT            2

#define ISINK_STEP_OFFSET				CON0_MIXED_OFFSET
#define ISINK_STEP_MASK           		0x0070
#define ISINK_STEP_SHIFT          		4

#define ISINK_CLKSEL_MODE_OFFSET        CON0_MIXED_OFFSET
#define ISINK_CLKSEL_MODE_MASK          0x1000
#define ISINK_CLKSEL_MODE_SHIFT         12

#define ISINK_CLKSEL_OFFSET             CON0_MIXED_OFFSET
#define ISINK_CLKSEL_MASK               0x2000
#define ISINK_CLKSEL_SHIFT              13

#define ISINK_STATUS_OFFSET				CON0_MIXED_OFFSET
#define ISINK_STATUS_MASK           	0x8000
#define ISINK_STATUS_SHIFT          	15

#endif // #if defined(PMU_6260_REG_API)

#endif // #ifndef __PMU6260_HW_H__
