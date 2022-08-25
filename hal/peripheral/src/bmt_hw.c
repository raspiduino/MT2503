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
 *    bmt_hw.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines bmt hw register
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
#include "dcl.h"
#include "kal_public_api.h"
#include "drv_comm.h"
#include "bmt_hw.h"


// ============================================================
// define
// ============================================================
#define BMT_SaveAndSetIRQMask()    SaveAndSetIRQMask()
#define BMT_RestoreIRQMask(n)      RestoreIRQMask(n)


// ============================================================
// global variable
// ============================================================
#if defined( __BMT_2_0_ARCHITECTURE__)
#if defined(MT6255PMU) || defined(MT6256PMU)
const DCL_UINT32 chr_VBAT_CV_VTH[VBAT_CV_VTH_SIZE]=
{
    PMU_VOLT_04_200000_V,   PMU_VOLT_04_212500_V,   PMU_VOLT_04_225000_V,   PMU_VOLT_04_237500_V,
    PMU_VOLT_04_250000_V,   PMU_VOLT_04_262500_V,   PMU_VOLT_04_275000_V,   PMU_VOLT_04_287500_V,
    PMU_VOLT_04_000000_V,   PMU_VOLT_04_012500_V,   PMU_VOLT_04_025000_V,   PMU_VOLT_04_037500_V,
    PMU_VOLT_04_050000_V,   PMU_VOLT_04_062500_V,   PMU_VOLT_04_075000_V,   PMU_VOLT_04_087500_V,
    PMU_VOLT_04_100000_V,   PMU_VOLT_04_112500_V,   PMU_VOLT_04_125000_V,   PMU_VOLT_04_137500_V,
    PMU_VOLT_04_150000_V,   PMU_VOLT_04_162500_V,   PMU_VOLT_04_175000_V,   PMU_VOLT_04_187500_V
};


const DCL_UINT32 chr_CS_VTH[CS_VTH_SIZE]=
{
	PMU_CHARGE_CURRENT_800_00_MA,   PMU_CHARGE_CURRENT_700_00_MA,
	PMU_CHARGE_CURRENT_650_00_MA,   PMU_CHARGE_CURRENT_550_00_MA,
	PMU_CHARGE_CURRENT_450_00_MA,   PMU_CHARGE_CURRENT_400_00_MA,
	PMU_CHARGE_CURRENT_200_00_MA,   PMU_CHARGE_CURRENT_75_00_MA
};

const DCL_UINT32 chr_VCDT_HV_VTH[VCDT_HV_VTH_SIZE]=
{
	PMU_VOLT_04_200000_V, PMU_VOLT_04_250000_V,     PMU_VOLT_04_300000_V,   PMU_VOLT_04_350000_V,
	PMU_VOLT_04_400000_V, PMU_VOLT_04_450000_V,     PMU_VOLT_04_500000_V,   PMU_VOLT_04_550000_V,
	PMU_VOLT_04_600000_V, PMU_VOLT_06_000000_V,     PMU_VOLT_06_500000_V,   PMU_VOLT_07_000000_V,
	PMU_VOLT_07_500000_V, PMU_VOLT_08_500000_V,     PMU_VOLT_09_500000_V,   PMU_VOLT_10_500000_V	    
};

#elif defined(MT6250PMU)
const DCL_UINT32 chr_VBAT_CV_VTH[VBAT_CV_VTH_SIZE]=
{
	PMU_VOLT_03_775000_V,   PMU_VOLT_03_800000_V,   PMU_VOLT_03_825000_V,   PMU_VOLT_03_975000_V,
	PMU_VOLT_04_000000_V,   PMU_VOLT_04_025000_V, 	PMU_VOLT_04_050000_V,   PMU_VOLT_04_075000_V,
	PMU_VOLT_04_100000_V,   PMU_VOLT_04_125000_V,   PMU_VOLT_04_150000_V,   PMU_VOLT_04_162500_V,
    PMU_VOLT_04_175000_V,   PMU_VOLT_04_187500_V,   PMU_VOLT_04_200000_V,   PMU_VOLT_04_212500_V,
    PMU_VOLT_04_225000_V,   PMU_VOLT_04_237500_V,   PMU_VOLT_04_250000_V,   PMU_VOLT_04_275000_V,
    PMU_VOLT_04_300000_V,   PMU_VOLT_04_325000_V,   PMU_VOLT_04_350000_V,   PMU_VOLT_04_362500_V,
    PMU_VOLT_04_375000_V
};

const DCL_UINT32 chr_CS_VTH[CS_VTH_SIZE]=
{
	PMU_CHARGE_CURRENT_800_00_MA,   PMU_CHARGE_CURRENT_700_00_MA,
	PMU_CHARGE_CURRENT_650_00_MA,   PMU_CHARGE_CURRENT_550_00_MA,
	PMU_CHARGE_CURRENT_450_00_MA,   PMU_CHARGE_CURRENT_400_00_MA,
	PMU_CHARGE_CURRENT_200_00_MA,   PMU_CHARGE_CURRENT_70_00_MA
};

const DCL_UINT32 chr_VCDT_HV_VTH[VCDT_HV_VTH_SIZE]=
{
	PMU_VOLT_04_200000_V, PMU_VOLT_04_250000_V,     PMU_VOLT_04_300000_V,   PMU_VOLT_04_350000_V,
	PMU_VOLT_04_400000_V, PMU_VOLT_04_450000_V,     PMU_VOLT_04_500000_V,   PMU_VOLT_04_550000_V,
	PMU_VOLT_04_600000_V, PMU_VOLT_06_000000_V,     PMU_VOLT_06_500000_V,   PMU_VOLT_07_000000_V,
	PMU_VOLT_07_500000_V, PMU_VOLT_08_500000_V,     PMU_VOLT_09_500000_V,   PMU_VOLT_10_500000_V	    
};

#elif defined(MT6260PMU)
const DCL_UINT32 chr_VBAT_CV_VTH[VBAT_CV_VTH_SIZE]=
{
	PMU_VOLT_INVALID,	    PMU_VOLT_INVALID,       PMU_VOLT_INVALID,       PMU_VOLT_03_775000_V,
	PMU_VOLT_03_800000_V,   PMU_VOLT_03_850000_V,   PMU_VOLT_03_900000_V,	PMU_VOLT_04_000000_V,
	PMU_VOLT_04_050000_V,   PMU_VOLT_04_100000_V,   PMU_VOLT_04_125000_V,   PMU_VOLT_04_137500_V,
	PMU_VOLT_04_150000_V,   PMU_VOLT_04_162500_V,   PMU_VOLT_04_175000_V,   PMU_VOLT_04_187500_V,
	PMU_VOLT_04_200000_V,   PMU_VOLT_04_212500_V,   PMU_VOLT_04_225000_V,   PMU_VOLT_04_237500_V,
	PMU_VOLT_04_250000_V,   PMU_VOLT_04_262500_V,   PMU_VOLT_04_275000_V,   PMU_VOLT_04_300000_V,
	PMU_VOLT_04_325000_V,   PMU_VOLT_04_350000_V,   PMU_VOLT_04_375000_V,   PMU_VOLT_04_400000_V,
	PMU_VOLT_04_425000_V
};


const DCL_UINT32 chr_CS_VTH[CS_VTH_SIZE]=
{
	PMU_CHARGE_CURRENT_800_00_MA,   PMU_CHARGE_CURRENT_700_00_MA,
	PMU_CHARGE_CURRENT_650_00_MA,   PMU_CHARGE_CURRENT_550_00_MA,
	PMU_CHARGE_CURRENT_450_00_MA,   PMU_CHARGE_CURRENT_400_00_MA,
	PMU_CHARGE_CURRENT_200_00_MA,   PMU_CHARGE_CURRENT_70_00_MA
};

const DCL_UINT32 chr_VCDT_HV_VTH[VCDT_HV_VTH_SIZE]=
{
	PMU_VOLT_04_200000_V, PMU_VOLT_04_250000_V,     PMU_VOLT_04_300000_V,   PMU_VOLT_04_350000_V,
	PMU_VOLT_04_400000_V, PMU_VOLT_04_450000_V,     PMU_VOLT_04_500000_V,   PMU_VOLT_04_550000_V,
	PMU_VOLT_04_600000_V, PMU_VOLT_06_000000_V,     PMU_VOLT_06_500000_V,   PMU_VOLT_07_000000_V,
	PMU_VOLT_07_500000_V, PMU_VOLT_08_500000_V,     PMU_VOLT_09_500000_V,   PMU_VOLT_10_500000_V	    
};


#ifdef __DRV_BMT_HIGH_BATTERY_SUPPORT__
const DCL_UINT32 chr_VBAT_OV_VTH[VBAT_OV_VTH_SIZE]=
{
	PMU_VOLT_04_200000_V, PMU_VOLT_04_300000_V,     PMU_VOLT_04_400000_V,   PMU_VOLT_04_450000_V,
	PMU_VOLT_03_825000_V, PMU_VOLT_04_300000_V,     PMU_VOLT_04_300000_V,   PMU_VOLT_04_300000_V
};
#endif

#elif defined(MT6261PMU)
const DCL_UINT32 chr_VBAT_CV_VTH[VBAT_CV_VTH_SIZE]=
{
	PMU_VOLT_INVALID, 		PMU_VOLT_INVALID,       PMU_VOLT_INVALID,       PMU_VOLT_03_775000_V,
	PMU_VOLT_03_800000_V,   PMU_VOLT_03_850000_V,   PMU_VOLT_03_900000_V,	PMU_VOLT_04_000000_V,
	PMU_VOLT_04_050000_V,   PMU_VOLT_04_100000_V,   PMU_VOLT_04_125000_V,   PMU_VOLT_04_137500_V,
	PMU_VOLT_04_150000_V,   PMU_VOLT_04_162500_V,   PMU_VOLT_04_175000_V,   PMU_VOLT_04_187500_V,
	PMU_VOLT_04_200000_V,   PMU_VOLT_04_212500_V,   PMU_VOLT_04_225000_V,   PMU_VOLT_04_237500_V,
	PMU_VOLT_04_250000_V,   PMU_VOLT_04_262500_V,   PMU_VOLT_04_275000_V,   PMU_VOLT_04_300000_V,
	PMU_VOLT_04_325000_V,   PMU_VOLT_04_350000_V,   PMU_VOLT_04_375000_V,   PMU_VOLT_04_400000_V,
	PMU_VOLT_04_425000_V
};


const DCL_UINT32 chr_CS_VTH[CS_VTH_SIZE]=
{
	PMU_CHARGE_CURRENT_1600_00_MA,  PMU_CHARGE_CURRENT_1500_00_MA,
	PMU_CHARGE_CURRENT_1400_00_MA,  PMU_CHARGE_CURRENT_1300_00_MA,
	PMU_CHARGE_CURRENT_1200_00_MA,  PMU_CHARGE_CURRENT_1100_00_MA,
	PMU_CHARGE_CURRENT_1000_00_MA,  PMU_CHARGE_CURRENT_900_00_MA,
	PMU_CHARGE_CURRENT_800_00_MA,   PMU_CHARGE_CURRENT_700_00_MA,
	PMU_CHARGE_CURRENT_650_00_MA,   PMU_CHARGE_CURRENT_550_00_MA,
	PMU_CHARGE_CURRENT_450_00_MA,   PMU_CHARGE_CURRENT_300_00_MA,
	PMU_CHARGE_CURRENT_200_00_MA,   PMU_CHARGE_CURRENT_70_00_MA
};

const DCL_UINT32 chr_VCDT_HV_VTH[VCDT_HV_VTH_SIZE]=
{
	PMU_VOLT_04_200000_V, PMU_VOLT_04_250000_V,     PMU_VOLT_04_300000_V,   PMU_VOLT_04_350000_V,
	PMU_VOLT_04_400000_V, PMU_VOLT_04_450000_V,     PMU_VOLT_04_500000_V,   PMU_VOLT_04_550000_V,
	PMU_VOLT_04_600000_V, PMU_VOLT_06_000000_V,     PMU_VOLT_06_500000_V,   PMU_VOLT_07_000000_V,
	PMU_VOLT_07_500000_V, PMU_VOLT_08_500000_V,     PMU_VOLT_09_500000_V,   PMU_VOLT_10_500000_V	    
};

#ifdef __DRV_BMT_HIGH_BATTERY_SUPPORT__
const DCL_UINT32 chr_VBAT_OV_VTH[VBAT_OV_VTH_SIZE]=
{
	PMU_VOLT_04_200000_V, PMU_VOLT_04_300000_V,     PMU_VOLT_04_400000_V,   PMU_VOLT_04_450000_V,
	PMU_VOLT_03_825000_V, PMU_VOLT_04_300000_V,     PMU_VOLT_04_300000_V,   PMU_VOLT_04_300000_V
};
#endif

#else
const DCL_UINT32 chr_VBAT_CV_VTH[VBAT_CV_VTH_SIZE]=
{
	PMU_VOLT_03_775000_V,   PMU_VOLT_03_800000_V,   PMU_VOLT_03_825000_V,   PMU_VOLT_03_975000_V,
	PMU_VOLT_04_000000_V,   PMU_VOLT_04_025000_V, 	PMU_VOLT_04_050000_V,   PMU_VOLT_04_075000_V,
	PMU_VOLT_04_100000_V,   PMU_VOLT_04_125000_V,   PMU_VOLT_04_150000_V,   PMU_VOLT_04_162500_V,
    PMU_VOLT_04_175000_V,   PMU_VOLT_04_187500_V,   PMU_VOLT_04_200000_V,   PMU_VOLT_04_212500_V,
    PMU_VOLT_04_225000_V,   PMU_VOLT_04_237500_V,   PMU_VOLT_04_250000_V,   PMU_VOLT_04_275000_V,
    PMU_VOLT_04_300000_V,   PMU_VOLT_04_325000_V,   PMU_VOLT_04_350000_V,   PMU_VOLT_04_362500_V,
    PMU_VOLT_04_375000_V
};

const DCL_UINT32 chr_CS_VTH[CS_VTH_SIZE]=
{
	PMU_CHARGE_CURRENT_800_00_MA,   PMU_CHARGE_CURRENT_700_00_MA,
	PMU_CHARGE_CURRENT_650_00_MA,   PMU_CHARGE_CURRENT_550_00_MA,
	PMU_CHARGE_CURRENT_450_00_MA,   PMU_CHARGE_CURRENT_400_00_MA,
	PMU_CHARGE_CURRENT_200_00_MA,   PMU_CHARGE_CURRENT_70_00_MA
};

const DCL_UINT32 chr_VCDT_HV_VTH[VCDT_HV_VTH_SIZE]=
{
	PMU_VOLT_04_200000_V, PMU_VOLT_04_250000_V,     PMU_VOLT_04_300000_V,   PMU_VOLT_04_350000_V,
	PMU_VOLT_04_400000_V, PMU_VOLT_04_450000_V,     PMU_VOLT_04_500000_V,   PMU_VOLT_04_550000_V,
	PMU_VOLT_04_600000_V, PMU_VOLT_06_000000_V,     PMU_VOLT_06_500000_V,   PMU_VOLT_07_000000_V,
	PMU_VOLT_07_500000_V, PMU_VOLT_08_500000_V,     PMU_VOLT_09_500000_V,   PMU_VOLT_10_500000_V	    
};

#ifdef __DRV_BMT_HIGH_BATTERY_SUPPORT__
const DCL_UINT32 chr_VBAT_OV_VTH[VBAT_OV_VTH_SIZE]=
{
	PMU_VOLT_04_200000_V, PMU_VOLT_04_300000_V,     PMU_VOLT_04_400000_V,   PMU_VOLT_04_450000_V,
	PMU_VOLT_03_825000_V, PMU_VOLT_04_300000_V,     PMU_VOLT_04_300000_V,   PMU_VOLT_04_300000_V
};
#endif

#endif

// ============================================================
// ENUM
// ============================================================


// ============================================================
// structure
// ============================================================


// ============================================================
// typedef
// ============================================================



// ============================================================
// External Variables
// ============================================================


// ============================================================
// External function
// ============================================================


// ============================================================
DCL_UINT32 bmt_parameter_to_value(const DCL_UINT32 *parameter, const DCL_UINT32 array_size, const DCL_UINT32 val)
{
	DCL_UINT32 i;

	for(i=0;i<array_size;i++)
	{
		if (val == *(parameter + i))
		{
				return i;
		}
	}

	ASSERT(0);	// not find the value
	return 0;
}


DCL_STATUS bmt_set_register_value(const DCL_UINT32 offset, const DCL_UINT32 mask, const DCL_UINT32 value)
{
	kal_uint32 savedMask;
	
	savedMask = BMT_SaveAndSetIRQMask();
	DRV_BMT_SetData((CHR_CON0+offset),mask,value);
	BMT_RestoreIRQMask(savedMask);

	return STATUS_OK;
}
#endif //#if defined( __BMT_2_0_ARCHITECTURE__)


