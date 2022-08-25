
########################################## Makefile Usage ##########################################
#
# 1.Define source file lists to SRC_LIST
# 3.Define header file path to INC_DIR
# 4.Do not use the same name for 2(or more) files in different folders, even if they are wrapped by
#   compiler options.
# 5.In the beginning of a line, do not use "TAB" to instead "SPACE".
# 6.In the ending of a line, after "\", there should not any character, including "SPACE".
# 7.In the ending of the last line of a description segment, there should not an "\" there.
# 8.In the description of filter : ifneq ($(filter MT62XX, $(strip $(MODULE_DEFS))),), pay attention
#   to reserve "SPACE" in it.
#
####################################################################################################

ifneq ($(filter MT6251, $(strip $(MODULE_DEFS))),)
SRC_LIST = hal\display\ddv1\src\mt6251lcd\lcd_if_6251.c \
           hal\display\ddv1\src\mt6251lcd\lcd_lcm_if_6251.c \
           hal\display\ddv1\src\mt6251lcd\lcd_isr_handler_6251.c \
           hal\display\ddv1\src\mt6251lcd\lcd_update_if_6251.c \
           hal\display\ddv1\src\lcd_dummy.c \
           hal\display\ddv1\src\lcd_interface_manager.c

else ifneq ($(filter MT6573, $(strip $(MODULE_DEFS))),)
SRC_LIST = hal\display\ddv1\src\lcd_if.c \
           hal\display\ddv1\src\lcd_lcm_if.c \
           hal\display\ddv1\src\lcd_isr_handler.c \
           hal\display\ddv1\src\lcd_update_if.c \
           hal\display\ddv1\src\lcd_update_idp_series.c \
           hal\display\ddv1\src\tv_out.c \
           hal\display\ddv1\src\tv_out_test.c \
           hal\display\ddv1\src\lcd_dummy.c \
           hal\display\ddv1\src\lcd_interface_manager.c

else ifneq ($(filter MT6516, $(strip $(MODULE_DEFS))),)
SRC_LIST = hal\display\ddv1\src\lcd_if.c \
           hal\display\ddv1\src\lcd_lcm_if.c \
           hal\display\ddv1\src\lcd_isr_handler.c \
           hal\display\ddv1\src\lcd_update_if.c \
           hal\display\ddv1\src\lcd_update_idp_series.c \
           hal\display\ddv1\src\tv_out.c \
           hal\display\ddv1\src\tv_out_test.c \
           hal\display\ddv1\src\lcd_dummy.c \
           hal\display\ddv1\src\lcd_interface_manager.c

else
SRC_LIST = hal\display\adapter\src\wfd_lcd_adapter.c \
           hal\display\common\src\lcm_proxy.c \
           hal\display\common\src\owfimage.c \
           hal\display\common\src\owfnativestream.c \
           hal\display\lcd_if_manager\src\lcd_if_manager.c \
           hal\display\lcd_power_manager\src\lcd_power_mgr.c \
           hal\display\lcd_tear_manager\src\lcd_tear_manager.c \
           hal\display\wfc\src\wfc_autonomous.c \
           hal\display\wfc\src\wfcapi.c \
           hal\display\wfd\src\wfd_lcd_common.c \
           hal\display\wfd\src\wfdapi.c \
           hal\display\common\src\lcd_em.c \
           hal\display\common\src\display_io.c \
           hal\display\flatten\src\flatten_api.c
endif

ifneq ($(filter MT6235, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\display\lcd_tear_manager\src\lcd_tear_6235.c \
            hal\display\wfd\src\hw_6235\wfd_hwdevice_6235.c \
            hal\display\wfd\src\hw_6235\wfd_lcd_6235.c \
            hal\display\exception\lcd_exception_api_6235.c

else ifneq ($(filter MT6235B, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\display\lcd_tear_manager\src\lcd_tear_6235.c \
            hal\display\wfd\src\hw_6235\wfd_hwdevice_6235.c \
            hal\display\wfd\src\hw_6235\wfd_lcd_6235.c \
            hal\display\exception\lcd_exception_api_6235.c

else ifneq ($(filter MT6236, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\display\lcd_tear_manager\src\lcd_tear_6236.c \
            hal\display\wfd\src\hw_6236\wfd_govl_6236.c \
            hal\display\wfd\src\hw_6236\wfd_hwdevice_6236.c \
            hal\display\wfd\src\hw_6236\wfd_lcd_6236.c \
            hal\display\exception\lcd_exception_api_6236.c \
            hal\display\flatten\src\hw_6236\flatten_api_6236.c

else ifneq ($(filter MT6236B, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\display\lcd_tear_manager\src\lcd_tear_6236.c \
            hal\display\wfd\src\hw_6236\wfd_govl_6236.c \
            hal\display\wfd\src\hw_6236\wfd_hwdevice_6236.c \
            hal\display\wfd\src\hw_6236\wfd_lcd_6236.c \
            hal\display\exception\lcd_exception_api_6236.c \
            hal\display\flatten\src\hw_6236\flatten_api_6236.c

else ifneq ($(filter MT6268, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\display\lcd_tear_manager\src\lcd_tear_6268.c \
            hal\display\wfd\src\hw_6268\wfd_hwdevice_6268.c \
            hal\display\wfd\src\hw_6268\wfd_lcd_6268.c \
            hal\display\exception\lcd_exception_api_6268.c

else ifneq ($(filter MT6268A, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\display\lcd_tear_manager\src\lcd_tear_6268.c \
            hal\display\wfd\src\hw_6268\wfd_hwdevice_6268.c \
            hal\display\wfd\src\hw_6268\wfd_lcd_6268.c \
            hal\display\exception\lcd_exception_api_6268.c

else ifneq ($(filter MT6253, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\display\lcd_tear_manager\src\lcd_tear_6253.c \
            hal\display\wfd\src\hw_6253\wfd_hwdevice_6253.c \
            hal\display\wfd\src\hw_6253\wfd_lcd_6253.c \
            hal\display\exception\lcd_exception_api_6253.c

else ifneq ($(filter MT6252H, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\display\lcd_tear_manager\src\lcd_tear_6252H.c \
            hal\display\wfd\src\hw_6252\wfd_hwdevice_6252.c \
            hal\display\wfd\src\hw_6252\wfd_lcd_6252.c \
            hal\display\exception\lcd_exception_api_6252.c

else ifneq ($(filter MT6252, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\display\lcd_tear_manager\src\lcd_tear_6252.c \
            hal\display\wfd\src\hw_6252\wfd_hwdevice_6252.c \
            hal\display\wfd\src\hw_6252\wfd_lcd_6252.c \
            hal\display\exception\lcd_exception_api_6252.c

else ifneq ($(filter MT6276, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\display\lcd_tear_manager\src\lcd_tear_6276.c \
            hal\display\wfd\src\hw_6276\wfd_govl_6276.c \
            hal\display\wfd\src\hw_6276\wfd_hwdevice_6276.c \
            hal\display\wfd\src\hw_6276\wfd_lcd_6276.c \
            hal\display\exception\lcd_exception_api_6276.c \
            hal\display\flatten\src\hw_6276\flatten_api_6276.c

else ifneq ($(filter MT6256, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\display\lcd_tear_manager\src\lcd_tear_6256.c \
            hal\display\wfd\src\hw_6256\wfd_hwdevice_6256.c \
            hal\display\wfd\src\hw_6256\wfd_lcd_6256.c \
            hal\display\exception\lcd_exception_api_6256.c

else ifneq ($(filter MT6255, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\display\lcd_tear_manager\src\lcd_tear_6255.c \
            hal\display\wfd\src\hw_6255\wfd_hwdevice_6255.c \
            hal\display\wfd\src\hw_6255\wfd_lcd_6255.c \
            hal\display\exception\lcd_exception_api_6255.c \
            hal\display\flatten\src\hw_6255\flatten_api_6255.c

else ifneq ($(filter MT6250, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\display\lcd_tear_manager\src\lcd_tear_6250.c \
            hal\display\wfd\src\hw_6250\wfd_hwdevice_6250.c \
            hal\display\wfd\src\hw_6250\wfd_lcd_6250.c \
            hal\display\exception\lcd_exception_api_6250.c \
            hal\display\flatten\src\hw_6250\flatten_api_6250.c            

else ifneq ($(filter MT6260, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\display\lcd_tear_manager\src\lcd_tear_6260.c \
            hal\display\wfd\src\hw_6260\wfd_hwdevice_6260.c \
            hal\display\wfd\src\hw_6260\wfd_lcd_6260.c \
            hal\display\exception\lcd_exception_api_6260.c \
            hal\display\flatten\src\hw_6260\flatten_api_6260.c            

else ifneq ($(filter MT6261, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\display\lcd_tear_manager\src\lcd_tear_6260.c \
            hal\display\wfd\src\hw_6260\wfd_hwdevice_6260.c \
            hal\display\wfd\src\hw_6260\wfd_lcd_6260.c \
            hal\display\exception\lcd_exception_api_6260.c \
            hal\display\flatten\src\hw_6260\flatten_api_6260.c            

else ifneq ($(filter MT2501, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\display\lcd_tear_manager\src\lcd_tear_6260.c \
            hal\display\wfd\src\hw_6260\wfd_hwdevice_6260.c \
            hal\display\wfd\src\hw_6260\wfd_lcd_6260.c \
            hal\display\exception\lcd_exception_api_6260.c \
            hal\display\flatten\src\hw_6260\flatten_api_6260.c            

else ifneq ($(filter MT2502, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\display\lcd_tear_manager\src\lcd_tear_6260.c \
            hal\display\wfd\src\hw_6260\wfd_hwdevice_6260.c \
            hal\display\wfd\src\hw_6260\wfd_lcd_6260.c \
            hal\display\exception\lcd_exception_api_6260.c \
            hal\display\flatten\src\hw_6260\flatten_api_6260.c            

else
endif

#  Define include path lists to INC_DIR
INC_DIR = drv\include \
          hal\storage\mc\inc \
          hal\peripheral\inc \
          hal\display \
          hal\display\ddv1\include \
          inc \
          sst\include \
          media\image\include \
          interface\hal \
          interface\hal\mm_comm \
          interface\hal\display \
          interface\hal\display\ddv1 \
          hal\display\common\include \
          interface\hal\drv_sw_def \
          interface\hal\display\common \
          interface\hal\display\lcm_if \
          interface\hal\display\exception \
          hal\display \
          plutommi\Framework\GDI\GDIInc \
          plutommi\mtkapp\filemgr\filemgrinc \
          hal\mm_comm\inc \
          btmt\rf_desense \
          hal\display\flatten\inc \
          hal\graphics\color\hw\inc \
          interface\hal\graphics \
          interface\hal\display\flatten \
          hal\graphics\g2d\common\inc

# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK

