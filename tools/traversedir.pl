#!/usr/bin/perl -w

use File::Copy;

($#ARGV < 4) && die "Too few ARGUMENTS!\n";
$relDir = $ARGV[0];
$en_file = $ARGV[1];
$dis_file = $ARGV[2];
$if_fil = uc($ARGV[3]);
$log_fil = uc($ARGV[4]);
$dir_file = $ARGV[5];
$not_remove_dir_file = $ARGV[6];
if (defined($ARGV[7])&&($ARGV[7] =~ /TRUE/i)) {
	$not_remove_MTK_INTERNAL_MMI_FEATURES = 1;
} else {
	$not_remove_MTK_INTERNAL_MMI_FEATURES = 0;
}

$en_parallel = 0;
if(defined($ARGV[7])&&(($ARGV[7] =~ /NOPARALLEL/i)||(defined($ARGV[8])&&($ARGV[8] =~ /NOPARALLEL/i))))
{
	$en_parallel = 0;
}

(!-d $relDir) && die "Release Directory $relDir does NOT exist\n";
(!-e $en_file) && die "Enable file $en_file does NOT exist\n";
(!-e $dis_file) && die "Disable file $dis_file does NOT exist\n";
($if_fil ne "TRUE") && ($if_fil ne "FALSE") && die "if_fil $if_fil should be TRUE/FALSE\n";
($log_fil ne "TRUE") && ($log_fil ne "FALSE") && die "log_fil $log_fil should be TRUE/FALSE\n";
(!-e $dir_file) && die "Removal Dir file $dir_file does NOT exist\n";
(!-e $not_remove_dir_file) && die "Not removal Dir file $not_remove_dir_file does NOT exist\n";
system "del ~removalDir.log";
open(dirH,$dir_file);
while(<dirH>){
	chomp($_);
	if (!(index($_,"#") == 0) && length($_) >= 1){		
		if (index($_,"\\") == 0){
			$_ =~ s/\\//;
		}
		if ($_ =~ /.+(\\)$/) {
			chop($_);
		}	
		$_ = $relDir . "\\" . $_;
		if(!-e $_) {
			system "echo WARNING! $_ doesn't exist. >> ~removalDir.log";
			print "WARNING! $_ doesn't exist.\n";
		}
		push(@removalDir,$_);
	}
}
close(dirH);

$tmpPath = ".\\tmpPathforTraversedir";
system("if exist ~traverseFile*.c del /F /Q ~traverseFile*.c");

# Read not removal dir
open(dirH,$not_remove_dir_file);
while(<dirH>){
	chomp($_);
	if (!(index($_,"#") == 0) && length($_) >= 1){		
		if (index($_,"\\") == 0){
			$_ =~ s/\\//;
		}
		if ($_ =~ /.+(\\)$/) {
			chop($_);
		}
		$not_r_d = $relDir . "\\.\\" . $_;
		$_ = $relDir . "\\" . $_;

		if(!-e $_) {
			system "echo WARNING! $_ doesn't exist. >> ~not_removalDir.log";
			print "WARNING! $_ doesn't exist.\n";
		}
		${$_} = 1;
		${$not_r_d} = 1;
	}
}
close(dirH);

# Generator dummy en.def for MMI_features.h
my $en_file_dummy = "make\\dummy_en.def";
system("copy /y nul $en_file_dummy > nul");

#@thedirs = ($relDir);

@allfiles = qw();
foreach $specifyDir (@removalDir) {
  if (-d $specifyDir) {
    if (opendir(SUBDIRS, $specifyDir)) {
      @childdirs = sort readdir(SUBDIRS);
      closedir(SUBDIRS);
    } else {
      warn "Could not open $specifyDir\n";
      next;
    }
    foreach $f (@childdirs) {
      next if ($f eq ".");
      next if ($f eq "..");
      next if (($f eq "tools") && ($specifyDir eq $relDir));

      $fname = $specifyDir . "\\". $f;

      if (defined ${$fname}) {
        if (${$fname} eq 1) {
        next;
        }
      }
      if (defined ${$specifyDir}) {
        if (${$specifyDir} eq 1) {
        next;
        }
      }
    	if (-d $fname) {
      	push(@removalDir, $fname);
    	} elsif ($f =~ /\.(c|h|cpp|hpp|s|java|txt|mak)$/i) {
      	next if (lc($f) eq "t9.h");
      	if ($f =~ /txt$/i) {
      		if ($f =~ /^scat/i) {
      			push(@allfiles, $fname);
      		}
      	} else {
      		push(@allfiles, $fname);
      	}
    	}
  	}
	}	elsif (-e $specifyDir) {
		if ($specifyDir =~ /\.(c|h|cpp|hpp|s|java|txt|mak)$/i) {
      	next if (lc($specifyDir) eq "t9.h");
      	if ($specifyDir =~ /txt$/i) {
      		if ($specifyDir =~ /^scat/i) {
      			push(@allfiles, $specifyDir);
      		}
      	} else {
      		push(@allfiles, $specifyDir);
      	}
    } else {
    	warn "$specifyDir is not a code-removal-format(.c,.h,.cpp,.hpp,.s,.java) file.";
    	next;
    }
	}
}

#foreach $tarDir (@thedirs) {
#	print "$tarDir\n";
#  if (opendir(OBJDIRS, $tarDir)) {
#    @syndirs = sort readdir(OBJDIRS);
#    closedir(OBJDIRS);
#  } else {
#    warn "Could not open $tarDir\n";
#    next;
#  }
#  foreach $f (@syndirs) {
#    next if ($f eq ".");
#    next if ($f eq "..");
#    next if (($f eq "tools") && ($tarDir eq $relDir));
#    $fname = $tarDir . "\\". $f;
#    if (-d $fname) {
#      push(@thedirs, $fname);
#    } elsif ($f =~ /\.(c|h|cpp|hpp|s)$/i) {
#      next if (lc($f) eq "t9.h");
#      push(@allfiles, $fname);
#    }
#  }
#}
if($en_parallel){
	#for parallelize
	my $process = $ENV{NUMBER_OF_PROCESSORS};
	$maxdeep = 0;
	if(($process<1)||($process>128)){
		$maxdeep=5;
	#	print "process is $maxdeep, maxdeep=5\n";
	}else{
#		while(2**$maxdeep<$process){
#			$maxdeep ++;
#		}
		$maxdeep=int((log $process)/log 2);
	#	print "maxdeep = $maxdeep\n";
	}
	if($maxdeep < 0){
		$maxdeep = 0;
	}
	if($maxdeep > 3){
		$maxdeep = 3;
	}
	#$tmpdebugefolder = ".\\tmpdebugparallel";
	#system("md $tmpdebugefolder");

	if(-e "$tmpPath"){
		system("rd /S /Q $tmpPath");
	}
	system("md $tmpPath");
	print "filter start!\n";
	&scatterFilteFiles(0,$#allfiles,0,\@allfiles);
	&errorJudge;
	if(-e "$tmpPath"){
	  system("rd /S /Q $tmpPath");
  }
	print "filter done!\n";
	#system("rd /S /Q $tmpdebugefolder");
}
else{
	my $tmpFile = ".\\~traverseFile.c";
	foreach my $f (@allfiles) {
		my $writeFile = 1;
		if (($f =~ /mmi_features\.h/i) && ($not_remove_MTK_INTERNAL_MMI_FEATURES =~ /0/)) {
			open(F, "<$f");
			open(W, ">.\\~mmi_features.h");
			while(<F>){
				if (($_ =~ /ifdef/i) && ($_ =~ /MTK_INTERNAL_MMI_FEATURES/i)) {
					$writeFile = 0;
				}
				if($writeFile == 1) {
					print W $_;
				}
				if (($_ =~ /endif/i) && ($_ =~ /MTK_INTERNAL_MMI_FEATURES/i)) {
					$writeFile = 1;
				}
			}
			close(W);
			close(F);
			move(".\\~mmi_features.h",$f);
		}
		if ($f !~ /\.mak/) {
			if ($if_fil eq "TRUE") {
				die "Exist tmpFile of before start $f." if (-e "$tmpFile");
#				print("$f\n");
				if ($f !~ /mmi_features\.h/i)
				{
					system("perl tools\\if_fil.pl $f $en_file $dis_file $tmpFile");
				}
				else
				{
					system("perl tools\\if_fil.pl $f $en_file_dummy $dis_file $tmpFile");
				}
				move("$tmpFile","$f");
				#system("move /y $tmpFile $f > nul");
			}
			if ($log_fil eq "TRUE") {
				#print("\tlog_fil\n");
				system("perl tools\\log_fil.pl $f > nul");
			}
		}
	#	if(-e "mtk_tools\\renameCompileOption.pl"){
	#		system("perl mtk_tools\\renameCompileOption.pl $f");
	#	}
	}
}
system("if exist $en_file_dummy del $en_file_dummy");

@traverseTempFile = <~traverseFile*.c>;
if ($#traverseTempFile >= 0){
  die "Error:filter code fail, please try again\n";
}
else{
	exit 0;
}

sub scatterFilteFiles{
	my $deep = $_[2];
	my $files = $_[3];
	if(($_[0]<$_[1])&&($deep<$maxdeep)){
		my $mid = int(($_[0]+$_[1])/2);
		defined(my $pid=fork) or &errorHandle($$,"2 Cannot fork:$!");
		unless($pid){
			&scatterFilteFiles($_[0],$mid,$deep+1,$files);
			exit(0);
		}
		else{
			&scatterFilteFiles($mid+1,$_[1],$deep+1,$files);
			waitpid($pid,0);
		}
	}
	else{
#		my $tmpdebugefile = "$tmpdebugefolder\\jobs$$.tmp";
#		open DEBUGEFILE,">$tmpdebugefile" or die "Cannot debuge $tmpdebugefile\n";
#		for($_[0]..$_[1]){
#			my $file = $files->[$_];
#			print DEBUGEFILE $file."\n";
#		}
#		close DEBUGEFILE;
    my $name = $_[0];
		my $tmpFile = ".\\~traverseFile$name.c";
		for($_[0]..$_[1]){
			my $file = $files->[$_];
			chomp $file;
			if (($file =~ /mmi_features\.h/i) && ($not_remove_MTK_INTERNAL_MMI_FEATURES =~ /0/)) {
				&mmi_features_internal($file,$tmpFile);
			}
			if ($file !~ /\.mak/) {
				if ($if_fil eq "TRUE") {
#					print("$file\n");
					if ($file !~ /mmi_features\.h/i)
					{
						system("perl tools\\if_fil.pl $file $en_file $dis_file $tmpFile") and &errorHandle($$,"Error:if_fil fail $file\n");
					}
					else
					{
						system("perl tools\\if_fil.pl $file $en_file_dummy $dis_file $tmpFile") and &errorHandle($$,"Error:if_fil fail $file\n");
					}
					if(-e "$tmpFile"){
					  move("$tmpFile","$file") or move("$tmpFile","$file") or &errorHandle($$,"Error: if_fil can not cover file, please check it is read only or not $file\n");
					}
					#system("move /y $tmpFile $file > nul");
				}
				if ($log_fil eq "TRUE") {
					system("perl tools\\log_fil.pl $file $tmpFile > nul") and &errorHandle($$,"Error:log_fil fail in $file\n");
				}
			}
		}
	}
}

sub errorHandle{
	$threadhandle = $_[0];
	$errorMessage = $_[1];
  open ERRORLOG,">$tmpPath\\error$$.log" or die "Cannot error log $tmpPath\\error$$.log\n";
  print ERRORLOG "ERROR:$threadhandle $errorMessage\n";
  close ERRORLOG;
	die "ERROR:$threadhandle $errorMessage\n";
}

sub errorJudge{
	my @errorlogs = <$tmpPath\\error*.log>;
  if ($#errorlogs >= 0){
    die "ERROR:please check $tmpPath\\error*.log";
  }
	my @tempfiles = <~traverseFile*.c>;
  if ($#tempfiles >= 0){
    die "Error:exist temp file!!!!!\n";
  }
}

sub mmi_features_internal{
	my $file = $_[0];
	my $mmi_tmpfile = $_[1];
	my $writeFile = 1;
	my $inhandle;
	my $outhandle;
	open($inhandle, "<$file") or &errorHandle($$,"1 Cannot open target file $file");
	open($outhandle, ">$mmi_tmpfile") or &errorHandle($$,"2 Cannot open tempfile $mmi_tmpfile");
	while(<$inhandle>){
		if (($_ =~ /ifdef/i) && ($_ =~ /MTK_INTERNAL_MMI_FEATURES/i)) {
			$writeFile = 0;
		}
		if($writeFile == 1) {
			print $outhandle $_;
		}
		if (($_ =~ /endif/i) && ($_ =~ /MTK_INTERNAL_MMI_FEATURES/i)) {
			$writeFile = 1;
		}
	}
	close($outhandle);
	close($inhandle);
	open($inhandle, "<$mmi_tmpfile") or &errorHandle($$,"2 Cannot open tempfile $mmi_tmpfile");
	open($outhandle, ">$file") or &errorHandle($$,"1 Cannot open target file $file");
	while(<$inhandle>){
		print $outhandle $_;
	}
	close($outhandle);
	close($inhandle);
	sleep(1);
}
