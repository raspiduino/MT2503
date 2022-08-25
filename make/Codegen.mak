# ---------------------------------------------------------------
# Variable declaration for asngen/asnregen/mcddll_update/umts_gen
# ---------------------------------------------------------------
RUN_ASNGEN := FALSE
RUN_ASNGEN_L4 := FALSE
RUN_ASNREGEN := FALSE
RUN_MCDDLL_UPDATE := FALSE
RUN_MCDDLL_UPDATE_L4 := FALSE
RUN_UMTS_GEN := FALSE
ifeq ($(filter L1S BASIC UDVT,$(strip $(call Upper,$(PROJECT)))),)
  ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
RUN_MCDDLL_UPDATE := TRUE
RUN_ASNGEN := TRUE
    ifeq ($(call Upper,$(strip $(MCD_SUPPORT))),TRUE)
RUN_ASNGEN_L4 := TRUE
RUN_ASNREGEN := TRUE
    endif
    ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
RUN_UMTS_GEN := TRUE
    endif
  else ifneq ($(strip $(call Upper,$(LEVEL))),VENDOR)
    ifneq ($(findstring REL_SUB_PROTOCOL,$(call Upper,$(strip $(RELEASE_PACKAGE)))),)
RUN_MCDDLL_UPDATE = TRUE
RUN_ASNGEN := TRUE
      ifeq ($(call Upper,$(strip $(MCD_SUPPORT))),TRUE)
RUN_ASNGEN_L4 := TRUE
RUN_ASNREGEN := TRUE
      endif
      ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
RUN_UMTS_GEN := TRUE
      endif
    else ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
RUN_MCDDLL_UPDATE_L4 = TRUE
      ifeq ($(call Upper,$(strip $(MCD_SUPPORT))),TRUE)
RUN_ASNGEN_L4 := TRUE
      endif
    endif
  endif
endif

ifneq ($(filter NONE,$(strip $(call Upper,$(PROJECT)))),)
  RUN_MCDDLL_UPDATE := FALSE
  RUN_MCDDLL_UPDATE_L4 := FALSE
endif

# --------------------------------------
# Variable declaration for genmoduleinfo
# --------------------------------------

ifeq ($(strip $(MODIS_CONFIG)),FALSE)
  MODULE_INFO_DIR := $(strip $(TARGDIR))\module
else
  MODULE_INFO_DIR := $(strip $(TARGDIR))\module\MoDIS
endif

COM_DEF_PATH := $(foreach \
    mod,\
    $(COMPLIST),\
    $(if $(filter $($($(mod))),TRUE),\
      $(strip $(MODULE_INFO_DIR))\$($(mod))\$(mod)\$(mod).def,\
      $(strip $(MODULE_INFO_DIR))\$(mod)\$(mod).def\
    )\
  )

# GenModuleInfoList
# function: generate the makfile command for genmoduleinfo
# arguement 1: input module makefile
# arguement 2: output module.lis
define GenModuleInfoList
ifneq ($$(strip $$(AUTO_CHECK_DEPEND)),TRUE)
$(2): FORCE
endif
$(2): $(1) $$(NEED_CHECK_DEPEND_LIST) $$(NEED_CHECK_CODEGEN_LIST) $$(NEED_CHECK_COMP_LIST)
ifeq ($$(strip $$(MODIS_CONFIG)),TRUE)
	@echo setup MoDIS env of $$(basename $$(notdir $(1)))
	@(tools\make.exe -fmake\comp.mak -k -r -R $$(strip $$(CMD_ARGU)) --no-print-directory COMPONENT=$$(basename $$(notdir $(1))) GEN_MODULE_INFO=TRUE setup_env >$$(strip $$(COMPLOGDIR))\MoDIS_setup\$$(basename $$(notdir $(1)))_setEnv_MoDIS.log 2>&1) & \
		(if ERRORLEVEL 1 echo Error: $$(basename $$(notdir $(1))).lis Failed! Please check $$(strip $$(COMPLOGDIR))\MoDIS_setup\$$(basename $$(notdir $(1)))_setEnv_MoDIS.log & exit 1)
else
	@echo Generate $$(basename $$(notdir $(1))) information
	@(tools\make.exe -fmake\comp.mak -k -r -R $$(strip $$(CMD_ARGU)) --no-print-directory COMPONENT=$$(basename $$(notdir $(1))) GEN_MODULE_INFO=TRUE setup_env >$$(strip $$(COMPLOGDIR))\module_info\$$(basename $$(notdir $(1)))_module_info.log 2>&1) & \
		(if ERRORLEVEL 1 echo Error: $$(basename $$(notdir $(1))).lis Failed! Please check $$(strip $$(COMPLOGDIR))\module_info\$$(basename $$(notdir $(1)))_module_info.log & exit 1)
endif
endef

$(foreach argu,$(MODULELIS),\
  $(eval MODULE_NAME := $(subst .lis,,$(argu))) \
  $(eval MODULE_MAKEFILE := $(call CheckNeedCopy,$(foreach dir,$(if $(filter $($($(MODULE_NAME))),TRUE),$($(MODULE_NAME))\$(MODULE_NAME),$(MODULE_NAME)),make\$(dir)\$(MODULE_NAME).mak))) \
  $(eval MODULE_LISTFILE := $(if $(filter $($($(MODULE_NAME))),TRUE),$(strip $(MODULE_INFO_DIR))\$($(MODULE_NAME))\$(MODULE_NAME)\$(MODULE_NAME).def,$(strip $(MODULE_INFO_DIR))\$(MODULE_NAME)\$(MODULE_NAME).def)) \
  $(eval $(call GenModuleInfoList,$(MODULE_MAKEFILE),$(MODULE_LISTFILE))) \
  $(eval $(MODULE_NAME).lis: $(MODULE_LISTFILE)) \
  $(eval $(MODULE_NAME).lib: $(MODULE_MAKEFILE)) \
  $(eval MODULE_MAKEFILE_LIST += $(MODULE_MAKEFILE)) \
)
# var MODULE_MAKEFILE: the real path of module makefile according to ALIAS and MSBB
# var MODULE_LISTFILE: the real path of module.def after genmoduleinfo
# var MODULE_MAKEFILE_LIST: the whole list of all module makefiles used
# phony target $module.lis: to keep backward compatibileity for the interface of MODULELIS=$module.lis
# vpath target $module.lib: module.lib should be built if module makefile is updated
MODULE_NAME :=
MODULE_MAKEFILE :=
MODULE_LISTFILE :=

# -----------------------------
# Variable declaration for cgen
# -----------------------------
TST_DB_TARGET := $(strip $(TST_DB))
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
  BPLGUINFOCUSTOMSRCP = BPLGUInfoCustomAppSrcP_$(strip $(PLATFORM))_$(strip $(CHIP_VER))_$(strip $(PURE_VERNO))
  CODE_GEN_LOG   =  $(strip $(COMPLOGDIR))\codegen.log
else
  BPLGUINFOCUSTOMSRCP = BPGUInfoCustomApp_pc_SrcP
  CODE_GEN_LOG = $(strip $(MODISDIR))\_BUILD_LOG\codegen.log
  CGEN_DEF_FILE = Pc_Cnf
  TST_DB := $(strip $(TSTDIR))\database_modis
endif
CGEN           =  $(strip $(FIXPATH))\tools\Cgen.exe
CGEN_CFG_FILE  =  $(strip $(TST_DB))\cgen.cfg
MMI_SCR_ID_FILE = make\~mmi_scr_id.c
MMI_SCR_ID_DB = $(strip $(TST_DB))\msglog_db\~mmi_scr_id.db
CODE_GEN_LST  =  $(strip $(TST_DB))\codegen.lis
PSTRACE_DB_DIR :=  $(strip $(TST_DB))\pstrace_db

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  TMD_FILES := $(L1_TMD_FILES)
else
  TMD_FILES :=
  ifeq ($(strip $(MTK_SUBSIDIARY)),FALSE)
    COMP_TRACE_DEFS := $(EXISTED_CUS_REL_TRACE_DEFS)
    COMP_TRACE_DEFS += $(NEW_CUS_REL_TRACE_DEFS)
  endif
endif

COMP_TRACE_DEFS_TARGET := $(COMP_TRACE_DEFS)
ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  COMP_TRACE_DEFS := $(foreach trc,$(COMP_TRACE_DEFS_TARGET),$(if $(filter L1%,$(call Upper,$(notdir $(trc)))),,$(trc)))
endif

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifeq ($(MAKELEVEL),0)
  ifneq ($(strip $(SWITCH_FOLDER)),)
    COPY_DB := $(shell copy /y $(TST_DB)\$(strip $(SWITCH_FOLDER))\*.* $(TST_DB)\ >NUL)
    ifneq ($(filter tst ,$(strip $(COMPLIST))),)
      COPY_TRCMOD := $(shell copy /y tst\src\$(strip $(SWITCH_FOLDER))\*.* tst\src\ >NUL)
      COPY_TRCMOD := $(shell copy /y tst\include\$(strip $(SWITCH_FOLDER))\*.* tst\include\ >NUL)
    endif
  endif
  endif #ifeq ($(MAKELEVEL),0)
  BPLGUINFOCUSTOM = $(shell dir $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMPREFIX))* /b)
else
  BPLGUINFOCUSTOM = $(BPLGUINFOCUSTOMPREFIX)_$(strip $(PURE_VERNO))
endif
ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  BPLGUINFOCUSTOM = BPGUInfoCustomApp_pc
endif

ifeq ($(call Upper,$(PROJECT)),L1S)
  ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
    CODEGEN_RESULT = $(strip $(TST_DB))\l1validation_db\BPLVInfo
  endif
else
  ifeq ($(strip $(SPLIT_SYSTEM)),TRUE)
    CODEGEN_RESULT = $(strip $(TST_DB))\BPLGUSplitInfo
  else
    ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
      CODEGEN_RESULT = $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMSRCP))
    else
      CODEGEN_RESULT = $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM))
    endif
  endif
endif

GV_FILES := $(subst /,\,$(wildcard $(subst \,/,$(strip $(TST_DB)))/gv/*.gv))
ifneq ($(strip $(AST_SUPPORT)),NONE)
  AST_TMD_FILES = $(AST_L1_TMD_FILES)
endif

CODEGEN_DEPENDENCY :=
# CODEGEN_DATABASE_OUT is the output file name of cgen database
# TODO: CODEGEN_RESULT <=> CODEGEN_DATABASE_OUT
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  ifneq ($(call Upper,$(PROJECT)),L1S)
    CODEGEN_DATABASE_OUT = $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM))
  else
    CODEGEN_DATABASE_OUT = $(strip $(TST_DB))\l1validation_db\BPLVInfo
  endif
else
    CODEGEN_DATABASE_OUT = $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMSRCP))
endif
# CODEGEN_DATABASE_IN is the input file name of cgen database
ifneq ($(call Upper,$(PROJECT)),L1S)
  ifneq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
    CODEGEN_DATABASE_IN = $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM))
  else ifeq ($(wildcard $(CODEGEN_DATABASE_OUT)),)
    CODEGEN_DATABASE_IN = $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM))
  else
    # remake with cgen should use generated database first after custom release, so as not to restore unchanged data to the default in full database
    CODEGEN_DATABASE_IN = $(CODEGEN_DATABASE_OUT)
  endif
else
    CODEGEN_DATABASE_IN = $(strip $(TST_DB))\l1validation_db\BPLVInfo
endif

CODEGEN_PREPROCESS := $(strip $(RULESDIR))\codegen_dep\cgen_src.det
ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
  ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
        CODEGEN_DEPENDENCY += $(strip $(RULESDIR))\codegen_dep\cgen_c.det
        CODEGEN_DEPENDENCY += $(strip $(RULESDIR))\codegen_dep\cgen_l1.det
        CODEGEN_DEPENDENCY += $(strip $(RULESDIR))\codegen_dep\cgen_gv.det
        CODEGEN_PREPROCESS += $(strip $(RULESDIR))\codegen_dep\pri.det
        CODEGEN_PREPROCESS += $(strip $(RULESDIR))\codegen_dep\gv_db.det
        CODEGEN_PREPROCESS += $(strip $(RULESDIR))\codegen_dep\cgen_src.det
    ifneq ($(call Upper,$(PROJECT)),L1S)
        CODEGEN_DEPENDENCY += $(strip $(RULESDIR))\codegen_dep\cgen_un.det
        CODEGEN_DEPENDENCY += $(strip $(RULESDIR))\codegen_dep\cgen_cm.det
        CODEGEN_DEPENDENCY += $(strip $(RULESDIR))\codegen_dep\cgen_ap.det
        CODEGEN_DEPENDENCY += $(strip $(RULESDIR))\codegen_dep\cgen_ps.det
      ifeq ($(strip $(MODIS_CONFIG)),FALSE)
        CODEGEN_DEPENDENCY += $(strip $(RULESDIR))\codegen_dep\cgen_filter_gen.det
        CODEGEN_PREPROCESS += $(strip $(RULESDIR))\codegen_dep\log2SD_Catcher_filters.det
      else
        ifneq ($(filter TST_FILE_DEFAULT_CATCHER_FILTER.C,$(strip $(call Upper,$(notdir $(wildcard custom/tst/*.c))))),)
          # exist custom\tst\tst_file_default_Catcher_filter.c, will skip in -puremodis
        else
          CODEGEN_DEPENDENCY += $(strip $(RULESDIR))\codegen_dep\cgen_filter_gen.det
        endif
        ifneq ($(filter LOG2SD_CATCHER_FILTERS.INI,$(strip $(call Upper,$(notdir $(wildcard $(subst \,/,$(strip $(TSTDIR))\database\*.ini)))))),)
          # exist tst\database\log2SD_Catcher_filters.ini, will skip in -puremodis
        else
          CODEGEN_PREPROCESS += $(strip $(RULESDIR))\codegen_dep\log2SD_Catcher_filters.det
        endif
      endif
        CODEGEN_PREPROCESS += $(strip $(RULESDIR))\codegen_dep\app_pri.det
        CODEGEN_PREPROCESS += $(strip $(RULESDIR))\codegen_dep\custom_pri.det
        CODEGEN_PREPROCESS += $(strip $(RULESDIR))\codegen_dep\unionTag_parse.det
    else
      ifeq ($(strip $(MODIS_CONFIG)),FALSE)
        CODEGEN_DEPENDENCY += $(strip $(RULESDIR))\codegen_dep\cgen_ps.det
        CODEGEN_DEPENDENCY += $(strip $(RULESDIR))\codegen_dep\cgen_l1v.det
        CODEGEN_PREPROCESS += $(strip $(RULESDIR))\codegen_dep\l1v_db.det
      endif
    endif
  else
    ifneq ($(call Upper,$(PROJECT)),L1S)
        CODEGEN_DEPENDENCY += $(strip $(RULESDIR))\codegen_dep\cgen_cm.det
        CODEGEN_PREPROCESS += $(strip $(RULESDIR))\codegen_dep\custom_pri.det
      ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
        CODEGEN_DEPENDENCY += $(strip $(RULESDIR))\codegen_dep\cgen_ap.det
        CODEGEN_PREPROCESS += $(strip $(RULESDIR))\codegen_dep\app_pri.det
      endif
      ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
      ifneq ($(strip $(AST_SUPPORT)),NONE)
        CODEGEN_DEPENDENCY += $(strip $(RULESDIR))\codegen_dep\cgen_l1.det
      endif
      endif
        CODEGEN_DEPENDENCY += $(strip $(RULESDIR))\codegen_dep\cgen_ps.det
        CODEGEN_PREPROCESS += $(strip $(RULESDIR))\codegen_dep\cgen_src.det
      ifeq ($(strip $(MODIS_CONFIG)),FALSE)
        CODEGEN_DEPENDENCY += $(strip $(RULESDIR))\codegen_dep\cgen_filter_gen.det
        CODEGEN_PREPROCESS += $(strip $(RULESDIR))\codegen_dep\log2SD_Catcher_filters.det
      else
        ifneq ($(filter TST_FILE_DEFAULT_CATCHER_FILTER.C,$(strip $(call Upper,$(notdir $(wildcard custom/tst/*.c))))),)
          # exist custom\tst\tst_file_default_Catcher_filter.c, will skip in -puremodis
        else
          CODEGEN_DEPENDENCY += $(strip $(RULESDIR))\codegen_dep\cgen_filter_gen.det
        endif
        ifneq ($(filter LOG2SD_CATCHER_FILTERS.INI,$(strip $(call Upper,$(notdir $(wildcard $(subst \,/,$(strip $(TSTDIR))\database\*.ini)))))),)
          # exist tst\database\log2SD_Catcher_filters.ini, will skip in -puremodis
        else
          CODEGEN_PREPROCESS += $(strip $(RULESDIR))\codegen_dep\log2SD_Catcher_filters.det
        endif
      endif
    else
        CODEGEN_DEPENDENCY :=
    endif
  endif
        CODEGEN_PREPROCESS += $(strip $(RULESDIR))\codegen_dep\codegen_single.det
else
        CODEGEN_DEPENDENCY :=
endif


# CgenPreprocess
# function: generate the makfile command for cgen preprocess
# arguement 1: input source file to be preprocessed
# arguement 2: output preprocessed result
# arguement 3: output dependency file name, file path for cgen should be always r\codegen_dep
define CgenPreprocess
ifneq ($$(strip $$(AUTO_CHECK_CGEN)),TRUE)
  $$(strip $$(RULESDIR))\codegen_dep\$(3): FORCE
else
  -include $$(strip $$(RULESDIR))\codegen_dep\.\$(3)
endif
$$(strip $$(RULESDIR))\codegen_dep\$(3): $(1) $$(NEED_CHECK_DEPEND_LIST) $$(NEED_CHECK_CODEGEN_LIST)
ifeq ($$(filter $$(MAKECMDGOALS),cgen_preprocess),)
	@if /I "$$(strip $$(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$$@,T,'. time . \"\n\"";>>$$(MBIS_BUILD_TIME_TMP))
endif
ifeq ($$(strip $$(AUTO_CHECK_CGEN)),TRUE)
	-@echo $$@: $$?
endif
	@echo Preprocessing $(1) ...
	@if not exist $$(patsubst %\,%,$$(dir $(2))) mkdir $$(patsubst %\,%,$$(dir $(2)))
	@if not exist make\~inc_def.tmp tools\make.exe -fmake\gsm2.mak -r -R --no-print-directory make\~inc_def.tmp
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@($$(CC) -E -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $$(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(2) $(1) 2>$$(basename $$@).log) & \
		(if ERRORLEVEL 1 (type $$(basename $$@).log >>$$(CODE_GEN_LOG)) & (exit 1))
	@($$(CC) -M -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $$(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $$@ $(1) --no_depend_system_headers $$(DEPEND) $$(basename $$@).d) & \
		(if ERRORLEVEL 1 exit 1)
	@perl tools\pack_dep_gen.pl $$@ $$@ $$(patsubst %\,%,$$(dir $$@)) $$(basename $$(notdir $$@))\.d
	@if exist $$(basename $$@).d del $$(basename $$@).d
else
	@(cl.exe /E /w /DGEN_FOR_CPARSER /DGEN_FOR_PC /USTDC_HEADERS /nologo /showIncludes @make\~inc_def.tmp $(1) >$(2) 2>$$(basename $$@).log) & \
		(if ERRORLEVEL 1 (type $$(basename $$@).log >>$$(CODE_GEN_LOG)) & (exit 1))
	@echo Note: including file: $(1) >>$$(basename $$@).log
	@perl tools\pack_dep_gen.pl $$@ $$@ $$(patsubst %\,%,$$(dir $$@)) $$(basename $$(notdir $$@))\.log
endif
	@if exist $$(basename $$@).log del /q $$(basename $$@).log
ifeq ($$(filter $$(MAKECMDGOALS),cgen_preprocess),)
	@echo $$@ >>$$(CODE_GEN_LST)
	@echo $(2) >>$$(CODE_GEN_LST)
	@if /I "$$(strip $$(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$$@,T,'. time . \"\n\"";>>$$(MBIS_BUILD_TIME_TMP))
endif
endef


# *************************************************************************
#  Tools code preprocess and generation
# *************************************************************************
ifeq ($(strip $(ACTION)),slim_codegen)
  ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
slim_codegen: cleancodegen asngen umts_gen codegen asnregen cleanbin send
  else
slim_codegen: cleancodegen asngen codegen asnregen cleanbin send
  endif
	@echo Done.
else
  ## codegen
  ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
code_generate: cleancodegen asngen umts_gen codegen asnregen cleanbin mcddll_update send
  else
code_generate: cleancodegen asngen codegen asnregen cleanbin mcddll_update send
  endif
	@echo Done.
endif


codegen : ss_lcs_gen gencustominfo operator_check gencustomlists xml_parser nvram_edit_h_gen nvram_auto_gen genmoduleinfo cgen


# ---------------------------------------
# 3G Codegen Gen Files: ASN and DBME
# ---------------------------------------
umts_gen:
ifeq ($(RUN_UMTS_GEN),TRUE)
$(eval $(call CheckNeedDepend,umts_gen,pregen_dep))
$(strip $(RULESDIR))\pregen_dep\umts_gen.det: $(NEED_CHECK_CODEGEN_LIST)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	-@echo $@: $?
endif
    # backup files because they are touched again by umts_gen in both Target and MoDIS
	@if not exist $(strip $(UAS_FOLDER))\urr\dbme\include_bak (mkdir $(strip $(UAS_FOLDER))\urr\dbme\include_bak) else (if exist $(strip $(UAS_FOLDER))\urr\dbme\include_bak\*.* del /q $(strip $(UAS_FOLDER))\urr\dbme\include_bak\*.*)
	@if exist $(strip $(UAS_FOLDER))\urr\dbme\include\*.h copy /y $(strip $(UAS_FOLDER))\urr\dbme\include\*.h $(strip $(UAS_FOLDER))\urr\dbme\include_bak\ >NUL
	@if not exist $(strip $(UAS_FOLDER))\urr\dbme\src_bak (mkdir $(strip $(UAS_FOLDER))\urr\dbme\src_bak) else (if exist $(strip $(UAS_FOLDER))\urr\dbme\src_bak\*.* del /q $(strip $(UAS_FOLDER))\urr\dbme\src_bak\*.*)
	@if exist $(strip $(UAS_FOLDER))\urr\dbme\src\*.c copy /y $(strip $(UAS_FOLDER))\urr\dbme\src\*.c $(strip $(UAS_FOLDER))\urr\dbme\src_bak\ >NUL
	@if not exist $(strip $(UAS_FOLDER))\asn1\gen\include_bak (mkdir $(strip $(UAS_FOLDER))\asn1\gen\include_bak) else (if exist $(strip $(UAS_FOLDER))\asn1\gen\include_bak\*.* del /q $(strip $(UAS_FOLDER))\asn1\gen\include_bak\*.*)
	@if exist $(strip $(UAS_FOLDER))\asn1\gen\include\*.h copy /y $(strip $(UAS_FOLDER))\asn1\gen\include\*.h $(strip $(UAS_FOLDER))\asn1\gen\include_bak\ >NUL
	@if not exist $(strip $(UAS_FOLDER))\asn1\gen\src_bak (mkdir $(strip $(UAS_FOLDER))\asn1\gen\src_bak) else (if exist $(strip $(UAS_FOLDER))\asn1\gen\src_bak\*.* del /q $(strip $(UAS_FOLDER))\asn1\gen\src_bak\*.*)
	@if exist $(strip $(UAS_FOLDER))\asn1\gen\src\*.c copy /y $(strip $(UAS_FOLDER))\asn1\gen\src\*.c $(strip $(UAS_FOLDER))\asn1\gen\src_bak\ >NUL
	@if not exist $(strip $(PS_FOLDER))\mcddll\include_bak (mkdir $(strip $(PS_FOLDER))\mcddll\include_bak) else (if exist $(strip $(PS_FOLDER))\mcddll\include_bak\*.* del /q $(strip $(PS_FOLDER))\mcddll\include_bak\*.*)
	@if exist $(strip $(PS_FOLDER))\mcddll\include\*.h copy /y $(strip $(PS_FOLDER))\mcddll\include\*.h $(strip $(PS_FOLDER))\mcddll\include_bak\ >NUL
	@if not exist $(strip $(PS_FOLDER))\mcddll\src_bak (mkdir $(strip $(PS_FOLDER))\mcddll\src_bak) else (if exist $(strip $(PS_FOLDER))\mcddll\src_bak\*.* del /q $(strip $(PS_FOLDER))\mcddll\src_bak\*.*)
	@if exist $(strip $(PS_FOLDER))\mcddll\src\*.c copy /y $(strip $(PS_FOLDER))\mcddll\src\*.c $(strip $(PS_FOLDER))\mcddll\src_bak\ >NUL

  ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@(cd $(strip $(UAS_FOLDER))) && \
	(perl uas_generate.pl --CC=$(CC) --feature=" $(UMTS_RELEASE_SUPPORT) $(UMTS_MODE_SUPPORT) $(ULCS_ASN_SUPPORT_VERSION) $(REMOVE_DEBUG_INFO) " --deffile="..\$(INFOLOG)" 2>..\$(basename $@).log)
  else
	@(cd $(strip $(UAS_FOLDER))) && \
	(perl uas_generate.pl --CC="cl" --feature=" $(UMTS_RELEASE_SUPPORT) $(UMTS_MODE_SUPPORT) $(ULCS_ASN_SUPPORT_VERSION) MoDIS " --deffile="..\$(INFOLOG_MODIS)" 2>..\$(basename $@).log)
  endif

    # restore files if not changed in order to keep orginal timestamp
	@if exist $(strip $(UAS_FOLDER))\urr\dbme\include_bak\*.h for %%i in ($(strip $(UAS_FOLDER))\urr\dbme\include_bak\*.h) do ((fc $(strip $(UAS_FOLDER))\urr\dbme\include\%%~nxi $(strip $(UAS_FOLDER))\urr\dbme\include_bak\%%~nxi >NUL 2>&1) & (if not errorlevel 1 (copy /y $(strip $(UAS_FOLDER))\urr\dbme\include_bak\%%~nxi $(strip $(UAS_FOLDER))\urr\dbme\include\ >NUL) else (echo %%~nxi is updated)))
	@if exist $(strip $(UAS_FOLDER))\urr\dbme\include_bak rd /s /q $(strip $(UAS_FOLDER))\urr\dbme\include_bak
	@if exist $(strip $(UAS_FOLDER))\urr\dbme\src_bak\*.c for %%i in ($(strip $(UAS_FOLDER))\urr\dbme\src_bak\*.c) do ((fc $(strip $(UAS_FOLDER))\urr\dbme\src\%%~nxi $(strip $(UAS_FOLDER))\urr\dbme\src_bak\%%~nxi >NUL 2>&1) & (if not errorlevel 1 (copy /y $(strip $(UAS_FOLDER))\urr\dbme\src_bak\%%~nxi $(strip $(UAS_FOLDER))\urr\dbme\src\ >NUL) else (echo %%~nxi is updated)))
	@if exist $(strip $(UAS_FOLDER))\urr\dbme\src_bak rd /s /q $(strip $(UAS_FOLDER))\urr\dbme\src_bak
	@if exist $(strip $(UAS_FOLDER))\asn1\gen\include_bak\*.h for %%i in ($(strip $(UAS_FOLDER))\asn1\gen\include_bak\*.h) do ((fc $(strip $(UAS_FOLDER))\asn1\gen\include\%%~nxi $(strip $(UAS_FOLDER))\asn1\gen\include_bak\%%~nxi >NUL 2>&1) & (if not errorlevel 1 (copy /y $(strip $(UAS_FOLDER))\asn1\gen\include_bak\%%~nxi $(strip $(UAS_FOLDER))\asn1\gen\include\ >NUL) else (echo %%~nxi is updated)))
	@if exist $(strip $(UAS_FOLDER))\asn1\gen\include_bak rd /s /q $(strip $(UAS_FOLDER))\asn1\gen\include_bak
	@if exist $(strip $(UAS_FOLDER))\asn1\gen\src_bak\*.c for %%i in ($(strip $(UAS_FOLDER))\asn1\gen\src_bak\*.c) do ((fc $(strip $(UAS_FOLDER))\asn1\gen\src\%%~nxi $(strip $(UAS_FOLDER))\asn1\gen\src_bak\%%~nxi >NUL 2>&1) & (if not errorlevel 1 (copy /y $(strip $(UAS_FOLDER))\asn1\gen\src_bak\%%~nxi $(strip $(UAS_FOLDER))\asn1\gen\src\ >NUL) else (echo %%~nxi is updated)))
	@if exist $(strip $(UAS_FOLDER))\asn1\gen\src_bak rd /s /q $(strip $(UAS_FOLDER))\asn1\gen\src_bak
	@if exist $(strip $(PS_FOLDER))\mcddll\include_bak\*.h for %%i in ($(strip $(PS_FOLDER))\mcddll\include_bak\*.h) do ((fc $(strip $(PS_FOLDER))\mcddll\include\%%~nxi $(strip $(PS_FOLDER))\mcddll\include_bak\%%~nxi >NUL 2>&1) & (if not errorlevel 1 (copy /y $(strip $(PS_FOLDER))\mcddll\include_bak\%%~nxi $(strip $(PS_FOLDER))\mcddll\include\ >NUL) else (echo %%~nxi is updated)))
	@if exist $(strip $(PS_FOLDER))\mcddll\include_bak rd /s /q $(strip $(PS_FOLDER))\mcddll\include_bak
	@if exist $(strip $(PS_FOLDER))\mcddll\src_bak\*.c for %%i in ($(strip $(PS_FOLDER))\mcddll\src_bak\*.c) do ((fc $(strip $(PS_FOLDER))\mcddll\src\%%~nxi $(strip $(PS_FOLDER))\mcddll\src_bak\%%~nxi >NUL 2>&1) & (if not errorlevel 1 (copy /y $(strip $(PS_FOLDER))\mcddll\src_bak\%%~nxi $(strip $(PS_FOLDER))\mcddll\src\ >NUL) else (echo %%~nxi is updated)))
	@if exist $(strip $(PS_FOLDER))\mcddll\src_bak rd /s /q $(strip $(PS_FOLDER))\mcddll\src_bak

	@perl tools\pack_dep_gen.pl $(basename $@).d $@ $(strip $(UAS_FOLDER))\tools asn1_\w+\.log $(strip $(UAS_FOLDER))\tools
	@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $@)) $(basename $(notdir $@))\.\w+
	@if exist $(basename $@).log del /q $(basename $@).log
	@if exist $(basename $@).d del /q $(basename $@).d
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif


# ---------------------------------------
# SS LCS Codegen Gen Files: ASN
# ---------------------------------------
ss_lcs_gen:
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
$(eval $(call CheckNeedDependTarget,ss_lcs_gen,pregen_dep))
$(strip $(RULESDIR_TARGET))\pregen_dep\ss_lcs_gen.det: $(NEED_CHECK_CODEGEN_LIST)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	-@echo $@: $?
endif
	@if not exist $(strip $(PS_FOLDER))\l4\csm\ss\asn1\gen\include_bak (mkdir $(strip $(PS_FOLDER))\l4\csm\ss\asn1\gen\include_bak) else (if exist $(strip $(PS_FOLDER))\l4\csm\ss\asn1\gen\include_bak\*.* del /q $(strip $(PS_FOLDER))\l4\csm\ss\asn1\gen\include_bak\*.*)
	@if exist $(strip $(PS_FOLDER))\l4\csm\ss\asn1\gen\include\*.h copy /y $(strip $(PS_FOLDER))\l4\csm\ss\asn1\gen\include\*.h $(strip $(PS_FOLDER))\l4\csm\ss\asn1\gen\include_bak\ >NUL
	@(cd $(strip $(PS_FOLDER))\l4\csm\ss\tools) && \
		(call ss_lcs_generate.bat) && \
		(cd ..\..\..\..\..)
	@if exist $(strip $(PS_FOLDER))\l4\csm\ss\asn1\gen\include_bak\*.h for %%i in ($(strip $(PS_FOLDER))\l4\csm\ss\asn1\gen\include_bak\*.h) do ((fc $(strip $(PS_FOLDER))\l4\csm\ss\asn1\gen\include\%%~nxi $(strip $(PS_FOLDER))\l4\csm\ss\asn1\gen\include_bak\%%~nxi >NUL 2>&1) & (if not errorlevel 1 (copy /y $(strip $(PS_FOLDER))\l4\csm\ss\asn1\gen\include_bak\%%~nxi $(strip $(PS_FOLDER))\l4\csm\ss\asn1\gen\include\ >NUL) else (echo %%~nxi is updated)))
	@if exist $(strip $(PS_FOLDER))\l4\csm\ss\asn1\gen\include_bak rd /s /q $(strip $(PS_FOLDER))\l4\csm\ss\asn1\gen\include_bak
	@perl tools\pack_dep_gen.pl $@ $@ $(strip $(PS_FOLDER))\l4\csm\ss\tools asn1_ss_lcs\.log $(strip $(PS_FOLDER))\l4\csm\ss\tools
	@echo $@: $(strip $(PS_FOLDER))\l4\csm\ss\tools\ss_lcs_generate.bat $(strip $(PS_FOLDER))\l4\csm\ss\tools\asn1_ss_lcs.bat >>$@
	@if exist $(basename $@).log del /q $(basename $@).log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif


# ---------------------------------------
# MCDDLL update
# ---------------------------------------
IDB_PARSER_EXE := tools\IDB_Parser\IDB_Parser.exe
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
  RUN_MCDDLL_UPDATE_INPUT := $(strip $(PS_FOLDER))\mcddll\Release\*.idb
else
  RUN_MCDDLL_UPDATE_INPUT := $(strip $(PS_FOLDER))\mcddll\MoDIS_Release\*.idb
endif

mcddll_update:
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
  ifeq ($(strip $(ACTION)),slim_mcddll)
slim_mcddll:
  else
mcddll_update: codegen
  endif
endif
ifneq ($(filter TRUE,$(RUN_MCDDLL_UPDATE) $(RUN_MCDDLL_UPDATE_L4)),)
slim_mcddll: $(strip $(RULESDIR))\pregen_dep\mcddll_update.det
mcddll_update: $(strip $(RULESDIR))\pregen_dep\mcddll_update.det
$(eval $(call CheckNeedDepend,mcddll_update,pregen_dep))
$(strip $(RULESDIR))\pregen_dep\mcddll_update.det: $(VERNOFILE) $(NEED_CHECK_CODEGEN_LIST)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'mcddll_update START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	-@echo $@: $?
endif
	@if not exist $(COMPLOGDIR) (mkdir $(COMPLOGDIR))
	@tools\strcmpex.exe def def e make\~def.tmp $(foreach def,$(sort $(COM_DEFS)),$(def))
	@tools\strcmpex.exe inc inc e make\~mcddll_inc.tmp $(foreach inc,$(XGEN_INC_DIR),$(inc))
	@perl tools\lnitem.pl make\~def.tmp
	@perl tools\lnitem.pl make\~mcddll_inc.tmp

	@(echo [ COMMON OPTION ]> $(MCDDLL_INFOLOG)) && \
		(type make\~def.tmp >> $(MCDDLL_INFOLOG))
	@(echo [ COMMON INCLUDE PATH ] >> $(MCDDLL_INFOLOG)) && \
		(type make\~mcddll_inc.tmp >> $(MCDDLL_INFOLOG))
	@if exist $(MCDDLL_INFOLOG) \
		(if exist $(strip $(PS_FOLDER))\mcddll (copy /y $(MCDDLL_INFOLOG) $(strip $(PS_FOLDER))\mcddll > nul))

ifeq ($(strip $(RUN_MCDDLL_UPDATE)),TRUE)
  ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@(cd $(strip $(PS_FOLDER))\mcddll) && \
	(perl updatemcddll_msvc.pl $(call Upper,$(strip $(PROJECT))) $(strip $(VERNO)) $(strip $(PLATFORM))_$(strip $(CHIP_VER)) 2>..\..\$(MCDDLL_UPDATE_LOG))
  else
	@(cd $(strip $(PS_FOLDER))\mcddll) && \
	(perl updatemcddll_msvc.pl $(call Upper,$(strip $(PROJECT))) MoDIS $(strip $(VERNO)) 2>..\..\$(MCDDLL_UPDATE_LOG))
  endif
else ifeq ($(strip $(RUN_MCDDLL_UPDATE_L4)),TRUE)
  ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@(cd $(strip $(PS_FOLDER))\mcddll) && \
	(perl updatemcddll_msvc.pl $(call Upper,$(strip $(PROJECT))) -L4 $(strip $(VERNO)) $(strip $(PLATFORM))_$(strip $(CHIP_VER)) 2>..\..\$(MCDDLL_UPDATE_LOG))
  else
	@(cd $(strip $(PS_FOLDER))\mcddll) && \
	(perl updatemcddll_msvc.pl $(call Upper,$(strip $(PROJECT))) MoDIS -L4 $(strip $(VERNO)) 2>..\..\$(MCDDLL_UPDATE_LOG))
  endif
endif
	@copy /y $(strip $(PS_FOLDER))\mcddll\mcddll.dll $(strip $(TST_DB))\mcddll.dll >nul

	@if exist $(RUN_MCDDLL_UPDATE_INPUT) for %%i in ($(RUN_MCDDLL_UPDATE_INPUT)) do ($(IDB_PARSER_EXE) +p %%i >>$(MCDDLL_UPDATE_LOG))
	@if exist $(subst /,\,$(PROJDIR))\modem\mcddll\*.idb for %%i in ($(subst /,\,$(PROJDIR))\modem\mcddll\*.idb) do ($(IDB_PARSER_EXE) +p %%i >>$(MCDDLL_UPDATE_LOG))
	@echo [Dependency] $(strip $(PS_FOLDER))\mcddll\updatemcddll_msvc.pl $(IDB_PARSER_EXE) $(VERNOFILE) >>$(MCDDLL_UPDATE_LOG)
	@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $(MCDDLL_UPDATE_LOG))) $(basename $(notdir $(MCDDLL_UPDATE_LOG)))\.log

	@perl -e "print 'mcddll_update END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif


# -----------------------------
# Asn Gen Files
# -----------------------------
asngen_l4: gen_infolog
ifeq ($(RUN_ASNGEN_L4),TRUE)
$(eval $(call CheckNeedDependTarget,asngen_l4,pregen_dep))
$(strip $(RULESDIR_TARGET))\pregen_dep\asngen.det: $(strip $(RULESDIR_TARGET))\pregen_dep\asngen_l4.det
$(strip $(RULESDIR_TARGET))\pregen_dep\asngen_l4.det: $(NEED_CHECK_CODEGEN_LIST)
ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	-@echo $@: $?
endif
    # To generate ps\interfaces\asn\l4\gen_mcd_l4_common.asn
	@if not exist $(patsubst %\,%,$(dir $@)) mkdir $(patsubst %\,%,$(dir $@))
	@perl $(strip $(PS_FOLDER))\tools\pre_mcdparser.pl $(CC) $(foreach def,$(MCD_DEFS),-D$(def)) 2>$(basename $@).log
	@echo Generate L4 ASN Gen Files 1st Phase ...
	@(cd $(strip $(PS_FOLDER))\tools) && \
		(perl mcdparser.pl mcd_l4.ini --only=$(call lc,$(PROJECT)) --deffile="..\..\$(INFOLOG)" 2>>..\..\$(basename $@).log) && \
		(cd ..\..)
	@(fc $(strip $(PS_FOLDER))\interfaces\mcd\include\mcd_l4_common.h interface\ps\local_inc\mcd_l4_common.h >NUL 2>&1) & (if errorlevel 1 (MOVE /Y $(strip $(PS_FOLDER))\interfaces\mcd\include\mcd_l4_common.h interface\ps\local_inc\ >NUL) else (del /q $(strip $(PS_FOLDER))\interfaces\mcd\include\mcd_l4_common.h))
	@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $@)) $(basename $(notdir $@))\.log
ifneq ($(AUTO_CHECK_DEBUG),TRUE)
	@if exist $(basename $@).log del /q $(basename $@).log
endif
endif


asngen: gen_infolog
# asngen_l4
ifeq ($(RUN_ASNGEN),TRUE)
$(eval $(call CheckNeedDependTarget,asngen,pregen_dep))
$(strip $(RULESDIR_TARGET))\pregen_dep\asngen.det: $(NEED_CHECK_CODEGEN_LIST)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'asngen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	-@echo $@: $?
endif
  ifeq ($(call Upper,$(strip $(MCD_SUPPORT))),TRUE)
		@echo Generate ASN Gen Files 1st Phase ...
		@if not exist $(strip $(PS_FOLDER))\gen mkdir $(strip $(PS_FOLDER))\gen
		@(cd $(strip $(PS_FOLDER))\tools) && \
		(perl mcdparser.pl mcd.ini --only=$(call lc,$(PROJECT)) --deffile="..\..\$(INFOLOG)" 2>..\..\$(basename $@).log) && \
		(cd ..\..)
		@(fc $(strip $(PS_FOLDER))\interfaces\mcd\include\mcd_l3_inc_gprs_struct.h interface\ps\local_inc\mcd_l3_inc_gprs_struct.h >NUL 2>&1) & (if errorlevel 1 (MOVE /Y $(strip $(PS_FOLDER))\interfaces\mcd\include\mcd_l3_inc_gprs_struct.h interface\ps\local_inc\ >NUL) else (del /q $(strip $(PS_FOLDER))\interfaces\mcd\include\mcd_l3_inc_gprs_struct.h))
  else
		@echo Generate ASN Gen Files ...
		@(cd $(strip $(PS_FOLDER))) && \
			(call generate.bat 2>..\$(basename $@).log)
		@echo [Dependency] $(strip $(PS_FOLDER))\generate.bat >>$(basename $@).log
		@echo Generate ASN Gen Files Done ...
  endif

	@echo Compiling Csi ASN files...
	@(cd $(strip $(PS_FOLDER))\scsi\gen) && \
		(perl scsi_generate.pl --CC=$(CC) --feature=" $(UMTS_RELEASE_SUPPORT) $(UMTS_MODE_SUPPORT) " 2>>..\..\..\$(basename $@).log)
	@perl tools\pack_dep_gen.pl $(basename $@).d $@ $(strip $(PS_FOLDER))\scsi\gen \w+\.log $(strip $(PS_FOLDER))\scsi\gen
	@echo Compilation Csi ASN files done ...

	@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $@)) $(basename $(notdir $@))\.(log^|d)
ifneq ($(AUTO_CHECK_DEBUG),TRUE)
	@if exist $(basename $@).log del /q $(basename $@).log
	@if exist $(basename $@).d del /q $(basename $@).d
endif
	@perl -e "print 'asngen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif


asnregen: gen_infolog
ifeq ($(RUN_ASNREGEN),TRUE)
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
$(strip $(RULESDIR))\pregen_dep\mcddll_update.det: $(strip $(RULESDIR_TARGET))\pregen_dep\asnregen.det
endif
$(eval $(call CheckNeedDependTarget,asnregen,pregen_dep))
$(strip $(RULESDIR_TARGET))\pregen_dep\asnregen.det: $(NEED_CHECK_CODEGEN_LIST)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'asnregen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	-@echo $@: $?
endif
	@echo Generate ASN Gen Files 2nd Phase ...
	@if not exist $(strip $(PS_FOLDER))\interfaces\mcd\include_bak (mkdir $(strip $(PS_FOLDER))\interfaces\mcd\include_bak) else (if exist $(strip $(PS_FOLDER))\interfaces\mcd\include_bak\*.* del /q $(strip $(PS_FOLDER))\interfaces\mcd\include_bak\*.*)
	@if exist $(strip $(PS_FOLDER))\interfaces\mcd\include\*.h copy /y $(strip $(PS_FOLDER))\interfaces\mcd\include\*.h $(strip $(PS_FOLDER))\interfaces\mcd\include_bak\ >NUL
  ifeq ($(strip $(MODIS_CONFIG)),TRUE)
    ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@if not exist $(strip $(TST_DB_TARGET))\enumFile if exist $(strip $(TST_DB))\enumFile copy /y $(strip $(TST_DB))\enumFile $(strip $(TST_DB_TARGET))\ >NUL
    else
	@if not exist $(strip $(TST_DB_TARGET))\enumFileCustomAppSrc if exist $(strip $(TST_DB))\enumFileCustomAppSrc copy /y $(strip $(TST_DB))\enumFileCustomAppSrc $(strip $(TST_DB_TARGET))\ >NUL
    endif
  endif
  ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@(cd $(strip $(PS_FOLDER))\tools) && \
		(perl mcdparser.pl mcd.ini  --only=$(call lc,$(PROJECT)) --only=for_catcher --deffile="..\..\$(INFOLOG)" 2>..\..\$(basename $@).log)
  else
	@(cd $(strip $(PS_FOLDER))\tools) && \
		(perl mcdparser.pl mcd.ini  --only=$(call lc,$(PROJECT)) --only=for_catcher --deffile="..\..\$(INFOLOG)" --custom 2>..\..\$(basename $@).log)
  endif
	@if exist $(strip $(PS_FOLDER))\interfaces\mcd\include_bak\*.h for %%i in ($(strip $(PS_FOLDER))\interfaces\mcd\include_bak\*.h) do ((fc $(strip $(PS_FOLDER))\interfaces\mcd\include\%%~nxi $(strip $(PS_FOLDER))\interfaces\mcd\include_bak\%%~nxi >NUL 2>&1) & (if not errorlevel 1 (copy /y $(strip $(PS_FOLDER))\interfaces\mcd\include_bak\%%~nxi $(strip $(PS_FOLDER))\interfaces\mcd\include\ >NUL) else (echo %%~nxi is updated)))
	@if exist $(strip $(PS_FOLDER))\interfaces\mcd\include_bak rd /s /q $(strip $(PS_FOLDER))\interfaces\mcd\include_bak

	@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $@)) $(basename $(notdir $@))\.log
ifneq ($(AUTO_CHECK_DEBUG),TRUE)
	@if exist $(basename $@).log del /q $(basename $@).log
endif
	@perl -e "print 'asnregen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif


# add for daily build
codegen_check:
	@if /I "$(strip $(DAILY_BUILD))"  EQU "TRUE" (perl tools\get_latest_codegen_result.pl $(strip $(CUSTOMER)) $(strip $(PROJECT)) $(strip $(FLAVOR)) >> $(strip $(TARGDIR))\build.log)


nvram_edit_h_gen:
$(eval $(call CheckNeedDependTarget,nvram_edit_h_gen,pregen_dep))
$(strip $(RULESDIR_TARGET))\pregen_dep\nvram_edit_h_gen.det: $(NEED_CHECK_CODEGEN_LIST)
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	-@echo $@: $?
endif
	@if exist tools\NVRAMStatistic\nvram_edit_gen.mak \
		(tools\make.exe -ftools\NVRAMStatistic\nvram_edit_gen.mak -r -R NVRAM_EDITOR_H_TO_DB > $(strip $(COMPLOGDIR))\nvram_edit_h_gen.log 2>&1)
	@echo $@: tools\NVRAMStatistic\nvram_edit_gen.mak >$@
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


# -------------
# genmoduleinfo
# -------------
genmoduleinfo: genlog gencompbld
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if not exist $(MODULE_INFO_DIR) mkdir $(MODULE_INFO_DIR)
ifeq ($(strip $(MODIS_CONFIG)),TRUE)
	@if not exist $(strip $(COMPLOGDIR))\MoDIS_setup mkdir $(strip $(COMPLOGDIR))\MoDIS_setup
	@tools\make.exe -fmake\gsm2.mak -r -R $(CMD_ARGU) --no-print-directory AUTO_CHECK_DEPEND=$(AUTO_CHECK_DEPEND) AUTO_CHECK_CGEN=$(AUTO_CHECK_CGEN) MODIS_CONFIG=$(strip $(MODIS_CONFIG)) genmoduleinfo_start
	@echo setup MoDIS env is done
else
	@if not exist $(strip $(COMPLOGDIR))\module_info mkdir $(strip $(COMPLOGDIR))\module_info
	@perl tools\time.pl -n
	@tools\make.exe -fmake\gsm2.mak -r -R $(CMD_ARGU) --no-print-directory AUTO_CHECK_DEPEND=$(AUTO_CHECK_DEPEND) AUTO_CHECK_CGEN=$(AUTO_CHECK_CGEN) genmoduleinfo_start
	@echo Generating .lis and .def files are done
	@perl tools\time.pl -n
endif
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


genmoduleinfo_start: $(MODULELIS)
	@echo genmoduleinfo is done.


# *************************************************************************
# nvram_auto_gen
# *************************************************************************
nvram_auto_gen:
ifneq ($(filter __MOD_NVRAM__,$(strip $(COM_DEFS))),)
ifneq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
$(strip $(RULESDIR_TARGET))\pregen_dep\nvram_auto_gen.det: FORCE
else
-include $(strip $(RULESDIR_TARGET))\pregen_dep\.\nvram_auto_gen.det
endif
nvram_auto_gen: $(strip $(RULESDIR_TARGET))\pregen_dep\nvram_auto_gen.det
  ifeq ($(strip $(MODIS_CONFIG)),FALSE)
cgen: $(strip $(RULESDIR_TARGET))\pregen_dep\nvram_auto_gen.det
  endif
$(strip $(RULESDIR_TARGET))\pregen_dep\nvram_auto_gen.det: $(NEED_CHECK_DEPEND_LIST) $(NEED_CHECK_CODEGEN_LIST)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'nvram_auto_gen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifeq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
	-@echo $@: $?
endif
	@if not exist $(strip $(RULESDIR_TARGET)) (mkdir $(strip $(RULESDIR_TARGET))) else (if exist $(strip $(RULESDIR_TARGET))\nvram_auto_gen.dep del /q $(strip $(RULESDIR_TARGET))\nvram_auto_gen.dep)
	@if not exist $(patsubst %\,%,$(dir $@)) (mkdir $(patsubst %\,%,$(dir $@))) else (if exist $@ del /q $@)
	@tools\strcmpex.exe TRUE TRUE e make\~cus_opt.tmp $(foreach def,$(sort $(COM_DEFS_TARGET)),-D \"$(def)\")
	@tools\strcmpex.exe TRUE TRUE e make\~inc.tmp $(foreach inc,$(XGEN_INC_DIR_TARGET),$(inc))

	@if not exist $(strip $(TST_DB_TARGET))\pstrace_db mkdir $(strip $(TST_DB_TARGET))\pstrace_db
	@if exist $(strip $(TST_DB))\CompTrcDefs.lst (del $(strip $(TST_DB))\CompTrcDefs.lst)
	@tools\strcmpex.exe TRUE TRUE e $(strip $(TST_DB))\CompTrcDefs.lst $(call sort, $(foreach def,$(COMP_TRACE_DEFS),$(def)))
	@tools\CreateEmptyTrcGenFiles.exe $(strip $(TST_DB_TARGET))\pstrace_db $(strip $(TST_DB))\CompTrcDefs.lst $(strip $(TSTDIR))\database\TrcGen.lst

	@if exist $(MMIDIR)\customer \
		((echo CUSTOM_FOLDER = $(strip $(BOARD_VER))> tools\NVRAMStatistic\include\custom_option.txt) && \
		(echo MMI_FOLDER = $(strip $(MMI_BASE))>> tools\NVRAMStatistic\include\custom_option.txt) && \
		(echo CUSTOM_OPTION = \>> tools\NVRAMStatistic\include\custom_option.txt) && \
		(type make\~cus_opt.tmp >> tools\NVRAMStatistic\include\custom_option.txt))

	@if exist $(MMIDIR)\customer \
		(@perl -e "open F,'<make\~inc.tmp';my $$i=join('',<F>);close F;$$i =~s/\s+/ /gs;$$i =~ s/(\S+)/-I \"..\\..\\..\\$$1\"/gs;print \"CUSTOM_INC = $$i\";" > tools\NVRAMStatistic\include\custom_include.txt)

   #Output NVRAM info
  ifneq ($(filter WM_MODEM ANDROID_MODEM,$(strip $(SMART_PHONE_CORE))),)
    ifdef OPTR_SPEC
      ifneq ($(strip $(OPTR_SPEC)),NONE)
		@if exist tools\NVRAMStatistic\include \
			(tools\NVRAMStatistic\NVRAMAutogen.bat $(strip $(CUSTOMER)) $(strip $(BOARD_VER)) ..\..\..\$(strip $(OPTR_PATH)\$(word 3,$(subst _, ,$(OPTR_SPEC))))\custom\app 1 $(strip $(call Upper,$(LEVEL))) $(strip $(call Upper,$(CUSTOM_RELEASE))))
      else
		@if exist tools\NVRAMStatistic\include \
			(tools\NVRAMStatistic\NVRAMAutogen.bat $(strip $(CUSTOMER)) $(strip $(BOARD_VER)) NONE 1 $(strip $(call Upper,$(LEVEL))) $(strip $(call Upper,$(CUSTOM_RELEASE))))
      endif
    endif
  else
    ifdef OPTR_SPEC
      ifneq ($(strip $(OPTR_SPEC)),NONE)
		@if exist tools\NVRAMStatistic\include \
			(tools\NVRAMStatistic\NVRAMAutogen.bat $(strip $(CUSTOMER)) $(strip $(BOARD_VER)) ..\..\..\$(strip $(OPTR_PATH)\$(word 3,$(subst _, ,$(OPTR_SPEC))))\custom\app 0 $(strip $(call Upper,$(LEVEL))) $(strip $(call Upper,$(CUSTOM_RELEASE))))
      else
		@if exist tools\NVRAMStatistic\include \
			(tools\NVRAMStatistic\NVRAMAutogen.bat $(strip $(CUSTOMER)) $(strip $(BOARD_VER)) NONE 0 $(strip $(call Upper,$(LEVEL))) $(strip $(call Upper,$(CUSTOM_RELEASE))))
      endif
    endif
  endif

	@if exist tools\NVRAMStatistic\debug\nvram_auto_gen.dep (copy /y tools\NVRAMStatistic\debug\nvram_auto_gen.dep $(strip $(RULESDIR_TARGET))\nvram_auto_gen.dep >NUL)
	@perl tools\pack_dep_gen.pl $@ $@ tools\NVRAMStatistic\debug \.d tools\NVRAMStatistic\src

  ifneq ($(strip $(NO_PCIBT)),TRUE)
   ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    ifeq ($(strip $(DEMO_PROJECT)),TRUE)
     ifeq ($(filter REL_CR_INET_MMI_ROLLTECH%,$(strip $(RELEASE_PACKAGE))),)
      ifeq ($(strip $(VENDOR)),NONE)
				@tools\make.exe -fmake\xgen\xgenIncCheck.mak -r -R --no-print-directory DEP_FILE=$@ LOG=$(strip $(COMPLOGDIR))\nvram_gen.log
      endif
     endif 
    endif
   endif
  endif
	@if exist $(strip $(TST_DB))\BPLGUInfoCustomAppSrc (del /q $(strip $(TST_DB))\BPLGUInfoCustomAppSrc)

	@perl -e "print 'nvram_auto_gen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif


# -----------------------------
# cgen
# -----------------------------
cgen: $(strip $(RULESDIR))\codegen_dep\cgen_parse.det \
      $(strip $(RULESDIR))\codegen_dep\cgen_preflow.det
ifneq ($(strip $(CODEGEN_DEPENDENCY)),)
cgen: $(CODEGEN_DEPENDENCY) \
      $(strip $(RULESDIR))\codegen_dep\cgen_cfg.det
endif

# -----------------------------
# Step 1: Preprocess
# -----------------------------
ifneq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
  $(strip $(RULESDIR))\codegen_dep\cgen_preflow.det: FORCE
else
  -include $(strip $(RULESDIR))\codegen_dep\.\codegen.det
endif
$(strip $(RULESDIR))\codegen_dep\cgen_preflow.det: $(strip $(RULESDIR))\codegen_dep\cgen_parse.det
$(strip $(RULESDIR))\codegen_dep\cgen_preflow.det: $(strip $(TSTDIR))\database\TrcGen.lst
$(strip $(RULESDIR))\codegen_dep\cgen_preflow.det: $(NEED_CHECK_DEPEND_LIST) $(NEED_CHECK_CODEGEN_LIST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'codegen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifeq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
	-@echo $@: $?
endif

	@if exist $(strip $(CGEN_CFG_FILE)) del /Q /F $(strip $(CGEN_CFG_FILE))
	@if exist $(strip $(CODE_GEN_LOG)) del /Q /F $(strip $(CODE_GEN_LOG))

	@echo Check Directories ...
	@if not exist $(strip $(FIXPATH))\custom\tst mkdir $(strip $(FIXPATH))\custom\tst
	@if not exist $(strip $(TST_DB)) mkdir $(TST_DB)
	@if not exist $(strip $(TST_DB))\msglog_db mkdir $(strip $(TST_DB))\msglog_db
	@if not exist $(patsubst %\,%,$(dir $@)) mkdir $(patsubst %\,%,$(dir $@))
	@if not exist $(strip $(PSTRACE_DB_DIR)) mkdir $(strip $(PSTRACE_DB_DIR))
#	@perl tools\echoLongString.pl $(INFOMAKELOG) COMP_TRACE_DEFS $(COMP_TRACE_DEFS)

ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@tools\make.exe -fmake\gsm2.mak -r -R --no-print-directory gen_sfini
else
	@if not exist $(MODISLOGDIR) md $(MODISLOGDIR)
endif

	@if exist $(strip $(TST_DB))\CompTrcDefs.lst (del $(strip $(TST_DB))\CompTrcDefs.lst)
	@tools\strcmpex.exe TRUE TRUE e $(strip $(TST_DB))\CompTrcDefs.lst $(call sort,$(foreach def,$(COMP_TRACE_DEFS),$(def)))
	@tools\CreateEmptyTrcGenFiles.exe $(strip $(PSTRACE_DB_DIR)) $(strip $(TST_DB))\CompTrcDefs.lst $(strip $(TSTDIR))\database\TrcGen.lst
	@echo $(strip $(TST_DB))\CompTrcDefs.lst >>$(CODE_GEN_LST)

#make\~inc_def.tmp:
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@tools\strcmpex.exe def def e make\~inc_def.tmp $(foreach def,$(COM_DEFS) __NULL_DEF__,-D$(def))
else
	@tools\strcmpex.exe def def e make\~inc_def.tmp -D__NULL_DEF__
endif
	@perl tools\echoLongString2.pl make\~inc_def.tmp -D $(COM_DEF_PATH)
	@tools\strcmpex.exe inc inc e make\~inc.tmp $(foreach inc,$(XGEN_INC_DIR),-I$(inc))
	@type make\~inc.tmp >> make\~inc_def.tmp
	@if exist make\~inc.tmp del make\~inc.tmp
	@echo make\~inc_def.tmp >> $(CODE_GEN_LST)

	@echo $@: tools\CreateEmptyTrcGenFiles.exe $(strip $(TSTDIR))\database\TrcGen.lst $(NEED_CHECK_DEPEND_LIST) >$@
	@echo $@ >>$(CODE_GEN_LST)
#	@tools\make.exe -fmake\gsm2.mak -r -R --no-print-directory $(strip $(CMD_ARGU)) cgen_preprocess
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


make\~inc_def.tmp: FORCE
	@if exist $(strip $(CGEN_CFG_FILE)) del /Q /F $(strip $(CGEN_CFG_FILE))
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@tools\strcmpex.exe def def e make\~inc_def.tmp $(foreach def,$(COM_DEFS) __NULL_DEF__,-D$(def))
else
	@tools\strcmpex.exe def def e make\~inc_def.tmp -D__NULL_DEF__
endif
	@perl tools\echoLongString2.pl make\~inc_def.tmp -D $(COM_DEF_PATH)
	@tools\strcmpex.exe inc inc e make\~inc.tmp $(foreach inc,$(XGEN_INC_DIR),-I$(inc))
	@type make\~inc.tmp >>make\~inc_def.tmp
	@if exist make\~inc.tmp del make\~inc.tmp
	@echo make\~inc_def.tmp >>$(CODE_GEN_LST)


ifneq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
  $(strip $(RULESDIR))\codegen_dep\cgen_parse.det: FORCE
else
  -include $(strip $(RULESDIR))\codegen_dep\.\cgen_parse.det
endif
$(strip $(RULESDIR))\codegen_dep\cgen_parse.det: $(NEED_CHECK_DEPEND_LIST) $(NEED_CHECK_CODEGEN_LIST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if not exist $(patsubst %\,%,$(dir $@)) (mkdir $(patsubst %\,%,$(dir $@)))
ifneq ($(filter PLUTO_MMI COSMOS_MMI IOT_MMI,$(strip $(MMI_VERSION))),)
	@if exist plutommi\Customer\ResGenerator\res_parse_screen_id.pl \
		(perl plutommi\Customer\ResGenerator\res_parse_screen_id.pl $(strip $(MMI_VERSION)) 2>$(basename $@).log) & \
		(if ERRORLEVEL 1 (type $(basename $@).log >>$(CODE_GEN_LOG)) & (exit 1))
endif
	@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $@)) $(basename $(notdir $@))\.log
	@if exist $(basename $@).log del /q $(basename $@).log
	@echo $@ >>$(CODE_GEN_LST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


$(eval $(call CgenPreprocess,$(strip $(TSTDIR))\database\msglog_db\parse_db.c,$(strip $(TST_DB))\msglog_db\pri.db,pri.det))
$(eval $(call CgenPreprocess,$(strip $(TSTDIR))\database\msglog_db\app_parse_db.c,$(strip $(TST_DB))\msglog_db\app_pri.db,app_pri.det))
$(eval $(call CgenPreprocess,$(strip $(TSTDIR))\database\msglog_db\custom_parse_db.c,$(strip $(TST_DB))\msglog_db\custom_pri.db,custom_pri.det))
$(eval $(call CgenPreprocess,$(strip $(TSTDIR))\database\gv\gv_db.c,$(strip $(TST_DB))\gv\gv_db\gv_db.gv,gv_db.det))
$(eval $(call CgenPreprocess,$(strip $(TSTDIR))\database\unionTag\unionTag_db.c,$(strip $(TST_DB))\unionTag\unionTag_parse.txt,unionTag_parse.det))
$(eval $(call CgenPreprocess,$(strip $(TSTDIR))\database\l1validation_db\l1v_db.c,$(strip $(TST_DB))\l1validation_db\l1v_db\l1v_db.l1v,l1v_db.det))


ifneq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
  $(strip $(RULESDIR))\codegen_dep\codegen_single.det: FORCE
else
  -include $(strip $(RULESDIR))\codegen_dep\.\codegen_single.det
endif
$(strip $(RULESDIR))\codegen_dep\codegen_single.det: $(strip $(RULESDIR))\codegen_dep\cgen_parse.det
$(strip $(RULESDIR))\codegen_dep\codegen_single.det: $(NEED_CHECK_DEPEND_LIST) $(NEED_CHECK_CODEGEN_LIST) $(MODULE_MAKEFILE_LIST)
ifeq ($(filter $(MAKECMDGOALS),cgen_preprocess),)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif
	@echo Preprocessing codegen_single.h
	@if not exist make\~inc_def.tmp tools\make.exe -fmake\gsm2.mak -r -R --no-print-directory make\~inc_def.tmp
	@if exist $@ del $@
	@tools\strcmpex.exe def def e $(strip $(TST_DB))\pstrace_db\temp.lst $(COMP_TRACE_DEFS)
	@perl tools\lnitem.pl $(strip $(TST_DB))\pstrace_db\temp.lst
	@if exist $(strip $(TST_DB))\pstrace_db\codegen_single.h del $(strip $(TST_DB))\pstrace_db\codegen_single.h
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@for /f %%i in ($(strip $(TST_DB))\pstrace_db\temp.lst) do (echo #include "%%i" >>$(strip $(TST_DB))\pstrace_db\codegen_single.h)
else
	@for /f %%i in ($(strip $(TST_DB))\pstrace_db\temp.lst) do (if exist %%i echo #include "%%i" >>$(strip $(TST_DB))\pstrace_db\codegen_single.h)
endif
	@if exist $(strip $(TST_DB))\pstrace_db\temp.lst del $(strip $(TST_DB))\pstrace_db\temp.lst
	@copy /y $(strip $(TST_DB))\pstrace_db\codegen_single.h ~codegen_single.c >nul
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@($(CC) -E -W -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -o $(strip $(TST_DB))\pstrace_db\codegen_single.ptr ~codegen_single.c 2>$(basename $@).log) & \
		(if ERRORLEVEL 1 (type $(basename $@).log >>$(CODE_GEN_LOG)) & (exit 1))
	@($(CC) -M -W -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -o $@ ~codegen_single.c --no_depend_system_headers $(DEPEND) $(dir $@)codegen_single.d) & \
		(if ERRORLEVEL 1 exit 1)
	@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $@)) $(basename $(notdir $@))\.d
	@if exist $(dir $@)codegen_single.d del $(dir $@)codegen_single.d
else
	@(cl.exe /E /w /DGEN_FOR_PC /nologo /showIncludes @make\~inc_def.tmp ~codegen_single.c >$(strip $(TST_DB))\pstrace_db\codegen_single.ptr 2>$(basename $@).log) & \
		(if ERRORLEVEL 1 (type $(basename $@).log >>$(CODE_GEN_LOG)) & (exit 1))
	@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $@)) $(basename $(notdir $@))\.log
endif
	@if exist ~codegen_single.c del ~codegen_single.c
	@if exist $(basename $@).log del /q $(basename $@).log
ifeq ($(filter $(MAKECMDGOALS),cgen_preprocess),)
	@echo $(strip $(TST_DB))\pstrace_db\codegen_single.ptr >>$(CODE_GEN_LST)
	@echo $(strip $(TST_DB))\pstrace_db\codegen_single.h >>$(CODE_GEN_LST)
	@echo $@ >>$(CODE_GEN_LST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif


ifneq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
  $(strip $(RULESDIR))\codegen_dep\cgen_src.det: FORCE
else
  -include $(strip $(RULESDIR))\codegen_dep\.\cgen_src.det
endif
$(strip $(RULESDIR))\codegen_dep\cgen_src.det: $(strip $(RULESDIR))\codegen_dep\cgen_parse.det
$(strip $(RULESDIR))\codegen_dep\cgen_src.det: $(CGEN) $(NEED_CHECK_DEPEND_LIST) $(NEED_CHECK_CODEGEN_LIST)
ifeq ($(filter $(MAKECMDGOALS),cgen_preprocess),)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif
	@($(CGEN) -src $(MMI_SCR_ID_FILE) $(FIXPATH)\$(strip $(MMIDIR)) >$(basename $@).lis 2>&1) & \
		(if ERRORLEVEL 1 (type $(basename $@).lis >>$(CODE_GEN_LOG)) & (exit 1))
	@if not exist make\~inc_def.tmp tools\make.exe -fmake\gsm2.mak -r -R --no-print-directory make\~inc_def.tmp
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@($(CC) -E -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(MMI_SCR_ID_DB) $(MMI_SCR_ID_FILE) 2>$(basename $@).log) & \
		(if ERRORLEVEL 1 (type $(basename $@).log >>$(CODE_GEN_LOG)) & (exit 1))
	@($(CC) -M -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(MMI_SCR_ID_DB) $(MMI_SCR_ID_FILE) --no_depend_system_headers $(DEPEND) $(basename $@).d) & \
		(if ERRORLEVEL 1 exit 1)
else
	@(cl.exe /E /w /DGEN_FOR_CPARSER /DGEN_FOR_PC /USTDC_HEADERS /nologo /showIncludes @make\~inc_def.tmp $(MMI_SCR_ID_FILE) >$(MMI_SCR_ID_DB) 2>$(basename $@).log) & \
		(if ERRORLEVEL 1 (type $(basename $@).log >>$(CODE_GEN_LOG)) & (exit 1))
endif
	@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $@)) $(basename $(notdir $@))\.(lis^|log^|d)
	@if exist $(MMI_SCR_ID_FILE) del /q $(MMI_SCR_ID_FILE)
	@if exist $(basename $@).lis del /q $(basename $@).lis
	@if exist $(basename $@).d del /q $(basename $@).d
	@if exist $(basename $@).log del /q $(basename $@).log
ifeq ($(filter $(MAKECMDGOALS),cgen_preprocess),)
	@echo $@ >>$(CODE_GEN_LST)
	@echo $(MMI_SCR_ID_DB) >>$(CODE_GEN_LST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif


ifneq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
  $(strip $(RULESDIR))\codegen_dep\log2SD_Catcher_filters.det: FORCE
else
  -include $(strip $(RULESDIR))\codegen_dep\.\log2SD_Catcher_filters.det
endif
$(strip $(RULESDIR))\codegen_dep\log2SD_Catcher_filters.det: $(strip $(TSTDIR))\database\log2SD_Catcher_filters.h
$(strip $(RULESDIR))\codegen_dep\log2SD_Catcher_filters.det: $(NEED_CHECK_DEPEND_LIST) $(NEED_CHECK_CODEGEN_LIST)
ifeq ($(filter $(MAKECMDGOALS),cgen_preprocess),)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif
	@echo Preprocessing log2SD_Catcher_filters.h ...
	@if not exist make\~inc_def.tmp tools\make.exe -fmake\gsm2.mak -r -R --no-print-directory make\~inc_def.tmp
	@($(CC) -E -W -I$(strip $(TSTDIR))\database $(VIA) make\~inc_def.tmp -o $(strip $(TSTDIR))\database\log2SD_Catcher_filters.ini $(strip $(TSTDIR))\database\log2SD_Catcher_filters.h 2>$(basename $@).log) & \
		(if ERRORLEVEL 1 (type $(basename $@).log >>$(CODE_GEN_LOG)) & (exit 1))
	@($(CC) -M -W -I$(strip $(TSTDIR))\database $(VIA) make\~inc_def.tmp -o $@ $(strip $(TSTDIR))\database\log2SD_Catcher_filters.h --no_depend_system_headers $(DEPEND) $@) & \
		(if ERRORLEVEL 1 exit 1)
	@if exist $(basename $@).log del /q $(basename $@).log
ifeq ($(filter $(MAKECMDGOALS),cgen_preprocess),)
  ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@echo $@ >>$(CODE_GEN_LST)
	@echo $(strip $(TSTDIR))\database\log2SD_Catcher_filters.ini >> $(CODE_GEN_LST)
  endif
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif


# -----------------------------
# Step 2: Generate Base Information
# -----------------------------
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
ifneq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
  $(strip $(RULESDIR))\codegen_dep\cgen_c.det: FORCE
endif
$(strip $(RULESDIR))\codegen_dep\cgen_c.det: $(strip $(RULESDIR))\codegen_dep\pri.det
$(strip $(RULESDIR))\codegen_dep\cgen_c.det: $(strip $(TSTDIR))\database\$(CGEN_DEF_FILE) $(strip $(TSTDIR))\database\Pc_Cnf 
$(strip $(RULESDIR))\codegen_dep\cgen_c.det: $(VERNOFILE) $(CGEN) $(NEED_CHECK_DEPEND_LIST) $(NEED_CHECK_CODEGEN_LIST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo Generate Base Information ...
	@if exist $(strip $(TST_DB))\BPLGUInfoCustomApp_* del /q $(strip $(TST_DB))\BPLGUInfoCustomApp_*
	@if not exist $(strip $(TSTDIR))\src mkdir $(strip $(TSTDIR))\src
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@echo $(CGEN) -c $(strip $(TST_DB))\msglog_db\pri.db $(strip $(TSTDIR))\database\$(CGEN_DEF_FILE) $(strip $(TSTDIR))\database\Pc_Cnf $(CODEGEN_DATABASE_OUT) $(strip $(TST_DB))\enumFile $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) -qModSim-$(strip $(TSTDIR))\src\tst_querysimid.c -sf-$(strip $(TSTDIR))\database\sf.ini -prjName-$(strip $(FULL_PRJ_NAME)) -VERNO_HAL-$(strip $(VERNO_HAL)) >>$(CGEN_CFG_FILE)
	@echo $(strip $(TSTDIR))\src\tst_querysimid.c >>$(CODE_GEN_LST)
else
	@echo $(CGEN) -c $(strip $(TST_DB))\msglog_db\pri.db $(strip $(TSTDIR))\database\$(CGEN_DEF_FILE) $(strip $(TSTDIR))\database\Pc_Cnf $(CODEGEN_DATABASE_OUT) $(strip $(TST_DB))\enumFile MoDIS $(strip $(VERNO)) -qModSim-$(strip $(TSTDIR))\src\tst_querysimid_modis.c >>$(CGEN_CFG_FILE)
	@echo $(strip $(TSTDIR))\src\tst_querysimid_modis.c >>$(CODE_GEN_LST)
endif
	@echo $@: $(strip $(TSTDIR))\database\$(CGEN_DEF_FILE) $(strip $(TSTDIR))\database\Pc_Cnf $(strip $(VERNOFILE)) $(strip $(THE_MF)) $(strip $(VERNOFILE)) >$@
	@echo $@ >>$(CODE_GEN_LST)
	@echo $(strip $(TST_DB))\enumFile >>$(CODE_GEN_LST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif


# -----------------------------
# Step 3: Protocol trace information
# -----------------------------
ifneq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
  $(strip $(RULESDIR))\codegen_dep\cgen_ps.det: FORCE
endif
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  $(strip $(RULESDIR))\codegen_dep\cgen_ps.det: $(strip $(RULESDIR))\codegen_dep\cgen_c.det
  $(strip $(RULESDIR))\codegen_dep\cgen_ps.det: $(strip $(RULESDIR))\codegen_dep\cgen_ap.det
  $(strip $(RULESDIR))\codegen_dep\cgen_ps.det: $(strip $(RULESDIR))\codegen_dep\cgen_cm.det
else ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  $(strip $(RULESDIR))\codegen_dep\cgen_ps.det: $(strip $(RULESDIR))\codegen_dep\cgen_ap.det
  $(strip $(RULESDIR))\codegen_dep\cgen_ps.det: $(strip $(RULESDIR))\codegen_dep\cgen_cm.det
else
  $(strip $(RULESDIR))\codegen_dep\cgen_ps.det: $(strip $(RULESDIR))\codegen_dep\cgen_cm.det
endif
$(strip $(RULESDIR))\codegen_dep\cgen_ps.det: $(strip $(RULESDIR))\codegen_dep\cgen_parse.det $(strip $(RULESDIR))\codegen_dep\codegen_single.det
$(strip $(RULESDIR))\codegen_dep\cgen_ps.det: $(CGEN) $(NEED_CHECK_DEPEND_LIST) $(NEED_CHECK_CODEGEN_LIST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo Generate PS Trace Information ...
#backup xxx_trc_gen.h
	@if not exist $(strip $(PSTRACE_DB_DIR))_bak (mkdir $(strip $(PSTRACE_DB_DIR))_bak) else (if exist $(strip $(PSTRACE_DB_DIR))_bak\*.* del /q $(strip $(PSTRACE_DB_DIR))_bak\*.*)
	@if exist $(strip $(PSTRACE_DB_DIR))\*.h copy /y $(strip $(PSTRACE_DB_DIR))\*.h $(strip $(PSTRACE_DB_DIR))_bak\ >NUL
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@echo $(CGEN) -ps $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) $(strip $(TST_DB))\pstrace_db $(strip $(TST_DB))\pstrace_db\ps_trace_1.h >>$(CGEN_CFG_FILE)
	@echo $(CGEN) -rle $(strip $(TST_DB))\pstrace_db\ps_trace_2.h $(strip $(TST_DB))\pstrace_db\ps_trace_1.h >>$(CGEN_CFG_FILE)
	@echo $(CGEN) -sps $(strip $(TST_DB))\pstrace_db\ps_trace.h $(strip $(TST_DB))\pstrace_db\ps_trace_2.h >>$(CGEN_CFG_FILE)
else
	@echo $(CGEN) -ps $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) $(strip $(TST_DB))\pstrace_db $(strip $(TST_DB))\pstrace_db\ps_trace_1.h >>$(CGEN_CFG_FILE)
	@echo $(CGEN) -sps $(strip $(TST_DB))\pstrace_db\ps_trace.h $(strip $(TST_DB))\pstrace_db\ps_trace_1.h >>$(CGEN_CFG_FILE)
endif
	@echo $@: >$@
	@echo $@ >>$(CODE_GEN_LST)
	@echo $(strip $(TST_DB))\pstrace_db\ps_trace.h >>$(CODE_GEN_LST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


# -----------------------------
# Step 4: Layer 1 trace information
# -----------------------------
ifneq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
  $(strip $(RULESDIR))\codegen_dep\cgen_l1.det: FORCE
else
  -include $(strip $(RULESDIR))\codegen_dep\.\cgen_l1.det
endif
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  $(strip $(RULESDIR))\codegen_dep\cgen_l1.det: $(strip $(RULESDIR))\codegen_dep\cgen_c.det
endif
$(strip $(RULESDIR))\codegen_dep\cgen_l1.det: $(CGEN) $(NEED_CHECK_DEPEND_LIST) $(NEED_CHECK_CODEGEN_LIST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
#backup tst\include\*.h
	@if not exist tst\include_bak (mkdir tst\include_bak) else (if exist tst\include_bak\*.* del /q tst\include_bak\*.*)
	@if exist tst\include\*.h copy /y tst\include\*.h tst\include_bak\ >NUL
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@echo Generate L1 Trace Information ...
  ifeq ($(strip $(MODIS_CONFIG)),FALSE)
    ifeq ($(strip $(TMD_FILES)),)
	@echo $(CGEN) -L1 $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) L1_CATCHER $(strip $(TSTDIR))\src\TrcMod.c $(strip $(TSTDIR))\include\TrcMod.h $(TMD_FILES) >>$(CGEN_CFG_FILE)
	@tools\strcmpex.exe abc abc e $@ $@: $(filter-out CuStOm_StArT_AST CuStOm_EnD_AST,$(strip $(TMD_FILES)))
    else
	@echo $(CGEN) -L1 $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) L1_CATCHER $(strip $(TSTDIR))\src\TrcMod.c $(strip $(TSTDIR))\include\TrcMod.h $(strip $(TSTDIR))\database\l1validation_db\L1ModMsg.chk $(TMD_FILES) >>$(CGEN_CFG_FILE)
	@tools\strcmpex.exe abc abc e $@ $@: $(strip $(TSTDIR))\database\l1validation_db\L1ModMsg.chk  $(filter-out CuStOm_StArT_AST CuStOm_EnD_AST,$(strip $(TMD_FILES)))
	@for %%i in ($(foreach tmd_file,$(filter-out CuStOm_StArT_AST CuStOm_EnD_AST,$(strip $(TMD_FILES))), $(basename $(tmd_file)).c $(strip $(TSTDIR))\include\$(notdir $(basename $(tmd_file)).h))) do (echo %%i >>$(CODE_GEN_LST))
    endif
	@echo $(strip $(TSTDIR))\src\TrcMod.c >>$(CODE_GEN_LST)
	@echo $(strip $(TSTDIR))\include\TrcMod.h >>$(CODE_GEN_LST)
  else
      # workaround for -puremodis, because some L1 headers are always included
	@for %%i in ($(strip $(TSTDIR))\include\TrcMod.h $(foreach tmd_file,$(filter-out CuStOm_StArT_AST CuStOm_EnD_AST,$(strip $(TMD_FILES))), $(strip $(TSTDIR))\include\$(notdir $(basename $(tmd_file)).h))) do (if not exist %%i copy NUL %%i >NUL)
  endif
else
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  ifneq ($(strip $(AST_SUPPORT)),NONE)
	@if not exist $(strip $(TSTDIR))\src mkdir $(strip $(TSTDIR))\src
    ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@echo $(CGEN) -L1 $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) L1_CATCHER $(strip $(TSTDIR))\src\TrcMod.c $(strip $(TSTDIR))\include\TrcMod.h $(AST_TMD_FILES) >>$(CGEN_CFG_FILE)
	@tools\strcmpex.exe abc abc e $@ $@: $(filter-out CuStOm_StArT_AST CuStOm_EnD_AST,$(strip $(AST_TMD_FILES)))
	@for %%i in ($(foreach tmd_file,$(filter-out CuStOm_StArT_AST CuStOm_EnD_AST,$(strip $(AST_TMD_FILES))), $(basename $(tmd_file)).c $(strip $(TSTDIR))\include\$(notdir $(basename $(tmd_file)).h))) do (echo %%i >>$(CODE_GEN_LST))
	@echo $(strip $(TSTDIR))\src\TrcMod.c >>$(CODE_GEN_LST)
	@echo $(strip $(TSTDIR))\include\TrcMod.h >>$(CODE_GEN_LST)
    else
	@for %%i in ($(strip $(TSTDIR))\include\TrcMod.h $(foreach tmd_file,$(filter-out CuStOm_StArT_AST CuStOm_EnD_AST,$(strip $(AST_TMD_FILES))), $(strip $(TSTDIR))\include\$(notdir $(basename $(tmd_file)).h))) do (if not exist %%i copy NUL %%i >NUL)
    endif
  endif
  endif
endif
	@echo $@: >>$@
	@echo $@ >>$(CODE_GEN_LST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


# -----------------------------
# Step 5: Result temporary - Global variable information
# -----------------------------
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
ifneq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
  $(strip $(RULESDIR))\codegen_dep\cgen_gv.det: FORCE
endif
$(strip $(RULESDIR))\codegen_dep\cgen_gv.det: $(strip $(RULESDIR))\codegen_dep\cgen_c.det $(strip $(RULESDIR))\codegen_dep\gv_db.det
$(strip $(RULESDIR))\codegen_dep\cgen_gv.det: $(GV_FILES)
$(strip $(RULESDIR))\codegen_dep\cgen_gv.det: $(CGEN) $(NEED_CHECK_DEPEND_LIST) $(NEED_CHECK_CODEGEN_LIST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo Generate Global variable Information ...
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@echo $(CGEN) -gv $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) $(strip $(TST_DB))\gv\gv_db\ $(strip $(TSTDIR))\src\gvTbl.c >>$(CGEN_CFG_FILE)
	@echo $(strip $(TSTDIR))\src\gvTbl.c >>$(CODE_GEN_LST)
else
	@echo $(CGEN) -gv $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) $(strip $(TST_DB))\gv\gv_db\ $(strip $(TSTDIR))\src\gvTbl_modis.c >>$(CGEN_CFG_FILE)
	@echo $(strip $(TSTDIR))\src\gvTbl_modis.c >>$(CODE_GEN_LST)
endif
	@tools\strcmpex.exe abc abc e $(basename $@).d $@: $(GV_FILES)
	@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $@)) $(basename $(notdir $@))\.d
	@if exist $(basename $@).d del $(basename $@).d
	@echo $@ >> $(CODE_GEN_LST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif


# -----------------------------
# Step 6:  Result - Layer 1 validation information (L1S)
# -----------------------------
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
ifeq ($(call Upper,$(PROJECT)),L1S)
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  ifneq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
    $(strip $(RULESDIR))\codegen_dep\cgen_l1v.det: FORCE
  endif
$(strip $(RULESDIR))\codegen_dep\cgen_l1v.det: $(strip $(RULESDIR))\codegen_dep\cgen_c.det $(strip $(RULESDIR))\codegen_dep\l1v_db.det
$(strip $(RULESDIR))\codegen_dep\cgen_l1v.det: $(filter-out %\l1validation_db\l1v_db\l1v_db.l1v,$(shell dir $(strip $(TST_DB))\l1validation_db\*.l1v /s/b))
$(strip $(RULESDIR))\codegen_dep\cgen_l1v.det: $(CGEN) $(NEED_CHECK_DEPEND_LIST) $(NEED_CHECK_CODEGEN_LIST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo Generate L1 Validation Information ...
	@echo $(CGEN) -L1V $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) $(strip $(TST_DB))\l1validation_db\l1v_db\ >>$(CGEN_CFG_FILE)
	@if exist $(basename $@).d del $(basename $@).d
# too much *.l1v files, command length will be over 32KB
	@for /r $(strip $(TST_DB))\l1validation_db %%i in (*.l1v) do (echo $@: %%i >>$(basename $@).d)
	@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $@)) $(basename $(notdir $@))\.d
	@if exist $(basename $@).d del $(basename $@).d
	@echo $@ >>$(CODE_GEN_LST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif
endif
endif


# -----------------------------
# Step 7: Result - Union Information (GSM/GPRS)
#------------------------------
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
ifneq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
  $(strip $(RULESDIR))\codegen_dep\cgen_un.det: FORCE
endif
$(strip $(RULESDIR))\codegen_dep\cgen_un.det: $(strip $(RULESDIR))\codegen_dep\cgen_c.det $(strip $(RULESDIR))\codegen_dep\unionTag_parse.det
$(strip $(RULESDIR))\codegen_dep\cgen_un.det: $(CGEN) $(NEED_CHECK_DEPEND_LIST) $(NEED_CHECK_CODEGEN_LIST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo Generate Union Information ...
	@echo $(CGEN) -un $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) $(strip $(TST_DB))\unionTag\unionTag_parse.txt >>$(CGEN_CFG_FILE)
	@echo $@: >$@
	@echo $@ >>$(CODE_GEN_LST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif


# ------------------------------------------
# Step 8: Result - Merge customization code
# ------------------------------------------
ifneq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
  $(strip $(RULESDIR))\codegen_dep\cgen_cm.det: FORCE
endif
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  $(strip $(RULESDIR))\codegen_dep\cgen_cm.det: $(strip $(RULESDIR))\codegen_dep\cgen_c.det
endif
$(strip $(RULESDIR))\codegen_dep\cgen_cm.det: $(strip $(RULESDIR))\codegen_dep\custom_pri.det
$(strip $(RULESDIR))\codegen_dep\cgen_cm.det: $(VERNOFILE) $(CGEN) $(NEED_CHECK_DEPEND_LIST) $(NEED_CHECK_CODEGEN_LIST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@echo $(CGEN) -cm $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TST_DB))\enumFileCustom $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) -sf-$(strip $(TSTDIR))\database\sf.ini -prjName-$(strip $(FULL_PRJ_NAME)) -VERNO_HAL-$(strip $(VERNO_HAL)) >>$(CGEN_CFG_FILE)
  else
	@echo $(CGEN) -cm $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TST_DB))\enumFileCustom MoDIS $(strip $(VERNO)) >>$(CGEN_CFG_FILE)
  endif
	@echo $(strip $(TST_DB))\enumFileCustom >>$(CODE_GEN_LST)
else ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@echo $(CGEN) -cm $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TST_DB))\enumFileCustomSrc $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) -sf-$(strip $(TSTDIR))\database\sf.ini -prjName-$(strip $(FULL_PRJ_NAME)) -VERNO_HAL-$(strip $(VERNO_HAL)) >>$(CGEN_CFG_FILE)
  else
	@echo $(CGEN) -cm $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TST_DB))\enumFileCustomSrc MoDIS $(strip $(VERNO)) >>$(CGEN_CFG_FILE)
  endif
else
  ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@echo $(CGEN) -cm $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TST_DB))\enumFileCustomAppSrc $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) -sf-$(strip $(TSTDIR))\database\sf.ini -prjName-$(strip $(FULL_PRJ_NAME)) -VERNO_HAL-$(strip $(VERNO_HAL)) >>$(CGEN_CFG_FILE)
  else
	@echo $(CGEN) -cm $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TST_DB))\enumFileCustomAppSrc MoDIS $(strip $(VERNO)) $(MMIDIR) >>$(CGEN_CFG_FILE)
  endif
	@echo $(strip $(TST_DB))\enumFileCustomAppSrc >>$(CODE_GEN_LST)
endif
	@echo $@: $(VERNOFILE) $(THE_MF) >$@
	@echo $@ >>$(CODE_GEN_LST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


ifneq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
  $(strip $(RULESDIR))\codegen_dep\cgen_ap.det: FORCE
endif
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  $(strip $(RULESDIR))\codegen_dep\cgen_ap.det: $(strip $(RULESDIR))\codegen_dep\cgen_c.det
endif
$(strip $(RULESDIR))\codegen_dep\cgen_ap.det: $(strip $(RULESDIR))\codegen_dep\cgen_src.det $(strip $(RULESDIR))\codegen_dep\app_pri.det
$(strip $(RULESDIR))\codegen_dep\cgen_ap.det: $(VERNOFILE) $(CGEN) $(NEED_CHECK_DEPEND_LIST) $(NEED_CHECK_CODEGEN_LIST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
  ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@echo $(CGEN) -ap $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) $(strip $(TST_DB))\msglog_db\app_pri.db $(strip $(TST_DB))\enumFileCustomApp $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) $(MMI_SCR_ID_DB) >>$(CGEN_CFG_FILE)
	@echo $(strip $(TST_DB))\enumFileCustomApp >>$(CODE_GEN_LST)
  else
    ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
	@echo $(CGEN) -ap $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) $(strip $(TST_DB))\msglog_db\app_pri.db $(strip $(TST_DB))\enumFileCustomAppSrc $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) $(MMI_SCR_ID_DB) >>$(CGEN_CFG_FILE)
	@echo $(strip $(TST_DB))\enumFileCustomAppSrc >>$(CODE_GEN_LST)
    endif
  endif
else
  ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@echo $(CGEN) -ap $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) $(strip $(TST_DB))\msglog_db\app_pri.db $(strip $(TST_DB))\enumFileCustomApp MoDIS $(strip $(VERNO)) $(MMI_SCR_ID_DB) >>$(CGEN_CFG_FILE)
	@echo $(strip $(TST_DB))\enumFileCustomApp >>$(CODE_GEN_LST)
  else
    ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
	@echo $(CGEN) -ap $(CODEGEN_DATABASE_OUT) $(CODEGEN_DATABASE_IN) $(strip $(TST_DB))\msglog_db\app_pri.db $(strip $(TST_DB))\enumFileCustomAppSrc MoDIS $(strip $(VERNO)) $(MMI_SCR_ID_DB) >>$(CGEN_CFG_FILE)
	@echo $(strip $(TST_DB))\enumFileCustomAppSrc >>$(CODE_GEN_LST)
    endif
  endif
endif
	@echo $@: $(VERNOFILE) $(THE_MF) >$@
	@echo $@ >>$(CODE_GEN_LST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


ifneq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
  $(strip $(RULESDIR))\codegen_dep\cgen_filter_gen.det: FORCE
endif
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
  $(strip $(RULESDIR))\codegen_dep\cgen_filter_gen.det: $(strip $(RULESDIR))\codegen_dep\log2SD_Catcher_filters.det
else
  ifneq ($(filter LOG2SD_CATCHER_FILTERS.INI,$(strip $(call Upper,$(notdir $(wildcard $(subst \,/,$(strip $(TSTDIR))\database\*.ini)))))),)
    # exist tst\database\log2SD_Catcher_filters.ini
  else
    $(strip $(RULESDIR))\codegen_dep\cgen_filter_gen.det: $(strip $(RULESDIR))\codegen_dep\log2SD_Catcher_filters.det
  endif
endif
$(strip $(RULESDIR))\codegen_dep\cgen_filter_gen.det: $(filter-out \
                                                                   $(strip $(RULESDIR))\codegen_dep\cgen_filter_gen.det \
                                                                   $(strip $(RULESDIR))\codegen_dep\cgen_ps.det \
                                                                   $(strip $(RULESDIR))\codegen_dep\cgen_gv.det \
                                                                   $(strip $(RULESDIR))\codegen_dep\cgen_l1v.det \
                                                                   $(strip $(RULESDIR))\codegen_dep\cgen_un.det \
                                                      ,$(CODEGEN_DEPENDENCY))
$(strip $(RULESDIR))\codegen_dep\cgen_filter_gen.det: $(CGEN) $(NEED_CHECK_DEPEND_LIST) $(NEED_CHECK_CODEGEN_LIST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(MODIS_CONFIG)),FALSE)
	@echo $(CGEN) -filter_gen src $(CODEGEN_DATABASE_OUT) $(strip $(TSTDIR))\database\log2SD_Catcher_filters.ini $(strip $(FIXPATH))\custom\tst\tst_file_default_Catcher_filter.c __TST_WRITE_TO_FILE__ >>$(CGEN_CFG_FILE)
	@echo $(CGEN) -filter_gen bin $(CODEGEN_DATABASE_OUT) $(strip $(TSTDIR))\database\log2SD_Catcher_filters.ini $(strip $(TST_DB))\catcher_filter.bin >>$(CGEN_CFG_FILE)
	@echo $(strip $(FIXPATH))\custom\tst\tst_file_default_Catcher_filter.c >>$(CODE_GEN_LST)
	@echo $(strip $(TST_DB))\catcher_filter.bin >>$(CODE_GEN_LST)
else
	@if not exist $(strip $(FIXPATH))\custom\tst\tst_file_default_Catcher_filter.c (echo $(CGEN) -filter_gen src $(CODEGEN_DATABASE_OUT) $(strip $(TSTDIR))\database\log2SD_Catcher_filters.ini $(strip $(FIXPATH))\custom\tst\tst_file_default_Catcher_filter.c __TST_WRITE_TO_FILE__ >>$(CGEN_CFG_FILE))
endif
	@echo $@: >$@
	@echo $@ >>$(CODE_GEN_LST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


ifneq ($(strip $(AUTO_CHECK_CGEN)),TRUE)
  $(strip $(RULESDIR))\codegen_dep\cgen_cfg.det: FORCE
endif
$(strip $(RULESDIR))\codegen_dep\cgen_cfg.det: $(CODEGEN_DEPENDENCY)
$(strip $(RULESDIR))\codegen_dep\cgen_cfg.det: $(CGEN) $(NEED_CHECK_DEPEND_LIST) $(NEED_CHECK_CODEGEN_LIST)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ifneq ($(strip $(CUSTOM_RELEASE)),FALSE)
  ifneq ($(words $(strip $(BPLGUINFOCUSTOM))),1)
		@echo [ERROR] Cannot determine the original codegen database: $(strip $(BPLGUINFOCUSTOM)) >>$(CODE_GEN_LOG)
		@echo [ERROR] Cannot determine the original codegen database: $(strip $(BPLGUINFOCUSTOM))
		@exit 2
  endif
endif
		@if not exist $(strip $(CGEN_CFG_FILE)) \
			(echo Error: $(CGEN_CFG_FILE) does not exist!) && \
			(exit 1)
		@echo Cgen -cfg $(CGEN_CFG_FILE)
		@$(CGEN) -cfg $(CGEN_CFG_FILE) 2>>$(CODE_GEN_LOG)

#restore xxx_trc_gen.h
		@if exist $(strip $(PSTRACE_DB_DIR))_bak\*.h (for %%i in ($(strip $(PSTRACE_DB_DIR))_bak\*.h) do ((fc $(strip $(PSTRACE_DB_DIR))\%%~nxi $(strip $(PSTRACE_DB_DIR))_bak\%%~nxi >NUL 2>&1) & (if not errorlevel 1 (copy /y $(strip $(PSTRACE_DB_DIR))_bak\%%~nxi $(strip $(PSTRACE_DB_DIR))\ >NUL) else (echo %%~nxi is updated))))
		@if exist $(strip $(PSTRACE_DB_DIR))_bak rd /s /q $(strip $(PSTRACE_DB_DIR))_bak
		@if exist tst\include_bak\*.h (for %%i in (tst\include_bak\*.h) do ((fc tst\include\%%~nxi tst\include_bak\%%~nxi >NUL 2>&1) & (if not errorlevel 1 (copy /y tst\include_bak\%%~nxi tst\include\ >NUL) else (echo %%~nxi is updated))))
		@if exist tst\include_bak rd /s /q tst\include_bak

		@echo $@: $(CGEN) >$@
		@perl tools\pack_dep_gen.pl $(dir $@)codegen.det $(dir $@)cgen_preflow.det $(patsubst %\,%,$(dir $@)) \.det
		@echo $(dir $@)cgen_preflow.det: >>$(dir $@)cgen_preflow.det
		@perl tools\pack_dep_gen.pl $(strip $(RULESDIR))\codegen.dep custom_parse_db.obj $(patsubst %\,%,$(dir $@)) custom_pri\.det
		@perl tools\pack_dep_gen.pl $(strip $(RULESDIR))\app_parse_db.d app_parse_db.obj $(patsubst %\,%,$(dir $@)) app_pri\.det
		@if exist $(strip $(RULESDIR))\app_parse_db.d ((type $(strip $(RULESDIR))\app_parse_db.d >>$(strip $(RULESDIR))\codegen.dep) & (del $(strip $(RULESDIR))\app_parse_db.d))

		@echo $@ >>$(CODE_GEN_LST)
		@echo $(dir $@)codegen.det >>$(CODE_GEN_LST)
		@echo $(CGEN_CFG_FILE) >>$(CODE_GEN_LST)
		@echo $(CODEGEN_DATABASE_OUT) >>$(CODE_GEN_LST)
    ifneq ($(strip $(NO_PCIBT)),TRUE)
     ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
       ifeq ($(strip $(DEMO_PROJECT)),TRUE)
        ifeq ($(filter REL_CR_INET_MMI_ROLLTECH%,$(strip $(RELEASE_PACKAGE))),)
         ifeq ($(strip $(VENDOR)),NONE)
					@tools\make.exe -fmake\xgen\xgenIncCheck.mak -r -R --no-print-directory DEP_FILE=$(dir $@)app_pri.det LOG=$(strip $(CODE_GEN_LOG))
					@tools\make.exe -fmake\xgen\xgenIncCheck.mak -r -R --no-print-directory DEP_FILE=$(dir $@)custom_pri.det LOG=$(strip $(CODE_GEN_LOG))
         endif
        endif 
       endif
     endif
    endif

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
		@if exist $(strip $(TST_DB))\enumFileCustomSrc del /q $(strip $(TST_DB))\enumFileCustomSrc
  endif
endif
		@if exist $(strip $(TST_DB))\pstrace_db\ps_trace_1.h del /q $(strip $(TST_DB))\pstrace_db\ps_trace_1.h
		@if exist $(strip $(TST_DB))\pstrace_db\ps_trace_2.h del /q $(strip $(TST_DB))\pstrace_db\ps_trace_2.h

	@perl -e "print 'codegen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
ifeq ($(strip $(call Upper,$(MTK_INTERNAL))),TRUE)
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
	@echo $(CGEN) -sign $(strip $(NET_PATH))\$(strip $(CODEGEN_DATABASE_OUT))
	@$(CGEN) -sign "$(strip $(NET_PATH))"\$(strip $(CODEGEN_DATABASE_OUT))
  endif
	copy /Y $(strip $(CODEGEN_DATABASE_OUT)).* $(strip $(TARGDIR))
endif
endif
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


# *************************************************************************
# Clean Generated Code Sources
# *************************************************************************
cleancodegen:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))	
	@perl -e "print 'cleancodegen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifneq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	@echo clean codegen list
   # $(CODE_GEN_LST) should be copied to another place then delete
	@if exist $(CODE_GEN_LST) \
		(copy /y $(CODE_GEN_LST) make\~codegenlis.tmp >NUL) & \
		(for /f %%i in ($(CODE_GEN_LST)) do \
			(if exist %%i del %%i) \
		) & \
		(del $(CODE_GEN_LST))
  ifeq ($(strip $(MODIS_CONFIG)),TRUE)
	@if not exist $(strip $(RULESDIR))\codegen_dep \
		(mkdir $(strip $(RULESDIR))\codegen_dep) \
	else \
		(if exist $(strip $(RULESDIR))\codegen_dep\*.* del /q $(strip $(RULESDIR))\codegen_dep\*.*)
  endif
endif
	@perl -e "print 'cleancodegen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


## clean_codegen_intermedia_file
cci clean_codegen : cleancodegen


# *************************************************************************
# Clean 3 emi setting related files
# *************************************************************************
emiclean:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'emiclean START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

	@echo Clean EMI settings
	@if exist $(strip $(EMI_GENERATOR)) \
		(perl $(strip $(EMI_GENERATOR)) TRUE $(strip $(MEMORY_DEVICE_HDR)) $(strip $(THE_MF)) > $(strip $(COMPLOGDIR))\emigen.log) 2>&1

	@perl -e "print 'emiclean END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


# *************************************************************************
# Generate emi settings based on configurations in custom_MemoryDevice.h
# *************************************************************************
emigen:
$(eval $(call CheckNeedDependTarget,emigen,pregen_dep))
ifeq ($(strip $(DUMMY_LIS)),TRUE)
$(strip $(RULESDIR_TARGET))\pregen_dep\emigen.det: FORCE
else
$(strip $(RULESDIR_TARGET))\pregen_dep\sysgen_conf.det: $(strip $(RULESDIR_TARGET))\pregen_dep\emigen.det
$(strip $(RULESDIR_TARGET))\pregen_dep\emigen.det: $(NEED_CHECK_CODEGEN_LIST)
endif

   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'emigen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	-@echo $@: $?
endif
	@if not exist $(COMPLOGDIR) (mkdir $(COMPLOGDIR))
	@echo Generate EMI settings
	@if exist $(strip $(EMI_GENERATOR)) \
		(perl $(strip $(EMI_GENERATOR)) FALSE $(strip $(MEMORY_DEVICE_HDR)) $(strip $(THE_MF)) FALSE $(strip $(INSIDE_MTK)) >$(strip $(COMPLOGDIR))\emigen.log 2>&1)

	@if not exist $(patsubst %\,%,$(dir $@)) mkdir $(patsubst %\,%,$(dir $@))
	@perl tools\pack_dep_gen.pl $@ $@ $(strip $(COMPLOGDIR)) emigen\.log

	@perl -e "print 'emigen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


mcp_check:
ifneq ($(call Upper,$(strip $(LEVEL))),VENDOR)
$(eval $(call CheckNeedDependTarget,mcp_check,pregen_dep))
ifeq ($(strip $(DUMMY_LIS)),TRUE)
$(strip $(RULESDIR_TARGET))\pregen_dep\mcp_check.det: FORCE
else
$(strip $(RULESDIR_TARGET))\pregen_dep\sysgen_conf.det: $(strip $(RULESDIR_TARGET))\pregen_dep\mcp_check.det
$(strip $(RULESDIR_TARGET))\pregen_dep\mcp_check.det: $(NEED_CHECK_CODEGEN_LIST)
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'mcp_check START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	-@echo $@: $?
endif
	@if not exist $(COMPLOGDIR) (mkdir $(COMPLOGDIR))
	@echo perl .\tools\emiMCPcheck.pl $(strip $(PLATFORM)) $(call Upper,$(strip $(PROJECT))) $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))
	@echo $(strip $(COMPLOGDIR))\mcp_check.log
	@perl .\tools\emiMCPcheck.pl $(call Upper,$(strip $(PLATFORM))) $(call Upper,$(strip $(PROJECT))) $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER)) > $(strip $(COMPLOGDIR))\mcp_check.log

	@echo [Dependency] tools\emiMCPcheck.pl >$(basename $@).log
	@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $@)) $(basename $(notdir $@))\.log
	@if exist $(basename $@).log del /q $(basename $@).log
	@perl -e "print 'mcp_check END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif

# *************************************************************************
# Generate object list for scatter file
# *************************************************************************
obj_list_gen:
$(eval $(call CheckNeedDependTarget,obj_list_gen,pregen_dep))
ifeq ($(strip $(DUMMY_LIS)),TRUE)
$(strip $(RULESDIR_TARGET))\pregen_dep\obj_list_gen.det: FORCE
else
$(strip $(RULESDIR_TARGET))\pregen_dep\obj_list_gen.det: $(NEED_CHECK_CODEGEN_LIST)
endif
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if exist $(FIXPATH)\tools\objListGen.pl \
		(perl $(FIXPATH)\tools\objListGen.pl $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) $(strip $(THE_MF)) $(strip $(INSIDE_MTK)) $(strip $(DUMMY_LIS)) $(strip $(OBJ_SYS_AUTO_GEN))>$(strip $(COMPLOGDIR))\obj_list_gen.log 2>&1) & \
		(if ERRORLEVEL 1 echo Error: obj_list_gen.pl failed. Please check $(strip $(COMPLOGDIR))\obj_list_gen.log & exit 1)
	@perl tools\pack_dep_gen.pl $@ $@ $(strip $(COMPLOGDIR)) obj_list_gen\.log
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *************************************************************************
# Generate custom\system\BB\* base on makefile and EMI.h
# *************************************************************************
sysgen: sys_auto_gen sys_mem_gen
sys_auto_gen: sysgen_conf ckscatter
sysgen_conf: emigen mcp_check obj_list_gen

$(eval $(call CheckNeedDependTarget,sysgen_conf,pregen_dep))
ifeq ($(strip $(DUMMY_LIS)),TRUE)
$(strip $(RULESDIR_TARGET))\pregen_dep\sysgen_conf.det: FORCE
else
$(strip $(RULESDIR_TARGET))\pregen_dep\sysgen_conf.det: $(NEED_CHECK_CODEGEN_LIST) $(strip $(RULESDIR_TARGET))\pregen_dep\emigen.det $(strip $(RULESDIR_TARGET))\pregen_dep\obj_list_gen.det
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'sysgen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	-@echo $@: $?
endif
	@echo [Dependency] $(FIXPATH)\tools\sys_auto_gen.pl $(strip $(THE_MF)) >$(strip $(COMPLOGDIR))\sysgen.log
	@(perl $(FIXPATH)\tools\sys_auto_gen.pl $(SCATTERFILE) $(BL_SCATTERFILE) $(FOTA_SCATTERFILE) $(strip $(THE_MF)) $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) $(strip $(NEED_BUILD_BOOTLOADER)) $(strip $(INSIDE_MTK)) $(strip $(DUMMY_LIS)) $(strip $(FACTORY_BIN_FOLDER))\\FACTORY_ROM $(strip $(OBJ_SYS_AUTO_GEN)) $(strip $(TS_SCATTERFILE)) "$(CC)" "$(VIA)">$(strip $(COMPLOGDIR))\sysgen.log 2>&1) & \
		(if ERRORLEVEL 1 echo Error: sysgen_conf Failed. Please check $(strip $(COMPLOGDIR))\sysgen.log & exit 1)
	@perl tools\pack_dep_gen.pl $@ $@ $(strip $(COMPLOGDIR)) sysgen\.log
	@perl -e "print 'sysgen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


# *************************************************************************
# Calculate system memory size and generate header files
# *************************************************************************
sys_mem_gen:
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
sys_mem_gen: genlog
endif
ifneq ($(call Upper,$(strip $(LEVEL))),VENDOR)
$(eval $(call CheckNeedDepend,sys_mem_gen,pregen_dep))
$(strip $(RULESDIR))\pregen_dep\sys_mem_gen.det: make\config\config.mak $(NEED_CHECK_CODEGEN_LIST)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	-@echo $@: $?
endif
		@if exist make\~config_optInc.tmp (del /q make\~config_optInc.tmp)
# when make new, genmoduleinfo->genlog->mmi_feature_check->flavor_conf will be called twice, it will update dep file again
		@tools\make.exe -fmake\gsm2.mak -r -R --no-print-directory --old-file=genlog MODIS_CONFIG=$(strip $(MODIS_CONFIG)) MODULELIS=config.lis genmoduleinfo
  ifeq ($(strip $(MODIS_CONFIG)),TRUE)
		@echo System memory calculation for MoDIS>$(strip $(COMPLOGDIR))\syscomp.log
  else
		@echo System memory calculation for Target>$(strip $(COMPLOGDIR))\syscomp.log
		@tools\strcmpex.exe inc inc e make\~config_optInc.tmp $(foreach inc,$(COMMINCDIRS),-I$(inc))
		@tools\strcmpex.exe def def e make\~config_opt.tmp $(foreach def,$(COM_DEFS),-D$(def))
		@type make\~config_opt.tmp >> make\~config_optInc.tmp
  endif
		@if exist $(strip $(MODULE_INFO_DIR))\config \
			(for /F %%i in ($(strip $(MODULE_INFO_DIR))\config\config.def) do \
				(echo -D%%i >> make\~config_optInc.tmp)) & \
			(for /F %%i in ($(strip $(MODULE_INFO_DIR))\config\config.inc) do \
				(echo -I%%i >> make\~config_optInc.tmp))
		@if not exist $(patsubst %\,%,$(dir $@)) mkdir $(patsubst %\,%,$(dir $@))
		@if exist config\src\hal\syscomp_config.c \
      ($(CC) $(VIA) make\~config_optInc.tmp -c config\src\hal\syscomp_config.c -o ~syscomp_config.o --no_depend_system_headers 2>>$(strip $(COMPLOGDIR))\sys_mem_gen.log) && \
      (@perl tools\sys_mem_gen.pl ~syscomp_config.o $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) $(MODIS_CONFIG) $(strip $(COMPLOGDIR)) $(strip $(THE_MF))>>$(strip $(COMPLOGDIR))\sys_mem_gen.log) & \
				(if ERRORLEVEL 1 echo Error: System memory calculation failed. Please check $(strip $(COMPLOGDIR))\sys_mem_gen.log & exit 1)

	@echo [Dependency] tools\sys_mem_gen.pl >$(basename $@).log
	@perl tools\pack_dep_gen.pl $@ $@ $(patsubst %\,%,$(dir $@)) $(basename $(notdir $@))\.(log^|d)
	@if exist $(basename $@).d del /q $(basename $@).d
	@if exist $(basename $@).log del /q $(basename $@).log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif


gen_sfini:
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

	@if exist $(strip $(TARGDIR))\$(TARGNAME).lis \
		perl tools\MarginCalc.pl $(strip $(TARGDIR))\$(TARGNAME).lis >$(strip $(COMPLOGDIR))\MarginCalc.log 2>&1 & \
		(if ERRORLEVEL 1 (echo tools\MarginCalc.pl Error. Please check $(strip $(COMPLOGDIR))\MarginCalc.log & exit 1))

	@if exist $(strip $(COMPLOGDIR))\libs.log (del /f /q  $(strip $(COMPLOGDIR))\libs.log)
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@for /d %%i in ($(COMPLIST)) do \
		(echo $(COMPLIBDIR)\%%i.lib >> $(strip $(COMPLOGDIR))\libs.log)
else
  ifneq ($(strip $(MTK_LIBS)),)
		@tools\strcmpex.exe abc abc e $(strip $(COMPLOGDIR))\libs.log $(MTK_LIBS)
		@perl tools\lnitem.pl $(strip $(COMPLOGDIR))\libs.log
  endif
endif

	@perl tools\libinfo.pl $(strip $(COMPLOGDIR))\libs.log > $(strip $(COMPLOGDIR))\libinfo.log 2>&1 & \
		(if ERRORLEVEL 1 (echo tools\libinfo.pl Error. Please check $(strip $(COMPLOGDIR))\libinfo.log & exit 1))

	@echo $(strip $(INFOLOG)) > $(strip $(TSTDIR))\database\sf.ini
	@echo $(strip $(THE_MF)) >> $(strip $(TSTDIR))\database\sf.ini
	@echo $(strip $(MMI_FEATURES_LOG)) >> $(strip $(TSTDIR))\database\sf.ini
	@echo $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h >> $(strip $(TSTDIR))\database\sf.ini
	@echo $(strip $(COMPLOGDIR))\emigen.log >> $(strip $(TSTDIR))\database\sf.ini
	@echo $(strip $(COMPLOGDIR))\objcheck.log >> $(strip $(TSTDIR))\database\sf.ini
	@echo $(strip $(COMPLOGDIR))\ckSysDrv.log >> $(strip $(TSTDIR))\database\sf.ini
	@echo $(strip $(COMPLOGDIR))\drv_features_option.log >> $(strip $(TSTDIR))\database\sf.ini
	@echo $(strip $(COMPLOGDIR))\MarginCalc.log >> $(strip $(TSTDIR))\database\sf.ini
	@echo $(strip $(COMPLOGDIR))\libinfo.log >> $(strip $(TSTDIR))\database\sf.ini

  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


# MAKEFILE_LIST: internal variable to record all makefile included
postgen:
	@if not exist $(strip $(RULESDIR))\postgen_dep mkdir $(strip $(RULESDIR))\postgen_dep
	@tools\strcmpex.exe ABC ABC e $(strip $(RULESDIR))\postgen_dep\makefile_list.log [Dependency] $(MAKEFILE_LIST) $(MODULE_MAKEFILE_LIST)
	@perl tools\pack_dep_gen.pl $(strip $(RULESDIR))\postgen_dep\postgen.det $(strip $(RULESDIR))\postgen_dep\postgen.det $(strip $(RULESDIR))\postgen_dep makefile_list\.log
ifneq ($(AUTO_CHECK_DEBUG),TRUE)
	@if exist $(strip $(RULESDIR))\postgen_dep\*.log del $(strip $(RULESDIR))\postgen_dep\*.log
endif


