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
 *    msdc_custom.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements msdc customer support
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 ****************************************************************************/
#include "drv_comm.h"
#include "msdc_def.h"                        

#ifdef __RF_DESENSE_TEST__
#include <rf_desense_test.h>
#endif

#if defined(__MSDC_SD_MMC__) && defined(__MSDC2_SD_MMC__)&& !defined(__MSDC_SD_SDIO__)
static  const kal_uint32 msdc_custom = (MSDC_HOT_PLUG|MSDC_WP|MSDC2_HOT_PLUG|MSDC2_WP);
#elif defined(__MSDC_SD_SDIO__) && defined(__MSDC2_SD_MMC__)
static  const kal_uint32 msdc_custom = (MSDC2_HOT_PLUG|MSDC2_WP|MSDC_SDIO4_SD1);
#elif defined(__MSDC_SD_MMC__) && defined(__MSDC2_SD_SDIO__)
static  const kal_uint32 msdc_custom = (MSDC_HOT_PLUG|MSDC_WP|MSDC_SD4_SDIO1);
#else
static const kal_uint32 msdc_custom = (MSDC_HOT_PLUG|MSDC_WP|MSDC2_HOT_PLUG|MSDC2_WP);
#endif
kal_uint8 MSDC_GetIOCtrlParam(void)
{
	kal_uint8 reg = 0;
	// it only apply to the SD card io control
	msdc_io_ctrl_struct msdc_io_ctrl_sd_custom = 
	{
		MSDC_ODC_8MA,	// driving capacity of CMD/BS and SCLK
		MSDC_ODC_8MA,	// driving capacity of data lines
		MSDC_ODC_SLEW_FAST, // slew rate of CMD/BS and SCLK
		MSDC_ODC_SLEW_FAST // slew rate of data lines
	};
#ifdef __RF_DESENSE_TEST__
	/* Argus Lin MAUI_02605973 
	    Modify msdc driving current */
	switch(rf_desense_get_curr_mode())
	{
	    case RF_DESENSE_MODE_MSDC_4MA:
	        msdc_io_ctrl_sd_custom.cmd_clk_odc = msdc_io_ctrl_sd_custom.dat_odc = MSDC_ODC_4MA;
	        break;
	    case RF_DESENSE_MODE_MSDC_8MA:
	        msdc_io_ctrl_sd_custom.cmd_clk_odc = msdc_io_ctrl_sd_custom.dat_odc = MSDC_ODC_8MA;
	        break;
	    default:
	        break;
	}
#endif /* endof #ifdef __RF_DESENSE_TEST__ */	
	reg = (msdc_io_ctrl_sd_custom.dat_slew << 7) | (msdc_io_ctrl_sd_custom.cmd_clk_slew << 6) 
			|(msdc_io_ctrl_sd_custom.dat_odc<<3)|(msdc_io_ctrl_sd_custom.cmd_clk_odc);
	return reg;
}

/*
	We provide this API because that memory card's layout affect the signal,
	customer can use this API to tuning the suitable DLT when their layout did need.
	In addition to solve the bad layout, we can also try to set a higher clk and tuning the DLT here,
	so that we can run in high CLK stablely.

*/
kal_int8 MSDC_GetDLTFromOPCLK(kal_uint32 opClk, kal_uint8 *setRED)
{
	*setRED = 0;
	
	if(1000 > opClk) //this means we use a CLK < 1Mhz, should be used to initialize a card
		return 0xf0;
	switch(opClk){
		case 45500:	//45.5 MHz CLK, this should be only used on MT6268 with second CLK source
			*setRED = 1;
			return 2;
			break;
		case 22750:	//22.75 MHz CLK, this should be only used on MT6268 with second CLK source
			return 4;
			break;
		case 30500:	//30.5 MHz CLK, this should be only used on MT6268 with first CLK source
			return 4;
		case 15250:	//15.25 MHz CLK, this should be only used on MT6268 with first CLK source
			return 4;
			break;
		case 13000:	//13 MHz CLK, this should be only used on MT6516 with first CLK source, 104000/13000 = 8
			return 8;
			break;
		case 26000:	//26 MHz CLK, this should be only used on MT6516 with first CLK source, 104000/26000 = 4
			return 4;
			break;
		case 24000:	//24 MHz CLK, this should be only used on MT6253T with 2nd CLK source, 48000/24000 = 2
			return 2;
			break;
		default:		//deafult return a non-zero value
			return 1;
			break;
	}
		
}

kal_uint32 MSDC_GetCustom(void)
{
	return msdc_custom;
}


#ifdef __CARD_DOWNLOAD__

/*************************************************************************
* FUNCTION
*  MSDC_QueryIsPowerControllable
*
* DESCRIPTION
*  Query if the power source of MSDC is controllable.
*
* PARAMETERS*	
*
* RETURNS
*  1: power controllable, e.g. PMIC, GPIO
*  0: not power controllable, e.g. battery, constant power
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool MSDC_QueryIsPowerControllable(void)
{
#if 0
/* under construction !*/
/* under construction !*/
#else
    /* PMIC, GPIO */
    return KAL_TRUE;
#endif
}

/*************************************************************************
* FUNCTION
*  MSDC_SetPower
*
* DESCRIPTION
*  Switch on/off the power if power source of MSDC is controllable.
*
* PARAMETERS*
*  enable   TRUE/FALSE: switch on power/switch off power
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void MSDC_SetPower(kal_bool enable)
{
    if (enable == KAL_TRUE)
    {
        /* some examples
        // Example 1: PMIC_6235_REG_API
        //pmu_set_vbt_en(KAL_TRUE);
        
        // Example 2: PMIC_6318_REG_API
        //pmic_vmc_enable(KAL_TRUE);

        // Example 3: AVANTECH6239_DEMO_BB
        //GPIO_WriteIO(1, GPIO_EXT_SD_LDO_SWITCH);
        */
        //pmu_set_vsim_sel(VSIM_SEL_3_0);
        //pmu_set_vsim(KAL_TRUE);
    }
    else
    {
        /* some examples
        // Example 1: PMIC_6235_REG_API
        //pmu_set_vbt_en(KAL_FALSE);
        
        // Example 2: PMIC_6318_REG_API
        //pmic_vmc_enable(KAL_FALSE);

        // Example 3: AVANTECH6239_DEMO_BB
        //GPIO_WriteIO(0, GPIO_EXT_SD_LDO_SWITCH);
        */
        //pmu_set_vsim_sel(VSIM_SEL_1_8);
        //pmu_set_vsim(KAL_FALSE);
    }
}

#endif//__CARD_DOWNLOAD__

#if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
// Config GPIOx as the 3V LDO turn on switch
kal_char MSDC_GetLDO_GPIO(void)
{
	return 4;
}

// Config GPIOx as the SIM to Exteranl SD card switch
kal_char MSDC_GetSwitch_GPIO(void)
{
	return 6;
}
/*bewlow comes after JRD SIM+ issue on 2007_03_08, add custom setting on "clock without sim+" and "ext_sd ldo" */
// Config GPIOx as the EXT_SD LDO turn on switch
kal_char MSDC_GetEXTLDO_GPIO(void)
{
	return 2;
}

//config in which value can we switch to EXT card
//can only be value 0 or 1
kal_char MSDC_GetSwitchDirection()
{
	//in JRD, GPIO 1 means EXT, 0 means SIM+
	return 0;
}
#endif //__SIM_PLUS__ or DRV_MSDC_DUAL_TCARD_BY_SWITCH

#if defined(__SIM_PLUS__)
//config using 24M or 13M clock when there is no SIM+
//0 for 13M, 1 for 24M
kal_char MSDC_GetClockWithoutSIMPlus()
{
	return MSDC_24M;
}
/*end of JRD SIM+ issue on 2007_03_08*/
#endif //__SIM_PLUS__
