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
 * BppXhtml.h
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   
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

#ifndef BPP_XHTML_H
#define BPP_XHTML_H
#include "MMI_features.h"

#ifdef __MMI_BPP_SUPPORT__
#include "MMIDataType.h"
#include "fs_type.h"
#include "BppCuiGprot.h"
#include "BppXhtmlGprot.h"
#include "kal_general_types.h"
/* RHR add end */
/*****************************************************************
    Constant
*****************************************************************/
#define ArrayCount(ele)     (sizeof(ele) / sizeof(ele[0]))

#define BUF_SIZE            (256)

#define VER_10              XHTML_VER_100
#define VER_95              XHTML_VER_095

#define STYLE_PAGE          XHTML_STYLE_PAGE
#define STYLE_TOP           XHTML_STYLE_TOP
#define STYLE_BOTTOM        XHTML_STYLE_BOTTOM

#define PROP_SIZE           XHTML_PROP_SIZE
#define PROP_COUNTER        XHTML_PROP_COUNTER
#define PROP_MARGIN_TOP     XHTML_PROP_MARGIN_TOP
#define PROP_MARGIN_BOTTOM  XHTML_PROP_MARGIN_BOTTOM
#define PROP_MARGIN_LEFT    XHTML_PROP_MARGIN_LEFT
#define PROP_MARGIN_RIGHT   XHTML_PROP_MARGIN_RIGHT
#define PROP_COLOR          XHTML_PROP_COLOR
#define PROP_BK_COLOR       XHTML_PROP_BK_COLOR
#define PROP_WIDTH          XHTML_PROP_WIDTH
#define PROP_BORDER_BOTTOM  XHTML_PROP_BORDER_BOTTOM
#define PROP_TEXT_ALIGN     XHTML_PROP_TEXT_ALIGN
#define PROP_VERTICAL_ALIGN XHTML_PROP_VERTICAL_ALIGN
#define PROP_CONTENT        XHTML_PROP_CONTENT
#define PROP_LINE_HEIGHT    XHTML_PROP_LINE_HEIGHT

#define ELMN_HEAD           XHTML_ELE_HEAD
#define ELMN_BODY           XHTML_ELE_BODY
#define ELMN_TITLE          XHTML_ELE_TITLE
#define ELMN_CAPTION        XHTML_ELE_CAPTION
#define ELMN_DIV            XHTML_ELE_DIV
#define ELMN_PARA           XHTML_ELE_PARA
#define ELMN_TABLE          XHTML_ELE_TABLE
#define ELMN_TABLE_ROW      XHTML_ELE_TABLE_ROW
#define ELMN_TABLE_CELL     XHTML_ELE_TABLE_CELL

#define ATTR_WIDTH          XHTML_ATTR_WIDTH
#define ATTR_HEIGHT         XHTML_ATTR_HEIGHT


static const CHAR XhtmlStart[] =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n"
        "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML-Print %s//EN\"\r\n"
        "\"http://www.w3.org/MarkUp/DTD/xhtml-print10.dtd\">\r\n"
        "<html xmlns=\"http://www.w3.org/1999/xhtml\">\r\n" "\r\n";

static const CHAR DefaultStyleType[] = "\"text/css\"";

/*****************************************************************
    Structure
*****************************************************************/
typedef struct {
    U8 *ptr;
    U32 size;
    U32 len;
} xhtml_buff;

typedef struct {
    U32 type;
    union {
        FS_HANDLE fh;
        xhtml_buff buff;
    } u;
} xhtml_output;

typedef struct {
    PrintClass type;
    xhtml_output out;
    CHAR buff[BUF_SIZE];
    U32 data_len;
} xhtml_ctrl_block;


static const xhtml_attr_struct ImageAttrs[] =
{
    {XHTML_ATTR_WIDTH,      "%dmm"},
    {XHTML_ATTR_HEIGHT,     "%dmm"},
    {XHTML_ATTR_SRC,        "%s"},
    {XHTML_ATTR_INLINE_SIZE, "%d"},
    {XHTML_ATTR_TYPE,       "image/jpeg"}
};

static const xhtml_attr_struct ObjectAttrs[] =
{
    {XHTML_ATTR_SRC,        "%s"},
    {XHTML_ATTR_INLINE_SIZE, "%d"},
    {XHTML_ATTR_TYPE,       "%s"}
};

/*****************************************************************
    Prototypes
*****************************************************************/
static S32 xhtml_element_begin(xhtml_ctrl_block *xcb,
                               const CHAR *name,
                               xhtml_attr_struct *attrs,
                               U32 count, U32 empty);
static S32 xhtml_element_data(xhtml_ctrl_block *xcb, const CHAR *data);
static S32 xhtml_element_end(xhtml_ctrl_block *xcb, const CHAR *name);
static U32 xhtml_write(xhtml_ctrl_block *xcb, const CHAR *data);
static S32 xhtml_escaping(CHAR *out, U32 size, const CHAR *in, CHAR **end);
static MMI_BOOL xhtml_flush(xhtml_ctrl_block *xcb);

#endif /* __MMI_BPP_SUPPORT__ */

#endif /* BPP_XHTML_H */
