from public_def import *
#from read_config import *
import read_config
import custom_config
import public_var
from xml.etree import ElementTree
import os

class CParseKBXml:
    def __init__(self):
        self.m_attr_map = {}
        self.file_pre_num = 2
        self.file_path = os.getcwd()
        self.m_counter = 0
        
    def checkNeedToParse(self, filename):

        #check if support hw
        if not public_var.g_is_support_handwriting:
            for i in xrange(0, len(custom_config.handwritingPrefix)):
                if custom_config.handwritingPrefix[i] in filename:
                    print "not support handwriting"
                    return 0
        elif not public_var.g_is_support_qwerty and not public_var.g_is_support_matrix:
            for i in xrange(0, len(custom_config.matrixSymbolPrefix)):
                if custom_config.matrixSymbolPrefix[i] in filename and not "custom" in filename:
                    return 1
                                               
        #check if support qwerty
        if not public_var.g_is_support_qwerty: 
            for i in xrange(0, len(custom_config.qwertyPrefix)):
                if custom_config.qwertyPrefix[i] in filename:
                    print "not support qwerty"
                    return 0
        else:
            if "skb_special_alpha" in filename:
                print filename
                isInMiniKeyboardMapping = False
                fname = filename.replace("skb_special_alpha","")
                for key in custom_config.miniKeyboardMapping.keys():
                    if custom_config.miniKeyboardMapping[key] in fname:
                        isInMiniKeyboardMapping = True
                        for i in xrange(0, len(g_lang_tras_list)):
                            if g_lang_tras_list[i][0] not in key or g_lang_tras_list[i][1] not in key:
                                continue
                            else:
                                return 1 #if found, need to parse
                       
                if isInMiniKeyboardMapping:
                    print "not support", filename
                    return 0
                else:
                    return 1
            
        #check if support matrix
        if not public_var.g_is_support_matrix: 
            for i in xrange(0, len(custom_config.matrixPrefix)):
                if custom_config.matrixPrefix[i] in filename:
                    print "not support matrix"
                    return 0
        elif public_var.g_is_support_qwerty:
            if custom_config.symbol123Prefix in filename:
                return 0
            
        #check if support stroke
        if not public_var.g_is_support_stroke: 
            if custom_config.strokeSymbolPrefix in filename:
                print "not support stroke"
                return 0            
            
        #check if support dialer search
        if not public_var.g_is_support_dialer_search: 
            for i in xrange(0, len(custom_config.dialerSearchPrefix)):
                if custom_config.dialerSearchPrefix[i] in filename:
                    print "not support dialer_search"
                    return 0
            
        return 1
    
    def formatLanguage(self, fname):
        out_put = ""
        # language + location + 
        out_put += "GUI_VIRTUAL_KEYBOARD"
        if "hw" in fname:
            out_put +="_TRAY"
        else:
            if g_current_language != "":
                out_put += '_' + g_current_language.upper()
            if g_current_location != "":
                out_put += '_' + g_current_location.upper()
            if "symbol" in fname:
                count = fname.find("symbol")
                out_put += "_" + fname[count:].upper()
            if "123sym" in fname:
                count = fname.find("123sym")
                out_put += "_" + fname[count:].upper()
            if "phone" in fname:
                out_put += "_PHONE"
            if "stroke" in fname:
                out_put += "_STROKE"
            if "dialer" in fname:
                out_put += "_DIALER"
            if "phone_sym" in fname:
                out_put += "_SYMBOL"
            if "shift" in fname:
                out_put += "_SHIFT"

        return out_put
        
    def loadTemplateFolders(self):
        template_path = getPrePath(os.getcwd(), self.file_pre_num) + "\\VKResourece\\xml"
        template_path_rotate = getPrePath(os.getcwd(), self.file_pre_num) + "\\VKResourece\\xml-land"
        
        if not os.path.exists(template_path) or not os.path.exists(template_path_rotate):
            return
        
        g_current_language = 'en'
        g_current_location = ""
        flist = os.listdir(template_path)
        template_path += '\\'
        
        for f in flist:            
            if ("template" in f) and (f[-4:] == ".xml") and \
            ".bak" not in f:
                if self.checkNeedToParse(f):
                    self.parseTemplateXml(template_path+f, f, 0)
        if read_config.g_is_rotate:
            f = ""
            flist_rotate = os.listdir(template_path_rotate)
            template_path_rotate += '\\'
            for f in flist_rotate:
                if ("template" in f) and (f[-4:] == ".xml") and \
                ".bak" not in f:
                    if self.checkNeedToParse(f):
                        self.parseTemplateXml(template_path_rotate+f, f, 1)

        f = ""
        for f in flist:
            if f in custom_config.no_loadfile:
                continue
            if "template" not in f and (f[-4:] == ".xml") and "kb" in f and \
            ".bak" not in f:                   
                if self.checkNeedToParse(f):   
                    self.parseNormalXml(template_path+f, f, 0)
        if read_config.g_is_rotate:
            f = ""
            for f in flist_rotate:
                if f in custom_config.no_loadfile:
                    continue
                if "template" not in f and (f[-4:] == ".xml") and "kb" in f and\
                ".bak" not in f:
                    if self.checkNeedToParse(f):
                        self.parseNormalXml(template_path_rotate+f, f, 1)

    
    def loadNormalFolders(self):
        global g_current_language
        global g_current_location
        global g_lang_tras_list
        global g_lcdw
        global g_lcdh
        is_long = 0
        
        #just work aound to make is_long = 0, it should be 1
        if (g_lcdw*3 >= 5*g_lcdh) or (3*g_lcdh >= 5*g_lcdw):
            is_long = 0
        
        path1 = getPrePath(os.getcwd(), self.file_pre_num) + "\\VKResourece\\xml"
        path2 = path1
        path = path1
       # g_lang_tras_list = [['en', 'US'], ['zh', 'CN'], ['zh', 'TW'],['pt','PT'],
        #                    ['pt','BZ'],['id','ID'],['es','ES'],['es','SA'],
         #                   ['tr','TR'],['ms','MY'],['ro','RO'],['vi', 'VN'],
          #                  ['ru','RU'],['fr','CA'], ['de','DE'],['ar','SA'],['it','IT']]
        #['be','IN']['th','TH']['hi','IN']
     
        for lang_list in g_lang_tras_list:
            #language
            lang = lang_list[0]
            loc = lang_list[1]
            g_current_language = lang
            g_current_location = loc
            if is_long:
                path1 = path + "-" + lang + "-" + loc + "-long"
                #path2 = path +  "-" + lang + "-long"
            else:
                path1 = path + "-" + lang + "-" + loc 
                #path2 = path + "-" + lang 
            if os.path.exists(path1):
                self.loadExactlyFiles(path1,0)
            #if os.path.exists(path2):
             #   self.loadExactlyFiles(path2,0)
            
            if read_config.g_is_rotate:
                path1 += "-land"
                #path2 += "-land"
                if os.path.exists(path1):
                    self.loadExactlyFiles(path1,1)
                #if os.path.exists(path2):
                 #   self.loadExactlyFiles(path2,1)
            
    def loadExactlyFiles(self,path,rotate):
        file_list = os.listdir(path)
        
        for file in file_list:
            if file[-4:] == ".xml":                                       
                if self.checkNeedToParse(file):
                    self.parseNormalXml(path+"\\"+file,file, rotate)
                
           
    def parseFile(self):
        # load template files /rotate and normal
        self.loadTemplateFolders()
        self.loadNormalFolders()
        
    def parseExAttribute(self):
        for attr in g_key_list:
            for key in attr:
                value = attr[key]
                if key == "popup_skb":
                    if type(value) == str:
                        ret = format_xml(key, value)
                        if ret == "-1":
                            return;
                        attr[key] = ret 
    
    def getVkAttribute(self, file_name):
        if 'popup' in file_name:
            return 0
        if "hwkb_fullscreen" in file_name:
            return 11
        elif "hwkb" in file_name:
            return 3
        elif ("phn" in file_name) or ('phone' in file_name):
            return 2
        elif "qwerty" in file_name:
            return 1
        else:
            return 1
        
    def parseNormalXml(self, file_path, file_name, rotate):
        global g_key_list
        global g_key_index
        global g_row_set
        global g_row_set_index_list
        global g_kb_list     
        global g_toggle_state_id_list
        global g_toggle_state_index_list
        global g_toggle_key_list
        global g_error_buf
        
        fname = file_name.replace(".xml","")
        fcontent = open(file_path, "r").read()        
        root = ElementTree.fromstring(fcontent) 
        row_list = root._children
        
        #kb struct format
        index_fname = fname 
        if g_current_language:
            index_fname += '_' + g_current_language
        if g_current_location:
            index_fname += '_' + g_current_location
        if rotate:
            index_fname += "_rotate"
        
        row_index = index_fname
        
        #template deal
        kb_head_map = self.parse_keyboard_head(root.attrib)
        kb_head_map = self.formatData(kb_head_map,rotate)
        kb_head_map = self.computeKeysPos(kb_head_map)
        kb_head_map["row_num"] = len(row_list)
        kb_head_map["row_index"] = row_index
        vk_attr = self.getVkAttribute(fname)
        kb_head_map["vk_attribute"] = vk_attr
        kb_head_map["is_rotate"] = rotate
        kb_head_map["is_shift_spport"] = 0
        kb_head_map["is_cache"] = 0
        if "skb_template" in root.attrib:
            kb_head_map["skb_template"] = root.attrib["skb_template"].replace("@xml/","")
        
        #if current vkattruibut is popup,kb_type_num = GUI_VIRTUAL_KEYBOARD_DEFAULT
        kb_type_enum = None
        if vk_attr == 0:
            kb_type_enum = "GUI_VIRTUAL_KEYBOARD_MAX_LANG"
        else:
            kb_type_enum = self.formatLanguage(fname)
            if kb_type_enum not in g_kb_type_enum_list:
                g_kb_type_enum_list.append(kb_type_enum)
        kb_head_map["gui_virtual_keyboard_language_enum"] = kb_type_enum
        
        g_kb_list.append(kb_head_map)
        g_kb_index_list.append(index_fname)
        
        key_type_tmp = 0
        keytype = 0 
        
        if 'key_type'  in root.attrib:
            key_type_tmp = root.attrib["key_type"]
            keytype = root.attrib["key_type"]
        
        #row       
        row_id_list= []  
        row_id_map_used = {}
        for i in xrange(0, len(row_list)):
            row_attr = row_list[i].attrib
            if "row_id" in row_attr:
                row_id_list.append(row_attr['row_id'])

        start_y = 0
        row_static = 0
        #y_start_offset = 0
        for i in xrange(0,len(row_list)):
            row_index = index_fname + "_" +str(i)
            row_id = 0
            key_count = 0
            row_attr = row_list[i].attrib
                
            start_x = 0
            key_width = 0
            key_height = kb_head_map["height"]
            
            if "row_id" not in row_attr:
                row_attr['row_id'] = -1
                row_static += 1
                if row_static != 1:
                    start_y += int(float(key_height))
            else:
                if row_attr['row_id'] == "1":
                    row_static += 1
                    if row_static != 1:
                        start_y += int(float(key_height))
                #if start_y == '':
                 #   start_y = 0
                row_id = row_attr['row_id']
                if row_id not in row_id_map_used:
                    row_id_map_used[row_id] = 1
                else:
                    row_id_map_used[row_id] += 1
                    
            if "start_pos_x" in row_attr:
                start_x = (int(float(row_attr["start_pos_x"].replace("%p",""))*float(kb_head_map["kb_width"])/100))
            if "start_pos_y" in row_attr:
                start_y = (int(float(row_attr["start_pos_y"].replace("%p",""))*float(kb_head_map["kb_height"])/100))
                #y_start_offset = start_y
            
            if row_list[i]:
                key_line_count = len(row_list[i]._children)
            
            if row_index not in g_row_set:
                g_row_set[row_index] = {}
            key_nums = 0
            g_row_set[row_index]['row_attr'] = {}
            g_row_set_index_list.append(row_index)
            
            #key##############################
            row_key_list = []            
            icount = 0            
            if key_line_count > 0:
                row_key_list = row_list[i]._children                
                for ikey in xrange(0, key_line_count):
                    key_pos_x = 0
                    key_attr = row_key_list[ikey].attrib
                    
                    if "start_pos_x" in key_attr:
                        start_x = (int(float(key_attr["start_pos_x"].replace("%p",""))*float(kb_head_map["kb_width"])/100))
                    if "start_pos_y" in key_attr:
                        start_y = (int(float(key_attr["start_pos_y"].replace("%p",""))*float(kb_head_map["kb_height"])/100))
                    tag = row_key_list[ikey].tag
                    key_attr = self.formatDataEx(key_attr,rotate)
                    
                    if "label_balloon_longpress"  in key_attr:
                        if key_attr["label_balloon_longpress" ] == "\"":
                            key_attr["label_balloon_longpress" ] == '\\"'
                        key_attr["label_balloon_longpress" ] = "L\"" + key_attr["label_balloon_longpress" ]+"\""
                    if "label_balloon" in key_attr:
                        if key_attr["label_balloon" ] == "\"":
                            key_attr["label_balloon" ] = '\\"'
                        key_attr["label_balloon"] = "L\"" + key_attr["label_balloon"] + "\""
                    if "label" in key_attr:
                        if key_attr["label" ] == "\"":
                            key_attr["label" ] = '\\"'
                        key_attr["label"] = "L\"" + key_attr["label"] + "\""
                    if "label_aux" in key_attr:
                        if key_attr["label_aux" ] == "\"":
                            key_attr["label_aux" ] = '\\"'
                        key_attr["label_aux"] = "L\"" + key_attr["label_aux"] + "\""
                    
                    if "width" in key_attr:
                        key_width = str(int(float(key_attr["width"]) * float(kb_head_map["kb_width"])/100))
                    else:
                        key_width = str(kb_head_map["width"])
                    if "height" in key_attr:
                        key_height = str(int(float(key_attr["height"]) * float(kb_head_map["kb_height"])/100))
                    
                    if 'key_type' in key_attr:
                        keytype = key_attr['key_type']
                    else:
                        keytype = key_type_tmp
                ###########################################################
                    toggle_state_list = row_key_list[ikey]._children
                    
                    if toggle_state_list:
                        global g_toggle_index
                        tmap = {}
                        tmap["state_num"] = len(toggle_state_list)
                        tmap["index_count"] = g_toggle_index
                        flag = len(g_toggle_state_index_list)
                        key_attr["toggle_index"] =  flag
                        print key_attr["toggle_index"]
                        g_toggle_state_index_list.append(tmap)
                        
                        for toggle in toggle_state_list:
                            self.m_counter += len(toggle_state_list)
                            toggle_attr = self.formatDataEx(toggle.attrib,rotate)
                            if "key_type" not in toggle_attr:
                                toggle_attr["key_type"] = keytype
                            g_toggle_key_list.append(toggle_attr)
                            state_id = toggle_attr["state_id"]
                            g_toggle_state_id_list.append(state_id)
                        g_toggle_index += len(toggle_state_list)
                ###################################################################
                    if "popup_skb"  not in key_attr:
                        key_attr["popup_skb"] = 0
                    else:
                        if rotate and key_attr["popup_skb"] != 0:
                            key_attr["popup_skb"] += "_rotate"
                    
                    key_test_info = file_name
                    if tag == "keys":
                        l  = self.parseKeyStruct(key_attr)
                        lable_len = len(l[0])   #label [label_list, unicode_list]
                        key_nums += lable_len
                        for i in xrange(0, lable_len):
                            #start_x += int((float(key_width)))
                            new_attr = {}
                            for m_key in key_attr:
                                if "labels" or "codes" or "splitter" in m_key:
                                    continue
                                new_attr[m_key] = key_attr[m_key]
                            
                            new_attr["code"] = l[1][i]
                            new_attr["key_type"] = keytype
                            new_attr["pos_x"] = str(start_x) 
                            new_attr["pos_y"] = str(start_y)
                            new_attr["width"] = str(key_width)
                            new_attr["height"] = str(key_height)
                            new_attr["label"] = '''L"%s"'''%l[0][i]
                            new_attr["popup_skb"] = key_attr["popup_skb"]
                            icount += 1
                            key_index = row_index +"_" + str(icount)
                            g_key_list.append(new_attr)
                            g_key_index.append(key_index)
                            start_x += int((float(key_width)))
                    else:
                        ############################
                        key_nums += 1
                        key_attr["width"] = str(key_width)
                        key_attr["height"] = str(key_height)
                        key_attr["pos_x"] = str(start_x)
                        key_attr["pos_y"] = str(start_y)
                        #############################
                        key_attr["key_type"] = keytype
                        icount += 1
                        g_key_list.append(key_attr)
                        key_index = row_index +"_" + str(icount)
                        g_key_index.append(key_index)
                        start_x += int((float(key_width)))
            g_row_set[row_index]['row_attr'] = row_attr
            g_row_set[row_index]["key_count"] = key_nums
                    
    def parseKeyStruct(self, key_attr_map): 
        ret_list = []
        split = ""
        if "splitter" in key_attr_map:
              split = key_attr_map["splitter"]
        else:
            print "error.... parseKeyStruct"
            return ret_map
        tlist1 = self.getSplitKey(key_attr_map["labels"], split)         
        tlist = self.getSplitKey(key_attr_map["codes"], split)
        
        ret_list = [tlist1, tlist]
        return ret_list
        
    def getSplitKey(self, keys, split):
        ret_list = []
        if type(keys) == str:
            temp_str = ""
            for i in xrange(0, len(keys)):
                if keys[i] == str(split):
                    ret_list.append(temp_str)
                    temp_str = ""
                    continue
                temp_str += keys[i]
            if temp_str:
                ret_list.append(temp_str)
        elif type(keys) == unicode:
            temp_str = u""
            split = split.decode('utf-8')
            for i in xrange(0, len(keys)):
                if keys[i] == split:
                    ret_list.append(temp_str)
                    temp_str = u""
                    continue
                temp_str += keys[i]
            if temp_str:
                ret_list.append(temp_str)
        else:
            return []
        return ret_list
            
    def parse_keyboard_head(self, attr_map):
        ret_map = {}
        rmap = {}
        for key in attr_map:
            value = attr_map[key]
            if "skb_template" in key:
                rmap = self.getTemplate(value)
                ret_map["skb_template"] = value
                for rkey in rmap:
                    if not attr_map.has_key(rkey):
                        ret_map[rkey] = rmap[rkey]   
            else:
                ret_map[key] = attr_map[key]   
        return ret_map
    
    def formatData(self, attr_map, rotate):
        lcd_size = get_lcd_size()
        format_map= {}
        for key in attr_map:
            value = attr_map[key]
            format_map[key] = value
            if type(value) != str:
                continue
            if "%p" in value:
                format_map[key] = self.getCurrentSize(key,value, rotate)                 
            elif "@drawable" in value:
                format_map[key] = format_draw(key, value)
            elif "@color" in value:
                format_map[key] = format_color(key, value)
            elif "@dimen" in value:
                format_map[key] = format_dim(key, value)
            elif "@xml" in value:
                if "skb_template" in value:
                    format_map.pop(key)
                else:
                    if rotate and "_rotate" not in value:
                        attr_map[key] += "_rotate"
                        value = attr_map[key]
                    ret = format_xml(key, value)
                    format_map[key] = ret
                    
            elif key == "balloon_ratio_height" or key == "balloon_ratio_width":
                format_map[key] = format_map[key].replace("f","")
        return format_map
    
    def formatDataEx(self, attr_map, rotate):
        lcd_size = get_lcd_size()
        format_map= {}
        for key in attr_map:
            value = attr_map[key]
            format_map[key] = value
            if type(value) != str:
                continue
            if "%p" in value:
                format_map[key] = self.getCurrentSize(key,value, rotate)                 
            elif "@drawable" in value:
                format_map[key] = format_draw(key, value)
            elif "@color" in value:
                format_map[key] = format_color(key, value)
            elif "@dimen" in value:
                format_map[key] = format_dim(key, value)
            elif key == "balloon_ratio_height" or key == "balloon_ratio_width":
                format_map[key] = format_map[key].replace("f","")
        return format_map
    
    def getTemplate(self, key):
        key = key.replace("@xml/","")
        global g_template_attr_map
        if key not in g_template_attr_map:
            return {}
        return g_template_attr_map[key]
    
    def getCurrentSize(self,key, value, rotate):
        lcd_size = get_lcd_size()
        value = value.replace("%p","")
        num = float(value)
        
        if "kb_width" in key:     
           if rotate:   
               num *= lcd_size[1]/100.0
           else:
               num *= lcd_size[0]/100.0
           num = int(num)
           value = str(num)
        elif "kb_height" in key:
            if rotate:
                num *= lcd_size[0]/100.0
            else:
                num *= lcd_size[1]/100.0
            num = int(num)
            value = str(num)
        return value
    #
    # template keyboard
    #     
    def parseTemplateXml(self,file_path, file_name, rotate):
        #find template file to deatl it
        global g_keytype_index_map
        global g_template_key_type_list
        global g_template_attr_map
        fcontent = open(file_path, "rb").read()    
        root = ElementTree.fromstring(fcontent)       
        temp = file_name.replace(".xml","")   
        local_attr_map = {}
        local_keytype_list = []
        lcd_size = get_lcd_size()
        
        for key in root.attrib:
            value = root.attrib[key]
            if "%p" in value:
                value = self.getCurrentSize(key,value, rotate)
            elif "@drawable" in value:
                value = format_draw(key, value)
            elif "@color" in value:
                value = format_color(key, value)
            elif "@dimen" in value:
                value = format_dim(key, value)
            local_attr_map[key] = value 
            
        #default value
        if "skb_bg" not in local_attr_map:
            local_attr_map["skb_bg"] = 0
        if "kb_width" not in local_attr_map:
            local_attr_map["kb_width"] = 1
        if "kb_height" not in local_attr_map:
            local_attr_map["kb_height"] = 0.5
        if "key_xmargin" not in local_attr_map:
            local_attr_map["key_xmargin"] = 0
        if "key_ymargin" not in local_attr_map:
            local_attr_map["key_ymargin"] = 0
        if "bg" not in local_attr_map:
            local_attr_map["bg"] = 0
        if "hlbg" not in local_attr_map:
            local_attr_map["hlbg"] = 0
        if "balloonbg" not in local_attr_map:
            local_attr_map["balloonbg"] = 0
        if "balloon_ratio_width" not in local_attr_map:
            local_attr_map["balloon_ratio_width"] = 1
        if "balloon_ratio_height" not in local_attr_map:
            local_attr_map["balloon_ratio_height"] = 1
        
        g_template_attr_map[temp] = local_attr_map
        
        child_list = root._children
        local_attr_map = {}
        
        for i in xrange(0, len(child_list)):
            if child_list[i].tag != "key_type":
                continue
            
            attr = child_list[i].attrib
            if "id" not in attr:
                print "error, id not in attr,keytype!"
                continue
            keytype_index = '''%s%s'''%(temp,attr['id'])
            for key in attr:
                value = attr[key]
                if "@drawable" in value:
                    value = format_draw(key, value)
                elif "%p" in value:
                    value = self.getCurrentSize(key,value, rotate)
                elif "@color" in value:
                    value = format_color(key, value)
                elif "@dimen" in value:
                    value = format_dim(key, value)
                attr[key] = value

            if "balloon_ratio_height" not in attr:
                attr["balloon_ratio_height"] = g_template_attr_map[temp]["balloon_ratio_height"]
            if "balloon_ratio_width" not in attr:
                attr["balloon_ratio_width"] = g_template_attr_map[temp]["balloon_ratio_width"]

            g_template_key_type_list.append(attr)
            g_keytype_index_list.append(keytype_index)

    def computeKeysPos(self, attr):
        if "width" in attr:
            wid = attr["width"].replace("%p","")
            wid = float(wid)
            attr["width"] = int(wid * float(attr["kb_width"])/100)
        
        if "height" in attr:
            height = float(attr["height"].replace("%p",""))
            attr["height"] = int(height * float(attr["kb_height"])/100)
        
        if "key_xmargin" in attr:
            attr["key_xmargin"] = int(float(attr["key_xmargin"].replace("%p",""))*float(attr["kb_width"])/100)
        if "key_ymargin" in attr:
            attr["key_ymargin"] = int(float(attr["key_ymargin"].replace("%p",""))*float(attr["kb_height"])/100)
        return attr
    
    def getKbTypeName(self, file_name):
        ret = ""
        
        if "hwkb" in file_name:
            ret = 'TRAY'
        elif "skb_phn" in file_name:
            ret = 'PHN'
        elif "skb_qwerty" in file_name:
            ret = "QWERTY"
        else:
            ret = "POPUP"
        return ret
