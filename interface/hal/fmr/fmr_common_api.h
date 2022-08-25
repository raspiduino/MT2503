/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *	fmr_common_api.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file declares all FM radio public API.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __FMR_COMMON_API_H__
#define __FMR_COMMON_API_H__

void  FMR_PowerOn(void);
void  FMR_PowerOff(void);
void FMR_PollHWSearch( void *data );
kal_bool FMR_GetScanTbl(kal_uint16 *BitMapData);
kal_bool FMR_HWSearch( void (*callback)( kal_int16 wFreq, kal_uint8 wSignal_Lv, kal_bool is_valid ), kal_int16 wStartFreq, kal_bool is_up, kal_int16 wSpace, kal_bool is_preset );
void FMR_HWSearchForceStop(void);
kal_uint8 FMR_ValidStop(kal_int16 freq, kal_int8 signalvl, kal_bool is_step_up);
void  FMR_SetFreq(kal_int16 curf);
kal_uint8 FMR_PamdLevel( kal_int16 curf );
kal_uint8 FMR_GetSignalLevel( kal_int16 curf );
void  FMR_Mute(kal_uint8 mute);
void FMR_SetOutputDevice( kal_uint8 device );
void  FMR_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index );
#if defined(__GAIN_TABLE_SUPPORT__)
void FMR_SetOutputGainControl( kal_uint32 gain );
void  FMR_SetDualPathGainControl(kal_uint32 ext_amp_gain );
#endif
kal_bool FMR_IsChipValid(void);
kal_bool FMR_IsActive(void);
void FMR_EvaluateRSSIThreshold(void);
void FMR_Radio_EngineerMode(kal_uint16 group_idx, kal_uint16 item_idx, kal_uint32 item_value);
kal_uint16 FMR_GetIFCount(kal_int16 curf);
kal_uint32 FMR_GetCapArray(void);
kal_uint16 FMR_ReadByte(kal_uint8 addr);
void FMR_WriteByte(kal_uint8 addr, kal_uint16 data);
void FMR_SoftMuteOnOff(kal_uint8 On_Off);
void FMR_SoftMuteStage(kal_uint8 stage);
void FMR_StereoBlendStage(kal_uint8 stage);
kal_uint8 FMR_GetChipID(void);
kal_uint8 FMR_Get_H_L_side(kal_int16 curf);
kal_uint8 FMR_Get_stereo_mono(void);
kal_uint8 FMR_CheckOption(void);
kal_uint8 FMR_GetRXFilterBW(void);
kal_uint8 FMR_GetMagRatio(void);
void FMR_SetAntennaType(kal_uint8 ata_type);
kal_int8 FMR_GetAntennaType(void);

/**For EM FM radio new feature**/
typedef enum
{
	FMR_SOUND_TRACK_TYPE_MONO,
	FMR_SOUND_TRACK_TYPE_STEREO,
	FMR_SOUND_TRACK_TYPE_END
}fmr_sound_track_type_enum;
fmr_sound_track_type_enum FMR_Get_Sound_Track(void);
void FMR_Force_Mono(void);
void FMR_Force_Stereo(void);
typedef enum
{
	FMR_ANTENNA_TYPE_LONG,
	FMR_ANTENNA_TYPE_SHORT,
	FMR_ANTENNA_TYPE_END
}fmr_antenna_type_enum;
void FMR_Set_AntennaType(fmr_antenna_type_enum type);
fmr_antenna_type_enum FMR_Get_AntennaType(void);
kal_uint32 FMR_Get_RSSI_Threshold(fmr_antenna_type_enum type);
void FMR_Set_RSSI_Threshold(fmr_antenna_type_enum type, kal_uint32 value);
kal_int32 FMR_RSSI_Hex2Db(kal_uint32 Hex);
kal_uint32 FMR_RSSI_Db2Hex(kal_int32 Db);
kal_uint32 FMR_Get_Param(kal_uint8* param);
void FMR_Set_Param(kal_uint8* param, kal_uint32 len);
void FMR_RDS_Enable(void);
void FMR_RDS_Disable(void);
kal_uint32 FMR_RDS_GetBLER(void);

/******phase out interface******/
void FMR_AutoSearch(kal_uint8 dir, void(*fm_handler)(kal_int16 *data));
kal_int16 FMR_ManualSearch(kal_uint8 dir);
kal_int16 FMR_GetFreq(void);
void  FMR_Mono(kal_uint8 MS);
void  FMR_Standby(kal_uint8 standby);

#endif
