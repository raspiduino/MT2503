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
#   ThemeXMLDLTGen.pl
#
# Description: 
# ------------
#   generate default theme XML file for Downloadable Theme tool
#
#   usage:
#       ThemeXMLDLTGen.pl <output path> <default path>
#       e.g. ThemeXMLMBAGen.pl W:\DLT Z:
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
#  2011/12/16   Create.
#
#*****************************************************************************
#!/usr/bin/perl
#use strict;
#use warnings;

########################################
# Global Variables
########################################
my $gcPreXMLTool = "..\\..\\..\\..\\tools\\python25\\python.exe ..\\..\\..\\..\\tools\\py\\prexml.py";
my $gcResPath = "..\\..\\CustResource";
my $gcSysThemeFile = "$gcResPath\\VenusSysThemeCFG.xml";

my $gcVernoFile = "..\\..\\..\\..\\verno\\verno.c";
my $gcImgLogFile = "..\\debug\\image_resource_usage.txt";
my $gcThemeDescFile = "..\\debug\\venus_theme_log.txt";

my $gcThmTmpFoder = ".\\Temp";
my $gcThmCfgFile = "$gcThmTmpFoder\\VenusSysThemeCFG.xml.i";

my $gOutputDir = "";

my $gResThemeRoot = "";
my $gDefaultPath = "";

my $gProjectStr = "";
my $gVersionStr = "";
my $gLcdWidth = "";
my $gLcdHeight = "";

my %gIdDescHash = ();

my $gFlag = "";


########################################
# Function: replace path
#   data :  [IN]
########################################
sub addDesc
{
    my $data = shift;

    for my $id (sort keys %{$data})
    {
        $data->{$id}->{'desc'} = $gIdDescHash{$id};
    }
}

########################################
# Function: replace path
#   data :  [IN]
#   path :  [IN]
########################################
sub replacePath
{
    my $data = shift;
    my $path = shift;

    for my $id (sort keys %{$data})
    {
        my $full_path = "$path\\\\$data->{$id}->{'src'}";

        $full_path =~ s/RES_THEME_ROOT/$gResThemeRoot/;
        $full_path =~ s/\\+/\\\\/g;
        $data->{$id}->{'src'} = $full_path;
    }
}


########################################
# Function: convert one theme XML file
#   inputFilename   :  [IN] input file name
#   outputFilename  :  [IN] output file name
########################################
sub convertFile
{
    my $inputFilename = shift;
    my $outputFilename = shift;

    use XML::Simple;

    my $xml = new XML::Simple;
    my $dataIn = $xml->XMLin($inputFilename, forceArray => 1);

    # process
    $gResThemeRoot = $dataIn->{'RES_THEME_ROOT'};
    delete $dataIn->{'RES_THEME_ROOT'};
    $dataIn->{'isFullPath'} = "TRUE";
    $dataIn->{'project'} = $gProjectStr;
    $dataIn->{'version'} = $gVersionStr;
    $dataIn->{'width'} = $gLcdWidth;
    $dataIn->{'height'} = $gLcdHeight;

    my $path = $gDefaultPath."\\\\".$gResThemeRoot;
    $dataIn->{'thumbnail'} =~ s/RES_THEME_ROOT/$path/;
    $dataIn->{'preview'} =~ s/RES_THEME_ROOT/$path/;

    replacePath($dataIn->{'Image'}, $gDefaultPath);
    replacePath($dataIn->{'Audio'}, $gDefaultPath);
    replacePath($dataIn->{'Binary'}, $gDefaultPath);

    my $cpHashPtr = $dataIn->{'Component'};
    for my $cp (sort keys %{$cpHashPtr})
    {
        my $cpHash = $cpHashPtr->{$cp};
        my $path;

        $path = (exists $cpHash->{'imgPath'}) ? ($gDefaultPath."\\\\".$cpHash->{'imgPath'}) : ($gDefaultPath);
        replacePath($cpHash->{'Image'}, $path);
        addDesc($cpHash->{'Image'});
        delete $cpHash->{'imgPath'};

        $path = (exists $cpHash->{'adoPath'}) ? ($gDefaultPath."\\\\".$cpHash->{'adoPath'}) : ($gDefaultPath);
        replacePath($cpHash->{'Audio'}, $path);
        addDesc($cpHash->{'Audio'});
        delete $cpHash->{'adoPath'};

        $path = (exists $cpHash->{'binPath'}) ? ($gDefaultPath."\\\\".$cpHash->{'binPath'}) : ($gDefaultPath);
        replacePath($cpHash->{'Binary'}, $path);
        addDesc($cpHash->{'Binary'});
        delete $cpHash->{'binPath'};

        addDesc($cpHash->{'Color'});
        addDesc($cpHash->{'FontStyle'});
        addDesc($cpHash->{'Integer'});
    }

    # output
    open FP, ">$outputFilename" or die "Cannot open $outputFilename\n";
    print FP "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n\n";

    my $dataOut = $xml->XMLout($dataIn, RootName => "Theme");
    print FP $dataOut;

    close FP;
}


########################################
# Main Function
########################################
die "ThemeXMLDLTGen.pl <output path> <default path>\n" if ($#ARGV < 1);

$gOutputDir = shift @ARGV;
$gDefaultPath = shift @ARGV;
$gFlag = shift @ARGV if ($#ARGV != -1);

# get project and version
my $vernoFile = "$gcVernoFile";
if (-e $vernoFile)
{
    open FP, "<$vernoFile" or die "Error: Cannot open $vernoFile";
    while(<FP>)
    {
        chomp;
        $gProjectStr = "$gProjectStr$1" if (/\sbuild_branch_str.*\=\s*\"(.*)?\"/);
        $gProjectStr = "$gProjectStr($1)" if (/\sbuild_flavor_str.*\=\s*\"(.*)?\"/);
        $gVersionStr = "$1" if (/\sverno_str.*\=\s*\"(.*)?\"/);
    }
    close FP;
}

# get ID description
my $themeDesc = "$gcThemeDescFile";
if (-e $themeDesc)
{
    open FP, "<$themeDesc" or die "Error: Cannot open $themeDesc";
    while (<FP>)
    {
        chomp;
        my @test = split(/\t/);
        $gIdDescHash{$test[0]} = $test[1];
    }
    close FP;
}

# get file path
my $imgPath = "";
open FP, "<$gcImgLogFile" or die "Error: Cannot open $gcImgLogFile\n";
while(<FP>)
{
    my @test = split(/\t/);
    if ($test[5] =~ /(.*?)Images\\*(.*?)\\*MainLCD/)
    {
        $imgPath = "$1Images\\\\$2\\\\MainLCD";
        last;
    }
}
close FP;
if ($imgPath =~ /(\d+)X(\d+)/)
{
    $gLcdWidth = $1;
    $gLcdHeight = $2;
}


if ($gFlag eq "-tool")
{
    my $targetThemeFile = "VenusTheme1.xml";
    my $tempXMLFile = "$gcThmTmpFoder\\$targetThemeFile.i";
    system("$gcPreXMLTool $gcResPath\\$targetThemeFile $tempXMLFile");
    exit if ($? != 0);

    my $outputFilename = "$gOutputDir\\$targetThemeFile";
    my $subfix = "$gLcdWidth"."x"."$gLcdHeight";
    $outputFilename =~ s/\.xml/_$subfix\.xml/;

    convertFile($tempXMLFile, $outputFilename);

    exit;
}


system("$gcPreXMLTool $gcSysThemeFile $gcThmCfgFile");
exit if ($? != 0);

# parse theme configure file
use XML::Simple;
my $xml = new XML::Simple;
my $XMLData = $xml->XMLin($gcThmCfgFile, forceArray => 1);

my @gThemeArray = ();
my @gDltArray = ();
foreach(@{$XMLData->{'ThemePackage'}})
{
    if (exists $_->{'isDownloadable'})
    {
        if ($_->{'isDownloadable'} eq "TRUE")
        {
            push @gDltArray, $_->{'src'};
            next;
        }
    }
    push @gThemeArray, $_->{'src'};
}


# convert files and output ini
if ($#gDltArray >= 0)
{
    foreach(@gDltArray)
    {
        my $tempXMLFile = "$gcThmTmpFoder\\$_.i";
        system("$gcPreXMLTool $gcResPath\\$_ $tempXMLFile");
        exit if ($? != 0);

        my $outputFilename = "$gOutputDir\\$_";
        my $subfix = "$gLcdWidth"."x"."$gLcdHeight";
        $outputFilename =~ s/\.xml/_$subfix\.xml/;

        convertFile($tempXMLFile, $outputFilename);
    }
}
else
{
    my $tempXMLFile = "$gcThmTmpFoder\\$gThemeArray[0].i";
    system("$gcPreXMLTool $gcResPath\\$gThemeArray[0] $tempXMLFile");
    exit if ($? != 0);

    my $outputFilename = "$gOutputDir\\$gThemeArray[0]";
    my $subfix = "$gLcdWidth"."x"."$gLcdHeight";
    $outputFilename =~ s/\.xml/_$subfix\.xml/;

    convertFile($tempXMLFile, $outputFilename);
}

