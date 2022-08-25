#!/usr/bin/perl

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
#
# Filename: 
# ---------
#  DataBase.pm
#
# Description: 
# ------------
#  MAUI Database(xls) access functions.
#
# Auther: 
# -------
#  Woody(mtk80753)
# 
# Note:
# -----
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
package DataBase;	# declare package library
use strict;
use Office;

#******************************************************************************
# Global Data
#******************************************************************************
my $g_Sequence= "Seq";	#Sequence tag
my %g_hHierarchy=();	#Hash to store hierarchy inormation 	
my @g_aHierarchyNames=();	#All hiearchy names
my @g_aOperatorFeatures=();	#All operator features
my $g_Operator= "Operator";	#Operator tag


#Feature data structure: record all data of all features
#  --------------------------------------
#  |feature1 => <Hash reference1>		|
#  | 			  --------------------	|
#  | 			 |class => <data>	  |	|	
#  | 			 |optionList => <data>|	|	
#  | 			 |	.......			  | 		
#  | 			 --------------------	|
#  |feature2 => <Hash reference2>	  	|
#  | 			  ---------------------	|
#  | 			 |class => <data>	  |	|	
#  | 			 |optionList => <data>|	|	
#  | 			 |	.......			  |	|	
#  | 			  -------------------	|
#  |			 |	......			  |	|	
#  --------------------------------------
my %g_hFeatureData=();

# Class => Options, record options sequence according to DB sheet 2
my %g_hSortOptions=();

# column name. if you added a new item here, remember to add it to @g_colNames as well
my %g_str_class =         ('xml' => 'Class',          'xls' => 'Classification');
my %g_str_featureName =   ('xml' => 'Name',           'xls' => 'Feature[\s]*Name');
my %g_str_mmipackage =    ('xml' => 'MMIPackage',     'xls' => 'MMI[\s]*Package');
my %g_str_optionList =    ('xml' => 'OptionList',     'xls' => 'Option[\s]*List');
my %g_str_optionSetting = ('xml' => 'OptionSetting',  'xls' => 'Option[\s]*Setting');
my %g_str_defineValue =   ('xml' => 'DefineValue',    'xls' => 'Define[\s]*Value');
my %g_str_description =   ('xml' => 'Description',    'xls' => 'Description');
my %g_str_depAND =        ('xml' => 'DepAND',         'xls' => 'Dependency[\s]*\(AND\)');
my %g_str_depOR =         ('xml' => 'DepOR',          'xls' => 'Dependency[\s]*\(OR\)');
my %g_str_depERR =        ('xml' => 'DepERR',         'xls' => 'Dependency[\s]*\(ERR\)');
my %g_str_errMsg =        ('xml' => 'ErrMsg',         'xls' => 'Error[\s]*Message');
my %g_str_refDoc =        ('xml' => 'RefDoc',         'xls' => 'Reference[\s]*Doc.');
my %g_str_depMTK =        ('xml' => 'DepMTK',         'xls' => 'MTK[\s]*Internal[\s]*Description');
my %g_str_allowAutoRelease = ('xml' => 'AllowAutoRelease', 'xls' => 'Allow[\s]*AUTO[\s]*Release');
my %g_str_owner =         ('xml' => 'Owner',          'xls' => 'Owner');
my %g_str_lastUpdate =    ('xml' => 'LastUpdate',     'xls' => 'Last[\s]*Update');

# use 'xml' as data hash key
my $g_keyType = 'xml';

#Column names array
my @g_colNames = (\%g_str_class, \%g_str_featureName, \%g_str_mmipackage, \%g_str_optionList, 
                	\%g_str_optionSetting, \%g_str_defineValue, \%g_str_description, 
                	\%g_str_depAND, \%g_str_depOR, \%g_str_depERR, \%g_str_errMsg, \%g_str_refDoc,
                	\%g_str_allowAutoRelease, \%g_str_owner, \%g_str_lastUpdate);

#Option list and setting value
my $g_str_on = 'on';
my $g_str_off = 'off';
my $g_str_auto = 'auto';
my $g_str_x = '((x)|(n\/a))';
my $g_str_not_finished = 'not[\s]+finished';
my $g_macro_on = '__ON__';
my $g_macro_off = '__OFF__';
my $g_macro_auto = '__AUTO__';


return 1; # return true

#******************************************************************************
# Export Functions
#	DBXXX()
#******************************************************************************


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBOpen
# DESCRIPTION
#  DataBase open
# PARAMETERS
#  $DBPath: database file path(xls)
# RETURNS
#  N/A
# NOTE
#  Should be called before you using database.pm
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBOpen()
{
	my $DBPath;
	($DBPath) = @_;
	
	if (-e $DBPath)
	{
	}
	else
	{
		die "[ERROR] DB: $DBPath doesn't exist!\n";
	}

	my $errDirectiveCount = 0;
	my @errorLog = ();

	my $row = 0;
	&Office::excelOpen($DBPath);

	#####Read the hierarchy information#####
	&Office::excelSetWorksheet(2);
	$row = 2;
	my $HierarchyData = Trim(&Office::excelRead($row, 1));
	while ($HierarchyData !~ /^[\s]*$/)	#If not empty
	{
		$HierarchyData =~ s/\[/:/g;
		$HierarchyData =~ s/\]/:/g;
		$HierarchyData =~ s/::/:/g;
		$HierarchyData =~ s/^://g;
		my @HierarchyTemp = split	/:/, $HierarchyData;

		my $Options = &Office::excelRead($row, 2);
		$Options = &Trim($Options) if $Options;
		if($Options)
		{
			$Options = &Trim($Options);
			my @arrayOptions = split /\r?\n/, $Options;

			my $bottom_class = &DBGetBottomClass($HierarchyData);
			$g_hSortOptions{$bottom_class} = \@arrayOptions;

			my $top_class = &DBGetTopClass($HierarchyData);
			if($top_class eq $g_Operator)
			{
				push @g_aOperatorFeatures, @arrayOptions;
			}

			my $rhHierarchyTemp = \%g_hHierarchy;
			foreach my $Class (@HierarchyTemp)
			{
				AddHierarchy($Class, $rhHierarchyTemp, $top_class);
				$rhHierarchyTemp = $rhHierarchyTemp->{$Class};
			}	
		}
				
		# Read next line
		$row++;
		$HierarchyData = &Office::excelRead($row, 1);
		$HierarchyData = &Trim($HierarchyData) if defined($HierarchyData);
	}

	#####Read all feature data information#####
	&Office::excelSetWorksheet(1);
	my %colIndexHash;
	&GetColIndex(\%colIndexHash);	
	my @mycolNames_ref = ();
	foreach my $colName_ref (@g_colNames)
	{
	    push @mycolNames_ref, $colName_ref if ($colName_ref != \%g_str_featureName);
	}
	
	$row = 2;
	my $feature = &Office::excelRead($row, $colIndexHash{$g_str_featureName{'xls'}});
	$feature = &Trim($feature) if $feature;
	while ($feature !~ /^[\s]*$/)
	{          
	    # process error directive
	    if ($feature =~ /^\#error$/i)
	    {
	        $feature = "$feature$errDirectiveCount";
	        $errDirectiveCount++;
	    }
	    
	    # check for duplicate feature
	    push @errorLog, "[ERROR] $feature is duplicate!\n" if (defined $g_hFeatureData{$feature});
	    
	    foreach my $colName_ref (@mycolNames_ref)
	    {
	        # all data are stored in 'xml' key
	        my $colName = ${$colName_ref}{$g_keyType};
	        my $Value = Trim(&Office::excelRead($row, $colIndexHash{${$colName_ref}{'xls'}}));
	        if("Class" eq $colName)
	        {
	        	#Special case for "Class": update duplicated class
			${$g_hFeatureData{$feature}}{$colName} = &UpdateDuplicatedClass($Value);
	        }
	        else
	        {
		        ${$g_hFeatureData{$feature}}{$colName} = $Value;
	        }
	    }
	            
	    # read next feature name
	    $row++;
	    $feature = &Office::excelRead($row, $colIndexHash{$g_str_featureName{'xls'}});
	    $feature = &Trim($feature) if defined($feature);
	}      
	die "\n".join('', @errorLog) if (@errorLog);

	#Validate feature data
	&ValidateFeatureData(\%g_hFeatureData);
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBClose
# DESCRIPTION
#  DataBase close
# PARAMETERS
#  N/A
# RETURNS
#  N/A
# NOTE
#  Should be called when you finish using Database.pm
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBClose()
{
	&Office::excelClose();
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetHierarchy
# DESCRIPTION
#  Get MMI feature options hierarchy information from database
# PARAMETERS
# RETURNS
#  Reference of the hierarchy hash
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetHierarchy()
{
	return \%g_hHierarchy;
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetSortOptions
# DESCRIPTION
#  Get sorted options from database
# PARAMETERS
#  
# RETURNS
#  Reference of the options hash
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetSortOptions()
{
	return \%g_hSortOptions;
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetAllSortFeatures
# DESCRIPTION
#  Get all sorted feature names, the sequence follows DB record
# PARAMETERS
#  
# RETURNS
#  Reference of the feature names array
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetAllSortFeatures()
{
	my @allSortedFeatures = (); # all features

	#Sort all feature names
	while((my $key, my $value) = each %{g_hSortOptions})
	{	
		if (defined($value))
		{
			foreach my $option (@{$value})
			{
				push @allSortedFeatures,$option;
			}
		}
	}

	foreach my $feature (keys(%{g_hFeatureData}))
	{
		push @allSortedFeatures, $feature if(!grep /^$feature$/,@allSortedFeatures);          
	}
	
	return \@allSortedFeatures;
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetFeatureClass
# DESCRIPTION
#  Get the class of feature
# PARAMETERS
#  $Feature
# RETURNS
#  Class
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetFeatureClass()
{
	my $Feature;
	($Feature)=@_;
	
	my $class=${$g_hFeatureData{$Feature}}{$g_str_class{$g_keyType}};
	return $class if $class;
	return "";
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetFeaturePackage
# DESCRIPTION
#  Get the MMI package of the feature
# PARAMETERS
#  $Feature
# RETURNS
#  MMI package
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetFeaturePackage()
{
	my $Feature;
	($Feature)=@_;
	
	my $mmipackage=${$g_hFeatureData{$Feature}}{$g_str_mmipackage{$g_keyType}};
	return $mmipackage if $mmipackage;
	return "";
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetFeatureOptionList
# DESCRIPTION
#  Get the Option list of the feature
# PARAMETERS
#  $Feature
# RETURNS
#  Option list
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetFeatureOptionList()
{
	my $Feature;
	($Feature)=@_;
	
	my $optionList=${$g_hFeatureData{$Feature}}{$g_str_optionList{$g_keyType}};
	return $optionList if $optionList;
	return "";
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetFeatureOptionSetting
# DESCRIPTION
#  Get the Option setting of the feature
# PARAMETERS
#  $Feature
# RETURNS
#  Option setting
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetFeatureOptionSetting()
{
	my $Feature;
	($Feature)=@_;
	
	my $optionSetting=${$g_hFeatureData{$Feature}}{$g_str_optionSetting{$g_keyType}};
	return $optionSetting if $optionSetting;
	return "";
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetFeatureDefineValue
# DESCRIPTION
#  Get the define value of the feature
# PARAMETERS
#  $Feature
# RETURNS
#  Define value
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetFeatureDefineValue()
{
	my $Feature;
	($Feature)=@_;
	
	my $define_val=${$g_hFeatureData{$Feature}}{g_str_defineValue{$g_keyType}};
	return $define_val if $define_val;
	return "";
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetFeatureDescription
# DESCRIPTION
#  Get the Description of the feature
# PARAMETERS
#  $Feature
# RETURNS
#  Description
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetFeatureDescription()
{
	my $Feature;
	($Feature)=@_;
	
	my $description=${$g_hFeatureData{$Feature}}{$g_str_description{$g_keyType}};
	return $description if $description;
	return "";
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetFeatureDepAnd
# DESCRIPTION
#  Get the And dependency of the feature
# PARAMETERS
#  $Feature
# RETURNS
#  And dependency
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetFeatureDepAnd()
{
	my $Feature;
	($Feature)=@_;
	
	my $depAnd=${$g_hFeatureData{$Feature}}{$g_str_depAND{$g_keyType}};
	return $depAnd if $depAnd;
	return "";
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetFeatureDepOr
# DESCRIPTION
#  Get the OR dependency of the feature
# PARAMETERS
#  $Feature
# RETURNS
#  OR dependency
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetFeatureDepOr()
{
	my $Feature;
	($Feature)=@_;
	
	my $depOr=${$g_hFeatureData{$Feature}}{$g_str_depOR{$g_keyType}};
	return $depOr if $depOr;
	return "";
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetFeatureDepErr
# DESCRIPTION
#  Get the ERR dependency of the feature
# PARAMETERS
#  $Feature
# RETURNS
#  ERR dependency
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetFeatureDepErr()
{
	(my $Feature)=@_;
	
	my $dep_err=${$g_hFeatureData{$Feature}}{g_str_depERR{$g_keyType}};
	return $dep_err if $dep_err;
	return "";
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetFeatureErrMsg
# DESCRIPTION
#  Get the ERR message of the feature
# PARAMETERS
#  $Feature
# RETURNS
#  ERR message
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetFeatureErrMsg()
{
	my $Feature;
	($Feature)=@_;
	
	my $errMsg=${$g_hFeatureData{$Feature}}{$g_str_errMsg{$g_keyType}};
	return $errMsg if $errMsg;
	return "";
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetFeatureRefDoc
# DESCRIPTION
#  Get the refernce document of the feature
# PARAMETERS
#  $Feature
# RETURNS
#  Refernce document
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetFeatureRefDoc()
{
	my $Feature;
	($Feature)=@_;
	
	my $refDoc=${$g_hFeatureData{$Feature}}{$g_str_refDoc{$g_keyType}};
	return $refDoc if $refDoc;
	return "";
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetFeatureDepMtk
# DESCRIPTION
#  Get the MTK dependency of the feature
# PARAMETERS
#  $Feature
# RETURNS
#  MTK dependency
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetFeatureDepMtk()
{
	(my $Feature)=@_;
	
	my $dep_mtk=${$g_hFeatureData{$Feature}}{g_str_depMTK{$g_keyType}};
	return $dep_mtk if $dep_mtk;
	return "";
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetFeatureAllowAutoRelease
# DESCRIPTION
#  Get the Allow auto release property of the feature
# PARAMETERS
#  $Feature
# RETURNS
#  Allow auto release property
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetFeatureAllowAutoRelease()
{
	(my $Feature)=@_;
	
	my $allow_auto_rel=${$g_hFeatureData{$Feature}}{g_str_allowAutoRelease{$g_keyType}};
	return $allow_auto_rel if $allow_auto_rel;
	return "";
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetFeatureOwner
# DESCRIPTION
#  Get the owner of the feature
# PARAMETERS
#  $Feature
# RETURNS
#  Owner
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetFeatureOwner()
{
	(my $Feature)=@_;
	
	my $owner=${$g_hFeatureData{$Feature}}{g_str_owner{$g_keyType}};
	return $owner if $owner;
	return "";
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBGetFeatureLastUpdate
# DESCRIPTION
#  Get the last update property of the feature
# PARAMETERS
#  $Feature
# RETURNS
#  Last update property
# NOTE
#  DBOpen() should be called first
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBGetFeatureLastUpdate()
{
	(my $Feature)=@_;
	
	my $last_update=${$g_hFeatureData{$Feature}}{g_str_lastUpdate{$g_keyType}};
	return $last_update if $last_update;
	return "";
}

#******************************************************************************
# FUNCTION
#  GetDependency
# DESCRIPTION
#  Get a option's dependency
# PARAMETERS
#  $FeatureName - [in]The name of the option
#  $raDepCFG -[out]Array of Found CFG dependences
#  $raDepaGlobal - [out]Array of Found global dependences
# RETURNS
#  n/a
#******************************************************************************
sub DBGetFeatureDependency()
{
	my $FeatureName;
	my $raDepCFG;
	my $raDepaGlobal;
	($FeatureName, $raDepCFG, $raDepaGlobal) = @_;

	my $rhFeatureData = \%g_hFeatureData;
	my @AllFeatureNames = keys(%{$rhFeatureData});
	my $raFeatureNames = \@AllFeatureNames;
	
	my $DepAnd=&DBGetFeatureDepAnd($FeatureName);
	my $DepOr=&DBGetFeatureDepOr($FeatureName);
	my $Deps="$DepAnd$DepOr";
	$Deps =~ s/\s+/ /g;#remove dummy blanks
	#abstract all options from the out of order strings
	#and stored into an array
	my @DepAll = ($Deps =~ /defined\((\w+)\)|\((\w+)\s*==\s*\w+\)/g);
	
	foreach my $Dep (@DepAll)
	{	
		next if !$Dep;

		$Dep = &Trim($Dep);
		
		if($Dep =~ /CFG\w+/)
		{
			next if($Dep eq &DataBase::DBGetCfgName($FeatureName));
			push @{$raDepCFG}, $Dep if(!grep /^$Dep$/,@{$raDepCFG});
		}
		elsif(grep /^$Dep$/,@{$raFeatureNames})
		{
			#The dep is in the database

			my $DepOptionSetting=&DBGetFeatureOptionSetting($Dep);
			if(&DataBase::DBIsFeatureSwitchable($DepOptionSetting))
			{
				#The dep is configurable
				my $CFGName=&DataBase::DBGetCfgName($Dep);
				if((!&DBIsOperatorFeature) && (!grep /^$CFGName$/,@{$raDepCFG}))
				{
					push @{$raDepCFG}, $CFGName;
				}
			}
			else
			{
				#The dep is not configurable, go on the search
				&DBGetFeatureDependency($Dep, $raDepCFG, $raDepaGlobal);
			}
		}
		else
		{	
			#The dep is not in the database, so it is a global option
			push @{$raDepaGlobal}, $Dep if(!grep /^$Dep$/,@{$raDepaGlobal});
		}
	}
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  PrintHierarchy
# DESCRIPTION
#  Print the hierarchy, debug usage
# PARAMETERS
#  $rhHierarchy[In] - hierarchy data to be printed
# RETURNS
#  None
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBPrintHierarchy()
{
	my $rhHierarchy;
	($rhHierarchy) = @_;
	
	while((my $key1, my $value1) = each %{$rhHierarchy})
	{
		if($g_Sequence eq $key1)
		{
			print "Sequence start:\n@{$value1}\nSequence end!\n";
			next;
		}
		
		print $key1, "\n";
		while((my $key2, my $value2) = each %{$value1})
		{
			if($g_Sequence eq $key2)
			{
				print "\tSequence start:\n\t@{$value2}\n\tSequence end!\n";
				next;
			}
			print "\t",$key2,"\n";
			while((my $key3, my $value3) = each %{$value2})
			{
				if($g_Sequence eq $key3)
				{
					print "\t\tSequence start:\n\t\t@{$value3}\n\t\tSequence end!\n";
					next;
				}
				print "\t\t",$key3,"\n";
				while((my $key4, my $value4) = each %{$value3})
				{
					if($g_Sequence eq $key4)
					{
						print "\t\t\tSequence start:\n\t\t\t@{$value4}\n\t\t\tSequence end!\n";
						next;
					}
					print "\t\t\t",$key4,"\n";
					
				}

			}
		}
	}
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  DBPrintSortOptions
# DESCRIPTION
#  Print the sort options, debug usage
# PARAMETERS
#  $rhClassOptions[In] - Options to be printed
# RETURNS
#  None
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub DBPrintSortOptions()
{
	my $rhClassOptions;
	($rhClassOptions) = @_;

	print "\nClass Options:\n";
	while((my $key, my $value) = each %{$rhClassOptions})
	{	
		print "\t$key:\n";
		if(defined($value))
		{
			my $Options = join '\n\t\t', @{$value};
			print "\t\t$Options\n";
		}
	}
}

#******************************************************************************
# FUNCTION
#  DBGetCfgName
# DESCRIPTION
#  Tranfer Option name to CFG_XXX
# PARAMETERS
#  __XXX_YYY__
# RETURNS
#  CFG_XXX_YYY
#******************************************************************************
sub DBGetCfgName()
{
    my $feature;
    ($feature) = @_;  
    
    my $cfgName = "";
    my $tmpFeature;
    
    # get CFG name from feature name
    if ($feature ne "")
    {
        $tmpFeature = $feature; 
        $tmpFeature =~ s/(^[_]*)|([_]*$)//g;
        $cfgName = "CFG_"."$tmpFeature";
    }
       
    return $cfgName;
}

#******************************************************************************
# FUNCTION
#  DBGetBottomClass
# DESCRIPTION
#  Get the bottom class of a class hierarchy
# PARAMETERS
#  $class = "[A][B][C]"
# RETURNS
#  "C"
#******************************************************************************
sub DBGetBottomClass()
{
	my $class;
	($class) = @_;
	if($class)
	{	
		$class =~ s/\[/:/g;
		$class =~ s/\]/:/g;
		$class =~ s/::/:/g;
		$class =~ s/^://g;
		my @aClass = split	/:/, $class;
		return $aClass[-1];
	}
	else
	{
		return "";
	}
}

#******************************************************************************
# FUNCTION
#  DBGetTopClass
# DESCRIPTION
#  Get the top class of a class hierarchy
# PARAMETERS
#  $class = "[A][B][C]"
# RETURNS
#  "A"
#******************************************************************************
sub DBGetTopClass()
{
	my $class;
	($class) = @_;
	if($class)
	{	
		$class =~ s/\[/:/g;
		$class =~ s/\]/:/g;
		$class =~ s/::/:/g;
		$class =~ s/^://g;
		my @aClass = split	/:/, $class;
		return $aClass[0];
	}
	else
	{
		return "";
	}
}

#******************************************************************************
# FUNCTION
#  DBIsFeatureSwitchable
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
sub DBIsFeatureSwitchable()
{
    my $optionSetting;
    ($optionSetting) = @_;
    
    return 1 if ($optionSetting !~ /^[\s]*(($g_str_x)|($g_str_not_finished))?[\s]*$/i);
    return 0;
}

#******************************************************************************
# FUNCTION
#  DBTransOptionList
# DESCRIPTION
#  Transfer option list into standard format
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
sub DBTransOptionList()
{
	my $OptionList = $_[0];

	if(!$OptionList)
	{
		$OptionList = Trim($OptionList);    # remove head and tail spaces
		$OptionList =~ s/([\s]+\,[\s]+)|([\s]+\,)|(\,[\s]+)/\,/g;  # remove empty first
		$OptionList =~ s/(^|(\,))($g_str_on)((\,)|$)/$1$g_macro_on$5/ig;
		$OptionList =~ s/(^|(\,))($g_str_off)((\,)|$)/$1$g_macro_off$5/ig;
		$OptionList =~ s/(^|(\,))($g_str_auto)((\,)|$)/$1$g_macro_auto$5/ig;
		$OptionList =~ s/\,/\, /g;  # restore space
	}
	
	return $OptionList;
}

#******************************************************************************
# FUNCTION
#  DBTransOptionSetting
# DESCRIPTION
#  Transfer option setting into standard format
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
sub DBTransOptionSetting()
{
	my $OptionSetting = $_[0];

	if ($OptionSetting =~ /^$g_str_on$/i)
	{
	    $OptionSetting = $g_macro_on;
	}
	elsif ($OptionSetting =~ /^$g_str_off$/i)
	{
	    $OptionSetting = $g_macro_off;
	}
	elsif ($OptionSetting =~ /^$g_str_auto$/i)
	{
	    $OptionSetting = $g_macro_auto;
	}
	else
	{
	    $OptionSetting =~ s/(^[\s]*)|([\s]*$)//g;
	}

	return $OptionSetting;
}


#******************************************************************************
# FUNCTION
#  DBIsOperatorFeature
# DESCRIPTION
#  Feature is a operator feature or not 
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
sub DBIsOperatorFeature()
{
	(my $Feature) = @_;
	
	return 1 if(grep /^$Feature$/,@g_aOperatorFeatures);
	return 0;
	
}



#******************************************************************************
# Internal Functions
#******************************************************************************

#******************************************************************************
# FUNCTION
#  ValidateFeatureData
# DESCRIPTION
#  
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
sub ValidateFeatureData()
{
        # validate data : pair of '(' and ')'
        
        my %oriFeatureDataHash = %{$_[0]};
        
        my @pairErr = ();
        foreach my $feature (keys(%oriFeatureDataHash))
        {
            my @tmpErr = ();
            my $str;
           
            $str = $oriFeatureDataHash{$feature}{$g_str_depAND{$g_keyType}};
            &ValidatePairing($str, \@tmpErr);
            
            $str = $oriFeatureDataHash{$feature}{$g_str_depOR{$g_keyType}};
            &ValidatePairing($str, \@tmpErr);
           
            $str = $oriFeatureDataHash{$feature}{$g_str_depERR{$g_keyType}};
            &ValidatePairing($str, \@tmpErr);
            
            if (@tmpErr)
            {
                push @pairErr, "[ERROR] [$feature]\n";
                push @pairErr, "\t".join('', @tmpErr)."\n";
            }
        }
        die join('', @pairErr) if (@pairErr);
}

#******************************************************************************
# FUNCTION
#  ValidatePairing
# DESCRIPTION
#  make sure specific chars occur in pair
# PARAMETERS
#  xxxx
# RETURNS
#  xxxx
#******************************************************************************
sub ValidatePairing()
{
    my $str;
    my $errMsg_ref;
    
    ($str, $errMsg_ref) = @_;

    my ($count1, $count2);
    my $result = 1; # default to success
    
    if ($str)
    {   
        $count1 = () = ($str =~ /\(/g);
        $count2 = () = ($str =~ /\)/g);
        #print "$count1 - $count2\n";
           
        if ($count1 != $count2)
        {
            push @{$errMsg_ref}, "'(' and ')' count mismatch - $count1 : $count2\n";
            $result = 0;
        }
    }    
    
    return $result;
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  AddHierarchy
# DESCRIPTION
#  Add a new class into the hierarchy hash
# PARAMETERS
#  $ClassName[In] - class to be added
#  $rhHierarchy[In/Out] -Hierarchy hash to be added into 
# RETURNS
#  None
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub AddHierarchy()
{
	my $ClassName;
	my $rhHierarchy;
	my $TopClass;
	($ClassName, $rhHierarchy, $TopClass) = @_;

	if($ClassName !~ /^[\s]*$/)
	{		
		if (!exists( ${$rhHierarchy}{$ClassName}))
		{
			#Add a new item into the hash, 
			{
				#DOM do not allow duplicated topic names
				#So we should rename it:
				if(grep /^$ClassName$/,@g_aHierarchyNames)
				{
					print "[DataBase Warning] Duplicated topic: $ClassName\n";
					$ClassName=$ClassName."($TopClass)";
				}
				
				my %SubHierarchy;
				${$rhHierarchy}{$ClassName} = \%SubHierarchy;

				push @g_aHierarchyNames, $ClassName;
			}

			#Add the new class name into sequence array
			{			
				if(!exists(${$rhHierarchy}{$g_Sequence}))
				{
					my @Seq=();
					${$rhHierarchy}{$g_Sequence} = \@Seq;
				}
				
				my $refSeq = ${$rhHierarchy}{$g_Sequence};
				push @{$refSeq}, $ClassName if(!grep /^$ClassName$/,@{$refSeq});

				}
			}

		
	}


}

#******************************************************************************
# FUNCTION
#  GetColIndex
# DESCRIPTION
# PARAMETERS
# 	"Column name" => Index: 	"Classification" => 1
# 								"Feature Name" => 2
#								"MMI Package" => 3
# RETURNS
#  xxx
#******************************************************************************
sub GetColIndex()
{
    my $rhColIndex=0;
    
    my $cellData="";
    my $col = 1;
    my @errorLog = ();
    
    ($rhColIndex) = @_;
    
    $cellData = &Office::excelRead(1, $col);
    while( $cellData ne "")
    {
        #print "title [$cellData]\n";
        
        foreach my $colName_ref (@g_colNames)
        {
        		my $g_colNamestr = ${$colName_ref}{'xls'};
            if ($cellData =~ /^[\s]*$g_colNamestr[\s]*$/i)
            {
                # prevent cover existing data
                if (!defined($$rhColIndex{${$colName_ref}{'xls'}}))
                {
                    $$rhColIndex{${$colName_ref}{'xls'}} = $col;
                }
            }            
        }
        $col++;
        $cellData = &Office::excelRead(1, $col);
    }
    
    # check if all index are found
    foreach my $colName_ref (@g_colNames)
    {
        if (!defined($$rhColIndex{${$colName_ref}{'xls'}}))
        {
            push @errorLog, "can't get index of ${$colName_ref}{'xls'} in excel file\n";
        }
    }
    
    if (scalar(@errorLog))
    {
        die join('',@errorLog);
    }
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

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# FUNCTION
#  UpdateDuplicatedClass
# DESCRIPTION
#  Update the option's class if it is dupicated
# PARAMETERS
#  
# RETURNS
#  
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sub UpdateDuplicatedClass()
{
	(my $Class)= @_;
	return $Class if(!$Class);
	
	my @Classes = ($Class =~ /\[([A-Za-z0-9_\/\(\) \\]+)\]/g);
	my $rhHierarchy = \%g_hHierarchy;
	foreach my $cls (@Classes)
	{	
		if("Slim" eq $cls)
		{
			my $Stop = 0;
		}
		
		if(!exists(${$rhHierarchy}{$cls}))
		{
			if(defined(${$rhHierarchy}{$g_Sequence}))
			{
				my @Seq = @{${$rhHierarchy}{$g_Sequence}};
				my @Found = grep /^$cls/,@{Seq};
				if(@Found)
				{
					$Class =~ s/$cls/$Found[0]/;
				}
			}

		}

		$rhHierarchy = ${$rhHierarchy}{$cls};
	}

	return $Class;
}

