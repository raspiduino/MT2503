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
#*   scatGenBL.pl
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
#*   Claudia Lo  (mtk01876)
#*
#****************************************************************************/

use strict;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use sysGenUtility;                 #pm file name without case sensitivity

#global variables
my $FEATURE_QUERY_FUNCTION_PTR;
my $BB;
my $EXTSRAM_SIZE;
my $BB_PATH;
my $MAUI_SCATTERFILE;
my $BL_SCATTERFILE;
my $EXT_BL_SCATTERFILE;
my $NFB;
my $SYSRAM_BASE;
my $SYSRAM_SIZE;
my $MAUI_BOOTLOADER_BASE;
my $MAUI_BOOTLOADER_SIZE;
my $MAUI_EXT_BOOTLOADER_BASE;
my $MAUI_EXT_BOOTLOADER_SIZE;
my $IOT_TOTAL_BUFFER_SIZE;

my ($READ_ONLY_BASE,$READ_ONLY_SIZE);
my ($EXT_BOOTLOADER_BASE,$EXT_BOOTLOADER_SIZE);
my $DebugPrint    = 1;             # 1 for debug; 0 for non-debug
#****************************************************************************
# Constants
#****************************************************************************
my $SCATGEN_BL_VERNO = " v0.01";
                     #  v0.01 , 2014/01/03 by Yinli, initial draft

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
1;

#****************************************************************************
# MAIN INTERFACE
# input: 
#****************************************************************************
sub scatGenBL_main
{
    ($FEATURE_QUERY_FUNCTION_PTR, $BB, $EXTSRAM_SIZE, $BB_PATH, $MAUI_SCATTERFILE,$BL_SCATTERFILE) = @_;
    print "[scatGenBL_main]Input patameters:$FEATURE_QUERY_FUNCTION_PTR, $BB, $EXTSRAM_SIZE, $BB_PATH, $MAUI_SCATTERFILE,$BL_SCATTERFILE\n" if($DebugPrint);
  

    # ext_BL scatter file
    $EXT_BL_SCATTERFILE = $BL_SCATTERFILE;
    $EXT_BL_SCATTERFILE =~ s/.txt//;
    $EXT_BL_SCATTERFILE .= "_ext.txt";   

    #query booting mode
    $NFB = isNAND($FEATURE_QUERY_FUNCTION_PTR);

    #parse MAUI scatter to get Sys RAM and BL size info
    &parse_maui_scatterfile($MAUI_SCATTERFILE);

    #generate $BL_SCATTERFILE
    #              $EXT_BL_SCATTERFILE 
    &GenerateFile($BL_SCATTERFILE, undef);
    &GenerateFile($EXT_BL_SCATTERFILE, undef);
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
        &scatgenBL_die("[1.0]$strFilePath: the template must exist!", __FILE__, __LINE__);   
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
    open (FILE_HANDLE, $strFilePath) or &scatgenBL_die("[1.0]Cannot open $strFilePath\n", __FILE__, __LINE__);
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
                    or &scatgenBL_die("[2.0]$func() doesn't exist!\n", __FILE__, __LINE__);
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
    open (FILE, ">$strFilePath") or &scatgenBL_die("[1.0]Cannot open $strFilePath\n", __FILE__, __LINE__);
    print FILE $content;
    close FILE;
}


sub parse_maui_scatterfile
{
    my $maui_scatter = shift;

    open (SCATTER_H, "<$maui_scatter") or &scatgenBL_die("[1.0]$maui_scatter: file error!", __FILE__, __LINE__);
    while (<SCATTER_H>)
    {
        if (/\s*INTSRAM_MULTIMEDIA\s*(0x\w+)\s*\w*\s*(0x\w+)/)
        {
              $SYSRAM_BASE = $1;
              $SYSRAM_SIZE = $2;
        }
        elsif (/\s*EXT_BOOTLOADER\s*(0x\w+)\s*\w*\s*(0x\w+)/)
        {
            $MAUI_EXT_BOOTLOADER_BASE = $1;
            $MAUI_EXT_BOOTLOADER_SIZE = $2;
        }
        elsif (/\s*EXT_BOOTLOADER\s*(0x\w+)\s*\w*\s*/)
        {
            $MAUI_EXT_BOOTLOADER_BASE = $1;
            $MAUI_EXT_BOOTLOADER_SIZE = undef;
        }
        elsif (/^\s*BOOTLOADER\s*(0x\w+)\s*\w*\s*(0x\w+)/)
        {
            $MAUI_BOOTLOADER_BASE = $1;
            $MAUI_BOOTLOADER_SIZE = $2;
        }
        elsif (/^\s*BOOTLOADER\s*(0x\w+)\s*\w*\s*/)
        {
            $MAUI_BOOTLOADER_BASE = $1;
            $MAUI_BOOTLOADER_SIZE = undef;
        } 
    }
    close (SCATTER_H) or &scatgenBL_die("[1.0]$maui_scatter: file error!", __FILE__, __LINE__);
}

sub isNAND
{
    my ($func) = @_;
    my $nfb_or_emb;
    if (defined &$func('nand_flash_booting') and &$func('nand_flash_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$func('nand_flash_booting');
    }
    elsif (defined &$func('emmc_booting') and &$func('emmc_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$func('emmc_booting');
    }
    else
    {
          $nfb_or_emb = 'NONE';
    }
    return $nfb_or_emb; 
}

#-----------------------------------------------------------------------------
# Gen fucntions:
#-----------------------------------------------------------------------------
sub GenVersion
{
    return "system auto generator". $SCATGEN_BL_VERNO;
}

sub GenDate
{
    my ($day, $month, $year) = (localtime)[3,4,5]; $month++; $year+=1900;
    return "$year/$month/$day";
}
sub QueryFileName_BL
{
    my $filename;
    $filename = $1 if($BL_SCATTERFILE =~ /(\w+\.txt)/);
    return $filename;
}
sub QueryFileName_extBL
{
    my $filename ;
    $filename = $1 if($EXT_BL_SCATTERFILE =~ /(\w+\.txt)/);
    return $filename;
}

#****************************************************************************
#Functions for BL scatter file
#****************************************************************************
sub GetREAD_ONLYBaseAndSize
{
    if (&sysUtil::is_sv5($BB) == 1)
    {
        my %BBtbl_READ_ONLY_base =
        (
             'MT6276'  => '0x50000000',
             'MT6251'  => '0x40020000',
             'MT6256'  => '0x91004000',
             'MT6255'  => '0x40000900',
             'MT6922'  => '0x40000900',
             'MT6250'  => '0x70008000',
             'MT6260'  => '0x70006600',
             'MT6261_Family'  => '0x70006000',
        );

        my $bb = (&sysUtil::is_MT6261_Family($BB))? 'MT6261_Family'  : $BB;
        $READ_ONLY_BASE = &config_query_hash_bb(\%BBtbl_READ_ONLY_base, $bb, __LINE__);
    }
    else
    {
        my %BBtbl_READ_ONLY_base =
        (
             'MT6268'  => '0x92002000',
             'MT6235'  => '0x40002000',
             'MT6235B' => '0x40002000',
             'MT6236'  => '0x40002000',
             'MT6252'  => '0x00000000',
             'MT6253'  => '0x00000000',
             'MT6921'  => '0x40002000',
        );
        $READ_ONLY_BASE = '0x00000000'; # NOR+SV3 always starts from 0x0
        $READ_ONLY_BASE = &config_query_hash_bb(\%BBtbl_READ_ONLY_base, $BB, __LINE__) if ($NFB ne 'NONE');
    }
    
    $READ_ONLY_SIZE = "";
    $READ_ONLY_SIZE = $MAUI_BOOTLOADER_SIZE if($NFB eq 'NONE');
    return $READ_ONLY_BASE. ' '. $READ_ONLY_SIZE;
}
sub GenBL_GFH_SECTION_OnlySV5
{
    my $template = '';
    if (&sysUtil::is_sv5($BB) == 1)  # Only generate on SV5 platform
    {
        my @bl_gfh_section_libs = split("\n", &BL_GFH_SECTION_EV());
        map { s/^\s+//; } @bl_gfh_section_libs;
        $template = &format_execution_view('BL_GFH_SECTION',
	                                        '+0x0',
	                                        undef,
	                                        \@bl_gfh_section_libs);
    }
    chomp($template);
    return $template;
}
#****************************************************************************
# subroutine:  NFB Layout :: EXT_READ_ONLY
# return:      the body strings
#****************************************************************************
sub BL_GFH_SECTION_EV
{
    my $template = <<"__TEMPLATE";
         * (BOOTLOADER_GFH, +First)
         * (BOOTLOADER_GFH_EXT)
__TEMPLATE

    return $template;
}
sub GenBL_SecInfo_OnlySV3
{
    my $template = GetSecInfo_OnlySV3($READ_ONLY_BASE);
    return $template;
}
sub GetREAD_WRITEBase
{
    my $base = '';
    my $READ_WRITE_BASE_6921 = (($BB eq 'MT6921') and ($NFB ne 'NONE')) ? '+0x0' : '0x50000000';   
    my %BBtbl_READ_WRITE_base =
    (
         'MT6276'  => '+0x0',
         'MT6268'  => '+0x0',
         'MT6235'  => '+0x0',
         'MT6235B' => '+0x0',
         'MT6236'  => '+0x0',
         'MT6921'  => $READ_WRITE_BASE_6921,
         'MT6252'  => '0x40009000',
         'MT6251'  => '+0x0',
         'MT6253'  => '0x40000000',
         'MT6256'  => '+0x0',
         'MT6255'  => '+0x0',
         'MT6922'  => '+0x0',
         'MT6250'  => '+0x0',
         'MT6260'  => '+0x0',
         'MT6261_Family'  => '+0x0',
    );
    my $bb = (&sysUtil::is_MT6261_Family($BB))? 'MT6261_Family'  : $BB;  
    $base = &config_query_hash_bb(\%BBtbl_READ_WRITE_base, $bb, __LINE__);
    return $base;
}
sub GetREAD_ONLY_INTBase
{
    my $base = '';
    my %BBtbl_READ_ONLY_INT_base =
    (
         'MT6276'  => '0x5000C000',
         'MT6268'  => '0x92014000',
         'MT6235'  => '0x50008000',
         'MT6235B' => '0x50008000',
         'MT6236'  => '0x50008000',
         'MT6921'  => '0x50008000',
         'MT6252'  => '+0x0',
         'MT6251'  => '+0x0',
         'MT6253'  => '+0x0',
         'MT6256'  => '0x50000000', 
         'MT6255'  => '0x50000000',
         'MT6922'  => '0x50000000',
         'MT6250'  => '0x70004940',
         'MT6260'  => '0x70004000',
         'MT6261_Family'  => '0x70004000',
    );
    my $bb = (&sysUtil::is_MT6261_Family($BB))? 'MT6261_Family'  : $BB;
    $base = &config_query_hash_bb(\%BBtbl_READ_ONLY_INT_base, $bb, __LINE__);
    return $base;
}
sub GetREAD_WRITE_INTBase
{
    my $base = '';
    my %BBtbl_READ_WRITE_INT_base =
    (
         'MT6276'  => '0x5004C000',
         'MT6268'  => '0x50048000',
         'MT6235'  => '0x5002E000',
         'MT6235B' => '0x5002E000',
         'MT6236'  => '0x5004E000',
         'MT6921'  => '0x5004E000',
         'MT6252'  => '+0x0',
         'MT6251'  => '+0x0',
         'MT6253'  => '+0x0',
         'MT6256'  => '0x9100C000',
         'MT6255'  => '0x40006000',
         'MT6922'  => '0x40006000',
         'MT6250'  => '+0x0',
         'MT6260'  => '+0x0',
         'MT6261_Family'  => '+0x0',
    );
    my $bb = (&sysUtil::is_MT6261_Family($BB))? 'MT6261_Family'  : $BB;
    $base = &config_query_hash_bb(\%BBtbl_READ_WRITE_INT_base, $bb, __LINE__);
    return $base;
}
sub GenEMIINIT_CODEInfo
{
    my $template = '';
    if ((&sysUtil::is_sv5($BB) == 1) or ($NFB ne 'NONE'))
    {
	    $template .= &format_execution_view('EMIINIT_CODE',
	                                        '+0x0',
	                                        undef,
	                                        ["*                            (EMIINITZI)"]);
    }
    else
    {
        my %BBtbl_EMIINIT_CODE_base =
        (
             'MT6252'  => '0x40008000',
             'MT6251'  => '0x40000080',
             'MT6253'  => '0x40000000',
             'MT6255'  => '0x40000080',
             'MT6922'  => '0x40000080',
             'MT6921'  => '0x50000000',
        );
        my $emiinit_code_base = &config_query_hash_bb(\%BBtbl_EMIINIT_CODE_base, $BB, __LINE__) . " OVERLAY";
        $template .= &format_execution_view('EMIINIT_CODE',
                                            $emiinit_code_base,
                                            undef,
                                            ["*                            (EMIINITCODE, EMIINITCONST, EMIINITRW, EMIINITZI)"]);
    }
    chomp($template);
    return $template;
}
sub GenREAD_WRITE_SYS_RAMInfo
{
    my $template = '';
    if (($NFB ne 'NONE') and (&sysUtil::is_noSYSRAM($BB) != 1))  
    {# Only generate on NFB and which has SysRAM
        $template .= &format_execution_view('READ_WRITE_SYS_RAM',
                                            $SYSRAM_BASE,
                                            '0x2000',
                                            ["bl_ImageLoaderCommon.obj (INTERNZI)"]);
    }
    chomp($template);
    return $template;
}
sub GenBL_SIGNATURE_SECTION_OnlySV5
{
    my $template = '';
    if (&sysUtil::is_sv5($BB) == 1)  # Only generate on SV5 platform
	{
        $template .= &format_execution_view('BL_SIGNATURE_SECTION',
                                            '+0x0',
                                            undef,
                                            ["*                     (BL_SIGNATURE_SECTION)"]);	
	}
    
    chomp($template);
    return $template;
}
sub Gen__HIDDEN_BL_SECURE_MAC_OnlySV3
{
    my $template = '';
    if (&sysUtil::is_sv5($BB) != 1)
    {
        my $mac_overlay = '';
        $mac_overlay = "OVERLAY" if ($NFB ne 'NONE');
        $template = <<"__TEMPLATE";
;=========================================================================
; This load region must be behind all the protected load region
;=========================================================================
; do NOT modify load region naming and pragma naming!
;=========================================================================

__HIDDEN_BL_SECURE_MAC +0x0 $mac_overlay
{
    __HIDDEN_BL_SECURE_MAC +0x0 
    {
        *.obj (BL_SECURE_MAC_SIZE)
    }
    __HIDDEN_BL_SECURE_MAC_CONTENT +0x0
    {
        *.obj (BL_SECURE_MAC_CONTENT)
    }
    __HIDDEN_SECURE_MAC +0x0
    {
        *.obj (FOTA_SECINFO)
    }
}   
__TEMPLATE
        chomp($template);
    }
    
    return $template;
}

#****************************************************************************
#Functions for EXT_BL scatter file
#****************************************************************************
sub GetEXT_BOOTLOADERBaseAndSize
{
    my $ext_bl_update_support = &$FEATURE_QUERY_FUNCTION_PTR('ext_bl_update_support');
    if (defined $ext_bl_update_support and $ext_bl_update_support eq 'TRUE')
    {
        ### NAND: ExtMem size - 1M, NOR/N+0: fixed
        ### NAND: 1M, NOR: 512K, N+0:fixed
        if ($BB eq 'MT6251')
        {
            $EXT_BOOTLOADER_BASE = "0x40030000";
            $EXT_BOOTLOADER_SIZE = "0x30000";
        }
        elsif ($NFB ne 'NONE')
        {
            $EXT_BOOTLOADER_BASE = sprintf("0x%x", $EXTSRAM_SIZE - (1024*1024));
            $EXT_BOOTLOADER_SIZE = sprintf("0x%x", (1024*1024));
        }
        else
        {
            $EXT_BOOTLOADER_BASE = sprintf("0x%x", &sysUtil::query_cs1_addr($BB ,0, 1) + 72*1024);
            $EXT_BOOTLOADER_SIZE = sprintf("0x%x", (512*1024));
        }
    }
    else
    {
        if ($NFB ne 'NONE')
        {
            $EXT_BOOTLOADER_BASE = sprintf("0x%x", $EXTSRAM_SIZE - (1024*1024));
            $EXT_BOOTLOADER_SIZE = "";
        }
        else
        {
            $EXT_BOOTLOADER_BASE = sprintf("0x%08x", hex($MAUI_EXT_BOOTLOADER_BASE) & (~0xf8000000));
            $EXT_BOOTLOADER_SIZE = $MAUI_EXT_BOOTLOADER_SIZE;
            $EXT_BOOTLOADER_BASE = sprintf("0x%08x", hex($MAUI_EXT_BOOTLOADER_BASE)) if($BB eq "MT6255" or $BB eq "MT6922" or $BB eq "MT6250" or $BB eq "MT6260" or $BB eq "MT6261" or &sysUtil::is_MT6261_Family($BB));
        }
    }
    return $EXT_BOOTLOADER_BASE . ' ' . $EXT_BOOTLOADER_SIZE;
}

sub GenEXT_BL_GFH_SECTION_OnlySV5
{
    my $template = '';
    if (&sysUtil::is_sv5($BB) == 1)  # Only generate on SV5 platform
    {
	    $template .= &format_execution_view('EXT_BL_GFH_SECTION',
	                                        '+0x0',
	                                        undef,
	                                        ["*    (EXT_BOOTLOADER_GFH, +First)"]);
    }
    chomp($template);
    return $template;
}
sub GenEXT_BL_SecInfo_OnlySV3
{
    my $template = GetSecInfo_OnlySV3($EXT_BOOTLOADER_BASE);
    return $template;
}
sub GetEXT_READ_WRITEBase
{
    my $ext_read_write_base = '';
    my $ext_bl_update_support = &$FEATURE_QUERY_FUNCTION_PTR('ext_bl_update_support');
    if ($NFB ne 'NONE' or (defined $ext_bl_update_support and $ext_bl_update_support eq 'TRUE'))
    {
    	$ext_read_write_base = "+0x0";
    }
    else
    {
        if ($BB eq 'MT6251')
        {
    	    $ext_read_write_base = "0x40030000";
        }
        else
        {
            $ext_read_write_base = sprintf("0x%x", &sysUtil::query_cs1_addr($BB,0, 1) + 72*1024);
        }
    }
    return $ext_read_write_base;
}
sub GetEXT_READ_ONLY_INTBase
{
    my $base = '';
    my %BBtbl_EXT_READ_ONLY_INT_base =
    (
         'MT6276'  => '0x5000C000',
         'MT6268'  => '0x92014000',
         'MT6235'  => '0x50008000',
         'MT6235B' => '0x50008000',
         'MT6236'  => '0x50008000',
         'MT6921'  => '0x50008000',
         'MT6252'  => '0x40008080',
         'MT6251'  => '+0x0',
         'MT6253'  => '0x40000080',
         'MT6256'  => '0x50000000',
         'MT6255'  => '0x50000000',
         'MT6922'  => '0x50000000',
         'MT6250'  => '0x700040c0',
         'MT6260'  => '0x70005000',
         'MT6261_Family'  => '0x70005000',
    );
    my $bb = (&sysUtil::is_MT6261_Family($BB))? 'MT6261_Family'  : $BB;
    $base = &config_query_hash_bb(\%BBtbl_EXT_READ_ONLY_INT_base, $bb, __LINE__);
    return $base;
}

sub GenEXT_READ_ONLY_INTInputSections
{
	my $template;
	if ($BB eq 'MT6251')
	{
		$template = <<"__TEMPLATE";
         br_crypto_asm.obj            (+RO)
         br_crypto_drv*.obj           (+RO)
         br_sha256_sw.obj             (+RO)
         br_sha256_hw.obj             (+RO)
         br_sha1_sw.obj               (+RO)
         br_sha1_hw.obj               (+RO)
         br_rsa_sw.obj                (+RO)
         br_M1_rsa.obj                (+RO)
         br_crypto_platform.obj       (+RO)
         *                            (INTERNCODE)
__TEMPLATE
	}
	else
	{
		$template = <<"__TEMPLATE";
         sha1_engine.obj              (+RO)
         md5_engine.obj               (+RO)
         br_crypto_asm.obj            (+RO)
         br_crypto_drv*.obj           (+RO)
         br_sha256_sw.obj             (+RO)
         br_sha256_hw.obj             (+RO)
         br_sha1_sw.obj               (+RO)
         br_sha1_hw.obj               (+RO)
         br_rsa_sw.obj                (+RO)
         br_M1_rsa.obj                (+RO)
         br_crypto_platform.obj       (+RO)
         *                            (INTERNCODE)
__TEMPLATE
	}
	my $serial_flash_stt_support = &$FEATURE_QUERY_FUNCTION_PTR('serial_flash_stt_support');
    if (defined $serial_flash_stt_support and $serial_flash_stt_support eq 'TRUE')
    {
        my $stt_template = << "__TEMPLATE";
         divrt_9e.o                   (+RO)
         bl_STT_SF.obj                (+RO)
         bl_DBGPRINT.obj              (+RO)
         bl_UART.obj                  (+RO)
__TEMPLATE
        $template .= $stt_template;
    }
    chomp($template);
    return $template;
}
sub GetEXT_READ_WRITE_INTBase
{
    my $base = '';
    my %BBtbl_EXT_READ_WRITE_INT_base =
    (
         'MT6276'  => '0x5004C000',
         'MT6268'  => '0x50048000',
         'MT6235'  => '0x5002E000',
         'MT6235B' => '0x5002E000',
         'MT6236'  => '0x5004E000',
         'MT6921'  => '0x5004E000',
         'MT6252'  => '+0x0',
         'MT6251'  => '+0x0',
         'MT6253'  => '+0x0',
         'MT6256'  => '0x9100C000',
         'MT6255'  => '0x40006000',
         'MT6922'  => '0x40006000',
         'MT6250'  => '+0x0',
         'MT6260'  => '+0x0',
         'MT6261_Family'  => '+0x0',
    );
    my $bb = (&sysUtil::is_MT6261_Family($BB))? 'MT6261_Family'  : $BB;
    $base = &config_query_hash_bb(\%BBtbl_EXT_READ_WRITE_INT_base, $bb, __LINE__);
    return $base;
}
sub GenEXT_READ_WRITE_INTInputSections
{
	my $template;
	if ($BB eq 'MT6251')
	{
		$template = <<"__TEMPLATE";
         br_crypto_asm.obj            (+RW, +ZI)
         br_crypto_drv*.obj           (+RW, +ZI)
         br_sha256_sw.obj             (+RW, +ZI)
         br_sha256_hw.obj             (+RW, +ZI)
         br_sha1_sw.obj               (+RW, +ZI)
         br_sha1_hw.obj               (+RW, +ZI)
         br_rsa_sw.obj                (+RW, +ZI)
         br_M1_RSA.obj                (+RW, +ZI)
         br_crypto_platform.obj       (+RW, +ZI)
         *                            (INTERNDATA)
__TEMPLATE
	}
	else
	{
		$template = <<"__TEMPLATE";
         sha1_engine.obj              (+RW, +ZI)
         md5_engine.obj               (+RW, +ZI)
         br_crypto_asm.obj            (+RW, +ZI)
         br_crypto_drv*.obj           (+RW, +ZI)
         br_sha256_sw.obj             (+RW, +ZI)
         br_sha256_hw.obj             (+RW, +ZI)
         br_sha1_sw.obj               (+RW, +ZI)
         br_sha1_hw.obj               (+RW, +ZI)
         br_rsa_sw.obj                (+RW, +ZI)
         br_M1_RSA.obj                (+RW, +ZI)
         br_crypto_platform.obj       (+RW, +ZI)
         *                            (INTERNDATA)
__TEMPLATE
	}
    chomp($template);
    return $template;
}
sub GenDA_SHAREInfo_ForMT6251
{
    my $template = '';
    if ($BB eq 'MT6251')
    {
        my @da_share_libs = split("\n", &DA_SHARE_EV());
        map { s/^\s+//; } @da_share_libs;
	    $template .= &format_execution_view('DA_SHARE',
	                                        '0x40000A00',
	                                        undef,
	                                        \@da_share_libs);
        chomp($template);	                                        
    }
    return $template;
}
#****************************************************************************
# subroutine:  Layout :: DA_SHARE
# return:      the body strings
#****************************************************************************
sub DA_SHARE_EV
{
	my $template = <<"__TEMPLATE";
         *.l                          (+RO, +RW, +ZI)
         bl_bootarm.obj               (SHARECODE)
         bl_DBGPRINT.obj              (+RO, +RW, +ZI)
         bl_portingfunc.obj           (+RO, +RW, +ZI)
         bl_UART.obj                  (+RO, +RW, +ZI)
         sha1_engine.obj              (+RO, +RW, +ZI)
         md5_engine.obj               (+RO, +RW, +ZI)
         M1_rsa.obj                   (+RO, +RW, +ZI)
         SSS_interface.obj            (+RO, +RW, +ZI)
         SSS_secure_shared.obj        (+RO, +RW, +ZI)
__TEMPLATE
    chomp($template);
    return $template;
}
sub GenREAD_WRITE_SYS_RAMOrBL_INFO_NOR
{
    my $template = '';
    my %BBtbl_BL_INFO_NOR_base =  #Sysram Base
    (
         'MT6252'  => '0x40008000',
         'MT6251'  => '0x40000080',
         'MT6253'  => '0x40000000',
         'MT6921'  => '0x40000000',
         'MT6255'  => '0x40000000',
         'MT6922'  => '0x40000000',
         'MT6250'  => '0x70004040',
         'MT6260'  => '0x70004040',
         'MT6261_Family'  => '0x70004040',
    );
    my $bb = (&sysUtil::is_MT6261_Family($BB))? 'MT6261_Family'  : $BB;
    my $read_write_base = (&sysUtil::is_noSYSRAM($BB) == 1) ? &config_query_hash_bb(\%BBtbl_BL_INFO_NOR_base, $bb, __LINE__) : $SYSRAM_BASE;
    if ($NFB ne 'NONE')  # Only generate on NFB
    {
        $template .= &format_execution_view('READ_WRITE_SYS_RAM',
                                            $read_write_base,
                                            '0x2000',
                                            ["bl_ImageLoaderCommon.obj     (INTERNZI)"]);
    }
    else  # Only generate on NOR
    {
        $template .= &format_execution_view('BL_INFO_NOR',
                                            &config_query_hash_bb(\%BBtbl_BL_INFO_NOR_base, $bb, __LINE__),
                                            '0x80',
                                            ["*.obj                        (BL_INFO_NOR)"]);
    }
    chomp($template);
    return $template;
}
sub GenEXT_BL_SIGNATURE_SECTION_OnlySV5
{
    my $template = '';
	if (&sysUtil::is_sv5($BB) == 1)  # Only generate on SV5 platform
	{
	    $template .= &format_execution_view('EXT_BL_SIGNATURE_SECTION',
	                                        '+0x0',
	                                        undef,
	                                        ["*                            (EXT_BL_SIGNATURE_SECTION)"]);
	}
    chomp($template);
    return $template;
}

#****************************************************************************
# For IOT-FOTA
#****************************************************************************
sub GenEXT_BL_IOT_FOTA_WORKING_BUF
{
    my $template = '';
	my $ext_bl_IOT_FOTA_support = &$FEATURE_QUERY_FUNCTION_PTR('FUNET_ENABLE');
	my %BBtbl_BL_IOT_FOTA_WORKING_base =  #Sysram Base
    (
         'MT6260'  => '0x00072000',
		 'MT6261_Family'  => '0x00072000',
    );
	my $bb = (&sysUtil::is_MT6261_Family($BB))? 'MT6261_Family'  : $BB;
	my $IOT_FOTA_WORKING_base = &config_query_hash_bb(\%BBtbl_BL_IOT_FOTA_WORKING_base, $bb, __LINE__) ;
	$IOT_FOTA_WORKING_base = "$IOT_FOTA_WORKING_base EMPTY";
	# Only generate when "project".mak FUNET_ENABLE = FULL_IMAGE_UPDATE
	if (defined $ext_bl_IOT_FOTA_support and $ext_bl_IOT_FOTA_support eq 'FULL_IMAGE_UPDATE')  # Only generate when "project".mak FUNET_ENABLE = FULL_IMAGE_UPDATE
	{
	    $template .= &format_execution_view('EXT_BL_IOT_FOTA_WORKING_BUF',
	                                        $IOT_FOTA_WORKING_base,
	                                        '0xC800',
	                                        [""]);
	}
    chomp($template);
    return $template;
}

sub GenEXT_BL_IOT_FOTA_IMAGE_BUF
{
    my $template = '';
	my $ext_bl_IOT_FOTA_support = &$FEATURE_QUERY_FUNCTION_PTR('FUNET_ENABLE');
	my %BBtbl_BL_IOT_FOTA_IMAGE_base =  #Sysram Base
    (
         'MT6260'  		  => '0x00080000',
		 'MT6261_Family'  => '0x00080000',
    );
	my $bb = (&sysUtil::is_MT6261_Family($BB))? 'MT6261_Family'  : $BB;
	my $IOT_FOTA_IMAGE_base = &config_query_hash_bb(\%BBtbl_BL_IOT_FOTA_IMAGE_base, $bb, __LINE__) ;
	my $IOT_RAM_BASE  = hex($IOT_FOTA_IMAGE_base);
	$IOT_FOTA_IMAGE_base ="$IOT_FOTA_IMAGE_base EMPTY";
	
	# $IOT_IMAGE_BUF_SIZE should smaler than $IOT_DECOMPRESSION_BUF_SIZE
	# $IOT_DECOMPRESSION_BUF_SIZE + $IOT_IMAGE_BUF_SIZE should smaller than $IOT_TOTAL_BUFFER_SIZE
	$IOT_TOTAL_BUFFER_SIZE = (&sysUtil::query_cs1_addr($BB, 0, 1) + ($EXTSRAM_SIZE) - $IOT_RAM_BASE);
	my $IOT_IMAGE_BUF_SIZE =  sprintf("0x%x",($IOT_TOTAL_BUFFER_SIZE/2)-0x00010000 );
	# Only generate when "project".mak FUNET_ENABLE = FULL_IMAGE_UPDATE
	if (defined $ext_bl_IOT_FOTA_support and $ext_bl_IOT_FOTA_support eq 'FULL_IMAGE_UPDATE')  
	{
	    $template .= &format_execution_view('EXT_BL_IOT_FOTA_IMAGE_BUF',
	                                        $IOT_FOTA_IMAGE_base ,
	                                        $IOT_IMAGE_BUF_SIZE,
	                                        [""]);
	}
    chomp($template);
    return $template;
}

sub GenEXT_BL_IOT_FOTA_DECOMPRESSION_BUF
{
    my $template = '';
	my $ext_bl_IOT_FOTA_support = &$FEATURE_QUERY_FUNCTION_PTR('FUNET_ENABLE');
	# $IOT_IMAGE_BUF_SIZE should smaler than $IOT_DECOMPRESSION_BUF_SIZE
	# $IOT_DECOMPRESSION_BUF_SIZE + $IOT_IMAGE_BUF_SIZE should smaller than $IOT_TOTAL_BUFFER_SIZE
	my $IOT_DECOMPRESSION_BUF_SIZE = sprintf("0x%x",($IOT_TOTAL_BUFFER_SIZE/2)+0x00005000 );
	# Only generate when "project".mak FUNET_ENABLE = FULL_IMAGE_UPDATE
	if (defined $ext_bl_IOT_FOTA_support and $ext_bl_IOT_FOTA_support eq 'FULL_IMAGE_UPDATE')  
	{
	    $template .= &format_execution_view('EXT_BL_IOT_FOTA_DECOMPRESSION_BUF',
	                                       '+0x0 EMPTY',
	                                        $IOT_DECOMPRESSION_BUF_SIZE,
	                                        [""]);
	}
    chomp($template);
    return $template;
}

sub GenEXT_BL_IOT_FOTA_RAM_DUMMY_END
{
    my $template = '';
	my $ext_bl_IOT_FOTA_support = &$FEATURE_QUERY_FUNCTION_PTR('FUNET_ENABLE');

	my $RAM_DUMMY_END = sprintf("0x%x", &sysUtil::query_cs1_addr($BB, 0, 1) + ($EXTSRAM_SIZE - 4));
	# Only generate when "project".mak FUNET_ENABLE = FULL_IMAGE_UPDATE
	if (defined $ext_bl_IOT_FOTA_support and $ext_bl_IOT_FOTA_support eq 'FULL_IMAGE_UPDATE')  
	{
	    $template .= &format_execution_view('EXT_BL_IOT_FOTA_RAM_DUMMY_END',
	                                       $RAM_DUMMY_END,
	                                       '0x04',
	                                        ["*                            (EXT_BL_IOT_FOTA_RAM_DUMMY_END)"]);
	}
    chomp($template);
    return $template;
}


#****************************************************************************
#Functions shared in BL and EXT_BL
#****************************************************************************
sub GetSecInfo_OnlySV3
{
    my $base = shift;
    my $template = '';
    if (&sysUtil::is_sv5($BB) != 1)  # Only generate on non-SV5 platform
    {
    	my $bl_alg_table_base = sprintf("0x%x FIXED", hex($base)+0x400);
	    $template .= &format_execution_view('BL_ALG_TABLE',
	                                        $bl_alg_table_base,
	                                        undef,
	                                        ["*.obj (BL_ALG_TABLE)"]);
	    $template .= &format_execution_view('BL_SECINFO',
	                                        '+0x0',
	                                        undef,
	                                        ["*.obj (BL_SECINFO)"]);
    }
    chomp($template);
    return $template;
}
sub GetEXT_UN_INITBase
{
    # --- --- ---
    ### NAND: ExtMem size - 4M, NOR: ExtMem size - 1.5M, N+0: fixed
    my $ext_un_init_base = '';
    if ($BB eq 'MT6251')
    {
    	$ext_un_init_base = "0x40007000";
    }
    elsif ($NFB ne 'NONE')
    {
    	$ext_un_init_base = sprintf("0x%x", $EXTSRAM_SIZE - (4*1024*1024));
    }
    elsif($BB eq 'MT6260' or $BB eq 'MT6261')
	{
		$ext_un_init_base = "0x00033000"
	}	
	else
    {
    	$ext_un_init_base = sprintf("0x%x", &sysUtil::query_cs1_addr($BB, 0, 1) + ($EXTSRAM_SIZE - (1.5*1024*1024)));
		

    }
    return $ext_un_init_base;
}
sub GetSHARE_BUFBaseAndSize
{
    # --- --- ---
    ### NAND: 8K, NOR: 8K, N+0: Last 8K of IntRam
    ### N+0:4K, others: 64K
    my ($share_buf_base, $share_buf_size);
    if ($BB eq 'MT6251')
    {
    	$share_buf_base = "0x4005F000";
    	$share_buf_size = "0x1000"
    }
    elsif ($NFB ne 'NONE')
    {
    	$share_buf_base = sprintf("0x%x", 8*1024);
    	$share_buf_size = "0x10000";
    }
    else
    {
    	$share_buf_base = sprintf("0x%x", &sysUtil::query_cs1_addr($BB,0, 1)+(8*1024));
    	$share_buf_size = "0x10000";
    }
    return $share_buf_base . ' ' . $share_buf_size;
}
sub GetSTACK_AREABase
{
    my $base = '';
    my %BBtbl_STACK_AREA_base =
       (
             'MT6276'  => '0x5004F000',
             'MT6268'  => '0x50052800',
             'MT6235'  => '0x50033000',
             'MT6235B' => '0x50033000',
             'MT6236'  => '0x50053000',
             'MT6921'  => '0x50053000',
             'MT6252'  => '0x4000BC00',
             'MT6251'  => '0x4005E000',
             'MT6253'  => '0x4001F000',
             'MT6256'  => '0x50042000',
             'MT6255'  => '0x50041000',
             'MT6922'  => '0x50041000',
             'MT6250'  => '0x7000c400',
             'MT6260'  => '0x7000c000',
             'MT6261_Family'  => '0x70009000',
       );
    my $bb = (&sysUtil::is_MT6261_Family($BB))? 'MT6261_Family'  : $BB;
    $base = &config_query_hash_bb(\%BBtbl_STACK_AREA_base, $bb, __LINE__);
    return $base;
}
sub GetDUMMY_ENDBase
{
    my $base = '';
    my %BBtbl_DUMMY_END_base =
    (
         'MT6276'  => '0xC8014000',
         'MT6268'  => '0x92018000',
         'MT6235'  => '0x40010000',
         'MT6235B' => '0x40010000',
         'MT6236'  => '0x40010000',
         'MT6921'  => '0x40010000',
         'MT6252'  => '0x4000cc00',
         'MT6251'  => '0x40060000',
         'MT6253'  => '0x40020000',
         'MT6256'  => '0x91010000',
         'MT6255'  => '0x40007000',
         'MT6922'  => '0x40007000',
         'MT6250'  => '0x7000d400',
         'MT6260'  => '0x7000d000',
         'MT6261_Family'  => '0x7000A000',
    );
    my $bb = (&sysUtil::is_MT6261_Family($BB))? 'MT6261_Family'  : $BB;
    $base = &config_query_hash_bb(\%BBtbl_DUMMY_END_base, $bb, __LINE__);
    return $base;
}

#****************************************************************************
# subroutine:  config_query_hash_bb
# return:      address/size defined in the input hash of the input bb
#****************************************************************************
sub config_query_hash_bb
{
    my ($href, $bb, $Line) = @_;
    print "$bb\n";
    if (not exists $href->{$bb})
    {
        &scatgenBL_die("[2.0]Unsupported Bootloader Scatter information on $bb !\n",__FILE__, $Line);
    }

    return $href->{$bb};
}
#****************************************************************************
# subroutine:  Execution View Generator
# input:       Region name [string], Begin [string], Length [string], Content [Array Reference]
# output:      execution view body string
#****************************************************************************
sub format_execution_view
{
    my ($name, $begin, $length, $ar) = @_;
    my $formated_string = ' ' x 4 . $name . " $begin $length\n";
    $formated_string .= ' ' x 4 . "{\n";
    foreach (@$ar)
    {
        $formated_string .= ' ' x 9 . $_ . "\n";
    }
    $formated_string .= ' ' x 4 . "}\n";
    return $formated_string;
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

sub scatgenBL_die
{
    my ($error_msg, $file, $line_no) = @_;
    &error_handler($error_msg, $file, $line_no, 'SCATGEN_BL');
}

