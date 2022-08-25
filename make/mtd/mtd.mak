# Define source file lists to SRC_LIST
SRC_LIST = hal\storage\flash\mtd\src\flash_cfi.c \
           hal\storage\flash\mtd\src\flash_mtd.c \
           hal\storage\flash\mtd\src\flash_mtd.intel.c \
           hal\storage\flash\mtd\src\flash_mtd.amd.c \
           hal\storage\flash\mtd\src\flash_mtd.ramdisk.c \
           hal\storage\flash\mtd\src\flash_disk.c \
           hal\storage\flash\mtd\src\flash_mtd_sf_common.c \
           hal\storage\flash\mtd\src\flash_mtd_sf_dal.c \
           hal\storage\flash\mtd\src\flash_mtd_sf_ut.c \
           hal\storage\flash\mtd\src\flash_mtd_pf_dal.c

# Add by Kuohong
# NAND driver build condition
SRC_LIST += hal\storage\flash\mtd\src\NAND_MTD.c \
            hal\storage\flash\mtd\src\flash_user.c 
# #if ( defined(__NAND_FDM_50__) && (defined(__NFI_VERSION2__)||defined(__NFI_VERSION3_1__)) )
ifneq ($(filter __NAND_FDM_50__, $(strip $(MODULE_DEFS))),)
  ifneq ($(filter __NFI_VERSION2__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\storage\flash\mtd\src\NAND_DAL.c
    SRC_LIST += hal\storage\flash\mtd\src\NAND_MTD_FDM50.c
    SRC_LIST += hal\storage\flash\mtd\src\NAND_DevConfig.c
  else 
     ifneq ($(filter __NFI_VERSION3_1__, $(strip $(MODULE_DEFS))),)
       SRC_LIST += hal\storage\flash\mtd\src\NAND_DAL.c
       SRC_LIST += hal\storage\flash\mtd\src\NAND_MTD_FDM50.c
       SRC_LIST += hal\storage\flash\mtd\src\NAND_DevConfig.c
     endif
  endif
endif
# End Kuohong

# For SPI-NAND (begin)
ifneq ($(filter __NAND_FDM_50__, $(strip $(MODULE_DEFS))),)
  ifneq ($(filter __SNAND_VERSION2__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\storage\flash\mtd\src\SPI_NAND_DAL.c
    SRC_LIST += hal\storage\flash\mtd\src\SPI_NAND_MTD_FDM50.c
    SRC_LIST += hal\storage\flash\mtd\src\SPI_NAND_DevConfig.c  
    SRC_LIST += hal\storage\flash\mtd\src\bl_STT_SNAND.c 
  endif
endif
# For SPI-NAND (end)

#  Define include path lists to INC_DIR
INC_DIR = inc \
          sss\interface\inc \
          drv\include \
          hal\system\fota\inc \
          sst\include \
          init\include \
          hal\system\GFH\public \
          interface\hal\system \
          hal\system\dma\inc \
          hal\storage\flash\fdm\inc \
          hal\storage\flash\mtd\inc \
          hal\peripheral\inc  \
          custom\common\hal \
          interface\hal\L1 \
          hal\system\DP\inc
          

# Define the specified compile options to COMP_DEFS
COMP_DEFS = 


