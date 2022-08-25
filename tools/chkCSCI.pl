#!/usr/bin/perl
use strict;

my $ListFile_AP = $ARGV[0];
my $ListFile_Tiny = $ARGV[1];
my $retval = 0;

### Check *.lis exists
if (!((-e $ListFile_AP) && (-e $ListFile_Tiny)))
{
	print "Static CSCI Checking is bypassed: ";
	print "list file(s) for";
	print " AP" unless (-e $ListFile_AP);
	print " and" unless ((-e $ListFile_AP) || (-e $ListFile_Tiny));
	print " Tiny System" unless (-e $ListFile_Tiny);
	print " do" unless  ((-e $ListFile_AP) || (-e $ListFile_Tiny));
	print " does" if  ((-e $ListFile_AP) || (-e $ListFile_Tiny));
	print " NOT exist\n";
	exit;
}

### Parse AP's lis

(my $rhash_size, my $rhash_offset, my $rhash_lib) = parseFile($ListFile_AP);
my %hSize_AP = %$rhash_size;
my %hOffset_AP = %$rhash_offset;
my %hLib_AP = %$rhash_lib;

### Parse Tiny's lis

(my $rhash_size, my $rhash_offset, my $rhash_lib) = parseFile($ListFile_Tiny);
my %hSize_Tiny = %$rhash_size;
my %hOffset_Tiny = %$rhash_offset;
my %hLib_Tiny = %$rhash_lib;

while (my ($key, $value) = each (%hSize_AP)) {
	if (!exists($hSize_Tiny{$key}))
	{
		print "CSCI Error: \"$key\" is defined at AP:$hLib_AP{$key} while undefined at Tiny!\n";
		$retval = 1;
	}
	elsif ($hSize_Tiny{$key} != $value)
	{
		print "CSCI Error: \"$key\" has different sizes! (AP: $value \@$hLib_AP{$key}, Tiny: $hSize_Tiny{$key} \@$hLib_Tiny{$key})\n";
		$retval = 1;
	}
	
	delete $hSize_AP{$key};
	delete $hSize_Tiny{$key};
}

while (my ($key, $value) = each (%hSize_Tiny)) {
	print "CSCI Error: \"$key\" is defined at Tiny:$hLib_Tiny{$key} while undefined at AP!\n";
	$retval = 1;
}

exit($retval) if ($retval);
while (my ($key, $value) = each (%hOffset_AP)) {
	if (exists($hOffset_Tiny{$key}) && $hOffset_Tiny{$key} != $value)
	{
		printf "CSCI Error: \"$key\" has different offsets! (AP: 0x%x, Tiny: 0x%x)\n" ,$value, $hOffset_Tiny{$key};
		$retval = 1;
	}
}

print "Static CSCI Checking Passed\n" unless ($retval);
exit($retval);

############# Subroutines #################
sub parseFile
{		
		my $filename = shift;
		my %_size;
		my %_offset;
		my %_lib;
		
		my $state = 0;
		my $regionBase;
		
    open(FILE, $filename) or die "$!";    
    while (<FILE>) {
        if ($state == 0)
        {
        	if (index($_, "Execution Region CSCI_DATA") >= 0)
        	{
	        	$state = 1;
	        	my @line = split(/,/,substr($_,index($_,"0x")));
	        	$regionBase = hex($line[0]);
					}
        }
        elsif ($state == 1)
        {
        	$state = 2 if (index($_, "Base Addr") >= 0);
        }
        elsif ($state == 2)
        {
        	if (index($_, "csci_static_") >= 0)
        	{
        		$state = 3;
        		my @ll = split(' ',$_);
        		$_size{substr($ll[5],12)} = hex($ll[1]);
        		$_offset{substr($ll[5],12)} = hex($ll[0]) - $regionBase;        		
        		$_lib{substr($ll[5],12)} = $ll[6];
        	}
        }
        elsif ($state ==3)
        {
          if (index($_, "csci_static_") < 0)
          {
             next if (index($_, "PAD") >= 0);
             last;
          }          
        	        	
        	my @ll = split(' ',$_);
        	$_size{substr($ll[5],12)} = hex($ll[1]);
        	$_offset{substr($ll[5],12)} = hex($ll[0]) - $regionBase;
        	$_lib{substr($ll[5],12)} = $ll[6];
        }
    }
    
    return (\%_size, \%_offset, \%_lib);
}


