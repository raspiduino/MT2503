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
 * fm_radio.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      FM Radio Driver
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 *
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
 *
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "kal_public_defs.h"
#include "fm_radio.h"
#include "fmr_common_api.h"
#include "fmr_trc.h"
#include "l1_fh_interface.h" //add
#include "intrCtrl.h" //add
#include "l1audio.h"
#if defined(MT6255FM)
#include "custom_emi_release.h"
#endif
#if defined(__TOUCH_PANEL_CAPACITY__)//FM Desense CTP
#include "dcl.h"
#endif
#include "multiboot_config.h"
#include "fmr_config_customize.h"
#ifdef __FM_RADIO_RDS_SUPPORT__
#include "stack_ltlcom.h"
#include "fmr_main.h"
#include "fm_rds.h"
extern kal_uint16 INT_BootMode(void);
extern kal_bool isRdsOn;
RDS_CallBack pstRDS_Hdlr;
extern RDSData_Struct *pstRDSData;
static kal_uint16 RDS_TA_BackUpFreq;
extern kal_uint16 _BLER_CHK_INTERVAL;
extern kal_uint16 RDS_Sync_Cnt;
extern kal_uint16 RDS_Block_Reset_Cnt;
extern void fm_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg);
extern void fm_stop_timer(kal_uint8 timer_id);
extern void RDS_BlerCheck(void);
extern fm_timer_table_struct fm_timer_table[MAX_NUM_OF_FM_TIMER];
extern kal_bool g_AF_Enable;
extern kal_bool g_TP_Enable;
#endif

extern void AFE_SetHardwareMute(kal_bool mute);

#ifdef __FM_RADIO_HW_SEARCH__
extern kal_uint8 HWSearch_flag;
extern kal_uint16 FreqSt;
#if 0  /*no need to detect since MMI should force stop first*/   
#if defined(MT6251FM)
/* under construction !*/
#else
/* under construction !*/
#endif
#endif
#endif
/*add FM_RADIO_ENABLE compile option in most API because meta can link FMR API even FM disable*/
#if defined(FM_RADIO_ENABLE)
static kal_bool isFmActive;
extern kal_int16 _current_frequency;
#ifndef FMR_RAMP_DOWN_SUPPORT
static kal_bool isSpeakerOn = KAL_FALSE;
#endif
FMR_data *pstFMR_data;
#if 0//defined(MT6256FM)||defined(MT6255FM)
/* under construction !*/
#endif
#if defined(MT6252H) || defined(MT6252)
static kal_bool SpeakerOn = KAL_FALSE;
static kal_uint8 FMR_volume = 0;
static kal_int8 FMR_digital_gain_index = 0;
#if defined(__GAIN_TABLE_SUPPORT__)
static kal_uint32 FMR_gain = 0;
#endif
static kal_bool FMR_volume_update = KAL_TRUE;
#endif
#endif

#if (FMR_ENHANCED_SCAN==1)
static kal_uint16 g_SOFTE_MUTEBitMap[16];
extern kal_uint16 FMDrv_DesenseBitMap[16];
extern kal_uint16 FMR_DESENSE_LEVEL;
//kal_int32 FMR_FalseAlarmRSSI[7] = 
const kal_int16 FMR_FalseAlarmRSSI[7] = 
{
	-272, -258, -245, -232, -218, -205, -192
};

kal_bool All_Channel_Hopping_Set = 0;

#if (FMR_50K_STEP==1)
static kal_uint16 FMR_Seek_CheckValid(kal_int32 Channel, kal_uint16 *ValidFreq,kal_int32 *rRssi,kal_bool direction);
#else
static kal_uint16 FMR_Seek_CheckValid(kal_int32 Channel, kal_uint16 *ValidFreq,kal_int32 *rRssi);
#endif

#endif
#if (defined(FMR_SW_RSSI_SORT))
/*RSSI sort part*/
extern kal_bool Scan_Sort_on;
const kal_uint16 g_BitMap_Masks[16] = 
{
    0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080,
    0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000
};
#if(FMR_ENHANCED_SCAN==0)
static kal_uint16 g_BitMap[16];
static FMR_SCAN_Sort_Data *pScanSortData=NULL;
static kal_bool *FalseFreqSearched=NULL;
#endif
/*SW eliminate*/
extern kal_uint8 FMR_EmptyRSSI[];
extern kal_bool FMR_SWEliminate_on;
extern kal_uint8 FMR_EmptyChannelNum;
extern kal_uint16 g_EmptyChannel[];
#endif
extern void FH_get_FM_frequency_hopping_set_by_calc( int ch_freq, sFHset* _fhset);
#ifdef MT6626
extern kal_uint8 is_shortAntenna;
extern kal_uint8 BtRadio_Power_Handler(kal_uint8 sys, kal_uint8 on, kal_uint8 is_fm_i2s);
#endif
#if (defined(FM_RADIO_ENABLE))
typedef enum
{
	FMR_CQI_RSSI=0,
#if defined(MT6616) || defined(MT6626) || defined(MT6276FM) || defined(MT6255FM) || defined(MT6256FM) || defined(MT6251FM)
	FMR_CQI_PAMD,
#endif	
	FMR_CQI_END
}FMR_CQI_e;
typedef kal_uint16 (*pFMR_CQI_Fuc)(kal_int16 curf);
static const pFMR_CQI_Fuc CQI_FucList[FMR_CQI_END]=
{
	FMDrv_GetSigLvl
#if defined(MT6616) || defined(MT6626) || defined(MT6276FM) || defined(MT6255FM) || defined(MT6256FM) || defined(MT6251FM)
	,FMDrv_GetPamdLvl	
#endif	
};
#endif
void FMR_PowerOn()
{
#if defined(__TOUCH_PANEL_CAPACITY__)//FM Desense CTP
   DCL_HANDLE handle;
   STS_CTRL_SET_DEVICE_T set_device;
#endif
#if (defined(FM_RADIO_ENABLE))
   //kal_trace(TRACE_GROUP_2,FM_API_ENTRANCE,1);
   if(isFmActive == KAL_TRUE)/*FM power protection*/
   {
	   return;
   }
#if defined(__BT_FM_VIA_SCO__) // when FM power on and audio via BT, some noise heared at BT HFP.So keep silence before power on and unmute after tune.
   L1SP_MutePCMOuputPort(KAL_TRUE);    
#endif   
   isFmActive = KAL_TRUE;
#if !defined(IC_MODULE_TEST)
   ktLock();
#endif   
   pstFMR_data = (FMR_data*)get_ctrl_buffer( sizeof(FMR_data) );
#ifdef __FM_RADIO_RDS_SUPPORT__
   //pstRDS_Hdlr = (RDS_Hdlr*)get_ctrl_buffer( sizeof(RDS_Hdlr) );
   isRdsOn = KAL_FALSE;
#endif
   FMDrv_PowerOnReset();
   pstFMR_data->is_searching = KAL_FALSE;
#if !defined(IC_MODULE_TEST)
   L1D_FH_FM_TurnOn( KAL_TRUE );
#if defined( __FMRADIO_I2S_SUPPORT__ )
	if(!I2S_is_I2S_open())
	{
		I2SIN_MuteSpeaker(KAL_TRUE); //to solve pop noise when powering on FM 
		FM_I2S_Open();
		kal_sleep_task(23);
		I2SIN_MuteSpeaker(KAL_FALSE); //to solve pop noise when powering on FM 
#ifndef FMR_RAMP_DOWN_SUPPORT
		isSpeakerOn = KAL_TRUE;    
#endif		
		// isPowerOn = KAL_TRUE;
		kal_sleep_task(4);//for unmute speaker stable
   }
#endif
#if defined(__TOUCH_PANEL_CAPACITY__)
   handle=DclSTS_Open(DCL_TS,0);
   set_device.mode = DCL_CTP_FM_ENABLE;  // set_device.mode = DCL_CTP_FM_DISABLE;
   DclSTS_Control(handle,STS_CMD_SET_DEVICE,(DCL_CTRL_DATA_T *)&set_device);
   DclSTS_Close(handle);
#endif
#endif
	kal_trace(TRACE_GROUP_2,FM_API_EXIT,1);
#endif
}

void FMR_PowerOff()
{
#if defined(__TOUCH_PANEL_CAPACITY__)
   DCL_HANDLE handle;
   STS_CTRL_SET_DEVICE_T set_device;
#endif
#if (defined(FM_RADIO_ENABLE))
//	kal_trace(TRACE_GROUP_2,FM_API_ENTRANCE,2);
	if(isFmActive == KAL_FALSE)/*FM power protection*/
	{
		return;
	}
	while(pstFMR_data->is_searching)/*avoid next fast power on issue*/
	{
		pstFMR_data->bHWsearchStop = KAL_TRUE;
		kal_sleep_task(5);
	}
#if defined(MT6252H) || defined(MT6252)
   SpeakerOn = KAL_FALSE;
#endif
#ifdef __FM_RADIO_RDS_SUPPORT__
	if(isRdsOn)
	{
		FMR_RDS_OnOff(KAL_FALSE);
	}
#endif

    isFmActive = KAL_FALSE;
  AFE_SetHardwareMute(KAL_TRUE); 
	FMDrv_PowerOffProc();
	
#if defined( __FMRADIO_I2S_SUPPORT__ )
	I2SIN_TurnOffSpeaker();
	FM_I2S_Close();
#else
	LINEIN_Close();
#endif
  AFE_SetHardwareMute(KAL_FALSE);
#ifndef FMR_RAMP_DOWN_SUPPORT
	isSpeakerOn = KAL_FALSE;
#if defined(__BT_FM_VIA_SCO__) // to flush some silence for BT eSCO.
   kal_sleep_task(10);
#endif
#endif

#ifdef __FM_RADIO_RDS_SUPPORT__
   //free_ctrl_buffer(pstRDS_Hdlr);
   pstRDS_Hdlr = (RDS_CallBack)0;
   isRdsOn = KAL_FALSE;
#endif
   ktUnlock();
   free_ctrl_buffer(pstFMR_data);
   pstFMR_data = (FMR_data *)0;
   L1D_FH_FM_TurnOn( KAL_FALSE );
/*
#if defined( __FMRADIO_I2S_SUPPORT__ )
	I2SIN_TurnOffSpeaker();
	FM_I2S_Close();
#else
	LINEIN_Close();
#endif
*/
#if defined(__TOUCH_PANEL_CAPACITY__)
   handle=DclSTS_Open(DCL_TS,0);
   set_device.mode = DCL_CTP_FM_DISABLE;
   DclSTS_Control(handle,STS_CMD_SET_DEVICE,(DCL_CTRL_DATA_T *)&set_device);
   DclSTS_Close(handle);
#endif
#if 0//defined(MT6256FM)||defined(MT6255FM)
/* under construction !*/
#endif
#if defined(__BT_FM_VIA_SCO__) // when FM power on and audio via BT, some noise heared at BT HFP.So keep silence before power on and unmute after tune.
	L1SP_MutePCMOuputPort(KAL_FALSE);	
#endif   
	kal_trace(TRACE_GROUP_2,FM_API_EXIT,2);
#endif
}
#if (FMR_ENHANCED_SCAN==1)
void FMR_MergeDesenseBitMap()
{
	kal_uint32 i,temp;
	if(FMR_EmptyChannelNum>0)
	{
		for(i=0; i<FMR_EmptyChannelNum; i++)
		{
			temp = g_EmptyChannel[i] - 875;
			FMDrv_DesenseBitMap[temp/16] |= g_BitMap_Masks[temp%16];
		}
	}
}
/*return TRUE: is desense freq*/
kal_bool FMR_DensenseDetect(kal_int32 i,kal_int32 rRSSI)
{
	if((FMDrv_DesenseBitMap[i/16]>>(i%16))&0x0001)/*desense list*/
	{
		FMR_DESENSE_LEVEL = (FMR_DESENSE_LEVEL > 6) ? 6 : FMR_DESENSE_LEVEL;
		if(rRSSI<FMR_FalseAlarmRSSI[FMR_DESENSE_LEVEL])
		{
			return KAL_TRUE;
		}
	}
	return KAL_FALSE;
}
#if (FMR_NOISE_FLOORT_DETECT==1)
/*return TRUE:get noise floor freq*/
kal_bool FMR_NoiseFloorDetect(kal_bool *rF,kal_int32 rssi,kal_int32 *F_rssi)
{
	if(rF[0]==KAL_TRUE)
	{
		if(rF[1]==KAL_TRUE)
		{
			F_rssi[2]=rssi;
			rF[2]=KAL_TRUE;
			return KAL_TRUE;
		}
		else
		{
			F_rssi[1]=rssi;
			rF[1]=KAL_TRUE;
		}
	}
	else
	{
		F_rssi[0]=rssi;
		rF[0]=KAL_TRUE;
	}
	return KAL_FALSE;
}
#endif
void FMR_SoftMuteScan(void)
{
	kal_int32 i,j,RSSI,temp;
	kal_uint16 ChannelNo=0,Num=0;
#ifdef __COSMOS_MMI__
	kal_uint16 maxNum=20;
#else
	kal_uint16 maxNum=30;
#endif
	FMR_SOFTE_MUTE_SCAN_Data *pSortData=NULL;
	kal_bool LastExist=KAL_FALSE/*,Neighbor_Flag=KAL_FALSE*/;
#if (FMR_NOISE_FLOORT_DETECT==1)
	kal_int32 Pacc=0,Nacc=0;
	extern kal_int32 FMR_RSSI_LANTTH;
	extern kal_int32 FMR_Noise_Offset;
	kal_int32 NF=0;
	kal_bool F[3]={KAL_FALSE,KAL_FALSE,KAL_FALSE};
	kal_int32 F_Rssi[3]={0};
	kal_uint8 NF_Idx=0;
#endif

	FMR_MergeDesenseBitMap();
	kal_mem_set(g_SOFTE_MUTEBitMap,0x0,sizeof(g_SOFTE_MUTEBitMap));
	pSortData = (FMR_SOFTE_MUTE_SCAN_Data *)get_ctrl_buffer((sizeof(FMR_SOFTE_MUTE_SCAN_Data)* ((FM_RADIO_CHANNEL_NUMBER+1)/2)));/*max channel num=(1080-875+1)/2*/
	FMDrv_PresetScan();
	/*get bit mapfor Polit check*/
	for (i = 0; i < FM_RADIO_CHANNEL_NUMBER; i++)
	{
		ChannelNo = i+FM_RADIO_MIN_FREQ;
		//if(Neighbor_Flag==KAL_TRUE)/*bypass neighbor channel*/
		/*{
			Neighbor_Flag=KAL_FALSE;
			continue;
		}*/
		if(pstFMR_data->bHWsearchStop)
		{
			free_ctrl_buffer(pSortData);
			FMDrv_RestorePresetScan();
			return;
		}
		if(FMDrv_GetSofteMute(ChannelNo,&RSSI)==KAL_TRUE)
		{
#if (FMR_NOISE_FLOORT_DETECT==1)
			kal_mem_set(F,KAL_FALSE,sizeof(F));
#endif
			if(FMR_DensenseDetect(i,RSSI)==KAL_TRUE)
			{
				//kal_prompt_trace(MOD_FMR,"desense channel[%d]",ChannelNo);
				kal_trace(TRACE_INFO,FM_INFO_DENSENSE_CHANNEL,ChannelNo,0);
				LastExist=KAL_FALSE;
				continue;
			}
			if(LastExist==KAL_TRUE)	/*neighbor channel*/
			{
				if(RSSI>pSortData[Num-1].RSSI)/*save current freq and cover last channel*/
				{
					if(FMDrv_SevereDensense(ChannelNo,RSSI)==KAL_TRUE)
					{
						LastExist=KAL_FALSE;
						continue;
					}
					pSortData[Num-1].ChannelNo=ChannelNo;
					pSortData[Num-1].RSSI=RSSI;
				}
				else/*ignore current freq*/
				{
					LastExist=KAL_FALSE;
					continue;
				}
			}
			else/*save current*/
			{
				if(FMDrv_SevereDensense(ChannelNo,RSSI)==KAL_TRUE)
				{
					LastExist=KAL_FALSE;
					continue;
				}
				pSortData[Num].ChannelNo=ChannelNo;
				pSortData[Num].RSSI=RSSI;
				Num++;
				LastExist=KAL_TRUE;
				//kal_prompt_trace(MOD_FMR,"Num++%d",Num);
			}
		}
		else
		{
#if (FMR_NOISE_FLOORT_DETECT==1)
			if(FMR_DensenseDetect(i,RSSI)==KAL_FALSE)
			{
				if(FMR_NoiseFloorDetect(F,RSSI,F_Rssi)==KAL_TRUE)
				{
					Pacc+=F_Rssi[1];
					Nacc++;
					/*check next freq*/
					F[0]=F[1];
					F_Rssi[0]=F_Rssi[1];
					F[1]=F[2];
					F_Rssi[1]=F_Rssi[2];
					F[2]=KAL_FALSE;
					F_Rssi[2]=0;
					//kal_trace(TRACE_INFO,FM_INFO_NOISE_FLOOR,Pacc,Nacc);
				}
			}
			else
			{
				kal_mem_set(F,KAL_FALSE,sizeof(F));
			}
#endif			
			LastExist=KAL_FALSE;
		}
#if (FMR_NOISE_FLOORT_DETECT==1)
		if(((i%41)==0)&&(i!=0))
		{
			if(Nacc>0)
			{
				NF=Pacc/Nacc;
			}
			else
			{
				NF=FMR_RSSI_LANTTH-FMR_Noise_Offset;
			}
			Pacc=0;
			Nacc=0;
			for(j=NF_Idx; j<Num; j++)
			{
				if(pSortData[j].RSSI<(NF+FMR_Noise_Offset))
				{
					kal_trace(TRACE_INFO,FM_INFO_NOISE_FLOOR_DETECT,pSortData[j].ChannelNo,NF);
					pSortData[j].ChannelNo=0;
					pSortData[j].RSSI=-1000;
				}
			}
			NF_Idx=j;
			//kal_prompt_trace(MOD_FMR,"NF_Idx[%d]",NF_Idx);
		}
#endif		
	}
	//kal_prompt_trace(MOD_FMR,"get channel no.[%d]",Num);
	if(Num==0)/*get nothing*/
	{
		free_ctrl_buffer(pSortData);
		FMDrv_RestorePresetScan();
		return;
	}
	for(i=0; i<Num; i++)//debug
	{
		kal_trace(TRACE_INFO,FM_INFO_SCAN_CHANNEL_NUM,i,pSortData[i].ChannelNo);
	}
#ifdef FMR_SW_RSSI_SORT	
    if((Scan_Sort_on == KAL_TRUE)&&(INT_BootMode() == MTK_NORMAL_MODE))
    {
		if(Num > maxNum)/*sort*/
		{
			for(i=Num-1; i>0; i--)
			{
				for(j=0; j<i; j++)
				{
					if(pSortData[j].RSSI < pSortData[j+1].RSSI)
					{
						temp = pSortData[j].RSSI;
						pSortData[j].RSSI = pSortData[j+1].RSSI;
						pSortData[j+1].RSSI = temp;
						temp = pSortData[j].ChannelNo;
						pSortData[j].ChannelNo = pSortData[j+1].ChannelNo;
						pSortData[j+1].ChannelNo = temp;					
					}
				}
			}
			Num=maxNum;
		}
    }
#endif	
	for(i=0; i<Num; i++)//channle no. to bit
	{
		temp = pSortData[i].ChannelNo - FM_RADIO_MIN_FREQ;
		if(temp >= 0)
		{
			g_SOFTE_MUTEBitMap[temp/16] |= g_BitMap_Masks[temp%16];
		}
	}
	
	FMDrv_RestorePresetScan();
	free_ctrl_buffer(pSortData);
    return;
}

#if (FMR_50K_STEP==1)
kal_bool FMR_50K_DensenseDetect(kal_uint16 freq,kal_int32 rRSSI)
{
	const kal_uint16 List[]={9215};
	kal_int32 i;
	for(i=0;i<1;i++)
	{
		if(freq==List[i])
		{
			if(rRSSI<FMR_FalseAlarmRSSI[FMR_DESENSE_LEVEL])
			{
				kal_trace(TRACE_INFO,FM_INFO_DENSENSE_CHANNEL,freq,1);
				return KAL_TRUE;
			}
		}
	}
	return KAL_FALSE;
}

kal_bool FMR_SoftMuteSeek(kal_uint16 *ValidFreq,kal_int32 *rRssi)
{
	kal_int32 i;
	kal_uint16 ReturnVal;
	kal_uint32 Total_Channel = 206, Divider = 10;

	FMR_MergeDesenseBitMap();
	FMDrv_PresetScan();
	FMDrv_GetSeekOrigFreq(ValidFreq);

	if(pstFMR_data->wSpace==1)		//100k
	{
		Total_Channel = 206;
		Divider = 10;
	}
	else if(pstFMR_data->wSpace==2)	//50k
	{
		Total_Channel = 411;
		Divider = 5;
	}
	else							//200k
	{
		Total_Channel = 103;
		Divider = 20;
	}
	
	if(pstFMR_data->is_up==KAL_TRUE)/*forward*/
	{
		for (i=((*ValidFreq-8750)/Divider+1); i<Total_Channel; i++)
		{
			ReturnVal = FMR_Seek_CheckValid(i*Divider, ValidFreq, rRssi, KAL_TRUE);
			
			if(ReturnVal == 0)
				return KAL_FALSE;
			else if(ReturnVal == 1)
				return KAL_TRUE;
		}
		for (i=0; i<((*ValidFreq-8750)/Divider); i++)
		{
			ReturnVal = FMR_Seek_CheckValid(i*Divider, ValidFreq, rRssi, KAL_TRUE);
			
			if(ReturnVal == 0)
				return KAL_FALSE;
			else if(ReturnVal == 1)
				return KAL_TRUE;
		}
	}
	else/*backward*/
	{
		for (i=((*ValidFreq-8750)/Divider-1); i>=0; i--)
		{
			ReturnVal = FMR_Seek_CheckValid(i*Divider, ValidFreq, rRssi, KAL_FALSE);
			
			if(ReturnVal == 0)
				return KAL_FALSE;
			else if(ReturnVal == 1)
				return KAL_TRUE;
		}
		for (i=Total_Channel-1; i>((*ValidFreq-8750)/Divider); i--)
		{
			ReturnVal = FMR_Seek_CheckValid(i*Divider, ValidFreq, rRssi, KAL_FALSE);
			
			if(ReturnVal == 0)
				return KAL_FALSE;
			else if(ReturnVal == 1)
				return KAL_TRUE;
		}
	}
	/*seek fail, return orginal freq*/
	//FMDrv_GetSeekOrigFreq(ValidFreq);
	*rRssi=0;
	FMDrv_RestorePresetScan();
	return KAL_TRUE;
}

kal_uint16 FMR_Seek_CheckValid(kal_int32 Channel, kal_uint16 *ValidFreq,kal_int32 *rRssi, kal_bool direction)
{
	kal_uint16 Freq = 0; 
	kal_int32 temp_RSSI = 0, temp_Channel = 0;
	kal_uint16 temp_Freq = 0;
	
	Freq = Channel + 8750;
	if(pstFMR_data->bHWsearchStop)
	{
		FMDrv_RestorePresetScan();
		return 0;
	}
	if(FMDrv_GetSofteMute(Freq,rRssi)==KAL_TRUE)/*valid*/
	{
		if((Freq%10)==0)//100k
		{
			if(FMR_DensenseDetect(Channel/10,*rRssi)==KAL_TRUE)
			{
				return 2;
			}
		}
		else			//50k
		{
			if(FMR_50K_DensenseDetect(Freq,*rRssi)==KAL_TRUE)
			{
				return 2;
			}
		}
		if(FMDrv_SevereDensense(Freq,*rRssi)==KAL_TRUE)
		{
			return 2;
		}

		if(direction && (Freq < 10800))
		{
			if(pstFMR_data->wSpace==1)	//100k
			{
				temp_Freq = Freq + 10;
				temp_Channel = Channel + 10;
			}
			else if(pstFMR_data->wSpace==2)	//50k
			{
				temp_Freq = Freq + 5;
			}
		}
		else if((!direction) && (Freq > 8750))
		{
			if(pstFMR_data->wSpace==1)	//100k
			{
				temp_Freq = Freq - 10;
				temp_Channel = Channel - 10;
			}
			else if(pstFMR_data->wSpace==2) //50k
			{
				temp_Freq = Freq - 5;
			}
		}
		else
		{
			FMDrv_RestorePresetScan();
			*ValidFreq = Freq;
			return 1;
		}

		if(FMDrv_GetSofteMute(temp_Freq,&temp_RSSI)==KAL_TRUE)/*valid*/
		{
			if((temp_Freq%10)==0)	//100k
			{
				if(FMR_DensenseDetect(temp_Channel/10,temp_RSSI)==KAL_FALSE)
					if(FMDrv_SevereDensense(temp_Freq,temp_RSSI)==KAL_FALSE)
					{
						if(temp_RSSI > *rRssi)
							return 2;
					}
			}
			else	//50k
			{
				if(FMR_50K_DensenseDetect(temp_Freq,temp_RSSI)==KAL_FALSE)
					if(FMDrv_SevereDensense(temp_Freq,temp_RSSI)==KAL_FALSE)
					{
						if(temp_RSSI > *rRssi)
							return 2;
					}
			}
		}
		
		FMDrv_RestorePresetScan();
		*ValidFreq = Freq;
		return 1;
	}
	else	
		return 2;
}
#else
kal_bool FMR_SoftMuteSeek(kal_uint16 *ValidFreq,kal_int32 *rRssi)
{
	kal_int32 i;
	kal_uint16 ReturnVal;

	FMR_MergeDesenseBitMap();
	FMDrv_PresetScan();
	FMDrv_GetSeekOrigFreq(ValidFreq);
	if(pstFMR_data->is_up==KAL_TRUE)/*forward*/
	{
		for (i=(*ValidFreq-875+1); i<206; i++)
		{
			ReturnVal = FMR_Seek_CheckValid(i, ValidFreq, rRssi);
			
			if(ReturnVal == 0)
				return KAL_FALSE;
			else if(ReturnVal == 1)
				return KAL_TRUE;
			}
		for (i=0; i<(*ValidFreq-875); i++)
		{
			ReturnVal = FMR_Seek_CheckValid(i, ValidFreq, rRssi);
			
			if(ReturnVal == 0)
				return KAL_FALSE;
			else if(ReturnVal == 1)
				return KAL_TRUE;
			}
		}
	else/*backward*/
	{
		for (i=(*ValidFreq-875-1); i>=0; i--)
		{
			ReturnVal = FMR_Seek_CheckValid(i, ValidFreq, rRssi);
			
			if(ReturnVal == 0)
				return KAL_FALSE;
			else if(ReturnVal == 1)
				return KAL_TRUE;
			}
		for (i=205; i>(*ValidFreq-875); i--)
				{
			ReturnVal = FMR_Seek_CheckValid(i, ValidFreq, rRssi);
			
			if(ReturnVal == 0)
				return KAL_FALSE;
			else if(ReturnVal == 1)
				return KAL_TRUE;
				}
				}
	/*seek fail, return orginal freq*/
	//FMDrv_GetSeekOrigFreq(ValidFreq);
	*rRssi=0;
				FMDrv_RestorePresetScan();
				return KAL_TRUE;
			}

kal_uint16 FMR_Seek_CheckValid(kal_int32 Channel, kal_uint16 *ValidFreq,kal_int32 *rRssi)
		{
	kal_uint16 Freq; 
	
	Freq = Channel + 875;
			if(pstFMR_data->bHWsearchStop)
			{
				FMDrv_RestorePresetScan();
		return 0;
			}
	if(FMDrv_GetSofteMute(Freq,rRssi)==KAL_TRUE)/*valid*/
			{
		if(FMR_DensenseDetect(Channel,*rRssi)==KAL_TRUE)
				{
			return 2;
				}
		if(FMDrv_SevereDensense(Freq,*rRssi)==KAL_TRUE)
				{
			return 2;
				}
				FMDrv_RestorePresetScan();
		*ValidFreq = Freq;
		return 1;
	}
	else	
		return 2;
}

#endif
#endif

void FMR_PollHWSearch( void *data )
{
#ifdef __FM_RADIO_HW_SEARCH__
#if (FMR_ENHANCED_SCAN==0)
    kal_uint8 stop,is_valid;
    kal_uint16 wCurf,SignalLv;
#if (defined(FMR_SW_RSSI_SORT))
	ilm_struct *fmr_ilm;
#endif
#else
	kal_int32 RSSI;
	kal_uint16 wCurf;
#if (defined(__FM_RADIO_RDS_SUPPORT__))
	kal_bool RDSOn=isRdsOn;
#endif
#endif

	kal_trace(TRACE_GROUP_2,FM_API_ENTRANCE,5);
	if(pstFMR_data == NULL)
	{
		return;
	}
#if (FMR_ENHANCED_SCAN==1)
#if (FMR_50K_STEP==1)
	wCurf=10800;
#else
	wCurf=1080;
#endif
	RSSI=0;
#if (defined(__FM_RADIO_RDS_SUPPORT__))
	if(RDSOn)
	{
		RDS_Disable();
	}
#endif
	if(pstFMR_data->is_preset)
	{
		FMR_SoftMuteScan();
	}
	else
	{
		FMR_SoftMuteSeek(&wCurf,&RSSI);
		kal_trace(TRACE_INFO, FM_INFO_FM_HW_SEARCH_E, wCurf);
	}
	pstFMR_data->is_searching = KAL_FALSE;
#if (defined(__FM_RADIO_RDS_SUPPORT__))
	if(RDSOn)
	{
		RDS_Enable();
	}
#endif
	if(pstFMR_data->bHWsearchStop)
	{
		return;
	}
	pstFMR_data->callback(wCurf,RSSI,KAL_TRUE);
#else
#if (defined(MT6616)&&defined(FM_INTERFACE_HCI))	
 	while(1)
#endif		
    {
      // polling
        stop = FMDrv_HWSpolling(&wCurf, &is_valid);
        kal_trace(TRACE_INFO, FM_INFO_FM_HW_SEARCH_E, wCurf);
#if 0  /*no need to detect since MMI should force stop first*/   
/* under construction !*/
/* under construction !*/
#ifndef INTERNAL_ANTENNAL_SUPPORT
#if defined(MT6251FM)
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if (defined(__FM_RADIO_RDS_SUPPORT__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif		
        if(pstFMR_data != NULL)
        {
            if(pstFMR_data->bHWsearchStop)
            {
      	        pstFMR_data->is_searching = KAL_FALSE;
#if (defined(__FM_RADIO_RDS_SUPPORT__))
                if(isRdsOn)
                {
                    RDS_Init_Data();
                    RDS_INTR_Enable();
                }
#endif
                return;
            }
            if (stop)
            {
//#if defined(FM_INTERFACE_HCI)
		        SignalLv = 255;/*not referenced*/
//#else
//      	        SignalLv = (kal_uint8)FMDrv_GetSigLvl(wCurf);
//#endif
	            if(pstFMR_data != NULL)
	            {
#if (defined(FMR_SW_RSSI_SORT))
					//RSSI sorting
					if(((Scan_Sort_on == KAL_TRUE)|| (FMR_SWEliminate_on == KAL_TRUE))
						&&(pstFMR_data->is_preset == KAL_TRUE))
					{
						FMR_SCAN_Sort();
						if(pstFMR_data->bHWsearchStop)
						{
							pstFMR_data->is_searching = KAL_FALSE;
#if (defined(__FM_RADIO_RDS_SUPPORT__))
							if(isRdsOn)
							{
								RDS_Init_Data();
								RDS_INTR_Enable();
							}
#endif
							return;
						}
					}
					/*SW seek eliminate*/
					if(pstFMR_data->is_preset == KAL_FALSE)
					{
						if(FMR_Seek_Eliminate(wCurf) == KAL_TRUE)
						{
							FMDrv_HWSearch(wCurf, pstFMR_data->is_up, pstFMR_data->wSpace, pstFMR_data->is_preset);
							fmr_ilm = allocate_ilm(MOD_FMR);
							fmr_ilm->msg_id = MSG_ID_FMR_HWSEARCH_IND;
							fmr_ilm->local_para_ptr = NULL;
							fmr_ilm->peer_buff_ptr = NULL;
							fmr_ilm->dest_mod_id = MOD_FMR;
							fmr_ilm->src_mod_id = MOD_FMR;
							fmr_ilm->sap_id = FMR_SAP;
							msg_send_ext_queue(fmr_ilm);							 
							return;
						}
						if(FMR_EmptyChannelNum>0)
						{
							free_ctrl_buffer(FalseFreqSearched);
						}
					}
#endif
	                pstFMR_data->is_searching = KAL_FALSE;
      	            if (is_valid == 1)
      	            {
         	            pstFMR_data->callback( wCurf, SignalLv, KAL_TRUE );
      	            }
                    else
                    {
         	            pstFMR_data->callback( wCurf, SignalLv, KAL_FALSE );
                    }
	            }
#if (defined(__FM_RADIO_RDS_SUPPORT__))
                if(isRdsOn)
                {
                    RDS_Init_Data();
                    RDS_INTR_Enable();
                }
#endif
				kal_trace(TRACE_GROUP_2,FM_API_EXIT,5);
                return;
            }
#if (defined(MT6616)&&defined(FM_INTERFACE_HCI))	
            else
            {
                kal_sleep_task(10);
            }
#endif			
        }
        else
        {
			kal_trace(TRACE_GROUP_2,FM_API_EXIT,50);
      	    return;
        }
    }
#endif
#endif
}
#if (defined(FMR_SW_RSSI_SORT)&&(FMR_ENHANCED_SCAN==0))
void FMR_SCAN_Sort(void)
{
    kal_uint16 BitTbl_Ori[16],temp;
    kal_uint8 ChannelNum = 0;/* EmptyNum=0,*/
	kal_int32 i,j;
	//kal_uint16 *p_EmptyChannel=NULL;
#if (defined(MT6250FM) || defined(MT6260FM) || defined(MT6261FM))
	kal_bool Neighbor_Flag=KAL_FALSE;
#endif
	FMR_SCAN_Sort_Data ChannelTemp;
#ifdef __COSMOS_MMI__
	kal_uint8 maxNum=20;
#else
	kal_uint8 maxNum=30;
#endif
	//kal_trace(TRACE_GROUP_2,FM_API_ENTRANCE,6);

    //kal_mem_set(BitTbl_Ori,0x0,sizeof(BitTbl_Ori));
    if (!FMR_GetScanTbl_Internal(BitTbl_Ori))
    {
        return;
    }
	if (INT_BootMode() != MTK_NORMAL_MODE )/*disable sorting under other mode*/
	{
		kal_mem_cpy(g_BitMap,BitTbl_Ori,sizeof(BitTbl_Ori));
		return;
	}
    for (i = 0; i < 206; i++)//get channel numbert
    {
		if (BitTbl_Ori[i/16] & g_BitMap_Masks[i%16])
		{
			ChannelNum++;
		}
    }
	if(ChannelNum == 0)
	{
		return;
	}
	//if((FMR_SWEliminate_on == KAL_TRUE)&& (FMR_EmptyChannelNum > 0))/*allocate false channel*/
	/*{
		p_EmptyChannel = (kal_uint16 *)get_ctrl_buffer((sizeof(kal_uint16)* FMR_EmptyChannelNum));
		kal_mem_set(p_EmptyChannel,0x0,(sizeof(kal_uint16)* FMR_EmptyChannelNum));
	}*/
#if (defined(MT6250FM) || defined(MT6260FM) || defined(MT6261FM))
	//if((ChannelNum > maxNum)||(FMR_SWEliminate_on == KAL_TRUE))/*adjacent channel check must get cqi*/
	{
		pScanSortData = (FMR_SCAN_Sort_Data *)get_ctrl_buffer((sizeof(FMR_SCAN_Sort_Data)* ChannelNum));
		kal_mem_set(pScanSortData,0x0,(sizeof(FMR_SCAN_Sort_Data)* ChannelNum));
		temp = FMDrv_SCAN_Sort_Tune(pScanSortData,ChannelNum);/*get rssi*/
		if(temp == KAL_FALSE)/*scan abort*/
		{
			free_ctrl_buffer(pScanSortData);
			kal_trace(TRACE_GROUP_2,FM_API_EXIT,61);
			return;
		}
		/*adjacent channel check*/
		Neighbor_Flag=KAL_FALSE;
		for (i = 0; i < 205; i++)
		{
			if ((BitTbl_Ori[i/16]&g_BitMap_Masks[i%16])&&(BitTbl_Ori[(i+1)/16]&g_BitMap_Masks[(i+1)%16]))
			{
				if(Neighbor_Flag==KAL_TRUE)/*bypass neighbor channel*/
				{
					pScanSortData[i].skip=KAL_TRUE;
					pScanSortData[i].RSSI = 0;
					Neighbor_Flag=KAL_FALSE;
					i++;
					continue;
				}
				if(pScanSortData[i].RSSI < pScanSortData[i+1].RSSI)/*save i+1*/
				{
					pScanSortData[i].skip=KAL_TRUE;
					pScanSortData[i].RSSI = 0;
					//kal_prompt_trace(MOD_FMR,"save i+1");
					Neighbor_Flag=KAL_TRUE;
				}
				else/*save i*/
				{
					pScanSortData[i+1].skip=KAL_TRUE;
					pScanSortData[i+1].RSSI = 0;
					i++;
				}
			}
			else
			{
				Neighbor_Flag=KAL_FALSE;
			}
		}
		
		if((FMR_SWEliminate_on == KAL_TRUE)&&(FMR_EmptyChannelNum > 0))/*SW eliminate*/
		{
			for(i=0; i<maxNum; i++)
			{
				for(j=0; j<FMR_EmptyChannelNum; j++)
				{
					if(pScanSortData[i].ChannelNo == g_EmptyChannel[j])
					{
						if(pScanSortData[i].RSSI < FMR_EmptyRSSI[j])
						{
							pScanSortData[i].skip = KAL_TRUE;
							pScanSortData[i].RSSI = 0;
						}
					}
				}
			}
		}
		if(ChannelNum > maxNum)/*start sort */
		{
			//sorting
			for(i=ChannelNum-1; i>0; i--)
			{
				for(j=0; j<i; j++)
				{
					if(pScanSortData[j].RSSI < pScanSortData[j+1].RSSI)
					{
						kal_mem_cpy(&ChannelTemp,&pScanSortData[j],sizeof(FMR_SCAN_Sort_Data));
						kal_mem_cpy(&pScanSortData[j],&pScanSortData[j+1],sizeof(FMR_SCAN_Sort_Data));
						kal_mem_cpy(&pScanSortData[j+1],&ChannelTemp,sizeof(FMR_SCAN_Sort_Data));
					}
				}
			}
		}
	}
#else
    if((ChannelNum > maxNum)||(FMR_SWEliminate_on == KAL_TRUE))/*get channel list*/
    {
        pScanSortData = (FMR_SCAN_Sort_Data *)get_ctrl_buffer((sizeof(FMR_SCAN_Sort_Data)* ChannelNum));
		kal_mem_set(pScanSortData,0x0,(sizeof(FMR_SCAN_Sort_Data)* ChannelNum));
		ChannelNum = 0;
		for (i = 0; i < 206; i++)
		{
			if (BitTbl_Ori[i/16] & g_BitMap_Masks[i%16])
			{
				pScanSortData[ChannelNum].ChannelNo = i + 875;
				//pScanSortData[ChannelNum].RSSI = 0;
				ChannelNum++;
			}
		}
    }
	if(ChannelNum > maxNum)/*start sort and get rssi info*/
	{
		temp = FMDrv_SCAN_Sort_Tune(pScanSortData,ChannelNum);/*get rssi*/
		if(temp == KAL_FALSE)/*scan abort*/
		{
			free_ctrl_buffer(pScanSortData);
			/*if(p_EmptyChannel != NULL)
			{
				free_ctrl_buffer(p_EmptyChannel);
			}*/
			kal_trace(TRACE_GROUP_2,FM_API_EXIT,61);
			return;
		}
		if((FMR_SWEliminate_on == KAL_TRUE)&&(FMR_EmptyChannelNum > 0))/*SW eliminate*/
		{
			for(i=0; i<maxNum; i++)
			{
				for(j=0; j<FMR_EmptyChannelNum; j++)
				{
					if(pScanSortData[i].ChannelNo == g_EmptyChannel[j])
					{
						if(pScanSortData[i].RSSI < FMR_EmptyRSSI[j])
						{
							pScanSortData[i].skip = KAL_TRUE;
							pScanSortData[i].RSSI = 0;
							//p_EmptyChannel[EmptyNum] = g_EmptyChannel[j];
							//EmptyNum++;
						}
					}
				}
			}
		}
		//sorting
		for(i=ChannelNum-1; i>0; i--)
		{
			for(j=0; j<i; j++)
			{
				if(pScanSortData[j].RSSI < pScanSortData[j+1].RSSI)
				{
					kal_mem_cpy(&ChannelTemp,&pScanSortData[j],sizeof(FMR_SCAN_Sort_Data));
					kal_mem_cpy(&pScanSortData[j],&pScanSortData[j+1],sizeof(FMR_SCAN_Sort_Data));
					kal_mem_cpy(&pScanSortData[j+1],&ChannelTemp,sizeof(FMR_SCAN_Sort_Data));
				}
			}
		}
	}
	else if((FMR_SWEliminate_on == KAL_TRUE)&&(FMR_EmptyChannelNum > 0))/*without sort,only do eliminate*/
	{
		for(i=0; i<ChannelNum; i++)
		{
			if(FMR_Seek_Eliminate(pScanSortData[i].ChannelNo))
			{
				//p_EmptyChannel[EmptyNum] = pScanSortData[i].ChannelNo;
				//EmptyNum++;
				pScanSortData[i].skip = KAL_TRUE;
			}
		}
	}
	else/*no need to sort or eliminate*/
	{
		kal_mem_cpy(g_BitMap,BitTbl_Ori,sizeof(BitTbl_Ori));
		kal_trace(TRACE_GROUP_2,FM_API_EXIT,62);
		return;
	}
#endif	

	if(ChannelNum <= maxNum)
	{
		maxNum = ChannelNum;
	}
    kal_mem_set(g_BitMap,0x0,sizeof(g_BitMap));
    for(i=0; i<maxNum; i++)//channle no. to bit
    {
		/*if((FMR_SWEliminate_on == KAL_TRUE)&&(p_EmptyChannel != NULL))
		{
			for(j=0; j<EmptyNum; j++)
			{
				if(pScanSortData[i].ChannelNo == p_EmptyChannel[j])
				{
					kal_trace(TRACE_INFO,FM_INFO_EMPTY_NO,p_EmptyChannel[j]);
					b_skip = KAL_TRUE;
					break;
				}
			}
			if(b_skip == KAL_TRUE)
			{
				b_skip = KAL_FALSE;
				continue;
			}
		}*/
		if(pScanSortData[i].skip == KAL_FALSE)
		{
			temp = pScanSortData[i].ChannelNo - 875;
			g_BitMap[temp/16] |= g_BitMap_Masks[temp%16];
		}
		else
		{
			kal_prompt_trace(MOD_FMR,"skip %d",pScanSortData[i].ChannelNo);
		}
    }
    free_ctrl_buffer(pScanSortData);
	/*if(p_EmptyChannel != NULL)
	{
		free_ctrl_buffer(p_EmptyChannel);
	}*/
	kal_trace(TRACE_GROUP_2,FM_API_EXIT,6);

    return;
}
/*
*return true: it's false alarm, need to eliminate
*         false: need to save
*/
kal_bool FMR_Seek_Eliminate(kal_uint16 rFreq)
{
	kal_uint32 i;
	kal_bool Eliminate = KAL_FALSE;
	
	kal_trace(TRACE_GROUP_2,FM_API_ENTRANCE,7);
	if(FMR_EmptyChannelNum>0)
	{
		for(i=0; i<FMR_EmptyChannelNum; i++)
		{
			if(g_EmptyChannel[i] == rFreq)
			{
				if(FalseFreqSearched[i] == KAL_FALSE)
				{
					Eliminate = FMDrv_Seek_Eliminate(rFreq,FMR_EmptyRSSI[i]);
					kal_trace(TRACE_INFO,FM_INFO_SeekEliminate,rFreq,Eliminate,i);
					FalseFreqSearched[i] = KAL_TRUE;
				}
				else
				{
					Eliminate = KAL_FALSE;
					kal_trace(TRACE_INFO,FM_INFO_SeekEliminate,rFreq,Eliminate,1000);
					break;
				}
			}
		}
	}
	//kal_trace(TRACE_GROUP_2,FM_API_EXIT,7);
	return Eliminate;
}
#endif
kal_bool FMR_GetScanTbl(kal_uint16 *BitMapData)
{
#if (FMR_ENHANCED_SCAN==1)
	kal_mem_cpy(BitMapData,g_SOFTE_MUTEBitMap,sizeof(g_SOFTE_MUTEBitMap));
	return KAL_TRUE;
#else	
#if (defined(FMR_SW_RSSI_SORT))
	//kal_trace(TRACE_GROUP_2,FM_API_ENTRANCE,8);
    if(Scan_Sort_on == KAL_TRUE)
    {
        kal_mem_cpy(BitMapData,g_BitMap,sizeof(g_BitMap));
		kal_trace(TRACE_GROUP_2,FM_API_EXIT,8);
        return KAL_TRUE;
    }
    else
#endif		
    {
        return FMR_GetScanTbl_Internal(BitMapData);
    }
#endif		
}
#if (FMR_ENHANCED_SCAN==0)
kal_bool FMR_GetScanTbl_Internal(kal_uint16 *BitMap)
{
#ifdef __FM_RADIO_HW_SCAN__
	kal_uint8 offset;

//	kal_trace(TRACE_GROUP_2,FM_API_ENTRANCE,9);
#if	((!defined(MT6250FM)) && (!defined(MT6260FM)) && (!defined(MT6261FM)))
	if (HWSearch_flag != 0)
#endif		
	{
    	for(offset=0; offset<16; offset++)
    	{
    		FMDrv_GetScanTbl(BitMap, offset);
    	}
		kal_trace(TRACE_GROUP_2,FM_API_EXIT,9);
		return KAL_TRUE;
    }
#if	((!defined(MT6250FM)) && (!defined(MT6260FM)) && (!defined(MT6261FM)))
	else
	{
		return KAL_FALSE;
	}
#endif		
#else
    return KAL_FALSE;
#endif
}
#endif
void FMR_ChkSearchStop(void)
{
#ifdef __FM_RADIO_HW_SEARCH__
	//kal_trace(TRACE_GROUP_2,FM_API_ENTRANCE,10);
    if(pstFMR_data != NULL)
    {
        FMR_PollHWSearch(NULL);
    }
	kal_trace(TRACE_GROUP_2,FM_API_EXIT,10);
#endif
}
/*
*parameters:
*callback: after HW search finished, search result will return to caller by this function.
*wStartFreq: search start freq
*is_up: seek dircetion, not used in scan,1-->seek up, 0-->seek down
*wSpace:seek or scan step:0:200KHz, 1:100KHz
*is_preset:KAL_FALSE.seek, KAL_TRUE.scan
*/
kal_bool FMR_HWSearch( void (*callback)( kal_int16 wFreq, kal_uint8 wSignal_Lv, kal_bool is_valid ), kal_int16 wStartFreq, kal_bool is_up, kal_int16 wSpace, kal_bool is_preset )
{
#ifdef __FM_RADIO_HW_SEARCH__
	//kal_trace(TRACE_GROUP_2,FM_API_ENTRANCE,4);
    if(pstFMR_data->is_searching)
	{
		return KAL_FALSE;
	}
#if (defined(__FM_RADIO_RDS_SUPPORT__)&&(FMR_ENHANCED_SCAN==0))
    if(isRdsOn)
    {
        RDS_INTR_Disable();
    }
#endif
#if (defined(FMR_SW_RSSI_SORT)&&(FMR_ENHANCED_SCAN==0))
	if((is_preset==KAL_FALSE)&&(FMR_EmptyChannelNum>0))
	{
		FalseFreqSearched = (kal_bool *)get_ctrl_buffer(sizeof(kal_bool)* FMR_EmptyChannelNum);
		kal_mem_set(FalseFreqSearched,0x0,(sizeof(kal_bool)* FMR_EmptyChannelNum));
	}
#endif
	pstFMR_data->bHWsearchStop = KAL_FALSE;
	pstFMR_data->is_searching = KAL_TRUE;	 
	pstFMR_data->is_preset = is_preset;   
	pstFMR_data->callback = callback; 
	pstFMR_data->is_up = is_up; 
	pstFMR_data->wSpace = wSpace; 
	// hw search
	kal_trace(TRACE_INFO, FM_INFO_FM_HW_SEARCH_S, wStartFreq, is_up, wSpace, is_preset);
	FMDrv_HWSearch(wStartFreq, is_up, wSpace, is_preset);

   kal_trace(TRACE_GROUP_2,FM_API_EXIT,4);
   return KAL_TRUE;
#else
	return KAL_FALSE;
#endif
}

void FMR_HWSearchForceStop(void)
{
#if (defined(FM_RADIO_ENABLE))
  //kal_trace(TRACE_GROUP_2,FM_API_ENTRANCE,11);
  if(pstFMR_data != NULL)
   pstFMR_data->bHWsearchStop = KAL_TRUE;
  while(pstFMR_data->is_searching)/*make sure search has stopt*/
  {
	  kal_sleep_task(3);
  }
  #if defined(FM_INTERFACE_HCI)
	FMR_PollHWSearch(NULL);
  #endif
  kal_trace(TRACE_GROUP_2,FM_API_EXIT,11);
#endif
}

 /* signal level range is 0 ~ 15 , 5767 has 16 levels ADC */
kal_uint8 FMR_ValidStop(kal_int16 freq, kal_int8 signalvl, kal_bool is_step_up)
{
#if (defined(FM_RADIO_ENABLE))
#ifndef __FM_RADIO_HW_SEARCH__
    kal_uint8 value = 0;
	//kal_trace(TRACE_GROUP_2,FM_API_ENTRANCE,12);
#if (defined(__FM_RADIO_RDS_SUPPORT__))
    if(isRdsOn)
    {
        RDS_INTR_Disable();
    }
#endif
    L1D_FH_FM_SetFreq( freq );
    value = FMDrv_ValidStop(freq, FM_RADIO_INPUT_LEVEL_THRESHOLD, is_step_up);
#if (defined(__FM_RADIO_RDS_SUPPORT__))
    if(isRdsOn)
    {
        RDS_Init_Data();
        RDS_INTR_Enable();
    }
#endif
	kal_trace(TRACE_GROUP_2,FM_API_EXIT,12);
    return value;
#else
	return 0;
#endif
#else
	return 0;
#endif
}

void FMR_SetFreq( kal_int16 curf ) /* input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)*/
{
	kal_int16 Index;
#if (defined(FM_RADIO_ENABLE))
	//kal_trace(TRACE_GROUP_2,FM_API_ENTRANCE,3);
    if((pstFMR_data->is_searching == KAL_TRUE) && (!pstFMR_data->bHWsearchStop))
    {
        return;
    }

#if 0//defined( __FMRADIO_I2S_SUPPORT__ )
   #if defined(MT6256FM) //don't affect other chips firstly
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
#endif
#if defined( __FMRADIO_I2S_SUPPORT__ )
//   I2SIN_TurnOnSpeaker(); 
#else
  #if defined(MT6252H) || defined(MT6252)
   if(!SpeakerOn) //to reduce electric noises when first powering on
   {
      FMR_volume_update = KAL_FALSE;
      #if defined(__GAIN_TABLE_SUPPORT__)      
      FMR_SetOutputGainControl((FMR_gain & 0x0003FFFF) | 0x04000000); //silence_gain    
      #else
      if (FMR_volume != 0)
      {
         FMR_SetOutputVolume(1, FMR_digital_gain_index);
      }
      #endif
      
      LINEIN_Open();
      kal_sleep_task(55);

      #if defined(__GAIN_TABLE_SUPPORT__)
      FMR_SetOutputGainControl(FMR_gain);
      #else
      FMR_SetOutputVolume(FMR_volume, FMR_digital_gain_index);
      #endif
      FMR_volume_update = KAL_TRUE;
      SpeakerOn = KAL_TRUE; 
   }
  #else
   LINEIN_Open();
  #endif
#endif

#if (defined(__FM_RADIO_RDS_SUPPORT__))
   if(isRdsOn)
   {
       RDS_INTR_Disable();
   }
#endif
#if (defined(MT6250FM))
#if (FMR_50K_STEP==1)
	FM_GET_HOPPING_INDEX(curf/10,&Index);
#else
   FM_GET_HOPPING_INDEX(curf,&Index);
#endif
   L1D_FH_FM_SetFreq(Index);
#elif (defined(MT6260FM) || defined(MT6261FM))
if(!All_Channel_Hopping_Set)
{
#if (FMR_50K_STEP==1)
		FM_GET_HOPPING_INDEX(curf/10,&Index);
#else
	   FM_GET_HOPPING_INDEX(curf,&Index);
#endif
	   L1D_FH_FM_Set_PLL_FreeRunParams(Index,0x40);
}
#elif defined(MT6255FM)
	   if(custom_EMI_QueryFullSpeedClock() == EMI_CLK_166MHZ)
	   {
		   if((curf>=875) && (curf<998))
			   L1D_FH_FM_Set_EPLL_FreeRunParams( 21, 0x76 );   //-1%~-8%
		   else if((curf>=998) && (curf<1035))
			   L1D_FH_FM_Set_EPLL_FreeRunParams( 21, 0x39 );   //-1%~-4.5%
		   else if((curf>=1035) && (curf<1080))
			   L1D_FH_FM_Set_EPLL_FreeRunParams( 48, 0x3a );   //-4.5%~-8%
		   else
			   ;
	   }
#else
   //L1D_FH_FM_SetFreq( curf );
   /*MPLL frequency hopping for FM: start*/ 
   {  sFHset FHset_FM;
      FH_get_FM_frequency_hopping_set_by_calc( curf , &FHset_FM );
      L1D_FH_FM_Set_FHset( FHset_FM );    
   }
   /*MPLL frequency hopping for FM: end*/
#endif   
	FMDrv_SetFreq( curf );
#ifndef FMR_RAMP_DOWN_SUPPORT
   if (KAL_FALSE == isSpeakerOn) 
   {
#if defined( __FMRADIO_I2S_SUPPORT__ )
      I2SIN_MuteSpeaker(KAL_FALSE);
#else
      LINEIN_MuteSpeaker(KAL_FALSE);
#endif
      isSpeakerOn = KAL_TRUE;
   }
#endif
#if (defined(__FM_RADIO_RDS_SUPPORT__))
    if(isRdsOn)
    {
        RDS_INTR_Enable();
    }
#endif
#if defined(__BT_FM_VIA_SCO__) // when FM power on and audio via BT, some noise heared at BT HFP.So keep silence before power on and unmute after tune.
	L1SP_MutePCMOuputPort(KAL_FALSE);	
#endif   
	kal_trace(TRACE_GROUP_2,FM_API_EXIT,3);
#endif
}
#if (defined(FM_RADIO_ENABLE))
kal_uint8 FMR_GetCQI(kal_int16 curf,FMR_CQI_e index)
{
	kal_uint8 temp;
#if (defined(__FM_RADIO_RDS_SUPPORT__))
	if(isRdsOn)
	{
		RDS_INTR_Disable();
	}
#endif	
	temp=CQI_FucList[index](curf);
	//kal_trace(TRACE_INFO, FM_INFO_FM_CQI,curf,index,temp);

#if (defined(__FM_RADIO_RDS_SUPPORT__))
	if(isRdsOn)
	{
	   RDS_INTR_Enable();
	}
#endif	
	return temp;
}
#endif
kal_uint8 FMR_PamdLevel( kal_int16 curf )
{
#if defined(MT6616) || defined(MT6626) || defined(MT6276FM) || defined(MT6255FM) || defined(MT6256FM) || defined(MT6251FM)
	//kal_uint8 pamd;
	return FMR_GetCQI(curf,FMR_CQI_PAMD);
//	kal_trace(TRACE_INFO, FM_INFO_FM_PAMD_LVL, curf, pamd);
//	return pamd;
#else
   return 0;
#endif
}

kal_uint8 FMR_GetSignalLevel( kal_int16 curf )
{
#if (defined(FM_RADIO_ENABLE))
  // kal_uint8 rssi;
   
   return FMR_GetCQI(curf,FMR_CQI_RSSI);
//   kal_trace(TRACE_INFO, FM_INFO_FM_RSSI_LVL, curf, rssi);
   //return rssi;
#else
	return 0;
#endif
}
/*0,unmute. 1, mute*/
void FMR_Mute( kal_uint8 mute )
{
#if (defined(FM_RADIO_ENABLE))
#ifndef FMR_RAMP_DOWN_SUPPORT
   //kal_trace(TRACE_GROUP_2,FM_API_ENTRANCE,13);
   	if (mute) 
	{
		FMDrv_Mute(1);
#if defined( __FMRADIO_I2S_SUPPORT__ )
		I2SIN_MuteSpeaker(KAL_TRUE);
#else  
		LINEIN_MuteSpeaker(KAL_TRUE);      
#endif
		isSpeakerOn = KAL_FALSE;
   	} 
	else 
	{
#if defined( __FMRADIO_I2S_SUPPORT__ )
		I2SIN_MuteSpeaker(KAL_FALSE);
#else
		LINEIN_MuteSpeaker(KAL_FALSE);
#endif
		isSpeakerOn = KAL_TRUE;
		FMDrv_Mute(0);
   }
	kal_trace(TRACE_GROUP_2,FM_API_EXIT,13);
#endif
#endif
}

void FMR_Init(void)
{
#if (defined(FM_RADIO_ENABLE))
   FMDrv_ChipInit();
#endif
}
/*------------------------------------------------------------------------------*/

void FMR_SetOutputDevice( kal_uint8 device )
{
#if (defined(FM_RADIO_ENABLE))
#if defined( __FMRADIO_I2S_SUPPORT__ )
   I2SIN_SetOutputDevice(device);
#else
   LINEIN_SetOutputDevice(device);
#endif
	//kal_trace(TRACE_INFO,FM_SET_OutputDevice,device);
#endif
}

void FMR_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index )
{
#if (defined(FM_RADIO_ENABLE))
#if defined( __FMRADIO_I2S_SUPPORT__ )
   I2SIN_SetOutputVolume( volume1, digital_gain_index );
#else
#if defined(MT6252H) || defined(MT6252)
   if(FMR_volume_update)
   {
      FMR_volume = volume1; 
      FMR_digital_gain_index = digital_gain_index;
   }
#endif   
   LINEIN_SetOutputVolume( volume1, digital_gain_index );
#endif
	kal_trace(TRACE_INFO,FM_SET_OutputVolume,volume1,digital_gain_index);
#endif
}

#if defined(__GAIN_TABLE_SUPPORT__)
void FMR_SetOutputGainControl( kal_uint32 gain )
{
#if defined(FM_RADIO_ENABLE)
#if defined(MT6252H) || defined(MT6252)
   if(FMR_volume_update)
      FMR_gain = gain;
#endif   
   LINEIN_SetOutputGainControl( gain );
#endif
}
void  FMR_SetDualPathGainControl(kal_uint32 ext_amp_gain )
{
#if defined(FM_RADIO_ENABLE)
   LINEIN_SetOutputGainControlDualPath( ext_amp_gain );
#endif
}
#endif

/*
  FMR_IsChipValid could be called to confirm if FM chip dose exist.
  Return ture if FM chip is valid, return KAL_FALSE otherwise.
*/
kal_bool FMR_IsChipValid(void)
{
#if (defined(FM_RADIO_ENABLE))
	return FMDrv_IsChipValid();
#else
	return KAL_FALSE;
#endif
}

kal_bool FMR_IsActive(void)
{
#if (defined(FM_RADIO_ENABLE))
   return isFmActive;
#else
	return KAL_FALSE;
#endif
}

void FMR_EvaluateRSSIThreshold(void)
{
#if 0//defined(MT6189A1)
/* under construction !*/
#endif
}

void FMR_Radio_EngineerMode(kal_uint16 group_idx, kal_uint16 item_idx, kal_uint32 item_value)
{
#if defined(FM_RADIO_ENABLE)
    FMDrv_radio_item_info(group_idx, item_idx, item_value);
#endif
}

kal_uint16 FMR_GetIFCount(kal_int16 curf)
{
#if defined(MT6189A1) || defined(MT6188A1) || defined(AR1000)
    return FMDrv_GetIF(curf);
#else
    return 0;
#endif
}

kal_uint32 FMR_GetCapArray(void)
{
#if (defined(FMR_GET_CAP_SUPPORT))
    return FMDrv_GetCapArray();
#else
    return 0;
#endif
}


kal_uint16 FMR_ReadByte(kal_uint8 addr)
{
#if defined(FM_RADIO_ENABLE)
    return FMDrv_ReadByte(addr);
#else
    return 0;
#endif
}

void FMR_WriteByte(kal_uint8 addr, kal_uint16 data)
{
#if defined(FM_RADIO_ENABLE)
	FMDrv_WriteByte(addr, data);
#endif
}

void FMR_SoftMuteOnOff(kal_uint8 On_Off)	//On:1, Off:0
{
#if defined(MT6188A1)
    FMDrv_SoftMuteOnOff((kal_bool)On_Off);
#endif
}

void FMR_SoftMuteStage(kal_uint8 stage)	//stage1~3
{
#if defined(MT6188A1)
    FMDrv_SoftMuteStage(stage);
#endif
}

void FMR_StereoBlendStage(kal_uint8 stage)	//stage1~3
{
#if defined(MT6188A1)
    FMDrv_StereoBlendStage(stage);
#endif
}

kal_uint8 FMR_GetChipID(void)
{
#if defined(MT6189A1) || defined(MT6188A1)
	return FMDrv_GetChipID();
#elif defined(MT6616)
	return 6; //META Tools read Chip ID
#elif defined(MT6276FM)
	return 7; //META Tools read Chip ID
#elif defined(MT6256FM)
	return 8; //META Tools read Chip ID
#elif defined(MT6251FM)	
	return 9; //META Tools read Chip ID
#elif defined(MT6626)
    return 10; //META Tools read Chip ID	
#elif defined(MT6255FM) 
	return 11; //META Tools read Chip ID	
#elif defined(MT6250FM) 
	return 12; //META Tools read Chip ID	
#elif defined(MT6260FM) 
	return 13; //META Tools read Chip ID	
#elif defined(MT6261FM)
	return 14;
#else
    return 0;
#endif
}

kal_uint8 FMR_Get_H_L_side(kal_int16 curf) /* input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)*/
{
#if defined(MT6189A1) || defined(MT6188A1)
	return FMDrv_Get_H_L_side(curf);//1:H side, 0:L side
#else 
    return 0;
#endif
}

kal_uint8 FMR_Get_stereo_mono(void)
{
#if (defined(FM_RADIO_ENABLE))
	return FMDrv_Get_stereo_mono();//1:stereo, 0:mono
#else
	return 0;
#endif
}

kal_uint8 FMR_CheckOption(void)
{
	return 0;
}
kal_uint8 FMR_GetRXFilterBW(void)
{
	return 1;
}
kal_uint8 FMR_GetMagRatio(void)
{
	kal_int16 MRValue=0;
#if defined(FMR_NEW_CHIP)
	MRValue = FMDrv_GetMR();
	//kal_trace(TRACE_INFO,FM_INFO_FM_MR,MRValue);
	if(MRValue < 0)/*MR range1x~50*/
	{
		MRValue = 0;
	}
#endif
	return (kal_uint8)MRValue;
}

/*************************************************
* Name: FMR_SetAntennaType
* Desription: to switch FM antenna input
* Parameter: 0-->FM_ANTENNA_USE_EARPHONE
*                  1-->FM_ANTENNA_USE_SHORT_ATA
*************************************************/
void FMR_SetAntennaType(kal_uint8 ata_type)
{
#ifdef FMR_SHORT_ANTENNA_SUPPORT
	FMDrv_SetAntennaType(ata_type);
	kal_trace(TRACE_INFO,FM_SET_ANTENNAY_TYPE,ata_type);
    if (-1 != (kal_int16)_current_frequency)
    {
	    FMR_SetFreq(_current_frequency);
    }
#endif
}
/*************************************************
* Name: FMR_GetAntennaType
* Desription: to get FM antenna input settings
* Return: 0-->FM_ANTENNA_USE_EARPHONE
*             1-->FM_ANTENNA_USE_SHORT_ATA
*************************************************/
kal_int8 FMR_GetAntennaType(void)
{
	kal_int8 type=-1;
#ifdef FMR_SHORT_ANTENNA_SUPPORT
	type = FMDrv_GetAntennaType();
	kal_trace(TRACE_INFO,FM_GET_ANTENNAY_TYPE,type);
#endif
	return type;
}
#ifdef FMR_INJECT_DEBUG
void FMR_INJECT_Parse(ilm_struct *current_ilm)//RUN
{
    tst_module_string_inject_struct* tst_inject = (tst_module_string_inject_struct*)current_ilm->local_para_ptr;
	kal_int32 longRSSI=0,ShortRSSI=0,CQI=0,ATDC=0,SoftmuteGain=0;
	kal_uint32 PRX=0;
	switch(tst_inject->index)
	{
		case 0:
		{
			extern kal_int32 FMR_RSSI_LANTTH;
			extern kal_int32 FMR_MRTH;
			extern kal_int32 FMR_PAMD_TH;
			sscanf((kal_char *)tst_inject->string, "%d,%d,%d", &longRSSI,&ShortRSSI,&CQI); 
#if (FMR_ENHANCED_SCAN==1)
			FMR_RSSI_LANTTH = longRSSI;
			FMR_MRTH = ShortRSSI;
			FMR_PAMD_TH = CQI;
#else
			FMDrv_SetLonAntenTH(longRSSI);
			FMDrv_SetShortAntenTH(ShortRSSI);
			FMDrv_SetCQITH(CQI);
#endif			
			kal_prompt_trace(MOD_FMR,"long RSSI TH=%d",longRSSI);
			kal_prompt_trace(MOD_FMR,"MR TH=%d",ShortRSSI);
			kal_prompt_trace(MOD_FMR,"CQI TH=%d",CQI);
			break;
		}
		case 1:
		{
#if (FMR_ENHANCED_SCAN==1)
			extern FMR_Audio_Level_e FMR_AUDIO_LEVEL;
			extern kal_int32 FMR_ATDC_TH;
			extern kal_uint32 FMR_PRX_TH;
			sscanf((kal_char *)tst_inject->string, "%d,%d,%d", &ATDC,&SoftmuteGain,&PRX); 
			FMR_ATDC_TH = ATDC;
			FMR_AUDIO_LEVEL = (FMR_Audio_Level_e)SoftmuteGain;
			FMR_PRX_TH = PRX;
			kal_prompt_trace(MOD_FMR,"ATDC TH=%d",ATDC);
			kal_prompt_trace(MOD_FMR,"SoftmuteGain TH=%d",SoftmuteGain);
			kal_prompt_trace(MOD_FMR,"PRX TH=%d",PRX);
#else
			FMDrv_SetLonAntenTH(longRSSI);
			kal_prompt_trace(MOD_FMR,"long RSSI TH=%x",longRSSI);
#endif			
			break;
		}
		case 2:
		{
#if (FMR_ENHANCED_SCAN==1)
			extern kal_int32 FMR_PAMD_TH;
			extern kal_int32 FMR_PAMD_TONE_TH;
			extern kal_uint32 FMR_ATDEV_TH;
			sscanf((kal_char *)tst_inject->string, "%d,%d,%d", &CQI,&SoftmuteGain,&PRX); 
			FMR_PAMD_TH=CQI;
			FMR_PAMD_TONE_TH=SoftmuteGain;
			FMR_ATDEV_TH=PRX;
			kal_prompt_trace(MOD_FMR,"PAMD TH=%d",CQI);
			kal_prompt_trace(MOD_FMR,"PAMD tone TH=%d",SoftmuteGain);
			kal_prompt_trace(MOD_FMR,"ATDEV TH=%d",PRX);
#else
			sscanf((kal_char *)tst_inject->string, "%d", &ShortRSSI); 
			FMDrv_SetShortAntenTH(ShortRSSI);
			kal_prompt_trace(MOD_FMR,"Short RSSI TH=%x",ShortRSSI);
			break;
#endif			
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif		
		default:
			break;
	}
	
}
#endif

/***********APIs for Engineer mode************/
/*sounk track:0,mono. 1,stereo.
* FM chip driver file need return correct value
*/
fmr_sound_track_type_enum FMR_Get_Sound_Track(void)
{
#ifdef FMR_EM_NEW_FEATURE	
	kal_uint8 type;
	type = FMDrv_Get_stereo_mono();
	//kal_trace(TRACE_INFO,FM_INFO_GetSoundTrack,type);
	return (fmr_sound_track_type_enum)type;
#else
	return FMR_SOUND_TRACK_TYPE_MONO;
#endif	
}
void FMR_Force_Mono(void)
{
#ifdef FMR_EM_NEW_FEATURE	
	FMDrv_Force_Mono();
#endif
}
void FMR_Force_Stereo(void)/*can't force mono, this function will set FM auto modulation*/
{
#ifdef FMR_EM_NEW_FEATURE	
	FMDrv_Force_Stereo();
#endif
}
void FMR_Set_AntennaType(fmr_antenna_type_enum type)
{
#ifdef FMR_EM_NEW_FEATURE	
	FMR_SetAntennaType((kal_uint8)type);
#endif
}
fmr_antenna_type_enum FMR_Get_AntennaType(void)
{
#ifdef FMR_EM_NEW_FEATURE	
	fmr_antenna_type_enum type;
	if(FMR_GetAntennaType() == 1)
	{
		type = FMR_ANTENNA_TYPE_SHORT;
	}
	else
	{
		type = FMR_ANTENNA_TYPE_LONG;
	}
	return type;
#else
	return FMR_ANTENNA_TYPE_LONG;
#endif	
}
kal_uint32 FMR_Get_RSSI_Threshold(fmr_antenna_type_enum type)
{
#ifdef FMR_EM_NEW_FEATURE	
	kal_uint32 Temp=0;
	Temp = FMDrv_GetRSSITH((kal_uint8)type);
	//kal_trace(TRACE_INFO,FM_INFO_GetRSSITH,type,Temp);
	return Temp;
#else
	return 0;
#endif	
}
void FMR_Set_RSSI_Threshold(fmr_antenna_type_enum type, kal_uint32 value)
{
#ifdef FMR_EM_NEW_FEATURE	
	FMDrv_SetRSSITH((kal_uint8)type,value);
#endif
}
kal_int32 FMR_RSSI_Hex2Db(kal_uint32 Hex)
{
#ifdef FMR_EM_NEW_FEATURE	
	kal_int32 Db=0;
	Db = FMDrv_RSSI_Hex2Db(Hex);
	//kal_trace(TRACE_INFO,FM_INFO_HEX2DB,Hex,Db);
	return Db;
#else
	return 0;
#endif	
}
kal_uint32 FMR_RSSI_Db2Hex(kal_int32 Db)
{
#ifdef FMR_EM_NEW_FEATURE	
	kal_uint32 Hex;
	Hex = FMDrv_RSSI_Db2Hex(Db);
	//kal_trace(TRACE_INFO,FM_INFO_DB2HEX,Db,Hex);
	return Hex;
#else
	return 0;
#endif	
}
kal_uint32 FMR_Get_Param(kal_uint8* param)
{
	return 0;
}
void FMR_Set_Param(kal_uint8* param, kal_uint32 len)
{
#if defined(MT6255FM)||defined(MT6256FM)
	if(param[0]==1)
	{
		FMR_PowerOn();
		FMDrv_Freq_CQI_Log();
		FMR_PowerOff();
	}
#elif (defined(MT6250FM) || defined(MT6260FM) || defined(MT6261FM))	
	FMR_PowerOn();
	FMR_Set_AntennaType((fmr_antenna_type_enum)param[0]);	//0: LANT, 1:SANT

	if(param[1]==0x01)
	{		
		FMDrv_JammerScan();
	}
	else if(param[1]==0x02)
	{
		FMDrv_Freq_CQI_Log(param[2]);
	}
	else if(param[1]==0x03)
	{
		FMDrv_Freq_CQI_Through_Time_Log(param[2],param[3],param[4]);
	}
	else if(param[1]==0x04)
	{
		FMDrv_EM_Set_AudioLevel(param[2]);//0~4
	}
	else if(param[1]==0x05)
	{
		FMDrv_EM_Set_RSSI(param[2]);//0x84~0x81, 0~0x46(70)
	}
	else if(param[1]==0x06)
	{
		FMDrv_EM_Set_DesenseLevel(param[2]);//0~6
	}
	FMR_PowerOff();
#endif		
	return;
}
#ifdef __FM_RADIO_RDS_SUPPORT__
void FMR_RDS_DummyCBK(RdsEvent event)
{
	return;
}
#endif	
void FMR_RDS_Enable(void)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
	FMR_RDS_OnOff(KAL_TRUE);
	FMR_RDS_Open(FMR_RDS_DummyCBK);
#endif	
}
void FMR_RDS_Disable(void)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
	FMR_RDS_OnOff(KAL_FALSE);
#endif
}
kal_uint32 FMR_RDS_GetBLER(void)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
	kal_uint32 BLER=0;

	BLER=FMR_RDS_Get_BadBlock_Ratio();
	return BLER;
#else
	return 0;
#endif
}

/***********************************END of EM APIs***********************************************/
#ifdef __FM_RADIO_RDS_SUPPORT__
void FMR_RDS_INTR_OnOff(kal_bool On_Off)
{
	kal_trace(TRACE_INFO,FM_RDS_INTR_ONOFF,On_Off);
	if(On_Off)
		RDS_INTR_Enable();
	else
		RDS_INTR_Disable();
	return;
}

kal_bool FMR_RDS_HWChk(void)
{
//	kal_bool isSupportRDS;
//	isSupportRDS = RDS_RegChk();
	return KAL_TRUE;
}

void FMR_RDS_OnOff(kal_bool On_Off)
{
	if(!FMR_RDS_HWChk())
	{
		ASSERT(0);
	}
	if(On_Off)
	{
		#if (!defined(IC_MODULE_TEST))
		//if (INT_BootMode() != MTK_FACTORY_MODE )
        fm_start_timer(FM_RDS_BLER_CHECK_TIMER, FM_RDS_BLER_CHECK_INTERVAL, FMR_RDS_ChkEvent, NULL);
		#endif
		RDS_Enable();
	}
	else
	{
		RDS_Disable();
		#if (!defined(IC_MODULE_TEST))
		//if (INT_BootMode() != MTK_FACTORY_MODE )
		fm_stop_timer(FM_RDS_BLER_CHECK_TIMER);
		#endif
	}
	kal_trace(TRACE_GROUP_2,FM_API_EXIT,14);
	return;
}

void FMR_RDS_BlerCheck(void * param)
{
#if !defined(FMR_DSP_CHIP)
	RDS_BlerCheck();
#endif
	//kal_trace(TRACE_GROUP_2,FM_API_ENTRANCE,15);
    if(pstRDSData->AF_Data.Addr_Cnt == 0xFF) //AF List Finished
    {
        pstRDSData->event_status |= RDS_EVENT_AF;
    }
	FMR_PamdLevel(_current_frequency);/*for dbg*/
	FMR_GetSignalLevel(_current_frequency);/*for dbg*/
	FMR_GetMagRatio();/*for dbg*/
    fm_stop_timer(FM_RDS_BLER_CHECK_TIMER);
	fm_start_timer(FM_RDS_BLER_CHECK_TIMER,_BLER_CHK_INTERVAL,FMR_RDS_ChkEvent, NULL);
	kal_trace(TRACE_GROUP_2,FM_API_EXIT,15);
}

void FMR_RDS_Open(RDS_CallBack callback)
{
	RDS_Sync_Cnt = 0;
	RDS_Block_Reset_Cnt = 0;
   	//pstRDS_Hdlr->callback = callback; 
   	pstRDS_Hdlr=callback;
}

void FMR_RDS_Get_Block_Value(kal_uint16 *buffer)
{
#if defined(FMR_NEW_CHIP)
    FMDrv_RDS_GetData(buffer);
#else
	kal_uint8 offset;
	for(offset=0; offset<5; offset++)
	{
		RDS_Get_Block_Value(buffer, offset);
	}
#endif
}

kal_uint16 FMR_RDS_Get_GoodBlock_Counter(void)
{
	kal_uint16 reg_value;
	reg_value = RDS_Read_Block_Counter(KAL_TRUE);
	return reg_value;
}
kal_uint16 FMR_RDS_Get_BadBlock_Counter(void)
{
	kal_uint16 reg_value;
	reg_value = RDS_Read_Block_Counter(KAL_FALSE);
	return reg_value;
}
kal_uint16 FMR_RDS_Get_BadBlock_Ratio(void)
{
	kal_uint16 reg1, reg2, ratio;
	reg1 = RDS_Read_Block_Counter(KAL_TRUE);
	reg2 = RDS_Read_Block_Counter(KAL_FALSE);
	if((reg1==0)&&(reg2==0))
		ratio = 0;
	else
		ratio = ((float)reg2/(reg1 + reg2))*100;
    kal_trace(TRACE_INFO,FM_INFO_FM_RDS_BLER_ERR,(reg1 + reg2), ratio);
	return ratio;
}

void FMR_RDS_Reset_Block_Counter(void)
{
	RDS_Reset_Block_Counter();
	return;
}
void FMR_RDS_Read_Group_Counter(kal_uint16 *pstGroupCnt)
{
 	kal_uint8 indx;
	
	if(!isRdsOn)
		return;
 	for(indx=0; indx<32; indx++)
 	{
 		*(pstGroupCnt+indx) = pstRDSData->Group_Cnt[indx];
 	}
	return;
}
void FMR_RDS_Reset_Group_Counter(void)
{
	kal_uint8 indx;

	if(!isRdsOn)
		return;

	for(indx=0; indx<32; indx++)
	{
		pstRDSData->Group_Cnt[indx] = 0;
	}
	return;
}
void FMR_RDS_ChkEvent(void * param)
{
  if(!isRdsOn)
    return;
#if !defined(IC_MODULE_TEST)
  if((fm_timer_table[FM_BASE_TIMER_ID].event_id == NULL)/*&&(INT_BootMode() != MTK_FACTORY_MODE )*/)/*META mode need clear block count too*/
  {
    pstRDSData->event_status |= RDS_EVENT_RDS_TIMER;
  }
  RDS_EventGet();
#else
  pstRDS_Hdlr(1);
#endif
}
void FMR_RDS_GetStatus(RdsFlag *flag, kal_uint16 *buffer)
{
	kal_uint8 cnt;
	kal_uint16 flag_mask;
	
	if(!isRdsOn)
		return;

	for(cnt = 0; cnt<16; cnt++)
	{
		flag_mask = 1<<cnt;
		if((pstRDSData->RDSFlag.flag_status)&flag_mask)
		{
			switch(flag_mask)
			{
				case RDS_FLAG_IS_TP:
					*buffer = pstRDSData->RDSFlag.TP[1];
					break;
#if FMR_RDS_FULL_SUPPORT					
				case RDS_FLAG_IS_TA:
					*buffer = pstRDSData->RDSFlag.TA;
					break;
				case RDS_FLAG_IS_MUSIC:
					*buffer = pstRDSData->RDSFlag.Music;
					break;
				case RDS_FLAG_IS_STEREO:
					*buffer = pstRDSData->RDSFlag.Stereo;					
					break;
				case RDS_FLAG_IS_ARTIFICIAL_HEAD:
					*buffer = pstRDSData->RDSFlag.Artificial_Head;
					break;
				case RDS_FLAG_IS_COMPRESSED:
					*buffer = pstRDSData->RDSFlag.Compressed;					
					break;
				case RDS_FLAG_IS_DYNAMIC_PTY:
					*buffer = pstRDSData->RDSFlag.Dynamic_PTY;				
					break;
				case RDS_FLAG_TEXT_AB:
					*buffer = pstRDSData->RDSFlag.Text_AB;					
					break;
#endif					
				default:
					*buffer=0;
					break;					
			}
			*flag = (RdsFlag)flag_mask;
            pstRDSData->RDSFlag.flag_status &= ~flag_mask;
			kal_trace(TRACE_INFO,FM_INFO_FM_RDS_EVENT_STATUS,flag_mask,*buffer);
            return;
		}
	}
}

void FMR_RDS_GetInfo(RdsCmd Cmd, kal_uint16 *buffer, kal_uint8 *bufsize)
{
	kal_uint16 PAMD_Value, AF_PAMD_LBound, AF_PAMD_HBound, TA_PAMD_Threshold;
	kal_uint16 indx, set_freq = 875, sw_freq, org_freq;
	kal_uint16 PAMD_Level[25];
	kal_uint16 PAMD_DB_TBL[5] =
	{
	// 5dB, 10dB, 15dB, 20dB, 25dB, 
 	//	13, 17, 21, 25, 29
 	    8,10,12,15,20
	};
#if (defined(MT6251FM)||defined(MT6276FM)||defined(MT6256FM))
    kal_uint16 max_af_num =0;
#endif
	if(!isRdsOn)
	{
        *bufsize = 0;
		return;
	}
	kal_trace(TRACE_INFO,FM_INFO_FM_RDS_EVENT_INFO, Cmd);
    *bufsize = 1;
	switch(Cmd)
	{
#if FMR_RDS_FULL_SUPPORT					
		case RDS_CMD_PI_CODE:
			*buffer = pstRDSData->PI;			
			break;
		case RDS_CMD_PTY_CODE:
			*buffer = pstRDSData->PTY;
			break;
		/*case RDS_CMD_LOCDATETIME:
			break;*/
		case RDS_CMD_UTCDATETIME:
			*buffer = pstRDSData->CT.Month;
			*(buffer+1) = pstRDSData->CT.Day;
			*(buffer+2) = pstRDSData->CT.Year;
			*(buffer+3) = pstRDSData->CT.Hour;
			*(buffer+4) = pstRDSData->CT.Minute;
			*(buffer+5) = pstRDSData->CT.Local_Time_offset_signbit;
			*(buffer+6) = pstRDSData->CT.Local_Time_offset_half_hour;
			break;
#endif			
		case RDS_CMD_PROGRAMNAME:
            *bufsize = 8;
			for(indx=0; indx<8; indx++)
			{
				*(buffer+indx) = pstRDSData->PS_Data.PS[2][indx];
			}			
			break;
 		case RDS_CMD_LAST_RADIOTEXT:
			*bufsize = 2*(1+pstRDSData->RT_Data.TextLength)*(1+pstRDSData->RT_Data.isTypeA);
			for(indx=0; indx<64; indx++)
			{
				*(buffer+indx) = pstRDSData->RT_Data.TextData[2][indx];
			}
			pstRDSData->RT_Data.isRTDisplay = KAL_FALSE;
			break;			
		case RDS_CMD_AF:
			AF_PAMD_LBound = PAMD_DB_TBL[0]; //5dB
			AF_PAMD_HBound = PAMD_DB_TBL[2]; //15dB
			PAMD_Value = FMDrv_GetPamdLvl(_current_frequency);
			sw_freq = _current_frequency;
			org_freq = _current_frequency;
			*buffer = org_freq;
			if(PAMD_Value < AF_PAMD_LBound)
			{				
       			//_backup_frequency = _current_frequency;
      //#if ((!defined(FM_INTERFACE_HCI)) && defined(MT6616)) || ((!defined(FM_INTERFACE_HCI)) && defined(MT6626))
#if (!defined(FM_INTERFACE_HCI))
                RDS_INTR_Disable();
			    //FMDrv_ClrIntr();
#endif

#if (defined(MT6251FM)||defined(MT6276FM)||defined(MT6256FM))
                if (pstRDSData->AF_Data.AF[1][0] > 2)
                {
                   max_af_num = 2;
                }
                else
                {
                   max_af_num = pstRDSData->AF_Data.AF[1][0];
                }
                for(indx=0; indx<max_af_num; indx++)
#else
                for(indx=0; indx<pstRDSData->AF_Data.AF[1][0]; indx++)
#endif
      	        {
   		  	        if(pstRDSData->AF_Data.isMethod_A == 1)
       		        {
						if(pstRDSData->AF_Data.AF[1][indx+1] < 205)  //AF VHF Freq
						{
							set_freq = pstRDSData->AF_Data.AF[1][indx+1] + 875;
						    kal_trace(TRACE_INFO, FM_INFO_FM_RDS_AF_SET, 10, set_freq);
						}
   				    }
					else
					{
						if(pstRDSData->AF_Data.AF[1][indx+1] < 205)  //AF VHF Freq
						{
							set_freq = pstRDSData->AF_Data.AF[1][indx+1] + 875;
							kal_trace(TRACE_INFO, FM_INFO_FM_RDS_AF_SET, 11, set_freq);
						}					
					}
					if(set_freq != org_freq)
       		        {
						PAMD_Level[indx] = FMDrv_GetPamdLvl(set_freq);
						kal_trace(TRACE_INFO, FM_INFO_FM_RDS_AF_PAMD, set_freq, indx, PAMD_Level[indx]);
					    if(PAMD_Level[indx] > PAMD_Value)
					    {
        				    PAMD_Value = PAMD_Level[indx];
        			        sw_freq = set_freq;
					    }
       		        }
       	        }
				if((PAMD_Value > AF_PAMD_HBound)&&(sw_freq != 0))
				{
					kal_trace(TRACE_INFO, FM_INFO_FM_RDS_AF_SWITCH, sw_freq);
					*buffer = sw_freq;
					RDS_Init_Data();
					FMR_SetFreq(sw_freq);
				}
				else
				{
					//FMR_SetFreq(org_freq);
                    *buffer = org_freq;
				    FMR_SetFreq(org_freq);
			    }
      //#if ((!defined(FM_INTERFACE_HCI)) && defined(MT6616)) || ((!defined(FM_INTERFACE_HCI)) && defined(MT6626))
#if (!defined(FM_INTERFACE_HCI))
				RDS_INTR_Enable();
#endif
			}
			else
			{
				*buffer = org_freq;
			}
			break;
		case RDS_CMD_AF_LIST:
			for(indx=0; indx<=pstRDSData->AF_Data.AF[1][0]; indx++)
			{
				if ((indx != 0)&&(pstRDSData->AF_Data.AF[1][indx] < 205))				
			    {
					*(buffer+indx) = pstRDSData->AF_Data.AF[1][indx] + 875;
				}					
				else
					*(buffer+indx) = pstRDSData->AF_Data.AF[1][indx];
			}
			break;
		/*case RDS_CMD_AFON:
			break;*/
		case RDS_CMD_TAON:
			TA_PAMD_Threshold = PAMD_DB_TBL[2]; //15dB
			sw_freq = _current_frequency;
			org_freq = _current_frequency;
			*buffer = org_freq;
       		RDS_TA_BackUpFreq = _current_frequency;
			PAMD_Value = 0;
 		      //#if ((!defined(FM_INTERFACE_HCI)) && defined(MT6616)) || ((!defined(FM_INTERFACE_HCI)) && defined(MT6626))
#if (!defined(FM_INTERFACE_HCI))
            RDS_INTR_Disable();
            //FMDrv_ClrIntr();
#endif
       		for(indx=0; indx<pstRDSData->AFON_Data.AF[1][0]; indx++)
       		{
       			//if(indx == 0)   PAMD_Value = 255; //for test
				//else //for test
				if(pstRDSData->AFON_Data.AF[1][indx+1] < 205)  //AF VHF Freq
				{
					set_freq = pstRDSData->AFON_Data.AF[1][indx+1] + 875;
					kal_trace(TRACE_INFO, FM_INFO_FM_RDS_AF_SET, 10, set_freq);
				}					
				if(set_freq != org_freq)
				{
					PAMD_Level[indx] = FMDrv_GetPamdLvl(set_freq);
				if(PAMD_Level[indx] > PAMD_Value)
				{
					PAMD_Value = PAMD_Level[indx];
						sw_freq = set_freq;
				}
       		}
       		}
			if((PAMD_Value > TA_PAMD_Threshold)&&(sw_freq != 0))
			{
				pstRDSData->Switch_TP= KAL_TRUE;
                RDS_Init_Data();
 	      		FMR_SetFreq(sw_freq);  
				*buffer = sw_freq;	
			}
			else
			{			
				FMR_SetFreq(org_freq);
				*buffer = org_freq;	
			}
                      //#if (!defined(FM_INTERFACE_HCI)) && defined(MT6616)
#if (!defined(FM_INTERFACE_HCI))
            RDS_INTR_Enable();
#endif
			break;
		case RDS_CMD_TAON_OFF:
		{
			pstRDSData->Switch_TP= KAL_FALSE;
			*buffer = RDS_TA_BackUpFreq;	
  			FMR_SetFreq(RDS_TA_BackUpFreq);			
			break;			
		}
		default:
            *bufsize = 0;
			break;
	}
}

#if (defined(MT6616))
void FMR_HCI_Event_Hdlr(kal_bool isReadyRead)
{
#if defined(FM_INTERFACE_HCI)
	FMDrv_HCI_Event_Hdlr(isReadyRead);
	if((pstFMR_data->bHWsearchStop) == KAL_FALSE)
	{
		if((pstFMR_data->FM_HCI_data.buffer[4]) == 0x0A)
		{
			if(pstFMR_data->FM_HCI_data.buffer[2] == 4)
				FMR_ChkSearchStop();
		}
		else if((pstFMR_data->FM_HCI_data.buffer[4]) == 0x0B)
		{
			if(pstFMR_data->FM_HCI_data.buffer[2] == 0x22)
			{
				FMR_ChkSearchStop();
			}
		}
	}
#endif
}
#endif

void FMR_EINTChk(void)
{
	kal_uint16 intr;
	
    if(!isFmActive)
    {
        return;
    }
    
	FMDrv_GetIntr(&intr);
	kal_trace(TRACE_INFO,FM_INTR_VALUE,intr);
	if(intr&0x0001)
	{
		if(pstFMR_data->is_searching)
		{
			FMR_ChkSearchStop();
		}
		FMDrv_ClrIntr();
		//EXT_STC_flag = 1;
	}   
	else if(intr&0x0020)
	{
		kal_trace(TRACE_INFO,FM_INFO_FM_RDS_EINT);
		RDS_Eint_Handler();//(RDS_Event_Handler);
        FMDrv_ClrIntr();
		//kal_trace(TRACE_INFO,FM_INFO_FM_RDS_CLR);		
	}
    return;
}
/*b_AFON: 1,AF enable. 0, AF disable*/
void FMR_RDS_EnableAF(kal_bool b_AFON)
{
	g_AF_Enable = b_AFON;
}
/*b_TPON: 1,TP enable. 0, TP disable*/
void FMR_RDS_EnableTP(kal_bool b_TPON)
{
	g_TP_Enable = b_TPON;
	if(!b_TPON)
		pstRDSData->RDSFlag.TP[1] = KAL_FALSE;
}
#endif/*end of __FM_RADIO_RDS_SUPPORT__*/

#if (defined(MT6626))
#if 0
/* under construction !*/
/* under construction !*/
#if (defined(FM_RADIO_ENABLE))
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined( __FMRADIO_I2S_SUPPORT__ )
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __FM_RADIO_RDS_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   
#endif	
/* under construction !*/
#endif
void FMR_BT_Do_Chip_Force_Reset_Done(void)
{
#if (defined(FM_RADIO_ENABLE))
    //after power on, _current_frequency will be set to -1. So saving first here.
    kal_int16 temp_curFreq = _current_frequency;

	if(!isFmActive)
    {
        return;
	}

	//kal_print("FMR_BT_Do_Chip_Force_Reset_Done");
    //re-allocate memory for data structure
    if(pstFMR_data != NULL)
    {
    	free_ctrl_buffer(pstFMR_data);
    	pstFMR_data = (FMR_data *)0;
		pstFMR_data = (FMR_data*)get_ctrl_buffer( sizeof(FMR_data) );
    }
	else
    {
		pstFMR_data = (FMR_data*)get_ctrl_buffer( sizeof(FMR_data) );
    }

    //reset as common part requested
    BtRadio_Power_Handler(1, 0, 0);
		
    //power on sequence
	FMDrv_PowerOnReset();
	pstFMR_data->is_searching = KAL_FALSE;
	FMR_SetAntennaType(is_shortAntenna);
	FMR_SetFreq(temp_curFreq);
	//FMR_RDS_OnOff(isRdsOn);
	#if defined(__FM_RADIO_RDS_SUPPORT__)
	if(isRdsOn)
    {
		//kal_print("reset, RDS ON!");
        FMDrv_RDS_Enable();
    }
    else
    {
		//kal_print("reset, RDS OFF!");
        FMDrv_RDS_Disable();
    }
  #endif/*defined(__FM_RADIO_RDS_SUPPORT__)*/
#endif
}
#endif/*defined MT6626*/
