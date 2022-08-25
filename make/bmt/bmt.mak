# Define source file lists to SRC_LIST
SRC_LIST = hal\peripheral\src\bmt_create.c 

OLD_BMT_ARCHITECTURE_PLATFORM = MT6252 MT6253 MT6276 MT6255 MT6256 MT6251 MT6235 MT6235B MT6236 MT6921 MT6922 MT6326 MT6268 MT6573 MT6575 
#OLD_BMT_ARCHITECTURE_PLATFORM = MT6252 MT6253 MT6276 MT6251 MT6235 MT6235B MT6236 MT6921 MT6922 MT6326 MT6268 MT6573 MT6575
ifneq ($(filter $(strip $(PLATFORM)) ,$(OLD_BMT_ARCHITECTURE_PLATFORM)),)
    SRC_LIST += hal\peripheral\src\bmt.c \
                hal\peripheral\src\bmtutil.c \
                hal\peripheral\src\bmt_main.c \
                hal\peripheral\src\bmt_ext_charger.c \
                hal\peripheral\src\bmt_ext_cable_fac_if.c \
                hal\peripheral\src\dcl_bmt_old.c 
else
   SRC_LIST += hal\peripheral\src\bmt_utility.c \
               hal\peripheral\src\bmt_task_main.c \
               hal\peripheral\src\bmt_sw_chip_setting.c \
               hal\peripheral\src\bmt_timer_control.c \
               hal\peripheral\src\bmt_hw.c \
               hal\peripheral\src\dcl_bmt.c  	
ifeq ($(strip $(CHARGING_ALGORITHM)),PULSE_LI_CHARGING)
   SRC_LIST += hal\peripheral\src\bmt_pulse_li.c 
endif
ifeq ($(strip $(CHARGING_ALGORITHM)),PULSE_NIMH_CHARGING)
   SRC_LIST += hal\peripheral\src\bmt_pulse_nimh.c
endif
ifeq ($(strip $(CHARGING_ALGORITHM)),LINEAR_LI_CHARGING)
   SRC_LIST += hal\peripheral\src\bmt_linear_li.c
endif
ifeq ($(strip $(CHARGING_ALGORITHM)),LINEAR_NIMH_CHARGING)
   SRC_LIST += hal\peripheral\src\bmt_linear_nimh.c
endif

ifneq ($(strip $(GENERAL_EXTERNAL_CHARGER)),NONE)
    SRC_LIST += hal\peripheral\src\bmt_external_chr_setting.c
else
    SRC_LIST += hal\peripheral\src\bmt_internal_chr_setting.c
endif

endif

#  Define include path lists to INC_DIR
INC_DIR = hal\peripheral\inc \
drv\include \
inc \
interface\hwdrv \
interface\hal\L1 \
interface\hal \
track\drv\drv_inc \
track\at\at_inc \
ELL\ell-common \
track\fun\fun_inc  \
track\at\at_inc \
track\os\os_inc  \
gps\mnl\include

# Define the specified compile options to COMP_DEFS
COMP_DEFS = BMT_KAL_DEBUG

# Define the source file search paths to SRC_PATH
SRC_PATH = hal\peripheral\src
