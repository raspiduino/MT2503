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
#*   vivaCalculator.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This file calculates the size information
#*
#*
#* Author:
#* -------
#*   Ke-Ting Chen (mtk03141)
#*
#*****************************************************************************

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
use warnings;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use File::Copy;
use File::Basename;
use vivaHelper;

#****************************************************************************
# History
#****************************************************************************
my $VIVA_CALCULATOR_VERNO = " v1.01";
   # v1.01: Phase in ZIMAGE_CONTENT_POLICY and DCM_COMPRESSION auto-configuration
   # v1.00: Phase in

#****************************************************************************
# Constants
#****************************************************************************
my $DEBUG = 1;

# Binary
my $romBinaryName = "ROM";
my $bootZImageBinaryName = "BOOT_ZIMAGE_ER";
my $zImageBinaryName = "ZIMAGE_ER";
my $dcmcmpBinaryName = "DYNAMIC_COMP_CODE";
my $aliceBinaryName = "ALICE";

# Normal scatter
my $objectROM1ListFileName = "objectROM1.list";
my $objectBootZImageListFileName = "objectBOOT_ZIMAGE.list";
my $objectZImageListFileName = "objectZIMAGE.list";
my $objectAliceListFileName = "objectALICE.list";

# Dummy scatter
my $objectROM1DummyListFileName = "objectROM1_dummy.list";
my $objectBootZImageDummyListFileName = "objectBOOT_ZIMAGE_dummy.list";
my $objectZImageDummyListFileName = "objectZIMAGE_dummy.list";
my $objectAliceDummyListFileName = "objectALICE_dummy.list";
my $objectAliceForbidDummyListFileName = "objectALICE_FORBID_dummy.list";

# Alignment
my $bootZImageSizeAlignment = 256;
my $zImageSizeAlignment = 256;
my $dcmcmpSizeAlignment = 256;
my $aliceSizeAlignment = 256;

my $veneerReserveRatio = 0.05;
my $minVeneerReserveSize = 5120;
my $maxVeneerReserveSize = 102400;
my $smallestSplitableRAMSize = 10240;

my $separateLine = "=============================================================";

use constant CONFIG_FAIL_INSUFFICIENT_RAM => 0;
use constant CONFIG_FAIL_ZIMAGE_OVERFLOW  => 1;
use constant CONFIG_FAIL_FEATURE_NOT_ENABLED => 2;
use constant CONFIG_FAIL_NO_CONFIG_CHANGED => 3;
use constant CONFIG_FAIL_INSUFFICIENT_FLASH_SIZE => 4;
use constant CONFIG_FAIL_INSUFFICIENT_RAM_FOR_BOOT_ZIMAGE => 5;
use constant CONFIG_FAIL_NOT_SUPPORT_ZIMAGE_MUST_ONLY => 6;

my $debugLogFile = ".\\tools\\vivaCalculator.debug";
open DEBUG_LOG, ">$debugLogFile" or die "Cannot open debug log file: $!\n";

#****************************************************************************
# Arguments
#****************************************************************************
&vivaHelper::ErrorHandler("Insufficient arguments!")
   unless scalar(@ARGV) == 9;

my $dummyLISFilePath = $ARGV[0];
my $binaryFolder = $ARGV[1];
my $customFolder = $ARGV[2];
my $makefilePath = $ARGV[3];

my $freeROMSize = $ARGV[4];
my $newFeatureROCodeSize = $ARGV[5];
my $newFeatureRODataSize = $ARGV[6];
my $newFeatureRWSize = $ARGV[7];
my $newFeatureZISize = $ARGV[8];

# Print out the arguments
debugLog($separateLine);
debugLog("Arguments:");
debugLog("Dummy LIS File: $dummyLISFilePath");
debugLog("Binary Folder: $binaryFolder");
debugLog("Custom Folder: $customFolder");
debugLog("Makefile: $makefilePath");
debugLog("Free ROM Size: $freeROMSize");
debugLog("New Feature RO-CODE Size: $newFeatureROCodeSize");
debugLog("New Feature RO-DATA Size: $newFeatureRODataSize");
debugLog("New Feature RW Size: $newFeatureRWSize");
debugLog("New Feature ZI Size: $newFeatureZISize");
debugLog("");

#****************************************************************************
# Variables
#****************************************************************************
my $featureConfigFilePath = "$customFolder\\custom_FeatureConfig.h";

# Binary
my $romBinary = "$binaryFolder\\$romBinaryName";
my $bootZImageBinary = "$binaryFolder\\$bootZImageBinaryName";
my $zImageBinary = "$binaryFolder\\$zImageBinaryName";
my $dcmcmpBinary = "$binaryFolder\\$dcmcmpBinaryName";
my $aliceBinary = "$binaryFolder\\$aliceBinaryName";

#my $totalLISROMSize;
my %featureConfig;

# Feature switchs
my $bootZImageEnabled = 0;
my $zImageEnabled = 0;
my $dcmcmpEnabled = 0;
my $aliceEnabled = 0;
my $mbaEnabled = 0;

my $zImageContentPolicy = "BEST_PERF";

# Output configurations
my $bootZImageMaxCompressedSize = 0;

my $zImageMaxCompressedSize = 0;

my $dcmcmpMaxCompressedSize = 0;
my $dcmcmpUsedROM = 0;
my $dcmcmpUsedRAM = 0;

my $aliceMaxCompressedSize = 0;

my $restFreeROM = 0;
my $restAvailabeRAM = 0;

# Output object lists
my @rom1List;
my @bootZImageList;
my @zImageList;
my @aliceList;

#****************************************************************************
# Initialize
#****************************************************************************
debugLog($separateLine);
debugLog("[Start initializing stage]");

# Initialize VIVA helper for makefile parsing and LIS parsing
&vivaHelper::Initialize(vivaHelper::CONFIG_TYPE, $makefilePath, $dummyLISFilePath);

# Check the feature set
{
   debugLog("Checking feature set...");

   my $bootZImageOption = &vivaHelper::GetMakefileOption("BOOT_ZIMAGE_SUPPORT");
   my $zImageOption = &vivaHelper::GetMakefileOption("ZIMAGE_SUPPORT");
   my $dcmcmpOption = &vivaHelper::GetMakefileOption("DCM_COMPRESSION_SUPPORT");
   my $aliceOption = &vivaHelper::GetMakefileOption("ALICE_SUPPORT");
   my $mbaOption = &vivaHelper::GetMakefileOption("MULTIPLE_BINARY_FILES");

   my $zImageContentPolicyOption = &vivaHelper::GetMakefileOption("ZIMAGE_CONTENT_POLICY");

   if (defined $bootZImageOption and $bootZImageOption eq "TRUE")
   {
      $bootZImageEnabled = 1;
      subDebugLog("BOOT_ZIMAGE is enabled");
   }

   if (defined $zImageOption and $zImageOption eq "TRUE")
   {
      $zImageEnabled = 1;
      subDebugLog("ZIMAGE is enabled");

      if (defined $zImageContentPolicyOption)
      {
         $zImageContentPolicy = $zImageContentPolicyOption;
      }
      subDebugLog("ZIMAGE_CONTENT_POLICY is $zImageContentPolicy");
      &vivaHelper::ErrorHandler("Current version does not support ZIMAGE_CONTENT_POLICY != BEST_PERF!")
         unless $zImageContentPolicy eq "BEST_PERF";
   }

   if (defined $dcmcmpOption and $dcmcmpOption eq "TRUE")
   {
      $dcmcmpEnabled = 1;
      subDebugLog("DCM with Compression is enabled");
   }

   if (defined $aliceOption and $aliceOption eq "TRUE")
   {
      $aliceEnabled = 1;
      subDebugLog("ALICE is enabled");
   }

   if (defined $mbaOption and $mbaOption eq "TRUE")
   {
      $mbaEnabled = 1;
      subDebugLog("MBA is enabled");
      &vivaHelper::ErrorHandler("Current version does not support MBA!");
   }

   &vivaHelper::ErrorHandler("There is no VIVA feature enabled!")
      unless $zImageEnabled or $bootZImageEnabled or $aliceEnabled or $dcmcmpEnabled;
}

# Parse feature config file
debugLog("Parsing feature configuration file");
{
   &parseFeatureConfigFile(\%featureConfig);

   if (defined $featureConfig{CONFIG_VIVA_VENEER_RESERVE_SIZE_RATIO})
   {
      $veneerReserveRatio = $featureConfig{CONFIG_VIVA_VENEER_RESERVE_SIZE_RATIO};
   }
   if (defined $featureConfig{CONFIG_VIVA_MIN_VENEER_RESERVE_SIZE})
   {
      $minVeneerReserveSize = $featureConfig{CONFIG_VIVA_MIN_VENEER_RESERVE_SIZE};
   }
   if (defined $featureConfig{CONFIG_VIVA_MAX_VENEER_RESERVE_SIZE})
   {
      $maxVeneerReserveSize = $featureConfig{CONFIG_VIVA_MAX_VENEER_RESERVE_SIZE};
   }
   subDebugLog("Veneer Reserve Ratio = $veneerReserveRatio");
   subDebugLog("Minimum Veneer Reserve Size = $minVeneerReserveSize");
   subDebugLog("Maximum Veneer Reserve Size = $maxVeneerReserveSize");
}
debugLog("[End initializing stage]\n");

#****************************************************************************
# Configure
#****************************************************************************
debugLog($separateLine);
debugLog("[Start calculating stage]");

# Note DCMCMP should be configured before BOOT_ZIMAGE, ZIMAGE, and ALICE
if($dcmcmpEnabled)
{
   &calculateDcmcmp();
}

debugLog("");

if ($zImageEnabled)
{
   &calculateBootZImage_ZImage_Alice();
}
elsif ($aliceEnabled)
{
   &calculateAlice();
}

debugLog("[End calculating stage]\n");

#****************************************************************************
# Output
#****************************************************************************
debugLog($separateLine);
debugLog("[Start output stage]");

printLog("Rest Free ROM = $restFreeROM");
printLog("Rest Available RAM = $restAvailabeRAM");

if ($restAvailabeRAM < 0 || $restFreeROM < ($newFeatureROCodeSize + $newFeatureRODataSize + $newFeatureRWSize) * -0.1)
{
   printLog("FAIL: New feature cannot be added absolutely!");
}
elsif ($restFreeROM < 0)
{
   printLog("FAIL: New feature cannot be added with high probability!");
}
elsif ($restFreeROM < ($newFeatureROCodeSize + $newFeatureRODataSize + $newFeatureRWSize) * 0.1)
{
   printLog("PASS: New feature can be added with low probability!");
}
else
{
   printLog("PASS: New feature can be added with high probability!");
}

debugLog("[End output stage]");

close DEBUG_LOG;

exit 0;

#****************************************************************************
# subroutine:  calculateDcmcmp
# description: Perform the DCMCMP configuration
# input:       None
# output:      DCMCMP max compressed size, changed,
#              DCMCMP used ROM size, DCMCMP used RAM size
#****************************************************************************
sub calculateDcmcmp
{
   debugLog("Calculating DCMCMP...");

   my @regionInfo;
   my %configInfo;

   # Get all load region information in the LIS
   &vivaHelper::GetAllLISLoadRegionInfo(\@regionInfo);

   # Get DCMCMP region configuration information
   &vivaHelper::ReadRegionConfigInfoHash("DCMP", $customFolder, "RegionPostfixName", ["BodyRealSize"], \%configInfo);

   # Traverse all DCMCMP regions in LIS and set to region configuration information
   foreach my $region (@regionInfo)
   {
      # Filter the DCMCMP regions
      next unless ($region->{"region_name"} =~ m/DYNAMIC_COMP_(.+)/);
      next if ($region->{"region_name"} =~ m/DYNAMIC_COMP_CODE/);

      $dcmcmpUsedROM += $region->{"actual_size"};

      debugLog("$region->{region_name}_BODY, ".hex($configInfo{$1}{"BodyRealSize"}));
   }

   $dcmcmpUsedRAM = &vivaHelper::GetDcmcmpTotalRAMSize($customFolder);

   debugLog("Used ROM: $dcmcmpUsedROM");
   debugLog("Used RAM: $dcmcmpUsedRAM");
}

sub calculateBootZImage_ZImage_Alice
{
   debugLog("Calculating ZIMAGE, and ALICE...");

   my $romLoadRegionSize;
   my $rom1RegionSize;
   my $bootZImageRegionSize;
   my $zImageRegionSize;
   my $aliceRegionSize;

   my @bootZImageDummyList;
   my @aliceForbidDummyList;
   my @anyCodeDummyList;
   my @anyDataDummyList;

   my $bootZImageDummyRegionPadding;
   my $aliceForbidDummyRegionPadding;
   my $anyCodeDummyRegionPadding;
   my $anyDataDummyRegionPadding;

   my $rom1DummyRegionSize;
   my $bootZImageDummyRegionSize;
   my $zImageDummyRegionSize;
   my $aliceDummyRegionSize;
   my $aliceForbidDummyRegionSize;
   my $anyCodeDummyRegionSize;
   my $anyDataDummyRegionSize;

   my $bootZImageCompressionRatio;
   my $zImageCompressionRatio;
   my $aliceCompressionRatio;

   my $freeRAMSize;

   my $availableRAM;
   my $veneerReserveSize;

   my $computeROMSize;

   my $romSizeDiff;
   my $bootZImageSizeDiff = 0;
   my $zImageSizeDiff = 0;
   my $aliceSizeDiff = 0;

   my %variables =
      (
       '$dcmcmpMaxCompressedSize' => ["DCMCMP Compressed ROM Size", \$dcmcmpMaxCompressedSize],
       '$dcmcmpUsedRAM' => ["DCMCMP Used RAM", \$dcmcmpUsedRAM],
       '$veneerReserveSize' => ["Veneer Reserve Size", \$veneerReserveSize],
       '$veneerReserveRatio' => ["Veneer Reserve Ratio", \$veneerReserveRatio],
       '$minVeneerReserveSize' => ["Minimum Veneer Reserve Size", \$minVeneerReserveSize],
       '$maxVeneerReserveSize' => ["Maximum Veneer Reserve Size", \$maxVeneerReserveSize],
       '$romLoadRegionSize' => ["ROM Load Region Size", \$romLoadRegionSize],
       '$rom1RegionSize' => ["ROM1 Region Size", \$rom1RegionSize],
       '$bootZImageRegionSize' => ["BOOT_ZIMAGE Region Size", \$bootZImageRegionSize],
       '$zImageRegionSize' => ["ZIMAGE Region Size", \$zImageRegionSize],
       '$aliceRegionSize' => ["ALICE Region Size", \$aliceRegionSize],
       '$bootZImageDummyRegionPadding' => ["BOOT_ZIMAGE Dummy Region Padding", \$bootZImageDummyRegionPadding],
       '$aliceForbidDummyRegionPadding' => ["ALICE_FORBID Dummy Region Padding", \$aliceForbidDummyRegionPadding],
       '$anyCodeDummyRegionPadding' => ["ANY_CODE Dummy Region Padding", \$anyCodeDummyRegionPadding],
       '$anyDataDummyRegionPadding' => ["ANY_DATA Dummy Region Padding", \$anyDataDummyRegionPadding],
       '$rom1DummyRegionSize' => ["ROM1 Dummy Region Size", \$rom1DummyRegionSize],
       '$bootZImageDummyRegionSize' => ["BOOT_ZIMAGE Dummy Region Size", \$bootZImageDummyRegionSize],
       '$zImageDummyRegionSize' => ["ZIMAGE Dummy Region Size", \$zImageDummyRegionSize],
       '$aliceDummyRegionSize' => ["ALICE Dummy Region Size", \$aliceDummyRegionSize],
       '$aliceForbidDummyRegionSize' => ["ALICE_FORBID Dummy Region Size", \$aliceForbidDummyRegionSize],
       '$anyCodeDummyRegionSize' => ["ANY_CODE Dummy Region Size", \$anyCodeDummyRegionSize],
       '$anyDataDummyRegionSize' => ["ANY_DATA Dummy Region Size", \$anyDataDummyRegionSize],
       '$freeRAMSize' => ["Free RAM Size", \$freeRAMSize],
       '$availableRAM' => ["Available RAM", \$availableRAM],
       '$freeROMSize' => ["Free ROM Size", \$freeROMSize],
       '$newFeatureROCodeSize' => ["New Feature RO-CODE Size", \$newFeatureROCodeSize],
       '$newFeatureRODataSize' => ["New Feature RO-DATA Size", \$newFeatureRODataSize],
       '$newFeatureRWSize' => ["New Feature RW Size", \$newFeatureRWSize],
       '$newFeatureZISize' => ["New Feature ZI Size", \$newFeatureZISize],
       '$bootZImageCompressionRatio' => ["BOOT_ZIMAGE Compression Ratio", \$bootZImageCompressionRatio],
       '$zImageCompressionRatio' => ["ZIMAGE Compression Ratio", \$zImageCompressionRatio],
       '$aliceCompressionRatio' => ["ALICE Compression Ratio", \$aliceCompressionRatio],
       '$computeROMSize' => ["ROM Size", \$computeROMSize],
       '$romSizeDiff' => ["ROM Size Diff", \$romSizeDiff],
       '$bootZImageSizeDiff' => ["BOOT_ZIMAGE Size Diff", \$bootZImageSizeDiff],
       '$zImageSizeDiff' => ["ZIMAGE Size Diff", \$zImageSizeDiff],
       '$aliceSizeDiff' => ["ALICE Size Diff", \$aliceSizeDiff],
       '$restFreeROM' => ["Rest Free ROM", \$restFreeROM],
       '$restAvailabeRAM' => ["Rest Available RAM", \$restAvailabeRAM]
      );

   my %objectLists =
      (
       '@rom1List' => ["ROM1 List", \@rom1List, '$rom1RegionSize',],
       '@bootZImageList' => ["BOOT_ZIMAGE List", \@bootZImageList, '$bootZImageRegionSize',],
       '@zImageList' => ["ZIMAGE List", \@zImageList, '$zImageRegionSize',],
       '@aliceList' => ["ALICE List", \@aliceList, '$aliceRegionSize',],
       '@bootZImageDummyList' => ["BOOT_ZIMAGE Dummy List", \@bootZImageDummyList, '$bootZImageDummyRegionSize', '$bootZImageDummyRegionPadding'],
       '@aliceForbidDummyList' => ["ALICE_FORBID Dummy List", \@aliceForbidDummyList, '$aliceForbidDummyRegionSize', '$aliceForbidDummyRegionPadding'],
       '@anyCodeDummyList' => ["ANY_CODE Dummy List", \@anyCodeDummyList, '$anyCodeDummyRegionSize', '$anyCodeDummyRegionPadding'],
       '@anyDataDummyList' => ["ANY_DATA Dummy List", \@anyDataDummyList, '$anyDataDummyRegionSize', '$anyDataDummyRegionPadding']
      );

   debugLog("Get dummy scatter object lists");
   {
      # To be added
      $bootZImageDummyRegionPadding = &_inputObjectListFromExecutionRegion("BOOT_ZIMAGE_ER", \@bootZImageDummyList, "+RO", "BOOT_ZIMAGE list");
      $aliceForbidDummyRegionPadding = &_inputObjectListFromExecutionRegion("ALICE_FORBID", \@aliceForbidDummyList, "+RO", "ALICE_FORBID list");
      $anyCodeDummyRegionPadding = &_inputObjectListFromExecutionRegion("ZIMAGE_DUMMY_CODE", \@anyCodeDummyList, "+RO-CODE", "ANY_CODE list");
      $anyDataDummyRegionPadding = &_inputObjectListFromExecutionRegion("ZIMAGE_DUMMY_DATA", \@anyDataDummyList, "+RO-DATA", "ANY_DATA list");

      push @anyCodeDummyList, {"name" => "new_feature.obj", "attributes" => ["+RO-CODE"], "size" => $newFeatureROCodeSize, "category" => "compute size"} unless ($newFeatureROCodeSize == 0);
      push @anyDataDummyList, {"name" => "new_feature.obj", "attributes" => ["+RO-DATA"], "size" => $newFeatureRODataSize, "category" => "compute size"} unless ($newFeatureRODataSize == 0);
   }

   debugLog("Get size information");
   {
      $rom1DummyRegionSize = &_getExecutionRegionInfo("ROM1", "actual_size");
      $bootZImageDummyRegionSize = &_getExecutionRegionInfo("BOOT_ZIMAGE_ER", "actual_size") if ($bootZImageEnabled);
      $zImageDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_ER", "actual_size");
      $aliceDummyRegionSize = &_getExecutionRegionInfo("ALICE", "actual_size") if ($aliceEnabled);
      $aliceForbidDummyRegionSize = &_getExecutionRegionInfo("ALICE_FORBID", "actual_size") if ($aliceEnabled);
      $anyCodeDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_DUMMY_CODE", "actual_size") + $newFeatureROCodeSize;
      $anyDataDummyRegionSize = &_getExecutionRegionInfo("ZIMAGE_DUMMY_DATA", "actual_size") + $newFeatureRODataSize;

      $romLoadRegionSize = &_getLoadRegionInfo("ROM", "actual_size");
      $rom1RegionSize = $rom1DummyRegionSize;
      $bootZImageRegionSize = $bootZImageDummyRegionSize if ($bootZImageEnabled);
      $zImageRegionSize = $zImageDummyRegionSize;
      $aliceRegionSize = $aliceDummyRegionSize if ($aliceEnabled);

      $freeRAMSize = &getFreeRAMSize();
   }

   debugLog("Compute the compression ratios");
   {
      $bootZImageCompressionRatio = &_getCompressionRatio("BOOT_ZIMAGE", $bootZImageBinary, $bootZImageBinary.".bin") if ($bootZImageEnabled);
      $zImageCompressionRatio = &_getCompressionRatio("ZIMAGE", $zImageBinary, $zImageBinary.".bin");
      $aliceCompressionRatio = &_getCompressionRatio("ALICE", $aliceBinary, $aliceBinary.".bin") if ($aliceEnabled);
   }

   # Configure
   {
      debugLog("Compute Available RAM");

      $veneerReserveSize = ($freeRAMSize - $dcmcmpUsedRAM - $zImageDummyRegionSize) * $veneerReserveRatio;
      if ($veneerReserveSize < $minVeneerReserveSize)
      {
         &_evaluateAssignment('$veneerReserveSize = $minVeneerReserveSize', \%variables);
      }
      elsif ($veneerReserveSize > $maxVeneerReserveSize)
      {
         &_evaluateAssignment('$veneerReserveSize = $maxVeneerReserveSize', \%variables);
      }
      else
      {
         &_evaluateAssignment('$veneerReserveSize = ($freeRAMSize - $dcmcmpUsedRAM - $zImageDummyRegionSize) * $veneerReserveRatio', \%variables);
      }
      &_evaluateAssignment('$availableRAM = $freeRAMSize - $dcmcmpUsedRAM - $zImageDummyRegionSize - $veneerReserveSize - $newFeatureRWSize - $newFeatureZISize', \%variables);
      $availableRAM = int($availableRAM);

      if ($aliceEnabled && $bootZImageEnabled)
      {
         _layout_BootZImage_ZImage_Alice(\%variables, \%objectLists);
      }
      elsif ($aliceEnabled)
      {
         _layout_ZImage_Alice(\%variables, \%objectLists);
      }
      else # only ZIMAGE is enabled
      {
         _layout_ZImage(\%variables, \%objectLists);
      }

      debugLog("Compute the Max Compressed Size");
      {
         $bootZImageMaxCompressedSize = &_getRegionMaxCompressedSize("BOOT_ZIMAGE", $bootZImageRegionSize, $bootZImageCompressionRatio) if $bootZImageEnabled;
         $zImageMaxCompressedSize = &_getRegionMaxCompressedSize("ZIMAGE", $zImageRegionSize, $zImageCompressionRatio);
         $aliceMaxCompressedSize = &_getRegionMaxCompressedSize("ALICE", $aliceRegionSize, $aliceCompressionRatio) if $aliceEnabled;
      }

      debugLog("Compute the free size");
      {
         &_evaluateAssignment('$computeROMSize = $rom1RegionSize + ($romLoadRegionSize - $rom1DummyRegionSize - $aliceForbidDummyRegionSize)', \%variables);
         $romSizeDiff = &_getBinarySizeDiff("ROM", $computeROMSize, $romBinary);
         $bootZImageSizeDiff = &_getBinarySizeDiff("BOOT_ZIMAGE", $bootZImageMaxCompressedSize, $bootZImageBinary) if $bootZImageEnabled;
         $zImageSizeDiff = &_getBinarySizeDiff("ZIMAGE", $zImageMaxCompressedSize, $zImageBinary);
         $aliceSizeDiff = &_getBinarySizeDiff("ALICE", $aliceMaxCompressedSize, $aliceBinary) if $aliceEnabled;

         &_evaluateAssignment('$restFreeROM = $freeROMSize - $romSizeDiff - $bootZImageSizeDiff - $zImageSizeDiff - $aliceSizeDiff - $newFeatureRWSize', \%variables);
         &_evaluateAssignment('$restAvailabeRAM = $availableRAM', \%variables);
      }
   }
}

sub _layout_BootZImage_ZImage_Alice
{
   my $variables = shift;
   my $objectLists = shift;

   # When BOOT_ZIMAGE enabled, all ALICE_FORBID and ANY_DATA list should be in ZIMAGE
   debugLog("Push ALICE_FORBID List and ANY_DATA List to ZIMAGE");
   {
      &_pushToObjectList('@zImageList', '@aliceForbidDummyList', $variables, $objectLists);
      &_pushToObjectList('@zImageList', '@anyDataDummyList', $variables, $objectLists);

      &_evaluateAssignment('$availableRAM = $availableRAM - ($aliceForbidDummyRegionSize + $anyDataDummyRegionSize)', $variables);
   }

   # The rest RAM size is then used by BOOT_ZIMAGE
   debugLog("Push BOOT_ZIMAGE");
   if (__getVar('$availableRAM', $variables) >= __getVar('$bootZImageDummyRegionSize', $variables))
   {
      subDebugLog("Available RAM >= BOOT_ZIMAGE_ER size");

      # All BOOT_ZIMAGE region can be put in RAM
      # No change of BOOT_ZIMAGE object list
      subDebugLog("BOOT_ZIMAGE list = BOOT_ZIMAGE dummy list");
      subDebugLog("BOOT_ZIMAGE region size = BOOT_ZIMAGE dummy size = ".__getVar('$bootZImageDummyRegionSize', $variables));

      &_evaluateAssignment('$availableRAM = $availableRAM - $bootZImageDummyRegionSize', $variables);
   }
   else
   {
      subDebugLog("Available RAM < BOOT_ZIMAGE_ER size");

      # Should split BOOT_ZIMAGE dummy list
      &vivaHelper::ChangeObjectListAttributeListByObjectList(__getObjList('@bootZImageDummyList', $objectLists),
                                                             __getObjList('@bootZImageList', $objectLists));
      @{__getObjList('@bootZImageList', $objectLists)} = ();
      __setVar('$bootZImageRegionSize', 0, $variables);

      &_splitObjectListAndPush('@bootZImageDummyList', '@bootZImageList', '@rom1List',
                               '$availableRAM', $variables, $objectLists);

      __setVar('$availableRAM', 0, $variables);
      subDebugLog("Available RAM = 0");
   }

   # Finally, the rest RAM is used by ZIMAGE for ANY_CODE
   debugLog("Push ANY_CODE to ZIMAGE or ALICE");
   {
      &_splitObjectListAndPushByAvailableRAM('@anyCodeDummyList', '@zImageList', '@aliceList',
                                             $variables, $objectLists);
   }
}

sub _layout_ZImage_Alice
{
   my $variables = shift;
   my $objectLists = shift;

   # The available RAM is first used to compress ALICE_FORBID list
   debugLog("Push ALICE_FORBID List to ZIMAGE and ROM1");
   {
      &_splitObjectListAndPushByAvailableRAM('@aliceForbidDummyList', '@zImageList', '@rom1List',
                                             $variables, $objectLists);
   }

   # The rest RAM size is then used by ANY_DATA
   debugLog("Push ANY_DATA to ZIMAGE and ROM1");
   {
      &_splitObjectListAndPushByAvailableRAM('@anyDataDummyList', '@zImageList', '@rom1List',
                                             $variables, $objectLists);
   }

   # Finally, the rest RAM is used by ZIMAGE for ANY_CODE
   debugLog("Push ANY_CODE to ZIMAGE or ALICE");
   {
      &_splitObjectListAndPushByAvailableRAM('@anyCodeDummyList', '@zImageList', '@aliceList',
                                             $variables, $objectLists);
   }
}

sub _layout_ZImage
{
   my $variables = shift;
   my $objectLists = shift;

   # The rest RAM size is first used by ANY_DATA
   debugLog("Push ANY_DATA to ZIMAGE and ROM1");
   {
      &_splitObjectListAndPushByAvailableRAM('@anyDataDummyList', '@zImageList', '@rom1List',
                                             $variables, $objectLists);
   }

   # Finally, the rest RAM is used by ZIMAGE for ANY_CODE
   debugLog("Push ANY_CODE to ZIMAGE or ROM1");
   {
      &_splitObjectListAndPushByAvailableRAM('@anyCodeDummyList', '@zImageList', '@rom1List',
                                             $variables, $objectLists);
   }
}

sub calculateAlice
{
   debugLog("Calculating ALICE");

   my $romSizeDiff;
   my $aliceRegionSize;
   my $aliceCompressionRatio;
   my $freeRAMSize;
   my $availableRAM;
   my $aliceSizeDiff;

   my %variables =
      (
       '$aliceRegionSize' => ["ALICE Region Size", \$aliceRegionSize],
       '$freeRAMSize' => ["Free RAM Size", \$freeRAMSize],
       '$availableRAM' => ["Available RAM", \$availableRAM],
       '$freeROMSize' => ["Free ROM Size", \$freeROMSize],
       '$newFeatureROCodeSize' => ["New Feature RO-CODE Size", \$newFeatureROCodeSize],
       '$newFeatureRODataSize' => ["New Feature RO-DATA Size", \$newFeatureRODataSize],
       '$newFeatureRWSize' => ["New Feature RW Size", \$newFeatureRWSize],
       '$newFeatureZISize' => ["New Feature ZI Size", \$newFeatureZISize],
       '$aliceCompressionRatio' => ["ALICE Compression Ratio", \$aliceCompressionRatio],
       '$romSizeDiff' => ["ROM Size Diff", \$romSizeDiff],
       '$aliceSizeDiff' => ["ALICE Size Diff", \$aliceSizeDiff],
       '$restFreeROM' => ["Rest Free ROM", \$restFreeROM],
       '$restAvailabeRAM' => ["Rest Available RAM", \$restAvailabeRAM]
      );

   $freeRAMSize = &getFreeRAMSize();
   debugLog("Compute Available RAM");
   &_evaluateAssignment('$availableRAM = ($freeRAMSize - $dcmcmpUsedRAM) * (1 - $veneerReserveRatio) - $newFeatureRWSize - $newFeatureZISize', \%variables);
   $availableRAM = int($availableRAM);

   $aliceRegionSize = &_getExecutionRegionInfo("ALICE", "actual_size") + $newFeatureROCodeSize;
   $aliceCompressionRatio = &_getCompressionRatio("ALICE", $aliceBinary, $aliceBinary.".bin");
   $aliceMaxCompressedSize = &_getRegionMaxCompressedSize("ALICE", $aliceRegionSize, $aliceCompressionRatio);

   debugLog("Compute the free size");
   {
      &_evaluateAssignment('$romSizeDiff = $newFeatureRODataSize + $newFeatureRWSize', \%variables);
      $aliceSizeDiff = &_getBinarySizeDiff("ALICE", $aliceMaxCompressedSize, $aliceBinary);

      &_evaluateAssignment('$restFreeROM = $freeROMSize - $romSizeDiff - $aliceSizeDiff - $newFeatureRWSize', \%variables);
      &_evaluateAssignment('$restAvailabeRAM = $availableRAM', \%variables);
   }
}

sub _inputObjectListFromFile
{
   my $filename = shift;
   my $listRef = shift;
   my $listName = shift;
   my @filePath = fileparse($filename);

   &vivaHelper::InputObjectListFromFile($filename, $listRef);
   subDebugLog("Input $listName list from $filePath[0]");
}

sub _inputObjectListFromExecutionRegion
{
   my $regionName = shift;
   my $listRef = shift;
   my $defaultAttribute = shift;
   my $defaultCategory = shift;
   my $padding = 0;

   my @originalList;
   my @mergeList;

   $padding = &vivaHelper::GetLISExecutionRegionObjectList($regionName, \@originalList, $defaultAttribute, $defaultCategory);
   subDebugLog("Get $regionName list from LIS execution region, padding = $padding");
   &vivaHelper::MergeDuplicateObjectListByName(\@originalList, $listRef, \@mergeList);
   subDebugLog("   Merge duplicate entry: $_->{name}, size: $_->{size}") foreach @mergeList;
   return $padding;
}

sub _getExecutionRegionInfo
{
   my $regionName = shift;
   my $infoName = shift;
   my %regionInfo;
   my $result;

   &vivaHelper::GetLISExecutionRegionInfo($regionName, \%regionInfo);
   $result = $regionInfo{$infoName};
   subDebugLog("$regionName execution region $infoName = $result");

   return $result;
}

sub _getLoadRegionInfo
{
   my $regionName = shift;
   my $infoName = shift;
   my %regionInfo;
   my $result;

   &vivaHelper::GetLISLoadRegionInfo($regionName, \%regionInfo);
   $result = $regionInfo{$infoName};
   subDebugLog("$regionName load region $infoName = $result");

   return $result;
}

sub _getRegionMaxCompressedSize
{
   my $regionName = shift;
   my $regionSize = shift;
   my $compressionRatio = shift;

   my $maxCompressedSize = int($regionSize * $compressionRatio + 0.99);
   subDebugLog("$regionName max compressed size = $regionName Region Size * $regionName Compression Ratio");
   subDebugLog("   = $regionSize * $compressionRatio");
   subDebugLog("   = $maxCompressedSize");

   return $maxCompressedSize;
}

sub _pushToObjectList
{
   my $targetList = shift;
   my $sourceList = shift;

   my $variables = shift;
   my $objectLists = shift;

   push @{$objectLists->{$targetList}[1]}, @{$objectLists->{$sourceList}[1]};
   subDebugLog("$objectLists->{$targetList}[0] += $objectLists->{$sourceList}[0]");
   _evaluateAssignment("$objectLists->{$targetList}[2] = $objectLists->{$targetList}[2] + $objectLists->{$sourceList}[2]", $variables);
}

sub _splitObjectListAndPush
{
   my $sourceList = shift;
   my $firstList = shift;
   my $secondList = shift;

   my $splitSize = shift;

   my $variables = shift;
   my $objectLists = shift;

   my $splitSizeWithVeneer;
   my $actualSplitSize;

   my @list1;
   my @list2;

   $variables->{'$splitSizeWithVeneer'} = ["Splitted Size with Veneer", \$splitSizeWithVeneer];
   $variables->{'$actualSplitSize'} = ["Actual Splitted Size", \$actualSplitSize];

   #$objectLists->{'@list1'} = ["Splitted List", \@list1, '$actualSplitSize * (1 + $veneerReserveRatio)'];
   $objectLists->{'@list1'} = ["Splitted List", \@list1, '$actualSplitSize + '."$objectLists->{$sourceList}[3]"];
   $objectLists->{'@list2'} = ["Rest List", \@list2, "$objectLists->{$sourceList}[2]".' - $actualSplitSize'];

   subDebugLog("Split $objectLists->{$sourceList}[0]");

   #&_evaluateAssignment('$splitSizeWithVeneer = '."$splitSize".' * (1 + $veneerReserveRatio)', $variables);
   &_evaluateAssignment('$splitSizeWithVeneer = '."$splitSize - $objectLists->{$sourceList}[3]", $variables);
   $splitSizeWithVeneer = int($splitSizeWithVeneer);

   $actualSplitSize = &vivaHelper::SplitObjectListBySize($objectLists->{$sourceList}[1], $splitSizeWithVeneer,
                                                         \@list1, \@list2);
   subDebugLog("Actual Splitted Size = $actualSplitSize");

   &_pushToObjectList($firstList, '@list1', $variables, $objectLists);
   &_pushToObjectList($secondList, '@list2', $variables, $objectLists);

   delete $variables->{'$splitSizeWithVeneer'};
   delete $variables->{'$actualSplitSize'};

   delete $objectLists->{'@list1'};
   delete $objectLists->{'@list2'};

   return $actualSplitSize;
}

sub _splitObjectListAndPushByAvailableRAM
{
   my $sourceList = shift;
   my $firstList = shift;
   my $secondList = shift;

   my $variables = shift;
   my $objectLists = shift;

   if (${$variables->{'$availableRAM'}[1]} < $smallestSplitableRAMSize and ${$variables->{'$availableRAM'}[1]} != 0)
   {
      subDebugLog("Available RAM < Smallest Splitable RAM");
      subDebugLog("   = $smallestSplitableRAMSize");

      if (${$variables->{'$availableRAM'}[1]} > 0)
      {
         ${$variables->{'$availableRAM'}[1]} = 0;
         subDebugLog("Available RAM = 0");
      }
   }

   &_splitObjectListAndPush($sourceList, $firstList, $secondList,
                            '$availableRAM', $variables, $objectLists);

   if (${$variables->{'$availableRAM'}[1]} >= ${$variables->{$objectLists->{$sourceList}[2]}[1]})
   {
      &_evaluateAssignment('$availableRAM = $availableRAM - '."$objectLists->{$sourceList}[2]", $variables);
   }
   else
   {
      if (${$variables->{'$availableRAM'}[1]} > 0)
      {
         ${$variables->{'$availableRAM'}[1]} = 0;
         subDebugLog("Available RAM = 0");
      }
   }
}

sub _evaluateAssignment
{
   my $assignmentString = shift;
   my $variables = shift;
   my @assignment = split(/=/, $assignmentString);

   my $symbolString = $assignmentString;

   $assignment[0] =~ s/(?:^ +)||(?: +$)//g;
   $assignment[1] =~ s/(?:^ +)||(?: +$)//g;

   my $evaluationString = $assignment[1];

   while (my ($key, $value)= each %$variables)
   {
      my $matchSymbol = "\\$key";
      $symbolString =~ s/$matchSymbol/$value->[0]/g;
      $evaluationString =~ s/$matchSymbol/${$value->[1]}/g;
   }

   my $intermediate = eval{$evaluationString};
   my $assigneeRef = $variables->{$assignment[0]}[1];

   $$assigneeRef = eval ($evaluationString);

   subDebugLog($symbolString);
   subDebugLog("   = $intermediate");
   subDebugLog("   = $$assigneeRef");
}

sub __getVar
{
   my $variableName = shift;
   my $variables = shift;

   return ${$variables->{$variableName}[1]};
}

sub __getVarText
{
   my $variableName = shift;
   my $variables = shift;

   return ${$variables->{$variableName}[0]};
}

sub __setVar
{
   my $variableName = shift;
   my $value = shift;
   my $variables = shift;

   ${$variables->{$variableName}[1]} = $value;
}

sub __getObjList
{
   my $objectListName = shift;
   my $objectLists = shift;

   return $objectLists->{$objectListName}[1];
}

sub __getObjListSize
{
   my $objectListName = shift;
   my $objectLists = shift;

   return $objectLists->{$objectListName}[2];
}

sub __getObjListPadding
{
   my $objectListName = shift;
   my $objectLists = shift;

   return $objectLists->{$objectListName}[3];
}

sub __getObjListText
{
   my $objectListName = shift;
   my $objectLists = shift;

   return $objectLists->{$objectListName}[0];
}

sub _isObjectListChanged
{
   my $objectListFile = shift;
   my $objectListRef = shift;

   my @objectListOriginal;

   &vivaHelper::InputObjectListFromFile($objectListFile, \@objectListOriginal);

   if (&vivaHelper::CompareObjectList(\@objectListOriginal, $objectListRef) == 0)
   {
      return 0;
   }
   else
   {
      return 1;
   }
}

sub _getCompressionRatio
{
   my $regionName = shift;
   my $compressedBinary = shift;
   my $uncompressedBinary = shift;

   my $uncompressedBinarySize = -s $uncompressedBinary or
      &vivaHelper::ErrorHandler("Cannot get file size $uncompressedBinary: $!", __FILE__, __LINE__);
   my $compressedBinarySize = -s $compressedBinary or
      &vivaHelper::ErrorHandler("Cannot get file size $compressedBinary: $!", __FILE__, __LINE__);

   my $compressionRatio = $compressedBinarySize / $uncompressedBinarySize;
   subDebugLog("$regionName Compression Ratio = $regionName Compressed Binary Size / $regionName Uncompressed Binary Size");
   subDebugLog("   = $compressedBinarySize / $uncompressedBinarySize");
   subDebugLog("   = $compressionRatio");

   return $compressionRatio;
}

sub _getBinarySizeDiff
{
   my $regionName = shift;
   my $computeSize = shift;
   my $binary = shift;

   my $binarySize = -s $binary or
      &vivaHelper::ErrorHandler("Cannot get file size $binary: $!", __FILE__, __LINE__);

   my $result = $computeSize - $binarySize;

   subDebugLog("$regionName Size Difference = $regionName Max Compressed Size - $regionName Compressed Binary Size");
   subDebugLog("   = $computeSize - $binarySize");
   subDebugLog("   = $result");

   return $result;
}

#****************************************************************************
# subroutine:  parseFeatureConfigFile
# description: Get the settings in the feature config file
# input:       The setting hash ref
# output:      The settings
#****************************************************************************
sub parseFeatureConfigFile
{
   my $featureConfigRef = shift;
   my $filename = $featureConfigFilePath;

   open my $input, "<$filename" or
      &vivaHelper::ErrorHandler("Cannot open file $filename: $!");

   while (<$input>)
   {
      chomp;
      if (/^\s*\#define\s+(\S+)\s+(\S+)/)
      {
         if (substr($2, 0, 2) eq "0x")
         {
            $featureConfigRef->{$1} = hex($2);
         }
         else
         {
            $featureConfigRef->{$1} = $2;
         }
      }
   }

   close $input;
}

#****************************************************************************
# subroutine:  getFreeRAMSize
# description: Get the free RAM size.
# input:       None
# output:      Free RAM size
#****************************************************************************
sub getFreeRAMSize
{
   # TODO: Move this to LISInfo.pm
   my $externalRAMSize = &getExternalRAMSize();
   my $usedRAM;
   my $cacheDummyEndSize = 4;
   my $result;

   my %regionInfo;
   &vivaHelper::GetLISExecutionRegionInfo("DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI", \%regionInfo);
   $usedRAM = ($regionInfo{"base_address"} & hex("0x07FFFFFF")) + $regionInfo{"actual_size"};
   subDebugLog("End of cacheable ZI = $usedRAM");

   &vivaHelper::GetLISExecutionRegionInfo("EXTSRAM_DSP_TX", \%regionInfo);
   $usedRAM += $regionInfo{"max_size"};
   subDebugLog("DSP TX RAM = ".$regionInfo{"max_size"});

   &vivaHelper::GetLISExecutionRegionInfo("EXTSRAM_DSP_RX", \%regionInfo);
   $usedRAM += $regionInfo{"max_size"};
   subDebugLog("DSP RX RAM = ".$regionInfo{"max_size"});

   subDebugLog("Cache dummy end size = $cacheDummyEndSize");

   $result = $externalRAMSize - $usedRAM - $cacheDummyEndSize;

   subDebugLog("Free RAM size = External Total RAM Size - (End of cacheable ZI + DSP TX RAM + DSP RX RAM) - Cache Dummy End Size");
   subDebugLog("   = $result");

   return $result;
}

#****************************************************************************
# subroutine:  getExternalRAMSize
# description: Get the external RAM size.
# input:       None
# output:      External RAM size
#****************************************************************************
sub getExternalRAMSize
{
   my $result;

   if (0)
   {
      $result = $featureConfig{"PROJECT_EXPECTED_RAM_LIMIT"};

      debugLog("Project Expected RAM Limit is set");
   }
   else
   {
      my $filename = "$customFolder\\custom_EMI_release.h";

      open my $input, "<$filename" or
         &vivaHelper::ErrorHandler("Cannot open file $filename: $!");

      while (<$input>)
      {
        if (/\#define EMI_EXTSRAM_SIZE ((\S|\s)+)/)
        {
          $result = eval($1);
          last;
        }
      }
      close ($input);
   }

   subDebugLog("External Total RAM Size =  $result");

   return $result;
}

#****************************************************************************
# subroutine:  min
# description: Get the minimum one in the two input.
# input:       Number 1, number 2
# output:      Minimum number
#****************************************************************************
sub min
{
    my ($m, $n) = @_;

    if ($m < $n) {
        $m
    }
    else {
        $n
    }
}

sub printLog
{
   print "$_[0]\n";
   debugLog($_[0]);
}

sub debugLog
{
   if ($DEBUG)
   {
      print DEBUG_LOG ("$_[0]\n");
   }
}

sub subDebugLog
{
   if ($DEBUG)
   {
      print DEBUG_LOG ("\t$_[0]\n");
   }
}
