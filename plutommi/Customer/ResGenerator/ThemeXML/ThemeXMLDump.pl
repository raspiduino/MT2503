#*****************************************************************************
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
#*****************************************************************************
#
# Filename: 
# ---------
#   ThemeXMLDump.pl
#
# Description: 
# ------------
#   Dump the information of theme bin file
#       [usage] ThemeXMLDump.pl
#
#
# Auther: 
# -------
#   Fred
# 
# Note:
# -----
#
# Log: 
# -----
#  2011/07/18   Create.
#  2012/02/02   Update for downloadable theme revise
#
#*****************************************************************************
#!/usr/bin/perl
#use strict;
#use warnings;

########################################
# global variables
########################################
my $gNumOfRes;
my @gIds;
my %gResNumTable;
my %gResAddrTable;
my @gResName = ("Image", "Color", "Font Style", "Integer", "Audio", "Binary");

my $gThumbnailAddr = 0;
my $gThumbnailSize = 0;
my $gPreviewAddr = 0;
my $gPreviewSize = 0;
my $gInfoAddr = 0;
my $gInfoSize = 0;
my $gResTableAddr = 0;
my $gResTableSize = 0;
my $gStringTableAddr = 0;
my $gStringTableSize = 0;
my $gFontDataAddr = 0;
my $gFontDataSize = 0;
my $gImgDataAddr = 0;
my $gImgDataSize = 0;
my $gAdoDataAddr = 0;
my $gAdoDataSize = 0;
my $gBinDataAddr = 0;
my $gBinDataSize = 0;


########################################
# main function
########################################
my $inXMLFile = $ARGV[0];
my $inFlag = $ARGV[1];
my $buf;
&PrintDependency($0);

# print help
if (($#ARGV == -1) || ($ARGV[0] eq "-h") || ($ARGV[1] eq "-h"))
{
    print "***Usage of ThemeXMLDump.pl ***\n";
    print "\t This tool can retrieve the information from one Theme binary file.\n\n";

    print "1. ThemeXMLDump.pl <bin filename> -h\n";
    print "\t - help\n";
    print "\t - e.g. ThemeXMLDump.pl temp\\VenusTheme1.xml.bin -h\n";
    print "\n";

    print "2. ThemeXMLDump.pl <bin filename> -l\n";
    print "\t - list the information about the theme bin\n";
    print "\t - e.g. ThemeXMLDump.pl temp\\VenusTheme1.xml.bin -l\n";
    print "\n";

    print "3. ThemeXMLDump.pl <bin filename> -ls <resource type>\n";
    print "\t - list IDs of one resource type\n";
    print "\t - e.g. ThemeXMLDump.pl temp\\VenusTheme1.xml.bin -ls 0\n";
    print "\n";

    print "4. ThemeXMLDump.pl <bin filename> -d <resource type> <resource ID>\n";
    print "\t - dump the data for the resource ID\n";
    print "\t - e.g. ThemeXMLDump.pl temp\\VenusTheme1.xml.bin -d 1 VCP_COL_TEXT_VIEW_HYPELINK\n";

    print "5. ThemeXMLDump.pl <bin filename> -d <resource type> <resource ID> -o <output file>\n";
    print "\t - dump the data for the resource ID to one file, only for image / audio / binary \n";
    print "\t - e.g. ThemeXMLDump.pl temp\\VenusTheme1.xml.bin -d 0 VCP_IMG_INFO_BALLOON_PROGRESS -o image.bin\n";
    exit;
}


my $totalFileSize = -s "$inXMLFile";

open FP, "<$inXMLFile" or die "Cannot open $inXMLFile";
binmode(FP);


# read signature
read(FP, $buf, 4) or die "Cannot read signature";
die "The signature is wrong" if ($buf ne "THM\0");

# skip check-sum
read(FP, $buf, 12) or die "Cannot read check-sum";


# read table
my $headerSize = 16;
read(FP, $gThumbnailAddr, 4) or die;
$gThumbnailAddr = unpack('L', $gThumbnailAddr) + $headerSize;
read(FP, $gThumbnailSize, 4) or die;
$gThumbnailSize = unpack('L', $gThumbnailSize);
read(FP, $gPreviewAddr, 4) or die;
$gPreviewAddr = unpack('L', $gPreviewAddr) + $headerSize;
read(FP, $gPreviewSize, 4) or die;
$gPreviewSize = unpack('L', $gPreviewSize);
read(FP, $gInfoAddr, 4) or die;
$gInfoAddr = unpack('L', $gInfoAddr) + $headerSize;
read(FP, $gInfoSize, 4) or die;
$gInfoSize = unpack('L', $gInfoSize);
read(FP, $gResTableAddr, 4) or die;
$gResTableAddr = unpack('L', $gResTableAddr) + $headerSize;
read(FP, $gResTableSize, 4) or die;
$gResTableSize = unpack('L', $gResTableSize);
read(FP, $gStringTableAddr, 4) or die;
$gStringTableAddr = unpack('L', $gStringTableAddr) + $headerSize;
read(FP, $gStringTableSize, 4) or die;
$gStringTableSize = unpack('L', $gStringTableSize);
read(FP, $gFontDataAddr, 4) or die;
$gFontDataAddr = unpack('L', $gFontDataAddr) + $headerSize;
read(FP, $gFontDataSize, 4) or die;
$gFontDataSize = unpack('L', $gFontDataSize);
read(FP, $gImgDataAddr, 4) or die;
$gImgDataAddr = unpack('L', $gImgDataAddr) + $headerSize;
read(FP, $gImgDataSize, 4) or die;
$gImgDataSize = unpack('L', $gImgDataSize);
read(FP, $gAdoDataAddr, 4) or die;
$gAdoDataAddr = unpack('L', $gAdoDataAddr) + $headerSize;
read(FP, $gAdoDataSize, 4) or die;
$gAdoDataSize = unpack('L', $gAdoDataSize);
read(FP, $gBinDataAddr, 4) or die;
$gBinDataAddr = unpack('L', $gBinDataAddr) + $headerSize;
read(FP, $gBinDataSize, 4) or die;
$gBinDataSize = unpack('L', $gBinDataSize);


# read number of resource
seek(FP, $gInfoAddr, 0);
read(FP, $buf, 1) or die "Cannot read number of resource";
$gNumOfRes = unpack('C', $buf);

# read project string
read(FP, $buf, 1) or die "Cannot read project string length";
my $prjStrLen = unpack('C', $buf);
my $prjStr = "";
read(FP, $prjStr, $prjStrLen) or die "Cannot read project string";
chop($prjStr);

# read version string
read(FP, $buf, 1) or die "Cannot read version stringlength";
my $verStrLen = unpack('C', $buf);
my $verStr = "";
read(FP, $verStr, $verStrLen) or die "Cannot read version string";
chop($verStr);

# read LCD
read(FP, $buf, 2) or die "Cannot read LCD width";
my $lcdW = unpack('S', $buf);
read(FP, $buf, 2) or die "Cannot read LCD height";
my $lcdH = unpack('S', $buf);


# read table information
seek(FP, $gResTableAddr, 0);
for (my $i = 0 ; $i < $gNumOfRes ; $i ++)
{
    read(FP, $buf, 1) or die "Cannot read $i resource table type";
    my $id = unpack('C', $buf);

    read(FP, $buf, 2) or die "Cannot read $i resource table number";
    my $num = unpack('S', $buf);

    read(FP, $buf, 4) or die "Cannot read $i resource table offset";
    my $addr = unpack('L', $buf);

    push @gIds, $id;
    $gResNumTable{$id} = $num;
    $gResAddrTable{$id} = $addr + $gResTableAddr;
}


# print theme bin information
if ($inFlag eq "-l")
{

    if ($lcdW != 0)
    {
        print "Project: $prjStr\n";
        print "Version: $verStr\n";
        print "LCD: $lcdW X $lcdH\n\n";
    }

    print "Number of Resource: $gNumOfRes\n\n";

    print "Type\tNumber\tOffset\n";
    print "$_\t$gResNumTable{$_}\t$gResAddrTable{$_}\n" foreach(@gIds);

    exit;
}

# print string IDs of one resource type
if (($inFlag eq "-ls") ||
    ($inFlag eq "-d"))
{
    my $inType = $ARGV[2];
    my @strHashTable = ();
    my @strOffsetTable = ();
    my @dataTable = ();
    my @dataSizeTable = ();

    # seek to start offset of resource table
    seek(FP, $gResAddrTable{$inType}, 0);

    #print "Hash\tData\tID String\n";

    for (my $i = 0 ; $i < $gResNumTable{$inType} ; $i ++)
    {
        read(FP, $buf, 1) or die "Cannot read $i resource hash value of $inType resource type";
        my $hashValue = unpack('C', $buf);

        read(FP, $buf, 4) or die "Cannot read $i resource string offset of $inType resource type";
        my $strOffset = unpack('L', $buf) + $gStringTableAddr;

        read(FP, $buf, 4) or die "Cannot read $i resource data of $inType resource type";
        my $data = unpack('L', $buf);

        read(FP, $buf, 4) or die "Cannot read $i resource size of $inType resource type";
        my $size = unpack('L', $buf);

        push @strHashTable, $hashValue;
        push @strOffsetTable, $strOffset;
        push @dataTable, $data;
        push @dataSizeTable, $size;
    }

    if ($inFlag eq "-ls")
    {
        printf "%4s %10s %s\n", "Hash", "Data", "ID";
        for (my $i = 0 ; $i < $gResNumTable{$inType} ; $i ++)
        {
            seek(FP, $strOffsetTable[$i], 0);

            read(FP, $buf, 256);      
            my $len = index($buf, pack('C', 0));
            my $str = substr($buf, 0, $len);

            printf "%4d %10d %s\n", $strHashTable[$i], $dataTable[$i], $str;
        }
    }

    if ($inFlag eq "-d")
    {
        my $strId = $ARGV[3];
        print "$strId \[ $gResName[$inType] \]\n";

        for (my $i = 0 ; $i < $gResNumTable{$inType} ; $i ++)
        {
            seek(FP, $strOffsetTable[$i], 0);

            read(FP, $buf, 256);
            my $len = index($buf, pack('C', 0));
            my $str = substr($buf, 0, $len);

            if ($str eq $strId)
            {
                my $data = $dataTable[$i];
                my $size = $dataSizeTable[$i];

                $data += $gFontDataAddr if ($gResName[$inType] eq "Font Style");
                $data += $gImgDataAddr if ($gResName[$inType] eq "Image");
                $data += $gAdoDataAddr if ($gResName[$inType] eq "Audio");
                $data += $gBinDataAddr if ($gResName[$inType] eq "Binary");

                if (($gResName[$inType] eq "Image") ||
                    ($gResName[$inType] eq "Audio") ||
                    ($gResName[$inType] eq "Binary"))
                {
                    seek(FP, $data, 0);

                    if ($ARGV[4] eq "-o")
                    {
                        open OUTFP, ">$ARGV[5]" or die "Cannot open $ARGV[5]";
                        binmode(OUTFP);
                        read(FP, $buf, $size);
                        print OUTFP $buf;
                        close OUTFP;
                    }
                    else
                    {
                        for (my $j = 0 ; $j < $size ; $j ++)
                        {
                            read(FP, $buf, 1);
                            printf "0x%02X, ", ord($buf);

                            if (($j % 8) == 7)
                            {
                                print "\n";
                            }
                        }
                        print "\n";
                    }
                }

                if ($gResName[$inType] eq "Integer")
                {
                    printf "Value = $data\n";
                }

                if ($gResName[$inType] eq "Color")
                {
                    printf "(A, R, G, B) = (%X, %X, %X, %X)\n", $data >> 24, ($data & 0x00FF0000) >> 16, ($data & 0x0000FF00) >> 8, ($data & 0x000000FF);
                }

                if ($gResName[$inType] eq "Font Style")
                {
                    my %enumSize = (
                        'SMALL'         => 0,
                        'MEDIUM'        => 1,
                        'LARGE'         => 2,
                        'SUBLCD'        => 3,
                        'DIALER'        => 4
                    );

                    my %flagAttribute = (
                        'NORMAL'        => 0,
                        'BOLD'          => 1,
                        'OBLIQUE'       => 2,
                        'ITALIC'        => 4,
                        'UNDERLINE'     => 8,
                        'STRIKETHROUGH' => 16
                    );

                    my %enumEffect = (
                        'NONE'          => 0,
                        'STRIKETHROUGH' => 1,
                        'BORDER'        => 2,
                        'VFX_FE1_1'     => 3,
                        'VFX_FE1_2'     => 4,
                        'VFX_FE1_3'     => 5,
                        'VFX_FE1_4'     => 6,
                        'VFX_FE1_5'     => 7,
                        'VFX_FE1_6'     => 8,
                        'VFX_FE1_7'     => 9,
                        'VFX_FE1_8'     => 10,
                        'VFX_FE1_9'     => 11,
                        'VFX_FE2_1'     => 12,
                        'VFX_FE3_1'     => 13,
                        'VFX_FE4_1'     => 14,
                        'VFX_FE5_1'     => 15
                    );

                    seek(FP, $data, 0);

                    read(FP, $buf, 1);
                    my $size = unpack('C', $buf);

                    my $strSize;
                    if ($size > 128)
                    {
                        $strSize = "VEC(".($size - 128).")";
                    }
                    else
                    {
                        foreach(keys %enumSize)
                        {
                            if ($size == $enumSize{$_})
                            {
                                $strSize = $_;
                                last;
                            }
                        }
                    }

                    read(FP, $buf, 1);
                    my $attribute = unpack('C', $buf);
                    my $strAttribute;

                    foreach(keys %flagAttribute)
                    {
                        if ($attribute == $flagAttribute{$_})
                        {
                            $strAttribute = $_;
                            last;
                        }
                    }

                    read(FP, $buf, 1);
                    my $effect = unpack('C', $buf);
                    my $strEffect;

                    foreach(keys %enumEffect)
                    {
                        if ($effect == $enumEffect{$_})
                        {
                            $strEffect = $_;
                            last;
                        }
                    }

                    printf "Size\t\t= $strSize\n";
                    printf "Attribute\t= $strAttribute\n";
                    printf "Effect\t\t= $strEffect\n";
                }

                last;
            }
        }
    }

    exit;
}

close FP;

sub PrintDependency
{
	my $file = shift;
	if (-e $file)
	{
		my $path = Win32::GetCwd() . "\\" . $file;
		$path =~ s/\//\\/g;
		print STDERR "[Dependency] $path\n";
	}
}
