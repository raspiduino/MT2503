# Define source file lists to SRC_LIST
SRC_LIST = nvram\src\nvram_factory_config.c \
           nvram\src\nvram_handler_read.c \
           nvram\src\nvram_handler_reset.c \
           nvram\src\nvram_handler_startup.c \
           nvram\src\nvram_handler_write.c \
           nvram\src\nvram_drval_fat.c \
           nvram\src\nvram_ilm.c \
           nvram\src\nvram_io.c \
           nvram\src\nvram_ltable.c \
           nvram\src\nvram_main.c \
           nvram\src\nvram_multi_folder.c \
           nvram\src\nvram_interface.c \
           nvram\src\nvram_l1def.c \
           nvram\src\nvram_util.c 

SRC_LIST += nvram\src\nvram_pseudo_merge.c

SRC_LIST += nvram\src\nvram_ex_io.c
SRC_LIST += nvram\src\nvram_msg_handler.c

ifneq ($(filter __UMTS_RAT__, $(strip $(MODULE_DEFS))),)
  ifneq ($(filter __MTK_UL1_FDD__, $(strip $(MODULE_DEFS))),)
	 SRC_LIST += nvram\src\nvram_ul1def.c
  endif
endif

ifneq ($(filter __NVRAM_COMPRESS_SUPPORT__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += nvram\src\nvram_unzip.c
endif



ifneq ($(filter TST_HANDLER, $(strip $(MODULE_DEFS))),)
	SRC_LIST += nvram\src\nvram_handler_tst.c
endif

ifneq ($(filter __NVRAM_UNIT_TEST__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += nvram\src\nvram_tst.c
endif




# ifneq ($(filter __XXX__, $(strip $(MODULE_DEFS))),)
#	SRC_LIST += xxxx\xxxxx\AAA.c
# endif
# ifeq ($(strip $(NAND_SUPPORT)),FALSE)
#                SRC_LIST += xxxx
# endif

# Define include path lists to INC_DIR
INC_DIR = nvram\include \
          init\include \
          custom\common custom\common\hal custom\common\ps \
          applib\misc\include \
          drv\include \
          plutommi\Customer\ResGenerator\zlib \
          security\sds \
          hal\system\ipc\inc \
          interface\ps\include \
          interface\ps\enum
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS =


COMP_DEFS += CURR_MODULE=MOD_$(strip $(call Upper,$(COMPONENT))) 
 
