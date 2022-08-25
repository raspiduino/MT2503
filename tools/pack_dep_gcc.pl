use strict;

if ($#ARGV != 2)
{
	print "pack_dep_gcc.pl output_filename dep_input_dir src_input_dir\n";
	die "DIE\n";
}


my $fileOut = shift @ARGV;
my $depDir = shift @ARGV;
my $curDir = shift @ARGV;

my $depContent;
opendir DIRHANDLE, "$depDir" or die "Cannot open dir $depDir: $!";
foreach my $file (readdir DIRHANDLE)
{
	next if (($file eq ".") || ($file eq ".."));
	if ($file =~ /\.d$/i)
	{
		ParseDep(\$depContent, "$depDir\\$file");
	}
}
closedir DIRHANDLE;

open OUTPUTHANDLE, ">$fileOut" or die "Cannot write $fileOut\n";
print OUTPUTHANDLE "$depContent";
close OUTPUTHANDLE;

sub ParseDep
{
	my $refContent = shift @_;
	my $fileInput = shift @_;
	my $Backup = $/;
	undef $/;
	open INPUTHANDLE, "<$fileInput" or die "Cannot open file $fileInput\n";
	my $fileContent = <INPUTHANDLE>;
	close INPUTHANDLE;
	$/ = $Backup;
	$fileContent =~ s/\\\n//gs;
	$fileContent =~ s/\//\\/gs;
	my @fileList = split(/\s+/, $fileContent);
	$fileList[0] =~ s/(\S*\\)?(\S+?)\.(o|obj)\:/$2.obj\:/i;
	$$refContent .= $fileList[0];
	my $index;
	for($index=1; $index <= $#fileList; $index++)
	{
		my $line = "	$curDir\\" . $fileList[$index];
		if ($index < $#fileList)
		{
			$$refContent .= "$line \\\n";
		}
		else
		{
			$$refContent .= "$line\n";
		}
	}
}
