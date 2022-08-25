# Define source file lists to SRC_LIST
ifeq ($(strip $(MMIDIR)),plutommi)
  SRC_LIST = vendor\InputMethod\cstar\adaptation\src\CstarEngine.c
endif

ifeq ($(strip $(MMIDIR)),lcmmi)
  SRC_LIST = vendor\InputMethod\cstar\adaptation\src\cstarlcengine.c
endif

#  Define include path lists to INC_DIR
ifeq ($(strip $(MMIDIR)),plutommi)
  INC_DIR = applib\mem\include \
            vendor\InputMethod\cstar\adaptation\include \
            plutommi\mmi\asyncevents\AsyncEventsInc \
            plutommi\mmi\Audio\AudioInc \
            plutommi\mmi\PROFILES\ProfilesInc \
            plutommi\mmi\GSMCallApplication\CommonFiles\CommonInc \
            plutommi\mmi\GSMCallApplication\outgoingcallmanagement\outgoinginc \
            plutommi\mmi\GSMCallApplication\incomingcallmanagement\incominginc \
            plutommi\mmi\DateTime\DateTimeInc \
            plutommi\Framework\DebugLevels\debuglevelInc \
            plutommi\Framework\Tasks\tasksinc \
            plutommi\Framework\MemManager\MemManagerInc \
            fmt\include \
            plutommi\Framework\CommonFiles\commoninc \
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
            plutommi\Framework\InputMethod\Inc \
            plutommi\Framework\InputMethod\Engine\Engine_Inc \
            plutommi\Framework\InputMethod\UI\UI_Inc \
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
            vendor\InputMethod\cstar\v2_official\inc
endif

ifeq ($(strip $(MMIDIR)),lcmmi)
  INC_DIR = vendor\InputMethod\cstar\adaptation\include \
            lcmmi\mmi\asyncevents\AsyncEventsInc \
            lcmmi\mmi\Audio\AudioInc \
            lcmmi\mmi\PROFILES\ProfilesInc \
            lcmmi\mmi\callmanagement\CommonFiles\CommonInc \
            lcmmi\mmi\callmanagement\outgoingcallmanagement\outgoinginc \
            lcmmi\mmi\callmanagement\incomingcallmanagement\incominginc \
            plutommi\mmi\GSMCallApplication\CommonFiles\CommonInc \
            plutommi\mmi\GSMCallApplication\outgoingcallmanagement\outgoinginc \
            plutommi\mmi\GSMCallApplication\incomingcallmanagement\incominginc \
            lcmmi\mmi\Calls\CallsInc \
            lcmmi\mmi\DateTime\DateTimeInc \
            lcmmi\mmi\debuglevels\debuglevelInc \
            lcmmi\mmi\framework\tasks\tasksinc \
            lcmmi\mmi\framework\osl\oslInc \
            fmt\include \
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
            lcmmi\mmi\CommonScreens\CommonScreensInc \
            lcmmi\MtkApp\MtkAppInc \
            lcmmi\MtkApp\EngineerMode\EngineerModeInc \
            lcmmi\MtkApp\SoundRecorder\SoundRecorderInc \
            lcmmi \
            lcmmi\customer\customerinc \
            lcmmi\MtkApp\AudioPlayer\AudioPlayerInc \
            lcmmi\MtkApp\FileMgr\FileMgrInc \
            lcmmi\MtkApp\GDI\GDIInc \
            lcmmi\mmi\InputMethod\Inc \
            lcmmi\mmi\InputMethod\Engine\Engine_Inc \
            lcmmi\mmi\BIDI\BIDIInc \
            lcmmi\mmi\InputMethod\ui\ui_Inc
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

