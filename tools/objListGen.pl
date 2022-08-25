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
#*   objListGen.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This file generate the object list for scatter file including.
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
use File::Path;
use Storable qw/lock_retrieve lock_nstore/;
use objListHelper;
use FileInfoParser;
use CommonUtility;
use scatFrame;
use tools::pack_dep_gen;

PrintDependModule();

#****************************************************************************
# History
#****************************************************************************
my $OBJ_LIST_GEN_VERNO = " v1.07";
   # v1.07: Phase in NAND booting support
   # v1.06: Phase in obj_sys_auto_gen
   # v1.05: Phase in ZIMAGE_CONTENT_POLICY
   # v1.04: Check if INSIDE_MTK to gen dummy lis or not
   # v1.03: Phase in check conflict mechanism
   # v1.02: Phase in PrintDependency
   # v1.01: Phase in BOOT_ZIMAGE
   # v1.00: Phase in object list generate mechanism

#****************************************************************************
# Constants
#****************************************************************************
my $DEBUG = 1;
my $templateFolderPath  = "custom\\system\\Template";
my $objectListGenFolderPath = "scat_config\\FeatureBased\\ObjListGen";

# Feature option
my $featureOptionBackupFileName = "object.list.backup";

# Source
my $aliceForbidListFileName = "AliceForbidList.csv";
my $aliceNandForbidListFileName = "AliceNandForbidList.csv";
my $bootZImageForbidListFileName = "BootZImageForbidList.csv";
my $zImageForbidListFileName = "ZImageForbidList.csv";

my $zImageMustListFileName = "Common.csv";

# Source backup
my $aliceForbidListBackupFileName = "AliceForbidList.csv.backup";
my $aliceNandForbidListBackupFileName = "AliceNandForbidList.csv.backup";
my $bootZImageForbidListBackupFileName = "BootZImageForbidList.csv.backup";
my $zImageForbidListBackupFileName = "ZImageForbidList.csv.backup";

my $zImageMustListBackupFileName = "ZIMAGE.csv.backup";

# Normal scatter
my $objectROM1ListFileName = "objectROM1.list";
my $objectROM2ListFileName = "objectROM2.list";
my $objectROM2RODATAListFileName = "objectROM2_RODATA.list";
my $objectBootZImageListFileName = "objectBOOT_ZIMAGE.list";
my $objectZImageListFileName = "objectZIMAGE.list";
my $objectAliceListFileName = "objectALICE.list";

# Dummy scatter
my $objectROM1DummyListFileName = "objectROM1_dummy.list";
my $objectROM2DummyListFileName = "objectROM2_dummy.list";
my $objectROM2RODATADummyListFileName = "objectROM2_RODATA_dummy.list";
my $objectBootZImageDummyListFileName = "objectBOOT_ZIMAGE_dummy.list";
my $objectZImageDummyListFileName = "objectZIMAGE_dummy.list";
my $objectAliceDummyListFileName = "objectALICE_dummy.list";
my $objectAliceForbidDummyListFileName = "objectALICE_FORBID_dummy.list";

my $separateLine = "=============================================================";

use constant GEN_FAIL_OBJECT_CONFLICT_CSV_TO_CSV => 0;
use constant GEN_FAIL_OBJECT_CONFLICT_CSV_TO_LIST => 1;

#****************************************************************************
# Arguments
#****************************************************************************
&objListHelper::ErrorHandler("Insufficient arguments! ".scalar(@ARGV))
   unless scalar(@ARGV) >= 3;

my $customFolder = $ARGV[0];
my $makefilePath = $ARGV[1];
my $insideMTK = $ARGV[2];
my $forceDummyScatter = $ARGV[3];
my $forceRegenObjectList = $ARGV[4];

# To align error message file name format
$customFolder =~ s/^.\\|^\\//;
$makefilePath =~ s/^.\\|^\\//;
PrintDependency($makefilePath);

# Print out the arguments
printLog($separateLine);
printLog("Arguments:");
printLog("Custom Folder: $customFolder");
printLog("Makefile: $makefilePath");
printLog("Is Inside MTK: $insideMTK");
printLog("Force Dummy Scatter: $forceDummyScatter");
printLog("Force Regen Object List: $forceRegenObjectList");
printLog("");

#****************************************************************************
# Variables
#****************************************************************************
# Files
my $sourceCSVFolder = "$templateFolderPath\\$objectListGenFolderPath";
my $destinationListFolder = "$customFolder\\$objectListGenFolderPath";

# Source files
my $aliceForbidListFile = &_getSourceFilePath($aliceForbidListFileName);
my $aliceNandForbidListFile = &_getSourceFilePath($aliceNandForbidListFileName);
my $bootZImageForbidListFile = &_getSourceFilePath($bootZImageForbidListFileName);
my $zImageForbidListFile = &_getSourceFilePath($zImageForbidListFileName);

my $zImageMustListFile = &scatFrame::GetConfigInput("ZIMAGE", $zImageMustListFileName, scatFrame::InputSections, $customFolder);

# Source backup files
my $featureOptionBackupFile = "$destinationListFolder\\$featureOptionBackupFileName";
my $aliceForbidListBackupFile = "$destinationListFolder\\$aliceForbidListBackupFileName";
my $aliceNandForbidListBackupFile = "$destinationListFolder\\$aliceNandForbidListBackupFileName";
my $bootZImageForbidListBackupFile = "$destinationListFolder\\$bootZImageForbidListBackupFileName";
my $zImageForbidListBackupFile = "$destinationListFolder\\$zImageForbidListBackupFileName";

my $zImageMustListBackupFile = "$destinationListFolder\\$zImageMustListBackupFileName";

# Normal scatter
my $objectROM1ListFile = "$destinationListFolder\\$objectROM1ListFileName";
my $objectROM2ListFile = "$destinationListFolder\\$objectROM2ListFileName";
my $objectROM2RODATAListFile = "$destinationListFolder\\$objectROM2RODATAListFileName";
my $objectBootZImageListFile = "$destinationListFolder\\$objectBootZImageListFileName";
my $objectZImageListFile = "$destinationListFolder\\$objectZImageListFileName";
my $objectAliceListFile = "$destinationListFolder\\$objectAliceListFileName";

# Dummy scatter
my $objectROM1DummyListFile = "$destinationListFolder\\$objectROM1DummyListFileName";
my $objectROM2DummyListFile = "$destinationListFolder\\$objectROM2DummyListFileName";
my $objectROM2RODATADummyListFile = "$destinationListFolder\\$objectROM2RODATADummyListFileName";
my $objectBootZImageDummyListFile = "$destinationListFolder\\$objectBootZImageDummyListFileName";
my $objectZImageDummyListFile = "$destinationListFolder\\$objectZImageDummyListFileName";
my $objectAliceDummyListFile = "$destinationListFolder\\$objectAliceDummyListFileName";
my $objectAliceForbidDummyListFile = "$destinationListFolder\\$objectAliceForbidDummyListFileName";

# Feature switches
my %makefileOptions;

my $aliceEnabled = 0;
my $bootZImageEnabled = 0;
my $zImageEnabled = 0;

my $zImageContentPolicy = "BEST_PERF"; # Default value

my $isDummyScatter = 0;

my $isNandBooting = 0;

# Source object lists
my @aliceForbidList = ();
my @bootZImageForbidList = ();
my @zImageForbidList = ();

my @zImageMustList = ();

# Output object lists
my %outputObjectLists =
(
   "ROM1"               => {"list" => [], "generate" => 0, "list_file" => $objectROM1ListFile},
   "ROM2"               => {"list" => [], "generate" => 0, "list_file" => $objectROM2ListFile},
   "ROM2_RODATA"        => {"list" => [], "generate" => 0, "list_file" => $objectROM2RODATAListFile},
   "BOOT_ZIMAGE"        => {"list" => [], "generate" => 0, "list_file" => $objectBootZImageListFile},
   "ZIMAGE"             => {"list" => [], "generate" => 0, "list_file" => $objectZImageListFile},
   "ALICE"              => {"list" => [], "generate" => 0, "list_file" => $objectAliceListFile},
   "ROM1_DUMMY"         => {"list" => [], "generate" => 0, "list_file" => $objectROM1DummyListFile},
   "ROM2_DUMMY"         => {"list" => [], "generate" => 0, "list_file" => $objectROM2DummyListFile},
   "ROM2_RODATA_DUMMY"  => {"list" => [], "generate" => 0, "list_file" => $objectROM2RODATADummyListFile},
   "BOOT_ZIMAGE_DUMMY"  => {"list" => [], "generate" => 0, "list_file" => $objectBootZImageDummyListFile},
   "ZIMAGE_DUMMY"       => {"list" => [], "generate" => 0, "list_file" => $objectZImageDummyListFile},
   "ALICE_DUMMY"        => {"list" => [], "generate" => 0, "list_file" => $objectAliceDummyListFile},
   "ALICE_FORBID_DUMMY" => {"list" => [], "generate" => 0, "list_file" => $objectAliceForbidDummyListFile}
);

#****************************************************************************
# Initialize
#****************************************************************************
printLog($separateLine);
printLog("[Start initializing stage]");

# Initialize the environment
&initialize();

printLog("[End initializing stage]\n");

#****************************************************************************
# Check conflict
#****************************************************************************
printLog($separateLine);
printLog("[Start checking conflict stage]");

# Initialize the environment
&checkConflict();

printLog("[End checking conflict stage]\n");

#****************************************************************************
# Remove the duplicated objects
#****************************************************************************
printLog($separateLine);
printLog("[Start removing duplicated objects stage]");

# Initialize the environment
&removeDulicatedObjects();

printLog("[End removing duplicated objects stage]\n");

#****************************************************************************
# Process ALICE Forbid List
#****************************************************************************
printLog($separateLine);
printLog("[Start processing ALICE forbid list stage]");

if (&processAliceForbidList())
{
   printLog("Process completed");
}
else
{
   printLog("Process skipped");
}

printLog("[End processing ALICE forbid list stage]\n");

#****************************************************************************
# Process ZIMAGE Forbid List
#****************************************************************************
printLog($separateLine);
printLog("[Start prcoessing ZIMAGE forbid list stage]");

if (&processZImageForbidList())
{
   printLog("Process completed");
}
else
{
   printLog("Process skipped");
}

printLog("[End prcoessing ZIMAGE fobid list stage]\n");

#****************************************************************************
# Process BOOT_ZIMAGE Forbid List
#****************************************************************************
printLog($separateLine);
printLog("[Start processing BOOT_ZIMAGE forbid list stage]");

if (&processBootZImageForbidList())
{
   printLog("Process completed");
}
else
{
   printLog("Process skipped");
}

printLog("[End processing BOOT_ZIMAGE forbid list stage]\n");

#****************************************************************************
# Process Wildcard
#****************************************************************************
printLog($separateLine);
printLog("[Start processing Wildcard stage]");

if (&processWildcard())
{
   printLog("Process completed");
}
else
{
   printLog("Process skipped");
}

printLog("[End processing Wildcard stage]\n");

#****************************************************************************
# Output to files
#****************************************************************************
printLog($separateLine);
printLog("[Start outputing stage]");
{
   foreach my $objectList (values %outputObjectLists)
   {
      if ($objectList->{"generate"})
      {
         my @filename = fileparse($objectList->{"list_file"});
         printLog("Generate $filename[0]");
         &objListHelper::SortObjectListByCategory($objectList->{"list"});
         &objListHelper::OutputObjectListToObjListFile($objectList->{"list_file"}, $objectList->{"list"}, "        ");
      }
      #elsif (-e $objectList->{"list_file"} and not $objectList->{"manual_modified"})
      #{
      #   unlink $objectList->{"list_file"} or
      #      &objListHelper::ErrorHandler("Fail to delete file $objectList->{list_file} $!");
      #}
   }
}
printLog("[End outputing stage]\n");


sub initialize
{
   unless (-d $destinationListFolder)
   {
       mkpath($destinationListFolder)
         or &objListHelper::ErrorHandler("Fail to create folder $destinationListFolder $!");
   }

   # Check the feature set
   {
      printLog("Checking feature set...");

      # Parse makefile
      if (0 == &FileInfo::Parse_MAKEFILE($makefilePath, \%makefileOptions))
      {
         &objListHelper::ErrorHandler("Fail to parse makefile $makefilePath $!");
      }

      $aliceEnabled = &_checkFeatureOption("ALICE", "ALICE_SUPPORT", "TRUE", \%makefileOptions);
      $bootZImageEnabled = &_checkFeatureOption("BOOT_ZIMAGE", "BOOT_ZIMAGE_SUPPORT", "TRUE", \%makefileOptions);
      $zImageEnabled = &_checkFeatureOption("ZIMAGE", "ZIMAGE_SUPPORT", "TRUE", \%makefileOptions);

      # Check dummy scatter
      {
         my $option = $makefileOptions{"DUMMY_SCATTER_ENABLE"};
         if ((defined $option and $option eq "TRUE" and ($insideMTK == 1)) or ($forceDummyScatter eq "TRUE"))
         {
            debugLog("DUMMY_SCATTER is enabled");
            $isDummyScatter = 1;
         }
      }

      # Check ZIMAGE_CONTENT_POLICY
      {
         my $option = $makefileOptions{"ZIMAGE_CONTENT_POLICY"};
         $zImageContentPolicy = $option if (defined $option);
         debugLog("ZIMAGE_CONTENT_POLICY is $zImageContentPolicy");
      }

      # Check NAND_FLASH_BOOTING
      {
         my $option = $makefileOptions{"NAND_FLASH_BOOTING"};
         $isNandBooting = 1 if ((defined $option) && ($option ne "NONE"));
         debugLog("NAND_FLASH_BOOTING is $option");
      }

      # Check if the feature options are changed
      {
         my $featureOptionChanged = 0;

         if (-e $featureOptionBackupFile)
         {
            $featureOptionChanged = 1 if not &_isFileContentMatch($makefilePath, $featureOptionBackupFile);
         }
         else
         {
            $featureOptionChanged = 1;
         }

         if ($featureOptionChanged or $forceRegenObjectList eq "TRUE")
         {
            copy($makefilePath, $featureOptionBackupFile) or
               &objListHelper::ErrorHandler("Fail to backup file $makefilePath $!");
            _removeObjectLists();
         }
      }
   }

   # Parse source object lists
   {
      printLog("Parsing source object lists...");

      if ($aliceEnabled)
      {
         if ($isNandBooting)
         {
            &_getSourceObjectList("ALICE Forbidden List", $aliceNandForbidListFile, \@aliceForbidList,
                                  \%makefileOptions, $aliceNandForbidListBackupFile);
         }
         else
         {
            &_getSourceObjectList("ALICE Forbidden List", $aliceForbidListFile, \@aliceForbidList,
                                  \%makefileOptions, $aliceForbidListBackupFile);
         }
      }

      if ($bootZImageEnabled)
      {
         &_getSourceObjectList("BOOT_ZIMAGE Forbidden List", $bootZImageForbidListFile, \@bootZImageForbidList,
                               \%makefileOptions, $bootZImageForbidListBackupFile);
      }

      if ($zImageEnabled)
      {
         &_getSourceObjectList("ZIMAGE Forbidden List", $zImageForbidListFile, \@zImageForbidList,
                               \%makefileOptions, $zImageForbidListBackupFile);

         &_getSourceObjectList("ZIMAGE List", $zImageMustListFile, \@zImageMustList,
                               \%makefileOptions, $zImageMustListBackupFile);
      }
   }
}

sub _getSourceFilePath
{
   my $filename = shift;

   my $filePath = "$sourceCSVFolder\\$filename";
   $filePath = "$destinationListFolder\\$filename" if (-e "$destinationListFolder\\$filename");

   return $filePath;
}

sub _checkFeatureOption
{
   my $featureName = shift;
   my $featureOption = shift;
   my $featureEnableValue = shift;
   my $makefileOptions = shift;

   my $result = 0;

   my $option = $makefileOptions->{$featureOption};
   if (defined $option and $option eq $featureEnableValue)
   {
      debugLog("$featureName is enabled");
      $result = 1;
   }

   return $result;
}

sub _isFileContentMatch
{
   my $firstFile = shift;
   my $secondFile = shift;

   if (&CommonUtil::GetFileContent($firstFile) eq &CommonUtil::GetFileContent($secondFile))
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

sub _getSourceObjectList
{
   my $listName = shift;
   my $sourceFile = shift;
   my $listRef = shift;
   my $makefileOptions = shift;
   my $backupFile = shift;
   my $sourceFileChanged = 0;

   debugLog("Get $listName");
   &objListHelper::InputObjectListFromCSVFile($sourceFile, $listRef, $makefileOptions);
   PrintDependency($sourceFile);

   if (-e $backupFile)
   {
      unless (&_isFileContentMatch($sourceFile, $backupFile))
      {
         $sourceFileChanged = 1;

         copy($sourceFile, $backupFile) or
            &objListHelper::ErrorHandler("Fail to backup file $sourceFile $!");
      }
   }
   else
   {
      copy($sourceFile, $backupFile) or
         &objListHelper::ErrorHandler("Fail to backup file $sourceFile $!");

      $sourceFileChanged = 1;
   }

   if ($sourceFileChanged)
   {
      debugLog("$listName changed");
      _removeObjectLists();
   }
   else
   {
      debugLog("$listName not changed");
   }
}

sub _removeObjectLists
{
   debugLog("Delete object lists");
   unlink $_->{"list_file"} foreach (values %outputObjectLists);
}

sub checkConflict
{
   if ($zImageEnabled)
   {
      # Check against zImageForbidList
      {
         my @zmzfList = ();
         my @zmOverlapList = ();
         my @dummy = ();
         my @conflictList = ();

         &objListHelper::SplitObjectListByCheckList(\@zImageMustList, \@zImageForbidList, \@zmzfList, \@zmzfList, \@dummy);
         &objListHelper::SplitObjectListByCheckList(\@zImageForbidList, \@zImageMustList, \@dummy, \@zmOverlapList, \@dummy);

         @dummy = grep(($_->{"library"} ne "Unknown") && &objListHelper::IsObjectAttributeListConflict($_, $_->{"matchedObject"}), @zmzfList);
         @conflictList = map { {"zm" => $_->{"name"}, "zf" => $_->{"matchedObject"}{"name"}} } @dummy;

         @dummy = grep(($_->{"library"} ne "Unknown") && &objListHelper::IsObjectAttributeListConflict($_, $_->{"matchedObject"}), @zmOverlapList);
         push @conflictList, map { {"zf" => $_->{"name"}, "zm" => $_->{"matchedObject"}{"name"}} } @dummy;

         if (0 != scalar(@conflictList))
         {
            printLog("$zImageMustListFileName: $_->{zm} conflicts with $zImageForbidListFileName: $_->{zf}") foreach @conflictList;
            &genFail(GEN_FAIL_OBJECT_CONFLICT_CSV_TO_CSV, $zImageMustListFileName, $zImageForbidListFileName);
         }
      }
   }
}

sub processAliceForbidList
{
   if ($aliceEnabled)
   {
      if ($zImageEnabled)
      {
         my @afList;
         my @afOverlapList;
         my @afzfList;

         &objListHelper::SplitObjectListByCheckList(\@aliceForbidList, \@zImageForbidList, \@afzfList, \@afOverlapList, \@afList);

         &objListHelper::ChangeObjectListAttributeList(\@afList, "+RO");
         &objListHelper::ChangeObjectListAttributeList(\@afOverlapList, "+RO-CODE");
         &objListHelper::ChangeObjectListAttributeList(\@afzfList, "+RO");

         if ($isDummyScatter)
         {
            &_pushToOutputObjectList("ALICE_FORBID_DUMMY", \@afList, "AF_nZF");
            &_pushToOutputObjectList("ROM1_DUMMY", \@afOverlapList, "AF_OVERLAP_ZF");
            &_pushToOutputObjectList("ROM1_DUMMY", \@afzfList, "AF_ZF");
            &_pushToOutputObjectList("ALICE_DUMMY", [], "EMPTY");
         }
         else
         {
            if ($zImageContentPolicy eq "BEST_PERF")
            {
               &_pushToOutputObjectList("ZIMAGE", \@afList, "AF_nZF");
            }
            else
            {
               &_pushToOutputObjectList("ROM1", \@afList, "AF_nZF");
            }
            &_pushToOutputObjectList("ROM1", \@afOverlapList, "AF_OVERLAP_ZF");
            &_pushToOutputObjectList("ROM1", \@afzfList, "AF_ZF");
            &_pushToOutputObjectList("ALICE", [], "EMPTY");
         }
      }
      else
      {
         if ($isDummyScatter)
         {
            if ($isNandBooting)
            {
               &_pushToOutputObjectList("ROM2_DUMMY", \@aliceForbidList, "AF");
            }
            else
            {
               &_pushToOutputObjectList("ROM1_DUMMY", \@aliceForbidList, "AF");
            }
            &_pushToOutputObjectList("ALICE_DUMMY", [], "EMPTY");
         }
         else
         {
            if ($isNandBooting)
            {
               &_pushToOutputObjectList("ROM2", \@aliceForbidList, "AF");
            }
            else
            {
               &_pushToOutputObjectList("ROM1", \@aliceForbidList, "AF");
            }
            &_pushToOutputObjectList("ALICE", [], "EMPTY");
         }
      }

      return 1;
   }
   else
   {
      return 0;
   }
}

sub processZImageForbidList
{
   if ($zImageEnabled)
   {
      if ($aliceEnabled)
      {
         my @zfUnmatchedList = grep((not $_->{"matched"}), @zImageForbidList);

         my @zf_RList;
         my @zf_AList;
         my @zfafList;
         my @zfOverlapList;
         my @zfOnlyList;

         &objListHelper::SplitObjectListByCheckList(\@zfUnmatchedList, \@aliceForbidList, \@zfafList, \@zfOverlapList, \@zfOnlyList);

         # ZFAF list should have been empty if there were no wildcard symbol
         # Append this list to ZF only list since the priority is lower for wildcard
         push @zfOnlyList, @zfafList;
         &objListHelper::SortObjectListByCategory(\@zfOnlyList);

         # Specify the ZF overlap list to ROM1 with +RO-CODE, +RO-DATA since the libraries include them are in AF list
         foreach my $object (@zfOverlapList)
         {
            if ($object->{"attributes"}[0] eq "+RO")
            {
               $object->{"attributes"}[0] = "+RO-CODE";
               $object->{"attributes"}[1] = "+RO-DATA";
               push @zf_RList, $object;
            }
            else
            {
               push @zf_RList, $object;
            }
         }

         # The data part is in ROM1 and code part is in ALICE for ZF only list
         foreach my $object (@zfOnlyList)
         {
            if ($object->{"attributes"}[0] eq "+RO")
            {
               my %newObject = %$object;
               $object->{"attributes"}[0] = "+RO-DATA";
               push @zf_RList, $object;

               $newObject{"attributes"} = ["+RO"];
               push @zf_AList, \%newObject;
            }
            elsif ($object->{"attributes"}[0] eq "+RO-CODE")
            {
               push @zf_AList, $object;

               if (defined $object->{"attributes"}[1] and $object->{"attributes"}[1] eq "+RO-DATA")
               {
                  my %newObject = %$object;
                  $newObject{"attributes"} = ["+RO-DATA"];
                  push @zf_RList, \%newObject;
                  splice @{$object->{"attributes"}}, -1;
               }
            }
            else
            {
               push @zf_RList, $object;
            }
         }

         if ($isDummyScatter)
         {
            &_pushToOutputObjectList("ROM1_DUMMY", \@zf_RList, "ZF_R");
            &_pushToOutputObjectList("ALICE_DUMMY", \@zf_AList, "ZF_A");

            &_pushToOutputObjectList("ZIMAGE_DUMMY", [], "EMPTY");
         }
         else
         {
            &_pushToOutputObjectList("ROM1", \@zf_RList, "ZF_R");
            &_pushToOutputObjectList("ALICE", \@zf_AList, "ZF_A");

            &_pushToOutputObjectList("ZIMAGE", [], "EMPTY");
         }
      }
      else
      {
         if ($isDummyScatter)
         {
            &_pushToOutputObjectList("ROM1_DUMMY", \@zImageForbidList, "ZF");
            &_pushToOutputObjectList("ZIMAGE_DUMMY", [], "EMPTY");
         }
         else
         {
            &_pushToOutputObjectList("ROM1", \@zImageForbidList, "ZF");
            &_pushToOutputObjectList("ZIMAGE", [], "EMPTY");
         }
      }

      return 1;
   }
   else
   {
      return 0;
   }
}

sub processBootZImageForbidList
{
   if ($bootZImageEnabled)
   {
      my @bzList;
      my @afzfbzfList;
      my @afzfbzfOverlapList;

      # BOOT_ZIMAGE library problem workaround
      my @bootZImageNormalForbidList;
      my @bootZImageWorkaroundForbidList;

      foreach my $object (@bootZImageForbidList)
      {
         if ($object->{"category"} eq "Workaround")
         {
            push @bootZImageWorkaroundForbidList, $object;
         }
         else
         {
            push @bootZImageNormalForbidList, $object;
         }
      }

      if ($isDummyScatter)
      {
        #&objListHelper::SplitObjectListByCheckList(\@{$outputObjectLists{"ROM1_DUMMY"}{"list"}}, \@bootZImageForbidList, \@afzfbzfList, \@afzfbzfOverlapList, \@bzList);
         &objListHelper::SplitObjectListByCheckList(\@{$outputObjectLists{"ROM1_DUMMY"}{"list"}}, \@bootZImageNormalForbidList, \@afzfbzfList, \@afzfbzfOverlapList, \@bzList);
      }
      else
      {
        #&objListHelper::SplitObjectListByCheckList(\@{$outputObjectLists{"ROM1"}{"list"}}, \@bootZImageForbidList, \@afzfbzfList, \@afzfbzfOverlapList, \@bzList);
         &objListHelper::SplitObjectListByCheckList(\@{$outputObjectLists{"ROM1"}{"list"}}, \@bootZImageNormalForbidList, \@afzfbzfList, \@afzfbzfOverlapList, \@bzList);
      }

      # BOOT_ZIMAGE library problem workaround
      {
         # Force the workaround libraries to ROM1
         my %bootZImageWorkaourndForbidHash = map { $_->{"name"} => 1 } @bootZImageWorkaroundForbidList;
         my @tempBZList = @bzList;
         @bzList = ();

         foreach my $object (@tempBZList)
         {
            if (exists $bootZImageWorkaourndForbidHash{$object->{"name"}})
            {
               push @afzfbzfList, $object;
            }
            else
            {
               push @bzList, $object;
            }
         }
      }

      if ($isDummyScatter)
      {
         &_pushToOutputObjectList("BOOT_ZIMAGE_DUMMY", \@bzList, "AFZF_nBZ");

         @{$outputObjectLists{"ROM1_DUMMY"}{"list"}} = ();
         debugLog("Empty ROM1");
         &_pushToOutputObjectList("ROM1_DUMMY", \@afzfbzfList, "AFZFBZ");
         &_pushToOutputObjectList("ROM1_DUMMY", \@afzfbzfOverlapList, "BZ_OVERLAP_AFZF");
      }
      else
      {

         &_pushToOutputObjectList("BOOT_ZIMAGE", \@bzList, "AFZF_nBZ");

         @{$outputObjectLists{"ROM1"}{"list"}} = ();
         debugLog("Empty ROM1");
         &_pushToOutputObjectList("ROM1", \@afzfbzfList, "AFZFBZ");
         &_pushToOutputObjectList("ROM1", \@afzfbzfOverlapList, "BZ_OVERLAP_AFZF");
      }

      return 1;
   }
   else
   {
      return 0;
   }
}

sub _pushToOutputObjectList
{
   my $objectListName = shift;
   my $objectListRef = shift;
   my $pushedListName = shift;

   push @{$outputObjectLists{$objectListName}{"list"}}, @$objectListRef;
   debugLog("Push $pushedListName to $objectListName");

   if (-e $outputObjectLists{$objectListName}{"list_file"})
   {
      #if ($isSourceChanged)
      #{
      #   $outputObjectLists{$objectListName}{"generate"} = 1;
      #}
   }
   else
   {
      $outputObjectLists{$objectListName}{"generate"} = 1;
   }
}

sub removeDulicatedObjects
{
   if ($zImageEnabled)
   {
      # Filter out the objects in zImageMustList
      #{
      #   if ($isDummyScatter)
      #   {
      #      &_removeObjectByCheckList($outputObjectLists{"ROM1_DUMMY"}{"list"}, \@zImageMustList, "ROM1_DUMMY", $zImageMustListFileName);
      #      &_removeObjectByCheckList($outputObjectLists{"BOOT_ZIMAGE_DUMMY"}{"list"}, \@zImageMustList, "BOOT_ZIMAGE_DUMMY", $zImageMustListFileName);
      #      &_removeObjectByCheckList($outputObjectLists{"ZIMAGE_DUMMY"}{"list"}, \@zImageMustList, "ZIMAGE_DUMMY", $zImageMustListFileName);
      #      &_removeObjectByCheckList($outputObjectLists{"ALICE_DUMMY"}{"list"}, \@zImageMustList, "ALICE_DUMMY", $zImageMustListFileName);
      #      &_removeObjectByCheckList($outputObjectLists{"ALICE_FORBID_DUMMY"}{"list"}, \@zImageMustList, "ALICE_FORBID_DUMMY", $zImageMustListFileName);
      #   }
      #   else
      #   {
      #      &_removeObjectByCheckList($outputObjectLists{"ROM1"}{"list"}, \@zImageMustList, "ROM1", $zImageMustListFileName);
      #      &_removeObjectByCheckList($outputObjectLists{"BOOT_ZIMAGE"}{"list"}, \@zImageMustList, "BOOT_ZIMAGE", $zImageMustListFileName);
      #      &_removeObjectByCheckList($outputObjectLists{"ZIMAGE"}{"list"}, \@zImageMustList, "ZIMAGE", $zImageMustListFileName);
      #      &_removeObjectByCheckList($outputObjectLists{"ALICE"}{"list"}, \@zImageMustList, "ALICE", $zImageMustListFileName);
      #   }
      #}

      &_removeObjectByCheckList(\@aliceForbidList, \@zImageMustList, $aliceForbidListFileName, $zImageMustListFileName);
      &_removeObjectByCheckList(\@bootZImageForbidList, \@zImageMustList, $bootZImageForbidListFileName, $zImageMustListFileName);
   }
}

sub _removeObjectByCheckList
{
   my $sourceList = shift;
   my $checkList = shift;
   my $sourceListName = shift;
   my $checkListFileName = shift;

   # Remove the matched list
   {
      my @matchList = ();
      my @unmatchList = ();
      &objListHelper::SplitObjectListByCheckList($sourceList, $checkList, \@matchList, \@matchList, \@unmatchList);
      #@matchList = grep($_->{"library"} ne "Unknown", @matchList);
      map { &objListHelper::RemoveDuplicateObjectAttribute($_, $_->{"matchedObject"}) } @matchList;
      push @unmatchList, @matchList;
      @$sourceList = grep(scalar(@{$_->{"attributes"}}) != 0, @unmatchList);

   }

   # Check if there is conflict
   {
      my @dummy = ();
      my @conflictList = ();
      &objListHelper::SplitObjectListByCheckList($checkList, $sourceList, \@dummy, \@conflictList, \@dummy);
      @conflictList = grep(&objListHelper::IsObjectAttributeListConflict($_, $_->{"matchedObject"}), @conflictList);

      if(scalar(@conflictList) != 0)
      {
         printLog("$checkListFileName: $_->{name} conflicts with $sourceListName: $_->{matchedObject}{name}") foreach @conflictList;
         &genFail(GEN_FAIL_OBJECT_CONFLICT_CSV_TO_LIST, $checkListFileName, $sourceListName);
      }
   }
}

sub processWildcard
{
   if ($isNandBooting)
   {
      if ($aliceEnabled)
      {
         unless ($isDummyScatter)
         {
            &_pushToOutputObjectList("ALICE", [objListHelper::RO_CODE_WILDCARD], "RO-CODE wildcard");
            &_pushToOutputObjectList("ROM2_RODATA", [objListHelper::RO_DATA_WILDCARD], "RO-DATA wildcard");
         }
         else
         {
            &_pushToOutputObjectList("ALICE_DUMMY", [objListHelper::RO_CODE_WILDCARD], "RO-CODE wildcard");
            &_pushToOutputObjectList("ROM2_RODATA_DUMMY", [objListHelper::RO_DATA_WILDCARD], "RO-DATA wildcard");
         }
      }
      return 1;
   }
   else
   {
      # When ZIMAGE or ALICE is enabled in NOR project, the wildcard should be generated by obj_list_gen while normal scatter
      # When dummy scatter, the wildcard will be generated by scatter gen
      unless ($isDummyScatter)
      {
         my @regionTable;
         # ZIMAGE, BOOT_ZIMAGE, ALICE
         $regionTable[0][0][0] = {"BEST_PERF" => ["ROM1", "ROM1"], "FIT_ROM" => ["ROM1", "ROM1"], "MUST_ONLY" => ["ROM1", "ROM1"]};
         $regionTable[0][0][1] = {"BEST_PERF" => ["ALICE", "ROM1"], "FIT_ROM" => ["ALICE", "ROM1"], "MUST_ONLY" => ["ALICE", "ROM1"]};
         $regionTable[0][1][0] = undef;
         $regionTable[0][1][1] = undef;
         $regionTable[1][0][0] = {"BEST_PERF" => ["ZIMAGE", "ZIMAGE"], "FIT_ROM" => ["ROM1", "ROM1"], "MUST_ONLY" => ["ROM1", "ROM1"]};
         $regionTable[1][0][1] = {"BEST_PERF" => ["ZIMAGE", "ZIMAGE"], "FIT_ROM" => ["ALICE", "ROM1"], "MUST_ONLY" => ["ALICE", "ROM1"]};
         $regionTable[1][1][0] = {"BEST_PERF" => ["ZIMAGE", "ZIMAGE"], "FIT_ROM" => ["ROM1", "ROM1"], "MUST_ONLY" => ["ROM1", "ROM1"]};
         $regionTable[1][1][1] = {"BEST_PERF" => ["ZIMAGE", "ZIMAGE"], "FIT_ROM" => ["ALICE", "ROM1"], "MUST_ONLY" => ["ALICE", "ROM1"]};

         &_pushToOutputObjectList($regionTable[$zImageEnabled][$bootZImageEnabled][$aliceEnabled]
                                              {$zImageContentPolicy}[0], [objListHelper::RO_CODE_WILDCARD], "RO-CODE wildcard");
         &_pushToOutputObjectList($regionTable[$zImageEnabled][$bootZImageEnabled][$aliceEnabled]
                                              {$zImageContentPolicy}[1], [objListHelper::RO_DATA_WILDCARD], "RO-DATA wildcard");
         return 1;
      }
      else
      {
         return 0;
      }
   }
}

#****************************************************************************
# subroutine:  genFailLog
# description: Output the config fail information.
# input:       Fail reason message, recommendation message
# output:      None
#****************************************************************************
sub genFailLog
{
   my ($failReason, $recommend) = @_;

   my $message = "Error: $failReason\nRecommend: $recommend\n";
   printLog("\n$message");

   &objListHelper::ErrorHandler("$message");
}

#****************************************************************************
# subroutine:  genFail
# description: Indicate the configuration is failed.
# input:       Fail code (constant with GEN_FAIL_XXXX)
# output:      None
#****************************************************************************
sub genFail
{
   my $failCode = shift;
   my $failReason;
   my $recommend;

   if ($failCode == GEN_FAIL_OBJECT_CONFLICT_CSV_TO_CSV)
   {
      my $first = shift;
      my $second = shift;
      $failReason = "Conflict between $first and $second";
      $recommend = "Please remove the conflict objects from CSV file";
   }
   elsif ($failCode == GEN_FAIL_OBJECT_CONFLICT_CSV_TO_LIST)
   {
      my $first = shift;
      my $second = shift;
      $failReason = "Conflict between $first and $second";
      $recommend = "Please wrap the conflict objects with pragma to move them to the target region instead of listing them in $first";
   }
   else
   {
      $failReason = "Unknown.";
      $recommend = "Please call for help";
   }

   &genFailLog($failReason, $recommend);
}

sub printLog
{
   print "$_[0]\n";
}

sub debugLog
{
   if ($DEBUG)
   {
      printLog("\t$_[0]");
   }
}
