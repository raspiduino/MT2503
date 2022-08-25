########## General platforms ##############

VIDEO_CODEC_SUPPORT_PLATFORM_ARM7 = MT6252 MT6252H MT6253E MT6253L MT6250 MT6260 MT6261
VIDEO_CODEC_SUPPORT_PLATFORM_ARM7TCM = MT6253
VIDEO_CODEC_SUPPORT_PLATFORM_ARM9 = MT6235 MT6235B MT6255 MT6922
VIDEO_CODEC_SUPPORT_PLATFORM_ARM9TCM = MT6236 MT6236B MT6921
VIDEO_CODEC_SUPPORT_PLATFORM_ARM11 = MT6276 MT6256

VIDEO_CODEC_SUPPORT_PLATFORM =  $(VIDEO_CODEC_SUPPORT_PLATFORM_ARM11) \
                                $(VIDEO_CODEC_SUPPORT_PLATFORM_ARM9TCM) \
                                $(VIDEO_CODEC_SUPPORT_PLATFORM_ARM9) \
                                $(VIDEO_CODEC_SUPPORT_PLATFORM_ARM7TCM) \
                                $(VIDEO_CODEC_SUPPORT_PLATFORM_ARM7)
                                
VIDEO_CODEC_SUPPORT_PLATFORM_ARM11TCM = NONE

########## Codec specified platforms ##############

VIDEO_CODEC_SUPPORT_PLATFORM_HYBRID_MP4ENC = MT6256
VIDEO_CODEC_SUPPORT_PLATFORM_HYBRID_MP4ENC_V5 = MT6250

########## H.264 decoder ##########################
H264_DECODE_MPHP_LIB = h264dec_mphp.arm11.a \
                       h264dec_mphp.arm9.a \
                       h264dec_mphp.arm9tcm.a  \
                       h264dec_mphp.arm7.a \
                       h264dec_mphp.arm7tcm.a \
                       h264dec_mphp.arm11.rel.a \
                       h264dec_mphp.arm9.rel.a \
                       h264dec_mphp.arm9tcm.rel.a  \
                       h264dec_mphp.arm7.rel.a \
                       h264dec_mphp.arm11.rvct22.a \
                       h264dec_mphp.arm11.rvct22.rel.a \
                       h264dec_mphp.arm7tcm.rel.a

H264_DECODE_LIB = h264dec.arm11.a \
                  h264dec.arm9.a \
                  h264dec.arm9tcm.a \
                  h264dec.arm7.a \
                  h264dec.arm7tcm.a \
                  h264dec.arm11.rvct22.a \
                  h264dec.arm11.rel.a \
                  h264dec.arm9.rel.a \
                  h264dec.arm9tcm.rel.a \
                  h264dec.arm7.rel.a \
                  h264dec.arm7tcm.rel.a \
                  h264dec.arm11.rvct22.rel.a

ifeq ($(strip $(H264_DECODE)),TRUE)
  ifeq ($(strip $(H264_DECODE_PROFILE)),MAINHIGH)
    COM_DEFS    += __H264_DEC_SW_SUPPORT_MAINHIGH__

    VIDEO_CODEC_LIB_NAME_LIST += $(H264_DECODE_MPHP_LIB)
  else
    VIDEO_CODEC_LIB_NAME_LIST += $(H264_DECODE_LIB)
  endif
endif

VIDEO_CODEC_CUS_REL_LIB_NAME_LIST += $(H264_DECODE_MPHP_LIB) $(H264_DECODE_LIB)

########## MPEG-4 decoder ##########################
MPEG4_DECODE_UVT_LIB = uvtdec.arm9.a \
                       uvtdec.arm9.rel.a \
                       uvtdec.arm9tcm.a \
                       uvtdec.arm11.a \
                       uvtdec.arm11.rvct22.a \
                       uvtdec.arm9tcm.rel.a \
                       uvtdec.arm11.rel.a \
                       uvtdec.arm11.rvct22.rel.a

MP4_DECODE_LIB = mp4dec.arm9.a \
                 mp4dec.arm9tcm.a \
                 mp4dec.arm11.a \
                 mp4dec.arm11.rvct22.a \
                 mp4dec.arm7.a \
                 mp4dec.arm7tcm.a \
                 mp4dec.arm9.rel.a \
                 mp4dec.arm9tcm.rel.a \
                 mp4dec.arm11.rel.a \
                 mp4dec.arm11.rvct22.rel.a \
                 mp4dec.arm7.rel.a \
                 mp4dec.arm7tcm.rel.a


MP4_DECODE_COMMON_LIB = mp4com.arm9.a \
                        mp4com.arm9tcm.a \
                        mp4com.arm11.a \
                        mp4com.arm11.rvct22.a \
                        mp4com.arm7.a \
                        mp4com.arm7tcm.a \
                        mp4com.arm9.rel.a \
                        mp4com.arm9tcm.rel.a \
                        mp4com.arm11.rel.a \
                        mp4com.arm11.rvct22.rel.a \
                        mp4com.arm7.rel.a \
                        mp4com.arm7tcm.rel.a


MP4_DECODE_ASP_LIB = mp4dec_asp.arm9.a \
                     mp4dec_asp.arm9tcm.a \
                     mp4dec_asp.arm11.a \
                     mp4dec_asp.arm11.rvct22.a \
                     mp4dec_asp.arm7.a \
                     mp4dec_asp.arm7tcm.a \
                     mp4dec_asp.arm9.rel.a \
                     mp4dec_asp.arm9tcm.rel.a \
                     mp4dec_asp.arm11.rel.a \
                     mp4dec_asp.arm11.rvct22.rel.a \
                     mp4dec_asp.arm7.rel.a \
                     mp4dec_asp.arm7tcm.rel.a


MP4_DECODE_ASP_COMMON_LIB = mp4com_asp.arm9.a \
                            mp4com_asp.arm9tcm.a \
                            mp4com_asp.arm11.a \
                            mp4com_asp.arm11.rvct22.a \
                            mp4com_asp.arm7.a \
                            mp4com_asp.arm7tcm.a \
                            mp4com_asp.arm9.rel.a \
                            mp4com_asp.arm9tcm.rel.a \
                            mp4com_asp.arm11.rel.a \
                            mp4com_asp.arm11.rvct22.rel.a \
                            mp4com_asp.arm7.rel.a \
                            mp4com_asp.arm7tcm.rel.a

MP4_DECODE_ULC_LIB = mp4dec_ulc.arm7.a \
                     mp4com_ulc.arm7.a \
                     mp4dec_ulc.arm7.rel.a \
                     mp4com_ulc.arm7.rel.a \

ifeq ($(strip $(MP4_DECODE)),TRUE)
  ifneq ($(filter $(strip $(PLATFORM)) ,$(VIDEO_CODEC_SUPPORT_PLATFORM_ARM11) $(VIDEO_CODEC_SUPPORT_PLATFORM_ARM9) $(VIDEO_CODEC_SUPPORT_PLATFORM_ARM9TCM)),)
    VIDEO_CODEC_LIB_NAME_LIST += $(MPEG4_DECODE_UVT_LIB)
    ifeq ($(strip $(MP4_DECODE_PROFILE)),ASP)
      VIDEO_CODEC_LIB_NAME_LIST += $(MP4_DECODE_ASP_COMMON_LIB)
    else
      VIDEO_CODEC_LIB_NAME_LIST += $(MP4_DECODE_COMMON_LIB)
    endif
  endif

  ifneq ($(filter $(strip $(COM_DEFS)) , __MED_VIDEO_ULC__),)
    ifneq ($(filter $(strip $(PLATFORM)) ,$(VIDEO_CODEC_SUPPORT_PLATFORM_ARM7)),)
      VIDEO_CODEC_LIB_NAME_LIST += $(MP4_DECODE_ULC_LIB)
    endif
  else
    ifeq ($(strip $(MP4_DECODE_PROFILE)),ASP)
      COM_DEFS    += __MP4_DEC_SW_SUPPORT_ASP__

      VIDEO_CODEC_LIB_NAME_LIST += $(MP4_DECODE_ASP_LIB)
      VIDEO_CODEC_LIB_NAME_LIST += $(MP4_DECODE_ASP_COMMON_LIB)
    else
      VIDEO_CODEC_LIB_NAME_LIST += $(MP4_DECODE_LIB)
      VIDEO_CODEC_LIB_NAME_LIST += $(MP4_DECODE_COMMON_LIB)
    endif
  endif
endif

VIDEO_CODEC_CUS_REL_LIB_NAME_LIST += $(MPEG4_DECODE_UVT_LIB) $(MP4_DECODE_LIB) $(MP4_DECODE_COMMON_LIB) $(MP4_DECODE_ASP_LIB) $(MP4_DECODE_ASP_COMMON_LIB) $(MP4_DECODE_ULC_LIB)

########## RM Decode ##########################
RM_DECODE_LIB = rmdec.arm11.a \
                rmdec.arm11.rvct22.a \
                rmdec.arm9.a \
                rmdec.arm9tcm.a \
                rmdec.arm7.a \
                rmdec.arm7tcm.a \
                rmdec.arm11.rel.a \
                rmdec.arm11.rvct22.rel.a \
                rmdec.arm9.rel.a \
                rmdec.arm9tcm.rel.a \
                rmdec.arm7.rel.a \
                rmdec.arm7tcm.rel.a

ifeq ($(strip $(RM_DECODE)),TRUE)
  VIDEO_CODEC_LIB_NAME_LIST += $(RM_DECODE_LIB)
  VIDEO_CODEC_CUS_REL_LIB_NAME_LIST += $(RM_DECODE_LIB)
endif

########## VP8 Decode ##########################
VP8_DECODE_LIB = vp8dec.arm11.a \
                 vp8dec.arm11.rel.a \
                 vp8dec.arm11.rvct22.a \
                 vp8dec.arm11.rvct22.rel.a \
                 vp8dec.arm7.a \
                 vp8dec.arm7.rel.a \
                 vp8dec.arm7tcm.a \
                 vp8dec.arm7tcm.rel.a \
                 vp8dec.arm9.a \
                 vp8dec.arm9.rel.a \
                 vp8dec.arm9tcm.a \
                 vp8dec.arm9tcm.rel.a

ifeq ($(strip $(VP8_DECODE)),TRUE)
  VIDEO_CODEC_LIB_NAME_LIST += $(VP8_DECODE_LIB)
  VIDEO_CODEC_CUS_REL_LIB_NAME_LIST += $(VP8_DECODE_LIB)
endif

########## MP4 Encode ##########################
MP4_ENCODE_HYBRID_PLATFORM_HYBRID_LIB = mp4enc_hybrid.arm11.a \
                                        mp4enc_hybrid.arm11.rvct22.a \
                                        mp4enc_hybrid.arm11.rel.a \
                                        mp4enc_hybrid.arm11.rvct22.rel.a

MP4_ENCODE_HYBRID_PLATFORM_NORMAL_LIB = mp4enc.arm11.a \
                                        mp4enc.arm11.rel.a

MP4_ENCODE_HYBRID_PLATFORM_HYBRID_LIB_V5 = mp4enc_hybrid_v5.arm7.a \
                                           mp4enc_hybrid_v5.arm7.rel.a

MP4_ENCODE_HYBRID_PLATFORM_NORMAL_LIB_V5 = mp4enc.arm7.arm7tcm.a \
                                           mp4enc.arm7.arm7tcm.rel.a

MP4_ENCODE_LIB = mp4enc.arm9.arm9tcm.a \
                 mp4enc.arm9.arm9tcm.rel.a

MP4_ENCODE_UVT_LIB = uvtenc.arm11.a \
                     uvtenc.arm11.rvct22.a \
                     uvtenc.arm9.a \
                     uvtenc.arm9.rel.a \
                     uvtenc.arm9tcm.a \
                     uvtenc.arm11.rel.a \
                     uvtenc.arm11.rvct22.rel.a \
                     uvtenc.arm9tcm.rel.a

ifeq ($(strip $(MP4_ENCODE)),TRUE)
  ifneq ($(filter $(strip $(PLATFORM)) ,$(VIDEO_CODEC_SUPPORT_PLATFORM_ARM11) $(VIDEO_CODEC_SUPPORT_PLATFORM_ARM11TCM)),)
    ifneq ($(filter $(strip $(PLATFORM)) ,$(VIDEO_CODEC_SUPPORT_PLATFORM_HYBRID_MP4ENC)),)
      VIDEO_CODEC_LIB_NAME_LIST += $(MP4_ENCODE_HYBRID_PLATFORM_HYBRID_LIB)
    else
      VIDEO_CODEC_LIB_NAME_LIST += $(MP4_ENCODE_HYBRID_PLATFORM_NORMAL_LIB)
    endif
  endif

  ifneq ($(filter $(strip $(PLATFORM)) ,$(VIDEO_CODEC_SUPPORT_PLATFORM_ARM7) $(VIDEO_CODEC_SUPPORT_PLATFORM_ARM7TCM)),)
    ifneq ($(filter $(strip $(PLATFORM)) ,$(VIDEO_CODEC_SUPPORT_PLATFORM_HYBRID_MP4ENC_V5)),)
      VIDEO_CODEC_LIB_NAME_LIST += $(MP4_ENCODE_HYBRID_PLATFORM_HYBRID_LIB_V5)
    else
      VIDEO_CODEC_LIB_NAME_LIST += $(MP4_ENCODE_HYBRID_PLATFORM_NORMAL_LIB_V5)
    endif
  endif

  VIDEO_CODEC_LIB_NAME_LIST += $(MP4_ENCODE_LIB)

  ifneq ($(filter $(strip $(PLATFORM)) ,$(VIDEO_CODEC_SUPPORT_PLATFORM_ARM11) $(VIDEO_CODEC_SUPPORT_PLATFORM_ARM9) $(VIDEO_CODEC_SUPPORT_PLATFORM_ARM9TCM)),)
    VIDEO_CODEC_LIB_NAME_LIST += $(MP4_ENCODE_UVT_LIB)
  endif
endif

VIDEO_CODEC_CUS_REL_LIB_NAME_LIST += $(MP4_ENCODE_HYBRID_PLATFORM_HYBRID_LIB) $(MP4_ENCODE_HYBRID_PLATFORM_NORMAL_LIB) $(MP4_ENCODE_HYBRID_PLATFORM_HYBRID_LIB_V5) $(MP4_ENCODE_HYBRID_PLATFORM_NORMAL_LIB_V5) 
VIDEO_CODEC_CUS_REL_LIB_NAME_LIST += $(MP4_ENCODE_LIB) $(MP4_ENCODE_UVT_LIB)

########## H.264 Encode ##########################
H264_ENCODE_LIB = h264enc.arm9.a \
                  h264enc.arm9.rel.a \
                  h264enc.arm11.a \
                  h264enc.arm11.rel.a \
                  h264enc.arm11.rvct22.a \
                  h264enc.arm11.rvct22.rel.a

ifeq ($(strip $(H264_ENCODE)),TRUE)
  VIDEO_CODEC_LIB_NAME_LIST += $(H264_ENCODE_LIB)
endif

VIDEO_CODEC_CUS_REL_LIB_NAME_LIST += $(H264_ENCODE_LIB)

VIDEO_CODEC_LIB_LIST = $(VIDEO_CODEC_LIB_NAME_LIST:%.a=hal\video_codec\lib\\%.a)
VIDEO_CODEC_CUS_REL_LIB_LIST = $(VIDEO_CODEC_CUS_REL_LIB_NAME_LIST:%.a=hal\video_codec\lib\\%.a)

ifneq ($(filter $(strip $(PLATFORM)) ,$(VIDEO_CODEC_SUPPORT_PLATFORM_ARM7)),)
  VIDEO_CODEC_CONFIG_EXT += .arm7.
endif

ifneq ($(filter $(strip $(PLATFORM)) ,$(VIDEO_CODEC_SUPPORT_PLATFORM_ARM7TCM)),)
  VIDEO_CODEC_CONFIG_EXT += .arm7tcm.
endif

ifneq ($(filter $(strip $(PLATFORM)) ,$(VIDEO_CODEC_SUPPORT_PLATFORM_ARM9)),)
  VIDEO_CODEC_CONFIG_EXT += .arm9.
endif

ifneq ($(filter $(strip $(PLATFORM)) ,$(VIDEO_CODEC_SUPPORT_PLATFORM_ARM9TCM)),)
  VIDEO_CODEC_CONFIG_EXT += .arm9tcm.
endif

ifneq ($(filter $(strip $(PLATFORM)) ,$(VIDEO_CODEC_SUPPORT_PLATFORM_ARM11)),)
  VIDEO_CODEC_CONFIG_EXT += .arm11.
endif

ifneq ($(filter $(strip $(PLATFORM)) ,$(VIDEO_CODEC_SUPPORT_PLATFORM_ARM11TCM)),)
  VIDEO_CODEC_CONFIG_EXT += .arm11tcm.
endif

ifeq ($(filter $(strip $(PLATFORM)) ,$(VIDEO_CODEC_SUPPORT_PLATFORM)),)
  VIDEO_CODEC_CONFIG_EXT += .none.
endif

ifneq ($(strip $(DEMO_PROJECT)),TRUE)
  VIDEO_CODEC_CONFIG_EXT += .rel.
else
  VIDEO_CODEC_CONFIG_NEGATIVE_EXT += .rel.
endif

ifeq ($(strip $(RVCT_VERSION)),V22)
  VIDEO_CODEC_CONFIG_EXT += .rvct22.
else
  VIDEO_CODEC_CONFIG_NEGATIVE_EXT += .rvct22.
endif