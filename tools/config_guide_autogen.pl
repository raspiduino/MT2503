#!/usr/local/bin/perl -w

#******************************************************************************
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2007
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
#******************************************************************************

#******************************************************************************
#
# Filename:
# ---------
# config_guide_autogen.pl
#
# Project:
# --------
# 
#
# Description:
# ------------
# Generate MMI feature options configuration guide(chm) automatically
# 
#
# Author:
# -------
# Woody (mtk80753)
#
#==============================================================================
#             HISTORY
# Below this line, this part is controlled by version control system. DO NOT MODIFY!!
#------------------------------------------------------------------------------
# $Log$
#
# 2012/12/22   Create.
#------------------------------------------------------------------------------
# Upper this line, this part is controlled by version control system. DO NOT MODIFY!!
#==============================================================================
#******************************************************************************

use lib "./tools";
#print "\@INC is @INC\n";

use strict;
use Cwd;
use File::Basename;
use XML::Simple;
use Data::Dumper;
use encoding 'utf8';
use Office;
use DataBase;

#Add by Woody 2012/1/13
use Win32::OLE qw(CP_UTF8);
$Win32::OLE::CP=CP_UTF8;

#******************************************************************************************
# Global Data
#******************************************************************************************
my $g_CWD="";
my $g_DBPath="";
my $g_Log="..\\Doc\\MMI_CONFIG_GUIDE\\Source\\MMI_Config_Guide.log";

#Used by Hierarchy Update 
my $g_DOMProjectPath="..\\Doc\\DOM\\Config\\";
my $g_DOMProjectFileName="MMI_Config_Guide.dox";
my $g_DOMTopicFileName="MMI_Config_Guide.dtx";
my $g_Sequence= "Seq";

#Used by HeaderFile Generator
my $g_TempHeadFilePath = "..\\Doc\\MMI_CONFIG_GUIDE\\Output\\";
my $g_TempHeadFileName = "MMI_features_tmp.h";

#Used by Image Process
my $g_OutputPathName="..\\Doc\\MMI_CONFIG_GUIDE\\Output";
my $g_ImageRootPath="..\\Doc\\MMI_CONFIG_GUIDE\\Source\\";
my $g_ConvertPath="..\\plutommi\\Customer\\ResGenerator\\convert.exe";

#******************************************************************************************
# Main Flow
#******************************************************************************************
print "\n[ok] MMI Configuration Guide Autogen started! Please wait for several minutes...\n";

{
	chdir "./tools";
	
	#Create a duplicate of STDOUT and STDERR
	open my $oldout, ">&", \*STDOUT or die "Cannot dup STDOUT: $!";
	open STDOUT, ">$g_Log" or die "Cannot create logfile $g_Log: $!";
	open my $olderr, ">&", \*STDERR or die "Cannot dup STDERR: $!";
	open STDERR, ">&STDOUT" or die "Cannot redirect STDERR";
	select STDERR;
	$|=1;
	
	$g_CWD=getcwd;
	if($g_CWD =~ /(tools)/)
	{
		$g_DBPath=$`."plutommi\\Customer\\MMI_features.xls";
	}

	&DataBase::DBOpen($g_DBPath);
	print $oldout "\%20\n";

	&HierarchyUpdate();
	&HeaderFileGenerate($g_TempHeadFilePath);
	
	&ImageProcess($g_ImageRootPath);
	print $oldout "\%50\n";

	&GenerateCHM();
	print $oldout "\%100\n";

	&DataBase::DBClose();

	#Restore original STDOUT
	open STDOUT, '>&', $oldout or die "Cannot restore \$oldout: $!";
	open STDERR, '>&', $olderr or die "Cannot restore \$olderr: $!";

}

print "\n[ok] MMI Configuration Guide Autogen finished! Please check the log file:\n$g_Log\n\n";

exit;

#******************************************************************************************
# Sub functions
#******************************************************************************************

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  HierarchyUpdate
# DESCRIPTION
#  Update hirarchy information in DOM project file and topic file
# PARAMETERS
#  None
# RETURNS
#  None
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub HierarchyUpdate()
{
	print "[Output][HierarchyUpdate] start...\n";
	eval
	{
		# 1. Abstract hierarchy information from database
		my $rhHierarchy = &DataBase::DBGetHierarchy();
		#&DataBase::PrintHierarchy($rhHierarchy);

		# 2. Get sorted options from databas
		my $rhSortOptions = &DataBase::DBGetSortOptions();
		#&DataBase::PrintClassOptions($rhSortOptions);

		# 3. Update hierarchy into DOM project file
		&WriteDOM($g_DOMProjectPath, $rhHierarchy, $rhSortOptions);	
	};
	if($@)
	{
		print "[Error][HierarchyUpdate]: $@\n\n";
		die "[Error][HierarchyUpdate]: $@\n\n";
	}
	
	print "[Output][Hierarchy Update] done\n\n";
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  HeaderFileGenerate
# DESCRIPTION
#  Generate temp header file which will be used by DOM later
# PARAMETERS
#  $g_TempHeadFilePath[In] - Temp head file path
#  
# RETURNS
#  None
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub HeaderFileGenerate()
{	
	print "[Output][HeaderFileGenerate] start...\n";
	my $Path="";
	eval
	{
		$Path="$g_TempHeadFilePath$g_TempHeadFileName";

		my %nonReleaseFeature = ();

		my @OptionsComment = ();       	#All options' comment to be wrriten into head file

		&GenOptionsComment(\@OptionsComment, \%nonReleaseFeature);

		# generate temp header file
		&WriteHeadFile($Path, \@OptionsComment);
	};
	if($@)
	{
		print "[Error][HeaderFile Generate]:$Path $@\n\n";
		die "[Error][HeaderFile Generate]:$Path $@\n\n";
	}
	
	print "[Output][HeaderFileGenerate] done\n\n";
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  ImageProcess
# DESCRIPTION
#  
# PARAMETERS
#  $RootPath[In] - The root path of all images
#
# RETURNS
#  None
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub ImageProcess()
{
	my $RootPath;
	($RootPath)=@_;

	print "[Output][ImageProcess] start...\n";
	
	my $raSortFeatures=&DataBase::DBGetAllSortFeatures();
	foreach my $Feature (@{$raSortFeatures})
	{
		my $CFGName="";

		my $Class=&DataBase::DBGetFeatureClass($Feature);

		#if a duplicated option, its class is like [Slim][XXX(Slim)], we use the class to form folder path to find images here
		#But local folder doesn't contain (Slim), so we should remove it
		my $TopClass = &DataBase::DBGetTopClass($Class);
		$Class =~ s/(\($TopClass\)\])$/\]/g;
		
		$Class =~ s/\[\]/\\/g;
		$Class =~ s/\[/\\/g;
		$Class =~ s/\]/\\/g;
		$Class =~ s/\\\\/\\/g;
		$Class =~ s/\s+/_/g;
		$CFGName=&DataBase::DBGetCfgName($Feature);
		my $ImagePath="$RootPath\\$Class\\$CFGName";

		next if(!-e $ImagePath);
		
		eval
		{
			my @ImageNames;
			my @JpgNames=glob "$ImagePath"."\\*.jpg";
			my @BmpNames=glob "$ImagePath"."\\*.bmp";
			my @PngNames=glob "$ImagePath"."\\*.png";
			push @ImageNames, @JpgNames;
			push @ImageNames, @BmpNames;
			push @ImageNames, @PngNames;
			foreach my $Image (@ImageNames)
			{    
				my($filename, $directories, $suffix) = fileparse($Image);	
				my $src="$Image";
				my $Dst="$g_OutputPathName\\$CFGName"."_$filename";
				my $cmd="$g_ConvertPath $Image -resize x320^> $Dst"; 
				system($cmd);
			}
			
			@ImageNames=glob "$ImagePath"."\\*.jpeg";
			foreach my $Image (@ImageNames)
			{    
				my($filename, $directories, $suffix) = fileparse($Image);	
				my $src="$Image";
				my $Dst="$g_OutputPathName\\$CFGName"."_$filename";
				$Dst =~ s/.jpeg$/.jpg/i;
				my $cmd="$g_ConvertPath $Image -resize x320^> $Dst"; 
				system($cmd);
			}
			
		};
		if($@)
		{
			print "[Error] [Image process] $CFGName: $@, continuing...\n";
		}
	}
	print "[Output][ImageProcess] done\n\n";
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  GenerateCHM
# DESCRIPTION
#  
# PARAMETERS
#  $RootPath[In] - The root path of all images
#
# RETURNS
#  None
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub GenerateCHM()
{
	my $dom_ret;
	eval
	{
		my $dom_dir = "C:\\Program Files\\Doc-O-Matic 6 Professional\\dmcc.exe";
		my $project_dir = "$g_DOMProjectPath$g_DOMProjectFileName";
		my $dom_cmd = "\"$dom_dir\" -config \"MTKDocConfig-CHM\" -noshow  -w2 -i 558 \"$project_dir\"";
		#print "GenerateCHM cmd: \n$dom_cmd\n";
		$dom_ret = system("$dom_cmd");
	};
	if($@)
	{
		print "[Error][GenerateCHM]: $@\n\n";
		die "[Error][GenerateCHM]: $@\n\n";
	}

	#Move .chm to the same folder with .log file 
	my $chm_folder;
	my $chm_file;
	my $dst_path;
	
	if($g_CWD =~ /(tools)/)
	{
		$chm_folder=$`."Doc\\MMI_CONFIG_GUIDE\\Output";
		$chm_file=$chm_folder."\\*.chm";
		$dst_path=$`."Doc\\MMI_CONFIG_GUIDE";
	
		$chm_folder =~ s/\//\\/g;
		$chm_file =~ s/\//\\/g;
		$dst_path =~ s/\//\\/g;
	}
	system ("move /Y $chm_file $dst_path");
	system ("del /F /S /Q /A $chm_folder\\*.*");
	system ("rd /Q $chm_folder");
	printf "\n[ok][GenerateCHM] done! Result = %g\n\n", $dom_ret;
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  WriteDOM
# DESCRIPTION
#  Write hierarchy information into DOM porject files
# PARAMETERS
#  $refHierarchy[In] - hierarchy information
#  $g_DOMProjectPath[In] - DOM proejct path
# RETURNS
#  None
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub WriteDOM()
{
	my $g_DOMProjectPath;
	my $refHierarchy;
	my $rhClassOptions;
	($g_DOMProjectPath,$refHierarchy, $rhClassOptions) = @_;
	
	my $ProjectPath = $g_DOMProjectPath.$g_DOMProjectFileName;
	my $TopicPath = $g_DOMProjectPath.$g_DOMTopicFileName;
	my $HierarchyDataHeader;
	my $HierarchyData;
	my $TopicData;
	my $TopicCount=0;

	###Format new Topic and Hierarchy data###
	#Topic hierarchy data
	my $refSeq1 = $refHierarchy->{$g_Sequence};
	foreach my $key1 (@{$refSeq1})
	{
		my $value1 = $refHierarchy->{$key1};

		#Skip "Operator"
		next if $key1 eq "Operator";
		
		$TopicData .= "@@".$key1."\n\\ \\ \n\n";
		$HierarchyData.="\[External Topic Properties\\$key1\]\nCount=1\nETPCommand0=3\nETPGroup0=' !'\n\n";
		$HierarchyDataHeader.="ID".$TopicCount."=".$key1."\n";

		my $refSeq2 = $value1->{$g_Sequence};
		foreach my $key2 (@{$refSeq2})
		{
			my $value2 = $value1->{$key2};
			
			$TopicCount++;
			$TopicData .= "@@".$key2."\n\\ \\ \n\n";
			$HierarchyData.="\[External Topic Properties\\$key2\]\nCount=1\nETPCommand0=3\nETPGroup0=$key1\n\n";
			$HierarchyDataHeader.="ID".$TopicCount."=".$key2."\n";

			my $refSeq3 = $value2->{$g_Sequence};
			foreach my $key3 (@{$refSeq3})
			{
				my $value3 = $value2->{$key3};
				
				$TopicCount++;
				$TopicData .= "@@".$key3."\n\\ \\ \n\n";
				$HierarchyData.="\[External Topic Properties\\$key3\]\nCount=1\nETPCommand0=3\nETPGroup0=$key2\n\n";
				$HierarchyDataHeader.="ID".$TopicCount."=".$key3."\n";

				my $refSeq4 = $value3->{$g_Sequence};
				foreach my $key4 (@{$refSeq4})
				{			
					$TopicCount++;
					$TopicData .= "@@".$key4."\n\\ \\ \n\n";
					$HierarchyData.="\[External Topic Properties\\$key4\]\nCount=1\nETPCommand0=3\nETPGroup0=$key3\n\n";
					$HierarchyDataHeader.="ID".$TopicCount."=".$key4."\n";
				}
			}
		}
		$TopicCount++;
	}
	
	#Option sequence
	while((my $key, my $value) = each (%{$rhClassOptions}))
	{
		if(defined($value))
		{	
			my $option_index=&GetOptionOrder($key, $refHierarchy);
			if($option_index>0)
			{
				my $test;
			}
			foreach my $option (@{$value})
			{
				my $CFGOption = &DataBase::DBGetCfgName($option);
				$TopicCount++;
				$HierarchyData.="\[External Topic Properties\\$CFGOption\]\nCount=1\nETPCommand0=2\nETPTopicOrder0=$option_index\n\n";
				$HierarchyDataHeader.="ID".$TopicCount."=".$CFGOption."\n";
				$option_index++;
			}
		}
	}
	
	$HierarchyDataHeader="\[External Topic Properties\]\nCount=$TopicCount\n".$HierarchyDataHeader; 
	$HierarchyData=$HierarchyDataHeader."\n".$HierarchyData;
	$HierarchyData.="\[File Extensions\]";
	
	###Write topic data into DOM topic file ".dtx"###
	my $mode = 0100666;
	chmod($mode, $TopicPath);	#remove "readonly" property
	open TOPIC, ">", $TopicPath or die "[Error]: Cannot open DOM project topic file: $TopicPath!";
	print TOPIC $TopicData;
	close TOPIC;
	print "[OK][Write topic] into $TopicPath\n";

	###Write hierarchy information into DOM project file ".dox"###
	#Get data from source project file and stored in $PojectLines
	chmod($mode, $ProjectPath);	#remove "readonly" property
	open PROJECTFILE, "<", $ProjectPath or die "[Error]: Cannot open DOM project file: $ProjectPath!";
	my $PojectLines = join '', <PROJECTFILE>;
	close PROJECTFILE;
	#Deal with the source data
	$PojectLines =~ s/\[External Topic Properties\].*\[File Extensions\]/$HierarchyData/gs;
	#Write new data into bak file
	open PROJECT_BAK, ">", $ProjectPath.".bak" or die "[Error]: Cannot open bak DOM project file!"; 
	print PROJECT_BAK $PojectLines;
	close PROJECT_BAK;
	#Delete source file
	unlink $ProjectPath;
	#Rename bak file to source file name
	rename $ProjectPath.".bak",$ProjectPath;
	print "[OK][Write Hierarchy] into $ProjectPath\n";
}

#******************************************************************************
# FUNCTION
#  GenOptionsComment
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
sub GenOptionsComment()
{
	my $raOptionsComment;       	# reference to switch desc. (output)
	my $rhNonRelFeature;          	# non-release feature list
	($raOptionsComment, $rhNonRelFeature) = @_;

	my $raSortedFeatureNames=&DataBase::DBGetAllSortFeatures();

	my $lastClass = "";
	my $if_operator = "no"; 
	foreach my $feature (@{$raSortedFeatureNames})
	{	
		my $optionList = &DataBase::DBGetFeatureOptionList($feature);
		my $optionSetting = &DataBase::DBGetFeatureOptionSetting($feature);
		
		# only process option setting which is not empty, $str_x, $str_not_finished
		if (&DataBase::DBIsFeatureSwitchable($optionSetting))
		{
			my $class = &DataBase::DBGetFeatureClass($feature);
			my $description = &DataBase::DBGetFeatureDescription($feature);
			my $refDoc = &DataBase::DBGetFeatureRefDoc($feature);
			my $mmipackage = &DataBase::DBGetFeaturePackage($feature);

			#Translate option list and setting
			$optionList = &DataBase::DBTransOptionList($optionList);
			$optionSetting = &DataBase::DBTransOptionSetting($optionSetting);

			#Get option value data from option_desc.xml
			my $OptionValue = &GetOptionValueData(&DataBase::DBGetCfgName($feature), $class);
			
			#Format dependency table
			my $dependency = &FormatDependencyTable($feature);

			#Format comments for the option
			my $bottom_class = &DataBase::DBGetBottomClass($class);
			my $comments=&FormatOptionComment($feature,$bottom_class,$description, 
				$optionList, $optionSetting, $OptionValue, $dependency, $mmipackage, $refDoc);

			#Add this option's comment into the Array
			push @{$raOptionsComment},$comments; 
		}              
    }    
}

#******************************************************************************
# FUNCTION
#  GetOptionValueData
# DESCRIPTION
#  Get a option's preview data(CFG_XXX)
# PARAMETERS
#  $OptionName - The name of the option
# RETURNS
#  $OptionPrvData - Preview data(string)
#******************************************************************************
sub GetOptionValueData()
{
	my $OptionName; #in
	my $OptionClass;
	($OptionName, $OptionClass) = @_;

	my $OptionPrvData;	#out
	
	if($OptionClass)
	{
		my $TopClass = &DataBase::DBGetTopClass($OptionClass);
		$OptionClass =~ s/(\($TopClass\)\])$/\]/g;

		$OptionClass =~ s/\[\]/\\/g;
		$OptionClass =~ s/\[/\\/g;
		$OptionClass =~ s/\]/\\/g;
		$OptionClass =~ s/\\\\/\\/g;
		$OptionClass =~ s/\s+/_/g;
	}

	my $OptionDescFilePath = "$g_ImageRootPath$OptionClass$OptionName\\option_desc.xml";

	if (-e $OptionDescFilePath)
	{
		eval
		{
			# Create object
			my $OptionXml = new XML::Simple;

			# Read data from XML file
			my $OptionData = $OptionXml->XMLin($OptionDescFilePath, KeyAttr =>'', ForceArray=>1);

			# print output, debug usage
			#print Dumper($OptionData);

			#Header: "Option" flag and option value list
			
			my @OptionValList;
			my @OptionsVal;
			my $OptionVal = $OptionData->{"opt_val"};

			@OptionsVal = @{$OptionVal};
			foreach my $refhashOptionVal (@OptionsVal)
			{
				push @{OptionValList}, $refhashOptionVal->{"name"};
			}
			$OptionPrvData = "Option:\n" . "<b>[@OptionValList]</b>\n\n";

			#Get option detail values
			foreach my $refhashOption (@OptionsVal)
			{
				#Option value name
				my %OptionVal = %{$refhashOption};
				my $OptionValName = ${OptionVal}{"name"};
				$OptionPrvData.="<b>[$OptionValName]</b>\n\n";

				#Description
				$OptionPrvData.= "<u>Description:</u>\n";
				my $raOptionDesc = ${OptionVal}{"desc"};
				if(defined($raOptionDesc))
				{
					my @OptionDesc = @{$raOptionDesc};
					my $Desc =  join('',@OptionDesc);
					$Desc = &Check($Desc);
					$OptionPrvData.= "$Desc\n\n";			
				}

				#Description images
				my $raDescImages = ${OptionVal}{"image"};
				if(defined($raDescImages))
				{
					my @DescImages = @{$raDescImages};
					foreach my $rhDescImage (@DescImages)
					{
						my $DescImageName = $rhDescImage->{"name"};
						$DescImageName =~ s/\.(\w+)$//; # Remove extension name
						$DescImageName = "${OptionName}_${DescImageName}";
						$OptionPrvData.= "<img name=\"$DescImageName\" />\n\n";
					}
				}
				
				#Examples
				my $raOptionExamples = ${OptionVal}{"example"};
				if(defined($raOptionExamples))
				{
					my @OptionExamples = @{$raOptionExamples};
					my $ExmpIndex = 1;
					foreach my $refhashExample (@OptionExamples)
					{
						my %Example = %{$refhashExample};

						#Get descriptions of current example
						my @ExampleDesc;
						@ExampleDesc = @{${Example}{"desc"}} if (defined(${Example}{"desc"}));
						my $EmplDesc = join('',@ExampleDesc);
						$EmplDesc = &Check($EmplDesc);
						if(@OptionExamples > 1)
						{
							$OptionPrvData.= "<u>Example $ExmpIndex:</u>\n$EmplDesc\n";
						}
						else
						{
							$OptionPrvData.= "<u>Example:</u>\n$EmplDesc\n";
						}

						#Get images of current example
						my @ExampleImages;
						@ExampleImages = @{${Example}{"image"}} if (defined(${Example}{"image"}));
						foreach my $rImage (@ExampleImages)
						{
							my $Image = ${$rImage}{"name"};
							$Image =~ s/\.(\w+)$//; # Remove extension name
							$Image = "${OptionName}_${Image}";
							
							$OptionPrvData.= "<img name=\"$Image\" />\n";
						}

						$OptionPrvData.= "\n";

						$ExmpIndex++;
					}			
				}

			}
			
			
		};
		if($@)
		{
			print "[Error] Parsing $OptionClass$OptionName: $@, continuing\n";
			return "";
		}
		else
		{
			return $OptionPrvData;
		}
		
	}
	else
	{
		#print "[Warn] $OptionClass$OptionName xml not exist, continuing\n";
		return "";
	}
}


sub FormatDependencyTable()
{
	my $feature;
	($feature) = @_;

	my @DepCFG;
	my @DepGlobal;
	&DataBase::DBGetFeatureDependency($feature,\@DepCFG, \@DepGlobal);

	return "" if((@DepCFG eq 0) && (@DepGlobal eq 0));
	
	my @DepComments;
	push @DepComments, "<xtable columnwidth=\"50c%\">";

	#CFG
	if(@DepCFG == 0)
	{
		push @DepComments, "<b>MMI Feature       N/A";
		push @DepComments, " Option</b>           ";
		push @DepComments, "                      ";
	}
	elsif(@DepCFG == 1)
	{
		push @DepComments, "<b>MMI Feature       1. $DepCFG[0]";
		push @DepComments, " Option</b>           ";
		push @DepComments, "                      ";
	}
	elsif(@DepCFG == 2)
	{
		my $Index = 1;
		foreach my $CFG (@DepCFG)
		{
			if($Index ==1)
			{
				push @DepComments, "<b>MMI Feature       $Index. $CFG";
			}
			else
			{
				push @DepComments, " Option</b>           $Index. $CFG";
			}
			
			$Index++;
		}
		push @DepComments, "                      ";
	}
	else
	{
		my $Index = 1;
		foreach my $CFG (@DepCFG)
		{
			if($Index ==1)
			{
				push @DepComments, "<b>MMI Feature       $Index. $CFG";
			}
			elsif($Index == 2)
			{
				push @DepComments, " Option</b>           $Index. $CFG";
			}
			else
			{
				push @DepComments, "                      $Index. $CFG";
			}
			
			$Index++;
		}
	}
	
	#Global
	if(@DepGlobal == 0)
	{
		push @DepComments, "<b>Global            N/A";
		push @DepComments, " Compile Option</b>   ";
		push @DepComments, "                      ";
	}
	elsif(@DepGlobal == 1)
	{
		push @DepComments, "<b>Global            1. $DepGlobal[0]";
		push @DepComments, " Compile Option</b>   ";
		push @DepComments, "                      ";
	}
	elsif(@DepGlobal == 2)
	{
		my $Index = 1;
		foreach my $Global (@DepGlobal)
		{
			if($Index ==1)
			{
				push @DepComments, "<b>Global            $Index. $Global";
			}
			else
			{
				push @DepComments, " Compile Option</b>   $Index. $Global";
			}

			$Index++;
		}
		push @DepComments, "                      ";
	}
	else
	{
		my $Index = 1;
		foreach my $Global (@DepGlobal)
		{
			if($Index ==1)
			{
				push @DepComments, "<b>Global            $Index. $Global";
			}
			elsif($Index == 2)
			{
				push @DepComments, " Compile Option</b>   $Index. $Global";
			}
			else
			{
				push @DepComments, "                      $Index. $Global";
			}
			
			$Index++;
		}
	}

	push @DepComments, "</xtable>";
	
	return join("\n", @DepComments);
}
sub FormatOptionComment()
{   
	my $feature;
	my $class;
	my $description;
	my $optionList;
	my $optionSetting;
	my $optionValue;
	my $dependency;
	my $mmipackage;
	my $refDoc;
	($feature, $class, $description, $optionList, $optionSetting, $optionValue, $dependency, $mmipackage, $refDoc) = @_;

	# Section name in headfile
	my $str_description = "Description";
	my $str_option = "Option";
	my $str_refDoc = "Reference"; 
	my $str_dependency = "Dependency"; 
	my $str_mmipackage = "Package"; 
	my $str_sepBegin = "/*****************************************************************************";
	my $str_sepEnd   = "*****************************************************************************/";

	
	my @tmp;

	$description =~ s/\n//g if $description;
	$refDoc =~ s/[\n]+/, /g if $refDoc; 

	my $cfgName = &DataBase::DBGetCfgName($feature);

	push @tmp, "<GROUP $class>\n\n";
	push @tmp, "$str_description:\n$description\n\n" if $description;
	push @tmp, "$optionValue\n" if $optionValue;
	push @tmp, "$str_dependency:\n$dependency\n\n" if $dependency;
	push @tmp, "$str_mmipackage:\n$mmipackage\n\n" if $mmipackage;
	push @tmp, "$str_refDoc:\n$refDoc\n" if $refDoc;

	my $Comment = join('',@tmp);
	$Comment = "$str_sepBegin\n$Comment$str_sepEnd\n#define $cfgName\t($optionSetting)\n\n";
	
	return $Comment; 
}

#******************************************************************************************
# FUNCTION
#  WriteHeadFile
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************************
sub WriteHeadFile()
{
    my $filename;
    my $raOptionComments;      # reference to switch description array
    
    ($filename, $raOptionComments) = @_;
    
    my $hHeadFile;
    
    open($hHeadFile, '>:utf8', $filename) or die "[ERROR] can't open $filename $!\n";        
	my $Comments = join('', @$raOptionComments);
	print $hHeadFile "\x{feff}";#Write BOM
    print $hHeadFile $Comments;
    close($hHeadFile);
}

sub Check()
{
	my $str;
	($str) = @_;

	$str =~ s/^([\s]+) |([\s]+)$//g;
	$str =~ s/\n+\t+/\n/g;

	# utf-8 => gb2312
	#$str = encode("gb2312",decode("utf-8",$str));
	#$str =~ s/([x{80}-x{FFFF}])/'&#'.ord($1).';'/gse;
	
	return $str;
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  Trim
# DESCRIPTION
#  Remove blanks(Begining and Endding)
# PARAMETERS
#  Invalid string
# RETURNS
#  Valid string
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub GetOptionOrder()
{
	(my $option_class, my $rhHierarchy) = @_;

	while((my $key1, my $value1) = each %{$rhHierarchy})
	{
		next if $key1 eq $g_Sequence;
		
		if($option_class eq $key1)
		{
			my $refSeq = $value1->{$g_Sequence};
			return @{$refSeq} if(defined($refSeq));
			return 0;
		}
		else
		{
			my $order = &GetOptionOrder($option_class, $value1);
			return $order if($order > 0);	
		}
	}
    
    	return 0;
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  Trim
# DESCRIPTION
#  Remove blanks(Begining and Endding)
# PARAMETERS
#  Invalid string
# RETURNS
#  Valid string
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub Trim()
{
    my $str;
    ($str) = @_;

	if($str)
    {
    	$str =~ s/(^\s*)|(\s*$)//g;
    }
    
    return $str;
}

