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
 * DTVPlayerMBBMS.h
 *
 * Project:
 * --------
 * MAUI
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

#ifndef _DTV_PLAYER_MBBMS_H
#define _DTV_PLAYER_MBBMS_H

#ifdef __CMMB_CAS_MBBMS_SUPPORT__
#include "MMIDataType.h"

/*****************************************************************************
 * Define
 *****************************************************************************/
#define MMI_DTV_MBBMS_REQ_URL_LEN               (256)
#define MMI_DTV_MBBMS_MAX_FILE_LEN              (256)

/*****************************************************************************
 * Enum
 *****************************************************************************/
/* result of dtv mbbms */
typedef enum
{
    MMI_DTV_MBBMS_OK                        = 0,    /* ok */
    MMI_DTV_MBBMS_ERR_FAIL                  = 1,    /* fail */
    MMI_DTV_MBBMS_ERR_SRV_UNAVAILABLE       = 2,    /* service unavailable */
    MMI_DTV_MBBMS_ERR_INVALID_DATA          = 3,    /* invalid data */
    MMI_DTV_MBBMS_ERR_ALL                           /* end of error enum */
} mmi_dtv_mbbms_ret_enum;


/*****************************************************************************
 * Struct
 *****************************************************************************/
/* data account infor struct */
typedef struct
{
    MMI_BOOL    use_proxy;      /* use proxy or not */
    U32         net_id;         /* data account id */
    U8          prx_ip[4];      /* proxy ip */
    U16         prx_port;       /* proxy port */
    U8          app_id;         /* app id */
} mmi_dtv_mbbms_dcnt_struct;

/* download request struct */
typedef struct
{
    U8          req_url[MMI_DTV_MBBMS_REQ_URL_LEN + 1];    /* request url of the file */
    U16         file_path[MMI_DTV_MBBMS_MAX_FILE_LEN + 1]; /* filepath for saving the file */
} mmi_dtv_mbbms_download_req_struct;


typedef void (*dtv_func_ptr)(mmi_dtv_mbbms_ret_enum ret, U16 *file_path);
/*****************************************************************************
 * Extern func
 *****************************************************************************/
extern mmi_dtv_mbbms_ret_enum mmi_dtv_mbbms_open(dtv_func_ptr on_mbbms, mmi_dtv_mbbms_dcnt_struct *dcnt_ptr);
extern mmi_dtv_mbbms_ret_enum mmi_dtv_mbbms_close(void);
extern mmi_dtv_mbbms_ret_enum mmi_dtv_mbbms_download(mmi_dtv_mbbms_download_req_struct *req_data);
extern mmi_dtv_mbbms_ret_enum mmi_dtv_mbbms_cancel_download(void);

#endif  /* __CMMB_CAS_MBBMS_SUPPORT__ */

#endif /* _DTV_PLAYER_MBBMS_H */

