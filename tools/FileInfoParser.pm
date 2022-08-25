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
#*   FileInfoParser.pm
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
package FileInfo;
use strict;
#use warnings;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use sysgenUtility;                 #pm file name without case sensitivity
use CommonUtility;
use tools::pack_dep_gen;
PrintDependModule();

#****************************************************************************
# Constants
#****************************************************************************
my $FILEINFOPARSER_VERNO     = " v0.12";
                               # v0.12, 2012/02/05, Support undefined FeatureOption in EvaluateFeatureOptionCondition()
                               # m0.04, 2012/08/06, Add more common functions and ParseDefinition()
                               # v0.11, 2013/01/28, Add isNot() to check the feature option with NONE/FALSE
                               # v0.10, 2012/11/22, Add check mechanism to check the content of project makefile
                               # v0.09, 2012/07/10, Support EWS via tools::pack_dep_gen
                               # v0.08, 2012/06/12, Error message refinement
                               # v0.07, 2012/05/13, Move is_NOR from sysgenUtility to here and support general query
                               # v0.06, 2012/05/08, Copy parseFeatureOptionCondition 
                               #                    and EvaluateFeatureOptionCondition from objListHelper.pm to here
                               # v0.05 , 2012/05/08,  Query is_SmartPhone
                               # v0.04 , 2012/01/30,  To provide CUSTOMER and MODE in %MAKEFILE_OPTIONS
                               # v0.03 , 2011/12/17,  Fix parsing MakeFile
                               # v0.02 , 2011/11/01,  Remove $$ to support Perl v5.12.*
                               # v0.01 , 2011/09/21,  Initial revision

#****************************************************************************
# Global variable
#****************************************************************************
my $g_MAKEFILE_href = undef;
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# subroutine:  Parse_MAKEFILE
# input:    1. MAKEFILE path
#           2. a Hash to contain MAKEFILE information.
# output:   1=Parse successfully, 0 or die= Parse failed.
# sample code: my %MAKEFILE_OPTIONS;
#              &FileInfo::Parse_MAKEFILE($MAKEFILE_Path, \%MAKEFILE_OPTIONS);   
#****************************************************************************

sub Parse_MAKEFILE
{
    my ($strMAKEFILE_Path, $Info_href) = @_;
    my $bResult = 0;
    my $bValidityCheck = 0;
    if(-e $strMAKEFILE_Path)
    {
        open (FILE_HANDLE, $strMAKEFILE_Path) or &FileInfoParser_die("[2.0]Cannot open $strMAKEFILE_Path\n", __FILE__, __LINE__);
        while (<FILE_HANDLE>) 
        {
            if ((/^([^\#]*)\#?.*/) && ($1 =~ /^(\w+)\s*=\s*(.*\S)\s*$/))
            {
                my $keyname = lc($1);
                #defined($Info_href->{$keyname}) && warn "$1 redefined in $strMAKEFILE_Path!\n";
                $Info_href->{$keyname} = uc($2);
                $keyname = uc($1);
                #defined($Info_href->{$keyname}) && warn "$1 redefined in $strMAKEFILE_Path!\n";
                $Info_href->{$keyname} = uc($2);
                $bResult = 1;
            }
            elsif (/\s*\#\s*Release\s*Setting\s*Section/)
            {
                #this pattern should exists in the project.mak
                $bValidityCheck = 1;
            }
        }
        close FILE_HANDLE;
        
        #ValidityCheck
        &FileInfoParser_die("[1.5]Incorrect content in $strMAKEFILE_Path , please check it!", __FILE__, __LINE__) if($bValidityCheck == 0);
        
        if ($strMAKEFILE_Path =~ /make\\(\w+)_(\w+).mak/i) 
        {
            $Info_href->{'CUSTOMER'} = uc($1);
            $Info_href->{'customer'} = uc($1);
            $Info_href->{'MODE'} = uc($2);
            $Info_href->{'mode'} = uc($2);
        }
        $g_MAKEFILE_href = $Info_href;
    }
    else
    {
        &FileInfoParser_die("[1.4]$strMAKEFILE_Path: NOT exist!", __FILE__, __LINE__);
    }
    return $bResult;
}
sub GetMakeFileRef
{
    my ($strMAKEFILE_Path) = @_;
    if(!defined $g_MAKEFILE_href)
    {
        my %MakeFileOption;
        &Parse_MAKEFILE($strMAKEFILE_Path, \%MakeFileOption);
    }
    return $g_MAKEFILE_href;    
}


sub is
{
    my ($strKey, $strValue, $MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    my ($pack_name, $file, $line_no) = caller;
    &NoMakeFile_die($MakeFile_ref, $file, $line_no);
    my $bEqual = 0;
    if(exists $MakeFile_ref->{uc($strKey)} and uc($MakeFile_ref->{uc($strKey)}) eq uc($strValue))
    {
        $bEqual = 1;
    }
    return $bEqual;
}
sub find
{
    my ($strKey, $strValue, $MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    my ($pack_name, $file, $line_no) = caller;
    &NoMakeFile_die($MakeFile_ref, $file, $line_no);
    my $bFound = 0;
    if(exists $MakeFile_ref->{uc($strKey)} and $MakeFile_ref->{uc($strKey)} =~ /$strValue/)
    {
        $bFound = 1;
    }
    return $bFound;
}
sub isnot
{
    my ($strKey, $strValue, $MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    my ($pack_name, $file, $line_no) = caller;
    &NoMakeFile_die($MakeFile_ref, $file, $line_no);
    my $bNotEqual = 0;
    if(exists $MakeFile_ref->{uc($strKey)} and uc($MakeFile_ref->{uc($strKey)}) ne uc($strValue))
    {   #exist but not equal
        $bNotEqual = 1;
    }
    return $bNotEqual;
}
sub get
{
    my ($strKey, $MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    my ($pack_name, $file, $line_no) = caller;
    &NoMakeFile_die($MakeFile_ref, $file, $line_no);
    my $Value = undef;
    if(exists $MakeFile_ref->{uc($strKey)})
    {
        $Value = $MakeFile_ref->{uc($strKey)};
    }
    return $Value;
}
sub ParseDefinition
{
    my ($strFilePath, $Hash_ref, $bAllowDuplicated) = @_;
    my $content = &CommonUtil::GetFileContent($strFilePath);
    #strip comments
    $content =~ s/\/\/(.+)//g;
    $content =~s#/\*[^*]*\*+([^/*][^*]*\*+)*/|([^/"']*("[^"\\]*(\\[\d\D][^"\\]*)*"[^/"']*|'[^'\\]*(\\[\d\D][^'\\]*)*'[^/"']*|/+[^*/][^/"']*)*)#$2#g;

    my @lines = split(/\n|\r/, $content);
    my $nDuplicatedIndex=0;
    foreach my $line (@lines)
    {
        if ($line =~ /#define\s+(\w+)\s+\((.*)\)\s*$/ || $line =~ /#define\s+(\w+)\s+(\S*)\s*$/)
        {
            my $option = $1;
            my $value  = $2;
            &FileInfoParser_die("[2.0]$strFilePath: $option redefined in $strFilePath!", __FILE__, __LINE__) 
                if (!$bAllowDuplicated and defined($Hash_ref->{$option}));
            if (!defined $value)
            {
                $Hash_ref->{$option} = 'TRUE';
                $Hash_ref->{uc($option)} = 'TRUE';
                $Hash_ref->{lc($option)} = 'TRUE';
            }
            else
            {
                $Hash_ref->{$option} = $value;
                $Hash_ref->{uc($option)} = $value;
                $Hash_ref->{lc($option)} = $value;
            }
        }
    }
    close (FILE_HANDLE);
}
#****************************************************************************
# subroutine: is_SmartPhone - Query if it belongs smart phone project
# Input:      x
# Output:     1=it's SmartPhone, others=not SmartPhone
#****************************************************************************
sub is_SmartPhone
{
    my ($MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    my ($pack_name, $file, $line_no) = caller;
    &NoMakeFile_die($MakeFile_ref, $file, $line_no);
    my $bIsSmartPhone = 0;
    if( exists $MakeFile_ref->{SMART_PHONE_CORE} and $MakeFile_ref->{SMART_PHONE_CORE} ne "NONE" ) #NONE = feature phone
    {
        $bIsSmartPhone = 1;
    }
    return $bIsSmartPhone;
}


#****************************************************************************
# subroutine: is_NOR - Query if it's NOR flash
# Input:      \%MAKEFILE_OPTION
# Output:     0=not NOR, 1=NOR
#****************************************************************************
sub is_NOR
{
    my ($MAKEFILE_ref) = @_;
    $MAKEFILE_ref = $g_MAKEFILE_href if (!defined $MAKEFILE_ref);
    my ($pack_name, $file, $line_no) = caller;
    &NoMakeFile_die($MAKEFILE_ref, $file, $line_no);
    my $bNOR = 1; # 0=not NOR, 1= NOR
    if((exists $MAKEFILE_ref->{'nand_flash_booting'} and $MAKEFILE_ref->{'nand_flash_booting'} ne 'NONE') 
    or (exists $MAKEFILE_ref->{'emmc_booting'} and $MAKEFILE_ref->{'emmc_booting'} ne 'NONE'))
    {
        $bNOR = 0;
    }
    return $bNOR;
}
#****************************************************************************
# subroutine:  EvaluateFeatureOptionCondition
# description: Evaluate the feature option condition.
# input:       Feature option condition(string), makefile options hash ref
# output:      1: true, 0: false
# need init:   No
#****************************************************************************
sub EvaluateFeatureOptionCondition
{
   my ($condition, $makefileOptionsRef)  = @_;
   $makefileOptionsRef = $g_MAKEFILE_href if(!defined $makefileOptionsRef);
   my ($pack_name, $file, $line_no) = caller;
   &NoMakeFile_die($makefileOptionsRef, $file, $line_no);
   
   my @expressionTree;
   my @stack;

   # Transform the condition to expression tree in postfix form
   &parseFeatureOptionCondition($condition,  \@expressionTree);

   # Evaluate the expression tree
   foreach my $token (@expressionTree)
   {
      if ($token eq "&&" or $token eq "||")
      {
         my $second = pop(@stack);
         my $first = pop(@stack);
         push (@stack, eval "$first $token $second");
      }
      elsif ($token eq "=")
      {
         my $second = pop(@stack);
         my $first = pop(@stack);
         my $value = $makefileOptionsRef->{$first};
         $value = "UNDEFINED" unless defined $value;
         if ($value eq $second)
         {
            push (@stack, 1);
         }
         else
         {
            push (@stack, 0);
         }
      }
      elsif ($token eq "!")
      {
         my $first = pop(@stack);
         if ($first == 1)
         {
            push (@stack, 0);
         }
         else
         {
            push (@stack, 1);
         }
      }
      else
      {
         push @stack, $token;
      }
   }
   &FileInfoParser_die("[2.0]Incorrect syntax of feature option condition \"$condition\"", __FILE__, __LINE__)
      unless (1 == @stack);

   return $stack[0];
}

#****************************************************************************
# subroutine:  parseFeatureOptionCondition
# description: Parse the feature option condition to postfix form.
# input:       Feature option condition, expression tree ref
# output:      Expression tree
# need init:   No
#****************************************************************************
sub parseFeatureOptionCondition
{
   my $condition = shift;
   my $expressionTreeRef = shift;
   my $conditionNoSpace = $condition;
   $conditionNoSpace =~ s/ //g;

   my @tokens = split(/(=|\(|\)|&&|\|\||!)/, $conditionNoSpace);
   my @stack;

   # For error checking
   my $parenthesis = 0;
   my $operand = 0;
   my $operator = 0;

   foreach my $token (@tokens)
   {
      if ($token eq "")
      {
         # Skip empty token
         next;
      }
      elsif ($token eq "(")
      {
         push @stack, $token;
         ++$parenthesis;
      }
      elsif ($token eq ")")
      {
         &FileInfoParser_die("[2.0]Incorrect syntax of feature option condition \"$condition\"", __FILE__, __LINE__)
            unless (0 < $parenthesis);
         my $temp = pop(@stack);

         &FileInfoParser_die("[2.0]Incorrect syntax of feature option condition \"$condition\"", __FILE__, __LINE__)
            if ($temp eq "(");

         do
         {
            push @$expressionTreeRef, $temp;
            $temp = pop(@stack);
         } while ($temp ne "(");

         --$parenthesis;
      }
      elsif ($token eq "=" or $token eq "&&" or $token eq "||" or $token eq "!")
      {
         my $needLoop = 0;

         do
         {
            if (0 == scalar(@stack) or $stack[-1] eq "(")
            {
               # Stack is empty or stack top eqals to (
               push @stack, $token;
               $needLoop = 0;
            }
            elsif (0 < compareFeatureOptionOperator($stack[-1], $token))
            {
               # Stack top has higher priority than current token
               push @stack, $token;
               $needLoop = 0;
            }
            else
            {
               push @$expressionTreeRef, pop(@stack);
               $needLoop = 1;
            }
         } while ($needLoop);

         $operator += 1 unless ($token eq "!");
      }
      elsif ($token =~ /\w+/)
      {
         # Operand
         push @$expressionTreeRef, $token;
         $operand += 1;
      }
      else
      {
         &FileInfoParser_die("[2.0]Incorrect syntax of feature option condition \"$condition\"",  __FILE__, __LINE__);
      }
   }

   &FileInfoParser_die("[2.0]Incorrect syntax of feature option condition \"$condition\"", __FILE__, __LINE__)
      unless ($operator == ($operand - 1) and 0 == $parenthesis);

   push @$expressionTreeRef, reverse(@stack);
}

sub compareFeatureOptionOperator
{
   my $first = shift;
   my $second = shift;
   my %operatorToNumber = ("=" => 0, "!" => 1, "&&" => 2, "||" => 2);

   return $operatorToNumber{$first} <=> $operatorToNumber{$second};
}


#****************************************************************************
# subroutine:  FileInfoParser_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub FileInfoParser_die
{
    my ($error_msg, $file, $line_no) = @_;
    &sysUtil::error_handler($error_msg, $file, $line_no, 'FileInfoParser');    
}
sub NoMakeFile_die
{
    my ($MAKEFILE_ref, $file, $line_no) = @_;
    &FileInfoParser_die("[2.0]Please parse makefile by FileInfo::Parse_MAKEFILE() before using it.",$file, $line_no) 
        if(!defined $MAKEFILE_ref);
}
