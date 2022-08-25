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
 *  meta_customize.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains ft task customized funcitons in META mode.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _META_CUSTOMIZE_H_
#define _META_CUSTOMIZE_H_
#if defined(__MTK_TARGET__)
#if !defined(__MAUI_BASIC__)
#include "kal_general_types.h"
#include "ft_msg_audio.h"
/********************************************************************************
 * MODEM BSP API
 *******************************************************************************/
kal_uint16  custom_meta_check_must_backup_lid_array(kal_bool bCheckImeiFlag);
kal_uint16  custom_meta_get_check_lid_num(void);
kal_uint16  custom_meta_get_enum_by_index(kal_uint16 index);
kal_bool custom_ft_util_check_if_isp_support(void);
kal_bool custom_ft_util_check_if_usb_enable_support(void);
kal_uint16 custom_ft_get_calflag_enum(void);
kal_bool custom_ft_audio_query_iir_support(void);
kal_bool custom_ftaudio_set_iir_coeff_v3(void * buffer, kal_uint32 bufferLength);
kal_uint32 custom_ft_get_aud_max_volume_type(void);
kal_uint8 custom_ft_get_audio_speech_mode_num(void);
kal_uint8 custom_ft_get_audio_max_enhance_mode_para_num(void);
const WCHAR* custom_ft_get_audio_speech_mode_title(kal_uint8 idx);
kal_uint16 custom_ft_get_audio_total_title_length(void);
kal_bool custom_ft_get_speech_mode_table_support(void);
/***********************************
 * RF calibration history query API
 **********************************/
kal_uint16 custom_ft_get_rf_cal_env_enum(void);
kal_uint16 custom_ft_get_rf_loss_setting_enum(void);
kal_uint16 custom_ft_get_rf_test_power_result_enum(void);
void Custom_META_USBVirtualComDisconnect(void);
kal_bool Custom_META_SdsSupported(void);
kal_uint32 Custom_META_ControlBufferSize(void);
/****************************************************************************
 * Dual-mic support function
 ****************************************************************************/
kal_bool Custom_META_DualMicSupported(void);
/****************************************************************************
 * FT memory buffer
 ****************************************************************************/
kal_uint32 Custom_META_GetCustomMemoryPoolSize(void);
kal_uint8* Custom_META_GetCustomMemoryPool(void);
void* Custom_META_GetCustomMemoryPoolArrangement(void);

/********************************************************************************
 * Non MODEM BSP API
 *******************************************************************************/

/****************************************************************************
 * MATV custom wrapper function (START)
 ****************************************************************************/
kal_bool Custom_META_ATV_Support_Option(void);
kal_bool   Custom_META_matv_init(void);
kal_bool   Custom_META_matv_shutdown(void);
void       Custom_META_matv_set_country(kal_uint8 country);
void       Custom_META_matv_register_callback(void* cb_param,
                void * auto_cb,
                void * full_cb,
                void * finish_cb,
                void * audfmt_cb);
void       Custom_META_matv_chscan(kal_uint8 mode);
void       Custom_META_matv_chscan_stop(void);
kal_bool   Custom_META_matv_get_chtable(kal_uint8 ch, void *entry);
kal_bool   Custom_META_matv_set_chtable(kal_uint8 ch, void *entry);
void       Custom_META_matv_change_channel(kal_uint8 ch);
kal_int32  Custom_META_matv_get_chipdep(kal_uint8 item);
/****************************************************************************
 * MATV custom wrapper function (END)
 ****************************************************************************/
/****************************************************************************
 * CMMB custom wrapper function (START)
 ****************************************************************************/
kal_bool Custom_META_CmmbSupported(void);
/****************************************************************************
 * CMMB custom wrapper function (END)
 ****************************************************************************/
/****************************************************************************
 * FMR custom wrapper function (START)
 ****************************************************************************/
void Custom_META_FMR_RDS_INTR_OnOff(kal_bool On_Off);
kal_bool Custom_META_FMR_RDS_HWChk(void);
void Custom_META_FMR_RDS_OnOff(kal_bool On_Off);
void Custom_META_FMR_RDS_BlerCheck(void * param);
void Custom_META_FMR_RDS_Open(void (*callback)(kal_uint16 event));
void Custom_META_FMR_RDS_Get_Block_Value(kal_uint16 *buffer);
kal_uint16 Custom_META_FMR_RDS_Get_GoodBlock_Counter(void);
kal_uint16 Custom_META_FMR_RDS_Get_BadBlock_Counter(void);
kal_uint16 Custom_META_FMR_RDS_Get_BadBlock_Ratio(void);
void Custom_META_FMR_RDS_Reset_Block_Counter(void);
void Custom_META_FMR_RDS_Read_Group_Counter(kal_uint16 *pstGroupCnt);
void Custom_META_FMR_RDS_Reset_Group_Counter(void);
void Custom_META_FMR_RDS_ChkEvent(void * param);
void Custom_META_FMR_RDS_GetStatus(kal_uint8 *flag, kal_uint16 *buffer);
void Custom_META_FMR_RDS_GetInfo(kal_uint8 Cmd, kal_uint16 *buffer, kal_uint8 *bufsize);
void Custom_META_FMR_HCI_Event_Hdlr(kal_bool isReadyRead);
void Custom_META_FMR_EINTChk(void);
/****************************************************************************
 * FMR custom wrapper function (END)
 ****************************************************************************/
/****************************************************************************
 * DMNR custom wrapper function (START)
 ****************************************************************************/
kal_bool Custom_META_FT_PCMRB_Init( FT_PCMRB *rb, kal_int16 *buffer, kal_int32 buffer_size );
kal_int32 Custom_META_FT_PCMRB_GetFreeSpace( FT_PCMRB *rb );
kal_int32 Custom_META_FT_PCMRB_GetDataCount( FT_PCMRB *rb );
void Custom_META_FT_PCMRB_Write( FT_PCMRB *dest_rb, kal_int16 *src_buffer, kal_int32 size );
void Custom_META_FT_PCMRB_Read( FT_PCMRB *src_rb, kal_int16 *dest_buffer, kal_int32 size );
void Custom_META_FT_PCMRB_GetWriteBlock( FT_PCMRB *dest_rb, kal_int16 **write_ptr, kal_int32 *write_cnt );
void Custom_META_FT_PCMRB_GetReadBlock( FT_PCMRB *src_rb, kal_int16 **read_ptr, kal_int32 *read_cnt );
void Custom_META_FT_PCMRB_ShiftWritePointer( FT_PCMRB *rb, kal_int32 shamt );
void Custom_META_FT_PCMRB_ShiftReadPointer( FT_PCMRB *rb, kal_int32 shamt );
META_ECHO_LOOP_HANDLE* Custom_META_FtEchoLoop_GetHandle ( kal_uint32 dir, kal_uint8 *buffer, kal_int32 buffer_size );
kal_int32 Custom_META_FtStartDualMicControl(const FT_DUALMIC_CONTROL_T* param);
kal_int32 Custom_META_FtStartDualMicEchoTestPreSetting(const ft_l4aud_ex_echoloop_request_T *request );
kal_int32 Custom_META_FtStartDualMicEchoTest(ft_l4aud_ex_echoloop_request_T *request);
kal_int32 Custom_META_FtStopDualMicEchoTest(void* event);
void Custom_META_FtQueryDualMicEchoTest(FT_L4AUD_EX_CNF *l4aud_ex_cnf);
kal_int32 Custom_META_FtFreePcm2WayBuffer( FT_AUTO_RECORD_T* auto_record, FT_AUTO_SPEAK_T* auto_speak );
kal_int32 Custom_META_FtGetPcm2WayBuffer( FT_AUTO_RECORD_T* auto_record, FT_AUTO_SPEAK_T* auto_speak );
void Custom_META_FtAutoSpeakCallback( void *host_data, META_ECHO_LOOP_EVENT event );
void Custom_META_FtAutoSpeakGetDataFromFileToRB(kal_uint32 arg1, void *arg2);
kal_int32 Custom_META_FtAutoSpeakOpenFile( FT_AUTO_SPEAK_T* auto_speak );
void Custom_META_FtAutoRecCallback( void *host_data, META_ECHO_LOOP_EVENT event );
void Custom_META_FtAutoRecGetDataFromRBToFile( kal_uint32 arg1, void *arg2 );
kal_int32 Custom_META_FtAutoRecOpenFile( FT_AUTO_RECORD_T* auto_record );
kal_int32 Custom_META_FtAutoRecWriteFileHeader(void);
kal_int32 Custom_META_FtWriteInitParameter(void);
void Custom_META_FtDualMicRecordingInHisr( void );
void Custom_META_FtDualMicEchoTestLoopbackInHisr( void );
void Custom_META_FtDualMicRecordHandler( FT_AUTO_RECORD_T* autoRecord, kal_uint32 frameSize);
void Custom_META_FtDualMicSpeakHandler( FT_AUTO_SPEAK_T* autoSpeak, kal_uint32 frameSize);
void Custom_META_FtSendDualMicEchoTestStarted(void);
/****************************************************************************
 * DMNR custom wrapper function (END)
 ****************************************************************************/
#endif // #if !defined(__MAUI_BASIC__)
#endif // #if defined(__MTK_TARGET__)
#endif /* _META_CUSTOMIZE_H_ */
