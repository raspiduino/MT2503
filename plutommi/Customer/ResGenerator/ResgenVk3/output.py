#coding UTF-8
from public_def import *
import os


class CGen:
    def __init__(self):
        self.m_keylist_name = "keyTable"
        self.m_rowlist_name = "rowTable"
        self.m_kblist_name = "keyBoardTable"
        self.m_keytype_list_name = "keyTypeTable"
        self.m_key_struct_name = "gui_virtual_keyboard_keytype_struct"
        self.m_row_struct_name = "gui_virtual_keyboard_row_struct"
        self.m_toggle_struct_name = "gui_virtual_keyboard_togglekey_struct"
        self.m_kb_struct_name = "wgui_virtual_keyboard_layout_struct"
        self.m_toggle_file = "toggle"
        self.m_togle_state_list = "stateListTable"
        self.m_toggle_list = "toggleStructTable"
        self.m_toggle_key_name = "toggleKeyTable"
        self.m_folder = g_out_put_folder_name
        self.m_output_file = self.m_folder + "virtual_keyboard3_res.h"
        self.m_ptr_toggle_state = "toggleKeyPtrTable"
        self.m_ptr_toggle_state_list = []
        
    
    def genStructs(self):
        global g_out_put_folder_name
        global g_out_put_file
        
        file_path = g_out_put_folder_name + g_out_put_file_head
        if not os.path.exists(g_out_put_folder_name):
            os.mkdir(g_out_put_folder_name)
        files = os.listdir(g_out_put_folder_name)
        for f in files:
            os.remove(g_out_put_folder_name+f)
    
    def genKeyBoardEnum(self):
        global g_kb_type_enum_list
        file_path = g_out_put_folder_name + g_out_put_file_head
        file = open(file_path,'a')
        
        buf = '''\n\ntypedef enum gui_virtual_keyboard_language\n{\n'''
        for type in g_kb_type_enum_list:
            if type == "GUI_VIRTUAL_KEYBOARD_MAX_LANG":
                continue
            buf += '\t' + type + ',\n'
        buf += "  GUI_VIRTUAL_KEYBOARD_MAX_LANG\n"
        buf += '''}gui_virtual_keyboard_language_enum;'''
        
        file.write(buf)
        file.flush()
        file.close()
        
    def genKeyList(self):
        head = '''
#ifdef __MMI_IME_V3__

#ifndef __VIRTUAL_KEYBOARD3_DEFINE_H__
#define __VIRTUAL_KEYBOARD3_DEFINE_H__\n\n
'''
      #  head += '''#include "%s"\n'''%(g_out_put_file_head)
        head += '''#include "mmi_rp_srv_vk3_def.h"
#include "Lcd_sw_inc.h"
#include "mmi_rp_srv_input_method_def.h"\n\n '''
                   
        head += '''
extern const wgui_virtual_keyboard_layout_struct        keyBoardTable[];
extern const gui_virtual_keyboard_togglekey_struct    toggleStructTable[];
extern const gui_virtual_keyboard_key_struct     toggleKeyTable[];
extern const gui_virtual_keyboard_key_struct*  toggleKeyPtrTable[];
#ifdef __IMEHW_DCM_SUPPORT__
#include "dcmgr.h"
#pragma arm section rodata = "DYNAMIC_CODE_VKLAYOUT_RODATA"
#endif
\n\n'''
        key_buf = head + '''\n\n\nconst gui_virtual_keyboard_key_struct  \t%s[] = \n{\n'''%(self.m_keylist_name)
        def_buf = ""
        global g_key_list
        global g_key_index
        
        f = g_out_put_folder_name + g_out_put_file
        file = open(f, 'ab')
        file.write(key_buf)
        
        print 'len(g_key_list)*56 =',len(g_key_list)*56
        for ikey in xrange(0, len(g_key_list)):
            file.write('\n\t{\n\t')
            file.write('''\t/* index %s */\n'''%(ikey))
            file.write('''\t /* file_index: %s */ \n'''%(g_key_index[ikey]))
            key_attr = g_key_list[ikey]
            end_pos = len(g_key_attr)
            for index in xrange(0,len(g_key_attr)):
                attr = g_key_attr[index]
                if attr in key_attr:
                    if attr == 'code_longpress':
                        if ('\u') in key_attr[attr]:
                            key_attr[attr] = key_attr[attr].replace("\\u","0x")
                        else:
                            code = key_attr[attr]
                            ret = translateUnicode(code)
                            if ret != "":
                                key_attr[attr] = ret
                    if attr == 'code':
                        if ('\u') in key_attr[attr]:
                            key_attr[attr] = key_attr[attr].replace("\\u","0x")
                        else:
                            code = key_attr[attr]
                            ret = translateUnicode(code)
                            if ret != "":
                                key_attr[attr] = ret
                    if attr == "popup_skb":
                        popup_kb_offset = None
                        if (key_attr[attr] != '0') and (key_attr[attr] != 0):
                            if "@xml" in key_attr[attr]:
                                popup_kb_offset =  format_xml(attr,key_attr[attr])
                                file.write('\t\t')
                                if popup_kb_offset == "-1":
                                    file.write("0")
                                else:
                                    buf = self.m_kblist_name + "+" + popup_kb_offset
                                    print buf
                                    file.write(buf)
                            file.write(",\t\t\t")
                            file.write('''/* %s */\n'''%(attr))
                        else:
                            file.write('\t\t')
                            file.write("0")
                            file.write(",\t\t\t")
                            file.write('''/* %s */\n'''%(attr))
                    elif attr == "toggle_index":
                        if "toggle_index" in key_attr:
                            file.write('\t\t')
                            file.write(self.m_toggle_list + "+" + str(key_attr["toggle_index"]))
                            file.write('\t\t\t')
                            file.write('''/* %s */\n'''%(attr))
                        else:
                            file.write('\t\t')
                            file.write("0")                
                            file.write('\t\t\t')
                            file.write('''/* %s */\n'''%(attr))
                    else:
                        tt = key_attr[attr]
                        obj = None
                        if type(tt) == unicode:
                            obj = repr(tt)
                            if "\\u" in obj:
                                obj = obj.replace("\\u", "\\x")
                        else:
                            obj = tt
                        if obj and obj[0] == 'u':
                           obj = obj[1:]
                           obj = obj[1:len(obj)-1]
                        if obj == None:
                            obj = "0"
                        file.write('\t\t')
                        try:
                            file.write(obj)
                        except:
                            print "error....."
                        file.write(",\t\t\t")
                        file.write('''/* %s */\n'''%(attr))
                           
                else:
                    if attr == "toggle_index":
                        file.write('\t\t')
                        file.write("0")                
                        file.write("\t\t\t")
                        file.write('''/* %s */\n'''%(attr))
                    else:
                        file.write('\t\t')
                        file.write("0")                
                        file.write(",\t\t\t")
                        file.write('''/* %s */\n'''%(attr))
                
            file.write("\t},\t\n")
        file.write("};\n\n")
        file.flush()
        file.close()
    
    def genKeyTypeList(self):
        global g_template_key_type_list
        
        buf = '''const gui_virtual_keyboard_keytype_struct\t%s[] = \n{'''%(self.m_keytype_list_name)
        print 'len(g_template_key_type_list)*56 = ',len(g_template_key_type_list)*56
        for key in xrange(0,len(g_template_key_type_list)):
            type_map = g_template_key_type_list[key]
            buf += '''\n\t{\n'''
            buf += '''\t\t/* index %s */\n'''%(key)
            l = len(g_template_keytype_name)
           # for attr in g_template_keytype_name:
            for index in xrange(0, l):
                attr = g_template_keytype_name[index]
                if attr not in type_map:
                    if index == l-1:
                        buf += '''\t\t%s\t\t\t/*%s*/\n'''%(str(0),attr)
                    else:
                        buf += '''\t\t%s,\t\t\t/*%s*/\n'''%(str(0),attr)
                else:
                    if "text" in attr and "size" in attr:               
                        convert_str = "(U8)"
                        output_str = "(" + str(type_map[attr]) + ")"
                    else:
                        convert_str = ""
                        output_str = str(type_map[attr])
                    if index == l-1:
                        buf += '''\t\t%s%s\t\t\t/*%s*/\n'''%(convert_str,output_str,attr)
                    else:
                        buf += '''\t\t%s%s,\t\t\t/*%s*/\n'''%(convert_str,output_str,attr)
            buf += "\t},\n"
        buf += "\n};\n\n"
        
        file = open(self.m_output_file, "a")
        file.write(buf)
        file.flush()
        file.close()
        
    def genRowList(self):
        # judge this data whether correct.
        global g_row_set
        global g_row_set_index_list
        
        write_buffer = ""
        row_id = ""
        
        write_buffer += '''const %s\t\t%s[] = \n{\n'''%(self.m_row_struct_name,self.m_rowlist_name)
        print 'row list, g_row_set_index_list * 8=',len(g_row_set_index_list)* 8
        for index in g_row_set_index_list:
            write_buffer += '''\t\t/* index %s */\n'''%(g_row_set_index_list.index(index))
            row_ret = self.get_row_data(index) 
            row_id = 0
            key_count = ""
            offset = 0
            
            if index in g_row_set:
                key_count = g_row_set[index]["key_count"]
                row_id = g_row_set[index]['row_attr']['row_id']
            key_index = index + "_1" #'_1 means from first key start'
            if key_index in g_key_index:
                offset = g_key_index.index(key_index)
            else:
                print "error: ", key_index, "not in key index."
            
            write_buffer += '''\t{\t%s,'''%(str(row_id))
            write_buffer += '''\t%s,'''%(str(key_count))
            write_buffer += '''\t%s+%s\t},'''%(self.m_keylist_name,str(offset))
            write_buffer += '''\t\t/* %s */\n'''%(index)
        
        write_buffer += "};\n\n"
        fobj = open(self.m_output_file, "a")
        fobj.write(write_buffer)
        fobj.flush()
        fobj.close()
        
    def genKeyBoardList(self):
        global g_kb_list
        global g_row_set_index_list
        
        write_buffer = "const "
        tag = ",\t"
        write_buffer += self.m_kb_struct_name + "\t\t" + self.m_kblist_name + "[] = \n{\n"
        offset = 0
        print '(len(g_kb_list)+1)* 28=',(len(g_kb_list)+1)*28
        for couter in xrange(0, len(g_kb_list)):
            kb = g_kb_list[couter]
            write_buffer += '''\t\t/* index %s : %s */\n'''%(couter,g_kb_index_list[couter])
            write_buffer += '''\t{\n\t\t%s,\t\t\t/*keyboard height*/\n'''%(str(kb["kb_height"]))
            write_buffer += '''\t\t%s,\t\t\t/*keyboard width*/\n'''%(str(kb["kb_width"]))
            if "skb_bg" in kb:
                write_buffer += '''\t\t%s,\t\t\t/*skb_bg*/\n'''%(str(kb["skb_bg"]))
            else:
                write_buffer += '''\t\t-1,\t\t\t/*skb_bg*/\n'''
            
            row_index = kb["row_index"] + "_0"
            offset = g_row_set_index_list.index(row_index)
            
            write_buffer += '''\t\t%s,\t\t\t/*key_xmargin*/\n'''%(str(kb["key_xmargin"]))
            write_buffer += '''\t\t%s,\t\t\t/*key_ymargin*/\n'''%(str(kb["key_ymargin"]))
            write_buffer += '''\t\t%s,\t\t\t/*row_num*/\n'''%(str(kb["row_num"]))
            write_buffer += '''\t\t%s+%s,\t\t\t/*rowlist_pointer*/\n'''%(self.m_rowlist_name,str(offset))
            write_buffer += '''\t\t%s,\t\t\t/*gui_virtual_keyboard_language_enum*/\n'''%(kb["gui_virtual_keyboard_language_enum"])
            write_buffer += '''\t\t%s,\t\t\t/*vk_attribute*/\n'''%(str(kb["vk_attribute"]))
            write_buffer += '''\t\t%s,\t\t\t/*is_rotate*/\n'''%("MMI_TRUE" if kb["is_rotate"] else "MMI_FALSE")
            write_buffer += '''\t\t%s,\t\t\t/*is_shift_spport*/\n'''%("MMI_TRUE" if kb["is_shift_spport"] else "MMI_FALSE")
            write_buffer += '''\t\t%s,\t\t\t/*is_cache*/\n'''%("MMI_TRUE" if kb["is_cache"] else "MMI_FALSE")
            index = kb["skb_template"]+'0'#kb["key_type"]
            keytype_offset = g_keytype_index_list.index(index)
            
            write_buffer += '''\t\t%s+%s\t\t\t/*%s*/\n'''%(self.m_keytype_list_name,str(keytype_offset),index)
            write_buffer += "\t},\n"
            
        #the last keyboard item
        #update on 2011.12.15
        last_keyboard =  '''
  {
    0,  //height
    0,  //width
    0,  //background image id
    0,  //margin_x x
    0,  //margin_y y
    0,  //row num
    NULL,    //row_list
    GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY,    //keyboard type
    0,  //vk_attribute
    MMI_FALSE,  //is rotate
    MMI_FALSE,  //is shift support
    MMI_FALSE,  //is chache
    NULL    //key type list
  },\n'''
        
        write_buffer += last_keyboard            
        write_buffer += "};"
        
        fobj = open(self.m_output_file, "a")
        fobj.write(write_buffer)
        fobj.flush()
        fobj.close()
        
        
    def get_row_data(self, index):
        file_name = ""
        row_id = ""
        for i in index:
            if i=="_":
                file_name += row_id
                row_id = ""
            row_id += i
        row_id = row_id.replace("_","")
        return [row_id, file_name]
        
    def genStructContent(self):
        global g_key_index
        file = self.m_folder + "content.txt"
        f = open(file, "w")
        for key in g_key_index:
            f.write(key)
            f.write("\n")
            
        f.flush()
        f.close()
    
    #################################################################################
    #  flag       stateNum
    #  |          |              |
    #  | | | | | | | | | | | | | | toggle key struct
    #  | | | | | | | | | | | | | | toggle state id 
    ################################################################################
    def genToggleStateList(self):
        global g_toggle_state_id_list
        global g_toggle_state_index_list
        global g_toggle_key_list
        
        file = open(self.m_output_file, "a")
        file.write('''\n\nconst U8\t%s[] = \n{\n'''%self.m_togle_state_list)
        print 'len(g_toggle_state_id_list)* 1=',len(g_toggle_state_id_list)*1
        #toggle state id 
        for i in xrange(0,len(g_toggle_state_id_list)):
            file.write('''\t%s,'''%str(g_toggle_state_id_list[i]))
            file.write('''\t\t/*index %s*/\n'''%(i))
        file.write("};\n\n")
        
        buf = '''const gui_virtual_keyboard_key_struct\t %s[] = \n{\n'''%self.m_toggle_key_name
        
        print 'len(g_toggle_key_list)*56=',len(g_toggle_key_list)*56
        for i in xrange(0, len(g_toggle_key_list)):
            attr = g_toggle_key_list[i]
            buf += "\t{\n"
            if "state_id" in attr:
                buf += '''\t\t/* index %s, state id %s */ \n'''%(i, attr["state_id"])
            else:
                buf += '''\t\t/* index %s, state id not config!!!! */ \n'''%(i)
                
            for index in xrange(0,len(g_key_attr)):
                i = g_key_attr[index]
                if i in attr:
                    if i == "popup_skb":
                        popup_kb_offset = None
                        if (attr[i] != '0') and (attr[i] != 0):
                            if "@xml" in attr[i]:
                                popup_kb_offset =  format_xml(i,attr[i])
                                if popup_kb_offset == "-1":
                                    buf += "0"
                                else:
                                    buf += self.m_kblist_name + "+" + popup_kb_offset
                        else:
                            buf += "0"
                        buf += ",\t\t\t /*popup_skb*/"
                        continue
                    if i in ["pos_x","pos_y","height","width"]:
                        attr[i] = int(float(attr[i]))
                    if ('label' in i):
                        if type(attr[i]) == unicode:
                            attr[i] = repr(attr[i])
                            if attr[i][0] == "u":
                                attr[i] = attr[i][2:len(attr[i])-1]
                                attr[i] = attr[i].replace("\\u", "\\x")
                                attr[i] = "L" + '''"%s"'''%(attr[i])
                        else:
                            attr[i] = 'L' + '''"%s"'''%(attr[i])
                        if index == len(g_key_attr)-1:
                            buf += '''\t\t"%s"'''%(attr[i])
                        else:
                            buf += '''\t\t '''"%s"''','''%(attr[i])
                        buf += '''\t\t /*%s*/ \n''' %i
                    elif ('code' in i):
                        ret = translateUnicode(attr[i])
                        if ret != "":
                            if index == len(g_key_attr)-1:
                                buf += '''\t\t%s'''%str(ret)
                            else:
                                buf += '''\t\t%s,'''%str(ret)
                            buf += '''\t\t /*%s*/ \n''' %i
                        else:
                            if index == len(g_key_attr)-1:
                                buf += '''\t\t%s'''%str(attr[i])
                            else:
                                buf += '''\t\t%s,'''%str(attr[i])
                            buf += '''\t\t /*%s*/ \n''' %i
                    else:
                        if index == len(g_key_attr)-1:
                            buf += '''\t\t%s'''%str(attr[i])
                        else:
                            buf += '''\t\t%s,'''%str(attr[i])
                        buf += '''\t\t /*%s*/ \n''' %i
                else:
                    if index == len(g_key_attr)-1:
                        buf += '''\t\t0 \t\t\t  /*%s*/\n'''%i
                    else:
                        buf += '''\t\t0,\t\t\t  /*%s*/\n'''%i
            buf += "\t},\n\n"
        buf += "};\n\n"
        file.write(buf)
        file.flush()
    
        #output key pointer array
        buf = '''const gui_virtual_keyboard_key_struct*\t%s[] = \n{\n'''%(self.m_ptr_toggle_state)
        cnt = 0
        for state in g_toggle_state_index_list:
            flag = state['index_count']
            buf += '''\t\t\t/*index:%d*/\n'''%(cnt)
            buf += '''\t%s+%d,\n'''%(self.m_toggle_key_name, flag)
            cnt += 1
        buf += '};' 
        file.write(buf)
        
        file.write("\n\n const gui_virtual_keyboard_togglekey_struct\t")
        file.write(self.m_toggle_list + "[] = \n{\n")
        buf = ""
        count = 0
        print 'g_toggle_state_index_list * (12+4)=',len(g_toggle_state_index_list)*(12+4)
        for state_struct in g_toggle_state_index_list:
            buf += "\t{\n"
            buf += '''/* index: %d */\n'''%(g_toggle_state_index_list.index(state_struct))
            num = state_struct["state_num"]
            flag = state_struct["index_count"]
            buf += '''\t\t%s,\t\t\t/* state_num */\n'''%str(num)
            buf += '''\t\t%s+%s,\t\t\t/* toggle_stateid pointer */\n'''%(self.m_togle_state_list, str(flag))
            buf += '''\t\t%s+%s\t\t\t/* toggle_key pointer */\n'''%(self.m_ptr_toggle_state, count)
            count += 1
            buf += "\t},\n\n"
        buf += "};"
        file.write(buf)
        end = '''\n\n\n
#ifdef __IMEHW_DCM_SUPPORT__
#pragma arm section rodata
#endif

#endif    
#endif //__MMI_IME_V3__   '''
        file.write(end)
        file.flush()
        file.close()
                    
            
def translateUnicode(code):
    global g_map_unicode
    ret_value = ""
    if type(code) != str:
        code = str(code)   
    if code in g_map_unicode:
        ret_value = g_map_unicode[code]
    return ret_value
