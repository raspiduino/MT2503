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
 * ntpd2mmi_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of DHCP and ABM.
 *
 * Author:
 * -------
 * 
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
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

#ifndef _NTPD2MMI_STRUCT_H_
#define _NTPD2MMI_STRUCT_H_

#include "kal_release.h"        /* Basic data type */

/* return value of function */
#define NTPD_SUCCESS       0
#define NTPD_ERROR         -1
#define NTPD_UNREACH       -2


#define NTPD_SERVER_NUM    2    /* max server number */
#define NTPD_MAX_NAME_LEN  64   /* the name length */
#define NTPD_KEYID_LEN     32   /* key id length */
#define NTPD_ADDR_LEN      4    /* address length */
#define NTPD_MAX_CALLBACK  4    /* the number of callback */

typedef void (*ntpd_sync_cb) (kal_int32 result, kal_int64 offset, void *usr_data);


/***************************************************************************
 * <GROUP Structures>
 *
 * Local parameter of MSG_ID_ABM_DHCPD_ACTIVE_RES
 ***************************************************************************/
typedef struct ntpd_config_struct
{
    kal_uint8 server[NTPD_SERVER_NUM][NTPD_MAX_NAME_LEN];
    kal_uint8 keyid[NTPD_KEYID_LEN];
    kal_uint16 port[NTPD_SERVER_NUM];
    kal_int32 account_id;
    kal_uint16 auth;
    kal_uint16 server_num;
    kal_uint16 samples;
    kal_uint16 timeout;
} mmi_ntpd_config_struct;


extern kal_int32 ntpd_open(struct ntpd_config_struct *config);
extern kal_int32 ntpd_sync(ntpd_sync_cb callback, void *usr_data);
extern kal_int32 ntpd_sync_abort(void);
extern void ntpd_close(void);
#if defined(EMPTY_MMI)
extern void ntpd_sync_time_ext(ntpd_sync_cb callback, kal_uint32 account_id, void *usr_data);
extern void ntpd_sync_time_close();
#endif


#endif /* !_NTPD2MMI_STRUCT_H_ */


