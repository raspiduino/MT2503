/*****************************************************************************
*
* Filename:
* ---------
* cbm_consts.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file contains the CBM enums and constants
*
* Author:
* -------
 * -------
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef _CBM_CONSTS_H
#define _CBM_CONSTS_H


/*************************************************************************
* Constant values
*************************************************************************/

#ifdef __ABM_CBM_SLIM__

/* all network account id */
#define CBM_ALL_NWK_ACCT_ID     (0x3f)
/* invalid network account id */
#define CBM_INVALID_NWK_ACCT_ID (0x3e)
/* dcd network account id */
#define CBM_DCD_ACCT_ID	(0x3d)
/* external modem network account id */
#define CBM_EXT_MODEM_ACCT_ID	(0x3c)
/* SATCE csd network account id */
#define CBM_SAT_CSD_ACCT_ID	(0x3b)
/* SATCE gprs network account id */
#define CBM_SAT_PS_ACCT_ID (0x3a)
/* loopback network account id */
#define CBM_LOOPBACK_ACCT_ID	(0x39)
/* wifi account id */
#define CBM_WIFI_ACCT_ID    (0x38)
/* wifi hot spot account id */
#define CBM_WIFI_HS_ACCT_ID (0x37)
/* usb tethering account id */
#define CBM_USB_TR_ACCT_ID (0x36)
/* usb tethering ps account id */
#define CBM_USB_TR_PS_ACCT_ID (0x35)
/* default network account id. 
 * when application use this network account id,
 * smart setting will be applied.
 */
#define CBM_DEFAULT_ACCT_ID		(0x34)
/* MRE network account id */
#define CBM_MRE_ACCT_ID     (0x33)
/* wifi ap mode account id */
#define CBM_AP_MODE_ACCT_ID     (0x32)

#else /* __ABM_CBM_SLIM__ */

/* all network account id */
#define CBM_ALL_NWK_ACCT_ID     (0x7f)
/* invalid network account id */
#define CBM_INVALID_NWK_ACCT_ID (0x7e)
/* dcd network account id */
#define CBM_DCD_ACCT_ID	(0x7d)
/* external modem network account id */
#define CBM_EXT_MODEM_ACCT_ID	(0x7c)
/* SATCE csd network account id */
#define CBM_SAT_CSD_ACCT_ID	(0x7b)
/* SATCE gprs network account id */
#define CBM_SAT_PS_ACCT_ID (0x7a)
/* loopback network account id */
#define CBM_LOOPBACK_ACCT_ID	(0x79)
/* wifi account id */
#define CBM_WIFI_ACCT_ID    (0x78)
/* wifi hot spot account id */
#define CBM_WIFI_HS_ACCT_ID (0x77)
/* usb tethering account id */
#define CBM_USB_TR_ACCT_ID (0x76)
/* usb tethering ps account id */
#define CBM_USB_TR_PS_ACCT_ID (0x75)
/* default network account id. 
 * when application use this network account id,
 * smart setting will be applied.
 */
#define CBM_DEFAULT_ACCT_ID		(0x74)
/* MRE network account id */
#define CBM_MRE_ACCT_ID     (0x73)
/* wifi ap mode account id */
#define CBM_AP_MODE_ACCT_ID     (0x72)

#endif /* __ABM_CBM_SLIM__ */


/* invalid module id */
#define CBM_INVALID_MOD_ID  (0)
/* invalid application id */
#define CBM_INVALID_APP_ID  (0)

/* max applicaiton id */
#define CBM_MAX_APP_ID          (0xff)
/* max account number in 32-bits account id */
#define CBM_MAX_ACCT_NUM        (2)
/* all qos id */
#define CBM_ALL_QOS_ID          (0xff)

/* Minimum network account ID */
#define ABM_MIN_NWACC_ID    (0)


/*************************************************************************
* Enum values
*************************************************************************/

/* sim id */
typedef enum
{
    CBM_SIM_ID_SIM1, /* sim card one */
    CBM_SIM_ID_SIM2, /* sim card two */
    CBM_SIM_ID_SIM3, /* sim card there */
    CBM_SIM_ID_SIM4, /* sim card four */
    CBM_SIM_ID_TOTAL /* total sim card number */
} cbm_sim_id_enum;

/* Bearer state */
typedef enum
{
    CBM_DEACTIVATED             = 0x01, /* deactivated */
    CBM_ACTIVATING              = 0x02, /* activating */
    CBM_ACTIVATED               = 0x04, /* activated */
    CBM_DEACTIVATING            = 0x08, /* deactivating */
    CBM_CSD_AUTO_DISC_TIMEOUT   = 0x10, /* csd auto disconnection timeout */
    CBM_GPRS_AUTO_DISC_TIMEOUT  = 0x20, /* gprs auto disconnection timeout */
    CBM_NWK_NEG_QOS_MODIFY      = 0x040, /* negotiated network qos modify notification */
    CBM_WIFI_STA_INFO_MODIFY      = 0x080, /* wifi hot spot sta number is changed */
    CBM_BEARER_STATE_TOTAL
} cbm_bearer_state_enum;

typedef enum
{
    /* no bearer event */
    CBM_APP_BEARER_EVT_NONE = 0,
    /* always ask event */
    CBM_APP_BEARER_EVT_ALWAYS_ASK = 0x01,
    /* bearer fallback level one event */
    CBM_APP_BEARER_EVT_FB_L1       = 0x02, 
    /* bearer fallback level one with new connection event */
    CBM_APP_BEARER_EVT_FB_L1_WITH_NEW_CONN           = 0x04, 
    /* support non-auto bearer fallback level two with new connection */
    CBM_APP_BEARER_EVT_FB_L2_WITH_NEW_CONN   = 0x08, 
    /* support wifi to gprs fallback */
    CBM_APP_BEARER_EVT_FB_WIFI_TO_PS = 0x10,
    CBM_APP_BEARER_EVT_SWITCH = 0x20,
    CBM_APP_BEARER_EVT_DISCONNECT = 0x40,
    CBM_APP_BEARER_EVT_TOTAL
} cbm_app_bearer_event_enum;

/* bearer type */
typedef enum
{
    CBM_BEARER_NONE, /* no valid bearer */
    CBM_CSD = 0x01, /* CSD bearer */
    CBM_BEARER_GSM_CSD = CBM_CSD, /* CSD bearer */
    CBM_GPRS = 0x02, /* GPRS bearer */
    CBM_BEARER_GSM_GPRS = CBM_GPRS, /* GPRS bearer */
    CBM_EDGE = 0x04, /* EDGE bearer */
    CBM_BEARER_EDGE = CBM_EDGE, /* EDGE bearer */
    
    CBM_WIFI = 0x08, /* WIFI bearer */
    CBM_BEARER_WIFI = CBM_WIFI, /* WIFI bearer */

    CBM_WIFI_HS = 0x10, /* WIFI hot spot bearer */
    CBM_BEARER_HOTSPOT = CBM_WIFI_HS, /* WIFI hot spot bearer */
    
    CBM_USB_TR  = 0x20, /* USB Tethering */
    CBM_BEARER_USB_TR = CBM_USB_TR, /* USB Tethering */
    
    CBM_LOOPBACK = 0x40, /* loopback */
    CBM_BEARER_LOOPBACK = CBM_LOOPBACK, /* loopback */

    CBM_UMTS = 0x80, /* 3G UMTS (WCDMA) bearer */
    CBM_BEARER_UMTS = CBM_UMTS, /* 3G UMTS (WCDMA) bearer */


    CBM_3G = CBM_UMTS, /* Not real activated bearer type. This is 3G general name.
                          It contains all 3G bearer types, such as WCDMA, STDWCDMA, etc. */
    CBM_BEARER_3G = CBM_UMTS, /* Not real activated bearer type. This is 3G general name.
                                 It contains all 3G bearer types, such as WCDMA, STDWCDMA, etc. */

    CBM_PS  = CBM_GPRS | CBM_EDGE | CBM_BEARER_3G, /* Not real activated bearer type. This is packet service general name.
                                                      It contains all packet service types, such as GPRS, EDGE, UMTS, etc. */
    CBM_BEARER_PS = CBM_PS, /* Not real activated bearer type. This is packet service general name.
                               It contains all packet service types, such as GPRS, EDGE, UMTS, etc. */

    CBM_AP_MODE = 0x0100, /* WIFI AP mode bearer */
    CBM_BEARER_AP_MODE = CBM_AP_MODE, /* WIFI AP mode bearer */
    
    CBM_BEARER_TOTAL = 0xffff
} cbm_bearer_enum;

/* error cause */
typedef enum
{
    CBM_OK                  = 0,  /* success */
    CBM_ERROR               = -1, /* error */
    CBM_WOULDBLOCK          = -2, /* would block */
    CBM_LIMIT_RESOURCE      = -3, /* limited resource */
    CBM_INVALID_ACCT_ID     = -4, /* invalid account id*/
    CBM_INVALID_AP_ID       = -5, /* invalid application id*/
    CBM_INVALID_SIM_ID      = -6, /* invalid SIM id */
    CBM_BEARER_FAIL         = -7, /* bearer fail */
    CBM_DHCP_ERROR          = -8, /* DHCP get IP error */
    CBM_CANCEL_ACT_BEARER   = -9, /* cancel the account query screen, such as always ask or bearer fallback screen */
    CBM_DISC_BY_CM          = -10 /* bearer is deactivated by the connection management */
} cbm_result_error_enum;


/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __ABM_CBM_SLIM__
#define ABM_SPARED_APP_NUM  4
#else
#define ABM_SPARED_APP_NUM  9
#endif

/* Define Max application numbers */
#ifdef __IPSEC__
#define ABM_IPSEC_APP_NUM   1
#else
#define ABM_IPSEC_APP_NUM   0
#endif

#ifdef WAP_SUPPORT
#define ABM_WAP_APP_NUM     4
#else
#define ABM_WAP_APP_NUM     0
#endif

#ifdef STREAM_SUPPORT
#define ABM_STREAM_APP_NUM  1
#else
#define ABM_STREAM_APP_NUM  0
#endif

#ifdef __J2ME__
#define ABM_JAVA_APP_NUM    2
#else
#define ABM_JAVA_APP_NUM    0
#endif

#ifdef __EMAIL__
#define ABM_EMAIL_APP_NUM   4
#else
#define ABM_EMAIL_APP_NUM   0
#endif

#ifdef __VOIP__
#define ABM_VOIP_APP_NUM    1
#else
#define ABM_VOIP_APP_NUM    0
#endif

#ifdef __SYNCML_SUPPORT__
#define ABM_SYNCML_APP_NUM    3
#else
#define ABM_SYNCML_APP_NUM    0
#endif

#ifdef SYNCML_DM_SUPPORT
#define ABM_SYNCML_DM_APP_NUM    5
#else
#define ABM_SYNCML_DM_APP_NUM    0
#endif

#ifdef MMS_SUPPORT
#define ABM_MMS_APP_NUM     4
#else
#define ABM_MMS_APP_NUM     0
#endif

#ifdef __WIFI_SUPPORT__
#define ABM_WIFI_APP_NUM     1
#else
#define ABM_WIFI_APP_NUM     0
#endif

#ifdef __SATCE__
#define ABM_SAT_APP_NUM     1
#else
#define ABM_SAT_APP_NUM     0
#endif

#ifdef __SUPL_SUPPORT__
#define ABM_SUPL_APP_NUM    1
#else
#define ABM_SUPL_APP_NUM    0
#endif

#ifdef __SSL_SUPPORT__
#define ABM_SSL_APP_NUM    1
#else
#define ABM_SSL_APP_NUM    0
#endif

#ifdef __HOTSPOT_SUPPORT__
#define ABM_HOTSPOT_APP_NUM    1
#else
#define ABM_HOTSPOT_APP_NUM    0
#endif

#define ABM_MRE_APP_NUM     1

#ifdef __IOT__
#define ABM_IOT_APP_NUM    6
#else
#define ABM_IOT_APP_NUM    0
#endif


/* DOM-NOT_FOR_SDK-END */

/* couting total application numbers which are supported to use network service */
typedef enum
{
    ABM_APP_NUM_SPARED = ABM_SPARED_APP_NUM,                                    /* Spared app number: 9 */
    ABM_IPSEC_APP_NUM_END = ABM_APP_NUM_SPARED + ABM_IPSEC_APP_NUM,             /* IPSEC app number: 9+1 */
    ABM_WAP_APP_NUM_END = ABM_IPSEC_APP_NUM_END + ABM_WAP_APP_NUM,              /* WAP app number: 10+4 */
    ABM_STREAM_APP_NUM_END = ABM_WAP_APP_NUM_END + ABM_STREAM_APP_NUM,          /* Stream app number: 14+1 */
    ABM_JAVA_APP_NUM_END = ABM_STREAM_APP_NUM_END+ ABM_JAVA_APP_NUM,            /* Java app number: 15+2 */
    ABM_EMAIL_APP_NUM_END = ABM_JAVA_APP_NUM_END + ABM_EMAIL_APP_NUM,           /* EMAIL app number: 17+4 */
    ABM_VOIP_APP_NUM_END = ABM_EMAIL_APP_NUM_END + ABM_VOIP_APP_NUM,            /* VOIP app number: 21+1 */
    ABM_SYNCML_APP_NUM_END = ABM_VOIP_APP_NUM_END + ABM_SYNCML_APP_NUM,         /* SYNCML app number: 22+3 */
    ABM_MMS_APP_NUM_END = ABM_SYNCML_APP_NUM_END + ABM_MMS_APP_NUM,             /* MMS app number: 25+4 */
    ABM_WIFI_APP_NUM_END = ABM_MMS_APP_NUM_END + ABM_WIFI_APP_NUM,              /* WIFI app number: 29+1 */
    ABM_SAT_APP_NUM_END = ABM_WIFI_APP_NUM_END + ABM_SAT_APP_NUM,               /* SAT app number: 30+1 */
    ABM_SUPL_APP_NUM_END = ABM_SAT_APP_NUM_END + ABM_SUPL_APP_NUM,              /* SUPL app number: 31+1 */
    ABM_SSL_APP_NUM_END = ABM_SUPL_APP_NUM_END + ABM_SSL_APP_NUM,               /* SSL app number: 32+1 */
    ABM_SYNCML_DM_APP_NUM_END = ABM_SSL_APP_NUM_END + ABM_SYNCML_DM_APP_NUM,    /* Syncml DM app number: 33+5 */
    ABM_HOTSPOT_APP_NUM_END = ABM_SYNCML_DM_APP_NUM_END + ABM_HOTSPOT_APP_NUM,  /* hotspot app number: 38+1*/
    ABM_MRE_APP_NUM_END = ABM_HOTSPOT_APP_NUM_END + ABM_MRE_APP_NUM,            /* MRE app number: 39+1*/
    ABM_IOT_APP_NUM_END = ABM_MRE_APP_NUM_END + ABM_IOT_APP_NUM,                /* IOT app number: 40+6*/
    
    ABM_MAX_APP_NUM = ABM_IOT_APP_NUM_END                 /* Max app number: 46 */
} abm_max_app_num_enum;

#endif /* _CBM_CONSTS_H */

