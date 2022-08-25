# Define source file folder to SRC_LIST
AUDFOLDER         =  hal\audio\src\v1
AUD_SOLUTION      =  V1

# Start Define source file lists to SRC_LIST
# Common part
SRC_LIST += interface\hal\audio\audio_create.c  
SRC_LIST += $(strip $(AUDFOLDER))\am.c
SRC_LIST += $(strip $(AUDFOLDER))\sp_drv.c
SRC_LIST += $(strip $(AUDFOLDER))\tone_drv.c
SRC_LIST += $(strip $(AUDFOLDER))\tone_debug.c
SRC_LIST += $(strip $(AUDFOLDER))\dtmf_drv.c
SRC_LIST += $(strip $(AUDFOLDER))\media.c
SRC_LIST += $(strip $(AUDFOLDER))\l1audio_trace.c
SRC_LIST += $(strip $(AUDFOLDER))\pcm4way.c
SRC_LIST += $(strip $(AUDFOLDER))\audio_service.c
SRC_LIST += $(strip $(AUDFOLDER))\wav_codec.c
SRC_LIST += $(strip $(AUDFOLDER))\wav.c
SRC_LIST += $(strip $(AUDFOLDER))\dpmgr.c
SRC_LIST += $(strip $(AUDFOLDER))\l1audio_sph_srv.c
SRC_LIST += $(strip $(AUDFOLDER))\audioPP.c
SRC_LIST += $(strip $(AUDFOLDER))\audioCF.c
SRC_LIST += $(strip $(AUDFOLDER))\audio_idma.c
SRC_LIST += $(strip $(AUDFOLDER))\spe_custom_drv.c
SRC_LIST += $(strip $(AUDFOLDER))\sp_enhance.c
SRC_LIST += $(strip $(AUDFOLDER))\tone_loopback_rec.c         
SRC_LIST += $(strip $(AUDFOLDER))\PCMRB.c
SRC_LIST += hal\audio\src\common\src\AudComUtil.c
SRC_LIST += hal\audio\src\common\src\apm_comp.c
SRC_LIST += $(strip $(AUDFOLDER))\bt_serial_sync_drv.c

ifneq ($(strip $(MED_PROFILE)),MED_MODEM)
   SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\PcmSink.c
   SRC_LIST += hal\audio\src\common\src\AudioDrain.c
   SRC_LIST += hal\audio\src\common\src\MedAdapt.c
   SRC_LIST += hal\audio\src\common\src\PcmRouteSrc.c
   SRC_LIST += hal\audio\src\common\src\pcmRouteService.c
   SRC_LIST += hal\audio\src\common\src\SeekEngine.c
endif

SRC_LIST += $(strip $(AUDFOLDER))\comp\ast.c
SRC_LIST += $(strip $(AUDFOLDER))\comp\kt_Detect.c
SRC_LIST += $(strip $(AUDFOLDER))\comp\media_avsync.c
SRC_LIST += $(strip $(AUDFOLDER))\comp\tonedect.c
SRC_LIST += $(strip $(AUDFOLDER))\comp\tonesyn.c

ifneq ($(filter __MCU_DTMF_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST +=  $(strip $(AUDFOLDER))\PcmMixer.c
endif

AFE_SPLIT_DRIVER_PLATFORM  = MT6251 MT6255 MT6256 MT6250 MT6922 MT6260 MT6261 MT2501 MT2502
ifneq ($(filter $(strip $(MODULE_DEFS)), $(AFE_SPLIT_DRIVER_PLATFORM)),)
   SRC_LIST +=  $(strip $(AUDFOLDER))\afe_common.c
   ifeq ($(strip $(PLATFORM)),MT6260)
     SRC_LIST += $(strip $(AUDFOLDER))\afes\afe_6260.c
   endif
   ifeq ($(strip $(PLATFORM)),MT6250)
     SRC_LIST += $(strip $(AUDFOLDER))\afes\afe_6250.c
   endif
   ifeq ($(strip $(PLATFORM)),MT6255)
     SRC_LIST += $(strip $(AUDFOLDER))\afes\afe_6255.c
   endif
   ifeq ($(strip $(PLATFORM)),MT6922)
     SRC_LIST += $(strip $(AUDFOLDER))\afes\afe_6255.c
   endif
   ifeq ($(strip $(PLATFORM)),MT6256)
     SRC_LIST += $(strip $(AUDFOLDER))\afes\afe_6256.c
   endif
   ifeq ($(strip $(PLATFORM)),MT6261)
     ifneq ($(filter __DUAL_TALK_MODEM_SUPPORT__, $(strip $(CUSTOM_OPTION))),)
       SRC_LIST += $(strip $(AUDFOLDER))\afes\afe_6261m.c
     else
       SRC_LIST += $(strip $(AUDFOLDER))\afes\afe_6261.c
     endif
   endif
   ifeq ($(strip $(PLATFORM)),MT2501)
     SRC_LIST += $(strip $(AUDFOLDER))\afes\afe_6261.c
   endif
   ifeq ($(strip $(PLATFORM)),MT2502)
     SRC_LIST += $(strip $(AUDFOLDER))\afes\afe_6261.c
   endif
else
   SRC_LIST +=  $(strip $(AUDFOLDER))\afe2.c
endif

ifneq ($(filter __VM_CODEC_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST +=  $(strip $(AUDFOLDER))\vm.c
   SRC_LIST +=  $(strip $(AUDFOLDER))\vm_drv.c
endif

ifneq ($(filter __KARAOKE_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST +=  $(strip $(AUDFOLDER))\karaoke_drv.c
   SRC_LIST +=  $(strip $(AUDFOLDER))\remix.c
endif

ifneq ($(filter __CVSD_CODEC_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST +=  $(strip $(AUDFOLDER))\bt_sco_drv.c
   SRC_LIST +=  $(strip $(AUDFOLDER))\bt_sco_app.c
endif

ifneq ($(filter __SPECTRUM_DISPLAY_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST +=  $(strip $(AUDFOLDER))\spt_analyzer.c
endif

ifneq ($(filter __VIBRATION_SPEAKER_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST +=  $(strip $(AUDFOLDER))\vibration_drv.c
   SRC_LIST +=  $(strip $(AUDFOLDER))\vibration_rom.c
endif

ifneq ($(filter BGSND_ENABLE, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\snd_effect.c
endif

ifneq ($(filter WAV_CODEC, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\wav_thumb.c
  SRC_LIST += $(strip $(AUDFOLDER))\pcm_strm_drv.c
  SRC_LIST += $(strip $(AUDFOLDER))\pcm.c
  SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\wav_comp_drv.c
  SRC_LIST += hal\audio\src\common\src\WavDecoder.c
  SRC_LIST += hal\audio\src\common\src\WavParser.c
endif

ifneq ($(filter __DRA_DECODE_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\audio\src\common\src\DraDecoder.c
endif

ifneq ($(filter __CTM_SUPPORT__, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\ctm_drv.c
endif

ifneq ($(filter __ECALL_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\eCall_drv.c
  ifdef ECALL_SOURCE_REL_SUPPORT
    ifeq ($(strip $(ECALL_SOURCE_REL_SUPPORT)),TRUE)
       SRC_LIST += hal\audio\src32\eCall\ecall_control.c \
                   hal\audio\src32\eCall\ecall_fec.c \
                   hal\audio\src32\eCall\ecall_modem.c \
                   hal\audio\src32\eCall\ecall_rom.c \
                   hal\audio\src32\eCall\ecall_sync.c \
                   hal\audio\src32\eCall\modem_ivs.c \
                   hal\audio\src32\eCall\modem_psap.c
    endif
  endif  
endif

ifneq ($(filter AAC_DECODE, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\comp\aac_seek.c
  SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\aac_comp_drv.c
  SRC_LIST += hal\audio\src\common\src\AacParser.c
  ifeq ($(filter __KARAOKE_SUPPORT__, $(strip $(MODULE_DEFS))),)    
     SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\AacDspDecoder.c
  else
     SRC_LIST += hal\audio\src\common\src\AacDecoder.c
  endif       
endif

ifneq ($(filter AAC_PLUS_DECODE, $(strip $(MODULE_DEFS))),)
    SRC_LIST += $(strip $(AUDFOLDER))\aac_huffman_table.c
endif

ifneq ($(filter AMR_CODEC, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\amr.c
  SRC_LIST += $(strip $(AUDFOLDER))\amr_table.c
  SRC_LIST += $(strip $(AUDFOLDER))\comp\amr_seek.c
  SRC_LIST += $(strip $(AUDFOLDER))\comp\jamr.c
  ifneq ($(strip $(MED_PROFILE)),MED_MODEM)
    SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\amr_comp_drv.c
    SRC_LIST += hal\audio\src\common\src\AmrParser.c
    SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\AmrDspDecoder.c
  endif
  ifneq ($(filter DEDI_AMR_REC, $(strip $(MODULE_DEFS))),)
    SRC_LIST += $(strip $(AUDFOLDER))\amr_dedi.c
  endif
endif

ifneq ($(filter __APE_DECODE__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\ape_comp_drv.c
  SRC_LIST += hal\audio\src\common\src\ApeDecoder.c
  SRC_LIST += hal\audio\src\common\src\ApeParser.c
endif

ifneq ($(filter SBC_DECODE, $(strip $(MODULE_DEFS))),)
   SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\a2dp_comp_drv.c
   SRC_LIST += hal\audio\src\common\src\A2dpParser.c
   SRC_LIST += hal\audio\src\common\src\SbcDecoder.c
endif      

ifneq ($(filter __VORBIS_DECODE__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\vorbis_comp_drv.c
  SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\vorbis_strm_comp_drv.c
  SRC_LIST += hal\audio\src\common\src\VorbisStrmDecoder.c
  SRC_LIST += hal\audio\src\common\src\VorbisParser.c
  SRC_LIST += hal\audio\src\common\src\VorbisDecoder.c
endif

ifneq ($(filter __VORBIS_ENCODE__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\vorbis_enc_drv.c
endif

ifneq ($(filter __AUDIO_DSP_LOWPOWER_V2__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\audlp2_drv.c
endif

ifneq ($(filter __ENABLE_AUDIO_DVT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\audio_DVT.c
endif

ifneq ($(filter __COOK_DECODE__, $(strip $(MODULE_DEFS))),)   
  SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\cook_comp_drv.c 
  SRC_LIST += hal\audio\src\common\src\CookDecoder.c
  SRC_LIST += hal\audio\src\common\src\CookParser.c
endif  
  
ifneq ($(filter DAF_DECODE, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\comp\daf_seek.c
  SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\daf_comp_drv.c
  SRC_LIST += hal\audio\src\common\src\DafParser.c
  SRC_LIST += hal\audio\src\common\src\DafDecoder.c
endif

ifneq ($(filter __FLAC_DECODE__ , $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\flac_comp_drv.c
  SRC_LIST += hal\audio\src\common\src\FlacParser.c
  SRC_LIST += hal\audio\src\common\src\FlacDecoder.c
endif

ifneq ($(filter WMA_DECODE, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\wma_comp_drv.c
  SRC_LIST += hal\audio\src\common\src\WmaDecoder.c
  SRC_LIST += hal\audio\src\common\src\WmaParser.c
endif

ifneq ($(filter __DAF_ENCODE__, $(strip $(MODULE_DEFS))),)
  SRC_LIST +=  $(strip $(AUDFOLDER))\mp3_enc_drv.c
endif 

ifneq ($(filter __BT_AUDIO_VIA_SCO__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += $(strip $(AUDFOLDER))\avb_drv.c
endif

ifneq ($(filter __BES_EQ_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\comp\audioeq.c
endif

ifneq ($(filter __BES_TS_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\audio\src\common\src\BesSoundTemplate.c
  SRC_LIST += hal\audio\src\common\src\BesTSEntry.c
endif 

ifneq ($(filter __I2S_INPUT_MODE_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\i2s_drv.c
endif

ifneq ($(filter __BT_A2DP_PROFILE__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\sbc_drv.c
  ifeq ($(filter __LOW_COST_SUPPORT_COMMON__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += $(strip $(AUDFOLDER))\daf_rtpss.c
  endif
endif 

ifneq ($(filter __BT_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\BT_PcmLoopback.c
  ifneq ($(filter BT_Loopback_Test, $(strip $(COMP_DEFS))),)
    SRC_LIST += $(strip $(AUDFOLDER))\BT_loopback.c
  endif   
endif     
  
ifneq ($(filter DSP_WT_SYN, $(strip $(MODULE_DEFS))),)    
   SRC_LIST += $(strip $(AUDFOLDER))\Wavetable_SW.c
   SRC_LIST += hal\audio\src\common\src\melody\jimy_comp.c
   SRC_LIST += hal\audio\src\common\src\melody\jsmf_comp.c
   SRC_LIST += hal\audio\src\common\src\melody\jtone_comp.c
   SRC_LIST += hal\audio\src\common\src\melody\jwav_comp.c
   SRC_LIST += hal\audio\src\common\src\melody\melody_common.c
   SRC_LIST += hal\audio\src\common\src\melody\MelodySynthesizer.c
   SRC_LIST += hal\audio\src\common\src\melody\MelodyParser.c
endif
      
ifneq ($(filter __VAD_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST += $(strip $(AUDFOLDER))\vad_drv.c
endif

ifneq ($(filter AMRWB_ENCODE, $(strip $(MODULE_DEFS))),)
  AWB_SW_ENC_SUPPORT_PLATFORM = MT6255 MT6922
  ifneq ($(filter $(strip $(MODULE_DEFS)), $(AWB_SW_ENC_SUPPORT_PLATFORM)),)
    SRC_LIST += $(strip $(AUDFOLDER))\awb_enc.c
  endif
endif

ifneq ($(filter __AUDIO_RECORD_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\PcmSource.c
   SRC_LIST += hal\audio\src\common\src\PcmPacker.c
   SRC_LIST += hal\audio\src\common\src\SRConv.c
   ifneq ($(filter WAV_CODEC, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\pcm_comp_rec.c
      SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\wav_comp_rec.c
      SRC_LIST += hal\audio\src\common\src\WavEncoder.c
   endif
   ifneq ($(filter AMR_CODEC, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\amr_comp_rec.c
      SRC_LIST += hal\audio\src\v1\comp\PBMG\AmrDspEncoder.c
   endif
   ifneq ($(filter DEDI_AMR_REC, $(strip $(MODULE_DEFS))),)
      SRC_LIST += hal\audio\src\common\src\AmrEncoder.c
   endif
   ifneq ($(filter __VORBIS_ENCODE__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\vorbis_comp_rec.c
      SRC_LIST += hal\audio\src\common\src\VorbisEncoder.c
   endif
   ifneq ($(filter __VM_CODEC_SUPPORT__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\vm_comp_rec.c
      SRC_LIST += hal\audio\src\v1\comp\PBMG\VmDspEncoder.c
   endif
   ifneq ($(filter __SPEECH_ENHENCEMENT_SWIP_SUPPORT__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += hal\audio\src\common\src\SphEnhance.c
   endif
endif

ifneq ($(filter CYBERON_DIC_TTS, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\tts_drv.c
else
  ifneq ($(filter IFLY_TTS, $(strip $(MODULE_DEFS))),)
    SRC_LIST += $(strip $(AUDFOLDER))\tts_drv.c
    endif
endif

ifneq ($(filter SINOVOICE_TTS, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\tts_drv.c
endif

ifneq ($(filter __DUAL_TALK_MODEM_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\spc_drv.c
  SRC_LIST += $(strip $(AUDFOLDER))\pcm_rec.c
  SRC_LIST += $(strip $(AUDFOLDER))\audl_service.c
  SRC_LIST += $(strip $(AUDFOLDER))\sp_strm_drv.c
endif  

ifneq ($(filter __UMTS_RAT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST += $(strip $(AUDFOLDER))\amr_table.c \
               $(strip $(AUDFOLDER))\sp_3g.c
else
  ifneq ($(filter __UMTS_TDD128_MODE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += $(strip $(AUDFOLDER))\amr_table.c \
                $(strip $(AUDFOLDER))\sp_3g.c
  endif
endif

ifneq ($(filter __LG_VOICE_ENGINE__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\voice_clarity.c
endif
 
#  Define include path lists to INC_DIR
INC_DIR += $(strip $(AUDFOLDER))
INC_DIR += $(strip $(AUDFOLDER))\inc
INC_DIR += $(strip $(AUDFOLDER))\comp
INC_DIR += hal\audio\src\common\inc
INC_DIR += hal\audio\lib\MTKINC
INC_DIR += hal\audio\lib\VENDOR\tc01
INC_DIR += interface\hal\audio
INC_DIR += interface\hal\video
INC_DIR += interface\hal\system
INC_DIR += hal\dsp_ram
INC_DIR += hal\dp_engine\ctm
INC_DIR += hal\dp_engine
INC_DIR += $(strip $(PS_FOLDER))\l4\include
INC_DIR += hal\audio\src32_inc
INC_DIR += drv\include
INC_DIR += hal\video\demuxer\mp4_parser\inc
INC_DIR += hal\system\init\inc
INC_DIR += l1_dm\l1d_ext
INC_DIR += hal\system\DP\inc
INC_DIR += hal\system\dcmgr\inc
INC_DIR += custom\common\hal
INC_DIR += hal\system\AP_BtSS\inc
INC_DIR +=track\os\os_inc \
INC_DIR +=track\drv\drv_inc \
INC_DIR +=track\at\at_inc \
INC_DIR +=track\soc\soc_inc \
INC_DIR +=ELL\ell-common \
INC_DIR +=track\cmd\cmd_inc \
INC_DIR +=track\cust\cust_inc \
INC_DIR +=track\fun\fun_inc \
INC_DIR +=hal\peripheral\inc \
INC_DIR += track_agps\inc \
INC_DIR +=kal\include \
INC_DIR +=interface\hal\peripheral \
INC_DIR +=gps\mnl\include  
ifneq ($(filter __GENERAL_TTS__, $(strip $(MODULE_DEFS))),)
     INC_DIR += hal\audio\lib\VENDOR\tts
endif
  
ifneq ($(filter __CENTRALIZED_SLEEP_MANAGER__, $(strip $(MODULE_DEFS))),)
  INC_DIR    += hal\sleep_drv\public\inc
endif
  
# Define the specified compile options to COMP_DEFS
COMP_DEFS = APC S_INTWORK
  
