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
#*   sys_auto_gen.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is used to generate image layout
#*
#* Author:
#* -------
#*   Qmei Yang (mtk03726)
#*
#****************************************************************************/
use strict;
#****************************************************************************
# Included Modules
#****************************************************************************
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use sysGenUtility;                 #pm file name without case sensitivity
use FileInfoParser;
use tools::pack_dep_gen;
PrintDependModule();

#****************************************************************************
# Constants
#****************************************************************************
my $SYSAUTOGEN_VERNO = " v0.06";
                       # v0.06 by Yinli, Support Tiny System
                       # v0.05 by Yinli, Support BL scatter file re-org
                       # v0.04 by mei, Support to trigger 2 phase linking
                       # v0.03 by Carina, Support EWS via tools::pack_dep_gen
                       # v0.02 by mei, fix if system call fails, it'll return errro code:256
                       #               and make build flow will pass if without shifting.
                       # v0.01 by mei, initial version

#****************************************************************************
# Global Variables
#****************************************************************************
my $g_exit = 0;
my %g_MAKEFILE_OPTIONS;

#****************************************************************************
# Input Parameters
#****************************************************************************
my $IMAGELAYOUT           = $ARGV[0];
my $BL_IMAGELAYOUT        = $ARGV[1];
my $FOTA_IMAGELAYOUT      = $ARGV[2];
my $themf                 = $ARGV[3];
my $BB_PATH               = $ARGV[4];
my $NEED_BUILD_BOOTLOADER = $ARGV[5];
my $DUMMY_IMAGELAYOUT_ALLOW   = $ARGV[6];  # INSIDE_MTK (need to check dummy_scatter_enable)
my $DUMMY_IMAGELAYOUT_FORCE   = $ARGV[7];  # DUMMY_LIS (from gendummylis)
my $FACTORY_BIN_PATH      = $ARGV[8];
my $OBJ_SYS_AUTO_GEN      = $ARGV[9]; # trigger 2-phase linking
my $TS_IMAGELAYOUT        = $ARGV[10];
#****************************************************************************
# 1 >>> Run Process
#****************************************************************************

$g_exit = system("perl tools\\sysgen1.pl $BB_PATH $themf");
$g_exit = system("perl tools\\scatGen.pl $ARGV[0] $ARGV[1] $ARGV[2] $ARGV[3] $ARGV[4] $ARGV[5] $ARGV[6] $ARGV[7] $ARGV[8] $ARGV[9] $ARGV[10]") if($g_exit == 0);
$g_exit = system("perl tools\\sysgen2.pl $BB_PATH $IMAGELAYOUT $BL_IMAGELAYOUT $themf $TS_IMAGELAYOUT") if($g_exit == 0);

#****************************************************************************
# 2 >>> exit - no error: 0, error code: > 0
#****************************************************************************
exit $g_exit>>8;

#****************************************************************************
# subroutines
#****************************************************************************

