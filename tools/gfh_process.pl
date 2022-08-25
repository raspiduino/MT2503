#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2011
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

use File::Basename;
use File::Copy;
use strict;

#Usage: gfh_process.pl ProcessFileList IntermediateFile

my($gfh_files)    = $ARGV[0];
my($intermediate) = $ARGV[1];
my($makefile)     = $ARGV[2];

my($debug) = 1;

my($pbp_win32)= 'tools/pbp.exe';
my($pbp_linux)= 'tools/pbp';
my($key)      = 'tools/key_info.ini';
my($key_pubk) = 'tools/key_info_pubk.ini';
my($setting)  = 'tools/brom_setting.ini';

my($pbp) = $^O=~/linux/i ? $pbp_linux : $pbp_win32;
  
die "Intermediate file $intermediate doesn't exist" if not -e $intermediate;

open(FILEHANDLE, "$gfh_files") or die "can't open $!";
foreach (<FILEHANDLE>) { 
   chomp;
   my($result) = 0;
   if($_ =~ /SECURE/i){
      $result = &call_pbp("-secro","$_") if( -e $_);
   }elsif ($_ =~ /BOOTLOADER/i) {
      $result = &call_pbp("-bootloader","$_") if( -e $_);
   }elsif ($_ =~ /FOTA/i) {
       $result = &call_pbp("-fota","$_") if( -e $_);
   }else{
      $result = &call_pbp("-maui","$_") if( -e $_);
   }
   (print("Error[".$result."]: Failed in gfh_process.pl\n") && exit $result) if ($result!= 0);
}
close FILEHANDLE;

exit 0;

sub call_pbp
{

   my($status) = 0;

   my($arg) = shift(@_);
   my($file)= shift(@_);

   backupOrigBin($file) if $debug;			
   print("==> Proecssing $file\n");				
   my($cmd) = "$pbp -m $intermediate -m $makefile -i $key -i $key_pubk -i $setting $file";
   print("cmd=$cmd\n");
   $status = system("$pbp", "-m", $intermediate, "-m", $makefile, "-i", $key, "-i", $key_pubk, "-i", "$setting", $file);
   print("status=", $status>>8, "\n");
   return($status>>8) if $status != 0;
   print("==< Proecssing $file\n");
   return 0;
}


sub backupOrigBin
{
   my($url) = @_;
   my($path, $file) = (dirname($url), basename($url));
   my($backup_path) = "$path/backup";
   print "Backup $file\n";
   mkdir($backup_path) if(! -d $backup_path);

   copy($url, "$backup_path/$file.orig") or die "$!";
}
