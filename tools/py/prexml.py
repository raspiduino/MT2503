import os, sys
from maui import *
import makeOpt
import os.path
import re
import cPickle as pickle
import traceback
import xml
import xml.etree.ElementTree as ET
import StringIO
# ------------------------------------------------------------------------------
#   Global Data 
# ------------------------------------------------------------------------------

#
# This is most important data, we will store compile options into this dictionary.
#
opt = {}

# ------------------------------------------------------------------------------
#   Do pre-processor
# ------------------------------------------------------------------------------    
    
class PreProcessor:
    
    # Static members
    re_comments = re.compile(r"/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+/")
    
    re_comment  = re.compile(r"\/\*.*\*\/")
    re_comment2 = re.compile(r"\/\/.*$")
    re_define   = re.compile(r"defined\s*\(\s*(\w+)\s*\)")
    re_or       = re.compile(r"\s*\|\|\s*")
    re_and      = re.compile(r"\s*\&\&\s*")
    re_not      = re.compile(r"\s*\!\s*")
    
    re_option   = re.compile(r"\[\s*(.+)\s*]")
    re_co       = re.compile(r"^\s*#\s*(ifdef|ifndef|else|endif|elif|if)")
    re_co_ifdef = re.compile(r"^\s*#\s*ifdef\s*(\w+)")
    re_co_ifndef= re.compile(r"^\s*#\s*ifndef\s*(\w+)")
    re_macros   = re.compile(r"(\$\(.+?\))")
    re_macro    = re.compile(r"\$\((.+?)\)")
    
    def define(s):
        global opt
        return s in opt
        
    loc = {}
    loc['defined'] = define
    
    # Methods    
    def __init__(self):
        self.idx = 0
        self.lns = []
        self.doc = []
        self.has_xml_if = False
            
    def process_file(self, filename):
        file_content = file(filename).read()
        # remove /* comments */
        # file_content = re_comments.sub('', file_content)        
        self.lns = file_content.splitlines()
        self.Do_content(True)

    def Do_xml_tag(self, parent, ele):
        #print "<", ele.tag, ">"
        for name, value in ele.items():
            #print name, "=", value
            if name == "if":
                if not self.Expression(value):
                    parent.remove(ele)
                    self.has_xml_if = True
                    return

        if "if" in ele.attrib:
            del ele.attrib["if"]
                
        for child in ele.getchildren()[:]:
            self.Do_xml_tag(ele, child)

    def process_as_xml(self, output = None):
        docs = "\n".join(self.doc)
        try:
            et = ET.ElementTree(file=StringIO.StringIO(docs))
        except xml.parsers.expat.ExpatError, error:
            print >> sys.stderr, '-' * 79
            print >> sys.stderr, 'XML parse Error:', error.message
            print >> sys.stderr, self.doc[error.lineno-1]
            print >> sys.stderr, ' ' * (error.offset - 1) + '^'
            print >> sys.stderr, '-' * 79
            sys.exit(-1)
        
        self.doc = []
        self.Do_xml_tag(None, et.getroot())
        
        if output:
            outpath = os.path.dirname(output);
            if outpath and not os.path.exists(outpath):
                os.makedirs(outpath)
                
            if self.has_xml_if:
                et.write(file(output, "w"))
            else:
                f = open(output, 'w')
                try:
                    f.write(docs);
                finally:
                    f.close()    
        else:
            if self.has_xml_if:
                et.write(sys.stdout)
            else:
                print docs
        pass        

    def Expression(self, s):
        global opt
        s = self.re_define.sub(r'defined("\1")', s)
        s = self.re_and.sub(r' and ', s)
        s = self.re_or.sub(r' or ', s)
        s = self.re_not.sub(r' not ', s)
        try:
            r = eval(s, opt, self.loc)
        except TypeError, error:
            print >> sys.stderr, '-' * 79
            print >> sys.stderr, "Error: evaluate expression error:", s
            print >> sys.stderr, error.message
            print >> sys.stderr, '-' * 79
            sys.exit(-1)
        return r

    def Remove_Comment(self, s):
        s = self.re_comments.sub('', s)
        return s
        
    def Do_Express(self):
        ln = self.lns[self.idx]
        ln = self.Remove_Comment(ln)
        rep = self.re_co.match(ln)
        
        if rep:
            code = rep.groups()[0]
        
            if code in ('else', 'endif'):
                return code, None
            
            if code == 'ifdef':
                exp = self.re_co_ifdef.match(ln).groups()[0]
                return code, exp in opt
        
            if code == 'ifndef':
                exp = self.re_co_ifndef.match(ln).groups()[0]
                return code, exp not in opt
            
            if code in ('if', 'elif'):
                exp = self.re_co.sub('', ln)
                return code, self.Expression(exp.strip())
        
        return None, None
            
        
    def Do_if(self, v):
        find_true = False
        
        while 1:
            if self.idx >= len(self.lns):
                break
            
            code, res = self.Do_Express()
            self.idx += 1 
            
            if code == None:
                self.Do_line(self.lns[self.idx], v)
                    
            else:
                if v:
                    self.doc.append('')
                if code == 'endif':
                    break
                    
                elif code == 'else':
                    if not find_true:
                        self.Do_content(v)
                    else:
                        self.Do_content(False)
                elif code[:2] == 'if' or code == 'elif':
                    if res:
                        if not find_true:
                            find_true = True
                            self.Do_content(v)
                        else:
                            self.Do_content(False)
                    else:
                        self.Do_content(False)
    
    def Do_line(self, ln, v):
        if not v:
            self.doc.append('')
            return

        s = ''
        for i in self.re_macros.split(ln):
            m = self.re_macro.match(i)
            if m:
                macro = m.groups()[0].strip()
                try:
                    r = eval(macro, opt)
                    s += str(r)
                except Exception, error:
                    print >> sys.stderr, '-' * 79
                    print >> sys.stderr, 'Evaluate error:', error.message
                    print >> sys.stderr, 'In line', self.idx + 1, ':', macro
                    print >> sys.stderr, '-' * 79
                    sys.exit(-1)
            else:
                s += i            
        self.doc.append(s)
                
    def Do_content(self, v):
        while self.idx < len(self.lns):
            ln = self.lns[self.idx]
            
            if self.re_co.match(ln):
                code = self.re_co.match(ln).groups()[0]
                if code[:2] == 'if':
                    self.Do_if(v)
                else:
                    return # exit a block
            else:
                ln = self.Do_line(ln, v)
                self.idx += 1


if __name__ == '__main__':
    
    input_name = ''
    output_name = None
    
    # ------------------------------------------------------------------------------
    #   Check argument
    # ------------------------------------------------------------------------------
    
    argIdx = 0
    for arg in sys.argv:
        
        # special argument
        if arg[0] == '-':
            continue
            
        if argIdx == 0:
            pass
        elif argIdx == 1:
            input_name = arg
        elif argIdx == 2:
            output_name = arg
    
        argIdx += 1
    
    if not input_name:
        print >> sys.stderr, '-' * 79
        print >> sys.stderr, 'Usage: preOpt input_filename [output_filename]'
        print >> sys.stderr, '-' * 79
        sys.exit(-1)
    
    if not os.path.exists(input_name):
        error_exit('Cannot find input filename:', input_name)
    
    # ------------------------------------------------------------------------------
    #   Read option values
    # ------------------------------------------------------------------------------
    
    opt = makeOpt.getOpt()
    
    print '[prexml] Read option count:', len(opt)
    
    pre_processor = PreProcessor()
    pre_processor.process_file(input_name)
    pre_processor.process_as_xml(output_name)
