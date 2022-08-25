#!/usr/bin/perl
#
# Filename: 
# ---------
#  DLT_GenConverterData.pl
#
# Description: 
# ------------
#  used to generate DLT converter data.
#
# Auther: 
# -------
#  mtk01542
# 
# Note:
# -----
#  none.
#
# Log: 
# -----
#  2006/12/26   Create.
#

BEGIN { push @INC, '..\..\..\tools'}  # add additional library path
#package XXX;                           # declare package library
use strict;

use Office;

#******************************************************************************
# Global Data
#******************************************************************************
my $dataFile = "DLT_ThemeTagMapping.xls";
my $outputFilename = "mmi_theme_converter_data.h";
my $outputPath = "..\\..\\Framework\\ThemeManager\\ThemeManagerInc";
my $mmiThemeFile = "CustThemesRes.h";
my $mmiThemePath = "..\\..\\mmi\\inc";

my $tagImageList = 'ImageList';

#******************************************************************************
# Export Function
#******************************************************************************

#******************************************************************************
# Internal Data
#******************************************************************************


#******************************************************************************
# Program Start
#******************************************************************************
my $filename = getCurrDir()."\\$dataFile";

# tag related 

my $indexRow_tag = 1;
my %xmlHash = ();   # tag data
my $idx_tagHdlr = 1;
my $idx_fieldName = 2;

my $str_tagName = "Tag Name";
my $str_tagHdlr = "Tag Handler";
#my $str_fieldName = "field name of MMI_theme";
my $str_fieldName = "in MMI_theme struct";
my @indexStrArray = ($str_tagName, $str_tagHdlr, $str_fieldName);

# image id related

my $indexRow_imgList = 2;
my %imgDataHash = ();

my $str_imgAttr = "Image Attribute Name";
my $str_imgId = "Image ID in target";
my $str_imgCmplOption = "Compile Option";
my @indexStrArrayImgList = ($str_imgAttr, $str_imgId, $str_imgCmplOption);

my %indexHash = ();

my $row = 2;
my $tagName = "";

my @oriDataHead = ();
my @oriDataTail = ();
my @fileData = ();
my $dataSection = 'head';

&Office::excelOpen($filename);

# read tag data
&Office::excelGetColIndex(\@indexStrArray, \%indexHash, $indexRow_tag);
$tagName = trim(&Office::excelRead($row, $indexHash{$str_tagName}));
while ($tagName ne "")
{   
    $xmlHash{$tagName}[$idx_tagHdlr] = trim(&Office::excelRead($row, $indexHash{$str_tagHdlr}));
    $xmlHash{$tagName}[$idx_fieldName] = trim(&Office::excelRead($row, $indexHash{$str_fieldName}));

    $row++;
    $tagName = trim(&Office::excelRead($row, $indexHash{$str_tagName}));
}

# read image-id data
&Office::excelSetWorksheet($tagImageList);
&Office::excelGetColIndex(\@indexStrArrayImgList, \%indexHash, $indexRow_imgList);
$row = $indexRow_imgList + 1;
my $attrName = trim(&Office::excelRead($row, $indexHash{$str_imgAttr}));
while ($attrName ne "")
{
    my $imgId = trim(&Office::excelRead($row, $indexHash{$str_imgId}));
    my $cmplOption = trim(&Office::excelRead($row, $indexHash{$str_imgCmplOption}));

    die "duplicate: $attrName-$imgId\n" if (exists $imgDataHash{$attrName}{$imgId});
    $imgDataHash{$attrName}{$imgId} = $cmplOption;
    
    $row++;
    $attrName = trim(&Office::excelRead($row, $indexHash{$str_imgAttr}));
}

&Office::excelClose();

# sort tags and attrs
my @sortedTags = sort keys(%xmlHash);
my @sortedImgAttrs = sort keys(%imgDataHash);

my $outputFile = "$outputPath\\$outputFilename";

# read original data
open(hFile, "<$outputFile") or die "can't open $outputFile!\n";
@fileData = <hFile>;
close(hFile);
foreach my $line (@fileData)
{
    if ($dataSection eq 'head')
    {
        push @oriDataHead, $line;
        $dataSection = '' if ($line =~ /Converter Data Begins/);
    }
    elsif ($dataSection eq 'tail')
    {
        push @oriDataTail, $line;
    }
    else
    {
        if ($line =~/Converter Data Ends/)
        {
            $dataSection = 'tail';
            push @oriDataTail, $line;
        }
    }
}
push @oriDataHead, "\n";
unshift @oriDataTail, "\n";

open(hFile, ">$outputFile") or die "can't open $outputFile to write!\n";
@fileData = ();

# parse MMI_theme structure
&parseMMIThemeStruct(\@fileData, "$mmiThemePath\\$mmiThemeFile");

push @fileData, "MMI_theme_buff_type buffer_DLT;\n\n";
push @fileData, "#define BASE_PTR(x)\t\t(&(buffer_DLT.x))\n\n";

# generate tag data
push @fileData, "/* tags should be sorted in ASCII code order */\n";
push @fileData, "const tc_all_tags_index_struct g_tc_xml_tags_map[] = {\n";
foreach my $tag (@sortedTags)
{
    my $tagHdlr;
    
    die "tag handler is empty for $tag!!\n" if ($xmlHash{$tag}[$idx_tagHdlr] eq "");
    $tagHdlr = $xmlHash{$tag}[$idx_tagHdlr];
        
    #print "$tag [ver] = $xmlHash{$tag}[$idx_ver]\n";
    my $fieldName = $xmlHash{$tag}[$idx_fieldName];
    my $dltPtr = "NULL";
    my $basePtr = "NULL";
    
    #if ($fieldName !~ /^[\s]*$/)
    if ($fieldName =~ /^Y$/i)
    {
        $dltPtr = "DLT_PTR($tag)";  # tag name is same as MMI_theme field name
        if ($tagHdlr !~ /(mmi_tc_pu8_tag_handler)|(mmi_tc_s32_tag_handler)/)
        {
            $basePtr = "BASE_PTR($tag)";    # tag name is same as MMI_theme field name
        }
    }
    push @fileData, "\t{\"$tag\", $tagHdlr, (void *)$dltPtr, (void *)$basePtr},\n";
}
push @fileData, "};\n";

# generate image-id attribute data
push @fileData, "\n/* attributes should be sorted in ASCII code order */\n";
push @fileData, "const tc_image_tags_index_struct g_tc_image_tags_map[] = {\n";
foreach my $attr (@sortedImgAttrs)
{
    while (my ($key, $value) = each(%{$imgDataHash{$attr}}))
    {
        push @fileData, "#if $value\n" if ($value ne "");
        push @fileData, "\t{\"$attr\", $key},\n";
        push @fileData, "#endif\n" if ($value ne "");
    }
}
push @fileData, "};\n";

unshift @fileData, @oriDataHead;
push @fileData, @oriDataTail;
print hFile join('', @fileData);
close(hFile);

#******************************************************************************
# Internal Function
#******************************************************************************

#******************************************************************************
# FUNCTION
#  xxx
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************



#******************************************************************************
# FUNCTION
#  parseMMIThemeStruct
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
sub parseMMIThemeStruct()
{
    my $dataOut_ref;
    my $sourceFile;

    ($dataOut_ref, $sourceFile) = @_;
    
    my @fileData;
    my %buffList = ("UI_filled_area" => 1, "color" => 1);
    my $startParsing = 0;
    my $hFile;
    
    open($hFile, "<$sourceFile") or die "[ERROR] can't open $sourceFile!\n";
    @fileData = <$hFile>;
    close($hFile);
    
    foreach my $line (@fileData)
    {

        if ($line =~ /^[\s]*}[\s]*MMI_theme;/)
        {
            push @{$dataOut_ref}, "} MMI_theme_buff_type;\n\n\n";
            last;
        }

        if ($startParsing)
        {
            if ($line =~ /^[\s]*([\w]+)[\s]+([\w]+);/)
            {              
                # special handle for UI_font_type -> stFontAttribute
                if ($1 eq 'UI_font_type')
                {
                    push @{$dataOut_ref}, "\tstFontAttribute\t$2;\n";
                }
            }
            elsif ($line =~ /^[\s]*([\w]+)[\s]*\*[\s]*([\w]+);/)
            {
                push @{$dataOut_ref}, "\t$1\t$2;\n";
            }
            else
            {
                # skip continuous empty lines
                if (!(($line =~ /^[\s]*$/) && ($$dataOut_ref[scalar(@{$dataOut_ref})-1] =~ /^[\s]*$/)))
                {
                    push @{$dataOut_ref}, $line if ($line !~ /^[\s]*{/);
                }
            }
        }
        elsif ($line =~ /^[\s]*typedef[\s]+struct[\s]+_MMI_theme/)
        {
            push @{$dataOut_ref}, "typedef struct {\n";
            $startParsing = 1;
        }
    }
}


#******************************************************************************
# FUNCTION
#  getCurrDir
# DESCRIPTION
#  get current directory
# PARAMETERS
#  none
# RETURNS
#  current directory
#******************************************************************************
sub getCurrDir()
{
    use Cwd;    
    my $currDir;
    
    $currDir = getcwd;
    $currDir =~ s/\//\\/g;
    return $currDir;    
}


#******************************************************************************
# FUNCTION
#  trim
# DESCRIPTION
#  trim left and right spaces
# PARAMETERS
#  $str [IN] - string to process
# RETURNS
#  processed string
#******************************************************************************
sub trim()
{
    my $str;
    ($str) = @_;
    
    $str =~ s/(^\s*)|(\s*$)//g;
    return $str;
}
