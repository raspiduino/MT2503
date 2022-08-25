# Define source file lists to SRC_LIST
ifeq ($(strip $(MMIDIR)),plutommi)
  SRC_LIST = plutommi\Customer\CustResource\themeres.c
endif

ifeq ($(strip $(MMIDIR)),lcmmi)
  SRC_LIST = lcmmi\Customer\CustResource\themeres.c
endif
 
# Define include path lists to INC_DIR
ifeq ($(strip $(MMIDIR)),plutommi)
INC_DIR = plutommi\Framework\GUI\gui_inc \
          plutommi\mmi\miscframework\miscframeworkinc \
          plutommi\Framework\GDI\gdiinc \
          plutommi\Framework\MemManager\memmanagerinc \
          applib\mem\include
endif

ifeq ($(strip $(MMIDIR)),lcmmi)
INC_DIR = lcmmi\mmi\gui\gui_inc \
          lcmmi\mmi\miscframework\miscframeworkinc \
          lcmmi\MtkApp\GDI\GDIInc \
          lcmmi\mmi\framework\osl\oslInc
endif

# Define the specified compile options to COMP_DEFS
ifeq ($(strip $(MMIDIR)),plutommi)
COMP_DEFS = MMI_ON_HARDWARE_P \
            __EMS__ \
            SIM_APP_TOOLKIT \
            TETRIS_GAME_APP \
            CM_APPLICATION_ENABLE \
            MESSAGES_APPLICATION \
            __UCS2_ENCODING \
            CELLBROADCAST_APP \
            __CB__ \
            VM_SUPPORT \
            SHORTCUTS_APP \
            T9LANG_Chinese \
            T9LANG_English \
            EMS_LITTLE_ENDIAN \
            EMS_MEM_MANAGEMENT \
            T9ALPHABETIC \
            T9CHINESE
endif

ifeq ($(strip $(MMIDIR)),lcmmi)
COMP_DEFS = MMI_ON_HARDWARE_P  \
            __EMS__ \
            SIM_APP_TOOLKIT \
            TETRIS_GAME_APP \
            CM_APPLICATION_ENABLE \
            MESSAGES_APPLICATION \
            __UCS2_ENCODING \
            CELLBROADCAST_APP \
            __CB__ \
            VM_SUPPORT \
            SHORTCUTS_APP \
            T9LANG_Chinese \
            T9LANG_English \
            EMS_LITTLE_ENDIAN \
            EMS_MEM_MANAGEMENT \
            T9ALPHABETIC \
            T9CHINESE
endif

 
ifeq ($(strip $(MMIDIR)),plutommi)
endif

ifeq ($(strip $(MMIDIR)),lcmmi)
endif
 
