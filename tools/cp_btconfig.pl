#!/usr/bin/env perl
# 
# Copyright Statement:
# --------------------
# This software is protected by Copyright and the information contained
# herein is confidential. The software may not be copied and the information
# contained herein may not be used or disclosed except with the written
# permission of MediaTek Inc. (C) 2005
# 
# BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
# NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
# SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
# 
# BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
# LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
# 
# THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
# WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
# LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
# RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
# THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
# 
#****************************************************************************/
#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
use File::Path;

($#ARGV != 1) && &Usage;
my $dest_folder = $ARGV[0]; # The destination folder
my $board_ver   = $ARGV[1]; # The board version

if (!-e $dest_folder) {
	mkpath($dest_folder) or &error_handler("Create $dest_folder failed. $!", __FILE__, __LINE__);
}

my @files = qw(
custom\\common\\hal\\nvram\\custom_nvram_lid_cat.xml
custom\\common\\nvram_input_event_cfg.h
custom\\common\\nvram_input_event_cfg_desc.txt
plutommi\\customer\\custresource\\mmi_cache_table.c
);
push @files,"custom\\system\\${board_ver}\\custom_memorydevice.h";

my $re_code = 0;
foreach my $f (@files) {
	print "Copying $f ...\n";
	if (!-e "$f") {
		warn "[WARN] could not find $f\n";
		next;
	}
	if (-d $f) {
		print "xcopy /q /e /y $f $dest_folder\\*.* \n";
		$re_code = system("xcopy /q /e /y $f $dest_folder\\*.* > nul");
	} elsif (-e $f) {
		print "xcopy /q /y $f $dest_folder\\$f\\ \n";
		$re_code = system("xcopy /q /y $f $dest_folder\\ > nul");
	}
	warn "[WARN] copy $f failed\n" if ($re_code>>8);
 }

exit 0;

#****************************************************************************
# subroutine: Usage
#****************************************************************************
sub Usage {
  warn << "__END_OF_USAGE";
Usage:
  perl cp_btconfig.pl destination_directory board_version
__END_OF_USAGE
  exit 1;
}


#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no) = @_;
    
    my $final_error_msg = "ERROR: $error_msg at $file line $line_no\n";
    print $final_error_msg;
    die $final_error_msg;
}
