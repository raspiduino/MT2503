#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2006
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
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   sysGen2.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script parse scatter file and 
#*       1. force generate custom_scatstruct.h if update required
#*       2. force generate custom_scatstruct.c if update required
#*       3. force generate custom_blconfig.c if update required
#*
#* Author:
#* -------
#*   Qmei Yang  (mtk03726)
#*
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use sysgenUtility;                 #pm file name without case sensitivity
use scatInfo;
use FileInfoParser;
use CommonUtility;
use config_MemSegment;
use tools::pack_dep_gen;
PrintDependModule();

#****************************************************************************
# Constants
#****************************************************************************
my $SYSGEN2_VERNO     = " v1.73 -> p1.74 -> p1.75.";
                       #  p1.75 , 2014/04/21 by Yinli, Support boot_zimage and zimage area protection by MPI after bring up
                       #  p1.74 , 2014/04/21 by Yinli, Reserve 12kB ram-space for SWLA when zimage using BEST_PERF policy
                       #  v1.73 , 2014/02/26 by Yinli, Support Tiny System
                       #  v1.72 , 2013/12/17 by Yinli, Replace INT_RetrieveDSPTXRXBaseAddr()& INT_QuerySystemRAMInfo() by scatstruct API 
                       #  v1.71 , 2013/12/17 by Yinli, Bug fixed in get_region_length() and SCAT_C_Gen_TEMPLATE_EXTCODE_ASSIGN()
                       #  v1.70 , 2013/11/26 by Yinli, Support MPU protect Zimage&DCM area before decompress
                       #  v1.69 , 2013/11/19 by Yinli, Support strict MPU and precise code region determination
                       #  v1.68 , 2013/09/23 by Yinli, A verno-number is reserved for the new trunk branch 11C
                       #  p1.67 , 2013/08/16 by Yinli, Support BT Box, add BLCONFIG_C_Gen_BASE_ROM_ON_FLASH() to get ROM begin address on flash
                       #  v1.66 , 2013/02/18 by Carina, Modify Get_Dump_Regions() to get the correct DCM dump length
                       #  v1.65 , 2013/01/29 by Carina, Modify SCAT_C_Gen_TEMPLATE_MAX_FREERAM_MMU() to support ALICE on NAND
                       #  v1.64 , 2013/01/11 by Carina, Support new DCM dump mechanism
                       #  v1.63 , 2012/12/06 by Carina, Support Dumping DCM regions
                       #  v1.62 , 2012/11/16 by Carina, Move Dec2Hex from sysGenUtility to CommonUtility
                       #  v1.61 , 2012/10/31 by Carina, Move is_NOR() from sysGenUtility to FileInfoParser to support general query
                       #  v1.60 , 2012/07/18 by Carina, Support BOOTCERT in NAND project
                       #  v1.59 , 2012/07/10 by Carina, Support EWS via tools::pack_dep_gen
                       #  v1.58 , 2012/06/25 by mei, Fix memory dump bug
                       #  v1.57 , 2012/06/12 by Carina, Error message refinement
                       #  v1.56 - reserved for Modifying ZIMAGE name to ZIMAGE_ER to provide the free ram to SWLA
                       #  v1.55 , 2012/04/17 by mei, Support ALICE dump sync with cmmgen
                       #  v1.54 , 2012/04/03, Phase in ALICE
                       #  v1.53 , 2012/03/28, Modify APIs for FOTA in order to query TCM information 
                       #  v1.52 , 2012/03/27, Fix wrong region name's bug in custom_get_MaxAvailableMemorySegment()
                       #  v1.51 , 2012/03/19, Fix MultiROM for incorrect linker symbol
                       #  v1.50 , 2012/04/17, Support EWS to print file dependency
                       #  v1.49 , 2012/03/15, Provide TCM information APIs for FOTA
                       #  v1.48 - reserved for VIVA (11BW1132SP)
                       #  v1.47 , 2012/02/20, Fix missing declaraion of linker symbol
                       #  v1.46 , 2012/02/06, Support sysgen2 synced with cmmgen
                       #  v1.45 , 2012/01/31, Fix incorrect template
                       #  v1.44 , 2012/01/31, Generate ROM base for custom_blconfig.c if ROM base=+0x0...
                       #  v1.43 , 2012/01/31, Generate custom_get_MaxAvailableMemorySegment() contents to avoid 53 build error for MAP2CREGPA
                       #  v1.42 , 2012/01/30, refactory sysgen2
                       #  v1.41 , 2012/01/14, Add $bisBL parameter in query_cs1_addr() in order to sync with sysGenUtility.pm
                       #  v1.40 , 2012/01/08, To support Query HW boundary for CR4 
                       #  v1.39 , 2012/01/06, To support CR4 
                       #  v1.38 , 2011/12/17, Fix parsing makefile
                       #  v1.37 , 2011/11/01, Remove $$ to support PERL v5.12.*
                       #  v1.36 , 2011/10/30, Support ABSOLUTE in parse_region_string()
                       #  v1.35 , 2011/10/21, Revise get_cont_region()
                       #  v1.34 , 2011/10/13, To support Cache & MMU HAL
                       #  v1.33 , 2011/10/10, Simplify the judgement
                       #  v1.32 , 2011/10/07, To support isolating med and asm pool in scatter file for DSP shared memory
                       #  v1.31 , 2011/09/29, Add error checking when Demand Paging binary size is not defined as multiples of MB
                       #  v1.30 , 2011/09/29, Fix a build warning
                       #  v1.29 , 2011/09/21, To support FastBoot
                       #  v1.28 , 2011/09/19, Let custom_demp_h_file_body() support emmc_booting
                       #  v1.27 , 2011/09/16, Move common functions to sysGenUtility.pm
                       #  v1.26 , 2011/09/08, Modify custom_demp.h template
                       #  v1.25 , 2011/09/07, To support INTSRAM_SINGLE_BANK_CODE for 6251
                       #  v1.24 , 2011/09/06, To support MBA_ON_DEMAND and THIRD_ROM removal
                       #  v1.23 , 2011/09/05, To support custom_FeatureConfig.h
                       #  v1.22 , 2011/09/02, To support custom_FeatureConfig.h
                       #  v1.21 , 2011/08/22, Modify FLMM_PASPACE APIs to return non-cacheable information and to modify MCU/DSP share info APIs to hard-code MED/ASM pool part
                       #  v1.20 , 2011/08/19, Set DCM Compression Region type to DCM to prevent it being assigned to Cacheable Regions (follow ZIMAGE convention)
                       #                      Skip DUMMY_END regions when calculating continuous regions to fix errors when DUMMY_END is not the last region of that type
                       #  v1.19 , 2011/08/04, Add DCM Compression Region into Cached RW region
                       #  v1.18 , 2011/08/03, Add new API custom_get_SINGLEBANKCODE_and_VectorTable_Base() for MPU to protect vector table
                       #  v1.17 , 2011/08/02, Add Query API for FLMM_PASPACE_Base/FLMM_PASPACE_END
                       #  v1.16 , 2011/08/02, Fix TX RX to EXTSRAM_RW
                       #  v1.15 , 2011/08/02, Add custom_get_SysRam_MaxSize() for querying sysram's actual size
                       #  v1.14 , 2011/07/27, Change DSPONLY region to RW attribute
                       #  v1.13 , 2011/07/25, To support non-cacheable RO extsram region
                       #  v1.12 , 2011/07/15, Modify custom_scatstruct.c template to add DSP_ROM into noncacheable region
                       #  v1.11 , 2011/07/12, Modify custom_scatstruct.c and custom_scatstruct.h template to support MT6256 DSP Query
                       #  v1.10 , Modify custom_blconfig.c template to support EXT_BL_UPDATE_SUPPORT feature
                       #  v1.09 , Modify custom_blconfig.c template to add __UBL__ in custom_check_valid_secro to prevent build error in MAUI
                       #  v1.08 , Add file owners
                       #  v1.07 , Modify custom_get_SINGLEBANKCODE_End() to allow MPU wrap the entire SINGLE_BANK_CODE area on all platforms
                       #  v1.06 , To support MT6575 Auto-Gen
                       #  v1.05 , Modify custom_blconfig.c template to set USBDL key as Back key for COSMOS_MMI
                       #  v1.04 , Modify custom_blconfig.c template to support Fast Meta
                       #  v1.02 , Modify custom_get_SINGLEBANKCODE_End() to allow MPU wrap the entire SINGLE_BANK_CODE area
                       #  v1.01 , To support MT6921 Auto-Gen
                       #  v1.00 , Support eMMC Booting
                       #  v0.99 , Remove MED/ASM pool from MCU/DSP share region on MT6573 GPRS segment
                       #  v0.98 , Modify custom_scatstruct.c and custom_scatstruct.h template to add FLMM query APIs
                       #  v0.97 , Modify custom_scatstruct.c template to put EXTSRAM_FS in normal non-cacheable region
                       #  v0.96 , Modify custom_blconfig.c template to correct __UBL__ compile option
                       #  v0.95 , Modify custom_blconfig.c template to add BL version string retrieval function and to wrap BL-only part with __UBL__ option
                       #  v0.94 , Get DEMAND_PAGING_ROM0 size only when NAND_FLASH_BOOTING is ONDEMAND or MIXED to prevent demand paging code segments being generated in custom_scatstruct.c due to referenced with LoadView hash
                       #  v0.93 , Define DEMP_PAGE_POOL_SIZE directly based on scatter file DEMAND_PAGING_ROM0 load region size
                       #  v0.92 , Return PROTECTED_RES region information for MT6251 (INTSRAM_PROTECTED_RES)
                       #  v0.85 , Modify custom_blconfig.c template to support Card DL
                       #  v0.91 , Change MT6236 and MT6276 DEMAND_PAGING size to 34MB to fix memory expiration issue
                       #  v0.90 , Add INTSRAM_DATA_PREINIT to MT6251 for BL-backup data
                       #  v0.89 , Separate DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE into RW and ZI regions and pass ZI region to DSP when COSMOS_MMI
                       #  v0.88 , 
                       #  v0.87 , Change MCU-DSP share region to DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE region when COSMOS_MMI because MED pool was merged to ASM pool when COSMOS_MMI
                       #  v0.86 , Adopt MANUAL-CHECKIN pattern for manual check-in files to bypass Auto-Gen
                       #  v0.84 , Support BOOT_CERT region and add BOOCERT APIs for BOOT_CERT region query
                       #  v0.82 , Enlarge MBA page table size because more obj are put in Demand Paging region for MBA to save memory consumption
                       #  v0.81 , Support MT6251
                       #  v0.80 , Remove MT6255
                       #  v0.79 , Support RHR (Merge MAUIW1043OF_RHR to MAUI)
                       #  v0.78 , Enlarge MT6276 Demand Paging region size to 28 because extra lib/obj is put in Demand Paging region for MT6276 slimming
                       #  v0.77 , Rename MT6253E/L as MT6252H/MT6252
                       #  v0.76 , Support new scatter file region format with ABSOLUTE attribute
                       #  v0.75 , Enlarge Demand Paging region size from 16MB to 18MB
                       #  v0.74 , Support RHR Add and add header files include on custom_scatstruct.c, custom_scatstruct.h, and custom_blconfig.c
                       #  v0.73 , To support MT6253E/L
                       #  v0.72 , Add MT6573 to ARM11 table
                       #  v0.71 , To support SV5
                       #  v0.70 , To support MT6276, Fcore, and ARM11
                       #  v0.69 , Modify custom_blconfig.c to add API custom_USB_Cable_Detection() to move USB detection flow as customizable function
                       #  v0.68 , Remove CODE_PATCH_CODE region when the compiler is RVCT to fix RVCT bug (CODE_PATCH_ENGINE will not be defined on RVCT)
                       #  v0.67 , Add two new APIs for RES_PROT region: custom_get_PROTECTED_RES_Base and custom_get_PROTECTED_RES_Length
                       #  v0.66 , Prevent SHOULDBE_EMPTYSECTION from being regarded as EXTSRAM region for RVCT C library porting
                       #  v0.65 , Enlarge Demand Paging reigon for (MT6236) RAM shrinking
                       #  v0.64 , Support Smart Phone (MT6516) different scatter file layout (extra EXTSRAM_FS)
                       #  v0.63 , Re-organize custom_blconfig.c template for easy IP sharing and support customizable silent bootloader
                       #  v0.62 , Modify custom_blconfig.c template to add customized DA version check function and holding mode setting
                       #  v0.61 , Modify custom_blconfig.c template to support customizable slient bootloader
                       #  v0.59 , Turn-on USBDL timeout for all TC01 projects
                       #  v0.58 , Fix sort hex issue
                       #  v0.57 , Add three new APIs in custom_scatstruct.c: custom_get_1st_ROM_RAMEnd, custom_get_2nd_ROM_RAM
                       #  v0.56 , Modify custom_blconfig.c template to support X-Download
                       #  v0.55 , Support MT6236 Auto-Gen
                       #  v0.54 , Support ARM11 Phase-in
                       #  v0.53 , Support USBDL timeout for TC01
                       #  v0.52 , Modify custom_scatstruct.c template for ARM9 MBA 
                       #  v0.51 , Modify custom_blconfig.c template for USB Download template update
                       #  v0.50 , Modify custom_blconfig.c template to avoid build warning
                       #  v0.49 , Modify custom_scatstruct.c template to fix FDM5 issues
                       #  v0.48 , Modify custom_blconfig.c template for better USBDL performance
                       #  v0.47 , Add the support of USBDL2.0
                       #  v0.46 , Add the support of MT6268
                       #  v0.45 , Remove MT6205B related codes
                       #  v0.44 , Add a page table entry at the end of the original FAT to avoid data abort for NOR FDM 5.0
                       #  v0.43 , Set DEMP region's size to a proper value
                       #  v0.42 , Remove THIRD_ROM and DYNAMIC_CODE in DEMAND_PAGING_ROM0 from MAULTI_ROM_LOAD_REGIONS
                       #  v0.41 , Enlarge the size of DEMP_PAGE_POOL_SIZE to 16 on MT6238
                       #  v0.40 , Enlarge the size of DEMP_PAGE_POOL_SIZE to 14
                       #  v0.39 , Support FOTA+NFB Auto-Gen
                       #  v0.38 , Put CODE_PATCH_CODE to Cacheable region
                       #  v0.37 , Add CACHED_EXTSRAM_CODE related API and definitions
                       #  v0.36 , Return the base address of EMIINIT_CODE instead of INTSRAM_CODE for arm9_itcm_base_addr
                       #  v0.35 , Modify the judgement of secret key length
                       #  v0.34 , Add file name and fline number information and unify all auto-gen error messages
                       #  v0.33 , Return SECURE regions in MULTI_ROM_LOAD_REGION
                       #  v0.32 , Modify custom_get_SINGLEBANKCODE_End
                       #  v0.31 , Fix duplicate extern error
                       #  v0.30 , Re-organize custom_scatstruct.c APIs and create custom_scatstruct.h
                       #  v0.29 , Modify custom_blconfig.c template to provide TCM base address information
                       #  v0.28 , Modify the calculation for MAX_CPT_POOL_SIZE
                       #  v0.27 , Unify Auto-Gen error messages
                       #  v0.26 , Enlarge Demand Paging load region size to 13MB
                       #  v0.25 , Add DYNAMIC_CACHEABLE regions into CPT calculation
                       #  v0.24 , Support FOTA Auto-Gen
                       #  v0.23 , Modify sysGen2.pl to support new SW Video scatter file layout + JBLENDIA
                       #  v0.22 , Modify custom_blconfig.c template to roll back custom_ROM_baseaddr()
                       #  v0.21 , Modify custom_blconfig.c template to fix boot-loader sanity test fail for FOTA
                       #  v0.20 , Modify custom_blconfig.c template for FOTA bug fix on boot-loader
                       #  v0.19 , Modify custom_blconfig.c template for NVRAM sec_ro data structure change
                       #  v0.18 , Modify templates for FOTA
                       #  v0.17 , Modify custom_scatstruct.c template for MT6235/MT6238 dynamic cacheable region
                       #  v0.16 , custom_img_config.h template imported
                       #  v0.15 , Modify sysGen2.pl to define RAMStartAddress which is used in MAP2CREGVA in cache_sw.h.
                       #  v0.14 , Modify sysGen2.pl to support custom_get_1st_ROMBINARY_EndAddr and custom_get_2nd_ROMBINARY_EndAddr on ARM9
                       #  v0.13 , Modify sysGen2.pl to extern all linker symbols
                       #  v0.12 , Modify sysGen2.pl to fix get_Max_AvailableRAMSegment error
                       #  v0.11 , Modify sysGen2.pl for MT6235/MT6238 custom_scatstruct.c templates
                       #  v0.10 , Modify sysGen2.pl for custom_scatstruct.c template to initialize MaxbeginAddr.
                       #  v0.09 , modify custom_blconfig.c template to add global variable g_custom_secure_ro_addr
                       #  v0.08 , modify custom_blconfig.c to phase in USB download for end user
                       #  v0.07 , align scatter file parse logic to ckscatter
                       #  v0.06 , output custom_blconfig.c since W07.45
                       #  v0.05 , get_ROM_Length algorithm revise
                       #  v0.04 , apply formal dependency check since W07.36
                       #  v0.03 , force update custom_scatstruct.c since W07.20
                       #  v0.02 , two new functions for cache.c

#****************************************************************************
# Global Variable
#****************************************************************************
my $g_bb;
my %MAKEFILE_OPTIONS;
my $g_MAUIScat = undef;
my $g_TinyScat = undef;
my %g_GroupedRegions; # Key => [content count, contents] #for saving time
my %g_RegionsInSameGroup; #Key => [region,region,region] #for saving time
my $g_DumpRegions = undef;    # Key => [[], [], []]
#****************************************************************************
# File Names
#****************************************************************************
my $CUSTOM_SCATSTRUCT_C   = $ARGV[0] . '\\' . "custom_scatstruct.c";
my $CUSTOM_SCATSTRUCT_H   = $ARGV[0] . '\\' . "custom_scatstruct.h";
my $CUSTOM_SCATSTRUCT_FOTA_C   = $ARGV[0] . '\\' . "custom_scatstruct_fota.c";
my $CUSTOM_BLCONFIG_C     = $ARGV[0] . '\\' . "custom_blconfig.c";
my $CUSTOM_TSCONFIG_C     = $ARGV[0] . '\\' . "custom_tsconfig.c";
my $CUSTOM_TSCONFIG_H     = $ARGV[0] . '\\' . "custom_tsconfig.h";
my $CUSTOM_DEMP_H         = $ARGV[0] . '\\' . "custom_demp.h";
my $CUSTOM_FEATURE_CFG_H  = $ARGV[0] . '\\' . "custom_FeatureConfig.h";
my $CUSTOM_FLASH_H        = $ARGV[0] . '\\' . "custom_flash.h";
my $SCATTERFILE           = $ARGV[1];
my $BL_SCATTERFILE        = $ARGV[2];
my $THEMF                 = $ARGV[3];
my $TS_SCATTERFILE        = $ARGV[4];
# to align error message file name format
$CUSTOM_SCATSTRUCT_C =~ s/^.\\|^\\//;
$CUSTOM_SCATSTRUCT_H =~ s/^.\\|^\\//;
$CUSTOM_SCATSTRUCT_FOTA_C =~ s/^.\\|^\\//;
$CUSTOM_BLCONFIG_C   =~ s/^.\\|^\\//;
$CUSTOM_TSCONFIG_C   =~ s/^.\\|^\\//;
$CUSTOM_TSCONFIG_H   =~ s/^.\\|^\\//;
$CUSTOM_DEMP_H       =~ s/^.\\|^\\//;
$CUSTOM_FEATURE_CFG_H =~ s/^.\\|^\\//;
$SCATTERFILE         =~ s/^.\\|^\\//;
$BL_SCATTERFILE      =~ s/^.\\|^\\//;
$THEMF               =~ s/^.\\|^\\//;

# ext_BL scatter file
my $EXT_BL_SCATTERFILE = $BL_SCATTERFILE;
$EXT_BL_SCATTERFILE =~ s/.txt//;
$EXT_BL_SCATTERFILE .= "_ext.txt";

my $DebugPrint    = 0; # 1 for debug; 0 for non-debug


#****************************************************************************
# 1 >>>  Parse Make File
#****************************************************************************
&sysUtil::sysgen_die("[1.4]$THEMF: NOT exist!", __FILE__, __LINE__) if (!-e $THEMF);
if(1!=&FileInfo::Parse_MAKEFILE($THEMF, \%MAKEFILE_OPTIONS))
{
   &sysUtil::sysgen_die("[1.1]Parse MakeFile failed");
}
$g_bb = $MAKEFILE_OPTIONS{"platform"};
#****************************************************************************
# 2 >>>  Parse Scatter File
#****************************************************************************
$g_MAUIScat = new scatInfo;
$g_MAUIScat->ParseScatterFile($SCATTERFILE);
$g_MAUIScat->ClassifyRegionType( \%MAKEFILE_OPTIONS );
my $DumpRegions_ref = $g_MAUIScat->GetDumpExeRegions($g_bb);

my $ts_DumpRegions_ref;
if(exists $MAKEFILE_OPTIONS{"TINY_SYS"} 
   and $MAKEFILE_OPTIONS{'TINY_SYS'} eq 'TRUE')
{
    $g_TinyScat = new scatInfo;
    $g_TinyScat->ParseScatterFile($TS_SCATTERFILE);
    $g_TinyScat->ts_ClassifyRegionType();
    $ts_DumpRegions_ref = $g_TinyScat->ts_GetDumpExeRegions();
}
#****************************************************************************
# 3 >>> parse key definition in CUSTOM_FLASH_H
#****************************************************************************
my $isDummy = &CommonUtil::CheckFileWithKeyword($SCATTERFILE,'(Dummy scatter)');
&memConfig::Parse($CUSTOM_FLASH_H,memConfig::CUSTOM_FLASH,$isDummy);
                                                  
#****************************************************************************
# 4 >>>  Generate custom_scatstruct.c
#                 custom_scatstruct.h
#                 custom_scatstruct_fota.c 
#                 custom_blconfig.c
#                 custom_demp.h
#****************************************************************************
&GenerateFile($CUSTOM_SCATSTRUCT_C, \&SCAT_C_Preprocess);
&GenerateFile($CUSTOM_SCATSTRUCT_H, undef);
&GenerateFile($CUSTOM_SCATSTRUCT_FOTA_C, undef);
&GenerateFile($CUSTOM_DEMP_H, \&DEMP_H_Preprocess);
&GenerateFile($CUSTOM_BLCONFIG_C, undef);
if(exists $MAKEFILE_OPTIONS{"TINY_SYS"} 
   and $MAKEFILE_OPTIONS{'TINY_SYS'} eq 'TRUE')
{
    &GenerateFile($CUSTOM_TSCONFIG_C, undef);
    &GenerateFile($CUSTOM_TSCONFIG_H, undef);
}
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
exit 0;
#****************************************************************************
# subroutine:  GenerateFile
# Input:       $strFilePath = the file to be generated if it exists without check-in history.
#              $PreprocessFunc_ref = to preprocess if there is any condition 
#                                    which needs to be tested before generating
# Output:      x
#****************************************************************************
sub GenerateFile
{
    my ($strFilePath, $PreprocessFunc_ref) = @_;
    if(&isToGen($strFilePath))
    {
        &$PreprocessFunc_ref() if(defined $PreprocessFunc_ref);
        my $content = &ProcessTemplate($strFilePath);
        &WriteFile($strFilePath, $content);
    }
}
#****************************************************************************
# subroutine:  isToGen
# Input:       $strFilePath = the file to be generated if it exists without check-in history.
# Output:      $bToGen: undef = not to generate file, 1=need to generate file 
#****************************************************************************
sub isToGen
{
    my ($strFilePath) = @_;
    my $bToGen = undef;
    if(-e $strFilePath)
    {
        $bToGen = 1 if(1 != &sysUtil::HasCheckinHistory($strFilePath));
    }
    else
    {
        &sysUtil::sysgen_die("[1.4]$strFilePath: the template must exist!", __FILE__, __LINE__);   
    }
    return $bToGen;
}
#****************************************************************************
# subroutine:  ProcessTemplate
# Input:       $strFilePath: the file to be processed
# Output:      $content: the content after processing
# Description: if there is the pattern as [AUTOGEN_funcname], 
#              the whole pattern will be replaced by calling funcname().
#              if funcname() doesn't exist, it'll fail and report error.
#****************************************************************************
sub ProcessTemplate
{
    my ($strFilePath) = @_;
    my $content;
    open (FILE_HANDLE, $strFilePath) or &sysUtil::sysgen_die("[1.4]Cannot open $strFilePath\n", __FILE__, __LINE__);
    while(<FILE_HANDLE>)
    {
        my $strLine = $_;
        while ($strLine =~ /\[AUTOGEN_(\w+)\]/)
        {
            my $func = $1;
            my $template;
            {
                no strict 'refs';
                $template = &{$func}() if(exists &{$func}) 
                    or &sysUtil::sysgen_die("[2.0]$func() doesn't exist!\n", __FILE__, __LINE__);
            }
            $strLine =~ s/\[AUTOGEN_$func\]/$template/g;
        }
        $content .= $strLine;
    }
    close FILE_HANDLE;
    return $content;
}
#****************************************************************************
# subroutine:  WriteFile
# Input:       $strFilePath: the file to be generated
#              $content: the content to be written into $strFilePath
# Output:      x
#****************************************************************************
sub WriteFile
{
    my ($strFilePath, $content) = @_;
    open (FILE, ">$strFilePath") or &sysUtil::sysgen_die("[3.2]Cannot open $strFilePath\n", __FILE__, __LINE__);
    print FILE $content;
    close FILE;
}
#-----------------------------------------------------------------------------
# Preprocess fucntions:
#-----------------------------------------------------------------------------
sub DEMP_H_Preprocess
{
    #MaxSize in DemandPaging should be units of MB.
    if ($MAKEFILE_OPTIONS{'nand_flash_booting'} eq 'ONDEMAND' or $MAKEFILE_OPTIONS{'emmc_booting'} eq 'ONDEMAND' )
    {
        my $Info = $g_MAUIScat->GetLoadRegionInfo("DEMAND_PAGING_ROM0");
        &sysUtil::sysgen_die("[2.0]$CUSTOM_FEATURE_CFG_H: MAX_DEMAND_PAGING_ROM0_SIZE should be configured as multiple of MB when DEMAND_PAGING is enabled!", __FILE__, __LINE__)
          if (int(hex($Info->[Region::MaxSize]/(1024*1024))) != (hex($Info->[Region::MaxSize]/(1024*1024))));
    }
}
sub SCAT_C_Preprocess
{
    # Report error if there is another region ahead of SINGLE_BANK_CODE (between SINGLE_BANK_CODE and vector table)
    # Because MPU channel will be wrapped from vector table (0x0) to the end of SINGLE_BANK_CODE to reduce the number of channels
    my $strRegionName = $g_MAUIScat->SearchExeRegionName("SINGLE_BANK_CODE");
    if(defined $strRegionName)
    {
        my $array_ref = $g_MAUIScat->GetExeRegionsByLoadRegion("ROM");
        my $SINGLE_BANK_CODE_Base = $g_MAUIScat->GetRegionInfo($strRegionName, Region::Base);
        if(!(exists $MAKEFILE_OPTIONS{"NORFLASH_NON_XIP_SUPPORT"} and $MAKEFILE_OPTIONS{"NORFLASH_NON_XIP_SUPPORT"} == "TRUE"))
        {
            foreach (@$array_ref)
            {
                next if(/SINGLE_BANK_CODE/);
                my $Info = $g_MAUIScat->GetExeRegionInfo($_);
                if(defined $Info->[Region::Base])
                {
                    if ((hex($Info->[Region::Base])) <= (hex($SINGLE_BANK_CODE_Base)) 
                    and ((hex($Info->[Region::Base]) >= (0xFF000000 & hex($SINGLE_BANK_CODE_Base))) ))
                    {
                        &sysUtil::sysgen_die("[2.0]$SCATTERFILE: No region($_) can exist between vector table and SINGLE_BANK_CODE for MPU configuration!", __FILE__, __LINE__);
                    }
                }
            }
        }
    }
}
#-----------------------------------------------------------------------------
# Gen fucntions:
#-----------------------------------------------------------------------------
sub GenVersion
{
    return "system auto generator". $SYSGEN2_VERNO. " + sysGenUtility" . &sysUtil::sysgenUtility_verno();
}
sub DEMP_H_Gen_MBA_LIST
{
    my $template;
    my $MBA_href = &GetGroupedRegions("MBA");
    foreach(@$MBA_href)
    {
        my $temp = uc($_->[0]); 
        $temp =~ s/_ROM//;
        $template .= "    DEMP_$temp,\n";
    }
    return $template;
}
sub DEMP_H_Gen_DEMP_MAIN_BINSIZE
{
    my $nMaxSize = 0;
    if($g_MAUIScat->IsRegionExistent("DEMAND_PAGING_ROM0"))
    {
        my $Info = $g_MAUIScat->GetLoadRegionInfo("DEMAND_PAGING_ROM0");
        $nMaxSize = hex($Info->[Region::MaxSize])/ (1024*1024);
    }
    return $nMaxSize;
}
sub DEMP_H_Gen_MBA_BINSIZE_LIST
{
    my $template;
    my $MBA_href = &GetGroupedRegions("MBA");
    foreach(@$MBA_href)
    {
        my $temp = uc($_->[0]); 
        $temp =~ s/_ROM//;
        my $Info = $g_MAUIScat->GetLoadRegionInfo($_->[0]);
        my $nMaxSize = hex($Info->[Region::MaxSize])/ (1024*1024);
        $template .= "#define DEMP_$temp\_SIZE $nMaxSize\n";
    }
    return $template;
}
sub DEMP_H_Gen_DEMP_MBA_BINSIZE
{
    my $template;
    my $MBA_href = &GetGroupedRegions("MBA");
    foreach(@$MBA_href)
    {
        my $temp = uc($_->[0]); 
        $temp =~ s/_ROM//;
        $template .= " + DEMP_$temp\_SIZE";
    }
    return $template;
}
sub BLCONFIG_C_Gen_BASE_CS1
{
    return &CommonUtil::Dec2Hex( &sysUtil::query_cs1_addr($g_bb, 0, 0) );
}
sub BLCONFIG_C_Gen_BASE_EXT_BL
{
    ### This addr tells BL where to find ext-BL
    ### NOR/SF + EXT_BL_UPDATE_SUPPORT = FALSE: XIP, the same as MAUI scatter EXT_BL load view base
    ### NOR/SF + EXT_BL_UPDATE_SUPPORt = TRUE: non-XIP, the same as MAUI scatter EXT_BL load view base (not the same as actual EXT_BL load view base)
    ### NFB/EMMC_BOOTING: EXT_BL scatter EXT_BL load view base
    my $strBase = "0x0";
    if (0==&FileInfo::is_NOR(\%MAKEFILE_OPTIONS))
    {
        my $BLScat = new scatInfo;
        $BLScat->ParseScatterFile($EXT_BL_SCATTERFILE);
        my $strEXT_BL_Base = $BLScat->GetRegionInfo("EXT_BOOTLOADER", Region::Base);
        $strBase = &CommonUtil::Dec2Hex( hex($strEXT_BL_Base)&(~0xf8000000)) if (defined $strEXT_BL_Base);
    }
    else
    {
        my $strEXT_BL_Base = $g_MAUIScat->GetRegionInfo("EXT_BOOTLOADER", Region::Base);
        $strBase = &CommonUtil::Dec2Hex( hex($strEXT_BL_Base)&(~0xf8000000)) if (defined $strEXT_BL_Base);
    }
    return $strBase;
}


sub BLCONFIG_C_Gen_BASE_ROM_LV
{
    my $strBase = "0";	
    my $Info_ref = $g_MAUIScat->GetLoadRegionInfo("ROM");
	 
    if(!defined $Info_ref->[Region::Base])
    {
        if($Info_ref->[Region::Offset] =~ /^\+(0x\w+)/)
        {
            $strBase = $1;
        }
        else
        {
            warn("[BLCONFIG_C_Gen_BASE_ROM_LV] ROM has no offset(".$Info_ref->[Region::Offset].") as well!\n", __FILE__, __LINE__);    
        }
    }
    else
    {
        $strBase = $Info_ref->[Region::Base];
    }
    return $strBase;
}


sub get_ROM_base_on_Flash_Non_XIP
{
    my $strRomBaseAddr = '0x0';
    my ($arrRef,$lastLRinBL);
    $lastLRinBL= $g_MAUIScat->GetPreviousLoadRegionName("ROM"); #last load-region in BL layout
    $arrRef = $g_MAUIScat->GetLoadRegionInfo($lastLRinBL);
    print "[get_ROM_base_on_Flash_Non_XIP]lastLRinBL=$lastLRinBL\n" if($DebugPrint);

    my ($base,$size,$nextBlockAddr);
    $base = (defined $arrRef->[Region::Base])? hex($arrRef->[Region::Base])&(~0xf8000000) : 0;
    $size = (defined $arrRef->[Region::MaxSize])? hex($arrRef->[Region::MaxSize])&(~0xf8000000) : 0;

    #get next block align address as ROM begin address
    $nextBlockAddr = &memConfig::Get_next_block_aligned_addr($base,$size);
    
    #to sync with layout13/layout4 in scatGenLib.pl
    $nextBlockAddr = &memConfig::Get_block_aligned_addr($nextBlockAddr);
    print "[get_ROM_base_on_Flash_Non_XIP]nextBlockAddr=$nextBlockAddr\n" if($DebugPrint);

    #get swapping base-address
    $base = (defined $arrRef->[Region::Base])? hex($arrRef->[Region::Base]): 0;
    my $rom_bank = $base & 0xf8000000;
    $strRomBaseAddr = &CommonUtil::Dec2Hex ($nextBlockAddr ^ $rom_bank) if($rom_bank);
    print "[get_ROM_base_on_Flash_Non_XIP]base=$base,rom_bank=$rom_bank,strRomBaseAddr=$strRomBaseAddr\n" if($DebugPrint);
    return $strRomBaseAddr;
}
sub BLCONFIG_C_Gen_BASE_ROM_ON_FLASH
{
    my $strBase = "0";
    if( exists $MAKEFILE_OPTIONS{"norflash_non_xip_support"} 
        and $MAKEFILE_OPTIONS{"norflash_non_xip_support"} eq "TRUE"
      )
    {
        #when NORFLASH_NON_XIP_SUPPORT is enabled, ROM will shadow to RAM 0x0, 
        #what's more, on Nor flash booting, BL related regions will be front of ROM,
        #so at this time, ROM LV address is not the position where flashtool should download the ROM,
        #so this API  is to tell flashtool the position where to download the Rom binary
        $strBase = &get_ROM_base_on_Flash_Non_XIP();
    }
    else
    {
        $strBase = &BLCONFIG_C_Gen_BASE_ROM_LV();
    }
	
    return $strBase;
}
sub BLCONFIG_C_Gen_BASE_FACTORY_ROM_LV
{
    my $Info_ref = $g_MAUIScat->GetLoadRegionInfo("FACTORY_ROM", Region::Base);
    return (defined $Info_ref->[Region::Base])? $Info_ref->[Region::Base] : "0xFFFFFFFF";
}
sub BLCONFIG_C_Gen_BASE_SECURE_RO_LV
{
    my $strBase = "0";
    my $Info_ref = $g_MAUIScat->GetLoadRegionInfo("__HIDDEN_SECURE_RO", Region::Base);
    return (defined $Info_ref->[Region::Base])? $Info_ref->[Region::Base] : "0";
}

sub SCAT_H_Gen_DSPTXRX_BUFF_MACRO()
{
    my $hasDSPTXRX_buff = &sysUtil::HasDSPTXRX_buff($g_bb);
    my $template = '';
    $template = "SUPPORT_DSP_TXRX_BUFF\n" if($hasDSPTXRX_buff);
    return $template;
}
sub SCAT_H_Gen_DUMP_REGION_COUNT
{
    my $nCount = 0;
    if(!defined $g_DumpRegions)
    {
        $g_DumpRegions = $g_MAUIScat->GetDumpExeRegions($g_bb);
    }
    foreach my $strGroupName (keys %$g_DumpRegions)
    {
        my $array_ref = $g_DumpRegions->{$strGroupName};
        $nCount += ($#$array_ref +1);
    }
    return $nCount;
}
sub SCAT_C_Gen_TEMPLATE_DUMP_REGION_ASSIGN
{
    my $template;
    my $DumpRegions_ref = &Get_Dump_Regions();
    for(my $i = 0; $i < $#$DumpRegions_ref+1; $i++)
    {
        my $GroupName = $DumpRegions_ref->[$i]->[0];
        my $ALICE_COMPRESSED = scatInfo->COMPRESSED_ALICE;
        if($DumpRegions_ref->[$i]->[1] =~ /$ALICE_COMPRESSED/)
        {
            $template .= "    {\n";
            $template .= "    kal_uint32 aliceCompressedBase, aliceCompressedLength;\n";
            $template .= "    AliceGetCompressedDumpRegion(\&aliceCompressedBase, \&aliceCompressedLength);\n";
            $template .= "    region[$i].addr = aliceCompressedBase;\n";
            $template .= "    region[$i].len = aliceCompressedLength;\n";
            $template .= "    }\n";
        }
        else
        {
            $template .= "    region[$i].addr = ".$DumpRegions_ref->[$i]->[1].";\n";
            $template .= "    region[$i].len = ".$DumpRegions_ref->[$i]->[2].";\n";
        }
        
        $template .= "    region[$i].addr = MAP2CREGPA(region[$i].addr);\n" if($GroupName eq "DYNAMIC_DC_PA");
        $template .= "    region[$i].addr = MAP2CREGVA(region[$i].addr);\n" if($GroupName eq "DYNAMIC_DNC_VA");
        
    }
    return $template;
}
sub Get_Dump_Regions
{
    my @DumpRegions;
    if(!defined $g_DumpRegions)
    {
        $g_DumpRegions = $g_MAUIScat->GetDumpExeRegions($g_bb);
    }
    my $nIndex = 0;
    foreach my $strGroupName (%$g_DumpRegions)
    {
        my $array_ref = $DumpRegions_ref->{$strGroupName};
        foreach my $RegionItem (@$array_ref)
        {
            my $RegionName = $RegionItem->[0];
            my $Info = $g_MAUIScat->GetExeRegionInfo($RegionName);
            if($RegionName eq "DUMP_VECTOR_TABLE")
            {
                print "[$strGroupName]$RegionName: ".$Info->[Region::Base].", ".$Info->[Region::MaxSize]."\n" if($DebugPrint);
                push(@DumpRegions, [$strGroupName, $Info->[Region::Base], $Info->[Region::MaxSize]]); 
                $nIndex++; next;
            }
            if($RegionName =~ /^DYNAMIC_COMP/)
            {
                my $LastRegionName = $RegionItem->[ scalar(@$RegionItem)-1 ];
                my $LastDCMInfo = $g_MAUIScat->GetExeRegionInfo($LastRegionName);
                my $strLength = "(kal_uint32)&Image\$\$$LastRegionName\$\$Base + ".$LastDCMInfo->[Region::MaxSize]." - region\[$nIndex].addr";
                print "[$strGroupName]$RegionName: (kal_uint32)&Image\$\$$RegionName\$\$Base, $strLength\n" if($DebugPrint);
                push(@DumpRegions, [$strGroupName, "(kal_uint32)&Image\$\$$RegionName\$\$Base", $strLength]); 
                $nIndex++; next;
            }
            if($g_MAUIScat->IsFixedLengthDumpGroup($strGroupName))
            {
                print "[$strGroupName]$RegionName: (kal_uint32)&Image\$\$$RegionName\$\$Base, ".$Info->[Region::MaxSize]."\n"if($DebugPrint);
                push(@DumpRegions, [$strGroupName, "(kal_uint32)&Image\$\$$RegionName\$\$Base", $Info->[Region::MaxSize]]); 
                $nIndex++; next;
            }
            else
            {
                my $LastRegionName =  $RegionItem->[ scalar(@$RegionItem)-1 ];
                my $strLength = undef;
                if(scalar(@$RegionItem) == 1)
                {
                    my ($bIsFixed, $strFixedLength) = $g_MAUIScat->IsFixedLengthRegion($RegionName);
                    $strLength = $strFixedLength if ($bIsFixed == 1 
                                         or ($g_bb eq "MT6256" and $RegionName eq "DSP_ROM") 
                                         or ($strGroupName =~ /MCU_([NC|C]+)_DSP_([NC|C]+)/ and $RegionName =~/SHAREMEM/));
                }
                if(!defined $strLength)
                {
                    $strLength = "(kal_uint32)&Image\$\$$LastRegionName\$\$ZI\$\$Limit - region\[$nIndex].addr";
                }
                print "[$strGroupName]$RegionName: (kal_uint32)&Image\$\$$RegionName\$\$Base, $strLength\n" if($DebugPrint);
                push(@DumpRegions, [$strGroupName, "(kal_uint32)&Image\$\$$RegionName\$\$Base", $strLength]); 
                $nIndex++; next;
            }
        }
    }
    return \@DumpRegions; #[[GroupName, Base, Length]...]
}

sub SCAT_C_Gen_REGION_SYMBOL
{
    my $template;
    my $ExeRegion_ref = $g_MAUIScat->GetAllExeRegion();
    foreach (@$ExeRegion_ref)
    {
        $template .= "extern kal_uint32 Image\$\$$_\$\$Base;\n";
        $template .= "extern kal_uint32 Image\$\$$_\$\$RO\$\$Base;\n";
        $template .= "extern kal_uint32 Image\$\$$_\$\$Length;\n";
        $template .= "extern kal_uint32 Image\$\$$_\$\$RO\$\$Length;\n";
        $template .= "extern kal_uint32 Image\$\$$_\$\$ZI\$\$Limit;\n";
    }
    my $MULTIROM_ref = &GetGroupedRegions("MULTIROM");
    my ($BOOTCERT, $SECURE_MAC, $SECURE_RO) = (undef, undef, undef);
    my $bSetDCM = 0;
    foreach (@$MULTIROM_ref)
    {
        my $array_ref = $_;
        if(scalar(@$array_ref) > 1)
        {
            if($array_ref->[0] =~ /DYNAMIC_CODE/ and $bSetDCM == 0)
            {
                my ($strRegionName, $strLenght) = &Get_DCM_Region_Info($array_ref);
                $template .= "extern kal_uint32 Load\$\$$strRegionName\$\$Base;\n";
                $bSetDCM = 1;
            }
            else
            {
                $template .= "extern kal_uint32 Load\$\$".$array_ref->[ 0 ]."\$\$Base;\n"; #FirstRegion
                $template .= "extern kal_uint32 Load\$\$".$array_ref->[ scalar(@$array_ref)-1 ]."\$\$Base;\n"; #LastRegion
            }
        }
        else
        {
            $template .= "extern kal_uint32 Load\$\$".$array_ref->[0]."\$\$Base;\n";
            $BOOTCERT = $_->[0] if($_->[0] =~ /BOOT_CERT/);
            $SECURE_MAC = $_->[0] if($_->[0] =~ /__HIDDEN_SECURE_MAC/);
            $SECURE_RO = $_->[0] if($_->[0] =~ /SECURE_RO/);
        }
    }
    my $ROM_End = &Gen_RegionName_EV_ROM_END("ROM");
    $template .= "extern kal_uint32 Load\$\$$ROM_End\$\$Base;\n";
    my $ROM_2nd_End = &Gen_RegionName_EV_ROM_END("SECONDARY_ROM");
    $template .= "extern kal_uint32 Load\$\$$ROM_2nd_End\$\$Base;\n" if(defined $ROM_2nd_End);
    
    return $template;
}
sub SCAT_C_Gen_ARRAY_DEMP_RESOURCE_TABLE
{
    my $template;
    my $MBA_href = &GetGroupedRegions("MBA");
    foreach(@$MBA_href)
    {
        my $temp = $_->[0]; 
        $temp =~ s/_ROM//;
        $template .= "static kal_uint16 demp_".lc($temp)."_image_table[DEMP_".uc($temp)."_SIZE * DEMP_BLOCK_PER_MB];\n";
    }
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_DEMP_RESOURCE_TABLE_ASSIGN
{
    my $template;
    my $MBA_href = &GetGroupedRegions("MBA");
    foreach(@$MBA_href)
    {
        my $temp = $_->[0]; 
        $temp =~ s/_ROM//;
        $template .= "    demp_image_table[DEMP_".uc($temp)."] = demp_".lc($temp)."_image_table;\n";
    }
    return $template;
}
sub GetGroupedRegionCount
{
    my ($strKey) = @_;
    my $nCount = 0;
    if($strKey eq "CPT")
    {
        my $fpt_count = 1; # ROM
        $fpt_count++ if($g_MAUIScat->IsRegionExistent("SECONDARY_ROM"));
        $nCount = 1 + (4*&GetGroupedRegionCount("DYNAMIC_DNC")) + 
                      (4*&GetGroupedRegionCount("DYNAMIC_DC")) + 
                      (4*&GetGroupedRegionCount("CACHED_RW")) + 
                      (4*&GetGroupedRegionCount("CACHED_RO")) + 
                      (2*&GetGroupedRegionCount("NONCACHED_RW")) + 
                      (2*&GetGroupedRegionCount("NONCACHED_RO")) + 
                      (2*&GetGroupedRegionCount("MULTIROM")) + 
                      1 + #cpt_for_last: DSPTX, DSPRX
                      (&GetGroupedRegionCount("EXTCODE")-1) + 2 +
                      $fpt_count;
    }
    else
    {
        if(exists $g_GroupedRegions{$strKey})
        {
            $nCount = $g_GroupedRegions{$strKey}->[0];
        }
        else
        {
            my $Array_ref = $g_MAUIScat->GetGroupedRegions($strKey);
            $nCount = (scalar(@$Array_ref));
            $g_GroupedRegions{$strKey} = [$nCount, $Array_ref];
        }
    }
    return $nCount;
}
sub SCAT_C_Gen_ARM9_PT_POOLSIZE
{
    my $template;
    my $cpt_count = &GetGroupedRegionCount("CPT");
    if(defined $g_MAUIScat->SearchLoadRegionName("DEMAND_PAGING"))
    {
       $template = "#define MAX_FPT_POOL_SIZE ( DEMP_TOTAL_BIN_SIZE * 4 * 1024)\n";
       $template .="#define MAX_CPT_POOL_SIZE ($cpt_count * 1 * 1024)";
    }
    else
    {
       $template = "#define MAX_FPT_POOL_SIZE ( 0 )\n";
       $template .="#define MAX_CPT_POOL_SIZE ($cpt_count * 1 * 1024)";
    }
    return $template;
}
sub SCAT_C_Gen_ARM11_PT_POOLSIZE
{
    my $template;
    my $cpt_count = &GetGroupedRegionCount("CPT");
    if(defined $g_MAUIScat->SearchLoadRegionName("DEMAND_PAGING"))
    {
       $template = "#define MAX_CPT_POOL_SIZE ( ($cpt_count + DEMP_TOTAL_BIN_SIZE) * 1 * 1024)";
    }
    else
    {
       $template = "#define MAX_CPT_POOL_SIZE ( $cpt_count * 1 * 1024)";
    }
    return $template;
}
sub SCAT_C_Gen_ARRAY_EXTSRAM_REGION
{
    my $DYNAMIC_DNC_Count = 1+&GetGroupedRegionCount("DYNAMIC_DNC");
    my $DYNAMIC_DC_Count = 1+&GetGroupedRegionCount("DYNAMIC_DC");
    my $CACHED_RW_Count = 1+&GetGroupedRegionCount("CACHED_RW"); 
    my $CACHED_RO_Count = 1+&GetGroupedRegionCount("CACHED_RO"); 
    my $NONCACHED_RW_Count = 1+&GetGroupedRegionCount("NONCACHED_RW");
    my $NONCACHED_RO_Count = 1+&GetGroupedRegionCount("NONCACHED_RO"); 
    my $EXTCODE_Count = 1+&GetGroupedRegionCount("EXTCODE");
    my $template = <<"__TEMPLATE";
static EXTSRAM_REGION_INFO_T DYNAMIC_CACHED_EXTSRAM_DNC_REGION[$DYNAMIC_DNC_Count];
static EXTSRAM_REGION_INFO_T DYNAMIC_CACHED_EXTSRAM_DC_REGION[$DYNAMIC_DC_Count];
static EXTSRAM_REGION_INFO_T CACHED_EXTSRAM_REGION[$CACHED_RW_Count];
static EXTSRAM_REGION_INFO_T CACHED_EXTSRAM_CODE_REGION[$CACHED_RO_Count];
static EXTSRAM_REGION_INFO_T NONCACHED_EXTSRAM_REGION[$NONCACHED_RW_Count];
static EXTSRAM_REGION_INFO_T NONCACHED_EXTSRAM_RO_REGION[$NONCACHED_RO_Count];
static EXTSRAM_REGION_INFO_T CACHED_EXTCODE_REGION[$EXTCODE_Count];
__TEMPLATE
}
sub SCAT_C_Gen_ARRAY_MULTIROM_REGION
{
    my $MULTIROM_Count = 1+&GetGroupedRegionCount("MULTIROM");
    my $template = <<"__TEMPLATE";
static EXTSRAM_REGION_INFO_T MULTI_ROM_LOAD_REGION[$MULTIROM_Count];
__TEMPLATE
}
sub SCAT_C_Gen_ARRAY_DSP_SHARE_REGION
{
    my $MCU_C_DSP_C_Count = 1;
    if (!(($MAKEFILE_OPTIONS{'platform'} eq 'MT6573' or $MAKEFILE_OPTIONS{'platform'} eq 'MT6575') and ($MAKEFILE_OPTIONS{'MODE'} eq 'GPRS')))
    {
        $MCU_C_DSP_C_Count++;
    }
    my $MCU_C_DSP_NC_Count = 1+&GetGroupedRegionCount("MCU_C_DSP_NC");
    my $MCU_NC_DSP_C_Count = 1+&GetGroupedRegionCount("MCU_NC_DSP_C"); 
    my $MCU_NC_DSP_NC_Count = 1+&GetGroupedRegionCount("MCU_NC_DSP_NC"); 
    my $template = <<"__TEMPLATE";
static EXTSRAM_REGION_INFO_T MCU_C_DSP_C_REGION[$MCU_C_DSP_C_Count];
static EXTSRAM_REGION_INFO_T MCU_C_DSP_NC_REGION[$MCU_C_DSP_NC_Count];
static EXTSRAM_REGION_INFO_T MCU_NC_DSP_C_REGION[$MCU_NC_DSP_C_Count];
static EXTSRAM_REGION_INFO_T MCU_NC_DSP_NC_REGION[$MCU_NC_DSP_NC_Count];
__TEMPLATE
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_1stRAM_BEGIN
{
    my $template = "0";
    my $array_ref = $g_MAUIScat->GetExeRegionsInRAMByLoadRegion("ROM");
    &sysUtil::sysgen_die("[2.0]There should be execution regions in ROM!", __FILE__, __LINE__) if(!defined $array_ref);
    my $strRegionName = $array_ref->[0];
    my $Offset = lc($g_MAUIScat->GetRegionInfo($strRegionName, Region::Offset));
    if($Offset =~ /\+0xf/)
    {
        $template = "(kal_uint32)((kal_uint32)&Image\$\$$strRegionName\$\$Base & (~0xf0000000))";
    }
    else
    {
        $template = "(kal_uint32)&Image\$\$$strRegionName\$\$Base";
    }
    return $template;
}
sub SCAT_C_Gen_RegionName_EV_1stRAM_END
{
    my $array_ref = $g_MAUIScat->GetExeRegionsInRAMByLoadRegion("ROM");
    &sysUtil::sysgen_die("[2.0]There should be execution regions in ROM!", __FILE__, __LINE__) if(!defined $array_ref);
    return $array_ref->[$#{$array_ref}];
}
sub SCAT_C_Gen_RegionName_EV_1stROM_BEGIN
{
    my $array_ref = $g_MAUIScat->GetExeRegionsByLoadRegion("ROM");
    &sysUtil::sysgen_die("[2.0]There should be execution regions in ROM!", __FILE__, __LINE__) if(!defined $array_ref);
    return $array_ref->[0];
}
sub SCAT_C_Gen_TEMPLATE_1stROM_LENGTH
{
    my $array_ref = $g_MAUIScat->GetExeRegionsInROMByLoadRegion("ROM");
    &sysUtil::sysgen_die("[2.0]There should be execution regions in ROM!", __FILE__, __LINE__) if(!defined $array_ref);
    return &get_region_length($array_ref);
}
sub get_region_length
{
    my ($array_ref) = @_;
    my $template = "";
    foreach (@$array_ref)
    {
        my $Info = $g_MAUIScat->GetExeRegionInfo($_);
        if(defined $Info->[Region::Offset])
        {
            my $Offset = "";
            if($Info->[Region::Offset] =~ /^\+(\w+)/)
            {
                $Offset = " + $1" if(hex($1)!=0);
            }
            $template .= "    Length += (kal_uint32)&Image\$\$$_\$\$Length$Offset;\n";
        }
        else
        {
            my $strBase = $Info->[Region::Base];
            my $strFirstBase = $g_MAUIScat->GetRegionInfo($array_ref->[0], Region::Base);
            if(!defined $strFirstBase)
            {
                my $LoadInfo = $g_MAUIScat->GetLoadRegionInfo($array_ref->[0]);
                $strFirstBase = $LoadInfo->[Region::Base];
            }
            if($strBase ne $strFirstBase)
            {
                $template .= "    Length = $strBase - $strFirstBase; /* $_ define fixed address */ \n";
            }
            $template .= "    Length += (kal_uint32)&Image\$\$$_\$\$Length;\n";
        }
    }
    return $template;
}
sub SCAT_C_Gen_RegionName_EV_1stROM_END
{
    return &Gen_RegionName_EV_ROM_END("ROM");
}
sub Gen_RegionName_EV_ROM_END
{
    my ($ROM) = @_;
    my $array_ref = $g_MAUIScat->GetExeRegionsByLoadRegion($ROM);
    &sysUtil::sysgen_die("[2.0]There should be execution regions in ROM!", __FILE__, __LINE__) if(!defined $array_ref and $ROM eq "ROM");
    my $LastRegion = undef;
    if(defined $array_ref)
    {
        my $nIndex = $#{$array_ref};
        foreach my $i (0 .. $nIndex)
        {
            if($array_ref->[$#{$array_ref} - $i] !~ /INTSRAM_BLINUSED|FLEXL2_DATA|FLMM/)
            {
                $LastRegion = $array_ref->[$#{$array_ref} - $i];
                last;
            }
        }
    }
    return $LastRegion;
}
sub SCAT_C_Gen_TEMPLATE_2ndROM_BEGIN
{
    my $template = "0";
    my $array_ref = $g_MAUIScat->GetExeRegionsByLoadRegion("SECONDARY_ROM");
    $template = '(kal_uint32)&Image$$'.$array_ref->[0].'$$Base' if(defined $array_ref);
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_2ndROM_LENGTH
{
    my $array_ref = $g_MAUIScat->GetExeRegionsInROMByLoadRegion("SECONDARY_ROM");
    return &get_region_length($array_ref);
}
sub SCAT_C_Gen_TEMPLATE_2ndROM_END
{
    my $template = "";
    my $RegionName = &Gen_RegionName_EV_ROM_END("SECONDARY_ROM");
    if(defined $RegionName)
    {
        $template = <<"__TEMPLATE";
    EndAddr  = (kal_uint32)&Load\$\$$RegionName\$\$Base;
    EndAddr += (kal_uint32)&Image\$\$$RegionName\$\$Length;
__TEMPLATE
    }
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_2ndRAM_BEGIN
{
    my $template = "0";
    my $array_ref = $g_MAUIScat->GetExeRegionsInRAMByLoadRegion("SECONDARY_ROM");
    if(scalar(@$array_ref) > 0)
    {
        my $strRegionName = $array_ref->[0];
        my $Offset = lc($g_MAUIScat->GetRegionInfo($strRegionName, Region::Offset));
        if($Offset =~ /\+0xf/)
        {
            $template = "(kal_uint32)((kal_uint32)&Image\$\$$strRegionName\$\$Base & (~0xf0000000))";
        }
        else
        {
            $template = "(kal_uint32)&Image\$\$$strRegionName\$\$Base";
        }
    }
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_2ndRAM_END
{
    my $template = "";
    my $array_ref = $g_MAUIScat->GetExeRegionsInRAMByLoadRegion("SECONDARY_ROM");
    if(scalar(@$array_ref) > 0)
    {
        my $strRegionName = $array_ref->[$#{$array_ref}];
        my $strEnd = ($strRegionName =~/DUMMY_END/) ? "Base" : "ZI\$\$Limit";
        $template = "    EndAddr  = (kal_uint32)&Image\$\$$strRegionName\$\$$strEnd;";
    }
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_SYSRAM_BEGIN
{
    my $strBase = "0xE0000000";
    $strBase = '(kal_uint32)&Image$$INTSRAM_MULTIMEDIA$$Base' if($g_MAUIScat->IsRegionExistent("INTSRAM_MULTIMEDIA"));
    return $strBase;
}
sub SCAT_C_Gen_TEMPLATE_SYSRAM_END
{
    my $strBase = "0xE0000000";
    $strBase = '(kal_uint32)&Image$$INTSRAM_MULTIMEDIA$$ZI$$Limit' if($g_MAUIScat->IsRegionExistent("INTSRAM_MULTIMEDIA"));
    return $strBase;
}
sub SCAT_C_Gen_MaxSize_SYSRAM
{
    my $strMaxSize = "0";
    $strMaxSize = $g_MAUIScat->GetRegionInfo("INTSRAM_MULTIMEDIA", Region::MaxSize) if($g_MAUIScat->IsRegionExistent("INTSRAM_MULTIMEDIA"));
    return $strMaxSize;
}
sub SCAT_C_Gen_SYSRAM_Info
{
    my $template = undef;
    my($strBase,$strLength,$strRet);
    if(&sysUtil::is_noSYSRAM($g_bb))
    {
        $strBase = "0xFFFFFFFF";
        $strLength = "0x0";
        $strRet = "-1";
    }
    else
    {
       ($strBase,$strLength) = &sysUtil::GetSysramInfo($g_bb);
       $strRet = "0";
    }

    $template = <<"__TEMPLATE";
    *addr = $strBase;
    *len = $strLength;
    return $strRet;
__TEMPLATE

    chomp($template);
    return $template;
}
sub SCAT_C_Gen_RegionName_EV_INTSRAM_HW_BOUNDARY
{
    my $strRegion = "INTSRAM_DATA";
    $strRegion = "INTSRAM_PHYSICAL_BOUNDARY" if($g_MAUIScat->IsRegionExistent("INTSRAM_PHYSICAL_BOUNDARY"));
    return $strRegion;
}
sub SCAT_C_Gen_MaxSize_INTSRAM_HW_BOUNDARY
{
    my $strMaxSize = "0";
    $strMaxSize = $g_MAUIScat->GetRegionInfo("INTSRAM_PHYSICAL_BOUNDARY", Region::MaxSize) if($g_MAUIScat->IsRegionExistent("INTSRAM_PHYSICAL_BOUNDARY"));
    return $strMaxSize;
}
sub SCAT_C_Gen_TEMPLATE_PROTECTED_RES_BEGIN
{
    return &Gen_Region_EV_TEMPLATE("PROTECTED_RES", "Base");
}
sub SCAT_C_Gen_TEMPLATE_PROTECTED_RES_LEGNTH
{
    return &Gen_Region_EV_TEMPLATE("PROTECTED_RES", "Length");
}
sub SCAT_C_Gen_TEMPLATE_BOOTCERT_BEGIN
{
    my $template = "0";
    $template = '(kal_uint32)&Image$$BOOT_CERT$$Base' if($g_MAUIScat->IsRegionExistent("BOOT_CERT"));
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_BOOTCERT_LEGNTH
{
    my $array_ref = $g_MAUIScat->GetExeRegionsByLoadRegion("BOOT_CERT");
    return &get_region_length($array_ref);
}
sub SCAT_C_Gen_TEMPLATE_SECUREMAC_BEGIN
{
    my $template = "0";
    $template = '(kal_uint32)&Load$$__HIDDEN_SECURE_MAC$$Base' if($g_MAUIScat->IsRegionExistent("__HIDDEN_SECURE_MAC"));
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_SECUREMAC_LEGNTH
{
    my $template = "0";
    $template = '(kal_uint32)&Image$$__HIDDEN_SECURE_MAC$$Length + (kal_uint32)&Image$$__HIDDEN_SECURE_MAC_CONTENT$$Length' 
    if($g_MAUIScat->IsRegionExistent("__HIDDEN_SECURE_MAC"));
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_SECURERO_BEGIN
{
    my $template = "0";
    $template = '(kal_uint32)&Load$$SECURE_RO$$Base' if($g_MAUIScat->IsRegionExistent("SECURE_RO"));
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_SECURERO_LEGNTH
{
    my $template = "0";
    $template = '(kal_uint32)&Image$$SECURE_RO$$Length' if($g_MAUIScat->IsRegionExistent("SECURE_RO"));
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_DSPTXRX_BEGIN
{
    my $template = "0";
    my $strRegionName = $g_MAUIScat->SearchExeRegionName("_DSP_TX");
    $strRegionName = $g_MAUIScat->SearchExeRegionName("_DSP_RX") if(!defined $strRegionName);
    $template = "(kal_uint32)&Image\$\$$strRegionName\$\$Base" if(defined $strRegionName);
    return $template;
}

sub SCAT_C_Gen_TEMPLATE_DSPTXRX_VAR_DECLARE
{
    my $hasDSPTXRX_buff = &sysUtil::HasDSPTXRX_buff($g_bb);
    my $isNorFB = (exists $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} eq 'NONE')? 1 : 0;
    my $varDeclare = '';
    if($hasDSPTXRX_buff)
    {
        if($isNorFB)
        {
            if($g_bb eq 'MT6251')
            {
               $varDeclare =    "extern kal_uint32 Image\$\$INTSRAM_DSP_TX_RX\$\$ZI\$\$Length;\n" 
            }
            else
            {
                $varDeclare = "extern kal_uint32 Image\$\$EXTSRAM_DSP_TX\$\$ZI\$\$Length;\n";
                $varDeclare .= "extern kal_uint32 Image\$\$EXTSRAM_DSP_RX\$\$ZI\$\$Length;\n";
            }
        }
        else
        {
            $varDeclare = "extern kal_uint32 Image\$\$SECONDARY_EXTSRAM_DSP_TX\$\$ZI\$\$Length;\n";
            $varDeclare .= "extern kal_uint32 Image\$\$SECONDARY_EXTSRAM_DSP_RX\$\$ZI\$\$Length;\n";
        }
    }
    return $varDeclare;
}
sub SCAT_C_Gen_TEMPLATE_DSPTXRX_BASE_LEN
{
    my $template = '';
    my $isNorFB = (exists $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} eq 'NONE')? 1 : 0;
    if($isNorFB && ($g_bb eq 'MT6251'))
    {
        $template =<<"__TEMPLATE"
   *TX_Base = (kal_uint32)&Image\$\$INTSRAM_DSP_TX_RX\$\$Base;
   *RX_Base = (kal_uint32)&Image\$\$INTSRAM_DSP_TX_RX\$\$Base;
   
   region_sz = 4 * 1024;
   while (region_sz < ((kal_uint32)&Image\$\$INTSRAM_DSP_TX_RX\$\$Length
                      +(kal_uint32)&Image\$\$INTSRAM_DSP_TX_RX\$\$ZI\$\$Length))
   {
      region_sz = region_sz << 1;
   }
   *TX_Size = region_sz;
   *RX_Size = region_sz;
__TEMPLATE
    }
    else
    {
        my ($TX_Base,$RX_Base,$TX_Len,$TX_ZI_Len,$RX_Len,$RX_ZI_Len);
        if($isNorFB)
        {
            $TX_Base = "(kal_uint32)&Image\$\$EXTSRAM_DSP_TX\$\$Base";
            $RX_Base = "(kal_uint32)&Image\$\$EXTSRAM_DSP_RX\$\$Base";
            $TX_Len = "(kal_uint32)&Image\$\$EXTSRAM_DSP_TX\$\$Length";
            $TX_ZI_Len = "(kal_uint32)&Image\$\$EXTSRAM_DSP_TX\$\$ZI\$\$Length";
            $RX_Len = "(kal_uint32)&Image\$\$EXTSRAM_DSP_RX\$\$Length";
            $RX_ZI_Len = "(kal_uint32)&Image\$\$EXTSRAM_DSP_RX\$\$ZI\$\$Length)";
        }
        else
        {
            $TX_Base = "(kal_uint32)&Image\$\$SECONDARY_EXTSRAM_DSP_TX\$\$Base";
            $RX_Base = "(kal_uint32)&Image\$\$SECONDARY_EXTSRAM_DSP_RX\$\$Base";
            $TX_Len = "(kal_uint32)&Image\$\$SECONDARY_EXTSRAM_DSP_TX\$\$Length";
            $TX_ZI_Len = "(kal_uint32)&Image\$\$SECONDARY_EXTSRAM_DSP_TX\$\$ZI\$\$Length";
            $RX_Len = "(kal_uint32)&Image\$\$SECONDARY_EXTSRAM_DSP_RX\$\$Length";
            $RX_ZI_Len = "(kal_uint32)&Image\$\$SECONDARY_EXTSRAM_DSP_RX\$\$ZI\$\$Length)";
        }
        
        $template =<<"__TEMPLATE"
   *TX_Base = $TX_Base;
   *RX_Base = $RX_Base;

   region_sz = 4 * 1024;
   while (region_sz < ($TX_Len
                      +$TX_ZI_Len))
   {
      region_sz = region_sz << 1;
   }
   *TX_Size = region_sz;

   region_sz = 4 * 1024;
   while (region_sz < ($RX_Len
                      +$RX_ZI_Len)
   {
      region_sz = region_sz << 1;
   }
   *RX_Size = region_sz;
__TEMPLATE
    }

    chomp($template);
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_DSPTXRX_CHIPSELECT
{
    my $template = '';
    my $isNorFB = (exists $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} eq 'NONE')? 1 : 0;
    my $ret = &sysUtil::GetDSPTXRX_chipselect($g_bb,$isNorFB);

    if($isNorFB && ($g_bb eq 'MT6251'))
    {
        $template = "    chipSelect = 0;\n";
    }
    else
    {
        $template = ($ret)? "    chipSelect = (*TX_Base&0xF0000000) >> 27;\n" 
                          : "    chipSelect = (*TX_Base&0xF8000000) >> 27;\n";
    }

    chomp($template);
    return $template;
}

sub SCAT_C_Gen_TEMPLATE_DSPTXRX_CHIPSELECT_CK
{
    my $template = '';
    my $isNorFB = (exists $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} eq 'NONE')? 1 : 0;
    my $ret = &sysUtil::GetDSPTXRX_chipselect_ck($g_bb,$isNorFB);
    $template = ($ret) ? "    ASSERT(chipSelect<=2);\n"
                       : "    ASSERT(chipSelect<2);\n";
    chomp($template);
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_MAX_FREERAM_NON_MMU
{
    my $template;
    if($g_bb eq "MT6251")
    {
        $template = <<"__TEMPLATE";
    /* Round 1 */
    ThisRegionBegin = (kal_uint32)&Image\$\$INTSRAM_DSP_TX_RX\$\$Base;
    LastRegionEnd   = (kal_uint32)&Image\$\$INTSRAM_DATA_PREINIT\$\$ZI\$\$Limit;
    LastRegionEnd   = (LastRegionEnd + 16) & 0xFFFFFFF0;
    if ((ThisRegionBegin - LastRegionEnd) > MaxLength)
    {
       MaxBeginAddr = LastRegionEnd;
       MaxLength    = ThisRegionBegin - LastRegionEnd;
    }
__TEMPLATE
    }
    elsif(0 == &sysUtil::is_mmu($g_bb))
    {
        my $array_ref = &GetGroupedRegions("NONCACHED_RW");
        my $nIndex = 0;
        my $PreviousLastRegion;
        foreach(@$array_ref)
        {
            if($nIndex > 0)
            {
                my $ThisRegion = $_->[0];
                $template .= <<"__TEMPLATE";
    /* Round $nIndex */
    ThisRegionBegin = (kal_uint32)&Image\$\$$ThisRegion\$\$Base;
    LastRegionEnd   = (kal_uint32)&Image\$\$$PreviousLastRegion\$\$ZI\$\$Limit;
    LastRegionEnd   = (LastRegionEnd + 16) & 0xFFFFFFF0;
    if ((ThisRegionBegin - LastRegionEnd) > MaxLength)
    {
       MaxBeginAddr = LastRegionEnd;
       MaxLength    = ThisRegionBegin - LastRegionEnd;
    }
__TEMPLATE
            }
            $PreviousLastRegion = $_->[$#$_];
            $nIndex++;
        }
    }
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_MAX_FREERAM_MMU
{
    my $DUMMY_END = &Gen_RegionName_EV_DUMMY_END_Base();
    my $LAST_CACHED_REGION = &Gen_RegionName_EV_LAST_CACHED_REGION();
    my $strLastRegionEnd;
    my $strExternAlicefunc;
    my $MAP2CREGPAtemplate;
    my $strSWLA_res_size = '0';
    if(&FileInfo::is("alice_support", "TRUE") and !&FileInfo::is_NOR())
    {
        $strExternAlicefunc = "extern kal_uint32 AliceGetRawDataEndAddress(void);";
        $strLastRegionEnd = "AliceGetRawDataEndAddress()";
    }
    else
    {
        $strLastRegionEnd = "(kal_uint32)&Image\$\$$LAST_CACHED_REGION\$\$ZI\$\$Limit";
        $MAP2CREGPAtemplate = <<"__MAP2CREGPATEMPLATE"
    /* Convert to non-cached address */
    MaxBeginAddr  =  MAP2CREGPA(MaxBeginAddr);
__MAP2CREGPATEMPLATE

    }

    my $Info = $g_MAUIScat->GetExeRegionInfo('SWLA_RES_MEM');
    if(defined $Info->[Region::Base] and defined $Info->[Region::MaxSize])
    {
        $strSWLA_res_size =  $Info->[Region::MaxSize];
        my $strSWLA_res_base = $Info->[Region::Base];
        my $DummyEndInfo = $g_MAUIScat->GetExeRegionInfo($DUMMY_END);
        my $strDummy_end_base = $DummyEndInfo->[Region::Base];
        if($strSWLA_res_base ne $strDummy_end_base)
        {
            &sysUtil::sysgen_die("[2.0]$SCATTERFILE: SWLA_RES_MEM base:$strSWLA_res_base is not equal to $DUMMY_END:$strDummy_end_base base!", __FILE__, __LINE__);
        }
    }
    
    my $template = <<"__TEMPLATE";
    {
        $strExternAlicefunc
        /* Direct Assign the Cached Region */
        ThisRegionBegin = (kal_uint32)&Image\$\$$DUMMY_END\$\$Base + $strSWLA_res_size;
        LastRegionEnd   = $strLastRegionEnd;
        LastRegionEnd   = (LastRegionEnd + 16) & 0xFFFFFFF0;
    }

    MaxLength       = (ThisRegionBegin & 0x0FFFFFFF) - (LastRegionEnd  & 0x0FFFFFFF);
    MaxBeginAddr    = LastRegionEnd;

    /* round to 4KB aligned */
    MaxBeginAddr = ((MaxBeginAddr + 4096 - 1) >> 12) << 12;

    if (MaxLength < 4096) {
        MaxLength = 0;
    } else {
        /* round down to 4KB aligned */
        MaxLength -= 4096;
        /* round up end address to 4KB aligned */
        MaxLength = (MaxLength / 4096) * 4096;
    }

    $MAP2CREGPAtemplate
__TEMPLATE

    return (1 == &sysUtil::is_mmu($g_bb)) ? $template: "";
}
sub Gen_RegionName_EV_DUMMY_END_Base
{
    my $strRegionName;
    if(1 == &sysUtil::is_mmu($g_bb))
    {
        $strRegionName = "CACHED_DUMMY_END";
        $strRegionName = $g_MAUIScat->SearchExeRegionName("DUMMY_END") if(! $g_MAUIScat->IsRegionExistent($strRegionName));
    }
    return $strRegionName;
}
sub Gen_RegionName_EV_LAST_CACHED_REGION
{
    my $strPreviousRegionName;
    if(1 == &sysUtil::is_mmu($g_bb))
    {
        my $strRegionName = &Gen_RegionName_EV_DUMMY_END_Base();
        $strPreviousRegionName = $g_MAUIScat->GetPreviousExeRegionName($strRegionName) if(defined $strRegionName);
        &sysUtil::sysgen_die("[2.0]Region Name can't be empty!", __FILE__, __LINE__) if(!defined $strPreviousRegionName);
    }
    return $strPreviousRegionName;
}

sub SCAT_C_Gen_TEMPLATE_NVRAM_BASE
{
    return &Gen_Region_EV_TEMPLATE("NVRAM", "Base");
}
sub SCAT_C_Gen_TEMPLATE_NVRAM_LENGTH
{
    return &Gen_Region_EV_TEMPLATE("NVRAM", "Length");
}
sub SCAT_C_Gen_TEMPLATE_DSP_ROM_BASE
{
    return &Gen_Region_EV_TEMPLATE("DSP_ROM", "Base");
}
sub SCAT_C_Gen_TEMPLATE_DSP_ROM_LENGTH
{
    return &Gen_Region_EV_TEMPLATE("DSP_ROM", "Length");
}
sub Gen_Region_EV_TEMPLATE
{
    my ($strKey, $strPostfix) = @_;
    my $template = "0";
    my $RegionName = $g_MAUIScat->SearchExeRegionName($strKey);
    if(defined $RegionName)
    {
        $template = "(kal_uint32)&Image\$\$$RegionName\$\$$strPostfix";
    }
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_EXTSRAM_REGION_DYNAMIC_DC_ASSIGN
{
    return &get_region_info_template("DYNAMIC_DC","DYNAMIC_CACHED_EXTSRAM_DC_REGION");
}
sub SCAT_C_Gen_TEMPLATE_EXTSRAM_REGION_DYNAMIC_DNC_ASSIGN
{
    return &get_region_info_template("DYNAMIC_DNC","DYNAMIC_CACHED_EXTSRAM_DNC_REGION");
}
sub SCAT_C_Gen_TEMPLATE_EXTSRAM_REGION_CACHED_RW_ASSIGN
{
    return &get_region_info_template("CACHED_RW","CACHED_EXTSRAM_REGION");
}
sub SCAT_C_Gen_TEMPLATE_EXTSRAM_REGION_CACHED_RO_ASSIGN
{
    return &get_region_info_template("CACHED_RO","CACHED_EXTSRAM_CODE_REGION");
}
sub SCAT_C_Gen_TEMPLATE_EXTSRAM_REGION_NONCACHED_RW_ASSIGN
{
    return &get_region_info_template("NONCACHED_RW","NONCACHED_EXTSRAM_REGION");
}
sub SCAT_C_Gen_TEMPLATE_EXTSRAM_REGION_NONCACHED_RO_ASSIGN
{
    return &get_region_info_template("NONCACHED_RO","NONCACHED_EXTSRAM_RO_REGION");
}
#****************************************************************************
# API FOR FOTA
#****************************************************************************
sub SCAT_FOTA_C_Gen_BASE_INTSRAMCODE
{
    require "tools/scatGenFOTA.pl";
    PrintDependModule();
    my ($strCODE_Base, $strCODE_Size, $strDATA_Base, $strDATA_Size) = &Get_TCM_info($g_bb); 
    $strCODE_Base = "0xE0000000" if (!defined $strCODE_Base);
    return $strCODE_Base;
}
sub SCAT_FOTA_C_Gen_Length_INTSRAMCODE
{
    require "tools/scatGenFOTA.pl";
    PrintDependModule();
    my ($strCODE_Base, $strCODE_Size, $strDATA_Base, $strDATA_Size) = &Get_TCM_info($g_bb);
    $strCODE_Size = "0" if (!defined $strCODE_Size);
    return $strCODE_Size;
}
sub SCAT_FOTA_C_Gen_Base_INTSRAMDATA
{
    require "tools/scatGenFOTA.pl";
    PrintDependModule();
    my ($strCODE_Base, $strCODE_Size, $strDATA_Base, $strDATA_Size) = &Get_TCM_info($g_bb);
    $strDATA_Base = "0xE0000000" if (!defined $strDATA_Base);
    return $strDATA_Base;
}
sub SCAT_FOTA_C_Gen_Length_INTSRAMDATA
{
    require "tools/scatGenFOTA.pl";
    PrintDependModule();
    my ($strCODE_Base, $strCODE_Size, $strDATA_Base, $strDATA_Size) = &Get_TCM_info($g_bb);
    $strDATA_Size = "0" if (!defined $strDATA_Size);
    return $strDATA_Size;
}
sub GetGroupedRegions
{
    my ($strKey) = @_;
    my $Array_ref = undef;
    my $nCount = 0;
    if(exists $g_GroupedRegions{$strKey})
    {
        $Array_ref = $g_GroupedRegions{$strKey}->[1];
    }
    else
    {
        $Array_ref = $g_MAUIScat->GetGroupedRegions($strKey);
        $nCount = (scalar(@$Array_ref));
        $g_GroupedRegions{$strKey} = [$nCount, $Array_ref];
    }
    return $Array_ref;
}
sub get_region_info_template
{
    my ($strKey, $strArrayName) = @_;
    my $template;
    my $GroupedRegion_ref = &GetGroupedRegions($strKey);
    my $nIndex =0;
    my $RegionPrefix = ($strKey ne "MULTIROM") ? "Image" : "Load";
    foreach (@$GroupedRegion_ref) #[[], [], []]
    {
        my $array_ref = $_;
        my $Region = $array_ref->[0];
        my $strLength = undef;
        if($Region =~ /DYNAMIC_CODE/ and $strKey eq "MULTIROM")
        {# DCM Regions in MULTIROM should be handled especially
            ($Region, $strLength) = &Get_DCM_Region_Info($array_ref);
        }
        $template .= "    $strArrayName\[$nIndex].addr = (kal_uint32)&$RegionPrefix\$\$$Region\$\$Base;\n";
        
        if(scalar(@$array_ref) > 1)
        {
            $Region = $array_ref->[ scalar(@$array_ref)-1 ]; #LastRegion
            
        }
        else
        {
            my ($bIsFixed, $strFixedLength) = $g_MAUIScat->IsFixedLengthRegion($Region);
            $strLength = $strFixedLength if ($bIsFixed == 1 
                                         or ($g_bb eq "MT6256" and $Region eq "DSP_ROM") 
                                         or ($strKey =~ /MCU_([NC|C]+)_DSP_([NC|C]+)/ and $Region =~/SHAREMEM/));
        }
        if(!defined $strLength)
        {
            if($Region =~/RW$|JUMP_TABLE|BOOT_CERT|CUST_PARA|SECURE_MAC/)
            {
                $strLength = "(kal_uint32)((kal_uint32)&$RegionPrefix\$\$$Region\$\$Base + (kal_uint32)&Image\$\$$Region\$\$Length) - $strArrayName\[$nIndex].addr";
            }
            elsif($Region =~/SECURE_RO|FLASHTOOL_CFG/)
            {   
                $strLength = "(kal_uint32)&Image\$\$$Region\$\$Length";
            }
            else
            {
                $strLength = "(kal_uint32)&Image\$\$$Region\$\$ZI\$\$Limit - $strArrayName\[$nIndex].addr";
            }
        }
        $template .= "    $strArrayName\[$nIndex].len = $strLength;\n";
        $nIndex++;
    }
    $template .= "    $strArrayName\[$nIndex].addr = $strArrayName\[$nIndex].len = 0;\n";
    return $template;
}
sub Get_DCM_Region_Info
{
    my ($array_ref) = @_;
    my $strBaseRegion;
    my $nStart = 0xFFFFFFFF;
    my $nEnd = 0;
    foreach (@$array_ref)
    {
        my $Info = $g_MAUIScat->GetExeRegionInfo($_);
        my $nBase = hex($Info->[Region::Base]);
        my $nMaxSize = hex($Info->[Region::MaxSize]);
        if ($nBase < $nStart)
        {
            $nStart = $nBase;
            $strBaseRegion = $_;
        }
        $nEnd = $nBase+$nMaxSize if($nEnd < $nBase+$nMaxSize);
    }
    my $strLength = &CommonUtil::Dec2Hex($nEnd - $nStart);
    return ($strBaseRegion, $strLength);
}
sub SCAT_C_Gen_TEMPLATE_EXTCODE_ASSIGN
{
    my ($strKey, $strArrayName) = ("EXTCODE", "CACHED_EXTCODE_REGION");
    my $template;
    my $GroupedRegion_ref = &GetGroupedRegions($strKey);
    my $nIndex =0;
    foreach (@$GroupedRegion_ref) #[[], [], []]
    {
        my $array_ref = $_;
        my $Region = $array_ref->[0];
        $template .= "    $strArrayName\[$nIndex].addr = (kal_uint32)&Image\$\$$Region\$\$Base;\n";
        if($Region =~ /^ROM/)
        {
            $template .= "    $strArrayName\[$nIndex].len = custom_get_1st_ROM_ROMLength();\n" 
        }
        elsif($Region =~ /SECONDARY_ROM/)
        {
            $template .= "    $strArrayName\[$nIndex].len = custom_get_2nd_ROM_ROMLength();\n";
        }
        elsif(scalar(@$array_ref) > 1)
        {
            $Region = $array_ref->[ scalar(@$array_ref)-1 ]; #LastRegion
            $template .= "    $strArrayName\[$nIndex].len = (kal_uint32)((kal_uint32)&Load\$\$$Region\$\$Base + (kal_uint32)&Image\$\$$Region\$\$Length) - $strArrayName\[$nIndex].addr;\n";
        }
        else
        {   #sync with MBA region in MULTIROM group in get_region_info_template() 
            my $load_region = $g_MAUIScat->GetLoadRegionsByExeRegion($Region);
            my $info_ref = $g_MAUIScat->GetLoadRegionInfo($load_region);
            my $strFixedLength = $info_ref->[Region::MaxSize] if(defined $info_ref->[Region::Attribute]);
            $template .= "    $strArrayName\[$nIndex].len = $strFixedLength;\n";
        }
        $nIndex++;
    }
    $template .= "    $strArrayName\[$nIndex].addr = $strArrayName\[$nIndex].len = 0;\n";
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_MULTIROM_ASSIGN
{
    &get_region_info_template("MULTIROM", "MULTI_ROM_LOAD_REGION");
}
sub SCAT_C_Gen_TEMPLATE_MCU_NC_DSP_C_ASSIGN
{
    return &get_region_info_template("MCU_NC_DSP_C","MCU_NC_DSP_C_REGION");
}
sub SCAT_C_Gen_TEMPLATE_MCU_C_DSP_NC_ASSIGN
{
    return &get_region_info_template("MCU_C_DSP_NC","MCU_C_DSP_NC_REGION");
}
sub SCAT_C_Gen_TEMPLATE_MCU_C_DSP_C_ASSIGN
{
    my $template;
    if (!(($MAKEFILE_OPTIONS{'platform'} eq 'MT6573' or $MAKEFILE_OPTIONS{'platform'} eq 'MT6575') and ($MAKEFILE_OPTIONS{'MODE'} eq 'GPRS')))
    {
        $template = <<"__TEMPLATE";
#if defined(__MED_IN_ASM__)
    #if __VIDEO_STANDALONE_MEMORY__
    MCU_C_DSP_C_REGION[0].addr = ((kal_uint32)&Image\$\$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_VIDEOPOOL\$\$Base & (~0xf0000000));
    MCU_C_DSP_C_REGION[0].len = ((kal_uint32)&Image\$\$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL\$\$Base & (~0xf0000000)) - MCU_C_DSP_C_REGION[0].addr;
    #else /* __VIDEO_STANDALONE_MEMORY__ */
    MCU_C_DSP_C_REGION[0].addr = ((kal_uint32)&Image\$\$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL\$\$Base & (~0xf0000000));
    MCU_C_DSP_C_REGION[0].len = ((kal_uint32)&Image\$\$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI\$\$Base & (~0xf0000000)) - MCU_C_DSP_C_REGION[0].addr;
    #endif /* __VIDEO_STANDALONE_MEMORY__ */
#else  /* __MED_IN_ASM__ */
    MCU_C_DSP_C_REGION[0].addr = (kal_uint32)&Image\$\$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL\$\$Base;
    MCU_C_DSP_C_REGION[0].len = (kal_uint32)&Image\$\$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI\$\$Base - MCU_C_DSP_C_REGION[0].addr;
#endif  /* __MED_IN_ASM__ */
    MCU_C_DSP_C_REGION[1].addr = MCU_C_DSP_C_REGION[1].len = 0;
__TEMPLATE
    }
    else
    {
        $template = "    MCU_C_DSP_C_REGION[0].addr = MCU_C_DSP_C_REGION[0].len = 0;";
    }
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_MCU_NC_DSP_NC_ASSIGN
{
    return &get_region_info_template("MCU_NC_DSP_NC","MCU_NC_DSP_NC_REGION");
}
sub SCAT_C_Gen_MaxSize_56_DSP_ROM
{
    my $strMaxSize= "0";
    $strMaxSize = $g_MAUIScat->GetRegionInfo("DSP_ROM", Region::MaxSize) if($g_bb eq "MT6256");
    return $strMaxSize;
}
sub SCAT_C_Gen_MaxSize_56_TX1
{
    my $strMaxSize= "0";
    $strMaxSize = $g_MAUIScat->GetRegionInfo("SECONDARY_EXTSRAM_DSP_RW_MCU_RW_TX1", Region::MaxSize) if($g_bb eq "MT6256");
    return $strMaxSize;
}
sub SCAT_C_Gen_MaxSize_56_TX2_AND_RX
{
    my $strMaxSize= "0";
    $strMaxSize = $g_MAUIScat->GetRegionInfo("SECONDARY_EXTSRAM_DSP_RW_MCU_RW_DMA_RW_TX2_AND_RX", Region::MaxSize) if($g_bb eq "MT6256");
    return $strMaxSize;
}
sub SCAT_C_Gen_MaxSize_56_DSPOnly
{
    my $strMaxSize= "0";
    $strMaxSize = $g_MAUIScat->GetRegionInfo("SECONDARY_EXTSRAM_DSP_RW_DSPONLY", Region::MaxSize) if($g_bb eq "MT6256");
    return $strMaxSize;
}
sub SCAT_C_Gen_MaxSize_56_DMA
{
    my $strMaxSize= "0";
    $strMaxSize = $g_MAUIScat->GetRegionInfo("SECONDARY_EXTSRAM_DSP_DMA_RX", Region::MaxSize) if($g_bb eq "MT6256");
    return $strMaxSize;
}
sub SCAT_C_Gen_TEMPLATE_SINGLEBANK_BEGIN
{
    return &Gen_Region_EV_TEMPLATE("SINGLE_BANK_CODE", "Base");
}
sub SCAT_C_Gen_TEMPLATE_SINGLEBANK_NEXT
{
    my $template = "0";
    my $strRegionName = $g_MAUIScat->SearchExeRegionName("SINGLE_BANK_CODE");
    if(defined $strRegionName)
    {
        $strRegionName = $g_MAUIScat->GetNextExeRegionName($strRegionName);
        $template = "(kal_uint32)&Image\$\$$strRegionName\$\$Base";
    }
    return $template;
}
sub SCAT_C_Gen_TEMPLATE__EXTSRAMALICE_NEXT
{
    my $template = "0";
    my $strRegionName = $g_MAUIScat->SearchExeRegionName("EXTSRAM_ALICE");
    if(defined $strRegionName)
    {
        $strRegionName = $g_MAUIScat->GetNextExeRegionName($strRegionName);
        $template = "(kal_uint32)&Image\$\$$strRegionName\$\$Base";
    }
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_ALICE_BEGIN
{
    my $template = "0xE0000000";
    my $array_ref = $g_MAUIScat->GetExeRegionsByLoadRegion("ALICE");
    $template = '(kal_uint32)&Image$$'.$array_ref->[0].'$$Base' if(defined $array_ref);
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_ALICE_LEGNTH
{
    my $template = "0";
    my $array_ref = $g_MAUIScat->GetExeRegionsByLoadRegion("ALICE");
    $template = '(kal_uint32)&Image$$'.$array_ref->[0].'$$Length' if(defined $array_ref);    
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_ZIMAGE_RO_REGION_ASSIGN
{
    my $template = &get_region_base_and_length("ZIMAGE","RO_ONLY"); 
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_ZIMAGE_REGION_ASSIGN
{
    my $template = &get_region_base_and_length("ZIMAGE",""); 
    return $template;
}

sub SCAT_C_Gen_TEMPLATE_BOOT_ZIMAGE_REGION_ASSIGN
{
    my $template = &get_region_base_and_length("BOOT_ZIMAGE",""); 
    return $template;
}

sub get_region_base_and_length
{
    my $loadRegionName = shift;
    my $attr = shift;
    my $template="";
    if(!$g_MAUIScat->IsRegionExistent($loadRegionName))
    {
        $template = "    region->addr = 0x0;\n";
        $template .= "    region->len = 0x0;";
    }
    else
    {
        my $array_ref = $g_MAUIScat->GetExeRegionsByLoadRegion($loadRegionName);
        my ($firstExeRegion, $lastExeRegion) = ($array_ref->[0],$array_ref->[$#{$array_ref}]);
        if($attr eq 'RO_ONLY')
        {
            $template = "    region->addr = (kal_uint32)&Image\$\$$firstExeRegion\$\$RO\$\$Base;\n";
            $template .= "    region->len = (kal_uint32)0x0;\n";
            for my $i (0..$#{$array_ref})
            {
                my $region = $array_ref->[$i];
                $template .= "    region->len += (kal_uint32)&Image\$\$$region\$\$RO\$\$Length;\n"; 
            }
        }
        else
        {
            $template = "    region->addr = (kal_uint32)&Image\$\$$firstExeRegion\$\$Base;\n";
            $template .= "    region->len = (kal_uint32)&Image\$\$$lastExeRegion\$\$ZI\$\$Limit - region->addr;";      	
        }

    } 
    return $template;
}

sub SCAT_C_Gen_TEMPLATE_DCM_REGION_ASSIGN
{
    my $template="";
    if(!$g_MAUIScat->IsRegionExistent("DYNAMIC_COMP_CODE"))
    {
        $template = "    region->addr = 0x0;\n";
        $template .= "    region->len = 0x0;";  
    }
    else
    {
        my $GroupedRegion_ref = &GetGroupedRegions("DCM");           
        foreach (@$GroupedRegion_ref) #[[], [], []]
        {
            my $array_ref = $_;
            my $strLength = undef;
            my $LastRegionName = $array_ref->[ scalar(@$array_ref)-1 ];
            my $FirstRegionName = $array_ref->[0];
            my $LastDCMInfo = $g_MAUIScat->GetExeRegionInfo($LastRegionName);
            my $strLength = "(kal_uint32)&Image\$\$$LastRegionName\$\$Base + ".$LastDCMInfo->[Region::MaxSize]." - region->addr";
            $template .= "    region->addr = (kal_uint32)&Image\$\$$FirstRegionName\$\$Base;\n";
            $template .= "    region->len = $strLength;";
        }
    }

    return $template;
}

my $code_region_str="";
sub SCAT_C_Gen_CODE_REGION_ARRAY_ASSIGN
{
    my ($template,$count) = &get_all_code_addr_info();
    my $str = "static EXTSRAM_REGION_INFO_T TOTAL_CODE_REGION[$count];\n"; 
    $code_region_str = $template;
    return $str;
}

sub SCAT_C_Gen_CODE_REGION_ASSIGN
{
    #my ($template,$count) = &get_all_code_addr_info();
    return $code_region_str;
}

sub GetAllRegionsInSameGroup()
{
    my ($strKey) = @_;
    my $arr_ref = undef;
    if (exists $g_RegionsInSameGroup{$strKey})
    {
        $arr_ref = $g_RegionsInSameGroup{$strKey};
    }
    else
    {
        $arr_ref = $g_MAUIScat->GetAllRegionsInSameGroup($strKey);
        $g_RegionsInSameGroup{$strKey} = $arr_ref;
    }
    
    return $arr_ref;
}
sub GetSpecialGroupRegions
{
    my ($strKey) = @_;
    my @specialGroupRegions;
    foreach my $group (@$strKey)
    {
        my $arr_ref = &GetAllRegionsInSameGroup($group);
        push (@specialGroupRegions,@$arr_ref) if(defined $arr_ref);
        print "[GetSpecialGroupRegions]$group: @$arr_ref\n" if(defined $arr_ref and $DebugPrint);
    }
    return \@specialGroupRegions;
}
sub get_all_code_addr_info
{
    my $template="";
    my $ExeRegion_ref = $g_MAUIScat->GetAllExeRegion();
    my $nIndex = 0;

    #for ROM/SECONDARY_ROM
    {
        my $exeRegion = $g_MAUIScat->GetFirstExeRegionNameByLoadRegion("ROM");
        if(defined $exeRegion)
        {
            $template .= "    TOTAL_CODE_REGION[$nIndex].addr = (kal_uint32)&Image\$\$$exeRegion\$\$RO\$\$Base;\n";
            $template .= "    TOTAL_CODE_REGION[$nIndex].len = custom_get_1st_ROM_ROMLength();\n";
            $nIndex++;
        }
        
        my $exeRegion = $g_MAUIScat->GetFirstExeRegionNameByLoadRegion("SECONDARY_ROM");
        if(defined $exeRegion)
        {
            $template .= "    TOTAL_CODE_REGION[$nIndex].addr = (kal_uint32)&Image\$\$$exeRegion\$\$RO\$\$Base;\n";
            $template .= "    TOTAL_CODE_REGION[$nIndex].len = custom_get_2nd_ROM_ROMLength();\n" ;
            $nIndex++;
        }
    }
    
    #for common execution regions
    my @nonCodeGroup = qw(DYNAMIC_DNC DYNAMIC_DC NONCACHED_RW CACHED_RW MCU_C_DSP_NC MCU_NC_DSP_C MCU_NC_DSP_NC);
    my $nonCodeGroupRegions_ref = &GetSpecialGroupRegions(\@nonCodeGroup);
    my %nonCodeGroupRegions;
    my $idx = 0;
    map{$nonCodeGroupRegions{$_} = $idx++} @$nonCodeGroupRegions_ref;
    map {print "[get_all_code_addr_info]$_: $nonCodeGroupRegions{$_}\n"} keys %nonCodeGroupRegions if($DebugPrint);

    foreach my $strExeRegionName (@$ExeRegion_ref)
    {
        #bypass obvious none-code regions 
        next if($strExeRegionName ne "SINGLE_BANK_CODE" && exists $nonCodeGroupRegions{$strExeRegionName}); #why SINGLE_BANK_CODE is belongs to NONCACHED_RW group??
        #bypass obvious none-code regions 
        next if($strExeRegionName =~ /VIVA|GFH$|^INTSRAM_DATA|SIGNATURE_SECTION$|LANG_PACK|CUSTPACK|DUMMY_END|EXTSRAM_TMP_PAGE_TABLE|EMPTYSECTION$|^jblend_ram$/); 
        #ROM/DCM regions will be handled especially
        next if($strExeRegionName =~ /^ROM|SECONDARY_ROM|DYNAMIC_COMP/);
        #all secure regions don't have RO-CODE
        next if($strExeRegionName =~ /SECURE|FLASHTOOL_CFG|CUST_PARA|BOOT_CERT|^CBR$/);
        #none Image$$DUMP_VECTOR_TABLE$$Base
        next if($strExeRegionName eq "DUMP_VECTOR_TABLE");
        $template .= "    TOTAL_CODE_REGION[$nIndex].addr = (kal_uint32)&Image\$\$$strExeRegionName\$\$RO\$\$Base;\n";
        $template .= "    TOTAL_CODE_REGION[$nIndex].len = (kal_uint32)&Image\$\$$strExeRegionName\$\$RO\$\$Length;\n";
        $nIndex++;
    }

    #for Vector table
    {
       $template .= "    TOTAL_CODE_REGION[$nIndex].addr = 0x0;\n";
       $template .= "    TOTAL_CODE_REGION[$nIndex].len = 0x200;\n";
       $nIndex++;  
    }
    
    #for DCM 
    {
        my $GroupedRegion_ref = &GetGroupedRegions("DCM");           
        foreach (@$GroupedRegion_ref) #[[], [], []]
        {
            my $array_ref = $_;
            my $strLength = undef;
            my $LastRegionName = $array_ref->[ scalar(@$array_ref)-1 ];
            my $FirstRegionName = $array_ref->[0];
            my $LastDCMInfo = $g_MAUIScat->GetExeRegionInfo($LastRegionName);
            my $strLength = "(kal_uint32)&Image\$\$$LastRegionName\$\$RO\$\$Base + ".$LastDCMInfo->[Region::MaxSize]." - TOTAL_CODE_REGION\[$nIndex].addr";
            $template .= "    TOTAL_CODE_REGION[$nIndex].addr = (kal_uint32)&Image\$\$$FirstRegionName\$\$RO\$\$Base;\n";
            $template .= "    TOTAL_CODE_REGION[$nIndex].len = $strLength;\n";
            $nIndex++;  
        }
    }
    
    return ($template,$nIndex);
}
sub SCAT_C_Gen_TS_REGION_SYMBOL
{
    my $template;
    my $ExeRegion_ref = $g_TinyScat->GetAllExeRegion();
    foreach (@$ExeRegion_ref)
    {
        $template .= "extern kal_uint32 Image\$\$$_\$\$Base;\n";
        $template .= "extern kal_uint32 Image\$\$$_\$\$Length;\n";
        $template .= "extern kal_uint32 Image\$\$$_\$\$ZI\$\$Limit;\n";
    }
    foreach my $i (1 .. $g_TinyScat->{LoadRegionCount})
    {
        my $LoadRegionName = $g_TinyScat->{LoadRegion}{$i}->[0];
        $template .= "extern kal_uint32 Load\$\$$LoadRegionName\$\$Base;\n";
    }
    
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_TINYSYS_ROM1_ON_FLASH
{
    ###this address and length tell tiny loader where to find tiny image on flash
    my ($template,$strBase) = (undef,undef); 
    if(exists $MAKEFILE_OPTIONS{'TINY_SYS'} 
        and $MAKEFILE_OPTIONS{'TINY_SYS'} eq 'TRUE')
    {
        my $arr_ref = $g_MAUIScat->GetLoadRegionInfo("TS_ROM1");
        $strBase = $arr_ref->[Region::Base];
    }
    $template = &get_tiny_region_info_template($strBase);
    return $template;
}
      
sub SCAT_C_Gen_TEMPLATE_TINYSYS_ROM2_ON_FLASH
{
    ###this address and length tell tiny loader where to find tiny image on flash
    my ($template,$strBase) = (undef,undef); 
    if(exists $MAKEFILE_OPTIONS{'TINY_SYS'} 
        and $MAKEFILE_OPTIONS{'TINY_SYS'} eq 'TRUE')
    {
        my $arr_ref = $g_MAUIScat->GetLoadRegionInfo("TS_ROM2");
        $strBase = $arr_ref->[Region::Base];
    }
    
    $template = &get_tiny_region_info_template($strBase);
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_TINYSYS_ROM1_LV_INFO
{
    ### This addr and length  tells tiny_loader  where to find tiny image LV infomation
    my ($template,$strBase) = (undef,undef); 
    if(exists $MAKEFILE_OPTIONS{'TINY_SYS'} 
       and $MAKEFILE_OPTIONS{'TINY_SYS'} eq 'TRUE')
    {
    	my $arr_ref = $g_TinyScat->GetLoadRegionInfo("TINYSYS_ROM1");
        $strBase = $arr_ref->[Region::Base];
    }
    $template = &get_tiny_region_info_template($strBase);
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_TINYSYS_ROM2_LV_INFO
{
    ### This addr and length  tells tiny_loader  where to find tiny image LV infomation 
    my ($template,$strBase) = (undef,undef,undef); 
    if(exists $MAKEFILE_OPTIONS{'TINY_SYS'} 
        and $MAKEFILE_OPTIONS{'TINY_SYS'} eq 'TRUE')
    {
        my $arr_ref = $g_TinyScat->GetLoadRegionInfo("TINYSYS_ROM2");
        $strBase = $arr_ref->[Region::Base];
    }
    
    $template = &get_tiny_region_info_template($strBase);
    return $template;
}
sub get_tiny_region_info_template
{
    my ($strBase) = @_;
    my $template;
    $template = <<"__TEMPLATE";
    *pBase = (kal_uint32)$strBase;
__TEMPLATE

    $template .= ($strBase)? '    return KAL_TRUE;' : '    return KAL_FALSE;';
    return $template;
}

sub SCAT_H_Gen_TS_DUMP_REGION_COUNT
{
    my $nCount = 0;
    if(exists $MAKEFILE_OPTIONS{'TINY_SYS'} 
    and $MAKEFILE_OPTIONS{'TINY_SYS'} eq 'TRUE')
    {
        if(!defined $ts_DumpRegions_ref)
        {
            $ts_DumpRegions_ref = $g_TinyScat->ts_GetDumpExeRegions();
        }
        foreach my $strGroupName (keys %$ts_DumpRegions_ref)
        {
            my $array_ref = $ts_DumpRegions_ref->{$strGroupName};
            $nCount += ($#$array_ref +1);
        }
    }

    return $nCount;
}
sub SCAT_C_Gen_TS_TEMPLATE_DUMP_REGION_ASSIGN
{
    my $template;
    if(exists $MAKEFILE_OPTIONS{'TINY_SYS'} 
    and $MAKEFILE_OPTIONS{'TINY_SYS'} eq 'TRUE')
    {
        my $DumpRegions_ref = &ts_Get_Dump_Regions();
        for(my $i = 0; $i < $#$DumpRegions_ref+1; $i++)
        {
            my $GroupName = $DumpRegions_ref->[$i]->[0];
            $template .= "    region[$i].addr = ".$DumpRegions_ref->[$i]->[1].";\n";
            $template .= "    region[$i].len = ".$DumpRegions_ref->[$i]->[2].";\n";
        }
    }

    return $template;
}
sub ts_Get_Dump_Regions
{
    my @DumpRegions;
    if(!defined $ts_DumpRegions_ref)
    {
        $ts_DumpRegions_ref = $g_TinyScat->ts_GetDumpExeRegions();
    }
    my $nIndex = 0;
    foreach my $strGroupName (%$ts_DumpRegions_ref)
    {
        my $array_ref = $ts_DumpRegions_ref->{$strGroupName};
        foreach my $RegionItem (@$array_ref)
        {
            my $RegionName = $RegionItem->[0];
            my $Info = $g_TinyScat->GetExeRegionInfo($RegionName);
            my $LastRegionName =  $RegionItem->[ scalar(@$RegionItem)-1 ];
            my $strLength = "(kal_uint32)&Image\$\$$LastRegionName\$\$ZI\$\$Limit - region\[$nIndex\].addr";
            print "[$strGroupName]$RegionName: (kal_uint32)&Image\$\$$RegionName\$\$Base, $strLength\n" if($DebugPrint);
            push(@DumpRegions, [$strGroupName, "(kal_uint32)&Image\$\$$RegionName\$\$Base", $strLength]); 
            $nIndex++; next;
        }
    }
    return \@DumpRegions; #[[GroupName, Base, Length]...]
}
