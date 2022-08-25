import sys
import os
import traceback

from resgen_populate_util import output_file_data_text, convert_to_symbol_name, get_output_data_file_name
from resgen_populate_util import output_data_hw_header, output_res, output_map
from resgen_populate_util import output_repeat_list, output_fail_list
from resgen_offline_param import ResPopParam, BinaryResParam, ResParamModel, BinaryParamTextFileDAO, ResReportHelper
from resgen_log import ResgenLog

g_error_flag = 0
TAG = 'RESGEN_POPULATE'

def output_binary_header(binary_type, binary_size, output_file):
    binary_header = '\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x00, 0x00, 0x00,\n' % (
            binary_type,
            binary_size % (256 ** 1) / (256 ** 0),
            binary_size % (256 ** 2) / (256 ** 1),
            binary_size % (256 ** 3) / (256 ** 2),
            binary_size % (256 ** 4) / (256 ** 3),
            )
    output_file.write(binary_header)

def output_binary_content(filename, binary_type, output_file):
    binary_size = os.path.getsize(filename)
    if binary_size == 0:
        binary_type = 0

    output_binary_header(binary_type, binary_size, output_file)
    output_file_data_text(filename, output_file)

def output_binary_content_wrapper(filename, binary_type, output_file):
    if filename.lower().endswith('.fs') or filename.lower().endswith('.vs'):
        alternate_file = filename + 'b'
        alternate_found = os.path.exists(alternate_file)
        
        if alternate_found:
            output_file.write('#if ( !defined (__MTK_TARGET__) )\n')
            output_binary_content(filename, binary_type, output_file)
            output_file.write('#else\n')
            output_binary_content(alternate_file, binary_type, output_file)
            output_file.write('#endif\n')
        else:
            output_binary_content(filename, binary_type, output_file)
    else:
        output_binary_content(filename, binary_type, output_file)


def output_binary(filename, binary_type, output_file):
    output_file.write('__align(4) const U8 %s[] =\n{\n' % convert_to_symbol_name(filename) )
    output_binary_content_wrapper(filename, binary_type, output_file)
    output_file.write(' };\n')

def populate_all_binary_data(binaryResModel):
    global TAG
    ResgenLog.v(TAG, 'Start binary resource generation ... Model = ' + binaryResModel.name)

    output_file = file(get_output_data_file_name('Binary'), 'w');
    binary_list = binaryResModel.items
    output_data_hw_header(output_file)

    symbol_name_list = []
    symbol_name_meta_data = {}
    binary_res_map = {}
    unique_count = 0
    res_id_list = []
    
    # Record the binary resource of generated filed
    fail_file_list = ResParamModel('FAILED_BINARY_RESOURCE', 0)
    # Record the duplicated binary resource
    repeat_list = ResParamModel('REPEAT_BINARY_RESOURCE', 0)
    # Record the binary resource usage
    success_list = ResParamModel('SUCCEEDED_BINARY_RESOURCE', 0)

    for entry in binary_list:
        if(not entry is None):
            res_id = entry.idEnumValue
            filename = entry.binaryFilePath
            binary_type = entry.binaryType
        else:
            continue
        symbol_name = convert_to_symbol_name(filename)
        if symbol_name_meta_data.has_key(symbol_name):
            repeat_list.add(entry)
        else:
            if os.path.exists(filename):
                output_binary(filename, binary_type, output_file)
                symbol_name_meta_data[symbol_name] = (res_id, unique_count)
                symbol_name_list.append(symbol_name)
                success_list.add(entry)
                unique_count += 1
            else:
                symbol_name = '________CUSTOMER__BINARY__NOBINARY_BIN'
                fail_file_list.add(entry)
                # Handling population error
                global g_error_flag
                g_error_flag = 1
                completeContentPath = os.path.normpath('mcu\\plutommi\\customer\\resgenerator\\' + entry.binaryFilePath)
                completeResPath = os.path.normpath('mcu\\plutommi\\customer\\resgenerator\\' + entry.resFilePath)
                if completeResPath is None:
                    completeResPath = entry.resFilePath
                if completeContentPath is None:
                    completeContentPath = entry.binaryFilePath
                resource_dump_title = "FAILED RESOURCE " + entry.getReportTitle()
                resource_dump_str = entry.toReportString()
                print >> sys.stderr, "** Error!! Binary resource declaration failed, file not found:", completeContentPath
                print >> sys.stderr, "** FILE:", completeResPath
                print >> sys.stderr, "**", resource_dump_title
                print >> sys.stderr, "**", resource_dump_str
                ResgenLog.e(TAG, 'Binary resource declaration failed, file not found: ' + completeContentPath )
                ResgenLog.e(TAG, 'FILE: ' +  completeResPath )
                ResgenLog.e(TAG, resource_dump_title)
                ResgenLog.e(TAG, resource_dump_str)
                
        res_id_list.append(res_id)
        binary_res_map[res_id] = symbol_name

    res_id_list.sort()

    output_res('Binary', symbol_name_list)
    output_map('Binary', res_id_list, binary_res_map, symbol_name_meta_data)
    
    # Create resport for further debugging
    reportHelper = ResReportHelper()
    reportHelper.createFailedReport(ResReportHelper.REPORT_FAILED_BINARY, fail_file_list)
    reportHelper.createUsageReport(ResReportHelper.REPORT_USAGE_BINARY, success_list)
    reportHelper.createDuplicatedReport(ResReportHelper.REPORT_DUPLICATED_BINARY, repeat_list)

    if(g_error_flag == 1):
        ResgenLog.v(TAG, 'Finished binary resource generation, but got some error.')    
    else:
        ResgenLog.v(TAG, 'Finished binary resource generation, you can check ' +  ResReportHelper.REPORT_USAGE_BINARY + ' for the detailed resource usage information')




def main():
    global TAG
# Load Binary Resources from Offline DB
    resParamModelObj = ResParamModel('ALL_BINARY_RESOURCE', 0)
    ResgenLog.v(TAG, '------------------Load Offline resource data from Resgen DB------------------')
    resParamModelObj.loadFromRepository(ResParamModel.DEFAULT_REPO_BINARY_PREXML_LEGACY)
    resParamModelObj.loadFromRepository(ResParamModel.DEFAULT_REPO_BINARY_3D_DEV)
    resParamModelObj.loadFromRepository(ResParamModel.DEFAULT_REPO_BINARY_3D_META)
#    resParamModelObj.loadFrom3DMetaFile('temp/mmi_rp_binary3d_populate_with_meta.txt');
    resParamModelObj.loadFromRepository('offline_xml_binary_repo.txt')
    resParamModelObj.loadFromRepository(ResParamModel.DEFAULT_REPO_BINARY_POSTXML_LEGACY)
    ResgenLog.v(TAG, '------------------------------------------------------------------------------')

    resParamModelObj.flush('debug/debug_offline_all_binary_repo.txt')
    ResgenLog.v(TAG, 'populate_all_binary_data')
    populate_all_binary_data(resParamModelObj)
    
if __name__ == '__main__':
    try:
        sys.stdout.write('[Dependency] %s\n' % os.path.abspath(sys.argv[0]))
        sys.stdout.write('[Dependency] %s\\resgen_populate_util.py\n' % os.path.dirname(os.path.abspath(sys.argv[0])))
        sys.stdout.write('[Dependency] %s\\resgen_offline_param.py\n' % os.path.dirname(os.path.abspath(sys.argv[0])))
        sys.stdout.write('[Dependency] %s\\resgen_log.py\n' % os.path.dirname(os.path.abspath(sys.argv[0])))
        main()
    except:
        ResgenLog.w(TAG, 'Exception occured in main function')
        print '\n', '-'*20, "python exception start", '-'*20
        traceback.print_exc(file=sys.stdout)
        print '-'*20, "python exception  end ", '-'*20
        raise
    if g_error_flag:
        exit(2)
