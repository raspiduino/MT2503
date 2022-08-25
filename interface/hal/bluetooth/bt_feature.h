#ifndef __BT_FEATURE_H
#define __BT_FEATURE_H

#define __BT_MAUI_PLATFORM__


/* Due to 6601 is phase out. Always set chip version 1. */
//#if defined(__BTMODULE_MT6601__)
//#define __BT_CHIP_VERSION_0__   
//#else
#define __BT_CHIP_VERSION_1__
//#endif


//#define __ENABLE_NUM_COMPLETED_PKT_EVENT_TIMER__
#if defined(__BTMODULE_MT6616__)
/* Turn on or off MTK_STP_SUPPORTED compile option here */
#if !defined (__MT6616_NO_STP__)
#define __MTK_STP_SUPPORTED__
#endif /*__MT6616_NO_STP__*/
#endif /*__BTMODULE_MT6616__*/


#ifdef __BT_VER_21__
#define __BT_2_1_AUTO_FLUSH__
#define __BT_2_1_SUPERVISION_TIMEOUT_EVENT__
#define __BT_2_1_ENABLED__
#define __BT_2_1_SNIFF_SUBRATING__
#define __BT_2_1_ENTENDED_INQUIRY_RESPONSE__
#ifndef __BT_DISABLE_SSP_SUPPORT__
#define __BT_2_1_SIMPLE_PAIRING__
#endif
#endif /* __BT_VER_21__ */ 

#ifdef __BT_VER_30__
#define __BT_2_1_AUTO_FLUSH__
#define __BT_2_1_SUPERVISION_TIMEOUT_EVENT__
#define __BT_2_1_ENABLED__
#define __BT_2_1_SNIFF_SUBRATING__
#define __BT_2_1_ENTENDED_INQUIRY_RESPONSE__
#ifndef __BT_DISABLE_SSP_SUPPORT__
#define __BT_2_1_SIMPLE_PAIRING__
#endif
#define __BT_3_0_UNICAST__
#endif

#define __BT_2_1_BLOCK_DEVICE__

#if defined (__WIFI_BT_SINGLE_ANTENNA_SUPPORT__)
#define __BT_SINGLE_ANTENNA__
#endif


#endif /* __BT_FEATURE_H */ 
