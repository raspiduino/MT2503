use tools::zImageProcess;

# @ARGV[0] : binary need to compressed
# @ARGV[1] : raw binary backup
# @ARGV[2] : ini

my $binaryContent = @ARGV[0];
my $binaryBackup =  @ARGV[1];
my $decompressStartAddress = 0x00000032;
my $partitions = [{"ratio" => [1], "type" => 0}];

open INPUT, '<', @ARGV[2] or die "open failed: $!\n";
foreach $line (<INPUT>)
{
	
	if( !($line =~ m/#/))
	{
		if($line =~ m/PARTIAL_PKG/i && $line =~ m/true/i)
		{
			
		}
		elsif ($line =~ m/COMPRESSED /i && $line =~ m/true/i)
		{
			$compressed =  true;
		}		
	}

}

if($compressed)
{
	&zImageProcess::CompressByPartitionIOT(
	$binaryContent, 
	$binaryBackup, 
	undef, 
	$decompressStartAddress,
	$partitions
	);

}

