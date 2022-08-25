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
#*   Append2.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This script can append some information to a file
#*   1. its file name
#*   2. input strings
#*   3. flash configuration information
#*   This script also can query flash configuration stored in FlashConf.c
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# Usage
#****************************************************************************
sub Usage
{
  print "perl append2.pl -h -d
               <symfile> <flash_cfg_file> <filename> <bin_name> <verno> <MAKEILE> <scatter file>
               <symfile> <flash_cfg_string> <filename> <bin_name> <verno> <MAKEILE>
               <flash_cfg_file> <scatter file>\n";
  exit(1);
}

use File::stat;
use File::Basename;
use Math::BigInt;

#****************************************************************************
# parsing command arguments
#****************************************************************************

$DebugPrint = 0;
$rom_info_ver = "MTK_ROMINFO_v09";
(length($rom_info_ver) != 15) && die "ROM_INFO_VER: $rom_info_ver should be 15 bytes!\n";
$file = "";
$bin_name = "";
$symFile = "";
$verno = "";
$FLASH_CFG = "";
$themf = "";
$query_mode = 0;
my $sec_support = 0;
my $needEMIInfo = 0;
my $regbase2;
while ($#ARGV != -1)
{
	if ($ARGV[0] =~ /-h/i)
	{
    &Usage;
	}
	elsif ($ARGV[0] =~ /-d/i)
	{
    $DebugPrint = 1;
	}
	elsif ($#ARGV == 2)
	{
    $FLASH_CFG = $ARGV[0];
    (!-e $FLASH_CFG) && die "$FLASH_CFG does NOT EXIST!\n";
    $memory_cfg = $ARGV[1];
    (!-e $memory_cfg) && die "$memory_cfg does NOT EXIST!\n";
    $themf = $ARGV[2];
    (!-e $themf) && die "$themf does NOT EXIST!\n";
    $query_mode = 1;
    last;
	}
	elsif ($#ARGV == 8)
	{
    $symFile = $ARGV[0];
    (!-e $symFile) && die "$symFile does NOT EXIST!\n";
    $FLASH_CFG = $ARGV[1];
    $file = $ARGV[2];
    $originalFile = $file;
    (!-e $file) && die "$file does NOT EXIST!\n";
    $bin_name = $ARGV[3];
    (length($bin_name) > 127) && die "BIN_NAME: $ARGV[3] should NOT exceed 127 bytes!\n";
    $verno = $ARGV[4];
    (length($verno) > 63) && die "VERNO: $ARGV[4] should NOT exceed 63 bytes!\n";
    $themf = $ARGV[5];
    (!-e $themf) && die "$themf does NOT EXIST!\n";
    $project = $ARGV[6];
    $build_time_str = $ARGV[7];
     $custom_secure_config_h = $ARGV[8]."\\custom_secure_config.h";
    (!-e $custom_secure_config_h) && die "$custom_secure_config_h does NOT EXIST!\n";
    last;
	}
	elsif ($#ARGV == 10)
	{
    $symFile = $ARGV[0];
    (!-e $symFile) && die "$symFile does NOT EXIST!\n";
    $FLASH_CFG = $ARGV[1];
    $file = $ARGV[2];
    $originalFile = $file;
    (!-e $file) && die "$file does NOT EXIST!\n";
    $bin_name = $ARGV[3];
    (length($bin_name) > 127) && die "BIN_NAME: $ARGV[3] should NOT exceed 127 bytes!\n";
    $verno = $ARGV[4];
    (length($verno) > 63) && die "VERNO: $ARGV[4] should NOT exceed 63 bytes!\n";
    $themf = $ARGV[5];
    (!-e $themf) && die "$themf does NOT EXIST!\n";
    $memory_cfg = $ARGV[6];
    $EMI_INFO = $ARGV[6];

		if ($memory_cfg !~ /\d.+/)
		{
      (!-e $memory_cfg) && die "$memory_cfg does NOT EXIST!\n";
    }
    $scat = $ARGV[7];
    (!-e $scat) && die "$scat does NOT EXIST!\n";
    $project = $ARGV[8];
    $build_time_str = $ARGV[9];
     $custom_secure_config_h = $ARGV[10]."\\custom_secure_config.h";
    (!-e $custom_secure_config_h) && die "$custom_secure_config_h does NOT EXIST!\n";
    last;
	}
	else
	{
    &Usage;
  }
  shift(@ARGV);
}

#if ($query_mode == 0) {
  open (FILE_HANDLE, "<$themf") or die "cannot open $themf\n";
while (<FILE_HANDLE>)
{
	if ((/^([^\#]*)\#?.*/) && ($1 =~ /^(\w+)\s*=\s*(.*\S)\s*$/))
	{
      $keyname = lc($1);
      defined($${keyname}) && warn "$1 redefined in $themf!\n";
      $${keyname} = uc($2);
    }
  }

if ($secure_support eq "TRUE")
{
    $sec_support = 1;
    ($secure_version !~ /\d{1,4}/) && die "SECURE_VERSION: $secure_version should be a integer no longer than 4 digits!\n";
    ($secure_jtag_enable !~ /(TRUE|FALSE)/) && die "SECURE_JTAG_ENABLE: $secure_jtag_enable should be TRUE or FALSE!\n";
    $secure_jtag_enable = ($secure_jtag_enable =~ /TRUE/)? 1 : 0;
    (length($secure_custom_name) > 31) && die "SECURE_CUSTOM_NAME: $secure_custom_name should NOT exceed 31 bytes!\n";
  }
    
my %BBtbl_EMI = (
      'MT6225'       => 1,
      'MT6253T'      => 1,
      'MT6253'       => 1,
      'MT6253E'      => 1,
      'MT6253L'      => 1,      
      'MT6228'       => 1,
      'MT6252'       => 1,
      'MT6252H'      => 1,
      'MT6229'       => 2,
      'MT6230'       => 2,
      'MT6235'       => 3,
      'MT6235B'      => 3,
      'MT6236'       => 3,
      'MT6236B'      => 3,
      'MT6238'       => 3,
      'MT6239'       => 3,
      'MT6268A'      => 3,
      'MT6268'       => 3,
      'MT6270A'      => 3,
      'MT6921'       => 3,
   );
  if (($nand_flash_booting ne "NONE") || (exists $BBtbl_EMI{$platform}))
  {
      open (CUSTOM_EMI_H, "<$memory_cfg") or die "cannot open $memory_cfg\n";
	$backup = $/;
	undef $/;
      $reading = <CUSTOM_EMI_H>;
      $/ = $backup;
      close CUSTOM_EMI_H;  #End of open (FLASH_CFG, "<$FLASH_CFG")
       
      if  ($reading =~ /\n\s*#define\s+DRAM_CS\s+/gs
       and $reading =~ /\n\s*#define\s+DRAM_SIZE\s+/gs)
      {
         $needEMIInfo = 1;
      }
  }

#}
#****************************************************************************
# parsing flash configuration from a file or a string
#****************************************************************************
my $full_hex_str = '';
my $full_emi_str; 

if ($FLASH_CFG =~ /flash_cfg_tmp\.c/i)
{
  open (FLASH_CFG, "<$FLASH_CFG") or die "cannot open $FLASH_CFG\n";

	$backup = $/;
	undef $/;
  $reading = <FLASH_CFG>;
  $/ = $backup;

  close FLASH_CFG;  #End of open (FLASH_CFG, "<$FLASH_CFG")

	my $flash_name  = '';              # part number
	my @NORFlashID  = (0, 0, 0, 0);    # flash ID (manufacture ID, device ID, ext. device ID1, ext. device ID2)
	my @NANDFlashID = (0, 0, 0, 0);    # flash ID (manufacture ID, device ID, ext. device ID1, ext. device ID2)
	my @EMMCFlashID = (0, 0, 0, 0);    # flash ID (manufacture ID, device ID, ext. device ID1, ext. device ID2)

  my $fs_nor_addr = 0;
  my $fs_nor_len = 0;
  my $fs_nand_addr = 0;
  my $fs_nand_len = 0;
  my $fs_emmc_addr = 0;
  my $fs_emmc_len = 0;
	my $hex_str = '';

	# get flash name(part number)
	if ($reading =~ /const\s+kal_char\s+PART_NUMBER\w+\[\d*\]\s*=\s*\"(.*)\"\s*;/)
	{
		$flash_name = $1;
		if ($bin_name !~ /\_FLN/)
		{    # there will be one more part number(NOR Flash with two and NAND with ONLY one)
			    # specified in custom memory device configuration file
			$bin_name .= "_FLN" . $flash_name;
			(length($bin_name) > 127) && die "PLATFORM ID: \"$bin_name\" should NOT exceed 127 bytes!\n";
		}
	}

	# get flash ID
	my @flashID = (0, 0, 0, 0);
  if ($reading =~ /const\s+kal_char\s+FLASH_ID\[\d*\]\s*=\s*\"\s*(?:\{\s*)?(\w+)\s*\,\s*(\w+)\s*(\,\s*(\w+))?\s*(\,\s*(\w+))?\s*(\,\s*(\w+))*\s*(?:\}\s*)?\"\s*;/)
	{           # Flash ID has four fields, manufacture ID, device ID, ext. device ID1 & ext. device ID2
		$flashID[0] = `perl -e "print ($1)" 2>&1` if ($1 ne "");
		$flashID[1] = `perl -e "print ($2)" 2>&1` if ($2 ne "");
		$flashID[2] = `perl -e "print ($4)" 2>&1` if ($4 ne "");
		$flashID[3] = `perl -e "print ($6)" 2>&1` if ($6 ne "");
	}

	if ($nand_flash_booting !~ /^NONE|FALSE$/)
	{
		@NANDFlashID = @flashID;
	}
	elsif ($emmc_booting !~ /^NONE|FALSE$/)
	{
		@EMMCFlashID = @flashID;	
	}
	else 
	{
		@NORFlashID = @flashID;
	}

  # get nor flash base address if device exists
  if ($reading =~ /int\s+fs_nor_base_address\s*=\s*(.*);/)
  {
  	 $fs_nor_addr = `perl -e "print ($1)" 2>&1`;
  }

  # get nor flash FAT space if device exists
  if ($reading =~ /int\s+fs_nor_length\s*=\s*(.*);/)
  {
  	 $fs_nor_len = `perl -e "print ($1)" 2>&1`;
  }

  # get nand flash base address if device exists
  if ($reading =~ /int\s+fs_nand_base_address\s*=\s*(.*);/)
  {
  	 $fs_nand_addr = `perl -e "print ($1)" 2>&1`;
  }

  # get nand flash FAT space if device exists
  if ($reading =~ /int\s+fs_nand_length\s*=\s*(.*);/)
  {
  	 $fs_nand_len = `perl -e "print ($1)" 2>&1`;
  }

  # get emmc flash base address if device exists
  if ($reading =~ /int\s+fs_emmc_base_address\s*=\s*(.*);/)
  {
  	 $fs_emmc_addr = `perl -e "print ($1)" 2>&1`;
  }

  # get emmc flash FAT space if device exists
  if ($reading =~ /int\s+fs_emmc_length\s*=\s*(.*);/)
  {
  	 $fs_emmc_len = `perl -e "print ($1)" 2>&1`;
  }

  $hex_str = sprintf("%02X", 3); # flash device num.
  $full_hex_str .= $hex_str;

	# 1st flash device info. --- NOR flash
	$hex_str = sprintf("%04X%04X%04X%04X%08X%08X", $NORFlashID[0], $NORFlashID[1], $NORFlashID[2], $NORFlashID[3], $fs_nor_addr, $fs_nor_len);
	$full_hex_str .= $hex_str;

	# 2nd flash device info. --- NAND flash
	$hex_str = sprintf("%04X%04X%04X%04X%08X%08X", $NANDFlashID[0], $NANDFlashID[1], $NANDFlashID[2], $NANDFlashID[3], $fs_nand_addr, $fs_nand_len);
  $full_hex_str .= $hex_str;
  
  # 3rd flash device info. --- eMMC flash
	$hex_str = sprintf("%04X%04X%04X%04X%08X%08X", $EMMCFlashID[0], $EMMCFlashID[1], $EMMCFlashID[2], $EMMCFlashID[3], $fs_emmc_addr, $fs_emmc_len);			
	$full_hex_str .= $hex_str;
}
elsif ($FLASH_CFG =~ /\.[ch]/i)
{
    die "Not Support $FLASH_CFG parsing Yet";
}
else
{
# parsing flash configuration from a string
    $full_hex_str = $FLASH_CFG;
    $full_emi_str = $EMI_INFO;
    if ((length($full_emi_str) == 0)
    && (($platform eq "MT6228") || ($platform eq "MT6229") || ($platform eq "MT6225") || ($platform eq "MT6253T") || ($platform eq "MT6253") || ($platform eq "MT6253E") || ($platform eq "MT6253L") || ($platform eq "MT6230") || ($platform eq "MT6252") || ($platform eq "MT6252H")))
    {
        die "Cannot get EMI_INFO.";
    }
    print "full_hex_str=$full_hex_str\n" if $DebugPrint == 1;
    
    print "[Flash Cfg 0] $FLASH_CFG\n" if $DebugPrint == 1;
}

######################################
#Get register values from custom_MEI.h
######################################
## Check DRAM setting in custom_EMI.h 

#if ($needEMIInfo == 1 and not defined $full_emi_str)
#{
#     $full_emi_str = getRegisterAddress($platform, $memory_cfg);
#}
#elsif (not defined $full_emi_str)
#{
#     $full_emi_str = '';
#}

##################################################################################################################
    
######################################
# Binary String 
######################################
$flash_len = length($full_hex_str);
if ( ($flash_len == 2)
  || ((($flash_len-34)%32) !=0)
  || ($flash_len > 34+5*32) )
{
    die "The length of $full_hex_str ($flash_len) should be 34+32n. (5>=n>=0)\n";
}
$flash_device_count = hex(substr($full_hex_str, 0, 2));

if ((($flash_len-2)/32) != $flash_device_count)
{
    die "($flash_len-2)/32 should be $flash_device_count\n";
}


#****************************************************************************
# in query, output @cfg_list with hex string
#****************************************************************************
if ($query_mode == 1)
{
  print "FLASH_CFG = $full_hex_str\n";
  print "EMI_INFO = $full_emi_str\n";
  exit(0);
}

#****************************************************************************
# Parse symbol file
#****************************************************************************
(open(LOGF, "<$symFile")) || die "$symFile can NOT been opened\n";
my %SYM_TBL = (
      'g_maui_gfh'       => undef,
      'INT_Vectors'      => undef,
      'IMG_INFO'         => undef,
      'IMG_FOTA_INFO'    => undef,
      'EMI_INFO'         => undef,
      'g_CustParaCfg'    => undef,
      'g_secinfo'        => undef,
      'g_secinfo_tail'   => undef,
      'g_bl_maui_paired_ver'   => undef,
   );

my %SYM_LEN = ('g_CustParaCfg' => undef,);

my $prev_symbol;

my $nand_fdm_dal_ver = "";

while(<LOGF>)
{

   # 0x00000000 A INT_Vectors
   if (/^0x(\S+)\s+\w\s+(\S+)$/)
   {
      if (exists $SYM_TBL{$2})
      {
         $SYM_TBL{$2} = hex($1);
      }
      

      if (exists $SYM_LEN{$prev_symbol})
      {
         $SYM_LEN{$prev_symbol} = hex($1) - $SYM_TBL{$prev_symbol};
      }
      $prev_symbol = $2;
   }
}
close(LOGF);

#****************************************************************************
#  For SDS Range Check
#****************************************************************************
(open(FILE, "<$custom_secure_config_h")) || die "$custom_secure_config_h can NOT been opened\n";
while(<FILE>)
{
  if (/^#define\s+SDS_START_ADDR\s+(.+)\s*/) {
    $sds_start_add = hex($1);
  }
  if (/^#define\s+SDS_TOTAL_SIZE\s+(.+)\s*/) {
    $sds_total_size = hex($1);
  }
}
close FILE;

#****************************************************************************
# Validation symbol and feature combination
#****************************************************************************
die "Could not find IMG_INFO in $symFile\n" unless defined $SYM_TBL{'IMG_INFO'};

#****************************************************************************
# Setup BINARY File Offset
#****************************************************************************
my %ROM_POS = (
      'IMG_INFO'         => undef,
      'IMG_FOTA_INFO'    => undef,
      'EMI_INFO'         => undef,
      'g_CustParaCfg'    => undef,
      'g_secinfo'        => undef,
      'g_secinfo_tail'   => undef,
      'g_bl_maui_paired_ver'   => undef,
   );

if (defined($SYM_TBL{'g_maui_gfh'}))
{
	map { $ROM_POS{$_} = $SYM_TBL{$_} - $SYM_TBL{'g_maui_gfh'} if defined($SYM_TBL{$_}); } keys %ROM_POS;
}
else
{
	map { $ROM_POS{$_} = $SYM_TBL{$_} - $SYM_TBL{'INT_Vectors'} if defined($SYM_TBL{$_}); } keys %ROM_POS;
}


#****************************************************************************
# set ROMINFO version
#****************************************************************************
if ((($system_drive_on_nand eq "TRUE") && ($nand_flash_booting eq "NONE")) || ($fota_enable eq "FOTA_FULL"))
{
        $rom_info_ver = "MTK_ROMINFO_v09";
}

#****************************************************************************
# append information to the file
#****************************************************************************
open (FILE, "+<$file") or die "cannot open $file\n";
binmode(FILE);

seek(FILE, $ROM_POS{'IMG_INFO'}, 0);

    seek(FILE, 16, 1);


    print FILE "$bin_name";
    print FILE "\0" x (128 -length($bin_name));
    print FILE "$verno";
    print FILE "\0" x (64 -length($verno));

#if ($FLASH_CFG =~ /custom_MemoryDevice\.h/i)
if ($nand_flash_booting !~ /^NONE|FALSE$/)
{
    print FILE pack("H4", "ffff");
}
else
{
    print FILE pack("H4", "0000");
}

    $flash_len = length($full_hex_str);

if (defined $SYM_TBL{'g_maui_gfh'})  #For SV5 platform.
{
  open (CFG,">.\\make\\~gfh_cfg_flash.tmp") or die "$!";
  print CFG "FLASH_DEV_CNT=$flash_device_count\n";

  for ($i=0; $i<$flash_device_count; $i++)
  {
    $menuID = hex(substr($full_hex_str, 2+32*$i, 4));
    $devID = hex(substr($full_hex_str, 6+32*$i, 4));
    $extID1 = hex(substr($full_hex_str, 10+32*$i, 4));
    $extID2 = hex(substr($full_hex_str, 14+32*$i, 4));
    $fatAddr = hex(substr($full_hex_str, 18+32*$i, 8));
    $fatLen = hex(substr($full_hex_str, 26+32*$i, 8));
    
    $regbase2 .= sprintf("0x%04X", $devID);
    $regbase2 .= sprintf("%04X"  , $menuID).",";
    $regbase2 .= sprintf("0x%04X", $extID2);
    $regbase2 .= sprintf("%04X"  , $extID1).",";
    $regbase2 .= sprintf("0x%08X", $fatAddr).",";
    $regbase2 .= sprintf("0x%08X", $fatLen).",";     
 }
  print CFG "FLASH_CFG_STR =".$regbase2."\n";
  close CFG;
}
else
{
  print FILE pack("v1", $flash_device_count);

  for ($i=0; $i<$flash_device_count; $i++)
  {
    $menuID = hex(substr($full_hex_str, 2+32*$i, 4));
    $devID = hex(substr($full_hex_str, 6+32*$i, 4));
    $extID1 = hex(substr($full_hex_str, 10+32*$i, 4));
    $extID2 = hex(substr($full_hex_str, 14+32*$i, 4));
    $fatAddr = hex(substr($full_hex_str, 18+32*$i, 8));
    $fatLen = hex(substr($full_hex_str, 26+32*$i, 8));
    print FILE pack("v1", $menuID);
    print FILE pack("v1", $devID);
    print FILE pack("v1", $extID1);
    print FILE pack("v1", $extID2);
    print FILE pack("V1", $fatAddr);
    print FILE pack("V1", $fatLen);
  }
}

if ($cust_para_support eq "TRUE")
{
    seek(FILE, 12+(6-$flash_device_count)*16, 1);
    print FILE pack("V1", $SYM_TBL{'g_CustParaCfg'});
    print FILE pack("V1", $SYM_LEN{'g_CustParaCfg'});
}

if ($sec_support == 1 and !defined $SYM_TBL{'g_maui_gfh'}) # For non-SV5 platform
{
  die "Could not find g_secinfo in $symFile\n" unless defined $SYM_TBL{'g_secinfo'};

  #Parse scatter file to get SECINFO_TAIL address.
  open(scat,"$scat") || die "Cannot open $sact. Error:$!\n";
  my $line = 0;
  my $rom_base = "";
  my $rom_line = 0;
  my $secondary_rom_base = "0";
  my $secondary_rom_line = 0;
  my $third_rom_base = "0";
  my $third_rom_line = 0;
  my $secinfo_tail_line = 0;
  my $secinfo_tail_base = "0";
  my $multiROM = "";
	while (<scat>)
	{
    $line++;

		if (index($_, "ROM") == 0)
		{
      $rom_line = $line;
			if ($_ =~ /[\w]+[\s](.+?)[\s]/ && $1 ne "+0x0")
			{
        $rom_base = $1;

        # Get ROM binary length.
				if ($file =~ /(.+)\\ROM/)
				{
          $bin_path = $1;
          $rom_length = get_length($file);
        }
      }
		}
		elsif (index($_, "SECONDARY_ROM") == 0)
		{
      $secondary_rom_line = $line;
			if ($_ =~ /[\w]+[\s](.+?)[\s]/)
			{
        $secondary_rom_base = $1;
				if ($secondary_rom_base =~ /\+(.+)/)
				{
          $secondary_rom_offset = hex $1;
          $secondary_rom_base = $rom_length + $secondary_rom_offset;
          $secondary_rom_length = get_length("$bin_path\\SECONDARY_ROM");
        }
      }
		}
		elsif (index($_, "THIRD_ROM") == 0)
		{
      $third_rom_line = $line;
			if ($_ =~ /[\w]+[\s](.+?)[\s]/)
			{
        $third_rom_base = $1;
				if ($third_rom_base =~ /\+(.+)/)
				{
          $third_rom_offset = $1;
          $third_rom_base = $secondary_rom_length + $third_rom_offset;
        }
      }
		}
		elsif ($_ =~ /^[a-zA-Z].+/)
		{
      $third_rom_line = $line;
			if ($_ =~ /[\w]+[\s](.+?)[\s]/)
			{
        $third_rom_base = $1;
				if ($third_rom_base =~ /\+(.+)/)
				{
          $third_rom_offset = $1;
          $third_rom_base = $secondary_rom_length + $third_rom_offset;
        }
      }
		}
		elsif (index($_, "SECINFO_TAIL") >= 0)
		{
      $secinfo_tail_line = $line;
    }
  }
  close(scat);

	if ($third_rom_line < $secondary_rom_line)
	{
    $third_rom_line = 0;
  }

	if ($secondary_rom_line == 0)
	{
    $secinfo_tail_base = $rom_base;
	}
	elsif ($secondary_rom_line > $secinfo_tail_line)
	{    #SECINFO_TAIL locates at ROM
    $secinfo_tail_base = $rom_base;
	}
	elsif (($secinfo_tail_line > $secondary_rom_line) && ($third_rom_line == 0))
	{    #SECINFO_TAIL locates at SECONDARY_ROM and no THIRD_ROM exits.
    $secinfo_tail_base = $secondary_rom_base;
    $multiROM = "SECONDARY";
	}
	elsif (($secinfo_tail_line > $secondary_rom_line) && ($third_rom_line > $secinfo_tail_line))
	{    #SECINFO_TAIL locates at SECONDARY_ROM
    $secinfo_tail_base = $secondary_rom_base;
    $multiROM = "SECONDARY";
	}
	elsif (($secinfo_tail_line > $third_rom_line) && (third_rom_line != "0"))
	{    #SECINFO_TAIL locates at THIRD_ROM
    $secinfo_tail_base = $third_rom_base;
    $multiROM = "THIRD";
  }

#************************************************************
#Start to write secinfo to ROM
#************************************************************	
    seek(FILE, $ROM_POS{'g_secinfo'} + 20, 0);
    print FILE pack("V1", $secure_jtag_enable);
    print FILE "$secure_custom_name";
    print FILE "\0" x (32 -length($secure_custom_name));
    seek(FILE, $ROM_POS{'g_secinfo'} + 60, 0);
    print FILE pack("V1", $secure_version);
    
	if ($secinfo_tail_base =~ /0x/i)
	{
      $secinfo_tail_base = hex($secinfo_tail_base);
    }

    # Verify the address of g_secinfo_tail
    seek(FILE, $ROM_POS{'g_secinfo'} + 80, 0);
    my $addr_secinfo_tail;
    die "cannot read $file\n" unless (my $chnum = (read FILE, $addr_secinfo_tail, 4));
    $addr_secinfo_tail = unpack ("V1",$addr_secinfo_tail);
    die "secinfo tail don't match\n" if ($SYM_TBL{'g_secinfo_tail'} != $addr_secinfo_tail);
        
	if (length($multiROM) > 0)
	{
		if ($multiROM eq "SECONDARY")
		{
        $file =~ s/ROM/SECONDARY_ROM/;
        open(multiFILE,"+<$file") || die "Cannot open $file. Error:$!\b";
		}
		elsif ($multiROM eq "THIRD")
		{
        $file =~ s/ROM/THIRD_ROM/;
        open(multiFILE,"$file") || die "Cannot open $file. Error:$!\b";
      }

#      $addr_secinfo_tail = $ROM_POS{'g_secinfo_tail'} % 0x08000000;
      $addr_secinfo_tail = $ROM_POS{'g_secinfo_tail'};
      $addr_secinfo_tail = $addr_secinfo_tail - $secinfo_tail_base;
      seek(multiFILE, $addr_secinfo_tail+20, 0);
      print multiFILE pack("V1", $secure_jtag_enable);
      print multiFILE "$secure_custom_name";
      print multiFILE "\0" x (32 -length($secure_custom_name));
      seek(multiFILE, $addr_secinfo_tail+60, 0);
      print multiFILE pack("V1", $secure_version);
      close(multiFILE);
	}
	else
	{
      $addr_secinfo_tail = unpack ("V1",$addr_secinfo_tail) % 0x08000000;

      seek(FILE, $ROM_POS{'g_secinfo_tail'} + 20, 0);    
      print FILE pack("V1", $secure_jtag_enable);
      print FILE "$secure_custom_name";
      print FILE "\0" x (32 -length($secure_custom_name));
      seek(FILE, $ROM_POS{'g_secinfo_tail'} + 60, 0);
      print FILE pack("V1", $secure_version);
    }
}

if ($rom_info_ver eq "MTK_ROMINFO_v09")
{
    $cust_para_addr = hex(0);
    $cust_para_len = hex(0);
    $bit_ctrl = hex(0);
    
    if ($cust_para_support eq "TRUE")
    {
      $cust_para_addr = $SYM_TBL{'g_CustParaCfg'};
      $cust_para_len = $SYM_LEN{'g_CustParaCfg'};
    }

    #Read the bit_ctrl first then OR needed bit
    seek(FILE, $ROM_POS{'IMG_INFO'} + 328, 0);
    (read FILE, $bit_ctrl, 4);
    $bit_ctrl=unpack("V1",$bit_ctrl);
    
    if (($system_drive_on_nand eq "TRUE") && ($nand_flash_booting eq "NONE"))
    {
            $bit_ctrl = $bit_ctrl | 0x00000002;
    }
    
    if ($fota_enable eq "FOTA_FULL")
    {
            $bit_ctrl = $bit_ctrl | 0x00000004;
    }

    if ($fota_enable eq "FOTA_DM")
    {
            $bit_ctrl = $bit_ctrl | 0x00000010;
    }

    if ($multiple_binary_files eq "TRUE")
    {
            $bit_ctrl = $bit_ctrl | 0x00000020;
    }

    seek(FILE, $ROM_POS{'IMG_INFO'} + 320, 0);
    print FILE pack("V1", $cust_para_addr);
      
    seek(FILE, $ROM_POS{'IMG_INFO'} + 324, 0);
    print FILE pack("V1", $cust_para_len);
  
    seek(FILE, $ROM_POS{'IMG_INFO'} + 328, 0);
    print FILE pack("V1", $bit_ctrl);

    if ($nand_fdm_dal_ver ne "")
    {
        seek(FILE, $ROM_POS{'IMG_INFO'} + 332, 0);
        print FILE "$nand_fdm_dal_ver";
    }

    #Read the g_bl_maui_paired_ver value.
    seek(FILE, $ROM_POS{'g_bl_maui_paired_ver'}, 0);
    (read FILE, $paired_ver, 4);
    $paired_ver=unpack("V1",$paired_ver);
    seek(FILE, $ROM_POS{'IMG_INFO'} + 344, 0);
    print FILE pack("V1", $paired_ver);

    #Set bit to be 1 when the following condition is satisified.
    #bit0: if SECURE_SUPPORT is TRUE
    #bit1: if FOTA_ENABLE is FOTA_DM
    #bit2: if MT6268T
    #bit3: if USB_DOWNLOAD_IN_BL is NORMAL or SECURE
    
    #Read the bit_ctrl first then OR needed bit
    seek(FILE, $ROM_POS{'IMG_INFO'} + 348, 0);
    (read FILE, $f_combination, 4);
    $f_combination=unpack("V1",$f_combination);
    
    if ($secure_support eq "TRUE")
    {
        $f_combination = $f_combination | 0x00000001;
    }
    if ($fota_enable eq "FOTA_DM")
    {
        $f_combination = $f_combination | 0x00000002;
    }
    if ($platform eq "MT6268T")
    {
        $f_combination = $f_combination | 0x00000004;
    }
    if (($usb_download_in_bl eq "NORMAL") || ($usb_download_in_bl eq "SECURE"))
    {
        $f_combination = $f_combination | 0x00000008;
    }
    if (($sw_binding_support eq "BIND_TO_CHIP") or ($sw_binding_support eq "BIND_TO_KEY") or ($sw_binding_support eq "BIND_TO_CHIP_AND_KEY"))
    {
        $f_combination = $f_combination | 0x00000010;
    }
    
    if ($fast_logo_support eq "TRUE")
    {
        $f_combination = $f_combination | 0x00000800;
    }
    
    seek(FILE, $ROM_POS{'IMG_INFO'} + 348, 0);
    print FILE pack("V1", $f_combination);
    
    seek(FILE, $ROM_POS{'IMG_INFO'} + 356, 0);
    print FILE pack("V1", $sds_start_add);
    seek(FILE, $ROM_POS{'IMG_INFO'} + 360, 0);
    print FILE pack("V1", $sds_total_size);
}

#************************************************************
#Start to write DA version num to ROM
#************************************************************

seek(FILE, $ROM_POS{'g_secinfo'} + 16, 0);
read(FILE, $version, 4);
$version = unpack("H*",$version);

if ($version eq "05000000") # only for v5		
{
	if ((defined $secure_da_version_limit) && (defined $secure_da_version_limit_cust) && ($secure_da_version_limit ne "NONE") && ($secure_da_version_limit_cust ne "NONE") && ($secure_da_version_limit ne 0) && ($secure_da_version_limit_cust ne 0))
	{
		seek(FILE, $ROM_POS{'g_secinfo'} + 92, 0);
		$secure_da_version_limit = sprintf("%08s",$secure_da_version_limit);
		my $temp1 = substr ($secure_da_version_limit, 6, 2);
		my $temp2 = substr ($secure_da_version_limit, 4, 2);
		my $temp3 = substr ($secure_da_version_limit, 2, 2);
		my $temp4 = substr ($secure_da_version_limit, 0, 2);
		$secure_da_version_limit_cust = sprintf("%08s",$secure_da_version_limit_cust);
		my $temp5 = substr ($secure_da_version_limit_cust, 6, 2);
		my $temp6 = substr ($secure_da_version_limit_cust, 4, 2);
		my $temp7 = substr ($secure_da_version_limit_cust, 2, 2);
		my $temp8 = substr ($secure_da_version_limit_cust, 0, 2);		
		$tempX = $temp1 . $temp2 . $temp3 . $temp4 . $temp5 . $temp6 . $temp7 . $temp8;
		print FILE pack("H*", $tempX);

	}
	elsif ((defined $secure_da_version_limit) && (defined $secure_da_version_limit_cust) && (($secure_da_version_limit eq "NONE") || ($secure_da_version_limit_cust eq "NONE") || ($secure_da_version_limit eq 0) || ($secure_da_version_limit_cust eq 0)))
	{
		seek(FILE, $ROM_POS{'g_secinfo'} + 92, 0);
		print FILE pack("H*", "ffffffffffffffff");		
	}		
}
close FILE;

#************************************************************
#Start to write IMG_FOTA_INFO to BIN file for FOTA
#************************************************************
if (defined $fota_enable)
{
	if ($fota_enable ne "NONE")
	{

    $IMG_FOTA_INFO = $ROM_POS{'IMG_FOTA_INFO'};
    
    (!defined($IMG_FOTA_INFO)) && die "IMG_FOTA_INFO address does NOT exist!";
    
    open (FILE, "+<$originalFile") or die "10 cannot open $originalFile\n"; 
    binmode(FILE);
    seek(FILE, $IMG_FOTA_INFO, 0);
    read(FILE,$BUFFER,32);
    @buffer = split(//,$BUFFER);
    @buffer2 = reverse @buffer; #Convert to little-endian.

    $count = 0;
    $checksum1="";
    $checksum2="";
    $checksum="";

#*********************************************************************************
# Calculate checksum of IMG_FOTA_INFO string (Check sum of "MTK_FOTA_ROMINFO_V01")
#*********************************************************************************
    foreach (@buffer2)
    {
      if ($count % 4 < 3)
      {
        $checksum1 = $checksum1.unpack("H*",$_);
      }
      if ($count % 4 == 3)
      {
        $checksum2 = $checksum1.unpack("H*",$_);
        $checksum = eval($checksum+hex($checksum2));
        $checksum1=undef;
        $checksum2=undef;
      }
      $count++;
    }

    seek(FILE, $IMG_FOTA_INFO+32, 0);

#Ex. 1FD0A7058 -> FD0A7058
    $checksum=$checksum%(Math::BigInt->new('0x100000000'));
    print FILE pack("V1",$checksum);

#****************************************************************************
# Write Platform ID and Project ID
#****************************************************************************
    print FILE "$bin_name";
    print FILE "\0" x (128 -length($bin_name));
    print FILE "$verno";
    print FILE "\0" x (64 -length($verno));

#****************************************************************************
# Get array numbers
#****************************************************************************
    $MAX_ARRAY_NUM=10; # This value was defined by the developer.
    read(FILE,$fota_version,4);
    $fota_version=unpack("V1",$fota_version);

#    seek(FILE, 4, 1); # Jump over fota_version "0x01" or "0x02" value which was defined by the developer.
    read(FILE,$array_num,4);

#****************************************************************************
# Write file size of each ROM image
#****************************************************************************
    $dir=dirname($file);

open (SCAT_HANDLE, "<$scat") or die "11 cannot open $scat\n";
$rom_num=0;
		while (<SCAT_HANDLE>)
		{
			if (/([^\{\}].+?)\s+/)
			{
				if ((!/^_/) && (!/BOOTLOADER/i) && (!/FOTA/i) && (!/DSP_BL/i))
				{
      $ROM{$rom_num}=$1;
      next;
  }
  }
			if ((/^{/) && (defined $ROM{$rom_num}))
			{
    print "ROM=".$ROM{$rom_num}."\n";
    $rom_num++;
			}
			else
			{
    undef $ROM{$rom_num};
  }
}
close (SCAT_HANDLE);

		if ($rom_num == 1)
		{
  $rom_name = $originalFile;
  $rom_size = stat("$rom_name")->size;
  seek(FILE, 8, 1);
  print FILE pack("V1",$rom_size);
		}
		else
		{
			for ($i = 0 ; $i <= $rom_num - 1 ; $i++)
			{
    $rom_name = $ROM{$i};
    $rom_size = stat("$dir\\$rom_name")->size;
    seek(FILE, 8, 1);
    print FILE pack("V1",$rom_size);
  }
}

#****************************************************************************
# Write XOR value of whole structure
# For image information: initial key is (0x86)
#****************************************************************************
    $xorall = 0x86;
    seek(FILE, $IMG_FOTA_INFO, 0);

    #$structSize = 252 + 12*$regionNo;
		if ($fota_version eq 1)
		{
        $structSize = 252 + 12*$MAX_ARRAY_NUM;
		}
		elsif ($fota_version eq 2)
		{

    	#V2 structure added one m_fota_reserved_size (4 bytes)
    	$structSize = 256 + 12*$MAX_ARRAY_NUM;
		}
		else
		{
    	$structSize = 252 + 12*$MAX_ARRAY_NUM;
    }
    read(FILE,$BUFFER,$structSize); #這裡需要知道上一個FOTA image總共佔用幾個bytes
    @buffer = split(//,$BUFFER);
        
		foreach (@buffer)
		{
    	$xorall = $xorall ^ ord($_);
    }
    print FILE pack("L",$xorall);
    
    close (FILE);

#****************************************************************************
  }
}

#************************************************************
#Start to write infomation to BIN file for MODEM
#************************************************************
#MODEM mechanism
if ($smart_phone_core eq "ANDROID_MODEM")
{
	my $structure_size = 188;
	my $check_header_str = "CHECK_HEADER";
	my $header_version = "01";
	open (FILE, "+<$file") or die "cannot open $file\n";
  binmode(FILE);
  seek(FILE, 0, 2);
  print FILE "$check_header_str";
  print FILE "\0" x (12 -length($bin_name));

  print FILE pack("V1",$header_version);
  
  #Debug/Release mode check
  #0x1: debug mode
  #0x2: release mode
  if($production_release eq "TRUE") {
  	print FILE pack("V1",2);
  } elsif($production_release eq "FALSE") {
  	print FILE pack("V1",1);
  } else {
  	print FILE pack("V1",0);
  }
  
  #2G/3G check
  #0x1: 2G
  #0x2: 3G
  if(($l1_wcdma eq "TRUE") || ($l1_tdd128 eq "TRUE")) {
  	print FILE pack("V1",2);
  } else {
  	print FILE pack("V1",1);
  }
  
  my $plat_chip_info = $platform."_".$chip_ver;
  print FILE "$plat_chip_info";
  print FILE "\0" x (16 -length($plat_chip_info));
  print FILE "$build_time_str";
  print FILE "\0" x (64 -length($build_time_str));
  
 
  
  if($verno =~ /(.+W\d\d\.\d\d).*/) {
  	 $build_verno = $1;
  }
  print FILE "$build_verno";
  print FILE "\0" x (64 -length($build_verno));
  
  seek(FILE, 16, 1);
  print FILE pack("V1",$structure_size);
  
}

exit 0;

#******************************************************************************
# FUNCTION
#  get_length
# DESCRIPTION
#  xxx
# PARAMETERS
#  binary path
# RETURNS
#  binary length
#******************************************************************************

sub get_length()
{
  ($path) = @_;
  $rom_size = stat("$path")->size;
  return $rom_size;
}
