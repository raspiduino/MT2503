#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2006
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
#*
#* Filename:
#* ---------
#*   clean_obj.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This script will auto delete object files in mcu\build
#*   
#*
#* Author:
#* -------
#*   ChunJen Cheng  (mtk90073)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision:   $
#* $Modtime:   $
#* $Log:   $
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================

my $curr_usr = lc(getlogin());
my %BM_list;

if (-e "\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\BM_conf.ini") {
  my %BM_conf = iniToHash("\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\BM_conf.ini");
    $bm_list = $BM_conf{'CLEAN_OBJ'}->{'BM_LIST'};
}

exit unless ($bm_list);
exit unless ($curr_usr);

foreach (split(/,/, $bm_list)) {
  if (/(\w+)/i) {
    $BM_list{$1} = 1;
  }
}

exit unless ($BM_list{$curr_usr});

my ($codebase) = @ARGV;
$codebase = Win32::GetCwd() unless $codebase;

if (-d $codebase) {
  # Clean J2ME
  #$j2me_dir = "$codebase\\j2me\\vm\\IJET";
  #print "rd /s /q $j2me_dir\\romizing\n";
  #system("rd /s /q $j2me_dir\\romizing");
  #print "rd /s /q $j2me_dir\\midp\n";
  #system("rd /s /q $j2me_dir\\midp");
  #print "rd /s /q $j2me_dir\\m3g\n";
  #system("rd /s /q $j2me_dir\\m3g");
  #print "rd /s /q $j2me_dir\\kvm_hi\n";
  #system("rd /s /q $j2me_dir\\kvm_hi");
  #print "rd /s /q $j2me_dir\\kvm_11\n";
  #system("rd /s /q $j2me_dir\\kvm_11");
  
  # Clean WIFI
  #$wifi_dir = "$codebase\\wifi";
   #undef @tmp;
   #@tmp = <$codebase\\wifi\\sslplus4\\*>;
  #foreach (@tmp) {
  #   unless (/include$/i) {
  #      #print "rd /s /q \"$_\"\n" if (-d $_);
  #      system("rd /s /q \"$_\"") if (-d $_);
  #      #print "del /q \"$_\"\n" if (-f $_);
  #      system("del /q \"$_\"") if (-f $_);
  #   }
  #}
  
  #undef @tmp;
   #@tmp = <$codebase\\wifi\\sb32\\*>;
  #foreach (@tmp) {
  #   unless (/include$/i) {
  #      #print "rd /s /q \"$_\"\n" if (-d $_);
  #      system("rd /s /q \"$_\"") if (-d $_);
  #      #print "del /q \"$_\"\n" if (-f $_);
  #      system("del /q \"$_\"") if (-f $_);
  #   }
  #}
  
  exit unless (-d "$codebase\\build");
  # Get project
  undef @tmp;
  @tmp = <$codebase\\build\\*\\*>;
  foreach (@tmp) {
    if((-d $_) && ($_ =~ /(basic|gsm|gprs|l1s|umts)$/i) && ($_ !~ /bin$/i)){
      $codebase = $_;
      last;
    }
  }

  # Get OBJ folder
  undef @tmp;
  @tmp = <$codebase\\*>;
  foreach (@tmp) {
    last if (substr($codebase = $_, -1) == 'o');
  }
  
  # Clean OBJ
  unless (-d "$codebase\\lib") {
    print "\n\n$codebase\\lib is not exist !!\n\n";
    #system("pause");
    exit;
  }
  undef @tmp;
  @tmp = <$codebase\\*>;
  foreach (@tmp) {
    unless (lc($_) eq lc("$codebase\\lib")) {
      $file_name = substr($_, rindex($_, "\\")+1);
      if (-f "$codebase\\lib\\$file_name.lib") { # if library was generated, delete it's obj files
         #print ("rd /s /q $_\n");
         system ("rd /s /q $_");
      }
    }
  }
  
} else {
  print "\n\n$codebase is not exist !!\n\n";
}

sub iniToHash{
    open(MYINI, $_[0]);
    my %hash;
    my $hashref;
    
    while(<MYINI>)
    {
        next if ((/^\s*$/) || (/^\s*#/));
        if (/^\s*\[(.+)\]/)
        {
            $hashref = $hash{$1} ||= {};
        }
        elsif (/^\s*(\S+)\s*=\s*(.+)\s*$/)
        {
            $hashref->{$1} = $2;
        }
        elsif (/^\s*(\S+)\s*\+=\s*(.+)\s*$/)
        {
          $hashref->{$1} = $hashref->{$1} . " $2";
        }
    }
    
    close MYINI;
    return %hash;
}

