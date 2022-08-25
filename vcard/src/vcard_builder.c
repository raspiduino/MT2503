#ifdef __VCARD_SUPPORT__

#include "MMI_features.h"
#include "GDI_features.h"

#include "stdio.h"
#include "kal_general_types.h"
#include "fs_type.h"
#include "fs_func.h"
#include "kal_public_api.h"

#include "vcard_lib.h"
#include "vcard_utility.h"
#include "vcard_builder.h"

static const kal_char VCARD_QP_TABLE[] = "0123456789ABCDEF";

static const kal_char VCARD_BASE64_TABLE[] = 
{
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};

void vcard_add_to_write_buffer(vcard_builder_struct *builder, kal_char *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (data[i])
    {
        if (builder->write_length == VCARD_MAX_WRITE_LENGTH)
        {
            FS_Write(builder->source, builder->write_buffer, builder->write_length, (kal_uint32*) &len);
            builder->write_length = 0;
        }

        builder->write_buffer[builder->write_length] = data[i++];
        builder->write_length++;
    }
}

kal_int32 vcard_flush_write_buffer(vcard_builder_struct *builder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 len;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = FS_Write(builder->source, builder->write_buffer, builder->write_length, (kal_uint32*) &len);
    if (result < 0)
    {
        return result;
    }

    builder->write_length = 0;

    return VCARD_NO_ERROR;
}

void vcard_encode_base64(vcard_builder_struct *builder, kal_char *buffer, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_int32 j = 0;
    kal_uint8 data[3];
    kal_int32 data_len = 0;
    kal_uint8 encode[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len; i++)
    {
        if (data_len < 3)
        {
            data[data_len] = buffer[i];
            data_len++;
        }

        if (data_len < 3)
        {
            continue;
        }

        encode[0] = VCARD_BASE64_TABLE[data[0] >> 2];
        encode[1] = VCARD_BASE64_TABLE[((data[0] << 4) + (data[1] >> 4)) & 0x3F];
        encode[2] = VCARD_BASE64_TABLE[((data[1] << 2) + (data[2] >> 6)) & 0x3F];
        encode[3] = VCARD_BASE64_TABLE[data[2] & 0x3F];
        encode[4] = '\0';

        if (j == 0)
        {
            vcard_add_to_write_buffer(builder, "\r\n ");
            j++;
        }

        if (j >= VCARD_MAX_LIMIT_QT_LINE)
        {
            vcard_add_to_write_buffer(builder, "\r\n ");
            vcard_add_to_write_buffer(builder, (kal_char*) encode);
            j = 5;
        }
        else
        {
            vcard_add_to_write_buffer(builder, (kal_char*) encode);
            j += 4;
        }

        data_len = 0;
    }

    if (data_len == 0)
    {
        if (len > 0)
        {
            return;
        }

        vcard_add_to_write_buffer(builder, "\r\n\r\n");
        return;
    }
    else if (data_len == 1)
    {
        encode[0] = VCARD_BASE64_TABLE[data[0] >> 2];
        encode[1] = VCARD_BASE64_TABLE[(data[0] << 4) & 0x3F];
        encode[2] = '=';
        encode[3] = '=';
        encode[4] = '\0';
    }
    else if (data_len == 2)
    {
        encode[0] = VCARD_BASE64_TABLE[data[0] >> 2];
        encode[1] = VCARD_BASE64_TABLE[((data[0] << 4) + (data[1] >> 4)) & 0x3F];
        encode[2] = VCARD_BASE64_TABLE[(data[1] << 2) & 0x3F];
        encode[3] = '=';
        encode[4] = '\0';
    }

    if (j == 0)
    {
        vcard_add_to_write_buffer(builder, "\r\n ");
    }

    if (j >= VCARD_MAX_LIMIT_QT_LINE)
    {
        vcard_add_to_write_buffer(builder, "\r\n ");
        vcard_add_to_write_buffer(builder, (kal_char*) encode);
    }
    else
    {
        vcard_add_to_write_buffer(builder, (kal_char*) encode);
    }
}

void vcard_encode_qp(vcard_builder_struct *builder, kal_char *field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0;
    kal_int32 j = 0;
    kal_uint8 encode[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (field[i])
    {
        if (field[i] >= '!' && field[i] <= '~' && field[i] != '=')
        {
            sprintf((kal_char*) encode, "%c", field[i++]);
            j++;
        }
        else
        {
            encode[0] = '=';
            encode[1] = VCARD_QP_TABLE[(field[i] & 0xF0) >> 4];
            encode[2] = VCARD_QP_TABLE[field[i++] & 0x0F];
            encode[3] = '\0';
            j += 3;
        }

        vcard_add_to_write_buffer(builder, (kal_char*) encode);

        if (j >= VCARD_MAX_LIMIT_QT_LINE)
        {
            vcard_add_to_write_buffer(builder, "=\r\n");
            j = 0;
        }
    }
}

void vcard_encode_photo(vcard_builder_struct *builder, FS_HANDLE photo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char buffer[270];
    kal_int32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (builder->version == VCARD_VERSION_3_0)
	{
		vcard_add_to_write_buffer(builder, "PHOTO;ENCODING=b;TYPE=");
	}
	else
	{
		vcard_add_to_write_buffer(builder, "PHOTO;ENCODING=BASE64;TYPE=");
	}
	
    switch (builder->object->photo.type)
    {
    
    #if defined(__GDI_MEMORY_PROFILE_2__)
        case VCARD_PHOTO_TYPE_JPG:
            vcard_add_to_write_buffer(builder, "JPG:");
            break;

        case VCARD_PHOTO_TYPE_JPEG:
            vcard_add_to_write_buffer(builder, "JPEG:");
            break;
    #endif /* defined(__GDI_MEMORY_PROFILE_2__) */

        case VCARD_PHOTO_TYPE_GIF:
            vcard_add_to_write_buffer(builder, "GIF:");
            break;

        case VCARD_PHOTO_TYPE_BMP:
            vcard_add_to_write_buffer(builder, "BMP:");
            break;

        case VCARD_PHOTO_TYPE_WBMP:
            vcard_add_to_write_buffer(builder, "WBMP:");
            break;

        case VCARD_PHOTO_TYPE_WBM:
            vcard_add_to_write_buffer(builder, "WBM:");
            break;

    #if defined(GDI_USING_PNG)
        case VCARD_PHOTO_TYPE_PNG:
            vcard_add_to_write_buffer(builder, "PNG:");
            break;
    #endif /* defined(GDI_USING_PNG) */

    #if defined(GDI_USING_M3D)
        case VCARD_PHOTO_TYPE_M3D:
            vcard_add_to_write_buffer(builder, "M3D:");
            break;
    #endif /* defined(GDI_USING_M3D) */

    #ifdef SVG12_SUPPORT
        case VCARD_PHOTO_TYPE_SVG:
            vcard_add_to_write_buffer(builder, "SVG:");
            break;
    #endif /* SVG12_SUPPORT */

        default:
            return;
    }

    do
    {
        FS_Read(photo, buffer, 270, (kal_uint32*) &len);
        if (len <= 0)
        {
            vcard_encode_base64(builder, "", 0);
            return;
        }

        vcard_encode_base64(builder, buffer, len);
    } while (1);
}

void vcard_set_field(vcard_builder_struct *builder, kal_wchar *field, kal_bool qp_encoding, kal_char *delimiter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (field && field[0])
    {
        vcard_convert_to_utf8(field, builder->field);

        if (!qp_encoding)
        {
            vcard_add_to_write_buffer(builder, builder->field);
        }
        else if (builder->version == VCARD_VERSION_3_0)
        {
            vcard_add_to_write_buffer(builder, builder->field);
        }
        else
        {
            vcard_add_to_write_buffer(builder, "=\r\n");
            vcard_encode_qp(builder, builder->field);
        }

        vcard_add_to_write_buffer(builder, delimiter);
    }
    else
    {
        vcard_add_to_write_buffer(builder, delimiter);
    }
}

void vcard_set_fn(vcard_builder_struct *builder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcard_add_to_write_buffer(builder, "FN;CHARSET=UTF-8:");

    if (builder->object->n.given && builder->object->n.given[0])
    {
        if (builder->object->n.family && builder->object->n.family[0])
        {
            vcard_set_field(builder, builder->object->n.given, KAL_FALSE, " ");
        }
        else
        {
            vcard_set_field(builder, builder->object->n.given, KAL_FALSE, "");
        }
    }

    vcard_set_field(builder, builder->object->n.family, KAL_FALSE, "\r\n");
}

void vcard_set_n(vcard_builder_struct *builder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (builder->version == VCARD_VERSION_3_0)
    {
        vcard_add_to_write_buffer(builder, "N;CHARSET=UTF-8:");
    }
    else
    {
        vcard_add_to_write_buffer(builder, "N;ENCODING=QUOTED-PRINTABLE;CHARSET=UTF-8:");
    }

    vcard_set_field(builder, builder->object->n.family, KAL_TRUE, ";");
    vcard_set_field(builder, builder->object->n.given, KAL_TRUE, ";");
    vcard_set_field(builder, builder->object->n.mid, KAL_TRUE, ";");
    vcard_set_field(builder, builder->object->n.prefix, KAL_TRUE, ";");
    vcard_set_field(builder, builder->object->n.suffix, KAL_TRUE, "\r\n");
}

void vcard_set_nickname(vcard_builder_struct *builder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (builder->version == VCARD_VERSION_3_0)
    {
        vcard_add_to_write_buffer(builder, "NICKNAME;CHARSET=UTF-8:");
    }
    else
    {
        vcard_add_to_write_buffer(builder, "X-NICKNAME;ENCODING=QUOTED-PRINTABLE;CHARSET=UTF-8:");
    }

    vcard_set_field(builder, builder->object->nickname.name, KAL_TRUE, "\r\n");
}

void vcard_set_bday(vcard_builder_struct *builder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char bday[20] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (builder->version == VCARD_VERSION_3_0)
	{
	    sprintf(
        	bday,
        	"BDAY:%04d-%02d-%02d\r\n",
        	builder->object->bday.year,
        	builder->object->bday.month,
        	builder->object->bday.day);
		vcard_add_to_write_buffer(builder, bday);	
	}
	else
	{
        sprintf(
            bday,
            "BDAY:%04d%02d%02d\r\n",
            builder->object->bday.year,
            builder->object->bday.month,
            builder->object->bday.day);
		    vcard_add_to_write_buffer(builder, bday);
	}

}

void vcard_set_adr(vcard_builder_struct *builder, vcard_adr_struct adr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (builder->version == VCARD_VERSION_3_0)
    {
        vcard_add_to_write_buffer(builder, "ADR;CHARSET=UTF-8:");
    }
    else
    {
        vcard_add_to_write_buffer(builder, "ADR;ENCODING=QUOTED-PRINTABLE;CHARSET=UTF-8:");
    }

    vcard_set_field(builder, adr.post_office, KAL_TRUE, ";");
    vcard_set_field(builder, adr.extended, KAL_TRUE, ";");
    vcard_set_field(builder, adr.street, KAL_TRUE, ";");
    vcard_set_field(builder, adr.locality, KAL_TRUE, ";");
    vcard_set_field(builder, adr.region, KAL_TRUE, ";");
    vcard_set_field(builder, adr.postal_code, KAL_TRUE, ";");
    vcard_set_field(builder, adr.country, KAL_TRUE, "\r\n");
}

void vcard_set_property(vcard_builder_struct *builder, kal_char *property, kal_char *param, kal_bool is_preferred)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcard_add_to_write_buffer(builder, property);

    if (builder->version == VCARD_VERSION_3_0)
    {
        if (is_preferred)
        {
            vcard_add_to_write_buffer(builder, ";TYPE=PREF,");
        }
        else
        {
            vcard_add_to_write_buffer(builder, ";TYPE=");
        }

        if (param && param[0])
        {
            vcard_add_to_write_buffer(builder, param);
            vcard_add_to_write_buffer(builder, ",");
        }
    }
    else
    {
        if (is_preferred)
        {
            vcard_add_to_write_buffer(builder, ";PREF;");
        }
        else
        {
            vcard_add_to_write_buffer(builder, ";");
        }

        if (param && param[0])
        {
            vcard_add_to_write_buffer(builder, param);
            vcard_add_to_write_buffer(builder, ";");
        }
    }
}

void vcard_set_tel(vcard_builder_struct *builder, vcard_tel_struct tel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (tel.type)
    {
    case VCARD_TEL_TYPE_VOICE:
        vcard_set_property(builder, "TEL", "", tel.is_preferred);
        vcard_add_to_write_buffer(builder, "VOICE:");
        break;

    case VCARD_TEL_TYPE_CELL:
        vcard_set_property(builder, "TEL", "VOICE", tel.is_preferred);
        vcard_add_to_write_buffer(builder, "CELL:");
        break;

    case VCARD_TEL_TYPE_HOME:
        vcard_set_property(builder, "TEL", "VOICE", tel.is_preferred);
        vcard_add_to_write_buffer(builder, "HOME:");
        break;

    case VCARD_TEL_TYPE_WORK:
        vcard_set_property(builder, "TEL", "VOICE", tel.is_preferred);
        vcard_add_to_write_buffer(builder, "WORK:");
        break;

    case VCARD_TEL_TYPE_FAX:
        vcard_set_property(builder, "TEL", "", tel.is_preferred);
        vcard_add_to_write_buffer(builder, "FAX:");
        break;

    default:
        return;
    }

    vcard_set_field(builder, tel.tel, KAL_FALSE, "\r\n");
}

void vcard_set_email(vcard_builder_struct *builder, vcard_email_struct email)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (email.type)
    {
    case VCARD_EMAIL_TYPE_INTERNET:
        vcard_set_property(builder, "EMAIL", "", email.is_preferred);
        vcard_add_to_write_buffer(builder, "INTERNET:");
        break;

    case VCARD_EMAIL_TYPE_HOME:
        vcard_set_property(builder, "EMAIL", "INTERNET", email.is_preferred);
        vcard_add_to_write_buffer(builder, "HOME:");
        break;

    case VCARD_EMAIL_TYPE_WORK:
        vcard_set_property(builder, "EMAIL", "INTERNET", email.is_preferred);
        vcard_add_to_write_buffer(builder, "WORK:");
        break;

    default:
        return;
    }

    vcard_set_field(builder, email.email, KAL_FALSE, "\r\n");
}

void vcard_set_title(vcard_builder_struct *builder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (builder->version == VCARD_VERSION_3_0)
    {
        vcard_add_to_write_buffer(builder, "TITLE;CHARSET=UTF-8:");
    }
    else
    {
        vcard_add_to_write_buffer(builder, "TITLE;ENCODING=QUOTED-PRINTABLE;CHARSET=UTF-8:");
    }

    vcard_set_field(builder, builder->object->title.title, KAL_TRUE, "\r\n");
}

void vcard_set_org(vcard_builder_struct *builder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (builder->version == VCARD_VERSION_3_0)
    {
        vcard_add_to_write_buffer(builder, "ORG;CHARSET=UTF-8:");
    }
    else
    {
        vcard_add_to_write_buffer(builder, "ORG;ENCODING=QUOTED-PRINTABLE;CHARSET=UTF-8:");
    }

    vcard_set_field(builder, builder->object->org.name, KAL_TRUE, ";");
    vcard_set_field(builder, builder->object->org.unit, KAL_TRUE, "\r\n");
}

void vcard_set_category(vcard_builder_struct *builder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (builder->version == VCARD_VERSION_3_0)
    {
        vcard_add_to_write_buffer(builder, "CATEGORIES;CHARSET=UTF-8:");
    }
    else
    {
        vcard_add_to_write_buffer(builder, "X-CATEGORIES;ENCODING=QUOTED-PRINTABLE;CHARSET=UTF-8:");
    }

    vcard_set_field(builder, builder->object->category.name, KAL_TRUE, "\r\n");
}

void vcard_set_note(vcard_builder_struct *builder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (builder->version == VCARD_VERSION_3_0)
    {
        vcard_add_to_write_buffer(builder, "NOTE;CHARSET=UTF-8:");
    }
    else
    {
        vcard_add_to_write_buffer(builder, "NOTE;ENCODING=QUOTED-PRINTABLE;CHARSET=UTF-8:");
    }

    vcard_set_field(builder, builder->object->note.note, KAL_TRUE, "\r\n");
}

void vcard_set_url(vcard_builder_struct *builder, vcard_url_struct url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (builder->version == VCARD_VERSION_3_0)
    {
        vcard_add_to_write_buffer(builder, "URL;CHARSET=UTF-8:");
    }
    else
    {
        vcard_add_to_write_buffer(builder, "URL;ENCODING=QUOTED-PRINTABLE;CHARSET=UTF-8:");
    }

    vcard_set_field(builder, url.url, KAL_TRUE, "\r\n");
}

void vcard_set_x(vcard_builder_struct *builder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char call_time[25];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (builder->object->x.call_type)
    {
        case VCARD_X_CALL_TYPE_DIALED:
            vcard_add_to_write_buffer(builder, "X-IRMC-CALL-DATETIME;DIALED:");
            break;

        case VCARD_X_CALL_TYPE_MISSED:
            vcard_add_to_write_buffer(builder, "X-IRMC-CALL-DATETIME;MISSED:");
            break;

        case VCARD_X_CALL_TYPE_RECEIVED:
            vcard_add_to_write_buffer(builder, "X-IRMC-CALL-DATETIME;RECEIVED:");
            break;

        default:
            return;
    }

    sprintf(
        call_time,
        "%04d%02d%02dT%02d%02d%02d\r\n",
        builder->object->x.call_time.year,
        builder->object->x.call_time.month,
        builder->object->x.call_time.day,
        builder->object->x.call_time.hour,
        builder->object->x.call_time.min,
        builder->object->x.call_time.sec);

    vcard_add_to_write_buffer(builder, call_time);
}

void vcard_set_uid(vcard_builder_struct *builder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	vcard_add_to_write_buffer(builder, "UID:");
	vcard_set_field(builder, builder->object->uid.uid, KAL_FALSE, "\r\n");
}

vcard_builder_struct *vcard_malloc_builder(FS_HANDLE source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_builder_struct *builder = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    builder = (vcard_builder_struct*) get_ctrl_buffer(sizeof(vcard_builder_struct));
    if (!vcard_add_instance(builder))
    {
        FS_Close(source);
        free_ctrl_buffer(builder);
        return NULL;
    }

    builder->source = source;
    builder->version = VCARD_VERSION_2_1;
    builder->mode = VCARD_BUILD_MODE_DEFAULT;
    builder->error_code = VCARD_NO_ERROR;
    builder->cancel = KAL_FALSE;

    builder->write_buffer = (kal_char*) get_ctrl_buffer(VCARD_MAX_WRITE_LENGTH);
    builder->write_length = -1;

    return builder;
}

kal_int32 vcard_build_object(vcard_builder_struct *builder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE photo = -1;
    kal_int32 i;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcard_add_to_write_buffer(builder, "BEGIN:VCARD\r\n");

    if (builder->version == VCARD_VERSION_3_0)
    {
        vcard_add_to_write_buffer(builder, "VERSION:3.0\r\n");
    }
    else
    {
        vcard_add_to_write_buffer(builder, "VERSION:2.1\r\n");
    }

    vcard_set_n(builder);

    if (builder->version == VCARD_VERSION_3_0)
    {
        vcard_set_fn(builder);
    }

    if (builder->object->nickname.name && builder->object->nickname.name[0])
    {
        vcard_set_nickname(builder);
    }

	if (builder->object->uid.uid && builder->object->uid.uid[0])
	{
		vcard_set_uid(builder);
	}

    if ((builder->object->org.name && builder->object->org.name[0]) ||
        (builder->object->org.unit && builder->object->org.unit[0]))
    {
        vcard_set_org(builder);
    }

    if (builder->object->title.title && builder->object->title.title[0])
    {
        vcard_set_title(builder);
    }

    if (builder->object->note.note && builder->object->note.note[0])
    {
        vcard_set_note(builder);
    }

    for (i = 0; i < VCARD_MAX_TEL_COUNT; i++)
    {
        if ((builder->mode & VCARD_BUILD_MODE_TEL_ALWAYS) ||
            (builder->object->tel[i].tel && builder->object->tel[i].tel[0]))
        {
            vcard_set_tel(builder, builder->object->tel[i]);
        }
    }

    for (i = 0; i < VCARD_MAX_ADR_COUNT; i++)
    {
        if ((builder->object->adr[i].post_office && builder->object->adr[i].post_office[0]) ||
            (builder->object->adr[i].extended && builder->object->adr[i].extended[0]) ||
            (builder->object->adr[i].street && builder->object->adr[i].street[0]) ||
            (builder->object->adr[i].locality && builder->object->adr[i].locality[0]) ||
            (builder->object->adr[i].region && builder->object->adr[i].region[0]) ||
            (builder->object->adr[i].postal_code && builder->object->adr[i].postal_code[0]) ||
            (builder->object->adr[i].country && builder->object->adr[i].country[0]))
        {
            vcard_set_adr(builder, builder->object->adr[i]);
        }
    }

    for (i = 0; i < VCARD_MAX_URL_COUNT; i++)
    {
        if (builder->object->url[i].url && builder->object->url[i].url[0])
        {
            vcard_set_url(builder, builder->object->url[i]);
        }
    }

    if (builder->object->bday.year && builder->object->bday.month && builder->object->bday.day)
    {
        vcard_set_bday(builder);
    }

    for (i = 0; i < VCARD_MAX_EMAIL_COUNT; i++)
    {
        if (builder->object->email[i].email && builder->object->email[i].email[0])
        {
            vcard_set_email(builder, builder->object->email[i]);
        }
    }

    if (builder->object->photo.file_name[0])
    {
        photo = FS_Open(builder->object->photo.file_name, FS_READ_ONLY);
        if (photo > 0)
        {
            vcard_encode_photo(builder, photo);
            FS_Close(photo);
        }
    }

    if (builder->object->category.name && builder->object->category.name[0])
    {
        vcard_set_category(builder);
    }

    if (builder->object->x.call_time.year && builder->object->x.call_time.month &&
        builder->object->x.call_time.day && builder->object->x.call_time.hour &&
        builder->object->x.call_time.min && builder->object->x.call_time.sec)
    {
        vcard_set_x(builder);
    }

    vcard_add_to_write_buffer(builder, "END:VCARD\r\n");

    result = vcard_flush_write_buffer(builder);
    if (result < VCARD_NO_ERROR)
    {
        builder->error_code = result;
        return VCARD_RESULT_FAIL;
    }

    return VCARD_RESULT_OK;
}

kal_int32 vcard_build_next_object(vcard_builder_struct *builder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcard_add_to_write_buffer(builder, "\r\n");

    return vcard_build_object(builder);
}

void vcard_free_builder(vcard_builder_struct *builder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcard_remove_instance(builder);
    free_ctrl_buffer(builder->write_buffer);
    free_ctrl_buffer(builder);
}

#endif /* __VCARD_SUPPORT__ */

