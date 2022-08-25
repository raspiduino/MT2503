#!/usr/local/bin/perl

# 
# Copyright Statement:
# --------------------
# This software is protected by Copyright and the information contained
# herein is confidential. The software may not be copied and the information
# contained herein may not be used or disclosed except with the written
# permission of MediaTek Inc. (C) 2005
# 
# BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
# NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
# SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
# 
# BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
# LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
# 
# THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
# WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
# LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
# RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
# THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
# 

use Net::SMTP;
use File::Basename;
use Win32::OLE qw(in);
use Win32::Registry;

# Defaultly, LSF will pass submission host env vars to execution host.
# In order to use execution host env vars.,
# We get LSF execution host env vars here and let all child processes
# also use the execution host env vars.
my @RESET_ENV_VAR_LIST = qw(NUMBER_OF_PROCESSORS);
my @RESET_ENV_VAR_LIST_FOR_MBIS = qw(MBIS_BUILD_TIME_TMP,MBIS_BUILD_TIME_LOG,MBIS_BUILD_INFO_LOG);
if ($ENV{MBIS_BUILD_TIME_TMP} =~ /mbis/)
{
  $mbis_time = time;
  push(@RESET_ENV_VAR_LIST, @RESET_ENV_VAR_LIST_FOR_MBIS);
}
&reset_env_var(\@RESET_ENV_VAR_LIST);

$ENV{"MoDIS"} = 'AutoPower';
$lsf_dir = "E:\\temp\\mcu";
$allArgv = join(" ", @ARGV);
@orgARGV = @ARGV;
$custom = "MTK";
$ini = "make.ini";
$enINI = 1;
@projects = qw(l1s gsm gprs basic udvt umts hspa tdd128 tdd128dpa tdd128hspa none);
chomp($cwd = `cd`);
$cwd = $orgARGV[0];
shift(@orgARGV);
$cwd =~ s/\\\(/\(/ig;
$cwd =~ s/\\\)/\)/ig;
$skipIni = 0;
$computerName = $ENV{"COMPUTERNAME"};
system("md $lsf_dir") if (!-d "$lsf_dir");
system("echo set LAST_SUBMITTED_CF=$computerName > ${lsf_dir}\\LAST_S_C.bat");
system("xcopy ${lsf_dir}\\LAST_S_C.bat $cwd /Y /Q > nul");
$curr_usr = getlogin() or die "can't get your login name\n$!\n";
$ENV{"LSF_remote"} = $cwd;

if ($ENV{MBIS_BUILD_TIME_TMP} =~ /mbis/)
{
  system("echo T_E,DISPATCH_CF,P,$mbis_time >> ${cwd}\\$ENV{MBIS_BUILD_TIME_TMP}");
}
shift(@ARGV);
while ($#ARGV != -1) {
  if ($ARGV[0] =~ /^(c|cu|cus|cust|custo|custom)=(\w+)/i) {
    $custom = $2;
    last;
  } elsif ($ARGV[0] =~ /^(p|pl|pla|plat|platf|platfo|platfor|platform)=(\w+)/i) {
    last;
  } elsif (($ARGV[0] !~ /-(puremodis|modis|uesim|debug|release)/i) && ($ARGV[0] !~ /^-(o|op|opt)=(.*)$/i)) {
    foreach $m (@projects) {
      if ($ARGV[0] =~ /\b$m\b/i) {
        shift(@ARGV);
        $skipIni = 1;
        last;
      }
      if ($ARGV[1] =~ /\b$m\b/i) {
        $custom = $ARGV[0];
        shift(@ARGV);
        shift(@ARGV);
        $skipIni = 1;
        last;
      }
    }
    if (($skipIni == 0) && ($enINI == 1) && (-e "${cwd}\\$ini")) {
      system("xcopy ${cwd}\\$ini ${lsf_dir}\\ /Y /Q >nul");  
      open (FILE_HANDLE, "<${lsf_dir}\\$ini") or die "cannot open ${lsf_dir}\\$ini\n";
      while (<FILE_HANDLE>) {
        if (/^(\S+)\s*=\s*(\S+)/) {
          $keyname = $1;
          $${keyname} = $2;
        }
      }
      close FILE_HANDLE;
      print "custom=$custom; plat=$plat; project=$project\n";
    }
  }
  shift(@ARGV);
}
#($custom = "MTK") if ($custom =~ /^mt6\d\d\d\w?$/i);
print("in m_cp2lsf.pl\n");

#**********************************************************************************************
# Readin Custom.bld
#**********************************************************************************************
my $Custombld = "Custom.bld";
if(-e "${cwd}\\make\\$Custombld"){
    open (CUSTOMBLD_HANDLE, "<${cwd}\\make\\$Custombld") or die "cannot open ${cwd}\\make\\$Custombld\n";
    while (<CUSTOMBLD_HANDLE>) {
      if (/^(\S+)\s*=\s*(\S+)/) {
        $keyname = $1;
        $${keyname} = $2;
      }
    }
    close CUSTOMBLD_HANDLE;
    if(!defined($LEVEL)){
      print "LEVEL not in ${cwd}\\make\\$Custombld\n";
    }
}
#**********************************************************************************************
# End of Readin Custom.bld
#**********************************************************************************************

#**********************************************************************************************
# Decide lsf_dir
#**********************************************************************************************
if ($custom eq "MTK") {
  if($project =~ /GSM/i) {
    $verno_file = "Verno.bld";
  } else {
    $verno_file = "Verno_classb.bld";
  }
} else {
  $verno_file = "Verno_$custom.bld";
}

system("md $lsf_dir\\make") unless (-e "$lsf_dir\\make");
system("copy /y $cwd\\make\\$verno_file $lsf_dir\\make\\$verno_file > nul");
open (VERNO_FILE, "<$lsf_dir\\make\\$verno_file") or die "cannot open $lsf_dir\\make\\$verno_file\n";
$backup = $/;
undef $/;
$fcontent = <VERNO_FILE>;
$/ = $backup;

if($fcontent =~ /VERNO\s*=\s*MAUI\.([^\s]+)/i) {
  $verno = $1;
  if($verno =~ /^W\d\d\.\d\d$/) { # for MainTrunk -> match Wxx.xx
    $branch = "MAUI"; # MAUI
  }
  if($verno =~ /^(\w+)\.W\d\d\.\d\d.MP/) { # for MP branch -> match 06B.Wxx.xx.MP
    $branch = "${1}MP"; # 06BMP
  }
  if($verno =~ /^(\w+)\.W\d\d\.\d\d$/) { # for ABC branch -> match 06B.Wxx.xx
    $branch = "$1"; # 06B
  }
}
close VERNO_FILE;

$branch = 'mcu' unless ($branch);

if (-e "\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\BM_conf.ini") {
	my %BM_conf= iniToHash("\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\BM_conf.ini");
  $lsf_cache_folder_list = $BM_conf{'M_CP2LSF'}->{'LSF_CACHE_FOLDER_LIST'};
  
  if($lsf_cache_folder_list =~/$branch/i)
  {
  	$lsf_dir = "E:\\temp\\$branch";
  }
  else
  {
  	$lsf_dir = "E:\\temp\\mcu";
  }
  unless (-e "$lsf_dir")
  {
  	system("md $lsf_dir");
  	$is_new_dir = 1;
  }
}
else
{
	if (-e "E:\\temp\\$branch") {
	  $lsf_dir = "E:\\temp\\$branch";
	} elsif ($branch eq 'MAUI') {
	  $lsf_dir = "E:\\temp\\$branch";
	  print "md $lsf_dir\n";
	  system("md $lsf_dir");
	  $is_new_dir = 1;
	  
	} elsif ($branch) {
	  my($sec, $min, $hour, $mday, $mon, $year) = localtime(time);
	  $year = sprintf("%02d",($year+1900)%100);
	  
	  if ($verno =~ /$year\w{1}\.W\d\d\.\d\d/i) { # match Wxx.xx
	    $lsf_dir = "E:\\temp\\$branch";
	    print "md $lsf_dir\n";
	    system("md $lsf_dir");
	    $is_new_dir = 1;
	  }
	}
}

print "\nTemp codebase is at $lsf_dir in $computerName\n";
$hitrate = 0;
if(-e "$lsf_dir\\make\\Verno.bld")
{
	  open (VERNO_FILE, "<$lsf_dir\\make\\Verno.bld") or die "cannot open $lsf_dir\\make\\Verno.bld\n";
	  $backup = $/;
	  undef $/;
	  $fcontent = <VERNO_FILE>;
	  $/ = $backup;
    
	  if($fcontent =~ /VERNO\s*=\s*MAUI\.([^\s]+)/i) {
    	$verno_old = $1;
	  }
    close VERNO_FILE;
    if($verno =~ /(\w+)\.W(\d\d)\.(\d\d)/){
	    $CurrentVernoBranch = ${1};
	    $CurrentVernoYear = ${2};
	    $CurrentVernoWeek = ${3};                                         
	  }
	  elsif($verno =~ /(\w+)\.(\w+)\.(\w+)/i)
	  {
	  	$CurrentVernoBranch = ${1};
	    $CurrentVernoYear = ${2};
	    $CurrentVernoWeek = ${3};
	  }
	  
	  if($verno_old =~ /(\w+)\.W(\d\d)\.(\d\d)/){
	     $CheckVernoBranch = ${1};
	     $CheckVernoYear = ${2};
	     $CheckVernoWeek = ${3};                                         
	  }
	  elsif($verno_old =~ /(\w+)\.(\w+)\.(\w+)/i)
	  {
	    $CheckVernoBranch = ${1};
	    $CheckVernoYear = ${2};
	    $CheckVernoWeek = ${3};
	  }
	  
	  if(($CheckVernoBranch ne "") && ($CurrentVernoYear ne "")&& ($CheckVernoWeek ne ""))
    {
      if((uc($CheckVernoBranch) eq uc($CurrentVernoBranch)) && (uc($CurrentVernoYear) eq uc($CheckVernoYear))
         && (uc($CurrentVernoWeek) eq uc($CheckVernoWeek)))
      {
      	$hitrate = 1;
      }
      elsif((uc($CheckVernoBranch) eq uc($CurrentVernoBranch)))
      {
      	$hitrate = 0.5;
      }
      else
      {
      	$hitrate = 0;
      }
    }
	
}

if ($ENV{MBIS_BUILD_INFO_LOG} =~ /mbis/)
{
  system("echo HIT_RATE,$hitrate >> ${cwd}\\$ENV{MBIS_BUILD_INFO_LOG}");
}

if ($is_new_dir) {
  foreach (split(/[\r\n]+/, `dir $lsf_dir`)) {
    if (/([0-9,]+)\s*(bytes free)$/i) {
      $free_space = "$1 bytes";
    }
  }

  if (-e "\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\BM_conf.ini") {
    my %BM_conf = iniToHash("\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\BM_conf.ini");
    $email_list = $BM_conf{'M_CP2LSF'}->{'CREATE_FOLDER_NOTIFY_LIST'} . ",$curr_usr";
  } else {
    $email_list = $curr_usr;
  }
  
  $smtp = Net::SMTP->new('smtp.mediatek.inc');
  $smtp->mail($curr_usr);
  map { $smtp->recipient($_); } split(/,/, $email_list);
  $smtp->data();
  $smtp->datasend("Subject: [Script Notify] $computerName had create a new folder $lsf_dir, and free disk space is $free_space\n");
  $smtp->quit;
}
#**********************************************************************************************
# End of decide lsf_dir
#**********************************************************************************************


#**********************************************************************************************
# Setup LSF temp folders
#**********************************************************************************************
if (-e "\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\BM_conf.ini") {
  my %BM_conf      = iniToHash("\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\BM_conf.ini");
  $lsf_folder_list = $BM_conf{'M_CP2LSF'}->{'LSF_FOLDER_LIST'};
  
  if ($lsf_folder_list)
  {
    foreach (<e:\\temp\\*>)
    {
      if (-d)
      {
        $folder_name = basename($_);
        
        if ($lsf_folder_list !~ /(\W)$folder_name(\W)/i)
        {
          print ("rd /s /q $_\n");
          system("rd /s /q $_");
        }
      }
    }
  }
}
#**********************************************************************************************
# Setup LSF temp folders
#**********************************************************************************************


#**********************************************************************************************
# Check disk free space
#**********************************************************************************************
if (-e "\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\BM_conf.ini") {
  my %BM_conf = iniToHash("\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\BM_conf.ini");
  $email_list = $BM_conf{'M_CP2LSF'}->{'UNDER_THRESHOLD_NOTIFY_LIST'} . ",$curr_usr";
  $threshold  = $BM_conf{'M_CP2LSF'}->{'THRESHOLD'};
  $threshold  = 40*1024*1024*1024;
} else {
  $email_list = $curr_usr;
  $threshold  = 30*1024*1024*1024;
}
$folder_status = `dir E:\\temp`;

foreach (split(/[\r\n]+/, $folder_status)) {
  if (/([0-9,]+)\s*(bytes free)$/i) {
    $free_space = $1;
    $free_space =~ s/,//gi;
  }
}

$latest_free_space = $free_space;

if (-e "\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\BM_conf.ini") {
	my %BM_conf= iniToHash("\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\BM_conf.ini");
  $lsf_delete_folder_list = $BM_conf{'M_CP2LSF'}->{'LSF_DELETE_FOLDER_LIST'};
  @lsf_delete_folder_list = split /,/, "$lsf_delete_folder_list";
  if(@lsf_delete_folder_list)
  {
  		$del_folder = '';
		  @lsf_temp_dir = <e:\\temp\\*>;
		  foreach $lsf_delete_folder(@lsf_delete_folder_list) {
		  	if($latest_free_space < $threshold){
			  	if($lsf_delete_folder !~ /\b$branch\b/i)
			  	{	  		
					  	foreach (@lsf_temp_dir)
					  	{
					  		if($_ =~ /$lsf_delete_folder/)
					  		{
					  			if (-d $_)
					  			{
					  				system("rd /s /q $_");
					  				print "\nrd /s /q $_\n";
					          $del_folder .= "$_\n";
					  			}
					  		}
					  	}
					  	foreach (split(/[\r\n]+/, `dir E:\\temp`))
				  		{
						    if (/([0-9,]+)\s*(bytes free)$/i)
						     {
							      $latest_free_space = $1;
							      $latest_free_space =~ s/,//gi;
						     }
						  }
				  	}

				  }
			  else
		  	{
		  		last;
		  	}
		  }
  }

  $smtp = Net::SMTP->new('smtp.mediatek.inc');
  $smtp->mail($curr_usr);
  map { $smtp->recipient($_); } split(/,/, $email_list);
  $smtp->data();
  $smtp->datasend("Subject: [Script Notify] $computerName :: $lsf_dir  free disk space is under threshold.\n");
  $smtp->datasend("The free disk space is $free_space bytes, and below is the folder status.\n\n");
  $smtp->datasend("=========================================================================\n\n");
  $smtp->datasend("$folder_status\n");
  $smtp->datasend("=========================================================================\n\n\n");
  $smtp->datasend("After script try to delete below folders, the latest free disk space is $latest_free_space bytes.\n\n");
  $smtp->datasend("$del_folder\n");
  $smtp->quit;
}
#**********************************************************************************************
# End of Check disk free space
#**********************************************************************************************


$build_start_time = time;
system("attrib -a -r  ${lsf_dir}\\*.* /s /d");
print("rd /s /q ${lsf_dir}\\build\n");
system("rd /s /q ${lsf_dir}\\build");

if ($ENV{MBIS_BUILD_TIME_TMP} =~ /mbis/)
{
  $mbis_time = time;
  system("echo T_S,TS_TO_CF,P,$mbis_time >> ${cwd}\\$ENV{MBIS_BUILD_TIME_TMP}");
}

if (($allArgv =~ /new_(modis|uesim)/i) && ($allArgv !~ /-puremodis/i)) {
  # copy log needed by MoDIS and generated by Target
  if (-d "${cwd}\\build\\${custom}\\log") {
    print("robocopy ${cwd}\\build\\${custom}\\log ${lsf_dir}\\build\\${custom}\\log /MIR /XF robo*.log /LOG:${cwd}\\TStoCF1.log /R:10 /NP\n");
    system("robocopy ${cwd}\\build\\${custom}\\log ${lsf_dir}\\build\\${custom}\\log /MIR /XF robo*.log /LOG:${cwd}\\TStoCF1.log /R:10 /A-:RA /NP");
    system("xcopy ${cwd}\\build\\${custom}\\MMI_DRV_DEFS.mak $lsf_dir\\build\\${custom}\\ /Y /Q >nul");
    system("xcopy $cwd\\TStoCF1.log $lsf_dir /Y /Q /i> nul");
  } else {
    print("${cwd}\\build\\${custom}\\log does NOT exist!\nPlease run target new firstly until resgen\n");
    exit 0;
  }
}

if (($allArgv =~ /new_(modis|uesim)/i) || ($allArgv =~ /-(modis|uesim)/i) || ($allArgv =~ /-puremodis/i)) {
  # copy files needed by Target with MoDIS
  print("robocopy $cwd $lsf_dir /MIR /XD ${cwd}\\build /XF robo*.log TStoCF*.log /LOG:${cwd}\\TStoCF.log /R:10 /NP\n");
  system("robocopy $cwd $lsf_dir /MIR /XD ${cwd}\\build /XF robo*.log TStoCF*.log /LOG:${cwd}\\TStoCF.log /R:10 /A-:RA /NP");
  if(defined($LEVEL) && ($LEVEL eq VENDOR)){
    print "xcopy $cwd\\build\\${custom}\\EXT_BOOTLOADER $lsf_dir\\build\\${custom}\\ /Y /Q >nul\n";
    system("xcopy $cwd\\build\\${custom}\\EXT_BOOTLOADER $lsf_dir\\build\\${custom}\\ /Y /Q >nul");
    print "xcopy $cwd\\build\\${custom}\\*BOOTLOADER*.bin $lsf_dir\\build\\${custom}\\ /Y /Q >nul\n";
    system("xcopy $cwd\\build\\${custom}\\*BOOTLOADER*.bin $lsf_dir\\build\\${custom}\\ /Y /Q >nul");
  }
} else {
  # copy files needed by Target without MoDIS
  system("rd /s /q $lsf_dir\\MoDIS\\MoDIS") if (-d "$lsf_dir\\MoDIS\\MoDIS");
  system("rd /s /q $lsf_dir\\MoDIS_VC9\\MoDIS") if (-d "$lsf_dir\\MoDIS_VC9\\MoDIS");  
  print("robocopy $cwd $lsf_dir /MIR /XD ${cwd}\\build ${cwd}\\MoDIS\\ ${cwd}\\MoDIS_VC9\\ /XF robo*.log TStoCF*.log /LOG:${cwd}\\TStoCF.log /R:10 /NP\n");
  system("robocopy $cwd $lsf_dir /MIR /XD ${cwd}\\build ${cwd}\\MoDIS\\ ${cwd}\\MoDIS_VC9\\ /XF robo*.log TStoCF*.log /LOG:${cwd}\\TStoCF.log /R:10 /A-:RA /NP");
  system("robocopy $cwd\\MoDIS_VC9\\NetSim $lsf_dir\\MoDIS_VC9\\NetSim /MIR /LOG+:${cwd}\\TStoCF.log /R:10 /A-:RA /NP") if (-d "$cwd\\MoDIS_VC9\\NetSim");
  #system("robocopy $cwd\\MoDIS_VC9 $lsf_dir\\MoDIS_VC9 *.h /s /MIR /LOG:${cwd}\\TStoCF3.log /R:10 /A-:RA /NP");
  if(defined($LEVEL) && ($LEVEL eq VENDOR)){
    print "xcopy $cwd\\build\\${custom}\\EXT_BOOTLOADER $lsf_dir\\build\\${custom}\\ /Y /Q >nul\n";
    system("xcopy $cwd\\build\\${custom}\\EXT_BOOTLOADER $lsf_dir\\build\\${custom}\\ /Y /Q >nul");
    print "xcopy $cwd\\build\\${custom}\\*BOOTLOADER*.bin $lsf_dir\\build\\${custom}\\ /Y /Q >nul\n";
    system("xcopy $cwd\\build\\${custom}\\*BOOTLOADER*.bin $lsf_dir\\build\\${custom}\\ /Y /Q >nul");
  }
}
system("copy $cwd\\build\\${custom}\\build.log $lsf_dir\\build\\${custom}\\build.log >nul") if (-e "$cwd\\build\\${custom}\\build.log");
system("xcopy $cwd\\TStoCF.log $lsf_dir /Y /Q /i> nul");

if ($ENV{MBIS_BUILD_TIME_TMP} =~ /mbis/)
{
  $mbis_time = time;
  system("echo T_E,TS_TO_CF,P,$mbis_time >> ${cwd}\\$ENV{MBIS_BUILD_TIME_TMP}");
}

#mbis
if ($ENV{MBIS_BUILD_TIME_TMP} =~ /mbis/)
{
  if (-d "${cwd}\\build\\${custom}\\log\\mbis") 
  {
    print("robocopy ${cwd}\\build\\${custom}\\log\\mbis ${lsf_dir}\\build\\${custom}\\log\\mbis /MIR  /LOG:${cwd}\\mbisTStoCF.log /R:10 /NP\n");
    system("robocopy ${cwd}\\build\\${custom}\\log\\mbis ${lsf_dir}\\build\\${custom}\\log\\mbis /MIR /LOG:${cwd}\\mbisTStoCF.log /R:10 /A-:RA /NP");
  }
  else
  {
    print "can't find ${cwd}\\build\\${custom}\\log\\mbis \n" ;
  }
}

my $result = 0;

chdir("e:");
chdir($lsf_dir);
system("set > lsf_env.log");
system("attrib +r ${lsf_dir}\\MoDIS\\MoDIS.ncb") if ((-d $lsf_dir) && (-e "${lsf_dir}\\MoDIS\\MoDIS.ncb"));
system("attrib +r ${lsf_dir}\\MoDIS_VC9\\MoDIS.ncb") if ((-d $lsf_dir) && (-e "${lsf_dir}\\MoDIS_VC9\\MoDIS.ncb"));
print("perl ${lsf_dir}\\make2.pl -lsf @orgARGV\n");
system("perl ${lsf_dir}\\make2.pl -lsf @orgARGV");


if ($allArgv !~ /new_(modis|uesim)/i) {
  print("perl ${lsf_dir}\\mtk_tools\\clean_obj.pl\n") if (-f "${lsf_dir}\\mtk_tools\\clean_obj.pl");
  system("perl ${lsf_dir}\\mtk_tools\\clean_obj.pl") if (-f "${lsf_dir}\\mtk_tools\\clean_obj.pl");
  print("perl ${lsf_dir}\\tools\\clean_obj.pl\n") if (-f "${lsf_dir}\\tools\\clean_obj.pl");
  system("perl ${lsf_dir}\\tools\\clean_obj.pl") if (-f "${lsf_dir}\\tools\\clean_obj.pl");
}


#**********************************************************************************************
# ZIP Target Load and MoDIS L1 release for subsidiary
#**********************************************************************************************
if (<${lsf_dir}\\build\\$custom\\*.mak> || $allArgv =~ /new_modis/i)
{
  $infomake_path = "${lsf_dir}\\build\\$custom\\log\\infomake.log";
  if ((! -e $infomake_path) && ($allArgv =~ /new_modis/i))
  {
    $infomake_path = "${lsf_dir}\\build\\$custom\\log\\infomake_modis.log";
  }
  if (-e $infomake_path)
  {
    open (FILE_HANDLE, "<$infomake_path") or warn "cannot open $infomake_path\n";
    while (<FILE_HANDLE>) {
      if (/^(\S+)\s*=\s*(\S+)/)
      {
        $keyname = lc($1);
        $${keyname} = uc($2);
      }
    }
    close FILE_HANDLE;
    if (($mtk_subsidiary eq 'TRUE') && ($custom_release eq 'FALSE'))
    {
      print ("perl ${lsf_dir}\\mtk_tools\\zip_load.pl\n");
      system("perl ${lsf_dir}\\mtk_tools\\zip_load.pl");
      if ($allArgv =~ /new_modis/i)
      {
        foreach (<${lsf_dir}\\build\\$custom\\*.rar>)
        {
          system("copy /Y $_  ${cwd}\\build\\$custom\\". basename($_) ." > nul 2>&1");
        }
      }
    }
  }
}
#**********************************************************************************************
# End of ZIP Target Load and MoDIS L1 release for subsidiary
#**********************************************************************************************
if ($ENV{MBIS_BUILD_TIME_TMP} =~ /mbis/)
{
  $mbis_time = time;
  system("echo T_S,CF_TO_TS,P,$mbis_time >> ${lsf_dir}\\$ENV{MBIS_BUILD_TIME_TMP}");
}

print "\nrobocopy $lsf_dir $cwd /MIR /XF robo*.log /XD ${lsf_dir}\\build ${lsf_dir}\\MoDIS ${lsf_dir}\\MoDIS_VC9 /LOG:robo1.log /R:10 /NP at ", &CurrTimeStr;
system("robocopy $lsf_dir $cwd /MIR /XF robo*.log /XD ${lsf_dir}\\build ${lsf_dir}\\MoDIS ${lsf_dir}\\MoDIS_VC9 /LOG:robo1.log /R:10 /NP");
system("xcopy ${lsf_dir}\\robo1.log $cwd /Y /Q /i> nul");


if ($allArgv !~ /new_(modis|uesim)/i) {
  print "\nrobocopy ${lsf_dir}\\build\\$custom ${cwd}\\build\\$custom /MIR /XF robo*.log info_modis.log infomake_modis.log info_uesim.log infomake_uesim.log /XD ${lsf_dir}\\build\\$custom\\module\\modis\\ ${lsf_dir}\\build\\$custom\\log\\modis_setup\\ ${lsf_dir}\\build\\$custom\\module\\uesim\\ ${lsf_dir}\\build\\$custom\\log\\uesim_setup\\ /LOG:robo2.log /R:10 /NP at ", &CurrTimeStr;
  system("robocopy ${lsf_dir}\\build\\$custom ${cwd}\\build\\$custom /MIR /XF robo*.log info_modis.log infomake_modis.log info_uesim.log infomake_uesim.log /XD ${lsf_dir}\\build\\$custom\\module\\modis\\ ${lsf_dir}\\build\\$custom\\log\\modis_setup\\ ${lsf_dir}\\build\\$custom\\module\\uesim\\ ${lsf_dir}\\build\\$custom\\log\\uesim_setup\\ /LOG:robo2.log /R:10 /NP");
  system("xcopy ${lsf_dir}\\robo2.log $cwd /Y /Q /i> nul");
}

if (($allArgv =~ /new_(modis|uesim)/i) || ($allArgv =~ /-(modis|uesim)/i)) {
  print "\nrobocopy ${lsf_dir}\\MoDIS_VC9 ${cwd}\\MoDIS_VC9 /MIR /XF robo*.log /LOG:robo3.log /R:10 /NP at ", &CurrTimeStr;
  system("robocopy ${lsf_dir}\\MoDIS_VC9 ${cwd}\\MoDIS_VC9 /MIR /XF robo*.log /LOG:robo3.log /R:10 /NP");
  if ($allArgv =~ /-puremodis/i)
  {
    # avoid deleting Target files
    print "\nrobocopy ${lsf_dir}\\build\\$custom ${cwd}\\build\\$custom /E /XF robo*.log /LOG:robo3.log /R:10 /NP at ", &CurrTimeStr;
    system("robocopy ${lsf_dir}\\build\\$custom ${cwd}\\build\\$custom /E /XF robo*.log /LOG:robo3.log /R:10 /NP");
  }
  else
  {
    if ($allArgv =~ /modis/i) {
      system("robocopy ${lsf_dir}\\build\\$custom\\module\\modis ${cwd}\\build\\$custom\\module\\modis /MIR /XF robo*.log /LOG+:robo3.log /R:10 /NP");
      system("robocopy ${lsf_dir}\\build\\$custom\\log\\modis_setup ${cwd}\\build\\$custom\\log\\modis_setup /MIR /XF robo*.log /LOG+:robo3.log /R:10 /NP");
      system("xcopy ${lsf_dir}\\build\\$custom\\log\\info_modis.log ${cwd}\\build\\${custom}\\log /Y /Q >nul");
      system("xcopy ${lsf_dir}\\build\\$custom\\log\\infomake_modis.log ${cwd}\\build\\${custom}\\log /Y /Q >nul");
    }
    if ($allArgv =~ /uesim/i) {
      system("robocopy ${lsf_dir}\\build\\$custom\\module\\uesim ${cwd}\\build\\$custom\\module\\uesim /MIR /XF robo*.log /LOG+:robo3.log /R:10 /NP");
      system("robocopy ${lsf_dir}\\build\\$custom\\log\\uesim_setup ${cwd}\\build\\$custom\\log\\uesim_setup /MIR /XF robo*.log /LOG+:robo3.log /R:10 /NP");
      system("xcopy ${lsf_dir}\\build\\$custom\\log\\info_uesim.log ${cwd}\\build\\${custom}\\log /Y /Q >nul");
      system("xcopy ${lsf_dir}\\build\\$custom\\log\\infomake_uesim.log ${cwd}\\build\\${custom}\\log /Y /Q >nul");
    }
  }
  system("xcopy ${lsf_dir}\\robo3.log $cwd /Y /Q /i> nul");
  system("attrib +r ${cwd}\\MoDIS_VC9\\MoDIS.ncb") if ((-d $cwd) && (-e "${cwd}\\MoDIS_VC9\\MoDIS.ncb"));  
}

#mbis
if ($ENV{MBIS_BUILD_TIME_TMP} =~ /mbis/)
{
  if (-d "${lsf_dir}\\build\\${custom}\\log\\mbis") 
  {
    print("robocopy ${lsf_dir}\\build\\${custom}\\log\\mbis ${cwd}\\build\\${custom}\\log\\mbis /MIR  /LOG:${cwd}\\mbisCFtoTS.log /R:10 /NP\n");
    system("robocopy ${lsf_dir}\\build\\${custom}\\log\\mbis ${cwd}\\build\\${custom}\\log\\mbis /MIR /LOG:${cwd}\\mbisCFtoTS.log /R:10 /A-:RA /NP");
  }
  else
  {
    print "can't find ${lsf_dir}\\build\\${custom}\\log\\mbis \n" ;
  }
}

if ($ENV{MBIS_BUILD_TIME_TMP} =~ /mbis/)
{
  $mbis_time = time;
  system("echo T_E,CF_TO_TS,P,$mbis_time >> ${cwd}\\$ENV{MBIS_BUILD_TIME_TMP}");
}

system("echo Building time: ". (time - $build_start_time) ." > \"$cwd\\lsf.log\"");
print "\nTemp codebase is at $lsf_dir in $computerName. Perl version is $]\n";
print "\nm_cp2lsf.pl end at ", &CurrTimeStr, "\n";

&terminate_process('^(modis.exe|catcher.exe|netsim.exe)$');
exit $result >>8;

sub CurrTimeStr {
  my($sec, $min, $hour, $mday, $mon, $year) = localtime(time);
  return (sprintf "%4.4d/%2.2d/%2.2d %2.2d:%2.2d", $year+1900, $mon+1, $mday, $hour, $min);
}

#usage:
#      my %hash=iniToHash('/tmp/myini.ini');
#      print $hash{'TITLE'}->{'Name'},"\n";
#
sub iniToHash
{
  open(MYINI, $_[0]);
  my %hash;
  my $hashref;
    
  while(<MYINI>)
  {
    next if ((/^\s*$/) || (/^\s*#/));
    if (/^\s*\[(.+)\]/)
    {
      $hashref = $hash{$1} ||= {};
    }
    elsif (/^\s*(\S+)\s*=\s*(.+)\s*$/)
    {
      $hashref->{$1} = $2;
    }
    elsif (/^\s*(\S+)\s*\+=\s*(.+)\s*$/)
    {
      $hashref->{$1} = $hashref->{$1} . " $2";
    }
  }
    
  close MYINI;
  return %hash;
}

sub terminate_process
{
  $reg_exp = $_[0] or die;

  $objWMI = Win32::OLE->GetObject('winmgmts:\\\\.\\root\\cimv2');
  $colProcesses = $objWMI->InstancesOf('Win32_Process');
  foreach my $objProcess (in $colProcesses)
  {
    if ($objProcess->Name =~ /$reg_exp/i)
    {
      $objName = $objProcess->Name;
      $objPID = $objProcess->ProcessID;
      $objWMIProcess = Win32::OLE->GetObject('winmgmts:\\\\.\\root\\cimv2:Win32_Process.Handle=\'' . $objPID . '\'');
      
      if ($intRC = $objWMIProcess->Terminate())
      {
        print "Could not kill process \"$objName\" (PID=$objPID). Error code: " . $intRC, "\n";
      }
    }
  }
}

sub reset_env_var
{
	my $env_var_ref = shift;
	my $CurrVer;
	my %vals;

	my $p = "SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment";
	$::HKEY_LOCAL_MACHINE->Open($p, $CurrVer) || die "Open: $!";
	$CurrVer->GetValues(\%vals); # get sub keys and value -hash ref

	foreach my $k (keys %vals)
	{
	#	print "$k\t\t@{$vals{$k}}\n";
		foreach my $env_var (@$env_var_ref)
		{
			if ($k eq $env_var)
			{
				$ENV{$env_var} = $vals{$k}->[2];
			}
		}
	}
}