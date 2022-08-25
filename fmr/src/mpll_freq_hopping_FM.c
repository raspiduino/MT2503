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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *  FM_test.c
 *
 * Project:
 * --------
 *   All
 *
 * Description:
 * ------------
 *   MPLL FH
 *
 * Author:
 * -------
 * -------
 *
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
 *******************************************************************************/
//#pragma arm section code = "PRIMARY_ROCODE", rodata = "PRIMARY_RODATA", zidata = "PRIMARY_ZI"
#include "l1_interface.h"
#include "l1d_cid.h"
#include "reg_base.h"
#include "l1_fh_interface.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "fmr_trc.h"
#include "kal_public_api.h"
#if defined(MT6250FM)
#include "flash_sfi_release.h"
#include "custom_EMI_release.h"
//power up sequence 20120614

const kal_uint8 HoppingTable_104_130_18[] = /* SF 104MHz, EMI 130MHz, 1.8V*/
{
	/* 760	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 770	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 780	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 790	*/
	0, 
	0, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 800	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 810	*/
	49, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	/* 820	*/
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	0, 
	0, 
	0, 
	0, 
	/* 830	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 840	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 850	*/
	0, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 860	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 870	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 880	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 890	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	0, 
	0, 
	0, 
	0, 
	/* 900	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 910	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 920	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 930	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 940	*/
	0, 
	0, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 950	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	38, 
	38, 
	38, 
	38, 
	/* 960	*/
	38, 
	38, 
	38, 
	38, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 970	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 980	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	38, 
	38, 
	38, 
	38, 
	/* 990	*/
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	/* 1000  */
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	/* 1010  */
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	0, 
	0, 
	0, 
	/* 1020  */
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 1030  */
	0, 
	0, 
	0, 
	0, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 1040  */
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 1050  */
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 1060  */
	49, 
	49, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	/* 1070  */
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	/* 1080  */
	38
};

const kal_uint8 HoppingTable_104_130_30[] = /* SF 104MHz, EMI 130MHz, 3.0V*/
{
	/* 760	*/
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	/* 770	*/
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	/* 780	*/
	21, 
	21, 
	21, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 790	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 800	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 810	*/
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	/* 820	*/
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	21, 
	21, 
	21, 
	21, 
	/* 830	*/
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	/* 840	*/
	21, 
	21, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 850	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 860	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 870	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 880	*/
	49, 
	49, 
	49, 
	49, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	/* 890	*/
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	/* 900	*/
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	/* 910	*/
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	/* 920	*/
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	/* 930	*/
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	49, 
	49, 
	49, 
	49, 
	/* 940	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 950	*/
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	/* 960	*/
	38, 
	38, 
	38, 
	38, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 970	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 980	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 990	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 1000  */
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	21, 
	21, 
	/* 1010  */
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	/* 1020  */
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	/* 1030  */
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	/* 1040  */
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	49, 
	49, 
	49, 
	49, 
	/* 1050  */
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 1060  */
	49, 
	49, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	/* 1070  */
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	/* 1080  */
	21
};

const kal_uint8 HoppingTable_78_104[] = /* SF 78MHz, EMI 104MHz*/
{
	/* 760	*/
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	/* 770	*/
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	/* 780	*/
	21, 
	21, 
	21, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 790	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 800	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 810	*/
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	/* 820	*/
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	21, 
	21, 
	21, 
	21, 
	/* 830	*/
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	/* 840	*/
	21, 
	21, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 850	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 860	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	49, 
	/* 870	*/
	49, 
	49, 
	49, 
	49, 
	49, 
	21, 
	21, 
	21, 
	21, 
	21, 
	/* 880	*/
	21, 
	21, 
	21, 
	21, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 890	*/
	0, 
	0, 
	0, 
	0, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	/* 900	*/
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	/* 910	*/
	38, 
	32, 
	32, 
	32, 
	32, 
	32, 
	32, 
	32, 
	32, 
	32, 
	/* 920	*/
	32, 
	32, 
	32, 
	32, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 930	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 940	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 950	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	38, 
	38, 
	38, 
	38, 
	/* 960	*/
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	/* 970	*/
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	/* 980	*/
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	32, 
	32, 
	32, 
	32, 
	/* 990	*/
	32, 
	32, 
	32, 
	32, 
	32, 
	21, 
	21, 
	21, 
	21, 
	21, 
	/* 1000  */
	21, 
	21, 
	21, 
	21, 
	21, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 1010  */
	0, 
	0, 
	0, 
	0, 
	0, 
	38, 
	38, 
	38, 
	38, 
	38, 
	/* 1020  */
	38, 
	38, 
	32, 
	32, 
	32, 
	32, 
	32, 
	32, 
	32, 
	32, 
	/* 1030  */
	32, 
	32, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	21, 
	/* 1040  */
	21, 
	21, 
	21, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 1050  */
	0, 
	0, 
	0, 
	32, 
	32, 
	32, 
	32, 
	32, 
	32, 
	38, 
	/* 1060  */
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	/* 1070  */
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	38, 
	/* 1080  */
	38
};



void FM_GET_HOPPING_INDEX(kal_int16 Freq,kal_int16*Index)
{
	/*0: 0~-2%
	* 21:-1~-3%
	* 32:-2~-4%
	* 38:-3~-5%
	* 41:-4~-6%
	* 49:-5~-7%
	*/
/*#ifdef __SFI_CLK_78MHZ__
	kal_int16 Hopping[2]={0,38};
#elif defined(__SFI_CLK_104MHZ__)
	kal_int16 Hopping[2]={0,49};
#else
#error "Unsupported SFI clock!"
#endif
	kal_uint8 Item=0;

	Item= Hopping_parameter[Freq-760];
	*Index=Hopping[Item];*/

if(SFI_Dev_WorkingFrequencyQuery() == SFI_CLK_78MHZ)
{
	if(custom_EMI_QueryFullSpeedClock() == EMI_CLK_104MHZ)	//50D
	{
		if(SFI_Dev_WorkingVoltageQuery() == SFI_Voltage_18)
		{
			*Index = HoppingTable_78_104[Freq-760];
		}
		else if(SFI_Dev_WorkingVoltageQuery() == SFI_Voltage_30)
		{
			*Index = HoppingTable_78_104[Freq-760];
		}
		else
		{
			*Index = 0;
			kal_trace(TRACE_INFO,FM_INFO_SFI_VOLTAGE_UNKNOWN);
		}
	}
	else if(custom_EMI_QueryFullSpeedClock() == EMI_CLK_130MHZ)	
	{
		if(SFI_Dev_WorkingVoltageQuery() == SFI_Voltage_18)
		{
			*Index = 0;
		}
		else if(SFI_Dev_WorkingVoltageQuery() == SFI_Voltage_30)
		{
			*Index = 0;
		}
		else
		{
			*Index = 0;
			kal_trace(TRACE_INFO,FM_INFO_SFI_VOLTAGE_UNKNOWN);
		}
	}
	else
	{
		*Index = 0;	
	}
}
else if(SFI_Dev_WorkingFrequencyQuery() == SFI_CLK_104MHZ)
{
	if(custom_EMI_QueryFullSpeedClock() == (emi_clock_enum)EMI_CLK_104MHZ)	
	{
		if(SFI_Dev_WorkingVoltageQuery() == SFI_Voltage_18)
		{
			*Index = 0;
		}
		else if(SFI_Dev_WorkingVoltageQuery() == SFI_Voltage_30)
		{
			*Index = 0;
		}
		else
		{
			*Index = 0;		
			kal_trace(TRACE_INFO,FM_INFO_SFI_VOLTAGE_UNKNOWN);
		}
	}
	else if(custom_EMI_QueryFullSpeedClock() == EMI_CLK_130MHZ)	
	{
		if(SFI_Dev_WorkingVoltageQuery() == SFI_Voltage_18)
		{
			*Index = HoppingTable_104_130_18[Freq-760];
		}
		else if(SFI_Dev_WorkingVoltageQuery() == SFI_Voltage_30)
		{
			*Index = HoppingTable_104_130_30[Freq-760];
		}
		else
		{
			*Index = 0;		
			kal_trace(TRACE_INFO,FM_INFO_SFI_VOLTAGE_UNKNOWN);
		}
	}
	else
	{
		*Index = 0;	
	}	
}
else
{
	*Index = 0;	
	kal_trace(TRACE_INFO,FM_INFO_SFI_CLK_NOT104Mor78M);
}

	return;
}
#elif (defined(MT6260FM) || defined(MT6261FM))
const kal_uint8 HoppingTable[] =
{
	/* 650	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 660	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	41, 
	41, 
	/* 670	*/
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	/* 680	*/
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	0, 
	0, 
	0, 
	0, 
	/* 690	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 700	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 710	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 720	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 730	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 740	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 750	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 760	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 770	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 780	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 790	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 800	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 810	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 820	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 830	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 840	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 850	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 860	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 870	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 880	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 890	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 900	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 910	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 920	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 930	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 940	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 950	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 960	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 970	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 980	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	/* 990	*/
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	41, 
	/* 1000  */
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	/* 1010  */
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	/* 1020  */
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	/* 1030  */
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	/* 1040  */
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	/* 1050  */
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	/* 1060  */
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	/* 1070  */
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	41, 
	/* 1080  */
	41
};

void FM_GET_HOPPING_INDEX(kal_int16 Freq,kal_int16*Index)
{
	/*0: 0~-2%
	* 21:-1~-3%
	* 32:-2~-4%
	* 38:-3~-5%
	* 41:-4~-6%
	* 49:-5~-7%
	*/

	*Index = HoppingTable[Freq-650];
}
#endif
/*Part1: FM_LCD_Cycle_Calculate */
#if IS_MPLL_FH_SUPPORT&&defined(FM_RADIO_ENABLE)

// For LCDFH
#if IS_CHIP_MT6252L || IS_CHIP_MT6252H
#define LCD_PCNF0               ((APBADDR32)(LCD_base+0x30))            /* LCD Clock Control Register                    */
#define LCD_WROICON             ((APBADDR32)(LCD_base+0x80))            /* LCD Clock Control Register                    */
#else
#define LCD_PCNF0               ((APBADDR32)(LCD_base+0x18))            /* LCD Clock Control Register                    */
#define LCD_WROICON             ((APBADDR32)(LCD_base+0x50))            /* LCD Clock Control Register                    */
#endif

#if IS_CHIP_MT6253 || IS_CHIP_MT6236 || IS_CHIP_MT6252L || IS_CHIP_MT6252H
unsigned long LCD_to_FM_Noise[MPLL_FH_TABLE_SIZE]  = {0};
kal_bool is_LCD_setted = KAL_FALSE;
#endif

void FM_LCD_Cycle_Calculate( void )
{
#if IS_CHIP_MT6252L || IS_CHIP_MT6252H
   signed long b32;
   int wst,c2wh,period,LCD_write_cycle;
   int LCD_noise_one = 1<<LCD_ONE_SCALE;
   signed short i;
   signed long LCD_Noise_F[MPLL_FH_TABLE_SIZE] = {0};
   unsigned char hoptype = L1D_FH_GetHoppingType();

   b32=HW_READ(LCD_PCNF0);
   wst= b32&0x3F;
   c2wh=(b32>>12)&0x3;
   b32=HW_READ(LCD_WROICON);
   period=(b32>>16)&0xFF;
   LCD_write_cycle=(period>c2wh)?wst+period+3:wst+c2wh+3;

   for(i=0;i<MPLL_FH_TABLE_SIZE;i++)
   {
      LCD_Noise_F[i]=(MPLL_F[hoptype][i]*LCD_noise_one)/(MPLL_F_FACTOR*(LCD_write_cycle)*4);
      //Multiply LCD_Noise by 100 to resever floating point
      //divide 2^14 to reduce LCD_noise_one scale
      LCD_Noise_F[i]=(LCD_Noise_F[i]*LCD_CLK_SCALE)>>LCD_ONE_SCALE;
      //From FM test, really LCD_data_pin noise will be half of the formula result
      LCD_to_FM_Noise[i]=LCD_Noise_F[i]>>1;
      //LCD_to_GSM_Noise[i]=(LCD_Noise_F[i]<<ARFCN_SCALE)/LCD_CLK_SCALE;
   }
   is_LCD_setted = KAL_TRUE;
#elif IS_CHIP_MT6253 || IS_CHIP_MT6236
   signed long b32;
   int if_clk, wst, c2wh, period, noise_ratio;
   int ratio_AHB = RATIO_AHB_VALUE;
   int LCD_noise_one = 1<<LCD_ONE_SCALE;
   signed short i;
   signed long  LCD_Noise_F[MPLL_FH_TABLE_SIZE] = {0};

   #if IS_CHIP_MT6253
   unsigned char hoptype = L1D_FH_GetHoppingType();
   #endif

   b32 = HW_READ( LCD_PCNF0 );
   wst = ( b32>>8 ) & 0x1F;
   if_clk = ( b32>>14 ) & 0x3;
   c2wh = ( b32>>28 ) & 0x3;
   b32 = HW_READ( LCD_WROICON );
   period = ( b32>>16 ) & 0x1FF;
   noise_ratio = ratio_AHB;

   switch( if_clk )
   {
      case 1:
      {  noise_ratio = noise_ratio<<2;
         break;
      }
      case 2:
      {  noise_ratio = noise_ratio<<1;
         break;
      }
      default:
      {  break;
      }
   }

   #if IS_CHIP_MT6253 || IS_CHIP_MT6236
   period = (period+1)/noise_ratio; // only get the integer part
   #endif
   for( i = 0; i < MPLL_FH_TABLE_SIZE; i++ )
   {
      #if IS_CHIP_MT6236
      LCD_Noise_F[i] = (MPLL_F[i]*LCD_noise_one)/(MPLL_F_FACTOR*(wst+c2wh+period+3)*noise_ratio);
      #else //MT6253
      LCD_Noise_F[i] = (MPLL_F[hoptype][i]*LCD_noise_one)/(MPLL_F_FACTOR*(wst+c2wh+period+3)*noise_ratio);
      #endif /*IS_CHIP_MT6236*/
      //Multiply LCD_Noise by 100 to resever floating point
      //divide 2^14 to reduce LCD_noise_one scale
      LCD_Noise_F[i] = (LCD_Noise_F[i]*LCD_CLK_SCALE)>>LCD_ONE_SCALE;
      //From FM test, really LCD_data_pin noise will be half of the formula result
      LCD_to_FM_Noise[i] = LCD_Noise_F[i]>>1;
   }

   is_LCD_setted = KAL_TRUE;
   kal_prompt_trace(MOD_FMR, "MT6253 FM_LCD_Cycle_Calculate");
#endif /*IS_CHIP_MT6253 || IS_CHIP_MT6236*/
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#else
void FM_LCD_Cycle_Calculate( void )
{
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif /*IS_MPLL_FH_SUPPORT*/
/*Part1 End */

/*Part2: FH_get_FM_frequency_hopping_set_by_calc*/
#if IS_MPLL_FH_SUPPORT&&defined(FM_RADIO_ENABLE)

#if IS_CHIP_MT6253
#define FM_COLLISION_RANGE              19 // = 0.19*LCD_CLK_SCALE

void FH_get_FM_frequency_hopping_set_by_calc( int ch_freq /*scaled FM_scale1 times*/, sFHset* _fhset )
{
   long clk, LCD_noise;
   unsigned short MPLL_index = 0;
   signed short FM_freq;
   unsigned char hoptype = L1D_FH_GetHoppingType();
   unsigned short MPLL_CLK_BASE[2] = {980, 1040};       /*{Down hopping, Up hopping}*/
   kal_int16 para1=9800,para2=10400;

   //Multiply L1d_FM_freq by 10 to reserve the floating point
   FM_freq = ch_freq * 10; // 10 = LCD_CLK_SCALE/10
   if( hoptype == DOWN_HOPPING )
   {
		para1 = 9800;  	
		para2 = 10400;
   }
   else //up hopping
   {
	   para1 = 10400;   
	   para2 = 11000;
   }
	if((FM_freq>=para1-FM_COLLISION_RANGE) && (FM_freq<=para2+FM_COLLISION_RANGE))
	{  
		MPLL_index = ( FM_freq - para1 ) / 50 + 2; // 50 = LCD_CLK_SCALE/2
		MPLL_index = ( MPLL_index >= MPLL_FH_TABLE_SIZE ) ? ( MPLL_index - MPLL_FH_TABLE_SIZE ) : MPLL_index;
	}

   if( is_LCD_setted )
   {
      clk = MPLL_CLK_BASE[hoptype] * 10 + 50 * MPLL_index; // 50 = LCD_CLK_SCALE/2
      LCD_noise = LCD_to_FM_Noise[MPLL_index];

      if( LCD_noise == 0 )
      {  EXT_ASSERT(0, 0, 0, 0);  }

      if( clk < FM_freq )
      {
         while( clk < FM_freq + FM_COLLISION_RANGE )
         {  clk = clk +LCD_noise;
            if( ( clk - FM_COLLISION_RANGE <= FM_freq ) && ( FM_freq <= clk+FM_COLLISION_RANGE ) )
            {  MPLL_index = ( ( MPLL_index + 2 ) >= MPLL_FH_TABLE_SIZE ) ? ( MPLL_index + 2 - MPLL_FH_TABLE_SIZE ) : ( MPLL_index + 2 );
               break;
            }
         }
      }
      else
      {
         while( clk > FM_freq - FM_COLLISION_RANGE )
         {  clk = clk - LCD_noise;
            if( ( clk - FM_COLLISION_RANGE <= FM_freq ) && ( FM_freq <= clk + FM_COLLISION_RANGE ) )
            {  MPLL_index = ( MPLL_index + 2 >= MPLL_FH_TABLE_SIZE ) ? ( MPLL_index + 2 - MPLL_FH_TABLE_SIZE ) : ( MPLL_index + 2 );
               break;
            }
         }
      }
   }

   *_fhset = MPLL_index;
   kal_prompt_trace(MOD_FMR, "MT6253 FH_get_FM_frequency_hopping_set_by_calc %x, %x,", ch_freq, *_fhset);
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#elif IS_CHIP_MT6236

#define FM_COLLISION_RANGE              96 // = 0.8MHz*LCD_CLK_SCALE, where 0.8MHz is FM guard band

const int MPLL_F_FM[MPLL_FH_TABLE_SIZE]=
{
   11960, //(104-3.25/6*8)*LCD_CLK_SCALE
   12025, //(104-3.25/6*7)*LCD_CLK_SCALE
   12090, //(104-3.25/6*6)*LCD_CLK_SCALE
   12155, //(104-3.25/6*5)*LCD_CLK_SCALE
   12220, //(104-3.25/6*4)*LCD_CLK_SCALE
   12285, //(104-3.25/6*3)*LCD_CLK_SCALE
   12350, //(104-3.25/6*2)*LCD_CLK_SCALE
   12415, //(104-3.25/6*1)*LCD_CLK_SCALE
   12480, //(104-0       )*LCD_CLK_SCALE
};

void FH_get_FM_frequency_hopping_set_by_calc( int ch_freq /*scaled FM_scale1 times*/, sFHset* _fhset )
{
   long MPLL_clk, LCD_noise;
   unsigned short MPLL_index = 0;
   short FM_freq, FM_freq_l, FM_freq_u;
   char i;
   kal_bool MPLL_Is_Usable[MPLL_FH_TABLE_SIZE];

   FM_freq = ch_freq * 12; // 12 = LCD_CLK_SCALE/10
   FM_freq_l = FM_freq - FM_COLLISION_RANGE;
   FM_freq_u = FM_freq + FM_COLLISION_RANGE;

   // jason: set false if collision, set true if safe
   for( i = 0; i < MPLL_FH_TABLE_SIZE; i++ )
      MPLL_Is_Usable[i] = ( ( FM_freq_l <= MPLL_F_FM[i] ) && ( FM_freq_u >= MPLL_F_FM[i] ) ) ? KAL_FALSE : KAL_TRUE;

   // jason: record current FM freq, from which MPLL has hopped away
   // l1dfh.FM_Freq_old=l1dfh.FM_Freq;

   if( is_LCD_setted )
   {
      for( i = 0; i < MPLL_FH_TABLE_SIZE; i++ )
      {
         if( MPLL_Is_Usable[i] == KAL_FALSE ) // if 0, no need to check LCD noise, continue next freq
            continue;

         MPLL_clk  = MPLL_F_FM[i];
         LCD_noise = LCD_to_FM_Noise[i];

         if( LCD_noise == 0 )
         {  EXT_ASSERT(0, 0, 0, 0);  }

         if( MPLL_clk < FM_freq )
         {
            while( MPLL_clk < FM_freq_u )
            {
              if( ( FM_freq_l <= MPLL_clk ) && ( FM_freq_u >= MPLL_clk ) ){ MPLL_Is_Usable[i] = KAL_FALSE; break; }
               MPLL_clk += LCD_noise;
            }
         }
         else
         {
            while( MPLL_clk > FM_freq_l )
            {
               if( (FM_freq_l <= MPLL_clk ) && ( FM_freq_u >= MPLL_clk ) ){ MPLL_Is_Usable[i] = KAL_FALSE; break;  }
               MPLL_clk -= LCD_noise;
            }
         }
      }
   }

   MPLL_Is_Usable[0] = KAL_FALSE; // jason: for MT6236, bit 0 is bypassed because DSP can not support 99.67MHz
   for( i = 0; i < MPLL_FH_TABLE_SIZE; i++ ) // tranform from array to hex number
      MPLL_index |= MPLL_Is_Usable[i] << i;

   *_fhset = MPLL_index;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#elif IS_CHIP_MT6256

extern const unsigned long fh_set_fm_lsb[321];
extern const unsigned long fh_set_fm_msb[321];

void FH_get_FM_frequency_hopping_set_by_calc( int ch_freq /*scaled FM_scale1 times*/, sFHset* _fhset )
{
   unsigned int idx;

   if( ( ch_freq >= 760 ) && ( ch_freq <= 1080 ) )
   {  idx = ch_freq - 760; /*idx: 0~320*/
      _fhset->fh_set_l = fh_set_fm_lsb[idx];
      _fhset->fh_set_h = fh_set_fm_msb[idx];
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

const unsigned long fh_set_fm_lsb[321] =
{  0x3F88F3CF, 0x915A5256, 0xE09746A7, 0x7EAEAEBA, 0x4F62DF1E,
   0x0574516A, 0x013F8EDB, 0x0015FFB7, 0x0006FB59, 0x0001D5EF,
   0x000032F3, 0x000002BF, 0x000000BC, 0x0000001B, 0x00000006,
   0xB8000000, 0xE8000000, 0xD4800000, 0x8D080000, 0xFBB80000,
   0x57560000, 0xFA4B5800, 0x66E56F00, 0xBDEAA5C0, 0x591B5478,
   0x1697602A, 0x23CCEEA4, 0x90F89F15, 0x62251361, 0xB7E3AAED,
   0xFB716DBD, 0x677FA753, 0x2FF7FA4A, 0xBD7FF028, 0xEBBDF4B7,
   0x6CD7B615, 0x0D0CFECF, 0x031DB7B7, 0x00DCFB57, 0x002C9EEB,
   0x000099B7, 0x00001B4F, 0x00001FCB, 0x000001AA, 0x000000EF,
   0x0000000E, 0x80000006, 0xC0000001, 0xE0000000, 0x64800000,
   0x2F600000, 0x31700000, 0xB2FDC000, 0xCA75B000, 0x64DFB400,
   0x3EF77F00, 0x1D67A740, 0x01B9DE68, 0x00957F6C, 0x0003A7F5,
   0x00067DED, 0x0000C77E, 0x0000105E, 0x000002E8, 0x00000094,
   0x00000037, 0x00000007, 0x00000000, 0x00000000, 0x00000000,
   0xA0000000, 0x88000000, 0x51000000, 0xAED00000, 0x6C740000,
   0x9FAE8000, 0xE1D50000, 0xFEFF8800, 0x9D547800, 0x49BF2F80,
   0xA6A6A104, 0xFE4B5D53, 0x4EE52FFB, 0x55EC2DAC, 0x983F8DB9,
   0xF867F15E, 0xBE11DE4B, 0x50DD3F18, 0x22ACBFC8, 0x3C468DBC,
   0x2FBBD17F, 0x07D4B22F, 0x019EFE19, 0x002E0380, 0x0003E834,
   0x0001F4AF, 0x0000371D, 0x00000FF3, 0x000001EC, 0x0000006C,
   0x8000000D, 0x80000001, 0xA2000000, 0xDF000000, 0xDB400000,
   0x76980000, 0xB6EA4000, 0x8FFF6000, 0xA9FEE400, 0xCF9ADD00,
   0xE3C353B0, 0x6F0B7A66, 0xC743BEAD, 0xFBE9FFE5, 0x75EE77FF,
   0x06DF6F7F, 0x026BD51F, 0x007CDB23, 0x000DBAB4, 0x000246A7,
   0x000049B5, 0x00001037, 0x000002C7, 0x000000F9, 0x0000002E,
   0x20000005, 0x8C000001, 0xE1000000, 0x6DA00000, 0x7E000000,
   0xFFE50000, 0x5DE90000, 0x21FE0800, 0x07FFC000, 0x019DD0C0,
   0x0025F258, 0x00136EAA, 0x0002ADE1, 0x00001DEC, 0x000013FD,
   0x000002FF, 0x000000DF, 0x0000000B, 0x20000004, 0x9C000003,
   0x8A000000, 0xA9200000, 0xD7B00000, 0xE8A40000, 0xCEE54000,
   0x7A9C2000, 0x7E095C00, 0x06ED3A00, 0x01DC4EA0, 0x007E29FC,
   0x000FE4AE, 0x0003F5B5, 0x00007F27, 0x00001F15, 0x000003F3,
   0x000000DA, 0x0000007A, 0xB800000F, 0xBC000001, 0x15000000,
   0xA9700000, 0xFFFC0000, 0xC2AF0000, 0xA2176000, 0x97DC7C00,
   0xE9A97E00, 0x1BE72680, 0x0A8C9DE0, 0xADD6E33C, 0xFC34659D,
   0xE0163FB3, 0xEF7DA766, 0x76D96C9F, 0xA6D32D52, 0x3FDF1F8A,
   0x59EE90D1, 0xC96FABBE, 0x9B5EBC27, 0xBA12EDFD, 0x3D13FDED,
   0xD5919FF4, 0x9171C3FE, 0xB77D08DF, 0x8D8B567F, 0x1963E1EF,
   0xD86CDF23, 0x913A5A16, 0xFBBA6ABA, 0x61B9DEE0, 0xBF851BEC,
   0xEDD552AF, 0x2D7471D6, 0x26FF7A6C, 0x044BEE7D, 0x007FEBE2,
   0x007ADEA8, 0x000B959C, 0x000383AD, 0x00008475, 0x000019DF,
   0x0000011B, 0x80000157, 0x80000072, 0x60000013, 0x44000002,
   0x5A000000, 0x5A500000, 0x3BD00000, 0xF3AF0000, 0x1DAE8000,
   0xEB3EA000, 0xB5E46C00, 0x6E287900, 0x75DE7A80, 0x7672DA30,
   0xD7DD76F4, 0x12FBDCFB, 0x47EFB3E2, 0xF1EFCFCE, 0xFE6EA576,
   0xEFDEAFDE, 0x37EAAD2B, 0x6EEF8D95, 0xACCE81BF, 0xDE7685BD,
   0xDADCE335, 0xED47FD95, 0x0964BD51, 0x7657E6DC, 0x1F04ACEC,
   0xE7F12FEF, 0x15EC2DAE, 0x267E29F6, 0x04AFF6AC, 0x0243B8ED,
   0x004CEEA4, 0x00033DA8, 0x0004AFE1, 0x0000A9B0, 0x00003CFE,
   0x00000C3D, 0x00000087, 0xC00000A9, 0x5000002C, 0x88000000,
   0xD1000000, 0x29700000, 0x7B380000, 0xB2FB0000, 0x131F8000,
   0x7EE24000, 0x659DD600, 0xCB6A4300, 0x16EBD5C0, 0xE99FD260,
   0x653695D6, 0x2F7DA766, 0x029B6C93, 0x03929CFE, 0x00B4C7BD,
   0x000D72AB, 0x00075CE1, 0x0001F07C, 0x00001B8A, 0x00000633,
   0x80000350, 0x400000DD, 0x9800007B, 0xB400000F, 0x8D000003,
   0xBA700000, 0x3DC80000, 0xAF260000, 0xB3ECC000, 0x9FEB3000,
   0x7EAEAC00, 0x49CF8800, 0x5363A780, 0x55EDAC30, 0x943F0EC8,
   0x145AAE7C, 0x1853BAC2, 0x8054EEEB, 0xE1443E6A, 0xD8746DD3,
   0xFA8D69FB, 0xED8A39AB, 0x5B72C97B, 0x7FF8B344, 0x01FE094D,
   0x4F7EC46E, 0xA0FBF00E, 0x449FFC8A, 0x5602FD2F, 0x1490BFA2,
   0x94216DE0, 0x644C1FEC, 0xE88765BE, 0x2685C3FE, 0x1FC712AD,
   0x06B783AA, 0x019987B7, 0x00728628, 0x0009D6D1, 0x000776F5,
   0x00015CF1, 0x000035D3, 0x00001B95, 0x800003A5, 0xC000002D,
   0xD8000076, 0xAE00001C, 0xD9800006, 0x97E00001, 0xEDE80000,
   0xF87E0000
};

const unsigned long fh_set_fm_msb[321] =
{  0x06F56640, 0x018AE2C0, 0x006CFB40, 0x0032FCC0, 0x001BE880,
   0x000D2B40, 0x8007D9E0, 0xC000B5E0, 0xC0001B4C, 0x0000A726,
   0x00006E94, 0x22000778, 0xFE000CAF, 0xE280053E, 0x6AA0002B,
   0x1AA00177, 0x15B000DD, 0x0F48006A, 0x01D0002F, 0x0232003E,
   0x00F8000F, 0x0015C02B, 0x0009F01E, 0x0003B82B, 0x00039836,
   0x00001239, 0x0001FF33, 0x8001B780, 0xC0017389, 0x00004D82,
   0xA0000B80, 0xB0000A80, 0x500005C0, 0x240000C0, 0x2D000100,
   0xA2800000, 0xF8E00000, 0x56C00040, 0x37800040, 0x89D00000,
   0xC63C0014, 0xDBF2003C, 0xECCB002F, 0x79362015, 0x3119D034,
   0x87EE781D, 0x7AB72033, 0x3EB8FA0C, 0x35CAD50F, 0x19442F02,
   0x0471F200, 0x033D5F80, 0x00DBF780, 0x006B9A80, 0x00138B80,
   0x001F5DC0, 0x800D6C40, 0xC006DB80, 0xC001F800, 0xE0012EC0,
   0x7000C660, 0xA801B5C0, 0xD6005F58, 0x77800F20, 0xA0C00DB8,
   0x672002D7, 0x02D00778, 0xBAB800ED, 0x7A9C00DB, 0x908E0077,
   0x7126000C, 0x39440017, 0x1475800D, 0x037DE069, 0x01FCD006,
   0x02696838, 0x00F33826, 0x003B4611, 0x001AC735, 0x001633AD,
   0x800AA191, 0x0005878F, 0x8001F38A, 0xD0017D01, 0xE800FB01,
   0x7000AF00, 0x3B003640, 0x3CC01740, 0x15200140, 0x13000200,
   0x1BE003A0, 0x07E00120, 0x03E60070, 0x01300074, 0x001C0076,
   0x001F003E, 0x001EC07D, 0x800F207E, 0x4001D017, 0x8001C017,
   0x0001E025, 0xB000F038, 0x78007A39, 0xBC005A1E, 0x6B001F0E,
   0x37C00F8C, 0x29A0078B, 0x1E000702, 0x0DD00040, 0x06380080,
   0x03CA0040, 0x00B20040, 0x000A0040, 0x001D0040, 0x001F4000,
   0x800D0040, 0x40020000, 0x4003D010, 0x0000B82C, 0xF001BA39,
   0x6C003F3E, 0xC5001B97, 0x63000D15, 0x7700060D, 0xE9C00583,
   0xB7A00202, 0x4B000341, 0x57D00040, 0x93FC0040, 0xF9EC0000,
   0x7ED60040, 0x443A0000, 0x115C8040, 0x3B732060, 0x1EE75020,
   0x0CC04830, 0x4261800C, 0xB37DEE29, 0xE1F6D212, 0x9160ABAE,
   0xA922B13B, 0xD79E2E8E, 0xCABD978B, 0xC4FCEF80, 0x726A37C1,
   0xB9F21B81, 0xCDF319C0, 0x7D20CCC0, 0x3F1FE800, 0x07D1F2C0,
   0x10EAFBC0, 0x17758EE0, 0x09B7E3C0, 0x05DE71D8, 0x00391C9E,
   0x005B48E6, 0x0036C4F8, 0x001682CE, 0x8009A7A0, 0x400CF1B0,
   0xA0033ECF, 0x2002DF71, 0x4001AD8E, 0x18007C63, 0xA6019A73,
   0x60006DFE, 0xF0C012F7, 0x59A00D54, 0x6F80015F, 0xB410009D,
   0xBB4800D5, 0xFF3000B7, 0x8FD200B6, 0xC5640020, 0xC36C004A,
   0xF338806E, 0xCB562073, 0xF7FF006C, 0x48F5402B, 0x97EE500D,
   0x8AA5083D, 0x66C6CC32, 0x21E5A036, 0x33F96633, 0xCDB1572E,
   0xA7EF6B9B, 0x733D578B, 0x3BD3CB19, 0x1FF6A582, 0x1461A643,
   0x0868D7C1, 0x0798EB40, 0x0107B380, 0x00D7F900, 0x007CAF00,
   0x0034B140, 0x00173E40, 0x400D5F40, 0x2007C370, 0x0003E7AC,
   0x60017F22, 0x2801E5AA, 0x3401B579, 0xF900FE00, 0xFC002FF8,
   0x4F4011F3, 0xE720082C, 0x91800677, 0xF94005EF, 0x1F30026E,
   0x2E9201EB, 0x174800EA, 0x0AEE0060, 0x06DE002E, 0x027A0070,
   0x03224076, 0x005E206E, 0x00159803, 0x001E6016, 0x80049816,
   0x400DBA1E, 0x6004783C, 0xC0031EBD, 0x1003CE07, 0x7800D1B7,
   0xD800283F, 0x9B000712, 0x0F00650D, 0xF6801C47, 0xAAC01E81,
   0x97E00B80, 0x6AE803C0, 0x70F80080, 0x0F1801C0, 0x869E0100,
   0xE6C800C0, 0xF7780060, 0xEA3B0040, 0xE31B4030, 0x7401E04E,
   0x78879072, 0x2C4FC00D, 0x152BE00A, 0xCB9BEC25, 0x97D2D636,
   0xA973A73C, 0xB3F774A4, 0xA819B6BB, 0xA6F9FEAB, 0x601CFD9E,
   0x30FC3292, 0x334B37DF, 0x086E5383, 0x1D415341, 0x06C75EC0,
   0x00D9C240, 0x0357F240, 0x0031FEC0, 0x0062CD40, 0x801224E0,
   0x40128E40, 0xC0073760, 0xE00F8DE8, 0x0001F4FC, 0x6003E9E6,
   0x780062DE, 0x0C01A1BD, 0xC1012237, 0x3580D17F, 0xDBC0186D,
   0xBA6008B7, 0x4B100C27, 0x6F90020B, 0x3BD00379, 0x8DC40508,
   0x51DA0150, 0x5FFE0020, 0x66DC00A2, 0x42790010, 0x039B8034,
   0x1D73E07A, 0x0622105F, 0x108F7856, 0x0F9BF833, 0x037F583F,
   0x012FCA30, 0x00835F2D, 0x0070CB34, 0x00102391, 0x001ECCBB,
   0x4007FF38, 0x80097D3A, 0x8005538E, 0xA00015CC, 0x30008FC1,
   0xE801A803, 0xF1017D80, 0x9D001240, 0xEA0073C0, 0x3F801DC0,
   0x6F801C40, 0x31F00340, 0x2EC00200, 0x1C7803E0, 0x0CB401D0,
   0x04DA0154, 0x05EC00FE, 0x02E80029, 0x00E80037, 0x006DA01E,
   0x002A203D, 0x400BD01F, 0xC019607D, 0xA0037829, 0xE005F011,
   0xA0009C1E, 0x28014A39, 0xD4015CB5, 0xBD014BA2, 0xCD806323,
   0xFDC04FBA
};

#elif IS_CHIP_MT6251
#define FMR_PCB_BOARD_2L 1
extern const unsigned char FM_FH_idx[321];

void FH_get_FM_frequency_hopping_set_by_calc( int ch_freq /*scaled FM_scale1 times*/, sFHset* _fhset )
{  unsigned int idx;

   if( ( ch_freq >= 760 ) && ( ch_freq <= 1080 ) )
   {  idx = ch_freq - 760; /*idx: 0~320*/
      *_fhset = FM_FH_idx[idx];
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#if defined(FMR_PCB_BOARD_2L)
const unsigned char FM_FH_idx[321] =
{    0,   2,   0,   1,   2,   1,   0,   0,   0,   0,
     0,   0,   1,   0,   0,   1,   7,  13,  16,  25,
    102, 102, 102, 102, 101, 102, 101, 101, 102, 101,
     1,   0,   0,   0,   0,   0,   0,   2,   1,   0,
     0,   0,   0,   2,   4,   0,   1,   0,   0,   0,
     0,   2,   2,   0,   0,   0,   0,   0,   0,   1,
     0,   1,   0,   1,   0,   3,   0,   1,   7,  12,
    16,  22,  28,  34,  40,  47,  53,  59,   0,   1,
     0,   0,   0,   0,   0,   1,   0,   2,   2,   0,
     0,   0,   1,   0,   0,   0,   0,   0,   2,   0,
     1,   0,   2,   9,  12,  16,  23,  28,  34,  40,
    46,  53,   0,   3,   9,  13,  17,  24,  29,  35,
    40,  46,  53,   0,   0,   0,   0,   5,   9,  14,
    17,  24,  31,  37,  41,  46,  54,   1,   3,   0,
     0,   0,   0,   0,   0,   1,   7,  11,  14,  20,
    25,  32,  38,  44,  48,  54,   5,   0,   0,   0,
     2,   1,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   6,  12,  15,  21,  25,  30,  35,  40,
    46,  52,   0,   0,   0,   0,   2,   1,   0,   0,
     0,   1,   3,   1,   3,   0,   1,   0,   1,   2,
     1,   0,   2,   0,   2,   0,   0,   1,   0,   1,
     2,   6,  10,  13,  18,  24,  28,  36,  39,  44,
    50,   4,   0,   0,   0,   2,   1,   0,   0,   0,
     0,   0,   0,   0,   1,   0,   0,   3,   4,   7,
    12,  16,  18,  26,  28,  33,  41,  43,   0,   0,
     0,   2,   0,   2,   2,   0,   0,   0,   0,   0,
     0,   1,   0,   0,   0,   1,   3,   3,   0,   0,
     0,   0,   2,   1,   4,   1,   5,  10,  13,  16,
    22,  26,  31,  36,  40,  46,   1,   0,   1,   0,
     0,   0,   0,   1,   0,   0,   1,   1,   0,   1,
     0,   1,   1,   0,   0,   2,   0,   0,   3,  10,
    13,  16,  19,  25,  31,  33,  38,  45,   0,   1,
     1
};
#else
const unsigned char FM_FH_idx[321] =
{    0,   2,   0,   1,   2,   1,   0,   0,   0,   0,
     0,   0,   1,   0,   0,   1,   7,  13,  16,  25,
    30,  37,  43,  50,  56,  64,   2,   0,   0,   0,
     1,   0,   0,   0,   0,   0,   0,   2,   1,   0,
     0,   0,   0,   2,   4,   0,   1,   0,   0,   0,
     0,   2,   2,   0,   0,   0,   0,   0,   0,   1,
     0,   1,   0,   1,   0,   3,   0,   1,   7,  12,
    16,  22,  28,  34,  40,  47,  53,  59,   0,   1,
     0,   0,   0,   0,   0,   1,   0,   2,   2,   0,
     0,   0,   1,   0,   0,   0,   0,   0,   2,   0,
     1,   0,   2,   9,  12,  16,  23,  28,  34,  40,
    46,  53,   0,   3,   9,  13,  17,  24,  29,  35,
    40,  46,  53,   0,   0,   0,   0,   5,   9,  14,
    17,  24,  31,  37,  41,  46,  54,   1,   3,   0,
     0,   0,   0,   0,   0,   1,   7,  11,  14,  20,
    25,  32,  38,  44,  48,  54,   5,   0,   0,   0,
     2,   1,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   6,  12,  15,  21,  25,  30,  35,  40,
    46,  52,   0,   0,   0,   0,   2,   1,   0,   0,
     0,   1,   3,   1,   3,   0,   1,   0,   1,   2,
     1,   0,   2,   0,   2,   0,   0,   1,   0,   1,
     2,   6,  10,  13,  18,  24,  28,  36,  39,  44,
    50,   4,   0,   0,   0,   2,   1,   0,   0,   0,
     0,   0,   0,   0,   1,   0,   0,   3,   4,   7,
    12,  16,  18,  26,  28,  33,  41,  43,   0,   0,
     0,   2,   0,   2,   2,   0,   0,   0,   0,   0,
     0,   1,   0,   0,   0,   1,   3,   3,   0,   0,
     0,   0,   2,   1,   4,   1,   5,  10,  13,  16,
    22,  26,  31,  36,  40,  46,   1,   0,   1,   0,
     0,   0,   0,   1,   0,   0,   1,   1,   0,   1,
     0,   1,   1,   0,   0,   2,   0,   0,   3,  10,
    13,  16,  19,  25,  31,  33,  38,  45,   0,   1,
     1
};
#endif
#elif IS_CHIP_MT6276
extern const unsigned char FM_FH_idx[321];

void FH_get_FM_frequency_hopping_set_by_calc( int ch_freq /*scaled FM_scale1 times*/, sFHset* _fhset )
{  unsigned int idx;

   if( ( ch_freq >= 760 ) && ( ch_freq <= 1080 ) )
   {  idx = ch_freq - 760; /*idx: 0~320*/
      *_fhset = FM_FH_idx[idx];
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

const unsigned char FM_FH_idx[321] =
{  200, 191, 183, 174, 166, 157, 149, 140, 132, 124,
   115, 107,  98,  90,  82,  74,  66,  57,  49,  41,
    33,  25,  17,   9,   2,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0, 279, 272, 265,
   257, 250, 243, 236, 228, 221, 214, 207, 200, 192,
   185, 178, 171, 164, 157, 150, 143, 136, 129, 122,
   115, 108, 101,  94,  88,  81,  74,  67,  60,  53,
    46,  40,  33,  26,  19,  13,   6,   2,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   237, 230, 224, 218, 212, 206, 200, 194, 188, 181,
   175, 169, 163, 157, 151, 145, 139, 133, 127, 121,
   115, 109, 103,  97,  91,  85,  79,  74,  68,  62,
    56
};
#else
void FH_get_FM_frequency_hopping_set_by_calc( int ch_freq , sFHset* _fhset )
{ /*empty function for not build error*/
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

#else  /*!IS_MPLL_FH_SUPPORT*/
void FH_get_FM_frequency_hopping_set_by_calc( int ch_freq , sFHset* _fhset )
{ /*empty function for not build error*/
   //kal_prompt_trace(MOD_FMR, "None FH_get_FM_frequency_hopping_set_by_calc %x, %x,", ch_freq, *_fhset);
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif /*IS_MPLL_FH_SUPPORT*/
/*Part2 end*/
//#pragma arm section code, rodata, zidata
