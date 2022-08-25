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
#*   ckImgSize.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*
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
#* 01 29 2013 amber.su
#* [MAUI_03323612] [MT6260C DEV][ALICE] Phase in NAND booting support
#* .
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#*****************************************************************************

#*****************************************************************************
# Included Modules
#*****************************************************************************
BEGIN { push @INC, '.\\tools\\' }  # add additional library path             
use vivaHelper; #for viva
use File::stat;
use FileInfoParser;
use LISInfo;
use config_MemSegment;
use tools::pack_dep_gen;

PrintDependModule();
#*************************************************************************************************
# Input and Parameters Initialization
#*************************************************************************************************
my ($makefile, $bin_folder, $lisfile, $flash_cfg_c,$custom_featureconfig_h) = @ARGV;
my %MAKEFILE_OPTIONS;

my $VIVA_FILE = "$bin_folder\\VIVA";
my $fs_base_addr;
my $actual_size;

my %FEATURE_CONFIG_Value;
my @MBA_ckRegion = qw(LANG_PACK_ROM CUSTPACK_ROM);
my %MBA_Regionsize ;

my $ckfail_cnt = 0;
my $debug = 0;
my $sperate_line = "============================================================\n";
#*************************************************************************************************
# Main Flow
#*************************************************************************************************
&error_handler("$makefile: NOT exist!", __FILE__, __LINE__) if (!-e $makefile);
if(!&vivaHelper::IsVIEnabled_NI($makefile)) {
  print "skip check memory size without enable VIVA\n";
  exit 0;
}

#parse makefile for LISInfo::CheckROMSize
if(1!=&FileInfo::Parse_MAKEFILE($makefile, \%MAKEFILE_OPTIONS)){
   &error_handler("Parse MakeFile failed");
}

if (exists $MAKEFILE_OPTIONS{'DUMMY_SCATTER_ENABLE'} and $MAKEFILE_OPTIONS{'DUMMY_SCATTER_ENABLE'} eq 'TRUE'){
  print "skip check memory size with DUMMY_SCATTER_ENABLE=TRUE\n";
  exit 0;
}

&error_handler("$VIVA_FILE: NOT exist!", __FILE__, __LINE__) if (!-e $VIVA_FILE);
my $VIVA_BIN_SIZE = stat("$VIVA_FILE")->size;
print "The VIVA bin size = $VIVA_BIN_SIZE\n";
#parse lis for LISInfo::CheckROMSize
&LISInfo::ParseLIS($lisfile);

my ($load_end,$check_fsbase) = &LISInfo::CheckMemoryExpired(\%MAKEFILE_OPTIONS,$VIVA_BIN_SIZE);

if($check_fsbase eq undef) {
  &error_handler("Call getFlashBaseAdd Failed!", __FILE__, __LINE__) if(1!=&getFlashBaseAdd);
  &checkSize("VIVA","The Boundary of VIVA bin","Actual VIVA End Address",$fs_base_addr,$load_end);
} else {
  &checkSize("VIVA","The Boundary of VIVA bin","Actual VIVA End Address",$check_fsbase,$load_end);
}

if (exists $MAKEFILE_OPTIONS{'MULTIPLE_BINARY_FILES'} and $MAKEFILE_OPTIONS{'MULTIPLE_BINARY_FILES'} eq 'TRUE'){
  &parse_customFeatureConfig($custom_featureconfig_h, \%FEATURE_CONFIG_Value);

  foreach my $region (@MBA_ckRegion) {
    if(!-e "$bin_folder\\$region"){
      $MBA_Regionsize{"$region"} = undef;
      next;
    }
    my $bin_config_value = &memConfig::Get_bin_comp_value(\%FEATURE_CONFIG_Value,$region);
    my $bin_actual_size = stat("$bin_folder\\$region")->size;
    $MBA_Regionsize{"$region"} = "$bin_actual_size";
    if($bin_config_value eq undef){
      &skip_info("$region","$region bin file");
    } else {
      &checkSize("$region","The Max Compressed Size of $region bin","Actual $region bin Size",$bin_config_value,$bin_actual_size);
    }
  }
  my ($MBA_end, $JUMP_base) = &LISInfo::GET_MBA_boundary(\%MAKEFILE_OPTIONS, \%FEATURE_CONFIG_Value, $MBA_Regionsize{"LANG_PACK_ROM"}, $MBA_Regionsize{"CUSTPACK_ROM"});
  if(($MBA_end eq undef) or ($JUMP_base eq undef)){
    &skip_info("MBA","the region before JUMP_TALBE region");
  } else{
    &checkSize("MBA","The Boundary of MBA bin","Actual MBA End Address",$JUMP_base,$MBA_end);
  }
}

if($ckfail_cnt){
  print "[Summary]\n";
  print "Error: Totally $ckfail_cnt image files got failure for checking image size!\n";
  exit 1;
}

exit 0;

#**************************************************************************************************
# Check Whether Total Image Files Size Overlap Limit or not
#**************************************************************************************************
sub checkSize {
  my($ckname,$limit_str,$actual_str,$max_compressed,$total_size )= @_;
  $left = $max_compressed-$total_size;
  print "[Check $ckname bin size]\n";  
  
  print sprintf ("%-40s %-10s %s\n","$limit_str","= $max_compressed","bytes");
  print sprintf ("%-40s %-10s %s\n","$actual_str","= $total_size","bytes");
  print "$sperate_line\Check $ckname Compressed ROM Size:";
  if ($left < 0)
  {
    # Note: The error pattern will be parsed by tools\auto_adjust_mem.pl
    # Pattern /Check .+ Compressed ROM Size: FAIL/
    $temp = "$actual_str has exceeded $limit_str by " .abs($left)." bytes";
    print " FAIL!\n";
    print STDERR "Error: $temp\n";
    print "Error: $temp.\n\n";
    $ckfail_cnt ++;
  }
  else
  {
    print(" PASS!\n\n");
  }
}

#**************************************************************************************************
# Parse ~flash_cfg_temp_c to Get Flash Base Address
#**************************************************************************************************
sub getFlashBaseAdd {
  my $ckresult = 0;
  &error_handler("$flash_cfg_c: NOT exist!", __FILE__, __LINE__) if (!-e $flash_cfg_c);
  open (FILE_HANDLE, "<$flash_cfg_c") or &error_handler("$flash_cfg_c: file error!", __FILE__, __LINE__);
  while (<FILE_HANDLE>) 
  {
    if (/int flash_base_address\s+=\s+((\S|\s)+);/) 
    {
      $fs_base_addr = eval($1);
      $ckresult = 1;
    }
  }
  close (FILE_HANDLE);
  print "The base address of file system = $fs_base_addr\n";
  return $ckresult;
}

#**************************************************************************************************
# Parse custom_FeatureConfig.h
#**************************************************************************************************
sub parse_customFeatureConfig{
  my ($file, $file_href) = @_;
  open (FILE, "<$file") or &error_handler("$file: file error!", __FILE__, __LINE__);
  while (<FILE>) 
  {
    if (/^#define\s+(\w+)\s+\((\w*)\)/ || /^#define\s+(\w+)\s+(\w*)/)
    {
      my $option = $1;
      my $value  = $2;
      &error_handler("$custom_featureconfig_h: $option redefined in custom_FeatureConfig.h!", __FILE__, __LINE__) if defined($FEATURE_CONFIG_Value{$option});
      if (!defined $value)
      {
        $FEATURE_CONFIG_Value{$option} = 'TRUE';
        $file_href->{$option} = 'TRUE';
      }
      else
      {
        $FEATURE_CONFIG_Value{$option} = $value;
        $file_href->{$option} = $value;
      }
    }
  }
  close (FILE);
}
#*************************************************************************************************
# Error Handling Message
#*************************************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no) = @_;
    my $final_error_msg = "Error: $error_msg at $file line $line_no\n";
    print "$final_error_msg";
    exit 1;
}
#*************************************************************************************************
# Print Message for skip information
#*************************************************************************************************
sub skip_info{
  my ($reg,$reg_base) = @_;
  print "[Skip to check $reg bin size] $reg_base is uncompressed\n\n";
}
