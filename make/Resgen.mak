
ifndef MMI_PROJ
  ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
    MMI_PROJ := PLUTO
  else
    MMI_PROJ := $(subst _MMI,,$(MMI_VERSION))
  endif
endif

ifndef MMI_BASE_PRJ
  MMI_BASE_PRJ := $(subst _MMI,,$(strip $(MMI_BASE)))
endif


NEED_COPY_MMIFEATURE := CUSTOMER_MMI
ifneq ($(filter PLUTO_MMI COSMOS_MMI NEPTUNE_MMI,$(strip $(MMI_VERSION))),)
  NEED_COPY_MMIFEATURE := $(strip $(MMI_VERSION))
endif
ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
  NEED_COPY_MMIFEATURE := PLUTO_MMI
endif

ifdef EMPTY_RESOURCE
  ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
    NEED_COPY_MMIFEATURE := CUSTOMER_MMI
  endif
endif
ifneq ($(filter L1S BASIC UDVT,$(call Upper,$(PROJECT))),)
  NEED_COPY_MMIFEATURE := NONE
endif


ifeq ($(strip $(MMI_IME_V3_SUPPORT)),TRUE)
  RESGEN_CMD_OPTION_IME_VERSION := IMEv3
else ifneq ($(strip $(FINGER_TOUCH_SUPPORT)),NONE)
  RESGEN_CMD_OPTION_IME_VERSION := IMEv2
else
  RESGEN_CMD_OPTION_IME_VERSION := IMEv1
endif

ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_FREETYPE)
  RESGEN_OPTION_FREETYPE := --FREETYPE
else ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_FREETYPE_DEMO)
  RESGEN_OPTION_FREETYPE := --FREETYPE
else
  RESGEN_OPTION_FREETYPE := --NO_FREETYPE
endif

ifdef DRV_CUSTOM_TOOL_SUPPORT
ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
ifneq ($(strip $(call Upper,$(LEVEL))),VENDOR)
  ifeq ($(wildcard $(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe),)
$(shell perl -e "print \"Error: $(FIXPATH)\\custom\\drv\\Drv_Tool\\DrvGen.exe is not found\".\"\n\" ";> $(strip $(COMPLOGDIR))\ckDrvGen.log)
$(error Error: Please check $(strip $(COMPLOGDIR))\ckDrvGen.log)
  else
    RUN_DRVGEN_INPUT := custom\codegen\$(strip $(BOARD_VER))\codegen.dws
    # For RF_MODULE = MT6129D
    ifeq ($(findstring MT6129D,$(strip $(RF_MODULE))),MT6129D)
      RUN_DRVGEN_INPUT := $(FIXPATH)\custom\codegen\$(strip $(BOARD_VER))\codegen_MT6129D.dws
    endif
    # For RF_MODULE = MT6139E
    ifeq ($(findstring MT6139E,$(strip $(RF_MODULE))),MT6139E)
      RUN_DRVGEN_INPUT := $(FIXPATH)\custom\codegen\$(strip $(BOARD_VER))\codegen_MT6139E.dws
    endif
    ifeq ($(strip $(BOARD_VER)),SUPERMAN29_DEMO_BB)
      RUN_DRVGEN_INPUT := $(FIXPATH)\custom\codegen\$(strip $(BOARD_VER))\codegen_$(strip $(SUB_BOARD_VER)).dws
    endif
    # For rotated keypad on Tianyu28_demo/UNICORN53V3_DEMO/UNICORN53V4_DEMO landscape MMI
    ifneq ($(filter $(strip $(BOARD_VER)),TIANYU28_DEMO_BB UNICORN53V3_DEMO_EVB UNICORN53V4_DEMO_EVB),)
      ifeq ($(strip $(MAIN_LCD_SIZE)),320X240)
        RUN_DRVGEN_INPUT := $(FIXPATH)\custom\codegen\$(strip $(BOARD_VER))\codegen1.dws
      endif
    endif
  endif
endif
endif
endif


ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
  ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
NEED_COPY_FONTRES := $(strip $(FONTRES_PATH_MTK))\FontRes.c $(strip $(FONTRES_PATH_CUST))\FontRes.c
NEED_COPY_FONTRES := $(call CheckNeedCopy,$(NEED_COPY_FONTRES))
  else
NEED_COPY_RES_GEN_FONT := $(strip $(FONTRES_PATH_MTK))\res_gen_font.cpp $(strip $(FONTRES_PATH_CUST))\res_gen_font.cpp
NEED_COPY_RES_GEN_FONT := $(call CheckNeedCopy,$(NEED_COPY_RES_GEN_FONT))
  endif
endif
endif


ifeq ($(filter BASIC UDVT,$(call Upper,$(PROJECT))),)
NEED_COPY_LCDRESOURCE_DIR := $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))
  ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
NEED_COPY_LCDRESOURCE_DIR += $(FIXPATH)\plutommi\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\FTO
  else
    ifneq ($(strip $(call Upper,$(FINGER_TOUCH_SUPPORT))),NONE)
NEED_COPY_LCDRESOURCE_DIR += $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\FTE
    else ifneq ($(strip $(call Upper,$(TOUCH_PANEL_SUPPORT))),NONE)
NEED_COPY_LCDRESOURCE_DIR += $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\touch
      ifneq ($(filter __LOW_COST_SUPPORT_COMMON__,$(strip $(COM_DEFS))),)
NEED_COPY_LCDRESOURCE_DIR += $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\slim_touch
      endif
    else
NEED_COPY_LCDRESOURCE_DIR += $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\non_touch
      ifneq ($(filter __LOW_COST_SUPPORT_COMMON__,$(strip $(COM_DEFS))),)
NEED_COPY_LCDRESOURCE_DIR += $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\slim_non_touch
      endif
    endif
  endif
  ifeq ($(call Upper,$(strip $(CUSTOM_RELEASE))),FALSE)
NEED_COPY_LCDRESOURCE := $(call CheckNeedCopyDir,$(NEED_COPY_LCDRESOURCE_DIR),.c) $(call CheckNeedCopyDir,$(NEED_COPY_LCDRESOURCE_DIR),.h)
  else ifneq ($(strip $(call Upper,$(LEVEL))),LEVEL2_OBJ)
NEED_COPY_LCDRESOURCE := $(call CheckNeedCopyDir,$(NEED_COPY_LCDRESOURCE_DIR),.c) $(call CheckNeedCopyDir,$(NEED_COPY_LCDRESOURCE_DIR),.h)
  endif
endif


ifneq ($(filter L1S BASIC,$(call Upper,$(PROJECT))),)
  NEED_COPY_MMISWITCH_LIST := $(FIXPATH)\$(MMIDIR)\Customer\CustResource\EMPTY_MMI\MMI_features_switchEMPTY.h
else
  ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
    NEED_COPY_MMISWITCH_LIST := $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\MMI_features_switch$(strip $(MMI_PROJ)).h
  else
    NEED_COPY_MMISWITCH_LIST := $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\MMI_features_switch$(strip $(MMI_PROJ)).h
  endif
  ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
    NEED_COPY_CUSTMISCDATA_LIST := $(FIXPATH)\$(MMIDIR)\Customer\CustResource\COSMOS_MMI\CustMiscData$(strip $(MMI_PROJ)).c
    NEED_COPY_CUSTRESDEF_LIST := $(FIXPATH)\$(MMIDIR)\Customer\CustResource\COSMOS_MMI\CustResDef$(strip $(MMI_PROJ)).h
    NEED_COPY_REFLIST_LIST := $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\ref_list.txt
  else
    NEED_COPY_CUSTMISCDATA_LIST := $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_BASE))\CustMiscData$(strip $(MMI_BASE_PRJ)).c
    NEED_COPY_CUSTRESDEF_LIST := $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_BASE))\CustResDef$(strip $(MMI_BASE_PRJ)).h
    NEED_COPY_REFLIST_LIST := $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_BASE))\ref_list.txt
  endif
  ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    NEED_COPY_MMISWITCH_LIST += $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI\MMI_features_switch$(strip $(ORIGINAL_CUSTOMER)).h
    ifdef FLAVOR
      ifneq ($(strip $(FLAVOR)),NONE)
        NEED_COPY_MMISWITCH_LIST += $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI\MMI_features_switch$(strip $(ORIGINAL_CUSTOMER))($(strip $(FLAVOR))).h
      endif
    endif
  endif
  ifneq ($(filter PLUTO_MMI COSMOS_MMI NEPTUNE_MMI IOT_MMI,$(strip $(MMI_VERSION))),)
    ifneq ($(strip $(EMPTY_RESOURCE)),FALSE)
      NEED_COPY_CUSTMISCDATA_LIST += $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI\CustMiscData$(strip $(ORIGINAL_CUSTOMER)).c
      NEED_COPY_CUSTRESDEF_LIST += $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI\CustResDef$(strip $(ORIGINAL_CUSTOMER)).h
    endif
  else
    NEED_COPY_CUSTMISCDATA_LIST += $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI\CustMiscData$(strip $(ORIGINAL_CUSTOMER)).c
    NEED_COPY_CUSTRESDEF_LIST += $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI\CustResDef$(strip $(ORIGINAL_CUSTOMER)).h
  endif
  NEED_COPY_REFLIST_LIST += $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI\ref_list.txt
endif
NEED_COPY_MMISWITCH := $(call CheckNeedCopy,$(NEED_COPY_MMISWITCH_LIST))
NEED_COPY_CUSTMISCDATA := $(call CheckNeedCopy,$(NEED_COPY_CUSTMISCDATA_LIST))
NEED_COPY_CUSTRESDEF := $(call CheckNeedCopy,$(NEED_COPY_CUSTRESDEF_LIST))
NEED_COPY_REFLIST := $(call CheckNeedCopy,$(NEED_COPY_REFLIST_LIST))


ifeq ($(strip $(RUN_RESGEN_NEW)),TRUE)
  ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
    NEED_COPY_RES_MMI_DIR := $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\Res_MMI
    NEED_COPY_CUSTRESOURCE_DIR := $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI
  else
    ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
      NEED_COPY_RES_MMI_DIR := $(FIXPATH)\$(MMIDIR)\Customer\CustResource\IOT_MMI\Res_MMI
      NEED_COPY_CUSTRESOURCE_DIR := $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI
    else
      NEED_COPY_RES_MMI_DIR := $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\Res_MMI
      NEED_COPY_CUSTRESOURCE_DIR := $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))
    endif
  endif
  NEED_COPY_CUSTRESOURCE_DIR += $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI
  NEED_COPY_RES_MMI := $(call CheckNeedCopyDir,$(NEED_COPY_RES_MMI_DIR),.c)
  NEED_COPY_CUSTRESOURCE_H := $(filter-out $(NEED_COPY_MMISWITCH_LIST) $(NEED_COPY_CUSTMISCDATA_LIST) $(NEED_COPY_CUSTRESDEF_LIST) $(NEED_COPY_REFLIST_LIST),$(call CheckNeedCopyDir,$(NEED_COPY_CUSTRESOURCE_DIR),.h))
  ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
    NEED_COPY_CUSTRESOURCE_H := $(filter-out $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\Themecomponents.h $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\CustResDef%.h $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\CustResDef%.h $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\MMI_features_switch%.h $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\MMI_features_switch%.h $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\MMI_Features_Switch%.h $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI\MMI_features_switch%.h $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI\MMI_Features_Switch%.h,$(NEED_COPY_CUSTRESOURCE_H))
  else
    NEED_COPY_CUSTRESOURCE_H := $(filter-out $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\Themecomponents.h $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\CustResDef%.h $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\CustResDef%.h $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\MMI_features_switch%.h $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\MMI_features_switch%.h $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\MMI_Features_Switch%.h $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI\MMI_features_switch%.h $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI\MMI_Features_Switch%.h,$(NEED_COPY_CUSTRESOURCE_H))
  endif
  NEED_COPY_CUSTRESOURCE_C := $(filter-out $(NEED_COPY_MMISWITCH_LIST) $(NEED_COPY_CUSTMISCDATA_LIST) $(NEED_COPY_CUSTRESDEF_LIST) $(NEED_COPY_REFLIST_LIST) %.h %.tmp %.xls %.vkw %.exe,$(call CheckNeedCopyDir,$(NEED_COPY_CUSTRESOURCE_DIR),.*))
  ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
    NEED_COPY_CUSTRESOURCE_C := $(filter-out $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\ThemeRes.c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\CustMiscData%.c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\CustMiscData%.c,$(NEED_COPY_CUSTRESOURCE_C))    
  else
    NEED_COPY_CUSTRESOURCE_C := $(filter-out $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\ThemeRes.c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\CustMiscData%.c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\CustMiscData%.c,$(NEED_COPY_CUSTRESOURCE_C))
  endif
  ifneq ($(filter PLUTO_MMI COSMOS_MMI,$(strip $(MMI_VERSION))),)
    NEED_COPY_VKV2VKW_LIST := $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\VKV2.vkw $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI\VKV2.vkw
    NEED_COPY_VKV2EXE_LIST := $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\VKV2ResourceGen.exe $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(ORIGINAL_CUSTOMER))_MMI\VKV2ResourceGen.exe
    NEED_COPY_VKV2VKW := $(call CheckNeedCopy,$(NEED_COPY_VKV2VKW_LIST))
    NEED_COPY_VKV2EXE := $(call CheckNeedCopy,$(NEED_COPY_VKV2EXE_LIST))
  endif
endif


ifeq ($(filter L1S BASIC,$(PROJECT)),)
ifdef J2ME_SUPPORT
ifneq ($(strip $(J2ME_SUPPORT)),NONE)
  J2ME_BORADBB_DIR := $(strip $(BOARD_VER))
  J2ME_SUPPORT_DIR := $(strip $(J2ME_SUPPORT))
  ifneq ($(filter IJET NEMO,$(strip $(J2ME_SUPPORT))),)
    ifdef FLAVOR
      ifneq ($(strip $(FLAVOR)),NONE)
        J2ME_BORADBB_DIR := $(strip $(BOARD_VER))($(strip $(FLAVOR)))
      endif
    endif
  else ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMY_MVM)
    J2ME_SUPPORT_DIR := DUMMY
  endif
  J2ME_GAMEGEN_EXE := $(wildcard custom\j2me\$(J2ME_SUPPORT_DIR)\_DEFAULT_BB\builtin_game_generator\DefaultGameGen.exe)
  ifneq ($(strip $(J2ME_GAMEGEN_EXE)),)
    J2ME_GAMEGEN_INPUTSYSTEM := _DEFAULT_BB
    J2ME_GAMEGEN_INPUTMIDLET := _DEFAULT_BB
    J2ME_GAMEGEN_OUTPUT := _DEFAULT_BB
    ifneq ($(wildcard custom\j2me\$(J2ME_SUPPORT_DIR)\$(J2ME_BORADBB_DIR)\_main.ks),)
    ifneq ($(wildcard custom\j2me\$(J2ME_SUPPORT_DIR)\$(J2ME_BORADBB_DIR)\_policy.txt),)
    ifneq ($(wildcard custom\j2me\$(J2ME_SUPPORT_DIR)\$(J2ME_BORADBB_DIR)\_tck.ks),)
      J2ME_GAMEGEN_INPUTSYSTEM := $(J2ME_BORADBB_DIR)
      J2ME_GAMEGEN_OUTPUT := $(J2ME_BORADBB_DIR)
    endif
    endif
    endif
    ifneq ($(filter PLUTO_MMI COSMOS_MMI NEPTUNE_MMI IOT_MMI,$(strip $(MMI_VERSION))),)
      ifneq ($(wildcard custom/j2me/$(J2ME_SUPPORT_DIR)/$(J2ME_BORADBB_DIR)/*.jar custom/j2me/$(J2ME_SUPPORT_DIR)/$(J2ME_BORADBB_DIR)/*.jad),)
        J2ME_GAMEGEN_INPUTMIDLET := $(J2ME_BORADBB_DIR)
        J2ME_GAMEGEN_OUTPUT := $(J2ME_BORADBB_DIR)
      endif
    else
      J2ME_GAMEGEN_INPUTMIDLET := $(J2ME_BORADBB_DIR)
      J2ME_GAMEGEN_OUTPUT := $(J2ME_BORADBB_DIR)
    endif
  endif
endif
endif
endif

NEED_COPY_RGB565 := $(subst /,\,$(wildcard $(MMIDIR)/Customer/Images/decoder/RGB565/*.*))

# Setting for IOT_MMI
MMI_VERSION_BASE := $(MMI_VERSION)
ifdef MMI_VERSION
  ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
    MMI_VERSION_BASE := PLUTO_MMI
  endif
endif

# Setting parameters for ResGenerator_HW in resgen_mtk target.
POPULATE_ARGUMENT := 
ifneq ($(filter __POPULATE_NO_STRING_DATA__ ,$(strip $(COM_DEFS))),)
  POPULATE_ARGUMENT += NOSTRING 
endif
ifneq ($(filter __POPULATE_NO_IMAGE_DATA__ ,$(strip $(COM_DEFS))),)
  POPULATE_ARGUMENT += NOIMAGE
endif

# *************************************************************************
# Generate Custom Information
# *************************************************************************
gencustominfo: flavor_conf
$(eval $(call CheckNeedDependTarget,gencustominfo,pregen_dep))
$(strip $(RULESDIR_TARGET))\pregen_dep\gencustominfo.det: $(NEED_CHECK_RESGEN_LIST)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if exist $(strip $(TARGDIR))\build.log \
		(@perl -e "print 'gencustominfo START TIME='";>>$(strip $(TARGDIR))\build.log & \
		@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)

ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	-@echo $@: $?
endif
	@if exist $(basename $@).log del /q $(basename $@).log
	@if not exist $(patsubst %\,%,$(dir $@)) mkdir $(patsubst %\,%,$(dir $@))
ifneq ($(strip $(RUN_DRVGEN_INPUT)),)
	@echo [Dependency] $(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(RUN_DRVGEN_INPUT) >>$(basename $@).log
	@echo [Dependency] $(wildcard $(FIXPATH)/custom/drv/Drv_Tool/*.fig $(FIXPATH)/custom/drv/Drv_Tool/*.cmp) >>$(basename $@).log
	$(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(RUN_DRVGEN_INPUT) $(strip $(COMPLOGDIR)) 2>&1 & \
		(if ERRORLEVEL 1 (echo DrvGen.exe Error. Please check $(strip $(COMPLOGDIR))\DrvGen.log & exit 1))
endif
ifneq ($(strip $(NEED_COPY_LCDRESOURCE)),)
	@echo [Dependency] $(NEED_COPY_LCDRESOURCE) >>$(basename $@).log
#  ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
	@for %%i in ($(strip $(NEED_COPY_LCDRESOURCE))) do (copy /y %%i $(FIXPATH)\$(MMIDIR)\Customer\CustResource\ >NUL)
#  else
#	@for %%i in ($(strip $(NEED_COPY_LCDRESOURCE))) do (copy /y %%i $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\ >NUL)
#  endif
endif
ifneq ($(strip $(NEED_COPY_MMISWITCH)),)
	@echo MMI_features_switch.h is from $(NEED_COPY_MMISWITCH)
	@echo [Dependency] $(NEED_COPY_MMISWITCH) >>$(basename $@).log
	@copy /y $(NEED_COPY_MMISWITCH) $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h >NUL
else
	@echo MMI_features_switch.h is from $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h
endif
ifneq ($(strip $(NEED_COPY_CUSTMISCDATA)),)
	@echo [Dependency] $(NEED_COPY_CUSTMISCDATA) >>$(basename $@).log
	@copy /y $(NEED_COPY_CUSTMISCDATA) $(FIXPATH)\$(MMIDIR)\Customer\CustResource\CustMiscData.c >NUL
endif
ifneq ($(strip $(NEED_COPY_CUSTRESDEF)),)
	@echo [Dependency] $(NEED_COPY_CUSTRESDEF) >>$(basename $@).log
	@copy /y $(NEED_COPY_CUSTRESDEF) $(FIXPATH)\$(MMIDIR)\Customer\CustomerInc\CustResDef.h >NUL
endif
ifneq ($(strip $(NEED_COPY_REFLIST)),)
# It seems only NEPTUNE resgen needs it
	@echo [Dependency] $(NEED_COPY_REFLIST) >>$(basename $@).log
	@copy /y $(NEED_COPY_REFLIST) $(FIXPATH)\$(MMIDIR)\Customer\CustResource\ref_list.txt >NUL
endif
ifneq ($(strip $(NEED_COPY_RES_GEN_FONT)),)
	@echo [Dependency] $(NEED_COPY_RES_GEN_FONT) >>$(basename $@).log
	@if not exist $(FIXPATH)\$(MMIDIR)\Customer\FontResgen mkdir $(FIXPATH)\$(MMIDIR)\Customer\FontResgen
	@copy /y $(NEED_COPY_RES_GEN_FONT) $(FIXPATH)\$(MMIDIR)\Customer\FontResgen\res_gen_font.cpp >NUL
endif
ifneq ($(strip $(NEED_COPY_FONTRES)),)
	@echo [Dependency] $(NEED_COPY_FONTRES) >>$(basename $@).log
	@copy /y $(NEED_COPY_FONTRES) $(FIXPATH)\$(MMIDIR)\Customer\CustResource\FontRes.c >NUL
endif

   # clean font related files in $(FIXPATH)\$(MMIDIR)\Customer\CustResource
ifneq ($(filter L1S BASIC UDVT,$(strip $(call Upper,$(PROJECT)))),)
else
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\L_*.h \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\L_MMIProp.h \
			(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\L_MMIProp.h $(FIXPATH)\make\ >NUL) \
		) & \
		(del /q $(FIXPATH)\$(MMIDIR)\Customer\CustResource\L_*.h) & \
		(if exist $(FIXPATH)\make\L_MMIProp.h \
			(copy /y $(FIXPATH)\make\L_MMIProp.h $(FIXPATH)\$(MMIDIR)\Customer\CustResource\ >NUL) & \
			(del $(FIXPATH)\make\L_MMIProp.h) \
		)
  endif
endif

	@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $@)) $(basename $(notdir $@))\.(log^|lis)
ifneq ($(AUTO_CHECK_DEBUG),TRUE)
	@if exist $(basename $@).log del /q $(basename $@).log
	@if exist $(basename $@).lis del /q $(basename $@).lis
endif

	@if exist $(strip $(TARGDIR))\build.log \
		(@perl -e "print 'gencustominfo END TIME='";>>$(strip $(TARGDIR))\build.log & \
		@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


gencustomlists: gencustominfo
$(eval $(call CheckNeedDependTarget,gencustomlists,pregen_dep))
$(strip $(RULESDIR_TARGET))\pregen_dep\gencustomlists.det: $(strip $(RULESDIR_TARGET))\pregen_dep\gencustominfo.det
$(strip $(RULESDIR_TARGET))\pregen_dep\gencustomlists.det: $(NEED_CHECK_RESGEN_LIST)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'gencustomlists START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # If module "custom" is released to customer with .lib only, don't run custominfo.pl
ifneq ($(strip $(call Upper,$(LEVEL))),VENDOR)
ifeq ($(strip $(call Upper,$(CUSTOM_EXIST))),TRUE)
	@if exist $(basename $@).log del /q $(basename $@).log
	@echo Generate customization information ... >> $(LOG)

  ifneq ($(J2ME_SUPPORT_DIR),)
  ifneq ($(J2ME_BORADBB_DIR),)
    # switch file
    ifneq ($(wildcard custom\j2me\$(J2ME_SUPPORT_DIR)\$(J2ME_BORADBB_DIR)\j2me_custom_option.h),)
	@if exist custom\j2me\$(J2ME_SUPPORT_DIR)\_DEFAULT_BB\j2me_custom_option.h del /q custom\j2me\$(J2ME_SUPPORT_DIR)\_DEFAULT_BB\j2me_custom_option.h
    else
	@if exist custom\j2me\$(J2ME_SUPPORT_DIR)\_DEFAULT_BB\_j2me_custom_option.h copy /y custom\j2me\$(J2ME_SUPPORT_DIR)\_DEFAULT_BB\_j2me_custom_option.h custom\j2me\$(J2ME_SUPPORT_DIR)\_DEFAULT_BB\j2me_custom_option.h >NUL
	@echo [Dependency] custom\j2me\$(J2ME_SUPPORT_DIR)\_DEFAULT_BB\_j2me_custom_option.h >>$(basename $@).log
    endif
    ifneq ($(wildcard custom\j2me\$(J2ME_SUPPORT_DIR)\$(J2ME_BORADBB_DIR)\j2me_custom_param.h),)
	@if exist custom\j2me\$(J2ME_SUPPORT_DIR)\_DEFAULT_BB\j2me_custom_param.h del /q custom\j2me\$(J2ME_SUPPORT_DIR)\_DEFAULT_BB\j2me_custom_param.h
    else
	@if exist custom\j2me\$(J2ME_SUPPORT_DIR)\_DEFAULT_BB\_j2me_custom_param.h copy /y custom\j2me\$(J2ME_SUPPORT_DIR)\_DEFAULT_BB\_j2me_custom_param.h custom\j2me\$(J2ME_SUPPORT_DIR)\_DEFAULT_BB\j2me_custom_param.h >NUL
	@echo [Dependency] custom\j2me\$(J2ME_SUPPORT_DIR)\_DEFAULT_BB\_j2me_custom_param.h >>$(basename $@).log
    endif
    # check romizing
    ifneq ($(filter IJET NEMO,$(strip $(J2ME_SUPPORT))),)
	@echo ROMizing folder is custom\j2me\$(J2ME_SUPPORT_DIR)\$(J2ME_BORADBB_DIR)
	@if not exist custom\j2me\$(J2ME_SUPPORT_DIR)\$(J2ME_BORADBB_DIR) ((echo ROMizing folder does not exist. Please execute romizing first.) && (exit 1))
    endif
    # game gen
    ifneq ($(strip $(J2ME_GAMEGEN_EXE)),)
	@(cd custom\j2me\$(J2ME_SUPPORT_DIR)\_DEFAULT_BB\builtin_game_generator) && \
		(DefaultGameGen.exe -certfolder -setpath .\setting -inputSystem "..\..\$(J2ME_GAMEGEN_INPUTSYSTEM)" -inputMidlet "..\..\$(J2ME_GAMEGEN_INPUTMIDLET)" -output "..\..\$(J2ME_GAMEGEN_OUTPUT)" -create -logpath "..\..\$(J2ME_GAMEGEN_INPUTMIDLET)") & \
		(exit 0)
	@echo [Dependency] custom\j2me\$(J2ME_SUPPORT_DIR)\_DEFAULT_BB\builtin_game_generator\DefaultGameGen.exe custom\j2me\$(J2ME_SUPPORT_DIR)\_DEFAULT_BB\builtin_game_generator\setting\setting.txt >>$(basename $@).log
	@echo [Dependency] $(wildcard custom/j2me/$(J2ME_SUPPORT_DIR)/$(J2ME_GAMEGEN_INPUTSYSTEM)/_main.ks custom/j2me/$(J2ME_SUPPORT_DIR)/$(J2ME_GAMEGEN_INPUTSYSTEM)/_policy.txt custom/j2me/$(J2ME_SUPPORT_DIR)/$(J2ME_GAMEGEN_INPUTSYSTEM)/_tck.ks) >>$(basename $@).log
	@echo [Dependency] $(wildcard custom/j2me/$(J2ME_SUPPORT_DIR)/$(J2ME_GAMEGEN_INPUTMIDLET)/*.jar custom/j2me/$(J2ME_SUPPORT_DIR)/$(J2ME_GAMEGEN_INPUTMIDLET)/*.jad custom/j2me/$(J2ME_SUPPORT_DIR)/$(J2ME_GAMEGEN_INPUTMIDLET)/*.keystore custom/j2me/$(J2ME_SUPPORT_DIR)/$(J2ME_GAMEGEN_INPUTMIDLET)/*.policy) >>$(basename $@).log
	@echo [Dependency] $(wildcard custom/j2me/$(J2ME_SUPPORT_DIR)/_DEFAULT_BB/builtin_game_generator/temp/TCK/*.* custom/j2me/$(J2ME_SUPPORT_DIR)/_DEFAULT_BB/builtin_game_generator/TCK/*.*) >>$(basename $@).log
    else
	@echo Skip to generate JAVA game due to no custom\j2me\$(J2ME_SUPPORT_DIR)\_DEFAULT_BB\builtin_game_generator\DefaultGameGen.exe
    endif
  endif
  endif
  ifeq ($(strip $(TOUCH_PANEL_SHORTCUT_SUPPORT)),TRUE)
	@if not exist custom\app\$(strip $(BOARD_VER))\touch_panel_shortcut_custom.c \
		(copy /y custom\common\touch_panel_shortcut_custom.c.tmp custom\app\$(strip $(BOARD_VER))\touch_panel_shortcut_custom.c >NUL) && \
		(echo [Dependency] custom\common\touch_panel_shortcut_custom.c.tmp >>$(basename $@).log)
	@if not exist custom\app\$(strip $(BOARD_VER))\touch_panel_shortcut_custom.h \
		(copy /y custom\common\touch_panel_shortcut_custom.h.tmp custom\app\$(strip $(BOARD_VER))\touch_panel_shortcut_custom.h >NUL) && \
		(echo [Dependency] custom\common\touch_panel_shortcut_custom.h.tmp >>$(basename $@).log)
  endif
  ifneq ($(strip $(NEED_COPY_RGB565)),)
	@tools\strcmpex.exe TRUE TRUE e $(basename $@).lis $(NEED_COPY_RGB565)
	@perl tools\lnitem.pl $(basename $@).lis
	@for /f %%i in ($(basename $@).lis) do (copy /y %%i $(MMIDIR)\Customer\Images\ >NUL)
  endif

	@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $@)) $(basename $(notdir $@))\.(log^|lis)
  ifneq ($(AUTO_CHECK_DEBUG),TRUE)
	@if exist $(basename $@).log del /q $(basename $@).log
	@if exist $(basename $@).lis del /q $(basename $@).lis
  endif
endif
endif
ifeq ($(strip $(call Upper,$(MAUI_IN_ROM))),TRUE)
	@if exist make\rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\rompatch.* \
		(xcopy /Y make\rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER)) make\rompatch >nul 2>&1) \
	else \
		(echo Directory make\rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER)) Does NOT exist.)
endif
	@perl -e "print 'gencustomlists END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


xml_parser: mmi_feature_check resgen_public
ifneq ($(filter PLUTO_MMI COSMOS_MMI IOT_MMI,$(strip $(MMI_VERSION))),)
ifeq ($(filter ANDROID_MODEM,$(strip $(SMART_PHONE_CORE))),)
$(eval $(call CheckNeedDependTarget,xml_parser,pregen_dep))
$(strip $(RULESDIR_TARGET))\pregen_dep\xml_parser.det: $(NEED_CHECK_RESGEN_LIST)
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'xml_parser START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	-@echo $@: $?
endif

  # generate dummy ps_trace.h and *_trc_gen.h
	@if not exist $(strip $(TST_DB_TARGET))\pstrace_db mkdir $(strip $(TST_DB_TARGET))\pstrace_db
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
  ifneq ($(strip $(call Upper,$(PROJECT))),UDVT)
	@if not exist $(strip $(TST_DB_TARGET))\pstrace_db\ps_trace.h \
		((echo #ifdef PSTRC_Mainh_DEF_H > $(strip $(TST_DB_TARGET))\pstrace_db\ps_trace.h) & \
		(echo #undef PSTRC_Mainh_DEF_H >> $(strip $(TST_DB_TARGET))\pstrace_db\ps_trace.h) & \
		(echo #endif >> $(strip $(TST_DB_TARGET))\pstrace_db\ps_trace.h))
  endif
  endif
	@if exist $(strip $(TST_DB))\CompTrcDefs.lst (del $(strip $(TST_DB))\CompTrcDefs.lst)
	@tools\strcmpex.exe TRUE TRUE e $(strip $(TST_DB))\CompTrcDefs.lst $(call sort, $(foreach def,$(COMP_TRACE_DEFS),$(def)))
	@tools\CreateEmptyTrcGenFiles.exe $(strip $(TST_DB_TARGET))\pstrace_db $(strip $(TST_DB))\CompTrcDefs.lst $(strip $(TSTDIR))\database\TrcGen.lst

		@if exist $(basename $@)_*.d del /q $(basename $@)_*.d
  ifneq ($(strip $(call Upper,$(LEVEL))),VENDOR)
    ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
      ifneq ($(filter $(strip $(ACTION)),new bm_new),)
        # new_resgen
			$(MMIDIR)\Customer\ResGenerator_XML.bat PLUTO_MMI $(CUSTOMER) B C $(strip $(RESGEN_CMD_OPTION_IME_VERSION))
      else ifneq ($(filter $(MAKECMDGOALS),new new_modis),)
        # new_resgen
			$(MMIDIR)\Customer\ResGenerator_XML.bat PLUTO_MMI $(CUSTOMER) B C $(strip $(RESGEN_CMD_OPTION_IME_VERSION))
      else
        # remake_resgen
			$(MMIDIR)\Customer\ResGenerator_XML.bat PLUTO_MMI $(CUSTOMER) R 0 $(strip $(RESGEN_CMD_OPTION_IME_VERSION))
      endif
    else
      ifneq ($(filter $(strip $(ACTION)),new bm_new),)
        # new_resgen
			$(MMIDIR)\Customer\ResGenerator_XML.bat $(MMI_VERSION) $(CUSTOMER) B C $(strip $(RESGEN_CMD_OPTION_IME_VERSION))
      else ifneq ($(filter $(MAKECMDGOALS),new new_modis),)
        # new_resgen
			$(MMIDIR)\Customer\ResGenerator_XML.bat $(MMI_VERSION) $(CUSTOMER) B C $(strip $(RESGEN_CMD_OPTION_IME_VERSION))
      else
        # remake_resgen
			$(MMIDIR)\Customer\ResGenerator_XML.bat $(MMI_VERSION) $(CUSTOMER) R 0 $(strip $(RESGEN_CMD_OPTION_IME_VERSION))
      endif
    endif
		@perl tools\pack_dep_gen.pl $(basename $@)_1.d $@ $(COMPLOGDIR) resgen_xml_\w+\.log
		@perl tools\pack_dep_gen.pl $(basename $@)_2.d $@ $(MMIDIR)\Customer\ResGenerator\debug\dep ^(common^|xml_parser)\.dep
    ifdef OPTR_SPEC
      ifneq ($(strip $(OPTR_SPEC)),NONE)
		@perl tools\pack_dep_gen.pl $(basename $@)_3.d $@ $(OPTR_PATH) \w+mmi_copy\.log
      endif
    endif
		@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $@)) $(basename $(notdir $@))_\d+\.d
ifneq ($(AUTO_CHECK_DEBUG),TRUE)
		@if exist $(basename $@)_*.d del /q $(basename $@)_*.d
endif

#	@if exist $(MMIDIR)\Customer\ResGenerator\Debug\dep\xml_parser.dep (copy /y $(MMIDIR)\Customer\ResGenerator\Debug\dep\xml_parser.dep $(strip $(RULESDIR_TARGET))\xml_parser.dep >NUL)
  endif
endif
endif

	@perl -e "print 'xml_parser END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


# *************************************************************************
#  Resgen
# *************************************************************************
ifeq ($(strip $(RUN_RESGEN)),TRUE)
resgen: xml_parser resgen_mtk
else
resgen:
endif

##############################################################
# Resource generate
##############################################################
resgen_public:
ifeq ($(strip $(RUN_RESGEN_NEW)),TRUE)
ifneq ($(strip $(call Upper,$(LEVEL))),VENDOR)
$(eval $(call CheckNeedDependTarget,resgen_public,pregen_dep))
$(strip $(RULESDIR_TARGET))\pregen_dep\xml_parser.det: $(strip $(RULESDIR_TARGET))\pregen_dep\resgen_public.det
$(strip $(RULESDIR_TARGET))\pregen_dep\resgen_mtk.det: $(strip $(RULESDIR_TARGET))\pregen_dep\resgen_public.det
$(strip $(RULESDIR_TARGET))\pregen_dep\resgen_public.det: $(NEED_CHECK_RESGEN_LIST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	-@echo $@: $?
endif
	@if exist $(basename $@)_*.lis del /q $(basename $@)_*.lis
		@tools\strcmpex.exe TRUE TRUE e make\~cus_opt.tmp $(foreach def,$(sort $(COM_DEFS_TARGET)),-D \"$(def)\")
		@tools\strcmpex.exe TRUE TRUE e make\~tgt_opt.tmp $(foreach def,$(COM_DEFS_TARGET) $(LCD_MODULE),/D \"$(def)\")
		@tools\strcmpex.exe TRUE TRUE e make\~inc.tmp $(foreach inc,$(COMMINCDIRS_TARGET),$(inc))
		@echo CUSTOM_OPTION = $(foreach def,$(BOARD_VER) $(PLATFORM) $(LCD_MODULE) $(EXT_CAM_MODULE) $(CMOS_SENSOR),-D "$(def)") \> $(MMIDIR)\Customer\resGenerator\custom_option.txt
		@type make\~cus_opt.tmp >> $(MMIDIR)\Customer\resGenerator\custom_option.txt
		@type make\~inc.tmp > $(MMIDIR)\Customer\resGenerator\custom_include.tmp
		@perl -e "open F,'<$(MMIDIR)\Customer\resGenerator\custom_include.tmp';my $$i=join('',<F>);close F;$$i =~s/\s+/ /gs;$$i =~ s/(\S+)/-I \"..\\..\\..\\$$1\"/gs;print \"CUSTOM_INC = $$i\";" > $(MMIDIR)\Customer\resGenerator\custom_include.txt
		@perl -e "open F,'<$(MMIDIR)\Customer\resGenerator\custom_include.tmp';my $$i=join('',<F>);close F;$$i =~s/\s+/ /gs;$$i =~ s/(\S+)/\/I \"..\\..\\$$1\"\n/gs;print \"$$i\";" > $(MMIDIR)\MMI\GlobalTargetPathDef
		@if exist $(MMIDIR)\Customer\resGenerator\custom_include.tmp del $(MMIDIR)\Customer\resGenerator\custom_include.tmp
		@if exist $(MMIDIR)\mmi\TargetOption.txt del $(MMIDIR)\mmi\TargetOption.txt
		@copy /Y make\~tgt_opt.tmp $(MMIDIR)\MMI\TargetOption.txt >NUL

	@tools\strcmpex.exe TRUE TRUE e $(basename $@)_1.lis $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator_XML.tmp $(MMIDIR)\Customer\ResGenerator_HW.tmp $(MMIDIR)\Customer\ResGenerator.tmp $(MMIDIR)\Customer\remakeResource.tmp $(MMIDIR)\Customer\UpdateSkin.tmp
	@perl tools\lnitem.pl $(basename $@)_1.lis
  ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator_HW.tmp XXX PLUTO $(MMIDIR)\Customer\ResGenerator_HW.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator.tmp XXX PLUTO $(MMIDIR)\Customer\ResGenerator.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\remakeResource.tmp XXX PLUTO $(MMIDIR)\Customer\remakeResource.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\UpdateSkin.tmp XXX PLUTO $(MMIDIR)\Customer\UpdateSkin.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator_XML.tmp XXX PLUTO $(MMIDIR)\Customer\ResGenerator_XML.bat
  else
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator_HW.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\Customer\ResGenerator_HW.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\Customer\ResGenerator.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\remakeResource.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\Customer\remakeResource.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\UpdateSkin.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\Customer\UpdateSkin.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator_XML.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\Customer\ResGenerator_XML.bat
  endif
  ifneq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator_XML.bat YYY $(patsubst %_MMI,%,$(CUSTOMER)) $(MMIDIR)\Customer\ResGenerator_XML.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator_XML.bat SSS $(strip $(OPTR_SPEC)) $(MMIDIR)\Customer\ResGenerator_XML.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator_XML.bat MMM $(strip $(MAIN_LCD_SIZE)) $(MMIDIR)\Customer\ResGenerator_XML.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator_XML.bat PPP $(strip $(OPTR_PATH)) $(MMIDIR)\Customer\ResGenerator_XML.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator_XML.bat QQQ $(strip $(TOUCH_PANEL_SUPPORT)) $(MMIDIR)\Customer\ResGenerator_XML.bat
  endif
  ifeq ($(strip $(NEED_COPY_MMIFEATURE)),CUSTOMER_MMI)
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator_HW.bat YYY $(patsubst %_MMI,%,$(CUSTOMER)) $(MMIDIR)\Customer\ResGenerator_HW.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator.bat YYY $(patsubst %_MMI,%,$(CUSTOMER)) $(MMIDIR)\Customer\ResGenerator.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\remakeResource.bat YYY $(patsubst %_MMI,%,$(CUSTOMER)) $(MMIDIR)\Customer\remakeResource.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\UpdateSkin.bat YYY $(patsubst %_MMI,%,$(CUSTOMER)) $(MMIDIR)\Customer\UpdateSkin.bat
  else
        ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
			@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator_HW.bat YYY PLUTO $(MMIDIR)\Customer\ResGenerator_HW.bat
			@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator.bat YYY PLUTO $(MMIDIR)\Customer\ResGenerator.bat
			@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\remakeResource.bat YYY PLUTO $(MMIDIR)\Customer\remakeResource.bat
			@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\UpdateSkin.bat YYY PLUTO $(MMIDIR)\Customer\UpdateSkin.bat
        else
			@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator_HW.bat YYY $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\Customer\ResGenerator_HW.bat
			@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator.bat YYY $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\Customer\ResGenerator.bat
			@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\remakeResource.bat YYY $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\Customer\remakeResource.bat
			@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\UpdateSkin.bat YYY $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\Customer\UpdateSkin.bat
        endif
  endif
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator_HW.bat SSS $(strip $(OPTR_SPEC)) $(MMIDIR)\Customer\ResGenerator_HW.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator_HW.bat MMM $(strip $(MAIN_LCD_SIZE)) $(MMIDIR)\Customer\ResGenerator_HW.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator_HW.bat PPP $(strip $(OPTR_PATH)) $(MMIDIR)\Customer\ResGenerator_HW.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator_HW.bat QQQ $(strip $(TOUCH_PANEL_SUPPORT)) $(MMIDIR)\Customer\ResGenerator_HW.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator.bat SSS $(strip $(OPTR_SPEC)) $(MMIDIR)\Customer\ResGenerator.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator.bat MMM $(strip $(MAIN_LCD_SIZE)) $(MMIDIR)\Customer\ResGenerator.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator.bat PPP $(strip $(OPTR_PATH)) $(MMIDIR)\Customer\ResGenerator.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\ResGenerator.bat QQQ $(strip $(TOUCH_PANEL_SUPPORT)) $(MMIDIR)\Customer\ResGenerator.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\remakeResource.bat SSS $(strip $(OPTR_SPEC)) $(MMIDIR)\Customer\remakeResource.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\remakeResource.bat MMM $(strip $(MAIN_LCD_SIZE)) $(MMIDIR)\Customer\remakeResource.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\remakeResource.bat PPP $(strip $(OPTR_PATH)) $(MMIDIR)\Customer\remakeResource.bat
		@perl $(MMIDIR)\Customer\replace_project_name.pl $(MMIDIR)\Customer\remakeResource.bat QQQ $(strip $(TOUCH_PANEL_SUPPORT)) $(MMIDIR)\Customer\remakeResource.bat

  ifdef OPTR_SPEC
    ifneq ($(strip $(OPTR_SPEC)),NONE)
		@if exist $(OPTR_PATH)\ResGenerator_OP.tmp \
			(@perl $(MMIDIR)\Customer\replace_project_name.pl $(OPTR_PATH)\ResGenerator_OP.tmp {OP_NAME} $(strip $(word 1,$(subst _, ,$(OPTR_SPEC)))) $(OPTR_PATH)\ResGenerator_OP.bat) && \
			(@perl $(MMIDIR)\Customer\replace_project_name.pl $(OPTR_PATH)\ResGenerator_OP.bat {VER_NUM} $(strip $(word 2,$(subst _, ,$(OPTR_SPEC)))) $(OPTR_PATH)\ResGenerator_OP.bat) && \
			(@perl $(MMIDIR)\Customer\replace_project_name.pl $(OPTR_PATH)\ResGenerator_OP.bat {SEG_NAME} $(strip $(word 3,$(subst _, ,$(OPTR_SPEC)))) $(OPTR_PATH)\ResGenerator_OP.bat) && \
			(@perl $(MMIDIR)\Customer\replace_project_name.pl $(OPTR_PATH)\ResGenerator_OP.bat {OP_FTE} $(strip $(FINGER_TOUCH_SUPPORT)) $(OPTR_PATH)\ResGenerator_OP.bat) && \
			(@perl $(MMIDIR)\Customer\replace_project_name.pl $(OPTR_PATH)\ResGenerator_OP.bat {OP_BROWSER} $(strip $(BROWSER_SUPPORT)) $(OPTR_PATH)\ResGenerator_OP.bat) && \
			(echo $(OPTR_PATH)\ResGenerator_OP.tmp >>$(basename $@)_1.lis)
		@if exist $(OPTR_PATH)\operator_CustResDef.tmp \
			(@perl $(MMIDIR)\Customer\replace_project_name.pl $(OPTR_PATH)\operator_CustResDef.tmp {OP_NAME} $(strip $(word 1,$(subst _, ,$(OPTR_SPEC)))) $(OPTR_PATH)\operator_CustResDef.h) && \
			(@perl $(MMIDIR)\Customer\replace_project_name.pl $(OPTR_PATH)\operator_CustResDef.h {VER_NUM} $(strip $(word 2,$(subst _, ,$(OPTR_SPEC)))) $(OPTR_PATH)\operator_CustResDef.h) && \
			(@perl $(MMIDIR)\Customer\replace_project_name.pl $(OPTR_PATH)\operator_CustResDef.h {SEG_NAME} $(strip $(word 3,$(subst _, ,$(OPTR_SPEC)))) $(OPTR_PATH)\operator_CustResDef.h) && \
			(echo $(OPTR_PATH)\operator_CustResDef.tmp >>$(basename $@)_1.lis)
		@if exist $(OPTR_PATH)\ResGenerator_OP_pre.tmp \
			(@perl $(MMIDIR)\Customer\replace_project_name.pl $(OPTR_PATH)\ResGenerator_OP_pre.tmp {OP_BROWSER} $(strip $(BROWSER_SUPPORT)) $(OPTR_PATH)\ResGenerator_OP_pre.bat) && \
			(echo $(OPTR_PATH)\ResGenerator_OP_pre.tmp >>$(basename $@)_1.lis)
    endif
  endif

# copy rule in ResGenerator_XML.bat
ifneq ($(strip $(NEED_COPY_RES_MMI)),)
	@if not exist $(MMIDIR)\Customer\Res_MMI (mkdir $(MMIDIR)\Customer\Res_MMI) else (del /q $(MMIDIR)\Customer\Res_MMI\*.*)
	@tools\strcmpex.exe TRUE TRUE e $(basename $@)_2.lis $(NEED_COPY_RES_MMI)
	@perl tools\lnitem.pl $(basename $@)_2.lis
	@for /f %%i in ($(basename $@)_2.lis) do (copy /y %%i $(MMIDIR)\Customer\Res_MMI\ >NUL)
  ifneq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
	@ren $(MMIDIR)\Customer\Res_MMI\Res_*.* res_*.*
  endif
endif
ifneq ($(strip $(NEED_COPY_CUSTRESOURCE_C)),)
	@tools\strcmpex.exe TRUE TRUE e $(basename $@)_3.lis $(NEED_COPY_CUSTRESOURCE_C)
	@perl tools\lnitem.pl $(basename $@)_3.lis
	@for /f %%i in ($(basename $@)_3.lis) do (copy /y %%i $(MMIDIR)\Customer\CustResource\ >NUL)
endif
ifneq ($(strip $(NEED_COPY_CUSTRESOURCE_H)),)
	@tools\strcmpex.exe TRUE TRUE e $(basename $@)_4.lis $(NEED_COPY_CUSTRESOURCE_H)
	@perl tools\lnitem.pl $(basename $@)_4.lis
	@for /f %%i in ($(basename $@)_4.lis) do (copy /y %%i $(MMIDIR)\MMI\Inc\ >NUL)
endif
ifneq ($(strip $(NEED_COPY_VKV2VKW)),)
#	@echo $(NEED_COPY_VKV2VKW) >>$(basename $@)_1.lis
#	@copy /y $(NEED_COPY_VKV2VKW) $(MMIDIR)\Customer\ResGenerator\ >NUL
endif
ifneq ($(strip $(NEED_COPY_VKV2EXE)),)
#	@echo $(NEED_COPY_VKV2EXE) >>$(basename $@)_1.lis
#	@copy /y $(NEED_COPY_VKV2EXE) $(MMIDIR)\Customer\ResGenerator\ >NUL
endif

	@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $@)) $(basename $(notdir $@))_\d+\.lis
ifneq ($(AUTO_CHECK_DEBUG),TRUE)
	@if exist $(basename $@)_*.lis del /q $(basename $@)_*.lis
endif

   # mbis time probe
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif
endif

# new_resgen and remake_resgen are merged into resgen_mtk, because the dep file should has an unified name
resgen_mtk: resgen_public
ifeq ($(strip $(RUN_RESGEN_NEW)),TRUE)
$(eval $(call CheckNeedDependTarget,resgen_mtk,pregen_dep))
$(strip $(RULESDIR_TARGET))\pregen_dep\resgen_mtk.det: $(NEED_CHECK_RESGEN_LIST)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'resgen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
  ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	-@echo $@: $?
  endif
  ifeq ($(strip $(call Upper,$(LEVEL))),VENDOR)
		@if exist $(MMIDIR)\VendorApp\DevResource\ResGenerator.bat \
			($(MMIDIR)\VendorApp\DevResource\ResGenerator.bat -t $(CUSTOMER))
  else
		@if exist $(strip $(RULESDIR_TARGET))\resgen.dep (del /q $(strip $(RULESDIR_TARGET))\resgen.dep)
		@if exist $(basename $@)_*.d del /q $(basename $@)_*.d
    ifneq ($(filter $(strip $(ACTION)),new bm_new),)
      # new_resgen
		$(MMIDIR)\Customer\ResGenerator_HW.bat $(MMI_VERSION_BASE) $(CUSTOMER) $(strip $(RESGEN_CMD_OPTION_IME_VERSION)) $(strip $(RESGEN_OPTION_FREETYPE)) $(strip $(POPULATE_ARGUMENT))
    else ifneq ($(filter $(MAKECMDGOALS),new new_modis),)
      # new_resgen
		$(MMIDIR)\Customer\ResGenerator_HW.bat $(MMI_VERSION_BASE) $(CUSTOMER) $(strip $(RESGEN_CMD_OPTION_IME_VERSION)) $(strip $(RESGEN_OPTION_FREETYPE)) $(strip $(POPULATE_ARGUMENT))
    else
      # remake_resgen
		$(MMIDIR)\Customer\ResGenerator_HW.bat $(MMI_VERSION_BASE) $(CUSTOMER) R $(strip $(RESGEN_CMD_OPTION_IME_VERSION)) $(strip $(RESGEN_OPTION_FREETYPE)) $(strip $(POPULATE_ARGUMENT))
    endif
    ifneq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
		@perl tools\pack_dep_gen.pl $(basename $@)_1.d $@ $(MMIDIR)\Customer\ResGenerator\debug\dep ^(common^|resgen)\.dep
		@perl tools\pack_dep_gen.pl $(basename $@)_2.d $@ $(COMPLOGDIR) resgen_font_\w+\.log plutommi\Customer\FontResgen
		@perl tools\pack_dep_gen.pl $(basename $@)_3.d $@ $(COMPLOGDIR) resgen_ref_list_\w+\.log plutommi\Customer\ResGenerator
		@perl tools\pack_dep_gen.pl $(basename $@)_4.d $@ $(COMPLOGDIR) (resgen_mtk_resgenerator_run^|resgen_misc_tool^|resgen_venus_theme_gen)\.log
    else
		@perl tools\pack_dep_gen.pl $(basename $@)_1.d $@ $(MMIDIR)\Customer\ResGenerator\debug\dep resgen\.dep
		@perl tools\pack_dep_gen.pl $(basename $@)_2.d $@ $(MMIDIR)\Customer\ResGenerator (mtk_resgenerator^|resgen_misc_tool)\.log
    endif
		@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $@)) $(basename $(notdir $@))_\d+\.d
ifneq ($(AUTO_CHECK_DEBUG),TRUE)
		@if exist $(basename $@)_*.d del /q $(basename $@)_*.d
endif
		@if exist $(MMIDIR)\Customer\ResGenerator\Debug\dep\resgen.dep (copy /y $(MMIDIR)\Customer\ResGenerator\Debug\dep\resgen.dep $(strip $(RULESDIR_TARGET))\resgen.dep >NUL)
    ifneq ($(strip $(VENDOR)),NONE)
		@for %%i in (bmp2ems.o BMPLoader.o GIFLoader.o ResBytestream.o UCS2.o ImageGetDimension.o FontRes.o) do if exist $(MMIDIR)\Customer\ResGenerator\debug\obj\mtk_resgenerator\%%i copy /y .\debug\obj\mtk_resgenerator\%%i $(MMIDIR)\Customer\VendorApp\ResGenerator\obj\ >NUL
		@if exist $(MMIDIR)\Customer\ResGenerator\custom_option.txt (copy /y /z $(MMIDIR)\Customer\ResGenerator\custom_option.txt $(MMIDIR)\VendorApp\resGenerator\custom_option.txt >NUL)
		@if exist $(MMIDIR)\Customer\ResGenerator\custom_include.txt (copy /y /z $(MMIDIR)\Customer\ResGenerator\custom_include.txt $(MMIDIR)\VendorApp\resGenerator\custom_include.txt >NUL)
    endif
  endif
	@perl -e "print 'resgen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif


# *************************************************************************
# Check Custom Menu Tree
# *************************************************************************
cust_menu_tree_check:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))	
	@perl -e "print 'cust_menu_tree_check START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if exist $(FIXPATH)\MoDIS_VC9\NetSim\get_resname_for_CustMenuTreeID_Out_c.pl \
	if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\CustMenuTreeID_Out.c \
	if exist $(FIXPATH)\$(MMIDIR)\Customer\ResGenerator\menu_resource_usage.txt \
		(perl $(FIXPATH)\MoDIS_VC9\NetSim\get_resname_for_CustMenuTreeID_Out_c.pl $(FIXPATH)\$(MMIDIR)\Customer\CustResource\CustMenuTreeID_Out.c $(FIXPATH)\$(MMIDIR)\Customer\ResGenerator\menu_resource_usage.txt $(FIXPATH)\$(MMIDIR)\Customer\CustResource\owner.txt)

	@if exist $(FIXPATH)\MoDIS_VC9\NetSim\CustMenuTreeOutVerifier.exe \
	if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\CustMenuTree_Out.c \
		($(FIXPATH)\MoDIS_VC9\NetSim\CustMenuTreeOutVerifier.exe $(FIXPATH)\$(MMIDIR)\Customer\CustResource\CustMenuTree_Out.c)

	@if exist $(FIXPATH)\MoDIS_VC9\NetSim\CustMenuTreeOutVerifier_Reporter.pl \
	if exist $(FIXPATH)\MoDIS_VC9\NetSim\CustMenuTreeOutResult.txt \
		(perl $(FIXPATH)\MoDIS_VC9\NetSim\CustMenuTreeOutVerifier_Reporter.pl $(VERNO) $(MMIDIR) $(MMI_BASE) $(CUSTOMER) $(PROJECT))
endif
	@perl -e "print 'cust_menu_tree_check END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


# *************************************************************************
# Check MMI Obj Values
# *************************************************************************
mmi_obj_check: sysgen mmi_feature_check genmoduleinfo
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
ifeq ($(filter BASIC UDVT,$(strip $(call Upper,$(PROJECT)))),)
ifneq ($(filter PLUTO_MMI COSMOS_MMI IOT_MMI,$(strip $(MMI_VERSION))),)
ifneq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'mmi_obj_check START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
  ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@if exist tools\objcheck.pl \
		(perl tools\objcheck.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)))
  else
    ifneq ($(strip $(call Upper,$(LEVEL))),LEVEL2_OBJ)
	@if exist tools\objcheck.pl \
		(perl tools\objcheck.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)))
    endif # ifneq ($(strip $(call Upper,$(LEVEL))),LEVEL2_OBJ)
  endif # ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@perl -e "print 'mmi_obj_check END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif
endif
endif
endif #ifeq ($(strip $(MODIS_CONFIG)),TRUE)


