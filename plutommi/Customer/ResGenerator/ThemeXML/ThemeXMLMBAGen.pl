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
#   ThemeXMLMBAGen.pl
#
# Description: 
# ------------
#   generate default theme XML file for CustPack tool
#
#   usage:
#       ThemeXMLMBAGen.pl <output directory> <mcu directory>
#       e.g. ThemeXMLMBAGen.pl Z:\custpack Z:
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
#  2011/10/05   Create.
#
#*****************************************************************************
#!/usr/bin/perl
#use strict;
#use warnings;

########################################
# Global Variables
########################################
my $gOutputDir = $ARGV[0];
my $gSourceDir = $ARGV[1];

my $gcVernoFile = "verno\\verno.c";
my $gcThemeDescFile = "plutommi\\Customer\\ResGenerator\\debug\\venus_theme_log.txt";

my $gcImgLogFile = "..\\debug\\image_resource_usage.txt";
my $gcThmTmpFoder = ".\\Temp";
my $gcThmCfgFile = "$gcThmTmpFoder\\VenusSysThemeCFG.xml.i";

my $gcIniFilename = "$gOutputDir\\VenusTheme.ini";

my $gResThemeRoot;
my $gImgRootPath;
my $gAdoRootPath = "..\\\\..\\\\Customer\\\\Audio\\\\";
my $gBinRootPath;

my $gProjectStr = "";
my $gVersionStr = "";
my $gLcdWidth = "";
my $gLcdHeight = "";

my %gIdDescHash = ();

&PrintDependency($0);

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

    my $path = $gImgRootPath."\\\\".$gResThemeRoot;
    $dataIn->{'thumbnail'} =~ s/RES_THEME_ROOT/$path/;
    $dataIn->{'preview'} =~ s/RES_THEME_ROOT/$path/;

    replacePath($dataIn->{'Image'}, $gImgRootPath);
    replacePath($dataIn->{'Audio'}, $gAdoRootPath);
    replacePath($dataIn->{'Binary'}, $gBinRootPath);

    my $cpHashPtr = $dataIn->{'Component'};
    for my $cp (sort keys %{$cpHashPtr})
    {
        my $cpHash = $cpHashPtr->{$cp};
        my $path;

        $path = (exists $cpHash->{'imgPath'}) ? ($gImgRootPath."\\\\".$cpHash->{'imgPath'}) : ($gImgRootPath);
        replacePath($cpHash->{'Image'}, $path);
        addDesc($cpHash->{'Image'});
        delete $cpHash->{'imgPath'};

        $path = (exists $cpHash->{'adoPath'}) ? ($gAdoRootPath."\\\\".$cpHash->{'adoPath'}) : ($gAdoRootPath);
        replacePath($cpHash->{'Audio'}, $path);
        addDesc($cpHash->{'Audio'});
        delete $cpHash->{'adoPath'};

        $path = (exists $cpHash->{'binPath'}) ? ($gBinRootPath."\\\\".$cpHash->{'binPath'}) : ($gBinRootPath);
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
die "ThemeXMLMBAGen.pl <output directory> <mcu directory>\n" if ($#ARGV != 1);

my $currDir = "$gSourceDir\\\\plutommi\\\\Customer\\\\ResGenerator\\\\";

# get project and version
my $vernoFile = "$gSourceDir\\$gcVernoFile";
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
my $themeDesc = "$gSourceDir\\$gcThemeDescFile";
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
open FP, "<$gcImgLogFile" or die "Error: Cannot open $gcImgLogFile\n";
while(<FP>)
{
    my @test = split(/\t/);
    if ($test[5] =~ /(.*?)Images\\*(.*?)\\*MainLCD/)
    {
        $gImgRootPath = "$1Images\\\\$2\\\\MainLCD";
        last;
    }
}
close FP;
if ($gImgRootPath =~ /(\d+)X(\d+)/)
{
    $gLcdWidth = $1;
    $gLcdHeight = $2;
}
$gImgRootPath = $currDir.$gImgRootPath;




# parse theme configure file
use XML::Simple;
my $xml = new XML::Simple;
my $xmlData = $xml->XMLin($gcThmCfgFile, forceArray => 1);

my @themeArray = ();
my @dltArray = ();
foreach(@{$xmlData->{'ThemePackage'}})
{
    if (exists $_->{'isDownloadable'})
    {
        if ($_->{'isDownloadable'} eq "TRUE")
        {
            push @dltArray, $_->{'src'};
            next;
        }
    }
    push @themeArray, $_->{'src'};
}

# convert files and output ini
open FPINI, ">$gcIniFilename" or die "Error: Cannot open $gcImgLogFile\n";
print FPINI "[Venus Theme]\n";
my $ind=0;
foreach(@themeArray)
{
    my $inputFilename = "$gcThmTmpFoder\\$_.i";
    my $outputFilename = "$gOutputDir\\$_";

    convertFile($inputFilename, $outputFilename);

    $ind++;
    print FPINI "Theme$ind = \"$outputFilename\"\n";
}
close FPINI;

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
