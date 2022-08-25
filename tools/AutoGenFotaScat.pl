#!/usr/bin/perl -w


#节区大小修正表，因为有些OBJ在不同项目里面，节区大小差异特别大，为了确保同一个sactter文件可以适应不同的项目

#These are configured for the MT2503A

#103A0000--103F0000--103F500 = 320K+20K
#106F0000--10790000--1079A00 = 620K+40K
#放大RO RW 空间，nvram由12k加大24k在其他地方修改
#chengjun+fota
    
my $Dir_obj = "build\\GXQ03D_M2M_11C\\gprs\\MT6261o\\track" ;  


my $track_lib = "build\\GXQ03D_M2M_11C\\gprs\\MT6261o\\lib\\track.lib";
my $track_nvram_lib = "build\\GXQ03D_M2M_11C\\gprs\\MT6261o\\lib\\track_NVRAM.lib";
my $fota_lib = "track\\mtk_lib\\fota.a";

my $track_axf = "track\\track.axf";
my $tmp_lis = "track\\tmp.lis";
    
my $mak_file = "make\\GXQ03D_M2M_11C_GPRS.mak";

if (-e $mak_file)
{
    open(FH_SCAT, "<$mak_file");
    @list = <FH_SCAT>;
    close(FH_SCAT);
    for $i ( 0 .. $#list )
    {
        $line = $list[$i];
	$p1 = index( $line ,"PROJECT_SUPPORT_TRACK");
	if ( $p1 > -1)
	{
	    $p1 = index( $line ,"=") + 1;
	    $tmp = substr( $line,$p1,length($line)-$p1 );
	    $tmp =~s/^ +//;
	    $p1 = index( $tmp ," ");
	    if ( $p1 > -1 )
	    {
		$tmp = substr( $tmp,0,$p1 );
	    }
	    else
	    {
		$p1 = index( $tmp ,"\n");
		if ( $p1 > -1 )
		{
		    $tmp = substr( $tmp,0,$p1 );
		}	
	    }
	    last;
	}
	
    }
}
else
{
    die "$mak_file 不存在，请检查！";
    exit 3;
}

my $tracker_scat = "track\\Scat_Tracker_$tmp.txt" ;


if ((-e $track_lib) && (-e $track_nvram_lib) && (-e $fota_lib) )
{	
    system("armlink   --info sizes --list $tmp_lis  --nodebug --noscanlib   --output $track_axf  $track_lib(*.obj)  $track_nvram_lib(*.obj)    $fota_lib(*.o) ");       
}
		
			   
if ((-e $track_lib) && (-e $track_nvram_lib) && (-e $fota_lib) )
{	
    system("armlink   --info sizes --list $tmp_lis  --nodebug --noscanlib   --output $track_axf  $track_lib(*.obj)  $track_nvram_lib(*.obj)    $fota_lib(*.o) ");       
}
else
{
    exit 2;
}

if ((-e $track_axf) && (-e $tmp_lis) )
{	
      
}
else
{
    exit 2; #生成scat文件失败
}



#读取临时编译lis文件，分析每个obj的节区大小
open(FH_LIS, "<$tmp_lis") or die "Can't open: $tmp_lis!\n" ;
@list = <FH_LIS>;
foreach my $line(@list)   #循环读取每一行的文本
{
    chomp $line;
    if( rindex($line,".obj") > 1) 
    {
        @tmp = split/\s+/,$line;
	$tmp[6] = $tmp[1] + $tmp[3];
        push @AoA,[ @tmp ];
    }
}



@ro_array = sort { $a->[7] cmp $b->[7]  } @AoA;
@rw_array = sort { $b->[4] <=> $a->[4]  } @AoA;
@zi_array = sort { $b->[5] <=> $a->[5]  } @AoA;


close(FH_LIS);

	#chengjun+fota DISK1起始地址
	my $adr_ro_load = 0x106F0038;     

	my $Ext = "obj" ;
	my $i = 0;
    
    
	open(OFH, "+>$tracker_scat") or die "Can't open: $tracker_scat!\n" ;
	#文件标识头
	print OFH (";Add by MagicNing for RAW_DISK  & FOTA\n");
	print OFH (";\n");  
	print OFH (";v1.0   2014-10-14,  MagicNing create this file\n");
	print OFH (";v1.1   2014-11-04,  MagicNing 分离RO,RW,ZI 节区  \n");
	print OFH (";-------------------------------------------------------------------\n");
	print OFH (";\n");
	print OFH (";\n");  
	print OFH (";\n");
	   
	
        #加载的函数指针数组
	$string = sprintf("0x%x", $adr_ro_load );	
	print OFH ("RO_ADDR_$i $string\n");
	print OFH ("{\n");
	print OFH ("    RO_$i +0\n"); #子节区偏移不用十六进制表示，是为了和存储地址偏移区分开来，方便MergeSections.pl拼接合并bin
	$i++;
	print OFH ("    {\n");
	print OFH ("        *    ( TRACK_F_CODE, +First )\n");
	print OFH ("    }\n");
	print OFH ("}\n");
	print OFH ("\n");
	
	#chengjun+fota  不认识
	$adr_ro_load = 0x106F0C00;
	$string = sprintf("0x%x", $adr_ro_load );
	#FOTA.a的函数
	print OFH ("RO_ADDR_$i $string\n");
	print OFH ("{\n");
	print OFH ("    RO_$i +0\n");
	$i++;
	print OFH ("    {\n");
	print OFH ("        *fota.a    ( +RO,+text )\n");
	print OFH ("    }\n");
	print OFH ("}\n");
	print OFH ("\n");           
        	
	$adr_ro_load = $adr_ro_load + 0x1C00;
        
	$ro_size = 0 ;
        for $n ( 0 .. $#ro_array )
	{
	    if ( $ro_array[$n][6] > 0 )
	    {	
		if ( $ro_size == 0 )
		{
		    $string = sprintf("0x%x", $adr_ro_load );
		    #添加每个obj的RO区域
		    print OFH ("RO_ADDR_$i $string\n");
		    print OFH ("{\n");
		    print OFH ("    RO_$i +0\n");
		    $i++;
		    print OFH ("    {\n");
		}
    
		print OFH ("        $ro_array[$n][7]  ( +RO,+text )\n");
		$ro_size += $ro_array[$n][6];
			
		if ( ($ro_size >= 0x10 ) ||  ($n == $#ro_array) )
		{
		    print OFH ("    }\n");
		    print OFH ("}\n");
		    print OFH ("\n");
		    
		    $ro_size = $ro_size + 0x40 - ($ro_size % 0x20 ) ;
		    $adr_ro_load += $ro_size;	    
		    $ro_size = 0;
		}
	    }
	    else
	    {
		$string = sprintf("0x%x", $adr_ro_load );
		#添加每个obj的RO区域
		print OFH ("RO_ADDR_$i $string\n");
		print OFH ("{\n");
		print OFH ("    RO_$i +0\n");
		$i++;
		print OFH ("    {\n");
		
		for $a ( $n .. $#ro_array )
		{
		    print OFH ("        $ro_array[$a][7]  ( +RO,+text )\n");
		    $ro_size += $ro_array[$a][6];
		}
		
		print OFH ("    }\n");
		print OFH ("}\n");
		print OFH ("\n");
		
		if ( $ro_size > 0)
		{
		    die "数组排序错误，有非0数据排在末端!";
		    exit 2;
		}		
		$adr_ro_load = $adr_ro_load + 0x800;		
	    }
	}
	
        $i = 0;	
	
	#chengjun+fota
	my $adr_rw_load = 0x10790038;
	my $adr_rw_exet = 0x00200000;
	$rw_size = 0 ;
        for $n ( 0 .. $#rw_array )
	{
	    if ( $rw_array[$n][4] > 0 )
	    {	
		if ( $rw_size == 0 )
		{
		    $string = sprintf("0x%x", $adr_rw_load );
	            $string2 = sprintf("0x%x", $adr_rw_exet );	
		    #添加每个obj的RW区域
		    print OFH ("RW_ADDR_$i $string\n");
		    print OFH ("{\n");
		    print OFH ("    RW_$i $string2\n");
		    $i++;
		    print OFH ("    {\n");		    
		    $a = 0;			
		}

		print OFH ("        $rw_array[$n][7]  ( +RW, +DATA )\n");
		$rw_size += $rw_array[$n][4];
		$a++;
					
		if ( ($rw_size >= 0x80 ) ||  ($n == $#rw_array) || ($a >= 2 ) )
		{
		    print OFH ("    }\n");
		    print OFH ("}\n");
		    print OFH ("\n");
		    		    
		    $rw_size = $rw_size + 0x180 - ($rw_size % 0x100 ) ;
		    $adr_rw_load += $rw_size;
		    $adr_rw_exet += $rw_size;   #特别注意，RW的原始数据需要保存的在加载域的 	    
		    $rw_size = 0;
		}
	    }
	    else
	    {
		if( $rw_size > 0 )
		{
		    print OFH ("    }\n");
		    print OFH ("}\n");
		    print OFH ("\n");
		    
		    $rw_size = $rw_size + 0x100 - ($rw_size % 0x80 ) ;
		    $adr_rw_load += $rw_size;
		    $adr_rw_exet += $rw_size;   #特别注意，RW的原始数据需要保存的在加载域的 		    
		    $rw_size = 0;
		}
		for $a ( $n .. $#rw_array )
		{
		    if ( ($a == $n) || ( ( $a % 4 ) == 0 ) )
		    {
			$string = sprintf("0x%x", $adr_rw_load );
			$string2 = sprintf("0x%x", $adr_rw_exet );	
			#添加每个obj的RW区域
			print OFH ("RW_ADDR_$i $string\n");
			print OFH ("{\n");
			print OFH ("    RW_$i $string2\n");
			$i++;
			print OFH ("    {\n");
		    }		    
		    print OFH ("        $rw_array[$a][7]  ( +RW, +DATA )\n");
		    $rw_size += $rw_array[$a][4];
		    $adr_rw_load = $adr_rw_load + 0x40;
		    $adr_rw_exet = $adr_rw_exet + 0x40;
		    if ( $rw_size > 0)
		    {
			die "数组排序错误，有非0数据排在末端!";
			exit 2;
		    }	
		    if ( ( $a == $#rw_array ) || ( ( $a % 4 ) == 3 )  )
		    {
			print OFH ("    }\n");
			print OFH ("}\n");
			print OFH ("\n");
		    }	
		}	
		last;
	    }
	}
	
	#chengjun+fota
	if ( ( $adr_rw_load + 0x100 ) > 0x10799FFF )
	{
	    die "RW  节区超出长度了，需要修改！！";
	    exit 3;
	}

	#chengjun+fota
	$adr_rw_exet = $adr_rw_exet + 0x10799F00 - $adr_rw_load ;
	$adr_rw_load = 0x10799F00;
	$string = sprintf("0x%x", $adr_rw_load );
	$string2 = sprintf("0x%x", $adr_rw_exet );
	#这个区域是卡位置用的，避免内存溢出	      
	print OFH ("RW_ADDR_$i $string\n");
	print OFH ("{\n");
	print OFH ("    RW_$i  $string2\n");
	$i++;
	print OFH ("    {\n");
	print OFH ("        *fota.a  ( +RW, +DATA, +ZI, +BSS )\n");
	print OFH ("    }\n");
	print OFH ("}\n");
	print OFH ("\n");	
	
                  
        $i = 0;
	$adr_rw_exet = $adr_rw_exet + 0x1000 - ($adr_rw_exet % 0x1000 );
	        
	$zi_size = 0 ;
        for $n ( 0 .. $#zi_array )
	{
	    $string = sprintf("0x%x", $adr_rw_exet );
	    #添加每个obj的ZI区域
	    print OFH ("ZI_ADDR_$i $string\n");
	    print OFH ("{\n");
	    print OFH ("    ZI_$i $string\n");
	    $i++;
	    print OFH ("    {\n");		
	    print OFH ("        $zi_array[$n][7]  ( +ZI, +BSS )\n");
	    $zi_size = $zi_array[$n][5] ;
	    print OFH ("    }\n");
	    print OFH ("}\n");
	    print OFH ("\n");
	    
	    
	    if ( $zi_size > 0 )
	    {
		$adr_rw_exet +=  $zi_size + 0x300 - ($zi_size % 0x200 ) ;
	    }
	    else
	    {
		$adr_rw_exet +=   0x200  ;
	    }
	}
	
		
	if ( ( $adr_rw_exet + 0x100 ) > 0x00300000 )
	{
	    die "ZI  节区超出长度了，需要修改！！";
	    exit 3;
	}
	
	#ZI 结束节区  占位置
	$adr_rw_exet = 0x002FFF00  ;
	$string2 = sprintf("0x%x", $adr_rw_exet );
	#这个区域是卡位置用的，避免内存溢出	      
	print OFH ("ZI_ADDR_$i $string2\n");
	print OFH ("{\n");
	print OFH ("    ZI_$i  $string2\n");
	$i++;
	print OFH ("    {\n");
	print OFH ("        *  ( NONE_OBJ )\n");
	print OFH ("    }\n");
	print OFH ("}\n");
	print OFH ("\n");
	
	
	#chengjun+fota
	#加载的NVRAM区域
	print OFH ("NVRAM_ADDR_0 0x1079A038\n");
	print OFH ("{\n");
	print OFH ("    NVRAM_0 +0\n");
	print OFH ("    {\n");
	print OFH ("        *      (TRACK_NVRAM_RODATA)\n");
	print OFH ("    }\n");
	print OFH ("}\n");
	print OFH ("\n");
		
	close(OFH) ;
        
	system("DEL /F /A /Q  $track_axf ") ;
	system("DEL /F /A /Q  $tmp_lis ") ;
	
exit 0;

