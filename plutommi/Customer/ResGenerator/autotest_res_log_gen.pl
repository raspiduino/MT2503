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
#   autotest_res_log_gen.pl
#
# Description: 
# ------------
#   generate resource usage log file for autotest
#       autotext_res_log_gen.pl <source mcu path> <output path>
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
#  2011/05/30   Create.
#
#*****************************************************************************

#!/usr/bin/perl

my $default_path = ".";
my $output_path = ".";

if ($#ARGV >= 0)
{
    $default_path = "$ARGV[0]\\plutommi\\Customer\\ResGenerator";
    $output_path = $default_path;
}

if ($#ARGV >= 1)
{
    $output_path = "$ARGV[1]\\plutommi\\Customer\\ResGenerator";
}

my $res_log_file = "$default_path\\debug\\image_resource_usage.txt";
my $enum_log_file = "$default_path\\debug\\resgen_xml_all_enum_IDs.log";
my $theme_log_path = "$default_path\\ThemeXML\\Log\\";
my $theme_log_prefix = "theme_xml_usage_VenusTheme";

my $output_filepath = "$output_path\\autotest_resource.log";

open OUT_FP, ">$output_filepath" or die "Cannot open $output_filepath.\n";
print OUT_FP "ID\tValue\tPath\n";

# read image_resource_usage.txt
open FP, "<$res_log_file" or die "Cannot open $res_log_file.\n";
<FP>;
while (<FP>)
{
    split(/\t/);
    print OUT_FP uc(@_[3])."\t".uc(@_[2])."\t".uc(@_[5])."\n";
}
close FP;

# read enum
open FP, "<$enum_log_file" or die "Cannot open $enum_log_file.\n";
while (<FP>)
{
    $strIdHash{$1} = $2 if (/(\w*)\s*\=\s*(\d*)/);
}
close FP;

# find log in theme folder
opendir DIR, "$theme_log_path" or die "Cannot open $theme_log_path.\n";
my @theme_log_files = grep(/$theme_log_prefix/, readdir(DIR));
closedir DIR;

# read theme resource log file
foreach $theme_log (sort @theme_log_files)
{
    my $filename = $theme_log_path.$theme_log;

    open FP, "<$filename" or die "Cannot open $filename.\n";
    while (<FP>)
    {
        chomp;
        if (/^IMAGE/)
        {
            split(/\t/);
            
            print OUT_FP uc(@_[1])."\t".$strIdHash{uc(@_[1])}."\t".uc(@_[2])."\n";
        }
    }
    close FP;

    # only read the default theme
    last;
}

close OUT_FP;
