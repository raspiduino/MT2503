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
#   get_resname_for_CustMenuTreeID_Out_c.pl
#
# Description: 
# ------------
#   get res_xxx.c filename for CustMenuTreeID_Out.c
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
#  2008/06/25   Create.
#
#*****************************************************************************

#!/usr/bin/perl


# check arguments
die "\nget_resname_for_CustMenuTreeID_Out_c.pl \<CustMenuTreeID_Out.c\> \<menu_resource_usage.txt\> \<output file\>\n" if (@ARGV != 3);

# open files
open(IDFILE, "<$ARGV[0]") or die "Cannot open $ARGV[0]";
open(MUFILE, "<$ARGV[1]") or die "Cannot open $ARGV[1]";
open(OUFILE, ">$ARGV[2]") or die "Cannot open $ARGV[2]";

# extract values
while (<IDFILE>)
{
    if (/ADD_APPLICATION_MENUITEM2([ \(]*)(.*?)([ \)]*)([ ;]*)$/)
    {
        $_ = $2;                        # matched menu tree content
        split(/,/);                     # split ","
        push(@ids, @_[0]);              # store the name
    }
}

# extract filenames
while (<MUFILE>)                            # parse menu_resource_usage.txt
{
    split(/\t/);                            # split tab
    @_[6] =~ s/\.\.\/Res_MMI\///g;          # remove "../Res_MMI/"
    @_[6] =~ s/\n//g;          # remove "../Res_MMI/"
    $id_filename_hash{@_[2]} = @_[6];       # mapping table of ID and filename
}

# output filename
for (0..(scalar(@ids) - 1))
{
    if (defined $id_filename_hash{$ids[$_]})
    {
        print OUFILE $id_filename_hash{$ids[$_]}."\n";
    }
    else
    {
        print OUFILE "unknown"."\n";
    }
}

# close files
close(IDFILE);
close(MUFILE);
close(OUFILE);
