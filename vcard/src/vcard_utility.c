#ifdef __VCARD_SUPPORT__

#include "MMI_features.h"

#include "string.h"
#include "kal_general_types.h"
#include "fs_type.h"
#include "fs_func.h"
#include "conversions.h"
#include "stack_common.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "kal_public_api.h"

#include "vcard_utility.h"

static const kal_char *VCARD_NAME_TABLE[] = 
{
    "BEGIN",
    "FN",
    "N",
    "NICKNAME",
    "PHOTO",
    "BDAY",
    "ADR",
    "LABEL",
    "TEL",
    "EMAIL",
    "MAILER",
    "TZ",
    "GEO",
    "TITLE",
    "ROLE",
    "LOGO",
    "AGENT",
    "ORG",
    "CATEGORIES",
    "NOTE",
    "PRODID",
    "REV",
    "SORT-STRING",
    "SOUND",
    "URL",
    "UID",
    "VERSION",
    "CLASS",
    "KEY",
    "X-NICKNAME",
    "X-CATEGORIES",
    #if defined(__BT_PBAP_CLIENT__)
    "X-IRMC-CALL-DATETIME",
    #endif
    "END"
};

vcard_tag_enum vcard_get_tag(kal_char *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_tag_enum tag = VCARD_TAG_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (tag = VCARD_TAG_BEGIN; tag <= VCARD_TAG_END; tag++)
    {
        if (strcmp(name, VCARD_NAME_TABLE[tag]) == 0)
        {
            break;
        }
    }

    return tag;
}

void vcard_strupr(kal_char *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; name[i]; i++)
    {
        if (name[i] >= 'a' && name[i] <= 'z')
        {
            name[i] -= 32;
        }
    }
}

kal_bool vcard_check_tcard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_int32 drive;
	kal_wchar* path;
	FS_HANDLE fh;
	
	kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	path = get_ctrl_buffer((VCARD_MAX_PATH_LEN + 1) * sizeof(kal_wchar));

	drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
	if (drive > 0)
	{
		kal_wsprintf(path, "%c:\\~vCard.tmp", (kal_char) drive);
		fh = FS_Open(path, FS_CREATE_ALWAYS | FS_READ_WRITE);
		if (fh > 0)
		{
			FS_Close(fh);
			FS_Delete(path);
			result = KAL_TRUE;
		}
	}
	
	free_ctrl_buffer(path);
	return result;
}

void vcard_create_folder(kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 drive;
    FS_HANDLE folder;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (vcard_check_tcard())
	{
		drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);  	
	}
	else
	{
		drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_V_REMOVABLE);	
	}

    if (drive > 0)
    {
        kal_wsprintf(path, "%c:\\vCard\\", (kal_char) drive);
        folder = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
        if (folder > 0)
        {
            FS_Close(folder);
        }
        else
        {
            FS_CreateDir(path);
        }
    }
}

void vcard_convert_to_ucs2(kal_char *field_src, kal_wchar *field_dest, vcard_charset_enum charset, kal_int32 max_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_chset_enum default_charset = MMI_CHSET_ASCII;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (charset == VCARD_CHARSET_ASCII)
    {
        default_charset = MMI_CHSET_ASCII;
    }
#ifdef __MMI_CHSET_WESTERN_ISO__
    else if (charset == VCARD_CHARSET_8859_1)
    {
        default_charset = MMI_CHSET_WESTERN_ISO;
    }
#endif /* __MMI_CHSET_WESTERN_ISO__ */
#ifdef __MMI_CHSET_SJIS__
    else if (charset == VCARD_CHARSET_SHIFT_JIS)
    {
        default_charset = MMI_CHSET_SJIS;
    }
#endif /* __MMI_CHSET_SJIS__ */
    else if (charset == VCARD_CHARSET_UTF8)
    {
        default_charset = MMI_CHSET_UTF8;
    }
#ifdef __MMI_CHSET_BIG5__
    else if (charset == VCARD_CHARSET_BIG5)
    {
        default_charset = MMI_CHSET_BIG5;
    }
#endif /* __MMI_CHSET_BIG5__ */
#ifdef __MMI_CHSET_HKSCS__
    else if (charset == VCARD_CHARSET_HKSCS)
    {
        default_charset = MMI_CHSET_HKSCS;
    }
#endif /* __MMI_CHSET_HKSCS__ */
#ifdef __MMI_CHSET_GB2312__
    else if (charset == VCARD_CHARSET_GB2312)
    {
        default_charset = MMI_CHSET_GB2312;
    }
#endif /* __MMI_CHSET_GB2312__ */
#ifdef __MMI_CHSET_GB18030__
    else if (charset == VCARD_CHARSET_GB18030)
    {
        default_charset = MMI_CHSET_GB18030;
    }
#endif /* __MMI_CHSET_GB18030__ */
    else
    {
    #if defined(__MMI_CHSET_BIG5__)
        default_charset = MMI_CHSET_BIG5;
    #elif defined(__MMI_CHSET_HKSCS__)
        default_charset = MMI_CHSET_HKSCS;
    #elif defined(__MMI_CHSET_GB2312__)
        default_charset = MMI_CHSET_GB2312;
    #elif defined(__MMI_CHSET_GB18030__)
        default_charset = MMI_CHSET_GB18030;
    #elif defined(__MMI_CHSET_WESTERN_ISO__)
        default_charset = MMI_CHSET_WESTERN_ISO;
    #endif
    }

    mmi_chset_convert(
        default_charset,
        MMI_CHSET_UCS2,
        (char*) field_src,
        (char*) field_dest,
        (max_len + 1) * sizeof(kal_wchar));
}

void vcard_add_delimiter(kal_char *field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char new_field[VCARD_MAX_FIELD_LENGTH];
    kal_char *new_field_p = new_field;
    kal_char *field_p = field;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*field_p)
    {
        if (*field_p == '\\' || *field_p == ';')
        {
            *(new_field_p++) = '\\';
        }
        *(new_field_p++) = *(field_p++);
    }
    *new_field_p = 0;

    memcpy(field, new_field, VCARD_MAX_FIELD_LENGTH);
}

void vcard_convert_to_utf8(kal_wchar *field_src, kal_char *field_dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(
        MMI_CHSET_UCS2,
        MMI_CHSET_UTF8,
        (char*) field_src,
        (char*) field_dest,
        VCARD_MAX_FIELD_LENGTH);

    vcard_add_delimiter(field_dest);
}

#ifdef __MULTI_VCARD_SUPPORT__

void vcard_send_msg_to_udx(module_type src_id, msg_type msg_id, void *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	ilm_struct ilm;
    sap_type sap_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (src_id)
    {
        case MOD_MMI:
            sap_id = MMI_UDX_SAP;
            break;
        default:
            sap_id = INVALID_SAP;
            break;
    }

    ilm.src_mod_id = src_id;
    ilm.dest_mod_id = MOD_VCARD;
    ilm.sap_id = sap_id;
    ilm.msg_id = msg_id;
    ilm.local_para_ptr = (local_para_struct*) local_para_ptr;
    ilm.peer_buff_ptr = (peer_buff_struct*) NULL;

	msg_send(&ilm);
}

void vcard_send_msg_from_udx(module_type dest_id, msg_type msg_id, void *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    sap_type sap_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dest_id)
    {
        case MOD_MMI:
            sap_id = MMI_UDX_SAP;
            break;
        default:
            sap_id = INVALID_SAP;
            break;
    }

    ilm_ptr = allocate_ilm(MOD_VCARD);
    ilm_ptr->src_mod_id = MOD_VCARD;
    ilm_ptr->dest_mod_id = dest_id;
    ilm_ptr->sap_id = sap_id;
    ilm_ptr->msg_id = msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_para_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
}

#endif /* __MULTI_VCARD_SUPPORT__ */

#endif /* __VCARD_SUPPORT__ */

