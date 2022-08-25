include custom_option.txt
include custom_include.txt
PLUTO_INC =  \
	 -I "."  \
	 -I "./Inc" \
	 -I "../.."  \
	 -I "../../customer/customerinc"  \
	 -I "../../MMI/PoC/PoCInc"  \
	 -I "../../Framework/DebugLevels/DebugLevelInc"  \
	 -I "../../MMI/Calls/CallsInc"  \
	 -I "../../MMI/ChatApp/ChatAppInc"  \
	 -I "../../MMI/EmailApp/EmailAppInc"  \
	 -I "../../MMI/IMPS/IMPSInc"  \
	 -I "../../MMI/Inc"  \
	 -I "../../MMI/Inc/ImgID"  \
	 -I "../../MMI/Inc/MenuID"  \
	 -I "../../MMI/Inc/StringID"  \
	 -I "../../Framework/osl/oslinc"  \
	 -I "../../MMI/CallManagement/CommonFiles/CommonInc"  \
	 -I "../../MMI/CallManagement/OutgoingCallManagement/OutgoingInc"  \
	 -I "../../MMI/CallManagement/IncomingCallManagement/IncomingInc"  \
	 -I "../../MMI/Setting/SettingInc"  \
	 -I "../../MMI/PhoneBook/PhoneBookInc"  \
	 -I "../../Framework/CommonScreens/CommonScreensInc"  \
	 -I "../../Framework/CommonFiles/CommonInc"	\
	 -I "../../Framework/Tasks/TasksInc"  \
	 -I "../../Framework/EventHandling/EventsInc"  \
	 -I "../../Framework/History/HistoryInc"  \
	 -I "../../Framework/MemManager/MemManagerInc"	\
	 -I "../../MMI/DataAccount/DataAccountInc"  \
	 -I "../../MMI/FunAndGames/FunAndGamesInc"  \
	 -I "../../Framework/GUI/gui_inc"  \
	 -I "../../MMI/DateTime/DateTimeInc"  \
	 -I "../../MMI/MiscFramework/MiscFrameworkInc"  \
	 -I "../../MMI/Help/HelpInc"  \
	 -I "../../MMI/IdleScreen/IdleScreenInc"  \
	 -I "../../MMI/Messages/MessagesInc"  \
	 -I "../../MMI/NITZHandler/NITZInc"  \
	 -I "../../MMI/PROFILES/ProfilesInc"  \
	 -I "../../MMI/SAT/SATInc"  \
	 -I "../../MMI/SSC/SSCInc"  \
	 -I "../../MMI/Organizer/OrganizerInc"  \
	 -I "../../MMI/Extra/ExtraInc"  \
	 -I "../../MMI/Customer/CustResource"  \
	 -I "../../MMI/FontData"  \
	 -I "../../Framework/DebugLevels/DebugLevelInc"  \
	 -I "../../MMI/MainMenu/MainMenuInc"  \
	 -I "../../MMI/ems/emsinc"  \
	 -I "../../MMI/Dictionary/DictInc"  \
	 -I "../../MMI/CPHS/CPHSInc"  \
	 -I "../../MMI/audio/audioinc"  \
	 -I "../../MMI/Stopwatch/StopwatchInc"  \
	 -I "../../MMI/Resource\Inc" \
	 -I "../../MtkApp/MtkAppInc"  \
	 -I "../../MtkApp/EngineerMode/EngineerModeInc"  \
	 -I "../../MtkApp/Connectivity/ConnectivityInc"  \
	 -I "../../MtkApp/SoundRecorder/SoundRecorderInc"  \
	 -I "../../MtkApp/AudioPlayer/AudioPlayerInc"  \
	 -I "../../MtkApp/ABRepeater/ABRepeaterInc"  \
	 -I "../../MtkApp/mmiapi/include"  \
	 -I "../../MTkApp/Camera/CameraInc"	\
	 -I "../../MTkApp/Video/VideoInc"	\
	 -I "../../MTkApp/FileMgr/FileMgrInc" \
	 -I "../../Framework/GDI/GDIInc" \
	 -I "../../MTkApp/vObjects/vObjectInc" \
	 -I "../../MTkApp/FMRadio/FMRadioInc"  \
	 -I "../../MTkApp/FMScheduleRec/FMScheduleRecInc"  \
	 -I "../../MTkApp/VRSD/VRSDInc" \
	 -I "../../MTkApp/VRSI/VRSIInc" \
	 -I "../../MTkApp/PhotoEditor\PhotoEditorInc" \
	 -I "../../MTkApp/BGSound/BGSoundInc" \
	 -I "../../MtkApp\JavaAgency\JavaAgencyInc" \
	 -I "../../../kal/include"  \
	 -I "../../../ps/interfaces/enum"  \
	 -I "../../../ps/l4/include"  \
	 -I "../../../ps/gen/mcd"  \
	 -I "../../../ps/interfaces/local_inc"  \
	 -I "../../../interface/mmi"  \
	 -I "../../../j2me/jam/include" \
	 -I "../../../fmt\include" \
	 -I "../DevApp/DevAppInc" \
	 -I "../CustomerInc" \
	 -I "../Avk/AvkInc" \
	 -I "../../Framework/MemManager/memmanagerinc" \
	 -I "../../VendorApp/ResGenerator/Inc"

INC = $(PLUTO_INC) ${CUSTOM_INC}

MTK_DEFS = \
	-D "__MULTI_BIN_LOAD__" \
	-D "__EXE_DLL__"

SHARE_DEFS = \
	-D "WIN32"\
	-D "MMI_ON_WIN32"\
	-D "_DEBUG"\
	-D "_WINDOWS"\
	-D "_MBCS"\
	-D "_CONSOLE"\
	-D "DEVELOPER_BUILD_FIRST_PASS"\
	-D "__UCS2_ENCODING"\
	-D "__RESOURCE_GEN_"\
	-D "_AFXDLL"\
	-D "__POPULATE_ENGINE_"\
	-D "DEBUG_WINDOW"\
	-D "_WINERROR_H" \
	-D "DEVAPP_RESOURCE" \
	-D "__DEVAPP_RESOURCE_OUTPUT__" \
	${CUSTOM_OPTION}

DEFINE = $(MTK_DEFS) $(SHARE_DEFS)

MMI_FEATURES_H = ../../MMI/Inc/MMI_features.h
ENUM_LIST_H = ./enum_list.h

OUTDIR_XML =./debug/res

OBJECTS = $(PLUTOMMI_OBJS) $(RES_OBJS) $(MTK_OBJS)

PLUTOMMI_OBJS = \
	./obj/ResBytestream.o\

  
MTK_OBJS = \
  CustResDeclare.o\
  DevApp_WriteRes.o\
  PopulateDevAppRes.o\
  DevApp_resgenerator.o\
  DevApp_bmp2ems.c\
  DevApp_BMPLoader.c\
  DevApp_GIFLoader.c\
  DevApp_ImageGetDimension.o\

RES_XML_SOURCES = $(patsubst ./temp/res/%, %,$(wildcard ./temp/res/*.c))
RES_XML_I = $(patsubst %.c,$(OUTDIR_XML)/%.i,$(RES_XML_SOURCES))

RES_SOURCES = $(patsubst ../DevResource/Res_MMI/%, %,$(wildcard ../DevResource/Res_MMI/*.c))

RES_OBJS = $(patsubst %.c,%.o,$(RES_SOURCES))

READEXCEL_OBJS = DevApp_readexcel.o\
          ./obj/FontRes.o\

INC_PATH_LIST = $(patsubst "%",%,$(filter "%",$(PLUTO_INC)))

H_LIST = $(filter-out %enum_list.h,$(foreach list, $(INC_PATH_LIST), $(wildcard $(list)/*.h)))

	

.SUFFIXES: .o .cpp .c

xml_files: $(RES_XML_I) $(H_LIST)
$(RES_XML_I):$(OUTDIR_XML)/%.i: temp/res/%.c
	@echo Compiling $< & 
	@gcc $(DEFINE) $(INC) $< -E > $@

DevApp_readexcel.o: DevApp_readexcel.c $(H_LIST) $(ENUM_LIST_H)
	@echo Compiling $< & \
	gcc $(DEFINE) $(INC) -g -w -c $< -o $@

%.o: %.c $(H_LIST)
	@echo Compiling $< & \
	gcc $(DEFINE) $(INC) -g -w -c $< -o $@

.cpp.o:
	@echo Compiling $< & \
	g++ $(DEFINE) $(INC) -g -w -c $< -o $@
#gcc $(DEFINE) $(INC) -dD -E -c $< -o $@

VPATH=.:../DevResource/Res_MMI:./obj
DevApp_readexcel.exe: $(READEXCEL_OBJS)
	@echo Linking $< & \
	gcc -g -o DevApp_readexcel  $(READEXCEL_OBJS)

DevApp_resgenerator.exe: $(OBJECTS)
	@echo Linking $< & \
	gcc -g -o Devapp_resgenerator $(OBJECTS)

