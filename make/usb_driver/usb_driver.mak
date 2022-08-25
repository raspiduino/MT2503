# Define source file lists to SRC_LIST
SRC_LIST = hal\connectivity\usb_driver\src\usb_phy_drv.c \
           hal\connectivity\usb_driver\src\usbms_ram.c \
           hal\connectivity\usb_driver\src\usbms_cdrom.c \
           hal\connectivity\usb_driver\src\upll_ctrl.c \
           hal\connectivity\usb_driver\src\usblog_drv.c \
           hal\connectivity\usb_driver\src\usb_dummy.c \
           hal\connectivity\usb_driver\src\dcl_usb_drv.c \
           hal\connectivity\usb_driver\src\dcl_usb_hcd.c \
           hal\connectivity\usb_driver\src\dcl_otg_drv.c

#  Define include path lists to INC_DIR
INC_DIR = drv\include \
          hal\connectivity\usb_driver\inc \
          usb\include \
          inc \
          hal\drv_def \
          interface\hal \
          interface\hal\connectivity\usb_driver \
          interface\hal\system \
          hal\system\regbase\inc \
          hal\system\dma\inc \
          hal\peripheral\inc

# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK

