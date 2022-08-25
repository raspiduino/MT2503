include ../include/custom_include.txt
include ../include/custom_option.txt


.PHONY: nvram_auto_gen 

modem_dir := ../../../custom/common/ps
nvram_dir := ../../../custom/common/hal/nvram
bsp_dir := ../../../custom/common/hal
mmi_dir := ../../../custom/common

bsp_src := $(basename $(notdir $(wildcard $(bsp_dir)/*_nvram_def.c)))
modem_src := $(basename $(notdir $(wildcard $(modem_dir)/*_nvram_def.c)))
mmi_src := $(basename $(notdir $(wildcard $(mmi_dir)/*_nvram_def.c)))
#nvram_src := $(basename $(notdir $(wildcard $(nvram_dir)/*.c)))

bsp_obj := $(patsubst %, ../debug/%.o, $(bsp_src))
modem_obj := $(patsubst %, ../debug/%.o, $(modem_src))
mmi_obj := $(patsubst %, ../debug/%.o, $(mmi_src))
#nvram_obj := $(patsubst %, ../debug/%.o, $(nvram_src))

NVM_CUST_SRC = \
BSP_LIST \
MODEM_LIST \
nvram_data_items.o \
nvram_cust_pack.o \
custom_nvram_sec.o \
nvram_gen_util.o

ifneq ($(filter "__MMI_FMI__", $(strip $(CUSTOM_OPTION))),)

	NVM_CUST_SRC += nvram_common_config.o nvram_user_config.o custom_nvram_cat.o
endif

ifneq ($(words $(mmi_src)), 0)
  NVM_CUST_SRC += MMI_LIST    
endif


#Vendor only can compile these files
NVM_VENDOR_SRC = nvram_gen_util.o

ifneq ($(filter "__MMI_FMI__", $(strip $(CUSTOM_OPTION))),)
    NVM_VENDOR_SRC += nvram_user_config.o
endif



NVM_CORE_SRC = \
nvram_factory_config.o

NVM_GEN_SRC = \
nvram_auto_gen.o

NVM_LNK_CMD = \
-Xlinker --script=nvram_auto_gen.txt -Xlinker --Map -Xlinker ../debug/nvram_auto_gen.map

NVM_GEN_OBJS = \
../debug/nvram_auto_gen.o \
../debug/nvram_gen_util.o \
../debug/nvram_factory_config.o \
../debug/nvram_data_items.o \
../debug/nvram_cust_pack.o \
../debug/custom_nvram_sec.o \
../debug/fs_quota_entry_dump.o \
$(modem_obj) \
$(bsp_obj)

ifneq ($(filter "__MMI_FMI__", $(strip $(CUSTOM_OPTION))),)
    NVM_GEN_OBJS += ../debug/nvram_user_config.o \
                    ../debug/nvram_common_config.o \
                    ../debug/custom_nvram_cat.o \
                    $(mmi_obj)
endif

ifneq ($(filter "__FS_QM_SUPPORT__", $(strip $(CUSTOM_OPTION))),)
    NVM_GEN_OBJS += ../debug/fs_quota.o
endif

QUOTA_SRC = fs_quota_entry_dump.o

ifneq ($(filter "__FS_QM_SUPPORT__", $(strip $(CUSTOM_OPTION))),)
	QUOTA_SRC += fs_quota.o
endif

ifeq ($(strip $(LEVEL)), VENDOR) # vendor release
	NVM_OPTION =  -fshort-enums  -D "NVRAM_AUTO_GEN" -D "__VENDOR_RELEASE__"
else
	NVM_OPTION =  -fshort-enums  -D "NVRAM_AUTO_GEN" 
endif

NVM_INC = -I "../include"


NVM_OPTION += -D "__NVRAM_SPLIT__"

QUOTA_OPTION =  -D "BUILD_TIME_CHECK_GEN" -D "GEN_FOR_PC"
QUOTA_INC = -I "../../../custom/common/"


#Using the folder from resource generator
MTK_DEFS = \
	-D "__MULTI_BIN_LOAD__" \
	-D "__EXE_DLL__"



############ MMI CACHE Makefile ####################################

ifeq ($(strip $(MMI_FOLDER)), NEPTUNE_MMI) 
	MMI_CACHE_GEN_CMD = \
	../debug/nvram_gen_mmi_cache.o \
	../debug/common_mmi_cache_config.o \
	../debug/custom_mmi_cache_config.o 
else
	MMI_CACHE_GEN_CMD = \
	../debug/nvram_gen_mmi_cache.o
endif

ifeq ($(strip $(MMI_FOLDER)), NEPTUNE_MMI) 
	NVM_CACHE_OBJS = \
	nvram_gen_mmi_cache.o \
	common_mmi_cache_config.o \
	custom_mmi_cache_config.o
else
	NVM_CACHE_OBJS = \
	nvram_gen_mmi_cache.o
endif

.SUFFIXES: .o .cpp .c .txt

############### mmi cache compiling ####################

common_mmi_cache_config.o: ../../../custom/common/${MMI_FOLDER}/common_mmi_cache_config.c
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC) -w -c $< -MMD -MF ../debug/$(basename $(@F)).d -o ../debug/$@
	echo "common_mmi_cache_config.o done"

custom_mmi_cache_config.o: ../../../custom/app/$(strip $(CUSTOM_FOLDER))/custom_mmi_cache_config.c
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC) -w -c $< -MMD -MF ../debug/$(basename $(@F)).d -o ../debug/$@
	echo "custom_mmi_cache_config.o done"

nvram_gen_mmi_cache.o: nvram_gen_mmi_cache.c
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC) -w -c $< -MMD -MF ../debug/$(basename $(@F)).d -o ../debug/$@
	echo "nvram_gen_mmi_cache.o done"

ifeq ($(strip $(LEVEL)), LEVEL2_OBJ)
  mmi_cache_gen: $(NVM_CACHE_OBJS)
	gcc -o ../debug/mmi_cache_gen $(MMI_CACHE_GEN_CMD)
	echo "build level2_obj nvram_auto_gen done" 
else
  ifeq ($(strip $(LEVEL)), VENDOR) # vendor release
    mmi_cache_gen: 
		gcc -o ../debug/mmi_cache_gen $(MMI_CACHE_GEN_CMD)
		echo "build vendor mmi_cache_gen done"
  else 
    mmi_cache_gen: $(NVM_CACHE_OBJS)
		gcc -o ../debug/mmi_cache_gen $(MMI_CACHE_GEN_CMD)
		echo "build mmi_cache_gen done"
  endif
endif


############ nvram_auto_gen compiling ####################################

MMI_LIST:
	echo "Building MMI: $(notdir $(mmi_src))"
	for f in $(mmi_src) ; do \
	  echo Compile $(mmi_dir)/$$f.c; \
	  gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC)  -w -c $(mmi_dir)/$$f.c -MMD -MF ../debug/$$f.d -o ../debug/$$f.o; \
	done

BSP_LIST:
	echo "Building BSP: $(notdir $(bsp_src))"
	for f in $(bsp_src) ; do \
	  echo Compile $(bsp_dir)/$$f.c; \
	  gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC)  -w -c $(bsp_dir)/$$f.c -MMD -MF ../debug/$$f.d -o ../debug/$$f.o; \
	done

	

MODEM_LIST:
	echo "Building MODEM: $(notdir $(modem_src))"
	for f in $(modem_src) ; do \
	  echo Compile $(modem_dir)/$$f.c; \
	  gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC)  -w -c $(modem_dir)/$$f.c -MMD -MF ../debug/$$f.d -o ../debug/$$f.o; \
	done

#NVRAM_LIST: 
#	echo "Building NVRAM: $(notdir $(nvram_src))"
#	for f in $(nvram_src) ; do \
#	  echo Compile $(nvram_dir)/$$f.c; \
#	  gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC)  -w -c $(nvram_dir)/$$f.c -MMD -MF ../debug/$$f.d -o ../debug/$$f.o; \
#	done


nvram_data_items.o: ../../../custom/common/hal/nvram/nvram_data_items.c
	echo "Compile ../../../custom/common/hal/nvram/nvram_data_items.c"
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC) -w -c $< -MMD -MF ../debug/$(basename $(@F)).d -o ../debug/$@

nvram_cust_pack.o: ../../../custom/common/hal/nvram/nvram_cust_pack.c
	echo "Compile ../../../custom/common/hal/nvram/nvram_cust_pack.c"
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC) -w -c $< -MMD -MF ../debug/$(basename $(@F)).d -o ../debug/$@

custom_nvram_sec.o: ../../../custom/common/hal/nvram/custom_nvram_sec.c
	echo "Compile ../../../custom/common/hal/nvram/custom_nvram_sec.c"
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC) -w -c $< -MMD -MF ../debug/$(basename $(@F)).d -o ../debug/$@


nvram_factory_config.o: ../../../nvram/src/nvram_factory_config.c
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC) -w -c $< -MMD -MF ../debug/$(basename $(@F)).d -o ../debug/$@
	echo "nvram_factory_config.o done"

ifneq ($(filter "__MMI_FMI__", $(strip $(CUSTOM_OPTION))),)
nvram_user_config.o: ../../../custom/app/$(strip $(CUSTOM_FOLDER))/nvram_user_config.c
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC) -w -c $< -MMD -MF ../debug/$(basename $(@F)).d -o ../debug/$@
	echo "nvram_user_config.o done"

nvram_common_config.o: ../../../custom/common/${MMI_FOLDER}/nvram_common_config.c
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC) -w -c $< -MMD -MF ../debug/$(basename $(@F)).d -o ../debug/$@
	echo "nvram_common_config.o done"

custom_nvram_cat.o: ../../../custom/common/hal/nvram/custom_nvram_cat.c
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC) -w -c $< -MMD -MF ../debug/$(basename $(@F)).d -o ../debug/$@
	echo "custom_nvram_cat.o done"

endif

fs_quota_entry_dump.o: fs_quota_entry_dump.c 
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC)  -w -c $< -MMD -MF ../debug/$(basename $(@F)).d -o ../debug/$@


fs_quota.o: ../../../custom/common/fs_quota.c
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC) -w -c $< -MMD -MF ../debug/$(basename $(@F)).d -o ../debug/$@

nvram_auto_gen.o: nvram_auto_gen.c
	echo "Compile nvram_auto_gen.c"
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC)  -w -c $< -MMD -MF ../debug/$(basename $(@F)).d -o ../debug/$@
	echo "nvram_auto_gen.o done"

nvram_gen_util.o: nvram_gen_util.c
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC)  -w -c $< -MMD -MF ../debug/$(basename $(@F)).d -o ../debug/$@
	echo "nvram_gen_util.o done"

ifneq ($(filter "NVRAM_NOT_PRESENT", $(strip $(CUSTOM_OPTION))),)
    nvram_auto_gen: nvram_auto_gen.o $(QUOTA_SRC)
	gcc -o ../debug/nvram_auto_gen ../debug/nvram_auto_gen.o
	echo "build nvram_auto_gen done"
else
ifeq ($(strip $(LEVEL)), LEVEL2_OBJ)
  ifneq ($(strip $(CUSTOM_RELEASE)), FALSE)
        nvram_auto_gen: $(NVM_GEN_SRC) $(NVM_CUST_SRC) $(QUOTA_SRC)
  else
        nvram_auto_gen: $(NVM_GEN_SRC) $(NVM_CUST_SRC) $(NVM_CORE_SRC) $(QUOTA_SRC)
  endif
	gcc -o ../debug/nvram_auto_gen ../debug/$(NVM_GEN_OBJS)
	echo "build level2_obj nvram_auto_gen done"
else
  ifeq ($(strip $(LEVEL)), VENDOR) # vendor release
    nvram_auto_gen: $(NVM_GEN_SRC) $(NVM_VENDOR_SRC) $(QUOTA_SRC)
		gcc $(NVM_LNK_CMD) -o ../debug/nvram_auto_gen $(NVM_GEN_OBJS)
		echo "build vendor nvram_auto_gen done"
  else 
    nvram_auto_gen: $(NVM_GEN_SRC) $(NVM_CUST_SRC) $(NVM_CORE_SRC) $(QUOTA_SRC)
#    nvram_auto_gen: nvram_auto_gen.o nvram_gen_util.o
		gcc $(NVM_LNK_CMD) -o ../debug/nvram_auto_gen $(NVM_GEN_OBJS)
#		ld  nvram_auto_gen.txt -o ../debug/nvram_auto_gen $(NVM_GEN_OBJS) -Map ../debug/nvram_auto_gen.map 
#		gcc -o ../debug/nvram_auto_gen $(NVM_GEN_OBJS)
		echo "build nvram_auto_gen done"
  endif
endif
endif
############### fs quota compiling ####################

