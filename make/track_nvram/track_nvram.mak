#This file for track

# Define source file lists to SRC_LIST


#  nvram
SRC_LIST += track\nvram\track_nvram_default_value.c

# Only need to be increased .c file in the above

#  Define include path lists to INC_DIR
INC_DIR =  track\os\os_inc\
           track\drv\drv_inc\
           track\at\at_inc\
           track\soc\soc_inc\
           track\cmd\cmd_inc\
           track\cust\cust_inc\
           track\fun\fun_inc\
           gps\mnl\include\
           hal\peripheral\inc\
           C_STL\C_STLInc\
           track_agps\inc\
	   kal\include\
	   interface\fs\
	   interface\hal\peripheral \
	   track\nvram


# Define the specified compile options to COMP_DEFS
COMP_DEFS = __GPS_TRACK__

# Define the source file search paths to SRC_PATH
SRC_PATH = track\os\os_src\
           track\drv\drv_src\
           track\at\at_src\
           track\soc\soc_src\
           track\cmd\cmd_src\
           track\cust\cust_src\
           track\fun\fun_src

#WATDOG
ifdef WATDOG
    ifneq ($(strip $(WATDOG)),NONE)
      COMP_DEFS += __WATCH_DOG__
      ifeq ($(strip $(WATDOG)),PULSE)
        COMP_DEFS += __WDT_PLUSE__
      endif
      ifeq ($(strip $(WATDOG)),IIC)
        COMP_DEFS += __WDT_USE_I2C__
      endif
  endif
endif
