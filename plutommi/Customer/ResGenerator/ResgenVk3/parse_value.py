#######################################################
# parse files in value folder
# author: tqq
#######################################################
from public_def import *
import os
from xml.etree import ElementTree

g_debug = True

class ParseValueXml:
    def __init__(self):
        self.m_str_network_list = []
        self.m_output_path = g_out_put_folder_name

    def parseAllValue(self):
        path = getPrePath("", 2) + "\\VKResourece\\values"
        file_list = os.listdir(path)
        
        for fl in file_list:
            #genreate map key
            temp_path = os.path.join(path, fl)
            if os.path.isfile(temp_path) == False:
                continue
            temp = fl.replace(".xml","")
            g_value_map[temp] = {}
            
            file_path =  path + "\\" + fl
            fcontent = open(file_path, "r").read()
            if fl.find(".xml") != -1:
                if fl.find("address")!= -1:
                    self.parse_address(fcontent,"address")
                elif fl.find("colors")!=-1:
                    self.parse_colors(fcontent,"colors")
                elif fl.find("bihua_for_hkb")!=-1:
                    self.parse_bihua_for_hkb(fcontent,"bihua_for_hkb")
                elif fl.find("dimen")!=-1:
                    self.parse_dim(fcontent,"dimen")
                elif fl.find("string")!=-1:
                    self.parse_string(fcontent,"string")
        return True

    #address xml
    def parse_address(self,file_content,fname):
        file_name = fname
        root = ElementTree.fromstring(file_content)
        num = len(root._children)
        cc_list = root._children
        for i in xrange(0, num):
            self.m_str_network_list.append([])
            self.m_str_network_list[i].append(cc_list[i].attrib["name"])
            for j in xrange(0,len(cc_list[i]._children)):
                self.m_str_network_list[i].append(cc_list[i][j].text)

        #print it all and wirte it to file.
        #print self.m_str_network_list
        g_value_map[file_name] = self.m_str_network_list
        
        #file_name += ".h"
        #file_path = self.m_output_path + file_name
        
        #if g_debug == True:
         #   pass
            #print "OutPut_path%s",file_path
        #obj_file = open(file_path, "w")
        
        #out put string arrays
        output_string = ""
        for cild in xrange(0, len(self.m_str_network_list)):
            gc = self.m_str_network_list[cild]
            if gc == []:
                continue
            array_name = gc[0]
            output_string += "char* "
            output_string += array_name
            output_string += "[]\n{\n"
            for stag in xrange(1, len(gc)):
                output_string += "\""                
                output_string += gc[stag]
                output_string += "\",\n" 
            output_string += "}\n\n"
       # if g_debug == True:
        #    pass
            #print output_string
        #obj_file.write(output_string)

    def parse_bihua_for_hkb(self,file_content,fname):
        file_name = fname
        root = ElementTree.fromstring(file_content)
        child_list = root._children
        map_bihua = {}
        for i in xrange(0, len(child_list)):
            if(child_list[i].attrib.has_key("name")):
                value = child_list[i].attrib["name"]
                map_bihua[value] = []
                cc_list = child_list[i]._children
                temp_list = []
                if cc_list != []:
                    for k in xrange(0, len(cc_list)):
                        temp_list.append(cc_list[k].text)
                    map_bihua[value] = temp_list
        #print map_bihua
        g_value_map[file_name] = map_bihua
            

    def parse_colors(self,file_content,fname):
        file_name = fname
        root = ElementTree.fromstring(file_content)
        child_list = root._children
        color_map = {}
      
        #if g_debug:
            #write_buffer = ""
        for i in xrange(0,len(child_list)):
            if child_list[i].attrib.has_key("name"):
                value = child_list[i].attrib["name"]
                color = child_list[i].text
                color = color.replace("#","")
                temp_color = "0x"
                if len(color) < 8:
                    for i in xrange(0, 8 - len(color)):
                        temp_color += 'f'
                        #print temp_color
                    temp_color += color
                else:
                    temp_color += color
                
                #if g_debug:
                 #   write_buffer += "\n#define\t\t\t"
                  #  write_buffer += value
                   # write_buffer += "\t\t\t"
                    #write_buffer += temp_color
                color_map[value] = temp_color
                #type swap
        #print color_map
        #if g_debug:
         #   file_path  = ""
          #  file_path = file_name + ".h"
           # file = open(file_path, "w")
            #file.write(write_buffer)
            #file.flush()
            #file.close()
        g_value_map[file_name] = color_map
        

    #string include single string and string array.
    def parse_string(self,file_content,fname):
        file_name = fname
        root = ElementTree.fromstring(file_content)
        child_list = root._children
        string_map = {}
        write_buffer = ""
        for child in child_list:
            if child.tag == "string" and child.attrib.has_key("name"):
                temp_string = ""
                string_name = child.attrib["name"]
                string = child.text
                temp_string += "\""
                temp_string += string
                temp_string += "\""
                string_map[string_name] = temp_string
                write_buffer += "\n"
                write_buffer += "#define \t\t"
                write_buffer += string_name
                write_buffer += "\t\t\t"
                write_buffer += temp_string
        g_value_map[file_name] = string_map
        #write it to file
        file_name += ".h"
        file_path = self.m_output_path + "\\" + file_name
        file = open(file_path,"w")
        file.write(write_buffer)
        file.flush()
        file.close()
        return True

    def parse_dim(self,file_content,fname):
        file_name = fname
        root = ElementTree.fromstring(file_content)
        child_list = root._children
        dim_map = {}
        
       # if g_debug:
        #        write_buffer = ""
                
        for i in xrange(0, len(child_list)):
            tag = child_list[i].tag
            attr = child_list[i].attrib
            #print tag
            key = ""
            value = ""
            if attr.has_key("name"):
                key = attr["name"]
                value = child_list[i].text
            else:
                continue
            
            #sp parse
            if "sp" in value:
                tsp = GetSp()
                if tsp != 0:
                    value+= str(tsp)
                    value = value.replace("sp", "*")
                    value += "/160"
            elif "dip" in value:
                value = value.replace("dip", "")
                value+="/160"
            if tag not in dim_map:
                dim_map[tag] = {}
            dim_map[tag][key] = value
            
          #  if g_debug:
           #     write_buffer += "\ntag:\t"
            #    write_buffer += tag
             #   if tag == "integer":
              #      write_buffer += "\t"*4
              #  else:
               #     write_buffer += "\t"*5
                #write_buffer += key
                #write_buffer += "\t"*10
                #write_buffer += value
        #print dim_map
        
        #write to file to test
       # if g_debug:
        #    file_name += ".h"
         #   file = open(file_name, "w")
          #  file.write(write_buffer)
          #  file.flush()
           # file.close()
            
        g_value_map[fname] = dim_map
        return True

