#ifndef VCARD_BUILDER_H
#define VCARD_BUILDER_H

#ifdef __VCARD_SUPPORT__

#include "kal_general_types.h"
#include "fs_type.h"

#include "vcard_lib.h"
#include "vcard_utility.h"

typedef struct
{
    FS_HANDLE source;
    vcard_version_enum version;
    vcard_build_mode_enum mode;
    kal_int32 error_code;
    kal_bool cancel;

    vcard_object_struct *object;
    vcard_builder_callback_type vb_callback;
    void *user_data;

    kal_char field[VCARD_MAX_FIELD_LENGTH];
    kal_char *write_buffer;
    kal_int32 write_length;
} vcard_builder_struct;

vcard_builder_struct *vcard_malloc_builder(FS_HANDLE source);
kal_int32 vcard_build_object(vcard_builder_struct *builder);
kal_int32 vcard_build_next_object(vcard_builder_struct *builder);
void vcard_free_builder(vcard_builder_struct *builder);

#endif /* __VCARD_SUPPORT__ */

#endif /* VCARD_BUILDER_H */

