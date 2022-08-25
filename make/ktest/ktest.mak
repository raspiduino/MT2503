# Define source file lists to SRC_LIST
SRC_LIST =
ifneq ($(filter __KTEST__, $(strip $(MODULE_DEFS))),)
SRC_LIST += mtkdebug\ktest\kal_autotest.c \
           mtkdebug\ktest\ktest_adaptation_oscar.c \
           mtkdebug\ktest\ktest_tc_timer.c \
           mtkdebug\ktest\ktest_tc_nu_timer.c \
           mtkdebug\ktest\ktest_lib_timer.c \
           mtkdebug\ktest\ktest_adaptation_target.c \
           mtkdebug\ktest\ktest_fsm.c \
           mtkdebug\ktest\ktest_interface.c \
           mtkdebug\ktest\ktest_tc_ipc.c \
           mtkdebug\ktest\ktest_tc_mm_adm.c \
           mtkdebug\ktest\ktest_tc_mm_afm.c \
           mtkdebug\ktest\ktest_tc_mm_ctrlbuf.c  \
           mtkdebug\ktest\ktest_tc_task.c \
           mtkdebug\ktest\ktest_tc_utl.c \
           mtkdebug\ktest\ktest_tc_mlib.c \
           mtkdebug\ktest\ktest_tc_sandbox.c
endif 
#  Define include path lists to INC_DIR
INC_DIR = config\include \
          kal\include \
          drv\include \
          usb\include \
          tst\include \
          interface\hwdrv \
          fsm\include \
          inc \
          mtkdebug\ktest
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS =

 
