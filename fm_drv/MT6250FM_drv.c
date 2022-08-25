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
 * MT6250FM_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      FM Radio Driver (MT6250)
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#if (defined(MT6250FM) || defined(MT6260FM) || defined(MT6261FM))
#include "drv_comm.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "fmr_trc.h"
#include "fmr_config_customize.h"
#include "fm_radio.h"
#include "us_timer.h"
#include "intrCtrl.h"
#include "drv_hisr.h"
#include "dcl.h"
#include "MT6250FM.h"
#include "flash_sfi_release.h"
#include "MT6250FM_dsp.h"
#include "l1audio.h"
#include "l1_fh_interface.h" 
#include "fmr_main.h"
/*
#include "kal_release.h"
#include "app_ltlcom.h"
#include "stack_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "stack_common.h"
#include "eint.h"
*/
/* defined in custom folder */
extern kal_uint16 FMR_DESENSE_LEVEL;

//extern kal_uint16 FMR_CQI_TH;
//kal_bool FM_MCUFA_OPEN = KAL_FALSE;
kal_bool FM_Data_debug = KAL_TRUE;
kal_bool FM_Unknown_ROM=KAL_TRUE;
//extern const kal_uint8 FM_EINT_NO;
extern FMR_data *pstFMR_data;
extern kal_bool isRdsOn;
//static kal_bool fm_state = LEVEL_LOW;

DCL_HANDLE FMR_dcl_handle = DCL_HANDLE_INVALID;

/// Global variables for current FM status
kal_int16 _current_frequency = -1;
//kal_int16 _backup_frequency = -1;
//static kal_bool  _is_fm_on = KAL_FALSE;
#if defined(MT6250FM)
static kal_int16 TimeOut_Cnt = 0;
#endif
#if defined(__CLASSK_CP_SUPPORT__)
static void FMDrv_ClassK_Desense_Check(void * param);
#endif
#if defined(__CLASSK_CP_SUPPORT__) || (FM_ESD_RECOVERY == 1)
extern void fm_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg);
extern void fm_stop_timer(kal_uint8 timer_id);
#endif
#if (FM_ESD_RECOVERY == 1)
static void FMDrv_ESD_Check(void * param);
static void FMDrv_ESD_Recovery(void);
static kal_bool ESD_Recovery = KAL_FALSE; 
#endif
//const kal_uint16 *bin_patch;
//const kal_uint16 *bin_coeff;
//kal_uint8 HWSearch_flag = 0;
//static kal_uint8 Valid_flag = 0;
//static kal_uint16 FreqKHz = 0;
//kal_uint16 FreqSt = 987;
//kal_bool DebugSwith = KAL_TRUE;
/*#if defined(INTERNAL_ANTENNAL_SUPPORT)
kal_uint8 is_shortAntenna = 1;
#else
kal_uint8 is_shortAntenna = 0;
#endif*/
extern void Brt_SingleArm_R_RC_Calibration(kal_uint8 *r_cal, kal_uint8 *rc_cal);
extern void FMDrv_RDS_Enable(void);
extern void FMDrv_RDS_Disable(void);
extern void mt6250_fm_force_upll_on(kal_bool force_on);/*for lock upll*/

typedef struct
{
    kal_uint32 PRX;
	kal_uint32 ATEDV;
	kal_uint32 PR;
	kal_int32 RSSI;
	kal_int32 PAMD;
	kal_int32 FPAMD;
	kal_int32 MR;
	kal_int32 ATDC;
}FM_CQIs;

static void Average_Of_CQIs(FM_CQIs *FM_cqi);
static void MT6250FM_Tune_Channel(kal_uint16 freq, kal_bool SoftMute_Flag);
#if defined(MT6250FM)
static void MT6250FM_EnableAudioBist(kal_bool flag);
#endif

#if (FMR_ENHANCED_SCAN==1)
extern FMR_Audio_Level_e FMR_AUDIO_LEVEL;
//const kal_int32 FMR_AUDIO_TH[FMR_Audio_End]=
const kal_uint16 FMR_AUDIO_TH[FMR_Audio_End]=
{
	14635,16421,18425,20674,32766
};

extern kal_int32 FMR_RSSI_THRESHOLD;
//kal_int32 FMR_RSSI_SANTTH =-296;
const kal_int8 FMR_PAMD_TH=-12;
const kal_uint8 FMR_PRX_TH=64;//80;
const kal_int8 FMR_MRTH=-67;
const kal_int8 FMR_PAMD_TONE_TH = -33;
const kal_uint8 FMR_ATDEV_TH=0;//1550;
const kal_int8 FMR_Noise_Offset = 10;
const kal_int16 FMR_ATDC_TH=3496;
kal_int16 FMR_RSSI_LANTTH =-296;
#endif

typedef struct 
{
	/**0xFFFF:polling status=1 
	 0xFFFE:polling status=0
	 0xFFFD:read status
	 0xFFFB:delay ms
	 0xFFFA: delay us
	 0xFFF9: DSP patch download
	 else: write register
	 **/ 
	union
	{
		kal_uint16 addr;
		kal_uint16 cmd;
	}CW_u;
	union
	{
		kal_uint16 AndPara;
		kal_uint16 Addr;
	}Para_u;
	kal_uint16 OrPara;
} FMDrv_ctrl_word_t;


#if 0//defined(MT6250FM_FPGA)
/* under construction !*/
#else
#if defined(MT6250FM)
#define POWER_ON_COMMAND_COUNT 25//19
#elif defined(MT6260FM) 
#define POWER_ON_COMMAND_COUNT 31
#elif defined(MT6261FM)
#define POWER_ON_COMMAND_COUNT 31
#endif
#endif
static const FMDrv_ctrl_word_t MT6250FM_PowerOnSetting[POWER_ON_COMMAND_COUNT] = 
{
#if defined(MT6250FM)
//FM Digital Init: fm_rgf_maincon
    {0x60, 0x0, 0x0001},//A1
    {0xFFFB, 0x0, 0x0003},//A2 Delay 3ms
    {0x60, 0x0, 0x0003},//A3
    {0x60, 0x0, 0x0007},//A4
    //{0x61, 0xFFF, 0x0000},//A5 reserve
#if defined(INTERNAL_ANTENNAL_SUPPORT)//A6   
	{0x61,0xFFEF,0x0010},
#else
	{0x61,0xFFEF,0x0000},
#endif
#ifdef MT6250FM_DEEMPHASIS_75//A7
	{0x61,0xEFFF,0x1000},
#else
	{0x61,0xEFFF,0x0000},
#endif
	{0xFFFD, 0x0062, 0x0000},//A9 read the HW version

	{0x61,0x7FFF,0x8000},//A1.1 dsp rom code version request enable
	{0x61,0xFFFD,0x0002},//A1.2 release ASIP reset
	{0x61,0xFFFE,0x0000},//A1.3 enable ASIP power
	{0xFFFF,0x84,0x0001},//A1.4 Chack if DSP code version ready
	{0xFFFD,0x83,0x0000},//A1.5 Get FM DSP code version
	{0x61,0x7FFF,0x0000},//A1.6 DSP rom code version request disable
	{0x61,0xFFFC,0x0001},//A1.7 Reset ASIP
	//{0xFFF9, 0x0, 0x0000},//B0 check dsp version
#if 0//defined(MT6250FM_FPGA)    
/* under construction !*/
#endif    
    {0xFFF9, 0x0, 0x0002},//C1 download patch
    {0xFFF9, 0x0, 0x0003},//D1 downloand coeff
//    {0xFFF9, 0x0, 0x0004},//D1 download hWACC coeff		
    {0x90, 0x0, 0x0040},//Reset download control
    {0x90, 0x0, 0x0000},//diable memory control from host
//	{0x67, 0xFC00,0x01D6},//E1((FM_RADIO_MIN_FREQ-640)<<1)
//	{0x66, 0xFC00,0x0370},//E2((FM_RADIO_MAX_FREQ-640)<<1)
//	{0x66, 0x87FF,0x2800},//E3 search step 100khz,Set rgf_seek_wrap
    {0x6A, 0x0, 0x0020},//E4 only enable RDS interrupt
    {0x6B, 0x0, 0x0020},//E4 only enable RDS interrupt
    {0x60, 0x0, 0x000F},//E5 Enable HW auto control
    {0x61, 0xFFFD, 0x0002},//E6 Release ASIP reset
    {0x61, 0xFFFE, 0x0000},//E7 Enable ASIP power
    {0xFFFB, 0x0, 0x0064},//E8 Delay 100ms
    {0xFFFF, 0x64, 0x0002}//E9 Check HW intitial complete
#elif defined(MT6260FM) 
//FM Digital Init: fm_rgf_maincon
    {0x98, 0x0, 0x8000},//A0
    {0x60, 0x0, 0x0001},//A1
    {0xFFFB, 0x0, 0x0003},//A2 Delay 3ms
    {0x60, 0x0, 0x0003},//A3
    {0x60, 0x0, 0x0007},//A4
    {0x70, 0x0, 0x0040},//A5
//#if defined(INTERNAL_ANTENNAL_SUPPORT)//A6   
//	{0x61,0xFFEF,0x0010},
//#else
//	{0x61,0xFFEF,0x0000},
//#endif
#ifdef MT6250FM_DEEMPHASIS_75//A7
	{0x61,0xEFFF,0x1000},
#else
	{0x61,0xEFFF,0x0000},
#endif
	{0xFFFD, 0x0062, 0x0000},//A9 read the HW version

	{0x61,0x7FFF,0x8000},//A1.1 dsp rom code version request enable
	{0x61,0xFFFD,0x0002},//A1.2 release ASIP reset
	{0x61,0xFFFE,0x0000},//A1.3 enable ASIP power
	{0xFFFF,0x84,0x0001},//A1.4 Chack if DSP code version ready
	{0xFFFD,0x83,0x0000},//A1.5 Get FM DSP code version
	{0x61,0x7FFF,0x0000},//A1.6 DSP rom code version request disable
	{0x61,0xFFFC,0x0001},//A1.7 Reset ASIP
	//{0xFFF9, 0x0, 0x0000},//B0 check dsp version
#if 0//defined(MT6250FM_FPGA)    
/* under construction !*/
#endif    
    {0xFFF9, 0x0, 0x0002},//C1 download patch
    {0xFFF9, 0x0, 0x0003},//D1 downloand coeff
//    {0xFFF9, 0x0, 0x0004},//D1 download hWACC coeff		
    {0x90, 0x0, 0x0040},//Reset download control
    {0x90, 0x0, 0x0000},//diable memory control from host
    
    {0x21, 0x0, 0xe000},//D2 set APLL divider
    {0xD8, 0x0, 0x03F0},//D2.1 set SDM coeff0_H
    {0xD9, 0x0, 0x3F04},//D2.2 set SDM coeff0_L
    {0xDA, 0x0, 0x0014},//D2.3 set SDM coeff1_H
    {0xDB, 0x0, 0x2A38},//D2.4 set SDM coeff1_L

    
//	{0x67, 0xFC00,0x01D6},//E1((FM_RADIO_MIN_FREQ-640)<<1)
//	{0x66, 0xFC00,0x0370},//E2((FM_RADIO_MAX_FREQ-640)<<1)
//	{0x66, 0x87FF,0x2800},//E3 search step 100khz,Set rgf_seek_wrap
    {0x6A, 0x0, 0x0020},//E4 only enable RDS interrupt
    {0x6B, 0x0, 0x0020},//E4 only enable RDS interrupt
    {0x60, 0x0, 0x000F},//E5 Enable HW auto control
    {0x61, 0xFFFD, 0x0002},//E6 Release ASIP reset
    {0x61, 0xFFFE, 0x0000},//E7 Enable ASIP power
    {0xFFFB, 0x0, 0x0064},//E8 Delay 100ms
    {0xFFFF, 0x64, 0x0002}//E9 Check HW intitial complete
#elif defined(MT6261FM)
//FM Digital Init: fm_rgf_maincon
    {0x60, 0x0, 0x0001},//A1
    {0xFFFB, 0x0, 0x0003},//A2 Delay 3ms
    {0x60, 0x0, 0x0003},//A3
    {0x60, 0x0, 0x0007},//A4
    {0x70, 0x0, 0x0040},//A5
//#if defined(INTERNAL_ANTENNAL_SUPPORT)//A6   
//	{0x61,0xFFEF,0x0010},
//#else
//	{0x61,0xFFEF,0x0000},
//#endif
#ifdef MT6250FM_DEEMPHASIS_75//A7
	{0x61,0xEFFF,0x1000},
#else
	{0x61,0xEFFF,0x0000},
#endif
	{0xFFFD, 0x0062, 0x0000},//A9 read the HW version

	{0x61,0x7FFF,0x8000},//A1.1 dsp rom code version request enable
	{0x61,0xFFFD,0x0002},//A1.2 release ASIP reset
	{0x61,0xFFFE,0x0000},//A1.3 enable ASIP power
	{0xFFFF,0x84,0x0001},//A1.4 Chack if DSP code version ready
	{0xFFFD,0x83,0x0000},//A1.5 Get FM DSP code version
	{0x61,0x7FFF,0x0000},//A1.6 DSP rom code version request disable
	{0x61,0xFFFC,0x0001},//A1.7 Reset ASIP
	//{0xFFF9, 0x0, 0x0000},//B0 check dsp version
#if 0//defined(MT6250FM_FPGA)    
/* under construction !*/
#endif    
    {0xFFF9, 0x0, 0x0002},//C1 download patch
    {0xFFF9, 0x0, 0x0003},//D1 downloand coeff
//    {0xFFF9, 0x0, 0x0004},//D1 download hWACC coeff		
    {0x90, 0x0, 0x0040},//Reset download control
    {0x90, 0x0, 0x0000},//diable memory control from host
    
    {0x21, 0x0, 0xe000},//D2 set APLL divider
    {0xD8, 0x0, 0x03F0},//D2.1 set SDM coeff0_H
    {0xD9, 0x0, 0x3F04},//D2.2 set SDM coeff0_L
    {0xDA, 0x0, 0x0014},//D2.3 set SDM coeff1_H
    {0xDB, 0x0, 0x2A38},//D2.4 set SDM coeff1_L
    {0x0F, 0xF800, 0x0455},//ADPLL fast tracking mode gain
    
//	{0x67, 0xFC00,0x01D6},//E1((FM_RADIO_MIN_FREQ-640)<<1)
//	{0x66, 0xFC00,0x0370},//E2((FM_RADIO_MAX_FREQ-640)<<1)
//	{0x66, 0x87FF,0x2800},//E3 search step 100khz,Set rgf_seek_wrap
    {0x6A, 0x0, 0x0020},//E4 only enable RDS interrupt
    {0x6B, 0x0, 0x0020},//E4 only enable RDS interrupt
    {0x60, 0x0, 0x000F},//E5 Enable HW auto control
    {0x61, 0xFFFD, 0x0002},//E6 Release ASIP reset
    {0x61, 0xFFFE, 0x0000},//E7 Enable ASIP power
    {0xFFFB, 0x0, 0x0064},//E8 Delay 100ms
    {0xFFFF, 0x64, 0x0002}//E9 Check HW intitial complete
#endif
};
/*be less than 1ms*/
void Delayus(kal_uint32 u4MicroSec)
{
	ust_busy_wait(u4MicroSec);
}
static void Delayms(kal_uint32 data)
{
    while(data--)
    {
        Delayus(1000);
    }
}

kal_bool MT6250FM_ReadWord(kal_uint8 addr, kal_uint16 *data)
{
    kal_uint32 active;
	
    DRV_WriteReg(FSPI_MAS_ADDR_REG, (kal_int16)(0x100 | addr));
    DRV_WriteReg(FSPI_MAS_CFG2_REG, 0); //[2:0]Actual data reads = (TRAN LEN + 1)x 16b
    DRV_WriteReg(FSPI_MAS_CTRL_REG, 0x01);
    do
    {
        active= DRV_Reg(FSPI_MAS_CTRL_REG);
    } while (1 == active);
    *data = DRV_Reg(FSPI_MAS_RDDATA_REG);
	if(FM_Data_debug == KAL_TRUE)
	{
		kal_trace(TRACE_GROUP_1,FM_READ_DATA,addr,*data);
	}
	return KAL_TRUE;
}

kal_bool MT6250FM_WriteWord(kal_uint8 addr, kal_uint16 data)
{
	 kal_uint32 active;
	 
	 DRV_WriteReg(FSPI_MAS_ADDR_REG, addr);
	 DRV_WriteReg(FSPI_MAS_WRDATA_REG, data);
	 DRV_WriteReg(FSPI_MAS_CTRL_REG, 0x01);
	 do
	 {
		 active = DRV_Reg(FSPI_MAS_CTRL_REG);
	 } while (1 == active);
	 if(FM_Data_debug == KAL_TRUE)
	 {
		 kal_trace(TRACE_GROUP_1,FM_WRITE_DATA,addr,data);
	 }
	return KAL_TRUE;
}
/*polling FM_MAIN_INTR stc_done bit is 1.
TimeOut: max times for polling(ramp down:1s,tune:3s,search:15s)
return: 
KAL_FALSE:didn't get in time. 
KAL_TRUE:  polling done in time
*/
static kal_bool MT6250FM_Polling(kal_uint32 TimeOut)
{
	kal_uint32 PollTimes=0;
	kal_uint16 dataRead;

	kal_trace(TRACE_GROUP_2,FM_API_ENTRANCE,16);
	FM_Data_debug = KAL_FALSE;
	MT6250FM_ReadWord(FM_MAIN_INTR, &dataRead);
	while((dataRead & FM_INTR_STC_DONE)==0)
	{
		if(PollTimes>TimeOut)/*time out*/
		{
			FM_Data_debug = KAL_TRUE;
			kal_trace(TRACE_GROUP_2,FM_API_EXIT,dataRead);
			return KAL_FALSE;
		}
		PollTimes++;
		kal_sleep_task(1);
		MT6250FM_ReadWord(FM_MAIN_INTR, &dataRead);
	}
	FM_Data_debug = KAL_TRUE;
	kal_trace(TRACE_GROUP_2,FM_API_EXIT,161);
	return KAL_TRUE;
}

/***********************************************************************
*  Turn on tune (internal)
***********************************************************************/
void MT6250FM_TUNE_ON()
{
    kal_uint16 dataRead;
    MT6250FM_ReadWord(FM_MAIN_CTRL, &dataRead);
    MT6250FM_WriteWord(FM_MAIN_CTRL, (dataRead&0xFFFE)|TUNE);
}

/***********************************************************************
*  Seek on (internal)
***********************************************************************/
void MT6250FM_SEEK_ON()
{
    kal_uint16 dataRead;
    MT6250FM_ReadWord(FM_MAIN_CTRL, &dataRead);
    MT6250FM_WriteWord(FM_MAIN_CTRL, (dataRead&0xFFFD)|SEEK);
}

/***********************************************************************
*  Scan on (internal)
***********************************************************************/
void MT6250FM_SCAN_ON()
{
    kal_uint16 dataRead;
    MT6250FM_ReadWord(FM_MAIN_CTRL, &dataRead);
    MT6250FM_WriteWord(FM_MAIN_CTRL, (dataRead&0xFFFB)|SCAN);
}

/***********************************************************************
*  RAMP off (internal)
***********************************************************************/
void MT6250FM_RampDown()
{
	kal_uint16 dataRead;
	//kal_trace(TRACE_GROUP_2,FM_API_ENTRANCE,34);
#if defined(__CLASSK_CP_SUPPORT__)
	fm_stop_timer(FM_CLASSK_CHECK_RSSI_TIMER);
#endif	
	//Clear DSP state
	MT6250FM_ReadWord(FM_MAIN_CTRL, &dataRead);		
	MT6250FM_WriteWord(FM_MAIN_CTRL, (dataRead&0xFFF0)); //Set rgf_tune/seek/scan/init= 0

	//Set DSP ramp down state
	MT6250FM_ReadWord(FM_MAIN_CTRL, &dataRead);		
	MT6250FM_WriteWord(FM_MAIN_CTRL, (dataRead|RAMP_DOWN));

	if(MT6250FM_Polling(200)==KAL_FALSE)
	{
		ASSERT(0);/*timeout*/
	}
	//Check STC_DONE status flag (not the interrupt flag!)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	//Set i2s disable
	//MT6250FM_ReadWord(FM_I2S_CON0, &dataRead);
	//MT6250FM_WriteWord(FM_I2S_CON0, 0x0000);
	//Clear DSP ramp down state
	MT6250FM_ReadWord(FM_MAIN_CTRL, &dataRead);		
	MT6250FM_WriteWord(FM_MAIN_CTRL, (dataRead&(~RAMP_DOWN)));

	MT6250FM_ReadWord(FM_MAIN_INTR, &dataRead);		
	MT6250FM_WriteWord(FM_MAIN_INTR, dataRead|FM_INTR_STC_DONE);//clear status flag
	//    MT6250FM_ReadWord(FM_MAIN_INTR, &dataRead);	/*for debug*/	

	kal_trace(TRACE_GROUP_2,FM_API_EXIT,34);
}

static void MT6250FM_writeFA(kal_uint16 *buff, kal_uint8 fa)
{
    kal_uint32 i=0;

	for(i=0; i<4;i++)
    {
        if((fa>>i)& 0x1)
            *buff |= (1<<(12+i));
        else
            *buff &= ~(1<<(12+i));
    }
}


/***********************************************************************
*  Get RSSI Value (internal)
*
*  parameter-->
*  return dBuVemf
***********************************************************************/
kal_uint16 MT6250FM_RSSI_Reg2dB(kal_uint16 reg)
{
    kal_int16 RSSI,dBValue;
    RSSI = (kal_int16)(reg&0x3FF);
    /*RS=RSSI
    *If RS>511, then RSSI(dBm)= (RS-1024)/16*6
    *                 else RSSI(dBm)= RS/16*6             */
    dBValue = (RSSI>511) ? (((RSSI-1024)*6/16)+113):(RSSI*6/16+113);
    if(dBValue < 0)
    {
        dBValue = 0;
    }
	return (kal_uint16)dBValue;
}
kal_uint16 MT6250FM_GetCurRSSI(void)
{
    kal_uint16 TmpReg;
    MT6250FM_ReadWord(FM_RSSI, &TmpReg);
	return MT6250FM_RSSI_Reg2dB(TmpReg);
}

/***********************************************************************
*  Get PAMD Value (internal)
***********************************************************************/
kal_uint16 MT6250FM_GetCurPamd(void)
{
    kal_uint16 TmpReg, PAMD, dBValue;
    MT6250FM_ReadWord(FM_PAMD_REG, &TmpReg);
    /*PA=PAMD
    *If PA>=256 then PAMD(dB)=  (PA-512)/16*6,
    *               else PAMD(dB)=PA/16*6                 */
    PAMD = TmpReg&0x1FF;
    dBValue = (PAMD>=256) ? ((512-PAMD)*6/16):0;
    
    return dBValue;
}

/**********************************************************************
*  Get really signal level in current frequency
*
*  parameter-->curf:frequency value of radio now
**********************************************************************/
kal_uint16 FMDrv_GetSigLvl(kal_int16 curf)
{
	kal_uint16 rssi;
	if(curf != _current_frequency)
	{
		FMDrv_SetFreq(curf);
	}
	rssi = MT6250FM_GetCurRSSI();
	return rssi;
}

/**********************************************************************
*  Get PAMD in current frequency
*
*  parameter-->curf:frequency value of radio now
**********************************************************************/
kal_uint16 FMDrv_GetPamdLvl(kal_int16 curf)
{
	kal_uint16 pamd,  total=0, Average_Time=0;
	kal_uint32 readtimes;

	if (curf != _current_frequency)
	{
		FMDrv_SetFreq(curf);
	}
	for(readtimes=0;readtimes<8;readtimes++)
	{
		pamd = MT6250FM_GetCurPamd();
		total += pamd;
        if (pamd != 0)
        {
            Average_Time++;
        }
		kal_sleep_task(10);	
	}
   	if(Average_Time != 0)
   	{
	    return total/Average_Time;
   	}
    else
    {
        return 0;
    }
}
/*
range:20~50dB
return dB
*/
kal_int16 FMDrv_GetMR(void)
{
	kal_uint16 RegTemp;
	kal_int16 MR;
    MT6250FM_ReadWord(FM_MR_REG, &RegTemp);
	RegTemp=(RegTemp&0x1FF);
	
	if(RegTemp > 255)
	{
		MR=(kal_int16)(RegTemp-512)*6/16;
	}
	else
	{
		MR=(kal_int16)RegTemp*6/16;
	}
	return MR;
}

/***********************************************************************
*  FMDrv_Get_stereo_mono
*
*  parameter-->
* RETURNS
*  0:mono 1:stereo
***********************************************************************/
kal_uint8 FMDrv_Get_stereo_mono(void)
{
    kal_uint16 TmpReg;
    MT6250FM_ReadWord(FM_RSSI, &TmpReg);
    TmpReg = (TmpReg&FM_STEREO)>>12;
    return TmpReg;
}
void FMDrv_WriteDSP(kal_uint16 addr,kal_uint16 data)
{
	MT6250FM_WriteWord(0xE2, addr);
	MT6250FM_WriteWord(0xE3, data);
	MT6250FM_WriteWord(0xE1, 0x2);
	Delayus(400);
}
void FMDrv_ReadDSP(kal_uint16 addr,kal_uint16 *data)
{
	MT6250FM_WriteWord(0xE2, addr);
	MT6250FM_WriteWord(0xE1, 0x1);		   
	Delayus(400);
	MT6250FM_ReadWord(0xE4, data);
}

kal_uint32 FMDrv_GetCapArray(void)
{
	
    kal_uint32 i=0;
    kal_uint16 regData=0, capValue=0;
    kal_uint32 cookedCapValue=0;

	kal_uint16 chara[] = { 165, 330, 660, 1320,
                           2640, 5280, 10560, 21120 };
	
    MT6250FM_ReadWord(0x60, &regData);
    MT6250FM_WriteWord(0x60, regData&0xFFF7);
	
    MT6250FM_ReadWord(0x25, &regData);
    
	capValue = regData >> 8;


	for(i=0;i<8;i++)
    {
        if((capValue >> i)&0x0001)
        {
            cookedCapValue += chara[i];
        }
    }
	
    MT6250FM_ReadWord(0x60, &regData);
    MT6250FM_WriteWord(0x60, regData|0x8);

	return cookedCapValue;
	
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*********************************************************************
*  DSP download procedure
*  parameter-->patch_download, coefficient_download
*
*********************************************************************/
static void MT6250FM_ParameterDownloadToDsp(const kal_uint16 *dsp_array, Download_type type)
{
    kal_uint32 CONTROL_CODE=0;
    kal_uint32 data_length = 0;  // in words
    kal_uint32 i;
	kal_uint16 DMa0x3000=0;

	FM_Data_debug = KAL_FALSE;
    switch(type) 
    {
        /*case rom_download:  //rom code
            CONTROL_CODE = 0x10;
            break;*/
        case patch_download:  //patch
        {
            CONTROL_CODE = 0x10;
			DMa0x3000=dsp_array[2];
            break;
        }
        case coefficient_download:  //coeff
        {
            CONTROL_CODE = 0x0e;
			if(FM_Unknown_ROM==KAL_FALSE)
			{
				DMa0x3000=dsp_array[2];
			}
			kal_trace(TRACE_INFO,FM_INFO_PATCH_VERSION,dsp_array[19]);
            break;
        }
//        case hw_coefficient_download:	//HW coeff
//            CONTROL_CODE = 0x0d;
//            break;
        default:
        	break;
    }
    data_length = dsp_array[1] - dsp_array[0] + 3; 

    if(data_length > 0) 
    {
        MT6250FM_WriteWord(0x90, 0);
        MT6250FM_WriteWord(0x91, dsp_array[0]);		//Start address
        MT6250FM_WriteWord(0x90, 0x0040); 			//Reset download control
        MT6250FM_WriteWord(0x90, CONTROL_CODE); 	//Set download control

		MT6250FM_WriteWord(0x92, DMa0x3000);
		for(i=3; i<data_length; i++) 
		{
		    MT6250FM_WriteWord(0x92, dsp_array[i]);
        }
    }
    else
    {
        ASSERT(0);
    }
	FM_Data_debug = KAL_TRUE;
}
/***********************************************************************
*  FM Chip initial
***********************************************************************/
void FMDrv_ChipInit(void)
{
}

void FMDrv_LISR(void)
{
	IRQMask(IRQ_FM_CODE);
	drv_active_hisr(DRV_FMIF_HISR_ID);
}

void FMDrv_HISR(void)
{
	ilm_struct *fmr_ilm;
	DRV_SendPrimitive(fmr_ilm,
                        MOD_EINT_HISR,
                        MOD_FMR,
                        MSG_ID_FMR_RDS_IND,
                        NULL,
                        FMR_SAP);
	msg_send_ext_queue(fmr_ilm);
}

/***********************************************************************
*  FM Interrupt initialize
***********************************************************************/
void FMDrv_IntrInit(void)
{
#if (defined(FM_EINT_SUPPORT_SEARCH)) || (defined(__FM_RADIO_RDS_SUPPORT__))
	kal_trace(TRACE_GROUP_2,FMDRV_API_ENTRANCE,0xA11);
	DRV_Register_HISR(DRV_FMIF_HISR_ID, FMDrv_HISR);
	IRQ_Register_LISR(IRQ_FM_CODE, FMDrv_LISR, "FM handler");
	IRQSensitivity(IRQ_FM_CODE,LEVEL_SENSITIVE);
	IRQUnmask(IRQ_FM_CODE);
#endif
}
void FMDrv_GetIntr(kal_uint16 *dataRead)
{
    MT6250FM_ReadWord(FM_MAIN_INTR, dataRead);
}

void FMDrv_ClrIntr(void)
{
#if (defined(FM_EINT_SUPPORT_SEARCH)) || (defined(__FM_RADIO_RDS_SUPPORT__))
    kal_uint16 dataRead;
    
	MT6250FM_ReadWord(FM_MAIN_INTR, &dataRead);
	MT6250FM_WriteWord(FM_MAIN_INTR, dataRead);//clear status flag
	IRQUnmask(IRQ_FM_CODE);
#endif
}

/***********************************************************************
*  Engineer mode function (API)
*
*  parameter-->group_idx: mono\stereo\RSSI_threshold\IF_count_delta
*              item_idx: sub select index
*              item_value: set parameter value
***********************************************************************/
void FMDrv_radio_item_info(kal_uint16 group_idx, kal_uint16 item_idx, kal_uint32 item_value)
{
	if(group_idx==0x02)
	{
		FMDrv_JammerScan();
	}
	return;
}

kal_uint16 FMDrv_ReadByte(kal_uint8 addr)
{
    kal_uint16 Data;
    MT6250FM_ReadWord(addr, &Data);
    return Data;
}

kal_bool FMDrv_WriteByte(kal_uint8 addr, kal_uint16 data)
{
    MT6250FM_WriteWord(addr, data);
    return KAL_TRUE;
}

void FMDrv_Mute(kal_uint8 mute)
{
    kal_uint16 dataRead;
    
    MT6250FM_ReadWord(FM_MAIN_CTRL,&dataRead);                           
    if (mute == 1)
    {
        MT6250FM_WriteWord(FM_MAIN_CTRL, dataRead|MUTE);  
    }
    else
    {
        MT6250FM_WriteWord(FM_MAIN_CTRL, dataRead&(~MUTE)); 
    }
}
void dcl_pmu_vcama_enable(kal_bool enable)
{
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VCAMA;
	if (FMR_dcl_handle == DCL_HANDLE_INVALID) 
	{
		FMR_dcl_handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	}
	DclPMU_Control(FMR_dcl_handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	if(!enable)
	{
		DclPMU_Close(FMR_dcl_handle);
		FMR_dcl_handle = DCL_HANDLE_INVALID;
	}	
}
void dcl_pmu_set_vcama(PMU_VOLTAGE_ENUM vol)
{
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
	val.voltage=vol;
	val.mod=VCAMA;
	if (FMR_dcl_handle == DCL_HANDLE_INVALID)
	{
		FMR_dcl_handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
	}
	DclPMU_Control(FMR_dcl_handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if (defined(MT6250FM))
void FMDrv_SetRCCal(void)
{
#ifdef __BTMODULE_MT6250__
	kal_uint8 R_Cal=0,RC_Cal=0;
	kal_uint32 reg32;
	
	Brt_SingleArm_R_RC_Calibration(&R_Cal,&RC_Cal);
	FM_FSPI_26M_CLK_ENABLE();/*fm FSPI and 26M clock enable*/
	reg32=*((volatile unsigned int*)0xA0770050);
	reg32=reg32&(~0x07FF)|R_Cal|0x0010|(RC_Cal<<5)|0x0400;
	*((volatile unsigned int*)0xA0770050)=reg32;
	FM_FSPI_26M_CLK_DISABLE();/*fm FSPI and 26M clock disable*/
#endif	
}
#endif	
/*************************************************************
* FM Radio power on Reset
*************************************************************/
void FMDrv_PowerOnReset(void)
{	
    kal_int32 i,j;
    kal_uint16 tmp_reg;
	kal_uint8 DSP_Code_Version,Rom_Reset_Version;

    kal_trace(TRACE_INFO,FM_INFO_FM_POWER_ON_RST);
    dcl_pmu_set_vcama(PMU_VOLT_02_800000_V);
 	dcl_pmu_vcama_enable(KAL_TRUE);
	//FMDrv_Debug0();
#if defined(MT6250FM)
	FM_FSPI_26M_CLK_ENABLE();/*fm FSPI and 26M clock enable*/
	FM_ADPLL_CLK_ENABLE();/*128K ADPLL clk enable*/
	mt6250_fm_force_upll_on(KAL_TRUE);	
#elif (defined(MT6260FM) || defined(MT6261FM))
	/*fm FSPI bclk and 26M clock enable*/
	*((volatile unsigned int*)0xA0010328) |= (0x1<<14);
    Delayms(1);
#endif
	
    for (i=0; i<POWER_ON_COMMAND_COUNT; i++) 
    { 
		kal_trace(TRACE_GROUP_1,FM_ON_SEQUENCE_CMD,i);
		switch(MT6250FM_PowerOnSetting[i].CW_u.cmd)
		{
			case(0xFFFF)://polling status=1  
			{ 
				j=0;
				FM_Data_debug = KAL_FALSE;
	            while(1)
	            {		
	                MT6250FM_ReadWord(MT6250FM_PowerOnSetting[i].Para_u.Addr, &tmp_reg);
	                if(tmp_reg&MT6250FM_PowerOnSetting[i].OrPara)
	                {
						break;
	                }
					if(j++ > 1000)
					{
						kal_trace(TRACE_INFO,FM_ON_POLLING_TIMES,110);
						kal_trace(TRACE_INFO,FM_INFO_READ_DATA, MT6250FM_PowerOnSetting[i].Para_u.Addr,tmp_reg);
						j=0;
					}
	            }
				FM_Data_debug = KAL_TRUE;
				break;
	        }
#if 0/*not used*/			
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif			
			case(0xFFFD)://read status
			{  
	            MT6250FM_ReadWord(MT6250FM_PowerOnSetting[i].Para_u.Addr,&tmp_reg);
				switch(MT6250FM_PowerOnSetting[i].Para_u.Addr)
				{
					case 0x62:
					{
						kal_trace(TRACE_INFO, FM_INFO_FM_CHIP_ID, tmp_reg);
#if defined(MT6250FM)
						if(tmp_reg != 0x6250)
#elif defined(MT6260FM)
						if(tmp_reg != 0x6260)
#elif defined(MT6261FM)
						if(tmp_reg != 0x6261)
#endif
						{
							ASSERT(0);
						}
						/*IDS select*/
						/*MT6250FM_ReadWord(0x7C,&tmp_reg);
						MT6250FM_WriteWord(0x7C,tmp_reg&0xFF0F|0x0020);*/
						break;
					}

					case 0x83:
					{
						DSP_Code_Version = tmp_reg&0x00FF;
						Rom_Reset_Version = (tmp_reg&0xFF00)>>8;
						kal_trace(TRACE_INFO,FM_INFO_ROM_VERSION,Rom_Reset_Version,DSP_Code_Version);
						if(Rom_Reset_Version == 0)/*E1:Rom 0*/
						{
							FM_Unknown_ROM = KAL_FALSE;
						}
						else
						{
							FM_Unknown_ROM = KAL_TRUE;
						}
						//bin_patch=bin_patch_New;
						//bin_coeff=bin_coeff_New;
						break;
					}
					default:
						break;
				}
	        }
			case(0xFFFB)://delay ms
			{ 
	            Delayms(MT6250FM_PowerOnSetting[i].OrPara);
				break;
	        }	
#if 0/*not used*/			
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif			
			case(0xFFF9)://select the function that already coded
			{ 
	            switch(MT6250FM_PowerOnSetting[i].OrPara)
	            {
					/*case 0x0000:
					{
						MT6250FM_CheckDSPVersion();
						break;
					}*/
#if 0//defined(MT6250FM_FPGA)            
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif                    
	                case 0x02:  //DSP path download
	                    MT6250FM_ParameterDownloadToDsp(bin_patch_New, patch_download);
	                    break;
	                case 0x03:  //DSP coefficient download
	                    MT6250FM_ParameterDownloadToDsp(bin_coeff_New, coefficient_download);
	                    break;
#if 0//6250FM doesn't need
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	                default:
	                    ASSERT(0);
	                    break;
	            }
				break;
	        }	
			default:
			{
	            if(MT6250FM_PowerOnSetting[i].Para_u.AndPara > 0)
	            {
	                MT6250FM_ReadWord(MT6250FM_PowerOnSetting[i].CW_u.addr, &tmp_reg);
	                tmp_reg &= MT6250FM_PowerOnSetting[i].Para_u.AndPara;
	                tmp_reg |= MT6250FM_PowerOnSetting[i].OrPara;
	            }
	            else
	            {
	                tmp_reg = MT6250FM_PowerOnSetting[i].OrPara;
	            }
	            MT6250FM_WriteWord(MT6250FM_PowerOnSetting[i].CW_u.addr, tmp_reg);
				break;
	        }	
 		}
    }
	
	MT6250FM_WriteWord(FM_I2S_CON0, 0x0003);	//enable I2S master
	//RF fine tuning for yield loss on FM RF
	MT6250FM_WriteWord(0x60, 0x0007);	
	MT6250FM_WriteWord(0x03, 0xf6ed);	
#if defined(MT6261FM)
	MT6250FM_WriteWord(0x15, 0x0d80);	
	MT6250FM_WriteWord(0x16, 0x0046);	
	MT6250FM_WriteWord(0x17, 0x092a);	
#endif	
	MT6250FM_WriteWord(0x60, 0x000f);	
    FMDrv_IntrInit();   
#if defined(MT6250FM)
	/*open ABBSYS*/
	FM_AFE_ABBSYS_ENABLE();
	FM_D_DIE_ABBSYS_ENABLE();
	FM_A_DIE_ABBSYS_ENABLE();
	//for short antenna R/Rc cal debug
	MT6250FM_ReadWord(0x60,&tmp_reg);
	MT6250FM_WriteWord(0x60, tmp_reg&(~0x0008));
	MT6250FM_ReadWord(0x2A,&tmp_reg);
	MT6250FM_ReadWord(0x60,&tmp_reg);
	MT6250FM_WriteWord(0x60, tmp_reg|0x0008);
#endif
#if (FM_ESD_RECOVERY == 1)
	if(!ESD_Recovery)
		fm_start_timer(FM_ESD_TIMER, FM_ESD_TIMER_INTERVAL, FMDrv_ESD_Check, NULL);
#endif
    _current_frequency = -1;
	kal_trace(TRACE_GROUP_2,FM_API_EXIT,11);
}


/*****************************************************************
*  FM Radio power off
*****************************************************************/
void FMDrv_PowerOffProc(void)
{
    kal_int32 i;
   
 	kal_trace(TRACE_GROUP_2,FM_API_ENTRANCE,21);
#if (FM_ESD_RECOVERY == 1)
		if(!ESD_Recovery)
			fm_stop_timer(FM_ESD_TIMER);
#endif
#if (defined(FM_EINT_SUPPORT_SEARCH)) || (defined(__FM_RADIO_RDS_SUPPORT__))
    IRQMask(IRQ_FM_CODE);
#endif
#if defined(__CLASSK_CP_SUPPORT__)
	Media_SetChargePump(KAL_TRUE, MEDIA_VCP_FM);
#endif	
     //MT6250FM_RampDown();
	Delayms(200);
	 MT6250FM_WriteWord(FM_I2S_CON0, 0x0000);
#if defined(MT6261FM)
	MT6250FM_WriteWord(FM_EN_CTRL,0x107);//Disable HW clock control
#else
     MT6250FM_WriteWord(FM_EN_CTRL,0x330F);//Disable HW clock control
#endif
     MT6250FM_WriteWord(FM_CG_CTRL_HOST,0x0001);//Reset ASIP
	 
    for(i=3; i>=0; i--)
    {
        MT6250FM_WriteWord(FM_RESET_FMSYS, 0x0000); //digital core + digital rgf reset
    }
    MT6250FM_WriteWord(FM_EN_CTRL, 0x0000); //Disable all clock
    MT6250FM_WriteWord(FM_EN_CTRL, 0x4000); //Reset rgfrf
    MT6250FM_WriteWord(FM_EN_CTRL, 0x0000); 
#if defined(MT6250FM)	
	mt6250_fm_force_upll_on(KAL_FALSE);	
    FM_FSPI_26M_CLK_DISABLE();/*fm FSPI and 26M clock disable*/
	FM_ADPLL_CLK_DISABLE();/*128K ADPLL clk disable*/
#elif (defined(MT6260FM) || defined(MT6261FM))
	/*fm FSPI bclk and 26M clock disable*/
	*((volatile unsigned int*)0xA0010318) |= (0x1<<14);
#endif
	dcl_pmu_vcama_enable(KAL_FALSE);
#if defined(MT6250FM)
	/*close ABBSYS*/
	FM_D_DIE_ABBSYS_DISABLE();
	FM_A_DIE_ABBSYS_DISABLE();
	FM_AFE_ABBSYS_DISABLE();
#endif
    _current_frequency = -1;
	kal_trace(TRACE_GROUP_2,FM_API_EXIT,21);
}

/*********************************************************************
*  Radio set frquency
*
*  parameter-->curf:setting frequency value
                    input value unit: Khz
*********************************************************************/
#if (defined(MT6260FM) || defined(MT6261FM))
void FMDrv_SetFreq( kal_int16 curf )

{
	kal_trace(TRACE_INFO,FMDRV_API_ENTRANCE,0xA30);

	_current_frequency = curf;
	MT6250FM_Tune_Channel(curf, KAL_FALSE);
#if defined(__CLASSK_CP_SUPPORT__)
	fm_start_timer(FM_CLASSK_CHECK_RSSI_TIMER, FM_CLASSK_CHECK_RSSI_INTERVAL, FMDrv_ClassK_Desense_Check, NULL);
#endif	
	kal_trace(TRACE_INFO,FMDRV_API_EXIT,0xA30);

	/*dbg bist,need modify*/
/*	MT6250FM_ReadWord(0x60,&dataRead);
	MT6250FM_WriteWord(0x60,dataRead&0xFFF7);
	MT6250FM_ReadWord(0x7C,&dataRead);
	MT6250FM_WriteWord(0x7C,dataRead|0x0002);*/
}
#elif defined(MT6250FM)
void FMDrv_SetFreq( kal_int16 curf )   
{
	kal_uint32 CHAN = 0;
	kal_uint16 dataRead;
	kal_uint16 volume_bak;
	kal_uint16 g_I2SIN_CheckDataValid = 0;

	//kal_trace(TRACE_INFO,FMDRV_API_ENTRANCE,0xA30);
	MT6250FM_RampDown();
    kal_sleep_task(8); 
	
	_current_frequency = curf;
#if (FMR_50K_STEP==1)
	CHAN = (curf - 6400)/5;
	MT6250FM_ReadWord(FM_CHANNEL_SET, &dataRead);
	if(curf%10==0)
		MT6250FM_writeFA(&dataRead, (channel_parameter[curf/10 - 760]));
	else
		MT6250FM_writeFA(&dataRead, 0);
#else
	CHAN = (curf - 640)<<1;
	MT6250FM_ReadWord(FM_CHANNEL_SET, &dataRead);
	MT6250FM_writeFA(&dataRead, (channel_parameter[curf - 760]));
#endif
	MT6250FM_WriteWord(FM_CHANNEL_SET, (dataRead&0xFC00)|CHAN);
	//MT6250FM_WriteWord(FM_CHANNEL_SET, (dataRead&0x4C00)|CHAN); //for debug:disable ATJ/FA/HILO

	MT6250FM_ReadWord(0x7d,&volume_bak);
	MT6250FM_WriteWord(0x7d, 0x0);	//set volume to 0

	I2SIN_MuteSpeaker(KAL_TRUE);	//mute speaker	
	I2SIN_MuteDSP(KAL_TRUE);
	BT_MuteSpeaker(KAL_TRUE); //mute SCO or SBC if available

	MT6250FM_TUNE_ON(); 
	if(MT6250FM_Polling(600)==KAL_FALSE)
	{
		ASSERT(0);/*timeout*/
	}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	//Set i2s_en and master mode
	//MT6250FM_ReadWord(FM_I2S_CON0, &dataRead);
	//MT6250FM_WriteWord(FM_I2S_CON0, 0x0003);

	MT6250FM_ReadWord(FM_MAIN_INTR, &dataRead);
	MT6250FM_WriteWord(FM_MAIN_INTR, dataRead|FM_INTR_STC_DONE);//clear status flag
	//MT6250FM_ReadWord(FM_MAIN_INTR, &dataRead);/*for debug*/
	
	MT6250FM_EnableAudioBist(KAL_TRUE);
	g_I2SIN_CheckDataValid = I2SIN_CheckDataValid(); //wait about 32~64 ms
	
	if(g_I2SIN_CheckDataValid == 0)	//error happened
	{
		TimeOut_Cnt ++;
		if(TimeOut_Cnt >= 3)	//error happened for more than 3 times then no longer check
		{				
			kal_trace(TRACE_INFO,FM_I2SIN_CheckDataValid_TIMEOUT);
			TimeOut_Cnt = 0;
			
			g_I2SIN_CheckDataValid = 0;
			MT6250FM_EnableAudioBist(KAL_FALSE);
			MT6250FM_WriteWord(0x7d, volume_bak);	//set volume to default value

			kal_trace(TRACE_INFO,FMDRV_API_EXIT,0xA31);
			return;
		}		

		kal_trace(TRACE_INFO,FM_I2SIN_CheckDataValid_ERROR);

#ifdef __FM_RADIO_RDS_SUPPORT__
		if(isRdsOn)
		{
			FMDrv_RDS_Disable();
		}		
#endif    	
		dataRead = FMDrv_GetAntennaType();
		FMDrv_PowerOffProc();

		FMDrv_PowerOnReset();
		FMDrv_SetAntennaType((kal_uint8)dataRead);
#ifdef __FM_RADIO_RDS_SUPPORT__
		if(isRdsOn)
		{
			FMDrv_RDS_Enable();
		}		
#endif
		
		g_I2SIN_CheckDataValid = 0;
		FMDrv_SetFreq(curf);
	}
	else	//normal
	{		
		g_I2SIN_CheckDataValid = 0;
		MT6250FM_EnableAudioBist(KAL_FALSE);
		MT6250FM_WriteWord(0x7d, volume_bak);	//set volume to default value

		kal_trace(TRACE_INFO,FMDRV_API_EXIT,0xA30);
	}
    TimeOut_Cnt = 0;
#if defined(__CLASSK_CP_SUPPORT__)
	fm_start_timer(FM_CLASSK_CHECK_RSSI_TIMER, FM_CLASSK_CHECK_RSSI_INTERVAL, FMDrv_ClassK_Desense_Check, NULL);
#endif	
	/*dbg bist,need modify*/
/*	MT6250FM_ReadWord(0x60,&dataRead);
	MT6250FM_WriteWord(0x60,dataRead&0xFFF7);
	MT6250FM_ReadWord(0x7C,&dataRead);
	MT6250FM_WriteWord(0x7C,dataRead|0x0002);*/
}
void MT6250FM_EnableAudioBist(kal_bool flag)
{
	kal_uint16 dataRead;

	MT6250FM_ReadWord(0x9d, &dataRead);	
	if(flag)
	{
		dataRead = (dataRead & 0xFFF0)|(0x1<<15)|(0x1);
		MT6250FM_WriteWord(0x9d, dataRead); //enable audio bist 
	}
	else
		MT6250FM_WriteWord(0x9d, dataRead&(~(0x1<<15)));	//disable audio bist	

	MT6250FM_ReadWord(0x9d, &dataRead); //makesure data is written to HW
	kal_sleep_task(10);  //to flush previous Baseband DSP I2S buffer (it is filled with bist sine)
	
	if(!flag)
	{
		I2SIN_MuteSpeaker(KAL_FALSE);	//unmute speaker
		I2SIN_MuteDSP(KAL_FALSE);
		BT_MuteSpeaker(KAL_FALSE); //mute SCO or SBC if available
	}
}
#endif
/*********************************************************************
*  Set Antenna type
*  parameter-->Type: 1:Short Antenna, 0:Long Antenna
*********************************************************************/
kal_bool FMDrv_SetAntennaType(kal_uint8 ATAType)
{
    kal_uint16 dataRead;
    MT6250FM_ReadWord(FM_CG_CTRL_HOST, &dataRead);
    if(ATAType)
    {
		MT6250FM_WriteWord(FM_CG_CTRL_HOST,dataRead|SHORT_ANTENNA);
    }
    else
    {
		MT6250FM_WriteWord(FM_CG_CTRL_HOST,dataRead&(~SHORT_ANTENNA));
    }
    
    return KAL_TRUE;
}

/*********************************************************************
*  Get Antenna type
*  parameter
*  return-->1:Short Antenna, 0:Long Antenna
*********************************************************************/
kal_uint8 FMDrv_GetAntennaType(void)
{
    kal_uint16 dataRead;
    
    MT6250FM_ReadWord(FM_CG_CTRL_HOST, &dataRead);
    if(dataRead&SHORT_ANTENNA)
    {
        return 1; //short antenna
    }
    else
    {
        return 0; //long antenna
    }
}
/*
preset of search:
set lower/upper bound,search step size
parameter:search_step:0,50Khz, 1.100Khz, 2.200Khz
*/
static void FMDrv_SearchSet(kal_uint8 search_step)
{
    kal_uint16 dataRead;
	//set lower bound
    MT6250FM_ReadWord(FM_MAIN_CFG2, &dataRead);  
    MT6250FM_WriteWord(FM_MAIN_CFG2, (dataRead&0xFC00)|((FM_RADIO_MIN_FREQ-640)<<1));
	//set upper bound and search step size
    MT6250FM_ReadWord(FM_MAIN_CFG1, &dataRead);  
    MT6250FM_WriteWord(FM_MAIN_CFG1, (dataRead&0x8C00)|(1<<(12+search_step))|((FM_RADIO_MAX_FREQ-640)<<1));
    //MT6250FM_ReadWord(FM_MAIN_CFG1, &dataRead);//debug
}
/**********************************************************************
*  Radio valid station,used in HW auto search frequency to verify 
*  valid positon
*
*  parameter-->freq: start frequency
               seek_dir:1-->seek up, 0-->seek down
               space:search step,0:200KHz, 1:100KHz
               is_scan:0.seek, 1.scan
**********************************************************************/
void FMDrv_HWSearch(kal_int16 freq, kal_bool seek_dir, kal_int16 space, kal_bool is_scan)
{
#if (FMR_ENHANCED_SCAN==1)
	kal_uint16 dataRead;
	if(is_scan)
	{
		return;
	}
	else
	{
		MT6250FM_ReadWord(FM_CHANNEL_SET, &dataRead);
		
#if (FMR_50K_STEP==1)
		MT6250FM_WriteWord(FM_CHANNEL_SET, (dataRead&0xFC00)|((freq - 6400)/5));
#else
		MT6250FM_WriteWord(FM_CHANNEL_SET, (dataRead&0xFC00)|((freq - 640)<<1));
#endif
		return;
	}
#else
    kal_uint8 UpDown_flag=1;
    kal_uint8 search_step;
    kal_uint16 dataRead;
    
    if(space)
    {// 100K
        search_step = 1;
    }
    else
    { //200K
        search_step = 2;
    }
    	
    //set start freq for seek
    if(!is_scan)
    {
	    MT6250FM_ReadWord(FM_CHANNEL_SET, &dataRead);
	    MT6250FM_WriteWord(FM_CHANNEL_SET, (dataRead&0xFC00)|((freq - 640)<<1));
    }
    MT6250FM_RampDown();
    FMDrv_SearchSet(search_step);

    if(!is_scan)// seek defaut enable wrap and seek dirction
    {	
		UpDown_flag = 1-seek_dir;
	    MT6250FM_ReadWord(FM_MAIN_CFG1, &dataRead);
        MT6250FM_WriteWord(FM_MAIN_CFG1, dataRead&0xF3FF|0x0800|(UpDown_flag<<10)); 
        MT6250FM_SEEK_ON();   
    }
	else
	{	
		MT6250FM_SCAN_ON();
	}
//	MT6250FM_ReadWord(FM_MAIN_INTR, &dataRead);/*for debug*/
#endif
}

kal_uint8 FMDrv_HWSpolling(kal_uint16 *curf, kal_uint8 *is_valid)
{
#if (FMR_ENHANCED_SCAN==1)
	return 1;
#else
	kal_uint16 dataRead;

	while(1)
	{
		if(pstFMR_data->bHWsearchStop == 1)
		{
			*curf = 0;
			*is_valid = 0;
			MT6250FM_RampDown();
			FMDrv_ClrIntr();
			return 0;
		}
		if(MT6250FM_Polling(6)==KAL_TRUE)
		{
			break;
		}
	}
	MT6250FM_ReadWord(FM_MAIN_INTR, &dataRead);	
	MT6250FM_WriteWord(FM_MAIN_INTR, (dataRead|FM_INTR_STC_DONE));//clear status flag
	MT6250FM_ReadWord(FM_MAIN_INTR, &dataRead);	//for dbg
	MT6250FM_ReadWord(FM_STAT1, &dataRead); 
	MT6250FM_WriteWord(FM_CHANNEL_SET,(dataRead&CUR_RF_CHAN)>>4);/*after seek done, write for DSP*/
	*curf = 640 + ((dataRead&CUR_RF_CHAN)>>(SHIFT_READCHAN+1));			

	if(*curf > 1080)
	{
		*curf = 1080;
	}
	else if(*curf < 875)
	{
		*curf = 875;
	}
	*is_valid = 1;
	return 1;
#endif	
}
/*set scan info bit to get channel info*/
void FMDrv_SetScanInfo(void)
{
	kal_uint16 dataRead;
	MT6250FM_WriteWord(FM_MAIN_CTRL, SCAN_INFO);
	
	while(1)
	{
		if(MT6250FM_Polling(6)==KAL_TRUE)
		{
			MT6250FM_ReadWord(FM_MAIN_INTR, &dataRead);
			if(dataRead&FM_INTR_RDS)
			{
				MT6250FM_WriteWord(FM_MAIN_INTR, FM_INTR_STC_DONE|FM_INTR_RDS);
				break;
			}
		}
	}
}
/*
Para1:freq
Para2:RSSI
Para3:reserved
*/
void FMDrv_ReadChannelCQI(kal_uint16 *Para1,kal_uint16 *Para2,kal_uint16 *Para3)
{
	kal_uint16 DataRead;
	MT6250FM_ReadWord(FM_RDS_RDATA, &DataRead);
	*Para1 = ((DataRead&0x03FF)>>1)+640;
	MT6250FM_ReadWord(FM_RDS_RDATA, &DataRead);
	*Para2 = MT6250FM_RSSI_Reg2dB(DataRead);
	MT6250FM_ReadWord(FM_RDS_RDATA, Para3);
	kal_trace(TRACE_INFO,FM_INFO_SCAN_CQI,*Para1,*Para2,*Para3);
}
void FMDrv_GetScanChannelInfo(FMR_SCAN_Sort_Data *p_SortData,kal_int32 ChannelNum)
{
	kal_int32 offset,i,j=0;
	kal_uint16 reserved,dataRead;
	offset = ChannelNum/16;
	MT6250FM_ReadWord(FM_MAIN_CTRL, &dataRead);
	MT6250FM_WriteWord(FM_MAIN_CTRL, dataRead&0xFFF8);
	MT6250FM_ReadWord(FM_INTE_MASK, &dataRead);
	MT6250FM_WriteWord(FM_INTE_MASK, dataRead&(~FM_RDS_MASK));

	while(offset-->0)
	{
		FMDrv_SetScanInfo();
		for(i=15; i>=0; i--)
		{
			FMDrv_ReadChannelCQI(&p_SortData[j].ChannelNo,&p_SortData[j].RSSI,&reserved);
			j++;
		}
	}
	offset = ChannelNum%16-1;
	if(offset>=0)
	{
		FMDrv_SetScanInfo();
		for(i=offset; i>=0; i--)
		{
			FMDrv_ReadChannelCQI(&p_SortData[j].ChannelNo,&p_SortData[j].RSSI,&reserved);
			j++;
		}
	}
	MT6250FM_ReadWord(FM_INTE_MASK, &dataRead);
	MT6250FM_WriteWord(FM_INTE_MASK, dataRead|FM_RDS_MASK);
}

void FMDrv_JammerScan(void)
{
	kal_uint8 isvalid,search_step=1;/*1.100k,2.200k*/
	kal_uint16 dataRead,curfreq,BitMap[16];
	kal_int32 offset,ChannelNum=0;
//	kal_uint32 ChannelIdex,Jam_Freq,CQI;
	extern const kal_uint16 g_BitMap_Masks[16]; 
	FMR_SCAN_Sort_Data *ChannelData;

	/*disable RDS interrupt*/
//	MT6250FM_ReadWord(FM_INTE_MASK, &dataRead);
//	MT6250FM_WriteWord(FM_INTE_MASK, dataRead&(~FM_RDS_MASK));
	
	MT6250FM_RampDown();
	MT6250FM_ReadWord(FM_CG_CTRL_HOST, &dataRead);	
	MT6250FM_WriteWord(FM_CG_CTRL_HOST,dataRead|FM_JAMMER_SCAN);
	
    FMDrv_SearchSet(search_step);
	MT6250FM_SCAN_ON();

	pstFMR_data->is_preset = KAL_TRUE; 
	pstFMR_data->bHWsearchStop = KAL_FALSE;
	FMDrv_HWSpolling(&curfreq,&isvalid);
	/*read bitmap*/
	for(offset=0; offset<16; offset++)
	{
		FMDrv_GetScanTbl(BitMap, offset);
	}
    for(offset=0; offset<206; offset++)//get channel numbert
    {
		if(BitMap[offset/16] & g_BitMap_Masks[offset%16])
		{
			ChannelNum++;
		}
    }
	if(ChannelNum>0)
	{
		ChannelData = (FMR_SCAN_Sort_Data *)get_ctrl_buffer((sizeof(FMR_SCAN_Sort_Data)* ChannelNum));
		FMDrv_GetScanChannelInfo(ChannelData,ChannelNum);	
		free_ctrl_buffer(ChannelData);
	}
	
	/*disable Jammer scan*/
	MT6250FM_ReadWord(FM_CG_CTRL_HOST, &dataRead);	
	MT6250FM_WriteWord(FM_CG_CTRL_HOST,dataRead&(~FM_JAMMER_SCAN));
	
}
void FMDrv_GetScanTbl(kal_uint16 *BitMapData, kal_uint8 offset)
{
	MT6250FM_ReadWord(FM_RDS_RDATA, &BitMapData[offset]);	
}
#if (defined(FMR_SW_RSSI_SORT)&&(FMR_ENHANCED_SCAN==0))
/*after seek, HW will tune to end freq. So only need to read RSSI*/
kal_bool FMDrv_Seek_Eliminate(kal_uint16 rFreq, kal_uint16 RSSI)
{
	kal_bool EmptyChannel = KAL_FALSE;
	kal_uint16 RSSIValue=0;
    kal_uint32 cnt=0;

   	for(cnt=0; cnt<4; cnt++)
   	{
   	    RSSIValue += MT6250FM_GetCurRSSI();
        Delayus(2250);
   	}
    RSSIValue = RSSIValue/4;
	kal_trace(TRACE_INFO,FM_INFO_SortTuneRssi,rFreq,RSSIValue);
	if(RSSIValue < RSSI)
	{
		EmptyChannel = KAL_TRUE;
	}

	return EmptyChannel;
}
/*p_SortData: channel list struct,
rChannelNo:total channel number
*/
kal_bool FMDrv_SCAN_Sort_Tune(FMR_SCAN_Sort_Data *p_SortData,kal_uint8 rChannelNo)
{
	FMDrv_GetScanChannelInfo(p_SortData,(kal_int32)rChannelNo);
	return KAL_TRUE;
}
#endif
#if (FMR_ENHANCED_SCAN==1)
/*return KAL_TRUE: is severe desense, KAL_FALSE: freq is invalid
*/
kal_bool FMDrv_SevereDensense(kal_uint16 freq,kal_int32 rRSSI)
{
#if (FMR_50K_STEP==1)
	const kal_uint16 List[]={9600,10400};
#else
	const kal_uint16 List[]={960,1040};
#endif
	kal_int32 i;
	for(i=0;i<2;i++)
	{
		if(freq==List[i])
		{
			if(rRSSI<-107)
			{
				kal_trace(TRACE_INFO,FM_INFO_DENSENSE_CHANNEL,freq,1);
				return KAL_TRUE;
			}
		}
	}
	return KAL_FALSE;
}
void FMDrv_PresetScan(void)
{
	kal_uint16 dataRead;
	MT6250FM_RampDown();
	/*soft mute tune*/
	MT6250FM_ReadWord(FM_CG_CTRL_HOST, &dataRead);
	MT6250FM_WriteWord(FM_CG_CTRL_HOST, (dataRead&0xBFFF)|0x4000);
#if defined(MT6250FM)
	/*disable AFC*/
	MT6250FM_ReadWord(0x60, &dataRead);
	MT6250FM_WriteWord(0x60,dataRead&0xFFF7);
	MT6250FM_ReadWord(0x73, &dataRead);
	MT6250FM_WriteWord(0x73,dataRead&0xFBFF);
	MT6250FM_ReadWord(0x60, &dataRead);
	MT6250FM_WriteWord(0x60,dataRead|0x0008);
#endif
}
void FMDrv_RestorePresetScan(void)
{
	kal_uint16 dataRead;
	/*clear soft mute tune bit*/
    MT6250FM_ReadWord(FM_CG_CTRL_HOST, &dataRead);
	MT6250FM_WriteWord(FM_CG_CTRL_HOST,dataRead&(~0x4000));
#if defined(MT6250FM)
	/*enable AFC*/
	MT6250FM_ReadWord(0x60, &dataRead);
	MT6250FM_WriteWord(0x60,dataRead&0xFFF7);
	MT6250FM_ReadWord(0x73, &dataRead);
	MT6250FM_WriteWord(0x73,dataRead|0x0400);
	MT6250FM_ReadWord(0x60, &dataRead);
	MT6250FM_WriteWord(0x60,dataRead|0x0008);
#endif
	MT6250FM_RampDown();
}
void FMDrv_GetSeekOrigFreq(kal_uint16 *OriFreq)
{
    kal_uint16 dataRead;
	MT6250FM_ReadWord(FM_CHANNEL_SET, &dataRead);
#if (FMR_50K_STEP==1)
	*OriFreq = ((dataRead&0x03FF)*5)+6400;
#else
	*OriFreq = ((dataRead&0x03FF)>>1)+640;
#endif
}
/*
freq:target freqency
return KAL_TRUE:freq is valid
KAL_FALSE: freq is invalid
*/

#if defined(MT6250FM)
/*kal_uint16 FMDrv_DesenseBitMap[16]=
{
	0x0300,0x0080,0xE000,0x0001,0x0400,0x0071,0x0000,0x1800,
	0x0000,0x0080,0x0020,0x0000,0x0700,0x0000,0x0000,0x0000
};*/
/*kal_uint16 FMDrv_DesenseBitMap[16]= // 2012.5.15 update
{
	0x0000,0x0000,0xC000,0x0000,0x0000,0x0030,0x0000,0x1800,
	0x0000,0x0000,0x0020,0x0000,0x0300,0x0000,0x0000,0x0000
};*/
const kal_uint16 FMDrv_DesenseBitMap[16]= // 2012.6.13 update
{
	0x0000,0x0000,0xC008,0x0000,0x0000,0x0020,0x0000,0x1800,
	0x0000,0x0000,0x0020,0x0000,0x0300,0x0000,0x0000,0x0000
};
#elif (defined(MT6260FM) || defined(MT6261FM))
const kal_uint16 FMDrv_DesenseBitMap[16]= // 2013.1.21 update
{
	0x0000,0x0000,0xC008,0x0001,0x0000,0x0000,0x0000,0x0810,
	0x0000,0x0000,0x0020,0x0000,0x0300,0x0000,0x0000,0x0000
};
#endif

#if (FMR_50K_STEP==1)
void MT6250FM_Tune_Channel(kal_uint16 freq, kal_bool SoftMute_Flag)
	{
		kal_int16 Index=0;
		kal_uint16 dataRead;
	
		if(SoftMute_Flag)
		{
#if defined(MT6250FM)
		FM_GET_HOPPING_INDEX(freq/10,&Index);
		L1D_FH_FM_SetFreq(Index);
#endif
#if (defined(MT6260FM) || defined(MT6261FM))
		FM_GET_HOPPING_INDEX(freq/10,&Index);
		L1D_FH_FM_Set_PLL_FreeRunParams(Index,0x40);
#endif
		}

		MT6250FM_RampDown();
		MT6250FM_ReadWord(FM_CHANNEL_SET, &dataRead);
#if defined(MT6250FM)
		if(freq%10==0)
			MT6250FM_writeFA(&dataRead, (channel_parameter[freq/10 - 760]));
		else
			MT6250FM_writeFA(&dataRead, 0);
#elif (defined(MT6260FM) || defined(MT6261FM))
		if(freq%10==0)
			MT6250FM_writeFA(&dataRead, (channel_parameter[freq/10 - 650]));
		else
			MT6250FM_writeFA(&dataRead, 0);
#endif
		if(SoftMute_Flag)
		{
			MT6250FM_WriteWord(FM_CHANNEL_SET, (dataRead&0x6C00)|((freq - 6400)/5));//HiLo	enable
		}
		else
		{
			MT6250FM_WriteWord(FM_CHANNEL_SET, (dataRead&0xFC00)|((freq - 6400)/5));//HiLo	enable
		}
		
		MT6250FM_TUNE_ON(); 
		kal_sleep_task(1);/*tune need 10ms, delay 1*4.615ms first*/
		if(MT6250FM_Polling(600)==KAL_FALSE)
		{	 
			ASSERT(0);/*timeout*/
		}
		MT6250FM_ReadWord(FM_MAIN_INTR, &dataRead); 	 
		MT6250FM_WriteWord(FM_MAIN_INTR, dataRead|FM_INTR_STC_DONE);//clear status flag
			
	}

#else
void MT6250FM_Tune_Channel(kal_uint16 freq, kal_bool SoftMute_Flag)
{
	kal_int16 Index=0;
	kal_uint16 dataRead;

	if(SoftMute_Flag)
	{
#if defined(MT6250FM)
	FM_GET_HOPPING_INDEX(freq,&Index);
	L1D_FH_FM_SetFreq(Index);
#endif
#if (defined(MT6260FM) || defined(MT6261FM))
	FM_GET_HOPPING_INDEX(freq,&Index);
	L1D_FH_FM_Set_PLL_FreeRunParams(Index,0x40);
#endif
	}
	
    MT6250FM_RampDown();
    MT6250FM_ReadWord(FM_CHANNEL_SET, &dataRead);
#if defined(MT6250FM)
    MT6250FM_writeFA(&dataRead, (channel_parameter[freq - 760]));
#elif (defined(MT6260FM) || defined(MT6261FM))
	MT6250FM_writeFA(&dataRead, (channel_parameter[freq - 650]));
#endif
	if(SoftMute_Flag)
	{
    MT6250FM_WriteWord(FM_CHANNEL_SET, (dataRead&0x6C00)|((freq - 640)<<1));//HiLo  enable
	}
	else
	{
		MT6250FM_WriteWord(FM_CHANNEL_SET, (dataRead&0xFC00)|((freq - 640)<<1));//HiLo	enable
	}
    
    MT6250FM_TUNE_ON();	
	kal_sleep_task(1);/*tune need 10ms, delay 1*4.615ms first*/
	if(MT6250FM_Polling(600)==KAL_FALSE)
    {    
		ASSERT(0);/*timeout*/
	}
	MT6250FM_ReadWord(FM_MAIN_INTR, &dataRead);		 
	MT6250FM_WriteWord(FM_MAIN_INTR, dataRead|FM_INTR_STC_DONE);//clear status flag
		
}
#endif
/*return KAL_TRUE:freq is valid, KAL_FALSE: freq is invalid
*/
kal_bool FMDrv_GetSofteMute(kal_uint16 freq,kal_int32 *rRSSI)
{
	kal_uint16 dataRead,softmuteGain=0;
	kal_bool Valid=KAL_FALSE;
	FM_CQIs FM_cqi;
		
	MT6250FM_Tune_Channel(freq, KAL_TRUE);
		
	/*get CQIs*/
	memset(&FM_cqi, 0, sizeof(FM_CQIs));
	Delayms(9);
	Average_Of_CQIs(&FM_cqi);	
#if defined(MT6250FM)
	FMDrv_ReadDSP(0x02C1,&dataRead);
#elif (defined(MT6260FM) || defined(MT6261FM))
	MT6250FM_ReadWord(FM_SMG_REG, &dataRead); 	 
#endif
	softmuteGain=dataRead;
	
	*rRSSI = FM_cqi.RSSI;
	FMR_RSSI_THRESHOLD = (FMR_RSSI_THRESHOLD < -4) ? -4 : FMR_RSSI_THRESHOLD;
	FMR_RSSI_THRESHOLD = (FMR_RSSI_THRESHOLD > 70) ? 70 : FMR_RSSI_THRESHOLD;
	FMR_RSSI_LANTTH = (kal_int32)((FMR_RSSI_THRESHOLD + 6 - 113) * 16 / 6);	
	if((FM_cqi.RSSI>=FMR_RSSI_LANTTH)&&(FM_cqi.PAMD<=FMR_PAMD_TH)&&(FM_cqi.ATDC<=FMR_ATDC_TH)&&(FM_cqi.MR>=FMR_MRTH)&&(FM_cqi.PRX>=FMR_PRX_TH)&&(softmuteGain>FMR_AUDIO_TH[FMR_AUDIO_LEVEL]))
	{
		if(FM_cqi.ATEDV>=FM_cqi.ATDC)
		{
			Valid=KAL_TRUE;
		}
	}
	kal_trace(TRACE_INFO,FM_INFO_SOFT_MUTE_TUNE_CQI,freq,FM_cqi.RSSI,FM_cqi.PAMD,FM_cqi.ATDC,FM_cqi.MR,FM_cqi.PRX,softmuteGain,FM_cqi.ATEDV,Valid);
	return Valid;
}
#endif

/**APIs for EM**/
kal_uint32 FMDrv_GetRSSITH(kal_uint8 type)/*0: long ant. 1: short ant.*/
{
	kal_uint32 RSSI_TH;
	if(type == 0)
	{
		RSSI_TH = 0x301;
	}
	else
	{
		RSSI_TH = 0x2e0;
	}
	return RSSI_TH;
}
void FMDrv_SetRSSITH(kal_uint8 type,kal_uint32 value)/*0: long ant. 1: short ant.*/
{
	if(type == 0)
	{
	}
	else
	{
	}
}
kal_int32 FMDrv_RSSI_Hex2Db(kal_uint32 Hex)
{
	kal_int32 dBValue;
	
    dBValue = Hex&0x3FF;
	dBValue = (kal_int32)((dBValue>511)?(((float)dBValue-1024)*6/16+113):((float)dBValue*6/16+113));
    
    return dBValue;
}
kal_uint32 FMDrv_RSSI_Db2Hex(kal_int32 Db)
{
	kal_int32 dBValue;
	kal_uint32 HexValue;
	dBValue = (Db-113)*16/6;
	HexValue = (kal_uint32)((dBValue < 0)?(dBValue+0x10000):(dBValue+0xFC00));
	return HexValue;
}
void FMDrv_Force_Mono(void)
{
	kal_uint16 RegTemp;
	
	MT6250FM_ReadWord(0x60,&RegTemp);
	MT6250FM_WriteWord(0x60, RegTemp&(~0x0008));/*change to SW control*/
	
	MT6250FM_ReadWord(0x75,&RegTemp);
	MT6250FM_WriteWord(0x75, RegTemp|0x0008);/*force MONO*/
	
	MT6250FM_ReadWord(0x60,&RegTemp);
	MT6250FM_WriteWord(0x60, RegTemp|0x0008);/*change to DSp control*/
}
void FMDrv_Force_Stereo(void)
{
	kal_uint16 RegTemp;

	MT6250FM_ReadWord(0x60,&RegTemp);
	MT6250FM_WriteWord(0x60, RegTemp&(~0x0008));/*change to SW control*/
	
	MT6250FM_ReadWord(0x75,&RegTemp);
	MT6250FM_WriteWord(0x75, RegTemp&(~0x0008));/*auto modulate*/
	
	MT6250FM_ReadWord(0x60,&RegTemp);
	MT6250FM_WriteWord(0x60, RegTemp|0x0008);/*change to DSp control*/
}
kal_bool FMDrv_IsChipValid( void )
{
	return KAL_TRUE;
}
void FMDrv_GetCQILIst(kal_char **CQIList)
{
#ifdef __MTK_TARGET__	   
	kal_uint16 TmpReg;
	FM_CQIs FM_cqi;
		
	memset(&FM_cqi, 0, sizeof(FM_CQIs));
	Delayms(9);

	Average_Of_CQIs(&FM_cqi);
	
	//Soft_mute Gain
#if defined(MT6250FM)
	FMDrv_ReadDSP(0x02C1,&TmpReg);
#elif (defined(MT6260FM) || defined(MT6261FM))
	MT6250FM_ReadWord(FM_SMG_REG, &TmpReg);	 
#endif
	kal_sprintf(CQIList[8],"0x%04x,",TmpReg);
	//MT6250FM_WriteWord(FM_PG_SEL, 0);
	
	//delta RSSI
#if defined(MT6250FM)
	FMDrv_ReadDSP(0x02D4,&TmpReg);
#elif (defined(MT6260FM) || defined(MT6261FM))
	MT6250FM_ReadWord(FM_DELTARSSI_REG, &TmpReg);	 
#endif
	kal_sprintf(CQIList[9],"0x%04x,",TmpReg);

	kal_sprintf(CQIList[0],"0x%04x,", (kal_int16)(FM_cqi.RSSI) & 0x03FF);
	kal_sprintf(CQIList[1],"0x%04x,", (kal_int16)(FM_cqi.PAMD) & 0x01FF);
	kal_sprintf(CQIList[2],"0x%04x,", (kal_uint16)(FM_cqi.PR) & 0x03FF);
	kal_sprintf(CQIList[3],"0x%04x,", (kal_int16)(FM_cqi.FPAMD) & 0x0FFF);
	kal_sprintf(CQIList[4],"0x%04x,", (kal_int16)(FM_cqi.MR) & 0x01FF);
	kal_sprintf(CQIList[5],"0x%04x,", (kal_int16)(FM_cqi.ATDC) & 0xFFFF);
	kal_sprintf(CQIList[6],"0x%04x,", (kal_uint16)(FM_cqi.PRX) & 0x00FF);
	kal_sprintf(CQIList[7],"0x%04x,", (kal_uint16)(FM_cqi.ATEDV) & 0xFFFF);

//	kal_sprintf(CQIList[i],"0x%x\n",0x1234);
#endif
}

void Average_Of_CQIs(FM_CQIs *FM_cqi)
{
	kal_uint16 TmpReg;
	kal_int32 i;
	
	for(i=8; i>0; i--)
	{
	//RSSI
	MT6250FM_ReadWord(FM_RSSI, &TmpReg);
		(*FM_cqi).RSSI += ((TmpReg&0x3FF)>=512)?((TmpReg&0x3FF)-1024):(TmpReg&0x3FF);
			
	//PAMD
	MT6250FM_ReadWord(FM_PAMD_REG, &TmpReg);
		(*FM_cqi).PAMD += ((TmpReg&0x1FF)>=256)?((TmpReg&0x1FF)-512):(TmpReg&0x1FF);

	//PR
	MT6250FM_ReadWord(FM_PR_REG, &TmpReg);
		(*FM_cqi).PR += (TmpReg&0x3FF);		

	//FPAMD
	MT6250FM_ReadWord(FM_FPAMD_REG, &TmpReg);
		(*FM_cqi).FPAMD += ((TmpReg&0xFFF)>=2048)?((TmpReg&0xFFF)-4096):(TmpReg&0xFFF);

	//MR
	MT6250FM_ReadWord(FM_MR_REG, &TmpReg);
		(*FM_cqi).MR += ((TmpReg&0x1FF)>=256)?((TmpReg&0x1FF)-512):(TmpReg&0x1FF);

	//ATDC
	MT6250FM_ReadWord(FM_ATDC_REG, &TmpReg);
		(*FM_cqi).ATDC += (TmpReg>=32768)?(65536-TmpReg):(TmpReg);

	//PRX
	MT6250FM_ReadWord(FM_PRX_REG, &TmpReg);
		(*FM_cqi).PRX += (TmpReg&0xFF);

	//ATDEV
	MT6250FM_ReadWord(FM_ATDEV_REG, &TmpReg);
		(*FM_cqi).ATEDV += TmpReg;

		Delayus(2250);
	}

	(*FM_cqi).RSSI = ((*FM_cqi).RSSI + 4)/8;
	(*FM_cqi).PAMD = ((*FM_cqi).PAMD + 4)/8;
	(*FM_cqi).PR  = ((*FM_cqi).PR  + 4)/8;
	(*FM_cqi).FPAMD = ((*FM_cqi).FPAMD + 4)/8;
	(*FM_cqi).MR = ((*FM_cqi).MR + 4)/8;
	(*FM_cqi).PRX = ((*FM_cqi).PRX + 4)/8;
	(*FM_cqi).ATEDV = ((*FM_cqi).ATEDV + 4)/8;
	(*FM_cqi).ATDC = ((*FM_cqi).ATDC + 4)/8;
	
}
/*FS test code*/
void FMDrv_Freq_CQI_Log(kal_uint8 FileMax)
{
#ifdef __MTK_TARGET__	   
	kal_int8 drive=FS_NO_ERROR;
	FS_DiskInfo DI;
	kal_int32 ret,i,j;
	kal_wchar driName[12];
	FS_HANDLE FS_handle = 0;
	kal_uint32 WrittenLength;
	//kal_uint8 teststring[7];
	kal_char FreqNo[7];
	kal_char *CQIList[10];
	kal_char Data[10][8];
	kal_uint8 CQINum=10;
	//kal_uint16 TmpReg;
	kal_int32 FileCnt = 1;
	kal_uint16 Freq;

   // if (((drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE ) >= 'A') && (drive <= 'Z'))
	drive = FS_GetDrive(/*FS_DRIVE_V_NORMAL*/FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE );
	//kal_prompt_trace(MOD_FMR,"%x.drive=%d=%c",FS_DRIVE_V_NORMAL,drive,(kal_uint8)drive);
	kal_wsprintf(driName,"%c:\\",drive);
	//kal_prompt_trace(MOD_FMR,"driName=%s",driName);
	ret = FS_GetDiskInfo((const kal_wchar *)driName,&DI,FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
	if(ret > FS_NO_ERROR)
	{
		//kal_prompt_trace(MOD_FMR,"DriveLetter=%d,WriteProtect=%d,TotalClusters=%d,FreeClusters=%d,SectorsPerCluster%d,BytesPerSector=%d",DI.DriveLetter,DI.WriteProtect,DI.TotalClusters,DI.FreeClusters,DI.SectorsPerCluster,DI.BytesPerSector);
	}
	else
	{
		//kal_prompt_trace(MOD_FMR,"ERROR.ret=%d",ret);
	}
	if(DI.WriteProtect)
	{
		//kal_prompt_trace(MOD_FMR,"ERROR:Disk write protected!!!");
		ASSERT(0);
	}

	for(i=0; i<CQINum; i++)
	{
		CQIList[i]=Data[i];
	}

	for(FileCnt=1; FileCnt<FileMax+1; FileCnt++)
	{
		kal_wsprintf(driName,"%c:\\FMcqiLog%d", drive, FileCnt);
	//kal_prompt_trace(MOD_FMR,"driName=%s",driName);
	FS_handle = FS_Open((const kal_wchar*)driName,FS_READ_WRITE|FS_CREATE);
	//kal_prompt_trace(MOD_FMR,"FS_handle=%d",FS_handle);
	if(FS_handle > FS_NO_ERROR)
	{
			ret = FS_Write(FS_handle, (void *)"Freq,   RSSI,   PAMD,   PR,     FPAMD,  MR,     ATDC,   PRX,    ATDEV,  SMGain, DltaRSSI",88,&WrittenLength);
		
		for(Freq=875; Freq<=1080; Freq++)
		{
			kal_sprintf(FreqNo,"\n%04d,\0",Freq);				
			ret = FS_Write(FS_handle, (void *)FreqNo,sizeof(FreqNo),&WrittenLength);
			ret = FS_Write(FS_handle, (void *)"\0",1,&WrittenLength);
			if(ret < FS_NO_ERROR)
			{
				//error
			}
			
			FMDrv_PresetScan(); 	//soft mute set
			MT6250FM_Tune_Channel(Freq, KAL_TRUE);
			FMDrv_GetCQILIst(CQIList);
		    
			for(j=0; j<CQINum; j++)
			{
				ret = FS_Write(FS_handle, (void *)CQIList[j],sizeof(Data[j]),&WrittenLength);
				if(ret < FS_NO_ERROR)
				{
					//error
				}
			}
			//kal_prompt_trace(MOD_FMR,"WrittenLength=%d",WrittenLength);
		}
		
			FMDrv_RestorePresetScan();	//soft mute clear				
			FS_Close(FS_handle);
		}
	}
#endif	
}

void FMDrv_Freq_CQI_Through_Time_Log(kal_uint8 FreqHigh, kal_uint8 FreqLow, kal_uint8 sTime)
{
#ifdef __MTK_TARGET__
	kal_int8 drive = FS_NO_ERROR;
	FS_DiskInfo DI;
	kal_int32 ret;
	kal_wchar driName[12];
	FS_HANDLE FS_handle = 0;	
	kal_uint32 WrittenLength;
	kal_uint32 TimeCnt = 1;
	kal_uint32 i = 0, j = 0;
	kal_uint16 TempData = 875;	
	kal_char Data[10][8];	
#if defined(MT6250FM)
	kal_int16 Index;
#endif
	TimeCnt = (kal_uint32)(sTime * 1000 / 4.615);
	TempData = (FreqHigh<<8) | FreqLow;
	
	drive = FS_GetDrive(/*FS_DRIVE_V_NORMAL*/FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE );		
	kal_wsprintf(driName,"%c:\\",drive);		
	ret = FS_GetDiskInfo((const kal_wchar *)driName, &DI, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
	
	if(DI.WriteProtect)
	{
		//kal_prompt_trace(MOD_FMR,"ERROR:Disk write protected!!!");
		ASSERT(0);
	}
		
	kal_wsprintf(driName, "%c:\\FMcqiThroughTimeLog%d", drive,TempData);
	FS_handle = FS_Open((const kal_wchar*)driName,FS_READ_WRITE|FS_CREATE);
	if(FS_handle > FS_NO_ERROR)
	{
		ret = FS_Write(FS_handle, (void *)"PAMD,   FPAMD,  ATDC,  DltaRSSI,RSSI,   PR,     MR,     PRX,    ATDEV,   SMGAIN\n",80,&WrittenLength);		
#if defined(MT6250FM)
		FM_GET_HOPPING_INDEX(TempData,&Index);
   		L1D_FH_FM_SetFreq(Index);		
#endif
		FMDrv_PresetScan(); 	//soft mute set
		FMDrv_SetFreq(TempData);
		
		Delayms(30);	
		
		for(i=1; i<TimeCnt; i++)
		{
			//Delta RSSI
#if defined(MT6250FM)
			FMDrv_ReadDSP(0x02D4,&TempData);
#elif (defined(MT6260FM) || defined(MT6261FM))
			MT6250FM_ReadWord(FM_DELTARSSI_REG, &TempData);	 
#endif
			kal_sprintf(Data[3],"0x%04x,\0",TempData);
		
			//PAMD
			MT6250FM_ReadWord(FM_PAMD_REG, &TempData);
			kal_sprintf(Data[0],"0x%04x,\0",TempData);
			
			//FPAMD
			MT6250FM_ReadWord(FM_FPAMD_REG, &TempData);
			kal_sprintf(Data[1],"0x%04x,\0",TempData);
			
			//ATDC
			MT6250FM_ReadWord(FM_ATDC_REG, &TempData);
			kal_sprintf(Data[2],"0x%04x,\0",TempData);

			//RSSI
			MT6250FM_ReadWord(FM_RSSI, &TempData);
			kal_sprintf(Data[4],"0x%04x,\0",TempData);
			
			//PR
			MT6250FM_ReadWord(FM_PR_REG, &TempData);
			kal_sprintf(Data[5],"0x%04x,\0",TempData);
			
			//MR
			MT6250FM_ReadWord(FM_MR_REG, &TempData);
			kal_sprintf(Data[6],"0x%04x,\0",TempData);
			
			//PRX
			MT6250FM_ReadWord(FM_PRX_REG, &TempData);
			kal_sprintf(Data[7],"0x%04x,\0",TempData);
			
			//ATDEV
			MT6250FM_ReadWord(FM_ATDEV_REG, &TempData);
			kal_sprintf(Data[8],"0x%04x,\0",TempData);
			
			//Soft_mute Gain
#if defined(MT6250FM)
			FMDrv_ReadDSP(0x02C1,&TempData);
#elif (defined(MT6260FM) || defined(MT6261FM))
			MT6250FM_ReadWord(FM_SMG_REG, &TempData);  
#endif
			kal_sprintf(Data[9],"0x%04x,\n",TempData);
			Delayus(2250);			
			
			for(j=0; j<10; j++)
			{
				ret = FS_Write(FS_handle, (void *)Data[j],sizeof(Data[j]),&WrittenLength);
				if(ret < FS_NO_ERROR)
				{
					//error
				}
			}
			//kal_prompt_trace(MOD_FMR,"WrittenLength=%d",WrittenLength);
		}
		
		FMDrv_RestorePresetScan();	//soft mute clear	
		FS_Close(FS_handle);
	}
#endif	
}

void FMDrv_EM_Set_AudioLevel(kal_uint8 AudioLevel)
{
	if(AudioLevel < 5)
	{
		FMR_AUDIO_LEVEL = (FMR_Audio_Level_e)AudioLevel;
	}
	else
	{
		FMR_AUDIO_LEVEL = (FMR_Audio_Level_e)1;
	}
	 
}
void FMDrv_EM_Set_RSSI(kal_uint8 RSSILevel)
{
	if(RSSILevel < 71)
	{
		FMR_RSSI_THRESHOLD = RSSILevel;
	}
	else if((RSSILevel > 128) & (RSSILevel < 133))
	{
		FMR_RSSI_THRESHOLD = 128 - RSSILevel;
	}
	else
	{
		FMR_RSSI_THRESHOLD = -4;
	}
}

void FMDrv_EM_Set_DesenseLevel(kal_uint8 DesenseLevel)
{
	if(DesenseLevel < 7)
	{
		FMR_DESENSE_LEVEL = DesenseLevel;
	}
	else
	{
		FMR_DESENSE_LEVEL = 1;
	}
}

#if defined(__CLASSK_CP_SUPPORT__)
kal_bool FMDrv_ClassK_Permit()
{
	kal_bool ClassK_Enable;
	kal_int32 i;
	kal_uint32 rssi = 0;
	kal_uint16 RssiPassTH = 26;	//dBuVemf
	kal_uint16 RssiFailTH = 2;	//dBuVemf

	for(i=8;i>0;i--)
	{
		rssi += MT6250FM_GetCurRSSI();
		Delayus(2250);
	}
	rssi /= 8;

	ClassK_Enable = Media_IsChargePump();

	if(ClassK_Enable)	
	{
		if(rssi < RssiFailTH)	//pass->fail
		{
			return KAL_FALSE;
		}
		else
			return KAL_TRUE;
	}
	else
	{
		if(rssi > RssiPassTH)	//fail->pass
		{
			return KAL_TRUE;
		}
		else
			return KAL_FALSE;
	}
}


void FMDrv_ClassK_Desense_Check(void * param)
{
	kal_bool ClassK_Enable;

	ClassK_Enable = FMDrv_ClassK_Permit();

	if(ClassK_Enable != Media_IsChargePump())
	{
		Media_SetChargePump(ClassK_Enable, MEDIA_VCP_FM);
	}
	
	fm_stop_timer(FM_CLASSK_CHECK_RSSI_TIMER);
	fm_start_timer(FM_CLASSK_CHECK_RSSI_TIMER, FM_CLASSK_CHECK_RSSI_INTERVAL, FMDrv_ClassK_Desense_Check, NULL);

}
#endif
#if (FM_ESD_RECOVERY == 1)
void FMDrv_ESD_Check(void * param)
{
	kal_uint16 dataRead;

	fm_stop_timer(FM_ESD_TIMER);
	
	MT6250FM_ReadWord(0x62, &dataRead);
	if((dataRead != 0x6250)&&(dataRead != 0x6260)&&(dataRead != 0x6261))
	{
		ESD_Recovery = KAL_TRUE; //recovering
		FMDrv_ESD_Recovery();
		ESD_Recovery = KAL_FALSE; //recovery finish
	}
	
	fm_start_timer(FM_ESD_TIMER, FM_ESD_TIMER_INTERVAL, FMDrv_ESD_Check, NULL);
}

void FMDrv_ESD_Recovery(void)
{
    kal_int16 temp_curFreq = _current_frequency;
	kal_uint16 dataRead;
	
	//reset FSPI & FM_digital_core
	*((volatile unsigned int*)0xA0260030) |= (0x3<<0);
	Delayus(200);
	dataRead = *((volatile unsigned int*)0xA0260030);
	kal_prompt_trace(MOD_FMR,"after reset,0xA0260030=%d", dataRead);
	*((volatile unsigned int*)0xA0260030) &= ~(0x3<<0);
	Delayus(200);
	dataRead = *((volatile unsigned int*)0xA0260030);
	kal_prompt_trace(MOD_FMR,"reset finish,0xA0260030=%d", dataRead);

	*((volatile unsigned int*)0xA0260048) &= ~(0x3<<0);
	Delayus(200);
	dataRead = *((volatile unsigned int*)0xA0260048);
	kal_prompt_trace(MOD_FMR,"after reset,0xA0260048=%d", dataRead);
	*((volatile unsigned int*)0xA0260048) |= (0x3<<0);
	Delayus(200);
	dataRead = *((volatile unsigned int*)0xA0260048);
	kal_prompt_trace(MOD_FMR,"reset finish,0xA0260048=%d", dataRead);

	
	FMDrv_PowerOffProc();
	FMDrv_PowerOnReset();
	_current_frequency = temp_curFreq;
	FMDrv_SetFreq(temp_curFreq);
}
#endif

#endif // defined(MT6250FM)
