#ifndef VCARD_LIB_H
#define VCARD_LIB_H

#ifdef __VCARD_SUPPORT__

#include "kal_general_types.h"
#include "conversions.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#define VCARD_MAX_N_LENGTH          60
#define VCARD_MAX_NICKNAME_LENGTH   60
#define VCARD_MAX_TITLE_LENGTH      30
#define VCARD_MAX_ORG_LENGTH        30
#define VCARD_MAX_TEL_LENGTH        60
#define VCARD_MAX_EMAIL_LENGTH      120
#define VCARD_MAX_ADR_LENGTH        30
#define VCARD_MAX_URL_LENGTH        210
#define VCARD_MAX_CATEGORY_LENGTH   30
#define VCARD_MAX_NOTE_LENGTH       210
#define VCARD_MAX_PATH_LENGTH       260
#define VCARD_MAX_UID_LENGTH        50

#define VCARD_MAX_ADR_COUNT         1
#define VCARD_MAX_TEL_COUNT         4
#define VCARD_MAX_EMAIL_COUNT       2
#define VCARD_MAX_URL_COUNT         1

/* Result */
typedef enum
{
    VCARD_RESULT_FAIL = -1,
    VCARD_RESULT_OK,
    VCARD_RESULT_MORE
} vcard_result_enum;

/* Error Code */
typedef enum
{
    /* FS Error Code here */

    VCARD_NO_ERROR,
    VCARD_ERROR_INVALID_FORMAT,
    VCARD_ERROR_UNDEFINED_VERSION,

    /* vCard Internal Use */
    VCARD_NO_ERROR_MORE = 0xFF
} vcard_error_enum;

/* Property */
typedef enum
{
    VCARD_PROPERTY_NONE = 0x0000,
    VCARD_PROPERTY_N = 0x0001,
    VCARD_PROPERTY_NICKNAME = 0x0002,
    VCARD_PROPERTY_PHOTO = 0x0004,
    VCARD_PROPERTY_BDAY = 0x0008,
    VCARD_PROPERTY_ADR = 0x0010,
    VCARD_PROPERTY_TEL = 0x0020,
    VCARD_PROPERTY_EMAIL = 0x0040,
    VCARD_PROPERTY_TITLE = 0x0080,
    VCARD_PROPERTY_ORG = 0x0100,
    VCARD_PROPERTY_CATEGORY = 0x0200,
    VCARD_PROPERTY_NOTE = 0x0400,
    VCARD_PROPERTY_URL = 0x0800,
    #if defined(__BT_PBAP_CLIENT__)
	VCARD_PROPERTY_X = 0x1000,
	#endif
    VCARD_PROPERTY_ALL = 0xFFFF
} vcard_property_enum;

/* Version */
typedef enum
{
    VCARD_VERSION_2_1,
    VCARD_VERSION_3_0
} vcard_version_enum;

/* Open Mode */
typedef enum
{
    VCARD_OPEN_MODE_DEFAULT = 0x00,
    VCARD_OPEN_MODE_APPEND = 0x01,
    VCARD_OPEN_MODE_HIDDEN = 0x02
} vcard_open_mode_enum;

/* Build Mode */
typedef enum
{
    VCARD_BUILD_MODE_DEFAULT = 0x00,
    VCARD_BUILD_MODE_TEL_ALWAYS = 0x01
} vcard_build_mode_enum;

/* Parse Mode */
typedef enum
{
    VCARD_PARSE_MODE_DEFAULT = 0x00,
    VCARD_PARSE_MODE_TEL_ALWAYS = 0x01
} vcard_parse_mode_enum;

/* Name */
typedef struct
{
    kal_wchar *family;              /* Family Name */
    kal_wchar *given;               /* Given Name */
    kal_wchar *mid;                 /* Additional Name */
    kal_wchar *prefix;              /* Name Prefix */
    kal_wchar *suffix;              /* Name Suffix */
    kal_wchar *name;                /* Formatted Name */
} vcard_n_struct;

/* Nick Name */
typedef struct
{
    kal_wchar *name;                /* Nick Name */
} vcard_nickname_struct;

/* Photo Format Type */
typedef enum
{
    VCARD_PHOTO_TYPE_JPG,
    VCARD_PHOTO_TYPE_JPEG,
    VCARD_PHOTO_TYPE_GIF,
    VCARD_PHOTO_TYPE_BMP,
    VCARD_PHOTO_TYPE_WBMP,
    VCARD_PHOTO_TYPE_WBM,
    VCARD_PHOTO_TYPE_PNG,
    VCARD_PHOTO_TYPE_M3D,
    VCARD_PHOTO_TYPE_SVG,
    VCARD_PHOTO_TYPE_TOTAL
} vcard_photo_type_enum;

/* Photograph */
typedef struct
{
    kal_wchar file_name[VCARD_MAX_PATH_LENGTH];
    vcard_photo_type_enum type;     /* Photo Format Type */
} vcard_photo_struct;

/* Birthdate */
typedef struct
{
    kal_uint16 year;                /* Year */
    kal_uint8 month;                /* Month */
    kal_uint8 day;                  /* Day */
} vcard_bday_struct;

/* Delivery Address */
typedef struct
{
    kal_wchar *post_office;         /* Post Office Address */
    kal_wchar *extended;            /* Extented Address */
    kal_wchar *street;              /* Street */
    kal_wchar *locality;            /* Locality */
    kal_wchar *region;              /* Region */
    kal_wchar *postal_code;         /* Postal Code */
    kal_wchar *country;             /* Country */
} vcard_adr_struct;

/* Telephone Type */
typedef enum
{
    VCARD_TEL_TYPE_VOICE,
    VCARD_TEL_TYPE_CELL,
    VCARD_TEL_TYPE_HOME,
    VCARD_TEL_TYPE_WORK,
    VCARD_TEL_TYPE_FAX,
    VCARD_TEL_TYPE_TOTAL
} vcard_tel_type_enum;

/* Telephone Number */
typedef struct
{
    kal_wchar *tel;                 /* Telephone Number */
    vcard_tel_type_enum type;       /* Telephone Type */
    kal_bool is_preferred;          /* Preferred Number or not */
} vcard_tel_struct;

/* Email Type */
typedef enum
{
    VCARD_EMAIL_TYPE_INTERNET,
    VCARD_EMAIL_TYPE_HOME,
    VCARD_EMAIL_TYPE_WORK,
    VCARD_EMAIL_TYPE_TOTAL
} vcard_email_type_enum;

/* Electronic Mail */
typedef struct
{
    kal_wchar *email;               /* Email Address */
    vcard_email_type_enum type;     /* Email Type */
    kal_bool is_preferred;          /* Preferred Email or not */
} vcard_email_struct;

/* Title */
typedef struct
{
    kal_wchar *title;               /* Job Title */
} vcard_title_struct;

/* Organization Name and Organizational Unit */
typedef struct
{
    kal_wchar *name;                /* Organization Name */
    kal_wchar *unit;                /* Organizational Unit */
} vcard_org_struct;

/* Category */
typedef struct
{
    kal_wchar *name;                /* Category Name */
} vcard_category_struct;

/* Comment */
typedef struct
{
    kal_wchar *note;                /* Note */
} vcard_note_struct;

/* Uniform Resource Locator */
typedef struct
{
    kal_wchar *url;                 /* URL */
} vcard_url_struct;

typedef struct
{
	kal_wchar uid[VCARD_MAX_UID_LENGTH + 1];
}vcard_uid_struct;
/* PBAP Call Type */
typedef enum
{
    VCARD_X_CALL_TYPE_DEFAULT = 0x00,
    VCARD_X_CALL_TYPE_DIALED = 0x01,
    VCARD_X_CALL_TYPE_MISSED = 0x02,
    VCARD_X_CALL_TYPE_RECEIVED = 0x04
} vcard_x_call_type_enum;

/* PBAP Call Time */
typedef struct
{
    kal_uint16 year;                /* Year */
    kal_uint8 month;                /* Month */
    kal_uint8 day;                  /* Day */
    kal_uint8 hour;                 /* Hour */
    kal_uint8 min;                  /* Minute */
    kal_uint8 sec;                  /* Second */
    kal_uint8 week;                 /* 0=Sunday */
} vcard_x_call_time_struct;

/* Extensions */
typedef struct
{
    vcard_x_call_type_enum call_type;
    vcard_x_call_time_struct call_time;
} vcard_x_struct;

/* vCard Object */
typedef struct
{
    vcard_n_struct n;                                   /* Name */
    vcard_nickname_struct nickname;                     /* Nick Name */
    vcard_photo_struct photo;                           /* Photograph */
    vcard_bday_struct bday;                             /* Birthdate */
    vcard_adr_struct adr[VCARD_MAX_ADR_COUNT];          /* Delivery Address */
    vcard_tel_struct tel[VCARD_MAX_TEL_COUNT];          /* Telephone Number */
    vcard_email_struct email[VCARD_MAX_EMAIL_COUNT];    /* Electronic Mail */
    vcard_title_struct title;                           /* Title */
    vcard_org_struct org;                               /* Organization Name and Organizational Unit */
    vcard_category_struct category;                     /* Category */
    vcard_note_struct note;                             /* Comment */
    vcard_url_struct url[VCARD_MAX_URL_COUNT];          /* Uniform Resource Locator */
    vcard_x_struct x;                                   /* Extensions */
	vcard_uid_struct uid;
} vcard_object_struct;

typedef void *VP_HANDLE;    /* vCard parser handle */

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  vcard_parser_callback_type
 * DESCRIPTION
 *  Definition of vCard parser callback
 * PARAMETERS
 *  error_code:         [IN]        vCard error code
 *  percentage:         [IN]        vCard parse percentage in progress
 *  object:             [IN]        vCard object allocated by vCard parser
 *  user_data:          [IN]        vCard user data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*vcard_parser_callback_type) (
                kal_int32 error_code,
                kal_uint16 percentage,
                vcard_object_struct *object,
                void *user_data);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  vcard_parser_callback_ex_type
 * DESCRIPTION
 *  Definition of vCard parser callback ex
 * PARAMETERS
 *  error_code:         [IN]        vCard error code
 *  object_count:       [IN]        vCard object count
 *  object_offset:      [IN]        vCard object offset to the file
 *  user_data:          [IN]        vCard user data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*vcard_parser_callback_ex_type) (
                kal_int32 error_code,
                kal_int32 object_count,
                kal_int32 *object_offset,
                void *user_data);

typedef void *VB_HANDLE;    /* vCard builder handle */

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  vcard_builder_callback_type
 * DESCRIPTION
 *  Definition of vCard builder callback
 * PARAMETERS
 *  error_code:         [IN]        vCard error code
 *  user_data:          [IN]        vCard user data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*vcard_builder_callback_type) (kal_int32 error_code, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  vcard_is_busying
 * DESCRIPTION
 *  This function is used to judge if vCard is busy parsing or building.
 * PARAMETERS
 *  handle:             [IN]        vCard parser or builder handle
 * RETURN VALUES
 *  KAL_TRUE:           Busy status
 *  KAL_FALSE:          Idle status
 *****************************************************************************/
extern kal_bool vcard_is_busying(void *handle);

/*****************************************************************************
 * FUNCTION
 *  vcard_open_parser
 * DESCRIPTION
 *  This function is used to open file and create vCard parser handle.
 * PARAMETERS
 *  file_name:          [IN]        vCard file name
 *  property:           [IN]        vCard property
 *  error_code:         [OUT]       vCard error code
 * RETURNS
 *  vCard parser handle
 *****************************************************************************/
extern VP_HANDLE vcard_open_parser(kal_wchar *file_name, vcard_property_enum property, kal_int32 *error_code);

/*****************************************************************************
 * FUNCTION
 *  vcard_set_parse_charset
 * DESCRIPTION
 *  This function is used to set vCard default charset.
 * PARAMETERS
 *  vp:                 [IN]        vCard parser handle
 *  default_charset:    [IN]        vCard default charset
 * RETURNS
 *  void
 *****************************************************************************/
extern void vcard_set_parse_charset(VP_HANDLE vp, mmi_chset_enum default_charset);

/*****************************************************************************
 * FUNCTION
 *  vcard_set_parse_mode
 * DESCRIPTION
 *  This function is used to set vCard parse mode.
 * PARAMETERS
 *  vp:                 [IN]        vCard parser handle
 *  mode:               [IN]        vCard parse mode
 * RETURNS
 *  void
 *****************************************************************************/
extern void vcard_set_parse_mode(VP_HANDLE vp, vcard_parse_mode_enum mode);

/*****************************************************************************
 * FUNCTION
 *  vcard_parse
 * DESCRIPTION
 *  This function is used to parse vCard (first object).
 * PARAMETERS
 *  vp:                 [IN]        vCard parser handle
 *  object:             [OUT]       vCard object allocated by vCard parser
 * RETURN VALUES
 *  VCARD_RESULT_FAIL:  Fail to parse vCard
 *  VCARD_RESULT_OK:    Successful
 *  VCARD_RESULT_MORE:  Successful, and more objects available
 *****************************************************************************/
extern kal_int32 vcard_parse(VP_HANDLE vp, vcard_object_struct **object);

#ifdef __MULTI_VCARD_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  vcard_multi_parse
 * DESCRIPTION
 *  This function is used to parse vCard one by one.
 *  NOTE: It is always an async. function. vp_callback can't be set as NULL.
 * PARAMETERS
 *  vp:                 [IN]        vCard parser handle
 *  vp_callback:        [IN]        vCard parser callback, app. will be notified after parsing one object
 *  user_data:          [IN]        vCard user data
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void vcard_multi_parse(VP_HANDLE vp, vcard_parser_callback_type vp_callback, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  vcard_multi_parse_ex
 * DESCRIPTION
 *  This function is used to parse vCard to get object count and offset to the file.
 *  NOTE: It is always an async. function. vp_callback_ex can't be set as NULL.
 * PARAMETERS
 *  vp:                 [IN]        vCard parser handle
 *  app_buffer:         [IN]        vCard app buffer
 *  app_buffer_size:    [IN]        vCard app buffer size in 4-bytes
 *  vp_callback_ex:     [IN]        vCard parser callback ex, app. will be notified after parsing all objects
 *  user_data:          [IN]        vCard user data
 * RETURNS
 *  void
 *****************************************************************************/
extern void vcard_multi_parse_ex(VP_HANDLE vp, kal_int32 *app_buffer, kal_int32 app_buffer_size, vcard_parser_callback_ex_type vp_callback_ex, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  vcard_multi_preview
 * DESCRIPTION
 *  This function is used to preview vCard.
 * PARAMETERS
 *  vp:                 [IN]        vCard parser handle
 *  object:             [OUT]       vCard object allocated by vCard parser
 *  object_offset:      [IN]        vCard object offset
 * RETURN VALUES
 *  VCARD_RESULT_FAIL:  Fail to preview vCard
 *  VCARD_RESULT_OK:    Successful
 *  VCARD_RESULT_MORE:  Successful, and more objects available
 *****************************************************************************/
extern kal_int32 vcard_multi_preview(VP_HANDLE vp, vcard_object_struct **object, kal_int32 object_offset);

#endif /* __MULTI_VCARD_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  vcard_get_parse_version
 * DESCRIPTION
 *  This function is used to get vCard version.
 * PARAMETERS
 *  vp:                 [IN]        vCard parser handle
 * RETURN VALUES
 *  VCARD_VERSION_2_1:  vCard 2.1
 *  VCARD_VERSION_3_0:  vCard 3.0
 *****************************************************************************/
extern vcard_version_enum vcard_get_parse_version(VP_HANDLE vp);

/*****************************************************************************
 * FUNCTION
 *  vcard_get_parse_error
 * DESCRIPTION
 *  This function is used to get vCard parse error.
 * PARAMETERS
 *  vp:                 [IN]        vCard parser handle
 * RETURNS
 *  vCard parse error
 *****************************************************************************/
extern kal_int32 vcard_get_parse_error(VP_HANDLE vp);

/*****************************************************************************
 * FUNCTION
 *  vcard_cancel_parse
 * DESCRIPTION
 *  This function is used to cancel parsing.
 *  NOTE: It is always an async. function. vp_callback can't be set as NULL.
 * PARAMETERS
 *  vp:                 [IN]        vCard parser handle
 *  vp_callback:        [IN]        vCard parser callback, app. will be notified after parsing cancelled
 * RETURNS
 *  void
 *****************************************************************************/
extern void vcard_cancel_parse(VP_HANDLE vp, vcard_parser_callback_type vp_callback);

/*****************************************************************************
 * FUNCTION
 *  vcard_close_parser
 * DESCRIPTION
 *  This function is used to close file and destroy vCard parser handle.
 * PARAMETERS
 *  vp:                 [IN]        vCard parser handle
 * RETURNS
 *  void
 *****************************************************************************/
extern void vcard_close_parser(VP_HANDLE vp);

/*****************************************************************************
 * FUNCTION
 *  vcard_open_builder
 * DESCRIPTION
 *  This function is used to open file and create vCard builder handle.
 * PARAMETERS
 *  file_name:          [IN]        vCard file name
 *  mode:               [IN]        vCard file open mode
 *  error_code:         [OUT]       vCard error code
 * RETURNS
 *  vCard builder handle
 *****************************************************************************/
extern VB_HANDLE vcard_open_builder(kal_wchar *file_name, vcard_open_mode_enum mode, kal_int32 *error_code);

/*****************************************************************************
 * FUNCTION
 *  vcard_set_build_version
 * DESCRIPTION
 *  This function is used to set vCard version.
 * PARAMETERS
 *  vb:                 [IN]        vCard builder handle
 *  version:            [IN]        vCard version
 * RETURNS
 *  void
 *****************************************************************************/
extern void vcard_set_build_version(VB_HANDLE vb, vcard_version_enum version);

/*****************************************************************************
 * FUNCTION
 *  vcard_set_build_mode
 * DESCRIPTION
 *  This function is used to set vCard build mode.
 * PARAMETERS
 *  vb:                 [IN]        vCard builder handle
 *  mode:               [IN]        vCard build mode
 * RETURNS
 *  void
 *****************************************************************************/
extern void vcard_set_build_mode(VB_HANDLE vb, vcard_build_mode_enum mode);

/*****************************************************************************
 * FUNCTION
 *  vcard_build
 * DESCRIPTION
 *  This function is used to build vCard.
 * PARAMETERS
 *  vb:                 [IN]        vCard builder handle
 *  object:             [IN]        vCard object allocated by app.
 * RETURN VALUES
 *  VCARD_RESULT_FAIL:  Fail to build vCard
 *  VCARD_RESULT_OK:    Successful
 *****************************************************************************/
extern kal_int32 vcard_build(VB_HANDLE vb, vcard_object_struct *object);

#ifdef __MULTI_VCARD_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  vcard_multi_build
 * DESCRIPTION
 *  This function is used to build vCard one by one.
 *  NOTE: It is always an async. function. vb_callback can't be set as NULL.
 * PARAMETERS
 *  vb:                 [IN]        vCard builder handle
 *  object:             [IN]        vCard object allocated by app.
 *  vb_callback:        [IN]        vCard builder callback, app. will be notified after building one object
 *  user_data:          [IN]        vCard user data
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void vcard_multi_build(VB_HANDLE vb, vcard_object_struct *object, vcard_builder_callback_type vb_callback, void *user_data);

#endif /* __MULTI_VCARD_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  vcard_get_build_error
 * DESCRIPTION
 *  This function is used to get vCard build error.
 * PARAMETERS
 *  vb:                 [IN]        vCard builder handle
 * RETURNS
 *  vCard build error
 *****************************************************************************/
extern kal_int32 vcard_get_build_error(VB_HANDLE vb);

/*****************************************************************************
 * FUNCTION
 *  vcard_cancel_build
 * DESCRIPTION
 *  This function is used to cancel building.
 *  NOTE: It is always an async. function. vb_callback can't be set as NULL.
 * PARAMETERS
 *  vb:                 [IN]        vCard builder handle
 *  vb_callback:        [IN]        vCard builder callback, app. will be notified after building cancelled
 * RETURNS
 *  void
 *****************************************************************************/
extern void vcard_cancel_build(VB_HANDLE vb, vcard_builder_callback_type vb_callback);

/*****************************************************************************
 * FUNCTION
 *  vcard_close_builder
 * DESCRIPTION
 *  This function is used to close file and destroy vCard builder handle.
 * PARAMETERS
 *  vb:                 [IN]        vCard builder handle
 * RETURNS
 *  void
 *****************************************************************************/
extern void vcard_close_builder(VB_HANDLE vb);

#ifdef __cplusplus
}
#endif

#endif /* __VCARD_SUPPORT__ */

#endif /* VCARD_LIB_H */

