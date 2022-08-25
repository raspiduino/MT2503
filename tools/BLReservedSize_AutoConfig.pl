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
#*   BLReservedSize_AutoConfig.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script parses LIS and modifies custom_FeatureConfig.h
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
use LISInfo;
use FileInfoParser;
use auto_adjust_mem; #pm file name without case sensitivity
use sysGenUtility;
use CommonUtility;
use File::stat;
#****************************************************************************
# AutoCheckin Information
#****************************************************************************
use constant OWNER        => "";
#****************************************************************************
# Constants
#****************************************************************************
my $BLSIZE_CONFIG_VERNO    = " v0.06";
                            #  v0.06 , Fix ESD ROM patch side effect: BL size increases and BL overlap with ext_BL
                            #  v0.05 , Add scatter file input
                            #  v0.04 , Fix not to run modification if scatter file path is incorrect
                            #  v0.03 , Move Dec2Hex from sysGenUtility to CommonUtility
                            #  v0.02 , do not adjust during ext_bl_update_support=TRUE
                            #  v0.01 , initial draft

#****************************************************************************
# Inputs
#****************************************************************************
my $BL_LIS_PATH                 = $ARGV[0]; 
my $EXT_BL_LIS_PATH             = $ARGV[1];
my $CUSTOM_FEATURE_CONFIG_H     = $ARGV[2] . "\\custom_FeatureConfig.h";
my $MAKE_FILE                   = $ARGV[3];
my $INTERMEDIATE_FILE           = $ARGV[4]; #make\\~BL_LinkError.tmp 
my $PROJECT_NAME                = $ARGV[5];
my $LOG_PATH                    = $ARGV[6];
my $SCATTER_FILE_PATH           = $ARGV[7];

#****************************************************************************
# Global Variables
#****************************************************************************
my $g_bAutoConfig          = 0;
my $g_bMAUIHasHistory      = 0;
my $g_bBLHasHistory        = 0;
my $g_bEXTBLHasHistory     = 0;
my $g_bLinkError           = 0;
my $strLinkErrorContent;
#****************************************************************************
# 0 > Parse Log
#****************************************************************************
&blconfig_die("$INTERMEDIATE_FILE doesn't exist!", __FILE__, __LINE__) if(!-e $INTERMEDIATE_FILE);
my $nLinkError = 0;

open (FILE_HANDLE, "<$INTERMEDIATE_FILE") or &dp_die("$INTERMEDIATE_FILE: file error!", __FILE__, __LINE__);
while (<FILE_HANDLE>)
{
    $strLinkErrorContent .= $_;
    #e.g. Error: L6220E: Load region DEMAND_PAGING_ROM0 size (54932988 bytes) exceeds limit (1048576 bytes).
    if(/L(\S+)E: Load region/)
    {
        $nLinkError++ if($1 ne "6220");
        $g_bLinkError = 1 if($1 eq "6220");
    }
    elsif(/L(\S+)E: Execution region/)
    {
        $nLinkError++;
    }
}
close FILE_HANDLE;

if($nLinkError > 0)
{
    &WriteLog($INTERMEDIATE_FILE, undef, "[AAPMC]tools\BLReservedSize_AutoConfig.pl can't handle this kind of link errors:\n$strLinkErrorContent\n");
    exit ERR::CANNOT_ADJUST;
}
#****************************************************************************
# 1 > Parse MAKEFILE
#****************************************************************************
my %MAKEFILE_OPTIONS;
if(1 != &FileInfo::Parse_MAKEFILE($MAKE_FILE, \%MAKEFILE_OPTIONS))
{
    print "MakeFile Parse Error: ERR_UNEXPECTED\n";
    exit ERR::ERR_UNEXPECTED;
}
$g_bAutoConfig =1 if(&FileInfo::is("BLRESERVEDSIZE_AUTOCONFIG", "TRUE"));
my $bb = $MAKEFILE_OPTIONS{'platform'};
#****************************************************************************
# 2 > Parse scatter file
#****************************************************************************
if($g_bAutoConfig == 1)
{
    my $SCATTER_FILE                = $SCATTER_FILE_PATH;
    my $BL_SCATTER_FILE             = $ARGV[2] . '\\scatBL_' . $bb . '.txt';
    my $EXT_BL_SCATTER_FILE         = $ARGV[2] . '\\scatBL_' . $bb . '_ext.txt';
    $g_bMAUIHasHistory  = &sysUtil::HasCheckinHistory($SCATTER_FILE);
    $g_bBLHasHistory    = &sysUtil::HasCheckinHistory($BL_SCATTER_FILE);
    $g_bEXTBLHasHistory = &sysUtil::HasCheckinHistory($EXT_BL_SCATTER_FILE);
    $g_bAutoConfig =0 if((defined $g_bMAUIHasHistory and $g_bMAUIHasHistory == 1) or
                         (defined $g_bBLHasHistory and $g_bBLHasHistory == 1) or
                         (defined $g_bEXTBLHasHistory and $g_bEXTBLHasHistory == 1)
                         or (!defined $g_bMAUIHasHistory)
                         or (!defined $g_bBLHasHistory)
                         or (!defined $g_bEXTBLHasHistory));  # if the file doesn't exist
}
#****************************************************************************
# 3 > Parse LIS
#****************************************************************************
&LISInfo::ParseLIS($BL_LIS_PATH);
my ($nBLBase, $nBLActualSize, $nBLMaxSize, $strBLAttr) = LISInfo::GetLoadRegionInfo("READ_ONLY", 0);
&LISInfo::ParseLIS($EXT_BL_LIS_PATH);
my ($nEXTBLBase, $nEXTBLActualSize, $nEXTBLMaxSize, $strEXTBLAttr) = LISInfo::GetLoadRegionInfo("EXT_BOOTLOADER", 0);
my $ERR_CODE =&AutoAdjust($nBLActualSize, $nBLMaxSize, $nEXTBLActualSize, $nEXTBLMaxSize);
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
exit $ERR_CODE;


#****************************************************************************
# subroutines
#****************************************************************************
sub AutoAdjust
{
    my ($nBLActualSize, $nBLMaxSize, $nEXTBLActualSize, $nEXTBLMaxSize) = @_;
    my $ERR_CODE = ERR::NO_NEED_TO_UPDATE;
    print "[Actual Size] BL=".&CommonUtil::Dec2Hex($nBLActualSize).", EXT_BL=".&CommonUtil::Dec2Hex($nEXTBLActualSize)."\n";
    if(($bb eq 'MT6260') and ($MAKEFILE_OPTIONS{'secure_support'} eq 'TRUE'))
    {
        #BL size should 4-kB align
        my $align = 4*1024;
        $nBLActualSize = ($nBLActualSize % $align ==0) ? $nBLActualSize : (int($nBLActualSize / $align)+1) * $align;

        #add ROM patch size
        my $rom_patch_stat = stat(".\\bootloader_bin\\MT6260_E1_ROM_PATCH_RELEASE.bin");
        &sysUtil::sysgen_die("[3.2]can not get .\\bootloader_bin\\MT6260_E1_ROM_PATCH_RELEASE.bin", __FILE__, __LINE__) unless defined $rom_patch_stat;
        my $rom_patch_size = $rom_patch_stat->size;
        $nBLActualSize += $rom_patch_size;
        
        #add Signature size
        $nBLActualSize += 932;
        print "BL size: $nBLActualSize after add ROM patch size $rom_patch_size byte and Signature size 932 byte when secure_support is TRUE on MT6260 platform\n";
    }
    my $nBLSize_suggest = $nBLActualSize % (1024) == 0 ? 1024*(int($nBLActualSize / 1024)) : 1024*(int($nBLActualSize / 1024)+1);
    my $nEXTBLSize_suggest = $nEXTBLActualSize % (1024) == 0 ? 1024*(int($nEXTBLActualSize / 1024)) : 1024*(int($nEXTBLActualSize / 1024)+1);
    print "nBLSize_suggest=$nBLSize_suggest,nEXTBLSize_suggest=$nEXTBLSize_suggest\n";
    my %RegionInfo; # Key: strRegionName, Value=[strOrgMaxSize, strMaxSize_suggest]
    if($nBLSize_suggest != $nBLMaxSize)
    {
        $RegionInfo{BL} = [&CommonUtil::Dec2Hex($nBLMaxSize), &CommonUtil::Dec2Hex($nBLSize_suggest)];
    }
    if($nEXTBLSize_suggest != $nEXTBLMaxSize )
    {
        if(&FileInfo::is("ext_bl_update_support", "TRUE"))
        {
            $nEXTBLSize_suggest = $nEXTBLMaxSize; # should reserve the same maxsize as original due to self update mechanism
        }
        else
        {
            $RegionInfo{EXT_BL} = [&CommonUtil::Dec2Hex($nEXTBLMaxSize), &CommonUtil::Dec2Hex($nEXTBLSize_suggest)];
        }
    }
    my $RegionInfoSize = keys %RegionInfo;
    my $strErrorMsg = "LinkError: \n$strLinkErrorContent\n" if($strLinkErrorContent ne "");
    if($RegionInfoSize != 0)
    {   
        if(!$g_bAutoConfig)
        {
            print "NO CHANGE\n";
            if(&FileInfo::is("BLRESERVEDSIZE_AUTOCONFIG", "TRUE"))
            {
                &WriteLog($INTERMEDIATE_FILE, \%RegionInfo, ($g_bMAUIHasHistory==1 or $g_bBLHasHistory==1 or $g_bEXTBLHasHistory ==1)?
                        "$strErrorMsg\nManual check-in history exists in scatter file.\nPlease remove your own modifications first, \nrebuild and make sure the load is successfully built, \nthen add your own modifications back.\n" : undef);
            }
            else
            {
                &WriteLog($INTERMEDIATE_FILE, \%RegionInfo, "$strErrorMsg\BLRESERVEDSIZE_AUTOCONFIG=FALSE or not exist, no update.\n");
            }
            $ERR_CODE = $g_bLinkError ? ERR::NO_MODIFY : ERR::NO_NEED_TO_UPDATE;
        }
        else
        {
            my $strModifiedRegionInfo = &GetModifiedInfo(\%RegionInfo);
            my $P4Info_ref =  &AUTO_ADJUST::CreateP4InfoTemplate(OWNER, $PROJECT_NAME, "\n[AutoCheckin]", $strModifiedRegionInfo);
            my %ChangeList;
            map {$ChangeList{"MAX_$_\_SIZE"} = $RegionInfo{$_}[1] }keys %RegionInfo;
            if( ERR::AAPMCLOG_SUCCESS == &AAPMCLogParser::Open($LOG_PATH))
            {
                $ERR_CODE = &AAPMCLogParser::AddOneChangeRecord($CUSTOM_FEATURE_CONFIG_H, \%ChangeList, $P4Info_ref);
                &AAPMCLogParser::Close($LOG_PATH);
            }
            print "Duplicated modification\n" if($ERR_CODE == ERR::ERR_MODIFYDUPLICATED);
            print "Unexpected Error\n" if($ERR_CODE == ERR::ERR_UNEXPECTED);
            if($ERR_CODE == ERR::AAPMCLOG_SUCCESS)
            {
                print "MODIFY SUCCESS\n";
                &WriteLog($INTERMEDIATE_FILE, \%RegionInfo, undef);
            }
        }
    }
    else
    {
        if($g_bLinkError)
        {
            print "$strErrorMsg\nBL Link Error:L6220E Load Region: shouldn't be no adjustment.\n";
            $ERR_CODE = ERR::ERR_UNEXPECTED;
        }
        else
        {
            print "No need to update.\n";
        }
        print "(nBLActualSize, nBLMaxSize, nBLSize_suggest) = ($nBLActualSize, $nBLMaxSize, $nBLSize_suggest)\n";
        print "(nEXTBLActualSize, nEXTBLMaxSize, nEXTBLSize_suggest) = ($nEXTBLActualSize, $nEXTBLMaxSize, $nEXTBLSize_suggest)\n";    
    }
    print "Return ERR_CODE: $ERR_CODE\n";
    return $ERR_CODE;
}
#****************************************************************************
# subroutine:  GetModifiedInfo
#              to get Modified Region information
# input:       $RegionInfo; # Key: strRegionName, Value=[strOrgMaxSize, strMaxSize_suggest]
#              strRegionName: Load Region Name
#              strOrgMaxSize: Original MaxSize
#              strMaxSize_suggest: Suggested MaxSize
# output:      $strInfo - Modified region information
#****************************************************************************
sub GetModifiedInfo
{
    my ($RegionInfo_ref) = (@_);
    my $strInfo;
    $strInfo =  "[Before auto adjustment]\n";
    map {$strInfo .= $_." MAXSIZE=".$RegionInfo_ref->{$_}[0]."\n" } keys %$RegionInfo_ref;
    $strInfo .= "[After auto adjustment]\n";
    $strInfo .= "In custom\\system\\[BB]\\custom_featureconfig.h:\n";
    map {$strInfo .= "RECOMMAND: Please set MAX_".$_."_SIZE=".$RegionInfo_ref->{$_}[1]."\n" } keys %$RegionInfo_ref;
    return $strInfo;
}

#****************************************************************************
# subroutine:  WriteLog
# input:       $LogPath: Log Path
#              $RegionInfo; # Key: strRegionName, Value=[strOrgMaxSize, strMaxSize_suggest]
#              strRegionName: Load Region Name
#              strOrgMaxSize: Original MaxSize
#              strMaxSize_suggest: Suggested MaxSize
#              $strMsg: comment
#****************************************************************************
sub WriteLog
{
    my ($LogPath, $RegionInfo_ref, $strMsg) = (@_);
    print $strMsg if(defined $strMsg);    
    my $strModifiedInfo;
    if(defined $RegionInfo_ref)
    {
        $strModifiedInfo = &GetModifiedInfo($RegionInfo_ref);
        print $strModifiedInfo;
    }
    open (FILE_HANDLE, ">$LogPath") or &blconfig_die("Cannot open log: $LogPath\n", __FILE__, __LINE__);
    print FILE_HANDLE $strMsg if(defined $strMsg);
    if(defined $RegionInfo_ref)
    {
        print FILE_HANDLE $strModifiedInfo;
    }   
    close FILE_HANDLE;
}
#****************************************************************************
# subroutine:  blconfig_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub blconfig_die
{
    my ($error_msg, $file, $line_no) = @_;
    &AUTO_ADJUST::error_handler($error_msg, $file, $line_no, 'BLReservedSize_Config');
}
