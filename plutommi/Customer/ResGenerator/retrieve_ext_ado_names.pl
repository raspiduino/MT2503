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
#   retrieve_ext_img_names.pl
#
# Description: 
# ------------
#   Retrieve the names and file path of those images which will be put into CustPack.
#   This is only for CustPack.ini usage.
#       [usage] retrieve_ext_img_names.pl <default directory>
#
# Auther: 
# -------
#   Fred Shen
# 
# Note:
# -----
#
# Log: 
# -----
#  2007/03/23   Create.
#
#*****************************************************************************

#!/usr/bin/perl

# open files
&PrintDependency($0);

open(INFILE, "<..\\CustResource\\CustAdoResExt.c") or die "Cannot open CustAdoResExt.c.";
open(LOGFILE, "<.\\debug\\audio_resource_usage.txt") or die "Cannot open audio_resource_usage.txt";
open(OUTFILE, ">..\\CustResource\\CustAdoNamesExt") or die "Cannot open CustAdoNamesExt";

# get default directory
$default_dir = "plutommi\\"; #$ARGV[0];

# construct hash table, mapping from variables to real file paths
#   eg. [__MAINLCD__ACTIVE__POWERONOFF__LOGO] = "(default directory)\MAINLCD\ACTIVE\POWERONOFF\LOGO.BMP"
while (<LOGFILE>)                           # parse image_resource_usage.txt
{
    chomp;
    split(/\t/);                            # split tab
    $_ = uc(@_[5]);                         # get file path and convert it to upper case
    $file_path = $_;                        # get file path
    
# Since current symbol name of audio data has ________CUSTOMER__audio__prefix,
# the handling scripts of stripping "Customer\\audio" is removed
#    ==========================REMOVED START =============================
#        $_ = $1 if (/(\\\\PLUTO.*?)$/);       # get sub-string from \\MAINLCD
#        $file_path =~ s/\.\.\\+CUSTOMER\\+AUDIO//g;
#    ========================== REMOVED END  ==============================

    $file_path = $default_dir.$file_path;   # append default directory at front
    $file_path =~ s/\\+/\\/g;               # replace "\\" to "\"
    $file_path =~ s/\.\.\\//g;                 # remove ..\\..\\
    $_ = $1 if (/^(.*)\.({MP3|IMY|MID|WAV|MMF|PCM|DVI|AMR|AAC|WMA|M4A})$/i);           # remove extention file name
    s/[\\\. -]/\_/g;                        # replace from "\", ".", " ", "-" to "_"
    $var_name_hash{$_} = $file_path;        # put variable name with file path into hash table
}

# output mapping table with variables and file paths
#   eg. __MAINLCD__ACTIVE__POWERONOFF__LOGO_BMP_ = "(default directory)\MAINLCD\ACTIVE\POWERONOFF\LOGO.BMP"
while (<INFILE>)                            # output CustImgNamesExt
{
    if (/\(U8\*\)\&(.*?),/i)                # retrieve variable names
    {
        $var_name = $_ = $1;                # get variable name
        $_ = $1 if (/^(.*)_/);              # remove the last "_"
        $_ = $1 if (/^(.*)_({MP3|IMY|MID|WAV|MMF|PCM|DVI|AMR|AAC|WMA|M4A})$/i);        # remove extention file name
        if (defined $var_name_hash{$_})     # output file path if exists
        {
            print OUTFILE $var_name." = \"".$var_name_hash{$_}."\"\n";
        }
        else                                # not found in hash table
        {                                   # output fake file path
            $_ = $var_name;                 # get variable name
            $_ = $1 if (/^(.*)_/);          # remove the last "_"
            s/^(.*)_(...)$/$1.$2/;          # convert variable name into file path for extention name
            s/__/\\\\/g;                    # convert variable name into file path for file directory
            $file_path = $default_dir.$_;   # append default directory at front
            $file_path =~ s/\\+/\\/g;       # replace "\\" to "\"
            print OUTFILE $var_name." = \"".$file_path."\"\n";
        }
    }
    
}

# close files
close(OUTFILE);
close(LOGFILE);
close(INFILE);

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
