# Define source file lists to SRC_LIST
SRC_LIST = vendor\handwriting\guobi\adaptation\src\GuobiInterface.c

#  Define include path lists to INC_DIR
INC_DIR = applib\mem\include          \
          plutommi\mmi\asyncevents\AsyncEventsInc          \
          plutommi\mmi\Audio\AudioInc          \
          plutommi\mmi\GSMCallApplication\CommonFiles\CommonInc          \
          plutommi\mmi\GSMCallApplication\outgoingcallmanagement\outgoinginc          \
          plutommi\mmi\GSMCallApplication\incomingcallmanagement\incominginc          \
          plutommi\mmi\DateTime\DateTimeInc          \
          plutommi\Framework\DebugLevels\debuglevelInc          \
          plutommi\Framework\CommonFiles\commoninc          \
          plutommi\Framework\MemManager\MemManagerInc          \
          plutommi\Framework\Tasks\tasksinc          \
          plutommi\Framework\History\historyInc          \
          plutommi\Framework\EventHandling\EventsInc          \
          plutommi\mmi\FunAndGames\FunAndGamesInc          \
          plutommi\Framework\GUI\gui_inc          \
          plutommi\Framework\GUI\oem_inc          \
          plutommi\MMI\IdleScreen\IdleScreenInc          \
          plutommi\MMI\IdleScreen\IdleScreenInc\DemoAppInc \
          plutommi\mmi\inc \
          plutommi\mmi\resource\inc \
	    plutommi\CUI\inc \
          plutommi\Framework\Interface          \
          plutommi\mmi\inc\MenuID          \
          plutommi\mmi\MainMenu\MainMenuInc          \
          plutommi\mmi\Messages\MessagesInc          \
          plutommi\mmi\miscframework\miscframeworkinc          \
          plutommi\mmi\phonebook\PhonebookInc          \
          plutommi\mmi\sat\satInc          \
          plutommi\mmi\Setting\SettingInc          \
          plutommi\MtkApp\MtkAppInc          \
          plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
          plutommi\MtkApp\SoundRecorder\SoundRecorderInc          \
          plutommi          \
          plutommi\customer\customerinc          \
          plutommi\MtkApp\Camera\CameraInc          \
          plutommi\MtkApp\AudioPlayer\AudioPlayerInc          \
          plutommi\MtkApp\FileMgr\FileMgrInc          \
          plutommi\Framework\GDI\GDIInc          \
          plutommi\Framework\InputMethod\Inc          \
          plutommi\Framework\InputMethod\Engine\Engine_Inc          \
          plutommi\Framework\InputMethod\ui\ui_Inc \
          vendor\handwriting\guobi\v1\inc   \
          hal\system\dcmgr\inc  \
          hal\system\init\inc

# Define the specified compile options to COMP_DEFS
COMP_DEFS = MMI_ON_HARDWARE_P \
            __UCS2_ENCODING

