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
 *  MOTApp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MOT App head file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
  ****************************************************************************/
#ifndef __MOT_APP_H_H_20120421_H__
#define __MOT_APP_H_H_20120421_H__

#include "mmi_features.h"
#ifdef __MMI_MOT_SUPPORT__

#include "MotSrvGprot.h"
#include "GlobalConstants.h"

#define APP_MOT_DESCRIPTION_OVERHEAD   100
#define APP_MOT_DESCRIPTION_LEN       (SRV_MOT_DATETIME_LEN + SRV_MOT_ARTIST_LEN + SRV_MOT_DESCRIPT_LEN + APP_MOT_DESCRIPTION_OVERHEAD)
#define APP_MOT_THUMBNAIL_HEAD         8
typedef struct
{
    U16 title[SRV_MOT_TITLE_LEN]; 
    S32 total;
    S32 highlight;
}mmi_mot_list_info;

typedef struct
{
   U32 item_index; //  index of category screen;
   U32 content_id;    //content id of mot srv.
}mmi_mot_mapping_item;


typedef struct
{
    srv_mot_h          srv_handle;    
    srv_mot_ret_enum   srv_last_ret;
    S32                drive;
    
    U32 total_category;
    U32 active_category_index;

    mmi_mot_list_info  list_info;

    U32 flags;
    
    U32 total_cache_num;
    mmi_mot_mapping_item content_cache[MAX_SUB_MENUS];
    
    srv_mot_file_path_struct active_filepath;
    
    /* due to content info is a large struct, it may cause stack overflow.
     * we using asm as temp content buffer.
     */
    srv_mot_content_info_struct content_info_temp_buf;
    
    /* 
         * using for saving image data with 8 bytes header.
         */
    U8    thumbnail_image_data[SRV_MOT_THUMBNAIL_SIZE + APP_MOT_THUMBNAIL_HEAD];
    
    WCHAR description[APP_MOT_DESCRIPTION_LEN];
}mmi_mot_context;

#define MMI_MOT_MSG_TRACE(VAL)					\
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MOT_MSG_TRACE, __LINE__, VAL)


#endif /* __MMI_MOT_APP__ */
#endif /* __MOT_APP_H_H_20120421_H__ */

