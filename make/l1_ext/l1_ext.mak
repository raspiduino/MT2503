# Define source file lists to SRC_LIST

SRC_LIST = l1_dm\l1d_ext\l1d_data.c \
           l1_dm\l1d_ext\m12190.c \
           l1_dm\l1d_ext\m12191.c \
           l1_dm\l1d_ext\m12192.c \
           l1_dm\l1d_ext\m12194.c \
           l1_dm\l1d_ext\m12195.c \
           l1_dm\l1d_ext\m12196.c

ifneq ($(filter __2G_RF_CUSTOM_TOOL_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST += l1_dm\l1d_ext\m12197.c
endif

#  Define include path lists to INC_DIR
INC_DIR = l1_dm\l1d_ext
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS = 
 

 
