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
#   ThemeXMLDLTAutoGen.pl
#
# Description: 
# ------------
#   generate Downloadable Theme file from system theme config XML
#
#   usage:
#       ThemeXMLDLTAutoGen.pl
#       e.g. ThemeXMLDLTAutoGen
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
#  2012/01/16   Create.
#
#*****************************************************************************
#!/usr/bin/perl
use Cwd;
use strict;
use warnings;

########################################
# Global Variables
########################################
my $gcImgLogFile = "..\\debug\\image_resource_usage.txt";
my $mcuFolder = "..\\..\\..\\..";
my $dltFolder = "DLT";
my $iniTemplate = "$dltFolder\\ThemeGen.ini";
my $tempTemplate = "$dltFolder\\ThemeGen_temp.ini";

########################################
# Main Function
########################################

my $currPath = getcwd;
$currPath =~ s/\/+/\\/g;

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
$imgPath =~ s/\\+/\\/g;
$imgPath = "$currPath\\..\\$imgPath";

my $mcuPath = "$currPath\\$mcuFolder";

# subst
system("subst X: /D");
system("subst X: $imgPath");
system("subst Y: /D");
system("subst Y: $mcuPath");

system("perl ThemeXMLDLTGen.pl $dltFolder X:");

# find dlt
opendir(DIR, $dltFolder);
my @files = grep(/\.xml$/, readdir(DIR));
closedir(DIR);

foreach my $file (@files)
{
    my $prefix = $1 if $file =~ /(.*)\.xml$/;

    # gen ini
    open FPIN, "<$iniTemplate" or die;
    open FPOUT, ">$tempTemplate" or die;

    while(<FPIN>)
    {
        chomp;
        s/XXXXX/$prefix/g;
        print FPOUT "$_\n";
    }

    close FPIN;
    close FPOUT;

    # gen theme
    print STDERR "========== Generating $file ==========\n";
    chdir("..");
    system("ThemeXML\\ThemeXMLParser.pl -i ThemeXML\\$tempTemplate");
    chdir("ThemeXML");
}

# copy to modis folder
my $modisFolder = "..\\..\\..\\..\\MoDIS_VC9\\WIN32FS\\DRIVE_D";

if (-d $modisFolder)
{
    my $themeFolder = "$modisFolder\\Theme";

    unless (-d $themeFolder)
    {
        mkdir $themeFolder;
    }
    system("copy \/Y $dltFolder\\*.med $themeFolder\\*.med");
}

print STDERR "Press enter to continue...";
<STDIN>;
