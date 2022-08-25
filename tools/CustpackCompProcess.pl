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
#*   CustpackCompProcess.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This file implemented the MBA ZIMAGE post build process.
#*
#*
#* Author:
#* -------
#*   Timon Lu (mtk03814)
#*
#*****************************************************************************

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
use warnings;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use vivaHelper;
use zImageProcess;
use File::Copy;

#****************************************************************************
# Constants
#****************************************************************************
use constant SUPPORT_ZIMAGE => 1;
use constant NOT_SUPPORT_ZIMAGE  => 0;
use constant RESOURCE_BIN_EXISTED => 1;
use constant SYSTEM_JUMP_TABLE_NUM  => 5;
use constant PREAMBLE_STRUCT_SIZE  => 108;
use constant GFH_STRUCT_SIZE  => 56;
use constant PREAMBLE_MAGIC  => 0x12345678;
use constant CUSTPACK_NUM => 0x1;

#****************************************************************************
# Arguments
#****************************************************************************
&vivaHelper::ErrorHandler("Insufficient arguments!", __LINE__, __FILE__)
   unless scalar(@ARGV) == 5;

my ($lisFilePath, $binaryFolder, $custpackINIPath, $makefilePath, $customFolder) = @ARGV;

$lisFilePath  =~ s/^.\\|^\\//;
$binaryFolder =~ s/^.\\|^\\//;
$custpackINIPath =~ s/^.\\|^\\//;
$makefilePath =~ s/^.\\|^\\//;
$customFolder =~ s/^.\\|^\\//;


#****************************************************************************
#Global variable
#****************************************************************************
# Binary name
my $JTBinName = "JUMP_TABLE";
my $JTBin = "$binaryFolder\\$JTBinName";
my $JTBinGFH = $JTBin."_GFH";
my $JTBinBody = $JTBin."_Body";
my $JTBinSig = $JTBin."_Sig";
my $JTBinFinal = $JTBin."_Final";
my $custpackBINFolder;
# File path
my $featureConfigFilePath = "$customFolder\\custom_FeatureConfig.h";
# Feature config option
my %featureConfig;


my @jumpTableInfo;
my %resourcePreamble;
#****************************************************************************
# Process
#****************************************************************************
printLog("Start CustPack Compression post-build processing...");

# Initialize for makefile feature option parsing
&vivaHelper::Initialize(vivaHelper::CONFIG_TYPE, $makefilePath, $lisFilePath);

# Parse feature config file
printLog("Parsing feature configuration file");
&parseFeatureConfigFile(\%featureConfig);

my $MBAEnabled = &vivaHelper::GetMakefileOption("MULTIPLE_BINARY_FILES");
my $ZImageEnabled = &vivaHelper::GetMakefileOption("ZIMAGE_SUPPORT");
# This script support only when MBA is enabled
unless (defined $MBAEnabled and defined $ZImageEnabled and $MBAEnabled eq "TRUE"){
   &ErrorHandler("MBA Feature Option disable or missed!", __LINE__, __FILE__); 
}
&ParseCustPackINI();

&OutputBatchFile();

my $MBABinary = "CUSTPACK_ROM";
my @MBABinaryList = ("$custpackBINFolder\\CUSTPACK_ROM");

&BackupBinary(@MBABinaryList);
# procedure change depends on whether ZImage is enable or not
if($ZImageEnabled eq "TRUE"){
    &ReadJumpTableFromBin();
    &CompressedProcess($MBABinary, SUPPORT_ZIMAGE);
    &WriteJumpTableIntoBin();
}

printLog("End CustPack Comp processing");

exit 0;

#****************************************************************************
# subroutine:  ParseCustPackINI
# description: backup binary in current folder 
# input: an array of backup binary name
# output: none
#****************************************************************************
sub ParseCustPackINI
{
	 open my $INI_BIN_HANDLE, "<$custpackINIPath" or
      &vivaHelper::ErrorHandler("Cannot open resource binary $custpackINIPath: $!", __FILE__, __LINE__);
   binmode $INI_BIN_HANDLE;

   my $INISize = -s $custpackINIPath;
   
   my $INIRead;
   sysread ($INI_BIN_HANDLE, $INIRead, $INISize);
   if ($INIRead =~ /OutputBin_PATH = \"Z:\\\.\\(.*\\).*\"/i)
   {
      $custpackBINFolder = $1;
   }
}
#****************************************************************************
# subroutine:  BackupBinary
# description: backup binary in current folder 
# input: an array of backup binary name
# output: none
#****************************************************************************
sub OutputBatchFile
{
   my $batfilepath = "CustpackComp.bat";
   my $compPerl = "tools\\CustpackCompProcess.pl";
	 
   open my $BAT_BIN_HANDLE, ">$batfilepath" or
      &vivaHelper::ErrorHandler("Cannot create $batfilepath: $!", __FILE__, __LINE__);
   my $command = "$compPerl $lisFilePath $binaryFolder $custpackINIPath $makefilePath $customFolder";
   print $BAT_BIN_HANDLE $command."\n";
   print $BAT_BIN_HANDLE "pause";
   close $BAT_BIN_HANDLE;
}
#****************************************************************************
# subroutine:  BackupBinary
# description: backup binary in current folder 
# input: an array of backup binary name
# output: none
#****************************************************************************
sub BackupBinary(){
   my @backupList = @_;
   
   foreach my $binary (@backupList){
   	  my $binarybackup = "$binary"."_backup";   	  
      copy($binary, $binarybackup) or
         &vivaHelper::ErrorHandler("Cannot backup binary $binarybackup: $!", __FILE__, __LINE__);

   }
}  
#****************************************************************************
# subroutine:  CompressedProcess
# description: MBA post build main function
#              
# input:  resource bin name, resource bin number, support ZImage or not
# output: none
#****************************************************************************
sub CompressedProcess
{  	 
   my $binaryname = shift;
   my $isSupportZImage = shift;	 
   my $binary = "$custpackBINFolder\\$binaryname";	 	 
   my $binaryBackup = "$binary"."_backup" ;
   my $binaryGFH = "$binary"."_GFH";
   my $binaryBody = "$binary"."_Body";
   my $binaryPreamble = "$binary"."_Preamble";
   my $binaryContent = "$binary"."_Content";
   my $binaryBody_org = "$binaryBody"."_org";
   my $binaryFinal = "$binary"."_final";
   my $binarySig = "$binary"."_Sig"; 
   my @concatenateResbinaryList;
   my $compressedTotalSize;
 
   #decide whether to split resource by binary or not
   if(&vivaHelper::IsSV5() == 1){
      printLog("Split $binary ...");
	    &vivaHelper::SplitBinaryByGFH($binary, $binaryGFH, $binaryBody, $binarySig);
	 }
	 elsif(&vivaHelper::IsSV5() == 0){
	 	  printLog("Copy $binary to $binaryBody ...");
      copy($binary, $binaryBody) or
         &vivaHelper::ErrorHandler("Cannot backup binary $binary: $!", __FILE__, __LINE__);
	 }
	 #read Preamble from BIN
	 ReadPreambleFromBIN($binaryBody);
	 #Copy Preamble from jump table to custpack Preamble
	 $jumpTableInfo[CUSTPACK_NUM]{"LoadAddress"} = $resourcePreamble{"LoadAddress"};
	 $jumpTableInfo[CUSTPACK_NUM]{"ExecAddress"} = $resourcePreamble{"ExecAddress"};
	 #Split Preamble from BIN
	 SplitPreambleFromBIN($binaryBody, $binaryPreamble, $binaryContent);
	 
	 # Decide to whether to compress resource body or not
	 if($isSupportZImage == SUPPORT_ZIMAGE){
	 	  if($featureConfig{$binaryname."_COMPRESS"} == SUPPORT_ZIMAGE){
         printLog("Compressing $binaryContent ...");
         &zImageProcess::CompressByPartition($binaryContent, $binaryBody_org, undef, $resourcePreamble{"ExecAddress"});
      }
      elsif($featureConfig{$binaryname."_COMPRESS"} == NOT_SUPPORT_ZIMAGE){
      	 printLog("Don't compress by FeatureConfig. Rename $binaryContent to $binaryBody_org ...");
      	 copy($binaryContent, $binaryBody_org) or
            &vivaHelper::ErrorHandler("Cannot backup binary $binaryContent: $!", __FILE__, __LINE__);
      }
      else{
      	 ErrorHandler ($binaryname."_COMPRESS in custom_FeatureConfig.h isn't equal to 0 or 1", __FILE__, __LINE__);
      }
   }    
   elsif($isSupportZImage == NOT_SUPPORT_ZIMAGE){
      printLog("Don't support compression. Rename $binaryContent to $binaryBody_org ...");
      copy($binaryContent, $binaryBody_org) or
         &vivaHelper::ErrorHandler("Cannot backup binary $binaryContent: $!", __FILE__, __LINE__);
   }
   #Calculate total size
   
   my $binaryContentSize = -s $binaryContent;   
   my $binaryPreambleSize = -s $binaryPreamble;
   my $binaryGFHSize;
   my $binarySigSize;
   if(&vivaHelper::IsSV5() == 1){
   	  $binaryGFHSize  = -s $binaryGFH;
   	  $binarySigSize  = -s $binarySig;
      $compressedTotalSize = $binaryGFHSize + $binaryPreambleSize + $binaryContentSize + $binarySigSize;
      printLog("Total Size: $compressedTotalSize = $binaryGFHSize + $binaryPreambleSize + $binaryContentSize + $binarySigSize");
   }
   elsif(&vivaHelper::IsSV5() == 0){
   	  $compressedTotalSize = $binaryPreambleSize + $binaryContentSize;
      printLog("Total Size: $compressedTotalSize = $binaryPreambleSize + $binaryContentSize;");
   }
   
   my $reservedSize = $featureConfig{"CONFIG_".$binaryname."_MAX_COMPRESSED_SIZE"};
   # Modify compress size in resource preamble & jump table
   if($featureConfig{$binaryname."_COMPRESS"} == SUPPORT_ZIMAGE){
      if($featureConfig{"CONFIG_".$binaryname."_MAX_COMPRESSED_SIZE"} < $compressedTotalSize){
      	  &ErrorHandler("Compress size($compressedTotalSize) exceed reserve size($reservedSize), ".
      	                "please modify CONFIG_CUSTPACK_ROM_MAX_COMPRESSED_SIZE in custom_FeatureConfig.h\n".
      	                "After modification, please m sysgen, m c,r custom to rebuild full load\n", __FILE__, __LINE__);
      }
      else {
         $resourcePreamble{"CompressedSize"} = $featureConfig{"CONFIG_".$binaryname."_MAX_COMPRESSED_SIZE"};
         $jumpTableInfo[CUSTPACK_NUM]{"CompressedSize"} = $resourcePreamble{"CompressedSize"};	
      }
   }
   else{
      $resourcePreamble{"CompressedSize"} = $compressedTotalSize;
      $jumpTableInfo[CUSTPACK_NUM]{"CompressedSize"} = $resourcePreamble{"CompressedSize"};
   }
   # Modify compress or not in resource preamble & jump table
   $resourcePreamble{"Compressed"} = $featureConfig{$binaryname."_COMPRESS"};
   $jumpTableInfo[CUSTPACK_NUM]{"Compressed"} = $resourcePreamble{"Compressed"};
   # Modify Project ID in resource preamble & jump table
   $jumpTableInfo[CUSTPACK_NUM]{"ProjectID"} = $resourcePreamble{"ProjectID"};
   
   # Fill-in compress size in the resource preamble
   FillInfoToResourceBINPreamble($binaryPreamble);
   # Modify GFH Info
   if(&vivaHelper::IsSV5() == 1){
      ModifyGFHInfo($binaryGFH, $compressedTotalSize);
   }
   
   # Concatenate resource BIN
   if(&vivaHelper::IsSV5() == 1){
      @concatenateResbinaryList = ($binaryGFH, $binaryPreamble, $binaryContent, $binarySig);
   }
   elsif(&vivaHelper::IsSV5() == 0){
   	  @concatenateResbinaryList = ($binaryPreamble, $binaryContent);
   }
   printLog("Concatenating $binaryFinal ...");
   
   open my $BIN_HANDLE, ">$binaryFinal" or
      &vivaHelper::ErrorHandler("Cannot open file $binaryFinal: $!", __FILE__, __LINE__);
   binmode $BIN_HANDLE;   
   &vivaHelper::ConcatenateBinary($BIN_HANDLE, \@concatenateResbinaryList);      
   close $BIN_HANDLE;
   
   printLog("Deleting temporary file ...");
   my @deleteList;
   if(&vivaHelper::IsSV5() == 1){
      @deleteList = ($binary, $binaryGFH, $binaryPreamble, $binaryBody, $binaryContent, $binaryBody_org, $binarySig);
   }
   elsif(&vivaHelper::IsSV5() == 0){
   	  @deleteList = ($binary, $binaryPreamble, $binaryBody, $binaryContent, $binaryBody_org);
   }
   DeleteTmpBinary(\@deleteList);
   
   rename ($binaryFinal, $binary);
      
   return $compressedTotalSize;
}



sub ReadPreambleFromBIN
{
	 my $binPath = shift;
	 my $content;
	 my @result;
	 
	 open RESOURCE_BIN_HANDLE, "<$binPath" or
      &vivaHelper::ErrorHandler("Cannot open resource binary $binPath: $!", __FILE__, __LINE__);
   binmode RESOURCE_BIN_HANDLE;
   
   sysread (RESOURCE_BIN_HANDLE, $content, PREAMBLE_STRUCT_SIZE);
   
   @result = unpack("a64a6SSSLLLLLLLL", $content);
   	  
   $resourcePreamble{"ProjectID"} = $result[0];
   $resourcePreamble{"Vpattern"} = $result[1];
   $resourcePreamble{"Version"} = $result[2];
   $resourcePreamble{"Compressed"} = $result[3];
   $resourcePreamble{"Existed"} = $result[4];
   $resourcePreamble{"LoadAddress"} = $result[5];
   $resourcePreamble{"CompressedSize"} = $result[6];
   $resourcePreamble{"MAXRAMSize"} = $result[7];
   $resourcePreamble{"Resource_version"} = $result[8];
   $resourcePreamble{"ExecAddress"} = $result[9];
   $resourcePreamble{"TableSize"} = $result[10];
   $resourcePreamble{"ContentSize"} = $result[11];
   $resourcePreamble{"Magic"} = $result[12];
  
   close RESOURCE_BIN_HANDLE;
   	  
}
#****************************************************************************
# subroutine:  WriteJumpTableIntoBin
# description: write jump table information in @jumpTableInfo to $JTBinBody
#              , and concatenate $JTBinGFH, $JTBinBody, $JTBinSig into $JTBin
#              There are no arguments because global variable is used
# input:   none
# output:  none    
#****************************************************************************
sub WriteJumpTableIntoBin
{
	 open my $JUMPBODY_BIN_HANDLE, ">$JTBinBody" or
      &vivaHelper::ErrorHandler("Cannot open resource binary $JTBinBody: $!", __FILE__, __LINE__);
   binmode $JUMPBODY_BIN_HANDLE;
   
	 my $content;
	 my @result;
	 my @ConcatenateJumpTablebinaryList;
	 my @deleteList;
	 
   for(my $i = 0; $i < SYSTEM_JUMP_TABLE_NUM; $i++){
   	  $result[0] = $jumpTableInfo[$i]{"ProjectID"};
   	  $result[1] = $jumpTableInfo[$i]{"Vpattern"};
   	  $result[2] = $jumpTableInfo[$i]{"Version"};
   	  $result[3] = $jumpTableInfo[$i]{"Compressed"};
   	  $result[4] = $jumpTableInfo[$i]{"Existed"};
   	  $result[5] = $jumpTableInfo[$i]{"LoadAddress"};
   	  $result[6] = $jumpTableInfo[$i]{"CompressedSize"};
   	  $result[7] = $jumpTableInfo[$i]{"MAXRAMSize"};
   	  $result[8] = $jumpTableInfo[$i]{"Resource_version"};
   	  $result[9] = $jumpTableInfo[$i]{"ExecAddress"};
   	  $result[10] = $jumpTableInfo[$i]{"TableSize"};
   	  $result[11] = $jumpTableInfo[$i]{"ContentSize"};
   	  $result[12] = $jumpTableInfo[$i]{"Magic"};
   	  
   	  $content = pack("a64a6SSSLLLLLLLL", @result);
   	  print $JUMPBODY_BIN_HANDLE $content;
   } # end of for loop
   
   close $JUMPBODY_BIN_HANDLE;
   
   open my $JUMP_BIN_HANDLE, ">$custpackBINFolder\\$JTBinName" or
      &vivaHelper::ErrorHandler("Cannot open resource binary JUMP_TABLE_Final: $!", __FILE__, __LINE__);
   binmode $JUMP_BIN_HANDLE;
   
   if(&vivaHelper::IsSV5() == 1){
      @ConcatenateJumpTablebinaryList = ($JTBinGFH, $JTBinBody, $JTBinSig);
   }
   elsif(&vivaHelper::IsSV5() == 0){
   	  @ConcatenateJumpTablebinaryList = ($JTBinBody);
   }
   &vivaHelper::ConcatenateBinary($JUMP_BIN_HANDLE, \@ConcatenateJumpTablebinaryList);
   close $JUMP_BIN_HANDLE;
   
   if(&vivaHelper::IsSV5() == 1){
      @deleteList = ($JTBinGFH, $JTBinBody, $JTBinSig);
   }
   elsif(&vivaHelper::IsSV5() == 0){
   	  @deleteList = ($JTBinBody);
   }
   DeleteTmpBinary(\@deleteList);
   
}
#****************************************************************************
# subroutine:  ReadJumpTableFromBin
# description: read jump table from JUMP_TABLE , and assign values into @jumpTableInfo
#              if jump table structure(Preamble) is changed, this function should be changed, too. 
# input:   none
# output:  none
#****************************************************************************
sub ReadJumpTableFromBin
{   
   my $content;
	 my @result;
   
   if(&vivaHelper::IsSV5() == 1){
       &vivaHelper::SplitBinaryByGFH($JTBin, $JTBinGFH, $JTBinBody, $JTBinSig);     	 
   }
   elsif(&vivaHelper::IsSV5() == 0){
   	   copy($JTBin, $JTBinBody) or
         &vivaHelper::ErrorHandler("Cannot backup binary $JTBin: $!", __FILE__, __LINE__);
   }
	 
   open RESOURCE_BIN_HANDLE, "<$JTBinBody" or
      &vivaHelper::ErrorHandler("Cannot open resource binary $JTBin: $!", __FILE__, __LINE__);
   binmode RESOURCE_BIN_HANDLE;
            
   
   for(my $i = 0; $i < SYSTEM_JUMP_TABLE_NUM; $i++){
   	  sysread (RESOURCE_BIN_HANDLE, $content, PREAMBLE_STRUCT_SIZE);
   	  @result = unpack("a64a6SSSLLLLLLLL", $content);
   	  
   	  $jumpTableInfo[$i]{"ProjectID"} = $result[0];
   	  $jumpTableInfo[$i]{"Vpattern"} = $result[1];
   	  $jumpTableInfo[$i]{"Version"} = $result[2];
   	  $jumpTableInfo[$i]{"Compressed"} = $result[3];
   	  $jumpTableInfo[$i]{"Existed"} = $result[4];
   	  $jumpTableInfo[$i]{"LoadAddress"} = $result[5];
   	  $jumpTableInfo[$i]{"CompressedSize"} = $result[6];
   	  $jumpTableInfo[$i]{"MAXRAMSize"} = $result[7];
   	  $jumpTableInfo[$i]{"Resource_version"} = $result[8];
   	  $jumpTableInfo[$i]{"ExecAddress"} = $result[9];
   	  $jumpTableInfo[$i]{"TableSize"} = $result[10];
   	  $jumpTableInfo[$i]{"ContentSize"} = $result[11];
   	  $jumpTableInfo[$i]{"Magic"} = $result[12];
   	  
   	  if($jumpTableInfo[$i]{"Magic"} != PREAMBLE_MAGIC){
   	     ErrorHandler ("Jump table [$i] magic number is not equal 0x12345678 : $!", __FILE__, __LINE__);
   	  }	
   } # end of for loop
   
   close RESOURCE_BIN_HANDLE;
}
#****************************************************************************
# subroutine:  DeleteTmpBinary
# description: Remove binary from build folder
# input:       array reference of binary name
# output:      
#****************************************************************************
sub DeleteTmpBinary
{
	my $binaryArrayRef = shift;
	#my @arrayRef = $$binaryArrayRef
	
	foreach my $binary (@$binaryArrayRef)
	{
		unlink("$binary")  or ErrorHandler("Cannot delete file $binary: $!", __FILE__, __LINE__);
	}
}
#****************************************************************************
# subroutine:  SplitPreambleFromBIN
# description: Split Preamble and jump table from resource bin
#              binary body -> (binary preamble, binary content)
# input:       binary body, binary preamble , binary content
# output:      None
#****************************************************************************
sub SplitPreambleFromBIN
{
	  my $binaryBody = shift;
	  my $binaryPreamble = shift;
	  my $binaryContent = shift;
	  
	  my $binaryBodySize  = -s $binaryBody;
	  my $binaryContentSize = $binaryBodySize - $resourcePreamble{"TableSize"};
	  printLog($binaryBodySize." ".$binaryContentSize);
	  my @sizeArray = ($resourcePreamble{"TableSize"}, $binaryContentSize);
	  my @filenameArray = ($binaryPreamble, $binaryContent);
	  
	  &vivaHelper::SplitBinaryBySize($binaryBody, \@sizeArray, \@filenameArray);
}
#****************************************************************************
# subroutine:  ModifyGFHInfo
# description: Modify GFH m_load_addr since m_load_addr will change 
#              according to previous resource bin
# input:       GFH path, resource bin number
# output:      none
#****************************************************************************
sub ModifyGFHInfo
{
   my $binaryGFH = shift;
   my $binsize = shift;
   my %GFHInfo;
   my $GFH_BIN_HANDLE;
   # Read GFH information
   open $GFH_BIN_HANDLE, "<$binaryGFH" or
     &vivaHelper::ErrorHandler("Cannot open file $binaryGFH: $!", __FILE__, __LINE__);
   binmode $GFH_BIN_HANDLE;
   &vivaHelper::ReadGFHFileInfo($GFH_BIN_HANDLE, \%GFHInfo);
   close $GFH_BIN_HANDLE;
   # Modify load address in GFH
   $GFHInfo{"m_load_addr"} = $resourcePreamble{"LoadAddress"} - GFH_STRUCT_SIZE; 
   # Modify compressed size in GFH
   $GFHInfo{"m_file_len"} = $binsize;
   # Modify Attribute to show post build is complete
   $GFHInfo{"m_attr"} = $GFHInfo{"m_attr"} + 1;
   #$fileInfoRef->{"m_attr"}
   # Write back into GFH
   open $GFH_BIN_HANDLE, ">$binaryGFH" or
     &vivaHelper::ErrorHandler("Cannot open file $binaryGFH: $!", __FILE__, __LINE__);
   binmode $GFH_BIN_HANDLE;
   &vivaHelper::WriteGFHFileInfo($GFH_BIN_HANDLE, \%GFHInfo);
   close $GFH_BIN_HANDLE;
}
#****************************************************************************
# subroutine:  FillInfoToResourceBINPreamble
# description: fill preamble information into resource bin preamble
# input:       resource bin number, resource bin path
# output:      noen
#****************************************************************************
sub FillInfoToResourceBINPreamble
{
	 my $binaryPath = shift;
	 my $content;
	 my @result;
	 
   open my $RESOURCE_BIN_HANDLE, "+<$binaryPath" or
      &vivaHelper::ErrorHandler("Cannot open resource binary $binaryPath: $!", __FILE__, __LINE__);
   binmode $RESOURCE_BIN_HANDLE;
   
   $result[0] = $resourcePreamble{"ProjectID"};
   $result[1] = $resourcePreamble{"Vpattern"};
   $result[2] = $resourcePreamble{"Version"};
   $result[3] = $resourcePreamble{"Compressed"};
   $result[4] = $resourcePreamble{"Existed"};
   $result[5] = $resourcePreamble{"LoadAddress"};
   $result[6] = $resourcePreamble{"CompressedSize"};
   $result[7] = $resourcePreamble{"MAXRAMSize"};
   $result[8] = $resourcePreamble{"Resource_version"};
   $result[9] = $resourcePreamble{"ExecAddress"};
   $result[10] = $resourcePreamble{"TableSize"};
   $result[11] = $resourcePreamble{"ContentSize"};
   $result[12] = $resourcePreamble{"Magic"};
   	  
   $content = pack("a64a6SSSLLLLLLLL", @result);	 
   print $RESOURCE_BIN_HANDLE $content;   
   close $RESOURCE_BIN_HANDLE;
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
      &vivaHelper::ErrorHandler("Cannot open file $filename: $!", __FILE__, __LINE__);

   while (<$input>)
   {
      chomp;
      if (/^\s*\#define\s+(\S+)\s+(\S+)/)
      {
         $featureConfigRef->{$1} = hex($2);
      }
   }

   close $input;
}
#****************************************************************************
# subroutine:  printLog
# description: Get the basic information of processing
# input:       None
# output:      
#****************************************************************************
sub printLog
{
   print "[CustComp] $_[0]\n";
}
#****************************************************************************
# subroutine:  ErrorHandler
# description: Handle the post process error and output the error message.
#              Note calling this function will lead program terminated.
# input:       Message, source filename, line number
# output:      None
# need init:   Yes/No
#****************************************************************************
sub ErrorHandler
{
   my ($message, $file, $line) = @_;

   my $errorMessage = "[MBAComp] ERROR: $message at $file line $line\n";

   print $errorMessage;
   
   die $errorMessage;
   
}