.PHONY: new_modis gen_modis codegen_modis clean_modis remake_modis update_modis ap_modis codegen_vre_modis rel_at_modis
.PHONY: gen_infolog_modis modis_copied_files modis_copied_dirs modis_touched_files createMoDIS

new_modis: gen_modis codegen_modis clean_modis remake_modis
ifeq ($(strip $(call Upper,$(MTK_INTERNAL))),TRUE)
  ifeq ($(strip $(MoDIS)),AutoPower)
    new_modis: ap_modis
  endif
# new_modis: rel_at_modis
endif

update_modis: gen_modis codegen_modis remake_modis
gen_modis: gen_infolog_modis gen_infomakelog
ifneq ($(strip $(call Upper,$(LEVEL))),LEVEL2_OBJ)
  gen_modis: genmoduleinfo
endif
# modis_copied_files modis_copied_dirs
gen_modis: createMoDIS
ifneq ($(filter UMTS HSPA TDD128 TDD128DPA TDD128HSPA,$(strip $(call Upper,$(PROJECT)))),)
  codegen_modis: cleancodegen sys_mem_gen_modis umts_gen cgen mcddll_update
else
  codegen_modis: cleancodegen sys_mem_gen_modis cgen mcddll_update
endif
codegen_modis: mtegen
clean_codegen_modis: cleancodegen
sys_mem_gen_modis: sys_mem_gen

define modis_copy_one_file
#.PHONY: $(2)
$(2): $(1)
	@echo copy $$< $$@
	@if not exist $$(dir $$@) mkdir $$(dir $$@)
	@copy /y $$< $$@ >NUL
endef

define modis_copy_one_dir
.PHONY: $(2)
$(2): $(1)
	@echo xcopy $$< $$@
	@if not exist $$@ mkdir $$@
	@xcopy /e/y $$< $$@ >NUL
endef

define modis_touch_one_file
$(1):
# create dummy files before they are generated in codegen_modis
	@echo touch $$@
	@if not exist $$(dir $$@) mkdir $$(dir $$@)
	@copy /y NUL $$(subst /,\,$$@) >NUL
endef

modis_copied_files:
modis_copied_dirs:
modis_touched_files:

$(foreach argu,$(MODIS_COPY_FILE), \
  $(eval SYMBOL_COMMA := ,) \
  $(eval MODIS_COPY_SRC := $(word 1,$(subst $(SYMBOL_COMMA), ,$(argu)))) \
  $(eval MODIS_COPY_DST := $(word 2,$(subst $(SYMBOL_COMMA), ,$(argu)))) \
  $(eval $(call modis_copy_one_file,$(MODIS_COPY_SRC),$(MODIS_COPY_DST))) \
  $(eval modis_copied_files: $(MODIS_COPY_DST)) \
)
$(foreach argu,$(MODIS_COPY_DIR), \
  $(eval SYMBOL_COMMA := ,) \
  $(eval MODIS_COPY_SRC := $(patsubst %\,%,$(word 1,$(subst $(SYMBOL_COMMA), ,$(argu))))) \
  $(eval MODIS_COPY_DST := $(patsubst %\,%,$(word 2,$(subst $(SYMBOL_COMMA), ,$(argu))))) \
  $(eval $(call modis_copy_one_dir,$(MODIS_COPY_SRC),$(MODIS_COPY_DST))) \
  $(eval modis_copied_dirs: $(MODIS_COPY_DST)) \
)
$(foreach argu,$(MODIS_TOUCH_FILE), \
  $(eval $(call modis_touch_one_file,$(argu))) \
  $(eval modis_touched_files: $(argu)) \
)
MODIS_COPY_SRC :=
MODIS_COPY_DST :=

gen_infolog_modis:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if exist $(strip $(TARGDIR))\build.log \
		(@perl -e "print '$@ START TIME='";>>$(strip $(TARGDIR))\build.log & \
		@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)

	@if not exist $(COMPLOGDIR) mkdir $(COMPLOGDIR)
	@if not exist $(MODISLOGDIR) mkdir $(MODISLOGDIR)
	@if not exist $(strip $(RULESDIR))\pregen_dep mkdir $(strip $(RULESDIR))\pregen_dep
	@tools\strcmpex.exe def def e make\~def.tmp $(sort $(COM_DEFS))
	@tools\strcmpex.exe inc inc e make\~inc.tmp $(COMMINCDIRS)
	@perl tools\lnitem.pl make\~def.tmp
	@perl tools\lnitem.pl make\~inc.tmp

	@(echo [ COMMON OPTION ]> $(INFOLOG_MODIS)) && \
	(type make\~def.tmp >> $(INFOLOG_MODIS))
	@(echo [ COMMON INCLUDE PATH ] >> $(INFOLOG_MODIS)) && \
	(type make\~inc.tmp >> $(INFOLOG_MODIS))

	@if exist $(strip $(TARGDIR))\build.log \
		(@perl -e "print '$@ END TIME='";>>$(strip $(TARGDIR))\build.log & \
		@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

createMoDIS: #$(strip $(THE_MF)) make\~inc_def.tmp
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@tools\make -fmake\Gsm2.mak -r -R $(CMD_ARGU) --no-print-directory AUTO_CHECK_DEPEND=$(AUTO_CHECK_DEPEND) AUTO_CHECK_CGEN=$(AUTO_CHECK_CGEN) MODIS_CONFIG=$(strip $(MODIS_CONFIG)) MODIS_UESIM=$(strip $(MODIS_UESIM)) modis_copied_files modis_copied_dirs modis_touched_files
ifneq ($(strip $(call Upper,$(LEVEL))),LEVEL2_OBJ)
  ifeq ($(strip $(DO_UPDATE_MODULE)),TRUE)
	@echo perl createMoDIS.pl ../$(strip $(THE_MF)) $(strip $(MODIS_UESIM)) "$(strip $(MODULELIS))"
	@(cd $(strip $(MODISDIR))) && \
	(perl createMoDIS.pl ../$(strip $(THE_MF)) $(strip $(MODIS_UESIM)) "$(strip $(MODULELIS))") && \
	(cd ..)
  else
	@echo perl createMoDIS.pl ../$(strip $(THE_MF)) $(strip $(MODIS_UESIM))
	@(cd $(strip $(MODISDIR))) && \
	(perl createMoDIS.pl ../$(strip $(THE_MF)) $(strip $(MODIS_UESIM))) && \
	(cd ..)
  endif
endif
	@echo gen_modis done.
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

clean_modis:
ifneq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(DO_CLEAN_MODULE)),TRUE)
	@(cd $(strip $(MODISDIR))) && \
	(for %%i in ($(CLEAN_MODS)) do \
		(vcbuild.exe /clean /nologo "%%i\%%i$(strip $(MODIS_SUFFIX)).vcproj" "$(strip $(MODIS_MODE))|Win32") \
	) & \
	(cd ..)
	@for %%i in ($(CLEAN_MODS)) do \
		(if exist $(strip $(MODISDIR))\_BUILD_LOG\%%i$(strip $(MODIS_SUFFIX)).log del /q $(strip $(MODISDIR))\_BUILD_LOG\%%i$(strip $(MODIS_SUFFIX)).log)
else
	@(cd $(strip $(MODISDIR))) && \
	(vcbuild.exe /clean /nologo $(strip $(MODIS_UESIM)).sln "$(strip $(MODIS_MODE))|Win32") & \
	(cd ..)
	@for %%i in ($(COMPLIST)) do \
		(if exist $(strip $(MODISDIR))\_BUILD_LOG\%%i$(strip $(MODIS_SUFFIX)).log del /q $(strip $(MODISDIR))\_BUILD_LOG\%%i$(strip $(MODIS_SUFFIX)).log)
endif
	@for %%i in ($(strip $(MODIS_UESIM)) _PowerOn) do \
		(if exist $(strip $(MODISDIR))\_BUILD_LOG\%%i.log del /q $(strip $(MODISDIR))\_BUILD_LOG\%%i.log)
	@echo clean_modis done.
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif

remake_modis: cleanbin
ifeq ($(strip $(REDUCE_HEADER_DEPTH)),TRUE)
  remake_modis: startbuildlibs
endif
remake_modis: $(strip $(MODISDIR))\MoDIS\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\MoDIS.exe
ifeq ($(strip $(call Upper,$(MTK_INTERNAL))),TRUE)
  remake_modis: scan_modis
endif
remake_modis: done_modis
MODIS_COMPLIBLIST := $(foreach lib,$(filter-out modis.lib,$(COMPLIBLIST)),$(strip $(MODISDIR))\$(basename $(notdir $(lib)))\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\$(basename $(notdir $(lib))).lib)
$(MODIS_COMPLIBLIST): FORCE
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl tools\time.pl
ifneq ($(strip $(MODIS_INCREDIBUILD)),TRUE)
    # IncrediBuild == FALSE
	@echo vcbuild "$(strip $(MODISDIR))\$(basename $(notdir $@))\$(basename $(notdir $@))$(strip $(MODIS_SUFFIX)).vcproj" "$(strip $(MODIS_MODE))|Win32" /logfile:"$(strip $(MODISDIR))\_BUILD_LOG\$(basename $(notdir $@))$(strip $(MODIS_SUFFIX)).log"
	@(vcbuild.exe /nologo "$(strip $(MODISDIR))\$(basename $(notdir $@))\$(basename $(notdir $@))$(strip $(MODIS_SUFFIX)).vcproj" "$(strip $(MODIS_MODE))|Win32" /logfile:"$(strip $(MODISDIR))\_BUILD_LOG\$(basename $(notdir $@))$(strip $(MODIS_SUFFIX)).log" >NUL) & \
	(if not errorlevel 1 \
		(echo       ==^> [P]) \
	else ( \
		(echo       ==^> [Fail]) & \
		(if exist $(strip $(MODISDIR))\$(basename $(notdir $@))\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\$(basename $(notdir $@)).lib del $(strip $(MODISDIR))\$(basename $(notdir $@))\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\$(basename $(notdir $@)).lib) \
	)) & \
	(echo.)
else
    # IncrediBuild == TRUE
	@echo BuildConsole "$(strip $(MODISDIR))\$(basename $(notdir $@))\$(basename $(notdir $@))$(strip $(MODIS_SUFFIX)).vcproj" /CFG="$(strip $(MODIS_MODE))|Win32" /LOG="$(strip $(MODISDIR))\_BUILD_LOG\$(basename $(notdir $@))$(strip $(MODIS_SUFFIX)).log" /SILENT
	@(BuildConsole.exe "$(strip $(MODISDIR))\$(basename $(notdir $@))\$(basename $(notdir $@))$(strip $(MODIS_SUFFIX)).vcproj" /CFG="$(strip $(MODIS_MODE))|Win32" /LOG="$(strip $(MODISDIR))\_BUILD_LOG\$(basename $(notdir $@))$(strip $(MODIS_SUFFIX)).log" /SILENT) & \
	(if not errorlevel 1 \
		(echo       ==^> [P]) \
	else ( \
		(echo       ==^> [Fail]) & \
		(if exist $(strip $(MODISDIR))\$(basename $(notdir $@))\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\$(basename $(notdir $@)).lib del $(strip $(MODISDIR))\$(basename $(notdir $@))\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\$(basename $(notdir $@)).lib) \
	)) & \
	(echo.)
endif
ifeq ($(strip $(REDUCE_HEADER_DEPTH)),TRUE)
  ifneq ($(filter $(strip $(MMI_VERSION)),PLUTO_MMI NEPTUNE_MMI IOT_MMI),)
	@perl tools\get_log_modis.pl $(strip $(MODISDIR))\_BUILD_LOG\$(basename $(notdir $@))$(strip $(MODIS_SUFFIX)).log tools\copy_mmi_include_h.bat
  endif
endif
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))


ifneq ($(filter $(MAKECMDGOALS),new new_modis),)
  ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
    MODIS_BUILD_LIB_FIRST := TRUE
    # -smart new_modis
  else
    # new_modis
    MODIS_BUILD_LIB_FIRST := FALSE
  endif
else
  # remake_modis or remake_uesim
  MODIS_BUILD_LIB_FIRST := TRUE
  #ifeq ($(strip $(DO_REMAKE_MODULE)),TRUE)
  #else ifneq ($(strip $(MODIS_INCREDIBUILD)),TRUE)
  #endif
endif

ifeq ($(strip $(MODIS_BUILD_LIB_FIRST)),TRUE)
$(strip $(MODISDIR))\MoDIS\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\MoDIS.exe: $(MODIS_COMPLIBLIST)
endif
$(strip $(MODISDIR))\MoDIS\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\MoDIS.exe: FORCE
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifneq ($(strip $(MODIS_INCREDIBUILD)),TRUE)
  # IncrediBuild == FALSE
  ifeq ($(strip $(MODIS_BUILD_LIB_FIRST)),FALSE)
    # new_modis
      ifeq ($(strip $(REDUCE_HEADER_DEPTH)),TRUE)
        ifneq ($(filter $(strip $(MMI_VERSION)),PLUTO_MMI NEPTUNE_MMI IOT_MMI),)
	@(cd $(strip $(MODISDIR))) && (perl modisDepend.pl $(strip $(MODIS_MODE)) TRUE) && (cd ..)
        else
	@(cd $(strip $(MODISDIR))) && (perl modisDepend.pl $(strip $(MODIS_MODE)) FALSE) && (cd ..)
        endif
      else
	@(cd $(strip $(MODISDIR))) && (perl modisDepend.pl $(strip $(MODIS_MODE)) FALSE) && (cd ..)
      endif
  else
    # remake_modis or UESim
	@perl tools\time.pl
	@echo vcbuild "$(strip $(MODISDIR))\$(strip $(MODIS_UESIM)).sln" "$(strip $(MODIS_MODE))|Win32" /logfile:"$(strip $(MODISDIR))\_BUILD_LOG\$(strip $(MODIS_UESIM)).log"
	@(vcbuild.exe /nologo "$(strip $(MODISDIR))\$(strip $(MODIS_UESIM)).sln" "$(strip $(MODIS_MODE))|Win32" /logfile:"$(strip $(MODISDIR))\_BUILD_LOG\$(strip $(MODIS_UESIM)).log" >NUL) & \
	(if not errorlevel 1 \
		(echo       ==^> [P]) \
	else ( \
		(echo       ==^> [Fail]) & \
		(if exist $(strip $(MODISDIR))\MoDIS\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\MoDIS.exe del $(strip $(MODISDIR))\MoDIS\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\MoDIS.exe) \
	)) & \
	(echo.)
  endif
else
  # IncrediBuild == TRUE
	@perl tools\time.pl
	@echo BuildConsole "$(strip $(MODISDIR))\$(strip $(MODIS_UESIM)).sln" /CFG="$(strip $(MODIS_MODE))|Win32" /LOG="$(strip $(MODISDIR))\_BUILD_LOG\$(strip $(MODIS_UESIM)).log" /SILENT
	@(BuildConsole.exe "$(strip $(MODISDIR))\$(strip $(MODIS_UESIM)).sln" /CFG="$(strip $(MODIS_MODE))|Win32" /LOG="$(strip $(MODISDIR))\_BUILD_LOG\$(strip $(MODIS_UESIM)).log" /SILENT) & \
	(if not errorlevel 1 \
		(echo       ==^> [P]) \
	else ( \
		(echo       ==^> [Fail]) & \
		(if exist $(strip $(MODISDIR))\MoDIS\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\MoDIS.exe del $(strip $(MODISDIR))\MoDIS\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\MoDIS.exe) \
	)) & \
	(echo.)
endif
ifeq ($(strip $(REDUCE_HEADER_DEPTH)),TRUE)
  ifneq ($(filter $(strip $(MMI_VERSION)),PLUTO_MMI NEPTUNE_MMI IOT_MMI),)
	@perl tools\get_log_modis.pl $(strip $(MODISDIR))\_BUILD_LOG\$(strip $(MODIS_UESIM)).log tools\copy_mmi_include_h.bat
  endif
endif
	@if exist $(strip $(HEADER_TEMP)) rmdir /S /Q $(strip $(HEADER_TEMP))
	@if not exist $(strip $(MODISDIR))\MoDIS\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\MoDIS.exe exit 2
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

scan_modis:
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo $@ for $(sort $(COMPSCANLIST)) ...
	@if not exist $(RULESDIR) mkdir $(RULESDIR)
	@if not exist $(RULESDIR)\log_dep mkdir $(RULESDIR)\log_dep
ifneq ($(filter $(MAKECMDGOALS),scan_modis),)
	@for %%i in ($(sort $(COMPSCANLIST))) do ((tools\IDB_Parser\IDB_Parser.exe +p MoDIS_VC9\%%i\$(strip $(MODIS_MODE))\vc90.idb >$(RULESDIR)\log_dep\%%i.log) && (perl tools\pack_dep_gen.pl --modis $(RULESDIR)\%%i.dep %%i.lib $(RULESDIR)\log_dep \b%%i\.log))
else
	@for %%i in ($(sort $(filter-out modis,$(COMPLIST)))) do ((tools\IDB_Parser\IDB_Parser.exe +p MoDIS_VC9\%%i\$(strip $(MODIS_MODE))\vc90.idb >$(RULESDIR)\log_dep\%%i.log) && (perl tools\pack_dep_gen.pl --modis $(RULESDIR)\%%i.dep %%i.lib $(RULESDIR)\log_dep \b%%i\.log))
endif
	@for %%i in (MoDIS) do ((tools\IDB_Parser\IDB_Parser.exe +p MoDIS_VC9\%%i\$(strip $(MODIS_MODE))\vc90.idb >$(RULESDIR)\log_dep\%%i.log) && (perl tools\pack_dep_gen.pl --modis $(RULESDIR)\%%i.dep %%i.lib $(RULESDIR)\log_dep \b%%i\.log))
	@echo $@ done.
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

done_modis: $(strip $(MODISDIR))\MoDIS\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\MoDIS.exe
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo Check if any error happened during MoDIS build process ...
	@if exist $(strip $(MODISDIR))\MoDIS\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\MoDIS.exe \
		perl tools\parse_comp_err.pl $(strip $(CUSTOMER)) $(MODIS_CONFIG)
	@if exist $(strip $(MODISDIR))\MoDIS\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\MoDIS.exe if exist $(strip $(FIXPATH))\comp_err.txt \
		(perl -e "open F,'<$(strip $(FIXPATH))\comp_err.txt';my $$backup=$$/;undef $$/;my $$reading=<F>;close F;if($$reading =~ /might be failed/i){print 'Some error happened during MoDIS build process. Delete the binary file.'.\"\n\";system('del /F $(strip $(MODISDIR))\MoDIS\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\MoDIS.exe');exit 1;};")
	@if not exist $(strip $(MODISDIR))\MoDIS\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\MoDIS.exe exit 2
	@echo Cleaning temporary files ...
	@if exist make\~*.tmp del /f /q make\~*.tmp
ifeq ($(call Upper,$(strip $(MODIS_UESIM))),MODIS)
ifneq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	@echo Generate MSLT folder ...
	@(cd $(strip $(MODISDIR))) && (if exist createMSLT.bat if exist modisReleaseL1.pl (call createMSLT.bat MSLT >nul)) && (cd ..)
endif
endif
	@echo remake_modis done.
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ap_modis: .\$(strip $(MODISDIR))\MoDIS\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\MoDIS.exe
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifneq ($(filter EMPTY_MMI EXTERNAL_MMI,$(strip $(MMI_VERSION))),)
	@echo Skip MoDIS Auto PowerOn Test for $(strip $(CUSTOMER))_$(strip $(PROJECT)) due to MMI_VERSION=$(strip $(MMI_VERSION))
else ifeq ($(strip $(VENUS_MMI)),VENUS_3D)
	@echo Skip MoDIS Auto PowerOn Test for $(strip $(CUSTOMER))_$(strip $(PROJECT)) due to VENUS_MMI=$(strip $(VENUS_MMI))
else
	@(cd $(strip $(MODISDIR))) && \
	(perl modisAutoTest.pl ap_modis $(strip $(MODIS_MODE))) && \
	(cd ..)
endif
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

rel_at_modis: .\$(strip $(MODISDIR))\MoDIS\$(strip $(MODIS_MODE))$(strip $(MODIS_SUFFIX))\MoDIS.exe
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@(cd $(strip $(MODISDIR))) && \
	(perl modisAutoTest.pl rel_at_modis $(strip $(MODIS_MODE)) $(strip $(THE_MF)) ..\$(VERNOFILE)) && \
	(cd ..)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

$(eval $(call CgenPreprocess,$(MODISDIR)\MoDIS\Database\MRE_structure.lst,$(MODISDIR)\MoDIS\database\mre_modis.db,mre_modis.det))

codegen_vre_modis: $(strip $(RULESDIR))\codegen_dep\mre_modis.det $(strip $(TSTDIR))\database\$(CGEN_DEF_FILE) $(strip $(TSTDIR))\database\Pc_Cnf $(VERNOFILE) $(THE_MF)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	$(CGEN) -c $(MODISDIR)\MoDIS\database\mre_modis.db $(strip $(TSTDIR))\database\$(CGEN_DEF_FILE) $(strip $(TSTDIR))\database\Pc_Cnf $(MODISDIR)\MoDIS\database\mre_modis_cnf.int $(MODISDIR)\MoDIS\database\database_mre MoDIS $(strip $(VERNO)) 2>$(MODISDIR)\_BUILD_LOG\codegen_vre_modis.log
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

mtegen:
ifneq ($(strip $(call Upper,$(LEVEL))),VENDOR)
ifneq ($(filter $(strip $(MMI_VERSION)),PLUTO_MMI IOT_MMI),)
  RUN_MTEGEN_INPUT := plutommi\Customer\CustResource\PLUTO_MMI\MMI_theme_file.xls plutommi\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_theme_file.xls
  RUN_MTEGEN_INPUT := $(call CheckNeedCopy,$(RUN_MTEGEN_INPUT))
$(eval $(call CheckNeedDepend,mtegen,pregen_dep))
$(strip $(RULESDIR))\pregen_dep\mtegen.det:
ifneq ($(strip $(RUN_MTEGEN_INPUT)),)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo perl plutommi\Customer\ResGenerator\mte_excel_gen.pl plutommi\Framework\MTE\MTEInc\mte_data.h $(RUN_MTEGEN_INPUT) $(VERNO)
	@perl plutommi\Customer\ResGenerator\mte_excel_gen.pl plutommi\Framework\MTE\MTEInc\mte_data.h $(RUN_MTEGEN_INPUT) $(VERNO)
	@if not exist $(patsubst %\,%,$(dir $@)) (mkdir $(patsubst %\,%,$(dir $@))) else (if exist $@ del /q $@)
	@echo $@: plutommi\Customer\ResGenerator\mte_excel_gen.pl $(RUN_MTEGEN_INPUT) $(strip $(VERNOFILE)) >$@
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@$(strip $(MODIS_SUFFIX)),T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
else
	@(echo [ERROR] not found MMI_theme_file.xls) && (exit 2)
endif
endif
endif

