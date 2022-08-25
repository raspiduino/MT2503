
#ifndef __GB_WG_MTKPLATVER_H__
#define __GB_WG_MTKPLATVER_H__


// 用的是什么平台的
#define __GB_MTK_PLATFORM__


#ifdef __GB_MTK_PLATFORM__
//#define GB_MTK_09APLAT
#define GB_MTK_10APLAT
//#define GB_MTK_11B6255
//#define GB_MTK_10A1108
//#define GB_MTK_08BPLAT
//#define GB_MTK_08APLAT
//#define GB_MTK_07B
#endif



//#define GB_MTK_QWERTY
#define GB_MTK_TOUCH
//#define GB_MTK_NUMKEY
//#define TEST_RAND_TIME

#define DIRECT_UPDATE_TIME
//#define DELAY_UPDATE_TIME
//#define FULL_UPDATE_DATA

#if defined(GB_MTK_09BPLAT) || defined(GB_MTK_10APLAT)
#define MAX_PB_PHONE_ENTRIES  MMI_PHB_PHONE_ENTRIES
#define MAX_PB_SIM_ENTRIES  MMI_PHB_SIM_ENTRIES
#define MAX_PB_NUMBER_LENGTH  MMI_PHB_NUMBER_LENGTH
#define MAX_PB_NAME_LENGTH  MMI_PHB_NAME_LENGTH
#define MAX_PB_EMAIL_LENGTH MMI_PHB_EMAIL_LENGTH

#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
#define OPTIONAL_FIELDS_RECORD_SIZE (169 + MAX_PB_EMAIL_LENGTH * 2)     /* optional fields size */
#else
#define OPTIONAL_FIELDS_RECORD_SIZE (169 + MAX_PB_EMAIL_LENGTH)         /* optional fields size */
#endif

#endif //#ifdef GB_MTK_09BPLAT

#endif // #ifndef __GB_WG_MTKPLATVER_H__