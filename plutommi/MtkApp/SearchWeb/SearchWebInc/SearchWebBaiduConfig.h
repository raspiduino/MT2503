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
 *  SearchBaiduConfig.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Configuration for Baidu search.
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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

#ifndef __MMI_SEARCH_WEB_BAIDU_CONFIG_H__
#define __MMI_SEARCH_WEB_BAIDU_CONFIG_H__

#include "MMI_features.h"


/*-----------------------------for pluto and cosmos------------------------
 * Customer ID.
 * This ID is based on the contract of customer and Baidu. By default, it is "0000".
 ----------------------------------------------------------------------*/
#define MMI_SEARCH_WEB_BAIDU_CUSTOMER_ID            "0000"


#ifdef __MMI_SEARCH_WEB_BAIDU__

#include "nvram_common_defs.h"
#ifndef __MMI_SEARCH_WEB_BAIDU_PROT_H__
#include "SearchWebBaiduProt.h"
#endif

/****************************************************************************
 * Typedef
 ****************************************************************************/

/*
 * The format of request page.
 * Baidu website will generate the format corresponding to the "bd_page_type"
 * parameter. The value of each enum is definied in the Baidu's specification.
 */
typedef enum
{
    MMI_SEARCH_WEB_BAIDU_BD_PAGE_TYPE_WML   = 0,
    MMI_SEARCH_WEB_BAIDU_BD_PAGE_TYPE_XHTML = 1,

    MMI_SEARCH_WEB_BAIDU_BD_PAGE_TYPE_END_OF_ENUM
} mmi_search_web_baidu_bd_page_type_enum;


/****************************************************************************
 * Configurations for Customization
 ****************************************************************************/

/*
 * Default hot key setting.
 * If change please take care of __MMI_REDUCED_KEYPAD__.
 */
#define MMI_SEARCH_WEB_BAIDU_DEFAULT_HOT_KEY        (MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY)

/*
 * Maximum uid length of Baidu search.
 * DO NOT set larger than NVRAM_EF_SEARCH_WEB_BAIDU_UID_MAX_LEN.
 */
#define MMI_SEARCH_WEB_BAIDU_MAX_UID_LEN            (28)

/*
 * Maximum number of raw characters of input.
 * MUST NOT be larger than NVRAM_EF_SEARCH_WEB_HISTORY_MAX_STRING_LEN.
 * Note that a Chinese character will be encoded into 9 bytes in the URL, so
 * please also care the length-limitation of generated URL. 
 */
#define MMI_SEARCH_WEB_BAIDU_MAX_INPUT_LEN          (NVRAM_EF_SEARCH_WEB_HISTORY_MAX_STRING_LEN)


/*
 * Default format of Baidu's output.
 * The value should be one of mmi_sweb_baidu_bd_page_type_enum.
 */
#define MMI_SEARCH_WEB_BAIDU_DEFAULT_BD_PAGE_TYPE   MMI_SEARCH_WEB_BAIDU_BD_PAGE_TYPE_WML

/*
 * Default encoding of parameters. See mmi_chset_enum.
 */
#define MMI_SEARCH_WEB_BAIDU_DEFAULT_URL_ENCODING   MMI_CHSET_UTF8

/*
 * Maximum URL length.
 * If URL is longer than this value, it will be truncated. Some proxy servers
 * may only support at most 255 characters of URL. You may enlarge this value,
 * so that the truncation is done by proxy. However, do not set it to be larger
 * than 512, because the buffer to store the URL is allocated from the control
 * buffer.
 */
#define MMI_SEARCH_WEB_BAIDU_MAX_URL_LEN            (300)

#endif /* __MMI_SEARCH_WEB_BAIDU__ */

#endif /* __MMI_SEARCH_WEB_BAIDU_CONFIG_H__ */
