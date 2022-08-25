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
#*
#* Filename:
#* ---------
#*   ThirdROM_process.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*
#*
#* Author:
#* -------
#*   Amber Su  (mtk03389)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#*
#* 03 15 2013 amber.su
#* [MAUI_03330378] [Approved DVT] Phase in DCM debug tool (DDT)
#* .
#*
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#*****************************************************************************

#*****************************************************************************
# Included Modules
#*****************************************************************************
use File::stat;

#*****************************************************************************
# Input and Parameters Initialization
#*****************************************************************************
my ($THIRD_ROM_BIN) = @ARGV;

#*****************************************************************************
# Main Flow
#*****************************************************************************
&error_handler("$THIRD_ROM_BIN: NOT exist!", __FILE__, __LINE__) if (!-e $THIRD_ROM_BIN);
my $THIRD_ROM_BIN_SIZE = stat("$THIRD_ROM_BIN")->size;
print "The THIRD_ROM bin size = $THIRD_ROM_BIN_SIZE\n";

my $NAND_BLOCK_SIZE   =  64 * 2 * 1024 ;
my $NAND_RESERVED_BLOCK_COUNT = 5 ;

my $LEN = ((($THIRD_ROM_BIN_SIZE / $NAND_BLOCK_SIZE) + 1) + $NAND_RESERVED_BLOCK_COUNT) * $NAND_BLOCK_SIZE;
print "LEN = ((($THIRD_ROM_BIN_SIZE / $NAND_BLOCK_SIZE) + 1) + $NAND_RESERVED_BLOCK_COUNT) * $NAND_BLOCK_SIZE\n";

print "LEN = $LEN\n";

open (OUTFILE, "+<$THIRD_ROM_BIN") or &error_handler("$THIRD_ROM_BIN cannot open!", __FILE__, __LINE__);
binmode(OUTFILE);
seek(OUTFILE, 36, 0);
print OUTFILE pack("V1",$LEN);
close OUTFILE;

print "Done\n";
exit 0;
#*****************************************************************************
# Error Handling Message
#*****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no) = @_;
    my $final_error_msg = "Error: $error_msg at $file line $line_no\n";
    print "$final_error_msg";
    exit 1;
}
