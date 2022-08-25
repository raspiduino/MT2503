# Define source file lists to SRC_LIST
SRC_LIST = usb\src\usb.c \
           usb\src\usb_adap.c \
           usb\src\usb_resource.c \
           usb\src\usbacm_drv.c \
           usb\src\usbacm_adap.c \
           usb\src\usbacm_ft.c \
           usb\src\usbacm_logging.c \
           usb\src\usbms_drv.c \
           usb\src\usbms_adap.c \
           usb\src\usbms_state.c \
           usb\src\usbvideo_drv.c \
           usb\src\usbvideo_state.c \
           usb\src\usb_mode.c \
           usb\src\usb_task.c \
           usb\src\usbd.c \
           usb\src\usb_host_default_drv.c \
           usb\src\usb_host_ms_drv.c \
           usb\src\usb_host_ms_state.c \
           usb\src\usb_host_ms_adap.c \
           usb\src\usb_host_acm_drv.c \
           usb\src\otg.c \
           usb\src\ptp_state.c \
           usb\src\usbimage_drv.c \
           usb\src\usbimage_mtp_state.c \
           usb\src\usb_debug_tool.c \
           usb\src\usbacm_echo.c
 
# Define include path lists to INC_DIR
INC_DIR = hal\connectivity\usb_driver\inc \
          usb\include \
          interface\hal\connectivity\usb_driver \
          interface\hwdrv \
          inc \
          fs\fat\include \
          hal\system\dcmgr\inc \
          $(strip $(PS_FOLDER))\l4\include
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWOR
 
 
