#@ARGV[0] in:  card download ini path
#@ARGV[1] out: iot-fota ini path
#@ARGV[2] config: full or mba
use File::Copy;

$skip_line = 0;
$get_resource_type = 0;
$pre_line;

#Read config
open INPUT, '<', @ARGV[2] or die "open failed: $!\n";
foreach $line (<INPUT>)
{
	
	if( !($line =~ m/#/))
	{
		if($line =~ m/PARTIAL_PKG/i && $line =~ m/true/i)
		{
			$partial = true;
		}
		elsif ($line =~ m/COMPRESSED /i && $line =~ m/true/i)
		{
		}		
	}

}

copy(@ARGV[0],@ARGV[1]);

open INPUT, '<', @ARGV[0] or die "open failed: $!\n";
open OUTPUT, '>', @ARGV[1] or die "open failed: $!\n";

foreach $line (<INPUT>)
{
	#skip check
	if($skip_line!="\s" && $skip_line >0)
	{
		$skip_line --;
		next;	
	}
	elsif($line =~ /Base_Directory/i)
	{
		print OUTPUT $line;
		print OUTPUT "ONLY_GEN_CODE_REGION=yes\n";
		print OUTPUT "IOT_ENABLE=yes\n";
		print OUTPUT "NO_CHECK_FAT_RANGE=yes\n";
	}
	elsif($line =~ /Bootloader/i || $line =~ /Ext-Bootloader/i)
	{
		$skip_line=2;
	}
	elsif($partial &&( $line=~ /Primary MAUI/i ||$line=~ /VIVA/i))
	{
		$skip_line=2;
	}
	elsif($line =~ /Resource Bin/i )
	{
		if($line =~ /1/ ){
			print OUTPUT "[LANGUAGE_PACK]\n";
		
		}elsif($line =~ /2/){
			print OUTPUT "[CUSTOM_PACK]\n";
		
		}elsif($line =~ /3/){
			print OUTPUT "[JUMP_TABLE]\n";
		}
	}
	else
	{
		print OUTPUT $line;
	}
	$pre_line = $line;
}


#perl -pi'*' -e s/TRUE/FALSE/g abc.txt