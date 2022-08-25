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
 *  meta_customize.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains ft task customized bt funcitons in META mode.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined(__MTK_TARGET__)
#if !defined(__MAUI_BASIC__)
/****************************************************************************
 * KAL
 ***************************************************************************/
#include "kal_general_types.h"
#include "app_ltlcom.h"
#include "init.h"
/****************************************************************************
 * NVRAM
 ***************************************************************************/
#include "nvram_enums.h"
#include "nvram_data_items.h"
#include "nvram_interface.h"
#include "adc_nvram_def.h"
/****************************************************************************
 * MODEM BSP
 ***************************************************************************/
#include "ft_msg.h"
#include "l1audio.h"
#include "meta_customize.h"
/****************************************************************************
 * Non MODEM BSP
 ***************************************************************************/
//#if !defined(__MODEM_COMPONENT__) && !defined(__MODEM_PRODUCT__)
#include "aud_defs.h"
#include "fmr\fmr_common_api.h"
#include "fmr\fmr_rds_api.h"
#include "matvctrl.h"
//#endif // #if !defined(__MODEM_COMPONENT__) && !defined(__MODEM_PRODUCT__)

nvram_lid_enum  meta_must_backup_lid_array[ ] =
{
#ifndef __MAUI_BASIC__
	  // RF part
	  NVRAM_EF_L1_AGCPATHLOSS_LID
	  
#ifdef __GSM850__
    ,NVRAM_EF_L1_RAMPTABLE_GSM850_LID
    ,NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID
#endif
//#if defined(__PGSM900__)||defined(__EGSM900__)||defined(__RGSM900__)
#ifdef __EGSM900__
    ,NVRAM_EF_L1_RAMPTABLE_GSM900_LID
    ,NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID
#endif
#ifdef __DCS1800__
    ,NVRAM_EF_L1_RAMPTABLE_DCS1800_LID
    ,NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID
#endif
#ifdef __PCS1900__
    ,NVRAM_EF_L1_RAMPTABLE_PCS1900_LID
    ,NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID
#endif
    
#if defined(__EPSK_TX__)
#ifdef __GSM850__
    ,NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID
    ,NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID
#endif
//#if defined(__PGSM900__)||defined(__EGSM900__)||defined(__RGSM900__)
#ifdef __EGSM900__
    ,NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID
    ,NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID
#endif
#ifdef __DCS1800__    
    ,NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_LID
    ,NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID
#endif
#ifdef __PCS1900__
    ,NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID
    ,NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID
#endif    
#endif /* __EPSK_TX__ */ 
    ,NVRAM_EF_L1_AFCDATA_LID
    ,NVRAM_EF_L1_TXIQ_LID
    ,NVRAM_EF_L1_RFSPECIALCOEF_LID
    ,NVRAM_EF_L1_CRYSTAL_AFCDATA_LID
    ,NVRAM_EF_L1_CRYSTAL_CAPDATA_LID
 
#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
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
#endif // #if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
   

#ifdef  __BTMODULE_MT6601__
    ,NVRAM_EF_BTRADIO_MT6601_LID
#endif
#ifdef  __BTMODULE_MT6611__
    ,NVRAM_EF_BTRADIO_MT6611_LID
#endif

#if defined(__WIFI_SUPPORT__) && defined(__CUSTOM_WIFI_FEATURES_SWITCH__)
    ,NVRAM_EF_WNDRV_TX_POWER_2400M_LID
    ,NVRAM_EF_WNDRV_TX_POWER_5000M_LID
    ,NVRAM_EF_WNDRV_DAC_DC_OFFSET_LID
    ,NVRAM_EF_WNDRV_TX_ALC_POWER_LID
    ,NVRAM_EF_WNDRV_ALC_SLOPE_LID
    ,NVRAM_EF_WNDRV_MAC_ADDRESS_LID
#endif // #if defined(__WIFI_SUPPORT__) && defined(__CUSTOM_WIFI_FEATURES_SWITCH__)

#ifdef __AST_TL1_TDD__
    ,NVRAM_EF_AST_TL1_TEMP_DAC_LID
    ,NVRAM_EF_AST_TL1_AFC_DATA_LID
    ,NVRAM_EF_AST_TL1_PATHLOSS_BAND33_35_37_39_LID
    ,NVRAM_EF_AST_TL1_PATHLOSS_BAND34_LID
    ,NVRAM_EF_AST_TL1_PATHLOSS_BAND36_LID
    ,NVRAM_EF_AST_TL1_PATHLOSS_BAND38_LID
    ,NVRAM_EF_AST_TL1_PATHLOSS_BAND40_LID
    ,NVRAM_EF_AST_TL1_TXDAC_BAND33_35_37_39_LID
    ,NVRAM_EF_AST_TL1_TXDAC_BAND34_LID
    ,NVRAM_EF_AST_TL1_TXDAC_BAND36_LID
    ,NVRAM_EF_AST_TL1_TXDAC_BAND38_LID
    ,NVRAM_EF_AST_TL1_TXDAC_BAND40_LID
#endif  // end of __AST_TL1_TDD__
    
    
// others
	  ,NVRAM_EF_ADC_LID
#ifndef __TC01__  // for general customer, keep the original policy: check barcode, imei, and sml
	  ,NVRAM_EF_BARCODE_NUM_LID

// special: 
    
	  ,NVRAM_EF_SML_LID
	  ,NVRAM_EF_IMEI_IMEISV_LID  // for exception handling, must be put in the last position
#endif //#ifndef __TC01_

#else
    0  // at least one element
#endif //#ifndef __MAUI_BASIC__

};

kal_uint16  custom_meta_check_must_backup_lid_array(kal_bool bCheckImeiFlag)
{
#ifndef __MAUI_BASIC__
      kal_uint16 i;
    kal_char *pcStrPrefix;
      kal_char *pcStrVerNo;
    kal_uint16 lid_num = custom_meta_get_check_lid_num();//sizeof(meta_must_backup_lid_array)/ sizeof(nvram_lid_enum);
    kal_bool error_flag = KAL_FALSE;
    kal_uint16 stop_index = 0;
    
#ifndef __TC01__	  
	  for(i=0; i<lid_num-1; i++)  // imei exclusively
#else
/* under construction !*/
#endif
    {
        if(NVRAM_IO_ERRNO_OK != nvram_check_backup(meta_must_backup_lid_array[i], &pcStrPrefix, &pcStrVerNo))
        {
                 error_flag = KAL_TRUE;
                 stop_index = i;
                 break;
        }

    }
#ifndef __TC01__
    if(i==lid_num-1) // pass the all check except IMEI
    {
        if(bCheckImeiFlag)  // need to check imei
        {
        	 	if(NVRAM_IO_ERRNO_OK != nvram_check_backup(meta_must_backup_lid_array[i], &pcStrPrefix, &pcStrVerNo))
        	 	  	   error_flag =KAL_TRUE;  	
        }
        stop_index = i;
    }
#endif
    
    if(error_flag == KAL_TRUE)
    {
          return stop_index;
    }
    else
    {
         return lid_num; // means success!
    }
#else
    return 0;
#endif // #ifndef __MAUI_BASIC__

}

kal_uint16  custom_meta_get_check_lid_num(void)
{
    return sizeof(meta_must_backup_lid_array)/sizeof(nvram_lid_enum);
}

kal_uint16  custom_meta_get_enum_by_index(kal_uint16 index)
{
    if(index < custom_meta_get_check_lid_num())
        return (kal_uint16)meta_must_backup_lid_array[index];
    else
          return custom_meta_get_check_lid_num();
}


kal_bool custom_ft_util_check_if_isp_support()
{
      //#if defined(ISP_SUPPORT) && !defined(YUV_SENSOR_SUPPORT)
      #if defined(ISP_SUPPORT)
        return KAL_TRUE;
      #else
        return KAL_FALSE;
      #endif
}

kal_bool custom_ft_util_check_if_usb_enable_support()
{
    #if defined(__USB_ENABLE__)
        return KAL_TRUE;
    #else
        return KAL_FALSE;
    #endif
}
kal_uint16 custom_ft_get_calflag_enum(void)
{
#if !defined (NVRAM_NOT_PRESENT)	
	 return NVRAM_EF_CAL_FLAG_LID;
#else
   return 0;
#endif
}


// --- for the request: FT_L4AUD_EX_OP_SET_ACF_IIR
kal_bool custom_ft_audio_query_iir_support(void)
{
#if  defined(__BES_LOUDNESS_SUPPORT__)  && !defined(__SMART_PHONE_MODEM__)
	return KAL_TRUE;
#else
	return KAL_FALSE;
#endif
	
}
kal_bool custom_ftaudio_set_iir_coeff_v3(void * buffer, kal_uint32 bufferLength)
{
#if defined(__BES_LOUDNESS_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    Media_SetBesLoudnessCustomCoeff_v3(buffer, bufferLength);
    return KAL_TRUE;
#else // #if defined(__BES_LOUDNESS_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    return KAL_FALSE;
#endif
}
void Custom_META_FMR_RDS_INTR_OnOff(kal_bool On_Off)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
    FMR_RDS_INTR_OnOff(On_Off);
#endif
}

kal_bool Custom_META_FMR_RDS_HWChk(void)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
    FMR_RDS_HWChk();
#endif
    return KAL_TRUE;
}

void Custom_META_FMR_RDS_OnOff(kal_bool On_Off)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
    FMR_RDS_OnOff(On_Off);
#endif
}

void Custom_META_FMR_RDS_BlerCheck(void * param)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
    FMR_RDS_BlerCheck(param);
#endif
}

void Custom_META_FMR_RDS_Open(void (*callback)(kal_uint16 event))
{
#ifdef __FM_RADIO_RDS_SUPPORT__
    FMR_RDS_Open(callback);
#endif
}

void Custom_META_FMR_RDS_Get_Block_Value(kal_uint16 *buffer)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
    FMR_RDS_Get_Block_Value(buffer);
#endif
}

kal_uint16 Custom_META_FMR_RDS_Get_GoodBlock_Counter(void)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
    return FMR_RDS_Get_GoodBlock_Counter();
#else
    return 0;
#endif
}
kal_uint16 Custom_META_FMR_RDS_Get_BadBlock_Counter(void)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
    return FMR_RDS_Get_BadBlock_Counter();
#else
    return 0;
#endif
}
kal_uint16 Custom_META_FMR_RDS_Get_BadBlock_Ratio(void)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
    return FMR_RDS_Get_BadBlock_Ratio();
#else
    return 0;
#endif
}
void Custom_META_FMR_RDS_Reset_Block_Counter(void)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
    FMR_RDS_Reset_Block_Counter();
#endif
}
void Custom_META_FMR_RDS_Read_Group_Counter(kal_uint16 *pstGroupCnt)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
    FMR_RDS_Read_Group_Counter(pstGroupCnt);
#endif
}
void Custom_META_FMR_RDS_Reset_Group_Counter(void)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
    FMR_RDS_Reset_Group_Counter();
#endif
}
void Custom_META_FMR_RDS_ChkEvent(void * param)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
    FMR_RDS_ChkEvent(param);
#endif
}
void Custom_META_FMR_RDS_GetStatus(kal_uint8 *flag, kal_uint16 *buffer)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
    FMR_RDS_GetStatus(flag, buffer);
#endif
}

void Custom_META_FMR_RDS_GetInfo(kal_uint8 Cmd, kal_uint16 *buffer, kal_uint8 *bufsize)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
    FMR_RDS_GetInfo((RdsCmd)Cmd, buffer, bufsize);
#endif
}

void Custom_META_FMR_HCI_Event_Hdlr(kal_bool isReadyRead)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
#if defined(MT6616)
    FMR_HCI_Event_Hdlr(isReadyRead);
#endif
#endif
}
void Custom_META_FMR_EINTChk(void)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
    FMR_EINTChk();
#endif
}

kal_bool Custom_META_ATV_Support_Option(void)
{
#if defined(__ATV_SUPPORT__)
    return KAL_TRUE;
#else // #if defined(__ATV_SUPPORT__)
    return KAL_FALSE;
#endif
}

/****************************************************************************
 * MATV custom wrapper function (START)
 ****************************************************************************/
kal_bool   Custom_META_matv_init(void)
{
#if defined(__ATV_SUPPORT__)
    return matv_init();
#else // #if defined(__ATV_SUPPORT__)
    return KAL_TRUE;
#endif
}
kal_bool   Custom_META_matv_shutdown(void)
{
#if defined(__ATV_SUPPORT__)
    return matv_shutdown();
#else // #if defined(__ATV_SUPPORT__)
    return KAL_TRUE;
#endif
}
void       Custom_META_matv_set_country(kal_uint8 country)
{
#if defined(__ATV_SUPPORT__)
    matv_set_country(country);
#endif // #if defined(__ATV_SUPPORT__)
}
void       Custom_META_matv_register_callback(void* cb_param,
                void * auto_cb,
                void * full_cb,
                void * finish_cb,
                void * audfmt_cb)
{
#if defined(__ATV_SUPPORT__)
    matv_register_callback(cb_param,
                (matv_autoscan_progress_cb)auto_cb,
                (matv_fullscan_progress_cb)full_cb,
                (matv_scanfinish_cb)finish_cb,
                (matv_audioformat_cb)audfmt_cb);
#endif // #if defined(__ATV_SUPPORT__)
}
void       Custom_META_matv_chscan(kal_uint8 mode)
{
#if defined(__ATV_SUPPORT__)
    matv_chscan(mode);
#endif // #if defined(__ATV_SUPPORT__)
}
void       Custom_META_matv_chscan_stop(void)
{
#if defined(__ATV_SUPPORT__)
    matv_chscan_stop();
#endif // #if defined(__ATV_SUPPORT__)
}
kal_bool   Custom_META_matv_get_chtable(kal_uint8 ch, void *entry)
{
#if defined(__ATV_SUPPORT__)
    return matv_get_chtable(ch, entry);
#else // #if defined(__ATV_SUPPORT__)
    return KAL_TRUE;
#endif
}
kal_bool   Custom_META_matv_set_chtable(kal_uint8 ch, void *entry)
{
#if defined(__ATV_SUPPORT__)
    return matv_set_chtable(ch, entry);
#else // #if defined(__ATV_SUPPORT__)
    return KAL_TRUE;
#endif
}
void       Custom_META_matv_change_channel(kal_uint8 ch)
{
#if defined(__ATV_SUPPORT__)
    matv_change_channel(ch);
#endif // #if defined(__ATV_SUPPORT__)
}
kal_int32  Custom_META_matv_get_chipdep(kal_uint8 item)
{
#if defined(__ATV_SUPPORT__)
    return matv_get_chipdep(item);
#else // #if defined(__ATV_SUPPORT__)
    return 0;
#endif
}
/****************************************************************************
 * MATV custom wrapper function (END)
 ****************************************************************************/
/*******************************************************************************
 * FUNCTION
 *   Custom_META_IsAllowedLimitedStateOperation
 *
 * DESCRIPTION
 *   Customizable limited state META mode operation check function
 *
 * CALLS
 *   INT_GetMetaModeSrc
 *
 * PARAMETERS
 *   ptrMsg the ilm_struct of the request message
 *
 * RETURNS
 *   The indicator of the operation is allowed or denied
 *
 *******************************************************************************/
kal_bool Custom_META_IsAllowedLimitedStateOperation(ilm_struct* ptrMsg)
{
#ifdef __TOOL_ACCESS_CTRL__
    // default allowed
    kal_bool allowed = KAL_TRUE;
    FT_H * ft_header = NULL;
    MODE_ENTRY_SRC mode = INT_GetMetaModeSrc();
    /*********************************
     * define more limited state below
     **********************************/
    if(E_BLSUSB == mode)
    {
        ft_header=(FT_H *)(ptrMsg->local_para_ptr);
        // check the operation is basic operation or not
        // non-basic operations can be customized
        if(KAL_FALSE == FT_META_IsBasicOperation(ft_header->ft_msg_id))
        {
            switch (ft_header->ft_msg_id)
            {
                /*******************************************************
                 * Add more allowed operations below for E_BLSUSB state
                 * message type id defined in interface\meta\ft_msg.h
                 * enum type FT_MESSAGE_ID
                 *******************************************************/
                case FT_FAT_OPERATION_ID:
                    allowed = KAL_TRUE;
                    break;
                default:
                    // if the state is limited state, default denied
                    allowed = KAL_FALSE;
                    break;
            }
        }
    }
    /*********************************
     * define more limited state below
     **********************************/
    // else if(...)
    // {
    // }
    return allowed;
#else // #ifdef __TOOL_ACCESS_CTRL__
    return KAL_TRUE;
#endif
}
kal_uint16 custom_ft_get_rf_cal_env_enum(void)
{
#ifdef __TC01__
/* under construction !*/
#else
    return 0;
#endif
}
kal_uint16 custom_ft_get_rf_loss_setting_enum(void)
{
#ifdef __TC01__
/* under construction !*/
#else
    return 0;
#endif
}
kal_uint16 custom_ft_get_rf_test_power_result_enum(void)
{
#ifdef __TC01__
/* under construction !*/
#else
    return 0;
#endif
}
void Custom_META_USBVirtualComDisconnect(void)
{
#if defined(__USB_ENABLE__)
    DCL_BOOL dcl_data = DCL_TRUE;
    DCL_HANDLE  usb_dcl_handle;
    usb_dcl_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);
    DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_PDN_ENABLE, (DCL_CTRL_DATA_T  *)&dcl_data);
    DclUSB_DRV_Close(usb_dcl_handle);
#endif // #if defined(__USB_ENABLE__)
}
/**
 * This function will return the number audio volume type
 *
 * usage: custom_ft_get_audio_speech_mode_num();
 * @return number of volume type
 */
kal_uint32 custom_ft_get_aud_max_volume_type(void)
{
#ifdef __GAIN_TABLE_SUPPORT__
    return AUD_MAX_VOLUME_TYPE;
#else // #ifdef __GAIN_TABLE_SUPPORT__
    return 0;
#endif // #ifndef __GAIN_TABLE_SUPPORT__
}
/**
 * This function will return the number of speech mode.
 *
 * usage: custom_ft_get_audio_speech_mode_num();
 * @return number of speech mode
 */
kal_uint8 custom_ft_get_audio_speech_mode_num(void)
{
#ifdef __SPEECH_MODE_TABLE_SUPPORT__
    return NUM_SPEECH_MODE;
#else
    return 0;
#endif // __SPEECH_MODE_TABLE_SUPPORT__
}
/**
 * This function will return the max number of parameters for speech modes.
 *
 * usage: custom_ft_get_audio_max_enhance_mode_para_num();
 * @return maximum number of parameters for speech modes
 */
kal_uint8 custom_ft_get_audio_max_enhance_mode_para_num(void)
{
#ifdef __SPEECH_MODE_TABLE_SUPPORT__
    return NUM_MAX_ENHANCE_MODE_PARAS;
#else
    return 0;
#endif // __SPEECH_MODE_TABLE_SUPPORT__
}
/**
 * This function will return the max number of parameters for speech modes.
 *
 * usage: custom_ft_get_audio_speech_mode_title(0);
 * @para idx : speech mode index
 * @return type wchar string, speech mode title
 */
const WCHAR* custom_ft_get_audio_speech_mode_title(kal_uint8 idx)
{
#ifdef __SPEECH_MODE_TABLE_SUPPORT__
    return speech_mode_table[idx].title;
#else
    return 0;
#endif // __SPEECH_MODE_TABLE_SUPPORT__
}
/**
 * This function will calculate total speech mode title length and return it.
 *
 * usage: custom_ft_get_audio_total_title_length();
 * @return total sum of speech mode title length
 */
kal_uint16 custom_ft_get_audio_total_title_length(void)
{
#ifdef __SPEECH_MODE_TABLE_SUPPORT__
    kal_int8 i;	
    kal_uint16  total_length = 0;
    for(i=0;i<custom_ft_get_audio_speech_mode_num();i++)
    {
       total_length += (kal_wstrlen(custom_ft_get_audio_speech_mode_title(i))+1)*2;
    }
    return total_length;
#else
    return 0;
#endif // __SPEECH_MODE_TABLE_SUPPORT__
}
/**
 * This function will return the result of speech mode table support.
 *
 * usage: custom_ft_get_speech_mode_table_support();
 * @return KAL_TRUE, support speech mode table; KAL_FALSE, not support speech mode tabble 
 */
kal_bool custom_ft_get_speech_mode_table_support(void)
{
#ifdef __SPEECH_MODE_TABLE_SUPPORT__
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif // __SPEECH_MODE_TABLE_SUPPORT__}
}
kal_bool Custom_META_CmmbSupported(void)
{
#if defined(__CMMB_SUPPORT__)
    return KAL_TRUE;
#else // #if defined(__CMMB_SUPPORT__)
    return KAL_FALSE;
#endif // #if !defined(_CMMB_SUPPORT__)
}
/**
 * This function will return the result of SDS support.
 *
 * usage: Custom_META_SdsSupported();
 * @return KAL_TRUE, support SDS; KAL_FALSE, does not support SDS
 */
kal_bool Custom_META_SdsSupported(void)
{
#if defined(__SECURE_DATA_STORAGE__)
    return KAL_TRUE;
#else // #if defined(__SECURE_DATA_STORAGE__)
    return KAL_FALSE;
#endif // #if !defined(__SECURE_DATA_STORAGE__)
}
/**
 * This function is used for customization
 * The return value will be used as the maximum size of
 * control buffer used between META and target
 *
 * FT task will truncate the value to the actual
 * maximum value if the return value is over the actual
 * maximum value
 * (eg. system maximum value is 8K and the custom parameter
 * asks for 16K, the result is 8K)
 *
 * on the other hand, if the custom parameter asks fewer
 * than 2K, the FT task will override the value to 2K to
 * keep the legacy command compatible.
 * (eg. custom parameter is 1K, the FT task will override
 * the setting to 2K for backward compatible)
 */
kal_uint32 Custom_META_ControlBufferSize(void)
{
    return 8192;
}
/**
 * This function will return the result of dual-mic support.
 *
 * usage: Custom_META_DualMicSupported();
 * @return KAL_TRUE, support dual-mic; KAL_FALSE, does not support dual-mic
 */
kal_bool Custom_META_DualMicSupported(void)
{
#if defined(__DUAL_MIC_SUPPORT__)
    return KAL_TRUE;
#else // #if defined(__DUAL_MIC_SUPPORT__)
    return KAL_FALSE;
#endif // #if !defined(__DUAL_MIC_SUPPORT__)
}
/**
 * This function query the FT custom memory pool size
 * @return pool size
 */
#if defined(__DUAL_MIC_SUPPORT__) || defined(__CMMB_SUPPORT__)
#define META_CUSTOM_MEM_POOL_SIZE 512*1024
#else // #if defined(__DUAL_MIC_SUPPORT__) || defined(__CMMB_SUPPORT__)
#define META_CUSTOM_MEM_POOL_SIZE 4096
#endif // #if !defined(__DUAL_MIC_SUPPORT__) && !defined(__CMMB_SUPPORT__)
__align(4) kal_uint8 ft_ext_mem[META_CUSTOM_MEM_POOL_SIZE];
kal_uint32 Custom_META_GetCustomMemoryPoolSize(void)
{
    return META_CUSTOM_MEM_POOL_SIZE;
}
/**
 * This function return the pool arrangement
 */
static const kal_uint32 ft_subpool_size[8] = { 16384, 32768, 65536, 131072, 262144, 524288, 0xffffffff, 0 };
void* Custom_META_GetCustomMemoryPoolArrangement(void)
{
    if(Custom_META_GetCustomMemoryPoolSize() > 4096)
    {
        return (void*)ft_subpool_size;
    }
    else
    {
        return NULL;
    }
}
/**
 * This function get the custom memory pool address
 */
kal_uint8* Custom_META_GetCustomMemoryPool(void)
{
    return ft_ext_mem;
}
#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"
/****************************************************************************
 * DMNR custom wrapper function (START)
 ****************************************************************************/
kal_bool Custom_META_FT_PCMRB_Init( FT_PCMRB *rb, kal_int16 *buffer, kal_int32 buffer_size )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    return FT_PCMRB_Init(rb, buffer, buffer_size);
#else
    return KAL_FALSE; 
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
kal_int32 Custom_META_FT_PCMRB_GetFreeSpace( FT_PCMRB *rb )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    return Custom_META_FT_PCMRB_GetFreeSpace(rb);
#else
    return 0;
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
kal_int32 Custom_META_FT_PCMRB_GetDataCount( FT_PCMRB *rb )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    return FT_PCMRB_GetDataCount(rb);
#else
    return 0;
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
void Custom_META_FT_PCMRB_Write( FT_PCMRB *dest_rb, kal_int16 *src_buffer, kal_int32 size )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    FT_PCMRB_Write(dest_rb, src_buffer, size);  
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
void Custom_META_FT_PCMRB_Read( FT_PCMRB *src_rb, kal_int16 *dest_buffer, kal_int32 size )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    FT_PCMRB_Read(src_rb, dest_buffer, size);    
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
void Custom_META_FT_PCMRB_GetWriteBlock( FT_PCMRB *dest_rb, kal_int16 **write_ptr, kal_int32 *write_cnt )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    FT_PCMRB_GetWriteBlock(dest_rb, write_ptr, write_cnt);
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
void Custom_META_FT_PCMRB_GetReadBlock( FT_PCMRB *src_rb, kal_int16 **read_ptr, kal_int32 *read_cnt )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    FT_PCMRB_GetReadBlock(src_rb, read_ptr, read_cnt);  
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
void Custom_META_FT_PCMRB_ShiftWritePointer( FT_PCMRB *rb, kal_int32 shamt )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    FT_PCMRB_ShiftWritePointer(rb, shamt);   
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
void Custom_META_FT_PCMRB_ShiftReadPointer( FT_PCMRB *rb, kal_int32 shamt )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    FT_PCMRB_ShiftReadPointer(rb, shamt);   
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
META_ECHO_LOOP_HANDLE* Custom_META_FtEchoLoop_GetHandle ( kal_uint32 dir, kal_uint8 *buffer, kal_int32 buffer_size )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    return FtEchoLoop_GetHandle(dir, buffer, buffer_size);
#else
    return NULL;
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
kal_int32 Custom_META_FtStartDualMicControl(const FT_DUALMIC_CONTROL_T* param)
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    return FtStartDualMicControl(param);
#else
    return 0;
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
kal_int32 Custom_META_FtStartDualMicEchoTestPreSetting(const ft_l4aud_ex_echoloop_request_T *request )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    return FtStartDualMicEchoTestPreSetting(request);
#else
    return 0;
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
kal_int32 Custom_META_FtStartDualMicEchoTest(ft_l4aud_ex_echoloop_request_T *request)
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    return FtStartDualMicEchoTest(request);
#else
    return 0;
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
kal_int32 Custom_META_FtStopDualMicEchoTest(void* event)
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    return FtStopDualMicEchoTest(event);
#else
    return 0;
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
void Custom_META_FtQueryDualMicEchoTest(FT_L4AUD_EX_CNF *l4aud_ex_cnf)
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    FtQueryDualMicEchoTest(l4aud_ex_cnf);
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
kal_int32 Custom_META_FtFreePcm2WayBuffer( FT_AUTO_RECORD_T* auto_record, FT_AUTO_SPEAK_T* auto_speak )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    return FtFreePcm2WayBuffer(auto_record, auto_speak);
#else
    return 0;    
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
kal_int32 Custom_META_FtGetPcm2WayBuffer( FT_AUTO_RECORD_T* auto_record, FT_AUTO_SPEAK_T* auto_speak )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    return FtGetPcm2WayBuffer(auto_record, auto_speak);
#else
    return 0;    
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
void Custom_META_FtAutoSpeakCallback( void *host_data, META_ECHO_LOOP_EVENT event )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    FtAutoSpeakCallback(host_data, event);
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
void Custom_META_FtAutoSpeakGetDataFromFileToRB(kal_uint32 arg1, void *arg2)
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    FtAutoSpeakGetDataFromFileToRB(arg1, arg2);
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
kal_int32 Custom_META_FtAutoSpeakOpenFile( FT_AUTO_SPEAK_T* auto_speak )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    return FtAutoSpeakOpenFile(auto_speak);
#else
    return 0;     
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
void Custom_META_FtAutoRecCallback( void *host_data, META_ECHO_LOOP_EVENT event )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    FtAutoRecCallback(host_data, event);
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
void Custom_META_FtAutoRecGetDataFromRBToFile( kal_uint32 arg1, void *arg2 )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    FtAutoRecGetDataFromRBToFile(arg1, arg2);
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
kal_int32 Custom_META_FtAutoRecOpenFile( FT_AUTO_RECORD_T* auto_record )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    return FtAutoRecOpenFile(auto_record);
#else
    return 0;    
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
kal_int32 Custom_META_FtAutoRecWriteFileHeader(void)
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    return FtAutoRecWriteFileHeader();
#else
    return 0;    
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
kal_int32 Custom_META_FtWriteInitParameter(void)
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    return FtWriteInitParameter();
#else
    return 0;    
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
void Custom_META_FtDualMicRecordingInHisr( void )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    FtDualMicRecordingInHisr();
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
void Custom_META_FtDualMicEchoTestLoopbackInHisr( void )
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    FtDualMicEchoTestLoopbackInHisr();
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
void Custom_META_FtDualMicRecordHandler( FT_AUTO_RECORD_T* autoRecord, kal_uint32 frameSize)
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    FtDualMicRecordHandler(autoRecord, frameSize);
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
void Custom_META_FtDualMicSpeakHandler( FT_AUTO_SPEAK_T* autoSpeak, kal_uint32 frameSize)
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    FtDualMicSpeakHandler(autoSpeak, frameSize);
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
void Custom_META_FtSendDualMicEchoTestStarted(void)
{
#if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
    FtSendDualMicEchoTestStarted();
#endif // #if defined(__DUAL_MIC_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
}
#pragma arm section code, rodata
/****************************************************************************
 * DMNR custom wrapper function (END)
 ****************************************************************************/
#endif // #if !defined(__MAUI_BASIC__)
#endif // #if defined(__MTK_TARGET__)
