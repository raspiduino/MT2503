MTK_DEFS = \
	-D "__MULTI_BIN_LOAD__" \
	-D "__EXE_DLL__" \
	-D "__RESGEN_INTERNAL_POP_FILE_REDUCE__" \
	-D "__RESGEN_INTERNAL_OFFLINE__" \
	-D "__RESGEN_INTERNAL_3D_META_RESGEN_AUTO__" \
	-D "__REGEN_INTERNAL_BATCHED__"

SHARE_DEFS_BASE = \
	-D "WIN32"\
	-D "_DEBUG"\
	-D "_WINDOWS"\
	-D "_MBCS"\
	-D "_CONSOLE"\
	-D "__UCS2_ENCODING"\
	-D "MMI_ON_WIN32"\
	-D "__RESOURCE_GEN_"\
	-D "_L4_COMMON_STRUCT_H"\
	-D "DEVELOPER_BUILD_FIRST_PASS"\
	-D "_AFXDLL"\
	-D "__MOD_SMSAL__"\
	-D "__SAT__"\
	-D "SHORTCUTS_APP"\
	-D "__POPULATE_ENGINE_"\
	-D "DEBUG_WINDOW"\
	-D "VM_SUPPORT" \
	-D "_WINERROR_H" \
	-D "_LIB"\
	-D "NO_GZIP"\
	-D "NO_ERRNO_H"\
	-D "NOBYFOUR"\
	-D "__XML_SUPPORT__"

ifndef $(COMPILER_VER)
COMPILER_VER = gcc33
endif

ifeq ($(strip $(COMPILER_VER)), gcc45)
    INC =
    SHARE_DEFS = $(SHARE_DEFS_BASE)
    TIME = %time%
    VIA = @inc.via @option.via
    RESGEN_PCH = resgen_pch.h.gch
    RESGEN_PCH_SRC = resgen_pch.h
else
    include resgen_inc.txt
    include custom_option.txt
    INC = $(RESGEN_INC)
    SHARE_DEFS = $(SHARE_DEFS_BASE) ${CUSTOM_OPTION}
    TIME =
    VIA =
    RESGEN_PCH =
endif

ifeq ($(USES_DEBUG), YES)
    MTK_DEFS:= -D "RESGEN_DEBUG_MODE"
endif

DEFINE = $(MTK_DEFS) $(SHARE_DEFS)

MMI_FEATURES_H = ../../MMI/Inc/MMI_features.h
ENUM_LIST_H = ./enum_list.h

OUTDIR =./debug/obj
OUTDIR_XML =./debug/res

OUTDIR_RESGEN_XML =./debug/obj/resgen_xml
OUTDIR_MTK_RESGEN =./debug/obj/mtk_resgenerator
OUTDIR_MTK_RESGEN_XML =./debug/obj/mtk_resgenerator_xml
OUTDIR_MTK_RESGEN_CORE =./debug/obj/mtk_resgenerator_core
OUTDIR_REF_LIST_MERGE =./debug/obj/ref_list_merge
OUTDIR_PLMNCREATE =./debug/obj/plmncreate
OUTDIR_FONT_GEN =./debug/obj/font_gen

OUTDIR_RESGEN_DEP = ./debug/dep/resgen
OUTDIR_XML_PARSER_DEP = ./debug/dep/xml_parser
OUTDIR_COMMON_DEP = ./debug/dep/common

# Offline Resgen OBJs
OUTDIR_OFFLINE_RESGEN_TOOL = ./OfflineResGenerator/lib/tool
# Offline Resgen common OBJs compiling doesn not included in Resgen Process
OUTDIR_OFFLINE_RESGEN_COMMON = ./OfflineResGenerator/lib/common
# Resgen Log OBJs
OUTDIR_RESGEN_LOG_COMMON = ./ResgenLog/lib/common
# Resgen Core OBJs
OUTDIR_RESGEN_CORE_COMMON = ./ResgenCore/lib/common

MTK_RESGEN_OBJECTS = $(MTK_OBJS) $(PLUTOMMI_OBJS) $(MTK_REGGEN_OBJS) $(ZLIB_OBJS) $(MTK_RESGEN_XML_OBJS)

PLUTOMMI_OBJS = \
	$(OUTDIR_MTK_RESGEN_CORE)/CustResDeclare.o\
	$(OUTDIR_MTK_RESGEN_CORE)/PopulateRes.o\
	$(OUTDIR_MTK_RESGEN_CORE)/WriteRes.o\
	$(OUTDIR_MTK_RESGEN_CORE)/WriteImgRes.o\
	$(OUTDIR_MTK_RESGEN_CORE)/WriteResUtil.o\
    $(OUTDIR_MTK_RESGEN_CORE)/WriteProcess.o\
	$(OUTDIR_MTK_RESGEN_CORE)/ResBytestream.o\
	$(OUTDIR_MTK_RESGEN_CORE)/BMPLoader.o\
	$(OUTDIR_MTK_RESGEN_CORE)/ABMLoader.o\
	$(OUTDIR_MTK_RESGEN_CORE)/bmp2ems.o\
	$(OUTDIR_MTK_RESGEN_CORE)/GIFLoader.o\
	$(OUTDIR_MTK_RESGEN_CORE)/ImageGetDimension.o\
	$(OUTDIR_MTK_RESGEN_CORE)/ThreadPool.o\
    $(OUTDIR_MTK_RESGEN_CORE)/CmidiGen.o

MTK_OBJS = \
    $(OUTDIR_MTK_RESGEN_CORE)/mtk_resgenerator.o\
    $(OUTDIR_MTK_RESGEN_CORE)/str_merge.o \
    $(OUTDIR_MTK_RESGEN_CORE)/FontRes.o \
    $(OUTDIR_MTK_RESGEN_CORE)/FontData.o

FONT_OBJECTS = \
    $(OUTDIR_FONT_GEN)/res_gen_font.o\
    $(OUTDIR_FONT_GEN)/bdf_operation.o\
    $(OUTDIR_FONT_GEN)/FontClass.o\
    $(OUTDIR_FONT_GEN)/Fontgen.o\
    $(OUTDIR_FONT_GEN)/FontResFile.o\
    $(OUTDIR_FONT_GEN)/FontHWCompress.o

LIB = ../FontResgen/libbfenc.a ../FontResgen/libforfont.a ../FontResgen/LzmaLib.a

MTK_RESGEN_SOURCES = $(patsubst ../Res_MMI/%, %,$(wildcard ../Res_MMI/*.c))
MTK_RESGEN_XML_SOURCES = $(patsubst ../Res_MMI_XML/%, %,$(wildcard ../Res_MMI_XML/*.c))
ZLIB_SOURCES = $(patsubst ./zlib/%, %,$(wildcard ./zlib/*.c))

MTK_REGGEN_OBJS = $(patsubst %.c,$(OUTDIR_MTK_RESGEN)/%.o,$(MTK_RESGEN_SOURCES))
MTK_RESGEN_XML_OBJS = $(patsubst %.c,$(OUTDIR_MTK_RESGEN_XML)/%.o,$(MTK_RESGEN_XML_SOURCES))

ZLIB_OBJS = $(patsubst %.c,$(OUTDIR_MTK_RESGEN)/%.o,$(ZLIB_SOURCES))

RES_XML_SOURCES = $(patsubst ./temp/res/%, %,$(wildcard ./temp/res/*.c))
RES_XML_I = $(patsubst %.c,$(OUTDIR_XML)/%.i,$(RES_XML_SOURCES))

REF_LIST_MERGE_OBJS = $(OUTDIR_REF_LIST_MERGE)/ref_list_merge.o

PLMNCREATE_OBJS = $(OUTDIR_PLMNCREATE)/plmncreate.o

RES_XML_RES = $(patsubst ./ResgenXML/ResgenSrc/%, %,$(wildcard ./ResgenXML/ResgenSrc/*.c))
RES_XML_OBJS = $(patsubst %.c,$(OUTDIR_RESGEN_XML)/%.o,$(RES_XML_RES))

RES_XML_CUST_RES = $(patsubst ./ResgenXML/CustResSrc/%, %,$(wildcard ./ResgenXML/CustResSrc/*.c))
RES_XML_CUST_OBJS = $(patsubst %.c,$(OUTDIR_RESGEN_XML)/%.o,$(RES_XML_CUST_RES))

################################### Offline ResGen Path (START) ###################################

# Retrive file list of Offline Resgen common source
RES_OFFLINE_RESGEN_COMMON_SOURCE = $(patsubst ./OfflineResGenerator/src/common/%, %,$(wildcard ./OfflineResGenerator/src/common/*.cpp))

# Retrive file list of Offline Resgen tool source
RES_OFFLINE_RESGEN_TOOL_SOURCE = $(patsubst ./OfflineResGenerator/src/tool/%, %,$(wildcard ./OfflineResGenerator/src/tool/*.cpp))

# Retrive file list of Offline Resgen common objs
RES_OFFLINE_RESGEN_COMMON_OBJ = $(patsubst %.cpp,$(OUTDIR_OFFLINE_RESGEN_COMMON)/%.o,$(RES_OFFLINE_RESGEN_COMMON_SOURCE))

# Retrive file list of Offline Resgen tool objs
RES_OFFLINE_RESGEN_TOOL_OBJ = $(patsubst %.cpp,$(OUTDIR_OFFLINE_RESGEN_TOOL)/%.o,$(RES_OFFLINE_RESGEN_TOOL_SOURCE))

################################### Offline ResGen Path (END)   ###################################

################################### Resgen Log Path (START)     ###################################

# Retrive file list of Resgen log source
RES_RESGEN_LOG_SOURCE = $(patsubst ./ResgenLog/src/common/%, %,$(wildcard ./ResgenLog/src/common/*.cpp))

# Retrive file list of Resgen log objs
RES_RESGEN_LOG_OBJ = $(patsubst %.cpp,$(OUTDIR_RESGEN_LOG_COMMON)/%.o,$(RES_RESGEN_LOG_SOURCE))

################################### Resgen Log Path (END)       ###################################

################################### Resgen CORE Path (START)     ###################################

# Retrive file list of Resgen log source
RES_RESGEN_CORE_SOURCE = $(patsubst ./ResgenCore/src/common/%, %,$(wildcard ./ResgenCore/src/common/*.cpp))

# Retrive file list of Resgen log objs
RES_RESGEN_CORE_OBJ = $(patsubst %.cpp,$(OUTDIR_RESGEN_CORE_COMMON)/%.o,$(RES_RESGEN_CORE_SOURCE))

################################### Resgen CORE Path (END)       ###################################

RES_XML_OBJS_ALL = $(RES_XML_OBJS) $(RES_XML_CUST_OBJS)



CC = gcc

CFLAG = -g

.SUFFIXES: .o .cpp .c

$(OUTDIR_REF_LIST_MERGE)/ref_list_merge.o: ref_list_merge.c
	@echo Compiling $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -w -c $< -MMD -MF $(OUTDIR_RESGEN_DEP)/$(basename $(@F)).d -o $@

$(OUTDIR_PLMNCREATE)/plmncreate.o: plmncreate.c
	@echo Compiling $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -w -c $< -MMD -MF $(OUTDIR_RESGEN_DEP)/$(basename $(@F)).d -o $@

xml_files: $(RES_XML_I)
$(RES_XML_I):$(OUTDIR_XML)/%.i: temp/res/%.c
	@echo Preprocessing $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $< -E -MMD -MF $(OUTDIR_XML_PARSER_DEP)/$(basename $(@F)).d > $@

$(OUTDIR_FONT_GEN)/%.o: %.cpp
	@echo Compiling $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -c -w $< -MMD -MF $(OUTDIR_RESGEN_DEP)/$(basename $(@F)).d -o $@

$(OUTDIR_MTK_RESGEN)/%.o: %.c
	@echo $(TIME) Compiling $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -c -w $< -MMD -MF $(OUTDIR_RESGEN_DEP)/$(basename $(@F)).d -o $@

$(OUTDIR_MTK_RESGEN_CORE)/%.o: %.c
	@echo $(TIME) Compiling $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -c -g -Wa,-a,-ad $< -MMD -MF $(OUTDIR_RESGEN_DEP)/$(basename $(@F)).d -o $@ > $@.cod
#	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -c -w $< -MMD -MF $(OUTDIR_RESGEN_DEP)/$(basename $(@F)).d -o $@

$(OUTDIR_MTK_RESGEN_CORE)/%.o: %.cpp
	@echo $(TIME) Compiling $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -c -g -Wa,-a,-ad $< -MMD -MF $(OUTDIR_RESGEN_DEP)/$(basename $(@F)).d -o $@ > $@.cod
#	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -c -w $< -MMD -MF $(OUTDIR_RESGEN_DEP)/$(basename $(@F)).d -o $@

$(OUTDIR_MTK_RESGEN_XML)/%.o: %.c $(RESGEN_PCH)
	@echo $(TIME) Compiling $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -c -w $< -MMD -MF $(OUTDIR_RESGEN_DEP)/$(basename $(@F)).d -o $@

ifeq ($(strip $(COMPILER_VER)), gcc45)
$(RESGEN_PCH): $(RESGEN_PCH_SRC)
	@echo $(TIME) Compiling $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -c -w $< -MMD -MF $(OUTDIR_RESGEN_DEP)/$(basename $(@F)).d -o $@
	@echo $(TIME) Finish Compiling $< &
endif

$(OUTDIR_RESGEN_XML)/%.o: %.c
	@echo $(TIME) Compiling $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -c -w $< -MMD -MF $(OUTDIR_XML_PARSER_DEP)/$(basename $(@F)).d -o $@

$(OUTDIR_OFFLINE_RESGEN_TOOL)/%.o: %.c
	@echo $(TIME) Compiling $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -c -w $< -MMD -MF $(OUTDIR_COMMON_DEP)/$(basename $(@F)).d -o $@

$(OUTDIR_OFFLINE_RESGEN_TOOL)/%.o: %.cpp
	@echo $(TIME) Compiling $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -c -w $< -MMD -MF $(OUTDIR_COMMON_DEP)/$(basename $(@F)).d -o $@
	
$(OUTDIR_OFFLINE_RESGEN_COMMON)/%.o: %.c
	@echo $(TIME) Compiling $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -c -w $< -MMD -MF $(OUTDIR_COMMON_DEP)/$(basename $(@F)).d -o $@

$(OUTDIR_OFFLINE_RESGEN_COMMON)/%.o: %.cpp
	@echo $(TIME) Compiling $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -c -w $< -MMD -MF $(OUTDIR_COMMON_DEP)/$(basename $(@F)).d -o $@

$(OUTDIR_RESGEN_LOG_COMMON)/%.o: %.c
	@echo $(TIME) Compiling $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -c -w $< -MMD -MF $(OUTDIR_COMMON_DEP)/$(basename $(@F)).d -o $@

$(OUTDIR_RESGEN_LOG_COMMON)/%.o: %.cpp
	@echo $(TIME) Compiling $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -c -w $< -MMD -MF $(OUTDIR_COMMON_DEP)/$(basename $(@F)).d -o $@

$(OUTDIR_RESGEN_CORE_COMMON)/%.o: %.c
	@echo $(TIME) Compiling $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -c -w $< -MMD -MF $(OUTDIR_COMMON_DEP)/$(basename $(@F)).d -o $@

$(OUTDIR_RESGEN_CORE_COMMON)/%.o: %.cpp
	@echo $(TIME) Compiling $< &
	@$(CC) $(DEFINE) $(INC) $(VIA) $(CFLAG) -c -w $< -MMD -MF $(OUTDIR_COMMON_DEP)/$(basename $(@F)).d -o $@

VPATH=./ResgenCore/src/common:./ResgenLog/src/common:./OfflineResGenerator/src/common:./OfflineResGenerator/src/tool:../Res_MMI:../Res_MMI_XML:.:../CustResource:../../MMI/Resource:../../MMI/MiscFramework/MiscFrameworkSrc:./ResgenXML/ResgenSrc:./ResgenXML/CustResSrc:./zlib:../FontResgen

# Standalone offline tool has not been support in Resgen 1.5
# offline_resgen target only build the unit test progarm now
offline_resgen: $(RES_RESGEN_CORE_OBJ) $(RES_OFFLINE_RESGEN_COMMON_OBJ) $(RES_RESGEN_LOG_OBJ) $(RES_OFFLINE_RESGEN_TOOL_OBJ)
	@echo "Building MTK offline resgen framework" $(RES_OFFLINE_RESGEN_COMMON_OBJ) $(RES_OFFLINE_RESGEN_TOOL_OBJ)
	@$(CC) -g -o offline_resgen $(RES_RESGEN_CORE_OBJ) $(RES_OFFLINE_RESGEN_COMMON_OBJ) $(RES_RESGEN_LOG_OBJ) $(RES_OFFLINE_RESGEN_TOOL_OBJ) -lstdc++

resgen_xml.exe: $(RES_XML_OBJS_ALL) $(RES_RESGEN_CORE_OBJ) $(RES_RESGEN_LOG_OBJ) $(RES_OFFLINE_RESGEN_COMMON_OBJ)
	@echo Linking *.o for resgen_xml.exe...
	@$(CC) -g -o resgen_xml  $(RES_XML_OBJS_ALL) $(RES_RESGEN_CORE_OBJ) $(RES_RESGEN_LOG_OBJ) $(RES_OFFLINE_RESGEN_COMMON_OBJ) -lstdc++

mtk_resgenerator.exe: $(RESGEN_PCH) $(MTK_RESGEN_OBJECTS) $(RES_RESGEN_CORE_OBJ) $(RES_OFFLINE_RESGEN_COMMON_OBJ) $(RES_RESGEN_LOG_OBJ)
	@echo $(TIME) Linking *.o for mtk_resgenerator.exe...
	@$(CC) -g -o mtk_resgenerator  $(MTK_RESGEN_OBJECTS) $(RES_RESGEN_CORE_OBJ) $(RES_OFFLINE_RESGEN_COMMON_OBJ) $(RES_RESGEN_LOG_OBJ) -lstdc++ -Wl,-Map,mtk_resgenerator.map
	@echo $(TIME) Finish Linking *.o for mtk_resgenerator.exe...

ref_list_merge.exe: $(REF_LIST_MERGE_OBJS)
	@echo Linking $< &
	@$(CC) -g -o ref_list_merge  $(REF_LIST_MERGE_OBJS)

plmncreate.exe: $(PLMNCREATE_OBJS)
	@echo Linking $< &
	@$(CC) -g -o plmncreate  $(PLMNCREATE_OBJS)

font_gen.exe: $(FONT_OBJECTS)
	@echo Linking $< &
	@echo $@: $(LIB) >$(OUTDIR_RESGEN_DEP)/$(basename $(@F)).d
	@g++ -g -o font_gen.exe $(FONT_OBJECTS) $(LIB)

clean:
	if exist .\debug\obj\mtk_resgenerator rd /S/Q .\debug\obj\mtk_resgenerator >nul
	if exist .\debug\obj\mtk_resgenerator_xml rd /S/Q .\debug\obj\mtk_resgenerator_xml >nul
	if exist $(RESGEN_PCH) del $(RESGEN_PCH)
	md .\debug\obj\mtk_resgenerator
	md .\debug\obj\mtk_resgenerator_xml

