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
#*   config_MemSegment.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This module collects the subroutines for common utility. 
#*       
#*
#* Author:
#* -------
#*   Carina Liao (mtk04017)
#*
#****************************************************************************/
package memConfig;
use strict;
#use warnings;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use sysgenUtility;                 #pm file name without case sensitivity
use CommonUtility;
use FileInfoParser;
use tools::pack_dep_gen;
PrintDependModule();

#****************************************************************************
# Constants
#****************************************************************************
my $CONFIGMEMSEGMENT_VERNO   = " v0.09";
                               # v0.09 , 2013/09/23,  A verno-number is reserved for the new trunk branch 11C
                               # p0.08 , 2013/08/16,  Move and re-org nor flash block query functions from scatGen.pl and scatGenLib.pl to here 
                               # p0.07 , 2013/05/03,  Use five more blocks size as SDS spare size on MT6260 NAND project
                               # v0.05 , 2012/10/31,  Move is_NOR() from sysGenUtility to FileInfoParser to support general query
                               # v0.04 , 2012/07/26,  Add some error handling
                               # v0.03 , 2012/07/10,  Support EWS via tools::pack_dep_gen
                               # v0.02 , 2012/05/29,  Provide Get_bin_comp_value() to support MBA with compression
                               # v0.01 , 2012/05/14,  Initial revision
#Parse File Type
use constant CUSTOM_FLASH                => "CUSTOM_FLASH";     
#****************************************************************************
# Global variable
#****************************************************************************
my %g_MemConfigValues;
my $DebugPrint    = 0; # 1 for debug; 0 for non-debug
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# subroutine:  Get_SDS_total_size: To get the SDS total size according to the block size
# input: 	     $block_size : the block size for SDS
#              $feature_config_ref : a hash reference to query defined values in custom_FeatureConfig.h
#              $feature_option_ref : a hash reference to query feature options in projec.mak
# return:      $sds_total_size
#****************************************************************************
sub Get_SDS_total_size
{
    
    my ($block_size, $feature_config_ref, $feature_option_ref) = @_;
    my $sds_data_size  = 0;
    my $sds_spare_size = 0;
    my $sds_total_size = 0;
    if(&FileInfo::is_NOR($feature_option_ref) != 1)
    {
        $sds_data_size  = (defined $feature_config_ref->{'SDS_MAX_SIZE'}) ? hex($feature_config_ref->{'SDS_MAX_SIZE'}) : 256*1024;
        $sds_spare_size = (defined $feature_config_ref->{'SDS_RESERVED_SIZE_FOR_BBM'}) ? hex($feature_config_ref->{'SDS_RESERVED_SIZE_FOR_BBM'}) : 256*1024;
        $sds_spare_size += 640*1024 if($feature_option_ref->{'platform'} eq "MT6260");
    }
    else
    {
        my $mode = $feature_option_ref->{'MODE'};
        my $two_blocks_size = 2 * $block_size; #the number of blocks for SDS need to be 2N
        
        if(defined $feature_config_ref->{'SDS_MAX_SIZE'})
        {
            $sds_data_size = hex($feature_config_ref->{'SDS_MAX_SIZE'});
        }
        elsif(($mode eq 'GSM') or ($mode eq 'GPRS'))
        {
            my $sds_temp_size = 0;
            &config_die("Input parameter: Block Size($block_size) can't be less than 1",__FILE__, __LINE__) 
                if(!defined $block_size or $block_size <= 0);
            while($sds_temp_size < 32*1024)
            {
                $sds_temp_size += $two_blocks_size;
            }
            $sds_data_size = ($block_size <=  12*1024) ? $sds_temp_size : $two_blocks_size;
        }
        else
        {
            my $sds_temp_size = 0;
            &config_die("Input parameter: Block Size($block_size) can't be less than 1",__FILE__, __LINE__) 
                if(!defined $block_size or $block_size <= 0);
            while($sds_temp_size < 128*1024)
            {
                $sds_temp_size += $two_blocks_size;
            }
            $sds_data_size = ($block_size <=  64*1024) ? $sds_temp_size : $two_blocks_size;
        }
    }
    
    $sds_total_size = $sds_data_size + $sds_spare_size;
    
    return $sds_total_size;
}

#****************************************************************************
# subroutine:  Get_bin_comp_value: To get bin size defined in custom_FeatureConfig.h
# input:       $feature_config_href : the hash reference of custom_FeatureConfig.h
#              $strBIN_name : the binary name
# return:      $nBIN_configSize : the compressed size of the input binary name in custom_Featureconfig.h                                  
#****************************************************************************
sub Get_bin_comp_value
{
    my ($feature_config_href, $strBIN_name) = @_;
    my $nBIN_configSize = undef;
    my $strBIN_configName;
    my $strBIN_compNAME;

    $strBIN_configName = 'CONFIG_'.$strBIN_name.'_MAX_COMPRESSED_SIZE';
    $strBIN_compNAME = $strBIN_name.'_COMPRESS';
    my $need_comp = $feature_config_href->{$strBIN_compNAME};
    $nBIN_configSize   = hex($feature_config_href->{$strBIN_configName}) if ($need_comp);

    return $nBIN_configSize;
}

#****************************************************************************
# subroutine:  config_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub config_die
{
    my ($error_msg, $file, $line_no) = @_;
    &sysUtil::error_handler($error_msg, $file, $line_no, 'config_MemSegment');
}


sub Parse
{
    my ($strFilePath,$Source,$bIsDummy) = @_;
    my %Results;
    if($Source eq CUSTOM_FLASH)
    {
        &_ParseFlashInfo($strFilePath, \%Results); 
        &_PostProcessFlashSize(\%Results,$bIsDummy);
    }
    else
    {
        &config_die("Input file is not recongnized: $Source",__FILE__,__LINE__);
    }
    $g_MemConfigValues{$Source} =  \%Results;

    if($DebugPrint)
    {
        my $hash_ref = $g_MemConfigValues{$Source};
        print "$strFilePath:\n";
        print "BlockTBLTxt = $hash_ref->{'BlockTBLTxt'}\n";
        print "RegionInfoTxt = $hash_ref->{'RegionInfoTxt'}\n";
        print "BankInfoTxt = $hash_ref->{'BankInfoTxt'}\n";
        print "NOR_FLASH_DENSITY = $hash_ref->{'NOR_FLASH_DENSITY'}\n";
        print "\n";
    }
}

#****************************************************************************
# Subroutine: _ParseFlashInfo
# Purpose:     Parse key definition in CUSTOM_FLASH_H
# Input:         1. $strFilePath, 2. $Hash_ref(Result Container)
# Outpur:       None, save in $Hash_ref
#****************************************************************************
sub _ParseFlashInfo
{
    my ($strFilePath, $Hash_ref) = @_;
    my (@BLK_LIST, @REGION_LIST, @BANK_LIST);
    open (FLASHC_HANDLE, "<$strFilePath") or &config_die("[3.2]$strFilePath: file error!", __FILE__, __LINE__);
    while (<FLASHC_HANDLE>) {
       if (/^FLASH_REGIONINFO_VAR_MODIFIER\s+FlashBlockTBL\s+\S+/)
       {
          $Hash_ref->{'BlockTBLFlag'} ++;
       }
       elsif (defined $Hash_ref->{'BlockTBLFlag'})
       {
          $Hash_ref->{'BlockTBLTxt'} .= $_;
          # debug purpose
          # print $_;
          if (/\{\s*(\S+)\s*,\s*(\S+)\s*\}/)
          {
                push @BLK_LIST, $_;
          }
          delete $Hash_ref->{'BlockTBLFlag'} if (/^\s+EndBlockInfo\s+/);
       }
       elsif (/^FLASH_REGIONINFO_VAR_MODIFIER\s+FlashRegionInfo\s+oriRegionInfo\S+/)
       {
          $Hash_ref->{'RegionInfoFlag'} ++;
       }
       elsif (exists $Hash_ref->{'RegionInfoFlag'})
       {
          $Hash_ref->{'RegionInfoTxt'} .= $_;
          if (/\{\s*(\S+)\s*,\s*(\S+)\s*\}/)
          {
             push @REGION_LIST, $_;
          }
          delete $Hash_ref->{'RegionInfoFlag'} if (/^\s+EndoriRegionInfo\s+/);
       }
       elsif (/^static\s+NORBankInfo\s+oriBankInfo\S+/)
       {
          $Hash_ref->{'BankInfoFlag'} ++;
       }
       elsif (exists $Hash_ref->{'BankInfoFlag'})
       {
          $Hash_ref->{'BankInfoTxt'} .= $_;
          if (/\{\s*(\S+)\s*,\s*(\S+)\s*\}/)
          {
             push @BANK_LIST, $_;
          }
          delete $Hash_ref->{'BankInfoFlag'} if (/^\s+EndBankInfo\s+/);
       }
       elsif (/^\s*\*\s+NOR_FLASH_DENSITY:\s*(\w*)/)
       {
       	  $Hash_ref->{'NOR_FLASH_DENSITY'} = $1;
       }
       elsif (/^\s*\*\s+NOR_FLASH_SIZE\(Mb\):\s*(\w*)/)
       {
       	  $Hash_ref->{'NOR_FLASH_SIZE(Mb)'} = $1;
       }
    }
    close (FLASHC_HANDLE);

    $Hash_ref->{'BLK_LIST'}= \@BLK_LIST;
    $Hash_ref->{'REGION_LIST'} = \@REGION_LIST;
    $Hash_ref->{'BANK_LIST'} = \@BANK_LIST;
}

sub _PostProcessFlashSize
{
    my ($hash_ref,$is_dummy) = @_;
    &_SetBlockTable($hash_ref);
    $hash_ref->{'CODESize'} = $is_dummy ? 0x8000000 : hex($hash_ref ->{'NOR_FLASH_DENSITY'});
}


#****************************************************************************
# Subroutine:  _SetBlockTable
# Purpose:     To gather Block Table
# Input:       $hash_ref(Result Container)
# Output:      None, save in $hash_ref      
#****************************************************************************
sub _SetBlockTable
{
    my $hash_ref = shift;
    my $FLASH_H_Value_BLK_LIST_aref = $hash_ref -> {'BLK_LIST'};
    my @FLASH_H_Value_BLK_LIST = @$FLASH_H_Value_BLK_LIST_aref;
  if (scalar(@FLASH_H_Value_BLK_LIST) > 0)
  {
    my %blk_href;
    foreach(@FLASH_H_Value_BLK_LIST)
    {
        if (/\{(0x\w+),\s*(0x\w+)\}/)
    	{
    	    $blk_href{hex($1)} = hex($2);
    	}
    }
    $hash_ref ->{'BLK_TABLE'} = \%blk_href;
  }
}

#****************************************************************************
# Subroutine:  Get_flash_block_size
# Purpose:     Query flash block size
# Input:         
#              $offset:  flash offset address
#              $bIsDummy: is dummy scatter or not
# Output:      Flash block size
#****************************************************************************
sub Get_flash_block_size
{
    my ($offset,$flash_size) = @_;  
    my $source = CUSTOM_FLASH;
    $flash_size = $g_MemConfigValues{$source}->{'CODESize'} if (!defined $flash_size || $flash_size==0);
    &config_die("[2.0]Query Block Size at $offset larger than available size($flash_size)!", __FILE__, __LINE__) if ($offset > $flash_size);

    my $hash_ref = $g_MemConfigValues{$source}->{'BLK_TABLE'}; 
    &config_die("[3.2]Block Size Information Unavailable, Please check EMI DataBase and custom_flash.c!", __FILE__, __LINE__) unless defined $hash_ref;

    my @offset = sort {$b <=> $a} keys %$hash_ref;
    foreach my $i (@offset)
    {
        return $hash_ref->{$i} if ($offset >= $i);
    }
    
    &config_die("[3.2]The configuration of block size in custom_flash.h is incorrect!", __FILE__, __LINE__);
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query Next Block-aligned Addr from input Addr   
# Input:       
#              $addr: Address, Offset to the next destination
#              $offset: flash offset address
#              $bIsDummy: is dummy scatter or not
# Output:      Next block-aligned addr
#****************************************************************************
sub Get_next_block_aligned_addr
{
    my ($addr,$offset,$flash_size) = @_;
    my $source = CUSTOM_FLASH;
    $flash_size = $g_MemConfigValues{$source}->{'CODESize'} if (!defined $flash_size || $flash_size==0);
    &config_die("[2.0]Query Block-aligned addr at ($addr + $offset) larger than available size: $flash_size!", __FILE__, __LINE__) if (($addr+$offset) > $flash_size);

    my $tmp_addr = $addr;
    while ($tmp_addr < ($addr+$offset))
    {
        my $nblock_size = &Get_flash_block_size($source,$tmp_addr,$flash_size);
        $tmp_addr = ($tmp_addr % $nblock_size ==0) ? ($tmp_addr+$nblock_size) : (int($tmp_addr /$nblock_size)+1)*$nblock_size;
    }
    &sysUtil::sysgen_die("[2.0]Query Block-aligned addr at $tmp_addr larger than available size: $flash_size!", __FILE__, __LINE__) if ($tmp_addr > $flash_size);
    return $tmp_addr;
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query how many blocks needed by input address
# Input:        
#              $offset: flash offset address
#              $bIsDummy: is dummy scatter or not
# Output:      block-aligned addr
#****************************************************************************
sub Get_block_aligned_addr
{
    my ($offset) =@_;
    my $nBlockSize = 0;
    # to see how many blocks it needs.
    while ($nBlockSize < $offset)
    {
    	$nBlockSize += &Get_flash_block_size(CUSTOM_FLASH,$nBlockSize);
    }
    return $nBlockSize;
}


#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query Max Flash Block Size before offset
# input:       Flash Offset Address
# Output:      Flash block size
#****************************************************************************
sub Get_max_flash_block_size
{
    my ($offset,$flash_size) = @_;
    my $source = CUSTOM_FLASH;
    my $max_block_sz = 0;
    $flash_size = $g_MemConfigValues{$source}->{'CODESize'} if (!defined $flash_size || $flash_size==0);
    &sysUtil::sysgen_die("[2.0]Query Block Size at $offset larger than available size: $flash_size!", __FILE__, __LINE__) if ($offset > $flash_size);

    my $href   = $g_MemConfigValues{$source}->{'BLK_TABLE'};
    &sysUtil::sysgen_die("[3.2]Block Size Information Unavailable, Please check EMI DataBase and custom_flash.h!", __FILE__, __LINE__) unless defined $href;

    my @offset = sort {$b <=> $a} keys %$href;

    foreach my $i (@offset)
    {
        if ($offset > $i)
        {
            if (hex($max_block_sz) < hex($href->{$i}))
            {
               $max_block_sz = $href->{$i};
            }
        }
    }
    return $max_block_sz;
}

sub Get_source_info
{
    my $source = shift;
    return $g_MemConfigValues{$source};
}
