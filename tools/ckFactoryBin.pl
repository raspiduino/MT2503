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
#
#*****************************************************************************
#* Filename:
#* ---------
#*   ckFactoryBin.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script will check factory bin before building MAUI_ONLY bin 
#*   with SPLIT_BINARY_SUPPORT=FACTORY_COMBINE case
#*
#* Author:
#* -------
#*   Amber Su  (mtk03389)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*----------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#* 
#*
#*----------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#*****************************************************************************
my ($customer, $factory_bin_folder) = @ARGV;

$factory_customer = $customer;
$factory_customer =~ s/COMBINE/FACTORY/i;

die "Folder: build\\$factory_customer does NOT exist.\n" if(!-d "build\\$factory_customer");

 foreach my $load (<build\\$factory_customer\\*.bin>) {
  if (-d "$load"){      
    foreach (&list_dir("$load")) {
    	$bin_exist = 1 if ($_ =~ /\.bin$/); 
    	if(($_ eq "ROM") || ($_ eq "SECONDARY_ROM")) {
    		system("md $factory_bin_folder") if(! -d "$factory_bin_folder");
  		  print "copy /y $load\\$_ $factory_bin_folder\\FACTORY\_${_}\n";
  		  system("copy /y $load\\$_ $factory_bin_folder\\FACTORY\_${_} > nul");
    	}     
    }
  } else {
  	if (($load !~ /_BOOTLOADER_/i) && ($load !~ /_FOTA_/i)) {
  		$bin_exist = 1;
  		system("md $factory_bin_folder") if(! -d "$factory_bin_folder");
  		print "copy /y $load $factory_bin_folder\\FACTORY_ROM\n";
  		system("copy /y $load $factory_bin_folder\\FACTORY_ROM > nul");
  		
  	}
  }  
}

if($bin_exist) { 
	exit 0;
} else {
	$tmp_str = "Error: factory bin does not exist. Please build FACTORY bin fist before build MAUI_ONLY bin with SPLIT_BINARY_SUPPORT=FACTORY_COMBINE.\n";
	print $tmp_str;
	print STDERR $tmp_str;
  exit 1;
}

sub list_dir {
  my $path  = $_[0];
  my @files = ();
  if (opendir(FILE, $path)) {
    foreach (readdir(FILE)) {
      next if ($_ eq ".");
      next if ($_ eq "..");
      push @files, $_;
    }
    closedir(FILE);
  }
  return @files;
}