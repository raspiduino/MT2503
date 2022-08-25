#*****************************************************************************
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
#*****************************************************************************
#
# Filename: 
# ---------
#   res_parese_screen_id.pl
#
# Description: 
# ------------
#   Pares *.res from mmi_res_range_def.h and output enum list of screen IDs
#       [usage] res_parese_screen_id.pl
#
# Auther: 
# -------
#   Fred
# 
# Note:
# -----
#
# Log: 
# -----
#
#*****************************************************************************

#!/usr/bin/perl


########################################################
# Trace Parser start
#
# This part is used to copy the trace declaration from app_trc.txt in
# the resource path of the application to the original
# application trace file like MMI_common_app_trc.h
#
########################################################


#0 run by make codegen and disable log info 
#1 run by make codegen and enable log info
#2 run by perl res_parse_screen_id.pl $mmi_version and enable log info
my $debug_level = 0;

#get the MMI Version info from the common line argument
my ($mmi_version_info) =  @ARGV;

#error handling if not specify the mmi version, take COSMOS_MMI as default
if (!(defined($mmi_version_info)) || length($mmi_version_info) == 0)
{
	$mmi_version_info = "COSMOS_MMI";
}

#mcu path of the code base
my $g_mcu_path;

#when run from the make procedure ($debug_level < 2), the current directory is mcu path
#when run from command line directly ($debug_level == 2), the current directory is mcu\plutommi\Customer\ResGenerator
if ($debug_level < 2)
{
    $g_mcu_path = '.';
}
else
{
    $g_mcu_path = "..\\..\\.."
}

#MMI trace file path
my $trc_path = "$g_mcu_path\\plutommi\\mmi\\inc\\";

#trace module to trace file mapping
my %module_trace = (
                        MOD_MMI_COMMON_APP => "$trc_path\\MMI_common_app_trc.h",
                        MOD_MMI_CONN_APP   => "$trc_path\\MMI_conn_app_trc.h",
                        MOD_MMI_MEDIA_APP  => "$trc_path\\MMI_media_app_trc.h",
                        MOD_MMI_INET_APP   => "$trc_path\\MMI_inet_app_trc.h"
				   );
									 
#resource range file path
my $range_file = "$g_mcu_path\\plutommi\\mmi\\inc\\mmi_res_range_def.h";

#pluto range file
my $pluto_range_file = "$g_mcu_path\\plutommi\\mmi\\inc\\mmi_pluto_res_range_def.h";

#library range file
my $mmi_lib_range_file = "$g_mcu_path\\plutommi\\mmi\\Inc\\mmi_lib_res_range_def.h";

#range file for venus app in FTE
my $fte_venus_range_file = "$g_mcu_path\\venusmmi\\app\\pluto_variation\\Interface\\vapp_package_res.h";

#my $package_ = "cosmos";
my $package_ = substr($mmi_version_info,0,(length($mmi_version_info)-4)); # 4 is the length of "_MMI"

#venus common range file
my $venus_range_file = "$g_mcu_path\\venusmmi\\app\\common\\interface\\vapp_res.h";

#package range file like cosmos
my $package_range_file = "$g_mcu_path\\venusmmi\\app\\$package_\\interface\\app\\vapp_package_res.h";

#venus app base path
my $venus_app_path = "$g_mcu_path\\venusmmi\\APP";

#package app base path
my $package_app_path = "$g_mcu_path\\venusmmi\\app\\$package_";

#fte venus app base path
my $fte_venus_range_path = "$g_mcu_path\\venusmmi\\app\\pluto_variation";

#range file res folder base path mapping in venus, declare range by VFX_APP_RES_DECLARE
%range_file_trace_file_base_path = (
                                       $venus_range_file => $venus_app_path,
                                       $package_range_file => $package_app_path,
                                       $fte_venus_range_file => $fte_venus_range_path
                                   );
#all range declaration file for debug
@range_decl_file = ($range_file, $pluto_range_file, $mmi_lib_range_file, $fte_venus_range_file, $venus_range_file, $package_range_file);

#application trace file info
# eg. "app_trc.txt" = > ("[APP NAME]" => "Test App", "[SCOPE]" => COSMOS, "[MODULE]" => MOD_MMI_COMMON_APP, "[TRC]" => \@trace)
my %file_info =();

#resouce path to _trc.txt mapping
# eg. "testApp/Res" => "testApp/Res/test_app_trc.txt"
my %path_file = ();

#log file handle needed when $debug_level > 0
my $log_file;

########################################################
# Main Program of Trace Parser
########################################################
&PrintDependency($0);
&trace_parser();

########################################################
# Trace Parser end
########################################################



# open mmi_res_range_def.h
open(FP, "<Plutommi\\MMI\\Inc\\mmi_res_range_def.h") or die "Cannot open mmi_res_range_def.h";
&PrintDependency("plutommi\\MMI\\Inc\\mmi_res_range_def.h");
print STDOUT "Parse mmi_res_range_def.h\n";

# parse mmi_res_range_def.h
while (<FP>)
{
    # match #define xxx GET_RESOURCE_BASE ( yyy ))
    if (/^\s*#define\s*(\w*).*?GET_RESOURCE_BASE\s*\(\s*(\w*?)\s*\)\s*\)/)
    {
        # $1 = xxx
        # $2 = yyy
        #print $1."\t".$2."\n";
        $id_base{$2} = $1;
        next;
    }

    # match RESOURCE_BASE_TABLE_ITEM_PATH(xxx, "yyy")
    if (/^\s*RESOURCE_BASE_TABLE_ITEM_PATH\(\s*(\w*)\s*,\s*\"(.*)\"\)/)
    {
        # #1 = xxx
        # $2 = yyy
        #print $1."\t".$2."\n";
        $dir_path{$1} = "Plutommi\\".uc($2);
        next;
    }
}

# close mmi_res_range_def.h
close(FP);

# print table:  ID    BASE    PATH
#print $_."\t".$id_base{$_}."\t".$dir_path{$_}."\n" foreach sort keys(%id_base);

print STDOUT "Find file list in each folder\n";

# get unique $dir_path because multiple ids may share the same path
$path{$dir_path{$_}} = 1 foreach(keys %dir_path);

# search path
foreach $dir (keys %path)
{
    #print $dir."\n";

    # open each folder
    next unless opendir(DIR, $dir);

    # search each .res file in each folder
    @files = grep(/\.res$/, readdir(DIR));
    #print $dir.$_."\n" foreach(@files);
    push @file_list, $dir.$_ foreach(@files);

    # close folder
    closedir(DIR);
}

# print .res file list
#print $_."\n" foreach(@file_list);

print STDOUT "Search each .res file \n";

# search each .res file
foreach my $file (@file_list)
{
    # open .res file
    next unless open(RESFILE, "<$file");

    my $app_id;

    while(<RESFILE>)
    {
        # match <APP id = "xxx">
        if (/\<\s*APP\s*id\s*\=\s*\"(\w*)\"/)
        {
            # $1 = xxx
            #print $1."\n";
            $app_id = $1;
            next;
        }

        # match <SCREEN id = "xxx"/>   
        if (/\<\s*SCREEN\s*id\s*\=\s*\"(\w*)\"\/\>/)
        {
            # $1 = xxx
            #print $1."\n";
            push @{$screen_list{$app_id}}, $1;
            &PrintDependency($file);
            next;
        }
    }

    # close .res file
    close(RESFILE);
}

print STDOUT "Output screen_enum.h \n";

# open screen_enum.h
my $screen_list_input;
my $screen_list_output;
if ((-e "plutommi\\Customer\\CustomerInc\\screen_enum.h") && open(FP, "<plutommi\\Customer\\CustomerInc\\screen_enum.h"))
{
	my $saved_sep = $/;
	undef $/;
	$screen_list_input = <FP>;
	$/ = $saved_sep;
	close(FP);
}

# output enum
foreach (keys %screen_list)
{
    my $app = $_;
    $screen_list_output .= "typedef enum\n{\n";
    my $i = 0;
    foreach (@{$screen_list{$_}})
    {
        if ($i++ == 0)
        {
            $screen_list_output .= "\t$_ = $id_base{$app} + 1,\n";
        }
        else
        {
            $screen_list_output .= "\t$_,\n";
        }
    }
    $screen_list_output .= "\n\tSCR_ID_".uc($app)."_ALL\n";
    $screen_list_output .= "} mmi_".lc($app)."scr_id_enum;\n\n\n";
}

if ($screen_list_input ne $screen_list_output)
{
    open(FP, ">plutommi\\Customer\\CustomerInc\\screen_enum.h") or die "Cannot open screen_enum.h";
    print FP $screen_list_output;
    close(FP);
}
else
{
    print "No need to update screen_enum.h\n";
}



#******************************************************************************
# FUNCTION
#  trace_parser
# DESCRIPTION
#  entry point
#
#
# PARAMETERS
#  none
# RETURNS
#  none
#******************************************************************************
sub trace_parser
{
    #******************************************************************************
    # Local variable
    #******************************************************************************
    
	#******************************************************************************
    # Code body
    #******************************************************************************
    print STDOUT "Start to collection application trace info...\n";
    if ($debug_level > 0)
    {
        my $curr_dir = `cd`;
        open($log_file, ">trace_parser.log") or die "cannot open trace_parser.log";
        
        print $log_file "Current Directory is $curr_dir\n";        
        print $log_file "MMI Version is $mmi_version_info\n\n";
        
        print $log_file "Start to print range declaration file list...\n\n";
        foreach (@range_decl_file)
        {
            print $log_file "$_\n";
        }
        
        print $log_file "\n";
        
        print $log_file "Start to print venus range file to res folder base path mapping\n\n";
        
        foreach (keys(%range_file_trace_file_base_path))
        {
            print $log_file "[file] $_\n";
            print $log_file "[Base Path] $range_file_trace_file_base_path{$_}\n";
        }
        
        print $log_file "\n";        
    }
    
    #get resource path from the range declaration file
    &get_venus_res_path();
    &get_res_path_format_mmi_res_declare($pluto_range_file);
    &get_res_path_format_mmi_res_declare($mmi_lib_range_file);
	&get_res_path();
	
	#print res file path
	if ($debug_level > 0)
	{
	    &print_res_path();
	}
	  
	&get_file_list();
	
	if ($debug_level > 0)
	{
	    &print_file_list();
	}
	
	foreach (keys(%file_info))
	{
	    # read trace file info into %file_info
        &trc_file_parser($_);
        
        if ($debug_level > 0)
        {
            print_file_info($_, \%file_info);
        }
	}

    #remove the trace file info that not belong to current MMI version
    &split_by_scope();
	  foreach (keys(%file_info))
	  {
	  	&PrintDependency($_);
	  }
	  &collect_trc();
    if ($debug_level > 0)
    {
        close($log_file);
    }
	  print STDOUT "Trace collection is finished.\n";
}


#******************************************************************************
# FUNCTION
#  get_venus_res_path
# DESCRIPTION
#  get venus app res path
#
#
# PARAMETERS
#  none
# RETURNS
#  none
#******************************************************************************
sub get_venus_res_path
{
    #******************************************************************************
    # Local variable
    #******************************************************************************
    my $line;
    
    #******************************************************************************
    # Code body
    #******************************************************************************
    foreach my $range_file (keys(%range_file_trace_file_base_path))
    {
        if (-e $range_file)
        {
            open(IN, $range_file) || die "cannot open $range_file";
            &PrintDependency($range_file);
            while(defined($line = <IN>))
            {
                if ($line =~ /VFX_APP_RES_DECLARE\(.+,\s*[0-9]*,\s*\"(.+)\"\)/)
            	{
            	    my @temp;
            	    my $path;
            	    @temp = split(/\\\\/, $1);
            	    $path = join('\\', @temp);
            	    $path = lc "$range_file_trace_file_base_path{$range_file}\\$path";
            	    $path_file{$path} = ();
                }
            }
            close(IN);
        }
        else
        {
            if ($debug_level > 0)
            {
                print $log_file "[ERR]$range_file is not a valid file\n";
            }
        }
    }
}


#******************************************************************************
# FUNCTION
#  get_res_path
# DESCRIPTION
#  get res file path info from mmi_res_range_def.h. The current path of the path
# info in mmi_res_range_def.h is plutommi
#
# PARAMETERS
#  none
# RETURNS
#  none
#******************************************************************************
sub get_res_path
{
    #******************************************************************************
    # Local variable
    #******************************************************************************
	my $line;
    
    #******************************************************************************
    # Code body
    #******************************************************************************
	open(IN, "$range_file") || die "Cannot open $range_file $!";
	&PrintDependency($range_file);
	while(defined($line = <IN>))
	{
	    if ($line =~ /RESOURCE_BASE_TABLE_ITEM_PATH\(.+,\s*\"(.+)\"\)/)
	  	{
	  	    my @temp;
	  	  	my $path;
	  	  	#print $1."\n";
	  	  	@temp = split(/\\\\/, $1);
	  	  	if ($temp[0] eq '..')
	  	  	{
	  	  	    shift(@temp);
	  	  	    unshift(@temp,  $g_mcu_path);
	  	  	}
	  	  	else
	  	  	{
	  	  	    if ($temp[0] eq '.')
	  	  	    {
	  	  	        shift(@temp);
	  	  	    }
	  	  	    unshift(@temp, "plutommi");
	  	  	    unshift(@temp, $g_mcu_path);  
	  	  	}
	  	  	$path = join('\\', @temp);
	  	  	$path = lc $path;
	  	  	$path_file{$path} = ();
	  	 }
	}
    close(IN);
}


#******************************************************************************
# FUNCTION
#  get_res_path_format_mmi_res_declare
# DESCRIPTION
#  get res path of pluto app and lib app
#
# PARAMETERS
#  none
# RETURNS
#  none
#******************************************************************************
sub get_res_path_format_mmi_res_declare
{
    #******************************************************************************
    # Local variable
    #******************************************************************************
	my $line;
    
	#******************************************************************************
    # Code body
    #******************************************************************************
    ($range_file_format_mmi_res_declare, ) = @_;
    
    if (-e $range_file_format_mmi_res_declare)
    {
        open(IN, "$range_file_format_mmi_res_declare") || die "Cannot open $range_file_format_mmi_res_declare $!";
        &PrintDependency($range_file_format_mmi_res_declare);
        while(defined($line = <IN>))
        {
            if ($line =~ /MMI_RES_DECLARE\(.+,\s*[0-9]*,\s*\"(.+)\"\)/)
            {
                my @temp;
                my $path;
                #print $1."\n";
                @temp = split(/\\\\/, $1);
                if ($temp[0] eq '..')
                {
                    shift(@temp);
                    unshift(@temp,  $g_mcu_path);
                }
                else
                {
                    if ($temp[0] eq '.')
                    {
                      shift(@temp);
                    }
                    unshift(@temp, "plutommi");
                    unshift(@temp, $g_mcu_path);                  
                }
                $path = join('\\', @temp);		  	  	  
                $path = lc $path;
                $path_file{$path} = ();
            }
        }
        close(IN);
    }
    else
    {
        if ($debug_level > 0)
        {
            print $log_file "[ERR] $range_file_format_mmi_res_declare is not a valid file\n";
        }
    }
}


#******************************************************************************
# FUNCTION
#  print_res_path
# DESCRIPTION
#  print res path info
#
# PARAMETERS
#  none
# RETURNS
#  none
#******************************************************************************
sub print_res_path
{
    #******************************************************************************
    # Local variable
    #******************************************************************************
    
	#******************************************************************************
    # Code body
    #******************************************************************************
    print $log_file "Start to print res path...\n\n";
    foreach (keys(%path_file))
    {
        print $log_file "$_\n";	  	   
    }
}


#******************************************************************************
# FUNCTION
#  get_file_list
# DESCRIPTION
#  get application trace file list
#
# PARAMETERS
#  none
# RETURNS
#  none
#******************************************************************************
sub get_file_list
{
    #******************************************************************************
    # Local variable
    #******************************************************************************
    my @file;
    
	#******************************************************************************
    # Code body
    #******************************************************************************
    foreach my $path (keys(%path_file))
    {
        push @file, grep {-f && ($_ =~ /_trc\.txt$/i)} glob "$path\\*";
        foreach (@file)
        {
            $file_info{$_} = ();
        }
    }    
}


#******************************************************************************
# FUNCTION
#  print_file_list
# DESCRIPTION
#  print application trace file list
#
# PARAMETERS
#  none
# RETURNS
#  none
#******************************************************************************
sub print_file_list
{
    #******************************************************************************
    # Local variable
    #******************************************************************************

	#******************************************************************************
    # Code body
    #******************************************************************************
    print $log_file "\n\nStart to print trace file list\n\n";
    foreach (keys(%file_info))
    {
        print $log_file "$_\n";	  	   
    }	  
}


#******************************************************************************
# FUNCTION
#  trc_file_parser
# DESCRIPTION
#  parser application trace file list
#
# PARAMETERS
#  $file_name : [IN] trace file name
# RETURNS
#  none
#******************************************************************************
sub trc_file_parser
{
    #******************************************************************************
    # Local variable
    #******************************************************************************
    my $file_name;
    my $line;
    my $count;
    my @trace;
    my $has_module = 0;
    my $has_scope = 0;
    
	#******************************************************************************
    # Code body
    #******************************************************************************
    ($file_name, ) = @_;
	open(IN, "$file_name") || die "Cannot open $file_name $!";
	while(defined($line = <IN>))
	{
	    $count++;
		&trim($line);
		next if ($line =~ /^#/);
		next if ($line =~ /^\s*\n$/);
		    
        if ($line =~ /^\[APP\sNAME\]|^\[MODULE\]|^\[SCOPE\]/)
		{
		    my $item;
			my $data;
			my @temp = split(/=/, $line);
			$item = shift(@temp);
			$item = &trim($item);
			$data = shift(@temp);
			$data = &trim($data);
			$file_info{$file_name}{$item} = $data;
			if ($item eq '[MODULE]')
			{
			    $has_module = 1;
				unless (&is_valid_module($data))
				{
				    die "wrong module type file $file_name $line: $count\n";
				}
			}
			if ($item eq '[SCOPE]')
			{
			    $has_scope = 1;
				my @scope = split(/,/, $data);
				foreach (@scope)
				{
				    $_ = &trim($_);
				}
				$file_info{$file_name}{$item} = \@scope;
			}
			#print "$item - $data\n";
        }
		elsif ($line =~ /^TRC_MSG(.+)/)
		{
		    unless (&is_valid_module($file_info{$file_name}{"[MODULE]"}))
		    {
		        die "please put the module before the trace declaration, $file_name line:$count : $line\n";
		    }
		    push(@trace, $line);
		}
        #else
        #{
        #   die "wrong format file $file_name line:$count : $line\n";
        #}
    }
    $file_info{$file_name}{"[TRC]"} = \@trace;
	close(IN);
	if ($has_module == 0)
	{
        die "Please specify [MODULE] in $file_name";
	}
	if ($has_scope == 0)
	{
        die "Please specify [SCOPE] in $file_name";
	}		
}


#******************************************************************************
# FUNCTION
#  split_by_scope
# DESCRIPTION
#  split trace file info by [SCOPE]
#
# PARAMETERS
#  none
# RETURNS
#  none
#******************************************************************************
sub split_by_scope
{
    #******************************************************************************
    # Local variable
    #******************************************************************************

    #******************************************************************************
    # Code body
    #******************************************************************************
    foreach my $file (keys(%file_info))
    {
        my $found = 0;
    	my @scopeArr = @{$file_info{$file}{"[SCOPE]"}};
    	foreach my $scope (@scopeArr)
    	{
    	    if ((($scope."_MMI") eq $mmi_version_info) || ("IOT_MMI" eq $mmi_version_info))
    		{
    	        $found = 1;
    		    last;    				
    		}
    	}
    	
    	if($found == 0)
    	{
    	    delete $file_info{$file};
    	}
    }
}


#******************************************************************************
# FUNCTION
#  collect_trc
# DESCRIPTION
#  collect the trace info and put them into the orignal trace file
#
# PARAMETERS
#  none
# RETURNS
#  none
#******************************************************************************
sub collect_trc
{
    #******************************************************************************
    # Local variable
    #******************************************************************************
	my $ignore;
    my $line;
    my @content;
    my $is_remove_enter;
    
	#******************************************************************************
    # Code body
    #******************************************************************************
    foreach my $mod (keys(%module_trace))
    {
        my $trc_file;
        @content = ();
        $trc_file = $module_trace{$mod};
        open(IN, "$trc_file") || die "Cannot open $trc_file $!";
        &PrintDependency($trc_file);
        while(defined($line = <IN>))
        {
            push(@content, $line);
        }
        close(IN);
		my $content_input = join('',@content);
		my $content_output;
		foreach $line (@content)
		{
			if ($line =~ /<codegen collect trace start>/)
			{
				$ignore = 1;
			}
			if ($line =~ /END_TRACE_MAP/)
			{
				$content_output .= "\t\/\*<codegen collect trace start>\*\/\n\n";
				foreach my $file (keys(%file_info))
				{
					if ($file_info{$file}{"[MODULE]"} eq $mod)
					{
						$content_output .= "\n";
#						$content_output .= "\t\/\*App Owner: $file_info{$file}{\"[OWNER]\"}\*\/\n";
						$content_output .= "\t\/\*App Name: $file_info{$file}{\"[APP NAME]\"}\*\/\n\n";
						foreach (@{$file_info{$file}{"[TRC]"}})
						{
							$content_output .= "\t$_";
						}
						$content_output .= "\n";
					}
				}
				$content_output .= "\t\/\*<codegen collect trace end>\*\/\n\n";
			}
			$content_output .= $line if ($ignore == 0 && $is_remove_enter == 0);
			$is_remove_enter = 0;
			if ($line =~ /<codegen collect trace end>/)
			{
				$ignore = 0;
				$is_remove_enter = 1;
			}
		}
		if ($content_input ne $content_output)
		{
			open(OUT, ">$trc_file") || die "Cannot open $trc_file $!";
			print OUT $content_output;
			close(OUT);
		}
		else
		{
			print "No need to update $trc_file\n";
		}
	}
}


#******************************************************************************
# FUNCTION
#  print_file_info
# DESCRIPTION
#  print application trace file info
#
# PARAMETERS
#  $file : [IN] trace file name
#  $href : [IN] file info hash reference
# RETURNS
#  none
#******************************************************************************
sub print_file_info
{
    #******************************************************************************
    # Local variable
    #******************************************************************************
    my $file;
    my $href;
    
	#******************************************************************************
    # Code body
    #******************************************************************************
    ($file, $href, ) =  @_;
    print $log_file "\n\n";
    print $log_file "[APP NAME]".${$href}{$file}{"[APP NAME]"}."\n";
    print $log_file "[MODULE]".${$href}{$file}{"[MODULE]"}."\n";
    print $log_file "[SCOPE]";
    foreach (@{${$href}{$file}{"[SCOPE]"}})
    {
        print $log_file "$_,";
    }
    print $log_file "\n";
    foreach (@{${$href}{$file}{"[TRC]"}})
    {
        print $log_file $_;
    }    
}


#******************************************************************************
# FUNCTION
#  is_valid_module
# DESCRIPTION
#  check if valid trace module
#
# PARAMETERS
#  none
# RETURNS
#  none
#******************************************************************************
sub is_valid_module
{
    #******************************************************************************
    # Local variable
    #******************************************************************************
    my $mod;
    
	#******************************************************************************
    # Code body
    #******************************************************************************
    ($mod,) = @_;
    foreach (keys(%module_trace))
    {
        if ($mod eq $_)
        {
            return 1;
        }
    }
    return 0;
}


#******************************************************************************
# FUNCTION
#  trim
# DESCRIPTION
#  trim left and right spaces
#
#
# PARAMETERS
#  $str [IN] - string to process
# RETURNS
#  processed string
#******************************************************************************
sub trim()
{
    #******************************************************************************
    # Local variable
    #******************************************************************************
    my $str;
    
	#******************************************************************************
    # Code body
    #******************************************************************************
    ($str) = @_;
    
    $str =~ s/(^\s*)|(\s*$)//g;
    return $str;
}sub PrintDependency
{
	my $file = shift;
	if (-e $file)
	{
		my $path = Win32::GetCwd() . "\\" . $file;
		$path =~ s/\//\\/g;
		print STDERR "[Dependency] $path\n";
	}
}
