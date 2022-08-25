# Define source file lists to SRC_LIST
SRC_LIST = media\metatag\src\ape_parser.c \
           media\metatag\src\id3_v1_parser.c \
           media\metatag\src\id3_v2_parser.c \
           media\metatag\src\meta_tag_api.c \
           media\metatag\src\meta_tag_parser.c \
           media\metatag\src\lyrics_parser.c \
           media\audio\src\aud_api.c \
           media\audio\src\aud_main.c \
           media\audio\src\aud_audio.c \
           media\audio\src\aud_speech.c \
           media\audio\src\aud_keytone.c \
           media\audio\src\aud_tone.c \
           media\audio\src\aud_melody.c \
           media\audio\src\aud_ilm.c \
           media\audio\src\aud_utility.c \
           media\audio\src\aud_media.c \
           media\audio\src\aud_fmradio.c \
           media\audio\src\aud_mma.c \
           media\audio\src\aud_post_process.c \
           media\audio\src\aud_id3_parser.c \
           media\audio\src\aud_daf_parser.c \
           media\audio\src\aud_player_media.c \
           media\audio\src\aud_player_mma.c \
           media\audio\src\aud_bt_a2dp.c \
           Media\common\src\bytestream_hw.c \
           media\common\src\med_main.c \
           media\common\src\med_utility.c \
           media\image\src\img_main.c \
           media\image\src\img_api.c \
           media\image\src\img_msg_handler.c \
           media\image\src\img_ilm.c \
           media\common\src\med_int_smalloc.c \
           media\common\src\med_ext_smalloc.c \
           media\video\src\vid_main.c \
           media\video\src\vid_api.c \
           media\video\src\vid_msg_handler.c \
           media\video\src\vid_recorder_msg_handler.c \
           media\video\src\vid_clipper_msg_handler.c \
           media\video\src\vid_msg_handler_modis.c \
           media\video\src\vid_ilm.c \
           media\common\src\med_v_main.c \
           media\common\src\med_ilm.c \
           media\common\src\med_api.c

#
# Audio
#
ifneq ($(filter __GAIN_TABLE_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += media\audio\src\aud_volume.c
endif

ifneq ($(filter __ATV_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += media\audio\src\aud_atv.c
endif

ifneq ($(filter __BT_HFG_PROFILE__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += media\audio\src\aud_bt_hfp.c
else
  ifneq ($(filter __BT_HF_PROFILE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += media\audio\src\aud_bt_hfp.c
  endif
endif

ifneq ($(filter __BT_A2DP_PROFILE__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += media\audio\src\aud_bt_main.c
else
  ifneq ($(filter __BT_HFG_PROFILE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += media\audio\src\aud_bt_main.c
  else
    ifneq ($(filter __BT_HF_PROFILE__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += media\audio\src\aud_bt_main.c
    endif
  endif
endif

ifeq ($(filter MED_V_NOT_PRESENT, $(strip $(MODULE_DEFS))),)
  SRC_LIST += media\audio\src\aud_build_cache.c
endif

ifneq ($(filter __CTM_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += media\audio\src\aud_ctm.c
endif

ifneq ($(filter __ECALL_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += media\audio\src\aud_ecall.c
endif

# Rich audio profile
ifneq ($(filter __RICH_AUDIO_PROFILE__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += media\audio\src\aud_input_stream.c
endif

ifneq ($(filter DSP_WT_SYN, $(strip $(MODULE_DEFS))),)
  ifeq ($(filter NEPTUNE_MMI, $(strip $(MODULE_DEFS))),)
    #SRC_LIST += media\audio\src\aud_mma.c
  endif
endif

  SRC_LIST += media\audio\src\aud_player_mpl.c

#ifneq ($(filter AUD_REC_ENABLE, $(strip $(MODULE_DEFS))),)
  SRC_LIST += media\audio\src\aud_record.c
  ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += media\audio\src\aud_recorder_media.c
  endif
#endif

ifneq ($(filter BGSND_ENABLE, $(strip $(MODULE_DEFS))),)
  SRC_LIST += media\audio\src\aud_snd.c
endif

ifneq ($(filter __GENERAL_TTS__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += media\audio\src\aud_tts.c
endif

ifneq ($(filter VM_SUPPORT, $(strip $(MODULE_DEFS))),)
  ifneq ($(filter VM_LOG, $(strip $(MODULE_DEFS))),)
    SRC_LIST += media\audio\src\aud_vm.c
  endif
endif

ifneq ($(filter VR_ENABLE, $(strip $(MODULE_DEFS))),)
  SRC_LIST += media\audio\src\aud_vr_main.c \
              media\audio\src\aud_vr_sd.c
endif

ifneq ($(filter VRSI_ENABLE, $(strip $(MODULE_DEFS))),)
  SRC_LIST += media\audio\src\aud_vrsi_main.c \
              media\audio\src\aud_vr_si.c
endif

ifneq ($(filter __AUDIO_TRIM_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += media\audio\src\aud_trim.c
endif

#
# Bitstream
#
ifneq ($(filter __BITSTREAM_API_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += media\bitstream\src\bitstream_ilm.c \
              media\bitstream\src\bitstream_main.c \
              media\bitstream\src\bitstream_audio.c \
              media\bitstream\src\bitstream_record.c
endif

ifneq ($(filter ISP_SUPPORT,$(strip $(MODULE_DEFS))),)
SRC_LIST += media\camera\src\cam_main.c \
            media\camera\src\cam_api.c \
            media\camera\src\cam_msg_handler.c \
            media\camera\src\cam_ilm.c
else
ifneq ($(filter __DIRECT_SENSOR_SUPPORT__,$(strip $(MODULE_DEFS))),)
SRC_LIST += media\camera\src\cam_main.c \
            media\camera\src\cam_api.c \
            media\camera\src\cam_msg_handler.c \
            media\camera\src\cam_ilm.c
endif
endif

#ifneq ($(filter WEBCAM_SUPPORT,$(strip $(MODULE_DEFS))),)
SRC_LIST += media\webcam\src\webcam_main.c \
            media\webcam\src\webcam_msg_handler.c \
            media\webcam\src\webcam_ilm.c \
            media\webcam\src\webcam_api.c
#endif

ifneq ($(filter TV_OUT_SUPPORT,$(strip $(MODULE_DEFS))),)
SRC_LIST += media\tvout\src\tvo_main.c \
            media\tvout\src\tvo_msg_handler.c \
            media\tvout\src\tvo_api.c \
            media\tvout\src\tvo_ilm.c
endif

ifneq ($(filter __MEDIA_VT__,$(strip $(MODULE_DEFS))),)
SRC_LIST += media\vcall\src\vcall_ilm.c \
            media\vcall\src\vcall_main.c \
            media\vcall\src\vcall_msg_hdlr.c \
            media\vcall\src\vcall.c
endif

ifneq ($(filter __VAD_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += media\audio\src\aud_vad.c
endif

#  Define include path lists to INC_DIR
INC_DIR = drv\include \
          media\common\include \
          media\audio\include \
          hal\mm_comm\inc \
          media\video\include \
          media\camera\include \
          media\image\include \
          media\webcam\include \
          media\tvout\include \
          media\mtv\include \
          drm\include \
          interface\ps\enum \
          interface\ps\include \
          interface\ps\local_inc \
          plutommi\mtkapp\mtkappinc \
          plutommi\Framework\GDI\gdiinc \
          plutommi\mmi\inc \
          plutommi\Framework\Interface \
          plutommi\service\mdi\mdiinc \
          plutommi\Service\ImgEdtSrv \
          media\rtp\inc \
          media\stream\include \
          applib\inet\engine\include \
          sst\include \
          applib\misc\include \
          $(strip $(PS_FOLDER))\l4\uem\include \
          media\vcall\include \
          media\metatag\include \
          interface\hwdrv \
          media\bitstream\include \
          vendor\player\ipeer\inc \
          blueangel\btcore\btstack\inc \
          blueangel\btcore\btadp\inc \
          matv\inc \
          interface\hal\video \
          interface\hal\mdp \
          interface\hal\fmr \
          interface\hal\drv_sw_def \
          hal\drv_def \
          hal\mm_comm\inc \
          hal\video\demuxer\provider\inc \
          hal\video\demuxer\mp4_parser\inc \
          hal\video\demuxer\avi_parser\inc \
          custom\video \
          hal\video\mpl\inc \
          hal\video\custom \
          hal\video_codec\interface\inc \
          btmt\rf_desense \
          interface\hal\connectivity\usb_driver \
          interface\hal\peripheral \
          interface\media\video \
          hal\peripheral\inc \
          interface\hal\bluetooth \
          plutommi\MMI\BrowserApp\Browser\BrowserInc \
          vendor\wap\obigo_Q03C\adaptation\integration\include \
          plutommi\Service\BrowserSrv \
          hal\system\dcmgr\inc \
          plutommi\Framework\CommandProcessor\CommandProcessorInc\
         track\drv\drv_inc \
          track\at\at_inc \
          ELL\ell-common \
          track\fun\fun_inc \
          track\at\at_inc \
          gps\mnl\include


# Define the specified compile options to COMP_DEFS
COMP_DEFS = VM_SUPPORT \
            __ID3_INFO_ENABLE__ \
            MMA_AMR_SUPPORT \
            MMI_ON_HARDWARE_P


ifeq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += media\audio\src\aud_player_modis.c
  SRC_LIST += media\audio\src\aud_recorder_modis.c
  INC_DIR += MoDIS_VC9\MoDIS
endif

