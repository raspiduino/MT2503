#ifdef __VCARD_SUPPORT__

#include "MMI_features.h"
#include "GDI_features.h"

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#include "kal_general_types.h"
#include "fs_type.h"
#include "fs_func.h"
#include "app_str.h"
#include "app_datetime.h"
#include "kal_public_api.h"

#include "vcard_lib.h"
#include "vcard_utility.h"
#include "vcard_parser.h"

static const kal_uint8 VCARD_BASE64_DTABLE[] = 
{
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0x3E, 0xFF, 0xFF, 0xFF, 0x3F,
    0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B,
    0x3C, 0x3D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,

    0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
    0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E,
    0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16,
    0x17, 0x18, 0x19, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20,
    0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
    0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30,
    0x31, 0x32, 0x33, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,

    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,

    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

void vcard_init_line(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parser->state = VCARD_STATE_NAME;
    parser->tag = VCARD_TAG_UNKNOWN;
    parser->line_begin = KAL_FALSE;
    parser->line_folding = KAL_FALSE;
    parser->line_length = 0;
    parser->name_offset = 0;
    parser->param_offset = 0;
    parser->data_offset = 0;
    parser->field_escape = KAL_FALSE;

	if (parser->version == VCARD_VERSION_3_0)
	{
		parser->encoding = VCARD_ENCODING_8BIT;
    	parser->charset = VCARD_CHARSET_UTF8;
	}
	else
	{
		parser->encoding = VCARD_ENCODING_7BIT;
    	parser->charset = VCARD_CHARSET_ASCII;	
	}
	
    for (i = 0; i < VCARD_MAX_FIELD_COUNT; i++)
    {
        parser->field_length[i] = 0;
    }
    parser->field_count = 0;
    parser->decode_length = 0;
}

void vcard_init_object(vcard_parser_struct *parser, vcard_property_enum property)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (property & VCARD_PROPERTY_N)
    {
        parser->object->n.family[0] = 0;
        parser->object->n.given[0] = 0;
    #ifdef VCARD_FULL_N
        parser->object->n.mid[0] = 0;
        parser->object->n.prefix[0] = 0;
        parser->object->n.suffix[0] = 0;
    #endif /* VCARD_FULL_N */
        parser->object->n.name[0] = 0;
    }

    if (property & VCARD_PROPERTY_NICKNAME)
    {
        parser->object->nickname.name[0] = 0;
    }

    if (property & VCARD_PROPERTY_ADR)
    {
        for (i = 0; i < VCARD_MAX_ADR_COUNT; i++)
        {
            parser->object->adr[i].post_office[0] = 0;
            parser->object->adr[i].extended[0] = 0;
            parser->object->adr[i].street[0] = 0;
            parser->object->adr[i].locality[0] = 0;
            parser->object->adr[i].region[0] = 0;
            parser->object->adr[i].postal_code[0] = 0;
            parser->object->adr[i].country[0] = 0;
        }
    }

    if (property & VCARD_PROPERTY_TEL)
    {
        for (i = 0; i < VCARD_MAX_TEL_COUNT; i++)
        {
            parser->object->tel[i].tel[0] = 0;
        }
    }

    if (property & VCARD_PROPERTY_EMAIL)
    {
        for (i = 0; i < VCARD_MAX_EMAIL_COUNT; i++)
        {
            parser->object->email[i].email[0] = 0;
        }
    }

    if (property & VCARD_PROPERTY_TITLE)
    {
        parser->object->title.title[0] = 0;
    }

    if (property & VCARD_PROPERTY_ORG)
    {
        parser->object->org.name[0] = 0;
        parser->object->org.unit[0] = 0;
    }

    if (property & VCARD_PROPERTY_CATEGORY)
    {
        parser->object->category.name[0] = 0;
    }

    if (property & VCARD_PROPERTY_NOTE)
    {
        parser->object->note.note[0] = 0;
    }

    if (property & VCARD_PROPERTY_URL)
    {
        for (i = 0; i < VCARD_MAX_URL_COUNT; i++)
        {
            parser->object->url[i].url[0] = 0;
        }
    }
	#if defined(__BT_PBAP_CLIENT__)
	if (property & VCARD_PROPERTY_X)
	{
	    parser->object->x.call_type=VCARD_X_CALL_TYPE_DEFAULT;
	}
	#endif

    parser->object->photo.file_name[0] = 0;
    parser->object->bday.year = 0;
    parser->object->bday.month = 0;
    parser->object->bday.day = 0;
    parser->object->x.call_type = VCARD_X_CALL_TYPE_DEFAULT;

    parser->version = VCARD_VERSION_2_1;
    parser->grouping = 0;
    parser->indent = 0;
    parser->photo = -1;
    parser->adr_count = 0;
    parser->tel_count = 0;
    parser->email_count = 0;
    parser->url_count = 0;
}

void vcard_get_fn(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->field_count > 0 && parser->object->n.name)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[0],
            parser->object->n.name,
            parser->charset,
            VCARD_MAX_N_LENGTH);
    }
}

void vcard_get_n(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->field_count > 1 && parser->object->n.family)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[0],
            parser->object->n.family,
            parser->charset,
            VCARD_MAX_N_LENGTH);
    }

    if (parser->field_count > 1 && parser->object->n.given)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[1],
            parser->object->n.given,
            parser->charset,
            VCARD_MAX_N_LENGTH);
    }
    else if (parser->field_count > 0 && parser->object->n.given)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[0],
            parser->object->n.given,
            parser->charset,
            VCARD_MAX_N_LENGTH);
    }

#ifdef VCARD_FULL_N
    if (parser->field_count > 2 && parser->object->n.mid)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[2],
            parser->object->n.mid,
            parser->charset,
            VCARD_MAX_N_LENGTH);
    }

    if (parser->field_count > 3 && parser->object->n.prefix)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[3],
            parser->object->n.prefix,
            parser->charset,
            VCARD_MAX_N_LENGTH);
    }

    if (parser->field_count > 4 && parser->object->n.suffix)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[4],
            parser->object->n.suffix,
            parser->charset,
            VCARD_MAX_N_LENGTH);
    }
#endif /* VCARD_FULL_N */
}

void vcard_get_nickname(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->field_count > 0 && parser->object->nickname.name)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[0],
            parser->object->nickname.name,
            parser->charset,
            VCARD_MAX_NICKNAME_LENGTH);
    }
}

void vcard_get_bday(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *field = parser->line_buffer + parser->field_offset[0];
    kal_char bday[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->field_count > 0)
    {
        strncpy(bday, field, 4);
        bday[4] = '\0';
        parser->object->bday.year = (kal_uint16) atoi(bday);
        field += 4;
        if (*field == '-')
        {
            field++;
        }

        strncpy(bday, field, 2);
        bday[2] = '\0';
        parser->object->bday.month = (kal_uint8) atoi(bday);
        field += 2;
        if (*field == '-')
        {
            field++;
        }

        strncpy(bday, field, 2);
        bday[2] = '\0';
        parser->object->bday.day = (kal_uint8) atoi(bday);
    }
}

#if defined(__BT_PBAP_CLIENT__)

void vcard_get_x(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *field = parser->line_buffer + parser->field_offset[0];
    kal_char call_time[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    if (parser->field_count > 0)
    {
        strncpy(call_time, field, 4);
        call_time[4] = '\0';
        parser->object->x.call_time.year = (kal_uint16) atoi(call_time);
        field += 4;
        if (*field == '-')
        {
            field++;
        }

        strncpy(call_time, field, 2);
        call_time[2] = '\0';
        parser->object->x.call_time.month = (kal_uint8) atoi(call_time);
        field += 2;
        if (*field == '-')
        {
            field++;
        }

        strncpy(call_time, field, 2);
        call_time[2] = '\0';
        parser->object->x.call_time.day = (kal_uint8) atoi(call_time);
		field += 2;
        if (*field == 'T')
        {
            field++;
        }

		strncpy(call_time, field, 2);
        call_time[2] = '\0';
        parser->object->x.call_time.hour = (kal_uint8) atoi(call_time);
		field += 2;
        if (*field == '-')
        {
            field++;
        }

		strncpy(call_time, field, 2);
        call_time[2] = '\0';
        parser->object->x.call_time.min = (kal_uint8) atoi(call_time);
		field += 2;
        if (*field == '-')
        {
            field++;
        }

		strncpy(call_time, field, 2);
        call_time[2] = '\0';
        parser->object->x.call_time.sec = (kal_uint8) atoi(call_time);
		

    }
}
	
#endif	


void vcard_get_adr(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool valid_adr = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->adr_count >= VCARD_MAX_ADR_COUNT)
    {
        return;
    }

    if (parser->field_count > 0 && parser->object->adr[parser->adr_count].post_office)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[0],
            parser->object->adr[parser->adr_count].post_office,
            parser->charset,
            VCARD_MAX_ADR_LENGTH);

        if (parser->object->adr[parser->adr_count].post_office[0])
        {
            valid_adr = KAL_TRUE;
        }
    }

    if (parser->field_count > 1 && parser->object->adr[parser->adr_count].extended)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[1],
            parser->object->adr[parser->adr_count].extended,
            parser->charset,
            VCARD_MAX_ADR_LENGTH);

        if (parser->object->adr[parser->adr_count].extended[0])
        {
            valid_adr = KAL_TRUE;
        }
    }

    if (parser->field_count > 2 && parser->object->adr[parser->adr_count].street)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[2],
            parser->object->adr[parser->adr_count].street,
            parser->charset,
            VCARD_MAX_ADR_LENGTH);

        if (parser->object->adr[parser->adr_count].street[0])
        {
            valid_adr = KAL_TRUE;
        }
    }

    if (parser->field_count > 3 && parser->object->adr[parser->adr_count].locality)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[3],
            parser->object->adr[parser->adr_count].locality,
            parser->charset,
            VCARD_MAX_ADR_LENGTH);

        if (parser->object->adr[parser->adr_count].locality[0])
        {
            valid_adr = KAL_TRUE;
        }
    }

    if (parser->field_count > 4 && parser->object->adr[parser->adr_count].region)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[4],
            parser->object->adr[parser->adr_count].region,
            parser->charset,
            VCARD_MAX_ADR_LENGTH);

        if (parser->object->adr[parser->adr_count].region[0])
        {
            valid_adr = KAL_TRUE;
        }
    }

    if (parser->field_count > 5 && parser->object->adr[parser->adr_count].postal_code)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[5],
            parser->object->adr[parser->adr_count].postal_code,
            parser->charset,
            VCARD_MAX_ADR_LENGTH);

        if (parser->object->adr[parser->adr_count].postal_code[0])
        {
            valid_adr = KAL_TRUE;
        }
    }

    if (parser->field_count > 6 && parser->object->adr[parser->adr_count].country)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[6],
            parser->object->adr[parser->adr_count].country,
            parser->charset,
            VCARD_MAX_ADR_LENGTH);

        if (parser->object->adr[parser->adr_count].country[0])
        {
            valid_adr = KAL_TRUE;
        }
    }

    if (valid_adr)
    {
        parser->adr_count++;
    }
}

void vcard_get_tel(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_tel_struct tel;
#ifndef __COSMOS_MMI_PACKAGE__
    kal_int32 i;
#endif
    kal_int32 type_mask = 0;
    kal_char *token_pos = parser->line_buffer + parser->name_offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->tel_count >= VCARD_MAX_TEL_COUNT)
    {
        return;
    }

    if (parser->field_count > 0)
    {
        tel.tel = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_TEL_LENGTH + 1) * sizeof(kal_wchar));
        tel.type = VCARD_TEL_TYPE_VOICE;
        tel.is_preferred = KAL_FALSE;

        if (parser->param_offset > parser->name_offset)
        {
            if (strstr(token_pos, "VOICE"))
            {
                type_mask |= 2 << VCARD_TEL_TYPE_VOICE;
            }
            if (strstr(token_pos, "CELL"))
            {
                type_mask |= 2 << VCARD_TEL_TYPE_CELL;
            }
            if (strstr(token_pos, "HOME"))
            {
                type_mask |= 2 << VCARD_TEL_TYPE_HOME;
            }
            if (strstr(token_pos, "WORK"))
            {
                type_mask |= 2 << VCARD_TEL_TYPE_WORK;
            }
            if (strstr(token_pos, "FAX"))
            {
                type_mask |= 2 << VCARD_TEL_TYPE_FAX;
            }

			if(type_mask == 0)
            {
                token_pos = strstr(token_pos, ";");
                if (!token_pos)
                {
                #if defined( __COSMOS_MMI_PACKAGE__)
                    if (!type_mask)
                    {
                        type_mask = 2 << VCARD_TEL_TYPE_VOICE;
                    }
                #elif !defined(__MMI_VCARD_TEL_VOICE_CELL_DIFFERENT__)
                    if (!type_mask)
                    {
                        type_mask = 2 << VCARD_TEL_TYPE_CELL;
                    }
                #endif /* __MMI_VCARD_TEL_VOICE_CELL_DIFFERENT__ */
                }
            }

            if (strstr(parser->line_buffer + parser->name_offset, "PREF"))
            {
                tel.is_preferred = KAL_TRUE;
            }
        }
        else
        {
        #if defined( __COSMOS_MMI_PACKAGE__)
            type_mask = 2 << VCARD_TEL_TYPE_VOICE;
        #elif !defined(__MMI_VCARD_TEL_VOICE_CELL_DIFFERENT__)
            type_mask = 2 << VCARD_TEL_TYPE_CELL;
        #endif
        }

        while (type_mask)
        {
				
            if (type_mask & (2 << VCARD_TEL_TYPE_VOICE))
            {
                type_mask &= ~(2 << VCARD_TEL_TYPE_VOICE);
            #if defined( __COSMOS_MMI_PACKAGE__)
                if (type_mask)
                {
                    continue;
                }
            #elif !defined(__MMI_VCARD_TEL_VOICE_CELL_DIFFERENT__)
                if (!type_mask)
                {
                    tel.type = VCARD_TEL_TYPE_CELL;
                }
            #else /* __MMI_VCARD_TEL_VOICE_CELL_DIFFERENT__ */
                continue;
            #endif /* __MMI_VCARD_TEL_VOICE_CELL_DIFFERENT__ */
            }
            else if (type_mask & (2 << VCARD_TEL_TYPE_CELL))
            {
                type_mask &= ~(2 << VCARD_TEL_TYPE_CELL);
                tel.type = VCARD_TEL_TYPE_CELL;
            }
            else if (type_mask & (2 << VCARD_TEL_TYPE_HOME))
            {
                type_mask &= ~(2 << VCARD_TEL_TYPE_HOME);
                tel.type = VCARD_TEL_TYPE_HOME;
            }
            else if (type_mask & (2 << VCARD_TEL_TYPE_WORK))
            {
                type_mask &= ~(2 << VCARD_TEL_TYPE_WORK);
                tel.type = VCARD_TEL_TYPE_WORK;
            }
            else if (type_mask & (2 << VCARD_TEL_TYPE_FAX))
            {
                type_mask &= ~(2 << VCARD_TEL_TYPE_FAX);
                tel.type = VCARD_TEL_TYPE_FAX;
            }
            else
            {
                free_ctrl_buffer(tel.tel);
                return;
            }

            vcard_convert_to_ucs2(
                parser->line_buffer + parser->field_offset[0],
                tel.tel,
                parser->charset,
                VCARD_MAX_TEL_LENGTH);

            if (parser->mode & VCARD_PARSE_MODE_TEL_ALWAYS)
            {
                if (parser->object->tel[parser->tel_count].tel)
                {
                    app_ucs2_wcscpy(parser->object->tel[parser->tel_count].tel, tel.tel);
                    parser->object->tel[parser->tel_count].type = tel.type;
                    parser->object->tel[parser->tel_count].is_preferred = tel.is_preferred;
                }
                parser->tel_count++;
            }
            else
            {
            #ifdef __COSMOS_MMI_PACKAGE__
                if (parser->object->tel[parser->tel_count].tel && !parser->object->tel[parser->tel_count].tel[0])
                {
                    app_ucs2_wcscpy(parser->object->tel[parser->tel_count].tel, tel.tel);
                    parser->object->tel[parser->tel_count].type = tel.type;
                    parser->object->tel[parser->tel_count].is_preferred = tel.is_preferred;
                    parser->tel_count++;
                }
            #else /* __COSMOS_MMI_PACKAGE__ */
                if (tel.type == VCARD_TEL_TYPE_CELL && parser->object->tel[0].tel && !parser->object->tel[0].tel[0])
                {
                    app_ucs2_wcscpy(parser->object->tel[0].tel, tel.tel);
                    parser->object->tel[0].type = VCARD_TEL_TYPE_CELL;
                    parser->object->tel[0].is_preferred = tel.is_preferred;
                    if (parser->object->tel[0].tel[0])
                    {
                        parser->tel_count++;
                    }
                }
                else if (tel.type != VCARD_TEL_TYPE_VOICE)
                {
                    for (i = 1; i < VCARD_MAX_TEL_COUNT; i++)
                    {
                        if (parser->object->tel[i].tel && !parser->object->tel[i].tel[0])
                        {
                            app_ucs2_wcscpy(parser->object->tel[i].tel, tel.tel);
                            parser->object->tel[i].type = tel.type;
                            parser->object->tel[i].is_preferred = tel.is_preferred;
                            if (parser->object->tel[i].tel[0])
                            {
                                parser->tel_count++;
                                break;
                            }
                        }
                    }
                }
            #endif /* __COSMOS_MMI_PACKAGE__ */
            }
        }

        free_ctrl_buffer(tel.tel);
    }
}

void vcard_get_email(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->email_count >= VCARD_MAX_EMAIL_COUNT)
    {
        return;
    }

    if (parser->field_count > 0 && parser->object->email[parser->email_count].email)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[0],
            parser->object->email[parser->email_count].email,
            parser->charset,
            VCARD_MAX_EMAIL_LENGTH);

        if (strstr(parser->line_buffer + parser->name_offset, "HOME"))
        {
            parser->object->email[parser->email_count].type = VCARD_EMAIL_TYPE_HOME;
        }
        else if (strstr(parser->line_buffer + parser->name_offset, "WORK"))
        {
            parser->object->email[parser->email_count].type = VCARD_EMAIL_TYPE_WORK;
        }
        else
        {
            parser->object->email[parser->email_count].type = VCARD_EMAIL_TYPE_INTERNET;
        }

        if (strstr(parser->line_buffer + parser->name_offset, "PREF"))
        {
            parser->object->email[parser->email_count].is_preferred = KAL_TRUE;
        }

        if (parser->object->email[parser->email_count].email[0])
        {
            parser->email_count++;
        }
    }
}

void vcard_get_title(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->field_count > 0 && parser->object->title.title)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[0],
            parser->object->title.title,
            parser->charset,
            VCARD_MAX_TITLE_LENGTH);
    }
}

void vcard_get_org(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->field_count > 0 && parser->object->org.name)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[0],
            parser->object->org.name,
            parser->charset,
            VCARD_MAX_ORG_LENGTH);
    }

    if (parser->field_count > 1 && parser->object->org.unit)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[1],
            parser->object->org.unit,
            parser->charset,
            VCARD_MAX_ORG_LENGTH);
    }
}

void vcard_get_category(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->field_count > 0 && parser->object->category.name)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[0],
            parser->object->category.name,
            parser->charset,
            VCARD_MAX_CATEGORY_LENGTH);
    }
}

void vcard_get_note(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->field_count > 0 && parser->object->note.note)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[0],
            parser->object->note.note,
            parser->charset,
            VCARD_MAX_NOTE_LENGTH);
    }
}

void vcard_get_url(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->url_count >= VCARD_MAX_URL_COUNT)
    {
        return;
    }

    if (parser->field_count > 0 && parser->object->url[parser->url_count].url)
    {
        vcard_convert_to_ucs2(
            parser->line_buffer + parser->field_offset[0],
            parser->object->url[parser->url_count].url,
            parser->charset,
            VCARD_MAX_URL_LENGTH);

        if (parser->object->url[parser->url_count].url[0])
        {
            parser->url_count++;
        }
    }
}

void vcard_get_version(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strstr(parser->line_buffer + parser->param_offset, "3.0"))
    {
        parser->version = VCARD_VERSION_3_0;
		parser->default_charset = VCARD_CHARSET_UTF8;
    }
    else
    {
        parser->version = VCARD_VERSION_2_1;
		parser->default_charset = VCARD_CHARSET_ASCII;
    }
}

void vcard_remove_delimiter(vcard_parser_struct *parser, kal_int32 field_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *field = parser->line_buffer + field_offset;
    kal_char *new_field = field;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*field)
    {
        if (*field == '\\' && (*(field + 1) == ';' || *(field + 1) == '\\'))
        {
            field++;
        }
        *(new_field++) = *(field++);
    }
    *new_field = 0;
}

kal_bool vcard_is_delimiter(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_delimiter = KAL_TRUE;
    kal_int32 line_offset = parser->line_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (parser->line_buffer[line_offset - 2] == '5' &&
        parser->line_buffer[line_offset - 1] == 'C')
    {
        line_offset = line_offset - 3;
        is_delimiter = !is_delimiter ? KAL_TRUE: KAL_FALSE;
    }

    return is_delimiter;
}

void vcard_decode_base64(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = parser->param_offset;
    kal_int32 j = i;
    kal_int32 k = 0;
    kal_int32 m = 0;
    kal_uint8 u, u0, u1, u2, u3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; i < parser->line_length; i++)
    {
        if (parser->decode_length < 4)
        {
            parser->decode_buffer[parser->decode_length] = parser->line_buffer[i];
            parser->decode_length++;
        }

        if (parser->decode_length < 4)
        {
            continue;
        }

        u0 = VCARD_BASE64_DTABLE[parser->decode_buffer[0]];
        u1 = VCARD_BASE64_DTABLE[parser->decode_buffer[1]];
        u2 = VCARD_BASE64_DTABLE[parser->decode_buffer[2]];
        u3 = VCARD_BASE64_DTABLE[parser->decode_buffer[3]];

        u = ((u0 << 2) | (u1 >> 4));
        parser->line_buffer[j] = u;
        j++;

        if (parser->decode_buffer[2] != '=')
        {
            u = ((u1 << 4) | (u2 >> 2));
            parser->line_buffer[j] = u;
            j++;

            if (parser->decode_buffer[3] != '=')
            {
                u = ((u2 << 6) | u3);
                parser->line_buffer[j] = u;
                j++;
            }
            else
            {
                m = 1;
            }
        }
        else
        {
            m = 2;
        }

        parser->decode_length = 0;
        k++;
    }

    parser->data_offset = parser->line_length - k - m - parser->decode_length;
}

void vcard_decode_base64_ex(vcard_parser_struct *parser, kal_int32 field_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = field_offset;
    kal_int32 j = i;
    kal_uint8 u, u0, u1, u2, u3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (parser->line_buffer[i])
    {
        if (parser->decode_length < 4)
        {
            parser->decode_buffer[parser->decode_length] = parser->line_buffer[i++];
            parser->decode_length++;
        }

        if (parser->decode_length < 4)
        {
            continue;
        }

        u0 = VCARD_BASE64_DTABLE[parser->decode_buffer[0]];
        u1 = VCARD_BASE64_DTABLE[parser->decode_buffer[1]];
        u2 = VCARD_BASE64_DTABLE[parser->decode_buffer[2]];
        u3 = VCARD_BASE64_DTABLE[parser->decode_buffer[3]];

        u = ((u0 << 2) | (u1 >> 4));
        parser->line_buffer[j] = u;
        j++;

        if (parser->decode_buffer[2] != '=')
        {
            u = ((u1 << 4) | (u2 >> 2));
            parser->line_buffer[j] = u;
            j++;

            if (parser->decode_buffer[3] != '=')
            {
                u = ((u2 << 6) | u3);
                parser->line_buffer[j] = u;
                j++;
            }
        }

        parser->decode_length = 0;
    }

    parser->line_buffer[j] = 0;
}

void vcard_decode_qp(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = parser->param_offset;
    kal_int32 j = i;
    kal_int32 k = 0;
    kal_int32 c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < parser->line_length)
    {
        if (parser->line_buffer[i] == '=')
        {
            sscanf(parser->line_buffer + i, "=%02X", &c);
            parser->line_buffer[j] = c;
            i += 3;
            k++;
        }
        else
        {
            parser->line_buffer[j] = parser->line_buffer[i];
            i++;
        }
        j++;
    }

    parser->data_offset = parser->line_length - 2 * k;
}

void vcard_decode_qp_ex(vcard_parser_struct *parser, kal_int32 field_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = field_offset;
    kal_int32 j = i;
    kal_int32 c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (parser->line_buffer[i])
    {
        if (parser->line_buffer[i] == '=')
        {
            sscanf(parser->line_buffer + i, "=%02X", &c);
            parser->line_buffer[j] = c;
            i += 3;
        }
        else
        {
            parser->line_buffer[j] = parser->line_buffer[i];
            i++;
        }
        j++;
    }

    parser->line_buffer[j] = 0;
}

void vcard_decode_photo(vcard_parser_struct *parser, kal_bool end_of_photo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 len;
	FS_HANDLE fd;
	kal_int32 offset;
	kal_int32 index;
	
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->encoding != VCARD_ENCODING_BASE64)
    {
        return;
    }

    if (parser->photo == -1 && parser->object)
    {
        applib_time_struct local_time;

        applib_dt_get_rtc_time(&local_time);

        vcard_create_folder(parser->object->photo.file_name);

        if (parser->param_offset > parser->name_offset)
        {
            kal_wchar *file_name = (kal_wchar*) get_ctrl_buffer(VCARD_MAX_PATH_LENGTH * sizeof(kal_wchar));
			
            kal_wsprintf(
                file_name,
                "PHOTO%04d-%02d-%02d-%02d-%02d-%02d(%d)",
                local_time.nYear,
                local_time.nMonth,
                local_time.nDay,
                local_time.nHour,
                local_time.nMin,
                local_time.nSec,
                parser->sequence++);

			index = parser->sequence;

        #if defined(__GDI_MEMORY_PROFILE_2__)
            if (strstr(parser->line_buffer + parser->name_offset, "JPG"))
            {
                app_ucs2_wcscat(file_name, L".JPG");
                parser->object->photo.type = VCARD_PHOTO_TYPE_JPG;
            }
            else if (strstr(parser->line_buffer + parser->name_offset, "JPEG"))
            {
                app_ucs2_wcscat(file_name, L".JPEG");
                parser->object->photo.type = VCARD_PHOTO_TYPE_JPEG;
            }
            else
        #endif /* defined(__GDI_MEMORY_PROFILE_2__) */
            if (strstr(parser->line_buffer + parser->name_offset, "GIF"))
            {
                app_ucs2_wcscat(file_name, L".GIF");
                parser->object->photo.type = VCARD_PHOTO_TYPE_GIF;
            }
            else if (strstr(parser->line_buffer + parser->name_offset, "BMP") ||
                !strstr(parser->line_buffer + parser->name_offset, "WBMP"))
            {
                app_ucs2_wcscat(file_name, L".BMP");
                parser->object->photo.type = VCARD_PHOTO_TYPE_BMP;
            }
            else if (strstr(parser->line_buffer + parser->name_offset, "WBMP"))
            {
                app_ucs2_wcscat(file_name, L".WBMP");
                parser->object->photo.type = VCARD_PHOTO_TYPE_WBMP;
            }
            else if (strstr(parser->line_buffer + parser->name_offset, "WBM") ||
                !strstr(parser->line_buffer + parser->name_offset, "WBMP"))
            {
                app_ucs2_wcscat(file_name, L".WBM");
                parser->object->photo.type = VCARD_PHOTO_TYPE_WBM;
            }
        #if defined(GDI_USING_PNG)
            else if (strstr(parser->line_buffer + parser->name_offset, "PNG"))
            {
                app_ucs2_wcscat(file_name, L".PNG");
                parser->object->photo.type = VCARD_PHOTO_TYPE_PNG;
            }
        #endif /* defined(GDI_USING_PNG) */
        #if defined(GDI_USING_M3D)
            else if (strstr(parser->line_buffer + parser->name_offset, "M3D"))
            {
                app_ucs2_wcscat(file_name, L".M3D");
                parser->object->photo.type = VCARD_PHOTO_TYPE_M3D;
            }
        #endif /* defined(GDI_USING_M3D) */
        #ifdef SVG12_SUPPORT
            else if (strstr(parser->line_buffer + parser->name_offset, "SVG"))
            {
                app_ucs2_wcscat(file_name, L".SVG");
                parser->object->photo.type = VCARD_PHOTO_TYPE_SVG;
            }
        #endif /* SVG12_SUPPORT */
            else
            {
                return;
            }

			offset = app_ucs2_wcslen(parser->object->photo.file_name);
			app_ucs2_wcscat(parser->object->photo.file_name, file_name);		

			fd = FS_Open(parser->object->photo.file_name, FS_READ_ONLY);
			while(fd >= 0)
			{
				FS_Close(fd);
				parser->object->photo.file_name[offset + 25] = index + '0';
				fd = FS_Open(parser->object->photo.file_name, FS_READ_ONLY);

				index++;
			}
            
            parser->photo = FS_Open(parser->object->photo.file_name, FS_CREATE_ALWAYS | FS_READ_WRITE);
            if (parser->photo < 0)
            {
                parser->photo = 0;
                parser->object->photo.file_name[0] = 0;
            }
            free_ctrl_buffer(file_name);
        }
    }

    if (parser->photo > 0)
    {
        vcard_decode_base64(parser);

        if (FS_Write(
                parser->photo,
                parser->line_buffer + parser->param_offset,
                parser->data_offset - parser->param_offset,
                (kal_uint32*) &len) < 0)
        {
            FS_Close(parser->photo);
            parser->photo = 0;
            FS_Delete(parser->object->photo.file_name);
            parser->object->photo.file_name[0] = 0;
            return;
        }

        if (end_of_photo)
        {
            FS_Close(parser->photo);
            parser->photo = 0;
        }
    }
}

kal_bool vcard_data_begin(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcard_strupr(parser->line_buffer);

    parser->tag = vcard_get_tag(parser->line_buffer);

    if (parser->param_offset > parser->name_offset)
    {
        vcard_strupr(parser->line_buffer + parser->name_offset);

        if (strstr(parser->line_buffer + parser->name_offset, "BASE64") ||
            strstr(parser->line_buffer + parser->name_offset, "ENCODING=B"))
        {
            parser->encoding = VCARD_ENCODING_BASE64;
        }
        else if (strstr(parser->line_buffer + parser->name_offset, "QUOTED-PRINTABLE"))
        {
            parser->encoding = VCARD_ENCODING_QP;
        }

        parser->charset = parser->default_charset;

        if (strstr(parser->line_buffer + parser->name_offset, "US-ASCII"))
        {
            parser->charset = VCARD_CHARSET_ASCII;
        }
    #if defined(__MMI_CHSET_WESTERN_ISO__)
        else if (strstr(parser->line_buffer + parser->name_offset, "ISO-8859-1"))
        {
            parser->charset = VCARD_CHARSET_8859_1;
        }
    #endif /* defined(__MMI_CHSET_WESTERN_ISO__) */
    #if defined(__MMI_CHSET_SJIS__)
        else if (strstr(parser->line_buffer + parser->name_offset, "SHIFT_JIS"))
        {
            parser->charset = VCARD_CHARSET_SHIFT_JIS;
        }
    #endif /* defined(__MMI_CHSET_SJIS__) */
        else if (strstr(parser->line_buffer + parser->name_offset, "UTF-8"))
        {
            parser->charset = VCARD_CHARSET_UTF8;
        }
    #if defined(__MMI_CHSET_BIG5__)
        else if (strstr(parser->line_buffer + parser->name_offset, "BIG5"))
        {
            parser->charset = VCARD_CHARSET_BIG5;
        }
    #endif /* defined(__MMI_CHSET_BIG5__) */
    #if defined(__MMI_CHSET_HKSCS__)
        else if (strstr(parser->line_buffer + parser->name_offset, "HKSCS"))
        {
            parser->charset = VCARD_CHARSET_HKSCS;
        }
    #endif /* defined(__MMI_CHSET_HKSCS__) */
    #if defined(__MMI_CHSET_GB2312__)
        else if (strstr(parser->line_buffer + parser->name_offset, "GB2312"))
        {
            parser->charset = VCARD_CHARSET_GB2312;
        }
    #endif /* defined(__MMI_CHSET_GB2312__) */
    #if defined(__MMI_CHSET_GB18030__)
        else if (strstr(parser->line_buffer + parser->name_offset, "GB18030") ||
            strstr(parser->line_buffer + parser->name_offset, "GBK"))
        {
            parser->charset = VCARD_CHARSET_GB18030;
        }
    #endif /* defined(__MMI_CHSET_GB18030__) */
	#if defined(__BT_PBAP_CLIENT__)
	    else if (strstr(parser->line_buffer + parser->name_offset, "DIALED"))
        {
            parser->object->x.call_type= VCARD_X_CALL_TYPE_DIALED;
        }
     else if (strstr(parser->line_buffer + parser->name_offset, "OUTGOING"))
        {
            parser->object->x.call_type= VCARD_X_CALL_TYPE_DIALED;
        }
		else if (strstr(parser->line_buffer + parser->name_offset, "MISSED"))
        {
            parser->object->x.call_type= VCARD_X_CALL_TYPE_MISSED;
        }
		else if (strstr(parser->line_buffer + parser->name_offset, "RECEIVED"))
        {
            parser->object->x.call_type= VCARD_X_CALL_TYPE_RECEIVED;
        }
   else if (strstr(parser->line_buffer + parser->name_offset, "INCOMING"))
        {
            parser->object->x.call_type= VCARD_X_CALL_TYPE_RECEIVED;
        }
	#endif
    }


    return KAL_TRUE;
}

kal_int32 vcard_data_end(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->tag == VCARD_TAG_PHOTO)
    {
        if (parser->property & VCARD_PROPERTY_PHOTO)
        {
            vcard_decode_photo(parser, KAL_TRUE);
        }
        vcard_init_line(parser);
        return VCARD_NO_ERROR;
    }

    if (parser->tag == VCARD_TAG_LOGO || parser->tag == VCARD_TAG_SOUND || parser->tag == VCARD_TAG_KEY)
    {
        vcard_init_line(parser);
        return VCARD_NO_ERROR;
    }

    for (i = 0; i < parser->field_count; i++)
    {
        if (parser->encoding == VCARD_ENCODING_BASE64)
        {
            vcard_decode_base64_ex(parser, parser->field_offset[i]);
        }
        else if (parser->encoding == VCARD_ENCODING_QP)
        {
            vcard_decode_qp_ex(parser, parser->field_offset[i]);
            vcard_remove_delimiter(parser, parser->field_offset[i]);
        }
        else
        {
            vcard_remove_delimiter(parser, parser->field_offset[i]);
        }
    }

    switch (parser->tag)
    {
        case VCARD_TAG_BEGIN:
            vcard_strupr(parser->line_buffer + parser->param_offset);

            if (strstr(parser->line_buffer + parser->param_offset, "VCARD"))
            {
                parser->grouping++;
                parser->indent++;
            }
            else
            {
                return VCARD_ERROR_INVALID_FORMAT;
            }
            break;
			
        case VCARD_TAG_FN:
            if (parser->property & VCARD_PROPERTY_N)
            {
                vcard_get_fn(parser);
            }
            break;

        case VCARD_TAG_N:
            if (parser->property & VCARD_PROPERTY_N)
            {
                vcard_get_n(parser);
            }
            break;

        case VCARD_TAG_NICKNAME:
        case VCARD_TAG_X_NICKNAME:
            if (parser->property & VCARD_PROPERTY_NICKNAME)
            {
                vcard_get_nickname(parser);
            }
            break;

        case VCARD_TAG_PHOTO:
            break;

        case VCARD_TAG_BDAY:
            if (parser->property & VCARD_PROPERTY_BDAY)
            {
                vcard_get_bday(parser);
            }
            break;

        case VCARD_TAG_ADR:
            if (parser->property & VCARD_PROPERTY_ADR)
            {
                vcard_get_adr(parser);
            }
            break;

        case VCARD_TAG_LABEL:
            break;

        case VCARD_TAG_TEL:
            if (parser->property & VCARD_PROPERTY_TEL)
            {
                vcard_get_tel(parser);
            }
            break;

        case VCARD_TAG_EMAIL:
            if (parser->property & VCARD_PROPERTY_EMAIL)
            {
                vcard_get_email(parser);
            }
            break;

        case VCARD_TAG_MAILER:
            break;

        case VCARD_TAG_TZ:
            break;

        case VCARD_TAG_GEO:
            break;

        case VCARD_TAG_TITLE:
            if (parser->property & VCARD_PROPERTY_TITLE)
            {
                vcard_get_title(parser);
            }
            break;

        case VCARD_TAG_ROLE:
            break;

        case VCARD_TAG_LOGO:
            break;

        case VCARD_TAG_AGENT:
            break;

        case VCARD_TAG_ORG:
            if (parser->property & VCARD_PROPERTY_ORG)
            {
                vcard_get_org(parser);
            }
            break;

        case VCARD_TAG_CATEGORIES:
        case VCARD_TAG_X_CATEGORIES:
            if (parser->property & VCARD_PROPERTY_CATEGORY)
            {
                vcard_get_category(parser);
            }
            break;

        case VCARD_TAG_NOTE:
            if (parser->property & VCARD_PROPERTY_NOTE)
            {
                vcard_get_note(parser);
            }
            break;

        case VCARD_TAG_PRODID:
            break;

        case VCARD_TAG_REV:
            break;

        case VCARD_TAG_SORT_STRING:
            break;

        case VCARD_TAG_SOUND:
            break;

        case VCARD_TAG_URL:
            if (parser->property & VCARD_PROPERTY_URL)
            {
                vcard_get_url(parser);
            }
            break;

        case VCARD_TAG_UID:
            break;

        case VCARD_TAG_VERSION:
            vcard_get_version(parser);
            break;

        case VCARD_TAG_CLASS:
            break;

        case VCARD_TAG_KEY:
            break;

		#if defined(__BT_PBAP_CLIENT__)
		case VCARD_TAG_X:
			if (parser->property & VCARD_PROPERTY_X)
            {
                vcard_get_x(parser);
            }	
            break;
		#endif	

        case VCARD_TAG_END:
            vcard_strupr(parser->line_buffer + parser->param_offset);

            if (strstr(parser->line_buffer + parser->param_offset, "VCARD"))
            {
                parser->indent--;
                if (parser->indent == 0)
                {
                    if (parser->property & VCARD_PROPERTY_N)
                    {
                        if (parser->object->n.family && !parser->object->n.family[0] &&
                            parser->object->n.given && !parser->object->n.given[0] &&
                        #ifdef VCARD_FULL_N
                            parser->object->n.mid && !parser->object->n.mid[0] &&
                            parser->object->n.prefix && !parser->object->n.prefix[0] &&
                            parser->object->n.suffix && !parser->object->n.suffix[0] &&
                        #endif /* VCARD_FULL_N */
                            parser->object->n.name && parser->object->n.name[0])
                        {
                            app_ucs2_wcscpy(parser->object->n.given, parser->object->n.name);
                        }
                    }

                    vcard_init_line(parser);
                    return VCARD_NO_ERROR_MORE;
                }
                else if (parser->indent < 0)
                {
                    return VCARD_ERROR_INVALID_FORMAT;
                }
            }
            else
            {
                return VCARD_ERROR_INVALID_FORMAT;
            }
            break;

        default:
            break;
    }

    vcard_init_line(parser);

    return VCARD_NO_ERROR;
}

kal_bool vcard_add_char_to_line(vcard_parser_struct *parser, kal_char c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->line_length < VCARD_MAX_LINE_LENGTH)
    {
        if (parser->state == VCARD_STATE_DATA && parser->tag == VCARD_TAG_ADR &&
            parser->field_count >= 1 && parser->field_count <= VCARD_MAX_FIELD_COUNT)
        {
            if (parser->field_length[parser->field_count - 1] < VCARD_MAX_ADR_LENGTH * VCARD_MAX_QT_COUNT)
            {
                parser->line_buffer[parser->line_length] = c;
                parser->line_length++;

                parser->field_length[parser->field_count - 1]++;
            }
            else if (parser->field_length[parser->field_count - 1] == VCARD_MAX_ADR_LENGTH * VCARD_MAX_QT_COUNT)
            {
                parser->line_buffer[parser->line_length] = 0;
                parser->line_length++;
                parser->line_buffer[parser->line_length] = c;
                parser->line_length++;

                parser->field_length[parser->field_count - 1]++;
            }
            else
            {
                parser->line_buffer[parser->line_length - 1] = c;
                return KAL_FALSE;
            }
        }
        else
        {
            parser->line_buffer[parser->line_length] = c;
            parser->line_length++;
        }
    }
    else if (parser->tag == VCARD_TAG_PHOTO)
    {
        if (parser->property & VCARD_PROPERTY_PHOTO)
        {
            vcard_decode_photo(parser, KAL_FALSE);
            memcpy(parser->line_buffer + parser->param_offset, parser->decode_buffer, parser->decode_length);
            parser->line_length = parser->param_offset + parser->decode_length;
            parser->decode_length = 0;
            parser->line_buffer[parser->line_length] = c;
            parser->line_length++;
        }
        else
        {
            parser->line_length = parser->param_offset;
            parser->line_buffer[parser->line_length] = c;
            parser->line_length++;
        }
    }
    else if (parser->tag == VCARD_TAG_LOGO || parser->tag == VCARD_TAG_SOUND || parser->tag == VCARD_TAG_KEY)
    {
        parser->line_length = parser->param_offset;
        parser->line_buffer[parser->line_length] = c;
        parser->line_length++;
    }
    else
    {
        parser->line_buffer[VCARD_MAX_LINE_LENGTH - 1] = c;
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

kal_bool vcard_add_field_to_list(vcard_parser_struct *parser, kal_int32 field_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->field_count < VCARD_MAX_FIELD_COUNT)
    {
        parser->field_offset[parser->field_count] = field_offset;
        parser->field_count++;
    }
    else
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

kal_int32 vcard_process_char(vcard_parser_struct *parser, kal_char c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (parser->state)
    {
        case VCARD_STATE_NAME:
            switch (c)
            {
                case ':':
                    vcard_add_char_to_line(parser, 0);
                    vcard_add_field_to_list(parser, parser->line_length);

                    parser->state = VCARD_STATE_DATA;
                    parser->name_offset = parser->line_length;
                    parser->param_offset = parser->name_offset;

                    vcard_data_begin(parser);
                    break;

                case ';':
                    vcard_add_char_to_line(parser, 0);

                    parser->state = VCARD_STATE_PARAM;
                    parser->name_offset = parser->line_length;
                    break;

                case '.':
                    parser->name_offset = 0;
                    break;

                default:
                    if (isspace(c))
                    {
                        return VCARD_NO_ERROR;
                    }

                    vcard_add_char_to_line(parser, c);
                    break;
            }
            break;

        case VCARD_STATE_PARAM:
            switch (c)
            {
                case ':':
                    vcard_add_char_to_line(parser, 0);
                    vcard_add_field_to_list(parser, parser->line_length);

                    parser->state = VCARD_STATE_DATA;
                    parser->param_offset = parser->line_length;

                    vcard_data_begin(parser);
                    break;

                default:
                    if (isspace(c))
                    {
                        return VCARD_NO_ERROR;
                    }

                    vcard_add_char_to_line(parser, c);
                    break;
            }
            break;

        case VCARD_STATE_DATA:
            switch (c)
            {
                case '\r':
                    return VCARD_NO_ERROR;

                case '\n':
                    vcard_add_char_to_line(parser, 0);
                    return vcard_data_end(parser);

                case ';':
                    if (parser->field_escape)
                    {
                        parser->field_escape = KAL_FALSE;
                        vcard_add_char_to_line(parser, c);
                    }
                    else if (parser->encoding == VCARD_ENCODING_QP && !vcard_is_delimiter(parser))
                    {
                        vcard_add_char_to_line(parser, c);
                    }
                    else
                    {
                        vcard_add_char_to_line(parser, 0);
                        vcard_add_field_to_list(parser, parser->line_length);
                    }
                    break;

                default:
                    switch (parser->encoding)
                    {
                        case VCARD_ENCODING_BASE64:
                            if (isspace(c))
                            {
                                return VCARD_NO_ERROR;
                            }

                            vcard_add_char_to_line(parser, c);
                            break;

                        case VCARD_ENCODING_QP:
                        default:
                            if (c == '\\')
                            {
                                if (parser->field_escape)
                                {
                                    parser->field_escape = KAL_FALSE;
                                }
                                else
                                {
                                    parser->field_escape = KAL_TRUE;
                                }
                            }
                            else if (parser->field_escape)
                            {
                                parser->field_escape = KAL_FALSE;
                                vcard_add_char_to_line(parser, '\\');
                            }

                            vcard_add_char_to_line(parser, c);
                            break;
                    }
                    break;
            }
            break;

        default:
            ASSERT(0);
            break;
    }

    return VCARD_NO_ERROR;
}

vcard_parser_struct *vcard_malloc_parser(FS_HANDLE source, vcard_property_enum property)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_parser_struct *parser = NULL;
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parser = (vcard_parser_struct*) get_ctrl_buffer(sizeof(vcard_parser_struct));
    if (!vcard_add_instance(parser))
    {
        FS_Close(source);
        free_ctrl_buffer(parser);
        return NULL;
    }

    parser->source = source;
    parser->property = property;
    parser->default_charset = VCARD_CHARSET_ASCII;
    parser->mode = VCARD_PARSE_MODE_DEFAULT;
    parser->error_code = VCARD_NO_ERROR;
    parser->percentage = 0;
    FS_GetFileSize(source, (kal_uint32*) &parser->file_size);
    parser->process_char = 0;
    parser->sequence = 0;
    parser->cancel = KAL_FALSE;

    parser->object = (vcard_object_struct*) get_ctrl_buffer(sizeof(vcard_object_struct));
    memset(parser->object, 0, sizeof(vcard_object_struct));

    if (property & VCARD_PROPERTY_N)
    {
        parser->object->n.family = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_N_LENGTH + 1) * sizeof(kal_wchar));
        parser->object->n.given = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_N_LENGTH + 1) * sizeof(kal_wchar));
    #ifdef VCARD_FULL_N
        parser->object->n.mid = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_N_LENGTH + 1) * sizeof(kal_wchar));
        parser->object->n.prefix = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_N_LENGTH + 1) * sizeof(kal_wchar));
        parser->object->n.suffix = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_N_LENGTH + 1) * sizeof(kal_wchar));
    #else /* VCARD_FULL_N */
        parser->object->n.mid = NULL;
        parser->object->n.prefix = NULL;
        parser->object->n.suffix = NULL;
    #endif /* VCARD_FULL_N */
        parser->object->n.name = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_N_LENGTH + 1) * sizeof(kal_wchar));
    }

    if (property & VCARD_PROPERTY_NICKNAME)
    {
        parser->object->nickname.name = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_NICKNAME_LENGTH + 1) * sizeof(kal_wchar));
    }

    if (property & VCARD_PROPERTY_ADR)
    {
        for (i = 0; i < VCARD_MAX_ADR_COUNT; i++)
        {
            parser->object->adr[i].post_office = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_ADR_LENGTH + 1) * sizeof(kal_wchar));
            parser->object->adr[i].extended = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_ADR_LENGTH + 1) * sizeof(kal_wchar));
            parser->object->adr[i].street = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_ADR_LENGTH + 1) * sizeof(kal_wchar));
            parser->object->adr[i].locality = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_ADR_LENGTH + 1) * sizeof(kal_wchar));
            parser->object->adr[i].region = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_ADR_LENGTH + 1) * sizeof(kal_wchar));
            parser->object->adr[i].postal_code = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_ADR_LENGTH + 1) * sizeof(kal_wchar));
            parser->object->adr[i].country = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_ADR_LENGTH + 1) * sizeof(kal_wchar));
        }
    }

    if (property & VCARD_PROPERTY_TEL)
    {
        for (i = 0; i < VCARD_MAX_TEL_COUNT; i++)
        {
            parser->object->tel[i].tel = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_TEL_LENGTH + 1) * sizeof(kal_wchar));
        }
    }

    if (property & VCARD_PROPERTY_EMAIL)
    {
        for (i = 0; i < VCARD_MAX_EMAIL_COUNT; i++)
        {
            parser->object->email[i].email = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_EMAIL_LENGTH + 1) * sizeof(kal_wchar));
        }
    }

    if (property & VCARD_PROPERTY_TITLE)
    {
        parser->object->title.title = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_TITLE_LENGTH + 1) * sizeof(kal_wchar));
    }

    if (property & VCARD_PROPERTY_ORG)
    {
        parser->object->org.name = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_ORG_LENGTH + 1) * sizeof(kal_wchar));
        parser->object->org.unit = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_ORG_LENGTH + 1) * sizeof(kal_wchar));
    }

    if (property & VCARD_PROPERTY_CATEGORY)
    {
        parser->object->category.name = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_CATEGORY_LENGTH + 1) * sizeof(kal_wchar));
    }

    if (property & VCARD_PROPERTY_NOTE)
    {
        parser->object->note.note = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_NOTE_LENGTH + 1) * sizeof(kal_wchar));
    }

    if (property & VCARD_PROPERTY_URL)
    {
        for (i = 0; i < VCARD_MAX_URL_COUNT; i++)
        {
            parser->object->url[i].url = (kal_wchar*) get_ctrl_buffer((VCARD_MAX_URL_LENGTH + 1) * sizeof(kal_wchar));
        }
    }

    parser->read_offset = -1;
    parser->line_buffer = (kal_char*) get_ctrl_buffer(VCARD_MAX_LINE_LENGTH);

    vcard_init_line(parser);
    vcard_init_object(parser, parser->property);

    return parser;
}

kal_int32 vcard_parse_object(vcard_parser_struct *parser, kal_int32 object_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char c;
    kal_int32 len, i;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (object_offset != -1)
    {
        vcard_init_object(parser, parser->property);
        FS_Seek(parser->source, object_offset, FS_FILE_BEGIN);
    }
    result = FS_Read(parser->source, parser->read_buffer, VCARD_MAX_READ_LENGTH, (kal_uint32*) &len);
    if (result < 0)
    {
        parser->error_code = result;
        return VCARD_RESULT_FAIL;
    }

    while (len > 0)
    {
        for (i = 0; i < len; i++)
        {
            c = parser->read_buffer[i];
            parser->process_char++;

            if (!parser->line_begin)
            {
                if (!parser->line_folding && (c == ' ' || c == '\t'))
                {
                    parser->line_folding = KAL_TRUE;
                    if (parser->encoding == VCARD_ENCODING_QP && parser->line_buffer[parser->line_length - 1] == '=')
                    {
                        parser->line_length--;
                        parser->field_length[parser->field_count - 1]--;
                    }
                    ASSERT(vcard_process_char(parser, c) == VCARD_NO_ERROR);
                    continue;
                }

                parser->line_begin = KAL_TRUE;

                if (parser->encoding == VCARD_ENCODING_QP && parser->line_buffer[parser->line_length - 1] == '=')
                {
                    parser->line_length--;
                    parser->field_length[parser->field_count - 1]--;
                }
                else if (!parser->line_folding)
                {
                    result = vcard_process_char(parser, '\n');
                    if (result == VCARD_NO_ERROR_MORE)
                    {
                        parser->percentage = (kal_uint16) (((kal_uint64) parser->process_char * 100) / parser->file_size);
                        parser->read_offset = i;
                        parser->read_length = len;
                        parser->process_char--;
                        return VCARD_RESULT_MORE;
                    }
                    else if (result != VCARD_NO_ERROR)
                    {
                        parser->error_code = result;
                        return VCARD_RESULT_FAIL;
                    }
                }
            }

            if (c == '\n')
            {
                parser->line_begin = KAL_FALSE;
                parser->line_folding = KAL_FALSE;
                if (parser->field_escape)
                {
                    parser->field_escape = KAL_FALSE;
                    vcard_add_char_to_line(parser, '\\');
                }
            }
            else
            {
                ASSERT(vcard_process_char(parser, c) == VCARD_NO_ERROR);
            }
        }

        result = FS_Read(parser->source, parser->read_buffer, VCARD_MAX_READ_LENGTH, (kal_uint32*) &len);
        if (result < 0)
        {
            parser->error_code = result;
            return VCARD_RESULT_FAIL;
        }
    }

    if (vcard_process_char(parser, '\n') < VCARD_NO_ERROR)
    {
        return VCARD_RESULT_FAIL;
    }

    parser->percentage = 100;
    return VCARD_RESULT_OK;
}

kal_int32 vcard_parse_next_object(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char c;
    kal_int32 i;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcard_init_object(parser, parser->property);
    for (i = parser->read_offset; i < parser->read_length; i++)
    {
        c = parser->read_buffer[i];
        parser->process_char++;

        if (!parser->line_begin)
        {
            if (!parser->line_folding && (c == ' ' || c == '\t'))
            {
                parser->line_folding = KAL_TRUE;
                if (parser->encoding == VCARD_ENCODING_QP && parser->line_buffer[parser->line_length - 1] == '=')
                {
                    parser->line_length--;
                    parser->field_length[parser->field_count - 1]--;
                }
                ASSERT(vcard_process_char(parser, c) == VCARD_NO_ERROR);
                continue;
            }

            parser->line_begin = KAL_TRUE;

            if (parser->encoding == VCARD_ENCODING_QP && parser->line_buffer[parser->line_length - 1] == '=')
            {
                parser->line_length--;
                parser->field_length[parser->field_count - 1]--;
            }
            else if (!parser->line_folding)
            {
                result = vcard_process_char(parser, '\n');
                if (result == VCARD_NO_ERROR_MORE)
                {
                    parser->percentage = (kal_uint16) (((kal_uint64) parser->process_char * 100) / parser->file_size);
                    parser->read_offset = i;
                    parser->process_char--;
                    return VCARD_RESULT_MORE;
                }
                else if (result != VCARD_NO_ERROR)
                {
                    parser->error_code = result;
                    return VCARD_RESULT_FAIL;
                }
            }
        }

        if (c == '\n')
        {
            parser->line_begin = KAL_FALSE;
            parser->line_folding = KAL_FALSE;
            if (parser->field_escape)
            {
                parser->field_escape = KAL_FALSE;
                vcard_add_char_to_line(parser, '\\');
            }
        }
        else
        {
            ASSERT(vcard_process_char(parser, c) == VCARD_NO_ERROR);
        }
    }

    return vcard_parse_object(parser, -1);
}

void vcard_free_parser(vcard_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcard_remove_instance(parser);
    free_ctrl_buffer(parser->line_buffer);
    if (parser->property & VCARD_PROPERTY_N)
    {
        free_ctrl_buffer(parser->object->n.family);
        free_ctrl_buffer(parser->object->n.given);
     #ifdef VCARD_FULL_N
        free_ctrl_buffer(parser->object->n.mid);
        free_ctrl_buffer(parser->object->n.prefix);
        free_ctrl_buffer(parser->object->n.suffix);
    #endif /* VCARD_FULL_N */
        free_ctrl_buffer(parser->object->n.name);
    }
    if (parser->property & VCARD_PROPERTY_NICKNAME)
    {
        free_ctrl_buffer(parser->object->nickname.name);
    }
    if (parser->property & VCARD_PROPERTY_ADR)
    {
        for (i = 0; i < VCARD_MAX_ADR_COUNT; i++)
        {
            free_ctrl_buffer(parser->object->adr[i].post_office);
            free_ctrl_buffer(parser->object->adr[i].extended);
            free_ctrl_buffer(parser->object->adr[i].street);
            free_ctrl_buffer(parser->object->adr[i].locality);
            free_ctrl_buffer(parser->object->adr[i].region);
            free_ctrl_buffer(parser->object->adr[i].postal_code);
            free_ctrl_buffer(parser->object->adr[i].country);
        }
    }
    if (parser->property & VCARD_PROPERTY_TEL)
    {
        for (i = 0; i < VCARD_MAX_TEL_COUNT; i++)
        {
            free_ctrl_buffer(parser->object->tel[i].tel);
        }
    }
    if (parser->property & VCARD_PROPERTY_EMAIL)
    {
        for (i = 0; i < VCARD_MAX_EMAIL_COUNT; i++)
        {
            free_ctrl_buffer(parser->object->email[i].email);
        }
    }
    if (parser->property & VCARD_PROPERTY_TITLE)
    {
        free_ctrl_buffer(parser->object->title.title);
    }
    if (parser->property & VCARD_PROPERTY_ORG)
    {
        free_ctrl_buffer(parser->object->org.name);
        free_ctrl_buffer(parser->object->org.unit);
    }
    if (parser->property & VCARD_PROPERTY_CATEGORY)
    {
        free_ctrl_buffer(parser->object->category.name);
    }
    if (parser->property & VCARD_PROPERTY_NOTE)
    {
        free_ctrl_buffer(parser->object->note.note);
    }
    if (parser->property & VCARD_PROPERTY_URL)
    {
        for (i = 0; i < VCARD_MAX_URL_COUNT; i++)
        {
            free_ctrl_buffer(parser->object->url[i].url);
        }
    }
    free_ctrl_buffer(parser->object);
    free_ctrl_buffer(parser);
}

#endif /* __VCARD_SUPPORT__ */

