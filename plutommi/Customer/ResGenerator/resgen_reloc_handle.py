import sys
import os
import struct


image_name_id_map = {}
binary3d_name_id_map = {}

def read_id_map():
    global image_name_id_map
    global binary3d_name_id_map

    image_map_file = file('debug\\resgen_xml_all_enum_IDs.log')
    for line in image_map_file.readlines():
        line = line.strip()
        if line:
            name, eq, id = line.split()
            image_name_id_map[name] = int(id)

    binary3d_map_file = file('temp\\mmi_rp_binary3d_id_map.txt')
    for line in binary3d_map_file.readlines():
        line = line.strip()
        if line:
            name, id = line.split()
            binary3d_name_id_map[name] = int(id)

def process_reloc_file(file_path):
    reloc_path = file_path + '.reloc'
    if os.path.exists(file_path) and os.path.exists(reloc_path):
        binary3d_file = file(file_path, 'rb+')
        reloc_file = file(reloc_path)
        replace_rules = {}
        for line in reloc_file:
            line = line.strip()
            if line:
                offset, name = line.split()
                res_id = None
                if name in binary3d_name_id_map:
                    res_id = binary3d_name_id_map[name]
                elif name in image_name_id_map:
                    res_id = image_name_id_map[name]
                if res_id != None:
                    binary3d_file.seek(int(offset) )
                    binary3d_file.write(struct.pack('<H', res_id))
                else:
                    binary3d_file.seek(int(offset) )
                    binary3d_file.write(struct.pack('<H', 0))
                    # output error
                    mtk_proj_path = os.getenv('MTK_PROJECT_PATH')
                    warning_str = 'Warning: reloc failed, file: ' + file_path + ' ,id not found: ' + name
                    if mtk_proj_path:
                        f = file('.\\..\\..\\..\\build\\' + mtk_proj_path + '\\log\\res_gen.log', 'a')
                        print >> f, warning_str
                        f.close()
                    print >> sys.stderr, warning_str
        binary3d_file.close()
        reloc_file.close()


def process_binary3d_list():
    binary3d_populate_file = file('temp\\mmi_rp_binary3d_populate.txt')
    for line in binary3d_populate_file.readlines():
        line = line.strip()
        if not line:
            continue
        id, file_name = line.split()
        process_reloc_file(file_name)


def main():
    read_id_map()
    process_binary3d_list()

if __name__ == '__main__':
    if not sys.argv[0] is None:
        sys.stdout.write('[Dependency] %s\n' % os.path.abspath(sys.argv[0]))
    main()

