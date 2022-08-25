import sys
import os
import StringIO
import traceback
import time
import struct
import re

from xml.sax import make_parser, handler, SAXParseException
from resgen_offline_param import ResPopParam, BinaryResParam, ResParamModel, BinaryParamTextFileDAO, ResReportHelper
from resgen_log import ResgenLog

# global variables
TAG = "RESGEN_XML_3D_DEV_HANDLE"
binary3d_content = []
image_content = []
res_base_table = {}
binary3d_name_id_map = {}
image_name_id_map = {}


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


class ResgenXMLParser(handler.ContentHandler):
    TAG = "ResgenXMLParser"

    def __init__(self, resFilePath, res_base_table):
        self._last_token = None
        self._current_app_id = None
        # record the RES file path
        self._current_resFilePath = resFilePath
        self.res_base_table = res_base_table

        self._context = {}
        self._context_names = ('image', 'binary3d')
        for context_name in self._context_names:
            self._context[context_name] = Context()
            self._context[context_name].id = None
            self._context[context_name].base_path = None
            self._context[context_name].content = None

    def getOrigianlResFilePath(self, appId, realPath):
        resFileName = os.path.basename(realPath)
        endIndex = resFileName.rindex('.')
        if endIndex >=0 :
            resFileName = resFileName[:endIndex] + '.res'
        if appId.upper() in res_base_table:
            if len(self.res_base_table[appId.upper()]) >=2:
                 resFileName = "" + self.res_base_table[appId.upper()][1] + resFileName
        return resFileName


    def startElement(self, name, attrs):
        name = name.lower()
        self._last_token = name
        if name in self._context_names:
            if 'id' in attrs:
                self._context[name].id = attrs['id']
            if 'base_path' in attrs:
                self._context[name].base_path = attrs['base_path']
        elif name == 'app':
            if 'id' in attrs:
                self._current_app_id = attrs['id']
                self._current_resFilePath = self.getOrigianlResFilePath(self._current_app_id, self._current_resFilePath )
                ResgenLog.v(ResgenXMLParser.TAG,"Parsing APP: " + self._current_app_id + "> from " + self._current_resFilePath )

    def endElement(self, name):
        name = name.lower()
        if name in self._context_names:
            if name == 'binary3d':
                self.handle_binary3d()
            elif  name == 'image':
                self.handle_image()
            self._context[name].id = None
            self._context[name].content = None
            self._context[name].base_path = None
        elif name == 'app':
            self._current_app_id = None

    def characters(self, content):
        content = content.strip()
        if not content:
            return
        name = self._last_token
        if name in self._context_names:
            if not self._context[name].content:
                self._context[name].content = content
            else:
                self._context[name].content += content

    def handle_binary3d(self):
        try:
            context = self._context['binary3d']
            if not context.id:
                ResgenLog.w(ResgenXMLParser.TAG, 'handle_binary3d: id is None')
                return

            if not context.content:
                ResgenLog.w(ResgenXMLParser.TAG, 'handle_binary3d: content is None')
                return

            content = parsePath(context.content)
            self.process_binary3d(self._current_app_id, context.id, content, context.base_path, self._current_resFilePath)
        except:
            ResgenLog.e(ResgenXMLParser.TAG, 'exception in handle_binary3d')
            print '\n', '-'*20, "python exception start", '-'*20
            traceback.print_exc(file=sys.stdout)
            print '-'*20, "python exception  end ", '-'*20

    def handle_image(self):
        context = self._context['image']
        if not context.id:
            ResgenLog.w(ResgenXMLParser.TAG, 'handle_image: id is None')
            return

        if not context.content:
            #ResgenLog.w(ResgenXMLParser.TAG, 'handle_image: Content is None')
            return

        content = parsePath(context.content)
        self.process_image(self._current_app_id, context.id, content, self._current_resFilePath)

    def process_binary3d(self, app_id, id, content, base_path, resFilePath):
        global binary3d_content
        global res_base_table
        if base_path == 'current':
            content = os.path.join('..\\..\\', res_base_table[app_id][1], content)
            ResgenLog.v(ResgenXMLParser.TAG,'content:' + content)
        binary3d_content.append((app_id, id, content, resFilePath) )

    def process_image(self, app_id, id, content, resFilePath):
        global image_content
        image_content.append( (app_id, id, content, resFilePath) )


def parse_xml_file(filename):
    global res_base_table
    global TAG
    xml_file = file(filename, 'r')

    content = ''

    in_xml = False

    for line in xml_file.readlines():
        if '<?xml' in line:
            in_xml = True
        if in_xml:
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
            if '<?xml' in line:
                content += '<venusxml>\n'

    if not content.strip():
        return

    content += '</venusxml>\n'

    parser = make_parser()
    parser.setContentHandler(ResgenXMLParser(filename, res_base_table))
    try:
        parser.parse(StringIO.StringIO(content) )
    except SAXParseException:
        ResgenLog.e(TAG, 'Exception in parse_xml_file: file = ' + filename )
        e = sys.exc_info()[1]
        print 'error:', e
        print content.split('\n')[e._linenum - 1]


def parse_all_xml_files():
    xml_folder = 'debug/res'

    for a_file in os.listdir(xml_folder):
        if a_file.lower().endswith('.i'):
            parse_xml_file(os.path.join(xml_folder, a_file) )


def load_res_base_table():
    global res_base_table
    in_file = file('debug/resgen_base_table.txt')

    for line in in_file.readlines():
        if line.startswith('min'):
            continue
        entries = line.strip().split()
        entries = [i for i in entries if i]
        start_id = int(entries[0])
        app_name = entries[2]
        if len(entries) >= 4:
            res_path = entries[3]
        else:
            res_path = ''
        if app_name not in res_base_table:
            res_base_table[app_name] = (start_id, res_path)


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


def output_binary3d_header_for_app(app_name, id_list):
    if len(id_list) == 0:
        return

    header_name = 'temp\\res_out\\CustomerInc\\' + gen_header_name_for_app(app_name)
    out_file = file(header_name, 'a')
    
    out_file.write('/******************** Binary 3D resource IDs - Begin ********************/\n')
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

    out_file.write('} mmi_rp_' + app_name.lower() + '_binary3d_enum;\n')
    out_file.write('\n#include "mmi_rp_mmi3dresource_def.h"\n\n')
    out_file.write('/******************** Binary 3D resource IDs - End ********************/\n')
    
    out_file.close()


def process_binary_3d(binary3DResModel, dbPath):
    global binary3d_content
    global TAG
    content_map_by_app = {}

    for entry in binary3d_content:
        if entry[0] not in content_map_by_app:
            content_map_by_app[entry[0] ] = []
        content_map_by_app[entry[0] ].append( (entry[1], entry[2]) )
   
    create_init_mmi_3d_header()
    for app_name in content_map_by_app:
        output_binary3d_header_for_app(app_name, content_map_by_app[app_name])

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
    ResgenLog.v(TAG, 'Flush dev binary 3d resource to Offline DB')
    binary3DResModel.flush(dbPath)




def process_image():
    global image_content
    global TAG
    content_map_by_app = {}
    for entry in image_content:
        if entry[0] not in content_map_by_app:
            content_map_by_app[entry[0] ] = []
        content_map_by_app[entry[0] ].append( (entry[1], entry[2]) )
    
    global image_name_id_map
    
    for app_name in content_map_by_app:
        appUpperName = app_name.upper()
        if not appUpperName in res_base_table:
            ResgenLog.e(TAG, " app name " + appUpperName + " not found")
            ResgenLog.e(TAG, " Please check if the application has been registered in mmi_pluto_res_range_def.h vapp_package_res.h orvapp_res.h  ")
        else:
            base_id = res_base_table[app_name.upper()][0]
            current_id = base_id + 1
            id_list = content_map_by_app[app_name]
            for entry in id_list:
                if not image_name_id_map.has_key(entry[0]):
                    image_name_id_map[entry[0] ] = current_id
                    current_id += 1


def output_id_map():
    image_map_file = file('temp\\mmi_rp_image_id_map.txt', 'w')
    for name in image_name_id_map:
        image_map_file.write(name + ' ' + str(image_name_id_map[name]) + '\n')
    image_map_file.close()

    binary3d_map_file = file('temp\\mmi_rp_binary3d_id_map.txt', 'w')
    for name in binary3d_name_id_map:
        binary3d_map_file.write(name + ' ' + str(binary3d_name_id_map[name]) + '\n')
    binary3d_map_file.close()


def create_init_mmi_3d_header():
    header_name = 'temp\\res_out\\CustomerInc\\' + gen_header_name_for_app('MMI3DRESOURCE')
    out_file = file(header_name, 'w')
    out_file.write('//MMI 3D Meta Resource Header\n')
    out_file.close()


def main():
    global TAG
    ResgenLog.v(TAG, 'resgen_xml_handle.py start' + time.strftime("%H:%M:%S +0000", time.gmtime()))

    ResgenLog.v(TAG,'load base table')
    load_res_base_table()

    ResgenLog.v(TAG,'Start parsing DEV 3D Resources')
    parse_all_xml_files()
    ResgenLog.v(TAG,'End of parsing DEV 3D Resources')

    ResgenLog.v(TAG,'Process 3D image resources')
    process_image()
    
    
    ResgenLog.v(TAG,'Store the Dev 3D Resource to DB')
    binary3DResParamModel = ResParamModel('BINARY_3D_DEV',0)
    process_binary_3d(binary3DResParamModel, ResParamModel.DEFAULT_REPO_BINARY_3D_DEV)
    
    ResgenLog.v(TAG,'Output Dev 3D Resource id map table')
    output_id_map()

    ResgenLog.v(TAG, 'resgen_xml_handle.py end' + time.strftime("%H:%M:%S +0000", time.gmtime()))


if __name__ == '__main__':
    old_path = os.getcwd()
    try:
        os.chdir(os.path.dirname(os.path.abspath(sys.argv[0])))
        sys.stdout.write('[Dependency] %s\n' % os.path.abspath(sys.argv[0]))
        sys.stdout.write('[Dependency] %s\\resgen_offline_param.py\n' % os.path.dirname(os.path.abspath(sys.argv[0])))
        sys.stdout.write('[Dependency] %s\\resgen_log.py\n' % os.path.dirname(os.path.abspath(sys.argv[0])))
        main()
    except:
        ResgenLog.w(TAG, 'Exception occured in main function')
        print '\n', '-'*20, "python exception start", '-'*20
        traceback.print_exc(file=sys.stdout)
        print '-'*20, "python exception  end ", '-'*20
        raise
    finally:
        os.chdir(old_path)
