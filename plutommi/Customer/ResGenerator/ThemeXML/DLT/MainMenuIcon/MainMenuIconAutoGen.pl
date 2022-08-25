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
#   MainMenuIconAutoGen.pl
#
# Description: 
# ------------
#   generate MainMenu Icon Downloadable Theme file
#
#   usage:
#       MainMenuIconAutoGen.pl
#       e.g. MainMenuIconAutoGen.pl
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
#  2012/01/20   Create.
#
#*****************************************************************************
#!/usr/bin/perl
use Cwd;
use strict;
use warnings;

########################################
# Global Variables
########################################
my $gcIniTemplate = "ThemeGen_Template.ini";
my $gcIniFile = "ThemeGen.ini";
my $gcThemeTemplate = "Theme_Template.xml";
my $gcThemeXml = "Theme.xml";
my $gcResFolder = "..\\..\\..";
my $gcImgLogFile = "..\\..\\..\\debug\\image_resource_usage.txt";
my $gcVernoFile = "..\\..\\..\\..\\..\\..\\verno\\verno.c";

my $gImgPath = "";
my $gNumOfTheme = 0;
my $gProjectStr = "";
my $gVersionStr = "";
my $gLcdWidth = 0;
my $gLcdHeight = 0;

########################################
# Main Function
########################################
my $currPath = getcwd;
$currPath =~ s/\/+/\\/g;

# create ThemeGen.ini;
open FPIN, "<$gcIniTemplate" or die "Error: Cannot open $gcIniTemplate\n";
open FPOUT, ">$gcIniFile" or die "Error: Cannot open $gcIniFile\n";

my $resPath = $currPath."\\".$gcResFolder;
while(<FPIN>)
{
    chomp;
    s/YYYYY/$resPath/g;
    print FPOUT "$_\n";

    if (/^\s*(.+?)\s*=\s*\"*(.+?)\"*\s*$/)
    {
        $gImgPath = $2 if ($1 eq "IMAGE_PATH");
        $gNumOfTheme = $2 if ($1 eq "NUMBER_OF_THEME");
    }
}

close FPIN;
close FPOUT;

# get image width and height
open FP, "<$gcImgLogFile" or die "Error: Cannot open $gcImgLogFile\n";
while(<FP>)
{
    my @test = split(/\t/);
    if ($test[5] =~ /(.*?)Images\\*(.*?)\\*MainLCD/)
    {
        if ($2 =~ /(\d+)X(\d+)/)
        {
            $gLcdWidth = $1;
            $gLcdHeight = $2;
        }
        last;
    }
}
close FP;

# get project and version
if (-e $gcVernoFile)
{
    open FP, "<$gcVernoFile" or die "Error: Cannot open $gcVernoFile";
    while(<FP>)
    {
        chomp;
        $gProjectStr = "$gProjectStr$1" if (/\sbuild_branch_str.*\=\s*\"(.*)?\"/);
        $gProjectStr = "$gProjectStr($1)" if (/\sbuild_flavor_str.*\=\s*\"(.*)?\"/);
        $gVersionStr = "$1" if (/\sverno_str.*\=\s*\"(.*)?\"/);
    }
    close FP;
}

# create Theme.xml;
open FPIN, "<$gcThemeTemplate" or die "Error: Cannot open $gcThemeTemplate\n";
open FPOUT, ">$gcThemeXml" or die "Error: Cannot open $gcThemeXml\n";

while(<FPIN>)
{
    chomp;
    s/YYYYY/$gImgPath/g;
    if (/^\s*<Theme/)
    {
        s/project=\"\"/project=\"$gProjectStr\"/g;
        s/version=\"\"/version=\"$gVersionStr\"/g;
        s/width=\"\"/width=\"$gLcdWidth\"/g;
        s/height=\"\"/height=\"$gLcdHeight\"/g;
    }
    print FPOUT "$_\n";
}

close FPIN;
close FPOUT;

my $themeIni = "temp.ini";
for (my $themeIdx = 1 ; $themeIdx <= $gNumOfTheme ; $themeIdx++)
{
    my $themeStr = sprintf "Theme_%02d", $themeIdx;

    open FPIN, "<$gcIniFile" or die "Error: Cannot open $gcIniFile\n";
    open FPOUT, ">$themeIni" or die "Error: Cannot open $themeIni\n";

    while(<FPIN>)
    {
        chomp;
        s/XXXXX/$themeStr/g;
        print FPOUT "$_\n";
    }

    close FPINI;
    close FPOUT;

    open FPIN, "<$gcThemeXml" or die "Error: Cannot open $gcThemeXml\n";
    open FPOUT, ">$themeStr.xml" or die "Error: Cannot open $themeStr.xml\n";

    while(<FPIN>)
    {
        chomp;
        s/XXXXX/$themeStr/g;
        print FPOUT "$_\n";
    }

    close FPINI;
    close FPOUT;

    print STDERR ("========== Generating $themeStr ==========\n");
    chdir("..\\..\\..");
    system("ThemeXML\\ThemeXMLParser.pl -i ThemeXML\\DLT\\MainMenuIcon\\$themeIni");
    chdir("ThemeXML\\DLT\\MainMenuIcon");
}

print STDERR "Press enter to continue...";
<STDIN>;
