#!/usr/bin/perl -w

#These are configured for the MT2503A
#    print ("log  FOTA_TRACKER :    ARGV[0] : $ARGV[0] \r\n   " );
#    print ("log  FOTA_TRACKER :    ARGV[1] : $ARGV[1] \r\n   " );
#    exit 1;

my $BIN_DIR = "GXQ03D_M2M_11C_PCB01_gprs_MT6261_S00.MAUI_11C_W14_18_IOT_MP_V4_F6.bin";


my $BUILD_DIR = "build\\GXQ03D_M2M_11C";
my $OBJSDIR = "$BUILD_DIR\\gprs\\MT6261o";
my $tracker_bin = "$BUILD_DIR\\Tracker_Bin";

my $tracker_ver = "track\\cust\\cust_inc\\track_version.h" ;

my $track_lib = "$tracker_bin\\lib\\track.lib";
my $track_nvram_lib = "$tracker_bin\\lib\\track_nvram.lib";
my $fota_lib = "track\\mtk_lib\\fota.a";
my $track_axf = "$tracker_bin\\track.axf";
my $track_lis = "$tracker_bin\\track.lis";
my $track_tmp = "tmp";

if(-e $tracker_bin)
{
	system("call rd /s /q $tracker_bin");
#system("del /F /S /Q $tracker_bin")  # 删除旧文件
}
mkdir $tracker_bin;

my $tracker_old_bin = "$BUILD_DIR\\$BIN_DIR";
if(-e $tracker_old_bin)
{
	system("xcopy  /S /E /H /I $BUILD_DIR\\$BIN_DIR  $tracker_bin ");
	#复制下载文件用于编辑修改
	system("xcopy  /S /E /H /I $BUILD_DIR\\$BIN_DIR  $tracker_bin\\$BIN_DIR ");
	#复制一份留底啊，方便以后做对比分析
}
else
{
    die "Can't find BIN files ' $tracker_old_bin ',please remake first !\n" ;
    exit 2;
}


my $mak_file = "make\\GXQ03D_M2M_11C_GPRS.mak";

if(-e $mak_file)
{
    open(FH_SCAT, "<$mak_file");
    @list = <FH_SCAT>;
    close(FH_SCAT);
    for $i(0 .. $#list )
    {
        $line = $list[$i];
        $p1 = index($line , "PROJECT_SUPPORT_TRACK");
        if($p1 > -1)
        {
            $p1 = index($line , "=") + 1;
            $tmp = substr($line, $p1, length($line) - $p1);
            $tmp =~s/^ +//;
            $p1 = index($tmp , " ");
            if($p1 > -1)
            {
                $tmp = substr($tmp, 0, $p1);
            }
            else
            {
                $p1 = index($tmp , "\n");
                if($p1 > -1)
                {
                    $tmp = substr($tmp, 0, $p1);
                }
            }
        }
    }
}
else
{
    die "$mak_file 不存在，请检查！";
    exit 3;
}

my $project_name = "__".$tmp."__";

my $tracker_scat = "track\\Scat_Tracker_$tmp.txt" ;

open(OFH, $tracker_scat) or die "Can't open: $tracker_scat!\n" ;
close(OFH) ;


open(FILE, "<$tracker_ver") or die "Can't open: $tracker_ver!\n" ;
my $record;

my $get_Project = 0;
my $num = 0;
my $i = 0;

while($record = <FILE>)
{
    #$i++;
    #print("file $i: $record\n");

    if((index($record, "#define") < index($record, "//")) or index($record, "//") < 0)
    {

        if($get_Project == 0)
        {
            if(index($record, $project_name) >= 0)
            {
                $get_Project = 1;
                print("get $project_name\n");
                next;
            }
            else
            {
                next;
            }
        }

        if(index($record, "#error") >= 0)
        {
            print "#error end\n" ;
            last;
        }

	# print "decode line string\n" ;

        if(index($record, "#define") >= 0)
        {
            if(index($record, "_TRACK_VER_PARAMETER_") > 0)
            {
                $p1 = rindex($record, " \"");
                #print "$p1 \n";
                $p2 = rindex($record, "\"");
                #print "$p2 \n";
                $VER_PARA = substr($record, $p1 + 2, $p2 - $p1 - 2);
                #print "$VER_PARA \n";
                $num++;
            }

            if(index($record, "_TRACK_VER_BASE_") > 0)
            {
                $p1 = rindex($record, " \"");
                #print "$p1 \n";
                $p2 = rindex($record, "\"");
                #print "$p2 \n";
                $VER_BASE = substr($record, $p1 + 2, $p2 - $p1 - 2);
                #print "$VER_BASE \n";
                $num++;
            }

            if(index($record, "_TRACK_VER_APP_") > 0)
            {
                $p1 = rindex($record, " \"");
                #print "$p1 \n";
                $p2 = rindex($record, "\"");
                #print "$p2 \n";
                $VER_APP = substr($record, $p1 + 2, $p2 - $p1 - 2);
                #print "$VER_APP \n";
                $num++;
            }

            if($num >= 3)
            {
                #print "$project_name deocede over\n" ;
                last;
            }
        }
    }
}

if($get_Project == 0)
{
    die "$tracker_ver can't find $project_name\n" ;
}

if($num != 3)
{
    die "$tracker_ver error\n" ;
}

close(FILE);


system("xcopy  /S /E /H /I $OBJSDIR\\track  $tracker_bin\\track ");
system("xcopy  /S /E /H /I $OBJSDIR\\lib  $tracker_bin\\lib ");


if((-e $track_lib) && (-e $track_nvram_lib) && (-e $fota_lib))
{

    system("armlink   --map --list $track_lis --noscanlib --scatter  $tracker_scat  --output $track_axf  $track_lib(*.obj)  $track_nvram_lib(*.obj)    $fota_lib(*.o) ");

    if(-e $track_axf)
    {
        if(-d $track_tmp)
        {
            system("call rd /s /q $track_tmp");
        }

        $result = system("fromelf $track_axf --bin --output $track_tmp ");
        if($result != 0)
        {
            exit 3;
        }

        if(-d $track_tmp)
        {
            system("copy   $tracker_scat  $tracker_bin ");
            system("copy   $BUILD_DIR\\GXQ61D_M2M_11C_PCB01_gprs_MT6261_S00.lis  $tracker_bin ");
            system("copy   $BUILD_DIR\\GXQ61D_M2M_11C_PCB01_gprs_MT6261_S00.elf  $tracker_bin ");
            system("xcopy  /S /E /H /I $track_tmp  $tracker_bin\\tracker_temp ");
#复制下载文件用于编辑修改
            system("call rd /s /q $track_tmp");

            $result = system("perl tools\\MergeSections.pl $tracker_bin $tracker_scat");
            if($result == 0)
            {
                my $new_bin = "$BUILD_DIR\\$VER_BASE.$VER_APP.$VER_PARA";
                if(-e $new_bin)
                {
# system("DEL /F /A /Q  $new_bin\\*.* ");  # 删除旧文件
# system("rmdir $new_bin");
                    system("call rd /s /q $new_bin");
                }
                rename $tracker_bin, $new_bin;
                my($sec, $min, $hour, $day, $mon, $year, $wday, $yday, $isdst) = localtime();
                my $format_time = sprintf("%02d-%02d-%02d %02d:%02d:%02d", $year + 1900, $mon + 1, $day, $hour, $min, $sec);
                my $new_path = "$BUILD_DIR\\$VER_APP";
                print $format_time, "\n";
#print $new_path, "\n";
#print $new_bin, "\n";
#print $VER_PARA, "\n";

                #system("tools\\crSendDir.exe $new_path $new_bin $VER_PARA");
                #chengjun+fota
                #Note the space symbol,ask clm
                system("tools\\crSendDir.exe $new_path $new_bin {R0:0x0,RW:0xA0000,NVRAM:0xAA000}");	

            }
            else
            {
                die "Error: MergeSections  make failed!!!\n" ;
                exit 1;
            }
        }
    }

}
else
{
    die "Can't find tracker lib !\n" ;
    exit 1;
}










