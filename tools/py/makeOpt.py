import os, sys
from maui import *
import os.path
import re
import cPickle as pickle

re_option = re.compile(r"\[\s*(.+)\s*]")

build_path              = get_build_path()
xml_path                = os.path.join(build_path, "xml")
macro_path              = os.path.join(xml_path, "macro")

info_log_filename       = os.path.join(build_path, "log", "info.log")
features_log_filename   = os.path.join(build_path, "log", "MMI_features.log")
output_filename         = os.path.join(xml_path, "option.x")


def process_info(opt, filename):
    info_log_section = ''
    for ln in file(filename):
        ln = ln.strip()
        if not ln:
            continue
        
        if re_option.match(ln):
            info_log_section = re_option.match(ln).groups()[0].strip()
            continue
        
        if info_log_section == 'COMMON OPTION':
            if '=' not in ln:
                opt[ln] = True
            else:
                h, l = ln.split('=', 1)
                try:
                    v = eval(l)
                except:
                    v = l.strip(' ()')
                
                if h in opt:
                    print 'Warning:', h, 'has been defined.'
                    
                opt[h] = v


def process_features(opt, filename):
    features_log_section = ''
    for ln in file(filename):
        ln = ln.strip()
        if ln[:3] == '[D]':
            ln = ln[4:]
            d = [i.strip() for i in ln.split(' ', 1) if i.strip()]
            if len(d) == 1:
                opt[d[0]] = True
            else:
                try:
                    v = eval(d[1])
                except:
                    v = d[1].strip(' ()')
    
                h = d[0]
                if h in opt:
                    print 'Warning:', h, 'has been defined.'
    
                opt[h] = v
                
def make(force = False):
    
    # ------------------------------------------------------------------------------
    #   Variables
    # ------------------------------------------------------------------------------
    
    #
    # This is most important data, we will store compile options into this dictionary.
    #
    opt = {}
        
    # ------------------------------------------------------------------------------
    #   Check whether need to rebuild option.x
    # ------------------------------------------------------------------------------
    
    need_rebuild = False
        
    macro_files = []
    if os.path.exists(macro_path):
        for f in os.listdir(macro_path):
            if len(f) > 3:
                macro_files.append(os.path.join(macro_path, f))
    
    if not os.path.exists(info_log_filename):
        error_exit('Cannot find info.log:', info_log_filename)
    
    if not os.path.exists(features_log_filename):
        error_exit('Cannot find MMI_features.log:', features_log_filename)
    
    if not force and not check_need_rebuild(output_filename, [info_log_filename, features_log_filename] + macro_files):
        print '[makeopt] The output file is latest'
        return
    
    print '[makeopt] Build options ...'
    
    # ------------------------------------------------------------------------------
    #   Process
    # ------------------------------------------------------------------------------
    
    # Process info.log
        
    process_info(opt, info_log_filename)
    process_features(opt, features_log_filename)
    for fn in macro_files:
        process_features(opt, fn)
    
    # Output as a cache
    
    print '[makeopt] Collect options count:', len(opt)
    
    try:
        os.makedirs(xml_path)
    except:
        pass
    
    try:        
        pickle.dump(opt, file(output_filename, "wb"), 2)
    except:
        error_exit('Save output file fail:', output_filename)


def getOpt():
    # check whether need to rebuild option.x
    make()
    
    try:
        opt = pickle.load(file(output_filename, "rb"))
    except:
        traceback.print_exc()
        error_exit('Read opt.bin error:', output_filename)
    
    return opt

if __name__ == "__main__":
    make()
