# Define source file lists to SRC_LIST
SRC_LIST = ELL\ell-common\ell_os.c  \
ELL\ell_main.c \
ELL\ell_update\ell_update.c \
ELL\ell_update\ell_update_net.c \
ELL\ell_update\ell_update_net_apn.c \
ELL\ell_update\ell_update_fun.c \
ELL\ell_update\ell_update_watchdog.c \
ELL\ell_timer\ell_timer.c


#  Define include path lists to INC_DIR
INC_DIR = plutommi\MtkApp\FileMgr\FileMgrInc \
plutommi\framework\interface \
interface\hal\peripheral \
hal\peripheral\inc \
applib\misc\include \
GPS\MNL\include \
custom\drv\track_sensor\BMA250 \
custom\drv\track_sensor\KXTJ31057 \
custom\drv\track_sensor\SC7A20 \
custom\drv\track_sensor\AFA750 \
custom\drv\track_sensor\MC3410 \
custom\drv\track_sensor\MMA8452Q \
track\project\$(strip $(PROJECT_SUPPORT_TRACK))\inc\
track\drv\drv_inc \
track\os\os_inc \
track\drv\drv_inc \
track\fun\fun_inc \
track\at\at_inc \
ELL\ell-common \
ELL\ell-elf \
ELL\ell-hal \
ELL\ell-linker \
ELL\ell_update \
ELL\ell_timer


# Define the specified compile options to COMP_DEFS
COMP_DEFS = 


# Define the source file search paths to SRC_PATH
SRC_PATH = ELL \
ELL\ell-common \
ELL\ell-hal \
ELL\ell-linker \
ELL\ell_update \
ELL\ell_timer
