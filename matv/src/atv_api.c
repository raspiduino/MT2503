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
 *   atv_api.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   implement adapter atv and mtv
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
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"
#include "kal_trace.h"

#if defined(__ATV_SUPPORT__)
#include "atv_api.h"

#if defined(__MTK_TARGET__)
#include "matvctrl.h"
#include "l1audio.h"        // Media_Status

#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#include "dcmgr.h"
//extern void DCM_Load( kal_int32 dynamic_code_id, kal_uint32 **remaining_buf, kal_uint32 *buf_size );
//extern void DCM_Unload( kal_int32 dynamic_code_id );
#endif

#define MATV_I2S_MAX_VOLUME     (150)
#define MATV_LINEIN_MAX_VOLUME  (254)

#if (defined(MT6223)||defined(MT6223P))
extern kal_bool bPreview_Delay_Frame_Count_Start;
#endif

kal_uint8 atv_slp_handle; // added for Sleep mode, sleep mode controll will move from MED to porting layer[MAUI_02602171]
kal_bool bAtv_IsSleepHandleInit = KAL_FALSE;  
kal_uint8 atv_color_system = SV_CS_NTSC443; // default is NTSC, for return video color system to AP, shaowu.he
extern void L1SM_SleepDisable( kal_uint8 handle );
extern void L1SM_SleepEnable( kal_uint8 handle );
extern kal_uint8 L1SM_GetHandle ( void );
extern kal_bool g_matv_FactoryMode;
extern kal_bool gdi_lcd_get_te_ctrl(void);
extern kal_bool gdi_lcd_set_te_ctrl(kal_bool te_ctrl);
extern kal_bool gdi_lcd_set_te_ctrl_with_commit(kal_bool te_ctrl);
extern kal_bool bATV_TE_Enable;

#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_MATVDRIVER_ROCODE", rodata = "DYNAMIC_CODE_MATVDRIVER_ROCODE"
#endif
void matv_assert(kal_bool matv_ret)
{
	ASSERT(matv_ret == KAL_TRUE);
}
/*void matv_sleepmode_enable(kal_bool enable)
{
	if (bAtv_IsSleepHandleInit == KAL_FALSE)  // MAUI_02602171
	{
		atv_slp_handle = L1SM_GetHandle ();
		bAtv_IsSleepHandleInit = KAL_TRUE;
	}
	if(enable)
		L1SM_SleepEnable(atv_slp_handle);
	else
		L1SM_SleepDisable(atv_slp_handle);
}*/
void matv_sleepmode_init(void)
{
	if (bAtv_IsSleepHandleInit == KAL_FALSE)  // MAUI_02602171
	{
		atv_slp_handle = L1SM_GetHandle ();
		bAtv_IsSleepHandleInit = KAL_TRUE;
	}
	
}
void matv_kal_sleep_task(kal_uint32 time_in_ms)
{
	kal_sleep_task(kal_milli_secs_to_ticks(time_in_ms));
}
/////

#if 0//defined(MOTION_SENSOR_SUPPORT)
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
/////


//	ret=bChipInit(1);
	
#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif
kal_bool ATV_PowerOn(void)
{
    kal_bool matv_ret;

#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
    DCM_Load(DYNAMIC_CODE_COMPRESS_MATVDRIVER, NULL, NULL);
#endif
/*	if (bAtv_IsSleepHandleInit == 0)  // MAUI_02602171
	{
		atv_slp_handle = L1SM_GetHandle ();
		bAtv_IsSleepHandleInit = KAL_TRUE;
	}
	L1SM_SleepDisable(atv_slp_handle);*/
	matv_sleepmode_init();
	L1SM_SleepDisable(atv_slp_handle);
	//matv_sleepmode_enable(KAL_TRUE);
	matv_kal_sleep_task(20); // need delay 20ms before MT5192 power-on
#if 0//defined(MOTION_SENSOR_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   /* MOTION_SENSOR_SUPPORT */

    matv_ret = matv_init();

    /* matv_init might failed */
    if (matv_ret == KAL_TRUE)
    {
        /* set audio output mode */
#if defined(__ATV_I2S_SUPPORT__)
        matv_ret = matv_set_chipdep(190, 2);    // I2S Slave
		matv_assert(matv_ret);

        matv_ret = matv_adjust(MATV_AUD_VOLUME, MATV_I2S_MAX_VOLUME);    // VOLUME
        matv_assert(matv_ret);
#else
        matv_ret = matv_set_chipdep(190, 3);    // PWM
        matv_assert(matv_ret);

        matv_ret = matv_adjust(MATV_AUD_VOLUME, MATV_LINEIN_MAX_VOLUME);    // VOLUME
        matv_assert(matv_ret);
#endif
    }
#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
    else
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_MATVDRIVER);
    }
#endif	

    return matv_ret;
}
kal_bool ATV_PowerOff(void)
{
    kal_bool matv_ret;

    matv_ret = matv_shutdown();
    matv_assert(matv_ret);
	//matv_sleepmode_init();
	/*if (bAtv_IsSleepHandleInit == 0)  // MAUI_02602171
	{
		atv_slp_handle = L1SM_GetHandle ();
		bAtv_IsSleepHandleInit = KAL_TRUE;
	}
	L1SM_SleepEnable(atv_slp_handle);*/
#if 0//defined(MOTION_SENSOR_SUPPORT)
/* under construction !*/
/* under construction !*/
#endif	 /* MOTION_SENSOR_SUPPORT */
	L1SM_SleepEnable(atv_slp_handle);
	//matv_sleepmode_enable(KAL_TRUE);

#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
	DCM_Unload(DYNAMIC_CODE_COMPRESS_MATVDRIVER);
#endif	
    return matv_ret;
}
#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_MATVDRIVER_ROCODE", rodata = "DYNAMIC_CODE_MATVDRIVER_ROCODE"
#endif
void ATV_Scan(kal_uint8 country, kal_uint8 mode)
{
    matv_set_country(country);

    if (mode == ATV_AUTOSCAN)
    {
        matv_chscan(MATV_AUTOSCAN);
    }
    else if (mode == ATV_FULLSCAN)
    {
        matv_chscan(MATV_FULLSCAN);
    }
    else if (mode == ATV_QUICKSCAN)
    {
        matv_chscan(MATV_QUICKSCAN);
    }
    else
    {
        ASSERT(0);
    }
}

void ATV_StopScan(void)
{
    matv_chscan_stop();
}

kal_bool ATV_GetChannelTable(kal_uint32 ch_id, atv_ch_info* ch_info)
{
    matv_ch_entry entry;
    kal_bool matv_ret;

    matv_ret = matv_get_chtable(ch_id, &entry);
    if (matv_ret == KAL_TRUE)
    {
        ch_info->freq = entry.freq;
        ch_info->audio_system = entry.sndsys;
        ch_info->color_system = entry.colsys;
        ch_info->flag = entry.flag;
        ch_info->valid = (entry.flag & CH_VALID) ? KAL_TRUE : KAL_FALSE;
		if(KAL_TRUE == ch_info->valid)
		atv_color_system = entry.colsys;
    }

    return matv_ret;
}

kal_bool ATV_SetChannelTable(kal_uint32 ch_id, atv_ch_info* ch_info)
{
    matv_ch_entry entry;
    kal_bool matv_ret;

    entry.freq = ch_info->freq;
    entry.sndsys = ch_info->audio_system;
    entry.colsys = ch_info->color_system;
    entry.flag = ch_info->flag;

    matv_ret = matv_set_chtable(ch_id, &entry);
	if(KAL_TRUE == entry.flag)
	atv_color_system = entry.colsys;
    matv_assert(matv_ret);

    return matv_ret;
}

kal_bool ATV_ClearChannelTable(void)
{
    kal_bool matv_ret;

    matv_ret = matv_clear_chtable();

    return matv_ret;
}

void ATV_ChangeChannel(kal_uint32 ch_id)
{
    matv_change_channel((kal_uint8)ch_id);
}

kal_bool ATV_VideoOpen(void)
{
    kal_bool matv_ret;
	#if (defined(MT6223)||defined(MT6223P))
	bPreview_Delay_Frame_Count_Start = KAL_TRUE;
	#endif
	gdi_lcd_set_te_ctrl_with_commit(KAL_FALSE);

    matv_ret = matv_suspend(KAL_FALSE);
    matv_assert(matv_ret);

    return KAL_TRUE;
}

kal_bool ATV_VideoClose(void)
{
    kal_bool matv_ret;
	#if (defined(MT6223)||defined(MT6223P))
		bPreview_Delay_Frame_Count_Start = KAL_FALSE;
	#endif
	gdi_lcd_set_te_ctrl_with_commit(bATV_TE_Enable);

    matv_ret = matv_suspend(KAL_TRUE);
    matv_assert(matv_ret);

    return KAL_TRUE;
}

kal_bool ATV_SetVideoParam(atv_video_param_t param, kal_int32 value)
{
    kal_bool matv_ret = KAL_FALSE;

    if (param == ATV_VDO_CONTRAST)
    {
        matv_ret = matv_adjust(MATV_VDO_CONTRAST, value);
    }
    else if (param == ATV_VDO_BRIGHTNESS)
    {
        matv_ret = matv_adjust(MATV_VDO_BRIGHTNESS, value);
    }
    else if (param == ATV_VDO_SATURATION)
    {
        matv_ret = matv_adjust(MATV_VDO_SATURATION, value);
    }
    else
    {
        ASSERT(0);
    }

    matv_assert(matv_ret);

    return matv_ret;
}

kal_uint8 ATV_GetVideoColorSystem(void)
{
  kal_uint8 return_value;

	switch(atv_color_system)
	{
       case SV_CS_PAL:
	   case SV_CS_PAL_N:
	   case SV_CS_SECAM:
	   	   return_value =ATV_SV_CS_PAL;
           break;
	    default:
			return_value = ATV_SV_CS_NTSC;
		   break;
	}
	return return_value;
}
kal_uint32 ATV_GetAudioFormat(void)
{
    return matv_audio_get_format();
}

void ATV_SetAudioFormat(kal_uint32 format)
{
    matv_audio_set_format(format);
}

kal_int32  ATV_GetSignalStrength(void)
{
    kal_int32 signal_strength;
    kal_int32 signal_colorstate;
//    kal_int32 signal_strengthtemp=0;
    kal_int32 signal_strength1=0;
    kal_int32 signal_cvbs_snr=0;
    signal_strength1 = matv_get_chipdep(SIG_RSSI);
    signal_colorstate = matv_get_chipdep(TVD_BurstLock);
    signal_cvbs_snr= matv_get_chipdep(SIG_CVBS_SNR);

    if (signal_strength1 >= 50)
    {
        signal_strength = ATV_MAX_SIGNAL_STRENGTH * 5 / 5;
    }
    else if (signal_strength1 >= 35)
    {
        signal_strength = ATV_MAX_SIGNAL_STRENGTH * 4 / 5;
    }
    else if (signal_strength1 >= 17)
    {
        signal_strength = ATV_MAX_SIGNAL_STRENGTH * 3 / 5;
    }
    else if (signal_strength1 >= 3)
    {
        signal_strength = ATV_MAX_SIGNAL_STRENGTH * 2 / 5;
    }
    else
    {
        signal_strength = ATV_MAX_SIGNAL_STRENGTH * 1 / 5;
    }
///////////////////
if(!signal_colorstate)
{
//	signal_strength=signal_strengthtemp;
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
	#endif
	if((signal_strength>=60))
		signal_strength -= 20;
   // if(signal_strengthtemp!=0)
   // 	{
	    	//signal_strength=signal_strengthtemp;
   // 	}
}
///////////////////
else
{
    if(signal_strength1<20&&signal_strength1>=10)
    	{
	    signal_strength=60;
    }

     if(signal_strength1<10)
    	{
	    signal_strength=40;
    }
}
///////////////////////////
     if(signal_cvbs_snr>=22000)
	signal_strength=20;
     if(signal_strength==60&&signal_cvbs_snr>=12000)
        signal_strength=40;

    return signal_strength;
}

kal_int32  ATV_GetSignalSNR(void)
{
    return matv_get_chipdep(SIG_SNR);
}
#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif
/* callback */
void ATV_RegisterCallback(void* cb_param,
	                        atv_autoscan_progress_cb auto_cb,
                        	atv_fullscan_progress_cb full_cb,
                        	atv_scanfinish_cb finish_cb,
                        	atv_audioformat_cb audfmt_cb)
{
    matv_register_callback(cb_param, auto_cb, full_cb, finish_cb, audfmt_cb);
}
#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_MATVDRIVER_ROCODE", rodata = "DYNAMIC_CODE_MATVDRIVER_ROCODE"
#endif
/* audio part */
void ATV_AudioSetOutputDevice(kal_uint8 device)
{
#if defined(__ATV_I2S_SUPPORT__)
   Media_SetOutputDevice( device );
#else
   LINEIN_SetOutputDevice( device );
#endif
}

void ATV_AudioSetOutputVolume(kal_uint8 volume1, kal_int8 digital_gain_index)
{
#if defined(__ATV_I2S_SUPPORT__)
   Media_SetOutputVolume( volume1, digital_gain_index );
#else
   LINEIN_SetOutputVolume( volume1, digital_gain_index );
#endif
}

void ATV_AudioSetLevelVolume(kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level)
{
#if defined(__ATV_I2S_SUPPORT__)
   Media_SetLevelVolume( MaxAnalogGain, step,level );
#endif
}

void ATV_AudioMute(kal_bool mute)
{
#if defined(__ATV_I2S_SUPPORT__)
   Media_MuteSpeaker( mute );
#else
   LINEIN_MuteSpeaker( mute );
#endif
}

kal_bool ATV_AudioOpen(void)
{
#if defined(__ATV_I2S_SUPPORT__)
    Media_Status audio_ret;

    matv_audio_open();
	AudioPP_DisableBesSound();
    if (I2S_is_I2S_open())
    {
        //kal_prompt_trace(MOD_MED, "I2S Opened!!!");
        ASSERT(0);
        return KAL_FALSE;
    }

    audio_ret = I2S_Open();
    ASSERT(audio_ret == MEDIA_SUCCESS);

    matv_audio_play();

#else
    matv_audio_open();
    LINEIN_Open();
    matv_audio_play();

#endif


    return KAL_TRUE;
}

kal_bool ATV_AudioClose(void)
{
#if defined(__ATV_I2S_SUPPORT__)
    Media_Status audio_ret;

    matv_audio_stop();

    audio_ret = I2S_Close();
    ASSERT(audio_ret == MEDIA_SUCCESS);
    AudioPP_EnableBesSound();
#else

    matv_audio_stop();
    LINEIN_Close();

#endif
	matv_audio_close();
    return KAL_TRUE;
}

void ATV_GetAudioParam(atv_audio_param_t param, kal_int32* value)
{
    if (param == ATV_AUD_TYPE)
    {
#if defined(__ATV_I2S_SUPPORT__)
        *value = ATV_AUD_TYPE_I2S;
#else
        *value = ATV_AUD_TYPE_LINEIN;
#endif
    }
    else if (param == ATV_AUD_SAMPLING_RATE)
    {
#if defined(__ATV_I2S_SUPPORT__)
        *value = 32000;
#else
        *value = 8000;
#endif
    }
    else if (param == ATV_AUD_BITS_PER_SAMPLE)
    {
        *value = 16;
    }
    else if (param == ATV_AUD_CHANNEL_NUM)
    {
        *value = 2;
    }
    else
    {
        ASSERT(0);
    }
}
void ATV_SetChannelScanMode(kal_bool enable)
{
    if (enable == KAL_TRUE)
    {
        g_matv_FactoryMode = KAL_FALSE;
    }
    else
    {
        g_matv_FactoryMode = KAL_TRUE;
    }
}

kal_bool ATV_GetChannelScanMode(void)
{
    kal_bool ret;

    if (g_matv_FactoryMode == KAL_TRUE)
    {
        ret = KAL_FALSE;
    }
    else
    {
        ret = KAL_TRUE;
    }

    return ret;
}
#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

#ifdef __ATA_SUPPORT__

extern void matv_kal_take_sem(void);
extern void matv_kal_give_sem();
extern void fATA_AVPatternOut(void);
extern kal_bool fATA_Lockstatus(kal_uint32 freq);
extern void fATA_AVPatternclose(void);
kal_uint8 matvdrv_ata_poweron(void)
{
     kal_uint32 ata_id;

#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
        if(!DCM_Isloaded(DYNAMIC_CODE_COMPRESS_MATVDRIVER))
        {
           DCM_Load(DYNAMIC_CODE_COMPRESS_MATVDRIVER, NULL, NULL);
        }
#endif		
	 
	if (bAtv_IsSleepHandleInit == 0)  
	{
		atv_slp_handle = L1SM_GetHandle ();
		bAtv_IsSleepHandleInit = 1;
	}
	L1SM_SleepDisable(atv_slp_handle); 
	kal_sleep_task(kal_milli_secs_to_ticks(20));
	if(matvdrv_init())
	{
	#if defined(__ATV_I2S_SUPPORT__)
		{
		matvdrv_set_chipdep(190,2);
		matvdrv_adjust(0,150); 
		}
	#else
		{
		matvdrv_set_chipdep(190,3);
		matvdrv_adjust(0,254); 
		}
	#endif
	    matvdrv_suspend(0);
		matv_kal_take_sem();
		ata_id=ATVChipID();
		matv_kal_give_sem();
		return ata_id; 
	
}
	else 
	{
		
		return 0;

	}	
}

kal_bool matvdrv_ata_lockstatus(kal_uint32 freq, kal_uint8 country)
{
    kal_bool lockstatus; 
	matvdrv_set_country(country);
	matv_kal_take_sem();
	lockstatus=fATA_Lockstatus(freq);
	matv_kal_give_sem();
	return lockstatus;
}

 kal_bool matvdrv_ata_avpatternout(void)
{
    matv_kal_take_sem();
	fATA_AVPatternOut();
	matv_kal_give_sem();
	return KAL_TRUE;
}
kal_bool matvdrv_ata_avpatternclose(void)
{
    matv_kal_take_sem();
	fATA_AVPatternclose();
	matv_kal_give_sem();
	return KAL_TRUE;
}


void matvdrv_ata_poweroff(void)
{
	matvdrv_ata_avpatternclose();	
	matvdrv_shutdown();
	if (bAtv_IsSleepHandleInit == 0)  
	{
		atv_slp_handle = L1SM_GetHandle ();
		bAtv_IsSleepHandleInit = KAL_TRUE;
	}	 
	L1SM_SleepEnable(atv_slp_handle);  

#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
	if( DCM_Isloaded(DYNAMIC_CODE_COMPRESS_MATVDRIVER) )
	{
	    DCM_Unload(DYNAMIC_CODE_COMPRESS_MATVDRIVER);
	}
#endif		
}
#endif

#else /* null function for MoDIS */

kal_bool ATV_PowerOn(void)
{
    return KAL_TRUE;
}
kal_bool ATV_PowerOff(void)
{
    return KAL_TRUE;
}

void ATV_Scan(kal_uint8 country, kal_uint8 mode)
{
}

void ATV_StopScan(void)
{
}

kal_bool ATV_GetChannelTable(kal_uint32 ch_id, atv_ch_info* ch_info)
{
    return KAL_TRUE;
}

kal_bool ATV_SetChannelTable(kal_uint32 ch_id, atv_ch_info* ch_info)
{
    return KAL_TRUE;
}

kal_bool ATV_ClearChannelTable(void)
{
    return KAL_TRUE;
}

void ATV_ChangeChannel(kal_uint32 ch_id)
{
}

kal_bool ATV_VideoOpen(void)
{
    return KAL_TRUE;
}

kal_bool ATV_VideoClose(void)
{
    return KAL_TRUE;
}

kal_bool ATV_SetVideoParam(atv_video_param_t param, kal_int32 value)
{
    return KAL_TRUE;
}

kal_uint32 ATV_GetAudioFormat(void)
{
    return 0;
}

void ATV_SetAudioFormat(kal_uint32 format)
{
}

kal_int32  ATV_GetSignalStrength(void)
{
    return 0;
}

kal_int32  ATV_GetSignalSNR(void)
{
    return 0;
}


/* callback */
void ATV_RegisterCallback(void* cb_param,
	                        atv_autoscan_progress_cb auto_cb,
                        	atv_fullscan_progress_cb full_cb,
                        	atv_scanfinish_cb finish_cb,
                        	atv_audioformat_cb audfmt_cb)
{
}

/* audio part */
void ATV_AudioSetOutputDevice(kal_uint8 device)
{
}

void ATV_AudioSetOutputVolume(kal_uint8 volume1, kal_int8 digital_gain_index)
{
}

void ATV_AudioSetLevelVolume(kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level)
{
}

void ATV_AudioMute(kal_bool mute)
{
}

kal_bool ATV_AudioOpen(void)
{
    return KAL_TRUE;
}

kal_bool ATV_AudioClose(void)
{
    return KAL_TRUE;
}

void ATV_GetAudioParam(atv_audio_param_t param, kal_int32* value)
{
}

kal_uint8 ATV_GetVideoColorSystem(void)
{
	return 0;
}
void ATV_SetChannelScanMode(kal_bool enable)
{
}

kal_bool ATV_GetChannelScanMode(void)
{
    return KAL_TRUE;
}

#endif /* __MTK_TARGET__ */

#elif defined(__MTK_TARGET__) && defined(__ATA_SUPPORT__)

kal_uint8 matvdrv_ata_poweron(void)
{
  return 0;

}

kal_bool matvdrv_ata_lockstatus(kal_uint32 freq, kal_uint8 country)
{   
   return KAL_FALSE;

}

 kal_bool matvdrv_ata_avpatternout(void)
{
	 return KAL_FALSE;
}

kal_bool matvdrv_ata_avpatternclose(void)
{
	return KAL_FALSE;

}


void matvdrv_ata_poweroff(void)
{
	
}


#endif /* __ATV_SUPPORT__ */
