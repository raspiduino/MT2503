/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  EngineerModeAGPSlogCore.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Core of AGPS log system.
 *  Includes template parser, formatter and utility functions.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "EngineerModeAGPSlogProt.h"
#include "MMI_features.h"

#ifdef __AGPS_LOG_SUPPORT__

#include "kal_general_types.h"
#include "EngineerModeAGPSlogGprot.h"
#include "kal_public_api.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "app_datetime.h"

#ifdef __EM_AGPSLOG_DEBUG_ON_VC__
    #define DEBUG_PARSER(printf_args) printf##printf_args
    #define DEBUG_FORMATTER(printf_args) printf##printf_args
#else
    #define DEBUG_PARSER(printf_args)
    #define DEBUG_FORMATTER(printf_args)
#endif

#define EM_AGPSLOG_TEMPLATE_INITED_MAGIC 0x7fABAB7f


/*****************************************************************************
 * Typedef
 *****************************************************************************/

typedef enum
{
    /* Common */
    EM_AGPSLOG_TOKEN_STRING,
    EM_AGPSLOG_TOKEN_PROC_NAME,
    EM_AGPSLOG_TOKEN_PROC_TIME,
    EM_AGPSLOG_TOKEN_U8,
    EM_AGPSLOG_TOKEN_U16,
    EM_AGPSLOG_TOKEN_FLOAT,
    EM_AGPSLOG_TOKEN_Y, /* Year */
    EM_AGPSLOG_TOKEN_MM, /* Month */
    EM_AGPSLOG_TOKEN_DD, /* Day of month */
    EM_AGPSLOG_TOKEN_TIME,
    /* SUPL */
    EM_AGPSLOG_TOKEN_SUPL_VERSION_MAJOR,
    EM_AGPSLOG_TOKEN_SUPL_VERSION_MINOR,
    EM_AGPSLOG_TOKEN_SUPL_VERSION_SERV_IND,
    EM_AGPSLOG_TOKEN_SUPL_SESSION_ID,
    EM_AGPSLOG_TOKEN_SUPL_POSITION_METHOD,
    EM_AGPSLOG_TOKEN_SUPL_SESSION_TYPE,
    EM_AGPSLOG_TOKEN_SUPL_MESSAGE_DIRECTION,
    EM_AGPSLOG_TOKEN_SUPL_MESSAGE_TYPE,
    EM_AGPSLOG_TOKEN_SUPL_STATUS_CODE,
    EM_AGPSLOG_TOKEN_SUPL_SLP_IP,
    EM_AGPSLOG_TOKEN_SUPL_SLP_PORT,
    /* RRLP */
    EM_AGPSLOG_TOKEN_RRLP_MESSAGE_TYPE,
    EM_AGPSLOG_TOKEN_RRLP_MESSAGE_ADC,
    /* GPS */
    EM_AGPSLOG_TOKEN_GPS_SATELLITE_SV_ID,
    EM_AGPSLOG_TOKEN_GPS_SATELLITE_STRENGTH,
    EM_AGPSLOG_TOKEN_GPS_POS_RESULT_LONGITUDE,
    EM_AGPSLOG_TOKEN_GPS_POS_RESULT_LATITUDE,
    EM_AGPSLOG_TOKEN_GPS_POS_RESULT_ALTITUDE,
    EM_AGPSLOG_TOKEN_GPS_POS_RESULT_VELOCITY,
    EM_AGPSLOG_TOKEN_GPS_POS_RESULT_DIRECTION,
    EM_AGPSLOG_TOKEN_GPS_POS_RESULT_Y,
    EM_AGPSLOG_TOKEN_GPS_POS_RESULT_MM,
    EM_AGPSLOG_TOKEN_GPS_POS_RESULT_DD,
    EM_AGPSLOG_TOKEN_GPS_POS_RESULT_TIME,
    EM_AGPSLOG_TOKEN_GPS_CONN_STATUS,
    EM_AGPSLOG_TOKEN_GPS_START_TYPE,
    /* --------------------------------- */
    EM_AGPSLOG_TOKEN_END_OF_ENUM,
    EM_AGPSLOG_TOKEN_UNKNOWN,
    /* for structure of parsing cache to indicate the end of an list */
    EM_AGPSLOG_TOKEN_END_MARK
} em_agpslog_token_enum;


/*
 kal_uint8 *p (NOTE HERE: p should be kal_uint8*)
     |  +-----------+-------------+
     +->|   token   | data length |  header
        +-----------+-------------+
            1 byte      1 byte
 We should avoid define a new struct since it may be more expensive
 and the potential alignment problem. (in future)
*/

/* Return type: em_agpslog_template_token_type_enum*/
#define em_agpslog_template_node_overhead      (2) /* header length */
#define em_agpslog_template_get_token(p)        (*(p))
#define em_agpslog_template_set_token(p,token)   do { *(p) = (kal_uint8)(token); } while (0)
/* Return type: kal_uint32, next token (relative) offset*/
#define em_agpslog_template_get_data_length(p) (*((p)+1))
#define em_agpslog_template_set_data_length(p, offset) \
    do { *((p)+1) = (kal_uint8)((offset) & 0xff); } while (0)
/* Return type: kal_uint8*, the start pointer of data */
#define em_agpslog_template_get_data_p(p)      (p + em_agpslog_template_node_overhead)
#define em_agpslog_template_go_to_next_node(p) \
    do { p += em_agpslog_template_node_overhead + em_agpslog_template_get_data_length(p); } while (0)


/* Log header in file */
typedef struct {
    kal_uint8 log_type;
    kal_uint8 data_length;
} em_agpslog_log_header_struct;


/* ----------------------------- Template parser ---------------------------*/

/*
 * if (str begins with pattern)
 * {
 *     next = next start position (go through the pattern)
 *     var = value
 *     break the loop or switch
 * }
*/
#define ASSIGN_IF_BEGINS(str, pattern, next, var, value) \
{ \
    if (em_agpslog_string_begins(str, (const kal_char*)pattern, next)) \
    { var = value; break; } else { } \
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_parse_log_type
 * DESCRIPTION
 *  Parse log type.
 * PARAMETERS
 *  char_p      [IN]   String
 *  next        [OUT]  Start pointer of next token (skipped the log type)
 * RETURNS
 *  em_agpslog_type_enum
 *****************************************************************************/
static em_agpslog_type_enum em_agpslog_parse_log_type(const kal_char* char_p, const kal_char **next)
{
    typedef struct {
        kal_char *log_type_str;
        em_agpslog_type_enum log_type;
    } log_type_mapping_struct;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    static const log_type_mapping_struct log_type_mapping[] =
    {
        { "PROCEDURE_DURATION", EM_AGPSLOG_PROCEDURE_DURATION },

    #define LOG_RECOGNIZE_ITEM(item) \
        { #item, EM_AGPSLOG_##item }

        /* MMI */
        LOG_RECOGNIZE_ITEM(MMI_DATE_TIME),
        LOG_RECOGNIZE_ITEM(MMI_BATTERY_INFO),
        /* SUPL */
        LOG_RECOGNIZE_ITEM(SUPL_VERSION),
        LOG_RECOGNIZE_ITEM(SUPL_SESSION_ID),
        LOG_RECOGNIZE_ITEM(SUPL_SESSION_TYPE),
        LOG_RECOGNIZE_ITEM(SUPL_POSITION_METHOD),
        LOG_RECOGNIZE_ITEM(SUPL_SESSION_TYPE),
        LOG_RECOGNIZE_ITEM(SUPL_MESSAGE_TYPE),
        LOG_RECOGNIZE_ITEM(SUPL_STATUS_CODE),
        LOG_RECOGNIZE_ITEM(SUPL_SLP_ADDRESS),
        LOG_RECOGNIZE_ITEM(SUPL_SSL),
        /* RRLP */
        LOG_RECOGNIZE_ITEM(RRLP_MESSAGE_TYPE),
        /* GPS */
        LOG_RECOGNIZE_ITEM(GPS_ACCURACY),
        LOG_RECOGNIZE_ITEM(GPS_SATELLITE_INFO),
        LOG_RECOGNIZE_ITEM(GPS_POSITION_RESULT),
        LOG_RECOGNIZE_ITEM(GPS_CONNECTIVITY_STATUS),
        LOG_RECOGNIZE_ITEM(GPS_START_TYPE),

    #undef LOG_RECOGNIZE_ITEM

        { NULL, EM_AGPSLOG_TYPE_UNKNOWN } /* tail item */
    };

    em_agpslog_type_enum log_type;
    const log_type_mapping_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    log_type = EM_AGPSLOG_TYPE_UNKNOWN;

    for (item = log_type_mapping; item->log_type_str != NULL; item++)
    {
        if (em_agpslog_string_begins(char_p, item->log_type_str, next))
        {
            log_type = item->log_type;
            break;
        }
    }

    return log_type;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_append_parse_log
 * DESCRIPTION
 *  Append parse log to em_agpslog_parse_log_struct.
 *  If log == NULL, this function will return immediately.
 * PARAMETERS
 *  log             [IN/OUT]    Parse log.
 *  warning_type    [IN]        Warning type (String)
 *  msg             [IN]        Message
 *  line_number     [IN]        Line number
 * RETURNS
 *  em_agpslog_type_enum
 *****************************************************************************/
static void em_agpslog_append_parse_log(
    em_agpslog_parse_log_struct *log,
    const kal_char* warning_type, /* must not be NULL */
    const kal_char* msg,          /* can be NULL */
    const kal_uint32 line_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 max_length;
    kal_char* log_tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (log == NULL || log->full)
    {
        return;
    }

    max_length = em_agpslog_strlen(warning_type) + 5 ; /* 5 digits of line number at most */
    if (msg != NULL)
    {
        max_length += em_agpslog_strlen(msg);
    }

    log_tail = log->log_tail;

    if (log_tail + max_length < log->log_end) /* Cannot be <= to contain tail '\0' */
    {
        em_agpslog_strcpy(log_tail, warning_type);
        log_tail += em_agpslog_strlen(log_tail);
        em_agpslog_itoa(log_tail, line_number, 0);
        log_tail += em_agpslog_strlen(log_tail);

        if (msg != NULL)
        {
            em_agpslog_strcpy(log_tail, ": ");
            log_tail += em_agpslog_strlen(log_tail);
            em_agpslog_strcpy(log_tail, msg);
            log_tail += em_agpslog_strlen(log_tail);
        }

        em_agpslog_strcpy(log_tail, "\r\n");
        log_tail += em_agpslog_strlen(log_tail);
    }
    else
    {
        log->full = KAL_TRUE;
    }

    log->log_tail = log_tail;
    log->warning_count++;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_parse_token
 * DESCRIPTION
 *  Parse term.
 * PARAMETERS
 *  log_type        [IN]    em_agpslog_type_enum
 *                          Parser parse token type according to log type.
 *  char_p          [IN]    String
 *  next            [IN]    Start pointer of next token
 * RETURNS
 *  em_agpslog_token_enum
 *****************************************************************************/
static em_agpslog_token_enum em_agpslog_parse_token(
    const em_agpslog_type_enum log_type,
    const kal_char *char_p,
    const kal_char **next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_agpslog_token_enum token;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    token = EM_AGPSLOG_TOKEN_UNKNOWN;

    switch (log_type)
    {
        /* Common */
        case EM_AGPSLOG_PROCEDURE_DURATION:
            ASSIGN_IF_BEGINS(char_p, "<proc>", next, token, EM_AGPSLOG_TOKEN_PROC_NAME);
            ASSIGN_IF_BEGINS(char_p, "<ms>", next, token, EM_AGPSLOG_TOKEN_PROC_TIME);
            break;
        /* MMI */
        case EM_AGPSLOG_MMI_DATE_TIME:
            ASSIGN_IF_BEGINS(char_p, "<y>", next, token, EM_AGPSLOG_TOKEN_Y);
            ASSIGN_IF_BEGINS(char_p, "<mm>", next, token, EM_AGPSLOG_TOKEN_MM);
            ASSIGN_IF_BEGINS(char_p, "<dd>", next, token, EM_AGPSLOG_TOKEN_DD);
            ASSIGN_IF_BEGINS(char_p, "<time>", next, token, EM_AGPSLOG_TOKEN_TIME);
            break;
        case EM_AGPSLOG_MMI_BATTERY_INFO:
            ASSIGN_IF_BEGINS(char_p, "<mAh>", next, token, EM_AGPSLOG_TOKEN_U16);
            break;
        /* SUPL */
        case EM_AGPSLOG_SUPL_VERSION:
            ASSIGN_IF_BEGINS(char_p, "<major>", next, token, EM_AGPSLOG_TOKEN_SUPL_VERSION_MAJOR);
            ASSIGN_IF_BEGINS(char_p, "<minor>", next, token, EM_AGPSLOG_TOKEN_SUPL_VERSION_MINOR);
            ASSIGN_IF_BEGINS(char_p, "<serv_ind>", next, token, EM_AGPSLOG_TOKEN_SUPL_VERSION_SERV_IND);
            break;
        case EM_AGPSLOG_SUPL_SESSION_ID:
            ASSIGN_IF_BEGINS(char_p, "<s_id>", next, token, EM_AGPSLOG_TOKEN_SUPL_SESSION_ID);
            break;
        case EM_AGPSLOG_SUPL_POSITION_METHOD:
            ASSIGN_IF_BEGINS(char_p, "<method>", next, token, EM_AGPSLOG_TOKEN_SUPL_POSITION_METHOD);
            break;
        case EM_AGPSLOG_SUPL_SESSION_TYPE:
            ASSIGN_IF_BEGINS(char_p, "<s_type>", next, token, EM_AGPSLOG_TOKEN_SUPL_SESSION_TYPE);
            break;
        case EM_AGPSLOG_SUPL_MESSAGE_TYPE:
            ASSIGN_IF_BEGINS(char_p, "<dir>", next, token, EM_AGPSLOG_TOKEN_SUPL_MESSAGE_DIRECTION);
            ASSIGN_IF_BEGINS(char_p, "<msg>", next, token, EM_AGPSLOG_TOKEN_SUPL_MESSAGE_TYPE);
            break;
        case EM_AGPSLOG_SUPL_STATUS_CODE:
            ASSIGN_IF_BEGINS(char_p, "<code>", next, token, EM_AGPSLOG_TOKEN_SUPL_STATUS_CODE);
            break;
        case EM_AGPSLOG_SUPL_SLP_ADDRESS:
            ASSIGN_IF_BEGINS(char_p, "<ip>", next, token, EM_AGPSLOG_TOKEN_SUPL_SLP_IP);
            ASSIGN_IF_BEGINS(char_p, "<port>", next, token, EM_AGPSLOG_TOKEN_SUPL_SLP_PORT);
            break;
        case EM_AGPSLOG_SUPL_SSL:
            break;
        /* RRLP */
        case EM_AGPSLOG_RRLP_MESSAGE_TYPE:
            ASSIGN_IF_BEGINS(char_p, "<msg>", next, token, EM_AGPSLOG_TOKEN_RRLP_MESSAGE_TYPE);
            break;
        case EM_AGPSLOG_RRLP_ASSISTANCE_DATA_CONTENT:
            break;
        /* GPS */
        case EM_AGPSLOG_GPS_ACCURACY:
            ASSIGN_IF_BEGINS(char_p, "<accu>", next, token, EM_AGPSLOG_TOKEN_FLOAT);
            break;
        case EM_AGPSLOG_GPS_SATELLITE_INFO:
            ASSIGN_IF_BEGINS(char_p, "<sv_id>", next, token, EM_AGPSLOG_TOKEN_GPS_SATELLITE_SV_ID);
            ASSIGN_IF_BEGINS(char_p, "<strength>", next, token, EM_AGPSLOG_TOKEN_GPS_SATELLITE_STRENGTH);
            break;
        case EM_AGPSLOG_GPS_POSITION_RESULT:
            ASSIGN_IF_BEGINS(char_p, "<longi>", next, token, EM_AGPSLOG_TOKEN_GPS_POS_RESULT_LONGITUDE);
            ASSIGN_IF_BEGINS(char_p, "<lati>", next, token, EM_AGPSLOG_TOKEN_GPS_POS_RESULT_LATITUDE);
            ASSIGN_IF_BEGINS(char_p, "<alti>", next, token, EM_AGPSLOG_TOKEN_GPS_POS_RESULT_ALTITUDE);
            ASSIGN_IF_BEGINS(char_p, "<velo>", next, token, EM_AGPSLOG_TOKEN_GPS_POS_RESULT_VELOCITY);
            ASSIGN_IF_BEGINS(char_p, "<dir>", next, token, EM_AGPSLOG_TOKEN_GPS_POS_RESULT_DIRECTION);
            ASSIGN_IF_BEGINS(char_p, "<y>", next, token, EM_AGPSLOG_TOKEN_GPS_POS_RESULT_Y);
            ASSIGN_IF_BEGINS(char_p, "<mm>", next, token, EM_AGPSLOG_TOKEN_GPS_POS_RESULT_MM);
            ASSIGN_IF_BEGINS(char_p, "<dd>", next, token, EM_AGPSLOG_TOKEN_GPS_POS_RESULT_DD);
            ASSIGN_IF_BEGINS(char_p, "<time>", next, token, EM_AGPSLOG_TOKEN_GPS_POS_RESULT_TIME);
            break;
        case EM_AGPSLOG_GPS_CONNECTIVITY_STATUS:
            ASSIGN_IF_BEGINS(char_p, "<status>", next, token, EM_AGPSLOG_TOKEN_GPS_CONN_STATUS);
            break;
        case EM_AGPSLOG_GPS_START_TYPE:
            ASSIGN_IF_BEGINS(char_p, "<st_type>", next, token, EM_AGPSLOG_TOKEN_GPS_START_TYPE);
            break;
        default:
            token = EM_AGPSLOG_TOKEN_UNKNOWN;
            break;
    }

    return token;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_template_parse_line
 * DESCRIPTION
 *  Parse one line, extract log type and tokens from the line.
 * PARAMETERS
 *  buffer_p        [IN]
 *  buffer_end      [IN]
 *  line            [IN]
 *  next_buffer_p   [OUT]
 *  buffer_full     [OUT]
 *  line_number     [IN]
 *  log             [IN/OUT]
 * RETURNS
 *  em_agpslog_type_enum
 *****************************************************************************/
static em_agpslog_type_enum em_agpslog_template_parse_line(
    kal_uint8 *buffer_p,
    kal_uint8 *buffer_end,
    kal_char *line,
    kal_uint8** next_buffer_p,
    kal_bool *buffer_full,
    /* For parse log */
    const int line_number,
    em_agpslog_parse_log_struct* log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_agpslog_type_enum log_type;
    em_agpslog_token_enum token;
    kal_char* next; /* of line[] */
    kal_uint8* p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DEBUG_PARSER(("%2d: %s\n", line_number, line));

    *next_buffer_p = buffer_p;

    if (line[0] == '#' || line[0] == '\0')
    {
        return EM_AGPSLOG_TYPE_COMMENT;
    }

    log_type = em_agpslog_parse_log_type(line, (const kal_char**)(&next));
    DEBUG_PARSER(("    [%d] ", log_type));

    if (log_type == EM_AGPSLOG_TYPE_UNKNOWN)
    {
        kal_char ori_char;

        DEBUG_PARSER(("\n"));

        /* Generate parse log: Invalid Log type */
        next = line;
        while (*next != '\0' && *next != ' ' && *next != '\t')
        {
            next++;
        }
        ori_char = *next;
        *next = '\0';
        em_agpslog_append_parse_log(log, "[IL]", line, line_number);
        *next = ori_char;

        return log_type;
    }

    /* Skip spaces & tabs */
    while (*next == ' ' || *next == '\t')
    {
        next++;
    }

    p = buffer_p ;
    while (*next != '\0')
    {
        kal_char* t_next;

        if (em_agpslog_template_get_data_p(p) +
                2 * em_agpslog_template_node_overhead >= buffer_end)
        {
            /* Can not append anything */
            *buffer_full = KAL_TRUE;
            break;
        }

        /* one character look ahead */
        if (*next == '<')
        {
            token = em_agpslog_parse_token(log_type, next, (const kal_char**)(&t_next));

            if (token != EM_AGPSLOG_TOKEN_UNKNOWN)
            {
                DEBUG_PARSER(("<%d>", token));
                em_agpslog_template_set_token(p, token);
                em_agpslog_template_set_data_length(p, 0);
                em_agpslog_template_go_to_next_node(p);
                next = t_next;
            }
            else
            {
                kal_char ori_char;

                t_next = next;

                /* ignore this token */
                while (*t_next != '\0' && *t_next != '>')
                {
                    t_next++;
                }

                if (*t_next == '>')
                {
                    t_next++;
                }

                /* Generate parse log: Invalid Term */
                ori_char = *t_next;
                *t_next = '\0';
                em_agpslog_append_parse_log(log, "[IT]", next, line_number);
                *t_next = ori_char;

                next = t_next;
            }
        }
        else
        {
            kal_uint32 data_length = 0 ;
            kal_char* str_p = (kal_char*)em_agpslog_template_get_data_p(p);

            while (*next != '\0' && *next != '<')
            {
                if ((kal_uint8*)str_p + em_agpslog_template_node_overhead + 2
                        >= buffer_end)
                {
                    *buffer_full = KAL_TRUE;
                    break;
                }

                if (*next == '\\')
                {
                    kal_char follow_char = *(next+1);
                    kal_char char_rep = ' ';

                    switch (follow_char)
                    {
                        case 'b':
                            char_rep = ' ';
                            break;
                        case 't':
                            char_rep = '\t';
                            break;
                        case 'n':
                            *(str_p++) = '\r';
                            data_length++;
                            char_rep = '\n';
                            break;
                        case '\\':
                            char_rep = '\\';
                            break;
                        case '\0':
                            next--;
                            break;
                        default:
                            char_rep = follow_char;
                            break;
                    }

                    *(str_p++) = char_rep;
                    data_length++;
                    next += 2;
                }
                else
                {
                    *(str_p++) = *(next++);
                    data_length++;
                }
            }

            *(str_p++) = '\0';
            data_length++;

            DEBUG_PARSER(( "%s", (str_p - data_length) ));

            em_agpslog_template_set_token(p, EM_AGPSLOG_TOKEN_STRING);
            em_agpslog_template_set_data_length(p, data_length);
            em_agpslog_template_go_to_next_node(p);
        }
    }

    em_agpslog_template_set_token(p, EM_AGPSLOG_TOKEN_END_MARK);
    em_agpslog_template_set_data_length(p, 0);
    em_agpslog_template_go_to_next_node(p);

    *next_buffer_p = p ;
    DEBUG_PARSER(("\n"));

    return log_type;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_template_init
 * DESCRIPTION
 *  Initialize em_agpslog_template_struct. Allocate resource
 * PARAMETERS
 *  t        [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_template_init(em_agpslog_template_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Can not be initialized twice */
    ASSERT(t->inited_magic != EM_AGPSLOG_TEMPLATE_INITED_MAGIC);

    kal_mem_set(t, 0, sizeof(em_agpslog_template_struct));

    t->is_parsed = KAL_FALSE;
    t->buffer_p = (kal_uint8*)get_ctrl_buffer(EM_AGPSLOG_MAX_TEMPLATE_BUFFER);
    t->buffer_end = t->buffer_p + EM_AGPSLOG_MAX_TEMPLATE_BUFFER;

    t->inited_magic = EM_AGPSLOG_TEMPLATE_INITED_MAGIC;
}

/*****************************************************************************
 * FUNCTION
 *  em_agpslog_template_reset
 * DESCRIPTION
 *  Parse template file.
 * PARAMETERS
 *  t           [OUT] Parse result: formatting information
 *  f_hdlr      [IN]  Template file
 *  parse_log   [OUT] Parse log. User have to allocate a memory
 *                    for parse_log->log and set parse_log->log_end.
 * RETURNS
 *  KAL_TRUE if no warning
 *****************************************************************************/
kal_bool em_agpslog_template_reset(
     em_agpslog_template_struct *t,
     FS_HANDLE f_hdlr,
     em_agpslog_parse_log_struct *parse_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;
    kal_char *line;
    em_agpslog_file_struct file;
    kal_uint8 *buffer_p;
    kal_bool buffer_full;
    kal_bool complete_line;
    kal_uint32 line_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Should be initialized before */
    ASSERT(t->inited_magic == EM_AGPSLOG_TEMPLATE_INITED_MAGIC);

    for (i = 0; i < EM_AGPSLOG_TYPE_TOTAL; i++)
    {
        t->of_type[i] = NULL;
    }

    em_agpslog_file_struct_init(&file, f_hdlr);

    line = (kal_char*)get_ctrl_buffer(EM_AGPSLOG_MAX_LINE_BUFFER);

    buffer_full = KAL_FALSE;
    buffer_p = t->buffer_p;

    /* For parse log */
    line_number = 1;
    if (parse_log != NULL)
    {
        parse_log->full = KAL_FALSE;
        parse_log->log_tail = parse_log->log;
        parse_log->warning_count = 0;
    }

    while (em_agpslog_file_read_line(&file, line, EM_AGPSLOG_MAX_LINE_BUFFER, &complete_line))
    {
        em_agpslog_type_enum log_type;
        kal_uint8 *next_buffer_p = buffer_p;

        log_type = em_agpslog_template_parse_line(
            buffer_p,
            t->buffer_end,
            line,
            &next_buffer_p,
            &buffer_full,
            line_number,
            parse_log
            );

        if (buffer_full)
        {
            /* Generate parse log: too-Large-Template */
            em_agpslog_append_parse_log(parse_log, "[LT]", "Too large template.", line_number);
            break;
        }

        if (log_type < EM_AGPSLOG_TYPE_TOTAL)
        {
            if (t->of_type[log_type] == NULL)
            {
                t->of_type[log_type] = buffer_p;
                buffer_p = next_buffer_p;
            }
            else
            {
                /* Generate parse log: Re-Define */
                kal_char ori_char;
                kal_char *next;

                next = line;
                while (*next != '\0' && *next != ' ' && *next != '\t')
                {
                    next++;
                }
                ori_char = *next;
                *next = '\0';
                em_agpslog_append_parse_log(parse_log, "[RD]", line, line_number);
                *next = ori_char;
            }
        }

        if (!complete_line)
        {
            /* Swallow remaining characters of the line */
            while (em_agpslog_file_read_line(&file, line,
                EM_AGPSLOG_MAX_LINE_BUFFER, &complete_line) && !complete_line)
            {
            }

            /* Generate parse log: too-Long-Line */
            em_agpslog_append_parse_log(parse_log, "[LL]", "Too long line.", line_number);
        }

        line_number++;
    }

    t->is_parsed = KAL_TRUE;

    free_ctrl_buffer(line);

    ASSERT(buffer_p <= t->buffer_end);

    return (parse_log == NULL || parse_log->warning_count == 0 ? KAL_TRUE : KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_template_deinit
 * DESCRIPTION
 *  Finalize em_agpslog_template_struct, deallocate resource
 * PARAMETERS
 *  t        [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_template_deinit(em_agpslog_template_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Should be initialized before */
    ASSERT(t->inited_magic == EM_AGPSLOG_TEMPLATE_INITED_MAGIC);

    if (t->buffer_p != NULL)
    {
        free_ctrl_buffer(t->buffer_p);
    }

    kal_mem_set(t, 0, sizeof(em_agpslog_template_struct));

    t->is_parsed = KAL_FALSE;
    t->buffer_p = NULL;
    t->buffer_end = NULL;
}

/* --------------------------- Log system core ------------------------------ */

#if 0 /* Ring buffer */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 , ring buffer */


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_flush_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  log_buffer_p        [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_flush_buffer(em_agpslog_log_buffer_struct* log_buffer_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Write(
        log_buffer_p->log_file,
        log_buffer_p->buffer,
        log_buffer_p->tail_index,
        NULL);

    log_buffer_p->tail_index = 0;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_write
 * DESCRIPTION
 *  Write log to log buffer. Flush if buffer full.
 * PARAMETERS
 *  log_buffer_p        [IN/OUT]
 *  log_type            [IN]
 *  data                [IN]        Log data
 *  length              [IN]        Data length
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_write(
    em_agpslog_log_buffer_struct *log_buffer_p,
    em_agpslog_type_enum log_type,
    const kal_uint8 *data,
    kal_uint32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_agpslog_log_header_struct header;
    kal_uint8* buffer_tail;
    kal_uint32 new_tail_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_tail_index = log_buffer_p->tail_index + sizeof(header) + length;

    if (new_tail_index >= log_buffer_p->size)
    {
        /* flush to file, otherwise the buffer will overflow */
        em_agpslog_flush_buffer(log_buffer_p);
    }

    buffer_tail = log_buffer_p->buffer + log_buffer_p->tail_index;
    
    header.log_type = (kal_uint8)log_type;
    header.data_length = (kal_uint8)length;

    kal_mem_cpy(buffer_tail, &header, sizeof(header));
    buffer_tail += sizeof(header);
    kal_mem_cpy(buffer_tail, data, length);

    log_buffer_p->tail_index += (kal_uint16)(sizeof(header) + length);
}


/* -------------------------------- Formatter ------------------------------- */

/*****************************************************************************
 * FUNCTION
 *  em_agpslog_read_one_log_from_file
 * DESCRIPTION
 *  Extract one log from raw log file.
 * PARAMETERS
 *  file            [IN]
 *  log_type        [OUT]   Log type
 *  data            [OUT]   Log data
 *  length          [OUT]   Data length
 * RETURNS
 *  KAL_TRUE if not EOF (the output values are valid)
 *****************************************************************************/
static kal_bool em_agpslog_read_one_log_from_file(
    FS_HANDLE file,
    em_agpslog_type_enum *log_type,
    kal_uint8 *data,
    kal_uint32 *length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UINT n_read;
    em_agpslog_log_header_struct header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *log_type = EM_AGPSLOG_TYPE_UNKNOWN;
    *length = 0;

    if (FS_Read(file, &header, sizeof(header), &n_read) != FS_NO_ERROR ||
        n_read != sizeof(header))
    {
        return KAL_FALSE;
    }

    if (FS_Read(file, data, header.data_length, &n_read) != FS_NO_ERROR ||
        n_read != header.data_length)
    {
        return KAL_FALSE;
    }

    if (header.log_type >= EM_AGPSLOG_TYPE_TOTAL)
    {
        return KAL_FALSE;
    }

    *log_type = header.log_type;
    *length = header.data_length;

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_template_format_file
 * DESCRIPTION
 *  Format log file by assigned template, save result into dest.
 * PARAMETERS
 *  dest                [OUT]
 *  dest_length_max     [IN]   Size of dest
 *  log_template        [IN]   Template
 *  raw_file            [OUT]  Raw log file
 *  dest_full_callback  [IN]   If buffer(dest) full, this function will be called
 *                             Returns KAL_TRUE means allows to empty the buffer
 *                             and continue formatting.
 *  args                [IN]   Argument which will be passed to dest_full_callback
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_template_format_file(
    kal_char* dest,
    const kal_uint32 dest_length_max,
    const em_agpslog_template_struct *log_template,
    FS_HANDLE raw_file,
    kal_bool (*dest_full_callback)(void *args, kal_char* dest, const kal_uint32 length),
    void *args /* pass to dest_full_callback */
    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_agpslog_type_enum log_type;
    kal_uint32 data_length;
    kal_uint32 t_data[EM_AGPSLOG_MAX_LOG_SIZE/sizeof(kal_uint32)]; /* 4-byte aligned */
    kal_uint8 *data;
    kal_char* dest_tail;
    kal_uint32 dest_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(log_template->inited_magic == EM_AGPSLOG_TEMPLATE_INITED_MAGIC);
    ASSERT(log_template->is_parsed && log_template->buffer_p != NULL);

    DEBUG_FORMATTER(("Formatter:\n"));

    data = (kal_uint8*)t_data;
    dest_tail = dest;
    *dest_tail = '\0';
    dest_length = 0;

    while (em_agpslog_read_one_log_from_file(raw_file, &log_type, data, &data_length))
    {
        typedef union {
            kal_char string[1];
            applib_time_struct time;
            kal_uint8 val_of_u8[3];
            kal_uint16 val_of_u16[3];
            float val_of_float[3];
            em_agpslog_network_address_struct nw_addr;
            em_agpslog_position_result_struct pos_result;
        } data_union;

        const kal_uint8* p = NULL;
        const data_union* u = (data_union*)data;

        if (log_type < EM_AGPSLOG_TYPE_TOTAL)
        {
            p = log_template->of_type[log_type];

            if (p == NULL)
            {
                continue;
            }
        }
        else
        {
            continue;
        }

        while (1)
        {
            kal_uint32 append_length;
            em_agpslog_token_enum token = em_agpslog_template_get_token(p);
            kal_uint32 data_length = em_agpslog_template_get_data_length(p);
            const kal_char* str_of_p = (kal_char*)em_agpslog_template_get_data_p(p);

            ASSERT(dest_length < dest_length_max);

            if (token == EM_AGPSLOG_TOKEN_END_MARK)
            {
                break;
            }

            if ( dest_length + data_length >= dest_length_max ||
                dest_length + EM_AGPSLOG_MAX_FORMATTED_TOKEN_LENGTH >= dest_length_max)
            {
                /* dest buffer full */
                if (dest_full_callback == NULL ||
                    dest_full_callback(args, dest, dest_length) == KAL_FALSE)
                {
                    if (data_length + 5 <= dest_length_max)
                    {
                        em_agpslog_strcpy(dest_tail, "...");
                        append_length = em_agpslog_strlen(dest_tail);
                        dest_tail += append_length;
                        dest_length += append_length;
                    }
                    goto em_agpslog_format_file_by_template_tokeninate;
                }
                else /* dest_full_callback() returns KAL_TRUE */
                {
                    *dest_tail = '\0';
                    dest_tail = dest;
                    dest_length = 0;
                }
            }

            /* NOTE: We have to make sure the lengths of all formatted string
                     smaller than EM_AGPSLOG_MAX_FORMATTED_TOKEN_LENGTH */
            switch (token)
            {
                /* General */
                case EM_AGPSLOG_TOKEN_STRING:
                    em_agpslog_strcpy(dest_tail, str_of_p);
                    break;
                case EM_AGPSLOG_TOKEN_PROC_NAME:
                    em_agpslog_strcpy(dest_tail, em_agpslog_get_proc_name_string(u->val_of_u16[0]));
                    break;
                case EM_AGPSLOG_TOKEN_PROC_TIME:
                    em_agpslog_itoa(dest_tail, u->val_of_u16[1], 0);
                    break;
                case EM_AGPSLOG_TOKEN_U8:
                    em_agpslog_itoa(dest_tail, u->val_of_u8[0], 0);
                    break;
                case EM_AGPSLOG_TOKEN_U16:
                    em_agpslog_itoa(dest_tail, u->val_of_u16[0], 0);
                    break;
                case EM_AGPSLOG_TOKEN_FLOAT:
                    em_agpslog_format_float(dest_tail, u->val_of_float[0]);
                    break;
                case EM_AGPSLOG_TOKEN_Y:
                    em_agpslog_itoa(dest_tail, u->time.nYear, 0);
                    break;
                case EM_AGPSLOG_TOKEN_MM:
                    em_agpslog_itoa(dest_tail, u->time.nMonth, 2);
                    break;
                case EM_AGPSLOG_TOKEN_DD:
                    em_agpslog_itoa(dest_tail, u->time.nDay, 2);
                    break;
                case EM_AGPSLOG_TOKEN_TIME:
                    em_agpslog_format_time(dest_tail, u->time.nHour, u->time.nMin, u->time.nSec);
                    break;
                /* SUPL */
                case EM_AGPSLOG_TOKEN_SUPL_VERSION_MAJOR:
                    em_agpslog_itoa(dest_tail, u->val_of_u8[0], 0);
                    break;
                case EM_AGPSLOG_TOKEN_SUPL_VERSION_MINOR:
                    em_agpslog_itoa(dest_tail, u->val_of_u8[1], 0);
                    break;
                case EM_AGPSLOG_TOKEN_SUPL_VERSION_SERV_IND:
                    em_agpslog_itoa(dest_tail, u->val_of_u8[2], 0);
                    break;
                case EM_AGPSLOG_TOKEN_SUPL_SESSION_ID:
                    em_agpslog_strcpy(dest_tail, u->string);
                    break;
                case EM_AGPSLOG_TOKEN_SUPL_POSITION_METHOD:
                    em_agpslog_strcpy(dest_tail, em_agpslog_get_supl_pos_mth_string(u->val_of_u8[0]));
                    break;
                case EM_AGPSLOG_TOKEN_SUPL_SESSION_TYPE:
                    em_agpslog_strcpy(dest_tail, em_agpslog_get_supl_session_type_string(u->val_of_u8[0]));
                    break;
                case EM_AGPSLOG_TOKEN_SUPL_MESSAGE_DIRECTION:
                    em_agpslog_strcpy(dest_tail, em_agpslog_get_direction_string(u->val_of_u8[0]));
                    break;
                case EM_AGPSLOG_TOKEN_SUPL_MESSAGE_TYPE:
                    em_agpslog_strcpy(dest_tail, em_agpslog_get_supl_message_type_string(u->val_of_u8[1]));
                    break;
                case EM_AGPSLOG_TOKEN_SUPL_STATUS_CODE:
                    em_agpslog_strcpy(dest_tail, em_agpslog_get_supl_status_string(u->val_of_u8[0]));
                    break;
                case EM_AGPSLOG_TOKEN_SUPL_SLP_IP:
                    em_agpslog_format_ip_addr(dest_tail, &(u->nw_addr));
                    break;
                case EM_AGPSLOG_TOKEN_SUPL_SLP_PORT:
                    em_agpslog_itoa(dest_tail, u->nw_addr.port, 0);
                    break;
                /* RRLP */
                case EM_AGPSLOG_TOKEN_RRLP_MESSAGE_TYPE:
                    em_agpslog_strcpy(dest_tail, em_agpslog_get_rrlp_message_type_string(u->val_of_u8[0]));
                    break;
                /* GPS */
                case EM_AGPSLOG_TOKEN_GPS_SATELLITE_SV_ID:
                    em_agpslog_itoa(dest_tail, u->val_of_u16[0], 0);
                    break;
                case EM_AGPSLOG_TOKEN_GPS_SATELLITE_STRENGTH:
                    em_agpslog_itoa(dest_tail, u->val_of_u16[1], 0);
                    break;
                case EM_AGPSLOG_TOKEN_GPS_POS_RESULT_LONGITUDE:
                    em_agpslog_format_float(dest_tail, u->pos_result.longitude);
                    break;
                case EM_AGPSLOG_TOKEN_GPS_POS_RESULT_LATITUDE:
                    em_agpslog_format_float(dest_tail, u->pos_result.latitude);
                    break;
                case EM_AGPSLOG_TOKEN_GPS_POS_RESULT_ALTITUDE:
                    em_agpslog_format_float(dest_tail, u->pos_result.altitude);
                    break;
                case EM_AGPSLOG_TOKEN_GPS_POS_RESULT_VELOCITY:
                    em_agpslog_format_float(dest_tail, u->pos_result.velocity);
                    break;
                case EM_AGPSLOG_TOKEN_GPS_POS_RESULT_DIRECTION:
                    em_agpslog_format_float(dest_tail, u->pos_result.direction);
                    break;
                case EM_AGPSLOG_TOKEN_GPS_POS_RESULT_Y:
                    em_agpslog_itoa(dest_tail, u->pos_result.time.nYear, 0);
                    break;
                case EM_AGPSLOG_TOKEN_GPS_POS_RESULT_MM:
                    em_agpslog_itoa(dest_tail, u->pos_result.time.nMonth, 2);
                    break;
                case EM_AGPSLOG_TOKEN_GPS_POS_RESULT_DD:
                    em_agpslog_itoa(dest_tail, u->pos_result.time.nDay, 2);
                    break;
                case EM_AGPSLOG_TOKEN_GPS_POS_RESULT_TIME:
                    em_agpslog_format_time(
                        dest_tail,
                        u->pos_result.time.nHour,
                        u->pos_result.time.nMin,
                        u->pos_result.time.nSec);
                    break;
                case EM_AGPSLOG_TOKEN_GPS_CONN_STATUS:
                    em_agpslog_strcpy(dest_tail, em_agpslog_get_gps_conn_status_string(u->val_of_u8[0]));
                    break;
                case EM_AGPSLOG_TOKEN_GPS_START_TYPE:
                    em_agpslog_strcpy(dest_tail, em_agpslog_get_gps_start_type_string(u->val_of_u8[0]));
                    break;
                default:
                    em_agpslog_strcpy(dest_tail, "");
                    break;
            }

            append_length = em_agpslog_strlen(dest_tail);
            dest_tail += append_length;
            dest_length += append_length;

            em_agpslog_template_go_to_next_node(p);
        }

        *(dest_tail++) = '\r';
        *(dest_tail++) = '\n';
        dest_length += 2;
    }

em_agpslog_format_file_by_template_tokeninate:

    *dest_tail = '\0';
}


/* -------------------------------- Utility --------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  em_agpslog_string_begins
 * DESCRIPTION
 *  Does str begin with pattern?
 * PARAMETERS
 *  str            [IN]
 *  pattern        [IN]
 *  next           [OUT] Pointer points to the char after the pattern in str
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool em_agpslog_string_begins(
    const kal_char *str,
    const kal_char *pattern,
    const kal_char **next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_char *i, *j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = str;
    j = pattern;
    while (*i && *j && *i == *j)
    {
        i++;
        j++;
    }

    if (*j == '\0')
    {
        *next = i;
        return KAL_TRUE;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_format_time
 * DESCRIPTION
 *  Format time as "hh:mm:ss"
 * PARAMETERS
 *  time_str        [OUT]
 *  hour            [IN]
 *  min             [IN]
 *  sec             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_format_time(
    kal_char* time_str,
    kal_uint8 hour,
    kal_uint8 min,
    kal_uint8 sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    em_agpslog_itoa(time_str, hour, 0);
    time_str += em_agpslog_strlen(time_str);
    *(time_str++) = ':';
    em_agpslog_itoa(time_str, min, 2);
    time_str += 2;
    *(time_str++) = ':';
    em_agpslog_itoa(time_str, sec, 2);
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_format_ip_addr
 * DESCRIPTION
 *  Format the IP address in addr as "a.b.c.d"
 * PARAMETERS
 *  ip_str        [OUT]
 *  addr          [IN]  Network address
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_format_ip_addr(
    kal_char* ip_str, 
    const em_agpslog_network_address_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    const kal_uint8 *ip;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ip = addr->ip;

    if (addr->addr_len > 0)
    {
        em_agpslog_itoa(ip_str, ip[0], 0);
        for (i = 1; i < addr->addr_len; i++)
        {
            ip_str += em_agpslog_strlen(ip_str);
            *(ip_str++) = '.';
            em_agpslog_itoa(ip_str, ip[i], 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_strlen
 * DESCRIPTION
 *  strlen
 * PARAMETERS
 *  str        [IN]
 * RETURNS
 *  kal_uint32: string length
 *****************************************************************************/
kal_uint32 em_agpslog_strlen(const kal_char *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    register const kal_char *str_p;
    register kal_uint32 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_p = str;
    length = 0;

    while (*str_p)
    {
        str_p++;
        length++;
    }

    return length;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_strcpy
 * DESCRIPTION
 *  strcpy
 * PARAMETERS
 *  dest        [OUT]
 *  src         [IN]
 * RETURNS
 *  dest
 *****************************************************************************/
kal_char* em_agpslog_strcpy(kal_char *dest, const kal_char *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    register const kal_char *src_p;
    register kal_char *dest_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_p = dest;
    src_p = src;
    while (*src_p)
    {
        *(dest_p++) = *(src_p++);
    }

    *dest_p = '\0';

    return dest;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_itoa
 * DESCRIPTION
 *  itoa
 * PARAMETERS
 *  str         [OUT]
 *  val         [IN]
 *  n_digits    [IN]  At lease n_digits digits, fill with '0'
 * RETURNS
 *  str
 *****************************************************************************/
kal_char* em_agpslog_itoa(
    kal_char* str,
    const kal_uint32 val,
    const kal_uint32 n_digits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *str_p;
    kal_char buffer[14];
    kal_uint32 buffer_i;
    kal_uint32 t_val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buffer_i = 0;
    t_val = val;
    while (t_val > 0)
    {
        buffer[buffer_i++] = (kal_uint8)('0' + (t_val % 10));
        t_val /= 10;
    }

    while (buffer_i < n_digits && buffer_i < sizeof(buffer))
    {
        buffer[buffer_i++] = '0';
    }

    /* reverse & copy to str */
    str_p = str;
    while (buffer_i > 0)
    {
        buffer_i--;
        *(str_p++) = buffer[buffer_i];
    }

    if ( str_p == str )
    {
        *(str_p++) = '0';
    }

    *str_p = '\0';

    return str;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_format_float
 * DESCRIPTION
 *  Format floating point value as "i.ffff"
 * PARAMETERS
 *  str         [OUT]
 *  val         [IN]
 * RETURNS
 *  str
 *****************************************************************************/
kal_char* em_agpslog_format_float(kal_char* str, const float val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *str_p;
    kal_uint32 integer_part, fraction_part;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_p = str;

    /* We have to use division & floating operations as less as possible */
    /* Assume val's degree near 0 */
    if ( val < 0 )
    {
        *(str_p++) = '-'; /* negative sign */
        fraction_part = (kal_uint32)(val * -10000.0f + 0.5f);
    }
    else
    {
        fraction_part = (kal_uint32)(val * 10000.0f + 0.5f);
    }

    integer_part = fraction_part / 10000;
    fraction_part = fraction_part - (integer_part * 10000);

    em_agpslog_itoa(str_p, integer_part, 0);
    str_p += em_agpslog_strlen(str_p);
    *(str_p++) = '.';
    em_agpslog_itoa(str_p, fraction_part, 4);

    return str;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_file_read_line
 * DESCRIPTION
 *  Read one line from file. line[] will not contain '\n' or '\r'.
 * PARAMETERS
 *  file_p          [IN/OUT]
 *  line            [OUT]
 *  line_max        [IN]        Size of line buffer
 *  complete_line   [OUT]       Returned line[] is whole line?
 * RETURNS
 *  EOF? (all output values are invalid if KAL_FALSE)
 *****************************************************************************/
kal_bool em_agpslog_file_read_line(
    em_agpslog_file_struct* file_p,
    kal_char *line,
    kal_uint32 line_max,
    kal_bool *complete_line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;
    kal_uint32 line_tail;
    kal_uint32 n_read;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *complete_line = KAL_FALSE;
    line_max--; /* to contain tail '\0' */

    if (file_p->eof && file_p->buffer_tail == 0)
    {
        return KAL_FALSE;
    }

    line_tail = 0;

    if (file_p->buffer_tail > 0)
    {
        kal_char* buffer = file_p->buffer;
        kal_uint32 buffer_tail = file_p->buffer_tail;

        /* Copy bufferred data to line[] */
        for (i = 0; line_tail < line_max && i < buffer_tail; i++)
        {
            if (buffer[i] == '\n')
            {
                break;
            }
            else if (buffer[i] == '\r')
            {
                /* ignore */
            }
            else
            {
                line[line_tail++] = buffer[i];
            }
        }

        if (i < buffer_tail)
        {
            kal_uint32 j;

            /* Move remaining data to buffer head.
               Inefficient, but easy to be maintained. */
            // TODO: To be more efficent
            i++; /* Swallow '\n' */
            j = 0;
            while (i < buffer_tail)
            {
                buffer[j++] = buffer[i++];
            }

            buffer_tail = j;
            file_p->buffer_tail = (kal_uint16)buffer_tail;

            /* There are data in buffer,
               we have read one line completely. */
            line[line_tail++] = '\0';
            *complete_line = KAL_TRUE;

            return KAL_TRUE;
        }
        else /* i == buffer_tail */
        {
            /* We have consume all buffer data */
            buffer_tail = 0;
            file_p->buffer_tail = 0;
        }
    }

    /* Currently, file_p->tail == 0 */

    FS_Read(file_p->handler,
        (line + line_tail),
        (line_max - line_tail),
        &n_read);

    if (n_read < (line_max - line_tail))
    {
        *complete_line = KAL_TRUE;
        file_p->eof = KAL_TRUE;
    }

    if ( line_tail == 0 && n_read == 0 && file_p->buffer_tail == 0)
    {
        line[line_tail++] = '\0';
        return KAL_FALSE;
    }

    /* Check new-line in read data */
    i = line_tail;
    line_tail += n_read;
    line[line_tail] = '\0';
    for (; i < line_tail; i++)
    {
        if (line[i] == '\r')
        {
            line[i] = '\0';
        }
        else if (line[i] == '\n')
        {
            kal_char* buffer;
            kal_uint32 buffer_tail;

            line[i] = '\0';
            i++; /* swallow '\n' ('\0' currently) */

            /* Rewind characters after the '\n' into buffer */
            buffer = file_p->buffer;
            buffer_tail = 0;
            while (i < line_tail)
            {
                buffer[buffer_tail++] = line[i++];
            }

            file_p->buffer_tail = (kal_uint16)buffer_tail;
            *complete_line = KAL_TRUE;

            break;
        }
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_file_struct_init
 * DESCRIPTION
 *  Initialize em_agpslog_file_struct. Be sure to init em_agpslog_file_struct
 *  before calling em_agpslog_file_read_line().
 * PARAMETERS
 *  file          [OUT]
 *  f_hdlr        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_file_struct_init(em_agpslog_file_struct* file, FS_HANDLE f_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    file->handler = f_hdlr;
    file->buffer = (kal_char*)get_ctrl_buffer(EM_AGPSLOG_MAX_LINE_BUFFER);
    file->buffer_tail = 0;
    file->size = EM_AGPSLOG_MAX_LINE_BUFFER;
    file->eof = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_file_struct_deinit
 * DESCRIPTION
 *  Finalize em_agpslog_file_struct.
 * PARAMETERS
 *  file          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_file_struct_deinit(em_agpslog_file_struct* file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    free_ctrl_buffer(file->buffer);
    file->buffer = NULL;
}

#endif /* __AGPS_LOG_SUPPORT__ */
