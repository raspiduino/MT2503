use strict;

my $force_romizing = 0;
my $debug_print = 0;
my $thefile = shift @ARGV or &usage;
my $theVerno = shift @ARGV or &usage;
my $m_in_lsf = shift @ARGV;

my $custom;
my $project;
#print "Read $thefile $theVerno\n";
if ($thefile =~ /make\\(\w+)_(\w+?)(\(\w+\))?\.mak/i)
{
	$custom = $1;
	$project = $2;
}
else
{
	die "The Makefile format should be make\\custom_project.mak\n";
}
my $build_log = "build\\$custom\\romizing.log";

my %feature;
open (FILE_HANDLE, "<$thefile") or die "cannot open $thefile\n";
while (<FILE_HANDLE>)
{
	if ((/^([^\#]*)\#?.*/) && ($1 =~ /^(\w+)\s*=\s*(.*\S)\s*$/))
	{
		my $keyname = lc($1);
		$feature{$keyname} = uc($2);
	}
}
close FILE_HANDLE;

my %verno;
open (FILE_HANDLE, "<$theVerno") or die "cannot open $theVerno\n";
while (<FILE_HANDLE>)
{
	if ((/^([^\#]*)\#?.*/) && ($1 =~ /^(\w+)\s*=\s*(.*\S)\s*$/))
	{
		my $keyname = lc($1);
		$verno{$keyname} = uc($2);
	}
}
close FILE_HANDLE;

chomp(my $cwd = `cd`);

my $notify_list = "\\\\glbfs14\\sw_releases\\3rd_party\\Scripts\\BM_conf.ini";
my $romizing_repository = "\\\\mtkrfs02\\Public1\\romizing_repository";
my $romizing_repository_backup = "\\\\glbfs14\\sw_releases\\romizing_repository";
my $curr_usr = lc(getlogin());
my $BM_LIST;
if (-e $notify_list)
{
	my %BM_conf = iniToHash($notify_list);
	$BM_LIST = $BM_conf{'romizing_server'}->{'BM_LIST'};
}

if ((defined $feature{j2me_support}) && ((uc($feature{j2me_support}) eq "NEMO") || (uc($feature{j2me_support}) eq "IJET")))
{
  # To check if the Java settings in the project makefile was the same with the romizing one.
  #unlink("make\\~romizing\.log") if (-e "make\\~romizing.log");
  unlink($build_log) if (-e $build_log);
  my $source_path;
  my $destination_path;
  my $rec_name;
  my $make_name;
  if ($ENV{'MTK_INTERNAL'} eq 'TRUE')
  {
    if ((-d "$romizing_repository_backup\\$verno{verno}") || (("mtk80869" =~ /$curr_usr/i) && (-d $romizing_repository_backup)))
    {
      $romizing_repository = $romizing_repository_backup;
    }
  }
  if ((defined($feature{flavor})) && ($feature{flavor} ne "NONE")) {
    $source_path = "$romizing_repository\\$verno{verno}\\$feature{board_ver}\($feature{flavor}\)\\";
    $destination_path = "custom\\j2me\\$feature{j2me_support}\\$feature{board_ver}\($feature{flavor}\)\\";
    $rec_name = "$feature{board_ver}\($feature{flavor}\).rec";
    $make_name = "${custom}_${project}($feature{flavor})";
  } else {
    $source_path = "$romizing_repository\\$verno{verno}\\$feature{board_ver}\\";
    $destination_path = "custom\\j2me\\$feature{j2me_support}\\$feature{board_ver}\\";
    $rec_name = "$feature{board_ver}.rec";
    $make_name = "${custom}_${project}";
  }
  print "romizing_repository = $romizing_repository\n" if ($debug_print);
  if (($ENV{'MTK_INTERNAL'} eq 'TRUE') && (-d $romizing_repository)) {
    if (($BM_LIST =~ /$curr_usr/i) && (-d "j2me\\vm\\$feature{j2me_support}\\romizing")) {
      # OF
      if ($m_in_lsf) {
        &gen_romizing($source_path, $make_name, $feature{j2me_support});
        &copy_romizing($source_path, $destination_path, $rec_name);
      } else {
        if ($cwd =~ /^e/i) {
          &gen_romizing($source_path, $make_name, $feature{j2me_support});
          &copy_romizing($source_path, $destination_path, $rec_name);
        }
      }
    } elsif (("mtk80869" =~ /$curr_usr/i) && (-d "j2me\\vm\\$feature{j2me_support}\\romizing")) {
      # workaround for ROMizing script owner in subsidiary
      &gen_romizing($destination_path, $make_name, $feature{j2me_support});
    } else {
      if (-d $destination_path) {
        if ($BM_LIST =~ /$curr_usr/i) {
          &copy_romizing($source_path, $destination_path, $rec_name);
        } else {
          if (!-e "$destination_path\\$rec_name") {
            &copy_romizing($source_path, $destination_path, $rec_name);
          }
        }
      } else {
        &copy_romizing($source_path, $destination_path, $rec_name);
      }
    }
  }

  my $romizing_flag = 0;
  if ($feature{j2me_support} eq "IJET") {
    if (-e "$destination_path$rec_name") {
      open (FILE_HANDLE, "<$destination_path$rec_name") or die "Cannot open $destination_path$rec_name:$!\n";
      open (WRITE_HANDLE, ">>$build_log") or die "Cannot open $build_log:$!\n";
      while (<FILE_HANDLE>) {
        if (/^(\S+)\s*=\s*(\S+)/) {
          my $rec_keyname = lc($1);
          if ($${rec_keyname} ne uc($2)) {
            if (($${rec_keyname} eq "KVM") && (uc($2) eq "KVM_SOURCE")) {
            } elsif (($${rec_keyname} eq "KVM_SOURCE") && (uc($2) eq "KVM")) {
            } elsif (($${rec_keyname} eq "HI_VM_SOURCE") && (uc($2) eq "HI_VM")) {
            } elsif (($${rec_keyname} eq "HI_VM") && (uc($2) eq "HI_VM_SOURCE")) {
            } elsif (${rec_keyname} eq "verno") {
            } else {
              print STDERR "ERROR: $rec_keyname mismatched in the project makefile(".$${rec_keyname}.") and the romizing(".uc($2).").\n";
              print WRITE_HANDLE "ERROR: $rec_keyname mismatched in the project makefile(".$${rec_keyname}.") and the romizing(".uc($2).").\n";
              $romizing_flag = 1;
            }
          }
        }
      }
      close WRITE_HANDLE;
      close FILE_HANDLE;
      if ($romizing_flag == 1) {
        #if ($empty_resource eq "TRUE") {
          exit(1);
        #}
      }
    }
  }
} else {
  print "Remove romizing folder for BM\n" if ($debug_print);
  if (($BM_LIST =~ /$curr_usr/i) && (-d "j2me\\vm\\IJET\\romizing")) {
    print ("call rd /s /q j2me\\vm\\IJET\\romizing\n");
    system("call rd /s /q j2me\\vm\\IJET\\romizing");
  }
  if (($BM_LIST =~ /$curr_usr/i) && (-d "j2me\\vm\\NEMO\\romizing")) {
    print ("call rd /s /q j2me\\vm\\NEMO\\romizing\n");
    system("call rd /s /q j2me\\vm\\NEMO\\romizing");
  }
}

exit(0);




sub gen_romizing
{ 
  my ($source, $make_name, $java_path) = @_;
  my $is_regen  = 0;
  my $lib_mtime = 0;
  # dependency check
  if ((-e $source) && ($force_romizing == 0))
  {
    foreach my $file (&list_dir($source))
    {
      $lib_mtime = &get_file_mYMD("$source\\$file") if (&get_file_mYMD("$source\\$file") > $lib_mtime);
    }
    my @romizing_checklist;
    push(@romizing_checklist, split(/[\r\n]+/, `robocopy $cwd\\j2me\\vm\\$java_path\\romizing\\src $cwd\\abcdef /S /MAXAGE:$lib_mtime /L /NS /NC /NDL /NJH /NJS /NP`));
    push(@romizing_checklist, split(/[\r\n]+/, `robocopy $cwd\\j2me\\vm\\$java_path\\romizing $cwd\\abcdef proguardConfig.txt *.mak *.pl /MAXAGE:$lib_mtime /L /NS /NC /NDL /NJH /NJS /NP`));
    foreach my $file (@romizing_checklist)
    {
      if ($file =~ /^\s*(\S+)/i)
      {
        $is_regen = 1;
        print "ROMizing: $file\n" if ($debug_print);
        last;
      }
    }
  }
  else
  {
    $is_regen = 1;
    #print "ROMizing: FORCE\n";
  }
  # do romizing
  if ($is_regen)
  {
    chdir("$cwd\\j2me\\vm\\$java_path\\romizing");
    print "call go32.bat $verno{branch} $make_name remake\n";
    my $result = system("call go32.bat $verno{branch} $make_name remake");
    chdir($cwd);
    my $log_name = $feature{board_ver};
    if ((defined($feature{flavor})) && ($feature{flavor} ne "NONE")) {
      $log_name = "$feature{board_ver}\($feature{flavor}\)";
    }
    if (-e "j2me\\vm\\$java_path\\romizing\\${log_name}_romizing.log")
    {
      my $FILE_OUTPUT;
      if (!-z "j2me\\vm\\$java_path\\romizing\\${log_name}_romizing.log")
      {
        open $FILE_OUTPUT, ">$build_log" or die "ERROR: Fail to write $build_log\n";
        print $FILE_OUTPUT "ERROR: Fail to do ROMizing for $make_name\n";
        my $FILE_INPUT;
        if (open($FILE_INPUT, "<j2me\\vm\\$java_path\\romizing\\${log_name}_romizing.log"))
        {
          my $backup = $/;
          undef $/;
          my $text = <$FILE_INPUT>;
          $/ = $backup;
          print $FILE_OUTPUT $text;
          close $FILE_INPUT;
        }
        else
        {
          print $FILE_OUTPUT "ERROR: Fail to read j2me\\vm\\$java_path\\romizing\\${log_name}_romizing.log\n";
        }
        close $FILE_OUTPUT;
        print "ERROR: Fail to do ROMizing for $make_name, check $build_log\n";
        exit(1);
      }
      else
      {
        open $FILE_OUTPUT, ">$build_log" or die "ERROR: Fail to write $build_log\n";
        print $FILE_OUTPUT "[Info] Passed in ROMizing for $make_name at " . time . "\n";
        close $FILE_OUTPUT;
      }
    }
    else
    {
      print "Not found j2me\\vm\\$java_path\\romizing\\${log_name}_romizing.log\n";
    }
  }
  else
  {
    print "No need to update gen_romizing result\n";
  }
  if (-e "$cwd\\j2me\\vm\\$java_path\\romizing")
  {
    print ("call rd /s /q $cwd\\j2me\\vm\\$java_path\\romizing\n");
    system("call rd /s /q $cwd\\j2me\\vm\\$java_path\\romizing");
  }
  if (($ENV{"LSF_remote"}) && (-e $ENV{"LSF_remote"} . "\\j2me\\vm\\$java_path\\romizing"))
  {
    print ("call rd /s /q " . $ENV{"LSF_remote"} . "\\j2me\\vm\\$java_path\\romizing\n");
    system("call rd /s /q " . $ENV{"LSF_remote"} . "\\j2me\\vm\\$java_path\\romizing");
  }
}

sub copy_romizing
{
	my ($source, $destination, $rec) = @_;
	print "source=$source\n";
	print "destination=$destination\n";
	print "rec=$rec\n";
	if ((-d $source) && (-e "$source\\$rec"))
	{
		my $timestamp_server = (stat("$source\\$rec"))[9];
		my $timestamp_local = 0;
		if (-e "$destination\\$rec") {
			$timestamp_local = (stat("$destination\\$rec"))[9];
		}
		if ($timestamp_server > $timestamp_local) {
			print "copy \"$source\*\" to \"$destination\*\" ...\n";
			system("if exist \"$destination\*.c\" del /q \"$destination\*.c\"");
			system("if exist \"$destination\*.cpp\" del /q \"$destination\*.cpp\"");
			system("xcopy /e /Y \"$source\*\" \"$destination\*\" > nul");
		}
	}
	else
	{
		my $res;
		if ($feature{"j2me_romizing_switch"} eq "TRUE")
		{
			$res = &search_romizing();
		}
		else
		{
			print "Skip searching other project romizing result when J2ME_ROMIZING_SWITCH != TRUE\n";
		}
		if ($res ne "")
		{
			&copy_romizing("$romizing_repository\\$verno{verno}\\$res\\", $destination, "$res.rec");
		}
		else
		{
			open FP, ">>build\\${custom}\\romizing.log";
			print FP "ERROR: $source does not exist.\nPlease execute romizing first.\n";
			close FP;
			print "ERROR: $source does not exist.\nPlease execute romizing first.\n";
			exit(2);
		}
	}
}

sub search_romizing
{
	my $last_index = -1;
	my $last_found = "";
	my @java_feature_list = &read_java_def("make\\JAVA_DEF.mak");
	foreach my $dir (&list_dir("$romizing_repository\\$verno{verno}"))
	{
		next if ($dir eq ".");
		next if ($dir eq "..");
		my $rec = "$romizing_repository\\$verno{verno}\\$dir\\$dir.rec";
		my %rec;
		if (-e $rec)
		{
			print $rec . "\n" if ($debug_print);
			open (FILE_HANDLE, "<$rec") or die "cannot open $rec\n";
			while (<FILE_HANDLE>) {
				if ((/^([^\#]*)\#?.*/) && ($1 =~ /^(\w+)\s*=\s*(.*\S)\s*$/)) {
					my $keyname = lc($1);
					$rec{$keyname} = uc($2);
				}
			}
			close FILE_HANDLE;
			my $this_index = 0;
			my $this_found = 1;
			while (($this_index <= $#java_feature_list) && ($this_found == 1))
			{
				my $name = lc($java_feature_list[$this_index]);
				if ($rec{$name} eq $feature{$name})
				{
					print $rec{$name} . "==" . $feature{$name} . "\n" if ($debug_print);
					$this_index++;
				}
				else
				{
					print $rec{$name} . "!=" . $feature{$name} . "\n" if ($debug_print);
					$this_found = 0;
					$this_index--;
				}
			}
			if ($last_index < $this_index)
			{
				$last_index = $this_index;
				$last_found = $dir;
			}
			if ($last_index >= $#java_feature_list)
			{
				last;
			}
		}
	}

	print "Last found = " . $last_found . "\nMatched count = " . $last_index;
	if ($last_index >= $#java_feature_list)
	{
		print " (Full)\n";
	}
	else
	{
		print " (Partial)\n";
	}
	return $last_found;
}

sub read_java_def
{
	my $input = shift;
	my @result;
	if ((-e $input) && (open FILE_HANDLE, "<$input"))
	{
		my $line;
		my $flag_read;
		my $flag_cont = 0;
		while ($line = <FILE_HANDLE>)
		{
			if (($line =~ /^\s*(NEMO)_FEATURE_LIST\s*:?=/) || ($flag_cont))
			{
				$flag_read .= $line;
				if ($line =~ /\\$/)
				{
					$flag_cont = 1;
				}
			}
			else
			{
				$flag_cont = 0;
			}
		}
		close FILE_HANDLE;
		$flag_read =~ s/^\s*(NEMO)_FEATURE_LIST\s*:?=//;
		$flag_read =~ s/\\\n//g;
		$flag_read =~ s/^\s+//;
		@result = split(/\s+/, $flag_read);
	}
	else
	{
		die "Fail to open $input";
	}
	return @result;
}

sub list_dir
{
  my $path  = $_[0];
  my @files = ();
  
  if (opendir(FILE, $path)) {
    foreach (readdir(FILE))
    {
      next if ($_ eq ".");
      next if ($_ eq "..");
      push @files, $_;
    }
    closedir(FILE);
  }
  
  return @files;
}

sub get_file_mYMD
{
  my($sec, $min, $hour, $mday, $mon, $year, $wday, $yday, $isdst) = localtime((stat($_[0]))[9]);

  return sprintf("%04d%02d%02d", ($year + 1900), ($mon + 1), $mday);
}

sub iniToHash {
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

sub usage
{
	die "romizing.pl project.mak verno.bld\n";
}

