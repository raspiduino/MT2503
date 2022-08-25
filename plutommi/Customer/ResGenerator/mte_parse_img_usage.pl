#
# MTE image resource header file generator
#
open(INFILE, "<.\\debug\\image_resource_usage.txt") or die "Cannot open image_resource_usage.txt!";
open(OUTFILE, ">..\\CustResource\\mte_img_resource.h") or die "Cannot open mte_img_resource.h!";

%image_resource_hash = ();

$backslash_warn = 0;
$warning_msg = "Please make sure the number of consecutive backslashes is EVEN.\n[ID]   [PATH]\n";

$count = 0;
$total_size = 0;

$content = "
typedef struct
{
    S32 id;
    S32 size;
    S8* path;
} mmi_mte_img_resource_struct;

static const mmi_mte_img_resource_struct g_mmi_mte_img_resource[] =
{
";

$l = <INFILE>;    # skip the first line cotaning only column names
while ($l = <INFILE>)
{
    chomp($l);    
    @v = split(/\t/, $l);

    ($id, $name, $size, $file_path) = @v[2..5];

    $file_path =~ /^\.\.\\\\\.\.\\\\Customer\\\\Images\\\\(.*)/i;    
    $file_path = $1;

    # warnings on even backslashes
    while ($file_path =~ /(\\+)/g)
    {
       if (length($1) & 1)
       {
           $backslash_warn++;
           $warning_msg .="$backslash_warn: $name $file_path\n";
           last;
       }
    }

    if ($file_path eq "")
    {
        $file_path = "NULL";
    }
    else
    {
        $file_path = '"'.$file_path.'"';                       
    }

    if ($image_resource_hash{$file_path})
    {   # only count 1 duped image
        $size = -$size;
        $image_resource_hash{$file_path}++;       
    }
    else
    {
        $image_resource_hash{$file_path} = 1;                
        $total_size += $size;
    }

    $content .= "{$id, $size, $file_path}, // $name\n";
    $count++;
}

# output mte resource header file
print OUTFILE "//\n// DO NOT MODIFY THIS FILE!!!\n//\n\n";
print OUTFILE "#define MMI_MTE_SYSTEM_IMAGE_RESOURCE_SIZE $total_size\n";
print OUTFILE "#define MMI_MTE_SYSTEM_IMAGE_RESOURCE_NUM $count\n";
print OUTFILE $content;
print OUTFILE "};\n\n";

close(OUTFILE);
close(INFILE);

print $warning_msg."\n" if $backslash_warn;

# copy convert.exe to modis directory for MTE usage
`copy convert.exe ..\\..\\..\\modis\\modis\\debug`;
`copy convert.exe ..\\..\\..\\modis\\modis\\release`;
