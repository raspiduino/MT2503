my $folder_path = $ARGV[0];
my $file_postfix = $ARGV[1];
my $output = $ARGV[2];

opendir (DIR, $folder_path) or die "no folder : $folder_path";
@files = grep {/.+_GFH/i}  readdir DIR;
close DIR;

open (FILE, ">$output") or die "cannot open $output";
foreach (@files)
{
	$ori_name = $_;
	$_ =~ s/_GFH//i;
	system("rename $folder_path\\$ori_name $_");
	print FILE "$folder_path\\$_\n";
}
close FILE;