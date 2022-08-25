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
 * Filename:
 * ---------
 *  l1sp.h
 *
 * Project:
 * --------
 *   MTK6208
 *
 * Description:
 * ------------
 *   FMRadio Task interface definition
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __FM_RADIO_H__
#define __FM_RADIO_H__
//#include "kal_general_types.h" //add

#if (defined(MT6626)||defined(MT6251FM)||defined(MT6276FM)||defined(MT6256FM)||defined(MT6255FM)||defined(MT6250FM) || defined(MT6260FM) || defined(MT6261FM))
#define FMR_SW_RSSI_SORT /*support RSSI sort and sw eliminate false channel*/
#define FMR_EM_NEW_FEATURE
#if (defined(INTERNAL_ANTENNAL_SUPPORT))
#define FMR_GET_CAP_SUPPORT
#define FMR_SHORT_ANTENNA_SUPPORT
#endif
#endif
#if (defined(MT6626)||defined(MT6616)||defined(MT6251FM)||defined(MT6276FM)||defined(MT6256FM)||defined(MT6255FM)||defined(MT6250FM) || defined(MT6260FM) || defined(MT6261FM))
#define FMR_RAMP_DOWN_SUPPORT/*FM Support ramp down don't need FMR mute*/
#define FMR_NEW_CHIP
#endif
#if (defined(MT6250FM) || defined(MT6260FM) || defined(MT6261FM))
#define FMR_ENHANCED_SCAN 1/*1:enable SW scan, 0:enable HW scan*/
#define FMR_NOISE_FLOORT_DETECT 1/*1:enable , 0:disable noise floor detect*/
#define FMR_50K_STEP 0
#else
#define FMR_ENHANCED_SCAN 0
#endif

#if (defined(MT6626)||defined(MT6250FM) || defined(MT6260FM) || defined(MT6261FM))
#define FMR_DSP_CHIP
#endif
#ifndef __FM_RADIO_HW_SEARCH__
/* defined in custom folder */
extern unsigned char const FM_RADIO_INPUT_LEVEL_THRESHOLD;
#endif
#ifdef FMR_DEBUG_TRACE
#define FMR_TRACE(trace_class,string) kal_prompt_trace(MOD_FMR, string)
#define FMR_TRACE0(trace_class,string,Para0) kal_prompt_trace(MOD_FMR, string,(Para0))
#define FMR_TRACE1(trace_class,string,Para0,Para1) kal_prompt_trace(MOD_FMR, string,(Para0),(Para1))
#else
#define FMR_TRACE(trace_class,string) kal_trace(TRACE_INFO,trace_class)
#define FMR_TRACE0(trace_class,string,Para0) kal_trace(TRACE_INFO,trace_class,(Para0))
#define FMR_TRACE1(trace_class,string,Para0,Para1) kal_trace(TRACE_INFO,trace_class,(Para0),(Para1))
#endif
typedef struct
{
	kal_uint16 RSSI;
	kal_uint16 ChannelNo;
	kal_bool skip;
}FMR_SCAN_Sort_Data;

#if (FMR_ENHANCED_SCAN==1)
typedef struct
{
    kal_int32 RSSI;
    kal_uint16 ChannelNo;
}FMR_SOFTE_MUTE_SCAN_Data;
typedef enum
{
	FMR_Audio_FalseAlarm = 0,
	FMR_Audio_Acceptable,
	FMR_Audio_Better,
	FMR_Audio_MBetter,
	FMR_Audio_Best,
	FMR_Audio_End
}FMR_Audio_Level_e;
#endif

#if (defined(MT6616) && defined(FM_INTERFACE_HCI))
typedef struct{
   kal_uint8 buffer[256];
   kal_uint16 cmd;
   kal_uint16 event;
}HCI_data;
#endif   
typedef struct{
   void (*callback)( kal_int16 wFreq, kal_uint8 wSignal_Lv, kal_bool is_vlaid );
   kal_bool bHWsearchStop;
   kal_bool is_preset;
   kal_bool is_searching;
   kal_bool is_up;
   kal_int16 wSpace;
#if (defined(MT6616) && defined(FM_INTERFACE_HCI))
   HCI_data FM_HCI_data;
#endif   
}FMR_data;

/* FM Radio Interface */
void  ktLock( void );
void  ktUnlock( void );
void  FMDrv_PowerOnReset(void);
void  FMDrv_PowerOffProc(void);
kal_uint8 FMDrv_ValidStop(kal_int16 freq, kal_int8 signalvl, kal_bool is_step_up);
void  FMDrv_SetFreq_Original(kal_int16 curf );
void  FMDrv_SetFreq(kal_int16 curf );
kal_uint16 FMDrv_GetSigLvl(kal_int16 curf );
kal_uint16 FMDrv_GetPamdLvl(kal_int16 curf );
void  FMDrv_Mute(kal_uint8 mute);
void  FMDrv_ChipInit(void);
kal_bool  FMDrv_IsChipValid(void);
void  FMDrv_SetVolumeLevel(kal_uint8 level);
void  FMDrv_EvaluateRSSIThreshold(void);
void  FMDrv_radio_item_info(kal_uint16 group_idx, kal_uint16 item_idx, kal_uint32 item_value);
kal_uint16 FMDrv_GetIF(kal_uint16 curf);
kal_uint16 FMDrv_ReadByte(kal_uint8 addr);
kal_bool FMDrv_WriteByte(kal_uint8 addr, kal_uint16 data);
void FMDrv_SoftMuteOnOff(kal_bool On_Off);
void FMDrv_SoftMuteStage(kal_uint8 stage);
void FMDrv_StereoBlendStage(kal_uint8 stage);
kal_uint8 FMDrv_GetChipID(void);
kal_uint8 FMDrv_Get_H_L_side(kal_int16 curf);
kal_uint8 FMDrv_Get_stereo_mono(void);
kal_uint8 FMDrv_HWSpolling(kal_uint16 *curf, kal_uint8 *is_valid);
void FMDrv_HWSearch(kal_int16 freq, kal_bool is_step_up, kal_int16 space, kal_bool is_preset);
void FMGetScanTbl(kal_uint16 *CH_TBL);
void FMDrv_GetIntr(kal_uint16 *dataRead);
void FMDrv_GetScanTbl(kal_uint16 *BitMapData, kal_uint8 offset);
kal_bool FMR_RDS_HWChk(void);
kal_bool FMDrv_SetAntennaType(kal_uint8 ATAType);
kal_uint8 FMDrv_GetAntennaType(void);
void FMDrv_ClrIntr(void);
#if (defined(FMR_GET_CAP_SUPPORT))
kal_uint32 FMDrv_GetCapArray(void);
#endif
#if (defined(FMR_SW_RSSI_SORT)&&(FMR_ENHANCED_SCAN==0))
kal_bool FMDrv_SCAN_Sort_Tune(FMR_SCAN_Sort_Data *p_SortData,kal_uint8 rChannelNo);
void FMDrv_SCAN_Sort_Tune_Internal(kal_uint16 freq,kal_uint16 *p_RSSI);
static void FMR_SCAN_Sort(void);
kal_bool FMR_Seek_Eliminate(kal_uint16 rFreq);
kal_bool FMDrv_Seek_Eliminate(kal_uint16 rFreq, kal_uint16 RSSI);
#endif
#if(FMR_ENHANCED_SCAN==1)
void FMDrv_PresetScan(void);
void FMDrv_RestorePresetScan(void);
kal_bool FMDrv_GetSofteMute(kal_uint16 freq,kal_int32 *rRSSI);
void FMDrv_GetSeekOrigFreq(kal_uint16 *OriFreq);
kal_bool FMDrv_SevereDensense(kal_uint16 freq,kal_int32 rRSSI);
#endif
static kal_bool FMR_GetScanTbl_Internal(kal_uint16 *BitMap);
kal_int16 FMDrv_GetMR(void);
kal_uint32 FMDrv_GetRSSITH(kal_uint8 type);
void FMDrv_SetRSSITH(kal_uint8 type,kal_uint32 value);
kal_int32 FMDrv_RSSI_Hex2Db(kal_uint32 Hex);
kal_uint32 FMDrv_RSSI_Db2Hex(kal_int32 Db);
void FMDrv_Force_Mono(void);
void FMDrv_Force_Stereo(void);
#if defined(MT6255FM)||defined(MT6256FM)
void FMDrv_Freq_CQI_Log(void);
#endif		
#if (defined(MT6250FM) || defined(MT6260FM) || defined(MT6261FM))
void FMDrv_Freq_CQI_Log(kal_uint8 FileCnt);
void FMDrv_Freq_CQI_Through_Time_Log(kal_uint8 FreqHigh, kal_uint8 FreqLow, kal_uint8 sTime);
void FMDrv_EM_Set_AudioLevel(kal_uint8 AudioLevel);
void FMDrv_EM_Set_RSSI(kal_uint8 RSSILevel);
void FMDrv_EM_Set_DesenseLevel(kal_uint8 DesenseLevel);
#endif		
void FMDrv_JammerScan(void);
#if (defined(MT6250FM))
void FM_GET_HOPPING_INDEX(kal_int16 Freq,kal_int16*Index);
#endif
#if defined(__CLASSK_CP_SUPPORT__)
kal_bool FMDrv_ClassK_Permit(void);
#endif
#endif
