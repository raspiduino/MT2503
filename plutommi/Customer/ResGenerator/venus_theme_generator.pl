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
#   venus_theme_generator.pl
#
# Description: 
# ------------
#   generator Venus system theme file
#       [usage] venus_theme_generator.pl
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
#  2010/08/05   Create.
#
#*****************************************************************************

#!/usr/bin/perl
#use strict;
#use warnings;

########################################
# Constant
########################################
my $gcLog           = "[ThemeGen]";
my $gcErrorInfo     = "$gcLog Please read venus_theme_generator.log for detail information.\n";
my $gcErrorHeader   = "#error \"venug_theme_generator got error. Please check venus_theme_generator.log first.\"";

my $gcLogPath       ="debug";
my $gcResPath       ="..\\CustResource";

my $gIsThirdRom     = "FALSE";
my $gcOptionFile    = "custom_option.txt";
my $gcResLogFile    = "$gcLogPath\\venus_theme_log.txt";
my $gcResIdFile     = "$gcLogPath\\resgen_xml_all_enum_IDs.log";

my $gcThemeIdFile   = "$gcResPath\\CustVenusThemeId.h";
my $gcThemeDataFile = "$gcResPath\\CustVenusThemeData.h";

my $gcAppIconFile   = "$gcResPath\\CustVenusAppIconData.h";

my $gcSysThemeFile  = "$gcResPath\\VenusSysThemeCFG.xml";
#&PrintDependency($gcSysThemeFile);

my $gcPlutoAppIcon1  = "$gcResPath\\PlutoAppIcon1.xml";


my $gcPreXMLTool    = "..\\..\\..\\tools\\python25\\python.exe ..\\..\\..\\tools\\py\\prexml.py";
#&PrintDependency("..\\..\\..\\tools\\py\\prexml.py");
my $gcXMLParser     = "ThemeXML\\ThemeXMLParser.pl";
#&PrintDependency($gcXMLParser);

my $gcThemeXMLPath   = "ThemeXML";
my $gcThemeXMLTempPath  = "$gcThemeXMLPath\\Temp";
my $gcThemeBinFile = "$gcThemeXMLTempPath\\CustEnfbVenusThemeData";
my $gcAppIconBinFile = "$gcThemeXMLTempPath\\CustEnfbVenusAppIconData";
my $gcThemeXMLLogPath   = "$gcThemeXMLPath\\Log";
my $gcThemeXMLLogFile   = "$gcThemeXMLLogPath\\venus_theme_generator.log";
#&PrintDependency($0);

########################################
# Global Variables
########################################
my %gImgStrIdHash = ();
my %gColStrIdHash = ();
my %gFntStrIdHash = ();
my %gIntStrIdHash = ();
my %gAdoStrIdHash = ();
my %gBinStrIdHash = ();


########################################
# Function: calculate the hash value of string
#   str     : [IN] input string
########################################
sub hashString
{
    my $str = shift;
    my $value = 0;

    $value += ord($_) foreach split(//, $str);

    return $value % 255;
}


########################################
# Function: print log
#   str     : [IN] log string
########################################
sub printLog
{
    my $str = shift;

    print STDERR "$str\n";
    system("echo $str >> $gcThemeXMLLogFile");
}


########################################
# Function: exit with error
########################################
sub myExit
{
    # create error header
    open FP, ">$gcThemeIdFile" or die "$gcLog Error: Cannot open $gcThemeIdFile.\n";
    print FP "$gcErrorHeader";
    close FP;

    open FP, ">$gcThemeDataFile" or die "$gcLog Error: Cannot open $gcThemeDataFile.\n";
    print FP "$gcErrorHeader";
    close FP;

    open FP, ">$gcAppIconFile" or die "$gcLog Error: Cannot open $gcAppIconFile.\n";
    print FP "$gcAppIconFile";
    close FP;

    exit -1;
}


########################################
# Main Function
########################################

# create files
open FP, ">$gcThemeXMLLogFile" or die "$gcLog Error: Cannot open $gcThemeXMLLogFile.\n";
close FP;

&PrintDependency($gcPlutoAppIcon1);
printLog("$gcLog Load $gcSysThemeFile");

# pre-process system theme config file
my $tempXMLFile = "$gcThemeXMLTempPath\\VenusSysThemeCFG.xml.i";
system("$gcPreXMLTool $gcSysThemeFile $tempXMLFile >> $gcThemeXMLLogFile 2>&1");
if ($? != 0)
{
    printLog("Error [$?]: $gcSysThemeFile preprocess error.");
    print STDERR $gcErrorInfo;
    myExit();
}


# load system theme config XML
use XML::Simple;
my $xml = new XML::Simple;
my $XMLData = $xml->XMLin($tempXMLFile, forceArray => 1);

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

my @gAppIconArray = ();
foreach(@{$XMLData->{'AppIconPackage'}})
{
    push @gAppIconArray, $_->{'src'};
}


printLog("$gcLog Load $gcResLogFile");

# load theme resource IDs
my $pStrIdHash;
my %dummy = ();
open FP, "<$gcResLogFile" or die "$gcLog Error: Cannot open $gcResLogFile";
while(<FP>)
{
    if (/^\[(\w*)\]$/)
    {
        #print STDERR $1."\n";
        $pStrIdHash = \%dummy;
        $pStrIdHash = \%gImgStrIdHash if ($1 eq "RP_IMAGE");
        $pStrIdHash = \%gColStrIdHash if ($1 eq "RP_COLOR");
        $pStrIdHash = \%gFntStrIdHash if ($1 eq "RP_FONTSTYLE");
        $pStrIdHash = \%gIntStrIdHash if ($1 eq "RP_INTEGER");
        $pStrIdHash = \%gAdoStrIdHash if ($1 eq "RP_AUDIO");
        $pStrIdHash = \%gBinStrIdHash if ($1 eq "RP_BINARY");
        next;
    }
    else
    {
        my @test = split(/\t/);
        #print STDERR $test[0]."\n";
        $pStrIdHash->{$test[0]} = 0;
    }
}
close FP;


printLog("$gcLog Load $gcResIdFile");

# load ID enum values
my %strIdHash = ();
open FP, "<$gcResIdFile" or die "$gcLog Error: Cannot open $gcResLogFile";
while(<FP>)
{
    $strIdHash{$1} = $2 if (/(\w*)\s*\=\s*(\d*)/);
}
close FP;


# map ID string and enum values
$gImgStrIdHash{$_} = ($strIdHash{$_}) ? ($strIdHash{$_}) : (0) foreach(keys %gImgStrIdHash);
$gColStrIdHash{$_} = ($strIdHash{$_}) ? ($strIdHash{$_}) : (0) foreach(keys %gColStrIdHash);
$gFntStrIdHash{$_} = ($strIdHash{$_}) ? ($strIdHash{$_}) : (0) foreach(keys %gFntStrIdHash);
$gIntStrIdHash{$_} = ($strIdHash{$_}) ? ($strIdHash{$_}) : (0) foreach(keys %gIntStrIdHash);
$gAdoStrIdHash{$_} = ($strIdHash{$_}) ? ($strIdHash{$_}) : (0) foreach(keys %gAdoStrIdHash);
$gBinStrIdHash{$_} = ($strIdHash{$_}) ? ($strIdHash{$_}) : (0) foreach(keys %gBinStrIdHash);


printLog("$gcLog Output $gcThemeIdFile");

####################################################################################################
# output CustVenusThemeId.h
####################################################################################################
open FP, ">$gcThemeIdFile" or die "$gcLog Error: Cannot open $gcThemeIdFile";
print FP "/\* This file is automatically generated by venus_theme_generator.pl. Do not modify it. \*/\n\n";
print FP "#ifndef __CUST_VENUS_THEME_ID_H__\n";
print FP "#define __CUST_VENUS_THEME_ID_H__\n";
print FP "\n";
print FP "typedef struct\n{\tU8 hash_value;\n\tU16 id;\n\tconst U8* str;\n} mmi_res_thm_id_str_tbl_struct;\n";
print FP "\n";
print FP "#define MMI_RES_THM_ALL_IMG_IDS ".scalar(keys %gImgStrIdHash)."\n";
print FP "#define MMI_RES_THM_ALL_COL_IDS ".scalar(keys %gColStrIdHash)."\n";
print FP "#define MMI_RES_THM_ALL_FNT_IDS ".scalar(keys %gFntStrIdHash)."\n";
print FP "#define MMI_RES_THM_ALL_INT_IDS ".scalar(keys %gIntStrIdHash)."\n";
print FP "#define MMI_RES_THM_ALL_ADO_IDS ".scalar(keys %gAdoStrIdHash)."\n";
print FP "#define MMI_RES_THM_ALL_BIN_IDS ".scalar(keys %gBinStrIdHash)."\n";
print FP "\n";
print FP "static const U8 g_mmi_res_thm_".lc($_)."_str[] = \"$_\";\n" foreach(sort keys %gImgStrIdHash);
print FP "static const U8 g_mmi_res_thm_".lc($_)."_str[] = \"$_\";\n" foreach(sort keys %gColStrIdHash);
print FP "static const U8 g_mmi_res_thm_".lc($_)."_str[] = \"$_\";\n" foreach(sort keys %gFntStrIdHash);
print FP "static const U8 g_mmi_res_thm_".lc($_)."_str[] = \"$_\";\n" foreach(sort keys %gIntStrIdHash);
print FP "static const U8 g_mmi_res_thm_".lc($_)."_str[] = \"$_\";\n" foreach(sort keys %gAdoStrIdHash);
print FP "static const U8 g_mmi_res_thm_".lc($_)."_str[] = \"$_\";\n" foreach(sort keys %gBinStrIdHash);
print FP "\n";
print FP "static const mmi_res_thm_id_str_tbl_struct g_mmi_res_thm_img_id_str_tbl[] =\n{\n";
print FP "\t{".hashString($_).", $gImgStrIdHash{$_}, g_mmi_res_thm_".lc($_)."_str},\n" foreach (sort {$gImgStrIdHash {$a} <=> $gImgStrIdHash {$b}} keys %gImgStrIdHash);
print FP "\t{0, 0, NULL},\n" if (scalar(keys %gImgStrIdHash) == 0);
print FP "};\n";
print FP "\n";
print FP "static const mmi_res_thm_id_str_tbl_struct g_mmi_res_thm_col_id_str_tbl[] =\n{\n";
print FP "\t{".hashString($_).", $gColStrIdHash{$_}, g_mmi_res_thm_".lc($_)."_str},\n" foreach (sort {$gColStrIdHash {$a} <=> $gColStrIdHash {$b}} keys %gColStrIdHash);
print FP "\t{0, 0, NULL},\n" if (scalar(keys %gColStrIdHash) == 0);
print FP "};\n";
print FP "\n";
print FP "static const mmi_res_thm_id_str_tbl_struct g_mmi_res_thm_fnt_id_str_tbl[] =\n{\n";
print FP "\t{".hashString($_).", $gFntStrIdHash{$_}, g_mmi_res_thm_".lc($_)."_str},\n" foreach (sort {$gFntStrIdHash {$a} <=> $gFntStrIdHash {$b}} keys %gFntStrIdHash);
print FP "\t{0, 0, NULL},\n" if (scalar(keys %gFntStrIdHash) == 0);
print FP "};\n";
print FP "\n";
print FP "static const mmi_res_thm_id_str_tbl_struct g_mmi_res_thm_int_id_str_tbl[] =\n{\n";
print FP "\t{".hashString($_).", $gIntStrIdHash{$_}, g_mmi_res_thm_".lc($_)."_str},\n" foreach (sort {$gIntStrIdHash {$a} <=> $gIntStrIdHash {$b}} keys %gIntStrIdHash);
print FP "\t{0, 0, NULL},\n" if (scalar(keys %gIntStrIdHash) == 0);
print FP "};\n";
print FP "\n";
print FP "static const mmi_res_thm_id_str_tbl_struct g_mmi_res_thm_ado_id_str_tbl[] =\n{\n";
print FP "\t{".hashString($_).", $gAdoStrIdHash{$_}, g_mmi_res_thm_".lc($_)."_str},\n" foreach (sort {$gAdoStrIdHash {$a} <=> $gAdoStrIdHash {$b}} keys %gAdoStrIdHash);
print FP "\t{0, 0, NULL},\n" if (scalar(keys %gAdoStrIdHash) == 0);
print FP "};\n";
print FP "\n";
print FP "static const mmi_res_thm_id_str_tbl_struct g_mmi_res_thm_bin_id_str_tbl[] =\n{\n";
print FP "\t{".hashString($_).", $gBinStrIdHash{$_}, g_mmi_res_thm_".lc($_)."_str},\n" foreach (sort {$gBinStrIdHash {$a} <=> $gBinStrIdHash {$b}} keys %gBinStrIdHash);
print FP "\t{0, 0, NULL},\n" if (scalar(keys %gBinStrIdHash) == 0);
print FP "};\n";
print FP "\n";
print FP "#endif /* __CUST_VENUS_THEME_ID_H__ */";
close FP;


####################################################################################################
# output theme data
####################################################################################################

open OPTIONF, "<$gcOptionFile" or die "$gcLog Error: Could not open $gcOptionFile.\n";
while (<OPTIONF>)
{
    chomp;
    if ((/__COSMOS_MMI_PACKAGE__/) && (/__NFB_THIRD_ROM_SUPPORT__/))
    {
        $gIsThirdRom = "TRUE";
        last;
    }
}
close OPTIONF;

printLog("$gcLog Read option $gIsThirdRom");

# create theme binary file
if ($gIsThirdRom eq "TRUE")
{
    open FP, ">$gcThemeBinFile" or die "$gcLog Error: Cannot open $gcThemeBinFile.\n";
    close FP;
}

open OUTF, ">..\\CustResource\\CustVenusThemeData.h" or die "$gcLog Error: Cannot open CustVenusThemeData.h";
select OUTF;

print "/\* This file is automatically generated by venus_theme_generator.pl. Do not modify it. \*/\n";
if ($gIsThirdRom eq "TRUE")
{
    print "#ifndef __CUST_VENUS_THEME_DATA_H__\n";
    print "#define __CUST_VENUS_THEME_DATA_H__\n";
    print "\n";
    print "typedef struct\n{\tU32 offset;\n\tU32 length;\n} mmi_res_thm_attr_struct;\n";
    print "\n";
}
else
{
    print qq{
    #if !defined(__MTK_TARGET__)
    #define __align(x)
    #endif /* !defined(__MTK_TARGET__) */
    };
}

my %gThemeArrayName = ();
my %gThemeOffsetArray = ();
my %gThemeLengthArray = ();
my $offset = 0;
foreach(@gThemeArray)
{
    my $tempXMLFile = "$gcThemeXMLTempPath\\$_.i";
    system("$gcPreXMLTool $gcResPath\\$_ $tempXMLFile >> $gcThemeXMLLogFile 2>&1");
    &PrintDependency("$gcResPath\\$_");
    if ($? != 0)
    {
        printLog("Error [$?]: $_ preprocess error.");
        print STDERR $gcErrorInfo;
        myExit();
    }

    my $command = "perl $gcXMLParser $tempXMLFile $gcThemeXMLTempPath\\$_.bin";
    printLog("$gcLog $command");
    system("$command >> $gcThemeXMLLogFile 2>&1");
    if ($? != 0)
    {
        printLog("Error [$?]: $tempXMLFile parse error.");
        print STDERR $gcErrorInfo;
        myExit();
    }

    open INF, "<$gcThemeXMLTempPath\\$_.bin";
    binmode INF;

    if ($gIsThirdRom eq "TRUE")
    {
        open OUTBIN, ">>$gcThemeBinFile" or die "$gcLog Error: Cannot open $gcThemeBinFile.\n";
        binmode OUTBIN;

        printLog("$gcLog Output binary of $_");

        $gThemeOffsetArray{$_} = $offset;
    }
    else
    {
        printLog("$gcLog Output array of $_");
        my $name = lc("mmi_thm_data_$_");
        $name =~ s/\./_/g;
        $gThemeArrayName{$_} = $name;
        print "\n\n__align(4) static const U8 $name [] = \{\n";
    }

    my $count = 0;
    while (!eof(INF))
    {
        $count++;

        my $buf;

        read(INF, $buf, 1);
        if ($gIsThirdRom eq "TRUE")
        {
            print OUTBIN $buf;
        }
        else
        {
            printf "0x%02X, ", ord($buf);

            print "\n" if (!($count % 32));
        }
    }

    if ($gIsThirdRom eq "TRUE")
    {
        $gThemeLengthArray{$_} = $count;
        $offset += $count;

        close OUTBIN;
    }
    else
    {
        print "\n};\n";
    }

    close INF;
}

print "\n\n#define MMI_VENUS_THEME_TOTAL_COUNT ".scalar(@gThemeArray)."\n";
if (scalar(@gThemeArray) == 0)
{
    if ($gIsThirdRom eq "TRUE")
    {
        print "\n\nstatic const mmi_res_thm_attr_struct g_mmi_res_thm_attr_array [] = \{\n";
        print "\t{0, 0},\n";
    }
    else
    {
        print "\n\n__align(4) static const U8* const g_mmi_venus_theme_data_array [] = \{\n";
        print "\t(U8*)0\n";
    }
}
else
{
    if ($gIsThirdRom eq "TRUE")
    {
        print "\n\nstatic const mmi_res_thm_attr_struct g_mmi_res_thm_attr_array [MMI_VENUS_THEME_TOTAL_COUNT] = \{\n";
        print "\t{$gThemeOffsetArray{$_}, $gThemeLengthArray{$_}},\n" foreach (@gThemeArray);
    }
    else
    {
        print "\n\n__align(4) static const U8* const g_mmi_venus_theme_data_array [MMI_VENUS_THEME_TOTAL_COUNT] = \{\n";
        print "\t(U8*)$gThemeArrayName{$_},\n" foreach (@gThemeArray);
    }
}
print "\};\n\n";
if ($gIsThirdRom eq "TRUE")
{
    print "#endif /* __CUST_VENUS_THEME_DATA_H__ */";
}

close OUTF;


####################################################################################################
# output app icon data
####################################################################################################

# create app icon binary file
if ($gIsThirdRom eq "TRUE")
{
    open FP, ">$gcAppIconBinFile" or die "$gcLog Error: Cannot open $gcAppIconBinFile.\n";
    close FP;
}

open OUTF, ">$gcAppIconFile" or die "$gcLog Error: Cannot open $gcAppIconFile";
select OUTF;

print "/\* This file is automatically generated by venus_theme_generator.pl. Do not modify it. \*/\n";
if ($gIsThirdRom eq "TRUE")
{
    print "#ifndef __CUST_VENUS_APP_ICON_DATA_H__\n";
    print "#define __CUST_VENUS_APP_ICON_DATA_H__\n";
    print "\n";
    print "typedef struct\n{\tU32 offset;\n\tU32 length;\n} mmi_res_app_icon_attr_struct;\n";
    print "\n";
}
else
{
    print qq{
    #if !defined(__MTK_TARGET__)
    #define __align(x)
    #endif /* !defined(__MTK_TARGET__) */
    };
}

my %gAppIconArrayName = ();
my %gAppIconOffsetArray = ();
my %gAppIconLengthArray = ();
my $offset = 0;
foreach(@gAppIconArray)
{
    my $tempXMLFile = "$gcThemeXMLTempPath\\$_.i";
    system("$gcPreXMLTool $gcResPath\\$_ $tempXMLFile >> $gcThemeXMLLogFile 2>&1");
    if ($? != 0)
    {
        printLog("Error [$?]: $_ preprocess error.");
        print STDERR $gcErrorInfo;
        myExit();
    }

    my $command = "perl $gcXMLParser $tempXMLFile $gcThemeXMLTempPath\\$_.bin";
    printLog("$gcLog $command");
    system("$command >> $gcThemeXMLLogFile 2>&1");
    if ($? != 0)
    {
        printLog("Error [$?]: $tempXMLFile parse error.");
        print STDERR $gcErrorInfo;
        myExit();
    }

    open INF, "<$gcThemeXMLTempPath\\$_.bin";
    binmode INF;

    if ($gIsThirdRom eq "TRUE")
    {
        open OUTBIN, ">>$gcAppIconBinFile" or die "$gcLog Error: Cannot open $gcAppIconBinFile.\n";
        binmode OUTBIN;
    
        printLog("$gcLog Output binary of $_");

        $gAppIconOffsetArray{$_} = $offset;
    }
    else
    {
        printLog("$gcLog Output array of $_");
        my $name = lc("mmi_app_icon_data_$_");
        $name =~ s/\./_/g;
        $gAppIconArrayName{$_} = $name;
        print "\n\n__align(4) static const U8 $name [] = \{\n";
    }

    my $count = 0;
    while (!eof(INF))
    {
        $count++;

        my $buf;

        read(INF, $buf, 1);
        if ($gIsThirdRom eq "TRUE")
        {
            print OUTBIN $buf;
        }
        else
        {
            printf "0x%02X, ", ord($buf);

            print "\n" if (!($count % 32));
        }
    }

    if ($gIsThirdRom eq "TRUE")
    {
        $gAppIconLengthArray{$_} = $count;
        $offset += $count;

        close OUTBIN;
    }
    else
    {
        print "\n};\n";
    }

    close INF;
}

print "\n\n#define MMI_VENUS_APP_ICON_TOTAL_COUNT ".scalar(@gAppIconArray)."\n";
if (scalar(@gAppIconArray) == 0)
{
    if ($gIsThirdRom eq "TRUE")
    {
        print "\n\nstatic const mmi_res_app_icon_attr_struct g_mmi_res_app_icon_attr_array [] = \{\n";
        print "\t{0, 0},\n"; 
    }
    else
    {
        print "\n\n__align(4) static const U8* const g_mmi_venus_app_icon_data_array [] = \{\n";
        print "\t(U8*)0\n";
    }
}
else
{
    if ($gIsThirdRom eq "TRUE")
    {
        print "\n\nstatic const mmi_res_app_icon_attr_struct g_mmi_res_app_icon_attr_array [MMI_VENUS_APP_ICON_TOTAL_COUNT] = \{\n";
        print "\t{$gAppIconOffsetArray{$_}, $gAppIconLengthArray{$_}},\n" foreach (@gAppIconArray);
    }
    else
    {
        print "\n\n__align(4) static const U8* const g_mmi_venus_app_icon_data_array [MMI_VENUS_APP_ICON_TOTAL_COUNT] = \{\n";
        print "\t(U8*)$gAppIconArrayName{$_},\n" foreach (@gAppIconArray);
    }
}
print "\};\n\n";
if ($gIsThirdRom eq "TRUE")
{
    print "#endif /* __CUST_VENUS_APP_ICON_DATA_H__ */";
}

close OUTF;

system("perl ThemeXML\\ThemeXMLOutputImageHtml.pl");

printLog("$gcLog System Theme generate completely");

sub PrintDependency
{
	my $file = shift;
	if (-e $file)
	{
		my $path = Win32::GetCwd() . "\\" . $file;
		$path =~ s/\//\\/g;
		print STDOUT "[Dependency] $path\n";
		system("echo [Dependency] $path >> $gcThemeXMLLogFile");
	}
}
