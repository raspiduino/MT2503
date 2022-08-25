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
#*   CommonUtility.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is to provide common utility
#*
#* Author:
#* -------
#*   Qmei Yang (mtk03726)
#*
#****************************************************************************/
#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
package CommonUtil;
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# CommonUtility Version
#****************************************************************************
sub CommonUtil_verno
{
    return " v0.08";
           # v0.08 , 20130923 by Yinli, A verno-number is reserved for the new trunk branch 11C
           # p0.07 , 20130816 by Yinli, Add CheckFileWithKeyword()
           # m0.06 , 20130201 by mei, Add WriteCSV()
           # m0.05 , 20130115 by mei, Add WriteFileContent()
           # v0.03 , 20120612 by Carina, Error message refinement
           # v0.02 , 20120512 by mei, strengthen funcationality for ParseCSV()
           # v0.01 , 20120504 by mei, initial version
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


#****************************************************************************
# subroutine:  Dec2Hex: translate dec number to hex string
# input:       Number in dec
# output:      hex in string 
#****************************************************************************
#Hex2Dex() : hex string to dec number = hex()
sub Dec2Hex
{
    my ($num) = @_;
    return sprintf("0x%x", $num);
}

#****************************************************************************
# subroutine:  GetFileContent
# input:   strFilePath
# output:  strFileContent after chomp
#****************************************************************************
sub GetFileContent
{
    my ($strFilePath) = @_;
    my $content;
    open FILE, "<$strFilePath" or &error_handler("[2.0]$strFilePath: open file error!", __FILE__, __LINE__, 'CommonUtil::GetFileContent');
    {
        local $/;
        $content = <FILE>;
    }
    close FILE;
    chomp($content);
    return $content;
}

#****************************************************************************
# subroutine:  WriteFileContent
# input:   $strFilePath, $$strFileContent, 
#          $bAppend: 0 or undef= not append in the file, 1=need to append
# output:  x
#****************************************************************************
sub WriteFileContent
{
    my ($strFilePath, $strContent, $bAppend) = @_;
    my $strAppend = "";
    $strAppend = ">" if($bAppend);
    open FILE, ">$strAppend$strFilePath" or &error_handler("[2.0]$strFilePath: open file error!", __FILE__, __LINE__, 'CommonUtil::WriteFileContent');
    print FILE $strContent;    
    close FILE;
}

#****************************************************************************
# subroutine:  ParseCSV
# input:   1. strFilePath
#          2. $bSkipFirstLine: 1=skip, 0 or undef=not to skip
# output:  1. \@ContentList: array reference [[column, column, column...], [column, column, column...], ...]
#          2. \%IndexByName: if $bSkipFirstLine==1, return empty hash; if not, return hash reference in Name=>index
#****************************************************************************
sub ParseCSV
{
    my ($strFilePath, $bSkipFirstLine) = @_;
    my @ContentList;
    my @LineMeaning;
    my %IndexByName;
    open FILE, "<$strFilePath" or &error_handler("[1.4/2.0]$strFilePath: open file error!", __FILE__, __LINE__, 'CommonUtil::ParseCSV');
    if(1 != $bSkipFirstLine)
    {
        my $FirstLine = <FILE>;
        chomp($FirstLine);
        @LineMeaning = split(/,/, $FirstLine, -1);
        for(my $i=0; $i<=$#LineMeaning ; $i++)
        {
            $IndexByName{$LineMeaning[$i]} = $i;
        }
    }
    while(<FILE>)
    {
        chomp;
        my @entry = split(/,/, $_, -1);
        for(my $i= (scalar(@LineMeaning)- scalar(@entry)); (($i>0) && (1 != $bSkipFirstLine)); $i--)
        {
            push @entry, "";
        }
        my @Removed_Empty; # to replace "  " by ""  
        foreach my $item(@entry)
        {
            my $orgitem = $item;
            $item =~ s/\s//g;
            push (@Removed_Empty, ($item eq "") ? "" : $orgitem );
        }
        push @ContentList, \@Removed_Empty;
    }
    close FILE;
    return (\@ContentList, \%IndexByName);
}
#****************************************************************************
# subroutine:  WriteCSV
# input:   1. strFilePath
#          2. $ContentList_aref: \@ContentList: array reference [[column, column, column...], [column, column, column...], ...]
#          3. $Index_href: \%IndexByName: if $bSkipFirstLine==1, return empty hash; if not, return hash reference in Name=>index
# output:  N/A
#****************************************************************************
sub WriteCSV
{
    my ($strFilePath, $ContentList_aref, $Index_href) = @_;
    my $strContent;
    if(defined $Index_href)
    {
        my $nColumnCount = keys %$Index_href;
        my %ColumnName = reverse %$Index_href;
        for(my $i=0; $i<$nColumnCount; $i++)
        {
            $strContent .= $ColumnName{$i};
            $strContent .= "," if($i != $nColumnCount-1);
        }
        $strContent .= "\n";
    }
    foreach my $Content (@$ContentList_aref)
    {
        $strContent .= join(",", @$Content) . "\n";
    }
    WriteFileContent($strFilePath, $strContent, 0);
}


#****************************************************************************
# subroutine:  ConnetString
# input:   1. \@token
#          2. string to conect
#          3. $bConnectEmptyString: 1=support emptystring connect, 0 or undef=not support it
# output:  string
#****************************************************************************
sub ConnetString
{
    my ($token_ref, $strConnector, $bConnectEmptyString) = @_;
    my $strResult;
    if($bConnectEmptyString)
    {
        $strResult = join($strConnector, @$token_ref);
    }
    else
    {
        foreach my $i (@$token_ref)
        {
            my $temp = $i;
            $temp =~ s/\s//g;
            if($strResult eq "" and $temp ne "")
            {
                $strResult = $i;
            }
            else
            {
                $strResult = join($strConnector, $strResult, $i) if($i ne "");
            }
        }
    }
    return $strResult;
}

#****************************************************************************
# subroutine: CheckFileWithKeyword: check the existent file contains $Keyword or not
# input:      $FilePath : the file path you want to check
#             $Keyword : the keyword you want to search in the file
# return:     TRUE: the file contains  $Keyword
#             FALSE: the file doesn't contains $Keyword
#****************************************************************************
sub CheckFileWithKeyword
{
    my ($FilePath, $Keyword) = @_;
    my $strContent = &GetFileContent($FilePath);
    return ($strContent =~ /$Keyword/) ? 'TRUE' : 'FALSE';
}
