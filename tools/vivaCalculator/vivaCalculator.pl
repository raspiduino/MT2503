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
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   vivaCalculator.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This file calculates the size information
#*
#*
#* Author:
#* -------
#*   Ke-Ting Chen (mtk03141)
#*
#*****************************************************************************

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
use warnings;

my $dummyLISFilePath;
my $binaryFolder;
my $customFolder;
my $makefilePath;

my $freeROMSize;
my $newFeatureROCodeSize;
my $newFeatureRODataSize;
my $newFeatureRWSize;
my $newFeatureZISize;

open FILE, "<vivaCalculator.txt" or die ("Cannot open file vivaCalculator.txt: $!");

my $line;
my $pointer;

while ($line = <FILE>)
{
   chomp($line);

   next if $line eq "";

   if ($line =~ /\[Dummy LIS File\]/)
   {
      $pointer = \$dummyLISFilePath;
   }
   elsif ($line =~ /\[Binary Folder\]/)
   {
      $pointer = \$binaryFolder;
   }
   elsif ($line =~ /\[Custom Folder\]/)
   {
      $pointer = \$customFolder;
   }
   elsif ($line =~ /\[Makefile\]/)
   {
      $pointer = \$makefilePath;
   }
   elsif ($line =~ /\[Free ROM Size\]/)
   {
      $pointer = \$freeROMSize;
   }
   elsif ($line =~ /\[New Feature RO-CODE Size\]/)
   {
      $pointer = \$newFeatureROCodeSize;
   }
   elsif ($line =~ /\[New Feature RO-DATA Size\]/)
   {
      $pointer = \$newFeatureRODataSize;
   }
   elsif ($line =~ /\[New Feature RW Size\]/)
   {
      $pointer = \$newFeatureRWSize;
   }
   elsif ($line =~ /\[New Feature ZI Size\]/)
   {
      $pointer = \$newFeatureZISize;
   }
   else
   {
      $$pointer = $line;
   }
}

close FILE;

print `perl tools\\vivaCalculatorImp.pl $dummyLISFilePath $binaryFolder $customFolder $makefilePath $freeROMSize $newFeatureROCodeSize $newFeatureRODataSize $newFeatureRWSize $newFeatureZISize`;
