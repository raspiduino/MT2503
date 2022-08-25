# NVRAM Editor
nvram_dir_list = common\hal common\ps common


def_h += $(foreach DIR,$(nvram_dir_list), \
  $(foreach FILE,$(shell if exist custom\$(DIR)\*_nvram_def.h dir custom\$(DIR)\*_nvram_def.h /b),$(FILE)) \
)
editor_h += $(foreach DIR,$(nvram_dir_list), \
  $(foreach FILE,$(shell if exist custom\$(DIR)\*_nvram_editor.h dir custom\$(DIR)\*_nvram_editor.h /b),$(FILE)) \
)

def_c +=$(foreach DIR,$(nvram_dir_list), \
  $(foreach FILE,$(shell if exist custom\$(DIR)\*_nvram_def.c dir custom\$(DIR)\*_nvram_def.c /b),$(FILE)) \
)
        
def_obj := $(patsubst %, %.obj, $(basename $(notdir $(def_c))))
tbl_list += logical_data_item_table_core \
        		logical_data_item_table_internal \
        		logical_data_item_table_factory \
					$(patsubst %, logical_data_item_table_%, $(subst _nvram_def.obj,,$(def_obj)))

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifneq ($(filter custom,$(CUS_REL_MTK_COMP)),)
      NVRAM_OBJ_LIST += $(patsubst %,$(strip $(CUS_MTK_LIB))\custom.lib(%.obj), $(basename $(notdir $(def_c)))) $(CUS_MTK_LIB)\custom.lib(nvram_data_items.obj) $(CUS_MTK_LIB)\custom.lib(fs_quota.obj)
  else
    ifneq ($(filter custom,$(COMPLIST)),)
          NVRAM_OBJ_LIST += $(patsubst %,$(strip $(COMPLIBDIR))\custom.lib(%.obj), $(basename $(notdir $(def_c)))) $(COMPLIBDIR)\custom.lib(nvram_data_items.obj) $(COMPLIBDIR)\custom.lib(fs_quota.obj)
    endif
  endif
  ifneq ($(filter nvram,$(CUS_REL_MTK_COMP)),)
      NVRAM_OBJ_LIST += $(strip $(CUS_MTK_LIB))\nvram.lib(nvram_factory_config.obj)
  else
    ifneq ($(filter nvram,$(COMPLIST)),)
      NVRAM_OBJ_LIST += $(strip $(COMPLIBDIR))\nvram.lib(nvram_factory_config.obj)
    endif
  endif
else
  ifneq ($(filter custom,$(COMPLIST)),)
        NVRAM_OBJ_LIST += $(patsubst %,$(strip $(COMPLIBDIR))\custom.lib(%.obj), $(basename $(notdir $(def_c)))) $(COMPLIBDIR)\custom.lib(nvram_data_items.obj) $(COMPLIBDIR)\custom.lib(fs_quota.obj)
  endif
  ifneq ($(filter nvram,$(COMPLIST)),)
        NVRAM_OBJ_LIST += $(strip $(COMPLIBDIR))\nvram.lib(nvram_factory_config.obj)
  endif
endif


ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
  ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
    ifneq ($(filter custom,$(COMPLIST)),)
      ifneq ($(filter custom,$(CUS_REL_MTK_COMP)),)
        NVRAM_OBJ_LIST += $(strip $(CUS_MTK_LIB))\custom.lib(nvram_common_config.obj) $(strip $(CUS_MTK_LIB))\custom.lib(nvram_user_config.obj)
      else
        NVRAM_OBJ_LIST += $(strip $(COMPLIBDIR))\custom.lib(nvram_common_config.obj) $(strip $(COMPLIBDIR))\custom.lib(nvram_user_config.obj)
      endif
    endif  
  else
    ifneq ($(filter custom,$(COMPLIST)),)
       NVRAM_OBJ_LIST += $(strip $(COMPLIBDIR))\custom.lib(nvram_common_config.obj) $(strip $(COMPLIBDIR))\custom.lib(nvram_user_config.obj)
    endif
  endif

	tbl_list +=logical_data_item_table_common_app logical_data_item_table_cust
endif

tbl_list +=g_fs_quota_init g_nvram_custpack_init

NVRAM_LNK_OPT := $(patsubst %, --keep=%, $(tbl_list))

NVRAM_EDITOR_H_TO_DB:
	@echo #ifdef GEN_FOR_PC >  custom\common\hal\nvram\nvram_editor.h
	@echo #ifndef __NVRAM_EDITOR_H__ >>  custom\common\hal\nvram\nvram_editor.h
	@echo #define __NVRAM_EDITOR_H__ >>  custom\common\hal\nvram\nvram_editor.h
  ifneq ($(words $(def_h)),0)
	@for %%f in ($(def_h)) do echo #include "%%f" >> custom\common\hal\nvram\nvram_editor.h
  endif
  ifneq ($(words $(editor_h)),0)
	@for %%f in ($(editor_h)) do echo #include "%%f" >> custom\common\hal\nvram\nvram_editor.h
  endif
	@echo #endif /* __NVRAM_EDITOR_H__ */ >>  custom\common\hal\nvram\nvram_editor.h
	@echo #endif /* GEN_FOR_PC */ >>  custom\common\hal\nvram\nvram_editor.h