from public_def import *
from parse_value import *
from parse_xml import *
from output import *
from read_config import *
from copyfile import *
from public_var import g_is_open_vk3

def parseValueXml():
    valueObj = ParseValueXml()
    valueObj.parseAllValue()
    
def parseKeyBoardXml():
    parseObj = CParseKBXml()    
    parseObj.parseFile()

def outputFiles():
    global g_lang_list
    cgen = CGen()
    cgen.genStructs()
    cgen.genKeyBoardEnum()
    cgen.genKeyList()
    cgen.genKeyTypeList()
    cgen.genStructContent()
    cgen.genRowList()
    cgen.genKeyBoardList()
    cgen.genToggleStateList()

def checkFolder():
    checkDir()

def Main():
    print "Read Config Begin...."
    ret = readConfigMain()
    print "Read Config End..."

    if not ret:
        return 
    
    checkFolder()
    
    print "Parse Value Xmls..."
    parseValueXml()    
    
    print "Parse keyboard Xmls..."
    parseKeyBoardXml()
    
    print "output  datas..."
    outputFiles()

    copyfiles()
    
if __name__ == "__main__":
    Main()


    
