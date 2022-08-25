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
#   copy_ref_list.pl
#
# Description: 
# ------------
#   copy all ref_list_xxx.txt, independent of project
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
#  2011/03/24   Create.
#
#*****************************************************************************

#!/usr/bin/perl

my @res_range_header = ("..\\..\\MMI\\Inc\\mmi_res_range_def.h",
                        "..\\..\\MMI\\Inc\\mmi_pluto_res_range_def.h",
                        "..\\..\\MMI\\Inc\\mmi_lib_res_range_def.h",
                        "..\\..\\..\\venusmmi\\app\\common\\interface\\vapp_res.h",
                        "..\\..\\..\\venusmmi\\app\\cosmos\\interface\\app\\vapp_package_res.h",
                       );

my @path_pattern = ("RESOURCE_BASE_TABLE_ITEM_PATH",
                    "MMI_RES_DECLARE",
                    "VFX_APP_RES_DECLARE",
                   );

my $dst_folder = ".\\temp\\ref_list\\";

my %path_hash = ();

&PrintDependency($0);

foreach my $f (@res_range_header)
{
    open FILE, "<$f";
    &PrintDependency($f);
    while(<FILE>)
    {
        # search pattern
        foreach my $p (@path_pattern)
        {
            if (/^\s*$p/)
            {
                # search "..."
                if (/\"(.*)\"/)
                {
                    # skip null path
                    if (length($1) > 0)
                    {
                        #print "$1\n";
                        $path_hash{"..\\\\..\\\\$1"} = 1;
                    }
                }
                last;
            }
        }
    }
    close(FILE);
}

#print "$_\n" foreach(sort keys(%path_hash));
foreach(sort keys(%path_hash))
{
    my $cmd = "xcopy \"$_\\ref_list*.txt\" $dst_folder /y/D > null 2>&1";
    $cmd =~ s/\\+/\\/g;
    #print "$cmd\n";
    system($cmd);
    while (my $file = <$_\\ref_list*.txt>)
    {
        &PrintDependency($file);
    }
}

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
