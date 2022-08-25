#!/usr/bin/perl -w

#  $tempStr = sprintf("MergeSections para:    ARGV[0] : %s \r\n  ", $ARGV[0]  );
#  print $tempStr;
#These are configured for the MT2503A

if( $#ARGV != 1 )
{
    exit 0;    
}

my $Dir_tmp = "$ARGV[0]\\tracker_temp";
my $section_0 = "$ARGV[0]\\TRACK_RO" ;
my $section_1 = "$ARGV[0]\\TRACK_RW" ;
my $section_2 = "$ARGV[0]\\TRACK_NVRAM" ;
my $scat_txt = "$ARGV[1]";

my $Ext = "" ;
my $buffer = "";
$buffer_gfh = "";
my $bufferNull = "\0" ;
my $i =0;
my $n =0;
my $addr_offset=0;

        
open(FH_SCAT, "<$scat_txt") or die "Can't open: $scat_txt!\n" ;
@list = <FH_SCAT>;
close(FH_SCAT);


open(OFH_S0, "+> $section_0");
open(OFH_S1, "+> $section_1");
open(OFH_S2, "+> $section_2");

open(FH, "tools\\GFH_HEADER") or die "Can't open: GFH_HEADER !\n" ;
binmode(FH);        
read(FH, $buffer_gfh, 0x38, 0);
close(FH);
binmode(OFH_S0);
print OFH_S0 $buffer_gfh;
binmode(OFH_S1);
print OFH_S1 $buffer_gfh;
binmode(OFH_S2);
print OFH_S2 $buffer_gfh;    

              
my $addr_begin = 0;  #上一节区地址
    
for $i ( 0 .. $#list )
{
    $file = $list[$i];

    my $p0 ;
    my $p1 ;
    my $p2 ;
    my $p3 ;
    my $rw_file ;
    my $k = 0;
    
        
    if (index( $file ,"RO_ADDR") > -1)
    {
        $p0 = index($file,"RO_ADDR_")+8;
        $p1 = index($file," ") - $p0;
        $ro_file = "";        
        $ro_file = substr($file,$p0,$p1);        
        
        if (index($file,"0x") > -1)
        {
            $p2 = index($file,"0x")+2;
            $p3 = rindex($file,"\n") - $p2;
            $addr_offset = hex(substr($file,$p2,$p3));
        }
        else
        {
            exit 4;
        }
        
        if( $ro_file == 0 )
        {
            $addr_begin = $addr_offset ;
        }
        
        $k = 0;
        while ( $k < ( $addr_offset - $addr_begin ) )
        {
            print OFH_S0 $bufferNull;
            $k++;
        }
        $addr_begin += $k;
   
        
        if( open(FH, "<$Dir_tmp\\RO_$ro_file"))
        {
            $k = tell(OFH_S0);
    #        print  "$k  :  ";
            binmode(FH);        
            read(FH, $buffer, 10000000, 0);
            close(FH);
            binmode(OFH_S0);
            print OFH_S0 $buffer;
            $k = tell(OFH_S0) - $k ;
            $addr_begin = $addr_offset + $k;
    #        print  "$k\n";
        }
        
        if( $ro_file > 65 )
        {
            print  "$addr_begin  - $addr_offset \n";
        }
    }
    
    if (index($file,"RW_ADDR") > -1)
    {       
        $p0 = index($file,"RW_ADDR_")+8;
        $p1 = index($file," ") - $p0;
        $rw_file = substr($file,$p0,$p1);
        
        if (index($file,"0x") > -1)
        {
            $p2 = index($file,"0x")+2;
            $p3 = rindex($file,"\n") - $p2;
            $addr_offset = hex(substr($file,$p2,$p3));
            if( $rw_file == 0 )
            {
                $addr_begin = $addr_offset ;
            }
        }
        else
        {
            exit 4;
        }
                
        if( open(FH, "<$Dir_tmp\\RW_$rw_file"))
        {
            if( $rw_file > 0 )
            {
                $k = 0;
                while ( $k < ( $addr_offset - $addr_begin ) )
                {
                    print OFH_S1 $bufferNull;
                    $k++;
                }
            }
            $k = tell(OFH_S1);

            binmode(FH);        
            read(FH, $buffer, 10000000, 0);
            close(FH);
            binmode(OFH_S1);
            print OFH_S1 $buffer;
            $k = tell(OFH_S1) - $k ;
            $addr_begin = $addr_offset + $k;

        }
          
    }
    
    
    if (index($file,"NVRAM_ADDR_") > -1)
    {        
        if( open(FH, "<$Dir_tmp\\NVRAM_0"))
        {
            binmode(FH);        
            read(FH, $buffer, 10000000, 0);
            close(FH);
            binmode(OFH_S2);
            print OFH_S2 $buffer;    
        }           
    }
}
    
close(OFH_S0) ;
close(OFH_S1) ;
close(OFH_S2) ;



open(OFH_S0, "+< $section_0");
binmode(OFH_S0);
my @array = stat("$section_0");
my $file_len = $array[7];

seek OFH_S0,0x1C,0;
# RO固定加载地址 0x106F0000
#chengjun+fota
print OFH_S0  pack("H*", "00");
print OFH_S0  pack("H*", "00");
print OFH_S0  pack("H*", "6F");
print OFH_S0  pack("H*", "10");
#   ro长度
$outvar = sprintf("%08x", $file_len );
print OFH_S0 pack("H*", substr($outvar,6,2) );
print OFH_S0 pack("H*", substr($outvar,4,2) );
print OFH_S0 pack("H*", substr($outvar,2,2) );
print OFH_S0 pack("H*", substr($outvar,0,2) );
close(OFH_S0);



open(OFH_S1, "+< $section_1");
binmode(OFH_S1);
@array = stat("$section_1");
$file_len = $array[7];

seek OFH_S1,0x1C,0;
# RW固定加载地址 0x10790000
#chengjun+fota
print OFH_S1  pack("H*", "00");
print OFH_S1  pack("H*", "00");
print OFH_S1  pack("H*", "79");
print OFH_S1  pack("H*", "10");
#   RW长度
$outvar = sprintf("%08x", $file_len );
print OFH_S1 pack("H*", substr($outvar,6,2) );
print OFH_S1 pack("H*", substr($outvar,4,2) );
print OFH_S1 pack("H*", substr($outvar,2,2) );
print OFH_S1 pack("H*", substr($outvar,0,2) );

close(OFH_S1) ;


open(OFH_S2, "+< $section_2");
binmode(OFH_S2);
@array = stat("$section_2");
$file_len = $array[7];

seek OFH_S2,0x1C,0;
# NVRAM固定加载地址 0x1079A000
#chengjun+fota
print OFH_S2  pack("H*", "00");
print OFH_S2  pack("H*", "A0");
print OFH_S2  pack("H*", "79");
print OFH_S2  pack("H*", "10");
#   RW长度
$outvar = sprintf("%08x", $file_len );
print OFH_S2 pack("H*", substr($outvar,6,2) );
print OFH_S2 pack("H*", substr($outvar,4,2) );
print OFH_S2 pack("H*", substr($outvar,2,2) );
print OFH_S2 pack("H*", substr($outvar,0,2) );

close(OFH_S2) ;

