import os, sys
import os.path

#
# To speed up the peroformance, we will cache the mcu folder.
#
mcu_path = ''


#
# This function print error message and exit the program with error code -1.
#
def error_exit(*msg):
    print >> sys.stderr, '-' * 79
    print >> sys.stderr, "Error:", " ".join(msg)
    print >> sys.stderr, '-' * 79
    sys.exit(-1)
    
#
# This function return project root path, 
#  for example: T:\_Dbg\LIBRA35_DEMO_gprs(FTE).09B_W10.07\mcu
#
def get_mcu_path():
    global mcu_path
    
    if mcu_path:
        return mcu_path
        
    try:
        folder = os.path.dirname(__file__)
    except:
        folder = os.path.abspath('.')
    
    paths = folder.split('\\')
    
    while paths:
        if paths[-1].lower() == 'mcu' or os.path.exists(os.path.join("\\".join(paths), "plutommi")):
            mcu_path = "\\".join(paths)
            return mcu_path
        
        paths = paths[:-1]
           
    # there is no mcu folder, check there are plutommi folder
    root = folder[:3]
    if os.path.exists(os.path.join(root, "plutommi")):
        return root

    error_exit('Cannot find root path:', folder)


#
# This function return the custom name, 
#  for example: LIBRA35_DEMO
#
def get_custom_name():
    # check ENV first
    try:
        value = os.environ['MTK_PROJECT_PATH']
        if value != '':
            return value
    except KeyError:
        pass

    # check 'make.ini'
    mcu = get_mcu_path()
    make_ini = os.path.join(mcu, "make.ini")
    
    if not os.path.exists(make_ini):
        error_exit('Cannot find make.ini')
    
    for ln in file(make_ini):
        try:
            key, value = [i.strip() for i in ln.strip().split("=")]
        except:
            continue
            
        if (not key) or (not value):
            continue

        if key == 'custom':
            return value
            
    error_exit('Cannot detect custom name')


#
# This function return the project name, 
#  for example: LIBRA35_DEMO
#
def get_project_name():
    mcu = get_mcu_path()
    make_ini = os.path.join(mcu, "make.ini")
    
    if not os.path.exists(make_ini):
        error_exit('Cannot find make.ini')
    
    for ln in file(make_ini):
        try:
            key, value = [i.strip() for i in ln.strip().split("=")]
        except:
            continue
            
        if (not key) or (not value):
            continue

        if key == 'project':
            return value
            
    error_exit('Cannot detect project name')


#
# This function will detect the project setting (make.ini) and return the build path, 
#  for example: T:\_Dbg\LIBRA35_DEMO_gprs(FTE).09B_W10.07\mcu\build\LIBRA35_DEMO
#
def get_build_path():
    mcu = get_mcu_path()
    custom_path = os.path.join(mcu, 'build', get_custom_name())
    if not os.path.exists(custom_path):
        error_exit('Build path is not existed:', custom_path)
    return custom_path
            
#
# This function will detect the project setting (make.ini) and return the project path, 
#  for example: T:\_Dbg\LIBRA35_DEMO_gprs(FTE).09B_W10.07\mcu\build\LIBRA35_DEMO\gprs
#
def get_project_path():
    mcu = get_mcu_path()
    project_path = os.path.join(mcu, 'build', get_custom_name(), get_project_name())
    if not os.path.exists(project_path):
        error_exit('Project path is not existed:', project_path)
    return project_path
            

#
# This function will detect timestamp, check whether need to rebuild the output file.
#
def check_need_rebuild(output, inputs):
    try:
        # in windows, the min modify time resolution is 2 sec, we need to fix it.
        output_mtime = os.path.getmtime(output) + 1
    except WindowsError:
        # Cannot find output file
        return True 

    for fn in inputs:
        try:
            if os.path.getmtime(fn) > output_mtime:
                return True
        except WindowsError:
            # the input file is not exist? rebuild it.
            return True

    return False
    
