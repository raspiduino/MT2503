import os

#from public_def import *
from public_var import *
import public_var


g_is_rotate = 0
g_map_unicode = {}
g_lang_map = {} #macro:lang
g_lang_list = [] #current lang list//mmi_feature_option
g_lang_tras_list = []
g_load_file_attr = ""
g_num_list = ['0','1','2','3','4','5','6','7','8','9']

g_bg_list1 = []
g_bg_list2 = []
g_bg_file_map = {}
g_bg_path_list1 = []
g_bg_path_list2 = []
g_is_cosmos = True
g_root_path = "plutommi\\"
g_path1 = "Service\\vk3Srv\\Res\\"

def readConfig():
    global g_lang_map
    global g_lang_list
    
    global g_cosmos_mmi
    global g_venus_mmi
    global g_main_lcd
    global g_fte
    global g_cosmos_slim
    global g_fte_slim
    global g_low_cost_style
    global g_basic_ui_style
    
    file_path = os.path.join("../../../../","build//")
    log_file = ""
    
    ini_file = "../../../../make.ini"
    content = open(ini_file, 'r').readlines()
    for ini_line in content:
        if "custom" in ini_line:
            log_file = ini_line.replace("custom", "")
            log_file = log_file.replace("=", "")
            log_file = log_file.replace(" ", "")
            log_file = log_file.replace("\n", "")
        
    if os.path.isdir(file_path):
        file_path = os.path.join(file_path, log_file)
        file_path = os.path.join(file_path, 'log')
        
    fpath = ""

    fpath = os.path.join(file_path,"info.log")
    lines = open(fpath,'r').readlines()
    for line in lines:
        if "\n" in line:
            line = line.replace("\n","")
        if '__MMI_MAINLCD_' in line:
            g_main_lcd = line
            line = line.replace("__MMI_MAINLCD_","")
            readInfoLog(line)
        if line == "__LOW_COST_SUPPORT_COMMON__" and (g_cosmos_mmi == True):
            g_cosmos_slim = True
        if "__COSMOS_MMI__" == line:
            g_cosmos_mmi = True
        elif line == "__VENUS_MMI__":
            g_venus_mmi = True
        elif line == "__MMI_FTE_SUPPORT__":
            g_fte = True
        elif "__MMI_BASIC_UI_STYLE__" in line:
            g_basic_ui_style = True
        elif "LOW_COST_SUPPORT" in line:
            g_low_cost_style = True
        elif "__NO_HANDWRITING__" in line:
            public_var.g_is_support_handwriting = False
            print "is_support handwriting = ", public_var.g_is_support_handwriting
    
    fpath = os.path.join(file_path, 'MMI_features.log')
    lines = open(fpath,'r').readlines()
    for line in lines:
        if ("[D]" in line )and ("MMI_LANG" in line):
            readLang(line, 'lang')
        elif ("__MMI_SCREEN_ROTATE__" in line) and ('[D]' in line):
            readLang(line, 'rotate')
        elif ("[D]" in line ) and ("__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__" in line):
            global g_is_open_vk3
            g_is_open_vk3 = True
        elif ("[D]" in line ) and ("__MMI_FTE_SUPPORT_SLIM__" in line):
            g_fte_slim = True
        elif ("[D]" in line ) and ("__MMI_IME_VK_TYPE_ALPHANUMERIC__" in line):
            public_var.g_is_support_matrix = True
            print "is_support martrix = ",public_var.g_is_support_matrix
        elif ("[D]" in line ) and ("__MMI_IME_VK_TYPE_QWERTY__" in line):
            public_var.g_is_support_qwerty = True
            print "is_support qwerty = ",public_var.g_is_support_qwerty
        elif ("[D]" in line ) and ("__MMI_DIALER_SEARCH__" in line) and (not g_cosmos_mmi):
            public_var.g_is_support_dialer_search = True
            print "is_support dialer = ",public_var.g_is_support_dialer_search            
        elif ("[D]" in line ) and ("__MMI_IME_STROKE_INPUT__" in line):
            public_var.g_is_support_stroke = True
            print "is_support stroke = ",public_var.g_is_support_stroke            
    
    if g_is_open_vk3:        
        get_current_image_folder()
        genImageID()
        
            
def get_current_image_folder():
    global g_cosmos_mmi
    global g_venus_mmi
    global g_image_folder
    global g_main_lcd
    global g_fte
    global g_fte_slim
    global g_cosmos_slim
    global g_low_cost_style
    global g_basic_ui_style
    
    if g_cosmos_mmi and g_venus_mmi:
        if g_main_lcd == "__MMI_MAINLCD_240X320__":
            if g_cosmos_slim:
                g_image_folder = "COSMOS_SLIM240X320"
            else:
                g_image_folder = "COSMOS240X320"
        elif g_main_lcd == "__MMI_MAINLCD_240X400__":
            if g_cosmos_slim:
                g_image_folder = "COSMOS_SLIM240X400"
            else:
                g_image_folder = "COSMOS240X400"
        elif g_main_lcd == "__MMI_MAINLCD_320X480__":
            if g_cosmos_slim:
                g_image_folder = "COSMOS_SLIM320X480"
            else:
                g_image_folder = "COSMOS320X480"
        elif g_main_lcd == "__MMI_MAINLCD_480X800__":
            if g_cosmos_slim:
                g_image_folder = "COSMOS_SLIM480X800"
            else:
                g_image_folder = "COSMOS480X800"
    else:
        if g_fte:
            if g_main_lcd == "__MMI_MAINLCD_240X320__":
                if g_fte_slim:
                    g_image_folder = "FTE_SLIM240X320"
                else:
                    g_image_folder = "FTE240X320"
            elif  g_main_lcd == "__MMI_MAINLCD_240X400__":
                    g_image_folder = "FTE240X400"
            elif g_main_lcd == "__MMI_MAINLCD_320X240__":
                    g_image_folder = "FTE320X240"
            elif g_main_lcd == "__MMI_MAINLCD_320X480__":
                    g_image_folder = "FTE320X480"
            elif g_main_lcd == "__MMI_MAINLCD_480X800__":
                    g_image_folder = "FTE480X800"
        else:
            if g_basic_ui_style:
                if g_main_lcd == "__MMI_MAINLCD_128X128__":
                    g_image_folder = "PLUTO_BASIC128X128"
                elif g_main_lcd == "__MMI_MAINLCD_128X160__":
                    g_image_folder = "PLUTO_BASIC128X160"
                elif g_main_lcd == "__MMI_MAINLCD_176X220__":
                    g_image_folder = "PLUTO_BASIC176X220"
                elif g_main_lcd == "__MMI_MAINLCD_240X320__":
                    g_image_folder = "PLUTO_BASIC240X320"
                else:
                    g_image_folder = "PLUTO_BASIC176X220"
            if g_low_cost_style:
                if g_main_lcd == "__MMI_MAINLCD_128X128__":
                    g_image_folder = "PLUTO_SLIM128X128"
                elif g_main_lcd == "__MMI_MAINLCD_128X160__":
                    g_image_folder = "PLUTO_SLIM128X160"
                elif g_main_lcd == "__MMI_MAINLCD_176X220__":
                    g_image_folder = "PLUTO_SLIM176X220"
                elif g_main_lcd == "__MMI_MAINLCD_240X320__":
                    g_image_folder = "PLUTO_SLIM240X320"
                elif g_main_lcd == "__MMI_MAINLCD_320X240__":
                    g_image_folder = "PLUTO_SLIM320X240"
                else:
                    g_image_folder = "PLUTO_SLIM128X128"
            else:
                if g_main_lcd == "__MMI_MAINLCD_128X64__":
                    g_image_folder = "PLUTO128X64"
                elif g_main_lcd == "__MMI_MAINLCD_128X160__":
                    g_image_folder = "PLUTO128X160"
                elif g_main_lcd == "__MMI_MAINLCD_176X220__":
                    g_image_folder = "PLUTO176X220"
                elif g_main_lcd == "__MMI_MAINLCD_240X320__":
                    g_image_folder = "PLUTO240X320"
                elif g_main_lcd == "__MMI_MAINLCD_320X240__":
                    g_image_folder = "PLUTO320X240"
                elif g_main_lcd == "__MMI_MAINLCD_240X400__":
                    g_image_folder = "PLUTO240X400"
                elif g_main_lcd == "__MMI_MAINLCD_320X480__":
                    g_image_folder = "PLUTO320X480"
                elif g_main_lcd == "__MMI_MAINLCD_360X640__":
                    g_image_folder = "PLUTO360X640"
                elif g_main_lcd == "__MMI_MAINLCD_480X800__":
                    g_image_folder = "PLUTO480X800"
                else:
                    g_image_folder = "PLUTO128X128"

def genImageID():
    global g_bg_list1
    global g_bg_list2
    global g_bg_path_list1
    global g_bg_path_list2
    global g_bg_file_map
    global g_image_folder
    global g_is_cosmos
    import os
    import zipfile
    
    pre_len = 2
    is_cosmos = True
    path = getPrePathEx("", pre_len)
    path +=  "\\Images\\" + g_image_folder + "\\"
    
    file_list = os.listdir(path)
    zf = ""
    
    if "FTE" in path:
        g_is_cosmos = False

    if g_is_cosmos:
        if "Image.zip" in file_list or "image.zip" in file_list:
            zf = path + "Image.zip"
            z = zipfile.ZipFile(zf, "r")
            for name in z.namelist():
                name = name.replace("\n","")
                if name[-4:] != ".png":
                    continue
                if "Image/" in name:
                    name = name.replace("Image/","")
                
                if "MainLCD/Default/VK3/"  in name:
                    name = name.replace("MainLCD/Default/VK3/","")
                                        
                    if "Keyicon/" in name or "Popupicon/" in name:
                        if "dialer" in name and not public_var.g_is_support_dialer_search:
                            continue    
                        g_bg_path_list1.append(name)
                        index = g_bg_path_list1.index(name)
                    		  
                        if "Keyicon/" in name:
                            name = name.replace("Keyicon/", "")
                        elif "Popupicon/" in name:
                            name = name.replace("Popupicon/","")
                        name = name.replace(".png","")
                        fname = name.replace(".9slice", "")
                        if fname not in g_bg_file_map.keys():
                            g_bg_file_map[fname] = [1, index]
                        name = name.upper()
                        name = name.replace(".","_")
                        temp = "IMG_ID_" + name
                        temp = temp.replace("/","_")
                        g_bg_list1.append(temp)
                
                elif ("Components" not in name)and "/Theme" in name and "VK3/" in name:
                    fname = name.replace("MainLCD/","")
                    g_bg_path_list2.append(fname)
                    index = g_bg_path_list2.index(fname)
                    name = getPngName(fname)
                    #name = name.replace("MainLCD/Theme1/VK3/","")
                    name = name.replace(".png","")
                    fname = name.replace(".9slice", "")
                    if fname not in g_bg_file_map.keys():
                        g_bg_file_map[fname] = [2, index]
                    name = name.upper()
                    name = name.replace(".","_")
                    temp = "IMG_ID_" + name
                    g_bg_list2.append(temp)
    else:
           if "Image.zip" in file_list or "image.zip" in file_list:
            zf = path + "Image.zip"
            z = zipfile.ZipFile(zf, "r")
            for name in z.namelist():
                name = name.replace("\n","")
                if name[-4:] != ".png":
                    continue
                if "Image/" in name:
                    name = name.replace("Image/","")
                    
                fname = name
                
                if "MainLCD/UIElement/VK3/"  in name:
                    name = name.replace("MainLCD/UIElement/VK3/","")
                    
                    if "Keyicon/" in name or "Popupicon/" in name:
                        if "dialer" in name and not public_var.g_is_support_dialer_search:
                            continue
                        g_bg_path_list1.append(name)
                        index = g_bg_path_list1.index(name)
                        if "Keyicon/" in name:
                            name = name.replace("Keyicon/", "")
                        elif "Popupicon/" in name:
                            name = name.replace("Popupicon/","")
                        name = name.replace(".png","")
                        fname = name.replace(".9slice", "")
                        if fname not in g_bg_file_map.keys():
                            g_bg_file_map[fname] = [1, index]
                        name = name.upper()
                        name = name.replace(".","_")
                        temp = "IMG_ID_" + name
                        temp = temp.replace("/","_")
                        g_bg_list1.append(temp)
                
                    else:
                        
                        if "ime/Arrow" in name or "ime/InputBox" in name or \
                        "ime/TextFocusedHighlight" in name or "ime/TextUnfocusedHighlight" in name or \
                        ("ime/new_cand_box" in name and "keyboard_background" not in name and "highlight_bkg" not in name):
                            continue
                        print name
                        g_bg_path_list2.append(name)
                        index = g_bg_path_list2.index(name)
                        name = getPngName(name)
                        #name = name.replace("MainLCD/Theme1/VK3/","")
                        name = name.replace(".png","")
                        fname = name.replace(".9slice", "")
                        if fname not in g_bg_file_map.keys():
                            g_bg_file_map[fname] = [2, index]
                        name = name.upper()
                        name = name.replace("/", "_")
                        name = name.replace(".","_")
                        temp = "IMG_ID_" + name
                        g_bg_list2.append(temp)
                
def readLang(line, param):
    global g_lang_map
    global g_lang_list
    global g_is_rotate
    
    if param == 'rotate':
        g_is_rotate = 1
    elif param == 'lang':
        begin = -1
        sLang = ""
        for i in line:
            if begin>0 and ((i == ' ') or i == '\n'):
                break
            if i == "_" and begin <= 0:
                begin += 1
                sLang += i
            if i == '_' and begin > 0:
                sLang += i
            if begin > 0:
                sLang += i
        sLang = sLang.replace('__', '_')
        sLang = sLang.replace('____','__')
        sLang = sLang.replace(' ', '')
        g_lang_list.append(sLang)
      

def readInfoLog(line):
    global g_lcdw
    global g_lcdh
    
    lcd_size = line
    l = 0
    cur_string = ["",""]
    for i in xrange(0, len(lcd_size)):
        if lcd_size[i] == 'X' or lcd_size[i] == 'x':
            l = 1
        if lcd_size[i] == '_':
            break
        if lcd_size[i]  in g_num_list:
            cur_string[l] += lcd_size[i]
    g_lcdw = int(cur_string[0])
    g_lcdh = int(cur_string[1])

def readFontRes():
    lang_map = {}
    lines = open('FontConstTable.txt', 'r').readlines()
    bRead = False
    bMacro = False
    key = ''
    f = open('lang_config.ini', 'w')
    for line in lines:
        if "mtk_gLanguageArray" in line:
            bRead = True
        if bRead:
            if '#if defined' in line:
                left = line.find('(')
                right = line.find(')')
                l = line[left+1:right]
                bMacro = True
                if l not in lang_map:
                    lang_map[l] = ["",""]
                    key = l
            
            if bMacro and bRead and ("\"" in line) and ('*#' not in line):
                begin = 0
                cur = 0
                for i in line:
                    if i == "\"" and begin:
                        break
                    elif i == "\"":
                        begin = 1
                    elif begin and i == "-":
                        cur = 1
                        lang_map[key][cur] = ''
                    elif begin:
                        lang_map[key][cur] += i
    for key in lang_map:
        f.write(key)
        f.write('\t\t\t')
        f.write(lang_map[key][0])
        f.write('\t\t\t')
        f.write(lang_map[key][1])
        f.write('\n')
    f.close()

    global g_lang_map
    g_lang_map = lang_map
                    
                
def readUnicodeMapping():
    #print "readUnicodeMapping()"
    global g_map_unicode
    f = open('unicode_mapping.txt', 'r')
    lines = f.readlines()
    for line in lines:
        tl = line.split('\t\t')
        if len(tl) > 1:
            key = tl[1].replace('\n','')
            value = tl[0]
            if key not in g_map_unicode:
                g_map_unicode[key] = value
    f.close()
    return 

def translateLang():
    global g_lang_map
    global g_lang_list
    global g_lang_tras_list
    for lang in g_lang_list:
        if lang in g_lang_map:
            g_lang_tras_list.append(g_lang_map[lang])
    #print "current open language macro:"
    #print g_lang_list
    #print g_lang_tras_list

# other attribute:land or long
# long ---> land
def translateOtherAtt():
    global g_load_file_attr
    global g_is_rotate
    global g_lcdw
    global g_lcdh
    
    g_load_file_attr = ''
    if ((g_lcdw/g_lcdh) >= (5/3)) or ((g_lcdh/g_lcdw) >= (5/3)):
        g_load_file_attr += '-long'
    if g_is_rotate:
        g_load_file_attr += '-land'

def getPrePathEx(lpath,pre_num):
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

def genXmlImage():
    import os
    lpath = getSlicePath(os.getcwd(), g_root_path)
     
    if not os.path.exists(lpath + "Service"):
        os.mkdir(lpath + "Service")
    if not os.path.exists(lpath + "Service\\vk3Srv\\"):
        os.mkdir(lpath + "Service\\vk3Srv\\")
    if not os.path.exists(lpath + "Service\\vk3Srv\\Res"):
        os.mkdir(lpath + "Service\\vk3Srv\\Res")
    if not os.path.exists(lpath + "Service\\vk3Srv\\inc"):
        os.mkdir(lpath + "Service\\vk3Srv\\inc")
        
    res_out_path = lpath + g_path1 + "vk3.res"
    
    global g_bg_list1
    global g_bg_list2
    global g_bg_path_list1
    global g_bg_path_list2
    
    wbuffer = "#include \"MMI_features.h\" \n"
    wbuffer += "#include \"CustResDef.h\" \n\n\n"
    wbuffer += "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"     
    wbuffer += "<APP id=\"SRV_VK3\">" + "\n"
    
    if g_is_cosmos:
        for i in xrange(0, len(g_bg_path_list1)):
            wbuffer += "\t<IMAGE id = " + "\""        
            wbuffer += g_bg_list1[i] + "\""
            wbuffer += ">"
            wbuffer += "CUST_IMG_PATH_ROOT"
            wbuffer += "\""
            wbuffer += "\\\\\\\\MainLCD\\\\\\\\Default\\\\\\\\VK3\\\\\\\\"
            fname = g_bg_path_list1[i].replace("/","\\\\\\\\")
            wbuffer += fname
            wbuffer += "\""
            #wbuffer += '''  force_type="FORCE_AB2" '''
            wbuffer += "</IMAGE>"
            wbuffer += "\n"
    else:
        for i in xrange(0, len(g_bg_path_list1)):
            wbuffer += "\t<IMAGE id = " + "\""        
            wbuffer += g_bg_list1[i] + "\""
            wbuffer += ">"
            wbuffer += "CUST_IMG_PATH_ROOT"
            wbuffer += "\""
            wbuffer += "\\\\\\\\MainLCD\\\\\\\\UIElement\\\\\\\\VK3\\\\\\\\"
            fname = g_bg_path_list1[i].replace("/","\\\\\\\\")
            wbuffer += fname
            wbuffer += "\""
            #wbuffer += '''  force_type="FORCE_AB2" '''
            wbuffer += "</IMAGE>"
            wbuffer += "\n"
       
        for k in xrange(0, len(g_bg_path_list2)):
            wbuffer += "\t<IMAGE id = " + "\""
            wbuffer += g_bg_list2[k] + "\""
            wbuffer += ">"
            wbuffer += "CUST_IMG_PATH_ROOT"
            wbuffer += "\""
            wbuffer += "\\\\\\\\MainLCD\\\\\\\\UIElement\\\\\\\\VK3\\\\\\\\"
            fname = g_bg_path_list2[k].replace("/","\\\\\\\\")
            wbuffer += fname
            wbuffer += "\""
            wbuffer += "</IMAGE>"
            wbuffer += "\n"
       
    
    wbuffer += "</APP>"
    try:
        f = open(res_out_path, "w")
    except:
        print "open %s error......"(res_out_path)
    f.write(wbuffer)
    f.close()

def getPngName(path_name):
    tmp = path_name
    str_len = len(tmp)
    str_list = []
    tmp_str = ""
    if "/" not in path_name:
        return path_name
    for i in xrange(1, str_len):
        if tmp[- i] == "/":
            break
        str_list.append(tmp[-i])
        
    str_list.reverse()
    
    for s in str_list:
        tmp_str += s
    return tmp_str

def getSlicePath(path, slice_root):
    temp_str = ""
    index = path.find(slice_root)
    if index == -1:
        return temp_str
    temp_str = path[0:index + len(slice_root)]
    return temp_str

def readConfigMain():
    readUnicodeMapping()
    readConfig()
    readFontRes()
    translateLang()
    translateOtherAtt()
    genXmlImage()
    return g_is_open_vk3

if __name__ == "__main__":
    readConfigMain()

        
    
