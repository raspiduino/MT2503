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
#include "drv_comm.h"
#include "init.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"

//pmu6260_init_set_E1_E2.txt	

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
void dcl_pmu6260_internal_init(void)
{
	{
	//<ECO_E1>
	//address, mask, value,     ap shift, ap mask, ap value, bank
	//LDO_CON0
	//sleep-mode is controlled by digital HW sleep-mode control
	//0x00C0[0:0] = 0x0
		PMU_DRV_SetData16(0xA07000C0,0x1,0x0);
	//VIBR_CON0
	//VIBR bypass soft start function
	//0x01B0[11:11] = 0x1
		PMU_DRV_SetData16(0xA07001B0,0x800,0x800);
	//VMC_CON0
	//VMC bypass soft start function
	//0x01C0[11:11] = 0x1
		PMU_DRV_SetData16(0xA07001C0,0x800,0x800);
	//VCORE_CON3
	//VCORE 1.0V in sleep mode
	//0x023C[8:4] = 0x1C
		PMU_DRV_SetData16(0xA070023C,0x1F0,0x1C0);
	//VCORE_CON3
	//Enable VCORE soft-change mode
	//0x023C[3:3] = 0x1
		PMU_DRV_SetData16(0xA070023C,0x8,0x8);
	//CHR_CON0
	//support high voltage charger
	//0x0A00[0:0] = 0x1
		PMU_DRV_SetData16(0xA0700A00,0x1,0x1);
	//CHR_CON4
	//RG_CSDAC_STP
	//0x0A10[10:8] = 0x0
		PMU_DRV_SetData16(0xA0700A10,0x700,0x0);
	//CHR_CON5
	//OV: 4.3V
	//0x0A14[6:4] = 0x1
		PMU_DRV_SetData16(0xA0700A14,0x70,0x10);
	//CHR_CON9
	//charger watch dog precc 32 sec
	//0x0A24[3:0] = 0x3
		PMU_DRV_SetData16(0xA0700A24,0xF,0x3);
	//CHR_CON11
	//To reset all BC11 register
	//0x0A2C[11:11] = 0x1
		PMU_DRV_SetData16(0xA0700A2C,0x800,0x800);
	//CHR_CON11
	//force BC11 controlled by BB for charger detection
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
	//0x0A38[0:0] = 0x1
		PMU_DRV_SetData16(0xA0700A38,0x1,0x1);
	//STRUP_CON0
	//avoid keypad short problem
	//0x0A80[4:4] = 0x0
		PMU_DRV_SetData16(0xA0700A80,0x10,0x0);
	//STRUP_CON0
	//auto thermal power-down
	//0x0A80[3:3] = 0x1
		PMU_DRV_SetData16(0xA0700A80,0x8,0x8);
	//STRUP_CON1
	//disable power good detection after power up
	//0x0A84[3:3] = 0x1
		PMU_DRV_SetData16(0xA0700A84,0x8,0x8);
	//ISINK0_CON1
	//isink0 phase shift to prevent RF de-sense
	//0x0C14[0:0] = 0x1
		PMU_DRV_SetData16(0xA0700C14,0x1,0x1);
	//ISINK1_CON1
	//isink1 phase shift to prevent RF de-sense
	//0x0C24[0:0] = 0x1
		PMU_DRV_SetData16(0xA0700C24,0x1,0x1);
	//ISINK2_CON1
	//isink2 phase shift to prevent RF de-sense
	//0x0C34[0:0] = 0x1
		PMU_DRV_SetData16(0xA0700C34,0x1,0x1);
	//ISINK3_CON1
	//isink3 phase shift to prevent RF de-sense
	//0x0C44[0:0] = 0x1
		PMU_DRV_SetData16(0xA0700C44,0x1,0x1);
	//SPK_CON3
	//reduce pop noise
	//0x0D0C[14:14] = 0x1
		PMU_DRV_SetData16(0xA0700D0C,0x4000,0x4000);
	//</ECO_E1>
	}
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
	
