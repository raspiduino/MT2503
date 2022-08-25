# Define source file lists to SRC_LIST
ifeq ($(strip $(MMIDIR)),plutommi)
  SRC_LIST = vendor\InputMethod\T9\adaptation\src\t9engine.c
endif

ifeq ($(strip $(MMIDIR)),lcmmi)
  SRC_LIST = vendor\InputMethod\T9\adaptation\src\t9lcengine.c
endif

# Define include path lists to INC_DIR
ifeq ($(strip $(MMIDIR)),plutommi)
INC_DIR = applib\mem\include \
          vendor\InputMethod\t9\adaptation\include \
          plutommi\Framework\IndicLanguages\IndicLanguagesInc \
          plutommi\mmi\asyncevents\AsyncEventsInc \
          plutommi\mmi\Audio\AudioInc \
          plutommi\mmi\GSMCallApplication\CommonFiles\CommonInc \
          plutommi\mmi\GSMCallApplication\outgoingcallmanagement\outgoinginc \
          plutommi\mmi\GSMCallApplication\incomingcallmanagement\incominginc \
          plutommi\mmi\DateTime\DateTimeInc \
          plutommi\Framework\DebugLevels\debuglevelInc \
          plutommi\Framework\CommonFiles\commoninc \
          plutommi\Framework\MemManager\MemManagerInc \
          plutommi\Framework\Tasks\tasksinc \
          plutommi\Framework\History\historyInc \
          plutommi\Framework\EventHandling\EventsInc \
          plutommi\mmi\FunAndGames\FunAndGamesInc \
          plutommi\Framework\GUI\gui_inc \
          plutommi\Framework\GUI\oem_inc \
          plutommi\MMI\IdleScreen\IdleScreenInc \
          plutommi\MMI\IdleScreen\IdleScreenInc\DemoAppInc \
          plutommi\mmi\inc \
          plutommi\CUI\inc \
          plutommi\Framework\Interface \
          plutommi\mmi\inc\MenuID \
          plutommi\mmi\MainMenu\MainMenuInc \
          plutommi\mmi\Messages\MessagesInc \
          plutommi\mmi\miscframework\miscframeworkinc \
          plutommi\mmi\phonebook\PhonebookInc \
          plutommi\mmi\sat\satInc \
          plutommi\mmi\Setting\SettingInc \
          plutommi\MtkApp\MtkAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
          plutommi\MtkApp\SoundRecorder\SoundRecorderInc \
          plutommi \
          plutommi\customer\customerinc \
          plutommi\MtkApp\Camera\CameraInc \
          plutommi\MtkApp\AudioPlayer\AudioPlayerInc \
          plutommi\MtkApp\FileMgr\FileMgrInc \
          plutommi\Framework\GDI\GDIInc \
          plutommi\Framework\CommonScreens\CommonScreensInc \
          plutommi\Framework\InputMethod\Inc \
          plutommi\Framework\InputMethod\Engine\Engine_Inc \
          plutommi\Framework\InputMethod\ui\ui_Inc
endif

ifeq ($(strip $(MMIDIR)),lcmmi)
INC_DIR = vendor\InputMethod\t9\adaptation\include \
          lcmmi\mmi\IndicLanguages\IndicLanguagesInc \
          lcmmi\mmi\asyncevents\AsyncEventsInc \
          lcmmi\mmi\Audio\AudioInc \
          lcmmi\mmi\callmanagement\CommonFiles\CommonInc \
          lcmmi\mmi\callmanagement\outgoingcallmanagement\outgoinginc \
          lcmmi\mmi\callmanagement\incomingcallmanagement\incominginc \
          lcmmi\mmi\Calls\CallsInc \
          lcmmi\mmi\DateTime\DateTimeInc \
          lcmmi\mmi\debuglevels\debuglevelInc \
          lcmmi\mmi\framework\tasks\tasksinc \
          lcmmi\mmi\framework\osl\oslInc \
          lcmmi\mmi\framework\history\historyInc \
          lcmmi\mmi\framework\EventHandling\EventsInc \
          lcmmi\mmi\FunAndGames\FunAndGamesInc \
          lcmmi\mmi\gui\gui_inc \
          lcmmi\MMI\IdleScreen\IdleScreenInc \
          lcmmi\mmi\inc \
          lcmmi\mmi\inc\MenuID \
          lcmmi\mmi\MainMenu\MainMenuInc \
          lcmmi\mmi\Messages\MessagesInc \
          lcmmi\mmi\miscframework\miscframeworkinc \
          lcmmi\mmi\phonebook\PhonebookInc \
          lcmmi\mmi\sat\satInc \
          lcmmi\mmi\Setting\SettingInc \
          lcmmi\MtkApp\MtkAppInc \
          lcmmi\MtkApp\EngineerMode\EngineerModeInc \
          lcmmi\MtkApp\SoundRecorder\SoundRecorderInc \
          lcmmi \
          lcmmi\customer\customerinc \
          lcmmi\MtkApp\AudioPlayer\AudioPlayerInc \
          lcmmi\MtkApp\FileMgr\FileMgrInc \
          lcmmi\MtkApp\GDI\GDIInc \
          lcmmi\MMI\CommonScreens\CommonScreensInc \
          lcmmi\mmi\InputMethod\Inc \
          lcmmi\mmi\InputMethod\Engine\Engine_Inc \
          lcmmi\mmi\InputMethod\ui\ui_Inc \
          lcmmi\mmi\BIDI\BIDIInc
endif

# Define the specified compile options to COMP_DEFS
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
            T9LANG_English \
            T9LANG_Chinese \
            T9LANG_Spanish \
            T9LANG_French \
            T9LANG_German \
            T9LANG_Italian \
            T9LANG_Portuguese \
            T9LANG_Thai \
            T9LANG_Bulgarian \
            T9LANG_Indonesian \
            T9LANG_Vietnamese \
            T9LANG_Czech \
            T9LANG_Polish \
            T9LANG_Turkish \
            T9LANG_Finnish \
            T9LANG_Hungarian \
            T9LANG_Norwegian \
            T9LANG_Dutch \
            T9LANG_Swedish \
            T9LANG_Arabic \
            T9LANG_Russian \
            T9LANG_Slovenian \
            T9LANG_Swedish \
            T9LANG_Hebrew \
            T9LANG_Greek \
            T9LANG_Hindi \
            T9LANG_Danish \
            T9LANG_Malay \
            T9LANG_Croatian \
            T9LANG_Slovak \
            T9LANG_Romanian \
            EMS_LITTLE_ENDIAN \
            EMS_MEM_MANAGEMENT \
            T9ALPHABETIC \
            T9CHINESE

 
