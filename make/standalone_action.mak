#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
# *************************************************************************
# STANDALONE_ACTION.mak - independent build action
#
#  DISCUSSION:
#
#  USAGE:
#
#  IMPORTANT NOTES:
#
# *************************************************************************
#
# $Revision:$
# $Modtime:$
# $Log:$
#
# 01 21 2014 amber.su
# [MAUI_03483722] [Target Build] [AAPMC] add bootloader to FS auto config flow
# .
#
# 01 20 2014 amber.su
# [MAUI_03483722] [Target Build] [AAPMC] add bootloader to FS auto config flow
# .
#
# 11 01 2013 amber.su
# [MAUI_03465358] [Target Build] enhance for gendummylis flow
# .
#
# 02 22 2013 amber.su
# [MAUI_03330378] [Approved DVT] Phase in DCM debug tool (DDT)
# .
#
# 02 04 2013 amber.su
# [MAUI_03330378] [Approved DVT] Phase in DCM debug tool (DDT)
# .
#
# 12 26 2012 amber.su
# [MAUI_03299193] [SystemService][Auto-Gen][Internal Refinement] Refine BLReservedSize_AutoConfig.pl protential bug
# .
# 
# 10 18 2012 amber.su
# [MAUI_03241322] [ZIMAGE] Phase in ZIMAGE_CONTENT_POLICY and phase out ZIMAGE_FAVOR_ROM
# .
# 
# 10 18 2012 amber.su
# [MAUI_03241322] [ZIMAGE] Phase in ZIMAGE_CONTENT_POLICY and phase out ZIMAGE_FAVOR_ROM
# .
# *************************************************************************

.PHONY: gendsp gendummylis update_memconfig post_memconfig dcm_debug dcm_done

# *************************************************************************
#  Process DSP BIN
# *************************************************************************	
gendsp:
ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
		@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
			(copy /y $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BIN)).bin" $(strip $(TARGDIR))\$(strip $(BIN_FILE))\DSP_ROM >NUL)& \
			(copy /y $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BL_BIN)).bin" $(strip $(TARGDIR))\$(strip $(BIN_FILE))\DSP_BL >NUL) \
		else \
			(copy /y $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BIN)).bin" $(strip $(TARGDIR))\DSP_ROM >NUL) & \
			(copy /y $(FIXPATH)\dsp_bin\"$(strip $(DUALMACDSP_BL_BIN)).bin" $(strip $(TARGDIR))\DSP_BL >NUL)
endif

# *************************************************************************
#  Generate dummy .lis file for memory analysis
# *************************************************************************	
gendummylis: 
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

	@if exist $(SCATTERFILE) copy /y $(SCATTERFILE) $(SCATTERFILE).original > NUL
	@if exist $(strip $(TARGDIR))\$(strip $(LIS_FILE)) copy /y $(strip $(TARGDIR))\$(strip $(LIS_FILE)) $(strip $(TARGDIR))\$(strip $(LIS_FILE)).original > NUL
	@tools\make.exe -fmake\gsm2.mak -r -R DUMMY_LIS=TRUE sys_auto_gen LINK_BIN_FILE & \
		(if ERRORLEVEL 1 exit 1)
	
	@if not exist $(strip $(TARGDIR))\$(TARGNAME).elf	\
		echo Error in gendummylis & exit 1

ifeq ($(strip $(VIVA_AUTO_SUPPORT)),TRUE)
	@tools\make.exe -fmake\gsm2.mak -r -R FROMELF_BIN_FILE & \
		(if ERRORLEVEL 1 exit 1)
	@if not exist $(strip $(TARGDIR))\VIVA_DEBUG md $(strip $(TARGDIR))\VIVA_DEBUG
	@if exist  $(strip $(TARGDIR))\$(strip $(LIS_FILE)).original move /y  $(strip $(TARGDIR))\$(strip $(LIS_FILE)).original $(strip $(TARGDIR))\VIVA_DEBUG\$(strip $(LIS_FILE)).original > NUL
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
		md $(strip $(TARGDIR))\VIVA_DEBUG\$(strip $(BIN_FILE))_dummy & \
		copy /y $(strip $(TARGDIR))\$(strip $(BIN_FILE))\*.* $(strip $(TARGDIR))\VIVA_DEBUG\$(strip $(BIN_FILE))_dummy & \
		copy /y $(strip $(TARGDIR))\$(strip $(LIS_FILE)) $(strip $(TARGDIR))\VIVA_DEBUG\$(strip $(LIS_FILE)).dummy & \
		rd /S /Q $(strip $(TARGDIR))\$(strip $(BIN_FILE))		
endif
	@copy /y $(SCATTERFILE) $(SCATTERFILE).dummy > NUL      
	@if exist $(SCATTERFILE).original move /y $(SCATTERFILE).original $(SCATTERFILE) > NUL
	@if exist	$(strip $(TARGDIR))\$(strip $(LIS_FILE)).original	del /q $(strip $(TARGDIR))\$(strip $(LIS_FILE)).original
	@if exist	$(strip $(TARGDIR))\$(IMG_FILE)	del /q $(strip $(TARGDIR))\$(IMG_FILE)

	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	
# *************************************************************************
#  Generate Binary File with Auto-Memory-Config for VIVA, FS, and DEMAEND_PAGING
# *************************************************************************			
update_memconfig:
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

	@if exist make\~VIVA_LinkError.tmp \
		tools\make.exe -fmake\gsm2.mak -r -R VIVA_AUTO_SUPPORT=TRUE gendummylis

	@(perl tools\auto_adjust_mem.pl 2 $(strip $(TARGDIR)) $(strip $(LIS_FILE)) $(BTLD_PREFIX).lis $(BTLD_EXT_PREFIX).lis $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) $(strip $(THE_MF)) $(strip $(COMPLOGDIR)) $(strip $(TARGDIR))\VIVA_DEBUG\$(strip $(BIN_FILE))_dummy ~flash_cfg_tmp.c $(strip $(CUSTOMER)) ~fs_quota_usage.log ~nvram_lid_size.log $(strip $(FEATURE_OVERLOAD)) $(strip $(SYSTEM_DRIVE_ON_NAND)) $(strip $(NVRAM_PSEUDO_MERGE)) $(strip $(INSIDE_MTK)) $(strip $(SCATTERFILE)))>> $(strip $(COMPLOGDIR))\auto_adjust_mem.log
	
	@if exist make\~NoAAPMC.tmp \
		(del /f /q make\~NoAAPMC.tmp) \
	else \
		(tools\make.exe -fmake\gsm2.mak -r -R post_memconfig) & \
		(if ERRORLEVEL 1 exit 1)

  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

post_memconfig: 
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

	@echo .
	@echo ======== Two-Phase Linking Process Start... ========
	@echo .
	
	@if exist make\~VIVA_LinkError.tmp (tools\make.exe -fmake\gsm2.mak -r -R -o obj_list_gen viva_config)

#skip obj_list_gen for AAPMC flow
#with -o obj_list_gen

	@if exist make\~DP_LinkError.tmp \
		(if exist $(strip $(COMPLIBDIR))\custom.lib (del /q /f $(strip $(COMPLIBDIR))\custom.lib)) && \
		(if exist $(strip $(COMPLIBDIR))\system.lib (del /q /f $(strip $(COMPLIBDIR))\system.lib)) && \
		(if exist $(strip $(OBJSDIR))\custom\*.obj (del $(strip $(OBJSDIR))\custom\*.obj)) && \
		(if exist $(strip $(OBJSDIR))\system\*.obj (del $(strip $(OBJSDIR))\system\*.obj)) && \
		(tools\make.exe -fmake\gsm2.mak -r -R -o obj_list_gen demandpaging_config) && \
		(if ERRORLEVEL 1 exit 1)
		
	@if exist make\~FS_LinkError.tmp \
		(if exist $(strip $(COMPLIBDIR))\custom.lib (del /q /f $(strip $(COMPLIBDIR))\custom.lib)) && \
		(if exist $(strip $(COMPLIBDIR))\init.lib (del /q /f $(strip $(COMPLIBDIR))\init.lib)) && \
		(if exist $(strip $(COMPLIBDIR))\mtd.lib (del /q /f $(strip $(COMPLIBDIR))\mtd.lib)) && \
		(if exist $(strip $(COMPLIBDIR))\system.lib (del /q /f $(strip $(COMPLIBDIR))\system.lib)) && \
		(if exist $(strip $(OBJSDIR))\custom\*.obj (del $(strip $(OBJSDIR))\custom\*.obj)) && \
		(if exist $(strip $(OBJSDIR))\init\*.obj (del $(strip $(OBJSDIR))\init\*.obj)) && \
		(if exist $(strip $(OBJSDIR))\system\*.obj (del $(strip $(OBJSDIR))\system\*.obj)) && \
		(if exist $(strip $(OBJSDIR))\mtd\*.obj (del $(strip $(OBJSDIR))\mtd\*.obj))
		
	@if exist make\~FS_LinkError.tmp \
			if exist make\~FS_LinkError_BBU.tmp \
				((tools\make.exe -fmake\gsm2.mak -r -R CK_BBU=TRUE -o obj_list_gen filesystem_config) && (if ERRORLEVEL 1 exit 1)) \
			else \
				((tools\make.exe -fmake\gsm2.mak -r -R -o obj_list_gen filesystem_config) && (if ERRORLEVEL 1 exit 1))

	@if exist make\~BL_LinkError.tmp \
		(tools\make.exe -fmake\gsm2.mak -r -R -o obj_list_gen bl_config) && \
		(if ERRORLEVEL 1 exit 1)

 # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

viva_config: sys_auto_gen LINK_BIN_FILE
 # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))  
	@if exist $(strip $(COMPLOGDIR))\auto_adjust_mem.log \
		move /y $(strip $(COMPLOGDIR))\auto_adjust_mem.log $(strip $(TARGDIR))\VIVA_DEBUG\auto_adjust_mem.log > nul
	@echo .
	@echo ======== Two-Phase Linking Process Finished ========
	@echo Please refer to $(strip $(TARGDIR))\VIVA_DEBUG\auto_adjust_mem.log for more details of two-phase linking
	@echo .
 # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

demandpaging_config: sys_auto_gen cus_sys_lib LINK_BIN_FILE
 # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))  
	@if exist $(strip $(COMPLOGDIR))\auto_adjust_mem.log \
		move /y $(strip $(COMPLOGDIR))\auto_adjust_mem.log $(strip $(TARGDIR))\DEMAND_PAGING_DEBUG\auto_adjust_mem.log > nul
	@echo .
	@echo ======== Two-Phase Linking Process Finished ========
	@echo Please refer to $(strip $(TARGDIR))\DEMAND_PAGING_DEBUG\auto_adjust_mem.log for more details of two-phase linking
	@echo .
 # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

cus_sys_lib:
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@(tools\make.exe -fmake\gsm2.mak -r -R XGC_AND_NOT_BOOTLOADER=FALSE custom.lib system.lib) && \
	(if ERRORLEVEL 1 exit 1)
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ifeq ($(strip $(CK_BBU)),TRUE)
filesystem_config: sys_auto_gen cksysdrv bootloader cus_ini_mtd_lib cleanbin LINK POSTBUILD ckbinblockusage_check
else
filesystem_config: sys_auto_gen cksysdrv bootloader cus_ini_mtd_lib cleanbin LINK_BIN_FILE LINK_BIN_FILE_CHECK
endif

 # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))  
	@if not exist $(strip $(TARGDIR))\FILE_SYSTEM_DEBUG (md $(strip $(TARGDIR))\FILE_SYSTEM_DEBUG)
	@if exist $(strip $(COMPLOGDIR))\auto_adjust_mem.log \
		move /y $(strip $(COMPLOGDIR))\auto_adjust_mem.log $(strip $(TARGDIR))\FILE_SYSTEM_DEBUG\auto_adjust_mem.log > nul
	@echo .
	@echo ======== Two-Phase Linking Process Finished ========
	@echo Please refer to $(strip $(TARGDIR))\FILE_SYSTEM_DEBUG\auto_adjust_mem.log for more details of two-phase linking
	@echo .
 # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

cus_ini_mtd_lib:
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if exist $(strip $(COMPLOGDIR))\ckSysDrv.log \
		(@perl -e "open F,'<$(strip $(COMPLOGDIR))\ckSysDrv.log';my $$backup=$$/;undef $$/;my $$reading=<F>;close F;if($$reading =~ /Shortage/i){print 'cksysdrv has errors. Delete the binary file.'.\"\n\";system('del /S /Q /F $(strip $(TARGDIR))\$(strip $(BIN_FILE))');exit 1;};")

	@(tools\make.exe -fmake\gsm2.mak -r -R XGC_AND_NOT_BOOTLOADER=FALSE custom.lib init.lib mtd.lib system.lib) && \
	(if ERRORLEVEL 1 exit 1)
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

video_mem_gen:
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@tools\strcmpex.exe inc inc e make\~optInc.tmp $(foreach inc,$(COMMINCDIRS),-I$(inc))
	@tools\strcmpex.exe def def e make\~opt.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@type make\~opt.tmp >> make\~optInc.tmp
	@if not exist $(strip $(RULESDIR))\video_mem_gen_dep (md $(strip $(RULESDIR))\video_mem_gen_dep)
	@perl .\tools\lucy.pl make\~optInc.tmp $(strip $(RULESDIR))\video_mem_gen_dep\video_mem_gen.det > $(strip $(COMPLOGDIR))\video_mem_gen.log & \
		(if ERRORLEVEL 1 echo Error: video_mem_gen failed! Please check $(strip $(COMPLOGDIR))\video_mem_gen.log & exit 1)
	@if exist $(strip $(RULESDIR))\video_mem_gen_dep\video_mem_gen.det \
		(perl .\tools\pack_dep.pl $(strip $(RULESDIR))\video_mem_gen_dep\video_mem_gen.det tools\copy_mmi_include_h.bat> $(strip $(RULESDIR))\video_mem_gen.dep ) && \
		(rd /s /q $(strip $(RULESDIR))\video_mem_gen_dep)
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

bl_config: sys_auto_gen gen_bl_verno gencompbld bl_preflow LINK_BL
 # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))  
	@if not exist $(strip $(TARGDIR))\BOOTLOADER_DEBUG (md $(strip $(TARGDIR))\BOOTLOADER_DEBUG)
	@if exist $(strip $(COMPLOGDIR))\auto_adjust_mem.log \
		move /y $(strip $(COMPLOGDIR))\auto_adjust_mem.log $(strip $(TARGDIR))\BOOTLOADER_DEBUG\auto_adjust_mem.log > nul
	@echo .
	@echo ======== Two-Phase Linking Process Finished ========
	@echo Please refer to $(strip $(TARGDIR))\BOOTLOADER_DEBUG\auto_adjust_mem.log for more details of two-phase linking
	@echo .
 # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *************************************************************************
#  CATGen flow
# *************************************************************************
catgen:
ifneq ($(strip $(call Upper,$(LEVEL))),VENDOR)
ifneq ($(strip $(CAT_SUPPORT)),NONE)
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	
	@if exist $(strip $(CATDB)) del /Q $(strip $(CATDB))> nul
	
	@tools\CAT\MMIResource\catmeta.bat $(FIXPATH)\tools\CAT\CatResMeta.ini 2> $(strip $(COMPLOGDIR))\catmeta.log & \
	(if ERRORLEVEL 1 echo Error: catmeta.bat failed! Please check $(strip $(COMPLOGDIR))\catmeta.log & exit 1)

	@if exist make\~CatGen.cfg del /Q make\~CatGen.cfg
	@perl tools\echoLongString4.pl make\~CatGen.cfg ELF=$(strip $(TARGDIR))\$(TARGNAME).elf BIN=$(strip $(TARGDIR))\$(strip $(BIN_FILE)) CatcherDB=$(CODEGEN_DATABASE_OUT) HW=$(strip $(PLATFORM))_$(strip $(CHIP_VER)) SW=$(strip $(VERNO))
	@perl tools\lnitem.pl make\~CatGen.cfg
	@echo OUTPUT=$(strip $(CATDB))>> make\~CatGen.cfg
ifneq ($(filter $(strip $(SV5_PLATFORM)),$(PLATFORM)),)
	@echo SV5_PLATFORM=TRUE >> make\~CatGen.cfg
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		(echo DOWNLOAD_FILE=$(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(BOARD_VER)).cfg >> make\~CatGen.cfg) \
	else \
		(echo DOWNLOAD_FILE=$(strip $(TARGDIR))\$(strip $(BOARD_VER)).cfg >> make\~CatGen.cfg)
else
	@echo DOWNLOAD_FILE=$(strip $(SCATTERFILE_FLASHTOOL)) >> make\~CatGen.cfg
endif
	@echo LIS=$(FIXPATH)\~lis_temp >> make\~CatGen.cfg
	@echo RES=$(FIXPATH)\tools\CAT\CatResMeta.ini >> make\~CatGen.cfg
	@echo BRANCH=$(strip $(BRANCH)) >> make\~CatGen.cfg
	@echo BUILD_DATE_TIME=$(strip $(BUILD_DATE_TIME)) >> make\~CatGen.cfg
	@echo CUSTOM_NVRAM_PATH=$(FIXPATH)\custom\common\hal\nvram >> make\~CatGen.cfg
	@echo CUSTOM_MMI_CACHE_PATH=$(FIXPATH)\custom\common >> make\~CatGen.cfg
	@echo CUSTOM_AUDIO_PATH1=$(FIXPATH)\custom\audio\$(strip $(BOARD_VER)) >> make\~CatGen.cfg
	@echo CUSTOM_AUDIO_PATH2=$(FIXPATH)\custom\audio\_DEFAULT_BB\$(strip $(PLATFORM)) >> make\~CatGen.cfg
	@echo MMI_NVRAM_MANAGER_RES_PATH=$(FIXPATH)\plutommi\Framework\NVRAMManager\NVRAMManagerRes >> make\~CatGen.cfg
	@echo 7LZMA=$(FIXPATH)\tools\7lzma.exe >> make\~CatGen.cfg
	@echo THE_MF=$(strip $(THE_MF)) >> make\~CatGen.cfg
	@echo FLASHFILE=$(strip $(FLASHFILE)) >> make\~CatGen.cfg
	@echo VIVA=$(FIXPATH)\tools\CAT\INI\VIVA.ini >> make\~CatGen.cfg
	@echo CK_IMG_SIZE=$(FIXPATH)\tools\CAT\INI\ckImgSize.ini >> make\~CatGen.cfg
	@echo VIVA_DEPENDENCY=$(strip $(RULESDIR_TARGET))\postgen_dep\vivaProcess.det >> make\~CatGen.cfg
	@echo CK_IMG_SIZE_DEPENDENCY=$(strip $(RULESDIR_TARGET))\postgen_dep\ckImgSize.det >> make\~CatGen.cfg


	@$(FIXPATH)\tools\CAT\CatGen.exe make\~CatGen.cfg 2> $(strip $(COMPLOGDIR))\CatGen.log & \
		(if ERRORLEVEL 1 echo Error: CatGen.exe failed! Please check $(strip $(COMPLOGDIR))\CatGen.log & exit 1)

	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif
endif

# *************************************************************************
#  Generate invalid obj_list_gen to force to run two-phase linking
# *************************************************************************
obj_sys_auto_gen:
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@tools\make.exe -fmake\gsm2.mak -r -R OBJ_SYS_AUTO_GEN=TRUE sys_auto_gen & \
		(if ERRORLEVEL 1 echo Error in obj_sys_auto_gen & exit 1)
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *************************************************************************
#  DCM Debug Tool
# *************************************************************************
dcm_debug:
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	
	@if exist $(strip $(TARGDIR))\DCM_DEBUG (rd /S /Q $(strip $(TARGDIR))\DCM_DEBUG)
	@md $(strip $(TARGDIR))\DCM_DEBUG
	
	@if not exist $(strip $(TARGDIR))\$(TARGNAME).htm \
		(tools\make.exe -fmake\gsm2.mak -r -R DCM_OPTION=TRUE cleanbin LINK) & \
		(if ERRORLEVEL 1 exit 1)

	@tools\DDTMain.exe $(strip $(TARGDIR))\$(TARGNAME).lis $(strip $(TARGDIR))\$(TARGNAME).htm 2>$(strip $(COMPLOGDIR))\DDTMain.log & \
	(if ERRORLEVEL 1 (echo DDTMain Error. Please check $(strip $(COMPLOGDIR))\DDTMain.log & exit 1))
	
	@if exist $(strip $(COMPLIBDIR))\system.lib del /F /Q $(strip $(COMPLIBDIR))\system.lib

	@(tools\make.exe -fmake\gsm2.mak -r -R XGC_AND_NOT_BOOTLOADER=FALSE DCM_DEBUG_SUITE_ENABLE=TRUE DCM_OPTION=FALSE gencompbld system.lib cleanbin LINK POSTBUILD_CHECK cmmgen cfggen catgen done) & \
	(tools\make.exe -fmake\gsm2.mak -r -R dcm_done) & \
	(if ERRORLEVEL 1 exit 1)
	
	@echo DCM Debug is finished!
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

dcm_done:

	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
		
	@if exist hal\system\dcmgr\src\dcm_intercept_c.c del /F /Q hal\system\dcmgr\src\dcm_intercept_c.c
	@if exist hal\system\dcmgr\src\dcm_intercept_a.s del /F /Q hal\system\dcmgr\src\dcm_intercept_a.s
	@if exist $(strip $(OBJSDIR))\system\dcm_intercept_c.obj del /F /Q $(strip $(OBJSDIR))\system\dcm_intercept_c.obj
	@if exist $(strip $(OBJSDIR))\system\dcm_intercept_a.obj del /F /Q $(strip $(OBJSDIR))\system\dcm_intercept_a.obj
	@if exist $(strip $(TARGDIR))\$(TARGNAME).htm del /F /Q $(strip $(TARGDIR))\$(TARGNAME).htm
	
#	@if exist $$(strip $$(TARGDIR))\via\system_inc.via (copy /y $$(strip $$(TARGDIR))\via\system_inc.via $(strip $(TARGDIR))\DCM_DEBUG\system_inc.via >nul)
#	@if exist $$(strip $$(TARGDIR))\via\system.via (copy /y $$(strip $$(TARGDIR))\via\system.via $(strip $(TARGDIR))\DCM_DEBUG\system.via >nul)
#	@if exist hal\system\dcmgr\src\dcm_intercept_c.c (copy /y hal\system\dcmgr\src\dcm_intercept_c.c $(strip $(TARGDIR))\DCM_DEBUG\dcm_intercept_c.c >nul)
#	@if exist hal\system\dcmgr\src\dcm_intercept_a.s (copy /y hal\system\dcmgr\src\dcm_intercept_a.s $(strip $(TARGDIR))\DCM_DEBUG\dcm_intercept_a.c >nul)
#	@if exist $(strip $(OBJSDIR))\system\dcm_intercept_c.obj (copy /y $(strip $(OBJSDIR))\system\dcm_intercept_c.obj $(strip $(TARGDIR))\DCM_DEBUG\dcm_intercept_c.obj >nul)
#	@if exist $(strip $(OBJSDIR))\system\dcm_intercept_a.obj (copy /y $(strip $(OBJSDIR))\system\dcm_intercept_a.obj $(strip $(TARGDIR))\DCM_DEBUG\dcm_intercept_a.obj >nul)
#	@if exist $(strip $(TARGDIR))\$(TARGNAME).htm (copy /y $(strip $(TARGDIR))\$(TARGNAME).htm $(strip $(TARGDIR))\DCM_DEBUG\$(TARGNAME).htm >nul)
	
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
