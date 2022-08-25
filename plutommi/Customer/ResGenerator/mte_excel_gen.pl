use File::Copy;

#
# Open MTE theme data 
#

if ($#ARGV != 2)
{
	die "Usage: mte_excel_gen.pl output input verno\n";
}

my $output = shift @ARGV;
my $input = shift @ARGV;
my $verno = shift @ARGV;


#open(INFILE, "<MMI_theme_file.xls") or die "Cannot open MMI_theme_file.xls!";
open(OUTFILE, ">$output") or die "Cannot write $output!";

use Cwd;


#
# THEME EXCEL TO MTE DATA CONVETOR
#
use Win32::OLE qw(in with);
use Win32::OLE::Const 'Microsoft Excel';
use Win32::OLE::Variant;
use Win32::OLE::NLS qw(:LOCALE :DATE);

Win32::OLE->Option(CP => Win32::OLE::CP_UTF8);
use Encode qw/encode decode/; 

$Win32::OLE::Warn = 3; # Die on Errors.

my $dir = getcwd();
$dir =~ s/\//\\/g;
$dir .= "\\$input";
my $curr_time_str = &get_CurrTime_str();
$dir =~ s/\.xls$//i;
$dir .= "_" . $curr_time_str . $$ . ".xls";
$dir =~ s/\\\\/\\/g;
copy($input, $dir) or die "[Error] fail to copy from $input to $dir\n";
#
# Record Verno Info
#
my $verno_string = "//\n// Verno Information of mte_data.h.\n//\n";
print OUTFILE $verno_string;
print OUTFILE "//".$verno."\n";



#
# constants
#
my $start_row = 2; # START ROW INDEX FOR THE REAL DATA START

my $LCD_DIMENSION_NUM = 8;  # MUST SYNC WITH MTEGPROT.H
# ::Warn = 2; throws the errors, but #
# expects that the programmer deals  #



my %theme_component_type = (
"color" =>    "MMI_MTE_THEME_DATA_TYPE_COLOR",
"border_color" =>    "MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR",
"UI_filled_area" => "MMI_MTE_THEME_DATA_TYPE_FILLER",
"PU8" => "MMI_MTE_THEME_DATA_TYPE_IMAGE",
"UI_font_type" => "MMI_MTE_THEME_DATA_TYPE_FONT",
"S32" => "MMI_MTE_THEME_DATA_TYPE_INTEGER",
"SYMBOL" => "MMI_MTE_THEME_DATA_TYPE_SYMBOL");

@dm_group_name = qw(DM_BASE_LAYER_START DM_BASE_LAYER_END DM_NEW_LAYER_START DM_NEW_LAYER_END DM_SCR_BG DM_BASE_CONTROL_SET1 DM_BASE_CONTROL_SET2 DM_BASE_CONTROL_SET_SUBMENU DM_BASE_CONTROL_SET_COMMON DM_CIRCULAR_MENU1 DM_LIST1 DM_ROTATE_MENU1 DM_INLINE_FIXED_LIST1 DM_MATRIX_MENU1 DM_DYNAMIC_LIST1 DM_DYNAMIC_MATRIX1 DM_ASYNCDYNAMIC_LIST1 DM_ASYNCDYNAMIC_MATRIX1 DM_SINGLELINE_INPUTBOX1 DM_MULTILINE_INPUTBOX1 DM_EMS_INPUTBOX1 DM_DIALER_INPUT_BOX1 DM_TAB_CONTROL DM_HORIZONTAL_TAB_BAR DM_DATE_TIME_DISPLAY DM_TITLE1 DM_STATUS_BAR1 DM_LSK DM_RSK DM_CSK DM_BUTTON_BAR1 DM_BUTTON DM_CALENDAR DM_ALIGNED_AREA_START DM_ALIGNED_AREA_END DM_STRING DM_IMAGE DM_BACK_FILL_AREA DM_RECTANGLE DM_LINE DM_SLIDE_CONTROL DM_CATEGORY_CONTROLLED_AREA DM_CATEGORY_CONTROLLED_AREA2 DM_POPUP_BACKGROUND DM_NWAY_STOPWATCH DM_TYPICAL_STOPWATCH DM_WALL_PAPER DM_SCROLL_TEXT DM_PERCENTAGE_BAR DM_PANEL DM_ICON_BAR);

for ($i = 0; $i <= $#dm_group_name; $i++)
{
    #$dm_group_name[$i] = chomp($dm_group_name[$i]);
    #print ">>$dm_group_name[$i]\n";
    $dm_groups{$dm_group_name[$i]} = 0;
}

my %dm_result = ();

#typedef enum
#{
#    MMI_MTE_IMAGE_NONE = 0,
#    MMI_MTE_IMAGE_GIF = 1 << 0,
#    MMI_MTE_IMAGE_JPG = 1 << 1,
#    MMI_MTE_IMAGE_BMP = 1 << 2,
#    MMI_MTE_IMAGE_PNG = 1 << 3,         // Standard PNG format (only allowed after MT6238)
#    MMI_MTE_IMAGE_BMP_TO_ABM = 1 << 4,  // BMP files will be converted to ABM internally.
#    MMI_MTE_IMAGE_PNG_TO_ABM = 1 << 5   // PNG files will be converted to ABM internally.
#} mmi_mte_image_enum;

my %img_type = (
"GIF" => "MMI_MTE_IMAGE_GIF",
"JPG" => "MMI_MTE_IMAGE_JPG",
"BMP" => "MMI_MTE_IMAGE_BMP",
"PNG" => "MMI_MTE_IMAGE_PNG",
"BMP_SEQ" => "MMI_MTE_IMAGE_BMP_SEQUENCE",
"JPG_SEQ" => "MMI_MTE_IMAGE_JPG_SEQUENCE",
"PNG_SEQ" => "MMI_MTE_IMAGE_PNG_SEQUENCE",
"9Slice" => "MMI_MTE_IMAGE_9SLICE"
);

my %theme_component_group = ();


$group_count = 0;


#while ($l = <FILE>)
#{            
#    #print "    {\"$name\", $count, $group_id, $type, L\"$name\", 1, $sub_lcd, {$theme_data_offset, $img_flag}},\n";
#    
#    $tc .= "    {\"$name\", $count, $group_id, $type, NULL, 1, $sub_lcd, {$theme_data_offset, $img_flag}},\n";
#    
#    $name =~ s/_/ /g;
#    
#    $t_desc .= "    L\"$name\",\n";
#    
#    $count++;
#}


#print "\nTOTAL $count GC $group_count\n";
#print $f;




#typedef struct
#{
#    char *name;                         // component name in ASCII
#    unsigned int id;                    // component ID
#    unsigned int group_id;              // component group id
#    mmi_mte_theme_data_type_enum type;  // component data type
#    char *description;                  // component detail description in Unicode
#    int allow_editing;                  // component allow editing in [Screen 5]
#    mmi_mte_lcd_type_enum lcd_type;     // component LCD type
#    mmi_mte_theme_component_internal_struct internal_data;	// not accessed by MTE directly
#} mmi_mte_theme_component_struct;

my $excelfile = $dir;

my $Excel = Win32::OLE->new('Excel.Application', 'Quit');

#$Excel->{DisplayAlerts}=0;   

my $Book = $Excel->Workbooks->Open($excelfile);   

#
# Theme component
#
my $Sheet = $Book->Worksheets("Theme");
$Sheet->Activate();   


# GET ALL THEME DATA
$theme_count = 0;

$name = $Sheet->Range("B".$start_row)->{Value}; 

$tc = "/* theme component info structure */\n";
$tc .= "static mmi_mte_theme_component_struct g_mmi_mte_theme_component_info[MMI_MTE_THEME_COMPONENT_NUM] =\n{\n";

$t_desc = "/* theme component English description */\n";
$t_desc .= "static const wchar_t *g_mmi_mte_theme_component_description_EN[MMI_MTE_THEME_COMPONENT_NUM] =\n{\n";

$t_desc_gb = "/* theme component GB description */\n";
$t_desc_gb .= "static const wchar_t *g_mmi_mte_theme_component_description_GB[MMI_MTE_THEME_COMPONENT_NUM] =\n{\n";

$category_id_filter = "";

while ($name ne "")
{    
    $name = $Sheet->Range("B".$start_row)->{Value};       
    $type = $Sheet->Range("C".$start_row)->{Value}; 
    $group_name = $Sheet->Range("D".$start_row)->{Value}; 
    $desc = $Sheet->Range("E".$start_row)->{Value}; 
    $desc_gb = $Sheet->Range("F".$start_row)->{Value}; 
    $editable = $Sheet->Range("G".$start_row)->{Value}; 
    $version = $Sheet->Range("I".$start_row)->{Value}; 
    $img_format = $Sheet->Range("J".$start_row)->{Value}; 
    $allow_null_filler = $Sheet->Range("Y".$start_row)->{Value}; 
    $in_categories = $Sheet->Range("Z".$start_row)->{Value}; 
    $allow_border_filler = $Sheet->Range("AA".$start_row)->{Value}; 
    
    for ($i = 0; $i < $LCD_DIMENSION_NUM; $i++)
    {
        $colum_index = ord("K") + $i;        
        $img_dimension[$i] = $Sheet->Range(chr($colum_index).$start_row)->{Value}; 
    }
    
    $cat_filter = "NULL";
    
    # save category filter structure
    if ($in_categories ne "")
    {
        $temp = $in_categories;
        $temp =~ s/ //g;
        @temps = split(/\,/, $temp);
        $cat_count = $#temps + 1;
        $temp = join(", ", @temps);
        $temp .= ", -1";
        $cat_filter = "mmi_mte_category_filter_$theme_count";
        $category_id_filter .= "static S32 $cat_filter"."[] = {$temp};\n";        
    }
    
    
    $dm_group = $Sheet->Range("S".$start_row)->{Value}; 
    $dependency = $Sheet->Range("T".$start_row)->{Value}; 
    $symbol_name = $Sheet->Range("U".$start_row)->{Value}; 
    $theme_index =  $Sheet->Range("V".$start_row)->{Value}; 

    $value_range =  $Sheet->Range("X".$start_row)->{Value}; 

################# IGNORE 07B ##################
#    if ($version eq "07B")
#    {
#        #next;
#        $start_row++;
#        next;
#    }
###############################################

    $group_id = -1;


    if ($desc eq "OBSOLETE")
    {
        $obsolete = 1;
        $editable = 0;
    }
    else
    {
        $obsolete = 0;
    }
    
    # trim name
    $name =~ s/[ \t\r\n]//g;

    if ($name eq "")
    {
        last;
    }
    
        
    if ($name =~ /sub_lcd/)
    {
        $sub_lcd = 1;
    }
    else
    {
        $sub_lcd = 0;
    }
    

    $type = $theme_component_type{$type};

    if ($obsolete == 0)
    {
        $group_id = $theme_component_group{$group_name};
        if (!defined($group_id))
        {
            $theme_component_group{$group_name} = $group_count;
            $group_id = $group_count;
            $group_count++;
        }
    }

    $theme_data_offset = $theme_index * 4;    
    
    #print ">>>>$count $name $type GN $group_name GI $group_id\n";       
    #print $name."\n";
    
    if ($obsolete == 1)
    {
        $desc = "";
        $desc_gb = "";
    }
    
    # $img_flag = 0;
    
    if ($img_format eq "")
    {
        $img_flag = 0;
        $img_dim = "{0}";
    }
    else
    {        
        
        $recommend_image_type = "";
        
        $img_flag = $img_format;
        $img_flag =~ s/ //g;
        @img_format = split(/,/, $img_flag);                
        
        $img_flag = "";
        $c = 0;
        foreach $i (@img_format)
        {
            $rec = substr($i, 0, 1);
            
            if ($rec eq "*")
            {
                $i = substr($i, 1);
                $recommend_image_type = $img_type{$i};                
            }            
            
            $img_flag .= $img_type{$i};
                                   
            if ($c < $#img_format)
            {
                $img_flag .= " | ";
            }            
            
            $c++;
        }
        
        if ($recommend_image_type ne "")
        {
            $img_flag .= " | ($recommend_image_type << 16)";
        }                
        
        # image dimension
        $img_dim = "{";
        for ($i = 0; $i < $LCD_DIMENSION_NUM; $i++)
        {
            $dim = $img_dimension[$i];
            $dim =~ s/ //g;
            
            if (($dim eq "") || ($dim eq "TBD"))
            {
                $img_dim .= "{0, 0}, ";
            }
            else
            {   
                $dim =~ s/MENUITEM_WIDTH/LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH/g;
                

                if ($dim =~ /(\d+)[xX](\d+)/)
                {
                    $w = $1;
                    $h = $2;
                }
                else
                {
                    ($w, $h) = split(/x/, $dim);
                }               
                
                $img_dim .= "{$w, $h}, ";
            }
        }
        $img_dim .= "}";
    }     
    
    # only count in DM group if it is not obsolete
    if (($obsolete == 0) && ($dm_group ne ""))
    {
        $dm_group =~ s/ //g;
        @dg = split(/,/, $dm_group);
        foreach $d (@dg)
        {
            if (defined($dm_groups{$d}))
            {
                $dm_groups{$d}++;
                $dm_result{$d} .= $theme_count.", ";
            }
        }
    }
    
    $component_hash{$name} = $theme_count;
    
    if ($value_range eq "")
    {
        $value_range = "0, 0";
        
        if ($type eq "MMI_MTE_THEME_DATA_TYPE_INTEGER")
        {
            die "$name VALUE RANGE IS NOT DEFINED!\n";
        }
    }
    else
    {
        $value_range =~ s/ //g;
        $value_range =~ /\[(.+),(.+)\]/;
        
        $value_range = "$1, $2";
    }
    
    #
    # filler flag
    #
    @filler_flags = ();
    if ($allow_null_filler == 1)
    {
        push(@filler_flags, "MMI_MTE_FILLER_ALLOW_NULL");
    }
    if ($allow_border_filler == 1)
    {
        push(@filler_flags, "MMI_MTE_FILLER_ALLOW_BORDER");
    }
    
    if ($#filler_flags >= 0)
    {
        $filler_flag = join(" | ", @filler_flags);
    }
    else
    {
        $filler_flag = "0";
    }
    
    
    if (($dependency ne "") && ($editable eq "1"))
    {   #dependency theme component
        $if_macro = $dependency;
        
        $if_macro =~ s/([A-Z0-9_]+)/defined\($1\)/g;
            
        $tc .= "#if $if_macro\n";
        $tc .= "    {\"$name\", $theme_count, $group_id, $type, NULL, $editable, $sub_lcd, $value_range, $filler_flag, {$theme_data_offset, $img_flag, \"$symbol_name\", $img_dim, $cat_filter}},\n";    
        $tc .= "#else\n";
        # non editable
        $img_dim = "{0}";
        $tc .= "    {\"$name\", $theme_count, $group_id, $type, NULL, 0, $sub_lcd, $value_range, $filler_flag, {$theme_data_offset, $img_flag, \"$symbol_name\", $img_dim, $cat_filter}},\n";    
        $tc .= "#endif\n";              
        #print $if_macro."\n";
        #exit;
    }
    else
    {
        $tc .= "    {\"$name\", $theme_count, $group_id, $type, NULL, $editable, $sub_lcd, $value_range, $filler_flag, {$theme_data_offset, $img_flag, \"$symbol_name\", $img_dim, $cat_filter}},\n";    
    }
    
    $t_desc .= "    L\"$desc\",\n";   
    
    
    # $desc_gb = Encode::decode("gb2312", $desc_gb);
    #print ">>>".length($desc_gb)."\n";
    
    $t_desc_gb .= "    L\"";    
    $ucs2 = encode("UCS-2LE", $desc_gb);
    #print ">>>$ucs2\n";
    for ($i = 0; $i < length($ucs2); $i += 2)
    {        
        $t_desc_gb .= sprintf("\\x%02X%02X", ord(substr($ucs2, $i + 1, 1)), ord(substr($ucs2, $i, 1)));
    }
    
    $t_desc_gb .= "\",\n";
    
    #$t_desc_gb .= "    L\"$desc_gb \",\n";
    #$pp = join(', ', unpack("H*",$desc_gb)); 
    #print ">>$pp\n";
    
    $theme_count++;
    $start_row++;
        
} 

#exit;


$t_desc .= "};\n";
$t_desc_gb .= "};\n";
$tc .= "};\n";

#$group_count--; # compensate for OBSOLETE group
print OUTFILE "//\n// DO NOT MODIFY ME!!!\n//\n\n";

print OUTFILE "#define\tMMI_MTE_THEME_COMPONENT_NUM\t$theme_count\n";
print OUTFILE "#define\tMMI_MTE_THEME_COMPONENT_GROUP_NUM\t$group_count\n\n";

print OUTFILE "
typedef struct
{
    unsigned int num;
    int component_id[MMI_MTE_THEME_COMPONENT_NUM];    
} mmi_mte_control_set_group_struct;

typedef struct
{
    unsigned int num;
    int dm_group_id[DM_CONTROL_TOTAL];
} mmi_mte_control_set_discard_dm_struct;

typedef struct
{
    int   screen_id;
    int   category_id;
    mmi_mte_control_set_group_struct component_set;
    mmi_mte_control_set_discard_dm_struct discard_dm;
} mmi_mte_current_screen_filter_struct;
\n\n";

print OUTFILE $category_id_filter."\n\n";


print OUTFILE $tc;

print OUTFILE "\n\n";
print OUTFILE $t_desc;
print OUTFILE "\n\n";
print OUTFILE $t_desc_gb;
print OUTFILE "\n\n";


#
# example screen
#
my $Sheet = $Book->Worksheets("Example Screen");
$Sheet->Activate();

$es = "/* English example screen name */\n";
$es .= "static const wchar_t *g_mmi_mte_example_screen_name_EN[MMI_MTE_EXAMPLE_SCREEN_NUM] =\n{\n"; 

$es_gb = "/* GB example screen name */\n";
$es_gb .= "static const wchar_t *g_mmi_mte_example_screen_name_GB[MMI_MTE_EXAMPLE_SCREEN_NUM] =\n{\n"; 

$name = "start";

$start_row = 2;


$es_enum = "/* Example screen enumeration */\nenum\n{\n";


while (1)
{
    $name = $Sheet->Range("B".$start_row)->{Value}; 
    $enum = $Sheet->Range("E".$start_row)->{Value}; 
    $name_gb = $Sheet->Range("C".$start_row)->{Value}; 
    $compile_option = $Sheet->Range("D".$start_row)->{Value}; 
    last if ($name eq "");
    

    
    if ($compile_option ne "")
    {
        $compile_option =~ s/([A-Z0-9_]+)/defined\($1\)/g;
        
        $es .= "#if $compile_option\n";
        $es_gb .= "#if $compile_option\n";
        $es_enum .= "#if $compile_option\n";
    }
    
    $es .= "\tL\"$name\",\n";
    $es_gb .= "\tL\"".to_ucs2($name_gb)."\",\n";
    $es_enum .= "\t$enum,\n";
    
    if ($compile_option ne "")
    {
        $es .= "#endif\n";
        $es_gb .= "#endif\n"; 
        $es_enum .= "#endif\n";
    }    
    
    $start_row++;
}

$es_enum .= "\tMMI_MTE_EXAMPLE_SCREEN_NUM\n";

$es_enum .= "} mmi_mte_example_screen_enum;\n\n";
$es .= "};\n\n";
$es_gb .= "};\n\n";

print OUTFILE $es_enum;
print OUTFILE $es;
print OUTFILE $es_gb;

#
# GROUP NAME
#

my $Sheet = $Book->Worksheets("Component Group Name");
$Sheet->Activate(); 

# ENGISH
$gc = "/* English component group name */\n";
$gc .= "static const wchar_t *g_mmi_mte_theme_component_group_name_EN[MMI_MTE_THEME_COMPONENT_GROUP_NUM] =\n{\n";

sub hashValueAscendingNum 
{
    $theme_component_group{$a} <=> $theme_component_group{$b};
}

$c = 0;
foreach $k (sort hashValueAscendingNum (keys(%theme_component_group))) 
{
    #print $k."\n";
    $gc .= "\tL\"$k\", // $c\n";
    $c++;
}

$gc .= "};\n\n";

print OUTFILE $gc;

# GB
$gc = "/* GB component group name */\n";
$gc .= "static const wchar_t *g_mmi_mte_theme_component_group_name_GB[MMI_MTE_THEME_COMPONENT_GROUP_NUM] =\n{\n";


@group_enum = ();

$c = 0;
foreach $k (sort hashValueAscendingNum (keys(%theme_component_group))) 
{
    $start_row = 2;
    $done = 0;
    
    while (1)
    {
        $name = $Sheet->Range("A".$start_row)->{Value}; 
        $name_gb = $Sheet->Range("B".$start_row)->{Value};   
        $group_enum_name = $Sheet->Range("C".$start_row)->{Value};   

        last if ($name eq "");
        
        if ($name eq $k)
        {
            push(@group_enum, "\t$group_enum_name");            
            $gc .= "\tL\"".to_ucs2($name_gb)."\", // $c\n";
            $done = 1;
        }

        $start_row++;        
    }        
    
    if ($done == 0)
    {
        die "$k $name GROUP NAME NOT FOUND!!!\n";
    }
    
    $c++;
}

$gc .= "};\n\n";

$group_enum_def = "typedef enum\n{\n";
$group_enum_def .= join(",\n", @group_enum);
$group_enum_def .= "\n} mmi_mte_group_enum;\n\n";

print OUTFILE $group_enum_def;

print OUTFILE $gc;


#print "TOTAL: $theme_count\n";

print OUTFILE "/* MTE theme components to DM control sets */\n";
print OUTFILE "static const mmi_mte_control_set_group_struct g_mmi_mte_control_set_group[] =\n{\n";
#foreach $d (keys(%dm_groups))
for ($i = 0; $i <= $#dm_group_name; $i++)
{
    $d = $dm_group_name[$i];    
    #print $d." ".$dm_groups{$d}."\n";
    #print $dm_result{$d}."\n";
    
    $ca = $dm_result{$d};
    #get rid of ", "
    chop($ca);
    chop($ca);
    
    if ($ca eq "")
    {
        $ca = "0";
    }
    
    print OUTFILE "\t{".$dm_groups{$d}.", {".$ca."}}, // $d\n";
}

print OUTFILE "};\n\n";


my $Sheet = $Book->Worksheets("Specific Screen");
$Sheet->Activate(); 

$start_row = 2;
$name = $Sheet->Range("A".$start_row)->{Value}; 

#
# screen filter
#

$filter_count = 0;

$start = 0;

$filter_num = 0;

$compile_option = "";

while ($name ne "EOF")
{        
    $name = $Sheet->Range("A".$start_row)->{Value};       
    $component_name = $Sheet->Range("D".$start_row)->{Value}; 
    $marker = $Sheet->Range("I".$start_row)->{Value}; 
    $discard_dm = $Sheet->Range("I".$start_row)->{Value}; 
    $dependency = $Sheet->Range("K".$start_row)->{Value};              
            
    if ($marker eq "START")
    {
        $category_id = $Sheet->Range("F".$start_row)->{Value}; 
        $screen_id = $Sheet->Range("G".$start_row)->{Value};  
        $discard_dm = $Sheet->Range("J".$start_row)->{Value};  
        
        
        if ($screen_id eq "")
        {
            $screen_id = 0;
        }
        
        if ($category_id eq "")
        {
            $category_id = 0;
        }
        
        if ($discard_dm eq "")
        {
            $discard_dm_hash{$filter_num} = 0;
            $discard_dm_num_hash{$filter_num} = 0;
        }
        else
        {
            $discard_dm =~ s/ //g;
            @discard_dm_ids = split(/,/, $discard_dm);
                           
            foreach $c (@discard_dm_ids)
            {
                $discard_dm_hash{$filter_num} .= $c.", ";
                $discard_dm_num_hash{$filter_num}++;
            }            
        }
               
        if (!defined($screen_hash{$filter_num}))
        {
            $screen_hash{$filter_num} = 0;
            
            if ($dependency ne "")
            {
                if ($screen_id)
                {
                	  if ($category_id)
                	  {
                        $screen_cat_hash{$filter_num} = "SCREEN_FILTER_$screen_id, SCREEN_FILTER_$category_id";
                    }
                    else
                    {
                        $screen_cat_hash{$filter_num} = "SCREEN_FILTER_$screen_id, $category_id";
                    }    
                }
                else
                {
                    $screen_cat_hash{$filter_num} = "$screen_id, SCREEN_FILTER_$category_id";
                }
                
                $dep_category_id = $dependency;
                $dep_category_id =~ s/([A-Z0-9_]+)/defined\($1\)/g;
                # category ID dependency
                $compile_option .= "#if $dep_category_id\n";
                if ($screen_id)
                {
                    $compile_option .= "#define SCREEN_FILTER_".$screen_id." ".$screen_id."\n"; 
                }
                if ($category_id)
                {
                    $compile_option .= "#define SCREEN_FILTER_".$category_id." ".$category_id."\n";          
                }
                $compile_option .= "#else\n";   
                if ($screen_id)
                {
                    $compile_option .= "#define SCREEN_FILTER_".$screen_id." MMI_MTE_INVALID_FILTER_COMPONENT\n"; 
                }     
                if ($category_id)
                {                
                    $compile_option .= "#define SCREEN_FILTER_".$category_id." MMI_MTE_INVALID_FILTER_COMPONENT\n";            
                }
                $compile_option .= "#endif\n";                
            }
            else
            {
                $screen_cat_hash{$filter_num} = "$screen_id, $category_id";                
            }
        }                
        
        $start = 1;
        

        # print "START $start_row $filter_num $category_id $screen_id\n";        
    }

    $start_row++;    
         
    #print ">>>$name\n";

    # print "== $component_name\n";

    if (($component_name ne "") && ($start == 1))
    {   
        $component_name =~ s/[ \t\r\n]//g;
        @names = split(/,/, $component_name);
       
        $screen_hash{$filter_num} += $#names + 1;
              
        if ($dependency ne "")
        {
            $dependency =~ s/([A-Z0-9_]+)/defined\($1\)/g;

            $compile_option .= "#if $dependency\n";
            @comp_names = ();
            foreach $c (@names)
            {
                if (substr($c, 0, 1) eq "-")
                {
                    $c = substr($c, 1, length($c) - 1);
                    $is_remove_comp = "-";
                }
                else
                {
                    $is_remove_comp = "";
                }
                
                $comp_name = "SCREEN_FILTER_".$filter_num."_$c";
                
                $comp_name =~ tr/a-z/A-Z/;                   
                
                push(@comp_names, $comp_name);                      
                     
                $compile_option .= "#define $comp_name ".$is_remove_comp.$component_hash{$c}."\n";
                $screen_component_hash{$filter_num} .= $comp_name.", ";
            }                
            
            $compile_option .= "#else\n";
            foreach $c (@comp_names)
            {                              
                $compile_option .= "#define $c MMI_MTE_INVALID_FILTER_COMPONENT\n";              
            }
            
            $compile_option .= "#endif\n";                        
        }
        else
        {
            foreach $c (@names)
            {
                if (substr($c, 0, 1) eq "-")
                {
                    $c = substr($c, 1, length($c) - 1);
                    $is_remove_comp = "-";
                }
                else
                {
                    $is_remove_comp = "";
                }            
            
                $screen_component_hash{$filter_num} .= $is_remove_comp.$component_hash{$c}.", ";
            }
        }
    }
    
    if ($marker eq "END")
    {
        $filter_num++;
        $start = 0;
        
        # print "END $start_row $filter_num $category_id $screen_id\n";      
        next;
    }        
    
    #next if (($start == 0) && ($marker eq ""));
}

$filter_count = $filter_num;

print OUTFILE "#define\tMMI_MTE_CURRENT_SCREEN_FILTER_NUM\t$filter_count\n\n";

print OUTFILE "/*\n * screen filter\n */\n";
print OUTFILE "/* filter dependencies */\n";
print OUTFILE $compile_option."\n";
print OUTFILE "static const mmi_mte_current_screen_filter_struct g_mmi_mte_current_screen_filter[MMI_MTE_CURRENT_SCREEN_FILTER_NUM] =\n{\n";

#foreach $k (keys(%screen_hash))
#foreach $k (@screen_filter_order)
for ($k = 0; $k < $filter_num; $k++)
{
    #print ">>>>".$k."\n";
    
    
    # no component at all, use the 0 array
    $component_list = $screen_component_hash{$k};
    if ($component_list eq "")
    {
        $component_list = "0";
    }
    
    print OUTFILE "\t{".$screen_cat_hash{$k}.", ".$screen_hash{$k}.", {".$component_list."}, {".$discard_dm_num_hash{$k}.", {".$discard_dm_hash{$k}."}}},\n";
}

print OUTFILE "};\n\n";


sub to_ucs2
{
    my $str = $_[0];
    my $ucs2;
    my $i;
    my $result;
    
    $ucs2 = encode("UCS-2LE", $str);

    for ($i = 0; $i < length($ucs2); $i += 2)
    {        
        $result .= sprintf("\\x%02X%02X", ord(substr($ucs2, $i + 1, 1)), ord(substr($ucs2, $i, 1)));
    }
    
    return $result;
}


##################################
# BACKWARD COMPATIBILITY WORKSHEET
##################################

# find the compatibility sheet (available since 08A)
$found = 0;
foreach my $sheet (in $Book->{Worksheets})
{
    $found = 1 if ($sheet->{Name} eq "COMPATIBILITY");
}

# not found, skip the last output compatibility section
goto mte_gen_exit if (!$found);

my $Sheet = $Book->Worksheets("COMPATIBILITY");

$branch_verno = "";

# output branch table
$start_row = 1;
$name = "";
$branch_count = 0;

while (1)
{
    $name = $Sheet->Range("A".$start_row)->{Value};     
    last if ($name eq "EOF");
    
    @n = split(/ /, $name);
    $branch{$n[0]} = $branch_count;
    $n[1] =~ /(\d+)\.(\d+)/;
    $major_ver = $1;
    $minor_ver = $2;
    $branch_verno .= "MMI_MTE_VER($major_ver, $minor_ver), // $n[0]\n";
    $branch_count++;
    $start_row++;
} 

print OUTFILE "#define MMI_MTE_VER(major, minor)    (((major) << 16) | ((minor) & 0xFFFF))\n";
print OUTFILE "#define MMI_MTE_GET_MAJOR_VER(ver)   (((ver) >> 16) & 0xFFFF)\n";
print OUTFILE "#define MMI_MTE_GET_MINOR_VER(ver)   ((ver) & 0xFFFF)\n";
print OUTFILE "#define MMI_MTE_BRANCH_NUM $branch_count\n\n";
print OUTFILE "static const int g_mmi_mte_branch_ver[MMI_MTE_BRANCH_NUM] = \n{\n";
print OUTFILE $branch_verno;
print OUTFILE "};\n";

# output backward renaming table
$start_row++;
$from = $Sheet->Range("A".$start_row)->{Value};
$to = $Sheet->Range("B".$start_row)->{Value};
$start_row++;

$tc_count = 0;
$back_list = "";

while (1)
{
    $name = $Sheet->Range("A".$start_row)->{Value};     
    last if ($name eq "EOF");
    
    $t = $Sheet->Range(chr(ord("A") + $branch_count - 1).$start_row)->{Value};     
       
    if ($t ne "")
    {
        for ($i = 0; $i < $branch_count - 1; $i++)
        {
            $name = $Sheet->Range(chr(ord("A") + $i).$start_row)->{Value};
            $back_list .= "\"$name\", "
            # print "$t >>>".$name."\n";
        }        
        
        $back_list .="\"$t\", \n";
        
        $tc_count++;
    }
       
    $start_row++;   
} 

print OUTFILE "\n#define MMI_MTE_BACKWARD_COMPATIBILITY_COMPONENT_NUM   $tc_count\n";
print OUTFILE "static const char *g_mmi_mte_backward_component[MMI_MTE_BACKWARD_COMPATIBILITY_COMPONENT_NUM * MMI_MTE_BRANCH_NUM] =\n{\n";
print OUTFILE $back_list."};\n\n";

#open(OUTFILE1, ">mte_data_done.h") or die "Cannot open mte_data_done.h!";
#print OUTFILE1 "\nmte_data.h generate done!!!\n";

mte_gen_exit:

$Excel->Workbooks->Close();

close(OUTFILE);
#close(OUTFILE1);
unlink($dir) if (-e $dir);

sub get_CurrTime_str
{
    my($sec, $min, $hour, $mday, $mon, $year) = localtime(time);
    return (sprintf "%04d_%02d_%02d_%02d_%02d_%02d", $year+1900, $mon+1, $mday, $hour, $min, $sec);
}
