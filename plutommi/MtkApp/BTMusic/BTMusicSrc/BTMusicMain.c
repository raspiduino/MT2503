#include "MMI_features.h"
#if defined(__MMI_BT_MUSIC__)

#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif //__MMI_USB_SUPPORT__

#ifdef __MMI_BACKGROUND_CALL__
#include "UCMGProt.h"
#endif //__MMI_BACKGROUND_CALL__

#include "CommonScreens.h"
#include "UCMSrvGProt.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "BTMusicProt.h"
#include "AudioPlayerBTNowPlaying.h"
#include "MMIDataType.h"
#include "mmi_rp_app_bt_music_def.h"
#include "string.h"
#include "GlobalResDef.h"
#include "BTDialerSrvGprot.h"

#ifdef __MMI_AVRCP_SUPPORT__
#include "BtcmSrvGprot.h"
#include "BTMMIAVRCPGProt.h"
#endif // __MMI_AVRCP_SUPPORT__ 

#ifdef __MMI_A2DP_SUPPORT__
#include "av_bt.h"
#endif  // __MMI_A2DP_SUPPORT__
/*******************************************************/
/*******************************************************/
void HighlightAudioPlayerBt(void)
{
    SetLeftSoftkeyFunction(mmi_bt_music_entry_main, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_bt_music_entry_main,KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
void mmi_bt_music_entry_main(void)
{
    //mdi_audio_terminate_background_play();
    mmi_bt_music_launch_fn(GRP_ID_ROOT);
    }
    
#endif //__MMI_BT_MUSIC__
