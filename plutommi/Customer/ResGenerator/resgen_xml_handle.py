import sys
import os
import StringIO
import traceback
import time
import struct
import re

from xml.sax import make_parser, handler, SAXParseException

# global variables
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

    def __init__(self):
        self._last_token = None
        self._current_app_id = None

        self._context = {}
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
        elif name == 'app':
            if 'id' in attrs:
                self._current_app_id = attrs['id']

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
        context = self._context['binary3d']
        if not context.id:
            print 'id is None'
            return

        if not context.content:
            print 'content is None'
            return

        content = parsePath(context.content)
        self.process_binary3d(self._current_app_id, context.id, content, context.base_path)

    def handle_image(self):
        context = self._context['image']
        if not context.id:
            print 'id is None'
            return

        if not context.content:
            #print 'content is None'
            return

        content = parsePath(context.content)
        self.process_image(self._current_app_id, context.id, content)

    def process_binary3d(self, app_id, id, content, base_path):
        global binary3d_content
        global res_base_table
        if base_path == 'current':
            content = os.path.join('..\\..\\', res_base_table[app_id][1], content)
            print 'content:', content
        binary3d_content.append((app_id, id, content) )

    def process_image(self, app_id, id, content):
        global image_content
        image_content.append( (app_id, id, content) )


def parse_xml_file(filename):
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
    parser.setContentHandler(ResgenXMLParser())
    try:
        parser.parse(StringIO.StringIO(content) )
    except SAXParseException:
        e = sys.exc_info()[1]
        print 'filename: ', filename
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

    out_file.write('/******************** Binary 3D resource IDs - End ********************/\n')
    out_file.close()


def process_binary_3d():
    global binary3d_content
    content_map_by_app = {}

    for entry in binary3d_content:
        if entry[0] not in content_map_by_app:
            content_map_by_app[entry[0] ] = []

        content_map_by_app[entry[0] ].append( (entry[1], entry[2]) )

    for app_name in content_map_by_app:
        output_binary3d_header_for_app(app_name, content_map_by_app[app_name])

    output_binary3d_populate = file('temp\\mmi_rp_binary3d_populate.txt', 'w')

    for entry in binary3d_content:
        out_str = str(binary3d_name_id_map[entry[1] ] ) + ' ' + entry[2] + '\n'
        output_binary3d_populate.write(out_str)
        binary3d_path = entry[2]


def process_image():
    global image_content
    content_map_by_app = {}
    for entry in image_content:
        if entry[0] not in content_map_by_app:
            content_map_by_app[entry[0] ] = []

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


def output_id_map():
    image_map_file = file('temp\\mmi_rp_image_id_map.txt', 'w')
    for name in image_name_id_map:
        image_map_file.write(name + ' ' + str(image_name_id_map[name]) + '\n')
    image_map_file.close()

    binary3d_map_file = file('temp\\mmi_rp_binary3d_id_map.txt', 'w')
    for name in binary3d_name_id_map:
        binary3d_map_file.write(name + ' ' + str(binary3d_name_id_map[name]) + '\n')
    binary3d_map_file.close()


def main():
    print 'resgen_xml_handle.py start', time.time()

    print 'load base table'
    load_res_base_table()

    print 'start parsing'
    parse_all_xml_files()
    print 'end parsing'

    print 'processing'
    process_image()
    print 'output'
    process_binary_3d()
    print 'output id map'
    output_id_map()

    print 'resgen_xml_handle.py end', time.time()

if __name__ == '__main__':
    old_path = os.getcwd()
    try:
        sys.stdout.write('[Dependency] %s\n' % os.path.abspath(sys.argv[0]))
        os.chdir(os.path.dirname(os.path.abspath(sys.argv[0])))
        main()
    finally:
        os.chdir(old_path)

