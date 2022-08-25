# Define source file lists to SRC_LIST
SRC_LIST = applib\misc\src\app_asyncfile.c \
applib\misc\src\app_base64.c \
applib\misc\src\app_datetime.c \
applib\misc\src\app_time.c \
applib\misc\src\app_mime.c \
applib\misc\src\app_qp.c \
applib\misc\src\app_str.c \
applib\misc\src\app_md5.c \
applib\mem\src\app_mem.c \
applib\misc\src\app_crc.c \
applib\misc\src\app_url.c \
applib\kazlib\dict.c \
applib\misc\src\app_ua.c \
applib\misc\src\app_addr.c \
applib\misc\src\app_html.c \
applib\misc\src\app_html_char_ref.c \
applib\misc\src\app_plmn.c

ifneq ($(filter __MMI_MMS_POSTCARD__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += applib\misc\src\app_oppostcard.c 
endif

ifneq ($(filter __MMI_FMI__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += applib\misc\src\app_usedetails.c
endif

#  Define include path lists to INC_DIR
INC_DIR = applib\misc\include \
applib\mem\include \
drv\include \
dp_engine\che\include \
plutommi\mmi\inc \
plutommi\Framework\Interface \
plutommi\CUI\Inc \
plutommi\Framework\NVRAMManager\NVRAMManagerInc \
lcmmi\mmi\Framework\NVRAMManager\NVRAMManagerInc \
vendor\game_engine\brogent\adaptation \
plutommi\mtkapp\barcodereader\barcodereaderinc \
plutommi\Framework\GDI\GDIINC \
vendor\game_engine\intergrafx\adaptation \
plutommi\MtkApp\Avatar\AvatarInc \
plutommi\MtkApp\Camera\CameraInc \
plutommi\MtkApp\Camcorder\CamcorderInc \
plutommi\service\MDI\MDIInc \
plutommi\mmi\UnifiedMMS\MMSApp\MMSAppInc \
plutommi\Service\UmmsSrv \
custom\common\pluto_mmi \
custom\common custom\common\hal custom\common\ps \
plutommi\MMI\BrowserApp\Browser\BrowserInc \
plutommi\Framework\CommonFiles\commoninc \
plutommi\Framework\Tasks\tasksinc \
plutommi\Framework\MemManager\memmanagerinc \
plutommi\Framework\DebugLevels\debuglevelinc \
plutommi\mtkapp\mmiapi\include \
plutommi\mtkapp\mtkappinc \
plutommi\MtkApp\MobileTVPlayer\MobileTVPlayerInc \
plutommi\MtkApp\DTVPlayer\DTVPlayerInc \
plutommi\MtkApp\PhotoEditor\PhotoEditorInc \
plutommi\mtkapp\ABRepeater\ABRepeaterInc \
plutommi\mtkapp\connectivity\connectivityinc\btmtk \
plutommi\mtkapp\connectivity\connectivityinc\btcommon \
plutommi\mtkapp\MediaPlayer\MediaPlayerInc \
media\common\include \
media\image\include \
plutommi\mtkapp\filemgr\filemgrinc \
fmt\include \
plutommi\mmi\datetime\datetimeinc \
vendor\wap\obigo_q03c\adaptation\integration\include \
plutommi\Framework\InputMethod\inc \
plutommi\customer\customerinc \
plutommi\MMI\miscframework\miscframeworkinc \
plutommi\mmi\inc\menuid \
plutommi\mmi\audio\audioinc \
plutommi\Framework\GUI\gui_inc \
plutommi\Framework\GUI\oem_inc \
plutommi\mmi\idlescreen\idlescreeninc \
plutommi\mmi\profiles\profilesinc \
plutommi\mmi\phonebook\phonebookinc \
plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
venusmmi\app\common\data \
plutommi\mmi\Organizer\OrganizerInc \
plutommi\mtkapp\Video\VideoInc \
plutommi\service\inc \
xmlp\include \
media\vcall\include \
plutommi\mtkapp\MREAPP\MREAPPInc \
plutommi\mmi\BrowserApp\Browser\BrowserInc \
plutommi\Service\BrowserSrv \
plutommi\MtkApp\WgtMgrApp\WgtMgrAppInc \
vendor\opera\browser\adaptation\inc \
plutommi\mmi\Setting\SettingInc \
plutommi\mmi\emailapp\emailappinc \
venusmmi\app\Cosmos\interface\app \
venusmmi\framework\interface \
venusmmi\app\Cosmos\ucm \
hal\peripheral\inc \
venusmmi\framework\ui_core\base\
venusmmi\app\Cosmos\WidgetDelegator \
j2me\jal\include \
plutommi\mtkapp\javaagency\javaagencyinc 

# Define the specified compile options to COMP_DEFS
COMP_DEFS = MMI_ON_HARDWARE_P \
__UCS2_ENCODING

