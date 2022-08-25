# Define source file lists to SRC_LIST
ifeq ($(strip $(MMIDIR)),plutommi)
  SRC_LIST = vendor\InputMethod\zi\adaptation\src\ziengine.c
endif

ifeq ($(strip $(MMIDIR)),lcmmi)
  SRC_LIST = vendor\InputMethod\zi\adaptation\src\zilcengine.c
endif

# Define include path lists to INC_DIR
ifeq ($(strip $(MMIDIR)),plutommi)
INC_DIR = applib\mem\include \
          vendor\InputMethod\zi\adaptation\include \
          plutommi\Framework\IndicLanguages\IndicLanguagesInc \
          plutommi\mmi\asyncevents\AsyncEventsInc \
          plutommi\mmi\Audio\AudioInc \
          plutommi\mmi\PROFILES\ProfilesInc \
          plutommi\mmi\GSMCallApplication\CommonFiles\CommonInc \
          plutommi\mmi\GSMCallApplication\outgoingcallmanagement\outgoinginc \
          plutommi\mmi\GSMCallApplication\incomingcallmanagement\incominginc \
          plutommi\mmi\DateTime\DateTimeInc \
          plutommi\Framework\DebugLevels\debuglevelInc \
          plutommi\mmi\EMS\EmsInc \
          plutommi\Framework\CommonFiles\commoninc \
          plutommi\Framework\MemManager\MemManagerInc \
          plutommi\Framework\Tasks\tasksinc \
          plutommi\Framework\osl\oslInc \
          plutommi\Framework\History\historyInc \
          plutommi\Framework\EventHandling\EventsInc \
          plutommi\mmi\FunAndGames\FunAndGamesInc \
          plutommi\Framework\GUI\gui_inc \
          plutommi\Framework\GUI\oem_inc \
          plutommi\MMI\IdleScreen\IdleScreenInc \
          plutommi\MMI\IdleScreen\IdleScreenInc\DemoAppInc \
          plutommi\mmi\inc \
          plutommi\Framework\Interface \
          plutommi\mmi\inc\MenuID \
          plutommi\mmi\MainMenu\MainMenuInc \
          plutommi\mmi\Messages\MessagesInc \
          plutommi\mmi\miscframework\miscframeworkinc \
          plutommi\mmi\phonebook\PhonebookInc \
          plutommi\mmi\sat\satInc \
          plutommi\mmi\Setting\SettingInc \
          plutommi\Framework\CommonScreens\CommonScreensInc \
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
          applib\misc\include \
          plutommi\Framework\InputMethod\Inc \
          plutommi\Framework\InputMethod\Engine\Engine_Inc \
          plutommi\Framework\InputMethod\ui\ui_Inc
endif

ifeq ($(strip $(MMIDIR)),lcmmi)
INC_DIR = vendor\InputMethod\zi\adaptation\include \
          lcmmi\mmi\IndicLanguages\IndicLanguagesInc \
          lcmmi\mmi\asyncevents\AsyncEventsInc \
          lcmmi\mmi\Audio\AudioInc \
          lcmmi\mmi\PROFILES\ProfilesInc \
          lcmmi\mmi\callmanagement\CommonFiles\CommonInc \
          lcmmi\mmi\callmanagement\outgoingcallmanagement\outgoinginc \
          lcmmi\mmi\callmanagement\incomingcallmanagement\incominginc \
          lcmmi\mmi\Calls\CallsInc \
          lcmmi\mmi\Connect\ConnectInc \
          lcmmi\mmi\custresource \
          lcmmi\mmi\DateTime\DateTimeInc \
          lcmmi\mmi\debuglevels\debuglevelInc \
          lcmmi\mmi\EMS\EmsInc \
          lcmmi\mmi\FontData \
          lcmmi\mmi\framework\tasks\tasksinc \
          lcmmi\mmi\framework\osl\oslInc \
          lcmmi\mmi\framework\history\historyInc \
          lcmmi\mmi\framework\EventHandling\EventsInc \
          lcmmi\mmi\FunAndGames\FunAndGamesInc \
          lcmmi\mmi\gui\gui_inc \
          lcmmi\MMI\IdleScreen\IdleScreenInc \
          lcmmi\MMI\IdleScreen\IdleScreenInc\DemoAppInc \
          lcmmi\mmi\inc \
          lcmmi\mmi\inc\ImgID \
          lcmmi\mmi\inc\MenuID \
          lcmmi\mmi\inc\StringID \
          lcmmi\mmi\MainMenu\MainMenuInc \
          lcmmi\mmi\Messages\MessagesInc \
          lcmmi\mmi\miscframework\miscframeworkinc \
          lcmmi\mmi\phonebook\PhonebookInc \
          lcmmi\mmi\sat\satInc \
          lcmmi\mmi\Setting\SettingInc \
          lcmmi\mmi\CommonScreens\CommonScreensInc \
          lcmmi\MtkApp\MtkAppInc \
          lcmmi\MtkApp\EngineerMode\EngineerModeInc \
          lcmmi\MtkApp\SoundRecorder\SoundRecorderInc \
          lcmmi \
          lcmmi\customer\customerinc \
          lcmmi\MtkApp\Camera\CameraInc \
          lcmmi\MtkApp\AudioPlayer\AudioPlayerInc \
          lcmmi\MtkApp\FileMgr\FileMgrInc \
          lcmmi\MtkApp\GDI\GDIInc \
          applib\misc\include \
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
            SHORTCUTS_APP
 
 
