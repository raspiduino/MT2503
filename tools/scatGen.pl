#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2007
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
#*   scatGen.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script aim to generate scatter file base on Makefile and custom_EMI.h
#*       1. generate scatter file if not exists
#*
#* Author:
#* -------
#*   JI Huang  (mtk01077)
#*
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use sysGenUtility;                 #pm file name without case sensitivity
use FileInfoParser;
use config_MemSegment;
use CommonUtility;
use tools::pack_dep_gen;
use File::stat;
PrintDependModule();

#****************************************************************************
# Global Variables
#****************************************************************************
my ($NOR_FLASH_BASE_ADDRESS_VAL, $NOR_ALLOCATED_FAT_SPACE_VAL, $ori_NOR_FLASH_BASE_ADDRESS_VAL);
# FactoryBin Size
my $nFactoryBinSize = 0;
my $DebugPrint = 1; # 1 for debug; 0 for non-debug
my $g_USE_DUMMY_SCATTER = "FALSE";
my %MAKEFILE_OPTIONS;
#****************************************************************************
# File Names
#****************************************************************************
my $SCATTERFILE           = $ARGV[0];
my $BL_SCATTERFILE        = $ARGV[1];
my $FOTA_SCATTERFILE      = $ARGV[2];
my $themf                 = $ARGV[3];
my $BB_PATH               = $ARGV[4];
my $CUSTOM_EMI_H          = $ARGV[4] . '\\' . "custom_EMI.h";
my $CUSTOM_EMI_RELEASE_H  = $ARGV[4] . '\\' . "custom_EMI_release.h";
my $CUSTOM_MEM_DEV_H      = $ARGV[4] . '\\' . "custom_MemoryDevice.h";
my $CUSTOM_FEATURECONFIG_H = $ARGV[4] . '\\' . "custom_FeatureConfig.h";
my $CUSTOM_FLASH_H        = $ARGV[4] . '\\' . "custom_flash.h";
my $FLASH_OPT_GEN_H       = $ARGV[4] . '\\' . "flash_opt_gen.h";
my $CUSTOM_SECURE_CONFIG_H = $ARGV[4] . '\\' . "custom_secure_config.h";
my $CUSTOM_IMG_CONFIG_H   = $ARGV[4] . '\\' . "custom_img_config.h";
my $TS_MEM_CONFIG_H       = $ARGV[4] . '\\' . "ts_mem_config.h"; # for tiny_system
my $NEED_BUILD_BOOTLOADER = $ARGV[5];
my $INSIDE_MTK            = $ARGV[6];  # INSIDE_MTK (need to check dummy_scatter_enable)
my $DUMMY_SCATTER_FORCE   = $ARGV[7];  # DUMMY_LIS (from gendummylis)
my $FACTORY_BIN_PATH      = $ARGV[8];
my $OBJ_SYS_AUTO_GEN       = $ARGV[9]; # trigger 2-phase linking
my $TS_SCATTERFILE        = $ARGV[10]; # for tiny_system
# to align error message file name format
$SCATTERFILE =~ s/^.\\|^\\//;
$themf       =~ s/^.\\|^\\//;
$BB_PATH     =~ s/^.\\|^\\//;

# DL scat: scatter file for flash tool to download images
my $DL_SCATTERFILE = $SCATTERFILE;
$DL_SCATTERFILE =~ s/.txt//;
$DL_SCATTERFILE .= "_flashtool.txt";
my $DL_Wateramrk = ';AutoGen Copyed from';

# ext_BL scatter file
my $EXT_BL_SCATTERFILE = $BL_SCATTERFILE;
$EXT_BL_SCATTERFILE =~ s/.txt//;
$EXT_BL_SCATTERFILE .= "_ext.txt";

#Dummy scatter Watermark
my $DUMMY_SCATTER_Watermark = ' (Dummy scatter)';


#****************************************************************************
# 1 >>> main judges : scatter file exists or not
#****************************************************************************
&sysUtil::del_noCheckinHistory_file($CUSTOM_SECURE_CONFIG_H);
&sysUtil::del_noCheckinHistory_file($CUSTOM_IMG_CONFIG_H);
&sysUtil::del_noCheckinHistory_file($TS_MEM_CONFIG_H);
&sysUtil::del_noCheckinHistory_file($FOTA_SCATTERFILE);
&sysUtil::del_noCheckinHistory_file($SCATTERFILE);
&sysUtil::del_noCheckinHistory_file($DL_SCATTERFILE);
# DL_scatter with watermark($DL_Wateramrk) and Check-in history will be deleted.
# -> Always regen copyed file.
&DelFileWithKeyword($DL_SCATTERFILE, $DL_Wateramrk);

if (-e $SCATTERFILE and -e $DL_SCATTERFILE and -e $BL_SCATTERFILE and -e $EXT_BL_SCATTERFILE 
    and -e $FOTA_SCATTERFILE and -e $CUSTOM_SECURE_CONFIG_H and -e $CUSTOM_IMG_CONFIG_H)
{
   exit 0;
}
#****************************************************************************
# 2 >>> parse Project Make File
#****************************************************************************
if(1!=&FileInfo::Parse_MAKEFILE($themf, \%MAKEFILE_OPTIONS))
{
   &sysUtil::sysgen_die("[1.1]Parse MakeFile failed");
}

#****************************************************************************
# 3 >>> Check user settings validity - DUMMY SCATTER
#****************************************************************************
&config_DummyScatterSetting();
#****************************************************************************
# 4 >>> Get Factory Bin Size if necessary
#****************************************************************************
&GetFactoryBinSize(); 
#****************************************************************************
# 5 >>> parse key definition in CUSTOM_MEM_DEV_H
#****************************************************************************
my %MEM_DEV_H_Value;
&ParseDefinition($CUSTOM_MEM_DEV_H, \%MEM_DEV_H_Value);
#****************************************************************************
# 6 >>> parse key definition in CUSTOM_FEATURECONFIG_H
#****************************************************************************
my %FEATURE_CONFIG_Value;
&ParseDefinition($CUSTOM_FEATURECONFIG_H, \%FEATURE_CONFIG_Value);
# not to refer to ProjectLimit if it's not INSIDE_MTK.
if($INSIDE_MTK == 0)
{
    delete $FEATURE_CONFIG_Value{"PROJECT_EXPECTED_CODE_LIMIT"} if (exists $FEATURE_CONFIG_Value{"PROJECT_EXPECTED_CODE_LIMIT"});
    delete $FEATURE_CONFIG_Value{"PROJECT_EXPECTED_RAM_LIMIT"} if (exists $FEATURE_CONFIG_Value{"PROJECT_EXPECTED_RAM_LIMIT"});
    delete $FEATURE_CONFIG_Value{"PROJECT_EXPECTED_RAM_LIMIT_NFB"} if (exists $FEATURE_CONFIG_Value{"PROJECT_EXPECTED_RAM_LIMIT_NFB"});
}

my $CONFIG_FOTA_UE_FLASH_SPACE = (defined $FEATURE_CONFIG_Value{'CONFIG_FOTA_UE_FLASH_SPACE'}) ? $FEATURE_CONFIG_Value{'CONFIG_FOTA_UE_FLASH_SPACE'} : "0x0";
my $CONFIG_FOTA_NAND_MAP_TABLE_SIZE = (defined $FEATURE_CONFIG_Value{'CONFIG_FOTA_NAND_MAP_TABLE_SIZE'}) ? $FEATURE_CONFIG_Value{'CONFIG_FOTA_NAND_MAP_TABLE_SIZE'} : "0x800";
my $CONFIG_FOTA_PACKAGE_BLOCK_NUMBER = (defined $FEATURE_CONFIG_Value{'CONFIG_FOTA_PACKAGE_BLOCK_NUMBER'}) ? $FEATURE_CONFIG_Value{'CONFIG_FOTA_PACKAGE_BLOCK_NUMBER'} : "4";
my $CONFIG_FOTA_PACKAGE_AREA_SIZE = (defined $FEATURE_CONFIG_Value{'CONFIG_FOTA_PACKAGE_AREA_SIZE'}) ? $FEATURE_CONFIG_Value{'CONFIG_FOTA_PACKAGE_AREA_SIZE'} : "0x0";

#****************************************************************************
# 7 >>> parse key definition in CUSTOM_EMI_RELEASE_H
#****************************************************************************
my %EMI_H_Value;
&GetExtsramSize($CUSTOM_EMI_RELEASE_H, \%EMI_H_Value);
#****************************************************************************
# 8 >>> parse key definition in CUSTOM_FLASH_H
#****************************************************************************
my (%FLASH_H_Value,$hash_ref);
my (@FLASH_H_Value_BLK_LIST, @FLASH_H_Value_REGION_LIST, @FLASH_H_Value_BANK_LIST);
&memConfig::Parse($CUSTOM_FLASH_H,memConfig::CUSTOM_FLASH,$g_USE_DUMMY_SCATTER);
$hash_ref = &memConfig::Get_source_info(memConfig::CUSTOM_FLASH);
@FLASH_H_Value_BLK_LIST = @{$hash_ref->{'BLK_LIST'}};
@FLASH_H_Value_REGION_LIST = @{$hash_ref->{'REGION_LIST'}};
@FLASH_H_Value_BANK_LIST = @{$hash_ref->{'BANK_LIST'}};
%FLASH_H_Value = %$hash_ref;
#****************************************************************************
# 9 >>> parse key definition in FLASH_OPT_GEN_H
#****************************************************************************
my $NAND_flash_size;
&ParseFlashInfo_NAND($FLASH_OPT_GEN_H);
                                                  
#****************************************************************************
# 10 >>> Flash information gathering
#       Dump Block Table 
#****************************************************************************
my %NORFLASH_INFO_BLOCKS_TABLE;
%NORFLASH_INFO_BLOCKS_TABLE = %{$hash_ref->{'BLK_TABLE'}} if defined $hash_ref->{'BLK_TABLE'}; #when NFB, $hash_ref->{'BLK_TABLE'} will be undefine and cause a build error if not checked
#****************************************************************************
# 11 >>> Check user settings validity : NOR
#****************************************************************************
if (1==&FileInfo::is_NOR(\%MAKEFILE_OPTIONS))
{
    &check_user_setting();
}
#****************************************************************************
# 12 >>> Board parameters gathering
#****************************************************************************
my (%BOARD_PARAMETERS,%NORFLASH_INFO);
&gather_board_parameters(\%BOARD_PARAMETERS);
$NORFLASH_INFO{'AVAILABLE_SIZE'} = $BOARD_PARAMETERS{'FLASH'};  # moved here to get flash size after check_user_setting
#****************************************************************************
# 13 >>> Dump gathered information for debug use
#****************************************************************************
&PrintDebugInfo();
#****************************************************************************
# 14 >>> Generate custom_secure_config.h
#****************************************************************************
&GenCUSTOM_SECURE_CONFIG_H($CUSTOM_SECURE_CONFIG_H) if (!-e $CUSTOM_SECURE_CONFIG_H);
#****************************************************************************
# 15 >>> Generate custom_img_config.h
#****************************************************************************
&GenCUSTOM_IMG_CONFIG_H($CUSTOM_IMG_CONFIG_H) if (!-e $CUSTOM_IMG_CONFIG_H);
#****************************************************************************
# 16 >>> Generate ts_mem_config.h when TINY_SYSTEM is enabled
#****************************************************************************
if(exists $MAKEFILE_OPTIONS{'TINY_SYS'} and $MAKEFILE_OPTIONS{'TINY_SYS'} eq 'TRUE')
{
    &GenTS_MEM_CONFIG_H($TS_MEM_CONFIG_H) if (!-e $TS_MEM_CONFIG_H);
}

#****************************************************************************
# 17 >>> FOTA configurations gathering
#****************************************************************************
my %FOTA_CONFIG;
&ParseCUSTOM_IMG_CONFIG_H($CUSTOM_IMG_CONFIG_H, \%FOTA_CONFIG);
#****************************************************************************
# 18 >>> Generate MAUI Scatter File
#****************************************************************************
if (!-e $SCATTERFILE)
{
    &GenMAUIScatter($SCATTERFILE, 0);
}

#****************************************************************************
# 19 >>> Generate DL Scatter File for flash tool
#****************************************************************************
if (!-e $DL_SCATTERFILE)
{
    #DCM_COMPRESSION_SUPPORT = TRUE
    #or SECURE_SUPPROT = TRUE
    #or ALICE_SUPPORT = TRUE
    if((defined $MAKEFILE_OPTIONS{'dcm_compression_support'} and $MAKEFILE_OPTIONS{'dcm_compression_support'} eq 'TRUE')
    or (defined $MAKEFILE_OPTIONS{'zimage_support'} and $MAKEFILE_OPTIONS{'zimage_support'} eq 'TRUE') 
    or (defined $MAKEFILE_OPTIONS{'alice_support'} and $MAKEFILE_OPTIONS{'alice_support'} eq 'TRUE'))
    {
        &GenMAUIScatter($DL_SCATTERFILE, 1);
    }
    else
    {
        &CopyandMarkFile($SCATTERFILE, $DL_SCATTERFILE, $DL_Wateramrk);
    }
}

#****************************************************************************
# 20 >>> Generate Bootloader Scatter File
#****************************************************************************
&GenBLScatter();


#****************************************************************************
# 21 >>> Generate FOTA Scatter File
#****************************************************************************
if (exists $MAKEFILE_OPTIONS{'fota_enable'} and $MAKEFILE_OPTIONS{'fota_enable'} eq 'FOTA_DM')
{
    if (!-e $FOTA_SCATTERFILE)
    {
        &GenFOTAScatter();
    }
}

#****************************************************************************
# 22 >>> Generate tiny sys scatter file  when TINY_SYSTEM is enabled
#****************************************************************************
if(exists $MAKEFILE_OPTIONS{'TINY_SYS'} and $MAKEFILE_OPTIONS{'TINY_SYS'} eq 'TRUE')
{
    &GenTSScatter()
}
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
exit;

#****************************************************************************
# subroutine:  GenMAUIScatter: Generate MAUI main scatter file
# input: 	     $filepath : the file path to save a scatter layout 
#                 $Is_Flashtool_Layout : 0=normal layout, 1=flashtool required layout
# return:      x
# require:    tools/scatGenLib.pl -> scatGen_main();
#****************************************************************************
sub GenMAUIScatter
{
    require "tools/scatGenLib.pl";
    PrintDependModule();
    #$Is_Flashtool_Layout : 0=normal layout, 1=flashtool required layout
    my ($filepath, $Is_Flashtool_Layout ) = @_;
    my $dummy_pattern = ($g_USE_DUMMY_SCATTER eq 'TRUE')? $DUMMY_SCATTER_Watermark : "";
    my $nfb_or_emb = (&isNFB()==1) ? "TRUE" : "FALSE" ;
    my $scat_content = &scatGen_main(sub { my ($key) = @_;
                                            if (exists $MAKEFILE_OPTIONS{$key})
                                            {   return $MAKEFILE_OPTIONS{$key};
                                            }
                                            else
                                            {   return undef;
                                            }
                                         },
                                     $BOARD_PARAMETERS{'BB'},
                                     \%NORFLASH_INFO,
                                     \%NORFLASH_INFO_BLOCKS_TABLE,
                                     $BOARD_PARAMETERS{'EXTSRAM'},
                                     $nfb_or_emb,
                                     \%FOTA_CONFIG,
                                     $BB_PATH,
                                     $themf,
                                     $NEED_BUILD_BOOTLOADER,
                                     \%MEM_DEV_H_Value,
                                     $Is_Flashtool_Layout,
                                     $g_USE_DUMMY_SCATTER,
                                     \%FEATURE_CONFIG_Value,
                                     $nFactoryBinSize,
                                     $OBJ_SYS_AUTO_GEN
                                    );

    &sysUtil::sysgen_die("[2.0]Unsupported Feature Combination. Please create $filepath manually!", __FILE__, __LINE__) unless defined $scat_content;

    open (SCATTER_TXT, ">$filepath") or &sysUtil::sysgen_die("[2.0]$filepath: file error!", __FILE__, __LINE__);

    print SCATTER_TXT &copyright_file_header_for_scatter($BOARD_PARAMETERS{'BB'});
    print SCATTER_TXT &description_file_header_for_scatter( $filepath.$dummy_pattern,
                             "defines the memory map for the validation board\n",
                             "system auto generator ". &scatGen_verno() . " + sysGenUtility" . &sysUtil::sysgenUtility_verno(),
                             &dump_board_parameters());
    print SCATTER_TXT $scat_content;
    close SCATTER_TXT;

    print "$filepath is generated\n";
}

#****************************************************************************
# subroutine:  GenBLScatter: Generate BL scatter file
# input: 	     $filepath : the file path to save a scatter layout 
# return:      x
# require:    tools/BLscatGen.pl -> scatGenBL_main()
#****************************************************************************
sub GenBLScatter
{
    require "tools/scatGenBL.pl";
    require "tools/scatGenLib.pl";
    PrintDependModule();
    &scatGenBL_main(sub { my ($key) = @_;
                          if (exists $MAKEFILE_OPTIONS{$key})
                          {   return $MAKEFILE_OPTIONS{$key};
                          }
                          else
                          {   return undef;
                          }
                    },
                    $BOARD_PARAMETERS{'BB'},
                    $BOARD_PARAMETERS{'EXTSRAM_ORIGINAL'},
                    $BB_PATH,
                    $SCATTERFILE,
                    $BL_SCATTERFILE
                    ); 
    print "$BL_SCATTERFILE is generated\n";  
    print "$EXT_BL_SCATTERFILE is generated\n"; 
}
#****************************************************************************
# subroutine:  GenFOTAScatter: Generate FOTA scatter file
# input: 	     $filepath : the file path to save a scatter layout 
# return:      x
# require:    tools/FOTAscatGen.pl -> scatGenBL_main()
#****************************************************************************
sub GenFOTAScatter
{
    require "tools/scatGenFOTA.pl";
    require "tools/scatGenLib.pl";
    PrintDependModule();
    my $scat_content = &scatGenFOTA_main(sub { my ($key) = @_;
                                                  if (exists $MAKEFILE_OPTIONS{$key})
                                                  {   return $MAKEFILE_OPTIONS{$key};
                                                  }
                                                  else
                                                  {   return undef;
                                                  }
                                                 },
                                             $BOARD_PARAMETERS{'BB'},
                                             $BOARD_PARAMETERS{'EXTSRAM_ORIGINAL'},
                                             \%FOTA_CONFIG,
                                             $BB_PATH,
                                             $SCATTERFILE
                                            );

    open (FOTA_SCATTER_TXT, ">$FOTA_SCATTERFILE") or &sysUtil::sysgen_die("[2.0]$FOTA_SCATTERFILE: file error!", __FILE__, __LINE__);    
    print FOTA_SCATTER_TXT &copyright_file_header_for_scatter();
    print FOTA_SCATTER_TXT &description_file_header_for_scatter( $FOTA_SCATTERFILE,
                           "defines the memory map for FOTA\n",
                           "system auto generator ". &scatGen_verno(). " + sysGenUtility" . &sysUtil::sysgenUtility_verno());
    print FOTA_SCATTER_TXT $scat_content;
    close FOTA_SCATTER_TXT;
    
    print "$FOTA_SCATTERFILE is generated\n";
}

#****************************************************************************
# subroutine:  GenTSScatter: Generate tiny sys scatter file
# input: 	     $filepath : the file path to save a scatter layout 
# return:      x
# require:    tools/scatGenTS.pl -> scatGenTS_main()
#****************************************************************************
sub GenTSScatter
{
    require "tools/scatGenTS.pl";
    PrintDependModule();
    &scatGenTS_main(sub { my ($key) = @_;
                          if (exists $MAKEFILE_OPTIONS{$key})
                          {   return $MAKEFILE_OPTIONS{$key};
                          }
                          else
                          {   return undef;
                          }
                    },
                    \%BOARD_PARAMETERS,
                    $TS_SCATTERFILE
                    );   
}
#****************************************************************************
# subroutine:  isNFB: to know whether it's NFB or EMMC Booting
# return:      1=NFB or EMMC booting, 0=NOR
#****************************************************************************
sub isNFB
{
    my $bnfb_or_emb = 0;
    if ((exists $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} ne 'NONE') or (exists $MAKEFILE_OPTIONS{'emmc_booting'} and $MAKEFILE_OPTIONS{'emmc_booting'} ne 'NONE'))
    {
        $bnfb_or_emb = 1;
    }
    return $bnfb_or_emb;
}

#****************************************************************************
# subroutine:  CopyandMarkFile: Copy a file from source  to destination
#                    with adding $Watermark in the line containing 'Filename:', 
#                    and replace .txt to _flashtool.txt once.
# input: 	     $SrcPath : Source file path
#                 $DestPath : Destined file path
#                 $Watermark : the keyword to identify if the destined file is copied or manually added.
# return:      x
#****************************************************************************
sub CopyandMarkFile
{
	my($SrcPath, $DestPath, $Watermark)= @_;
	my $KeyWordtoMark = "$Watermark: $SrcPath";

	my $content;
	open FILE, "<$SrcPath" or &sysUtil::sysgen_die("[2.0]$SrcPath: open file error!", __FILE__, __LINE__);
	{
		local $/;
		$content = <FILE>;
	}
	close FILE;
	
	#Change File Name
	$content =~ s/\.txt/_flashtool.txt/;
	#Write Copy Mark
	$content =~ s/Filename:/Filename: $KeyWordtoMark/; 
	
	open FILE, ">$DestPath" or &sysUtil::sysgen_die("[2.0]$DestPath: open file error!", __FILE__, __LINE__);
	print FILE $content;
	close FILE;
}
#****************************************************************************
# subroutine:  DelFileWithKeyword: Delete the existent file which contains $Watermark
# input: 	     $FilePath : the file path you want to delete
#                 $Keyword : the keyword you want to search in the file
# return:      x
#****************************************************************************
sub DelFileWithKeyword
{
	my ($FilePath, $Keyword) = @_;

	if(-e $FilePath)
	{
		my $NeedDelete = 0;
	
		open FILE, "<$FilePath" or &sysUtil::sysgen_die("[3.2]$FilePath: open file error!", __FILE__, __LINE__);
		{
			local $/;
			my $content = <FILE>;
			$NeedDelete = 1 if($content =~ /$Keyword/);
		}
		close FILE;
		if($NeedDelete eq 1)
		{
			unlink $FilePath;
		}
		else
		{
			PrintDependency($FilePath);
		}
	}
}

#****************************************************************************
# subroutine:  custom_secure_config_h_file_body
#****************************************************************************
sub custom_secure_config_h_file_body
{
    my ($flash_end_addr);
    if (&FileInfo::is_NOR(\%MAKEFILE_OPTIONS) != 1)
    {
        $flash_end_addr = $NAND_flash_size*1024*1024;
    }
    else
    {
        $flash_end_addr = hex($FLASH_H_Value{'NOR_FLASH_DENSITY'});
    }

    ### Get the last block size for SDS (the all blocks for SDS are fixed size)
    my $sds_block_size = undef;
    $sds_block_size = &memConfig::Get_flash_block_size($flash_end_addr-1) if(&FileInfo::is_NOR(\%MAKEFILE_OPTIONS));
    ### Get SDS total size
    my $sds_total_size = &memConfig::Get_SDS_total_size($sds_block_size,\%FEATURE_CONFIG_Value,\%MAKEFILE_OPTIONS);
    
    ### Get SDS reserved size (the sds reserved size is 0 for NOR booting)
    my $sds_reserve_size_nfb = (defined $FEATURE_CONFIG_Value{'SDS_RESERVED_SIZE_FOR_BBM'}) ? hex($FEATURE_CONFIG_Value{'SDS_RESERVED_SIZE_FOR_BBM'}) : 256*1024;
    $sds_reserve_size_nfb += 640*1024 if($BOARD_PARAMETERS{'BB'} eq "MT6260");
    my $sds_reserve_size = (&FileInfo::is_NOR(\%MAKEFILE_OPTIONS)) ? 0 : $sds_reserve_size_nfb; 
    
    ### Calculate SDS start address
    my $sds_baseaddr;
    $sds_baseaddr = $flash_end_addr - $sds_total_size;

    ### Ensure block alignment (NOR booting)
    if ((defined $MAKEFILE_OPTIONS{'sds_support'} and $MAKEFILE_OPTIONS{'sds_support'} eq 'TRUE') and (&FileInfo::is_NOR(\%MAKEFILE_OPTIONS)))
    {
        my $sds_tmp_addr = $sds_baseaddr + $sds_total_size;
        my $sds_tmp_size    = $sds_total_size;
        while ($sds_tmp_size > 0)
        {   
            my $cur_blk_size = &memConfig::Get_flash_block_size($sds_tmp_addr-1);
            $sds_tmp_addr -= $cur_blk_size;
            $sds_tmp_size -= $cur_blk_size;
        }
        if ($sds_tmp_size < 0)
        {
            my $suggested_sds_max_size = sprintf("0x%x", $sds_total_size - $sds_tmp_size);
            &sysUtil::sysgen_die("[3.1]$CUSTOM_FEATURECONFIG_H: SDS_MAX_SIZE should be multiple of blocks! It is SUGGESTED to set SDS_MAX_SIZE as $suggested_sds_max_size!", __FILE__, __LINE__);
        }
    }

    ###
    my ($sds_baseaddr_str, $sds_max_size_str, $sds_reserved_size_str, $sds_rgn_num_str) = ('0x0', '0x0','0x0','0');
    if (defined $MAKEFILE_OPTIONS{'sds_support'} and $MAKEFILE_OPTIONS{'sds_support'} eq 'TRUE')
    {
        $sds_baseaddr_str = sprintf("0x%x", $sds_baseaddr);
        $sds_max_size_str = sprintf("0x%x", $sds_total_size);
        $sds_reserved_size_str = sprintf("0x%x", $sds_reserve_size);
        $sds_rgn_num_str = (defined $FEATURE_CONFIG_Value{'SDS_RGN_NUM'}) ? $FEATURE_CONFIG_Value{'SDS_RGN_NUM'} : '2';
    }
    ###
    my $template = <<"__TEMPLATE";
#ifndef __CUSTOM_SECURE_CONFIG_H__
#define __CUSTOM_SECURE_CONFIG_H__

/* Secure data storage configuration */
#ifdef __SECURE_DATA_STORAGE__
#define SDS_START_ADDR     $sds_baseaddr_str
#define SDS_TOTAL_SIZE     $sds_max_size_str
#define SDS_RESERVED_SIZE  $sds_reserved_size_str
#define SDS_RGN_NUM        $sds_rgn_num_str
#endif 

/* Boot cert configuration */
#define BOOT_CERT_CTRL_PATTERN 0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF \\
                               ,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF \\
                               ,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF \\
                               ,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF \\
                               ,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF \\
                               ,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF \\
                               ,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF \\
                               ,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF

#endif /* __CUSTOM_SECURE_CONFIG_H__ */
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  custom_img_config_h_file_body
#****************************************************************************
sub custom_img_config_h_file_body
{
    my ($cs_swap_config, $cs_swap_address);
    my ($ue_flash_base_address, $str_ue_flash_base_address);
    my ($ue_resident_flash_space_size, $str_ue_resident_flash_space_size);
    my ($ue_backup_flash_space_size, $str_ue_backup_flash_space_size);
    my ($ue_execution_base, $str_ue_execution_base);
    my $maui_image_amount = 0;
    my ($str_maui_flash_space, $image_base_addr, $str_image_base_addr, $ROM_size);
    my $str_ROM_size = "0x0";
    my ($strJUMPTABLE_size, $strLANG_PACK_size, $strCUSTPACK_size)=("0x0","0x0","0x0");
    my ($package_storage_base, $str_package_storage_base);
    my ($package_storage_size, $str_package_storage_size);
    my ($backup_storage_base, $str_backup_storage_base);
    my ($backup_storage_size, $str_backup_storage_size);
    my ($package_block_number, $str_package_block_number);
    my ($str_fota_maui_mapping_table_size);
    my ($rom_begin_addr_on_flash,$str_rom_begin_addr_on_flash)=(0x0,"0x0"); #for  NORFLASH_NON_XIP_SUPPORT
    my ($ts_rom1_begin_addr_on_flash, $str_ts_rom1_begin_addr_on_flash) = (0x0,"0x0"); #for TINY_SYS, feature on MT6261 and after
    my ($ts_rom2_begin_addr_on_flash, $str_ts_rom2_begin_addr_on_flash) = (0x0,"0x0"); #for TINY_SYS, feature on MT6261 and after
    # determine $config_cs_swap
    my $mbin  = $MAKEFILE_OPTIONS{'multiple_binary_files'};
    my $esb   = $MAKEFILE_OPTIONS{'enhanced_single_bank_nor_flash_support'};
    my $usbdl = $MAKEFILE_OPTIONS{'usb_download_in_bl'};
    my $fota  = $MAKEFILE_OPTIONS{'fota_enable'};
    my $nfb_or_emb;
    if (exists $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} ne 'NONE')
    {
    	  $nfb_or_emb = $MAKEFILE_OPTIONS{'nand_flash_booting'};
    }
    elsif (exists $MAKEFILE_OPTIONS{'emmc_booting'} and $MAKEFILE_OPTIONS{'emmc_booting'} ne 'NONE')
    {
    	  $nfb_or_emb = $MAKEFILE_OPTIONS{'emmc_booting'};
    }
    else
    {
    	  $nfb_or_emb = 'NONE';
    }
    my $secure_ro = $MAKEFILE_OPTIONS{'secure_ro_enable'};
    my $secure_support = $MAKEFILE_OPTIONS{'secure_support'};
    #sync with config_setup in scatGenLib.pl
    my $bb = $BOARD_PARAMETERS{'BB'};
    if (($nfb_or_emb eq 'NONE')  
         and(&sysUtil::is_mpu_capable($bb) or defined &sysUtil::is_arm9($bb) or &sysUtil::is_arm11($bb))
        )
    {
       # determine $cs_swap_config
        if ($NEED_BUILD_BOOTLOADER eq 'TRUE')
        {
            $cs_swap_config = 1;
        } 
        if (defined $esb and $esb eq 'TRUE')
        {
            $cs_swap_config = 1;  
        }
        if (defined $usbdl and $usbdl ne 'NONE')
        {
            $cs_swap_config = 1;  
        }
        if (defined $fota and $fota eq 'FOTA_DM')
        {
            $cs_swap_config = 1;  
        }
    }
    ###
    if ($cs_swap_config == 1)
    {
        $cs_swap_address = &sysUtil::query_cs1_addr($bb, 0);
    }
    else
    {
    	   $cs_swap_address = 0;
    }   
    ###
    # define image list information
    my $dsp_solution = $MAKEFILE_OPTIONS{'dsp_solution'};
    my $mba_bin = $MAKEFILE_OPTIONS{'MBA_DEFAULT_BINARY'};
    my @enfb_image_list = ($dsp_solution eq 'DUALMACDSP') ? ('ROM', 'DSP_ROM', 'SECONDARY_ROM', 'THIRD_ROM') : ('ROM', 'SECONDARY_ROM', 'THIRD_ROM');
    my @ondemand_image_list = ($dsp_solution eq 'DUALMACDSP') ? ('ROM', 'DSP_ROM', 'SECONDARY_ROM', 'DEMAND_PAGING_ROM0') : ('ROM', 'SECONDARY_ROM', 'DEMAND_PAGING_ROM0');
    my @basic_image_list = ($dsp_solution eq 'DUALMACDSP') ? ('ROM', 'DSP_ROM', 'SECONDARY_ROM') : ('ROM', 'SECONDARY_ROM');
    my @mbin_lang_enfb_image_list =  ($dsp_solution eq 'DUALMACDSP') ? ('ROM', 'DSP_ROM', 'SECONDARY_ROM', 'LANG_PACK_ROM', 'THIRD_ROM') : ('ROM', 'SECONDARY_ROM', 'LANG_PACK_ROM', 'THIRD_ROM');
    my @mbin_cust_enfb_image_list =  ($dsp_solution eq 'DUALMACDSP') ? ('ROM', 'DSP_ROM', 'SECONDARY_ROM', 'CUSTPACK_ROM', 'THIRD_ROM') : ('ROM', 'SECONDARY_ROM', 'CUSTPACK_ROM', 'THIRD_ROM');
    my @mbin_enfb_image_list = ($dsp_solution eq 'DUALMACDSP') ? ('ROM', 'DSP_ROM', 'SECONDARY_ROM', 'LANG_PACK_ROM', 'CUSTPACK_ROM', 'THIRD_ROM') : ('ROM', 'SECONDARY_ROM', 'LANG_PACK_ROM', 'CUSTPACK_ROM', 'THIRD_ROM');
    my @mbin_lang_ondemand_image_list =  ($dsp_solution eq 'DUALMACDSP') ? ('ROM', 'DSP_ROM', 'SECONDARY_ROM', 'DEMAND_PAGING_ROM0', 'LANG_PACK_ROM') : ('ROM', 'SECONDARY_ROM', 'DEMAND_PAGING_ROM0', 'LANG_PACK_ROM');
    my @mbin_cust_ondemand_image_list =  ($dsp_solution eq 'DUALMACDSP') ? ('ROM', 'DSP_ROM', 'SECONDARY_ROM', 'DEMAND_PAGING_ROM0', 'CUSTPACK_ROM') : ('ROM', 'SECONDARY_ROM', 'DEMAND_PAGING_ROM0', 'CUSTPACK_ROM');
    my @mbin_ondemand_image_list = ($dsp_solution eq 'DUALMACDSP') ? ('ROM', 'DSP_ROM', 'SECONDARY_ROM', 'DEMAND_PAGING_ROM0', 'LANG_PACK_ROM', 'CUSTPACK_ROM') : ('ROM', 'SECONDARY_ROM', 'DEMAND_PAGING_ROM0', 'LANG_PACK_ROM', 'CUSTPACK_ROM');
    if(defined $bb and $bb eq 'MT6256')
    {
        @ondemand_image_list = ('ROM', 'SECONDARY_ROM', 'DSP_ROM', 'DEMAND_PAGING_ROM0');
        @mbin_lang_ondemand_image_list = ('ROM', 'SECONDARY_ROM', 'DSP_ROM', 'DEMAND_PAGING_ROM0', 'LANG_PACK_ROM');
        @mbin_cust_ondemand_image_list = ('ROM', 'SECONDARY_ROM', 'DSP_ROM', 'DEMAND_PAGING_ROM0', 'CUSTPACK_ROM');
        @mbin_ondemand_image_list = ('ROM', 'SECONDARY_ROM', 'DSP_ROM', 'DEMAND_PAGING_ROM0', 'LANG_PACK_ROM', 'CUSTPACK_ROM');
        @basic_image_list = ('ROM', 'SECONDARY_ROM', 'DSP_ROM');
    }
    
    my $intergrafx_support = $MAKEFILE_OPTIONS{'intergrafx_support'};
    my $strDemandPagingSize = (defined $intergrafx_support and $intergrafx_support ne 'NONE') ? "0x5C00000" : "0x3C00000";
    my %size_Tbl =
       (        'ROM'                => '0x300000',
                'DSP_ROM'            => '0x100000',
                'SECONDARY_ROM'      => '0xB00000',
                'THIRD_ROM'          => '0x200000',
                'DEMAND_PAGING_ROM0' => $strDemandPagingSize,
                'LANG_PACK_ROM'      => '0x800000',
                'CUSTPACK_ROM'       => '0x800000',
       );
	   
	   ###
       my ($nfb_image_definition, $nor_image_definition);
	   if (defined $nfb_or_emb and $nfb_or_emb ne 'NONE')
	   {
        ###
        # bootloader should be at least 64KB
        $ue_flash_base_address = 0;
        $str_ue_flash_base_address = sprintf("0x%08X", $ue_flash_base_address);
	   
        ###
        $ue_resident_flash_space_size = 0xC0000;
        $str_ue_resident_flash_space_size = sprintf("0x%X", $ue_resident_flash_space_size);;

        ###
        $ue_backup_flash_space_size = 0xC0000;
        $str_ue_backup_flash_space_size = sprintf("0x%X", $ue_backup_flash_space_size);;
        
        ###
        # image head area size = block number * block size (0x20000) 
        #                      = (1(BL_IMG_MAX_SIZE) + 6(FOTA_UE_RESIDENT_FLASH_SPACE_SIZE) + 6(FOTA_UE_BACKUP_FLASH_SPACE_SIZE) + 8(image list block) + 1(ext_bootloader) + 2(bad block margin)) * 0x20000 = 0x300000
        my $image_head_area_size = 0x300000;
   
        ###
        $ue_execution_base = &comp_physical_ram_size() - hex('0x200000');  # Put FOTA at the last 2MB of the RAM
        $str_ue_execution_base = sprintf("0x%08X", $ue_execution_base);
   
        ### get target binary list and get binary size from hash
        my @target_list_ref;
        if ($mbin eq 'TRUE' and $nfb_or_emb eq 'ENFB')
        {
            if(!defined $mba_bin or (defined $mba_bin and $mba_bin eq 'CUST_AND_LANG'))
            {
                @target_list_ref = @mbin_enfb_image_list;#('ROM', 'SECONDARY_ROM', 'LANG_PACK_ROM', 'CUSTPACK_ROM', 'THIRD_ROM');
            }
            elsif(defined $mba_bin and $mba_bin eq 'LANG_ONLY')
            {
                @target_list_ref =	@mbin_lang_enfb_image_list; 
            }
            elsif(defined $mba_bin and $mba_bin eq 'CUST_ONLY')
            {
                @target_list_ref =	@mbin_cust_enfb_image_list; 	
            }
        }
        elsif ($mbin eq 'TRUE' and $nfb_or_emb eq 'ONDEMAND')
        {
            if(!defined $mba_bin or (defined $mba_bin and $mba_bin eq 'CUST_AND_LANG'))
            {
                @target_list_ref = @mbin_ondemand_image_list;#('ROM', 'SECONDARY_ROM', 'DEMAND_PAGING_ROM0', 'LANG_PACK_ROM', 'CUSTPACK_ROM');
            }
            elsif(defined $mba_bin and $mba_bin eq 'LANG_ONLY')
            {
                @target_list_ref =	@mbin_lang_ondemand_image_list; 
            }
            elsif(defined $mba_bin and $mba_bin eq 'CUST_ONLY')
            {
                @target_list_ref =	@mbin_cust_ondemand_image_list; 	
            }
        }
        elsif ($mbin eq 'FALSE' and $nfb_or_emb eq 'ENFB')
        {
            @target_list_ref = @enfb_image_list;#('ROM', 'SECONDARY_ROM', 'THIRD_ROM');
        }
        elsif ($mbin eq 'FALSE' and $nfb_or_emb eq 'ONDEMAND')
        {
            @target_list_ref = @ondemand_image_list;#('ROM', 'SECONDARY_ROM', 'DEMAND_PAGING_ROM0');
        }
        elsif ($mbin eq 'FALSE' and $nfb_or_emb eq 'BASIC')
        {
            @target_list_ref = @basic_image_list;#('ROM', 'SECONDARY_ROM');
        }
        else
        {
            &sysUtil::sysgen_die("[1.1]$themf: Unsupported configuration MBA=$mbin and NFB=$nfb_or_emb!", __FILE__, __LINE__);
        }
        $maui_image_amount = $#target_list_ref + 1;

        my $extern_def_list;
        my $target_def_list;
        my $dummy_def_list;
        my $indent_for_str_maui_flash_space;
        my $bin_size_sum = 0;
        foreach (@target_list_ref)
        {
            my $bin_name = $_;
            my $bin_1st_region_name = $bin_name;
            if ($bin_1st_region_name eq 'ROM' or $bin_1st_region_name eq 'SECONDARY_ROM'  or $bin_1st_region_name eq 'THIRD_ROM' or $bin_1st_region_name eq 'DEMAND_PAGING_ROM0' or $bin_1st_region_name eq 'LANG_PACK_ROM' or $bin_1st_region_name eq 'CUSTPACK_ROM' or $bin_1st_region_name eq 'JUMP_TABLE')
            {
                if (&sysUtil::is_sv5($BOARD_PARAMETERS{'BB'}) == 1)
                {
                    $bin_1st_region_name .= "_GFH";
                }
            }
            
            my $max_bin_size_str = "MAX_" . $_ . "_SIZE";
            my $size;
            if (defined $FEATURE_CONFIG_Value{$max_bin_size_str})
            {
            	$size = hex($FEATURE_CONFIG_Value{$max_bin_size_str});
            }
            elsif (defined $size_Tbl{$_})
            {
            	$size = hex($size_Tbl{$_});
            }
            else
            {
            	$size = 0x400000;
            }
            
            $bin_size_sum += $size;
            $extern_def_list .= "extern kal_uint32 Load\$\$$bin_1st_region_name\$\$Base;\n";
            $target_def_list .= "#define MAUI_LOAD_ADDRESS_$bin_name   ((kal_uint32)&Load\$\$$bin_1st_region_name\$\$Base)\n";
            $dummy_def_list .= "#define MAUI_LOAD_ADDRESS_$bin_name   ((kal_uint32)0)\n";
            
            if (!defined $indent_for_str_maui_flash_space)
            {
                $indent_for_str_maui_flash_space = " ";
            }
            elsif ($indent_for_str_maui_flash_space eq " ")
            {
                $indent_for_str_maui_flash_space = "                                     ";
            }
            $str_maui_flash_space .= "$indent_for_str_maui_flash_space\{MAUI_LOAD_ADDRESS_$bin_name, MAX_LENGTH_$bin_name, 0x0}, \\\n";
        }
        
        chomp $extern_def_list;
        chomp $target_def_list;
        chomp $dummy_def_list;
        chomp $str_maui_flash_space;
    
        $nfb_image_definition .= <<"__TEMPLATE";
#if defined(__MTK_TARGET__)

$extern_def_list

$target_def_list

#else /* __MTK_TARGET__ */

$dummy_def_list
 
#endif /* __MTK_TARGET__ */

#define FOTA_MAUI_FLASH_SPACE      {$str_maui_flash_space
                                     END_MAUI_INFO}
__TEMPLATE

        ###
        # FOTA_PACKAGE_STORAGE_BASE = image head area size + all ROM sizes (ROM, SECONDARY_ROM, THIRD_ROM, DEMAND_PAGING_ROM0)
        $package_storage_base = $image_head_area_size + $bin_size_sum;
        $str_package_storage_base = sprintf("0x%08X", $package_storage_base);
    
        ###
        $package_storage_size = (hex($CONFIG_FOTA_PACKAGE_AREA_SIZE) / 0x20000) * 0x20000;
        $str_package_storage_size = sprintf("0x%08X", $package_storage_size);
        
        ###
        $package_block_number = $package_storage_size / 0x4000;
        $str_package_block_number = sprintf("%d", $package_block_number);
        
        ### BACKUP_STORAGE is consecutive to PACKAGE_STORAGE
        $backup_storage_base = $package_storage_base + $package_storage_size;
        $str_backup_storage_base = sprintf("0x%08X", $backup_storage_base);
        
        ### BACKUP_STORAGE_SIZE is 6 blocks in NAND
        $backup_storage_size = 6 * 0x20000;
        $str_backup_storage_size = sprintf("0x%08X", $backup_storage_size);
    }
    else
    {
        ###
        # bootloader is at least 128KB for general bootloader
       	if (&sysUtil::is_sv5($bb) == 1)
        {
            my $nReservedBLSize;
            my $package_seg = $MAKEFILE_OPTIONS{'package_seg'};
            my $ext_bl_update_support = $MAKEFILE_OPTIONS{'ext_bl_update_support'};
            my $card_dl = $MAKEFILE_OPTIONS{'card_download'};
            my $isSmallpackage = ($package_seg eq '32_32_SEG' or $package_seg eq '16_32_SEG' or $package_seg eq '24_32_SEG') ? 1 : 0;
            my ($HEADER_BLOCK_MIN_SIZE, $BL_MIN_SIZE, $ROOT_CERT_MIN_SIZE, $EXT_BL_MIN_SIZE, $EXT_BL_BAK_MIN_SIZE);
            if (defined $package_seg and $package_seg eq '16_3_SEG')
            {
                $HEADER_BLOCK_MIN_SIZE = 2 * 1024;
                $BL_MIN_SIZE = 6 * 1024;
                $EXT_BL_MIN_SIZE = 4 * 1024;
                $EXT_BL_BAK_MIN_SIZE = 0; 
            }
            elsif (($bb eq 'MT6250' or $bb eq 'MT6260' or &sysUtil::is_MT6261_Family($bb))and $isSmallpackage)
            {
            	my $isSecOnSlimSeg = (($bb eq 'MT6260' or &sysUtil::is_MT6261_Family($bb)) and ($package_seg eq '32_32_SEG') and (&FileInfo::is("secure_support", "TRUE"))) ? 1 : 0;
                $HEADER_BLOCK_MIN_SIZE = 2 * 1024;
                $BL_MIN_SIZE = 10 * 1024;
                $EXT_BL_MIN_SIZE = ($isSecOnSlimSeg)? (28 * 1024) : (8 * 1024);
                $EXT_BL_BAK_MIN_SIZE = 0;
            }
            elsif ((!defined $ext_bl_update_support) or (defined $ext_bl_update_support and $ext_bl_update_support eq 'FALSE'))
            {
                $HEADER_BLOCK_MIN_SIZE = 4 * 1024;
                $BL_MIN_SIZE = (&sysUtil::is_MT6261_Family($bb))? 20 * 1024 : 24 * 1024;
                $EXT_BL_MIN_SIZE = 96 * 1024;
                $EXT_BL_BAK_MIN_SIZE = 0;
                $EXT_BL_MIN_SIZE = 224 * 1024 if (defined $card_dl and $card_dl ne 'NONE');
            }
            else
            {
                $HEADER_BLOCK_MIN_SIZE = 4 * 1024;
                $BL_MIN_SIZE = (&sysUtil::is_MT6261_Family($bb))? 20 * 1024 : 24 * 1024;
                $EXT_BL_MIN_SIZE = 0x40000;
                $EXT_BL_BAK_MIN_SIZE = 0x40000;
            }
            #fix ESD patch side effect on MT6260
            if(($bb eq 'MT6260') and (&FileInfo::is("secure_support", "TRUE")))
            {
                #BL size should 4-kB align
                my $align = 4*1024;
                $BL_MIN_SIZE = ($BL_MIN_SIZE % $align ==0) ? $BL_MIN_SIZE : (int($BL_MIN_SIZE / $align)+1) * $align;

                #add ROM patch size
                my $rom_patch_stat = stat(".\\bootloader_bin\\MT6260_E1_ROM_PATCH_RELEASE.bin");
                &sysUtil::sysgen_die("[3.2]can not get .\\bootloader_bin\\MT6260_E1_ROM_PATCH_RELEASE.bin", __FILE__, __LINE__) unless defined $rom_patch_stat;
                my $rom_patch_size = $rom_patch_stat->size;
                $BL_MIN_SIZE += $rom_patch_size;
                print "ROM_PATCH_SIZE is $rom_patch_size\n";
                
                #add Signature size
                $BL_MIN_SIZE += 932;

                #should 1-kB align
                $align = 1*1024;
                $BL_MIN_SIZE = ($BL_MIN_SIZE % $align ==0) ? $BL_MIN_SIZE : (int($BL_MIN_SIZE / $align)+1) * $align;
            }
    
            $BL_MIN_SIZE = (exists $FEATURE_CONFIG_Value{MAX_BL_SIZE}) ? 
                                        hex($FEATURE_CONFIG_Value{MAX_BL_SIZE}) : $BL_MIN_SIZE;
            $EXT_BL_MIN_SIZE = (exists $FEATURE_CONFIG_Value{MAX_EXT_BL_SIZE}) ? 
                                        hex($FEATURE_CONFIG_Value{MAX_EXT_BL_SIZE}) : $EXT_BL_MIN_SIZE;
            if(defined $ext_bl_update_support and $ext_bl_update_support eq 'TRUE')
            {
                
                $EXT_BL_BAK_MIN_SIZE = (exists $FEATURE_CONFIG_Value{MAX_EXT_BL_SIZE}) ? 
                                        hex($FEATURE_CONFIG_Value{MAX_EXT_BL_SIZE})  : $EXT_BL_BAK_MIN_SIZE;
            }
            print "[custom_img_config_h]bl_base=" . &CommonUtil::Dec2Hex($HEADER_BLOCK_MIN_SIZE) . ",bl_size=" . &CommonUtil::Dec2Hex($BL_MIN_SIZE) . "\n" ;
            
            $ROOT_CERT_MIN_SIZE = (&FileInfo::is("secure_support", "TRUE") and !($package_seg eq '16_3_SEG'))? (4 * 1024) : 0;
            my $root_cert_base = $HEADER_BLOCK_MIN_SIZE + $BL_MIN_SIZE;
            print "[custom_img_config_h]root_cert_base=" . &CommonUtil::Dec2Hex($root_cert_base) . ",root_cert_size=" . &CommonUtil::Dec2Hex($ROOT_CERT_MIN_SIZE) . "\n";
			
            ### EXT_BOOTLOADER is behind ROOT_CERT and should be block-aligned if EXT_BL_UPDATE_SUPPORT is turned on
            my $ext_bl_base = (defined $ext_bl_update_support and $ext_bl_update_support eq 'TRUE') ? (&memConfig::Get_next_block_aligned_addr($root_cert_base,$ROOT_CERT_MIN_SIZE))         
                                                                                                    : ($root_cert_base + $ROOT_CERT_MIN_SIZE);# EXT_BL base without remap
            my $ext_bl_size = (defined $ext_bl_update_support and $ext_bl_update_support eq 'TRUE') ? (&memConfig::Get_next_block_aligned_addr($ext_bl_base,$EXT_BL_MIN_SIZE)- $ext_bl_base)
                                                                                                    : ($EXT_BL_MIN_SIZE);
            print "[custom_img_config_h]ext_bl_base=" . &CommonUtil::Dec2Hex($ext_bl_base) . ",ext_bl_size=" . &CommonUtil::Dec2Hex($ext_bl_size) . "\n";

            ### EXT_BOOTLOADER_BAK is behind EXT_BOOTLOADER and should be block-aligned
            my ($ext_bl_bak_base, $ext_bl_bak_size) = (($ext_bl_base + $ext_bl_size), 0); 
            if(defined $ext_bl_update_support and $ext_bl_update_support eq 'TRUE')
            {
                $ext_bl_bak_base = (&memConfig::Get_next_block_aligned_addr($ext_bl_base,$ext_bl_size));# EXT_BL base without remap
                $ext_bl_bak_size = (&memConfig::Get_next_block_aligned_addr($ext_bl_bak_base,$EXT_BL_BAK_MIN_SIZE) - $ext_bl_bak_base);
            } 
            print "[custom_img_config_h]ext_bl_bak_base=" . &CommonUtil::Dec2Hex($ext_bl_bak_base) . ",ext_bl_bak_size=" . &CommonUtil::Dec2Hex($ext_bl_bak_size) . "\n";

            ### CBR is behind EXT_BOOTLOADER
            my ($cbr_region_normal_block_num,$cbr_region_spare_block_num);
            if ($secure_ro eq 'TRUE' or $secure_support eq 'TRUE')
            {
                $cbr_region_normal_block_num = 1;
                $cbr_region_spare_block_num = 0;
            }
            else
            {
                $cbr_region_normal_block_num = 0;
                $cbr_region_spare_block_num = 0;
            }
            my $cbr_blk = $cbr_region_normal_block_num*2 + $cbr_region_spare_block_num;
            my $cbr_base = $ext_bl_bak_size==0 ? (&memConfig::Get_next_block_aligned_addr($ext_bl_base,$ext_bl_size))
                                               : (&memConfig::Get_next_block_aligned_addr($ext_bl_bak_base,$ext_bl_bak_size));# CBR base without remap
            my $nBaseAddress = $cbr_base;
            my $nblock_size = 0;
            my $cbr_size = 0;
            foreach (1..$cbr_blk)
            {
                $nblock_size = memConfig::Get_flash_block_size($nBaseAddress);
                $cbr_size += $nblock_size;
                $nBaseAddress += $nblock_size;
            }
            print "[custom_img_config_h]cbr_base=" . &CommonUtil::Dec2Hex($cbr_base) . ",cbr_size=" . &CommonUtil::Dec2Hex($cbr_size) . "\n";
            
            #to sync with layout13/layout4 in scatGenLib.pl
            $nBaseAddress = &memConfig::Get_block_aligned_addr($nBaseAddress);
            
            #reserve TinySystem size on flash
            if(&FileInfo::is("tiny_sys", "TRUE", \%MAKEFILE_OPTIONS))
            {
                my ($TS_ROM1_SIZE, $TS_ROM2_SIZE) = (44*1024,45*1024);#tiny system max image size
                $ts_rom1_begin_addr_on_flash = $nBaseAddress ^ $cs_swap_address ;	
                $str_ts_rom1_begin_addr_on_flash = sprintf("0x%08X", $ts_rom1_begin_addr_on_flash);
                $nBaseAddress += $TS_ROM1_SIZE;
                $ts_rom2_begin_addr_on_flash = $nBaseAddress ^ $cs_swap_address ;	
                $str_ts_rom2_begin_addr_on_flash = sprintf("0x%08X", $ts_rom2_begin_addr_on_flash);
                $nBaseAddress += $TS_ROM2_SIZE;

                #get next block addr as MAUI begin address
                $nBaseAddress = &memConfig::Get_block_aligned_addr($nBaseAddress);
            }
 
            $ue_flash_base_address = $nBaseAddress;
            $rom_begin_addr_on_flash = $nBaseAddress ^ $cs_swap_address ;
            $str_rom_begin_addr_on_flash = sprintf("0x%08X", $rom_begin_addr_on_flash);
            print "[custom_img_config_h]rom_begin_addr_on_flash=" . &CommonUtil::Dec2Hex($rom_begin_addr_on_flash) . "\n";
        }
        else
        {
            my ($BL_MIN_SIZE, $EXT_BL_MIN_SIZE, $EXT_BL_BAK_MIN_SIZE) = (32*1024 , 96*1024, 0);            
            $EXT_BL_MIN_SIZE = 224*1024 if(! &FileInfo::is("card_download", "NONE", \%MAKEFILE_OPTIONS));
            $EXT_BL_BAK_MIN_SIZE = 0x40000 if(&FileInfo::is("ext_bl_update_support", "TRUE", \%MAKEFILE_OPTIONS));
            $BL_MIN_SIZE = (exists $FEATURE_CONFIG_Value{MAX_BL_SIZE}) ? 
                                        hex($FEATURE_CONFIG_Value{MAX_BL_SIZE}) : $BL_MIN_SIZE;
            $EXT_BL_MIN_SIZE = (exists $FEATURE_CONFIG_Value{MAX_EXT_BL_SIZE}) ? 
                                        hex($FEATURE_CONFIG_Value{MAX_EXT_BL_SIZE}) : $EXT_BL_MIN_SIZE;
            if(&FileInfo::is("ext_bl_update_support", "TRUE", \%MAKEFILE_OPTIONS))
            {
                $EXT_BL_BAK_MIN_SIZE = (exists $FEATURE_CONFIG_Value{MAX_EXT_BL_SIZE}) ? 
                                        hex($FEATURE_CONFIG_Value{MAX_EXT_BL_SIZE}) : $EXT_BL_BAK_MIN_SIZE;
            }
            my $ReservedBLSize = $BL_MIN_SIZE + $EXT_BL_MIN_SIZE + $EXT_BL_BAK_MIN_SIZE;
            
            $ue_flash_base_address=&memConfig::Get_next_block_aligned_addr(0x0,$ReservedBLSize);
            
            if(&FileInfo::is("ext_bl_update_support", "TRUE", \%MAKEFILE_OPTIONS))
            {
                $ue_flash_base_address = &memConfig::Get_next_block_aligned_addr($BL_MIN_SIZE,$EXT_BL_MIN_SIZE);
                $ue_flash_base_address = &memConfig::Get_next_block_aligned_addr($ue_flash_base_address,$EXT_BL_BAK_MIN_SIZE);
            }
            
            #to sync with layout13/layout4 in scatGenLib.pl
            $ue_flash_base_address = &memConfig::Get_block_aligned_addr($ue_flash_base_address);
            $rom_begin_addr_on_flash = $ue_flash_base_address ^ $cs_swap_address ;
            $str_rom_begin_addr_on_flash = sprintf("0x%08X", $rom_begin_addr_on_flash);
        }
        $str_ue_flash_base_address = sprintf("0x%08X", $ue_flash_base_address);
     
        ###
        $str_ue_resident_flash_space_size = $CONFIG_FOTA_UE_FLASH_SPACE;
        $ue_resident_flash_space_size = hex($str_ue_resident_flash_space_size);
   
        ###
        $ue_execution_base = &comp_physical_ram_size() - hex('0x80000');  # Put FOTA at the last 512KB of the RAM
        $str_ue_execution_base = sprintf("0x%08X", $ue_execution_base);
   
        ###
        $maui_image_amount = 1;
        my @target_list_ref = ('ROM');
        if (exists $MAKEFILE_OPTIONS{'multiple_binary_files'} and $MAKEFILE_OPTIONS{'multiple_binary_files'} eq 'TRUE')
        {
        	  if(!defined $mba_bin or (defined $mba_bin and $mba_bin eq 'CUST_AND_LANG'))
        	  {
                $maui_image_amount = 4;
                @target_list_ref = ('ROM', 'LANG_PACK_ROM', 'CUSTPACK_ROM', 'JUMP_TABLE');
            }
            elsif(defined $mba_bin and $mba_bin eq 'LANG_ONLY')
            {
                $maui_image_amount = 3;
                @target_list_ref = ('ROM', 'LANG_PACK_ROM', 'JUMP_TABLE');
            }
            elsif(defined $mba_bin and $mba_bin eq 'CUST_ONLY')
            {
                $maui_image_amount = 3;
                @target_list_ref = ('ROM', 'CUSTPACK_ROM', 'JUMP_TABLE');
            }
        }

        ###
        ### !!! multi-image is not supported yet !!!
        my $tmp_ue_flash_space_size = $ue_resident_flash_space_size;
        $image_base_addr = $ue_flash_base_address;
        while ($tmp_ue_flash_space_size > 0)
        {
       	    $tmp_ue_flash_space_size -= &memConfig::Get_flash_block_size($image_base_addr);
       	    $image_base_addr += &memConfig::Get_flash_block_size($image_base_addr);
        }
        $str_ue_resident_flash_space_size = sprintf("0x%X", $ue_resident_flash_space_size - $tmp_ue_flash_space_size);  # UE_RESIDENT_FLASH_SPACE_SIZE should be block-aligned
        $tmp_ue_flash_space_size = $ue_resident_flash_space_size;  # backup UE space
        while ($tmp_ue_flash_space_size > 0)
        {
            $tmp_ue_flash_space_size -= &memConfig::Get_flash_block_size($image_base_addr);
    	    $image_base_addr += &memConfig::Get_flash_block_size($image_base_addr);  	       
        }
        $ue_backup_flash_space_size = $ue_resident_flash_space_size - $tmp_ue_flash_space_size;
        $str_ue_backup_flash_space_size = sprintf("0x%X", $ue_backup_flash_space_size);
        $str_image_base_addr = sprintf("0x%08X", $image_base_addr ^ $cs_swap_address);  # remapping is always adopted when FOTA_DM
        my $query_address = $BOARD_PARAMETERS{'FLASH'} - 1;
        # FOTA: 1 block for __HIDDEN_SECURE_MAC
        # FOTA+SECURE: 5 blocks for __HIDDEN_SECURE_MAC (2), __HIDDEN_SECURE_RO, __HIDDEN_FLASHTOOL_CFG, __HIDDEN_CUST_PARA 
        if (defined $fota and $fota eq 'FOTA_DM')
        {
            my $last_block_size;
            my $blocks = (exists $MAKEFILE_OPTIONS{'secure_support'} and $MAKEFILE_OPTIONS{'secure_support'} eq 'TRUE') ? 5 : 0;
            while ($blocks != 0)
            {
                $last_block_size = &memConfig::Get_flash_block_size($query_address);
                $query_address -= $last_block_size;
            	$blocks--;
            }
        }
        if(exists $MAKEFILE_OPTIONS{'boot_cert_support'} and ($MAKEFILE_OPTIONS{'boot_cert_support'} ne 'FALSE' and $MAKEFILE_OPTIONS{'boot_cert_support'} ne 'NONE'))
        {
            my $last_block_size     = &memConfig::Get_flash_block_size($query_address);
            $query_address          -= $last_block_size;
        }
        my ($nJUMPTABLE_size, $nLANG_PACK_size, $nCUSTPACK_size) = (0,0,0);
        if(exists $MAKEFILE_OPTIONS{'multiple_binary_files'} and $MAKEFILE_OPTIONS{'multiple_binary_files'} eq 'TRUE')
        {
            #JumpTable_size = 1 block
            {
                my $last_block_size      = &memConfig::Get_flash_block_size($query_address);
                $query_address           -= $last_block_size;
                $nJUMPTABLE_size         += $last_block_size;
            }
            #CUSTPACK_size = 2 blocks
            foreach (1..2)
            {
                my $last_block_size      = &memConfig::Get_flash_block_size($query_address);
                $query_address           -= $last_block_size;
                $nCUSTPACK_size          += $last_block_size;
            }
            #LANG_PACK= 8 blocks
            foreach (1..8)
            {
                my $last_block_size      = &memConfig::Get_flash_block_size($query_address);
                $query_address           -= $last_block_size;
                $nLANG_PACK_size         += $last_block_size;
                
            }
            $strLANG_PACK_size = &CommonUtil::Dec2Hex($nLANG_PACK_size);
            $strCUSTPACK_size  = &CommonUtil::Dec2Hex($nCUSTPACK_size);
            $strJUMPTABLE_size = &CommonUtil::Dec2Hex($nJUMPTABLE_size);
        }
        $ROM_size = $query_address - $image_base_addr + 1;
        if(exists $MAKEFILE_OPTIONS{'split_binary_support'} and $MAKEFILE_OPTIONS{'split_binary_support'} eq 'FACTORY_COMBINE')
        {
            my $nFactoryBinSizeBlockAligned = 0;
            my $nFactoryBlock = &memConfig::Get_flash_block_size($nFactoryBinSize);
            if($nFactoryBinSize % &memConfig::Get_flash_block_size($nFactoryBinSize) == 0)
            {
                $nFactoryBinSizeBlockAligned = $nFactoryBlock * int($nFactoryBinSize / $nFactoryBlock); 
            }
            else
            {
                $nFactoryBinSizeBlockAligned = $nFactoryBlock * int($nFactoryBinSize / $nFactoryBlock +1);    
            }
            #print "[image_config.h]FactoryBinSizeBlockAligned=$nFactoryBinSizeBlockAligned\n";
            if(($ROM_size - $nFactoryBinSizeBlockAligned) <= 0)
            {
                 &sysUtil::sysgen_die("[1.2]ROM Size($ROM_size) is not enough to put in FactoryBin(Block Aligned)($nFactoryBinSizeBlockAligned)", __FILE__, __LINE__);
            }
            $ROM_size -= $nFactoryBinSizeBlockAligned;
              
        }
        $str_ROM_size = sprintf("0x%08X", $ROM_size);
    
        ###
        my $extern_def_list;
        my $target_def_list;
        my $dummy_def_list;
        my $indent_for_str_maui_flash_space;
        foreach (@target_list_ref)
        {
            my $bin_name = $_;
            my $bin_1st_region_name = $bin_name;
            if ($bin_1st_region_name eq 'ROM' or $bin_1st_region_name eq 'LANG_PACK_ROM' or $bin_1st_region_name eq 'CUSTPACK_ROM' or $bin_1st_region_name eq 'JUMP_TABLE')
            {
                if (&sysUtil::is_sv5($BOARD_PARAMETERS{'BB'}) == 1)
                {
                    $bin_1st_region_name .= "_GFH";
                }
            }
            $extern_def_list .= "extern kal_uint32 Load\$\$$bin_1st_region_name\$\$Base;\n";
            $target_def_list .= "#define MAUI_LOAD_ADDRESS_$bin_name   ((kal_uint32)&Load\$\$$bin_1st_region_name\$\$Base)\n";
            $dummy_def_list .= "#define MAUI_LOAD_ADDRESS_$bin_name   ((kal_uint32)0)\n";
            
            if (!defined $indent_for_str_maui_flash_space)
            {
                $indent_for_str_maui_flash_space = " ";
            }
            elsif ($indent_for_str_maui_flash_space eq " ")
            {
                $indent_for_str_maui_flash_space = "                                     ";
            }
            $str_maui_flash_space .= "$indent_for_str_maui_flash_space\{MAUI_LOAD_ADDRESS_$bin_name, MAX_LENGTH_$bin_name, 0x0}, \\\n";
        }
        chomp $extern_def_list;
        chomp $target_def_list;
        chomp $dummy_def_list;
        chomp $str_maui_flash_space;
    
        ###
        $nor_image_definition .= <<"__TEMPLATE";
#if defined(__MTK_TARGET__)

$extern_def_list

$target_def_list

#else /* __MTK_TARGET__ */

$dummy_def_list
 
#endif /* __MTK_TARGET__ */

#define FOTA_MAUI_FLASH_SPACE      {$str_maui_flash_space
                                     END_MAUI_INFO}
__TEMPLATE

        ###
        if ($MAKEFILE_OPTIONS{'fota_update_package_on_nand'} eq 'TRUE')
        {
            ###
            $str_package_storage_base = $MEM_DEV_H_Value{'NOR_BOOTING_NAND_FS_BASE_ADDRESS'};
            $package_storage_base = hex($str_package_storage_base);
               
            ###
            $package_storage_size = &config_query_package_storage_size();
            $str_package_storage_size = sprintf("0x%08X", $package_storage_size);
        
            ###
            $package_block_number = $package_storage_size / 0x4000;
            $str_package_block_number = sprintf("%d", $package_block_number);
        }
        else
        {
            ###
            $package_storage_base = $ori_NOR_FLASH_BASE_ADDRESS_VAL ^ $cs_swap_address;
            $str_package_storage_base = sprintf("0x%08X", $package_storage_base);
    
            ###
            $package_storage_size = &config_query_package_storage_size();
            $str_package_storage_size = sprintf("0x%08X", $package_storage_size);
        
            ###
            $package_block_number = $CONFIG_FOTA_PACKAGE_BLOCK_NUMBER;
            $str_package_block_number = sprintf("%d", $CONFIG_FOTA_PACKAGE_BLOCK_NUMBER);
        }
        
        ### BACKUP_STORAGE is consecutive to PACKAGE_STORAGE
        $backup_storage_base = $package_storage_base + $package_storage_size;
        $str_backup_storage_base = sprintf("0x%08X", $backup_storage_base);
        
        ### BACKUP_STORAGE_SIZE is 6 blocks in NAND
        $backup_storage_size = &config_query_backup_storage_size();
        $str_backup_storage_size = sprintf("0x%08X", $backup_storage_size);
    }
	   	   
    ###
    $str_fota_maui_mapping_table_size = $CONFIG_FOTA_NAND_MAP_TABLE_SIZE;
	   	   
    ###
    my ($cbr_region_normal_block_num, $cbr_region_spare_block_num);
    if (defined $nfb_or_emb and $nfb_or_emb ne 'NONE')
    {
        $cbr_region_normal_block_num = 2;
        $cbr_region_spare_block_num = 2;
    }
    elsif ($secure_ro eq 'TRUE' or $secure_support eq 'TRUE')
    {
        $cbr_region_normal_block_num = 1;
        $cbr_region_spare_block_num = 0;
    }
    else
    {
        $cbr_region_normal_block_num = 0;
        $cbr_region_spare_block_num = 0;
    }
         
    ###
    my $template = <<"__TEMPLATE";
#ifndef __CUSTOM_IMG_CONFIG_H__
#define __CUSTOM_IMG_CONFIG_H__

#ifdef __TINY_SYS_AP__
#include "kal_general_types.h"
#include "custom_fota.h"
#include "custom_FeatureConfig.h"
#endif // __TINY_SYS_AP__    
/****************************************************************************
   Following definitions are used to configure flash memory arrangement for Bootloader image

   Item 1. the maximum size of FOTA bootloader image
   Item 2. the ROM base address on Flash when NORFLASH_NON_XIP_SUPPORT is enabled
 ****************************************************************************/
#define BL_IMG_MAX_SIZE (0x40000)
#define ROM_BASE_ON_FLASH ($str_rom_begin_addr_on_flash)

/****************************************************************************
   Following definitions are used to configure flash memory arrangement for tiny system image

   Item 1. the begin address of TINYSYS_ROM1 image on flash when TINY_SYS is enabled
   Item 2. the begin address of TINYSYS_ROM2 image on flash when TINY_SYS is enabled
 ****************************************************************************/
#define TINYSYS_ROM1_BEGIN_ADDRESS $str_ts_rom1_begin_addr_on_flash
#define TINYSYS_ROM2_BEGIN_ADDRESS $str_ts_rom2_begin_addr_on_flash

/****************************************************************************
   Following definitions are used to configure flash memory arrangement for FOTA Engine image

   Item 1. the base address of FOTA update engine image

   Item 2. the maximum available flash memory size for update engine image

   Item 3. the maximum available flash memory size for update engine image back up

   Item 4. the maximum flash memory area for bootloader to search update engine image

   Item 5. the execution start address for bootloader to place update engine image
   Note: This value MUST be the same with scatter file setting

 ****************************************************************************/
#define FOTA_UE_FLASH_BASE_ADDRESS ($str_ue_flash_base_address)

#define FOTA_UE_RESIDENT_FLASH_SPACE_SIZE   ($str_ue_resident_flash_space_size)

#define FOTA_UE_BACKUP_FLASH_SPACE_SIZE     ($str_ue_backup_flash_space_size)

#define FOTA_UE_SEARCH_RANGE_SIZE  (0x400000)

#define FOTA_UE_EXECUTION_BASE     ($str_ue_execution_base)

/****************************************************************************
   Following definitions are used to configure flash memory arrangement for MAUI image

   Item 1. the number of MAUI image binary parts

   Item 2. the start address and maximum available flash memory size for each MAUI image
   Note: This maximum available value specifies the size of flash memory that a image can 
         occupy except reserved flash blocks specified in Item 7. The start address should 
         be synchronized with the begin address of each image binary during update/delta 
         package generation process.

   Item 3. the start address of flash storage reserved for update package

   Item 4. the size of flash storage reserved for update package

   Item 5. the start address of back up area for update purpose

   Item 6. the maximum flash block number in update package area

   Item 7. the size of back up area for update purpose
   Note: Certain FOTA solution, like RedBend, requires a dedicate flash space to back up flash 
         content during update process. In contrast, some colution, such as Bitfone, would use
         leftover flash blocks that are not occupied by firmware image as back up area. In this case, 
         the value of maximum available flash memory has to be increased to compensate back up
         requirement.

   Item 8. the flash blocks reserved for flash management
   Note: This value specifies the amount of blocks that must be reseerved from
         the gap between maximum avilable flash size, Item2, and the flash memory size
         really occupied by firmware image.

 ****************************************************************************/

#define FOTA_MAUI_IMAGE_AMOUNT     ($maui_image_amount)

#if defined(__FOTA_DM__) || defined(__MULTIPLE_BINARY_FILES__)

   #if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

      #if defined(__FOTA_DM__) 
         #if defined(MAX_ROM_SIZE)
            #define MAX_LENGTH_ROM  (MAX_ROM_SIZE)
         #else  /* MAX_ROM_SIZE */
            #define MAX_LENGTH_ROM  ($size_Tbl{'ROM'})
         #endif  /* MAX_ROM_SIZE */
      #else
         #define MAX_LENGTH_ROM  (0xFFFFFFFF)
      #endif /* __FOTA_DM__ */

      #if defined(__FOTA_DM__)
         #if defined(MAX_SECONDARY_ROM_SIZE)
            #define MAX_LENGTH_SECONDARY_ROM  (MAX_SECONDARY_ROM_SIZE)
         #else  /* MAX_SECONDARY_ROM_SIZE */
            #define MAX_LENGTH_SECONDARY_ROM  ($size_Tbl{'SECONDARY_ROM'})
         #endif  /* MAX_SECONDARY_ROM_SIZE */
      #else
         #define MAX_LENGTH_SECONDARY_ROM  (0xFFFFFFFF)
      #endif /* __FOTA_DM__ */

      #if defined(__FOTA_DM__)       
         #if defined(MAX_THIRD_ROM_SIZE)
            #define MAX_LENGTH_THIRD_ROM  (MAX_THIRD_ROM_SIZE)
         #else  /* MAX_THIRD_ROM_SIZE */
            #define MAX_LENGTH_THIRD_ROM  ($size_Tbl{'THIRD_ROM'})
         #endif  /* MAX_THIRD_ROM_SIZE */
      #else
         #define MAX_LENGTH_THIRD_ROM  (0xFFFFFFFF)
      #endif /* __FOTA_DM__ */

      #if defined(__FOTA_DM__) 
         #if defined(MAX_DEMAND_PAGING_ROM0_SIZE)
            #define MAX_LENGTH_DEMAND_PAGING_ROM0  (MAX_DEMAND_PAGING_ROM0_SIZE)
         #else  /* MAX_DEMAND_PAGING_ROM0_SIZE */
            #define MAX_LENGTH_DEMAND_PAGING_ROM0  ($size_Tbl{'DEMAND_PAGING_ROM0'})
         #endif  /* MAX_DEMAND_PAGING_ROM0_SIZE */
      #else
         #define MAX_LENGTH_DEMAND_PAGING_ROM0  (0xFFFFFFFF)
      #endif /* __FOTA_DM__ */
   
      #if defined(MAX_LANG_PACK_ROM_SIZE)
         #define MAX_LENGTH_LANG_PACK_ROM  (MAX_LANG_PACK_ROM_SIZE)
      #else  /* MAX_LANG_PACK_ROM_SIZE */
         #define MAX_LENGTH_LANG_PACK_ROM  ($size_Tbl{'LANG_PACK_ROM'})
      #endif  /* MAX_LANG_PACK_ROM_SIZE */
   
      #if defined(MAX_CUSTPACK_ROM_SIZE)
         #define MAX_LENGTH_CUSTPACK_ROM  (MAX_CUSTPACK_ROM_SIZE)
      #else  /* MAX_CUSTPACK_ROM_SIZE */
         #define MAX_LENGTH_CUSTPACK_ROM  ($size_Tbl{'CUSTPACK_ROM'})
      #endif  /* MAX_CUSTPACK_ROM_SIZE */

      #define MAX_LENGTH_DSP_ROM  ($size_Tbl{'DSP_ROM'})

   #else  /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */
   
      #if defined(__FOTA_DM__)
         #if defined(MAX_ROM_SIZE)
            #define MAX_LENGTH_ROM  (MAX_ROM_SIZE)
         #else  /* MAX_ROM_SIZE */
            #define MAX_LENGTH_ROM  ($str_ROM_size)
         #endif  /* MAX_ROM_SIZE */
      #else
         #define MAX_LENGTH_ROM     (0xFFFFFFFF)
      #endif

      #if defined(__FOTA_DM__)
         #if defined(MAX_LANG_PACK_ROM_SIZE)
            #define MAX_LENGTH_LANG_PACK_ROM  (MAX_LANG_PACK_ROM_SIZE)
         #else  /* MAX_LANG_PACK_ROM_SIZE */
            #define MAX_LENGTH_LANG_PACK_ROM  ($strLANG_PACK_size)
         #endif  /* MAX_LANG_PACK_ROM_SIZE */
      #else
         #define MAX_LENGTH_LANG_PACK_ROM     (0xFFFFFFFF)
      #endif

      #if defined(__FOTA_DM__)
         #if defined(MAX_CUSTPACK_ROM_SIZE)
           #define MAX_LENGTH_CUSTPACK_ROM  (MAX_CUSTPACK_ROM_SIZE)
         #else  /* MAX_CUSTPACK_ROM_SIZE */
            #define MAX_LENGTH_CUSTPACK_ROM  ($strCUSTPACK_size)
         #endif  /* MAX_CUSTPACK_ROM_SIZE */
      #else
         #define MAX_LENGTH_CUSTPACK_ROM     (0xFFFFFFFF)
      #endif

      #if defined(__FOTA_DM__)
         #define MAX_LENGTH_JUMP_TABLE  ($strJUMPTABLE_size)
      #else
         #define MAX_LENGTH_JUMP_TABLE  (0xFFFFFFFF)
      #endif
   
   #endif  /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

#else

   #if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
      #define MAX_LENGTH_ROM                 (0xFFFFFFFF)
      #define MAX_LENGTH_SECONDARY_ROM       (0xFFFFFFFF)
      #define MAX_LENGTH_THIRD_ROM           (0xFFFFFFFF)
      #define MAX_LENGTH_DEMAND_PAGING_ROM0  (0xFFFFFFFF)
      #define MAX_LENGTH_LANG_PACK_ROM       (0xFFFFFFFF)
      #define MAX_LENGTH_CUSTPACK_ROM        (0xFFFFFFFF)
      #define MAX_LENGTH_DSP_ROM             (0xFFFFFFFF)
   #else  /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */
      #define MAX_LENGTH_ROM                 (0xFFFFFFFF)
      #define MAX_LENGTH_LANG_PACK_ROM       (0xFFFFFFFF)
      #define MAX_LENGTH_CUSTPACK_ROM        (0xFFFFFFFF)
      #define MAX_LENGTH_JUMP_TABLE          (0xFFFFFFFF)
   #endif  /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

#endif

$nfb_image_definition
$nor_image_definition

#define FOTA_PACKAGE_STORAGE_BASE  ($str_package_storage_base)

#define FOTA_PACKAGE_STORAGE_SIZE  ($str_package_storage_size)

#define FOTA_PACKAGE_BLOCK_NUMBER  ($str_package_block_number)

#define FOTA_BACKUP_STORAGE_BASE   ($str_backup_storage_base)

#define FOTA_BACKUP_STORAGE_SIZE   ($str_backup_storage_size)

#define FOTA_RESERVED_FLASH_BLOCKS     (5)

/****************************************************************************
   Following definitions are used for MAUI image manageemt

   Item 1. the size of mapping table for MAUI ROM image

   Item 2. the size of mapping table for FUE ROM image

 ****************************************************************************/
#define FOTA_MAUI_MAPPING_TABLE_SIZE   ($str_fota_maui_mapping_table_size)

/****************************************************************************
   Following definitions are used for NAND flash device configuration

   Item 1. the maximum page size of supported NAND flash device

 ****************************************************************************/
#define FOTA_FLASH_MAX_PAGE_SIZE       (0x800)

/****************************************************************************
   Following definitions are used for FUE update process

   Item 1. the maximum heap size for FUE

 ****************************************************************************/
#define FOTA_CUSTOM_POOL_SIZE       (0x200000)

/****************************************************************************
   Following definitions are used for FOTA update package certification flow

   Item 1. the maximum length of message authentication code (in bytes)

   Item 2. the maximum length of key to encrypt message authentication code (in bytes)

 ****************************************************************************/
#define FOTA_CUSTOM_PACKAGE_MAC_SIZE     (20)

#define FOTA_CUSTOM_PACKAGE_SIG_SIZE     (128)

#define FOTA_CUSTOM_PACKAGE_KEY_MAX_LEN  (128)

#define FOTA_EXTRA_RESERVED_BLOCKS       (5)

/* Following data structure should be modified according to requirements in adoption of third partys solution */
#define __FUE_DUMMY_UPDATE_SUPPORT__

#if defined(__FUE_DUMMY_UPDATE_SUPPORT__)

/*
 * !CAUTION! size of FOTA_Custom_Update_Info MUST be equal to 88 bytes
 */
typedef struct {
   kal_uint32 FOTA_test_info1;
   kal_uint32 FOTA_test_info2;
   kal_uint32 FOTA_test_info3;
   kal_uint32 FOTA_test_info4;
   kal_uint32 FOTA_test_padding[18];
} FOTA_Custom_Update_Info;

#elif defined(__FUE_HP_SUPPORT__)

#include "Hp_update.h"

#elif defined(__FUE_REDBEND_SUPPORT__)

#include "RedBend_update.h"

#else

#error "Unsupported FOTA update information!!"

#endif /* __FUE_DUMMY_UPDATE_SUPPORT__ */

typedef struct {
   kal_uint32 m_pkg_mod_key_len;
   kal_char   m_pkg_mod_key[(FOTA_CUSTOM_PACKAGE_KEY_MAX_LEN<<1)+1];
   kal_uint32 m_pkg_exp_key_len;
   kal_char   m_pkg_exp_key[(FOTA_CUSTOM_PACKAGE_KEY_MAX_LEN<<1)+1];
} FOTA_Custom_Package_Certificate_st;

/****************************************************************************
   Following definitions are used for CBR region attribute

   Item 1. the block used for store CBR data. Each Normal block will occupy 2 physical blocks

   Item 2. the block used for bad block replacement on NAND flash. For the device, it should be zero

  Total blocks occupied by CBR will be CBR_REGION_NORMAL_BLOCK_NUM*2+CBR_REGION_SPARE_BLOCK_NUM
 ****************************************************************************/
#define CBR_REGION_NORMAL_BLOCK_NUM     $cbr_region_normal_block_num

#define CBR_REGION_SPARE_BLOCK_NUM      $cbr_region_spare_block_num


#endif /* __CUSTOM_IMG_CONFIG_H__ */
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  ts_mem_config_h_file_body
#****************************************************************************
sub ts_mem_config_h_file_body()
{
    my ($template,$temResMem,$temCSCI,$temWorkaround,$temDbgInfo);
    my $bb = $BOARD_PARAMETERS{'BB'};
    
    my $strExtsramSize = &CommonUtil::Dec2Hex($BOARD_PARAMETERS{'EXTSRAM'});
    my ($strTSMMDumpSize,$strAPDspramBakSize,$strAPIntsramBakSize,$strTSLogSize,$strTSResEmiSize,$strCSCIInfoSize) = &sysUtil::GetTS_ResMemSize($bb);

    my ($strDspRamBase,$strDspRamSize);
    ($strDspRamBase,$strDspRamSize)= ($bb eq 'MT6260')? ("TS_RES_EMI_BASE","MAX_TS_RES_EMI_SIZE") 
                                                      : (&sysUtil::GetTS_DspramInfo($bb));

    $template = <<"__TEMPLATE";
#ifndef __TS_MEM_CONFIG_H
#define __TS_MEM_CONFIG_H
/**
#   Low
#   +------------------+
#   |  tiny_res_emi    |
#   |  (MT6260 only)   |
#   +------------------+
#   |  tiny_logging    |
#   |                  |
#   +------------------+
#   |  ap_intsram_bak  |
#   |                  |
#   +------------------+ 
#   |  ap_dspram_bak   |
#   |                  |
#   +------------------+    
#   |  tiny_mem_dump   |
#   |                  |
#   +------------------+    
#   |  ap_csci_info    |
#   |                  |
#   +------------------+<-----  extsram end address
#   High    
**/

#define EMI_END_ADDRESS $strExtsramSize

__TEMPLATE


    $temCSCI = <<"__TEMPLATE";
/************************CSCI INFO SIZE AND BASE DEFINITION **********************/
#define TS_DSPRAM_BASE $strDspRamBase 
#define MAX_TS_DSPRAM_SIZE $strDspRamSize

#define MAX_CSCI_INFO_SIZE ($strCSCIInfoSize) 
#define CSCI_INFO_BASE_ON_AP (EMI_END_ADDRESS - MAX_CSCI_INFO_SIZE )
#define CSCI_INFO_BASE_ON_TINY (TS_DSPRAM_BASE + MAX_TS_DSPRAM_SIZE - MAX_CSCI_INFO_SIZE)

__TEMPLATE

    $temResMem = << "__TEMPLATE";
/***********************RESERVED MEMORY ON EMI FOR TINY_SYSTEM *******************/
/*user_1: tiny_mm_dump, backup memory dump info of TS mode to EMI before exchange to AP mode*/
#define  MAX_TS_MM_DUMP_SIZE  ($strTSMMDumpSize)
#define  TS_MM_DUMP_BASE   (CSCI_INFO_BASE_ON_AP - MAX_TS_MM_DUMP_SIZE )

/*user_2: ap_dspram_bak, backup DSPRAM info on AP to EMI when exchange to tiny system*/
#define  MAX_AP_DSPRAM_BAK_SIZE  ($strAPDspramBakSize)
#define  AP_DSPRAM_BAK_BASE   (TS_MM_DUMP_BASE -  MAX_AP_DSPRAM_BAK_SIZE)

/*user_3: ap_intsram_bak, backup INTSRAM info on AP to EMI when exchange to tiny system*/
#define  MAX_AP_INTSRAM_BAK_SIZE  ($strAPIntsramBakSize)
#define  AP_INTSRAM_BAK_BASE   (AP_DSPRAM_BAK_BASE -  MAX_AP_INTSRAM_BAK_SIZE)

/*user_4: tiny_logging, bakeup log on tiny system to EMI*/
#define  MAX_TS_LOGGING_SIZE  ($strTSLogSize)
#define  TS_LOGGING_BASE   (AP_INTSRAM_BAK_BASE - MAX_TS_LOGGING_SIZE )

/*user_5: tiny_res_emi, reserve extSRAM to simulate DSPRAM on MT6260, size wil be zero for other chips*/
#define  MAX_TS_RES_EMI_SIZE ($strTSResEmiSize)
#define  TS_RES_EMI_BASE   (TS_LOGGING_BASE - MAX_TS_RES_EMI_SIZE )

__TEMPLATE


$temWorkaround = <<"__TEMPLATE";
/*workaround before CSCI is ready, use the external EMI area as share info, 4MB -- 16MB area can be used*/
#define TEMP_MM_CSCI_BASE (15*1024*1024 - 2* 1024)      //reserve 2kB for memory dump user
#define TEMP_MM_CSCI_SIZE (2*1024)
#define TEMP_CSD_CSCI_BASE (TEMP_MM_CSCI_BASE - 2*1024) //reserve 2kB for CSD user
#define TEMP_CSD_CSCI_SIZE (2*1024)

#define TEMP_TIMER_STATUS_SYNC_MEM_BASE	(TEMP_CSD_CSCI_BASE - 2*1024)
#define TEMP_TIMER_STATUS_SYNC_MEM_SIZE	(2*1024)
#if defined(__TS_KTEST__)
#define TEMP_KERNEL_TEST_SHARE_MEM_BASE (TEMP_TIMER_STATUS_SYNC_MEM_BASE - 512)
#define TEMP_KERNEL_TEST_SHARE_MEM_SIZE (512)
#endif

/**
#   Low
#   +------------------+<-----  4*1024*1024
#   |                  |
#   |      (.....)     |
#   |                  |
#   |                  |
#   +------------------+
#   |      CSD         |
#   |                  |
#   +------------------+   
#   |  memory dump     |
#   |                  |
#   +------------------+<-----  16*1024*1024
#   High    
**/

#endif //__TS_MEM_CONFIG_H
__TEMPLATE

    $template .= $temCSCI.$temResMem.$temWorkaround;
    if($DebugPrint)
    {
        my ($strEMISize,$strTSMMDumpBase,$strAPDspramBakBase,$strAPIntsramBakBase,$strTSLogBase,$strTSResEmiBase,$strCSCIInfoBaseAP,$strCSCIInfoBaseTS);
        $strCSCIInfoBaseAP = &CommonUtil::Dec2Hex(hex($strExtsramSize)-hex($strCSCIInfoSize));
        $strCSCIInfoBaseTS = ($bb eq 'MT6260')? &CommonUtil::Dec2Hex(hex($strTSResEmiBase)+hex($strTSResEmiSize)-hex($strCSCIInfoSize))
                                              : &CommonUtil::Dec2Hex(hex($strDspRamBase)+hex($strDspRamSize)-hex($strCSCIInfoSize));
        $strEMISize = &CommonUtil::Dec2Hex($BOARD_PARAMETERS{'EXTSRAM'});
        $strTSMMDumpBase = &CommonUtil::Dec2Hex(hex($strCSCIInfoBaseAP)-hex($strTSMMDumpSize));
        $strAPDspramBakBase = &CommonUtil::Dec2Hex(hex($strTSMMDumpBase)-hex($strAPDspramBakSize));
        $strAPIntsramBakBase = &CommonUtil::Dec2Hex(hex($strAPDspramBakBase)-hex($strAPIntsramBakSize));
        $strTSLogBase = &CommonUtil::Dec2Hex(hex($strAPIntsramBakBase)-hex($strTSLogSize));
        $strTSResEmiBase = &CommonUtil::Dec2Hex(hex($strTSLogBase)-hex($strTSResEmiSize));

        $temDbgInfo = << "__TEMPLATE";
[
    EXTSRAM_SIZE            = $strEMISize
    
    MAX_TS_MM_DUMP_SIZE     = $strTSMMDumpSize
    TS_MM_DUMP_BASE         = $strTSMMDumpBase
    
    MAX_AP_DSPRAM_BAK_SIZE  = $strAPDspramBakSize
    AP_DSPRAM_BAK_BASE      = $strAPDspramBakBase 
    
    MAX_AP_INTSRAM_BAK_SIZE = $strAPIntsramBakSize
    AP_INTSRAM_BAK_BASE     = $strAPIntsramBakBase
    
    MAX_TS_LOGGING_SIZE     = $strTSLogSize
    TS_LOGGING_BASE         = $strTSLogBase
    
    MAX_TS_RES_EMI_SIZE     = $strTSResEmiSize
    TS_RES_EMI_BASE         = $strTSResEmiBase

    MAX_TS_DSPRAM_SIZE      = $strDspRamSize
    TS_DSPRAM_BASE          = $strDspRamBase
    
    MAX_CSCI_INFO_SIZE      = $strCSCIInfoSize
    CSCI_INFO_BASE_ON_AP    = $strCSCIInfoBaseAP
    CSCI_INFO_BASE_ON_TINY  = $strCSCIInfoBaseTS
]
__TEMPLATE
        print "$temDbgInfo";
    }
    
    return $template;
}
#****************************************************************************
# subroutine:  gather the required information for board
# return:      void (add key / value in input hash)
#****************************************************************************
sub gather_board_parameters
{
    my ($hash_ref) = @_;

    # <1> get platform
    $hash_ref->{'FLASH'}   = &comp_flash_size();
    $hash_ref->{'EXTSRAM'}          = &comp_ram_size();
    $hash_ref->{'EXTSRAM_ORIGINAL'} = &comp_physical_ram_size();
    $hash_ref->{'BB'}      = $MAKEFILE_OPTIONS{'platform'};
    if ($g_USE_DUMMY_SCATTER eq 'TRUE')
    {
        $hash_ref->{'FLASH'} = 0x8000000;
        $hash_ref->{'EXTSRAM'} = 0x8000000;
        $hash_ref->{'EXTSRAM_ORIGINAL'} = 0x8000000;
        $FEATURE_CONFIG_Value{'CONFIG_ZIMAGE_DECOMPRESSED_SIZE'} = "0x2000000";
    }

    # <2> gather sw features
    $hash_ref->{'SWCFG'}   = "";

    if (exists $MAKEFILE_OPTIONS{'nand_flash_booting'}
           and $MAKEFILE_OPTIONS{'nand_flash_booting'} ne 'NONE')
    {
        $hash_ref->{'NFB'} = 1;
        $hash_ref->{'SWCFG'} .= "NFB ";
    }
    if (exists $MAKEFILE_OPTIONS{'emmc_booting'}
           and $MAKEFILE_OPTIONS{'emmc_booting'} ne 'NONE')
    {
        $hash_ref->{'NFB'} = 1;
        $hash_ref->{'SWCFG'} .= "EMB ";
    }
    if (exists $MAKEFILE_OPTIONS{'fota_enable'}
           and $MAKEFILE_OPTIONS{'fota_enable'} ne 'NONE')
    {
        $hash_ref->{'SWCFG'} .= "FOTA ";
    }
    if (exists $MAKEFILE_OPTIONS{'usb_download_in_bl'}
           and $MAKEFILE_OPTIONS{'usb_download_in_bl'} ne 'NONE')
    {
        $hash_ref->{'SWCFG'} .= "USBDOWNLOAD ";
    }
    if (exists $MAKEFILE_OPTIONS{'multiple_binary_files'}
           and $MAKEFILE_OPTIONS{'multiple_binary_files'} eq 'TRUE')
    {
        $hash_ref->{'SWCFG'} .= "MULTIBIN ";
    }
    if (exists $MAKEFILE_OPTIONS{'secure_support'}
           and $MAKEFILE_OPTIONS{'secure_support'} eq 'TRUE')
    {
        $hash_ref->{'SWCFG'} .= "SECURE ";
    }
    if (exists $MAKEFILE_OPTIONS{'enhanced_single_bank_nor_flash_support'}
           and $MAKEFILE_OPTIONS{'enhanced_single_bank_nor_flash_support'} eq 'TRUE')
    {
        $hash_ref->{'SWCFG'} .= "ESBNOR ";
    }
}

#****************************************************************************
# subroutine:  dump the board parameters
# return:      the summary string 
#****************************************************************************
sub dump_board_parameters
{
    my ($bb, $loadsize, $ramsize) = ($BOARD_PARAMETERS{'BB'},
                                     $BOARD_PARAMETERS{'FLASH'} / (1024 * 1024),
                                     $BOARD_PARAMETERS{'EXTSRAM'} / (1024 * 1024)
                                    );
    $loadsize = $loadsize . "MB";
    $ramsize  = $ramsize . "MB";
    my $sw_features = $BOARD_PARAMETERS{'SWCFG'};

    my $template1 = <<"__TEMPLATE";
;--------------------
; SCHEME   : external $loadsize flash memory and $ramsize SRAM
; PLATFORM : $bb
; FEATURES : $sw_features
;--------------------
__TEMPLATE

    my $template2 = <<"__TEMPLATE";
;--------------------
; SCHEME   : external NAND flash and $ramsize LPSDRAM
; PLATFORM : $bb
; FEATURES : $sw_features
;--------------------
__TEMPLATE

   if (exists $BOARD_PARAMETERS{'NFB'}) { return $template2; }
   else                                 { return $template1; }
}

#****************************************************************************
# subroutine:  comp_flash_size
# return:      EMI value
#****************************************************************************
sub comp_flash_size
{
    my $rom_limit;
    
    if ((exists $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} ne 'NONE') or (exists $MAKEFILE_OPTIONS{'emmc_booting'} and $MAKEFILE_OPTIONS{'emmc_booting'} ne 'NONE'))
    {
        return 0;
    }
       
    if (exists $FEATURE_CONFIG_Value{'PROJECT_EXPECTED_CODE_LIMIT'})
    {
        $rom_limit = hex($FEATURE_CONFIG_Value{'PROJECT_EXPECTED_CODE_LIMIT'});
    }
    else
    {
       $rom_limit = $ori_NOR_FLASH_BASE_ADDRESS_VAL;
    }
    
    if ($DebugPrint == 1)
    {
       printf "[comp_flash_size]ROM size limit: 0x%08X\n", $rom_limit;
    }
    
    return $rom_limit;
}

#****************************************************************************
# subroutine:  comp_ram_size
# return:      EMI value
#****************************************************************************
sub comp_ram_size
{
    my $ram_limit;
    if ((defined $FEATURE_CONFIG_Value{'PROJECT_EXPECTED_RAM_LIMIT'}) && ((!exists $MAKEFILE_OPTIONS{'nand_flash_booting'} or $MAKEFILE_OPTIONS{'nand_flash_booting'} eq 'NONE') and (!exists $MAKEFILE_OPTIONS{'emmc_booting'} or $MAKEFILE_OPTIONS{'emmc_booting'} eq 'NONE')))
    {
        $ram_limit = hex($FEATURE_CONFIG_Value{'PROJECT_EXPECTED_RAM_LIMIT'});
    }
    elsif ((defined $FEATURE_CONFIG_Value{'PROJECT_EXPECTED_RAM_LIMIT_NFB'}) && ((exists $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} ne 'NONE') or (exists $MAKEFILE_OPTIONS{'emmc_booting'} and $MAKEFILE_OPTIONS{'emmc_booting'} ne 'NONE')))
    {
        $ram_limit = hex($FEATURE_CONFIG_Value{'PROJECT_EXPECTED_RAM_LIMIT_NFB'});
    }
    else
    {
       $EMI_H_Value{'EXTSRAM_SIZE'} =~ s/\(//;
       $EMI_H_Value{'EXTSRAM_SIZE'} =~ s/\(//;
       $ram_limit = $EMI_H_Value{'EXTSRAM_SIZE'} * 1024 * 1024 / 8;
    }

    if ($DebugPrint == 1)
    {
       printf "[comp_ram_size]RAM size limit: 0x%08X\n", $ram_limit;
    }
    
    return $ram_limit;
}

#****************************************************************************
# subroutine:  comp_physical_ram_size
# return:      EMI value
#****************************************************************************
sub comp_physical_ram_size
{
    my $ram_size;
    $EMI_H_Value{'EXTSRAM_SIZE'} =~ s/\(//;
    $EMI_H_Value{'EXTSRAM_SIZE'} =~ s/\(//;
    $ram_size = $EMI_H_Value{'EXTSRAM_SIZE'} * 1024 * 1024 / 8;

    if ($DebugPrint == 1)
    {
        printf "[comp_physical_ram_size]RAM size: 0x%08X\n", $ram_size;
    }
    
    return $ram_size;
}


#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query FOTA_PACKAGE_STORAGE_SIZE
# input:       None
# Output:      FOTA_PACKAGE_STORAGE_SIZE
#****************************************************************************
sub config_query_package_storage_size
{
    my $package_storage_size = 0;
    
    if ($MAKEFILE_OPTIONS{'fota_enable'} eq 'FOTA_DM')
    {
        if ((defined $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} ne 'NONE') or (defined $MAKEFILE_OPTIONS{'emmc_booting'} and $MAKEFILE_OPTIONS{'emmc_booting'} ne 'NONE') or ($MAKEFILE_OPTIONS{'fota_update_package_on_nand'} eq 'TRUE'))
        {
            $package_storage_size = (hex($CONFIG_FOTA_PACKAGE_AREA_SIZE) / 0x20000) * 0x20000;
        }
        else
        {
            my $fota_block_number = $CONFIG_FOTA_PACKAGE_BLOCK_NUMBER;
            my $tmp_fs_base = $ori_NOR_FLASH_BASE_ADDRESS_VAL;
            while ($fota_block_number > 0)
            {
                my $tmp_block_sz;
                $tmp_block_sz = &memConfig::Get_flash_block_size($tmp_fs_base);
                $tmp_fs_base += $tmp_block_sz;
                $package_storage_size += $tmp_block_sz;
                $fota_block_number--;
            }
        }
    }
    
    return $package_storage_size;
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query FOTA_BACKUP_STORAGE_BASE
# input:       None
# Output:      FOTA_BACKUP_STORAGE_BASE
#****************************************************************************
sub config_query_backup_storage_size
{
    my $backup_storage_size = 0;
    
    if ($MAKEFILE_OPTIONS{'fota_enable'} eq 'FOTA_DM')
    {
        if ((defined $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} ne 'NONE') or (defined $MAKEFILE_OPTIONS{'emmc_booting'} and $MAKEFILE_OPTIONS{'emmc_booting'} ne 'NONE'))
        {
            $backup_storage_size = 6 * 0x20000;
        }
        else
        {
            my $query_address = 0;
            my $max_block_size = 0;
            while ($query_address < hex($FLASH_H_Value{'NOR_FLASH_DENSITY'}))
            {
                my $cur_block_size = &memConfig::Get_flash_block_size($query_address);
                if ($cur_block_size > $max_block_size)
                {
                    $max_block_size = $cur_block_size;
                }
                $query_address += $cur_block_size;
            }
            $backup_storage_size = 2 * $max_block_size;
        }
    }
    
    return $backup_storage_size;
}

#****************************************************************************
# subroutine:  check user settings validity
# input:       $nor_flash_base_address:      NOR_FLASH_BASE_ADDRESS
# input:       $nor_allocated_fat_space:     NOR_ALLOCATED_FAT_SPACE
# input:       $project_expected_ram_limit:  PROJECT_EXPECTED_RAM_LIMIT
# input:       $project_expected_code_limit: PROJECT_EXPECTED_CODE_LIMIT
# return:      void
#****************************************************************************
sub check_user_setting
{
    my $flash_size          = hex($FLASH_H_Value{'NOR_FLASH_DENSITY'});
	   my @regions             = @FLASH_H_Value_REGION_LIST;
	   my @banks               = @FLASH_H_Value_BANK_LIST;
	   my @blocks              = @FLASH_H_Value_BLK_LIST;
    my $small_block_start   = $flash_size;
    my $sum_of_regions      = 0;
    my $blocks_of_regions   = 0;
    my $fat_base            = 0;
    my $fat_space           = 0;

    ### Calculate FAT size/start address
    for (0..$#regions)
    {
        if ($regions[$_] =~ /\{(0x\w+),\s*(\d+)\}/) # match {0x20000, 7}
        {
            $sum_of_regions += hex($1) * $2;
        }
    }
    
    if (($#regions>=0) && (defined $MEM_DEV_H_Value{'__NOR_FDM5__'}) && ($MEM_DEV_H_Value{'__NOR_FDM5__'} eq 'TRUE'))
    {
        if ($blocks[$#blocks] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0xFF0000,0x2000}
        {
            $small_block_start = hex($1);
        }
        $fat_space = $sum_of_regions - ($flash_size-$small_block_start);
    }
    else
    {
        $fat_space = $sum_of_regions;
    }
    $fat_base = $flash_size - $sum_of_regions;
    my $base_addr_string    = sprintf("0x%08X", $fat_base);
    my $fat_space_string    = sprintf("0x%08X", $fat_space);

    ### Check FAT settings validity
    my ($fat_block_aligned, $fat_bank_aligned);
    if ((defined $MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_BASE_ADDRESS'}) && (defined $MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_SIZE'}))
    {
        $NOR_FLASH_BASE_ADDRESS_VAL = hex($MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_BASE_ADDRESS'});
        $NOR_ALLOCATED_FAT_SPACE_VAL = hex($MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_SIZE'});
    }
    elsif ((defined $MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_BASE_ADDRESS'}) && (!defined $MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_SIZE'}))
    {
        $NOR_FLASH_BASE_ADDRESS_VAL = hex($MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_BASE_ADDRESS'});
        if (defined $MEM_DEV_H_Value{'__NOR_FDM5__'})
        {
            $NOR_ALLOCATED_FAT_SPACE_VAL = $small_block_start - hex($MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_BASE_ADDRESS'});
        }
        else
        {
            $NOR_ALLOCATED_FAT_SPACE_VAL = $flash_size - hex($MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_BASE_ADDRESS'});
        }
    }
    elsif ((!defined $MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_BASE_ADDRESS'}) && (defined $MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_SIZE'}))
    {
        $NOR_FLASH_BASE_ADDRESS_VAL = $fat_base;
        $NOR_ALLOCATED_FAT_SPACE_VAL = hex($MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_SIZE'});
    }
    else
    {
        $NOR_FLASH_BASE_ADDRESS_VAL = $fat_base;
        $NOR_ALLOCATED_FAT_SPACE_VAL = $fat_space;
    }
    $ori_NOR_FLASH_BASE_ADDRESS_VAL = $NOR_FLASH_BASE_ADDRESS_VAL;

    ### work-around for bad small block issue
    if ((($NOR_FLASH_BASE_ADDRESS_VAL+$NOR_ALLOCATED_FAT_SPACE_VAL)>$flash_size) && (($NOR_FLASH_BASE_ADDRESS_VAL+$NOR_ALLOCATED_FAT_SPACE_VAL)<=($FLASH_H_Value{'NOR_FLASH_SIZE(Mb)'}/8*1024*1024)))
    {
        $NOR_ALLOCATED_FAT_SPACE_VAL = $NOR_ALLOCATED_FAT_SPACE_VAL - ($NOR_FLASH_BASE_ADDRESS_VAL+$NOR_ALLOCATED_FAT_SPACE_VAL-$flash_size);
    }

    if ($DebugPrint == 1)
    {
    	   my $flash_base_address_str = sprintf("0x%08x", $NOR_FLASH_BASE_ADDRESS_VAL);
    	   my $allocated_fat_space_str = sprintf("0x%08x", $NOR_ALLOCATED_FAT_SPACE_VAL);
    	   print "[check_user_setting]FLASH_BASE_ADDRESS = $flash_base_address_str,\n[check_user_setting]ALLOCATED_FAT_SPACE = $allocated_fat_space_str\n";
    }
    
    &sysUtil::sysgen_die("[3.2]$CUSTOM_MEM_DEV_H: FAT_base_addr and FAT space should not < 0!", __FILE__, __LINE__)
        if (($NOR_FLASH_BASE_ADDRESS_VAL<0) || ($NOR_ALLOCATED_FAT_SPACE_VAL<0));
    &sysUtil::sysgen_die("[3.2]$CUSTOM_MEM_DEV_H: FAT space cannot exceed physical NOR flash size!", __FILE__, __LINE__)
        if (($NOR_FLASH_BASE_ADDRESS_VAL+$NOR_ALLOCATED_FAT_SPACE_VAL) > $flash_size);
    if (defined $MEM_DEV_H_Value{'__NOR_FDM5__'})
    {
        &sysUtil::sysgen_die("[3.2]$CUSTOM_MEM_DEV_H: FAT space cannot include small blocks in NOR FDM 5.0!", __FILE__, __LINE__)
            if (($NOR_FLASH_BASE_ADDRESS_VAL+$NOR_ALLOCATED_FAT_SPACE_VAL) > $small_block_start);
    }
    if ((defined $MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_BASE_ADDRESS'}) || (defined $MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_SIZE'}))
    {
        #single-bank FAT start address needs to be block-aligned
        for (0..$#blocks)
        {
            my $cur_block = $blocks[$#blocks-$_];
            if ($cur_block =~ /\{(0x\w+),\s*(0x\w+)\}/)
            {
                if ($NOR_FLASH_BASE_ADDRESS_VAL >= hex($1))
                {
                    if ((($NOR_FLASH_BASE_ADDRESS_VAL-hex($1))%hex($2)) == 0)
                    {
                        $fat_block_aligned = 'TRUE';
                    }
                    last;
                }
            }
        }
        
        #multi-bank FAT start address needs to be bank-aligned
        my $sum_of_banks = 0;
        for (0..$#banks)
        {
            my $cur_bank = $banks[$_];

            if ($cur_bank =~ /\{\s*(0x\w+),\s*(\d+)\s*\}/)
            {
                for (0..($2-1))
                {
                    $sum_of_banks += hex($1);
                    if ($sum_of_banks >= $NOR_FLASH_BASE_ADDRESS_VAL)
                    {
                        last;
                    }
                }
                if ($sum_of_banks >= $NOR_FLASH_BASE_ADDRESS_VAL)
                {
                    last;
                }
            }
        }
        if ($sum_of_banks == $NOR_FLASH_BASE_ADDRESS_VAL)
        {
            $fat_bank_aligned = 'TRUE';
        }
    }
    else
    {
        $fat_block_aligned = 'TRUE';
        $fat_bank_aligned = 'TRUE';
    }
    
    if ((exists $MAKEFILE_OPTIONS{'enhanced_single_bank_nor_flash_support'} and $MAKEFILE_OPTIONS{'enhanced_single_bank_nor_flash_support'} eq 'TRUE'))
    {
    	   &sysUtil::sysgen_die("[3.2]$CUSTOM_MEM_DEV_H: NOR_FLASH_BASE_ADDRESS needs to be block-aligned in single-bank setting!", __FILE__, __LINE__)
    	       if ($fat_block_aligned ne 'TRUE');
    }
    else
    {
    	   &sysUtil::sysgen_die("[3.2]$CUSTOM_MEM_DEV_H: NOR_FLASH_BASE_ADDRESS needs to be bank-aligned in multi-bank setting!", __FILE__, __LINE__)
    	       if ($fat_bank_aligned ne 'TRUE');
    }
    
    ### Check CODE setting validity
    if (defined $FEATURE_CONFIG_Value{'PROJECT_EXPECTED_CODE_LIMIT'})
    {
        #ensure practical
        &sysUtil::sysgen_die("[2.0]$CUSTOM_FEATURECONFIG_H: Cannot configure expected CODESIZE larger than (physical NOR flash size - FAT space)!", __FILE__, __LINE__)
            if ( hex($FEATURE_CONFIG_Value{'PROJECT_EXPECTED_CODE_LIMIT'}) > $NOR_FLASH_BASE_ADDRESS_VAL );
    }

    ### Check RAM setting validity
    if (defined $FEATURE_CONFIG_Value{'PROJECT_EXPECTED_RAM_LIMIT'})
    {
        #ensure practical
        &sysUtil::sysgen_die("[2.0]$CUSTOM_FEATURECONFIG_H: Cannot configure expected RAMSIZE larger than physical RAM size!", __FILE__, __LINE__)
            if ( hex($FEATURE_CONFIG_Value{'PROJECT_EXPECTED_RAM_LIMIT'}) > &comp_physical_ram_size() );
    }

    ### FAT tuning for FOTA
    if (($MAKEFILE_OPTIONS{'fota_enable'} eq 'FOTA_DM') and (!exists $MAKEFILE_OPTIONS{'fota_update_package_on_nand'} or $MAKEFILE_OPTIONS{'fota_update_package_on_nand'} ne 'TRUE'))
    {
        $NOR_FLASH_BASE_ADDRESS_VAL += &config_query_package_storage_size() + &config_query_backup_storage_size();
        $NOR_ALLOCATED_FAT_SPACE_VAL -= &config_query_package_storage_size() + &config_query_backup_storage_size();
    }
}

#****************************************************************************
# subroutine:  description_file_header
# return:      file header -- description 
# input:       $filename:     filename
# input:       $description:  one line description
# input:       $author:       optional
#****************************************************************************
sub description_file_header_for_scatter
{
    my ($filename, $description, $author, $board_description) = @_;
    my ($day, $month, $year) = (localtime)[3,4,5]; $month++; $year+=1900;
    $filename =~ s/.*\\//;
    my $template = <<"__TEMPLATE";
;/*****************************************************************************
; *
; * Filename:
; * ---------
; *   $filename
; *
; * Project:
; * --------
; *   Maui_Software
; *
; * Description:
; * ------------
; *   defines the memory map for the validation board
; *
; * Author:
; * -------
; *   $author
; *
; * Auto Generated Date:
; * -------
; *   $year/$month/$day
; *
; * Revision History:
; * -------
; * \$Log: $filename $author \$
; * 
; ****************************************************************************/
;
;=========================================================================
; This scatter file is auto-generated and please DO NOT change the content at will
;=========================================================================
;
$board_description
__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  copyright_file_header
# return:      file header -- copyright
#****************************************************************************
sub copyright_file_header_for_scatter
{
    my $pre_compile_str;
    my $bb = $MAKEFILE_OPTIONS{'platform'};
    my $dsp_solution = $MAKEFILE_OPTIONS{'dsp_solution'};
    my $alice = $MAKEFILE_OPTIONS{'alice_support'};
    my $mba = $MAKEFILE_OPTIONS{'multiple_binary_files'};
    my $norflash_non_xip = $MAKEFILE_OPTIONS{'norflash_non_xip_support'};
    my $isMauiInit = $MAKEFILE_OPTIONS{'dcm_compression_maui_init'};
    if (&sysUtil::NeedPreCompile($bb, $dsp_solution, $alice, $mba, &isNFB(),$norflash_non_xip,$isMauiInit))
    {
        $pre_compile_str = "#! armcc -E";
    }
    chomp $pre_compile_str;
    
    my $template = <<"__TEMPLATE";
$pre_compile_str
;/*****************************************************************************
;*  Copyright Statement:
;*  --------------------
;*  This software is protected by Copyright and the information contained
;*  herein is confidential. The software may not be copied and the information
;*  contained herein may not be used or disclosed except with the written
;*  permission of MediaTek Inc. (C) 2007
;*
;*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
;*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
;*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
;*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
;*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
;*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
;*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
;*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
;*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
;*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
;*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
;*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
;*
;*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
;*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
;*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
;*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
;*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
;*
;*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
;*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
;*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
;*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
;*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
;*
;*****************************************************************************/
;
__TEMPLATE

   return $template;
}

#****************************************************************************
#****************************************************************************
# Subroutine: config_DummyScatterSetting
# Purpose: Check user settings validity - DUMMY SCATTER
# Global variable: $MAKEFILE_OPTIONS
#                  $INSIDE_MTK
#                  $g_USE_DUMMY_SCATTER
#                  $DUMMY_SCATTER_FORCE
#                  $SCATTERFILE
#****************************************************************************
sub config_DummyScatterSetting
{
    if (1 == &FileInfo::is_NOR(\%MAKEFILE_OPTIONS))
    {
        if (exists $MAKEFILE_OPTIONS{'dummy_scatter_enable'} and $MAKEFILE_OPTIONS{'dummy_scatter_enable'} eq 'TRUE')
        {
            if ($INSIDE_MTK == 1)
            {
                $g_USE_DUMMY_SCATTER = 'TRUE';
            }
        }
    }
    if ($DUMMY_SCATTER_FORCE eq 'TRUE')
    {
        $g_USE_DUMMY_SCATTER = 'TRUE';
    }
    if( 1 == &sysUtil::HasCheckinHistory($SCATTERFILE) && $g_USE_DUMMY_SCATTER eq 'TRUE')
    {
        &sysUtil::sysgen_die("[3.2]Generating DUMMY SCATTER FILE can't work when a manual checked-in scatter file exists.\nRecommand: Please remove your own modifications first, \nrebuild and make sure the load is successfully built, \nthen add your own modifications back.\n", __FILE__, __LINE__);
    }
}
#****************************************************************************
# Subroutine: GetFactoryBinSize
# Purpose: Get Factory Bin Size if necessary
# Global variable: $MAKEFILE_OPTIONS
#                  $FACTORY_BIN_PATH
#                  $nFactoryBinSize
#                  $DebugPrint
#****************************************************************************
sub GetFactoryBinSize
{
    if(exists $MAKEFILE_OPTIONS{'split_binary_support'} and $MAKEFILE_OPTIONS{'split_binary_support'} eq 'FACTORY_COMBINE')
    {
        if(1 == &FileInfo::is_NOR(\%MAKEFILE_OPTIONS))
        {
            if(-e $FACTORY_BIN_PATH)
            {
                print "[GetFactoryBinSize]factory bin path=$FACTORY_BIN_PATH\n" if ($DebugPrint == 1);
                $nFactoryBinSize = -s $FACTORY_BIN_PATH;
                print "[GetFactoryBinSize]factory bin size=$nFactoryBinSize\n" if ($DebugPrint == 1);
            }
            else
            {
                &sysUtil::sysgen_die("[1.4]make\\Gsm2.mak: Factory Bin path doesn't exist!", __FILE__, __LINE__);
            }
        }
    }
}

#****************************************************************************
# Subroutine: ParseDefinition
# Purpose: parse key definition in the input file
# Input: 1. strFilePath, 2. Hash_ref(Result Container)
#****************************************************************************
sub ParseDefinition
{
    my ($strFilePath, $Hash_ref) = @_;
    open (MEMDEVH_HANDLE, "<$strFilePath") or &sysUtil::sysgen_die("[1.4]$strFilePath: file error!", __FILE__, __LINE__);
    PrintDependency($strFilePath);
    while (<MEMDEVH_HANDLE>) {
        if (/^#define\s+(\w+)\s+\((\w*)\)/ || /^#define\s+(\w+)\s+(\w*)/)
        {
            my $option = $1;
            my $value  = $2;
            
            &sysUtil::sysgen_die("[3.2]$strFilePath: $option redefined in custom_MemoryDevice.h!", __FILE__, __LINE__) if defined($Hash_ref->{$option});
            if (!defined $value)
            {
                $Hash_ref->{$option} = 'TRUE';
            }
            else
            {
                $Hash_ref->{$option} = $value;
            }
        }
    }
    close (MEMDEVH_HANDLE);
}

#****************************************************************************
# Subroutine: GetExtsramSize
# Purpose: parse key definition in CUSTOM_EMI_RELEASE_H
# Input: 1. strFilePath, 2. Hash_ref(Result Container)
#****************************************************************************
sub GetExtsramSize
{
    my ($strFilePath, $Hash_ref) = @_;
    # EXTSRAM_SIZE is defined in custom_EMI_release.h
    open (EMIRELEASEH_HANDLE, "<$strFilePath") or &sysUtil::sysgen_die("[3.2]$strFilePath: file error!", __FILE__, __LINE__);
    PrintDependency($strFilePath);
    while (<EMIRELEASEH_HANDLE>) {
        if (/^#define EMI_EXTSRAM_SIZE\s+\(\s*\(*\s*\(*\s*(\S+)\)*\s*<<\s*20\s*\)*\s*>>\s*3\s*\)/)
        {
            $Hash_ref->{'EXTSRAM_SIZE'} = $1;
        }
    }
    close (EMIRELEASEH_HANDLE);
}
                                      
#****************************************************************************
# Subroutine: ParseFlashInfo-NAND
# Purpose: parse key definition in FLASH_OPT_GEN_H
# Input: strFilePath
#****************************************************************************
sub ParseFlashInfo_NAND
{
    my ($strFilePath) = @_;
    open (FLASHOPTGENH_HANDLE, "<$strFilePath") or &sysUtil::sysgen_die("[3.2]$strFilePath: file error!", __FILE__, __LINE__);
    PrintDependency($strFilePath);
    while (<FLASHOPTGENH_HANDLE>) {
        if (/^#define NAND_TOTAL_SIZE\s*(\w*)/)
        {
            $NAND_flash_size = $1;
        }
    }
    close (FLASHOPTGENH_HANDLE);
}
#****************************************************************************
# Subroutine: PrintDebugInfo
# Purpose: Print Memory related information for debug usage
#****************************************************************************
sub PrintDebugInfo
{
    if ($DebugPrint == 1)
    {
        print "custom_EMI.h:\n";
        print "EXTSRAM_SIZE = $EMI_H_Value{'EXTSRAM_SIZE'}\n";
        print "\n";
        
        print "custom_MemoryDevice.h:\n";
        print "NOR_BOOTING_NOR_FS_BASE_ADDRESS = $MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_BASE_ADDRESS'}\n";
        print "NOR_BOOTING_NOR_FS_SIZE = $MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_SIZE'}\n";
        print "NOR_BOOTING_NOR_FS_FIRST_DRIVE_SECTORS = $MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_FIRST_DRIVE_SECTORS'}\n";
        print "NOR_BOOTING_NAND_FS_BASE_ADDRESS = $MEM_DEV_H_Value{'NOR_BOOTING_NAND_FS_BASE_ADDRESS'}\n";
        print "NOR_BOOTING_NAND_FS_SIZE = $MEM_DEV_H_Value{'NOR_BOOTING_NAND_FS_SIZE'}\n";
        print "NOR_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS = $MEM_DEV_H_Value{'NOR_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS'}\n";
        print "NOR_BOOTING_NAND_BLOCK_SIZE = $MEM_DEV_H_Value{'NOR_BOOTING_NAND_BLOCK_SIZE'}\n";
        print "NAND_BOOTING_NAND_FS_BASE_ADDRESS = $MEM_DEV_H_Value{'NAND_BOOTING_NAND_FS_BASE_ADDRESS'}\n";
        print "NAND_BOOTING_NAND_FS_SIZE = $MEM_DEV_H_Value{'NAND_BOOTING_NAND_FS_SIZE'}\n";
        print "NAND_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS = $MEM_DEV_H_Value{'NAND_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS'}\n";
        print "PROJECT_EXPECTED_RAM_LIMIT = $FEATURE_CONFIG_Value{'PROJECT_EXPECTED_RAM_LIMIT'}\n";
        print "PROJECT_EXPECTED_CODE_LIMIT = $FEATURE_CONFIG_Value{'PROJECT_EXPECTED_CODE_LIMIT'}\n";
        print "\n";
        
        print "custom_flash.h:\n";
        print "BlockTBLTxt = $FLASH_H_Value{'BlockTBLTxt'}\n";
        print "RegionInfoTxt = $FLASH_H_Value{'RegionInfoTxt'}\n";
        print "BankInfoTxt = $FLASH_H_Value{'BankInfoTxt'}\n";
        print "NOR_FLASH_DENSITY = $FLASH_H_Value{'NOR_FLASH_DENSITY'}\n";
        print "\n";
        
        print "BOARD_PARAMTERS:\n";
        print "FLASH = ".&CommonUtil::Dec2Hex($BOARD_PARAMETERS{'FLASH'})."\n";
        print "EXTSRAM = ".&CommonUtil::Dec2Hex($BOARD_PARAMETERS{'EXTSRAM'})."\n";
        print "EXTSRAM_ORIGINAL = ".&CommonUtil::Dec2Hex($BOARD_PARAMETERS{'EXTSRAM_ORIGINAL'})."\n";
        print "\n";
    }
}
#****************************************************************************
# Subroutine: ParseCUSTOM_IMG_CONFIG_H
# Purpose:  FOTA configurations gathering
# Input: 1. strFilePath, 2. Hash_ref(Result Container)
#****************************************************************************
sub ParseCUSTOM_IMG_CONFIG_H()
{
    my ($strFilePath , $Hash_ref) = @_;
    open (CUSTOM_IMG_CONFIG_READ_H, "<$strFilePath") or &sysUtil::sysgen_die("[2.0]$strFilePath: file error!", __FILE__, __LINE__);
    PrintDependency($strFilePath);
    while (<CUSTOM_IMG_CONFIG_READ_H>) {
    next if (/^\s*\/\// || /^\s*\/\*/);
    if (/#define\s+(\w+)\s+\((\w*)\)/ || /#define\s+(\w+)\s+(\w*)/)
    {
        my $option = $1;
        my $value  = $2;
        next if (($option =~ /MAX_LENGTH_/) and ($value !~ /\(*0x\w+\)*/ or $value eq '0xFFFFFFFF' or (hex($value)==0)));  # skip dummy size definitions
        $Hash_ref->{$option} = $value;
    }
    }
    $FOTA_CONFIG{'CONFIG_FOTA_UE_FLASH_SPACE'} = $CONFIG_FOTA_UE_FLASH_SPACE;
    $FOTA_CONFIG{'CONFIG_FOTA_PACKAGE_BLOCK_NUMBER'} = $CONFIG_FOTA_PACKAGE_BLOCK_NUMBER;
    $FOTA_CONFIG{'CONFIG_FOTA_PACKAGE_AREA_SIZE'} = $CONFIG_FOTA_PACKAGE_AREA_SIZE;
    
    close CUSTOM_IMG_CONFIG_READ_H;
}

#****************************************************************************
# subroutine:  GenCUSTOM_SECURE_CONFIG_H: Generate custom_secure_config.h
# input:      $filepath : custom_secure_config.h path
# return:      x
# require:    tools/scatGenLib.pl -> scatGen_verno();
#****************************************************************************
sub GenCUSTOM_SECURE_CONFIG_H
{
    my ($strFilePath) = @_;
    open (CUSTOM_SECURE_CONFIG_H, ">$strFilePath") or &sysUtil::sysgen_die("[2.0]$strFilePath: file error!", __FILE__, __LINE__);
    PrintDependency($strFilePath);
    print CUSTOM_SECURE_CONFIG_H &sysUtil::copyright_file_header();
    require "tools/scatGenLib.pl";
    PrintDependModule();
    print CUSTOM_SECURE_CONFIG_H &sysUtil::description_file_header(    "custom_secure_config.h",
           "This Module defines SRD related setting.",
           "Kengchu Lin (mtk01866)     " . "system auto generator" . &scatGen_verno() . " + sysGenUtility" . &sysUtil::sysgenUtility_verno());
    print CUSTOM_SECURE_CONFIG_H &custom_secure_config_h_file_body();
    close CUSTOM_SECURE_CONFIG_H;

    print "$strFilePath is generated\n";
}

#****************************************************************************
# subroutine:  CUSTOM_IMG_CONFIG_H: Generate custom_img_config.h
# input:      $filepath : custom_img_config.h path
# return:      x
# require:    tools/scatGenLib.pl -> scatGen_verno();
#****************************************************************************
sub GenCUSTOM_IMG_CONFIG_H
{
    my ($strFilePath) = @_;
    open (CUSTOM_IMG_CONFIG_H, ">$strFilePath") or &sysUtil::sysgen_die("[2.0]$strFilePath: file error!", __FILE__, __LINE__);
    PrintDependency($strFilePath);
    print CUSTOM_IMG_CONFIG_H &sysUtil::copyright_file_header();
    require "tools/scatGenLib.pl";
    PrintDependModule();
    print CUSTOM_IMG_CONFIG_H &sysUtil::description_file_header(    "custom_img_config.h",
           "This Module defines the FOTA (Firmware Over the Air) related setting.",
           "Carlos Yeh (mtk02377)     " . "system auto generator" . &scatGen_verno(). " + sysGenUtility" . &sysUtil::sysgenUtility_verno());
    print CUSTOM_IMG_CONFIG_H &custom_img_config_h_file_body();
    close CUSTOM_IMG_CONFIG_H;

    print "$strFilePath is generated\n";
}

#****************************************************************************
# subroutine:  GenTS_MEM_CONFIG_H: Generate ts_mem_config.h
# input:      $filepath : ts_mem_config.h path
# return:      x
# require:    tools/scatGenLib.pl -> scatGen_verno();
#****************************************************************************
sub GenTS_MEM_CONFIG_H
{
    my ($strFilePath) = @_;
    open (TS_MEM_CONFIG_H, ">$strFilePath") or &sysUtil::sysgen_die("[2.0]$strFilePath: file error!", __FILE__, __LINE__);
    PrintDependency($strFilePath);
    print TS_MEM_CONFIG_H &sysUtil::copyright_file_header();
    require "tools/scatGenLib.pl";
    PrintDependModule();
    print TS_MEM_CONFIG_H &sysUtil::description_file_header(    "ts_mem_config.h",
           "This file defines custom component module configuration variables",
           "Yinli Liang(mtk54166)     " . "system auto generator " . &scatGen_verno(). " + sysGenUtility" . &sysUtil::sysgenUtility_verno());
    print TS_MEM_CONFIG_H &ts_mem_config_h_file_body();
    close TS_MEM_CONFIG_H;

    print "$strFilePath is generated\n";

}
