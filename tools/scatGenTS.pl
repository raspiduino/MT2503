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
#*   scatGenTS.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script designed as module to be include by top level perl script
#*
#* Author:
#* -------
#*   Yinli Liang  (mtk54166)
#*
#****************************************************************************/

use strict;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use sysGenUtility;                 #pm file name without case sensitivity
use CommonUtility;
#global variables
my $FEATURE_QUERY_FUNCTION_PTR;
my $ref_BoardParameters;
my $TS_SCATTERFILE;
my $BB;

my $DebugPrint    = 1;             # 1 for debug; 0 for non-debug
#****************************************************************************
# Constants
#****************************************************************************
my $SCATGEN_TS_VERNO = " v0.02";
                     #  v0.02 , 2014/03/25 by Yinli, set a dummy end to restrict the max size of TINYSYS_ROM1 EV
                     #  v0.01 , 2014/02/21 by Yinli, initial draft

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
1;

#****************************************************************************
# MAIN INTERFACE
# input: 
#****************************************************************************
sub scatGenTS_main
{
    ($FEATURE_QUERY_FUNCTION_PTR, $ref_BoardParameters, $TS_SCATTERFILE) = @_;
    $BB = $ref_BoardParameters->{'BB'};
    #generate $TS_SCATTERFILE
    &GenerateFile($TS_SCATTERFILE, undef);
}

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
        print "$TS_SCATTERFILE is generated\n";
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
        &scatgenTS_die("[1.0]$strFilePath: the template must exist!", __FILE__, __LINE__);   
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
    open (FILE_HANDLE, $strFilePath) or &scatgenTS_die("[1.0]Cannot open $strFilePath\n", __FILE__, __LINE__);
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
                    or &scatgenTS_die("[2.0]$func() doesn't exist!\n", __FILE__, __LINE__);
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
    open (FILE, ">$strFilePath") or &scatgenTS_die("[1.0]Cannot open $strFilePath\n", __FILE__, __LINE__);
    print FILE $content;
    close FILE;
}

sub QueryFileName_TS
{
    my $filename;
    $filename = $1 if($TS_SCATTERFILE =~ /(\w+\.txt)/);
    return $filename;
}
sub GenVersion
{
    return "system auto generator". $SCATGEN_TS_VERNO;
}

sub GenDate
{
    my ($day, $month, $year) = (localtime)[3,4,5]; $month++; $year+=1900;
    return "$year/$month/$day";
}

#****************************************************************************
# subroutine:  GetTINYSYS_ROM1BaseAndSize
# description: get TINYSYS_ROM1 LV base and max-size
# Input:      
# Output:      
#****************************************************************************
sub GetTINYSYS_ROM1BaseAndSize()
{
    my ($strTS_ROM1_base,$strTS_ROM1_size) = &sysUtil::GetTS_IntsramInfo_under_tiny_mode($BB);
    return $strTS_ROM1_base. ' '. $strTS_ROM1_size;
}

#****************************************************************************
# subroutine:  GetTINYSYS_ROM2BaseAndSize
# description: get TINYSYS_ROM2 LV base and max-size
# Input:      
# Output:      
#****************************************************************************
sub GetTINYSYS_ROM2BaseAndSize()
{
    my ($strTS_ROM2_base,$strTS_ROM2_size);
    if($BB eq 'MT6260')
    {#use EMI to simulate DSPRAM for 60 demo
        my ($strTSMMDumpSize,$strAPDspramBakSize,$strAPIntsramBakSize,$strTSLogSize,$strTSResEmiSize,$strCSCIInfoSize) = &sysUtil::GetTS_ResMemSize($BB);
        my $total_res_size = hex($strCSCIInfoSize)+hex($strTSMMDumpSize)+hex($strAPDspramBakSize)+hex($strAPIntsramBakSize)+hex($strTSLogSize)+hex($strTSResEmiSize);
        $strTS_ROM2_size = $strTSResEmiSize;
        $strTS_ROM2_base = &CommonUtil::Dec2Hex($ref_BoardParameters->{'EXTSRAM'}-$total_res_size);
    }
    else
    {#on DSPRAM
        ($strTS_ROM2_base,$strTS_ROM2_size) = &sysUtil::GetTS_DspramInfo($BB);
    }

    return $strTS_ROM2_base.' '.$strTS_ROM2_size;
}

#****************************************************************************
# subroutine:  GetCSCI_DATABaseAndSize
# description: get execution region GetCSCI_DATABaseAndSize base and max-size
# Input:      
# Output:      
#****************************************************************************
sub GetCSCI_DATABaseAndSize
{
    my ($strCSCI_DATA_base,$strCSCI_DATA_size);
    my ($strTSMMDumpSize,$strAPDspramBakSize,$strAPIntsramBakSize,$strTSLogSize,$strTSResEmiSize,$strCSCIInfoSize) = &sysUtil::GetTS_ResMemSize($BB);
    if($BB eq 'MT6260')
    {#on EMI
        my $total_res_size = hex($strCSCIInfoSize)+hex($strTSMMDumpSize)+hex($strAPDspramBakSize)+hex($strAPIntsramBakSize)+hex($strTSLogSize)+hex($strTSResEmiSize); 
        $strCSCI_DATA_base = &CommonUtil::Dec2Hex($ref_BoardParameters->{'EXTSRAM'}-$total_res_size+hex($strTSResEmiSize)-hex($strCSCIInfoSize));
        $strCSCI_DATA_size = $strCSCIInfoSize;
    }
    else
    {#on DSPRAM
        my ($strDSPRAM_base,$strDSPRAM_size) = &sysUtil::GetTS_DspramInfo($BB);
        $strCSCI_DATA_base = &CommonUtil::Dec2Hex(hex($strDSPRAM_base)+hex($strDSPRAM_size)-hex($strCSCIInfoSize));
        $strCSCI_DATA_size = $strCSCIInfoSize;
    }    
    return $strCSCI_DATA_base .' '.$strCSCI_DATA_size;
}

#****************************************************************************
# subroutine:  GetTS_ROM1_DUMMY_ENDBase
# description: get TINYSYS_ROM1 EV end address
# Input:      
# Output:      
#****************************************************************************
sub GetTS_ROM1_DUMMY_ENDBase
{
    my ($strTS_ROM1_base,$strTS_ROM1_size) = &sysUtil::GetTS_IntsramInfo_under_tiny_mode($BB);
    my $nEnd_addr = hex($strTS_ROM1_base) + hex($strTS_ROM1_size);

    return sprintf("0x%08x",$nEnd_addr);
}

#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no, $strTitle) = @_;
       
    my $final_error_msg = "$strTitle ERROR: $error_msg at $file line $line_no : $!\n";
    print $final_error_msg;
    die $final_error_msg;
}

sub scatgenTS_die
{
    my ($error_msg, $file, $line_no) = @_;
    &error_handler($error_msg, $file, $line_no, 'SCATGEN_TS');
}

