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
#*   scatFrame.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is to generate the frame of memory layout 
#*   and provides the flow of generation
#*  
#* Author:
#* -------
#*   Qmei Yang (mtk03726)
#*
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use sysgenUtility;
use FileInfoParser;
use tools::pack_dep_gen;
PrintDependModule();
package scatFrame;
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# scatFrame Version
#****************************************************************************
sub scatFrame_verno
{
    return " v0.12";
           # v0.12 , 20131107 by Yinli, Exec-view base address of DYNAMIC_COMP_MAUIINIT shifts 40kB 
           #                            from the base of DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL
           # v0.11 , 20131031 by Yinli, Add a  new layout for special DCM region: DYNAMIC_COMP_MAUIINIT 
           # v0.10 , 20130923 by Yinli, A verno-number is reserved for the new trunk branch 11C
           # p0.09 , 20130227 by Carina, Modify the rule of generating MM/IME DCM layout 
           #                             (Generate the laytout of MM/IME overlay if MMI_VERSION = COSMOS_MMI)
           # v0.08 , 20130206 by Carina, Modify MM DCM layout to put MWREC/VIDMSG/MDIVID in the same group
           # v0.07 , 20130205 by mei, Directly support DCMP from csv
           # v0.06 , 20130130 by mei, Provide scatUtility for DCMP
           # v0.05 , 20120920 by Carina, Support GenExecutionRegions()
           # v0.04 , 20120612 by Carina, Support EWS via tools::pack_dep_gen
           # v0.03 , 20120612 by Carina, Error message refinement
           # v0.02 , 20120519 by mei, support Read BB folder first to get config input
           # v0.01 , 20120513 by mei, initial version
}
#****************************************************************************
# Constants
#****************************************************************************
#****************************************************************************
# Global Variables
#****************************************************************************
#****************************************************************************
# Input Parameters
#****************************************************************************
use constant InputSections => 0;
use constant Regions       => 1;
#SCAT Type
use constant MAIN          => 0;
use constant BL            => 1;
use constant EXT_BL        => 2;
use constant FOTA          => 3;
#****************************************************************************
# subroutines
#****************************************************************************
#scatFrame::GetPath("ROM", scatFrame::InputSections)
sub GetPath
{
    my ($strKey, $nType) = @_;
    my $strPath = undef;
    my $strMAINConfig = "scat_config\\";
    my %PathMap = ("InputSections"     => "InputSections\\",
                   "Regions"           => "RegionConfig\\",
                  );
    if($nType == InputSections)
    {
        $strPath = $strMAINConfig . $PathMap{InputSections}.$strKey."\\";
    }
    elsif($nType == Regions)
    {
        $strPath = $strMAINConfig . $PathMap{Regions};
    }
    else
    {
        &scatFrame_die("[2.0][GetPath]Unsupport Type", __FILE__, __LINE__);
    }
    return $strPath;
}

sub GetConfigInput
{
    my ($strKey, $strFileName, $nType, $bb_folder) = @_;
    my $strFile = &GetPath($strKey, $nType) . $strFileName;
    my $strCustomFolder = $bb_folder . "\\";
    my $strDefaultFolder = "custom\\system\\Template\\";
    my $strInput = $strDefaultFolder . $strFile;
    $strInput = $strCustomFolder.$strFile if(-e $strCustomFolder.$strFile);
    return $strInput;
}
sub GetCustomInput
{
    my ($strKey, $strFileName, $nType, $bb_folder) = @_;
    my $strFile = &GetPath($strKey, $nType) . $strFileName;
    my $strCustomFolder = $bb_folder . "\\";
    my $strInput = $strCustomFolder.$strFile;
    return $strInput; 
}

#****************************************************************************
# subroutine:  GenInputSections
# input:       InputSection_aref:   InputSections array reference (get from &CommonUtil::ParseCSV)
#              Indef_href:          Used to get Inputsections info (get from &CommonUtil::ParseCSV)
# output:      Inputsections string
#****************************************************************************
sub GenInputSections
{
    my ($InputSection_aref, $Indef_href) = @_;
    my $strContent;
    foreach my $item (@$InputSection_aref)
    {
        my $strModuleName = $item->[$Indef_href->{ModuleName}];
        my $strAttribute = $item->[$Indef_href->{Attribute}];
        $strModuleName =~ s/\s//g;
        next if($strModuleName eq "");
        my @AttrTemp = split(/\s+/, $strAttribute);
        if($strModuleName =~ /.lib$|.a$/ and $strModuleName !~ /^\*|\;/)
        {
            $strModuleName = "*".$strModuleName;
        }
        my @Attr;
        foreach my $strAttr (@AttrTemp)
        {
            if($strAttr =~ /^RO$|^RW$|^ZI$|^RO-CODE$|^RO-DATA$/)
            {
                $strAttr = "+".$strAttr;
            }
            push @Attr, $strAttr;
        }
        $strContent .= ' 'x8 . $strModuleName . " (". join(", ", @Attr) . ")\n";
    }
    return $strContent;
}

#****************************************************************************
# subroutine:  GenExecutionRegions
# input:       Region_aref:         Region info array reference (get from &CommonUtil::ParseCSV)
#              Indef_href:          Used to get region info (get from &CommonUtil::ParseCSV)
#              inputsection_href:   Input section hash reference 
#                                   key: execution region, value: inputsections
#              LoadRegion:          Which Load region Execution region belongs to 
# output:      Execution view body string
#****************************************************************************
sub GenExecutionRegions
{
    my ($Region_aref, $Indef_href, $inputsection_href) = @_;
    my $strContent;
    foreach my $item (@$Region_aref)
    {
        my $strRegionName = $item->[$Indef_href->{RegionName}];
        my $strOffset = $item->[$Indef_href->{Offset}];
        my $strBase = $item->[$Indef_href->{Base}];
        my $strAttribute = $item->[$Indef_href->{Attribute}];
        my $strMaxSize = $item->[$Indef_href->{MaxSize}];
        $strOffset =~ s/\s//g;
        $strBase =~ s/\s//g;
        $strMaxSize =~ s/\s//g;
        my @Attr = split(/\s+/, $strAttribute);
        $strOffset = "+".$strOffset if($strOffset ne "");
        my $strBaseAddress = ($strOffset eq "") ? $strBase : $strOffset;
        my $strInputSections = ${$inputsection_href}{$strRegionName};

        $strContent .= &format_execution_view($strRegionName, $strBaseAddress, 
                                              join(" ", @Attr), $strMaxSize, $strInputSections);
    }
    return $strContent;
}


#****************************************************************************
# subroutine:  format_execution_view
# input:       strName:         Region Name
#              strBegin:        Begin address (base address/offset)
#              strAttribute:    Attrbite list
#              strLength:       Region limit
#              strInputSection: InputSections
# output:      Execution view body string
#****************************************************************************
sub format_execution_view
{
    my ($strName, $strBegin, $strAttribute, $strLength, $strInputSection) = @_;
    my $formated_string = ' ' x 4 . $strName . " $strBegin $strAttribute $strLength\n";
    $formated_string .= ' ' x 4 . "{\n";
    $formated_string .= $strInputSection;
    $formated_string .= ' ' x 4 . "}\n";
    return $formated_string;
}

#****************************************************************************
# subroutine:  scatFrame_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub scatFrame_die
{
    my ($error_msg, $file, $line_no) = (@_);
    &sysUtil::error_handler($error_msg, $file, $line_no, 'scatFrame');    
}
#****************************************************************************
# Package
#****************************************************************************
package scatUtil;
use POSIX qw(floor ceil);
#****************************************************************************
# Global Variables
#****************************************************************************
my %g_DCMPSize;         # RegionPostfixName => BodyRealSize
my %g_DCMPoolInfo;      # Pool => [Region, Region, Region]
my %g_DCMRegionPoolMap; # Region => Pool
my %g_DCMPoolSize;      # Pool=>Size

sub ParseDCMP
{
    my ($bb_folder) = @_;
    my %DCMPInfo;
    my $strFilePath = scatFrame::GetConfigInput(undef, "DCMP.csv", scatFrame::Regions, $bb_folder);
    my ($ContentList_aref, $Index_href) = CommonUtil::ParseCSV($strFilePath, 0);
    foreach my $Content (@$ContentList_aref)
    {
        _SetDCMPSize($Content, $Index_href, \%g_DCMPSize);
        _SetPoolInfo($Content, $Index_href, \%g_DCMPoolInfo, \%g_DCMRegionPoolMap);
    }
    _SetPoolSize(\%g_DCMPoolInfo, \%g_DCMPSize, \%g_DCMPoolSize);
}
sub _SetDCMPSize # RegionPostfixName => BodyRealSize
{
    my ($Content_aref, $Index_href, $DCMPSize_href) = @_;
    my $Idx_Name = $Index_href->{RegionPostfixName};
    my $Idx_Size = $Index_href->{BodyRealSize};
    my $Idx_Ratio  = $Index_href->{VeneerRatio};
    my $Idx_Max = $Index_href->{VeneerMaxSize};
    my $Idx_Min = $Index_href->{VeneerMinSize};
    my $nSize = MultiplyWithLimit(hex($Content_aref->[$Idx_Size]), (1+$Content_aref->[$Idx_Ratio]), 
                                  hex($Content_aref->[$Idx_Max]), hex($Content_aref->[$Idx_Min]));
    #32bytes aligned
    $nSize = ceil($nSize/32)* 32;
    $DCMPSize_href->{$Content_aref->[$Idx_Name]} = $nSize + 0x40;
}
sub _SetPoolInfo # Pool => [Region, Region, Region]
{
    my ($Content_aref, $Index_href, $PoolInfo_href, $PoolRegionMap_href) = @_;
    my $Idx_Name = $Index_href->{RegionPostfixName};
    my $Idx_Pool = $Index_href->{SharePoolInfo};
    my $Idx_FO   = $Index_href->{FeatureOptions};
    my $Pool = $Content_aref->[$Idx_Pool];
    $Pool =~ s/\s//;
    if($Pool ne "")
    {
        if(FileInfo::EvaluateFeatureOptionCondition($Content_aref->[$Idx_FO]))
        {
            $PoolRegionMap_href->{$Content_aref->[$Idx_Name]} = $Pool;
            if(exists $PoolInfo_href->{$Pool})
            {
                push @{$PoolInfo_href->{$Pool}}, $Content_aref->[$Idx_Name];
            }
            else
            {
                $PoolInfo_href->{$Pool} = [$Content_aref->[$Idx_Name]];
            }
        }
    }
}

sub _SetPoolSize  # Pool=>Size
{
    my ($PoolInfo_href, $DCMPSize_href, $PoolSize_href) = @_;
    
    foreach my $Pool (keys %$PoolInfo_href)
    {
        my $Regions = $PoolInfo_href->{$Pool};
        my @Size = map { sysUtil::DCMP_is_MMorIME_head($_)? 
                        DCMP_query_MM_IME_Grouplength($_) : $DCMPSize_href->{$_} } @$Regions;
  
        my @SortedSize =  sort {$b <=> $a} @Size;
        $PoolSize_href->{$Pool} = $SortedSize[0];
    }
}
#$veneerReserveSize = &MultiplyWithLimit($binarySize, $veneerReserveRatio, $veneerReserveMax, $veneerReserveMin);
sub MultiplyWithLimit
{
    my $multiplicand = shift;
    my $multiplier = shift;
    my $max = shift;
    my $min = shift;
    
    my $result = $multiplicand * $multiplier;
    if ($result < $min)
    {
      $result = $min;
    }
    elsif ($result > $max)
    {
      $result = $max;
    }
    return $result;
}

#****************************************************************************
# subroutine:  Query DCM Compression SharePool Information on ram
#                   for dcm compression
# input: $strPostfix: Postfix in DYNAMIC_COMP_$strPostfix
# output: SharePoolnum, SharePool's max size
#****************************************************************************
sub DCMP_query_SharePoolInfo
{
    my ($strPostfix) = @_;
    DCMP_NoInputDie();
    my $strSharePoolNum = $g_DCMRegionPoolMap{$strPostfix};
    my $nMaxSize = $g_DCMPoolSize{$strSharePoolNum};
    return ($strSharePoolNum, $nMaxSize);
}
#****************************************************************************
# subroutine:  Process DCM Compression related information
#                   for dcm compression
# input: $RamBottomAddress: maybe RamSize - TxRx Region : from sub DCMP_code_layout
#        $combination: DYNAMIC_COMP_$strPostfix 's Postfix combination
#        $Output_table: %DCM_COMP_CODE_table{strPostfix: BaseAddress, MaxSize}: Combination's each information
# output: $TotalSize: Combination's SharePool total size
#****************************************************************************
sub DCMP_GetQueryInfo
{
    #$Output_table: %DCM_COMP_CODE_table{strPostfix: BaseAddress, MaxSize}
    my ($RamBottomAddress, $combination, $Output_table) = @_;
    my $TotalSize =0; #output: TotalRequiredSize
    
    my %TotalPool;
    foreach my $strPostfix (@$combination)
    {   
        my ($SharePoolNum, $MaxSize) = DCMP_query_SharePoolInfo($strPostfix);
        if(!defined $TotalPool{$SharePoolNum})
        {
            $RamBottomAddress -= $MaxSize;
            $TotalPool{$SharePoolNum}= [$MaxSize, $RamBottomAddress];
        }
        $Output_table->{$strPostfix} = [$TotalPool{$SharePoolNum}->[1], $MaxSize];
        #print "(strPostfix, base, size)=($strPostfix, $Output_table->{$strPostfix}->[0], $Output_table->{$strPostfix}->[1])\n";
    }
    foreach my $size (values %TotalPool)
    {
        $TotalSize += $size->[0];
    }
    #print "TotalSize=$TotalSize\n";
    return $TotalSize;
}
#****************************************************************************
# subroutine:  Get DCM Compression's combination
# input: x
# output: Combination total Size and Layout
#****************************************************************************
sub DCMP_GetCombination
{
    my @combination;
    DCMP_NoInputDie();
    foreach my $region (keys %g_DCMRegionPoolMap)
    {
       push(@combination, $region);
    }
    my $nSize = @combination;
    if($nSize==0)
    {
        &sysUtil::sysgen_die("[1.1]DCM Compression combination=0, please check feature option or turn off DCM Compression.", __FILE__, __LINE__);
    }
    return \@combination;
}
#****************************************************************************
# subroutine:  NOR Layout :: DCMP_Get_MM_IME_subRegionInfo :: SubRegions layout of MM/IME
#              for dcm compression
# input:   $strheadRegion: the head region of MM/IME group
#          $nBaseAddr: base address of head region
#          $nPrevMaxSize:  the previous region's maxsize
# output:  
#****************************************************************************
sub DCMP_Get_MM_IME_subRegionInfo
{
    my ($strheadRegion, $nBaseAddr, $nPrevMaxSize) = @_;
    my @Info;
    my $subRegionArray_ref;
    if(&FileInfo::is("DCM_MM_IMEHW_SUPPORT", "TRUE"))
    {
       if(&FileInfo::is("MMI_VERSION", "COSMOS_MMI"))
       {
           $subRegionArray_ref = &sysUtil::DCMP_query_IME_subRegion($strheadRegion);
       }
       else
       {
           $subRegionArray_ref = &sysUtil::DCMP_query_MM_subRegion($strheadRegion);
       }
    }
    foreach (@$subRegionArray_ref)
    {
        my $strPostfix = $_;
        $nBaseAddr += $nPrevMaxSize;
        my $nMaxSize = DCMP_GetRegionSize($strPostfix);
        $nPrevMaxSize = $nMaxSize;
        
        push(@Info, [$strPostfix, $nBaseAddr, $nMaxSize]);
    }
    return \@Info;
}

#****************************************************************************
# subroutine: DCMP_GetRegionSize
# purpose : Exec View :: MM/IME DCM regions :: Size Of MM/IME DCM regions
# Input:   $strRegion: e.g. MDP (DCM id)
# Output:  the size of DCMP regions
#****************************************************************************
sub DCMP_GetRegionSize  # head(0x40) + body
{   
    my ($strRegion) = @_;
    DCMP_NoInputDie();
    return $g_DCMPSize{$strRegion};
}

#****************************************************************************
# subroutine: DCMP_query_MM_IME_Grouplength
# purpose : Exec View :: MM/IME DCM regions :: Size Of MM/IME DCM MaxGroupregions
# Input:   $strRegion: e.g. MDP (DCM id)
# Output:  the max size of MM/IME Groupregions
#****************************************************************************
sub DCMP_query_MM_IME_Grouplength
{
    my ($strRegion) = @_;
    my $nMaxSize = 0;
    # --- --- --- 
    my $isCOSMOS = &FileInfo::is("MMI_VERSION", "COSMOS_MMI");
    my $nVKLAYOUTGroupSize =0;
    $nVKLAYOUTGroupSize =     &GetGroupSize("VKLAYOUT", $isCOSMOS) if($isCOSMOS);
    my $nMDPGroupSize =       &GetGroupSize("MDP", $isCOSMOS);
    my $nVECOMGroupSize =     &GetGroupSize("VECOM");
    my $nCAMCALGroupSize =    &GetGroupSize("CAMCAL");
    my $nMDICAMGroupSize =    &GetGroupSize("MDICAM");
    my $nVIDMSGGroupSize =    &GetGroupSize("VIDMSG");
    my $nMWWEBCAMGroupSize =  &GetGroupSize("MWWEBCAM");
    my $nMDIMTVGroupSize =    &GetGroupSize("MDIMTV");
    my $nMDISTREAMGroupSize = &GetGroupSize("MDISTREAM");

    my @OverLaygroup;
    push(@OverLaygroup, $nMDICAMGroupSize, $nVIDMSGGroupSize, $nMWWEBCAMGroupSize, $nMDIMTVGroupSize, $nMDISTREAMGroupSize);
    my $MMwithIME_size = ($nMDPGroupSize > $nVKLAYOUTGroupSize)? $nMDPGroupSize : $nVKLAYOUTGroupSize;

    my @OverLaygroup_sort =  sort {$b <=> $a} @OverLaygroup;
    my $OverLaygroup_size = $OverLaygroup_sort[0];
    
    my %BBtbl_size =
       (        
                'MDP'           => $MMwithIME_size,
                'VECOM'         => $nVECOMGroupSize,
                'CAMCAL'        => $nCAMCALGroupSize,
                'MDICAM'        => $OverLaygroup_size,
       );
    $nMaxSize = $BBtbl_size{$strRegion};
    return $nMaxSize;
}
sub GetGroupSize
{
    my ($strName, $bQueryIMEMM_Overlay) = @_;
    my $nGroupSize = DCMP_GetRegionSize($strName);
    my $subRegion_aref = ($bQueryIMEMM_Overlay)?  &sysUtil::DCMP_query_IME_subRegion($strName) 
                                               :  &sysUtil::DCMP_query_MM_subRegion($strName);
    foreach (@$subRegion_aref)
    {
        $nGroupSize += DCMP_GetRegionSize($_);
    }
    return $nGroupSize;
}

sub DCMP_NoInputDie
{
    if(!defined %g_DCMPSize or !defined %g_DCMPoolInfo or !defined %g_DCMRegionPoolMap or !defined %g_DCMPoolSize)
    {
        my ($pack_name, $file, $line_no) = caller;
        scatUtil_die("[2.0]Please use ParseDCMP() before using any DCMP functions!", $file, $line_no);
    }
}


#****************************************************************************
# subroutine: DCMP_MAUIINIT_Layout
# purpose :   layout for DYNAMIC_COMP_MAUIINIT region. In maui system, there are some codes, which 
#             will only be executed in maui_init stage by once. For these codes, DCM mechanism can be used
#             in order to save RAM size. The execution view is overlap with another region, and will be released 
#             before system schedule. this region base-address setting is different from other general DCM regions,
#             and will be maintained specially
# Input:      $bb:  bb chip
# Output:     $template: layout of  Load View+Execution View
#****************************************************************************
sub DCMP_MAUIINIT_Layout
{
    my $bb = shift;
    my $template = undef;
    my $strNextRegion = (&sysUtil::is_arm9($bb)==1 or &sysUtil::is_arm11($bb)==1)? "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_FLMM_PASPACE" : "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI";
    if(&FileInfo::is("DCM_COMPRESSION_MAUI_INIT", "TRUE"))
    {
     #   Low
      #+------------------+ -> ImageBase(DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL)
      #|     ZIMAGE       |
      #|  working buffer  |
      #+------------------+ -> 40*1024=40960=0xA000
      #|                  |
      #|                  |
      #|     MAUIINIT     |
      #|                  |
      #+------------------+
    #   High
        $template = << "__TEMPLATE";
DYNAMIC_COMP_MAUIINIT +0x0 ALIGN 32 
{ 
; 32byte aligned to support dynamically switchable cachability 
    DYNAMIC_COMP_MAUIINIT SetAddress(ImageBase(DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL)+0xA000,ALIGNMENT_32B) OVERLAY 0x40
    {
        * (DYNAMIC_COMP_MAUIINIT_HEAD) 
    }
    DYNAMIC_COMP_MAUIINIT_BODY +0x0 OVERLAY 
    {
        * (DYNAMIC_COMP_MAUIINIT_SECTION) 
    } 
    ScatterAssert(ImageLimit(DYNAMIC_COMP_MAUIINIT_BODY) < ImageBase($strNextRegion))
}        
__TEMPLATE
    }
    chomp($template);
    return $template;
}


#****************************************************************************
# subroutine:  scatUtil_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub scatUtil_die
{
    my ($error_msg, $file, $line_no) = @_;
    (my $pack_name, $file, $line_no) = caller if(!defined $file and !defined $line_no);
    &sysUtil::error_handler($error_msg, $file, $line_no, 'scatUtility');
}
