# Define source file lists to SRC_LIST

ifneq ($(filter __XML_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST = xmlp\src\xml_main.c \
           xmlp\src\xmlgen_main.c \
           xmlp\src\xmlgen_test.c \
           xmlp\src\xmlgen_common.c
endif
           
ifneq ($(filter __WBXML_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += xmlp\src\wbxmlp_main.c \
           xmlp\src\wbxmlp_test.c \
           xmlp\src\wbxmlgen_main.c \
           xmlp\src\wbxmlgen_test.c
endif
           
 
# Define include path lists to INC_DIR
INC_DIR = interface\fs \
          xmlp\include \
          drm\include \
          plutommi\mmi\Inc \
          plutommi\Framework\CommonFiles\commoninc \
          plutommi\Framework\MemManager\MemManagerInc \
          applib\mem\include
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS =

 
