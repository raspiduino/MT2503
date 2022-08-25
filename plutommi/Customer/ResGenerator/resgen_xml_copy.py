import sys
import os

g_res_list = []

def load_res_base_table_copy_path(skip_dev):
    path_set = set()
    in_file = file('debug/resgen_base_table.txt')

    for line in in_file.readlines():
        if line.startswith('min'):
            continue
        entries = line.strip().split('\t')
        entries = [i for i in entries if i]
        if len(entries) >= 4:
            app_name = entries[2]
            res_path = entries[3]
            if skip_dev and (app_name == 'APP_DEVAPP' or app_name == 'APP_AVK'):
                continue
            if res_path[-1] != '\\':
                res_path += '\\'
            path_set.add(res_path)
    return path_set

def output_custom_copy(path_list):
    out_file = file('debug/mmi_rp_custom_path.bat', 'w')

    ext_list = ('res', 'txt')
    for path in path_list:
        for ext in ext_list:
            cmd = 'xcopy /y plutommi\\' + path + '*.' + ext + ' %1\\plutommi\\' + path + '\n'
            out_file.write(cmd)

def copy_res_files(path_list):
    for path in path_list:
        cmd = 'xcopy ..\\..\\..\\plutommi\\' + path + '*.res .\\temp\\res\\*.c /y/D > nul'
        print 'Run command:[%s]' % (cmd)
        result = os.system(cmd)
        if result != 0:
            print 'no res found.'

        p = os.path.normpath('..\\..\\..\\plutommi\\' + path)
        if os.path.exists(p):
            ap = os.path.normpath('a\\b\\c\\' + p)
            for i in os.listdir(p):
                if os.path.splitext(i)[1].lower() == '.res':
                    g_res_list.append(os.path.join(ap, i))

def main():
    skip_dev = False
    if '-v' in sys.argv:
        skip_dev = True
    res_all_path_set = load_res_base_table_copy_path(skip_dev)

    path_list = list(res_all_path_set)
    path_list.sort()

    output_custom_copy(path_list)
    copy_res_files(path_list)

    for i in g_res_list:
        print 'Res:%s' % (i)

if __name__ == '__main__':
    old_path = os.getcwd()
    try:
        sys.stdout.write('[Dependency] %s\n' % os.path.abspath(sys.argv[0]))
        os.chdir(os.path.dirname(os.path.abspath(sys.argv[0])))
        main()
    finally:
        os.chdir(old_path)

