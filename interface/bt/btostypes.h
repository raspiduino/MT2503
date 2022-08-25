#ifndef __BTOSTYPES_H__
#define __BTOSTYPES_H__

#include "btostypes_int.h"

#ifndef _BDADDR7_
#define _BDADDR7_
#endif

typedef enum
{
    OS_STATUS_SUCCESS	= 0,
    OS_STATUS_FAILED	= 1,
} OS_STATUS;

// TODO: to update
typedef enum
{
    OS_FS_STATUS_OK				= 0,
    OS_FS_ERR					= -1,
    OS_FS_ERR_PATH				= -2,
    OS_FS_ERR_ACCESS			= -3,
    OS_FS_ERR_FULL 				= -4,
    OS_FS_ERR_EXIST 			= -5,
    OS_FS_ERR_DELAYED 			= -6,
    OS_FS_ERR_DEVICE_BUSY 		= -7,
    OS_FS_ERR_LOCK_MUTEX_FAIL 	= -8,
    OS_FS_ERR_ROOT_DIR_FULL 	= -9,
    OS_FS_ERR_APP_QUOTA_FULL 	= -10,
    OS_FS_ERR_WRITE_PROTECTION 	= -11,
    OS_FS_ERR_MEDIA_CHANGED 	= -12,
    OS_FS_ERR_MSDC_MOUNT_ERROR 	= -13,
    OS_FS_ERR_MSDC_NOT_PRESENT 	= -14,
    OS_FS_ERR_EOF 				= -15
} OS_FS_STATUS;

typedef enum
{
    OS_FS_READ_WRITE     = 0x000000001,
    OS_FS_READ_ONLY      = 0x000000002,
    OS_FS_CREATE         = 0x000000004,
    OS_FS_CREATE_ALWAYS  = 0x000000008,
    OS_FS_NONBLOCK       = 0x000000010,
    OS_FS_APPEND         = 0x000000020,
    OS_FS_OPEN_DIR       = 0x000000040,
} OS_FS_MODE;

typedef enum
{
    OS_CHSET_NONE,
    OS_CHSET_ARABIC_ISO,
    OS_CHSET_ARABIC_WIN,
    /* PMT START PERSIAN */
    OS_CHSET_PERSIAN_CP1097,
    OS_CHSET_PERSIAN_CP1098,
    /* PMT END PERSIAN */
    OS_CHSET_BALTIC_ISO,
    OS_CHSET_BALTIC_WIN,
    OS_CHSET_CEURO_ISO,
    OS_CHSET_CEURO_WIN,
    OS_CHSET_CYRILLIC_ISO,
    OS_CHSET_CYRILLIC_WIN,
    OS_CHSET_GREEK_ISO,
    OS_CHSET_GREEK_WIN,
    OS_CHSET_HEBREW_ISO,
    OS_CHSET_HEBREW_WIN,
    OS_CHSET_LATIN_ISO,
    OS_CHSET_NORDIC_ISO,
    OS_CHSET_SEURO_ISO,
    OS_CHSET_TURKISH_ISO,
    OS_CHSET_TURKISH_WIN,
    OS_CHSET_WESTERN_ISO,
    OS_CHSET_ARMENIAN_ISO,
    OS_CHSET_WESTERN_WIN,
    /* Add new (8-bit) encodings above this line */
    OS_CHSET_BIG5,
    OS_CHSET_GB2312,
    OS_CHSET_HKSCS,
    OS_CHSET_SJIS,
    OS_CHSET_GB18030,
    OS_CHSET_UTF7,
    OS_CHSET_EUCKR,
    OS_CHSET_THAI_WIN,
    OS_CHSET_VIETNAMESE_WIN,
    OS_CHSET_KOI8_R,
    OS_CHSET_TIS_620,

    /* PLace all encodings using algo to above this one */
    OS_CHSET_UTF16LE,
    OS_CHSET_UTF16BE,
    OS_CHSET_UTF8,
    OS_CHSET_UCS2,
    OS_CHSET_ASCII,
    OS_CHSET_TOTAL,
} OS_CHSET_ENUM;

typedef enum
{
    OS_FS_MOVE_COPY  = 0x00000001,
    OS_FS_MOVE_KILL  = 0x00000002,
    OS_FS_MOVE_OVERWRITE = 0x00000004
} OS_FS_MOVE_MODE;

typedef enum
{
    OS_FS_SEEK_BEGIN,
    OS_FS_SEEK_CURRENT,
    OS_FS_SEEK_END
} OS_FS_SEEK_MODE;


#ifndef LISTS_DEFINED
#define LISTS_DEFINED

typedef struct _ListEntry
{
    struct _ListEntry *Flink;
    struct _ListEntry *Blink;

} ListEntry;
#endif /* LISTS_DEFINED */

#ifndef BD_ADDR_SIZE
#define BD_ADDR_SIZE 6
typedef struct _BD_ADDR
{
    U8 addr[BD_ADDR_SIZE];
#ifdef _BDADDR7_
    U8 linkType; 
#endif    
} BD_ADDR;
#endif

typedef struct
{
    U32 lap;
    U8 uap;
    U16 nap;
} bt_addr_struct;

// Temporarily marked, the definition is now in bt_adp_log.h
/*
typedef enum {
	TRACE_FUNC,
	TRACE_STATE,
	TRACE_INFO,
} trace_class_enum;
*/

#endif

