#ifdef __SOCIAL_NETWORK_SUPPORT__

#include "custom_sns_config.h"
#include "nvram_common_defs.h"
#include "FileMgrSrvGProt.h"
#include "USBSrvGprot.h"
#include "DtcntSrvGprot.h"
#include "PhbSrvGprot.h"

#ifndef __MMI_SNS_PRELOAD_FACEBOOK__
const kal_uint8 *custom_sns_get_preload_facebook(void) { return NULL; }
#else
#ifdef WIN32
const kal_uint8 *custom_sns_get_preload_facebook(void) { return (kal_uint8 *)1; }
#else
extern const kal_uint8 FB_vpp[];
const kal_uint8 *custom_sns_get_preload_facebook(void) { return FB_vpp; }
#endif
#endif
#ifndef __MMI_SNS_PRELOAD_TWITTER__
const kal_uint8 *custom_sns_get_preload_twitter(void) { return NULL; }
#else
#ifdef WIN32
const kal_uint8 *custom_sns_get_preload_twitter(void) { return (kal_uint8 *)1; }
#else
extern const kal_uint8 TW_vpp[];
const kal_uint8 *custom_sns_get_preload_twitter(void) { return TW_vpp; }
#endif
#endif
#ifndef __MMI_SNS_PRELOAD_RENREN__
const kal_uint8 *custom_sns_get_preload_renren(void) { return NULL; }
#else
#ifdef WIN32
const kal_uint8 *custom_sns_get_preload_renren(void) { return (kal_uint8 *)1; }
#else
extern const kal_uint8 RR_vpp[];
const kal_uint8 *custom_sns_get_preload_renren(void) { return RR_vpp; }
#endif
#endif

kal_bool custom_sns_using_card_memory(void)
{
#if defined(CHAMPAGNE55N_V2_DEMO_BB) || defined(VICTOR56_DEMO_BB)
    return KAL_FALSE;
#else
    return KAL_TRUE;
#endif
}

kal_bool custom_sns_get_keys_for_facebook(kal_char **api_key, kal_char **secret_key)
{
/*
    static kal_char api_key_fb[]    = "please fill your api key";
    static kal_char secret_key_fb[] = "please fill your secret key";
    *api_key = (kal_char *)api_key_fb;
    *secret_key = (kal_char *)secret_key_fb;
    return KAL_TRUE;
*/
    return KAL_FALSE;
}

kal_bool custom_sns_get_keys_for_twitter(kal_char **api_key, kal_char **secret_key)
{
/*
    static kal_char api_key_tw[]    = "please fill your api key";
    static kal_char secret_key_tw[] = "please fill your secret key";
    *api_key = (kal_char *)api_key_tw;
    *secret_key = (kal_char *)secret_key_tw;
    return KAL_TRUE;
*/
    return KAL_FALSE;
}

kal_uint16 custom_sns_get_lid(void)
{
    return NVRAM_EF_SRV_SNS_ACCOUNT_LID; 
}

/*
 * Used to prevent event ID shifting when re-config feature options.
 */
#ifdef __MMI_USB_SUPPORT__
kal_uint16 gEvtIdUsbEnterMsMode = EVT_ID_USB_ENTER_MS_MODE;
kal_uint16 gEvtIdUsbExitMsMode = EVT_ID_USB_EXIT_MS_MODE;
#endif /* __MMI_USB_SUPPORT__ */
kal_uint16 gEvtIdSrvFmgrNotificationDevPlugOut = EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT;
kal_uint16 gEvtIdSrvFmgrNofiticationDevPlugin = EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN;
kal_uint16 gEvtIdSrvFmgrNotificationDevReady = EVT_ID_SRV_FMGR_NOTIFICATION_DEV_READY;
kal_uint16 gEvtIdSrvFmgrNotificationAdvAction = EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION;
kal_uint16 gEvtIdSrvFmgrNotificationFormat = EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT;
kal_uint16 gEvtIdSrvDtcntSimPreferenceUpdateInd = EVT_ID_SRV_DTCNT_SIM_PREFERENCE_UPDATE_IND;
kal_uint16 gEvtIdPhbDelContact = EVT_ID_PHB_DEL_CONTACT;


#endif /*__SOCIAL_NETWORK_SUPPORT__*/
