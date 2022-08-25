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
#*   factory_feature_check.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script will check and auto modify feature option of project makefile 
#*   based on factory makefile
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

use Win32::OLE qw(in with);
use Win32::OLE::Const 'Microsoft Excel';
$Win32::OLE::Warn = 3;

my $Option_Switch_File = Win32::GetCwd() . "\\tools\\GLBOptionSwtichRef\\Feature_Option_Guide_MUST_READ.xls";
my $Excel = Win32::OLE->GetActiveObject('Excel.Application') || Win32::OLE->new('Excel.Application', 'Quit');
die "File $Option_Switch_File does NOT exist\n" if(!-e $Option_Switch_File);

my ($theMF, $factoryMF, $bootup_arg, $custom_release) = @ARGV;
die "File $theMF does NOT exist\n" if(!-e $theMF);
die "File $factoryMF does NOT exist\n" if(!-e $factoryMF);

my $customer = 0;

if($custom_release eq "TRUE") {
  $customer = 1;
}

my %factory=();
my %Change_Set=();
my $separation = "*******************************************************************************************";

if($theMF =~ /make\\(.+)\_(.+)\.mak/) {
  $MFname = $1;
  $modem_type = $2;
  $MFname_tmp = $MFname;
  if(${MFname_tmp} =~ /(.+)\_(FACTORY|MAUIONLY|COMBINE)$/i) {
    $MFname = $1;
  }
}
my $newMF = "make\\".$MFname."_".uc($bootup_arg)."_".$modem_type."\.mak";

system("copy /y $theMF $newMF > nul");

if((uc($bootup_arg) eq "MAUIONLY") || (uc($bootup_arg) eq "COMBINE") ) {
	
	if(uc($bootup_arg) eq "MAUIONLY") {
		&Change_Value($newMF,SPLIT_BINARY_SUPPORT,MAUI_ONLY);
	} elsif(uc($bootup_arg) eq "COMBINE") {
		#Before generating COMBINE makefile, check FACTORY.bin is built and existed
		if (!&check_factory_bin("build\\${MFname}_FACTORY")) {
		  print STDERR "Factory bin is in  build\\${MFname}_FACTORY\n";
		  print STDERR "Error: cannot find FACTORY bin. Please build FACTORY bin first.\n";
		  exit 1;
		}
		&Change_Value($newMF,SPLIT_BINARY_SUPPORT,FACTORY_COMBINE);
	}
	
} elsif((uc($bootup_arg) eq "FACTORY")) {
  &Replace_Option;
  &Change_Value($newMF,SPLIT_BINARY_SUPPORT,FACTORY_ONLY) if(uc($bootup_arg) eq "FACTORY");
}

print STDERR "Done for generating $newMF\n";
exit 0;

sub Replace_Option {
	open (FILE_HANDLE, "<$factoryMF") or die "Cannot open $factoryMF\n";
  %SwitchOpts = &GetSwitchableFeatureOption if ($customer);
  while (<FILE_HANDLE>) {
    if ((/^([^\#]*)\#?.*/) && ($1 =~ /^(\w+)\s*=\s*(.*\S)\s*$/)) {
      $keyname = lc($1);
      next if($customer && !defined $SwitchOpts{$1});
      next if(uc($2) eq "ANY");
      $factory{$keyname} = uc($2);
    }
  }
  close FILE_HANDLE;

  open (FILE_HANDLE, "<$theMF") or die "Cannot open $theMF\n";
  $reading = "";
    while (<FILE_HANDLE>) {
      if ((/^([^\#]*)\#?.*/) && ($1 =~ /^(\w+)\s*=\s*(.*\S)\s*$/)) {
        $keyname = lc($1);
        $${keyname} = uc($2);
        if((defined $factory{$keyname}) && ($factory{$keyname} ne $${keyname})) {
          $original_value = $2;
          $chaged_value = $factory{$keyname};
          $_ =~ s/$original_value/$chaged_value/;
          $Change_Set{$keyname} = "$original_value,$chaged_value";
        }
      }
      $reading .= $_;
  }
  close FILE_HANDLE;

  open (MAKEFILE, ">$newMF") or die "Cannot open $newMF\n";
  print MAKEFILE $reading;
  close MAKEFILE;

  $cnt = keys %Change_Set;
  print "$separation\n[Summary]\n$separation\n";
  print "\n Total changed feature option: $cnt\n\n";
  print "$separation\n[Changed Feature Option Information]\n$separation\n";
  print sprintf ("%-50s %-25s %s\n","[Feature Option]","[Original Value]","[Result]");
  print "-------------------------------------------------------------------------------------------\n";
  
  foreach my $key (sort keys %Change_Set) {
  	my $value = $Change_Set{$key};
  	@temp = split/,/,$value;
  	$original_value = $temp[0];
  	$chaged_value   = $temp[1];
  	print sprintf ("%-50s %-25s %s\n",uc($key),$original_value,$chaged_value);
  }

}

sub GetSwitchableFeatureOption
{
	my %Feature_Options;

	my $Book = $Excel->Workbooks->Open($Option_Switch_File);	
	my $MainSheet = $Book->Worksheets("1.Option");
	my $max_row = 1024;
	my $max_colum = 16;
	my $Switch_col = 0;
	my $Option_head_row = 3;
	my $Name_col = 0;
	
	foreach my $col (1..$max_colum) {
		next unless defined $MainSheet->Cells($Title_row,$col)->{'Value'};
		
		if ($MainSheet->Cells($Title_row,$col)->{'Value'} =~ /Customer\sSwitchable?/i) {
			$Switch_col = $col;
		} elsif ($MainSheet->Cells($Title_row,$col)->{'Value'} =~ /Feature\sOption/i) {
			$Name_col = $col;
		}
	}
	foreach my $row ($Option_head_row..$max_row) {
		next unless defined $MainSheet->Cells($row,$Switch_col)->{'Value'};
		my $option_name = "";
		if (defined $MainSheet->Cells($row,$Switch_col)->{'Value'} && ($MainSheet->Cells($row,$Switch_col)->{'Value'} =~ /Y/i)) {# for specified PLATFORMs' switch verification
			$option_name = $MainSheet->Cells($row,$Name_col)->{'Value'};
			$option_name =~ s/\s//g;
			push @Feature_Options,$option_name;
			$Feature_Options{$option_name} = 1;
		}
	}
	$Book->Close;
	return %Feature_Options;
}

sub Change_Value
{
  my ($makefile, $target_name, $chaged_value) = @_;
  
  open (FILE_HANDLE, $makefile) or die "Cannot open $makefile\n";
  $reading="";
  while (<FILE_HANDLE>) {
    if (/^($target_name)\s*=\s*(\S+)/) {
      $original_value = $2;
      $_ =~ s/$original_value/$chaged_value/;
    }
    $reading .= $_;
  }
  close FILE_HANDLE;

  open (MAKEFILE, ">$makefile") or die "Cannot open $makefile\n";
  print MAKEFILE $reading;
  close MAKEFILE;
  
}

sub check_factory_bin {
  my $path = $_[0];
  foreach my $load (<$path\\*.bin>) {    
    if (-d "$load") {
      foreach (&list_dir("$load")) { 
        if ($_ =~ /\.bin$/) {
          return 1 ;
        };
        if ($_ =~ /\ROM$/) {
          return 1 ;
        };
      }
      return 0;
    }          
    return 1 if (($load !~ /_BOOTLOADER_/i) && ($load !~ /_FOTA_/i));    
  }
  return 0;
}

sub list_dir
{
  my $path  = $_[0];
  my @files = ();
  
  if (opendir(FILE, $path)) {
    foreach (readdir(FILE))
    {
      next if ($_ eq ".");
      next if ($_ eq "..");
      push @files, $_;
    }
    closedir(FILE);
  }
  return @files;
}