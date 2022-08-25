/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   pmu_init.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provide for pmu initial setting
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
#include "drv_comm.h"
#include "init.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"

//pmu6250_init_set_E1_E2.txt	
void dcl_pmu6250_internal_init(void)
{
	SW_SECVERSION SW_SecVersion = INT_SW_SecVersion();
	if(SW_SecVersion >= SW_SEC_1)
	{
	//<ECO_E2>
	//address, mask, value,     ap shift, ap mask, ap value, bank
	//LDO_CON0
	//sleep-mode is controlled by digital HW sleep-mode control
	//0x00C0[0:0] = 0x0
		PMU_DRV_SetData16(0xA07000C0,0x1,0x0);
	//VA_CON0
	//Enables VA remote sense
	//0x0120[2:2] = 0x1
		PMU_DRV_SetData16(0xA0700120,0x4,0x4);
	//VIBR_CON0
	//Maxwell's request (2.8V)
	//0x01B0[6:4] = 0x4
		PMU_DRV_SetData16(0xA07001B0,0x70,0x40);
	//VCORE_CON3
	//Change this setting based on Maxwell's request
	//0x023C[8:4] = 0x18
		PMU_DRV_SetData16(0xA070023C,0x1F0,0x180);
	//CHR_CON1
	//CV_VTH setting to 4.2000V
	//0x0A04[12:8] = 0xE
		PMU_DRV_SetData16(0xA0700A04,0x1F00,0xE00);
	//CHR_CON4
	//RG_CSDAC_STP
	//0x0A10[10:8] = 0x0
		PMU_DRV_SetData16(0xA0700A10,0x700,0x0);
	//CHR_CON5
	//RG_VBAT_OV_VTH=4.3V as battery charging algorsim requirement from SA & SW.
	//0x0A14[5:4] = 0x2
		PMU_DRV_SetData16(0xA0700A14,0x30,0x20);
	//CHR_CON9
	//RG_CHRWDT_TD
	//0x0A24[3:0] = 0x4
		PMU_DRV_SetData16(0xA0700A24,0xF,0x4);
	//CHR_CON11
	//RG_BC11_RST
	//0x0A2C[11:11] = 0x1
		PMU_DRV_SetData16(0xA0700A2C,0x800,0x800);
	//CHR_CON11
	//RG_BC11_BB_CTRL
	//0x0A2C[10:10] = 0x1
		PMU_DRV_SetData16(0xA0700A2C,0x400,0x400);
	//CHR_CON12
	//RG_ULC_DET_EN = 1 from Barry's request
	//0x0A30[7:7] = 0x1
		PMU_DRV_SetData16(0xA0700A30,0x80,0x80);
	//CHR_CON12
	//RG_HWCV_EN
	//0x0A30[6:6] = 0x1
		PMU_DRV_SetData16(0xA0700A30,0x40,0x40);
	//CHR_CON12
	//RG_CSDAC_MODE
	//0x0A30[2:2] = 0x1
		PMU_DRV_SetData16(0xA0700A30,0x4,0x4);
	//CHR_CON14
	//BATON  NTC Temp detection functionon
	//0x0A38[7:0] = 0x1
		PMU_DRV_SetData16(0xA0700A38,0xFF,0x1);
	//STRUP_CON0
	//avoid keypad short problem
	//0x0A80[4:4] = 0x0
		PMU_DRV_SetData16(0xA0700A80,0x10,0x0);
	//STRUP_CON1
	//disable power good detection after power up
	//0x0A84[3:3] = 0x1
		PMU_DRV_SetData16(0xA0700A84,0x8,0x8);
	//ISINKS_CON0
	//1.28us per step
	//0x0C00[3:2] = 0x3
		PMU_DRV_SetData16(0xA0700C00,0xC,0xC);
	//SPK_CON3
	//jiaye: reduce pop noise
	//0x0D0C[14:14] = 0x1
		PMU_DRV_SetData16(0xA0700D0C,0x4000,0x4000);
	//</ECO_E2>
	}
	else //if(SW_SecVersion >= SW_SEC_0)
	{
	//<ECO_E1>
	//address, mask, value,     ap shift, ap mask, ap value, bank
	//LDO_CON0
	//sleep-mode is controlled by digital HW sleep-mode control
	//0x00C0[0:0] = 0x0
		PMU_DRV_SetData16(0xA07000C0,0x1,0x0);
	//VA_CON0
	//Enables VA remote sense
	//0x0120[2:2] = 0x1
		PMU_DRV_SetData16(0xA0700120,0x4,0x4);
	//VIBR_CON0
	//Maxwell's request (2.8V)
	//0x01B0[6:4] = 0x4
		PMU_DRV_SetData16(0xA07001B0,0x70,0x40);
	//VCORE_CON3
	//Change this setting based on Maxwell's request
	//0x023C[8:4] = 0x18
		PMU_DRV_SetData16(0xA070023C,0x1F0,0x180);
	//CHR_CON1
	//CV_VTH setting to 4.2000V
	//0x0A04[12:8] = 0xE
		PMU_DRV_SetData16(0xA0700A04,0x1F00,0xE00);
	//CHR_CON4
	//RG_CSDAC_STP
	//0x0A10[10:8] = 0x0
		PMU_DRV_SetData16(0xA0700A10,0x700,0x0);
	//CHR_CON5
	//RG_VBAT_OV_VTH=4.3V as battery charging algorsim requirement from SA & SW.
	//0x0A14[5:4] = 0x2
		PMU_DRV_SetData16(0xA0700A14,0x30,0x20);
	//CHR_CON9
	//RG_CHRWDT_TD
	//0x0A24[3:0] = 0x3
		PMU_DRV_SetData16(0xA0700A24,0xF,0x3);
	//CHR_CON11
	//RG_BC11_RST
	//0x0A2C[11:11] = 0x1
		PMU_DRV_SetData16(0xA0700A2C,0x800,0x800);
	//CHR_CON11
	//RG_BC11_BB_CTRL
	//0x0A2C[10:10] = 0x1
		PMU_DRV_SetData16(0xA0700A2C,0x400,0x400);
	//CHR_CON12
	//RG_ULC_DET_EN = 1 from Barry's request
	//0x0A30[7:7] = 0x1
		PMU_DRV_SetData16(0xA0700A30,0x80,0x80);
	//CHR_CON12
	//RG_HWCV_EN
	//0x0A30[6:6] = 0x1
		PMU_DRV_SetData16(0xA0700A30,0x40,0x40);
	//CHR_CON12
	//RG_CSDAC_MODE
	//0x0A30[2:2] = 0x1
		PMU_DRV_SetData16(0xA0700A30,0x4,0x4);
	//CHR_CON14
	//BATON  NTC Temp detection functionon
	//0x0A38[7:0] = 0x1
		PMU_DRV_SetData16(0xA0700A38,0xFF,0x1);
	//STRUP_CON0
	//avoid keypad short problem
	//0x0A80[4:4] = 0x0
		PMU_DRV_SetData16(0xA0700A80,0x10,0x0);
	//STRUP_CON1
	//disable power good detection after power up
	//0x0A84[3:3] = 0x1
		PMU_DRV_SetData16(0xA0700A84,0x8,0x8);
	//SPK_CON3
	//jiaye: reduce pop noise
	//0x0D0C[14:14] = 0x1
		PMU_DRV_SetData16(0xA0700D0C,0x4000,0x4000);
	//</ECO_E1>
	}
}
	
