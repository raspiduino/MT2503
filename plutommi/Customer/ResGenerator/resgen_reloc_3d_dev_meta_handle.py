import sys
import os
import struct
import traceback
from resgen_offline_param import ResPopParam, BinaryResParam, ResParamModel, BinaryParamTextFileDAO, ResReportHelper
from resgen_log import ResgenLog

TAG = "RESGEN_RELOC_3D_DEV_META_HANDLE"
image_name_id_map = {}
binary3d_name_id_map = {}

def read_id_map():
    global image_name_id_map
    global binary3d_name_id_map

    path_all_enum_id = 'debug\\resgen_xml_all_enum_IDs.log'
    path_image_id_map_only_meta = 'temp\\mmi_rp_image_id_map_only_meta.txt'
    path_binary3d_id_map_with_meta = 'temp\\mmi_rp_binary3d_id_map_with_meta.txt'
   
    # Load Image ID refernace table for relocation    
    if os.path.exists(path_all_enum_id):
        for line in file(path_all_enum_id):
            line = line.strip()
            if line:
                name, eq, id = line.split()
                image_name_id_map[name] = int(id)

    if os.path.exists(path_image_id_map_only_meta):
        for line in file(path_image_id_map_only_meta):
            line = line.strip()
            if line:
                name, id = line.split()
                image_name_id_map[name] = int(id)

    # Load 3D binary ID for relocation
    if os.path.exists(path_binary3d_id_map_with_meta):
        for line in file(path_binary3d_id_map_with_meta):
            line = line.strip()
            if line:
                name, id = line.split()
                binary3d_name_id_map[name] = int(id)

def process_reloc_file(file_path):
    global TAG
    reloc_path = file_path + '.reloc'
    if not os.path.exists(file_path) or not os.path.exists(reloc_path):
        return 1
        
    result = 0
#    ResgenLog.v(TAG, 'Relocates 3D Resource, reloc file: ' + file_path)
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
                # write 0
                binary3d_file.seek(int(offset) )
                binary3d_file.write(struct.pack('<H', 0))
                # output error
                ResgenLog.e(TAG, '3D Resource reloc failed, id: ' + name + ' not found!')
                ResgenLog.e(TAG, 'File: ' + reloc_path)
                print >> sys.stderr, '** Error!! reloc failed, id:', name, 'not found!'
                print >> sys.stderr, '** FILE:', reloc_path
                result = 2
    binary3d_file.close()
    reloc_file.close()
    return result

def process_binary3d_list():
    global TAG
    result = [0, 0, 0]
    #Load all binay 3D resources
    #path_binary3d_populate_with_meta = 'temp\\mmi_rp_binary3d_populate_with_meta.txt'
    resParamModelObj = ResParamModel('BINARY_3D_FOR_RELOC', 0)
    resParamModelObj.loadFromRepository(ResParamModel.DEFAULT_REPO_BINARY_3D_DEV)
    resParamModelObj.loadFromRepository(ResParamModel.DEFAULT_REPO_BINARY_3D_META)
    
    for line in resParamModelObj.items:
        if not line:
            continue
        file_name = line.binaryFilePath
        ResgenLog.v(TAG, 'process_reloc_file: ' + file_name)
        result[process_reloc_file(file_name)] += 1
    return result

def main():
    ResgenLog.v(TAG, '')
    read_id_map()
    
    ResgenLog.v(TAG, 'do relocation ...')
    result = process_binary3d_list()
    if result[2] > 0:
        ResgenLog.v(TAG, '3D Resource Reloc done. ' + str(result[1])+ ' skip, ' + str(result[0]) + ' succeed, ' + str(result[2]) +' fail')
    else:
        ResgenLog.v(TAG, '3D Resource Reloc done. ' + str(result[1])+ ' skip, ' +str(result[0]) +' succeed')
    # if there is error
    if result[2] > 0:
        return -1
        
    return 0

if __name__ == '__main__':
    
    try:
        sys.stdout.write('[Dependency] %s\n' % os.path.abspath(sys.argv[0]))
        sys.stdout.write('[Dependency] %s\\resgen_offline_param.py\n' % os.path.dirname(os.path.abspath(sys.argv[0])))
        sys.stdout.write('[Dependency] %s\\resgen_log.py\n' % os.path.dirname(os.path.abspath(sys.argv[0])))
        result = main()
    except:
        ResgenLog.w(TAG, 'Exception occured in main function')
        print '\n', '-'*20, "python exception start", '-'*20
        traceback.print_exc(file=sys.stdout)
        print '-'*20, "python exception  end ", '-'*20
        raise

    sys.exit(result)
