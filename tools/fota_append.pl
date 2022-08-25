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
#*   fota_append.pl
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
sub Usage {
  print "perl fota_append.pl -h -d
               <symfile> <bin_name> <verno> <MAKEILE> <scatter file> <fota_bin>\n";
  exit(1);
}

#****************************************************************************
# Initialize CRC
#****************************************************************************
use Archive::Zip;
use FileHandle;
use File::stat;
use Fcntl;
use Math::BigInt;

#****************************************************************************
# parsing command arguments
#****************************************************************************
$DebugPrint = 0;
$bin_name = "";
$symFile = "";
$verno = "";
$themf = "";
$scat = "";

while ($#ARGV != -1) {
  if ($ARGV[0] =~ /-h/i) {
    &Usage;
  } elsif ($ARGV[0] =~ /-d/i) {
    $DebugPrint = 1;
  } elsif ($#ARGV == 5) {
    $symFile = $ARGV[0];
    (!-e $symFile) && die "$symFile does NOT EXIST!\n";
    $bin_name = $ARGV[1];
    (length($bin_name) > 127) && die "BIN_NAME: $ARGV[1] should NOT exceed 127 bytes!\n";
    $verno = $ARGV[2];
    (length($verno) > 63) && die "VERNO: $ARGV[2] should NOT exceed 63 bytes!\n";
    $themf = $ARGV[3];
    (!-e $themf) && die "$themf does NOT EXIST!\n";
    $scat = $ARGV[4];
    (!-e $scat) && die "$scat does NOT EXIST!\n";
    $fota_bin = $ARGV[5];
    (!-e $fota_bin) && die "$fota_bin does NOT EXIST!\n";
    last;
  } else {
    &Usage;
  }
  shift(@ARGV);
}

open (FILE_HANDLE, "<$themf") or die "cannot open $themf\n";
while (<FILE_HANDLE>) {
  if (/^(\S+)\s*=\s*(\S+)/) {
    $keyname = lc($1);
    defined($${keyname}) && warn "$1 redefined in $themf!\n";
    $${keyname} = uc($2);
  }
}
close (FILE_HANDLE);

#************************************************************
#Start to write IMG_UA_HEAD_INFO for FOTA
#************************************************************
if (defined $fota_enable) {
  if ($fota_enable ne "NONE") { 

    $IMG_UA_HEAD_INFO = 0;
    $BaseAddr = 0;
    $SV5 = 0;
    open (SYM, "<${symFile}") or die "cannot open ${symFile}\n";
    while (<SYM>) {
      if (/^0x(\S+)\s+\S+\s+IMG_UA_HEAD_INFO$/) {
        $IMG_UA_HEAD_INFO = hex($1);
      }
      if ($BaseAddr==0 && /^0x(\S+)\s+\S+\s+g_fue_gfh$/) {
        $BaseAddr = hex($1);
        $SV5 = 1;
      }
      if ($BaseAddr==0 && /^0x(\S+)\s+\S+\s+INT_Vectors$/) {
        $BaseAddr = hex($1);
      }
    }
    close (SYM);
    $IMG_UA_HEAD_INFO=$IMG_UA_HEAD_INFO-$BaseAddr;
    
    (!defined($IMG_UA_HEAD_INFO)) && die "IMG_UA_HEAD_INFO address does NOT exist!";

    open (FILE, "+<$fota_bin") or die "cannot open $fota_bin\n";
    binmode(FILE);
    seek(FILE, $IMG_UA_HEAD_INFO, 0);
    
    #Check sum of "MTK_UA_ROMINFO_HEAD_V01"
    read(FILE,$BUFFER,32);
    @buffer = split(//,$BUFFER);
    @buffer2 = reverse @buffer; #Convert to little-endian.

    $count = 0;
    $checksum1="";
    $checksum2="";
    $checksum="";

#****************************************************************************
# Calculate checksum of MTK_UA_ROMINFO_HEAD_V01 string
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

    seek(FILE, $IMG_UA_HEAD_INFO+32, 0);

#Ex. 1FD0A7058 -> FD0A7058
    $checksum=$checksum%(Math::BigInt->new('0x100000000'));
    print FILE pack("V1",$checksum);

#****************************************************************************
# Write Platform ID and Project ID
#****************************************************************************
    print FILE $bin_name;
    print FILE "\0" x (128 -length($bin_name));
    print FILE "$verno";
    print FILE "\0" x (64 -length($verno));

#****************************************************************************
# Write XOR value of whole structure
# For FOTA image infomation: initial key is (0x79)
#****************************************************************************
    seek(FILE, $IMG_UA_HEAD_INFO, 0);
    # Calcualte the whole structure size.
#    $structSize = 264 + 12*$regionNo;
    $structSize = 244;

    read(FILE,$BUFFER,$structSize);
    @buffer = split(//,$BUFFER);
    $xorall = 0x79;
    foreach(@buffer){
    	$xorall = $xorall ^ ord($_);
    }
    print FILE pack("L",$xorall);
    close (FILE);
#****************************************************************************
  }
}

#************************************************************
#Start to append IMG_UA_TAIL_INFO to FOTA bin
#************************************************************
if ((defined $fota_enable) and !$SV5 ) {
  if ($fota_enable ne "NONE") { 
    
    $Size_FOTA = stat("$fota_bin")->size;
  	$IMG_UA_TAIL_INFO = 0;
  	$FOTA_TAIL = "MTK_UA_ROMINFO_TAIL_V01";
    
    open (FILE, "+<$fota_bin") or die "cannot open $fota_bin\n";
    binmode(FILE);
#    $currentPosition = tell(FILE);
    seek(FILE, 0, 2);
    $crcLength = tell(FILE);    
    print FILE $FOTA_TAIL;
    print FILE "\0" x (32 -length($FOTA_TAIL));
    seek(FILE, -32, 1);
    
    #Check sum of "MTK_UA_ROMINFO_TAIL_V01"
    read(FILE,$BUFFER,32);
    @buffer = split(//,$BUFFER);
    @buffer2 = reverse @buffer; #Convert to little-endian.

    $count = 0;
    $checksum1="";
    $checksum2="";
    $checksum="";

#****************************************************************************
# Calculate checksum of MTK_UA_ROMINFO_TAIL_V01 string
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
# Calculate checksum of FOTA_ROM_INFO string
#****************************************************************************
    $ua_version = 1;
    print FILE pack("V1", $ua_version);

#****************************************************************************
# Write Size of FOTA image
#****************************************************************************
    print FILE pack("V1",$Size_FOTA);

#****************************************************************************
# Write length of CRC check area
#****************************************************************************
#    $currentPosition = tell(FILE);
    print FILE pack("V1",$Size_FOTA);
    $currentPosition = tell(FILE);
    printf "CRC calculate len : 0x%08X\n", $crcLength;

#****************************************************************************
# Write CRC of FOTA image
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
}
exit 0;

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
	my $fota_ua_crc_key = 288;
	$c = $fota_ua_crc_key;
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