#ifndef VCARD_PARSER_H
#define VCARD_PARSER_H

#ifdef __VCARD_SUPPORT__

#include "kal_general_types.h"
#include "fs_type.h"

#include "vcard_lib.h"
#include "vcard_utility.h"

#if defined(__BT_PBAP_CLIENT__)
#ifndef VCARD_FULL_N
#define VCARD_FULL_N
#endif
#endif


typedef struct
{
    FS_HANDLE source;
    vcard_property_enum property;
    vcard_charset_enum default_charset;
    vcard_parse_mode_enum mode;
    kal_int32 error_code;
    kal_uint16 percentage;
    kal_int32 file_size;
    kal_int32 process_char;
    kal_int32 sequence;
    kal_bool cancel;

    kal_int32 app_buffer_size;
    kal_int32 *app_buffer;
    kal_int32 object_count;
    vcard_object_struct *object;
    vcard_parser_callback_type vp_callback;
    vcard_parser_callback_ex_type vp_callback_ex;
    void *user_data;

    vcard_version_enum version;
    kal_int32 grouping;
    kal_int32 indent;
    FS_HANDLE photo;
    kal_int32 adr_count;
    kal_int32 tel_count;
    kal_int32 email_count;
    kal_int32 url_count;

    vcard_state_enum state;
    vcard_tag_enum tag;
    vcard_encoding_enum encoding;
    vcard_charset_enum charset;

    kal_char read_buffer[VCARD_MAX_READ_LENGTH];
    kal_int32 read_offset;
    kal_int32 read_length;

    kal_bool line_begin;
    kal_bool line_folding;
    kal_char *line_buffer;
    kal_int32 line_length;

    kal_int32 name_offset;
    kal_int32 param_offset;
    kal_int32 data_offset;

    kal_bool field_escape;
    kal_int32 field_offset[VCARD_MAX_FIELD_COUNT];
    kal_int32 field_length[VCARD_MAX_FIELD_COUNT];
    kal_int32 field_count;

    kal_uint8 decode_buffer[4];
    kal_int32 decode_length;
} vcard_parser_struct;

vcard_parser_struct *vcard_malloc_parser(FS_HANDLE source, vcard_property_enum property);
kal_int32 vcard_parse_object(vcard_parser_struct *parser, kal_int32 object_offset);
kal_int32 vcard_parse_next_object(vcard_parser_struct *parser);
void vcard_free_parser(vcard_parser_struct *parser);

#endif /* __VCARD_SUPPORT__ */

#endif /* VCARD_PARSER_H */

