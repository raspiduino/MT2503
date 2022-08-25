use Win32::Registry;
my %RegType = (
			0 => 'REG_0',
			1 => 'REG_SZ',
			2 => 'REG_EXPAND_SZ',
			3 => 'REG_BINARY',
			4 => 'REG_DWORD',
			5 => 'REG_DWORD_BIG_ENDIAN',
			6 => 'REG_LINK',
			7 => 'REG_MULTI_SZ',
			8 => 'REG_RESOURCE_LIST',
			9 => 'REG_FULL_RESOURCE_DESCRIPTION',
			10 => 'REG_RESSOURCE_REQUIREMENT_MAP');

my $Register_ID1 = "Software\\MICROSOFT\\Devstudio\\6.0\\Tools";


# "Software\\MICROSOFT\\Devstudio\\6.0\\Build System\\Components\\Platforms\\Win32 (x86)\\Directories";

my $Register_Dir = "Software\\MICROSOFT\\Devstudio\\6.0\\Build System\\Components\\Platforms\\Win32 (x86)\\Directories";

my $RegType, $RegValue, $RegKey, $value;
my %values;

my ($hkey, @key_list, $key);

$HKEY_CURRENT_USER->Open($Register_Dir,$hkey) ;

if ( $hkey eq "" )
{
} else
{
  exit 0;
}

$HKEY_CURRENT_USER->Open($Register_ID1,$hkey) ;

if ( $hkey eq "" )
{
  print "Microsoft Visual C++ 6.0 not found !\n";
  exit 0;
}  

$hkey->GetKeys(\@key_list);

#print "$Register_ID1 keys: \n";
foreach $key(@key_list)
{
	print " $key \n";
}

$hkey->GetValues(\%values);

my $tmp="999";
my $tmp2="999";
my $res=999;

foreach $value (keys(%values))
	{
	$RegType 	= $values{$value}->[1];
	$RegValue 	= $values{$value}->[2];
	$RegKey 	= $values{$value}->[0];
	
	if (( $value =~ /InitialDirectory#/  )&& (-d  $RegValue ))
	{
		$tmp =  $RegValue;
		
		
		 $tmp  =~ /([:\w\s\\]+)\\Tools[\w\s\\]*/;
		
		$tmp2 = $1;
		if ( $tmp2 eq "")
		{
		  next;
		}			 		 
		 
		 if (-d $tmp)
		 {
		    $tmp2="$tmp2"."\\MSDev98\\Bin\\MSDev\.com";
		    		    
		    if ( -f "$tmp2")
		    {
		       $res = 999;
		       $res = system($tmp2);
		       if ($res eq 0)
		       {
		       	 last;
		       }	
		       print " res == $res \n";
		      
		    } else
		    {		    
		      print " not -f $tmp2 \n";
		    }  

		 } else 
		 {
		   print " not -d $tmp2 \n";
		 }
	} else { next; }
		
	}


$hkey->Close();
