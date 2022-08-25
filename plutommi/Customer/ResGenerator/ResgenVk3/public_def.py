#define the output path and filename
#value moudle out put to out_value.h
#template file out put to template_head.h
#normal data out put to normal.h
import os
import sys

from read_config import *

g_debug = True
g_project_name = ""
g_current_language = "en"
g_current_location = ""
g_kb_type_enum_list = []
#struct key_type.
g_template_keytype_name =["bg","hlbg","balloon_bg",
                          "balloon_ratio_height",
                          "balloon_ratio_width",                          
                          "text_color1",
                          "text_color2",
                          "hltext_color1",
                          "hltext_color2", 
                           "bltext_color1",
                           "bltext_color2",
                           #"kb_width",
                           #"kb_height", 
                           "main_regx",
                           "main_regy",
                           "aux_regx",
                           "aux_regy",
                           "text_size1",
                           "text_size2",
                           "hltext_size1",
                           "hltext_size2",
                            "bltext_size1",
                            "bltext_size2"]

g_keyboard_attr = ["kb_height","kb_width","skb_bg",
                   "key_xmargin","key_ymargin","bitmap_cache_flag",
                   "needshift_flag", "row_num"]
g_key_attr = ["code","key_type","icon","icon_aux","icon_hl","icon_aux_hl","label",
              "label_aux","label_balloon","icon_balloon","code_longpress","label_balloon_longpress",
              "icon_balloon_longpress","pos_x","pos_y","height","width","popup_skb",'toggle_index']

g_keys_attr = ["codes", "labels"]
#this is template attr map
g_template_attr_map = {}
g_template_key_type_list = []
g_keytype_index_list = []
g_template_keyboard_map = {}

g_current_lang = "en"

#value/struct
#key:file_name
#value:{}
g_value_map = {}

g_popup_map = {}
g_format_map = {}
g_map_keyboard_attribute = {"skb_qwerty":1, "skb_phn":2, "hw":3, "skb_phone":2, "popup":0}

g_key_list = []
g_key_index = []

g_row_set = {}
g_row_set_index_list = []
g_kb_list = []
g_kb_index_list = []
g_toggle_state_id_list = []
g_toggle_state_index_list = []
g_toggle_key_list = []
g_index_counter = 0
g_toggle_index = 0
##lcd_size
g_lcdw = 0
g_lcdh = 0

dpi_120 = [[240],[320,400,432]]
dpi_160 = [[320],[480]]
dpi_240 = [[480],[800,854]]

global g_dpi_size
g_dpi_size = 0
const_dpi = "160"


g_test_buffer = ""
g_language_list = []

#config global var
g_project_root_path = "../../../../"

g_out_put_folder_name = "..//debug//res_out_put//"
g_out_put_file = "virtual_keyboard3_res.h"
g_out_put_file_head = "virtual_keyboard3_define.h"
g_res_xml_path = "\\VKResourece\\xml\\"
g_res_image_path = "\\VKResourece\\"

g_error_out_put = g_out_put_folder_name + "vkv3_error.txt"
g_error_buf = ""


def get_lcd_size():
    global g_lcdw
    global g_lcdh
    if g_lcdw==0 or g_lcdh == 0:
        readLcdSize()
    return [g_lcdw, g_lcdh]
    
def get_dip_size():
    global g_dpi_size
    global g_lcdw
    global g_lcdh
    if g_lcdw == 0 or g_lcdh == 0:
        readLcdSize()
    if g_lcdw in dpi_120[0] and g_lcdh in dpi_120[1]:
        g_dpi_size = 120
    elif g_lcdw in dpi_160[0] and g_lcdh in dpi_160[1]:
        g_dpi_size = 160
    elif g_lcdw in dpi_240[0] and g_lcdh in dpi_240[1]:
        g_dpi_size = 240
    return g_dpi_size

#if you want to get curent path, please input lpath = ""
def getPrePath(lpath,pre_num):
    import os
    cur_path = ""
    if lpath == "" or lpath == 0:
        cur_path = os.getcwd()
    else:
        cur_path = lpath    
    symbo_list = []
    for i in xrange(0, len(cur_path)):
        if cur_path[i] == '\\':
            if cur_path[i+1] == '\\':
                i += 1
            symbo_list.append(i)
    return cur_path[0: symbo_list[-pre_num]]

def format_color(key, value):
   color_map = g_value_map["colors"]
   value = value.replace("@color/","")
   if value in color_map:
       return color_map[value]
   return None

def format_dim(key, value):
    global g_dpi_size
    dim_map = g_value_map["dimen"]["dimen"]   
    v = value.replace("@dimen/", "")
    if v not in dim_map:
        return None
    return dim_map[v]

def format_draw(key, value):
    global g_bg_list1
    global g_bg_list2
    global g_bg_file_map
    ret_str = "0"
    
    fname = value.replace("@drawable/","")
    if fname not in g_bg_file_map.keys():
        #print fname + "\t" + key + "\t"  + value
        return ret_str
    
    flist = g_bg_file_map[fname]
    if len(flist) > 0:
        if flist[0] == 1:
            ret_str = g_bg_list1[flist[1]]
        elif flist[0] == 2:
                ret_str = g_bg_list2[flist[1]]
    #print ret_str
    return ret_str

def format_xml(key, value):
    global g_kb_index_list
    value = value.replace("@xml/","")
    ret = "-1"
    is_rotate = 0
    
    if "_rotate" in value:
        is_rotate = 1
        value = value.replace("_rotate","")
     
    if "xml-zh-CN/" in value:
        value = value.replace("xml-zh-CN/","")   
        value += '_zh_CN'
    else:
        if g_current_language:
            value += '_' + g_current_language
        if g_current_location:
            value += '_' + g_current_location       
    if is_rotate:
       value += '_rotate'       
    
    if value in g_kb_index_list:
        ret = str(g_kb_index_list.index(value))
    return ret
    
def GetSp():
    global g_dpi_size
    if g_dpi_size == 0:
            get_dip_size()
    return g_dpi_size

def format_value_dim(key):
    dim_value = key
    l = g_dpi_size
    if "sp" in key:
        dim_value = dim_value.replace("sp","*")
        if g_dpi_size == 0:
            l = get_dip_size()
        dim_value += str(l)
        dim_value += "/"+const_dpi
        
    elif "dip" in key:
        dim_value = dim_value.replace("dip", "*160")
        dim_value += "/" + const_dpi 
    return dim_value

#@xml/, mapx: dict,//attribute
def parseTemplateAttribute(xml_template, mapx):
    if xml_template.find("@xml") == -1:
        return None
    ret_dict = {}
    temp = xml_template.replace("@xml/", "")
    if temp not in g_template_attr_map:
        return None
    
    tmap = g_template_attr_map[temp]
    ret_map = mapx
    for key in tmap:
        if key not in mapx:
            ret_map[key] = tmap[key]
    return ret_map    

#config read
def readProjectConfig():
    import os
    global g_project_root_path
    project_config_path = os.path.join(g_project_root_path,"make.ini")
    fcontent = open(project_config_path, "r").read()
    fcontent = fcontent.split("\n")
    custom = ''
    project = ''
    for content in fcontent:
        if 'custom' in content:
            temp_cont = content.split()
            if temp_cont != '=' and temp_cont != "":
                custom = temp_cont[-1]
        if 'project' in content:
            temp_cont = content.split()[-1]
            if temp_cont != '=' and temp_cont != "":
                project = temp_cont
    if project:
        custom += "_" + project
    return custom

def readLcdSize():
    global g_project_root_path
    global g_project_name 
    project_name = readProjectConfig()
    g_project_name = project_name
    project_make_file = "make//" + project_name + ".mak"
    project_make_file = os.path.join(g_project_root_path, project_make_file)
    cur_string = ["",""]
    file = open(project_make_file, "r")
    lcd_size = ""
    l = 0
    is_rotate = 0
    lines = file.readlines()
        
    for line in lines:
        if line.find("MAIN_LCD_SIZE") != -1:
            lcd_size = line
            break
    
        
    if lcd_size:
        if "#" in lcd_size:
            index = lcd_size.find("#")
            lcd_size = lcd_size[0:index]
        for i in xrange(0, len(lcd_size)):
            if lcd_size[i] == 'X' or lcd_size[i] == 'x':
                l = 1
            if lcd_size[i]  in g_num_list:
                cur_string[l] += lcd_size[i]
    global g_lcdw
    global g_lcdh
    g_lcdw = int(cur_string[0])
    g_lcdh = int(cur_string[1])

def readLanguageConfig():
    file_path = os.path.join(g_project_root_path,"build//")
    
    files = os.listdir(file_path)
    fpath = ""
    for folder in files:
        l = os.path.join(file_path, folder)
        if os.path.isdir(l):
           files1 = os.listdir(l)
           if "log" in files1:
                fpath = os.path.join(l,"log//MMI_features.log")
                break;
    lines = open(fpath,'r').readlines()
    #for line in lines:
     #   if (("[D]"in line) == True) and ((("__MMI_LANG_") in line) == True):
      #      print line
    
def checkDir():
    if not os.path.exists(g_out_put_folder_name):
        os.mkdir(g_out_put_folder_name)
