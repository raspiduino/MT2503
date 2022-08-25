#ifndef _L1SP_TRC_H
#define _L1SP_TRC_H

#ifndef GEN_FOR_PC

   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before l1sp_trc.h"
   #endif

#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */

#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before nvram_trc.h"
#endif

#define TRACE_GROUP_SBC          TRACE_GROUP_1
#define TRACE_GROUP_RESAMPLER    TRACE_GROUP_1
#define TRACE_GROUP_SCO          TRACE_GROUP_1
#define TRACE_GROUP_DAFRTP       TRACE_GROUP_1
#define TRACE_GROUP_DSPDEBUG     TRACE_GROUP_1
#define TRACE_GROUP_SND          TRACE_GROUP_2
#define TRACE_GROUP_AUD_PROCESS  TRACE_GROUP_3
#define TRACE_GROUP_VORTP        TRACE_GROUP_4
#define TRACE_GROUP_PCM_CLK      TRACE_GROUP_4
#define TRACE_GROUP_CACHE        TRACE_GROUP_5
#define TRACE_GROUP_AST          TRACE_GROUP_5
#define TRACE_GROUP_AUDRTP       TRACE_GROUP_6
#define TRACE_GROUP_APM          TRACE_GROUP_7
#define TRACE_GROUP_SP3G         TRACE_GROUP_8
#define TRACE_GROUP_DSPSYN       TRACE_GROUP_1
#define TRACE_GROUP_MELODY_LV1   TRACE_GROUP_1
#define TRACE_GROUP_JWAV         TRACE_GROUP_2
#define TRACE_GROUP_AVB          TRACE_GROUP_7
#define TRACE_GROUP_LG_ENGINE    TRACE_GROUP_8
#define TRACE_GROUP_AUDIOLP      TRACE_GROUP_9
#define TRACE_GROUP_AUD_PLAYBACK TRACE_GROUP_9
#define TRACE_GROUP_AUD_RECORD   TRACE_GROUP_9
#define TRACE_GROUP_AUD_MD2GCTRL TRACE_GROUP_9
#define TRACE_GROUP_AUD_SPE_CSUT TRACE_GROUP_2
#define TRACE_GROUP_KARAOKE_VOC  TRACE_GROUP_2
#define TRACE_GROUP_M2M_AT       TRACE_GROUP_3


#define TRACE_GROUP_PLAYBACK_CILENT    TRACE_GROUP_1
#define TRACE_GROUP_PLAYBACK_COMPONENT TRACE_GROUP_1
#define TRACE_GROUP_DDLOAD             TRACE_GROUP_1
#define TRACE_GROUP_ECALL              TRACE_GROUP_1

#define TRACE_GROUP_VAD_VOC      TRACE_GROUP_2
#define TRACE_GROUP_VAD_LOG      TRACE_GROUP_3

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
   #include "l1sp_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_L1SP)

   // AFE
   TRC_MSG(AFE_SWITCH_FIR, "AFE Switch FIR %c for aud_func %X")
   TRC_MSG(AFE_SWITCH_LOOPBACK, "AFE Switch Loopback %c")
   TRC_MSG(AFE_SWITCH_MIC, "AFE Switch MIC %c for aud_func %X")
   TRC_MSG(AFE_SET_INPUT_SRC, "AFE SetInputSource: %X")
   TRC_MSG(AFE_GAIN, "AFE_VAG_CON:%X, AFE_AAG_CON:%X, DP_SIDETONE:%X")
   TRC_MSG(AFE_DIGI_GAIN, "DP_VOL_OUT_PCM:%X, DP_DigiGain_Setting:%X")
   TRC_MSG(AFE_SET_MIC_VOLUME, "AFE SetMicrophoneVolume: %X")
   TRC_MSG(AFE_SET_SIDETONE_VOLUME, "AFE SetSideToneVolume: %X")
   TRC_MSG(AFE_SET_OUTPUT_DEVICE, "AFE Set aud_func %X OutputDevice %X")
   TRC_MSG(AFE_SET_OUTPUT_VOLUME, "AFE Set aud_func %X OutputVolume %d %d")
   TRC_MSG(AFE_SET_LEVEL_VOLUME, "AFE Set aud_func %X MaxAnalogGain %d , step %d, level %d")
   TRC_MSG(AFE_SET_GIDI_GAIN, "AFE Set aud_func %X digital gain level %d")
   TRC_MSG(AFE_MUTE_SPEAKER, "AFE mute aud_func %X speaker %d")
   TRC_MSG(AFE_SET_EDI, "AFE Set EDI dir %d cycle %d fmt %d")
   TRC_MSG(AFE_SWITCH_HW_MUTE_SLEEP, "AFE Switch HW mute sleep %d")
   TRC_MSG(AFE_EXT_AU_AMP_CHANNEL_AND_DEVICE, "External audio amplifer debug: v_lowest=%d,v_device=%d, a_lowest=%d, a_lowest=%d")
   TRC_MSG(AFE_EXT_AU_AMP_FOUND_TWO_CHANNEL, "External audio amplifer debug: v_lowest=%d,a_lowest=%d, v_cmd=%d, a_cmd=%d")
   TRC_MSG(AFE_CHG_STATE, "AFE Change State (%d -> %d)")
   TRC_MSG(AFE_TURN_ON_AUDIO_CLK, "AFE Turn On Audio Clock: %d")
   TRC_MSG(AFE_STATE_INFO, "In AFE State(%d), v(%d, %d), a(%d, %d)")
   TRC_MSG(AFE_SET_DUAL_PATH_GAIN, "AFE set dual path gain 0x%X")
   TRC_MSG(AFE_SET_MIC_GAIN_CONTROL, "AFE set mic gain_ctrl Ana %d Dig %d(%d)")
   TRC_MSG(AFE_SET_OUTPUT_GAIN_CONTROL, "AFE set func %d gain_ctrl Ana %d Dig %d(%d) Ext 0x%x")
   TRC_MSG(AFE_TURN_OFF_AUDIO_CLOCK, "AFE_TurnOffAudioClock")
   TRC_MSG(AFE_TURN_ON_AUDIO_CLOCK, "AFE_TurnOnAudioClock")
   TRC_MSG(AFE_RETREIVE_DC_CALI_ADC_VALUE, "AFE retreive DC cali adc_value %d")
   TRC_MSG(AFE_SWITCH_2_CLASSD, "AFE Switch to Class-D")
   TRC_MSG(AFE_SWITCH_2_CLASSAB, "AFE Switch to Class-AB")
   TRC_MSG(AFE_ACLK_SET_HARDWARE_MUTE, "_AfeAclkSetHardwareMute (%d)")
   TRC_MSG(AFE_HARDWARE_MUTE_CTRL, "_AfeHardwareMuteCtrl (%d)")
   TRC_MSG(AFE_SWITCH_VCM, "Switch VCM = (%d)")
   TRC_MSG(AFE_SET_AUDIOFLAG, "AFE Set AUDIO FLAG, on=(%d), count=(%d), timer = (%d)")
   TRC_MSG(AFE_VOLUME_PROTECT, "AFE EnableVolumeProtection:afe.low_battery:%d")
   TRC_MSG(AFE_DC_CALIBRATION, "AFE_DC_Calibration: DC_OFFSET = %d, %d mV")
   TRC_MSG(AFE_SET_PCMIFLPK, "AFE pcmif loopback (%d)")

   // L1CTM
   TRC_MSG(L1CTM_OPEN, "Call L1Ctm_Open")
   TRC_MSG(L1CTM_CLOSE, "Call L1Ctm_Close")
   TRC_MSG(L1CTM_SET_INTERFACE, "Call L1Ctm_SetInterface")
   TRC_MSG(L1CTM_START_NEGOTIATION, "Call L1Ctm_StartNegotiation")
   TRC_MSG(L1CTM_TX_PUT_TEXT, "Call L1Ctm_TxPutText")
   TRC_MSG(L1CTM_RX_GET_TEXT, "Call L1Ctm_RxGetText")

   TRC_MSG(L1CTM_FAR_END_CTM_DETECTED, "L1Ctm far-end CTM detected")
   TRC_MSG(L1CTM_NEGOTIATION_SUCCESS, "L1Ctm negotiation success")
   TRC_MSG(L1CTM_NEGOTIATION_FAIL, "L1Ctm negotiation fail")
   TRC_MSG(L1CTM_DEMAND_CTM_ACK, "L1Ctm is demanded to send CTM ACK")
   TRC_MSG(L1CTM_UL_SEND_IDLE_AS_ACK, "L1CtmTx ul-path send IDLE as ACK")
   TRC_MSG(L1CTM_DL_DETECT_CTM_SYNC, "L1Ctm dl-path detect CTM Sync")
   TRC_MSG(L1CTM_DL_CTM_BURST_END, "L1Ctm dl-path detect CTM burst-end")

   TRC_MSG(L1CTM_UL_SEND_ENQUIRY_CHAR, "L1Ctm ul-path send %d-time ENQUIRY char")
   TRC_MSG(L1CTM_UL_GET_DECODED_TTY_CHAR, "L1Ctm ul-path get decoded TTY-char 0x%02X")
   TRC_MSG(L1CTM_UL_SEND_CTM_CHAR, "L1Ctm ul-path send CTM-char 0x%02X")
   TRC_MSG(L1CTM_DL_GET_RECEIVED_CTM_CHAR, "L1Ctm dl-path get received CTM-char 0x%02X")
   TRC_MSG(L1CTM_DL_SEND_TTY_CHAR, "L1Ctm dl-path send TTY-char 0x%02X")
   TRC_MSG(L1CTM_REC_DIR_NO, "L1Ctm record to dir REC_%02u")
   TRC_MSG(L1CTM_SAVE_DECODED_CHAR, "L1Ctm dl-path save decoded char 0x%02X")

   TRC_MSG(L1CTM_DEBUG_SHOW_SETTING1, "[CTM Setting 6229] AEC, EES, ES (Address 0x1A0~0x1A2): %d,%d,%d")
   TRC_MSG(L1CTM_DEBUG_SHOW_SETTING2, "[CTM Setting 6229] AMR codebook threshold=%d, gain=%d")
   TRC_MSG(L1CTM_DEBUG_SHOW_SETTING3, "[CTM Setting 6229] DSP_AFS/AHS_SP_BFI_THRESHOLD 0: %d,%d")
   TRC_MSG(L1CTM_DEBUG_SHOW_SETTING4, "[CTM Setting 6229] DSP_AFS/AHS_SP_BFI_THRESHOLD 1: %d,%d")
   TRC_MSG(L1CTM_DEBUG_SHOW_SETTING5, "[CTM Setting 6229] DSP_AFS/AHS_SP_BFI_THRESHOLD 2: %d,%d")
   TRC_MSG(L1CTM_DEBUG_SHOW_SETTING6, "[CTM Setting 6229] DSP_AFS/AHS_SP_BFI_THRESHOLD 3: %d,%d")
   TRC_MSG(L1CTM_DEBUG_SHOW_SETTING7, "[CTM Setting]: Audio Coefficient for input : %d, %d, %d, %d")
   TRC_MSG(L1CTM_DEBUG_SHOW_SETTING8, "[CTM Setting]: Audio Coefficient for output: %d, %d, %d, %d")
   TRC_MSG(L1CTM_FAKE_COSIM, "Turning on COSIM bit in DP_CTM_COSIM_CTRL")
   TRC_MSG(L1CTM_BUF_OVFLOW, "l1ctm buffer overflow")
   TRC_MSG(L1CTM_COSIM, "Turning on COSIM bit in DP_CTM_COSIM_CTRL")
   TRC_MSG(L1CTM_BFI_INFO, "l1ctm_in_hisr in cosim mode(buf_idx=%x, bfi_store_idx=%x, dsp_tch_bfi=%x, bfi flag=%x)")
   TRC_MSG(L1CTM_HCO_MODE, "Opening ctm in HCO mode.")
   TRC_MSG(L1CTM_VCO_MODE, "Opening ctm in VCO mode.")
   TRC_MSG(L1CTM_COSIM_MODE, "Opening CTM in cosim mode")
   TRC_MSG(L1CTM_NORMAL_MODE,"Opening ctm in normal mode (no HCO/VCO).")
   TRC_MSG(L1CTM_OPEN_PARAM, "ctm param is not null, cprm_debug_flag=%x")


   // SBC
   TRC_MSG(L1SBC_ENTER_SBC_INITIATEBITPOOL, "Enter SBC_InitiateBitPool")
   TRC_MSG(L1SBC_ENTER_SBC_ADJUSTBITPOOL, "Enter SBC_AdjustBitPool")
   TRC_MSG(L1SBC_ENTER_SBC_ADJUSTBITRATEFROMQOS, "Enter sbc_AdjustBitRateFromQoS")
   TRC_MSG(L1SBC_ENTER_SBC_QUERYPAYLOADSIZE, "Enter sbc_QueryPayloadSize")
   TRC_MSG(L1SBC_ENTER_SBC_GETPAYLOAD, "Enter sbc_GetPayload")
   TRC_MSG(L1SBC_ENTER_SBC_OPEN, "Enter SBC_Open")
   TRC_MSG(L1SBC_ENTER_SBC_CLOSE, "Enter SBC_Close")
   TRC_MSG(L1SBC_ENTER_SBC_GETMEMREQ, "Enter SBC_GetMemReq")
   TRC_MSG(L1SBC_ENTER_SBC_ENCODING, "Enter sbc_event_handler")
   TRC_MSG(L1SBC_QOS_REPORT, "SBC QoS=%d, change bitrate from %d to %d")
   TRC_MSG(L1SBC_OPEN_REPORT, "SBC opened with id=%d, initial bitrate=%d, full sbc=%d, fmt=%d")
   TRC_MSG(L1SBC_CLOSE_REPORT, "SBC closed with %d frame dropped")
   TRC_MSG(L1SBC_CONFIG_REPORT, "SBC encoder config: fs=%d, cm=%d, bp=%d-%d-%d")
   TRC_MSG(L1SBC_ENCODER_REPORT, "SBC encoder status: process %d samples, left %d bytes, produce %d frames")
   TRC_MSG(L1SBC_PAYLOAD_REPORT, "SBC payload request %dB, get %dB, %d frames, left %dB")
   TRC_MSG(L1SBC_FRAME_BUFFER_UNDERRUN, "SBC frame buffer underrun")
   TRC_MSG(L1SBC_ENCODER_CONFIG, "SBC encoder config: ana: %d, up: %d, sample freq: %d/%d")
   TRC_MSG(L1SBC_INITIATED, "SBC initiated")
   TRC_MSG(L1SBC_INITIATING, "SBC initiating, type %d, %d")
   TRC_MSG(L1SBC_MUTE, "SBC and AvBT mute: %d")
   TRC_MSG(L1SBC_SET_LEVEL_VOLUME, "SBC and AvBT SetLevelVolume: uCurStep: %d, uTotalStep: %d, uDigiGain: %d")

   // SND
   TRC_MSG(L1SND_ENTER_SND_OPEN, "Enter SND_Open")
   TRC_MSG(L1SND_ENTER_SND_CLOSE, "Enter SND_Close")
   TRC_MSG(L1SND_ENTER_SND_PLAY, "Enter SND_Play")
   TRC_MSG(L1SND_ENTER_SND_STOP, "Enter SND_Stop")
   TRC_MSG(L1SND_CONFIG_ULMIXER, "SND ConfigULMixer, flag:%d, gain:%d")
   TRC_MSG(L1SND_CONFIG_DLMIXER, "SND ConfigDLMixer, flag:%d, gain:%d")
   TRC_MSG(L1SND_REPEATED, "SND Repeat-play, elapsed:%d times")
   TRC_MSG(L1SND_FILLBUFFER, "SND Filled %d bytes")
   TRC_MSG(L1SND_DATACHUNK_SIZE, "SND Data chunk size: %d bytes")
   TRC_MSG(L1SND_SND_ALLOC_SRC, "SND alloc SRC")
   TRC_MSG(L1SND_SND_FREE_SRC, "SND free SRC")
   TRC_MSG(L1SND_SND_DO_SRC, "SND do SRC")
   TRC_MSG(L1SND_SND_DO_SRC_DETAIL, "SND do SRC, consume = %d generate = %d")

   TRC_MSG(L1SND_SND_UT_SND_PLAY_PLAY, "SND: snd_ut_snd_play, play")
   TRC_MSG(L1SND_SND_UT_SND_PLAY_OPEN, "SND: snd_ut_snd_play, open")
   TRC_MSG(L1SND_SND_UT_SND_PLAY_CONFIG, "SND: snd_ut_snd_play, config")
   TRC_MSG(L1SND_SND_UT_SND_PLAY_FSAL_OPEN, "SND: snd_ut_snd_play, fsal open")

   //Tone
   TRC_MSG( TONESTOP_FLUSHQUEUE1, "[TONE]toneStop_FlushQueue_1 *(%x)=%x *(%x)=%x")
   TRC_MSG( TONESTOP_FLUSHQUEUE2, "[TONE]toneStop_FlushQueue_2 *(%x)=%x *(%x)=%x")
   TRC_MSG( TONESTOP1,            "[TONE]toneStop1 return")
   TRC_MSG( TONESTOP2,            "[TONE]toneStop2 *(%x)=%x *(%x)=%x")
   TRC_MSG( TONEMUTE,             "[TONE]toneMute *(%x)=%x *(%x)=%x")
   TRC_MSG( TONEPLAY,             "[TONE]TONE_Play[%d]")
   TRC_MSG( TONESTOP,             "[TONE]TONE_Stop")
   TRC_MSG( TONESTOPANDWAIT1,     "[TONE]TONE_StopAndWait_1")
   TRC_MSG( TONESTOPANDWAIT2,     "[TONE]TONE_StopAndWait_2")
   TRC_MSG( KTSTOPFLUSHQUEUE1,    "[KT]ktStop_FlushQueue_1 *(%x)=%x")
   TRC_MSG( KTSTOPFLUSHQUEUE2,    "[KT]ktStop_FlushQueue_2 *(%x)=%x")
   TRC_MSG( KTSTOP1,              "[KT]ktStop_1 return")
   TRC_MSG( KTSTOP2,              "[KT]ktStop_2 *(%x)=%x")
   TRC_MSG( KTPLAY,               "[KT]KT_Play[%d]")
   TRC_MSG( KTSTOP,               "[KT]KT_Stop")
   TRC_MSG( KTSTOPANDWAIT1,       "[KT]KT_StopAndWait_1")
   TRC_MSG( KTSTOPANDWAIT2,       "[KT]KT_StopAndWait_2")

   // L1AUDIO
   TRC_MSG(L1AUDIO_OPEN_FILE, "Enter AUD_Open file, type = %d")
   TRC_MSG(L1AUDIO_OPEN_STREAM, "Enter AUD_Open stream, type = %d")
   TRC_MSG(L1AUDIO_PLAY_FILE, "Enter AUD_Play file, type = %d")
   TRC_MSG(L1AUDIO_PLAY_STREAM, "Enter AUD_Play stream, type = %d")
   TRC_MSG(L1AUDIO_RECORD, "Enter AUD_Record stream, type = %d")
   TRC_MSG(L1AUDIO_PROCESS, "Enter AUD_Process, type = %d")
   TRC_MSG(L1AUDIO_PAUSE, "Enter AUD_Pause, type = %d")
   TRC_MSG(L1AUDIO_RESUME, "Enter AUD_Resume, type = %d")
   TRC_MSG(L1AUDIO_STOP, "Enter AUD_Stop, type = %d")
   TRC_MSG(L1AUDIO_CLOSE, "Enter AUD_Close, type = %d")
   TRC_MSG(L1AUDIO_SEEK, "Enter AUD_Seek, type = %d")
   TRC_MSG(L1AUDIO_SET_START_TIME, "Set audio start time, start time = %d ms, type = %d")
   TRC_MSG(L1AUDIO_SET_STOP_TIME, "Set audio stop time, stop time = %d ms, type = %d")
   TRC_MSG(L1AUDIO_CONTENT, "Enter AUD_GetContentDescInfo, type = %d")

   TRC_MSG(L1AUDIO_INIT_STATE, "Audio function in initial state")
   TRC_MSG(L1AUDIO_RUNNING_STATE, "Audio function in running state")
   TRC_MSG(L1AUDIO_STOP_STATE, "Audio function in stop state")
   TRC_MSG(L1AUDIO_END_STATE, "Audio function in end state")
   TRC_MSG(L1AUDIO_IDLE_STATE, "Audio function in idle state")

   TRC_MSG(L1AUDIO_READ_BYTE, "Read %d bytes from media buffer")
   TRC_MSG(L1AUDIO_WRITE_DSP_FIRST_SEGMENT, "1stDSPStrAddr=%d, Len=%d")
   TRC_MSG(L1AUDIO_WRITE_DSP_SECOND_SEGMENT, "2ndDSPStrAddr=%d, Len=%d")
   TRC_MSG(L1AUDIO_WRITE_MCU_FIRST_SEGMENT, "1st, MBR=%d, %dW")
   TRC_MSG(L1AUDIO_WRITE_MCU_SECOND_SEGMENT, "2nd, MBR=%d, %dW")

   TRC_MSG(L1AUDIO_DSP_ERROR, "ERROR! DSP decodes bitstream")
   TRC_MSG(L1AUDIO_MCU_ERROR, "ERROR! MCU parses packet")
   TRC_MSG(L1AUDIO_READ_FILE_ERROR, "ERROR! File Error = %d")
   TRC_MSG(L1AUDIO_PARAMETER_ERROR, "ERROR! DSP returns parameter error")
   TRC_MSG(L1AUDIO_TRIM_INFO, "[L1AU][INFO]Infoindex: %d, (1) %d, (2): %d, (3): %d")
   TRC_MSG(L1AUDIO_TRIM_RANGE, "[L1AU][TRIM]Start: %d END: %d, time(0)/offset(1): %d")

   //DSP DEBUG
   TRC_MSG(DSPDEBUG_CTRLFLOW, "[AUDIO_DSPDebug]Control_Flow:flow(%x), I(%x)")

   //pcm strm drv
   TRC_MSG(L1AUDIO_PCM_STRM_BUF_OVFLOW, "PCM STRM: BUF_OverFlow")
   TRC_MSG(L1AUDIO_PCM_STRM_IDLE, "PCM STRM: IDLE_STATE")
   TRC_MSG(L1AUDIO_PCM_STRM_END, "PCM STRM: END_STATE")
   TRC_MSG(L1AUDIO_PCM_STRM_RUN, "PCM STRM: RUN_STATE")
   TRC_MSG(L1AUDIO_PCM_STRM_SILENCE, "PCM STRM: Silence %d")
   TRC_MSG(L1AUDIO_PCM_STRM_WDATA_IDMA, "PCM STRM: Addr=%d, Len=%d")

   // AUD RTP
   TRC_MSG(RTP_AUD_CONFIG, "RTP_AAC_Config, SR = %d, FrameDur = %d, channel# = %d")
   TRC_MSG(RTP_AUD_MB_UF, "RTP_MB_UF, pos = %d, type = %d")
   TRC_MSG(RTP_AUD_MB_OF, "RTP_MB_OF, pos = %d, type = %d")
   TRC_MSG(RTP_AUD_PKT_LOSS, "RTP_PKT_LOSS, loss = %d, type = %d")
   TRC_MSG(RTP_AUD_DISCAR, "RTP_PKT_DISCAR, p # = %d, type = %d")
   TRC_MSG(RTP_AUD_PutPktToJitter, "PutPktToJitterBuffer, seq number = %d, jitter count = %d, pos = %d, type = %d")
   TRC_MSG(RTP_AUD_PutPktFromJitter, "PutPktFromJitBufWithSilence, seq number = %d, jitter count = %d, type = %d")
   TRC_MSG(RTP_AUD_PutPkt, "PutPktFromJitBufInOrder, seq number = %d, jitter count = %d, type = %d")
   TRC_MSG(RTP_AUD_GetFromJitter, "Jitter Info, seq number = %d, jitter count = %d, pos = %d")
   TRC_MSG(RTP_AUD_PUTPKT_FST, "RTP_PUTPKT_FST, p # = %d")
   TRC_MSG(RTP_AUD_PUTPKT_FUNC, "RTP_PUTPKT_FUNC, packet# = %d, timestamp = %d, size = %d, type = %d")
   TRC_MSG(RTP_AUD_PUT_SIL, "RTP_Put_Silence, packet# = %d, frames = %d, type = %d")
   TRC_MSG(RTP_AUD_Info, "AAC-LATM_bufSize_Error, seq number = %d, Residual Buffer Size = %d, type = %d")
   TRC_MSG(RTP_AUD_PUT_PKT, "RTP_Put_Packet_To_Buf, packet# = %d, timestamp = %d, type = %d")
   TRC_MSG(RTP_AUD_FRM_IN_BUF, "RTP_Frame_In_Buf, frame count = %d, type = %d")
   TRC_MSG(RTP_AUD_FRM_IN_PKT, "RTP_Frame_In_packet, frame count = %d, type = %d")
   TRC_MSG(RTP_AUD_BUF_STATUS, "RTP_Buffer_Status, CurBufDur = %d, BufTotalSize = %d, BufFreeSize = %d, MinBufTotalDur = %d")
   TRC_MSG(RTP_AUD_CheckPkts, "RTP_AUD_CheckPkts, Start Seq = %d, CurSeqNum = %d, CurWriteIdx = %d, wirteIdx = %d, diff = %d")
   TRC_MSG(RTP_AUD_CHK_PKT, "RTP_AUD_CheckPkt, Start Seq = %d, type = %d")
   TRC_MSG(RTP_AUD_DROP_PKT, "RTP_AUD_DropPkt, Case = %d, type = %d")
   TRC_MSG(RTP_AUD_DRA_ERROR, "RTP_AUD_DRA Error %d")
   TRC_MSG(RTP_AUD_ADD_DELAY_IN, "RTP_AUD_AddDelay Desired %d ms, type = %d")
   TRC_MSG(RTP_AUD_ADD_DELAY_OUT, "RTP_AUD_AddDelay Resulted %d ms, type = %d")
   TRC_MSG(RTP_AUD_AAC_TIMESTAMP_PER_FRAME, "RTP_AUD_AAC Timestamp per frame: %d, aac type: %d (if Generic aac: 4096), IsFIX: %d")
   TRC_MSG(RTP_AUD_AAC_WRONG_SILENCE_FRAME, "RTP_AUD_AAC Wrong Silence Frame, Generic aac with 2048 timestamp/frame")

   // APM (Audio Post-Processing Manager)
   TRC_MSG(APM_ACTIVATE_INFO, "APM:Activate Task %d, Sampling Frequency %d, Channels %d")
   TRC_MSG(APM_ACTIVATING, "APM:Activating ID %d")
   TRC_MSG(APM_DEACTIVATE_INFO, "APM:Deactivate Task %d")
   TRC_MSG(APM_DEACTIVATING, "APM:Deactivating ID %d")
   TRC_MSG(APM_REGISTER, "APM:Register ID %d, Original tasks %d")
   TRC_MSG(APM_UNREGISTER, "APM:Unregister ID %d, Original tasks %d")
   TRC_MSG(APM_CLEARBUFFER, "APM:Clear Buffer")
   TRC_MSG(APM_EOF, "APM:EOF task %d")
   TRC_MSG(APM_TRUNCATE, "APM:Truncate outTempBuf")
   TRC_MSG(APM_IN_OVFLOW, "APM: In OVFLOW")
   TRC_MSG(APM_OUT_UDFLOW, "APM: OUT UDFLOW")
   TRC_MSG(APM_BS_DISABLE, "APM: Bessound Disable")
   TRC_MSG(APM_BS_ENABLE, "APM: Bessound enable")
   TRC_MSG(APM_BS_DISABLE_VIDEO, "APM: Bessound Disable in video")
   TRC_MSG(APM_BS_ENABLE_VIDEO, "APM: Bessound enable in video")
   TRC_MSG(APM_NOT_SUPPORT_AVBT, "APM: Not Support AvBT")


   // Audio Post Process
   TRC_MSG(L1AUDIO_PP_SET_3D, "Enter AudioPP_Set3D, set 3D effect cofeeicients")
   TRC_MSG(L1AUDIO_PP_SET_TS, "Enter AudioPP_SetTS, set speed mode %d")
   TRC_MSG(L1AUDIO_PP_3D_STATE, "3D effect is in state %d")
   TRC_MSG(L1AUDIO_PP_3D_WAIT_ADDRESS, "3D effect waits DSP for getting address")
   TRC_MSG(L1AUDIO_PP_3D_GET_ADDRESS, "3D effect gets coefficient address")
   TRC_MSG(L1AUDIO_PP_TS_STATE, "TS is in state %d")
   TRC_MSG(L1AUDIO_PP_IN_IDLE, "[AudioPP] AudioPP in Idle")

   // L1SP
   TRC_MSG(L1SP_SET_MODE, "L1SP set mode=%d, spk_lev=%d, mic_lev=%d")
   TRC_MSG(L1SP_APPLY_MODE, "L1SP on=%d, mode=%d, spk_lev=%d, mic_lev=%d")
   TRC_MSG(L1SP_SPEECH_ENHANCEMENT, "L1SP turn on speech enhancement flag=%d, m0=%d, m1=%d, c0=%d, c1=%d")
   TRC_MSG(L1SP_SET_MIC_VOL, "L1SP Set Mic Vol %d, sph_par %d")
   TRC_MSG(L1SP_ADAPT_MIC_VOL, "L1SP Adapt Mic Vol %d")
   TRC_MSG(L1SP_INC_SPK_VOL, "L1SP DSP Inc Spk Vol to %d, report %d")

   TRC_MSG(DACA_EXCEPTION,    "[DATACARD]Expection %d")
   TRC_MSG(DACA_OPEN_PORT,     "[DATACARD]mode=%d port %d")
   TRC_MSG(DACA_PLUGIN,        "[DATACARD]PlugIn mode=%d")
   TRC_MSG(DACA_STRM_ENABLE,   "[DATACARD]Enable mode=%d")
   TRC_MSG(DACA_STRM_DISABLE,  "[DATACARD]Disable mode=%d")
   TRC_MSG(L1SP_DEC_SPK_VOL, "L1SP DSP Dec Spk Vol to %d, report %d")
   TRC_MSG(L1SP_2MIC_STATE, "L1SP 2Mic Enter Speech Mode %d, sph_state %d")
   TRC_MSG(L1SP_2MIC_SLEEP, "L1SP 2Mic Enter Sleep Mode")
   TRC_MSG(L1SP_2MIC_ENTER_BYPASS, "L1SP 2Mic Enter Bypass mode")
   TRC_MSG(L1SP_2MIC_EXIT_BYPASS, "L1SP 2Mic Exit Bypass Mode(Enter Sleep mode)")

   TRC_MSG(L1SP_USELESS_SET, "SPH[ENH] %d, %d, %d, %d")

   TRC_MSG(SPC_SPEECH_ON,              "Spc_Speech_On %d")
   TRC_MSG(SPC_SPEECH_OFF,             "Spc_Speech_Off")
   TRC_MSG(SPC_SET_MIC_VOL,            "Spc_SetMicrophoneVolume %d")
   TRC_MSG(SPC_SET_SIDETONE_VOL,       "Spc_SetSidetoneVolume %d")
   TRC_MSG(SPC_TONE_PLAY,              "Spc_Default_Tone_Play %d %d")
   TRC_MSG(SPC_TONE_STOP,              "Spc_Default_Tone_Stop")
   TRC_MSG(SPC_SET_OUTPUT_VOL1,        "Spc_SetOutputVolume %d digital_gain_index = %d")
   TRC_MSG(SPC_SET_OUTPUT_VOL2,        "Spc_SetOutputVolume %d gain_idx %d")
   TRC_MSG(SPC_SET_INPUT_SRC1,         "Spc_SetInputSource param = %d")
   TRC_MSG(SPC_SET_INPUT_SRC2,         "Spc_SetInputSource device=%d")
   TRC_MSG(SPC_SET_OUTPUT_DEVICE1,     "Spc_SetOutputDevice param=%d")
   TRC_MSG(SPC_SET_OUTPUT_DEVICE2,     "Spc_SetOutputDevice device=%d")
   TRC_MSG(SPC_SET_SPEECHMODE_ADAPT,   "Spc_SetSpeechMode_Adaptation mode = %d")
   TRC_MSG(SPC_RECORD_ON,              "Spc_Record_On")
   TRC_MSG(SPC_RECORD_OFF,             "Spc_Record_Off")
   TRC_MSG(SPC_RECORD_RESULT,          "Spc_Record Result = %d")
   TRC_MSG(SPC_RECORD_OVERFLOW,        "Spc_Record Overflow, r=%d, w=%d")

   TRC_MSG(L1SP_ENABLE_DUAL_MIC_NR, "L1SP Set Dual Mic NR %d")
   TRC_MSG(L1SP_Mute_PCM_Ouput_Port, "L1SP Mute PCM Output Port: %d")
   TRC_MSG(L1SP_DMNR_LOOPBACK_FROM_MIC,            "[DMNR Loopback]FromMic %d %d %d %d")
   TRC_MSG(L1SP_DMNR_LOOPBACK_SKIP_MIC,            "[DMNR Loopback]Skip FromMic")
   TRC_MSG(L1SP_DMNR_LOOPBACK_TO_SE,               "[DMNR Loopback]ToSE %d %d %d %d")
   TRC_MSG(L1SP_DMNR_LOOPBACK_FILL_SE,             "[DMNR Loopback]FillSE")
   TRC_MSG(L1SP_DMNR_LOOPBACK_FROM_SD,             "[DMNR Loopback]FromSD %d %d %d %d")
   TRC_MSG(L1SP_DMNR_LOOPBACK_SKIP_SD,             "[DMNR Loopback]Skip FromSD")
   TRC_MSG(L1SP_DMNR_LOOPBACK_TO_SPK,              "[DMNR Loopback]ToSPK %d %d %d %d")
   TRC_MSG(L1SP_DMNR_LOOPBACK_FILL_SPK,            "[DMNR Loopback]FillSpk")
   TRC_MSG(L1SP_DMNR_LOOPBACK_UL_DL_INDEX,         "[DMNR Loopback]Dw, Dr, Uw, Ur %d %d %d %d")
   TRC_MSG(L1SP_DMNR_LOOPBACK_ILLEGAL_OPEN,        "[DMNR Loopback]illegal DMNR Loopback open")
   TRC_MSG(L1SP_DMNR_LOOPBACK_ILLEGAL_CLOSE,       "[DMNR Loopback]illegal DMNR Loopback close")
   TRC_MSG(L1SP_SET_ENHANCEMENT, "L1SP Set Enhancement keep=%x, turnOn=%x, turnOff=%x")
   TRC_MSG(L1SP_ENHANCE_ON_OFF, "L1SP turn enhance =%d, with state=%x")
   TRC_MSG(L1SP_SET_ENH_FIR, "SPH[ENH] enhancement mode %d, enhance Index %d, inFIR Index %d, outFIR Index %d, updateMask %d to value %d")
   TRC_MSG(L1SP_CHANGE_ENH_MODE, "SPH[ENH] ChangeSpeechMode premode=%d, aftermode=%d, currentMode=%d")
   TRC_MSG(L1SP_WRITE_FIR, "SPH[ENH] Write FIR isWB=%d")
   TRC_MSG(L1SP_UPDATE_SPE_APP_MASK, "SPH[ENH] Update spe app mask, spe_app_mask=%x, spe_usr_mask=%x, flags=%x, on/off=%d")
   TRC_MSG(L1SP_UPDATE_SPE_USR_MASK, "SPH[ENH] Update spe usr mask, spe_app_mask=%x, spe_usr_mask=%x, flags=%x, on/off=%d")
   TRC_MSG(L1SP_SET_MIC_GAIN_CONTROL,              "[MIC GAIN CONTROL]L1SP set mic gain control %x")
   TRC_MSG(L1SP_ADAPT_MIC_GAIN_CONTROL,            "[MIC GAIN CONTROL]L1SP adapt mic gain control %x")

   // VoRTP
   TRC_MSG(VORTP_ENTER_STARTTONE, "[VoRTP] Enter StartInbandTone; f1=%d, f2=%d, dB=%d, dura=%d")
   TRC_MSG(VORTP_ENTER_STOPTONE, "[VoRTP] Enter StopInbandTone")
   TRC_MSG(VORTP_UL_ENTER_OPEN, "[VoRTP] Enter OpenULChannel")
   TRC_MSG(VORTP_UL_ENTER_CONFIG, "[VoRTP] Enter UL::Config; type=%d, sid=%d")
   TRC_MSG(VORTP_UL_ENTER_SETBUFFER, "[VoRTP] Enter UL::SetBuffer; size=%d")
   TRC_MSG(VORTP_UL_ENTER_START, "[VoRTP] Enter UL::Start; sid=%d, ts=%d")
   TRC_MSG(VORTP_UL_ENTER_STOP, "[VoRTP] Enter UL::Stop; sid=%d")
   TRC_MSG(VORTP_UL_ENTER_CLOSE, "[VoRTP] Enter UL::Close")
   TRC_MSG(VORTP_UL_ENTER_SETMIX, "[VoRTP] Enter UL::SetMix; val=%d")
   TRC_MSG(VORTP_DL_ENTER_OPEN, "[VoRTP] Enter OpenDLChannel")
   TRC_MSG(VORTP_DL_ENTER_CONFIG, "[VoRTP] Enter DL::Config; type=%d, sid=%d")
   TRC_MSG(VORTP_DL_ENTER_SETBUFFER, "[VoRTP] Enter DL::SetBuffer; size=%d")
   TRC_MSG(VORTP_DL_ENTER_START, "[VoRTP] Enter DL::Start; sid=%d")
   TRC_MSG(VORTP_DL_ENTER_STOP, "[VoRTP] Enter DL::Stop; sid=%d")
   TRC_MSG(VORTP_DL_ENTER_CLOSE, "[VoRTP] Enter DL::Close")
   TRC_MSG(VORTP_JITTER_INFO, "[VoRTP] DL-Jitter; sid=%d, depth=%d, curJit=%d, old_ts=%d, new_ts=%d")
   TRC_MSG(VORTP_JITTER_OVERRUN, "[VoRTP] DL-Jitter; sid=%d, overrun=%d")
   TRC_MSG(VORTP_JITTER_PREBUF, "[VoRTP] DL-Jitter; sid=%d, prebuf=%d, fn=%d")
   TRC_MSG(VORTP_DL_ARRIVAL, "[VoRTP] DL-Arrival; sid=%d, seq=%d, ts=%d, type=%d, payload_sz=%d, pt=%d, m=%d")
   TRC_MSG(VORTP_DL_PLAY, "[VoRTP] DL-Play; sid=%d, seq=%d, ts=%d, type=%d, payload_sz=%d, pt=%d, m=%d")
   TRC_MSG(VORTP_UL_BORN, "[VoRTP] UL-Born; sid=%d, ts=%d, type=%d, payload_sz=%d, m=%d")
   TRC_MSG(VORTP_UL_SENT, "[VoRTP] UL-Sent; sid=%d, ts=%d, type=%d, payload_sz=%d, m=%d")
   TRC_MSG(VORTP_DL_INFO1, "[VoRTP] DL-Info; sid%d, arriv=%d, play=%d, miss=%d")
   TRC_MSG(VORTP_JITTER_BURST, "[VoRTP] DL-Burst; sid%d, curJit=%d, prevMaxJit=%d, latestBurstJit=%d")
   TRC_MSG(VORTP_JITTER_BURST_STATE, "[VoRTP] DL-Burst; sid=%d, isBurstState=%d")

   TRC_MSG(VORTP_CODEC_REG_G711, "[VoRTP] REG g711 cn=%d")
   TRC_MSG(VORTP_CODEC_REG_G726_16, "[VoRTP] REG g726_16 cn=%d")
   TRC_MSG(VORTP_CODEC_REG_G726_24, "[VoRTP] REG g726_24 cn=%d")
   TRC_MSG(VORTP_CODEC_REG_G726_32, "[VoRTP] REG g726_32 cn=%d")
   TRC_MSG(VORTP_CODEC_REG_G726_40, "[VoRTP] REG g726_40 cn=%d")
   TRC_MSG(VORTP_CODEC_REG_G729, "[VoRTP] REG g729 annexb=%d")
   TRC_MSG(VORTP_CODEC_REG_G7231, "[VoRTP] REG g7231 annexa=%d, bitrate=%d")

   TRC_MSG(VORTP_DUPLICATE_PACKET, "[VoRTP] Warning: src packet size = %d, dest array size = %d")

   TRC_MSG(VORTP_DUR_SYSTIME, "[VoRTP] warning:dur_systime=%d")
   TRC_MSG(VORTP_UL_START, "[VoRTP] vortp_ul_Start: %d B")
   TRC_MSG(VORTP_DL_START, "[VoRTP] vortp_dl_Start: %d B")
   TRC_MSG(VORTP_DUR_FTJBC_ON, "[VoRTP] FTJBC on")
   TRC_MSG(VORTP_DUR_FTJBC_OFF, "[VoRTP] FTJBC off")
   TRC_MSG(VORTP_SRC_CANNOT_OPEN, "[VoRTP] autorec: source file can't open")
   TRC_MSG(VORTP_VOIP_AUTOREC_STOP, "[VoRTP] VoIP auto recording stop")
   TRC_MSG(VORTP_CONTEXT, "[VoRTP] context.audId=%d, VoRTP_context.numStreams=%d")
   TRC_MSG(VORTP_UL_STATE, "[VoRTP] UL%d: state=%d, sid=%d")
   TRC_MSG(VORTP_UL_FIFO, "[VoRTP] UL%d fifo: read=%d, write=%d")
   TRC_MSG(VORTP_DL_STATE, "[VoRTP] DL%d: state=%d, sid=%d")
   TRC_MSG(VORTP_SYS_SAVE, "[VoRTP] sys.save = %d")
   TRC_MSG(VORTP_SYS_LOOPBACK, "[VoRTP] sys.loopback = %d")
   TRC_MSG(VORTP_SYS_AUTOREC, "[VoRTP] sys.autorec = %d/%d, %d")
   TRC_MSG(VORTP_IS_REC_PCM, "[VoRTP] is_rec_pcm = %d")
   TRC_MSG(VORTP_IS_REC_DL, "[VoRTP] is_rec_dl = %d")
   TRC_MSG(VORTP_IS_REC_UL, "[VoRTP] is_rec_ul = %d")
   TRC_MSG(VORTP_SYS_JITTER, "[VoRTP] sys.jitter = %d, %d")
   TRC_MSG(VORTP_JITTER_VAR_MUL, "[VoRTP] jitter_var_mul = %d")
   TRC_MSG(VORTP_JITTER_MEAN_RUN, "[VoRTP] jitter_mean_run = %d")
   TRC_MSG(VORTP_OPEN_SUCCESS, "[VoRTP] open %d success")
   TRC_MSG(VORTP_OPEN_FAIL, "[VoRTP] open %d fail")
   TRC_MSG(VORTP_QUERY_RESULT, "[VoRTP] query %d result - %d,%d,%d,%d")
   TRC_MSG(VORTP_QUERY_G729_FAIL, "[VoRTP] query %d g729 result fail")
   TRC_MSG(VORTP_QUERY_G729_RESULT, "[VoRTP] query %d g729 result - ptime=%d, maxptime=%d, annexb=%d")
   TRC_MSG(VORTP_QUERY_G7231_FAIL, "[VoRTP] query %d g7231 result fail")
   TRC_MSG(VORTP_QUERY_G7231_RESULT, "[VoRTP] query %d g7231 result - ptime=%d, maxptime=%d, annexa=%d")
   TRC_MSG(VORTP_QUERY_G726_32_FAIL, "[VoRTP] query %d g726_32 result fail")
   TRC_MSG(VORTP_QUERY_G726_32_RESULT, "[VoRTP] query %d g726_32 result - ptime=%d, maxptime=%d, cn=%d")
   TRC_MSG(VORTP_QUERY_G711_A_FAIL, "[VoRTP] query %d g711_a result fail")
   TRC_MSG(VORTP_QUERY_G711_A_RESULT, "[VoRTP] query %d g711_a result - ptime=%d, maxptime=%d, cn=%d")
   TRC_MSG(VORTP_UNKNOWN_CODEC, "[VoRTP] unknown codec")
   TRC_MSG(VORTP_CONFIG_UL_FAIL, "[VoRTP] config %d uplink fail - %d")
   TRC_MSG(VORTP_CONFIG_DL_FAIL, "[VoRTP] config %d downlink fail - %d")
   TRC_MSG(VORTP_CONFIG_OK, "[VoRTP] config %d ok")
   TRC_MSG(VORTP_SETBUF_UL_FAIL, "[VoRTP] setbuffer %d uplink fail - %d")
   TRC_MSG(VORTP_SETBUF_UL_OK, "[VoRTP] setbuffer_ul %d, %d ok")
   TRC_MSG(VORTP_SETBUF_DL_FAIL, "[VoRTP] setbuffer %d downlink fail - %d")
   TRC_MSG(VORTP_SETBUF_DL_OK, "[VoRTP] setbuffer_dl %d, %d ok")
   TRC_MSG(VORTP_START_UL_FAIL, "[VoRTP] start %d uplink fail - %d")
   TRC_MSG(VORTP_START_DL_FAIL, "[VoRTP] start %d downlink fail - %d")
   TRC_MSG(VORTP_START_OK, "[VoRTP] start %d ok")
   TRC_MSG(VORTP_STOP_UL_FAIL, "[VoRTP] stop %d uplink fail - %d")
   TRC_MSG(VORTP_STOP_DL_FAIL, "[VoRTP] stop %d downlink fail - %d")
   TRC_MSG(VORTP_STOP_OK, "[VoRTP] stop %d ok")
   TRC_MSG(VORTP_CLOSE_UL_FAIL, "[VoRTP] close %d uplink fail - %d")
   TRC_MSG(VORTP_CLOSE_DL_FAIL, "[VoRTP] close %d downlink fail - %d")
   TRC_MSG(VORTP_CLOSE_OK, "[VoRTP] close %d ok")
   TRC_MSG(VORTP_TONEON_OK, "[VoRTP] toneon ok")
   TRC_MSG(VORTP_TONEON_FAIL, "[VoRTP] toneon fail - %d")
   TRC_MSG(VORTP_TONEOFF_OK, "[VoRTP] toneoff OK")
   TRC_MSG(VORTP_TONEOFF_FAIL, "[VoRTP] toneoff fail - %d")
   TRC_MSG(VORTP_UNKNOWN_COMMAND, "[VoRTP] unknown command")

   // DAF stream sender over RTP
   TRC_MSG(ENTER_A2DP_DAF_OPEN, "Enter A2DP_DAF_Open")
   TRC_MSG(ENTER_A2DP_DAF_CLOSE, "Enter A2DP_DAF_Close")
   TRC_MSG(DAFRTP_PUTDATA, "DAFRTP PutData, putlen=%d, elapsed: %d, wait: %d")
   TRC_MSG(DAFRTP_GETDATA, "DAFRTP GetData, buflen=%d, getlen: %d, elapsed: %d, sample: %d, header: %d")
   TRC_MSG(DAFRTP_FRAMESYNC, "DAFRTP FrameSync, skip=%d, framelen: %d, bitrate: %d")

   // Audio Cache
   TRC_MSG(L1AUDIO_SET_CACHE_TBL, "Set Cache Table, type = %d")
   TRC_MSG(L1AUDIO_BUILD_CACHE, "Build Cache, type = %d, Ret = %d, Prog = %d")
   TRC_MSG(L1AUDIO_CACHE_STROFFSET, "Cache_Start_Offset, type = %d, idx = %d, offset = %d")
   TRC_MSG(L1AUDIO_CACHE_ACCFRAME, "Cache_Accumulated_Frame, type = %d, idx = %d, frame = %d")
   TRC_MSG(L1AUDIO_CACHE_FINISH_RETURN, "Cache Finished Return, type = %d")
   TRC_MSG(L1AUDIO_CACHE_END, "Cache End, type = %d, total frame = %d")
   TRC_MSG(L1AUDIO_CACHE_FAILED, "Cache Fail, type = %d, total frame = %d")
   TRC_MSG(L1AUDIO_SEEK_RESULT, " Seek Result, type=%d, Start Frame=%d, Offset=%d, ST(ms)=%d")
   TRC_MSG(L1AUDIO_SEEK_FAIL, " Seek Fail, type=%d, Start Frame=%d, Offset=%d, ST(ms)=%d")
   TRC_MSG(L1AUDIO_CACHE_GET_DUR, "Cache_Get_Duration, type = %d, dur = %d")
   TRC_MSG(L1AUDIO_CACHE_GET_DUR_F, "Cache_Get_Duration_F, type = %d, dur = %d")
   TRC_MSG(L1AUDIO_CACHE_GET_TOTAL_DUR, "Cache_Get_Total_Duration, type = %d, dur = %d")
   TRC_MSG(L1AUDIO_CACHE_FILE_SIZE, "File Size, type = %d, file size = %d")

   // AST
   TRC_MSG(L1AUDIO_AST_INIT, "[AST]Initial AST, Entry Number = %d, BufSize = %u")
   TRC_MSG(L1AUDIO_AST_FRAME_PER_ENTRY, "[AST]AST Entry Size, frame number = %u")
   TRC_MSG(L1AUDIO_AST_BUILD_TABLE, "[AST]Build AST Parsing Frame, Result = %u, Demand Parse frame = %u, Actual Parse frame = %u")
   TRC_MSG(L1AUDIO_AST_SEEK, "[AST]Seek in AST, destiny frame = %u, actual achieve frame = %u, offset = %u")
   TRC_MSG(L1AUDIO_AST_GET_INDEXED_FRAME, "[AST]Indexed Frame in AST: frame = %u")
   TRC_MSG(L1AUDIO_AST_GET_TOTAL_FRAME, "[AST]Estimated Total Frames: frame = %u")
   TRC_MSG(L1AUDIO_AST_UPDATE_TABLE, "[AST]Update AST table, Index = %u, Frame = %u, Offset = %u")

   // TTS
   TRC_MSG(TTS_TEXT_CONTENT, "TTS Content")
   TRC_MSG(TTS_IFLYTTS, "iFlyTTS Output=%d")
   TRC_MSG(TTS_SPCM_BUF, "Spcm Buf ptr=%x,len=%d")
   TRC_MSG(TTS_TASK_DONE, "TTS Task done %d")
   TRC_MSG(TTS_GET_DATA, "TTS GetData len=%d")
   TRC_MSG(TTS_PUT_SPCM, "JTTs put Spcm %d data")
   TRC_MSG(TTS_SET_BUF, "TTS SetBuffer %d")
   TRC_MSG(TTS_PLAY, "TTS Play")
   TRC_MSG(TTS_TDIC_ERR, "TDic Err =%d")
   TRC_MSG(TTS_JTTS_ERR, "jTTS Err =%d")
   TRC_MSG(TTS_TTS_STATE, "TTS state %d")
   TRC_MSG(TTS_TRC_PAUSE, "TTS Pause")
   TRC_MSG(TTS_RESUME, "TTS Resume")
   TRC_MSG(TTS_ENTER_STOP, "TTS enter Stop")
   TRC_MSG(TTS_LEAVE_STOP, "TTS leave Stop")
   TRC_MSG(TTS_CLOSE, "TTS Close")
   TRC_MSG(TTS_TDIC_SETPITCH, "TDIC SetPitch %d")
   TRC_MSG(TTS_SET_SPEED, "TTS SetSpeed %d")
   TRC_MSG(TTS_SET_VOL, "TTS SetVol %d")
   TRC_MSG(TTS_SPCM_EVENT, "TTS spcm_event %d")
   TRC_MSG(TTS_PRC_MED_END, "TTS PRC MED END")
   TRC_MSG(TTS_TDIC_GET_DATA, "TDIC get %d data%d, remain %d")
   TRC_MSG(TTS_TDIC_GET_NODATA, "TDIC Get No Data")
   TRC_MSG(TTS_TDIC_RPC_DONE, "TDIC PRC done")
   TRC_MSG(TTS_TDIC_RPC_NEED, "TDIC PRC needed")
   TRC_MSG(TTS_TDIC_RPC_DATA, "TDIC PRC data")
   TRC_MSG(TTS_TDIC_ERR_CODE, "TDic error code = %d")
   TRC_MSG(TTS_SET_ATTR, "TTSSetAttr id %x, val %x")

   // 3G speech
   TRC_MSG(SP3G_RAB_EST, "SP3G CSR notify RAB establish")
   TRC_MSG(SP3G_RAB_DEEST, "SP3G CSR notify RAB De-establish")
   TRC_MSG(SP3G_TX_SID_FIRST, "SP3G_HISR TX SID FISRT")
   TRC_MSG(SP3G_TX_SID_UPDATE, "SP3G_HISR TX SID UPDATE")
   TRC_MSG(SP3G_RX_SID_FIRST, "SP3G_HISR RX SID FISRT")
   TRC_MSG(SP3G_RX_SID_UPDATE, "SP3G_HISR RX SID UPDATE")
   TRC_MSG(SP3G_RX_NO_DATA, "SP3G_HISR RX GET NO DATA FRAME")
   TRC_MSG(SP3G_DTX_NO_DATA, "SP3G_HISR INSERT NO DATA")
   TRC_MSG(SP3G_BUFFER_STATUS, "SP3G_HISR DL r = %d, w = %d, num = %d, 1st byte = %x")
   TRC_MSG(SP3G_UL_DELAY, "SP3G UL delay %d")
   TRC_MSG(SP3G_REQUEST, "SP3G Request")
   TRC_MSG(SP3G_REQUEST_UL_FRAME_TYPE, "SP3G set UL frame type %MtSP3G_SpeechCodecType")
   TRC_MSG(SP3G_UL_GET_SPEECH_FRAME, "SP3G UL GetSpFrame")
   TRC_MSG(SP3G_DL_BUFFER_FINISH, "SP3G DL Buffering finished")
   TRC_MSG(SP3G_DL_PUT_SPEECH_FRAME, "SP3G DL sub_flow %d, frame_type %MtSP3G_SpeechCodecType, crc_status %d")
   TRC_MSG(SP3G_LOG_L1_INFO, "SP3G CFN=%x, l1info=%x, crc = %x, s_val =%x, %x, %x")
   TRC_MSG(SP3G_L1A_UPDATE_INFO, "SP3G Update Info bitmap %d, val %d")
   TRC_MSG(SP3G_INVALID_UL_CODEC_MODE, "SP3G invalid UL codec mode %d")
   TRC_MSG(SP3G_SET_DTX, "SP3G Set DTX %d")

   TRC_MSG(SP3G_UL_BIT_TRUE_DSP_F8, "SP3GHISR UL DSP len %d, %hx %hx %hx %hx %hx %hx %hx %hx")
   TRC_MSG(SP3G_UL_BIT_TRUE_DSP_N8, "SP3GHISR UL DSP %hx %hx %hx %hx %hx %hx %hx %hx")
   TRC_MSG(SP3G_TX_SPEECH_GOOD, "SP3G_HISR UL is TX_SPEECH_GOOD")
   TRC_MSG(SP3G_UL_NO_DATA, "SP3G_HISR UL is NO DATA")
   TRC_MSG(SP3G_UL_BIT_TRUE_F8, "SP3G_HISR=%d UL Type %dtSP3G_SpeechCodecType, Frm %hx %hx %hx %hx %hx %hx %hx %hx")
   TRC_MSG(SP3G_UL_BIT_TRUE_N13, "SP3G UL %hx %hx %hx %hx %hx %hx %hx %hx %hx %hx %hx %hx %hx")
   TRC_MSG(SP3G_UL_BUFFER, "SP3GVT UL cnt=%d,r=%d,w=%d")
   TRC_MSG(SP3G_DL_BIT_TRUE, "SP3G_HISR DL Type %d, Frm %x %x %x %x %x")
   TRC_MSG(SP3G_DL_BIT_TRUE_TASK, "SP3G DL Frm %x %x %x %x %x")
   TRC_MSG(SP3G_DL_BIT_TRUE_DSP_F8, "SP3GHISR DL DSP len %d, %hx %hx %hx %hx %hx %hx %hx %hx")
   TRC_MSG(SP3G_DL_BIT_TRUE_DSP_N8, "SP3GHISR DL DSP %hx %hx %hx %hx %hx %hx %hx %hx")
   TRC_MSG(SP3GVT_FAKE_NODATA, "SP3GVT Fake NoData")


   //VT
   TRC_MSG(SP3GVT_UL_GET_SPEECH_FRAME, "SP3GVT UL GetSpFrm, CurFrmCount %d")
   TRC_MSG(SP3GVT_UL_FRAME_INFO, "SP3GVT UL Frm len %d, first 3 byte %x %x %x")
   TRC_MSG(SP3GVT_DL_FRAME_INFO, "SP3GVT DL Frm len %d, first 3 byte %x %x %x")
   TRC_MSG(SP3GVT_DL_FRAME_ERROR, "SP3GVT DL FrmType Err Warning %d !!")
   TRC_MSG(SP3GVT_SET_DELAY, "SP3GVT SetDelay %d ms, about %d frame")

   //LG speech engine
   TRC_MSG(L1AUDIO_VC_START, "VC Start")
   TRC_MSG(L1AUDIO_VC_STOP, "VC Stop")
   TRC_MSG(L1AUDIO_VC_UNDERFLOW, "VC underflow, fill silence")
   TRC_MSG(L1AUDIO_VC_HISR, "VC hisr r=%d %d, w=%d %d")
   TRC_MSG(L1AUDIO_VC_TASK_PROCESS, "VC process done frame %d %d")
   TRC_MSG(L1AUDIO_VC_TASK_UPDATE, "VC process update process_ptr %d %d")
   TRC_MSG(L1AUDIO_VS_START, "VS Start")
   TRC_MSG(L1AUDIO_VS_STOP, "VS Stop")
   TRC_MSG(L1AUDIO_VS_UNDERFLOW, "VS underflow, fill silence")
   TRC_MSG(L1AUDIO_VS_HISR, "VS hisr r=%d %d, w=%d %d")
   TRC_MSG(L1AUDIO_VS_TASK_PROCESS, "VS DRC process done frame %d %d")
   TRC_MSG(L1AUDIO_VS_TASK_UPDATE, "VS DRC process update process_ptr %d %d")

   //VM
   TRC_MSG(VM_CONTROL, "vm_con : %x")
   TRC_MSG(VM_SP3G_VM_L1T, "SP3G VM L1T %x")

   // CCCI Message
   TRC_MSG(L1AUDIO_PROCESS_A2M_COMMAND, "SPC process A2M Msg Type = %d, Func Type = %d, par = %d")
   TRC_MSG(L1AUDIO_FINISH_A2M_COMMAND, "SPC finish A2M Msg Type = %d, Func Type = %d, par = %d")
   TRC_MSG(L1AUDIO_PROCESS_A2M_DATA_NOTIFY, "SPC process A2M Data, Type = %d, Func Type = %d, offset = %X, len = %X")
   TRC_MSG(L1AUDIO_FINISH_A2M_DATA_NOTIFY, "SPC finish A2M Data, Type = %d, Func Type = %d, offset = %X, len = %X")
   TRC_MSG(L1AUDIO_SEND_M2A_MESSAGE, "SPC send M2A message %08X")
   TRC_MSG(L1AUDIO_SEND_M2A_MESSAGE_FAIL, "SPC send M2A message %08X fail, ret %d")

   // MIDI DSPSYN
#if defined(__AUDIO_COMPONENT_SUPPORT__)
   //Interface
   TRC_MSG(MELODY_API_OPEN,"MidiAPI_Open, format=%x, hdl=%x")
   // 0x1000: AUDIO_NOT_SUPPORTED
   // 0x1001: Not support multiple playback, and there is already another audio is active
   // 0x1002: in vibration speaker, Not support multiple playback, and there is already another audio is active 
   // 0x1003: only allow one midi device each time
   // 0x1004: over MAXPLAYER
   TRC_MSG(MELODY_API_CLS,"MidiAPI_Close, format=%x, hdl=%x")
   TRC_MSG(MELODY_API_PLAY,"MidiAPI_Play, format=%x, hdl=%x, format=%x, repeat=%x")
   TRC_MSG(MELODY_API_STOP,"MidiAPI_Stop, format=%x, hdl=%x, time=%x")
   TRC_MSG(MELODY_API_RESUME,"MidiAPI_Resume, format=%x, hdl=%x")
   TRC_MSG(MELODY_API_PAUSE,"MidiAPI_Pause, format=%x, hdl=%x, time=%x")

   //Melody Component Operations
   TRC_MSG(MELODY_COMP_INIT,"MidiComp_Init, hdl=%x, device=%x, state=%x")
   TRC_MSG(MELODY_COMP_INITIP,"MidiComp_InitIP, hdl=%x, playerinit=%x, format=%x, melodyinit=%x, gain=%x")
   TRC_MSG(MELODY_COMP_PLAY,"MidiComp_Play, hdl=%x, dur=%x, stateBit=%x, time = %x")
   TRC_MSG(MELODY_COMP_PLAYEND,"MidiComp_PlayOk, hdl=%x, state=%x")
   TRC_MSG(MELODY_COMP_STOP,"MidiComp_Stop, hdl=%x, stateBit=%x")
   TRC_MSG(MELODY_COMP_STOPEND,"MidiComp_StopOK, hdl=%x, state=%x")
   TRC_MSG(MELODY_COMP_FREE,"MidiComp_Free, hdl=%x, stateBit=%x, hdlstate=%x, playerstate=%x")

   //Melody Component Properties
   TRC_MSG(MELODY_COMP_STEMPO,"MidiComp_SetTempo, hdl=%x, tempo = %x")
   TRC_MSG(MELODY_COMP_GTEMPO,"MidiComp_GetTempo, hdl=%x, tempo = %x")
   TRC_MSG(MELODY_COMP_STOPTIME,"MidiComp_SetStopTime, hdl=%x, stoptime = %x")
   TRC_MSG(MELODY_COMP_STARTTIME,"MidiComp_SetStartTime, hdl=%x, starttime = %x")
   TRC_MSG(MELODY_COMP_SRATE,"MidiComp_SetRate, hdl=%x, rate = %x")
   TRC_MSG(MELODY_COMP_STSRATE,"MidiComp_SetTsRate, hdl=%x, tsrate = %x")
   TRC_MSG(MELODY_COMP_GRATE,"MidiComp_GetRate, hdl=%x, rate = %x")
   TRC_MSG(MELODY_COMP_SLEVEL,"MidiComp_SetLevel, hdl=%x, level = %x")
   TRC_MSG(MELODY_COMP_GLEVEL,"MidiComp_GetLevel, hdl=%x, level = %x")
   TRC_MSG(MELODY_COMP_SPITCH,"MidiComp_SetPitch, hdl=%x, pitch = %x")
   TRC_MSG(MELODY_COMP_GPITCH,"MidiComp_GetPitch, hdl=%x, pitch = %x")
   TRC_MSG(MELODY_COMP_SPROGRAM,"MidiComp_SetProgram, hdl=%x, ch=%x, prog = %x")
   TRC_MSG(MELODY_COMP_GPROGRAM,"MidiComp_GetProgram, hdl=%x, ch=%x, prog = %x")
   TRC_MSG(MELODY_COMP_SVOLUME,"MidiComp_SetChVolume, hdl=%x, ch=%x, vol = %x")
   TRC_MSG(MELODY_COMP_GVOLUME,"MidiComp_GetChVolume, hdl=%x, ch=%x, vol = %x")

#else
   TRC_MSG(MIDI_DSPSYN_ENDHDL_IDLE,"DSP Idle")
   TRC_MSG(MIDI_DSPSYN_ENDHDL_END,"CallEndHdlr")
   TRC_MSG(MIDI_DSPSYN_TICK_END,"DSP Ending")
   TRC_MSG(MIDI_DSPSYN_TICK_TERMINATE,"DSP Terminating")
   TRC_MSG(MIDI_DSPSYN_START,"DStart state = %x, condition = %d")
   TRC_MSG(MIDI_DSPSYN_START_TERMINATE,"PutTermCmd")
   TRC_MSG(MIDI_DSPSYN_GETCHANNEL,"GetCh %d")
   TRC_MSG(MIDI_DSPSYN_SETCHANNEL,"SetCh %d")
   TRC_MSG(MIDI_DSPSYN_GETSTOPCMD,"GotStopCmd %d->%d, head=%d, tail=%d")
   TRC_MSG(MIDI_DSPSYN_GETENDCMD,"GotEndCmd %d->%d, head=%d, tail=%d")
   // MIDI SMF
   TRC_MSG(MIDI_JSMF_OPEN,"JSMFOpen, handle = %d")
   TRC_MSG(MIDI_JSMF_CLOSE,"JSMFCls, handle = %d")
   TRC_MSG(MIDI_JSMF_PLAY,"JSMFPlay, handle = %d")
   TRC_MSG(MIDI_JSMF_STOP,"JSMFStop, handle = %d")
   // MIDI IMY
   TRC_MSG(MIDI_JIMY_OPEN,"JIMYOpen, handle = %d")
   TRC_MSG(MIDI_JIMY_CLOSE,"JIMYCls, handle = %d")
   TRC_MSG(MIDI_JIMY_PLAY,"JIMYPlay, handle = %d")
   TRC_MSG(MIDI_JIMY_STOP,"JIMYStop, handle = %d")
   // MIDI TONE
   TRC_MSG(MIDI_JTONE_OPEN,"JTONEOpen, handle = %d")
   TRC_MSG(MIDI_JTONE_CLOSE,"JTONECls, handle = %d")
   TRC_MSG(MIDI_JTONE_PLAY,"JTONEPlay, handle = %d")
   TRC_MSG(MIDI_JTONE_STOP,"JTONEStop, handle = %d")
   // MIDI JWAV
   TRC_MSG(MIDI_JWAV_OPEN,"JWOpen, handle = %d")
   TRC_MSG(MIDI_JWAV_CLOSE,"JWCls, handle = %d")
   TRC_MSG(MIDI_JWAV_PLAY,"JWPlay, handle = %d")
   TRC_MSG(MIDI_JWAV_STOP,"JWStop, handle = %d")
   TRC_MSG(MIDI_JWAV_GETCOMMAND,"JWSFlag handle = %d, stop type =  %d")
   TRC_MSG(MIDI_JWAV_GETSTOPCMD,"Get Command JWStop, handle = %d")
   TRC_MSG(MIDI_JWAV_GETENDCMD,"Get JWEnd, handle = %d")
   TRC_MSG(MIDI_JWAV_GETREPEATCMD,"Get JWRep, handle = %d")
   TRC_MSG(MIDI_JWAV_ENDHDL,"JWEHnd, handle =  %d")
#endif

   //DAF
   TRC_MSG(DAF_L1AUDIO_STOP_TIME_UP_STATE, "DAF_L1AUDIO_STOP_TIME_UP_STATE")
   TRC_MSG(DAF_L1AUDIO_IDLE_STATE, "DAF_L1AUDIO_IDLE_STATE")
   TRC_MSG(DAF_L1AUDIO_END_STATE, "DAF_L1AUDIO_END_STATE")
   TRC_MSG(DAF_L1AUDIO_FRAME_LENGTH_TBL0, "DAF_L1AUDIO_FRAME_LENGTH_TBL 01~15:%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d")
   TRC_MSG(DAF_L1AUDIO_FRAME_LENGTH_TBL1, "DAF_L1AUDIO_FRAME_LENGTH_TBL 16~30:%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d")
   TRC_MSG(DAF_L1AUDIO_FRAME_LENGTH_TBL2, "DAF_L1AUDIO_FRAME_LENGTH_TBL 31~15:%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d")
   TRC_MSG(DAF_L1AUDIO_FIRSTWORD_POSITION, "DAF_L1AUDIO_FIRSTWORD_POSITION : %d")

   //AWBPLUS
   TRC_MSG(AWBPLUS_L1AUDIO_STOP_TIME_UP_STATE, "AWBPLUS_L1AUDIO_STOP_TIME_UP_STATE")
   TRC_MSG(AWBPLUS_L1AUDIO_IDLE_STATE, "AWBPLUS_L1AUDIO_IDLE_STATE")
   TRC_MSG(AWBPLUS_L1AUDIO_END_STATE, "AWBPLUS_L1AUDIO_END_STATE")

   //AAC
   TRC_MSG(AAC_L1AUDIO_IDLE_STATE, "AAC_L1AUDIO_IDLE_STATE")
   TRC_MSG(AAC_L1AUDIO_END_STATE, "AAC_L1AUDIO_END_STATE")
   TRC_MSG(AAC_L1AUDIO_STOP_TIME_UP_STATE, "AAC_L1AUDIO_STOP_TIME_UP_STATE")
   TRC_MSG(AAC_L1AUDIO_ERROR_REPORT, "AAC_Error ,frame_num= %d, err_code= %d, err_count= %d")

   //COOK
   TRC_MSG(COOK_L1AUDIO_IDLE_STATE, "COOK_L1AUDIO_IDLE_STATE")
   TRC_MSG(COOK_L1AUDIO_END_STATE, "COOK_L1AUDIO_END_STATE")
   TRC_MSG(COOK_L1AUDIO_STOP_TIME_UP_STATE, "COOK_L1AUDIO_STOP_TIME_UP_STATE")

   //WMA
   TRC_MSG(WMA_L1AUDIO_IDLE_STATE, "WMA_L1AUDIO_IDLE_STATE")
   TRC_MSG(WMA_L1AUDIO_END_STATE, "WMA_L1AUDIO_END_STATE")
   TRC_MSG(WMA_L1AUDIO_STOP_TIME_UP_STATE, "WMA_L1AUDIO_STOP_TIME_UP_STATE")

   //WAV
   TRC_MSG(WAV_L1AUDIO_IDLE_STATE, "WAV_L1AUDIO_IDLE_STATE")
   TRC_MSG(WAV_L1AUDIO_END_STATE, "WAV_L1AUDIO_END_STATE")
   TRC_MSG(WAV_L1AUDIO_INIT_STATE, "WAV_L1AUDIO_INIT_STATE")
   TRC_MSG(WAV_L1AUDIO_TIME_UP_STATE, "WAV_L1AUDIO_TIME_UP_STATE")
   TRC_MSG(WAV_L1AUDIO_BUF_UF, "WAV_L1AUDIO_BUF_UF")
   TRC_MSG(WAV_L1AUDIO_FREQ_CHANNEL, "WAV_L1AUDIO_FREQ_CHANNEL: WAV: Freq %d, Channel %d")
   TRC_MSG(WAV_L1AUDIO_PCMSINKHISR,  "WAV_PCMSINKHISR, D2M_count= %d!" )

   //tone_loopback_Rec
   TRC_MSG(L1AUDIO_TONE_LOOPBACK_REC_CALLBACK_MODE, "TONE_LOOPBACK_REC: callback Mode=%d")
   TRC_MSG(L1AUDIO_TONE_LOOPBACK_REC_MODE, "TONE_LOOPBACK_REC: Mode=%d")

   //spt
   TRC_MSG(L1AUDIO_SPT_SPT_RESET, "SPT reset,SR=%d,St=%d")
   TRC_MSG(L1AUDIO_SPT_SPT_TASK, "SPT TASK")
   TRC_MSG(L1AUDIO_SPT_D_F_T, "SPT D%d F%d T%d")
   TRC_MSG(L1AUDIO_SPT_SPT_OPEN, "SPT OPEN")

   //WAV DRA
   TRC_MSG(L1AUDIO_WAV_DRA_NO_SYNC, "WAV_DRA No Sync %d, Offset %d")
   TRC_MSG(L1AUDIO_WAV_DRA_ERROR, "WAV_DRA Error %d, Offset %d")

   //KT_detect
   TRC_MSG(L1AUDIO_KT_DETECT_START, "KT_DETECT_ktDetectStarted")
   TRC_MSG(L1AUDIO_KT_DETECT_STOP, "KT_DETECT_ktDetectStoped")
   TRC_MSG(L1AUDIO_KT_DETECT_DUMP, "KT_DETECT_prepare to dump pcm file")
   TRC_MSG(L1AUDIO_KT_DETECT_FINISH, "KT_DETECT_finish dump pcm file")

   //I2S
   TRC_MSG(L1AUDIO_I2S_ENABLE, "[I2S]enable, I2S mode %d enable, sr = %d")
   TRC_MSG(L1AUDIO_I2S_DISABLE, "[I2S]disable")
   TRC_MSG(L1AUDIO_I2S_REC_INIT, "[I2S]init, TCM ptr= %d, TCM size for i2srec= %d")
   TRC_MSG(L1AUDIO_I2S_REC_ACTIVATE, "[I2S]activate, use TCM: %d, encMemSIze: %d")
   TRC_MSG(L1AUDIO_I2S_REC_DEACTIVATE, "[I2S]deactivate")

   TRC_MSG(L1AUDIO_I2S_REC_ON, "[I2S]record on")
   TRC_MSG(L1AUDIO_I2S_REC_OFF, "[I2S]record off")
   TRC_MSG(L1AUDIO_I2S_REC_REC_OF, "[I2S]medbuf OF, freespace(word):%d, required(word):")
   TRC_MSG(L1AUDIO_I2S_REC_PROCESS, "[I2S]process, APM_inputCnt(word): %d, encBuf_space(word): %d")
   TRC_MSG(L1AUDIO_I2S_REC_ENCODED, "[I2S]encoder out, encData_consumed(word): %d, outputByte: %d, flush: %d")

   TRC_MSG(L1AUDIO_I2S_INTERRUPT   , "[I2S]I2S_DspIntHISR 0x1414: uControl: 0x%x, uEnableCheck: %d, uFinishCheck: %d, uMagicNo: 0x%x")
   TRC_MSG(L1AUDIO_I2S_CHECK_VALID , "[I2S]I2SIN_CheckDataValid, is_FM: %d,is_ON: %d, fValid: %d, uWaitTick: %d")
   TRC_MSG(L1AUDIO_I2S_MUTE_DSP    , "[I2S]I2SIN_MuteDSP, fMute: %d")
   TRC_MSG(L1AUDIO_I2S_TURNON_SPK  , "[I2S]I2SIN_TurnOnSpeaker")
   TRC_MSG(L1AUDIO_I2S_TURNOF_SPK  , "[I2S]I2SIN_TurnOffSpeaker")
   TRC_MSG(L1AUDIO_I2S_MUTE_SPK    , "[I2S]I2SIN_MuteSpeaker, mute: %d")
   TRC_MSG(L1AUDIO_I2S_SET_VOLUME  , "[I2S]I2SIN_SetOutputVolume, volume1: %d, kal_int8 digital_gain_index: %d")
   TRC_MSG(L1AUDIO_I2S_SET_DEVICE  , "[I2S]I2SIN_SetOutputDevice, device: %d")

   //I2S MP3 ENC
   TRC_MSG(L1AUDIO_MP3_ENC_MALLOC, "[I2S][MP3enc]emz_malloc, ptr: %x, size: %d")
   TRC_MSG(L1AUDIO_MP3_ENC_CALLOC, "[I2S][MP3enc]emz_calloc, ptr: %x, size: %d, num: %d")
   TRC_MSG(L1AUDIO_MP3_ENC_FREE, "[I2S][MP3enc]emz_free, ptr: %x")
   TRC_MSG(L1AUDIO_MP3_ENC_REALLOC, "[I2S][MP3enc]emz_realloc, old ptr: %x, new size: %d, new ptr: %x")
   TRC_MSG(L1AUDIO_MP3_ENC_MEMCPY, "[I2S][MP3enc]emz_memcpy, src ptr: %x, dst ptr: %x, len: %d")
   TRC_MSG(L1AUDIO_MP3_ENC_MEMSET, "[I2S][MP3enc]emz_memset, dst ptr: %x, len: %d, value: %d")
   TRC_MSG(L1AUDIO_MP3_ENC_ENCODED, "[I2S][MP3enc]Encode Out, inbuf: %x, outbuf %x, bs_len %d, flush %d, status %d")

   //BT_PCMLOOPBACK
   TRC_MSG(L1AUDIO_BT_PCMLOOPBACK_AFTER_SET, "BT_PCMLOOPBACK after set,DP_VOL_OUT_PCM= %d")
   TRC_MSG(L1AUDIO_BT_PCMLOOPBACK_MAGDB, "BT_PCMLOOPBACK magDB = %d")
   TRC_MSG(L1AUDIO_BT_PCMLOOPBACK_DUMP_PREP, "BT_PCMLOOPBACK prepare to dump pcm file")
   TRC_MSG(L1AUDIO_BT_PCMLOOPBACK_DUMP_DONE, "BT_PCMLOOPBACK finish dump pcm file BTLBdebug.pcm")
   TRC_MSG(L1AUDIO_BT_PCMLOOPBACK_DUMP_FAIL, "BT_PCMLOOPBACK unable to dump file")

   //tonedect
   TRC_MSG(L1AUDIO_TONEDECT, "TONEDECT s1(%d)=%2d, s2(%d)=%2d, n(%d)=%2d, (s-n)=%2d")

   //vr_si
   TRC_MSG(L1AUDIO_VR_SI_DCMUNLOAD, "[VR_SI] DcmUnLoad")
   TRC_MSG(L1AUDIO_VR_SI_ABORT, "[VR_SI] VRSI Abort")
   TRC_MSG(L1AUDIO_VR_SI_DCMLOAD_TRN, "[VR_SI] DcmLoad Trn")
   TRC_MSG(L1AUDIO_VR_SI_DCMLOAD_RCG, "[VR_SI] DcmLoad Rcg")
   TRC_MSG(L1AUDIO_VR_SI_DCMLOAD_DIGIADPT, "[VR_SI] DcmLoad digiAdpt")

   //BT_loopback
   TRC_MSG(L1AUDIO_BT_LOOPBACK_HISR, "[BT_LOOPBACK] Consume all data in spk buf R1")
   TRC_MSG(L1AUDIO_BT_LOOPBACK_SRC_FAIL, "[BT_LOOPBACK] autospeak: source file can't open")
   TRC_MSG(L1AUDIO_BT_LOOPBACK_WRITE_LEN, "[BT_LOOPBACK] write_len      K1 =%d")
   TRC_MSG(L1AUDIO_BT_LOOPBACK_SPK_NUM, "[BT_LOOPBACK] num_spk_sample K2 =%d")
   TRC_MSG(L1AUDIO_BT_LOOPBACK_DIFF, "[BT_LOOPBACK] diff_spk_and_rec_Spk_callcack K3 =%d")
   TRC_MSG(L1AUDIO_BT_LOOPBACK_READ_LEN, "[BT_LOOPBACK] read_len       T1 =%d")
   TRC_MSG(L1AUDIO_BT_LOOPBACK_REC_NUM, "[BT_LOOPBACK] num_rec_sample T2 =%d")
   TRC_MSG(L1AUDIO_BT_LOOPBACK_DIFF2, "[BT_LOOPBACK] diff_spk_and_rec_Rec_callcack T3 =%d")
   TRC_MSG(L1AUDIO_BT_LOOPBACK_STOP, "[BT_LOOPBACK] BT_Loopback_Stop P1")
   TRC_MSG(L1AUDIO_BT_LOOPBACK_PCMRB_FREESPACE, "[BT_LOOPBACK] auto_speak PCMRB_GetFreeSpace A1 =%d")
   TRC_MSG(L1AUDIO_BT_LOOPBACK_PCMRB_DATACOUNT, "[BT_LOOPBACK] auto_speak PCMRB_GetDataCount A2 =%d")
   
   //AVB
   TRC_MSG(L1AUDIO_AVB_CLOSE, "AVB_Close: uState: %d" ) 
   TRC_MSG(L1AUDIO_AVB_FLUSH, "AVB_Flush: uState: %d, uHisrRunning: %d, waiting tick: %d" ) 
   TRC_MSG(L1AUDIO_AVB_OPEN, "AVB_Open: uState: %d" ) 
   TRC_MSG(L1AUDIO_AVB_PROC, "AVB_Process: uState: %d AVB.uSegment_W: %d AVB.uSegment_R: %d" ) 
   TRC_MSG(L1AUDIO_AVB_HISR, "AVB_HISR: uState: %d AVB.uSegment_W: %d AVB.uSegment_R: %d" ) 
   TRC_MSG(L1AUDIO_AVB_WRITE_DATA,"AVB_WriteData, SrcDataLen(Word): %d, CopyedDataLen(Word): %d, DIFF: %d, Mono2Stereo: %d, ")
   TRC_MSG(L1AUDIO_AVB_WRITE_ZERO,"AVB_WriteSilence, SrcDataLen(Word): %d, CopyedDataLen(Word): %d, DIFF: %d")
   
   //avsync mp4
   TRC_MSG(L1AUDIO_AVSYNC_MP4_AUDIO_GETPLAYTIME,       "[AVSYNC_MP4] Audio_GetPlayTime,IntptCnt: %d, SeekPointTime: %d, CurrPlayTime(ms): %d")
   TRC_MSG(L1AUDIO_AVSYNC_MP4_VIDEO_GETPLAYTIME,       "[AVSYNC_MP4] Video_GetPlayTime,PrevIntptCnt: %d, CurrIntptCnt: %d, PrePlayTime: %d, CurrPlayTime(ms): %d")
   TRC_MSG(L1AUDIO_AVSYNC_MP4_SETPLAYBACKTIMERBASE, "[AVSYNC_MP4] MP4_SetPlaybackTimerBase,Prev PlayTime: %d, New PlayTime: %d")

   //MCU DECODE PLAYBACK
   TRC_MSG(L1AUDIO_PLAYBACK_PCMBF_UF, "[L1AU][PLY][HISR]PCM BUFFER Under Flow in HISR%d" )
   TRC_MSG(L1AUDIO_PLAYBACK_TIMEUP, "[L1AU][PLY][HISR]Time Up%d" )
   TRC_MSG(L1AUDIO_PLAYBACK_DSPRB_INIT, "[L1AU][PLY][HISR]DSP RB Init%d" )
   TRC_MSG(L1AUDIO_PLAYBACK_MEDIA_END, "[L1AU][PLY][HISR]Media End%d" )
   TRC_MSG(L1AUDIO_PLAYBACK_DSP_IDLE, "[L1AU][PLY][HISR]DSP IDLE%d" )
   TRC_MSG(L1AUDIO_PLAYBACK_GETDATA_FROM_FILE, "[L1AU][PLY][PROS]Put %d bytes to bsbuf" )

   //COOK PLAYBACK
   TRC_MSG(L1AUDIO_COOK_PARAM_1, "[COOK]COOK OPEN, nSamplesPut: %d, nChannels: %d, nRegions: %d" )
   TRC_MSG(L1AUDIO_COOK_PARAM_2, "[COOK]nFrameBits: %d, sampRate: %d, cplStart: %d, cplQbits: %d" )
   TRC_MSG(L1AUDIO_COOK_DECODE, "[COOK]DECODE TASK, output length: %d")
   TRC_MSG(L1AUDIO_COOK_DECODE_FAIL, "[COOK]DECODE FAIL")

   //WAVDEC PLAYBACK
   TRC_MSG(L1AUDIO_WAVDEC_PARAM_1, "[WAVDEC][Header Info1] format: %d, data offset: %d, SR: %d, Channelnum %d" )
   TRC_MSG(L1AUDIO_WAVDEC_PARAM_2, "[WAVDEC][Header Info1] data chunk length: %d, bite rate: %d, total dur: %d" )
   TRC_MSG(L1AUDIO_WAVDEC_DECODE, "[WAVDEC]DECODE TASK, output length: %d" )
   TRC_MSG(L1AUDIO_WAVDEC_DEC_FAIL, "[WAVDEC]DECODE FAIL" )


   //AUDIO PLAYBACK CILENT
   TRC_MSG(L1AUDIO_PLAYBACK_OPEN         , "[AUD_CIL][OPEN ] format: %d, handle: 0x%X, callback: 0x%X" )
   TRC_MSG(L1AUDIO_PLAYBACK_PLAY         , "[AUD_CIL][PLAY ] format: %d, handle: 0x%X" )
   TRC_MSG(L1AUDIO_PLAYBACK_STOP         , "[AUD_CIL][STOP ] format: %d, handle: 0x%X" )
   TRC_MSG(L1AUDIO_PLAYBACK_CLOSE        , "[AUD_CIL][CLOSE] format: %d, handle: 0x%X" )
   TRC_MSG(L1AUDIO_PLAYBACK_PROSS        , "[AUD_CIL][PROSS] format: %d, handle: 0x%X, event: %d" )
   TRC_MSG(L1AUDIO_PLAYBACK_PLAY_SUCCESS , "[AUD_CIL][PLAY ] format: %d, handle: 0x%X, PLAY SUCCESS" )

   //AUDIO PLAYBACK COMPONENT
   TRC_MSG(L1AUDIO_COM_INIT   , "[AUD_COMP][INIT ] type: %d, AudID: %d, com_status: %d" )
   TRC_MSG(L1AUDIO_COM_START  , "[AUD_COMP][START] type: %d, AudID: %d, com_status: %d" )
   TRC_MSG(L1AUDIO_COM_STOP   , "[AUD_COMP][STOP ] type: %d, AudID: %d, com_status: %d" )
   TRC_MSG(L1AUDIO_COM_DEINIT , "[AUD_COMP][DINIT] type: %d, AudID: %d, com_status: %d" )
   TRC_MSG(L1AUDIO_COM_PROSS  , "[AUD_COMP][PROSS] type: %d, AudID: %d, com_status: %d" )

   //Compensation Filter
   TRC_MSG(L1AUDIO_ACF_SELECT, "[ACF]Media_SelectAudioCompensation: %d" )
   TRC_MSG(L1AUDIO_ACF_ACTIVATE, "[ACF]Audio_Compensation_Activate, mode: %d" )

   //AUDIO PLAYBACK
   TRC_MSG(L1AUDIO_PLY_INFO, "[L1AU][PLY] type=%d, idx=%d, info1=%d, info2=%d, info3=%d")
   TRC_MSG(L1AUDIO_PLY_SR_CH, "[L1AU][PLY] type=%d, Sample rate=%d, channel num=%d")
   TRC_MSG(L1AUDIO_PLY_SEEKABLE, "[L1AU][PLY] type=%d, seekable=%d")
   TRC_MSG(L1AUDIO_PLY_DECODE_FAIL, "[L1AU][PLY] type=%d, DECODE FAIL")
   TRC_MSG(L1AUDIO_PLY_DECODE_EOF, "[L1AU][PLY] type=%d, DECODE EOF")
   TRC_MSG(L1AUDIO_PLY_DECODE_OUT, "[L1AU][PLY] type=%d, DECODE task output pcm: %d bytes")
   TRC_MSG(L1AUDIO_PLY_DECODE_CHECKSUM, "[L1AU][PLY] type=%d, CHECKSUM: 0x%X")
   TRC_MSG(L1AUDIO_PLY_HISR, "[L1AU][PLY] type=%d, HISR: Data Length%d")
   TRC_MSG(L1AUDIO_PLY_INIT_FAIL, "[L1AU][PLY] type=%d, INIT Fail: %d")


   // Data comsumption
   TRC_MSG(L1AUDIO_SINK_INFO, "[AUD][Sink] AudID: %d, Consume %d bytes")
   TRC_MSG(L1AUDIO_SOURCE_INFO, "[AUD][Source] Get %d bytes")


   //Audio General info
   TRC_MSG(L1AUDIO_GENERAL_INFO, "[AUD][%MAudio_Trace_Index] %d, %d, %d, %d, %d, %d")

   //Audio MD2G Power control
   TRC_MSG(L1AUDIO_MD2G_PWR_CTRL,          "[AUDMD2G][POWER] CTRL, audioid= %d, flag = %d")
   TRC_MSG(L1AUDIO_MD2G_PWR_CTRL_DONE,     "[AUDMD2G][POWER] CTRL DONE, audioid= %d, flag = %d")

   TRC_MSG(L1AUDIO_SETFLAG_A,              "[AUDMD2G] L1Audio_SetFlag , audioid= %d, runningState = %d")
   TRC_MSG(L1AUDIO_CLEARFLAG_A,            "[AUDMD2G] L1Audio_ClearFlag, audioid= %d, runningState = %d")
   TRC_MSG(L1AUDIO_SETFLAG_MD2G_A,         "[AUDMD2G] MD2G_L1Audio_SetFlag , audioid= %d, runningState = %d")
   TRC_MSG(L1AUDIO_CLEARFLAG_MD2G_A,       "[AUDMD2G] MD2G_L1Audio_ClearFlag, audioid= %d, runningState = %d")

   //AUDLP PLAYBACK
   TRC_MSG(L1AUDLP_AUDMA_LOCK_START,       "[AUDLP][AUDMA_LOCK]start, task_index: %d, register_id: %d," )
   TRC_MSG(L1AUDLP_AUDMA_LOCK_END,         "[AUDLP][AUDMA_LOCK]end  , task_index: %d, register_id: %d, lock_count: %d, id_count: %d," )
   TRC_MSG(L1AUDLP_AUDMA_UNLOCK_START,     "[AUDLP][AUDMA_UNLOCK]start, task_index: %d, register_id: %d," )
   TRC_MSG(L1AUDLP_AUDMA_UNLOCK_END,       "[AUDLP][AUDMA_UNLOCK]end  , task_index: %d, register_id: %d, lock_count: %d, id_count: %d," )

   TRC_MSG(L1AUDLP_AUDMA_LOCK_SYSTEMINIT,  "[AUDLP][AUDMA_LOCK]SystemInit, task_index: %d, register_id: %d," )
   TRC_MSG(L1AUDLP_AUDMA_UNLOCK_SYSTEMINIT,"[AUDLP][AUDMA_UNLOCK]SystemInit, task_index: %d, register_id: %d," )

   TRC_MSG(L1AUDLP_TIMEREXPIRE,            "[AUDLP][TIMER] Expire !" )
   TRC_MSG(L1AUDLP_LPINIT_START,           "[AUDLP][LPINIT] Start !, DSPDM_Rp: %d, DSPWp: %d" )
   TRC_MSG(L1AUDLP_LPINIT_CHECK,           "[AUDLP][LPINIT] Check !, audma_lock_count: %d, HWUsedFlag: %d" )
   TRC_MSG(L1AUDLP_LPINIT_M2D,             "[AUDLP][LPINIT] M2D !, DSPDM_Rp: %d, DSPWp: %d, PST_Rp: %d, PST_Wp: %d, pst_index: %d, DataFillInDSPBuff: %d" )
   TRC_MSG(L1AUDLP_STARTTIMER,             "[AUDLP][TIMER] Start !" )

   TRC_MSG(L1AUDLP_WriteDataByIDMA_START,  "[AUDLP][IDMA] Start!,flag: %d, lenInWordHigh: %d, lenInWordLow: %d, DSP_W: %d, DSP_R: %d, DSP_FreeLen: %d" )
   TRC_MSG(L1AUDLP_WriteDataByIDMA_END,    "[AUDLP][IDMA] End!  , DSP_FreeLenLow: %d, count: %d" )
   TRC_MSG(L1AUDLP_HISR_DAF,               "[AUDLP][HISR] MP3LP in Hisr!, state: %d, bProcessPST: %d" )
   TRC_MSG(L1AUDLP_HISR_ERR_REPORT,        "[AUDLP][HISR] MP3LP_ERR_REPORT!, state: %d, error_report: %d, DataFillInDSPBuff: %d, DSPUsedSectors: %d, DSPDM_Rp: %d, DSPDM_Wp: %d" )
   TRC_MSG(L1AUDLP_GETCURTIME_FROM_FRMCNT, "[AUDLP][CURTIME] Get Current Time!, PrevFrameCount: %d, CurrFrameCount: %d, CurrTime: %d" )

   TRC_MSG(L1AUDLP_STATE_ASKAUDMASTOP,     "[AUDLP][AUDMASTOP] state to AuDMA_STOP!%d" )
   TRC_MSG(L1AUDLP_STATE_PREFETCH,         "[AUDLP][AUDMASTOP] state to PREFETCH!%d" )

   TRC_MSG(L1AUDIO_RESAMPLER_OV1, "[L1AU][Resampler] RES RB OVFlow")
   TRC_MSG(L1AUDIO_RESAMPLER_OV2, "[L1AU][Resampler] RES buf OVFlow2")
   TRC_MSG(L1AUDIO_RESAMPLER_UDF, "[L1AU][Resampler] RES BUF UDFLOW")
   TRC_MSG(L1AUDIO_RESAMPLER_PUTBUF1, "[L1AU][Resampler] RES putbuf seg1=%d")
   TRC_MSG(L1AUDIO_RESAMPLER_PUTBUF2, "[L1AU][Resampler] RES putbuf seg2=%d")
   TRC_MSG(L1AUDIO_RESAMPLER_RESINTCM, "[L1AU][Resampler] ResInTcm;ResSize=%d,TcmLen=%d")
   TRC_MSG(L1AUDIO_RESAMPLER_RESHDLTCM, "[L1AU][Resampler] ResHdlInTcm;ResSize=%d,TcmLen=%d")
   TRC_MSG(L1AUDIO_RESAMPLER_RESINEXT, "[L1AU][Resampler] ResInExt")

   TRC_MSG(L1AUDLP_V2_INIT,                     "[AUDLPV2][INIT] Initial AUDLP mode variables!" )
   TRC_MSG(L1AUDLP_V2_ENABLE_DISABLE,           "[AUDLPV2][INIT] set audio low power mode, audlp_flag= %d, dspclock_switch= %d!" )
   TRC_MSG(L1AUDLP_V2_ENABLE_BYPASS,            "[AUDLPV2][INIT] Engineer mode bypass AUDLP mode!" )
   TRC_MSG(L1AUDLP_V2_SET_SWEVENT_CLK,          "[AUDLPV2][INIT] set sw event clock, flag= %d!" )
   TRC_MSG(L1AUDLP_V2_ENABLE_SWEVENT,           "[AUDLPV2][INIT] set sw event enable, flag= %d!" )
   TRC_MSG(L1AUDLP_V2_26M_CLK_SWITCH,           "[AUDLPV2][SWITCH] DSP clock 26M , flag= %d, state= %d!" )
   TRC_MSG(L1AUDLP_PCMSETBUFFER,                "[AUDLPV2][INIT] set pcm play larger buffer, flag= %d!" )
   
   TRC_MSG(L1AUDLP_V2_PCMSINKHISR,              "[AUDLPV2][PCMSinkHisr] enter PCM sinkhisr, D2M_count= %d!" )
   TRC_MSG(L1AUDLP_V2_PCMSINKHISR_DATA,         "[AUDLPV2][PCMSinkHisrData] fill in data     , read_ptr= 0x%X, write_ptr= 0x%X, empty= %d, D2M_count= %d!" )
   TRC_MSG(L1AUDLP_V2_PCMSINKHISR_DATA_DONE,    "[AUDLPV2][PCMSinkHisrData] fill in data Done, read_ptr= 0x%X, write_ptr= 0x%X, filled_size= %d!" )
   TRC_MSG(ACU_FILEREAD,                        "[AUDLPV2][ACU] FileRead %d bytes!" )

   TRC_MSG(L1AUDLP_V2_TIMEREXPIRE,              "[AUDLPV2][TIMER] Expire !,dsp_r_ptr= 0x%X, dsp_w_ptr= 0x%X,dataleft= %d, D2M_count= %d, sleep_dis= %d" )
   TRC_MSG(L1AUDLP_V2_STARTTIMER,               "[AUDLPV2][TIMER] Start  !,sleep_dis= %d" )
   TRC_MSG(L1AUDLP_V2_STOPTIMER,                "[AUDLPV2][TIMER] Stop   !" )
   TRC_MSG(L1AUDLP_V2_SETDSPBUFFER_SHORT,       "[AUDLPV2][ChangePara] set DSP buffer short,fAudLP_Enable= %d, setflag= %d!" )
   TRC_MSG(L1AUDLP_V2_SET_SAMPLERATE,           "[AUDLPV2][ChangePara] set audio samplerate = %d!" )

   //VORBIS
   TRC_MSG(L1AUDIO_VBSENC_RECORD   , "[L1AU][VBS_ENC]VBSENC_RECORD, State: %d, Speech: %d" )
   TRC_MSG(L1AUDIO_VBSENC_STOP     , "[L1AU][VBS_ENC]VBSENC_STOP, State: %d" )
   TRC_MSG(L1AUDIO_VBSENC_PAUSE    , "[L1AU][VBS_ENC]VBSENC_PAUSE, State: %d" )
   TRC_MSG(L1AUDIO_VBSENC_RESUME   , "[L1AU][VBS_ENC]VBSENC_RESUME, State: %d" )
   TRC_MSG(L1AUDIO_VBSENC_FLUSH    , "[L1AU][VBS_ENC]VBSENC_FLUSH, Media_GetDataCount: %d" )
   TRC_MSG(L1AUDIO_VBSENC_DSPOFF   , "[L1AU][VBS_ENC]VBSENC_DSPOFF, SampleRate: %d" )
   TRC_MSG(L1AUDIO_VBSENC_HISR     , "[L1AU][VBS_ENC]VBSENC_HISR, State: %d" )
   TRC_MSG(L1AUDIO_VBSENC_COPY2IN  , "[L1AU][VBS_ENC]VBSENC_COPY2IN, WBLK: %d, EBLK: %d, READY: %d, INLEN: %d, CurBLK_W: %d " )
   TRC_MSG(L1AUDIO_VBSENC_COPY2OUT , "[L1AU][VBS_ENC]VBSENC_COPY2OUT, OutLen: %d, OutLenRead: %d, Segment: %d " )
   TRC_MSG(L1AUDIO_VBSENC_PROCESS  , "[L1AU][VBS_ENC]VBSENC_PROCESS, State: %d, Ready: %d, OutLen: %d " )
   TRC_MSG(L1AUDIO_VBSENC_ENCODE   , "[L1AU][VBS_ENC]VBSENC_ENCODE, Flush: %d, OutLen: %d, EncBlk: %d " )
   TRC_MSG(L1AUDIO_VBSENC_FREE     , "[L1AU][VBS_ENC]VBSENC_FREE, State: %d " )
   TRC_MSG(L1AUDIO_VBSENC_INIT     , "[L1AU][VBS_ENC]VBSENC_INIT, State " )
   TRC_MSG(L1AUDIO_VBSENC_MEMSIZE  , "[L1AU][VBS_ENC]VBSENC_MEMSIZE, rt_tab: %d, shared: %d, encoder: %d, parser: %d, input: %d, output: %d  " )
   TRC_MSG(L1AUDIO_VBSENC_ALLOC_INPCM  , "[L1AU][VBS_ENC]VBSENC_ALLOC_INPCM: %d " )
   TRC_MSG(L1AUDIO_VBSENC_ALLOC_OUTBS  , "[L1AU][VBS_ENC]VBSENC_ALLOC_OUTBS: %d " )
   TRC_MSG(L1AUDIO_VBSENC_ALLOC_WORK   , "[L1AU][VBS_ENC]VBSENC_ALLOC_WORK: %d " )
   TRC_MSG(L1AUDIO_VBSENC_ALLOC_TEMP   , "[L1AU][VBS_ENC]VBSENC_ALLOC_TEMP: %d " )
   TRC_MSG(L1AUDIO_VBSENC_I2S_RECORD   , "[L1AU][VBS_ENC]VBSENC_I2S_RECORD: State: %d, SR: %d, CH: %d " )
   TRC_MSG(L1AUDIO_VBSENC_I2S_COPY2OUT , "[L1AU][VBS_ENC]VBSENC_I2S_COPY2OUT: OutLen: %d, OutLenRead: %d, FreeSpeace: %d " )
   TRC_MSG(L1AUDIO_VBSENC_I2S_PROCESS  , "[L1AU][VBS_ENC]VBSENC_I2S_PROCESS: State: %d, inDataCnt: %d, outFreeSpace: %d, Flush : %d " )

   //MIXER
   TRC_MSG(L1AUDIO_MIXER_PCMRENDER_START   , "[L1AU][MIXER]PcmRender_Start, uState: %d, numHook: %d" )
   TRC_MSG(L1AUDIO_MIXER_PCMRENDER_STOP    , "[L1AU][MIXER]PcmRender_Stop, uState: %d, numHook: %d" )
   TRC_MSG(L1AUDIO_MIXER_REGISTER_INPUT    , "[L1AU][MIXER]RenMix_RegisterInput, uState: %d, numHook: %d" )
   TRC_MSG(L1AUDIO_MIXER_UNREGISTER_INPUT  , "[L1AU][MIXER]RenMix_UnRegisterInput, uState: %d, numHook: %d" )
   TRC_MSG(L1AUDIO_MIXER_ACTIVATE1         , "[L1AU][MIXER]audioMixer_Activate1, uState: %d, numHook: %d" )
   TRC_MSG(L1AUDIO_MIXER_DEACTIVATE        , "[L1AU][MIXER]audioMixer_Deactivate, uState: %d, numHook: %d" )
   TRC_MSG(L1AUDIO_MIXER_MIXEROUT_STOP     , "[L1AU][MIXER]MixerOut_Stop, uState: %d, numHook: %d" )

   //Loudness
   TRC_MSG(L1AUDIO_LOUDNESS_RINETONE_ENABLE   ,"[L1AU][LOUDNESS]Ringtone_Mode_Enable")
   TRC_MSG(L1AUDIO_LOUDNESS_RINETONE_DISABLE  ,"[L1AU][LOUDNESS]Ringtone_Mode_Disable")
   TRC_MSG(L1AUDIO_LOUDNESS_REGISTRY          ,"[L1AU][LOUDNESS]Registry, iTurnOnLoudness: %d")
   TRC_MSG(L1AUDIO_LOUDNESS_INIT_PARAM        ,"[L1AU][LOUDNESS]Init Param, mode: %d, fBloud_HSF_AVAILABLE: %d")
   TRC_MSG(L1AUDIO_LOUDNESS_FILTER            ,"[L1AU][LOUDNESS]Filter, mode: %d, HPF[0][0]= 0x%X, BPF[0][0][0]= 0x%X")

   //ddload
   TRC_MSG(L1AUDIO_DDLOAD_STATUS_FAIL, "[DDLoad]DSP Status Not Clear")
   TRC_MSG(L1AUDIO_DDLOAD_STATUS_SUCCESS, "[DDLoad]DDLoad success")

   //eCall
   TRC_MSG(ECALL_IVS_DRV_CATCH_EVENT, "[eCall]IVS Driver Catch Event %d")
   TRC_MSG(ECALL_IVS_DRV_HLACK, "[eCall]IVS Driver HLACK. Expect %d, Received %d")
   TRC_MSG(ECALL_PSAP_DRV_CATCH_EVENT, "[eCall]PSAP Driver Catch Event %d")
   TRC_MSG(ECALL_PSAP_DRV_RECEIVE_MSD, "[eCall]PSAP Driver Received MSD")
   TRC_MSG(ECALL_PSAP_DRV_MSD_DATA, "[eCall]PSAP MSD (index %3d ~ %3d) %2X %2X %2X %2X %2X %2X %2X %2X %2X %2X")
   TRC_MSG(ECALL_IVS_MODEM_SENDSTART, "[eCall]IVS SendStart received from control")
   TRC_MSG(ECALL_IVS_MODEM_SENDSTART_IGNORE, "[eCall]IVS SendStart received from control, ignored")
   TRC_MSG(ECALL_IVS_MODEM_RX_RESET, "[eCall]IVS reset receiver")
   TRC_MSG(ECALL_IVS_MODEM_TX_RESET, "[eCall]IVS reset transmitter")
   TRC_MSG(ECALL_IVS_MODEM_TX_RESET_MSD_PROVIDED, "[eCall]IVS reset transmitter (MSD provided)")
   TRC_MSG(ECALL_IVS_MODEM_SENDSTART_DUR_MSD_IGNORE, "[eCall]IVS SendStart during MSD transmission, ignored.")
   TRC_MSG(ECALL_IVS_MODEM_SENDING_SEND, "[eCall]IVS sending  SEND")
   TRC_MSG(ECALL_IVS_MODEM_FULL_RESET, "[eCall]IVS full reset (no sync detected)")
   TRC_MSG(ECALL_IVS_MODEM_IGNORING_HLACK, "[eCall]IVS ignoring additional HLACK (data: 0x0%X, metric: %3d)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_HLACK_FINISHED, "[eCall]IVS received HLACK (data: 0x0%X, metric: %3d), finished.")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_HLACK_WAITING, "[eCall]IVS received HLACK (data: 0x0%X, metric: %3d), waiting...")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_START_LOW_RELIABILITY, "[eCall]IVS received START !> ignoring message (reliability too low)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_START_TOO_OFTEN, "[eCall]IVS received START (metric: %3d) too often starting over...")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_START_STARTING, "[eCall]IVS received START (metric: %3d), starting...")
   TRC_MSG(ECALL_IVS_MODEM_FAST_MODULATOR, "[eCall]IVS fast modulator chosen (NACK count: %d)")
   TRC_MSG(ECALL_IVS_MODEM_ROBUST_MODULATOR, "[eCall]IVS robust modulator chosen (NACK count: %d)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_START, "[eCall]IVS received START (metric: %3d)")
   TRC_MSG(ECALL_IVS_MODEM_START_AFTER_ACK, "[eCall]IVS START ... !> assuming previous ACK was wrong")
   TRC_MSG(ECALL_IVS_MODEM_START_AFTER_HLACK, "[eCall]IVS START ... !> assuming previous HLACK was wrong")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_NACK_EXCEPTING_START, "[eCall]IVS received NACK  !> ignoring message (expecting START)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_NACK_LOW_RELIABILITY, "[eCall]IVS received NACK  !> ignoring message (reliability too low)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_NACK_ASSUME_IDLE, "[eCall]IVS received NACK  !> ignoring message (assume IDLE)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_NACK_FIRST_TIME, "[eCall]IVS received NACK  (metric: %3d), first time")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_NACK, "[eCall]IVS received NACK  (metric: %3d)")
   TRC_MSG(ECALL_IVS_MODEM_NACK_AFTER_ACK, "[eCall]IVS NACK ... !> assuming previous ACK was wrong")
   TRC_MSG(ECALL_IVS_MODEM_NACK_AFTER_HLACK, "[eCall]IVS NACK ... !> assuming previous HLACK was wrong")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_ACK_EXPECTING_START, "[eCall]IVS received ACK   !> ignoring message (expecting START)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_ACK_RECORDED, "[eCall]IVS received ACK   !> ignoring message (already recorded)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_ACK_LOW_RELIABILITY, "[eCall]IVS received ACK   !> ignoring message (reliability too low)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_ACK_ASSUME_IDLE, "[eCall]IVS received ACK   !> ignoring message (assume IDLE)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_ACK, "[eCall]IVS received ACK   (metric: %3d), ACK recorded, wait for HLACK")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_ACK_WAITING, "[eCall]IVS received ACK   (metric: %3d), waiting...")
   TRC_MSG(ECALL_IVS_MODEM_ACK_AFTER_HLACK, "[eCall]IVS ACK ... !> assuming previous HLACK was wrong")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_IDLE_EXPECTING_START, "[eCall]IVS received IDLE  !> ignoring message (expecting START)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_IDLE_IGNORE, "[eCall]IVS received IDLE  !> ignoring message")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_IDLE_REMAINING, "[eCall]IVS remaining in IDLE mode")
   TRC_MSG(ECALL_SYNC_DETECTED, "[eCall]sync detected; delay: %+4d; npeaks: %+4d (inverted sync)")
   TRC_MSG(ECALL_SYNC_DETECTED_REGULAR, "[eCall]sync detected; delay: %+4d; npeaks: %+4d (regular sync)")
   TRC_MSG(ECALL_SYNC_MAX_RANGE, "[eCall]maximum sync checking range is [-480...480] samples")
   TRC_MSG(ECALL_SYNC_DETECTE_SLIP, "[eCall]sync check detects sample slip! [%+1d sample(s)]")
   TRC_MSG(ECALL_SYNC_PSAP_MAX_RANGE, "[eCall][PSAP] maximum sync tracking range is [-240...240] samples")
   TRC_MSG(ECALL_SYNC_PSAP_SLIP, "[eCall][PSAP] sync tracking detects sample slip! [%+1d sample(s)]")
   TRC_MSG(ECALL_CONTROL_PORT_UNDEFINE, "[eCall]control callback: port owner undefined.")
   TRC_MSG(ECALL_CONTROL_SYNC_LOCKED, "[eCall]sync locked, starting control message detection")
   TRC_MSG(ECALL_CONTROL_CODEC_INVERSION, "[eCall]codec inversion detected!")
   TRC_MSG(ECALL_CONTROL_MESSAGE_IGNORE, "[eCall]message ignored (bad sync check)")
   TRC_MSG(ECALL_PSAP_MODEM_RECEIVED_SEND_CONTROL, "[eCall][PSAP] SendStart received from control")
   TRC_MSG(ECALL_PSAP_MODEM_RECEIVED_SEND_OVER, "[eCall][PSAP] SendStart received, starting over...")
   TRC_MSG(ECALL_PSAP_MODEM_RECEIVED_SEND_IGNORE, "[eCall][PSAP] SendStart received from control, ignored.")
   TRC_MSG(ECALL_PSAP_MODEM_RECEIVED_HLACK, "[eCall][PSAP] HLACK data received from control")
   TRC_MSG(ECALL_PSAP_MODEM_RECEIVED_HLACK_IGNORE, "[eCall][PSAP] HLACK data received from control, ignored.")
   TRC_MSG(ECALL_PSAP_MODEM_RESET_RECEIVER, "[eCall][PSAP] reset receiver")
   TRC_MSG(ECALL_PSAP_MODEM_RESET_TRANSMITTER, "[eCall][PSAP] reset transmitter")
   TRC_MSG(ECALL_PSAP_MODEM_RECEIVED_SEND, "[eCall][PSAP] received SEND (metric: %3d), initiating START trigger")
   TRC_MSG(ECALL_PSAP_MODEM_INVERSION_DETECT, "[eCall][PSAP] codec inversion detected!")
   TRC_MSG(ECALL_PSAP_MODEM_INVERSION_SYNC, "[eCall][PSAP] codec inversion detected (sync observer)!")
   TRC_MSG(ECALL_PSAP_MODEM_RESTART, "[eCall][PSAP] restart due to tracking failures!")
   TRC_MSG(ECALL_PSAP_MODEM_CRC_FAIL, "[eCall][PSAP] CRC failed; rv = %d")
   TRC_MSG(ECALL_PSAP_MODEM_RECEIVED_MSD, "[eCall][PSAP] MSD successfully received; redundancy versions: %d")
   TRC_MSG(ECALL_PSAP_MODEM_SENDING_HLACK, "[eCall][PSAP] sending HLACK; data: 0x0%X")
   TRC_MSG(ECALL_PSAP_MODEM_SENDING_START, "[eCall][PSAP] sending START")
   TRC_MSG(ECALL_PSAP_MODEM_SENDING_NACK, "[eCall][PSAP] sending NACK")
   TRC_MSG(ECALL_PSAP_MODEM_SENDING_ACK, "[eCall][PSAP] sending ACK")
   TRC_MSG(ECALL_PSAP_MODEM_SENDING_ACK_PEND, "[eCall][PSAP] sending ACK (HLACK pending)")
   TRC_MSG(ECALL_PSAP_MODEM_FAST_REMAIN_IDLE, "[eCall][PSAP] remaining in IDLE mode")
   TRC_MSG(ECALL_PSAP_MODEM_FAST_MODULATION, "[eCall][PSAP] fast modulator chosen (metric: %d)")
   TRC_MSG(ECALL_PSAP_MODEM_ROBUST_MODULATION, "[eCall][PSAP] robust modulator chosen (metric: %d)")

   TRC_MSG(ECALL_IVS_MODEM_CRC, "[eCall][IVS] CRC %x")
   TRC_MSG(ECALL_PSAP_MODEM_CRC, "[eCall][PSAP] CRC %x")
   TRC_MSG(ECALL_PSAP_MODEM_TEMP_MSD, "[eCall][PSAP] Temp MSD (index %3d ~ %3d) %2X %2X %2X %2X %2X %2X %2X %2X %2X %2X")

   //Flexible EQ
   TRC_MSG(FLEXIBLE_EQ_TRANSFORM, "[Flexeq][%d] BarNum = %d")
   TRC_MSG(FLEXIBLE_EQ_SET_INIT,  "[Flexeq] uLen = %d")


   //BT SCO on ARM
   TRC_MSG(L1AUDIO_BTSCO_OPEN     ,"[SCO][DRV]Open, state: %d, uMode: %d, uLink: %d")
   TRC_MSG(L1AUDIO_BTSCO_START    ,"[SCO][DRV]Start, state: %d")
   TRC_MSG(L1AUDIO_BTSCO_STOP     ,"[SCO][DRV]Stop, state: %d")
   TRC_MSG(L1AUDIO_BTSCO_CLOSE    ,"[SCO][DRV]Close, state: %d")
   TRC_MSG(L1AUDIO_BTSCO_PROCESS  ,"[SCO][DRV]Process, state: %d, pRX: 0x%X, pTX: 0x%X")
   TRC_MSG(L1AUDIO_BTSCO_HISR     ,"[SCO][DRV]HISR, state: %d, uIsBtsysOff: %d")
   TRC_MSG(L1AUDIO_BTSCO_CONTROL  ,"[SCO][DRV]Control: 0x%X, PacketType: %d, W_Address: 0x%X, R_Address: 0x%X")
   TRC_MSG(L1AUDIO_BTSCO_COPY_RX  ,"[SCO][DRV]Copy_RX, overflow : %d, iPacket_w: %d, iPacket_r: %d, uBufferCount: %d")
   TRC_MSG(L1AUDIO_BTSCO_COPY_TX  ,"[SCO][DRV]Copy_TX, underflow: %d, iPacket_w: %d, iPacket_r: %d, uBufferCount: %d")
   TRC_MSG(L1AUDIO_BTSCO_SET_RX   ,"[SCO][DRV]SetCallback_RX, state : %d, ch: %d, filter: %d, PLC: %d, callback: 0x%X")
   TRC_MSG(L1AUDIO_BTSCO_SET_TX   ,"[SCO][DRV]SetCallback_TX, state : %d, ch: %d, filter: %d, PLC: %d, callback: 0x%X")
   TRC_MSG(L1AUDIO_BTSCO_GET_MEM  ,"[SCO][DRV]GetMemory, uModule: %d, uSize(byte): %d")
   TRC_MSG(L1AUDIO_BTSCO_PROC_TX_RAW  ,"[SCO][DRV]PROC_TX_RAW, RawDataLen(byte): %d,uPcmBuf_w(byte): %d")
   TRC_MSG(L1AUDIO_BTSCO_PROC_TX_SRC  ,"[SCO][DRV]PROC_TX_SRC, uConsumeByte: %d, uOutByte: %d")
   TRC_MSG(L1AUDIO_BTSCO_PROC_TX_CVSD ,"[SCO][DRV]CVSD_TX_CVSD, iPacket_w: %d, iPacket_r: %d, fEnableFilter: %d")
   TRC_MSG(L1AUDIO_BTSCO_PROC_RX_RAW  ,"[SCO][DRV]PROC_RX_RAW, CurrentFreeSpace(byte): %d, TotalFreeSpace(byte): %d, uPcmBuf_r(byte): %d")
   TRC_MSG(L1AUDIO_BTSCO_PROC_RX_PLC  ,"[SCO][DRV]PROC_RX_PLC")
   TRC_MSG(L1AUDIO_BTSCO_PROC_RX_CVSD ,"[SCO][DRV]CVSD_RX_CVSD, iPacket_w: %d, iPacket_r: %d, fEnableFilter: %d, fEnablePLC: %d")
   TRC_MSG(L1AUDIO_BTSCO_PROC_RX_PLC_PKT_LOST, "[SCO][DRV]PROC_RX_PLC_PKT_LOST, frm = %d")


   TRC_MSG(L1AUDIO_BTSCO_AP_AUDIO_ON        ,"[SCO][APP]Audio Path On, SampleRate: %d, ChannelNumber: %d")
   TRC_MSG(L1AUDIO_BTSCO_AP_AUDIO_OFF       ,"[SCO][APP]Audio Path Off")
   TRC_MSG(L1AUDIO_BTSCO_AP_AUDIO_SETINFO   ,"[SCO][APP]Audio SetInfo, SampleRate: %d, ChannelNumber: %d")
   TRC_MSG(L1AUDIO_BTSCO_AP_AUDIO_DATA      ,"[SCO][APP]Audio Write Data, SrcDataLen(Word): %d, CopyedDataLen(Word): %d, DIFF: %d, Mono2Stereo: %d, ")
   TRC_MSG(L1AUDIO_BTSCO_AP_AUDIO_ZERO      ,"[SCO][APP]Audio Write Zero, SrcDataLen(Word): %d, CopyedDataLen(Word): %d, DIFF: %d")
   TRC_MSG(L1AUDIO_BTSCO_AP_SPEECH_ON        ,"[SCO][APP]Speech Path On")
   TRC_MSG(L1AUDIO_BTSCO_AP_SPEECH_OFF       ,"[SCO][APP]Speech Path Off")
   TRC_MSG(L1AUDIO_BTSCO_AP_CORDLESS_ON      ,"[SCO][APP]Cordless Path On")
   TRC_MSG(L1AUDIO_BTSCO_AP_CORDLESS_OFF     ,"[SCO][APP]Cordless Path Off")
   TRC_MSG(L1AUDIO_BTSCO_AP_SPEECH_TX_DATA   ,"[SCO][APP]Speech TX data, uCurrentSpace(Byte): %d, uTotalSpace(Byte): %d")
   TRC_MSG(L1AUDIO_BTSCO_AP_SPEECH_TX_OF     ,"[SCO][APP]Speech TX Overflow, freespace(byte): %d")
   TRC_MSG(L1AUDIO_BTSCO_AP_SPEECH_RX_DATA   ,"[SCO][APP]Speech RX data, uCurrentData(Byte): %d, uTotalData(Byte): %d")
   TRC_MSG(L1AUDIO_BTSCO_AP_SPEECH_RX_UF     ,"[SCO][APP]Speech RX Underflow, datacount(byte): %d")
   TRC_MSG(L1AUDIO_BTSCO_AP_DISABLE_ALL      ,"[SCO][APP]Disable All APP, Current APP mode: %d")
   TRC_MSG(L1AUDIO_BTSCO_SET_BT              ,"[SCO][APP]SP_DRV Set BT: mode: %d, premode: %d, bt_on: %d")
   TRC_MSG(L1AUDIO_BTSCO_SET_CORDLESS_PATH   ,"[SCO][APP]SP_DRV Set Cordless Path: OrigPath: %d, NewPath: %d")

   TRC_MSG(L1AUDIO_BTSCO_LB_STOP_MED            ,"[SCO][LB]CVSD_Loopback_STOP_MED, uLostPacket: %d, uTotalPacket: %d")
   TRC_MSG(L1AUDIO_BTSCO_LB_CALLBACK_1          ,"[SCO][LB]CVSD_Loopback_Callback, fRuning: %d")
   TRC_MSG(L1AUDIO_BTSCO_LB_CALLBACK_2          ,"[SCO][LB]CVSD_Loopback_Callback, before, [playback]w: %d, r: %d, [record]w: %d, r: %d")
   TRC_MSG(L1AUDIO_BTSCO_LB_CALLBACK_3          ,"[SCO][LB]CVSD_Loopback_Callback, after,  [playback]w: %d, r: %d, [record]w: %d, r: %d")
   TRC_MSG(L1AUDIO_BTSCO_LB_HISR_1              ,"[SCO][LB]CVSD_Loopback_hisr, fRuning : %d")
   TRC_MSG(L1AUDIO_BTSCO_LB_HISR_2              ,"[SCO][LB]CVSD_Loopback_hisr, uPacketType: %d, uControl: 0x%X, Tx: 0x%X, Rx: 0x%X")
   TRC_MSG(L1AUDIO_BTSCO_LB_HISR_3              ,"[SCO][LB]CVSD_Loopback_hisr, [playback]w: %d, r: %d, [record]w: %d, r: %d")
   TRC_MSG(L1AUDIO_BTSCO_LB_RX_OVERFLOW         ,"[SCO][LB]CVSD_Loopback_hisr, RX_Overflow, count: %d")
   TRC_MSG(L1AUDIO_BTSCO_LB_TX_UNDERFLOW        ,"[SCO][LB]CVSD_Loopback_hisr, TX_underflow, count: %d")
   TRC_MSG(L1AUDIO_BTSCO_LB_RX_PACKET_LOST      ,"[SCO][LB]CVSD_Loopback_hisr, Packet Lost: uLostPacket: %d, uTotalPacket: %d")
   TRC_MSG(L1AUDIO_BTSCO_LB_OPEN_FILE_SD        ,"[SCO][LB]CVSD_Loopback_Open_File, USING SD")
   TRC_MSG(L1AUDIO_BTSCO_LB_OPEN_FILE_INTERNAL  ,"[SCO][LB]CVSD_Loopback_Open_File, USING Internal Memory")
   TRC_MSG(L1AUDIO_BTSCO_LB_OPEN_FILE_FAIL_REC  ,"[SCO][LB]CVSD_Loopback_Open_File, Open record file fail")
   TRC_MSG(L1AUDIO_BTSCO_LB_OPEN_FILE_FAIL_PLAY ,"[SCO][LB]CVSD_Loopback_Open_File, Open playback file fail")
   TRC_MSG(L1AUDIO_BTSCO_LB_START_MED           ,"[SCO][LB]CVSD_Loopback_Start_InMed, fRuning: %d")
   TRC_MSG(L1AUDIO_BTSCO_LB_FILE_SIZE           ,"[SCO][LB]CVSD_Loopback_Start_InMed, fileSize: %d")
   TRC_MSG(L1AUDIO_BTSCO_LB_START               ,"[SCO][LB]CVSD_Loopback_Start, fRuning: %d")
   TRC_MSG(L1AUDIO_BTSCO_LB_STOP                ,"[SCO][LB]CVSD_Loopback_Stop, fRuning: %d")
   TRC_MSG(L1AUDIO_BTSCO_HISR_READBACK          ,"[SCO][LB][DRV]Readback in HISR end, Control: 0x%X")
   TRC_MSG(L1AUDIO_BTSCO_LB_RX_CRC_ERROR        ,"[SCO][LB]CVSD_Loopback_hisr, CRC ERROR: uLostPacket: %d, uTotalPacket: %d")

   //pcmrut service
   TRC_MSG(PCMRUT_START,        "[PCMRoute] PcmRut_Start isHookHisr =%d")
   TRC_MSG(PCMRUT_STOP,         "[PCMRoute] PcmRut_Stop  isHookHisr =%d")
   TRC_MSG(PCMRUT_REG,          "[PCMRoute] hook  [%d] hdl=0x%X")
   TRC_MSG(PCMRUT_UNREG,        "[PCMRoute] unhook[%d] hdl=0x%X")
   TRC_MSG(PCMRUT_PUTSILENCE,   "[PCMRoute] PcmRut_PutData_Silence: %d bytes  hdl=0x%X")
   TRC_MSG(PCMRUT_PUTDATA,      "[PCMRoute] PcmRut_PutData: %d bytes ; silence data: %d bytes")
   TRC_MSG(PCMRUT_GETDATA,      "[PCMRoute] PcmRut_GetData: %d bytes")
   TRC_MSG(PCMRUT_HISR_INVALID, "[PCMRoute] Invalid HISR in beginning")
   TRC_MSG(PCMRUT_HISR_1,       "[PCMRoute] hisr, uBufHead1: %d, uBufHead2: %d, dataLen_put: %d, uIntNumberPerFrame: %d, uPcmSegment: %d")
   TRC_MSG(PCMRUT_HISR_2,       "[PCMRoute] hisr, fIsSoundPlaying: %d, uNoDecodeSD: %d, DSP CurRead: %d, MCU CurReadWrite: %d, uPcmSegment: %d")


   //pcmsink
   TRC_MSG(L1AUDIO_SINK_START_IN             , "[L1AU][SINK]pcmsink_start in,  uState: %d, uSampleRate: %d, uChannelNumber:%d" )
   TRC_MSG(L1AUDIO_SINK_START_OUT            , "[L1AU][SINK]pcmsink_start out, uState: %d, uFormat: %d, fIsDSPdecode: %d" )
   TRC_MSG(L1AUDIO_SINK_STOP_IN              , "[L1AU][SINK]pcmsink_stop in,  uState: %d" )
   TRC_MSG(L1AUDIO_SINK_STOP_OUT             , "[L1AU][SINK]pcmsink_stop out, uState: %d" )
   TRC_MSG(L1AUDIO_SINK_DSP_DATA_COUNT       , "[L1AU][SINK]pcmsink_DspGetDataCount, DSP_PCM_R: %d, DSP_PCM_W: %d, uDataCount: %d, uDspSoundWritePos: %d" )
   TRC_MSG(L1AUDIO_SINK_DSP_WRITE_BUF        , "[L1AU][SINK]pcmsink_DSPGetWriteBuffer, DSP_PCM_R: %d, DSP_PCM_W: %d, uLen: %d" )
   TRC_MSG(L1AUDIO_SINK_DSP_WRITE_DONE       , "[L1AU][SINK]pcmsink_DSPWriteDataDone, DSP_PCM_W: %d, uLen: %d" )
   TRC_MSG(L1AUDIO_SINK_UPDATE_GAIN          , "[L1AU][SINK]PcmSink_UpdateGain: uMuteFunction: %d, fAfeMute: %d, uDspGain: %d" )
   TRC_MSG(L1AUDIO_SINK_SET_INTERTTUPT       , "[L1AU][SINK]pcmsink_SetInterruptSample, uSample: %d" )
   TRC_MSG(L1AUDIO_SINK_HISR_UNDERFLOW       , "[L1AU][SINK]pcmsink_Hisr underflow: uState: %d, uDspCurrentSampleCount: %d" )
   TRC_MSG(L1AUDIO_SINK_HISR_IN              , "[L1AU][SINK]pcmsink_Hisr uState: %d, uPcmFunction: %d, uBluetoothFunction: %d, d2m_count: %d" )
   TRC_MSG(L1AUDIO_SINK_HISR_ENDING          , "[L1AU][SINK]pcmsink_Hisr_AudioData Ending, uState: %d, fIsTimeUp: %d" )
   TRC_MSG(L1AUDIO_SINK_HISR_MOVE_DATA       , "[L1AU][SINK]pcmsink_Hisr_AudioData Copy, fFillData: %d, uMovedToDspSamples: %d, isEOF: %d, fIsTimeUp: %d" )
   TRC_MSG(L1AUDIO_SINK_HISR_OUT             , "[L1AU][SINK]pcmsink_Hisr_AudioData out, uState: %d, pMedHdl=0x%X, isUnderflow: %d, waiting: %d, fIsDspUnderflow: %d" )
   TRC_MSG(L1AUDIO_SINK_HISR_SOUND           , "[L1AU][SINK]pcmsink_Hisr_SoundData wordcount: [dsp]: %d, [dtmf]: %d, [mixer]: %d" )
   TRC_MSG(L1AUDIO_SINK_START_BT             , "[L1AU][SINK]PcmSink_StartBT: uCurrentBtFunction: %d, uStartBtFunction: %d" )
   TRC_MSG(L1AUDIO_SINK_STOP_BT              , "[L1AU][SINK]PcmSink_StopBT: uCurrentBtFunction: %d, uStopBtFunction: %d" )
   TRC_MSG(L1AUDIO_SINK_DELAYOFF_BEGIN       , "[L1AU][SINK]pcmsink_DelayOff_TimeUp: uPcmFunction: %d, uState: %d" )
   TRC_MSG(L1AUDIO_SINK_DELAYOFF_EXCUTE      , "[L1AU][SINK]pcmsink_DelayOff_Excute: uPcmFunction: %d, uState: %d" )
   TRC_MSG(L1AUDIO_SINK_STOP_IMMEDIATE       , "[L1AU][SINK]pcmsink_STOP_IMMEDIATE: uPcmFunction: %d, uState: %d" )
   TRC_MSG(L1AUDIO_SINK_BT_MUTE              , "[L1AU][SINK]BT_MuteSpeaker: mute: %d" )
   TRC_MSG(L1AUDIO_SINK_BT_VOLUME            , "[L1AU][SINK]BT_SetLevelVolume: uCurStep: %d, uTotalStep: %d, uDigitalGain: %d" )
   TRC_MSG(L1AUDIO_SINK_HISR_DEBUG1          , "[L1AU][SINK][debug1]CurGain: [0x%X]%d, TarGain: [0x%X]%d, GainStep: [0x%X]%d" )
   TRC_MSG(L1AUDIO_SINK_HISR_DEBUG2          , "[L1AU][SINK][debug2]fIsMediaMute: %d, uMuteFunction: %d, fBtMute %d, uBtGain: %d" )
   TRC_MSG(L1AUDIO_SINK_SET_GAIN             , "[L1AU][SINK]PcmSink_SetGain: uGain: %d, previous uDspGain: %d" )
   TRC_MSG(L1AUDIO_SINK_MUTE                 , "[L1AU][SINK]PcmSink_Mute: fMute: %d, uFunction: %d, previous uMuteFunction: %d" )
   TRC_MSG(L1AUDIO_SINK_DEPOP_MUTE           , "[L1AU][SINK]PcmSink_DepopMute: uMsec: %d, previous uMuteFunction: %d, uState: %d" )

   //MCU DTMF
   TRC_MSG(MCU_DTMF_PLAY                     , "[DTMF]DTMF_MCU_Play, DTMF_SW.pHandle: 0x%X" )
   TRC_MSG(MCU_DTMF_STOP                     , "[DTMF]DTMF_MCU_Stop, DTMF_SW.pHandle: 0x%X" )
   TRC_MSG(MCU_DTMF_STOP_AND_WAIT            , "[DTMF]DTMF_MCU_StopAndWait, DTMF_SW.pHandle: 0x%X, I: %d, IsAudioPlaying: %d, SoundRuning: %d" )
   TRC_MSG(MCU_DTMF_DATA_REQUEST             , "[DTMF]DTMF_MCU_DataRequestCallback, DTMF_SW.pHandle: 0x%X" )
   TRC_MSG(MCU_DTMF_GET_DATA_COUNT           , "[DTMF]DTMF_MCU_GetDataCount, uDataWord: %d" )
   TRC_MSG(MCU_DTMF_READ_DATA_DONE           , "[DTMF]DTMF_MCU_ReadDataDone, uDataWord: %d" )
   TRC_MSG(MCU_DTMF_GET_REAR_BUFFER          , "[DTMF]DTMF_MCU_GetReadBuffer, uDataWord: %d" )
   TRC_MSG(MCU_DTMF_DESTROY                  , "[DTMF]dtmf_mcu_Destroy, DTMF_SW.pHandle: 0x%X, fNewDTMF: %d, fEnding: %d, fForceStop: %d" )
   TRC_MSG(MCU_DTMF_INIT                     , "[DTMF]dtmf_mcu_Init, uSampleRate: %d, uPcmBufSize(byte): %d, uTotalBufferSize(byte): %d" )
   TRC_MSG(MCU_DTMF_PROCESS_ENTRY            , "[DTMF]dtmf_mcu_Process.entry, fNewDTMF: %d, fClearDTMF: %d, fEnding: %d, uBufLen(byte): %d" )
   TRC_MSG(MCU_DTMF_PROCESS_STATUS           , "[DTMF]dtmf_mcu_Process.status, fIsPlaying: %d, uCurrentData: %d, uFlushSilenceCount: %d" )
   TRC_MSG(MCU_DTMF_NEWKEY                   , "[DTMF]dtmf_mcu_ActivatNewKey, uCurIdx: %d, IsQTMF: %d, Freq: [%d] [%d] [%d] [%d]" )
   TRC_MSG(MCU_DTMF_NEWKEY_FORCE_END_2       , "[DTMF]dtmf_mcu_ActivatNewKey, Force stop: uPreIndex2: %d, uRemainDuration: %d" )
   TRC_MSG(MCU_DTMF_NEWKEY_FORCE_END_1       , "[DTMF]dtmf_mcu_ActivatNewKey, Reduce Dur: uPreIndex1: %d, uRemainDuration: %d, uTotalDuration:%d" )
   TRC_MSG(MCU_DTMF_UPDATE_TONE_PREV_END     , "[DTMF]dtmf_mcu_UpdateTone, prev_end: uIndex: %d" )
   TRC_MSG(MCU_DTMF_UPDATE_TONE_CURR_END     , "[DTMF]dtmf_mcu_UpdateTone, curr_end: uIndex: %d" )
   TRC_MSG(MCU_DTMF_UPDATE_TONE_CURR_OFF     , "[DTMF]dtmf_mcu_UpdateTone, curr_off: uIndex: %d" )
   TRC_MSG(MCU_DTMF_UPDATE_TONE_CURR_ON      , "[DTMF]dtmf_mcu_UpdateTone, curr_on : uIndex: %d" )
   TRC_MSG(MCU_DTMF_UPDATE_TONE_RAMPDOWN     , "[DTMF]dtmf_mcu_UpdateTone, RAMPDOWN: uIndex: %d" )

   //misc control
   TRC_MSG(L1AU_ALLOW_MIDI_AUDIOPP           , "[MIXER]Media_AllowPostProcessingOnMidi, fEnable: %d" )
   TRC_MSG(MIXER_START                       , "[MIXER]pcmmixer_Start, pCompHandle: 0x%X, fRunning: %d, uStreamID: %d, uSampleRate: %d, uChannelNumber: %d" )
   TRC_MSG(MIXER_STOP                        , "[MIXER]pcmmixer_Stop , pCompHandle: 0x%X, fRunning: %d, uValidStreamID: %d" )

   //voice changer
   TRC_MSG(SPEECH_VCH_PROCESS                , "[VCH]Voice changer enable: %d  dcm=%d" )
   TRC_MSG(SPEECH_VCH_SET_MODE               , "[VCH]Voice changer ori_mode=%d  mode:%d  is_in_process=%d speech_on=%d" )

   //VAD
   TRC_MSG(VAD_DETECT_RESULT                 , "VAD_Active %d, Cry %d, count %d" )
   
   //DVT usage
   TRC_MSG(VOICE_TO_AUDDAC,        "[DVT] Voice via audio DAC test")
   
   // ATCOMMAND for eco cancellation and noise reduction
   TRC_MSG(SPH_M2M_AT_EC               , "L1SP_SetECOn Ispeech=%d ec_on=%d" )
   TRC_MSG(SPH_M2M_AT_NR               , "L1SP_SetNROn Ispeech=%d dlnr_on=%d ulnr_on=%d" )
   TRC_MSG(SPH_M2M_AT_GetECNR          , "L1SP status EC:%d DLNR:%d ULNR:%d" )  
   TRC_MSG(SPH_M2M_AT_EnableULSE               , "L1SP_Enable UL speech enhancement" )
   TRC_MSG(SPH_M2M_AT_EnableDLSE               , "L1SP_Enable DL speech enhancement" )
   TRC_MSG(SPH_M2M_AT_DisableULSE               , "L1SP_Disable UL speech enhancement" )
   TRC_MSG(SPH_M2M_AT_DisableDLSE               , "L1SP_Disable DL speech enhancement" )
   TRC_MSG(SPH_M2M_AT_SetDLNRStatusReady         , "L1SP_SetDLNRStatusReady" )
   TRC_MSG(SPH_M2M_AT_SetULNRStatusReady         , "L1SP_SetULNRStatusReady" )
   TRC_MSG(SPH_M2M_AT_SetECStatusReady         , "L1SP_SetECStatusReady" )
   TRC_MSG(SPH_M2M_AT_SetDLNRStatusWork        , "L1SP_SetDLNRStatusWork" )
   TRC_MSG(SPH_M2M_AT_SetULNRStatusWork         , "L1SP_SetULNRStatusWork" )
   TRC_MSG(SPH_M2M_AT_SetECStatusWork        , "L1SP_SetECStatusWork" )
   TRC_MSG(SPH_M2M_AT_SetDLNRStatusStop        , "L1SP_SetDLNRStatusStop" )
   TRC_MSG(SPH_M2M_AT_SetULNRStatusStop        , "L1SP_SetULNRStatusStop" )
   TRC_MSG(SPH_M2M_AT_SetECStatusStop       , "L1SP_SetECStatusStop" )
   TRC_MSG(SPH_M2M_AT_SetDLNRStatusIdle        , "L1SP_SetDLNRStatusIdle" )
   TRC_MSG(SPH_M2M_AT_SetULNRStatusIdle         , "L1SP_SetULNRStatusIdle" )
   TRC_MSG(SPH_M2M_AT_SetECStatusIdle        , "L1SP_SetECStatusIdle" )

    // PCM clock
    TRC_MSG(PCM_CLK_TRACE_GPIO_ON            , "[PCM_CLK]GPIO on DIR %x PULLEN %x MODE %x")
    TRC_MSG(PCM_CLK_TRACE_GPIO_OFF           , "[PCM_CLK]GPIO off DIR %x PULLEN %x MODE %x")
    TRC_MSG(PCM_CLK_TRACE_INIT               , "[PCM_CLK]Init")
    TRC_MSG(PCM_CLK_TRACE_IS_ENABLED         , "[PCM_CLK]Is_Enabled = %d")
    TRC_MSG(PCM_CLK_TRACE_ACTIVATING         , "[PCM_CLK]Activate, activating")
    TRC_MSG(PCM_CLK_TRACE_ACTIVATED          , "[PCM_CLK]Activate, do nothing, already activated")
    TRC_MSG(PCM_CLK_TRACE_DEACTIVATING       , "[PCM_CLK]Deactivate, deactivating")
    TRC_MSG(PCM_CLK_TRACE_DEACTIVATED        , "[PCM_CLK]Deactivate, do nothing, already deactivated")
    TRC_MSG(PCM_CLK_TRACE_ENABLE_CHANGE      , "[PCM_CLK]Media_Enable, apply change, b_enable = %d")
    TRC_MSG(PCM_CLK_TRACE_ENABLE_BYPASS      , "[PCM_CLK]Media_Enable, do nothing, b_enable = %d")
    TRC_MSG(PCM_CLK_TRACE_ENABLE_NOT_SUPPORT , "[PCM_CLK]Media_Enable, not supported, b_enable = %d")
    
END_TRACE_MAP(MOD_L1SP)
#endif // _L1SP_TRC_H
