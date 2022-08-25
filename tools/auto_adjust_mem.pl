#!/usr/bin/perl
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
#
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   auto_adjust_mem.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   1. This script will read link error and decide to enter two-phase linking
#*   2. If need, it will calculate recommand memory configuration value.
#*   3. If turn on *_AUTO_CONFIG option, it will triger two-phase linking.
#*
#* Author:
#* -------
#*   Amber Su  (mtk03389)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#*
#* 02 06 2013 amber.su
#* [MAUI_03332013] [SWPL Approved] Phase in DCM_COMPRESSION auto-configuration
#* .
#*
#* 02 06 2013 amber.su
#* [MAUI_03332013] [SWPL Approved] Phase in DCM_COMPRESSION auto-configuration
#* .
#*
#* 12 26 2012 amber.su
#* [MAUI_03299193] [SystemService][Auto-Gen][Internal Refinement] Refine BLReservedSize_AutoConfig.pl protential bug
#* .
#* 
#* 10 18 2012 amber.su
#* [MAUI_03241322] [ZIMAGE] Phase in ZIMAGE_CONTENT_POLICY and phase out ZIMAGE_FAVOR_ROM
#* .
#* 
#* 07 26 2012 amber.su
#* [MAUI_03216330] [Target Build] add dependency check for DUMMY_SCATTER_ENABLE
#* .
#*  V0, two phase linking process with ZIMAGE_AUTO_CONFIG
#*  V1, two phase linking process with DEMAND_PAGING_AUTO_CONFIG
#*  V2, parse all regions for link error for AAPMC on DP and MBA support
#*  V3, support auto checkin mechanism
#*  V4, two phase linking process with FILE_SYSTEM_AUTO_CONFIG
#*  V5, phase-in ALICE, and combine it with ZIMAGE prcessing
#*  V6, two phase linking process with BOOTLOADER
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************
#use strict;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use auto_adjust_mem; #pm file name without case sensitivity/for AAPMC
use vivaHelper; #for viva

#*************************************************************************************************
# Input and Parameters initialization
#*************************************************************************************************
my $LEVEL = $ARGV[0];
shift(@ARGV);
my $DEBUG = 1;
my $sperate_line = "====================================================================\n";

my $AAPMC_LOG = "AAPMC.log";
#*************************************************************************************************
# Main Flow
# >> LEVEL 1. Check link error pattern to decide whether enter to two-phase linking
# >> LEVEL 2. Calculate correct value to decide whether link error can be resolved with adjusted 
#             memory configuration value
#*************************************************************************************************
if($LEVEL == 1) {
  my $CURRENT_FLAG = $ARGV[0];
  shift(@ARGV);
  my $MAKEFILE = $ARGV[0];
  shift(@ARGV);
  
  my $LINK_ERR = 0;
  
  &error_handler("File: $MAKEFILE did NOT exist!", __FILE__, __LINE__) if (!-e $MAKEFILE);
  open (FILE_HANDLE, "<$MAKEFILE") or &error_handler("cannot open $MAKEFILE!", __FILE__, __LINE__);
  while (<FILE_HANDLE>) {
    if ((/^([^\#]*)\#?.*/) && ($1 =~ /^(\w+)\s*=\s*(.*\S)\s*$/)) {
      $keyname = lc($1);
      $${keyname} = uc($2);
    }
  }
  close FILE_HANDLE;
  
  system("del /q /f make\\~VIVA_LinkError.tmp > nul")if(-e "make\\~VIVA_LinkError.tmp");
  system("del /q /f make\\~DP_LinkError.tmp > nul")if(-e "make\\~DP_LinkError.tmp");
  system("del /q /f make\\~FS_LinkError.tmp > nul")if(-e "make\\~FS_LinkError.tmp");
  system("del /q /f make\\~FS_LinkError_BBU.tmp > nul")if(-e "make\\~FS_LinkError_BBU.tmp");
  system("del /q /f make\\~BL_LinkError.tmp > nul")if(-e "make\\~BL_LinkError.tmp");

  print "[Check any error related two-phase linking...]\n" if($DEBUG);
  if($CURRENT_FLAG eq "-bl")
  {
    ($BL_LINKLOG,$BL_EXT_LINKLOG) = @ARGV;

    if($BL_LINKLOG =~ /(.+)\\(.+)/) {
      $TARGDIR = $1;
      $bllogname = $2;
    }
    if($BL_EXT_LINKLOG =~ /(.+)\\(.+)/) {
      $blextlogname = $2;
    }

    if(((defined $nand_flash_booting) && ($nand_flash_booting eq "NONE"))&& ((defined $emmc_booting) && ($emmc_booting eq "NONE"))) {
      $LINK_ERR = &ckBLLinkError;
    }
  }
  elsif($CURRENT_FLAG eq "-maui")
  {
    ($LINKLOG,$ckImgSize,$ckSYSDRV_LOG,$ckBBU_LOG,$SYS_PATH,$FLASH_CFG,$FSUSAGE_LOG,$NVRAMID_LOG,$FEATURE_OVER,$SYSDRV,$NVRAM_PSEUDO,$PROJECT_NAME) = @ARGV;
    my $DP_LINK_ERR = 0;

    # delete debug folder and intermed. file
    # >> debug folder pattern: xxx_DEBUG
    #    -- it will be removed in backup action in gsm2.mak
    # >> intermed. file pattern: xxx_LinkError.tmp
    if($LINKLOG =~ /(.+)\\(.+)/) {
      $TARGDIR = $1;
      $logname = $2;
    }
    if($ckImgSize =~ /(.+)\\(.+)/) {
      $LogFolder = $1;
    }
        
    if(((defined $nand_flash_booting) && ($nand_flash_booting eq "NONE"))&& ((defined $emmc_booting) && ($emmc_booting eq "NONE"))) {
      $SYSDRV_ERR = &cksysdrvError;
      $FS_LINK_ERR = &ckLinkError;
      if(&vivaHelper::IsVIEnabled_NI($MAKEFILE)) {
        $VIVA_LINK_ERR = &ckVivaError;
      } 
      if($SYSDRV_ERR && !$FS_LINK_ERR) {
        #enlarge FS
        $LINK_ERR = 1;
      } elsif($FS_LINK_ERR||$VIVA_LINK_ERR){
        #shirk FS or adjust VIVA config
        $LINK_ERR = 1;
      } elsif($BL_LINK_ERR){
        # for bootloader
        $LINK_ERR = 1;
      }
    } else{
    
      if(((defined $nand_flash_booting) && ($nand_flash_booting eq "ONDEMAND"))||((defined $emmc_booting) && ($emmc_booting eq "ONDEMAND"))) {
        $DP_LINK_ERR = &ckDemandPagingError;
      }
      if($DP_LINK_ERR) {
        #adjust DP or MBA config
        $LINK_ERR = 1;
      } else{
         $SYSDRV_ERR = &cksysdrvError;
         $BBU_ERR = &ckBinBlockUasgeError;
         if($SYSDRV_ERR && -e $ckBBU_LOG){
           #adjust FS(enlarge/shrink)
           $LINK_ERR = 1;
           system("copy /y make\\~FS_LinkError.tmp make\\~FS_LinkError_BBU.tmp  > nul");
         } elsif(!$SYSDRV_ERR && $BBU_ERR){
           #shrink FS
           $LINK_ERR = 1;
           system("copy /y make\\~FS_LinkError.tmp make\\~FS_LinkError_BBU.tmp  > nul");
         }
      }
    }
    print "LEVEL = $LEVEL\n";
    #if occur link error, adjust FS first. If shirk FS failed, it will adjust VIVA directly.
    if(-e "make\\~FS_LinkError.tmp" && -e "make\\~VIVA_LinkError.tmp"){
      system("copy /y make\\~FS_LinkError.tmp make\\~FS_LinkError.ori.tmp > nul");
      print "perl tools\\cksysdrv.pl $FLASH_CFG $FSUSAGE_LOG $NVRAMID_LOG $FEATURE_OVER $SYSDRV $NVRAM_PSEUDO $SYS_PATH make\\~FS_LinkError.tmp $PROJECT_NAME AAPMC_temp.log> $LogFolder\\FileSystemConfig.log 2>&1\n" if($DEBUG);
      $out_str = "Calculating correct File System value...";
      $result = system("perl tools\\cksysdrv.pl $FLASH_CFG $FSUSAGE_LOG $NVRAMID_LOG $FEATURE_OVER $SYSDRV $NVRAM_PSEUDO $SYS_PATH make\\~FS_LinkError.tmp $PROJECT_NAME AAPMC_temp.log >> $LogFolder\\FileSystemConfig.log 2>&1") ;
      $result_temp = $result >> 8;
      print "Result = $result_temp\n";
      system("move /Y make\\~FS_LinkError.ori.tmp make\\~FS_LinkError.tmp > nul");
      system("del /q /f AAPMC_temp.log > nul")if(-e "AAPMC_temp.log");
      if(($result>>8) == ERR::CANNOT_ADJUST or ($result>>8) == ERR::NO_MODIFY or ($result>>8) == ERR::NO_MORE_SPACE) {
        system("rd /S /Q $TARGDIR\\FILE_SYSTEM_DEBUG > nul") if(-d "$TARGDIR\\FILE_SYSTEM_DEBUG");
        system("del /q /f make\\~FS_LinkError.tmp > nul")if(-e "make\\~FS_LinkError.tmp");
      } else {
        system("rd /S /Q $TARGDIR\\VIVA_DEBUG > nul") if(-d "$TARGDIR\\VIVA_DEBUG");
        system("del /q /f make\\~VIVA_LinkError.tmp > nul")if(-e "make\\~VIVA_LinkError.tmp");
      }
    }

  }
  
  if($LINK_ERR) {
    print "Need to enter two-phase linking process.\n" if($DEBUG);   
    exit 1;
  } else{
    print "Do not need to enter two-phase linking process.\n\n" if($DEBUG);    
    exit 0;
  }
}
elsif($LEVEL == 2) {
  my ($TARGDIR, $LIS_FILE,$BL_LIS_FILE,$BL_EXT_LIS_FILE,$SYS_PATH,$MAKEFILE,$LogFolder,$BIN_FOLDER,$FLASH_CFG,$PROJECT_NAME,$FSUSAGE_LOG,$NVRAMID_LOG,$FEATURE_OVER,$SYSDRV,$NVRAM_PSEUDO,$INSIDE_MTK,$SCATTER_FILE) = @ARGV;
  &error_handler("Folder: $SYS_PATH did NOT exist!", __FILE__, __LINE__) if (!-d $SYS_PATH);
  
  my $out_str = "";
  my $remd_str = "";
  my $result;
  
  my $Status = 0;
  
  my $LIS_FILE_PTH = "$TARGDIR\\$LIS_FILE";
  my $BL_LIS_FILE_PTH = "$TARGDIR\\$BL_LIS_FILE";
  my $BLEXT_LIS_FILE_PTH = "$TARGDIR\\$BL_EXT_LIS_FILE";
  print "LEVEL = $LEVEL\n";
  if(-e "make\\~VIVA_LinkError.tmp") {
    &error_handler("File: $LIS_FILE_PTH did NOT exist!", __FILE__, __LINE__) if(!-e $LIS_FILE_PTH);
    &error_handler("Folder: $BIN_FOLDER did NOT exist!", __FILE__, __LINE__) if (!-d $BIN_FOLDER);
    &error_handler("Folder: $SYS_PATH did NOT exist!", __FILE__, __LINE__) if (!-d $SYS_PATH);
    &error_handler("File: $MAKEFILE did NOT exist!", __FILE__, __LINE__) if (!-e $MAKEFILE);
    #re-calculate CONFIG_ALICE_DECOMPRESSED_SIZE and CONFIG_ALICE_MAX_COMPRESSED_SIZE size
    print "perl tools\\vivaConfig.pl $LIS_FILE $BIN_FOLDER $SYS_PATH $MAKEFILE $FLASH_CFG make\\~VIVA_LinkError.tmp $AAPMC_LOG \"$INSIDE_MTK\" > $LogFolder\\vivaConfig.log 2>&1\n" if($DEBUG);
    $out_str = "Calculating correct VIVA memory value...";
    $result = system("perl tools\\vivaConfig.pl $LIS_FILE_PTH $BIN_FOLDER $SYS_PATH $MAKEFILE $FLASH_CFG make\\~VIVA_LinkError.tmp $AAPMC_LOG \"$INSIDE_MTK\" > $LogFolder\\vivaConfig.log 2>&1") ;
    $remd_str = &getRecomdValue("make\\~VIVA_LinkError.tmp");
    $check_scrip = "vivaConfig";
  } elsif (-e "make\\~DP_LinkError.tmp") {
    &error_handler("File: $LIS_FILE_PTH did NOT exist!", __FILE__, __LINE__) if (!-e $LIS_FILE_PTH);
    #re-calculate MAX BIN size for DP and MBA
    print "perl tools\\DemandPagingConfig.pl $LIS_FILE_PTH $SYS_PATH $MAKEFILE make\\~DP_LinkError.tmp $PROJECT_NAME $AAPMC_LOG> $LogFolder\\DemandPagingConfig.log 2>&1\n" if($DEBUG);
    $out_str = "Calculating correct MAX BIN SIZE value...";
    $result = system("perl tools\\DemandPagingConfig.pl $LIS_FILE_PTH $SYS_PATH $MAKEFILE make\\~DP_LinkError.tmp $PROJECT_NAME $AAPMC_LOG> $LogFolder\\DemandPagingConfig.log 2>&1") ;
    $remd_str = &getRecomdValue("make\\~DP_LinkError.tmp");
    $check_scrip = "DemandPagingConfig";
  } elsif (-e "make\\~FS_LinkError.tmp") {
    #re-calculate FS size
    print "perl tools\\cksysdrv.pl $FLASH_CFG $FSUSAGE_LOG $NVRAMID_LOG $FEATURE_OVER $SYSDRV $NVRAM_PSEUDO $SYS_PATH make\\~FS_LinkError.tmp $PROJECT_NAME $AAPMC_LOG> $LogFolder\\FileSystemConfig.log 2>&1\n" if($DEBUG);
    $out_str = "Calculating correct File System value...";
    $result = system("perl tools\\cksysdrv.pl $FLASH_CFG $FSUSAGE_LOG $NVRAMID_LOG $FEATURE_OVER $SYSDRV $NVRAM_PSEUDO $SYS_PATH make\\~FS_LinkError.tmp $PROJECT_NAME $AAPMC_LOG >> $LogFolder\\FileSystemConfig.log 2>&1") ;
    $remd_str = &getRecomdValue("make\\~FS_LinkError.tmp");
    $check_scrip = "FileSystemConfig";
  } elsif (-e "make\\~BL_LinkError.tmp") {
    &error_handler("File: $BL_LIS_FILE_PTH did NOT exist!", __FILE__, __LINE__) if(!-e $BL_LIS_FILE_PTH);
    &error_handler("File: $BLEXT_LIS_FILE_PTH did NOT exist!", __FILE__, __LINE__) if(!-e $BLEXT_LIS_FILE_PTH);
    &error_handler("Folder: $SYS_PATH did NOT exist!", __FILE__, __LINE__) if (!-d $SYS_PATH);
    &error_handler("File: $MAKEFILE did NOT exist!", __FILE__, __LINE__) if (!-e $MAKEFILE);
    #re-calculate bootloader size
    print "perl tools\\BLReservedSize_AutoConfig.pl $BL_LIS_FILE_PTH $BLEXT_LIS_FILE_PTH $SYS_PATH $MAKEFILE make\\~BL_LinkError.tmp $PROJECT_NAME $AAPMC_LOG $SCATTER_FILE> $LogFolder\\BLReservedSizeConfig.log 2>&1\n" if($DEBUG);
    $out_str = "Calculating correct Bootloader value...";
    $result = system("perl tools\\BLReservedSize_AutoConfig.pl $BL_LIS_FILE_PTH $BLEXT_LIS_FILE_PTH  $SYS_PATH $MAKEFILE make\\~BL_LinkError.tmp $PROJECT_NAME $AAPMC_LOG $SCATTER_FILE > $LogFolder\\BLReservedSizeConfig.log 2>&1") ;
    $remd_str = &getRecomdValue("make\\~BL_LinkError.tmp");
    $check_scrip = "BLReservedSize_AutoConfig";
  } else {
    die "lack of log file to enter two-phase linking process\n";
  }
  # die error code: 2304 >> 9
  $check_log = "$LogFolder\\$check_scrip.log";
  if(($result>>8) == ERR::NO_MODIFY) { # NO_MODIFY: recommand a value but not modify custom_featureConfig.h || scatter file is checkin by human
    $out_str .= "Done.\nPlease adjust memory configuration manually and refer to $check_log\n";
    $out_str .= "$sperate_line$remd_str$sperate_line";
  } elsif (($result>>8) == ERR::AAPMCLOG_SUCCESS) { # AAPMCLOG_SUCCESS: recommand a value and write to AAMPC.log
    if(ERR::AAPMCLOG_SUCCESS == &AAPMCLogParser::Open($AAPMC_LOG)) {
        my $IndexArray_ref = &AAPMCLogParser::GetAllRecordsIndex();
        foreach my $i (@$IndexArray_ref) {
            my $ChangeRecord_ref = &AAPMCLogParser::GetByIndex($i, AAPMCLogParser::RECORD);
            $Status += &AUTO_ADJUST::ModifyByChangeRecord(".\\", $ChangeRecord_ref, 1);
        }
        $closevalue = &AAPMCLogParser::Close($AAPMC_LOG);
        if($closevalue == ERR::AAPMCLOG_SUCCESS){
          if($Status == ERR::ERR_MODIFYFAIL) {
            $out_str .= "Failed.\nAll memory configurations are unchange. It cannot apply two-phase linking process. Please check link error\n" 
          } else {
            # The pattern "The adjustment of memory configuration is done and refer to $check_log" will be parsed by auto-notify
            $out_str .= "Done.\nThe adjustment of memory configuration is done and refer to $check_log\n";
            $out_str .= "$sperate_line$remd_str$sperate_line";
          }
        } else {
          &error_handler("cannot close $AAPMC_LOG!", __FILE__, __LINE__);
        }
    }else {
        &error_handler("cannot open $AAPMC_LOG!", __FILE__, __LINE__);
    }
  } elsif (($result>>8) == ERR::AUTOCONFIG_SELF_MODIFY_SUCCESS) { # AUTOCONFIG_SELF_MODIFY_SUCCESS: skip AAPMC operation and treat it as AAPMCLOG_SUCCESS
    # The pattern "The adjustment of memory configuration is done and refer to $check_log" will be parsed by auto-notify
    $out_str .= "Done.\nThe adjustment of memory configuration is done and refer to $check_log\n";
    $out_str .= "$sperate_line$remd_str$sperate_line";
  } elsif (($result>>8) == ERR::NO_NEED_TO_UPDATE) { # NO_NEED_TO_UPDATE: skip AAPMC operation and treat it as AAPMCLOG_SUCCESS
    # The pattern "The adjustment of memory configuration is done and refer to $check_log" will be parsed by auto-notify
    $out_str .= "Done.\nDo not need to adjust memory configuration and refer to $check_log\n";
    #$out_str .= "$sperate_line$remd_str$sperate_line";
    
    # Keep going for build flow, but need not to trigger following action for AAPMC (by ~NoAAPMC.tmp)
    if($check_scrip eq "BLReservedSize_AutoConfig"){
      open(TEMPFILE,">make\\~NoAAPMC.tmp") or &error_handler("cannot open make\\~NoAAPMC.tmp!", __FILE__, __LINE__);
      print TEMPFILE ".";
      close TEMPFILE;
    }
  } elsif (($result>>8) == ERR::CANNOT_ADJUST) { # CANT_ADJUST: cannot adjust memory config
    $out_str .= "Failed.\nPlease check link error or check $check_log.\n";
    $out_str .= "$sperate_line$remd_str$sperate_line";
  } elsif (($result>>8) == ERR::ERR_MODIFYDUPLICATED) { # ERR_MODIFYDUPLICATED: cannot modify same memory config more than twice
    $out_str .= "Failed.\nDuplicate memory configuration value are existed. Please check $check_log\n";
  } elsif ((101 <= ($result>>8)) && ( ($result>>8) <= 110)) { # special error code
    $out_str .= "Failed.\nsome errors occured while executing tools\\$check_scrip.pl. Please check $check_log\n";
  } else {
    $out_str .= "Failed.\nsome errors occured while executing tools\\$check_scrip.pl. Please check $check_log\n";
  }
  
  my $return_code = $result>>8;
  if($Status != 0) {
    $return_code .= "-".$Status;
  }
  if((($result>>8) == ERR::AAPMCLOG_SUCCESS && $Status != ERR::ERR_MODIFYFAIL) or
     (($result>>8) == ERR::AUTOCONFIG_SELF_MODIFY_SUCCESS) or
     (($result>>8) == ERR::NO_NEED_TO_UPDATE)) {
    print "Result[$return_code]: $out_str\n";
    print STDERR "Result[$return_code]: $out_str\n";
    if(-e "$LogFolder\\auto_adjust_mem.log" && $check_scrip eq "BLReservedSize_AutoConfig" && ($result>>8) == ERR::NO_NEED_TO_UPDATE){
      system("md $TARGDIR\\BOOTLOADER_DEBUG") if(!-d "$TARGDIR\\BOOTLOADER_DEBUG");
      print STDERR "copy $LogFolder\\auto_adjust_mem.log $TARGDIR\\BOOTLOADER_DEBUG\\auto_adjust_mem.log\n";
      system("copy /y $LogFolder\\auto_adjust_mem.log $TARGDIR\\BOOTLOADER_DEBUG\\auto_adjust_mem.log > nul");
    }
  } else {
    print "AAPMC Error: Error[$return_code] $out_str\n";
    print STDERR "AAPMC Error: Error[$return_code] $out_str";
    system("type $LogFolder\\auto_adjust_mem.log >> $LogFolder\\aapmc_info.log");
    #copy log to XXX_DEBUG folder since if it need not to adjust BL, it will keep going for MAUI build flow.
    if(-e "$LogFolder\\auto_adjust_mem.log" && $check_scrip eq "BLReservedSize_AutoConfig"){
      system("md $TARGDIR\\BOOTLOADER_DEBUG") if(!-d "$TARGDIR\\BOOTLOADER_DEBUG");
      print STDERR "copy $LogFolder\\auto_adjust_mem.log $TARGDIR\\BOOTLOADER_DEBUG\\auto_adjust_mem.log\n";
      system("copy /y $LogFolder\\auto_adjust_mem.log $TARGDIR\\BOOTLOADER_DEBUG\\auto_adjust_mem.log > nul");
    }
    exit 1;
  }
}

#*************************************************************************************************
# Check link error pattern to decide whether enter to two-phase linking
# >> For VIVA case
#*************************************************************************************************
sub ckVivaError{
  my $CK_VIVA_ERR = 0;
  my $err_str = "";
  print "enter to check error for VIVA...\n";
  if(-e $LINKLOG) { 
    open (FILE_HANDLE, $LINKLOG) or die "Cannot open $LINKLOG\n";
    while (<FILE_HANDLE>) {
      if ($_ =~ /Error: (L6220E|L6406W|L6221E|L6388E):/) {
        print "[Link Error] $_" if($DEBUG);
        $err_str .= $_;
        $CK_VIVA_ERR = 1;
        last;
      }
    }
    close FILE_HANDLE; 
    if($CK_VIVA_ERR) {
      system("md $TARGDIR\\VIVA_DEBUG") if(!-d "$TARGDIR\\VIVA_DEBUG");
      system("copy /y $LINKLOG $TARGDIR\\VIVA_DEBUG\\$logname.error > nul");
    }
  }  
  if(!$CK_VIVA_ERR) {
    if(-e $ckImgSize) { 
    open (FILE_HANDLE, $ckImgSize) or &error_handler("cannot open $ckImgSize!", __FILE__, __LINE__);
    while (<FILE_HANDLE>) {
      if ($_ =~ /Check .+ Compressed ROM Size: FAIL/) {
        print "[ckImgSize Error] $_.\n" if($DEBUG);
        $err_str .= $_;
        $CK_VIVA_ERR = 1;
        system("md $TARGDIR\\VIVA_DEBUG") if(!-d "$TARGDIR\\VIVA_DEBUG");
        system("copy /y $ckImgSize $TARGDIR\\VIVA_DEBUG\\ckImgSize.log.error  > nul");
        last;
      }
    }
    close FILE_HANDLE;
    }
  }
  
  if($CK_VIVA_ERR) {
    open(TEMPFILE,">make\\~VIVA_LinkError.tmp") or &error_handler("cannot open make\\~VIVA_LinkError.tmp!", __FILE__, __LINE__);
    print TEMPFILE "$err_str";
    close TEMPFILE;
  }
  return $CK_VIVA_ERR;
}

#*************************************************************************************************
# Check link error pattern to decide whether enter to two-phase linking
# >> For DEMAND_PAGING case
#*************************************************************************************************
sub ckDemandPagingError{
  my $CK_DP_ERR = 0;
  my $link_err_str = "";
  print "enter to check error for Demand Paging...\n";
  if(-e $LINKLOG) { 
    open (FILE_HANDLE, $LINKLOG) or &error_handler("cannot open $LINKLOG!", __FILE__, __LINE__);
    while (<FILE_HANDLE>) {
      if ($_ =~ /Error: L6220E:/) {
        print "[Link Error] $_" if($DEBUG);
        $link_err_str .= $_;
        $CK_DP_ERR = 1;
      }
    }
    close FILE_HANDLE; 
    if($CK_DP_ERR) {
      system("md $TARGDIR\\DEMAND_PAGING_DEBUG") if(!-d "$TARGDIR\\DEMAND_PAGING_DEBUG");
      system("copy /y $LINKLOG $TARGDIR\\DEMAND_PAGING_DEBUG\\$logname.error > nul");
    }
  }
  if($CK_DP_ERR) {
    open(TEMPFILE,">make\\~DP_LinkError.tmp") or &error_handler("cannot open make\\~DP_LinkError.tmp!", __FILE__, __LINE__);
    print TEMPFILE "$link_err_str";
    close TEMPFILE;
  }
  return $CK_DP_ERR;   
}

#*************************************************************************************************
# Check system drive error
# >> For File System
#*************************************************************************************************
sub cksysdrvError{
  my $CK_SYSDRV_ERR = 0;
  my $err_str = "";
  print "enter to check error for system drive...\n";
  if(-e $ckSYSDRV_LOG) { 
    open (FILE_HANDLE, $ckSYSDRV_LOG) or &error_handler("cannot open $ckSYSDRV_LOG!", __FILE__, __LINE__);
    while (<FILE_HANDLE>) {
      if ($_ =~ /Shortage/i) {
        print "[Cksysdrv Error] $_" if($DEBUG);
        $err_str .= $_;
        $CK_SYSDRV_ERR = 1;
      } 
    }
    close FILE_HANDLE; 
    if($CK_SYSDRV_ERR) {
      system("md $TARGDIR\\FILE_SYSTEM_DEBUG") if(!-d "$TARGDIR\\FILE_SYSTEM_DEBUG");
      system("copy /y $ckSYSDRV_LOG $TARGDIR\\FILE_SYSTEM_DEBUG\\ckSysDrv.log.error > nul");
    }
  }
  if($CK_SYSDRV_ERR) {
    open(TEMPFILE,">make\\~FS_LinkError.tmp") or &error_handler("cannot open make\\~FS_LinkError.tmp!", __FILE__, __LINE__);
    print TEMPFILE "$err_str";
    #parse code size in checkbinaryblockusage.log
    if(-e $ckBBU_LOG) { 
      open (FILE_HANDLE, $ckBBU_LOG) or &error_handler("cannot open $ckBBU_LOG!", __FILE__, __LINE__);
      while (<FILE_HANDLE>) {
        if ($_ =~ /BIN size = .+ on NAND Flash/i) {
          print TEMPFILE "[CheckBinaryBlockUsage Info] $_";
        } 
      }
      close FILE_HANDLE;
    }
    close TEMPFILE;
  }
  return $CK_SYSDRV_ERR;
}

#*************************************************************************************************
# Check Binary Block Usage
# >> For bin file will obverlap FAT or not
#*************************************************************************************************
sub ckBinBlockUasgeError{
  my $CK_BBU_ERR = 0;
  my $err_str = "";
  print "enter to check error for binary block usage...\n";
  if(-e $ckBBU_LOG) { 
    open (FILE_HANDLE, $ckBBU_LOG) or &error_handler("cannot open $ckBBU_LOG!", __FILE__, __LINE__);
    while (<FILE_HANDLE>) {
      if ($_ =~ /Error: BIN(.+)overlap/i) {
        print "[CheckBinaryBlockUsage Error] $_" if($DEBUG);
        $err_str .= $_;
        $CK_BBU_ERR = 1;
      }
    }
    close FILE_HANDLE; 
    if($CK_BBU_ERR) {
      system("md $TARGDIR\\FILE_SYSTEM_DEBUG") if(!-d "$TARGDIR\\FILE_SYSTEM_DEBUG");
      system("copy /y $ckBBU_LOG $TARGDIR\\FILE_SYSTEM_DEBUG\\checkBinaryBlockUsage.log.error  > nul");
    }
  }
  if($CK_BBU_ERR) {
    open(TEMPFILE,">>make\\~FS_LinkError.tmp") or &error_handler("cannot open make\\~FS_LinkError.tmp!", __FILE__, __LINE__);
    print TEMPFILE "$err_str";
    close TEMPFILE;
  }
  return $CK_BBU_ERR;
}

#*************************************************************************************************
# Check system drive error
# >> For File System
#*************************************************************************************************
sub ckLinkError{
  my $CK_LK_ERR = 0;
  my $link_err_str = "";
  print "enter to check link error...\n";
  if(-e $LINKLOG) { 
    open (FILE_HANDLE, $LINKLOG) or &error_handler("cannot open $LINKLOG!", __FILE__, __LINE__);
    while (<FILE_HANDLE>) {
      if ($_ =~ /Error: (L6220E):/) {
        print "[Link Error] $_" if($DEBUG);
        $link_err_str .= $_;
        $CK_LK_ERR = 1;
      }
    }
    close FILE_HANDLE;
    if($CK_LK_ERR) {
      system("md $TARGDIR\\FILE_SYSTEM_DEBUG") if(!-d "$TARGDIR\\FILE_SYSTEM_DEBUG");
      system("copy /y $LINKLOG $TARGDIR\\FILE_SYSTEM_DEBUG\\$logname.error > nul");
    }
  }
  if($CK_LK_ERR) {
    open(TEMPFILE,">make\\~FS_LinkError.tmp") or &error_handler("cannot open make\\~FS_LinkError.tmp!", __FILE__, __LINE__);
    print TEMPFILE "$link_err_str";
    close TEMPFILE;
  }
  return $CK_LK_ERR;
}

#*************************************************************************************************
# Check link error
# >> For Bootloader
#*************************************************************************************************
sub ckBLLinkError{
  my $CK_BL_LK_ERR = 0;
  my $BL_LK_ERR = 0;
  my $NEED_CHECK = 0;
  my $link_err_str = "";
  print "enter to check link error for bootloader...\n";
  unlink "$TARGDIR\\BL_LINK.log" if (-e "$TARGDIR\\BL_LINK.log"); 
  if(-e $BL_LINKLOG){
    system("type $BL_LINKLOG >> $TARGDIR\\BL_LINK.log");
  }
  if(-e $BL_EXT_LINKLOG){
    system("type $BL_EXT_LINKLOG >> $TARGDIR\\BL_LINK.log");
  }
  if(-e "$TARGDIR\\BL_LINK.log") { 
    open (FILE_HANDLE, "$TARGDIR\\BL_LINK.log") or &error_handler("cannot open $TARGDIR\\BL_LINK.log!", __FILE__, __LINE__);
    while (<FILE_HANDLE>) {
      if ($_ =~ /Error: (L6220E):/) {
        print "[Link Error] $_" if($DEBUG);
        $link_err_str .= $_;
        $CK_BL_LK_ERR = 1;
      } elsif ($_ =~ /Error:/) {
        $BL_LK_ERR = 1;
      }
    }
    close FILE_HANDLE;
    if($CK_BL_LK_ERR) {
      system("md $TARGDIR\\BOOTLOADER_DEBUG") if(!-d "$TARGDIR\\BOOTLOADER_DEBUG");
      system("copy /y $BL_LINKLOG $TARGDIR\\BOOTLOADER_DEBUG\\$bllogname.error > nul");
      system("copy /y $BL_EXT_LINKLOG $TARGDIR\\BOOTLOADER_DEBUG\\$blextlogname.error > nul");
    }
  }
  unlink "$TARGDIR\\BL_LINK.log" if (-e "$TARGDIR\\BL_LINK.log");
  if(($CK_BL_LK_ERR) or ((!$CK_BL_LK_ERR) && (!$BL_LK_ERR))) {
    $NEED_CHECK = 1;
    print "No link error for bootloader\n" if (!$CK_BL_LK_ERR && $DEBUG);
    open(TEMPFILE,">make\\~BL_LinkError.tmp") or &error_handler("cannot open make\\~BL_LinkError.tmp!", __FILE__, __LINE__);
    print TEMPFILE "$link_err_str";
    close TEMPFILE;
  }
  return $NEED_CHECK;
}

#*************************************************************************************************
# Get recommand value after script calculation
# >> To show in command line
#*************************************************************************************************
sub getRecomdValue{
  $logfile = $_[0];
  my $backup= $/;
  undef $/;
  open B_FLIE,"<$logfile" or &error_handler("cannot open $logfile!", __FILE__, __LINE__);
  my $reading = <B_FLIE>;
  $/ = $backup;
  close B_FLIE;

  return $reading;
}

#*************************************************************************************************
# Error Handling Message
#*************************************************************************************************
sub error_handler
{
   my ($error_msg, $file, $line_no) = @_;
   my $final_error_msg = "ERROR: $error_msg at $file line $line_no\n";
   print $final_error_msg;
   exit 99;
}
