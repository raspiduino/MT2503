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

/*******************************************************************************
 * Filename:
 * ---------
 * ResgenDataType.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Minimal datatype header for resgen.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/


#ifndef __RESGEN_DATATYPE_H__
#define __RESGEN_DATATYPE_H__

#include <basetsd.h> // for __int64

typedef enum {
    MMI_FALSE   = 0,
    MMI_TRUE    = 1
} MMI_BOOL;

typedef char                S8;
typedef char                *PS8;
typedef unsigned char       U8;
typedef unsigned char       *PU8;

typedef unsigned short      pBOOL;
typedef int BOOL;

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

typedef short int           S16;
typedef short int           *PS16;
typedef unsigned short int  U16;
typedef unsigned short int  *PU16;

typedef int                 S32;
typedef int                 *PS32;
typedef unsigned int        U32;
typedef unsigned int        *PU32;

// float32 will be removed, please use FLOAT instead
typedef float               float32;
typedef float               FLOAT;

typedef unsigned __int64    U64;
typedef __int64             S64;
typedef void (*FuncPtrShort) (U16);

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
#ifndef _WCHAR_T_
#define _WCHAR_T_
#undef __need_wchar_t
#ifndef __cplusplus
typedef unsigned short wchar_t;
#endif
#endif
#endif

typedef wchar_t WCHAR;

#ifndef NULL
#define NULL               0
#endif

#define MMI_EVT_PARAM_HEADER    \
    U16 evt_id;                 \
    U16 size;                   \
    void *user_data;


#define mmi_id              MMI_ID
#define mmi_img_id          MMI_IMG_ID
#define mmi_str_id          MMI_STR_ID
#define mmi_menu_id         MMI_MENU_ID
#define mmi_timer_id        MMI_TIMER_ID
#define mmi_event_id        MMI_EVENT_ID
#define mmi_ret             MMI_RET

typedef unsigned short      MMI_ID_TYPE;
typedef U16                 MMI_ID;         /* app id, group id, screen id */
typedef U16                 MMI_IMG_ID;     /* image or icon */
typedef U16                 MMI_STR_ID;     /* string */
typedef U16                 MMI_MENU_ID;    /* menu item id, hilite id, hint id */
typedef U16                 MMI_TIMER_ID;   /* timer */
typedef U16                 MMI_EVENT_ID;

typedef S32                 mmi_ret;

typedef enum {
    RES_IMAGE,
    RES_MEDIA,
    RES_AUDIO,
    RES_JAVA_GAME,
    RES_FONT,
    RES_BINARY
} RESOURCE_TYPE_LIST;

typedef enum _binary_type_enum
{
    BINARY_TYPE_INVALID,
    BINARY_TYPE_VENUS_XML,
    BINARY_TYPE_TOTAL
} binary_type_enum;

#endif // __RESGEN_DATATYPE_H__
