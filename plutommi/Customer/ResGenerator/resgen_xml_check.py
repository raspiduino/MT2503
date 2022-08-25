import sys
import os
import StringIO
import traceback
import time
import re

from xml.sax import make_parser, handler, SAXParseException

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
        return True

    content += '</venusxml>\n'

    parser = make_parser()
    try:
        parser.parse(StringIO.StringIO(content) )
    except SAXParseException:
        e = sys.exc_info()[1]
        print '[ERROR] PARSER ERROR: [35] Unknown error, File=[%s] Line=[%d] data=[%s]' % (filename, e._linenum, e._msg)
        print '[ERROR] Resgen XML Parse Error, file:', filename,
        print 'line:', e._linenum, 'column:', e._colnum, 'info:', e._msg
        print '[ERROR] error line:',
        print content.split('\n')[e._linenum - 1]
        return False
    except:
        traceback.print_exc()
        return False

    return True


def parse_all_xml_files():
    xml_folder = 'debug/res'
    out_file = file('debug/resgen_valid_xml_list.txt', 'w')
    result = True

    for a_file in os.listdir(xml_folder):
        if a_file.lower().endswith('.i'):
            xml_path = os.path.join(xml_folder, a_file)
            if parse_xml_file(xml_path):
                out_file.write(a_file + '\n')
            else:
                result = False
    return result

def main():
    result = parse_all_xml_files()
    #result = parse_xml_file(sys.argv[1])
    if not result:
        sys.exit(2)

if __name__ == '__main__':
    old_path = os.getcwd()
    try:
        sys.stdout.write('[Dependency] %s\n' % os.path.abspath(sys.argv[0]))
        os.chdir(os.path.dirname(os.path.abspath(sys.argv[0])))
        main()
    finally:
        os.chdir(old_path)
