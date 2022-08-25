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
 * applib_html.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is intended for html related operations.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <ctype.h>
#include "string.h"
#include "wchar.h"
#include "kal_general_types.h"
#include "app_html.h"
#include "app_str.h"

/****************************************************************************** 
 * Configuration
 ******************************************************************************/

/* 
 * APPLIB_HTML_MAX_CONTINUOUS_LINE_FEED defines the maximum number of continuous
 * line feeds allowed in the extracted plaintext. 
 * 
 * The default value of APPLIB_HTML_MAX_CONTINUOUS_LINE_FEED is 2. This setting 
 * can be configurable by the customer. 
 *
 * If the customer does not want to add limitation to limit the maximum number 
 * of the ontinuous line feeds, set APPLIB_HTML_MAX_CONTINUOUS_LINE_FEED as (-1). 
 */
#define APPLIB_HTML_MAX_CONTINUOUS_LINE_FEED (2)


/* 
 * APPLIB_HTML_MAX_CONTINUOUS_SPACE defines the maximum number of continuous 
 * tabs/spaces allowed in the extracted plaintext.
 *
 * The default value of APPLIB_HTML_MAX_CONTINUOUS_SPACE is 1. This setting can 
 * be configurable by the customer. 
 *
 * If the customer doesn't want to add limitation to restrict the maximum number 
 * of the continuous tabs/spaces, set APPLIB_HTML_MAX_CONTINUOUS_SPACE as (-1).
 */
#define APPLIB_HTML_MAX_CONTINUOUS_SPACE     (1)


/****************************************************************************** 
 * Constant
 ******************************************************************************/

#define APPLIB_HTML_START_TAG_STYLE          "STYLE"
#define APPLIB_HTML_END_TAG_STYLE            "/STYLE"
#define APPLIB_HTML_START_TAG_SCRIPT         "SCRIPT"
#define APPLIB_HTML_END_TAG_SCRIPT           "/SCRIPT"

#define APPLIB_HTML_OPEN_BRACKET             '<'
#define APPLIB_HTML_CLOSE_BRACKET            '>'
#define APPLIB_HTML_HYPHEN                   '-'
#define APPLIB_HTML_EXCLAMATION_MARK         '!'
#define APPLIB_HTML_AMPERSAND                '&'
#define APPLIB_HTML_SEMICOLON                ';'
#define APPLIB_HTML_CARRIAGE_RETURN          '\r'
#define APPLIB_HTML_LINE_FEED                '\n'
#define APPLIB_HTML_TAB                      '\t'
#define APPLIB_HTML_SPACE                    ' '

#define APPLIB_HTML_LENGTH_START_TAG_COMMENT (4)  /* "<!--"    */
#define APPLIB_HTML_LENGTH_START_TAG_STYLE   (5)  /* "STYLE"   */
#define APPLIB_HTML_LENGTH_END_TAG_STYLE     (6)  /* "/STYLE"  */
#define APPLIB_HTML_LENGTH_START_TAG_SCRIPT  (6)  /* "SCRIPT"  */
#define APPLIB_HTML_LENGTH_END_TAG_SCRIPT    (7)  /* "/SCRIPT" */


/***************************************************************************** 
 * Defines
 *****************************************************************************/
#ifdef MIN
#undef MIN
#endif
#define MIN(A,B)	                         (((A)<(B))?(A):(B))

/****************************************************************************** 
 * ENUM
 ******************************************************************************/
typedef enum
{
    /* <P> or </P> */
    APPLIB_HTML_BLOCK_TAG_P_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_P_END_ENUM,

    /* <BR> or <BR/> */
    APPLIB_HTML_BLOCK_TAG_BR_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_BR_EMPTY_ENUM,

    /* <H1>, </H1>, <H2>, </H2>, <H3>, </H3>, <H4>, </H4>, <H5>, </H5>, <H6> or </H6> */
    APPLIB_HTML_BLOCK_TAG_H1_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_H1_END_ENUM,
    APPLIB_HTML_BLOCK_TAG_H2_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_H2_END_ENUM,
    APPLIB_HTML_BLOCK_TAG_H3_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_H3_END_ENUM,
    APPLIB_HTML_BLOCK_TAG_H4_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_H4_END_ENUM,
    APPLIB_HTML_BLOCK_TAG_H5_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_H5_END_ENUM,
    APPLIB_HTML_BLOCK_TAG_H6_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_H6_END_ENUM,

    /* <UL>, </UL>, <OL>, </OL>, <LI> or </LI> */
    APPLIB_HTML_BLOCK_TAG_UL_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_UL_END_ENUM,
    APPLIB_HTML_BLOCK_TAG_OL_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_OL_END_ENUM,
    APPLIB_HTML_BLOCK_TAG_LI_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_LI_END_ENUM,

    /* <DL>, </DL>, <DT>, </DT>, <DD> or </DD> */
    APPLIB_HTML_BLOCK_TAG_DL_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_DL_END_ENUM,
    APPLIB_HTML_BLOCK_TAG_DT_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_DT_END_ENUM,
    APPLIB_HTML_BLOCK_TAG_DD_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_DD_END_ENUM,

    /* <TABLE>, </TABLE>, <TR> or </TR> */
    APPLIB_HTML_BLOCK_TAG_TABLE_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_TABLE_END_ENUM,
    APPLIB_HTML_BLOCK_TAG_TR_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_TR_END_ENUM,

    /* <DIV>, </DIV>, <FORM>, </FORM>, <TEXTAREA> or </TEXTAREA> */
    APPLIB_HTML_BLOCK_TAG_DIV_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_DIV_END_ENUM,
    APPLIB_HTML_BLOCK_TAG_FORM_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_FORM_END_ENUM,
    APPLIB_HTML_BLOCK_TAG_TEXTAREA_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_TEXTAREA_END_ENUM,

    /* <HR>, <HR/>, <ADDRESS>, </ADDRESS>, <BLOCKQUOTE> or </BLOCKQUOTE> */
    APPLIB_HTML_BLOCK_TAG_HR_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_HR_EMPTY_ENUM,
    APPLIB_HTML_BLOCK_TAG_ADDRESS_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_ADDRESS_END_ENUM,
    APPLIB_HTML_BLOCK_TAG_BLOCKQUOTE_START_ENUM,
    APPLIB_HTML_BLOCK_TAG_BLOCKQUOTE_END_ENUM,

    APPLIB_HTML_BLCOK_TAG_END_OF_ENUM
} applib_html_block_tag_enum;

/****************************************************************************** 
 * Type Definition
 ******************************************************************************/
typedef struct
{
    char *tag_name;
    kal_uint8 tag_size;
} applib_html_block_tag_struct;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static const applib_html_block_tag_struct applib_html_block_tag_table[APPLIB_HTML_BLCOK_TAG_END_OF_ENUM] = 
{
    /* <P> or </P> */
    {"P", 1},
    {"/P", 2},

    /* <BR> or <BR/> */
    {"BR", 2},
    {"BR/", 3},

    /* <H1>, </H1>, <H2>, </H2>, <H3>, </H3>, <H4>, </H4>, <H5>, </H5>, <H6> or </H6> */
    {"H1", 2},
    {"/H1", 3},
    {"H2", 2},
    {"/H2", 3},
    {"H3", 2},
    {"/H3", 3},
    {"H4", 2},
    {"/H4", 3},
    {"H5", 2},
    {"/H5", 3},
    {"H6", 2},
    {"/H6", 3},

    /* <UL>, </UL>, <OL>, </OL>, <LI> or </LI> */
    {"UL", 2},
    {"/UL", 3},
    {"OL", 2},
    {"/OL", 3},
    {"LI", 2},
    {"/LI", 3},

    /* <DL>, </DL>, <DT>, </DT>, <DD> or </DD> */
    {"DL", 2},
    {"/DL", 3},
    {"DT", 2},
    {"/DT", 3},
    {"DD", 2},
    {"/DD", 3},

    /* <TABLE>, </TABLE>, <TR> or </TR> */
    {"TABLE", 5},
    {"/TABLE", 6},
    {"TR", 2},
    {"/TR", 3},

    /* <DIV>, </DIV>, <FORM>, </FORM>, <TEXTAREA> or </TEXTAREA> */
    {"DIV", 3},
    {"/DIV", 4},
    {"FORM", 4},
    {"/FORM", 5},
    {"TEXTAREA", 8},
    {"/TEXTAREA", 9},

    /* <HR>, <HR/>, <ADDRESS>, </ADDRESS>, <BLOCKQUOTE> or </BLOCKQUOTE> */
    {"HR", 2},
    {"HR/", 3},
    {"ADDRESS", 7},
    {"/ADDRESS", 8},
    {"BLOCKQUOTE", 10},
    {"/BLOCKQUOTE", 11}
};

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
static void applib_html_check_comment_beginning(
                applib_html_plaintext_context_struct *context,
                kal_uint8 *input_data,
                kal_uint32 index);
static void applib_html_check_comment_ending(
                applib_html_plaintext_context_struct *context,
                kal_uint8 *input_data,
                kal_uint32 index);
static void applib_html_check_all_tags(
                applib_html_plaintext_context_struct *context,
                kal_uint8 *input_data,
                kal_uint32 index);
static void applib_html_check_block_tags(
                applib_html_plaintext_context_struct *context,
                kal_uint8 *input_data,
                kal_uint32 index);
static kal_bool applib_html_check_single_tag(
                    applib_html_plaintext_context_struct *context,
                    kal_uint8 *input_data,
                    kal_uint32 index,
                    kal_uint8 *tag_name,
                    kal_uint32 tag_size);
static kal_bool applib_html_compare_tag_name(
                    kal_uint8 *data,
                    kal_uint32 size,
                    kal_uint8 *tag_name,
                    kal_uint32 tag_size);
static kal_bool applib_html_write_data_into_buffer(
					applib_html_plaintext_context_struct *context,
                    kal_uint8 *data,
                    kal_uint32 data_size,
                    kal_uint8 *output_buf,
                    kal_uint32 *output_size,
                    kal_uint32 *write_size,
                    kal_uint32 *read_size,
                    kal_uint32 read_pos,
                    kal_uint8 force_write);
static void applib_html_reset_incomplete_buffer(applib_html_plaintext_context_struct *context);
static void applib_html_adjust_output_info(
                applib_html_plaintext_context_struct *context,
                kal_uint8 *input_data,
                kal_uint32 input_size,
                kal_uint8 *output_buf,
                kal_uint32 *output_size,
                kal_uint32 *write_size,
                kal_uint32 *read_size);


/*****************************************************************************
 * FUNCTION
 *  applib_html_extract_plaintext_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  context         [IN/OUT]        The plaintext context. 
 * RETURNS
 *  void
 *****************************************************************************/
void applib_html_extract_plaintext_init(applib_html_plaintext_context_struct *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(context, 0x0, sizeof(applib_html_plaintext_context_struct));
}


/*****************************************************************************
 * FUNCTION
 *  applib_html_extract_plaintext_parse
 * DESCRIPTION
 *  
 * PARAMETERS
 *  context         [IN]            The plaintext context. 
 *  is_final        [IN]            Indicate the input data is the last part of 
 *                                  HTML or not.
 *  input_data      [IN]            The input UTF-8 encoded HTML formatted data.
 *  input_size      [IN]            Size of the input data.
 *  output_buf      [IN/OUT]        The output buffer. It is used to save the 
 *                                  extracted plain text data (UTF-8 encoded).
 *  output_size     [IN/OUT]        In the beginning, it is used to indicate the
 *                                  size of the output buffer. After extraction, 
 *                                  it is also used to indicate the size of the 
 *                                  extracted plaintext data.
 *  read_size       [OUT]           The total input size to be read.
 * RETURNS
 *  
 *****************************************************************************/
kal_bool applib_html_extract_plaintext_parse(
            applib_html_plaintext_context_struct *context,
            kal_uint8 is_final,
            kal_uint8 *input_data,
            kal_uint32 input_size,
            kal_uint8 *output_buf,
            kal_uint32 *output_size,
            kal_uint32 *read_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;
    kal_uint32 write_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (context == NULL ||
        input_data == NULL ||
        input_size == 0 || 
        output_buf == NULL || 
        output_size == NULL || 
        *output_size == 0 || 
        read_size == NULL)
    {
        return KAL_FALSE;
    }

    if (is_final == 0)
    {
        if (input_size < APPLIB_HTML_MAX_CHARACTER_ENTITY_NAME_LENGTH ||
            *output_size < APPLIB_HTML_MAX_CHARACTER_ENTITY_NAME_LENGTH)
        {
            /* 
             * If the input data is not the last part of HTML, then both of the
             * size of the input data and output buffer should be at least
             * APPLIB_HTML_MAX_CHARACTER_ENTITY_NAME_LENGTH (10).
             */
            return KAL_FALSE;
        }
    }

    *read_size = 0;
    memset(output_buf, 0x0, *output_size);

    for (i = 0; i < input_size; i++)
    {

        kal_uint8 *cur_data = input_data + i;

        if (context->open_bracket == 0 &&
            context->open_entity == 0 &&
            context->open_tag[APPLIB_HTML_COMMENT_ENUM] == 0 &&
            context->open_tag[APPLIB_HTML_STYLE_ENUM] == 0 && 
            context->open_tag[APPLIB_HTML_SCRIPT_ENUM] == 0)
        {
            /* 
             * "context->open_tag[APPLIB_HTML_COMMENT_ENUM] == 0" means it is 
             * outside comment.
             *
             * "context->open_tag[APPLIB_HTML_STYLE_ENUM] == 0" means it is
             * outside style sheets.
             *
             * "context->open_tag[APPLIB_HTML_SCRIPT_ENUM] == 0" means it is
             * outsude scripts.
             *
             * "context->open_bracket == 0" means it is outside tag.
             *
             * "context->open_entity == 0" means it is outside a character
             * entity reference.
             *
             * Therefore, the current character is in general mode (outside 
             * comment, style and script). Also, it is outside tag and outside
             * character entity reference.
             */

            if (context->open_tag[APPLIB_HTML_BLOCK_ELEMENT_ENUM] != 0)
            {
                /* If HTML block element is detected, insert a line feed. */
                kal_uint8 data = APPLIB_HTML_LINE_FEED;

                if (KAL_FALSE == applib_html_write_data_into_buffer(
									context,
                                    &data,
                                    1,
                                    output_buf,
                                    output_size,
                                    &write_size,
                                    read_size,
                                    i,
                                    KAL_FALSE))
                {
                    /* Output buffer is full. */
                    return KAL_TRUE;
                }
                else
                {
                    /* After writing a line feed, reset flag. */
                    context->open_tag[APPLIB_HTML_BLOCK_ELEMENT_ENUM] = 0;
                }
            }

            if (*cur_data == APPLIB_HTML_TAB)
            {
                /* If the current character is a tab ('\t'), replace it as a space (' '). */
                kal_uint8 data = APPLIB_HTML_SPACE;

                if (KAL_FALSE == applib_html_write_data_into_buffer(
									context,
                                    &data,
                                    1,
                                    output_buf,
                                    output_size,
                                    &write_size,
                                    read_size,
                                    i,
                                    KAL_FALSE))
                {
                    /* Output buffer is full. */
                    return KAL_TRUE;
                }
            }

            else if (*cur_data != APPLIB_HTML_OPEN_BRACKET && 
				     *cur_data != APPLIB_HTML_AMPERSAND &&
                     *cur_data != APPLIB_HTML_CARRIAGE_RETURN && 
                     *cur_data != APPLIB_HTML_LINE_FEED)
            {
                /* 
                 * If the current character is not '<', '&', '\r' and '\n', 
                 * write it into output buffer. 
                 */
                if (KAL_FALSE == applib_html_write_data_into_buffer(
									context,
                                    cur_data,
                                    1,
                                    output_buf,
                                    output_size,
                                    &write_size,
                                    read_size,
                                    i,
                                    KAL_FALSE))
                {
                    /* Output buffer is full. */
                    return KAL_TRUE;
                }
            }
        }

        switch (*cur_data)
        {
            case APPLIB_HTML_HYPHEN: /* '-' */
				
            /* '-' is a possbile ending of comment ending pattern ("<!--"). */

                if (context->open_tag[APPLIB_HTML_COMMENT_ENUM] == 0)
                {
                    /* 
                     * "context->open_tag[APPLIB_HTML_COMMENT_ENUM] == 0" means
                     * it is not in comment mode (ie. it is outside comment). 
                     *
                     * In general/style/script mode, we need to check if we need
                     * to enter comment ("<!--") or not. 
                     */
                    applib_html_check_comment_beginning(context, input_data, i);
                }
                break;

            case APPLIB_HTML_OPEN_BRACKET:  /* '<' */

            /* 
             * '<' is a possbile beginning of tag ("<TAG_NAME>"). It is invalid 
             * inside a character entity reference. 
             */
             
                if (context->open_entity != 0)
                {
                    /* 
                     * "context->open_entity != 0" means the current character 
                     * is inside a possibile character entity reference and 
                     * *(input_data + context->pos) is '&'.
                     * 
                     * '<' is invalid within a character entity reference, so 
                     * the possible character entity reference "&abc<..." is 
                     * invliad; we need to write this data into output buffer.
                     */

                    kal_uint32 size = i - context->pos;

                    /* Reset flag because this character entity reference is invalid. */
                    context->open_entity = 0;

                    /* Write the invalid character reference "&ab" into output buffer. */
                    if (KAL_FALSE == applib_html_write_data_into_buffer(
										context,
                                        input_data + context->pos,
                                        size,
                                        output_buf,
                                        output_size,
                                        &write_size,
                                        read_size,
                                        context->pos,
                                        KAL_TRUE))
                    {
                        /* 
                         * Output buffer is not enough; adjust *read_size based
                         * on the output buffer status to force re-send the 
                         * necessary data in the next time. 
                         */
                        return KAL_TRUE;
                    }
                }

                if (context->open_tag[APPLIB_HTML_COMMENT_ENUM] == 0)
                {
                    /* 
                     * "context->open_tag[APPLIB_HTML_COMMENT_ENUM] == 0" means
                     * it is not in comment mode. In general/style/script mode,
                     * tag checking is necessary. So we need to check if the 
                     * current character '<' is the beginning of tag or not.
                     *
                     * The first character of a tag name should not be '<', '>',
                     * or any whitespace.
                     */

                    if (i + 1 < input_size)
                    {
                        /* Check the start character of tag name. */
                        if (*(input_data + i + 1) == APPLIB_HTML_OPEN_BRACKET ||
                            *(input_data + i + 1) == APPLIB_HTML_CLOSE_BRACKET || 
                            isspace(*(input_data + i + 1)))
                        {
                            /* 
                             * '<', '>' or whitespace is not allowed to be the
                             * first character of tag name, so the following 
                             * string is not a tag. 
                             */

                            if (context->open_bracket == 0 && context->open_tag[APPLIB_HTML_SCRIPT_ENUM] == 0 &&
                                context->open_tag[APPLIB_HTML_STYLE_ENUM] == 0)
                            {
                                /* 
                                 * The current character '<' is in general mode 
                                 * (i.e. it is outside comment/script/style), 
                                 * and it is outside a tag. So we need to write
                                 * the current character '<' into output buffer. 
                                 */
                                if (KAL_FALSE == applib_html_write_data_into_buffer(
													context,
                                                    cur_data,
                                                    1,
                                                    output_buf,
                                                    output_size,
                                                    &write_size,
                                                    read_size,
                                                    i,
                                                    KAL_FALSE))
                                {
                                    /* 
                                     * Output buffer is not enough; adjust the 
                                     * read_size to force re-send necessary data 
                                     * in the next time. 
                                     */
                                    return KAL_TRUE;
                                }
                            }
                        }
                        else
                        {
                            /* The following string can be a possible tag. */
                            if (context->open_tag[APPLIB_HTML_SCRIPT_ENUM] == 0 &&
                                context->open_tag[APPLIB_HTML_STYLE_ENUM] == 0)
                            {
                                /* 
                                 * The current character'<' is in general mode 
                                 * (i.e. it is outside comment/script/style). 
                                 * We need to keep the pos as the first '<' 
                                 * because '<' is not allowed within tag. 
                                 */
                                if (context->open_bracket == 0)
                                {
                                    context->open_bracket = 1;
                                    context->pos = i;
                                }
                            }
                            else
                            {
                                /* 
                                 * The current character'<' is inside style mode
                                 * or script mode (i.e. it is outside comment, 
                                 * but inside script or style. So we need to 
                                 * Update pos to the latest '<'. 
                                 */
                                context->open_bracket = 1;
                                context->pos = i;

                                /* 
                                 * Invalidate the incomplete buffer because the 
                                 * latest '<' can be used for tag checking. 
                                 */
                                applib_html_reset_incomplete_buffer(context);
                            }
                        }
                    }
                    else
                    {
                        /* 
                         * The current character '<' is the last character of 
                         * input data, so we don't have enough information to 
                         * check if it is the beginning of a tag or not.
                         */
                        if (is_final == 0)
                        {
                            if (context->open_bracket == 0 ||
                                (context->open_bracket != 0 &&
                                 (context->open_tag[APPLIB_HTML_SCRIPT_ENUM] != 0 ||
                                  context->open_tag[APPLIB_HTML_STYLE_ENUM] != 0)))
                            {
                                /* Resend data from '<' to check the tag in the next time. */
                                *output_size = write_size;
                                *read_size = i;
                                return KAL_TRUE;
                            }
                        }
                    }
                }
                break;

            case APPLIB_HTML_CLOSE_BRACKET: /* '>' */

            /* 
             * '>' is a possbile comment ending "-->" (if it is in comment mode)
             * or it is a possible tag ending "<TAG_NAME>" (if it is in 
             * general/script/style mode). 
             */				
                if (context->open_tag[APPLIB_HTML_COMMENT_ENUM] != 0)
                {
                    /* 
                     * "ontext->open_tag[APPLIB_HTML_COMMENT_ENUM] != 0" means
                     * it is in comment mode (i.e. it is inside comment. We
                     * need to check if the current character is the comment
                     * ending or not.
                     */
                    applib_html_check_comment_ending(context, input_data, i);
                }
                else
                {
                    /* 
                     * "ontext->open_tag[APPLIB_HTML_COMMENT_ENUM] == 0" means
                     * it is in general/script/style mode (i.e. it is outside 
                     * comment. We need to check if the current character is
                     * a tag ending or not.
                     */

                    if (context->open_bracket != 0)
                    {
                        /* Open bracket and close bracket are paired; check tags. */
                        applib_html_check_all_tags(context, input_data, i);
                    }
                }
                context->open_bracket = 0;
                break;

            case APPLIB_HTML_AMPERSAND: /* '&' */

            /* '&' is a possbile beginning of character entity reference "&ab;". */
			
                if (context->open_bracket == 0 &&
                    context->open_tag[APPLIB_HTML_COMMENT_ENUM] == 0 &&
                    context->open_tag[APPLIB_HTML_SCRIPT_ENUM] == 0 && 
                    context->open_tag[APPLIB_HTML_STYLE_ENUM] == 0)
                {
		            /* 
    		         * "context->open_tag[APPLIB_HTML_COMMENT_ENUM] == 0" means 
    		         * it is outside comment.
            		 *
	            	 * "context->open_tag[APPLIB_HTML_STYLE_ENUM] == 0" means it 
	            	 * is outside style sheets.
    	    	     *
        	    	 * "context->open_tag[APPLIB_HTML_SCRIPT_ENUM] == 0" means 
        	    	 * it is outsude scripts.
    	        	 *
	        	     * "context->open_bracket == 0" means it is outside tag.
    	        	 *        	     *
        	    	 * Therefore, the current character is in general mode 
        	    	 * (outside comment, style and script). Also, it is 
        	    	 * outside tag.
        	    	 */

                    if (context->open_entity == 0)
                    {
                        /* 
                         * "context->open_entity == 0" means it is outside a 
                         * possible character entity reference, so we need to  
                         * update pos to '&' because it is the beginning of a
                         * possible character entity reference "&abc;". 
                         */
                        context->open_entity = 1;
                        context->pos = i;
                    }

                    else
                    {
                        /* 
                         * "context->open_entity != 0" means it is inside a
                         * possible character entity reference and 
                         * *(input_data + context->pos) is '&'.
                         *
                         * Nested character entity is not allowed, so the 
                         * possible character reference "&ab&" is invliad. 
                         *
                         * We need to write the previous data "&ab" into output 
                         * buffer and then update pos to the latest '&'. 
                         */

                        kal_uint32 size = i - context->pos;

                        /* Write the invalid character reference "&ab" into output buffer. */
                        if (KAL_FALSE == applib_html_write_data_into_buffer(
											context,
                                            input_data + context->pos,
                                            size,
                                            output_buf,
                                            output_size,
                                            &write_size,
                                            read_size,
                                            context->pos,
                                            KAL_TRUE))
                        {
                            /* 
                             * Output buffer is not enough; adjust *read_size to 
                             * force re-send necessary data in the next time. 
                             *
                             * Reset flag because the current character '&' shall
                             * be resent in the next time. 
                             */
                            context->open_entity = 0;
                            return KAL_TRUE;
                        }
                        else
                        {
                            context->pos = i;
                        }
                    }
                }
                break;

            case APPLIB_HTML_SEMICOLON: /* ';' */

            /* ';' is a possbile ending of character entity reference "&ab;". */

                if (context->open_bracket == 0 &&
                    context->open_entity != 0 &&
                    context->open_tag[APPLIB_HTML_COMMENT_ENUM] == 0 &&
                    context->open_tag[APPLIB_HTML_SCRIPT_ENUM] == 0 && 
                    context->open_tag[APPLIB_HTML_STYLE_ENUM] == 0)
                {

                    /* 
                     * "context->open_entity != 0" means the current character
                     * is a possbile ending of a character entity reference and
                     * the *(input_data + context->pos) is '&'. 
                     *
                     * We need to replace this character entity reference 
                     * "&abc;" into the corresponding characters (1 ~ 4 bytes). 
                     */

                    kal_uint8 *data = input_data + context->pos;
                    kal_uint32 size = i - context->pos + 1; /* size of "&ab;" is 4 */
                    kal_uint8 entity_buf[APPLIB_HTML_MAX_UTF8_SIZE_PER_CHAR];
                    kal_int32 entity_size = APPLIB_HTML_MAX_UTF8_SIZE_PER_CHAR;
                    kal_uint8 force_write = KAL_TRUE;

                    memset(entity_buf, 0x00, APPLIB_HTML_MAX_UTF8_SIZE_PER_CHAR);

                    context->open_entity = 0;

                    if (applib_html_cvt_char_ref
                        ((const kal_char*)data, (kal_int32)size, (kal_char*) entity_buf, &entity_size))
                    {
                        /* 
                         * Success to replace character entity reference "&ab;" 
                         * into the corresponding characters (1 ~ 4 bytes). 
                         */
						if (entity_size == 1)
						{
							if (*entity_buf == APPLIB_HTML_TAB)
							{
				                /* 
				                 * If the current character is a tab ('\t'), 
				                 * replace it as a space (' '). 
				                 */
				                kal_uint8 space = APPLIB_HTML_SPACE;
	                        	size = 1;
		                        data = &space;								
							}
							
							else if (*entity_buf == APPLIB_HTML_CARRIAGE_RETURN || 
								*entity_buf == APPLIB_HTML_LINE_FEED)
							{
				                /* 
				                 * If the current character is a line feed 
				                 * ('\n') or a carriage return ('\r'), filter
				                 * it.
				                 */
	                        	size = 0;
		                        data = NULL;
							}
							
							else
							{
	                        	size = 1;
		                        data = entity_buf;
							}
						}
						else 
						{
                        	size = entity_size;
	                        data = entity_buf;
						}
                        force_write = KAL_FALSE;
                    }

                    /* Write data into output buffer. */
                    if (KAL_FALSE == applib_html_write_data_into_buffer(
										context,
                                        data,
                                        size,
                                        output_buf,
                                        output_size,
                                        &write_size,
                                        read_size,
                                        context->pos,
                                        force_write))
                    {
                        /* 
                         * Output buffer is not enough; adjust the *read_size 
                         * to force re-send necessary data in the next time. 
                         */
                        return KAL_TRUE;
                    }
                }
                break;

            case APPLIB_HTML_SPACE:           /* ' ' */
            case APPLIB_HTML_TAB:             /* '\t' */
			case APPLIB_HTML_CARRIAGE_RETURN: /* '\r' */
            case APPLIB_HTML_LINE_FEED:       /* '\n' */

            /* It is invalid inside a character entity reference. */             
			
                if (context->open_entity != 0)
                {
                    /* 
                     * "context->open_entity != 0" means the current character 
                     * is inside a possibile character entity reference and 
                     * *(input_data + context->pos) is '&'.
                     * 
                     * whitespace is invalid within a character entity reference, so 
                     * the possible character entity reference "&ab " is 
                     * invliad; we need to write this data into output buffer.
                     */

                    kal_uint32 size = i - context->pos;

                    /* Reset flag because this character entity reference is invalid. */
                    context->open_entity = 0;

                    /* Write the invalid character reference "&ab" into output buffer. */
                    if (KAL_FALSE == applib_html_write_data_into_buffer(
										context,
                                        input_data + context->pos,
                                        size,
                                        output_buf,
                                        output_size,
                                        &write_size,
                                        read_size,
                                        context->pos,
                                        KAL_TRUE))
                    {
                        /* 
                         * Output buffer is not enough; adjust *read_size based
                         * on the output buffer status to force re-send the 
                         * necessary data in the next time. 
                         */
                        return KAL_TRUE;
                    }

		            if (*cur_data == APPLIB_HTML_TAB || *cur_data == APPLIB_HTML_SPACE)
		            {
        		        /* If the current character is a tab ('\t'), replace it as a space (' '). */
		                kal_uint8 data = APPLIB_HTML_SPACE;

        		        if (KAL_FALSE == applib_html_write_data_into_buffer(
										context,
                    	                &data,
                        	            1,
                            	        output_buf,
                                	    output_size,
                                    	&write_size,
	                                    read_size,
    	                                i,
        	                            KAL_FALSE))
            		    {
                    		/* Output buffer is full. */
		                    return KAL_TRUE;
        		        }
		            }
                }
				break;
			
            default:
                break;

        }   /* End of switch-case */
    }       /* End of for-loop */


    /* Update output information. */
    if (is_final != 0)
    {
        /* Input data is the last part of HTML; all input data are processed. */
        *read_size = input_size;
        *output_size = write_size;
    }
    else
    {
        /* 
         * The input data is not the last part of HTML. We need to adjust the 
         * output infomration based on the incomplete data and current status. 
         */
        applib_html_adjust_output_info(
            context,
            input_data,
            input_size,
            output_buf,
            output_size,
            &write_size,
            read_size);
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  applib_html_check_comment_beginning
 * DESCRIPTION
 *  
 * PARAMETERS
 *  context         [IN]        The plaintext context. 
 *  input_data      [IN]        The input HTML formatted data.
 *  index           [IN]        The index of the current character.
 * RETURNS
 *  void
 *****************************************************************************/
static void applib_html_check_comment_beginning(
                applib_html_plaintext_context_struct *context,
                kal_uint8 *input_data,
                kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (context->open_bracket != 0 && (index >= 3) &&
        *(input_data + index - 1) == APPLIB_HTML_HYPHEN &&
        *(input_data + index - 2) == APPLIB_HTML_EXCLAMATION_MARK &&
        *(input_data + index - 3) == APPLIB_HTML_OPEN_BRACKET)
    {
        /* The beginning pattern of HTML comment "<!--" is matched */
        context->open_tag[APPLIB_HTML_COMMENT_ENUM] = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_html_check_comment_ending
 * DESCRIPTION
 *  
 * PARAMETERS
 *  context         [IN]        The plaintext context. 
 *  input_data      [IN]        The input HTML formatted data.
 *  index           [IN]        The index of the current character.
 * RETURNS
 *  void
 *****************************************************************************/
static void applib_html_check_comment_ending(
                applib_html_plaintext_context_struct *context,
                kal_uint8 *input_data,
                kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((index >= 2) && 
		*(input_data + index - 1) == APPLIB_HTML_HYPHEN &&
        *(input_data + index - 2) == APPLIB_HTML_HYPHEN)
    {
        /* The end pattern of HTML comment "-->" is matched */
        context->open_tag[APPLIB_HTML_COMMENT_ENUM] = 0;
    }

    else if ((index >= 3) && 
		     isspace(*(input_data + index - 1)) && 
		     *(input_data + index - 2) == APPLIB_HTML_HYPHEN &&
             *(input_data + index - 3) == APPLIB_HTML_HYPHEN)
    {
        /* The end pattern of HTML comment "-- >" is matched */
        context->open_tag[APPLIB_HTML_COMMENT_ENUM] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_html_check_all_tags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  context         [IN]        The plaintext context. 
 *  input_data      [IN]        The input HTML formatted data.
 *  index           [IN]        The index of the current character.
 * RETURNS
 *  void
 *****************************************************************************/
static void applib_html_check_all_tags(
                applib_html_plaintext_context_struct *context,
                kal_uint8 *input_data,
                kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (context->open_tag[APPLIB_HTML_COMMENT_ENUM] != 0)
	{
        /* In comment mode, tag checking is not necessary. */
		return;
	}
	
    if (context->open_tag[APPLIB_HTML_SCRIPT_ENUM] != 0)
    {
        /* Inside script, but outside comment. */
        if (applib_html_check_single_tag(
			context, 
            input_data, 
            index, 
            (kal_uint8*) APPLIB_HTML_END_TAG_SCRIPT, 
            APPLIB_HTML_LENGTH_END_TAG_SCRIPT))
        {
            /* Detect SCRIPT end tag */
            context->open_tag[APPLIB_HTML_SCRIPT_ENUM] = 0;
        }
    }

    else if (context->open_tag[APPLIB_HTML_STYLE_ENUM] != 0)
    {
        /* Inside style, but outside comment. */
        if (applib_html_check_single_tag(
			context, 
			input_data, 
			index, 
			(kal_uint8*) APPLIB_HTML_END_TAG_STYLE, 
			APPLIB_HTML_LENGTH_END_TAG_STYLE))
        {
            /* Detect STYLE end tag */
            context->open_tag[APPLIB_HTML_STYLE_ENUM] = 0;
        }
    }

    else
    {
        /* Outside script, style and comment. */
        if (applib_html_check_single_tag(
			context, 
			input_data, 
			index, 
			(kal_uint8*) APPLIB_HTML_START_TAG_SCRIPT,
            APPLIB_HTML_LENGTH_START_TAG_SCRIPT))
        {
            /* Detect SCRIPT start tag */
            context->open_tag[APPLIB_HTML_SCRIPT_ENUM] = 1;
        }

        else if (applib_html_check_single_tag(
			context, 
			input_data, 
			index, 
			(kal_uint8*) APPLIB_HTML_START_TAG_STYLE,
			APPLIB_HTML_LENGTH_START_TAG_STYLE))
        {
            /* Detect STYLE start tag */
            context->open_tag[APPLIB_HTML_STYLE_ENUM] = 1;
        }

        else
        {
            /* Check HTML block element */
            applib_html_check_block_tags(context, input_data, index);
        }
    }

    /* After checking tag, invalidate the incomplete buffer. */
    applib_html_reset_incomplete_buffer(context);
}


/*****************************************************************************
 * FUNCTION
 *  applib_html_check_block_tags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  context         [IN]        The plaintext context. 
 *  input_data      [IN]        The input HTML formatted data.
 *  index           [IN]        The index of the current character.
 * RETURNS
 *  void
 *****************************************************************************/
static void applib_html_check_block_tags(
                applib_html_plaintext_context_struct *context,
                kal_uint8 *input_data,
                kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < APPLIB_HTML_BLCOK_TAG_END_OF_ENUM; i++)
    {
        if (applib_html_check_single_tag(
			context, 
			input_data, 
			index, 
			(kal_uint8*) applib_html_block_tag_table[i].tag_name,
             applib_html_block_tag_table[i].tag_size))
        {
            /* A HTML block element is detected. */
            context->open_tag[APPLIB_HTML_BLOCK_ELEMENT_ENUM] = 1;
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_html_check_single_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  context         [IN]        The plaintext context. 
 *  input_data      [IN]        The input HTML formatted data.
 *  index           [IN]        The index of the current character.
 *  tag_name        [IN]        The tag name that is used to compare.
 *  tag_size        [IN]        Size of the tag name.
 * RETURNS
 *  KAL_TRUE					The input data is the compared tag.
 *  KAL_FALSE					The input data is not the compared tag.   
 *****************************************************************************/
static kal_bool applib_html_check_single_tag(
                    applib_html_plaintext_context_struct *context,
                    kal_uint8 *input_data,
                    kal_uint32 index,
                    kal_uint8 *tag_name,
                    kal_uint32 tag_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint8 *data = NULL;
    kal_uint32 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * If context->incomplete_size is not 0, we need to use the incomplete data
     * in context->incomplete_buf for tag checking.     
     */

    if (context->incomplete_size != 0)
    {

        kal_uint32 copy_len = MIN(
			index + 1, 
			APPLIB_HTML_MAX_TAG_CHECK_LENGTH - context->incomplete_size);

        memcpy(
			context->incomplete_buf + context->incomplete_size, 
			input_data, 
			copy_len);
		
        data = context->incomplete_buf;
        size = context->incomplete_size + copy_len;
    }

    else
    {
        /* Take <TAG_NAME> for example, data is "TAG_NAME>" and size is 9. */
        data = input_data + context->pos + 1;
        size = index - context->pos;
    }

    return (applib_html_compare_tag_name(data, size, tag_name, tag_size));

}


/*****************************************************************************
 * FUNCTION
 *  applib_html_compare_tag_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [IN]        The data used to be compared.
 *  size            [IN]        Size of data.
 *  tag_name        [IN]        The tag name that is used to compare.
 *  tag_size        [IN]        Size of the compared tag name.
 * RETURNS
 *  KAL_TRUE					The input data is the compared tag.
 *  KAL_FALSE					The input data is not the compared tag. 
 *****************************************************************************/
static kal_bool applib_html_compare_tag_name(
                    kal_uint8 *data,
                    kal_uint32 size,
                    kal_uint8 *tag_name,
                    kal_uint32 tag_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */

    /*----------------------------------------------------------------*/

    /* 
     * (1) If "input_data" is "SCRIPT src=ab.js>", "input_size" is 16, 
     *     "tag_name" is "SCRIPT" and "tag_size" is 6: return TRUE.
     *
     * (2) If "input_data" is "SCRIPTXXX>", "input_size" is 10, 
     *     "tag_name" is "SCRIPT" and "tag_size" is 6: return FALSE.
     *
     * (3) If "input_data" is "SCRI", "input_size" is 4, "tag_name" 
     *     is "SCRIPT" and "tag_size" is 6: return FALSE.     
     */

    if (tag_size < size)
    {

        kal_uint8 *end = data + tag_size;

        if ((app_strnicmp((kal_char*) data, (kal_char*) tag_name, tag_size) == 0) &&
            ((*end == APPLIB_HTML_CLOSE_BRACKET) || isspace(*end)))
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  applib_html_write_data_into_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  context         [IN/OUT]        The plaintext context.
 *  data            [IN]            The extracted plaintext data.
 *  data_size       [IN]            The size of the extracted plaintext data.
 *  output_buf      [IN/OUT]        The output buffer which is used to store the
 *  output_size     [IN/OUT]        In the beginning, it is used to indicate the
 *                                  size of the output buffer. After writing, it
 *                                  is also used to indicate the total size of
 *                                  the extracted plaintext data.
 *  write_size      [IN/OUT]        In the beginning, it is used to indicate the 
 *                                  current plaintext data size. After writing, 
 *                                  it is also used to indicate the latest 
 *                                  plaintext data size.
 *  read_size       [OUT]           The total input size to be read. It shall be
 *                                  updated if output buffer is not enough.
 *  read_pos        [IN]            The current data position to be read.
 *  force_write     [IN]            Indicate to write the partial data into output 
 *                                  buffer if the output buffer is not enough.
 * RETURNS
 *  KAL_TRUE                        All data are copied to output buffer.
 *  KAL_FALSE                       Not all data are copied to output buffer.
 *****************************************************************************/
static kal_bool applib_html_write_data_into_buffer(
					applib_html_plaintext_context_struct *context,
                    kal_uint8 *data,
                    kal_uint32 data_size,
                    kal_uint8 *output_buf,
                    kal_uint32 *output_size,
                    kal_uint32 *write_size,
                    kal_uint32 *read_size,
                    kal_uint32 read_pos,
                    kal_uint8 force_write)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_uint8 insufficient_buf = 0;
	kal_uint32 size = data_size;
	kal_uint32 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	

    if (*write_size + data_size > *output_size)
    {
        /* Output buffer is not enough. */
        size = (*output_size > *write_size) ? (*output_size - *write_size) : 0;
		insufficient_buf = 1;
	}

	if (size != 0 && (insufficient_buf == 0 || (insufficient_buf == 1 && force_write == 1)))
	{	
        /* 
         * Write data into output buffer if the output buffer is enough or the 
         * caller wants to write partial data even though the output buffer is 
         * not enough.
         */

		for (j = 0; j < size; j++)
		{
			if (*(data + j) == APPLIB_HTML_LINE_FEED)
			{				
				if ((APPLIB_HTML_MAX_CONTINUOUS_LINE_FEED < 0) || 
					(context->linefeed < APPLIB_HTML_MAX_CONTINUOUS_LINE_FEED))
				{
					/* Merge the adjacent line feeds. */
		            *(output_buf + *write_size) = *(data + j);
    	   		    *write_size = *write_size + 1;
					context->linefeed ++;
				}							
			}
			
			else if (*(data + j) == APPLIB_HTML_SPACE)
			{
				if (context->linefeed == 0 && 
					((APPLIB_HTML_MAX_CONTINUOUS_SPACE < 0) || 
					(context->space < APPLIB_HTML_MAX_CONTINUOUS_SPACE)))
				{
					/* 
					 * Merge the adjacent spaces and filter the redundant spaces 
					 * which are adjacent to block elements.
					 */
	    	        *(output_buf + *write_size) = *(data + j);
	      		    *write_size = *write_size + 1;
					context->space ++;
				}
			}

			else
			{
    	        *(output_buf + *write_size) = *(data + j);
      		    *write_size = *write_size + 1;
				context->linefeed = 0;
				context->space = 0;
			}
		}
	}

	if (insufficient_buf == 0)
	{
		return KAL_TRUE;
	}   
    else
    {
        *output_size = *write_size;
        *read_size = read_pos + j;
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_html_reset_incomplete_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  context     [IN]        The plaintext context.
 * RETURNS
 *  void
 *****************************************************************************/
static void applib_html_reset_incomplete_buffer(applib_html_plaintext_context_struct *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (context->incomplete_size != 0)
    {
        context->incomplete_size = 0;
        memset(context->incomplete_buf, 0x0, APPLIB_HTML_MAX_TAG_CHECK_LENGTH);
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_html_adjust_output_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  context         [IN/OUT]        The plaintext context.
 *  input_data      [IN]            The input HTML formatted UTF-8 encoded data.
 *  input_size      [IN]            The size of the input data.
 *  output_buf      [IN/OUT]        The output buffer. It is used to save the 
 *                                  extracted plain text data (UTF-8 encoded).
 *  output_size     [IN/OUT]        In the beginning, it is used to indicate the
 *                                  size of the output buffer. After adjustion, 
 *                                  it is also used to indicate the size of the 
 *                                  extracted plaintext data.
 *  write_size      [IN/OUT]        In the beginning, it is used to indicate the 
 *                                  current plaintext data size. After adjustion, 
 *                                  it is also used to indicate the latest 
 *                                  plaintext data size.
 *  read_size       [OUT]           The total input size to be read.
 * RETURNS
 *  void
 *****************************************************************************/
static void applib_html_adjust_output_info(
                applib_html_plaintext_context_struct *context,
                kal_uint8 *input_data,
                kal_uint32 input_size,
                kal_uint8 *output_buf,
                kal_uint32 *output_size,
                kal_uint32 *write_size,
                kal_uint32 *read_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* The input data is not the last part of HTML. */

    if (context->open_tag[APPLIB_HTML_COMMENT_ENUM] != 0)
    {
        /* 
         * "context->open_tag[APPLIB_HTML_COMMENT_ENUM] != 0" means: currently,
         * it is inside comment (that is, now is in comment mode). 
         * 
         * In comment mode, force to re-send the last three characters to check
         * comment ending ("-->" or "-- >") in the next time. 
         */
        *read_size = input_size - 3;
        *output_size = *write_size;
    }

    else if (context->open_bracket != 0)
    {
        /* 
         * "context->open_tag[APPLIB_HTML_COMMENT_ENUM] == 0" means: currently, 
         * it it outside comment (i.e., it is in general, style or script mode). 
         *
         * "context->open_bracket != 0" means: currently, it is inside a tag and
         * *(input_data + context->pos) is '<'. 
         *
         * '<' is a possbile beginning of a comment ("<!--") or a tag ("<TAG>").
         */
        kal_uint32 pattern_size = input_size - context->pos;

        if (pattern_size < APPLIB_HTML_LENGTH_START_TAG_COMMENT)
        {
            /* 
             * '<' is a possbile beginning of a comment ("<!--") or a tag ("<TAG>").
             * Thefore, force to resend input data from '<' to check the comment 
             * beginning ("<!--") and tag in the next time. Since the '<' shall be 
             * re-sent, reset flag "context->open_bracket" as 0.
             * 
             */
            *read_size = context->pos;
            *output_size = *write_size;
            context->open_bracket = 0;
        }
        else
        {
            /* 
             * '<' is not a possbile beginning of a comment ("<!--"), but it is
             * a beginnigon of a tag ("<TAG>"). Therefore, save the incomplete
             * tag name into "context->incomplete_buf" to check the tag name
             * in the next time.
             *
             * Take input data "abc<tag_name" for example, "tag_name" will be 
             * saved to incomplete_buffer.
             */

            /* All input data are processed. */
            *read_size = input_size;
            *output_size = *write_size;
			
            applib_html_reset_incomplete_buffer(context);

			context->incomplete_size = MIN(
				input_size - context->pos - 1, 
				APPLIB_HTML_MAX_TAG_CHECK_LENGTH);

			memcpy(context->incomplete_buf, input_data + context->pos + 1, context->incomplete_size);
			
        }
    }
    else if (context->open_entity != 0)
    {

        /* 
         * "context->open_entity != 0" means: currently, it is outside comment,
         * script, stlye ((i.e., it is in general mode). In addition, it is
         * inside a character entity and outside a tag.
         *         
         * *(input_data + context->pos) is '&'. 
         *
         */

        kal_uint32 size = input_size - context->pos;

        if (size < APPLIB_HTML_MAX_CHARACTER_ENTITY_NAME_LENGTH)
        {
            /*
             * The maximum size of a character entity reference ("&thetasym;") 
             * is APPLIB_HTML_MAX_CHARACTER_ENTITY_NAME_LENGTH (10). If the 
             * incomplete character entity reference size is less than 10,
             * it is possible to be a valid character entity reference.
             *
             * Therefore, force to re-send data from '&' to check character 
             * entity reference ("&abc;") in the next time.
             *
             * Since '&' shall be re-sent, flag "context->open_entity" shall be 
             * reset as 0.
             */
            *read_size = context->pos;
            *output_size = *write_size;
        }
        else
        {
            /*
             * The maximum size of a character entity reference ("&thetasym;") 
             * is APPLIB_HTML_MAX_CHARACTER_ENTITY_NAME_LENGTH (10). If the 
             * incomplete character entity reference size equals to or exceeds
             * 10, it is not possible to be a valid character entity reference.
             *
             * Therefore, force to write the incomplete data from '&' into the
             * output buffer.
             *
             * If the output buffer is not enough, then force to write partial 
             * data until the output buffer is full and force to resend data 
             * from the data that haven't been written.
             *
             * Take "abc&1234567890abcde" for example, if "&1234567890ab" have 
             * been copied into output buffer, then force to resend from "cde".
             *
             * Since this is an invalid character entity reference, flag 
             * "context->open_entity" shall be reset as 0.
             */
            if (KAL_TRUE == applib_html_write_data_into_buffer(
								context,
                                input_data + context->pos,
                                size,
                                output_buf,
                                output_size,
                                write_size,
                                read_size,
                                context->pos,
                                KAL_TRUE))
            {
                /* All input data are processed. */
                *read_size = input_size;
                *output_size = *write_size;
            }
        }

        /* Reset flag. */
        context->open_entity = 0;
    }
    else
    {
        /* All input data are processed. */
        *read_size = input_size;
        *output_size = *write_size;
    }
}

