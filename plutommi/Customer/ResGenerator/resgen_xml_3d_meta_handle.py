import sys
import os
import StringIO
import traceback
import time
import struct
import re
import shutil

from xml.sax import make_parser, handler, SAXParseException
from resgen_offline_param import ResPopParam, BinaryResParam, ResParamModel, BinaryParamTextFileDAO, ResReportHelper
from resgen_log import ResgenLog

# global variables
TAG ='RESGEN_XML_3D_META_HANDLE'
binary3d_content = []
image_content = []
res_base_table = {}
binary3d_name_id_map = {}
image_name_id_map = {}
populated_image_name_id_map = {}
populated_binary3d_name_id_map = {}
theme_root_path = ''

class Context(object):
    pass

def parsePath(raw_string):
    paths = [i for i in raw_string.split('"') if i.strip()]
    if not paths:
        return ''

    for i in range(len(paths) ):
        paths[i] = paths[i].replace('\\\\', '\\').replace('\\\\', '\\')

    result = ''
    for p in paths:
        if not p:
            continue
        if result and result[-1] != '\\' and p[0] != '\\':
            result = result + '\\' + p
        else:
            result = result + p
    return result


####################################################
# Class:      ResgenXMLParser(handler.ContentHandler)
# Description:Parse the RES file and provide methods
#             to retrive the parsed result
####################################################

class ResgenXMLParser(handler.ContentHandler):
    TAG = "ResgenXMLParser"
    def __init__(self, resFilePath):
        self._last_token = None
        self._current_resFilePath = resFilePath

        self._context = {}
        # parsing tags: image and binary3d
        self._context_names = ('image', 'binary3d')
        for context_name in self._context_names:
            self._context[context_name] = Context()
            self._context[context_name].id = None
            self._context[context_name].base_path = None
            self._context[context_name].content = None


    def startElement(self, name, attrs):
        name = name.lower()
        self._last_token = name
        if name in self._context_names:
            if 'id' in attrs:
                self._context[name].id = attrs['id']
            if 'base_path' in attrs:
                self._context[name].base_path = attrs['base_path']

    def endElement(self, name):
        name = name.lower()
        if name in self._context_names:
            if name == 'binary3d':
                self.handle_binary3d()
            elif  name == 'image':
                self.handle_image()
            #reset the parsing context
            self._context[name].id = None
            self._context[name].content = None
            self._context[name].base_path = None


    def characters(self, content):
        content = content.strip()
        if not content:
            return
        content = res_macro_replace(content)
        name = self._last_token
        if name in self._context_names:
            if not self._context[name].content:
                self._context[name].content = content
            else:
                self._context[name].content += content

    def handle_binary3d(self):
        context = self._context['binary3d']
        if not context.id:
            ResgenLog.w(ResgenXMLParser.TAG,'handle_binary3d: id is None')
            return

        if not context.content:
            ResgenLog.w(ResgenXMLParser.TAG,'handle_binary3d: content is None')
            return
            
        if check_if_resource_populated(context.id,populated_binary3d_name_id_map):
            ResgenLog.w(ResgenXMLParser.TAG, 'Meta resource has been populated, Skip: '+ context.id)
            return

        content = parsePath(context.content)
        self.process_binary3d('MMI3DRESOURCE', context.id, content, context.base_path)

    def handle_image(self):
        context = self._context['image']
        if not context.id:
            ResgenLog.w(ResgenXMLParser.TAG, 'handle_image: id is None')
            return

        if not context.content:
            #print 'content is None'
            return

        if check_if_resource_populated(context.id, populated_image_name_id_map):
            ResgenLog.w(ResgenXMLParser.TAG, 'Meta resource has been populated, Skip: '+ context.id)
            return

        content = parsePath(context.content)
        self.process_image('MMI3DRESOURCE', context.id, content)

    def process_binary3d(self, app_id, id, content, base_path):
        global binary3d_content
        global res_base_table
        if base_path == 'current':
            content = os.path.join('..\\..\\', res_base_table[app_id][2], content)
        #    print 'content:', content
        binary3d_content.append((app_id, id, content, self._current_resFilePath) )

    def process_image(self, app_id, id, content):
        global image_content
        image_content.append( (app_id, id, content) )

####################################################
# Method:      parse_xml_file(filename)
# Description: Parsing the resource file 
####################################################
def parse_xml_file(filename):
    global TAG
    content = res_to_xml(filename);

    if not content:
        return

    ResgenLog.v(TAG, 'Parse ' + filename)
    parser = make_parser()
    parser.setContentHandler(ResgenXMLParser(filename))
    try:
        parser.parse(StringIO.StringIO(content) )
    except SAXParseException:
        ResgenLog.e(TAG, 'Exception occured when parsing: ' + filename)
        e = sys.exc_info()[1]
        print 'filename: ', filename
        print 'error:', e
        print content.split('\n')[e._linenum - 1]


####################################################
#  Method:      parse_3d_meta_res_files()
#  Description: Search and populate all meta res depend 
#               on 3D resource declared by user
####################################################
def parse_3d_meta_res_files():
    global populated_image_name_id_map
    global populated_binary3d_name_id_map
    
    cnt = 0
    binary3DResParamModel = ResParamModel('BINARY_3D_DEV',0)
    binary3DResParamModel.loadFromRepository(ResParamModel.DEFAULT_REPO_BINARY_3D_DEV)
    meta_res_path = get_3d_meta_res_paths(binary3DResParamModel)
    
    # save the meta_res_path to log file
    meta_res_path_log_file = file('temp\\resgen_log_3d_meta_res_path.log','w')
    for one_res_path in meta_res_path:
        meta_res_path_log_file.write(one_res_path+'\n')
    
    populated_image_name_id_map = get_res_id_name_map('temp\\mmi_rp_image_id_map.txt')
    populated_binary3d_name_id_map = get_res_id_name_map('temp\\mmi_rp_binary3d_id_map.txt')
    
    for a_file in meta_res_path:
        parse_xml_file(a_file)
        cnt+=1
    return cnt
    
####################################################

def load_res_base_table():
    global res_base_table
    in_file = file('debug/resgen_base_table.txt')

    for line in in_file.readlines():
        if line.startswith('min'):
            continue
        entries = line.strip().split()
        entries = [i for i in entries if i]
        start_id = int(entries[0])
        end_id = int(entries[1])
        app_name = entries[2]
        if len(entries) >= 4:
            res_path = entries[3]
        else:
            res_path = ''
        if app_name not in res_base_table:
            res_base_table[app_name] = (start_id, end_id, res_path)
            
    #Add the 3D resgen app range after APP_DEFAULT_END and END
    last_app_entry=res_base_table['APP_DEFAULT_END']
    res_base_table['END']=(last_app_entry[1]+1,last_app_entry[1]+2,'END','')
    res_base_table['MMI3DRESOURCE']=(last_app_entry[1]+3,65535,'MMI3DResource','')


def gen_header_name_for_app(app_name):
    return 'mmi_rp_' + app_name.lower() + '_def.h'


def gen_name_from_path(path):
    result = path.upper()
    result = result.replace('\\', '__').replace('.', '__')
    return result


def get_layout_count(app_name):
    count = 0
    layout_data_file_name = 'debug/vxml/' + app_name.lower() + '.txt'
    if not os.path.exists(layout_data_file_name):
        return 0
    layout_data_file = file('debug/vxml/' + app_name.lower() + '.txt')
    for line in layout_data_file:
        if line.strip():
            count += 1
    return count


def output_binary3d_header_for_app(app_name, id_list, enum_postfix):
    if len(id_list) == 0:
        return

    header_name = '..\\..\\Customer\\CustomerInc\\' + gen_header_name_for_app(app_name)
    out_file = file(header_name, 'a')

    out_file.write('/******************** 3D resource IDs - Begin ********************/\n')
    out_file.write('typedef enum\n')
    out_file.write('{\n')

    dup_id = set()
    global binary3d_name_id_map
    global res_base_table
    base_id = res_base_table[app_name.upper()][0]
    current_id = base_id + 1
    current_id += get_layout_count(app_name)
    first_id = True

    for entry in id_list:
        if not binary3d_name_id_map.has_key(entry[0]):
            if first_id:
                first_id = False
                out_str = '    ' + entry[0] + ' = ' + str(current_id) + ',\n'
            else:
                out_str = '    ' + entry[0] + ',\n'
            binary3d_name_id_map[entry[0] ] = current_id
            current_id += 1
            out_file.write(out_str)

    out_file.write('} mmi_rp_' + app_name.lower() + '_' + enum_postfix +';\n')

    out_file.write('/******************** 3D resource IDs - End ********************/\n')
    out_file.close()


def process_binary_3d(binary3DResModel, dbPath):
    global binary3d_content
    global TAG
    content_map_by_app = {}

    for entry in binary3d_content:
        if entry[0] not in content_map_by_app:
            content_map_by_app[entry[0] ] = []

        content_map_by_app[entry[0] ].append( (entry[1], entry[2]) )

    for app_name in content_map_by_app:
        output_binary3d_header_for_app(app_name, content_map_by_app[app_name], 'binary3d_enum')

    for entry in binary3d_content:
        #using stdandard offline resgen Data Access API and meta file to save the parameter
        try:
            if (len(entry)>=4) and (entry[1] in binary3d_name_id_map):
                idEnumValue = binary3d_name_id_map[entry[1]]
                idEnumString = entry[1]
                description = 'Generated by Resgen_XML'
                resFilePath = entry[3]
                noCompiling = 1
                binaryType = 0
                binaryFilePath = entry[2]
                temp = BinaryResParam(idEnumValue,idEnumString,resFilePath,description,noCompiling,binaryType,binaryFilePath)
                temp.setAppId(entry[0])
                binary3DResModel.add(temp)
        except:
            ResgenLog.e(TAG, 'process_binary_3d: exception when parsing entry: <'+ entry +'>')
            print '\n', '-'*20, "python exception start", '-'*20
            traceback.print_exc(file=sys.stdout)
            print '-'*20, "python exception  end ", '-'*20 
    
    binary3DResModel.flush(dbPath)


def process_image():
    global image_content
    content_map_by_app = {}
    for entry in image_content:
        if entry[0] not in content_map_by_app:
            content_map_by_app[entry[0] ] = []
        # entry[1] is ENUM ID value, entry[2] is path
        content_map_by_app[entry[0] ].append( (entry[1], entry[2]) )

    global image_name_id_map
    for app_name in content_map_by_app:
        base_id = res_base_table[app_name.upper()][0]
        current_id = base_id + 1
        id_list = content_map_by_app[app_name]
        for entry in id_list:
            if not image_name_id_map.has_key(entry[0]):
                image_name_id_map[entry[0] ] = current_id
                current_id += 1

    for app_name in content_map_by_app:
        output_binary3d_header_for_app(app_name, content_map_by_app[app_name],'image3d_enum')
                
    output_3d_image_populate = file('temp\\mmi_rp_image_populate_with_meta.txt', 'w')

    for entry in image_content:
        out_str = str(image_name_id_map[entry[1]] ) + ' ' + entry[2] + '\n'
        output_3d_image_populate.write(out_str)

    output_3d_image_populate.close()

def output_id_map():
    shutil.copy('temp\\mmi_rp_image_id_map.txt', 'temp\\mmi_rp_image_id_map_with_meta.txt')
    image_map_file = file('temp\\mmi_rp_image_id_map_with_meta.txt', 'a')
    for name in image_name_id_map:
        image_map_file.write(name + ' ' + str(image_name_id_map[name]) + '\n')
    image_map_file.close()

    image_map_file = file('temp\\mmi_rp_image_id_map_only_meta.txt', 'w')
    for name in image_name_id_map:
        image_map_file.write(name + ' ' + str(image_name_id_map[name]) + '\n')
    image_map_file.close()

    shutil.copy('temp\\mmi_rp_binary3d_id_map.txt', 'temp\\mmi_rp_binary3d_id_map_with_meta.txt')
    binary3d_map_file = file('temp\\mmi_rp_binary3d_id_map_with_meta.txt', 'a')
    for name in binary3d_name_id_map:
        binary3d_map_file.write(name + ' ' + str(binary3d_name_id_map[name]) + '\n')
    binary3d_map_file.close()

####################################################
# Method:        meta_res_default_macro_replace
# Description:   Replace the default macro in 3D res 
#                files
####################################################
def res_macro_replace(str_content):
    global theme_root_path
    macro_replace_list= {'\"':'','RES_THEME_ROOT':theme_root_path,'RES_BIN_V3D_THEME_ROOT':theme_root_path,'RES_BIN_V3D_COMMON_PATH':theme_root_path + '\\\\\\\\Default\\\\\\\\3D\\\\\\\\Common\\\\\\\\','RES_BIN_V3D_COMMON_SHADER_PATH':theme_root_path +'\\\\\\\\Default\\\\\\\\3D\\\\\\\\Common\\\\\\\\Shader\\\\\\\\','RES_BIN_V3D_COMMON_IMAGE_PATH':theme_root_path +'\\\\\\\\Default\\\\\\\\3D\\\\\\\\Common\\\\\\\\Image\\\\\\\\'}
    for old_item,new_item in macro_replace_list.items():
        str_content=str_content.replace(old_item,new_item)
    return str_content


####################################################
# Convert RES FILE to XML Document
####################################################
def res_to_xml(filename):
    xml_file = file(filename, 'r')
    content = '<?xml version="1.0" encoding="UTF-8"?>\n<venusxml>\n'
    in_xml = False

    for line in xml_file.readlines():

        if line.startswith('#'):
            continue

        striped = line.strip()
 
        if striped.startswith('<!--') and striped.endswith('-->'):
            continue
                
        line = re.sub("<!---*", "<!-- ", line)
        line = re.sub("-*-->", " -->", line)

        if not line:
            continue

        content += line
    
    if content:
        content += '</venusxml>\n'
    content = content.strip()
    
    return content
####################################################


####################################################
#  Method:      get_3d_meta_res_paths
#  Description: Search all meta res depend on 3D 
#               resource declared by user
####################################################
def get_3d_meta_res_paths(dev3DBinaryModel):
    mmi_3d_meta_res_path = set()
    for item in dev3DBinaryModel.items:
        if not item:
            continue
        file_name = item.binaryFilePath
        
        if file_name:
            folder = os.path.split(file_name)[0]
            res_path = os.path.join(folder, os.path.split(folder)[1] + ".res")
            if os.path.isfile(res_path):
                mmi_3d_meta_res_path.add(res_path)

    result = list(mmi_3d_meta_res_path)
    result.sort()
    return result

####################################################
#  Main Controller
####################################################
def main():
    global TAG
    start_time = time.time()
    ResgenLog.v(TAG, 'Auto generate 3D res from image.zip - Start')

    ResgenLog.v(TAG,  'load resource range...')
    load_res_base_table()
    
    ResgenLog.v(TAG,  'Start to write 3D meta data to headers')
     
    write_mmi_3d_header_start()
    
    ResgenLog.v(TAG,'parse res files...')
    c = parse_3d_meta_res_files()
    ResgenLog.v(TAG,'done (' + str(c) + 'files)' )
    
    ResgenLog.v(TAG,'process image......')
    process_image()
 
    ResgenLog.v(TAG,'process Meta 3D binarys resources ......')
    binary3DResParamModel = ResParamModel('BINARY_3D_META',0)
    process_binary_3d(binary3DResParamModel, ResParamModel.DEFAULT_REPO_BINARY_3D_META)

    ResgenLog.v(TAG,' output id map...')
    output_id_map()

    ResgenLog.v(TAG,  'Finished writing 3D meta data to headers')
    write_mmi_3d_header_end()

    # check if auto gen id exceed 16bit
    if not image_name_id_map:
      ResgenLog.v(TAG,  'No 3D image found')
    else:
      max_id = max(max(binary3d_name_id_map.values()), max(image_name_id_map.values()))
      if max_id > 65535:
          raise Exception("auto generated ID exceed 65535 (max=%d)" % (max_id))
      ResgenLog.v(TAG, 'Auto-generated 3D max id =' + str(max_id))

    offset = time.time() - start_time
    ResgenLog.v(TAG, 'Auto-generate 3D res from image.zip - End, take ' +str(offset) + ' secs')

####################################################


####################################################
# Compatiable filter
####################################################
def check_if_resource_populated(reouce_id, id_name_map):
    if(reouce_id in id_name_map):
        return True
    return False
####################################################

####################################################
# Write the starting content of mmi 3d meta resource 
# header
####################################################
def write_mmi_3d_header_start():
    header_name = '..\\..\\Customer\\CustomerInc\\' + gen_header_name_for_app('MMI3DRESOURCE')
    out_file = file(header_name, 'w')
    out_file.write('#ifndef __MMI_3D_META_RESOURCE_HEADER__\n#define __MMI_3D_META_RESOURCE_HEADER__\n')
    out_file.close()
####################################################

####################################################
# Write the ended content of mmi 3d meta resource 
# header
####################################################
def write_mmi_3d_header_end():
    header_name = '..\\..\\Customer\\CustomerInc\\' + gen_header_name_for_app('MMI3DRESOURCE')
    out_file = file(header_name, 'a')
    out_file.write('#endif // __MMI_3D_META_RESOURCE_HEADER__\n')
    out_file.close()
####################################################
    
####################################################
# Get name id maps
####################################################
def get_res_id_name_map(filename):
    name_id_map = {}
    name_id_map_file = file(filename)
    for line in name_id_map_file.readlines():
        line = line.strip()
        if line:
            name, id = line.split()
            name_id_map[name] = int(id)
    return name_id_map

####################################################
# Module Entry
####################################################

# Check if the file is being run as a top-level program file before 
# invoke main method
if __name__ == '__main__':
    old_path = os.getcwd()
    try:
        sys.stdout.write('[Dependency] %s\n' % os.path.abspath(sys.argv[0]))
        sys.stdout.write('[Dependency] %s\\resgen_offline_param.py\n' % os.path.dirname(os.path.abspath(sys.argv[0])))
        sys.stdout.write('[Dependency] %s\\resgen_log.py\n' % os.path.dirname(os.path.abspath(sys.argv[0])))
        os.chdir(os.path.dirname(os.path.abspath(sys.argv[0])))
        if(len(sys.argv)>1):
            theme_root_path = sys.argv[1]
            main()
        else:
            ResgenLog.v(TAG,'No theme_root_path passed, skip resgen_xml_3d_meta_handle')
    except:
        ResgenLog.w(TAG,'Exception occured when executing main function')
        print '\n', '-'*20, "python exception start", '-'*20
        traceback.print_exc(file=sys.stdout)
        print '-'*20, "python exception  end ", '-'*20
        raise
    finally:
        os.chdir(old_path)
####################################################
