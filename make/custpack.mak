
# *************************************************************************
# Set PHONY
# *************************************************************************
.PHONY : custpackini custpack clean_theme run_custpack theme_bin check_custpack_obj

ifeq ($(strip $(COMPILER)),RVCT)
  ifeq ($(strip $(MULTIPLE_BINARY_FILES)),TRUE)
    CUSTPACK_LNKOPT = --map --info sizes,totals --symbols --xref --libpath $(DIR_ARMLIB) --remove
    CUSTPACK_LNKOPT += --keep mtk_theme_header
  endif
  ifeq ($(strip $(MULTIPLE_BINARY_FILES)),TRUE)
#    CUSTPACK_LNKOPT = -remove -map -info sizes,totals,unused -symbols -xref -libpath $(DIR_ARMLIB) 
     CUSTPACK_LNKOPT = --map --info sizes,totals --symbols --xref --remove --libpath $(DIR_ARMLIB) 
     CUSTPACK_LNKOPT += --keep mtk_theme_header
  endif
else
  ifeq ($(strip $(MULTIPLE_BINARY_FILES)),TRUE)
#    CUSTPACK_LNKOPT = -remove -map -info sizes,totals,unused -symbols -xref -libpath $(DIR_ARMLIB) 
     CUSTPACK_LNKOPT = -map -info sizes,totals -symbols -xref -remove -libpath $(DIR_ARMLIB) 
     CUSTPACK_LNKOPT += -keep mtk_theme_header
  endif
endif

# *************************************************************************
# Generate CustPack information
# *************************************************************************
custpackini: nvram_auto_gen check_custpack_obj
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'custpackini START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
	@if not exist $(CUSTPACKDIR) \
		(md $(CUSTPACKDIR))
	@tools\strcmpex.exe def def e make\~cuspack_optInc.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@tools\strcmpex.exe inc inc e make\~cuspack_inc.tmp $(foreach inc,$(COMMINCDIRS),-I$(inc))
	@type make\~cuspack_inc.tmp >> make\~cuspack_optInc.tmp
	@type make\~cuspack_optInc.tmp >> make\~cuspack_theme_optInc.tmp
	@type make\~cuspack_optInc.tmp >> make\~cuspack_nvram_optInc.tmp
	(for /F %%i in ($(strip $(TARGDIR))\module\custom\custom.def) do \
		(echo -D%%i >> make\~cuspack_optInc.tmp) \
	) & \
	(for /F %%i in ($(strip $(TARGDIR))\module\custom\custom.inc) do \
		(echo -I%%i >> make\~cuspack_optInc.tmp) \
	)
ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
	(for /F %%i in ($(strip $(TARGDIR))\module\lcmmiresource\lcmmiresource.def) do \
		(echo -D%%i >> make\~cuspack_theme_optInc.tmp) \
	) & \
	(for /F %%i in ($(strip $(TARGDIR))\module\lcmmiresource\lcmmiresource.inc) do \
		(echo -I%%i >> make\~cuspack_theme_optInc.tmp) \
	)
else
	(for /F %%i in ($(strip $(TARGDIR))\module\mmiresource\mmiresource.def) do \
		(echo -D%%i >> make\~cuspack_theme_optInc.tmp) \
	) & \
	(for /F %%i in ($(strip $(TARGDIR))\module\mmiresource\mmiresource.inc) do \
		(echo -I%%i >> make\~cuspack_theme_optInc.tmp) \
	)
endif

	@if exist custom\common\hal\nvram\nvram_cust_pack.c \
		($(CC) $(VIA) make\~cuspack_optInc.tmp -E custom\common\hal\nvram\nvram_cust_pack.c > ~nvram_cust_pack.c)

	@if exist custom\common\custpack_certs.c \
		($(CC) $(VIA) make\~cuspack_optInc.tmp -E custom\common\custpack_certs.c > ~custom_custpack_certs.c)

	@if exist custom\common\custpack_java_certs.c \
		($(CC) $(VIA) make\~cuspack_optInc.tmp -E custom\common\custpack_java_certs.c > ~custom_custpack_java_certs.c)

	@echo. > ~nvram_tmp.c
	@if exist custom\common\hal\nvram\nvram_data_items.c \
		(for /F %%i in ($(strip $(TARGDIR))\module\nvram\nvram.def) do \
			(echo -D%%i >> make\~cuspack_nvram_optInc.tmp) \
		) & \
		(for /F %%i in ($(strip $(TARGDIR))\module\nvram\nvram.inc) do \
			(echo -I%%i >> make\~cuspack_nvram_optInc.tmp) \
		) & \
		($(CC) $(VIA) make\~cuspack_nvram_optInc.tmp -E custom\common\hal\nvram\nvram_data_items.c >> ~nvram_tmp.c)

	@if exist custom\common\$(strip $(MMI_BASE))\nvram_common_config.c \
		(@if exist custom\app\$(strip $(BOARD_VER))\nvram_user_config.c \
			($(CC) $(VIA) make\~cuspack_optInc.tmp -E custom\app\$(strip $(BOARD_VER))\nvram_user_config.c >> ~nvram_tmp.c) & \
			($(CC) $(VIA) make\~cuspack_optInc.tmp -E custom\common\$(strip $(MMI_BASE))\nvram_common_config.c >> ~nvram_tmp.c) \
		)
	@if exist custom\common\audio_nvram_def.c \
		($(CC) $(VIA) make\~cuspack_optInc.tmp -E custom\common\audio_nvram_def.c >> ~nvram_tmp.c)
	@if exist custom\common\userprofile_nvram_def.c \
		($(CC) $(VIA) make\~cuspack_optInc.tmp -E custom\common\userprofile_nvram_def.c >> ~nvram_tmp.c)

	if exist custom\system\$(strip $(BOARD_VER))\resource_custpack_preamble.c \
		($(CC) $(VIA) make\~cuspack_optInc.tmp -E custom\system\$(strip $(BOARD_VER))\resource_custpack_preamble.c > ~resource_custpack_preamble.c)

ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
	@if exist $(strip $(MMIDIR))\Customer\ResGenerator\retrieve_ext_img_names.pl \
		((cd $(strip $(MMIDIR))\Customer\ResGenerator) & \
		(perl retrieve_ext_img_names.pl $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))$(strip $(DISPLAY_TYPE))$(strip $(MAIN_LCD_SIZE))\))
	@if exist $(strip $(MMIDIR))\Customer\ResGenerator\retrieve_ext_ado_names.pl \
		((cd $(strip $(MMIDIR))\Customer\ResGenerator) & \
		(perl retrieve_ext_ado_names.pl $(strip $(MMIDIR))\Customer\Audio\$(strip $(MMI_PROJ))\))
else
	@if exist $(strip $(MMIDIR))\Customer\ResGenerator\retrieve_ext_img_names.pl \
		((cd $(strip $(MMIDIR))\Customer\ResGenerator) & \
		(perl retrieve_ext_img_names.pl $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))$(strip $(MAIN_LCD_SIZE))\))
	@if exist $(strip $(MMIDIR))\Customer\ResGenerator\retrieve_ext_ado_names.pl \
		((cd $(strip $(MMIDIR))\Customer\ResGenerator) & \
		(perl retrieve_ext_ado_names.pl $(strip $(MMIDIR))\Customer\Audio\PLUTO\))
endif
	@echo retrieve_ext_img_names.pl is done!!!

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
	@if not exist $(CUSTPACKDIR)\cosmos_theme_bin \
		(md $(CUSTPACKDIR)\cosmos_theme_bin)
	(cd plutommi\Customer\Resgenerator\ThemeXML) &\
		(perl ThemeXMLMBAGen.pl $(subst /,\,$(CURDIR))\$(CUSTPACKDIR)\cosmos_theme_bin $(subst /,\,$(CURDIR)))
	@copy /y plutommi\Customer\Resgenerator\ThemeXML\ThemeXMLParser.pl tools\ThemeXMLParser.pl >NUL
endif

	@if exist tools\processExtractObj.pl \
		(perl tools\processExtractObj.pl ~nvram_lid_size.log ~nvram_cust_pack.c $(strip $(CUSTOMER)) $(strip $(PROJECT)) $(strip $(CUSTPACKDIR)) tools\ExtractObj.ini)

# Use extractObj.pl to generate binary files
	@echo Execute extractObj.pl
	@if exist tools\extractObj.pl \
	(perl tools\extractObj.pl)

	@echo Generate the CustPack.ini.
	@if exist tools\processCustPack.pl \
		(if exist $(strip $(MMIDIR))\Customer\CustResource\CustImgNamesExt \
			(if exist $(strip $(MMIDIR))\Customer\CustResource\CustAdoNamesExt \
			(perl tools\processCustPack.pl $(strip $(MMIDIR))\Customer\CustResource\CustImgNamesExt ~nvram_lid_size.log ~nvram_tmp.c ~nvram_cust_pack.c ~resource_custpack_preamble.c $(strip $(MMIDIR))\Customer\CustResource\CustAdoNamesExt $(strip $(CUSTPACKDIR))\THEME_ROM.bin $(strip $(CUSTPACKDIR)) tools\CustPack.ini tools\CustPack.ini $(CODEGEN_RESULT) $(strip $(TARGDIR))\$(TARGNAME).lis $(strip $(TARGDIR))\$(strip $(BIN_FILE)) $(CUSTPACKDIR)\cosmos_theme_bin\VenusTheme.ini ~custom_custpack_certs.c ~custom_custpack_java_certs.c)))

	@echo processCustPack.pl is done!!!
	@echo copy mtk_resgenerator.exe ....
	@if exist $(strip $(MMIDIR))\Customer\ResGenerator\mtk_resgenerator.exe (copy /Y $(strip $(MMIDIR))\Customer\ResGenerator\mtk_resgenerator.exe $(strip $(FIXPATH))\tools\ >NUL)
	@if exist $(strip $(MMIDIR))\Customer\ResGenerator\convert.exe (copy /Y $(strip $(MMIDIR))\Customer\ResGenerator\convert.exe $(strip $(FIXPATH))\tools\ >NUL)

custpack: custpackini theme_bin run_custpack
	@echo Done.
	@perl -e "print 'custpackini END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

clean_theme:
	@if exist $(strip $(OBJSDIR))\theme_rom\themeres.obj (del /q /f $(strip $(OBJSDIR))\theme_rom\themeres.obj)
	@if exist $(strip $(OBJSDIR))\lib\theme_rom.lib (del /q /f $(strip $(OBJSDIR))\lib\theme_rom.lib)
	@if exist $(strip $(CUSTPACKDIR))\THEME_ROM.bin \
		(del /q /f $(strip $(CUSTPACKDIR))\THEME_ROM.bin)

theme_bin: clean_theme gencompbld theme_rom.lib
# Gerate Theme_ROM scatter files, Linker argument file and theme_rom lis files

	@echo Generate the Theme_ROM scatter file.
	if exist tools\genThemeRomScatter.pl \
		(perl tools\genThemeRomScatter.pl tools\CustPack.ini $(strip $(FIXPATH))\ThemeRom_scatter.txt $(strip $(FIXPATH))\~Theme_ROM.tmp $(strip $(CUSTPACKDIR)) theme_rom $(MMIDIR)\Customer\CustResource\themeres.c $(strip $(EMPTY_RESOURCE)) $(CUSTPACK_LNKOPT))

# Use Linker to generate Theme_ROM ELF file
ifeq ($(strip $(DISPLAY_TYPE)),BW)
 ifneq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
	@echo $(strip $(OBJSDIR))\theme_rom\themeres.obj >> $(strip $(FIXPATH))\~Theme_ROM.tmp
	$(strip $(LINK)) $(VIA) $(strip $(FIXPATH))\~Theme_ROM.tmp
	$(strip $(BIN_CREATE)) $(strip $(CUSTPACKDIR))\THEME_ROM.elf $(BIN_FORMAT) -output $(strip $(CUSTPACKDIR))\THEME_ROM.bin
 else
	@echo It should not include Themes when DISPLAY_TYPE = BW in NEPTUNE_MMI
 endif
else
	@echo $(strip $(OBJSDIR))\theme_rom\themeres.obj >> $(strip $(FIXPATH))\~Theme_ROM.tmp
	$(LINK) $(VIA) $(strip $(FIXPATH))\~Theme_ROM.tmp
	$(BIN_CREATE) $(strip $(CUSTPACKDIR))\THEME_ROM.elf $(BIN_FORMAT) -output $(strip $(CUSTPACKDIR))\THEME_ROM.bin
endif

run_custpack:
# Run custpack.exe to generate CUSTPACK_ROM
	@echo Write custpack_param.log
	@echo perl ${CURDIR}\tools\CustpackCompProcess.pl ${CURDIR}\$(strip $(TARGDIR))\$(strip $(LIS_FILE)) ${CURDIR}\$(strip $(TARGDIR))\$(strip $(BIN_FILE)) ${CURDIR}\$(FIXPATH)\tools\CustPack.ini ${CURDIR}\$(strip $(THE_MF)) ${CURDIR}\$(FIXPATH)\custom\system\$(strip $(BOARD_VER)) >tools\custpack_param.log

	@echo Executing custpack.exe
	@if exist tools\CustPack.exe \
		(tools\CustPack.exe)

check_custpack_obj:
	if exist $(strip $(COMPLIBDIR))\custom.lib \
		if not exist $(strip $(OBJSDIR))\custom\*.obj \
		(if not exist $(strip $(OBJSDIR))\custom (md $(strip $(OBJSDIR))\custom)) && \
			(copy /y $(strip $(COMPLIBDIR))\custom.lib $(strip $(OBJSDIR))\custom\custom.lib_bak >NUL) && \
			(perl tools\extract_obj_from_lib.pl $(subst /,\,$(OBJSDIR))\custom\custom.lib_bak $(subst /,\,$(OBJSDIR))\custom $(subst /,\,$(LIB)) $(TARGDIR)\module\custom\custom.lis) && \
			(del /q $(strip $(OBJSDIR))\custom\custom.lib_bak)
