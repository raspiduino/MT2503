# Define source file lists to SRC_LIST
ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
SRC_LIST = inet_ps\ntpd\src\empty_mmi\ntpd_hld.c \
           inet_ps\ntpd\src\empty_mmi\ntpd_mem.c \
           inet_ps\ntpd\src\empty_mmi\ntpd_util.c \
           inet_ps\ntpd\src\empty_mmi\recvbuff.c
else
SRC_LIST = inet_ps\ntpd\src\ntpd_hld.c \
           inet_ps\ntpd\src\ntpd_mem.c \
           inet_ps\ntpd\src\ntpd_util.c \
           inet_ps\ntpd\src\recvbuff.c
endif
 
# Define include path lists to INC_DIR
INC_DIR = inet_ps\ntpd\include \
          applib\misc\include
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS =

 
