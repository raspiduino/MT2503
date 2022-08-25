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
#   ThemeXMLOutputImageHtml.pl
#
# Description: 
# ------------
#   Parse all image_resource_usage.txt and output related image_resource_usage.htm
#       [usage] ThemeXMLOutputImageHtml.pl
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
#
#*****************************************************************************

#!/usr/bin/perl

my $gDir = "ThemeXML\\Log\\";

opendir(DIR, $gDir);
my @gLogFiles = grep(/^theme_xml_usage_.*\.log$/, readdir(DIR));
closedir(DIR);

#print "$_\n" foreach (@gLogFiles);


my %gStrList = ();
sub tableValueSorting {
    $gStrList{$a} cmp $gStrList{$b};
}

foreach my $file (@gLogFiles)
{
    my $input = $gDir.$file;
    $file =~ /^(.*?)\.log$/;
    my $output = $gDir.$1."\.html";

    open(HTMFILE, ">$output") or die "Cannot open $output";

    print STDOUT "Output $output...";

    open(LOGFILE, "<$input") or die "Cannot open $input";
    while (<LOGFILE>)
    {
        chomp;
        split(/\t/);

        $_ = uc(@_[3]);
        $respath{$_} = 1;
    }
    close(LOGFILE);

    #output html
    select HTMFILE;
print qq{
<HTML>
<HEAD></HEAD>
<BODY>

<TABLE border=2, id="mytable">
<TR>
<TD align="center"><B>Index</B></TD>
<TD align="center"><B>Image</B></TD>
<TD align="center"><B>Image ID</B></TD>
<TD align="center"><B>Size</B></TD>
<TD align="center"><B>Real Size</B></TD>
<TD align="center"><B>File path</B></TD>
<TD align="center"><B>Resource file</B></TD>
</TR>

};
	
    open(LOGFILE, "<$input") or die "Cannot open $input";
    my $idx = 0;
    my $dir = "..\\..\\..\\Images";
    my $flag = 0;
    %gStrList = ();
    while (<LOGFILE>)
	{
        chomp;
        next if (/^\s*$/);

        $flag = 2 if (/^#/);
        $flag = 1 if (/^#IMAGE/);
        next if ($flag != 1);
        next if (/^#/);

        $idx = $idx + 1;
        split(/\t/);
        $_ = uc(@_[3]);
        $rpath = $_;
        $_ = $2 if (/(\\+IMAGES)(.*?)$/);

        if (-d "$dir$_")
        {
            if (-e "$dir$_"."\\0.bmp")
            {
                $_ = $_."\\0.bmp";
            }
            if (-e "$dir$_"."\\0.pbm")
            {
                $_ = $_."\\0.bmp";
            }
            if (-e "$dir$_"."\\0.png")
            {
                $_ = $_."\\0.pnb";
            }
        }

        my $str = "<TR>";
        $str = $str."<TD><A href=\"$dir$_\">$idx</A></TD>";
        $str = $str."<TD><A href=\"$dir$_\"><img src=\"$dir$_\"/></A></TD>";
        $str = $str."<TD>@_[1]</TD>";
        if (exists $respath{$rpath})
        {
            $str = $str."<TD>@_[2]</TD><TD>@_[2]</TD>";
            delete $respath{$rpath};
        }
        else
        {
            $str = $str."<TD>@_[2]</TD><TD>0</TD>";
        }
        $str = $str."<TD>$_</TD>";
        $str = $str."<TD>$input</TD>";
        $str = $str."</TR>\n";
        #print "$str";

        $gStrList{$str} = @_[3];
	}
	close(LOGFILE);


    print "$_" foreach (sort tableValueSorting (keys %gStrList));

print qq{
</TABLE>

</BODY>
</HTML>
};

    print STDOUT "done.\n";

    # close files
    close(HTMFILE);
}
