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
#*   DemandPagingConfig.pl
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
use File::Copy;
#****************************************************************************
# AutoCheckin Information
#****************************************************************************
use constant OWNER        => "";
#****************************************************************************
# Constants
#****************************************************************************
my $DPCONFIG_VERNO    = " v0.09";
                       #  v0.09 , Move Dec2Hex from sysGenUtility to CommonUtility
                       #  v0.08 , Refine the mechanism of auto-adjust
                       #  v0.07 , Remove OWNER name not to apply auto-check-in
                       #  v0.06 , to support auto-check-in
                       #  v0.05 , to avoid MBA+DP maxsize overflow
                       #  v0.04 , to support to adjust all matched regions at the same time
                       #  v0.03 , to support to adjust ROM/2nd_ROM/MBA max size
                       #  v0.02 , update manually check-in scatter modification information for customers
                       #  v0.01 , initial draft

#****************************************************************************
# Inputs
#****************************************************************************
my $LIS_FILE = $ARGV[0];
my $CUSTOM_FEATURE_CONFIG_H = $ARGV[1] . '\\' . "custom_FeatureConfig.h";
my $MAKE_FILE = $ARGV[2];
my $INTERMEDIATE_FILE = $ARGV[3];  # make\\~DP_LinkError.tmp
my $PROJECT_NAME = $ARGV[4];
my $LOG_PATH = $ARGV[5];
my $SCATTER_FILE =  $ARGV[1] . '\\scat' . $PROJECT_NAME . '.txt';

#****************************************************************************
# Global Variables
#****************************************************************************
my @strRegionToAdjustList;
my $bAutoConfig          = 0;
#****************************************************************************
# 0 > Parse Log
#****************************************************************************
&dp_die("$INTERMEDIATE_FILE doesn't exist!", __FILE__, __LINE__) if(!-e $INTERMEDIATE_FILE);

open (FILE_HANDLE, "<$INTERMEDIATE_FILE") or &dp_die("$INTERMEDIATE_FILE: file error!", __FILE__, __LINE__);
while (<FILE_HANDLE>)
{
    #e.g. Error: L6220E: Load region DEMAND_PAGING_ROM0 size (54932988 bytes) exceeds limit (1048576 bytes).
    if(/L6220E:\s*Load\s*region\s*(DEMAND_PAGING_ROM0|ROM|SECONDARY_ROM|LANG_PACK_ROM|CUSTPACK_ROM)\s*size/)
    {
        push (@strRegionToAdjustList, ('DEMAND_PAGING_ROM0', 'ROM', 'SECONDARY_ROM', 'LANG_PACK_ROM', 'CUSTPACK_ROM'));
    }
}
close FILE_HANDLE;

my $nSize = @strRegionToAdjustList;
if($nSize == 0)
{
    &WriteLog($INTERMEDIATE_FILE, undef, "[AAPMC]tools\DemandPagingConfig.pl can't adjust the max size of this region \n it can only adjust ROM/SECONDARY_ROM/DEMAND_PAGING_ROM0/LANG_PACK_ROM/CUSTPACK_ROM.\n It may be link error.\n");
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
$bAutoConfig =1 if(defined $MAKEFILE_OPTIONS{'demand_paging_auto_config'} and 'TRUE' eq $MAKEFILE_OPTIONS{'demand_paging_auto_config'});
#****************************************************************************
# 2 > Parse scatter file
#****************************************************************************
my $bHasHistory = &sysUtil::HasCheckinHistory($SCATTER_FILE);
$bAutoConfig =0 if(defined $bHasHistory and $bHasHistory == 1);

#****************************************************************************
# 3 > Parse LIS to get specific Load Region's real size
#****************************************************************************
&LISInfo::ParseLIS($LIS_FILE);
my $ERR_CODE = &AutoAdjust(\@strRegionToAdjustList);
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
exit $ERR_CODE;

#****************************************************************************
# subroutine:  dp_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub dp_die
{
    my ($error_msg, $file, $line_no) = @_;
    &AUTO_ADJUST::error_handler($error_msg, $file, $line_no, 'DemandPagingConfig');
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
    open (FILE_HANDLE, ">$LogPath") or &dp_die("Cannot open log: $LogPath\n", __FILE__, __LINE__);
    print FILE_HANDLE $strMsg if(defined $strMsg);
    if(defined $RegionInfo_ref)
    {
        print FILE_HANDLE $strModifiedInfo;
    }   
    close FILE_HANDLE;
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
    map {$strInfo .= "MAX_".$_."_SIZE=".$RegionInfo_ref->{$_}[0]."\n" } keys %$RegionInfo_ref;
    $strInfo .= "[After auto adjustment]\n";
    map {$strInfo .= "RECOMMAND: Please set MAX_".$_."_SIZE=".$RegionInfo_ref->{$_}[1]."\n" } keys %$RegionInfo_ref;
    return $strInfo;
}


#****************************************************************************
# subroutine:  AutoAdjust
# input:       astrLoadRegionName: an array containing one or more strLoadRegionName
#****************************************************************************

sub AutoAdjust
{
    my ($strLoadRegionNameList_ref) = shift;
    my $ERR_CODE = ERR::ERR_UNEXPECTED;
    my $nInputSize=@$strLoadRegionNameList_ref;
    return $ERR_CODE if($nInputSize == 0);
    
    my %RegionInfo; # Key: strRegionName, Value=[strOrgMaxSize, strMaxSize_suggest]
    foreach(@$strLoadRegionNameList_ref)
    {
        my ($nBase, $nActualSize, $nMaxSize, $strAttr) = &LISInfo::GetLoadRegionInfo($_,0);
        #if the region is not in LIS file or the max size is not defined, no need to adjust
        next if(($nMaxSize == 0) or ($nMaxSize == 0xffffffff));
        if($nActualSize != $nMaxSize)
        {
            #Actual Size should be 1M aligned
            my $nMaxSize_suggest = $nActualSize % (1024*1024) == 0 ? 1024*1024*(int($nActualSize / (1024*1024))) : 1024*1024*(int($nActualSize / (1024*1024))+1);
            $RegionInfo{$_} = [&CommonUtil::Dec2Hex($nMaxSize), &CommonUtil::Dec2Hex($nMaxSize_suggest)];
        }
    }
    #map {print $_."->".$RegionInfo{$_}[0].",".$RegionInfo{$_}[1]."\n" } keys %RegionInfo;
    
    my $RegionInfoSize = keys %RegionInfo;
    if($RegionInfoSize != 0)
    {
        if("FAIL" eq &HealthCheck(\%RegionInfo))
        {
            print "==CANNOT ADJUST==\n";
            &WriteLog($INTERMEDIATE_FILE, undef, "[AAPMC]HealthCheck FAIL!\nDEMAND(+MBA)'s region shouldn't exceed 0xFFFFFFFF\n");
            $ERR_CODE = ERR::CANNOT_ADJUST;
        }
        else
        {
            if(!$bAutoConfig)
            {
                print "NO CHANGE\n";
                &WriteLog($INTERMEDIATE_FILE, \%RegionInfo, $bHasHistory==1 ? "Manual check-in history exists in scatter file.\nPlease remove your own modifications first, \nrebuild and make sure the load is successfully built, \nthen add your own modifications back.\n" : undef);
                $ERR_CODE = ERR::NO_MODIFY;
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
    }
    else
    {
        print "Shouldn't enter AutoAdjust(): all regions matchs ActualSize < MaxSize: ERR_UNEXPECTED\n";
        $ERR_CODE = ERR::ERR_UNEXPECTED;
    }
    return $ERR_CODE;
}

sub HealthCheck
{
    my ($AdjustRegionInfo_Ref) = (@_);
    my ($ERROR_PASS, $ERROR_FAIL) = ("PASS", "FAIL"); 
    my $ERR = $ERROR_PASS;

    my ($nBase, $nSize, $strAttribute);
    my ($nDPBase, $nDPSizeLIS, $nLANGSizeLIS, $nCUSTSizeLIS) = (0,0,0,0);
    ($nDPBase, $nSize, $nDPSizeLIS, $strAttribute)= &LISInfo::GetLoadRegionInfo("DEMAND_PAGING_ROM0", 0);
    ($nBase, $nSize, $nLANGSizeLIS, $strAttribute)= &LISInfo::GetLoadRegionInfo("LANG_PACK_ROM", 0);
    ($nBase, $nSize, $nCUSTSizeLIS, $strAttribute)= &LISInfo::GetLoadRegionInfo("CUSTPACK_ROM", 0);
    my ($nDPSize, $nLANGSize, $nCUSTSize) = ($nDPSizeLIS, $nLANGSizeLIS, $nCUSTSizeLIS);
    $nDPSize = hex($AdjustRegionInfo_Ref->{"DEMAND_PAGING_ROM0"}[1] ) if (exists $AdjustRegionInfo_Ref->{"DEMAND_PAGING_ROM0"});
    $nLANGSize = hex($AdjustRegionInfo_Ref->{"LANG_PACK_ROM"}[1] ) if (exists $AdjustRegionInfo_Ref->{"LANG_PACK_ROM"});
    $nCUSTSize = hex($AdjustRegionInfo_Ref->{"CUSTPACK_ROM"}[1] )if (exists $AdjustRegionInfo_Ref->{"CUSTPACK_ROM"});
    
    my $nTotal = $nDPBase+$nDPSize+$nLANGSize+$nCUSTSize;
    if( $nTotal > 0xffffffff )
    {
        print "DPBase, DPSize, LANG_Size, Cust_Size in LIS =>\n$nDPBase, $nDPSizeLIS, $nLANGSizeLIS, $nCUSTSizeLIS\n";
        print "======Actual Size======\n";
        print "DPSize = $nDPSize = ".&CommonUtil::Dec2Hex($nDPSize)."\n";
        print "LANGSize = $nLANGSize = ".&CommonUtil::Dec2Hex($nLANGSize)."\n";
        print "CUSTSize = $nCUSTSize = ".&CommonUtil::Dec2Hex($nCUSTSize)."\n";
        print "Total Size = $nTotal > 0xFFFFFFFF - FAIL\n";
        $ERR = $ERROR_FAIL;
    } 
    return $ERR;
}