# *************************************************************************
# Common macro definitions
# *************************************************************************
#$(call Upper,$(1)) ...... reference $(1) in upper-case letters
Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))

# *************************************************************************
# Common definitions
# *************************************************************************
ifndef MMI_BASE
  OPTR_MMIDIR   = plutommi
else
  ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
    OPTR_MMIDIR         =  lcmmi
  else
    ifeq ($(strip $(MMI_BASE)),VENUS_MMI)
      OPTR_MMIDIR         =  venusmmi
    else
      OPTR_MMIDIR         =  plutommi
    endif
  endif
endif

ifdef OPTR_SPEC
ifneq ($(strip $(OPTR_SPEC)),NONE)
  OPTR_PATH = operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC)))\$(word 2,$(subst _, ,$(OPTR_SPEC))))\$(strip $(OPTR_MMIDIR))
  -include $(OPTR_PATH)\operator.mak
endif
endif

L1S_BASIC=FALSE
ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
  L1S_BASIC=TRUE
endif
ifeq ($(call Upper,$(strip $(PROJECT))),BASIC)
  L1S_BASIC=TRUE
endif
ifeq ($(call Upper,$(strip $(PROJECT))),UDVT)
  L1S_BASIC=TRUE
endif

L1_UMTS=FALSE
ifeq ($(strip $(L1_WCDMA)),TRUE)
  L1_UMTS=TRUE
endif
ifeq ($(strip $(L1_TDD128)),TRUE)
  L1_UMTS=TRUE
endif

PS_FOLDER=ps
UAS_FOLDER=uas
ifeq ($(strip $(PPPV6_SUPPORT)),TRUE)
  PPP_FOLDER=ppp_v6
else
  PPP_FOLDER=ppp
endif

ifdef L1_TDD128
ifeq ($(strip $(L1_TDD128)),TRUE)
  PS_FOLDER=ps_tdd128
  UAS_FOLDER=uas_tdd128
endif
endif

ifndef GSM_PS_SUPPORT
  GSM_PS_SUPPORT := TRUE
endif

ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
  ifeq ($(strip $(IOT_NO_CELLULAR)),TRUE)
    GSM_PS_SUPPORT := FALSE
  endif
endif

ifdef BT_PRODUCT_LINE
  ifeq ($(strip $(BT_PRODUCT_LINE)),BT_BOX)
    GSM_PS_SUPPORT := FALSE
  endif
  ifeq ($(strip $(BT_PRODUCT_LINE)),BT_DIALER_BTONLY)
    GSM_PS_SUPPORT := FALSE
  endif
endif

# *************************************************************************
# Components list
# *************************************************************************
ifeq ($(strip $(RTOS)),NUCLEUS)
COMPLIST       =  nucleus nucleus_int nucleus_ctrl_code nucleus_critical_data
endif

ifeq ($(strip $(RTOS)),NUCLEUS_V2)
COMPLIST       =  nucleus_v2 nucleus_v2_int nucleus_v2_ctrl_code nucleus_v2_critical_data
endif

ifeq ($(strip $(RTOS)),THREADX)
COMPLIST       =  threadx threadx_ctrl_code threadx_ctrl_data
endif

ifeq ($(strip $(RTOS_DEBUG)),TRUE)
  ifeq ($(strip $(RTOS)),NUCLEUS)
    COMPLIST    += nucleus_debug
  endif
  ifeq ($(strip $(RTOS)),NUCLEUS_V2)
    COMPLIST    += nucleus_v2_debug
  endif
  ifeq ($(strip $(RTOS)),THREADX)
    COMPLIST    += threadx_debug
  endif
endif

ifeq ($(strip $(L1S_BASIC)),TRUE)
  ifeq ($(call Upper,$(strip $(PROJECT))),BASIC)
    COMPLIST       += interface
  endif
  ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
  COMPLIST       += dummyps

    ifeq ($(strip $(NVRAM_SUPPORT)),TRUE)
      COMPLIST  += nvram nvram_sec 
    endif
    ifneq ($(strip $(L1_UMTS)),TRUE)
      ifeq ($(strip $(L1_GPRS)),TRUE)
        COMPLIST       += l1_classb_g2 l1_ext interface_classb       # GPRS classb
      else
        COMPLIST       += l1_g2 l1_ext interface                     # GSM only
      endif
    else
    endif
  endif

else

  # For PS team developers add component module here.
  ifneq ($(strip $(GSM_PS_SUPPORT)),TRUE)
    COMPLIST       += nvram nvram_sec l4misc 
  else
    COMPLIST       += nvram nvram_sec cc l4misc ciss sms data sim2
  endif
  ifeq ($(filter WM_MODEM ANDROID_MODEM,$(strip $(SMART_PHONE_CORE))),)
    ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
      COMPLIST       += ems
    endif
  endif  
endif

ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
   COM_DEFS += __MTK_3G_MRAT_ARCH__
endif

ifndef SMART_PHONE_CORE
  SMART_PHONE_CORE = NONE
endif

ifneq ($(filter NONE MD,$(SMART_PHONE_CORE)),)
  COMPLIST += fs
endif

COMPLIST       += init config kal \
                  custom bmt \
                  sst fdm \
                  mtkdebug

ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
ifneq ($(call Upper,$(strip $(PROJECT))),UDVT)
  ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
    COMPLIST += ft ftc cct audio
  else
    ifneq ($(filter WM_MODEM ANDROID_MODEM,$(strip $(SMART_PHONE_CORE))),)
      COMPLIST += ft ftc cct audio
    else
      COMPLIST += ft ftc cct audio
    endif
  endif
endif
endif

ifeq ($(call Upper,$(strip $(PROJECT))),UDVT)
  COMPLIST += meut
endif

ifndef AST_SUPPORT
  AST_SUPPORT = NONE
endif

ifneq ($(filter TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
  ifdef L1_TDD128
    ifeq ($(strip $(L1_TDD128)),TRUE)
      ifeq ($(strip $(L1_3GSOLUTION)),MTK_TL1_TDD)
        COMPLIST       += tl1 ll1      # DM (EGPRS + TD) or DM (GPRS + TD)
      endif

      ifeq ($(strip $(L1_3GSOLUTION)),AST_TL1_TDD)
        ifeq ($(strip $(AST_SUPPORT)),AST1001)
          COMPLIST       += ast_l1_ast1001 ll1    # DM (EGPRS + 3G) or DM (GPRS + 3G)
          COMPLIST       += fta
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST2001)
          COMPLIST       += ast_l1_ast2001 ll1     # DM (EGPRS + 3G) or DM (GPRS + 3G)
          COMPLIST       += fta
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST2001FPGA)
          COMPLIST       += ast_l1_ast2001 ll1    # DM (EGPRS + 3G) or DM (GPRS + 3G)
          COMPLIST       += fta
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST3001)
          COMPLIST       += ast_l1_ast3001 ll1     # DM (EGPRS + 3G) or DM (GPRS + 3G)
          COMPLIST       += fta
        endif
      endif 
    endif
  endif
endif

UL1_PLATFORM    = MT6268 MT6268A MT6268T
UL1_HS_PLATFORM = MT6268H MT6270A MT6276 MT6573 MT6575
ifneq ($(filter L1S UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
  ifdef L1_3GSOLUTION
    ifneq ($(strip $(L1_3GSOLUTION)),NONE)
      COMPLIST += ll1
    endif
  endif
  ifdef L1_WCDMA
    ifeq ($(strip $(L1_WCDMA)),TRUE)
      ifeq ($(strip $(L1_3GSOLUTION)),MTK_UL1_FDD)
        ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
          UMTS_FDD_PLATFORM = FALSE
          ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
            COMPLIST       += ul1_hs ul1_hs_ext       # DM (EGPRS + 3G) or DM (GPRS + 3G)
            COM_DEFS       +=   __UL1_HS_PLATFORM__ __UL1_FMO_LIMITATION__
            UMTS_FDD_PLATFORM = TRUE
          endif
          ifneq ($(filter $(strip $(PLATFORM)),$(UL1_PLATFORM)),)
            COMPLIST       += ul1 ul1_ext          # DM (EGPRS + 3G) or DM (GPRS + 3G)
            COM_DEFS       +=   __UL1_PLATFORM__
            UMTS_FDD_PLATFORM = TRUE
          endif
          ifneq ($(strip $(UMTS_FDD_PLATFORM)),TRUE)
            $(warning ERROR: PLATFORM $(strip $(PLATFORM)) is not vaild UMTS_FDD_MODE_SUPPORT platform.) 
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif

      ifeq ($(strip $(L1_3GSOLUTION)),MA_L1)
        COMPLIST       += lcl # DM (EGPRS + 3G) or DM (GPRS + 3G)
      endif
    endif
  endif
endif

ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
  COMPLIST       += l1_classb_g2 l1_ext interface_classb l4_classb mm_classb2 rr_classb2 ratcm ratdm asn1_re
  COMPLIST       += sndcp sm llc
else
  ifneq ($(filter NONE GSM,$(strip $(call Upper,$(PROJECT)))),)
    ifneq ($(strip $(GSM_PS_SUPPORT)),TRUE)
      COMPLIST       += l1_g2 l1_ext interface l4 asn1_re
    else
      COMPLIST       += l1_g2 l1_ext interface l4 mm2 rr2 ratcm asn1_re
    endif
  endif
endif

ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
  COMPLIST       += l1_classb_umts l1_ext interface_classb l4_classb mm_classb_umts rr_classb_umts ratcm ratdm asn1_re uas
  COMPLIST       += fsm sndcp sm llc
endif

ifeq ($(call Upper,$(strip $(PROJECT))),BASIC)
  COMPLIST += fsm
endif

ifeq ($(strip $(MCD_SUPPORT)),TRUE)
  ifeq ($(strip $(L1S_BASIC)),FALSE)
    COMPLIST += mcd
  endif
else
  ifneq ($(call Upper,$(strip $(PROJECT))),L1S)
    ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
      ifneq ($(call Upper,$(strip $(PROJECT))),UDVT)
        COMPLIST += peer_classb
      endif
    endif
  endif
endif

ifdef EMAIL_SUPPORT
  ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
      COMPLIST += email emlst
  endif
endif

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  COMPLIST  	+= plutommi gdi_arm mmiresource vendorapp
else
  ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
    COMPLIST  	+= venus gdi_arm mmiresource vendorapp
  else
    ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      ifneq ($(call Upper,$(strip $(PROJECT))),L1S)
        ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
          ifneq ($(call Upper,$(strip $(PROJECT))),UDVT)
            COMPLIST		+= mmi
          endif
        endif
      endif
    else
      ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
        COMPLIST  	+= lcmmi lcmtkapp lcmmiresource
      else
        ifeq ($(strip $(MMI_VERSION)),NEPTUNE_COLOR_MMI)
          COMPLIST  	+= lcmmi lcmtkapp lcmmiresource
        else
          ifeq ($(strip $(MMI_VERSION)),WISDOM_MMI)
            COMPLIST		+= mmi
          else
            ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
              COMPLIST  += plutommi mmiresource vendorapp
            else
              COMPLIST  += plutommi gdi_arm mmiresource
            endif
          endif
        endif
      endif
    endif
  endif
endif

ifeq ($(strip $(TST_SUPPORT)),TRUE)
   COMPLIST    += tst
endif

ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
  ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
    COMPLIST    += abm soc tcpip tcpip_wifi
  else
    ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
      COMPLIST    += abm soc tcpip tcpip_wifi
    else
      ifeq ($(call Upper,$(strip $(PROJECT))),GSM)
        COMPLIST    += abm soc tcpip tcpip_wifi
      endif
    endif
  endif
endif

ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
  ifneq ($(call Upper,$(strip $(PROJECT))),UDVT)
    COMPLIST    += irda ircomm obex
  else
    COMPLIST    += irda
  endif
endif


ifeq ($(strip $(USB_SUPPORT)),TRUE)
  COMPLIST    += usb
endif

ifdef DRM_SUPPORT
  ifneq ($(strip $(DRM_SUPPORT)),NONE)
     COMPLIST    	+= drm
  endif
endif

ifeq ($(strip $(XML_SUPPORT)),TRUE)
	COMPLIST    += xmlp
endif

ifneq ($(strip $(IMPS_SUPPORT)),FALSE)
       COMPLIST    += imps
endif

ifdef SDP_SUPPORT
  ifneq ($(strip $(SDP_SUPPORT)),FALSE)
     COMPLIST    	+= sdp
  endif   
endif

ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK)
			   COMPLIST          += btadp btprofiles btstack 
endif

ifdef DT_SUPPORT
  ifneq ($(strip $(DT_SUPPORT)),FALSE)
     COMPLIST    	+= dt
  endif   
endif

ifdef IPERF_SUPPORT
  ifneq ($(strip $(IPERF_SUPPORT)),NONE)
     COMPLIST    	+= iperf
  endif   
endif

ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifneq ($(strip $(call Upper,$(PROJECT))),UDVT)
      COMPLIST += event_info
    endif
  endif
endif

COMPLIST       += verno oriverno

# *************************************************************************
# Components Object Files
# *************************************************************************
COMPOBJS			=

ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
  ifdef L1_UMTS
    ifeq ($(strip $(L1_WCDMA)),TRUE)
      ifeq ($(strip $(L1_3GSOLUTION)),MA_L1)
        COMPOBJS = ma_l1c\ma_l1c.lib # DM (EGPRS + 3G) or DM (GPRS + 3G)
      endif
    endif
  endif
endif

# *************************************************************************
# L1 TMD Files
# *************************************************************************

ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
    L1_TMD_FILES = l1_dm\common\L1C_Trace.tmd \
                   l1_dm\common\L1C2_Trace.tmd \
                   l1_dm\common\l1i_cs_trace.tmd \
                   l1_dm\common\l1i_ps_trace.tmd \
                   l1_dm\common\L1SC_Trace.tmd \
                   l1_dm\common\L1C_CSD_Trace.tmd \
                   l1_dm\common\L1D_Trace.tmd \
                   l1_dm\common\L1D2_Trace.tmd \
                   l1_dm\common\L1D_EDGE_Trace.tmd \
                   l1_dm\common\L1i_EGPRS_Trace.tmd \
                   l1_dm\common\L1C_egprs_trace.tmd \
                   l1_dm\common\l1i_amr_trace.tmd \
                   l1_dm\common\l1t_amr_trace.tmd
endif

ifneq ($(filter NONE GSM,$(strip $(call Upper,$(PROJECT)))),)
    L1_TMD_FILES    =  l1_dm\common\L1C_Trace.tmd \
                       l1_dm\common\L1SC_Trace.tmd \
                       l1_dm\common\l1i_cs_trace.tmd \
                       l1_dm\common\L1D_Trace.tmd \
                       l1_dm\common\L1C_csd_trace.tmd \
                       l1_dm\common\L1D2_Trace.tmd \
                       l1_dm\common\l1i_amr_trace.tmd \
                       l1_dm\common\l1t_amr_trace.tmd 
endif
                     
ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
    L1_TMD_FILES  =  l1_dm\common\L1C_Trace.tmd \
                     l1_dm\common\L1SC_Trace.tmd \
                     l1_dm\common\l1i_cs_trace.tmd \
                     l1_dm\common\L1D_Trace.tmd \
                     l1_dm\common\L1C_csd_trace.tmd \
                     l1_dm\common\L1D2_Trace.tmd \
                     l1_dm\common\l1i_amr_trace.tmd \
                     l1_dm\common\l1t_amr_trace.tmd \
                     l1_dm\common\L1D_EDGE_Trace.tmd
                     
    ifeq ($(strip $(L1_GPRS)),TRUE)
      L1_TMD_FILES += l1_dm\common\l1i_ps_trace.tmd
      L1_TMD_FILES += l1_dm\common\l1c_egprs_trace.tmd \
                      l1_dm\common\l1i_egprs_trace.tmd \
                      l1_dm\common\L1C2_Trace.tmd
    endif  
    ifeq ($(strip $(L1_UMTS)),TRUE)
        L1_TMD_FILES  +=   l1_dm\common\L1D3_Trace.tmd
        ifeq ($(strip $(L1_WCDMA)),TRUE)
           ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
        ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
          L1_TMD_FILES += ul1_hs\common\ul1c_trace1.tmd \
                          ul1_hs\common\ul1c_trace3.tmd \
                          ul1_hs\common\ul1c_trace4.tmd \
                          ul1_hs\common\UL1D_MLT_Trace1.tmd \
                          ul1_hs\common\UL1D_MLT_Trace2.tmd \
                          ul1_hs\common\UL1D_Trace.tmd \
                          ul1_hs\common\UL1D_Trace1.tmd \
                          ul1_hs\common\UL1D_Trace2.tmd \
                          ul1_hs\common\UL1D_Trace3.tmd \
                          ul1_hs\common\UL1D_Trace4.tmd \
                          ul1_hs\common\UL1D_Trace5.tmd \
                          ul1_hs\common\UL1D_Trace6.tmd \
                          ul1_hs\common\UL1TST_Trace1.tmd \
                          ul1_hs\common\UL1D_HSPA_Trace.tmd \
                          ul1_hs\common\UL1D_HSPA_Trace1.tmd \
                          ul1_hs\common\UL1D_HSPA_Trace2.tmd
          L1_TMD_FILES += ul1_hs\common\ul1c_trace2.tmd
          L1_TMD_FILES += md_sm\common\ul1sm\UL1SM_Trace1.tmd
        else
          L1_TMD_FILES += ul1\common\ul1c_trace1.tmd \
                          ul1\common\ul1c_trace3.tmd \
                          ul1\common\ul1c_trace4.tmd \
                          ul1\common\UL1D_MLT_Trace1.tmd \
                          ul1\common\UL1D_MLT_Trace2.tmd \
                          ul1\common\UL1D_Trace.tmd \
                          ul1\common\UL1D_Trace1.tmd \
                          ul1\common\UL1D_Trace2.tmd \
                          ul1\common\UL1D_Trace3.tmd \
                          ul1\common\UL1D_Trace4.tmd \
                          ul1\common\UL1D_Trace5.tmd \
                          ul1\common\UL1TST_Trace1.tmd
          L1_TMD_FILES += ul1\common\ul1c_trace2.tmd
          L1_TMD_FILES += md_sm\common\ul1sm\UL1SM_Trace1.tmd
             endif
           endif
        endif
        ifeq ($(strip $(L1_GPRS)),TRUE)
            L1_TMD_FILES  +=   l1_dm\common\l1dm_trace.tmd
        endif
    endif
endif

ifeq ($(strip $(L1_UMTS)),TRUE)
    L1_TMD_FILES  = l1_dm\common\L1C_Trace.tmd \
                    l1_dm\common\L1C2_Trace.tmd \
                    l1_dm\common\l1i_cs_trace.tmd \
                    l1_dm\common\l1i_ps_trace.tmd \
                    l1_dm\common\L1SC_Trace.tmd \
                    l1_dm\common\L1C_CSD_Trace.tmd \
                    l1_dm\common\L1D_Trace.tmd \
                    l1_dm\common\L1D2_Trace.tmd \
                    l1_dm\common\L1D_EDGE_Trace.tmd \
                    l1_dm\common\L1i_EGPRS_Trace.tmd \
                    l1_dm\common\L1C_egprs_trace.tmd \
                    l1_dm\common\l1i_amr_trace.tmd \
                    l1_dm\common\l1t_amr_trace.tmd \
                    l1_dm\common\l1dm_trace.tmd
 ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
    ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
      L1_TMD_FILES += ul1_hs\common\UL1D_MLT_Trace1.tmd \
                      ul1_hs\common\UL1D_MLT_Trace2.tmd \
                      ul1_hs\common\UL1D_Trace.tmd \
                      ul1_hs\common\UL1D_Trace1.tmd \
                      ul1_hs\common\UL1D_Trace2.tmd \
                      ul1_hs\common\UL1D_Trace3.tmd \
                      ul1_hs\common\UL1D_Trace4.tmd \
                      ul1_hs\common\UL1D_Trace5.tmd \
                      ul1_hs\common\UL1D_Trace6.tmd \
                      ul1_hs\common\ul1c_trace1.tmd \
                      ul1_hs\common\ul1c_trace3.tmd \
                      ul1_hs\common\ul1c_trace4.tmd \
                      ul1_hs\common\UL1TST_Trace1.tmd \
                      ul1_hs\common\UL1D_HSPA_Trace.tmd \
                      ul1_hs\common\UL1D_HSPA_Trace1.tmd \
                      ul1_hs\common\UL1D_HSPA_Trace2.tmd
      L1_TMD_FILES += ul1_hs\common\ul1c_trace2.tmd
      L1_TMD_FILES += md_sm\common\ul1sm\UL1SM_Trace1.tmd
    else
      L1_TMD_FILES += ul1\common\UL1D_MLT_Trace1.tmd \
                      ul1\common\UL1D_MLT_Trace2.tmd \
                      ul1\common\UL1D_Trace.tmd \
                      ul1\common\UL1D_Trace1.tmd \
                      ul1\common\UL1D_Trace2.tmd \
                      ul1\common\UL1D_Trace3.tmd \
                      ul1\common\UL1D_Trace4.tmd \
                      ul1\common\UL1D_Trace5.tmd \
                      ul1\common\ul1c_trace1.tmd \
                      ul1\common\ul1c_trace3.tmd \
                      ul1\common\ul1c_trace4.tmd \
                      ul1\common\UL1TST_Trace1.tmd
      L1_TMD_FILES += ul1\common\ul1c_trace2.tmd
      L1_TMD_FILES += md_sm\common\ul1sm\UL1SM_Trace1.tmd
    endif
  endif
endif

ifneq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  ifdef SMART_PHONE_CORE
    ifeq ($(strip $(SMART_PHONE_CORE)),NONE)
      L1_TMD_FILES  += hal\audio\src\v1\l1audio_trace.tmd
    endif
  else
    L1_TMD_FILES  += hal\audio\src\v1\l1audio_trace.tmd
  endif
endif

# *************************************************************************
# Component trace definition header files
# *************************************************************************
ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
  COMP_TRACE_DEFS   =  tst\local_inc\tst_trace.h
endif
ifneq ($(call Upper,$(strip $(PROJECT))),UDVT)
  COMP_TRACE_DEFS   =  tst\local_inc\tst_trace.h
endif

ifeq ($(strip $(L1S_BASIC)),TRUE)
  ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
    COMP_TRACE_DEFS += dummyps\include\internal\dps_trc.h \
                       hal\peripheral\inc\bmt_trc.h \
                       $(strip $(PS_FOLDER))\sim2\include\sim_trc.h

  endif

  COMP_TRACE_DEFS += l1_dm\common\l1a_trace.h

  ifeq ($(strip $(L1_WCDMA)),TRUE)
    ifneq ($(call Upper,$(strip $(PROJECT))),UDVT)
      COMP_TRACE_DEFS  += dummyups\include\internal\udps_trc.h
    endif
  endif
    
  ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
    ifeq ($(strip $(NVRAM_SUPPORT)),TRUE)
      COMP_TRACE_DEFS  += nvram\include\nvram_trc.h
    endif
  endif
  
  ifeq ($(strip $(L1_GPRS)),TRUE)
    ifeq ($(strip $(L1_WCDMA)),TRUE)
      ifeq ($(strip $(L1_3GSOLUTION)),MA_L1)
        COMP_TRACE_DEFS  += $(strip $(UAS_FOLDER))\lcl\include\lcl_trc.h
      else
        ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
          COMP_TRACE_DEFS  += ul1_hs\common\ul1a_trc.h
        else
          COMP_TRACE_DEFS  += ul1\common\ul1a_trc.h
        endif
      endif
    endif
  endif
  
  ifeq ($(call Upper,$(strip $(PROJECT))),UDVT)
    
      COMP_TRACE_DEFS   += $(strip $(PS_FOLDER))\sim2\include\sim_trc.h    
    COMP_TRACE_DEFS += hal\peripheral\inc\bmt_trc.h
  endif

else

  ifneq ($(strip $(L1_UMTS)),TRUE)
    COMP_TRACE_DEFS  +=  l1_dm\common\l1a_trace.h \
                         $(strip $(PS_FOLDER))\mm2\common\include\mm_trc.h \
                         $(strip $(PS_FOLDER))\rr2\common\include\rr_trc.h \
                         $(strip $(PS_FOLDER))\rr2\lapdm\include\lapdm_trc.h \
                         $(strip $(PS_FOLDER))\rr2\rlc\include\rlc_trc.h \
                         $(strip $(PS_FOLDER))\rr2\mac\include\mac_trc.h \
                         $(strip $(PS_FOLDER))\ratcm\include\ratcm_trc.h \
                         $(strip $(PS_FOLDER))\ratdm\include\ratdm_trc.h
    ifdef GEMINI
      ifneq ($(strip $(GEMINI)),FALSE)
        COMP_TRACE_DEFS += rsva\rsvas\include\rsvas_trc.h
      endif
    endif
  else
    ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
      COMP_TRACE_DEFS  +=  l1_dm\common\l1a_trace.h \
                           $(strip $(PS_FOLDER))\mm2\common\include\mm_trc.h \
                           $(strip $(PS_FOLDER))\rr2\common\include\rr_trc.h \
                           $(strip $(PS_FOLDER))\rr2\lapdm\include\lapdm_trc.h \
                           $(strip $(PS_FOLDER))\rr2\rlc\include\rlc_trc.h \
                           $(strip $(PS_FOLDER))\rr2\mac\include\mac_trc.h \
                           $(strip $(PS_FOLDER))\ratcm\include\ratcm_trc.h \
                           $(strip $(PS_FOLDER))\ratdm\include\ratdm_trc.h
    else
      COMP_TRACE_DEFS  +=  l1_dm\common\l1a_trace.h \
                           $(strip $(PS_FOLDER))\mm\common\include\mm_trc.h \
                           $(strip $(PS_FOLDER))\rr\include\rr_trc.h \
                           $(strip $(PS_FOLDER))\rr\lapdm\include\lapdm_trc.h \
                           $(strip $(PS_FOLDER))\rr\rlc\include\rlc_trc.h \
                           $(strip $(PS_FOLDER))\rr\mac\include\mac_trc.h \
                           $(strip $(PS_FOLDER))\rr\rrm\include\rrm_trc.h
    endif
  endif

 
    COMP_TRACE_DEFS   += $(strip $(PS_FOLDER))\sim2\include\sim_trc.h
  COMP_TRACE_DEFS   += nvram\include\nvram_trc.h \
                       $(strip $(PS_FOLDER))\l4\smsal\include\smsal_trc.h \
                       $(strip $(PS_FOLDER))\l4\phb\include\phb_trc.h \
                       $(strip $(PS_FOLDER))\l4\smu\include\smu_trc.h \
                       $(strip $(PS_FOLDER))\cc-ss\ss\include\ciss_trc.h \
                       $(strip $(PS_FOLDER))\cc-ss\cc\include\cc_trc.h \
                       $(strip $(PS_FOLDER))\l4\csm\csm_trc.h \
                       $(strip $(PS_FOLDER))\l4\include\l4_trc.h \
                       $(strip $(PS_FOLDER))\sms\include\sms_trc.h \
                       $(strip $(PS_FOLDER))\l4\uem\include\uem_trc.h \
                       $(strip $(PS_FOLDER))\l4\rac\include\rac_trc.h \
                       $(strip $(PS_FOLDER))\l4\tcm\include\tcm_trc.h \
                       $(strip $(PS_FOLDER))\$(strip $(PPP_FOLDER))\include\ppp_trc.h \
                       media\common\include\med_trc.h \
                       $(strip $(PS_FOLDER))\data\l2r\include\l2r_trc.h \
                       $(strip $(PS_FOLDER))\data\tdt\include\tdt_trc.h \
                       $(strip $(PS_FOLDER))\data\rlp\include\rlp_trc.h \
                       $(strip $(PS_FOLDER))\data\t30\include\t30_trc.h \
                       $(strip $(PS_FOLDER))\data\fa\include\fa_trc.h \
                       inet_ps\abm\include\abm_trc.h \
                       inet_ps\soc\include\soc_trc.h \
                       inet_ps\tcpip\include\tcpip_trc.h \
                       hal\peripheral\inc\bmt_trc.h

  ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
    COMP_TRACE_DEFS += $(strip $(PS_FOLDER))\llc\include\llc_trc.h \
                       $(strip $(PS_FOLDER))\sndcp\include\snd_trc.h \
                       $(strip $(PS_FOLDER))\sm\include\sm_trc.h
  else
    ifneq ($(filter UMTS HSPA  TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
      COMP_TRACE_DEFS += $(strip $(PS_FOLDER))\llc\include\llc_trc.h \
                         $(strip $(PS_FOLDER))\sndcp\include\snd_trc.h \
                         $(strip $(PS_FOLDER))\sm\include\sm_trc.h \
                         $(strip $(UAS_FOLDER))\l2\bmc\include\bmc_trc.h \
                         $(strip $(UAS_FOLDER))\l2\common\include\ul2_trc.h \
                         $(strip $(UAS_FOLDER))\l2\csr\include\csr_trc.h \
                         $(strip $(UAS_FOLDER))\l2\pdcp\include\pdcp_trc.h \
                         $(strip $(UAS_FOLDER))\l2\rabm\include\rabm_trc.h \
                         $(strip $(UAS_FOLDER))\l2\umac\include\umac_trc.h \
                         $(strip $(UAS_FOLDER))\l2\urlc\include\urlc_trc.h \
                         $(strip $(UAS_FOLDER))\urr\common\include\adr_trc.h \
                         $(strip $(UAS_FOLDER))\urr\cise\include\csce_trc.h \
                         $(strip $(UAS_FOLDER))\urr\cise\include\cse_trc.h \
                         $(strip $(UAS_FOLDER))\urr\cise\include\sibe_trc.h \
                         $(strip $(UAS_FOLDER))\urr\cise\include\usime_trc.h \
                         $(strip $(UAS_FOLDER))\urr\common\include\urr_trc.h \
                         $(strip $(UAS_FOLDER))\urr\dbme\include\dbme_trc.h \
                         $(strip $(UAS_FOLDER))\urr\meme\include\meme_trc.h \
                         $(strip $(UAS_FOLDER))\urr\rrce\include\rrce_trc.h \
                         $(strip $(UAS_FOLDER))\urr\slce\include\slce_trc.h

      ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
        ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
          COMP_TRACE_DEFS += ul1_hs\common\ul1a_trc.h
        else
          COMP_TRACE_DEFS += ul1\common\ul1a_trc.h
        endif
      endif

      ifdef GEMINI
        ifneq ($(strip $(GEMINI)),FALSE)
          COMP_TRACE_DEFS += rsva\rsvas\include\rsvas_trc.h \
                             rsva\rsvak\include\rsvak_trc.h \
                             rsva\rsvau\include\rsvau_trc.h \
                             rsva\rsvag\include\rsvag_trc.h
        endif
      endif
    else
      ifeq ($(call Upper,$(strip $(PROJECT))),GSM)
      endif
    endif
  endif

endif

COMP_TRACE_DEFS += sst\include\ex_trc.h

COMP_TRACE_DEFS += sst\include\sst_trc.h

COMP_TRACE_DEFS += $(strip $(PS_FOLDER))\l4\include\atci_trc.h

ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
  ifneq ($(call Upper,$(strip $(PROJECT))),UDVT)
    COMP_TRACE_DEFS   += $(strip $(PS_FOLDER))\ircomm\include\ircomm_trc.h \
                         $(strip $(PS_FOLDER))\obex\include\obex_trc.h \
                         irda\inc\irda_trace.h
  else
    COMP_TRACE_DEFS   += irda\inc\irda_trace.h
  endif
endif

ifeq ($(strip $(USB_SUPPORT)),TRUE)
        COMP_TRACE_DEFS	+= usb\include\usb_trc.h
endif

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  COMP_TRACE_DEFS += plutommi\mmi\inc\MMI_trc.h
else
  ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
    COMP_TRACE_DEFS += plutommi\mmi\inc\MMI_trc.h
  else
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      COMP_TRACE_DEFS += lcmmi\mmi\inc\MMI_trc.h \
                         lcmmi\mmi\inc\MMI_fw_trc.h \
                         lcmmi\mmi\inc\MMI_common_app_trc.h \
                         lcmmi\mmi\inc\MMI_media_app_trc.h
    else
      ifeq ($(strip $(MMI_VERSION)),NEPTUNE_COLOR_MMI)
        COMP_TRACE_DEFS += lcmmi\mmi\inc\MMI_trc.h \
                           lcmmi\mmi\inc\MMI_fw_trc.h \
                           lcmmi\mmi\inc\MMI_common_app_trc.h \
                           lcmmi\mmi\inc\MMI_media_app_trc.h
      else
        ifeq ($(strip $(MMI_VERSION)),WISDOM_MMI)
          COMP_TRACE_DEFS += external_mmi\wise\bal\common\include\ws_trc.h \
                             external_mmi\wise\bal\common\include\ws_ps_trc.h 
        else
          ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
            COMP_TRACE_DEFS += plutommi\mmi\inc\MMI_trc.h
          endif
        endif
      endif
    endif
  endif
endif

ifneq ($(strip $(IMPS_SUPPORT)),FALSE)
  COMP_TRACE_DEFS	+= inet_ps\imps\include\imps_trc.h
endif

ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifneq ($(strip $(call Upper,$(PROJECT))),UDVT)
      COMP_TRACE_DEFS += interface\event_info\event_info_trc.h
    endif
  endif
endif

# *************************************************************************
# Common include path
# *************************************************************************
CUSTOM_COMMINC    =  init\include kal\stacklib\include kal\adaptation\include \
                     sst\include inc \
                     interface\hwdrv interface\os interface\hal\audio interface\fota \
                     tst\include \
                     dummyps\include\sap \
                     l1_dm\l1d_ext \
                     interface\middleware \
                     interface\nvram \
                     interface\hal\L1 \
                     interface\hal\sleep_drv \
                     interface\fs \
                     interface\hal\camera \
                     interface\hal\postproc \
                     hal\camera\cal\inc \
                     hal\mdp\include \
                     interface\hal\mdp \
                     interface\hal\mm_comm \
                     hal\connectivity\usb_driver\inc \
                     hal\connectivity\usb_driver\src \
                     interface\hal\connectivity\usb_driver \
                     hal\mm_comm\inc \
                     interface\hal\storage \
                     interface\ps\enum \
                     interface\ps\include \
                     interface\ps\local_inc \
                     interface\ps\sap \
                     $(strip $(PS_FOLDER))\interfaces\sap \
                     interface\hal\drv_sw_def \
                     hal\drv_def \
                     hal\camera\isp\inc \
                     custom\drv\Camera_common \
                     hal\camera\mdp_cam_if\inc \
                     hal\graphics\jpeg\exif\inc \
                     interface\hal\display\ddv1 \
                     interface\hal\system \
                     hal\system\bootloader\inc \
                     hal\system\cirq\inc \
                     hal\system\counter\inc \
                     hal\system\dcm\inc \
                     hal\system\dma\inc \
                     hal\system\emi\inc \
                     hal\system\fota\inc \
                     hal\system\init\inc \
                     hal\system\ipc\inc \
                     hal\system\pdn\inc \
                     hal\system\pll\inc \
                     hal\system\regbase\inc \
                     hal\storage\flash\fdm\inc \
                     hal\cipher\include \
                     hal\connectivity\usb_driver\inc \
                     hal\storage\flash\mtd\inc \
                     $(strip $(PS_FOLDER))\l4\csm\ss\asn1\gen\include \
                     drv\include \
                     interface\fota \
                     interface\l1interface\external \
                     interface\l1interface\internal \
                     interface\l1interface\sap

ifneq ($(strip $(L1_UMTS)),TRUE)
  CUSTOM_COMMINC += asn1_re\include
else
  ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA L1S,$(strip $(call Upper,$(PROJECT)))),)
    CUSTOM_COMMINC += asn1_re\include \
                      $(strip $(UAS_FOLDER))\interfaces\sap

    ifeq ($(strip $(L1_WCDMA)),TRUE)
      CUSTOM_COMMINC += interface\ul1interface\external interface\ul1interface\sap
    endif
  endif
endif

ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
  CUSTOM_COMMINC += tst\database_classb\pstrace_db

else
  ifeq ($(strip $(L1_UMTS)),TRUE)
    ifeq ($(strip $(L1S_BASIC)),TRUE)
      CUSTOM_COMMINC += tst\database\pstrace_db
    else
      CUSTOM_COMMINC += tst\database_classb_umts\pstrace_db
    endif
    

    ifeq ($(strip $(L1_TDD128)),TRUE)
      CUSTOM_COMMINC += interface\tl1interface
    endif

    ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
      CUSTOM_COMMINC += dummyups\include\sap
      ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
         CUSTOM_COMMINC += interface\ul1interface\external interface\ul1interface\sap
      endif
    endif
    
  else
    ifneq ($(filter NONE GSM,$(strip $(call Upper,$(PROJECT)))),)
      CUSTOM_COMMINC += tst\database\pstrace_db
    else
      ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
        CUSTOM_COMMINC += dummyups\include\sap
        ifeq ($(strip $(L1_WCDMA)),TRUE)
          ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
            CUSTOM_COMMINC += interface\ul1interface\external interface\ul1interface\sap 
            ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
              CUSTOM_COMMINC += ul1_hs\ul1d_ext
            else
              CUSTOM_COMMINC += ul1\ul1d_ext
            endif
          endif
        else
          ifeq ($(strip $(L1_TDD128)),TRUE)
            CUSTOM_COMMINC += l1_dm\l1d_ext
            CUSTOM_COMMINC += tl1\common \
                              tl1\tl1d \
                              interface\tl1interface
          else
            CUSTOM_COMMINC += ul1\ul1d_ext
          endif
        endif
        CUSTOM_COMMINC += tst\database\pstrace_db
      else
        ifeq ($(call Upper,$(strip $(PROJECT))),UDVT)
          CUSTOM_COMMINC += tst\database\pstrace_db
        endif
      endif
    endif
  endif
endif

ifeq ($(strip $(L1_UMTS)),TRUE)
  ifdef L1_WCDMA
    ifeq ($(strip $(L1_WCDMA)),TRUE)
      ifeq ($(strip $(L1_3GSOLUTION)),MA_L1)
        CUSTOM_COMMINC  += $(strip $(UAS_FOLDER))\lcl\include
      else
        ifeq ($(strip $(L1_3GSOLUTION)),MTK_UL1_FDD)
          CUSTOM_COMMINC  += drv\include
        endif
      endif
    endif
  endif

  ifdef L1_TDD128
    ifeq ($(strip $(L1_TDD128)),TRUE)
      ifeq ($(strip $(L1_3GSOLUTION)),AST_TL1_TDD)
        CUSTOM_COMMINC  += ast_l1\include
      else
        ifeq ($(strip $(L1_3GSOLUTION)),MTK_TL1_TDD)
          CUSTOM_COMMINC  += drv\include
        endif
      endif
    endif
  endif
endif


CUSTOM_COMMINC    += $(strip $(PS_FOLDER))\interfaces\include \
                     $(strip $(PS_FOLDER))\interfaces\enum \
                     $(strip $(PS_FOLDER))\interfaces\local_inc \
                     interface\ps \
                     interface\mmi \
                     $(strip $(PS_FOLDER))\l4\include \
                     $(strip $(PS_FOLDER))\l4\atci\include \
                     $(strip $(PS_FOLDER))\l4\l4c\include\common \
                     $(strip $(PS_FOLDER))\l4\l4c\include\proc \
                     $(strip $(PS_FOLDER))\l4\csm\cc\include \
                     $(strip $(PS_FOLDER))\l4\uem\include \
                     $(strip $(PS_FOLDER))\l4\phb\include \
                     $(strip $(PS_FOLDER))\l4\csm\cc\include \
                     $(strip $(PS_FOLDER))\l4\csm \
                     $(strip $(PS_FOLDER))\l4\smsal\include \
                     $(strip $(PS_FOLDER))\l4\tcm\include \
                     media\common\include \
                     media\audio\include \
                     media\bitstream\include \
                     media\video\include \
                     media\camera\include \
                     media\image\include \
                     media\metatag\include \
                     fs\common\include \
                     fs\fat\include \
                     $(strip $(PS_FOLDER))\interfaces\mcd\include \
                     inet_ps\abm\include \
                     inet_ps\soc\include \
                     mmi\include \
                     fmt\include \
                     interface\fs \
                     interface\media \
                     interface\media\hal \
                     interface\common \
                     inet_ps\interfaces\enum


CUSTOM_COMMINC    +=  custom\l1_rf\$(RF_MODULE)

CUSTOM_COMMINC    +=  config\include\hal \
                      config\include\app

ifeq ($(strip $(L1_WCDMA)),TRUE)
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT) 
    CUSTOM_COMMINC += custom\ul1_rf\$(UMTS_RF_MODULE)
  endif
  ifeq ($(call Upper,$(strip $(PROJECT))),BASIC)
#    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT) 
      CUSTOM_COMMINC += interface\ul1interface\external interface\ul1interface\sap
#    endif
  endif
  ifeq ($(call Upper,$(strip $(PROJECT))),UDVT)
    CUSTOM_COMMINC += interface\ul1interface\external interface\ul1interface\sap
  endif
endif

ifeq ($(strip $(L1_TDD128)),TRUE)
  CUSTOM_COMMINC += custom\tl1_rf\$(UMTS_TDD128_RF_MODULE)
  ifeq ($(call Upper,$(strip $(PROJECT))),BASIC)
    CUSTOM_COMMINC += interface\tl1interface
  endif
endif

CUSTOM_COMMINC    +=  custom\drv\LCD\$(LCD_MODULE) \
                      custom\app\$(BOARD_VER) \
                      custom\ps\$(BOARD_VER) \
                      custom\system\$(BOARD_VER) \
                      custom\common \
                      custom\common\hal \
                      custom\common\ps \
                      custom\common\hal\nvram \
                      custom\common\hal_public

ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
   CUSTOM_COMMINC   +=  lcmmi\mmi\Inc
else
   CUSTOM_COMMINC   +=  plutommi\mmi\Inc plutommi\Framework\Interface
endif

ifneq ($(strip $(IMPS_SUPPORT)),FALSE)
  CUSTOM_COMMINC  +=	inet_ps\imps\include
endif


ifneq ($(strip $(SDP_SUPPORT)),FALSE)  
  CUSTOM_COMMINC += inet_ps\sdp\include
endif

ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifneq ($(strip $(call Upper,$(PROJECT))),UDVT)
      CUSTOM_COMMINC += tst\include interface\event_info
    endif
  endif
endif

ifdef AGPS_SUPPORT
    ifeq ($(strip $(AGPS_SUPPORT)), CONTROL_PLANE)
      CUSTOM_COMMINC    +=  ulcs\interfaces\sap
    endif
    
    ifeq ($(strip $(AGPS_SUPPORT)), BOTH)
      CUSTOM_COMMINC    +=  ulcs\interfaces\sap
    endif
endif

# *************************************************************************
# Common preprocessor definitions
# *************************************************************************
#ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
ifeq ($(strip $(L1S_BASIC)),TRUE)
CUSTOM_OPTION    +=  __L1_STANDALONE__ __CS_SERVICE__

ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
CUSTOM_OPTION    +=  DUMMY_PROTOCOL __FS_ON__ __MULTI_BOOT__
endif

ifeq ($(call Upper,$(strip $(PROJECT))),BASIC)
CUSTOM_OPTION    +=  L1_NOT_PRESENT NVRAM_NOT_PRESENT __MAUI_BASIC__
  ifneq ($(strip $(IC_TEST_TYPE)),IC_BURNIN_TEST)
    CUSTOM_OPTION     += MTK_SYSSERV_DEBUG 
  endif
  
  ifeq ($(strip $(IC_TEST_TYPE)),IC_MODULE_TEST)
    CUSTOM_OPTION += IC_MODULE_TEST
    CUSTOM_OPTION += DEVDRV_TEST
  endif

  ifeq ($(strip $(IC_TEST_TYPE)),IC_BURNIN_TEST)
    CUSTOM_OPTION    +=  IC_BURNIN_TEST
    CUSTOM_OPTION += DEVDRV_TEST
  endif

endif

ifeq ($(call Upper,$(strip $(PROJECT))),UDVT)
CUSTOM_OPTION    +=  L1_NOT_PRESENT __MEUT__ NVRAM_NOT_PRESENT __MAUI_BASIC__
CUSTOM_OPTION    +=  __UDVT__
endif

CUSTOM_OPTION    += L4_NOT_PRESENT MM_NOT_PRESENT CC_NOT_PRESENT CISS_NOT_PRESENT \
                    SMS_NOT_PRESENT SIM_NOT_PRESENT RR_NOT_PRESENT \
                    MMI_NOT_PRESENT SNDCP_NOT_PRESENT SM_NOT_PRESENT REASM_NOT_PRESENT \
                    LLC_NOT_PRESENT DATA_NOT_PRESENT PPP_NOT_PRESENT MED_NOT_PRESENT \
                    WAP_NOT_PRESENT ABM_NOT_PRESENT SOC_NOT_PRESENT TCPIP_NOT_PRESENT \
                    __18V_30V_ME__ MED_V_NOT_PRESENT

ifdef L1_UMTS
  ifeq ($(strip $(L1_UMTS)),TRUE)
    CUSTOM_OPTION    += RATCM_NOT_PRESENT RATDM_NOT_PRESENT UL2D_NOT_PRESENT UL2_NOT_PRESENT URR_NOT_PRESENT
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      CUSTOM_OPTION    += __UL1_STANDALONE__
    endif
  endif
endif

ifeq ($(call Upper,$(strip $(PROJECT))),L1S) 
  ifeq ($(strip $(NVRAM_SUPPORT)),TRUE)
    CUSTOM_OPTION  += __MOD_NVRAM__
  else
    CUSTOM_OPTION  += NVRAM_NOT_PRESENT
  endif
  
  ifeq ($(strip $(L1_GPRS)),TRUE)
    ifeq ($(strip $(PLATFORM)),MT6205B)
      $(error: MT6205B not support GPRS)
    endif

    CUSTOM_OPTION    +=  __PS_SERVICE__
  endif
  
  ifeq ($(strip $(L1_EGPRS)),TRUE)
  
    CUSTOM_OPTION    += __EGPRS_MODE__

    ifeq ($(strip $(L1_EPSK_TX)),TRUE)
      CUSTOM_OPTION    +=  __EPSK_TX__
    endif   
  endif
  
  ifeq ($(strip $(L1D_LOOPBACK)),1)
    COMPLIST         +=  l1d_lp1
    L1_TMD_FILES     +=  l1_dm\common\L1DLP_Trace.tmd
    ifneq ($(strip $(L1_UMTS)),TRUE)
      CUSTOM_COMMINC   +=  l1_dm\l1d_lp1
    endif
    CUSTOM_OPTION    +=  L1D_TEST
  endif

  ifeq ($(strip $(L1D_LOOPBACK)),2)
    COMPLIST         +=  l1d_lp2
    L1_TMD_FILES     +=  l1_dm\common\L1DLP_Trace.tmd
    ifneq ($(strip $(L1_UMTS)),TRUE)
      CUSTOM_COMMINC   +=  l1_dm\l1d_lp2
    endif
    CUSTOM_OPTION    +=  L1D_TEST
  endif

  ifeq ($(strip $(L1D_LOOPBACK)),3)
    COMPLIST         +=  l1d_lp3
    L1_TMD_FILES     +=  l1_dm\common\L1DLP3_Trace.tmd
    ifneq ($(strip $(L1_UMTS)),TRUE)
      CUSTOM_COMMINC   +=  l1_dm\l1d_lp3
    endif
    CUSTOM_OPTION    +=  L1D_TEST
  endif

  ifeq ($(strip $(L1D_LOOPBACK)),5)
     COMPLIST         +=  l1d_lp5
     L1_TMD_FILES     +=  l1_dm\common\L1DLP5_Trace.tmd
     CUSTOM_COMMINC   +=  l1_dm\l1d_lp5
     CUSTOM_OPTION    +=  L1D_TEST
  endif

  ifeq ($(strip $(L1D_LOOPBACK)),6)
     COMPLIST         +=  l1d_lp6
     L1_TMD_FILES     +=  l1_dm\common\L1DLP6_Trace.tmd
     CUSTOM_COMMINC   +=  l1_dm\l1d_lp6
     CUSTOM_OPTION    +=  L1D_TEST
  endif

  ifeq ($(strip $(L1D_LOOPBACK)),7)
     COMPLIST         +=  l1d_lp7
     L1_TMD_FILES     +=  l1_dm\common\L1DLP7_Trace.tmd
     CUSTOM_COMMINC   +=  l1_dm\l1d_lp7
     CUSTOM_OPTION    +=  L1D_TEST
  endif
  
  ifeq ($(strip $(L1D_LOOPBACK)),8)
     COMPLIST         +=  l1d_lp8
     L1_TMD_FILES     +=  l1_dm\common\L1DLP8_Trace.tmd
     CUSTOM_COMMINC   +=  l1_dm\l1d_lp8
     CUSTOM_OPTION    +=  L1D_TEST
  endif

  ifeq ($(strip $(L1D_COSIM)),TRUE)
    CUSTOM_OPTION    +=  L1D_TEST_COSIM
  endif

  ifeq ($(strip $(ISP_SUPPORT)),TRUE)
    CUSTOM_OPTION    += ISP_SUPPORT
  endif
endif

else


  CUSTOM_OPTION    += __MOD_L4C__ __MOD_UEM__ __MOD_NVRAM__  \
                     __EM_MODE__ __CPHS__ __MULTI_BOOT__ __FS_ON__ \
                     __18V_30V_ME__  __PHB_COMPARE_NUMBER_9_DIGIT__

  ifeq ($(strip $(GSM_PS_SUPPORT)),TRUE)
    CUSTOM_OPTION    +=  __MOD_CC__  __MOD_PHB__  __MOD_CSM__  \
                         __MOD_SMSAL__ __MOD_RAC__  __MOD_SIM__ __SAT__ __MOD_SMU__\
                         __MOD_CISS__ __MOD_SMS__ __MOD_MM__
  endif
endif


ifneq ($(strip $(GSM_PS_SUPPORT)),TRUE)
  CUSTOM_OPTION    += CC_NOT_PRESENT SIM_NOT_PRESENT \
                      CISS_NOT_PRESENT SMS_NOT_PRESENT \
                      DATA_NOT_PRESENT MM_NOT_PRESENT \
                      RATCM_NOT_PRESENT RR_NOT_PRESENT \
                      TELEPHONY_APP_NOT_PRESENT
endif

ifneq ($(strip $(L1_UMTS)),TRUE)
  ifeq ($(call Upper,$(strip $(PROJECT))),NONE)
    CUSTOM_OPTION += RATDM_NOT_PRESENT
  endif
  ifeq ($(call Upper,$(strip $(PROJECT))),GSM)
    CUSTOM_OPTION += RATDM_NOT_PRESENT
  endif
  ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
    CUSTOM_OPTION += RATDM_NOT_PRESENT RATCM_NOT_PRESENT
  endif
  ifeq ($(call Upper,$(strip $(PROJECT))),BASIC)
    CUSTOM_OPTION += RATDM_NOT_PRESENT RATCM_NOT_PRESENT
  endif
  ifeq ($(call Upper,$(strip $(PROJECT))),UDVT)
    CUSTOM_OPTION += RATDM_NOT_PRESENT RATCM_NOT_PRESENT
  endif
  CUSTOM_OPTION += __MTK_3G_MRAT_ARCH__ __GSM_RAT__
endif

ifneq ($(strip $(L1_UMTS)),TRUE)
  ifneq ($(strip $(CENTRALIZED_SLEEP_MANAGER)),TRUE)
    CUSTOM_OPTION += __NEW_OS_TICK__	
  endif
endif


ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
  CUSTOM_OPTION     += FMT_NOT_PRESENT
endif

ifneq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  CUSTOM_OPTION += __FLIGHT_MODE_SUPPORT__
endif

ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
  CUSTOM_OPTION += __CS_SERVICE__ __PS_SERVICE__ __MOD_TCM__
else
  ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
    CUSTOM_OPTION += __CS_SERVICE__ __PS_SERVICE__ __MOD_TCM__
  else
    ifneq ($(filter NONE GSM,$(strip $(call Upper,$(PROJECT)))),)
      CUSTOM_OPTION += __CS_SERVICE__ \
                       SNDCP_NOT_PRESENT SM_NOT_PRESENT REASM_NOT_PRESENT \
                       LLC_NOT_PRESENT
    endif
  endif
endif

ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
  CUSTOM_OPTION += __GSM_RAT__
endif

ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
  ifneq ($(call Upper,$(strip $(PROJECT))),UDVT)
    ifdef L1_WCDMA
      ifeq ($(strip $(L1_WCDMA)),TRUE)
        CUSTOM_OPTION    +=  __UMTS_RAT__ __MTK_3G_MRAT_ARCH__
        ifneq ($(strip $(L1_3GSOLUTION)),MA_L1)
          CUSTOM_OPTION  += MAL1_NOT_PRESENT __MTK_UL1_FDD__
        else
          CUSTOM_OPTION  += __MA_L1__  
        endif
      endif
    endif
    ifdef L1_TDD128
      ifeq ($(strip $(L1_TDD128)),TRUE)
        CUSTOM_OPTION    +=  __UMTS_RAT__ __MTK_3G_MRAT_ARCH__ __TDD_DM_GAP_OPTIMIZATION__
        ifneq ($(strip $(L1_3GSOLUTION)),AST_TL1_TDD)
          CUSTOM_OPTION  += MAL1_NOT_PRESENT __MTK_TL1_TDD__
        else
          ifeq ($(strip $(AST_SUPPORT)),AST1001)
            CUSTOM_OPTION  += __AST1001__
          endif
          ifeq ($(strip $(AST_SUPPORT)),AST1001_LIB)
            CUSTOM_OPTION  += __AST1001__
          endif
          ifeq ($(strip $(AST_SUPPORT)),AST2001)
            CUSTOM_OPTION  += __AST2001__
          endif
          ifeq ($(strip $(AST_SUPPORT)),AST2001_LIB)
            CUSTOM_OPTION  += __AST2001__
          endif
          ifeq ($(strip $(AST_SUPPORT)),AST2001FPGA)
            CUSTOM_OPTION  += __AST2001FPGA__
          endif
          ifeq ($(strip $(AST_SUPPORT)),AST2001FPGA_LIB)
            CUSTOM_OPTION  += __AST2001FPGA__
          endif
          ifeq ($(strip $(AST_SUPPORT)),AST3001)
            CUSTOM_OPTION  += __AST3001__
          endif
          ifeq ($(strip $(AST_SUPPORT)),AST3001_LIB)
            CUSTOM_OPTION  += __AST3001__
          endif
          CUSTOM_OPTION  += __AST_TL1_TDD__ __RACH_FACH_TL1_BITOFFSET__
          CUSTOM_OPTION  += __AST_$(strip $(AST_CHIP_VERSION))__
        endif
      endif
    endif
  endif
endif

ifneq ($(strip $(PLATFORM)),MT6251)
  CUSTOM_OPTION += __SYS_INTERN_RAM__
endif

CUSTOM_OPTION += MTK_NEW_API

ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
  CUSTOM_OPTION  += __PRODUCTION_RELEASE__
endif

# neptune only
ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
ifneq ($(strip $(MMI_VERSION)),COSMOS_MMI)
ifneq ($(strip $(MMI_VERSION)),BW_MMI)
ifneq ($(strip $(MMI_VERSION)),IOT_MMI)
  CUSTOM_OPTION    += MED_V_NOT_PRESENT
  CUSTOM_OPTION    += __SLIM_DATA__
endif
endif
endif
endif
endif
endif

ifeq ($(strip $(TST_SUPPORT)),TRUE)
  CUSTOM_OPTION    += __TST_MODULE__
else
  CUSTOM_OPTION    += DRV_DEBUG
endif


ifeq ($(strip $(MCD_SUPPORT)),TRUE)
  ifeq ($(strip $(L1S_BASIC)),FALSE)
    CUSTOM_OPTION    += __MCD__
  endif
endif

# For WISDOM_MMI
ifeq ($(strip $(MMI_VERSION)),WISDOM_MMI)
  CUSTOM_OPTION += $(strip $(MMI_VERSION)) __MMI_FMI__ __MOD_L4A__ EXTERNAL_MMI
endif

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  CUSTOM_OPTION += __MMI_FMI__ __MOD_L4A__ PLUTO_MMI __VENUS_MMI__ __PLUTO_MMI_PACKAGE__ 
else
  ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
    CUSTOM_OPTION += __MMI_FMI__ __MOD_L4A__ VENUS_MMI __COSMOS_MMI__ __VENUS_MMI__ PLUTO_MMI __COSMOS_MMI_PACKAGE__
  else
    ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      CUSTOM_OPTION += EMPTY_MMI
    else
      ifeq ($(strip $(MMI_VERSION)),BW_MMI)
        CUSTOM_OPTION += __MMI_FMI__ __MOD_L4A__ PLUTO_MMI __BW_MMI__
      else
        ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
          CUSTOM_OPTION += __MMI_FMI__ __MOD_L4A__ PLUTO_MMI __VENUS_MMI__ __PLUTO_MMI_PACKAGE__
        endif
      endif
    endif
  endif
endif

ifeq ($(strip $(MMI_VERSION)),NEPTUNE_COLOR_MMI)
  CUSTOM_OPTION += __MMI_FMI__ __MOD_L4A__  __VENUS_MMI__ NEPTUNE_MMI
else
  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
    CUSTOM_OPTION += __MMI_FMI__ __MOD_L4A__  __VENUS_MMI__ $(strip $(MMI_VERSION))
  endif
endif

ifeq ($(strip $(SPLIT_SYSTEM)),TRUE)
   CUSTOM_OPTION    += UT_ON_TARGET SPLIT_SYS
endif

ifeq ($(strip $(EMAIL_SUPPORT)),TRUE)
   CUSTOM_OPTION    += __EMAIL__
endif

ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
  CUSTOM_OPTION += __IOT__
endif

ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
   CUSTOM_OPTION    += __IRDA_SUPPORT__
endif

ifneq ($(strip $(PHB_SIM_ENTRY)),)
  CUSTOM_OPTION += __PHB_SIM_$(strip $(PHB_SIM_ENTRY))__
endif

ifneq ($(strip $(PHB_PHONE_ENTRY)),)
  CUSTOM_OPTION += __PHB_PHONE_$(strip $(PHB_PHONE_ENTRY))__
endif

ifeq ($(strip $(PMIC)),MT6305)
     CUSTOM_OPTION    += MT6305 __CHARGER_WITH_IMMEDIMATE_ADC__
endif

ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  CUSTOM_OPTION    += __DSP_FCORE4__
endif

ifdef BROWSER_SUPPORT
  ifneq ($(strip $(BROWSER_SUPPORT)),NONE)
    ifneq ($(call Upper,$(strip $(PROJECT))),GSM)
      ifeq ($(strip $(LOW_COST_SUPPORT)),NONE)
        CUSTOM_OPTION    +=  __SATCC__
      endif
    endif
  endif
endif

ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
  CUSTOM_OPTION    += __IDLE_INTERF_MEAS__ __PKT_EXT_MEAS__
endif

CUSTOM_OPTION += __AMR_WB_WHITE_LIST__

ifeq ($(strip $(EXT_MD_EXCEPTION_NOTIFY_ENABLE)),TRUE)
  COM_DEFS += __EXT_MD_EXCEPTION_NOTIFY_ENABLE__
endif
