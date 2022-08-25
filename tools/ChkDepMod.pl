use strict;
use File::Basename;
use File::stat;
use Getopt::Long;

my $step = 255;
my $check_exist = 0;
my $flag_debug = 0;

GetOptions(
	'step:i' => \$step,
);

&Usage() if ($#ARGV < 2);
my $project = shift @ARGV;
my $modem = shift @ARGV;
my $platform = shift @ARGV;
my $file_log = "ews_deps";
my $file_add = "ews_added_files";
my $file_modify = "ews_modified_files";
my $file_delete = "ews_deleted_files";

# collect all dependency files in codebase
my %file_depend;
foreach my $file ("build/" . $project . "/" . $modem . "/" . $platform . "r", "MoDIS_VC9/_BUILD_DEP")
{
	&FindDepend(\%file_depend, $file) if (-d $file);
}

if ($step == 0)
{
	# before build, check if any file in dep is patched/removed
	print "Checking before smart build ...\n";
	my %change_list;
	if (-e $file_add)
	{
		$check_exist = \%change_list;
		print "Found $file_add. ";
		&ReadChangeList(\%change_list, $file_add, 3);
	}
	if (-e $file_modify)
	{
		$check_exist = \%change_list;
		print "Found $file_modify. ";
		&ReadChangeList(\%change_list, $file_modify, 2);
	}
	if (-e $file_delete)
	{
		$check_exist = \%change_list;
		print "Found $file_delete. ";
		&ReadChangeList(\%change_list, $file_delete, 1);
	}
	if ($check_exist == 0)
	{
		print "Not found $file_add or $file_modify or $file_delete";
	}
	print "\n";
	my $number_update = &CheckDepend(\%file_depend, $check_exist);
	unlink($file_log) if (-e $file_log);

	# before submit job, check what lsf queue
	my $bqueues;
	if ($ENV{'MTK_INTERNAL'} eq 'TRUE')
	{
		if ($number_update < 20)
		{
			# normal
			$bqueues = 3;
		}
		else
		{
			# localq
			$bqueues = 2;
		}
		print "number_update = $number_update, return = $bqueues\n";
	}
	else
	{
		# no queue
		$bqueues = 1;
	}
	exit $bqueues;
}
elsif ($step == 1)
{
	# after build, check what dep files are updated
	my $LOGHANDLE;
	print "Checking after smart build ...\n";
	open $LOGHANDLE, ">$file_log" or die "Fail to write $file_log";
	my $time_standard = 0;
	if (-e "make/app_cfg.mak")
	{
		my $inode = stat("make/app_cfg.mak");
		$time_standard = $inode->mtime;
	}
	#print "time_standard = $time_standard\n";
	foreach my $file (keys %file_depend)
	{
		if ($file =~ /r[\\\/](codegen|pregen|comp|postgen)_dep[\\\/]\S+\.det$/i) # or ($file =~ /\\_BUILD_DEP\\\S+\.de[pt]$/i)
		{
			# Target det only
			my $inode = stat($file);
			$file_depend{$file} = $inode->mtime;
		}
	}
	my $number_update = 0;
	print $LOGHANDLE "[Info] The following dependency files have been updated:\n";
	foreach my $file (sort {$file_depend{$a} <=> $file_depend{$b}} keys %file_depend)
	{
		if ($file_depend{$file} > $time_standard)
		{
			print $LOGHANDLE basename($file) . " = " . $file_depend{$file};
			if (1)
			{
				# detail infomation
				if ($file =~ /r[\\\/](codegen|pregen)_dep[\\\/]\S+\.det$/i)
				{
					print $LOGHANDLE " (Target pre-gen)";
				}
				elsif ($file =~ /r[\\\/](comp)_dep[\\\/]\S+\.det$/i)
				{
					print $LOGHANDLE " (Target module)";
				}
				elsif ($file =~ /[\\\/]_BUILD_DEP[\\\/](codegen|pregen)_dep[\\\/]\S+\.det$/i)
				{
					print $LOGHANDLE " (MoDIS pre-gen)";
				}
			}
			print $LOGHANDLE "\n";
			$number_update++;
		}
	}
	print $LOGHANDLE "[Info] Totally ". $number_update . " files.\n";
	close $LOGHANDLE;
}
elsif ($step == 2)
{
	my $res = &BackTime(\%file_depend);
}
else
{
	&Usage();
}

exit 0;



sub FindDepend
{
	my $ref_depend = shift;
	my $in_path = shift;
	my $DIRHANDLE;
	opendir $DIRHANDLE, "$in_path" or die "Fail to opendir $in_path\n";
	my @file_dep = readdir $DIRHANDLE;
	closedir $DIRHANDLE;
	foreach my $line (@file_dep)
	{
		if (($line eq ".") || ($line eq ".."))
		{
			next;
		}
		elsif (-d $in_path . "/" . $line)
		{
			&FindDepend($ref_depend, $in_path . "/" . $line);
		}
		elsif ($line =~ /\.dep$/i)
		{
			$ref_depend->{$in_path . "/" . $line} = 0;
		}
		elsif ($line =~ /\.det$/i)
		{
			next if ($line eq "postgen.det");
			next if ($in_path !~ /\b(pregen|codegen|postgen|comp)_dep\b/i);
			$ref_depend->{$in_path . "/" . $line} = 0;
		}
	}
}

sub ReadChangeList
{
	my $ref_change = shift;
	my $in_file = shift;
	my $value = shift;
	my $line;
	my $FILEHANDLE;
	open $FILEHANDLE, "<$in_file" or die "Fail to read $in_file\n";
	while ($line = <$FILEHANDLE>)
	{
		chomp($line);
		$ref_change->{lc($line)} = $value;
	}
	close $FILEHANDLE;
}

sub CheckDepend
{
	my $ref_depend = shift;
	my $ref_change = shift;
	my $result = 0;
	my %file_dep;
	foreach my $file (keys %$ref_depend)
	{
		my $line;
		my $FILEHANDLE;
		open $FILEHANDLE, "<$file" or die "Fail to read $file\n";
		while ($line = <$FILEHANDLE>)
		{
			next if ($line =~ /^\#/i);
			$line =~ s/^(\S+\:)?\s*(.*?)\s*(\\)?$/$2/;
			foreach my $src (split /\s+/, $line)
			{
				if ($src eq "")
				{
					next;
				}
				elsif (defined $file_dep{lc($src)})
				{
					$file_dep{lc($src)}->{$file} = 1;
				}
				else
				{
					$file_dep{lc($src)} = {$file => 1};
				}
			}
		}
		close $FILEHANDLE;
	}
	my ($key, $value);
	while (($key, $value) = each %file_dep)
	{
		if ((($ref_change) && ($ref_change->{$key} == 1)) || (($ref_change == 0) && (! -e $key)))
		{
			print "[Warn] " . $key . " is deleted";
			print " in" if ($flag_debug);
			foreach my $file (keys %$value)
			{
				print " " . basename($file) if ($flag_debug);;
				$ref_depend->{$file} = 1;
				unlink($file) if (! $flag_debug);
			}
			print "\n";
		}
		elsif (($ref_change) && ($ref_change->{$key} == 2))
		{
			print "[Warn] " . $key . " is modified";
			print " in" if ($flag_debug);
			foreach my $file (keys %$value)
			{
				print " " . basename($file) if ($flag_debug);;
				$ref_depend->{$file} = 2;
			}
			print "\n";
		}
		elsif (($ref_change) && ($ref_change->{$key} == 3))
		{
			foreach my $file (keys %$value)
			{
				$ref_depend->{$file} = 3;
			}
		}
	}
	my $number_update = 0;
	while (($key, $value) = each %$ref_depend)
	{
		if ($value == 0)
		{
			$number_update++;
		}
	}
	return $number_update;
}

sub BackTime
{
	my $ref_hash = shift;
	my $result = 0;
	my %file_dep;
	foreach my $file (keys %$ref_hash)
	{
		my $inode = stat($file);
		my $line;
		my $FILEHANDLE;
		open $FILEHANDLE, "<$file" or die "Fail to read $file\n";
		while ($line = <$FILEHANDLE>)
		{
			next if ($line =~ /^\#/i);
			$line =~ s/^(\S+\:)?\s*(.*?)\s*(\\)?$/$2/;
			foreach my $src (split /\s+/, $line)
			{
				if ($src eq "")
				{
					next;
				}
				elsif (! -e $src)
				{
					print "[Warn] " . $src . " is missing\n";
					next;
				}
				elsif (($file_dep{lc($src)} == 0) || ($file_dep{lc($src)} > $inode->mtime))
				{
					$file_dep{lc($src)} = $inode->mtime;
				}
			}
		}
		close $FILEHANDLE;
	}
	my ($key, $value);
	while (($key, $value) = each %file_dep)
	{
		my $inode = stat($key);
		if ($inode->mtime > $value)
		{
			print "[Warn] " . $key . " is newer\n";
			$result |= 0x01;
			utime($inode->atime, $value - 1, $key) if (! $flag_debug);
		}
	}
	return $result;
}

sub Usage
{
	my $script = basename($0);
	print <<"__EOFUSAGE";

Usage: $script --step X PROJECT_NAME MODEM_TYPE PLATFORM

X         0:     Check before smart new, such as files deleted
          1:     Check after smart new, such as actions processed
          2:     Check after AAPMC, such as timestamp
PROJECT_NAME     Specify project name, such as AMBER38_DEMO etc...
MODEM_TYPE       Specify modem type, such as l1s, basic, gsm, gprs, umts etc...
PLATFORM         Specify platform in project makefile, such as MT6238 etc...
__EOFUSAGE
	exit 1;
}
