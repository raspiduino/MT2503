import os, sys
import re
import locale
import tempfile
import subprocess

from optparse import OptionParser

# from parse_mem_cfg_fpm_table import *

# =============== Const Setting ==================

g_build_path = r'%s\build'
g_cfg_path = r'%s\plutommi\Customer\ResGenerator\debug\mmi_mem_cfg.txt'
g_app_data_path = r'%s\plutommi\Customer\CustomerInc\mmi_rp_app_data.h'
g_obj_log_path = r'%s\build\%s\log\objcheck.log'

re_app_data = re.compile(r'#define\s+ASM_(CONC_)?(HEAP|EXTRA_BASE|APP_FG|CUI_BASE|CUI_FG|BASE|FG|TOTAL)_SIZE_(\w+)\s+\(([\W\w]+)\)')
re_app_data2 = re.compile(r'\s+ASM_(CONC_)?(HEAP|EXTRA_BASE|APP_FG|CUI_BASE|CUI_FG|BASE|FG|TOTAL)_SIZE_(\w+)\s=\s\(([\W\w]+)\),')

re_obj_check_1 = re.compile(r'\[D\]\s+app_asm_pool_(global|base|fg|sub|heap|total|extra_base|app_fg|cui_base|cui_fg)_union->(CONC_)?([\w]+)\s+(\d+)')
re_obj_check_2 = re.compile(r'\[\D\]\s+ASM_(CONC_)?(HEAP|EXTRA_BASE|APP_FG|CUI_BASE|CUI_FG|BASE|FG|TOTAL)_SIZE_([\w]+)\s+\(([\W\w]+)\)')
re_obj_check_total = re.compile(r'\[D\]\s+app_asm_pool_(sub_|global_|)union\s+(\d+)')

re_app_data_tag = re.compile(r'ASM_(CONC_)?(HEAP|EXTRA_BASE|APP_FG|CUI_BASE|CUI_FG|BASE|FG|TOTAL)_SIZE_(\w+)')

# =============== Global Setting ==================

g_setting_eval_macro = False
g_count_python_eval = 0
g_count_perl_eval = 0

g_bar_color = {
    'heap'      : '#9999FF',
    'extra_base': '#99FF99',
    'app_fg'    : '#FF9999',
        
    'base'      : '#99FFFF',
    'cui_base'  : '#99FFFF',
    'fg'        : '#FFCCFF',
    'cui_fg'    : '#FFCCFF',
    'total'     : '#FFFF33',
        
    'number'    : '#FF3380',
        
    'global'    : '#FF9900',
}

# =============== Function ==================

def parse_cfg_file(cfg_file):
    xml_list = {}
    conc_list = []

    for ln in file(cfg_file):
        ln = ln.rstrip()
        if ln.startswith("[id]"):
            results = {}
            for p in ln.split('['):
                if not p:
                    continue
                pair = p.strip().split(']')
                results[pair[0]] = pair[1]

            if results['id'] not in xml_list:
                xml_list[results['id']] = []
            xml_list[results['id']].append(results)

        elif ln.startswith("[concurrent]"):
            tag = ln[1:11]
            ln = ln[12:]
            results = [p.strip() for p in ln.split(',')]
            results.sort()
            conc_list.append((results, tag))
        elif ln.startswith("[concurrent_w_order]"):
            tag = ln[1:19]
            ln = ln[20:]
            results = [p.strip() for p in ln.split(',')]
            conc_list.append((results, tag))
        else:
            print >> sys.stderr, "Line not handled: %s" % (ln)
            
    return (xml_list, conc_list)

def parse_app_data_file(app_file):

    data_list = {}

    for ln in file(app_file):
        m = re_app_data.match(ln)
        if not m:
            m = re_app_data2.match(ln)
        if not m:
            continue

        conc = m.group(1)
        app_id = m.group(3)
        mem_type = m.group(2)
        mem_value = m.group(4)
        if conc:
            app_id = conc + app_id

        mem_value = mem_value.replace("ASM_FG_EXTRA(VRT_MEM_DEFAULT_CACHE_FACTOR)", "VRT_CACHE")

        try:
            data_list[app_id][mem_type] = mem_value
        except KeyError:
            data_list[app_id] = {mem_type: mem_value}

    return data_list

def parse_obj_check_file(obj_file):

    size_list = {}
    detail_list = {}

    for ln in file(obj_file):
        m = re_obj_check_1.match(ln)
        if m:
            conc = m.group(2)
            app_id = m.group(3)
            size_type = m.group(1)
            size_value = int(m.group(4))-4
            if size_type == 'sub':
                size_type = 'total'
            size_type = size_type.upper()
            if conc:
                app_id = conc + app_id
            
            if size_type == "GLOBAL":
                if size_value < 0 or app_id == "sum_total":
                    continue
                try:
                    size_list["_GLOBAL"][app_id] = size_value
                except KeyError:
                    size_list["_GLOBAL"] = {app_id:size_value}
                continue
                    
            try:
                size_list[app_id][size_type] = size_value
            except KeyError:
                size_list[app_id] = {size_type: size_value}
            continue

        m = re_obj_check_2.match(ln)
        if m:
            conc = m.group(1)
            app_id = m.group(3)
            detail_type = m.group(2)
            detail_value = m.group(4).strip()
            if conc:
                app_id = conc + app_id
            detail_value = detail_value.replace("ASM_FG_EXTRA(VRT_MEM_DEFAULT_CACHE_FACTOR)", "VRT_CACHE")
            
            try:
                detail_list[app_id][detail_type] = detail_value
            except KeyError:
                detail_list[app_id] = {detail_type: detail_value}
            continue

        m = re_obj_check_total.match(ln)
        if m:
            t = m.group(1)
            if t == "":
                t = "total"
            else:
                t = t[:-1]
                    
            size = int(m.group(2))
            if size < 4:
                size = 0
            try:
                size_list['_ASM'][t] = size
            except KeyError:
                size_list['_ASM'] = {t:size}
            continue
                        
    return (size_list, detail_list)

# split '+' and 'max' into pair
# in:   a + max(b, c)
# out:  [(a, b), (a, c)]
def parse_macro(input_str):
    def parse_str(input_str, tag_list, result_array):
        input_str = input_str.strip()
        total = len(input_str)
        if total == 0:
            result_array.append(list(tag_list))
            return

        if input_str.find('max') == 0:

            # extract a,b,c from "max(a, b) + c"
            j = 3
            level = 0
            a_start = a_end = b_start = b_end = c_start = c_end = 0
            while j < total:
                c = input_str[j]
                if c == '(':
                    level += 1
                    if level == 1:
                        a_start = j+1
                elif c == ',':
                    if level == 1:
                        a_end = j
                        b_start = j+1
                elif c == ')':
                    level -= 1
                    if level == 0:
                        b_end = j
                        c_start = j+1
                        c_end = total
                        break
                j += 1
                
            parse_str(input_str[a_start:a_end] + input_str[c_start:c_end], list(tag_list), result_array)
            parse_str(input_str[b_start:b_end] + input_str[c_start:c_end], [[tag, 0] for tag, f in tag_list], result_array)

        else:
            p = input_str.find("+")

            # extract a,b from "a+b"
            if p >= 0:
                a_str = input_str[:p].strip()
                b_str = input_str[p+1:]
            else:
                a_str = input_str
                b_str = ""

            tag_list.append([a_str, 1])
            parse_str(b_str, tag_list, result_array)

    result_list = []
    parse_str(input_str, [], result_list)
    return result_list

def split_str(input_str, delim):

    result_list = []

    total = len(input_str)
    j = 0
    start = 0
    level = 0
    while j < total:
        c = input_str[j]
        if c == '(':
            level += 1
        elif c == delim:
            if level == 0:
                result_list.append(input_str[start:j].strip())
                start = j+1
        elif c == ')':
            level -= 1
        j += 1
    
    input_str = input_str[start:].strip()
    if input_str:
        result_list.append(input_str)
    
    return result_list

def parse_app_info(input_str):
    m = re_app_data_tag.match(input_str)
    if m:
        if m.group(1):
            return (m.group(1)+m.group(3), m.group(2))
        else:
            return (m.group(3), m.group(2))
    return (None, None)

def eval_string(input_str):
    global g_count_python_eval
    global g_count_perl_eval
    
    if not g_setting_eval_macro:
        return (0, "")
    
    # try python version
    if input_str.find("?") < 0 and input_str.find("max") < 0:
        try:
            result_value = int(eval(input_str))
            if result_value >= 0:
                g_count_python_eval += 1
                return (result_value, "")
        except NameError:
            return (0, "")
        except SyntaxError:
            pass

    # try perl version
    #print >> sys.stderr, input_str
    
    g_count_perl_eval += 1
    fd, fn = tempfile.mkstemp(text=True)
    os.write(fd, "#!/usr/local/bin/perl -w")
    os.write(fd, "use List::Util qw[min max];")
    os.write(fd, '$a = "%s";' % (input_str))
    os.write(fd, "print eval($a);")
    os.close(fd)

    run_cmd = ["perl", fn]
    result = subprocess.Popen(run_cmd, shell = True, stdout = subprocess.PIPE, stderr = subprocess.PIPE)
    (my_out, my_err) = result.communicate()
   
    os.remove(fn)
    
    try:
        result_value = int(my_out)
    except:
        result_value = 0
    
    return (result_value, str(my_err))

def get_div_str(color, width, hint, data, align_right=False):
    if width=="0":
        return ""

    alignstr = ""
    if align_right:
        alignstr = "align=right"
    
    hintstr = ""
    if hint:
        hintstr = "title='%s'" % (hint)
    
    return "<div %s style='float:left;background-color:%s;width:%s%%;height:18px;' %s>%s</div>" % (alignstr, color, width, hintstr, data)

def get_percent_str(size, total):
    if size == 0:
        return "0"
    return "%.2f" % (float(size * 10000 / total)/100)

def number_to_str(number):
    if number < 0:
        return "??"
    elif number >= 1024 * 1024:
        return "%.1fM" % (float(number) / (1024 * 1024))
    elif number >= 1024:
        return "%.1fK" % (float(number) / 1024)
    else:
        return "%dB" % (number)

def get_converted_macro(path_list, app_list):
    map_list = {}
    for scen in path_list:
        for app_tag, flag in scen:
            appid, memtype = parse_app_info(app_tag)
            if not appid:
                continue
            
            try:
                size = app_list[appid].get_mem_size(memtype)
            except:
                size = 0
                
            disp_str = "%s(%s)" % (memtype.lower(), appid)
            map_list[app_tag] = ("<a class=app href='#%s' title='Size: %d(%s)'>%s</a>" % (appid, size, number_to_str(size), disp_str), len(disp_str))

    result_str = ""
    for scen in path_list:
        for app_tag, flag in scen:
            appid, memtype = parse_app_info(app_tag)
            if not appid:
                if flag:
                    result_str += app_tag + " + "
                else:
                    result_str += "&nbsp;" * (len(app_tag)+3)
            else:
                rep_str, rep_len = map_list[app_tag]
                if flag:
                    result_str += rep_str + " + "
                else:
                    result_str += "&nbsp;" * (rep_len+3)
        result_str = result_str[:-3] + "<br>"

    return result_str    

class app_info:
    def __init__(self, appid, cfg_list, data_list, size_list, detail_list):
        self.id = appid
        self.is_conc = appid.startswith("CONC")
        self.is_sub = False

        try:
            self.cfg_info = cfg_list[appid]
        except KeyError:
            self.cfg_info = []

        self.is_multi = len(self.cfg_info) > 1

        try:
            self.data_info = data_list[appid]
        except KeyError:
            self.data_info = {}

        try:
            self.size_info = size_list[appid]
        except KeyError:
            self.size_info = {}
        
        try:
            self.detail_info = detail_list[appid]
        except KeyError:
            self.detail_info = {}

        # set default size if not exist
        if 'FG' not in self.size_info:
            self.size_info['FG'] = 0
        if 'BASE' not in self.size_info:
            self.size_info['BASE'] = 0
        if 'TOTAL' not in self.size_info:
            self.size_info['TOTAL'] = self.size_info['FG'] + self.size_info['BASE']

        # setup dependency
        #self.dep_list = []
        #re_token = re.compile(r'\b\w+\b')
        #token_list = []
        #for value in self.cfg_info.itervalues():
        #    token_list += re_token.findall(value)
        #for token in token_list:
        #    if token in cfg_list and token != self.id:
        #        self.dep_list.append(token)

    def is_venus(self):
        if 'app_type' in self.data and self.data['app_type'] == 'venus':
            return True
        return False

    def get_mem_size(self, t):
        try:
            return self.size_info[t.upper()]
        except KeyError:
            return 0

    def get_macro_str(self, t):
        try:
            return self.data_info[t.upper()]
        except KeyError:
            return ""

    def get_max_path_list(self, memtype, app_list):

        # all path        
        path_list = parse_macro(self.get_macro_str(memtype))

        # find the max path
        max_path = path_list[0]
        if len(path_list) > 1:
            max_size = 0
            for path in path_list:
                size = 0
                for app_tag, flag in path:
                    appid, memtype = parse_app_info(app_tag)
    
                    if appid and appid in app_list:
                        size += app_list[appid].get_mem_size(memtype)
                        
                if size > max_size:
                    max_size = size
                    max_path = path

        # result
        result_path = []
        for app_tag, flag in max_path:
            appid, memtype = parse_app_info(app_tag)
            if appid == self.id:
                result_path += self.get_max_path_list(memtype, app_list)
            else:
                result_path.append([app_tag, 1])
        
        return result_path

    def print_html(self, app_list):
        
        total_size = self.get_mem_size('total')
        base_size = self.get_mem_size('base')
        fg_size = self.get_mem_size('fg')

        # title
        if self.is_conc:
            title_str = self.id
        else:
            title_str = "%s = %s (B:%s, F:%s)" % (self.id, number_to_str(total_size), number_to_str(base_size), number_to_str(fg_size))

            if base_size > total_size:
                title_str = "<font color=red>" + title_str + "</font>"
        print "<a name='%s'><H2>%s</H2>" % (self.id, title_str)
        
        # memory layout
        self.print_memory_layout(app_list)

        # Max path
        '''
        if self.get_mem_size('total') > 0:
            print "<H4>Maximum path</H4>"
            print "<table class=datatable><th>Type</th><th colspan=2>Size</th><th>Path</th>"
            if self.is_conc:
                print "<tr><td>total</td><td>%d</td><td>%s</td><td>%s</td></tr>" % (total_size, number_to_str(total_size), get_converted_macro([self.get_max_path_list('TOTAL', app_list)], app_list))
            else:
                print "<tr><td>base</td><td>%d</td><td>%s</td><td>%s</td></tr>" % (base_size, number_to_str(base_size), get_converted_macro([self.get_max_path_list('BASE', app_list)], app_list))
                print "<tr><td>fg</td><td>%d</td><td>%s</td><td>%s</td></tr>" % (fg_size, number_to_str(fg_size), get_converted_macro([self.get_max_path_list('FG', app_list)], app_list))
            print "</table>"
        '''

        # Macro
        #self.print_macro_str(app_list)
    
        # XML
        self.print_xml_str();

        # end
        print "<br><a href='#top'>back to top</a>"
        print "<HR>"

    #
    # when display_full = True, this API display a "full" memory layout (ruler, total, detail), used by normal app / concurrent
    # when display_full = False, this API display only "partial" memory layout (only detail), used by sub-config
    #
    def print_memory_layout(self, app_list, display_full = True, display_total_size = 0):
    
        total_size = self.get_mem_size('total')
    
        if total_size == 0:
            return

        if not display_full:
            total_size = display_total_size
    
        if display_full:
            #print >> sys.stderr, self.id
            print "<H4>Memory layout</H4>"
            print "<table class=bartable width=100%>"
        
            for size, name in [(1024*1024, '1M'), (1024*100, '100K')]:
                if total_size > size:
                    print "<tr><td>"
                    print get_div_str("#CCC", get_percent_str(size, total_size), name, name);
                    print "</td></tr>"
                    break
    
        # Total layout
        def print_path_list(result_list, app_list, padding_str=""):
            for scen in result_list:
                output_str = ""
                for app_tag, flag in scen:
                    #print >> sys.stderr, app_tag
                    appid, memtype = parse_app_info(app_tag)
                    if not appid:
                        size, err_str = eval_string(app_tag)
                        memtype = 'NUMBER'
                        hint_str = app_tag
                        content_str = 'number'
                    elif appid in app_list:
                        size = app_list[appid].get_mem_size(memtype)
                        hint_str = "%s(%s)" % (memtype.lower(), appid)
                        if appid == self.id:
                            content_str = memtype.lower()
                        else:
                            content_str = "<a class=app href='#%s'>%s</a>" % (appid, appid)
        
                            if memtype == 'TOTAL':
                                base_size = app_list[appid].get_mem_size('BASE')
                                if base_size > 0:
                                    content_str += "<div style='background-color:%s;width:%s%%;height:8px;' title='base = %s'></div>" % (g_bar_color['base'], get_percent_str(base_size, size), number_to_str(base_size))
                    else:
                        size = 0
                                                
                    if size > 0:
                        output_str += get_div_str(g_bar_color[memtype.lower()], get_percent_str(size, total_size), "%s = %s" % (hint_str, number_to_str(size)), content_str)
        
                if output_str:
                    print "<tr><td>"
                    print padding_str
                    print output_str
                    print "</td></tr>"

        # cui part, output "<tr><td>xxx</td></tr>"
        def print_cui(selfid, cui_str, app_list, padding_str, total_size):

            # recursively, output xxx
            def parse_cui_str(cui_str, kind, app_list, total_size=0xFFFFFFFF):
                
                #if selfid == 'APP_CALLSET2' and total_size != 0xFFFFFFFF:
                #    print >> sys.stderr, "[%5s] %s" % (kind, cui_str)
                
                return_size = 0
                return_str = ""
            
                m = re.match(r'^\s*(max)?\s*\(\s*([\w\W]+?)\s*\)\s*$', cui_str)
                if m:
                    if m.group(1) == 'max':
                        f = 'or'
                        delim = ','
                        content = m.group(2)
                    else:
                        f = 'and'
                        delim = '+'
                        content = m.group(2)
                else:
                    f = 'and'
                    delim = '+'
                    content = cui_str
            
                l = split_str(content, delim)
                
                if len(l) == 1:
                    appid = l[0]
                    if appid in app_list:

                        if kind == 'total':
                            memlist = ('base', 'fg')
                        elif kind == 'base':
                            memlist = ('base',)
                        
                        for memtype in memlist:
                            size = app_list[appid].get_mem_size(memtype)
                            if size == 0:
                                continue
                            hint_str = "%s(%s)" % (memtype, appid)
                            if appid == selfid:
                                content_str = memtype
                            else:
                                content_str = "<a class=app href='#%s'>%s</a>" % (appid, appid)

                            return_str += get_div_str(g_bar_color[memtype], get_percent_str(size, total_size), "%s = %s" % (hint_str, number_to_str(size)), content_str)
                            return_size += size
                    
                elif f == 'or':

                    max_size = 0
                    for s in l:
                        r1, foo = parse_cui_str(s, kind, app_list)
                        if r1 > max_size:
                            max_size = r1

                    str_list = []
                    for s in l:
                        str_list.append(parse_cui_str(s, kind, app_list, max_size)[1])

                    return_str = "<table class=cuitable width='%s%%'><tr><td>%s</tr></td></table>" % (get_percent_str(max_size, total_size), "</tr></td><tr><td>".join(str_list))
                    return_size = max_size
                
                elif f == 'and':
            
                    if kind == 'total':
            
                        max_size = 0
                        for s in l:
                            sum_size = 0
                            for s2 in l:
                                if s2 != s:
                                    sum_size += parse_cui_str(s2, "base", app_list)[0]
                            sum_size += parse_cui_str(s, "total", app_list)[0]
                            if sum_size > max_size:
                                max_size = sum_size

                        str_list = []
                        for s in l:
                            sum_str = ""
                            for s2 in l:
                                if s2 != s:
                                    sum_str += parse_cui_str(s2, "base", app_list, max_size)[1]
                            sum_str += parse_cui_str(s, "total", app_list, max_size)[1]
                            str_list.append(sum_str)
            
                        return_str = "<table class=cuitable width='%s%%'><tr><td>%s</tr></td></table>" % (get_percent_str(max_size, total_size), "</tr></td><tr><td>".join(str_list))
                        return_size = max_size
            
                    elif kind == 'base':
            
                        for s in l:
                            r1, r2 = parse_cui_str(s, kind, app_list, total_size)
                            if r1 > return_size:
                                return_size = r1
                            return_str += r2

                return (return_size, return_str)                         
                          
            print "<tr><td>"
            print padding_str
            s1, s2 = parse_cui_str(cui_str, 'total', app_list, total_size)
            print s2
            print "</tr></td>"
        
        if self.is_conc:
            print_path_list(parse_macro(self.get_macro_str('TOTAL')), app_list)
        else:

            # app base/fg
            if display_full:
                print "<tr><td>"
                for tag in ['BASE', 'FG']:
                    size = self.get_mem_size(tag)
                    disp_str = "%s(%s)" % (tag.lower(), self.id)
                    print get_div_str(g_bar_color[tag.lower()], get_percent_str(size, total_size), "%s = %s" % (disp_str, number_to_str(size)), tag.lower())
                print "</td></tr>"

            if self.is_multi:
                sub_count = len(self.cfg_info)
                for i in xrange(sub_count):
                    sub_id = "%s_S%dS_" % (self.id, i)
                    app_list[sub_id].print_memory_layout(app_list, False, total_size)
            else:
                # print app only (heap + extra_base + app_fg)
                print_path_list(parse_macro(" + ".join([t + self.id for t in ['ASM_HEAP_SIZE_', 'ASM_EXTRA_BASE_SIZE_', 'ASM_APP_FG_SIZE_']])), app_list)
    
                # print app + cui
                if self.cfg_info and 'cui' in self.cfg_info[0]:
                    size = self.get_mem_size('HEAP') + self.get_mem_size('EXTRA_BASE')
                    base_div = get_div_str('#F0F0F0', get_percent_str(size, total_size), "", "")
                    print_cui(self.id, self.cfg_info[0]['cui'], app_list, base_div, total_size)
    
        if display_full:
            print "</table>"
    
    def print_macro_str(self, app_list):
        
        # heap / extra_base / app_fg
        if self.is_conc:
            type_list = ['TOTAL']
        else:
            type_list = ['TOTAL', 'BASE', 'FG', 'HEAP', 'EXTRA_BASE', 'APP_FG', 'CUI_BASE', 'CUI_FG']
        
        print_str = ""
        for t in type_list:
            size = self.get_mem_size(t)
            macro_str = self.get_macro_str(t)

            if t in ['BASE', 'FG']:
                macro_str = macro_str.replace("ASM_CUI_%s_SIZE_%s" % (t, self.id), self.get_macro_str("CUI_" + t))
    
            if macro_str and t in ['TOTAL', 'BASE', 'FG', 'EXTRA_BASE', 'APP_FG']:
                macro_str = get_converted_macro(parse_macro(macro_str), app_list)
    
            if size > 0:
                print_str += "<tr><td>%s</td><td align=right>%d</td><td align=right>%s</td><td>%s</td></tr>" % (t.lower(), size, number_to_str(size), macro_str)
        if print_str:
            print "<H4>Macro</H4>"
            print "<table class=datatable><th>Type</th><th colspan=2>Size</th><th>Macro</th>"
            print print_str
            print "</table>"
    
    def print_xml_str(self):
        # Memory tag
        print "<H4>&lt;MEMORY&gt; XML data</H4>"

        tag_list = ['base', 'heap', 'extra_base', 'fg', 'cui', 'concurrent', 'concurrent_w_order']
        
        found = False
        for cfg in self.cfg_info:
            for tag in tag_list:
                if tag in cfg:
                    found = True
                    break

        if found:
            print "<table class='datatable'>"
            for cfg in self.cfg_info:
                print "<th>attr</th><th>value</th>"
                for tag in tag_list:
                    if tag in cfg:
                        print "<tr><td>%s</td><td>%s</td></tr>" % (tag, cfg[tag])
            print "</table>"
        else:
            print "n/a"        

def print_sort_by_size(id_list, app_list, max_size):
    size_sort_list = []
    for appid in id_list:
        app = app_list[appid]
        size_sort_list.append((app.get_mem_size('total'), app.get_mem_size('base'), app.get_mem_size('fg'), appid))
    size_sort_list.sort(reverse=True)

    print "<table class=datatable><th>Name</th><th colspan=3>Size</th><th width=100%>Percentage</th>"
    for size, basesize, fgsize, appid in size_sort_list:
        percent_value = get_percent_str(size, max_size)
        percent_base = get_percent_str(basesize, max_size)
        percent_fg = get_percent_str(fgsize, max_size)

        base_str = ""
        fg_str = ""
        percent_str = ""
        print "<tr><td><a href='#%s'>%s<a></td><td align=right>%d</td><td align=right>%s</td><td align=right>%s%%</td><td>" % (appid, appid, size, number_to_str(size), percent_value)
        if basesize != 0 or fgsize != 0:
            if basesize > 0:
                print get_div_str(g_bar_color['base'], percent_base, "", number_to_str(basesize), True)
            if fgsize > 0:
                print get_div_str(g_bar_color['fg'], percent_fg, "", number_to_str(fgsize), True)
        else:
            if size > 0:
                print get_div_str(g_bar_color['total'], percent_value, "", number_to_str(size), True)
        print "</td></tr>"
    print "</table>"

def print_apps_html(app_list, total_size):
    
    # --------------------------------------------------------------------------
    # collect data
    
    # find max name length of app
    max_len = 0
    for appid in app_list:
        app_len = len(appid)
        if app_len > max_len:
            max_len = app_len

    # group apps
    group_tags = ["CONC", "SRV", "CUI", "APP"]
    group_list = {}
    for appid in app_list:
        if app_list[appid].is_sub:
            continue
        found = False
        for t in group_tags:
            if appid.lower().find(t.lower()) >= 0:
                found = True
                try:
                    group_list[t].append(appid)
                except KeyError:
                    group_list[t] = [appid]
                break

        if not found:
            print >> sys.stderr, "Cannot group %s, skipped!" % (appid)
    for t in group_list:
        group_list[t].sort()

    if len(group_list) == 0:
        return

    # --------------------------------------------------------------------------
    # overview
    print "<H1>App Part</H1>"
    
    # ASM total size
    print "<H4>Total size = %d (%s)</H4>" % (total_size, number_to_str(total_size))
    
    # Sort by Size
    todo_list = []
    try:
        todo_list.append(group_list["CONC"] + group_list["APP"])
    except KeyError:
        try:
            todo_list.append(group_list["APP"])
        except KeyError:
            pass
    try:
        todo_list.append(group_list["CUI"])
    except KeyError:
        pass
    try:
        todo_list.append(group_list["SRV"])
    except KeyError:
        pass

    for group in todo_list:
        print_sort_by_size(group, app_list, total_size)
    print "<HR>"

    # --------------------------------------------------------------------------
    # index
    print "<a name='index'></a><H1>Index</H1>"
    print "<table class=datatable><tr>"
    percentage = 100 / len(group_list)
    for t in group_list:
        print "<th width=%d%%>%s</th>" % (percentage, t)
    print "</tr><tr>"
    for t in group_list:
        print "<td>"
        for appid in group_list[t]:
            print "<a href='#%s'>%s<a>%s" % (appid, appid, "&nbsp;" * (max_len-len(appid)))
        print "</td>"
    print "</tr></table><HR>"

    # --------------------------------------------------------------------------
    # each app
    for t in group_list:
        for appid in group_list[t]:
            if app_list[appid].is_sub:
                continue
            app_list[appid].print_html(app_list)

def print_globals_html(sizes, total_size):

    # --------------------------------------------------------------------------
    # overview
    print "<a name='_global'></a><H1>Global Part</H1>"
    
    # ASM total size
    print "<H4>Total size = %d (%s)</H4>" % (total_size, number_to_str(total_size))

    print "<table class=datatable><th>Name</th><th colspan=3>Size</th><th width=100%>Percentage</th>"
    
    ak = sizes.keys();
    ak.sort()
    for app_id in ak:
        size = sizes[app_id]
        percent_value = get_percent_str(size, total_size)
        
        print "<tr><td><a href='#%s'>%s<a></td><td align=right>%d</td><td align=right>%s</td><td align=right>%s%%</td><td>" % (app_id, app_id, size, number_to_str(size), percent_value)
        print get_div_str(g_bar_color['global'], percent_value, "", number_to_str(size), True)
        print "</td></tr>"
    print "</table><HR>"

def print_asm_overview(sizes):

    total_size = sizes['total']
    app_size = sizes['sub']
    global_size = sizes['global']
    anony_size = total_size - (app_size + global_size)

    type_info = ((app_size, "App", "#FF3"), (global_size, "Global", "#F90"), (anony_size, "Anonymous", "#3C0"))

    # --------------------------------------------------------------------------
    # overview
    print "<H1>Overview</H1>"
    
    # ASM total size
    print "<H4>ASM Pool Total size = %d (%s)</H4>" % (total_size, number_to_str(total_size))

    print "<table class=bartable width=100%><tr><td>"
    for size, name, clr in type_info:
        print get_div_str(clr, get_percent_str(size, total_size), "%d(%s)" % (size, number_to_str(size)), name);
    print "</td></tr></table>"    

    print "<table class=datatable>"
    print "<tr><th>Type</th><th>Size</th></tr>"
    for size, name, clr in type_info:
        print "<tr><td>%s</td><td>%d(%s)</td></tr>" % (name, size, number_to_str(size))
    print "</table><HR>"

def main(opt):

    # load name
    data = opt.mcu_path.split('\\')
    while True:
        load_name = data.pop()
        if load_name and load_name != 'mcu':
            break

    cfg_list, conc_list = parse_cfg_file(opt.cfg_path)
    data_list = parse_app_data_file(opt.app_path)
    size_list, detail_list = parse_obj_check_file(opt.obj_path)

    print >> sys.stderr, "mem_cfg(id, conc), rp_app_data, obj_check(size, detail) = %d, %d, %d, %d, %d" % (len(cfg_list), len(conc_list), len(data_list), len(size_list), len(detail_list))

    app_list = {}

    # each id in mem_cfg
    for appid in cfg_list:
        app = app_info(appid, cfg_list, data_list, size_list, detail_list)
        app_list[appid] = app
        
        if app.is_multi:
            for i in xrange(len(app.cfg_info)):
                sub_id = "%s_S%dS_" % (appid, i)
                app = app_info(sub_id, {sub_id: [cfg_list[appid][i], ]}, data_list, size_list, detail_list)
                app.is_sub = True
                app_list[sub_id] = app

    # treat conc as a new app
    for concs, conc_tag in conc_list:
        appid = 'CONC_' + '_'.join(concs)
        app = app_info(appid, {appid: [{conc_tag:', '.join(concs)},]}, data_list, size_list, detail_list)
        app_list[appid] = app

    # print html header
    print '''
<HTML>
<style type="text/css">
h1,h2,h3,h4,h5,h6 {font-family:Arial}
table.datatable {border-collapse:collapse;}
table.datatable th {font-family:Arial; background-color: #E5EECC; border:1px solid gray; padding: 2px; font-size: 0.9em;}
table.datatable td {font-family:Lucida Console; border:1px solid gray; padding: 2px; font-size: 0.9em;}
table.datatable td a:hover {background-color:#CFF;}
a.app:link {text-decoration:none;color:#000080;}
a.app:visited {text-decoration:none;color:#000080;}
a.app:hover {text-decoration:underline;}
a.app:active {text-decoration:underline;}
table.bartable {border-collapse:collapse;}
table.bartable td {font-family:Lucida Console; padding: 1px; font-size: 0.8em;}
table.bartable td div {border:1px solid gray; margin: 0px -1px; overflow:hidden;}
table.cuitable {float:left; border-collapse:collapse;}
table.cuitable td {font-family:Lucida Console; padding: 0px; font-size: 0.8em; vertical-align:middle;}
table.cuitable td div {border:1px solid gray; margin: 0px -1px; overflow:hidden;}
</style>
'''

    print "<TITLE>%s</TITLE><BODY>" % (load_name)
    print "<a name='top'></a><H1>%s</H1>%s" % (load_name, opt.mcu_path)

    if opt.app_name:
        try:
            app = app_list[opt.app_name]
            app.print_html(app_list)
        except KeyError:
            print >> sys.stderr, "< %s > not found!" % (opt.app_name)
    else:
        print_asm_overview(size_list['_ASM'])
        
        total_size = size_list['_ASM']['sub']
        print_apps_html(app_list, total_size)
        
        global_size = size_list['_ASM']['global']
        if global_size > 0:
            print_globals_html(size_list['_GLOBAL'], global_size)
        
    print '''
</BODY>
</HTML>
'''

    if g_setting_eval_macro:
        print >> sys.stderr, "Count of Python eval = %d" % (g_count_python_eval)
        print >> sys.stderr, "Count of Perl eval = %d" % (g_count_perl_eval)


if __name__ == "__main__":

    parser = OptionParser()
    parser.add_option("-f", dest="cfg_file")
    parser.add_option("--mcu", dest="mcu_path")
    parser.add_option("--proj", dest="proj_name")
    parser.add_option("--app", dest="app_name")
    parser.add_option("--html", dest="output_html", action="store_true", default=False)
    #parser.add_option("--eval", dest="eval_macro", action="store_true", default=False)
    
    (opt, args) = parser.parse_args()

    g_setting_eval_macro = True #opt.eval_macro

    if not opt.mcu_path:
        print >> sys.stderr, "Please use --mcu to specify load path"
        sys.exit(-1)

    if not os.path.exists(opt.mcu_path):
        print >> sys.stderr, "Can not open %s" % (opt.mcu_path)
        sys.exit(-1)

    opt.mcu_path = os.path.abspath(opt.mcu_path)

    if not opt.proj_name:
        entries = os.listdir(g_build_path % (opt.mcu_path))
        for d in entries:
            opt.proj_name = d
            break

    opt.cfg_path = g_cfg_path % (opt.mcu_path)
    opt.app_path = g_app_data_path % (opt.mcu_path)
    opt.obj_path = g_obj_log_path % (opt.mcu_path, opt.proj_name)

    error_found = False
    for check_path in [opt.cfg_path, opt.app_path, opt.obj_path]:
        if not os.path.exists(check_path):
            print >> sys.stderr, "Can not open %s" % (check_path)
            error_found = True
    if error_found:
        sys.exit(-1)


    if 0:
        a = r'450*1024 + 250*1024 + max(max(max(max(max(max(max(max(ASM_BASE_SIZE_VCUI_CONTACT_VIEW, ASM_BASE_SIZE_APP_DIALER), ASM_BASE_SIZE_VAPP_BOOKMARK_CUI), ASM_BASE_SIZE_VAPP_BROWSER), ASM_BASE_SIZE_VCUI_FMGR), ASM_BASE_SIZE_APP_DTCNT_CUI), ASM_BASE_SIZE_VCUI_CBM), ASM_BASE_SIZE_APP_MUSIC_PLAYER), ASM_BASE_SIZE_APP_GALLERY)'
        split_max(a, 14, True)
        sys.exit(0)
    if 0:
        a = r'ASM_BASE_SIZE_APP_MESSAGE + ASM_BASE_SIZE_APP_OPERA'
        print format_html_string(a, None)
        sys.exit(0)

    if 0:
        a, err = eval_string("max((150*1024 + (300*1024 + (150*1024))), max((600*1024 + (150*1024 + (300*1024 + (150*1024)))), (600*1024 + (0))))")
        print "1=== %s ====" % (a)
        print "2=== %s ====" % (err)
        sys.exit()

    if 0:
        result_list = parse_macro("1 + 2 + max(3 + max(10,11), max(4, max(max(5,8), max(6, 7))))");
        for line in result_list:
            for tag, f in line:
                if f:
                    print tag ,
                else:
                    print len(tag)*" " ,
            print ""
        sys.exit()

    if 0:
        a = r'A + B, max(C,D) + D, max(E, F+G),'
        print split_str(a, '+')
        sys.exit(0)


    if opt.cfg_file:
        print_cfg_in_excel(opt)
    else:
        main(opt)
