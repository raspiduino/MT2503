#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2008
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
#*   GetMemCons.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This script will get image component size changes.
#*
#* Author:
#* -------
#*   Hailong Liu  (mtk80026)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

use strict;
use File::Basename;

# library/object mem. size data structure
#my $size =
#{
# file1 => {
#          CODE => integer,
#          RO_DATA => integer,
#          RW_DATA => integer,
#          ZI => integer
#         },
# ......,
# fileN => {
#          CODE => integer,
#          RO_DATA => integer,
#          RW_DATA => integer,
#          ZI => integer
#         }
#};

&usage() if ($#ARGV < 3);

my $DEBUG = 0;

my $totalTimeCons = 0;
my $time = 0;
$time = time if ($DEBUG);

my ($NEW_MEM_MAP, $OLD_MEM_MAP, $RST_FILE, $COMPILATION_TOOL) = @ARGV;
my $librarySizeOld    = {};
my $librarySizeNew    = {};
my $objectSizeOld     = {};
my $objectSizeNew     = {};
my $armObjectSizeOld  = {};
my $armObjectSizeNew  = {};

unlink($RST_FILE) if (-e $RST_FILE);

# get old object & library size
print "Getting OLD object & library mem. size...\n";
($armObjectSizeOld, $objectSizeOld, $librarySizeOld) = readImgCompSize($OLD_MEM_MAP, $COMPILATION_TOOL);

$time = time - $time if ($DEBUG);
$totalTimeCons += $time if ($DEBUG);
print "[Time Consumption] [Get OLD OBJ&LIB size]:\t$time s\n" if ($DEBUG);

# get new object & library size
print "Getting NEW object & library mem. size...\n";
$time = time if ($DEBUG);

($armObjectSizeNew, $objectSizeNew, $librarySizeNew) = readImgCompSize($NEW_MEM_MAP, $COMPILATION_TOOL);

$time = time - $time if ($DEBUG);
$totalTimeCons += $time if ($DEBUG);
print "[Time Consumption] [Get NEW OBJ&LIB size]:\t$time s\n" if ($DEBUG);

# dump result to log
print "Generating mem. consumption log...\n";
$time = time if ($DEBUG);

dumpImgCompChgSizeInfo($librarySizeNew,    $librarySizeOld,    'library',    $RST_FILE);
dumpImgCompChgSizeInfo($objectSizeNew,     $objectSizeOld,     'object',     $RST_FILE);
dumpImgCompChgSizeInfo($armObjectSizeNew,  $armObjectSizeOld,  'armObject',  $RST_FILE);

$time = time - $time if ($DEBUG);
$totalTimeCons += $time if ($DEBUG);
print "[Time Consumption] [Generate mem. cons. log]:\t$time s\n" if ($DEBUG);
print "[Time Consumption] [Total]:\t$totalTimeCons s\n" if ($DEBUG);

sub dumpImgCompChgSizeInfo
{
	my ($newImgCompSizeHashRef, $oldImgCompSizeHashRef, $fileType, $log) = @_;
	my $totalCodeDelta   = 0;
	my $totalRODataDelta = 0;
	my $totalRWDataDelta = 0;
	my $totalZIDelta     = 0;
	my $rstContent       = "";

	if ($fileType eq 'object')
	{
		$rstContent .= "\n***********************************************************************"
		            .  "\n[Object(library member) Size Changes (Delta)] (Bytes)"
		            .  "\n***********************************************************************"
		            .  "\n"
		            .  sprintf("%15s%15s%15s%15s\t%-*s\n", "Code", "RO Data", "RW Data", "ZI",
		                       length("Object(library member) Name"), "Object(library member) Name")
		            .  "-----------------------------------------------------------------------\n";
	}
	elsif ($fileType eq 'library')
	{
		$rstContent .= "\n***********************************************************************"
		            .  "\n[Library Size Changes (Delta)] (Bytes)"
		            .  "\n***********************************************************************"
		            .  "\n"
		            .  sprintf("%15s%15s%15s%15s\t%-*s\n", "Code", "RO Data", "RW Data", "ZI",
		                       length("Library Name"), "Library Name")
		            .  "-----------------------------------------------------------------------\n";
	}
	elsif ($fileType eq 'armObject')
	{
		$rstContent .= "\n***********************************************************************"
		            .  "\n[ARM object Size Changes (Delta)] (Bytes)"
		            .  "\n***********************************************************************"
		            .  "\n"
		            .  sprintf("%15s%15s%15s%15s\t%-*s\n", "Code", "RO Data", "RW Data", "ZI",
		                       length("ARM object Name"), "ARM object Name")
		            .  "-----------------------------------------------------------------------\n";
	}
	else
	{
		warn "[Head][$fileType] Wrong file type!\n";
	}

	foreach my $file (getSuperset([keys %$newImgCompSizeHashRef], [keys %$oldImgCompSizeHashRef]))
	{
		if ((exists $newImgCompSizeHashRef->{$file}) && (exists $oldImgCompSizeHashRef->{$file}))
		{
			if (   ($newImgCompSizeHashRef->{$file}->{CODE} != $oldImgCompSizeHashRef->{$file}->{CODE})
				|| ($newImgCompSizeHashRef->{$file}->{RO_DATA} != $oldImgCompSizeHashRef->{$file}->{RO_DATA})
				|| ($newImgCompSizeHashRef->{$file}->{RW_DATA} != $oldImgCompSizeHashRef->{$file}->{RW_DATA})
				|| ($newImgCompSizeHashRef->{$file}->{ZI} != $oldImgCompSizeHashRef->{$file}->{ZI}))
			{
				$rstContent .= sprintf("%15s%15s%15s%15s\t%-*s\n",
				                       $newImgCompSizeHashRef->{$file}->{CODE}    - $oldImgCompSizeHashRef->{$file}->{CODE},
				                       $newImgCompSizeHashRef->{$file}->{RO_DATA} - $oldImgCompSizeHashRef->{$file}->{RO_DATA},
				                       $newImgCompSizeHashRef->{$file}->{RW_DATA} - $oldImgCompSizeHashRef->{$file}->{RW_DATA},
				                       $newImgCompSizeHashRef->{$file}->{ZI}      - $oldImgCompSizeHashRef->{$file}->{ZI},
				                       length($file), $file);
				$totalCodeDelta   += $newImgCompSizeHashRef->{$file}->{CODE}    - $oldImgCompSizeHashRef->{$file}->{CODE};
				$totalRODataDelta += $newImgCompSizeHashRef->{$file}->{RO_DATA} - $oldImgCompSizeHashRef->{$file}->{RO_DATA};
				$totalRWDataDelta += $newImgCompSizeHashRef->{$file}->{RW_DATA} - $oldImgCompSizeHashRef->{$file}->{RW_DATA};
				$totalZIDelta     += $newImgCompSizeHashRef->{$file}->{ZI}      - $oldImgCompSizeHashRef->{$file}->{ZI};
			}
			else
			{
				print "[$file]:\tNo mem. size changes\n" if ($DEBUG);			
			}
		}
		elsif ((exists $newImgCompSizeHashRef->{$file}) && (!exists $oldImgCompSizeHashRef->{$file}))
		{
			$rstContent .= sprintf("%15s%15s%15s%15s\t%-*s%s\n",
			                       $newImgCompSizeHashRef->{$file}->{CODE},
			                       $newImgCompSizeHashRef->{$file}->{RO_DATA},
			                       $newImgCompSizeHashRef->{$file}->{RW_DATA},
			                       $newImgCompSizeHashRef->{$file}->{ZI},
			                       length($file) + 8, $file,
			                       "(new added)");
			$totalCodeDelta   += $newImgCompSizeHashRef->{$file}->{CODE};
			$totalRODataDelta += $newImgCompSizeHashRef->{$file}->{RO_DATA};
			$totalRWDataDelta += $newImgCompSizeHashRef->{$file}->{RW_DATA};
			$totalZIDelta     += $newImgCompSizeHashRef->{$file}->{ZI};
		}
		elsif ((!exists $newImgCompSizeHashRef->{$file}) && (exists $oldImgCompSizeHashRef->{$file}))
		{
			$rstContent .= sprintf("%15s%15s%15s%15s\t%-*s%s\n",
			                       -$oldImgCompSizeHashRef->{$file}->{CODE},
			                       -$oldImgCompSizeHashRef->{$file}->{RO_DATA},
			                       -$oldImgCompSizeHashRef->{$file}->{RW_DATA},
			                       -$oldImgCompSizeHashRef->{$file}->{ZI},
			                       length($file) + 8, $file,
			                       "(removed)");
			$totalCodeDelta   += -$oldImgCompSizeHashRef->{$file}->{CODE};
			$totalRODataDelta += -$oldImgCompSizeHashRef->{$file}->{RO_DATA};
			$totalRWDataDelta += -$oldImgCompSizeHashRef->{$file}->{RW_DATA};
			$totalZIDelta     += -$oldImgCompSizeHashRef->{$file}->{ZI};
		}
		else
		{
			warn "[$file]: Wrong file name!\n";
		}
	}

	if ($fileType eq 'object')
	{
		$rstContent .= "\n-----------------------------------------------------------------------\n"
		            .  sprintf("%15s%15s%15s%15s\t%-*s\n",
		                       $totalCodeDelta, $totalRODataDelta, $totalRWDataDelta, $totalZIDelta,
		                       length("Object(library member) Delta Totals"), "Object(library member) Delta Totals");
	}
	elsif ($fileType eq 'library')
	{
		$rstContent .= "\n-----------------------------------------------------------------------\n"
		            .  sprintf("%15s%15s%15s%15s\t%-*s\n",
		                       $totalCodeDelta, $totalRODataDelta, $totalRWDataDelta, $totalZIDelta,
		                       length("Library Delta Totals"), "Library Delta Totals");
	}
	elsif ($fileType eq 'armObject')
	{
		$rstContent .= "\n-----------------------------------------------------------------------\n"
		            .  sprintf("%15s%15s%15s%15s\t%-*s\n",
		                       $totalCodeDelta, $totalRODataDelta, $totalRWDataDelta, $totalZIDelta,
		                       length("ARM object Delta Totals"), "ARM object Delta Totals");
	}
	else
	{
		warn "[Tail][$fileType] Wrong file type!\n";
	}

	open(LOG, ">>$log") or die "can NOT open the file $log!\n";
	print LOG $rstContent;
	close(LOG);
}

sub readImgCompSize
{
	my ($imgCompSizeFile, $compilationTool) = @_;
	my $imgCompObjSizeHashRef    = {};
	my $imgCompLibSizeHashRef    = {};
	my $imgCompARMObjSizeHashRef = {};
	my $imgSection               = 0;
	my $libMemberSection         = 0;
	my $libSection               = 0;
	my $armObjSection            = 0;

	my $imgCompSizeMatchPtrn     = '';

	if ($compilationTool =~ /^ADS$/i)
	{
		# Code    RO Data    RW Data    ZI Data      Debug
		$imgCompSizeMatchPtrn = '(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+';
	}
	elsif ($compilationTool =~ /^RVCT$/i)
	{
		# Code (inc. data)   RO Data    RW Data    ZI Data      Debug
		$imgCompSizeMatchPtrn = '(\d+)\s+\d+\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+';
	}
	else
	{
		die "The compilation tool \"$compilationTool\" is NOT supported!\n"
	}

	open(IMGCOMPSIZE, "<$imgCompSizeFile") or die "can NOT open the file $imgCompSizeFile!\n";
	while (<IMGCOMPSIZE>)
	{
		chomp;
		$imgSection = 1 if (/^\s*Image component sizes/i);
		$imgSection = 0 if (/Grand Totals/i);
		if ($imgSection)
		{
			$armObjSection    = 1 if (/Object Name/i);
			$libMemberSection = 1 if (/Library Member Name/i);
			$libSection       = 1 if (/Library Name/i);

			if ($armObjSection)
			{
				if (/^\s*$imgCompSizeMatchPtrn(\w.*\.(obj|o))$/i)
				{
					my $fileName = lc($6);
					$imgCompARMObjSizeHashRef->{$fileName}->{CODE}    = $1;
					$imgCompARMObjSizeHashRef->{$fileName}->{RO_DATA} = $2;
					$imgCompARMObjSizeHashRef->{$fileName}->{RW_DATA} = $3;
					$imgCompARMObjSizeHashRef->{$fileName}->{ZI}      = $4;
				}
				$armObjSection = 0 if (/Object Totals/i);
			}

			if ($libMemberSection)
			{
				if (/^\s*$imgCompSizeMatchPtrn(\w.*\.(obj|o))$/i)
				{
					my $fileName = lc($6);
					$imgCompObjSizeHashRef->{$fileName}->{CODE}    = $1;
					$imgCompObjSizeHashRef->{$fileName}->{RO_DATA} = $2;
					$imgCompObjSizeHashRef->{$fileName}->{RW_DATA} = $3;
					$imgCompObjSizeHashRef->{$fileName}->{ZI}      = $4;
				}
				$libMemberSection = 0 if (/Library Totals/i);
			}

			if ($libSection)
			{
				if (/^\s*$imgCompSizeMatchPtrn(\w.*\.(lib|a|l))$/i)
				{
					my $fileName = lc($6);
					$imgCompLibSizeHashRef->{$fileName}->{CODE}    = $1;
					$imgCompLibSizeHashRef->{$fileName}->{RO_DATA} = $2;
					$imgCompLibSizeHashRef->{$fileName}->{RW_DATA} = $3;
					$imgCompLibSizeHashRef->{$fileName}->{ZI}      = $4;
				}
				$libSection = 0 if (/Library Totals/i);
			}
		}
	}
	close(IMGCOMPSIZE);
	return ($imgCompARMObjSizeHashRef, $imgCompObjSizeHashRef, $imgCompLibSizeHashRef);
}

sub getSuperset
{
	my ($arr1Ref, $arr2Ref) = @_;
	my @result = @$arr1Ref;
	foreach my $e (@$arr2Ref)
	{
		my $tmp = quotemeta($e);
		push(@result, $e) if (!grep(/^$tmp$/i, @result));
	}
	return @result;
}

sub usage
{
	print <<"__EOFUSAGE";

usage: $0 <NEW_IMG_COMP_SIZE_FILE> <OLD_IMG_COMP_SIZE_FILE> <RESULT_LOG> <COMPILATION_TOOL>

NEW_IMG_COMP_SIZE_FILE    Image component size in NEW LIS file
OLD_IMG_COMP_SIZE_FILE    Image component size in OLD LIS file
RESULT_LOG                Dumped result log
COMPILATION_TOOL          ADS or RVCT

__EOFUSAGE
	exit 1;
}

