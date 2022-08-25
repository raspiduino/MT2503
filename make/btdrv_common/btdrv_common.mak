

ifneq ($(filter __BTMODULE_MT6260__ , $(strip $(MODULE_DEFS))),)
	# Define source file lists to SRC_LIST
	SRC_LIST = hal\bluetooth\mt6260\common\btdrv_common.c
	
	#  Define include path lists to INC_DIR
	INC_DIR = hal\bluetooth\mt6260\common\include \
	          blueangel\btcore\btstack\inc \
	          interface\hal\bluetooth
else
ifneq ($(filter __BTMODULE_MT6261__ , $(strip $(MODULE_DEFS))),)
	# Define source file lists to SRC_LIST
	SRC_LIST = hal\bluetooth\mt6261\common\btdrv_common.c
	
	#  Define include path lists to INC_DIR
	INC_DIR = hal\bluetooth\mt6261\common\include \
	          blueangel\btcore\btstack\inc \
	          interface\hal\bluetooth
else
	# Define source file lists to SRC_LIST
	SRC_LIST = hal\bluetooth\common\btdrv_common.c
	
	#  Define include path lists to INC_DIR
	INC_DIR = hal\bluetooth\common\include \
	          blueangel\btcore\btstack\inc \
	          interface\hal\bluetooth
endif
endif
