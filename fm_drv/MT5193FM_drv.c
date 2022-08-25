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
 * MT5195_drv.c
 *  refernce fm_drv/MT6189A1_drv.c
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      FM Radio Driver (MT5195)
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#if defined(__MTK_TARGET__)
#if defined(MT5193FM)
#include "kal_release.h"
#include "fmr_main.h"
#if (defined(MT6235)||defined(MT6235B))
#include "pmu_sw.h"
#elif (defined(MT6253T)||defined(MT6253))
#include "pmu6253_sw.h"
#endif

typedef kal_uint8	uint8;
typedef kal_uint16	uint16;
typedef kal_uint32	uint32;
typedef kal_uint8	UINT8;
typedef kal_uint16	UINT16;
typedef kal_uint32	UINT32;
typedef kal_int8	int8;
typedef kal_int16	int16;
typedef kal_int32	int32;
typedef kal_uint8	s8;
typedef kal_uint16	s16;
typedef kal_uint32	s32;
typedef kal_uint8	U8;
typedef kal_uint16	U16;
typedef kal_uint32	U32;
typedef kal_uint8	BYTE;
typedef kal_uint16	WORD;
typedef kal_uint32	DWRD;
typedef kal_uint8	UCHAR;
typedef kal_bool	BOOL;
typedef kal_bool	bool;
#define false KAL_FALSE			
#define true KAL_TRUE				

extern void mloop(void);
extern void fm_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg);
extern void fm_stop_timer(kal_uint8 timer_id);
extern void ATV_i2c_init(void);
extern void vApiAudioStop(void);
#ifdef __CUST_NEW__
extern const char gpio_matv_power_en_pin;
extern const char gpio_matv_reset_pin;
#else
const char gpio_matv_power_en_pin = 4;	//using GPIO4
const char gpio_matv_reset_pin = 3;	//using GPIO3
#endif
#ifndef __FMRADIO_I2S_SUPPORT__
extern void vApiAudioSetOutputMode(UINT8 output_mode);
#endif
/*============================================================
    FM radio control APIs
  ============================================================*/

UINT8 u1ApiAudioStartFmRdoDetect (BYTE bDefaultMode);

// for sleep mode control
static kal_uint8 slp_handle;
static bool bIsSleepHandleInit = false;

//-----------------------------------------------------------------------------
// fgApiAudioIsFmRdoDetectDone
//
/** Brief of fgApiAudioIsFmRdoDetectDone.
 *  Details of fgApiAudioIsFmRdoDetectDone (optional).
 *
 *  @param      void  
 *
 *  @retval     TRUE	        
 *  @retval     FALSE       
 */
//-----------------------------------------------------------------------------
BOOL fgApiAudioIsFmRdoDetectDone (void);

//-----------------------------------------------------------------------------
// bApiAudioGetFmRdoDetectStatus
//
/** Brief of bApiAudioGetFmRdoDetectStatus.
 *  Details of bApiAudioGetFmRdoDetectStatus (optional).
 *
 *  @param      UINT32*        pointer of information of detection  
 *
 *  @retval      BYTE          Detection result  
 */
//-----------------------------------------------------------------------------
BYTE bApiAudioGetFmRdoDetectStatus (kal_uint32 *info);


void vApiAudioSetMasterVolume (BYTE bValue);

//void vApiAudioSetFmMute(int32 eDecType, 
//			int32 eChangedItem, 
//			UINT8 u1Value);
void AUD_DspSetFmMute(int32 eDecType, 
                                int32 eChangedItem, 
                                UINT8 u1Value);
	//eDecType = AUD_ATV_DECODER_FMRDO
	//eChangedItem = AUD_FACTORY_FM_MUTE
	//u1Value = 1/0                                                  

BYTE dwApiAudioGetFormatSrc(void);
	//FMRDO_MONO = 1
	//FMRDO_STEREO = 2
	
void vApiAudioMainloop(void);

	typedef enum 
	{
		SV_NONE_DETECTED,	//0x0
		SV_MTS,			    //0x1
		SV_FM_FM,		    //0x2
		SV_NTSC_M,		    //0x3
		SV_A2_BG,		    //0x4
		SV_A2_DK1,		    //0x5
		SV_A2_DK2,		    //0x6
		SV_A2_DK3,		    //0x7
		SV_PAL_I,		    //0x8
		SV_PAL_BG,		    //0x09
		SV_PAL_DK,		    //0x0a
		SV_SECAM_L,         //0x0b
		SV_SECAM_L_PLUM,    //0x0c
		SV_SECAM_BG,	    //0x0d
		SV_SECAM_DK,        //0x0e
		SV_FMRDO,           //0x0f
	SV_SLT,         //0x10
	SV_NUM		
	} TV_AUD_SYS_T;
enum
{
	//export to standard enum (mandatory)
	EXPORT_SIG_RSSI=0,
	EXPORT_SIG_SNR,
	EXPORT_SIG_STRENGTH,
	EXPORT_TVD_MaxFrameRate, /* ref. eTVDMaxFramerate */
	EXPORT_AUD_OutputMode,
	EXPORT_AUD_SWMute,
	
	/* item >= 100, variant info, not fixed
	 * example
	 * MTK_GAIN0=100,
	 * MTK_GAIN1=101 
	 */
	MTK_TVD_MaxFrameRate=180,	/* ref. eTVDMaxFramerate */
	MTK_TVD_CamIFRefMCLK,		/* ref. eOnOff */
	MTK_TVD_CamIFMode,		/* ref. eTVDCamIFMode */
	MTK_TVD_CamIFCaptureMode,	/* ref. eOnOff */
	MTK_TVD_CamIFResolution,	/* (width<<16)|height */
	MTK_TVD_SMOOTHER,			/* ref. (eTVDSMOOTHER<<4)|Thr */
	MTK_TVD_PCLK_INV,			/* ref. eOnOff */
	MTK_TVD_FrameRate,
	MTK_TVD_FRDIV2_WA,			/* 1~5, 0xff*/
	MTK_TVD_ScanLockPara,			/*VOFST_TH Recheck_TH CHECKTVD_ROUND,  */
	MTK_AUD_OutputMode=190,		/* ref. eAUDOutputMode */
	MTK_AUD_SWMute,	
	MTK_CLI_PORT=200,

	MTK_DRV_VERSION_ID=202,
	MTK_DRV_VERSION_SUB_ID,
	MTK_LCM_WRITECYCLE=210,
	MTK_PAD_DRIVING,	/* (pin<<4)|driving ; pin:0~7, H, V, PCLK*/
	MTK_ATD_EQ,
	MTK_TVD_AdapC,
	MTK_AUD_AVC,
	MTK_AUD_SmartToggling
};
void vApiAudioSetChannelSrc(TV_AUD_SYS_T bChSrc);


void vApiAudioSetFmRdoStereoBlendFlag (UINT8 u1Flag);
void vApiSetFmScanTh (UINT32 _u4Idx, UINT32 _u4Val);

//#include "drv_comm.h"

/* FM radio scanning set threshold
*/
#define FM_SCAN_UP 0x14000
#define FM_SCAN_DOWN 0x8000
#define FM_SCAN_RES 128
#define FM_SCAN_STEP ((FM_SCAN_UP - FM_SCAN_DOWN) / FM_SCAN_RES)

static int8 fm_scan_eng_val = 0;
static bool fm_scan_eng_valid = false; // 1 --> enter engineer mode once
#define CUSTOM_MATV_AVC_FM 0

// i4Val = 0 ~ 127
static void MT5192_FM_SetTH (int8 i1Val)
{
	UINT32 u4Th;
	
	if (fm_scan_eng_valid)
	{
		i1Val = fm_scan_eng_val;	
	}
	
	if (i1Val & 0x80)
	{
		i1Val = 127;
	}
	i1Val = 127 - i1Val;
	
	u4Th = FM_SCAN_DOWN + (FM_SCAN_STEP * i1Val);
	vApiSetFmScanTh (2,u4Th);
}

//static bool chip_valid= false; //kai fix build warning
static bool  _is_fm_on = false;
extern kal_semid 	matv_sem_id;

// bool fgApiAudioGetFMRadioInfo(kal_uint32* power)
static bool MT5192_FM_GetRSSI(kal_uint32* power)
{
	bool ret;
	float rssi;
#if 1
	kal_sleep_task(kal_milli_secs_to_ticks(16));
	vApiGetFmrdoScanSignalLevel(&rssi);
	*power = (kal_uint32)rssi;
    ret = 1;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
	return ret;
}

extern void vApiMT5192_FmRdoSetFreq (UINT32 u4Freq, UINT8 u1Mode);
extern vApiFmRdoScanInit(void);
#if 0   //kai fix build warning
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
#if 1
/* under construction !*/
#else	
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
/* under construction !*/
#endif

// enginner mode struct
typedef enum group_idx {
	   mono=0,
	   stereo,
	   RSSI_threshold,
	   IF_count_delta,
	   GROUP_TOTAL_NUMS
	} FACTORY_GROUP_ENUM;
	
typedef enum item_idx {
	   Sblend_OFF=0,
	   Sblend_ON,  
	   ITEM_TOTAL_NUMS
	} FACTORY_ITEM_INDEX;
// enginner mode struct



	#define FMRDO_MONO      0x00010000
	#define FMRDO_STEREO    0x00020000
extern void vApiAudioSetAtvOutputMode(UINT32 eSoundMode);

void FMDrv_radio_item_info(kal_uint16 group_idx, kal_uint16 item_idx, kal_uint32 item_value)
{	
	kal_take_sem(matv_sem_id, KAL_INFINITE_WAIT);
	switch (group_idx)
	{
		case mono:
			if(item_value == 1)
  			{	//enable force mono?
  				// mono--> mono, stereo-> mono
  				vApiAudioSetAtvOutputMode(FMRDO_MONO);
		      	}
		      	else
		      	{	//disable force mono?
			      	// mono--> mono, stereo->  stereo
			      	vApiAudioSetAtvOutputMode(FMRDO_STEREO);
		      	}   
		break;
		case stereo:
			if(item_value == 0)
			{	//disable == enable force mono
				vApiAudioSetAtvOutputMode(FMRDO_MONO);
			}
			else
			{	//enable
				 vApiAudioSetAtvOutputMode(FMRDO_STEREO);
				switch (item_idx)
				{
					case Sblend_ON:
					vApiAudioSetFmRdoStereoBlendFlag(1);
					break;
					case Sblend_OFF:
					vApiAudioSetFmRdoStereoBlendFlag(0);
					break;
				}
			}
		break;
		case RSSI_threshold: 
			if((item_value<1)||(item_value>6))
				item_value=1;
			if (item_value == 1)
		        	fm_scan_eng_val = 20;		        	
		    	else if (item_value == 2)
		        	fm_scan_eng_val = 26;
		    	else if (item_value == 3)
		        	fm_scan_eng_val = 31;
		    	else if (item_value == 4)
		        	fm_scan_eng_val = 47;
		    	else if (item_value == 5)
		        	fm_scan_eng_val = 68;
		    	else if (item_value == 6)
		        	fm_scan_eng_val = 79;
		    	else
		    		fm_scan_eng_val = 31; 
		    		
		    	fm_scan_eng_valid = true; 	
			break;
		case IF_count_delta:
		break;
		
	}
	kal_give_sem(matv_sem_id);
}

/// level ranges from 0 to 12
//static bool adaptfm_mute; //kai fix build warning
static uint8  adaptfm_volume=127;
void FMDrv_SetVolumeLevel(uint8 level)
{
	kal_take_sem(matv_sem_id, KAL_INFINITE_WAIT);
	//DANIEL_20091210
	adaptfm_volume=level * 127 / 12;
	vApiAudioSetMasterVolume((kal_uint32)adaptfm_volume);
	//DANIEL_20091210
	kal_give_sem(matv_sem_id);
}

void FMDrv_Mute(uint8 mute)
{
	kal_take_sem(matv_sem_id, KAL_INFINITE_WAIT);
	//DANIEL_20091210
	//adaptfm_mute=(bool)mute;  //kai fix build warning
	vApiAudioSetMasterVolume(mute?0:adaptfm_volume);
	vApiAudioMainloop();
	//DANIEL_20091210
	kal_give_sem(matv_sem_id);
}
extern uint8 bChipInit(uint8 tvmode);
extern UINT8 bChipShutdown(void);
static	UINT32 chip_id;
/* integrate with TV
void FMDrv_MLoop(void *param)
{
	kal_take_sem(matv_sem_id, KAL_INFINITE_WAIT);
	mloop();
	kal_give_sem(matv_sem_id);
	fm_stop_timer(FM_MLoop_CHECK_TIMER);
	if(_is_fm_on)
	  fm_start_timer(FM_MLoop_CHECK_TIMER, FM_MLoop_CHECK_INTERVAL, FMDrv_MLoop, NULL);//ALBERT_1212_01	
} */

kal_bool matvdrv_poweroff_seq(void);
kal_bool matvdrv_poweron_seq(int tvmode);
extern void L1SM_SleepDisable( kal_uint8 handle );
extern void L1SM_SleepEnable( kal_uint8 handle );
extern kal_uint8 L1SM_GetHandle ( void );
extern UINT32 ATVChipID(void);

void FMDrv_PowerOnReset(void)
{
	//UINT32 id; //kai fix build warning
	if(_is_fm_on)
	  return;
	// disable Sleep mode  
	if (bIsSleepHandleInit == 0)
	{
		slp_handle = L1SM_GetHandle ();
		bIsSleepHandleInit = true;
	}
	L1SM_SleepDisable(slp_handle);  
	kal_sleep_task(kal_milli_secs_to_ticks(20)); // need delay 20ms before MT5192 power-on  

	kal_take_sem(matv_sem_id, KAL_INFINITE_WAIT);
	
	if(matvdrv_poweron_seq(0))
	{
		chip_id=ATVChipID();
		bChipInit(0);
		//chip_valid = true; //kai fix build warning
		_is_fm_on = true;
		vApiFmRdoScanInit();
#if  CUSTOM_MATV_AVC_FM
		DrvSetChipDep(MTK_AUD_AVC,0x30000);
#else
		DrvSetChipDep(MTK_AUD_AVC,0);
#endif		
#ifndef __FMRADIO_I2S_SUPPORT__
        	vApiAudioSetOutputMode(3);
#endif
		kal_prompt_trace(MOD_FMR, "FM Power On");
	}
	else
	{
		//chip_valid = false; //kai fix build warning
	_is_fm_on = false;
		kal_prompt_trace(MOD_FMR, "FM Power On Fail!");
	}
	kal_give_sem(matv_sem_id);
}

void FMDrv_PowerOffProc(void)
{
	kal_take_sem(matv_sem_id, KAL_INFINITE_WAIT);
	bChipShutdown();
	matvdrv_poweroff_seq();
	_is_fm_on = false;
	kal_give_sem(matv_sem_id);	
	kal_prompt_trace(MOD_FMR, "FM Power Off");
	//fm_stop_timer(FM_MLoop_CHECK_TIMER);
	
	// enable Sleep mode 
	if (bIsSleepHandleInit == 0)
	{
		slp_handle = L1SM_GetHandle ();
		bIsSleepHandleInit = true;
	}	 
	L1SM_SleepEnable(slp_handle);  	

	#if (defined(MT6223P)||defined(MT6223))	//check in for power saving
		matvdrv_ps_init(1);
	#endif
}

void FMDrv_SetFreq( int16 curf )  /* input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)*/
{
	if(!_is_fm_on)
	  FMDrv_PowerOnReset();
	FMDrv_Mute(1);  
	kal_take_sem(matv_sem_id, KAL_INFINITE_WAIT);
	vApiAudioStop();
	vApiMT5192_FmRdoSetFreq(curf*100,0);	
	vApiAudioSetChannelSrc(SV_FMRDO);
        vApiFmRdoScanInit();
	kal_give_sem(matv_sem_id);
	FMDrv_Mute(0);
}

uint16 FMDrv_GetSigLvl( int16 curf )
{
	uint16 ret;
	uint32 rssi=0;
	
	kal_take_sem(matv_sem_id, KAL_INFINITE_WAIT);
	//MT5192_FM_SetFreq(curf*100);
	ret=MT5192_FM_GetRSSI(&rssi)?(uint16)rssi:0;
	//vApiAudioSetChannelSrc(SV_FMRDO); 
	kal_give_sem(matv_sem_id);
	return ret;
}

uint16 FMDrv_GetIF( int16 curf)
{
   return 0;
}

void FMDrv_EvaluateRSSIThreshold(void) {
}

extern UINT8 bApiFmRdoScan (UINT32 u4Freq, UINT8 u1IsStepUp, UINT32 u4Step);
#define FMRDO_STEP 100

uint8 FMDrv_ValidStop(int16 freq, int8 signalvl, bool is_step_up)
{
	//uint32 rssi;  //kai fix build warning
	uint8 ret;
	
	MT5192_FM_SetTH (signalvl);
	FMDrv_Mute(1);
	kal_take_sem(matv_sem_id, KAL_INFINITE_WAIT);
#if 1
        vApiAudioSetChannelSrc ((TV_AUD_SYS_T) 0x15); 
	ret= bApiFmRdoScan (freq * FMRDO_STEP, is_step_up, FMRDO_STEP);
#else	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	kal_give_sem(matv_sem_id);
	return ret;
}



void FMDrv_ChipInit(void)
{
	/// power down the chip
	if (bIsSleepHandleInit == 0)
	{
		slp_handle = L1SM_GetHandle ();
		bIsSleepHandleInit = true;
	}
}

bool FMDrv_IsChipValid( void )
{
	/// anything to do?
	return true;
}

uint16 FMDrv_ReadByte(uint8 addr)
{
	return 0;
}

bool FMDrv_WriteByte(uint8 addr, uint16 data)
{
	return true;
}

void FMDrv_SoftMuteOnOff(uint8 On_Off)
{
	kal_take_sem(matv_sem_id, KAL_INFINITE_WAIT);
	AUD_DspSetFmMute(4 /*AUD_ATV_DECODER_FMRDO*/,0 /*AUD_FACTORY_FM_MUTE*/,On_Off);
	kal_give_sem(matv_sem_id);
}

void FMDrv_SoftMuteStage(uint8 stage)
{

}

void FMDrv_StereoBlendStage(uint8 stage)
{
	/* empty*/
	//DANIEL_20091210
	//NA - What's this?
	//DANIEL_20091210	
}

uint8 FMDrv_GetChipID(void)
{
	return chip_id; //0x92;
}

uint8 FMDrv_Get_H_L_side(kal_int16 curf) /* input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)*/
{
	return 0;/* empty*/
}

uint8 FMDrv_Get_stereo_mono(void)
{
	kal_take_sem(matv_sem_id, KAL_INFINITE_WAIT);
	//DANIEL_20091210
	if (dwApiAudioGetFormatSrc()==1 /*FMRDO_MONO*/)
	{
		kal_give_sem(matv_sem_id);
		return 0;	
	}
	else
	{
		kal_give_sem(matv_sem_id);
		return 1;
	}	
}
#endif
#endif
