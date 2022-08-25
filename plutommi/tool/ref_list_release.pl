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
#   ref_list_release.pl
#
# Description: 
# ------------
#   clean ref_list_xxx.txt
#       [usage] ref_list_release.pl <mcu path>
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
#  2008/11/18   Create.
#
#*****************************************************************************

#!/usr/bin/perl

$path = $ARGV[0]."\\plutommi\\Customer\\CustResource\\PLUTO_MMI\\";

# generate list of ref_list_xxx.txt path
@ref_paths = glob($path."ref_list\\ref_list*.txt");
push(@ref_paths, $path."ref_list.txt");
push(@ref_paths, $path."..\\ref_list.txt");
#print $_."\n" foreach @ref_paths;

# clean each ref_list.txt
foreach $file_path (@ref_paths)
{
    #print $file_path."\n";

    # read file
    if (open($file, "<:raw:encoding(UCS-2LE):crlf", $file_path))
    {
        @lines = <$file>;
        close($file);
    
        # filter
        for ($i = 3 ; $i < scalar(@lines) ; $i++)
        {
            last if (@lines[$i] =~ /^##number/);    # end of ref_list_xxx.txt
    
            @tokens = split(/\t/, @lines[$i]);      # split by tab
            $tokens[2] = "Reserved";                # set cell to "Reserved"
            @lines[$i] = join("\t", @tokens);       # output
        }
        
        # write file
        open($file, ">:raw:encoding(UCS-2LE):crlf", $file_path);
        print $file $_ foreach @lines;
        close($file);
    }
}
