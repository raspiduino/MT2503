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
#*   sysGenUtility.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This module collects the subroutines for common utility. 
#*       
#*
#* Author:
#* -------
#*   Qmei Yang (mtk03726)
#*
#****************************************************************************/


package sysUtil;
use strict;
use tools::pack_dep_gen;
use POSIX qw(floor ceil);
PrintDependModule();
#use warnings;


#****************************************************************************
# Constants
#****************************************************************************
my $SYSGENUTILITY_VERNO     = " v0.39";
             # v0.39 , 2013/02/04,  Refactory DCMP part
             # v0.38 , 2013/01/31,  Remove MDIAUD and MEDAUD DCM regions
             # v0.37 , - reserved for adding query_vivaTail_size() for image check mechanism
             # v0.36 , 2013/01/29,  Enlarge VKLAYOUT pool size for the MT6260 with FTE_WQVGA flavor
             # v0.35 , 2013/01/29,  Add NeedPreCompile() and query_addr_woBank() to support ALICE on NAND
             # v0.34 , 2013/01/24,  Modify MM/IME layout (put MDIVID to the same group of VIDMSG if INPUT_METHOD is none)
             # v0.33 , 2013/01/23,  Modify MM/IME layout (seperate CAMCAL and CAMMED to another non-overlay group if INPUT_METHOD is none)
             # v0.32 , 2013/01/22,  Modify query_MM_IME_Grouplength() to support adjust MM/IME pool size by flavor
             # v0.31 , 2013/01/21,  Modify query_MM_IME_length() to support adjust MM/IME pool size by flavor
             # v0.30 , 2013/01/11,  Add is_MMorIME_head(), query_MM_IME_length(), query_MM_IME_Grouplength(), query_MM_IME_InputSection(),
             #                      query_MM_subRegion(), query_IME_subRegion() to support MM/IME DCM new layout
             # v0.29 , 2012/12/21,  Add is_noSYSRAM() for NAND booting
             # v0.28 , 2012/11/16,  Move Dec2Hex from sysGenUtility to CommonUtility
             # v0.27 , 2012/11/06,  Support MT6260
             # v0.26 , 2012/10/31,  Move is_NOR() from here to FileInfoParser to support general query
             # v0.25 , 2012/07/17,  Move DSPTXRX_query_length from scatGenLib.pl to here
             # v0.24 , 2012/07/10,  Remove PrintDependency() and support EWS via tools::pack_dep_gen
             # v0.23 , 2012/06/12,  Error message refinement
             # v0.22 , 2012/04/12,  Modify GetIntsramInfo() to enhance 6250 FTE performance
             # v0.21 , 2012/03/26,  Modify the query method of vivaHelper.pm in query_viva_size()
             # v0.20 , 2012/03/22,  Add query_viva_size to support VIVA
             # v0.19 , 2012/03/21,  Support MT6250
             # v0.18 , 2012/04/17,  Support EWS to print file dependency
             # v0.17 , 2012/02/14,  Add check_cs1_base() and modify query_cs1_addr() to determine CS1 base address
             # v0.16 , 2012/01/30,  Support MT6922
             # v0.15 , 2012/01/28,  Add is_NOR() without supporting smartphone part
             # v0.14 , 2012/01/08,  Add is_CR4(), GetIntsramHWBoundary() and Support TK6280
             # v0.13 , 2012/01/08,  Add GetIntsramInfo() to get intsram CODE/DATA's information
             # v0.12 , 2012/01/08,  Remove has_cache()
             # v0.11 , 2011/11/04,  Remove phased-out chips and add is_arm7()
             # v0.10 , 2011/10/29,  modify query_cs1_addr for MT6255 bootloader workaround
             # v0.09 , 2011/10/28,  To support MT6255
             # v0.08 , 2011/10/28,  print an error message if the file can't be deleted
             # v0.07 , 2011/10/10,  Add has_cache()
             # v0.06 , 2011/09/25,  Move ChangeDefineValue() to auto_adjust_mem.pm and 
             #                      seperate HasCheckinHistory out from del_noCheckinHistory_file
             # v0.05 , 2011/09/16,  Add ChangeDefineValue() for common usage 
             #                      if needed to modify define value in some header files.
             # v0.04 , 2011/09/15,  Collect common functions which can be reused
             # v0.02 , 2011/05/24,  Support MT6921 in arm9 family
             # v0.01 , 2011/03/30,  Initial revision
     
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# Subroutine:  sysgenUtility_verno - to query this package's version number
# Parameters:  x
# Returns:     version number string
#****************************************************************************
sub sysgenUtility_verno
{
    return $SYSGENUTILITY_VERNO;
}

#****************************************************************************
# Subroutine:  GetIntsramInfo - to query INTSRAM_CODE and INTSRAM_DATA's Base/MaxSize
# Parameters:  BB chip  (eg. MT6276)
# Returns:     $strCODEBase, $strCODESize, $strDATABase, $strDATASize
#****************************************************************************
sub GetIntsramInfo
{
    my ($bb) = @_;
    my ($strCODEBase, $strCODESize, $strDATABase, $strDATASize) = (undef, undef, undef, undef);
    my %BB_INTSRAM_tbl =
       (        # $bb => [INTSRAM_CODE_Base, INTSRAM_CODE_Size, INTSRAM_DATA_Base, INTSRAM_DATA_Size]
                'MT6516'  => ["0x50000000", "0x0000E540", "0x5000E740", "0x00007200"],
                'MT6235'  => ["0x50000000", "0x0000C000", "0x50100000", "0x00008C00"],
                'MT6235B' => ["0x50000000", "0x0000C000", "0x50100000", "0x00008C00"], #MT6235
                'MT6236'  => ["0x50000000", "0x00010000", "0x50100000", "0x0000B000"],
                'MT6236B' => ["0x50000000", "0x00010000", "0x50100000", "0x0000B000"], #MT6236
                'MT6921'  => ["0x50000000", "0x00010000", "0x50100000", "0x0000B000"], #MT6236
                'MT6268'  => ["0x50000000", "0x00026000", "0x50100000", "0x00013800"],
                'MT6253'  => ["0x40000000", "0x00006A70", "0x40006A70", "0x00006200"],
                'MT6253E' => ["0x40008000", "0x00002C00", "0x4000AC00", "0x00002000"], 
                'MT6253L' => ["0x40008000", "0x00002C00", "0x4000AC00", "0x00002000"], #MT6253E
                'MT6252H' => ["0x40008000", "0x00002C00", "0x4000AC00", "0x00002000"], #MT6253E
                'MT6252'  => ["0x40008000", "0x00002C00", "0x4000AC00", "0x00002000"], #MT6253E
                'MT6250'  => ["0x70008000", "0x00002800", "0x7000A800", "0x00000C00"],
                'MT6260'  => ["0x70008000", "0x00002400", "0x7000A400", "0x00000C00"],
                'MT6276'  => ["0x50000000", "0x00010000", "0x50100000", "0x00010000"],
                'MT6573'  => ["0x50000000", "0x00010000", "0x50100000", "0x00010000"], #MT6276
                'MT6575'  => ["0x50000000", "0x00010000", "0x50100000", "0x00010000"], #MT6276
                'MT6256'  => ["0x50000000", "0x00003000", "0x50100000", "0x00003000"],
                'MT6255'  => ["0x50000000", "0x00002000", "0x50100000", "0x00002000"],
                'MT6922'  => ["0x50000000", "0x00002000", "0x50100000", "0x00002000"], #MT6255
                'TK6280'  => ["0x58020000", "0x00020000", "0x58040000", "0x00020000"],
       );
    if(exists $BB_INTSRAM_tbl{$bb})
    {
        $strCODEBase = $BB_INTSRAM_tbl{$bb}[0];
        $strCODESize = $BB_INTSRAM_tbl{$bb}[1];
        $strDATABase = $BB_INTSRAM_tbl{$bb}[2];
        $strDATASize = $BB_INTSRAM_tbl{$bb}[3];
    }
    return ($strCODEBase, $strCODESize, $strDATABase, $strDATASize);
}
#****************************************************************************
# Subroutine:  GetIntsramHWBoundary - to query INTSRAM_PHYSICAL_BOUNDARY's Base/MaxSize
# Parameters:  BB chip  (eg. MT6276)
# Returns:     $strBase, $strSize
#****************************************************************************
sub GetIntsramHWBoundary
{
    my ($bb) = @_;
    my ($strBase, $strSize) = (undef, undef);
    my %BB_tbl =
       (        # $bb => [ Base, Size]
                'TK6280'  => ["0x58040000", "0x00020000"],
       );
    if(&is_CR4($bb)==1 and exists $BB_tbl{$bb})
    {
        $strBase = $BB_tbl{$bb}[0];
        $strSize = $BB_tbl{$bb}[1];
    }
    return ($strBase, $strSize);
}
#****************************************************************************
# Subroutine:  is_arm7 - Query if it's ARM7 Family
# Parameters:  BB chip  (eg. MT6276)
# Returns:     1=belongs arm7 family, undef=not arm7 family
#****************************************************************************
sub is_arm7
{
    my ($bb) = @_;
    my %BBtbl_ARM7_Family =
       (        
                'MT6253'  => 1,
                'MT6252H' => 1,
                'MT6252'  => 1,
                'MT6251'  => 1,
                'MT6250'  => 1,
                'MT6260'  => 1,
       );
    return $BBtbl_ARM7_Family{$bb};
}
#****************************************************************************
# subroutine: is_mpu_capable - Query if it has mpu capability
# Input:      BB chip  (eg. MT6276)
# Output:     1=has mpu capability, others=doesn't have mpu capability
#****************************************************************************
sub is_mpu_capable
{
    my ($bb) = (@_);
    my %BBtbl_MPU_Capability =
       (       
                'MT6253'  => 1,
                'MT6252H' => 1,
                'MT6252'  => 1,
                'MT6251'  => 1,
                'MT6250'  => 1,
                'MT6260'  => 1,
       );
    return $BBtbl_MPU_Capability{$bb};  
}

#****************************************************************************
# Subroutine:  is_arm9 - Query if it's ARM9 Family
# Parameters:  BB chip (eg. MT6235)
# Returns:     1=belongs arm9 family, undef=not arm9 family
#****************************************************************************
sub is_arm9
{
    my ($bb) = @_;
    my %BBtbl_ARM9_Family =
       (        
                'MT6235'  => 1,
                'MT6235B' => 1,
                'MT6236'  => 1,
                'MT6236B' => 1,
                'MT6268A' => 1,
                'MT6268'  => 1,
                'MT6921'  => 1,
                'MT6255'  => 1,
                'MT6922'  => 1,
       );
    return $BBtbl_ARM9_Family{$bb};
}


#****************************************************************************
# Subroutine:  is_arm11 - Query if it's ARM11 Family
# Parameters:  BB chip  (eg. MT6276)
# Returns:     1=belongs arm11 family, undef=not arm11 family
#****************************************************************************
sub is_arm11
{
    my ($bb) = @_;
    my %BBtbl_ARM11_Family =
       (        
                'MT6256'  => 1,
                'MT6276'  => 1,
                'MT6573'  => 1,
                'MT6575'  => 1,
       );
    return $BBtbl_ARM11_Family{$bb};
}

#****************************************************************************
# Subroutine:  is_CR4 - Query if it's CR4
# Parameters:  BB chip  (eg. MT6280)
# Returns:     1=belongs CR4, undef=not CR4
#****************************************************************************
sub is_CR4
{
    my ($bb) = @_;
    my %BBtbl_CR4_Family =
       (        
                'TK6280'  => 1,
                'MT6280'  => 1,
       );
    return $BBtbl_CR4_Family{$bb};
}

#****************************************************************************
# subroutine:  Query if it has MMU(arm9, arm11, mtkmmu) 
#              to map the address like 0xf------- 
# input:       BB chip  (eg. MT6276)
# Output:      0=non-mmu, 1=it has mmu
#****************************************************************************
sub is_mmu
{
	my ($bb) = (@_);
	my $nIsMMU = 0; #0=non-MMU, 1=hasMMU;
	my %BBtbl_MTKMMU_Family =
       (        
                'MT6252'   => 1,
                'MT6252H'  => 1,
                'MT6250'   => 1,
                'MT6260'   => 1,
       );
	if(&is_arm9($bb) or &is_arm11($bb) or defined $BBtbl_MTKMMU_Family{$bb} or &is_CR4($bb))
	{
		$nIsMMU = 1;
	}
	return $nIsMMU;	
}
#****************************************************************************
# subroutine: is_sv5 - Query if it's SV5 Family
# Input:      BB chip  (eg. MT6276)
# Output:     1=belongs sv5 family, undef=not sv5 family
#****************************************************************************
sub is_sv5
{
    my ($bb) = (@_);
    my %BBtbl_SV5_Family =
       (        
                'MT6276'  => 1,
                'MT6251'  => 1,
                'MT6256'  => 1,
                'MT6255'  => 1,
                'MT6922'  => 1,
                'MT6250'  => 1,
                'MT6260'  => 1,
       );
    return $BBtbl_SV5_Family{$bb};  
}

#****************************************************************************
# subroutine: is_SmartPhone - Query if it belongs smart phone project
# Input:      BB chip  (eg. MT6276)
# Output:     1=belongs SmartPhone Project, others=not SmartPhone Project
#****************************************************************************
sub is_SmartPhone
{
    my ($bb) = (@_);
    my %BBtbl_SMART_PHONE = 
       (
                'MT6516'  => 1,
                'MT6573'  => 1,
                'MT6575'  => 1,
                'TK6280'  => 1,
       );
    return $BBtbl_SMART_PHONE{$bb};  
}

#****************************************************************************
# subroutine: DCMP_is_MMorIME_head - Query if the region is the head of MM or IME group
# Input:      $strRegion  (eg. MT6276)
# Output:     $ 1=the head of MM or IME group, others=not the head of MM or IME group
#****************************************************************************
sub DCMP_is_MMorIME_head
{
    my ($strRegion) = (@_);
    my %BBtbl_MM_head =
       (
                'MDP'         => 1,
                'VECOM'       => 1,
                'MDICAM'      => 1,
                'CAMCAL'      => 1,
                'MWREC'       => 1,
                'VIDMSG'      => 1,
                'MWWEBCAM'    => 1,
                'MDIMTV'      => 1,
                'MDISTREAM'   => 1,
                'VKLAYOUT'    => 1,
       );
    return $BBtbl_MM_head{$strRegion};
}

#****************************************************************************
# subroutine: DCMP_query_MM_subRegion - Qeury the group regions which belong to MM head region
# Input:      $strRegion: e.g. MDP (DCM id)
# Output:     array_ref of the group of MM regions (one group shares the pool with another group)
#****************************************************************************
sub DCMP_query_MM_subRegion
{
    my ($strRegion) = (@_);
    my %BBtbl_MM_sub = 
       (
                'MDP'           => [],
                'VECOM'         => ['RENDER'],
                'CAMCAL'        => ['CAMMED'],
                'MDICAM'        => [],
                'MWREC'         => [],
                'VIDMSG'        => ['MDIVID'],
                'MWWEBCAM'      => ['USBVIDEO'],
                'MDIMTV'        => ['MEDMTV'],
                'MDISTREAM'     => ['MEDSTREAM'],
       );
    return $BBtbl_MM_sub{$strRegion};
}

#****************************************************************************
# subroutine: DCMP_query_IME_subRegion - Qeury the group regions which belong to IME head region
# Input:      $strRegion: e.g. VKLAYOUT (DCM id)
# Output:     array_ref of the group of IME regions (one group shares the pool with another group)
#****************************************************************************
sub DCMP_query_IME_subRegion
{
    my ($strRegion) = (@_);
    my %BBtbl_IME_sub = 
       (
                'MDP'      => ['VECOM', 'RENDER', 'CAMCAL', 'MDICAM', 'CAMMED', 'MWREC', 'MDIVID'
                               , 'VIDMSG', 'MWWEBCAM', 'USBVIDEO', 'MDIMTV', 'MEDMTV', 'MDISTREAM', 'MEDSTREAM'],
                'VKLAYOUT' => ['GUOBIHW','IME'],
       );
    return $BBtbl_IME_sub{$strRegion};
}

#****************************************************************************
# subroutine: is_UMTS - Query if it's UMTS
# Input:      BB chip  (eg. MT6276)
# Output:     1=belongs UMTS Family, others=not UMTS Family
#****************************************************************************
sub is_UMTS
{
    my ($bb) = (@_);
    my %BBtbl_UMTS_Family =
       (        
                'MT6268'  => 1,
       );
    return $BBtbl_UMTS_Family{$bb};
}

#****************************************************************************
# subroutine: is_noSYSRAM - Query if NAND booting without sysram
# Input:      $bb
# Output:     0=sysram, 1=no sysram
#****************************************************************************
sub is_noSYSRAM
{
    my ($bb) = (@_);
    my %BBtbl_SYSRAM =
       (        
                'MT6250'  => 1,
                'MT6260'  => 1,
       );
    return $BBtbl_SYSRAM{$bb};
}

#****************************************************************************
# subroutine: DSPTXRX_query_length
# purpose : Exec View :: DSP TX RX :: Size Of TX RX query
# Input:      1. $bb: e.g. MT6250 
#             2. $mode: e.g. BASIC, L1S, GSM, GPRS, UMTS
# Output:     (nTXLength, nRXLength)
#****************************************************************************
sub DSPTXRX_query_length
{
    my ($bb, $mode) = @_;
    # --- --- --- 
    my %BBtbl_gprs_tx =
       (        'MT6235'  => 0x20000,
                'MT6235B' => 0x20000,
                'MT6236'  => 0x20000,
                'MT6236B' => 0x20000,
                'MT6921'  => 0x08000,
                'MT6268'  => 0x20000,
                'MT6253'  => 0x02000,
                'MT6516'  => 0x20000,
                'MT6276'  => 0x10000,
                'MT6253E' => 0x02000,
                'MT6253L' => 0x02000,
                'MT6252H' => 0x02000,
                'MT6252'  => 0x02000,
                'MT6573'  => 0x10000,
                'MT6575'  => 0x10000,
                'MT6255'  => 0x20000,
                'MT6922'  => 0x20000,
                'MT6250'  => 0x06000,
                'MT6260'  => 0x06000,
       );
       #map {print $_, "\n";} keys %BBtbl;
    my %BBtbl_gprs_rx =
       (        'MT6235'  => 0x20000,
                'MT6235B' => 0x20000,
                'MT6236'  => 0x20000,
                'MT6236B' => 0x20000,
                'MT6921'  => 0x20000,
                'MT6268'  => 0x20000,
                'MT6253'  => 0x02000,
                'MT6516'  => 0x20000,
                'MT6276'  => 0x18000,
                'MT6253E' => 0x02000,
                'MT6253L' => 0x02000,
                'MT6252H' => 0x02000,
                'MT6252'  => 0x02000,
                'MT6573'  => 0x18000,
                'MT6575'  => 0x18000,
                'MT6255'  => 0x20000,
                'MT6922'  => 0x20000,
                'MT6250'  => 0x0F000,
                'MT6260'  => 0x0F000,
       );
       #map {print $_, "\n";} keys %BBtbl;
    my %BBtbl_gsm_tx =
       (        'MT6235'  => 0x20000,
                'MT6235B' => 0x20000,
                'MT6236'  => 0x20000,
                'MT6236B' => 0x20000,
                'MT6921'  => 0x08000,
                'MT6268'  => 0x20000,
                'MT6253'  => 0x01000,
                'MT6516'  => 0x20000,
                'MT6276'  => 0x20000,
                'MT6253E' => 0x02000,
                'MT6253L' => 0x02000,
                'MT6252H' => 0x02000,
                'MT6252'  => 0x02000,
                'MT6573'  => 0x10000,
                'MT6575'  => 0x10000,
                'MT6255'  => 0x20000,
                'MT6922'  => 0x20000,
                'MT6250'  => 0x01000,
                'MT6260'  => 0x01000,
       );
       #map {print $_, "\n";} keys %BBtbl;
    my %BBtbl_gsm_rx =
       (        'MT6235'  => 0x20000,
                'MT6235B' => 0x20000,
                'MT6236'  => 0x20000,
                'MT6236B' => 0x20000,
                'MT6921'  => 0x20000,
                'MT6268'  => 0x20000,
                'MT6253'  => 0x01000,
                'MT6516'  => 0x20000,
                'MT6276'  => 0x20000,
                'MT6253E' => 0x02000,
                'MT6253L' => 0x02000,
                'MT6252H' => 0x02000,
                'MT6252'  => 0x02000,
                'MT6573'  => 0x18000,
                'MT6575'  => 0x18000,
                'MT6255'  => 0x20000,
                'MT6922'  => 0x20000,
                'MT6250'  => 0x04000,
                'MT6260'  => 0x04000,
       );
       #map {print $_, "\n";} keys %BBtbl;
    my %BBtbl_l1s_tx =
       (        'MT6276'  => 0x20000,
                'MT6573'  => 0x20000,
                'MT6575'  => 0x20000,
                'MT6250'  => 0x18000,
                'MT6260'  => 0x18000,
       );
       #map {print $_, "\n";} keys %BBtbl;
    my %BBtbl_l1s_rx =
       (        'MT6276'  => 0x20000,
       	        'MT6573'  => 0x20000,
       	        'MT6575'  => 0x20000,
       	        'MT6250'  => 0x0F000,
       	        'MT6260'  => 0x0F000,       	        
       );
       #map {print $_, "\n";} keys %BBtbl;
    # --- --- --- 
    if ($mode eq 'L1S')
    {
        if ((exists $BBtbl_l1s_tx{$bb}) and (exists $BBtbl_l1s_rx{$bb}))
        {
            return ($BBtbl_l1s_tx{$bb}, $BBtbl_l1s_rx{$bb});
        }
    }
    if ($mode eq 'GSM')
    {
        if ((!exists $BBtbl_gsm_tx{$bb}) or (!exists $BBtbl_gsm_rx{$bb}))
        {
            return (0, 0);
        }
        return ($BBtbl_gsm_tx{$bb}, $BBtbl_gsm_rx{$bb});
    }
    else
    {
        if ((!exists $BBtbl_gprs_tx{$bb}) or (!exists $BBtbl_gprs_rx{$bb}))
        {
            return (0, 0);
        }
        return ($BBtbl_gprs_tx{$bb}, $BBtbl_gprs_rx{$bb});
    }
}

#****************************************************************************
# subroutine:  determine CS1 base address
# input:       BB chip
# Output:      1 = CS1 base address is 0x08000000, others = CS1 base address is 0x10000000
#****************************************************************************
sub check_cs1_base
{
    my ($bb) = (@_);
    my %BBtbl_cs1_base =
       (
    	        'MT6253'  => 1,
              'MT6252H' => 1,
              'MT6252'  => 1,
              'MT6251'  => 1,
    	 );
    return $BBtbl_cs1_base{$bb};

}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: CS1 base address
# Note      :  this function doesn't guarantee if the chip needs to remap.
#              it only returns the address if needing remapping.
# input:       BB chip, base address(if no input, it's 0 in default), isBootloader(undef or 0= not bootloader)
# Output:      CS1 default base address
#****************************************************************************
sub query_cs1_addr
{
    my ($bb, $nBaseAddress, $bisBL) = @_;
    $nBaseAddress = 0 if(!defined $nBaseAddress);
    my $nCS1BaseAddress = $nBaseAddress;
    if (&check_cs1_base($bb) == 1)
    {
        $nCS1BaseAddress = $nBaseAddress ^ 0x08000000;
    }
    else
    {
        $nCS1BaseAddress = $nBaseAddress ^ 0x10000000;
    }
    if(defined $bisBL and $bisBL != 0)
    {
        if($bb eq "MT6255" or $bb eq "MT6922" or $bb eq "MT6250" or $bb eq "MT6260")
        {
            $nCS1BaseAddress = $nBaseAddress;
        }
    }
    return $nCS1BaseAddress;
}

#****************************************************************************
# subroutine:  query_addr_woBank :: Query :: address with our bank
# input:       base address(if no input, it's 0 in default)
# Output:      the base address without bank
#****************************************************************************
sub query_addr_woBank
{
    my ($nBaseAddress) = @_;
    my $nBaseAddressWoBank = ($nBaseAddress & 0x0FFFFFFF);
    return $nBaseAddressWoBank;
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: viva header size
# note:        This function is used to get viva header size if
#              DCMP support or ZIMAGE support or ALICE support
# input:       BB chip
# Output:      viva header size
#****************************************************************************
sub query_viva_size
{
    require "tools/vivaHelper.pm";
    PrintDependModule();
    my ($bb) = @_;
    my $viva_size = &vivaHelper::GetVIVAHeaderSize_NI(&is_sv5($bb));
    return $viva_size;
}

#****************************************************************************
# Subroutine:   del_noCheckinHistory_file
# Parameters:   one file path
# Returns:      N/A
#****************************************************************************
sub del_noCheckinHistory_file
{
    my ($filepath) = @_;
    return unless (-e $filepath);

    my $nHas = &HasCheckinHistory($filepath);
    if($nHas == 1)
    {
        print "$filepath: Check-in message is found. No need to update.\n";
    }
    elsif($nHas == 0)
    {
        unlink $filepath;
        print "$filepath can't be deleted properly!\n" if(-f $filepath);
    }
    return;
}
#****************************************************************************
# Subroutine:   HasCheckinHistory
# Parameters:   one file path
# Returns:      undef=not exists, 0=no history, 1=has history
#****************************************************************************
sub HasCheckinHistory
{
    my ($filepath) = @_;
    return undef unless (-e $filepath);
    my $nReturn = 0; # Empty=not exists, 0=no history, 1=has history

    ## Now check if the $target file check-in or auto-gen
    open SRC_FILE_R , "<$filepath" or &error_handler("[2.0]$filepath: file error!", __FILE__, __LINE__);
    my $reading;
    {
		local $/;
		$reading = <SRC_FILE_R>; 
	}    
    close SRC_FILE_R;

    ## Look for check-in pattern ##
    if (($reading =~ /\[MAUI_\d{8}\]/) or ($reading =~ /MANUAL-CHECKIN/i))
    {
        PrintDependency($filepath);
        $nReturn = 1;
    }   
    return $nReturn;
}
#****************************************************************************
# Subroutine:   NeedPreCompile
# Parameters:   $bb: bb chip
#               $dsp_solution: dsp solution
#               $alice: alice support
#               $isNFB: is NAND flash booting
# Returns:      0=no need pre-compile, 1=need pre-compile
#****************************************************************************
sub NeedPreCompile
{
    my ($bb, $dsp_solution, $alice, $mba, $isNFB) = @_;
    my $nNeedPreComp = 0;

    my %BBtbl_Precompile =
       (
           'MT6251'  => 1,
       );
    if((defined $dsp_solution and $dsp_solution eq 'DUALMACDSP') or ($isNFB and ($alice eq 'TRUE') and ($mba ne 'TRUE')) or (defined $BBtbl_Precompile{$bb}))
    {
        $nNeedPreComp = 1;
    }
    return $nNeedPreComp;
}
#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no, $strTitle) = @_;
       
    my $final_error_msg = "$strTitle ERROR: $error_msg at $file line $line_no : $!\n";
    print $final_error_msg;
    die $final_error_msg;
}

sub sysgen_die
{
    my ($error_msg, $file, $line_no) = @_;
    &error_handler($error_msg, $file, $line_no, 'SYSGEN');
}
sub sysUtil_die
{
    my ($error_msg, $file, $line_no) = @_;
    &error_handler($error_msg, $file, $line_no, 'SYSGENUTILITY');
}

#****************************************************************************
# subroutine:  description_file_header
# return:      file header -- description 
# input:       $filename:     filename
# input:       $description:  one line description
# input:       $author:       optional
#****************************************************************************
sub description_file_header
{
    my ($filename, $description, $author) = @_;
    my $template = <<"__TEMPLATE";
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   $filename
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   $description
 *
 * Author:
 * -------
 *   $author
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * \$Revision\$
 * \$Modtime\$
 * \$Log\$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  copyright_file_header
# return:      file header -- copyright
#****************************************************************************
sub copyright_file_header
{
    my $template = <<"__TEMPLATE";
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

__TEMPLATE

   return $template;
}
