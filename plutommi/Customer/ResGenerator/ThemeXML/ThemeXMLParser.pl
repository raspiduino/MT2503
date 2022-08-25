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
#   ThemeXMLParser.pl
#
# Description: 
# ------------
#   Parse one theme XML file and output raw data in C array
#       [usage]
#           ThemeXMLParser.pl <theme XML filename> <output bin filename>
#           ThemeXMLParser.pl -i <theme ini filename>
#
#       [prerequisites]
#           1. should be run under mcu\plutommi\Customer\ResGenerator
#           2. need debug\image_resource_usage.txt, resgen_xml_all_enum_IDs.log
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
#  2010/08/04   Create.
#
#*****************************************************************************
#!/usr/bin/perl
#use strict;
#use warnings;

&PrintDependency($0);

########################################
# Constant
########################################
my $gcLog = "[ThemeXML]";

my $gcImgLogFile = "";
my $gcResExeFile = "";

my $gcXMLTreeFile   = "";
my $gcResGenLogFile = "";
my $gcUsageLogFile  = "";

my $gcResTempFile   = "";
my $gcDataTempFile  = "";

my $gcDataTempImageFolder = "";
my $gcDataTempImageListFile = "";

my $gcFontDefSize   = "MEDIUM";
my $gcFontDefAttr   = "NORMAL";
my $gcFontDefEffect = "NONE";

my $gcNumOfRes      = 6;    # image, color, font style, integer, audio, binary
my $gcSizeTableInfo = 7;    # table ID (1 byte) + number of resource (2 bytes) + address of resource table (4 bytes)
my $gcSizeResTable  = 13;   # hash value of ID string (1 bytes) + ID string address (4 bytes) + data (4 bytes) + size (4 bytes)


########################################
# Global Variables
########################################
my %gImgHash = ();
my %gColHash = ();
my %gFntHash = ();
my %gIntHash = ();
my %gAdoHash = ();
my %gBinHash = ();

my %gStrAddrHash = ();

my $gIsFullPath = "FALSE";

my $gProjectString = "";
my $gVersionString = "";
my $gLcdWidth = 0;
my $gLcdHeight = 0;

my $gThumbnail  = "";
my $gPreview    = "";

my $gResThemeRoot = "";

my $gImgRootPath = "";
my $gAdoRootPath = "..\\\\..\\\\Customer\\\\Audio\\\\";
my $gBinRootPath = "";

my $gMode = "DEFAULT";

my $gTableSize = 9 * 8; # (thumbnail + preview + info + index + string + font + image + audio + binary) * (offset + size)

my $gThumbnailSize = 0;
my $gThumbnailData = "";
my $gThumbnailAddr = 0;

my $gPreviewSize = 0;
my $gPreviewData = "";
my $gPreviewAddr = 0;

my $gInfoSize = 0;
my $gInfoData = "";
my $gInfoAddr = 0;

my $gResTableSize = $gcNumOfRes * $gcSizeTableInfo;
my $gResTableData = "";
my $gResTableAddr = 0;

my $gStringTableSize = 0;
my $gStringTableData = "";
my $gStringTableAddr = 0;

my $gFontDataSize = 0;
my $gFontData = "";
my $gFontDataAddr = 0;

my $gImgDataSize = 0;
my $gImgData = "";
my $gImgDataAddr = 0;

my $gAdoDataSize = 0;
my $gAdoData = "";
my $gAdoDataAddr = 0;

my $gBinDataSize = 0;
my $gBinData = "";
my $gBinDataAddr = 0;

my $gMainThemeSize = 0;
my $gMainThemeData = "";

my %gIdAddrHash = ();
my %gFileSizeHash = ();

my $offset = 0;

########################################
# Function: Loading Image
#   data : image hash
#   path : image path
########################################
sub loadImage
{
    my $data = shift;
    my $path = shift;

    for my $imgId (sort keys %{$data})
    {
        my $full_path = "$path$data->{$imgId}->{'src'}";

        $full_path =~ s/RES_THEME_ROOT/$gResThemeRoot/;
        #print STDERR "$gcLog $imgId:\t$full_path\n";
        $full_path =~ s/\\+/\\\\/g;
        $gImgHash{$imgId} = $full_path;

        $gStrAddrHash{$imgId} = 0;
    }
}


########################################
# Function: Loading Color
#   data :  color hash
########################################
sub loadColor
{
    my $data = shift;

    for my $colId (sort keys %{$data})
    {
        my $color = $data->{$colId}->{'value'};
        my $h = qr/[0-9a-fA-F]/;

        $color =~ /\#($h{2})($h{2})($h{2})($h{2})/;
        #print STDERR "$gcLog $colId:\t(A=$1, R=$2, G=$3, B=$4)\n";
        $gColHash{$colId} = {'A'=>hex("0x$1"), 'R'=>hex("0x$2"), 'G'=>hex("0x$3"), 'B'=>hex("0x$4")};

        $gStrAddrHash{$colId} = 0;
    }
}


########################################
# Function: Loading Font
#   data :  font hash
########################################
sub loadFont
{
    my $data = shift;

    for my $fontId (sort keys %{$data})
    {
        my $font = $data->{$fontId};
        my $size = (exists $font->{'size'}) ? ($font->{'size'}) : ($gcFontDefSize);
        my $attribute = (exists $font->{'attribute'}) ? ($font->{'attribute'}) : ($gcFontDefAttr);
        my $effect = (exists $font->{'effect'}) ? ($font->{'effect'}) : ($gcFontDefEffect);

        #print STDERR "$gcLog $fontId:\t(size=$size, attribute=$attribute, effect=$effect)\n";
        $gFntHash{$fontId} = {'Size'=>$size, 'Attribute'=>$attribute, 'Effect'=>$effect};

        $gStrAddrHash{$fontId} = 0;
    }
}


########################################
# Function: Loading Integer
#   data :  integer hash
########################################
sub loadInteger
{
    my $data = shift;

    for my $intId (sort keys %{$data})
    {
        my $i = $data->{$intId}->{'value'};

        #print STDERR "$gcLog $intId:\t$i\n";
        $gIntHash{$intId} = $i;

        $gStrAddrHash{$intId} = 0;
    }
}


########################################
# Function: Loading Audio
#   data : audio hash
#   path : audio path
########################################
sub loadAudio
{
    my $data = shift;
    my $path = shift;

    for my $adoId (sort keys %{$data})
    {
        #print STDERR "$gcLog $adoId:\t$path\\$data->{$adoId}->{'src'}\n";
        $gAdoHash{$adoId} = "$path$data->{$adoId}->{'src'}";

        $gStrAddrHash{$adoId} = 0;
    }
}


########################################
# Function: Loading Binary
#   data : binary hash
#   path : binary path
########################################
sub loadBinary
{
    my $data = shift;
    my $path = shift;

    for my $binId (sort keys %{$data})
    {
        #print STDERR "$gcLog $binId:\t$path\\$data->{$binId}->{'src'}\n";
        $gBinHash{$binId} = "$path$data->{$binId}->{'src'}";

        $gStrAddrHash{$binId} = 0;
    }
}


########################################
# Function: printe a byte in binary
#   data : data
########################################
sub printByte
{
    my $data = shift;

    print pack('C', $data);
}


########################################
# Function: printe a word in binary
#   data : data
########################################
sub printWord
{
    my $data = shift;

    printByte(($data & 0xFF));
    printByte(($data & 0xFF00) >> 8);
}


########################################
# Function: printe a double word in binary
#   data : data
########################################
sub printDWord
{
    my $data = shift;

    printByte(($data & 0xFF));
    printByte(($data & 0xFF00) >> 8);
    printByte(($data & 0xFF0000) >> 16);
    printByte(($data & 0xFF000000) >> 24);
}


########################################
# Function: print 0 for 4-byte alignment
#   offset : offset
# Return : number (in bytes) of print data
########################################
sub printPadding4Byte
{
    my $offset = shift;
    my $offset_shift = 0;

    # 4-byte alignment
    for (my $i = 0 ; (($i + $offset) % 4) != 0 ; $i ++)
    {
        printByte(0);
        $offset_shift++;
    }

    return $offset_shift;
}


########################################
# Function: print binary data file
#   filename : input filename
# Return : number (in bytes) of print data
########################################
sub printBinaryFile
{
    my $filename = shift;
    my $offset_shift = 0;

    if (open(INFILE, "<$filename"))
    {
        binmode INFILE;

        my $buf;
        while (read(INFILE, $buf, 1))
        {
            print $buf;
            $offset_shift ++;
        }

        close INFILE;
    }

    return $offset_shift;
}


########################################
# Function: convert to valid windows file name
#   str : input file name
# Return : valid file name
########################################
sub convertValidFilename
{
    my $filename = shift;

    $filename =~ s/\//_/g;
    $filename =~ s/\\\\/_/g;
    $filename =~ s/\\/_/g;
    $filename =~ s/\./_/g;
    
    return $filename;
}

########################################
# Function: get the common header sub string of the 2 strings
# input  : 2 strings
# Return : common header of the 2 strings
########################################
sub commonHeaderString
{
    for ($i = 0; (substr($_[0], 0, $i+1) eq substr($_[1], 0, $i+1)) and $i < length $_[0]; $i++) {}
    return substr $_[0], 0, $i;
}

########################################
# Function: choose a random key from a hash
# input  : a hash table
# Return : a random key of the hash
########################################
sub chooseKey
{
    my %hashtable = @_;
    my @keys = keys %hashtable;
    return $keys[0];
}

########################################
# Function: calculate the hash value of string
#   str : input string
########################################
sub hashString
{
    my $str = shift;
    my $value = 0;

    $value += ord($_) foreach split(//, $str);

    return $value % 255;
}


########################################
# Function: sort keys of hash table with hashString function
#   hashPtr : hash table
# Returns: array of ID strings
########################################
sub sortHashKey
{
    my $hashPtr = shift;
    my %value;
    my @data = ();

    $value{$_} = hashString($_) foreach (keys %{$hashPtr});
    push @data, $_ foreach (sort {$value {$a} <=> $value {$b}} keys %value);

    return @data;
}


########################################
# Function: print table information
#   id      : table ID
#   number  : number of resource
#   addr    : address of resource table
########################################
sub printTableInfo
{
    my $id = shift;
    my $number = shift;
    my $addr = shift;

    printByte($id);
    printWord($number);
    printDWord($addr);
}


########################################
# Function: print item in resource table
#   strId   : ID string
#   addr    : ID string address
#   data    : data
########################################
sub printResourceTableItem
{
    my $strId = shift;
    my $hashValue = hashString($strId);
    my $addr = shift;
    my $data = shift;

    printByte($hashValue);
    printDWord($addr);
    printDWord($data);
    printDWord(0);
}


########################################
# Function: print item in resource table
#   strId   : ID string
#   addr    : ID string address
#   data    : data
#   size    : size of data
########################################
sub printDataResourceTableItem
{
    my $strId = shift;
    my $hashValue = hashString($strId);
    my $addr = shift;
    my $data = shift;
    my $size = shift;

    printByte($hashValue);
    printDWord($addr);
    printDWord($data);
    printDWord($size);
}


########################################
# Function: print log
#   str    : log info
########################################
sub printLog
{
    my $str = shift;

    print STDERR "$str";
}


########################################
# Function: read
#   file : temp filename 
#   size : data size
########################################
sub readTempFile
{
    my $file = shift;
    my $data;
    my $size = shift;

    open FP, "<$file" or die "$gcLog Error: Cannot open $file\n";
    binmode FP;
    read(FP, $data, $size);
    close FP;

    $_[0] = $data;
}


########################################
# Main Function
########################################

########################################
# Set arguments
########################################
my $inXMLFile;
my $outBinFile;
use File::Basename;

my $arg = shift @ARGV;
if ($arg eq "-i")
{   # load ini
    my $iniFile = shift @ARGV;

    open FP, "<$iniFile" or die "$gcLog Error: Cannot open $iniFile";
    &PrintDependency($iniFile);
    while(<FP>)
    {
        chomp;

        next if (/^\s*\[/);  # skip [xxx]
        next if (/^\s*;/);   # skip ;xxx
        next if (/^\s*$/);   # skip empty line;

        if (/^\s*(.+?)\s*=\s*\"*(.+?)\"*\s*$/)
        {
            $inXMLFile = $2 if ($1 eq "THEME_XML_FILE");
            $gcImgLogFile = $2 if ($1 eq "IMG_LOG_FILE");
            $gcResExeFile = $2 if ($1 eq "RES_EXE_FILE");
            $outBinFile = $2 if ($1 eq "THEME_BIN_FILE");
            $gcXMLTreeFile = $2 if ($1 eq "TREE_LOG_FILE");
            $gcResGenLogFile = $2 if ($1 eq "RESGEN_LOG_FILE");
            $gcUsageLogFile = $2 if ($1 eq "USAGE_LOG_FILE");
            $gcResTempFile = $2 if ($1 eq "RES_TEMP_FILE");
            $gcDataTempFile = $2 if ($1 eq "DATA_TEMP_FILE");
            $gcDataTempImageFolder = $2 if ($1 eq "DATA_TEMP_IMAGE_FOLDER");
            $gcDataTempImageListFile = $2 if ($1 eq "DATA_TEMP_IMAGE_LIST_FILE");
        }
    }
    close FP;

    $gcResTempFile =~ /(.*)\\(.*)$/;
    my $tempFolder = $1;
    $gcDataTempImageFolder = "$tempFolder\\TempImage" if ($gcDataTempImageFolder eq "");
    $gcDataTempImageListFile = "$tempFolder\\theme_list_file.txt" if ($gcDataTempImageListFile eq "");
}
else
{   # for systeme theme only
    $inXMLFile = $arg;
    $outBinFile = shift @ARGV;

    $gcImgLogFile    = ".\\debug\\image_resource_usage.txt";
    $gcResExeFile    = "mtk_resgenerator.exe";

    $gcXMLTreeFile   = ".\\ThemeXML\\Log\\theme_xml_tree_XXX.log";
    $gcResGenLogFile = ".\\ThemeXML\\Log\\theme_xml_resgen_XXX.log";
    $gcUsageLogFile  = ".\\ThemeXML\\Log\\theme_xml_usage_XXX.log";

    $gcResTempFile   = ".\\ThemeXML\\Temp\\theme_res.temp";
    $gcDataTempFile  = ".\\ThemeXML\\Temp\\theme_data.temp";

    # Replace log name with the prefix of the outBinFile
    $outBinFile =~ /(.*)\\(.*?)\.xml/i;
    my $inXMLFilePrefix = $2;
    $gcXMLTreeFile =~ s/XXX/$inXMLFilePrefix/;
    $gcResGenLogFile =~ s/XXX/$inXMLFilePrefix/;
    $gcUsageLogFile =~ s/XXX/$inXMLFilePrefix/;

    $gcDataTempImageFolder = ".\\ThemeXML\\TempImage";
    my @inXMLFilenameParts = split(/\./, basename $inXMLFile);
    $gcDataTempImageListFile = ".\\ThemeXML\\Log\\theme_list_file_" . $inXMLFilenameParts[0] . ".txt";
}

if ($#ARGV != -1)
{
    $arg = shift @ARGV;
    $gMode = "OTF" if ($arg eq "\-otf");
}


########################################
# load XML
########################################
printLog("$gcLog Load XML ... ");

use XML::Simple;

my $xml = new XML::Simple;
my $gXMLData = $xml->XMLin($inXMLFile, forceArray => 1);

# dump the XML tree
open FP, ">$gcXMLTreeFile" or die "$gcLog Error: Cannot open $gcXMLTreeFile";
use Data::Dumper;
print FP Dumper($gXMLData);
close FP;

# create log file of mtk_resgenerator.exe
open FP, ">$gcResGenLogFile" or die "$gcLog Error: Cannot open $gcResGenLogFile";
close FP;

printLog("done\n");

$gResThemeRoot = $gXMLData->{'RES_THEME_ROOT'};
$gIsFullPath = $gXMLData->{'isFullPath'} if exists $gXMLData->{'isFullPath'};
$gProjectString = $gXMLData->{'project'} if exists $gXMLData->{'project'};
$gVersionString = $gXMLData->{'version'} if exists $gXMLData->{'version'};
$gLcdWidth = $gLcdWidth + $gXMLData->{'width'} if exists $gXMLData->{'width'};
$gLcdHeight = $gLcdHeight + $gXMLData->{'height'} if exists $gXMLData->{'height'};
$gThumbnail = $gXMLData->{'thumbnail'} if exists $gXMLData->{'thumbnail'};
$gPreview = $gXMLData->{'preview'} if exists $gXMLData->{'preview'};

# get file path
if ($gIsFullPath eq "FALSE")
{
    open FP, "<$gcImgLogFile" or die "$gcLog Error: Cannot open $gcImgLogFile";
    while(<FP>)
    {
        my @test = split(/\t/);
        if ($test[5] =~ /(.*?)Images\\*(.*?)\\*MainLCD/)
        {
            $gImgRootPath = "$1Images\\\\$2\\\\MainLCD\\\\";
            #print STDERR "$gcLog image path = $gImgRootPath\n\n";
            last;
        }
    }
    close FP;
}

printLog("$gcLog Parse XML ... ");

# load global theme data
loadImage($gXMLData->{'Image'}, $gImgRootPath);
loadColor($gXMLData->{'Color'});
loadFont($gXMLData->{'FontStyle'});
loadInteger($gXMLData->{'Integer'});
loadAudio($gXMLData->{'Audio'}, $gAdoRootPath);
loadBinary($gXMLData->{'Binary'}, $gBinRootPath);

# load component theme data
my $cpHashPtr = $gXMLData->{'Component'};
for my $cp (sort keys %{$cpHashPtr})
{
    my $cpHash = $cpHashPtr->{$cp};
    my $path;

    #load image
    $path = (exists $cpHash->{'imgPath'}) ? ($gImgRootPath.$cpHash->{'imgPath'}."\\\\") : ($gImgRootPath);
    loadImage($cpHash->{'Image'}, $path);

    #load color
    loadColor($cpHash->{'Color'});

    #load font style
    loadFont($cpHash->{'FontStyle'});

    #load integer
    loadInteger($cpHash->{'Integer'});

    #load audio
    $path = (exists $cpHash->{'adoPath'}) ? ($gAdoRootPath.$cpHash->{'adoPath'}."\\\\") : ($gAdoRootPath);
    loadAudio($cpHash->{'Audio'}, $path);

    #load binary
    $path = (exists $cpHash->{'binPath'}) ? ($gBinRootPath.$cpHash->{'binPath'}."\\\\") : ($gBinRootPath);
    loadBinary($cpHash->{'Binary'}, $path);
}

printLog("done\n");

# count number of each resource
my $numOfImg = scalar keys %gImgHash;
my $numOfCol = scalar keys %gColHash;
my $numOfFnt = scalar keys %gFntHash;
my $numOfInt = scalar keys %gIntHash;
my $numOfAdo = scalar keys %gAdoHash;
my $numOfBin = scalar keys %gBinHash;


########################################
# create thumbnail
########################################
if ($gThumbnail ne "")
{
    $gThumbnail = $gImgRootPath.$gThumbnail;
    $gThumbnail =~ s/RES_THEME_ROOT/$gResThemeRoot/;
    $gThumbnail =~ s/\\+/\\\\/g;
    if (-e $gThumbnail)
    {
        my $filename = $gThumbnail;
        my $cmd = "$gcResExeFile -f -i \"$filename\" \"$gcResTempFile\"";
        system("echo $cmd >> $gcResGenLogFile");
        system("$cmd >> $gcResGenLogFile");

        if (($? / 256) != 1)
        {
            printLog("$gcLog Warning: $filename is failed to convert \n");
        }
        else
        {
            # thumbnail size
            $gThumbnailSize = -s "$gcResTempFile";
            $gThumbnailData = readTempFile($gcResTempFile, $gThumbnailSize);
        }
    }
}


########################################
# create preview
########################################
if ($gPreview ne "")
{
    $gPreview = $gImgRootPath.$gPreview;
    $gPreview =~ s/RES_THEME_ROOT/$gResThemeRoot/;
    $gPreview =~ s/\\+/\\\\/g;
    if (-e $gPreview)
    {
        my $filename = $gPreview;
        my $cmd = "$gcResExeFile -f -i \"$filename\" \"$gcResTempFile\"";
        system("echo $cmd >> $gcResGenLogFile");
        system("$cmd >> $gcResGenLogFile");

        if (($? / 256) != 1)
        {
            printLog("$gcLog Warning: $filename is failed to convert \n");
        }
        else
        {
            # thumbnail size
            $gPreviewSize = -s "$gcResTempFile";
            $gPreviewData = readTempFile($gcResTempFile, $gPreviewSize);
        }
    }
}


########################################
# create string table
########################################
open FP, ">$gcDataTempFile" or die "$gcLog Error: Cannot open $gcDataTempFile\n";
select FP;
binmode FP;

foreach (sort keys %gStrAddrHash)
{
    print $_;
    printByte(0);   # null terminate

    $gStrAddrHash{$_} = $gStringTableSize;
    $gStringTableSize += length($_) + 1;
}

select STDOUT;
close FP;

$gStringTableData = readTempFile($gcDataTempFile, $gStringTableSize);


########################################
# create font data
########################################
open FP, ">$gcDataTempFile" or die "$gcLog Error: Cannot open $gcDataTempFile\n";
select FP;
binmode FP;

foreach (sort keys %gFntHash)
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

    # convert size
    my $strSize = $gFntHash{$_}->{'Size'};
    my $size = ($strSize =~ /VEC\((\d+)\)/) ? (128 + $1) : ($enumSize{$strSize});
    #print STDERR "$gcLog $_:\tsize\t\t= $size\n";

    # convert attribute
    my $strAttribute = $gFntHash{$_}->{'Attribute'};
    my $attribute = 0;
    foreach (keys %flagAttribute)
    {
        $attribute = $attribute + $flagAttribute{$_} if ($strAttribute =~ /$_/);
    }
    #print STDERR "$gcLog $_:\tattribute\t= $attribute\n";

    # convert effect
    my $effect = $enumEffect{$gFntHash{$_}->{'Effect'}};
    #print STDERR "$gcLog $_:\teffect\t\t= $effect\n";

    printByte($size);
    printByte($attribute);
    printByte($effect);

    # shift offset
    #print STDERR "$gcLog $_:\toffset\t\t= $gFontDataSize\n";
    $gIdAddrHash{$_} = $gFontDataSize;
    $gFontDataSize += 3;
}

select STDOUT;
close FP;

$gFontData = readTempFile($gcDataTempFile, $gFontDataSize);

printLog("$gcLog Convert data\n");


########################################
# create image data
########################################
open FP, ">$gcDataTempFile" or die "$gcLog Error: Cannot open $gcDataTempFile\n";
select FP;
binmode FP;


open LIST_FILE, ">$gcDataTempImageListFile" or die "$gcLog Error: Cannot open $gcDataTempImageListFile\n";

#process image files
mkdir $gcDataTempImageFolder unless (-d $gcDataTempImageFolder);
my %dupImgTable;

my $commonPath = $gImgHash{chooseKey(%gImgHash)};
foreach (sort keys %gImgHash)
{
    $commonPath = commonHeaderString($commonPath, $gImgHash{$_});
}

my $commonPathLength = length $commonPath;

foreach (sort keys %gImgHash)
{
    my $filename = $gImgHash{$_};

    if (defined($dupImgTable{$filename}))
    {
        next;
    }

    if (-e $filename)
    {
        my $validFilename = convertValidFilename(substr $filename, $commonPathLength);
        my $outputTempFile = "$gcDataTempImageFolder\\$validFilename\.tmp";
        print LIST_FILE "i\t$filename\t$outputTempFile\t\n";

        $dupImgTable{$filename} = 1;
    }
}

close (LIST_FILE);

my $cmd = "$gcResExeFile -b $gcDataTempImageListFile";
system("echo $cmd >> $gcResGenLogFile");
system("echo mtk_resgen convert start %time%");
system("$cmd >> $gcResGenLogFile");

if (($? / 256) != 1)
{
    printLog("$gcLog Warning: list file is failed to convert \n");
}

system("echo mtk_resgen convert end %time%");

# output converted image file
my %dupImgTest;
foreach (sort keys %gImgHash)
{
    my $filename = $gImgHash{$_};

    if (defined($dupImgTest{$filename}))
    {
        $gIdAddrHash{$_} = $dupImgTest{$filename};
        next;
    }

    if (-e $filename)
    {
        # image starts at 4-byte aligned address
        $gImgDataSize += printPadding4Byte($gImgDataSize);

        # convert image
        my $validFilename = convertValidFilename(substr $filename, $commonPathLength);
        my $outputTempFile = "$gcDataTempImageFolder\\$validFilename\.tmp";
        printLog(".") if ($gMode eq "OTF");

        my $count = printBinaryFile($outputTempFile);
        $gFileSizeHash{$filename} = $count;
        $gIdAddrHash{$_} = ($count) ? ($gImgDataSize) : (0);
        $gImgDataSize += $count;
        $dupImgTest{$filename} = $gIdAddrHash{$_};
    }
    else
    {
        printLog("$gcLog Warning: $filename is not existed\n");
        $gFileSizeHash{$filename} = 0;
        $gIdAddrHash{$_} = 0xFFFFFFFF;
    }
}

select STDOUT;
close FP;

$gImgData = readTempFile($gcDataTempFile, $gImgDataSize);


########################################
# create audio data
########################################
open FP, ">$gcDataTempFile" or die "$gcLog Error: Cannot open $gcDataTempFile\n";
select FP;
binmode FP;

my %dupAdoTest;
foreach (sort keys %gAdoHash)
{
    my $filename = $gAdoHash{$_};

    if (defined($dupAdoTest{$filename}))
    {
        $gIdAddrHash{$_} = $dupAdoTest{$filename};
        next;
    }

    if (-e $filename)
    {
        # image starts at 4-byte aligned address
        $gAdoDataSize += printPadding4Byte($gAdoDataSize);

        # convert image
        #print STDERR "$gcResExeFile -f -i $filename $gcResTempFile\n";
        my $cmd = "$gcResExeFile -f -a \"$filename\" \"$gcResTempFile\"";
        system("echo $cmd >> $gcResGenLogFile");
        system("$cmd >> $gcResGenLogFile");
        printLog(".") if ($gMode eq "OTF");

        # ResGen got error
        if (($? / 256) != 1)
        {
            printLog("$gcLog Warning: $filename is failed to convert \n");
        }

        my $count = printBinaryFile($gcResTempFile);
        $gFileSizeHash{$filename} = $count;
        $gIdAddrHash{$_} = ($count) ? ($gAdoDataSize) : (0);
        $gAdoDataSize += $count;
        $dupAdoTest{$filename} = $gIdAddrHash{$_};
    }
    else
    {
        printLog("$gcLog Warning: $filename is not existed\n");
        $gFileSizeHash{$filename} = 0;
    }
}

select STDOUT;
close FP;

$gAdoData = readTempFile($gcDataTempFile, $gAdoDataSize);


########################################
# create binary data
########################################
open FP, ">$gcDataTempFile" or die "$gcLog Error: Cannot open $gcDataTempFile\n";
select FP;
binmode FP;

foreach (sort keys %gBinHash)
{
    my $filename = $gBinHash{$_};

    if (-e $filename)
    {
        $gBinDataSize += printPadding4Byte($gBinDataSize);
    
        my $count = printBinaryFile($filename);
        $gFileSizeHash{$filename} = 0;
        $gIdAddrHash{$_} = ($count) ? ($gBinDataSize) : (0);
        $gBinDataSize += $count;
    }
    else
    {
        printLog("$gcLog Warning: $filename is not existed\n");
        $gFileSizeHash{$filename} = 0;
    }
}

select STDOUT;
close FP;

$gBinData = readTempFile($gcDataTempFile, $gBinDataSize);

printLog("... done\n");

printLog("$gcLog Output data ... ");


########################################
# create info data
########################################
open FP, ">$gcDataTempFile" or die "$gcLog Error: Cannot open $gcDataTempFile\n";
binmode FP;
select FP;

# number of resource
printByte($gcNumOfRes);
$gInfoSize += 1;

# project srting
printByte(length($gProjectString) + 1);         # project string length
print $gProjectString;                          # project string
printByte(0);                                   # null-terminated
$gInfoSize += 1 + length($gProjectString) + 1;  # size (1 byte) + string length (n bytes) + null (1 byte)

# theme version
printByte(length($gVersionString) + 1);         # version string length
print $gVersionString;                          # version string
printByte(0);                                   # null-terminated
$gInfoSize += 1 + length($gVersionString) + 1;  # size (1 byte) + string length (n bytes) + null (1 byte)

# LCD width & height
printWord($gLcdWidth);  # screen width
printWord($gLcdHeight); # screen height
$gInfoSize += 4;        # width (2 bytes) + height (2 bytes)

select STDOUT;
close FP;

$gInfoData = readTempFile($gcDataTempFile, $gInfoSize);


########################################
# create resource table data
########################################
open FP, ">$gcDataTempFile" or die "$gcLog Error: Cannot open $gcDataTempFile\n";
binmode FP;
select FP;

# print index table of resource
my $tableAddr = $gResTableSize;
my $allTableSize = $gcSizeResTable * ($numOfImg + $numOfCol + $numOfFnt + $numOfInt + $numOfAdo + $numOfBin); 
$gResTableSize += $allTableSize;

printTableInfo(0, $numOfImg, $tableAddr);
$tableAddr += $gcSizeResTable*$numOfImg;

printTableInfo(1, $numOfCol, $tableAddr);
$tableAddr += $gcSizeResTable*$numOfCol;

printTableInfo(2, $numOfFnt, $tableAddr);
$tableAddr += $gcSizeResTable*$numOfFnt;

printTableInfo(3, $numOfInt, $tableAddr);
$tableAddr += $gcSizeResTable*$numOfInt;

printTableInfo(4, $numOfAdo, $tableAddr);
$tableAddr += $gcSizeResTable*$numOfAdo;

printTableInfo(5, $numOfBin, $tableAddr);
$tableAddr += $gcSizeResTable*$numOfBin;

# create usage log file
open FP_USG, ">$gcUsageLogFile" or die "$gcLog Error: Cannot open $gcUsageLogFile";
print FP_USG "TYPE\tID\tDATA\n";

# print each resource table
my @arrayId = ();

# image
print FP_USG "\n#IMAGE\tID\tSize\tFilepath\n";
@arrayId = sortHashKey(\%gImgHash);
printDataResourceTableItem($_, $gStrAddrHash{$_}, $gIdAddrHash{$_}, $gFileSizeHash{$gImgHash{$_}}) foreach (@arrayId);
print FP_USG "IMAGE\t$_\t$gFileSizeHash{$gImgHash{$_}}\t$gImgHash{$_}\n" foreach (@arrayId);

# color
print FP_USG "\n#COLOR\tID\t(A, R, G, B)\n";
@arrayId = sortHashKey(\%gColHash);
foreach (@arrayId)
{
    my $color = $gColHash{$_};
    my $data = $color->{'B'} | ($color->{'G'} << 8) | ($color->{'R'} << 16) | ($color->{'A'} << 24);

    printResourceTableItem($_, $gStrAddrHash{$_}, $data);
    print FP_USG "COLOR\t$_\t($color->{'A'}, $color->{'R'}, $color->{'G'}, $color->{'B'})\n";
}

# font
print FP_USG "\n#FONT\tID\tSize\tAttribute\tEffect\n";
@arrayId = sortHashKey(\%gFntHash);
printResourceTableItem($_, $gStrAddrHash{$_}, $gIdAddrHash{$_}) foreach (@arrayId);
print FP_USG "FONT\t$_\t".$gFntHash{$_}->{"Size"}."\t".$gFntHash{$_}->{"Attribute"}."\t".$gFntHash{$_}->{"Effect"}."\n" foreach (@arrayId);

# integer
print FP_USG "\n#INTEGER\tID\tValue\n";
@arrayId = sortHashKey(\%gIntHash);
printResourceTableItem($_, $gStrAddrHash{$_}, $gIntHash{$_}) foreach (@arrayId);
print FP_USG "INTEGER\t$_\t$gIntHash{$_}\n" foreach (@arrayId);

# audio
print FP_USG "\n#AUDIO\tID\tFilepath\n";
@arrayId = sortHashKey(\%gAdoHash);
printDataResourceTableItem($_, $gStrAddrHash{$_}, $gIdAddrHash{$_}, $gFileSizeHash{$gAdoHash{$_}}) foreach (@arrayId);
print FP_USG "AUDIO\t$_\t$gAdoHash{$_}\n" foreach (@arrayId);

# binary
print FP_USG "\n#BINARY\tID\tFilepath\n";
@arrayId = sortHashKey(\%gBinHash);
printDataResourceTableItem($_, $gStrAddrHash{$_}, $gIdAddrHash{$_}, $gFileSizeHash{$gBinHash{$_}}) foreach (@arrayId);
print FP_USG "BINARY\t$_\t$gBinHash{$_}\n" foreach (@arrayId);

close FP_USG;

select STDOUT;
close FP;

$gResTableData = readTempFile($gcDataTempFile, $gResTableSize);


########################################
# create main theme binary
########################################
open FP, ">$gcDataTempFile" or die "$gcLog Error: Cannot open $gcDataTempFile\n";
select FP;
binmode FP;

$offset = $gTableSize;

# print thumbnail
$offset += printPadding4Byte($offset);
$gThumbnailAddr = $offset;
print $gThumbnailData;
$offset += $gThumbnailSize;

# print preview
$offset += printPadding4Byte($offset);
$gPreviewAddr = $offset;
print $gPreviewData;
$offset += $gPreviewSize;

# print info
$gInfoAddr = $offset;
print $gInfoData;
$offset += $gInfoSize;

# print resource table
$gResTableAddr = $offset;
print $gResTableData;
$offset += $gResTableSize;

# print string table
$gStringTableAddr = $offset;
print $gStringTableData;
$offset += $gStringTableSize;

# print font data
$gFontDataAddr = $offset;
print $gFontData;
$offset += $gFontDataSize;

# print image data
$offset += printPadding4Byte($offset);
$gImgDataAddr = $offset;
print $gImgData;
$offset += $gImgDataSize;

# print audio data
$offset += printPadding4Byte($offset);
$gAdoDataAddr = $offset;
print $gAdoData;
$offset += $gAdoDataSize;

# print binary data
$offset += printPadding4Byte($offset);
$gBinDataAddr = $offset;
print $gBinData;
$offset += $gBinDataSize;

$gMainThemeSize = $gThumbnailSize + $gPreviewSize + $gInfoSize + $gResTableSize + $gStringTableSize + $gFontDataSize + $gImgDataSize + $gAdoDataSize + $gBinDataSize;

select STDOUT;
close FP;

$gMainThemeSize = -s "$gcDataTempFile";
$gMainThemeData = readTempFile($gcDataTempFile, $gMainThemeSize);


########################################
# create all theme data
########################################
open FP, ">$gcDataTempFile" or die "$gcLog Error: Cannot open $gcDataTempFile\n";
select FP;
binmode FP;

printDWord($gThumbnailAddr);
printDWord($gThumbnailSize);
printDWord($gPreviewAddr);
printDWord($gPreviewSize);
printDWord($gInfoAddr);
printDWord($gInfoSize);
printDWord($gResTableAddr);
printDWord($gResTableSize);
printDWord($gStringTableAddr);
printDWord($gStringTableSize);
printDWord($gFontDataAddr);
printDWord($gFontDataSize);
printDWord($gImgDataAddr);
printDWord($gImgDataSize);
printDWord($gAdoDataAddr);
printDWord($gAdoDataSize);
printDWord($gBinDataAddr);
printDWord($gBinDataSize);
$gMainThemeSize += $gTableSize;
print $gMainThemeData;

select STDOUT;
close FP;

$gMainThemeData = readTempFile($gcDataTempFile, $gMainThemeSize);


########################################
# create verification and final output
########################################

# calculate check-sum
my $sum = 0;
$sum += ord($_) foreach(split(//, $gMainThemeData));
my $key = 0xFFFFFFFF - $sum % 0xFFFFFFFF;

# open output file
open OUTFP, ">$outBinFile" or die "$gcLog Error: Cannot open $outBinFile";
binmode OUTFP;
select OUTFP;

# print verification header
print "THM\0";
printDWord(4);                  # check-sum length
printDWord($key);               # check-sum key
printDWord($gMainThemeSize);    # Theme data size

# print theme data
print $gMainThemeData;

select STDOUT;
close OUTFP;


printLog("done\n");


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
