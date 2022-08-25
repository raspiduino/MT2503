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
#*   emiGem.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script will
#*       1. parse custom_MemoryDevice.h to get memory device type and part number
#*       2. parse custom_EMI.h to retrieve the EMI setting 
#*       3. calc the latency on the specific platform
#*
#* Author:
#* -------
#*   JI Huang      (mtk01077)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#*
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
use Win32::OLE qw(in with);


#****************************************************************************
# Constants
#****************************************************************************
my $EMIMCPCHECK_VERNO  = " V1.12";
                         # V1.12 , 2011/07/07 , To support Combo Memory on all platforms
                         # V1.11 , 2011/04/11 , Skip all other chips except for MT6223(P), MT6235(B), and MT6238/MT6239
                         # V1.10 , 2010/06/29 , Disable MT6251
                         # V1.09 , 2008/12/31 , Remove MT6205B
                         # V1.08 , 2008/10/24 , Add a check rule for MT6235
                         # V1.07 , 2008/10/17 , Modify MCP Check rules on MT6235
                         # V1.06 , 2008/09/19 , Add EMI timing check on MT6235.
                         # V1.05 , 2008/09/12 , Add file name and fline number information and unify all auto-gen error messages
                         # V1.04 , 2008/08/16 , Remove tRRD check on MT6238
                         # V1.03 , 2008/08/01 , Rename EMI_is_16bit as EMI_is_page_size_16_byte to improve maintainability.
                         # V1.02 , 2008/06/16 , Add check rules for MT6235/MT6238.

my $PLATFORM                  = $ARGV[0];
my $MODE                      = $ARGV[1];
my $CUSTOM_MEMORY_DEVICE_HDR  = $ARGV[2]."\\"."custom_MemoryDevice.h";
my $CUSTOM_EMI_H              = $ARGV[2]."\\"."custom_EMI.h";

#****************************************************************************
# Global Variables
#****************************************************************************
my $MEMORY_DEVICE_TYPE;
my $FLASH_ACCESS_TYPE;
my $RAM_ACCESS_TYPE;
my @EMI_SettingOnCS;
my @EMI_CONJ;
my @EMI_CONL;


#****************************************************************************
# skip all chips other than MT6223(P), MT6235(B), and MT6238/MT6239
#****************************************************************************
if (($PLATFORM ne 'MT6223') and ($PLATFORM ne 'MT6223P') and ($PLATFORM ne 'MT6235') and ($PLATFORM ne 'MT6235B') and ($PLATFORM ne 'MT6238') and ($PLATFORM ne 'MT6239'))
{
    exit 0;
}

#****************************************************************************
# parse custom_MemoryDevice.h to extract MEMORY_DEVICE_TYPE & PART_NUMBER
#****************************************************************************
open CUSTOM_MEMORY_DEVICE_HDR, "<$CUSTOM_MEMORY_DEVICE_HDR" or &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: file error!", __FILE__, __LINE__);

while (<CUSTOM_MEMORY_DEVICE_HDR>)
{
   # matching the following lines
   # "#define MEMORY_DEVICE_TYPE    NOR_RAM_MCP"
   # "#define FLASH_ACCESS_TYPE     ASYNC_ACCESS"
   # "#define RAM_ACCESS_TYPE       ASYNC_ACCESS"
   # "#define CS0_PART_NUMBER       RD38F3040L0ZBQ0"

   $MEMORY_DEVICE_TYPE              = $1 if (/^#define\s+MEMORY_DEVICE_TYPE\s+(\w+)/);
   $FLASH_ACCESS_TYPE               = $1 if (/^#define\s+FLASH_ACCESS_TYPE\s+(\w+)/);
   $RAM_ACCESS_TYPE                 = $1 if (/^#define\s+RAM_ACCESS_TYPE\s+(\w+)/);
}

close CUSTOM_MEMORY_DEVICE_HDR;

#****************************************************************************
# parse custom_EMI.h to extract EMI setting
#****************************************************************************
open CUSTOM_EMI_H, "<$CUSTOM_EMI_H" or &error_handler("$CUSTOM_EMI_H: file error!", __FILE__, __LINE__);

my $search_step=0;

while (<CUSTOM_EMI_H>)
{
   #/*
   # ****************************************************************************
   # Specify the related EMI Setting
   # ****************************************************************************
   #*/
   ##if ( defined(MT6227) || defined(MT6226) || defined(MT6226M) )
   #
   #const kal_uint16   EMI_SettingOnCS[4] =
   #{
   #   0x44094324,
   #   0x440a4324,
   #   0,
   #   0
   #};
   #
   ##elif ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) )
   #
   #const kal_uint32   EMI_SettingOnCS[4] =
   #{
   #   0x40514648,
   #   0x40514648,
   #   0,
   #   0
   #};
   if (m/#define EMI_CONTROL_J_VAL_MCP\d+\s+(0x[0-9A-Fa-f]{8})/)
   {
   	   push @EMI_CONJ, $1;
   }
   if (m/#define EMI_CONTROL_L_VAL_MCP\d+\s+(0x[0-9A-Fa-f]{8})/)
   {
   	   push @EMI_CONL, $1;
   }
   if ($search_step==0)
   {
      $search_step++ if (m/Specify the related EMI Setting/);
      next;
   }
   elsif ($search_step==1)
   {
      if ((m/^#if/ or m/^#elif/) and (m/$PLATFORM/))
      {
         $search_step++;
      }
      elsif (m/^#endif/)
      {
         &error_handler("$CUSTOM_EMI_H: Platform not found in EMI setting!", __FILE__, __LINE__);
      }
   }
   elsif ($search_step==2)
   {
      if (m/EMI_SettingOnCS\[4\]/)
      {   
         $search_step++
      }
      elsif (m/^#if/ or m/^#elif/ or m/^#endif/)
      {
         &error_handler("$CUSTOM_EMI_H: EMI_SettingOnCS[4] not found!", __FILE__, __LINE__);
      }
      next;
   }
   elsif ($search_step==3)
   {
      if (m/(0x[0-9A-Fa-f]{8}),/ or m/(0x[0-9A-Fa-f]{4}),/)
      {
         push @EMI_SettingOnCS, hex($1);
      }
      elsif (m/^#if/ or m/^#elif/ or m/^#endif/)
      {
         $search_step++;
      }
      next;
   }
   #/*
   # ****************************************************************************
   # Specify additional information
   # ****************************************************************************
   #*/
   ##define DEV_CONFIG_RAM_PMODE_ADDR_1        0x020001e0
   ##define DEV_CONFIG_RAM_PMODE_DATA_1        0x01
   ##if ( defined(MT6218B) || defined(MT6217) || defined(MT6219) )
   ##define EMI_RAM_PAGE_MODE        
   ##elif ( defined(MT6226) || defined(MT6227) || defined(MT6226M) )
   ##define EMI_RAM_PAGE_MODE        0x44Ca4305
   ##elif ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) )
   ##define EMI_RAM_PAGE_MODE        
   ##elif ( defined(MT6223) || defined(MT6223P) || defined(MT6227D) || defined(MT6226D) )
   ##define EMI_RAM_PAGE_MODE        0x44Ca4305
   ##else
   ##define EMI_RAM_PAGE_MODE        0x4102
   ##endif
   #
   elsif ($search_step==4)
   {
      $search_step++ if (m/define/ and m/DEV_CONFIG_RAM_PMODE_DATA/);
      next;
   }
   elsif ($search_step==5)
   {
      if ((m/^#if/ or m/^#elif/) and (m/$PLATFORM/))
      {
         $search_step++;
      }
      elsif (m/^#endif/)
      {
         $search_step--;
         # die "NOT FOUND";
      }
   }
   elsif ($search_step==6)
   {
      if (/EMI_RAM_PAGE_MODE\s+(0x[0-9A-Fa-f]{8})/)
      {
         $EMI_SettingOnCS[1] = hex($1);
         $search_step++;
      }
   }
   else
   {
      last;
   }
}

close CUSTOM_EMI_H;

#****************************************************************************
# Control flow
#****************************************************************************
foreach my $e (@EMI_SettingOnCS)
{
   printf "0x%x\n",  $e;
   print "PAGE MODE\n" if (&EMI_is_pagemode($e));
   print "BURST MODE\n" if (&EMI_is_burstmode($e));
   print "16 bit\n" if (&EMI_is_page_size_16_byte($e));
   print "RLT: ", &EMI_val_RLT($e) ,"\n";
   print "PRLT: ", &EMI_val_PRLT($e) ,"\n";
}
print "-" x 20 ,"\n";

if ($PLATFORM eq "MT6223" || $PLATFORM eq "MT6223P")
{
   if ($RAM_ACCESS_TYPE eq "SYNC_ACCESS" || $FLASH_ACCESS_TYPE eq "SYNC_ACCESS")
   {
      print "MT6223 MCP check : SYNC_ACCESS type bypass\n";
   }
   elsif ($RAM_ACCESS_TYPE eq "ASYNC_ACCESS" && $FLASH_ACCESS_TYPE eq "ASYNC_ACCESS")
   {
      if ($MODE eq "GSM")
      {
         print "MT6223 MCP check : GSM Project bypass\n";
      }
      elsif ($MODE eq "GPRS")
      {
         my $latency;
         foreach my $s (@EMI_SettingOnCS)
         {
            if (&EMI_val_PRLT($s) == 0)
            {
               $latency = (&EMI_val_RLT($s) + 1) * 8;
            }
            elsif (&EMI_is_page_size_16_byte($s))
            {
               $latency = (&EMI_val_RLT($s) + 1 ) + ((&EMI_val_PRLT($s) + 1) * 7);
            }
            else
            {
               $latency = ((&EMI_val_RLT($s) + 1 ) * 2) + ((&EMI_val_PRLT($s) + 1) * 6);
            }
            &error_handler("$CUSTOM_EMI_H: MT6223 MCP check : Cannot support such low speed MCP!!!", __FILE__, __LINE__) if ($latency > 28);
         }
         print "MT6223 MCP check : GPRS project criteria pass\n";
      }
   }
   else
   {
      &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: MT6223 MCP check : illegal memory access type!", __FILE__, __LINE__);
   }
}
elsif ($PLATFORM eq "MT6235" || $PLATFORM eq "MT6235B")
{
    if ($MEMORY_DEVICE_TYPE ne 'NOR_RAM_MCP')
    {
    	for (0..$#EMI_CONJ)
    	{
    	    my $tRCD_val = &EMI_val_tRCD(hex($EMI_CONJ[$_]));
	        my $tRRD_val = &EMI_val_tRRD(hex($EMI_CONJ[$_]));
	        my $tRP_val = &EMI_val_tRP(hex($EMI_CONJ[$_]));
    	    my $RD_WAIT_CYC_val = &EMI_val_RD_WAIT_CYC(hex($EMI_CONJ[$_]));
    		my $RD_DEL_SEL_val = &EMI_val_RD_DEL_SEL(hex($EMI_CONL[$_]));

	    	### ACT_RC_CYC >= Max. of (tRCD, tRRD, tRP+1, 2) ###
	    	my $max = $tRCD_val;
	    	if ($max < $tRRD_val )
	    	{
	    	    $max = $tRRD_val;
	    	}
	    	if ($max < ($tRP_val+1))
	    	{
	    	    $max = $tRP_val + 1;
	    	}
	    	if ($max < 2)
	    	{
	    	    $max = 2;
	    	}
	    	&error_handler("$CUSTOM_EMI_H: MT6235 MCP check : ACT_RC_CYC >= Max. of (tRCD, tRRD, tRP+1, 2) disobeyed on MCP $_!!!", __FILE__, __LINE__) if ($tRCD_val < $max);
	    
	        ### RD_WAIT_CYC + (tRP + 2) >= RD_DEL_SEL ###
	        &error_handler("$CUSTOM_EMI_H: MT6235 MCP check : RD_WAIT_CYC + (tRP + 2) >= RD_DEL_SEL disobeyed on MCP $_!!!", __FILE__, __LINE__) if (($RD_WAIT_CYC_val+($tRP_val+2)) < $RD_DEL_SEL_val);
	        
	        ### RD_DEL_SEL <= 5
	        &error_handler("$CUSTOM_EMI_H: MT6235 MCP check : RD_DEL_SEL <= 5 disobeyed on MCP $_!!!", __FILE__, __LINE__) if ($RD_DEL_SEL_val > 5);
    	}
    }
}
else
{
      print "Platform " . $PLATFORM . " bypass\n";
}

exit 0;

#****************************************************************************
# Sub routines
#****************************************************************************
sub EMI_is_pagemode
{
   my ($setting) = @_;
   return 1 if ($setting & 0x00010000);
   return 0;
}

sub EMI_is_burstmode
{
   my ($setting) = @_;
   return 1 if ($setting & 0x00020000);
   return 0;
}

sub EMI_is_page_size_16_byte
{
   my ($setting) = @_;
   return 1 if ($setting & 0x00000020);
   return 0;
}

sub EMI_val_RLT
{
   my ($setting) = @_;
   return ($setting & 0x0000001f);
}

sub EMI_val_PRLT
{
   my ($setting) = @_;
   return (($setting & 0x001c0000) >> 18);
}

sub EMI_val_tRRD
{
   my ($setting) = @_;
   return (($setting & 0x00000700) >> 8);
}

sub EMI_val_tRCD
{
   my ($setting) = @_;
   return (($setting & 0x00007000) >> 12);
}

sub EMI_val_tRP
{
   my ($setting) = @_;
   return (($setting & 0x70000000) >> 28);
}

sub EMI_val_tRAS_MIN
{
   my ($setting) = @_;
   return (($setting & 0x00007000) >> 12);
}

sub EMI_val_RD_WAIT_CYC
{
   my ($setting) = @_;
   return ($setting & 0x00000003);
}

sub EMI_val_RD_DEL_SEL
{
   my ($setting) = @_;
   return ($setting & 0x00000007);
}

#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
	   my ($error_msg, $file, $line_no) = @_;
	   
	   my $final_error_msg = "MCPCHECK ERROR: $error_msg at $file line $line_no\n";
	   print $final_error_msg;
	   die $final_error_msg;
}
