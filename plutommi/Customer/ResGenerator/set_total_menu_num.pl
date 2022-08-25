#!/usr/bin/perl
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
# Filename: 
# ---------
#  set_total_menu_num.pl
#
# Description: 
# ------------
#  
#
# Auther: 
# -------
#  Kun Liu
# 
# Note:
# -----
#  none.
#
# Log: 
# -----
#  2007/12/20   Create.
#


#******************************************************************************
# Program Start
#******************************************************************************

#####################################
# Get the current working directory #
#####################################

use Cwd; 
my $cur_dir = getcwd();

# Replace the '/' to '\'
$cur_dir =~ tr/\//\\/;

&PrintDependency($0);

# Check the path's validity, confirm the script is running in the 
# directory mcu\plutommi\Customer

if (!($cur_dir =~ /\\plutommi\\Customer\\ResGenerator/i))
{
	 die "[ERROR] This script should running in the mcu\\plutommi\\Customer\\ResGenerator \n";
}


########################################
# Count the number of total menu items #
########################################

my $file_cust_menu_tree_id_c = $cur_dir;
$file_cust_menu_tree_id_c =~ s/\\plutommi\\Customer\\ResGenerator/\\plutommi\\customer\\custresource\\CustMenuTreeID_Out.c/i;

my $total_num = 0;

open(FILE, "< $file_cust_menu_tree_id_c") or die "[ERROR] Open $file_cust_menu_tree_id_c failed: $!";
while(<FILE>)
{   
	$total_num++;   
}   
close(FILE);


######################
# Set MAX_MENU_ITEMS #
######################

my $file_global_menu_items_h = $cur_dir;  "\\plutommi\\mmi\\inc\\GlobalMenuItems.h";
$file_global_menu_items_h =~ s/\\plutommi\\Customer\\ResGenerator/\\plutommi\\mmi\\inc\\CustMenuRes.h/i;
my $temp_file = $file_global_menu_items_h."~";

# Copy source code to temp file	
open(IN, "< $file_global_menu_items_h ") or die "[ERROR] Open $file_global_menu_items_h  failed: $!";
open(TEMP,   "> $temp_file") or die "[ERROR] Open $temp_file failed: $!";   
while(<IN>)
{   
	print TEMP $_;   
}   
close(TEMP);
close(IN);
	
# Set MAX_MENU_ITEMS
open(IN, "> $file_global_menu_items_h ") or die "[ERROR] Open $file_global_menu_items_h  failed: $!";
open(TEMP,   "< $temp_file") or die "[ERROR] Open $temp_file failed: $!";  
my $line;
while(<TEMP>)
{
	$line = $_;
	if ($line =~ /#define MAX_HILITE_HANDLER/)
	{
		print "Set MAX_HILITE_HANDLER = $total_num \n";
		$line = "#define MAX_HILITE_HANDLER $total_num \n";
	}

	print IN $line;  
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
