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

use File::stat;
use Math::BigInt;
#if ($#ARGV != 4) { &Usage; }

$file = $ARGV[0];
$verno_file = $ARGV[1];
$scatter_file = $ARGV[2];
$themf = $ARGV[3];
$symfile = $ARGV[4];
$bin_name = $ARGV[5];
$verno  = $ARGV[6];

(!-e "${file}") && die "${file} does NOT exist!\n";
(!-e "${verno_file}") && die "${verno_file} does NOT exist!\n";
(!-e "${scatter_file}") && die "${scatter_file} does NOT exist!\n";

die "$themf did NOT exist!\n" if (!-e $themf);

################################################
# Parse project makefile
################################################
open (FILE_HANDLE, "<$themf") or die "Cannot open makefile $themf\n";
while (<FILE_HANDLE>) {
  if (/^(\S+)\s*=\s*(\S+)/) {
    $keyname = lc($1);
    defined($${keyname}) && warn "$1 redefined in $themf!\n";
    $${keyname} = uc($2);
  }
}
close FILE_HANDLE;
################################################
# Parse .sym file to get g_BlSecInfo address
################################################
(open(LOGF, "<$symfile")) || die "$symfile can NOT been opened:$!\n";
$addr_secinfo = 0;
$img_bl_info_addr = 0;
$INT_Vectors = 0;
while(<LOGF>) {
  if (/^0x(\S+)\s+\S+\s+g_BlSecInfo$/) {
    $addr_secinfo = hex($1);
  }
  if (/^0x(\S+)\s+\S+\s+IMG_BL_INFO$/) {
    $img_bl_info_addr = hex($1);
  }
  if (/^0x(\S+)\s+\S+\s+INT_Vectors$/) {
    $INT_Vectors = hex($1);
  }
}
close LOGF;
################################################
# Main Flow
################################################
print "processing $file\n";
if($file =~ /BOOTLOADER.+ext\.bin/i) {
  &FillinBLinfo;
	&FilltoEXBLtail;     
} elsif ($file =~ /BOOTLOADER.+\.bin/i) { 
	&FillinSecInfo;
	&FilltoBLtail;
} else {
	die "$file is NOT for BOOTLOADER!!!\n";
}
print "processing $file DONE!!!\n";
exit 0;

sub FillinSecInfo {
	print "Fill in content of SecInfo for Secure platform only...\n";
  if (($secure_support eq "TRUE") || ($fota_enable eq "FOTA_DM") || ($ext_bl_update_support eq "TRUE")) {
  ##########################################
  # Set secure settings
  ##########################################
    if ($secure_support eq "TRUE") {
      $sec_support = 1;
      ($secure_version !~ /\d{1,4}/) && die "SECURE_VERSION: $secure_version should be a integer no longer than 4 digits!\n";
      ($secure_jtag_enable !~ /(TRUE|FALSE)/) && die "SECURE_JTAG_ENABLE: $secure_jtag_enable should be TRUE or FALSE!\n";
      $secure_jtag_enable = ($secure_jtag_enable =~ /TRUE/)? 1 : 0;
      (length($secure_custom_name) > 31) && die "SECURE_CUSTOM_NAME: $secure_custom_name should NOT exceed 31 bytes!\n";
    }
  } #End of if ($secure_support eq "TRUE")
  #exit 0 if $nand_flash_booting eq 'FALSE';

  $addr_secinfo=$addr_secinfo-$INT_Vectors;
  my %BBtbl_cfg = # Place the MCU list for bootloader configure might enabled
  (        'MT6225'  => 1,
           'MT6253T' => 1,
           'MT6253'  => 1,
           'MT6252H' => 1,
           'MT6252'  => 1,
           'MT6228'  => 1,
           'MT6229'  => 1,
           'MT6230'  => 1,
           'MT6235'  => 1,
           'MT6235B' => 1,
           'MT6236'  => 1,
           'MT6236B' => 1,
           'MT6921'  => 1,
           'MT6238'  => 1,
           'MT6239'  => 1,
  	 #--------------
           'MT6226'  => 1,
           'MT6227'  => 1,
           'MT6226M' => 1,
           'MT6226D' => 1,
           'MT6227D' => 1,
           'MT6223'  => 1,
           'MT6223P' => 1,
           'MT6268T' => 1,
           'MT6268A' => 1,
           'MT6268' => 1,
           'MT6270A' => 1,
           #--------------
           'MT6516' => 1,
  );
  die "Do not support rom_info_ver for PLATFORM=${platform}\n" unless defined $BBtbl_cfg{$platform};
  
  my %BBtbl_bloaderinfo = # Place the MCU list for bootloader configure might enabled
  (        'MT6225'  => "MTK_BLOADER_INFO_v02\0\0\0\0",
           'MT6253T' => "MTK_BLOADER_INFO_v02\0\0\0\0",
           'MT6253'  => "MTK_BLOADER_INFO_v02\0\0\0\0",
           'MT6252H' => "MTK_BLOADER_INFO_v02\0\0\0\0",         
           'MT6252'  => "MTK_BLOADER_INFO_v02\0\0\0\0",
           'MT6228'  => "MTK_BLOADER_INFO_v02\0\0\0\0",
           'MT6229'  => "MTK_BLOADER_INFO_v03\0\0\0\0",
           'MT6230'  => "MTK_BLOADER_INFO_v03\0\0\0\0",
           'MT6235'  => "MTK_BLOADER_INFO_v02\0\0\0\0",
           'MT6235B' => "MTK_BLOADER_INFO_v02\0\0\0\0",
           'MT6236'  => "MTK_BLOADER_INFO_v02\0\0\0\0",
           'MT6236B' => "MTK_BLOADER_INFO_v02\0\0\0\0",
           'MT6238'  => "MTK_BLOADER_INFO_v02\0\0\0\0",
           'MT6239'  => "MTK_BLOADER_INFO_v02\0\0\0\0",
           'MT6268A' => "MTK_BLOADER_INFO_v02\0\0\0\0",
           'MT6268'  => "MTK_BLOADER_INFO_v02\0\0\0\0",
           'MT6270A' => "MTK_BLOADER_INFO_v02\0\0\0\0",
           'MT6921'  => "MTK_BLOADER_INFO_v02\0\0\0\0",
           'MT6516'  => "MTK_BLOADER_INFO_v03\0\0\0\0",
  );
  
  $rom_info_ver = $BBtbl_bloaderinfo{$platform} or exit 0; # early exit and do-nothing
  
  
  if ($nand_flash_booting ne "NONE") {
  
  open (VERNO, "<${verno_file}") or die "cannot open verno file ${verno_file}\n";
  while (<VERNO>) {
    next if (/^\s*\/\//);
    if (/const\s+\S+\s+CHECKSUM_SEED\s+=\s+0x([0-9A-Fa-f]+)/) {
      (defined($checksum_seed)) && warn "checksum_seed redefined!";
      $checksum_seed = hex $1;
    } elsif (/const\s+\S+\s+BootLDVerno\[\d+\]\s+=\s+"(\S+)"/) {
      (defined($verno_str)) && warn "verno_str redefined!";
      $verno_str = $1;
    }
  }
  close VERNO;
  (!defined($checksum_seed)) && die "checksum_seed does NOT exist!";
  (!defined($verno_str)) && die "verno_str does NOT exist!";
  
  open (SCATTER, "<${scatter_file}") or die "cannot open the scatter file${scatter_file}\n";
  while (<SCATTER>) {
    next if (/^;/);
  
    if (/EXT_BOOTLOADER\s+0x([0-9A-Fa-f]+)/) {
      $start_addr = hex $1;
      last;
    }
  
    if (/READ_ONLY\s+0x([0-9A-Fa-f]+)/) {
      $start_addr = hex $1;
      last;
    }
  
  }
  close SCATTER;
  (!defined($start_addr)) && die "Start address does NOT exist!";
  
  } # End of if ($nand_flash_booting ne "NONE")
  #****************************************************************************
  # append information to MinBootloader bin file
  #****************************************************************************
  $totalLen = 0;
  
  if ($sec_support == 1) {
    open (FILE, "+<$file") or die "cannot open the bootloader bin file $file\n";
    binmode(FILE);
  
    seek(FILE, 0, 0);
    seek(FILE, $addr_secinfo+20, 0);
    print FILE pack("V1", $secure_jtag_enable);
    print FILE "$secure_custom_name";
    print FILE "\0" x (32 -length($secure_custom_name));
    seek(FILE, $addr_secinfo+60, 0);
    print FILE pack("V1", $secure_version);
    
    close FILE;
  }
  
  if ($nand_flash_booting ne "NONE") {
  open (FILE, ">>$file") or die "cannot open the bootloader bin file $file\n";
  binmode(FILE);
  
  print FILE $rom_info_ver;
  $totalLen += length $rom_info_ver;
  
  $binfilename = $file;
  $binfilename =~ s/.*\\//g;
  if (length ($binfilename) <= 64) {
    $binfilename .= "\0" x (64 - length ($binfilename));
  } else {
    ##die "Length of \"$binfilename\" is more than 64!!!";
    $binfilename =~ s/^(.{64}).*$/$1/;
    warn "$binfilename\n";
  }
  $totalLen += length $binfilename;
  
  my $emi_dummy = 0x0;
  
  print FILE $binfilename;
  print FILE $verno_str;
  print FILE pack("V1", $checksum_seed); #little endian
  print FILE pack("V1", $start_addr);
  print FILE pack("V1", $emi_dummy);
  print FILE pack("V1", $emi_dummy);
  ($rom_info_ver =~ /v03/i) && print FILE pack("V1", $emi_dummy);
  print FILE pack("V1", $emi_dummy);
  print FILE pack("V1", $emi_dummy);
  print FILE pack("V1", $emi_dummy);
  print FILE pack("V1", $emi_dummy);
  print FILE "MTK_BIN\0";
  $totalLen += 44;
  ($rom_info_ver =~ /v03/i) && ($totalLen += 4);
  print FILE pack("V1", $totalLen);
  
  close FILE;
  } # End of if ($nand_flash_booting ne "NONE")
  
}

sub FilltoBLtail {
  print "Append information to the tail of Bootloader...\n";

  #****************************************************************************
  # append information to MinBootloader bin file
  #****************************************************************************
  $totalLen = 0;
  
  open (FILE, ">>$file") or die "cannot open the bootloader bin file $file\n";
  binmode(FILE);
  
  print FILE $rom_info_ver;
  $totalLen += length $rom_info_ver;
  
  $binfilename = $file;
  $binfilename =~ s/.*\\//g;
  if (length ($binfilename) <= 64) {
    $binfilename .= "\0" x (64 - length ($binfilename));
  } else {
    ##die "Length of \"$binfilename\" is more than 64!!!";
    $binfilename =~ s/^(.{64}).*$/$1/;
    warn "$binfilename\n";
  }
  $totalLen += length $binfilename;
  
  print FILE $binfilename;
  print FILE $verno_str;
  print FILE pack("V1", $checksum_seed); #little endian
  print FILE pack("V1", $start_addr);
  print FILE pack("V1", $emi_gen_ctrl1);
  print FILE pack("V1", $emi_gen_ctrl2);
  ($rom_info_ver =~ /v03/i) && print FILE pack("V1", $emi_gen_ctrl3);
  print FILE pack("V1", $emi_dram_mode);
  print FILE pack("V1", $emi_dram_ext_mode);
  print FILE pack("V1", $emi_dram_ctrl);
  print FILE pack("V1", $emi_dram_refresh_ctrl);
  print FILE "MTK_BIN\0";
  $totalLen += 44;
  ($rom_info_ver =~ /v03/i) && ($totalLen += 4);
  print FILE pack("V1", $totalLen);
  close FILE;
	
}

sub FillinBLinfo {
	print "Fill in information for ExtBootloader...\n";
  #****************************************************************************
  # Get IMG_BL_INFO address
  #****************************************************************************

  $img_bl_info_addr = $img_bl_info_addr - $INT_Vectors if $img_bl_info_addr != 0;
  
  #****************************************************************************
  # append FOTA & EXT_BL_UPDATE information to the file
  #****************************************************************************
    if($img_bl_info_addr != 0) {
  		open (FILE, "+<$file") or die "cannot open the bootloader bin file $file\n";
      binmode(FILE);
      seek(FILE, $img_bl_info_addr, 0);
      read(FILE,$BUFFER,32);
  
      @buffer = split(//,$BUFFER);
      @buffer2 = reverse @buffer; #Convert to little-endian.
  
      $count = 0;
      $checksum1="";
      $checksum2="";
      $checksum="";
  
  #****************************************************************************
  # Calculate checksum of FOTA_ROM_INFO string
  #****************************************************************************
      foreach(@buffer2){
  	    if($count%4 < 3) {
  		    $checksum1 = $checksum1.unpack("H*",$_);
  	    }
  	    if($count%4 == 3) {
  		    $checksum2 = $checksum1.unpack("H*",$_);
  		    $checksum = eval($checksum+hex($checksum2));
          $checksum1=undef;
          $checksum2=undef;
  	    }
  	    $count++;
      }
  
      seek(FILE, $img_bl_info_addr+32, 0);
  #Ex. 1FD0A7058 -> FD0A7058
      $checksum=$checksum%(Math::BigInt->new('0x100000000'));
      print FILE pack("V1",$checksum);
  #****************************************************************************
  
      print FILE $bin_name;
      print FILE "\0" x (128 -length($bin_name));
      print FILE "$verno";
      print FILE "\0" x (64 -length($verno));
      seek(FILE, 4, 1); # Skip bl_verno.
  
  #***********************************************************************************
  # Get start address of boot loader (execution view) from the bootloader scatter file
  #***********************************************************************************
      seek(FILE, 4, 1); # Start address of boot loader (execution view)
  
  #****************************************************************************
  # Get size of boot loader image
  #****************************************************************************
      $rom_size = stat("$file")->size;
      print FILE pack("V1",$rom_size);
  #****************************************************************************
      seek(FILE, 4, 1); # Skip m_bl_max_length.
      
  #*********************************************
  #To calculate XOR value of the whole structure
  #For boot loader image infomation: initial key is  (0x35)
  #*********************************************
      $xorall = 0x35;
      seek(FILE, $img_bl_info_addr, 0);
      read(FILE,$BUFFER,244);
      @buffer = split(//,$BUFFER);
      foreach(@buffer){
      	$xorall = $xorall ^ ord($_);
      }
      print FILE pack("L",$xorall);
      close FILE; 
    }
}

sub FilltoEXBLtail {
	print "Append information to the tail of ExtBootloader...\n";
  #************************************************************
  # append IMG_TAIL_INFO to ExtBootloader bin file
  #************************************************************ 
    $Size_EXBL = stat("$file")->size;
    $IMG_UA_TAIL_INFO = 0;
    $EXBL_TAIL = "MTK_BL_ROMINFO_TAIL_V01";
    
    open (FILE, "+<$file") or die "cannot open $file\n";
    binmode(FILE);
  #  $currentPosition = tell(FILE);
    seek(FILE, 0, 2);
    $crcLength = tell(FILE);    
    print FILE $EXBL_TAIL;
    print FILE "\0" x (32 -length($EXBL_TAIL));
    seek(FILE, -32, 1);
    
    #Check sum of "MTK_BL_ROMINFO_TAIL_V01"
    read(FILE,$BUFFER,32);
    @buffer = split(//,$BUFFER);
    @buffer2 = reverse @buffer; #Convert to little-endian.
  
    $count = 0;
    $checksum1="";
    $checksum2="";
    $checksum="";
  
  #****************************************************************************
  # Calculate checksum of MTK_BL_ROMINFO_TAIL_V01 string
  #****************************************************************************
      foreach(@buffer2){
  	    if($count%4 < 3) {
  		    $checksum1 = $checksum1.unpack("H*",$_);
  	    }
  	    if($count%4 == 3) {
  		    $checksum2 = $checksum1.unpack("H*",$_);
  		    $checksum = eval($checksum+hex($checksum2));
          $checksum1=undef;
          $checksum2=undef;
  	    }
  	    $count++;
      }
  
      seek(FILE, 0, 2);
  #Ex. 1FD0A7058 -> FD0A7058
      $checksum=$checksum%(Math::BigInt->new('0x100000000'));
      print FILE pack("V1",$checksum);
  
  
  #****************************************************************************
  # Calculate checksum of EXBL_ROM_INFO string
  #****************************************************************************
      $ua_version = 1;
      print FILE pack("V1", $ua_version);
  
  #****************************************************************************
  # Write Size of ExtBootloader image
  #****************************************************************************
      print FILE pack("V1",$Size_EXBL);
  
  #****************************************************************************
  # Write length of ExtBootloader check area
  #****************************************************************************
  #    $currentPosition = tell(FILE);
      print FILE pack("V1",$Size_EXBL);
      $currentPosition = tell(FILE);
      printf "CRC calculate len : 0x%08X\n", $crcLength;
  
  #****************************************************************************
  # Write CRC of ExtBootloader image
  #****************************************************************************
      seek(FILE, 0, 0);
      
      my $read_length = 0;
      while ( $read_length < $crcLength )
      {
      	my $val;
      	sysread(FILE, $buffer, 1, 0);
  	    $val = ord($buffer);
  	    push @input_data_buffer, $val;
  	    $read_length++;
      }
      &Build_CRC_TBL;
      my $crc_result;
      $crc_result = &Update_CRC(@input_data_buffer);
      seek(FILE, $currentPosition, 0);
      print FILE pack("V1",$crc_result);
      printf "CRC VAL : 0x%08X\n", $crc_result;
  #****************************************************************************
  # Write XOR value of whole structure
  #****************************************************************************
      seek(FILE,-52, 1);
      read(FILE,$BUFFER,52);
      @buffer = split(//,$BUFFER);
      $xorall = 0x79;
      foreach(@buffer){
      	$xorall = $xorall ^ ord($_);
      }
      print FILE pack("L",$xorall);
      close (FILE);
  #****************************************************************************
}

sub Build_CRC_TBL
{
	my $n;
	my $k;
  my $c;
	foreach $n (0..255)
	{
		$c = $n;
		foreach $k (0..7)
		{
			if ($c & 0x1)
			{
				$c = 0xedb88320 ^ ( $c >> 1);
			}
			else
			{
				$c = $c >> 1;
			}
		}
		$crc_table[$n] = $c;
		#printf "TABLE [%d] : 0x%08x\n", $n , $c;
	}
}

sub Update_CRC
{
	# The input put as array @_
	my $c ;
  my $v;
	my $exbl_ua_crc_key = 288;
	$c = $exbl_ua_crc_key;
	foreach $v (@input_data_buffer)
	{
		my $index;
		#printf "Data : 0x%02x\t", $v;
		$index = ($c ^ $v) & 0xff;
		if (not defined $crc_table[ $index ] )
		{
			printf "TABLE index : %d not exists\n", $index;
			die "xx";
		}
		#$c = ( $crc_table[ ($c ^ $v) & 0xff ] ) ^ ($c >> 8);
		my $right_val = $c >> 8;
		$c = $crc_table[ $index ] ^ $right_val ;
		#printf "CRC : 0x%08x\n", $c;
	}
	return $c;
}

sub Usage {
  print "perl bl_append.pl <filename> <verno file> <scatter file> <makefile> <SYM file> <bin name> <verno>\n";
  exit 1;
}