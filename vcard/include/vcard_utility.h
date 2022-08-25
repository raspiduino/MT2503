#ifndef VCARD_UTILITY_H
#define VCARD_UTILITY_H

#ifdef __VCARD_SUPPORT__

#include "kal_general_types.h"
#include "stack_config.h"
#include "stack_msgs.h"

#define VCARD_MAX_PATH_LEN          259
#define VCARD_MAX_READ_LENGTH       512
#define VCARD_MAX_WRITE_LENGTH      256
#define VCARD_MAX_LINE_LENGTH       2048
#define VCARD_MAX_FIELD_LENGTH      448

#define VCARD_MAX_FIELD_COUNT       7
#define VCARD_MAX_QT_COUNT          9
#define VCARD_MAX_LIMIT_QT_LINE     72

typedef enum
{
    VCARD_STATE_NAME,
    VCARD_STATE_PARAM,
    VCARD_STATE_DATA
} vcard_state_enum;

typedef enum
{
    VCARD_TAG_BEGIN,
    VCARD_TAG_FN,
    VCARD_TAG_N,
    VCARD_TAG_NICKNAME,
    VCARD_TAG_PHOTO,
    VCARD_TAG_BDAY,
    VCARD_TAG_ADR,
    VCARD_TAG_LABEL,
    VCARD_TAG_TEL,
    VCARD_TAG_EMAIL,
    VCARD_TAG_MAILER,
    VCARD_TAG_TZ,
    VCARD_TAG_GEO,
    VCARD_TAG_TITLE,
    VCARD_TAG_ROLE,
    VCARD_TAG_LOGO,
    VCARD_TAG_AGENT,
    VCARD_TAG_ORG,
    VCARD_TAG_CATEGORIES,
    VCARD_TAG_NOTE,
    VCARD_TAG_PRODID,
    VCARD_TAG_REV,
    VCARD_TAG_SORT_STRING,
    VCARD_TAG_SOUND,
    VCARD_TAG_URL,
    VCARD_TAG_UID,
    VCARD_TAG_VERSION,
    VCARD_TAG_CLASS,
    VCARD_TAG_KEY,
    VCARD_TAG_X_NICKNAME,
    VCARD_TAG_X_CATEGORIES,
    #if defined(__BT_PBAP_CLIENT__)
	VCARD_TAG_X,
	#endif
    VCARD_TAG_END,
    VCARD_TAG_UNKNOWN
} vcard_tag_enum;

typedef enum
{
    VCARD_ENCODING_7BIT,
    VCARD_ENCODING_BASE64,
    VCARD_ENCODING_QP,
    VCARD_ENCODING_8BIT
} vcard_encoding_enum;

typedef enum
{
    VCARD_CHARSET_ASCII,
    VCARD_CHARSET_8859_1,
    VCARD_CHARSET_SHIFT_JIS,
    VCARD_CHARSET_UTF8,
    VCARD_CHARSET_BIG5,
    VCARD_CHARSET_HKSCS,
    VCARD_CHARSET_GB2312,
    VCARD_CHARSET_GB18030
} vcard_charset_enum;

vcard_tag_enum vcard_get_tag(kal_char *name);
void vcard_strupr(kal_char *name);
kal_bool vcard_check_tcard(void);
void vcard_create_folder(kal_wchar *path);

void vcard_convert_to_ucs2(kal_char *field_src, kal_wchar *field_dest, vcard_charset_enum charset, kal_int32 max_len);
void vcard_convert_to_utf8(kal_wchar *field_src, kal_char *field_dest);

#ifdef __MULTI_VCARD_SUPPORT__

void vcard_send_msg_to_udx(module_type src_id, msg_type msg_id, void *local_para_ptr);
void vcard_send_msg_from_udx(module_type dest_id, msg_type msg_id, void *local_para_ptr);

#endif /* __MULTI_VCARD_SUPPORT__ */

kal_bool vcard_add_instance(void *handle);
kal_bool vcard_remove_instance(void *handle);

#endif /* __VCARD_SUPPORT__ */

#endif /* VCARD_UTILITY_H */

